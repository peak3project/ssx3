#include "common.h"

//100%
INCLUDE_ASM("visualfx/boardwakefx", cBoardWakeFX_cBoardWakeFX);
#ifdef SKIP_ASM
// g++ 2.95 vtable entry (no thunks): {delta, index, fn}. Vtables are double-aligned.
struct sVtEntBW {
    short delta;
    short index;
    void* fn;
};

struct sVt9_BW {
    sVtEntBW e[9];
} __attribute__((aligned(8)));

struct sVt22_BW {
    sVtEntBW e[22];
} __attribute__((aligned(8)));

extern const sVt9_BW D_00488DA8;
extern const sVt22_BW D_00488DF0;
extern char D_00459B90[];
extern char D_00487968[];
extern char D_00487980[];
extern "C" void cRider_cRider(void* self);
struct sWakeDCF28;
extern "C" void func_002DCF28(sWakeDCF28* self);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");

struct sWakePtBW {
    float v[4];
    sWakePtBW() {}
};

struct sWakeStripBW {
    int hdr[8];
    sWakePtBW pts[5];
    sWakeStripBW() {}
};

struct sWakeElemBW {
    char data[0x30];
    sWakeElemBW() {}
};

// PORT: hand-written form of g++ 2.95's constructor for a class with a virtual base
// (cRider at +0xC0): vtable copies with delta fixups when not in charge.
extern "C" void* cBoardWakeFX_cBoardWakeFX(void* self, int inChrg)
{
    sVt9_BW t1;
    sVt22_BW t2;
    if (inChrg) {
        *(void**)self = (char*)self + 0xC0;
        cRider_cRider((char*)self + 0xC0);
    }
    *(void**)(*(char**)self + 0x6E8) = (void*)&D_00488DA8;
    *(void**)(*(char**)self + 0x6D0) = D_00459B90;
    *(void**)(*(char**)self + 0x6C0) = (void*)&D_00488DF0;
    if (inChrg == 0) {
        int vc;
        t1 = D_00488DA8;
        *(void**)(*(char**)self + 0x6E8) = &t1;
        {
            char* vbo = *(char**)self - 0xC0;
            vc = (char*)self - vbo;
        }
        t1.e[1].delta = D_00488DA8.e[1].delta + vc;
        t2 = D_00488DF0;
        *(void**)(*(char**)self + 0x6C0) = &t2;
        t2.e[1].delta = D_00488DF0.e[1].delta + vc;
    }
    sWakeStripBW*& strips = *(sWakeStripBW**)((char*)self + 0xC);
    strips = new (D_00487968, 0, 0) sWakeStripBW[32];
    sWakeElemBW** rows = (sWakeElemBW**)((char*)self + 0x10);
    rows[0] = new (D_00487980, 0, 0) sWakeElemBW[160];
    for (int i = 1; i < 5; i++) {
        rows[i] = *(sWakeElemBW**)((char*)self + 0x10) + i * 32;
    }
    *(int*)((char*)self + 0xB4) = -1;
    func_002DCF28((sWakeDCF28*)self);
    return self;
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_bwf {
public:
    virtual ~cRiderVbA0_bwf();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_bwf : public cRiderVbA0_bwf { public: char padA[0xC]; };
class cRiderVbB0_bwf { public: virtual void b01(); };
class cRiderVbB_bwf : public cRiderVbB0_bwf { public: char padB[0x14]; };
class cRiderVbC0_bwf {
public:
    virtual ~cRiderVbC0_bwf();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_bwf : public cRiderVbC0_bwf { public: char padC[0x10]; };
class cRiderVbBC_bwf : public cRiderVbB_bwf, public cRiderVbC_bwf { public: };
class cRiderVbPad_bwf { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_bwf : public cRiderVbPad_bwf, public cRiderVbA_bwf, public cRiderVbBC_bwf {
public:
    virtual ~cRiderVb_bwf();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DCDA0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

class cVbDtor002DCDA0 : virtual public cRiderVb_bwf {
public:
    char pad04[0x8];
    void* m0C;
    void* m10;
    char pad14[0xA8];
    virtual ~cVbDtor002DCDA0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002DCDA0::~cVbDtor002DCDA0()
{
    if (m0C != 0) cMemMan_free(m0C);
    if (m10 != 0) cMemMan_free(m10);
}
// PORT: the compiler names this dtor _$_15cVbDtor002DCDA0; expose it under the address-derived name.
__asm__(".globl func_002DCDA0\n.type func_002DCDA0,@function\nfunc_002DCDA0 = _$_15cVbDtor002DCDA0\n.size func_002DCDA0,0x184\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DCF28);
#ifdef SKIP_ASM
struct sWakeElemDCF28 {
    int a;
    float b;
    float c;
    int d;
    char pad10[0x20];
};

struct sWakeColDCF28 {
    float r, g, b, a;
};

struct sWakeDCF28 {
    char* obj;                    // 0x00
    int f4;                       // 0x04
    int f8;                       // 0x08
    int fC;                       // 0x0C
    sWakeElemDCF28* elems[5];     // 0x10
    float vals[5];                // 0x24
    int f38;                      // 0x38
    int f3C;                      // 0x3C
    int f40;                      // 0x40
    char pad44[0x1C];             // 0x44
    char sub60[0x40];             // 0x60
    sWakeColDCF28 col;            // 0xA0
    int fB0;                      // 0xB0
    int count;                    // 0xB4
    int fB8;                      // 0xB8
    float fBC;                    // 0xBC
};

extern "C" void func_002DE368(void* self);

extern "C" void func_002DCF28(sWakeDCF28* self)
{
    int old = self->count;
    float one;
    sWakeColDCF28 c;
    int i;
    if (*(int*)(self->obj + 0x870) >= 0) {
        self->count = 5;
        self->fB8 = 0x20;
        self->fBC = 1.25f;
    } else {
        self->count = 4;
        self->fB8 = 0x16;
        self->fBC = 0.800000011920929f;
    }
    one = 1.0f;
    c.r = one;
    c.g = one;
    c.b = one;
    c.a = one;
    self->col = c;
    self->f38 = 0;
    self->f4 = 0;
    self->f8 = 0;
    self->f3C = 0;
    self->f40 = 0;
    func_002DE368(self->sub60);
    if (old != self->count) {
        for (i = 0; i < 5; i++) {
            float t = 0.9900000095367432f - (float)i * (0.9800000190734863f / (float)(self->count - 1));
            int j;
            for (j = 0; j < 32; j++) {
                self->elems[i][j].a = 0;
                self->elems[i][j].b = t;
                self->elems[i][j].c = 1.0f;
                self->elems[i][j].d = 0;
            }
            self->vals[i] = (float)i / (float)(self->count - 1) * -25.000001907348633f;
        }
    }
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002DD0B8);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DDAB8);
#ifdef SKIP_ASM
extern char* D_004A289C;
extern int D_004A4528;

struct sGs_DAB8 {
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
    unsigned int wC;
    unsigned int f10 : 16;
    unsigned int f10hi : 16;
    void SetF22(int v) { f4_22 = v; }
};

extern sGs_DAB8 D_00501420_DAB8 __asm__("D_00501420");

struct sWakeVtx_DAB8 {
    char pad0[0x64];
    float age;               // 0x64
    char pad68[0x8];
};

struct sWake_DAB8 {
    char pad0[0x4];
    int count;               // 0x04
    int first;               // 0x08
    sWakeVtx_DAB8* verts;    // 0x0C
    char verts10[0xB4 - 0x10]; // 0x10
    int tex;                 // 0xB4
    int max;                 // 0xB8
    float life;              // 0xBC
};

class cGfx_DAB8 {
public:
    char pad[0xE84];
    sGs_DAB8* stateTop;
    char padE88[0x1030 - 0xE88];
    int f1030;
    int Get1030() { return f1030; }
    void PushState() { stateTop[1] = stateTop[0]; stateTop++; }
    char pad1034[0x10D8 - 0x1034];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void DrawStrip(void* verts, int tex, int first, int max, int n, float a, float da);
};

// Board wake: draws the wake strip with alpha fading by the age of the newest point.
extern "C" void func_002DDAB8(sWake_DAB8* self)
{
    if (D_004A4528 != 0 || self->count == 0)
        return;
    ((cGfx_DAB8*)D_004A289C)->PushState();
    *((cGfx_DAB8*)D_004A289C)->stateTop = D_00501420_DAB8;
    *(short*)(*(char**)(D_004A289C + 0xE84) + 0x10) = ((cGfx_DAB8*)D_004A289C)->Get1030();
    ((cGfx_DAB8*)D_004A289C)->stateTop->f0_2 = 0;
    ((cGfx_DAB8*)D_004A289C)->stateTop->SetF22(1);
    ((cGfx_DAB8*)D_004A289C)->stateTop->f4_23 = 0;
    ((cGfx_DAB8*)D_004A289C)->stateTop->f4_20 = 0;
    ((cGfx_DAB8*)D_004A289C)->stateTop->f4_12 = 0x14;
    ((cGfx_DAB8*)D_004A289C)->stateTop->f4_0 = 2;
    ((cGfx_DAB8*)D_004A289C)->stateTop->f8_10 = 0;
    ((cGfx_DAB8*)D_004A289C)->stateTop->f8_5 = 7;
    ((cGfx_DAB8*)D_004A289C)->stateTop->f4_2 = 5;
    float k = 1.25f;
    int draw = self->count;
    int n = draw;
    int over = draw + 2; over -= self->max;
    if (over >= 1)
        draw -= over;
    int last = (self->first + n - 1) % self->max;
    float t = (self->life - self->verts[last].age) / self->life;
    float a = 1.0f;
    if (t <= 0.8f)
        a = t * k;
    float da = (a - k) / (float)n;
    if (draw >= 2)
        ((cGfx_DAB8*)D_004A289C)->DrawStrip(self->verts10, self->tex, self->first, self->max, draw, k, da);
    ((cGfx_DAB8*)D_004A289C)->stateTop--;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DDD30);
#ifdef SKIP_ASM
struct sVecDD30 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sElemDD30 {
    sVecDD30 pts[5];            // 0x00
    sVecDD30 dir;               // 0x50
    float width;                // 0x60
    int i64;                    // 0x64
};

struct sSegDD30 {
    char pad0[0x1C];            // 0x00
    int f1C;                    // 0x1C
    sVecDD30 pos;               // 0x20
};

struct sWakeDD30 {
    char* obj;                  // 0x00
    int i4;                     // 0x04
    int head;                   // 0x08
    sElemDD30* elems;           // 0x0C
    sSegDD30* rings[5];         // 0x10
    char pad24[0x14];           // 0x24
    float phase;                // 0x38
    char pad3C[0x24];           // 0x3C
    sVecDD30 v60;               // 0x60
    sVecDD30 v70;               // 0x70
    sVecDD30 v80;               // 0x80
    float f90;                  // 0x90
    float f94;                  // 0x94
    char pad98[0x1C];           // 0x98
    int n;                      // 0xB4
};

extern sVecDD30 D_004FF120_DD30 __asm__("D_004FF120");
extern "C" float func_002D1928(int n, float x);

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sVecDD30 wakeScaleDD30(const sVecDD30& v, float s)
{
    sVecDD30 r;
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
static inline sVecDD30 wakeAddDD30(const sVecDD30& a, const sVecDD30& b)
{
    sVecDD30 r;
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
static inline sVecDD30 wakeSubDD30(const sVecDD30& a, const sVecDD30& b)
{
    sVecDD30 r;
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
static inline float wakeLenDD30(const sVecDD30& v)
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

extern "C" void func_002DDD30(sWakeDD30* self, sVecDD30* pos, float width)
{
    float w = self->f90 * (func_002D1928(3, self->phase) * 0.25f + 1.0f);
    sElemDD30* e = &self->elems[self->head];
    e->i64 = 0;
    e->pts[0] = D_004FF120_DD30;
    sVecDD30 dir = wakeScaleDD30(wakeScaleDD30(self->v80, -1.0f), wakeLenDD30(*(sVecDD30*)(self->obj + 0x1E0)));
    sVecDD30 neg = wakeScaleDD30(*(sVecDD30*)(self->obj + 0x1E0), -1.0f);
    {
        sVecDD30 x = wakeScaleDD30(wakeSubDD30(dir, neg), 0.85f);
        e->dir = x;
    }
    for (int i = 0; i < self->n; i++) {
        float t = (float)i / (float)(self->n - 1);
        float a = t * t;
        if (i == self->n - 1) {
            t *= 0.9f;
        }
        sVecDD30 x = wakeScaleDD30(wakeAddDD30(wakeScaleDD30(wakeScaleDD30(self->v70, a), 0.75f), wakeScaleDD30(self->v60, t)), w);
        e->pts[i] = x;
    }
    {
        sSegDD30* r0 = self->rings[0];
        sSegDD30* s = (sSegDD30*)(self->head * (int)sizeof(sSegDD30) + (int)r0); // PORT: pointer in int
        sVecDD30 x = wakeSubDD30(*pos, wakeScaleDD30(*(sVecDD30*)(self->obj + 0x370), 5.0f));
        s->pos = x;
    }
    self->rings[0][self->head].f1C = (int)(self->f94 * 128.0f);
    for (int j = 1; j < self->n; j++) {
        self->rings[j][self->head].pos = self->rings[0][self->head].pos;
        self->rings[j][self->head].f1C = self->rings[0][self->head].f1C;
    }
    e->width = width;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DE058);
#ifdef SKIP_ASM
struct sCol_E058 {
    float a, r, g, b;
};

struct sEnt_E058 {
    sCol_E058 col;              // 0x00
    char pad10[0xE0];
};

struct sSeg_E058 {
    float f0;                   // 0x00
    char pad4[0xC];             // 0x04
    int r;                      // 0x10
    int g;                      // 0x14
    int b;                      // 0x18
    char pad1C[0x14];           // 0x1C
};

struct sWakeVt_E058 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sWake_E058 {
    char* obj;                  // 0x00
    int count;                  // 0x04
    int head;                   // 0x08
    char padC[0x4];             // 0x0C
    sSeg_E058* ring;            // 0x10
    sSeg_E058* trails[4];       // 0x14
    char pad24[0x14];           // 0x24
    float phase;                // 0x38
    char pad3C[0x4];            // 0x3C
    int frame;                  // 0x40
    char pad44[0x5C];           // 0x44
    sCol_E058 col;              // 0xA0
    char padB0[0x8];            // 0xB0
    int cap;                    // 0xB8
};

extern sEnt_E058 D_004FA398[];

// PORT: g++ minimum operator (<?).
static inline float wakeClampE058(float v, float lo, float hi)
{
    float r;
    if (v >= lo) {
        r = v <? hi;
    } else {
        r = lo;
    }
    return r;
}

extern "C" void func_002DE058(sWake_E058* self)
{
    self->phase += 0.03333333507180214f;
    if (self->phase >= 4.0f) {
        self->phase -= 4.0f;
    }
    if (self->count < self->cap) {
        self->count++;
    }
    self->head = (self->head + self->cap - 1) % self->cap;
    char* sub = self->obj + 0x6C0;
    sWakeVt_E058* vt = *(sWakeVt_E058**)sub;
    sCol_E058 col = D_004FA398[vt[7].fn(sub + vt[7].delta)].col;
    col.a *= 2.0f;
    col.r *= 2.0f;
    col.g *= 2.0f;
    col.b *= 2.0f;
    col.r = wakeClampE058(col.r, 0.0f, 1.0f);
    col.g = wakeClampE058(col.g, 0.0f, 1.0f);
    col.b = wakeClampE058(col.b, 0.0f, 1.0f);
    col.a = wakeClampE058(col.a, 0.0f, 1.0f);
    self->col = col;
    self->ring[self->head].f0 = (float)self->frame * 0.5f;
    self->ring[self->head].f0 -= (float)(int)(self->ring[self->head].f0 * 0.015625f) * 64.0f + 32.0f;
    self->ring[self->head].r = (int)(self->col.r * 128.0f);
    self->ring[self->head].g = (int)(self->col.g * 128.0f);
    self->ring[self->head].b = (int)(self->col.b * 128.0f);
    int i;
    for (i = 0; i < 4; i++) {
        self->trails[i][self->head].f0 = self->ring[self->head].f0;
        self->trails[i][self->head].r = self->ring[self->head].r;
        self->trails[i][self->head].g = self->ring[self->head].g;
        self->trails[i][self->head].b = self->ring[self->head].b;
    }
    self->frame++;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DE368);
#ifdef SKIP_ASM
struct sVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sVec4 D_004FF120;

extern "C" void func_002DE368(void* self)
{
    *(int*)((char*)self + 0x34) = 0;
    *(int*)((char*)self + 0x30) = 0;
    *(sVec4*)((char*)self + 0x0) = D_004FF120;
    *(sVec4*)((char*)self + 0x20) = D_004FF120;
    *(sVec4*)((char*)self + 0x10) = D_004FF120;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DE398);
#ifdef SKIP_ASM
extern int D_004A3AFC;

struct sWakeVecE398 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only inline asm (float absolute value).
static inline float wakeAbsE398(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: the seed is reinterpreted as a float in [1,2) through memory (type pun).
static inline float wakeRandE398()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline void wakeScaleE398(sWakeVecE398& r, const sWakeVecE398& v, float s)
{
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
}

// PORT: PS2-only VU0 inline asm (a += b).
static inline void wakeAddE398(sWakeVecE398& a, const sWakeVecE398& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}

extern "C" void func_002DE398(char* self, sWakeVecE398* out)
{
    float s = *(float*)(self + 0x12C);
    float a = (1.0f - wakeAbsE398(s)) * 55.0f;
    float lo = -a;
    sWakeVecE398 t;
    sWakeVecE398 tmp;
    wakeScaleE398(tmp, *(sWakeVecE398*)(self + 0x50), s * 55.0f + (lo + (a - lo) * wakeRandE398()));
    t = tmp;
    wakeAddE398(*out, t);
    wakeScaleE398(tmp, *(sWakeVecE398*)(self + 0x40), wakeRandE398() * 20.0f + -10.0f);
    t = tmp;
    wakeAddE398(*out, t);
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002DE4A8);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DF1C8);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
class cVbElemBase002DF1C8 {
public:
    char pad[0x1F8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~cVbElemBase002DF1C8();
};
class cVbElem002DF1C8 : public cVbElemBase002DF1C8 {
public:
    char pad2[0x14];
    virtual ~cVbElem002DF1C8();
    static void operator delete[](void* p) { cMemMan_free(p); }
};

class cVbDtor002DF1C8 : virtual public cRiderVb_bwf {
public:
    char pad04[0x24];
    cVbElem002DF1C8* m28;
    void* m2C;
    char pad30[0x4C];
    void* m7C;
    char pad80[0xAC];
    virtual ~cVbDtor002DF1C8();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002DF1C8::~cVbDtor002DF1C8()
{
    delete[] m28;
    if (m2C != 0) cMemMan_free(m2C);
    if (m7C != 0) cMemMan_free(m7C);
}
// PORT: the compiler names this dtor _$_15cVbDtor002DF1C8; expose it under the address-derived name.
__asm__(".globl func_002DF1C8\n.type func_002DF1C8,@function\nfunc_002DF1C8 = _$_15cVbDtor002DF1C8\n.size func_002DF1C8,0x1E8\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DF3B0);
#ifdef SKIP_ASM
extern "C" void func_002E26B8(void* self);
extern "C" void func_002E2550(void* self);

extern "C" void func_002DF3B0(void* self)
{
    sVec4 c;
    c.x = 1.0f;
    c.y = 1.0f;
    c.z = 1.0f;
    c.w = 1.0f;
    *(float*)((char*)self + 0x120) = 0.5f;
    *(int*)((char*)self + 0x10) = 0;
    *(sVec4*)((char*)self + 0x90) = c;
    *(int*)((char*)self + 0x74) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x80) = 0;
    *(int*)((char*)self + 0x78) = 0;
    *(int*)((char*)self + 0xE0) = 0;
    *(int*)((char*)self + 0x12C) = 0;
    if (*(int*)((char*)self + 0x124) != (*(int*)(*(char**)self + 0x870) >= 0)) {
        func_002E26B8(self);
    }
    func_002E2550(self);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DF448);
#ifdef SKIP_ASM
struct sVEntry2DF448 {
    short delta;
    short index;
    void (*fn)(void*, void*, float);
};

struct func_002DF448_sElem {
    char pad0[0x58];
    float f58;                      // 0x58
    char pad5C[0x1F8 - 0x5C];
    sVEntry2DF448* vt;              // 0x1F8
    char pad1FC[0x210 - 0x1FC];
};

struct func_002DF448_sFx {
    char pad0[0x28];
    func_002DF448_sElem* elems;     // 0x28
    char* data;                     // 0x2C
    char pad30[0x60 - 0x30];
    int f60;                        // 0x60
};

extern "C" void func_002DF448(func_002DF448_sFx* self)
{
    int i;
    for (i = 0; i < 10; i++) {
        // PORT: pointer held in int (index-first address arithmetic)
        func_002DF448_sElem* e = (func_002DF448_sElem*)(i * 0x210 + (int)self->elems);
        sVEntry2DF448* vt = e->vt;
        vt[3].fn((char*)e + vt[3].delta, self->data + i * 0xE8, e->f58);
    }
    self->f60 = 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DF4D0);
#ifdef SKIP_ASM
extern const char D_004879D8[];
extern const char D_004879E8[];
extern const char D_004879F8[];
extern const char D_00487A08[];
extern const char D_00487A18[];
extern const char D_00487A28[];
extern const char D_004A3B00[];
extern const char D_00487A38[];
extern const char D_00487A48[];
extern const char D_00487A58[];
extern const char D_004A3B08[];
extern const char D_00487A68[];
extern const char D_00487A78[];
extern const char D_00487A88[];
extern const char D_00487A98[];
extern const char D_00487AA8[];
extern const char D_00487AB8[];
extern const char D_00487AC8[];
extern const char D_00487AD8[];
extern const char D_00487AE8[];
extern const char D_00487AF8[];
extern "C" int func_00310C48(void* self, int idx, const char* name);

extern "C" void func_002DF4D0(char* self)
{
    (*(int**)(self + 0x7C))[0] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004879D8);
    (*(int**)(self + 0x7C))[1] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004879E8);
    (*(int**)(self + 0x7C))[2] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004879F8);
    (*(int**)(self + 0x7C))[3] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A08);
    (*(int**)(self + 0x7C))[4] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A18);
    (*(int**)(self + 0x7C))[5] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A28);
    (*(int**)(self + 0x7C))[6] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004A3B00);
    (*(int**)(self + 0x7C))[7] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A38);
    (*(int**)(self + 0x7C))[8] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A48);
    (*(int**)(self + 0x7C))[9] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A58);
    (*(int**)(self + 0x7C))[10] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004A3B08);
    (*(int**)(self + 0x7C))[11] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A68);
    (*(int**)(self + 0x7C))[12] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A78);
    (*(int**)(self + 0x7C))[13] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A88);
    (*(int**)(self + 0x7C))[14] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A98);
    (*(int**)(self + 0x7C))[15] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004879D8);
    (*(int**)(self + 0x7C))[16] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004879E8);
    (*(int**)(self + 0x7C))[17] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004879F8);
    (*(int**)(self + 0x7C))[18] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A08);
    (*(int**)(self + 0x7C))[19] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A18);
    (*(int**)(self + 0x7C))[20] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A28);
    (*(int**)(self + 0x7C))[21] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_004A3B00);
    (*(int**)(self + 0x7C))[22] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A38);
    (*(int**)(self + 0x7C))[23] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487A48);
    (*(int**)(self + 0x7C))[24] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487AA8);
    (*(int**)(self + 0x7C))[25] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487AB8);
    (*(int**)(self + 0x7C))[26] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487AC8);
    (*(int**)(self + 0x7C))[27] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487AD8);
    (*(int**)(self + 0x7C))[28] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487AE8);
    (*(int**)(self + 0x7C))[29] = func_00310C48(*(void**)(*(char**)self + 0x780), 0, D_00487AF8);
    int i;
    for (i = 0; i < 30; i++) {
    }
    *(int*)(self + 0x80) = 1;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002DF920);
