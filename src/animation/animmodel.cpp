#include "common.h"

//100%
INCLUDE_ASM("animation/animmodel", cAnimModel_addModelPartLOD);
#ifdef SKIP_ASM
// PORT: operator_new__FUi is the game's tagged allocator (size, tag, flags, d); bound by asm label
// as operator new[] so the new-expressions below compute their destination before the call.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00489C80[];
extern "C" void func_003E6448(void* dst, int c, int n);

struct sLodRef_D8B8 {
    char* part;     // 0x0
    char* data;     // 0x4
    int pad[2];
};

struct sLodSlot_D8B8 {
    int used;               // 0x0
    sLodRef_D8B8* refs;     // 0x4
};

struct sModelPart_D8B8 {
    int id;                 // 0x00
    char pad4[0x14];
    sLodSlot_D8B8 lods[4];  // 0x18
    char* p38;              // 0x38
    char* p3C;              // 0x3C
    char* p40;              // 0x40
    int h44;                // 0x44
    int h48;                // 0x48
    int h4C;                // 0x4C
    int index;              // 0x50
    int pad54;
};

struct sAnimModel_D8B8 {
    int f0;
    int nrefs;                  // 0x4
    int count;                  // 0x8
    sModelPart_D8B8* parts;     // 0xC
};

