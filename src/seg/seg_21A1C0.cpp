#include "common.h"

INCLUDE_ASM("seg/seg_21A1C0", func_003191C0);

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_003194A8);
#ifdef SKIP_ASM
extern "C" void func_003191C0(void* str, const char* fmt, char* ap);

// sprintf into a cBXString.
// PORT: SN-specific va_start (gcc 2.95 EE EABI form); use <stdarg.h> off-PS2.
extern "C" void func_003194A8(void* str, const char* fmt, ...)
{
    char* ap;
    ap = (char*)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_003191C0(str, fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_003194F0);
#ifdef SKIP_ASM
struct cBXString_94F0 {
    char* str;
};
extern "C" void func_00318120(void* self);
extern unsigned char D_00499C81[];

// Strips trailing white space (D_00499C81 is the ctype table + 1, bit 8 = space).
extern "C" void func_003194F0(cBXString_94F0* self)
{
    func_00318120(self);
    char* end = 0;
    char* p;
    for (p = self->str; *p != 0; p++) {
        if (end == 0)
            end = p;
        if (!(D_00499C81[(int)*p] & 8))
            end = 0;
    }
    if (end != 0) {
        *end = 0;
        *(int*)(self->str - 8) = end - self->str;
    }
}
#endif

INCLUDE_ASM("seg/seg_21A1C0", func_00319578);

INCLUDE_ASM("seg/seg_21A1C0", func_00319610);

INCLUDE_ASM("seg/seg_21A1C0", func_00319660);

INCLUDE_ASM("seg/seg_21A1C0", func_00319690);

INCLUDE_ASM("seg/seg_21A1C0", func_00319718);

INCLUDE_ASM("seg/seg_21A1C0", func_00319790);

INCLUDE_ASM("seg/seg_21A1C0", func_003197D0);

INCLUDE_ASM("seg/seg_21A1C0", func_00319800);

INCLUDE_ASM("seg/seg_21A1C0", func_00319820);

INCLUDE_ASM("seg/seg_21A1C0", func_003198A0);

INCLUDE_ASM("seg/seg_21A1C0", func_00319910);

INCLUDE_ASM("seg/seg_21A1C0", func_00319930);

INCLUDE_ASM("seg/seg_21A1C0", func_003199D0);
