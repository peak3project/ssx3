#include "common.h"

struct cObjectInterface {
    char pad_0x00[0x84];
    struct cObjectInterface_Impl* mImpl; // offset 0x84
};

struct cObjectInterface_Impl {
    char pad_0x00[0x88];
    void* mInstanceMan; // offset 0x88
};

extern cObjectInterface* D_004A28A8;

//100%
INCLUDE_ASM("util/objectinterface", cObjectInterface_getInstanceMan__Fv);
#ifdef SKIP_ASM
void* cObjectInterface_getInstanceMan()
{
    return D_004A28A8->mImpl->mInstanceMan;
}
#endif

extern "C" void* func_002D9C00(void* self);

//100%
INCLUDE_ASM("util/objectinterface", func_002D1CF0__FPv);
#ifdef SKIP_ASM
void* func_002D1CF0(void* self)
{
    return func_002D9C00(self);
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D1D10);
#ifdef SKIP_ASM
extern char* D_004A289C;

// A render-state record of the graphics manager's state stack (D_00501420 holds the default).
struct sRS_2D1D10 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    short tex;
    short f12;
};
extern sRS_2D1D10 D_00501420;

struct sVec2_2D1D10 {
    float x, y;
    sVec2_2D1D10(const float& ax, const float& ay) : x(ax), y(ay) {}
};

struct sVec4_2D1D10 {
    float x, y, z, w;
};

struct sVE91_2D1D10 { short delta; short index; int (*fn)(void*, void*); };
struct sVE78_2D1D10 { short delta; short index; int (*fn)(void*, void*, const sVec2_2D1D10&, const sVec2_2D1D10&, const sVec2_2D1D10&, sVec4_2D1D10*); };
struct sVE79_2D1D10 { short delta; short index; int (*fn)(void*, void*, const sVec2_2D1D10&, const sVec2_2D1D10&, const sVec2_2D1D10&, sVec4_2D1D10*, float, int); };

struct sCtx_2D1D10 {
    char pad0[0xE84];
    sRS_2D1D10* top;        // 0xE84
    char pad_0xE88[0xF50 - 0xE88];
    int tex[64];            // 0xF50
    char pad_0x1050[0x10D8 - 0x1050];
    void* vt;               // 0x10D8
};

extern sCtx_2D1D10* D_004A5B80_2D1D10 __asm__("D_004A5B80");

static inline void push_2D1D10(sCtx_2D1D10* ctx)
{
    ctx->top[1] = ctx->top[0];
    ctx->top++;
}

static inline int texId_2D1D10(sCtx_2D1D10* ctx, int i)
{
    return ctx->tex[i];
}

static inline void pop_2D1D10(sCtx_2D1D10* ctx)
{
    ctx->top--;
}

static inline void set1_2D1D10(sCtx_2D1D10* ctx, unsigned int mask, int shift, unsigned int v)
{
    ctx->top->w1 = (ctx->top->w1 & ~mask) | ((v << shift) & mask);
}

static inline void set2_2D1D10(sCtx_2D1D10* ctx, unsigned int mask, int shift, unsigned int v)
{
    ctx->top->w2 = (ctx->top->w2 & ~mask) | ((v << shift) & mask);
}

extern "C" void func_002D1D10(void* obj, float* c, int mode, float size, float angle)
{
    char* g = D_004A289C;
    sVE91_2D1D10* vt = *(sVE91_2D1D10**)(g + 0x10D8);
    if (vt[91].fn(g + vt[91].delta, obj) != 0)
        return;
    sVec4_2D1D10 col;
    col.x = c[3];
    col.y = c[0];
    col.z = c[1];
    col.w = c[2];
    sCtx_2D1D10* ctx = D_004A5B80_2D1D10;
    push_2D1D10(ctx);
    *ctx->top = D_00501420;
    set1_2D1D10(ctx, 0x400000, 22, 1);
    set1_2D1D10(ctx, 0x3, 0, 0);
    set2_2D1D10(ctx, 0x1FFFFC00, 10, 0);
    set1_2D1D10(ctx, 0x7C, 2, 7);
    set2_2D1D10(ctx, 0x3E0, 5, 8);
    set1_2D1D10(ctx, 0x1800000, 23, 1);
    set1_2D1D10(ctx, 0x300000, 20, 0);
    set1_2D1D10(ctx, 0xFF000, 12, 0x14);
    ctx->top->tex = texId_2D1D10(ctx, mode + 0x25);
    if (angle != 0.0f) {
        sVE79_2D1D10* vt1 = (sVE79_2D1D10*)ctx->vt;
        vt1[79].fn((char*)ctx + vt1[79].delta, obj, sVec2_2D1D10(size, size), sVec2_2D1D10(0.0f, 0.0f),
                   sVec2_2D1D10(1.0f, 1.0f), &col, angle * 0.01745329424738884f, 1);
        if (mode == 1 || mode == 4) {
            sVE79_2D1D10* vt2 = (sVE79_2D1D10*)ctx->vt;
            vt2[79].fn((char*)ctx + vt2[79].delta, obj, sVec2_2D1D10(size, size), sVec2_2D1D10(0.0f, 0.0f),
                       sVec2_2D1D10(1.0f, 1.0f), &col, -angle * 0.01745329424738884f, 1);
        }
    } else {
        sVE78_2D1D10* vt3 = (sVE78_2D1D10*)ctx->vt;
        vt3[78].fn((char*)ctx + vt3[78].delta, obj, sVec2_2D1D10(size, size), sVec2_2D1D10(0.0f, 0.0f),
                   sVec2_2D1D10(1.0f, 1.0f), &col);
    }
    pop_2D1D10(ctx);
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D2058);
#ifdef SKIP_ASM
// VU0 microprogram entry (micro-memory address 0x828)
extern char D_828[];

