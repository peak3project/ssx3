#include "common.h"

//100%
INCLUDE_ASM("object/spring", cSpring_setupNodes);
#ifdef SKIP_ASM
struct sSpVec_53EF0 {
    float x, y, z, w;
    sSpVec_53EF0() {}
    sSpVec_53EF0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sSpNode_53EF0 {
    sSpVec_53EF0 p;         // 0x00
    sSpVec_53EF0 v;         // 0x10
    float a;                // 0x20
    float av;               // 0x24
    int pad28[2];           // 0x28
    sSpVec_53EF0 f;         // 0x30
    float t;                // 0x40
    int pad44[3];           // 0x44
};

struct sSpring_53EF0 {
    int n;                  // 0x00
    float k;                // 0x04
    float damp;             // 0x08
    float c;                // 0x0C
    float e;                // 0x10
    int pad14[2];           // 0x14
    float rest;             // 0x1C
    float scale;            // 0x20
    sSpNode_53EF0* nodes;   // 0x24
};

// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_0048E9C8[];
extern sSpVec_53EF0 D_004FF120_53EF0 __asm__("D_004FF120");
extern "C" void cSpring_setupNodes(sSpring_53EF0* s)
{
    int i;
    sSpNode_53EF0** dst = &s->nodes;
    *dst = new (D_0048E9C8, 0x20000000, 0) sSpNode_53EF0[s->n];
    sSpNode_53EF0* nd = s->nodes;
    for (i = 0; i < s->n; i++, nd++) {
        nd->p = D_004FF120_53EF0;
        nd->v = D_004FF120_53EF0;
        nd->f = D_004FF120_53EF0;
        nd->av = 0;
        nd->a = 0;
        nd->t = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/spring", func_00353FC0);
#ifdef SKIP_ASM
struct sSpVec_53FC0 {
    float x, y, z, w;
    sSpVec_53FC0() {}
    sSpVec_53FC0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sSpNode_53FC0 {
    sSpVec_53FC0 p;         // 0x00
    sSpVec_53FC0 v;         // 0x10
    float a;                // 0x20
    float av;               // 0x24
    int pad28[2];           // 0x28
    sSpVec_53FC0 f;         // 0x30
    float t;                // 0x40
    int pad44[3];           // 0x44
};

struct sSpring_53FC0 {
    int n;                  // 0x00
    float k;                // 0x04
    float damp;             // 0x08
    float c;                // 0x0C
    float e;                // 0x10
    int pad14[2];           // 0x14
    float rest;             // 0x1C
    float scale;            // 0x20
    sSpNode_53FC0* nodes;   // 0x24
};

extern char* D_004A5B64;
extern sSpVec_53FC0 D_004FF120_sp __asm__("D_004FF120");

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sSpVec_53FC0 spSub_53FC0(const sSpVec_53FC0& a, const sSpVec_53FC0& b)
{
    sSpVec_53FC0 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sSpVec_53FC0 spAdd_53FC0(const sSpVec_53FC0& a, const sSpVec_53FC0& b)
{
    sSpVec_53FC0 r;
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

// PORT: PS2-only VU0 inline asm (in-place vector add).
static inline void spAddEq_53FC0(sSpVec_53FC0& a, const sSpVec_53FC0& b)
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sSpVec_53FC0 spScale_53FC0(const sSpVec_53FC0& v, float s)
{
    sSpVec_53FC0 r;
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

// PORT: PS2-only VU0 inline asm (scalar times vector).
static inline sSpVec_53FC0 spScaleF_53FC0(float s, const sSpVec_53FC0& v)
{
    sSpVec_53FC0 r;
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

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void spScaleEq_53FC0(sSpVec_53FC0& v, float s)
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

// PORT: PS2-only VU0 inline asm (vector divided by scalar).
static inline sSpVec_53FC0 spDiv_53FC0(const sSpVec_53FC0& v, float s)
{
    sSpVec_53FC0 r;
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float spLength_53FC0(const sSpVec_53FC0& v)
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

extern "C" void func_00353FC0(sSpring_53FC0* self)
{
    sSpVec_53FC0 g(0.0f, 0.0f, -980.0f, 0.0f);
    float dt = 1.0f / (float)*(int*)(D_004A5B64 + 0x10);
    sSpVec_53FC0 F[16];
    float T[16];
    F[0] = F[self->n - 1] = D_004FF120_sp;
    T[0] = T[self->n - 1] = 0.0f;
    for (int i = 1; i < self->n - 1; i++) {
        sSpVec_53FC0 d1 = spSub_53FC0(self->nodes[i - 1].p, self->nodes[i].p);
        sSpVec_53FC0 d2 = spSub_53FC0(self->nodes[i + 1].p, self->nodes[i].p);
        spScaleEq_53FC0(d1, 1.0f - self->rest * self->scale / spLength_53FC0(d1));
        spScaleEq_53FC0(d2, 1.0f - self->rest * self->scale / spLength_53FC0(d2));
        F[i] = spScaleF_53FC0(self->k, spAdd_53FC0(d1, d2));
        spAddEq_53FC0(F[i], spScaleF_53FC0(dt * self->k, spSub_53FC0(spAdd_53FC0(self->nodes[i - 1].v, self->nodes[i + 1].v), spScale_53FC0(self->nodes[i].v, 2.0f))));
        // PORT: pointer arithmetic in int (only form that gives the target's index-first addu and
        // signed -0x30 offsets; g++ 2.95 turns nd[-1] into an unsigned 0xFFFFFFB0 offset).
        sSpNode_53FC0* nd = (sSpNode_53FC0*)(i * 0x50 + (int)self->nodes);
        T[i] = self->c * (((sSpNode_53FC0*)((int)nd - 0x50))->a - nd->a + nd[1].a - nd->a);
        T[i] += dt * self->c * (((sSpNode_53FC0*)((int)nd - 0x50))->av + nd[1].av - nd->av * 2.0f);
        spAddEq_53FC0(F[i], spAdd_53FC0(spScale_53FC0(nd->v, -self->damp), g));
        T[i] += -self->e * self->nodes[i].av;
    }
    for (int i = 1; i < self->n - 1; i++) {
        spAddEq_53FC0(F[i], self->nodes[i].f);
        T[i] += self->nodes[i].t;
    }
    for (int i = 1; i < self->n - 1; i++) {
        sSpVec_53FC0 v = spAdd_53FC0(spScale_53FC0(F[i], dt), spDiv_53FC0(spScaleF_53FC0(dt * dt * dt * self->k, spAdd_53FC0(F[i - 1], F[i + 1])), dt * dt * 2.0f * self->k + 1.0f));
        v = spDiv_53FC0(v, dt * dt * 2.0f * self->k + 1.0f);
        spAddEq_53FC0(self->nodes[i].v, v);
        spAddEq_53FC0(self->nodes[i].p, spScale_53FC0(self->nodes[i].v, dt));
        self->nodes[i].av += (dt * T[i] + dt * dt * dt * self->c * (T[i - 1] + T[i + 1]) / (dt * dt * 2.0f * self->c + 1.0f)) / (dt * dt * 2.0f * self->c + 1.0f);
        self->nodes[i].a += dt * self->nodes[i].av;
    }
    for (int i = 0; i < self->n; i++) {
        self->nodes[i].f = D_004FF120_sp;
        self->nodes[i].t = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("object/spring", func_003545D8);
#ifdef SKIP_ASM
struct sSpringVEntry45D8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_003545D8(void* self, void* stream)
{
    sSpringVEntry45D8* e = &(*(sSpringVEntry45D8**)stream)[1];
    e->fn((char*)stream + e->delta, self, 0x24);
    e = &(*(sSpringVEntry45D8**)stream)[1];
    e->fn((char*)stream + e->delta, *(void**)((char*)self + 0x24), *(int*)self * 0x50);
}
#endif

//100%
INCLUDE_ASM("object/spring", func_00354648);
#ifdef SKIP_ASM
extern "C" void cBucketMan_add(void* mgr, void* node, void* param);
extern void* D_00491F00[16];
extern char D_004A5988;

struct cObjNode {
    char pad_0x00[0xC];
    void* field_0xC;
};

extern "C" cObjNode* func_00354648(cObjNode* self, void* param2)
{
    self->field_0xC = D_00491F00;
    cBucketMan_add(&D_004A5988, self, param2);
    return self;
}
#endif

