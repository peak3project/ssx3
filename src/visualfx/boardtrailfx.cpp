#include "common.h"

//100%
INCLUDE_ASM("visualfx/boardtrailfx", cBoardTrailFX_initialize);
#ifdef SKIP_ASM
extern "C" void* cRider_cRider(void* self);
extern "C" void func_003E6448(void* p, int c, int n);
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
    short neg = -1;
    int i;
    for (i = 47; i >= 0; i--) {
        self->ids[i] = neg;
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

INCLUDE_ASM("visualfx/boardtrailfx", func_002E86F0);

//100%
INCLUDE_ASM("visualfx/boardtrailfx", func_002E87E8);
#ifdef SKIP_ASM
int func_0011FE98(void* self);
int func_00312AA0(void* self, int a1);
extern "C" char* func_00311B20(void* self, int a1);
extern "C" int func_001446A0(void* self, int a1);
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

INCLUDE_ASM("visualfx/boardtrailfx", func_002E8938);

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
extern "C" void* func_00354648(void* self);
extern "C" void func_002EAA28(void* self);

extern "C" void* func_002EA670(void* self)
{
    func_00354648(self);
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

INCLUDE_ASM("visualfx/boardtrailfx", func_002EA900);

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

INCLUDE_ASM("visualfx/boardtrailfx", func_002EAAE0);

INCLUDE_ASM("visualfx/boardtrailfx", func_002EAC60);

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
    float zero = 0.0f;
    if (zero < speed)
    {
        func_00392DE8(*(char**)(self->rider + 0x77C) + 0xD30, 1);
        char* r0 = self->rider;
        sV3_2EADD0 sz;
        sz.x = 2.0f;
        sz.y = 2.0f;
        sz.z = 2.0f;
        char* fs = *(char**)(r0 + 0x77C) + 0xD30;
        sV4_2EADD0 col;
        col.x = zero;
        col.y = zero;
        col.z = 1.0f;
        col.w = zero;
        func_00392D90(fs, &col, &sz);
    }
    if (zero < speed && func_0011FE98(self->rider) == 1)
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

INCLUDE_ASM("visualfx/boardtrailfx", func_002EB198);

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
void func_002E4D70(void* self);
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

INCLUDE_ASM("visualfx/boardtrailfx", func_002EBF48);

INCLUDE_ASM("visualfx/boardtrailfx", func_002EC060);

