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

INCLUDE_ASM("bx/memman", cMemMan_alloc);

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

INCLUDE_ASM("bx/memman", func_00317EE0);

INCLUDE_ASM("bx/memman", func_00317F18);