#ifdef SKIP_ASM
struct sWakeFxF920 {
    char* obj;                  // 0x00
    char pad4[0x24];            // 0x04
    char* p28;                  // 0x28
    char pad2C[0x4];            // 0x2C
    sWakeVecE398 v30;           // 0x30
    sWakeVecE398 v40;           // 0x40
    sWakeVecE398 v50;           // 0x50
    int i60;                    // 0x60
    char pad64[0x10];           // 0x64
    float f74;                  // 0x74
    char pad78[0x8];            // 0x78
    int i80;                    // 0x80
    char pad84[0xC];            // 0x84
    sWakeVecE398 col;           // 0x90
    sWakeVecE398 pos;           // 0xA0
    int iB0;                    // 0xB0
    float fB4;                  // 0xB4
    float fB8;                  // 0xB8
    float fBC;                  // 0xBC
    sWakeVecE398 dir;           // 0xC0
    char* pD0;                  // 0xD0
    int iD4;                    // 0xD4
    char padD8[0x50];           // 0xD8
    int i128;                   // 0x128
    float f12C;                 // 0x12C
};

struct sWakeVtF920 {
    short delta;
    short index;
    sWakeVecE398* (*fn)(void*);
};
struct sWakeVtIF920 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sMtxF920 {
    sWakeVecE398 r0, r1, r2, r3;
};

