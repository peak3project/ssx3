#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0047C520[];
extern void* D_0047D0E8[16];

struct cStreamPause {
    void* vtable;
};

//99.67%
INCLUDE_ASM("main/streampause", cStreamPause_construct__Fv);
#ifdef SKIP_ASM
cStreamPause* cStreamPause_construct()
{
    cStreamPause* self = (cStreamPause*)cMemMan_alloc(4, D_0047C520, 0x20000000, 0);
    self->vtable = D_0047D0E8;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/streampause", func_00242D50);
#ifdef SKIP_ASM
extern "C" void* func_00242D50(void* self, ...)
{
    return self;
}
#endif
//100%
INCLUDE_ASM("main/streampause", func_00242D90);
#ifdef SKIP_ASM
extern "C" int func_00242D90(signed char *first1, signed char *last1, signed char *first2, signed char *last2) {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (*first1 < *first2) return 1;
        if (*first2 < *first1) return 0;
    }
    return first1 == last1 && first2 != last2;
}
#endif
//100%
INCLUDE_ASM("main/streampause", func_00242DF8);
#ifdef SKIP_ASM
extern "C" int func_00242DF8(signed char *first1, signed char *last1, signed char *first2, signed char *last2) {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (*first1 < *first2) return -1;
        if (*first2 < *first1) return 1;
    }
    if (first2 == last2) return first1 != last1;
    return -1;
}
#endif
//100%
INCLUDE_ASM("main/streampause", func_00242E58);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00242E58(void *self) {
    int **head = *(int ***)((char*)self + 4);
    int **node = (int **)*head;
    int **next;

    while (node != head) {
        next = (int **)*node;
        operator_delete((int*)node);
        node = next;
        head = *(int ***)((char*)self + 4);
    }
    **(int ***)((char*)self + 4) = *(int **)((char*)self + 4);
    *(int ***)((char*)*(int ***)((char*)self + 4) + 4) = *(int ***)((char*)self + 4);
}
#endif

INCLUDE_ASM("main/streampause", func_00242EB8);

//100%
INCLUDE_ASM("main/streampause", func_00243838);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0047D6E8[];
extern void* D_0046D970[];

extern "C" void func_00243838(void* self, int flags)
{
    void** m = D_0047D6E8;
    *(void***)((char*)self + 0x0) = D_0046D970;
    *(void***)((char*)self + 0x1F8) = m;
    *(void***)((char*)self + 0x1E8) = m;
    *(void***)((char*)self + 0x1C4) = m;
    *(void***)((char*)self + 0x1A8) = m;
    *(void***)((char*)self + 0x198) = m;
    *(void***)((char*)self + 0x184) = m;
    *(void***)((char*)self + 0x164) = m;
    *(void***)((char*)self + 0x154) = m;
    *(void***)((char*)self + 0x144) = m;
    *(void***)((char*)self + 0x134) = m;
    *(void***)((char*)self + 0x124) = m;
    *(void***)((char*)self + 0x10C) = m;
    *(void***)((char*)self + 0xFC) = m;
    *(void***)((char*)self + 0xEC) = m;
    *(void***)((char*)self + 0xDC) = m;
    *(void***)((char*)self + 0xBC) = m;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("main/streampause", func_002438B0);

//100%
INCLUDE_ASM("main/streampause", func_002438E0);
#ifdef SKIP_ASM
extern "C" void func_002438E0(void) {

}
#endif
//100%
INCLUDE_ASM("main/streampause", func_002438E8);
#ifdef SKIP_ASM
extern "C" void func_002438E8(void) {

}
#endif
