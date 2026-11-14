#include "common.h"

//100%
INCLUDE_ASM("visualfx/boardsparkfx", cBoardSparkFX_cBoardSparkFX);
#ifdef SKIP_ASM
// g++ 2.95 vtable entry (no thunks): {delta, index, fn}. Vtables are double-aligned.
struct sVtEntBS {
    short delta;
    short index;
    void* fn;
};

struct sVt9_BS {
    sVtEntBS e[9];
} __attribute__((aligned(8)));

struct sVt22_BS {
    sVtEntBS e[22];
} __attribute__((aligned(8)));

extern const sVt9_BS D_00488CB0;
extern const sVt22_BS D_00488CF8;
extern char D_00459B90[];
extern char D_00487588[];
extern char D_00487598[];
extern char D_004875A8[];

extern "C" void* cRider_cRider(void* self);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_003714B8(void* self);
void* func_002F7A68(void* self);
extern "C" void func_0036CCB8(void* self);
extern "C" void func_0036CE00(void* self, float a, float b, float c);
extern "C" void func_0036CE28(void* self, float a, float b);
extern "C" void func_0036D008(void* self);
extern "C" void func_0036D3D8(void* self, float val);
extern "C" void func_00416210(void* dst, int c, int n);
extern "C" void func_002DAA78(void* self);

struct sBsVec4 {
    float x, y, z, w;
    sBsVec4() {}
};

extern "C" void func_0036CBF8(void* sys, int w, int h, float x, float y, float s, sBsVec4* v);

struct sBsIds {
    short id[2];
    sBsIds()
    {
        for (unsigned int i = 0; i < 2; i++) {
            id[i] = -1;
        }
    }
};

struct sBsSlot {
    char data[0x10];
    sBsIds ids;
    sBsSlot() { func_00416210(data, 0, 0x10); }
    void* operator new(unsigned int, void* p) { return p; }
};

struct sBsElem {
    float v[4];
    sBsElem() {}
    void* operator new[](unsigned int, void* p) { return p; }
};

struct sBsParams {
    int mode;           // 0x00
    int f04;            // 0x04
    float f08;          // 0x08
    float f0C;          // 0x0C
    float f10;          // 0x10
    float f14;          // 0x14
    float f18;          // 0x18
    float f1C[13];      // 0x1C
    float f50;          // 0x50
    float f54;          // 0x54
    float f58;          // 0x58
    float f5C;          // 0x5C
    float f60;          // 0x60
    float f64;          // 0x64
    float f68;          // 0x68
    float f6C;          // 0x6C
    float f70;          // 0x70
    float f74;          // 0x74
    float f78;          // 0x78
    float f7C;          // 0x7C
    float f80;          // 0x80
    float f84;          // 0x84
    float f88;          // 0x88
    float f8C;          // 0x8C
    float f90;          // 0x90
    float f94;          // 0x94
    float f98;          // 0x98
    float f9C;          // 0x9C
    float fA0;          // 0xA0
    float fA4[8];       // 0xA4
    int count;          // 0xC4
    int fC8;            // 0xC8
    float fCC;          // 0xCC
    int fD0;            // 0xD0
    float fD4;          // 0xD4
};

struct sBsVE {
    short delta;
    short index;
    void (*fn)(void*, sBsParams*, float);
};

struct sBsEmitter {
    char pad0[0x58];
    float rate;         // 0x58
    char pad5C[0x1F8 - 0x5C];
    sBsVE* vt;          // 0x1F8
};

struct cBoardSparkFX {
    char* vbase;            // 0x00
    char pad04[0x1C];
    sBsEmitter* emitter;    // 0x20
    sBsParams* params;      // 0x24
    void* gfx;              // 0x28
    char pad2C[0x40];
    int active;             // 0x6C
    char pad70[0xC];
    sBsSlot slotA;          // 0x7C
    sBsSlot slotB;          // 0x90
};

