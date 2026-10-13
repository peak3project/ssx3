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

    ld_args = "-EL -T config/undefined_syms_auto.txt -T config/undefined_funcs_auto.txt -Map $mapfile -T $in -o $out"

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
        "cpp",
        description="cpp $in",
        command=f"{COMPILE_CXX_RULE} $cflags -o $out && {cross}strip $out -N dummy-symbol-name",
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
        ninja.build(outputs=[inc], rule="asmoff", inputs=[f"obj/target/{stem}.o"], implicit=[src],
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
                unit_flags = (unit_flags + " " + COMMON_CXXFLAGS).strip()
            task, tvars = ("cc_unit", {"ccdir": UNIT_CC[seg.name]}) if seg.name in UNIT_CC else ("cc", None)
            if dual_objects:
                build(entry.object_path, entry.src_paths, task, out_dir="obj/target", collect_objdiff=True, orig_entry=entry,
                      extra_flags=unit_flags or None, variables=tvars)
                flags, inc = current_c_flags(entry)
                build(entry.object_path, entry.src_paths, task, out_dir="obj/current",
                      extra_flags=(flags + " " + unit_flags).strip(), implicit=inc, variables=tvars)
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

    # FIXME: Set skip_checksum to False once builds are able
    # to match; it has been temporairly enabled here.
    do_skip_checksum = args.skip_checksum or True
    do_objects = args.objects or False

    if do_clean:
        clean()
        if args.only_clean:
            return

    split.main([YAML_FILE], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    if do_objects:
        rewrite_lit4_loads_for_objdiff()
        build_stuff(linker_entries, skip_checksum=True, objects_only=True, dual_objects=True)
    else:
        build_stuff(linker_entries, do_skip_checksum)

    write_permuter_settings()

if __name__ == "__main__":
    main()