#ifndef LAYOUT_H
#define LAYOUT_H

// Compile-time checks that a struct field sits at the offset the target binary uses.
// A wrong offset fails the build with "size of array `check_T_f' is negative".
//
//   CHECK_OFFSET(cRider, mMetrix, 0x790);
//
// The offsets are the PS2 (32-bit pointer) layout. A 64-bit port defines
// DECOMP_NO_LAYOUT_CHECKS, since pointer fields change size there.
#ifndef DECOMP_NO_LAYOUT_CHECKS
#define DECOMP_OFFSETOF(T, f) ((unsigned int)&((T*)0)->f)
#define CHECK_OFFSET(T, f, off) typedef char check_##T##_##f[(DECOMP_OFFSETOF(T, f) == (off)) ? 1 : -1]
#else
#define CHECK_OFFSET(T, f, off)
#endif

#endif /* LAYOUT_H */
