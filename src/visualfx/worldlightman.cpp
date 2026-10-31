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

extern "C" void* cRider_cRider(void* self);
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
extern "C" void func_002DAA78(void* vself);

extern "C" void func_002F7AE0(void* vself) {
    func_002DAA78(vself);
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
extern "C" void func_002D4BE0(void* self);

extern "C" void func_002F7B30(void* self) {
    func_002D4BE0(self);
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
extern "C" void func_002EF6A0(void* self);

extern "C" void func_002F7B80(void* self) {
    func_002EF6A0(self);
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
extern "C" void func_002F1148(void *arg0);

extern "C" void func_002F7BA8(void *arg0) {
    func_002F1148(arg0);
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
extern "C" void func_002D9B40(void* self);

extern "C" void func_002F7E70(void* self) {
    func_002D9B40(self);
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
extern "C" void func_002E6640(void* self);

extern "C" void func_002F7EA8(void* self) {
    func_002E6640(self);
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
void* func_002E4D70(void* self);

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

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F83B0);
#ifdef SKIP_ASM
extern int* D_004A3BB0;

extern "C" void func_002F83B0(void)
{
    int* p = D_004A3BB0;
    float* pf = (float*)p;
    p[0x0] = 1;
    p[0x1] = 0;
    pf[0x2] = -1.0f;
    pf[0x3] = 1.0f;
    pf[0x4] = 40.0f;
    pf[0x5] = 1.0f;
    p[0x6] = 0;
    p[0x7] = 0;
    p[0x8] = 0;
    p[0x9] = 0;
    p[0xA] = 0;
    p[0xB] = 0;
    p[0xC] = 0;
    p[0xD] = 0;
    p[0xE] = 0;
    p[0xF] = 0;
    p[0x10] = 0;
    p[0x11] = 0;
    p[0x12] = 0;
    p[0x13] = 0;
    p[0x14] = 0;
    pf[0x15] = 150.0f;
    p[0x16] = 0;
    p[0x17] = 0;
    p[0x18] = 0;
    pf[0x19] = 150.0f;
    p[0x1A] = 0;
    p[0x1B] = 0;
    p[0x1C] = 0;
    pf[0x1D] = 150.0f;
    p[0x1E] = 0;
    p[0x1F] = 0;
    p[0x20] = 0;
    pf[0x21] = 1.0f;
    pf[0x22] = 1.0f;
    pf[0x23] = 1.0f;
    pf[0x24] = 1.0f;
    pf[0x25] = 1.0f;
    pf[0x26] = 1.0f;
    pf[0x27] = 1.0f;
    pf[0x28] = 1.0f;
    p[0x29] = 0;
    p[0x2A] = 0;
    p[0x2B] = 0;
    p[0x2C] = 0;
    p[0x2D] = 0;
    p[0x2E] = 0;
    p[0x2F] = 0;
    p[0x30] = 0;
    p[0x32] = 1;
    pf[0x33] = 20.0f;
    p[0x31] = 5;
    p[0x34] = 1;
    pf[0x35] = 20.0f;
    pf[0x36] = 1.0f;
    p[0x37] = 0;
    p[0x38] = 0;
    p[0x39] = 0;
    p[0x3A] = 0;
    p[0x3B] = 0;
    p[0x3C] = 0;
    p[0x3D] = 0;
    p[0x3E] = 0;
    p[0x3F] = 0;
    pf[0x40] = 140.0f;
    pf[0x41] = 1.0f;
    pf[0x42] = 1.0f;
    pf[0x43] = 1.0f;
    p[0x44] = 1;
    p[0x45] = 0;
    pf[0x46] = -1.0f;
    pf[0x47] = 1.5f;
    pf[0x48] = 70.0f;
    pf[0x49] = 0.25f;
    pf[0x4A] = 50.0f;
    p[0x4B] = 0;
    p[0x4C] = 0;
    p[0x4D] = 0;
    p[0x4E] = 0;
    p[0x4F] = 0;
    pf[0x50] = 10.0f;
    p[0x51] = 0;
    p[0x52] = 0;
    p[0x53] = 0;
    pf[0x54] = 10.0f;
    p[0x55] = 0;
    p[0x56] = 0;
    p[0x57] = 0;
    p[0x58] = 0;
    pf[0x59] = 100.0f;
    p[0x5A] = 0;
    p[0x5B] = 0;
    p[0x5C] = 0;
    pf[0x5D] = 100.0f;
    p[0x5E] = 0;
    p[0x5F] = 0;
    p[0x60] = 0;
    pf[0x61] = 100.0f;
    p[0x62] = 0;
    p[0x63] = 0;
    pf[0x64] = 1690.0f;  // D_0049F980
    pf[0x65] = 1.0f;
    pf[0x66] = 1.0f;
    pf[0x67] = 1.0f;
    pf[0x68] = 1.0f;
    p[0x69] = 0;
    pf[0x6A] = 1.0f;
    p[0x6B] = 0;
    p[0x6C] = 0;
    p[0x6D] = 0;
    p[0x6E] = 0;
    p[0x6F] = 0;
    p[0x70] = 0;
    p[0x71] = 0;
    p[0x72] = 0;
    p[0x73] = 0;
    p[0x74] = 0;
    p[0x76] = 0;
    p[0x77] = 0;
    p[0x75] = 24;
    p[0x78] = 1;
    pf[0x79] = 20.0f;
    pf[0x7A] = 1.0f;
    p[0x7B] = 0;
    p[0x7C] = 0;
    pf[0x7D] = 3.0f;
    p[0x7E] = 0;
    pf[0x7F] = 3.0f;
    p[0x80] = 0;
    p[0x81] = 0;
    p[0x82] = 0;
    p[0x83] = 0;
    pf[0x84] = 140.0f;
    pf[0x85] = 1.0f;
    pf[0x86] = 1.0f;
    pf[0x87] = 1.0f;
    p[0x88] = 1;
    p[0x89] = 0;
    pf[0x8A] = -1.0f;
    pf[0x8B] = 1.0f;
    pf[0x8C] = 30.0f;
    pf[0x8D] = 0.165010005f;  // D_0049F984
    p[0x8E] = 0;
    p[0x8F] = 0;
    p[0x90] = 0;
    p[0x91] = 0;
    p[0x92] = 0;
    p[0x93] = 0;
    p[0x94] = 0;
    p[0x95] = 0;
    p[0x96] = 0;
    p[0x97] = 0;
    p[0x98] = 0;
    p[0x99] = 0;
    p[0x9A] = 0;
    p[0x9B] = 0;
    p[0x9C] = 0;
    pf[0x9D] = 50.0f;
    p[0x9E] = 0;
    p[0x9F] = 0;
    p[0xA0] = 0;
    pf[0xA1] = 100.0f;
    p[0xA2] = 0;
    p[0xA3] = 0;
    p[0xA4] = 0;
    pf[0xA5] = 100.0f;
    p[0xA6] = 0;
    p[0xA7] = 0;
    pf[0xA8] = 655.0f;  // D_0049F988
    pf[0xA9] = 1.0f;
    pf[0xAA] = 1.0f;
    pf[0xAB] = 1.0f;
    pf[0xAC] = 1.0f;
    p[0xAD] = 0;
    pf[0xAE] = 1.0f;
    p[0xAF] = 0;
    p[0xB0] = 0;
    p[0xB1] = 0;
    p[0xB2] = 0;
    p[0xB3] = 0;
    p[0xB4] = 0;
    p[0xB5] = 0;
    p[0xB6] = 0;
    p[0xB7] = 0;
    p[0xB8] = 0;
    p[0xBA] = 0;
    p[0xBB] = 0;
    p[0xB9] = 24;
    p[0xBC] = 1;
    pf[0xBD] = 20.0f;
    pf[0xBE] = 1.0f;
    p[0xBF] = 0;
    p[0xC0] = 0;
    pf[0xC1] = 10.0f;
    p[0xC2] = 0;
    p[0xC3] = 0;
    p[0xC4] = 0;
    p[0xC5] = 0;
    p[0xC6] = 0;
    p[0xC7] = 0;
    pf[0xC8] = 140.0f;
    pf[0xC9] = 1.0f;
    pf[0xCA] = 1.0f;
    pf[0xCB] = 1.0f;
    p[0xCC] = 1;
    p[0xCD] = 0;
    pf[0xCE] = -1.0f;
    pf[0xCF] = 1.0f;
    pf[0xD0] = 55.5520096f;  // D_0049F990
    pf[0xD1] = 0.100000001f;  // D_0049F98C
    p[0xD2] = 0;
    p[0xD3] = 0;
    p[0xD4] = 0;
    p[0xD5] = 0;
    p[0xD6] = 0;
    p[0xD7] = 0;
    p[0xD8] = 0;
    p[0xD9] = 0;
    p[0xDA] = 0;
    p[0xDB] = 0;
    p[0xDC] = 0;
    p[0xDD] = 0;
    p[0xDE] = 0;
    p[0xDF] = 0;
    p[0xE0] = 0;
    pf[0xE1] = 50.0f;
    p[0xE2] = 0;
    p[0xE3] = 0;
    p[0xE4] = 0;
    pf[0xE5] = 500.0f;
    p[0xE6] = 0;
    p[0xE7] = 0;
    p[0xE8] = 0;
    pf[0xE9] = 500.0f;
    p[0xEA] = 0;
    p[0xEB] = 0;
    pf[0xEC] = -200.0f;
    pf[0xED] = 1.0f;
    pf[0xEE] = 1.0f;
    pf[0xEF] = 0.200000003f;  // D_0049F994
    pf[0xF0] = 0.200000003f;  // D_0049F994
    p[0xF1] = 0;
    pf[0xF2] = 1.0f;
    pf[0xF3] = 0.200000003f;  // D_0049F994
    pf[0xF4] = 0.200000003f;  // D_0049F994
    p[0xF5] = 0;
    p[0xF6] = 0;
    p[0xF7] = 0;
    p[0xF8] = 0;
    p[0xF9] = 0;
    p[0xFA] = 0;
    p[0xFB] = 0;
    p[0xFC] = 0;
    p[0xFE] = 0;
    p[0xFF] = 0;
    p[0xFD] = 24;
    p[0x100] = 1;
    pf[0x101] = 20.0f;
    pf[0x102] = 1.0f;
    p[0x103] = 0;
    p[0x104] = 0;
    pf[0x105] = 10.0f;
    p[0x106] = 0;
    p[0x107] = 0;
    p[0x108] = 0;
    p[0x109] = 0;
    p[0x10A] = 0;
    p[0x10B] = 0;
    pf[0x10C] = 140.0f;
    pf[0x10D] = 1.0f;
    pf[0x10E] = 1.0f;
    pf[0x10F] = 1.0f;
    p[0x110] = 2;
    p[0x111] = 0;
    pf[0x112] = -1.0f;
    pf[0x113] = 1.0f;
    pf[0x114] = 100.0f;
    pf[0x115] = 0.400000006f;  // D_0049F998
    p[0x116] = 0;
    p[0x117] = 0;
    p[0x118] = 0;
    p[0x119] = 0;
    p[0x11A] = 0;
    p[0x11B] = 0;
    p[0x11C] = 0;
    p[0x11D] = 0;
    p[0x11E] = 0;
    p[0x11F] = 0;
    p[0x120] = 0;
    p[0x121] = 0;
    p[0x122] = 0;
    p[0x123] = 0;
    p[0x124] = 0;
    pf[0x125] = 100.0f;
    p[0x126] = 0;
    p[0x127] = 0;
    p[0x128] = 0;
    pf[0x129] = 100.0f;
    p[0x12A] = 0;
    p[0x12B] = 0;
    p[0x12C] = 0;
    pf[0x12D] = 100.0f;
    p[0x12E] = 0;
    p[0x12F] = 0;
    pf[0x130] = 500.0f;
    pf[0x131] = 1.0f;
    pf[0x132] = 1.0f;
    pf[0x133] = 1.0f;
    pf[0x134] = 1.0f;
    p[0x135] = 0;
    pf[0x136] = 1.0f;
    p[0x137] = 0;
    p[0x138] = 0;
    p[0x139] = 0;
    p[0x13A] = 0;
    p[0x13B] = 0;
    p[0x13C] = 0;
    p[0x13D] = 0;
    p[0x13E] = 0;
    p[0x13F] = 0;
    p[0x140] = 0;
    p[0x142] = 0;
    pf[0x143] = 40.0f;
    p[0x141] = 24;
    p[0x144] = 1;
    pf[0x145] = 20.0f;
    pf[0x146] = 1.25f;
    p[0x147] = 0;
    p[0x148] = 0;
    p[0x149] = 0;
    pf[0x14A] = 8.0f;
    p[0x14B] = 0;
    p[0x14C] = 0;
    p[0x14D] = 0;
    p[0x14E] = 0;
    p[0x14F] = 0;
    pf[0x150] = 140.0f;
    pf[0x151] = 1.0f;
    pf[0x152] = 1.0f;
    pf[0x153] = 1.0f;
    p[0x154] = 1;
    p[0x155] = 0;
    pf[0x156] = -1.0f;
    pf[0x157] = 1.5f;
    pf[0x158] = 10.0f;
    pf[0x159] = 0.5f;
    p[0x15A] = 0;
    p[0x15B] = 0;
    p[0x15C] = 0;
    p[0x15D] = 0;
    p[0x15E] = 0;
    p[0x15F] = 0;
    p[0x160] = 0;
    p[0x161] = 0;
    p[0x162] = 0;
    p[0x163] = 0;
    p[0x164] = 0;
    p[0x165] = 0;
    p[0x166] = 0;
    p[0x167] = 0;
    p[0x168] = 0;
    pf[0x169] = 40.0f;
    p[0x16A] = 0;
    p[0x16B] = 0;
    p[0x16C] = 0;
    pf[0x16D] = 40.0f;
    p[0x16E] = 0;
    p[0x16F] = 0;
    p[0x170] = 0;
    pf[0x171] = 40.0f;
    p[0x172] = 0;
    p[0x173] = 0;
    pf[0x174] = 500.0f;
    pf[0x175] = 0.999000013f;  // D_0049F9A0
    pf[0x176] = 0.399500012f;  // D_0049F9A4
    pf[0x177] = 0.400000006f;  // D_0049F998
    pf[0x178] = 0.400000006f;  // D_0049F998
    p[0x179] = 0;
    pf[0x17A] = 0.0987500027f;  // D_0049F9A8
    pf[0x17B] = 0.115000002f;  // D_0049F99C
    pf[0x17C] = 0.107500002f;  // D_0049F9AC
    p[0x17D] = 0;
    p[0x17E] = 0;
    p[0x17F] = 0;
    p[0x180] = 0;
    p[0x181] = 0;
    p[0x182] = 0;
    p[0x183] = 0;
    p[0x184] = 0;
    p[0x186] = 1;
    pf[0x187] = 120.0f;
    p[0x185] = 25;
    p[0x188] = 1;
    pf[0x189] = 20.0f;
    pf[0x18A] = 0.800000012f;  // D_0049F9B0
    p[0x18B] = 0;
    p[0x18C] = 0;
    p[0x18D] = 0;
    pf[0x18E] = 7.0f;
    p[0x18F] = 0;
    p[0x190] = 0;
    p[0x191] = 0;
    p[0x192] = 0;
    p[0x193] = 0;
    pf[0x194] = 140.0f;
    pf[0x195] = 1.0f;
    pf[0x196] = 1.0f;
    pf[0x197] = 1.0f;
    p[0x198] = 2;
    p[0x199] = 0;
    pf[0x19A] = -1.0f;
    pf[0x19B] = 1.0f;
    pf[0x19C] = 24.0f;
    pf[0x19D] = 0.100000001f;  // D_0049F98C
    pf[0x19E] = 6.0f;
    pf[0x19F] = 0.100000001f;  // D_0049F98C
    pf[0x1A0] = 0.0900000036f;  // D_0049F9B4
    p[0x1A1] = 0;
    p[0x1A2] = 0;
    p[0x1A3] = 0;
    p[0x1A4] = 0;
    p[0x1A5] = 0;
    p[0x1A6] = 0;
    p[0x1A7] = 0;
    p[0x1A8] = 0;
    p[0x1A9] = 0;
    p[0x1AA] = 0;
    p[0x1AB] = 0;
    p[0x1AC] = 0;
    p[0x1AD] = 0;
    p[0x1AE] = 0;
    p[0x1AF] = 0;
    p[0x1B0] = 0;
    p[0x1B1] = 0;
    p[0x1B2] = 0;
    p[0x1B3] = 0;
    p[0x1B4] = 0;
    p[0x1B5] = 0;
    p[0x1B6] = 0;
    p[0x1B7] = 0;
    p[0x1B8] = 0;
    pf[0x1B9] = 1.0f;
    pf[0x1BA] = 0.0450000018f;  // D_0049F9BC
    pf[0x1BB] = 0.00875000004f;  // D_0049F9C0
    pf[0x1BC] = 1.0f;
    p[0x1BD] = 0;
    pf[0x1BE] = 1.0f;
    pf[0x1BF] = 0.966750026f;  // D_0049F9C4
    pf[0x1C0] = 1.0f;
    pf[0x1C1] = 0.5f;
    p[0x1C2] = 0;
    p[0x1C3] = 0;
    p[0x1C4] = 0;
    p[0x1C5] = 0;
    p[0x1C6] = 0;
    p[0x1C7] = 0;
    p[0x1C8] = 0;
    p[0x1CA] = 0;
    p[0x1CB] = 0;
    p[0x1C9] = 5;
    p[0x1CC] = 1;
    pf[0x1CD] = 20.0f;
    pf[0x1CE] = 1.20000005f;  // D_0049F9B8
    p[0x1CF] = 0;
    p[0x1D0] = 0;
    pf[0x1D1] = -21.5f;
    pf[0x1D2] = -13.75f;
    pf[0x1D3] = -21.5f;
    pf[0x1D4] = -372.75f;  // D_0049F9C8
    p[0x1D5] = 0;
    pf[0x1D6] = -3.0f;
    p[0x1D7] = 0;
    pf[0x1D8] = 140.0f;
    pf[0x1D9] = 1.0f;
    pf[0x1DA] = 1.0f;
    p[0x1DB] = 0;
    p[0x1DC] = 2;
    p[0x1DD] = 0;
    pf[0x1DE] = -1.0f;
    pf[0x1DF] = 1.0f;
    pf[0x1E0] = 24.0f;
    pf[0x1E1] = 0.100000001f;  // D_0049F98C
    pf[0x1E2] = 6.0f;
    pf[0x1E3] = 0.100000001f;  // D_0049F98C
    pf[0x1E4] = 0.0900000036f;  // D_0049F9B4
    p[0x1E5] = 0;
    p[0x1E6] = 0;
    p[0x1E7] = 0;
    p[0x1E8] = 0;
    p[0x1E9] = 0;
    p[0x1EA] = 0;
    p[0x1EB] = 0;
    p[0x1EC] = 0;
    p[0x1ED] = 0;
    p[0x1EE] = 0;
    p[0x1EF] = 0;
    p[0x1F0] = 0;
    p[0x1F1] = 0;
    p[0x1F2] = 0;
    p[0x1F3] = 0;
    p[0x1F4] = 0;
    p[0x1F5] = 0;
    p[0x1F6] = 0;
    p[0x1F7] = 0;
    p[0x1F8] = 0;
    p[0x1F9] = 0;
    p[0x1FA] = 0;
    p[0x1FB] = 0;
    p[0x1FC] = 0;
    pf[0x1FD] = 1.0f;
    pf[0x1FE] = 0.0450000018f;  // D_0049F9BC
    pf[0x1FF] = 0.00875000004f;  // D_0049F9C0
    pf[0x200] = 1.0f;
    p[0x201] = 0;
    pf[0x202] = 1.0f;
    pf[0x203] = 0.966750026f;  // D_0049F9C4
    pf[0x204] = 1.0f;
    pf[0x205] = 0.5f;
    p[0x206] = 0;
    p[0x207] = 0;
    p[0x208] = 0;
    p[0x209] = 0;
    p[0x20A] = 0;
    p[0x20B] = 0;
    p[0x20C] = 0;
    p[0x20E] = 0;
    p[0x20F] = 0;
    p[0x20D] = 5;
    p[0x210] = 1;
    pf[0x211] = 20.0f;
    pf[0x212] = 1.20000005f;  // D_0049F9B8
    p[0x213] = 0;
    p[0x214] = 0;
    pf[0x215] = -21.5f;
    pf[0x216] = 16.25f;
    pf[0x217] = -21.5f;
    pf[0x218] = -372.75f;  // D_0049F9C8
    p[0x219] = 0;
    pf[0x21A] = -3.0f;
    p[0x21B] = 0;
    pf[0x21C] = 140.0f;
    pf[0x21D] = 1.0f;
    pf[0x21E] = 1.0f;
    pf[0x21F] = 54.5f;
    p[0x220] = 3;
    p[0x221] = 0;
    pf[0x222] = -1.0f;
    pf[0x223] = 1.0f;
    pf[0x224] = 6.97600985f;  // D_0049F9CC
    pf[0x225] = 0.100000001f;  // D_0049F98C
    pf[0x226] = 6.20800018f;  // D_0049F9D0
    pf[0x227] = 0.100000001f;  // D_0049F98C
    pf[0x228] = 0.00999999978f;  // D_0049F9D4
    p[0x229] = 0;
    p[0x22A] = 0;
    p[0x22B] = 0;
    pf[0x22C] = 6.0f;
    p[0x22D] = 0;
    p[0x22E] = 0;
    p[0x22F] = 0;
    pf[0x230] = 6.0f;
    p[0x231] = 0;
    p[0x232] = 0;
    p[0x233] = 0;
    p[0x234] = 0;
    p[0x235] = 0;
    p[0x236] = 0;
    p[0x237] = 0;
    pf[0x238] = 87.5f;
    p[0x239] = 0;
    p[0x23A] = 0;
    p[0x23B] = 0;
    pf[0x23C] = 270.0f;
    p[0x23D] = 0;
    p[0x23E] = 0;
    p[0x23F] = 0;
    p[0x240] = 0;
    pf[0x241] = 0.924250007f;  // D_0049F9D8
    pf[0x242] = 1.0f;
    pf[0x243] = 1.0f;
    pf[0x244] = 0.424250007f;  // D_0049F9DC
    p[0x245] = 0;
    pf[0x246] = 0.935750008f;  // D_0049F9E0
    p[0x247] = 0;
    p[0x248] = 0;
    p[0x249] = 0;
    pf[0x24A] = 0.115000002f;  // D_0049F99C
    p[0x24B] = 0;
    p[0x24C] = 0;
    p[0x24D] = 0;
    p[0x24E] = 0;
    p[0x24F] = 0;
    p[0x250] = 0;
    p[0x252] = 0;
    pf[0x253] = 20.6000004f;  // D_0049F9E4
    p[0x251] = 5;
    p[0x254] = 1;
    pf[0x255] = 20.0f;
    pf[0x256] = 1.20000005f;  // D_0049F9B8
    p[0x257] = 0;
    p[0x258] = 0;
    pf[0x259] = -39.5f;
    p[0x25A] = 0;
    pf[0x25B] = -21.5f;
    pf[0x25C] = -394.25f;  // D_0049F9E8
    p[0x25D] = 0;
    p[0x25E] = 0;
    p[0x25F] = 0;
    pf[0x260] = 110.0f;
    pf[0x261] = 1.0f;
    pf[0x262] = 1.0f;
    pf[0x263] = 1.0f;
    p[0x264] = 8;
    p[0x265] = 0;
    pf[0x266] = -1.0f;
    pf[0x267] = 1.0f;
    pf[0x268] = 6.97600985f;  // D_0049F9CC
    pf[0x269] = 0.200000003f;  // D_0049F994
    pf[0x26A] = 6.20800018f;  // D_0049F9D0
    pf[0x26B] = 0.200000003f;  // D_0049F994
    pf[0x26C] = 0.00999999978f;  // D_0049F9D4
    p[0x26D] = 0;
    p[0x26E] = 0;
    p[0x26F] = 0;
    pf[0x270] = 6.0f;
    p[0x271] = 0;
    p[0x272] = 0;
    p[0x273] = 0;
    pf[0x274] = 6.0f;
    p[0x275] = 0;
    p[0x276] = 0;
    p[0x277] = 0;
    p[0x278] = 0;
    p[0x279] = 0;
    p[0x27A] = 0;
    p[0x27B] = 0;
    pf[0x27C] = 87.5f;
    p[0x27D] = 0;
    p[0x27E] = 0;
    p[0x27F] = 0;
    pf[0x280] = 270.0f;
    p[0x281] = 0;
    p[0x282] = 0;
    p[0x283] = 0;
    p[0x284] = 0;
    pf[0x285] = 0.924250007f;  // D_0049F9D8
    pf[0x286] = 1.0f;
    pf[0x287] = 1.0f;
    pf[0x288] = 0.424250007f;  // D_0049F9DC
    p[0x289] = 0;
    pf[0x28A] = 0.935750008f;  // D_0049F9E0
    p[0x28B] = 0;
    p[0x28C] = 0;
    p[0x28D] = 0;
    pf[0x28E] = 0.115000002f;  // D_0049F99C
    p[0x28F] = 0;
    p[0x290] = 0;
    p[0x291] = 0;
    p[0x292] = 0;
    p[0x293] = 0;
    p[0x294] = 0;
    p[0x296] = 0;
    pf[0x297] = 20.6000004f;  // D_0049F9E4
    p[0x295] = 5;
    p[0x298] = 1;
    pf[0x299] = 20.0f;
    pf[0x29A] = 1.20000005f;  // D_0049F9B8
    p[0x29B] = 0;
    p[0x29C] = 0;
    pf[0x29D] = -39.5f;
    p[0x29E] = 0;
    pf[0x29F] = -21.5f;
    pf[0x2A0] = -394.25f;  // D_0049F9E8
    p[0x2A1] = 0;
    p[0x2A2] = 0;
    pf[0x2A3] = 110.0f;
    pf[0x2A4] = 140.0f;
    pf[0x2A5] = 1.0f;
    pf[0x2A6] = 1.0f;
    pf[0x2A7] = 1.0f;
}
#endif

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

//100%
INCLUDE_ASM("visualfx/worldlightman", func_002F9838);
#ifdef SKIP_ASM
extern int* D_004A3BB0;

extern "C" void func_002F9838(void)
{
    int* p = D_004A3BB0;
    float* pf = (float*)p;
    p[0x2A8] = 5;
    p[0x2A9] = 0;
    pf[0x2AA] = -1.0f;
    pf[0x2AB] = 0.800000012f;  // D_0049FB04
    pf[0x2AC] = 5.0f;
    pf[0x2AD] = 0.25f;
    p[0x2AE] = 0;
    pf[0x2AF] = 0.100000001f;  // D_0049FB00
    p[0x2B0] = 0;
    p[0x2B1] = 0;
    p[0x2B2] = 0;
    p[0x2B3] = 0;
    p[0x2B4] = 0;
    p[0x2B5] = 0;
    p[0x2B6] = 0;
    p[0x2B7] = 0;
    p[0x2B8] = 0;
    p[0x2B9] = 0;
    p[0x2BA] = 0;
    p[0x2BB] = 0;
    p[0x2BC] = 0;
    pf[0x2BD] = 400.0f;
    p[0x2BE] = 0;
    p[0x2BF] = 0;
    p[0x2C0] = 0;
    pf[0x2C1] = 400.0f;
    p[0x2C2] = 0;
    p[0x2C3] = 0;
    p[0x2C4] = 0;
    pf[0x2C5] = 400.0f;
    p[0x2C6] = 0;
    p[0x2C7] = 0;
    pf[0x2C8] = -185.0f;
    pf[0x2C9] = 1.0f;
    pf[0x2CA] = 1.0f;
    pf[0x2CB] = 0.391000003f;  // D_0049FB14
    pf[0x2CC] = 0.0590000004f;  // D_0049FB08
    p[0x2CD] = 0;
    pf[0x2CE] = 1.0f;
    pf[0x2CF] = 0.972750008f;  // D_0049FB0C
    p[0x2D0] = 0;
    p[0x2D1] = 0;
    p[0x2D2] = 0;
    p[0x2D3] = 0;
    p[0x2D4] = 0;
    p[0x2D5] = 0;
    pf[0x2D6] = 0.351500005f;  // D_0049FB10
    p[0x2D7] = 0;
    p[0x2D8] = 0;
    p[0x2DA] = 0;
    p[0x2DB] = 0;
    p[0x2D9] = 41;
    p[0x2DC] = 1;
    pf[0x2DD] = 20.0f;
    pf[0x2DE] = 1.20000005f;  // D_0049FB18
    p[0x2DF] = 0;
    p[0x2E0] = 0;
    pf[0x2E1] = 16.25f;
    pf[0x2E2] = 3.0f;
    pf[0x2E3] = 18.0f;
    p[0x2E4] = 0;
    p[0x2E5] = 0;
    p[0x2E6] = 0;
    p[0x2E7] = 0;
    pf[0x2E8] = 140.0f;
    pf[0x2E9] = 1.0f;
    pf[0x2EA] = 0.449999988f;  // D_0049FB1C
    pf[0x2EB] = 0.699999988f;  // D_0049FB20
    p[0x2EC] = 10;
    p[0x2ED] = 0;
    pf[0x2EE] = -1.0f;
    pf[0x2EF] = 1.0f;
    pf[0x2F0] = 4.0f;
    pf[0x2F1] = 1.20000005f;  // D_0049FB18
    pf[0x2F2] = 5.0f;
    pf[0x2F3] = 2.0f;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
    pf[0x2F8] = 17.75f;
    p[0x2F9] = 0;
    p[0x2FA] = 0;
    p[0x2FB] = 0;
    pf[0x2FC] = 17.75f;
    p[0x2FD] = 0;
    p[0x2FE] = 0;
    p[0x2FF] = 0;
    p[0x300] = 0;
    pf[0x301] = 75.0f;
    p[0x302] = 0;
    p[0x303] = 0;
    p[0x304] = 0;
    pf[0x305] = 75.0f;
    p[0x306] = 0;
    p[0x307] = 0;
    p[0x308] = 0;
    pf[0x309] = 120.0f;
    p[0x30A] = 0;
    p[0x30B] = 0;
    pf[0x30C] = 10.0f;
    pf[0x30D] = 0.563750029f;  // D_0049FB28
    pf[0x30E] = 0.765250027f;  // D_0049FB2C
    pf[0x30F] = 0.757250011f;  // D_0049FB30
    pf[0x310] = 0.7755f;  // D_0049FB34
    p[0x311] = 0;
    pf[0x312] = 1.0f;
    pf[0x313] = 1.0f;
    pf[0x314] = 1.0f;
    p[0x315] = 0;
    pf[0x316] = 0.0297500007f;  // D_0049FB24
    pf[0x317] = 0.0297500007f;  // D_0049FB24
    p[0x318] = 0;
    p[0x319] = 0;
    pf[0x31A] = 0.439500004f;  // D_0049FB38
    pf[0x31B] = 0.436250001f;  // D_0049FB3C
    pf[0x31C] = 0.448500007f;  // D_0049FB40
    p[0x31E] = 1;
    pf[0x31F] = 70.0f;
    p[0x31D] = 5;
    p[0x320] = 1;
    pf[0x321] = 20.0f;
    pf[0x322] = 1.10000002f;  // D_0049FB44
    p[0x323] = 0;
    p[0x324] = 0;
    pf[0x325] = 75.0f;
    p[0x326] = 0;
    pf[0x327] = -60.0f;
    pf[0x328] = 172.5f;  // D_0049FB48
    p[0x329] = 0;
    pf[0x32A] = -223.0f;
    p[0x32B] = 0;
    pf[0x32C] = 55.0f;
    pf[0x32D] = 1.0f;
    pf[0x32E] = 0.419999987f;  // D_0049FB4C
    pf[0x32F] = 0.200000003f;  // D_0049FB60
    p[0x330] = 8;
    p[0x331] = 4;
    pf[0x332] = -1.0f;
    pf[0x333] = 1.0f;
    pf[0x334] = 9.99999975e-06f;  // D_0049FB50
    pf[0x335] = 0.00999999978f;  // D_0049FB54
    pf[0x336] = 10.1120005f;  // D_0049FB58
    p[0x337] = 0;
    pf[0x338] = 0.00100000005f;  // D_0049FB5C
    p[0x339] = 0;
    p[0x33A] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    p[0x33D] = 0;
    p[0x33E] = 0;
    p[0x33F] = 0;
    p[0x340] = 0;
    p[0x341] = 0;
    p[0x342] = 0;
    p[0x343] = 0;
    p[0x344] = 0;
    p[0x345] = 0;
    p[0x346] = 0;
    p[0x347] = 0;
    p[0x348] = 0;
    p[0x349] = 0;
    p[0x34A] = 0;
    p[0x34B] = 0;
    p[0x34C] = 0;
    p[0x34D] = 0;
    p[0x34E] = 0;
    p[0x34F] = 0;
    p[0x350] = 0;
    pf[0x351] = 1.0f;
    pf[0x352] = 1.0f;
    pf[0x353] = 0.375750005f;  // D_0049FB6C
    pf[0x354] = 0.219750002f;  // D_0049FB70
    p[0x355] = 0;
    pf[0x356] = 1.0f;
    pf[0x357] = 0.972750008f;  // D_0049FB0C
    p[0x358] = 0;
    p[0x359] = 0;
    pf[0x35A] = 0.0450000018f;  // D_0049FB68
    pf[0x35B] = 0.0450000018f;  // D_0049FB68
    pf[0x35C] = 0.0485000014f;  // D_0049FB74
    p[0x35D] = 0;
    pf[0x35E] = 0.272500008f;  // D_0049FB64
    p[0x35F] = 0;
    p[0x360] = 0;
    p[0x362] = 0;
    p[0x363] = 0;
    p[0x361] = 41;
    p[0x364] = 1;
    pf[0x365] = 20.0f;
    pf[0x366] = 1.20000005f;  // D_0049FB18
    p[0x367] = 0;
    p[0x368] = 0;
    pf[0x369] = 16.25f;
    pf[0x36A] = 3.0f;
    pf[0x36B] = 18.0f;
    p[0x36C] = 0;
    p[0x36D] = 0;
    p[0x36E] = 0;
    p[0x36F] = 0;
    pf[0x370] = 140.0f;
    pf[0x371] = 1.0f;
    pf[0x372] = 1.0f;
    pf[0x373] = 1.0f;
    p[0x374] = 15;
    p[0x375] = 0;
    pf[0x376] = -1.0f;
    pf[0x377] = 1.0f;
    pf[0x378] = 2.0f;
    pf[0x379] = 1.20000005f;  // D_0049FB18
    pf[0x37A] = 2.5f;
    pf[0x37B] = 2.0f;
    p[0x37C] = 0;
    p[0x37D] = 0;
    p[0x37E] = 0;
    p[0x37F] = 0;
    pf[0x380] = 17.75f;
    p[0x381] = 0;
    p[0x382] = 0;
    p[0x383] = 0;
    pf[0x384] = 17.75f;
    p[0x385] = 0;
    p[0x386] = 0;
    p[0x387] = 0;
    p[0x388] = 0;
    pf[0x389] = 87.5f;
    p[0x38A] = 0;
    p[0x38B] = 0;
    p[0x38C] = 0;
    pf[0x38D] = 152.5f;  // D_0049FB78
    p[0x38E] = 0;
    p[0x38F] = 0;
    p[0x390] = 0;
    pf[0x391] = 100.0f;
    p[0x392] = 0;
    p[0x393] = 0;
    pf[0x394] = 10.0f;
    pf[0x395] = 0.575500011f;  // D_0049FB80
    pf[0x396] = 0.661249995f;  // D_0049FB84
    pf[0x397] = 0.648500025f;  // D_0049FB88
    pf[0x398] = 0.668250024f;  // D_0049FB8C
    p[0x399] = 0;
    pf[0x39A] = 0.272500008f;  // D_0049FB64
    pf[0x39B] = 0.272500008f;  // D_0049FB64
    pf[0x39C] = 0.284750015f;  // D_0049FB90
    p[0x39D] = 0;
    pf[0x39E] = 0.0297500007f;  // D_0049FB24
    pf[0x39F] = 0.0297500007f;  // D_0049FB24
    p[0x3A0] = 0;
    p[0x3A1] = 0;
    pf[0x3A2] = 0.245250002f;  // D_0049FB7C
    pf[0x3A3] = 0.245250002f;  // D_0049FB7C
    pf[0x3A4] = 0.266750008f;  // D_0049FB94
    p[0x3A6] = 1;
    pf[0x3A7] = 200.0f;
    p[0x3A5] = 5;
    p[0x3A8] = 1;
    pf[0x3A9] = 20.0f;
    pf[0x3AA] = 1.20000005f;  // D_0049FB18
    p[0x3AB] = 0;
    p[0x3AC] = 0;
    pf[0x3AD] = 75.0f;
    p[0x3AE] = 0;
    pf[0x3AF] = -60.0f;
    pf[0x3B0] = 172.5f;  // D_0049FB48
    p[0x3B1] = 0;
    pf[0x3B2] = -223.0f;
    pf[0x3B3] = 55.0f;
    pf[0x3B4] = 105.0f;
    pf[0x3B5] = 1.0f;
    pf[0x3B6] = 0.5f;
    pf[0x3B7] = 0.300000012f;  // D_0049FB98
    p[0x3B8] = 10;
    p[0x3B9] = 0;
    pf[0x3BA] = -1.0f;
    pf[0x3BB] = 1.0f;
    pf[0x3BC] = 3.52000999f;  // D_0049FB9C
    pf[0x3BD] = 1.20000005f;  // D_0049FB18
    pf[0x3BE] = 2.24000001f;  // D_0049FBA0
    pf[0x3BF] = 2.29999995f;  // D_0049FBA4
    p[0x3C0] = 0;
    p[0x3C1] = 0;
    p[0x3C2] = 0;
    p[0x3C3] = 0;
    pf[0x3C4] = 17.75f;
    p[0x3C5] = 0;
    p[0x3C6] = 0;
    p[0x3C7] = 0;
    pf[0x3C8] = 17.75f;
    p[0x3C9] = 0;
    p[0x3CA] = 0;
    p[0x3CB] = 0;
    p[0x3CC] = 0;
    pf[0x3CD] = 87.5f;
    p[0x3CE] = 0;
    p[0x3CF] = 0;
    p[0x3D0] = 0;
    pf[0x3D1] = 152.5f;  // D_0049FB78
    p[0x3D2] = 0;
    p[0x3D3] = 0;
    p[0x3D4] = 0;
    pf[0x3D5] = 270.0f;
    p[0x3D6] = 0;
    p[0x3D7] = 0;
    pf[0x3D8] = 10.0f;
    pf[0x3D9] = 0.330000013f;  // D_0049FBA8
    pf[0x3DA] = 0.361250013f;  // D_0049FBB4
    pf[0x3DB] = 0.348500013f;  // D_0049FBB8
    pf[0x3DC] = 0.391000003f;  // D_0049FBC4
    p[0x3DD] = 0;
    p[0x3DE] = 0;
    p[0x3DF] = 0;
    p[0x3E0] = 0;
    p[0x3E1] = 0;
    pf[0x3E2] = 0.129500002f;  // D_0049FBAC
    pf[0x3E3] = 0.129500002f;  // D_0049FBAC
    p[0x3E4] = 0;
    p[0x3E5] = 0;
    pf[0x3E6] = 0.445250005f;  // D_0049FBB0
    pf[0x3E7] = 0.445250005f;  // D_0049FBB0
    pf[0x3E8] = 0.466500014f;  // D_0049FBBC
    p[0x3EA] = 1;
    pf[0x3EB] = 300.0f;
    p[0x3E9] = 5;
    p[0x3EC] = 1;
    pf[0x3ED] = 20.0f;
    pf[0x3EE] = 1.10000002f;  // D_0049FB44
    p[0x3EF] = 0;
    p[0x3F0] = 0;
    pf[0x3F1] = 75.0f;
    p[0x3F2] = 0;
    pf[0x3F3] = -60.0f;
    pf[0x3F4] = 200.0f;
    p[0x3F5] = 0;
    pf[0x3F6] = -273.0f;  // D_0049FBC0
    pf[0x3F7] = 105.0f;
    pf[0x3F8] = 140.0f;
    pf[0x3F9] = 1.0f;
    pf[0x3FA] = 1.0f;
    pf[0x3FB] = 0.400000006f;  // D_0049FBC8
    p[0x3FC] = 1;
    p[0x3FD] = 0;
    pf[0x3FE] = -1.0f;
    pf[0x3FF] = 1.0f;
    pf[0x400] = 4.0f;
    pf[0x401] = 1.0f;
    p[0x402] = 0;
    p[0x403] = 0;
    p[0x404] = 0;
    p[0x405] = 0;
    p[0x406] = 0;
    p[0x407] = 0;
    p[0x408] = 0;
    p[0x409] = 0;
    p[0x40A] = 0;
    p[0x40B] = 0;
    p[0x40C] = 0;
    p[0x40D] = 0;
    p[0x40E] = 0;
    p[0x40F] = 0;
    p[0x410] = 0;
    p[0x411] = 0;
    p[0x412] = 0;
    p[0x413] = 0;
    p[0x414] = 0;
    p[0x415] = 0;
    p[0x416] = 0;
    p[0x417] = 0;
    p[0x418] = 0;
    p[0x419] = 0;
    p[0x41A] = 0;
    p[0x41B] = 0;
    p[0x41C] = 0;
    pf[0x41D] = 1.0f;
    pf[0x41E] = 1.0f;
    pf[0x41F] = 1.0f;
    pf[0x420] = 1.0f;
    pf[0x421] = 1.0f;
    pf[0x422] = 1.0f;
    pf[0x423] = 1.0f;
    pf[0x424] = 1.0f;
    p[0x425] = 0;
    p[0x426] = 0;
    p[0x427] = 0;
    p[0x428] = 0;
    p[0x429] = 0;
    p[0x42A] = 0;
    p[0x42B] = 0;
    p[0x42C] = 0;
    p[0x42E] = 1;
    p[0x42F] = 0;
    p[0x42D] = 5;
    p[0x430] = 1;
    pf[0x431] = 20.0f;
    p[0x432] = 0;
    p[0x433] = 0;
    p[0x434] = 0;
    p[0x435] = 0;
    p[0x436] = 0;
    p[0x437] = 0;
    p[0x438] = 0;
    p[0x439] = 0;
    p[0x43A] = 0;
    p[0x43B] = 0;
    pf[0x43C] = 140.0f;
    pf[0x43D] = 1.0f;
    pf[0x43E] = 1.0f;
    pf[0x43F] = 1.0f;
    p[0x440] = 3;
    p[0x441] = 0;
    pf[0x442] = -1.0f;
    pf[0x443] = 1.0f;
    pf[0x444] = 9.21601009f;  // D_0049FBCC
    pf[0x445] = 0.0900100023f;  // D_0049FBD0
    pf[0x446] = 12.4160004f;  // D_0049FBD4
    pf[0x447] = 0.0762500018f;  // D_0049FBD8
    p[0x448] = 0;
    p[0x449] = 0;
    p[0x44A] = 0;
    p[0x44B] = 0;
    pf[0x44C] = 0.100000001f;  // D_0049FB00
    p[0x44D] = 0;
    p[0x44E] = 0;
    p[0x44F] = 0;
    pf[0x450] = 0.100000001f;  // D_0049FB00
    p[0x451] = 0;
    p[0x452] = 0;
    p[0x453] = 0;
    p[0x454] = 0;
    pf[0x455] = 20.0f;
    p[0x456] = 0;
    p[0x457] = 0;
    p[0x458] = 0;
    pf[0x459] = 20.0f;
    p[0x45A] = 0;
    p[0x45B] = 0;
    p[0x45C] = 0;
    pf[0x45D] = 20.0f;
    p[0x45E] = 0;
    p[0x45F] = 0;
    p[0x460] = 0;
    pf[0x461] = 0.454250008f;  // D_0049FBDC
    p[0x462] = 0;
    p[0x463] = 0;
    pf[0x464] = 1.0f;
    p[0x465] = 0;
    pf[0x466] = 1.0f;
    pf[0x467] = 0.627250016f;  // D_0049FBE0
    pf[0x468] = 0.981750011f;  // D_0049FBE4
    p[0x469] = 0;
    p[0x46A] = 0;
    p[0x46B] = 0;
    p[0x46C] = 0;
    p[0x46D] = 0;
    p[0x46E] = 0;
    p[0x46F] = 0;
    p[0x470] = 0;
    p[0x472] = 0;
    p[0x473] = 0;
    p[0x471] = 5;
    p[0x474] = 1;
    pf[0x475] = 20.0f;
    pf[0x476] = 1.20000005f;  // D_0049FB18
    p[0x477] = 0;
    p[0x478] = 0;
    pf[0x479] = 9.0f;
    pf[0x47A] = 6.25f;
    pf[0x47B] = 9.0f;
    p[0x47C] = 0;
    p[0x47D] = 0;
    p[0x47E] = 0;
    p[0x47F] = 0;
    pf[0x480] = 140.0f;
    pf[0x481] = 1.0f;
    pf[0x482] = 0.449999988f;  // D_0049FBE8
    pf[0x483] = 0.239999995f;  // D_0049FBEC
    p[0x484] = 8;
    p[0x485] = 0;
    pf[0x486] = -1.0f;
    pf[0x487] = 1.0f;
    pf[0x488] = 19.3920097f;  // D_0049FBF0
    pf[0x489] = 0.100000001f;  // D_0049FB00
    pf[0x48A] = 36.4160004f;  // D_0049FBF4
    pf[0x48B] = 0.0900000036f;  // D_0049FBF8
    p[0x48C] = 0;
    p[0x48D] = 0;
    p[0x48E] = 0;
    p[0x48F] = 0;
    pf[0x490] = 3.0f;
    p[0x491] = 0;
    p[0x492] = 0;
    p[0x493] = 0;
    pf[0x494] = 3.0f;
    p[0x495] = 0;
    p[0x496] = 0;
    p[0x497] = 0;
    p[0x498] = 0;
    pf[0x499] = 100.0f;
    p[0x49A] = 0;
    p[0x49B] = 0;
    p[0x49C] = 0;
    pf[0x49D] = 100.0f;
    p[0x49E] = 0;
    p[0x49F] = 0;
    p[0x4A0] = 0;
    pf[0x4A1] = 100.0f;
    p[0x4A2] = 0;
    p[0x4A3] = 0;
    p[0x4A4] = 0;
    pf[0x4A5] = 0.460500002f;  // D_0049FBFC
    p[0x4A6] = 0;
    p[0x4A7] = 0;
    p[0x4A8] = 0;
    p[0x4A9] = 0;
    pf[0x4AA] = 1.0f;
    pf[0x4AB] = 1.0f;
    pf[0x4AC] = 1.0f;
    p[0x4AD] = 0;
    pf[0x4AE] = 1.0f;
    p[0x4AF] = 0;
    p[0x4B0] = 0;
    p[0x4B1] = 0;
    p[0x4B2] = 0;
    pf[0x4B3] = 1.0f;
    p[0x4B4] = 0;
    p[0x4B6] = 0;
    pf[0x4B7] = 1.75f;
    p[0x4B5] = 38;
    p[0x4B8] = 1;
    pf[0x4B9] = 20.0f;
    pf[0x4BA] = 1.20000005f;  // D_0049FB18
    p[0x4BB] = 0;
    p[0x4BC] = 0;
    pf[0x4BD] = 36.0f;
    pf[0x4BE] = -15.25f;
    pf[0x4BF] = -12.0f;
    p[0x4C0] = 0;
    p[0x4C1] = 0;
    p[0x4C2] = 0;
    p[0x4C3] = 0;
    pf[0x4C4] = 140.0f;
    pf[0x4C5] = 1.0f;
    pf[0x4C6] = 0.742500007f;  // D_0049FC00
    pf[0x4C7] = 4.25f;
    p[0x4C8] = 3;
    p[0x4C9] = 0;
    pf[0x4CA] = -1.0f;
    pf[0x4CB] = 1.0f;
    pf[0x4CC] = 16.2560101f;  // D_0049FC08
    pf[0x4CD] = 0.272509992f;  // D_0049FC0C
    pf[0x4CE] = 11.9680004f;  // D_0049FC10
    pf[0x4CF] = 0.136250004f;  // D_0049FC14
    p[0x4D0] = 0;
    p[0x4D1] = 0;
    p[0x4D2] = 0;
    p[0x4D3] = 0;
    p[0x4D4] = 0;
    p[0x4D5] = 0;
    pf[0x4D6] = 10.0f;
    pf[0x4D7] = 10.0f;
    pf[0x4D8] = 10.0f;
    p[0x4D9] = 0;
    p[0x4DA] = 0;
    p[0x4DB] = 0;
    p[0x4DC] = 0;
    pf[0x4DD] = 177.5f;  // D_0049FC18
    p[0x4DE] = 0;
    p[0x4DF] = 0;
    p[0x4E0] = 0;
    pf[0x4E1] = 242.5f;  // D_0049FC04
    p[0x4E2] = 0;
    p[0x4E3] = 0;
    p[0x4E4] = 0;
    pf[0x4E5] = 242.5f;  // D_0049FC04
    p[0x4E6] = 0;
    p[0x4E7] = 0;
    pf[0x4E8] = -240.0f;
    pf[0x4E9] = 1.0f;
    pf[0x4EA] = 0.902750015f;  // D_0049FC1C
    pf[0x4EB] = 0.545000017f;  // D_0049FC20
    p[0x4EC] = 0;
    p[0x4ED] = 0;
    pf[0x4EE] = 0.169750005f;  // D_0049FC24
    pf[0x4EF] = 0.00875000004f;  // D_0049FC28
    p[0x4F0] = 0;
    p[0x4F1] = 0;
    p[0x4F2] = 0;
    p[0x4F3] = 0;
    pf[0x4F4] = 0.166500002f;  // D_0049FC2C
    p[0x4F5] = 0;
    pf[0x4F6] = 0.242500007f;  // D_0049FC30
    p[0x4F7] = 0;
    p[0x4F8] = 0;
    p[0x4FA] = 0;
    pf[0x4FB] = 2.4000001f;  // D_0049FC34
    p[0x4F9] = 41;
    p[0x4FC] = 1;
    pf[0x4FD] = 20.0f;
    pf[0x4FE] = 1.5f;
    p[0x4FF] = 0;
    p[0x500] = 0;
    pf[0x501] = 15.25f;
    pf[0x502] = -9.25f;
    p[0x503] = 0;
    p[0x504] = 0;
    p[0x505] = 0;
    p[0x506] = 0;
    p[0x507] = 0;
    pf[0x508] = 140.0f;
    pf[0x509] = 1.0f;
    pf[0x50A] = 1.0f;
    pf[0x50B] = 1.0f;
    p[0x50C] = 3;
    p[0x50D] = 0;
    pf[0x50E] = -1.0f;
    pf[0x50F] = 1.0f;
    pf[0x510] = 9.21601009f;  // D_0049FBCC
    pf[0x511] = 0.0900100023f;  // D_0049FBD0
    pf[0x512] = 12.4160004f;  // D_0049FBD4
    pf[0x513] = 0.0762500018f;  // D_0049FBD8
    p[0x514] = 0;
    p[0x515] = 0;
    p[0x516] = 0;
    p[0x517] = 0;
    pf[0x518] = 0.100000001f;  // D_0049FB00
    p[0x519] = 0;
    p[0x51A] = 0;
    p[0x51B] = 0;
    pf[0x51C] = 0.100000001f;  // D_0049FB00
    p[0x51D] = 0;
    p[0x51E] = 0;
    p[0x51F] = 0;
    p[0x520] = 0;
    pf[0x521] = 20.0f;
    p[0x522] = 0;
    p[0x523] = 0;
    p[0x524] = 0;
    pf[0x525] = 20.0f;
    p[0x526] = 0;
    p[0x527] = 0;
    p[0x528] = 0;
    pf[0x529] = 20.0f;
    p[0x52A] = 0;
    p[0x52B] = 0;
    p[0x52C] = 0;
    pf[0x52D] = 0.454250008f;  // D_0049FBDC
    p[0x52E] = 0;
    p[0x52F] = 0;
    pf[0x530] = 1.0f;
    p[0x531] = 0;
    pf[0x532] = 1.0f;
    pf[0x533] = 0.627250016f;  // D_0049FBE0
    pf[0x534] = 0.981750011f;  // D_0049FBE4
    p[0x535] = 0;
    p[0x536] = 0;
    p[0x537] = 0;
    p[0x538] = 0;
    p[0x539] = 0;
    p[0x53A] = 0;
    p[0x53B] = 0;
    p[0x53C] = 0;
    p[0x53E] = 0;
    p[0x53F] = 0;
    p[0x53D] = 5;
    p[0x540] = 1;
    pf[0x541] = 20.0f;
    pf[0x542] = 1.20000005f;  // D_0049FB18
    p[0x543] = 0;
    p[0x544] = 0;
    pf[0x545] = 9.0f;
    pf[0x546] = -6.25f;
    pf[0x547] = 9.0f;
    p[0x548] = 0;
    p[0x549] = 0;
    p[0x54A] = 0;
    p[0x54B] = 0;
    pf[0x54C] = 140.0f;
    pf[0x54D] = 1.0f;
    pf[0x54E] = 0.472750008f;  // D_0049FC38
    pf[0x54F] = 0.200000003f;  // D_0049FC3C
}
#endif

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

