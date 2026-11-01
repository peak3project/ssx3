"""cc_native.py <ccdir> <gcc args...>: run a Linux-native 32-bit ee-gcc (e.g. Sony's ee-gcc 2.9-ee-991111) on a unit.

These old i386 builds use 32-bit stat(), so on filesystems with 64-bit inode numbers (WSL's /mnt drives, some
network mounts) every open of a source or include file fails with "Value too large for defined data type". In that
case the inputs the compile needs (the .c file, the -I/-isystem/-Wa,-I directories it references) are mirrored into
a temporary directory on the local filesystem, the compiler runs there, and the object is copied back. Text inputs
are copied with LF line endings (a CRLF checkout breaks this preprocessor's line continuations). When the working
directory is already on a local filesystem the compiler runs in place.
"""

import os
import re
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


# ---- opt-in delay-slot fill (configure.py UNIT_AS_SWAP) ---------------------------------------------------------
#
# The retail SDK objects in the ee-gcc 2.9 units were assembled by a reorder-mode assembler that moves the instruction
# before an unfilled branch into its delay slot (binutils 2.9-era behaviour). The ee-as shipped with 2.9-ee-991111
# never does, so every slot cc1 left open (it keeps volatile accesses out of slots) stays `branch; nop` here while the
# retail code has `branch; insn`. This pass applies the same swap to the compiler's text before it is assembled.
# Rules (written from observation of the retail objects and gas's documented behaviour; see ssx3-tools WORKER.md 23):
#  * only in `.set reorder` regions, for a branch/jump without a label on it and no directive between it and the
#    previous instruction; branch-likely slots are never filled (they are annulled when not taken);
#  * the moved instruction is the one directly before the branch; it must be a single real instruction (no macro:
#    li/dli/li.s/la/div with 3 operands/... expand inside the assembler and act like a `.set noreorder` block), not a
#    branch, nop, sync, break, syscall, trap, cache, eret, ei/di or COP0 move;
#  * neither the previous instruction nor the one before it may have been emitted in `.set noreorder` mode (the
#    assembler clears its history at `.set reorder`; the first instruction after a noreorder block is never moved);
#  * no hazard: the branch does not read a GPR the moved instruction writes; a linking branch (jal/bal/jalr/bXzal)
#    needs the moved instruction not to touch $31 (or jalr's link register); a coprocessor condition branch (bc1x/bc2x)
#    does not take a compare, control-register or data move of that coprocessor; mfhi/mflo stay before conditional
#    branches (HI/LO hazard with a mult at the target); loads already satisfy the GPR rule (interlocked EE).
# The swapped pair is emitted inside `.set noreorder`/`.set reorder` so ee-as adds no nop.

FILL_FLAG = "--fill-delay-slots"

GPR_NAMES = {"zero": 0, "at": 1, "v0": 2, "v1": 3, "a0": 4, "a1": 5, "a2": 6, "a3": 7, "t0": 8, "t1": 9, "t2": 10,
             "t3": 11, "t4": 12, "t5": 13, "t6": 14, "t7": 15, "s0": 16, "s1": 17, "s2": 18, "s3": 19, "s4": 20,
             "s5": 21, "s6": 22, "s7": 23, "t8": 24, "t9": 25, "k0": 26, "k1": 27, "gp": 28, "sp": 29, "fp": 30,
             "s8": 30, "ra": 31}
GPR_RE = re.compile(r"\$(\d+|" + "|".join(GPR_NAMES) + r")(?![\w.])")
COND_BRANCHES = {"beq", "bne", "beql", "bnel", "blez", "bgtz", "bltz", "bgez", "blezl", "bgtzl", "bltzl", "bgezl",
                 "beqz", "bnez", "beqzl", "bnezl", "bltzal", "bgezal", "bltzall", "bgezall"}