extern void* D_004A28A8;
int func_0011FE98(void*);
int func_0011FEE8(void*);
int func_00312AA0(void*, int);
extern "C" void func_002DF448_F920(void*) __asm__("func_002DF448");
extern "C" void func_002DF4D0_F920(void*) __asm__("func_002DF4D0");
extern "C" void func_002E23E0_F920(void*, void*, void*, int, int, float) __asm__("func_002E23E0");
extern "C" void func_002E02B8_F920(void*) __asm__("func_002E02B8");
extern "C" void func_002DFE88_F920(void*) __asm__("func_002DFE88");
extern "C" void func_002E0EE8_F920(void*) __asm__("func_002E0EE8");
extern "C" void func_002E1120_F920(void*) __asm__("func_002E1120");
extern "C" void func_002E1598_F920(void*) __asm__("func_002E1598");
extern "C" void func_002E1A80_F920(void*) __asm__("func_002E1A80");
extern "C" void func_002E2260_F920(void*) __asm__("func_002E2260");
extern "C" void func_002E1F70_F920(void*) __asm__("func_002E1F70");

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float wakeLenF920(const sWakeVecE398& v)
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

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void wakeDivEqF920(sWakeVecE398& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s));
}

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sWakeVecE398 wakeScaleF920(const sWakeVecE398& v, float s)
{
    sWakeVecE398 r;
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
static inline sWakeVecE398 wakeAddF920(const sWakeVecE398& a, const sWakeVecE398& b)
{
    sWakeVecE398 r;
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

static inline sWakeVecE398 wakeRowF920(char* o, int k)
{
    return ((sWakeVecE398*)(*(char**)(*(char**)(o + 0x780) + 0x30) + (*(int*)(o + 0x8A4) << 6)))[k];
}

extern "C" void func_002DF920(sWakeFxF920* self)
{
    if (self->i60 != 0) {
        func_002DF448_F920(self);
    }
    if (self->i80 == 0) {
        func_002DF4D0_F920(self);
    }
    self->f12C = 0.0f;
    char* obj = self->obj;
    if (*(int*)(obj + 0x330) != 0) {
        int s = func_00312AA0(*(void**)(obj + 0x784), 2);
        if ((s >= 23 && s <= 28) || s == 37 || s == 38) {
            self->f12C = *(int*)(self->obj + 0x320) ? -1.0f : 1.0f;
        } else {
            self->f12C = *(int*)(self->obj + 0x320) ? 1.0f : -1.0f;
        }
    }
    obj = self->obj;
    self->fB4 = -*(float*)(obj + 0x1F0) * (1.0f - wakeAbsE398(*(float*)(obj + 0x214)));
    if (*(int*)(obj + 0x320) != 0) {
        self->fB4 = -self->fB4;
    }
    char* sub = self->obj + 0x6C0;
    sWakeVtF920* vt = *(sWakeVtF920**)sub;
    float sp = wakeLenF920(*vt[2].fn(sub + vt[2].delta));
    self->fB8 = sp;
    self->fBC = wakeAbsE398(sp);
    self->dir = *(sWakeVecE398*)(self->obj + 0x1E0);
    if (0.0f < sp) {
        wakeDivEqF920(self->dir, wakeLenF920(self->dir));
    }
    self->iB0 = 1;
    int st = func_0011FE98(self->obj);
    self->iD4 = st;
    if (st == 1 || st == 2 || st == 4 || func_0011FEE8(self->obj) == 9) {
        self->iB0 = 0;
    } else {
        char* o = self->obj;
        if (*(int*)(o + 0xAC4) != 0) {
            int t = *(int*)(o + 0xAD0) == 0 && *(int*)(o + 0xAFC) != 0;
            if (!t || *(int*)(o + 0xB00) == 0) {
                self->iB0 = 0;
            }
        }
    }
    char* o = self->obj;
    self->v50 = wakeRowF920(o, 0);
    float acc = (self->f74 - self->fB8) * 59.999996185302734f;
    self->v30 = wakeRowF920(o, 1);
    self->v40 = wakeRowF920(o, 2);
    self->pos = wakeRowF920(o, 3);
    self->pD0 = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x44) + *(int*)(o + 0x438) * 0xB0;
    int x = 0;
    if (555.5555419921875f < acc && 555.5555419921875f < self->fB8) {
        x = func_0011FEE8(o) != 9;
    }
    float f = acc * 0.5f;
    char* o2 = self->obj;
    int y = 0;
    if (*(int*)(o2 + 0xAC4) != 0 && *(int*)(o2 + 0xAD0) == 0) {
        y = *(int*)(o2 + 0xAFC) != 0;
    }
    if (y) {
        x = 27.77777862548828f <= acc;
        f = acc;
    }
    if (self->iB0 != 0 && x) {
        sWakeVecE398 p = wakeAddF920(self->pos, wakeScaleF920(*(sWakeVecE398*)(self->obj + 0x370), 10.0f));
        func_002E23E0_F920(self, &p, self->obj + 0x370, *(int*)(self->obj + 0x438), 1, f);
    }
    self->f74 = self->fB8;
    if (self->i128 != *(int*)(self->obj + 0x898)) {
        func_002E2550(self);
    }
    char* sub2 = self->obj + 0x6C0;
    sWakeVtIF920* vt2 = *(sWakeVtIF920**)sub2;
    int idx = vt2[7].fn(sub2 + vt2[7].delta);
    sEnt_E058* e = &D_004FA398[idx];
    sWakeVecE398 c;
    c.x = e->col.r;
    c.y = e->col.g;
    c.z = e->col.b;
    c.w = e->col.a;
    self->col = c;
    wakeScaleE398(self->col, self->col, 2.0f);
    self->col.w = 1.0f;
    if (*(int*)(self->p28 + 0x384)) func_002E02B8_F920(self);
    if (*(int*)(self->p28 + 0x7A4)) func_002DFE88_F920(self);
    if (*(int*)(self->p28 + 0x174)) func_002E0EE8_F920(self);
    if (*(int*)(self->p28 + 0x9B4)) func_002E1120_F920(self);
    if (*(int*)(self->p28 + 0xBC4)) func_002E1598_F920(self);
    if (*(int*)(self->p28 + 0xFE4)) func_002E1A80_F920(self);
    if (*(int*)(self->p28 + 0x1404)) func_002E2260_F920(self);
    if (*(int*)(self->p28 + 0x11F4)) func_002E1F70_F920(self);
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002DFE88);

INCLUDE_ASM("visualfx/boardwakefx", func_002E02B8);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E0EE8);
#ifdef SKIP_ASM
struct sWakeFx0EE8 {
    char* obj;                  // 0x00
    char pad4[0x24];            // 0x04
    char* em;                   // 0x28
    char* p2C;                  // 0x2C
    sWakeVecE398 dir;           // 0x30
    char pad40[0x50];           // 0x40
    sWakeVecE398 col;           // 0x90
    sWakeVecE398 pos;           // 0xA0
    int iB0;                    // 0xB0
    char padB4[0x8];            // 0xB4
    float fBC;                  // 0xBC
    char padC0[0x10];           // 0xC0
    char* pD0;                  // 0xD0
};

struct sWakeVt0EE8 {
    short delta;
    short index;
    sWakeVecE398* (*fn)(void*);
};

