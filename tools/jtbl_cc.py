#!/usr/bin/env python3
"""Compile a unit, pointing each switch jump table that is verified identical at the retail `jtbl_*` symbol.

    python3 tools/jtbl_cc.py --unit UNIT -- <compiler argv with -c SRC ... -o OUT.o>

Why: splat leaves every jump table in the shared rodata segment as raw words (asm/data/*.rodata.s,
`dlabel jtbl_X`), and the retail functions name it (`lui %hi(jtbl_X)`). Our C makes the compiler emit its own
copy into the unit's .rodata (`.rdata / $L16: / .word $L8 ...`, referenced as `%hi($L16)`), so objdiff sees
`jtbl_X` against `[.rodata]` and no function with a switch table can reach 100%, even when its code is
identical. The original toolchain also emitted a local table per unit; the shared, named one is a splat artifact
(the same situation as the .lit4 literal pool; configure.py `rewrite_lit4_loads_for_objdiff`).

What it does: compile to assembly, then assemble it once as is, with gas `-L` so the local labels are in the
symbol table. For each function, the k-th jump table it references is paired with the k-th jtbl_* its retail
asm references (asm/nonmatchings/UNIT/FUNC.s). The pair is accepted only if every entry points at the same
offset from the start of the function as the retail word (word - retail start address) and any retail words
past our last entry are 0 (alignment padding). Accepted tables are dropped from the assembly and their
%hi/%lo references renamed to jtbl_X; then the assembly is assembled again into OUT.o. A table that doesn't
verify is left as is, so the function still mismatches. Without any jump table the output is the same object
the plain `-c` compile gives (the driver also compiles to assembly and assembles it).

Also usable as a library by wrappers that already compile via -S (tools/gen/hybrid_cc.py in the workspace):
repoint(asm_text, unit, assemble) -> (new_asm_text, log lines).
"""
import re
import subprocess
import sys
from functools import lru_cache
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

TABLE = re.compile(r"^\s*\.rdata\s*\n(?:\s*\.align\s+\d+\s*\n)?(\$L\d+):\s*\n((?:\s*\.word\s+\$L\d+\s*\n)+)\s*\.text\s*\n", re.M)


@lru_cache(maxsize=None)
def retail_tables() -> dict[str, list[int]]:
    """jtbl_X -> its words, from splat's data asm."""
    out = {}
    for f in (ROOT / "asm/data").glob("*.s"):
        text = f.read_text(errors="replace")
        if "dlabel jtbl_" not in text:
            continue
        for name, body in re.findall(r"dlabel (jtbl_[0-9A-F]+)\n(.*?)enddlabel \1", text, re.S):
            out[name] = [int(w, 16) for w in re.findall(r"\.word 0x([0-9A-Fa-f]+)", body)]
    return out


def retail_func(unit: str, func: str) -> tuple[int, list[str]] | None:
    """(start address, jtbl_* names in order of first reference) from the function's retail asm."""
    p = ROOT / "asm/nonmatchings" / unit / f"{func}.s"
    if not p.exists():
        hits = list((ROOT / "asm/nonmatchings").rglob(f"{func}.s"))
        if len(hits) != 1:
            return None
        p = hits[0]
    text = p.read_text(errors="replace")
    m = re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", text)
    if not m:
        return None
    names = []
    for n in re.findall(r"%hi\((jtbl_[0-9A-F]+)\)", text):
        if n not in names:
            names.append(n)
    return int(m.group(1), 16), names


def local_symbols(obj: Path) -> dict[str, int]:
    """name -> value, from `readelf -s` of an object assembled with -L."""
    r = subprocess.run(["mips-linux-gnu-readelf", "-sW", str(obj)], capture_output=True, text=True, check=True)
    syms = {}
    for line in r.stdout.splitlines():
        f = line.split()
        if len(f) >= 8 and f[0].endswith(":") and re.fullmatch(r"[0-9a-fA-F]{8}", f[1]):
            syms.setdefault(f[7], int(f[1], 16))
    return syms


def functions(text: str):
    """(name, start, end) character spans of each `.ent NAME` ... `.end NAME` block."""
    for m in re.finditer(r"^\s*\.ent\s+(\S+)\s*$", text, re.M):
        e = re.compile(r"^\s*\.end\s+%s\s*$" % re.escape(m.group(1)), re.M).search(text, m.end())
        if e:
            yield m.group(1), m.start(), e.end()