extern "C" void cAnimModel_addModelPartLOD(sAnimModel_D8B8* self, int lod, char* part, int index)
{
    char* data = part + 0x60;
    for (int i = 0; i < self->count; i++) {
        if (self->parts[i].id == *(signed char*)(part + 0x52)) {
            self->parts[i].lods[lod].used = 1;
            self->parts[i].lods[lod].refs[index].part = part;
            self->parts[i].lods[lod].refs[index].data = data;
            return;
        }
    }
    for (int k = 0; k < 4; k++) {
        self->parts[self->count].lods[k].refs = new (D_00489C80, 0, 0) sLodRef_D8B8[self->nrefs];
        func_003E6448(self->parts[self->count].lods[k].refs, 0, self->nrefs << 4);
    }
    self->parts[self->count].id = *(signed char*)(part + 0x52);
    self->parts[self->count].lods[lod].used = 1;
    self->parts[self->count].lods[lod].refs[index].part = part;
    self->parts[self->count].lods[lod].refs[index].data = data;
    self->parts[self->count].p38 = data + *(int*)(part + 0x18);
    self->parts[self->count].p40 = data + *(int*)(part + 0x2C);
    self->parts[self->count].p3C = data + *(int*)(part + 0x1C);
    self->parts[self->count].h44 = *(short*)(part + 0x4A);
    self->parts[self->count].h48 = *(short*)(part + 0x4E);
    self->parts[self->count].h4C = *(short*)(part + 0x50);
    self->parts[self->count].index = index;
    self->count++;
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
struct sVec4_0030DBA0
{
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" void func_0030DBA0(void* self, float a, float b)
{
    sVec4_0030DBA0 v;
    v.x = a;
    v.y = b;
    v.z = b;
    v.w = 1.0f;
    *(sVec4_0030DBA0*)((char*)self + 0x140) = v;
}
#endif

INCLUDE_ASM("animation/animmodel", cAnimModel_compile);

//100%
INCLUDE_ASM("animation/animmodel", func_0030E9E0);
#ifdef SKIP_ASM
struct sAnimChannel_0030E9E0
{
    int active;
    int pad;
};

struct sAnimEntry_0030E9E0
{
    char pad[0x10];
    ulong mask;                          // 0x10
    sAnimChannel_0030E9E0 channels[4];   // 0x18
    char pad2[0x18];
    int param;                           // 0x50
    int pad3;
};

struct sAnimModel_0030E9E0
{
    char pad0[0x8];
    int numEntries;               // 0x8
    sAnimEntry_0030E9E0* entries; // 0xC
    char pad1[0x4];
    int count;                    // 0x14
    char pad2[0x4];
    int* indices;                 // 0x1C
    char pad3[0x130];
    ulong mask;                   // 0x150
};

// PORT: ulong is 64-bit here
extern "C" void func_0030E9E0(sAnimModel_0030E9E0* self, int i, int channel)
{
    if (i > self->count)
    {
        return;
    }
    if (self->indices == 0)
    {
        return;
    }
    int idx = self->indices[i];
    if (idx < 0)
    {
        return;
    }
    sAnimEntry_0030E9E0* e = &self->entries[idx];
    self->mask |= e->mask;
    if (channel < 0)
    {
        for (int k = 0; k < 4; k++)
        {
            e->channels[k].active = 1;
        }
    }
    else
    {
        e->channels[channel].active = 1;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030EA80);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_0030EA80(sAnimModel_0030E9E0* self, int i, int channel)
{
    if (i > self->count)
    {
        return;
    }
    if (self->indices == 0)
    {
        return;
    }
    int idx = self->indices[i];
    if (idx < 0)
    {
        return;
    }
    sAnimEntry_0030E9E0* e = &self->entries[idx];
    self->mask &= ~e->mask;
    if (channel < 0)
    {
        for (int k = 0; k < 4; k++)
        {
            e->channels[k].active = 0;
        }
    }
    else
    {
        e->channels[channel].active = 0;
        for (int k = 0; k < 4; k++)
        {
            if (e->channels[k].active)
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
extern "C" void func_0030EB60(sAnimModel_0030E9E0* self)
{
    for (int j = 0; j < self->numEntries; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            self->entries[j].channels[k].active = 0;
        }
    }
    self->mask = 0;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030EBC0);
#ifdef SKIP_ASM
extern "C" int func_0030EBC0(sAnimModel_0030E9E0* self, int i, int channel)
{
    int idx;
    if (i > self->count || self->indices == 0 || (idx = self->indices[i]) < 0)
    {
        return 0;
    }
    return self->entries[idx].channels[channel].active;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030EC18);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_0030EC18(sAnimModel_0030E9E0* self, int i, int param)
{
    if (i > self->count)
    {
        return;
    }
    if (self->indices == 0)
    {
        return;
    }
    int idx = self->indices[i];
    if (idx < 0)
    {
        return;
    }
    sAnimEntry_0030E9E0* e = &self->entries[idx];
    e->param = param;
    self->mask |= e->mask;
    for (int k = 0; k < 4; k++)
    {
        e->channels[k].active = 1;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_0030ECA0);
#ifdef SKIP_ASM
struct sAnimEntry_0030ECA0
{
    char pad[0x10];
    ulong mask;
    char pad2[0x40];
};

struct sAnimModel_0030ECA0
{
    char pad0[0xC];
    sAnimEntry_0030ECA0* entries; // 0xC
    char pad1[0xC];
    int* indices;                 // 0x1C
    char pad2[0x138];
    ulong mask;                   // 0x158
};

// PORT: ulong is 64-bit here
extern "C" void func_0030ECA0(sAnimModel_0030ECA0* self, int i)
{
    sAnimEntry_0030ECA0* e = &self->entries[self->indices[i]];
    self->mask |= e->mask;
}
#endif

INCLUDE_ASM("animation/animmodel", func_0030ECD8);

INCLUDE_ASM("animation/animmodel", func_0030F2B0);

INCLUDE_ASM("animation/animmodel", func_00310120);

INCLUDE_ASM("animation/animmodel", func_00310200);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/animmodel", func_003103F0);
#ifdef SKIP_ASM
struct sAm3103F0Pair
{
    char pad[0x20];
};

struct sAm3103F0
{
    char pad0[0x10];
    int count;
    char pad14[0x18];
    sAm3103F0Pair* pairs;
};

extern "C" void func_00310120(sAm3103F0* self, int i, sAm3103F0Pair* p);

extern "C" void func_003103F0(sAm3103F0* self)
{
    int i;
    for (i = 0; i < self->count; i++)
    {
        func_00310120(self, i, &self->pairs[i]);
    }
}
#endif

INCLUDE_ASM("animation/animmodel", func_00310458);

//100%
INCLUDE_ASM("animation/animmodel", func_00310530);
#ifdef SKIP_ASM
struct sAmVec4
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sAmMtx
{
    sAmVec4 row[4];
};

struct sAmPair
{
    sAmVec4 a;
    sAmVec4 b;
};

struct sAmEntry
{
    int unk0;
    int start;
    char pad8[0x3C];
    int count;
    char pad48[0x10];
};

struct sAmModel
{
    int unk0;
    int unk4;
    int numEntries;
    sAmEntry* entries;
    char pad10[0x1C];
    sAmPair* pairs;
    sAmMtx* mtxA;
    sAmMtx* mtxB;
};

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void amVecAddEq(sAmVec4* dst, sAmVec4* v)
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
static inline sAmVec4 amVecAdd(const sAmVec4& src, sAmVec4* b)
{
    sAmVec4 a = src;
    sAmVec4 r;
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

extern "C" void func_00310530(sAmModel* self, sAmVec4* v)
{
    for (int i = 0; i < self->numEntries; i++) {
        for (int j = 0; j < self->entries[i].count; j++) {
            int k = j + self->entries[i].start;
            amVecAddEq(&self->pairs[k].a, v);
            {
                sAmVec4 t = amVecAdd(self->mtxA[k].row[3], v);
                self->mtxA[k].row[3] = t;
            }
            {
                sAmVec4 t = amVecAdd(self->mtxB[k].row[3], v);
                self->mtxB[k].row[3] = t;
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

struct sAmRef_0640 {
    char* part;     // 0x0
    char* data;     // 0x4
    int f8;         // 0x8
    int fC;         // 0xC
};

struct sAmLod_0640 {
    int used;               // 0x0
    sAmRef_0640* refs;      // 0x4
};

struct sAmPart_0640 {
    int id;                 // 0x00
    char pad4[0x14];
    sAmLod_0640 lods[4];    // 0x18
    char pad38[0x18];
    int index;              // 0x50
    int pad54;
};

struct sAmLodInfo_0640 {
    int a;      // 0x0
    int b;      // 0x4
};

struct sAmModel_0640 {
    int f0;
    int f4;
    int count;                  // 0x8
    sAmPart_0640* parts;        // 0xC
    int nmats;                  // 0x10
    int f14;
    int lodded;                 // 0x18
    char pad1C[0x18];
    sAmMat_0640* matsA;         // 0x34
    sAmMat_0640* matsB;         // 0x38
    int f3C;
    sAmLodInfo_0640 info[4];    // 0x40
    char pad60[0x144 - 0x60];
    float alpha;                // 0x144
};

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

extern "C" void func_00310640(sAmModel_0640* self, int lod, int x, int y)
{
    sAmCtx_0640* ctx = D_004A5B80_0640;
    if (D_004A5948 == 0) {
        new ((void*)D_004FC420) sAmMat_0640[64];
        D_004A5948 = 1;
    }
    for (int i = 0; i < self->nmats; i++) {
        D_004FC420[i] = mulMat_0640(self->matsA[i], self->matsB[i]);
    }
    if (self->lodded != 0) {
        for (int j = 0; j < self->count; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAmPart_0640* p = (sAmPart_0640*)(j * (int)sizeof(sAmPart_0640) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAmRef_0640* r = &p->lods[lod].refs[p->index];
                if (r->part != 0) {
                    ((tSetMats_0640)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FC420, 0, r->fC, r->f8, 0);
                    int m = self->parts[j].id == 2 ? x : y;
                    ((tDraw_0640)ctx->vt[99].fn)((char*)ctx + ctx->vt[99].delta, r->part, r->data, m, 0, self->alpha);
                }
            }
        }
    } else {
        ((tSetMats_0640)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FC420, 0, self->info[lod].b, self->info[lod].a, 0);
        for (int j = 0; j < self->count; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAmPart_0640* p = (sAmPart_0640*)(j * (int)sizeof(sAmPart_0640) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAmRef_0640* r = p->lods[lod].refs;
                if (r->part != 0) {
                    int m = p->id == 2 ? x : y;
                    ((tDraw_0640)ctx->vt[99].fn)((char*)ctx + ctx->vt[99].delta, r->part, r->data, m, 0, self->alpha);
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

struct sAmRef_0948 {
    char* part;     // 0x0
    char* data;     // 0x4
    int f8;         // 0x8
    int fC;         // 0xC
};

struct sAmLod_0948 {
    int used;               // 0x0
    sAmRef_0948* refs;      // 0x4
};

struct sAmPart_0948 {
    int id;                 // 0x00
    char pad4[0x14];
    sAmLod_0948 lods[4];    // 0x18
    char pad38[0x18];
    int index;              // 0x50
    int pad54;
};

struct sAmLodInfo_0948 {
    int a;      // 0x0
    int b;      // 0x4
};

struct sAmModel_0948 {
    int f0;
    int f4;
    int count;                  // 0x8
    sAmPart_0948* parts;        // 0xC
    int nmats;                  // 0x10
    int f14;
    int lodded;                 // 0x18
    char pad1C[0x14];
    sAmMat_0948* matsA;         // 0x30
    int f34;
    sAmMat_0948* matsB;         // 0x38
    int f3C;
    sAmLodInfo_0948 info[4];    // 0x40
};

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

extern "C" void func_00310948(sAmModel_0948* self, int lod, int x, int y)
{
    if (D_004A594C == 0) {
        new ((void*)D_004FD420) sAmMat_0948[64];
        D_004A594C = 1;
    }
    sAmCtx_0948* ctx = D_004A5B80_0948;
    for (int i = 0; i < self->nmats; i++) {
        D_004FD420[i] = mulMat_0948(self->matsA[i], self->matsB[i]);
    }
    if (self->lodded != 0) {
        for (int j = 0; j < self->count; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAmPart_0948* p = (sAmPart_0948*)(j * (int)sizeof(sAmPart_0948) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAmRef_0948* r = &p->lods[lod].refs[p->index];
                if (r->part != 0) {
                    ((tSetMats_0948)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FD420, 0, r->fC, r->f8, 0);
                    int ok = (unsigned)(self->parts[j].id - 1) < 2;
                    int m = ok ? x : y;
                    ((tDraw_0948)ctx->vt[100].fn)((char*)ctx + ctx->vt[100].delta, r->part, r->data, m);
                }
            }
        }
    } else {
        ((tSetMats_0948)ctx->vt[111].fn)((char*)ctx + ctx->vt[111].delta, D_004FD420, 0, self->info[lod].b, self->info[lod].a, 0);
        for (int j = 0; j < self->count; j++) {
            // PORT: pointer arithmetic through int (offset-first addu).
            sAmPart_0948* p = (sAmPart_0948*)(j * (int)sizeof(sAmPart_0948) + (int)self->parts);
            if (p->lods[lod].used != 0) {
                sAmRef_0948* r = p->lods[lod].refs;
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

struct sAmGroup58 {
    int pad0;
    int first;
    char pad8[0x30];
    sAmItem50* items;
    char pad3C[0x8];
    int count;
    char pad48[0x10];
};

extern "C" int func_00310C48(void* self, int idx, const char* name)
{
    sAmGroup58* g = &(*(sAmGroup58**)((char*)self + 0xC))[(*(int**)((char*)self + 0x1C))[idx]];
    sAmItem50* items = g->items;
    for (int i = 0; i < g->count; i++)
    {
        if (func_004165A8(&items[i], name) == 0)
            return g->first + i;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310CE8);
#ifdef SKIP_ASM
extern "C" int func_00416B18(const char* a, const char* b, int n);
extern char D_004A3DF0[];

struct sAnimPart_0CE8 {
    int f0;
    int firstBit;               // 0x4
    int f8;
    int chanBit;                // 0xC
    char pad10[0x38 - 0x10];
    char* names;                // 0x38 (0x50-byte entries)
    char pad3C[0x44 - 0x3C];
    int count;                  // 0x44
    char pad48[0x58 - 0x48];
};

// PORT: returns a 64-bit mask (long is 8 bytes on the EE).
extern "C" ulong func_00310CE8(char* self, int idx, char* names)
{
    if (*(int*)(self + 0x14) < idx)
        return 0;
    int* tbl = *(int**)(self + 0x1C);
    if (tbl == 0 || tbl[idx] < 0)
        return 0;
    char* p = names;
    ulong mask = 0;
    sAnimPart_0CE8* part = &(*(sAnimPart_0CE8**)(self + 0xC))[tbl[idx]];
    while (*p) {
        char* q = p;
        if (*q != 0 && *q != ',') {
            do
                q++;
            while (*q != 0 && *q != ',');
        }
        int len = q - p;
        if (part->chanBit >= 0 && func_00416B18(p, D_004A3DF0, len) == 0) {
            mask |= (ulong)1 << (part->chanBit + *(int*)(self + 0x10));
        } else {
            char* list = part->names;
            int j = 0;
            ulong one = 1;
            for (; j < part->count; j++) {
                if (func_00416B18(list + j * 0x50, p, len) == 0 && *(list + len + j * 0x50) == 0) {
                    mask |= one << (part->firstBit + j);
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

extern "C" void func_00310EA8(void* self, cAmStream* s)
{
    s->read(*(void**)((char*)self + 0x2C), *(int*)((char*)self + 0x10) << 5);
}
#endif

//100%
INCLUDE_ASM("animation/animmodel", func_00310EE0);
#ifdef SKIP_ASM
extern "C" void func_00310EE0(void* self, cAmStream* s)
{
    s->write(*(void**)((char*)self + 0x2C), *(int*)((char*)self + 0x10) << 5);
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

INCLUDE_ASM("animation/animmodel", func_00311088);

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

