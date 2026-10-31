#include "common.h"

//100%
INCLUDE_ASM("object/flexrailnode", cFlexRailNode_addSpaceHash);
#ifdef SKIP_ASM
struct sHashKey_8B90 {
    int level;      // 0x0
    int x;          // 0x4
    int y;          // 0x8
    int z;          // 0xC
};

struct sHashCell_8B90 {
    char data[0x14];
};

struct sHashNode_8B90 {
    int field_0x0;
    int field_0x4;
    int type;       // 0x8
    void* owner;    // 0xC
};

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002D1BE0();
extern "C" void func_00328F28(sHashKey_8B90* out, void* box);
extern "C" void func_00328C20(sHashCell_8B90* cell, int type, sHashNode_8B90* node, sHashKey_8B90* key);
extern const char D_0048E808[];

extern "C" void cFlexRailNode_addSpaceHash(void* self)
{
    sHashNode_8B90* n = (sHashNode_8B90*)cMemMan_alloc(0x10, D_0048E808, 0x20000000, 0);
    n->owner = self;
    n->type = 3;
    *(sHashNode_8B90**)((char*)self + 0x54) = n;
    sHashCell_8B90* cell = (sHashCell_8B90*)func_002D1BE0();
    sHashNode_8B90* node = *(sHashNode_8B90**)((char*)self + 0x54);
    sHashKey_8B90 key;
    func_00328F28(&key, (char*)self + 0x30);
    sHashCell_8B90* c1 = key.x < 0 ? cell + 4 : cell;
    sHashCell_8B90* c2 = key.y < 0 ? c1 + 2 : c1;
    sHashCell_8B90* c3 = key.z < 0 ? c2 + 1 : c2;
    func_00328C20(c3, 2, node, &key);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00348C48);
#ifdef SKIP_ASM
void operator_delete(int*);
struct sOctCell_8C48 {
    void* child[8];
    void* lists[3];
};

struct sHashCellR_8C48 {
    char pad_0x0[0x10];
    sOctCell_8C48* oct;   // 0x10
};

extern "C" void func_003284B8(sOctCell_8C48* oct, int type, sHashNode_8B90* node, sHashKey_8B90* key, sHashCellR_8C48* cell);

static inline int octEmpty_8C48(sOctCell_8C48* o)
{
    if (o->child[0] != 0 || o->child[1] != 0 || o->child[2] != 0 || o->child[3] != 0
        || o->child[4] != 0 || o->child[5] != 0 || o->child[6] != 0 || o->child[7] != 0) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (o->lists[i] != 0) {
            return 0;
        }
    }
    return 1;
}

extern "C" void func_00348C48(void* self)
{
    sHashCellR_8C48* cell = (sHashCellR_8C48*)func_002D1BE0();
    sHashNode_8B90* node = *(sHashNode_8B90**)((char*)self + 0x54);
    (*(int*)((char*)cell + 0xA0))++;
    sHashKey_8B90 key;
    func_00328F28(&key, (char*)self + 0x30);
    sHashCellR_8C48* c1 = key.x < 0 ? cell + 4 : cell;
    sHashCellR_8C48* c2 = key.y < 0 ? c1 + 2 : c1;
    sHashCellR_8C48* c3 = key.z < 0 ? c2 + 1 : c2;
    sHashCellR_8C48* c = c3;
    func_003284B8(c->oct, 2, node, &key, c);
    if (octEmpty_8C48(c->oct)) {
        operator_delete((int*)c->oct);
        c->oct = 0;
    }
    operator_delete(*(int**)((char*)self + 0x54));
    *(void**)((char*)self + 0x54) = 0;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00348D98);
#ifdef SKIP_ASM
extern "C" void* func_00347D90(void* self, int type, void* a1, void* desc);
extern "C" void func_003492A8(void* self);
struct sFrBoxRail;
extern "C" void func_00349110(sFrBoxRail* self);
extern "C" void cFlexRailNode_addSpaceHash(void* self);
struct sFrNode9220;
extern "C" void func_00349220(void* self, sFrNode9220* node);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_0048FF30[];
extern char D_0048E820[];

struct sFrV_8D98 { float x, y, z, w; } __attribute__((aligned(16)));
extern sFrV_8D98 D_004FF120;

struct sFlexRailRef_348D98 {
    unsigned int id;
    sFlexRailRef_348D98() : id(0xFFFFFFFF) {}
};

struct sFlexRailElem_348D98 {
    sFrV_8D98 force;            // 0x00
    sFrV_8D98 vel;              // 0x10
    sFrV_8D98 posA;             // 0x20
    sFrV_8D98 posB;             // 0x30
    sFlexRailRef_348D98 link;   // 0x40
    int bone;                   // 0x44
    char pad48[8];
};

