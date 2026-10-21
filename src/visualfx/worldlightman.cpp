#include "common.h"

//100%
INCLUDE_ASM("visualfx/worldlightman", cWorldLightMan_initLightCache);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00487CD8[];

struct sWLCVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sWLCVec4 D_004FF120;

struct sWLCList {
    unsigned int head;
    char pad04[0x100];
};

struct sWLCBuf {
    int owner;
    int count;
    sWLCList lists[3];
};

struct sWLCNode {
    unsigned int id;
    int priority;
    char pad08[0xA8];
    sWLCVec4 v;
    int fC0;
    char padC4[0xAC];
    sWLCNode* next;
    sWLCNode* prev;
    char pad178[8];
};

// Light slot view based at self+0x40*i: id/f14 at +0x10/+0x14; slot i's cache buffer
// lives at +0x40 (func_002F53B0 views it as slots[i].buf at self+0x40).
struct sWLCLightHdr {
    char pad00[0x10];
    unsigned int id;
    int f14;
    char pad18[0x28];
};

struct sWLCMan {
    union {
        int f00;
        sWLCLightHdr hdr[8];
    };
    char pad200[0x10];
    sWLCNode nodes[32];
    sWLCNode* heads[32];
    int count;
};

extern "C" void cWorldLightMan_initLightCache(sWLCMan* self)
{
    unsigned int i;
    for (i = 0; i < 8; i++) {
        sWLCLightHdr* l = &self->hdr[i];
        l->id = 0xFFFFFFFF;
        l->f14 = 0;
        sWLCBuf* buf = (sWLCBuf*)operator new(0xA14, D_00487CD8, 0x20000000, 0);
        buf->owner = self->f00;
        buf->count = 0;
        buf->lists[0].head = 0xFFFFFFFF;
        buf->lists[1].head = 0xFFFFFFFF;
        buf->lists[2].head = 0xFFFFFFFF;
        *(sWLCBuf**)((char*)l + 0x40) = buf;
    }
    for (i = 0; i < 32; i++) {
        self->nodes[i].priority = 0;
        self->nodes[i].id = 0xFFFFFFFF;
        self->nodes[i].v = D_004FF120;
        self->nodes[i].fC0 = 0;
        self->nodes[i].next = 0;
        self->nodes[i].prev = 0;
    }
    self->count = 0;
    for (i = 0; i < 32; i++) {
        self->heads[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F53B0);
#ifdef SKIP_ASM
void operator_delete(int*);

struct func_002F53B0_sSlot {
    int* buf;
    char pad04[0x3C];
};

struct func_002F53B0_sMan {
    char pad00[0x40];
    func_002F53B0_sSlot slots[8];
};

extern "C" void func_002F53B0(func_002F53B0_sMan* self)
{
    unsigned int i;
    for (i = 0; i < 8; i++) {
        operator_delete(self->slots[i].buf);
    }
}
#endif

INCLUDE_ASM("visualfx/worldlightman", func_002F5400);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F5998);
#ifdef SKIP_ASM
struct sWorldLight {
    char pad00[0x10];
    unsigned int id;
    char pad14[0x2C];
};

extern "C" void func_002F5998(sWorldLight* lights)
{
    unsigned int i;
    for (i = 0; i < 8; i++) {
        lights[i].id = 0xFFFFFFFF;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F59D0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sWorldLightNode {
    long key;
    char pad08[0x168];
    sWorldLightNode* next;
    sWorldLightNode* prev;
    char pad178[8];
};

struct sWorldLightMan {
    char pad000[0x210];
    sWorldLightNode nodes[32];
    sWorldLightNode* heads[32];
};

extern "C" sWorldLightNode* func_002F59D0(sWorldLightMan* self, int priority)
{
    sWorldLightNode* best = 0;
    int min = priority + 1;
    unsigned int i;
    for (i = 0; i < 32; i++) {
        int p = *(int*)((char*)&self->nodes[i] + 4);
        if (p < min) {
            min = p;
            best = &self->nodes[i];
        }
    }
    int slot = (int)(best->key >> 8) & 0x1F;
    if (best->prev == 0) {
        self->heads[slot] = best->next;
        if (best->next != 0) {
            best->next->prev = 0;
        }
    } else {
        if (best->next == 0) {
            best->prev->next = 0;
        } else {
            best->prev->next = best->next;
            best->next->prev = best->prev;
        }
    }
    return best;
}
#endif

INCLUDE_ASM("visualfx/worldlightman", func_002F5A70);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F5AF0);
#ifdef SKIP_ASM
extern "C" void func_002F5B68(void* self, void* a1, void* a2, void** out, int count);
extern "C" void func_0038A6A8(void* a, void* b, void* c);

extern "C" void func_002F5AF0(void* self, void* a1, void* a2, void* a3, int count)
{
    void* buf[32];
    int i;
    func_002F5B68(self, a1, a2, buf, count);
    for (i = 0; i < count; i++) {
        if (buf[i] != 0) {
            func_0038A6A8(a3, a1, buf[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F5B68);
#ifdef SKIP_ASM
extern "C" float func_002F5D30(void* a, void* b, void* light);

struct sLight_5B68 {
    char pad_0x0[0x8];
    int type;           // 0x8
};

struct sLightMgr_5B68 {
    char pad_0x0[0x210];
    unsigned int count;         // 0x210
    sLight_5B68* lights[1];     // 0x214
};

// Keeps the `max` best-scoring type-6 lights in out[], sorted by descending score.
extern "C" void func_002F5B68(void* a, void* b, void* mgrp, void** outp, int max)
{
    sLightMgr_5B68* mgr = (sLightMgr_5B68*)mgrp;
    sLight_5B68** out = (sLight_5B68**)outp;
    float score[32];
    int count = 0;
    int i;
    for (i = 0; i < max; i++) {
        out[i] = 0;
        score[i] = 0.0f;
    }
    float minScore = 0.0f;
    unsigned int n = mgr->count;
    for (unsigned int j = 0; j < n; j++) {
        sLight_5B68* l = mgr->lights[j];
        if (l->type == 6) {
            float s = func_002F5D30(a, b, l);
            if (minScore < s) {
                int k;
                for (k = 0; k < count && s < score[k]; k++) {
                }
                if (k < max) {
                    count += count < max;
                    for (int m = count - 1; k < m; m--) {
                        out[m] = out[m - 1];
                        score[m] = score[m - 1];
                    }
                    out[k] = l;
                    score[k] = s;
                }
                minScore = score[max - 1];
            }
        }
    }
}
#endif

INCLUDE_ASM("visualfx/worldlightman", func_002F5D30);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6168);
#ifdef SKIP_ASM
struct func_002F6168_sVec3 {
    float x;
    float y;
    float z;
};

struct func_002F6168_sLight {
    char pad[0x1C];
    float radius;               // 0x1C
    char pad20[0x2C - 0x20];
    func_002F6168_sVec3 dir;    // 0x2C
    func_002F6168_sVec3 pos;    // 0x38
};

extern "C" int func_002F6168(void* self, func_002F6168_sVec3* p, func_002F6168_sLight* light,
                             float* outDist, float* outInvDist, float* outDot)
{
    float dx = light->pos.x - p->x;
    float dy = light->pos.y - p->y;
    float dz = light->pos.z - p->z;
    float d2 = dx * dx + dy * dy + dz * dz;
    float dist;
    float inv;
    if (light->radius * light->radius < d2) {
        return 0;
    }
    if (d2 != 0.0f) {
        // PORT: sqrt.s (sqrtf without errno check)
        __asm__("sqrt.s %0, %1" : "=f"(dist) : "f"(d2));
        inv = 1.0f / dist;
    } else {
        inv = 1.0f;
        dist = 1.0f;
    }
    if (outDot != 0) {
        *outDot = -(dx * light->dir.x + dy * light->dir.y + dz * light->dir.z) * inv;
    }
    *outDist = dist;
    *outInvDist = inv;
    return 1;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6238);
#ifdef SKIP_ASM
// g++ 2.95 vtable entry (no thunks): {delta, index, fn}. Vtables are double-aligned.
struct sVtEnt6238 {
    short delta;
    short index;
    void* fn;
};

struct sVt9_6238 {
    sVtEnt6238 e[9];
} __attribute__((aligned(8)));

struct sVt22_6238 {
    sVtEnt6238 e[22];
} __attribute__((aligned(8)));

extern const sVt9_6238 D_004886E0;
extern const sVt22_6238 D_00488728;
extern char D_00459B90[];

extern "C" void cRider_cRider(void* self);
void* func_002F64F0(void* self);

// PORT: hand-written form of g++ 2.95's constructor for a class with a virtual base
// (cRider at +0x10): vtable copies with delta fixups when not in charge.
extern "C" void* func_002F6238(void* self, int inChrg)
{
    sVt9_6238 t1;
    sVt22_6238 t2;
    if (inChrg) {
        *(void**)self = (char*)self + 0x10;
        cRider_cRider((char*)self + 0x10);
    }
    *(void**)(*(char**)self + 0x6E8) = (void*)&D_004886E0;
    *(void**)(*(char**)self + 0x6D0) = D_00459B90;
    *(void**)(*(char**)self + 0x6C0) = (void*)&D_00488728;
    if (inChrg == 0) {
        int vc;
        t1 = D_004886E0;
        *(void**)(*(char**)self + 0x6E8) = &t1;
        {
            char* vbo = *(char**)self - 0x10;
            vc = (char*)self - vbo;
        }
        t1.e[1].delta = D_004886E0.e[1].delta + vc;
        t2 = D_00488728;
        *(void**)(*(char**)self + 0x6C0) = &t2;
        t2.e[1].delta = D_00488728.e[1].delta + vc;
    }
    func_002F64F0(self);
    return self;
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_wlm {
public:
    virtual ~cRiderVbA0_wlm();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_wlm : public cRiderVbA0_wlm { public: char padA[0xC]; };
class cRiderVbB0_wlm { public: virtual void b01(); };
class cRiderVbB_wlm : public cRiderVbB0_wlm { public: char padB[0x14]; };
class cRiderVbC0_wlm {
public:
    virtual ~cRiderVbC0_wlm();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_wlm : public cRiderVbC0_wlm { public: char padC[0x10]; };
class cRiderVbBC_wlm : public cRiderVbB_wlm, public cRiderVbC_wlm { public: };
class cRiderVbPad_wlm { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_wlm : public cRiderVbPad_wlm, public cRiderVbA_wlm, public cRiderVbBC_wlm {
public:
    virtual ~cRiderVb_wlm();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6388);
#ifdef SKIP_ASM
class cVbDtor002F6388 : virtual public cRiderVb_wlm {
public:
    virtual ~cVbDtor002F6388();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002F6388::~cVbDtor002F6388()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor002F6388; expose it under the address-derived name.
__asm__(".globl func_002F6388\n.type func_002F6388,@function\nfunc_002F6388 = _$_15cVbDtor002F6388\n.size func_002F6388,0x15C\n");
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F64E8__FPv);
#ifdef SKIP_ASM
void func_002F64E8(void* self)
{
}
#endif

extern "C" void* func_00416210(void*, int, int);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F64F0__FPv);
#ifdef SKIP_ASM
void* func_002F64F0(void* self)
{
    return func_00416210(((char*)self + 0x4), 0, 4);
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6518);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: called for effect only; bound by asm label so the call has no value
void func_002F64F0_v(void* self) __asm__("func_002F64F0__FPv");
struct sWLCode6910;
extern "C" void func_002F6910(sWLCode6910* self);
extern void* D_004A28A8;
extern int D_004A3BC0;
extern int D_00534B30[];

struct sVec6518 {
    float x, y, z, w;
} __attribute__((aligned(16)));
extern sVec6518 D_004FF130;

struct sVE6518 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sRider6518 {
    char pad0[0x1E0];
    sVec6518 vel;               // 0x1E0
    char pad1F0[0xF8];          // 0x1F0
    float f2E8;                 // 0x2E8
    float f2EC;                 // 0x2EC
    float f2F0;                 // 0x2F0
    int mode;                   // 0x2F4
    float f2F8;                 // 0x2F8
    float f2FC;                 // 0x2FC
    char pad300[0x4];           // 0x300
    int f304;                   // 0x304
    int f308;                   // 0x308
    float maxSpeed;             // 0x30C
    float steer;                // 0x310
    float blend;                // 0x314
    char pad318[0x88];          // 0x318
    sVec6518 dir;               // 0x3A0
};

struct sWLCode6518 {
    sRider6518* rider;          // 0x0
    signed char state;          // 0x4
    unsigned char step;         // 0x5
    signed char count;          // 0x6
    unsigned char flags;        // 0x7
};

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float len6518(const sVec6518& v)
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec6518 norm6518(const sVec6518& v)
{
    sVec6518 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sVec6518 scale6518(const sVec6518& v, float s)
{
    sVec6518 r;
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
static inline void scaleEq6518(sVec6518& v, float s)
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
static inline sVec6518 add6518(const sVec6518& a, const sVec6518& b)
{
    sVec6518 r;
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

struct sVEsub6518 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_002F6518(sWLCode6518* self)
{
    char* sub = (char*)self->rider + 0x6C0;
    sVEsub6518* vt = *(sVEsub6518**)sub;
    if (vt[9].fn(sub + vt[9].delta) != 0) {
        return;
    }
    if (D_004A3BC0 >= 2) {
        func_002F64F0_v(self);
        D_004A3BC0--;
    }
    func_002F6910((sWLCode6910*)self);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0) {
        self->state = 0;
    }
    if (self->state == 1) {
        self->rider->mode = 11;
        self->rider->f308 = (self->flags >> 1) & 1;
        self->rider->f2F8 = 1.0f;
        self->rider->f2F0 = 60.0f;
        self->rider->f2EC = 60.0f;
        self->rider->f2E8 = 60.0f;
        self->rider->f304 = 0;
    } else {
        self->rider->f308 = 1;
        if (self->rider->mode != 11) {
            return;
        }
        self->rider->mode = 0;
        self->rider->f2F8 = 0.0f;
        self->rider->f2F0 = 0.0f;
        self->rider->f2EC = 0.0f;
        self->rider->f2E8 = 0.0f;
        self->rider->f304 = 1;
    }
    sRider6518* r = self->rider;
    if (r->mode != 11) {
        return;
    }
    if (!(0.0f < r->f2FC)) {
        return;
    }
    float len = len6518(r->vel);
    if (len < r->maxSpeed && len != 0.0f) {
        r->vel = norm6518(r->vel);
        scaleEq6518(self->rider->vel, self->rider->maxSpeed * self->rider->blend + len * (1.0f - self->rider->blend));
        len = len6518(self->rider->vel);
    }
    r = self->rider;
    if (r->steer == 0.0f) {
        return;
    }
    if (!(0.0010000000474974513f < len6518(r->dir))) {
        return;
    }
    if (!(9.999999747378752e-05f < len6518(r->vel))) {
        return;
    }
    r->vel = add6518(scale6518(norm6518(r->dir), len * self->rider->steer),
                     scale6518(norm6518(self->rider->vel), len * (1.0f - self->rider->steer)));
    r = self->rider;
    if (r->vel.x < 0.0f && r->vel.x >= 0.0f) {
        r->vel = D_004FF130;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6908__FPv);
#ifdef SKIP_ASM
void func_002F6908(void* self)
{
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6910);
#ifdef SKIP_ASM
struct sWLCode6910 {
    char pad0[4];
    signed char state;          // 0x4
    unsigned char step;         // 0x5
    signed char count;          // 0x6
    unsigned char flags;        // 0x7
};

extern signed char D_00445E30[];
extern int D_004A3BC0;
extern "C" void func_002F6B28(void* self);
extern "C" int func_002F6B38(void* self);

extern "C" void func_002F6910(sWLCode6910* self)
{
    int r = func_002F6B38(self);
    func_002F6B28(self);
    if (r == 0) {
        self->flags &= ~1;
        return;
    }
    if (self->flags & 1) {
        return;
    }
    self->flags |= 1;
    switch (self->state) {
    case -1:
        if (r & 0x40) {
            self->state = 0;
            self->count = 0;
            self->step = 0;
            self->flags = 0;
        }
        break;
    case 0:
        if (r & 0x10) {
            self->count++;
        } else if (r & 0x20) {
            if (self->count == D_00445E30[(signed char)self->step]) {
                self->count = 0;
                self->step++;
                if (self->step == 9) {
                    self->step = 0;
                    self->count = 0;
                    self->state = 1;
                }
            } else {
                self->state = -1;
            }
        }
        break;
    case 1:
        if (r == 0x60) {
            D_004A3BC0 = 8;
        } else if (r & 0x40) {
            self->flags ^= 2;
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6A58);
#ifdef SKIP_ASM
class func_002F6A58_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual int v01(void* dst, int size);
    virtual int v02(void* src, int size);
};

extern "C" void func_002F6A58(void* self, func_002F6A58_cObj* stream)
{
    stream->v01((char*)self + 4, 4);
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6A90);
#ifdef SKIP_ASM
extern "C" void func_002F6A90(void* self, func_002F6A58_cObj* stream)
{
    stream->v02((char*)self + 4, 4);
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6AC8);
#ifdef SKIP_ASM
extern "C" void func_002F6AC8(void* self, int type)
{
    switch (type) {
    case 0:
        *(unsigned char*)((char*)self + 7) |= 0x10;
        break;
    case 1:
        *(unsigned char*)((char*)self + 7) |= 0x20;
        break;
    case 2:
        *(unsigned char*)((char*)self + 7) |= 0x40;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6B28);
#ifdef SKIP_ASM
extern "C" void func_002F6B28(void* self)
{
    unsigned char* p = (unsigned char*)((char*)self + 0x7);
    *p &= 0x8f;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6B38);
#ifdef SKIP_ASM
extern "C" int func_002F6B38(void* self)
{
    return *(unsigned char*)((char*)self + 0x7) & 0x70;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F6B48);
#ifdef SKIP_ASM
extern "C" void* func_002F6B48(void* self, ...)
{
    return self;
}
#endif

INCLUDE_ASM("visualfx/worldlightman", func_002F6B88);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7A50);
#ifdef SKIP_ASM
extern char D_004FF1A0[];

extern "C" void* func_002F7A50()
{
    return D_004FF1A0;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7A60);
#ifdef SKIP_ASM
extern "C" void func_002F7A60(void) {

}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7A68__FPv);
#ifdef SKIP_ASM
void* func_002F7A68(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7A70);
#ifdef SKIP_ASM
extern "C" int func_002F7A70(void *arg0) {
    return (*(int *)((char*)(arg0) + (4))) > 0;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7A80);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long long *func_002F7A80(long long *arg0, void *arg1) {
    *arg0 = (*(long long *)((char*)((((*(int *)((char*)(arg1) + (0xB4))) * 0x10) + (((*(int *)((char*)(arg1) + (8))) * 0x70) + (*(int *)((char*)(arg1) + (0xC)))))) + (-0x10)));
    return arg0;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7AB0);
#ifdef SKIP_ASM
extern "C" void func_002F7AB0(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7AB8);
#ifdef SKIP_ASM
extern "C" void func_002DCF28();

extern "C" void func_002F7AB8(void) {
    func_002DCF28();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7AD8);
#ifdef SKIP_ASM
extern "C" void func_002F7AD8(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7AE0);
#ifdef SKIP_ASM
extern "C" void func_002DAA78();

extern "C" void func_002F7AE0(void) {
    func_002DAA78();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B00);
#ifdef SKIP_ASM
extern "C" void func_002F7B00(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B08);
#ifdef SKIP_ASM
extern "C" void func_002E8560();

extern "C" void func_002F7B08(void) {
    func_002E8560();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B28);
#ifdef SKIP_ASM
extern "C" void func_002F7B28(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B30);
#ifdef SKIP_ASM
extern "C" void func_002D4BE0();

extern "C" void func_002F7B30(void) {
    func_002D4BE0();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B50);
#ifdef SKIP_ASM
extern "C" void func_002F7B50(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B58);
#ifdef SKIP_ASM
extern "C" void func_002E3930();

extern "C" void func_002F7B58(void) {
    func_002E3930();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B78);
#ifdef SKIP_ASM
extern "C" void func_002F7B78(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7B80);
#ifdef SKIP_ASM
extern "C" void func_002EF6A0();

extern "C" void func_002F7B80(void) {
    func_002EF6A0();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7BA0);
#ifdef SKIP_ASM
extern "C" void func_002F7BA0(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7BA8);
#ifdef SKIP_ASM
extern "C" void func_002F1148();

extern "C" void func_002F7BA8(void) {
    func_002F1148();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7BC8);
#ifdef SKIP_ASM
extern "C" int func_002F7BC8(int arg0) {
    return arg0 + 4;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7BD0);
#ifdef SKIP_ASM
extern "C" void func_002F7BD0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x6490))) = arg1;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7BD8);
#ifdef SKIP_ASM
extern "C" void func_002F7BD8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x6494))) = arg1;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7BE0);
#ifdef SKIP_ASM
extern "C" int func_002F7BE0(void* self)
{
    return *(unsigned int*)self == 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7BF0);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F7BF0(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7C20__FPv);
#ifdef SKIP_ASM
void func_002F7C20(void* self)
{
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7C28__FPv);
#ifdef SKIP_ASM
void func_002F7C28(void* self)
{
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7C30__FPv);
#ifdef SKIP_ASM
void func_002F7C30(void* self)
{
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7C38);
#ifdef SKIP_ASM
extern "C" void func_002D6410(void* self);
extern void* D_00488648[];

extern "C" void* func_002F7C38(void* self)
{
    *(void***)self = D_00488648;
    func_002D6410(self);
    return self;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7C70);
#ifdef SKIP_ASM
extern int D_004A3A30;

extern "C" int *func_002F7C70(void) {
    return &D_004A3A30;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7C80);
#ifdef SKIP_ASM
extern int D_004A3A34;

extern "C" int *func_002F7C80(void) {
    return &D_004A3A34;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7C90);
#ifdef SKIP_ASM
extern int D_004A3A38;

extern "C" int *func_002F7C90(void) {
    return &D_004A3A38;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7CA0);
#ifdef SKIP_ASM
extern int D_004A3A3C;

extern "C" int *func_002F7CA0(void) {
    return &D_004A3A3C;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7CB0);
#ifdef SKIP_ASM
extern int D_004A3A40;

extern "C" int *func_002F7CB0(void) {
    return &D_004A3A40;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7CC0);
#ifdef SKIP_ASM
extern int D_004A3A44;

extern "C" int *func_002F7CC0(void) {
    return &D_004A3A44;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7CD0);
#ifdef SKIP_ASM
extern int D_004A3A48;

extern "C" int *func_002F7CD0(void) {
    return &D_004A3A48;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7CE0);
#ifdef SKIP_ASM
extern int D_004A3A4C;

extern "C" int *func_002F7CE0(void) {
    return &D_004A3A4C;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7CF0);
#ifdef SKIP_ASM
extern int D_004A3A50;

extern "C" int *func_002F7CF0(void) {
    return &D_004A3A50;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D00);
#ifdef SKIP_ASM
extern int D_004A3A54;

extern "C" int *func_002F7D00(void) {
    return &D_004A3A54;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D10);
#ifdef SKIP_ASM
extern int D_004A3A58;

extern "C" int *func_002F7D10(void) {
    return &D_004A3A58;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D20);
#ifdef SKIP_ASM
extern int D_004A3A5C;

extern "C" int *func_002F7D20(void) {
    return &D_004A3A5C;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D30);
#ifdef SKIP_ASM
extern int D_004A3A60;

extern "C" int *func_002F7D30(void) {
    return &D_004A3A60;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D40);
#ifdef SKIP_ASM
extern int D_004A3A64;

extern "C" int *func_002F7D40(void) {
    return &D_004A3A64;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D50);
#ifdef SKIP_ASM
extern int D_004A3A68;

extern "C" int *func_002F7D50(void) {
    return &D_004A3A68;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D60);
#ifdef SKIP_ASM
extern int D_004A3A6C;

extern "C" int *func_002F7D60(void) {
    return &D_004A3A6C;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D70);
#ifdef SKIP_ASM
extern int D_004A3A70;

extern "C" int *func_002F7D70(void) {
    return &D_004A3A70;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D80);
#ifdef SKIP_ASM
extern int D_004A3A74;

extern "C" int *func_002F7D80(void) {
    return &D_004A3A74;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7D90);
#ifdef SKIP_ASM
extern int D_004A3A78;

extern "C" int *func_002F7D90(void) {
    return &D_004A3A78;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7DA0);
#ifdef SKIP_ASM
extern int D_004A3A7C;

extern "C" int *func_002F7DA0(void) {
    return &D_004A3A7C;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7DB0);
#ifdef SKIP_ASM
extern int D_004A3A80;

extern "C" int *func_002F7DB0(void) {
    return &D_004A3A80;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7DC0);
#ifdef SKIP_ASM
extern int D_004A3A84;

extern "C" int *func_002F7DC0(void) {
    return &D_004A3A84;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7DD0);
#ifdef SKIP_ASM
extern int D_004A3A88;

extern "C" int *func_002F7DD0(void) {
    return &D_004A3A88;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7DE0);
#ifdef SKIP_ASM
extern int D_004A3A8C;

extern "C" int *func_002F7DE0(void) {
    return &D_004A3A8C;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7DF0);
#ifdef SKIP_ASM
extern int D_004A3A90;

extern "C" int *func_002F7DF0(void) {
    return &D_004A3A90;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E00);
#ifdef SKIP_ASM
extern int D_004A3A94;

extern "C" int *func_002F7E00(void) {
    return &D_004A3A94;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E10);
#ifdef SKIP_ASM
extern int D_004A3A98;

extern "C" int *func_002F7E10(void) {
    return &D_004A3A98;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E20);
#ifdef SKIP_ASM
extern int D_004A3A9C;

extern "C" int *func_002F7E20(void) {
    return &D_004A3A9C;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E30);
#ifdef SKIP_ASM
extern int D_004A3AA0;

extern "C" int *func_002F7E30(void) {
    return &D_004A3AA0;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E40);
#ifdef SKIP_ASM
extern int D_004A3AA4;

extern "C" int *func_002F7E40(void) {
    return &D_004A3AA4;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E50);
#ifdef SKIP_ASM
extern int D_004A3AA8;

extern "C" int *func_002F7E50(void) {
    return &D_004A3AA8;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E60);
#ifdef SKIP_ASM
extern int D_004A3AAC;

extern "C" int *func_002F7E60(void) {
    return &D_004A3AAC;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E70);
#ifdef SKIP_ASM
extern "C" void func_002D9B40();

extern "C" void func_002F7E70(void) {
    func_002D9B40();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E90);
#ifdef SKIP_ASM
extern int D_004A3AB8;

extern "C" int func_002F7E90(void) {
    return D_004A3AB8;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7E98);
#ifdef SKIP_ASM
extern int D_004A3AC4;

extern "C" int func_002F7E98(void) {
    return D_004A3AC4;
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7EA0);
#ifdef SKIP_ASM
extern "C" void func_002F7EA0(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7EA8);
#ifdef SKIP_ASM
extern "C" void func_002E6640();

extern "C" void func_002F7EA8(void) {
    func_002E6640();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7EC8);
#ifdef SKIP_ASM
extern "C" void func_002F7EC8(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7ED0);
#ifdef SKIP_ASM
extern "C" void func_002EADC0__FPv();

extern "C" void func_002F7ED0(void) {
    func_002EADC0__FPv();
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7EF0);
#ifdef SKIP_ASM
extern "C" void func_002F7EF0(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7EF8);
#ifdef SKIP_ASM
extern "C" void func_002F7EF8(void) {

}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7F00);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F7F00(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7F30);
#ifdef SKIP_ASM
extern void* D_00488308[];
void operator_delete(int*);

extern "C" void func_002F7F30(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00488308;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7F60);
#ifdef SKIP_ASM
extern void* D_00488308[];
void operator_delete(int*);

extern "C" void func_002F7F60(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00488308;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7F90);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F7F90(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FC0);
#ifdef SKIP_ASM
extern "C" int func_002F7FC0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA0)));
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FC8);
#ifdef SKIP_ASM
extern "C" void func_002F7FC8(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FD0);
#ifdef SKIP_ASM
extern "C" void func_002F7FD0(void) {

}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FD8);
#ifdef SKIP_ASM
extern "C" int func_002F7FD8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x44)));
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FE0);
#ifdef SKIP_ASM
extern "C" int func_002F7FE0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x64)));
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FE8);
#ifdef SKIP_ASM
extern "C" int func_002F7FE8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x78)));
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FF0__FPv);
#ifdef SKIP_ASM
int func_002F7FF0(void* self)
{
    return *(int*)((char*)self + 0x74);
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F7FF8);
#ifdef SKIP_ASM
extern "C" int func_002F7FF8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x60)));
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8000);
#ifdef SKIP_ASM
extern void* D_004880E0[];
extern "C" void func_002E4D30(void* p);

