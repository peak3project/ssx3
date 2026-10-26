#!/usr/bin/env python3
import argparse
import os
import shutil
import subprocess
import sys
import json
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"
OUTDIR = "out"

# Kept relative (not ROOT / ...) so splat resolves base_path relatively too;
# otherwise it bakes this machine's absolute path into generated files like
# include/macro.inc's ".include" directives.
YAML_FILE = Path("config") / "ssx3_us.yaml"
BASENAME = "SLUS_207.72"
LD_PATH = f"{BASENAME}.ld"
ELF_PATH = f"{OUTDIR}/{BASENAME}"
MAP_PATH = f"{OUTDIR}/{BASENAME}.map"
PRE_ELF_PATH = f"{OUTDIR}/{BASENAME}.elf"

COMMON_INCLUDES = "-Iinclude -isystem include/sdk/ee -isystem include/gcc"
if sys.platform == "darwin":
    # macOS has no /usr/include for the compiler to fall back on (under Linux
    # + Wine it picks up the host's glibc headers there, e.g. <stdint.h>), so
    # supply the few headers the sources need from tools/macos/include.
    COMMON_INCLUDES += " -isystem tools/macos/include"


# The compiler is SN V1.36 with its dormant `vec_mark` insn switched on (see tools/patch_vecmark.py):
# the retail code shows EA's compiler emitted it in every empty array-ctor loop. The patched copy is
# generated from the stock download on first configure.
STOCK_CC_DIR = f"{TOOLS_DIR}/cc/eegcc-2.95.3-V1.36"
CC_DIR = f"{TOOLS_DIR}/cc/eegcc-2.95.3-V1.36-vecmark"
if not os.path.isdir(CC_DIR) and os.path.isdir(STOCK_CC_DIR):
    subprocess.run([sys.executable, f"{TOOLS_DIR}/patch_vecmark.py", STOCK_CC_DIR, CC_DIR], check=True)
DRIVER_PATH_FLAG = f"-B{CC_DIR}/lib/gcc-lib/ee/2.95.3/"

# See tools/cc/README.md for how these were gathered
COMMON_CFLAGS = "-O2"
# Fork-only: per-unit extra compiler flags. EA's support library (ealib/) was built with -G0 (no $gp small data:
# globals and float constants are addressed with lui/%lo and lui/ori/mtc1), except one embedded module at
# 0x3D6498-0x3DBAE8 (ealib/seg_2D7498) that uses $gp and default flags. Evidence: notes/stuck.md "ealib".
UNIT_CFLAGS = {
    "ealib/seg_2B4578": "-G0",
    "ealib/seg_2DCAE8": "-G0",
    # Library tail of .text (0x3EDF50-0x42E590), split by the same evidence: seg_2F0F40, seg_313F58 (C library:
    # strchr/strcpy/sprintf/ungetc) and seg_325220 reach .sdata/.sbss globals with lui/%lo and never via $gp.
    "seg/seg_2F0F40": "-G0",
    # Sony SDK area (ee-gcc 2.9). Its libm block loads float constants inline (li.s through $at, no $gp pool) and
    # its assembler did not pad lwc1/mtc1 hazards (the EE interlocks them); -Wa,-mips4 drops that padding. Every
    # matched function of the unit is unchanged by both flags (full-unit check, 2026-10-26).
    "seg/seg_2FE810": "-G0 -Wa,-mips4",
    "seg/seg_3113A0_eh": "-fexceptions",
    "seg/seg_313800_exception": "-G0 -fexceptions",
    "seg/seg_313F58": "-G0",
    "seg/seg_315B68_tinfo": "-G0",
    "seg/seg_316FB8": "-G0",
    "seg/seg_325220": "-G0",
    "seg/seg_32F020": "-G0",
    # Units whose retail code was compiled WITH exceptions (the default of g++ 2.95): their functions only match
    # with -fexceptions, and every already-matched function in them is unchanged by it (full-build check, 2026-10-21).
    # Per-unit flags come after COMMON_CXXFLAGS, so this overrides the -fno-exceptions default.
    "main/loadscreens_prestart": "-fexceptions",
}
# Fork-only: per-unit compiler. EA's embedded $gp module (ealib/seg_2D7498, 0x3D6498-0x3DBAE8) was built with an
# older SN build, ee-gcc 2.95.3-114 (its non-leaf functions save ra with sq; 107 and 114 reproduce all 48 landed
# functions plus the sq-ra prologues, 136 does not). Local copy from the decomp.me PS2 compiler bundle; if it is
# missing the unit falls back to the default compiler (and those functions just don't match).
UNIT_CC = {
    "ealib/seg_2D7498": f"{TOOLS_DIR}/cc/eegcc-2.95.3-114",
}
for _u, _d in list(UNIT_CC.items()):
    if not os.path.isfile(f"{_d}/bin/ee-gcc2953.exe"):
        print(f"warning: {_d} missing; {_u} builds with the default compiler")
        del UNIT_CC[_u]