extern "C" void* func_00348D98(char* self, void* a1, char* desc)
{
    func_00347D90(self, 0x14, a1, desc);
    *(void**)(self + 0xC) = D_0048FF30;
    *(float*)(self + 0x60) = *(float*)(desc + 0x48);
    *(float*)(self + 0x64) = *(float*)(desc + 0x4C);
    *(float*)(self + 0x68) = *(float*)(desc + 0x50);
    sFlexRailRef_348D98 refs[8];
    int bones[8];
    int n = 0;
    unsigned int* ids = (unsigned int*)(desc + 4);
    int* bn = (int*)(desc + 0x24);
    for (int i = 0; i < 8; i++, ids++, bn++) {
        unsigned int id = *ids;
        if (id != 0xFFFFFFFF) {
            refs[n].id = id;
            bones[n] = *bn;
            n++;
        }
    }
    sFlexRailElem_348D98*& elems = *(sFlexRailElem_348D98**)(self + 0x70);
    elems = new (D_0048E820, 0x20000000, 0) sFlexRailElem_348D98[*(int*)(self + 0x20)];
    for (int j = 0; j < *(int*)(self + 0x20); j++) {
        (*(sFlexRailElem_348D98**)(self + 0x70))[j].link.id = refs[j].id;
        (*(sFlexRailElem_348D98**)(self + 0x70))[j].bone = bones[j];
        (*(sFlexRailElem_348D98**)(self + 0x70))[j].vel = D_004FF120;
        (*(sFlexRailElem_348D98**)(self + 0x70))[j].force = D_004FF120;
        func_00349220(self, (sFrNode9220*)&(*(sFlexRailElem_348D98**)(self + 0x70))[j]);
        (*(sFlexRailElem_348D98**)(self + 0x70))[j].posB = (*(sFlexRailElem_348D98**)(self + 0x70))[j].posA;
    }
    func_003492A8(self);
    func_00349110((sFrBoxRail*)self);
    cFlexRailNode_addSpaceHash(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00348FA0);
#ifdef SKIP_ASM
extern "C" void* func_00347EA8(void* self, void* a1, void* stream);
extern "C" void func_003492A8(void* self);
struct sFrBoxRail;
extern "C" void func_00349110(sFrBoxRail* self);
extern "C" void cFlexRailNode_addSpaceHash(void* self);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_0048FF30[];
extern char D_0048E820[];

struct sFlexRailRef_348FA0 {
    unsigned int id;
    sFlexRailRef_348FA0() : id(0xFFFFFFFF) {}
};

struct sFlexRailElem_348FA0 {
    char pad[0x40];
    sFlexRailRef_348FA0 link;
    char pad44[0xC];
};

struct sFrStreamVEntry_348FA0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_00348FA0(char* self, void* a1, void* stream)
{
    func_00347EA8(self, a1, stream);
    *(void**)(self + 0xC) = D_0048FF30;
    sFrStreamVEntry_348FA0* vt = *(sFrStreamVEntry_348FA0**)stream;
    vt[2].fn((char*)stream + vt[2].delta, self + 0x60, 0xC);
    sFlexRailElem_348FA0** elems = (sFlexRailElem_348FA0**)(self + 0x70);
    *elems = new (D_0048E820, 0x20000000, 0) sFlexRailElem_348FA0[*(int*)(self + 0x20)];
    sFrStreamVEntry_348FA0* vt2 = *(sFrStreamVEntry_348FA0**)stream;
    vt2[2].fn((char*)stream + vt2[2].delta, *(void**)(self + 0x70), *(int*)(self + 0x20) * 0x50);
    func_003492A8(self);
    func_00349110((sFrBoxRail*)self);
    cFlexRailNode_addSpaceHash(self);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flexrailnode", func_003490B0);
#ifdef SKIP_ASM
extern char D_0048FF30[];
void cMemMan_free(void*);
extern "C" void func_00348C48(void* self);
extern "C" void func_00347F90(void* self, int flags);

extern "C" void func_003490B0(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0048FF30;
    func_00348C48(self);
    void* p = *(void**)((char*)self + 0x70);
    if (p != 0) {
        cMemMan_free(p);
    }
    func_00347F90(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00349110);
#ifdef SKIP_ASM
struct sFrBoxVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sFrBoxElem {
    char pad_0x00[0x20];
    sFrBoxVec4 pos; // 0x20
    char pad_0x30[0x20];
};

struct sFrBoxRail {
    char pad_0x00[0x20];
    int count;          // 0x20
    char pad_0x24[0xC];
    sFrBoxVec4 min;     // 0x30
    sFrBoxVec4 max;     // 0x40
    char pad_0x50[0x20];
    sFrBoxElem* elems;  // 0x70
};

// PORT: PS2-only VU0 inline asm (vector sub-assign).
static inline void vu0SubFRBox(sFrBoxVec4& dst, sFrBoxVec4& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vu0AddFRBox(sFrBoxVec4& dst, sFrBoxVec4& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

// bounding box of the rail elements, padded by 200 on x/y/z
extern "C" void func_00349110(sFrBoxRail* self)
{
    sFrBoxElem* e = self->elems;
    int n = self->count;
    self->min = self->max = e[0].pos;
    for (int i = 1; i < n; i++) {
        sFrBoxVec4* p = &e[i].pos;
        if (p->x < self->min.x) {
            self->min.x = p->x;
        }
        if (p->y < self->min.y) {
            self->min.y = p->y;
        }
        if (p->z < self->min.z) {
            self->min.z = p->z;
        }
        if (p->x > self->max.x) {
            self->max.x = p->x;
        }
        if (p->y > self->max.y) {
            self->max.y = p->y;
        }
        if (p->z > self->max.z) {
            self->max.z = p->z;
        }
    }
    sFrBoxVec4 pad;
    pad.x = 200.0f;
    pad.y = 200.0f;
    pad.z = 200.0f;
    pad.w = 0.0f;
    vu0SubFRBox(self->min, pad);
    vu0AddFRBox(self->max, pad);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00349220);
#ifdef SKIP_ASM
struct sFrNodeVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sFrNodeMtx {
    sFrNodeVec4 r[4];
};

struct sFrModelSet9220 {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C, (model >> 2) << 8 | low byte
};

struct sFrWorld9220 {
    char pad_0x0[0x8];
    sFrModelSet9220** sets; // 0x8
};

extern "C" sFrWorld9220** func_002D1BD8();
extern "C" void func_0034FED8(void* model, int bone, sFrNodeMtx* out);

static inline void* refToPtr9220(unsigned int p)
{
    return (void*)(p << 2);
}

struct sFrModelRef9220 {
    unsigned int id;

    void* get()
    {
        sFrModelSet9220* set = (*func_002D1BD8())->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        unsigned int p = set->refs[id >> 8] >> 8;
        if (p == 0) {
            return 0;
        }
        return refToPtr9220(p);
    }
};

struct sFrNode9220 {
    char pad_0x0[0x20];
    sFrNodeVec4 posA;       // 0x20
    sFrNodeVec4 posB;       // 0x30
    sFrModelRef9220 model;  // 0x40
    int bone;               // 0x44
};

extern "C" void func_00349220(void* self, sFrNode9220* node)
{
    sFrNodeMtx m;
    func_0034FED8(node->model.get(), node->bone, &m);
    sFrNodeVec4 v = m.r[3];
    node->posB = v;
    node->posA = v;
}
#endif

INCLUDE_ASM("object/flexrailnode", func_003492A8);

//100%
INCLUDE_ASM("object/flexrailnode", func_00349798);
#ifdef SKIP_ASM
struct sFrVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sFrElem {
    sFrVec4 pos;   // 0x00
    sFrVec4 vel;   // 0x10
    char pad[0x30];
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sFrVec4 vu0ScaleFR(const sFrVec4& v, float s)
{
    sFrVec4 r;
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
static inline void vu0AddFR(sFrVec4& dst, sFrVec4 b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

extern "C" void func_00349798(void* self, void* node, sFrVec4* v)
{
    if (*(int*)((char*)node + 0x64) >= 0) {
        vu0AddFR((*(sFrElem**)((char*)self + 0x70))[*(int*)((char*)node + 0x64)].pos,
                 vu0ScaleFR(*v, 1.0f - *(float*)((char*)node + 0x68)));
        vu0AddFR((*(sFrElem**)((char*)self + 0x70))[*(int*)((char*)node + 0x64) + 1].pos,
                 vu0ScaleFR(*v, *(float*)((char*)node + 0x68)));
    }
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00349840);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector times scalar).
// PORT: PS2-only VU0 inline asm (vector add-assign).
extern "C" void func_00349840(void* self, void* node)
{
    if (*(int*)((char*)node + 0x64) >= 0) {
        vu0AddFR(*(sFrVec4*)((char*)node + 0x20),
                 vu0ScaleFR((*(sFrElem**)((char*)self + 0x70))[*(int*)((char*)node + 0x64)].vel,
                            *(float*)((char*)node + 0x68)));
        vu0AddFR(*(sFrVec4*)((char*)node + 0x20),
                 vu0ScaleFR((*(sFrElem**)((char*)self + 0x70))[*(int*)((char*)node + 0x64) + 1].vel,
                            1.0f - *(float*)((char*)node + 0x68)));
    }
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_003498E8);
#ifdef SKIP_ASM
struct sFrV_98E8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sFrN_98E8 {
    sFrV_98E8 force;            // 0x00
    sFrV_98E8 vel;              // 0x10
    sFrV_98E8 posA;             // 0x20
    sFrV_98E8 posB;             // 0x30
    sFrModelRef9220 model;      // 0x40
    int bone;                   // 0x44
    char pad48[8];
};

extern "C" float func_002D1C70();
extern "C" void func_00349220(void* self, sFrNode9220* node);
// View (func_00348D98 earlier in this unit declares it with its own type).
extern sFrV_98E8 D_004FF120_98E8 __asm__("D_004FF120");

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sFrV_98E8 vu0Sub_98E8(const sFrV_98E8& a, const sFrV_98E8& b)
{
    sFrV_98E8 r;
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sFrV_98E8 vu0Scale_98E8(const sFrV_98E8& v, float s)
{
    sFrV_98E8 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sFrV_98E8 vu0Add_98E8(const sFrV_98E8& a, const sFrV_98E8& b)
{
    sFrV_98E8 r;
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

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vu0AddEq_98E8(sFrV_98E8& dst, sFrV_98E8 b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

extern "C" void func_003498E8(char* self)
{
    float dt = func_002D1C70();
    sFrN_98E8* n = *(sFrN_98E8**)(self + 0x70);
    for (int i = 0; i < *(int*)(self + 0x20); i++, n++) {
        if (*(int*)((char*)n->model.get() + 0xC))
            func_00349220(self, (sFrNode9220*)n);
        float* k = (float*)(self + 0x60);
        float ks = -*(float*)(self + 0x60);
        sFrV_98E8 acc = vu0Add_98E8(vu0Scale_98E8(vu0Sub_98E8(n->posA, n->posB), ks),
                                    vu0Scale_98E8(n->force, k[2]));
        vu0AddEq_98E8(acc, vu0Scale_98E8(n->vel, -*(float*)(self + 0x64)));
        vu0AddEq_98E8(n->posA, vu0Scale_98E8(n->vel, dt));
        vu0AddEq_98E8(n->vel, vu0Scale_98E8(acc, dt));
        n->force = D_004FF120_98E8;
    }
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00349AD0);
#ifdef SKIP_ASM
struct sFlexRailVEntry9AD0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00348B40(void* self, void* stream);

extern "C" void func_00349AD0(void* self, void* stream)
{
    func_00348B40(self, stream);
    sFlexRailVEntry9AD0* e = &(*(sFlexRailVEntry9AD0**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x60, 0xC);
    e = &(*(sFlexRailVEntry9AD0**)stream)[1];
    e->fn((char*)stream + e->delta, *(void**)((char*)self + 0x70), *(int*)((char*)self + 0x20) * 0x50);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00349B48);
#ifdef SKIP_ASM
extern "C" void* func_00347D90(void* self, int type, void* a1, void* desc);
extern "C" void func_0034A0B0(void* self);
struct sFrBoxRail60;
extern "C" void func_00349F18(sFrBoxRail60* self);
struct sFrNodeA028;
extern "C" void func_0034A028(void* self, sFrNodeA028* node);
extern char D_0048FD90[];
extern char D_0048E830[];

struct sFrV_9B48 { float x, y, z, w; } __attribute__((aligned(16)));
extern sFrV_9B48 D_004FF120_9B48 __asm__("D_004FF120");

// PORT: PS2-only VU0 inline asm (a - b).
static inline sFrV_9B48 Sub_9B48(const sFrV_9B48& a, const sFrV_9B48& b)
{
    sFrV_9B48 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

struct sFlexRef_9B48 {
    unsigned int id;
    sFlexRef_9B48() : id(0xFFFFFFFF) {}
};

struct sFlexElem_9B48 {
    sFrV_9B48 pos;              // 0x00
    sFrV_9B48 dir;              // 0x10
    sFrV_9B48 v20;              // 0x20
    sFrV_9B48 v30;              // 0x30
    sFrV_9B48 v40;              // 0x40
    sFlexRef_9B48 link;         // 0x50
    int bone;                   // 0x54
    char pad58[8];
};

extern "C" void* func_00349B48(char* self, void* a1, char* desc)
{
    func_00347D90(self, 0x15, a1, desc);
    *(void**)(self + 0xC) = D_0048FD90;
    *(float*)(self + 0x60) = *(float*)(desc + 0x48);
    *(float*)(self + 0x64) = *(float*)(desc + 0x4C);
    *(float*)(self + 0x68) = *(float*)(desc + 0x50);
    sFlexRef_9B48 refs[8];
    int bones[8];
    int n = 0;
    unsigned int* ids = (unsigned int*)(desc + 4);
    int* bn = (int*)(desc + 0x24);
    for (int i = 0; i < 8; i++, ids++, bn++) {
        unsigned int id = *ids;
        if (id != 0xFFFFFFFF) {
            refs[n].id = id;
            bones[n] = *bn;
            n++;
        }
    }
    sFlexElem_9B48*& elems = *(sFlexElem_9B48**)(self + 0x70);
    elems = new (D_0048E830, 0x20000000, 0) sFlexElem_9B48[*(int*)(self + 0x20)];
    for (int j = 0; j < *(int*)(self + 0x20); j++) {
        (*(sFlexElem_9B48**)(self + 0x70))[j].link.id = refs[j].id;
        (*(sFlexElem_9B48**)(self + 0x70))[j].bone = bones[j];
        (*(sFlexElem_9B48**)(self + 0x70))[j].v30 = D_004FF120_9B48;
        (*(sFlexElem_9B48**)(self + 0x70))[j].v40 = D_004FF120_9B48;
        (*(sFlexElem_9B48**)(self + 0x70))[j].v20 = D_004FF120_9B48;
        (*(sFlexElem_9B48**)(self + 0x70))[j].dir = D_004FF120_9B48;
        func_0034A028(self, (sFrNodeA028*)&(*(sFlexElem_9B48**)(self + 0x70))[j]);
    }
    for (int k = 0; k < *(int*)(self + 0x20) - 1; k++) {
        (*(sFlexElem_9B48**)(self + 0x70))[k].dir =
            Sub_9B48((*(sFlexElem_9B48**)(self + 0x70))[k + 1].pos, (*(sFlexElem_9B48**)(self + 0x70))[k].pos);
    }
    func_0034A0B0(self);
    func_00349F18((sFrBoxRail60*)self);
    cFlexRailNode_addSpaceHash(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00349DB0);
#ifdef SKIP_ASM
extern "C" void* func_00347EA8(void* self, void* a1, void* stream);
extern "C" void func_0034A0B0(void* self);
extern "C" void cFlexRailNode_addSpaceHash(void* self);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_0048FD90[];
extern char D_0048E830[];

struct sFlexRailElem_349DB0 {
    char pad[0x50];
    unsigned int link;
    char pad54[0xC];
    sFlexRailElem_349DB0() : link(~0u) {}
};

struct sFrStreamVEntry_349DB0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_00349DB0(char* self, void* a1, void* stream)
{
    func_00347EA8(self, a1, stream);
    *(void**)(self + 0xC) = D_0048FD90;
    sFrStreamVEntry_349DB0* vt = *(sFrStreamVEntry_349DB0**)stream;
    vt[2].fn((char*)stream + vt[2].delta, self + 0x60, 0xC);
    sFlexRailElem_349DB0** elems = (sFlexRailElem_349DB0**)(self + 0x70);
    *elems = new (D_0048E830, 0x20000000, 0) sFlexRailElem_349DB0[*(int*)(self + 0x20)];
    sFrStreamVEntry_349DB0* vt2 = *(sFrStreamVEntry_349DB0**)stream;
    vt2[2].fn((char*)stream + vt2[2].delta, *(void**)(self + 0x70), *(int*)(self + 0x20) * 0x60);
    func_0034A0B0(self);
    cFlexRailNode_addSpaceHash(self);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flexrailnode", func_00349EB8);
#ifdef SKIP_ASM
extern char D_0048FD90[];
void cMemMan_free(void*);
extern "C" void func_00348C48(void* self);
extern "C" void func_00347F90(void* self, int flags);

extern "C" void func_00349EB8(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0048FD90;
    func_00348C48(self);
    void* p = *(void**)((char*)self + 0x70);
    if (p != 0) {
        cMemMan_free(p);
    }
    func_00347F90(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_00349F18);
#ifdef SKIP_ASM
struct sFrBoxElem60 {
    sFrBoxVec4 pos; // 0x00
    char pad_0x10[0x50];
};

struct sFrBoxRail60 {
    char pad_0x00[0x20];
    int count;           // 0x20
    char pad_0x24[0xC];
    sFrBoxVec4 min;      // 0x30
    sFrBoxVec4 max;      // 0x40
    char pad_0x50[0x20];
    sFrBoxElem60* elems; // 0x70
};

// PORT: PS2-only VU0 inline asm (vector sub-assign).
// PORT: PS2-only VU0 inline asm (vector add-assign).
// bounding box of the rail elements, padded by 200 on x/y/z
extern "C" void func_00349F18(sFrBoxRail60* self)
{
    sFrBoxElem60* e = self->elems;
    int n = self->count;
    self->min = self->max = e[0].pos;
    for (int i = 1; i < n; i++) {
        sFrBoxVec4* p = &e[i].pos;
        if (p->x < self->min.x) {
            self->min.x = p->x;
        }
        if (p->y < self->min.y) {
            self->min.y = p->y;
        }
        if (p->z < self->min.z) {
            self->min.z = p->z;
        }
        if (p->x > self->max.x) {
            self->max.x = p->x;
        }
        if (p->y > self->max.y) {
            self->max.y = p->y;
        }
        if (p->z > self->max.z) {
            self->max.z = p->z;
        }
    }
    sFrBoxVec4 pad;
    pad.x = 200.0f;
    pad.y = 200.0f;
    pad.z = 200.0f;
    pad.w = 0.0f;
    vu0SubFRBox(self->min, pad);
    vu0AddFRBox(self->max, pad);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034A028);
#ifdef SKIP_ASM
extern "C" sFrWorld9220** func_002D1BD8();
extern "C" void func_0034FED8(void* model, int bone, sFrNodeMtx* out);

struct sFrNodeA028 {
    sFrNodeVec4 pos;        // 0x0
    char pad_0x10[0x40];
    sFrModelRef9220 model;  // 0x50
    int bone;               // 0x54
};

extern "C" void func_0034A028(void* self, sFrNodeA028* node)
{
    sFrNodeMtx m;
    func_0034FED8(node->model.get(), node->bone, &m);
    sFrNodeVec4 v = m.r[3];
    node->pos = v;
}
#endif

INCLUDE_ASM("object/flexrailnode", func_0034A0B0);

//100%
INCLUDE_ASM("object/flexrailnode", func_0034A568);
#ifdef SKIP_ASM
struct sV4_A568 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sFrElem_A568 {
    sV4_A568 pos;               // 0x00
    sV4_A568 vel;               // 0x10
    sV4_A568 posA;              // 0x20
    sV4_A568 posB;              // 0x30
    sV4_A568 force;             // 0x40
    char pad50[0x10];
};

struct sFrNodeA568 {
    sV4_A568 pos;               // 0x00
    char pad10[0x54];
    int idx;                    // 0x64
};

struct sFrRailA568 {
    char pad0[0x60];
    float k[3];                 // 0x60
    char pad6C[4];
    sFrElem_A568* elems;        // 0x70
};

// PORT: PS2-only VU0 inline asm (vector length).
static inline float vu0Len_A568(const sV4_A568& v)
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_A568 vu0Scale_A568(const sV4_A568& v, float s)
{
    sV4_A568 r;
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

// PORT: PS2-only VU0 inline asm (vector times scalar, in place).
static inline void vu0ScaleEq_A568(sV4_A568& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(v), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_A568 vu0Sub_A568(const sV4_A568& a, const sV4_A568& b)
{
    sV4_A568 r;
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

// PORT: PS2-only VU0 inline asm (cross product).
static inline sV4_A568 vu0Cross_A568(const sV4_A568& a, const sV4_A568& b)
{
    sV4_A568 r;
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

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vu0AddEq_A568(sV4_A568& dst, sV4_A568 b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

extern "C" void func_0034A568(sFrRailA568* self, sFrNodeA568* node, sV4_A568* dir)
{
    float len = vu0Len_A568(*dir);
    sV4_A568 d;
    if (200.0f < len) {
        d = vu0Scale_A568(*dir, 200.0f / len);
    } else {
        d = *dir;
    }
    if (node->idx < 0) {
        return;
    }
    sV4_A568 a = vu0Sub_A568(node->pos, self->elems[0].pos);
    sV4_A568 c = vu0Cross_A568(d, a);
    float alen = vu0Len_A568(a);
    int i;
    for (i = 0; i < node->idx; i++) {
        float* k = self->k;
        sV4_A568 t = a;
        float lv = vu0Len_A568(self->elems[i].vel);
        vu0ScaleEq_A568(t, lv / vu0Len_A568(t));
        vu0AddEq_A568(self->elems[i].force, vu0Scale_A568(vu0Scale_A568(c, vu0Len_A568(self->elems[i].vel) / alen), k[2]));
    }
    float* k = self->k;
    vu0AddEq_A568(self->elems[node->idx].force, vu0Scale_A568(vu0Scale_A568(c, vu0Len_A568(vu0Sub_A568(node->pos, self->elems[node->idx].pos)) / alen), k[2]));
}
#endif

INCLUDE_ASM("object/flexrailnode", func_0034A838);

//100%
INCLUDE_ASM("object/flexrailnode", func_0034A8C8);
#ifdef SKIP_ASM
extern "C" float func_002D1C70();

struct sV4_A8C8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sV4Slot_A8C8 {
    sV4_A8C8 v;
    sV4Slot_A8C8() {}
};

// PORT: the unit declares D_004FF120 with another vector type; alias it here.
extern sV4_A8C8 D_004FF120_A8C8 __asm__("D_004FF120");

struct sFrElem_A8C8 {
    sV4_A8C8 pos;               // 0x00
    sV4_A8C8 vel;               // 0x10
    sV4_A8C8 posA;              // 0x20
    sV4_A8C8 posB;              // 0x30
    sV4_A8C8 force;             // 0x40
    char pad50[0x10];
};

struct sFrRailA8C8 {
    char pad0[0x20];
    int count;                  // 0x20
    char pad24[0x3C];
    float k[3];                 // 0x60
    char pad6C[4];
    sFrElem_A8C8* elems;        // 0x70
};

// PORT: PS2-only VU0 inline asm (vector length).
static inline float vu0Len_A8C8(const sV4_A8C8& v)
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

// PORT: PS2-only VU0 inline asm (normalize).
static inline sV4_A8C8 vu0Norm_A8C8(const sV4_A8C8& v)
{
    sV4_A8C8 r;
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
static inline sV4_A8C8 vu0Scale_A8C8(const sV4_A8C8& v, float s)
{
    sV4_A8C8 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_A8C8 vu0Add_A8C8(const sV4_A8C8& a, const sV4_A8C8& b)
{
    sV4_A8C8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (cross product).
static inline sV4_A8C8 vu0Cross_A8C8(const sV4_A8C8& a, const sV4_A8C8& b)
{
    sV4_A8C8 r;
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

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vu0AddEq_A8C8(sV4_A8C8& dst, const sV4_A8C8& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b)
        : "memory");
}

extern "C" void func_0034A8C8(sFrRailA8C8* self)
{
    float dt = func_002D1C70();
    sV4Slot_A8C8 f[8];
    for (int i = 0; i < self->count - 1; i++) {
        f[i].v = vu0Scale_A8C8(self->elems[i].posA, -self->k[0]);
        vu0AddEq_A8C8(f[i].v, vu0Scale_A8C8(self->elems[i].posB, -self->k[1]));
    }
    for (int i = 0; i < self->count - 1; i++) {
        vu0AddEq_A8C8(f[i].v, self->elems[i].force);
    }
    for (int i = 0; i < self->count - 1; i++) {
        sV4_A8C8 a;
        a = vu0Scale_A8C8(f[i].v, dt);
        vu0AddEq_A8C8(self->elems[i].posA, vu0Scale_A8C8(self->elems[i].posB, dt));
        vu0AddEq_A8C8(self->elems[i].posB, a);
    }
    sV4_A8C8 acc = D_004FF120_A8C8;
    for (int i = 0; i < self->count - 1; i++) {
        vu0AddEq_A8C8(acc, self->elems[i].posA);
        float len = vu0Len_A8C8(self->elems[i].vel);
        sV4_A8C8 s = vu0Scale_A8C8(vu0Norm_A8C8(vu0Add_A8C8(self->elems[i].vel, vu0Cross_A8C8(self->elems[i].vel, acc))), len);
        self->elems[i + 1].pos = vu0Add_A8C8(self->elems[i].pos, s);
    }
    for (int i = 0; i < self->count; i++) {
        self->elems[i].force = D_004FF120_A8C8;
    }
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AC10);
#ifdef SKIP_ASM
struct sFlexRailVEntryAC10 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00348B40(void* self, void* stream);

extern "C" void func_0034AC10(void* self, void* stream)
{
    func_00348B40(self, stream);
    sFlexRailVEntryAC10* e = &(*(sFlexRailVEntryAC10**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x60, 0xC);
    e = &(*(sFlexRailVEntryAC10**)stream)[1];
    e->fn((char*)stream + e->delta, *(void**)((char*)self + 0x70), *(int*)((char*)self + 0x20) * 0x60);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AC88);
#ifdef SKIP_ASM
extern char* D_004A5B64;

struct sFrRailDesc;

struct sFrRailOut_AC88 {
    char on0, on1, on2, on3;  // 0x0
    float a[4];               // 0x4
    float b[4];               // 0x14
    float c[4];               // 0x24
    float p[3];               // 0x34
    float q[4];               // 0x40
    float r0;                 // 0x50
    float r1;                 // 0x54
};

struct sFrRailTriple_AC88 {
    float a, b, c;
};

struct sFrRailSrc_AC88 {
    int f0;
    int on0, on1, on2;        // 0x4
    sFrRailTriple_AC88 t[4];  // 0x10
    float p[3];               // 0x40
    float q[4];               // 0x4C
    float r0;                 // 0x5C
    float r1;                 // 0x60
    int on3;                  // 0x64
};

static inline float perSec_34AC88(float x)
{
    return x * (1.0f / (float)*(int*)(D_004A5B64 + 0x10));
}

extern "C" sFrRailDesc* func_0034AC88(sFrRailDesc* out, void* src)
{
    sFrRailOut_AC88* d = (sFrRailOut_AC88*)out;
    sFrRailSrc_AC88* s = (sFrRailSrc_AC88*)src;
    d->on0 = s->on0 != 0;
    d->on1 = s->on1 != 0;
    d->on2 = s->on2 != 0;
    d->on3 = s->on3 != 0;
    {
        float x = s->p[0];
        float y = s->p[1];
        float z = s->p[2];
        d->p[0] = x;
        d->p[1] = y;
        d->p[2] = z;
    }
    {
        float x = s->q[0];
        float y = s->q[1];
        float z = s->q[2];
        d->q[0] = x;
        d->q[1] = y;
        d->q[2] = z;
    }
    d->q[3] = s->q[3];
    d->r0 = perSec_34AC88(s->r0);
    d->r1 = perSec_34AC88(s->r1);
    d->a[0] = perSec_34AC88(s->t[0].a);
    d->b[0] = s->t[0].b;
    d->c[0] = s->t[0].c;
    d->a[1] = perSec_34AC88(s->t[1].a);
    d->b[1] = s->t[1].b;
    d->c[1] = s->t[1].c;
    d->a[2] = perSec_34AC88(s->t[2].a);
    d->b[2] = s->t[2].b;
    d->c[2] = s->t[2].c;
    d->a[3] = perSec_34AC88(s->t[3].a);
    d->b[3] = s->t[3].b;
    d->c[3] = s->t[3].c;
    return out;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flexrailnode", func_0034ADD8);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, void* a1, int type, void* a3);
extern "C" void* func_002D1CB0(void);
extern char D_0048FC10[];

struct sFrRailDesc {
    int data[0x58 / 4];
};

extern "C" sFrRailDesc* func_0034AC88(sFrRailDesc* out, void* src);
extern "C" void func_0034C548(void* mgr, void* node, sFrRailDesc* desc);

extern "C" void* func_0034ADD8(void* self, void* a1, void* node, void* src)
{
    sFrRailDesc desc;
    func_0034FB00(self, a1, 0xA, node);
    *(void**)((char*)self + 0xC) = D_0048FC10;
    *(unsigned int*)((char*)node + 0x8) = (*(unsigned int*)((char*)node + 0x8) & 0xFFFFFFFD) | 4;
    func_0034AC88(&desc, src);
    func_0034C548(func_002D1CB0(), node, &desc);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AE68);
#ifdef SKIP_ASM
extern "C" void* cInstanceNode_cInstanceNode(void* self, void* a1, void* stream);
extern char D_0048FC10[];

extern "C" void* func_0034AE68(void* self, void* a1, void* stream)
{
    cInstanceNode_cInstanceNode(self, a1, stream);
    *(void**)((char*)self + 0xC) = D_0048FC10;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AEA0);
#ifdef SKIP_ASM
extern char D_0048FC10[];
extern "C" void* func_002D1CB0(void);
extern "C" void func_0034C600(void* set, void* arg);
extern "C" void func_0034FBF0(void* self, int flags);

extern "C" void func_0034AEA0(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0048FC10;
    func_0034C600(func_002D1CB0(), *(void**)((char*)self + 0x18));
    func_0034FBF0(self, flags);
}
#endif

extern "C" void* func_0034FE90(void* self);

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AEF8__FPv);
#ifdef SKIP_ASM
void* func_0034AEF8(void* self)
{
    return func_0034FE90(self);
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AF18__FPv);
#ifdef SKIP_ASM
void func_0034AF18(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AF20);
#ifdef SKIP_ASM
extern "C" void* func_0034AF20(void* self)
{
    *(int*)((char*)self + 0x5c) = 0;
    *(unsigned int*)((char*)self + 0x58) = 0xFFFFFFFFU;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AF38);
#ifdef SKIP_ASM
extern int D_004A4010;
extern void* D_0048FBF8[];

struct sFlexRail_AF38 {
    char pad_0x0[0x60];
    int f60;            // 0x60
    char pad_0x64[0x10];
    int f74;            // 0x74
    char pad_0x78[0x18];
    int f90;            // 0x90
    int slots[60];      // 0x94
    void** vt;          // 0x184
};

extern "C" void* func_0034AF38(void* self)
{
    sFlexRail_AF38* s = (sFlexRail_AF38*)self;
    int i;
    func_0034AF20(self);
    s->f60 = 0;
    s->f74 = 0;
    s->vt = D_0048FBF8;
    for (i = 0; i < 60; i++) {
        s->slots[i] = 0;
    }
    int id = D_004A4010;
    s->f90 = id;
    D_004A4010 = id + 1;
    if (D_004A4010 >= 2) {
        D_004A4010 = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AFB8);
#ifdef SKIP_ASM
extern void* D_0048FBF8[];
void operator_delete(int*);

extern "C" void func_0034AFB8(void* self, int flags)
{
    *(void***)((char*)self + 0x184) = D_0048FBF8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034AFE8);
#ifdef SKIP_ASM
extern "C" int func_00415FC8(const void* a, const void* b, int n);

extern "C" int func_0034AFE8(void* self, void* data, void* ctx)
{
    if (*(int*)((char*)self + 0x5C) == 0) {
        return 0;
    }
    if (**(int**)((char*)ctx + 0x80) != *(int*)((char*)self + 0x58)) {
        return 0;
    }
    return func_00415FC8(data, self, 0x58) == 0;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034B038);
#ifdef SKIP_ASM
extern "C" void cFlagSet_CreateMesh(void* self, void* mesh);

struct sFlagDef_34B038 {
    int v[0x58 / 4];
};

struct sFlagSet_34B038 {
    sFlagDef_34B038 def;
    int f58;
    int count;
    char pad60[0x94 - 0x60];
    void* meshes[1];
};

extern "C" void func_0034B038(sFlagSet_34B038* self, sFlagDef_34B038* def, char* mesh)
{
    if (self->count == 0) {
        self->def = *def;
        self->f58 = **(int**)(mesh + 0x80);
        cFlagSet_CreateMesh(self, mesh);
    }
    self->meshes[self->count] = mesh;
    self->count++;
}
#endif

//100%
INCLUDE_ASM("object/flexrailnode", func_0034B168);
#ifdef SKIP_ASM
struct sFrRider_B168 {
    char pad_0x0[0x78];
    int id;                 // 0x78
    char pad_0x7c[0x4];
    int* track;             // 0x80
};

struct sFrRail_B168 {
    char pad_0x0[0x58];
    int track;              // 0x58
    int count;              // 0x5C
    char pad_0x60[0x34];
    sFrRider_B168* riders[1]; // 0x94
};

extern "C" void func_0034B7B8(void* self);

extern "C" int func_0034B168(sFrRail_B168* self, sFrRider_B168* rider)
{
    if (self->count == 0) {
        return 0;
    }
    if (*rider->track != self->track) {
        return 0;
    }
    for (int i = 0; i < self->count; i++) {
        if (self->riders[i]->id == rider->id) {
            self->riders[i] = self->riders[self->count - 1];
            self->riders[self->count - 1] = 0;
            if (--self->count == 0) {
                func_0034B7B8(self);
            }
            return 1;
        }
    }
    return 0;
}
#endif

