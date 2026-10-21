#include "common.h"

extern void* D_004936D8[16];
extern void* D_004A5B8C;

struct cPSPLightMan {
    void* vtable;
};

//100%
INCLUDE_ASM("render/ps2lightman", cPSPLightMan_cPSPLightMan__FP12cPSPLightMan);
#ifdef SKIP_ASM
cPSPLightMan* cPSPLightMan_cPSPLightMan(cPSPLightMan* self)
{
    self->vtable = D_004936D8;
    D_004A5B8C = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/ps2lightman", func_0038AE28);
#ifdef SKIP_ASM
extern void* D_004A5B8C;
extern void* D_004936D8[];
void operator_delete(int* ptr);

extern "C" void func_0038AE28(void* self, int flags)
{
    *(void***)self = D_004936D8;
    D_004A5B8C = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

