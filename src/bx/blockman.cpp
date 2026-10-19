#include "common.h"

INCLUDE_ASM("bx/blockman", cBlockMan_init);


//100%
INCLUDE_ASM("bx/blockman", func_00316BE0);
#ifdef SKIP_ASM
extern "C" int func_00316BE0(void *arg0, int arg1) {
    int temp_5;
    int var_3;

    temp_5 = arg1 - (*(int *)((char*)(arg0) + (0)));
    var_3 = 0;
    if (temp_5 > 0) {
        var_3 = temp_5 < (*(int *)((char*)(arg0) + (4)));
    }
    return var_3;
}
#endif
//100%
INCLUDE_ASM("bx/blockman", func_00316C00);
#ifdef SKIP_ASM
struct sPool_6C00 {
    int base;
    int size;
    unsigned int blockSize;
    int* freeList;
};

extern "C" int* func_00316C00(void* self, unsigned int size) {
    int i;
    sPool_6C00* pool;
    int* head;

    for (i = 0; i < *(int*)((char*)self + 0xC); i++) {
        pool = (sPool_6C00*)((i << 4) + *(int*)((char*)self + 8));
        if (pool->blockSize >= size) {
            head = pool->freeList;
            if (head != 0) {
                pool->freeList = (int*)*head;
                return head;
            }
        }
    }
    return 0;
}
#endif
//100%
INCLUDE_ASM("bx/blockman", func_00316C60);
#ifdef SKIP_ASM
struct sPool_6C60 {
    int base;
    int size;
    unsigned int blockSize;
    int* freeList;
};

extern "C" void func_00316C60(void* self, int* ptr) {
    int i;
    int off;
    sPool_6C60* pool;

    for (i = 0; i < *(int*)((char*)self + 0xC); i++) {
        pool = (sPool_6C60*)((i << 4) + *(int*)((char*)self + 8));
        off = (int)ptr - pool->base;
        if (off >= 0 && off < pool->size) {
            *ptr = (int)pool->freeList;
            ((sPool_6C60*)((i << 4) + *(int*)((char*)self + 8)))->freeList = ptr;
            return;
        }
    }
}
#endif
//100%
INCLUDE_ASM("bx/blockman", func_00316CC8);
#ifdef SKIP_ASM
extern "C" void func_00316CC8(void) {

}
#endif