// PORT: hand-written form of g++ 2.95's constructor for a class with a virtual base
// (cRider at +0xB0): vtable copies with delta fixups when not in charge.
extern "C" void* cBoardSparkFX_cBoardSparkFX(cBoardSparkFX* self, int inChrg)
{
    sVt9_BS t1;
    sVt22_BS t2;
    if (inChrg) {
        self->vbase = (char*)self + 0xB0;
        cRider_cRider((char*)self + 0xB0);
    }
    *(const void**)(self->vbase + 0x6E8) = &D_00488CB0;
    *(void**)(self->vbase + 0x6D0) = D_00459B90;
    *(const void**)(self->vbase + 0x6C0) = &D_00488CF8;
    if (inChrg == 0) {
        int vc;
        t1 = D_00488CB0;
        *(void**)(self->vbase + 0x6E8) = &t1;
        {
            char* vbo = self->vbase - 0xB0;
            vc = (char*)self - vbo;
        }
        t1.e[1].delta = D_00488CB0.e[1].delta + vc;
        t2 = D_00488CF8;
        *(void**)(self->vbase + 0x6C0) = &t2;
        t2.e[1].delta = D_00488CF8.e[1].delta + vc;
    }
    new ((char*)self + 0x2C) sBsElem[3];
    self->active = 1;
    new (&self->slotA) sBsSlot;
    new (&self->slotB) sBsSlot;
    self->emitter = (sBsEmitter*)func_003714B8(cMemMan_alloc(0x210, D_00487588, 0, 0));
    self->params = (sBsParams*)cMemMan_alloc(0xD8, D_00487598, 0, 0);
    self->gfx = func_002F7A68(cMemMan_alloc(0x150, D_004875A8, 0, 0));
    func_0036CCB8(self->gfx);
    sBsVec4 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = -3000.0f;
    v.w = 0.0f;
    func_0036CBF8(self->gfx, 0x1E, 8, 0.4000000059604645f, 0.012000000104308128f, 1.5f, &v);
    func_0036CE00(self->gfx, 7.5f, 0.0f, 7.5f);
    func_0036CE28(self->gfx, 0.10000000149011612f, 0.1940000057220459f);
    func_0036D008(self->gfx);
    func_0036D3D8(self->gfx, 0.0f);
    self->params->mode = 1;
    self->params->f04 = 0;
    self->params->f08 = -1.0f;
    self->params->f0C = 1.0f;
    self->params->f10 = 6.0f;
    self->params->f14 = 4.0f;
    self->params->f18 = 6.0f;
    self->params->f1C[0] = 0.0f;
    self->params->f1C[1] = 0.0f;
    self->params->f1C[2] = 0.0f;
    self->params->f1C[3] = 0.0f;
    self->params->f1C[4] = 0.0f;
    self->params->f1C[5] = 0.0f;
    self->params->f1C[6] = 0.0f;
    self->params->f1C[7] = 0.0f;
    self->params->f1C[8] = 0.0f;
    self->params->f1C[9] = 0.0f;
    self->params->f1C[10] = 0.0f;
    self->params->f1C[11] = 0.0f;
    self->params->f1C[12] = 0.0f;
    self->params->f50 = 600.0f;
    self->params->f54 = 200.0f;
    self->params->f58 = 0.0f;
    self->params->f5C = 0.0f;
    self->params->f60 = 0.0f;
    self->params->f64 = 200.0f;
    self->params->f68 = 0.0f;
    self->params->f6C = 0.0f;
    self->params->f70 = 0.0f;
    self->params->f74 = 100.0f;
    self->params->f78 = 0.0f;
    self->params->f7C = 0.0f;
    self->params->f80 = -800.0f;
    self->params->f84 = 1.0f;
    self->params->f88 = 1.0f;
    self->params->f8C = 1.0f;
    self->params->f90 = 1.0f;
    self->params->f94 = 0.0f;
    self->params->f98 = 0.21559999883174896f;
    self->params->f9C = 0.18000000715255737f;
    self->params->fA0 = 0.13699999451637268f;
    self->params->fA4[0] = 0.0f;
    self->params->fA4[1] = 0.0f;
    self->params->fA4[2] = 0.0f;
    self->params->fA4[3] = 0.0f;
    self->params->fA4[4] = 0.0f;
    self->params->fA4[5] = 0.0f;
    self->params->fA4[6] = 0.0f;
    self->params->fA4[7] = 0.0f;
    self->params->fC8 = 1;
    self->params->fCC = 6.0f;
    self->params->count = 5;
    self->params->fD0 = 8;
    self->params->fD4 = 27.0f;
    self->params->count = 14;
    sBsEmitter* em = self->emitter;
    em->vt[3].fn((char*)em + em->vt[3].delta, self->params, em->rate);
    self->active = 0;
    func_002DAA78(self);
    return self;
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_bsf {
public:
    virtual ~cRiderVbA0_bsf();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_bsf : public cRiderVbA0_bsf { public: char padA[0xC]; };
class cRiderVbB0_bsf { public: virtual void b01(); };
class cRiderVbB_bsf : public cRiderVbB0_bsf { public: char padB[0x14]; };
class cRiderVbC0_bsf {
public:
    virtual ~cRiderVbC0_bsf();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_bsf : public cRiderVbC0_bsf { public: char padC[0x10]; };
class cRiderVbBC_bsf : public cRiderVbB_bsf, public cRiderVbC_bsf { public: };
class cRiderVbPad_bsf { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_bsf : public cRiderVbPad_bsf, public cRiderVbA_bsf, public cRiderVbBC_bsf {
public:
    virtual ~cRiderVb_bsf();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("visualfx/boardsparkfx", func_002DA8E8);
#ifdef SKIP_ASM
class cVbMember002DA8E8 {
public:
    char pad[0x1F8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~cVbMember002DA8E8();
};

class cVbDtor002DA8E8 : virtual public cRiderVb_bsf {
public:
    char pad04[0x1C];
    cVbMember002DA8E8* m20;
    void* m24;
    void* m28;
    char pad2C[0x80];
    virtual ~cVbDtor002DA8E8();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002DA8E8::~cVbDtor002DA8E8()
{
    delete m20;
    operator_delete((int*)m24);
    operator_delete((int*)m28);
}
// PORT: the compiler names this dtor _$_15cVbDtor002DA8E8; expose it under the address-derived name.
__asm__(".globl func_002DA8E8\n.type func_002DA8E8,@function\nfunc_002DA8E8 = _$_15cVbDtor002DA8E8\n.size func_002DA8E8,0x18C\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardsparkfx", func_002DAA78);
#ifdef SKIP_ASM
struct sV4_AA78 { float x, y, z, w; } __attribute__((aligned(16)));
struct sRS_AA78 {
    int f0;
    int flagsA;     // 0x4
    int flagsB;     // 0x8
    int fC;
    short tex;      // 0x10
    short pad;
};
extern sV4_AA78 D_004FF130;
extern sRS_AA78 D_00501420_AA78 __asm__("D_00501420");
extern char* D_004A289C_AA78 __asm__("D_004A289C");

// Render-state field setters (mask, shift, value), as the unit's other effects write them.
#define RS_SETA_AA78(rs, mask, shift, v) ((rs).flagsA = ((rs).flagsA & ~(mask)) | (((v) << (shift)) & (mask)))
#define RS_SETB_AA78(rs, mask, shift, v) ((rs).flagsB = ((rs).flagsB & ~(mask)) | (((v) << (shift)) & (mask)))

struct sSparkFx_AA78 {
    char pad0[0x10];
    sV4_AA78 pos;           // 0x10
    char pad20[0x50];
    int f70, f74, f78;      // 0x70
    sRS_AA78 rsA;           // 0x7C
    sRS_AA78 rsB;           // 0x90
};

// Spark FX init: two render states copied from the defaults with their mode bits set (the second also sets f0 bits 2-3).
extern "C" void func_002DAA78(void* vself)
{
    sSparkFx_AA78* self = (sSparkFx_AA78*)vself;
    self->pos = D_004FF130;
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = 0;
    self->rsA = D_00501420_AA78;
    RS_SETB_AA78(self->rsA, 0x3E0, 5, 7);
    RS_SETA_AA78(self->rsA, 0x400000, 22, 1);
    RS_SETA_AA78(self->rsA, 0x1800000, 23, 0);
    RS_SETA_AA78(self->rsA, 0x300000, 20, 0);
    RS_SETA_AA78(self->rsA, 0xFF000, 12, 0);
    RS_SETA_AA78(self->rsA, 0x3, 0, 2);
    RS_SETA_AA78(self->rsA, 0x7C, 2, 7);
    int texA = *(int*)(D_004A289C_AA78 + 0xFA8);
    self->rsA.tex = texA;
    self->rsB = D_00501420_AA78;
    RS_SETB_AA78(self->rsB, 0x3E0, 5, 7);
    RS_SETA_AA78(self->rsB, 0x400000, 22, 1);
    RS_SETA_AA78(self->rsB, 0x1800000, 23, 0);
    RS_SETA_AA78(self->rsB, 0x300000, 20, 0);
    RS_SETA_AA78(self->rsB, 0xFF000, 12, 9);
    RS_SETA_AA78(self->rsB, 0x3, 0, 2);
    RS_SETA_AA78(self->rsB, 0x7C, 2, 7);
    int texB = *(int*)(D_004A289C_AA78 + 0xFA8);
    self->rsB.tex = texB;
    self->rsB.f0 |= 0xC;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardsparkfx", func_002DABC8);
#ifdef SKIP_ASM
struct sV4_ABC8 {
    float x, y, z, w;
    sV4_ABC8() {}
    sV4_ABC8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sVE_ABC8 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMtx_ABC8 {
    sV4_ABC8 r0, r1, r2, r3;
};

// Spark colour at the start of each 0xF0-byte surface record (only 4-byte aligned).
struct sSurfCol_ABC8 {
    float a, r, g, b;
};
struct sSurface_ABC8 {
    sSurfCol_ABC8 col;
    char pad10[0xE0];
};
extern sSurface_ABC8 D_004FA398[];

// Per-rider trick/event flags (0xB0 bytes each).
struct sRiderStats_ABC8 {
    char pad0[0x88];
    int f88;
    int f8C;
    char pad90[0x20];
};

struct sSparkFx_ABC8 {
    char* rider;                // 0x00
    char pad04[0xC];
    sV4_ABC8 pos;               // 0x10
    sBsEmitter* emitter;        // 0x20
    sBsParams* params;          // 0x24
    void* gfx;                  // 0x28
    char pad2C[4];
    sV4_ABC8 sparks[3];         // 0x30
    float sparkSize[3];         // 0x60
    int active;                 // 0x6C
    int f70;                    // 0x70
    int f74;                    // 0x74
    int f78;                    // 0x78
};

extern char* D_004A5B64;
extern char* D_004A28A8;
extern int D_004A3AFC;
extern int D_004A4728;
extern int D_004A472C;

int func_0011FE98(void* rider);
extern "C" void func_0036D428(void* gfx, float dt);
extern "C" void func_003717C0_ABC8(void* emitter, const sV4_ABC8* pos, const sV4_ABC8* vel,
                                   const sV4_ABC8* col, int on, float dt) __asm__("func_003717C0");
extern "C" void func_0036D318(void* gfx, const sV4_ABC8& a, const sV4_ABC8& b, const sV4_ABC8& c,
                              const sV4_ABC8& d, float t);
extern "C" void func_0036D1F0(void* gfx, const sV4_ABC8& a, const sV4_ABC8& b, const sV4_ABC8& c,
                              const sV4_ABC8& d);
extern "C" void func_0036CEF8(void* gfx, const sV4_ABC8& p, const sV4_ABC8& a, const sV4_ABC8& b);

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sV4_ABC8 Scale_ABC8(const sV4_ABC8& v, float s)
{
    sV4_ABC8 r;
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

// PORT: PS2-only VU0 inline asm (in-place v *= s).
static inline void ScaleEq_ABC8(sV4_ABC8& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "lqc2      $vf4, %0\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sV4_ABC8 Add_ABC8(const sV4_ABC8& a, const sV4_ABC8& b)
{
    sV4_ABC8 r;
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

// PORT: PS2-only VU0 inline asm (a - b).
static inline sV4_ABC8 Sub_ABC8(const sV4_ABC8& a, const sV4_ABC8& b)
{
    sV4_ABC8 r;
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_ABC8(const sV4_ABC8& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: the seed is reinterpreted as a float in [1,2) through memory (type pun).
static inline float Rand_ABC8()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

static inline float RandRange_ABC8(float lo, float hi)
{
    return lo + (hi - lo) * Rand_ABC8();
}

#define MIN_ABC8(a, b) ((a) < (b) ? (a) : (b))

// Sets the four components of a vector.
#define SET4_ABC8(v, a, b, c, d) ((v).x = (a), (v).y = (b), (v).z = (c), (v).w = (d))

// cRider::getSide (by value).
static inline sV4_ABC8 GetSide_ABC8(char* r)
{
    return *(sV4_ABC8*)(r + 0x1A0);
}


// Bone matrix of the rider's model; off is the cRider field holding the bone index.
static inline sMtx_ABC8* Bone_ABC8(char* r, int off)
{
    return &((sMtx_ABC8*)*(char**)(*(char**)(r + 0x780) + 0x34))[*(int*)(r + off)];
}

// Row i of a matrix, by value.
static inline sV4_ABC8 Row_ABC8(const sMtx_ABC8* m, int i)
{
    return (&m->r0)[i];
}

// Board spark update: emits sparks from the board while grinding fast, drives the glow sprite and the
// occasional sparkle bursts.
extern "C" void func_002DABC8(sSparkFx_ABC8* self)
{
    sRiderStats_ABC8* stats =
        &((sRiderStats_ABC8*)*(char**)(*(char**)(D_004A28A8 + 0x84) + 0x44))[*(int*)(self->rider + 0x438)];
    func_0036D428(self->gfx, 1.0f / (float)*(int*)(D_004A5B64 + 0x10));
    if (self->active) {
        sBsEmitter* em = self->emitter;
        em->vt[3].fn((char*)em + em->vt[3].delta, self->params, em->rate);
        self->active = 1;
    }
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = 0;
    float speed = Length_ABC8(*(sV4_ABC8*)(self->rider + 0x1E0));
    int fast = speed > 277.77777f;
    int air = func_0011FE98(self->rider) == 4;
    if (fast) {
        if (stats->f8C) {
            self->f70 = 1;
            if (air) {
                self->f74 = 1;
            }
        }
        if ((air && stats->f88) || *(int*)(self->rider + 0x438) == 9) {
            self->f78 = 1;
        }
    }
    sV4_ABC8 pos = Add_ABC8(*(sV4_ABC8*)(self->rider + 0x460),
                            Scale_ABC8(*(sV4_ABC8*)(self->rider + 0x1E0), 0.01f));
    self->pos = pos;
    if (self->f78) {
        sV4_ABC8 color;
        float maxp = 0.6f;
        if (*(int*)(self->rider + 0x438) == 9) {
            sV4_ABC8 c;
            SET4_ABC8(c, 0.2156f, 0.18f, 0.137f, 1.0f);
            color = c;
            maxp = 0.1f;
        } else {
            char* sub = self->rider + 0x6C0;
            sVE_ABC8* vt = *(sVE_ABC8**)sub;
            int type = vt[7].fn(sub + vt[7].delta);
            sSurfCol_ABC8 c = D_004FA398[type].col;
            sV4_ABC8 t;
            SET4_ABC8(t, c.r, c.g, c.b, c.a);
            color = t;
            ScaleEq_ABC8(color, 2.0f);
            color.w = 1.0f;
        }
        sV4_ABC8 side = Scale_ABC8(Scale_ABC8(GetSide_ABC8(self->rider), speed), 0.25f);
        sV4_ABC8 vel = Sub_ABC8(Add_ABC8(Scale_ABC8(*(sV4_ABC8*)(self->rider + 0x1E0), 1.2f), side),
                                Scale_ABC8(side, Rand_ABC8() * 2.0f));
        float lim = MIN_ABC8(speed / 1666.6667f * 0.1f, maxp);
        int on = Rand_ABC8() < lim;
        func_003717C0_ABC8(self->emitter, &pos, &vel, &color, on, 0.016666668f);
    } else {
        func_003717C0_ABC8(self->emitter, &pos, 0, 0, 0, 0.016666668f);
    }
    if (self->f70) {
        const sV4_ABC8& b0 = Row_ABC8(Bone_ABC8(self->rider, 0x8A4), 2);
        const sV4_ABC8& b1 = Row_ABC8(Bone_ABC8(self->rider, 0x8A4), 0);
        int hot = 0;
        if (D_004A472C || D_004A4728 || *(float*)(self->rider + 0x2F0) > 0.0f) {
            hot = 1;
        }
        {
            sV4_ABC8 a, b, c, d;
            if (hot) {
                SET4_ABC8(a, 255.0f, 0.0f, 255.0f, 153.0f);
                SET4_ABC8(b, 255.0f, 0.0f, 255.0f, 102.0f);
                SET4_ABC8(c, 0.0f, 0.0f, 0.0f, 0.0f);
                SET4_ABC8(d, 0.0f, 0.0f, 0.0f, 0.0f);
                func_0036D318(self->gfx, a, b, c, d, 0.194f);
            } else {
                SET4_ABC8(a, 77.0f, 77.0f, 255.0f, 153.0f);
                SET4_ABC8(b, 255.0f, 51.0f, 51.0f, 102.0f);
                SET4_ABC8(c, 0.0f, 0.0f, 0.0f, 0.0f);
                SET4_ABC8(d, 0.0f, 0.0f, 0.0f, 0.0f);
                func_0036D318(self->gfx, a, b, c, d, 0.194f);
            }
            SET4_ABC8(a, 0.0f, 0.0f, 400.0f, 0.0f);
            SET4_ABC8(b, 600.0f, 0.0f, 0.0f, 0.0f);
            SET4_ABC8(c, 0.0f, 600.0f, 0.0f, 0.0f);
            SET4_ABC8(d, 0.0f, 0.0f, 600.0f, 0.0f);
            func_0036D1F0(self->gfx, a, b, c, d);
        }
        if (air) {
            func_0036CEF8(self->gfx, pos, Scale_ABC8(b0, 10.0f), Scale_ABC8(b1, 10.0f));
        } else {
            func_0036CEF8(self->gfx, pos, Scale_ABC8(b0, 15.0f), Scale_ABC8(b1, 90.0f));
        }
    }
    if (self->f74 && Rand_ABC8() > 0.7f) {
        for (int i = 0; i < 3; i++) {
            self->sparkSize[i] = RandRange_ABC8(20.0f, 30.0f);
            self->sparks[i] = Add_ABC8(self->pos, sV4_ABC8(RandRange_ABC8(-4.0f, 4.0f), RandRange_ABC8(-4.0f, 4.0f),
                                                           RandRange_ABC8(-4.0f, 4.0f), 0.0f));
        }
    } else {
        self->f74 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardsparkfx", func_002DB478);
#ifdef SKIP_ASM
extern "C" void func_00371688(void* self, int a1);

struct sRS_B478 {
    int v[5];
};
struct sRenderCtx_B478 {
    char pad[0xE84];
    sRS_B478* top;
};
extern sRenderCtx_B478* D_004A289C;
extern char* D_004A5B80;

struct sVec2_B478 {
    float x, y;
    sVec2_B478(float ax, float ay) : x(ax), y(ay) {}
};
struct sVec4_B478 {
    float x, y, z, w;
    sVec4_B478(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

// Function-local statics `uv0(0,0)`, `uv1(1,1)`, `col(1,1,1,1)` and their init guards, spelled out
// as the globals splat named.
extern float D_004A54D0;
extern float D_004A54D4;
extern int D_004A54D8;
extern float D_004A54E0;
extern float D_004A54E4;
extern int D_004A54E8;
extern int D_004A54EC;
extern sVec4_B478 D_004D57A0;

struct sVE_B478a {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sVE_B478b {
    short delta;
    short index;
    void (*fn)(void*, void*, sVec2_B478*, const sVec2_B478*, const sVec2_B478*, const sVec4_B478*);
};

static inline void push_B478(sRenderCtx_B478* ctx)
{
    ctx->top[1] = ctx->top[0];
    ctx->top++;
}

static inline void pop_B478(sRenderCtx_B478* ctx)
{
    ctx->top--;
}

extern "C" void func_002DB478(char* self)
{
    char* o = *(char**)(self + 0x20);
    if (*(int*)(o + 0x1E0) > 0) {
        func_00371688(o, 7);
    }
    if (*(int*)(self + 0x70) != 0) {
        push_B478(D_004A289C);
        *D_004A289C->top = *(sRS_B478*)(self + 0x7C);
        char* ctx = (char*)D_004A289C;
        sVE_B478a* vt = *(sVE_B478a**)(ctx + 0x10D8);
        vt[82].fn(ctx + vt[82].delta, *(int*)(self + 0x28));
        pop_B478(D_004A289C);
    }
    if (*(int*)(self + 0x74) != 0) {
        push_B478(D_004A289C);
        *D_004A289C->top = *(sRS_B478*)(self + 0x90);
        if (D_004A54D8 == 0) {
            D_004A54D8 = 1;
            D_004A54D0 = 0.0f;
            D_004A54D4 = 0.0f;
        }
        if (D_004A54E8 == 0) {
            D_004A54E8 = 1;
            D_004A54E0 = 1.0f;
            D_004A54E4 = 1.0f;
        }
        if (D_004A54EC == 0) {
            D_004A54EC = 1;
            D_004D57A0.x = 1.0f;
            D_004D57A0.y = 1.0f;
            D_004D57A0.z = 1.0f;
            D_004D57A0.w = 1.0f;
        }
        sVec2_B478* uv0 = (sVec2_B478*)&D_004A54D0;
        sVec2_B478* uv1 = (sVec2_B478*)&D_004A54E0;
        for (int i = 0; i < 3; i++) {
            sVec2_B478 size(((float*)(self + 0x60))[i], ((float*)(self + 0x60))[i]);
            char* ctx = D_004A5B80;
            sVE_B478b* vt = *(sVE_B478b**)(ctx + 0x10D8);
            vt[78].fn(ctx + vt[78].delta, self + 0x30 + i * 0x10, &size, uv0, uv1, &D_004D57A0);
        }
        pop_B478(D_004A289C);
    }
}
#endif

