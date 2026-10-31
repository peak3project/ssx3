#include "common.h"

//100%
INCLUDE_ASM("fe/feflowstate", cFEFlowState_setNumStates);
#ifdef SKIP_ASM
extern "C" void func_001A06B0(void* self);
extern "C" void* func_00416210(void* dst, int c, int n);
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_00460B80[];

extern "C" void cFEFlowState_setNumStates(void* self, int a1)
{
    signed char n = a1;
    func_001A06B0(self);
    *(signed char*)self = n;
    void* p = operator_new__FUi(n, D_00460B80, 0x100, 0);
    *(void**)((char*)self + 0x4) = p;
    func_00416210(p, 0, n);
}
#endif

//100%
INCLUDE_ASM("fe/feflowstate", func_001A06B0);
#ifdef SKIP_ASM
void cMemMan_free(void* ptr);

extern "C" void func_001A06B0(void* self)
{
    void* p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        cMemMan_free(p);
        *(void**)((char*)self + 0x4) = 0;
    }
    *(char*)self = 0;
}
#endif

//100%
INCLUDE_ASM("fe/feflowstate", func_001A06F0);
#ifdef SKIP_ASM
extern "C" signed char func_001A06F0(void* self, int a1)
{
    return *(signed char*)(*(int*)((char*)self + 0x4) + (signed char)a1);
}
#endif

//100%
INCLUDE_ASM("fe/feflowstate", func_001A0708);
#ifdef SKIP_ASM
extern "C" void func_001A0708(void* self, int a1, int a2)
{
    *(char*)(*(int*)((char*)self + 0x4) + (signed char)a1) = a2;
}
#endif

