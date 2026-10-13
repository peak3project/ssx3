#include "common.h"

//100%
INCLUDE_ASM("render/particle", cBaseClass_DynamicEmitter_Allocate);
#ifdef SKIP_ASM
// PORT: operator_new__FUi is the game's tagged allocator (size, tag, flags, d); bound by asm label
// as operator new[] so the array new-expressions below match.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00492650[];
extern char D_00492670[];

struct sEmitParticle_0C60 {
    float v[4];
    sEmitParticle_0C60() {}
};

struct sEmitState_0C60 {
    float v[4];
    sEmitState_0C60() {}
};

extern "C" void cBaseClass_DynamicEmitter_Allocate(void* self)
{
    char* s = (char*)self;
    sEmitParticle_0C60** pp = (sEmitParticle_0C60**)(s + 0x1A0);
    *pp = new (D_00492650, 0, 0) sEmitParticle_0C60[*(int*)(s + 0x178)];
    sEmitState_0C60** ps = (sEmitState_0C60**)(s + 0x1A4);
    *ps = new (D_00492670, 0, 0) sEmitState_0C60[*(int*)(s + 0x178)];
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00370CF8);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

extern "C" void func_00370CF8(void* self, int reset)
{
    if (*(void**)((char*)self + 0x1A0) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x1A0));
        *(void**)((char*)self + 0x1A0) = 0;
    }
    if (*(void**)((char*)self + 0x1A4) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x1A4));
        *(void**)((char*)self + 0x1A4) = 0;
    }
    if (reset) {
        *(int*)((char*)self + 0x170) = 0;
        *(int*)((char*)self + 0x178) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", cBaseClass_DynamicEmitter_reset);
#ifdef SKIP_ASM
struct sVec4A {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sVec4A D_004FF120;

extern "C" void cBaseClass_DynamicEmitter_reset(void* self)
{
    int i;
    *(int*)((char*)self + 0x17C) = 0;
    for (i = 0; i < *(int*)((char*)self + 0x178); i++) {
        (*(sVec4A**)((char*)self + 0x1A0))[i] = D_004FF120;
        (*(sVec4A**)((char*)self + 0x1A4))[i] = D_004FF120;
        *(int*)((char*)self + 0x17C) = 0;
        *(int*)((char*)self + 0x1E0) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00370DC8);
#ifdef SKIP_ASM
int BXrand();

extern "C" void func_0036CBF8(void* sys, int count, int a2, sVec4A* v, float a, float b, float c);
extern "C" void func_00370058(void* sys, void* a1, void* def, void* a3, float f);
extern char D_004FF1A0[];

struct sGsState_00370DC8 {
    int w0;
    unsigned int a : 2;
    unsigned int pad2 : 18;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int pad23 : 9;
    unsigned int pad0_ : 10;
    unsigned int d : 19;
    unsigned int pad29 : 3;
    int w3;
    int w4;
};

extern sGsState_00370DC8 D_00501420;


class cEmitter_00370DC8 {
public:
    float start;            // 0x0
    int f4;                 // 0x4
    int f8;                 // 0x8
    int fC;                 // 0xC
    float f10;              // 0x10
    float f14;              // 0x14
    char pad18[0x8];
    char sys[0x150];        // 0x20
    int active;             // 0x170
    int f174;               // 0x174
    int count;              // 0x178
    int f17C;               // 0x17C
    char f180[0x30];        // 0x180
    char v1B0[0x10];        // 0x1B0
    char v1C0[0x10];        // 0x1C0
    char v1D0[0x10];        // 0x1D0
    int f1E0;               // 0x1E0
    sGsState_00370DC8 gs;   // 0x1E4
    virtual void v01(int a);
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();

    void setA(int v) { gs.a = v; }
    void setB(int v) { gs.b = v; }
    void setC(int v) { gs.c = v; }
    void setD(int v) { gs.d = v; }
};

static inline float randf_00370DC8()
{
    union { int i; float f; } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float fceil_00370DC8(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (t < x) {
        t += 1.0f;
    }
    return t;
}

static inline float life_00370DC8(char* def)
{
    float t = *(float*)(def + 0x8);
    if (t >= 0.0f) {
        return t;
    }
    return *(float*)(def + 0x14) + *(float*)(def + 0x1C) * 0.5f;
}

static inline float start_00370DC8(char* def)
{
    float t = *(float*)(def + 0x8);
    if (t < 0.0f) {
        return t;
    }
    return t + *(float*)(def + 0x14) + *(float*)(def + 0x1C) * 0.5f;
}

extern "C" void func_00370DC8(cEmitter_00370DC8* self, char* def, float f)
{
    int n = *(int*)(def + 0xD0);
    self->fC = n;
    self->f14 = *(float*)(def + 0xD4);
    if (n >= 2) {
        float fn = (float)n;
        self->f10 = fn * randf_00370DC8();
    } else {
        self->f10 = 0.0f;
    }
    self->f4 = *(int*)(def + 0xC4);
    self->f8 = *(int*)(def + 0xC8);
    self->start = start_00370DC8(def);
    int changed = 0;
    float frames = life_00370DC8(def) * 60.0f;
    if (self->count != (int)fceil_00370DC8(frames)) {
        self->count = (int)fceil_00370DC8(frames);
        changed = 1;
    }
    *(sVec4A*)self->v1B0 = D_004FF120;
    *(sVec4A*)self->v1C0 = D_004FF120;
    *(sVec4A*)self->v1D0 = D_004FF120;
    float l = life_00370DC8(def);
    sVec4A v;
    v.x = *(float*)(def + 0x78);
    v.y = *(float*)(def + 0x7C);
    v.z = *(float*)(def + 0x80);
    v.w = 0.0f;
    func_0036CBF8(self->sys, *(int*)(def + 0x0) * self->count, *(int*)(def + 0x4), &v, l,
                  *(float*)(def + 0x20), *(float*)(def + 0xC));
    func_00370058(self->sys, D_004FF1A0, def, self->f180, f);
    if (changed) {
        self->v01(0);
        self->v05();
        self->v02();
    }
    self->active = 1;
    self->gs = D_00501420;
    self->setC(1);
    self->setB(0);
    self->setA(2);
    self->setD(0);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003710D0);
#ifdef SKIP_ASM
struct sPtQ10D0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

static inline float randUnit10D0()
{
    union { int i; float f; } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

// PORT: the unit's callers use a 4-arg declaration; bind the real 5-arg body by asm label.
extern "C" void func_003710D0_impl(char* self, sPtQ10D0* pos, sPtQ10D0* vel, int rnd, float dt) __asm__("func_003710D0");
extern "C" void func_003710D0_impl(char* self, sPtQ10D0* pos, sPtQ10D0* vel, int rnd, float dt)
{
    if (*(int*)(self + 0x174) == 0) {
        return;
    }
    int alive = (*(sPtQ10D0**)(self + 0x1A4))[*(int*)(self + 0x17C)].w > 0.0f;
    if (alive) {
        if (rnd == 0) {
            *(int*)(self + 0x1E0) = *(int*)(self + 0x1E0) - 1;
        }
    } else if (rnd) {
        *(int*)(self + 0x1E0) = *(int*)(self + 0x1E0) + 1;
    }
    if (pos) {
        *(sPtQ10D0*)(self + 0x1B0) = *pos;
    } else {
        pos = (sPtQ10D0*)(self + 0x1B0);
    }
    if (vel) {
        *(sPtQ10D0*)(self + 0x1C0) = *vel;
    } else {
        vel = (sPtQ10D0*)(self + 0x1C0);
    }
    (*(sPtQ10D0**)(self + 0x1A0))[*(int*)(self + 0x17C)] = *pos;
    (*(sPtQ10D0**)(self + 0x1A0))[*(int*)(self + 0x17C)].w = 0.0f;
    (*(sPtQ10D0**)(self + 0x1A4))[*(int*)(self + 0x17C)] = *vel;
    // PORT: pointer held in int (index-first addu)
    sPtQ10D0* v = (sPtQ10D0*)((*(int*)(self + 0x17C) << 4) + *(int*)(self + 0x1A4));
    if (rnd) {
        v->w = randUnit10D0() + 1.0f;
    } else {
        v->w = 0.0f;
    }
    int idx = *(int*)(self + 0x17C) - 1;
    *(int*)(self + 0x17C) = idx;
    if (idx < 0) {
        *(int*)(self + 0x17C) = *(int*)(self + 0x178) - 1;
    }
    float f = *(float*)(self + 0x10) + *(float*)(self + 0x14) * dt;
    *(float*)(self + 0x10) = f;
    if ((int)f >= *(int*)(self + 0xC)) {
        *(float*)(self + 0x10) = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003712B8);
#ifdef SKIP_ASM
class cStream003712B8 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
};

extern "C" void func_003712B8(void* self, cStream003712B8* stream)
{
    struct {
        float a;
        float b;
        int c;
        int d;
        int e;
    } buf;
    buf.a = *(float*)((char*)self + 0x0);
    buf.b = *(float*)((char*)self + 0x28);
    buf.d = *(int*)((char*)self + 0x170);
    buf.c = *(int*)((char*)self + 0x174);
    buf.e = *(int*)((char*)self + 0x17C);
    stream->v01(&buf, 0x14);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371318);
#ifdef SKIP_ASM
class cStream00371318 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

extern "C" void func_00371318(void* self, cStream00371318* stream)
{
    struct {
        float a;
        float b;
        int c;
        int d;
        int e;
    } buf;
    stream->v02(&buf, 0x14);
    *(float*)((char*)self + 0x0) = buf.a;
    *(float*)((char*)self + 0x28) = buf.b;
    *(int*)((char*)self + 0x170) = buf.d;
    *(int*)((char*)self + 0x174) = buf.c;
    *(int*)((char*)self + 0x17C) = buf.e;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371380);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPtRS1380 {
    int field_0x0;          // 0x1E4
    int flagsA;             // 0x1E8, bits 2..6 = layer
    int flagsB;             // 0x1EC, bits 5..9 = blend
    int field_0xC;          // 0x1F0
    short tex;              // 0x1F4
    short pad;
};

struct sPtVEntry1380 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sPtCtx1380 {
    char pad_0x0[0xE84];
    sPtRS1380* top;             // 0xE84
    char pad_0xE88[0xF50 - 0xE88];
    int texIds[(0x10D8 - 0xF50) / 4];   // 0xF50
    sPtVEntry1380* vtable;      // 0x10D8
};

extern char* D_004A5B80;
extern sPtCtx1380* D_004A5B80_ctx __asm__("D_004A5B80");
extern int D_0044B420[];

struct sPtObj1380 {
    char pad_0x0[0x4];
    int base;               // 0x4
    int kind;               // 0x8
    char pad_0xC[0x4];
    float frame;            // 0x10
    char pad_0x14[0x160];
    int field_0x174;        // 0x174
    char pad_0x178[0x68];
    int field_0x1E0;        // 0x1E0
    sPtRS1380 rs;           // 0x1E4
};

extern "C" void func_00371380(sPtObj1380* self, int blend)
{
    if (self->field_0x174 == 0) {
        return;
    }
    sPtCtx1380* ctx = D_004A5B80_ctx;
    if (self->field_0x1E0 == 0) {
        return;
    }
    int tex = ctx->texIds[self->base + (int)self->frame];
    if (tex < 0) {
        return;
    }
    self->rs.flagsA = (self->rs.flagsA & ~0x7C) | ((D_0044B420[self->kind] << 2) & 0x7C);
    self->rs.flagsB = (self->rs.flagsB & ~0x3E0) | ((blend << 5) & 0x3E0);
    self->rs.tex = tex;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *ctx->top = self->rs;
    sPtVEntry1380* vt = ctx->vtable;
    vt[83].fn((char*)ctx + vt[83].delta, self);
    ctx->top--;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003714B8);
#ifdef SKIP_ASM
extern "C" void* func_00370B60(void* self);
extern void* D_004930D0[];

extern "C" void* func_003714B8(void* self)
{
    func_00370B60(self);
    *(void***)((char*)self + 0x1F8) = D_004930D0;
    *(int*)((char*)self + 0x200) = 0;
    *(int*)((char*)self + 0x204) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003714F8);
#ifdef SKIP_ASM
extern void* D_004930D0[];
extern "C" void func_003715B0(void* self, int a1);
extern "C" void func_00370C08(void* self, int flags);

extern "C" void func_003714F8(void* self, int flags)
{
    *(void***)((char*)self + 0x1F8) = D_004930D0;
    func_003715B0(self, 0);
    func_00370C08(self, flags);
}
#endif

//100%
INCLUDE_ASM("render/particle", cDynamicColourEmitter_Allocate);
#ifdef SKIP_ASM
extern char D_00492690[];

struct sEmitColour_1548 {
    unsigned char rgba[4];
    sEmitColour_1548() {}
};

extern "C" void cDynamicColourEmitter_Allocate(void* self)
{
    char* s = (char*)self;
    sEmitColour_1548** pc = (sEmitColour_1548**)(s + 0x204);
    cBaseClass_DynamicEmitter_Allocate(self);
    *pc = new (D_00492690, 0, 0) sEmitColour_1548[*(int*)(s + 0x178)];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/particle", func_003715B0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
extern "C" void func_00370CF8(void* self, int a1);

extern "C" void func_003715B0(void* self, int a1)
{
    void* p = *(void**)((char*)self + 0x204);
    if (p != 0) {
        cMemMan_free(p);
        *(void**)((char*)self + 0x204) = 0;
    }
    func_00370CF8(self, a1);
}
#endif

//100%
INCLUDE_ASM("render/particle", cDynamicColourEmitter_reset);
#ifdef SKIP_ASM
struct sRGBA_1600 {
    unsigned char r, g, b, a;
};

// Function-local static `sRGBA black(0,0,0,0)` and its init guard, spelled out
// as the globals splat named.
extern unsigned char D_004A5998;
extern unsigned char D_004A5999;
extern unsigned char D_004A599A;
extern unsigned char D_004A599B;
extern int D_004A599C;

extern "C" void cDynamicColourEmitter_reset(void* self)
{
    int i;
    cBaseClass_DynamicEmitter_reset(self);
    for (i = 0; i < *(int*)((char*)self + 0x178); i++) {
        if (D_004A599C == 0) {
            D_004A5998 = 0;
            D_004A5999 = 0;
            D_004A599A = 0;
            D_004A599B = 0;
            D_004A599C = 1;
        }
        (*(sRGBA_1600**)((char*)self + 0x204))[i] = *(sRGBA_1600*)&D_004A5998;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371688);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPtRS1688 {
    int field_0x0;          // 0x1E4
    int flagsA;             // 0x1E8, bits 2..6 = layer
    int flagsB;             // 0x1EC, bits 5..9 = blend
    int field_0xC;          // 0x1F0
    short tex;              // 0x1F4
    short pad;
};

struct sPtVEntry1688 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sPtCtx1688 {
    char pad_0x0[0xE84];
    sPtRS1688* top;             // 0xE84
    char pad_0xE88[0xF50 - 0xE88];
    int texIds[(0x10D8 - 0xF50) / 4];   // 0xF50
    sPtVEntry1688* vtable;      // 0x10D8
};

extern char* D_004A5B80;
extern sPtCtx1688* D_004A5B80_ctx1688 __asm__("D_004A5B80");
extern int D_0044B420[];

struct sPtObj1688 {
    char pad_0x0[0x4];
    int base;               // 0x4
    int kind;               // 0x8
    char pad_0xC[0x4];
    float frame;            // 0x10
    char pad_0x14[0x160];
    int field_0x174;        // 0x174
    char pad_0x178[0x68];
    int field_0x1E0;        // 0x1E0
    sPtRS1688 rs;           // 0x1E4
};

extern "C" void func_00371688(sPtObj1688* self, int blend)
{
    if (self->field_0x174 == 0) {
        return;
    }
    sPtCtx1688* ctx = D_004A5B80_ctx1688;
    if (self->field_0x1E0 == 0) {
        return;
    }
    int tex = ctx->texIds[self->base + (int)self->frame];
    if (tex < 0) {
        return;
    }
    self->rs.flagsA = (self->rs.flagsA & ~0x7C) | ((D_0044B420[self->kind] << 2) & 0x7C);
    self->rs.flagsB = (self->rs.flagsB & ~0x3E0) | ((blend << 5) & 0x3E0);
    self->rs.tex = tex;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *ctx->top = self->rs;
    sPtVEntry1688* vt = ctx->vtable;
    vt[84].fn((char*)ctx + vt[84].delta, self);
    ctx->top--;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/particle", func_003717C0);
#ifdef SKIP_ASM
struct sPtCol17C0 {
    float r, g, b, a;
} __attribute__((aligned(16)));

struct sPtRGBA17C0 {
    unsigned char r, g, b, a;
};

struct sPtObj17C0 {
    char pad_0x0[0x17C];
    int idx;                    // 0x17C
    char pad_0x180[0x50];
    sPtCol17C0 col;             // 0x1D0
    char pad_0x1E0[0x24];
    sPtRGBA17C0* colors;        // 0x204
};

extern "C" void func_003710D0(void* self, int a1, int a2, int a3);

// PORT: g++ minimum operator (<?).
static inline float clamp17C0(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

extern "C" void func_003717C0(sPtObj17C0* self, int a1, int a2, sPtCol17C0* col, int a4)
{
    if (col != 0) {
        self->col = *col;
    } else {
        col = &self->col;
    }
    self->colors[self->idx].a = (int)clamp17C0(col->a * 255.0f, 0.0f, 255.0f);
    self->colors[self->idx].r = (int)clamp17C0(col->r * 255.0f, 0.0f, 255.0f);
    self->colors[self->idx].g = (int)clamp17C0(col->g * 255.0f, 0.0f, 255.0f);
    self->colors[self->idx].b = (int)clamp17C0(col->b * 255.0f, 0.0f, 255.0f);
    func_003710D0(self, a1, a2, a4);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371940);
#ifdef SKIP_ASM
struct sGifQuad {
    unsigned int w[4];
} __attribute__((aligned(16)));

extern sGifQuad D_0044B430;

// PORT: PS2 hardware registers (D2 = GIF DMA channel, VIF1 FIFO, GIF_MODE).
extern "C" void func_00371940(unsigned int madr, int qwc, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x1000A000 & 0x100) {
        }
    }
    *(sGifQuad*)0x10005000 = D_0044B430;
    *(volatile int*)0x10003010 = 4;
    if (madr > 0x6FFFFFFF) {
        *(volatile unsigned int*)0x1000A010 = (madr & 0x3FF0) | 0x80000000;
    } else {
        *(volatile unsigned int*)0x1000A010 = madr;
    }
    *(volatile int*)0x1000A020 = qwc;
    *(volatile int*)0x1000A000 = 0x101;
    if (flags & 2) {
        while (*(volatile int*)0x1000A000 & 0x100) {
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371D10);
#ifdef SKIP_ASM
extern "C" void func_00371D10(unsigned int madr, int sadr, int qwc, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x1000D400 & 0x100) {
        }
    }
    *(volatile int*)0x1000D410 = madr;
    *(volatile int*)0x1000D480 = sadr & 0x3FFF;
    *(volatile int*)0x1000D420 = qwc;
    *(volatile int*)0x1000D400 = 0x100;
    if (flags & 2) {
        while (*(volatile int*)0x1000D400 & 0x100) {
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371DD8);
#ifdef SKIP_ASM
extern "C" void func_00371DD8(int sadr, unsigned int madr, int qwc, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x1000D000 & 0x100) {
        }
    }
    *(volatile int*)0x1000D010 = madr;
    *(volatile int*)0x1000D080 = sadr & 0x3FFF;
    *(volatile int*)0x1000D020 = qwc;
    *(volatile int*)0x1000D000 = 0x100;
    if (flags & 2) {
        while (*(volatile int*)0x1000D000 & 0x100) {
        }
    }
}
#endif

extern "C" void* func_003725B0(void* self);

//100%
INCLUDE_ASM("render/particle", func_00372500__FPv);
#ifdef SKIP_ASM
void* func_00372500(void* self)
{
    return func_003725B0(self);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00372520);
#ifdef SKIP_ASM
extern int D_004A422C;
extern int D_004A41E0;
extern int D_004A41E4;
extern int D_004A41E8;
extern void* D_00493068[];

struct sPtVert_2520 {
    float x;        // 0x0
    float y;        // 0x4
    float z;        // 0x8
    int w;          // 0xC
    int r;          // 0x10
    int g;          // 0x14
    int b;          // 0x18
    int a;          // 0x1C
    char pad[0x10];
};
extern sPtVert_2520 D_00501440[];

struct sPtObj_2520 {
    void** vt;      // 0x0
    void* owner;    // 0x4
    int f8;         // 0x8
};

extern "C" void* func_00372520(sPtObj_2520* self, void* owner)
{
    int i;
    self->owner = owner;
    self->vt = D_00493068;
    self->f8 = 0;
    if (D_004A422C == 0) {
        sPtVert_2520* v = D_00501440;
        for (i = 0; i < 0x106; i++, v++) {
            v->a = 0xFF;
            v->r = D_004A41E0;
            v->g = D_004A41E4;
            v->b = D_004A41E8;
            v->z = 1.0f;
            v->w = 0;
            v->x = 0.0f;
            if (i & 1) {
                v->y = 1.0f;
            } else {
                v->y = 0.0f;
            }
        }
        D_004A422C = 1;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003725B0);
#ifdef SKIP_ASM
extern float D_004A4230;
extern float D_004A4234;
extern float D_004A4238;

extern "C" void* func_003725B0(void* self)
{
    if (D_004A4230 != (float)D_004A41E0 || D_004A4234 != (float)D_004A41E4 || D_004A4238 != (float)D_004A41E8) {
        int i;
        for (i = 0; i < 0x106; i++) {
            sPtVert_2520* v = &D_00501440[i];
            v->r = D_004A41E0;
            v->g = D_004A41E4;
            v->b = D_004A41E8;
        }
        D_004A4230 = (float)D_004A41E0;
        D_004A4234 = (float)D_004A41E4;
        D_004A4238 = (float)D_004A41E8;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00372660);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void operator_delete(int* ptr);
extern void* D_00493068[];
extern void* D_00488680[];

extern "C" void func_00372660(void* self, int flags)
{
    *(void***)self = D_00493068;
    if (*(void**)((char*)self + 0x8) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x8));
    }
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("render/particle", func_003726C8);

//100%
INCLUDE_ASM("render/particle", func_00372AA0);
#ifdef SKIP_ASM
extern int D_004A423C;
extern int D_004A4208;
extern int D_004A420C;
extern int D_004A4210;
extern int D_004A4214;
extern void* D_00493038[];

struct sPtVert_2AA0 {
    float x;        // 0x0
    float y;        // 0x4
    float z;        // 0x8
    int w;          // 0xC
    int r;          // 0x10
    int g;          // 0x14
    int b;          // 0x18
    int a;          // 0x1C
    char pad[0x10];
};
extern sPtVert_2AA0 D_00504560[];

struct sPtObj_2AA0 {
    void** vt;      // 0x0
};

extern "C" void* func_00372AA0(sPtObj_2AA0* self)
{
    int i;
    self->vt = D_00493038;
    if (D_004A423C == 0) {
        for (i = 0; i < 8; i++) {
            D_00504560[i].a = D_004A4214;
            D_00504560[i].r = D_004A4208;
            D_00504560[i].g = D_004A420C;
            D_00504560[i].b = D_004A4210;
            D_00504560[i].z = 1.0f;
            D_00504560[i].w = 0;
            D_00504560[i].x = 0.0f;
            D_00504560[i].y = 0.0f;
        }
        D_004A423C = 1;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00372B30);
#ifdef SKIP_ASM
inline void* operator new[](unsigned int, void* p) { return p; }

struct sPtElem2B30 {
    float v[4];
    sPtElem2B30() {}
};

extern "C" void* func_00372B30(void* self)
{
    new ((char*)self + 0x20) sPtElem2B30[4];
    new ((char*)self + 0x60) sPtElem2B30[6];
    new ((char*)self + 0xC0) sPtElem2B30[8];
    new ((char*)self + 0x140) sPtElem2B30[4];
    new ((char*)self + 0x180) sPtElem2B30[6];
    new ((char*)self + 0x1E0) sPtElem2B30[8];
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    return self;
}
#endif

INCLUDE_ASM("render/particle", func_00372B78);

//100%
INCLUDE_ASM("render/particle", func_003739D0);
#ifdef SKIP_ASM
struct sPtSlot39D0 {
    int f0;
    int f4;
    int f8;
};

struct sPtPools39D0 {
    int cnt[3];                     // 0x0
    sPtSlot39D0* elems[3];          // 0xC
    sPtSlot39D0* slots[3];          // 0x18
    char pad_0x24[0xC];
    int* freeList[3];               // 0x30
    int freeCount[3];               // 0x3C
    char pad_0x48[0x1A8 - 0x48];
    int cntB[3];                    // 0x1A8
    char pad_0x1B4[0x1CC - 0x1B4];
    int* freeListB[3];              // 0x1CC
    int freeCountB[3];              // 0x1D8
};

extern "C" void func_003E6448(void* dst, int c, int n);

extern "C" void func_003739D0(sPtPools39D0* self)
{
    int n0 = self->cnt[0];
    int n1 = self->cnt[1];
    int n2 = self->cnt[2];
    int size = 0xC;
    func_003E6448(self->elems[0], 0, n0 * size);
    func_003E6448(self->elems[1], 0, n1 * size);
    func_003E6448(self->elems[2], 0, n2 * size);
    self->freeCount[0] = 0;
    self->freeCount[1] = 0;
    self->freeCount[2] = 0;
    int i;
    for (i = 0; i < n0; i++) {
        self->freeList[0][self->freeCount[0]++] = i;
    }
    for (i = 0; i < n1; i++) {
        self->freeList[1][self->freeCount[1]++] = i;
    }
    for (i = 0; i < n2; i++) {
        self->freeList[2][self->freeCount[2]++] = i;
    }
    int m0 = self->cntB[0];
    int m1 = self->cntB[1];
    int m2 = self->cntB[2];
    int k;
    for (k = 0; k < 3; k++) {
        int j;
        for (j = 0; j < self->cnt[k]; j++) {
            self->slots[k][j].f8 = -1;
            self->slots[k][j].f4 = 0;
            self->slots[k][j].f0 = 0;
        }
    }
    self->freeCountB[0] = 0;
    self->freeCountB[1] = 0;
    self->freeCountB[2] = 0;
    for (i = 0; i < m0; i++) {
        self->freeListB[0][self->freeCountB[0]++] = i;
    }
    for (i = 0; i < m1; i++) {
        self->freeListB[1][self->freeCountB[1]++] = i;
    }
    for (i = 0; i < m2; i++) {
        self->freeListB[2][self->freeCountB[2]++] = i;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374180);
#ifdef SKIP_ASM
struct sPatchVec {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPatchOut {
    float x, y, z;
};

struct sPatchSet {
    char pad_0x00[0x190];
    sPatchVec* basis[3];    // 0x190
    int count[3];           // 0x19C
};

// PORT: PS2-only VU0 inline asm (tensor-product patch evaluation: out[i][j] =
// sum over basis[i] (x) basis[j] of the 4x4 control block at mat+0x40).
extern "C" void func_00374180(sPatchSet* self, char* mat, sPatchOut* out, int idx)
{
    int n = self->count[idx];
    sPatchVec* basis = self->basis[idx];
    int i;
    int j;
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "lqc2      $vf5, 0x40(%0)\n"
        "lqc2      $vf6, 0x50(%0)\n"
        "lqc2      $vf7, 0x60(%0)\n"
        "lqc2      $vf8, 0x70(%0)\n"
        "lqc2      $vf9, 0x80(%0)\n"
        "lqc2      $vf10, 0x90(%0)\n"
        "lqc2      $vf11, 0xA0(%0)\n"
        "lqc2      $vf12, 0xB0(%0)\n"
        "lqc2      $vf13, 0xC0(%0)\n"
        "lqc2      $vf14, 0xD0(%0)\n"
        "lqc2      $vf15, 0xE0(%0)\n"
        "lqc2      $vf16, 0xF0(%0)\n"
        :
        : "r"(mat + 0x40));
    for (i = 0; i < n; i++) {
        __asm__ __volatile__(
            "lqc2      $vf17, 0x0(%0)\n"
            "vmulax.xyzw ACC, $vf1, $vf17x\n"
            "vmadday.xyzw ACC, $vf2, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf3, $vf17z\n"
            "vmaddw.xyzw $vf18, $vf4, $vf17w\n"
            "vmulax.xyzw ACC, $vf5, $vf17x\n"
            "vmadday.xyzw ACC, $vf6, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf7, $vf17z\n"
            "vmaddw.xyzw $vf19, $vf8, $vf17w\n"
            "vmulax.xyzw ACC, $vf9, $vf17x\n"
            "vmadday.xyzw ACC, $vf10, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf11, $vf17z\n"
            "vmaddw.xyzw $vf20, $vf12, $vf17w\n"
            "vmulax.xyzw ACC, $vf13, $vf17x\n"
            "vmadday.xyzw ACC, $vf14, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf15, $vf17z\n"
            "vmaddw.xyzw $vf21, $vf16, $vf17w\n"
            :
            : "r"(&basis[i]));
        for (j = 0; j < n; j++) {
            sPatchVec t;
            __asm__(
                "lqc2      $vf22, 0x0(%1)\n"
                "vmulax.xyzw ACC, $vf18, $vf22x\n"
                "vmadday.xyzw ACC, $vf19, $vf22y\n"
                "vmaddaz.xyzw ACC, $vf20, $vf22z\n"
                "vmaddw.xyzw $vf23, $vf21, $vf22w\n"
                "sqc2      $vf23, %0\n"
                : "=m"(t)
                : "r"(&basis[j]));
            *out++ = *(sPatchOut*)&t;
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374298);
#ifdef SKIP_ASM
struct sV2_4298 {
    float x, y;
    sV2_4298() {}
    sV2_4298(float ax, float ay) : x(ax), y(ay) {}
    sV2_4298& operator+=(const sV2_4298& b) { x += b.x; y += b.y; return *this; }
};

static inline sV2_4298 operator-(const sV2_4298& a, const sV2_4298& b)
{
    return sV2_4298(a.x - b.x, a.y - b.y);
}

static inline sV2_4298 operator*(const sV2_4298& a, float k)
{
    return sV2_4298(a.x * k, a.y * k);
}

extern "C" void func_00374298(char* self, char* src, sV2_4298* out, int idx)
{
    int n = *(int*)(self + (idx << 2) + 0x19C);
    sV2_4298 c0 = *(sV2_4298*)(src + 0x20);
    sV2_4298 c1 = *(sV2_4298*)(src + 0x28);
    sV2_4298 c2 = *(sV2_4298*)(src + 0x30);
    sV2_4298 c3 = *(sV2_4298*)(src + 0x38);
    float step = 1.0f / (float)(n - 1);
    sV2_4298 dl = (c2 - c0) * step;
    sV2_4298 dr = (c3 - c1) * step;
    int i;
    for (i = 0; i < n; i++) {
        sV2_4298 p = c0;
        sV2_4298 d = (c1 - c0) * step;
        int j;
        for (j = 0; j < n; j++) {
            *out = p;
            out++;
            p += d;
        }
        c0 += dl;
        c1 += dr;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374440);
#ifdef SKIP_ASM
struct sPtVec2 {
    float x, y;
};

struct sPtRect {
    char pad_0x0[0x10];
    sPtVec2 origin;
    sPtVec2 size;
};

extern "C" void func_00374440(char* self, sPtRect* rect, sPtVec2* out, int idx)
{
    int i, j;
    int n = *(int*)(self + (idx << 2) + 0x19C);
    sPtVec2 pos = rect->origin;
    sPtVec2 step = rect->size;
    float inv = 1.0f / (float)(n - 1);
    step.x *= inv;
    step.y *= inv;
    for (i = 0; i < n; i++) {
        sPtVec2 cur = pos;
        for (j = 0; j < n; j++) {
            *out++ = cur;
            cur.y += step.y;
        }
        pos.x += step.x;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374518);
#ifdef SKIP_ASM
struct sPatchVec4518 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPatchOut4518 {
    float x, y, z;
    sPatchOut4518() {}
    sPatchOut4518(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    sPatchOut4518(const sPatchOut4518& o) : x(o.x), y(o.y), z(o.z) {}
};

static inline sPatchOut4518 Cross4518(const sPatchOut4518& a, const sPatchOut4518& b)
{
    return sPatchOut4518(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

static inline sPatchOut4518 Normalize4518(const sPatchOut4518& v)
{
    float d2 = v.x * v.x + v.y * v.y + v.z * v.z;
    float d;
    // PORT: sqrt.s (sqrtf without errno check)
    __asm__("sqrt.s %0, %1" : "=f"(d) : "f"(d2));
    if (d != 0.0f) {
        float k = 1.0f / d;
        return sPatchOut4518(v.x * k, v.y * k, v.z * k);
    }
    return v;
}

struct sPatchSet4518 {
    char pad_0x00[0x190];
    sPatchVec4518* basis[3];    // 0x190
    int count[3];               // 0x19C
    char pad_0x1A8[0x310 - 0x1A8];
    sPatchVec4518* dbasis[3];   // 0x310
};

// PORT: PS2-only VU0 inline asm (tensor-product patch evaluation, then normals
// as the normalised cross product of the two partial derivatives).
extern "C" void func_00374518(sPatchSet4518* self, char* mat, sPatchOut4518* out, int idx)
{
    int n = self->count[idx];
    sPatchVec4518* basis = self->basis[idx];
    sPatchVec4518* dbasis = self->dbasis[idx];
    sPatchOut4518* o = out;
    int i;
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "lqc2      $vf5, 0x40(%0)\n"
        "lqc2      $vf6, 0x50(%0)\n"
        "lqc2      $vf7, 0x60(%0)\n"
        "lqc2      $vf8, 0x70(%0)\n"
        "lqc2      $vf9, 0x80(%0)\n"
        "lqc2      $vf10, 0x90(%0)\n"
        "lqc2      $vf11, 0xA0(%0)\n"
        "lqc2      $vf12, 0xB0(%0)\n"
        "lqc2      $vf13, 0xC0(%0)\n"
        "lqc2      $vf14, 0xD0(%0)\n"
        "lqc2      $vf15, 0xE0(%0)\n"
        "lqc2      $vf16, 0xF0(%0)\n"
        :
        : "r"(mat + 0x40));
    for (i = 0; i < n; i++) {
        __asm__ __volatile__(
            "lqc2      $vf17, 0x0(%0)\n"
            "vmulax.xyzw ACC, $vf1, $vf17x\n"
            "vmadday.xyzw ACC, $vf2, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf3, $vf17z\n"
            "vmaddw.xyzw $vf18, $vf4, $vf17w\n"
            "vmulax.xyzw ACC, $vf5, $vf17x\n"
            "vmadday.xyzw ACC, $vf6, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf7, $vf17z\n"
            "vmaddw.xyzw $vf19, $vf8, $vf17w\n"
            "vmulax.xyzw ACC, $vf9, $vf17x\n"
            "vmadday.xyzw ACC, $vf10, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf11, $vf17z\n"
            "vmaddw.xyzw $vf20, $vf12, $vf17w\n"
            "vmulax.xyzw ACC, $vf13, $vf17x\n"
            "vmadday.xyzw ACC, $vf14, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf15, $vf17z\n"
            "vmaddw.xyzw $vf21, $vf16, $vf17w\n"
            :
            : "r"(&dbasis[i]));
        for (int j = 0; j < n; j++) {
            sPatchVec4518 t;
            __asm__(
                "lqc2      $vf22, 0x0(%1)\n"
                "vmulax.xyzw ACC, $vf18, $vf22x\n"
                "vmadday.xyzw ACC, $vf19, $vf22y\n"
                "vmaddaz.xyzw ACC, $vf20, $vf22z\n"
                "vmaddw.xyzw $vf23, $vf21, $vf22w\n"
                "sqc2      $vf23, %0\n"
                : "=m"(t)
                : "r"(&basis[j]));
            *o++ = *(sPatchOut4518*)&t;
        }
    }
    o = out;
    for (i = 0; i < n; i++) {
        __asm__ __volatile__(
            "lqc2      $vf17, 0x0(%0)\n"
            "vmulax.xyzw ACC, $vf1, $vf17x\n"
            "vmadday.xyzw ACC, $vf2, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf3, $vf17z\n"
            "vmaddw.xyzw $vf18, $vf4, $vf17w\n"
            "vmulax.xyzw ACC, $vf5, $vf17x\n"
            "vmadday.xyzw ACC, $vf6, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf7, $vf17z\n"
            "vmaddw.xyzw $vf19, $vf8, $vf17w\n"
            "vmulax.xyzw ACC, $vf9, $vf17x\n"
            "vmadday.xyzw ACC, $vf10, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf11, $vf17z\n"
            "vmaddw.xyzw $vf20, $vf12, $vf17w\n"
            "vmulax.xyzw ACC, $vf13, $vf17x\n"
            "vmadday.xyzw ACC, $vf14, $vf17y\n"
            "vmaddaz.xyzw ACC, $vf15, $vf17z\n"
            "vmaddw.xyzw $vf21, $vf16, $vf17w\n"
            :
            : "r"(&basis[i]));
        for (int j = 0; j < n; j++) {
            sPatchVec4518 t;
            __asm__(
                "lqc2      $vf22, 0x0(%1)\n"
                "vmulax.xyzw ACC, $vf18, $vf22x\n"
                "vmadday.xyzw ACC, $vf19, $vf22y\n"
                "vmaddaz.xyzw ACC, $vf20, $vf22z\n"
                "vmaddw.xyzw $vf23, $vf21, $vf22w\n"
                "sqc2      $vf23, %0\n"
                : "=m"(t)
                : "r"(&dbasis[j]));
            sPatchOut4518 r = Normalize4518(Cross4518(*(sPatchOut4518*)&t, *o));
            *o++ = r;
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003747A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPV3_47A0 {
    float x, y, z;
};

struct sPV2_47A0 {
    float x, y;
};

struct sPEnt_47A0 {
    char* mat;      // 0x0
    int flags;      // 0x4
    int nslot;      // 0x8
};

struct sPMgr_47A0 {
    char pad_0x0[0x18];
    sPEnt_47A0* entries[3];         // 0x18
    char pad_0x24[0xC];
    int* freeList[3];               // 0x30
    int freeCount[3];               // 0x3C
    sPV3_47A0 (*pos0)[16];          // 0x48
    sPV3_47A0 (*pos1)[36];          // 0x4C
    sPV3_47A0 (*pos2)[64];          // 0x50
    sPV2_47A0 (*uv0)[16];           // 0x54
    sPV2_47A0 (*uv1)[36];           // 0x58
    sPV2_47A0 (*uv2)[64];           // 0x5C
    sPV2_47A0 (*col0)[16];          // 0x60
    sPV2_47A0 (*col1)[36];          // 0x64
    sPV2_47A0 (*col2)[64];          // 0x68
    char pad_0x6C[0x1B4 - 0x6C];
    sPV3_47A0 (*nrm0)[16];          // 0x1B4
    sPV3_47A0 (*nrm1)[36];          // 0x1B8
    sPV3_47A0 (*nrm2)[64];          // 0x1BC
    char pad_0x1C0[0xC];
    int* nfreeList[3];              // 0x1CC
    int nfreeCount[3];              // 0x1D8
};

// func_00374518 is declared through a local view so the unit's own definition keeps its types
extern "C" void func_00374518_47A0(sPMgr_47A0* self, char* mat, sPV3_47A0* out, int idx) __asm__("func_00374518");

static inline int PopSlot_47A0(sPMgr_47A0* self, int idx)
{
    int r;
    if (self->freeCount[idx] > 0) {
        r = self->freeList[idx][--self->freeCount[idx]];
    } else {
        r = -1;
    }
    return r;
}

static inline sPV3_47A0* PosOf_47A0(sPMgr_47A0* self, int idx, int slot)
{
    switch (idx) {
    case 0:
        return self->pos0[slot];
    case 1:
        return self->pos1[slot];
    case 2:
        return self->pos2[slot];
    }
    return 0;
}

static inline sPV2_47A0* UVOf_47A0(sPMgr_47A0* self, int idx, int slot)
{
    switch (idx) {
    case 0:
        return self->uv0[slot];
    case 1:
        return self->uv1[slot];
    case 2:
        return self->uv2[slot];
    }
    return 0;
}

static inline sPV2_47A0* ColOf_47A0(sPMgr_47A0* self, int idx, int slot)
{
    switch (idx) {
    case 0:
        return self->col0[slot];
    case 1:
        return self->col1[slot];
    case 2:
        return self->col2[slot];
    }
    return 0;
}

static inline sPV3_47A0* NrmOf_47A0(sPMgr_47A0* self, int idx, int slot)
{
    switch (idx) {
    case 0:
        return self->nrm0[slot];
    case 1:
        return self->nrm1[slot];
    case 2:
        return self->nrm2[slot];
    }
    return 0;
}

extern "C" int func_003747A0(sPMgr_47A0* self, char* mat, int idx, int bit, int normals)
{
    int slot = PopSlot_47A0(self, idx);
    sPV3_47A0* pos = PosOf_47A0(self, idx, slot);
    sPV2_47A0* uv = UVOf_47A0(self, idx, slot);
    sPV2_47A0* col = ColOf_47A0(self, idx, slot);
    func_00374180((sPatchSet*)self, mat, (sPatchOut*)pos, idx);
    func_00374298((char*)self, mat, (sV2_4298*)uv, idx);
    func_00374440((char*)self, (sPtRect*)mat, (sPtVec2*)col, idx);
    sPEnt_47A0* e = &self->entries[idx][slot];
    e->mat = mat;
    *(short*)(mat + (idx << 1) + 0x1A6) = slot;
    e->flags |= 0xC | (1 << bit);
    if (normals) {
        int nslot = self->nfreeList[idx][--self->nfreeCount[idx]];
        sPV3_47A0* nrm = NrmOf_47A0(self, idx, nslot);
        func_00374518_47A0(self, mat, nrm, idx);
        e->nslot = nslot;
    }
    return slot;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374A88);
#ifdef SKIP_ASM
struct sPartItem {
    char pad[0xC];
    short v;
    short pad2;
};

struct sPartOwner {
    char pad[0x18];
    char* lists[1];
};

extern "C" void func_00374A88(sPartOwner* self, int count, sPartItem* items, int idx, int bit)
{
    int mask = (1 << bit) | 0xC;
    for (int i = 0; i < count; i++) {
        short v = items[i].v;
        if (v >= 0) {
            char* p = self->lists[idx] + v * 0xC;
            *(int*)(p + 4) |= mask;
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374AE0);
#ifdef SKIP_ASM
struct sPartItem14 {
    char pad[0xC];
    short v;
    short pad2;
    int pad3;
};

extern "C" void func_00374AE0(sPartOwner* self, int count, sPartItem14* items, int idx, int bit)
{
    int mask = (1 << bit) | 0xC;
    for (int i = 0; i < count; i++) {
        short v = items[i].v;
        if (v >= 0) {
            char* p = self->lists[idx] + v * 0xC;
            *(int*)(p + 4) |= mask;
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374B38);
#ifdef SKIP_ASM
struct sPartRef {
    char pad_0x00[0x1A6];
    short slot[3];          // 0x1A6
};

struct sPartSlotEntry {
    sPartRef* owner;      // 0x00
    int flags;              // 0x04
    int slot;               // 0x08
};

struct sPartLists {
    int count[3];               // 0x00
    char pad_0x0C[0xC];
    sPartSlotEntry* entries[3];     // 0x18
    char pad_0x24[0xC];
    int* freeList[3];           // 0x30
    int freeCount[3];           // 0x3C
    char pad_0x48[0x1CC - 0x48];
    int* slotList[3];           // 0x1CC
    int slotCount[3];           // 0x1D8
};

extern "C" void func_00374B38(sPartLists* self)
{
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        int n = self->count[i];
        sPartSlotEntry* list = self->entries[i];
        for (j = 0; j < n; j++) {
            sPartSlotEntry* e = &list[j];
            int f = e->flags;
            if (f & 4) {
                e->flags = f & ~4;
            } else if (f & 8) {
                e->flags = f & ~8;
            } else if (f != 0) {
                e->flags = 0;
                e->owner->slot[i] = -1;
                if (e->slot >= 0) {
                    self->slotList[i][self->slotCount[i]++] = e->slot;
                    e->slot = -1;
                }
                self->freeList[i][self->freeCount[i]++] = j;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374C90);
#ifdef SKIP_ASM
extern void* D_004A4248;
extern void* D_00493820[];

extern "C" void* func_00374C90(void* self)
{
    *(void***)((char*)self + 0x4) = D_00493820;
    D_004A4248 = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374CA8);
#ifdef SKIP_ASM
extern void* D_004A4248;
extern void* D_00493820[];
void operator_delete(int* ptr);

extern "C" void func_00374CA8(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00493820;
    D_004A4248 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00374CE0);
#ifdef SKIP_ASM
extern "C" void func_00374CE0(void* self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    *(int*)((char*)self + 0x17c) = a1;
    *(int*)((char*)self + 0x180) = a2;
    *(int*)((char*)self + 0x184) = a3;
    *(int*)((char*)self + 0x188) = a4;
    *(int*)((char*)self + 0x18c) = a5;
    *(int*)((char*)self + 0x190) = a6;
}
#endif

INCLUDE_ASM("render/particle", func_00374D00);

//100%
INCLUDE_ASM("render/particle", func_00375890);
#ifdef SKIP_ASM
extern char* D_004A5B80;

struct sPtVec4_5890 {
    float x, y, z, w;
    sPtVec4_5890(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

class cGfxMan_5890 {
public:
    char pad[0x10D8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67(const sPtVec4_5890& pos, void* a, void* b, int tex, float scale);
};

extern "C" void func_00375890(void* self)
{
    char* s = (char*)self;
    ((cGfxMan_5890*)D_004A5B80)->v67(sPtVec4_5890(*(float*)(s + 0xC), *(float*)(s + 0x10), *(float*)(s + 0x14), 1.0f),
                                     s + 0x90, s + 0xD0, *(int*)(s + 0x170), 1.0f);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003758F8__FPv);
#ifdef SKIP_ASM
void* func_003758F8(void* self)
{
    *(int*)((char*)self + 0x170) = -1;
    *(int*)((char*)self + 0x174) = 0x80;
    *(int*)((char*)self + 0x178) = 0x80;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00375918);
#ifdef SKIP_ASM
extern char* D_004A5B80;
extern "C" void func_00367B60(void* mgr, int id);
void operator_delete(int* ptr);

struct sPtVEntry_5918 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00375918(void* self, int flags)
{
    char* s = (char*)self;
    int tex = *(int*)(s + 0x170);
    if (tex >= 0) {
        func_00367B60(*(void**)(D_004A5B80 + 0x18F4), tex);
        char* mgr = D_004A5B80;
        sPtVEntry_5918* vt = *(sPtVEntry_5918**)(mgr + 0x10D8);
        vt[50].fn(mgr + vt[50].delta, *(int*)(s + 0x170));
        *(int*)(s + 0x170) = -1;
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00375990);
#ifdef SKIP_ASM
extern char* D_004A5B80;

struct sPtVEntry_5990 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int);
};

extern "C" void func_00375990(void* self)
{
    char* s = (char*)self;
    if (*(int*)(s + 0x170) < 0) {
        char* mgr = D_004A5B80;
        sPtVEntry_5990* vt = *(sPtVEntry_5990**)(mgr + 0x10D8);
        *(int*)(s + 0x170) = vt[52].fn(mgr + vt[52].delta, *(int*)(s + 0x174), *(int*)(s + 0x178), 2);
    }
}
#endif

extern void* D_00493000[];

//100%
INCLUDE_ASM("render/particle", func_003759E8__FPv);
#ifdef SKIP_ASM
void* func_003759E8(void* self)
{
    *(int*)self = (int)(void*)D_00493000;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00375A00__FPv);
#ifdef SKIP_ASM
void func_00375A00(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00375A08);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00492878[];
extern "C" void* func_00395288(void* self);

extern "C" void* func_00375A08(void)
{
    return func_00395288(cMemMan_alloc(0x75E0, D_00492878, 0, 0));
}
#endif

INCLUDE_ASM("render/particle", func_00375A40);

//100%
INCLUDE_ASM("render/particle", func_00376268);
#ifdef SKIP_ASM
extern "C" void func_00424880(int);
extern "C" void func_00423AA0(int, int);
extern "C" void func_00424950(int);
extern "C" void func_00423AD0(int, int);
extern "C" void func_00423BF0(int);
extern "C" void func_00423BB0(int);
extern "C" void func_00423DB0(int);
extern "C" void func_00367360(void*);
void* func_00361F40(void* self);
void operator_delete(int* ptr);
extern char D_005059D8[];

extern "C" void func_00376268(void* self)
{
    func_00424880(2);
    func_00423AA0(2, *(int*)((char*)self + 0x5AC0));
    func_00424950(1);
    func_00423AD0(0, *(int*)((char*)self + 0x5AC4));
    func_00423BF0(*(int*)((char*)self + 0x5AD0));
    func_00423BB0(*(int*)((char*)self + 0x5AD0));
    func_00423DB0(*(int*)((char*)self + 0x5AC8));
    func_00423DB0(*(int*)((char*)self + 0x5ACC));
    operator_delete(*(int**)((char*)self + 0x18F0));
    func_00367360(*(void**)((char*)self + 0x18F4));
    operator_delete(*(int**)((char*)self + 0x18F4));
    func_00361F40(D_005059D8);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003762F8);
#ifdef SKIP_ASM
struct sPartTexEntA4 {
    char pad_0x00[0x88];
    int width;          // 0x88
    int height;         // 0x8C
    int psm;            // 0x90
    int clutPsm;        // 0x94
    int fmt;            // 0x98
    char pad_0x9C[4];
    int id;             // 0xA0
};

struct sPartTexCache {
    char pad_0x00[0x59C4];
    int count;              // 0x59C4
    char pad_0x59C8[4];
    sPartTexEntA4* textures;     // 0x59CC
};

extern "C" int func_003762F8(sPartTexCache* self, int width, int height, unsigned int bpp,
                             unsigned int clutBpp, int fmt, int id)
{
    int i;
    sPartTexEntA4* t = self->textures;
    for (i = 0; i < self->count; i++, t++) {
        if (t->width == width && t->height == height && t->id == id) {
            int ok1 = 0;
            int ok2 = 0;
            int ok3 = 0;
            switch (bpp) {
            case 16:
                if (t->psm == 2) ok1 = 1; else ok1 = 0;
            case 24:
                if (t->psm == 1) ok1 = 1;
                break;
            case 32:
                if (t->psm == 0) ok1 = 1; else ok1 = 0;
                break;
            }
            switch (clutBpp) {
            case 16:
                if (t->clutPsm == 2) ok2 = 1; else ok2 = 0;
                break;
            case 24:
                if (t->clutPsm == 1) ok2 = 1; else ok2 = 0;
                break;
            case 32:
                if (t->clutPsm == 0) ok2 = 1; else ok2 = 0;
                break;
            }
            if (fmt == 24) {
                if (t->fmt == 0x31) ok3 = 1; else ok3 = 0;
            }
            if (ok1 && ok2 && ok3) {
                return i;
            }
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00376468);
#ifdef SKIP_ASM
struct sVEntry00376468 {
    short delta;
    short index;
    void* fn;
};

extern "C" void* func_00376468(void* self)
{
    sVEntry00376468* vt = *(sVEntry00376468**)((char*)self + 0x10D8);
    int i = ((int (*)(void*))vt[123].fn)((char*)self + vt[123].delta);
    if (i >= 0) {
        vt = *(sVEntry00376468**)((char*)self + 0x10D8);
        return ((void* (*)(void*, int))vt[4].fn)((char*)self + vt[4].delta, i);
    }
    return 0;
}
#endif

INCLUDE_ASM("render/particle", func_003764C0);

//100%
INCLUDE_ASM("render/particle", func_00376560);
#ifdef SKIP_ASM
extern "C" void* func_00376560(void* self, int a1)
{
    return *(char**)((char*)self + 0x59cc) + a1 * 0xa4;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00376578);
#ifdef SKIP_ASM
struct sPartVEntry122 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int, int, int, int);
};

extern "C" int func_00376578(void* self, int a1)
{
    sPartVEntry122* vt = *(sPartVEntry122**)((char*)self + 0x10D8);
    return vt[122].fn((char*)self + vt[122].delta, 0x200, 0x1C0, 0x18, 0x20, 0x18, a1);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003765B8);
#ifdef SKIP_ASM
struct sPtQ65B8 {
    float v[4];
} __attribute__((aligned(16)));

struct sPtMtx65B8 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPtScis65B8 {
    unsigned short v[4];
};

struct sPtView65B8 {
    float x, y, w, h;               // 0x00
    char pad_0x10[0x14];
    float f24;                      // 0x24
    float f28;                      // 0x28
    float f2C;                      // 0x2C
    sPtQ65B8 q30;                   // 0x30
    sPtQ65B8 q40;                   // 0x40
    sPtQ65B8 q50;                   // 0x50
    sPtMtx65B8 m60;                 // 0x60
    sPtMtx65B8 mA0;                 // 0xA0
    sPtMtx65B8 mE0;                 // 0xE0
    sPtMtx65B8 m120;                // 0x120
    sPtQ65B8 q160;                  // 0x160
    sPtQ65B8 q170;                  // 0x170
    sPtMtx65B8 m180;                // 0x180
    sPtMtx65B8 m1C0;                // 0x1C0
    sPtQ65B8 q200;                  // 0x200
    sPtQ65B8 q210;                  // 0x210
    sPtScis65B8 scissor;            // 0x220
    int key;                        // 0x228
    int pad_0x22C;
};

struct sPtGfx65B8 {
    char pad_0x0[0x10DC];
    int curView;                    // 0x10DC
    char pad_0x10E0[0x18F0 - 0x10E0];
    char* keys;                     // 0x18F0
    char pad_0x18F4[0x5780 - 0x18F4];
    sPtMtx65B8 m5780;               // 0x5780
    sPtMtx65B8 m57C0;               // 0x57C0
    sPtMtx65B8 m5800;               // 0x5800
    sPtQ65B8 q5840;                 // 0x5840
    sPtQ65B8 q5850;                 // 0x5850
    sPtMtx65B8 m5860;               // 0x5860
    sPtMtx65B8 m58A0;               // 0x58A0
    sPtQ65B8 q58E0;                 // 0x58E0
    sPtQ65B8 q58F0;                 // 0x58F0
    sPtScis65B8 scissor;            // 0x5900
    float f5908;                    // 0x5908
    float f590C;                    // 0x590C
    float f5910;                    // 0x5910
    char pad_0x5914[0xC];
    sPtQ65B8 q5920;                 // 0x5920
    char pad_0x5930[0x6AF0 - 0x5930];
    sPtMtx65B8 m6AF0;               // 0x6AF0
    char pad_0x6B30[0x40];
    sPtQ65B8 q6B70;                 // 0x6B70
    sPtQ65B8 q6B80;                 // 0x6B80
    char pad_0x6B90[0x6D20 - 0x6B90];
    sPtView65B8 views[1];           // 0x6D20
};

// PORT: PS2-only VU0 asm (lqc2/sqc2 4x4 matrix copy).
static inline void vu0CopyMtx65B8(sPtMtx65B8* dst, sPtMtx65B8* src)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "sqc2      $vf1, 0x0(%1)\n"
        "sqc2      $vf2, 0x10(%1)\n"
        "sqc2      $vf3, 0x20(%1)\n"
        "sqc2      $vf4, 0x30(%1)\n"
        :
        : "r"(src), "r"(dst)
        : "memory");
}

extern "C" void func_003950C0(sPtView65B8* dst, sPtView65B8* src);

extern "C" void func_003765B8(sPtGfx65B8* self)
{
    sPtView65B8* v = &self->views[self->curView];
    v->scissor = self->scissor;
    v->key = *(int*)(self->keys + 0x69CC4);
    v->f24 = self->f590C;
    v->f28 = self->f5908;
    vu0CopyMtx65B8(&v->m60, &self->m6AF0);
    v->q30 = self->q6B70;
    v->q40 = self->q6B80;
    vu0CopyMtx65B8(&v->mA0, &self->m5780);
    vu0CopyMtx65B8(&v->mE0, &self->m57C0);
    vu0CopyMtx65B8(&v->m120, &self->m5800);
    v->q160 = self->q5840;
    v->q170 = self->q5850;
    vu0CopyMtx65B8(&v->m180, &self->m5860);
    vu0CopyMtx65B8(&v->m1C0, &self->m58A0);
    v->q200 = self->q58E0;
    v->q210 = self->q58F0;
    v->f2C = self->f5910;
    v->q50 = self->q5920;
    self->curView++;
    func_003950C0(&self->views[self->curView], v);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00376768);
#ifdef SKIP_ASM
struct sPtQ6768 {
    float v[4];
} __attribute__((aligned(16)));

struct sPtMtx6768 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPtScis6768 {
    unsigned short v[4];
};

struct sPtView6768 {
    float x, y, w, h;               // 0x00
    char pad_0x10[0x14];
    float f24;                      // 0x24
    float f28;                      // 0x28
    float f2C;                      // 0x2C
    sPtQ6768 q30;                   // 0x30
    sPtQ6768 q40;                   // 0x40
    sPtQ6768 q50;                   // 0x50
    sPtMtx6768 m60;                 // 0x60
    sPtMtx6768 mA0;                 // 0xA0
    sPtMtx6768 mE0;                 // 0xE0
    sPtMtx6768 m120;                // 0x120
    sPtQ6768 q160;                  // 0x160
    sPtQ6768 q170;                  // 0x170
    sPtMtx6768 m180;                // 0x180
    sPtMtx6768 m1C0;                // 0x1C0
    sPtQ6768 q200;                  // 0x200
    sPtQ6768 q210;                  // 0x210
    sPtScis6768 scissor;            // 0x220
    int key;                        // 0x228
    int pad_0x22C;
};

struct sPtGfx6768 {
    char pad_0x0[0x10DC];
    int curView;                    // 0x10DC
    char pad_0x10E0[0x18F0 - 0x10E0];
    char* keys;                     // 0x18F0
    char pad_0x18F4[0x5780 - 0x18F4];
    sPtMtx6768 m5780;               // 0x5780
    sPtMtx6768 m57C0;               // 0x57C0
    sPtMtx6768 m5800;               // 0x5800
    sPtQ6768 q5840;                 // 0x5840
    sPtQ6768 q5850;                 // 0x5850
    sPtMtx6768 m5860;               // 0x5860
    sPtMtx6768 m58A0;               // 0x58A0
    sPtQ6768 q58E0;                 // 0x58E0
    sPtQ6768 q58F0;                 // 0x58F0
    sPtScis6768 scissor;            // 0x5900
    float f5908;                    // 0x5908
    float f590C;                    // 0x590C
    float f5910;                    // 0x5910
    char pad_0x5914[0xC];
    sPtQ6768 q5920;                 // 0x5920
    char pad_0x5930[0x6AF0 - 0x5930];
    sPtMtx6768 m6AF0;               // 0x6AF0
    char pad_0x6B30[0x40];
    sPtQ6768 q6B70;                 // 0x6B70
    sPtQ6768 q6B80;                 // 0x6B80
    int i6B90;                      // 0x6B90
    char pad_0x6B94[0x6D20 - 0x6B94];
    sPtView6768 views[1];           // 0x6D20
};

// PORT: PS2-only VU0 asm (lqc2/sqc2 4x4 matrix copy).
static inline void vu0CopyMtx6768(sPtMtx6768* dst, sPtMtx6768* src)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "sqc2      $vf1, 0x0(%1)\n"
        "sqc2      $vf2, 0x10(%1)\n"
        "sqc2      $vf3, 0x20(%1)\n"
        "sqc2      $vf4, 0x30(%1)\n"
        :
        : "r"(src), "r"(dst)
        : "memory");
}

extern "C" void func_00364B88(void* table, void* key);

extern "C" void func_00376768(sPtGfx6768* self)
{
    self->curView--;
    sPtView6768* v = &self->views[self->curView];
    self->scissor = v->scissor;
    if (v->key == -1) {
        func_00364B88(self->keys, &self->scissor);
    } else {
        *(int*)(self->keys + 0x69CC4) = v->key;
    }
    self->f590C = v->f24;
    self->f5908 = v->f28;
    vu0CopyMtx6768(&self->m6AF0, &v->m60);
    self->q6B70 = v->q30;
    self->q6B80 = v->q40;
    vu0CopyMtx6768(&self->m5780, &v->mA0);
    vu0CopyMtx6768(&self->m57C0, &v->mE0);
    vu0CopyMtx6768(&self->m5800, &v->m120);
    self->q5840 = v->q160;
    self->q5850 = v->q170;
    vu0CopyMtx6768(&self->m5860, &v->m180);
    vu0CopyMtx6768(&self->m58A0, &v->m1C0);
    self->q58E0 = v->q200;
    self->q58F0 = v->q210;
    self->f5910 = v->f2C;
    self->q5920 = v->q50;
    self->i6B90 = 0;
}
#endif

INCLUDE_ASM("render/particle", func_00376938);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/particle", func_00376A70);
#ifdef SKIP_ASM
struct sPtVEntryI6A70 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sPtView6A70 {
    float x, y, w, h;               // 0x6D20 in the first view
    char pad_0x10[0x220];
};

struct sPtGfx6A70 {
    char pad_0x0[0x10D8];
    sPtVEntryI6A70* vtable;         // 0x10D8
    int curView;                    // 0x10DC
    char pad_0x10E0[0x18F0 - 0x10E0];
    void* keys;                     // 0x18F0
    char pad_0x18F4[0x5900 - 0x18F4];
    unsigned short scissor[4];      // 0x5900
    char pad_0x5908[0x6B94 - 0x5908];
    int clampMode;                  // 0x6B94
    float clampTop;                 // 0x6B98
    float clampBottom;              // 0x6B9C
    char pad_0x6BA0[0x6D20 - 0x6BA0];
    sPtView6A70 views[1];           // 0x6D20
};

extern "C" void func_00376938(void* self, float x, float y, float w, float h);
extern "C" void func_00364B88(void* table, void* key);

extern "C" void func_00376A70(sPtGfx6A70* self, float x, float y, float w, float h)
{
    sPtVEntryI6A70* e = &self->vtable[11];
    int height = e->fn((char*)self + e->delta);
    int mode = self->clampMode;
    if (mode < 3) {
        if (mode >= 0) {
            float fh = (float)height;
            float top = self->clampTop * fh;
            if (y < top) {
                y = top;
            }
            float bottom = self->clampBottom * fh;
            if (bottom < h) {
                h = bottom;
            }
        }
    }
    self->views[self->curView].x = x;
    self->views[self->curView].y = y;
    self->views[self->curView].w = w;
    self->views[self->curView].h = h;
    func_00376938(self, x, y, w, h);
    func_00364B88(self->keys, self->scissor);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00376B90);
#ifdef SKIP_ASM
struct sPartVec4i {
    float x, y, z, w;
};

extern "C" sPartVec4i* func_00376B90(sPartVec4i* r, void* self)
{
    int i = *(int*)((char*)self + 0x10dc);
    float* p = (float*)((char*)self + (i * 0x230 + 0x6d20));
    int x = (int)p[0];
    int y = (int)p[1];
    int z = (int)p[2];
    int w = (int)p[3];
    r->x = (float)x;
    r->y = (float)y;
    r->z = (float)z;
    r->w = (float)w;
    return r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00376C10);
#ifdef SKIP_ASM
extern "C" float func_00376C10(void* self)
{
    int i = *(int*)((char*)self + 0x10dc);
    char* p = (char*)self + i * 0x230;
    return *(float*)(p + 0x6d38);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00376C28);
#ifdef SKIP_ASM
struct sPartEmitter {
    char pad[0x10];
    float x;
    float y;
    float z;
    char pad2[0x230 - 0x1C];
};

struct sPartSys {
    char pad[0x10dc];
    int cur;
    char pad2[0x6d20 - 0x10e0];
    sPartEmitter emitters[1];
};

extern "C" void func_00376C28(sPartSys* self, float* a, float* b, float* c)
{
    sPartEmitter* e = &self->emitters[self->cur];
    *a = e->z;
    *b = e->x;
    *c = e->y;
}
#endif

INCLUDE_ASM("render/particle", func_00376C58);

//100%
INCLUDE_ASM("render/particle", func_00377278);
#ifdef SKIP_ASM
struct sPt7278 {
    float x, y, z, w;
    sPt7278() {}
    sPt7278(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sMat7278 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPtView7278 {
    char pad_0x0[0x1C];
    float depth;                    // 0x1C
    char pad_0x20[0x210];
};

struct sPtCam7278 {
    char pad_0x0[0x8];
    float x;                        // 0x8
    char pad_0xC[0xC];
    float y;                        // 0x18
    char pad_0x1C[0xC];
    float z;                        // 0x28
};

struct sPtGfx7278 {
    char pad_0x0[0x10DC];
    int curView;                    // 0x10DC
    char pad_0x10E0[0x13E4 - 0x10E0];
    sPtCam7278* cam;                // 0x13E4
    char pad_0x13E8[0x5858 - 0x13E8];
    float f5858;                    // 0x5858
    char pad_0x585C[0x58A0 - 0x585C];
    sMat7278 m58A0;                 // 0x58A0
    char pad_0x58E0[0x8];
    float depthScale;               // 0x58E8
    char pad_0x58EC[0xC];
    float f58F8;                    // 0x58F8
    char pad_0x58FC[0x5A40 - 0x58FC];
    int mode;                       // 0x5A40
    char pad_0x5A44[0x6B90 - 0x5A44];
    int texReady;                   // 0x6B90
    char pad_0x6B94[0x6D20 - 0x6B94];
    sPtView7278 views[1];           // 0x6D20
};

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector); the PC port needs a C fallback.
static inline sPt7278 MulMat7278(const sMat7278* m, const sPt7278& v)
{
    sPt7278 r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector * scalar); the PC port needs a C fallback.
static inline sPt7278 Scale7278(const sPt7278& v, float s)
{
    sPt7278 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add); the PC port needs a C fallback.
static inline sPt7278 Add7278(const sPt7278& a, const sPt7278& b)
{
    sPt7278 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

extern "C" void func_0037D968(void* self);

static inline float DepthOffset7278(sPtGfx7278* self, sPt7278* pos, float dist)
{
    if (dist != 0.0f) {
    sPt7278 dir(self->cam->x, self->cam->y, self->cam->z, 0.0f);
    sPt7278 a = MulMat7278(&self->m58A0, *pos);
    sPt7278 c = MulMat7278(&self->m58A0, Add7278(*pos, Scale7278(dir, dist)));
    float za = a.z / a.w;
    float zc = c.z / c.w;
    if (-1.0f <= za && za <= 1.0f && -1.0f <= zc && zc <= 1.0f) {
        return self->depthScale * (zc - za);
    }
    }
    return 0.0f;
}

extern "C" void func_00377278(sPtGfx7278* self, sPt7278* pos, float dist)
{
    sPtView7278* v = &self->views[self->curView];
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    float d = DepthOffset7278(self, pos, dist);
    if (d != v->depth) {
        v->depth = d;
        float k = 32767.5f;
        if (self->mode == 0x31) {
            k = 8388467.5f;
        }
        self->f58F8 = k + d;
        self->f5858 = k + v->depth;
        self->texReady = 0;
    }
}
#endif

INCLUDE_ASM("render/particle", func_00377458);

//100%
INCLUDE_ASM("render/particle", func_00377950);
#ifdef SKIP_ASM
extern "C" void func_00377950(void* self, int mode)
{
    *(int*)((char*)self + 0x6b94) = mode;
    switch (mode) {
    case 0:
        *(float*)((char*)self + 0x6b98) = 0.0f;
        *(float*)((char*)self + 0x6b9c) = 1.0f;
        *(float*)((char*)self + 0x6ba0) = 1.0f;
        *(float*)((char*)self + 0x6ba4) = 1.0f;
        break;
    case 1:
        *(float*)((char*)self + 0x6b98) = 0.125f;
        *(float*)((char*)self + 0x6b9c) = 0.75f;
        *(float*)((char*)self + 0x6ba0) = 0.75f;
        *(float*)((char*)self + 0x6ba4) = 0.75f;
        break;
    case 2:
        *(float*)((char*)self + 0x6ba0) = 0.75f;
        *(float*)((char*)self + 0x6b98) = 0.0f;
        *(float*)((char*)self + 0x6b9c) = 1.0f;
        *(float*)((char*)self + 0x6ba4) = 1.0f;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003779E0);
#ifdef SKIP_ASM
struct sPart20 {
    int v[5];
};

extern "C" void func_003779E0(void* self, sPart20* src)
{
    *(sPart20*)((char*)self + 0x6b94) = *src;
}
#endif

INCLUDE_ASM("render/particle", func_00377A10);

INCLUDE_ASM("render/particle", func_00377CF0);

INCLUDE_ASM("render/particle", func_003781A0);

INCLUDE_ASM("render/particle", func_00378808);

INCLUDE_ASM("render/particle", func_00379028);

INCLUDE_ASM("render/particle", func_00379860);

INCLUDE_ASM("render/particle", func_00379BD0);

INCLUDE_ASM("render/particle", func_0037A260);

//100%
INCLUDE_ASM("render/particle", func_0037A430);
#ifdef SKIP_ASM
struct sPtRS_A430 {
    int f0;                         // bits 6..9 = layer
    int f4;
    int f8;                         // bits 0..4 = key
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_A430 {
    sPtRS_A430 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_A430 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_A430 ents[1];            // 0x80
};

struct sPtGfx_A430 {
    char pad_0x0[0xE84];
    sPtRS_A430* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_A430* ring;             // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x5A28 - 0x5A04];
    unsigned int pendBuf;           // 0x5A28
    unsigned long* pend;            // 0x5A2C
};

extern int D_004A4474;
extern "C" unsigned int func_0038F668(int dma, unsigned long* p, int a2);

// PORT: uncached (0x30000000) pointers held in int.
// Flushes the pending packet into a ring entry and resets the render state's layer bits.
extern "C" void func_0037A430(sPtGfx_A430* self)
{
    unsigned int next = func_0038F668(D_004A4474, self->pend, 4);
    self->bufAddr = next;
    unsigned int buf = self->pendBuf;
    sPtRing_A430* ring = self->ring;
    sPtRS_A430* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtEnt_A430* e = (sPtEnt_A430*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    self->bufAddr += 0x10;
    self->top->f0 &= ~0x3C0;
    self->top->fC &= 0xC0000000;
    self->pendBuf = 0;
    self->pend = 0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037A540);
#ifdef SKIP_ASM
struct sPartVEntryI_A540 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sPartVEntryD_A540 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sPartEmitter_A540 {
    int field_0x0;
    void* vt;       // 0x4
};

extern "C" sPartEmitter_A540* func_00385138(void* mem, void* a1, void* a2, void* a3, unsigned int flags);
extern const char D_004928D8[];

extern "C" sPartEmitter_A540* func_0037A540(void* a0, void* a1, void* a2, unsigned int flags)
{
    sPartEmitter_A540* e = func_00385138(cMemMan_alloc(0x1CC, D_004928D8, flags, 0), a1, a2, a0, flags);
    if (flags & 0x40000000) {
        if (e == 0) {
            return 0;
        }
        sPartVEntryI_A540* vt = (sPartVEntryI_A540*)e->vt;
        if (vt[2].fn((char*)e + vt[2].delta) == 0) {
            sPartVEntryD_A540* vt2 = (sPartVEntryD_A540*)e->vt;
            vt2[1].fn((char*)e + vt2[1].delta, 3);
            return 0;
        }
    }
    return e;
}
#endif

INCLUDE_ASM("render/particle", func_0037A610);

INCLUDE_ASM("render/particle", func_0037B548);

INCLUDE_ASM("render/particle", func_0037BA50);

INCLUDE_ASM("render/particle", func_0037BB10);

//100%
INCLUDE_ASM("render/particle", func_0037BC40);
#ifdef SKIP_ASM
// Pages used by a w x h buffer of the given GS pixel format (32-bit pages are 64x32, 16-bit 64x64).
static inline int pages_37BC40(int psm, int bw, int h)
{
    switch (psm) {
    case 0:
    case 1:
    case 48:
    case 49:
        return bw * ((h + 31) >> 5);
    case 2:
    case 10:
    case 50:
    case 58:
        return bw * ((h + 63) >> 6);
    }
    return 0;
}

static inline int zpages_37BC40(int psm, int bw, int h)
{
    switch (psm) {
    case 48:
    case 49:
        return bw * ((h + 31) >> 5);
    case 50:
    case 58:
        return bw * ((h + 63) >> 6);
    }
    return 0;
}

// Size in 256-byte blocks of the frame, texture and z buffers for a w x h screen.
extern "C" int func_0037BC40(void* self, int w, int h, int fbPsm, int texPsm, int zPsm)
{
    int bw = (w + 63) >> 6;
    int fb = pages_37BC40(fbPsm, bw, h);
    int tex = pages_37BC40(texPsm, bw, h);
    int z = zpages_37BC40(zPsm, bw, h);
    return (fb + tex + z) << 5;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037BD38);
#ifdef SKIP_ASM
extern "C" int func_0037BD38(void* self, int a, int b)
{
    switch (a) {
    case 0:
    case 1:
    case 10:
    case '0':
    case '1':
    case ':':
        if (b == '0' || b == '1' || b == ':') {
            return 1;
        }
        break;
    case 2:
    case '2':
        if (b == '2') {
            return 1;
        }
        break;
    }
    return 0;
}
#endif

INCLUDE_ASM("render/particle", func_0037BD98);

//100%
INCLUDE_ASM("render/particle", func_0037C198);
#ifdef SKIP_ASM
struct sPtBits_C198 {
    unsigned long f0 : 3;
    unsigned long g0 : 1;
    unsigned long f1 : 3;
    unsigned long g1 : 1;
    unsigned long f2 : 3;
    unsigned long g2 : 1;
    unsigned long f3 : 3;
    unsigned long g3 : 1;
    unsigned long f4 : 3;
    unsigned long g4 : 1;
    unsigned long f5 : 3;
    unsigned long g5 : 1;
    unsigned long f6 : 3;
    unsigned long g6 : 1;
    unsigned long f7 : 3;
    unsigned long g7 : 1;
    unsigned long f8 : 3;
    unsigned long g8 : 1;
    unsigned long f9 : 3;
    unsigned long g9 : 1;
    unsigned long f10 : 3;
    unsigned long g10 : 1;
    unsigned long f11 : 3;
    unsigned long g11 : 1;
    unsigned long f12 : 3;
    unsigned long g12 : 1;
    unsigned long f13 : 3;
    unsigned long g13 : 1;
    unsigned long f14 : 3;
    unsigned long g14 : 1;
    unsigned long f15 : 3;
    unsigned long g15 : 1;
};

struct sPtGfx_C198 {
    char pad_0x0[0x59E0];
    sPtBits_C198 bits;              // 0x59E0
};

// PORT: 64-bit `long` bitfields (the GS-style register word).
extern "C" void func_0037C198(sPtGfx_C198* self, int* src)
{
    self->bits.f0 = src[0];
    self->bits.f1 = src[1];
    self->bits.f2 = src[2];
    self->bits.f3 = src[3];
    self->bits.f4 = src[4];
    self->bits.f5 = src[5];
    self->bits.f6 = src[6];
    self->bits.f7 = src[7];
    self->bits.f8 = src[8];
    self->bits.f9 = src[9];
    self->bits.f10 = src[10];
    self->bits.f11 = src[11];
    self->bits.f12 = src[12];
    self->bits.f13 = src[13];
    self->bits.f14 = src[14];
    self->bits.f15 = src[15];
    self->bits.g0 = 0;
    self->bits.g1 = 0;
    self->bits.g2 = 0;
    self->bits.g3 = 0;
    self->bits.g4 = 0;
    self->bits.g5 = 0;
    self->bits.g6 = 0;
    self->bits.g7 = 0;
    self->bits.g8 = 0;
    self->bits.g9 = 0;
    self->bits.g10 = 0;
    self->bits.g11 = 0;
    self->bits.g12 = 0;
    self->bits.g13 = 0;
    self->bits.g14 = 0;
    self->bits.g15 = 0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C570);
#ifdef SKIP_ASM
extern "C" int func_004139F8(float f);

// PORT: g++ `<?` (min) operator; needs a macro / std::min on a modern compiler.
static inline float clamp_C570(float x, float hi)
{
    return x >= 0.0f ? (x <? hi) : 0.0f;
}

struct sPartColour_C570 {
    float r, g, b;
};

extern "C" void func_0037C570(void* self, sPartColour_C570* c)
{
    float one = 1.0f;
    *(int*)((char*)self + 0x59EC) = func_004139F8(clamp_C570(c->r, one) * 128.0f);
    *(int*)((char*)self + 0x59F0) = func_004139F8(clamp_C570(c->g, one) * 128.0f);
    *(int*)((char*)self + 0x59F4) = func_004139F8(clamp_C570(c->b, one) * 128.0f);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C720);
#ifdef SKIP_ASM
// PORT: g++ `<?` (min) operator; needs a macro / std::min on a modern compiler.
static inline float clamp_C720(float x, float hi)
{
    return x >= 0.0f ? (x <? hi) : 0.0f;
}

// Stores the inverted alpha (1 - clamped a) as a 0..128 value.
extern "C" void func_0037C720(void* self, float a)
{
    *(int*)((char*)self + 0x59F8) = func_004139F8((1.0f - clamp_C720(a, 1.0f)) * 128.0f);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C7C0);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);
void func_00366FE0(void* p, int a1);

extern "C" void func_0037C7C0(void* self, int a1)
{
    func_003E6448((char*)self + 0x3838, 0, 0x1F40);
    func_00366FE0(*(void**)((char*)self + 0x18F4), a1);
}
#endif

extern "C" void* func_003E6574(void*, void*, int);

//100%
INCLUDE_ASM("render/particle", func_0037C808__FPv);
#ifdef SKIP_ASM
void* func_0037C808(void* self)
{
    return func_003E6574((char*)self + 0x18f8, (char*)self + 0x3838, 0x1f40);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C830);
#ifdef SKIP_ASM
struct sVEntry0037C830 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0037C830(void* self)
{
    int i;
    for (i = 0; i < 2000; i++) {
        if (((int*)((char*)self + 0x18F8))[i] != 0) {
            sVEntry0037C830* vt = *(sVEntry0037C830**)((char*)self + 0x10D8);
            vt[50].fn((char*)self + vt[50].delta, i);
        }
    }
}
#endif

// declared by mangled name so we can call it with a single argument, the way
// the target does (its real signature takes a second arg the caller leaves set)
extern "C" void func_00366FE0__FPvi(void*);

//100%
INCLUDE_ASM("render/particle", func_0037C8A0);
#ifdef SKIP_ASM
extern "C" void func_0037C8A0(void* self)
{
    func_00366FE0__FPvi(*(void**)((char*)self + 0x18f4));
}
#endif

INCLUDE_ASM("render/particle", func_0037C8C0);

//100%
INCLUDE_ASM("render/particle", func_0037CAF8);
#ifdef SKIP_ASM
extern "C" int func_00367440(void* mgr, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                             int a8, int a9, int a10, int a11);

extern "C" int func_0037CAF8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                              int a8, int a9, int a10, int a11)
{
    int i = func_00367440(*(void**)((char*)self + 0x18F4), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    *(int*)((char*)self + (i << 2) + 0x3838) = 1;
    return i;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037CB50);
#ifdef SKIP_ASM
extern "C" void func_00367BC0(void* tbl, int idx);

extern "C" void func_0037CB50(void* self, int idx)
{
    func_00367BC0(*(void**)((char*)self + 0x18F4), idx);
    *(int*)((char*)self + (idx << 2) + 0x18F8) = 0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037CB90);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` bitfield (GS TEX0 register layout)
struct sGsTex0 {
    ulong TBP0 : 14;
    ulong TBW : 6;
    ulong PSM : 6;
    ulong TW : 4;
    ulong TH : 4;
    ulong TCC : 1;
    ulong TFX : 2;
    ulong CBP : 14;
    ulong CPSM : 4;
    ulong CSM : 1;
    ulong CSA : 5;
    ulong CLD : 3;
};

struct sPartTex {
    char pad[0x38];
    sGsTex0 tex0;
};

struct sPartTexTable {
    int pad[2];
    sPartTex* entries[2000];
};

extern "C" int func_0037CB90(void* self, int idx)
{
    sPartTexTable* t = *(sPartTexTable**)((char*)self + 0x18f4);
    int r;
    if (idx >= 0) {
        if (idx < 2000) {
            r = t->entries[idx] != 0;
        } else {
            r = 0;
        }
    } else {
        r = 1;
    }
    return r;
}
#endif

extern "C" void* func_003691B0(int);

//100%
INCLUDE_ASM("render/particle", func_0037CBC8__FPv);
#ifdef SKIP_ASM
void* func_0037CBC8(void* self)
{
    return func_003691B0(*(int*)((char*)self + 0x18f4));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037CBE8);
#ifdef SKIP_ASM
struct sPartVEntry52 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int);
};

extern "C" void func_0037CBE8(void* self, void* out, int a2, int a3)
{
    sPartVEntry52* vt = *(sPartVEntry52**)((char*)self + 0x10D8);
    *(int*)((char*)out + 4) = vt[52].fn((char*)self + vt[52].delta, a2, a3, 0);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037CC30);
#ifdef SKIP_ASM
struct sVEntry0037CC30 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00367B60(void* mgr, int id);

extern "C" void func_0037CC30(void* self, void* item)
{
    if (*(int*)((char*)item + 0x4) != -1) {
        func_00367B60(*(void**)((char*)self + 0x18F4), *(int*)((char*)item + 0x4));
        sVEntry0037CC30* vt = *(sVEntry0037CC30**)((char*)self + 0x10D8);
        vt[50].fn((char*)self + vt[50].delta, *(int*)((char*)item + 0x4));
        *(int*)((char*)item + 0x4) = -1;
    }
}
#endif

INCLUDE_ASM("render/particle", func_0037CC98);

extern "C" void* func_00369130(int);

//100%
INCLUDE_ASM("render/particle", func_0037D090__FPv);
#ifdef SKIP_ASM
void* func_0037D090(void* self)
{
    return func_00369130(*(int*)((char*)self + 0x18f4));
}
#endif

INCLUDE_ASM("render/particle", func_0037D0B0);

//100%
INCLUDE_ASM("render/particle", func_0037D318);
#ifdef SKIP_ASM
extern "C" void func_00367D20(void* gm, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

extern "C" void func_0037D318(char* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    func_00367D20(*(void**)(self + 0x18F4), a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D348);
#ifdef SKIP_ASM
struct sPtRS_D348 {
    int f0;
    int f4;
    int f8;                         // bits 0..4 = key
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_D348 {
    sPtRS_D348 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_D348 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_D348 ents[1];            // 0x80
};

struct sPtGfx_D348 {
    char pad_0x0[0xE84];
    sPtRS_D348* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_D348* ring;             // 0x18F0
    void* texset;                   // 0x18F4
    char pad_0x18F8[0x5A00 - 0x18F8];
    unsigned int bufAddr;           // 0x5A00
};

extern "C" void func_00367DB8_D348(void* texset, int idx, unsigned int* buf) __asm__("func_00367DB8");

// PORT: uncached (0x30000000) pointers held in int.
// Uploads texture idx into the uncached buffer and queues a ring entry for it.
extern "C" int func_0037D348(sPtGfx_D348* self, int idx)
{
    unsigned int buf = self->bufAddr;
    unsigned int p = buf | 0x30000000;
    func_00367DB8_D348(self->texset, idx, &p);
    unsigned int next = p & 0x0FFFFFFF;
    self->bufAddr = next;
    sPtRing_D348* ring = self->ring;
    sPtRS_D348* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtEnt_D348* e = (sPtEnt_D348*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    self->bufAddr += 0x10;
    return 1;
}
#endif

INCLUDE_ASM("render/particle", func_0037D450);

extern "C" void* func_00367CD0(int);

//100%
INCLUDE_ASM("render/particle", func_0037D738__FPv);
#ifdef SKIP_ASM
void* func_0037D738(void* self)
{
    return func_00367CD0(*(int*)((char*)self + 0x18f4));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D758);
#ifdef SKIP_ASM
struct sPartQ16 {
    int w[4];
} __attribute__((aligned(16)));

struct sPartMtx {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPartDrawEntry {
    sPartQ16 q;          // 0x00
    sPartMtx m0;         // 0x10
    sPartMtx m1;         // 0x50
    float f;             // 0x90
    int i;               // 0x94
};

struct sPartDrawList {
    char pad_0x0[0x13EC];
    int count;                    // 0x13EC
    sPartDrawEntry entries[1];    // 0x13F0
};

// PORT: PS2-only VU0 asm (lqc2/sqc2 4x4 matrix copy).
static inline void vu0CopyMtxP(sPartMtx* dst, sPartMtx* src)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "sqc2      $vf1, 0x0(%1)\n"
        "sqc2      $vf2, 0x10(%1)\n"
        "sqc2      $vf3, 0x20(%1)\n"
        "sqc2      $vf4, 0x30(%1)\n"
        :
        : "r"(src), "r"(dst)
        : "memory");
}

extern "C" void func_0037D758(sPartDrawList* self, sPartQ16* q, sPartMtx* m0, sPartMtx* m1, float f, int i)
{
    self->entries[self->count].q = *q;
    vu0CopyMtxP(&self->entries[self->count].m0, m0);
    vu0CopyMtxP(&self->entries[self->count].m1, m1);
    self->entries[self->count].f = f;
    self->entries[self->count].i = i;
    self->count++;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D800);
#ifdef SKIP_ASM
struct sPtRS_D800 {
    int f0;
    int f4;
    int f8;                         // bits 0..4 = key
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_D800 {
    sPtRS_D800 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_D800 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_D800 ents[1];            // 0x80
};

struct sPtGfx_D800 {
    char pad_0x0[0xE84];
    sPtRS_D800* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_D800* ring;             // 0x18F0
    void* texset;                   // 0x18F4
    char pad_0x18F8[0x5A00 - 0x18F8];
    unsigned int bufAddr;           // 0x5A00
};

extern "C" void func_00367F18_D800(void* texset, int idx, float* color, unsigned int* buf) __asm__("func_00367F18");

// Release-build assert: expands to an empty do { } while (0); its loop notes keep the target's scheduling.
#define ASSERT_D800(cond) do { } while (0)

// PORT: uncached (0x30000000) pointers held in int.
// Like func_0037D348 for the two-argument upload; the queued entry is flagged.
extern "C" void func_0037D800(sPtGfx_D800* self, int idx, float* color)
{
    unsigned int buf = self->bufAddr;
    unsigned int p = buf | 0x30000000;
    func_00367F18_D800(self->texset, idx, color, &p);
    unsigned int next = p & 0x0FFFFFFF;
    self->bufAddr = next;
    sPtRing_D800* ring = self->ring;
    sPtRS_D800* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtEnt_D800* e = (sPtEnt_D800*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        ASSERT_D800(e != 0);
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 1;
    }
    self->bufAddr += 0x10;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D908);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` bitfield (GS TEX0 register layout)
extern "C" int func_0037D908(void* self, int idx)
{
    sPartTexTable* t = *(sPartTexTable**)((char*)self + 0x18f4);
    return 1 << t->entries[idx]->tex0.TW;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D938);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` bitfield (GS TEX0 register layout)
extern "C" int func_0037D938(void* self, int idx)
{
    sPartTexTable* t = *(sPartTexTable**)((char*)self + 0x18f4);
    return 1 << t->entries[idx]->tex0.TH;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D968);
#ifdef SKIP_ASM
struct sMat_D968 {
    float m[4][4];
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMat_D968(sMat_D968* d, const sMat_D968* a, const sMat_D968* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0CopyMat_D968(sMat_D968* d, const sMat_D968* s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

extern "C" void func_003645B8(void* ring, sMat_D968* m);

extern "C" void func_0037D968(void* selfp)
{
    char* self = (char*)selfp;
    *(int*)(self + 0x6B90) = 1;
    sMat_D968 t2;
    sMat_D968 t;
    vu0MulMat_D968(&t, (sMat_D968*)(self + 0x6AF0), *(sMat_D968**)(self + 0x13E4));
    vu0CopyMat_D968(&t2, &t);
    vu0CopyMat_D968((sMat_D968*)(self + 0x6B30), &t2);
    vu0CopyMat_D968((sMat_D968*)(self + 0x5780), *(sMat_D968**)(self + 0x13E4));
    vu0MulMat_D968(&t, (sMat_D968*)(self + 0x57C0), (sMat_D968*)(self + 0x5780));
    vu0CopyMat_D968(&t2, &t);
    vu0CopyMat_D968((sMat_D968*)(self + 0x5800), &t2);
    vu0MulMat_D968(&t, (sMat_D968*)(self + 0x5860), (sMat_D968*)(self + 0x5780));
    vu0CopyMat_D968(&t2, &t);
    vu0CopyMat_D968((sMat_D968*)(self + 0x58A0), &t2);
    func_003645B8(*(void**)(self + 0x18F0), (sMat_D968*)(self + 0x5780));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037DBE8);
#ifdef SKIP_ASM
struct sPtVecDBE8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPtMtxDBE8 {
    sPtVecDBE8 r[4];
};

struct sPtGfxDBE8 {
    char pad_0x0[0x6B30];
    sPtMtxDBE8 clipMtx;         // 0x6B30
    float minX;                 // 0x6B70
    float minY;                 // 0x6B74
    float maxZ;                 // 0x6B78
    float field_0x6B7C;
    float maxX;                 // 0x6B80
    float maxY;                 // 0x6B84
    float minZ;                 // 0x6B88
    float field_0x6B8C;
    int clipValid;              // 0x6B90
};

extern "C" void func_0037D968(void* self);

// PORT: PS2-only VU0 inline asm (matrix * vector).
static inline sPtVecDBE8 mtxApplyDBE8(sPtMtxDBE8* m, const sPtVecDBE8& v)
{
    sPtVecDBE8 out;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf8, %1\n"
        "lqc2      $vf4, 0x0(%2)\n"
        "lqc2      $vf5, 0x10(%2)\n"
        "lqc2      $vf6, 0x20(%2)\n"
        "lqc2      $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        ".set pop\n"
        : "=m"(out)
        : "m"(v), "r"(m)
        : "memory");
    return out;
}

extern "C" int func_0037DBE8(sPtGfxDBE8* self, const sPtVecDBE8* p)
{
    if (self->clipValid == 0) {
        func_0037D968(self);
    }
    sPtVecDBE8 v = mtxApplyDBE8(&self->clipMtx, *p);
    int code = 0;
    float w = 1.0f / v.w;
    v.x *= w;
    v.y *= w;
    v.w = w;
    if (v.x < self->minX) {
        code |= 2;
    }
    if (self->maxX < v.x) {
        code |= 1;
    }
    if (v.y < self->minY) {
        code |= 8;
    }
    if (self->maxY < v.y) {
        code |= 4;
    }
    float z = v.z;
    if (w < 0.0f) {
        code ^= 0x2F;
    } else {
        if (self->maxZ < z) {
            code |= 0x20;
        }
        if (z < self->minZ) {
            code |= 0x10;
        }
    }
    return code;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037DD20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPtVecDD20 {
    float x, y, z, w;
    float& X() { return x; }
    float& Y() { return y; }
    float& Z() { return z; }
} __attribute__((aligned(16)));

struct sPtGfxDD20 {
    char pad_0x0[0x5A30];
    unsigned int width;         // 0x5A30
    unsigned int height;        // 0x5A34
    char pad_0x5A38[0x6B90 - 0x5A38];
    int clipValid;              // 0x6B90
};

// func_0037DEE0 is defined later in this unit with its own vector type; bind a view.
extern "C" sPtVecDD20 func_0037DEE0_DD20(void* self, const sPtVecDD20* p) __asm__("func_0037DEE0");

static inline int clampDD20(int n)
{
    int hi = 0xFFFFFF;
    int r;
    if (n >= 0) {
        r = n;
        if (r > hi) {
            r = hi;
        }
    } else {
        r = 0;
    }
    return r;
}

extern "C" sPtVecDD20 func_0037DD20(sPtGfxDD20* self, const sPtVecDD20* p)
{
    if (self->clipValid == 0) {
        func_0037D968(self);
    }
    sPtVecDD20 v = func_0037DEE0_DD20(self, p);
    v.X() = (float)(int)(v.X() - (2048.0f - (float)(self->width >> 1)));
    v.Y() = (float)(int)(v.Y() - (2048.0f - (float)(self->height >> 1)));
    v.Z() = (float)clampDD20((int)v.Z());
    return v;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037DE88);
#ifdef SKIP_ASM
// VU0 microprogram entry (micro-memory address 0x570; resolved via undefined_syms_auto.txt)
extern char D_570[];

// PORT: PS2-only VU0 microprogram call (lqc2/ctc2/vcallmsr/cfc2); the PC port needs a C
// version of the microprogram.
extern "C" int func_0037DE88(void* self, void* a, void* b, void* m)
{
    int r1;
    int r2;
    __asm__ __volatile__(
        "lqc2      $vf15, 0x0(%2)\n"
        "lqc2      $vf16, 0x0(%3)\n"
        "lqc2      $vf10, 0x0(%4)\n"
        "lqc2      $vf11, 0x10(%4)\n"
        "lqc2      $vf12, 0x20(%4)\n"
        "lqc2      $vf13, 0x30(%4)\n"
        "ctc2.ni   %5, $vi27\n"
        "vnop\n"
        "vnop\n"
        "vcallmsr  $vi27\n"
        "cfc2.i    %0, $vi1\n"
        "cfc2.ni   %1, $vi2\n"
        : "=r"(r1), "=r"(r2)
        : "r"(a), "r"(b), "r"(m), "r"((unsigned int)D_570 >> 3));
    if (r2 != 0) {
        return 1;
    }
    if (r1 != 0) {
        return 2;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037DEE0);
#ifdef SKIP_ASM
struct sPartQVec {
    float x, y, z, w;
} __attribute__((aligned(16)));

// Transforms v by the 4x4 matrix at self+0x58A0, divides by w, then scales by the
// vector at self+0x58E0 and adds the one at self+0x58F0.
// PORT: PS2-only VU0 macro-mode asm; the PC port needs a C version.
extern "C" sPartQVec func_0037DEE0(void* self, sPartQVec* v)
{
    sPartQVec r;
    __asm__ __volatile__(
        "lqc2      $vf10, 0x0(%1)\n"
        "lqc2      $vf1, 0x0(%2)\n"
        "lqc2      $vf2, 0x10(%2)\n"
        "lqc2      $vf3, 0x20(%2)\n"
        "lqc2      $vf4, 0x30(%2)\n"
        "lqc2      $vf5, %3\n"
        "lqc2      $vf6, %4\n"
        "vmulax.xyzw  ACC, $vf1, $vf10x\n"
        "vmadday.xyzw ACC, $vf2, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf10z\n"
        "vmaddw.xyzw  $vf11, $vf4, $vf10w\n"
        "vdiv      Q, $vf0w, $vf11w\n"
        "vwaitq\n"
        "vmulq.xyzw   $vf12, $vf11, Q\n"
        "vmula.xyzw   ACC, $vf5, $vf12\n"
        "vmaddw.xyzw  $vf13, $vf6, $vf0w\n"
        "sqc2      $vf13, %0\n"
        : "=m"(r)
        : "r"(v), "r"((char*)self + 0x58A0),
          "m"(*(sPartQVec*)((char*)self + 0x58E0)),
          "m"(*(sPartQVec*)((char*)self + 0x58F0)));
    return r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037DF88);
#ifdef SKIP_ASM
struct sPartVEntry_DF88 {
    short delta;
    short index;
    int (*fn)(void*, void*, void*, void*);
};

struct sPartItem_DF88 {
    char data[0xA0];
};

struct sPartSys_DF88 {
    char pad_0x0[0x10D8];
    sPartVEntry_DF88* vt;       // 0x10D8
    char pad_0x10dc[0x310];
    unsigned int count;         // 0x13EC
    char pad_0x13f0[0x10];
    sPartItem_DF88 items[1];    // 0x1400
};

extern "C" unsigned int func_0037DF88(sPartSys_DF88* self, void* a1, void* a2)
{
    unsigned int mask = 0;
    for (unsigned int i = 0; i < self->count; i++) {
        sPartVEntry_DF88* e = &self->vt[93];
        if (e->fn((char*)self + e->delta, a1, a2, &self->items[i]) != 1) {
            mask |= 1 << i;
        }
    }
    return mask;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037E040);
#ifdef SKIP_ASM
// PORT: 128-bit GPR quadword (TImode); the PC port needs a 16-byte struct.
typedef int cPartQuad128 __attribute__((mode(TI)));

// Appends a DMA cnt tag (qwc 5) plus a VIF UNPACK V4-32 header and the 4x4 matrix m
// to the packet at *pp.
// PORT: 64-bit `ulong` packet words and PS2-only VU0 asm (lqc2/sqc2 copy).
extern "C" void func_0037E040(void* m, char** pp)
{
    char* p = *pp;
    *(cPartQuad128*)p = 0x10000005;
    *(ulong*)(p + 0x18) = (ulong)0x6C048005 << 32;
    *(ulong*)(p + 0x10) = 0;
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "sqc2      $vf1, 0x0(%1)\n"
        "sqc2      $vf2, 0x10(%1)\n"
        "sqc2      $vf3, 0x20(%1)\n"
        "sqc2      $vf4, 0x30(%1)\n"
        :
        : "r"(m), "r"(p + 0x20)
        : "memory");
    *pp = p + 0x60;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037E098);
#ifdef SKIP_ASM
struct sPartPktQuad {
    int w[4];
} __attribute__((aligned(16)));

// PORT: 64-bit `ulong` packet words.
extern "C" void func_0037E098(sPartPktQuad* src, void* self, sPartPktQuad* hdr, char** pp)
{
    char* p = *pp;
    int i;
    *(ulong*)(p + 0x0) = 0x1000000F;
    *(ulong*)(p + 0x8) = 0;
    *(ulong*)(p + 0x10) = 0;
    *(ulong*)(p + 0x18) = (ulong)0x6C038009 << 32;
    ((sPartPktQuad*)(p + 0x20))[0] = hdr[0];
    ((sPartPktQuad*)(p + 0x20))[1] = hdr[1];
    ((sPartPktQuad*)(p + 0x20))[2] = hdr[2];
    *(ulong*)(p + 0x50) = 0;
    *(ulong*)(p + 0x58) = (ulong)0x6C0A800F << 32;
    p += 0x60;
    for (i = 0; i < 10; i++) {
        ((sPartPktQuad*)p)[i] = src[i];
    }
    p += 0xA0;
    *pp = p;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037E120);
#ifdef SKIP_ASM
// Appends a DMA cnt tag (qwc 6), a VIF header and the 4x4 matrix m to the packet at *pp,
// then the optional sub-packets.
// PORT: 64-bit `ulong` packet words and PS2-only VU0 asm (lqc2/sqc2 copy).
extern "C" void func_0037E120(void* self, sPartPktQuad* m, sPartPktQuad* hdr, int a3, void* m2,
                              sPartPktQuad* src, int flags, char** pp)
{
    char* p = *pp;
    *(cPartQuad128*)p = 0x10000006;
    *(ulong*)(p + 0x10) = 0x20000000;
    *(ulong*)(p + 0x18) = 0x6C05800001000101;
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "sqc2      $vf1, 0x0(%1)\n"
        "sqc2      $vf2, 0x10(%1)\n"
        "sqc2      $vf3, 0x20(%1)\n"
        "sqc2      $vf4, 0x30(%1)\n"
        :
        : "r"(m), "r"(p + 0x20)
        : "memory");
    *(ulong*)(p + 0x60) = 0;
    *(ulong*)(p + 0x68) = (ulong)flags << 32;
    p += 0x70;
    if (m2 != 0) {
        func_0037E040(m2, &p);
    }
    if (flags & 1) {
        sPartPktQuad t = m[3];
        func_0037E098(src, &t, hdr, &p);
    }
    *pp = p;
}
#endif

INCLUDE_ASM("render/particle", func_0037E238);

//100%
INCLUDE_ASM("render/particle", func_00380380);
#ifdef SKIP_ASM
struct sV3_0380 {
    float x, y, z;
};

struct sCol0380 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short a : 1;
};

struct sEnt0380 {
    int f0;
    char* node;
    int f8;
    int fC;
};

struct sMdl0380 {
    char pad_0x0[0x8];
    sEnt0380* ents;         // 0x8
    char pad_0xC[0xC];
    sV3_0380 scale;         // 0x18
    int dataOff;            // 0x24
};

extern "C" void func_00380380(void* self, char* obj, int idx, float* pos, float* uv, float* col)
{
    sMdl0380* mdl = *(sMdl0380**)(obj + 0x80);
    char* base = *(char**)(*(char**)(*(char**)(mdl->ents[idx].node + 0x20)) + 0x4);
    char* data = *(char**)(base + mdl->dataOff + 0x4);
    short* t = (short*)(data + 0x80);
    short* p = (short*)(data + 0xA0);
    sCol0380* c = (sCol0380*)(*(char**)(base + *(int*)(obj + 0x98) + 0x14) + 0x10);
    sV3_0380 k;
    sV3_0380 s = mdl->scale;
    k.x = s.x * 3.0518509447574615e-05f;
    k.y = s.y * 3.0518509447574615e-05f;
    k.z = s.z * 3.0518509447574615e-05f;
    int i;
    for (i = 0; i < 4; i++) {
        pos[i * 3 + 0] = (float)p[0] * k.x;
        pos[i * 3 + 1] = (float)p[1] * k.y;
        pos[i * 3 + 2] = (float)p[2] * k.z;
        p += 3;
        uv[i * 2 + 0] = (float)t[0] * 0.000244140625f;
        uv[i * 2 + 1] = (float)t[1] * 0.000244140625f;
        t += 2;
        col[1] = (float)c->r * 0.032258063554763794f;
        col[2] = (float)c->g * 0.032258063554763794f;
        col[3] = (float)c->b * 0.032258063554763794f;
        col[0] = (float)c->a;
        c++;
        col += 4;
    }
}
#endif

INCLUDE_ASM("render/particle", func_00380518);

//100%
INCLUDE_ASM("render/particle", func_003807A0);
#ifdef SKIP_ASM
struct sPtRS_07A0 {
    int f0;
    int f4;
    int f8;
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_07A0 {
    sPtRS_07A0 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_07A0 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_07A0 ents[1];            // 0x80
};

struct sQuad_07A0 {
    unsigned int w[4];
} __attribute__((aligned(16)));

struct sPtGfx_07A0 {
    char pad_0x0[0xE84];
    sPtRS_07A0* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_07A0* ring;             // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x6B90 - 0x5A04];
    int texReady;                   // 0x6B90
};

struct sTrail_07A0 {
    char pad_0x0[0x20];
    sQuad_07A0 q[0x15];             // 0x20
    float scale;                    // 0x170 (unused here)
    char pad_0x174[4];
    int count;                      // 0x178
    int head;                       // 0x17C
    char pad_0x180[0x20];
    sQuad_07A0* posA;               // 0x1A0
    sQuad_07A0* posB;               // 0x1A4
};

struct sHdr_07A0 {
    int seg;
    int step;
    float fstep;
    float v;
} __attribute__((aligned(16)));

extern int D_004A44FC;
extern int D_004A4474;
extern char D_510[];
extern "C" unsigned long* func_0038F460(int dma, unsigned int buf, int a2, int a3);
extern "C" unsigned int func_0038F668(int dma, unsigned long* p, int a2);
extern "C" void func_0037D968(void* self);

static inline int Wrap_07A0(int i, int start, int m)
{
    return (i + start) % m;
}

static inline void CopyQuads_07A0(unsigned long** pp, const void* srcp, int n)
{
    const sQuad_07A0* src = (const sQuad_07A0*)srcp;
    sQuad_07A0* d = (sQuad_07A0*)*pp;
    sQuad_07A0* end = d + n;
    while (d != end) {
        *d++ = *src++;
    }
    *pp = (unsigned long*)d;
}

// PORT: uncached (0x30000000) pointers and VU microprogram addresses held in int; 64-bit GS words are `ulong`.
extern "C" void func_003807A0(sPtGfx_07A0* self, sTrail_07A0* obj)
{
    if (D_004A44FC != 0)
        return;
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0x100;
    self->top->fC &= 0xC0000000;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    int n = obj->count;
    sHdr_07A0 hdr;
    int done = 0;
    hdr.step = *(int*)((char*)obj + 0x20) / n;
    hdr.fstep = (float)hdr.step;
    int nb = n / 64 + 1;
    for (int i = 0; i < nb; i++) {
        unsigned int buf = self->bufAddr;
        unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
        p[0] = 0x1000009A;
        p[1] = 0;
        p[2] = 0;
        p[3] = (unsigned long)0xD931 << 47;
        hdr.v = hdr.fstep * (float)(i * 64) * *(float*)((char*)obj + 0x2C);
        int seg = obj->count - done;
        if (seg >= 0x41)
            seg = 0x40;
        hdr.seg = seg;
        p += 4;
        CopyQuads_07A0(&p, obj->q, 0x15);
        CopyQuads_07A0(&p, &hdr, 1);
        int wrap = obj->head + 1;
        int m = obj->count;
        int s = (done + wrap) % m;
        done += hdr.seg;
        int over = s + hdr.seg - m;
        if (over < 0)
            over = 0;
        int first = s + hdr.seg - s;
        if (m - s < first)
            first = m - s;
        int pad = 0x40 - first - over;
        sQuad_07A0* lastA;
        sQuad_07A0* lastB;
        if (done < m) {
            int e = Wrap_07A0(done, wrap, m);
            lastB = obj->posB + e;
            lastA = obj->posA + e;
        } else {
            int e = Wrap_07A0(done - 1, wrap, m);
            lastB = obj->posB + e;
            lastA = obj->posA + e;
        }
        CopyQuads_07A0(&p, obj->posA + s, first);
        if (over > 0)
            CopyQuads_07A0(&p, obj->posA, over);
        CopyQuads_07A0(&p, lastA, 1);
        p = (unsigned long*)((sQuad_07A0*)p + pad);
        CopyQuads_07A0(&p, obj->posB + s, first);
        if (over > 0)
            CopyQuads_07A0(&p, obj->posB, over);
        CopyQuads_07A0(&p, lastB, 1);
        p = (unsigned long*)((sQuad_07A0*)p + pad);
        p[0] = (unsigned long)(((unsigned int)D_510 >> 3) | 0x14000000) << 32;
        p[1] = (unsigned long)0x8800 << 45;
        p += 2;
        unsigned int next = func_0038F668(D_004A4474, p, 4);
        self->bufAddr = next;
        sPtRing_07A0* ring = self->ring;
        sPtRS_07A0* rs = self->top;
        if (ring->count < 0xA28) {
            rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
            int key = *(int*)((char*)ring + 0x69CC0);
            sPtEnt_07A0* e = (sPtEnt_07A0*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
            e->rs = *rs;
            e->buf = buf;
            e->next = next;
            e->key = key;
            e->flag = 0;
        }
        self->bufAddr += 0x10;
    }
    self->top->f0 &= ~0x3C0;
    self->top->fC &= 0xC0000000;
}
#endif

INCLUDE_ASM("render/particle", func_00380CE0);

INCLUDE_ASM("render/particle", func_00381310);

//100%
INCLUDE_ASM("render/particle", func_003816F0);
#ifdef SKIP_ASM
struct sPtRS_16F0 {
    int f0;                         // bits 6..9 = layer
    int f4;
    int f8;                         // bits 0..4 = key
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_16F0 {
    sPtRS_16F0 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_16F0 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_16F0 ents[1];            // 0x80
};

struct sQuad_16F0 {
    unsigned int w[4];
} __attribute__((aligned(16)));

struct sMat_16F0 {
    float m[4][4];
    sMat_16F0() {}
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
    sMat_16F0(const sMat_16F0& s)
    {
        __asm__ __volatile__(
            "lqc2      $vf1, 0x0(%1)\n"
            "lqc2      $vf2, 0x10(%1)\n"
            "lqc2      $vf3, 0x20(%1)\n"
            "lqc2      $vf4, 0x30(%1)\n"
            "sqc2      $vf1, 0x0(%0)\n"
            "sqc2      $vf2, 0x10(%0)\n"
            "sqc2      $vf3, 0x20(%0)\n"
            "sqc2      $vf4, 0x30(%0)\n"
            :
            : "r"(this), "r"(&s)
            : "memory");
    }
} __attribute__((aligned(16)));

struct sVec4_16F0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPtGfx_16F0 {
    char pad_0x0[0xE84];
    sPtRS_16F0* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_16F0* ring;             // 0x18F0
    char pad_0x18F4[0x5860 - 0x18F4];
    sMat_16F0 m5860;                // 0x5860
    char pad_0x58A0[0x5A00 - 0x58A0];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x6B90 - 0x5A04];
    int texReady;                   // 0x6B90
};

struct sPtObj_16F0 {
    sQuad_16F0 q[5];                // 0x00
    sMat_16F0 mat;                  // 0x50
};

extern int D_004A4474;
extern char D_408[];
extern "C" unsigned long* func_0038F460(int dma, unsigned int buf, int a2, int a3);
extern "C" unsigned int func_0038F668(int dma, unsigned long* p, int a2);
extern "C" void func_0037D968(void* self);

// PORT: PS2-only VU0 inline asm (4x4 matrix product).
static inline sMat_16F0 MulMat_16F0(const sMat_16F0& a, const sMat_16F0& b)
{
    sMat_16F0 d;
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(&d), "r"(&a), "r"(&b)
        : "memory");
    return d;
}

static inline void CopyQuads_16F0(unsigned long** pp, const void* srcp, int n)
{
    const sQuad_16F0* src = (const sQuad_16F0*)srcp;
    sQuad_16F0* d = (sQuad_16F0*)*pp;
    sQuad_16F0* end = d + n;
    while (d != end) {
        *d++ = *src++;
    }
    *pp = (unsigned long*)d;
}

// PORT: uncached (0x30000000) pointers and VU microprogram addresses held in int; 64-bit GS words are `ulong`.
extern "C" void func_003816F0(sPtGfx_16F0* self, sPtObj_16F0* obj)
{
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0x140;
    self->top->fC &= 0xC0000000;
    self->top->f4 = (self->top->f4 & ~3) | 2;
    self->top->f8 &= 0xE00003FF;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    sMat_16F0 m = MulMat_16F0(self->m5860, obj->mat);
    unsigned int buf = self->bufAddr;
    unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
    p[0] = 0x1000000D;
    p[1] = 0;
    p[2] = 0;
    p[3] = (unsigned long)0xD817 << 47;
    p += 4;
    sVec4_16F0 v0;
    v0.x = 0.0f;
    v0.y = 0.0f;
    v0.z = 0.0f;
    v0.w = 0.0f;
    sVec4_16F0 v1;
    v1.x = 1.0f;
    v1.y = 1.0f;
    v1.z = 0.0f;
    v1.w = 0.0f;
    CopyQuads_16F0(&p, (const sQuad_16F0*)&m, 4);
    CopyQuads_16F0(&p, (const sQuad_16F0*)&v0, 1);
    CopyQuads_16F0(&p, (const sQuad_16F0*)&v1, 1);
    CopyQuads_16F0(&p, obj->q, 5);
    p[0] = (unsigned long)(((unsigned int)D_408 >> 3) | 0x14000000) << 32;
    p[1] = (unsigned long)0x8800 << 45;
    p += 2;
    unsigned int next = func_0038F668(D_004A4474, p, 4);
    self->bufAddr = next;
    sPtRing_16F0* ring = self->ring;
    sPtRS_16F0* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtEnt_16F0* e = (sPtEnt_16F0*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    self->bufAddr += 0x10;
    self->top->f4 &= ~3;
    self->top->f8 &= 0xE00003FF;
    self->top->f0 &= ~0x3C0;
    self->top->fC &= 0xC0000000;
}
#endif

INCLUDE_ASM("render/particle", func_00381AD0);

INCLUDE_ASM("render/particle", func_00381F10);

//100%
INCLUDE_ASM("render/particle", func_00382170);
#ifdef SKIP_ASM
struct sPt2170 {
    float x, y, z, w;
    sPt2170() {}
} __attribute__((aligned(16)));

struct sMat2170 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sVtx2170 {
    float s, t, q, pad;     // 0x00
    int r, g, b, a;         // 0x10
    sPt2170 pos;            // 0x20
    sVtx2170() {}
};

struct sRS2170 {
    int field_0x0;
    int flagsA;             // 0x4, bits 2..6 = layer
    int flagsB;             // 0x8
    int field_0xC;
    short tex;              // 0x10
    short pad;
};

struct cRMgr2170 {
    char pad_0x0[0x10D8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual sMat2170* v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73(int n, sVtx2170* v, int f);
};

extern sPt2170 D_004FFBC0[];
extern int D_004A59A0;

// PORT: PS2-only VU0 inline asm (matrix copy); the PC port needs a C fallback.
static inline void CopyMat2170(sMat2170* dst, const sMat2170* src)
{
    __asm__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector); the PC port needs a C fallback.
static inline sPt2170 MulMat2170(const sMat2170* m, const sPt2170& v)
{
    sPt2170 r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector * scalar); the PC port needs a C fallback.
static inline sPt2170 Scale2170(const sPt2170& v, float s)
{
    sPt2170 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add); the PC port needs a C fallback.
static inline sPt2170 Add2170(const sPt2170& a, const sPt2170& b)
{
    sPt2170 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

extern "C" void func_00382170(cRMgr2170* mgr, sPt2170* pos, float* col, float radius, int segs)
{
    char* self = (char*)mgr;
    sMat2170 m;
    int step;
    int i;
    int k;

    CopyMat2170(&m, mgr->v35());
    sPt2170 c = MulMat2170(&m, *pos);
    if (3000.0f < c.z) {
        return;
    }
    if (segs > 0) {
        step = segs;
    } else if (2000.0f < c.z) {
        step = 4;
    } else if (750.0f < c.z) {
        step = 2;
    } else {
        step = 1;
    }
    if (D_004A59A0 == 0) {
        D_004FFBC0[0].x = 0.0f;
        D_004FFBC0[0].y = 1.0f;
        D_004FFBC0[0].z = 0.0f;
        D_004FFBC0[0].w = 0.0f;
        D_004FFBC0[1].x = 0.3799999952316284f;
        D_004FFBC0[1].y = 0.9200000166893005f;
        D_004FFBC0[1].z = 0.0f;
        D_004FFBC0[1].w = 0.0f;
        D_004FFBC0[2].x = 0.7099999785423279f;
        D_004FFBC0[2].y = 0.7099999785423279f;
        D_004FFBC0[2].z = 0.0f;
        D_004FFBC0[2].w = 0.0f;
        D_004FFBC0[3].x = 0.9200000166893005f;
        D_004FFBC0[3].y = 0.3799999952316284f;
        D_004FFBC0[3].z = 0.0f;
        D_004FFBC0[3].w = 0.0f;
        D_004FFBC0[4].x = 1.0f;
        D_004FFBC0[4].y = 0.0f;
        D_004FFBC0[4].z = 0.0f;
        D_004FFBC0[4].w = 0.0f;
        D_004FFBC0[5].x = 0.9200000166893005f;
        D_004FFBC0[5].y = -0.3799999952316284f;
        D_004FFBC0[5].z = 0.0f;
        D_004FFBC0[5].w = 0.0f;
        D_004FFBC0[6].x = 0.7099999785423279f;
        D_004FFBC0[6].y = -0.7099999785423279f;
        D_004FFBC0[6].z = 0.0f;
        D_004FFBC0[6].w = 0.0f;
        D_004FFBC0[7].x = 0.3799999952316284f;
        D_004FFBC0[7].y = -0.9200000166893005f;
        D_004FFBC0[7].z = 0.0f;
        D_004FFBC0[7].w = 0.0f;
        D_004FFBC0[8].x = 0.0f;
        D_004FFBC0[8].y = -1.0f;
        D_004FFBC0[8].z = 0.0f;
        D_004FFBC0[8].w = 0.0f;
        D_004FFBC0[9].x = -0.3799999952316284f;
        D_004FFBC0[9].y = -0.9200000166893005f;
        D_004FFBC0[9].z = 0.0f;
        D_004FFBC0[9].w = 0.0f;
        D_004FFBC0[10].x = -0.7099999785423279f;
        D_004FFBC0[10].y = -0.7099999785423279f;
        D_004FFBC0[10].z = 0.0f;
        D_004FFBC0[10].w = 0.0f;
        D_004FFBC0[11].x = -0.9200000166893005f;
        D_004FFBC0[11].y = -0.3799999952316284f;
        D_004FFBC0[11].z = 0.0f;
        D_004FFBC0[11].w = 0.0f;
        D_004FFBC0[12].x = -1.0f;
        D_004FFBC0[12].y = 0.0f;
        D_004FFBC0[12].z = 0.0f;
        D_004FFBC0[12].w = 0.0f;
        D_004FFBC0[13].x = -0.9200000166893005f;
        D_004FFBC0[13].y = 0.3799999952316284f;
        D_004FFBC0[13].z = 0.0f;
        D_004FFBC0[13].w = 0.0f;
        D_004FFBC0[14].x = -0.7099999785423279f;
        D_004FFBC0[14].y = 0.7099999785423279f;
        D_004FFBC0[14].z = 0.0f;
        D_004FFBC0[14].w = 0.0f;
        D_004FFBC0[15].x = -0.3799999952316284f;
        D_004FFBC0[15].y = 0.9200000166893005f;
        D_004FFBC0[15].z = 0.0f;
        D_004FFBC0[15].w = 0.0f;
        D_004A59A0 = 1;
    }
    (*(sRS2170**)(self + 0xE84))->tex = -1;
    (*(sRS2170**)(self + 0xE84))->flagsA = ((*(sRS2170**)(self + 0xE84))->flagsA & ~0x7C) | 4;
    mgr->v31();
    mgr->v37();

    sVtx2170 verts[17];
    i = 0;
    for (k = 0; k < 16; k += step) {
        verts[i].r = (int)(col[1] * 128.0f);
        verts[i].g = (int)(col[2] * 128.0f);
        verts[i].b = (int)(col[3] * 128.0f);
        verts[i].a = (int)(col[0] * 128.0f);
        sPt2170 p = Add2170(c, Scale2170(D_004FFBC0[k], radius));
        verts[i].pos = p;
        i++;
    }
    verts[i].r = (int)(col[1] * 128.0f);
    verts[i].g = (int)(col[2] * 128.0f);
    verts[i].b = (int)(col[3] * 128.0f);
    verts[i].a = (int)(col[0] * 128.0f);
    sPt2170 p = Add2170(c, Scale2170(D_004FFBC0[0], radius));
    verts[i].pos = p;
    i++;
    mgr->v73(i, verts, 0);
    (*(sRS2170**)(self + 0xE84))->flagsA = ((*(sRS2170**)(self + 0xE84))->flagsA & ~0x7C) | 4;
    mgr->v32();
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003825C0);
#ifdef SKIP_ASM
extern "C" void func_003825F8(void* arg);

extern "C" int func_003825C0(int cause, void* arg)
{
    if (cause != 2) {
        // PORT: PS2-only debug trap (assert).
        __asm__ __volatile__("break 0");
    }
    func_003825F8(arg);
    // PORT: PS2-only: re-enable interrupts (EI).
    __asm__ __volatile__("sync.l\n\tei");
    return 1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003825F8);
#ifdef SKIP_ASM
extern "C" void func_00423DD0(int sema);

extern "C" void func_003825F8(void* self)
{
    int t = ++*(int*)((char*)self + 0x5ABC);
    if (*(int*)((char*)self + 0x5A8C) == 4) {
        if (t >= *(int*)((char*)self + 0x5AB8)) {
            *(int*)((char*)self + 0x5A8C) = 5;
            *(int*)((char*)self + 0x5ABC) = 0;
            func_00423DD0(*(int*)((char*)self + 0x5AC8));
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00382650);
#ifdef SKIP_ASM
extern "C" void func_00382688(void* arg);

extern "C" int func_00382650(int cause, void* arg)
{
    if (cause != 1) {
        // PORT: PS2-only debug trap (assert).
        __asm__ __volatile__("break 0");
    }
    func_00382688(arg);
    // PORT: PS2-only: re-enable interrupts (EI).
    __asm__ __volatile__("sync.l\n\tei");
    return 1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00382688);
#ifdef SKIP_ASM
extern "C" void func_00423DD0(int sema);

extern "C" void func_00382688(void* self)
{
    if (*(volatile int*)((char*)self + 0x5A8C) == 1) {
        *(volatile int*)((char*)self + 0x5A8C) = 2;
        func_00423DD0(*(int*)((char*)self + 0x5AC8));
    } else if (*(volatile int*)((char*)self + 0x5A8C) == 3) {
        *(volatile int*)((char*)self + 0x5A8C) = 4;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003826E0);
#ifdef SKIP_ASM
extern "C" int func_003826E0(void* self)
{
    volatile int* arr = (volatile int*)((char*)self + 0x5a90);
    volatile int* s = &arr[*(int*)((char*)self + 0x5a10)];
    if (*s == 0 || *s == 1) {
        if (*s == 0) {
            *s = 1;
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00382730);
#ifdef SKIP_ASM
extern "C" int func_00382730(void* self)
{
    return *(unsigned int*)((char*)self + 0x5a8c) == 0;
}
#endif

extern "C" void* func_00382760(void* self);

//100%
INCLUDE_ASM("render/particle", func_00382740__FPv);
#ifdef SKIP_ASM
void* func_00382740(void* self)
{
    return func_00382760(self);
}
#endif

INCLUDE_ASM("render/particle", func_00382760);

INCLUDE_ASM("render/particle", func_00382AF0);

INCLUDE_ASM("render/particle", func_00383A10);

//100%
INCLUDE_ASM("render/particle", func_00384D98);
#ifdef SKIP_ASM
extern "C" void* func_00384D98(void* self, unsigned int* src)
{
    *(unsigned int**)((char*)self + 0x0) = src;
    *(unsigned int*)((char*)self + 0x4) = *src | 0x30000000;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00384DC0);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` packet words.
extern "C" void func_00384DC0(void* self)
{
    if (*(int*)((char*)self + 0x10) & 1) {
        *(*(ulong**)((char*)self + 0x4))++ = 0;
    }
    *(ulong*)(*(char**)((char*)self + 0xC) + 0x0) = ((ulong)0x14000000 << 32) | 1;
    *(ulong*)(*(char**)((char*)self + 0xC) + 0x8) = 0;
    *(ulong*)(*(char**)((char*)self + 0xC) + 0x10) = 0x4A;
    *(ulong*)(*(char**)((char*)self + 0xC) + 0x18) = 0;
    *(ulong*)(*(char**)((char*)self + 0xC) + 0x20) =
        (*(int*)((char*)self + 0x10) | 0x8000) | ((ulong)0xD000 << 46);
    *(ulong*)(*(char**)((char*)self + 0xC) + 0x28) = 0x521;
    *(char**)((char*)self + 0xC) += 0x30;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00384E50);
#ifdef SKIP_ASM
struct sPtRS_4E50 {
    int f0;
    int f4;
    int f8;                         // bits 0..4 = key
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_4E50 {
    sPtRS_4E50 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_4E50 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_4E50 ents[1];            // 0x80
};

struct sPtGfx_4E50 {
    char pad_0x0[0xE84];
    sPtRS_4E50* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_4E50* ring;             // 0x18F0
};

struct sPktBuilder_4E50 {
    unsigned int* where;            // 0x0
    unsigned int cur;               // 0x4 (uncached)
    unsigned int start;             // 0x8 (uncached)
    int open;                       // 0xC
};

extern sPtGfx_4E50* D_004A5B80_4E50 __asm__("D_004A5B80");
extern "C" void func_00384DC0(void* self);
void operator_delete(int*);

// PORT: uncached (0x30000000) pointers held in int; 64-bit GS words are `ulong`.
// Packet builder destructor: closes the packet with its DMA tags and queues it on the particle ring.
extern "C" void func_00384E50(sPktBuilder_4E50* self, int flags)
{
    if (self->start != 0) {
        if (self->open != 0)
            func_00384DC0(self);
        unsigned long* p = (unsigned long*)self->start;
        int qwc = ((unsigned long*)self->cur - p) / 2;
        p[0] = (qwc - 1) | 0x10000000;
        ((unsigned long*)self->start)[1] = 0;
        ((unsigned long*)self->start)[2] = 0;
        unsigned int n = qwc;
        ((unsigned long*)self->start)[3] = (unsigned long)((n - 2) | 0x50000000) << 32;
        unsigned int buf = self->start & 0x0FFFFFFF;
        unsigned int next = self->cur & 0x0FFFFFFF;
        self->cur = next;
        self->start = buf;
        sPtGfx_4E50* g = D_004A5B80_4E50;
        sPtRing_4E50* ring = g->ring;
        sPtRS_4E50* rs = g->top;
        if (ring->count < 0xA28) {
            rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
            int key = *(int*)((char*)ring + 0x69CC0);
            sPtEnt_4E50* e = (sPtEnt_4E50*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
            e->rs = *rs;
            e->buf = buf;
            e->next = next;
            e->key = key;
            e->flag = 0;
        }
        self->cur += 0x10;
        *self->where = self->cur;
    }
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00384FD0);
#ifdef SKIP_ASM
struct sPartGsCtx {
    int field_0x0;
    ulong* p;            // 0x4
    int field_0x8;
    int field_0xc;
    int count;           // 0x10
};

struct sPartGsVtx {
    float s;             // 0x0
    float t;             // 0x4
    int field_0x8;
    int field_0xc;
    unsigned int r;      // 0x10
    unsigned int g;      // 0x14
    unsigned int b;      // 0x18
    unsigned int a;      // 0x1c
};

struct sPartGsPos {
    float x, y, z, q;
};

// PORT: 64-bit `ulong` GS packet words; float bits reinterpreted via *(int*)&f.
extern "C" void func_00384FD0(sPartGsCtx* ctx, sPartGsVtx* v, sPartGsPos* pos)
{
    ctx->p[0] = (ulong)v->r | ((ulong)v->g << 8) | ((ulong)v->b << 16) | ((ulong)v->a << 24)
              | ((ulong)*(int*)&pos->q << 32);
    union { float f; int i; } us, ut;
    us.f = v->s * pos->q;
    ut.f = v->t * pos->q;
    ctx->p[1] = (ulong)us.i | ((ulong)ut.i << 32);
    ctx->p[2] = (ulong)(int)pos->x | ((ulong)(int)pos->y << 16) | ((ulong)(int)(pos->z * pos->q) << 32);
    ctx->p += 3;
    ctx->count++;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/particle", func_003850A8);
#ifdef SKIP_ASM
// PORT: packet pointers held in int fields (field_0x8 / field_0xc).
extern "C" void func_003850A8(sPartGsCtx* ctx, sPartGsVtx* v, sPartGsPos* pos)
{
    if (ctx->field_0x8 == 0) {
        ulong* p = ctx->p;
        ctx->field_0x8 = (int)p;
        ctx->p = p + 4;
    } else if (ctx->field_0xc != 0) {
        func_00384DC0(ctx);
    }
    ulong* q = ctx->p;
    ctx->count = 0;
    ctx->field_0xc = (int)q;
    ctx->p = q + 6;
    func_00384FD0(ctx, v, pos);
}
#endif

INCLUDE_ASM("render/particle", func_00385138);

//100%
INCLUDE_ASM("render/particle", func_00385260);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00493938[];

extern "C" void func_00385260(int* self, int flags)
{
    *(void**)((char*)self + 0x4) = D_00493938;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/particle", func_00385290);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
extern void* D_00493208[];

extern "C" void func_00385290(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00493208;
    if (*(void**)((char*)self + 0x19C) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x19C));
    }
    func_00385260((int*)self, flags);
}
#endif

INCLUDE_ASM("render/particle", func_003852E8);

INCLUDE_ASM("render/particle", func_00385410);

INCLUDE_ASM("render/particle", func_00385530);

INCLUDE_ASM("render/particle", func_003856B8);

//100%
INCLUDE_ASM("render/particle", func_00385A38);
#ifdef SKIP_ASM
struct sPartVec3 {
    float x, y, z;
};

extern "C" void func_00385A38(void* self, short* out, int i, sPartVec3* v)
{
    float s = *(float*)((char*)self + 0x198);
    sPartVec3 t;
    t.x = v->x * s;
    t.y = v->y * s;
    t.z = v->z * s;
    int j = i * 3;
    out[j] = (short)t.x;
    out[j + 1] = (short)t.y;
    out[j + 2] = (short)t.z;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00385AA0);
#ifdef SKIP_ASM
// PORT: g++ `<?` (min) operator.
static inline float partClampf(float x, float lo, float hi)
{
    if (x >= lo) {
        return x <? hi;
    }
    return lo;
}

extern "C" void func_00385AA0(void* self, unsigned short* buf, int idx, const float* c)
{
    unsigned char r = (int)(partClampf(c[1], 0.0f, 1.0f) * 32.0f);
    unsigned char g = (int)(partClampf(c[2], 0.0f, 1.0f) * 32.0f);
    unsigned char b = (int)(partClampf(c[3], 0.0f, 1.0f) * 32.0f);
    unsigned char a = (int)(partClampf(c[0], 0.0f, 1.0f) * 32.0f);
    if (r > 31) r = 31;
    if (g > 31) g = 31;
    if (b > 31) b = 31;
    if (a > 0) a = 1;
    buf[idx] = (a << 15) | (b << 10) | (g << 5) | r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00385BA0);
#ifdef SKIP_ASM
struct sShortUV {
    short u;
    short v;
};

extern "C" void func_00385BA0(void* self, sShortUV* dst, int idx, float* src)
{
    dst[idx].u = (short)(src[0] * 4096.0f);
    dst[idx].v = (short)(src[1] * 4096.0f);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00385BE0);
#ifdef SKIP_ASM
class cPartVirt {
public:
    int field_0x0;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int, int, int);
};

extern "C" void func_00385BE0(cPartVirt* self, int a, void* b, int c)
{
    self->v08(a, **(short**)((char*)b + 4), c);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00385C10);
#ifdef SKIP_ASM
struct sPtRS_5C10 {
    int f0;                         // bits 6..9 = layer
    int f4;
    int f8;                         // bits 0..4 = key
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_5C10 {
    sPtRS_5C10 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_5C10 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_5C10 ents[1];            // 0x80
};

struct sPtGfx_5C10 {
    char pad_0x0[0xE84];
    sPtRS_5C10* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_5C10* ring;             // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x6B90 - 0x5A04];
    int texReady;                   // 0x6B90
};

struct sMat_5C10 {
    float m[4][4];
    sMat_5C10() {}
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
    sMat_5C10(const sMat_5C10& s)
    {
        __asm__ __volatile__(
            "lqc2      $vf1, 0x0(%1)\n"
            "lqc2      $vf2, 0x10(%1)\n"
            "lqc2      $vf3, 0x20(%1)\n"
            "lqc2      $vf4, 0x30(%1)\n"
            "sqc2      $vf1, 0x0(%0)\n"
            "sqc2      $vf2, 0x10(%0)\n"
            "sqc2      $vf3, 0x20(%0)\n"
            "sqc2      $vf4, 0x30(%0)\n"
            :
            : "r"(this), "r"(&s)
            : "memory");
    }
} __attribute__((aligned(16)));

struct sVec4_5C10 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBez_5C10 {
    char pad_0x0[0x194];
    float scale;                    // 0x194
    char pad_0x198[0x8];
    int buf;                        // 0x1A0
    int flip;                       // 0x1A4
    char pad_0x1A8[0x4];
    unsigned int tags[2];           // 0x1AC
    char pad_0x1B4[0x1C4 - 0x1B4];
    sPtGfx_5C10* gfx;               // 0x1C4
};

// PORT: PS2-only VU0 inline asm (scale the rows of a 4x4 matrix by a vector).
static inline sMat_5C10 ScaleMat_5C10(const sMat_5C10& m, const sVec4_5C10& v)
{
    sMat_5C10 d;
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%2)\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2      $vf8, 0x0(%0)\n"
        "sqc2      $vf9, 0x10(%0)\n"
        "sqc2      $vf10, 0x20(%0)\n"
        "sqc2      $vf11, 0x30(%0)\n"
        :
        : "r"(&d), "r"(&m), "r"(&v)
        : "memory");
    return d;
}

extern int D_004A4474;
extern "C" unsigned long* func_0038F460(int dma, unsigned int buf, int a2, int a3);
extern "C" unsigned int func_0038F668(int dma, unsigned long* p, int a2);
extern "C" void func_0037D968(void* self);
extern "C" void func_0037E120_5C10(sPtGfx_5C10* gfx, sMat_5C10* m, sMat_5C10* hdr, sVec4_5C10* scale, int flag, int a5, int prim, char** pp) __asm__("func_0037E120");

// PORT: uncached (0x30000000) pointers held in int; 64-bit GS words are `ulong`.
extern "C" void func_00385C10(sBez_5C10* self, sMat_5C10* mat, int tex, int flag)
{
    if (self->flip) {
        self->flip = 0;
        self->buf = (self->buf + 1) & 1;
    }
    if (self->gfx->texReady == 0) {
        func_0037D968(self->gfx);
    }
    self->gfx->top->f0 = (self->gfx->top->f0 & ~0x3C0) | 0xC0;
    self->gfx->top->fC &= 0xC0000000;
    self->gfx->top->tex = tex;
    unsigned int addr = self->gfx->bufAddr;
    sMat_5C10 m = *mat;
    float s = self->scale;
    sVec4_5C10 sc;
    sc.x = s;
    sc.y = s;
    sc.z = s;
    sc.w = 1.0f;
    sMat_5C10 m2 = ScaleMat_5C10(*mat, sc);
    char* p = (char*)func_0038F460(D_004A4474, addr, -1, 0);
    func_0037E120_5C10(self->gfx, &m2, &m, &sc, flag, 0, flag ? 0x22 : 0x20, &p);
    *(ulong*)p = ((ulong)self->tags[self->buf] << 32) | 0x50000000;
    *(ulong*)(p + 8) = 0;
    p += 0x10;
    addr = func_0038F668(D_004A4474, (unsigned long*)p, 4);
    sPtRing_5C10* ring = self->gfx->ring;
    sPtRS_5C10* rs = self->gfx->top;
    unsigned int cur = self->gfx->bufAddr;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtEnt_5C10* e = (sPtEnt_5C10*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = cur;
        e->next = addr;
        e->key = key;
        e->flag = 0;
    }
    self->gfx->bufAddr = addr + 0x10;
}
#endif

INCLUDE_ASM("render/particle", func_00385EB0);

INCLUDE_ASM("render/particle", func_00386128);

//100%
INCLUDE_ASM("render/particle", func_00386640);
#ifdef SKIP_ASM
extern "C" void func_0036ABA0(void* self, int a1);
extern "C" void func_00390458(void* self, int a1);
extern "C" void func_0036C740(void* self, int a1);

extern "C" void func_00386640(void* self, int a1)
{
    func_0036ABA0(self, a1);
    func_00390458(self, a1);
    func_0036C740(self, a1);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00386688);
#ifdef SKIP_ASM
struct sPartPair {
    int a, b;
};

// Pushes the current matrix (self+0x6AF0) and the pair at self+0x5900 onto slot i.
// PORT: PS2-only VU0 asm (lqc2/sqc2 matrix copy).
extern "C" void func_00386688(void* self, int i)
{
    // PORT: (int)self pointer arithmetic (index added first, as in the target).
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "sqc2      $vf1, 0x0(%1)\n"
        "sqc2      $vf2, 0x10(%1)\n"
        "sqc2      $vf3, 0x20(%1)\n"
        "sqc2      $vf4, 0x30(%1)\n"
        :
        : "r"((char*)self + 0x6AF0), "r"((char*)((i << 6) + (int)self) + 0x5930)
        : "memory");
    ((sPartPair*)((char*)self + 0x59B0))[i] = *(sPartPair*)((char*)self + 0x5900);
    *(int*)((char*)self + 0x59C0) = i + 1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003866E0__FPvii);
#ifdef SKIP_ASM
void func_003866E0(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x6d0c) = a1;
    *(int*)((char*)self + 0x6d10) = a2;
}
#endif

INCLUDE_ASM("render/particle", func_003866F0);

INCLUDE_ASM("render/particle", func_00386BD0);

//100%
INCLUDE_ASM("render/particle", func_00386CF0);
#ifdef SKIP_ASM
void func_00369FF0(void* self);

extern "C" void func_00386CF0(void* self)
{
    func_00369FF0(self);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00386D10);
#ifdef SKIP_ASM
struct sPartStrip_6D10 {
    void* verts;    // 0x0
    void* cols;     // 0x4
    int count;      // 0x8
    int field_0xc;
    int field_0x10;
};

extern "C" void func_00387EC0(void* self, void* verts, void* cols, int count, void* a4, void* a5, void* a6, float f0, float f1);

extern "C" void func_00386D10(void* self, sPartStrip_6D10* strips, int n, void* a3, void* a4, void* a5, float f0, float f1)
{
    for (; n > 0; n--, strips++) {
        if (strips->count >= 2) {
            func_00387EC0(self, strips->verts, strips->cols, strips->count, a3, a4, a5, f0, f1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00386DD0);
#ifdef SKIP_ASM
struct sPartStrip_6DD0 {
    void* verts;    // 0x0
    void* cols;     // 0x4
    int count;      // 0x8
    float f0;       // 0xC
    float f1;       // 0x10
};

extern "C" void func_00387EC0(void* self, void* verts, void* cols, int count, void* a4, void* a5, void* a6, float f0, float f1);

extern "C" void func_00386DD0(void* self, sPartStrip_6DD0* strips, int n, void* a3, void* a4, void* a5)
{
    for (; n > 0; n--, strips++) {
        if (strips->count >= 2) {
            func_00387EC0(self, strips->verts, strips->cols, strips->count, a3, a4, a5, strips->f0, strips->f1);
        }
    }
}
#endif

INCLUDE_ASM("render/particle", func_00386E78);

INCLUDE_ASM("render/particle", func_00387EC0);

//100%
INCLUDE_ASM("render/particle", func_003883B8);
#ifdef SKIP_ASM
struct sPtRS_83B8 {
    int f0;                         // bits 6..9 = layer
    int f4;
    int f8;                         // bits 0..4 = key
    int fC;
    short tex;
    short pad;
};

struct sPtEnt_83B8 {
    sPtRS_83B8 rs;                  // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};

struct sPtRing_83B8 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sPtEnt_83B8 ents[1];            // 0x80
};

struct sPtGfx_83B8 {
    char pad_0x0[0xE84];
    sPtRS_83B8* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing_83B8* ring;             // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x6B90 - 0x5A04];
    int texReady;                   // 0x6B90
};

extern int D_004A5B84;
extern sPtRS_83B8 D_00501420_rs __asm__("D_00501420");

extern "C" void func_0037D968(void* self);
extern "C" void func_003885E0(void* self, void* a, void* b, void* c, void* d, int i0, int i1, float f0, float f1);

// PORT: uncached (0x30000000) pointers held in int.
extern "C" void func_003883B8(sPtGfx_83B8* self, void* a1, int n, void* a3, void* a4, void* a5, float f0, float f1)
{
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0xC0;
    self->top->fC &= 0xC0000000;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    unsigned int buf = self->bufAddr;
    func_003E6448((void*)D_004A5B84, 0, 0x30);
    int i;
    for (i = 0; i < n - 1; i++) {
        func_003885E0(self, a1, a3, a4, a5, i, i + 1, f0, f1);
    }
    sPtRing_83B8* ring = self->ring;
    unsigned int next = self->bufAddr;
    sPtRS_83B8* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtEnt_83B8* e = (sPtEnt_83B8*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    self->bufAddr += 0x10;
    self->top->f0 &= ~0x3C0;
    self->top->fC &= 0xC0000000;
    *self->top = D_00501420_rs;
}
#endif

INCLUDE_ASM("render/particle", func_003885E0);

INCLUDE_ASM("render/particle", func_003889F0);

//100%
INCLUDE_ASM("render/particle", func_00389098);
#ifdef SKIP_ASM
extern "C" int func_004139F8(float f);

extern "C" void func_00389098(void* self, const float* c)
{
    float k = 255.0f;
    int r = func_004139F8(c[0] * k);
    r |= func_004139F8(c[1] * k) << 8;
    r |= func_004139F8(c[2] * k) << 16;
    *(int*)((char*)self + 0x6AE0) = r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389118);
#ifdef SKIP_ASM
extern "C" void func_00424880(int);
extern "C" void func_00423AA0(int, int);
extern "C" void func_00424950(int);
extern "C" void func_00423AD0(int, int);

extern "C" void func_00389118(void* self)
{
    func_00424880(2);
    func_00423AA0(2, *(int*)((char*)self + 0x5AC0));
    func_00424950(1);
    func_00423AD0(0, *(int*)((char*)self + 0x5AC4));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389260);
#ifdef SKIP_ASM
struct sPartVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" void func_00389260(sPartVec4* v)
{
    for (int i = 0; i < 10; i++) {
        v[i].x = v[i].y = v[i].z = v[i].w = 0.0f;
    }
}
#endif

INCLUDE_ASM("render/particle", func_00389308);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/particle", func_00389520);
#ifdef SKIP_ASM
extern "C" void func_00389308(void* self, void* dst, float w, float x, float y, float z);

extern "C" void func_00389520(void* self, const float* v, void* dst)
{
    func_00389308(self, dst, 1.0f, v[0], v[1], v[2]);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389558);
#ifdef SKIP_ASM
extern "C" void func_00389558(float* a, float* b)
{
    a[0] += b[0];
    a[1] += b[1];
    a[2] += b[2];
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389590);
#ifdef SKIP_ASM
extern "C" void func_00389590(sPartVec4* a, sPartVec4* b, sPartVec4* c, float s)
{
    float kx = s * c->x;
    float ky = s * c->y;
    float kz = s * c->z;
    float kw = s * c->w;
    for (int i = 0; i < 10; i++) {
        a[i].x += b[i].x * ky;
        a[i].y += b[i].y * kz;
        a[i].z += b[i].z * kw;
        a[i].w += b[i].w * kx;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389620);
#ifdef SKIP_ASM
struct sVec4_9620 {
    float x, y, z, w;
};

// Integrates the w channel of ten particle vectors: dst.w += src.w * dt.
extern "C" void func_00389620(sVec4_9620* dst, sVec4_9620* src, float dt)
{
    float* s = &src->w;
    float* d = &dst->w;
    for (int i = 0; i < 10; i++) {
        *d += *s * dt;
        d += 4;
        s += 4;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389730);
#ifdef SKIP_ASM
struct sPartVec4x10 {
    sPartVec4 v[10];
};

// PORT: VU0 macro-mode vector add; the PC port needs plain C.
static inline sPartVec4 sPartVec4_add(const sPartVec4& a, const sPartVec4& b)
{
    sPartVec4 r;
    __asm__(
        "lqc2       $vf3, 0x0(%1)\n"
        "lqc2       $vf4, 0x0(%2)\n"
        "vadd.xyzw  $vf5, $vf3, $vf4\n"
        "sqc2       $vf5, %0\n"
        : "=m"(r)
        : "r"(&a), "r"(&b));
    return r;
}

extern "C" sPartVec4x10 func_00389730(sPartVec4x10* a, sPartVec4x10* b)
{
    sPartVec4x10 r;
    for (int i = 0; i < 10; i++) {
        r.v[i] = sPartVec4_add(a->v[i], b->v[i]);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003897A0);
#ifdef SKIP_ASM
// PORT: VU0 macro-mode vector scale; the PC port needs plain C.
static inline sPartVec4 sPartVec4_scale(const sPartVec4& a, float s)
{
    sPartVec4 r;
    __asm__(
        "mfc1       $2, %2\n"
        "lqc2       $vf4, 0x0(%1)\n"
        "qmtc2.ni   $2, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2       $vf5, %0\n"
        : "=m"(r)
        : "r"(&a), "f"(s)
        : "$2");
    return r;
}

extern "C" sPartVec4x10 func_003897A0(sPartVec4x10* a, float s)
{
    sPartVec4x10 r;
    for (int i = 0; i < 10; i++) {
        r.v[i] = sPartVec4_scale(a->v[i], s);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389810);
#ifdef SKIP_ASM
// PORT: VU0 macro-mode vector scale (vec4 *= s); the PC port needs plain C.
extern "C" sPartVec4* func_00389810(sPartVec4* v, float s)
{
    for (int i = 0; i < 10; i++) {
        __asm__ __volatile__(
            "mfc1       $2, %1\n"
            "lqc2       $vf4, 0x0(%0)\n"
            "qmtc2.ni   $2, $vf3\n"
            "vmulx.xyzw $vf5, $vf4, $vf3x\n"
            "sqc2       $vf5, 0x0(%0)\n"
            :
            : "r"(&v[i]), "f"(s)
            : "$2", "memory");
    }
    return v;
}
#endif

INCLUDE_ASM("render/particle", func_00389840);

//100%
INCLUDE_ASM("render/particle", func_00389C38);
#ifdef SKIP_ASM
struct sParticleEntryA0;
extern "C" sParticleEntryA0* func_0038ABF8(void* self, int i);
extern "C" void func_00389CB8(sPartVec4* self, void* p, float s);
extern int D_004A43C4;

struct sPartLib_9C38 {
    int f0;
    int count;      // 0x4
    void* items;    // 0x8
};
extern sPartLib_9C38 D_005047F8;
extern sPartVec4 D_00504810;

extern "C" void func_00389C38(sPartVec4* self, void* p)
{
    func_00389260(self);
    sPartLib_9C38* lib = &D_005047F8;
    if (lib->count > 0) {
        func_00389590(self, (sPartVec4*)func_0038ABF8(lib, D_004A43C4), &D_00504810, 1.0f);
    }
    if (p != 0) {
        func_00389CB8(self, p, 1.0f);
    }
}
#endif

INCLUDE_ASM("render/particle", func_00389CB8);

//100%
INCLUDE_ASM("render/particle", func_0038A530);
#ifdef SKIP_ASM
extern "C" int func_0038A530(float* p, float* n, void* s, float* dist, float* inv, float* planeD)
{
    float d;
    float k;
    float dx = *(float*)((char*)s + 0x38) - p[0];
    float dy = *(float*)((char*)s + 0x3C) - p[1];
    float r = *(float*)((char*)s + 0x1C);
    float dz = *(float*)((char*)s + 0x40) - p[2];
    float d2 = dx * dx + dy * dy + dz * dz;
    if (r * r < d2) {
        return 0;
    }
    if (d2 != 0.0f) {
        // PORT: sqrt.s (sqrtf without errno check)
        __asm__("sqrt.s %0, %1" : "=f"(d) : "f"(d2));
        k = 1.0f / d;
    } else {
        k = 1.0f;
        d = k;
    }
    dx *= k;
    dy *= k;
    dz *= k;
    *planeD = -(dx * *(float*)((char*)s + 0x2C) + dy * *(float*)((char*)s + 0x30) + dz * *(float*)((char*)s + 0x34));
    *dist = d;
    *inv = k;
    n[0] = dx;
    n[1] = dy;
    n[2] = dz;
    n[3] = 1.0f;
    return 1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0038A618);
#ifdef SKIP_ASM
extern "C" int func_0038A618(float* p, float* n, void* s, float* dist, float* inv)
{
    float dx = *(float*)((char*)s + 0x38) - p[0];
    float dy = *(float*)((char*)s + 0x3C) - p[1];
    float r = *(float*)((char*)s + 0x1C);
    float dz = *(float*)((char*)s + 0x40) - p[2];
    float d2 = dx * dx + dy * dy + dz * dz;
    if (r * r < d2) {
        return 0;
    }
    float d;
    // PORT: sqrt.s (sqrtf without errno check)
    __asm__("sqrt.s %0, %1" : "=f"(d) : "f"(d2));
    *dist = d;
    float k = 1.0f / d;
    *inv = k;
    dy *= k;
    dz *= k;
    dx *= k;
    n[3] = 1.0f;
    n[0] = dx;
    n[1] = dy;
    n[2] = dz;
    return 1;
}
#endif

INCLUDE_ASM("render/particle", func_0038A6A8);

//100%
INCLUDE_ASM("render/particle", func_0038ABF8);
#ifdef SKIP_ASM
struct sParticleEntryA0 {
    char pad_0x00[0xA0];
};

extern "C" sParticleEntryA0* func_0038ABF8(void* self, int i)
{
    int count = *(int*)((char*)self + 0x4);
    if (i >= count) {
        i = count - 1;
    }
    return *(sParticleEntryA0**)((char*)self + 0x8) + i;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0038AC20);
#ifdef SKIP_ASM
extern "C" int func_0038AC50(void* self, const char* name);

extern "C" sParticleEntryA0* func_0038AC20(void* self, const char* name)
{
    return func_0038ABF8(self, func_0038AC50(self, name));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0038AC50);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const void* a, const void* b);

extern "C" int func_0038AC50(void* self, const char* name)
{
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x4); i++) {
        if (func_004165A8(name, *(char**)((char*)self + 0xC) + (i << 3)) == 0) {
            return i;
        }
    }
    return 0;
}
#endif

