#include "common.h"

//100%
INCLUDE_ASM("visualfx/boardtrailfx", cBoardTrailFX_initialize);
#ifdef SKIP_ASM
extern "C" void* cRider_cRider(void* self);
extern "C" void* func_003E6448(void* p, int c, int n);
struct func_002E8560_sTrail;
extern "C" void func_002E8560(func_002E8560_sTrail* self);
extern char D_00459B90[];
extern char D_00487B20[];

// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

struct sBTVtEnt {
    short delta;
    short index;
    void* fn;
};
struct sBTVt9 {
    sBTVtEnt e[9];
} __attribute__((aligned(8)));
struct sBTVt22 {
    sBTVtEnt e[22];
} __attribute__((aligned(8)));

extern const sBTVt9 D_00488BB8;
extern const sBTVt22 D_00488C00;

struct sBTTrailVtx {
    float v[12];
    sBTTrailVtx() {}
};

struct cBoardTrailFX {
    char* vbase;                // 0x00
    int f04;                    // 0x04
    int f08;                    // 0x08
    int fC;                     // 0x0C
    sBTTrailVtx* strip[6];      // 0x10
    int f28;                    // 0x28
    short ids[48];              // 0x2C
};

// PORT: hand-written form of g++ 2.95's constructor for a class with a virtual base
// (cRider at +0xF0): vtable copies with delta fixups when not in charge.
extern "C" void* cBoardTrailFX_initialize(cBoardTrailFX* self, int inChrg)
{
    if (inChrg) {
        self->vbase = (char*)self + 0xF0;
        cRider_cRider((char*)self + 0xF0);
    }
    *(const void**)(self->vbase + 0x6E8) = &D_00488BB8;
    *(void**)(self->vbase + 0x6D0) = D_00459B90;
    *(const void**)(self->vbase + 0x6C0) = &D_00488C00;
    if (inChrg == 0) {
        int vc;
        sBTVt9 t1 = D_00488BB8;
        *(void**)(self->vbase + 0x6E8) = &t1;
        {
            char* vbo = self->vbase - 0xF0;
            vc = (char*)self - vbo;
        }
        t1.e[1].delta = D_00488BB8.e[1].delta + vc;
        sBTVt22 t2 = D_00488C00;
        *(void**)(self->vbase + 0x6C0) = &t2;
        t2.e[1].delta = D_00488C00.e[1].delta + vc;
    }
    self->f28 = 0;
    int i;
    for (i = 0; i < 48; i++) {
        self->ids[i] = -1;
    }
    sBTTrailVtx** s = self->strip;
    s[0] = new (D_00487B20, 0, 0) sBTTrailVtx[324];
    for (i = 1; i < 6; i++) {
        s[i] = self->strip[0] + i * 54;
    }
    self->fC = 0;
    func_003E6448(self->strip[0], 0, 0x3CC0);
    func_002E8560((func_002E8560_sTrail*)self);
    return self;
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_btf {
public:
    virtual ~cRiderVbA0_btf();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_btf : public cRiderVbA0_btf { public: char padA[0xC]; };
class cRiderVbB0_btf { public: virtual void b01(); };
class cRiderVbB_btf : public cRiderVbB0_btf { public: char padB[0x14]; };
class cRiderVbC0_btf {
public:
    virtual ~cRiderVbC0_btf();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_btf : public cRiderVbC0_btf { public: char padC[0x10]; };
class cRiderVbBC_btf : public cRiderVbB_btf, public cRiderVbC_btf { public: };
class cRiderVbPad_btf { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_btf : public cRiderVbPad_btf, public cRiderVbA_btf, public cRiderVbBC_btf {
public:
    cRiderVb_btf();
    virtual ~cRiderVb_btf();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002E83F0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

class cVbDtor002E83F0 : virtual public cRiderVb_btf {
public:
    char pad04[0xC];
    void* m10;
    char pad14[0xD8];
    virtual ~cVbDtor002E83F0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002E83F0::~cVbDtor002E83F0()
{
    if (m10 != 0) cMemMan_free(m10);
}
// PORT: the compiler names this dtor _$_15cVbDtor002E83F0; expose it under the address-derived name.
__asm__(".globl func_002E83F0\n.type func_002E83F0,@function\nfunc_002E83F0 = _$_15cVbDtor002E83F0\n.size func_002E83F0,0x170\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002E8560);
#ifdef SKIP_ASM
struct func_002E8560_sVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct func_002E8560_sVtx {
    float x, y, z;
    char pad[0x24];
};

struct func_002E8560_sTrail {
    int f0;
    float f4;
    float f8;
    int fC;
    float* v10;
    float* v14;
    float* v18;
    float* v1C;
    float* v20;
    float* v24;
    char pad28[0x8C - 0x28];
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
    int fA0;
    int fA4;
    char padA8[8];
    func_002E8560_sVec4 colB0;
    func_002E8560_sVec4 colC0;
    func_002E8560_sVec4 colD0;
    int fE0;
};

extern func_002E8560_sVec4 D_004FF130;
extern func_002E8560_sVec4 D_004FF120;
extern float D_004A45B0;
extern float D_004A45B4;
extern float D_004A45B8;

extern "C" void func_002E8560(func_002E8560_sTrail* self)
{
    self->f94 = 2;
    self->f90 = 0;
    self->f8C = 0;
    self->f98 = 0;
    self->f9C = 0;
    self->fA0 = 0;
    self->fA4 = 0;
    self->colB0 = D_004FF130;
    self->colC0 = D_004FF120;
    self->colD0 = D_004FF120;
    self->f4 = 1.0f;
    self->f8 = 1.0f;
    self->fE0 = 0;
    for (int i = 0; i < 54; i++) {
        float t = (float)(i & 1);
        self->v18[i * 12] = D_004A45B8;
        self->v10[i * 12] = D_004A45B4;
        self->v1C[i * 12] = D_004A45B0;
        self->v20[i * 12] = 1.0f - D_004A45B0;
        self->v14[i * 12] = 1.0f - D_004A45B4;
        self->v24[i * 12] = 1.0f - D_004A45B8;
        self->v18[i * 12 + 1] = self->v10[i * 12 + 1] = self->v1C[i * 12 + 1] = self->v20[i * 12 + 1] = self->v14[i * 12 + 1] = self->v24[i * 12 + 1] = t;
        self->v18[i * 12 + 2] = self->v10[i * 12 + 2] = self->v1C[i * 12 + 2] = self->v20[i * 12 + 2] = self->v14[i * 12 + 2] = self->v24[i * 12 + 2] = 1.0f;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002E86F0);
#ifdef SKIP_ASM
struct sBTV4_86F0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// The trail part of cBoardTrailFX that this function uses (see func_002E8938's sBTrail_8938).
struct sBTrail_86F0 {
    char* rider;                // 0x00 virtual base pointer (the cRider part)
    char pad04[0x94 - 0x04];
    int state;                  // 0x94
    char pad98[0xB0 - 0x98];
    sBTV4_86F0 lastPos;         // 0xB0
    char padC0[0xE0 - 0xC0];
    int delay;                  // 0xE0
};

// PORT: PS2-only VU0 inline asm (a - b).
static inline sBTV4_86F0 btSub_86F0(const sBTV4_86F0& a, const sBTV4_86F0& b)
{
    sBTV4_86F0 r;
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
static inline float btLength_86F0(const sBTV4_86F0& v)
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

// Same test as func_002E87E8's boardTrailCanDraw.
static inline int boardTrailCanDraw_86F0(char* r)
{
    int ok = 0;
    if (*(int*)(r + 0xAC4) != 0 && *(int*)(r + 0xAD0) == 0) ok = *(int*)(r + 0xAFC) != 0;
    return ok;
}

// Decides whether the trail starts a new segment this frame: forced (state 1), the rider moved far enough
// from the last segment, or the direction turned enough (d = dot of the new and last direction).
extern "C" int func_002E86F0(sBTrail_86F0* self, float d)
{
    if (self->delay > 0) {
        self->delay--;
        return 0;
    }
    sBTV4_86F0 dist = btSub_86F0(*(sBTV4_86F0*)(self->rider + 0x460), self->lastPos);
    float maxLen = 110.0f;
    float len = btLength_86F0(dist);
    if (boardTrailCanDraw_86F0(self->rider)) {
        maxLen = 30.0f;
    }
    if (self->state == 1 || maxLen <= len || d < 0.999f) {
        if (self->state == 1) {
            self->delay = 2;
        }
        self->lastPos = *(sBTV4_86F0*)(self->rider + 0x460);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002E87E8);
#ifdef SKIP_ASM
int func_0011FE98(void* self);
int func_00312AA0(void* self, int a1);
extern "C" char* func_00311B20(void* self, int a1);
extern "C" bool func_001446A0(void* self, int a1);
extern float D_004A4590;
extern float D_004A4594;
extern float D_004A4598;
extern float D_004A459C;

static inline int boardTrailCanDraw(char* r)
{
    int ok = 0;
    if (*(int*)(r + 0xAC4) != 0 && *(int*)(r + 0xAD0) == 0) ok = *(int*)(r + 0xAFC) != 0;
    return ok;
}
// Picks the trail fade rate for the rider's current state; returns 0 when no trail should be drawn.
extern "C" int func_002E87E8(char** self)
{
    if (func_0011FE98(self[0]) == 2) {
        if (*(int*)(*(char**)(self[0] + 0x77C) + 0x30) != 0) {
            return 0;
        }
    } else if (func_0011FE98(self[0]) != 0) {
        if (!boardTrailCanDraw(self[0])) return 0;
        if (*(int*)(self[0] + 0xB00) == 0) return 0;
    }
    if (func_00312AA0(*(void**)(self[0] + 0x784), 2) == 0x16) {
        if (func_001446A0(func_00311B20(*(void**)(self[0] + 0x784), 2) + 0xB0, 0)) {
            if (!func_001446A0(func_00311B20(*(void**)(self[0] + 0x784), 2) + 0xB0, 1)) {
                return 0;
            }
        }
    }
    switch (*(int*)(self[0] + 0x438)) {
    case 1:
        *(float*)((char*)self + 0x9C) = D_004A4594;
        return 1;
    case 0:
    case 5:
    case 6:
    case 12:
        *(float*)((char*)self + 0x9C) = D_004A4590;
        return 1;
    case 2:
    case 13:
        *(float*)((char*)self + 0x9C) = D_004A4598;
        return 1;
    case 3:
        *(float*)((char*)self + 0x9C) = D_004A459C;
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002E8938);
#ifdef SKIP_ASM
// Segments in the trail ring buffer (the prototype asserts BufHead < kTrailNumSeg).
enum { kTrailNumSeg = 54 };

struct sBTV4_8938 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBTMtx_8938 {
    sBTV4_8938 row[4];
};

// One trail vertex: texture coordinates, integer colour (0..255) and position.
struct sBTVtx_8938 {
    float u, v, q;
    int f0C;
    int r, g, b, a;
    sBTV4_8938 pos;
};

// The trail part of cBoardTrailFX (the cRider virtual base follows at +0xF0).
struct sBTrail_8938 {
    char* rider;                // 0x00 virtual base pointer (the cRider part)
    float w1;                   // 0x04
    float w2;                   // 0x08
    int flip;                   // 0x0C
    sBTVtx_8938* strip[6];      // 0x10
    int f28;                    // 0x28
    short ids[48];              // 0x2C
    int head;                   // 0x8C
    int count;                  // 0x90
    int state;                  // 0x94
    int f98;                    // 0x98
    float fade;                 // 0x9C
    float lift;                 // 0xA0
    int fA4;                    // 0xA4
    int padA8[2];               // 0xA8
    sBTV4_8938 colB0;           // 0xB0
    sBTV4_8938 lastDir;         // 0xC0
    sBTV4_8938 side;            // 0xD0
};

// Rider colour (a, r, g, b) of the render-state table entry (0xF0 bytes each).
struct sBTCol_8938 {
    float a, r, g, b;
};
struct sBTRSRow_8938 {
    sBTCol_8938 col;
    char pad[0xF0 - 0x10];
};

struct sBTVEnt_8938 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern sBTRSRow_8938 D_004FA398[];
extern float D_004A4580;
extern float D_004A4584;
extern float D_004A4588;
extern float D_004A458C;
extern float D_004A45AC;
extern float D_004A3B28;
extern float D_004A3B2C;
extern int D_004A3AFC;
extern "C" float func_0031C228(float);
// Decides whether the trail starts a new segment this frame.
extern "C" int func_002E86F0_8938(sBTrail_8938* self, float d) __asm__("func_002E86F0");

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sBTV4_8938 btScale(const sBTV4_8938& v, float s)
{
    sBTV4_8938 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sBTV4_8938 btAdd(const sBTV4_8938& a, const sBTV4_8938& b)
{
    sBTV4_8938 r;
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
static inline sBTV4_8938 btSub(const sBTV4_8938& a, const sBTV4_8938& b)
{
    sBTV4_8938 r;
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

// PORT: PS2-only VU0 inline asm (a += b). Assembled in noreorder mode: retail leaves the final sqc2 out of a
// following branch delay slot.
static inline void btAddEq(sBTV4_8938& a, const sBTV4_8938& b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float btLength(const sBTV4_8938& v)
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float btDot(const sBTV4_8938& a, const sBTV4_8938& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector divided by scalar).
static inline sBTV4_8938 btDiv(const sBTV4_8938& v, float s)
{
    sBTV4_8938 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize).
static inline sBTV4_8938 btNormalize(const sBTV4_8938& v)
{
    sBTV4_8938 r;
    __asm__(
        "lqc2       $vf3, %1\n"
        "vaddw.x    $vf6, $vf0, $vf0w\n"
        "vmul.xyzw  $vf4, $vf3, $vf3\n"
        "vadday.x   ACC, $vf4, $vf4y\n"
        "vmaddaz.x  ACC, $vf6, $vf4z\n"
        "vmaddw.x   $vf4, $vf6, $vf4w\n"
        "vrsqrt     Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2       $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sBTV4_8938 btCross(const sBTV4_8938& a, const sBTV4_8938& b)
{
    sBTV4_8938 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only inline asm (float absolute value).
static inline float btAbs(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ minimum operator (<?).
static inline float btClamp(float v, float lo, float hi)
{
    float r;
    if (v >= lo) {
        r = v <? hi;
    } else {
        r = lo;
    }
    return r;
}

static inline float btAtan2(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f)
            a += 3.1415927410125732f;
        else
            a -= 3.1415927410125732f;
    }
    return a;
}

// PORT: the seed is reinterpreted as a float in [1,2) through memory (type pun).
static inline float btRand()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

// A random value in [0, s).
static inline float btRandScale(const float& s)
{
    return s * btRand();
}

// Bone matrix of the rider's model; off is the cRider field holding the bone index.
static inline sBTMtx_8938* btBone(char* r, int off)
{
    return &((sBTMtx_8938*)*(char**)(*(char**)(r + 0x780) + 0x34))[*(int*)(r + off)];
}

static inline sBTV4_8938 btBoneRow(char* r, int off, int row)
{
    return btBone(r, off)->row[row];
}

static inline sBTV4_8938 btBonePos(char* r, int off)
{
    return btBone(r, off)->row[3];
}

static inline int btCanDraw(char* r)
{
    int ok = 0;
    if (*(int*)(r + 0xAC4) != 0 && *(int*)(r + 0xAD0) == 0) ok = *(int*)(r + 0xAFC) != 0;
    return ok;
}

static inline void btGrow(sBTrail_8938* self)
{
    if (self->count < kTrailNumSeg) self->count++;
}

// Updates the board trail: adds a segment at the board's current edges each frame.
extern "C" void func_002E8938(sBTrail_8938* self)
{
    int prev = (self->head + kTrailNumSeg - 1) % kTrailNumSeg;
    if (func_002E87E8((char**)self) == 0) {
        if (self->state == 0) return;
        if (self->state == 1) {
            self->head = (self->head + kTrailNumSeg - 3) % kTrailNumSeg;
            // Unused on this path; retail keeps the divisor load of its (removed) division check.
            prev = (self->head + kTrailNumSeg - 1) % kTrailNumSeg;
            int c = self->count - 3;
            if (c < 0) c = 0;
            self->count = c;
        } else {
            self->strip[2][prev].pos = self->strip[3][prev].pos = self->strip[0][prev].pos;
            self->strip[5][prev].pos = self->strip[4][prev].pos = self->strip[1][prev].pos;
            for (int i = 0; i < 6; i++) {
                self->strip[i][self->head].pos = self->strip[1][prev].pos;
                self->strip[i][self->head].pos.w = 1.0f;
                self->strip[i][self->head].a = self->strip[1][prev].a = 0;
                self->strip[i][self->head].r = self->strip[1][prev].r;
                self->strip[i][self->head].g = self->strip[1][prev].g;
                self->strip[i][self->head].b = self->strip[1][prev].b;
            }
        }
        self->state = 0;
        return;
    }
    if (self->state == 0) {
        self->head = (self->head + 3) % kTrailNumSeg;
        prev = (self->head + kTrailNumSeg - 1) % kTrailNumSeg;
    }
    self->lift = D_004A4588 - self->fade * D_004A458C;
    sBTV4_8938 pts[4];
    const sBTV4_8938& pos = btBoneRow(self->rider, 0x8A4, 3);
    const sBTV4_8938& side = btBoneRow(self->rider, 0x8A4, 2);
    const sBTV4_8938& fwd = btBoneRow(self->rider, 0x8A4, 0);
    sBTV4_8938 a = btScale(fwd, 87.5f);
    sBTV4_8938 b = btScale(side, 17.5f);
    if (func_0011FE98(self->rider) == 0 || (btCanDraw(self->rider) && *(int*)(self->rider + 0xB00) != 0)) {
        sBTV4_8938 left = btSub(pos, a);
        float s = 0.0f;
        sBTV4_8938 right = btAdd(pos, a);
        if (*(int*)(self->rider + 0x330) != 0) {
            int k = func_00312AA0(*(void**)(self->rider + 0x784), 2);
            if (k >= 0x17 && k <= 0x1E) {
                s = -1.0f;
                if (*(int*)(self->rider + 0x320) != 0) s = 1.0f;
            } else {
                s = 1.0f;
                if (*(int*)(self->rider + 0x320) != 0) s = -1.0f;
            }
        }
        if (0.0f < s) {
            btAddEq(left, btScale(fwd, s * 175.0f <? 140.0f));
        } else if (s < 0.0f) {
            btAddEq(right, btScale(fwd, s * 175.0f >? -140.0f));
        }
        pts[0] = btAdd(right, b);
        pts[2] = btAdd(left, b);
        pts[1] = btSub(right, b);
        pts[3] = btSub(left, b);
    } else {
        char* r = self->rider;
        pts[0] = btBonePos(r, 0x8B0);
        pts[1] = btBonePos(r, 0x8B8);
        if (*(int*)(r + 0x150) != 0) {
            pts[2] = btBonePos(r, 0x918);
            pts[3] = btBonePos(r, 0x8E8);
        } else {
            sBTV4_8938 left = btSub(pos, a);
            pts[2] = btAdd(left, b);
            pts[3] = btSub(left, b);
        }
    }
    float speed = btLength(*(sBTV4_8938*)(self->rider + 0x1E0));
    sBTV4_8938 dir;
    if (speed < 0.01f) {
        dir = self->lastDir;
    } else {
        dir = btDiv(*(sBTV4_8938*)(self->rider + 0x1E0), speed);
    }
    dir = btNormalize(btSub(dir, btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(dir, *(sBTV4_8938*)(self->rider + 0x370)))));
    sBTV4_8938 across = btCross(dir, *(sBTV4_8938*)(self->rider + 0x370));
    if (btDot(across, self->side) < 0.0f) {
        across = btScale(across, -1.0f);
    }
    sBTV4_8938 d1 = btSub(pts[1], *(sBTV4_8938*)(self->rider + 0x460));
    sBTV4_8938 d0 = btSub(pts[0], *(sBTV4_8938*)(self->rider + 0x460));
    sBTV4_8938 d3 = btSub(pts[3], *(sBTV4_8938*)(self->rider + 0x460));
    sBTV4_8938 d2 = btSub(pts[2], *(sBTV4_8938*)(self->rider + 0x460));
    float s1 = btDot(d1, across);
    float s0 = btDot(d0, across);
    float s3 = btDot(d3, across);
    float s2 = btDot(d2, across);
    sBTV4_8938 top;
    sBTV4_8938 bot;
    if (s0 < s1 && s3 < s1 && s2 < s1) {
        top = btSub(pts[1], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d1) - D_004A3B28));
    } else if (s1 < s0 && s3 < s0 && s2 < s0) {
        top = btSub(pts[0], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d0) - D_004A3B28));
    } else if (s1 < s3 && s0 < s3 && s2 < s3) {
        top = btSub(pts[3], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d3) - D_004A3B28));
    } else {
        top = btSub(pts[2], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d2) - D_004A3B28));
    }
    if (s1 < s0 && s1 < s3 && s1 < s2) {
        bot = btSub(pts[1], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d1) - D_004A3B28));
    } else if (s0 < s1 && s0 < s3 && s0 < s2) {
        bot = btSub(pts[0], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d0) - D_004A3B28));
    } else if (s3 < s1 && s3 < s0 && s3 < s2) {
        bot = btSub(pts[3], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d3) - D_004A3B28));
    } else {
        bot = btSub(pts[2], btScale(*(sBTV4_8938*)(self->rider + 0x370), btDot(*(sBTV4_8938*)(self->rider + 0x370), d2) - D_004A3B28));
    }
    sBTV4_8938 et = btSub(top, *(sBTV4_8938*)(self->rider + 0x460));
    sBTV4_8938 eb = btSub(bot, *(sBTV4_8938*)(self->rider + 0x460));
    float ft = btDot(et, dir);
    float fb = btDot(eb, dir);
    float st = btDot(et, across);
    float sb = btDot(eb, across);
    if (func_0011FE98(self->rider) == 2) {
        top = btAdd(btAdd(*(sBTV4_8938*)(self->rider + 0x460), btScale(across, st * 0.75f)), btScale(*(sBTV4_8938*)(self->rider + 0x370), D_004A3B28));
        bot = btAdd(btAdd(*(sBTV4_8938*)(self->rider + 0x460), btScale(across, sb * 0.75f)), btScale(*(sBTV4_8938*)(self->rider + 0x370), D_004A3B28));
    }
    self->strip[2][self->head].pos = top;
    self->strip[0][self->head].pos = top;
    self->strip[3][self->head].pos = top;
    self->strip[4][self->head].pos = bot;
    self->strip[1][self->head].pos = bot;
    self->strip[5][self->head].pos = bot;
    float ang = btAtan2(btAbs(ft), btAbs(st));
    float k;
    if (0.7853982448577881f < ang) {
        k = btClamp(2.0f - ang * 1.2732393741607666f, 0.0f, 1.0f);
    } else {
        k = btClamp(ang * 1.2732393741607666f, 0.0f, 1.0f);
    }
    if (speed * 0.0036000001709908247f <= 1.0f) {
        k *= speed * 0.0036000001709908247f;
    }
    sBTV4_8938 ground = btAdd(*(sBTV4_8938*)(self->rider + 0x460), btScale(*(sBTV4_8938*)(self->rider + 0x370), D_004A3B28));
    sBTV4_8938 mid;
    if (ft < fb) {
        mid = btAdd(ground, btScale(dir, k * ft));
    } else {
        mid = btAdd(ground, btScale(dir, k * fb));
    }
    sBTV4_8938 p0 = btAdd(mid, btScale(across, st));
    sBTV4_8938 p1 = btAdd(mid, btScale(across, sb));
    sBTV4_8938 n = btNormalize(btSub(p1, p0));
    sBTV4_8938 u1 = btScale(n, D_004A4580);
    sBTV4_8938 u3 = btScale(btScale(n, D_004A4584), btAbs(*(float*)(self->rider + 0x454) <? 0.0f) + 10.0f);
    sBTV4_8938 w = btScale(*(sBTV4_8938*)(self->rider + 0x370), self->lift);
    sBTV4_8938 h = btScale(*(sBTV4_8938*)(self->rider + 0x370), *(float*)(self->rider + 0x454) <? 0.0f);
    self->strip[2][prev].pos = btAdd(btAdd(btSub(p0, u3), h), h);
    self->strip[0][prev].pos = btAdd(btSub(p0, btScale(u1, self->w1)), w);
    self->strip[3][prev].pos = btAdd(p0, h);
    self->strip[4][prev].pos = btAdd(p1, h);
    self->strip[1][prev].pos = btAdd(btAdd(p1, btScale(u1, self->w2)), w);
    self->strip[5][prev].pos = btAdd(btAdd(btAdd(p1, u3), h), h);
    char* o = self->rider + 0x6C0;
    sBTVEnt_8938* vt = *(sBTVEnt_8938**)o;
    sBTCol_8938 c = D_004FA398[vt[7].fn(o + vt[7].delta)].col;
    for (int i = 0; i < 6; i++) {
        self->strip[i][self->head].a = self->strip[i][prev].a = (int)btClamp(c.a * 255.0f, 0.0f, 255.0f);
        self->strip[i][self->head].r = self->strip[i][prev].r = (int)btClamp(c.r * 255.0f, 0.0f, 255.0f);
        self->strip[i][self->head].g = self->strip[i][prev].g = (int)btClamp(c.g * 255.0f, 0.0f, 255.0f);
        self->strip[i][self->head].b = self->strip[i][prev].b = (int)btClamp(c.b * 255.0f, 0.0f, 255.0f);
    }
    for (int i = 0; i < 6; i++) {
        self->strip[i][self->head].pos.w = 1.0f;
    }
    sBTV4_8938 e0 = btSub(self->strip[0][self->head].pos, self->strip[0][prev].pos);
    sBTV4_8938 e1 = btSub(self->strip[1][self->head].pos, self->strip[1][prev].pos);
    int back0 = btDot(e0, dir) < 0.0f;
    int back1 = btDot(e1, dir) < 0.0f;
    if (back0) {
        if (back1) {
            self->strip[0][self->head].pos = self->strip[2][self->head].pos = self->strip[3][self->head].pos =
                btAdd(self->strip[0][prev].pos, btScale(dir, D_004A3B2C));
            self->strip[1][self->head].pos = self->strip[5][self->head].pos = self->strip[4][self->head].pos =
                btAdd(self->strip[1][prev].pos, btScale(dir, D_004A3B2C));
        } else {
            self->strip[0][self->head].pos = self->strip[2][self->head].pos = self->strip[3][self->head].pos =
                self->strip[1][self->head].pos;
        }
    } else if (back1) {
        self->strip[1][self->head].pos = self->strip[5][self->head].pos = self->strip[4][self->head].pos =
            self->strip[0][self->head].pos;
    }
    if (self->state == 0) {
        int pp = (prev + kTrailNumSeg - 1) % kTrailNumSeg;
        for (int i = 0; i < 6; i++) {
            self->strip[i][pp].pos = self->strip[1][prev].pos;
            self->strip[i][pp].r = self->strip[1][prev].r;
            self->strip[i][pp].g = self->strip[1][prev].g;
            self->strip[i][pp].b = self->strip[1][prev].b;
            self->strip[i][pp].a = self->strip[i][prev].a = 0;
        }
        self->strip[2][prev].pos = self->strip[3][prev].pos = self->strip[0][prev].pos;
        self->strip[5][prev].pos = self->strip[4][prev].pos = self->strip[1][prev].pos;
        btGrow(self);
        btGrow(self);
        btGrow(self);
        self->state = 1;
    }
    if (func_002E86F0_8938(self, btDot(dir, self->lastDir))) {
        int h = self->head;
        self->side = across;
        self->w1 = btRandScale(D_004A45AC) + 1.0f;
        self->w2 = btRandScale(D_004A45AC) + 1.0f;
        self->head = (h + 1) % kTrailNumSeg;
        btGrow(self);
        for (int i = 0; i < 6; i++) {
            self->strip[i][self->head].pos = self->strip[i][h].pos;
            self->strip[i][self->head].a = self->strip[i][h].a;
            self->strip[i][self->head].r = self->strip[i][h].r;
            self->strip[i][self->head].g = self->strip[i][h].g;
            self->strip[i][self->head].b = self->strip[i][h].b;
        }
        self->state = 2;
    }
    self->lastDir = dir;
    self->flip = 1 - self->flip;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA480);
#ifdef SKIP_ASM
struct sMtxEntry_A480 {
    int v[5];
};
extern int D_004A4518;
extern int D_004A451C;
struct sRenderCtx_A480 {
    char pad[0xE84];
    sMtxEntry_A480* top;
};
extern sRenderCtx_A480* D_004A289C;

class func_002EA480_cObj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09();
};

static inline void push_A480(sRenderCtx_A480* ctx)
{
    ctx->top[1] = ctx->top[0];
    ctx->top++;
}

static inline void pop_A480(sRenderCtx_A480* ctx)
{
    ctx->top--;
}

extern "C" void func_002EA480(void* self)
{
    if (D_004A4518 != 0) {
        return;
    }
    if (D_004A451C != 0) {
        func_002EA480_cObj* o = (func_002EA480_cObj*)(*(char**)self + 0x6C0);
        if (o->v09() != 0) {
            return;
        }
    }
    if (*(int*)((char*)self + 0x90) < 2) {
        return;
    }
    push_A480(D_004A289C);
    pop_A480(D_004A289C);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA538);
#ifdef SKIP_ASM
extern int D_004A45C8;

struct sTrailStripA538 {
    char* pts;                  // 0x0
    int start;                  // 0x4
    int count;                  // 0x8
    int fC;                     // 0xC
    float scale;                // 0x10
};
struct sRctxVtA538 { short delta; short index; void (*fn)(void*, sTrailStripA538*, int); };

extern "C" void func_002EA538(char** trails, int n)
{
    sTrailStripA538 strips[16];
    int count = 0;
    push_A480(D_004A289C);
    if (n > 0) {
    do {
        char* t = *trails;
        int len = *(int*)(t + 0x90);
        if (len < 2) continue;
        int k = len - 0x39;
        int start = *(int*)(t + 0x8C) - k;
        int cnt = len - 2;
        int over = len - 0x32;
        if (over > 0) {
            cnt -= over;
            start += over;
        }
        if (cnt < 2) continue;
        int st = start % 0x36;
        float sc = 1.0f / (float)D_004A45C8;
        if (count < 16) {
            strips[count].pts = t + 0x10;
            strips[count].start = st;
            strips[count].count = cnt;
            strips[count].fC = 0;
            strips[count].scale = sc;
            count++;
        }
    } while (trails++, --n > 0);
    }
    {
        char* ctx = (char*)D_004A289C;
        sRctxVtA538* vt = *(sRctxVtA538**)(ctx + 0x10D8);
        vt[89].fn(ctx + vt[89].delta, strips, count);
    }
    pop_A480(D_004A289C);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA670);
#ifdef SKIP_ASM
extern void* D_00487F30[];
extern "C" void* func_00354648(void* self, void* param2);
extern "C" void func_002EAA28(void* self);

extern "C" void* func_002EA670(void* self, void* param2)
{
    func_00354648(self, param2);
    *(void***)((char*)self + 0xC) = D_00487F30;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    func_002EAA28(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA6B8);
#ifdef SKIP_ASM
extern "C" void func_002EAA28(void* self);

struct func_002EA6B8_sFade {
    char pad[0x10];
    int state;
    float t;
    float dur;
};

extern "C" void func_002EA6B8(func_002EA6B8_sFade* self, float dur)
{
    switch (self->state) {
    case 0:
        func_002EAA28(self);
        self->dur = dur;
        self->t = 0.0f;
        break;
    case 1:
        return;
    case 2: {
        float r = self->t / self->dur;
        self->dur = dur;
        self->t = (1.0f - r) * dur;
        break;
    }
    case 3: {
        float r = self->t / self->dur;
        self->dur = dur;
        self->t = r * dur;
        break;
    }
    }
    self->state = 3;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA780);
#ifdef SKIP_ASM
struct sTrailFade {
    char pad[0x10];
    int state;
    float value;
    float time;
};

extern "C" void func_002EA780(sTrailFade* self, float t)
{
    switch (self->state) {
    case 0:
        return;
    case 1:
        self->time = t;
        self->value = 0.0f;
        break;
    case 2:
        self->value = (self->value / self->time) * t;
        self->time = t;
        break;
    case 3:
        self->value = (1.0f - self->value / self->time) * t;
        self->time = t;
        break;
    }
    self->state = 2;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA820);
#ifdef SKIP_ASM
struct sBTVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

extern char* D_004A5B80;

extern "C" void func_002EA820(void* self)
{
    if (*(int*)((char*)self + 0x10) != 0) {
        *(int*)((char*)self + 0x10) = 0;
        char* obj = D_004A5B80;
        sBTVEntry* e = &(*(sBTVEntry**)(obj + 0x10D8))[41];
        e->fn(obj + e->delta, (char*)self + 0x20);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA860);
#ifdef SKIP_ASM
extern char* D_004A5B80;

extern "C" void func_002EA860(void* self)
{
    if (*(int*)((char*)self + 0x10) == 0) {
        func_002EAA28(self);
    }
    char* obj = D_004A5B80;
    *(int*)((char*)self + 0x10) = 1;
    sBTVEntry* e = &(*(sBTVEntry**)(obj + 0x10D8))[41];
    e->fn(obj + e->delta, (char*)self + 0x34);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA8B8);
#ifdef SKIP_ASM
extern "C" void func_002EA8B8(void* self, int up)
{
    int s = *(int*)((char*)self + 0x10);
    if (s == 2 || s == 3) {
        *(int*)((char*)self + 0x1C) = 0;
        return;
    }
    if (up) {
        *(int*)((char*)self + 0x1C) += 1;
        return;
    }
    if (*(int*)((char*)self + 0x1C) > 0) {
        *(int*)((char*)self + 0x1C) -= 1;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EA900);
#ifdef SKIP_ASM
extern "C" void func_002EA820(void* self);
extern "C" void func_002EA860(void* self);

struct sFadeCol_A900 {
    int id;
    float c[4];
};

struct sVE_A900 { short delta; short index; void (*fn)(void*, sFadeCol_A900*); };

struct sFade_A900 {
    char pad0[0x10];
    int mode;           // 0x10
    float t;            // 0x14
    float dur;          // 0x18
    int done;           // 0x1C
    int id;             // 0x20
    float from[4];      // 0x24
    int f34;
    float to[4];        // 0x38
};

extern char* D_004A5B64_A900 __asm__("D_004A5B64");
extern char* D_004A5B80_A900 __asm__("D_004A5B80");

extern "C" void func_002EA900(sFade_A900* self)
{
    if (self->done != 0)
        return;
    int mode = self->mode;
    if (mode != 2 && mode != 3)
        return;
    self->t += 1.0f / (float)*(int*)(D_004A5B64_A900 + 0x10);
    if (self->dur < self->t) {
        if (mode == 2)
            func_002EA820(self);
        else
            func_002EA860(self);
        return;
    }
    float k = self->t / self->dur;
    if (mode == 2)
        k = 1.0f - k;
    sFadeCol_A900 col;
    col.id = self->id;
    col.c[2] = self->from[2] + (self->to[2] - self->from[2]) * k;
    col.c[3] = self->from[3] + (self->to[3] - self->from[3]) * k;
    col.c[0] = self->from[0] + (self->to[0] - self->from[0]) * k;
    col.c[1] = self->from[1] + (self->to[1] - self->from[1]) * k;
    char* d = D_004A5B80_A900;
    sVE_A900* vt = *(sVE_A900**)(d + 0x10D8);
    vt[41].fn(d + vt[41].delta, &col);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EAA28);
#ifdef SKIP_ASM
struct sBTState {
    int mode;
    float a;
    float b;
    float c;
    float d;
};

struct sBTFx {
    char pad[0x20];
    sBTState saved;
    sBTState cur;
};

struct sBTVEntryGet {
    short delta;
    short index;
    sBTState* (*fn)(void*);
};

extern char* D_004A5B80;

extern "C" void func_002EAA28(void* self)
{
    sBTFx* s = (sBTFx*)self;
    char* obj = D_004A5B80;
    sBTVEntryGet* e = &(*(sBTVEntryGet**)(obj + 0x10D8))[42];
    s->saved = *e->fn(obj + e->delta);
    float c = 0.75f;
    float d = 0.6299999952316284f;
    if (s->saved.mode == 2) {
        s->cur.d = d;
        s->cur.mode = 2;
        s->cur.b = 1.0f;
        s->cur.c = c;
        s->cur.a = 0.0f;
    } else {
        s->cur.mode = 1;
        s->cur.a = 0.125f;
        s->cur.b = c;
        s->cur.c = c;
        s->cur.d = d;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EAAE0);
#ifdef SKIP_ASM
void func_002EADC0(void* self);
struct cBtfIn_2EAAE0 {
    char data[0x10];
    cBtfIn_2EAAE0() {}
};
class cBtf_2EAAE0 : virtual public cRiderVb_btf {
public:
    char pad04[0xC];
    cBtfIn_2EAAE0 a[3][4];
    char pad[0x34];
    cBtf_2EAAE0();
    virtual ~cBtf_2EAAE0();
};

cBtf_2EAAE0::cBtf_2EAAE0()
{
    func_002EADC0(this);
}
// PORT: cRiderVb_btf stands in for cRider; its constructor is the retail cRider_cRider.
__asm__("__12cRiderVb_btf = cRider_cRider\n");
// PORT: the compiler names this ctor __11cBtf_2EAAE0i; expose it under the address-derived name.
__asm__(".globl func_002EAAE0\n.type func_002EAAE0,@function\nfunc_002EAAE0 = __11cBtf_2EAAE0i\n.size func_002EAAE0,0x180\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EAC60);
#ifdef SKIP_ASM
class cVbDtor002EAC60 : virtual public cRiderVb_btf {
public:
    char body[0x10C];
    virtual ~cVbDtor002EAC60();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002EAC60::~cVbDtor002EAC60()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor002EAC60; expose it under the address-derived name.
__asm__(".globl func_002EAC60\n.type func_002EAC60,@function\nfunc_002EAC60 = _$_15cVbDtor002EAC60\n.size func_002EAC60,0x15C\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EADC0__FPv);
#ifdef SKIP_ASM
void func_002EADC0(void* self)
{
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EADD0);
#ifdef SKIP_ASM
int func_0011FE98(void* self);
void func_00392DE8(void* self, int val);
extern "C" void func_00392D90(void* self, void* q, void* v);
extern int D_004A4720;

struct sV4_2EADD0
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sV3_2EADD0
{
    float x, y, z;
};

struct sSlot_2EADD0
{
    sV4_2EADD0 v[4];
};

struct sNode_2EADD0
{
    sV4_2EADD0 fwd;     // 0x00
    sV4_2EADD0 pad10;   // 0x10
    sV4_2EADD0 side;    // 0x20
    sV4_2EADD0 pos;     // 0x30
};

struct sTrail_2EADD0
{
    char* rider;        // 0x00
    int pad4[2];
    int count;          // 0x0C
    int cur;            // 0x10
    int pad14[3];
    sSlot_2EADD0 slots[3];  // 0x20
    sV4_2EADD0 e0;      // 0xE0
    sV4_2EADD0 f0;      // 0xF0
};

// PORT: PS2-only VU0 inline asm (a + b).
static inline sV4_2EADD0 Add_2EADD0(const sV4_2EADD0& a, const sV4_2EADD0& b)
{
    sV4_2EADD0 r;
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
static inline sV4_2EADD0 Sub_2EADD0(const sV4_2EADD0& a, const sV4_2EADD0& b)
{
    sV4_2EADD0 r;
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_2EADD0 Scale_2EADD0(const sV4_2EADD0& v, float s)
{
    sV4_2EADD0 r;
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

extern "C" void func_002EADD0(sTrail_2EADD0* self)
{
    float speed = *(float*)(self->rider + 0x2EC);
    if (D_004A4720 != 0)
        speed = 10.0f;
    if (0.0f < speed)
    {
        func_00392DE8(*(char**)(self->rider + 0x77C) + 0xD30, 1);
        char* r0 = self->rider;
        sV3_2EADD0 sz;
        sz.x = 2.0f;
        sz.y = 2.0f;
        sz.z = 2.0f;
        char* fs = *(char**)(r0 + 0x77C) + 0xD30;
        sV4_2EADD0 col;
        col.x = 0.0f;
        col.y = 0.0f;
        col.z = 1.0f;
        col.w = 0.0f;
        func_00392D90(fs, &col, &sz);
    }
    if (0.0f < speed && func_0011FE98(self->rider) == 1)
    {
        self->cur = (self->cur + 2) % 3;
        int n = self->count + 1;
        self->count = n < 4 ? n : 3;
        char* r = self->rider;
        sV4_2EADD0 pos = ((sNode_2EADD0*)(*(char**)(*(char**)(r + 0x780) + 0x30) + (*(int*)(r + 0x8A4) << 6)))->pos;
        sV4_2EADD0 fwd = ((sNode_2EADD0*)(*(char**)(*(char**)(r + 0x780) + 0x30) + (*(int*)(r + 0x8A4) << 6)))->fwd;
        sV4_2EADD0 side = ((sNode_2EADD0*)(*(char**)(*(char**)(r + 0x780) + 0x30) + (*(int*)(r + 0x8A4) << 6)))->side;
        self->e0 = Sub_2EADD0(pos, Scale_2EADD0(side, 12.0f));
        self->f0 = Add_2EADD0(pos, Scale_2EADD0(side, 12.0f));
        self->slots[self->cur].v[0] = Sub_2EADD0(Add_2EADD0(pos, Scale_2EADD0(fwd, 70.0f)), Scale_2EADD0(side, 18.0f));
        self->slots[self->cur].v[1] = Add_2EADD0(Add_2EADD0(pos, Scale_2EADD0(fwd, 70.0f)), Scale_2EADD0(side, 18.0f));
        self->slots[self->cur].v[2] = Add_2EADD0(Sub_2EADD0(pos, Scale_2EADD0(fwd, 70.0f)), Scale_2EADD0(side, 18.0f));
        self->slots[self->cur].v[3] = Sub_2EADD0(Sub_2EADD0(pos, Scale_2EADD0(fwd, 70.0f)), Scale_2EADD0(side, 18.0f));
    }
    else
    {
        self->count = 0;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EB198);
#ifdef SKIP_ASM
struct sRS_EB198 {
    unsigned int f0_0 : 2;
    unsigned int f0_2 : 2;
    unsigned int f0_4 : 28;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 5;
    unsigned int f4_12 : 8;
    unsigned int f4_20 : 2;
    unsigned int f4_22 : 1;
    unsigned int f4_23 : 2;
    unsigned int f4_25 : 7;
    unsigned int f8_0 : 5;
    unsigned int f8_5 : 5;
    unsigned int f8_10 : 19;
    unsigned int f8_29 : 3;
    short fC;
    short fE;
    short f10;
    short f12;
};
extern sRS_EB198 D_00501420;

struct sV4_EB198 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVtx_EB198 {
    float s, t, q, pad;
    int c[4];
    sV4_EB198 pos;
    sVtx_EB198() {}
};

struct sSlot_EB198 {
    sV4_EB198 v[4];
};

struct sTrail_EB198 {
    char* rider;            // 0x00
    int pad4[2];
    int count;              // 0x0C
    int cur;                // 0x10
    int pad14[3];
    sSlot_EB198 slots[3];   // 0x20
    sV4_EB198 e0;           // 0xE0
    sV4_EB198 f0;           // 0xF0
};

struct sVE71_EB198 {
    short delta;
    short index;
    void (*fn)(void*, int, sVtx_EB198*, int);
};

#define TOP_EB198 ((sRS_EB198*)D_004A289C->top)

static inline int GetF1048_EB198(sRenderCtx_A480* ctx) { return *(int*)((char*)ctx + 0x1048); }

static inline void SetF10_EB198(short& f, int v) { f = v; }

static inline void SetF4_22_EB198(sRS_EB198* rs, int v) { rs->f4_22 = v; }

static inline void AddVert_EB198(sVtx_EB198* v, float s, float t, const sV4_EB198& col, const sV4_EB198& pos)
{
    v->c[0] = (int)(col.y * 255.0f);
    v->c[1] = (int)(col.z * 255.0f);
    v->c[2] = (int)(col.w * 255.0f);
    v->c[3] = (int)(col.x * 128.0f);
    v->q = 1.0f;
    v->pos = pos;
    v->s = s;
    v->t = t;
}

extern "C" void func_002EB198(sTrail_EB198* self)
{
    if (self->count < 2) {
        return;
    }
    push_A480(D_004A289C);
    *TOP_EB198 = D_00501420;
    SetF10_EB198(TOP_EB198->f10, GetF1048_EB198(D_004A289C));
    TOP_EB198->f0_2 = 3;
    TOP_EB198->f4_23 = 0;
    TOP_EB198->f4_20 = 0;
    TOP_EB198->f4_12 = 0x14;
    TOP_EB198->f4_0 = 2;
    TOP_EB198->f8_10 = 0;
    TOP_EB198->f8_5 = 7;
    TOP_EB198->f4_2 = 7;
    SetF4_22_EB198(TOP_EB198, 1);
    sVtx_EB198 verts[4][7];
    int counts[4];
    sV4_EB198 col;
    for (int i = 0; i < 4; i++) {
        counts[i] = 0;
    }
    col.x = 1.0f;
    col.y = 1.0f;
    col.z = 1.0f;
    col.w = 1.0f;
    AddVert_EB198(&verts[1][counts[1]++], 0.5f, 0.0f, col, self->f0);
    AddVert_EB198(&verts[3][counts[3]++], 0.5f, 0.0f, col, self->e0);
    for (int i = 0; i < self->count; i++) {
        int sl = (self->cur + i) % 3;
        col.x = 0.5f;
        col.y = 0.5f;
        col.z = 0.5f;
        col.w = 0.5f;
        float t = 1.0f - (float)i / (float)(self->count - 1);
        AddVert_EB198(&verts[0][counts[0]++], 0.0f, t, col, self->slots[sl].v[0]);
        AddVert_EB198(&verts[0][counts[0]++], 1.0f, t, col, self->slots[sl].v[1]);
        AddVert_EB198(&verts[1][counts[1]++], 1.0f, t, col, self->slots[sl].v[1]);
        AddVert_EB198(&verts[1][counts[1]++], 0.0f, t, col, self->slots[sl].v[2]);
        AddVert_EB198(&verts[2][counts[2]++], 0.0f, t, col, self->slots[sl].v[2]);
        AddVert_EB198(&verts[2][counts[2]++], 1.0f, t, col, self->slots[sl].v[3]);
        AddVert_EB198(&verts[3][counts[3]++], 1.0f, t, col, self->slots[sl].v[3]);
        AddVert_EB198(&verts[3][counts[3]++], 0.0f, t, col, self->slots[sl].v[0]);
    }
    for (int k = 0; k < 4; k++) {
        char* ctx = (char*)D_004A289C;
        sVE71_EB198* vt = *(sVE71_EB198**)(ctx + 0x10D8);
        vt[71].fn(ctx + vt[71].delta, counts[k], verts[k], 0);
    }
    pop_A480(D_004A289C);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EB8F0);
#ifdef SKIP_ASM
struct sBTVEntryR {
    short delta;
    short index;
    float* (*fn)(void*);
};

extern char* D_004A5B80;
extern float D_004A3B3C;
extern float D_004A3B40;
extern float D_004A3B44;

extern "C" void func_002EB8F0(void)
{
    char* obj = D_004A5B80;
    sBTVEntryR* e = &(*(sBTVEntryR**)(obj + 0x10D8))[42];
    float* r = e->fn(obj + e->delta);
    float a = r[1];
    float w = r[2];
    D_004A3B3C = a;
    float b = w + a;
    D_004A3B40 = b;
    D_004A3B44 = b - a;
}
#endif

INCLUDE_ASM("visualfx/boardtrailfx", func_002EB938);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardtrailfx", func_002EBB10);
#ifdef SKIP_ASM
struct sBTRect4 {
    float x, y, z, w;
};

extern float D_004A3B30;
extern float D_004A3B38;
extern float D_004A3B3C;
extern float D_004A3B44;

extern "C" void func_002EB938(sBTRect4* pos, sBTRect4* rect, sBTRect4* color, float f);

extern "C" void func_002EBB10(void* self, float s)
{
    sBTRect4 color = *(sBTRect4*)((char*)self + 4);
    color.x = ((sBTRect4*)((char*)self + 4))->x * s;
    sBTRect4 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 640.0f;
    pos.w = 480.0f;
    sBTRect4 rect;
    rect.x = D_004A3B30;
    rect.y = D_004A3B3C;
    rect.z = D_004A3B38;
    rect.w = D_004A3B44;
    func_002EB938(&pos, &rect, &color, pos.x);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EBBA8);
#ifdef SKIP_ASM
void* func_002E4D70(void* self);
extern void* D_004880A0[];

struct func_002EBBA8_sVec4 {
    float x, y, z, w;
};

struct func_002EBBA8_sObj {
    void** vtable;               // 0x0
    func_002EBBA8_sVec4 v;       // 0x4
    int a;                       // 0x14
    int b;                       // 0x18
};

extern "C" func_002EBBA8_sObj* func_002EBBA8(func_002EBBA8_sObj* self, const func_002EBBA8_sVec4& v, int a, int b)
{
    func_002EBBA8_sVec4 t = v;
    func_002E4D70(self);
    self->vtable = D_004880A0;
    self->v = t;
    self->a = a;
    self->b = b;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardtrailfx", func_002EBC40);
#ifdef SKIP_ASM
extern float D_004A3B30;
extern float D_004A3B34;
extern float D_004A3B38;
extern float D_004A3B3C;
extern float D_004A3B40;
extern float D_004A3B44;
extern "C" void func_002EB938(sBTRect4* pos, sBTRect4* rect, sBTRect4* color, float f);

extern "C" void func_002EBC40(char* self, float t)
{
    float k = 1.0f - t;
    float dx = (float)*(int*)(self + 0x14) * k * 640.0f;
    float dy = (float)*(int*)(self + 0x18) * k * -480.0f;
    float w = 640.0f;
    float u0, u1;
    if (dx < 0.0f) {
        w = dx + w;
        u0 = D_004A3B30 + D_004A3B38 * 0.0015625000232830644f * dx;
        u1 = D_004A3B34;
        dx = 0.0f;
    } else {
        w = w - dx;
        u0 = D_004A3B30;
        u1 = u0 + D_004A3B38 * 0.0015625000232830644f * w;
    }
    float h;
    float v0, v1;
    if (dy < 0.0f) {
        h = dy + 480.0f;
        v0 = D_004A3B3C + D_004A3B44 * 0.0020833334419876337f * dy;
        v1 = D_004A3B40;
        dy = 0.0f;
    } else {
        h = 480.0f - dy;
        v0 = D_004A3B3C;
        v1 = v0 + D_004A3B44 * 0.0020833334419876337f * h;
    }
    float uw = u1 - u0;
    float vh = v1 - v0;
    sBTRect4 pos;
    pos.x = dx;
    pos.y = dy;
    pos.z = w;
    pos.w = h;
    sBTRect4 rect;
    rect.x = u0;
    rect.y = v0;
    rect.z = uw;
    rect.w = vh;
    func_002EB938(&pos, &rect, (sBTRect4*)(self + 4), 0.0f);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EBD88);
#ifdef SKIP_ASM
struct sTrailVec_002EBD88 { float x, y, z, w; };

extern void* D_00488080[];

extern "C" void* func_002EBD88(void* self, sTrailVec_002EBD88 v, float a, float b)
{
    func_002E4D70(self);
    *(void***)self = D_00488080;
    *(sTrailVec_002EBD88*)((char*)self + 4) = v;
    *(float*)((char*)self + 0x14) = a;
    *(float*)((char*)self + 0x18) = b;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EBE20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
unsigned int BXrand();
// base ctor returns this; the unit declares it void
void* func_002E4D70_r(void* self) __asm__("func_002E4D70__FPv");
extern void* D_00488080[];

struct sBtRectBE20 { float x, y, w, h; };

extern "C" void* func_002EBE20(void* self, sBtRectBE20 rect)
{
    func_002E4D70_r(self);
    *(void***)self = D_00488080;
    *(sBtRectBE20*)((char*)self + 0x4) = rect;
    unsigned int r1 = BXrand() % 1000;
    float* p = (float*)((char*)self + 0x14);
    *p = (float)r1 * 0.64000004529953f;
    unsigned int r2 = BXrand() % 1000;
    float* q = (float*)((char*)self + 0x18);
    *q = (float)r2 * 0.48000001907348633f;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EBF48);
#ifdef SKIP_ASM
struct sBTFVec4_BF48 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBTFDev_BF48 {
    char pad_0x0[0xE84];
    char* state;            // 0xE84
};

struct sBTFState_BF48 {
    char pad_0x0[0x10];
    short mode;             // 0x10
};

extern sBTFDev_BF48* D_004A5B80_d __asm__("D_004A5B80");
extern float D_004A3B30;
extern float D_004A3B38;
extern float D_004A3B3C;
extern float D_004A3B44;

extern "C" void func_002EBF48(float u, float v, float* out, float* col)
{
    if (((sBTFState_BF48*)D_004A5B80_d->state)->mode != -1) {
        ((int*)out)[4] = (int)(col[1] * 128.0f);
        ((int*)out)[5] = (int)(col[2] * 128.0f);
        ((int*)out)[6] = (int)(col[3] * 128.0f);
        ((int*)out)[7] = (int)(col[0] * 128.0f);
    } else {
        ((int*)out)[4] = (int)(col[1] * 255.0f);
        ((int*)out)[5] = (int)(col[2] * 255.0f);
        ((int*)out)[6] = (int)(col[3] * 255.0f);
        ((int*)out)[7] = (int)(col[0] * 128.0f);
    }
    {
        sBTFVec4_BF48 t;
        float x = D_004A3B30 + D_004A3B38 * 0.0015625f * u;
        float y = D_004A3B3C + D_004A3B44 * 0.0020833334f * v;
        out[2] = 1.0f;
        t.w = 1.0f;
        t.x = u;
        t.y = v;
        t.z = 0.0f;
        out[0] = x;
        *(sBTFVec4_BF48*)(out + 8) = t;
        out[1] = y;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002EC060);
#ifdef SKIP_ASM
extern float D_00504FB8[];

struct sBTVert_C060 {
    float f[12];
    sBTVert_C060() {}
} __attribute__((aligned(16)));

struct sBTVEntryDraw {
    short delta;
    short index;
    void (*fn)(void*, int, sBTVert_C060*, int);
};

static inline float clampBT(float v, float lo, float hi)
{
    float r;
    if (lo <= v)
        r = v <? hi;
    else
        r = lo;
    return r;
}

// Points of a half circle of radius r around x = cx, one every `step` radians: ys gets the sine part, xs the
// x position clamped to the screen. D_00504FB8 is a 512-entry sine table (index = angle * 256/pi, +0x80 = cosine).
static inline void BuildArc_C060(float* ys, float* xs, const float& cx, float r, float step)
{
    float ang = 0.0f;
    for (int i = 0; i < 40; i++, ang += step) {
        int idx = (int)(ang * 81.4873275756836f) & 0x1FF;
        ys[i] = r * D_00504FB8[idx];
        float x = cx + r * D_00504FB8[idx + 0x80];
        xs[i] = clampBT(x, 0.0f, 640.0f);
    }
}

extern "C" void func_002EC060(char* self, float t)
{
    float r = (1.0f - t) * 800.0f;
    float x1 = *(float*)(self + 0x14) + r;
    float x0 = *(float*)(self + 0x14) - r;
    sBTRect4 pos;
    sBTRect4 rect;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = x0;
    pos.w = 480.0f;
    rect.z = D_004A3B30 + D_004A3B38 * 0.0015625000232830644f * x0;
    rect.x = D_004A3B30;
    rect.y = D_004A3B3C;
    rect.w = D_004A3B44;
    func_002EB938(&pos, &rect, (sBTRect4*)(self + 4), 0.0f);
    float w = 640.0f - x1;
    pos.x = x1;
    pos.y = 0.0f;
    pos.z = w;
    pos.w = 480.0f;
    rect.x = D_004A3B30 + D_004A3B38 * 0.0015625000232830644f * x1;
    rect.y = D_004A3B3C;
    rect.z = D_004A3B30 + D_004A3B38 * w * 0.0015625000232830644f;
    rect.w = D_004A3B44;
    func_002EB938(&pos, &rect, (sBTRect4*)(self + 4), 0.0f);

    float ys[40];
    float xs[40];
    BuildArc_C060(ys, xs, *(float*)(self + 0x14), r, 0.08055365830659866f); // pi / 39

    sBTVert_C060 top[80];
    sBTVert_C060 bot[80];
    for (int i = 0; i < 40; i++) {
        sBTVert_C060* t0 = top + i * 2;
        func_002EBF48(xs[i], 0.0f, t0->f, (float*)(self + 4));
        sBTVert_C060* t1 = top + i * 2 + 1;
        float y0 = clampBT(*(float*)(self + 0x18) - ys[i], 0.0f, 480.0f);
        func_002EBF48(xs[i], y0, t1->f, (float*)(self + 4));
        float y1 = clampBT(*(float*)(self + 0x18) + ys[i], 0.0f, 480.0f);
        sBTVert_C060* b0 = bot + i * 2;
        func_002EBF48(xs[i], y1, b0->f, (float*)(self + 4));
        sBTVert_C060* b1 = bot + i * 2 + 1;
        func_002EBF48(xs[i], 480.0f, b1->f, (float*)(self + 4));
    }

    char* obj = D_004A5B80;
    sBTVEntryDraw* e = &(*(sBTVEntryDraw**)(obj + 0x10D8))[71];
    e->fn(obj + e->delta, 0x50, top, 0);
    obj = D_004A5B80;
    e = &(*(sBTVEntryDraw**)(obj + 0x10D8))[71];
    e->fn(obj + e->delta, 0x50, bot, 0);
}
#endif