struct sQ128 { float v[4]; } __attribute__((aligned(16)));

// PORT: PS2-only VU0 microprogram call (ctc2/vcallmsr/cfc2); the PC port needs a C version.
extern "C" int func_002D2058(sQ128* v)
{
    char* inst = (char*)*(void**)((char*)D_004A28A8->mImpl + 0x8C);
    int mask = *(int*)(inst + 0x110);
    for (int i = 0; i < *(int*)(inst + 0x10C); i++) {
        int bit = 1 << i;
        if (mask & bit) {
            sQ128* m = (sQ128*)(*(char**)(inst + 8 + i * 8) + 0x50);
            int r;
            __asm__ __volatile__(
                ".set push\n"
                ".set noreorder\n"
                "lqc2      $vf1, %1\n"
                "lqc2      $vf2, %2\n"
                "lqc2      $vf3, %3\n"
                "lqc2      $vf4, %4\n"
                "lqc2      $vf5, %5\n"
                "lqc2      $vf6, %6\n"
                "ctc2.ni   %7, $vi27\n"
                "vnop\n"
                "vnop\n"
                "vcallmsr  $vi27\n"
                "cfc2.i    %0, $vi1\n"
                ".set pop\n"
                : "=&r"(r)
                : "m"(m[0]), "m"(m[1]), "m"(m[2]), "m"(m[3]), "m"(m[4]), "m"(*v), "r"((int)D_828 >> 3)
                : "memory");
            int ok = r == 1;
            if (ok) return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D20F8);
#ifdef SKIP_ASM
extern void* D_004A3A00;

extern "C" int func_002D20F8(void) {
    return (*(int*)&D_004A3A00);
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D2100);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00486758[];
extern "C" void* func_002D21C0(void* p);

extern "C" void* func_002D2100(void)
{
    return func_002D21C0(cMemMan_alloc(1, D_00486758, 0, 0));
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D2138);
#ifdef SKIP_ASM
extern "C" void func_002D2138(void) {

}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2140);
#ifdef SKIP_ASM
extern "C" void func_002D2140(void) {

}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2148);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern long long D_004FF120;

extern "C" long long *func_002D2148(long long *arg0) {
    *arg0 = D_004FF120;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2160);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern long long D_004FF120;

extern "C" long long *func_002D2160(long long *arg0) {
    *arg0 = D_004FF120;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2178);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern long long D_004FF120;

extern "C" long long *func_002D2178(long long *arg0) {
    *arg0 = D_004FF120;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2190);
#ifdef SKIP_ASM
extern "C" float func_002D2190(void) {
    return 0.0f;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D21A0);
#ifdef SKIP_ASM
extern "C" float func_002D21A0(void) {
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D21B0__FPv);
#ifdef SKIP_ASM
void func_002D21B0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D21B8__FPv);
#ifdef SKIP_ASM
void func_002D21B8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D21C0);
#ifdef SKIP_ASM
extern void* D_004A3A00;

extern "C" void* func_002D21C0(void* p)
{
    D_004A3A00 = p;
    return p;
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D21D0);
#ifdef SKIP_ASM
// PORT: callers declare func_002D21D0 as void; it really returns the written size (4).
extern "C" int func_002D21D0_impl(signed char** self, float f) __asm__("func_002D21D0");
extern "C" int func_002D21D0_impl(signed char** self, float f)
{
    unsigned int v = *(unsigned int*)&f;
    signed char* p = *self;
    p[0] = v;
    p[1] = v >> 8;
    p[2] = v >> 16;
    p[3] = v >> 24;
    *self += 4;
    return 4;
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D2210);
#ifdef SKIP_ASM
extern "C" int func_002D2210(signed char** self, unsigned int v)
{
    signed char* p = *self;
    p[0] = v;
    p[1] = v >> 8;
    p[2] = v >> 16;
    p[3] = v >> 24;
    *self += 4;
    return 4;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2248);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D2248(void* self, float* v)
{
    int i;
    for (i = 0; i < 3; i++) {
        func_002D21D0(self, v[i]);
    }
    return 0xC;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D22A8);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D22A8(void* self, float* v)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_002D21D0(self, v[i]);
    }
    return 0x10;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2308);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D2308(void* self, float* v)
{
    int i;
    for (i = 0; i < 16; i++) {
        func_002D21D0(self, v[i]);
    }
    return 0x40;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2368);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D2368(void* self, float* q)
{
    func_002D21D0(self, q[3]);
    func_002D21D0(self, q[0]);
    func_002D21D0(self, q[1]);
    func_002D21D0(self, q[2]);
    return 0x10;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D23C8);
#ifdef SKIP_ASM
extern "C" int func_002D23C8(signed char **arg0, signed char arg1) {
    **arg0 = arg1;
    *arg0 += 1;
    return 1;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D23E8);
#ifdef SKIP_ASM
extern "C" int func_002D23C8(signed char **arg0, signed char arg1);
extern "C" unsigned int strlen(const char* s);

extern "C" int func_002D23E8(signed char** out, const char* s)
{
    unsigned int i;
    int n = 0;
    for (i = 0; i < strlen(s); i++) {
        n += func_002D23C8(out, s[i]);
    }
    func_002D23C8(out, 0);
    return n + 1;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2478);
#ifdef SKIP_ASM
extern "C" int func_002D2210(signed char** out, unsigned int len);

struct sStr_2478 {
    unsigned int len;
    signed char* data;
};

extern "C" int func_002D2478(signed char** out, sStr_2478** pp)
{
    unsigned int i;
    int n = func_002D2210(out, (*pp)->len);
    for (i = 0; i < (*pp)->len; i++) {
        n += func_002D23C8(out, (*pp)->data[i]);
    }
    return n;
}
#endif
