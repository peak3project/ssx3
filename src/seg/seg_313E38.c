#include "common.h"

//100%
INCLUDE_ASM("seg/seg_313E38", func_00412E38);
#ifdef SKIP_ASM
extern char D_004998B8[];
extern void operator_delete__FPi(void *);
void func_00412E38(int *p, int f) {
    *p = (int)D_004998B8;
    if (f & 1) {
        operator_delete__FPi(p);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E38", func_00412E68);
#ifdef SKIP_ASM
extern char D_004998A0[];
void *func_00412E68(void **p) {
    *p = D_004998A0;
    return p;
}
#endif
