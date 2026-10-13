#include "common.h"

//100%
INCLUDE_ASM("object/animnode", cAnimNode_setAnimMeshCache);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_003513D0(void* self);
extern "C" void func_003612C0(void* self);
extern "C" void func_00351398(void* self, void* src);
extern char D_0048E860[];
extern char D_0048E870[];
extern void* D_00490AD0[];
extern void* D_00490AF0[];

struct sMeshInst_E448 {
    char pad_0x0[0x84];
    void** vtable;          // 0x84
    char pad_0x88[0x48];
    sMeshInst_E448()
    {
        vtable = D_00490AF0;
        func_003513D0(this);
        vtable = D_00490AD0;
        func_003612C0(this);
    }
    void operator delete[](void* p, unsigned int size);
};

struct sMeshRef_E448 {
    char data[0x20];
    sMeshRef_E448() {}
};

struct sAnimEntry_E448 {
    int pad_0x0[2];
    void* src;              // 0x8
    int pad_0xC;
};

struct sAnimDef_E448 {
    int pad_0x0;
    int count;                  // 0x4
    sAnimEntry_E448* entries;   // 0x8
};

struct sAnimNode_E448 {
    char pad_0x0[0x2C];
    char* res;                  // 0x2C
    char pad_0x30[0x10];
    int numMeshes;              // 0x40
    int pad_0x44;
    sMeshInst_E448* meshes;     // 0x48
    sMeshRef_E448* refs;        // 0x4C
};

