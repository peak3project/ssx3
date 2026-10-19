#include "common.h"

extern "C" void func_003E6574(void* dst, void* src, int size);

struct sInstanceStruct {
    char pad_0x00[0x8];
    int field_0x8;
    char pad_0xC[0x78 - 0xC];
    void* field_0x78;
};

//100%
INCLUDE_ASM("object/instanceman", cInstanceMan_copyInstance__FPvP15sInstanceStructT0);
#ifdef SKIP_ASM
void cInstanceMan_copyInstance(void* self, sInstanceStruct* a, void* b)
{
    void* saved = a->field_0x78;
    func_003E6574(a, b, 0xA0);
    a->field_0x78 = saved;
    a->field_0x8 |= 0x2000;
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_003512C0);
#ifdef SKIP_ASM
struct sInstHandle {
    unsigned int gen : 8;
    unsigned int index : 24;
};

struct sInstSlot {
    char pad_0x00[0x8];
    int flags;              // 0x08
    char pad_0x0C[0x6C];    // 0x0C
    sInstHandle handle;     // 0x78
    char pad_0x7C[0x34];    // 0x7C
};

struct sInstPool {
    int gen;                // 0x0
    char pad_0x4[0x8];      // 0x4
    sInstSlot* slots;       // 0xC
};

extern "C" sInstSlot* func_003512C0(sInstPool* self, unsigned int handle)
{
    if ((handle & 0xFF) == self->gen) {
        sInstSlot* slot = &self->slots[handle >> 8];
        slot->handle.gen = self->gen;
        slot->handle.index = slot - self->slots;
        slot->flags |= 0x2000;
        return slot;
    }
    return 0;
}
#endif

INCLUDE_ASM("object/instanceman", func_00351330);

//100%
INCLUDE_ASM("object/instanceman", func_00351398);
#ifdef SKIP_ASM
extern "C" void func_00351398(void* self, float* src)
{
    *(float**)((char*)self + 0x40) = src;
    *(float*)((char*)self + 0x44) = src[0];
    *(float*)((char*)self + 0x48) = src[1];
    *(float*)((char*)self + 0x4c) = src[2];
    *(float*)((char*)self + 0x50) = src[3];
    *(float*)((char*)self + 0x54) = src[4];
    *(float*)((char*)self + 0x58) = src[5];
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_003513D0);
#ifdef SKIP_ASM
extern "C" void* func_003E6448(void* dst, int value, int size);

extern "C" void func_003513D0(void* self)
{
    func_003E6448(self, 0, 0x40);
    func_003E6448((char*)self + 0x44, 0, 0x40);
    *(int*)((char*)self + 0x40) = 0;
}
#endif

INCLUDE_ASM("object/instanceman", func_00351410);

INCLUDE_ASM("object/instanceman", func_00351448);

INCLUDE_ASM("object/instanceman", func_00351480);

