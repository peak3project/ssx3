#include "common.h"

//100%
INCLUDE_ASM("sound/ps2soundman", cSndPlayOpts_cSndPlayOpts);
#ifdef SKIP_ASM
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern "C" void* func_002ADE88(void* self, int heap);
extern "C" int func_003BA020(void* desc);
extern "C" void* func_00416210(void* dst, int v, int n);
extern char D_00483178[];
extern char D_00483188[];
extern char D_00483198[];
extern char D_004831A8[];
extern char D_004A3750[];
extern char D_004831B8[];
extern char D_004A3758[];
extern char D_004A3760[];
extern char D_004A3768[];
extern char D_004831C8[];
extern char D_004831D8[];
extern char D_004831E8[];
extern char D_004831F8[];
extern char D_00483208[];

struct sSmVEntry9350 {
    short delta;
    short index;
    void* fn;
};
struct sSmVtbl9350 {
    sSmVEntry9350 e[4];
} __attribute__((aligned(8)));
// PORT: the unit declares D_00483BE0 later with its own struct type; view bound by asm label
extern const sSmVtbl9350 D_00483BE0_9350 __asm__("D_00483BE0");

struct sSndDesc9350 {
    char c[0x18];
};

struct sSndEnv9350 {
    int f0;
    int f4;
    int f8;
    int fC;
};

struct sSndPlayOpts9350 {
    char* vbase;                // 0x00
    sSndDesc9350 cur;           // 0x04
    volatile int depth;         // 0x1C
    sSndDesc9350* descs;        // 0x20
    int f24[4];                 // 0x24
    int* f34;                   // 0x34
    int* f38;                   // 0x38
    int* f3C;                   // 0x3C
    char f40[4][8];             // 0x40
    int* f60;                   // 0x60
    int* f64;                   // 0x64
    int* f68;                   // 0x68
    int* f6C;                   // 0x6C
    sSndEnv9350* env;           // 0x70
    int* f74;                   // 0x74
    int* f78;                   // 0x78
    int* f7C;                   // 0x7C
    int* f80;                   // 0x80
    int* f84;                   // 0x84
};