extern "C" void func_003717C0(void* em, void* pos, void* d, void* vel, int alive, float dt);

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sWakeVecE398 wakeScale0EE8(const sWakeVecE398& v, float s)
{
    sWakeVecE398 r;
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
static inline sWakeVecE398 wakeAdd0EE8(const sWakeVecE398& a, const sWakeVecE398& b)
{
    sWakeVecE398 r;
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

static inline float wakeLimit0EE8()
{
    return 222.22222900390625f;
}

extern "C" void func_002E0EE8(sWakeFx0EE8* self)
{
    int flag = *(int*)(*(char**)(self->obj + 0x88C) + 0xA0);
    char* em = self->em;
    if (self->iB0 != 0 && wakeLimit0EE8() < self->fBC && *(int*)(self->pD0 + 0x58) != 0 && flag == 0) {
        sWakeVecE398 pos = wakeAdd0EE8(self->pos, wakeScale0EE8(self->dir, 15.0f));
        func_002DE398((char*)self, &pos);
        char* sub = self->obj + 0x6C0;
        sWakeVt0EE8* vt = *(sWakeVt0EE8**)sub;
        sWakeVecE398* v = vt[2].fn(sub + vt[2].delta);
        sWakeVecE398 vel = wakeAdd0EE8(
            wakeAdd0EE8(wakeScale0EE8(*v, *(float*)(self->p2C + 0xD8)),
                        wakeScale0EE8(*(sWakeVecE398*)(self->obj + 0x370), *(float*)(self->p2C + 0xDC))),
            wakeScale0EE8(wakeScale0EE8(*(sWakeVecE398*)(self->obj + 0x370), *(float*)(self->p2C + 0xE0)), self->fBC));
        func_003717C0(em, &pos, &vel, &self->col, 1, 0.01666666753590107f);
    } else {
        func_003717C0(em, &self->pos, 0, 0, 0, 0.01666666753590107f);
    }
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E10B8);

INCLUDE_ASM("visualfx/boardwakefx", func_002E1120);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E1598);
#ifdef SKIP_ASM
struct sWakeFx1598 {
    char* obj;                  // 0x00
    float f4;                   // 0x04
    char pad8[0x20];            // 0x08
    char* p28;                  // 0x28
    char pad2C[0x64];           // 0x2C
    sWakeVecE398 col;           // 0x90
    sWakeVecE398 pos;           // 0xA0
    char padB0[0x20];           // 0xB0
    char* pD0;                  // 0xD0
    int iD4;                    // 0xD4
    char padD8[0x8];            // 0xD8
    float fE0;                  // 0xE0
    char padE4[0xC];            // 0xE4
    sWakeVecE398 vF0;           // 0xF0
    sWakeVecE398 dir;           // 0x100
    char pad110[0x4];           // 0x110
    int i114;                   // 0x114
    char pad118[0x8];           // 0x118
    float f120;                 // 0x120
    int i124;                   // 0x124
};

extern "C" void func_002F4118(void*, float);

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float wakeDot1598(const sWakeVecE398& a, const sWakeVecE398& b)
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

// PORT: PS2-only VU0 inline asm (a - b).
static inline sWakeVecE398 wakeSub1598(const sWakeVecE398& a, const sWakeVecE398& b)
{
    sWakeVecE398 r;
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

struct sWakeVt1598 {
    short delta;
    short index;
    sWakeVecE398* (*fn)(void*);
};

// PORT: g++ minimum operator (<?).
static inline float wakeClamp1598(float v, float lo, float hi)
{
    float r;
    if (v >= lo) {
        r = v <? hi;
    } else {
        r = lo;
    }
    return r;
}

static inline float wakeMin1598(float a, float b)
{
    return a <= b ? a : b;
}

static inline sWakeVecE398* wakeVel1598(sWakeFx1598* self)
{
    char* sub = self->obj + 0x6C0;
    sWakeVt1598* vt = *(sWakeVt1598**)sub;
    return vt[2].fn(sub + vt[2].delta);
}

// PORT: g++ minimum operator (<?).
extern "C" void func_002E1598(sWakeFx1598* self)
{
    char* cfg = self->pD0;
    if (27.77777862548828f < self->fE0 && *(int*)(cfg + 0x60) != 0) {
        int a = 6;
        int b = 5;
        if (*(int*)(cfg + 0x64) != 0 && 277.77777099609375f < self->fE0) {
            a = 5;
            b = 6;
        }
        if (a == 5 && *(int*)(self->obj + 0xAC4) == 0) {
            func_002F4118(&self->vF0, self->fE0);
        }
        sWakeVecE398 pos = self->vF0;
        float k = 1.0f;
        if (a == 6) {
            k = 0.5f;
            wakeAddE398(pos, wakeScale0EE8(self->dir, 20.0f));
        } else {
            wakeAddE398(pos, wakeScale0EE8(self->dir, 45.0f));
        }
        float lim = 3333.33349609375f;
        float r = wakeClamp1598(self->fE0 / lim, 0.0f, 1.0f);
        float f = self->f4;
        if (f < 1.0f || a == 5) {
            if (self->iD4 == 2) {
                if (f < 2.0f) {
                    float n = f + (r + r) * k;
                    self->f4 = wakeMin1598(n, 2.0f);
                }
            } else if (self->i114 == 0) {
                if (f < 1.5f) {
                    self->f4 = (f + r * (k * 1.5f)) <? 2.0f;
                }
            } else {
                if (f < 1.0f) {
                    self->f4 = (f + r * k) <? 2.0f;
                }
            }
        }
        float j = 25.0f;
        if (*(int*)(cfg + 0x64) != 0 && self->i124 != 0) {
            j = 60.0f;
        }
        float lo = -j;
        {
            sWakeVecE398 t;
            t.z = 0.0f;
            t.w = 0.0f;
            t.x = lo + (j - lo) * wakeRandE398();
            t.y = lo + (j - lo) * wakeRandE398();
            wakeAddE398(pos, t);
        }
        sWakeVecE398* va = wakeVel1598(self);
        sWakeVecE398* vb = wakeVel1598(self);
        sWakeVecE398* up = (sWakeVecE398*)(self->obj + 0x370);
        sWakeVecE398 t = wakeSub1598(*va, wakeScale0EE8(*up, wakeDot1598(*vb, *up) * 0.75f));
        float m = 0.30000001192092896f;
        if (self->i114 == 0) m = 0.4000000059604645f;
        sWakeVecE398 vel = wakeScale0EE8(t, m);
        float al = 0.5f;
        if (self->i114 == 0) al = 1.0f;
        if (self->f120 < al) {
            self->f120 = al;
        } else {
            self->f120 = self->f120 * 0.800000011920929f + al * 0.19999998807907104f;
        }
        sWakeVecE398 col = self->col;
        col.w = self->f120;
        func_003717C0(self->p28 + a * 0x210, &pos, &vel, &col, 1, 0.01666666753590107f);
        func_003717C0(self->p28 + b * 0x210, &self->vF0, 0, 0, 0, 0.01666666753590107f);
        if (self->fE0 < 83.33333587646484f) {
            self->fE0 = 0.0f;
        } else {
            float m = *(float*)(cfg + 0x68);
            if (self->i124 == 0) {
                m *= 0.4000000059604645f;
            }
            self->fE0 = self->fE0 * m;
        }
    } else {
        func_003717C0(self->p28 + 0xC60, &self->pos, 0, 0, 0, 0.01666666753590107f);
        func_003717C0(self->p28 + 0xA50, &self->pos, 0, 0, 0, 0.01666666753590107f);
        self->fE0 = 0.0f;
    }
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E1A80);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E1F70);
#ifdef SKIP_ASM
struct sWakeFx1F70 {
    char* obj;                  // 0x00
    char pad4[0xC];             // 0x04
    float f10;                  // 0x10
    char pad14[0x14];           // 0x14
    char* p28;                  // 0x28
    char* p2C;                  // 0x2C
    sWakeVecE398 dir;           // 0x30
    char pad40[0x50];           // 0x40
    sWakeVecE398 col;           // 0x90
    sWakeVecE398 pos;           // 0xA0
    int iB0;                    // 0xB0
    char padB4[0x8];            // 0xB4
    float fBC;                  // 0xBC
    char padC0[0x10];           // 0xC0
    char* pD0;                  // 0xD0
};

struct sWakeVt1F70 {
    short delta;
    short index;
    sWakeVecE398* (*fn)(void*);
};

// PORT: g++ minimum operator (<?).
static inline float wakeClamp1F70(float v, float lo, float hi)
{
    float r;
    if (v >= lo) {
        r = v <? hi;
    } else {
        r = lo;
    }
    return r;
}

static inline float wakeLimit1F70()
{
    return 277.77777099609375f;
}

static inline sWakeVecE398* wakeVel1F70(sWakeFx1F70* self)
{
    char* sub = self->obj + 0x6C0;
    sWakeVt1F70* vt = *(sWakeVt1F70**)sub;
    return vt[2].fn(sub + vt[2].delta);
}

// PORT: g++ minimum/maximum operators (<?, >?).
extern "C" void func_002E1F70(sWakeFx1F70* self)
{
    int done = 0;
    void* em = self->p28 + 0x1080;
    if (self->iB0 == 0 || *(float*)(self->pD0 + 0x5C) < 0.009999999776482582f) {
        self->f10 = (self->f10 - 0.01666666753590107f) >? 0.0f;
    } else {
        done = 1;
        self->f10 = (self->f10 + 0.010000000707805157f) <? *(float*)(self->pD0 + 0x5C);
    }
    if ((self->iB0 == 0 && wakeVel1F70(self)->z < -3333.33349609375f) || self->fBC < wakeLimit1F70()) {
        self->f10 = 0.0f;
    }
    sWakeVecE398 pos = self->pos;
    if (!done && 0.0f < self->f10) {
        float a = wakeClamp1F70(self->f10 * 1.25f, 0.0f, 1.0f);
        if (wakeVel1F70(self)->z < 0.0f) {
            a *= wakeClamp1F70((wakeVel1F70(self)->z + 3333.33349609375f) / 3333.33349609375f, 0.0f, 1.0f);
        }
        sWakeVecE398 col = self->col;
        col.w = a;
        sWakeVecE398* v = wakeVel1F70(self);
        sWakeVecE398 vel = wakeAdd0EE8(
            wakeAdd0EE8(wakeScale0EE8(*v, *(float*)(self->p2C + 0x818)),
                        wakeScale0EE8(self->dir, *(float*)(self->p2C + 0x81C))),
            wakeScale0EE8(wakeScale0EE8(self->dir, *(float*)(self->p2C + 0x820)), self->fBC));
        func_002DE398((char*)self, &pos);
        func_003717C0(em, &pos, &vel, &col, 1, 0.01666666753590107f);
    } else {
        func_003717C0(em, &self->pos, 0, 0, 0, 0.01666666753590107f);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E2260);
#ifdef SKIP_ASM
struct sWakeMtx2260 {
    sWakeVecE398 row[4];
};

struct sWakeFx2260 {
    char* obj;                  // 0x00
    float f4;                   // 0x04
    char pad8[0x20];            // 0x08
    char* p28;                  // 0x28
    char* p2C;                  // 0x2C
    char pad30[0x48];           // 0x30
    int i78;                    // 0x78
    int* p7C;                   // 0x7C
    char pad80[0x10];           // 0x80
    sWakeVecE398 col;           // 0x90
    char padA0[0x18];           // 0xA0
    float fB8;                  // 0xB8
    char padBC[0x18];           // 0xBC
    int iD4;                    // 0xD4
};

extern "C" void func_003717C0(void* em, void* pos, void* d, void* vel, int alive, float dt);

// PORT: g++ minimum operator (<?).
static inline float wakeClamp2260(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

static inline float wakeLimit2260()
{
    return 83.33333587646484f;
}

// PORT: g++ maximum operator (>?).
extern "C" void func_002E2260(sWakeFx2260* self)
{
    float zero = 0.0f;
    void* em = self->p28 + 0x1290;
    if (zero < self->f4 && wakeLimit2260() < self->fB8) {
        float dt;
        float a;
        sWakeVecE398 col;
        sWakeVecE398 pos;
        sWakeVecE398 vel;
        sWakeVecE398 tmp;
        char* obj;
        sWakeMtx2260* m;
        int k;
        a = wakeClamp2260(self->f4 * 1.5f, zero, 1.0f);
        col = self->col;
        col.w = a;
        dt = 0.01666666753590107f;
        obj = self->obj;
        k = self->p7C[self->i78];
        m = *(sWakeMtx2260**)(*(char**)(obj + 0x780) + 0x30);
        pos = ((sWakeMtx2260*)((char*)m + (k << 6)))->row[3];
        wakeScaleE398(tmp, *(sWakeVecE398*)(obj + 0x1E0), *(float*)(self->p2C + 0x900));
        vel = tmp;
        func_003717C0(em, &pos, &vel, &col, 1, dt);
        self->i78++;
        if (self->i78 >= 30) {
            self->i78 = 0;
        }
        if (self->iD4 != 2) {
            self->f4 = (self->f4 - dt) >? zero;
        }
    } else {
        char* obj = self->obj;
        int k = *(int*)(obj + 0x89C);
        sWakeMtx2260* m = *(sWakeMtx2260**)(*(char**)(obj + 0x780) + 0x30);
        sWakeVecE398 pos = ((sWakeMtx2260*)((char*)m + (k << 6)))->row[3];
        func_003717C0(em, &pos, 0, 0, 0, 0.01666666753590107f);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E23E0);
#ifdef SKIP_ASM
struct sV4_23E0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only inline asm (float absolute value).
static inline float Abs_23E0(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_23E0 Sub_23E0(const sV4_23E0& a, const sV4_23E0& b)
{
    sV4_23E0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector length via vsqrt).
static inline float Length_23E0(const sV4_23E0& v)
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

struct sRiderState_23E0 {
    char pad[0xAC4];
    int fAC4;
    char padAC8[8];
    int fAD0;
    char padAD4[0x28];
    int fAFC;
    int fB00;
};

static inline int Carving_23E0(sRiderState_23E0* r)
{
    return r->fAC4 != 0 && r->fAD0 == 0 && r->fAFC != 0;
}

struct sWake_23E0 {
    sRiderState_23E0* rider;    // 0x00
    char pad4[0xDC];
    float lastSpeed;            // 0xE0
    char padE4[0xC];
    sV4_23E0 pos;               // 0xF0
    sV4_23E0 dir;               // 0x100
    int f110;                   // 0x110
    int f114;                   // 0x114
    char pad118[0xC];
    int f124;                   // 0x124
};

extern "C" void func_002E23E0(sWake_23E0* self, sV4_23E0* pos, sV4_23E0* dir, int a, int b, float speed)
{
    float s = Abs_23E0(speed);
    float d = Abs_23E0(Length_23E0(Sub_23E0(self->pos, *pos)));
    float maxd = 180.0f;
    if (self->f124 != 0)
        maxd = 100.0f;
    if (self->lastSpeed < s) {
        if (maxd < d || (Carving_23E0(self->rider) && self->rider->fB00 != 0)) {
            if (b == 0)
                self->lastSpeed = s + s;
            else
                self->lastSpeed = s;
            self->pos = *pos;
            self->dir = *dir;
            self->f110 = a;
            self->f114 = b;
        }
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E24D0);
#ifdef SKIP_ASM
extern "C" void func_00371688(void* self, int mode);

struct func_002E24D0_sWake {
    char pad_0x000[0x174];
    void* field_0x174;
    char pad_0x178[0x1E0 - 0x178];
    int field_0x1E0;
    char pad_0x1E4[0x210 - 0x1E4];
};

struct func_002E24D0_sFx {
    void* owner;                    // 0x0
    char pad_0x04[0x24];
    func_002E24D0_sWake* wakes;     // 0x28
};

extern "C" void func_002E24D0(func_002E24D0_sFx* self)
{
    if (*(int*)((char*)self->owner + 0xB18) != 0) {
        int i;
        for (i = 0; i < 10; i++) {
            func_002E24D0_sWake* w = &self->wakes[i];
            if (w->field_0x174 != 0 && w->field_0x1E0 > 0) {
                func_00371688(w, 7);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E2550);
#ifdef SKIP_ASM
#define S28(off) (*(int*)((char*)*(void**)((char*)self + 0x28) + (off)))

extern "C" void func_002E2550(void* self)
{
    int mode = *(int*)((char*)*(void**)self + 0x898);
    *(int*)((char*)self + 0x128) = mode;
    switch (mode) {
    case 0:
        S28(0xBC4) = 1;
        S28(0xDD4) = 1;
        S28(0x174) = 1;
        {
            int v = 0;
            if (*(int*)((char*)self + 0x124) != 0 || *(int*)((char*)*(void**)self + 0xAC4) != 0)
                v = 1;
            S28(0x9B4) = v;
        }
        S28(0x384) = *(int*)((char*)self + 0x124);
        S28(0x594) = *(int*)((char*)self + 0x124);
        S28(0x7A4) = *(int*)((char*)self + 0x124);
        S28(0xFE4) = *(int*)((char*)self + 0x124);
        S28(0x11F4) = *(int*)((char*)self + 0x124);
        S28(0x1404) = *(int*)((char*)self + 0x124);
        break;
    case 1:
        S28(0xBC4) = 1;
        S28(0xDD4) = 1;
        S28(0x174) = 1;
        S28(0x384) = *(int*)((char*)self + 0x124);
        S28(0x594) = *(int*)((char*)self + 0x124);
        S28(0x7A4) = *(int*)((char*)self + 0x124);
        S28(0xFE4) = *(int*)((char*)self + 0x124);
        S28(0x11F4) = *(int*)((char*)self + 0x124);
        S28(0x9B4) = 0;
        S28(0x1404) = 0;
        break;
    default:
        S28(0xBC4) = 1;
        S28(0xDD4) = *(int*)((char*)self + 0x124);
        S28(0x384) = 0;
        S28(0x174) = 0;
        S28(0x594) = 0;
        S28(0x7A4) = 0;
        S28(0xFE4) = 0;
        S28(0x9B4) = 0;
        S28(0x11F4) = 0;
        S28(0x1404) = 0;
        break;
    }
}
#undef S28
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E26B8);
#ifdef SKIP_ASM
struct sWakeVt26B8 { short delta; short index; void (*fn)(void*, void*, float); };

extern "C" void func_002E26B8(void* vself)
{
    char* self = (char*)vself;
    int on = *(int*)(*(char**)self + 0x870) >= 0;
    *(int*)(self + 0x124) = on;
    if (on) {
        *(float*)(*(char**)(self + 0x2C) + 0x498) = 55.0f;
        *(float*)(*(char**)(self + 0x2C) + 0x4A0) = 25.0f;
        *(float*)(*(char**)(self + 0x2C) + 0x554) = 170.0f;
        *(float*)(*(char**)(self + 0x2C) + 0x580) = 30.0f;
        *(float*)(*(char**)(self + 0x2C) + 0x588) = 20.0f;
        *(float*)(*(char**)(self + 0x2C) + 0x63C) = 60.0f;
    } else {
        *(float*)(*(char**)(self + 0x2C) + 0x498) = 24.75f;
        *(float*)(*(char**)(self + 0x2C) + 0x4A0) = 5.0f;
        *(float*)(*(char**)(self + 0x2C) + 0x554) = 76.5f;
        *(float*)(*(char**)(self + 0x2C) + 0x580) = 19.5f;
        *(float*)(*(char**)(self + 0x2C) + 0x588) = 8.0f;
        *(float*)(*(char**)(self + 0x2C) + 0x63C) = 39.0f;
    }
    {
        char* b = *(char**)(self + 0x28);
        char* o = b + 0xA50;
        sWakeVt26B8* vt = *(sWakeVt26B8**)(b + 0xC48);
        vt[3].fn(o + vt[3].delta, *(char**)(self + 0x2C) + 0x488, *(float*)(b + 0xAA8));
    }
    {
        char* b = *(char**)(self + 0x28);
        char* o = b + 0xC60;
        sWakeVt26B8* vt = *(sWakeVt26B8**)(b + 0xE58);
        vt[3].fn(o + vt[3].delta, *(char**)(self + 0x2C) + 0x570, *(float*)(b + 0xCB8));
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E27E8);
#ifdef SKIP_ASM
extern "C" float func_002E27E8(int type)
{
    switch (type) {
    case 0x10:
        return 180.0f;
    case 0x20:
        return 100.0f;
    case 0x40:
        return 350.0f;
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E2860__FPv);
#ifdef SKIP_ASM
void* func_002E2860(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E2868);
#ifdef SKIP_ASM
struct sV3_2868 { float x, y, z; };
struct sV4_2868 { float x, y, z, w; sV4_2868(const float& a, const float& b, const float& c, const float& d) { x = a; y = b; z = c; w = d; } };
struct sV2_2868 { float x, y; sV2_2868() { x = 0.0f; y = 0.0f; } sV2_2868(const float& a, const float& b) { x = a; y = b; } };
struct sCol_2868 { float a; sV3_2868 d; };

struct sRsState_2868 {
    int f0;                 // 0x0
    int flagsA;             // 0x4
    int flagsB;             // 0x8
    int fC;                 // 0xC
    short tex;              // 0x10
    short pad;
};

struct sRsVEnt_2868 {
    short delta;
    short index;
    void (*fn)(void*, sV4_2868*, sV2_2868*, sV2_2868*, sV2_2868*, sCol_2868*, float, int);
};

struct sRsCtx_2868 {
    char pad0[0xE84];
    sRsState_2868* top;         // 0xE84
    char pad1[0x1024 - 0xE88];
    int tex1024;                // 0x1024
    int tex1028;                // 0x1028
    char pad2[0x10D8 - 0x102C];
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
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void Draw(const sV4_2868& pos, const sV2_2868& size, const sV2_2868& uv0, const sV2_2868& uv1, const sCol_2868& col, float rot, int flags);
};

struct sPart_2868 {
    char pad0[0xC];
    int flags;                  // 0xC
    sV3_2868 vel;               // 0x10
    sV3_2868 pos;               // 0x1C
    char pad28[0x40 - 0x28];
    float alpha[1];             // 0x40
};

struct sWake_2868 {
    char pad0[0x20];
    sPart_2868* part;           // 0x20
    char pad24[4];
    float rot;                  // 0x28
    unsigned short on;          // 0x2C
    unsigned short useAlpha;    // 0x2E
};

extern sRsCtx_2868* D_004A5B80_2868 __asm__("D_004A5B80");

// PORT: PS2 sqrt.s asm helper; use sqrtf on PC.
static inline float Sqrt_2868(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline int rsTex1024_2868(sRsCtx_2868* ctx)
{
    return ctx->tex1024;
}

static inline int rsTex1028_2868(sRsCtx_2868* ctx)
{
    return ctx->tex1028;
}

static inline void rsSetA_2868(sRsCtx_2868* ctx, int mask, int shift, int v)
{
    ctx->top->flagsA = (ctx->top->flagsA & ~mask) | ((v << shift) & mask);
}

extern "C" void func_002E2868(sWake_2868* self, int idx)
{
    if (self->on == 0) {
        return;
    }
    sV3_2868 n;
    sPart_2868* q = self->part;
    float x = q->vel.x;
    float y = q->vel.y;
    float z = q->vel.z;
    float len = Sqrt_2868(x * x + y * y + z * z);
    if (len != 0.0f) {
        float inv = 1.0f / len;
        n.x = x * inv;
        n.y = y * inv;
        n.z = z * inv;
    } else {
        n.x = q->vel.x;
        n.y = q->vel.y;
        n.z = q->vel.z;
    }
    sCol_2868 col;
    col.d.x = n.x;
    col.d.y = n.y;
    col.d.z = n.z;
    sRsCtx_2868* ctx = D_004A5B80_2868;
    if (self->useAlpha != 0) {
        col.a = self->part->alpha[idx];
        rsSetA_2868(ctx, 0x1800000, 23, 2);
        rsSetA_2868(ctx, 0x300000, 20, 0);
        rsSetA_2868(ctx, 0xFF000, 12, 0x14);
    } else {
        col.a = 1.0f;
        rsSetA_2868(ctx, 0x1800000, 23, 1);
        rsSetA_2868(ctx, 0x300000, 20, 0);
        rsSetA_2868(ctx, 0xFF000, 12, 0x14);
    }
    if (col.a <= 0.0f) {
        return;
    }
    float size = 0.0f;
    switch ((unsigned int)(self->part->flags & 0x70)) {
    case 0x10:
        ctx->top->tex = rsTex1024_2868(ctx);
        size = 180.0f;
        break;
    case 0x20:
        ctx->top->tex = rsTex1028_2868(ctx);
        size = 100.0f;
        break;
    case 0x40:
        ctx->top->tex = rsTex1024_2868(ctx);
        size = 350.0f;
        break;
    }
    sPart_2868* p = self->part;
    ctx->Draw(sV4_2868(p->pos.x, p->pos.y, p->pos.z, 1.0f), sV2_2868(size, size), sV2_2868(), sV2_2868(1.0f, 1.0f), col, self->rot, 2);
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E2B00);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E2E18);
#ifdef SKIP_ASM
struct sBWVEntry2E18 {
    short delta;
    short index;
    void (*fn)(void*, void*, void*);
};

struct sWakePair2E18 {
    int a;
    int b;
};

struct sWakeMgr2E18 {
    char pad0[0x60];
    sWakePair2E18 pairs[1];     // 0x60
};

extern void* D_004886B0[];
extern char* D_004A5B80;
extern int D_004A3B18;
void* func_002E2860(void* self);
void* func_002E3110(void* self);
extern "C" void func_002F4380(void* self);

// PORT: hand-written g++ 2.95 member-array construction loops (vptr at 0x649C).
extern "C" void* func_002E2E18(void* self)
{
    *(void***)((char*)self + 0x649C) = D_004886B0;
    {
        char* b1 = (char*)self + 0x68;
        int i1 = 0;
        do {
            char* b2 = b1;
            int i2 = 1;
            do {
                char* b3 = b2;
                int i3 = 0xFF;
                do {
                    func_002E2860(b3);
                    b3 += 0x30;
                } while (--i3 != -1);
                b2 += 0x3000;
            } while (--i2 != -1);
            b1 += 0x6000;
        } while (--i1 != -1);
    }
    {
        char* b1 = (char*)self + 0x6070;
        int i1 = 0;
        do {
            char* b2 = b1;
            int i2 = 1;
            do {
                func_002F4380(b2);
                b2 += 0x210;
            } while (--i2 != -1);
            b1 += 0x420;
        } while (--i1 != -1);
    }
    *(int*)((char*)self + 0x6494) = 1;
    {
        int i;
        for (i = 0; i < 1; i++) {
            ((sWakeMgr2E18*)self)->pairs[i].a = 0;
            ((sWakeMgr2E18*)self)->pairs[i].b = 0;
        }
    }
    {
        char* obj = D_004A5B80;
        sBWVEntry2E18* e = &(*(sBWVEntry2E18**)(obj + 0x10D8))[117];
        e->fn(obj + e->delta, (void*)func_002E3110, self);
    }
    D_004A3B18 = 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E2F98__FPvi);
#ifdef SKIP_ASM
void func_002E2F98(void* self, int i)
{
    *(int*)((char*)self + (i << 2) + 0x60) = 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E2FA8);
#ifdef SKIP_ASM
struct sWakePoint {
    int a;
    int pad04;
    int c;
    short d;
    short e;
    char pad10[0x20];
};

struct sWakeFx {
    char pad00[0x60];
    int counts[10];
    sWakePoint points[1][256];
};

extern "C" void func_002E2FA8(sWakeFx* self, int v, int i)
{
    int n = self->counts[i];
    self->points[i][n].a = v;
    self->points[i][n].d = 0;
    self->points[i][n].e = 0;
    self->points[i][n].c = 0;
    self->counts[i]++;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E2FF8);
#ifdef SKIP_ASM
extern "C" void func_002E2FA8(sWakeFx* self, int v, int i);

extern "C" void func_002E2FF8(sWakeFx* self, int* vals, int count, int unused, int i)
{
    int n;
    for (n = 0; n < count; n++) {
        func_002E2FA8(self, vals[n], i);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E3060);
#ifdef SKIP_ASM
struct sBWVEntry2 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern void* D_004886B0[];
extern char* D_004A5B80;
extern int D_004A3B18;
void operator_delete(int* p);

extern "C" void func_002E3060(void* self, int flags)
{
    char* obj = D_004A5B80;
    *(void***)((char*)self + 0x649C) = D_004886B0;
    sBWVEntry2* e = &(*(sBWVEntry2**)(obj + 0x10D8))[117];
    e->fn(obj + e->delta, 0, 0);
    D_004A3B18 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E30D0);
#ifdef SKIP_ASM
extern "C" void func_002E3338(void* self, int i);
extern "C" void func_002E3478(void* self, int i);

extern "C" void func_002E30D0(void* self, int i)
{
    func_002E3338(self, i);
    func_002E3478(self, i);
}
#endif

extern "C" void* func_002E3130(void* self);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E3110__FPv);
#ifdef SKIP_ASM
void* func_002E3110(void* self)
{
    return func_002E3130(self);
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E3130);

INCLUDE_ASM("visualfx/boardwakefx", func_002E3338);

INCLUDE_ASM("visualfx/boardwakefx", func_002E3478);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E3578);
#ifdef SKIP_ASM
struct sWakeRState {
    int f0;
    unsigned a0 : 2;
    unsigned a2 : 5;
    unsigned a7 : 15;
    unsigned a22 : 1;
    unsigned a23 : 9;
    unsigned b0 : 5;
    unsigned b5 : 5;
    unsigned b10 : 19;
    unsigned b29 : 3;
    int fC;
    int f10;
};

struct sWakeRCtx {
    char pad[0xE84];
    sWakeRState* top;
};

extern char* D_004A5B80;
extern sWakeRState D_00501420;

static inline void setA22_3578(sWakeRCtx* c, int v) { c->top->a22 = v; }
static inline void setA0_3578(sWakeRCtx* c, int v) { c->top->a0 = v; }
static inline void setB10_3578(sWakeRCtx* c, int v) { c->top->b10 = v; }
static inline void setA2_3578(sWakeRCtx* c, int v) { c->top->a2 = v; }
static inline void setB5_3578(sWakeRCtx* c, int v) { c->top->b5 = v; }

extern "C" void func_002E3578(void)
{
    sWakeRCtx* ctx = (sWakeRCtx*)D_004A5B80;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *ctx->top = D_00501420;
    setA22_3578(ctx, 1);
    setA0_3578(ctx, 2);
    setB10_3578(ctx, 0);
    setA2_3578(ctx, 7);
    setB5_3578(ctx, 7);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E3668);
#ifdef SKIP_ASM
extern char* D_004A289C;

extern "C" void func_002E3668(void)
{
    *(char**)(D_004A289C + 0xE84) -= 0x14;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E3680);
#ifdef SKIP_ASM
// g++ 2.95 vtable entry (no thunks): {delta, index, fn}. Vtables are double-aligned.
struct sVtEnt3680 {
    short delta;
    short index;
    void* fn;
};

struct sVt9_3680 {
    sVtEnt3680 e[9];
} __attribute__((aligned(8)));

struct sVt22_3680 {
    sVtEnt3680 e[22];
} __attribute__((aligned(8)));

extern const sVt9_3680 D_004889C8;
extern const sVt22_3680 D_00488A10;
extern char D_00459B90[];

struct sWakeFade_3930;
extern "C" void cRider_cRider(void* self);
extern "C" void func_002E3930(sWakeFade_3930* self);

// PORT: hand-written form of g++ 2.95's constructor for a class with a virtual base
// (cRider at +0x40): vtable copies with delta fixups when not in charge.
extern "C" void* func_002E3680(void* self, int inChrg)
{
    sVt9_3680 t1;
    sVt22_3680 t2;
    if (inChrg) {
        *(void**)self = (char*)self + 0x40;
        cRider_cRider((char*)self + 0x40);
    }
    *(void**)(*(char**)self + 0x6E8) = (void*)&D_004889C8;
    *(void**)(*(char**)self + 0x6D0) = D_00459B90;
    *(void**)(*(char**)self + 0x6C0) = (void*)&D_00488A10;
    if (inChrg == 0) {
        int vc;
        t1 = D_004889C8;
        *(void**)(*(char**)self + 0x6E8) = &t1;
        {
            char* vbo = *(char**)self - 0x40;
            vc = (char*)self - vbo;
        }
        t1.e[1].delta = D_004889C8.e[1].delta + vc;
        t2 = D_00488A10;
        *(void**)(*(char**)self + 0x6C0) = &t2;
        t2.e[1].delta = D_00488A10.e[1].delta + vc;
    }
    func_002E3930((sWakeFade_3930*)self);
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E37D0);
#ifdef SKIP_ASM
class cVbDtor002E37D0 : virtual public cRiderVb_bwf {
public:
    char body[0x3C];
    virtual ~cVbDtor002E37D0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002E37D0::~cVbDtor002E37D0()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor002E37D0; expose it under the address-derived name.
__asm__(".globl func_002E37D0\n.type func_002E37D0,@function\nfunc_002E37D0 = _$_15cVbDtor002E37D0\n.size func_002E37D0,0x15C\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E3930);
#ifdef SKIP_ASM
struct sWakeVec4_3930 {
    float x;
    float y;
    float z;
    float w;
    sWakeVec4_3930() {}
    sWakeVec4_3930(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct sWakeFade_3930 {
    int f0;
    int f4;
    sWakeVec4_3930 a;
    sWakeVec4_3930 b;
    sWakeVec4_3930 c;
};

extern "C" void func_002E3930(sWakeFade_3930* self)
{
    self->a = sWakeVec4_3930(0.5f, 1.0f, 0.0f, 0.0f);
    self->b = sWakeVec4_3930(0.699999988079071f, 1.0f, 0.699999988079071f, 0.699999988079071f);
    self->c = self->a;
    self->f4 = 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E39D8);
#ifdef SKIP_ASM
extern "C" float func_0031C040(float x);
extern float D_004A55AC;

struct sWkVt39D8 { short delta; short index; int (*fn)(void*); };
struct sWkCol39D8 {
    char* rider;                // 0x0
    float phase;                // 0x4
    float a[4];                 // 0x8
    float b[4];                 // 0x18
    float out[4];               // 0x28
};

extern "C" void func_002E39D8(sWkCol39D8* self)
{
    char* o = self->rider + 0x6C0;
    sWkVt39D8* vt = *(sWkVt39D8**)o;
    if (vt[8].fn(o + vt[8].delta) == 0) return;
    float half = 0.5f;
    float p = self->phase + D_004A55AC * 0.01666666753590107f;
    float t = p * 0.15915493667125702f + half;
    float f;
    // PORT: FPU-only float->int->float round trip (floor helper); no C cast reproduces it.
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(f) : "f"(t));
    if (t < f) f -= 1.0f;
    float q = p - f * 6.2831854820251465f;
    self->phase = q;
    float s = func_0031C040(q) * half + half;
    float u = 1.0f - s;
    self->out[0] = s * self->a[0] + u * self->b[0];
    self->out[1] = s * self->a[1] + u * self->b[1];
    self->out[2] = s * self->a[2] + u * self->b[2];
    self->out[3] = s * self->a[3] + u * self->b[3];
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E3AF8);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4228);
#ifdef SKIP_ASM
extern "C" void* func_00354648(void* self, void* a1);
extern "C" void* func_00282CD0(void* self);
extern "C" void func_00283298(void* self);
extern "C" void func_002E4CB0(void);
extern void* D_00488100[];
extern void* D_00488158[];

extern "C" void* func_002E4228(void* self, void* a1, int a2)
{
    func_00354648(self, a1);
    func_00282CD0((char*)self + 0x10);
    *(int*)((char*)self + 0x74) = a2;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x68) = 0;
    *(int*)((char*)self + 0x70) = 0;
    *(int*)((char*)self + 0x78) = 0;
    *(int*)((char*)self + 0x7C) = 0;
    *(int*)((char*)self + 0x80) = 0;
    *(void***)((char*)self + 0x1C) = D_00488100;
    *(void***)((char*)self + 0xC) = D_00488158;
    *(int*)((char*)self + 0x6C) = -1;
    func_002E4CB0();
    func_00283298((char*)self + 0x10);
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E42D0);
#ifdef SKIP_ASM
struct sBWVEntry1 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

extern char* D_004A5B80;
extern "C" void func_002E4578(void* self);
extern "C" void func_002832D8(void* self);
extern "C" void func_00283228(void* self, int flags);
extern "C" void func_003546C8(void* self, int flags);

extern "C" void func_002E42D0(void* self, int flags)
{
    *(void***)((char*)self + 0x1C) = D_00488100;
    *(void***)((char*)self + 0xC) = D_00488158;
    char* m = (char*)self + 0x10;
    func_002E4578(self);
    if (*(int*)((char*)self + 0x7C) != 0) {
        char* obj = D_004A5B80;
        sBWVEntry1* e = &(*(sBWVEntry1**)(obj + 0x10D8))[60];
        e->fn(obj + e->delta, (char*)self + 0x68);
        *(int*)((char*)self + 0x7C) = 0;
    }
    func_002832D8(m);
    func_00283228(m, 0);
    func_003546C8(self, flags);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4370);
#ifdef SKIP_ASM
struct sBWVEntry4370 {
    short delta;
    short index;
    void (*fn)(void*, void*, int, int);
};

struct sBWVEntryI4370 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern char* D_004A5B80;
extern "C" void func_002E4578(void* self);

// PORT: later callers declare this as void (and an int alias); the body returns int.
extern "C" int func_002E4370_def(void* self, int a1, void* o1, void* o2, float f0, float f1, float f2, int a4, int a5) __asm__("func_002E4370");

extern "C" int func_002E4370_def(void* self, int a1, void* o1, void* o2, float f0, float f1, float f2, int a4, int a5)
{
    if (*(int*)((char*)self + 0x44) != 0) {
        func_002E4578(self);
    }
    *(int*)((char*)self + 0x78) = a1;
    *(int*)((char*)self + 0x70) = a5;
    if (a4 != 0) {
        if (*(int*)((char*)self + 0x7C) != 0) {
            *(int*)((char*)self + 0x7C) = 0;
        }
        char* ref = (char*)self + 0x68;
        if (~*(int*)((char*)self + 0x6C) == 0) {
            char* obj = D_004A5B80;
            sBWVEntry4370* e = &(*(sBWVEntry4370**)(obj + 0x10D8))[59];
            e->fn(obj + e->delta, ref, 0x100, 0x100);
            if (~*(int*)((char*)self + 0x6C) == 0) {
                if (o1 != 0) {
                    sBWVEntryI4370* vt = *(sBWVEntryI4370**)o1;
                    vt[1].fn((char*)o1 + vt[1].delta, 3);
                }
                if (o2 != 0) {
                    sBWVEntryI4370* vt = *(sBWVEntryI4370**)o2;
                    vt[1].fn((char*)o2 + vt[1].delta, 3);
                }
                return 0;
            }
        }
    }
    *(void**)((char*)self + 0x4C) = o1;
    *(void**)((char*)self + 0x50) = o2;
    *(float*)((char*)self + 0x54) = f0;
    *(float*)((char*)self + 0x58) = f1;
    *(float*)((char*)self + 0x5C) = f2;
    *(int*)((char*)self + 0x44) = 1;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x60) = a4;
    if (a4 != 0) {
        *(int*)((char*)self + 0x64) = 1;
    }
    return 1;
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E44C8);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E44F0);
#ifdef SKIP_ASM
// PORT: the unit declares func_002E4370 as void; this caller returns its int result.
extern "C" int func_002E4370_i(void* self, int a1, int a2, int a3, float f0, float f1, int a4, int a5, float f2) __asm__("func_002E4370");

extern "C" int func_002E44F0(void* self, int a1, int a2, float f)
{
    if (*(int*)((char*)self + 0x44) == 0) {
        return func_002E4370_i(self, a1, 0, a2, 0.0f, 0.0f, 0, 0, f);
    }
    *(int*)((char*)self + 0x50) = a2;
    *(float*)((char*)self + 0x5C) = f;
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E4540);
#ifdef SKIP_ASM
extern "C" void func_002E4370(void* self, int a1, int a2, int a3, float f0, float f1, int a4, int a5, float f2);

extern "C" void func_002E4540(void* self, int a1, int a3, int a5, float f2)
{
    func_002E4370(self, a1, 0, a3, 0.0f, 0.0f, 1, a5, f2);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4578);
#ifdef SKIP_ASM
struct sBWVEntryI_4578 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sBWVEntryR_4578 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern char* D_004A5B80;

extern "C" void func_002E4578(void* self)
{
    if (*(int*)((char*)self + 0x44) != 0) {
        *(int*)((char*)self + 0x44) = 0;
        *(int*)((char*)self + 0x40) = 0;
        char* o = *(char**)((char*)self + 0x4C);
        if (o != 0) {
            sBWVEntryI_4578* e = &(*(sBWVEntryI_4578**)o)[1];
            e->fn(o + e->delta, 3);
        }
        *(char**)((char*)self + 0x4C) = 0;
        o = *(char**)((char*)self + 0x50);
        if (o != 0) {
            sBWVEntryI_4578* e = &(*(sBWVEntryI_4578**)o)[1];
            e->fn(o + e->delta, 3);
        }
        *(char**)((char*)self + 0x50) = 0;
        *(int*)((char*)self + 0x70) = 0;
        if (~*(int*)((char*)self + 0x6C) != 0) {
            char* obj = D_004A5B80;
            *(int*)((char*)self + 0x7C) = 1;
            sBWVEntryR_4578* e = &(*(sBWVEntryR_4578**)(obj + 0x10D8))[0x72];
            *(int*)((char*)self + 0x80) = e->fn(obj + e->delta);
            *(int*)((char*)self + 0x64) = 0;
            *(int*)((char*)self + 0x60) = 0;
        }
        *(int*)((char*)self + 0x78) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4638);
#ifdef SKIP_ASM
extern "C" void func_002E4638(void* self, int up)
{
    if (*(int*)((char*)self + 0x44) == 0) {
        *(int*)((char*)self + 0x40) = 0;
        return;
    }
    if (up) {
        *(int*)((char*)self + 0x40) += 1;
        return;
    }
    if (*(int*)((char*)self + 0x40) != 0) {
        *(int*)((char*)self + 0x40) -= 1;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4678);
#ifdef SKIP_ASM
extern "C" float func_002E4678(void* self)
{
    if (*(int*)((char*)self + 0x44) == 0) {
        return 0.0f;
    }
    float v = *(float*)((char*)self + 0x54) + *(float*)((char*)self + 0x58)
            + *(float*)((char*)self + 0x5C) - *(float*)((char*)self + 0x48);
    if (v < 0.0f) {
        return 0.0f;
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E46C8);
#ifdef SKIP_ASM
extern char* D_004A5B80;
extern char* D_004A5B64;

struct sWkVtA46C8 { short delta; short index; int (*fn)(void*); };
struct sWkVtB46C8 { short delta; short index; void (*fn)(void*, void*); };

extern "C" void func_002E46C8(char* self)
{
    char* ctx = D_004A5B80;
    if (*(int*)(self + 0x7C) != 0) {
        sWkVtA46C8* vt = *(sWkVtA46C8**)(ctx + 0x10D8);
        if (vt[114].fn(ctx + vt[114].delta) - *(int*)(self + 0x80) >= 3) {
            sWkVtB46C8* vt2 = *(sWkVtB46C8**)(ctx + 0x10D8);
            vt2[60].fn(ctx + vt2[60].delta, self + 0x68);
            *(int*)(self + 0x7C) = 0;
        }
    }
    if (*(int*)(self + 0x44) == 0) return;
    if (*(int*)(self + 0x40) != 0) return;
    if (*(int*)(self + 0x18) > 0) {
        *(float*)(self + 0x48) = *(float*)(self + 0x3C);
    } else if (*(float**)(self + 0x70) != 0) {
        *(float*)(self + 0x48) = **(float**)(self + 0x70) * (*(float*)(self + 0x54) + *(float*)(self + 0x58) + *(float*)(self + 0x5C));
    } else {
        *(float*)(self + 0x48) += 1.0f / (float)*(int*)(D_004A5B64 + 0x10);
    }
    if (*(float*)(self + 0x54) + *(float*)(self + 0x58) + *(float*)(self + 0x5C) <= *(float*)(self + 0x48)) {
        func_002E4578(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E47E8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern char* D_004A5B80;
extern "C" void func_002EB8F0(void);
// PORT: cWorldPainterMan_reset is defined with an unused self param; this caller passes none.
void cWorldPainterMan_reset_47E8() __asm__("cWorldPainterMan_reset__FPv");

struct sRsState47E8 {
    int f0;                     // 0x0
    int flagsA;                 // 0x4
    int flagsB;                 // 0x8
    int fC;                     // 0xC
    short tex;                  // 0x10
    short pad;
};

struct sRsVt47E8 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sRsVtP47E8 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sRsVtV47E8 {
    short delta;
    short index;
    void (*fn)(void*, int, int, float, float, float, float, float, float);
};

struct sRsCtx47E8 {
    char pad0[0xE84];
    sRsState47E8* top;          // 0xE84
    char pad1[0x10D8 - 0xE88];
    sRsVt47E8* vtable;          // 0x10D8
};

struct sFadeVt47E8 {
    short delta;
    short index;
    void (*fn)(void*, float);
};

struct sFade47E8 {
    char pad0[0x44];
    int active;                 // 0x44
    float time;                 // 0x48
    char* o1;                   // 0x4C
    char* o2;                   // 0x50
    float fadeIn;               // 0x54
    float hold;                 // 0x58
    float fadeOut;              // 0x5C
    int useTex;                 // 0x60
    int pending;                // 0x64
    int ref;                    // 0x68
    int tex;                    // 0x6C
    int i70;                    // 0x70
    int rider;                  // 0x74
};

static inline void rsSetA47E8(sRsCtx47E8* ctx, int mask, int shift, int v)
{
    ctx->top->flagsA = (ctx->top->flagsA & ~mask) | ((v << shift) & mask);
}

static inline void rsSetB47E8(sRsCtx47E8* ctx, int mask, int shift, int v)
{
    ctx->top->flagsB = (ctx->top->flagsB & ~mask) | ((v << shift) & mask);
}

static inline void rsSet047E8(sRsCtx47E8* ctx, int mask, int shift, int v)
{
    ctx->top->f0 = (ctx->top->f0 & ~mask) | ((v << shift) & mask);
}

static inline int fadeTex47E8(sFade47E8* self)
{
    return self->tex;
}

extern "C" void func_002E47E8(sFade47E8* self)
{
    if (self->rider != *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84) + 0x14)) {
        return;
    }
    func_002EB8F0();
    sRsCtx47E8* ctx = (sRsCtx47E8*)D_004A5B80;
    if (self->active == 0) {
        return;
    }
    float t = self->time;
    if (self->pending != 0 && self->fadeIn + self->hold <= t) {
        sRsVtP47E8* vt = (sRsVtP47E8*)ctx->vtable;
        vt[61].fn((char*)ctx + vt[61].delta, &self->ref);
        self->pending = 0;
    }
    char* o;
    float a;
    if (self->o1 == 0) {
        a = 1.0f - (t - self->hold) / self->fadeOut;
        o = self->o2;
    } else if (t < self->fadeIn || self->o2 == 0) {
        a = t / self->fadeIn;
        o = self->o1;
    } else if (t < self->fadeIn + self->hold) {
        a = 1.0f;
        o = self->o1;
    } else {
        a = 1.0f - (t - (self->fadeIn + self->hold)) / self->fadeOut;
        o = self->o2;
    }
    float c = wakeClampE058(a, 0.0f, 1.0f);
    if (c >= 0.93f) {
        cWorldPainterMan_reset_47E8();
    }
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    ctx->vtable[21].fn((char*)ctx + ctx->vtable[21].delta);
    ctx->vtable[31].fn((char*)ctx + ctx->vtable[31].delta);
    ctx->vtable[37].fn((char*)ctx + ctx->vtable[37].delta);
    sRsVtV47E8* vv = (sRsVtV47E8*)ctx->vtable;
    vv[26].fn((char*)ctx + vv[26].delta, 0, 0, 0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    rsSetB47E8(ctx, 0x3E0, 5, 8);
    rsSetA47E8(ctx, 0x400000, 22, 1);
    rsSetA47E8(ctx, 0x1800000, 23, 2);
    rsSetA47E8(ctx, 0x300000, 20, 0);
    rsSetA47E8(ctx, 0xFF000, 12, 0x14);
    rsSetA47E8(ctx, 0x7C, 2, 5);
    rsSet047E8(ctx, 0xC, 2, 3);
    rsSetA47E8(ctx, 0x3, 0, 2);
    rsSetB47E8(ctx, 0x1FFFFC00, 10, 0);
    if (self->useTex != 0) {
        ctx->top->tex = fadeTex47E8(self);
    } else {
        ctx->top->tex = -1;
    }
    if (self->useTex == 0 || self->pending == 0) {
        sFadeVt47E8* ov = *(sFadeVt47E8**)o;
        ov[2].fn(o + ov[2].delta, c);
    }
    ctx->vtable[32].fn((char*)ctx + ctx->vtable[32].delta);
    ctx->vtable[22].fn((char*)ctx + ctx->vtable[22].delta);
    ctx->top--;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E4B98);
#ifdef SKIP_ASM
struct sWakeParams_4B98 {
    int mode;
    float a;
    float b;
    float c;
    int id;
    float level;
};

void func_00283430(void* self);
extern "C" int func_0027A4A0(void* tbl, int mode, int id);
extern "C" void func_002E4370(void* self, int a1, int a2, int a3, float f0, float f1, int a4, int a5, float f2);
extern "C" void func_002E4540(void* self, int a1, int a3, int a5, float f2);
extern void* D_004A28A4;

extern "C" void func_002E4B98(void* self)
{
    sWakeParams_4B98* p = (sWakeParams_4B98*)((char*)self + 0x28);
    func_00283430((char*)self + 0x10);
    if (*(int*)((char*)self + 0x28) != 7) {
        int r1 = func_0027A4A0(D_004A28A4, *(int*)((char*)self + 0x28), *(int*)((char*)self + 0x38));
        int r2 = func_0027A4A0(D_004A28A4, *(int*)((char*)self + 0x28), *(int*)((char*)self + 0x38));
        func_002E4370(self, 2, r1, r2, *(float*)((char*)self + 0x34), *(float*)((char*)self + 0x30), 0, 0, *(float*)((char*)self + 0x2C));
    } else {
        func_002E4540(self, 2, func_0027A4A0(D_004A28A4, 7, *(int*)((char*)self + 0x38)), 0, *(float*)((char*)self + 0x34));
    }
    *(float*)((char*)self + 0x48) = p->level;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4C60);
#ifdef SKIP_ASM
void func_00283440(void*);
extern "C" void func_002E4578(void* self);

extern "C" void func_002E4C60(void* self)
{
    func_00283440((char*)self + 0x10);
    func_002E4578(self);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4C90);
#ifdef SKIP_ASM
extern "C" int func_002E4C90(void* self)
{
    int r = 0;
    if (*(int*)((char*)self + 0x60) != 0) {
        r = *(int*)((char*)self + 0x64) != 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4CB0);
#ifdef SKIP_ASM
extern int D_00538850[];

extern "C" void func_002E4CB0(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        D_00538850[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4CE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sWakePoolEntry {
    char data[0x64];
};

extern int D_00538850[];
// same object as the unit's later `extern sWakeSlot D_005382C0[]` (0x64-byte slots)
extern sWakePoolEntry D_wakePool[] __asm__("D_005382C0");
extern sWakePoolEntry* D_004A3B1C;

extern "C" sWakePoolEntry* func_002E4CE8(void)
{
    for (int i = 0; i < 4; i++) {
        if (D_00538850[i] == 0) {
            D_00538850[i] = 1;
            return &D_wakePool[i];
        }
    }
    return D_004A3B1C;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4D30);
#ifdef SKIP_ASM
struct sWakeSlot {
    char pad[0x64];
};

extern sWakeSlot D_005382C0[];
extern int D_00538850[];

extern "C" void func_002E4D30(void* p)
{
    int i;
    if (p == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (&D_005382C0[i] == p) {
            D_00538850[i] = 0;
            return;
        }
    }
}
#endif

extern void* D_004880E0[];

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4D70__FPv);
#ifdef SKIP_ASM
void* func_002E4D70(void* self)
{
    *(int*)self = (int)(void*)D_004880E0;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4D88);
#ifdef SKIP_ASM
struct sVec4D88 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMatD88 {
    sVec4D88 r[4];
};

extern char D_004FF1A0[];
int BXrand();

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void wakeCopyMatD88(sMatD88* dst, const sMatD88* src)
{
    __asm__ __volatile__(
        "lqc2       $vf1, 0x0(%1)\n"
        "lqc2       $vf2, 0x10(%1)\n"
        "lqc2       $vf3, 0x20(%1)\n"
        "lqc2       $vf4, 0x30(%1)\n"
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf2, 0x10(%0)\n"
        "sqc2       $vf3, 0x20(%0)\n"
        "sqc2       $vf4, 0x30(%0)\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (scale matrix rows by the components of s).
static inline void wakeScaleMatD88(sMatD88* dst, const sMatD88* src, const sVec4D88& s)
{
    __asm__ __volatile__(
        "lqc2       $vf1, %2\n"
        "lqc2       $vf4, 0x0(%1)\n"
        "lqc2       $vf5, 0x10(%1)\n"
        "lqc2       $vf6, 0x20(%1)\n"
        "lqc2       $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2       $vf8, 0x0(%0)\n"
        "sqc2       $vf9, 0x10(%0)\n"
        "sqc2       $vf10, 0x20(%0)\n"
        "sqc2       $vf11, 0x30(%0)\n"
        :
        : "r"(dst), "r"(src), "m"(s)
        : "memory");
}

extern "C" void* func_002E4D88(char* self, int a1, int a2, float f0, float f1, float f2, float f3)
{
    *(int*)(self + 0x8) = 0;
    *(int*)(self + 0x10) = 0;
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 0x24) = 0;
    *(int*)(self + 0x28) = 0;
    *(float*)(self + 0x2C) = 1.0f;
    *(int*)(self + 0x30) = 0;
    *(int*)(self + 0x34) = 0;
    *(int*)(self + 0x38) = 0;
    *(int*)(self + 0x3C) = 0;
    *(int*)(self + 0x40) = 0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x90) = 0;
    *(int*)(self + 0x94) = 0;
    *(float*)(self + 0xA4) = 1.0f;
    *(float*)(self + 0xA8) = 1.0f;
    *(float*)(self + 0xAC) = 1.0f;
    *(int*)(self + 0x0) = a1;
    *(int*)(self + 0x4) = a2;
    *(float*)(self + 0xC) = f0;
    *(float*)(self + 0x14) = f1;
    *(float*)(self + 0x18) = f2;
    *(float*)(self + 0x1C) = f3;
    *(int*)(self + 0xB0) = 1;
    *(int*)(self + 0x98) = BXrand();
    *(int*)(self + 0x9C) = BXrand();
    *(int*)(self + 0xA0) = BXrand();
    wakeCopyMatD88((sMatD88*)(self + 0x50), (sMatD88*)D_004FF1A0);
    {
        sMatD88 t2;
        sVec4D88 s;
        sMatD88 tmp;
        s.x = *(float*)(self + 0xC);
        s.y = *(float*)(self + 0xC);
        s.z = *(float*)(self + 0xC);
        s.w = 1.0f;
        wakeScaleMatD88(&tmp, (sMatD88*)(self + 0x50), s);
        wakeCopyMatD88(&t2, &tmp);
        wakeCopyMatD88((sMatD88*)(self + 0x50), &t2);
    }
    {
        sVec4D88 p;
        p.x = 0.0f;
        p.y = 0.0f;
        p.z = 0.0f;
        p.w = 1.0f;
        *(sVec4D88*)(self + 0x20) = p;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4F10__FPv);
#ifdef SKIP_ASM
void func_002E4F10(void* self)
{
    *(int*)((char*)self + 0x94) = 0;
    *(int*)((char*)self + 0xb0) = 1;
    *(int*)((char*)self + 0x90) = 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E4F28);
#ifdef SKIP_ASM
void operator_delete(int* p);

extern "C" void func_002E4F28(int* self, int flags)
{
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E4F50);

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E5430);
#ifdef SKIP_ASM
struct sWakeVec5430 {
    float x, y, z, w;
    sWakeVec5430() {}
    sWakeVec5430(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sWakeGrid5430 {
    char pad_0x0[0xC];
    float size;                 // 0xC
    char pad_0x10[0x10];
    sWakeVec5430 pos;           // 0x20
};

// PORT: PS2-only VU0 inline asm (a -= b).
static inline void wakeSub5430(sWakeVec5430& a, const sWakeVec5430& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

static inline void wakeWrap5430(float& r, float v, float s)
{
    if (v > s * 0.5f) {
        float q = v / s;
        r = (q - (float)(int)q) * s - s;
    } else if (v < -(s * 0.5f)) {
        float q = v / s;
        r = (q - (float)(int)q) * s + s;
    }
}

extern "C" void func_002E5430(sWakeGrid5430* self, sWakeVec5430* d)
{
    wakeSub5430(self->pos, *d);
    float x = self->pos.x;
    float y = self->pos.y;
    float z = self->pos.z;
    float px = x;
    float py = y;
    float pz = z;
    wakeWrap5430(x, px, self->size);
    wakeWrap5430(y, py, self->size);
    wakeWrap5430(z, pz, self->size);
    self->pos = sWakeVec5430(x, y, z, 1.0f);
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E55D8);
#ifdef SKIP_ASM
struct sMat_6008;
extern char* D_004A289C;

struct sVec55D8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat55D8 {
    sVec55D8 v[4];
    sMat55D8() {}
    // PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
    sMat55D8(const sMat55D8& o)
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
            : "r"(this), "r"(&o)
            : "memory");
    }
    // PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
    sMat55D8& operator=(const sMat55D8& o)
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
            : "r"(this), "r"(&o)
            : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct sCellInfo55D8 {
    sVec55D8 pos;               // 0x00
    sVec55D8 col;               // 0x10
    int i20;                    // 0x20
    int i24;                    // 0x24
    int i28;                    // 0x28
    int i2C;                    // 0x2C
    sVec55D8 lo;                // 0x30
    sVec55D8 hi;                // 0x40
    sMat55D8 mat;               // 0x50
};

struct sCell55D8 {
    int i0;                     // 0x00
    int type;                   // 0x04
    int active;                 // 0x08
    float size;                 // 0x0C
    char pad10[0x4];            // 0x10
    float f14;                  // 0x14
    float f18;                  // 0x18
    char pad1C[0x4];            // 0x1C
    sVec55D8 pos;               // 0x20
    char pad30[0x20];           // 0x30
    sMat55D8 mat;               // 0x50
    char pad90[0x8];            // 0x90
    int i98;                    // 0x98
    int i9C;                    // 0x9C
    int iA0;                    // 0xA0
    float colR;                 // 0xA4
    float colG;                 // 0xA8
    float colB;                 // 0xAC
};

struct sVt55D8 {
    short delta;
    short index;
    void (*fn)(void*, sCellInfo55D8*);
};

// PORT: 128-bit TImode quadword (the PC port needs a 16-byte struct).
typedef int cQuad55D8 __attribute__((mode(TI)));
extern cQuad55D8 D_004FF140;
extern cQuad55D8 D_004FF150;
extern cQuad55D8 D_004FF160;

// PORT: PS2-only VU0 inline asm (4x4 matrix * matrix).
static inline sMat55D8 wakeMulMat55D8(const sMat55D8& a, const sMat55D8& b)
{
    sMat55D8 r;
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
        : "r"(&r), "r"(&a), "r"(&b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v / s).
static inline sVec55D8 wakeDiv55D8(const sVec55D8& v, float s)
{
    sVec55D8 r;
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

// PORT: PS2-only VU0 inline asm (a += b).
static inline void wakeAddEq55D8(sVec55D8& a, const cQuad55D8& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (a -= b).
static inline void wakeSubEq55D8(sVec55D8& a, const cQuad55D8& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (a -= b).
static inline void wakeSubV55D8(sVec55D8& a, const sVec55D8& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

extern "C" void func_002E55D8(int* p, sMat_6008* m, float x, float y, float z)
{
    sCell55D8* self = (sCell55D8*)p;
    if (self->active == 0) {
        return;
    }
    float x1 = x + 1.0f;
    float y1 = y + 1.0f;
    float z1 = z + 1.0f;
    sCellInfo55D8 info;
    info.mat = wakeMulMat55D8(*(sMat55D8*)m, self->mat);
    sVec55D8 v = wakeDiv55D8(self->pos, self->size);
    info.pos = v;
    float r = self->colR * 128.0f;
    float g = self->colG * 128.0f;
    float b = self->colB * 128.0f;
    float a = self->f18 * 128.0f;
    v.y = g;
    info.i20 = self->active;
    info.i24 = self->i98;
    info.i28 = self->i9C;
    info.i2C = self->iA0;
    info.lo.w = self->f14;
    info.hi.w = self->size;
    v.x = r;
    v.z = b;
    info.lo.x = x;
    info.lo.y = y;
    info.lo.z = z;
    info.hi.x = x1;
    info.hi.y = y1;
    info.hi.z = z1;
    v.w = a;
    info.col = v;
    if (info.pos.x < x + -0.5f) {
        wakeAddEq55D8(info.pos, D_004FF140);
    }
    if (x1 + 0.5f < info.pos.x) {
        wakeSubEq55D8(info.pos, D_004FF140);
    }
    if (info.pos.y < y + -0.5f) {
        wakeAddEq55D8(info.pos, D_004FF150);
    }
    if (y1 + 0.5f < info.pos.y) {
        wakeSubEq55D8(info.pos, D_004FF150);
    }
    if (info.pos.z < z + -0.5f) {
        wakeAddEq55D8(info.pos, D_004FF160);
    }
    if (z1 + 0.5f < info.pos.z) {
        wakeSubEq55D8(info.pos, D_004FF160);
    }
    v.x = 1.5f;
    v.y = 1.5f;
    v.z = 1.5f;
    v.w = 0.0f;
    wakeSubV55D8(info.pos, v);
    switch (self->type) {
    case 0: {
        sVt55D8* vt = *(sVt55D8**)(D_004A289C + 0x10D8);
        vt[85].fn(D_004A289C + vt[85].delta, &info);
        break;
    }
    case 1: {
        sVt55D8* vt = *(sVt55D8**)(D_004A289C + 0x10D8);
        vt[86].fn(D_004A289C + vt[86].delta, &info);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E5920);
#ifdef SKIP_ASM
extern void* D_00487FD8[];
extern "C" void func_00319CC8(void);
extern void* D_004A28A8;
extern char D_004A3B20[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sVec5920 {
    float x, y, z, w;
    sVec5920() {}
    sVec5920(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    void* operator new[](unsigned int, void* p) { return p; }
} __attribute__((aligned(16)));

struct sWake5920 {
    char pad0[0xC];             // 0x00
    void** vtbl;                // 0x0C
    void* fx[12];               // 0x10
    sVec5920 v[2];              // 0x40
};

extern "C" void* func_002E5920(sWake5920* self, void* a1)
{
    func_00354648(self, a1);
    self->vtbl = D_00487FD8;
    new (self->v) sVec5920[2];
    func_00319CC8();
    for (int i = 11; i >= 0; i--) {
        self->fx[i] = 0;
    }
    for (int j = 0; j < 2; j++) {
        self->v[j] = sVec5920(0.0f, 0.0f, 0.0f, 1.0f);
    }
    self->fx[0] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 0, 0, 1500.0f, 3.0f, 1.0f, -200.0f);
    self->fx[1] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 0, 0, 1500.0f, 3.0f, 1.0f, -200.0f);
    self->fx[2] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 0, 0, 2000.0f, 3.0f, 1.0f, -200.0f);
    self->fx[3] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 0, 0, 3000.0f, 3.0f, 1.0f, -200.0f);
    self->fx[4] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 0, 1, 2000.0f, 600.0f, 0.05999999865889549f, -100.0f);
    self->fx[5] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 0, 1, 2000.0f, 600.0f, 0.05999999865889549f, -100.0f);
    if (*(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x7C) >= 2) {
        self->fx[6] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 1, 0, 1500.0f, 3.0f, 1.0f, -200.0f);
        self->fx[7] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 1, 0, 1500.0f, 3.0f, 1.0f, -200.0f);
        self->fx[8] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 1, 0, 2000.0f, 3.0f, 1.0f, -200.0f);
        self->fx[9] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 1, 0, 3000.0f, 3.0f, 1.0f, -200.0f);
        self->fx[10] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 1, 1, 2000.0f, 600.0f, 0.05999999865889549f, -100.0f);
        self->fx[11] = func_002E4D88((char*)cMemMan_alloc(0xC0, D_004A3B20, 0, 0), 1, 1, 2000.0f, 600.0f, 0.05999999865889549f, -100.0f);
    }
    func_00319CC8();
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E5D18);
#ifdef SKIP_ASM
extern void* D_00487FD8[];
extern "C" void func_00319CC8(void);
extern "C" void func_002E4F28(int* self, int flags);
extern "C" void func_003546C8(void* self, int flags);

extern "C" void func_002E5D18(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_00487FD8;
    func_00319CC8();
    int i;
    for (i = 0; i < 12; i++) {
        int* p = ((int**)((char*)self + 0x10))[i];
        if (p != 0) {
            func_002E4F28(p, 3);
        }
    }
    func_00319CC8();
    func_003546C8(self, flags);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E5DA0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A473C;
extern float D_004A4740;
extern float D_004A4744;
extern float D_004A4748;
extern float D_004A474C;
extern float D_004A4750;
extern float D_004A4754;
extern float D_004A4758;
extern float D_004A475C;
struct sWakeV4_5DA0 { float x, y, z, w; };
extern sWakeV4_5DA0 D_005059B8;
extern sWakeV4_5DA0 D_005059C8;
extern "C" float func_002EE448(int i);
extern "C" float func_002EE508(int i);
extern "C" float func_002EE600(int i);
extern "C" float func_002EE660(int i);
extern "C" float func_002EE4C0(int i);
extern "C" float func_002EE570(int i);
extern "C" float func_002EE5B8(int i);
extern "C" float func_002EE6A8(int i);
extern "C" float func_002EE780(int i);
extern "C" float cRenderStateMan_SnowFlakeColourR(int i);
extern "C" float cRenderStateMan_SnowFlakeColourG(int i);
extern "C" float cRenderStateMan_SnowFlakeColourB(int i);
extern "C" float func_002EE8A0(int i);
extern "C" float func_002EE8E8(int i);
extern "C" float func_002EE930(int i);
extern "C" float func_002EE978(int i);
void* func_002306A8(void* self, int i);
extern "C" void func_002F4330(void* obj, float v);

struct sWakeRec_5DA0 {
    float f[8];
    sWakeV4_5DA0 c0;
    sWakeV4_5DA0 c1;
};
extern "C" void func_002E4F50(int* elem, sWakeRec_5DA0* rec);

extern "C" void func_002E5DA0(void* self)
{
    sWakeRec_5DA0 recs[2];
    unsigned int i;
    for (i = 0; i < *(unsigned int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84) + 0x10); i++) {
        if (D_004A473C != 0) {
            recs[i].f[0] = D_004A4740;
            recs[i].f[1] = D_004A4744;
            recs[i].f[2] = D_004A4758;
            recs[i].f[3] = D_004A475C;
            recs[i].f[4] = D_004A4748;
            recs[i].f[5] = D_004A474C;
            recs[i].f[6] = D_004A4750;
            recs[i].f[7] = D_004A4754;
            const sWakeV4_5DA0* a = &D_005059B8; recs[i].c0.x = a->x; recs[i].c0.y = a->y; recs[i].c0.z = a->z; recs[i].c0.w = a->w;
            const sWakeV4_5DA0* b = &D_005059C8; recs[i].c1.x = b->x; recs[i].c1.y = b->y; recs[i].c1.z = b->z; recs[i].c1.w = b->w;
        } else {
            int k = (i == 0) ? 6 : 7;
            recs[i].f[0] = func_002EE448(k);
            recs[i].f[1] = func_002EE508(k);
            recs[i].f[2] = func_002EE600(k);
            recs[i].f[3] = func_002EE660(k);
            recs[i].f[4] = func_002EE4C0(k);
            recs[i].f[5] = func_002EE570(k);
            recs[i].f[6] = func_002EE5B8(k);
            recs[i].f[7] = func_002EE6A8(k);
            recs[i].c0.x = func_002EE780(k);
            recs[i].c0.y = cRenderStateMan_SnowFlakeColourR(k);
            recs[i].c0.z = cRenderStateMan_SnowFlakeColourG(k);
            recs[i].c0.w = cRenderStateMan_SnowFlakeColourB(k);
            recs[i].c1.x = func_002EE8A0(k);
            recs[i].c1.y = func_002EE8E8(k);
            recs[i].c1.z = func_002EE930(k);
            recs[i].c1.w = func_002EE978(k);
        }
        func_002F4330(func_002306A8(*(void**)((char*)D_004A28A8 + 0x84), i), recs[i].f[0]);
    }
    int j;
    for (j = 0; j < 12; j++) {
        int* p = ((int**)((char*)self + 0x10))[j];
        if (p != 0) {
            func_002E4F50(p, &recs[*p]);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E6008);
#ifdef SKIP_ASM
struct sV4_6008 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat_6008 {
    sV4_6008 v[4];
    // PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
    sMat_6008& operator=(const sMat_6008& o)
    {
        __asm__ __volatile__(
            ".set noreorder\n"
            "lqc2      $vf1, 0x0(%1)\n"
            "lqc2      $vf2, 0x10(%1)\n"
            "lqc2      $vf3, 0x20(%1)\n"
            "lqc2      $vf4, 0x30(%1)\n"
            "sqc2      $vf1, 0x0(%0)\n"
            "sqc2      $vf2, 0x10(%0)\n"
            "sqc2      $vf3, 0x20(%0)\n"
            "sqc2      $vf4, 0x30(%0)\n"
            ".set reorder\n"
            :
            : "r"(this), "r"(&o)
            : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct sRsState_6008 {
    int f0;                 // 0x0
    int flagsA;             // 0x4
    int flagsB;             // 0x8
    int fC;                 // 0xC
    short tex;              // 0x10
    short pad;
};

struct sRsVEnt_6008 {
    short delta;
    short index;
    sMat_6008* (*fn)(void*);
};

struct sRsCtx_6008 {
    char pad0[0xE84];
    sRsState_6008* top;         // 0xE84
    char pad1[0xF70 - 0xE88];
    int texF70;                 // 0xF70
    char pad2[0x10D8 - 0xF74];
    sRsVEnt_6008* vtable;       // 0x10D8
};

struct sRiders_6008 {
    int f0;
    char* riders[4];            // 0x4
    int cur;                    // 0x14
};

struct sWakeFx_6008 {
    char pad0[0x10];
    int* parts[12];             // 0x10
    sWakeVec5430 last[4];       // 0x40
};

extern int D_004A4524;
extern int D_004A4760[1];
extern void* D_004A28A8;
extern sRsCtx_6008* D_004A5B80_6008 __asm__("D_004A5B80");
extern sRsState_6008 D_00501420_6008[] __asm__("D_00501420");
extern sV4_6008 D_004FF130;
extern "C" void func_002E55D8(int* p, sMat_6008* m, float r, float g, float b);

static inline sRiders_6008* riders_6008()
{
    return *(sRiders_6008**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84);
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sWakeVec5430 sub_6008(const sWakeVec5430& a, const sWakeVec5430& b)
{
    sWakeVec5430 r;
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

static inline int rsTexF70_6008(sRsCtx_6008* ctx)
{
    return ctx->texF70;
}

static inline void rsSetA_6008(sRsCtx_6008* ctx, int mask, int shift, int v)
{
    ctx->top->flagsA = (ctx->top->flagsA & ~mask) | ((v << shift) & mask);
}

static inline void rsSetB_6008(sRsCtx_6008* ctx, int mask, int shift, int v)
{
    ctx->top->flagsB = (ctx->top->flagsB & ~mask) | ((v << shift) & mask);
}

extern "C" void func_002E6008(sWakeFx_6008* self)
{
    if (D_004A4524 != 0) {
        return;
    }
    sRiders_6008* rs = riders_6008();
    int k = rs->cur;
    sWakeVec5430 a = *(sWakeVec5430*)(rs->riders[k] + 0x20);
    sWakeVec5430 d = sub_6008(a, self->last[k]);
    self->last[k] = a;
    sRsCtx_6008* ctx = D_004A5B80_6008;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *ctx->top = D_00501420_6008[0];
    rsSetA_6008(ctx, 0x400000, 22, 1);
    rsSetB_6008(ctx, 0x3E0, 5, 7);
    if (D_004A4760[0] != 0) {
        rsSetA_6008(ctx, 0x7C, 2, 7);
    } else {
        rsSetA_6008(ctx, 0x7C, 2, 5);
    }
    rsSetA_6008(ctx, 0x3, 0, 2);
    rsSetB_6008(ctx, 0x1FFFFC00, 10, 0);
    ctx->top->tex = rsTexF70_6008(ctx);
    sMat_6008 m;
    m = *ctx->vtable[35].fn((char*)ctx + ctx->vtable[35].delta);
    m.v[3] = D_004FF130;
    sRiders_6008* rs2 = riders_6008();
    sWakeVec5430 c = *(sWakeVec5430*)(rs2->riders[rs2->cur] + 0x80);
    float r = c.x * 0.6f + -0.5f;
    float g = c.y * 0.6f + -0.5f;
    float b = c.z * 0.6f + -0.5f;
    int i;
    for (i = 0; i < 12; i++) {
        int* p = self->parts[i];
        if (p != 0 && *p == k) {
            func_002E5430((sWakeGrid5430*)p, &d);
            func_002E55D8(self->parts[i], &m, r, g, b);
        }
    }
    ctx->top--;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/boardwakefx", func_002E62C8);
#ifdef SKIP_ASM
void func_002E4F10(void*);

extern "C" void func_002E62C8(void* self)
{
    int i;
    void** p = (void**)((char*)self + 0x10);
    for (i = 0; i < 12; i++) {
        if (p[i] != 0) {
            func_002E4F10(p[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E6320);
#ifdef SKIP_ASM
extern const sVt9_3680 D_00488550;
extern const sVt22_3680 D_00488598;
extern char D_00487B08[];
extern "C" void func_002E6640(void* self);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
inline void* operator new[](unsigned int, void* p) { return p; }

struct sWakeSeg_6320 {
    char data[0x1C];
    sWakeSeg_6320() {}
};

struct sWakePt_6320 {
    char data[0x20];
    sWakePt_6320() {}
};

// PORT: hand-written form of g++ 2.95's constructor for a class with a virtual base
// (cRider at +0x3B0): vtable copies with delta fixups when not in charge.
extern "C" void* func_002E6320(void* self, int inChrg)
{
    sVt9_3680 t1;
    sVt22_3680 t2;
    if (inChrg) {
        *(void**)self = (char*)self + 0x3B0;
        cRider_cRider((char*)self + 0x3B0);
    }
    *(void**)(*(char**)self + 0x6E8) = (void*)&D_00488550;
    *(void**)(*(char**)self + 0x6D0) = D_00459B90;
    *(void**)(*(char**)self + 0x6C0) = (void*)&D_00488598;
    if (inChrg == 0) {
        int vc;
        t1 = D_00488550;
        *(void**)(*(char**)self + 0x6E8) = &t1;
        {
            char* vbo = *(char**)self - 0x3B0;
            vc = (char*)self - vbo;
        }
        t1.e[1].delta = D_00488550.e[1].delta + vc;
        t2 = D_00488598;
        *(void**)(*(char**)self + 0x6C0) = &t2;
        t2.e[1].delta = D_00488598.e[1].delta + vc;
    }
    new ((char*)self + 0x50) sWakeSeg_6320[30];
    sWakePt_6320*& pts = *(sWakePt_6320**)((char*)self + 0x3AC);
    pts = new (D_00487B08, 0, 0) sWakePt_6320[20];
    func_002E6640(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E64C0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
extern "C" void func_0037C720(void* mgr, float f);
extern char* D_004A289C;

class cVbDtor002E64C0 : virtual public cRiderVb_bwf {
public:
    char pad04[0x3A8];
    void* m3AC;
    virtual ~cVbDtor002E64C0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002E64C0::~cVbDtor002E64C0()
{
    if (m3AC != 0) cMemMan_free(m3AC);
    func_0037C720(D_004A289C, 0.0f);
}
// PORT: the compiler names this dtor _$_15cVbDtor002E64C0; expose it under the address-derived name.
__asm__(".globl func_002E64C0\n.type func_002E64C0,@function\nfunc_002E64C0 = _$_15cVbDtor002E64C0\n.size func_002E64C0,0x17C\n");
#endif

//100%
INCLUDE_ASM("visualfx/boardwakefx", func_002E6640);
#ifdef SKIP_ASM
struct sWakeVec4 {
    float x;
    float y;
    float z;
    float w;
} __attribute__((aligned(16)));

extern "C" void func_002E6640(void* self)
{
    sWakeVec4 v;
    v.x = 1.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 1.0f;
    *(int*)((char*)self + 0x398) = 0x39;
    *(int*)((char*)self + 0x8) = 0;
    *(sWakeVec4*)((char*)self + 0x40) = v;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x30) = 0;
    *(int*)((char*)self + 0x3A0) = 0;
    *(int*)((char*)self + 0x39C) = 0;
    *(int*)((char*)self + 0x3A4) = (*(int*)(*(char**)self + 0x870) >= 0) ? 0x14 : 0x12;
    *(int*)((char*)self + 0x3A8) = 0;
}
#endif

INCLUDE_ASM("visualfx/boardwakefx", func_002E66B8);

INCLUDE_ASM("visualfx/boardwakefx", func_002E6C08);

INCLUDE_ASM("visualfx/boardwakefx", func_002E7A10);

