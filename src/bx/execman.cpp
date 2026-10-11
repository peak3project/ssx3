#include "common.h"

struct cExecutionMan {
    int field_0x0;
    int field_0x4;
    void* field_0x8;
};

extern void* D_0048DC30[16];
void operator_delete(int* ptr);

//100%
INCLUDE_ASM("bx/execman", cExecutionMan__cExecutionMan__FP13cExecutionMani);
#ifdef SKIP_ASM
void cExecutionMan__cExecutionMan(cExecutionMan* self, int flags)
{
    self->field_0x8 = D_0048DC30;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("bx/execman", cExecutionMan_prepause__Fv);
#ifdef SKIP_ASM
void cExecutionMan_prepause()
{
}
#endif

//100%
INCLUDE_ASM("bx/execman", cExecutionMan_postpause__Fv);
#ifdef SKIP_ASM
void cExecutionMan_postpause()
{
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320AD8);
#ifdef SKIP_ASM
// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00320AD8(cExecutionMan* self, int flags)
{
    self->field_0x8 = D_0048DC30;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_00423C90(void* self);

//100%
INCLUDE_ASM("bx/execman", func_00320B08__FPv);
#ifdef SKIP_ASM
void* func_00320B08(void* self)
{
    return func_00423C90(self);
}
#endif

extern "C" void* func_00320550(int, int);

//100%
INCLUDE_ASM("bx/execman", func_00320B28__FPv);
#ifdef SKIP_ASM
void* func_00320B28(void* self)
{
    return func_00320550(1, 0xffff);
}
#endif

extern "C" void* func_00320550(int, int);

//100%
INCLUDE_ASM("bx/execman", func_00320B48__FPv);
#ifdef SKIP_ASM
void* func_00320B48(void* self)
{
    return func_00320550(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320B68);
#ifdef SKIP_ASM
// Branchless ceil(log2(x)): count leading zeros by halving the search
// window (16/8/4/2 bits), then subtract one more if x isn't a power of two.
extern "C" int func_00320B68(int x)
{
    int n, m, y;
    n = ((x - 0x10000) >> 31) & 16;
    y = x << n;
    m = ((y - 0x1000000) >> 31) & 8;
    y <<= m;
    n += m;
    m = ((y - 0x10000000) >> 31) & 4;
    y <<= m;
    n += m;
    m = ((y - 0x40000000) >> 31) & 2;
    y <<= m;
    n += m;
    n += 1 + (y >> 31);
    n += -(x & (x - 1)) >> 31;
    return n ^ 31;
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320BF0);
#ifdef SKIP_ASM
extern "C" void* func_00320FA8(int, int, int);

extern "C" void* func_00320BF0(void* self, int a1)
{
    return func_00320FA8(*(int*)((char*)self + 0x4), *(int*)self, a1);
}
#endif

extern "C" void* func_00321108(int, int, int);

//100%
INCLUDE_ASM("bx/execman", func_00320C48__FPvi);
#ifdef SKIP_ASM
void* func_00320C48(void* self, int a1)
{
    return func_00321108(*(int*)((char*)self + 0x4), *(int*)self, a1);
}
#endif

