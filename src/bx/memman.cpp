#include "common.h"

extern unsigned int D_004A3E84;
extern const char D_004A3E88[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

//100%
INCLUDE_ASM("bx/memman", operator_new1__Fi);
#ifdef SKIP_ASM
void* operator_new1(int size)
{
    return cMemMan_alloc(size, D_004A3E88, D_004A3E84, 0);
}
#endif

//100%
INCLUDE_ASM("bx/memman", operator_new2__Fi);
#ifdef SKIP_ASM
void* operator_new2(int size)
{
    return cMemMan_alloc(size, D_004A3E88, D_004A3E84, 0);
}
#endif

//100%
INCLUDE_ASM("bx/memman", cMemMan_alloc);
#ifdef SKIP_ASM
extern void* D_00538B00[16];
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern "C" void* func_00319A90(unsigned int size, unsigned int align, int flags, int top);

// Allocates from the block heap under the global lock. Alignment: flag 0x400 -> 128, else 8 (small) or 16;
// a nonzero log2 field in flags bits 24-27 overrides it with 4 << n. The selection is written branch-free
// with sign masks (-1/0), as the original allocator does.
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d)
{
    int n = (flags >> 24) & 0xF;
    int mask = (int)((flags & 0x400) << 21) >> 31;
    unsigned int align = mask & 0x80;
    align |= (mask + 1) << (((size - 16) >> 31) + 4);
    mask = (n - 1) >> 31;
    unsigned int log = 4 << n;
    if (!mask)
        align = log;
    MUTEX_lock(D_00538B00);
    void* r = func_00319A90(size, align, flags, d);
    MUTEX_unlock(D_00538B00);
    return r;
}
#endif

//100%
INCLUDE_ASM("bx/memman", operator_new__FUi);
#ifdef SKIP_ASM
// PORT: the target calls the 4-arg cMemMan_alloc with only $a0 set (a1..a3 left as-is).
void* cMemMan_alloc1(unsigned int size) __asm__("cMemMan_alloc");

void* operator_new(unsigned int size)
{
    return cMemMan_alloc1(size);
}
#endif

extern void* D_00538B00[16];
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern "C" void func_00319B48(void* ptr);

//100%
INCLUDE_ASM("bx/memman", operator_delete__FPi);
#ifdef SKIP_ASM
void operator_delete(int* ptr)
{
    MUTEX_lock(D_00538B00);
    func_00319B48(ptr);
    MUTEX_unlock(D_00538B00);
}
#endif

//100%
INCLUDE_ASM("bx/memman", cMemMan_free__FPv);
#ifdef SKIP_ASM
void cMemMan_free(void* ptr)
{
    MUTEX_lock(D_00538B00);
    func_00319B48(ptr);
    MUTEX_unlock(D_00538B00);
}
#endif

//100%
INCLUDE_ASM("bx/memman", func_00317EE0);
#ifdef SKIP_ASM
extern "C" void func_00317EE0(void) {
    MUTEX_lock(D_00538B00);
    MUTEX_unlock(D_00538B00);
}
#endif
//100%
INCLUDE_ASM("bx/memman", func_00317F18);
#ifdef SKIP_ASM
extern "C" void func_00319CC8();

extern "C" void func_00317F18(void) {
    func_00319CC8();
}
#endif
