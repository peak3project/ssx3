"""cc_native.py <ccdir> <gcc args...>: run a Linux-native 32-bit ee-gcc (e.g. Sony's ee-gcc 2.9-ee-991111) on a unit.

These old i386 builds use 32-bit stat(), so on filesystems with 64-bit inode numbers (WSL's /mnt drives, some
network mounts) every open of a source or include file fails with "Value too large for defined data type". In that
case the inputs the compile needs (the .c file, the -I/-isystem/-Wa,-I directories it references) are mirrored into
a temporary directory on the local filesystem, the compiler runs there, and the object is copied back. Text inputs
are copied with LF line endings (a CRLF checkout breaks this preprocessor's line continuations). When the working
directory is already on a local filesystem the compiler runs in place.
"""

import os
import shutil
import subprocess
import sys
import tempfile

TEXT = (".c", ".cpp", ".h", ".hpp", ".inc", ".s", ".S")


def copy_text_lf(src, dst, *args, **kw):
    """copy2 that also turns CRLF into LF for text files."""
    if dst.endswith(TEXT):
        data = open(src, "rb").read().replace(b"\r\n", b"\n")
        open(dst, "wb").write(data)
        shutil.copystat(src, dst)
        return dst
    return shutil.copy2(src, dst)


def needs_mirror(path):
    try:
        return os.stat(path).st_ino > 0xFFFFFFFF or os.stat(".").st_ino > 0xFFFFFFFF
    except OSError:
        return False


def asm_include_dirs(args):
    dirs = ["."]
    for a in args:
        if a.startswith("-Wa,-I"):
            dirs.append(a[len("-Wa,-I"):])
    return dirs


def expand_includes(text, dirs, depth=0):
    """Inline `.include "file"` directives (this assembler stops opening includes after a few hundred files)."""
    out = []
    for line in text.split("\n"):
        s = line.strip()
        if s.startswith(".include") and '"' in s and depth < 8:
            name = s.split('"')[1]
            path = next((os.path.join(d, name) for d in dirs if os.path.isfile(os.path.join(d, name))), None)
            if path:
                inner = open(path, "rb").read().replace(b"\r\n", b"\n").decode("latin-1")
                out.append(expand_includes(inner, dirs, depth + 1))
                continue
        out.append(line)
    return "\n".join(out)


def compile_two_step(gcc, args, cwd):
    """gcc -S, inline the .include directives, then assemble the result with the same flags."""
    out_i = args.index("-o") + 1
    src = next(a for a in args if a.endswith((".c", ".cpp")))
    s_file = os.path.join(tempfile.mkdtemp(prefix="cc_native_s."), "unit.s")
    s_args = ["-S" if a == "-c" else a for a in args]
    s_args[out_i] = s_file
    rc = subprocess.call([gcc] + s_args, cwd=cwd)
    if rc != 0:
        return rc
    text = expand_includes(open(s_file, encoding="latin-1").read(), [os.path.join(cwd, d) for d in asm_include_dirs(args)])
    open(s_file, "w", encoding="latin-1").write(text)
    c_args = [s_file if a == src else a for a in args]
    rc = subprocess.call([gcc] + c_args, cwd=cwd)
    shutil.rmtree(os.path.dirname(s_file), ignore_errors=True)
    return rc


def main():
    ccdir, args = sys.argv[1], sys.argv[2:]
    gcc = os.path.join(ccdir, "bin", "ee-gcc")
    src = next((a for a in args if a.endswith((".c", ".cpp")) and os.path.isfile(a)), None)
    if src is None or not needs_mirror(src):
        sys.exit(compile_two_step(gcc, args, os.getcwd()) if src else subprocess.call([gcc] + args))

    out_i = args.index("-o") + 1
    out = args[out_i]
    tmp = tempfile.mkdtemp(prefix="cc_native.")
    try:
        unit_dirs = set()
        # the unit's INCLUDE_ASM directories: INCLUDE_ASM("seg/seg_325220", f) -> asm/nonmatchings/seg/seg_325220
        for line in open(src, errors="replace"):
            if "INCLUDE_ASM(\"" in line:
                unit_dirs.add(line.split("INCLUDE_ASM(\"", 1)[1].split("\"", 1)[0])
        new_args = list(args)
        for a in args:
            for prefix in ("-Wa,-I", "-I", ""):
                p = a[len(prefix):] if a.startswith(prefix) else None
                if p and not p.startswith("-") and os.path.isdir(p) and not os.path.isabs(p):
                    if p.rstrip("/") == "asm/nonmatchings":
                        for u in unit_dirs:
                            if os.path.isdir(os.path.join(p, u)):
                                shutil.copytree(os.path.join(p, u), os.path.join(tmp, p, u), dirs_exist_ok=True,
                                                copy_function=copy_text_lf)
                    else:
                        shutil.copytree(p, os.path.join(tmp, p), dirs_exist_ok=True, copy_function=copy_text_lf)
                    break
        os.makedirs(os.path.join(tmp, os.path.dirname(src)), exist_ok=True)
        copy_text_lf(src, os.path.join(tmp, src))
        new_args[out_i] = os.path.join(tmp, "out.o")
        rc = compile_two_step(gcc, new_args, tmp)
        if rc == 0:
            os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
            shutil.copyfile(os.path.join(tmp, "out.o"), out)
        sys.exit(rc)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


if __name__ == "__main__":
    main()
