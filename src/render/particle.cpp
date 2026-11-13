#include "common.h"
#include "bx/math3d.h"

// ---- Shared declarations: one type per real thing, used by the functions below ----

// A render-state record of cPS2GraphicsMan's state stack (top at 0xE84; D_00501420 holds the default). f4 bits
// 2..6 = layer, f8 bits 5..9 = blend, bits 0..4 = key.
struct sPtRenderState {
    int f0;
    int f4;
    int f8;
    int fC;
    short tex;
    short pad;
};

// One 0x80-byte entry of the graphics manager's draw ring (ring at 0x18F0): its render state, packet buffer, link
// and sort key.
struct sPtRingEnt {
    sPtRenderState rs;       // 0x00
    unsigned int buf;        // 0x14
    unsigned int next;       // 0x18
    short key;               // 0x1C
    short flag;              // 0x1E
    char pad_0x20[0x60];
};

// The graphics manager draw ring (cPS2GraphicsMan + 0x18F0): entry count, then the 0x80-byte entries from 0x80.
struct sPtRing {
    int count;               // 0x0
    char pad_0x4[0x7C];
    sPtRingEnt ents[1];      // 0x80
};

// 4x4 float matrix (POD, 16-byte aligned).
struct sPtMatrix {
    float m[4][4];
} __attribute__((aligned(16)));