//100%
INCLUDE_ASM("object/instanceman", func_00351508);
#ifdef SKIP_ASM
// PORT: the original reads *a before checking a for null.
extern "C" float func_00351508(void* self)
{
    float r = 0.0f;
    char** a = *(char***)(*(char**)((char*)self + 0x40) + 0x20);
    char* b = *a;
    if (a != 0 && b != 0) {
        char* c = *(char**)(b + 0x4);
        if (c != 0) {
            r = *(float*)(c + 0x10);
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00351538);
#ifdef SKIP_ASM
struct sImRange;
struct sImRangeTable;
extern "C" sImRange* func_00351A80(sImRangeTable* t, int* cur, float x);

struct sImSeg_351538 {
    float a, b, c, d;
    float lo;
    float hi;
};

struct sImCurve_351538 {
    int count;
    sImSeg_351538* segs;
};

static inline bool inRange_351538(sImSeg_351538* e, float x)
{
    return e->lo <= x && x < e->hi;
}

// PORT: the unit declares func_00351538(void*) for its caller; the body also reads t from $f12
void func_00351538_impl(char* self, float t) __asm__("func_00351538");

void func_00351538_impl(char* self, float t)
{
    sImCurve_351538** curves = *(sImCurve_351538***)(*(char**)(self + 0x40) + 0x20);
    int* cur = (int*)self;
    unsigned int mask = 1;
    float* out = (float*)(self + 0x44);
    for (int i = 0; i < 16; i++) {
        sImCurve_351538* c = *curves;
        if (*(unsigned int*)(*(char**)(self + 0x40) + 0x18) & mask) {
            sImSeg_351538* e = &c->segs[*cur];
            if (!inRange_351538(e, t)) {
                e = (sImSeg_351538*)func_00351A80((sImRangeTable*)c, cur, t);
            }
            *out = ((e->a * t + e->b) * t + e->c) * t + e->d;
            curves++;
            cur++;
        }
        mask <<= 1;
        out++;
    }
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00351660);
#ifdef SKIP_ASM
extern "C" sImRange* func_00351A80(sImRangeTable* t, int* cur, float x);

struct sImSeg_351660 {
    float a, b, c, d;
    float lo;
    float hi;
};

struct sImCurve_351660 {
    int count;
    sImSeg_351660* segs;
};

struct sImV4_351660 {
    float x, y, z, w;
    sImV4_351660() {}
    sImV4_351660(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

static inline bool inRange_351660(sImSeg_351660* e, float x)
{
    return e->lo <= x && x < e->hi;
}

extern "C" void func_00351660(char* self, sImV4_351660* vel, sImV4_351660* rotVel, float t)
{
    float out[16];
    sImCurve_351660** curves = *(sImCurve_351660***)(*(char**)(self + 0x40) + 0x20);
    int* cur = (int*)self;
    int mask = 1;
    float* o = out;
    for (int i = 0; i < 16; i++, mask <<= 1, o++) {
        sImCurve_351660* c = *curves;
        if (*(int*)(*(char**)(self + 0x40) + 0x18) & mask) {
            sImSeg_351660* e = &c->segs[*cur];
            if (!inRange_351660(e, t)) {
                e = (sImSeg_351660*)func_00351A80((sImRangeTable*)c, cur, t);
            }
            curves++;
            cur++;
            *o = e->a * (t * 3.0f) * t + 2.0f * e->b * t + e->c;
        } else {
            *o = 0.0f;
        }
    }
    *vel = sImV4_351660(out[0], out[1], out[2], 0.0f);
    *rotVel = sImV4_351660(-out[3], -out[4], -out[5], 0.0f);
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00351800);
#ifdef SKIP_ASM
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void* func_00351538(void* self);

struct sImInst_351800 {
    char pad_0x0[0x44];
    float t[3];         // 0x44
    float rot[3];       // 0x50
    char pad_0x5c[0x34];
    float m[4][4];      // 0x90
};

extern "C" void func_00351800(sImInst_351800* self)
{
    func_00351538(self);
    float r[3];
    float sc[3][2];
    r[0] = -self->rot[0] * 0.01745329424738884f;
    r[1] = -self->rot[1] * 0.01745329424738884f;
    r[2] = -self->rot[2] * 0.01745329424738884f;
    func_0031BE50(&sc[0][0], &sc[0][1], r[0]);
    func_0031BE50(&sc[1][0], &sc[1][1], r[1]);
    func_0031BE50(&sc[2][0], &sc[2][1], r[2]);
    float sx = sc[0][0];
    float sy = sc[1][0];
    float cx = sc[0][1];
    float sz = sc[2][0];
    float cz = sc[2][1];
    float cy = sc[1][1];
    float sxsy = sx * sy;
    float cxsy = cx * sy;
    float cxsz = cx * sz;
    self->m[0][0] = cy * cz;
    self->m[0][1] = -cy * sz;
    self->m[0][2] = sy;
    self->m[0][3] = 0.0f;
    self->m[1][0] = sxsy * cz + cxsz;
    self->m[1][1] = cx * cz - sxsy * sz;
    self->m[1][2] = -sx * cy;
    self->m[1][3] = 0.0f;
    self->m[2][0] = sx * sz - cxsy * cz;
    self->m[2][1] = cxsz * sy + sx * cz;
    self->m[2][2] = cx * cy;
    self->m[2][3] = 0.0f;
    self->m[3][0] = self->t[0];
    self->m[3][1] = self->t[1];
    self->m[3][2] = self->t[2];
    self->m[3][3] = 1.0f;
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00351948);
#ifdef SKIP_ASM
struct sImMat44 {
    float m[4][4];
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMatIM(sImMat44* d, const sImMat44* a, const sImMat44* b)
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
static inline void vu0CopyMatIM(sImMat44* d, const sImMat44* s)
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

extern "C" void func_00351948(void* self, sImMat44* m)
{
    sImMat44* dst = (sImMat44*)((char*)self + 0x90);
    sImMat44 t2;
    sImMat44 t;
    vu0MulMatIM(&t, m, dst);
    vu0CopyMatIM(&t2, &t);
    vu0CopyMatIM(dst, &t2);
}
#endif

INCLUDE_ASM("object/instanceman", func_00351A10);

extern "C" void* func_00351538(void* self);

//99.29%
INCLUDE_ASM("object/instanceman", func_00351A60__FPv);
#ifdef SKIP_ASM
void* func_00351A60(void* self)
{
    return func_00351538(self);
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00351A80);
#ifdef SKIP_ASM
struct sImRange {
    char pad_0x00[0x10];
    float lo;   // 0x10
    float hi;   // 0x14
};

struct sImRangeTable {
    int count;          // 0x0
    sImRange* entries;  // 0x4
};

static inline bool sImRange_contains(sImRange* e, float x)
{
    return e->lo <= x && x < e->hi;
}

static inline bool sImRange_below(sImRange* e, float x)
{
    return x < e->hi;
}

extern "C" sImRange* func_00351A80(sImRangeTable* t, int* cur, float x)
{
    sImRange* e;
    int i = ++*cur;
    if (i < t->count) {
        e = &t->entries[i];
        if (sImRange_contains(e, x)) {
            return e;
        }
    }
    e = t->entries;
    for (*cur = 0; *cur < t->count - 1; ++*cur, e++) {
        if (sImRange_below(e, x)) {
            return e;
        }
    }
    return e;
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00351B40);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, void* a1, int type, void* def);
extern "C" float func_002D1C70();
extern "C" void func_00352230(void* self);

extern void* D_0048F6D8[];

struct sImV4 {
    float v[4];
    sImV4() {}
    sImV4(const float& x, const float& y, const float& z, const float& w)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
        v[3] = w;
    }
    sImV4(float x, float y, float z)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
        v[3] = 0.0f;
    }
    // placement form for the member arrays (the unit defines the global one further down)
    static void* operator new[](unsigned int, void* p) { return p; }
} __attribute__((aligned(16)));

static inline sImV4 operator*(const sImV4& a, const sImV4& b)
{
    return sImV4(a.v[0] * b.v[0], a.v[1] * b.v[1], a.v[2] * b.v[2], a.v[3] * b.v[3]);
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sImV4 vu0ScaleIM(const sImV4& v, float s)
{
    sImV4 r;
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

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vu0AddIM(sImV4& d, const sImV4& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(d)
        : "m"(d), "m"(b)
        : "memory");
}

// PORT: abs.s helper
static inline float absIM(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

struct sImMtx {
    float m[4][4];
    sImMtx() {}
    sImMtx(const sImMtx& o) { vu0CopyMatIM((sImMat44*)this, (const sImMat44*)&o); }
    sImV4 getRow(int i) const { return *(const sImV4*)m[i]; }
    sImMtx& operator=(const sImMtx& o)
    {
        vu0CopyMatIM((sImMat44*)this, (const sImMat44*)&o);
        return *this;
    }
} __attribute__((aligned(16)));

// parent * (local bone matrix with its translation scaled)
static inline sImMtx mulScaledIM(const sImMtx& parent, const sImMtx& src, const sImV4& s)
{
    sImMtx m;
    *(sImV4*)m.m[0] = src.getRow(0);
    *(sImV4*)m.m[1] = src.getRow(1);
    *(sImV4*)m.m[2] = src.getRow(2);
    *(sImV4*)m.m[3] = src.getRow(3) * s;
    sImMtx r;
    vu0MulMatIM((sImMat44*)&r, (const sImMat44*)&parent, (const sImMat44*)&m);
    return r;
}

struct sImVEntry {
    short delta;
    short index;
    void* (*fn)(void*);
};

struct sImVEntryI {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sImObj {
    char pad_0x00[0xC];
    sImVEntry* vt;
};

struct sImModelInst {
    char pad_0x0[0xC];
    sImObj* owner;        // 0xC
    sImObj* getOwner() { return owner; }
};

struct sImBone {
    int parent;           // 0x0
    char pad_0x4[0x8];
    sImMtx* mtx;          // 0xC
};

struct sImSkel {
    char pad_0x0[0x4];
    int count;            // 0x4
    sImBone* bones;       // 0x8
};

struct sImModel {
    char pad_0x0[0x8];
    unsigned int flags;   // 0x8
    char pad_0xC[0x74];   // 0x10: root matrix
    sImSkel* skel;        // 0x80
    float scale;          // 0x84
};

struct sImWorld3 {
    char pad_0x0[0x8];
    unsigned int** sets;  // 0x8
};

extern "C" sImWorld3** func_002D1BD8();

static inline void* refToPtrIM(unsigned int p)
{
    return (void*)(p << 2);
}

struct sImRef {
    unsigned int id;
    void* get()
    {
        unsigned int* set = (*func_002D1BD8())->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        unsigned int p = (*(unsigned int**)((char*)set + 0x1C))[id >> 8] >> 8;
        if (p == 0) {
            return 0;
        }
        return refToPtrIM(p);
    }
};

struct sImDef {
    char pad_0x0[0x4];
    int f4;               // 0x4
    float f8;             // 0x8
    float fC;             // 0xC
    float f10;            // 0x10
    float a[3];           // 0x14
    float b[3];           // 0x20
    float angle;          // 0x2C
    float f30;            // 0x30
    sImRef model;         // 0x34
    int bone;             // 0x38
};

struct sImPair {
    sImV4 pos;
    sImV4 rot;
};

extern "C" sImPair func_0031B748(sImMtx* m);

struct sImInst {
    char pad_0x00[0xC];
    void* vt;             // 0xC
    char pad_0x10[0x8];
    sImModel* model;      // 0x18
    float f1C;            // 0x1C
    float f20;            // 0x20
    float f24;            // 0x24
    char pad_0x28[0x8];
    sImV4 rot[24];        // 0x30
    sImV4 arr1[24];       // 0x1B0
    char pad_0x330[0x60];
    sImV4 f390;           // 0x390
    sImV4 f3A0;           // 0x3A0
    sImV4 pos[24];        // 0x3B0
    sImV4 arr3[24];       // 0x530
    int f6B0;             // 0x6B0
    float f6B4;           // 0x6B4
};

struct sImSrc {
    char pad_0x00[0x10];
    sImV4 v;              // 0x10
    char pad_0x20[0x10];
    float s;              // 0x30
};

extern "C" sImInst* func_00351B40(sImInst* self, void* a1, void* a2, sImDef* def, sImSrc* src, sImObj* owner)
{
    func_0034FB00(self, a1, 0xB, a2);
    self->vt = D_0048F6D8;
    new (&self->rot) sImV4[24];
    new (&self->arr1) sImV4[24];
    new (&self->pos) sImV4[24];
    new (&self->arr3) sImV4[24];
    self->f6B0 = def->f4;
    self->f1C = def->f10;
    self->f24 = def->f30;
    self->f6B4 = def->f8;
    float rot = def->angle * 0.01745329424738884f;
    self->f20 = rot * func_002D1C70();
    sImSkel* skel = self->model->skel;
    sImMtx local[24];
    sImMtx* mats = local;
    sImObj* obj = owner;
    sImMtx* root = (sImMtx*)((char*)self->model + 0x10);
    if (~def->model.id != 0) {
        sImModelInst* m = (sImModelInst*)def->model.get();
        if (m != 0 && m->getOwner() != 0) {
            obj = m->getOwner();
        }
    }
    if (obj != 0) {
        sImVEntry* e = &obj->vt[24];
        root = (sImMtx*)e->fn((char*)obj + e->delta);
        e = &obj->vt[26];
        if (e->fn((char*)obj + e->delta) != 0) {
            e = &obj->vt[27];
            mats = (sImMtx*)e->fn((char*)obj + e->delta);
            if (def->bone != -1) {
                root = &mats[def->bone];
                mats = local;
            }
        }
    }
    if (mats == local) {
        sImBone* b = skel->bones;
        float s = self->model->scale;
        sImV4 scale(s, s, s, 1.0f);
        for (int i = 0; i < skel->count; i++, b++) {
            if (b->parent != -1) {
                local[i] = mulScaledIM(local[b->parent], *b->mtx, scale);
            } else {
                local[i] = mulScaledIM(*root, *b->mtx, scale);
            }
        }
    }
    for (int i = 0; i < skel->count; i++) {
        sImPair p = func_0031B748(&mats[i]);
        self->rot[i] = p.rot;
        self->pos[i] = p.pos;
    }
    if (owner != 0) {
        sImVEntryI* vt = (sImVEntryI*)owner->vt;
        vt[1].fn((char*)owner + vt[1].delta, 3);
    }
    self->f390 = sImV4(def->a[0], def->a[1], def->a[2]);
    self->f3A0 = sImV4(def->b[0], def->b[1], def->b[2]);
    if (src != 0) {
        vu0AddIM(self->f3A0, vu0ScaleIM(vu0ScaleIM(src->v, absIM(src->s)), def->fC));
    }
    self->model->flags = (self->model->flags & ~2u) | 4u;
    self->model->flags &= ~0x60u;
    func_00352230(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00352168);
#ifdef SKIP_ASM
extern "C" void* cInstanceNode_cInstanceNode(void* self, void* a1, void* stream);
extern void* D_0048F6D8[];

inline void* operator new[](unsigned int, void* p) { return p; }

struct sInstManVEntry2168 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sInstElem2168 {
    float v[4];
    sInstElem2168() {}
};

extern "C" void* func_00352168(void* self, void* a1, void* stream)
{
    cInstanceNode_cInstanceNode(self, a1, stream);
    *(void***)((char*)self + 0xC) = D_0048F6D8;
    new ((char*)self + 0x30) sInstElem2168[24];
    new ((char*)self + 0x1B0) sInstElem2168[24];
    new ((char*)self + 0x330) sInstElem2168[24];
    new ((char*)self + 0x4B0) sInstElem2168[24];
    sInstManVEntry2168* e = &(*(sInstManVEntry2168**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x1C, 0xC);
    *(float*)((char*)self + 0x1C) = -1.0f;
    return self;
}
#endif

extern void* D_0048F6D8[];
extern "C" void* func_0034FBF0(void*);

//100%
INCLUDE_ASM("object/instanceman", func_00352208__FPv);
#ifdef SKIP_ASM
void* func_00352208(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_0048F6D8;
    return func_0034FBF0(self);
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00352230);
#ifdef SKIP_ASM
unsigned int BXrand();
extern char* D_004A5B64;

struct sV4_352230 {
    float x, y, z, w;
    sV4_352230() {}
    sV4_352230(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sDebris_352230 {
    char pad0[0x18];
    char* model;            // 0x18
    float timer;            // 0x1C
    float spinScale;        // 0x20
    char pad24[0xC];
    sV4_352230 rot[24];     // 0x30
    sV4_352230 axis[24];    // 0x1B0
    float spin[24];         // 0x330
    float vmax[4];          // 0x390
    sV4_352230 vbase;       // 0x3A0
    sV4_352230 pos[24];     // 0x3B0
    sV4_352230 vel[24];     // 0x530
};

static inline float randf_352230()
{
    union {
        int i;
        float f;
    } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

static inline float randRange_352230(float lo, float hi)
{
    return randf_352230() * (hi - lo) + lo;
}

static inline float randScale_352230(float s)
{
    return s * randf_352230();
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sV4_352230 Normalize_352230(const sV4_352230& v)
{
    sV4_352230 r;
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_352230 Scale_352230(const sV4_352230& v, float s)
{
    sV4_352230 r;
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

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void AddEq_352230(sV4_352230& d, const sV4_352230& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(d)
        : "m"(d), "m"(b)
        : "memory");
}

extern "C" void func_00352230(void* p)
{
    sDebris_352230* self = (sDebris_352230*)p;
    char* g = *(char**)(self->model + 0x80);
    for (int i = 0; i < *(int*)(g + 4); i++) {
        self->spin[i] = self->spinScale * randRange_352230(0.5f, 1.0f);
        self->axis[i] = sV4_352230(randRange_352230(-1.0f, 1.0f), randRange_352230(-1.0f, 1.0f), randRange_352230(-1.0f, 1.0f), 0.0f);
        self->axis[i] = Normalize_352230(self->axis[i]);
    }
    for (int j = 0; j < *(int*)(g + 4); j++) {
        float vx = randScale_352230(self->vmax[0]) * (1.0f / (float)*(int*)(D_004A5B64 + 0x10));
        if (BXrand() & 1) {
            vx = -vx;
        }
        float vy = randScale_352230(self->vmax[1]) * (1.0f / (float)*(int*)(D_004A5B64 + 0x10));
        if (BXrand() & 1) {
            vy = -vy;
        }
        float vz = randScale_352230(self->vmax[2]) * (1.0f / (float)*(int*)(D_004A5B64 + 0x10));
        self->vel[j] = Scale_352230(self->vbase, *(float*)(D_004A5B64 + 0x14));
        AddEq_352230(self->vel[j], sV4_352230(vx, vy, vz, 0.0f));
    }
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00352500);
#ifdef SKIP_ASM
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern char* D_004A5B64;

struct sV4_352500 {
    float x, y, z, w;
    sV4_352500() {}
    sV4_352500(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sQ_352500 : sV4_352500 {
    sQ_352500(float aw, float ax, float ay, float az) { w = aw; x = ax; y = ay; z = az; }
};

struct sVE_352500 { short delta; short index; void (*fn)(void*, int); };

struct sDebris_352500 {
    char pad0[0xC];
    sVE_352500* vt;         // 0xC
    char pad10[0x8];
    char* model;            // 0x18
    float timer;            // 0x1C
    char pad20[0x10];
    sV4_352500 rot[24];     // 0x30
    sV4_352500 axis[24];    // 0x1B0
    float spin[24];         // 0x330
    char pad390[0x20];
    sV4_352500 pos[24];     // 0x3B0
    sV4_352500 vel[24];     // 0x530
    int state;              // 0x6B0
    float gravity;          // 0x6B4
};

// PORT: PS2-only VU0 inline asm (quaternion multiply).
static inline sV4_352500 QMul_352500(const sV4_352500& a, const sV4_352500& b)
{
    sV4_352500 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vmul.xyzw $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w  ACC, $vf7, $vf7x\n"
        "vmsubay.w ACC, $vf0, $vf7y\n"
        "vmsubz.w  $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place normalize via rsqrt).
static inline void NormalizeEq_352500(sV4_352500& v)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v)
        :
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void AddEq_352500(sV4_352500& d, const sV4_352500& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(d)
        : "m"(d), "m"(b)
        : "memory");
}

extern "C" void func_00352500(sDebris_352500* self)
{
    if (self->timer > 0.0f) {
        self->timer -= *(float*)(D_004A5B64 + 0x14);
        if (self->timer <= 0.0f) {
            self->vt[34].fn((char*)self + self->vt[34].delta, 1);
            return;
        }
    }
    if (self->timer > 0.0f) {
        char* g = *(char**)(self->model + 0x80);
        for (int i = 0; i < *(int*)(g + 4); i++) {
            float s, c;
            func_0031BE50(&s, &c, self->spin[i] * 0.5f);
            sV4_352500* q = &self->rot[i];
            *q = QMul_352500(*q, sQ_352500(c, s * self->axis[i].x, s * self->axis[i].y, s * self->axis[i].z));
            NormalizeEq_352500(*q);
        }
        for (int i = 0; i < *(int*)(g + 4); i++) {
            AddEq_352500(self->pos[i], self->vel[i]);
            AddEq_352500(self->vel[i], sV4_352500(0.0f, 0.0f, self->gravity * -980.0f * *(float*)(D_004A5B64 + 0x14), 0.0f));
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00352708);
#ifdef SKIP_ASM
struct sInstanceManVEntry2708 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

int func_0034FCC0(void* self);
extern "C" void func_0034FE28(void* self);

extern "C" void func_00352708(void* self, int check)
{
    if (check != 0 && func_0034FCC0(self) != 0) {
        return;
    }
    if (*(int*)((char*)self + 0x6B0) == 0) {
        func_0034FE28(self);
    }
    if (*(int*)((char*)self + 0x6B0) == 2 && self != 0) {
        sInstanceManVEntry2708* vt = *(sInstanceManVEntry2708**)((char*)self + 0xC);
        vt[1].fn((char*)self + vt[1].delta, 3);
    }
}
#endif

//100%
INCLUDE_ASM("object/instanceman", func_00352780);
#ifdef SKIP_ASM
extern "C" void func_0034FE28(void* self);

struct sInstManVEntry2780 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00352780(void* self)
{
    if (*(int*)((char*)self + 0x6B0) != 0) {
        *(int*)(*(char**)((char*)self + 0x18) + 0x8) &= 0xFFFF0300;
        *(int*)(*(char**)((char*)self + 0x18) + 0x8) |= *(int*)(*(char**)((char*)self + 0x18) + 0x8) >> 16;
        *(int*)(*(char**)((char*)self + 0x18) + 0x8) |= 2;
        if (self != 0) {
            sInstManVEntry2780* vt = *(sInstManVEntry2780**)((char*)self + 0xC);
            vt[1].fn((char*)self + vt[1].delta, 3);
        }
    } else {
        func_0034FE28(self);
    }
}
#endif

INCLUDE_ASM("object/instanceman", func_00352810);

//100%
INCLUDE_ASM("object/instanceman", func_00352A58);
#ifdef SKIP_ASM
struct sSerVEntry_00352A58 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0034FE90(void* self, void* stream);

extern "C" void func_00352A58(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sSerVEntry_00352A58* vt = *(sSerVEntry_00352A58**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x1C, 0xC);
}
#endif