extern "C" void func_002F8000(void* self, int flags)
{
    *(void***)self = D_004880E0;
    if (flags & 1) {
        func_002E4D30(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8030);
#ifdef SKIP_ASM
extern void* D_004880E0[];
extern "C" void func_002E4D30(void* p);

extern "C" void func_002F8030(void* self, int flags)
{
    *(void***)self = D_004880E0;
    if (flags & 1) {
        func_002E4D30(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8060);
#ifdef SKIP_ASM
struct sLightVec_002F8060 { float x, y, z, w; };

extern void* D_004880C0[];
void func_002E4D70(void* self);

extern "C" void* func_002F8060(void* self, sLightVec_002F8060 v)
{
    func_002E4D70(self);
    *(void***)self = D_004880C0;
    *(sLightVec_002F8060*)((char*)self + 4) = v;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F80D8);
#ifdef SKIP_ASM
extern void* D_004880E0[];
extern "C" void func_002E4D30(void* p);

extern "C" void func_002F80D8(void* self, int flags)
{
    *(void***)self = D_004880E0;
    if (flags & 1) {
        func_002E4D30(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8108);
#ifdef SKIP_ASM
extern void* D_004880E0[];
extern "C" void func_002E4D30(void* p);

extern "C" void func_002F8108(void* self, int flags)
{
    *(void***)self = D_004880E0;
    if (flags & 1) {
        func_002E4D30(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8138);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F8138(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8168__FPv);
#ifdef SKIP_ASM
void func_002F8168(void* self)
{
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8170);
#ifdef SKIP_ASM
static inline unsigned long bitOf(int b) { return 1UL << b; }
extern "C" int func_002F8170(unsigned long* p, int bit)
{
    unsigned long m = 1UL << bit;
    return (*p & m) != 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8188);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F8188(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_003546C8(void* self);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F81B8__FPv);
#ifdef SKIP_ASM
void* func_002F81B8(void* self)
{
    return func_003546C8(self);
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F81D8);
#ifdef SKIP_ASM
extern "C" int func_002F81D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F81E0);
#ifdef SKIP_ASM
extern "C" void func_002F81E0(int *arg0) {
    *arg0 = 1;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F81F0);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F81F0(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8220);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F8220(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8250);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F8250(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8280);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F8280(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F82B0);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F82B0(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F82E0);
#ifdef SKIP_ASM
extern void* D_00488680[];
void operator_delete(int*);

extern "C" void func_002F82E0(void* self, int flags)
{
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8310);
#ifdef SKIP_ASM
extern void* D_00487DA0[];
void operator_delete(int*);

extern "C" void func_002F8310(void* self, int flags)
{
    *(void***)((char*)self + 0x44) = D_00487DA0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8340);
#ifdef SKIP_ASM
extern void* D_00487D78[];
void operator_delete(int*);

extern "C" void func_002F8340(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00487D78;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_002F6B88(int, int);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8370__FPv);
#ifdef SKIP_ASM
void* func_002F8370(void* self)
{
    return func_002F6B88(1, 0xffff);
}
#endif

extern "C" void* func_002F6B88(int, int);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8390__FPv);
#ifdef SKIP_ASM
void* func_002F8390(void* self)
{
    return func_002F6B88(0, 0xffff);
}
#endif

INCLUDE_ASM("visualfx/worldlightman", func_002F83B0);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F8FF8__FPv);
#ifdef SKIP_ASM
void func_002F8FF8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F9000);
#ifdef SKIP_ASM
extern "C" void* func_002F9000(void* self, ...)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F9040);
#ifdef SKIP_ASM
extern float D_004FAC90[4];
extern float D_004FACA0[4];
extern float D_004FACB0[4];
extern float D_004FACC0[4];
extern float D_004FACD0[4];
extern float D_004FACE0[4];
extern float D_004FACF0[4];
extern float D_004FAD00[4];
extern float D_004FAD10[4];
extern float D_004FAD20[4];
extern float D_004FAD30[4];
extern float D_004FAD40[4];
extern float D_004FAD50[4];
extern float D_004FAD60[4];
extern float D_004FAD70[4];
extern float D_004FAD80[4];
extern float D_004FAD90[4];
extern float D_004FADA0[4];
extern float D_004FADB0[4];
extern float D_004FADC0[4];
extern float D_004FADD0[4];
extern float D_004FADE0[4];
extern float D_004FADF0[4];
extern float D_004FAE00[4];
extern float D_004FAE10[4];
extern float D_004FAE20[4];
extern float D_004FAE30[4];
extern float D_004FAE40[4];
extern float D_004FAE50[4];
extern float D_004FAE60[4];
extern float D_004FAE70[4];
extern float D_004FAE80[4];
extern float D_004FAE90[4];
extern float D_004FAEA0[4];
extern float D_004FAEB0[4];
extern float D_004FAEC0[4];
extern float D_004FAED0[4];
extern float D_004FAEE0[4];
extern float D_004FAEF0[4];
extern float D_004FAF00[4];
extern float D_004FAF10[4];
extern float D_004FAF20[4];
extern float D_004FAF30[4];
extern float D_004FAF40[4];
extern float D_004FAF50[4];
extern float D_004FAF60[4];
extern float D_004FAF70[4];
extern float D_004FAF80[4];
extern float D_004FAF90[4];
extern float D_004FAFA0[4];
extern float D_004FAFB0[4];
extern float D_004FAFC0[4];
extern float D_004FAFD0[4];
extern float D_004FAFE0[4];
extern float D_004FAFF0[4];
extern float D_004FB000[4];

void sti_002F9040(int init, int prio) __asm__("func_002F9040");
void sti_002F9040(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004FAC90[0] = 1.0f;
        D_004FAC90[1] = 1.0f;
        D_004FAC90[2] = 1.0f;
        D_004FAC90[3] = 0.5f;
        D_004FACA0[0] = 0.4998680055141449f;
        D_004FACA0[1] = 1.0f;
        D_004FACA0[2] = 1.0f;
        D_004FACA0[3] = 0.0f;
        D_004FACB0[0] = 0.12951700389385223f;
        D_004FACB0[1] = 1.0f;
        D_004FACB0[2] = 1.0f;
        D_004FACB0[3] = 0.0f;
        D_004FACC0[0] = 0.22426900267601013f;
        D_004FACC0[1] = 0.9402310252189636f;
        D_004FACC0[2] = 0.5425059795379639f;
        D_004FACC0[3] = 0.0004030000127386302f;
        D_004FACD0[0] = 0.4652079939842224f;
        D_004FACD0[1] = 0.32170501351356506f;
        D_004FACD0[2] = 0.9943439960479736f;
        D_004FACD0[3] = 0.0f;
        D_004FACE0[0] = 0.17792600393295288f;
        D_004FACE0[1] = 1.0f;
        D_004FACE0[2] = 1.0f;
        D_004FACE0[3] = 0.0f;
        D_004FACF0[0] = 0.4411740005016327f;
        D_004FACF0[1] = 0.41388601064682007f;
        D_004FACF0[2] = 0.3211260139942169f;
        D_004FACF0[3] = 0.4398239850997925f;
        D_004FAD00[0] = 0.500997006893158f;
        D_004FAD00[1] = 0.24849599599838257f;
        D_004FAD00[2] = 1.0f;
        D_004FAD00[3] = 1.0f;
        D_004FAD10[0] = 0.27687299251556396f;
        D_004FAD10[1] = 0.6395620107650757f;
        D_004FAD10[2] = 0.13423900306224823f;
        D_004FAD10[3] = 0.0f;
        D_004FAD20[0] = 0.8936439752578735f;
        D_004FAD20[1] = 0.5263469815254211f;
        D_004FAD20[2] = 0.5051450133323669f;
        D_004FAD20[3] = 0.8687300086021423f;
        D_004FAD30[0] = 1.0f;
        D_004FAD30[1] = 1.0f;
        D_004FAD30[2] = 1.0f;
        D_004FAD30[3] = 1.0f;
        D_004FAD40[0] = 1.0f;
        D_004FAD40[1] = 0.0f;
        D_004FAD40[2] = 0.0f;
        D_004FAD40[3] = 0.0f;
        D_004FAD50[0] = 1.0f;
        D_004FAD50[1] = 0.550000011920929f;
        D_004FAD50[2] = 0.5350000262260437f;
        D_004FAD50[3] = 0.550000011920929f;
        D_004FAD60[0] = 1.0f;
        D_004FAD60[1] = 1.0f;
        D_004FAD60[2] = 1.0f;
        D_004FAD60[3] = 1.0f;
        D_004FAD70[0] = 1.0f;
        D_004FAD70[1] = 1.0f;
        D_004FAD70[2] = 1.0f;
        D_004FAD70[3] = 1.0f;
        D_004FAD80[0] = 1.0f;
        D_004FAD80[1] = 0.0f;
        D_004FAD80[2] = 0.0f;
        D_004FAD80[3] = 0.0f;
        D_004FAD90[0] = 1.0f;
        D_004FAD90[1] = 0.0f;
        D_004FAD90[2] = 0.0f;
        D_004FAD90[3] = 0.0f;
        D_004FADA0[0] = 1.0f;
        D_004FADA0[1] = 1.0f;
        D_004FADA0[2] = 1.0f;
        D_004FADA0[3] = 1.0f;
        D_004FADB0[0] = 1.0f;
        D_004FADB0[1] = 0.5f;
        D_004FADB0[2] = 1.0f;
        D_004FADB0[3] = 0.5f;
        D_004FADC0[0] = 1.0f;
        D_004FADC0[1] = 0.5f;
        D_004FADC0[2] = 1.0f;
        D_004FADC0[3] = 0.5f;
        D_004FADD0[0] = 1.0f;
        D_004FADD0[1] = 0.5f;
        D_004FADD0[2] = 1.0f;
        D_004FADD0[3] = 0.5f;
        D_004FADE0[0] = 1.0f;
        D_004FADE0[1] = 0.7828119993209839f;
        D_004FADE0[2] = 0.06171900033950806f;
        D_004FADE0[3] = 0.03984399884939194f;
        D_004FADF0[0] = 1.0f;
        D_004FADF0[1] = 1.0f;
        D_004FADF0[2] = 0.7988259792327881f;
        D_004FADF0[3] = 0.0f;
        D_004FAE00[0] = 0.9886710047721863f;
        D_004FAE00[1] = 0.9230499863624573f;
        D_004FAE00[2] = 0.34311699867248535f;
        D_004FAE00[3] = 0.0f;
        D_004FAE10[0] = 1.0f;
        D_004FAE10[1] = 1.0f;
        D_004FAE10[2] = 1.0f;
        D_004FAE10[3] = 1.0f;
        D_004FAE20[0] = 1.0f;
        D_004FAE20[1] = 1.0f;
        D_004FAE20[2] = 0.7976430058479309f;
        D_004FAE20[3] = 0.0f;
        D_004FAE30[0] = 1.0f;
        D_004FAE30[1] = 0.9222670197486877f;
        D_004FAE30[2] = 0.34179699420928955f;
        D_004FAE30[3] = 0.0f;
        D_004FAE40[0] = 1.0f;
        D_004FAE40[1] = 0.7847639918327332f;
        D_004FAE40[2] = 0.06054700165987015f;
        D_004FAE40[3] = 0.04062499850988388f;
        D_004FAE50[0] = 1.0f;
        D_004FAE50[1] = 0.800000011920929f;
        D_004FAE50[2] = 0.44999998807907104f;
        D_004FAE50[3] = 1.0f;
        D_004FAE60[0] = 1.0f;
        D_004FAE60[1] = 0.3281260132789612f;
        D_004FAE60[2] = 1.0f;
        D_004FAE60[3] = 0.3539060056209564f;
        D_004FAE70[0] = 1.0f;
        D_004FAE70[1] = 1.0f;
        D_004FAE70[2] = 1.0f;
        D_004FAE70[3] = 1.0f;
        D_004FAE80[0] = 1.0f;
        D_004FAE80[1] = 1.0f;
        D_004FAE80[2] = 1.0f;
        D_004FAE80[3] = 1.0f;
        D_004FAE90[0] = 1.0f;
        D_004FAE90[1] = 0.8613290190696716f;
        D_004FAE90[2] = 0.38124799728393555f;
        D_004FAE90[3] = 0.0f;
        D_004FAEA0[0] = 1.0f;
        D_004FAEA0[1] = 1.0f;
        D_004FAEA0[2] = 1.0f;
        D_004FAEA0[3] = 1.0f;
        D_004FAEB0[0] = 1.0f;
        D_004FAEB0[1] = 0.3244380056858063f;
        D_004FAEB0[2] = 1.0f;
        D_004FAEB0[3] = 0.0f;
        D_004FAEC0[0] = 1.0f;
        D_004FAEC0[1] = 1.0f;
        D_004FAEC0[2] = 1.0f;
        D_004FAEC0[3] = 1.0f;
        D_004FAED0[0] = 1.0f;
        D_004FAED0[1] = 1.0f;
        D_004FAED0[2] = 0.0f;
        D_004FAED0[3] = 0.0f;
        D_004FAEE0[0] = 0.7007060050964355f;
        D_004FAEE0[1] = 0.0f;
        D_004FAEE0[2] = 0.0f;
        D_004FAEE0[3] = 0.0f;
        D_004FAEF0[0] = 1.0f;
        D_004FAEF0[1] = 0.7828530073165894f;
        D_004FAEF0[2] = 0.06140600144863129f;
        D_004FAEF0[3] = 0.04146299883723259f;
        D_004FAF00[0] = 1.0f;
        D_004FAF00[1] = 0.32487601041793823f;
        D_004FAF00[2] = 1.0f;
        D_004FAF00[3] = 0.35280099511146545f;
        D_004FAF10[0] = 1.0f;
        D_004FAF10[1] = 1.0f;
        D_004FAF10[2] = 0.7977359890937805f;
        D_004FAF10[3] = 0.0f;
        D_004FAF20[0] = 1.0f;
        D_004FAF20[1] = 0.4937489926815033f;
        D_004FAF20[2] = 1.0f;
        D_004FAF20[3] = 0.49179700016975403f;
        D_004FAF30[0] = 1.0f;
        D_004FAF30[1] = 1.0f;
        D_004FAF30[2] = 1.0f;
        D_004FAF30[3] = 1.0f;
        D_004FAF40[0] = 1.0f;
        D_004FAF40[1] = 0.800000011920929f;
        D_004FAF40[2] = 1.0f;
        D_004FAF40[3] = 0.800000011920929f;
        D_004FAF50[0] = 1.0f;
        D_004FAF50[1] = 1.0f;
        D_004FAF50[2] = 0.0f;
        D_004FAF50[3] = 0.0f;
        D_004FAF60[0] = 1.0f;
        D_004FAF60[1] = 1.0f;
        D_004FAF60[2] = 0.0f;
        D_004FAF60[3] = 0.0f;
        D_004FAF70[0] = 1.0f;
        D_004FAF70[1] = 1.0f;
        D_004FAF70[2] = 0.0f;
        D_004FAF70[3] = 0.0f;
        D_004FAF80[0] = 1.0f;
        D_004FAF80[1] = 0.3273420035839081f;
        D_004FAF80[2] = 1.0f;
        D_004FAF80[3] = 0.35390499234199524f;
        D_004FAF90[0] = 1.0f;
        D_004FAF90[1] = 1.0f;
        D_004FAF90[2] = 0.061000000685453415f;
        D_004FAF90[3] = 0.039000000804662704f;
        D_004FAFA0[0] = 1.0f;
        D_004FAFA0[1] = 1.0f;
        D_004FAFA0[2] = 0.7999979853630066f;
        D_004FAFA0[3] = 0.0f;
        D_004FAFB0[0] = 1.0f;
        D_004FAFB0[1] = 0.9589840173721313f;
        D_004FAFB0[2] = 0.6143789887428284f;
        D_004FAFB0[3] = 0.0f;
        D_004FAFC0[0] = 1.0f;
        D_004FAFC0[1] = 0.9285150170326233f;
        D_004FAFC0[2] = 0.3399839997291565f;
        D_004FAFC0[3] = 0.0f;
        D_004FAFD0[0] = 1.0f;
        D_004FAFD0[1] = 0.8738250136375427f;
        D_004FAFD0[2] = 0.24931700527668f;
        D_004FAFD0[3] = 0.017578000202775f;
        D_004FAFE0[0] = 1.0f;
        D_004FAFE0[1] = 0.7843739986419678f;
        D_004FAFE0[2] = 0.06132800132036209f;
        D_004FAFE0[3] = 0.03945299983024597f;
        D_004FAFF0[0] = 1.0f;
        D_004FAFF0[1] = 0.0f;
        D_004FAFF0[2] = 1.0f;
        D_004FAFF0[3] = 0.0f;
        D_004FB000[0] = 1.0f;
        D_004FB000[1] = 1.0f;
        D_004FB000[2] = 0.0f;
        D_004FB000[3] = 0.0f;
    }
}
#endif

extern "C" void* func_002F9040(int, int);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F9818__FPv);
#ifdef SKIP_ASM
void* func_002F9818(void* self)
{
    return func_002F9040(1, 0xffff);
}
#endif

INCLUDE_ASM("visualfx/worldlightman", func_002F9838);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002FA5F8__FPv);
#ifdef SKIP_ASM
void func_002FA5F8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002FA600);
#ifdef SKIP_ASM
extern "C" void* func_002FA600(void* self, ...)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002FA640);
#ifdef SKIP_ASM
extern float D_004FB010[4];
extern float D_004FB020[4];
extern float D_004FB030[4];
extern float D_004FB040[4];
extern float D_004FB050[4];
extern float D_004FB060[4];
extern float D_004FB070[4];
extern float D_004FB080[4];
extern float D_004FB090[4];
extern float D_004FB0A0[4];
extern float D_004FB0B0[4];
extern float D_004FB0C0[4];
extern float D_004FB0D0[4];
extern float D_004FB0E0[4];
extern float D_004FB0F0[4];
extern float D_004FB100[4];
extern float D_004FB110[4];
extern float D_004FB120[4];
extern float D_004FB130[4];
extern float D_004FB140[4];
extern float D_004FB150[4];
extern float D_004FB160[4];
extern float D_004FB170[4];
extern float D_004FB180[4];
extern float D_004FB190[4];
extern float D_004FB1A0[4];
extern float D_004FB1B0[4];
extern float D_004FB1C0[4];
extern float D_004FB1D0[4];
extern float D_004FB1E0[4];
extern float D_004FB1F0[4];
extern float D_004FB200[4];
extern float D_004FB210[4];
extern float D_004FB220[4];
extern float D_004FB230[4];
extern float D_004FB240[4];
extern float D_004FB250[4];
extern float D_004FB260[4];
extern float D_004FB270[4];
extern float D_004FB280[4];
extern float D_004FB290[4];
extern float D_004FB2A0[4];
extern float D_004FB2B0[4];
extern float D_004FB2C0[4];
extern float D_004FB2D0[4];
extern float D_004FB2E0[4];
extern float D_004FB2F0[4];
extern float D_004FB300[4];
extern float D_004FB310[4];
extern float D_004FB320[4];
extern float D_004FB330[4];
extern float D_004FB340[4];
extern float D_004FB350[4];
extern float D_004FB360[4];
extern float D_004FB370[4];
extern float D_004FB380[4];