// 4x4 float matrix with an empty ctor and a VU0 copy ctor (copies go through vf1..vf4).
struct sPtMatrixV {
    float m[4][4];
    sPtMatrixV() {}
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
    sPtMatrixV(const sPtMatrixV& s)
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

// One 128-bit GIF / DMA packet quadword (four unsigned words, 16-byte aligned).
struct sGifQuad {
    unsigned int w[4];
} __attribute__((aligned(16)));

// Plain three-float vector.
struct sPtVec3 {
    float x, y, z;
};

// Unaligned four-float vector (not t4Vector: no 16-byte alignment).
struct sPtVec4u {
    float x, y, z, w;
};

// g++ 2.95 vtable entry for a method taking (self, int).
struct sPtVtVI {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// Four floats with an empty ctor (arrays of it are built with vec_new loops; not the POD t4Vector).
struct sPtVec4c {
    float v[4];
    sPtVec4c() {}
};

// g++ 2.95 vtable entry for a method taking only self, returning int.
struct sPtVtI {
    short delta;
    short index;
    int (*fn)(void*);
};

// g++ 2.95 vtable entry for a method taking (self, pointer).
struct sPtVtVP {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

// g++ 2.95 vtable entry for a method taking (self, int, int, int), returning int.
struct sPtVtIIII {
    short delta;
    short index;
    int (*fn)(void*, int, int, int);
};

// Byte colour (r, g, b, a).
struct sPtRGBA {
    unsigned char r, g, b, a;
};

// Particle vertex record (position, int colour, 16 spare bytes).
struct sPtVert {
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

// 4x4 float matrix without the 16-byte alignment of sPtMatrix (the skinning code uses it as one bone matrix:
// column j of each row feeds output component j).
struct sPtMatrixU {
    float m[4][4];
};

// Plain two-float vector.
struct sPtVec2 {
    float x, y;
};

// Four floats as an aligned array (indexed access; same bytes as t4Vector).
struct sPtQuadF {
    float v[4];
} __attribute__((aligned(16)));

// Four unsigned shorts (a scissor / viewport rectangle).
struct sPtScissor {
    unsigned short v[4];
};

// 128-bit packet quadword as four signed words (the unsigned view is sGifQuad).
struct sPtQuadI {
    int w[4];
} __attribute__((aligned(16)));

// Segment header (seg, step, fstep, v) of the 003807A0 / 00380CE0 strip packets.
struct sPtSegHdr {
    int seg;
    int step;
    float fstep;
    float v;
} __attribute__((aligned(16)));

// Float / int bit view.
union uPtFloatBits {
    float f;
    int i;
};

// A dynamic emitter as 00371380 / 00371688 see it (base, kind, frame; its render state at 0x1E4).
struct sPtEmitter {
    char pad_0x0[0x4];
    int base;               // 0x4
    int kind;               // 0x8
    char pad_0xC[0x4];
    float frame;            // 0x10
    char pad_0x14[0x160];
    int field_0x174;        // 0x174
    char pad_0x178[0x68];
    int field_0x1E0;        // 0x1E0
    sPtRenderState rs;           // 0x1E4
};

// Camera / view block (viewport, matrices, scissor) that 003765B8 and 00376768 fill.
struct sPtView {
    float x, y, w, h;               // 0x00
    char pad_0x10[0x14];
    float f24;                      // 0x24
    float f28;                      // 0x28
    float f2C;                      // 0x2C
    sPtQuadF q30;                   // 0x30
    sPtQuadF q40;                   // 0x40
    sPtQuadF q50;                   // 0x50
    sPtMatrix m60;                 // 0x60
    sPtMatrix mA0;                 // 0xA0
    sPtMatrix mE0;                 // 0xE0
    sPtMatrix m120;                // 0x120
    sPtQuadF q160;                  // 0x160
    sPtQuadF q170;                  // 0x170
    sPtMatrix m180;                // 0x180
    sPtMatrix m1C0;                // 0x1C0
    sPtQuadF q200;                  // 0x200
    sPtQuadF q210;                  // 0x210
    sPtScissor scissor;            // 0x220
    int key;                        // 0x228
    int pad_0x22C;
};

// Five packet quadwords followed by a VU0-copied matrix.
struct sPtMatPacket {
    sGifQuad q[5];                // 0x00
    sPtMatrixV mat;                  // 0x50
};

// cPS2GraphicsMan (prototype class) as the particle renderers see it: render-state stack top, texture ids, draw
// ring, texture set, scissor, frame-buffer setup, bounds. Fields named by their users; the rest is padding.
struct cPS2GraphicsMan {
    char pad_0x0[0xE84];
    sPtRenderState* top;            // 0xE84
    char pad_0xE88[0xF50 - 0xE88];
    int texIds[(0x10D8 - 0xF50) / 4];   // 0xF50
    sPtVtVP* vtable;                // 0x10D8
    char pad_0x10DC[0x18F0 - 0x10DC];
    sPtRing* ring;                  // 0x18F0
    void* texset;                   // 0x18F4
    char pad_0x18F8[0x5860 - 0x18F8];
    sPtMatrixV m5860;               // 0x5860
    char pad_0x58A0[0x5900 - 0x58A0];
    unsigned short scX;             // 0x5900
    unsigned short scY;             // 0x5902
    unsigned short scW;             // 0x5904
    unsigned short scH;             // 0x5906
    char pad_0x5908[0x5A00 - 0x5908];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x5A28 - 0x5A04];
    unsigned int pendBuf;           // 0x5A28
    unsigned long* pend;            // 0x5A2C
    unsigned int width;             // 0x5A30
    unsigned int height;            // 0x5A34
    char pad_0x5A38[0x4];
    unsigned int psm;               // 0x5A3C
    char pad_0x5A40[0x5A50 - 0x5A40];
    unsigned int fbw;               // 0x5A50
    char pad_0x5A54[0x5A84 - 0x5A54];
    unsigned int fbp;               // 0x5A84
    char pad_0x5A88[0x6AF0 - 0x5A88];
    float f6AF0;                    // 0x6AF0
    char pad_0x6AF4[0x6B04 - 0x6AF4];
    float f6B04;                    // 0x6B04
    char pad_0x6B08[0x6B30 - 0x6B08];
    sPtMatrix m6B30;                // 0x6B30
    float xmin;                     // 0x6B70
    float ymin;                     // 0x6B74
    float zmin;                     // 0x6B78
    float wmin;                     // 0x6B7C
    float xmax;                     // 0x6B80
    float ymax;                     // 0x6B84
    float zmax;                     // 0x6B88
    float wmax;                     // 0x6B8C
    int texReady;                   // 0x6B90
};

// Copies n packet quadwords to *pp and advances it.
static inline void CopyQuads(unsigned long** pp, const void* srcp, int n)
{
    const sGifQuad* src = (const sGifQuad*)srcp;
    sGifQuad* d = (sGifQuad*)*pp;
    sGifQuad* end = d + n;
    while (d != end) {
        *d++ = *src++;
    }
    *pp = (unsigned long*)d;
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMtx(sPtMatrix* dst, sPtMatrix* src)
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

int BXrand();
// Uniform random float in [0, 1).
static inline float randUnit()
{
    union { int i; float f; } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

static inline float clampPos(float x, float hi)
{
    return x >= 0.0f ? (x <? hi) : 0.0f;
}

static inline int wrapIndex(int i, int start, int m)
{
    return (i + start) % m;
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, by value).
static inline sPtMatrixV MulMatV(const sPtMatrixV& a, const sPtMatrixV& b)
{
    sPtMatrixV d;
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

// PORT: PS2-only VU0 inline asm (4x4 matrix copy, non-volatile form).
static inline void CopyMat(sPtMatrix* dst, const sPtMatrix* src)
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

// Callees declared by several functions below.
extern "C" void func_00364B88(void* table, void* key);
extern "C" void func_00367B60(void* mgr, int id);
extern "C" void func_0037D968(void* self);
extern "C" void func_00382AF0(void* self, bool enable, bool waitVSync);
extern "C" void func_00387EC0(void* self, void* verts, void* cols, int count, void* a4, void* a5, void* a6, float f0, float f1);
extern "C" unsigned long* func_0038F460(int dma, unsigned int buf, int a2, int a3);
extern "C" unsigned int func_0038F668(int dma, unsigned long* p, int a2);
extern "C" void func_003E6448(void* dst, int c, int n);
extern "C" int func_004139F8(float f);
extern "C" void func_00423AA0(int, int);
extern "C" void func_00423AD0(int, int);
extern "C" void func_00423DD0(int sema);
extern "C" void func_00424020(int);
extern "C" void func_00424880(int);
extern "C" void func_00424950(int);

// The graphics manager instance.
extern cPS2GraphicsMan* D_004A5B80;

// The default render state (00370DC8 reads the same object through its bit-field view sGsState_00370DC8).
extern sPtRenderState D_00501420_rs __asm__("D_00501420");

// Globals declared by several functions below.
extern int D_0044B420[];
extern void* D_00493068[];
extern void* D_004930D0[];
extern void* D_00493820[];
extern void* D_004A4248;
extern int D_004A4474;
extern int D_004A44FC;
extern char D_005059D8[];

// ---- end of shared declarations ----

//100%
INCLUDE_ASM("render/particle", cBaseClass_DynamicEmitter_Allocate);
#ifdef SKIP_ASM
// PORT: operator_new__FUi is the game's tagged allocator (size, tag, flags, d); bound by asm label
// as operator new[] so the array new-expressions below match.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00492650[];
extern char D_00492670[];

extern "C" void cBaseClass_DynamicEmitter_Allocate(void* self)
{
    char* s = (char*)self;
    sPtVec4c** pp = (sPtVec4c**)(s + 0x1A0);
    *pp = new (D_00492650, 0, 0) sPtVec4c[*(int*)(s + 0x178)];
    sPtVec4c** ps = (sPtVec4c**)(s + 0x1A4);
    *ps = new (D_00492670, 0, 0) sPtVec4c[*(int*)(s + 0x178)];
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

extern t4Vector D_004FF120;

extern "C" void cBaseClass_DynamicEmitter_reset(void* self)
{
    int i;
    *(int*)((char*)self + 0x17C) = 0;
    for (i = 0; i < *(int*)((char*)self + 0x178); i++) {
        (*(t4Vector**)((char*)self + 0x1A0))[i] = D_004FF120;
        (*(t4Vector**)((char*)self + 0x1A4))[i] = D_004FF120;
        *(int*)((char*)self + 0x17C) = 0;
        *(int*)((char*)self + 0x1E0) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00370DC8);
#ifdef SKIP_ASM
int BXrand();

extern "C" void func_0036CBF8(void* sys, int count, int a2, t4Vector* v, float a, float b, float c);
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
        self->f10 = fn * randUnit();
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
    *(t4Vector*)self->v1B0 = D_004FF120;
    *(t4Vector*)self->v1C0 = D_004FF120;
    *(t4Vector*)self->v1D0 = D_004FF120;
    float l = life_00370DC8(def);
    t4Vector v;
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

// PORT: the unit's callers use a 4-arg declaration; bind the real 5-arg body by asm label.
extern "C" void func_003710D0_impl(char* self, t4Vector* pos, t4Vector* vel, int rnd, float dt) __asm__("func_003710D0");
extern "C" void func_003710D0_impl(char* self, t4Vector* pos, t4Vector* vel, int rnd, float dt)
{
    if (*(int*)(self + 0x174) == 0) {
        return;
    }
    int alive = (*(t4Vector**)(self + 0x1A4))[*(int*)(self + 0x17C)].w > 0.0f;
    if (alive) {
        if (rnd == 0) {
            *(int*)(self + 0x1E0) = *(int*)(self + 0x1E0) - 1;
        }
    } else if (rnd) {
        *(int*)(self + 0x1E0) = *(int*)(self + 0x1E0) + 1;
    }
    if (pos) {
        *(t4Vector*)(self + 0x1B0) = *pos;
    } else {
        pos = (t4Vector*)(self + 0x1B0);
    }
    if (vel) {
        *(t4Vector*)(self + 0x1C0) = *vel;
    } else {
        vel = (t4Vector*)(self + 0x1C0);
    }
    (*(t4Vector**)(self + 0x1A0))[*(int*)(self + 0x17C)] = *pos;
    (*(t4Vector**)(self + 0x1A0))[*(int*)(self + 0x17C)].w = 0.0f;
    (*(t4Vector**)(self + 0x1A4))[*(int*)(self + 0x17C)] = *vel;
    // PORT: pointer held in int (index-first addu)
    t4Vector* v = (t4Vector*)((*(int*)(self + 0x17C) << 4) + *(int*)(self + 0x1A4));
    if (rnd) {
        v->w = randUnit() + 1.0f;
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
INCLUDE_ASM("render/particle", func_00371268);
#ifdef SKIP_ASM
extern "C" void func_0036D3D8(void* p, float v);

extern "C" void func_00371268(char* self, float v)
{
    if (v == 0.0f) {
        func_0036D3D8(self + 0x20, 0.0f);
        return;
    }
    *(float*)self = v;
    func_0036D3D8(self + 0x20, v);
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

extern "C" void func_00371380(sPtEmitter* self, int blend)
{
    if (self->field_0x174 == 0) {
        return;
    }
    cPS2GraphicsMan* ctx = D_004A5B80;
    if (self->field_0x1E0 == 0) {
        return;
    }
    int tex = ctx->texIds[self->base + (int)self->frame];
    if (tex < 0) {
        return;
    }
    self->rs.f4 = (self->rs.f4 & ~0x7C) | ((D_0044B420[self->kind] << 2) & 0x7C);
    self->rs.f8 = (self->rs.f8 & ~0x3E0) | ((blend << 5) & 0x3E0);
    self->rs.tex = tex;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *ctx->top = self->rs;
    sPtVtVP* vt = ctx->vtable;
    vt[83].fn((char*)ctx + vt[83].delta, self);
    ctx->top--;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003714B8);
#ifdef SKIP_ASM
extern "C" void* func_00370B60(void* self);

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
        (*(sPtRGBA**)((char*)self + 0x204))[i] = *(sPtRGBA*)&D_004A5998;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371688);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

extern "C" void func_00371688(sPtEmitter* self, int blend)
{
    if (self->field_0x174 == 0) {
        return;
    }
    cPS2GraphicsMan* ctx = D_004A5B80;
    if (self->field_0x1E0 == 0) {
        return;
    }
    int tex = ctx->texIds[self->base + (int)self->frame];
    if (tex < 0) {
        return;
    }
    self->rs.f4 = (self->rs.f4 & ~0x7C) | ((D_0044B420[self->kind] << 2) & 0x7C);
    self->rs.f8 = (self->rs.f8 & ~0x3E0) | ((blend << 5) & 0x3E0);
    self->rs.tex = tex;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *ctx->top = self->rs;
    sPtVtVP* vt = ctx->vtable;
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

struct sPtObj17C0 {
    char pad_0x0[0x17C];
    int idx;                    // 0x17C
    char pad_0x180[0x50];
    sPtCol17C0 col;             // 0x1D0
    char pad_0x1E0[0x24];
    sPtRGBA* colors;        // 0x204
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
INCLUDE_ASM("render/particle", func_003718E8);
#ifdef SKIP_ASM
// PORT: PS2 hardware registers (D2 = GIF DMA channel CHCR, 0x10003010 = VIF1 area register).
extern "C" void func_003718E8(void)
{
    while (*(volatile int*)0x1000A000 & 0x100) {
    }
    *(volatile int*)0x10003010 = 4;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00371940);
#ifdef SKIP_ASM

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
INCLUDE_ASM("render/particle", func_00371A58);
#ifdef SKIP_ASM
// PORT: PS2 hardware registers (D0 = VIF0 DMA channel).
extern "C" void func_00371A58(unsigned int madr, int qwc, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x10008000 & 0x100) {
        }
    }
    if (madr > 0x6FFFFFFF) {
        *(volatile unsigned int*)0x10008010 = (madr & 0x3FF0) | 0x80000000;
    } else {
        *(volatile unsigned int*)0x10008010 = madr;
    }
    *(volatile int*)0x10008020 = qwc;
    *(volatile int*)0x10008000 = 0x100;
    if (flags & 2) {
        while (*(volatile int*)0x10008000 & 0x100) {
        }
    }
}
#endif
//100%
INCLUDE_ASM("render/particle", func_00371B40);
#ifdef SKIP_ASM
// PORT: PS2 hardware registers (D1 = VIF1 DMA channel).
extern "C" void func_00371B40(unsigned int madr, int qwc, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x10009000 & 0x100) {
        }
    }
    if (madr > 0x6FFFFFFF) {
        *(volatile unsigned int*)0x10009010 = (madr & 0x3FF0) | 0x80000000;
    } else {
        *(volatile unsigned int*)0x10009010 = madr;
    }
    *(volatile int*)0x10009020 = qwc;
    *(volatile int*)0x10009000 = 0x101;
    if (flags & 2) {
        while (*(volatile int*)0x10009000 & 0x100) {
        }
    }
}
#endif
//100%
INCLUDE_ASM("render/particle", func_00371C28);
#ifdef SKIP_ASM
// PORT: PS2 hardware registers (D1 = VIF1 DMA channel).
extern "C" void func_00371C28(unsigned int madr, int qwc, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x10009000 & 0x100) {
        }
    }
    if (madr > 0x6FFFFFFF) {
        *(volatile unsigned int*)0x10009010 = (madr & 0x3FF0) | 0x80000000;
    } else {
        *(volatile unsigned int*)0x10009010 = madr;
    }
    *(volatile int*)0x10009020 = qwc;
    *(volatile int*)0x10009000 = 0x100;
    if (flags & 2) {
        while (*(volatile int*)0x10009000 & 0x100) {
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
INCLUDE_ASM("render/particle", func_00371EA0);
#ifdef SKIP_ASM
// PORT: PS2 hardware registers (D1 = VIF1 DMA channel, chain mode via TADR).
extern "C" void func_00371EA0(unsigned int tadr, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x10009000 & 0x100) {
        }
    }
    if (tadr > 0x6FFFFFFF) {
        *(volatile unsigned int*)0x10009030 = (tadr & 0x3FF0) | 0x80000000;
    } else {
        *(volatile unsigned int*)0x10009030 = tadr;
    }
    *(volatile int*)0x10009020 = 0;
    if (flags & 1) {
        *(volatile int*)0x10009000 = 0x145;
    } else {
        *(volatile int*)0x10009000 = 0x105;
    }
    if (flags & 2) {
        while (*(volatile int*)0x10009000 & 0x100) {
        }
    }
}
#endif
//100%
INCLUDE_ASM("render/particle", func_00371F98);
#ifdef SKIP_ASM
// PORT: PS2 hardware registers (D2 = GIF DMA channel, chain mode via TADR; GIF_MODE).
extern "C" void func_00371F98(unsigned int tadr, int flags)
{
    if (flags & 4) {
        while (*(volatile int*)0x1000A000 & 0x100) {
        }
    }
    *(volatile int*)0x10003010 = 4;
    if (tadr > 0x6FFFFFFF) {
        *(volatile unsigned int*)0x1000A030 = (tadr & 0x3FF0) | 0x80000000;
    } else {
        *(volatile unsigned int*)0x1000A030 = tadr;
    }
    if (flags & 1) {
        *(volatile int*)0x1000A000 = 0x144;
    } else {
        *(volatile int*)0x1000A000 = 0x104;
    }
    if (flags & 2) {
        while (*(volatile int*)0x1000A000 & 0x100) {
        }
    }
}
#endif
//100%
INCLUDE_ASM("render/particle", func_00372098);
#ifdef SKIP_ASM
// PORT: PS2 hardware registers (0x1000E000 = D_CTRL, 0x1000E020 = D_PCR).
extern "C" void func_00372098(int enable)
{
    if (enable != 0) {
        *(volatile unsigned int*)0x1000E000 |= 1;
        *(volatile int*)0x1000E020;
        *(volatile int*)0x1000E020 = 1;
        return;
    }
    *(volatile unsigned int*)0x1000E000 &= 0xFFFFFFFE;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003720F0);
#ifdef SKIP_ASM
// PORT: walks a DMA tag chain, relocating `ref` tag addresses (id 3) and stopping at `ret` (id 6).
extern "C" long* func_003720F0(long* chain)
{
    long* p = chain;
    int done = 0;
    long* base = p;
    while (!done) {
        long tag = *p;
        int hi = (int)(tag >> 32);
        int type = (int)(tag >> 28) & 7;
        int qwc = (int)tag & 0xFFFF;
        switch (type) {
        case 0:
        case 2:
        case 4:
        case 5:
        case 7:
            break;
        case 1:
            p += 2;
            p += qwc * 2;
            break;
        case 3:
            *p = ((long)((int)base + hi) << 32) | (*p & 0xFFFFFFFF);
            p += 2;
            break;
        case 6:
            p += 2;
            p += qwc * 2;
            done = 1;
            break;
        }
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00372198);
#ifdef SKIP_ASM
extern "C" void* func_003E6574_cp(void* dst, void* src, int n) __asm__("func_003E6574");

// PORT: copies a DMA tag chain, replacing `ref` tags (id 3) that point at a1/a2/a3 by nop/end packets.
extern "C" void func_00372198(long* chain, int a1, int a2, int a3)
{
    long* src = chain;
    long* dst = chain + 2;
    int count = 0;
    int done = 0;
    long tag;
    while (!done) {
        tag = *src;
        int qwc = (int)tag & 0xFFFF;
        int hi = (int)(tag >> 32);
        switch ((int)(tag >> 28) & 7) {
        case 0:
        case 2:
        case 4:
        case 5:
        case 7:
            break;
        case 1:
            src += 2;
            func_003E6574_cp(dst, src, qwc * 16);
            src = (long*)((char*)src + qwc * 16);
            dst = (long*)((char*)dst + qwc * 16);
            count += qwc;
            break;
        case 3:
            // The a1 and a2 arms are identical; the binary keeps the a2 compare and both copies.
            if (hi == a1) {
                *dst++ = 0;
                count++;
                src += 2;
                *dst++ = 0;
            } else if (hi == a2) {
                *dst++ = 0;
                count++;
                src += 2;
                *dst++ = 0;
            } else if (hi == a3) {
                *dst++ = 0x3000000005000001L;
                count++;
                src += 2;
                *dst++ = 0;
            }
            break;
        case 6:
            func_003E6574_cp(dst, src, (qwc + 1) * 16);
            src += 2;
            dst += 2;
            src = (long*)((char*)src + qwc * 16);
            dst = (long*)((char*)dst + qwc * 16);
            done = 1;
            break;
        }
    }
    tag = *chain;
    *chain = (tag & 0xFFFF0000) | (count & 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00372348);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int n);
// PORT: copies a DMA tag chain, merging runs into `cnt` tags and rebasing `ref` tags that point at a3.
extern "C" void func_00372348(long* chain, int a1, int a2, int a3)
{
    long* src = chain;
    long* dst = chain + 2;
    int count = 0;
    long* pend = chain;
    int done = 0;
    while (!done) {
        long tag = *src;
        int qwc = (int)tag & 0xFFFF;
        int hi = (int)(tag >> 32);
        switch ((int)(tag >> 28) & 7) {
        case 0:
        case 2:
        case 4:
        case 5:
        case 7:
            break;
        case 1:
            src += 2;
            func_003E6574(dst, src, qwc * 16);
            src = (long*)((char*)src + qwc * 16);
            dst = (long*)((char*)dst + qwc * 16);
            count += qwc;
            break;
        case 3:
            if (hi == a1 || hi == a2) {
                *dst = 0;
                count++;
                dst++;
                src += 2;
                *dst = 0;
                dst++;
            } else if (hi == a3) {
                pend[1] = 0;
                pend[0] = count | 0x10000000;
                count = 0;
                *dst = ((long)((int)chain + hi) << 32) | *(unsigned int*)src;
                src += 2;
                dst++;
                *dst = 0;
                dst++;
                pend = dst;
                dst += 2;
            }
            break;
        case 6:
            if (count > 0) {
                pend[1] = 0;
                pend[0] = count | 0x10000000;
                count = 0;
            }
            func_003E6574(dst, src, (qwc + 1) * 16);
            src += 2;
            dst += 2;
            src = (long*)((char*)src + qwc * 16);
            dst = (long*)((char*)dst + qwc * 16);
            done = 1;
            break;
        }
    }
}
#endif
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

extern sPtVert D_00501440[];

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
        sPtVert* v = D_00501440;
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
            sPtVert* v = &D_00501440[i];
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

extern sPtVert D_00504560[];

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
INCLUDE_ASM("render/particle", func_00372B20);
#ifdef SKIP_ASM
extern "C" int func_00372B20(int *arg0, int *arg1) {
    return *arg0 - *arg1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00372B30);
#ifdef SKIP_ASM
inline void* operator new[](unsigned int, void* p) { return p; }

extern "C" void* func_00372B30(void* self)
{
    new ((char*)self + 0x20) sPtVec4c[4];
    new ((char*)self + 0x60) sPtVec4c[6];
    new ((char*)self + 0xC0) sPtVec4c[8];
    new ((char*)self + 0x140) sPtVec4c[4];
    new ((char*)self + 0x180) sPtVec4c[6];
    new ((char*)self + 0x1E0) sPtVec4c[8];
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00372B78);
#ifdef SKIP_ASM
// cBezierCache (render/beziercache.cpp): per patch order (4x4, 6x6, 8x8 control points) a record cache with a free
// list, point / uv grids, a normal cache with its own free list, and the cubic basis tables.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

struct sBzRec_2B78 {
    int f0;
    int f4;
    int f8;                     // -1 = free
};

struct sBzV3_2B78 {
    float x, y, z;
    sBzV3_2B78() {}
};

struct sBzV2_2B78 {
    float u, v;
    sBzV2_2B78() {}
};

struct sBzPts4_2B78 { sBzV3_2B78 p[4][4]; };
struct sBzPts6_2B78 { sBzV3_2B78 p[6][6]; };
struct sBzPts8_2B78 { sBzV3_2B78 p[8][8]; };
struct sBzUV4_2B78 { sBzV2_2B78 p[4][4]; };
struct sBzUV6_2B78 { sBzV2_2B78 p[6][6]; };
struct sBzUV8_2B78 { sBzV2_2B78 p[8][8]; };

struct sBzCache_2B78 {
    int cacheSize[3];               // 0x000
    sBzRec_2B78* m4x4CacheRecord;   // 0x00C
    sBzRec_2B78* m6x6CacheRecord;   // 0x010
    sBzRec_2B78* m8x8CacheRecord;   // 0x014
    sBzRec_2B78* records[3];        // 0x018
    int* freeBuf4;                  // 0x024
    int* freeBuf6;                  // 0x028
    int* freeBuf8;                  // 0x02C
    int* freeList[3];               // 0x030
    int freeListSP[3];              // 0x03C
    sBzPts4_2B78* pts4;             // 0x048
    sBzPts6_2B78* pts6;             // 0x04C
    sBzPts8_2B78* pts8;             // 0x050
    sBzUV4_2B78* uvA4;              // 0x054
    sBzUV6_2B78* uvA6;              // 0x058
    sBzUV8_2B78* uvA8;              // 0x05C
    sBzUV4_2B78* uvB4;              // 0x060
    sBzUV6_2B78* uvB6;              // 0x064
    sBzUV8_2B78* uvB8;              // 0x068
    int pad06C;
    t4Vector basis4[4];             // 0x070
    t4Vector basis6[6];             // 0x0B0
    t4Vector basis8[8];             // 0x110
    t4Vector* basis[3];             // 0x190
    int order[3];                   // 0x19C
    int nrmCacheSize[3];            // 0x1A8
    sBzPts4_2B78* nrm4;             // 0x1B4
    sBzPts6_2B78* nrm6;             // 0x1B8
    sBzPts8_2B78* nrm8;             // 0x1BC
    int* nrmFreeBuf4;               // 0x1C0
    int* nrmFreeBuf6;               // 0x1C4
    int* nrmFreeBuf8;               // 0x1C8
    int* nrmFreeList[3];            // 0x1CC
    int nrmFreeListSP[3];           // 0x1D8
    int pad1E4[3];
    t4Vector dbasis4[4];            // 0x1F0
    t4Vector dbasis6[6];            // 0x230
    t4Vector dbasis8[8];            // 0x290
    t4Vector* dbasis[3];            // 0x310
};

extern char D_00492728[];
extern char D_00492738[];
extern char D_00492748[];
extern char D_00492758[];
extern char D_00492768[];
extern char D_00492778[];
extern char D_00492788[];
extern char D_00492798[];
extern char D_004927A8[];
extern char D_004927B8[];
extern char D_004927C8[];
extern char D_004927D8[];
extern char D_004927E8[];
extern char D_004927F8[];
extern char D_00492808[];
extern char D_00492818[];
extern char D_00492828[];
extern char D_00492838[];
extern char D_00492848[];
extern char D_00492858[];
extern char D_00492868[];

extern "C" void func_00372B78(sBzCache_2B78* self, int n4, int n6, int n8, int nn4, int nn6, int nn8)
{
    int i, k;
    float t;

    self->cacheSize[0] = n4;
    self->cacheSize[1] = n6;
    self->cacheSize[2] = n8;
    self->m4x4CacheRecord = new (D_00492728, 0, 0) sBzRec_2B78[n4];
    self->m6x6CacheRecord = new (D_00492738, 0, 0) sBzRec_2B78[n6];
    self->m8x8CacheRecord = new (D_00492748, 0, 0) sBzRec_2B78[n8];
    self->records[0] = self->m4x4CacheRecord;
    self->records[1] = self->m6x6CacheRecord;
    self->records[2] = self->m8x8CacheRecord;
    func_003E6448(self->m4x4CacheRecord, 0, n4 * sizeof(sBzRec_2B78));
    func_003E6448(self->m6x6CacheRecord, 0, n6 * sizeof(sBzRec_2B78));
    func_003E6448(self->m8x8CacheRecord, 0, n8 * sizeof(sBzRec_2B78));

    self->freeBuf4 = new (D_00492758, 0, 0) int[n4];
    self->freeBuf6 = new (D_00492768, 0, 0) int[n6];
    self->freeBuf8 = new (D_00492778, 0, 0) int[n8];
    self->freeList[0] = self->freeBuf4;
    self->freeList[1] = self->freeBuf6;
    self->freeList[2] = self->freeBuf8;
    self->freeListSP[0] = 0;
    self->freeListSP[1] = 0;
    self->freeListSP[2] = 0;
    for (i = 0; i < n4; i++)
        self->freeList[0][self->freeListSP[0]++] = i;
    for (i = 0; i < n6; i++)
        self->freeList[1][self->freeListSP[1]++] = i;
    for (i = 0; i < n8; i++)
        self->freeList[2][self->freeListSP[2]++] = i;

    {
        sBzPts4_2B78*& r = self->pts4;
        r = new (D_00492788, 0, 0) sBzPts4_2B78[n4];
    }
    {
        sBzPts6_2B78*& r = self->pts6;
        r = new (D_00492798, 0, 0) sBzPts6_2B78[n6];
    }
    {
        sBzPts8_2B78*& r = self->pts8;
        r = new (D_004927A8, 0, 0) sBzPts8_2B78[n8];
    }
    {
        sBzUV4_2B78*& r = self->uvA4;
        r = new (D_004927B8, 0, 0) sBzUV4_2B78[n4];
    }
    {
        sBzUV6_2B78*& r = self->uvA6;
        r = new (D_004927C8, 0, 0) sBzUV6_2B78[n6];
    }
    {
        sBzUV8_2B78*& r = self->uvA8;
        r = new (D_004927D8, 0, 0) sBzUV8_2B78[n8];
    }
    {
        sBzUV4_2B78*& r = self->uvB4;
        r = new (D_004927E8, 0, 0) sBzUV4_2B78[n4];
    }
    {
        sBzUV6_2B78*& r = self->uvB6;
        r = new (D_004927F8, 0, 0) sBzUV6_2B78[n6];
    }
    {
        sBzUV8_2B78*& r = self->uvB8;
        r = new (D_00492808, 0, 0) sBzUV8_2B78[n8];
    }

    for (i = 0; i < 4; i++) {
        t4Vector b;
        t = i * 0.33333334f;
        b.x = t * t * t;
        b.y = t * t;
        b.z = t;
        b.w = 1.0f;
        self->basis4[i] = b;
    }
    for (i = 0; i < 6; i++) {
        t4Vector b;
        t = i * 0.2f;
        b.x = t * t * t;
        b.y = t * t;
        b.z = t;
        b.w = 1.0f;
        self->basis6[i] = b;
    }
    for (i = 0; i < 8; i++) {
        t4Vector b;
        t = i * 0.14285715f;
        b.x = t * t * t;
        b.y = t * t;
        b.z = t;
        b.w = 1.0f;
        self->basis8[i] = b;
    }
    self->basis[0] = self->basis4;
    self->basis[1] = self->basis6;
    self->basis[2] = self->basis8;
    self->order[0] = 4;
    self->order[1] = 6;
    self->order[2] = 8;
    self->nrmCacheSize[0] = nn4;
    self->nrmCacheSize[1] = nn6;
    self->nrmCacheSize[2] = nn8;

    for (k = 0; k < 3; k++) {
        int j;
        for (j = 0; j < self->cacheSize[k]; j++)
            self->records[k][j].f8 = -1;
    }

    if (nn4 > 0)
        {
        sBzPts4_2B78*& r = self->nrm4;
        r = new (D_00492818, 0, 0) sBzPts4_2B78[nn4];
    }
    if (nn6 > 0)
        {
        sBzPts6_2B78*& r = self->nrm6;
        r = new (D_00492828, 0, 0) sBzPts6_2B78[nn6];
    }
    if (nn8 > 0)
        {
        sBzPts8_2B78*& r = self->nrm8;
        r = new (D_00492838, 0, 0) sBzPts8_2B78[nn8];
    }
    if (nn4 > 0)
        self->nrmFreeBuf4 = new (D_00492848, 0, 0) int[nn4];
    if (nn6 > 0)
        self->nrmFreeBuf6 = new (D_00492858, 0, 0) int[nn6];
    if (nn8 > 0)
        self->nrmFreeBuf8 = new (D_00492868, 0, 0) int[nn8];
    self->nrmFreeList[0] = self->nrmFreeBuf4;
    self->nrmFreeList[1] = self->nrmFreeBuf6;
    self->nrmFreeList[2] = self->nrmFreeBuf8;
    self->nrmFreeListSP[0] = 0;
    self->nrmFreeListSP[1] = 0;
    self->nrmFreeListSP[2] = 0;
    for (i = 0; i < nn4; i++)
        self->nrmFreeList[0][self->nrmFreeListSP[0]++] = i;
    for (i = 0; i < nn6; i++)
        self->nrmFreeList[1][self->nrmFreeListSP[1]++] = i;
    for (i = 0; i < nn8; i++)
        self->nrmFreeList[2][self->nrmFreeListSP[2]++] = i;

    for (i = 0; i < 4; i++) {
        t4Vector b;
        t = i * 0.33333334f;
        b.x = t * (t * 3.0f);
        b.y = t + t;
        b.z = 1.0f;
        b.w = 0.0f;
        self->dbasis4[i] = b;
    }
    for (i = 0; i < 6; i++) {
        t4Vector b;
        t = i * 0.2f;
        b.x = t * (t * 3.0f);
        b.y = t + t;
        b.z = 1.0f;
        b.w = 0.0f;
        self->dbasis6[i] = b;
    }
    for (i = 0; i < 8; i++) {
        t4Vector b;
        t = i * 0.14285715f;
        b.x = t * (t * 3.0f);
        b.y = t + t;
        b.z = 1.0f;
        b.w = 0.0f;
        self->dbasis8[i] = b;
    }
    self->dbasis[0] = self->dbasis4;
    self->dbasis[1] = self->dbasis6;
    self->dbasis[2] = self->dbasis8;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003737D0);
#ifdef SKIP_ASM
struct sPtBufs_37D0 {
    void* p[3];
};

struct sPtSys_37D0 {
    char pad0[0xC];
    sPtBufs_37D0 b0C;       // 0x0C
    char pad18[0xC];
    sPtBufs_37D0 b24;       // 0x24
    char pad30[0x18];
    sPtBufs_37D0 b48;       // 0x48
    sPtBufs_37D0 b54;       // 0x54
    sPtBufs_37D0 b60;       // 0x60
    char pad6C[0x148];
    sPtBufs_37D0 b1B4;      // 0x1B4
    sPtBufs_37D0 b1C0;      // 0x1C0
};

#define PT_FREE_BUFS_37D0(t) \
    if ((t).p[0]) cMemMan_free((t).p[0]); \
    if ((t).p[1]) cMemMan_free((t).p[1]); \
    if ((t).p[2]) cMemMan_free((t).p[2]); \
    (t).p[0] = 0; \
    (t).p[1] = 0; \
    (t).p[2] = 0

// Frees the seven three-buffer sets and clears their pointers.
extern "C" void func_003737D0(sPtSys_37D0* self)
{
    PT_FREE_BUFS_37D0(self->b0C);
    PT_FREE_BUFS_37D0(self->b24);
    PT_FREE_BUFS_37D0(self->b48);
    PT_FREE_BUFS_37D0(self->b54);
    PT_FREE_BUFS_37D0(self->b60);
    PT_FREE_BUFS_37D0(self->b1B4);
    PT_FREE_BUFS_37D0(self->b1C0);
}
#endif

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

extern "C" void func_003739D0(sPtPools39D0* self)
{
    int n0 = self->cnt[0];
    int n1 = self->cnt[1];
    int n2 = self->cnt[2];
    func_003E6448(self->elems[0], 0, n0 * 0xC);
    func_003E6448(self->elems[1], 0, n1 * 0xC);
    func_003E6448(self->elems[2], 0, n2 * 0xC);
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
INCLUDE_ASM("render/particle", func_00373C28);
#ifdef SKIP_ASM

static inline float ptBlend_3C28(sPtVec3* p, sPtMatrixU* mt, float* w, int j)
{
    float x = p->x;
    float y = p->y;
    float z = p->z;
    return (mt[0].m[0][j] * x + mt[0].m[1][j] * y + mt[0].m[2][j] * z + mt[0].m[3][j]) * w[0]
         + (mt[1].m[0][j] * x + mt[1].m[1][j] * y + mt[1].m[2][j] * z + mt[1].m[3][j]) * w[1]
         + (mt[2].m[0][j] * x + mt[2].m[1][j] * y + mt[2].m[2][j] * z + mt[2].m[3][j]) * w[2]
         + (mt[3].m[0][j] * x + mt[3].m[1][j] * y + mt[3].m[2][j] * z + mt[3].m[3][j]);
}

// Blends p through four matrices: out = M0 p * w[0] + M1 p * w[1] + M2 p * w[2] + M3 p
// (rows 0-2 scale x, y, z; row 3 is the translation).
extern "C" void func_00373C28(void* self, sPtVec3* p, sPtMatrixU* mt, float* w, float* out)
{
    out[0] = ptBlend_3C28(p, mt, w, 0);
    out[1] = ptBlend_3C28(p, mt, w, 1);
    out[2] = ptBlend_3C28(p, mt, w, 2);
}
#endif
//100%
INCLUDE_ASM("render/particle", func_00373EA8);
#ifdef SKIP_ASM

static inline float ptBlend4_3EA8(sPtVec4u* p, sPtMatrixU* mt, float* w, int j)
{
    float x = p->x;
    float y = p->y;
    float z = p->z;
    float h = p->w;
    return (mt[0].m[0][j] * x + mt[0].m[1][j] * y + mt[0].m[2][j] * z + mt[0].m[3][j] * h) * w[0]
         + (mt[1].m[0][j] * x + mt[1].m[1][j] * y + mt[1].m[2][j] * z + mt[1].m[3][j] * h) * w[1]
         + (mt[2].m[0][j] * x + mt[2].m[1][j] * y + mt[2].m[2][j] * z + mt[2].m[3][j] * h) * w[2]
         + (mt[3].m[0][j] * x + mt[3].m[1][j] * y + mt[3].m[2][j] * z + mt[3].m[3][j] * h) * w[3];
}

// Blends the homogeneous point p through four matrices weighted by w[0..3]; writes x, y, z.
extern "C" void func_00373EA8(void* self, sPtVec4u* p, sPtMatrixU* mt, float* w, float* out)
{
    out[0] = ptBlend4_3EA8(p, mt, w, 0);
    out[1] = ptBlend4_3EA8(p, mt, w, 1);
    out[2] = ptBlend4_3EA8(p, mt, w, 2);
}
#endif
//100%
INCLUDE_ASM("render/particle", func_00374180);
#ifdef SKIP_ASM

struct sPatchSet {
    char pad_0x00[0x190];
    t4Vector* basis[3];    // 0x190
    int count[3];           // 0x19C
};

// PORT: PS2-only VU0 inline asm (tensor-product patch evaluation: out[i][j] =
// sum over basis[i] (x) basis[j] of the 4x4 control block at mat+0x40).
extern "C" void func_00374180(sPatchSet* self, char* mat, sPtVec3* out, int idx)
{
    int n = self->count[idx];
    t4Vector* basis = self->basis[idx];
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
            t4Vector t;
            __asm__(
                "lqc2      $vf22, 0x0(%1)\n"
                "vmulax.xyzw ACC, $vf18, $vf22x\n"
                "vmadday.xyzw ACC, $vf19, $vf22y\n"
                "vmaddaz.xyzw ACC, $vf20, $vf22z\n"
                "vmaddw.xyzw $vf23, $vf21, $vf22w\n"
                "sqc2      $vf23, %0\n"
                : "=m"(t)
                : "r"(&basis[j]));
            *out++ = *(sPtVec3*)&t;
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
    t4Vector* basis[3];    // 0x190
    int count[3];               // 0x19C
    char pad_0x1A8[0x310 - 0x1A8];
    t4Vector* dbasis[3];   // 0x310
};

// PORT: PS2-only VU0 inline asm (tensor-product patch evaluation, then normals
// as the normalised cross product of the two partial derivatives).
extern "C" void func_00374518(sPatchSet4518* self, char* mat, sPatchOut4518* out, int idx)
{
    int n = self->count[idx];
    t4Vector* basis = self->basis[idx];
    t4Vector* dbasis = self->dbasis[idx];
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
            t4Vector t;
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
            t4Vector t;
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
    sPtVec3 (*pos0)[16];          // 0x48
    sPtVec3 (*pos1)[36];          // 0x4C
    sPtVec3 (*pos2)[64];          // 0x50
    sPtVec2 (*uv0)[16];           // 0x54
    sPtVec2 (*uv1)[36];           // 0x58
    sPtVec2 (*uv2)[64];           // 0x5C
    sPtVec2 (*col0)[16];          // 0x60
    sPtVec2 (*col1)[36];          // 0x64
    sPtVec2 (*col2)[64];          // 0x68
    char pad_0x6C[0x1B4 - 0x6C];
    sPtVec3 (*nrm0)[16];          // 0x1B4
    sPtVec3 (*nrm1)[36];          // 0x1B8
    sPtVec3 (*nrm2)[64];          // 0x1BC
    char pad_0x1C0[0xC];
    int* nfreeList[3];              // 0x1CC
    int nfreeCount[3];              // 0x1D8
};

// func_00374518 is declared through a local view so the unit's own definition keeps its types
extern "C" void func_00374518_47A0(sPMgr_47A0* self, char* mat, sPtVec3* out, int idx) __asm__("func_00374518");

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

static inline sPtVec3* PosOf_47A0(sPMgr_47A0* self, int idx, int slot)
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

static inline sPtVec2* UVOf_47A0(sPMgr_47A0* self, int idx, int slot)
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

static inline sPtVec2* ColOf_47A0(sPMgr_47A0* self, int idx, int slot)
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

static inline sPtVec3* NrmOf_47A0(sPMgr_47A0* self, int idx, int slot)
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
    sPtVec3* pos = PosOf_47A0(self, idx, slot);
    sPtVec2* uv = UVOf_47A0(self, idx, slot);
    sPtVec2* col = ColOf_47A0(self, idx, slot);
    func_00374180((sPatchSet*)self, mat, (sPtVec3*)pos, idx);
    func_00374298((char*)self, mat, (sV2_4298*)uv, idx);
    func_00374440((char*)self, (sPtRect*)mat, (sPtVec2*)col, idx);
    sPEnt_47A0* e = &self->entries[idx][slot];
    e->mat = mat;
    *(short*)(mat + (idx << 1) + 0x1A6) = slot;
    e->flags |= 0xC | (1 << bit);
    if (normals) {
        int nslot = self->nfreeList[idx][--self->nfreeCount[idx]];
        sPtVec3* nrm = NrmOf_47A0(self, idx, nslot);
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
void operator_delete(int* ptr);

extern "C" void func_00375918(void* self, int flags)
{
    char* s = (char*)self;
    int tex = *(int*)(s + 0x170);
    if (tex >= 0) {
        func_00367B60(D_004A5B80->texset, tex);
        char* mgr = (char*)D_004A5B80;
        sPtVtVI* vt = *(sPtVtVI**)(mgr + 0x10D8);
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

extern "C" void func_00375990(void* self)
{
    char* s = (char*)self;
    if (*(int*)(s + 0x170) < 0) {
        char* mgr = (char*)D_004A5B80;
        sPtVtIIII* vt = *(sPtVtIIII**)(mgr + 0x10D8);
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
extern "C" void func_00423BF0(int);
extern "C" void func_00423BB0(int);
extern "C" void func_00423DB0(int);
extern "C" void func_00367360(void*);
void* func_00361F40(void* self);
void operator_delete(int* ptr);

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

struct sPtGfx65B8 {
    char pad_0x0[0x10DC];
    int curView;                    // 0x10DC
    char pad_0x10E0[0x18F0 - 0x10E0];
    char* keys;                     // 0x18F0
    char pad_0x18F4[0x5780 - 0x18F4];
    sPtMatrix m5780;               // 0x5780
    sPtMatrix m57C0;               // 0x57C0
    sPtMatrix m5800;               // 0x5800
    sPtQuadF q5840;                 // 0x5840
    sPtQuadF q5850;                 // 0x5850
    sPtMatrix m5860;               // 0x5860
    sPtMatrix m58A0;               // 0x58A0
    sPtQuadF q58E0;                 // 0x58E0
    sPtQuadF q58F0;                 // 0x58F0
    sPtScissor scissor;            // 0x5900
    float f5908;                    // 0x5908
    float f590C;                    // 0x590C
    float f5910;                    // 0x5910
    char pad_0x5914[0xC];
    sPtQuadF q5920;                 // 0x5920
    char pad_0x5930[0x6AF0 - 0x5930];
    sPtMatrix m6AF0;               // 0x6AF0
    char pad_0x6B30[0x40];
    sPtQuadF q6B70;                 // 0x6B70
    sPtQuadF q6B80;                 // 0x6B80
    char pad_0x6B90[0x6D20 - 0x6B90];
    sPtView views[1];           // 0x6D20
};

extern "C" void func_003950C0(sPtView* dst, sPtView* src);

extern "C" void func_003765B8(sPtGfx65B8* self)
{
    sPtView* v = &self->views[self->curView];
    v->scissor = self->scissor;
    v->key = *(int*)(self->keys + 0x69CC4);
    v->f24 = self->f590C;
    v->f28 = self->f5908;
    vu0CopyMtx(&v->m60, &self->m6AF0);
    v->q30 = self->q6B70;
    v->q40 = self->q6B80;
    vu0CopyMtx(&v->mA0, &self->m5780);
    vu0CopyMtx(&v->mE0, &self->m57C0);
    vu0CopyMtx(&v->m120, &self->m5800);
    v->q160 = self->q5840;
    v->q170 = self->q5850;
    vu0CopyMtx(&v->m180, &self->m5860);
    vu0CopyMtx(&v->m1C0, &self->m58A0);
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

struct sPtGfx6768 {
    char pad_0x0[0x10DC];
    int curView;                    // 0x10DC
    char pad_0x10E0[0x18F0 - 0x10E0];
    char* keys;                     // 0x18F0
    char pad_0x18F4[0x5780 - 0x18F4];
    sPtMatrix m5780;               // 0x5780
    sPtMatrix m57C0;               // 0x57C0
    sPtMatrix m5800;               // 0x5800
    sPtQuadF q5840;                 // 0x5840
    sPtQuadF q5850;                 // 0x5850
    sPtMatrix m5860;               // 0x5860
    sPtMatrix m58A0;               // 0x58A0
    sPtQuadF q58E0;                 // 0x58E0
    sPtQuadF q58F0;                 // 0x58F0
    sPtScissor scissor;            // 0x5900
    float f5908;                    // 0x5908
    float f590C;                    // 0x590C
    float f5910;                    // 0x5910
    char pad_0x5914[0xC];
    sPtQuadF q5920;                 // 0x5920
    char pad_0x5930[0x6AF0 - 0x5930];
    sPtMatrix m6AF0;               // 0x6AF0
    char pad_0x6B30[0x40];
    sPtQuadF q6B70;                 // 0x6B70
    sPtQuadF q6B80;                 // 0x6B80
    int i6B90;                      // 0x6B90
    char pad_0x6B94[0x6D20 - 0x6B94];
    sPtView views[1];           // 0x6D20
};

extern "C" void func_00376768(sPtGfx6768* self)
{
    self->curView--;
    sPtView* v = &self->views[self->curView];
    self->scissor = v->scissor;
    if (v->key == -1) {
        func_00364B88(self->keys, &self->scissor);
    } else {
        *(int*)(self->keys + 0x69CC4) = v->key;
    }
    self->f590C = v->f24;
    self->f5908 = v->f28;
    vu0CopyMtx(&self->m6AF0, &v->m60);
    self->q6B70 = v->q30;
    self->q6B80 = v->q40;
    vu0CopyMtx(&self->m5780, &v->mA0);
    vu0CopyMtx(&self->m57C0, &v->mE0);
    vu0CopyMtx(&self->m5800, &v->m120);
    self->q5840 = v->q160;
    self->q5850 = v->q170;
    vu0CopyMtx(&self->m5860, &v->m180);
    vu0CopyMtx(&self->m58A0, &v->m1C0);
    self->q58E0 = v->q200;
    self->q58F0 = v->q210;
    self->f5910 = v->f2C;
    self->q5920 = v->q50;
    self->i6B90 = 0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00376938);
#ifdef SKIP_ASM

struct sPtGfx6938 {
    char pad_0x0[0x10D8];
    sPtVtI* vtable;         // 0x10D8
    char pad_0x10DC[0x5900 - 0x10DC];
    unsigned short scissor[4];      // 0x5900: x, y, w, h
};

// Clips the rectangle to the screen (negative origins shrink the size) and stores it as the scissor box.
extern "C" void func_00376938(void* p, float x, float y, float w, float h)
{
    sPtGfx6938* self = (sPtGfx6938*)p;
    sPtVtI* e = &self->vtable[10];
    int width = e->fn((char*)self + e->delta);
    e = &self->vtable[11];
    int height = e->fn((char*)self + e->delta);
    if (x < 0.0f) {
        w += x;
        x = 0.0f;
    }
    if (y < 0.0f) {
        h += y;
        y = 0.0f;
    }
    int ix = (int)x;
    self->scissor[0] = ix < width - 1 ? ix : width - 1;
    int iy = (int)y;
    self->scissor[1] = iy < height - 1 ? iy : height - 1;
    int iw = (int)w;
    int maxw = width - self->scissor[0];
    int rw;
    if (iw >= 0) {
        rw = maxw < iw ? maxw : iw;
    } else {
        rw = 0;
    }
    self->scissor[2] = rw;
    int ih = (int)h;
    int maxh = height - self->scissor[1];
    int rh;
    if (ih >= 0) {
        rh = maxh < ih ? maxh : ih;
    } else {
        rh = 0;
    }
    self->scissor[3] = rh;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/particle", func_00376A70);
#ifdef SKIP_ASM

struct sPtView6A70 {
    float x, y, w, h;               // 0x6D20 in the first view
    char pad_0x10[0x220];
};

struct sPtGfx6A70 {
    char pad_0x0[0x10D8];
    sPtVtI* vtable;         // 0x10D8
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

extern "C" void func_00376A70(sPtGfx6A70* self, float x, float y, float w, float h)
{
    sPtVtI* e = &self->vtable[11];
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

extern "C" sPtVec4u* func_00376B90(sPtVec4u* r, void* self)
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

//100%
INCLUDE_ASM("render/particle", func_00376C58);
#ifdef SKIP_ASM
struct sPtView6C58 {
    float x, y, w, h;               // 0x00
    float zNear;                    // 0x10
    float zFar;                     // 0x14
    float fov;                      // 0x18
    float depth;                    // 0x1C
    int f20;                        // 0x20
    char pad_0x24[0x230 - 0x24];
};

struct sPtVtU6C58 {
    short delta;
    short index;
    unsigned (*fn)(void*);
};

struct sPtGfx6C58 {
    char pad_0x0[0x10D8];
    sPtVtU6C58* vtable;             // 0x10D8
    int curView;                    // 0x10DC
    char pad_0x10E0[0x57C0 - 0x10E0];
    sPtMatrix m57C0;                // 0x57C0
    char pad_0x5800[0x5840 - 0x5800];
    sPtQuadF q5840;                 // 0x5840
    sPtQuadF q5850;                 // 0x5850
    sPtMatrix m5860;                // 0x5860
    char pad_0x58A0[0x58E0 - 0x58A0];
    sPtQuadF q58E0;                 // 0x58E0
    sPtQuadF q58F0;                 // 0x58F0
    char pad_0x5900[0x8];
    float fov;                      // 0x5908
    float zFar;                     // 0x590C
    float f5910;                    // 0x5910
    char pad_0x5914[0xC];
    sPtQuadF q5920;                 // 0x5920
    char pad_0x5930[0x5A40 - 0x5930];
    int mode;                       // 0x5A40
    char pad_0x5A44[0x6AF0 - 0x5A44];
    sPtMatrix m6AF0;                // 0x6AF0
    char pad_0x6B30[0x40];
    sPtQuadF q6B70;                 // 0x6B70
    sPtQuadF q6B80;                 // 0x6B80
    int texReady;                   // 0x6B90
    int clampMode;                  // 0x6B94
    float clampTop;                 // 0x6B98
    float clampBottom;              // 0x6B9C
    float scaleX;                   // 0x6BA0
    float scaleY;                   // 0x6BA4
    char pad_0x6BA8[0x6D20 - 0x6BA8];
    sPtView6C58 views[1];           // 0x6D20
};

// PORT: the unit declares func_0031BE50 as (s, c, angle); its real parameter order is (angle, s, c).
extern void SinCos_6C58(float angle, float* s, float* c) __asm__("func_0031BE50");
extern "C" float func_0040D588(float x);
extern "C" void func_00376938(void* self, float x, float y, float w, float h);

// PORT: SN abs.s asm helper (PS2 FPU).
static inline float fsAbs_6C58(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// Scales a projection pair by the active letterbox mode's factors.
static inline void ClampScale6C58(sPtGfx6C58* self, float& x, float& y)
{
    int mode = self->clampMode;
    if (mode < 3) {
        if (mode >= 0) {
            x *= self->scaleX;
            y *= self->scaleY;
        }
    }
}

extern "C" void func_00376C58(sPtGfx6C58* self, float fov, float zNear, float zFar)
{
    sPtView6C58* v = &self->views[self->curView];
    v->f20 = 0;
    v->zNear = zNear;
    v->zFar = zFar;
    v->fov = fov;
    // PORT: int-arithmetic view address (as in func_00376C10); the typed self->views[i] reads score 94-95%.
    char* p = (char*)self + self->curView * 0x230;
    float x = *(float*)(p + 0x6D20);
    float y = *(float*)(p + 0x6D24);
    float w = *(float*)(p + 0x6D28);
    float h = *(float*)(p + 0x6D2C);
    float zlo, zhi, zscale;
    if (self->mode == 0x31) {
        zscale = 16777215.0f;
        zlo = -8388467.5f;
        zhi = 8388467.5f;
    } else {
        zscale = 65535.0f;
        zlo = -32767.5f;
        zhi = 32767.5f;
    }
    self->zFar = zFar;
    self->fov = fov;
    sPtVtU6C58* e = &self->vtable[11];
    unsigned height = e->fn((char*)self + e->delta);
    e = &self->vtable[10];
    unsigned width = e->fn((char*)self + e->delta);
    float aspect = (float)height * 1.3333334f / (float)width;
    float s, c;
    SinCos_6C58(fov, &s, &c);
    float sx = (w * 0.5f) / (s / c);
    float sy = sx * aspect;
    ClampScale6C58(self, sx, sy);
    e = &self->vtable[10];
    float offX = 32768.0f - (float)(e->fn((char*)self + e->delta) * 8);
    e = &self->vtable[11];
    float offY = 32768.0f - (float)(e->fn((char*)self + e->delta) * 8);
    float zA = (-zscale * zNear) / (zFar - zNear);
    self->m6AF0.m[0][0] = sx * 16.0f;
    self->m6AF0.m[1][0] = 0.0f;
    self->m6AF0.m[2][0] = (w * 0.5f + x) * 16.0f + offX;
    self->m6AF0.m[3][0] = 0.0f;
    self->m6AF0.m[0][1] = 0.0f;
    self->m6AF0.m[1][1] = -sy * 16.0f;
    self->m6AF0.m[2][1] = (h * 0.5f + y) * 16.0f + offY;
    self->m6AF0.m[3][1] = 0.0f;
    self->m6AF0.m[0][2] = 0.0f;
    self->m6AF0.m[1][2] = 0.0f;
    self->m6AF0.m[2][2] = zA;
    float zB = -zFar * zA + v->depth;
    self->m6AF0.m[3][2] = zB;
    self->m6AF0.m[0][3] = 0.0f;
    self->m6AF0.m[1][3] = 0.0f;
    self->m6AF0.m[2][3] = 1.0f;
    self->m6AF0.m[3][3] = 0.0f;
    self->q6B70.v[0] = x * 16.0f + offX;
    self->q6B70.v[1] = y * 16.0f + offY;
    self->q6B70.v[2] = zA * zNear + zB;
    self->q6B80.v[0] = (x + w) * 16.0f + offX;
    self->q6B80.v[1] = (y + h) * 16.0f + offY;
    self->q6B80.v[2] = zA * zFar + zB;
    self->q6B70.v[3] = 1.0f / zNear;
    self->q6B80.v[3] = 1.0f / zFar;
    self->texReady = 0;
    float aspect2 = aspect * (w / h);
    float px = 1.0f / func_0040D588(fov);
    float py = 1.0f / func_0040D588(fov) * aspect2;
    ClampScale6C58(self, px, py);
    e = &self->vtable[10];
    float sw = (float)e->fn((char*)self + e->delta);
    float cx = (w * 0.5f - sw * 0.5f) + x;
    e = &self->vtable[11];
    float sh = (float)e->fn((char*)self + e->delta);
    float cy = (h * 0.5f - sh * 0.5f) + y;
    float zz = (zFar + zNear) / (zFar - zNear);
    float zw = -(2.0f * zFar * zNear) / (zFar - zNear);
    self->m5860.m[0][0] = px;
    self->m5860.m[0][1] = 0.0f;
    self->m5860.m[0][2] = 0.0f;
    self->m5860.m[0][3] = 0.0f;
    self->m5860.m[1][0] = 0.0f;
    self->m5860.m[1][1] = py;
    self->m5860.m[1][2] = 0.0f;
    self->m5860.m[1][3] = 0.0f;
    self->m5860.m[2][0] = 0.0f;
    self->m5860.m[2][1] = 0.0f;
    self->m5860.m[2][2] = zz;
    self->m5860.m[2][3] = 1.0f;
    self->m5860.m[3][0] = 0.0f;
    self->m5860.m[3][1] = 0.0f;
    self->m5860.m[3][2] = zw;
    self->m5860.m[3][3] = 0.0f;
    self->q58E0.v[0] = w * 0.5f;
    self->q58E0.v[1] = -(h * 0.5f);
    self->q58E0.v[2] = zlo;
    self->q58E0.v[3] = 0.0f;
    self->q58F0.v[0] = cx + 2047.5f;
    self->q58F0.v[1] = cy + 2047.5f;
    self->q58F0.v[2] = zhi + v->depth;
    self->q58F0.v[3] = 0.0f;
    float gw = 2048.0f - 2.0f * fsAbs_6C58(cx);
    float gh = 2048.0f - 2.0f * fsAbs_6C58(cy);
    self->m57C0.m[0][0] = (w / gw) * px;
    self->m57C0.m[0][1] = 0.0f;
    self->m57C0.m[0][2] = 0.0f;
    self->m57C0.m[0][3] = 0.0f;
    self->m57C0.m[1][0] = 0.0f;
    self->m57C0.m[1][1] = (h / gh) * py;
    self->m57C0.m[1][2] = 0.0f;
    self->m57C0.m[1][3] = 0.0f;
    self->m57C0.m[2][0] = 0.0f;
    self->m57C0.m[2][1] = 0.0f;
    self->m57C0.m[2][2] = zz;
    self->m57C0.m[2][3] = 1.0f;
    self->m57C0.m[3][0] = 0.0f;
    self->m57C0.m[3][1] = 0.0f;
    self->m57C0.m[3][2] = zw;
    self->m57C0.m[3][3] = 0.0f;
    self->q5840.v[0] = gw * 0.5f;
    self->q5840.v[1] = -(gh * 0.5f);
    self->q5840.v[2] = zlo;
    self->q5840.v[3] = 0.0f;
    self->q5850.v[0] = cx + 2047.5f;
    self->q5850.v[1] = cy + 2047.5f;
    self->q5850.v[2] = zhi + v->depth;
    self->q5850.v[3] = 0.0f;
    func_00376938(self, x, y, w, h);
    self->f5910 = 40000.0f;
    self->q5920.v[0] = 1023.0f;
    self->q5920.v[1] = 0.0f;
    self->q5920.v[2] = 0.0f;
    self->q5920.v[3] = 1023.0f / 40000.0f;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00377278);
#ifdef SKIP_ASM
struct sPt7278 {
    float x, y, z, w;
    sPt7278() {}
    sPt7278(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
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
    sPtMatrix m58A0;                 // 0x58A0
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
static inline sPt7278 MulMat7278(const sPtMatrix* m, const sPt7278& v)
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

//100%
INCLUDE_ASM("render/particle", func_00377A10);
#ifdef SKIP_ASM

struct sVE_7A10 {
    short delta;
    short index;
    unsigned int (*fn)(void*);
};

struct sVE2_7A10 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sVE3_7A10 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sRect_7A10 {
    int x;
    int y;
    float w;
    float h;
};

struct sGfx_7A10 {
    char pad0[0xE84];
    sPtRenderState* top;            // 0xE84
    char pad1[0x10D8 - 0xE88];
    char* vt;                   // 0x10D8
    char pad2[0x18F0 - 0x10DC];
    void* ring;                 // 0x18F0
    void* sys;                  // 0x18F4
    char pad3[0x5A00 - 0x18F8];
    int f5A00;
    int f5A04;
    int f5A08;
    int f5A0C;
    int f5A10;
    int f5A14;
    int f5A18;
    int f5A1C;
    int f5A20;
    int f5A24;
    char pad4[0x5A90 - 0x5A28];
    volatile int slot[2];              // 0x5A90
    volatile int cur;                  // 0x5A98
    int f5A9C;
    int f5AA0;
    volatile int next;                 // 0x5AA4
    int f5AA8;
    int f5AAC;
    int f5AB0;
    int f5AB4;
    char pad5[0x5AC8 - 0x5AB8];
    int f5AC8;
    int f5ACC;
};

extern "C" void func_00363490(void* ring, void* a, void* b, void* c, void* d);
extern "C" int func_00423DE0_i(int a) __asm__("func_00423DE0");
extern "C" void func_00423DC0(int a);
extern "C" void func_004247D8(int a, int b);
extern "C" void func_00362CC8(void* ring);
extern "C" void func_003673D0(void* sys) __asm__("func_003673D0__FPv");
extern "C" void func_00361F90(void* p) __asm__("func_00361F90__FPv");

static inline void setView_7A10(sGfx_7A10* self)
{
    sVE2_7A10* v2 = (sVE2_7A10*)(self->vt + 0xC0);
    void (**fnp)(void*, void*, int) = &v2->fn;
    char* th = (char*)self + v2->delta;
    float fw = (float)((sVE_7A10*)(self->vt + 0x50))->fn((char*)self + ((sVE_7A10*)(self->vt + 0x50))->delta);
    float fh = (float)((sVE_7A10*)(self->vt + 0x58))->fn((char*)self + ((sVE_7A10*)(self->vt + 0x58))->delta);
    sRect_7A10 r;
    r.w = fw;
    r.h = fh;
    r.x = 0;
    r.y = 0;
    (*fnp)(th, &r, 1);
}

extern "C" void func_00377A10(sGfx_7A10* self)
{
    setView_7A10(self);
    ((sVE3_7A10*)(self->vt + 0x1B0))->fn((char*)self + ((sVE3_7A10*)(self->vt + 0x1B0))->delta);
    int old0 = self->f5A00;
    int old1 = self->f5A14;
    int l1;
    int l2;
    func_00363490(self->ring, &self->f5A00, &l1, &self->f5A14, &l2);
    func_00423DE0_i(self->f5ACC);
    self->next = self->f5A10;
    self->f5AA8 = old0;
    self->f5AAC = l1;
    self->f5AB0 = old1;
    self->f5AB4 = l2;
    self->slot[self->next] = 2;
    func_00423DC0(self->f5ACC);
    func_00423DC0(self->f5AC8);
    int x1 = self->f5A10 == 0;
    int x2 = self->f5A24 == 0;
    int b = self->f5A0C + x1 * 0xCCC80;
    int c = self->f5A20 + x2 * 0x26600;
    self->f5A10 = x1;
    self->f5A24 = x2;
    self->f5A04 = b;
    self->f5A00 = b;
    self->f5A18 = c;
    self->f5A14 = c;
    func_004247D8(b, b + 0xCCC80);
    func_004247D8(self->f5A14, self->f5A14 + 0x26600);
    *self->top = D_00501420_rs;
    func_00362CC8(self->ring);
    func_003673D0(self->sys);
    setView_7A10(self);
    func_00361F90(D_005059D8);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00377CF0);
#ifdef SKIP_ASM
typedef int cQuad128_CF0 __attribute__((mode(TI)));

// PORT: PS2-only VU0 inline asm (vector subtract); the PC port needs a C fallback.
static inline sPt7278 Sub_CF0(const sPt7278& a, const sPt7278& b)
{
    sPt7278 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline int Bits_CF0(float f)
{
    uPtFloatBits u;
    u.f = f;
    return u.i;
}

static inline int Outcode_CF0(cPS2GraphicsMan* self, const sPt7278& v)
{
    int c = 0;
    if (v.x < self->xmin)
        c = 2;
    if (self->xmax < v.x)
        c |= 1;
    if (v.y < self->ymin)
        c |= 8;
    if (self->ymax < v.y)
        c |= 4;
    if (v.w < 0.0f) {
        c ^= 0x2F;
    } else {
        if (v.z > self->zmin)
            c |= 0x20;
        if (v.z < self->zmax)
            c |= 0x10;
    }
    return c;
}

// PORT: PS2-only GS packet build and VU0 inline asm; uncached (0x30000000) pointers.
extern "C" void func_00377CF0(cPS2GraphicsMan* self, sPt7278* pos, float* size, int* uv0, int* uv1, float* color)
{
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    sPt7278 p = MulMat7278(&self->m6B30, *pos);
    float sx = size[0];
    float inv = 1.0f / p.w;
    float sy = size[1];
    p.x *= inv;
    p.y *= inv;
    float dx = self->f6AF0 * sx * inv;
    p.w = inv;
    float dy = self->f6B04 * sy * inv;
    sPt7278 d(dx, dy, 0.0f, 0.0f);
    sPt7278 a = Sub_CF0(p, d);
    sPt7278 b = Add7278(p, d);
    int ca = Outcode_CF0(self, a);
    int cb = Outcode_CF0(self, b);
    if ((ca & cb) == 0) {
        unsigned int buf = self->bufAddr;
        long* q = (long*)(buf | 0x30000000);
        *(cQuad128_CF0*)q = 0x10000005;
        q[3] = (long)0x50000004 << 32;
        q[2] = 0;
        q[4] = ((long)0x64000000 << 32) | 0x8001;
        q[5] = 0x525120;
        q[6] = 0x5E;
        q[7] = uv0[0] | ((long)uv0[1] << 32);
        long one = Bits_CF0(1.0f);
        q[8] = (long)(int)(color[1] * 128.0f) | ((long)(int)(color[2] * 128.0f) << 8) | ((long)(int)(color[3] * 128.0f) << 16) | ((long)(int)(color[0] * 128.0f) << 24) | (one << 32);
        q[9] = (int)a.x | ((long)(int)a.y << 16) | ((long)(int)(a.z * a.w) << 32);
        q[10] = uv1[0] | ((long)uv1[1] << 32);
        q[11] = (int)b.x | ((long)(int)b.y << 16) | ((long)(int)(b.z * b.w) << 32);
        q += 12;
        unsigned int next = (unsigned int)q & 0x0FFFFFFF;
        sPtRing* ring = self->ring;
        self->bufAddr = next;
        sPtRenderState* rs = self->top;
        if (ring->count < 0xA28) {
            rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
            int key = *(int*)((char*)ring + 0x69CC0);
            sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
            e->rs = *rs;
            e->buf = buf;
            e->next = next;
            e->key = key;
            e->flag = 0;
        }
        self->bufAddr += 0x10;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003781A0);
#ifdef SKIP_ASM
struct sVE_81A0 {
    short delta;
    short index;
    sPt7278 (*fn)(void*, const sPt7278*);
};

struct sGfx_81A0 {
    char pad_0x0[0xE84];
    sPtRenderState* top;                   // 0xE84
    char pad_0xE88[0x10D8 - 0xE88];
    sVE_81A0* vt;                   // 0x10D8
    char pad_0x10DC[0x13E4 - 0x10DC];
    float* cam;                     // 0x13E4
    char pad_0x13E8[0x18F0 - 0x13E8];
    sPtRing* ring;                // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x5A30 - 0x5A04];
    unsigned int vpW;               // 0x5A30
    unsigned int vpH;               // 0x5A34
    char pad_0x5A38[0x6B90 - 0x5A38];
    int texReady;                   // 0x6B90
};

// Rotates the xy part of a by the 4x4 matrix m (columns 0 and 1) into r.
static inline void Rot_81A0(sPt7278& r, float* m, const sPt7278& a)
{
    float x = a.x * m[0] + a.y * m[1];
    float y = a.x * m[4] + a.y * m[5];
    float z = a.x * m[8] + a.y * m[9];
    float w = a.x * m[12] + a.y * m[13];
    r.x = x;
    r.y = y;
    r.z = z;
    r.w = w;
}

extern "C" void func_0031BE50(float* s, float* c, float angle);

// PORT: PS2-only GS packet build; uncached (0x30000000) pointers.
extern "C" void func_003781A0(sGfx_81A0* self, float ang, sPt7278* pos, float* size, int* uvA, int* uvB, float* color, int n)
{
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    sPt7278 t0 = self->vt[92].fn((char*)self + self->vt[92].delta, pos);
    float s, c;
    func_0031BE50(&s, &c, ang);
    float* m = self->cam;
    sPt7278 v1;
    sPt7278 v2(c, s, 0.0f, 0.0f);
    Rot_81A0(v1, m, v2);
    Rot_81A0(v2, m, sPt7278(-v2.y, v2.x, v2.z, v2.w));
    sPt7278 p1 = Add7278(*pos, Scale7278(v1, size[0]));
    sPt7278 p2 = Add7278(*pos, Scale7278(v2, size[1]));
    p1.w = 1.0f;
    p2.w = 1.0f;
    sPt7278 q1 = Sub_CF0(self->vt[92].fn((char*)self + self->vt[92].delta, &p1), t0);
    sPt7278 q2 = Sub_CF0(self->vt[92].fn((char*)self + self->vt[92].delta, &p2), t0);
    sPt7278 c0 = Sub_CF0(Sub_CF0(t0, q1), q2);
    sPt7278 c1 = Sub_CF0(Add7278(t0, q1), q2);
    sPt7278 c2 = Add7278(Sub_CF0(t0, q1), q2);
    sPt7278 c3 = Add7278(Add7278(t0, q1), q2);
    unsigned int buf = self->bufAddr;
    long* q = (long*)(buf | 0x30000000);
    int ox = (0x800 - (self->vpW >> 1)) * 16;
    int oy = (0x800 - (self->vpH >> 1)) * 16;
    int x0 = ox + (int)(c0.x * 16.0f), y0 = oy + (int)(c0.y * 16.0f);
    int x1 = ox + (int)(c1.x * 16.0f), y1 = oy + (int)(c1.y * 16.0f);
    int x2 = ox + (int)(c2.x * 16.0f), y2 = oy + (int)(c2.y * 16.0f);
    int x3 = ox + (int)(c3.x * 16.0f), y3 = oy + (int)(c3.y * 16.0f);
    int z = (int)t0.z;
    int cg = (int)(color[1] * 128.0f);
    int cb = (int)(color[2] * 128.0f);
    int ca = (int)(color[3] * 128.0f);
    int cr = (int)(color[0] * 128.0f);
    for (int i = 0; i < n; i++) {
        q[0] = 0x10000007;
        q[1] = 0;
        q[2] = 0;
        q[3] = (long)0x50000006 << 32;
        q[4] = ((long)0xA4000000 << 32) | 0x8001;
        q[5] = 0x5252525210L;
        q[6] = 0x54;
        q[7] = (long)cg | ((long)cb << 8) | ((long)ca << 16) | ((long)cr << 24) | ((long)Bits_CF0(1.0f) << 32);
        q[8] = uvA[0] | ((long)uvA[1] << 32);
        q[9] = (long)x0 | ((long)y0 << 16) | ((long)z << 32);
        q[10] = uvB[0] | ((long)uvA[1] << 32);
        q[11] = (long)x1 | ((long)y1 << 16) | ((long)z << 32);
        q[12] = uvA[0] | ((long)uvB[1] << 32);
        q[13] = (long)x2 | ((long)y2 << 16) | ((long)z << 32);
        q[14] = uvB[0] | ((long)uvB[1] << 32);
        q[15] = (long)x3 | ((long)y3 << 16) | ((long)z << 32);
        q += 16;
    }
    unsigned int next = (unsigned int)q & 0x0FFFFFFF;
    sPtRing* ring = self->ring;
    self->bufAddr = next;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    self->bufAddr += 0x10;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00378808);
#ifdef SKIP_ASM
struct sGlyph8808 {
    unsigned short code;    // 0x0
    unsigned char w;        // 0x2
    unsigned char h;        // 0x3
    unsigned short u;       // 0x4
    unsigned short v;       // 0x6
    signed char adv;        // 0x8
    signed char xoff;       // 0x9
    signed char yoff;       // 0xA
    char pad;
};

struct sFontRes8808 {
    int count;              // 0x0
    sGlyph8808* table;      // 0x4
    sGlyph8808* def;        // 0x8
    int first;              // 0xC
    int last;               // 0x10
};

struct sView8808 {
    char pad_0x0[0x20];
    int mode;               // 0x20
    char pad_0x24[0x230 - 0x24];
};

struct sGfx8808 {
    char pad_0x0[0xE84];
    sPtRenderState* top;            // 0xE84
    char pad_0xE88[0x10DC - 0xE88];
    int curView;                    // 0x10DC
    char pad_0x10E0[0x18F0 - 0x10E0];
    sPtRing* ring;                  // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x6AF0 - 0x5A04];
    float f6AF0;                    // 0x6AF0
    char pad_0x6AF4[0x6B04 - 0x6AF4];
    float f6B04;                    // 0x6B04
    char pad_0x6B08[0x6B18 - 0x6B08];
    float f6B18;                    // 0x6B18
    char pad_0x6B1C[0x6B20 - 0x6B1C];
    float f6B20;                    // 0x6B20
    float f6B24;                    // 0x6B24
    float f6B28;                    // 0x6B28
    char pad_0x6B2C[0x6B30 - 0x6B2C];
    sPtMatrix m6B30;                // 0x6B30
    char pad_0x6B70[0x6B90 - 0x6B70];
    int texReady;                   // 0x6B90
    char pad_0x6B94[0x6D20 - 0x6B94];
    sView8808 views[1];             // 0x6D20
};

// Homogeneous position (w given) with a const-reference ctor: its stores, w included, go straight to the stack
// slot, where the by-value sPt7278 ctor keeps `this` in a register for a constant w.
struct sPtPos8808 : sPt7278 {
    sPtPos8808(const float& ax, const float& ay, const float& az, const float& aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

// Stores a two-float pair (uv, half size); both values are computed before either store.
static inline void Set2_8808(float* d, float a, float b)
{
    d[0] = a;
    d[1] = b;
}

// Glyph lookup: direct index for [first, last], binary search above, default glyph if not found.
static inline sGlyph8808* Find8808(sFontRes8808* f, int c)
{
    if (c < f->first)
        return 0;
    if (c <= f->last)
        return f->table + c - f->first;
    int lo = f->last - f->first;
    int hi = f->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph8808* p = f->table + mid;
        if (c == p->code)
            return p;
        if (c < p->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return f->def;
}

// PORT: PS2-only GS packet build and VU0 inline asm; uncached (0x30000000) pointers.
extern "C" void func_00378808(sGfx8808* self, sFontRes8808* font, char* s, float* color,
                              float x, float y, float sx, float sy, float su, float sv, float z)
{
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    unsigned int buf = self->bufAddr;
    unsigned long* p = (unsigned long*)(buf | 0x30000000);
    unsigned long* q = p + 10;
    int nloop = 0;
    if (self->views[self->curView].mode != 0) {
        float vz = self->f6B18 * z + self->f6B28;
        sPt7278 a;
        sPt7278 b;
        a.z = vz;
        a.w = 1.0f;
        b.z = vz;
        b.w = 1.0f;
        for (; *s; s++) {
            sGlyph8808* g = Find8808(font, (unsigned char)*s);
            if (g) {
                nloop++;
                float uv0[2];
                float uv1[2];
                Set2_8808(uv0, g->u * su, g->v * sv);
                Set2_8808(uv1, (g->u + g->w) * su, (g->v + g->h) * sv);
                a.x = (x + g->xoff * sx) * self->f6AF0 + self->f6B20;
                a.y = (y + g->yoff * sy) * self->f6B04 + self->f6B24;
                b.x = a.x + g->w * sx * self->f6AF0;
                b.y = a.y + g->h * sy * self->f6B04;
                q[0] = Bits_CF0(uv0[0]) | ((long)Bits_CF0(uv0[1]) << 32);
                q[1] = (int)a.x | ((long)(int)a.y << 16) | ((long)(int)a.z << 32);
                q[2] = Bits_CF0(uv1[0]) | ((long)Bits_CF0(uv1[1]) << 32);
                q[3] = (int)b.x | ((long)(int)b.y << 16) | ((long)(int)b.z << 32);
                q += 4;
                x += g->adv * sx;
            }
        }
    } else {
        for (; *s; s++) {
            sGlyph8808* g = Find8808(font, (unsigned char)*s);
            if (g) {
                nloop++;
                float uv0[2];
                float uv1[2];
                float size[2];
                Set2_8808(uv0, g->u * su, g->v * sv);
                Set2_8808(uv1, (g->u + g->w) * su, (g->v + g->h) * sv);
                Set2_8808(size, g->w * sx * 0.5f, g->h * sy * 0.5f);
                sPtPos8808 pos(x + g->xoff * sx + size[0], y + g->yoff * sy + size[1], z, 1.0f);
                sPt7278 v = MulMat7278(&self->m6B30, pos);
                float inv = 1.0f / v.w;
                v.x *= inv;
                v.y *= inv;
                float dx = self->f6AF0 * size[0] * inv;
                v.w = inv;
                float dy = self->f6B04 * size[1] * inv;
                sPt7278 d(dx, dy, 0.0f, 0.0f);
                sPt7278 a = Sub_CF0(v, d);
                sPt7278 b = Add7278(v, d);
                q[0] = Bits_CF0(uv0[0]) | ((long)Bits_CF0(uv0[1]) << 32);
                q[1] = (int)a.x | ((long)(int)a.y << 16) | ((long)(int)(a.z * a.w) << 32);
                q[2] = Bits_CF0(uv1[0]) | ((long)Bits_CF0(uv1[1]) << 32);
                q[3] = (int)b.x | ((long)(int)b.y << 16) | ((long)(int)(b.z * b.w) << 32);
                q += 4;
                x += g->adv * sx;
            }
        }
    }
    p[0] = (nloop * 2 + 4) | 0x10000000;
    p[1] = 0;
    p[2] = 0;
    p[3] = (unsigned long)((nloop * 2 + 3) | 0x50000000U) << 32;
    p[4] = 0x2400000000000001UL;
    p[5] = 0x10;
    p[6] = 0x56;
    p[7] = (long)(int)(color[1] * 204.0f) | ((long)(int)(color[2] * 204.0f) << 8) |
           ((long)(int)(color[3] * 204.0f) << 16) | ((long)(int)(color[0] * 128.0f) << 24) |
           ((long)Bits_CF0(1.0f) << 32);
    p[8] = (unsigned long)(nloop | 0x8000) | ((unsigned long)0x8800 << 47);
    p[9] = 0x5252;
    unsigned int next = (unsigned int)q & 0x0FFFFFFF;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    self->bufAddr = next + 0x10;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00379028);
#ifdef SKIP_ASM
struct sGlyph9028 {
    unsigned short code;    // 0x0
    unsigned char w;        // 0x2
    unsigned char h;        // 0x3
    unsigned short u;       // 0x4
    unsigned short v;       // 0x6
    signed char adv;        // 0x8
    signed char xoff;       // 0x9
    signed char yoff;       // 0xA
    char pad;
};

struct sFontRes9028 {
    int count;              // 0x0
    sGlyph9028* table;      // 0x4
    sGlyph9028* def;        // 0x8
    int first;              // 0xC
    int last;               // 0x10
};

struct sView9028 {
    char pad_0x0[0x20];
    int mode;               // 0x20
    char pad_0x24[0x230 - 0x24];
};

struct sGfx9028 {
    char pad_0x0[0xE84];
    sPtRenderState* top;            // 0xE84
    char pad_0xE88[0x10DC - 0xE88];
    int curView;                    // 0x10DC
    char pad_0x10E0[0x18F0 - 0x10E0];
    sPtRing* ring;                  // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x6AF0 - 0x5A04];
    float f6AF0;                    // 0x6AF0
    char pad_0x6AF4[0x6B04 - 0x6AF4];
    float f6B04;                    // 0x6B04
    char pad_0x6B08[0x6B18 - 0x6B08];
    float f6B18;                    // 0x6B18
    char pad_0x6B1C[0x6B20 - 0x6B1C];
    float f6B20;                    // 0x6B20
    float f6B24;                    // 0x6B24
    float f6B28;                    // 0x6B28
    char pad_0x6B2C[0x6B30 - 0x6B2C];
    sPtMatrix m6B30;                // 0x6B30
    char pad_0x6B70[0x6B90 - 0x6B70];
    int texReady;                   // 0x6B90
    char pad_0x6B94[0x6D20 - 0x6B94];
    sView9028 views[1];             // 0x6D20
};

// Homogeneous position (w given) with a const-reference ctor: its stores, w included, go straight to the stack
// slot, where the by-value sPt7278 ctor keeps `this` in a register for a constant w.
struct sPtPos9028 : sPt7278 {
    sPtPos9028(const float& ax, const float& ay, const float& az, const float& aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

// Stores a two-float pair (uv, half size); both values are computed before either store.
static inline void Set2_9028(float* d, float a, float b)
{
    d[0] = a;
    d[1] = b;
}

// Glyph lookup: direct index for [first, last], binary search above, default glyph if not found.
static inline sGlyph9028* Find9028(sFontRes9028* f, int c)
{
    if (c < f->first)
        return 0;
    if (c <= f->last)
        return f->table + c - f->first;
    int lo = f->last - f->first;
    int hi = f->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph9028* p = f->table + mid;
        if (c == p->code)
            return p;
        if (c < p->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return f->def;
}

// PORT: PS2-only GS packet build and VU0 inline asm; uncached (0x30000000) pointers.
extern "C" void func_00379028(sGfx9028* self, sFontRes9028* font, unsigned short* s, float* color,
                              float x, float y, float sx, float sy, float su, float sv, float z)
{
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    unsigned int buf = self->bufAddr;
    unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
    unsigned long* q = p + 10;
    int nloop = 0;
    if (self->views[self->curView].mode != 0) {
        float vz = self->f6B18 * z + self->f6B28;
        sPt7278 a;
        sPt7278 b;
        a.z = vz;
        a.w = 1.0f;
        b.z = vz;
        b.w = 1.0f;
        for (; *s; s++) {
            sGlyph9028* g = Find9028(font, *s);
            if (g) {
                nloop++;
                float uv0[2];
                float uv1[2];
                Set2_9028(uv0, g->u * su, g->v * sv);
                Set2_9028(uv1, (g->u + g->w) * su, (g->v + g->h) * sv);
                a.x = (x + g->xoff * sx) * self->f6AF0 + self->f6B20;
                a.y = (y + g->yoff * sy) * self->f6B04 + self->f6B24;
                b.x = a.x + g->w * sx * self->f6AF0;
                b.y = a.y + g->h * sy * self->f6B04;
                q[0] = Bits_CF0(uv0[0]) | ((long)Bits_CF0(uv0[1]) << 32);
                q[1] = (int)a.x | ((long)(int)a.y << 16) | ((long)(int)a.z << 32);
                q[2] = Bits_CF0(uv1[0]) | ((long)Bits_CF0(uv1[1]) << 32);
                q[3] = (int)b.x | ((long)(int)b.y << 16) | ((long)(int)b.z << 32);
                q += 4;
                x += g->adv * sx;
            }
        }
    } else {
        for (; *s; s++) {
            sGlyph9028* g = Find9028(font, *s);
            if (g) {
                nloop++;
                float uv0[2];
                float uv1[2];
                float size[2];
                Set2_9028(uv0, g->u * su, g->v * sv);
                Set2_9028(uv1, (g->u + g->w) * su, (g->v + g->h) * sv);
                Set2_9028(size, g->w * sx * 0.5f, g->h * sy * 0.5f);
                sPtPos9028 pos(x + g->xoff * sx + size[0], y + g->yoff * sy + size[1], z, 1.0f);
                sPt7278 v = MulMat7278(&self->m6B30, pos);
                float inv = 1.0f / v.w;
                v.x *= inv;
                v.y *= inv;
                float dx = self->f6AF0 * size[0] * inv;
                v.w = inv;
                float dy = self->f6B04 * size[1] * inv;
                sPt7278 d(dx, dy, 0.0f, 0.0f);
                sPt7278 a = Sub_CF0(v, d);
                sPt7278 b = Add7278(v, d);
                q[0] = Bits_CF0(uv0[0]) | ((long)Bits_CF0(uv0[1]) << 32);
                q[1] = (int)a.x | ((long)(int)a.y << 16) | ((long)(int)(a.z * a.w) << 32);
                q[2] = Bits_CF0(uv1[0]) | ((long)Bits_CF0(uv1[1]) << 32);
                q[3] = (int)b.x | ((long)(int)b.y << 16) | ((long)(int)(b.z * b.w) << 32);
                q += 4;
                x += g->adv * sx;
            }
        }
    }
    p[0] = (nloop * 2 + 4) | 0x10000000;
    p[1] = 0;
    p[2] = 0;
    p[3] = (unsigned long)((nloop * 2 + 3) | 0x50000000U) << 32;
    p[4] = 0x2400000000000001UL;
    p[5] = 0x10;
    p[6] = 0x56;
    p[7] = (long)(int)(color[1] * 204.0f) | ((long)(int)(color[2] * 204.0f) << 8) |
           ((long)(int)(color[3] * 204.0f) << 16) | ((long)(int)(color[0] * 128.0f) << 24) |
           ((long)Bits_CF0(1.0f) << 32);
    p[8] = (unsigned long)(nloop | 0x8000) | ((unsigned long)0x8800 << 47);
    p[9] = 0x5252;
    unsigned int next = func_0038F668(D_004A4474, q, 4);
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    self->bufAddr = next + 0x10;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
}
#endif

INCLUDE_ASM("render/particle", func_00379860);

INCLUDE_ASM("render/particle", func_00379BD0);

INCLUDE_ASM("render/particle", func_0037A260);

//100%
INCLUDE_ASM("render/particle", func_0037A430);
#ifdef SKIP_ASM

// PORT: uncached (0x30000000) pointers held in int.
// Flushes the pending packet into a ring entry and resets the render state's layer bits.
extern "C" void func_0037A430(cPS2GraphicsMan* self)
{
    unsigned int next = func_0038F668(D_004A4474, self->pend, 4);
    self->bufAddr = next;
    unsigned int buf = self->pendBuf;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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
        sPtVtI* vt = (sPtVtI*)e->vt;
        if (vt[2].fn((char*)e + vt[2].delta) == 0) {
            sPtVtVI* vt2 = (sPtVtVI*)e->vt;
            vt2[1].fn((char*)e + vt2[1].delta, 3);
            return 0;
        }
    }
    return e;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037A610);
#ifdef SKIP_ASM
extern char D_80[];
extern char D_70[];
extern char D_398[];
extern int D_004A4510;
extern int D_004A4530;

// The render-state record as this function sees it: bit-field words (f0 bits 4..5, 6..9 mode, 20..27 alpha; f4 test,
// layer, blend, ...; f8 bits 0..4 key, 10..28 depth; fC address) and two texture ids.
struct sRS_A610 {
    int f0;
    int f4;
    int f8;
    int fC;
    short tex;
    short tex2;
};

struct sPtVtVF {
    short delta;
    short index;
    void (*fn)(void*, float);
};

// One matrix list of a model chunk: count + bone indices.
struct sMtxList_A610 {
    int count;
    int* index;
};

// A DMA reference: packet address + data (each data block starts with its qword count).
struct sDmaRef_A610 {
    unsigned int addr;
    unsigned short* data;
};

struct sSub_A610 {
    sDmaRef_A610* refs;
    int count;
};

struct sChunk_A610 {
    unsigned int flags;         // 0x0
    int tex;                    // 0x4
    short texSlot;              // 0x8
    unsigned char alpha;        // 0xA
    char pad_0xB;
    int numSubs;                // 0xC
    sSub_A610* subs;            // 0x10
};

struct sMdl_A610 {
    char pad_0x0[0x20];
    int chunkOfs;               // 0x20
    char pad_0x24[0x3C - 0x24];
    sMtxList_A610* lists;       // 0x3C
    float* lodW;                // 0x40
    char pad_0x44[0x4];
    short numChunks;            // 0x48
    char pad_0x4A[0x50 - 0x4A];
    short numLods;              // 0x50
};

struct sGfx_A610 {
    char pad_0x0[0xE84];
    sRS_A610* top;                  // 0xE84
    char pad_0xE88[0x10B0 - 0xE88];
    int texSlots[(0x10D8 - 0x10B0) / 4];   // 0x10B0
    sPtVtVF* vtable;                // 0x10D8
    char pad_0x10DC[0x13E8 - 0x10DC];
    t4Matrix* bones;                // 0x13E8
    char pad_0x13EC[0x18F0 - 0x13EC];
    sPtRing* ring;                  // 0x18F0
    char pad_0x18F4[0x58A0 - 0x18F4];
    sPtMatrix m58A0;                // 0x58A0
    char pad_0x58E0[0x5920 - 0x58E0];
    sPtQuadF q5920;                 // 0x5920
    char pad_0x5930[0x5A00 - 0x5930];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x6B90 - 0x5A04];
    int texReady;                   // 0x6B90
};

extern "C" void func_0037CBC8_A610(void* self, int tex, int mode) __asm__("func_0037CBC8__FPv");

// PORT: PS2-only VU0 inline asm (matrix * vector, clamp, depth read back from vi1).
static inline int Depth_A610(sGfx_A610* self, t4Vector v)
{
    long r;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    __asm__ __volatile__(
        "lqc2      $vf5, %1\n"
        "lqc2      $vf10, %2\n"
        "lqc2      $vf1, 0x0(%3)\n"
        "lqc2      $vf2, 0x10(%3)\n"
        "lqc2      $vf3, 0x20(%3)\n"
        "lqc2      $vf4, 0x30(%3)\n"
        "vmulax.xyzw ACC, $vf1, $vf10x\n"
        "vmadday.xyzw ACC, $vf2, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf10z\n"
        "vmaddw.xyzw $vf11, $vf4, $vf10w\n"
        "vmulw.w    $vf11, $vf11, $vf5w\n"
        "vmaxx.w    $vf11, $vf11, $vf0x\n"
        "vminix.w   $vf11, $vf11, $vf5x\n"
        "vftoi0.xyzw $vf11, $vf11\n"
        "vmtir      $vi1, $vf11w\n"
        "cfc2.ni    %0, $vi1\n"
        : "=&r"(r)
        : "m"(self->q5920), "m"(v), "r"(&self->m58A0)
        : "memory");
    return (int)r;
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void CopyMtx_A610(void* dst, const void* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

// Inline copy of func_00396C30: uploads the list's matrices and calls the skinning program.
static inline void UploadMtx_A610(sMtxList_A610* list, t4Matrix* mats, unsigned long** cur)
{
    int n = list->count;
    int* idx = list->index;
    unsigned long* p = *cur;
    p[0] = (n * 4 + 2) | 0x10000000;
    p[1] = 0;
    p[2] = (unsigned long)0x8000 << 45;
    p[3] = ((unsigned long)(unsigned int)((n << 18) | 0x6C000011) << 32) | 0x1000101;
    p += 4;
    for (int i = 0; i < n; i++) {
        CopyMtx_A610(p, &mats[idx[i]]);
        p += 8;
    }
    p[0] = ((unsigned long)n << 32) | 0x600103FF;
    p[1] = (unsigned long)(((unsigned int)D_80 >> 3) | 0x14000000) | ((unsigned long)(((unsigned int)D_70 >> 3) | 0x14000000) << 32);
    p += 2;
    *cur = p;
}

// Sets the width-bit field at shift in a render-state word.
static inline void SetField_A610(int& w, int shift, int width, int v)
{
    int mask = ((1 << width) - 1) << shift;
    w = (w & ~mask) | ((v << shift) & mask);
}

static inline void SetTest_A610(sGfx_A610* self)
{
    if (D_004A4530 == 0) {
        SetField_A610(self->top->f4, 7, 5, 0x11);
    } else {
        SetField_A610(self->top->f4, 7, 5, 3);
    }
}

static inline void SetTex_A610(sGfx_A610* self, int t)
{
    self->top->tex = t;
}

static inline void SetTex2_A610(sGfx_A610* self, int t)
{
    self->top->tex2 = t;
}

#define MIN_A610(a, b) ((a) < (b) ? (a) : (b))

// PORT: PS2-only DMA/VIF packet build; uncached (0x30000000) pointers held in int.
extern "C" void func_0037A610(sGfx_A610* self, sMdl_A610* mdl, char* base, int shadow)
{
    if (D_004A4510 == 0) {
        self->top[1] = *self->top;
        self->top++;
        self->vtable[124].fn((char*)self + self->vtable[124].delta, 1.0f);
        if (self->texReady == 0) {
            func_0037D968(self);
        }
        int matIdx = 0;
        sChunk_A610* chunk = (sChunk_A610*)(base + mdl->chunkOfs);
        t4Matrix* bones = self->bones;
        SetTex2_A610(self, self->texSlots[chunk->texSlot]);
        SetField_A610(self->top->f0, 4, 2, 3);
        int z = MIN_A610(0x400, Depth_A610(self, bones->row[3]) + 0x10);
        if (shadow) {
            SetField_A610(self->top->f0, 20, 8, 0);
            SetField_A610(self->top->f4, 2, 5, 7);
            SetTest_A610(self);
            SetField_A610(self->top->f4, 0, 2, 2);
            SetField_A610(self->top->f8, 10, 19, z);
            SetField_A610(self->top->f4, 23, 2, 1);
            SetField_A610(self->top->f4, 20, 2, 0);
            SetField_A610(self->top->f4, 12, 8, 0x14);
        }
        for (int i = 0; i < mdl->numChunks; i++) {
            func_0037CBC8_A610(self, chunk->tex, 3);
            SetTex_A610(self, chunk->tex);
            if (!shadow) {
                if (chunk->flags & 0x8000) {
                    SetField_A610(self->top->f4, 2, 5, 5);
                    SetField_A610(self->top->f0, 20, 8, chunk->alpha);
                    SetField_A610(self->top->f4, 7, 5, 0xC);
                    SetField_A610(self->top->f4, 0, 2, 2);
                    SetField_A610(self->top->f8, 10, 19, z);
                    SetField_A610(self->top->f4, 23, 2, 1);
                    SetField_A610(self->top->f4, 20, 2, 3);
                    SetField_A610(self->top->f4, 12, 8, 0x5C);
                } else {
                    SetField_A610(self->top->f4, 2, 5, 1);
                    SetField_A610(self->top->f0, 20, 8, 0);
                    SetTest_A610(self);
                    SetField_A610(self->top->f4, 0, 2, 0);
                    SetField_A610(self->top->f8, 10, 19, 0);
                    SetField_A610(self->top->f4, 23, 2, 1);
                    SetField_A610(self->top->f4, 20, 2, 0);
                    SetField_A610(self->top->f4, 12, 8, 0x14);
                }
            }
            if (chunk->flags & 1) {
                unsigned int buf = self->bufAddr;
                unsigned long* p = (unsigned long*)(buf | 0x30000000);
                sMtxList_A610* list = &mdl->lists[matIdx];
                sSub_A610* send = chunk->subs + chunk->numSubs;
                for (sSub_A610* s = chunk->subs; s != send; list++, s++) {
                    UploadMtx_A610(list, bones, &p);
                    p[0] = ((unsigned long)s->refs->addr << 32) | 0x50000000;
                    p[1] = 0;
                    p += 2;
                }
                unsigned int next = (unsigned int)p & 0x0FFFFFFF;
                sPtRing* ring = self->ring;
                self->bufAddr = next;
                sRS_A610* rs = self->top;
                if (ring->count < 0xA28) {
                    rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
                    int key = *(int*)((char*)ring + 0x69CC0);
                    sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
                    *(sRS_A610*)&e->rs = *rs;
                    e->buf = buf;
                    e->next = next;
                    e->key = key;
                    e->flag = 0;
                }
                self->bufAddr += 0x10;
            } else if (chunk->flags & 0x100) {
                unsigned int buf = self->bufAddr;
                unsigned int prog = (unsigned int)D_398 >> 3;
                unsigned long* p = (unsigned long*)(buf | 0x30000000);
                int nlod = mdl->numLods;
                float* w = mdl->lodW;
                int found = 0;
                for (int j = 0; j < nlod; j++) {
                    if (w[j] > 0.01f) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    // scale stays a variable: the target rematerialises its bits per branch arm and carries them in a register
                    // into the second element (a literal folds into one 64-bit constant).
                    float scale = 12800.0f;
                    sMtxList_A610* list = &mdl->lists[matIdx];
                    sSub_A610* send = chunk->subs + chunk->numSubs;
                    for (sSub_A610* s = chunk->subs; s != send; list++, s++) {
                        UploadMtx_A610(list, bones, &p);
                        int n = s->count;
                        sDmaRef_A610* r = s->refs;
                        int even = (n & 1) == 0;
                        for (int k = 0; k < n; k += 2, r++) {
                            unsigned short* d1 = r->data;
                            p[0] = ((unsigned long)r->addr << 32) | 0x50000000;
                            p[1] = 0;
                            p[2] = ((unsigned long)(unsigned int)d1 << 32) | 0x50000001;
                            p[3] = 0;
                            p[4] = (unsigned long)0x640180B4 << 32;
                            if (w[0] < 0.0f) {
                                p[5] = (unsigned long)*(int*)&scale << 32;
                            } else {
                                p[5] = (long)*(int*)&w[0] | ((unsigned long)*(int*)&scale << 32);
                            }
                            p += 6;
                            if (even || k < n - 1) {
                                r++;
                            }
                            unsigned short* d2 = r->data;
                            p[0] = ((unsigned long)r->addr << 32) | 0x50000000;
                            p[1] = 0;
                            p[2] = ((unsigned long)(unsigned int)d2 << 32) | 0x50000001;
                            p[3] = 0;
                            p[4] = ((unsigned long)0x640180B4 << 32) | 0x11000000;
                            if (w[0] < 0.0f) {
                                p[5] = (unsigned long)*(int*)&scale << 32;
                            } else {
                                p[5] = (long)*(int*)&w[0] | ((unsigned long)*(int*)&scale << 32);
                            }
                            p += 6;
                            for (int j = 1; j < nlod; j++) {
                                d1 += (*d1 + 1) * 8;
                                d2 += (*d2 + 1) * 8;
                                if (w[j] > 0.01f) {
                                    p[0] = ((unsigned long)(unsigned int)d1 << 32) | 0x50000001;
                                    p[1] = 0;
                                    p[2] = (unsigned long)0x640180B4 << 32;
                                    p[3] = (long)*(int*)&w[j] | ((unsigned long)*(int*)&scale << 32);
                                    p[4] = ((unsigned long)(unsigned int)d2 << 32) | 0x50000001;
                                    p[5] = 0;
                                    p[6] = (unsigned long)0x640180B4 << 32;
                                    p[7] = (long)*(int*)&w[j] | ((unsigned long)*(int*)&scale << 32);
                                    p += 8;
                                }
                            }
                            p[0] = 0x10000001;
                            p[1] = 0;
                            p[2] = ((unsigned long)(prog | 0x14000000) << 32) | 0x11000000;
                            p[3] = ((unsigned long)(prog | 0x14000000) << 32) | 0x11000000;
                            p += 4;
                        }
                    }
                } else {
                    sMtxList_A610* list = &mdl->lists[matIdx];
                    sSub_A610* send = chunk->subs + chunk->numSubs;
                    for (sSub_A610* s = chunk->subs; s != send; list++, s++) {
                        UploadMtx_A610(list, bones, &p);
                        sDmaRef_A610* r = s->refs;
                        sDmaRef_A610* end = r + s->count;
                        p[0] = ((unsigned long)r->addr << 32) | 0x50000000;
                        p[1] = 0;
                        p += 2;
                        for (r++; r != end; r++) {
                            p[0] = ((unsigned long)r->addr << 32) | 0x50000001;
                            p[1] = 0;
                            p[2] = (unsigned long)0x11000000 << 32;
                            p[3] = (unsigned long)(prog | 0x14000000) << 32;
                            p += 4;
                        }
                        p[0] = 0x10000001;
                        p[1] = 0;
                        p[2] = (unsigned long)0x11000000 << 32;
                        p[3] = (unsigned long)(prog | 0x14000000) << 32;
                        p += 4;
                    }
                }
                unsigned int next = (unsigned int)p & 0x0FFFFFFF;
                sPtRing* ring = self->ring;
                self->bufAddr = next;
                sRS_A610* rs = self->top;
                if (ring->count < 0xA28) {
                    rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
                    int key = *(int*)((char*)ring + 0x69CC0);
                    sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
                    *(sRS_A610*)&e->rs = *rs;
                    e->buf = buf;
                    e->next = next;
                    e->key = key;
                    e->flag = 0;
                }
                self->bufAddr += 0x10;
            }
            matIdx += chunk->numSubs;
            chunk++;
        }
        self->top--;
        SetField_A610(self->top->f0, 6, 4, 0);
        SetField_A610(self->top->fC, 0, 30, 0);
    }
}
#endif

INCLUDE_ASM("render/particle", func_0037B548);

//100%
INCLUDE_ASM("render/particle", func_0037BA50);
#ifdef SKIP_ASM
// PORT: PS2-only GS packet build; uncached (0x30000000) pointers held in int and 128-bit qword copies.
typedef int cQuad128_BA50 __attribute__((mode(TI)));

struct sRS_BA50 {
    int f0;
    int f4;
    int f8;
    int fC;
};

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void CopyMat_BA50(void* dst, const void* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

// Emits a particle-batch header packet: GIF tag, the batch matrix and two parameter qwords.
extern "C" void func_0037BA50(char* self, void* mat, cQuad128_BA50* a, cQuad128_BA50* b)
{
    unsigned int buf = *(unsigned int*)(self + 0x5A00);
    unsigned long* p = (unsigned long*)(buf | 0x30000000);
    p[0] = 0x60000007;
    p[2] = (unsigned long)0x8000 << 45;
    p[3] = (unsigned long)0xD80C << 47;
    p[1] = 0;
    CopyMat_BA50(p + 4, mat);
    ((cQuad128_BA50*)p)[6] = *a;
    ((cQuad128_BA50*)p)[7] = *b;
    p += 16;
    *(unsigned int*)(self + 0x5A00) = (unsigned int)p & 0x0FFFFFFF;
    sRS_BA50* rs = *(sRS_BA50**)(self + 0xE84);
    rs->f0 = (rs->f0 & ~0x3C0) | 0x1C0;
    sRS_BA50* rs2 = *(sRS_BA50**)(self + 0xE84);
    rs2->fC = (rs2->fC & 0xC0000000) | (buf & 0x3FFFFFFF);
}
#endif

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

//100%
INCLUDE_ASM("render/particle", func_0037BD98);
#ifdef SKIP_ASM
extern "C" void func_00367078(int gs);
void func_00367340(void* self, int a1, int a2);
extern "C" int func_003673D8(int gs, int size);
extern "C" void func_003E6690(int a);
extern "C" void func_003FD910(int a, int b, int c, int d);

struct sParticleTarget_37BD98 {
    char pad0[0x18F4];
    int gs;                     // 0x18F4
    char pad18F8[0x59D0 - 0x18F8];
    int f59D0;                  // 0x59D0
    char pad59D4[0x5A30 - 0x59D4];
    unsigned int width;         // 0x5A30
    unsigned int height;        // 0x5A34
    unsigned int psm;           // 0x5A38
    unsigned int psm2;          // 0x5A3C
    unsigned int zpsm;          // 0x5A40
    short f5A44;                // 0x5A44
    short f5A46;                // 0x5A46
    short f5A48;                // 0x5A48
    int f5A4C;                  // 0x5A4C
    unsigned int f5A50;         // 0x5A50
    unsigned int f5A54;         // 0x5A54
    unsigned int f5A58;         // 0x5A58
    unsigned int f5A5C;         // 0x5A5C
    int f5A60;                  // 0x5A60
    int f5A64;                  // 0x5A64
    int f5A68;                  // 0x5A68
    int f5A6C;                  // 0x5A6C
    int f5A70;                  // 0x5A70
    int f5A74;                  // 0x5A74
    int f5A78;                  // 0x5A78
    int f5A7C;                  // 0x5A7C
    int f5A80;                  // 0x5A80
};

extern "C" int func_0037BD98(sParticleTarget_37BD98* self, unsigned int a1, unsigned int a2, unsigned int w, unsigned int h,
                             unsigned int psm, unsigned int psm2, unsigned int zpsm, short s0, short s1, short s2, int flag)
{
    if (!func_0037BD38(self, psm2, zpsm))
        return 0;

    self->f5A58 = a2;
    self->width = w;
    self->height = h;
    self->psm2 = psm2;
    self->psm = psm;
    self->zpsm = zpsm;
    self->f5A44 = s1;
    self->f5A46 = s2;
    self->f5A74 = 0;
    self->f5A54 = a1;
    self->f5A48 = 2;
    self->f5A4C = flag;
    self->f5A60 = 0;

    switch (a1) {
    case 0x100:
        self->f5A64 = 9;
        break;
    case 0x140:
        self->f5A64 = 7;
        break;
    case 0x180:
        self->f5A64 = 6;
        break;
    case 0x200:
        self->f5A64 = 4;
        break;
    case 0x280:
        self->f5A64 = 3;
        break;
    }

    self->f5A50 = (self->width + 0x3F) >> 6;
    self->f5A5C = (self->f5A54 + 0x3F) >> 6;

    switch (self->psm) {
    case 0:
    case 1:
    case 0x30:
    case 0x31:
        self->f59D0 = 0;
        self->f5A68 = self->f5A5C * ((self->f5A58 + 0x1F) >> 5);
        break;
    case 2:
    case 10:
    case 0x32:
    case 0x3A:
        self->f59D0 = 1;
        self->f5A68 = self->f5A5C * ((self->f5A58 + 0x3F) >> 6);
        break;
    }

    switch (self->psm2) {
    case 0:
    case 1:
    case 0x30:
    case 0x31:
        self->f5A6C = self->f5A50 * ((self->height + 0x1F) >> 5);
        break;
    case 2:
    case 10:
    case 0x32:
    case 0x3A:
        self->f5A6C = self->f5A50 * ((self->height + 0x3F) >> 6);
        break;
    }

    switch (self->zpsm) {
    case 0x30:
    case 0x31:
        self->f5A70 = self->f5A50 * ((self->height + 0x1F) >> 5);
        break;
    case 0x32:
    case 0x3A:
        self->f5A70 = self->f5A50 * ((self->height + 0x3F) >> 6);
        break;
    }

    int gs = self->gs;
    func_00367078(gs);
    self->f5A78 = func_003673D8(gs, self->f5A6C << 13);
    self->f5A7C = func_003673D8(gs, self->f5A68 << 13);
    self->f5A80 = func_003673D8(gs, self->f5A70 << 13);

    // PORT: reads psm and psm2 as one 64-bit word.
    if (*(long*)&self->psm == 0x100000001L)
        func_00367340((void*)self->gs, self->f5A78 << 11, self->f5A54 * self->f5A58 + self->width * self->height * 2);
    else if (self->psm == 1)
        func_00367340((void*)self->gs, self->f5A7C << 11, self->f5A54 * self->f5A58 + self->width * self->height);
    else
        func_00367340((void*)self->gs, self->f5A80 << 11, self->width * self->height);

    func_00424020(0);
    *(volatile long*)0x12001000 = 8;
    while (!(*(volatile long*)0x12001000 & 8)) {
    }
    *(volatile long*)0x12001000;

    func_003FD910(s0, self->f5A44, flag ? 0x50 : self->f5A48, self->f5A46);
    func_003E6690(flag ? 3 : 1);
    func_00382AF0(self, 0, 1);
    return 1;
}
#endif

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

// PORT: g++ `<?` (min) operator; needs a macro / std::min on a modern compiler.

struct sPartColour_C570 {
    float r, g, b;
};

extern "C" void func_0037C570(void* self, sPartColour_C570* c)
{
    *(int*)((char*)self + 0x59EC) = func_004139F8(clampPos(c->r, 1.0f) * 128.0f);
    *(int*)((char*)self + 0x59F0) = func_004139F8(clampPos(c->g, 1.0f) * 128.0f);
    *(int*)((char*)self + 0x59F4) = func_004139F8(clampPos(c->b, 1.0f) * 128.0f);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C638);
#ifdef SKIP_ASM
struct sRGB_C638 {
    float x, y, z;
    sRGB_C638() {}
    sRGB_C638(const sRGB_C638& o) { x = o.x; y = o.y; z = o.z; }
};

extern "C" sRGB_C638 func_0037C638(void* self)
{
    sRGB_C638 v;
    v.x = (float)*(unsigned int*)((char*)self + 0x59EC) * 0.0078125f;
    v.y = (float)*(unsigned int*)((char*)self + 0x59F0) * 0.0078125f;
    v.z = (float)*(unsigned int*)((char*)self + 0x59F4) * 0.0078125f;
    return v;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C720);
#ifdef SKIP_ASM
// PORT: g++ `<?` (min) operator; needs a macro / std::min on a modern compiler.

// Stores the inverted alpha (1 - clamped a) as a 0..128 value.
extern "C" void func_0037C720(void* self, float a)
{
    *(int*)((char*)self + 0x59F8) = func_004139F8((1.0f - clampPos(a, 1.0f)) * 128.0f);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C770);
#ifdef SKIP_ASM
extern "C" float func_0037C770(void* self)
{
    unsigned int v = *(unsigned int*)((char*)self + 0x59F8);
    return 1.0f - (float)v * 0.0078125f;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C7C0);
#ifdef SKIP_ASM
void func_00366FE0(void* p, int a1);

extern "C" void func_0037C7C0(void* self, int a1)
{
    func_003E6448((char*)self + 0x3838, 0, 0x1F40);
    func_00366FE0(*(void**)((char*)self + 0x18F4), a1);
}
#endif

extern "C" void func_003E6574(void*, void*, int);

//100%
INCLUDE_ASM("render/particle", func_0037C808__FPv);
#ifdef SKIP_ASM
void func_0037C808(void* self)
{
    func_003E6574((char*)self + 0x18f8, (char*)self + 0x3838, 0x1f40);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037C830);
#ifdef SKIP_ASM

extern "C" void func_0037C830(void* self)
{
    int i;
    for (i = 0; i < 2000; i++) {
        if (((int*)((char*)self + 0x18F8))[i] != 0) {
            sPtVtVI* vt = *(sPtVtVI**)((char*)self + 0x10D8);
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

//100%
INCLUDE_ASM("render/particle", func_0037C8C0);
#ifdef SKIP_ASM
struct sTexHdr_C8C0 {
    int f0;                         // 0x0: low byte = type, upper 24 bits = offset to base header
    short s4;                       // 0x4
    short s6;                       // 0x6
    short s8;                       // 0x8
    char pad_0xA[2];
    unsigned int fC;                // 0xC
    int f10;                        // 0x10
};

struct sVEntry0037C8C0 {
    short delta;
    short index;
    int (*fn)(void*, void*, int, int, int, int, int, int, void*, int, int, int);
};

extern "C" double func_00413AF8(float f);
extern "C" double dlog_C8C0(double) __asm__("func_0040D610");
extern "C" double func_00411FD8(double, double);
extern "C" double func_00411F70(double, double);
extern "C" int dtoi_C8C0(double) __asm__("func_00412608");
extern "C" void func_0037D090_C8C0(void* self, int h, int a, int b, int c, int d) __asm__("func_0037D090__FPv");

static inline int clampX_C8C0(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
static inline int clampY_C8C0(int v, int lo, int hi)
{
    int r;
    if (v < lo) r = lo;
    else { r = hi; if (v <= hi) r = v; }
    return r;
}
static inline int clampZ_C8C0(int v, int lo, int hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}
static inline int clampW_C8C0(int v, int lo, int hi)
{
    return v < lo ? lo : (v <= hi ? v : hi);
}
extern "C" int func_0037C8C0(char* self, sTexHdr_C8C0* src, int a2, int a3, int a4, int a5)
{
    int fmt = 0;
    int cls = 0;
    void* pal = 0;
    void* data;
    unsigned int type = *(unsigned char*)src;
    switch (type) {
    case 1: {
        sTexHdr_C8C0* base = src->f0 >> 8 ? (sTexHdr_C8C0*)((char*)src + (src->f0 >> 8)) : 0;
        fmt = 0xB;
        if (src->fC & 0x2000) fmt = 0xC;
        cls = 1;
        if (base->fC & 0x1000)
            pal = (char*)base + base->f10;
        else
            pal = (char*)base + 0x10;
        break;
    }
    case 2: {
        sTexHdr_C8C0* base = src->f0 >> 8 ? (sTexHdr_C8C0*)((char*)src + (src->f0 >> 8)) : 0;
        fmt = 9;
        if (src->fC & 0x2000) fmt = 10;
        cls = 1;
        if (base->fC & 0x1000)
            pal = (char*)base + base->f10;
        else
            pal = (char*)base + 0x10;
        break;
    }
    case 3:
        fmt = 2;
        break;
    case 5:
        fmt = 0;
        break;
    default:
        break;
    }
    unsigned int flags = src->fC;
    data = (char*)src + 0x10;
    if (flags & 0x1000)
        data = (char*)src + src->f10;
    sVEntry0037C8C0* vt = *(sVEntry0037C8C0**)(self + 0x10D8);
    int h = vt[47].fn(self + vt[47].delta, data, a2, src->s4, src->s6, flags >> 28, fmt, cls, pal, a3, a4, a5);
    if ((src->fC & 0xF0000000) != 0 && src->s8 != 0) {
        double d = func_00413AF8(240.0f / ((float)src->s8 * 6.1035156e-05f));
        d = dlog_C8C0(d);
        d = func_00411FD8(d, 1.4426950408889634);
        d = func_00411F70(0.0, d);
        d = func_00411FD8(d, 16.0);
        int k = dtoi_C8C0(d);
        k = clampZ_C8C0(k, -0x7FF, -0x87);
        func_0037D090_C8C0(self, h, 5, 1, 0, k);
    }
    return h;
}
#endif

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

extern "C" void func_0037CBE8(void* self, void* out, int a2, int a3)
{
    sPtVtIIII* vt = *(sPtVtIIII**)((char*)self + 0x10D8);
    *(int*)((char*)out + 4) = vt[52].fn((char*)self + vt[52].delta, a2, a3, 0);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037CC30);
#ifdef SKIP_ASM

extern "C" void func_0037CC30(void* self, void* item)
{
    if (*(int*)((char*)item + 0x4) != -1) {
        func_00367B60(*(void**)((char*)self + 0x18F4), *(int*)((char*)item + 0x4));
        sPtVtVI* vt = *(sPtVtVI**)((char*)self + 0x10D8);
        vt[50].fn((char*)self + vt[50].delta, *(int*)((char*)item + 0x4));
        *(int*)((char*)item + 0x4) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037CC98);
#ifdef SKIP_ASM
typedef int cQuad128_CC98 __attribute__((mode(TI)));

struct sPtTex_CC98 {
    char pad_0x0[0x28];
    int size;                       // 0x28
};

struct sPtTexTbl_CC98 {
    int pad[2];
    sPtTex_CC98* entries[1];        // 0x8
};

struct sPtGfxB_CC98 {
    char pad_0x0[0xE84];
    sPtRenderState* top;                // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sPtRing* ring;             // 0x18F0
    sPtTexTbl_CC98* tbl;            // 0x18F4
    char pad_0x18F8[0x5900 - 0x18F8];
    unsigned short vx;              // 0x5900
    unsigned short vy;              // 0x5902
    unsigned short vw;              // 0x5904
    unsigned short vh;              // 0x5906
    char pad_0x5908[0x5A00 - 0x5908];
    unsigned int bufAddr;           // 0x5A00
    char pad_0x5A04[0x5A54 - 0x5A04];
    int f5A54;
    int f5A58;
    int f5A5C;
    char pad_0x5A60[0x5A80 - 0x5A60];
    unsigned int f5A80;
    char pad_0x5A84[4];
    int f5A88;
};

extern "C" void func_0037CC98(sPtGfxB_CC98* self, int* obj)
{
    self->top[1] = *self->top;
    self->top++;
    sPtTex_CC98* tex = self->tbl->entries[obj[1]];
    self->top->f0 &= ~0x3C0;
    self->top->fC &= 0xC0000000;
    unsigned int buf = self->bufAddr;
    int sz = tex->size / 32;
    int w5A88 = self->f5A88 << 5;
    int h5A5C = self->f5A5C;
    unsigned int f80 = self->f5A80;
    unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
    *(cQuad128_CC98*)p = 0x10000013;
    p[2] = 0;
    p[3] = 0x5000001200000000UL;
    p += 4;
    p[0] = 0x1000000000008011UL;
    p[1] = 0xE;
    p[2] = (long)sz | 0x40000;
    p[3] = 0x4C;
    p[4] = (unsigned long)(f80 | 0x1000000) | 0x100000000UL;
    p[5] = 0x4E;
    p[6] = 0xff000000ff0000UL;
    p[7] = 0x40;
    p[8] = 0x30000;
    p[9] = 0x47;
    p[10] = 0;
    p[11] = 0x18;
    p[12] = 0x2a;
    p[13] = 0x42;
    p[14] = 0x8000000080UL;
    p[15] = 0x3b;
    p[16] = 0;
    p[17] = 0x14;
    p[18] = (long)w5A88 | (long)h5A5C << 14 | 0x2a8000000L;
    p[19] = 6;
    p[20] = 0x116;
    p[21] = 0;
    uPtFloatBits one;
    one.f = 1.0f;
    p[22] = ((unsigned long)one.i << 32) | 0x80808080UL;
    p[23] = 1;
    p += 24;
    int f58 = self->f5A58;
    int f54 = self->f5A54;
    p[0] = 0x80008;
    p[1] = 3;
    p[2] = 0xffff00000000UL;
    p[3] = 5;
    p[4] = (long)(f54 * 16 - 8) | (long)(f58 * 16 - 8) << 16;
    p[5] = 3;
    p[6] = 0xffff10001000UL;
    p[7] = 5;
    p += 8;
    p[0] = 0;
    p[1] = 0x3f;
    p[2] = (unsigned long)self->vx | (unsigned long)(self->vx + (self->vw - 1)) << 16 | (unsigned long)self->vy << 32 | (unsigned long)(self->vy + (self->vh - 1)) << 48;
    p[3] = 0x40;
    p += 4;
    unsigned int next = func_0038F668(D_004A4474, p, 4);
    self->bufAddr = next;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    *(int*)((char*)self + 0xF44) = 1;
    self->bufAddr += 0x10;
    self->top--;
}
#endif

extern "C" void* func_00369130(int);

//100%
INCLUDE_ASM("render/particle", func_0037D090__FPv);
#ifdef SKIP_ASM
void* func_0037D090(void* self)
{
    return func_00369130(*(int*)((char*)self + 0x18f4));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D0B0);
#ifdef SKIP_ASM
struct sTexSrc_D0B0 {
    int f0;                         // 0x0: low byte = type, upper 24 bits = offset
    short s4;                       // 0x4
    short s6;                       // 0x6
    char pad8[4];
    unsigned int fC;                // 0xC
};

struct sVE_D0B0 {
    short delta;
    short index;
    void (*fn)(void*, int, void*, int, int, unsigned int, int, int, void*, int);
};

struct sGfxView_D0B0 {
    char pad[0x10D8];
    sVE_D0B0* vt;                   // 0x10D8
};

extern char D_004A4390[];
void* operator_new_D0B0(unsigned int, char*, unsigned int, int) __asm__("operator_new__FUi");
extern "C" int func_003E6188(void* dst, void* src, int n);
extern "C" unsigned int func_003B47F8(void* src, void* dst);
extern "C" void* func_002523A8(void* p);

extern "C" void func_0037D0B0(void* selfp, int a1, void* objp, int a3)
{
    sGfxView_D0B0* self = (sGfxView_D0B0*)selfp;
    sTexSrc_D0B0* obj = (sTexSrc_D0B0*)objp;
    int mode = 0;
    char* extra = 0;
    int flagB = 0;
    unsigned int type = *(unsigned char*)obj;
    switch (type) {
    case 1: {
        mode = 0xB;
        int w = obj->f0 >> 8;
        flagB = 1;
        char* sub = w ? (char*)obj + w : 0;
        int hi = obj->fC & 0x2000;
        if (hi) mode = 0xC;
        if (((sTexSrc_D0B0*)sub)->fC & 0x1000)
            extra = sub + *(int*)(sub + 0x10);
        else
            extra = sub + 0x10;
        break;
    }
    case 2: {
        mode = 9;
        int w = obj->f0 >> 8;
        flagB = 1;
        char* sub = w ? (char*)obj + w : 0;
        int hi = obj->fC & 0x2000;
        if (hi) mode = 0xA;
        if (((sTexSrc_D0B0*)sub)->fC & 0x1000)
            extra = sub + *(int*)(sub + 0x10);
        else
            extra = sub + 0x10;
        break;
    }
    case 3:
        mode = 2;
        break;
    case 5:
        mode = 0;
        break;
    }
    int allocated = 0;
    char* tmp = 0;
    char* p10 = (char*)obj + 0x10;
    unsigned int fC;
    char* data;
    unsigned char* ob = (unsigned char*)obj;
    if (ob[0x10] == 0x10 && ob[0x11] == 0xFB) {
        unsigned int size = (ob[0x12] << 16 | ob[0x13] << 8 | ob[0x14]) + 0x10;
        allocated = 1;
        tmp = (char*)operator_new_D0B0(size, D_004A4390, 0x80000100, 0);
        func_003E6188(tmp, obj, 0x10);
        char* payload = tmp + 0x10;
        func_003B47F8(p10, payload);
        *(unsigned char*)tmp &= 0x7F;
        if (((sTexSrc_D0B0*)tmp)->fC & 0x1000) {
            data = tmp + *(int*)(tmp + 0x10);
            fC = obj->fC;
        } else {
            data = tmp + 0x10;
            fC = obj->fC;
        }
    } else {
        if (obj->fC & 0x1000)
            data = (char*)obj + *(int*)((char*)obj + 0x10);
        else
            data = p10;
        fC = obj->fC;
    }
    sVE_D0B0* e = &self->vt[0x188 / 8];
    e->fn((char*)self + e->delta, a1, data, obj->s4, obj->s6, fC >> 28, mode, flagB, extra, a3);
    if (allocated) {
        func_002523A8(tmp);
    }
}
#endif

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

extern "C" void func_00367DB8_D348(void* texset, int idx, unsigned int* buf) __asm__("func_00367DB8");

// PORT: uncached (0x30000000) pointers held in int.
// Uploads texture idx into the uncached buffer and queues a ring entry for it.
extern "C" int func_0037D348(cPS2GraphicsMan* self, int idx)
{
    unsigned int buf = self->bufAddr;
    unsigned int p = buf | 0x30000000;
    func_00367DB8_D348(self->texset, idx, &p);
    unsigned int next = p & 0x0FFFFFFF;
    self->bufAddr = next;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

//100%
INCLUDE_ASM("render/particle", func_0037D450);
#ifdef SKIP_ASM

// PORT: 64-bit `ulong` GS packet words; uncached (0x30000000) pointers held in int.
extern "C" int func_0037D450(cPS2GraphicsMan* self)
{
    unsigned int buf = self->bufAddr;
    ulong* p = (ulong*)(buf | 0x30000000);
    p[0] = 0x10000006;
    p[1] = 0;
    p[2] = (ulong)0x8800 << 45;
    p[3] = (ulong)0x50000005 << 32;
    p[4] = ((ulong)0x10000000 << 32) | 0x8004;
    p[5] = 0xE;
    p[6] = (ulong)self->fbp | ((ulong)self->fbw << 16) | ((ulong)self->psm << 24);
    p[7] = 0x4C;
    p[8] = (ulong)self->scX | ((ulong)(self->scX + (self->scW - 1)) << 16) | ((ulong)self->scY << 32) | ((ulong)(self->scY + (self->scH - 1)) << 48);
    p[9] = 0x40;
    p[10] = (ulong)self->scX | ((ulong)(self->scX + (self->scW - 1)) << 16) | ((ulong)self->scY << 32) | ((ulong)(self->scY + (self->scH - 1)) << 48);
    p[11] = 0x41;
    p[12] = (ulong)((0x800 - (self->width >> 1)) << 4) | ((ulong)((0x800 - (self->height >> 1)) << 4) << 32);
    p[13] = 0x18;
    p += 14;
    unsigned int next = (unsigned int)p & 0x0FFFFFFF;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    self->bufAddr = next;
    int one = 1;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->flag = one;
        e->next = next;
        e->key = key;
        e->buf = buf;
    }
    self->bufAddr += 0x10;
    return 0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D668);
#ifdef SKIP_ASM
struct sPtGfx_D668 {
    char pad_0x0[0x5A3C];
    unsigned int psm;               // 0x5A3C
    char pad_0x5A40[0x10];
    unsigned int fbw;               // 0x5A50
    char pad_0x5A54[0x30];
    unsigned int fbp;               // 0x5A84
};

extern "C" void func_0037D668(sPtGfx_D668* self, ulong** pp, int a2, int mode)
{
    ulong* p = *pp;
    switch (mode) {
    case 0:
        p[1] = ((ulong)0x50000001 << 32) | 0x11000000;
        p[2] = ((ulong)0x10000000 << 32) | 0x8001;
        p[3] = 0xE;
        p[0] = 0;
        p[4] = (ulong)self->fbp | ((ulong)self->fbw << 16) | ((ulong)self->psm << 24) | ((ulong)a2 << 32);
        p[5] = 0x4C;
        break;
    case 1:
        p[1] = ((ulong)0x50000002 << 32) | 0x11000000;
        p[2] = ((ulong)0x10000000 << 32) | 0x8001;
        p[3] = 0xE;
        p[0] = 0;
        p[4] = (ulong)self->fbp | ((ulong)self->fbw << 16) | ((ulong)self->psm << 24) | ((ulong)a2 << 32);
        p[5] = 0x4D;
        break;
    default:
        *pp = p;
        return;
    }
    p += 6;
    *pp = p;
}
#endif

extern "C" void* func_00367CD0(void*);

//100%
INCLUDE_ASM("render/particle", func_0037D738__FPv);
#ifdef SKIP_ASM
void* func_0037D738(void* self)
{
    return func_00367CD0(*(void**)((char*)self + 0x18f4));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D758);
#ifdef SKIP_ASM

struct sPartDrawEntry {
    sPtQuadI q;          // 0x00
    sPtMatrix m0;         // 0x10
    sPtMatrix m1;         // 0x50
    float f;             // 0x90
    int i;               // 0x94
};

struct sPartDrawList {
    char pad_0x0[0x13EC];
    int count;                    // 0x13EC
    sPartDrawEntry entries[1];    // 0x13F0
};

extern "C" void func_0037D758(sPartDrawList* self, sPtQuadI* q, sPtMatrix* m0, sPtMatrix* m1, float f, int i)
{
    self->entries[self->count].q = *q;
    vu0CopyMtx(&self->entries[self->count].m0, m0);
    vu0CopyMtx(&self->entries[self->count].m1, m1);
    self->entries[self->count].f = f;
    self->entries[self->count].i = i;
    self->count++;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037D800);
#ifdef SKIP_ASM

extern "C" void func_00367F18_D800(void* texset, int idx, float* color, unsigned int* buf) __asm__("func_00367F18");

// Release-build assert: expands to an empty do { } while (0); its loop notes keep the target's scheduling.
#define ASSERT_D800(cond) do { } while (0)

// PORT: uncached (0x30000000) pointers held in int.
// Like func_0037D348 for the two-argument upload; the queued entry is flagged.
extern "C" void func_0037D800(cPS2GraphicsMan* self, int idx, float* color)
{
    unsigned int buf = self->bufAddr;
    unsigned int p = buf | 0x30000000;
    func_00367F18_D800(self->texset, idx, color, &p);
    unsigned int next = p & 0x0FFFFFFF;
    self->bufAddr = next;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMat_D968(sPtMatrix* d, const sPtMatrix* a, const sPtMatrix* b)
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
static inline void vu0CopyMat_D968(sPtMatrix* d, const sPtMatrix* s)
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

extern "C" void func_003645B8(void* ring, sPtMatrix* m);

extern "C" void func_0037D968(void* selfp)
{
    char* self = (char*)selfp;
    *(int*)(self + 0x6B90) = 1;
    sPtMatrix t2;
    sPtMatrix t;
    vu0MulMat_D968(&t, (sPtMatrix*)(self + 0x6AF0), *(sPtMatrix**)(self + 0x13E4));
    vu0CopyMat_D968(&t2, &t);
    vu0CopyMat_D968((sPtMatrix*)(self + 0x6B30), &t2);
    vu0CopyMat_D968((sPtMatrix*)(self + 0x5780), *(sPtMatrix**)(self + 0x13E4));
    vu0MulMat_D968(&t, (sPtMatrix*)(self + 0x57C0), (sPtMatrix*)(self + 0x5780));
    vu0CopyMat_D968(&t2, &t);
    vu0CopyMat_D968((sPtMatrix*)(self + 0x5800), &t2);
    vu0MulMat_D968(&t, (sPtMatrix*)(self + 0x5860), (sPtMatrix*)(self + 0x5780));
    vu0CopyMat_D968(&t2, &t);
    vu0CopyMat_D968((sPtMatrix*)(self + 0x58A0), &t2);
    func_003645B8(*(void**)(self + 0x18F0), (sPtMatrix*)(self + 0x5780));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037DBE8);
#ifdef SKIP_ASM

struct sPtMtxDBE8 {
    t4Vector r[4];
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

// PORT: PS2-only VU0 inline asm (matrix * vector).
static inline t4Vector mtxApplyDBE8(sPtMtxDBE8* m, const t4Vector& v)
{
    t4Vector out;
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

extern "C" int func_0037DBE8(sPtGfxDBE8* self, const t4Vector* p)
{
    if (self->clipValid == 0) {
        func_0037D968(self);
    }
    t4Vector v = mtxApplyDBE8(&self->clipMtx, *p);
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

static inline int clampDD20(int n, int lo, int hi)
{
    int r;
    if (n >= lo) {
        r = n;
        if (r > hi) {
            r = hi;
        }
    } else {
        r = lo;
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
    v.Z() = (float)clampDD20((int)v.Z(), 0, 0xFFFFFF);
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

// Transforms v by the 4x4 matrix at self+0x58A0, divides by w, then scales by the
// vector at self+0x58E0 and adds the one at self+0x58F0.
// PORT: PS2-only VU0 macro-mode asm; the PC port needs a C version.
extern "C" t4Vector func_0037DEE0(void* self, t4Vector* v)
{
    t4Vector r;
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
          "m"(*(t4Vector*)((char*)self + 0x58E0)),
          "m"(*(t4Vector*)((char*)self + 0x58F0)));
    return r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_0037DF40);
#ifdef SKIP_ASM

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4x4 matrix * vector).
extern "C" t4Vector func_0037DF40(void* self, t4Vector* v)
{
    char* m = (char*)self + 0x58A0;
    t4Vector r;
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf10, %1\n"
        "lqc2         $vf1, 0x0(%2)\n"
        "lqc2         $vf2, 0x10(%2)\n"
        "lqc2         $vf3, 0x20(%2)\n"
        "lqc2         $vf4, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf1, $vf10x\n"
        "vmadday.xyzw ACC, $vf2, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf10z\n"
        "vmaddw.xyzw  $vf11, $vf4, $vf10w\n"
        "sqc2         $vf11, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*v), "r"(m)
        : "memory");
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

// PORT: 64-bit `ulong` packet words.
extern "C" void func_0037E098(sPtQuadI* src, void* self, sPtQuadI* hdr, char** pp)
{
    char* p = *pp;
    int i;
    *(ulong*)(p + 0x0) = 0x1000000F;
    *(ulong*)(p + 0x8) = 0;
    *(ulong*)(p + 0x10) = 0;
    *(ulong*)(p + 0x18) = (ulong)0x6C038009 << 32;
    ((sPtQuadI*)(p + 0x20))[0] = hdr[0];
    ((sPtQuadI*)(p + 0x20))[1] = hdr[1];
    ((sPtQuadI*)(p + 0x20))[2] = hdr[2];
    *(ulong*)(p + 0x50) = 0;
    *(ulong*)(p + 0x58) = (ulong)0x6C0A800F << 32;
    p += 0x60;
    for (i = 0; i < 10; i++) {
        ((sPtQuadI*)p)[i] = src[i];
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
extern "C" void func_0037E120(void* self, sPtQuadI* m, sPtQuadI* hdr, int a3, void* m2,
                              sPtQuadI* src, int flags, char** pp)
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
        sPtQuadI t = m[3];
        func_0037E098(src, &t, hdr, &p);
    }
    *pp = p;
}
#endif

INCLUDE_ASM("render/particle", func_0037E238);

//100%
INCLUDE_ASM("render/particle", func_00380380);
#ifdef SKIP_ASM

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
    sPtVec3 scale;         // 0x18
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
    sPtVec3 k;
    sPtVec3 s = mdl->scale;
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

//100%
INCLUDE_ASM("render/particle", func_00380518);
#ifdef SKIP_ASM

extern int D_004A44F8;
extern char D_0[];

// Sends obj's 0x15 quads to the VU1 program at address 0 under a pushed render state.
extern "C" void func_00380518(cPS2GraphicsMan* self, sGifQuad* obj)
{
    if (D_004A44F8 != 0)
        return;
    self->top[1] = *self->top;
    self->top++;
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0x100;
    self->top->fC &= 0xC0000000;
    self->top->f4 = (self->top->f4 & ~3) | 2;
    self->top->f8 &= 0xE00003FF;
    self->top->f8 = (self->top->f8 & ~0x3E0) | 0xE0;
    unsigned int buf = self->bufAddr;
    unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
    p[0] = 0x10000017;
    p[1] = 0;
    p[2] = 0;
    p[3] = (unsigned long)0xD82B << 47;
    p += 4;
    CopyQuads(&p, obj, 0x15);
    p[0] = (unsigned long)(((unsigned int)D_0 >> 3) | 0x14000000) << 32;
    p[1] = (unsigned long)0x8800 << 45;
    p += 2;
    self->bufAddr = func_0038F668(D_004A4474, p, 4);
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    sPtRing* ring = self->ring;
    unsigned int next = self->bufAddr;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    self->bufAddr += 0x10;
    self->top--;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003807A0);
#ifdef SKIP_ASM

struct sTrail_07A0 {
    char pad_0x0[0x20];
    sGifQuad q[0x15];             // 0x20
    float scale;                    // 0x170 (unused here)
    char pad_0x174[4];
    int count;                      // 0x178
    int head;                       // 0x17C
    char pad_0x180[0x20];
    sGifQuad* posA;               // 0x1A0
    sGifQuad* posB;               // 0x1A4
};

extern char D_510[];

// PORT: uncached (0x30000000) pointers and VU microprogram addresses held in int; 64-bit GS words are `ulong`.
extern "C" void func_003807A0(cPS2GraphicsMan* self, sTrail_07A0* obj)
{
    if (D_004A44FC != 0)
        return;
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0x100;
    self->top->fC &= 0xC0000000;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    int n = obj->count;
    sPtSegHdr hdr;
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
        CopyQuads(&p, obj->q, 0x15);
        CopyQuads(&p, &hdr, 1);
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
        sGifQuad* lastA;
        sGifQuad* lastB;
        if (done < m) {
            int e = wrapIndex(done, wrap, m);
            lastB = obj->posB + e;
            lastA = obj->posA + e;
        } else {
            int e = wrapIndex(done - 1, wrap, m);
            lastB = obj->posB + e;
            lastA = obj->posA + e;
        }
        CopyQuads(&p, obj->posA + s, first);
        if (over > 0)
            CopyQuads(&p, obj->posA, over);
        CopyQuads(&p, lastA, 1);
        p = (unsigned long*)((sGifQuad*)p + pad);
        CopyQuads(&p, obj->posB + s, first);
        if (over > 0)
            CopyQuads(&p, obj->posB, over);
        CopyQuads(&p, lastB, 1);
        p = (unsigned long*)((sGifQuad*)p + pad);
        p[0] = (unsigned long)(((unsigned int)D_510 >> 3) | 0x14000000) << 32;
        p[1] = (unsigned long)0x8800 << 45;
        p += 2;
        unsigned int next = func_0038F668(D_004A4474, p, 4);
        self->bufAddr = next;
        sPtRing* ring = self->ring;
        sPtRenderState* rs = self->top;
        if (ring->count < 0xA28) {
            rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
            int key = *(int*)((char*)ring + 0x69CC0);
            sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

//100%
INCLUDE_ASM("render/particle", func_00380CE0);
#ifdef SKIP_ASM

struct sCol_0CE0 {
    char b[4];
    sCol_0CE0() {}
};

struct sTrail_0CE0 {
    char pad_0x0[0x20];
    sGifQuad q[0x15];             // 0x20
    float scale;                    // 0x170 (unused here)
    char pad_0x174[4];
    int count;                      // 0x178
    int head;                       // 0x17C
    char pad_0x180[0x20];
    sGifQuad* posA;               // 0x1A0
    sGifQuad* posB;               // 0x1A4
    char pad_0x1A8[0x200 - 0x1A8];
    int alt;                        // 0x200
    sCol_0CE0* cols;                // 0x204
};

extern char D_A00[];
extern char D_F10[];
extern "C" void func_003E6574(void* dst, void* src, int n);

// PORT: uncached (0x30000000) pointers and VU microprogram addresses held in int; 64-bit GS words are `ulong`.
extern "C" void func_00380CE0(cPS2GraphicsMan* self, sTrail_0CE0* obj)
{
    if (D_004A44FC != 0)
        return;
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0x100;
    self->top->fC &= 0xC0000000;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    int n = obj->count;
    sPtSegHdr hdr;
    int done = 0;
    hdr.step = *(int*)((char*)obj + 0x20) / n;
    hdr.fstep = (float)hdr.step;
    int nb = n / 43 + 1;
    unsigned int prog = (unsigned int)(obj->alt != 0 ? D_F10 : D_A00) >> 3;
    for (int i = 0; i < nb; i++) {
        unsigned int buf = self->bufAddr;
        unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
        p[0] = 0x1000007C;
        p[1] = 0;
        p[2] = 0;
        p[3] = (unsigned long)0xD8DD << 47;
        hdr.v = hdr.fstep * (float)(i * 43) * *(float*)((char*)obj + 0x2C);
        int seg = obj->count - done;
        if (seg >= 0x2C)
            seg = 0x2B;
        hdr.seg = seg;
        p += 4;
        CopyQuads(&p, obj->q, 0x15);
        CopyQuads(&p, &hdr, 1);
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
        int pad = 0x2B - first - over;
        sGifQuad* lastA;
        sGifQuad* lastB;
        sCol_0CE0* lastC;
        if (done < m) {
            int e = wrapIndex(done, wrap, m);
            lastA = obj->posA + e;
            lastB = obj->posB + e;
            lastC = obj->cols + e;
        } else {
            int e = wrapIndex(done - 1, wrap, m);
            lastA = obj->posA + e;
            lastB = obj->posB + e;
            lastC = obj->cols + e;
        }
        CopyQuads(&p, obj->posA + s, first);
        if (over > 0)
            CopyQuads(&p, obj->posA, over);
        CopyQuads(&p, lastA, 1);
        p = (unsigned long*)((sGifQuad*)p + pad);
        CopyQuads(&p, obj->posB + s, first);
        if (over > 0)
            CopyQuads(&p, obj->posB, over);
        CopyQuads(&p, lastB, 1);
        p = (unsigned long*)((sGifQuad*)p + pad);
        p[0] = 0;
        p[1] = (unsigned long)0x6E2CC06E << 32;
        p += 2;
        sCol_0CE0 cols[44];
        func_003E6574(cols, obj->cols + s, first * 4);
        if (over > 0)
            func_003E6574(cols + first, obj->cols, over * 4);
        cols[first + over] = *lastC;
        CopyQuads(&p, cols, 11);
        p[0] = (unsigned long)(prog | 0x14000000) << 32;
        p[1] = (unsigned long)0x8800 << 45;
        p += 2;
        unsigned int next = func_0038F668(D_004A4474, p, 4);
        self->bufAddr = next;
        sPtRing* ring = self->ring;
        sPtRenderState* rs = self->top;
        if (ring->count < 0xA28) {
            rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
            int key = *(int*)((char*)ring + 0x69CC0);
            sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

//100%
INCLUDE_ASM("render/particle", func_00381310);
#ifdef SKIP_ASM

extern char D_0[];

// PORT: uncached (0x30000000) pointers and VU microprogram addresses held in int; 64-bit GS words are `ulong`.
extern "C" void func_00381310(cPS2GraphicsMan* self, sPtMatPacket* obj)
{
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0x140;
    self->top->fC &= 0xC0000000;
    self->top->f4 = (self->top->f4 & ~3) | 2;
    self->top->f8 &= 0xE00003FF;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    sPtMatrixV m = MulMatV(self->m5860, obj->mat);
    unsigned int buf = self->bufAddr;
    unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
    p[0] = 0x1000000D;
    p[1] = 0;
    p[2] = 0;
    p[3] = (unsigned long)0xD817 << 47;
    p += 4;
    t4Vector v0;
    v0.x = 0.0f;
    v0.y = 0.0f;
    v0.z = 0.0f;
    v0.w = 0.0f;
    t4Vector v1;
    v1.x = 1.0f;
    v1.y = 1.0f;
    v1.z = 0.0f;
    v1.w = 0.0f;
    CopyQuads(&p, (const sGifQuad*)&m, 4);
    CopyQuads(&p, (const sGifQuad*)&v0, 1);
    CopyQuads(&p, (const sGifQuad*)&v1, 1);
    CopyQuads(&p, obj->q, 5);
    p[0] = (unsigned long)(((unsigned int)D_0 >> 3) | 0x14000000) << 32;
    p[1] = (unsigned long)0x8800 << 45;
    p += 2;
    unsigned int next = func_0038F668(D_004A4474, p, 4);
    self->bufAddr = next;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

//100%
INCLUDE_ASM("render/particle", func_003816F0);
#ifdef SKIP_ASM

extern char D_408[];

// PORT: uncached (0x30000000) pointers and VU microprogram addresses held in int; 64-bit GS words are `ulong`.
extern "C" void func_003816F0(cPS2GraphicsMan* self, sPtMatPacket* obj)
{
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0x140;
    self->top->fC &= 0xC0000000;
    self->top->f4 = (self->top->f4 & ~3) | 2;
    self->top->f8 &= 0xE00003FF;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    sPtMatrixV m = MulMatV(self->m5860, obj->mat);
    unsigned int buf = self->bufAddr;
    unsigned long* p = func_0038F460(D_004A4474, buf, -1, 0);
    p[0] = 0x1000000D;
    p[1] = 0;
    p[2] = 0;
    p[3] = (unsigned long)0xD817 << 47;
    p += 4;
    t4Vector v0;
    v0.x = 0.0f;
    v0.y = 0.0f;
    v0.z = 0.0f;
    v0.w = 0.0f;
    t4Vector v1;
    v1.x = 1.0f;
    v1.y = 1.0f;
    v1.z = 0.0f;
    v1.w = 0.0f;
    CopyQuads(&p, (const sGifQuad*)&m, 4);
    CopyQuads(&p, (const sGifQuad*)&v0, 1);
    CopyQuads(&p, (const sGifQuad*)&v1, 1);
    CopyQuads(&p, obj->q, 5);
    p[0] = (unsigned long)(((unsigned int)D_408 >> 3) | 0x14000000) << 32;
    p[1] = (unsigned long)0x8800 << 45;
    p += 2;
    unsigned int next = func_0038F668(D_004A4474, p, 4);
    self->bufAddr = next;
    sPtRing* ring = self->ring;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

//100%
INCLUDE_ASM("render/particle", func_00381AD0);
#ifdef SKIP_ASM
// Projected clip-space point (the file's VU0 point type).
typedef sPt7278 sClipPt_3A10;

// Clip vertex: three quadwords (texture coords, colour, position); the colour quadword holds integers.
struct sClipVtx_3A10 {
    float st[4];                    // 0x00
    float col[4];                   // 0x10: integer channels r, g, b, a
    sClipPt_3A10 pos;               // 0x20
    sClipVtx_3A10() {}
};

// GS packet under construction (out-of-line ctor func_00384D98, close func_00384E50).
struct sClipPkt_1AD0 {
    unsigned int* where;            // 0x0
    unsigned int cur;               // 0x4
    unsigned int start;             // 0x8
    int open;                       // 0xC
    int count;                      // 0x10
};

void* PktOpen_1AD0(sClipPkt_1AD0* pkt, unsigned int* buf) __asm__("func_00384D98");
void PktClose_1AD0(sClipPkt_1AD0* pkt, int flags) __asm__("func_00384E50");
void PktVert_1AD0(sClipPkt_1AD0* pkt, sClipVtx_3A10* v, sClipPt_3A10* p) __asm__("func_00384FD0");
void PktStrip_1AD0(sClipPkt_1AD0* pkt, sClipVtx_3A10* v, sClipPt_3A10* p) __asm__("func_003850A8");
extern "C" int func_00383A10(cPS2GraphicsMan* self, sClipVtx_3A10* ivert, sClipPt_3A10* iproj, int* ioutcode);

// The vertex before v. Int arithmetic: the typed v[-1] / *(v - 1) gives gcc 2.95's unsigned-sizetype
// offset split (addiu base,-32768 + 32720(base)), 99.5 instead of 100.
#define PREVVTX_1AD0(v) (*(sClipVtx_3A10*)((int)(v) - (int)sizeof(sClipVtx_3A10)))

// Draws a strip of n vertices, clipping each edge against the view volume.
extern "C" void func_00381AD0(cPS2GraphicsMan* self, int n, sClipVtx_3A10* v)
{
    sClipPt_3A10 prev;
    sClipPkt_1AD0 pkt;
    int prevoc;
    int i;

    if (self->texReady == 0) {
        func_0037D968(self);
    }
    prevoc = -1;
    PktOpen_1AD0(&pkt, &self->bufAddr);
    for (i = 0; i < n; i++, v++) {
        int oc = 0;
        sClipPt_3A10 proj = MulMat7278(&self->m6B30, v->pos);
        proj.w = 1.0f / proj.w;
        proj.x *= proj.w;
        proj.y *= proj.w;
        if (proj.x < self->xmin) {
            oc = 2;
        }
        if (self->xmax < proj.x) {
            oc |= 1;
        }
        if (proj.y < self->ymin) {
            oc |= 8;
        }
        if (self->ymax < proj.y) {
            oc |= 4;
        }
        if (proj.w < 0.0f) {
            oc ^= 0x2F;
        } else {
            if (proj.z > self->zmin) {
                oc |= 0x20;
            }
            if (proj.z < self->zmax) {
                oc |= 0x10;
            }
        }
        if (oc == 0) {
            if (prevoc == 0) {
                PktVert_1AD0(&pkt, v, &proj);
            } else if (i != 0) {
                int ioutcode[2];
                sClipVtx_3A10 ivert[2];
                sClipPt_3A10 iproj[2];
                iproj[0] = prev;
                ivert[0] = PREVVTX_1AD0(v);
                ioutcode[0] = prevoc;
                iproj[1] = proj;
                ivert[1] = *v;
                ioutcode[1] = oc;
                func_00383A10(self, ivert, iproj, ioutcode);
                PktStrip_1AD0(&pkt, &ivert[0], &iproj[0]);
                PktVert_1AD0(&pkt, v, &proj);
            } else {
                PktStrip_1AD0(&pkt, v, &proj);
            }
        } else if (prevoc == 0) {
            sClipVtx_3A10 ivert[2];
            sClipPt_3A10 iproj[2];
            int ioutcode[2];
            iproj[0] = prev;
            ivert[0] = PREVVTX_1AD0(v);
            ioutcode[0] = prevoc;
            iproj[1] = proj;
            ivert[1] = *v;
            ioutcode[1] = oc;
            func_00383A10(self, ivert, iproj, ioutcode);
            PktVert_1AD0(&pkt, &ivert[1], &iproj[1]);
        } else if ((prevoc & oc) == 0) {
            sClipVtx_3A10 ivert[2];
            sClipPt_3A10 iproj[2];
            int ioutcode[2];
            iproj[0] = prev;
            ivert[0] = PREVVTX_1AD0(v);
            ioutcode[0] = prevoc;
            iproj[1] = proj;
            ivert[1] = *v;
            ioutcode[1] = oc;
            if (func_00383A10(self, ivert, iproj, ioutcode)) {
                PktStrip_1AD0(&pkt, &ivert[0], &iproj[0]);
                PktVert_1AD0(&pkt, &ivert[1], &iproj[1]);
            }
        }
        prev = proj;
        prevoc = oc;
    }
    PktClose_1AD0(&pkt, 2);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00381F10);
#ifdef SKIP_ASM

extern char D_3BF0[];

// PORT: uncached (0x30000000) pointers held in int; 64-bit GS words are `unsigned long`.
extern "C" void func_00381F10(cPS2GraphicsMan* self, sPtMatrix* m, float* col, int n)
{
    self->top->f0 = (self->top->f0 & ~0x3C0) | 0xC0;
    self->top->fC &= 0xC0000000;
    if (self->texReady == 0) {
        func_0037D968(self);
    }
    unsigned int buf = self->bufAddr;
    unsigned long* p = (unsigned long*)(buf | 0x30000000);
    p[0] = 0x1000000A;
    p[1] = 0;
    p[2] = 0;
    p[3] = (unsigned long)0xD811 << 47;
    p[4] = ((unsigned long)0x10014000 << 32) | 1;
    p[5] = 0xE;
    p[6] = (long)(int)(col[1] * 128.0f) | ((long)(int)(col[2] * 128.0f) << 8) | ((long)(int)(col[3] * 128.0f) << 16) | ((long)(int)(col[0] * 128.0f) << 24) | ((unsigned long)0x3F800000 << 32);
    p[7] = 1;
    p[8] = (unsigned long)(n | 0x8000) | ((unsigned long)0x800A << 45);
    p[9] = 4;
    CopyMat((sPtMatrix*)(p + 10), m);
    p[18] = n;
    p[19] = 0;
    p[20] = 0;
    p[21] = (unsigned long)(((unsigned int)D_3BF0 >> 3) | 0x14000000) << 32;
    p += 22;
    self->bufAddr = (unsigned int)p & 0x0FFFFFFF;
    sPtRing* ring = self->ring;
    unsigned int next = self->bufAddr;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    self->bufAddr += 0x10;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00382170);
#ifdef SKIP_ASM
struct sPt2170 {
    float x, y, z, w;
    sPt2170() {}
} __attribute__((aligned(16)));

struct sVtx2170 {
    float s, t, q, pad;     // 0x00
    int r, g, b, a;         // 0x10
    sPt2170 pos;            // 0x20
    sVtx2170() {}
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
    virtual sPtMatrix* v35();
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

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector); the PC port needs a C fallback.
static inline sPt2170 MulMat2170(const sPtMatrix* m, const sPt2170& v)
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
    sPtMatrix m;
    int step;
    int i;
    int k;

    CopyMat(&m, mgr->v35());
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
    (*(sPtRenderState**)(self + 0xE84))->tex = -1;
    (*(sPtRenderState**)(self + 0xE84))->f4 = ((*(sPtRenderState**)(self + 0xE84))->f4 & ~0x7C) | 4;
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
    (*(sPtRenderState**)(self + 0xE84))->f4 = ((*(sPtRenderState**)(self + 0xE84))->f4 & ~0x7C) | 4;
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

//100%
INCLUDE_ASM("render/particle", func_00382760);
#ifdef SKIP_ASM
typedef int u128 __attribute__((mode(TI)));
extern "C" void func_00423DE0(int);
extern "C" void func_00423DC0(int);
extern "C" char D_0044B9C0[] __attribute__((aligned(16)));

struct sParticleDma_382760 {
    char pad0[0x5A8C];
    volatile int state;
    volatile int slot[2];
    volatile int cur;
    int f5A9C;
    int f5AA0;
    volatile int next;
    int f5AA8;
    int f5AAC;
    int f5AB0;
    int f5AB4;
    char pad5AB8[0x10];
    int sema0;
    int sema1;
    char pad5AD0[0x123C];
    void (*cb)(int);
    int cbArg;
};

extern "C" void* func_00382760(void* arg)
{
    sParticleDma_382760* self = (sParticleDma_382760*)arg;
    for (;;) {
        func_00423DE0(self->sema0);
        func_00423DE0(self->sema1);
        if (self->state == 5) {
            self->slot[self->cur] = 0;
            self->state = 0;
            func_00382AF0(self, 1, 0);
        }
        if (self->state == 0 && self->slot[self->next] == 2) {
            if (*(volatile int*)0x10009000 & 0x100) {
                do {
                } while (*(volatile int*)0x10009000 & 0x100);
            }
            do {
            } while (*(volatile int*)0x1000A000 & 0x100);
            do {
            } while (*(volatile int*)0x10003C00 & 0x1F000003);
            do {
            } while ((*(volatile long*)0x12001000 & 0xC000) != 0x4000);
            self->cur = self->next;
            self->slot[self->cur] = 3;
            self->state = 1;
            self->f5A9C = self->f5AAC;
            self->f5AA0 = self->f5AB4;
            func_00424020(0);
            if (*(volatile int*)0x1000D000 & 0x100) {
                do {
                } while (*(volatile int*)0x1000D000 & 0x100);
            }
            *(u128*)0x10005000 = *(u128*)D_0044B9C0;
            *(volatile int*)0x10003010 = 4;
            if (*(volatile int*)0x10003C00 & 0x1F000003) {
                do {
                } while (*(volatile int*)0x10003C00 & 0x1F000003);
            }
            do {
            } while ((*(volatile long*)0x12001000 & 0xC000) != 0x4000);
            *(volatile int*)0x1000A030 = self->f5AB0;
            *(volatile int*)0x1000A000 = 0x105;
            *(volatile int*)0x10009030 = self->f5AA8;
            *(volatile int*)0x10009000 = 0x185;
        } else if (self->state == 2) {
            if (self->cb)
                self->cb(self->cbArg);
            *(u128*)0x10005000 = *(u128*)D_0044B9C0;
            *(volatile int*)0x10003010 = 4;
            if (*(volatile int*)0x10003C00 & 0x1F000003) {
                do {
                } while (*(volatile int*)0x10003C00 & 0x1F000003);
            }
            do {
            } while ((*(volatile long*)0x12001000 & 0xC000) != 0x4000);
            *(volatile int*)0x1000A030 = self->f5AA0;
            *(volatile int*)0x1000A000 = 0x105;
            self->state = 3;
            *(volatile int*)0x10009030 = self->f5A9C;
            *(volatile int*)0x10009000 = 0x185;
        }
        func_00423DC0(self->sema1);
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00382AF0);
#ifdef SKIP_ASM
// The display / frame-buffer state of the graphics manager as the flip routine reads it.
struct sGsFlip_382AF0 {
    float offX;                 // 0x0
    float offY;                 // 0x4
    char pad8[0xF44 - 0x8];
    int skipSwap;               // 0xF44
    char padF48[0x5900 - 0xF48];
    unsigned short scX;         // 0x5900
    unsigned short scY;         // 0x5902
    unsigned short scW;         // 0x5904
    unsigned short scH;         // 0x5906
    char pad5908[0x59D0 - 0x5908];
    unsigned int dthe;          // 0x59D0
    char pad59D4[0x59E0 - 0x59D4];
    unsigned long dimx;         // 0x59E0
    int blur;                   // 0x59E8
    unsigned int blurR;         // 0x59EC
    unsigned int blurG;         // 0x59F0
    unsigned int blurB;         // 0x59F4
    unsigned int blurA;         // 0x59F8
    float blurScale;            // 0x59FC
    char pad5A00[0x5A30 - 0x5A00];
    unsigned int width;         // 0x5A30
    unsigned int height;        // 0x5A34
    unsigned int psm;           // 0x5A38
    unsigned int psm2;          // 0x5A3C
    unsigned int zpsm;          // 0x5A40
    short interlace;            // 0x5A44
    short ffmd;                 // 0x5A46
    short f5A48;                // 0x5A48
    int f5A4C;                  // 0x5A4C
    unsigned int fbw;           // 0x5A50
    unsigned int dispW;         // 0x5A54
    unsigned int dispH;         // 0x5A58
    unsigned int dispFbw;       // 0x5A5C
    unsigned int magv;          // 0x5A60
    unsigned int magh;          // 0x5A64
    int f5A68;                  // 0x5A68
    int f5A6C;                  // 0x5A6C
    int f5A70;                  // 0x5A70
    int frame;                  // 0x5A74
    unsigned int buf0;          // 0x5A78
    unsigned int buf1;          // 0x5A7C
    unsigned int zbp;           // 0x5A80
    unsigned int drawFbp;       // 0x5A84
    unsigned int dispFbp;       // 0x5A88
    char pad5A8C[0x6AE0 - 0x5A8C];
    unsigned int clearCol;      // 0x6AE0
};

extern unsigned long D_004FFCC0[];

// PORT: PS2-only inline asm (sync before handing the packet to DMA).
static inline void Sync_382AF0(void)
{
    __asm__ __volatile__("sync");
}

static inline int Clamp_382AF0(int v, int lo, int hi)
{
    int r;
    if (v >= lo) {
        r = v;
        if (v > hi)
            r = hi;
    } else
        r = lo;
    return r;
}

static inline unsigned int DivU_382AF0(unsigned int a, unsigned int b)
{
    return a / b;
}

// PORT: PS2 hardware registers (DMA CHCR / VIF1_STAT / GS privileged registers).
extern "C" void func_00382AF0(void* arg, bool enable, bool waitVSync)
{
    sGsFlip_382AF0* self = (sGsFlip_382AF0*)arg;
    unsigned long* p;
    unsigned int size;

    self->frame++;
    if (self->skipSwap != 0) {
        self->skipSwap = 0;
    } else if (self->blur == 0 && (self->frame & 1) == 0) {
        self->drawFbp = self->buf1;
        self->dispFbp = self->buf0;
    } else {
        self->drawFbp = self->buf0;
        self->dispFbp = self->buf1;
    }

    if (*(volatile int*)0x10009000 & 0x100) {
        do {
        } while (*(volatile int*)0x10009000 & 0x100);
    }
    do {
    } while (*(volatile int*)0x1000A000 & 0x100);
    do {
    } while (*(volatile int*)0x1000D000 & 0x100);
    do {
    } while (*(volatile int*)0x10003C00 & 0x1F000003);
    do {
    } while ((*(volatile long*)0x12001000 & 0xC000) != 0x4000);

    if (waitVSync) {
        *(volatile long*)0x12001000 = 8;
        while (!(*(volatile long*)0x12001000 & 8)) {
        }
        *(volatile long*)0x12001000;
    }

    *(volatile unsigned long*)0x12000000 = (unsigned long)enable | 0xFF20;
    *(volatile unsigned long*)0x12000020 = (long)self->interlace | (long)self->ffmd << 1;
    *(volatile unsigned long*)0x12000070 = (unsigned long)self->dispFbp | (unsigned long)self->dispFbw << 9 |
                                           (unsigned long)self->psm << 15;
    if (self->f5A4C) {
        int dh = self->dispH - 1;
        *(volatile unsigned long*)0x12000080 = (long)((int)(self->offX * 4.0f + -43.0f) + 344) |
                                               (long)((int)(12.0f - self->offY * 2.0f) + 35) << 12 |
                                               (long)(1550 / (int)self->dispW - 1) << 23 | (long)((int)self->dispW * (1550 / (int)self->dispW) - 1) << 32 |
                                               (long)dh << 44;
    } else {
        int mul = 1;
        if (self->interlace != 0 && self->ffmd == 1)
            mul = 2;
        *(volatile unsigned long*)0x12000080 = (unsigned long)(self->offX * 8.0f + 5.0f + 636.0f) |
                                               (unsigned long)(50.0f - self->offY * 2.0f) << 12 |
                                               (unsigned long)self->magh << 23 | (unsigned long)self->magv << 27 |
                                               (unsigned long)2560 << 32 |
                                               (unsigned long)((self->height - 1) * mul) << 44;
    }
    *(volatile unsigned long*)0x120000E0 = 0;

    p = (unsigned long*)((unsigned int)D_004FFCC0 | 0x30000000);
    if (self->blur) {
        int r, g, b;
        float q;
        int n, step, i, abe;
        int u, v, v1;
        int x, y, x0, y0, left, top, vb, y1;

        p[0] = 0x100000000000000BUL;
        p[1] = 0xE;
        p[2] = (unsigned long)self->dispFbp | (unsigned long)self->dispFbw << 16 | (unsigned long)self->psm << 24 |
               0xFF00000000000000UL;
        p[3] = 0x4C;
        p[4] = 0x61;
        p[5] = 0x14;
        p[6] = (unsigned long)(self->drawFbp << 5) | (unsigned long)self->fbw << 14 | (unsigned long)self->psm2 << 20 |
               (unsigned long)10 << 26 | (unsigned long)9 << 30;
        p[7] = 6;
        p[8] = 0x8000000064UL;
        p[9] = 0x42;
        p[10] = 5;
        p[11] = 8;
        p[12] = (unsigned long)(self->dispW - 1) << 16 | (unsigned long)(self->dispH - 1) << 48;
        p[13] = 0x40;
        p[14] = (unsigned long)(self->dispW - 1) << 16 | (unsigned long)(self->dispH - 1) << 48;
        p[15] = 0x41;
        p[16] = (unsigned long)((0x800 - (self->dispW >> 1)) << 4) | (unsigned long)((0x800 - (self->dispH >> 1)) << 4) << 32;
        p[17] = 0x18;
        p[18] = (unsigned long)self->zbp | (unsigned long)(self->zpsm - 0x30) << 24 | (unsigned long)1 << 32;
        p[19] = 0x4E;
        p[20] = 0x30000;
        p[21] = 0x47;
        p[22] = 0;
        p[23] = 0x3F;
        abe = self->blurA != 0x80;
        p[24] = 0x2400000000000001UL;
        p[25] = 0x10;
        p[26] = (unsigned long)abe << 6 | 0x11E;
        r = Clamp_382AF0((int)((float)self->blurR * self->blurScale), 0, 255);
        g = Clamp_382AF0((int)((float)self->blurG * self->blurScale), 0, 255);
        b = Clamp_382AF0((int)((float)self->blurB * self->blurScale), 0, 255);
        q = 1.0f;
        p[27] = (unsigned long)r | (unsigned long)g << 8 | (unsigned long)b << 16 | (unsigned long)self->blurA << 24 | (unsigned long)*(unsigned int*)&q << 32;

        n = DivU_382AF0(self->dispW, 32);
        left = -(int)(self->dispW >> 1) * 16 + 0x8000;
        step = (self->width / n) * 16;
        top = 0x8000 - (self->dispH >> 1) * 16;
        if (self->f5A4C) {
            u = 8;
            x = 0;
            y = 0;
        } else {
            u = 0;
            x = -8;
            y = -8;
        }
        x0 = x + left;
        y0 = y + top;
        vb = (self->height - 1) * 16 + 8;
        y1 = y0 + (self->dispH - 1) * 16;
        p[28] = (unsigned long)(n + 1) | 0x4400000000000000UL;
        p[29] = 0x5353;
        v = u;
        v1 = v + step;
        p += 30;
        for (i = 0; i < n; i++) {
            p[0] = (unsigned long)v | 0x80000;
            p[1] = (unsigned long)x0 | (unsigned long)y0 << 16;
            p[2] = (unsigned long)v1 | (unsigned long)vb << 16;
            p[3] = (unsigned long)(x0 + 0x200) | (unsigned long)y1 << 16;
            v += step;
            v1 += step;
            x0 += 0x200;
            p += 4;
        }
        p[0] = (unsigned long)u | (unsigned long)(self->height * 16 - 8) << 16;
        p[1] = (unsigned long)(-(self->dispW >> 1) * 16 + 0x8000) | (unsigned long)((self->dispH >> 1) * 16 + 0x7FE8) << 16 |
               0x800000000000UL;
        p[2] = (unsigned long)(self->width << 4) | (unsigned long)(self->height * 16 - 8) << 16;
        p[3] = (unsigned long)((self->dispW >> 1) * 16 + 0x8000) | (unsigned long)((self->dispH >> 1) * 16 + 0x7FF8) << 16 |
               0x800000000000UL;
        p += 4;
    }

    p[0] = 0x1000000000008010UL;
    p[1] = 0xE;
    p[2] = (unsigned long)self->drawFbp | (unsigned long)self->fbw << 16 | (unsigned long)self->psm2 << 24;
    p[3] = 0x4C;
    p[4] = (unsigned long)self->drawFbp | (unsigned long)self->fbw << 16 | (unsigned long)self->psm2 << 24 |
           0xFF00000000000000UL;
    p[5] = 0x4D;
    p[6] = (unsigned long)self->zbp | (unsigned long)(self->zpsm - 0x30) << 24;
    p[7] = 0x4E;
    p[8] = (unsigned long)self->zbp | (unsigned long)(self->zpsm - 0x30) << 24;
    p[9] = 0x4F;
    p[10] = (unsigned long)((0x800 - (self->width >> 1)) << 4) | (unsigned long)((0x800 - (self->height >> 1)) << 4) << 32;
    p[11] = 0x18;
    p[12] = (unsigned long)((0x800 - (self->width >> 1)) << 4) | (unsigned long)((0x800 - (self->height >> 1)) << 4) << 32;
    p[13] = 0x19;
    p[14] = 0;
    p[15] = 0x4A;
    p[16] = 0;
    p[17] = 0x4B;
    p[18] = 0x8000000080UL;
    p[19] = 0x3B;
    p[20] = 1;
    p[21] = 0x1A;
    p[22] = 1;
    p[23] = 0x46;
    p[24] = (unsigned long)self->dthe;
    p[25] = 0x45;
    p[26] = self->dimx;
    p[27] = 0x44;
    p[28] = 0;
    p[29] = 0x49;
    p[30] = 0;
    p[31] = 0x22;
    p[32] = 0;
    p[33] = 0x3F;
    p += 34;
    {
        unsigned int n = self->width >> 5;
        int top = 0x800 - (self->height >> 1);
        int y1 = (self->height + top) * 16;
        int y0 = top * 16;
        int x = (0x800 - (self->width >> 1)) * 16;
        p[0] = (long)(int)((n * 2 + 4) | 0x8000) | 0x1000000000000000UL;
        p[1] = 0xE;
        p[2] = 0x30000;
        p[3] = 0x47;
        p[4] = 6;
        p[5] = 0;
        p[6] = (unsigned long)(self->clearCol | 0x80000000) | 0x3F80000000000000UL;
        p[7] = 1;
        p += 8;
        for (; n != 0; n--) {
            p[0] = (unsigned long)x | (unsigned long)y0 << 16;
            p[1] = 5;
            p[2] = (unsigned long)(x + 0x200) | (unsigned long)y1 << 16;
            p[3] = 5;
            x += 0x200;
            p += 4;
        }
    }
    p[0] = 0x500AD;
    p[1] = 0x47;
    p += 2;
    p[0] = 0x1000000000008002UL;
    p[1] = 0xE;
    p[2] = (unsigned long)self->scX | (unsigned long)(self->scX + (self->scW - 1)) << 16 | (unsigned long)self->scY << 32 |
           (unsigned long)(self->scY + (self->scH - 1)) << 48;
    p[3] = 0x40;
    p[4] = (unsigned long)self->scX | (unsigned long)(self->scX + (self->scW - 1)) << 16 | (unsigned long)self->scY << 32 |
           (unsigned long)(self->scY + (self->scH - 1)) << 48;
    p[5] = 0x41;
    p += 6;
    size = ((unsigned int)p & 0x0FFFFFFF) - (unsigned int)D_004FFCC0;
    Sync_382AF0();
    func_00371940((unsigned int)D_004FFCC0, size >> 4, 6);
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00383770);
#ifdef SKIP_ASM
extern "C" void func_00383808(void *, int, int, int, int, int, int, int, int);

extern "C" int func_00383770(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    func_00424020(0);
    func_00383808(arg0, arg5, (*(int *)((char*)(arg0) + (0x5A84))) << 5, arg3, arg4, (*(int *)((char*)(arg0) + (0x5A30))), (*(int *)((char*)(arg0) + (0x5A3C))), arg1, arg2);
    return 1;
}
#endif

INCLUDE_ASM("render/particle", func_00383808);
//100%
INCLUDE_ASM("render/particle", func_00383A10);
#ifdef SKIP_ASM
// sClipPt_3A10 / sClipVtx_3A10: see func_00381AD0.

// Integer view of colour channel k of a vertex.
#define VTXCOL_3A10(v, k) (*(unsigned int*)&(v).col[k])

// Clips the line ivert[0]-ivert[1] (projected points iproj, outcodes ioutcode) against the view volume.
// Returns 0 when the line is completely outside.
extern "C" int func_00383A10(cPS2GraphicsMan* self, sClipVtx_3A10* ivert, sClipPt_3A10* iproj, int* ioutcode)
{
    int code = ioutcode[0] | ioutcode[1];
    if (code & 0x20) {
        float t = (iproj[0].w - self->wmin) / (iproj[0].w - iproj[1].w);
        int i = (ioutcode[0] & 0x20) == 0;
        float dx = iproj[0].x - iproj[1].x;
        float dy = iproj[0].y - iproj[1].y;
        float tt = t * iproj[1].w / self->wmin;
        iproj[i].x = iproj[0].x - t * dx;
        iproj[i].y = iproj[0].y - t * dy;
        iproj[i].z = self->zmin;
        iproj[i].w = self->wmin;
        ivert[i].st[0] = ivert[0].st[0] + tt * (ivert[1].st[0] - ivert[0].st[0]);
        ivert[i].st[1] = ivert[0].st[1] + tt * (ivert[1].st[1] - ivert[0].st[1]);
        VTXCOL_3A10(ivert[i], 0) = (int)(VTXCOL_3A10(ivert[0], 0) + tt * (VTXCOL_3A10(ivert[1], 0) - VTXCOL_3A10(ivert[0], 0)));
        VTXCOL_3A10(ivert[i], 1) = (int)(VTXCOL_3A10(ivert[0], 1) + tt * (VTXCOL_3A10(ivert[1], 1) - VTXCOL_3A10(ivert[0], 1)));
        VTXCOL_3A10(ivert[i], 2) = (int)(VTXCOL_3A10(ivert[0], 2) + tt * (VTXCOL_3A10(ivert[1], 2) - VTXCOL_3A10(ivert[0], 2)));
        VTXCOL_3A10(ivert[i], 3) = (int)(VTXCOL_3A10(ivert[0], 3) + tt * (VTXCOL_3A10(ivert[1], 3) - VTXCOL_3A10(ivert[0], 3)));
        ioutcode[i] = 0;
        if (iproj[i].x < self->xmin)
            ioutcode[i] = 2;
        if (iproj[i].x > self->xmax)
            ioutcode[i] |= 1;
        if (iproj[i].y < self->ymin)
            ioutcode[i] |= 8;
        if (iproj[i].y > self->ymax)
            ioutcode[i] |= 4;
        if (ioutcode[0] & ioutcode[1])
            return 0;
        code = ioutcode[0] | ioutcode[1];
    }
    if (code & 0x10) {
        float t = (iproj[0].w - self->wmax) / (iproj[0].w - iproj[1].w);
        int i = (ioutcode[0] & 0x10) == 0;
        float dx = iproj[0].x - iproj[1].x;
        float dy = iproj[0].y - iproj[1].y;
        float tt = t * iproj[1].w / self->wmax;
        iproj[i].x = iproj[0].x - t * dx;
        iproj[i].y = iproj[0].y - t * dy;
        iproj[i].z = self->zmax;
        iproj[i].w = self->wmax;
        ivert[i].st[0] = ivert[0].st[0] + tt * (ivert[1].st[0] - ivert[0].st[0]);
        ivert[i].st[1] = ivert[0].st[1] + tt * (ivert[1].st[1] - ivert[0].st[1]);
        VTXCOL_3A10(ivert[i], 0) = (int)(VTXCOL_3A10(ivert[0], 0) + tt * (VTXCOL_3A10(ivert[1], 0) - VTXCOL_3A10(ivert[0], 0)));
        VTXCOL_3A10(ivert[i], 1) = (int)(VTXCOL_3A10(ivert[0], 1) + tt * (VTXCOL_3A10(ivert[1], 1) - VTXCOL_3A10(ivert[0], 1)));
        VTXCOL_3A10(ivert[i], 2) = (int)(VTXCOL_3A10(ivert[0], 2) + tt * (VTXCOL_3A10(ivert[1], 2) - VTXCOL_3A10(ivert[0], 2)));
        VTXCOL_3A10(ivert[i], 3) = (int)(VTXCOL_3A10(ivert[0], 3) + tt * (VTXCOL_3A10(ivert[1], 3) - VTXCOL_3A10(ivert[0], 3)));
        ioutcode[i] = 0;
        if (iproj[i].x < self->xmin)
            ioutcode[i] = 2;
        if (iproj[i].x > self->xmax)
            ioutcode[i] |= 1;
        if (iproj[i].y < self->ymin)
            ioutcode[i] |= 8;
        if (iproj[i].y > self->ymax)
            ioutcode[i] |= 4;
        if (ioutcode[0] & ioutcode[1])
            return 0;
        code = ioutcode[0] | ioutcode[1];
    }
    if (code & 8) {
        float t = (iproj[0].y - self->ymin) / (iproj[0].y - iproj[1].y);
        int i = (ioutcode[0] & 8) == 0;
        float dx = iproj[0].x - iproj[1].x;
        float dz = iproj[0].z - iproj[1].z;
        float dw = iproj[0].w - iproj[1].w;
        iproj[i].x = iproj[0].x - t * dx;
        iproj[i].y = self->ymin;
        iproj[i].z = iproj[0].z - t * dz;
        iproj[i].w = iproj[0].w - t * dw;
        ivert[i].st[0] = ivert[0].st[0] + t * (ivert[1].st[0] - ivert[0].st[0]);
        ivert[i].st[1] = ivert[0].st[1] + t * (ivert[1].st[1] - ivert[0].st[1]);
        VTXCOL_3A10(ivert[i], 0) = (int)(VTXCOL_3A10(ivert[0], 0) + t * (VTXCOL_3A10(ivert[1], 0) - VTXCOL_3A10(ivert[0], 0)));
        VTXCOL_3A10(ivert[i], 1) = (int)(VTXCOL_3A10(ivert[0], 1) + t * (VTXCOL_3A10(ivert[1], 1) - VTXCOL_3A10(ivert[0], 1)));
        VTXCOL_3A10(ivert[i], 2) = (int)(VTXCOL_3A10(ivert[0], 2) + t * (VTXCOL_3A10(ivert[1], 2) - VTXCOL_3A10(ivert[0], 2)));
        VTXCOL_3A10(ivert[i], 3) = (int)(VTXCOL_3A10(ivert[0], 3) + t * (VTXCOL_3A10(ivert[1], 3) - VTXCOL_3A10(ivert[0], 3)));
        ioutcode[i] = 0;
        if (iproj[i].x < self->xmin)
            ioutcode[i] = 2;
        if (iproj[i].x > self->xmax)
            ioutcode[i] |= 1;
        if (ioutcode[0] & ioutcode[1])
            return 0;
        code = ioutcode[0] | ioutcode[1];
    }
    if (code & 4) {
        float t = (iproj[0].y - self->ymax) / (iproj[0].y - iproj[1].y);
        int i = (ioutcode[0] & 4) == 0;
        float dx = iproj[0].x - iproj[1].x;
        float dz = iproj[0].z - iproj[1].z;
        float dw = iproj[0].w - iproj[1].w;
        iproj[i].x = iproj[0].x - t * dx;
        iproj[i].y = self->ymax;
        iproj[i].z = iproj[0].z - t * dz;
        iproj[i].w = iproj[0].w - t * dw;
        ivert[i].st[0] = ivert[0].st[0] + t * (ivert[1].st[0] - ivert[0].st[0]);
        ivert[i].st[1] = ivert[0].st[1] + t * (ivert[1].st[1] - ivert[0].st[1]);
        VTXCOL_3A10(ivert[i], 0) = (int)(VTXCOL_3A10(ivert[0], 0) + t * (VTXCOL_3A10(ivert[1], 0) - VTXCOL_3A10(ivert[0], 0)));
        VTXCOL_3A10(ivert[i], 1) = (int)(VTXCOL_3A10(ivert[0], 1) + t * (VTXCOL_3A10(ivert[1], 1) - VTXCOL_3A10(ivert[0], 1)));
        VTXCOL_3A10(ivert[i], 2) = (int)(VTXCOL_3A10(ivert[0], 2) + t * (VTXCOL_3A10(ivert[1], 2) - VTXCOL_3A10(ivert[0], 2)));
        VTXCOL_3A10(ivert[i], 3) = (int)(VTXCOL_3A10(ivert[0], 3) + t * (VTXCOL_3A10(ivert[1], 3) - VTXCOL_3A10(ivert[0], 3)));
        ioutcode[i] = 0;
        if (iproj[i].x < self->xmin)
            ioutcode[i] = 2;
        if (iproj[i].x > self->xmax)
            ioutcode[i] |= 1;
        if (ioutcode[0] & ioutcode[1])
            return 0;
        code = ioutcode[0] | ioutcode[1];
    }
    if (code & 2) {
        float t = (iproj[0].x - self->xmin) / (iproj[0].x - iproj[1].x);
        int i = (ioutcode[0] & 2) == 0;
        float dy = iproj[0].y - iproj[1].y;
        float dz = iproj[0].z - iproj[1].z;
        float dw = iproj[0].w - iproj[1].w;
        iproj[i].x = self->xmin;
        iproj[i].y = iproj[0].y - t * dy;
        iproj[i].z = iproj[0].z - t * dz;
        iproj[i].w = iproj[0].w - t * dw;
        ivert[i].st[0] = ivert[0].st[0] + t * (ivert[1].st[0] - ivert[0].st[0]);
        ivert[i].st[1] = ivert[0].st[1] + t * (ivert[1].st[1] - ivert[0].st[1]);
        VTXCOL_3A10(ivert[i], 0) = (int)(VTXCOL_3A10(ivert[0], 0) + t * (VTXCOL_3A10(ivert[1], 0) - VTXCOL_3A10(ivert[0], 0)));
        VTXCOL_3A10(ivert[i], 1) = (int)(VTXCOL_3A10(ivert[0], 1) + t * (VTXCOL_3A10(ivert[1], 1) - VTXCOL_3A10(ivert[0], 1)));
        VTXCOL_3A10(ivert[i], 2) = (int)(VTXCOL_3A10(ivert[0], 2) + t * (VTXCOL_3A10(ivert[1], 2) - VTXCOL_3A10(ivert[0], 2)));
        VTXCOL_3A10(ivert[i], 3) = (int)(VTXCOL_3A10(ivert[0], 3) + t * (VTXCOL_3A10(ivert[1], 3) - VTXCOL_3A10(ivert[0], 3)));
        ioutcode[i] = 0;
    }
    if (code & 1) {
        float t = (iproj[0].x - self->xmax) / (iproj[0].x - iproj[1].x);
        int i = (ioutcode[0] & 1) == 0;
        float dy = iproj[0].y - iproj[1].y;
        float dz = iproj[0].z - iproj[1].z;
        float dw = iproj[0].w - iproj[1].w;
        iproj[i].x = self->xmax;
        iproj[i].y = iproj[0].y - t * dy;
        iproj[i].z = iproj[0].z - t * dz;
        iproj[i].w = iproj[0].w - t * dw;
        ivert[i].st[0] = ivert[0].st[0] + t * (ivert[1].st[0] - ivert[0].st[0]);
        ivert[i].st[1] = ivert[0].st[1] + t * (ivert[1].st[1] - ivert[0].st[1]);
        VTXCOL_3A10(ivert[i], 0) = (int)(VTXCOL_3A10(ivert[0], 0) + t * (VTXCOL_3A10(ivert[1], 0) - VTXCOL_3A10(ivert[0], 0)));
        VTXCOL_3A10(ivert[i], 1) = (int)(VTXCOL_3A10(ivert[0], 1) + t * (VTXCOL_3A10(ivert[1], 1) - VTXCOL_3A10(ivert[0], 1)));
        VTXCOL_3A10(ivert[i], 2) = (int)(VTXCOL_3A10(ivert[0], 2) + t * (VTXCOL_3A10(ivert[1], 2) - VTXCOL_3A10(ivert[0], 2)));
        VTXCOL_3A10(ivert[i], 3) = (int)(VTXCOL_3A10(ivert[0], 3) + t * (VTXCOL_3A10(ivert[1], 3) - VTXCOL_3A10(ivert[0], 3)));
        ioutcode[i] = 0;
    }
    return 1;
}
#endif

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

struct sPktBuilder_4E50 {
    unsigned int* where;            // 0x0
    unsigned int cur;               // 0x4 (uncached)
    unsigned int start;             // 0x8 (uncached)
    int open;                       // 0xC
};

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
        cPS2GraphicsMan* g = D_004A5B80;
        sPtRing* ring = g->ring;
        sPtRenderState* rs = g->top;
        if (ring->count < 0xA28) {
            rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
            int key = *(int*)((char*)ring + 0x69CC0);
            sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

//100%
INCLUDE_ASM("render/particle", func_003852E8);
#ifdef SKIP_ASM
struct sPartRow_52E8 {
    int f0;
    void* uv;                       // 0x4
    int f8;
    int fC;
};

struct sPartGrid_52E8 {
    char pad_0x0[0x190];
    unsigned short width;           // 0x190
    char pad_0x192[0x1A0 - 0x192];
    int sel;                        // 0x1A0
    int done;                       // 0x1A4
    char pad_0x1A8[0xC];
    sPartRow_52E8* rows[2];         // 0x1B4
    int height;                     // 0x1BC
};

extern "C" void func_00385A38_uv(void* self, void* dst, int idx, float* src) __asm__("func_00385A38");

extern "C" void func_003852E8(sPartGrid_52E8* self, float* src)
{
    int z = self->sel == 0;
    for (int r = 0; r < self->height; r++) {
        sPartRow_52E8* strip = &self->rows[z][r];
        int i0 = r * self->width;
        int i1 = i0 + self->width;
        int idx = 0;
        for (int c = 0; c < self->width; c++) {
            func_00385A38_uv(self, strip->uv, idx, src + i0 * 3);
            func_00385A38_uv(self, strip->uv, idx + 1, src + i1 * 3);
            idx += 2;
            i0++;
            i1++;
        }
    }
    self->done = 1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00385410);
#ifdef SKIP_ASM
struct sPartRow_5410 {
    int cnt;
    int f4;
    void* uv;                       // 0x8
    int fC;
};

struct sPartGrid_5410 {
    char pad_0x0[0x190];
    unsigned short width;           // 0x190
    char pad_0x192[0x1A0 - 0x192];
    int sel;                        // 0x1A0
    int done;                       // 0x1A4
    char pad_0x1A8[0xC];
    sPartRow_5410* rows[2];         // 0x1B4
    int height;                     // 0x1BC
    int stripLen;                   // 0x1C0
};

extern "C" void func_00385BA0_uv(void* self, void* dst, int idx, float* src) __asm__("func_00385BA0");

extern "C" void func_00385410(sPartGrid_5410* self, float* src)
{
    int z = self->sel == 0;
    for (int r = 0; r < self->height; r++) {
        sPartRow_5410* strip = &self->rows[z][r];
        int i0 = r * self->width;
        int i1 = i0 + self->width;
        int idx = 0;
        for (int c = 0; c < self->width; c++) {
            func_00385BA0_uv(self, strip->uv, idx, src + i0 * 2);
            func_00385BA0_uv(self, strip->uv, idx + 1, src + i1 * 2);
            idx += 2;
            i0++;
            i1++;
        }
    }
    self->done = 1;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00385530);
#ifdef SKIP_ASM
struct sPartRow_5530 {
    int f0;
    void* verts;                    // 0x4
    int f8;
    void* colors;                   // 0xC
};

struct sPartGrid_5530 {
    char pad_0x0[0x190];
    unsigned short width;           // 0x190
    char pad_0x192[0x1A0 - 0x192];
    int sel;                        // 0x1A0
    int done;                       // 0x1A4
    char pad_0x1A8[0xC];
    sPartRow_5530* rows[2];         // 0x1B4
    int height;                     // 0x1BC
};

extern "C" void func_00385A38_vt(void* self, void* dst, int idx, float* src) __asm__("func_00385A38");
extern "C" void func_00385AA0_col(void* self, void* dst, int idx, float* src) __asm__("func_00385AA0");

extern "C" void func_00385530(sPartGrid_5530* self, float* verts, float* colors)
{
    int z = self->sel == 0;
    for (int r = 0; r < self->height; r++) {
        sPartRow_5530* strip = &self->rows[z][r];
        int i0 = r * self->width;
        int i1 = i0 + self->width;
        int idx = 0;
        for (int c = 0; c < self->width; c++) {
            func_00385AA0_col(self, strip->colors, idx, colors + i0 * 4);
            func_00385A38_vt(self, strip->verts, idx, verts + i0 * 3);
            func_00385AA0_col(self, strip->colors, idx + 1, colors + i1 * 4);
            func_00385A38_vt(self, strip->verts, idx + 1, verts + i1 * 3);
            idx += 2;
            i0++;
            i1++;
        }
    }
    self->done = 1;
}
#endif

INCLUDE_ASM("render/particle", func_003856B8);

//100%
INCLUDE_ASM("render/particle", func_00385A38);
#ifdef SKIP_ASM

extern "C" void func_00385A38(void* self, short* out, int i, sPtVec3* v)
{
    float s = *(float*)((char*)self + 0x198);
    sPtVec3 t;
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

struct sBez_5C10 {
    char pad_0x0[0x194];
    float scale;                    // 0x194
    char pad_0x198[0x8];
    int buf;                        // 0x1A0
    int flip;                       // 0x1A4
    char pad_0x1A8[0x4];
    unsigned int tags[2];           // 0x1AC
    char pad_0x1B4[0x1C4 - 0x1B4];
    cPS2GraphicsMan* gfx;               // 0x1C4
};

// PORT: PS2-only VU0 inline asm (scale the rows of a 4x4 matrix by a vector).
static inline sPtMatrixV ScaleMat_5C10(const sPtMatrixV& m, const t4Vector& v)
{
    sPtMatrixV d;
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

extern "C" void func_0037E120_5C10(cPS2GraphicsMan* gfx, sPtMatrixV* m, sPtMatrixV* hdr, t4Vector* scale, int flag, int a5, int prim, char** pp) __asm__("func_0037E120");

// PORT: uncached (0x30000000) pointers held in int; 64-bit GS words are `ulong`.
extern "C" void func_00385C10(sBez_5C10* self, sPtMatrixV* mat, int tex, int flag)
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
    sPtMatrixV m = *mat;
    float s = self->scale;
    t4Vector sc;
    sc.x = s;
    sc.y = s;
    sc.z = s;
    sc.w = 1.0f;
    sPtMatrixV m2 = ScaleMat_5C10(*mat, sc);
    char* p = (char*)func_0038F460(D_004A4474, addr, -1, 0);
    func_0037E120_5C10(self->gfx, &m2, &m, &sc, flag, 0, flag ? 0x22 : 0x20, &p);
    *(ulong*)p = ((ulong)self->tags[self->buf] << 32) | 0x50000000;
    *(ulong*)(p + 8) = 0;
    p += 0x10;
    addr = func_0038F668(D_004A4474, (unsigned long*)p, 4);
    sPtRing* ring = self->gfx->ring;
    sPtRenderState* rs = self->gfx->top;
    unsigned int cur = self->gfx->bufAddr;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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
INCLUDE_ASM("render/particle", func_003865D8);
#ifdef SKIP_ASM
extern "C" void func_003865D8(void *arg0, void **arg1) {
    (*(void **)((char*)(arg0) + (8))) = (void *) *arg1;
    *arg1 = arg0;
}
#endif
//100%
INCLUDE_ASM("render/particle", func_003865E8);
#ifdef SKIP_ASM

extern "C" void func_003865E8(void* head)
{
    void* p = head;
    if (p != 0) {
        do {
            void* next = *(void**)((char*)p + 8);
            if (p != 0) {
                sPtVtVI* vt = *(sPtVtVI**)((char*)p + 4);
                vt[1].fn((char*)p + vt[1].delta, 3);
            }
            p = next;
        } while (p != 0);
    }
}
#endif

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

//100%
INCLUDE_ASM("render/particle", func_00386BD0);
#ifdef SKIP_ASM
struct sBlendMtx_6BD0 {
    float m[16];
} __attribute__((aligned(16)));

struct sBlendLink_6BD0 {
    short w;
    unsigned char idx;
    unsigned char pad;
};

struct sBlendEnt_6BD0 {
    int count;
    sBlendLink_6BD0* links;
    int pad;
};

// PORT: PS2-only VU0 inline asm (set the I register).
static inline void setI_6BD0(int bits)
{
    __asm__ volatile("ctc2.ni    %0, $vi21\n" : : "r"(bits) : "$21");
}

// PORT: PS2-only VU0 inline asm (first weighted matrix, kept in vf1-vf4).
static inline void blendFirst_6BD0(const sBlendMtx_6BD0* m, int w)
{
    __asm__ volatile(
        "qmtc2.ni   %4, $vf5\n"
        "vitof0.x   $vf5, $vf5\n"
        "lqc2       $vf1, %0\n"
        "lqc2       $vf2, %1\n"
        "vmuli.x    $vf5, $vf5, I\n"
        "lqc2       $vf3, %2\n"
        "lqc2       $vf4, %3\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        : : "m"(m->m[0]), "m"(m->m[4]), "m"(m->m[8]), "m"(m->m[12]), "r"(w));
}

// PORT: PS2-only VU0 inline asm (accumulate next weighted matrix into vf1-vf4).
static inline void blendAdd_6BD0(const sBlendMtx_6BD0* m, int w)
{
    __asm__ volatile(
        "qmtc2.ni   %4, $vf5\n"
        "vitof0.x   $vf5, $vf5\n"
        "lqc2       $vf6, %0\n"
        "lqc2       $vf7, %1\n"
        "vmuli.x    $vf5, $vf5, I\n"
        "lqc2       $vf8, %2\n"
        "lqc2       $vf9, %3\n"
        "vmulaw.xyzw ACC, $vf1, $vf0w\n"
        "vmaddx.xyzw $vf1, $vf6, $vf5x\n"
        "vmulaw.xyzw ACC, $vf2, $vf0w\n"
        "vmaddx.xyzw $vf2, $vf7, $vf5x\n"
        "vmulaw.xyzw ACC, $vf3, $vf0w\n"
        "vmaddx.xyzw $vf3, $vf8, $vf5x\n"
        "vmulaw.xyzw ACC, $vf4, $vf0w\n"
        "vmaddx.xyzw $vf4, $vf9, $vf5x\n"
        : : "m"(m->m[0]), "m"(m->m[4]), "m"(m->m[8]), "m"(m->m[12]), "r"(w));
}

// PORT: PS2-only VU0 inline asm (store vf1-vf4).
static inline void blendStore_6BD0(sBlendMtx_6BD0* d)
{
    __asm__ volatile(
        "sqc2       $vf1, %0\n"
        "sqc2       $vf2, %1\n"
        "sqc2       $vf3, %2\n"
        "sqc2       $vf4, %3\n"
        : "=m"(d->m[0]), "=m"(d->m[4]), "=m"(d->m[8]), "=m"(d->m[12]));
}

extern "C" void func_00386BD0(char* self, sBlendMtx_6BD0* mats, int unused, sBlendEnt_6BD0* ents, int n, sBlendMtx_6BD0* out)
{
    if (out == 0) {
        out = *(sBlendMtx_6BD0**)(self + 0x13E8);
    }
    setI_6BD0(0x3C23D70A);
    int i;
    for (i = 0; i < n; i++) {
        sBlendMtx_6BD0* dst = out++;
        sBlendEnt_6BD0* e = &ents[i];
        sBlendLink_6BD0* l = e->links;
        blendFirst_6BD0((sBlendMtx_6BD0*)((char*)mats + (l->idx << 6)), l->w);
        int cnt = e->count;
        l++;
        int k;
        for (k = 1; k < cnt; k++) {
            blendAdd_6BD0((sBlendMtx_6BD0*)((char*)mats + (l->idx << 6)), l->w);
            l++;
        }
        blendStore_6BD0(dst);
    }
}
#endif

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

//100%
INCLUDE_ASM("render/particle", func_00387EC0);
#ifdef SKIP_ASM
struct sPtGfx_7EC0 {
    char pad_0x0[0x5A00];
    unsigned int bufAddr;           // 0x5A00
};

struct sPair_7EC0 {
    int a;
    int b;
};

struct sVtx_7EC0 {
    sGifQuad q[3];                // 0x30 bytes
};

extern int D_004A43A0;
extern sPair_7EC0 D_004A43A8[];
extern char D_3A00[];
extern char D_3A08[];

// PORT: uncached (0x30000000) GIF/DMA packet pointers; 64-bit GS words are `ulong`.
void func_00387EC0_impl(sPtGfx_7EC0* self, sVtx_7EC0** tbl, int start, int n, int ia, int ib, int flag, float fa, float fb) __asm__("func_00387EC0");
void func_00387EC0_impl(sPtGfx_7EC0* self, sVtx_7EC0** tbl, int start, int n, int ia, int ib, int flag, float fa, float fb)
{
    unsigned int addr = (D_004A43A0 ? (unsigned int)D_3A00 : (unsigned int)D_3A08) >> 3;
    int a;
    long b;
    D_004A43A0 = 0;
    if (flag) {
        a = 0x5C;
        b = 0x412;
    } else {
        a = 4;
        b = 0x41F;
    }
    unsigned long* p = (unsigned long*)(self->bufAddr | 0x30000000);
    if (n != 0) {
        do {
            unsigned long prim = ((unsigned long)a << 47) | ((unsigned long)0x8000 << 31);
            int c = n < 0x25 ? n : 0x24;
            int lim = 0x36 - start;
            int m = c < lim ? c : lim;
            int r = c - m;
            sPair_7EC0 q = D_004A43A8[0];
            if (r < 0) {
                r = 0;
            }
            if (n <= c) {
                q.a = (start + c - 2) % 0x36;
                q.b = (start + c - 1) % 0x36;
                if (r >= 2) {
                    r -= 2;
                } else {
                    int m2 = m - 2;
                    m = m2 + r;
                    r = 0;
                }
            }
            unsigned int unpackCmd = 0x6C000000;
            p[0] = 0x10000003;
            p[3] = (unsigned long)0xD805 << 47;
            p[4] = (unsigned long)((c * 2) | 0x8000) | prim | ((unsigned long)0xC000 << 46);
            p[6] = (long)(c * 3) | ((long)c << 32);
            p[7] = *(unsigned int*)&fb | ((unsigned long)*(unsigned int*)&fa << 32);
            p[1] = 0;
            p[2] = (unsigned long)0x1000101 << 32;
            p[5] = b;
            p += 8;
            unsigned int t = 2;
            if (m != 0) {
                p[0] = 0x10000001;
                p[1] = 0;
                p[2] = (unsigned long)0x1000101 << 32;
                int m3 = m * 3;
                unsigned int hm = (m3 << 16) | 0x8000;
                p[3] = (unsigned long)((t | hm) | unpackCmd) << 32;
                p[4] = (unsigned long)(m3 | 0x30000000) | ((unsigned long)(unsigned int)((int)tbl[ia] + start * 0x30) << 32);
                p[5] = 0;
                t = m3 + 2;
                p += 6;
            }
            if (r != 0) {
                p[0] = 0x10000001;
                p[1] = 0;
                p[2] = (unsigned long)0x1000101 << 32;
                int r3 = r * 3;
                unsigned int hr = (r3 << 16) | 0x8000;
                p[3] = (unsigned long)((t | hr) | unpackCmd) << 32;
                p[4] = (unsigned long)(r3 | 0x30000000) | ((unsigned long)(unsigned int)tbl[ia] << 32);
                p[5] = 0;
                t += r3;
                p += 6;
            }
            if (q.a >= 0) {
                p[0] = 0x10000007;
                p[1] = 0;
                p[2] = (unsigned long)0x1000101 << 32;
                unsigned int lo = t | 0x68000;
                p[3] = (unsigned long)(lo | unpackCmd) << 32;
                t += 6;
                p += 4;
                *(sVtx_7EC0*)p = tbl[ia][q.a];
                p += 6;
                *(sVtx_7EC0*)p = tbl[ia][q.b];
                p += 6;
            }
            if (m != 0) {
                p[0] = 0x10000001;
                p[1] = 0;
                p[2] = (unsigned long)0x1000101 << 32;
                int m3 = m * 3;
                unsigned int hm = (m3 << 16) | 0x8000;
                p[3] = (unsigned long)((t | hm) | unpackCmd) << 32;
                p[4] = (unsigned long)(m3 | 0x30000000) | ((unsigned long)(unsigned int)((int)tbl[ib] + start * 0x30) << 32);
                p[5] = 0;
                t += m3;
                p += 6;
            }
            if (r != 0) {
                p[0] = 0x10000001;
                p[1] = 0;
                p[2] = (unsigned long)0x1000101 << 32;
                int r3 = r * 3;
                unsigned int hr = (r3 << 16) | 0x8000;
                p[3] = (unsigned long)((t | hr) | unpackCmd) << 32;
                p[4] = (unsigned long)(r3 | 0x30000000) | ((unsigned long)(unsigned int)tbl[ib] << 32);
                p[5] = 0;
                t += r3;
                p += 6;
            }
            if (q.a >= 0) {
                p[0] = 0x10000007;
                p[1] = 0;
                p[2] = (unsigned long)0x1000101 << 32;
                unsigned int lo2 = t | 0x68000;
                p[3] = (unsigned long)(lo2 | unpackCmd) << 32;
                p += 4;
                *(sVtx_7EC0*)p = tbl[ib][q.a];
                p += 6;
                *(sVtx_7EC0*)p = tbl[ib][q.b];
                p += 6;
            }
            p[0] = 0x10000001;
            p[1] = 0;
            p[2] = 0;
            p[3] = (unsigned long)(addr | 0x14000000) << 32;
            p += 4;
            fa += fb * (float)c;
            n -= c;
            if (n > 0) {
                n += 1;
                start = (start + c - 1) % 0x36;
            }
        } while (n != 0);
    }
    self->bufAddr = (unsigned int)p & 0x0FFFFFFF;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_003883B8);
#ifdef SKIP_ASM

extern int D_004A5B84;

extern "C" void func_003885E0(void* self, void* a, void* b, void* c, void* d, int i0, int i1, float f0, float f1);

// PORT: uncached (0x30000000) pointers held in int.
extern "C" void func_003883B8(cPS2GraphicsMan* self, void* a1, int n, void* a3, void* a4, void* a5, float f0, float f1)
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
    sPtRing* ring = self->ring;
    unsigned int next = self->bufAddr;
    sPtRenderState* rs = self->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sPtRingEnt* e = (sPtRingEnt*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
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

extern "C" void func_00389098(void* self, const float* c)
{
    int r = func_004139F8(c[0] * 255.0f);
    r |= func_004139F8(c[1] * 255.0f) << 8;
    r |= func_004139F8(c[2] * 255.0f) << 16;
    *(int*)((char*)self + 0x6AE0) = r;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389118);
#ifdef SKIP_ASM

extern "C" void func_00389118(void* self)
{
    func_00424880(2);
    func_00423AA0(2, *(int*)((char*)self + 0x5AC0));
    func_00424950(1);
    func_00423AD0(0, *(int*)((char*)self + 0x5AC4));
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389160);
#ifdef SKIP_ASM
extern "C" void *func_00389160(void *arg0, float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5, float fparg6, float fparg7, float arg_sp0, float arg_sp8, float arg_sp10, float arg_sp18, float arg_sp20, float arg_sp28, float arg_sp30, float arg_sp38, float arg_sp40, float arg_sp48, float arg_sp50, float arg_sp58, float arg_sp60, float arg_sp68, float arg_sp70, float arg_sp78, float arg_sp80, float arg_sp88, float arg_sp90, float arg_sp98, float arg_spA0, float arg_spA8) {
    (*(float *)((char*)(arg0) + (0x10))) = fparg3;
    (*(float *)((char*)(arg0) + (0x20))) = fparg6;
    (*(float *)((char*)(arg0) + (0x30))) = arg_sp8;
    (*(float *)((char*)(arg0) + (0x40))) = arg_sp20;
    (*(float *)((char*)(arg0) + (0x50))) = arg_sp38;
    (*(float *)((char*)(arg0) + (0x60))) = arg_sp50;
    (*(float *)((char*)(arg0) + (0x70))) = arg_sp68;
    (*(float *)((char*)(arg0) + (0x80))) = arg_sp80;
    (*(float *)((char*)(arg0) + (0x90))) = arg_sp98;
    (*(float *)((char*)(arg0) + (4))) = fparg1;
    (*(float *)((char*)(arg0) + (0))) = fparg0;
    (*(float *)((char*)(arg0) + (0x14))) = fparg4;
    (*(float *)((char*)(arg0) + (0x24))) = fparg7;
    (*(float *)((char*)(arg0) + (0x34))) = arg_sp10;
    (*(float *)((char*)(arg0) + (0x44))) = arg_sp28;
    (*(float *)((char*)(arg0) + (0x54))) = arg_sp40;
    (*(float *)((char*)(arg0) + (0x64))) = arg_sp58;
    (*(float *)((char*)(arg0) + (0x74))) = arg_sp70;
    (*(float *)((char*)(arg0) + (0x84))) = arg_sp88;
    (*(float *)((char*)(arg0) + (0x94))) = arg_spA0;
    (*(float *)((char*)(arg0) + (8))) = fparg2;
    (*(float *)((char*)(arg0) + (0x18))) = fparg5;
    (*(float *)((char*)(arg0) + (0x28))) = arg_sp0;
    (*(float *)((char*)(arg0) + (0x38))) = arg_sp18;
    (*(float *)((char*)(arg0) + (0x48))) = arg_sp30;
    (*(float *)((char*)(arg0) + (0x58))) = arg_sp48;
    (*(float *)((char*)(arg0) + (0x68))) = arg_sp60;
    (*(float *)((char*)(arg0) + (0x78))) = arg_sp78;
    (*(float *)((char*)(arg0) + (0x88))) = arg_sp90;
    (*(float *)((char*)(arg0) + (0x98))) = arg_spA8;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    (*(int *)((char*)(arg0) + (0x2C))) = 0;
    (*(int *)((char*)(arg0) + (0x3C))) = 0;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x5C))) = 0;
    (*(int *)((char*)(arg0) + (0x6C))) = 0;
    (*(int *)((char*)(arg0) + (0x7C))) = 0;
    (*(int *)((char*)(arg0) + (0x8C))) = 0;
    (*(int *)((char*)(arg0) + (0x9C))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389260);
#ifdef SKIP_ASM

extern "C" void func_00389260(t4Vector* v)
{
    for (int i = 0; i < 10; i++) {
        v[i].x = v[i].y = v[i].z = v[i].w = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389290);
#ifdef SKIP_ASM
extern "C" void func_00389290(float* dst, float* src)
{
    for (int i = 0; i < 4; i++) {
        dst[0] = src[0];
        dst[4] = src[3];
        dst[8] = -src[3];
        dst[12] = src[6];
        dst[16] = src[9];
        dst[20] = src[12];
        dst[24] = src[15];
        dst[28] = src[18];
        dst[32] = src[21];
        dst[36] = src[24];
        dst++;
        src++;
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
extern "C" void func_00389590(t4Vector* a, t4Vector* b, t4Vector* c, float s)
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

// Integrates the w channel of ten particle vectors: dst.w += src.w * dt.
extern "C" void func_00389620(sPtVec4u* dst, sPtVec4u* src, float dt)
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
INCLUDE_ASM("render/particle", func_00389660);
#ifdef SKIP_ASM

extern "C" void func_00389660(sPtVec4u* v, float* q)
{
    for (int i = 0; i < 10; i++) {
        v[i].x *= q[1];
        v[i].y *= q[2];
        v[i].z *= q[3];
        v[i].w *= q[0];
    }
}
#endif
//100%
INCLUDE_ASM("render/particle", func_003896C0);
#ifdef SKIP_ASM

extern "C" void func_003896C0(sPtVec4u* v, float* q, float s)
{
    for (int i = 0; i < 10; i++) {
        v[i].x = v[i].x * s * q[1];
        v[i].y = v[i].y * s * q[2];
        v[i].z = v[i].z * s * q[3];
        v[i].w = v[i].w * s * q[0];
    }
}
#endif

//100%
INCLUDE_ASM("render/particle", func_00389730);
#ifdef SKIP_ASM
struct sPartVec4x10 {
    t4Vector v[10];
};

// PORT: VU0 macro-mode vector add; the PC port needs plain C.
static inline t4Vector sPartVec4_add(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
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
static inline t4Vector sPartVec4_scale(const t4Vector& a, float s)
{
    t4Vector r;
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
extern "C" t4Vector* func_00389810(t4Vector* v, float s)
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
extern "C" void func_00389CB8(t4Vector* self, void* p, float s);
extern int D_004A43C4;

struct sPartLib_9C38 {
    int f0;
    int count;      // 0x4
    void* items;    // 0x8
};
extern sPartLib_9C38 D_005047F8;
extern t4Vector D_00504810;

extern "C" void func_00389C38(t4Vector* self, void* p)
{
    func_00389260(self);
    sPartLib_9C38* lib = &D_005047F8;
    if (lib->count > 0) {
        func_00389590(self, (t4Vector*)func_0038ABF8(lib, D_004A43C4), &D_00504810, 1.0f);
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

