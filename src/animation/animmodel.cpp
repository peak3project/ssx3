#include "common.h"
#include "animation/animmodel.h"

//100%
INCLUDE_ASM("animation/animmodel", cAnimModel_addModelPartLOD);
#ifdef SKIP_ASM
// PORT: operator_new__FUi is the game's tagged allocator (size, tag, flags, d); bound by asm label
// as operator new[] so the new-expressions below compute their destination before the call.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00489C80[];
extern "C" void func_003E6448(void* dst, int c, int n);

extern "C" void cAnimModel_addModelPartLOD(cAnimModel* self, int lod, char* part, int index)
{
    char* data = part + 0x60;
    for (int i = 0; i < self->numParts; i++) {
        if (self->parts[i].id == *(signed char*)(part + 0x52)) {
            self->parts[i].lods[lod].used = 1;
            self->parts[i].lods[lod].refs[index].part = part;
            self->parts[i].lods[lod].refs[index].data = data;
            return;
        }
    }
    for (int k = 0; k < 4; k++) {
        self->parts[self->numParts].lods[k].refs = new (D_00489C80, 0, 0) sAnimModelLodRef[self->numLodRefs];
        func_003E6448(self->parts[self->numParts].lods[k].refs, 0, self->numLodRefs << 4);
    }
    self->parts[self->numParts].id = *(signed char*)(part + 0x52);
    self->parts[self->numParts].lods[lod].used = 1;
    self->parts[self->numParts].lods[lod].refs[index].part = part;
    self->parts[self->numParts].lods[lod].refs[index].data = data;
    self->parts[self->numParts].boneNames = data + *(int*)(part + 0x18);
    self->parts[self->numParts].unk_40 = data + *(int*)(part + 0x2C);
    self->parts[self->numParts].unk_3C = data + *(int*)(part + 0x1C);
    self->parts[self->numParts].numBones = *(short*)(part + 0x4A);
    self->parts[self->numParts].unk_48 = *(short*)(part + 0x4E);
    self->parts[self->numParts].unk_4C = *(short*)(part + 0x50);
    self->parts[self->numParts].refIndex = index;
    self->numParts++;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030DB70__FPvi);
#ifdef SKIP_ASM
struct sAnimModelList {
    char pad_0x00[0x60];
    int count;     // 0x60
    int items[1];  // 0x64
};

void func_0030DB70(void* self, int item)
{
    sAnimModelList* list = (sAnimModelList*)self;
    list->items[list->count++] = item;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030DB90);
#ifdef SKIP_ASM
extern "C" int func_0030DB90(void* self, void* a1)
{
    return *(int*)self - *(int*)a1;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030DBA0);
#ifdef SKIP_ASM
extern "C" void func_0030DBA0(cAnimModel* self, float a, float b)
{
    t4Vector v;
    v.x = a;
    v.y = b;
    v.z = b;
    v.w = 1.0f;
    self->unk_140 = v;
}
#endif

INCLUDE_ASM("animation/animmodel", cAnimModel_compile);