# Fork-only: units built with Sony's ee-gcc 2.9-ee-991111 (Linux-native i386 build, decomp.me PS2 compiler bundle).
# Most of the Sony SDK and runtime library code in .text was compiled with it: its non-leaf functions save callee
# registers with `sd $16,0($sp); sd $31,0x10($sp)`, which neither SN 2.95.3 build produces (they use sq). Unit edges
# sit where that fingerprint starts and stops. Override the location with EE_GCC29_DIR; if the compiler is missing
# (or not on Linux) these units fall back to the default compiler and those functions just don't match.
EE_GCC29_DIR = os.environ.get("EE_GCC29_DIR", f"{TOOLS_DIR}/cc/ee-gcc2.9-991111")
UNIT_CC_NATIVE = {
    "seg/seg_2FE810": EE_GCC29_DIR,
    "seg/seg_3113A0_eh": EE_GCC29_DIR,
    "seg/seg_312310": EE_GCC29_DIR,
    "seg/seg_313800_exception": EE_GCC29_DIR,
    "seg/seg_313F58": EE_GCC29_DIR,
    "seg/seg_315B68_tinfo": EE_GCC29_DIR,
    "seg/seg_325220": EE_GCC29_DIR,
}
if not sys.platform.startswith("linux") or not os.path.isfile(f"{EE_GCC29_DIR}/bin/ee-gcc"):
    if UNIT_CC_NATIVE:
        print(f"warning: {EE_GCC29_DIR}/bin/ee-gcc missing or not on Linux; ee-gcc 2.9 units build with the default compiler")
    UNIT_CC_NATIVE = {}
# Fork-only: units whose retail code was assembled with SN's own Ps2EeAs, not the driver's GNU as. In the newlib unit
# only Ps2EeAs reproduces `li -1; dsrl32` for `dli 0xffffffff`, its ori/dsll16/dsll14 64-bit constant chains and its
# short-loop nops in loops with an inner exit branch (all 23 retail `addiu -1; dsrl32 0` pairs are in this unit).
# Affects obj/current only (tools/ps2eeas_cc.py); the linked build assembles these functions from their asm. Set
# SSX3_NO_PS2EEAS=1 to use GNU as instead; if Ps2EeAs.exe is missing the unit uses GNU as (those functions don't match).
PS2EEAS = os.environ.get("PS2EEAS", f"{STOCK_CC_DIR}/ee/bin/Ps2EeAs.exe")
UNIT_PS2EEAS = {"seg/seg_316FB8"}
if os.environ.get("SSX3_NO_PS2EEAS") or not os.path.isfile(PS2EEAS):
    if UNIT_PS2EEAS and not os.environ.get("SSX3_NO_PS2EEAS"):
        print(f"warning: {PS2EEAS} missing; {', '.join(sorted(UNIT_PS2EEAS))} use GNU as")
    UNIT_PS2EEAS = set()
# The game was built without C++ exception support: its constructors and destructors have no EH cleanup
# landing pads, which g++ 2.95 emits by default (e.g. cAngerFX_cAngerFX only matches with -fno-exceptions).
COMMON_CXXFLAGS = "-fno-exceptions"

