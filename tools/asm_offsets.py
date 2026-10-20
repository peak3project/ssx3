#!/usr/bin/env python3
"""Write the target offset of every INCLUDE_ASM'd function of one unit, for position-faithful obj/current.

SN's assembler pads short loops with nops depending on where the loop sits in the section, so a matched
function only reproduces the target bytes at its target offset. obj/current (-DSKIP_ASM) contains only the
C functions; with -DASM_OFFSETS each INCLUDE_ASM becomes `.org __off_<NAME>` (include/include_asm.h), which
puts every C function at the offset it has in obj/target. The skipped asm functions leave zero-filled gaps
with no symbols, so they still count as unmatched.

usage: tools/asm_offsets.py SRC.cpp TARGET.o OUT.inc
"""
import re
import subprocess
import sys
from pathlib import Path

ASM_ROOT = Path("asm/nonmatchings")


def main() -> None:
    src, target, out = (Path(a) for a in sys.argv[1:4])
    syms = {}
    readelf = subprocess.run(["mips-linux-gnu-readelf", "-sW", str(target)], capture_output=True, text=True, check=True)
    for line in readelf.stdout.splitlines():
        f = line.split()
        if len(f) >= 8 and f[3] == "FUNC" and f[6] == "1":
            syms[f[7]] = int(f[1], 16)
    lines = []
    text = src.read_text(errors="ignore")
    starts = sorted(set(syms.values()))
    incs = list(re.finditer(r'^INCLUDE_ASM\("([^"]+)",\s*(\w+)\);[^\n]*\n(\s*#ifdef SKIP_ASM)?', text, re.M))
    for k, m0 in enumerate(incs):
        folder, name, matched = m0.group(1), m0.group(2), m0.group(3)
        # only a slot with nothing but comments/preprocessor lines up to the next INCLUDE_ASM can be filled exactly;
        # if other C (methods, helpers, data) is emitted in between, keep the old .org-only behaviour
        between = text[m0.end():incs[k + 1].start() if k + 1 < len(incs) else len(text)]
        between = re.sub(r'/\*.*?\*/|//[^\n]*', '', between, flags=re.S)
        between = '\n'.join(l for l in between.split('\n') if not l.strip().startswith('#'))
        plain = not between.strip()
        asm = ASM_ROOT / folder / f"{name}.s"
        m = re.search(r"^\s*glabel\s+(\S+)", asm.read_text(errors="ignore"), re.M) if asm.exists() else None
        sym = m.group(1) if m else name
        if sym in syms:
            off = syms[sym]
            lines.append(f"__off_{name} = 0x{off:X}\n")
            # An unmatched function's slot is filled with a fixed-size .space (up to the next function) instead of
            # being left to the next .org: gas makes its alignment and short-loop decisions on provisional frag
            # addresses, which skip .org gaps, so without this a C function's padding depended on how much C
            # precedes it in the file.
            nxt = [a for a in starts if a > off]
            # The fill is a literal .space (an assembler macro, so the size is a constant; `.space symbol` would
            # be a variable frag again). Only for C units: g++ can emit code (out-of-line inlines, thunks) that is
            # not visible between the INCLUDE_ASM lines, and exact fills then overflow the next .org.
            if not matched and plain and nxt and src.suffix == ".c":
                lines.append(f"__size_{name} = 0x{nxt[0] - off:X}\n"
                             f".macro __fill_{name}\n.space 0x{nxt[0] - off:X}\n.endm\n")
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text("".join(lines))


if __name__ == "__main__":
    main()