// PORT: g++ 2.95 virtual-base construction with a stack vtable this-adjust fix-up, written out by hand.
extern "C" sSndPlayOpts9350* cSndPlayOpts_cSndPlayOpts(sSndPlayOpts9350* self, int inchrg, int heap)
{
    if (inchrg != 0) {
        self->vbase = (char*)self + 0x88;
        func_002ADE88((char*)self + 0x88, heap);
    }
    *(const sSmVtbl9350**)(self->vbase + 4) = &D_00483BE0_9350;
    if (inchrg == 0) {
        sSmVtbl9350 t1 = D_00483BE0_9350;
        *(sSmVtbl9350**)(self->vbase + 4) = &t1;
        char* base = self->vbase - 0x88;
        int d = (char*)self - base;
        t1.e[1].delta = D_00483BE0_9350.e[1].delta + d;
    }
    self->depth = -1;
    self->descs = (sSndDesc9350*)operator_new__FUi(0x60, D_00483178, 0, 0);
    self->f34 = (int*)operator_new__FUi(0x10, D_00483188, 0, 0);
    self->f38 = (int*)operator_new__FUi(0x10, D_00483198, 0, 0);
    self->f3C = (int*)operator_new__FUi(0x10, D_004831A8, 0, 0);
    self->f60 = (int*)operator_new__FUi(0x10, D_004A3750, 0, 0);
    self->f64 = (int*)operator_new__FUi(0x10, D_004831B8, 0, 0);
    self->f68 = (int*)operator_new__FUi(0x10, D_004A3758, 0, 0);
    self->f6C = (int*)operator_new__FUi(0x10, D_004A3760, 0, 0);
    self->env = (sSndEnv9350*)operator_new__FUi(0x40, D_004A3768, 0, 0);
    self->f74 = (int*)operator_new__FUi(0x10, D_004831C8, 0, 0);
    self->f78 = (int*)operator_new__FUi(0x10, D_004831D8, 0, 0);
    self->f7C = (int*)operator_new__FUi(0x10, D_004831E8, 0, 0);
    self->f80 = (int*)operator_new__FUi(0x10, D_004831F8, 0, 0);
    self->f84 = (int*)operator_new__FUi(0x10, D_00483208, 0, 0);
    self->depth++;
    self->descs[self->depth] = self->cur;
    self->f24[self->depth] = 0;
    self->f34[self->depth] = 0;
    self->f38[self->depth] = self->descs[self->depth].c[0];
    self->f3C[self->depth] = 0;
    func_00416210((char*)self + self->depth * 8 + 0x40, 0, 8);
    self->f60[self->depth] = 0;
    self->f64[self->depth] = 0;
    self->f68[self->depth] = 0;
    self->f6C[self->depth] = 0;
    self->env[self->depth].f4 = 0;
    self->env[self->depth].f0 = 100;
    self->env[self->depth].f8 = 90;
    self->env[self->depth].fC = 50;
    self->f74[self->depth] = 0;
    self->f80[self->depth] = 0;
    self->f84[self->depth] = 0;
    self->f78[self->depth] = 127;
    self->f7C[self->depth] = 1;
    func_003BA020(&self->descs[self->depth]);
    self->cur = self->descs[self->depth];
    self->depth--;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/ps2soundman", func_002A97C0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void operator_delete(int* ptr);
extern "C" void func_002ADEE8(void* self, int flags);

struct sSmVEntry97C0 {
    short delta;
    short index;
    void* fn;
};
struct sSmVtbl97C0 {
    sSmVEntry97C0 e[4];
} __attribute__((aligned(8)));
extern const sSmVtbl97C0 D_00483BE0;

// PORT: g++ 2.95 virtual-base destruction with a stack vtable this-adjust fix-up, written out by hand.
extern "C" void func_002A97C0(char* self, int flags)
{
    *(const sSmVtbl97C0**)(*(char**)self + 4) = &D_00483BE0;
    if (flags == 0) {
        sSmVtbl97C0 t1 = D_00483BE0;
        *(sSmVtbl97C0**)(*(char**)self + 4) = &t1;
        char* base = *(char**)self - 0x88;
        int d = self - base;
        t1.e[1].delta = D_00483BE0.e[1].delta + d;
    }
    if (*(void**)(self + 0x20) != 0) {
        cMemMan_free(*(void**)(self + 0x20));
    }
    if (*(void**)(self + 0x34) != 0) {
        cMemMan_free(*(void**)(self + 0x34));
    }
    if (*(void**)(self + 0x38) != 0) {
        cMemMan_free(*(void**)(self + 0x38));
    }
    if (*(void**)(self + 0x3C) != 0) {
        cMemMan_free(*(void**)(self + 0x3C));
    }
    if (*(void**)(self + 0x60) != 0) cMemMan_free(*(void**)(self + 0x60));
    if (*(void**)(self + 0x64) != 0) cMemMan_free(*(void**)(self + 0x64));
    if (*(void**)(self + 0x68) != 0) cMemMan_free(*(void**)(self + 0x68));
    if (*(void**)(self + 0x6C) != 0) cMemMan_free(*(void**)(self + 0x6C));
    if (*(void**)(self + 0x70) != 0) cMemMan_free(*(void**)(self + 0x70));
    if (*(void**)(self + 0x74) != 0) cMemMan_free(*(void**)(self + 0x74));
    if (*(void**)(self + 0x78) != 0) cMemMan_free(*(void**)(self + 0x78));
    if (*(void**)(self + 0x7C) != 0) cMemMan_free(*(void**)(self + 0x7C));
    if (*(void**)(self + 0x80) != 0) cMemMan_free(*(void**)(self + 0x80));
    if (*(void**)(self + 0x84) != 0) cMemMan_free(*(void**)(self + 0x84));
    if (flags & 2) {
        func_002ADEE8(*(void**)self, 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/ps2soundman", func_002A9988);
#ifdef SKIP_ASM
extern "C" void func_002A9988(void* self, float a, float b)
{
    (*(float**)((char*)self + 0x6C))[*(int*)((char*)self + 0x1C)] = a;
    if (b < 0.0f) {
        (*(float**)((char*)self + 0x68))[*(int*)((char*)self + 0x1C)] = a;
        return;
    }
    (*(float**)((char*)self + 0x68))[*(int*)((char*)self + 0x1C)] = b;
}
#endif