# splat's generated INCLUDE_ASM macro emits `.include "FOLDER/NAME.s"` relative
# to the nonmatchings dir (no longer hardcodes "asm/nonmatchings/"), so the
# internal assembler needs that dir on its include search path.
ASM_INCLUDE_FLAG = "-Wa,-Iasm/nonmatchings"

COMPILE_C_RULE = f"{CC_DIR}/bin/ee-gcc2953.exe -c {COMMON_INCLUDES} {ASM_INCLUDE_FLAG} {DRIVER_PATH_FLAG} {COMMON_CFLAGS} $in"
COMPILE_CXX_RULE = f"{CC_DIR}/bin/ee-gcc2953.exe -xc++ -c {COMMON_INCLUDES} {ASM_INCLUDE_FLAG} {DRIVER_PATH_FLAG} {COMMON_CFLAGS} {COMMON_CXXFLAGS} $in"

CATEGORY_MAP = {
    "sce": "Libs",
    "data": "Data",
}

WINE = "wine"
if sys.platform == "linux" or sys.platform == "linux2":
    COMPILE_C_RULE = f"{WINE} {COMPILE_C_RULE}"
    COMPILE_CXX_RULE = f"{WINE} {COMPILE_CXX_RULE}"
elif sys.platform == "darwin":
    # macOS: run the Windows compiler with wibo (decompals/wibo, the
    # `wibo-macos` release asset; runs under Rosetta 2 on Apple Silicon)
    # instead of Wine. Uses $WIBO, else tools/wibo/wibo, else `wibo` on PATH.
    _wibo_local = TOOLS_DIR / "wibo" / "wibo"
    WIBO = os.environ.get("WIBO") or (str(_wibo_local) if _wibo_local.exists() else "wibo")
    COMPILE_C_RULE = f"{WIBO} {COMPILE_C_RULE}"
    COMPILE_CXX_RULE = f"{WIBO} {COMPILE_CXX_RULE}"

def clean():
    files_to_clean = [
        ".splache",
        ".ninja_log",
        "build.ninja",
        "permuter_settings.toml",
        LD_PATH
    ]
    for filename in files_to_clean:
        if os.path.exists(filename):
            os.remove(filename)

    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("obj", ignore_errors=True)
    shutil.rmtree("out", ignore_errors=True)


def write_permuter_settings():
    with open("permuter_settings.toml", "w", encoding="utf-8") as f:
        f.write(f"""compiler_command = "{COMPILE_CXX_RULE} -D__GNUC__"
assembler_command = "mips-linux-gnu-as -march=r5900 -mabi=eabi -Iinclude"
compiler_type = "gcc"

[preserve_macros]

[decompme.compilers]
"tools/cc/eegcc-2.95.3-V1.36-vecmark/bin/gcc" = "eegcc-2.95.3-V1.36"
""")


def rewrite_uld_hi_for_objdiff():
    """Objects mode only: `lui $r, %hi(SYM + 0x7)` -> `%hi(SYM)` where that lui feeds an unaligned 64-bit load.

    For an 8-byte value read with ldl %lo(SYM + 0x7) / ldr %lo(SYM), splat writes the lui as %hi(SYM + 0x7) and
    modern gas pairs that HI16 with the ldl's LO16. The EE assembler the game was built with pairs it with the
    ldr's LO16 (+0), and objdiff reads a HI16's addend from the LO16 after it, so identical bytes compared as
    +7 vs +0 (sound-key family, 2026-10-18). Only rewritten when both spellings give the same immediate and the
    function has the matching ldr. Never used for the linked ELF (same bytes either way).
    """
    import re

    hi7 = re.compile(r"(lui\s+(\$\w+), )%hi\((D_([0-9A-F]{8})) \+ 0x7\)")
    rewritten = 0
    for f in Path("asm/nonmatchings").rglob("*.s"):
        text = f.read_text()
        if " + 0x7)" not in text:
            continue

        def sub(m):
            nonlocal rewritten
            addr = int(m.group(4), 16)
            same = ((addr + 7 + 0x8000) >> 16) == ((addr + 0x8000) >> 16)
            if same and re.search(r"ldr\s+\$\w+, %%lo\(%s\)\(%s\)" % (m.group(3), re.escape(m.group(2))), text):
                rewritten += 1
                return f"{m.group(1)}%hi({m.group(3)})"
            return m.group(0)

        new_text = hi7.sub(sub, text)
        if new_text != text:
            f.write_text(new_text)
    print(f"uld %hi rewrite for objdiff: {rewritten} lui")


