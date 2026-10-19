#include "common.h"

//100%
INCLUDE_ASM("object/instancenode", cInstanceNode_cInstanceNode);
#ifdef SKIP_ASM
struct sInstNodeCtorVEntry {
    short delta;
    short index;
    int (*fn)(void*, void*);
};

extern "C" void* cSortObjNode_cSortObjNode(void* self, void* a1, void* stream);
extern char D_00491C80[];

extern "C" void* cInstanceNode_cInstanceNode(void* self, void* a1, void* stream)
{
    cSortObjNode_cSortObjNode(self, a1, stream);
    *(void**)((char*)self + 0xC) = D_00491C80;
    sInstNodeCtorVEntry* vt = *(sInstNodeCtorVEntry**)stream;
    *(int*)((char*)self + 0x18) = vt[4].fn((char*)stream + vt[4].delta, self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FBF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0034FC80(void* self, void* a1);
extern void* func_00354920_dtor(void* self, int flags) __asm__("func_00354920__FPv");

extern "C" void func_0034FBF0(void* self, int flags)
{
    *(void***)((char*)self + 0xc) = (void**)D_00491C80;
    func_0034FC80(self, *(void**)((char*)self + 0x18));
    *(int*)(*(char**)((char*)self + 0x18) + 8) &= 0xFFFF0300;
    {
        char* o = *(char**)((char*)self + 0x18);
        int v = *(int*)(o + 8);
        *(int*)(o + 8) = v | (v >> 16);
    }
    *(int*)(*(char**)((char*)self + 0x18) + 8) |= 2;
    func_00354920_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FC78);
#ifdef SKIP_ASM
extern "C" void func_0034FC78(int a0, void* a1)
{
    *(int*)((char*)a1 + 0xc) = a0;
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FC80);
#ifdef SKIP_ASM
extern "C" void func_0034FC80(void* self, void* a1)
{
    if (a1 != 0) {
        if (*(int*)((char*)a1 + 0xc) == (int)self) {
            *(int*)((char*)a1 + 0xc) = 0;
        }
    }
}
#endif

extern "C" void* func_002D19E8(int);

//100%
INCLUDE_ASM("object/instancenode", func_0034FCA0);
#ifdef SKIP_ASM
extern "C" void func_002D1A78(int);

extern "C" void func_0034FCA0(void *arg0) {
    func_002D1A78((*(int *)((char*)(arg0) + (0x18))));
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FCC0__FPv);
#ifdef SKIP_ASM
void* func_0034FCC0(void* self)
{
    return func_002D19E8(*(int*)((char*)self + 0x18));
}
#endif

extern "C" void* func_002D1A30(int);

//100%
INCLUDE_ASM("object/instancenode", func_0034FCE0__FPv);
#ifdef SKIP_ASM
void* func_0034FCE0(void* self)
{
    return func_002D1A30(*(int*)((char*)self + 0x18));
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FD00);
#ifdef SKIP_ASM
struct sInstNodeVEntryFD00 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0034FD00(void* self, int a1)
{
    if (a1 != 0) {
        if (func_0034FCC0(self) != 0) return;
    }
    *(int*)(*(char**)((char*)self + 0x18) + 8) &= 0xFFFF0300;
    {
        char* o = *(char**)((char*)self + 0x18);
        int v = *(int*)(o + 8);
        *(int*)(o + 8) = v | (v >> 16);
    }
    *(int*)(*(char**)((char*)self + 0x18) + 8) |= 2;
    if (self != 0) {
        sInstNodeVEntryFD00* vt = *(sInstNodeVEntryFD00**)((char*)self + 0xc);
        vt[1].fn((char*)self + vt[1].delta, 3);
    }
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FD90);
#ifdef SKIP_ASM
struct sInstNodeVEntryFD90 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0034FD90(void* self)
{
    int* f = (int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f &= 0xFFFF0000;
    f = (int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f |= *f >> 16;
    f = (int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f |= 2;
    if (self != 0) {
        sInstNodeVEntryFD90* vt = *(sInstNodeVEntryFD90**)((char*)self + 0xC);
        vt[1].fn((char*)self + vt[1].delta, 3);
    }
}
#endif

extern "C" void* func_002D19B8(int, int, int);

//100%
INCLUDE_ASM("object/instancenode", func_0034FE00__FPviii);
#ifdef SKIP_ASM
void* func_0034FE00(void* self, int a1, int a2, int a3)
{
    return func_002D19B8(a1, a2, a3);
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FE28);
#ifdef SKIP_ASM
struct sInstNodeDtorVEntry {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern char D_0048E738[];
extern "C" void* func_003506D8(void* mem, int v);

extern "C" void func_0034FE28(void* self)
{
    int v = *(int*)((char*)self + 0x18);
    if (self != 0) {
        sInstNodeDtorVEntry* vt = *(sInstNodeDtorVEntry**)((char*)self + 0xC);
        vt[1].fn((char*)self + vt[1].delta, 3);
    }
    func_003506D8(cMemMan_alloc(0x1C, D_0048E738, 0x20000000, 0), v);
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_0034FE90);
#ifdef SKIP_ASM
struct sInstNodeVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

extern "C" void func_00354980(void* self, void* stream);

extern "C" void func_0034FE90(void* self, void* stream)
{
    func_00354980(self, stream);
    sInstNodeVEntry* vt = *(sInstNodeVEntry**)stream;
    vt[6].fn((char*)stream + vt[6].delta, self);
}
#endif

INCLUDE_ASM("object/instancenode", func_0034FED8);

//100%
INCLUDE_ASM("object/instancenode", func_00350288);
#ifdef SKIP_ASM
struct sInMat44_0288 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sInVec4_0288 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sInBone_0288 {
    int parent;                 // 0x0
    int f4;
    int f8;
    sInMat44_0288* mat;         // 0xC
};

struct sInSkel_0288 {
    int f0;
    int count;                  // 0x4
    sInBone_0288* bones;        // 0x8
};

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMat_0288(sInMat44_0288* d, const sInMat44_0288* a, const sInMat44_0288* b)
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
static inline void vu0CopyMat_0288(sInMat44_0288* d, const sInMat44_0288* s)
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

static inline void buildBone_0288(sInMat44_0288* d, const sInMat44_0288* parent, const sInMat44_0288* m, const sInVec4_0288& scale)
{
    sInMat44_0288 local;
    sInVec4_0288 v;
    sInVec4_0288 tr;
    sInMat44_0288 t;
    v = *(sInVec4_0288*)m->m[0];
    *(sInVec4_0288*)local.m[0] = v;
    v = *(sInVec4_0288*)m->m[1];
    *(sInVec4_0288*)local.m[1] = v;
    v = *(sInVec4_0288*)m->m[2];
    *(sInVec4_0288*)local.m[2] = v;
    tr = *(sInVec4_0288*)m->m[3];
    v.x = tr.x * scale.x;
    v.y = tr.y * scale.y;
    v.z = tr.z * scale.z;
    v.w = tr.w * scale.w;
    *(sInVec4_0288*)local.m[3] = v;
    vu0MulMat_0288(&t, parent, &local);
    vu0CopyMat_0288(d, &t);
}

extern "C" void func_00350288(void* self, sInMat44_0288* parent, sInMat44_0288* out)
{
    char* o = *(char**)((char*)self + 0x18);
    sInSkel_0288* sk = *(sInSkel_0288**)(o + 0x80);
    float s = *(float*)(o + 0x84);
    sInBone_0288* b = sk->bones;
    sInVec4_0288 scale;
    scale.x = s;
    scale.y = s;
    scale.z = s;
    scale.w = 1.0f;
    for (int i = 0; i < sk->count; i++, b++) {
        sInMat44_0288 t2;
        if (b->parent != -1) {
            buildBone_0288(&t2, &out[b->parent], b->mat, scale);
            vu0CopyMat_0288(&out[i], &t2);
        } else {
            buildBone_0288(&t2, parent, b->mat, scale);
            vu0CopyMat_0288(&out[i], &t2);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/instancenode", cInstanceNode_getBoundBoxInfo);
#ifdef SKIP_ASM
struct sIbVec4
{
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sIbVec4 IbSub(const sIbVec4& a, const sIbVec4& b)
{
    sIbVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (dot product).
static inline float IbDot(const sIbVec4& a, const sIbVec4& b)
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

// PORT: sqrt.s (sqrtf without errno check)
static inline float IbSqrt(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

// Writes the model's bounding box (min, max) and the radius of the sphere around its centre that holds every corner.
extern "C" void cInstanceNode_getBoundBoxInfo(void* self, sIbVec4* box, float* radius)
{
    sIbVec4 t;
    t.x = *(float*)(*(char**)((char*)self + 0x18) + 0x60);
    t.y = *(float*)(*(char**)((char*)self + 0x18) + 0x64);
    t.z = *(float*)(*(char**)((char*)self + 0x18) + 0x68);
    t.w = 1.0f;
    box[0] = t;
    t.x = *(float*)(*(char**)((char*)self + 0x18) + 0x6C);
    t.y = *(float*)(*(char**)((char*)self + 0x18) + 0x70);
    t.z = *(float*)(*(char**)((char*)self + 0x18) + 0x74);
    box[1] = t;
    t = *(sIbVec4*)(*(char**)((char*)self + 0x18) + 0x40);
    sIbVec4* mx = &box[1];
    sIbVec4* ctr = &t;
    float best = 0.0f;
    for (int i = 0; i < 8; i++) {
        float x = (i & 1) ? box[0].x : mx->x;
        float y = (i & 2) ? box[0].y : mx->y;
        float z = (i & 4) ? box[0].z : mx->z;
        sIbVec4 c;
        c.x = x;
        c.y = y;
        c.z = z;
        c.w = 1.0f;
        sIbVec4 d = IbSub(c, *ctr);
        float l = IbDot(d, d);
        if (best < l) best = l;
    }
    *radius = IbSqrt(best);
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_00350698);
#ifdef SKIP_ASM
struct sInstNodeEntry {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
};

struct sInstNodeList {
    int field_0x0;
    int count;                // 0x4
    sInstNodeEntry* entries;  // 0x8
};

extern "C" int func_00350698(void* self)
{
    sInstNodeList* list = *(sInstNodeList**)((char*)self + 0x80);
    int i;
    int count = list->count;
    sInstNodeEntry* e = list->entries;
    for (i = 0; i < count; i++, e++) {
        if (e->field_0x8 != 0) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/instancenode", func_003506D8);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, int a1, int type, int a3);
extern char D_00491B00[];

extern "C" void* func_003506D8(void* self, int v)
{
    func_0034FB00(self, 8, 6, v);
    *(void**)((char*)self + 0xC) = D_00491B00;
    unsigned int* f = (unsigned int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f &= 0xFFFFFF9F;
    f = (unsigned int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f = (*f & 0xFFFFFFFD) | 4;
    return self;
}
#endif

