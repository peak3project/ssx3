#include "common.h"

//100%
INCLUDE_ASM("object/deadfadenode", cDeadFadeNode_cDeadFadeNode);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, int a1, int type, void* a3);
extern "C" float func_002D1C70();
extern "C" void func_003E6574(void* dst, void* src, int size);
extern char D_00491980[];
extern char D_0048E8A8[];

// PORT: array new bound to the tagged allocator
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

struct sDfV4_0750 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sDfMat_0750 {
    sDfV4_0750 r[4];
};

struct sDfMatElem_0750 {
    sDfV4_0750 r[4];
    sDfMatElem_0750() {}
};

struct sDfPart_0750 {
    int parent;
    int pad4;
    int pad8;
    sDfMat_0750* mat;   // 0xC
};

struct sDfModel_0750 {
    int pad0;
    int count;              // 0x4
    sDfPart_0750* parts;    // 0x8
};

struct sDfInst_0750 {
    char pad_0x00[0x8];
    unsigned int flags;     // 0x8
    char pad_0x0C[0x4];
    sDfMat_0750 world;      // 0x10
    char pad_0x50[0x30];
    sDfModel_0750* model;   // 0x80
    float scale;            // 0x84
};

struct sDfDesc_0750 {
    int w[2];
    float f8;
    float fC;
};

struct sDfBlock_0750 {
    unsigned int w[3];
};

struct sDfVE_0750 {
    short delta;
    short index;
    void* fn;
};

struct sDfOther_0750 {
    char pad_0x00[0xC];
    sDfVE_0750* vt;         // 0xC
};