//100%
INCLUDE_ASM("animation/animmodel", func_0030E9E0);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_0030E9E0(cAnimModel* self, int i, int channel)
{
    if (i > self->maxPartIndex)
    {
        return;
    }
    if (self->partIndex == 0)
    {
        return;
    }
    int idx = self->partIndex[i];
    if (idx < 0)
    {
        return;
    }
    sAnimModelPart* e = &self->parts[idx];
    self->mask |= e->mask;
    if (channel < 0)
    {
        for (int k = 0; k < 4; k++)
        {
            e->lods[k].used = 1;
        }
    }
    else
    {
        e->lods[channel].used = 1;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030EA80);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_0030EA80(cAnimModel* self, int i, int channel)
{
    if (i > self->maxPartIndex)
    {
        return;
    }
    if (self->partIndex == 0)
    {
        return;
    }
    int idx = self->partIndex[i];
    if (idx < 0)
    {
        return;
    }
    sAnimModelPart* e = &self->parts[idx];
    self->mask &= ~e->mask;
    if (channel < 0)
    {
        for (int k = 0; k < 4; k++)
        {
            e->lods[k].used = 0;
        }
    }
    else
    {
        e->lods[channel].used = 0;
        for (int k = 0; k < 4; k++)
        {
            if (e->lods[k].used)
            {
                self->mask |= e->mask;
                break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030EB60);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_0030EB60(cAnimModel* self)
{
    for (int j = 0; j < self->numParts; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            self->parts[j].lods[k].used = 0;
        }
    }
    self->mask = 0;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030EBC0);
#ifdef SKIP_ASM
extern "C" int func_0030EBC0(cAnimModel* self, int i, int channel)
{
    int idx;
    if (i > self->maxPartIndex || self->partIndex == 0 || (idx = self->partIndex[i]) < 0)
    {
        return 0;
    }
    return self->parts[idx].lods[channel].used;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030EC18);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_0030EC18(cAnimModel* self, int i, int param)
{
    if (i > self->maxPartIndex)
    {
        return;
    }
    if (self->partIndex == 0)
    {
        return;
    }
    int idx = self->partIndex[i];
    if (idx < 0)
    {
        return;
    }
    sAnimModelPart* e = &self->parts[idx];
    e->refIndex = param;
    self->mask |= e->mask;
    for (int k = 0; k < 4; k++)
    {
        e->lods[k].used = 1;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030ECA0);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_0030ECA0(cAnimModel* self, int i)
{
    sAnimModelPart* e = &self->parts[self->partIndex[i]];
    self->unk_158 |= e->mask;
}
#endif

INCLUDE_ASM("animation/animmodel", func_0030ECD8);

INCLUDE_ASM("animation/animmodel", func_0030F2B0);

//100%
INCLUDE_ASM("animation/animmodel", func_00310120);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 macro-mode asm. Builds bone matrix unk_030[i] from the bone's quaternion
// (rot, rows 0-2) and position (pos, row 3), then unk_034[i] = unk_030[i] with each row scaled
// by the matching component of unk_140.
// PORT: index-first (int) address arithmetic (pointer in int).
extern "C" void func_00310120(cAnimModel* self, int i, sAnimModelBone* p)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2       $vf4, 0x10(%0)\n"
        "lqc2       $vf3, 0x0(%0)\n"
        "vaddw.xyz  $vf1, $vf0, $vf0w\n"
        "vadd.xyz   $vf5, $vf4, $vf4\n"
        "vsub.w     $vf10, $vf10, $vf10\n"
        "vsub.w     $vf11, $vf11, $vf11\n"
        "vsub.w     $vf12, $vf12, $vf12\n"
        "vmul.xyz   $vf6, $vf5, $vf4\n"
        "vmulw.xyz  $vf7, $vf5, $vf4w\n"
        "vopmula.xyz ACC, $vf5, $vf4\n"
        "vmadd.xyz  $vf8, $vf0, $vf0\n"
        "vsubay.x   ACC, $vf1, $vf6y\n"
        "vmsubz.x   $vf10, $vf1, $vf6z\n"
        "vsubaz.y   ACC, $vf1, $vf6z\n"
        "vmsubx.y   $vf11, $vf1, $vf6x\n"
        "vsubax.z   ACC, $vf1, $vf6x\n"
        "vmsuby.z   $vf12, $vf1, $vf6y\n"
        "vaddaz.y   ACC, $vf0, $vf8z\n"
        "vmaddz.y   $vf10, $vf1, $vf7z\n"
        "vaddax.z   ACC, $vf0, $vf8x\n"
        "vmaddx.z   $vf11, $vf1, $vf7x\n"
        "vaddax.y   ACC, $vf0, $vf8x\n"
        "vmsubx.y   $vf12, $vf1, $vf7x\n"
        "vadday.z   ACC, $vf0, $vf8y\n"
        "vmsuby.z   $vf10, $vf1, $vf7y\n"
        "vaddaz.x   ACC, $vf0, $vf8z\n"
        "vmsubz.x   $vf11, $vf1, $vf7z\n"
        "vadday.x   ACC, $vf0, $vf8y\n"
        "vmaddy.x   $vf12, $vf1, $vf7y\n"
        "sqc2       $vf3, 0x30(%1)\n"
        "sqc2       $vf10, 0x0(%1)\n"
        "sqc2       $vf11, 0x10(%1)\n"
        "sqc2       $vf12, 0x20(%1)\n"
        ".set pop\n"
        :
        : "r"(p), "r"((t4Matrix*)((i << 6) + (int)self->unk_030))
        : "memory");
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2       $vf1, 0x140(%2)\n"
        "lqc2       $vf4, 0x0(%0)\n"
        "lqc2       $vf5, 0x10(%0)\n"
        "lqc2       $vf6, 0x20(%0)\n"
        "lqc2       $vf7, 0x30(%0)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2       $vf8, 0x0(%1)\n"
        "sqc2       $vf9, 0x10(%1)\n"
        "sqc2       $vf10, 0x20(%1)\n"
        "sqc2       $vf11, 0x30(%1)\n"
        ".set pop\n"
        :
        : "r"((t4Matrix*)((i << 6) + (int)self->unk_030)), "r"((t4Matrix*)((i << 6) + (int)self->unk_034)), "r"(self)
        : "memory");
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310200);
#ifdef SKIP_ASM
// Vector/quaternion with constructors (the result temps go straight into the return slot).
struct sAmQuat_0200
{
    float x, y, z, w;
    sAmQuat_0200() {}
    sAmQuat_0200(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sAmXform_0200
{
    sAmQuat_0200 pos;
    sAmQuat_0200 rot;
};

extern t4Vector D_004FF130;

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sAmQuat_0200 amQuatMul_0200(const sAmQuat_0200& a, const sAmQuat_0200& b)
{
    sAmQuat_0200 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sAmQuat_0200 amSub_0200(const sAmQuat_0200& a, const sAmQuat_0200& b)
{
    sAmQuat_0200 r;
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
static inline sAmQuat_0200 amAdd_0200(const sAmQuat_0200& a, const sAmQuat_0200& b)
{
    sAmQuat_0200 r;
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

// PORT: PS2-only VU0 inline asm (v rotated by quaternion q).
static inline sAmQuat_0200 amRot_0200(const sAmQuat_0200& q, const sAmQuat_0200& v)
{
    sAmQuat_0200 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsub.w    $vf8, $vf8, $vf8\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vopmsub.xyz $vf7, $vf6, $vf4\n"
        "vmulaw.xyz ACC, $vf5, $vf0w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf7, $vf0w\n"
        "vmaddw.xyz $vf8, $vf7, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(r)
        : "m"(q), "m"(v)
        : "memory");
    return r;
}

// Child transform = parent transform a composed with local transform b.
static inline sAmXform_0200 amCombine_0200(const sAmXform_0200& a, const sAmXform_0200& b)
{
    sAmXform_0200 r;
    r.rot = amQuatMul_0200(a.rot, b.rot);
    r.pos = amAdd_0200(amRot_0200(a.rot, amSub_0200(b.pos, *(const sAmQuat_0200*)&D_004FF130)), a.pos);
    return r;
}

// One boneNames entry (0x50 bytes): the name, then the parent bone (< 0 = root).
struct sAmBoneInfo_0200 {
    char name[0x12];
    short parent;
    char pad[0x3C];
};

// Rebuilds the world bones from the local pose: bone k = parent (or the next root transform) * local k.
extern "C" void func_00310200(cAnimModel* self, sAnimModelBone* roots)
{
    for (int i = 0; i < self->numParts; i++)
    {
        // PORT: pointer arithmetic through int (offset-first addu).
        sAmBoneInfo_0200* info = (sAmBoneInfo_0200*)((sAnimModelPart*)(i * (int)sizeof(sAnimModelPart) + (int)self->parts))->boneNames;
        for (int j = 0; j < ((sAnimModelPart*)(i * (int)sizeof(sAnimModelPart) + (int)self->parts))->numBones; j++)
        {
            int k = j + ((sAnimModelPart*)(i * (int)sizeof(sAnimModelPart) + (int)self->parts))->firstBone;
            sAnimModelBone* parent;
            sAmBoneInfo_0200* e = &info[j];
            short p = e->parent;
            if (p < 0)
                parent = roots++;
            else
                parent = &self->bones[p];
            t4Vector* lp = (t4Vector*)((k << 4) + (int)self->localPos);
            sAmXform_0200 local;
            local.pos = sAmQuat_0200(lp->x * self->unk_140.x, lp->y * self->unk_140.y, lp->z * self->unk_140.z, lp->w * self->unk_140.w);
            local.rot = *(sAmQuat_0200*)((k << 4) + (int)self->localRot);
            *(sAmXform_0200*)((k << 5) + (int)self->bones) = amCombine_0200(*(sAmXform_0200*)parent, local);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/animmodel", func_003103F0);
#ifdef SKIP_ASM
extern "C" void func_00310120(cAnimModel* self, int i, sAnimModelBone* p);

extern "C" void func_003103F0(cAnimModel* self)
{
    int i;
    for (i = 0; i < self->numBones; i++)
    {
        func_00310120(self, i, &self->bones[i]);
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310458);
#ifdef SKIP_ASM
extern t4Vector D_004FF130;

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector).
static inline t4Vector amMulMat_0458(const t4Matrix* m, const t4Vector& v)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

struct sAmPoint_0458 {
    float x, y, z;
    int bone;
};

// Returns point `index` of the part with this id, transformed by its bone matrix (unk_034),
// or D_004FF130 when no part has the id.
extern "C" t4Vector func_00310458(cAnimModel* model, int id, int index)
{
    for (int i = 0; i < model->numParts; i++)
    {
        // PORT: pointer arithmetic through int (offset-first addu).
        sAnimModelPart* part = (sAnimModelPart*)(i * (int)sizeof(sAnimModelPart) + (int)model->parts);
        if (part->id == id)
        {
            sAmPoint_0458* pt = (sAmPoint_0458*)((index << 4) + (int)part->unk_3C);
            t4Matrix* m = (t4Matrix*)(((pt->bone + part->firstBone) << 6) + (int)model->unk_034);
            t4Vector v;
            v.x = pt->x;
            v.y = pt->y;
            v.z = pt->z;
            v.w = 1.0f;
            return amMulMat_0458(m, v);
        }
    }
    return D_004FF130;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310530);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void amVecAddEq(t4Vector* dst, t4Vector* v)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(*dst)
        : "m"(*dst), "m"(*v));
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline t4Vector amVecAdd(const t4Vector& src, t4Vector* b)
{
    t4Vector a = src;
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(*b)
        : "memory");
    return r;
}

extern "C" void func_00310530(cAnimModel* self, t4Vector* v)
{
    for (int i = 0; i < self->numParts; i++) {
        for (int j = 0; j < self->parts[i].numBones; j++) {
            int k = j + self->parts[i].firstBone;
            amVecAddEq(&self->bones[k].pos, v);
            {
                t4Vector t = amVecAdd(self->unk_030[k].row[3], v);
                self->unk_030[k].row[3] = t;
            }
            {
                t4Vector t = amVecAdd(self->unk_034[k].row[3], v);
                self->unk_034[k].row[3] = t;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310640);
#ifdef SKIP_ASM
struct sAmMat_0640;
// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0CopyMat_0640(void* d, const void* s)
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

struct sAmMat_0640 {
    float m[16];
    sAmMat_0640() {}
    sAmMat_0640(const sAmMat_0640& s) { vu0CopyMat_0640(this, &s); }
    sAmMat_0640& operator=(const sAmMat_0640& s)
    {
        vu0CopyMat_0640(this, &s);
        return *this;
    }
    // placement array new for the one-time construction of the matrix palette.
    void* operator new[](unsigned int, void* p) { return p; }
} __attribute__((aligned(16)));


// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMat_0640(sAmMat_0640* d, const sAmMat_0640* a, const sAmMat_0640* b)
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

static inline sAmMat_0640 mulMat_0640(const sAmMat_0640& a, const sAmMat_0640& b)
{
    sAmMat_0640 t;
    vu0MulMat_0640(&t, &a, &b);
    return t;
}

struct sAmVEnt_0640 {
    short delta;
    short index;
    void* fn;
};

struct sAmCtx_0640 {
    char pad[0x10D8];
    sAmVEnt_0640* vt;           // 0x10D8
};

typedef void (*tSetMats_0640)(void*, sAmMat_0640*, int, int, int, int);
typedef void (*tDraw_0640)(void*, char*, char*, int, int, float);

extern int D_004A5948;
extern sAmCtx_0640* D_004A5B80_0640 __asm__("D_004A5B80");
extern sAmMat_0640 D_004FC420[];

extern "C" void func_00310640(cAnimModel* self, int lod, int x, int y)
{
    sAmCtx_0640* ctx = D_004A5B80_0640;
    if (D_004A5948 == 0) {
        new ((void*)D_004FC420) sAmMat_0640[64];
        D_004A5948 = 1;
    }
    for (int i = 0; i < self->numBones; i++) {
        D_004FC420[i] = mulMat_0640(((sAmMat_0640*)self->unk_034)[i], ((sAmMat_0640*)self->unk_038)[i]);
    }
    if (self->unk_018 != 0) {
        for (int j = 0; j < self->numParts; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAnimModelPart* p = (sAnimModelPart*)(j * (int)sizeof(sAnimModelPart) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAnimModelLodRef* r = &p->lods[lod].refs[p->refIndex];
                if (r->part != 0) {
                    ((tSetMats_0640)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FC420, 0, r->unk_0C, r->unk_08, 0);
                    int m = self->parts[j].id == 2 ? x : y;
                    ((tDraw_0640)ctx->vt[99].fn)((char*)ctx + ctx->vt[99].delta, r->part, r->data, m, 0, self->unk_140.y);
                }
            }
        }
    } else {
        ((tSetMats_0640)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FC420, 0, self->lodInfo[lod].unk_04, self->lodInfo[lod].unk_00, 0);
        for (int j = 0; j < self->numParts; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAnimModelPart* p = (sAnimModelPart*)(j * (int)sizeof(sAnimModelPart) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAnimModelLodRef* r = p->lods[lod].refs;
                if (r->part != 0) {
                    int m = p->id == 2 ? x : y;
                    ((tDraw_0640)ctx->vt[99].fn)((char*)ctx + ctx->vt[99].delta, r->part, r->data, m, 0, self->unk_140.y);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310948);
#ifdef SKIP_ASM
struct sAmMat_0948;
// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0CopyMat_0948(void* d, const void* s)
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

struct sAmMat_0948 {
    float m[16];
    sAmMat_0948() {}
    sAmMat_0948(const sAmMat_0948& s) { vu0CopyMat_0948(this, &s); }
    sAmMat_0948& operator=(const sAmMat_0948& s)
    {
        vu0CopyMat_0948(this, &s);
        return *this;
    }
    // placement array new for the one-time construction of the matrix palette.
    void* operator new[](unsigned int, void* p) { return p; }
} __attribute__((aligned(16)));


// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMat_0948(sAmMat_0948* d, const sAmMat_0948* a, const sAmMat_0948* b)
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

static inline sAmMat_0948 mulMat_0948(const sAmMat_0948& a, const sAmMat_0948& b)
{
    sAmMat_0948 t;
    vu0MulMat_0948(&t, &a, &b);
    return t;
}

struct sAmVEnt_0948 {
    short delta;
    short index;
    void* fn;
};

struct sAmCtx_0948 {
    char pad[0x10D8];
    sAmVEnt_0948* vt;           // 0x10D8
};

typedef void (*tSetMats_0948)(void*, sAmMat_0948*, int, int, int, int);
typedef void (*tDraw_0948)(void*, char*, char*, int);

extern int D_004A594C;
extern sAmCtx_0948* D_004A5B80_0948 __asm__("D_004A5B80");
extern sAmMat_0948 D_004FD420[];

extern "C" void func_00310948(cAnimModel* self, int lod, int x, int y)
{
    if (D_004A594C == 0) {
        new ((void*)D_004FD420) sAmMat_0948[64];
        D_004A594C = 1;
    }
    sAmCtx_0948* ctx = D_004A5B80_0948;
    for (int i = 0; i < self->numBones; i++) {
        D_004FD420[i] = mulMat_0948(((sAmMat_0948*)self->unk_030)[i], ((sAmMat_0948*)self->unk_038)[i]);
    }
    if (self->unk_018 != 0) {
        for (int j = 0; j < self->numParts; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAnimModelPart* p = (sAnimModelPart*)(j * (int)sizeof(sAnimModelPart) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAnimModelLodRef* r = &p->lods[lod].refs[p->refIndex];
                if (r->part != 0) {
                    ((tSetMats_0948)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FD420, 0, r->unk_0C, r->unk_08, 0);
                    int ok = (unsigned)(self->parts[j].id - 1) < 2;
                    int m = ok ? x : y;
                    ((tDraw_0948)ctx->vt[100].fn)((char*)ctx + ctx->vt[100].delta, r->part, r->data, m);
                }
            }
        }
    } else {
        ((tSetMats_0948)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FD420, 0, self->lodInfo[lod].unk_04, self->lodInfo[lod].unk_00, 0);
        for (int j = 0; j < self->numParts; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAnimModelPart* p = (sAnimModelPart*)(j * (int)sizeof(sAnimModelPart) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAnimModelLodRef* r = p->lods[lod].refs;
                if (r->part != 0) {
                    int ok = (unsigned)(p->id - 1) < 2;
                    int m = ok ? x : y;
                    ((tDraw_0948)ctx->vt[100].fn)((char*)ctx + ctx->vt[100].delta, r->part, r->data, m);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310C48);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const void* a, const void* b);

struct sAmItem50 {
    char name[0x50];
};

extern "C" int func_00310C48(cAnimModel* self, int idx, const char* name)
{
    sAnimModelPart* g = &self->parts[self->partIndex[idx]];
    sAmItem50* items = (sAmItem50*)g->boneNames;
    for (int i = 0; i < g->numBones; i++)
    {
        if (func_004165A8(&items[i], name) == 0)
            return g->firstBone + i;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310CE8);
#ifdef SKIP_ASM
extern "C" int func_00416B18(const char* a, const char* b, int n);
extern char D_004A3DF0[];

// PORT: returns a 64-bit mask (long is 8 bytes on the EE).
extern "C" ulong func_00310CE8(cAnimModel* self, int idx, char* names)
{
    if (self->maxPartIndex < idx)
        return 0;
    int* tbl = self->partIndex;
    if (tbl == 0 || tbl[idx] < 0)
        return 0;
    char* p = names;
    ulong mask = 0;
    sAnimModelPart* part = &self->parts[tbl[idx]];
    while (*p) {
        char* q = p;
        if (*q != 0 && *q != ',') {
            do
                q++;
            while (*q != 0 && *q != ',');
        }
        int len = q - p;
        if (part->unk_0C >= 0 && func_00416B18(p, D_004A3DF0, len) == 0) {
            mask |= (ulong)1 << (part->unk_0C + self->numBones);
        } else {
            char* list = part->boneNames;
            int j = 0;
            ulong one = 1;
            for (; j < part->numBones; j++) {
                if (func_00416B18(list + j * 0x50, p, len) == 0 && *(list + len + j * 0x50) == 0) {
                    mask |= one << (part->firstBone + j);
                    break;
                }
            }
        }
        p = q + (*q == ',');
    }
    return mask;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310EA8);
#ifdef SKIP_ASM
class cAmStream {
public:
    virtual void read(void* data, int size);
    virtual void write(void* data, int size);
};

extern "C" void func_00310EA8(cAnimModel* self, cAmStream* s)
{
    s->read(self->bones, self->numBones << 5);
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310EE0);
#ifdef SKIP_ASM
extern "C" void func_00310EE0(cAnimModel* self, cAmStream* s)
{
    s->write(self->bones, self->numBones << 5);
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310F18);
#ifdef SKIP_ASM
// PORT: operator_new__FUi is the game's tagged allocator (size, tag, flags, d); bound by asm label
// as operator new[] so the new-expressions below compute their destination before the call.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00489D50[];

struct sAnimElem_310F18
{
    int a[5];
};

struct sAnimNode_310F18
{
    int used;                   // 0x00
    sAnimElem_310F18* data;     // 0x04
    char pad8[0x14];
    sAnimNode_310F18* prev;     // 0x1C
    sAnimNode_310F18* next;     // 0x20
};

// Typed views of the pool tables (declared as int[] later in this unit).
extern sAnimNode_310F18* D_004FE7A0_310F18[] __asm__("D_004FE7A0");
extern sAnimNode_310F18* D_004FE860_310F18[] __asm__("D_004FE860");

extern "C" sAnimNode_310F18* func_00310F18(int bank, int n)
{
    D_004FE7A0_310F18[bank] = new (D_00489D50, 0x20000000, 0) sAnimNode_310F18[20];
    for (int i = 0; i < 20; i++)
    {
        D_004FE7A0_310F18[bank][i].next = &D_004FE7A0_310F18[bank][i] + 1;
        D_004FE7A0_310F18[bank][i].prev = &D_004FE7A0_310F18[bank][i] - 1;
        D_004FE7A0_310F18[bank][i].used = 0;
        D_004FE7A0_310F18[bank][i].data = new (D_00489D50, 0x20000000, 0) sAnimElem_310F18[n];
    }
    D_004FE7A0_310F18[bank][0].prev = &D_004FE7A0_310F18[bank][19];
    D_004FE7A0_310F18[bank][19].next = D_004FE7A0_310F18[bank];
    return D_004FE860_310F18[bank] = D_004FE7A0_310F18[bank];
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00311048);
#ifdef SKIP_ASM
extern void* D_004A3DF8;
extern "C" void func_00416210(void* dst, int c, int n);
// PORT: prototype mismatch. func_003110D0 is defined later in the unit as (void), but this
// caller passes the model in $4.
void func_003110D0_1(void* self) __asm__("func_003110D0");

extern "C" void* func_00311048(void* self)
{
    D_004A3DF8 = self;
    func_00416210(self, 0, 0x3FC);
    func_003110D0_1(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00311088);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void operator_delete(int*);
// func_00311110 ignores its argument (matched as (void)); the call here passes self in a0.
extern "C" void func_00311110_self(void* self) __asm__("func_00311110");

extern "C" void func_00311088(void* self, int flags)
{
    D_004A3DF8 = 0;
    func_00311110_self(self);
    if (flags & 1)
    {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_003110D0);
#ifdef SKIP_ASM
extern int D_004FE7A0[];
extern int D_004FE860[];

extern "C" void func_003110D0(void)
{
    for (int i = 0; i < 48; i++)
    {
        D_004FE7A0[i] = 0;
        D_004FE860[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00311110);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void cMemMan_free(void*);

struct sAnimNode_311110
{
    unsigned char* owner;       // 0x00
    void* data;                 // 0x04
    char pad8[0x14];
    sAnimNode_311110* prev;     // 0x1C
    sAnimNode_311110* next;     // 0x20
};

// Typed views of the pool tables (declared as int[] in this unit).
extern sAnimNode_311110* D_004FE7A0_311110[] __asm__("D_004FE7A0");
extern sAnimNode_311110* D_004FE860_311110[] __asm__("D_004FE860");

extern "C" void func_00311110(void)
{
    for (int bank = 0; bank < 48; bank++)
    {
        if (D_004FE7A0_311110[bank] != 0)
        {
            for (int i = 0; i < 20; i++)
            {
                if (D_004FE7A0_311110[bank][i].owner != 0)
                {
                    D_004FE7A0_311110[bank][i].owner[5] = 0xFF;
                }
                if (D_004FE7A0_311110[bank][i].data != 0)
                {
                    cMemMan_free(D_004FE7A0_311110[bank][i].data);
                }
            }
            if (D_004FE7A0_311110[bank] != 0)
            {
                cMemMan_free(D_004FE7A0_311110[bank]);
            }
            D_004FE7A0_311110[bank] = 0;
            D_004FE860_311110[bank] = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00311220);
#ifdef SKIP_ASM
extern "C" void func_00311290(void* self, char* data);

extern "C" void* func_00311220(void* self, char* data)
{
    *(int*)self = 0;
    func_00311290(self, data);
    return self;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00311250);
#ifdef SKIP_ASM
extern "C" char* func_003E22F0(void* src, int flags);

extern "C" void* func_00311250(char** self, void* src)
{
    char* data = func_003E22F0(src, 0);
    *self = data;
    func_00311290(self, data);
    return self;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00311290);
#ifdef SKIP_ASM
extern "C" void func_00311290(void* self, char* data)
{
    *(char**)((char*)self + 0x4) = data;
    *(char**)((char*)self + 0x8) = data + 0x10;
    *(char**)((char*)self + 0xC) = data + *(int*)(data + 0x4);
    *(char**)((char*)self + 0x10) = data + *(int*)(data + 0x8);
    *(char**)((char*)self + 0x14) = data + *(int*)(data + 0xC);
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_003112C8);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);

extern "C" void func_003112C8(void* self, int flags)
{
    void* p = *(void**)self;
    if (p != 0)
    {
        cMemMan_free(p);
    }
    if (flags & 1)
    {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("animation/animmodel", func_00311318);