void sti_002FA640(int init, int prio) __asm__("func_002FA640");
void sti_002FA640(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004FB010[0] = 1.0f;
        D_004FB010[1] = 1.0f;
        D_004FB010[2] = 1.0f;
        D_004FB010[3] = 0.5f;
        D_004FB020[0] = 0.4998680055141449f;
        D_004FB020[1] = 1.0f;
        D_004FB020[2] = 1.0f;
        D_004FB020[3] = 0.0f;
        D_004FB030[0] = 0.12951700389385223f;
        D_004FB030[1] = 1.0f;
        D_004FB030[2] = 1.0f;
        D_004FB030[3] = 0.0f;
        D_004FB040[0] = 0.22426900267601013f;
        D_004FB040[1] = 0.9402310252189636f;
        D_004FB040[2] = 0.5425059795379639f;
        D_004FB040[3] = 0.0004030000127386302f;
        D_004FB050[0] = 0.4652079939842224f;
        D_004FB050[1] = 0.32170501351356506f;
        D_004FB050[2] = 0.9943439960479736f;
        D_004FB050[3] = 0.0f;
        D_004FB060[0] = 0.17792600393295288f;
        D_004FB060[1] = 1.0f;
        D_004FB060[2] = 1.0f;
        D_004FB060[3] = 0.0f;
        D_004FB070[0] = 0.4411740005016327f;
        D_004FB070[1] = 0.41388601064682007f;
        D_004FB070[2] = 0.3211260139942169f;
        D_004FB070[3] = 0.4398239850997925f;
        D_004FB080[0] = 0.500997006893158f;
        D_004FB080[1] = 0.24849599599838257f;
        D_004FB080[2] = 1.0f;
        D_004FB080[3] = 1.0f;
        D_004FB090[0] = 0.27687299251556396f;
        D_004FB090[1] = 0.6395620107650757f;
        D_004FB090[2] = 0.13423900306224823f;
        D_004FB090[3] = 0.0f;
        D_004FB0A0[0] = 0.8936439752578735f;
        D_004FB0A0[1] = 0.5263469815254211f;
        D_004FB0A0[2] = 0.5051450133323669f;
        D_004FB0A0[3] = 0.8687300086021423f;
        D_004FB0B0[0] = 1.0f;
        D_004FB0B0[1] = 1.0f;
        D_004FB0B0[2] = 1.0f;
        D_004FB0B0[3] = 1.0f;
        D_004FB0C0[0] = 1.0f;
        D_004FB0C0[1] = 0.0f;
        D_004FB0C0[2] = 0.0f;
        D_004FB0C0[3] = 0.0f;
        D_004FB0D0[0] = 1.0f;
        D_004FB0D0[1] = 0.550000011920929f;
        D_004FB0D0[2] = 0.5350000262260437f;
        D_004FB0D0[3] = 0.550000011920929f;
        D_004FB0E0[0] = 1.0f;
        D_004FB0E0[1] = 1.0f;
        D_004FB0E0[2] = 1.0f;
        D_004FB0E0[3] = 1.0f;
        D_004FB0F0[0] = 1.0f;
        D_004FB0F0[1] = 1.0f;
        D_004FB0F0[2] = 1.0f;
        D_004FB0F0[3] = 1.0f;
        D_004FB100[0] = 1.0f;
        D_004FB100[1] = 0.0f;
        D_004FB100[2] = 0.0f;
        D_004FB100[3] = 0.0f;
        D_004FB110[0] = 1.0f;
        D_004FB110[1] = 0.0f;
        D_004FB110[2] = 0.0f;
        D_004FB110[3] = 0.0f;
        D_004FB120[0] = 1.0f;
        D_004FB120[1] = 1.0f;
        D_004FB120[2] = 1.0f;
        D_004FB120[3] = 1.0f;
        D_004FB130[0] = 1.0f;
        D_004FB130[1] = 0.5f;
        D_004FB130[2] = 1.0f;
        D_004FB130[3] = 0.5f;
        D_004FB140[0] = 1.0f;
        D_004FB140[1] = 0.5f;
        D_004FB140[2] = 1.0f;
        D_004FB140[3] = 0.5f;
        D_004FB150[0] = 1.0f;
        D_004FB150[1] = 0.5f;
        D_004FB150[2] = 1.0f;
        D_004FB150[3] = 0.5f;
        D_004FB160[0] = 1.0f;
        D_004FB160[1] = 0.7828119993209839f;
        D_004FB160[2] = 0.06171900033950806f;
        D_004FB160[3] = 0.03984399884939194f;
        D_004FB170[0] = 1.0f;
        D_004FB170[1] = 1.0f;
        D_004FB170[2] = 0.7988259792327881f;
        D_004FB170[3] = 0.0f;
        D_004FB180[0] = 0.9886710047721863f;
        D_004FB180[1] = 0.9230499863624573f;
        D_004FB180[2] = 0.34311699867248535f;
        D_004FB180[3] = 0.0f;
        D_004FB190[0] = 1.0f;
        D_004FB190[1] = 1.0f;
        D_004FB190[2] = 1.0f;
        D_004FB190[3] = 1.0f;
        D_004FB1A0[0] = 1.0f;
        D_004FB1A0[1] = 1.0f;
        D_004FB1A0[2] = 0.7976430058479309f;
        D_004FB1A0[3] = 0.0f;
        D_004FB1B0[0] = 1.0f;
        D_004FB1B0[1] = 0.9222670197486877f;
        D_004FB1B0[2] = 0.34179699420928955f;
        D_004FB1B0[3] = 0.0f;
        D_004FB1C0[0] = 1.0f;
        D_004FB1C0[1] = 0.7847639918327332f;
        D_004FB1C0[2] = 0.06054700165987015f;
        D_004FB1C0[3] = 0.04062499850988388f;
        D_004FB1D0[0] = 1.0f;
        D_004FB1D0[1] = 0.800000011920929f;
        D_004FB1D0[2] = 0.44999998807907104f;
        D_004FB1D0[3] = 1.0f;
        D_004FB1E0[0] = 1.0f;
        D_004FB1E0[1] = 0.3281260132789612f;
        D_004FB1E0[2] = 1.0f;
        D_004FB1E0[3] = 0.3539060056209564f;
        D_004FB1F0[0] = 1.0f;
        D_004FB1F0[1] = 1.0f;
        D_004FB1F0[2] = 1.0f;
        D_004FB1F0[3] = 1.0f;
        D_004FB200[0] = 1.0f;
        D_004FB200[1] = 1.0f;
        D_004FB200[2] = 1.0f;
        D_004FB200[3] = 1.0f;
        D_004FB210[0] = 1.0f;
        D_004FB210[1] = 0.8613290190696716f;
        D_004FB210[2] = 0.38124799728393555f;
        D_004FB210[3] = 0.0f;
        D_004FB220[0] = 1.0f;
        D_004FB220[1] = 1.0f;
        D_004FB220[2] = 1.0f;
        D_004FB220[3] = 1.0f;
        D_004FB230[0] = 1.0f;
        D_004FB230[1] = 0.3244380056858063f;
        D_004FB230[2] = 1.0f;
        D_004FB230[3] = 0.0f;
        D_004FB240[0] = 1.0f;
        D_004FB240[1] = 1.0f;
        D_004FB240[2] = 1.0f;
        D_004FB240[3] = 1.0f;
        D_004FB250[0] = 1.0f;
        D_004FB250[1] = 1.0f;
        D_004FB250[2] = 0.0f;
        D_004FB250[3] = 0.0f;
        D_004FB260[0] = 0.7007060050964355f;
        D_004FB260[1] = 0.0f;
        D_004FB260[2] = 0.0f;
        D_004FB260[3] = 0.0f;
        D_004FB270[0] = 1.0f;
        D_004FB270[1] = 0.7828530073165894f;
        D_004FB270[2] = 0.06140600144863129f;
        D_004FB270[3] = 0.04146299883723259f;
        D_004FB280[0] = 1.0f;
        D_004FB280[1] = 0.32487601041793823f;
        D_004FB280[2] = 1.0f;
        D_004FB280[3] = 0.35280099511146545f;
        D_004FB290[0] = 1.0f;
        D_004FB290[1] = 1.0f;
        D_004FB290[2] = 0.7977359890937805f;
        D_004FB290[3] = 0.0f;
        D_004FB2A0[0] = 1.0f;
        D_004FB2A0[1] = 0.4937489926815033f;
        D_004FB2A0[2] = 1.0f;
        D_004FB2A0[3] = 0.49179700016975403f;
        D_004FB2B0[0] = 1.0f;
        D_004FB2B0[1] = 1.0f;
        D_004FB2B0[2] = 1.0f;
        D_004FB2B0[3] = 1.0f;
        D_004FB2C0[0] = 1.0f;
        D_004FB2C0[1] = 0.800000011920929f;
        D_004FB2C0[2] = 1.0f;
        D_004FB2C0[3] = 0.800000011920929f;
        D_004FB2D0[0] = 1.0f;
        D_004FB2D0[1] = 1.0f;
        D_004FB2D0[2] = 0.0f;
        D_004FB2D0[3] = 0.0f;
        D_004FB2E0[0] = 1.0f;
        D_004FB2E0[1] = 1.0f;
        D_004FB2E0[2] = 0.0f;
        D_004FB2E0[3] = 0.0f;
        D_004FB2F0[0] = 1.0f;
        D_004FB2F0[1] = 1.0f;
        D_004FB2F0[2] = 0.0f;
        D_004FB2F0[3] = 0.0f;
        D_004FB300[0] = 1.0f;
        D_004FB300[1] = 0.3273420035839081f;
        D_004FB300[2] = 1.0f;
        D_004FB300[3] = 0.35390499234199524f;
        D_004FB310[0] = 1.0f;
        D_004FB310[1] = 1.0f;
        D_004FB310[2] = 0.061000000685453415f;
        D_004FB310[3] = 0.039000000804662704f;
        D_004FB320[0] = 1.0f;
        D_004FB320[1] = 1.0f;
        D_004FB320[2] = 0.7999979853630066f;
        D_004FB320[3] = 0.0f;
        D_004FB330[0] = 1.0f;
        D_004FB330[1] = 0.9589840173721313f;
        D_004FB330[2] = 0.6143789887428284f;
        D_004FB330[3] = 0.0f;
        D_004FB340[0] = 1.0f;
        D_004FB340[1] = 0.9285150170326233f;
        D_004FB340[2] = 0.3399839997291565f;
        D_004FB340[3] = 0.0f;
        D_004FB350[0] = 1.0f;
        D_004FB350[1] = 0.8738250136375427f;
        D_004FB350[2] = 0.24931700527668f;
        D_004FB350[3] = 0.017578000202775f;
        D_004FB360[0] = 1.0f;
        D_004FB360[1] = 0.7843739986419678f;
        D_004FB360[2] = 0.06132800132036209f;
        D_004FB360[3] = 0.03945299983024597f;
        D_004FB370[0] = 1.0f;
        D_004FB370[1] = 0.0f;
        D_004FB370[2] = 1.0f;
        D_004FB370[3] = 0.0f;
        D_004FB380[0] = 1.0f;
        D_004FB380[1] = 1.0f;
        D_004FB380[2] = 0.0f;
        D_004FB380[3] = 0.0f;
    }
}
#endif

extern "C" void* func_002FA640(int, int);

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002FAE18__FPv);
#ifdef SKIP_ASM
void* func_002FAE18(void* self)
{
    return func_002FA640(1, 0xffff);
}
#endif