extern "C" void cAnimNode_setAnimMeshCache(sAnimNode_E448* self)
{
    sAnimDef_E448* def = *(sAnimDef_E448**)(self->res + 0x80);
    sAnimEntry_E448* e = def->entries;
    int i;
    self->numMeshes = 0;
    for (i = 0; i < def->count; i++, e++) {
        if (e->src != 0)
            self->numMeshes++;
    }
    if (self->numMeshes != 0) {
        sMeshInst_E448*& meshes = self->meshes;
        meshes = new (D_0048E860, 0x20000000, 0) sMeshInst_E448[self->numMeshes];
    } else {
        self->meshes = 0;
    }
    sMeshRef_E448*& refs = self->refs;
    refs = new (D_0048E870, 0x20000000, 0) sMeshRef_E448[def->count];
    e = def->entries;
    int k = 0;
    for (i = 0; i < def->count; i++, e++) {
        if (e->src != 0) {
            func_00351398(&self->meshes[k++], e->src);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/animnode", func_0034E600);
#ifdef SKIP_ASM
struct sVec4_E600 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat_E600 {
    sVec4_E600 r[4];
    sMat_E600() {}
};

struct sVEntry_E600a {
    short delta;
    short index;
    sMat_E600* (*fn)(void*, int);
};

struct sVEntry_E600b {
    short delta;
    short index;
    void (*fn)(void*, int, sMat_E600*);
};

extern "C" void func_0034E600(void* self, int id, int idx, sVec4_E600* out)
{
    void* obj = (char*)self + 0x14;
    if (id == *(int*)((char*)self + 0x2C)) {
        sVEntry_E600a* vt = *(sVEntry_E600a**)((char*)self + 0x20);
        sVec4_E600 t = vt[29].fn((char*)obj + vt[29].delta, idx)->r[3];
        *out = t;
        return;
    }
    sMat_E600 buf[24];
    sVEntry_E600b* vt = *(sVEntry_E600b**)((char*)self + 0x20);
    vt[33].fn((char*)obj + vt[33].delta, id + 0x10, buf);
    sVec4_E600 t = buf[idx].r[3];
    *out = t;
}
#endif

INCLUDE_ASM("object/animnode", func_0034E698);

//100%
INCLUDE_ASM("object/animnode", func_0034E798);
#ifdef SKIP_ASM
struct sVec4_E798 {
    float x, y, z, w;
    sVec4_E798() {}
    sVec4_E798(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sVec3_E798 {
    float x, y, z;
};

struct sRow_E798 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat_E798 {
    sRow_E798 r[4];
};

struct sDelta_E798 {
    sVec4_E798 pos;
    sVec4_E798 rot;
};

struct sBone_E798 {
    int parent;
    int f4;
    int active;
    int fC;
};

struct sVE_E798 {
    short delta;
    short index;
    void* fn;
};

extern sVec4_E798 D_004FF120;
extern char* D_004A5B64;
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void func_00351660(void* node, sVec4_E798* pos, sVec4_E798* rot, float t);

// PORT: PS2-only VU0 inline asm (vector times-assign scalar).
static inline void vu0ScaleEq_E798(sVec4_E798& v, float s)
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

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector).
static inline sVec4_E798 vu0MulMat_E798(const sMat_E798* m, const sVec4_E798& v)
{
    sVec4_E798 r;
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

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_E798 vu0Sub_E798(const sVec4_E798& a, const sVec4_E798& b)
{
    sVec4_E798 r;
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
static inline sVec4_E798 vu0Add_E798(const sVec4_E798& a, const sVec4_E798& b)
{
    sVec4_E798 r;
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

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sVec4_E798 vu0Cross_E798(const sVec4_E798& a, const sVec4_E798& b)
{
    sVec4_E798 r;
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

// PORT: PS2-only VU0 inline asm (a += b).
static inline void vu0AddEq_E798(sVec4_E798& a, const sVec4_E798& b)
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

static inline sVec4_E798 boneE798Pos(char* self, int i)
{
    return *(sVec4_E798*)&(*(sMat_E798**)(self + 0x44))[i].r[3];
}

extern "C" void func_0034E798(char* self)
{
    char* obj = self + 0x14;
    if (*(unsigned short*)(self + 0x26) & 1) {
        sVE_E798* vt = *(sVE_E798**)(self + 0x20);
        ((void (*)(void*))vt[51].fn)(obj + vt[51].delta);
    }
    char* info = *(char**)(*(char**)(obj + 0x18) + 0x80);
    int k = 0;
    sBone_E798* ent = *(sBone_E798**)(info + 8);
    for (int i = 0; i < *(int*)(info + 4); i++, ent++) {
        ((sDelta_E798*)*(char**)(self + 0x4C))[i].pos = D_004FF120;
        ((sDelta_E798*)*(char**)(self + 0x4C))[i].rot = D_004FF120;
        float d2r = 0.01745329424738884f;
        if (ent->active == 0) continue;
        char* node = *(char**)(self + 0x48) + k * 0xD0;
        k++;
        sVE_E798* vt = *(sVE_E798**)(self + 0x20);
        float t = ((float (*)(void*))vt[53].fn)(self + vt[53].delta);
        sVec4_E798 pos;
        sVec4_E798 rotv;
        func_00351660(node, &pos, &rotv, *(float*)(self + 4));
        sVec4_E798 rot;
        rot = sVec4_E798(-*(float*)(node + 0x50), -*(float*)(node + 0x54), -*(float*)(node + 0x58), 0.0f);
        vu0ScaleEq_E798(pos, t * (float)*(int*)(D_004A5B64 + 0x10));
        vu0ScaleEq_E798(rotv, t * (float)*(int*)(D_004A5B64 + 0x10) * d2r);
        sMat_E798 m;
        {
            sVec3_E798 e;
            e.x = rot.x;
            e.y = rot.y;
            e.z = rot.z;
            float s1, c1, s2, c2;
            func_0031BE50(&s1, &c1, e.y);
            func_0031BE50(&s2, &c2, e.z);
            m.r[0].x = c1 * c2;
            m.r[0].y = -c1 * s2;
            m.r[0].z = s1;
            m.r[0].w = 0.0f;
            m.r[1].x = s2;
            m.r[1].y = c2;
            m.r[1].z = 0.0f;
            m.r[1].w = 0.0f;
            m.r[2].x = 0.0f;
            m.r[2].y = 0.0f;
            m.r[2].z = 1.0f;
            m.r[2].w = 0.0f;
            m.r[3].x = 0.0f;
            m.r[3].y = 0.0f;
            m.r[3].z = 0.0f;
            m.r[3].w = 1.0f;
        }
        rotv = vu0MulMat_E798(&m, rotv);
        pos = vu0MulMat_E798(&(*(sMat_E798**)(self + 0x44))[i], pos);
        rotv = vu0MulMat_E798(&(*(sMat_E798**)(self + 0x44))[i], rotv);
        if (ent->parent >= 0) {
            sVec4_E798 d = vu0Sub_E798(boneE798Pos(self, i), boneE798Pos(self, ent->parent));
            vu0AddEq_E798(rotv, ((sDelta_E798*)*(char**)(self + 0x4C))[ent->parent].rot);
            vu0AddEq_E798(pos, vu0Add_E798(((sDelta_E798*)*(char**)(self + 0x4C))[ent->parent].pos,
                                           vu0Cross_E798(d, ((sDelta_E798*)*(char**)(self + 0x4C))[ent->parent].rot)));
        }
        ((sDelta_E798*)*(char**)(self + 0x4C))[i].pos = pos;
        vu0AddEq_E798(((sDelta_E798*)*(char**)(self + 0x4C))[i].rot, rotv);
    }
    *(int*)(self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("object/animnode", func_0034EBA0);
#ifdef SKIP_ASM
struct sAnimLinkList_EBA0;

struct sAnimLink_EBA0 {
    char pad_0x00[0x18];
    sAnimLinkList_EBA0* list; // 0x18
};

struct sAnimLinkList_EBA0 {
    char pad_0x00[0xC];
    sAnimLink_EBA0* head; // 0x0C
};

extern "C" void func_002D1AC8(sAnimLinkList_EBA0* list);

struct sAnimNode_EBA0 {
    char pad_0x00[0x14];
    sAnimLink_EBA0 link; // 0x14
};

// is this node's link at the head of its list, after func_002D1AC8?
extern "C" int func_0034EBA0(sAnimNode_EBA0* self)
{
    sAnimLink_EBA0* link = &self->link;
    func_002D1AC8(self->link.list);
    return link->list->head == link;
}
#endif

INCLUDE_ASM("object/animnode", func_0034EBE0);

//100%
INCLUDE_ASM("object/animnode", func_0034EC58);
#ifdef SKIP_ASM
extern "C" void* func_00355280(void* self, void* a1, int type, void* a2);
struct cFloatingNode;
void cFloatingNode_initInfo(cFloatingNode* self);
extern char D_0048E880[];
extern void* D_0048F858[];

struct sAnimFrame_EC58 {
    char data[0x40];
    sAnimFrame_EC58() {}
};

struct sQ_EC58 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sAnimInfo_EC58 {
    int f0;
    float f4, f8, fC, f10, f14, f18;
};

extern "C" void* func_0034EC58(void* self, void* a1, void* a2, sAnimInfo_EC58* info)
{
    char* s = (char*)self;
    func_00355280(self, a1, 0xE, a2);
    *(void***)(s + 0xC) = D_0048F858;
    *(float*)(s + 0x2C) = info->f4;
    *(float*)(s + 0x30) = info->f8;
    *(float*)(s + 0x34) = info->f14;
    *(float*)(s + 0x38) = info->fC;
    *(float*)(s + 0x3C) = info->f10;
    *(float*)(s + 0x40) = info->f18 * 1e-6f;
    sQ_EC58 p = *(sQ_EC58*)(*(char**)(s + 0x18) + 0x40);
    *(int*)(s + 0x54) = 0;
    *(int*)(s + 0x5C) = 0;
    *(int*)(s + 0x60) = 0;
    *(int*)(s + 0x64) = 0;
    *(int*)(s + 0x6C) = 0;
    *(int*)(s + 0x70) = 0;
    *(int*)(s + 0x48) = 0;
    *(int*)(s + 0x44) = 0;
    *(int*)(s + 0x78) = 0;
    *(float*)(s + 0x4C) = p.z;
    *(float*)(s + 0x50) = p.z;
    cFloatingNode_initInfo((cFloatingNode*)self);
    sAnimFrame_EC58** pf = (sAnimFrame_EC58**)(s + 0x74);
    *pf = new (D_0048E880, 0x20000000, 0) sAnimFrame_EC58[*(int*)(*(char**)(*(char**)(s + 0x18) + 0x80) + 0x4)];
    *(unsigned short*)(s + 0x12) |= 1;
    char* m = *(char**)(s + 0x18);
    *(unsigned int*)(m + 8) = (*(unsigned int*)(m + 8) & 0xFFFFFFFD) | 4;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/animnode", func_0034ED88);
#ifdef SKIP_ASM
extern "C" void* cMoveNode_cMoveNode(void* self, void* a1, void* stream);
struct cFloatingNode;
void cFloatingNode_initInfo(cFloatingNode* self);
extern void* D_0048F858[];
extern char D_0048E880[];

struct sStreamVE_ED88 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// Element type with an empty constructor; the array new leaves only its loop counters.
struct sAnimFrame_ED88 {
    char data[0x40];
    sAnimFrame_ED88() {}
};

extern "C" void* func_0034ED88(void* self, void* a1, void* stream)
{
    char* s = (char*)self;
    int hasInfo;
    cMoveNode_cMoveNode(self, a1, stream);
    *(int*)(s + 0x78) = 0;
    *(void***)(s + 0xC) = D_0048F858;
    sStreamVE_ED88* vt = *(sStreamVE_ED88**)stream;
    vt[2].fn((char*)stream + vt[2].delta, &hasInfo, 4);
    if (hasInfo != 0) {
        cFloatingNode_initInfo((cFloatingNode*)self);
    }
    sStreamVE_ED88* vt2 = *(sStreamVE_ED88**)stream;
    vt2[2].fn((char*)stream + vt2[2].delta, s + 0x2C, 0x48);
    sAnimFrame_ED88** pf = (sAnimFrame_ED88**)(s + 0x74);
    *pf = new (D_0048E880, 0x20000000, 0) sAnimFrame_ED88[*(int*)(*(char**)(*(char**)(s + 0x18) + 0x80) + 0x4)];
    *(unsigned short*)(s + 0x12) |= 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/animnode", func_0034EE68);
#ifdef SKIP_ASM
extern void* D_0048F858[];
extern "C" void func_0034F048(void* self);
extern "C" void func_003553C0(void* self, int flags);
void operator_delete(int*);

extern "C" void func_0034EE68(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_0048F858;
    func_0034F048(self);
    operator_delete(*(int**)((char*)self + 0x74));
    func_003553C0(self, flags);
}
#endif