struct cDeadFadeNode_0750 {
    char pad_0x00[0xC];
    void* vt;                   // 0xC
    char pad_0x10[0x8];
    sDfInst_0750* inst;         // 0x18
    sDfBlock_0750 block;        // 0x1C
    float f28;                  // 0x28
    float f2C;                  // 0x2C
    float f30;                  // 0x30
    float f34;                  // 0x34
    sDfMatElem_0750* mats;      // 0x38
};

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMat_0750(sDfMat_0750* d, const void* a, const sDfMat_0750* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
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
        ".set reorder\n"
        :
        : "r"(d), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0CopyMat_0750(void* d, const void* s)
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

static inline sDfV4_0750 row_0750(const sDfMat_0750* m, int i)
{
    return m->r[i];
}

static inline void mulv_0750(sDfV4_0750& r, const sDfV4_0750& a, const sDfV4_0750& b)
{
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    r.w = a.w * b.w;
}

// Builds a part matrix: dst = parent * (local with its translation row scaled by s).
static inline void partMat_0750(sDfMat_0750* dst, const void* parentMat, const sDfMat_0750* m, const sDfV4_0750& s)
{
    sDfMat_0750 l;
    l.r[0] = row_0750(m, 0);
    l.r[1] = row_0750(m, 1);
    l.r[2] = row_0750(m, 2);
    sDfV4_0750 t;
    sDfV4_0750 r3 = m->r[3];
    mulv_0750(t, r3, s);
    l.r[3] = t;
    sDfMat_0750 tt;
    vu0MulMat_0750(&tt, parentMat, &l);
    vu0CopyMat_0750(dst, &tt);
}

typedef int (*DfBoolFn_0750)(void*);
typedef sDfMat_0750* (*DfMatFn_0750)(void*);
typedef void (*DfSetFn_0750)(void*, int);

extern "C" cDeadFadeNode_0750* cDeadFadeNode_cDeadFadeNode(cDeadFadeNode_0750* self, int a1, void* obj, sDfDesc_0750* desc, sDfOther_0750* other)
{
    sDfMatElem_0750** pm = &self->mats;
    func_0034FB00(self, a1, 0x16, obj);
    self->vt = D_00491980;
    self->block.w[0] = 0xFFFFFFFF;
    self->block = *(sDfBlock_0750*)desc;
    self->f2C = func_002D1C70() / desc->f8;
    self->f34 = desc->fC * func_002D1C70();
    self->f30 = 0.0f;
    self->f28 = 1.0f;
    sDfModel_0750* model = self->inst->model;
    *pm = new (D_0048E8A8, 0x20000000, 0) sDfMatElem_0750[model->count];
    if (other != 0 && ((DfBoolFn_0750)other->vt[26].fn)((char*)other + other->vt[26].delta)) {
        sDfMat_0750* src = ((DfMatFn_0750)other->vt[27].fn)((char*)other + other->vt[27].delta);
        func_003E6574(self->mats, src, model->count << 6);
    } else {
        sDfMat_0750* base = &self->inst->world;
        if (other != 0) {
            base = ((DfMatFn_0750)other->vt[24].fn)((char*)other + other->vt[24].delta);
        }
        sDfPart_0750* p = model->parts;
        float k = self->inst->scale;
        sDfV4_0750 s;
        s.x = k;
        s.y = k;
        s.z = k;
        s.w = 1.0f;
        sDfMat_0750 t2;
        for (int i = 0; i < model->count; i++, p++) {
            int parent = p->parent;
            if (parent != -1) {
                partMat_0750(&t2, &self->mats[parent], p->mat, s);
                vu0CopyMat_0750(&self->mats[i], &t2);
            } else {
                partMat_0750(&t2, base, p->mat, s);
                vu0CopyMat_0750(&self->mats[i], &t2);
            }
        }
    }
    if (other != 0) {
        ((DfSetFn_0750)other->vt[1].fn)((char*)other + other->vt[1].delta, 3);
    }
    self->inst->flags &= ~0x60;
    self->inst->flags = (self->inst->flags & ~2) | 4;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350B98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* cInstanceNode_ctor_v(void* self) __asm__("cInstanceNode_cInstanceNode");
extern char D_00491980[];

extern "C" void* func_00350B98(void* self, void* bucket, void* stream)
{
    cInstanceNode_ctor_v(self);
    *(void**)((char*)self + 0xC) = D_00491980;
    *(unsigned int*)((char*)self + 0x1C) = 0xFFFFFFFFU;
    *(int*)((char*)self + 0x38) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350BE0);
#ifdef SKIP_ASM
extern char D_00491980[];
void cMemMan_free(void*);
extern "C" void func_0034FBF0(void* self, int flags);

extern "C" void func_00350BE0(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_00491980;
    void* p = *(void**)((char*)self + 0x38);
    if (p != 0) {
        cMemMan_free(p);
    }
    func_0034FBF0(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350C38);
#ifdef SKIP_ASM
// PORT: the project names this func_002D1CC0__FPv (one void* arg), but it is a
// pass-through wrapper and this caller passes two args (prototype mismatch).
void* func_002D1CC0_2(void*, void*) __asm__("func_002D1CC0__FPv");

extern "C" void func_00350C38(void* self)
{
    float t;
    *(float*)((char*)self + 0x30) += *(float*)((char*)self + 0x34);
    t = *(float*)((char*)self + 0x28);
    if (t > 0.0f) {
        *(float*)((char*)self + 0x28) = t - *(float*)((char*)self + 0x2C);
    } else {
        func_002D1CC0_2(*(void**)((char*)self + 0x18), (char*)self + 0x1C);
    }
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350C90);
#ifdef SKIP_ASM
// PORT: the project names this func_002D1CC0__FPv (one void* arg), but it is a
// pass-through wrapper and this caller passes two args (prototype mismatch).
void* func_002D1CC0_2(void*, void*) __asm__("func_002D1CC0__FPv");

extern "C" void func_00350C90(void* self)
{
    func_002D1CC0_2(*(void**)((char*)self + 0x18), (char*)self + 0x1C);
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350CB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sDfVec_350CB8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sDfMat_350CB8 {
    sDfVec_350CB8 r[4];
};

struct sDfSlot_350CB8 {
    int f0;
    int type;
};

struct sDfCam_350CB8 {
    char pad_0x0[0x20];
    sDfSlot_350CB8 slots[(0x3F0 - 0x20) / 8];  // 0x20
    struct {
        int kind;
        char pad[0x14];
    } paths[1];                     // 0x3F0
};

struct sDfObj_350CB8 {
    char pad_0x0[0x60];
    float pos[3];                   // 0x60
    float scl[3];                   // 0x6C
    char pad_0x78[0x7D - 0x78];
    unsigned char slot;             // 0x7D
    short path;                     // 0x7E
    char pad_0x80[0x94 - 0x80];
    void* light;                    // 0x94
};

struct sDfGfxVt_350CB8 {
    short delta;
    short index;
    void* fn;
};

struct cDfGfx_350CB8 {
    char pad_0x0[0x10D8];
    sDfGfxVt_350CB8* vt;            // 0x10D8
};

typedef sDfMat_350CB8 (*DfViewFn_350CB8)(void*);
typedef int (*DfCullFn_350CB8)(void*, sDfVec_350CB8*, sDfVec_350CB8*, const sDfMat_350CB8&);
typedef void (*DfDrawFn_350CB8)(void*, void*, void*, void*, float, void*, void*, int);

extern sDfCam_350CB8** D_004A47B8_350CB8 __asm__("D_004A47B8");
extern cDfGfx_350CB8* D_004A5B80_350CB8 __asm__("D_004A5B80");
extern sDfMat_350CB8 D_004FF1A0_350CB8 __asm__("D_004FF1A0");

#define OBJ_350CB8(s) (*(sDfObj_350CB8**)((char*)(s) + 0x18))

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void MatCopy_350CB8(sDfMat_350CB8* d, const sDfMat_350CB8* s)
{
    __asm__(
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

static inline bool IsT6_350CB8(sDfCam_350CB8* c, int i)
{
    return c->slots[i].type == 6;
}

static inline int Visible_350CB8(sDfCam_350CB8* cam, sDfObj_350CB8* obj)
{
    if (obj->slot == 0xFF) {
        return 1;
    }
    if (IsT6_350CB8(cam, obj->slot)) {
        return cam->paths[obj->path].kind == 3;
    }
    return 0;
}

// Draws the fading corpse: culls its box, then draws it lowered by the fade depth at 0x30.
extern "C" void func_00350CB8(char* self)
{
    sDfCam_350CB8* cam = *D_004A47B8_350CB8;
    if (!Visible_350CB8(cam, OBJ_350CB8(self))) {
        return;
    }
    cDfGfx_350CB8* gfx = D_004A5B80_350CB8;
    {
        sDfGfxVt_350CB8* vt = gfx->vt;
        char* thisp = (char*)gfx + vt[93].delta;
        sDfVec_350CB8 b[2];
        b[0].x = OBJ_350CB8(self)->pos[0];
        b[0].y = OBJ_350CB8(self)->pos[1];
        b[0].z = OBJ_350CB8(self)->pos[2];
        b[0].w = 1.0f;
        b[1].x = OBJ_350CB8(self)->scl[0];
        b[1].y = OBJ_350CB8(self)->scl[1];
        b[1].z = OBJ_350CB8(self)->scl[2];
        b[1].w = 1.0f;
        int res = ((DfCullFn_350CB8)vt[93].fn)(thisp, &b[0], &b[1], ((DfViewFn_350CB8)gfx->vt[43].fn)((char*)gfx + gfx->vt[43].delta));
        if (res == 1) {
            return;
        }
    }
    sDfMat_350CB8 xf;
    MatCopy_350CB8(&xf, &D_004FF1A0_350CB8);
    sDfVec_350CB8 t;
    t.x = 0.0f;
    t.y = 0.0f;
    t.z = -*(float*)(self + 0x30);
    t.w = 1.0f;
    xf.r[3] = t;
    ((DfDrawFn_350CB8)gfx->vt[95].fn)((char*)gfx + gfx->vt[95].delta, OBJ_350CB8(self), OBJ_350CB8(self)->light, &xf,
                                      *(float*)(self + 0x28), *(void**)(self + 0x38), 0, 0);
}
#endif

extern "C" void* func_0034FE90(void* self);

//100%
INCLUDE_ASM("object/deadfadenode", func_00350E70__FPv);
#ifdef SKIP_ASM
void* func_00350E70(void* self)
{
    return func_0034FE90(self);
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350E90);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, int a1, int type, void* a3);
extern char D_00491800[];

extern "C" void* func_00350E90(void* self, void* a1)
{
    func_0034FB00(self, 1, 0x10, a1);
    *(void**)((char*)self + 0xC) = D_00491800;
    unsigned int* f = (unsigned int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f &= 0xFFFFFF9F;
    f = (unsigned int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f = (*f & 0xFFFFFFFD) | 4;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350F08);
#ifdef SKIP_ASM
extern "C" void cInstanceNode_cInstanceNode(void* self);
extern char D_00491800[];

extern "C" void* func_00350F08(void* self, void* bucket, void* stream)
{
    cInstanceNode_cInstanceNode(self);
    *(void**)((char*)self + 0xC) = D_00491800;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350F40__FPv);
#ifdef SKIP_ASM
void* func_00350F40(void* self)
{
    return func_0034FE90(self);
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350F60);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, int a1, int type, void* a3);
extern char D_00491680[];

extern "C" void* func_00350F60(void* self, void* a1)
{
    func_0034FB00(self, 1, 0x13, a1);
    *(void**)((char*)self + 0xC) = D_00491680;
    unsigned int* f = (unsigned int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f &= 0xFFFFFF9F;
    f = (unsigned int*)(*(char**)((char*)self + 0x18) + 0x8);
    *f = (*f & 0xFFFFFFFD) | 4;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00350FD8);
#ifdef SKIP_ASM
extern "C" void cInstanceNode_cInstanceNode(void* self);
extern char D_00491680[];

extern "C" void* func_00350FD8(void* self, void* bucket, void* stream)
{
    cInstanceNode_cInstanceNode(self);
    *(void**)((char*)self + 0xC) = D_00491680;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/deadfadenode", func_00351010__FPv);
#ifdef SKIP_ASM
void* func_00351010(void* self)
{
    return func_0034FE90(self);
}
#endif