def rewrite_lit4_loads_for_objdiff():
    """Objects mode only: turn `lwc1 $fN, (D_x)` loads of .lit4 pool entries back into `li.s $fN, value`.

    The compiler never names float literals: it emits `li.s` and the assembler puts the value in
    the object's own .lit4 (R_MIPS_LITERAL). splat instead references the retail pool entry by name
    (GPREL16 to an external D_ symbol), which no C can reproduce. Rewriting the target asm the same
    way the original toolchain built it makes the two comparable; the instruction bytes are
    unchanged (one gp-relative lwc1). Values with a zero low half are skipped, because gas would
    expand those to lui+mtc1. Never used for the linked ELF: its .lit4 layout comes from the split
    .lit4 data segment.
    """
    import re
    import struct

    lit4_files = list(Path("asm/data").glob("*.lit4.s"))
    values = {}
    for f in lit4_files:
        for addr, word in re.findall(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+\.float", f.read_text()):
            raw = bytes.fromhex(word)
            if int.from_bytes(raw, "little") & 0xFFFF:
                values[addr] = struct.unpack("<f", raw)[0]
    load = re.compile(r"lwc1(\s+)(\$f\d+), \((D_([0-9A-F]{8}))\) /\* gp_rel: \(D_[0-9A-F]{8}\) \*/")
    rewritten = 0
    for f in Path("asm/nonmatchings").rglob("*.s"):
        text = f.read_text()
        if "gp_rel" not in text:
            continue

        def sub(m):
            nonlocal rewritten
            if m.group(4) not in values:
                return m.group(0)
            rewritten += 1
            return f"li.s{m.group(1)}{m.group(2)}, {values[m.group(4)]!r} /* lit4: {m.group(3)} */"

        new = load.sub(sub, text)
        if new != text:
            f.write_text(new)
    print(f"lit4: rewrote {rewritten} literal loads to li.s for objdiff")

def fix_short_loop_branches():
    """Write the loop-back branch of each address in config/short_loop_branches.txt as a raw `.word`.

    Re-assembling splat's output of a very short loop (e.g. `c.lt.s; nop; nop; bc1tl`) makes SN `as` insert
    its R5900 short-loop nops a second time, so the function (and obj/target) comes out longer than retail.
    As a raw word the branch keeps its exact encoding and the assembler no longer sees a loop.
    """
    import re

    path = Path("config/short_loop_branches.txt")
    if not path.exists():
        return
    addrs = {int(m, 16) for m in re.findall(r"^\s*0x([0-9A-Fa-f]+)", path.read_text(), re.M)}
    line = re.compile(r"^(\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/)\s+(\S+)\s.*$", re.M)
    done = set()
    for f in Path("asm/nonmatchings").rglob("*.s"):
        text = f.read_text()
        if not any(f"{a:08X}" in text for a in addrs):
            continue

        def sub(m):
            vram = int(m.group(2), 16)
            if vram not in addrs:
                return m.group(0)
            done.add(vram)
            word = int.from_bytes(bytes.fromhex(m.group(3)), "little")
            return f"{m.group(1)}  .word 0x{word:08X} /* {m.group(4)}: raw word, see config/short_loop_branches.txt */"

        f.write_text(line.sub(sub, text))
    missing = addrs - done
    if missing:
        print("short-loop fix: not found: " + ", ".join(f"0x{a:08X}" for a in sorted(missing)))
    print(f"short-loop fix: {len(done)} loop branches written as raw words")


def build_stuff(linker_entries: List[LinkerEntry], skip_checksum=False, objects_only=False, dual_objects=False):
    """
    Build the objects and the final ELF file.
    If objects_only is True, only build objects and skip linking/checksum.
    If dual_objects is True, build objects twice: once normally, once with -DSKIP_ASM.
    """
    built_objects: Set[Path] = set()
    objdiff_units = []  # For objdiff.json

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = None,
        implicit_outputs: List[str] = None,
        out_dir: str = None,
        extra_flags: str = "",
        collect_objdiff: bool = False,
        orig_entry=None,
        implicit: List[str] = None,
    ):
        """
        Helper function to build objects.
        """
        # Handle none parameters
        if variables is None:
            variables = {}

        if implicit_outputs is None:
            implicit_outputs = []

        # Convert object_paths to list if it is not already
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        # Only rewrite output path to .o if out_dir is set (i.e. --objects mode)
        if out_dir:
            new_object_paths = []
            for obj in object_paths:
                obj = Path(obj)
                stem = obj.stem
                if obj.suffix in [".s", ".c" , ".cpp"]:
                    stem = obj.stem
                else:
                    if obj.suffix == ".o" and obj.with_suffix("").suffix in [".cpp",".s", ".c"]:
                        stem = obj.with_suffix("").stem
                target_dir = out_dir if out_dir else obj.parent
                new_obj = Path(target_dir) / (stem + ".o")
                new_object_paths.append(new_obj)
            object_paths = new_object_paths

        # Otherwise, use the original object_paths (with .s.o, .c.o, etc.)

        # Convert paths to strings
        object_strs = [str(obj) for obj in object_paths]

        # Add object paths to built_objects
        for idx, object_path in enumerate(object_paths):
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            # Add extra_flags to variables if present
            build_vars = variables.copy()
            if extra_flags:
                build_vars["cflags"] = extra_flags
            ninja.build(
                outputs=[str(object_path)],
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=build_vars,
                implicit=implicit or [],
                implicit_outputs=implicit_outputs,
            )
            # Collect for objdiff.json if requested
            if collect_objdiff and orig_entry is not None:
                src = src_paths[0] if src_paths else None
                if src:
                    src = Path(src)
                    # Always use the final "matched" name, i.e. as if it will be in src/ with no asm/ prefix
                    try:
                        # If the file is in asm/, replace asm/ with nothing (just drop asm/)
                        if src.parts[0] == "asm":
                            rel = Path(*src.parts[1:])
                        elif src.parts[0] == "src":
                            rel = Path(*src.parts[1:])
                        else:
                            rel = src
                        # Remove extension for the name
                        name = str(rel.with_suffix(""))
                    except Exception:
                        name = str(src.with_suffix(""))
                else:
                    name = object_path.stem
                if "target" in str(object_path):
                    target_path = str(object_path)
                    # Determine if a .c or .cpp file exists in src/ for this unit (recursively)
                    src_base = rel.with_suffix("")
                    src_c_files = list(Path("src").rglob(src_base.name + ".c"))
                    src_cpp_files = list(Path("src").rglob(src_base.name + ".cpp"))
                    has_src = bool(src_c_files or src_cpp_files)
                    # Determine the category based on the name
                    categories = [name.split("/")[0]]
                    unit = {
                        "name": name,
                        "target_path": target_path,
                        "metadata": {
                            "progress_categories": categories,
                        }
                    }
                    if has_src:
                        base_path = str(object_path).replace("target", "current")
                        unit["base_path"] = base_path
                    objdiff_units.append(unit)

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w", encoding="utf-8"), width=9999)

    cross = "mips-linux-gnu-"

    ld_args = "-EL -T config/undefined_syms.txt -T config/undefined_syms_auto.txt -T config/undefined_funcs_auto.txt -Map $mapfile -T $in -o $out"

    as_cpp = "cpp"
    as_filter = ""
    if sys.platform == "darwin":
        # Apple's /usr/bin/cpp mis-parses `-isystem DIR`; use clang directly.
        # Also normalise $t0-$t7 to numeric names (see tools/macos/o32_gpr_names.pl).
        as_cpp = "clang -E -x assembler-with-cpp"
        as_filter = "perl -p tools/macos/o32_gpr_names.pl | "

    ninja.rule(
        "as",
        description="as $in",
        command=f"{as_cpp} {COMMON_INCLUDES} $in -o  - | {as_filter}{cross}as -no-pad-sections -EL -march=5900 -mabi=eabi -Iinclude -o $out",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{COMPILE_C_RULE} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "cc_unit",
        description="cc $in ($ccdir)",
        command=f"{COMPILE_C_RULE.replace(CC_DIR, '$ccdir')} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "cc_native",
        description="cc $in ($ccdir)",
        command=f"python3 {ROOT}/tools/cc_native.py $ccdir -c {COMMON_INCLUDES} {ASM_INCLUDE_FLAG} {COMMON_CFLAGS} $in $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "cpp",
        description="cpp $in",
        command=f"{COMPILE_CXX_RULE} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    # Objects mode, obj/current only: the same compiles through tools/jtbl_cc.py, which points each switch jump
    # table that matches the retail one entry for entry at its jtbl_* symbol (see that file).
    jt = "python3 tools/jtbl_cc.py --unit $unit -- "
    ninja.rule(
        "cc_jt",
        description="cc $in (jtbl)",
        command=f"{jt}{COMPILE_C_RULE} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )
    ninja.rule(
        "cc_unit_jt",
        description="cc $in ($ccdir, jtbl)",
        command=f"{jt}{COMPILE_C_RULE.replace(CC_DIR, '$ccdir')} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )
    # (fork) units assembled with SN's Ps2EeAs (UNIT_PS2EEAS): the same compile, jump tables repointed, then Ps2EeAs
    ninja.rule(
        "cc_ps2as",
        description="cc $in (jtbl, Ps2EeAs)",
        command=f"python3 tools/ps2eeas_cc.py --unit $unit --as {PS2EEAS} -- {COMPILE_C_RULE} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )
    ninja.rule(
        "cpp_jt",
        description="cpp $in (jtbl)",
        command=f"{jt}{COMPILE_CXX_RULE} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{cross}ld {ld_args}",
    )

    ninja.rule(
        "asmoff",
        description="asmoff $out",
        command="python3 tools/asm_offsets.py $src $in $out",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{cross}objcopy $in $out -O binary",
    )

    def current_c_flags(entry):
        """-DSKIP_ASM plus the target offsets of the unit's INCLUDE_ASM functions (tools/asm_offsets.py), so
        every C function in obj/current sits at its obj/target offset: SN's assembler pads short loops
        depending on position, so a matched function only reproduces the target bytes there."""
        obj = Path(entry.object_path)
        stem = obj.with_suffix("").stem if obj.suffix == ".o" else obj.stem
        src = str(entry.src_paths[0])
        inc = f"obj/offsets/{stem}/asm_offsets.inc"
        ninja.build(outputs=[inc], rule="asmoff", inputs=[f"obj/target/{stem}.o"], implicit=[src, "tools/asm_offsets.py"],
                    variables={"src": src})
        return f"-DSKIP_ASM -DASM_OFFSETS -Wa,-Iobj/offsets/{stem}", [inc]

    # Add recipes for everything
    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            unit_flags = UNIT_CFLAGS.get(seg.name, "")
            # .cpp sources are listed as c segments and go through the cc rule; give them the C++ flags here
            if any(str(p).endswith(".cpp") for p in entry.src_paths):
                unit_flags = (COMMON_CXXFLAGS + " " + unit_flags).strip()
            if seg.name in UNIT_CC_NATIVE:
                task, tvars = ("cc_native", {"ccdir": UNIT_CC_NATIVE[seg.name]})
            elif seg.name in UNIT_CC:
                task, tvars = ("cc_unit", {"ccdir": UNIT_CC[seg.name]})
            else:
                task, tvars = ("cc", None)
            if dual_objects:
                build(entry.object_path, entry.src_paths, task, out_dir="obj/target", collect_objdiff=True, orig_entry=entry,
                      extra_flags=unit_flags or None, variables=tvars)
                flags, inc = current_c_flags(entry)
                # (fork) tools/jtbl_cc.py drives the SN driver; the ee-gcc 2.9 wrapper isn't wired to it, so these units' switch
                # functions keep their local jump tables (and stay below 100% in objdiff)
                jt = task != "cc_native"
                cur_task = task + "_jt" if jt else task
                tools_dep = ["tools/jtbl_cc.py"] if jt else []
                if seg.name in UNIT_PS2EEAS and task == "cc":
                    cur_task, tools_dep = "cc_ps2as", ["tools/jtbl_cc.py", "tools/ps2eeas_cc.py"]
                build(entry.object_path, entry.src_paths, cur_task, out_dir="obj/current",
                      extra_flags=(flags + " " + unit_flags).strip(), implicit=inc + tools_dep,
                      variables={**(tvars or {}), "unit": seg.name})
            else:
                build(entry.object_path, entry.src_paths, task, extra_flags=unit_flags or None, variables=tvars)
        elif isinstance(seg, splat.segtypes.common.cpp.CommonSegCpp):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "cpp", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                flags, inc = current_c_flags(entry)
                build(entry.object_path, entry.src_paths, "cpp", out_dir="obj/current", extra_flags=flags, implicit=inc)
            else:
                build(entry.object_path, entry.src_paths, "cpp")
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.rodatabin.CommonSegRodatabin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.textbin.CommonSegTextbin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.bin.CommonSegBin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as")
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    if objects_only:
        # Write objdiff.json if dual_objects (i.e. --objects)
        if dual_objects:
            objdiff = {
                "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
                "custom_make": "ninja",
                "custom_args": [],
                "build_target": False,
                "build_base": True,
                "watch_patterns": [
                    "src/**/*.c",
                    "src/**/*.cp",
                    "src/**/*.cpp",
                    "src/**/*.cxx",
                    "src/**/*.h",
                    "src/**/*.hp",
                    "src/**/*.hpp",
                    "src/**/*.hxx",
                    "src/**/*.s",
                    "src/**/*.S",
                    "src/**/*.asm",
                    "src/**/*.inc",
                    "src/**/*.py",
                    "src/**/*.yml",
                    "src/**/*.txt",
                    "src/**/*.json"
                ],
                "units": objdiff_units,
                "progress_categories": [ {"id": id, "name": name} for id, name in CATEGORY_MAP.items() ],
            }
            with open("objdiff.json", "w", encoding="utf-8") as f:
                json.dump(objdiff, f, indent=2)
        return

    ninja.build(
        PRE_ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ninja.build(
        ELF_PATH,
        "elf",
        PRE_ELF_PATH,
    )

    # FIXME: Do this in a more elegant way;
    # probably a python script which reads the splat yaml to get the SHA1,
    # rather than needing a seperate sha1 file.
    # My obession with DRY will never stop >:3
    if not skip_checksum:
        ninja.build(
            ELF_PATH + ".ok",
            "sha1sum",
            "config/checksum.sha1",
            implicit=[ELF_PATH],
        )
    else:
        print("Not adding sha1 rule")

def main():
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean artifacts and build",
        action="store_true",
    )
    parser.add_argument(
        "-C",
        "--only-clean",
        help="Only clean artifacts",
        action="store_true",
    )
    parser.add_argument(
        "-s",
        "--skip-checksum",
        help="Skip the checksum step",
        action="store_true",
    )
    parser.add_argument(
        "-o",
        "--objects",
        help="Build objects to obj/target and obj/current (with -DSKIP_ASM), skip linking and checksum",
        action="store_true",
    )
    args = parser.parse_args()

    do_clean = (args.clean or args.only_clean) or False

    # The normal build is byte-identical to retail since 2026-10-17 (fork), so the checksum runs unless -s.
    do_skip_checksum = args.skip_checksum
    do_objects = args.objects or False

    if do_clean:
        clean()
        if args.only_clean:
            return

    split.main([YAML_FILE], modes="all", verbose=False)
    fix_short_loop_branches()

    linker_entries = split.linker_writer.entries

    if do_objects:
        rewrite_lit4_loads_for_objdiff()
        rewrite_uld_hi_for_objdiff()
        build_stuff(linker_entries, skip_checksum=True, objects_only=True, dual_objects=True)
    else:
        build_stuff(linker_entries, do_skip_checksum)

    write_permuter_settings()

if __name__ == "__main__":
    main()