def repoint(text: str, unit: str, assemble) -> tuple[str, list[str]]:
    """assemble(asm_text, extra_flags) -> object Path. Returns the rewritten assembly and a log."""
    if not TABLE.search(text):
        return text, []
    syms = local_symbols(assemble(text, ["-Wa,-L"]))
    log = []
    for func, a, b in reversed(list(functions(text))):  # back to front: earlier spans stay valid
        body = text[a:b]
        tables = list(TABLE.finditer(body))
        if not tables:
            continue
        info = retail_func(unit, func)
        if info is None or func not in syms:
            log.append(f"{func}: no retail asm, tables left local")
            continue
        start, names = info
        if len(names) != len(tables):
            log.append(f"{func}: {len(tables)} tables here, {len(names)} in retail; left local")
            continue
        accepted = []
        for t, name in zip(tables, names):
            label, entries = t.group(1), re.findall(r"\$L\d+", t.group(2))
            ours = [syms.get(e, -1) - syms[func] for e in entries]
            words = retail_tables().get(name)
            if words is None or len(words) < len(ours):
                log.append(f"{func}: {name} missing or shorter than {label}; left local")
                continue
            if ours != [w - start for w in words[:len(ours)]] or any(words[len(ours):]):
                log.append(f"{func}: {label} differs from {name}; left local")
                continue
            accepted.append((t, name))
            log.append(f"{func}: {label} -> {name} ({len(ours)} entries)")
        for t, name in reversed(accepted):
            body = body[:t.start()] + body[t.end():]
        for t, name in accepted:
            body = re.sub(r"%(hi|lo)\(" + re.escape(t.group(1)) + r"\)", lambda m, n=name: f"%{m.group(1)}({n})", body)
        text = text[:a] + body + text[b:]
    return text, log


def main() -> None:
    args = sys.argv[1:]
    unit = args[args.index("--unit") + 1]
    argv = args[args.index("--") + 1:]
    out = Path(argv[argv.index("-o") + 1])
    src = next(a for a in argv if a.endswith((".cpp", ".c")))

    s_path = Path(str(out) + ".jt.s")
    cmd = list(argv)
    cmd[cmd.index("-c")] = "-S"
    cmd[cmd.index("-o") + 1] = str(s_path)
    r = subprocess.run(cmd, capture_output=True, text=True)
    sys.stderr.write(r.stderr)
    if r.returncode:
        sys.exit(r.returncode)

    asm_base = [a for a in argv if a not in ("-xc++", "-xc")]

    def assemble(text: str, extra: list[str], dest: Path | None = None) -> Path:
        dest = dest or Path(str(out) + ".jtcheck.o")
        path = Path(str(dest) + ".s")
        path.write_text(text)
        c = list(asm_base)
        c[c.index(src)] = str(path)
        c[c.index("-o") + 1] = str(dest)
        c[c.index("-c"):c.index("-c") + 1] = ["-c", *extra]
        rr = subprocess.run(c, capture_output=True, text=True)
        if rr.returncode and ".org" in rr.stderr and "backwards" in rr.stderr:
            # gas relaxation with INCLUDE_ASM `.org` slots (-DASM_OFFSETS): a function that fills its slot exactly can
            # make the second relax pass grow (R5900 short-loop nop / alignment decided on stale frag addresses) and
            # then fail with "attempt to .org backwards" depending only on how much C precedes it in the file. Any
            # listing option (-an: no source, no forms) makes gas lay the frags out consistently; retry with it.
            lst = Path(str(dest) + ".lst")
            c2 = list(c)
            c2[c2.index("-c") + 1:c2.index("-c") + 1] = ["-Wa,-an=" + str(lst)]
            rr = subprocess.run(c2, capture_output=True, text=True)
            lst.unlink(missing_ok=True)
        if rr.returncode:
            sys.stderr.write(rr.stderr)
            sys.exit(rr.returncode)
        path.unlink()
        return dest

    text = s_path.read_text()
    new, log = repoint(text, unit, assemble)
    assemble(new, [], out)
    for p in (s_path, Path(str(out) + ".jtcheck.o")):
        p.unlink(missing_ok=True)
    if log and "-v" in args[:args.index("--")]:
        sys.stderr.write("".join(f"jtbl_cc: {l}\n" for l in log))


if __name__ == "__main__":
    main()