COP_BRANCHES = {"bc0f", "bc0t", "bc0fl", "bc0tl", "bc1f", "bc1t", "bc1fl", "bc1tl", "bc2f", "bc2t", "bc2fl", "bc2tl"}
BRANCHES = COND_BRANCHES | COP_BRANCHES | {"b", "bal", "j", "jal", "jr", "jalr"}
LINK_BRANCHES = {"jal", "bal", "jalr", "bltzal", "bgezal", "bltzall", "bgezall"}
LIKELY_BRANCHES = {m for m in COND_BRANCHES | COP_BRANCHES if m.endswith("l") and m not in ("bltzal", "bgezal")}
# never moved into a slot (gas treats them as unmovable or as macro expansions)
UNMOVABLE = {"nop", "sync", "sync.l", "sync.p", "break", "syscall", "eret", "ei", "di", "cache", "pref", "mfc0", "mtc0",
             "tlbr", "tlbwi", "tlbwr", "tlbp", "teq", "tne", "tge", "tgeu", "tlt", "tltu", "teqi", "tnei", "tgei",
             "tgeiu", "tlti", "tltiu", "mtc1", "mfc1", "dmtc1", "dmfc1", "ctc1", "cfc1", "mtc2", "mfc2", "qmtc2",
             "qmfc2", "ctc2", "cfc2"}
MACROS = {"dli", "li.s", "li.d", "la", "dla", "ulw", "uld", "ulh", "ulhu", "usw", "usd", "ush", "seq", "sne", "sge",
          "sgeu", "sgt", "sgtu", "sle", "sleu", "rem", "remu", "drem", "dremu", "mul", "dmul", "abs", "dabs", "bge",
          "bgt", "ble", "blt", "bgeu", "bgtu", "bleu", "bltu", "bgel", "bgtl", "blel", "bltl", "bgeul", "bgtul",
          "bleul", "bltul"}
STORES = {"sb", "sh", "sw", "sd", "sq", "swl", "swr", "sdl", "sdr", "swc1", "sdc1", "swc2", "sqc2", "s.s", "s.d"}
NO_GPR_DEST = STORES | {"mult", "multu", "dmult", "dmultu", "div", "divu", "ddiv", "ddivu", "madd", "maddu", "mthi",
                        "mtlo", "mtsa", "mtc1", "dmtc1", "ctc1", "mtc2", "qmtc2", "ctc2", "mtc0"}
COP1_MOVES = {"mtc1", "mfc1", "dmtc1", "dmfc1", "ctc1", "cfc1"}
HILO_READS = {"mfhi", "mflo"}


def gprs(op):
    """GPR numbers named in one operand (`$2`, `$sp`, `0($16)`, `%lo(x)($3)`; `$f0`/`$L5` are not GPRs)."""
    out = []
    for m in GPR_RE.finditer(op):
        r = m.group(1)
        out.append(int(r) if r.isdigit() else GPR_NAMES[r])
    return out


def insn_regs(mn, ops):
    """(written GPRs, read GPRs) of a plain instruction; coprocessor moves name only one GPR."""
    if mn in COP1_MOVES or mn in ("mfc0", "mtc0", "mtc2", "mfc2", "qmtc2", "qmfc2", "ctc2", "cfc2"):
        ops = ops[:1]
    regs = [gprs(o) for o in ops]
    if not regs:
        return set(), set()
    if mn in NO_GPR_DEST and not (mn in ("mult", "multu", "madd", "maddu") and len(ops) == 3):
        return set(), set(sum(regs, []))
    dest = set(regs[0]) if ops[0].startswith("$") else set()
    reads = set(sum(regs[1:], [])) | (set(regs[0]) - dest)
    if mn in ("movz", "movn"):
        reads |= dest
    return dest - {0}, reads


def li_is_macro(ops):
    """`li rd,imm` is one instruction when imm fits addiu/ori or is a lui constant; otherwise lui+ori."""
    try:
        v = int(ops[1].split("#")[0].strip(), 0)
    except (ValueError, IndexError):
        return True
    return not (-0x8000 <= v <= 0xFFFF or (v & 0xFFFF) == 0 and -0x80000000 <= v <= 0xFFFFFFFF)


