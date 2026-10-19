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

INCLUDE_ASM("visualfx/worldlightman", func_002F6B48);

INCLUDE_ASM("visualfx/worldlightman", func_002F6B88);

INCLUDE_ASM("visualfx/worldlightman", func_002F7A50);
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

INCLUDE_ASM("visualfx/worldlightman", func_002F7C38);
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

INCLUDE_ASM("visualfx/worldlightman", func_002F8170);

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

//99.38%
INCLUDE_ASM("visualfx/worldlightman", func_002F8370__FPv);
#ifdef SKIP_ASM
void* func_002F8370(void* self)
{
    return func_002F6B88(1, 0xffff);
}
#endif

extern "C" void* func_002F6B88(int, int);

//99.38%
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

INCLUDE_ASM("visualfx/worldlightman", func_002F9000);

INCLUDE_ASM("visualfx/worldlightman", func_002F9040);

extern "C" void* func_002F9040(int, int);

//99.38%
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

INCLUDE_ASM("visualfx/worldlightman", func_002FA600);

INCLUDE_ASM("visualfx/worldlightman", func_002FA640);

extern "C" void* func_002FA640(int, int);

//99.38%
INCLUDE_ASM("visualfx/worldlightman", func_002FAE18__FPv);
#ifdef SKIP_ASM
void* func_002FAE18(void* self)
{
    return func_002FA640(1, 0xffff);
}
#endif

