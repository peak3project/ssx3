#!/usr/bin/env python3
"""Compile a unit for obj/current and assemble it with SN's Ps2EeAs instead of the driver's GNU as.

    python3 tools/ps2eeas_cc.py --unit UNIT --as PS2EEAS.exe -- <compiler argv with -c SRC ... -o OUT.o>

Why (fork): the retail newlib unit (seg/seg_316F98) was assembled with SN's own Ps2EeAs, not GNU as. Only Ps2EeAs
expands `dli 0xffffffff` as `li -1; dsrl32`, builds 64-bit constants with its ori/dsll16/dsll14 chain and pads
short loops that contain an inner exit branch; with GNU as those functions can't reach 100% from any C. The
normal (linked) build is not affected: it assembles every function from its asm.

What it does: compile to assembly (-S, without -DASM_OFFSETS: Ps2EeAs can't read `.include`/`.org`), repoint the
switch jump tables with tools/jtbl_cc.py (verified with GNU as, which keeps local labels), then assemble the
result with Ps2EeAs in a local temp dir (it fails on large files on some mounts, and wants LF input).
"""
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import jtbl_cc  # noqa: E402


def main() -> None:
    args = sys.argv[1:]
    unit = args[args.index("--unit") + 1]
    ps2as = args[args.index("--as") + 1]
    argv = [a for a in args[args.index("--") + 1:] if a != "-DASM_OFFSETS" and not a.startswith("-Wa,-Iobj/offsets")]
    out = Path(argv[argv.index("-o") + 1])
    src = next(a for a in argv if a.endswith((".cpp", ".c")))
    tmp = Path(tempfile.mkdtemp(prefix="ps2eeas_"))
    try:
        s_path = tmp / "unit.s"
        cmd = list(argv)
        cmd[cmd.index("-c")] = "-S"
        cmd[cmd.index("-o") + 1] = str(s_path)
        r = subprocess.run(cmd, capture_output=True, text=True)
        sys.stderr.write(r.stderr)
        if r.returncode:
            sys.exit(r.returncode)

        asm_base = [a for a in argv if a not in ("-xc++", "-xc")]

        def gas(text: str, extra: list, dest: Path = None) -> Path:
            dest = dest or tmp / "check.o"
            path = Path(str(dest) + ".s")
            path.write_text(text)
            c = list(asm_base)
            c[c.index(src)] = str(path)
            c[c.index("-o") + 1] = str(dest)
            c[c.index("-c"):c.index("-c") + 1] = ["-c", *extra]
            rr = subprocess.run(c, capture_output=True, text=True)
            if rr.returncode:
                sys.stderr.write(rr.stderr)
                sys.exit(rr.returncode)
            return dest

        text = s_path.read_text().replace("\r\n", "\n")
        new, _log = jtbl_cc.repoint(text, unit, gas)
        final = tmp / "final.s"
        final.write_text(new, newline="\n")
        obj = tmp / "final.o"
        rr = subprocess.run(["wine", ps2as, "-G0", str(final), "-o", str(obj)], capture_output=True, text=True,
                            env=dict(os.environ, WINEDEBUG="-all"))
        if rr.returncode or not obj.exists():
            sys.stderr.write(rr.stdout + rr.stderr)
            sys.exit(rr.returncode or 1)
        shutil.copyfile(obj, out)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


if __name__ == "__main__":
    main()