def fill_delay_slots(text, log=None):
    """Move the previous instruction into the delay slot of unfilled reorder-mode branches (rules above)."""
    lines = text.split("\n")
    noreorder, stack = False, []
    prev_flag = pp_flag = 0          # emitted-in-noreorder flags of the previous and the pre-previous instruction
    prev = None                      # (line index, mnemonic, operands) of the previous instruction, None if unusable
    pending = False                  # a label or a non-.set directive since the previous instruction
    swaps = []
    for i, raw in enumerate(lines):
        line = raw.split("#", 1)[0].strip() if not raw.lstrip().startswith("#") else ""
        if not line:
            continue
        m = re.match(r"^([\w$.]+):\s*(.*)$", line)
        if m:
            pending = True
            line = m.group(2).strip()
            if not line:
                continue
        if line.startswith("."):
            d = line.split()
            if d[0] == ".set" and len(d) > 1:
                opt = d[1].rstrip(",")
                if opt == "noreorder":
                    noreorder = True
                elif opt == "reorder":
                    if noreorder:
                        prev_flag = pp_flag = 1
                    noreorder = False
                elif opt == "push":
                    stack.append(noreorder)
                elif opt == "pop" and stack:
                    noreorder = stack.pop()
            else:
                pending = True
            continue
        parts = line.split(None, 1)
        mn = parts[0]
        ops = [o.strip() for o in parts[1].split(",")] if len(parts) > 1 else []
        macro = mn in MACROS or (mn == "li" and li_is_macro(ops)) or \
            (mn in ("div", "divu", "ddiv", "ddivu") and len(ops) == 3)
        if noreorder or macro:
            pp_flag, prev_flag = prev_flag, 1
            prev, pending = None if macro else (i, mn, ops), False
            continue
        if mn in BRANCHES:
            if mn in ("j", "jal") and ops and ops[-1].startswith("$"):    # cc1 writes jr/jalr as `j $4`, `jal $31,$2`
                mn = "jr" if mn == "j" else "jalr"
            swapped = False
            if prev is not None and not pending and not prev_flag and not pp_flag:
                pmn, pops = prev[1], prev[2]
                movable = pmn not in BRANCHES and pmn not in UNMOVABLE
                likely = mn in LIKELY_BRANCHES
                if movable and not likely:
                    pw, pr = insn_regs(pmn, pops)
                    if mn in ("jr", "jalr"):
                        breads = set(gprs(ops[-1]))
                    elif mn in COND_BRANCHES:
                        breads = set(gprs(ops[0])) | (set(gprs(ops[1])) if mn in ("beq", "bne", "beql", "bnel") else set())
                    else:
                        breads = set()
                    link = {31} if mn in LINK_BRANCHES else set()
                    if mn == "jalr" and len(ops) == 2:
                        link = set(gprs(ops[0]))
                    ok = not (pw & breads) and not ((pw | pr) & link)
                    if mn in COP_BRANCHES:
                        cop = mn[2]
                        ok = ok and not (cop == "1" and (pmn in COP1_MOVES or pmn.startswith("c.")))
                        ok = ok and not (cop == "2" and (pmn.startswith("v") or pmn.endswith("c2")))
                        ok = ok and not (cop == "0" and pmn.endswith("c0"))
                    if pmn in HILO_READS and mn in COND_BRANCHES | COP_BRANCHES:
                        ok = False
                    if ok:
                        swaps.append((prev[0], i))
                        swapped = True
                if log is not None:
                    log.append((i, lines[prev[0]].strip(), line, swapped))
            # the branch, then (unless filled) the assembler's nop: both in reorder mode
            pp_flag, prev_flag = (prev_flag, 0) if swapped else (0, 0)
        else:
            pp_flag, prev_flag = prev_flag, 0
        prev, pending = (i, mn, ops), False
    for p, b in swaps:
        label, insn = re.match(r"^(\s*(?:[\w$.]+:)?)\s*(.*)$", lines[p]).groups()
        lines[p] = label + "\n\t.set\tnoreorder\n" + lines[b] + "\n\t" + insn + "\n\t.set\treorder"
        lines[b] = None
    return "\n".join(l for l in lines if l is not None)



def compile_two_step(gcc, args, cwd):
    """gcc -S, inline the .include directives, then assemble the result with the same flags."""
    fill_slots = FILL_FLAG in args                  # configure.py UNIT_AS_SWAP, passed in the unit's cflags
    args = [a for a in args if a != FILL_FLAG]
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
    if fill_slots:
        filled = fill_delay_slots(open(s_file, encoding="latin-1").read())
        open(s_file, "w", encoding="latin-1").write(filled)
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
