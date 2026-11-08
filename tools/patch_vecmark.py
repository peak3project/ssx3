#!/usr/bin/env python3
"""Make SN ee-gcc 2.95.3 V1.36 emit its `vec_mark` insn, as the compiler that built SSX 3 evidently did.

V1.36's cc1plus contains an SN-added insn `vec_mark` (insn code 638, `(unspec_volatile [(const_int 0)] 144)`,
empty output template) and a peephole (code 639) that deletes `vec_mark; reg += -1; branch` when the branch's
delay slot is still empty, printing "# empty vec_new loop removed by peephole". Nothing in V1.36 ever emits
`vec_mark`, so the peephole never fires. The retail SSX 3 code shows it did fire: every empty g++ array-ctor
(build_vec_init) loop either vanished, leaving its dead `li N; li -1` setup behind, or kept its loop-top
decrement with the delay slot filled from the fall-through. Retail has no empty loop in the shape stock V1.36
produces.

This patch makes build_vec_init call `emit_insn (gen_vec_mark ())` at the top of each loop body: its call to
expand_start_target_temps (0x43fe20) is redirected to a 26-byte stub in the unused tail of .text that makes
the original call and then emits the marker, except in a loop whose element type is itself an array (the row loop
of a 2-D member array): retail lets reorg fill that loop's branch delay slot with the loop-top decrement, which
the volatile marker would block (func_00372B78; no code change in any other C++ unit, 2026-11-08). Verified:
all 6,991 then-matched functions compile to the same bytes; empty array-ctor loops now reproduce both retail shapes.

usage: tools/patch_vecmark.py SRC_COMPILER_DIR DST_COMPILER_DIR   (copies SRC to DST, patches DST's cc1plus)
"""
import hashlib
import shutil
import struct
import sys
from pathlib import Path

STOCK_SHA1 = "2e7192cd633a2a04f2a78fe84e4ac0fdbd6867ad"
PATCHED_SHA1 = "7410088eab8c39f86ce38fff509be769cd94db77"
CC1PLUS = "lib/gcc-lib/ee/2.95.3/cc1plus.exe"

TEXT_VA, TEXT_OFF = 0x401000, 0x1000
HOOK = 0x43FE20           # build_vec_init: call expand_start_target_temps
START_TARGET_TEMPS = 0x589040
GEN_VEC_MARK = 0x517790
EMIT_INSN = 0x4AE740
CAVE = 0x5AEEE0           # end of .text's raw data (0x120 bytes of zero padding)


def off(va: int) -> int:
    return TEXT_OFF + va - TEXT_VA


def patch(data: bytearray) -> None:
    rel = struct.unpack("<i", data[off(HOOK) + 1:off(HOOK) + 5])[0]
    assert data[off(HOOK)] == 0xE8 and HOOK + 5 + rel == START_TARGET_TEMPS, "unexpected bytes at hook"
    assert data[off(CAVE):off(CAVE) + 32] == bytes(32), "cave not empty"
    code = bytearray()

    def call(target: int) -> None:
        here = CAVE + len(code)
        code.extend(b"\xe8" + struct.pack("<i", target - (here + 5)))

    call(START_TARGET_TEMPS)
    # no marker in a loop whose element is itself an array (the recursive build_vec_init path; %esi = element
    # type, TREE_CODE at +8, ARRAY_TYPE = 0x12): retail keeps those loops' delay slots stealable
    code += b"\x80\x7e\x08\x12"  # cmpb $0x12, 0x8(%esi)
    code += b"\x74\x0e"        # je ret
    call(GEN_VEC_MARK)
    code += b"\x50"            # push eax
    call(EMIT_INSN)
    code += b"\x83\xc4\x04"    # add esp, 4
    code += b"\xc3"            # ret
    data[off(CAVE):off(CAVE) + len(code)] = code
    data[off(HOOK) + 1:off(HOOK) + 5] = struct.pack("<i", CAVE - (HOOK + 5))
    # grow .text's VirtualSize to cover the stub (the raw data already contains it)
    pe = struct.unpack("<I", data[0x3C:0x40])[0]
    opt = struct.unpack("<H", data[pe + 20:pe + 22])[0]
    sh = pe + 24 + opt
    assert data[sh:sh + 5] == b".text"
    struct.pack_into("<I", data, sh + 8, 0x1AE000)


def main() -> None:
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    src, dst = Path(sys.argv[1]), Path(sys.argv[2])
    data = bytearray((src / CC1PLUS).read_bytes())
    if hashlib.sha1(data).hexdigest() != STOCK_SHA1:
        sys.exit(f"{src / CC1PLUS}: not the stock SN V1.36 cc1plus (sha1 mismatch)")
    patch(data)
    if hashlib.sha1(data).hexdigest() != PATCHED_SHA1:
        sys.exit("patched cc1plus has an unexpected sha1")
    tmp = dst.with_name(dst.name + ".tmp")
    shutil.rmtree(tmp, ignore_errors=True)
    shutil.copytree(src, tmp)
    (tmp / CC1PLUS).write_bytes(data)
    shutil.rmtree(dst, ignore_errors=True)
    tmp.rename(dst)
    print(f"{dst}: vec_mark-patched compiler (cc1plus sha1 {PATCHED_SHA1})")


if __name__ == "__main__":
    main()
