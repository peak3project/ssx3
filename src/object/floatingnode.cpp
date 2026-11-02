#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void cInstanceNode_getBoundBoxInfo(void* self, void* out);
extern const char D_0048E890[];

struct cFloatingNode {
    char pad_0x00[0x78];
    void* field_0x78;
};

//100%
INCLUDE_ASM("object/floatingnode", cFloatingNode_initInfo__FP13cFloatingNode);
#ifdef SKIP_ASM
// PORT: the unit declares cInstanceNode_getBoundBoxInfo with 2 args; its body uses 3 ($6 is written).
void cInstanceNode_getBoundBoxInfo_3(void* self, void* box, void* out) __asm__("cInstanceNode_getBoundBoxInfo");

void cFloatingNode_initInfo(cFloatingNode* self)
{
    void* mem = cMemMan_alloc(0x30, D_0048E890, 0x20000000, 0);
    self->field_0x78 = mem;
    cInstanceNode_getBoundBoxInfo_3(self, mem, (char*)mem + 0x20);
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034EF08);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_0034EF08(cFloatingNode* self)
{
    if (self->field_0x78 != 0) {
        operator_delete((int*)self->field_0x78);
        self->field_0x78 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034EF40);
#ifdef SKIP_ASM
struct sBox_F048;
extern "C" void* func_002D1BE0();
extern "C" void func_003291E0(void* world, int type, void* id, sBox_F048* box, sBox_F048* old);
extern "C" void func_003568B0(void* self);

struct sFlVec4_34EF40 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sFlBox_34EF40 {
    sFlVec4_34EF40 min;
    sFlVec4_34EF40 max;
};

struct sFlInfo_34EF40 {
    sFlBox_34EF40 box;
    float radius;
};

// PORT: PS2-only VU0 inline asm (a - b).
static inline sFlVec4_34EF40 vu0Sub_34EF40(const sFlVec4_34EF40& a, const sFlVec4_34EF40& b)
{
    sFlVec4_34EF40 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sFlVec4_34EF40 vu0Add_34EF40(const sFlVec4_34EF40& a, const sFlVec4_34EF40& b)
{
    sFlVec4_34EF40 r;
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

struct sFlVEntry_34EF40 {
    short delta;
    short index;
    char* (*fn)(void*);
};

static inline sFlVec4_34EF40 nodePos_34EF40(char* self)
{
    sFlVEntry_34EF40* vt = *(sFlVEntry_34EF40**)(self + 0xC);
    return *(sFlVec4_34EF40*)(vt[24].fn(self + vt[24].delta) + 0x30);
}

extern "C" void func_0034EF40(char* self)
{
    sFlInfo_34EF40* info = *(sFlInfo_34EF40**)(self + 0x78);
    if (info != 0) {
        sFlBox_34EF40 nb;
        sFlBox_34EF40 old = info->box;
        float r = info->radius;
        sFlVec4_34EF40 ext;
        ext.x = r;
        ext.y = r;
        ext.z = r;
        ext.w = 0.0f;
        nb.min = vu0Sub_34EF40(nodePos_34EF40(self), ext);
        nb.max = vu0Add_34EF40(nodePos_34EF40(self), ext);
        (*(sFlInfo_34EF40**)(self + 0x78))->box = nb;
        void* id = *(void**)(self + 0x18);
        func_003291E0(func_002D1BE0(), 0, id, (sBox_F048*)&nb, (sBox_F048*)&old);
    } else {
        func_003568B0(self);
    }
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034F048);
#ifdef SKIP_ASM
struct sVec4_F048 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBox_F048 {
    sVec4_F048 min;
    sVec4_F048 max;
};

struct sInst_F048 {
    char pad_0x00[0x60];
    float min[3];   // 0x60
    float max[3];   // 0x6C
};

extern "C" void* func_002D1BE0();
extern "C" void func_003291E0(void* world, int type, void* id, sBox_F048* box, sBox_F048* old);
extern "C" void func_003567E0(void* self);

extern "C" void func_0034F048(cFloatingNode* self)
{
    sBox_F048* info = (sBox_F048*)self->field_0x78;
    if (info != 0) {
        sBox_F048 nb;
        sBox_F048 old = *info;
        sInst_F048* inst = *(sInst_F048**)((char*)self + 0x18);
        sVec4_F048 t;
        t.x = inst->min[0];
        t.y = inst->min[1];
        t.z = inst->min[2];
        t.w = 1.0f;
        nb.min = t;
        t.x = inst->max[0];
        t.y = inst->max[1];
        t.z = inst->max[2];
        nb.max = t;
        *info = nb;
        void* id = *(void**)((char*)self + 0x18);
        func_003291E0(func_002D1BE0(), 0, id, &nb, &old);
        func_0034EF08(self);
    } else {
        func_003567E0(self);
    }
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034F120);
#ifdef SKIP_ASM
struct sV4_F120 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat_F120 {
    sV4_F120 r[4];
};

struct sPart_F120 {
    int parent;
    int pad4;
    int pad8;
    sMat_F120* mat;     // 0xC
};

struct sModel_F120 {
    int pad0;
    int count;          // 0x4
    sPart_F120* parts;  // 0x8
};

struct sInst_F120 {
    char pad_0x00[0x80];
    sModel_F120* model; // 0x80
    float scale;        // 0x84
};

struct sFlBase_F120 {
    char pad_0x00[0x28];
    float f28;
    char pad_0x2C[0xC];
    float f38;
};

struct sFloat_F120 {
    char pad_0x00[0x12];
    unsigned short flags;   // 0x12
    char pad_0x14[0x4];
    sInst_F120* inst;       // 0x18
    char pad_0x1C[0x34];
    float f50;              // 0x50
};

extern "C" void func_0031BE50(float* s, float* c, float angle);

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMat_F120(sMat_F120* d, const sMat_F120* a, const sMat_F120* b)
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
static inline void vu0CopyMat_F120(sMat_F120* d, const sMat_F120* s)
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

static inline sV4_F120 row_F120(const sMat_F120* m, int i)
{
    return m->r[i];
}

static inline void mulv_F120(sV4_F120& r, const sV4_F120& a, const sV4_F120& b)
{
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    r.w = a.w * b.w;
}

// Builds a part matrix: dst = parent * (local with its translation row scaled by s).
static inline void partMat_F120(sMat_F120* dst, const sMat_F120* parentMat, const sMat_F120* m, const sV4_F120& s)
{
    sMat_F120 l;
    l.r[0] = row_F120(m, 0);
    l.r[1] = row_F120(m, 1);
    l.r[2] = row_F120(m, 2);
    sV4_F120 t;
    sV4_F120 r3 = m->r[3];
    mulv_F120(t, r3, s);
    l.r[3] = t;
    sMat_F120 tt;
    vu0MulMat_F120(&tt, parentMat, &l);
    vu0CopyMat_F120(dst, &tt);
}

extern "C" void func_0034F120(sFloat_F120* self, sMat_F120* world, sMat_F120* out)
{
    sMat_F120 M;
    sFlBase_F120* b = (sFlBase_F120*)((char*)self + 0x2C);
    sV4_F120 pos = world->r[3];
    sV4_F120 t;
    t.x = 0.0f;
    t.y = 0.0f;
    t.z = self->f50 - pos.z;
    float r[3];
    r[0] = b->f28;
    r[1] = b->f38;
    r[2] = 0.0f;
    float sx, cx, sy, cy, sz, cz;
    func_0031BE50(&sx, &cx, r[0]);
    func_0031BE50(&sy, &cy, r[1]);
    func_0031BE50(&sz, &cz, r[2]);
    float sxsy = sx * sy;
    float cxsy = cx * sy;
    float cxsz = cx * sz;
    M.r[0].x = cy * cz;
    M.r[0].y = -cy * sz;
    M.r[0].z = sy;
    M.r[0].w = 0.0f;
    M.r[1].x = sxsy * cz + cxsz;
    M.r[1].y = cx * cz - sxsy * sz;
    M.r[1].z = -sx * cy;
    M.r[1].w = 0.0f;
    M.r[2].x = sx * sz - cxsy * cz;
    M.r[2].y = cxsz * sy + sx * cz;
    M.r[2].z = cx * cy;
    M.r[2].w = 0.0f;
    M.r[3].x = t.x;
    M.r[3].y = t.y;
    M.r[3].z = t.z;
    M.r[3].w = 1.0f;
    sInst_F120* inst = self->inst;
    sModel_F120* model = inst->model;
    sPart_F120* p = model->parts;
    float k = inst->scale;
    sV4_F120 s;
    s.x = k;
    s.y = k;
    s.z = k;
    s.w = 1.0f;
    sMat_F120 t2;
    for (int i = 0; i < model->count; i++, p++) {
        int parent = p->parent;
        if (parent != -1) {
            partMat_F120(&t2, &out[parent], p->mat, s);
            vu0CopyMat_F120(&out[i], &t2);
        } else {
            sMat_F120 w;
            sMat_F120 tt;
            vu0MulMat_F120(&tt, world, &M);
            vu0CopyMat_F120(&w, &tt);
            partMat_F120(&t2, &w, p->mat, s);
            vu0CopyMat_F120(&out[i], &t2);
        }
    }
    self->flags &= ~1;
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034F600);
#ifdef SKIP_ASM
struct sV4_F600 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sV4_F600 D_004FF140_F600[] __asm__("D_004FF140");
extern sV4_F600 D_004FF150_F600[] __asm__("D_004FF150");

// PORT: PS2-only VU0 inline asm (a - b).
static inline sV4_F600 vu0Sub_F600(const sV4_F600& a, const sV4_F600& b)
{
    sV4_F600 r;
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

static inline sV4_F600 pos_F600(sV4_F600* m)
{
    return m[3];
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector).
static inline sV4_F600 vu0MtxMul_F600(const sV4_F600* m, const sV4_F600* v)
{
    sV4_F600 r;
    __asm__(
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        : "=m"(r)
        : "o"(*v), "r"(m)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sV4_F600 vu0Cross_F600(const sV4_F600& a, const sV4_F600& b)
{
    sV4_F600 r;
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_F600(const sV4_F600& a, const sV4_F600& b)
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

struct sFlVE_F600 {
    short delta;
    short index;
    sV4_F600* (*fn)(void*);
};

struct sFloat_F600 {
    char pad_0x00[0xC];
    sFlVE_F600* vt;     // 0x0C
    char pad_0x10[0x34];
    float f44;
    char pad_0x48[0x18];
    float f60;
    char pad_0x64[0xC];
    float f70;
};

extern "C" void func_0034F600(sFloat_F600* self, sV4_F600* a, sV4_F600* b)
{
    sFlVE_F600* vt = self->vt;
    sV4_F600* m = vt[24].fn((char*)self + vt[24].delta);
    sV4_F600 d = vu0Sub_F600(a[0], pos_F600(m));
    sV4_F600 u = vu0MtxMul_F600(m, &D_004FF140_F600[0]);
    sV4_F600 v = vu0MtxMul_F600(m, &D_004FF150_F600[0]);
    self->f44 += vu0Dot_F600(*b, a[1]);
    sV4_F600 c = vu0Cross_F600(*b, d);
    self->f60 += vu0Dot_F600(c, u);
    self->f70 += vu0Dot_F600(c, v);
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034F790);
#ifdef SKIP_ASM
struct sV4_F790 {
    float x, y, z, w;
    sV4_F790() {}
    sV4_F790(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

extern sV4_F790 D_004FF140_F790[] __asm__("D_004FF140");
extern sV4_F790 D_004FF150_F790[] __asm__("D_004FF150");
extern "C" void func_00356AE0(void* self, void* a);

// PORT: PS2-only VU0 inline asm (a - b).
static inline sV4_F790 vu0Sub_F790(const sV4_F790& a, const sV4_F790& b)
{
    sV4_F790 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sV4_F790 vu0Add_F790(const sV4_F790& a, const sV4_F790& b)
{
    sV4_F790 r;
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

// PORT: PS2-only VU0 inline asm (a += b).
static inline void vu0AddEq_F790(sV4_F790& a, const sV4_F790& b)
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

static inline sV4_F790 pos_F790(sV4_F790* m)
{
    return m[3];
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sV4_F790 vu0Scale_F790(const sV4_F790& v, float s)
{
    sV4_F790 r;
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

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector).
static inline sV4_F790 vu0MtxMul_F790(const sV4_F790* m, const sV4_F790* v)
{
    sV4_F790 r;
    __asm__(
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        : "=m"(r)
        : "o"(*v), "r"(m)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sV4_F790 vu0Cross_F790(const sV4_F790& a, const sV4_F790& b)
{
    sV4_F790 r;
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

struct sFlVE_F790 {
    short delta;
    short index;
    sV4_F790* (*fn)(void*);
};

struct sFlBase_F790 {
    char pad_0x00[0x1C];
    float f1C;
    char pad_0x20[0x10];
    float f30;
    char pad_0x34[0xC];
    float f40;
};

struct sFloat_F790 {
    char pad_0x00[0xC];
    sFlVE_F790* vt;     // 0x0C
};

extern "C" void func_0034F790(sFloat_F790* self, sV4_F790* a)
{
    func_00356AE0(self, a);
    sFlVE_F790* vt = self->vt;
    sV4_F790* m = vt[24].fn((char*)self + vt[24].delta);
    sFlBase_F790* b = (sFlBase_F790*)((char*)self + 0x2C);
    sV4_F790 d = vu0Sub_F790(a[0], pos_F790(m));
    sV4_F790 u = vu0MtxMul_F790(m, &D_004FF140_F790[0]);
    sV4_F790 v = vu0MtxMul_F790(m, &D_004FF150_F790[0]);
    sV4_F790 s = vu0Add_F790(vu0Scale_F790(u, b->f30), vu0Scale_F790(v, b->f40));
    vu0AddEq_F790(a[2], vu0Add_F790(sV4_F790(0.0f, 0.0f, b->f1C, 0.0f), vu0Cross_F790(d, s)));
    vu0AddEq_F790(a[3], s);
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034F930);
#ifdef SKIP_ASM
extern char* D_004A5B64;

// The tilt clamp reads the angles through a view of the spring block at +0x2C.
struct sFloatTilt_34F930 {
    char pad0[0x28];
    float pos2;         // 0x54
    char pad2C[0x38 - 0x2C];
    float pos3;         // 0x64
};

struct sFloatingNode_34F930 {
    char pad0[0x12];
    unsigned short flags;           // 0x12
    char pad14[0x2C - 0x14];
    float k;            // 0x2C
    float damp;         // 0x30
    float gain;         // 0x34
    float k2;           // 0x38
    float damp2;        // 0x3C
    float gain2;        // 0x40
    float in1;          // 0x44
    float vel1;         // 0x48
    float rest1;        // 0x4C
    float pos1;         // 0x50
    float pos2;         // 0x54
    float pad58;
    float vel2;         // 0x5C
    float in2;          // 0x60
    float pos3;         // 0x64
    float pad68;
    float vel3;         // 0x6C
    float in3;          // 0x70
};

// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
// Steps the float spring (bob height plus two tilt axes) by one frame.
static inline float clamp_34F930(float v, float lo, float hi) { return v >= lo ? v <? hi : lo; }
extern "C" int func_0034F930(sFloatingNode_34F930* self)
{
    float dt = 1.0f / (float)*(int*)(D_004A5B64 + 0x10);
    float a1 = -self->k * (self->pos1 - self->rest1) + self->gain * self->in1 + -self->damp * self->vel1;
    float a2 = -self->k2 * self->pos2 + self->gain2 * self->in2 + -self->damp2 * self->vel2;
    float a3 = -self->k2 * self->pos3 + self->gain2 * self->in3 + -self->damp2 * self->vel3;
    self->pos1 += self->vel1 * dt;
    self->vel1 += a1 * dt;
    self->pos2 += self->vel2 * dt;
    self->vel2 += a2 * dt;
    self->pos3 += self->vel3 * dt;
    self->vel3 += a3 * dt;
    sFloatTilt_34F930* t = (sFloatTilt_34F930*)&self->k;
    // +-80 degrees
    self->pos2 = clamp_34F930(t->pos2, -1.3962635f, 1.3962635f);
    self->pos3 = clamp_34F930(t->pos3, -1.3962635f, 1.3962635f);
    self->in1 = 0.0f;
    self->in2 = 0.0f;
    self->in3 = 0.0f;
    self->flags |= 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034FA88);
#ifdef SKIP_ASM
struct sFloatingVEntryFA88 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00356B30(void* self, void* stream);

extern "C" void func_0034FA88(cFloatingNode* self, void* stream)
{
    int has;
    func_00356B30(self, stream);
    has = self->field_0x78 != 0;
    sFloatingVEntryFA88* e = &(*(sFloatingVEntryFA88**)stream)[1];
    e->fn((char*)stream + e->delta, &has, 4);
    e = &(*(sFloatingVEntryFA88**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x2C, 0x48);
}
#endif

//100%
INCLUDE_ASM("object/floatingnode", func_0034FB00);
#ifdef SKIP_ASM
extern "C" void* func_00354850(void* self, void* a1, int type);
extern "C" void func_0034FC78(void* self, void* node);
extern "C" void func_002D1BF0(void* node);
extern char D_00491C80[];

extern "C" void* func_0034FB00(void* self, void* a1, int type, void* node)
{
    func_00354850(self, a1, type);
    *(void**)((char*)self + 0x18) = node;
    *(void**)((char*)self + 0xC) = D_00491C80;
    func_0034FC78(self, node);
    if ((*(int*)((char*)node + 0x8) & 0x100) == 0) {
        if (type != 6 && type != 0x10 && type != 0x16) {
            func_002D1BF0(node);
        }
    }
    return self;
}
#endif

