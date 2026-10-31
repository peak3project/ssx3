#include "common.h"

//100%
INCLUDE_ASM("object/movenode", cMoveNode_cMoveNode);
#ifdef SKIP_ASM
struct sSerVEntry_55298 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct cMoveNode;
void cMoveNode_addModifierBlock(cMoveNode* self);
extern "C" void* cInstanceNode_cInstanceNode(void* self, void* a, void* stream);
extern "C" void tModifierBlock_readFromReplayFrame(void* block, void* stream);
extern "C" void cMoveNode_setupOverlapSystem(void* self);
extern char D_00491028[];

// PORT: the unit declares cMoveNode_cMoveNode(void*) (1 arg) for its callers; the body reads a1/a2
// (forwarded to cInstanceNode_cInstanceNode), so the 3-arg body is bound by asm label.
void* cMoveNode_cMoveNode_3(void* self, void* a, void* stream) __asm__("cMoveNode_cMoveNode");

void* cMoveNode_cMoveNode_3(void* self, void* a, void* stream)
{
    int flag;
    cInstanceNode_cInstanceNode(self, a, stream);
    *(int*)((char*)self + 0x1C) = 0;
    *(void**)((char*)self + 0xC) = D_00491028;
    sSerVEntry_55298* e = &(*(sSerVEntry_55298**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x20, 4);
    e = &(*(sSerVEntry_55298**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x24, 4);
    e = &(*(sSerVEntry_55298**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x28, 4);
    e = &(*(sSerVEntry_55298**)stream)[2];
    e->fn((char*)stream + e->delta, &flag, 4);
    if (flag) {
        cMoveNode_addModifierBlock((cMoveNode*)self);
        tModifierBlock_readFromReplayFrame(*(void**)((char*)self + 0x1C), stream);
    }
    cMoveNode_setupOverlapSystem(self);
    *(unsigned short*)((char*)self + 0x12) |= 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003553C0);
#ifdef SKIP_ASM
extern char D_00491028[];
extern "C" void func_003567E0(void* self);
extern "C" void func_00352AE8(void* block, int flags);
extern "C" void func_0034FBF0(void* self, int flags);

extern "C" void func_003553C0(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_00491028;
    func_003567E0(self);
    void* block = *(void**)((char*)self + 0x1C);
    if (block != 0) {
        func_00352AE8(block, 3);
    }
    func_0034FBF0(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355420);
#ifdef SKIP_ASM
struct sMoveNodeVEntryI {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_00355420(void* self)
{
    void* block = *(void**)((char*)self + 0x1C);
    if (block == 0) {
        return 1;
    }
    void* node = *(void**)block;
    if (node == 0) {
        return 1;
    }
    sMoveNodeVEntryI* vt = *(sMoveNodeVEntryI**)node;
    return vt[8].fn((char*)node + vt[8].delta);
}
#endif

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
struct tModifierBlock;
tModifierBlock* tModifierBlock_tModifierBlock(tModifierBlock* self);
extern const char D_0048E9D8[];

struct cMoveNode {
    char pad_0x00[0x1C];
    void* field_0x1C;
};

//100%
INCLUDE_ASM("object/movenode", cMoveNode_addModifierBlock__FP9cMoveNode);
#ifdef SKIP_ASM
void cMoveNode_addModifierBlock(cMoveNode* self)
{
    void* mem = cMemMan_alloc(0x28, D_0048E9D8, 0x20000000, 0);
    self->field_0x1C = tModifierBlock_tModifierBlock((tModifierBlock*)mem);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003554B0);
#ifdef SKIP_ASM
struct sMoveNodeVEntryV54B0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_003530D0(void* block);

extern "C" void func_003554B0(cMoveNode* self, void* mod)
{
    sMoveNodeVEntryV54B0* e = &(*(sMoveNodeVEntryV54B0**)((char*)self + 0xC))[49];
    e->fn((char*)self + e->delta);
    if (self->field_0x1C == 0) {
        cMoveNode_addModifierBlock(self);
    } else {
        func_003530D0(self->field_0x1C);
    }
    *(void**)self->field_0x1C = mod;
    e = &(*(sMoveNodeVEntryV54B0**)((char*)self + 0xC))[48];
    e->fn((char*)self + e->delta);
    unsigned int* f = (unsigned int*)(*(char**)((char*)self + 0x18) + 8);
    *f = (*f & ~0x20u) | 0x40;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355550);
#ifdef SKIP_ASM
extern "C" void func_00353118(void* block);

extern "C" void func_00355550(cMoveNode* self, void* v)
{
    if (self->field_0x1C == 0) {
        cMoveNode_addModifierBlock(self);
    } else {
        func_00353118(self->field_0x1C);
    }
    *(void**)((char*)self->field_0x1C + 0x4) = v;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003555A8);
#ifdef SKIP_ASM
extern "C" void func_00353150(void* block);

extern "C" void func_003555A8(cMoveNode* self, void* v)
{
    if (self->field_0x1C == 0) {
        cMoveNode_addModifierBlock(self);
    } else {
        func_00353150(self->field_0x1C);
    }
    *(void**)((char*)self->field_0x1C + 0x8) = v;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355600);
#ifdef SKIP_ASM
extern "C" void func_00353188(void* block);

extern "C" void func_00355600(cMoveNode* self, void* v)
{
    if (self->field_0x1C == 0) {
        cMoveNode_addModifierBlock(self);
    } else {
        func_00353188(self->field_0x1C);
    }
    *(void**)((char*)self->field_0x1C + 0xC) = v;
}
#endif

struct cEffectLink;
void cEffectLink_add(cEffectLink* link, cEffectLink* other);

//100%
INCLUDE_ASM("object/movenode", cMoveNode_addEffectModifier__FP9cMoveNodePv);
#ifdef SKIP_ASM
void cMoveNode_addEffectModifier(cMoveNode* self, void* effect)
{
    if (self->field_0x1C == 0) {
        cMoveNode_addModifierBlock(self);
    }
    cEffectLink_add((cEffectLink*)((char*)self->field_0x1C + 0x10), (cEffectLink*)effect);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003556A8);
#ifdef SKIP_ASM
extern "C" void func_0035B670(void* list, void* item);

extern "C" void func_003556A8(cMoveNode* self, void* item)
{
    if (self->field_0x1C == 0) {
        cMoveNode_addModifierBlock(self);
    }
    func_0035B670((char*)self->field_0x1C + 0x1C, item);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003556F8);
#ifdef SKIP_ASM
extern "C" void func_00352C70(void* block);
extern "C" int func_00352E50(void* block);

extern "C" void func_003556F8(cMoveNode* self)
{
    if (self->field_0x1C != 0) {
        func_00352C70(self->field_0x1C);
        if (func_00352E50(self->field_0x1C) != 0) {
            *(unsigned short*)((char*)self + 0x12) |= 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355748);
#ifdef SKIP_ASM
extern "C" void func_00352D20(void*);

extern "C" void func_00355748(cMoveNode* self)
{
    if (self->field_0x1C != 0) {
        func_00352D20(self->field_0x1C);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355770);
#ifdef SKIP_ASM
extern char* D_004A5B64;
extern "C" int func_002D1B30(int);
void* func_0034FE00(void*, int, int, int);

struct cMN_355770_Obj {
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09(int);
    virtual int v10(int a, int b);
};

struct cMN_355770_VEnt {
    short delta;
    short index;
    int (*fn)(void*, int);
};

extern "C" void func_00355770(cMoveNode* self, int a1, int a2, int a3)
{
    cMN_355770_Obj** p = (cMN_355770_Obj**)self->field_0x1C;
    if (p != 0) {
        cMN_355770_Obj* obj = *p;
        if (obj != 0) {
            obj->v10(a1, a2);
            char* o = *(char**)self->field_0x1C;
            cMN_355770_VEnt* vt = *(cMN_355770_VEnt**)o;
            if (vt[9].fn(o + vt[9].delta, func_002D1B30(a3)) == 0) {
                return;
            }
        }
    }
    if (*(int*)((char*)self + 0x20) <= 0) {
        *(int*)((char*)self + 0x20) = *(int*)(D_004A5B64 + 0x10) / 2;
        func_0034FE00(self, a1, a2, a3);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355858);
#ifdef SKIP_ASM
extern char* D_004A5B64;

extern "C" void func_00355858(void* self, float secs)
{
    *(int*)((char*)self + 0x20) = (int)((float)*(int*)(D_004A5B64 + 0x10) * secs);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355878__FPvT0);
#ifdef SKIP_ASM
float func_00355878(void* self, void* a1)
{
    float t0 = *(float*)((char*)a1 + 0x4);
    *(float*)((char*)self + 0x24) = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355888);
#ifdef SKIP_ASM
struct sMnVEntryF {
    short delta;
    short index;
    void (*fn)(void*, float);
};

extern "C" void func_00355888(void* self, void* a1)
{
    sMnVEntryF* vt = *(sMnVEntryF**)((char*)self + 0xC);
    vt[41].fn((char*)self + vt[41].delta, *(float*)((char*)a1 + 0x4));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_003558B8);
#ifdef SKIP_ASM
struct sMoveQuad;
extern char D_0048E8F0[];
extern "C" void* func_00356EB8(void* self, sMoveQuad* pos);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void func_003558B8(cMoveNode* self, sMoveQuad* pos)
{
    func_003554B0(self, func_00356EB8(cMemMan_alloc(0x90, D_0048E8F0, 0x20000000, 0), pos));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355918);
#ifdef SKIP_ASM
extern char D_0048E8F0[];
extern "C" void* func_00356F10(void* mem, void* desc);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void func_00355918(cMoveNode* self, void* desc)
{
    func_003554B0(self, func_00356F10(cMemMan_alloc(0x90, D_0048E8F0, 0x20000000, 0), desc));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355978);
#ifdef SKIP_ASM
struct sMoveQuad;
extern char D_0048E8E0[];
extern "C" void* func_00357038(void* self, void* a1, void* a2, sMoveQuad* pos);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void func_00355978(cMoveNode* self, void* a1, void* a2, sMoveQuad* pos)
{
    func_003554B0(self, func_00357038(cMemMan_alloc(0xB0, D_0048E8E0, 0x20000000, 0), a1, a2, pos));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_003559F8);
#ifdef SKIP_ASM
extern char D_0048E918[];
extern "C" void* func_003572E0(void* self, void* owner, void* a2, float f0, float f1);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void func_003559F8(cMoveNode* self, void* a1, float f0, float f1)
{
    func_003554B0(self, func_003572E0(cMemMan_alloc(0xB0, D_0048E918, 0x20000000, 0),
                                      *(void**)((char*)self + 0x18), a1, f0, f1));
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355A78);
#ifdef SKIP_ASM
extern int D_004A3AC4;
extern char D_0048E928[];
extern "C" void* func_00357750(void* self, void* src);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void func_00355A78(cMoveNode* self)
{
    if (D_004A3AC4 == 0) {
        func_003554B0(self, func_00357750(cMemMan_alloc(0x90, D_0048E928, 0x20000000, 0), *(void**)((char*)self + 0x18)));
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355AD0);
#ifdef SKIP_ASM
extern char D_0048E8D0[];
extern "C" void* func_00359460(void* mem, void* desc);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void func_00355AD0(cMoveNode* self, void* desc)
{
    func_003554B0(self, func_00359460(cMemMan_alloc(0xF0, D_0048E8D0, 0x20000000, 0), desc));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", cMoveNode_addSpline);
#ifdef SKIP_ASM
extern char D_0048E9E8[];
extern "C" void* func_00359F88(void* mem, void* desc, void* owner);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void cMoveNode_addSpline(cMoveNode* self, void* desc)
{
    func_003554B0(self, func_00359F88(cMemMan_alloc(0x58, D_0048E9E8, 0x20000000, 0), desc,
                                      *(void**)((char*)self + 0x18)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355B90);
#ifdef SKIP_ASM
extern char D_0048E940[];
extern "C" void* func_0035F6E8(void* mem, void* desc);
extern "C" void func_00355550(cMoveNode* self, void* mod);

extern "C" void func_00355B90(cMoveNode* self, void* desc)
{
    func_00355550(self, func_0035F6E8(cMemMan_alloc(0x50, D_0048E940, 0x20000000, 0), desc));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355BF0);
#ifdef SKIP_ASM
extern char D_0048E958[];
extern "C" void* func_0035F0B8(void* mem, void* desc, void* owner);
extern "C" void func_003555A8(cMoveNode* self, void* mod);

extern "C" void func_00355BF0(cMoveNode* self, void* desc)
{
    func_003555A8(self, func_0035F0B8(cMemMan_alloc(0xE8, D_0048E958, 0x20000000, 0), desc, *(void**)((char*)self + 0x18)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355C50);
#ifdef SKIP_ASM
extern char D_0048E968[];
extern "C" void* func_00342768(void* mem, void* desc, void* owner);
extern "C" void func_00355600(cMoveNode* self, void* mod);

extern "C" void func_00355C50(cMoveNode* self, void* desc)
{
    func_00355600(self, func_00342768(cMemMan_alloc(0x50, D_0048E968, 0x20000000, 0), desc, *(void**)((char*)self + 0x18)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", cMoveNode_addParticle);
#ifdef SKIP_ASM
extern char D_0048E978[];
extern "C" void* func_003458C0(void* mem, void* desc, void* owner);
void cMoveNode_addEffectModifier(cMoveNode* self, void* mod);

extern "C" void cMoveNode_addParticle(cMoveNode* self, void* desc)
{
    cMoveNode_addEffectModifier(self, func_003458C0(cMemMan_alloc(0x1F0, D_0048E978, 0x20000000, 0), desc,
                                                    *(void**)((char*)self + 0x18)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", cMoveNode_addDynamicParticle);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void* func_00345C90(void* mem, void* desc, void* inst, int index, void* a4);
extern const char D_0048E990[];

extern "C" void cMoveNode_addDynamicParticle(cMoveNode* self, void* desc, int index, void* a4)
{
    if (index < 0 || index >= *(int*)(*(char**)(*(char**)((char*)self + 0x18) + 0x80) + 4)) {
        operator_delete((int*)desc);
        return;
    }
    cMoveNode_addEffectModifier(self, func_00345C90(cMemMan_alloc(0x270, D_0048E990, 0x20000000, 0), desc, *(void**)((char*)self + 0x18), index, a4));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355DB8);
#ifdef SKIP_ASM
extern char D_0048E908[];
extern "C" void* func_0035DA70(void* mem, void* a1, void* a2, void* a3);
extern "C" void func_003554B0(cMoveNode* self, void* mod);

extern "C" void func_00355DB8(cMoveNode* self, void* a1, void* a2, void* a3)
{
    func_003554B0(self, func_0035DA70(cMemMan_alloc(0x2D0, D_0048E908, 0x20000000, 0), a1, a2, a3));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00355E38);
#ifdef SKIP_ASM
extern char D_0048E9B8[];
extern "C" int func_00353418(void* self, int id);
extern "C" void* func_0035B708(void* mem, void* desc, void* owner);
extern "C" void func_003556A8(cMoveNode* self, void* item);

extern "C" void func_00355E38(cMoveNode* self, void* desc)
{
    void* block = self->field_0x1C;
    if (block != 0 && func_00353418(block, *(int*)((char*)desc + 0x4)) != 0) {
        return;
    }
    func_003556A8(self, func_0035B708(cMemMan_alloc(0x90, D_0048E9B8, 0x20000000, 0), desc,
                                      *(void**)((char*)self + 0x18)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", cMoveNode_addHalo);
#ifdef SKIP_ASM
extern char D_0048E9A8[];
extern "C" void* func_00346120(void* mem, void* desc, void* owner);
void cMoveNode_addEffectModifier(cMoveNode* self, void* mod);

extern "C" void cMoveNode_addHalo(cMoveNode* self, void* desc)
{
    cMoveNode_addEffectModifier(self, func_00346120(cMemMan_alloc(0x40, D_0048E9A8, 0x20000000, 0), desc,
                                                    *(void**)((char*)self + 0x18)));
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00355F10);
#ifdef SKIP_ASM
extern "C" void func_00356020(cMoveNode* self, cMoveNode* other);

struct sMat44_355F10 {
    float m[16];
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMatrix_355F10(void* dst, void* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

struct sNodeVEntryI_355F10 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sNodeVEntryP_355F10 {
    short delta;
    short index;
    char* (*fn)(void*);
};
struct sNodeVEntryD_355F10 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sNodeVEntryV_355F10 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00355F10(cMoveNode* self, void* srcv)
{
    char* src = (char*)srcv;
    if (src == 0) {
        return;
    }
    sNodeVEntryI_355F10* vi = *(sNodeVEntryI_355F10**)(src + 0xC);
    if (vi[16].fn(src + vi[16].delta) != 0) {
        func_00356020(self, (cMoveNode*)src);
    }
    sNodeVEntryP_355F10* vp = *(sNodeVEntryP_355F10**)(src + 0xC);
    char* m = vp[24].fn(src + vp[24].delta);
    if (m == *(char**)((char*)self + 0x18) + 0x10) {
        sNodeVEntryD_355F10* vd = *(sNodeVEntryD_355F10**)(src + 0xC);
        vd[1].fn(src + vd[1].delta, 3);
        return;
    }
    sMat44_355F10 copy;
    vu0CopyMatrix_355F10(&copy, m);
    int keep = *(int*)(*(char**)((char*)self + 0x18) + 8);
    sNodeVEntryD_355F10* vd = *(sNodeVEntryD_355F10**)(src + 0xC);
    vd[1].fn(src + vd[1].delta, 3);
    *(int*)(*(char**)((char*)self + 0x18) + 8) = keep;
    func_00355918(self, &copy);
    *(int*)((char*)self + 0x28) = 1;
    sNodeVEntryV_355F10* vv = *(sNodeVEntryV_355F10**)((char*)self + 0xC);
    vv[50].fn((char*)self + vv[50].delta);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356020);
#ifdef SKIP_ASM
extern "C" void func_00353398(void* block, void* other);

extern "C" void func_00356020(cMoveNode* self, cMoveNode* other)
{
    if (other->field_0x1C != 0) {
        if (self->field_0x1C == 0) {
            cMoveNode_addModifierBlock(self);
        }
        func_00353398(self->field_0x1C, (char*)other->field_0x1C + 0x10);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356078);
#ifdef SKIP_ASM
struct sMnVEntryP_6078 {
    short delta;
    short index;
    void* (*fn)(void*);
};
// Virtual call through the modifier object's vtable (slot 18); taking the object by reference matches the register allocation.
static inline void* VCall18_6078(char*& o)
{
    sMnVEntryP_6078* vt = *(sMnVEntryP_6078**)o;
    return vt[18].fn(o + vt[18].delta);
}
extern "C" void* func_00356078(char* self)
{
    char** h = *(char***)(self + 0x1C);
    char* o = h ? *h : 0;
    if (o != 0)
        return VCall18_6078(o);
    return *(char**)(self + 0x18) + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003560C0);
#ifdef SKIP_ASM
struct sMnVEntryI2_60C0 {
    short delta;
    short index;
    int (*fn)(void*, int);
};
struct sMnVEntryI_60C0 {
    short delta;
    short index;
    int (*fn)(void*);
};
// Taking the object by reference matches the target's register allocation (see func_00356078).
static inline int VCall23_60C0(char*& o, int a)
{
    sMnVEntryI2_60C0* vt = *(sMnVEntryI2_60C0**)o;
    return vt[23].fn(o + vt[23].delta, a);
}
// Asks the modifier object (slot 23, passing a through), then falls back to the node's own slot 27.
extern "C" int func_003560C0(char* self, int a)
{
    char** h = *(char***)(self + 0x1C);
    char* o = h ? *h : 0;
    if (o != 0) {
        int r = VCall23_60C0(o, a);
        if (r != 0) return r;
    }
    sMnVEntryI_60C0* vs = *(sMnVEntryI_60C0**)(self + 0xC);
    return vs[27].fn(self + vs[27].delta);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356128);
#ifdef SKIP_ASM
struct sMnVEntryP_6128 {
    short delta;
    short index;
    void* (*fn)(void*);
};
// Taking the object by reference matches the target's register allocation (see func_00356078).
static inline void* VCall_6128(char*& o, int i)
{
    sMnVEntryP_6128* vt = *(sMnVEntryP_6128**)o;
    return vt[i].fn(o + vt[i].delta);
}
// Returns the modifier object's slot-19 value, else its slot-18 value; without one, the node's object position.
extern "C" void* func_00356128(char* self)
{
    char** h = *(char***)(self + 0x1C);
    char* o = h ? *h : 0;
    if (o != 0) {
        void* r = VCall_6128(o, 19);
        if (r != 0) return r;
        return VCall_6128(o, 18);
    }
    return *(char**)(self + 0x18) + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356198);
#ifdef SKIP_ASM
void* func_0034FCE0(void* self);
extern "C" int func_00352ED0(void* block);
extern "C" void func_00352F08(void* block);

struct sMnVEntryI_356198 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sMnVEntryV_356198 {
    short delta;
    short index;
    void (*fn)(void*);
};
struct sMnVEntryVi_356198 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00356198(void* selfv)
{
    cMoveNode* self = (cMoveNode*)selfv;
    char* s = (char*)selfv;
    if (*(int*)(s + 0x20) > 0) {
        *(int*)(s + 0x20) -= 1;
    }
    sMnVEntryI_356198* vi = *(sMnVEntryI_356198**)(s + 0xC);
    if (vi[20].fn(s + vi[20].delta) != 0) {
        sMnVEntryI_356198* vi2 = *(sMnVEntryI_356198**)(s + 0xC);
        if (vi2[23].fn(s + vi2[23].delta) <= 0 && func_0034FCE0(self) == 0) {
            sMnVEntryV_356198* vv = *(sMnVEntryV_356198**)(s + 0xC);
            vv[35].fn(s + vv[35].delta);
            return;
        }
    }
    func_003556F8(self);
    sMnVEntryI_356198* vi3 = *(sMnVEntryI_356198**)(s + 0xC);
    if (vi3[15].fn(s + vi3[15].delta) != 0) {
        func_00355748(self);
        if (self->field_0x1C != 0 && func_00352ED0(self->field_0x1C) != 0) {
            func_00352F08(self->field_0x1C);
            sMnVEntryVi_356198* vw = *(sMnVEntryVi_356198**)(s + 0xC);
            vw[34].fn(s + vw[34].delta, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356298);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sMoveQuad;
extern sMoveQuad D_004FF1A0[];

struct sMnVec_6298 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMnMat_6298 {
    sMnVec_6298 r[4];
};

struct sMnSlot_6298 {
    int f0;
    int type;                       // 0x4 (array at 0x20 + 4)
};

struct sMnCam_6298 {
    char pad_0x0[0x20];
    sMnSlot_6298 slots[(0x3F0 - 0x20) / 8];  // 0x20
    struct {
        int kind;
        char pad[0x14];
    } paths[1];                     // 0x3F0
};

struct sMnObj_6298 {
    char pad_0x0[0x8];
    int flags;                      // 0x8
    char pad_0xC[0x50 - 0xC];
    char box[0x10];                 // 0x50
    float pos[3];                   // 0x60
    float scl[3];                   // 0x6C
    char pad_0x78[0x7D - 0x78];
    unsigned char slot;             // 0x7D
    short path;                     // 0x7E
    char pad_0x80[0x94 - 0x80];
    void* light;                    // 0x94
};

class cMnOwner_6298 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual int v26();
};

struct sMnMod_6298 {
    cMnOwner_6298* owner;           // 0x0
    void* rot;                      // 0x4
    char* volatile light;           // 0x8
};

class cMnNode_6298 {
public:
    char pad[0xC];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void* v24();
    virtual void v25();
    virtual int v26();
    virtual void* v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void* v44();
    virtual sMnVec_6298* v45();
};

extern sMnCam_6298** D_004A47B8_6298 __asm__("D_004A47B8");
struct sMnGfxVt_6298 {
    short delta;
    short index;
    void* fn;
};

struct cMnGfx_6298 {
    char pad_0x0[0x10D8];
    sMnGfxVt_6298* vt;              // 0x10D8
};

typedef sMnMat_6298 (*MnViewFn_6298)(void*);
typedef int (*MnCullFn_6298)(void*, sMnVec_6298*, sMnVec_6298*, const sMnMat_6298&);
typedef void (*MnDrawFn_6298)(void*, void*, void*, void*, void*, void*, int, float);

extern cMnGfx_6298* D_004A5B80_6298 __asm__("D_004A5B80");
extern "C" void func_00352DD0(void* self);
extern "C" int func_002D2058(void* v);
extern "C" void* func_0035FC20(void* self, void* m);

#define OBJ_6298(s) (*(sMnObj_6298**)((char*)(s) + 0x18))
#define MOD_6298(s) (*(sMnMod_6298**)((char*)(s) + 0x1C))

static inline int HasRot_6298(sMnMod_6298* m)
{
    return m != 0 && m->rot != 0;
}

static inline int HasLight_6298(sMnMod_6298* m)
{
    return m != 0 && m->light != 0;
}

static inline void* Mat_6298(void* rot, sMnMat_6298* m)
{
    void* r;
    if (rot) {
        r = func_0035FC20(rot, m);
    } else {
        r = 0;
    }
    return r;
}

static inline void* LmSub_6298(char* l)
{
    return l + 0x24;
}

static inline void* Lm_6298(char* l)
{
    if (l == 0) {
        return 0;
    }
    return LmSub_6298(l);
}

static inline void* RotOf_6298(cMnNode_6298* n, sMnMat_6298* m)
{
    if (HasRot_6298(MOD_6298(n))) {
        return Mat_6298(MOD_6298(n)->rot, m);
    }
    return 0;
}

static inline void* LightOf_6298(cMnNode_6298* n)
{
    if (HasLight_6298(MOD_6298(n))) {
        return Lm_6298(MOD_6298(n)->light);
    }
    return OBJ_6298(n)->light;
}

static inline bool IsT6_6298(sMnCam_6298* c, int i)
{
    return c->slots[i].type == 6;
}

static inline int Visible_6298(sMnCam_6298* cam, sMnObj_6298* obj)
{
    if (obj->slot == 0xFF) {
        return 1;
    }
    if (IsT6_6298(cam, obj->slot)) {
        return cam->paths[obj->path].kind == 3;
    }
    return 0;
}

extern "C" void func_00356298(cMnNode_6298* self)
{
    sMnCam_6298* cam = *D_004A47B8_6298;
    sMnObj_6298* obj = OBJ_6298(self);
    if (!Visible_6298(cam, obj)) {
        return;
    }
    int flags = 0;
    cMnGfx_6298* gfx = D_004A5B80_6298;
    if (MOD_6298(self)) {
        func_00352DD0(MOD_6298(self));
        cMnOwner_6298* o = MOD_6298(self)->owner;
        if (o) {
            if (o->v26() == 7) {
                flags |= 0x2000;
            }
        }
    }
    if (!(OBJ_6298(self)->flags & 4)) {
        return;
    }
    if (*(int*)((char*)self + 0x28)) {
        return;
    }
    void* mat = self->v44();
    int res;
    if (mat) {
        sMnVec_6298* m = self->v45();
        sMnGfxVt_6298* vt = gfx->vt;
        char* thisp = (char*)gfx + vt[93].delta;
        res = ((MnCullFn_6298)vt[93].fn)(thisp, m, m + 1, ((MnViewFn_6298)gfx->vt[43].fn)((char*)gfx + gfx->vt[43].delta));
    } else {
        sMnGfxVt_6298* vt = gfx->vt;
        char* thisp = (char*)gfx + vt[93].delta;
        sMnVec_6298 b[2];
        b[0].x = OBJ_6298(self)->pos[0];
        b[0].y = OBJ_6298(self)->pos[1];
        b[0].z = OBJ_6298(self)->pos[2];
        b[0].w = 1.0f;
        b[1].x = OBJ_6298(self)->scl[0];
        b[1].y = OBJ_6298(self)->scl[1];
        b[1].z = OBJ_6298(self)->scl[2];
        b[1].w = 1.0f;
        res = ((MnCullFn_6298)vt[93].fn)(thisp, &b[0], &b[1], ((MnViewFn_6298)gfx->vt[43].fn)((char*)gfx + gfx->vt[43].delta));
    }
    if (res == 1) {
        return;
    }
    flags |= 0x400;
    if (res) {
        flags |= 0x20;
    }
    if (!mat) {
        if (func_002D2058(OBJ_6298(self)->box)) {
            return;
        }
    }
    void* rot = 0;
    void* tex;
    void* xf;
    if (self->v26()) {
        tex = self->v27();
        xf = D_004FF1A0;
    } else {
        tex = 0;
        xf = self->v24();
    }
    sMnMat_6298 rm;
    if (HasRot_6298(MOD_6298(self))) {
        rot = RotOf_6298(self, &rm);
        flags |= 2;
    }
    void* light = HasLight_6298(MOD_6298(self)) ? LightOf_6298(self) : OBJ_6298(self)->light;
    sMnGfxVt_6298* vt = gfx->vt;
    ((MnDrawFn_6298)vt[95].fn)((char*)gfx + vt[95].delta, OBJ_6298(self), light, xf, tex, rot, flags, *(float*)((char*)self + 0x24));
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356608);
#ifdef SKIP_ASM
// Draws the node with a caller-supplied texture and flags (visibility, rotation and light as in func_00356298).
extern "C" void func_00356608(cMnNode_6298* self, void* tex, int flags)
{
    sMnCam_6298* cam = *D_004A47B8_6298;
    sMnObj_6298* obj = OBJ_6298(self);
    if (!Visible_6298(cam, obj)) {
        return;
    }
    void* rot = 0;
    cMnGfx_6298* gfx = D_004A5B80_6298;
    sMnMat_6298 rm;
    if (HasRot_6298(MOD_6298(self))) {
        rot = RotOf_6298(self, &rm);
        flags |= 2;
    }
    void* light = HasLight_6298(MOD_6298(self)) ? LightOf_6298(self) : OBJ_6298(self)->light;
    sMnGfxVt_6298* vt = gfx->vt;
    ((MnDrawFn_6298)vt[95].fn)((char*)gfx + vt[95].delta, OBJ_6298(self), light, D_004FF1A0, tex, rot, flags, *(float*)((char*)self + 0x24));
}
#endif

//100%
INCLUDE_ASM("object/movenode", cMoveNode_setupOverlapSystem);
#ifdef SKIP_ASM
struct tModifierBlock;
extern "C" void cInstanceNode_getBoundBoxInfo(void* self, void* box, float* radius);
// PORT: these take the box / radius as a second argument; the symbols are mangled with one parameter.
void tModifierBlock_setBoundBox_K(tModifierBlock* mb, void* box) __asm__("tModifierBlock_setBoundBox__FP14tModifierBlock");
void tModifierBlock_setRadius_K(tModifierBlock* mb, float r) __asm__("tModifierBlock_setRadius__FP14tModifierBlock");

struct sBox_3567 {
    float v[8];
} __attribute__((aligned(16)));

// Copies the instance's bounding box and radius into its modifier block, when it has one with data.
extern "C" void cMoveNode_setupOverlapSystem(void* self_)
{
    char* self = (char*)self_;
    int* mb = *(int**)(self + 0x1C);
    int n = mb != 0;
    if (n)
        n = *mb;
    else
        n = 0;
    if (n) {
        sBox_3567 box;
        float radius;
        cInstanceNode_getBoundBoxInfo(self, &box, &radius);
        tModifierBlock_setBoundBox_K(*(tModifierBlock**)(self + 0x1C), &box);
        tModifierBlock_setRadius_K(*(tModifierBlock**)(self + 0x1C), radius);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003567E0);
#ifdef SKIP_ASM
#include "common.h"
struct tModifierBlock;
void tModifierBlock_setBoundBox_K(tModifierBlock* mb, void* box) __asm__("tModifierBlock_setBoundBox__FP14tModifierBlock");
struct sMnVec4_67E0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMnBox_67E0 {
    sMnVec4_67E0 min, max;
};

extern "C" sMnBox_67E0* func_00352B88_67E0(void* mb) __asm__("func_00352B88");
extern "C" void* func_002D1BE0(void);
extern "C" void func_003291E0_67E0(void* mgr, int a, void* obj, sMnBox_67E0* box, sMnBox_67E0* old) __asm__("func_003291E0");

// Sets the modifier block's bound box from the node's own extents (self->18 + 0x60) and re-files it.
extern "C" void func_003567E0(void* vself)
{
    char* self = (char*)vself;
    char** h = *(char***)(self + 0x1C);
    char* blk = h ? *h : 0;
    // Binding a reference to the object matches the target register allocation (see func_00356078).
    char*& o = blk;
    if (o == 0)
        return;
    sMnBox_67E0 box;
    sMnBox_67E0 old = *func_00352B88_67E0(*(void**)(self + 0x1C));
    char* n = *(char**)(self + 0x18);
    sMnVec4_67E0 v;
    v.x = *(float*)(n + 0x60);
    v.y = *(float*)(n + 0x64);
    v.z = *(float*)(n + 0x68);
    v.w = 1.0f;
    box.min = v;
    v.x = *(float*)(n + 0x6C);
    v.y = *(float*)(n + 0x70);
    v.z = *(float*)(n + 0x74);
    box.max = v;
    tModifierBlock_setBoundBox_K(*(tModifierBlock**)(self + 0x1C), &box);
    void* obj = *(void**)(self + 0x18);
    func_003291E0_67E0(func_002D1BE0(), 0, obj, &box, &old);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003568B0);
#ifdef SKIP_ASM
struct sMnVec4_68B0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMnBox_68B0 {
    sMnVec4_68B0 min, max;
};

struct sMnVEntM_68B0 {
    short delta;
    short index;
    sMnVec4_68B0* (*fn)(void*);
};
struct sMnVEnt_68B0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" sMnBox_68B0* func_00352B88_68B0(void* mb) __asm__("func_00352B88");
extern "C" float func_00352BF8(void* mb);
extern "C" void* func_002D1BE0(void);
extern "C" void func_003291E0(void* mgr, int a, void* obj, sMnBox_68B0* box, sMnBox_68B0* old);

// PORT: PS2-only VU0 inline asm (a - b).
static inline void vu0Sub_68B0(sMnVec4_68B0& out, const sMnVec4_68B0& a, const sMnVec4_68B0& b)
{
    sMnVec4_68B0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    out = r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline void vu0Add_68B0(sMnVec4_68B0& out, const sMnVec4_68B0& a, const sMnVec4_68B0& b)
{
    sMnVec4_68B0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    out = r;
}

// World position: translation row of the node's transform (virtual slot 24).
static inline sMnVec4_68B0 pos_68B0(char* self)
{
    sMnVEntM_68B0* vt = *(sMnVEntM_68B0**)(self + 0xC);
    return vt[24].fn(self + vt[24].delta)[3];
}

static inline void VCall24_68B0(char*& o)
{
    sMnVEnt_68B0* vt = *(sMnVEnt_68B0**)o;
    vt[24].fn(o + vt[24].delta);
}

// Refits the modifier block's bound box around the node's position (radius from the block) and re-files it.
extern "C" void func_003568B0(char* self)
{
    char** h = *(char***)(self + 0x1C);
    char* o = h ? *h : 0;
    if (o == 0)
        return;
    sMnBox_68B0 box;
    sMnBox_68B0 old = *func_00352B88_68B0(*(void**)(self + 0x1C));
    float r = func_00352BF8(*(void**)(self + 0x1C));
    sMnVec4_68B0 rv;
    rv.w = 0.0f;
    rv.x = r;
    rv.y = r;
    rv.z = r;
    sMnVec4_68B0 v;
    vu0Sub_68B0(v, pos_68B0(self), rv);
    box.min = v;
    vu0Add_68B0(v, pos_68B0(self), rv);
    box.max = v;
    tModifierBlock_setBoundBox_K(*(tModifierBlock**)(self + 0x1C), &box);
    void* obj = *(void**)(self + 0x18);
    func_003291E0(func_002D1BE0(), 0, obj, &box, &old);
    VCall24_68B0(o);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003569D0);
#ifdef SKIP_ASM
extern "C" int func_00352B88(void*);

extern "C" int func_003569D0(cMoveNode* self)
{
    if (self->field_0x1C != 0) {
        return func_00352B88(self->field_0x1C) != 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356A00);
#ifdef SKIP_ASM
extern "C" int func_00352B88(void*);

extern "C" int func_00356A00(cMoveNode* self)
{
    if (self->field_0x1C != 0) {
        return func_00352B88(self->field_0x1C);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356A28);
#ifdef SKIP_ASM
struct sMoveNodeVEntryA28 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_00356A28(void* self)
{
    void* block = *(void**)((char*)self + 0x1C);
    if (block == 0) {
        return 0;
    }
    void* node = *(void**)block;
    if (node == 0) {
        return 0;
    }
    sMoveNodeVEntryA28* vt = *(sMoveNodeVEntryA28**)node;
    return vt[20].fn((char*)node + vt[20].delta);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356A70);
#ifdef SKIP_ASM
struct sMoveNodeVEntryA70 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int, int);
};

extern "C" int func_00356A70(void* self, int a, int b, int c, int d)
{
    void* block = *(void**)((char*)self + 0x1C);
    if (block == 0) {
        return 0;
    }
    void* node = *(void**)block;
    if (node == 0) {
        return 0;
    }
    sMoveNodeVEntryA70* vt = *(sMoveNodeVEntryA70**)node;
    return vt[21].fn((char*)node + vt[21].delta, a, b, c, d);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356AB8);
#ifdef SKIP_ASM
extern "C" void func_00353020(void*, int, int);

extern "C" void func_00356AB8(cMoveNode* self, int a1, int a2)
{
    if (self->field_0x1C != 0) {
        func_00353020(self->field_0x1C, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356AE0);
#ifdef SKIP_ASM
extern "C" void func_00353098(void*, void*);

extern "C" void func_00356AE0(cMoveNode* self, void* out)
{
    if (self->field_0x1C != 0) {
        func_00353098(self->field_0x1C, out);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356B08);
#ifdef SKIP_ASM
extern "C" void func_00352F40(void*);

extern "C" void func_00356B08(cMoveNode* self)
{
    if (self->field_0x1C != 0) {
        func_00352F40(self->field_0x1C);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356B30);
#ifdef SKIP_ASM
struct sSerVEntry_56B30 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0034FE90(void* self, void* stream);
extern "C" void func_00353448(void* block, void* stream);

// PORT: the unit declares func_00356B30 as `void* (void*)` for its callers; the body writes
// to the stream in a1, so the 2-arg body is bound by asm label.
void func_00356B30_2(void* self, void* stream) __asm__("func_00356B30");

void func_00356B30_2(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sSerVEntry_56B30* e = &(*(sSerVEntry_56B30**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x20, 4);
    e = &(*(sSerVEntry_56B30**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x24, 4);
    e = &(*(sSerVEntry_56B30**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x28, 4);
    int flag = *(void**)((char*)self + 0x1C) != 0;
    e = &(*(sSerVEntry_56B30**)stream)[1];
    e->fn((char*)stream + e->delta, &flag, 4);
    void* block = *(void**)((char*)self + 0x1C);
    if (block != 0) {
        func_00353448(block, stream);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356BF0);
#ifdef SKIP_ASM
struct sMnVEntryI_6BF0 {
    short delta;
    short index;
    int (*fn)(void*);
};
static inline int VCall_6BF0(char* o, int i)
{
    sMnVEntryI_6BF0* vt = *(sMnVEntryI_6BF0**)o;
    return vt[i].fn(o + vt[i].delta);
}
// Does the modifier object's virtual slot 26 report state 2?
extern "C" int func_00356BF0(char* self)
{
    char** h = *(char***)(self + 0x1C);
    if (h != 0) {
        char* o = *h;
        if (o != 0 && VCall_6BF0(o, 26) == 2)
            return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356C48);
#ifdef SKIP_ASM
struct sMnVEntryI6C48 {
    short delta;
    short index;
    int (*fn)(void*);
};

// PORT: func_0035AAD0 takes one argument, but this caller passes a second ($5 = a1);
// the original declaration it was compiled against must have had two parameters.
int func_0035AAD0_2(void* self, void* a1) __asm__("func_0035AAD0__FPv");

extern "C" int func_00356C48(cMoveNode* self, void* a1)
{
    void* block = self->field_0x1C;
    if (block != 0) {
        void* node = *(void**)block;
        if (node != 0) {
            sMnVEntryI6C48* vt = *(sMnVEntryI6C48**)node;
            if (vt[26].fn((char*)node + vt[26].delta) == 2) {
                return func_0035AAD0_2(*(void**)self->field_0x1C, a1);
            }
        }
        return 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356CC8);
#ifdef SKIP_ASM
struct sMnVEntryI6CC8 {
    short delta;
    short index;
    int (*fn)(void*);
};

// PORT: func_0035AAE0 takes one argument, but this caller passes a second ($5 = a1);
// the original declaration it was compiled against must have had two parameters.
int func_0035AAE0_2(void* self, void* a1) __asm__("func_0035AAE0__FPv");

extern "C" int func_00356CC8(cMoveNode* self, void* a1)
{
    void* block = self->field_0x1C;
    if (block != 0) {
        void* node = *(void**)block;
        if (node != 0) {
            sMnVEntryI6CC8* vt = *(sMnVEntryI6CC8**)node;
            if (vt[26].fn((char*)node + vt[26].delta) == 2) {
                return func_0035AAE0_2(*(void**)self->field_0x1C, a1);
            }
        }
        return 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356D48);
#ifdef SKIP_ASM
extern "C" int func_00356D48(void* self)
{
    void* block = *(void**)((char*)self + 0x1C);
    if (block == 0) {
        return 0;
    }
    void* node = *(void**)block;
    if (node == 0) {
        return 0;
    }
    sMoveNodeVEntryI* vt = *(sMoveNodeVEntryI**)node;
    if (vt[26].fn((char*)node + vt[26].delta) != 2) {
        return 0;
    }
    return *(int*)((char*)**(void***)((char*)self + 0x1C) + 0x34);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356DB0);
#ifdef SKIP_ASM
struct sMoveFlags_6DB0 {
    char pad_0x00[0x8];
    unsigned int w;     // 0x8
};

extern void* D_00490E80[];
extern "C" void* func_00355280(void* self, void* a1, int type, void* a3);

extern "C" void* func_00356DB0(void* self, void* a1, void* a2, int a3, int a4)
{
    func_00355280(self, a1, 0x11, a2);
    *(void***)((char*)self + 0xC) = D_00490E80;
    if (a4 != 0 || ((*(sMoveFlags_6DB0**)((char*)self + 0x18))->w & 3) == 3) {
        sMoveFlags_6DB0* f = *(sMoveFlags_6DB0**)((char*)self + 0x18);
        f->w = (f->w & ~2) | 4;
    }
    if (a3 != 0) {
        sMoveFlags_6DB0* f = *(sMoveFlags_6DB0**)((char*)self + 0x18);
        f->w = (f->w & ~0x40) | 0x20;
    }
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00356E60);
#ifdef SKIP_ASM
extern "C" void* cMoveNode_cMoveNode(void* self);
extern void* D_00490E80[];

extern "C" void* func_00356E60(void* self, void* bucket, void* stream)
{
    cMoveNode_cMoveNode(self);
    *(void***)((char*)self + 0xC) = D_00490E80;
    return self;
}
#endif

extern "C" void* func_00356B30(void* self);

//100%
INCLUDE_ASM("object/movenode", func_00356E98__FPv);
#ifdef SKIP_ASM
void* func_00356E98(void* self)
{
    return func_00356B30(self);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356EB8);
#ifdef SKIP_ASM
struct sMoveQuad {
    float v[4];
} __attribute__((aligned(16)));

extern void* D_0048F5F0[];
extern sMoveQuad D_004FF1A0[];

extern "C" void* func_00356EB8(void* self, sMoveQuad* pos)
{
    *(void***)self = D_0048F5F0;
    *(sMoveQuad*)((char*)self + 0x30) = *pos;
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy, D_004FF1A0 -> self+0x50).
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"((char*)self + 0x50), "r"(D_004FF1A0)
        : "memory");
    *(int*)((char*)self + 0x44) = 1;
    *(sMoveQuad*)((char*)self + 0x80) = *(sMoveQuad*)((char*)self + 0x30);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356F10);
#ifdef SKIP_ASM
struct sMoveQuad2 {
    float v[4];
} __attribute__((aligned(16)));

extern void* D_0048F5F0[];

extern "C" void* func_00356F10(void* self, void* src)
{
    *(void***)self = D_0048F5F0;
    sMoveQuad2 v = *(sMoveQuad2*)((char*)src + 0x30);
    *(sMoveQuad2*)((char*)self + 0x30) = v;
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy, src -> self+0x50).
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"((char*)self + 0x50), "r"(src)
        : "memory");
    *(int*)((char*)self + 0x44) = 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00356F68);
#ifdef SKIP_ASM
struct sMnVEntrySer6F68 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// PORT: callers declare this void; the body returns self, so bind it via an asm label.
extern "C" void* func_00356F68(void* self, void* stream);
extern "C" void* func_00356F68(void* self, void* stream)
{
    *(void***)self = D_0048F5F0;
    sMnVEntrySer6F68* vt = *(sMnVEntrySer6F68**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x10, 0x40);
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy, D_004FF1A0 -> self+0x50).
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"((char*)self + 0x50), "r"(D_004FF1A0)
        : "memory");
    *(int*)((char*)self + 0x44) = 1;
    return self;
}
#endif

typedef int cQuad128 __attribute__((mode(TI)));

//100%
INCLUDE_ASM("object/movenode", func_00356FF0);
#ifdef SKIP_ASM
extern "C" void func_00356FF0(void* self)
{
    cQuad128 v = *(cQuad128*)((char*)self + 0x30);
    *(int*)((char*)self + 0x44) = 0;
    *(cQuad128*)((char*)self + 0x80) = v;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357000);
#ifdef SKIP_ASM
class func_00357000_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
};

extern "C" void func_00357000(void* self, func_00357000_cObj* obj)
{
    obj->v01((char*)self + 0x10, 0x40);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357038);
#ifdef SKIP_ASM
extern char D_0048F508[];

extern "C" void* func_00357038(void* self, void* a1, void* a2, sMoveQuad* pos)
{
    func_00356EB8(self, pos);
    *(void**)((char*)self + 0x0) = D_0048F508;
    *(void**)((char*)self + 0xA0) = a1;
    *(void**)((char*)self + 0x90) = a2;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00357090);
#ifdef SKIP_ASM
struct sMnVEntrySer7090 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sMnVEntryRd7090 {
    short delta;
    short index;
    void* (*fn)(void*);
};

extern "C" void* func_00356F68(void* self, void* stream);
extern char D_0048F508[];

extern "C" void* func_00357090(void* self, void* stream)
{
    func_00356F68(self, stream);
    *(void**)((char*)self + 0x0) = D_0048F508;
    sMnVEntrySer7090* e = &(*(sMnVEntrySer7090**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x90, 4);
    sMnVEntryRd7090* r = &(*(sMnVEntryRd7090**)stream)[3];
    *(void**)((char*)self + 0xA0) = r->fn((char*)stream + r->delta);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357108);
#ifdef SKIP_ASM
struct sMnVec4_357108 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMnMtx_357108 {
    sMnVec4_357108 r[4];
};

extern "C" void func_0034FED8(void* model, int bone, sMnMtx_357108* out);

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMtx_357108(void* dst, void* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (matrix * vector).
static inline sMnVec4_357108 vu0MtxApply_357108(sMnMtx_357108* m, sMnVec4_357108* v)
{
    sMnVec4_357108 out;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf8, %1\n"
        "lqc2      $vf4, 0x0(%2)\n"
        "lqc2      $vf5, 0x10(%2)\n"
        "lqc2      $vf6, 0x20(%2)\n"
        "lqc2      $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        ".set pop\n"
        : "=m"(out)
        : "m"(*v), "r"(m)
        : "memory");
    return out;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sMnVec4_357108 vu0Add_357108(const sMnVec4_357108& a, const sMnVec4_357108& b)
{
    sMnVec4_357108 r;
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

static inline sMnVec4_357108 vel_357108(char* self)
{
    return *(sMnVec4_357108*)(self + 0x80);
}

struct sMnVEntryI_357108 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sMnVEntryM_357108 {
    short delta;
    short index;
    sMnMtx_357108* (*fn)(void*, int);
};

extern "C" void func_00357108(char* self)
{
    char* o = *(char**)(*(char**)(self + 0xA0) + 0xC);
    if (o != 0) {
        sMnVEntryI_357108* vi = *(sMnVEntryI_357108**)(o + 0xC);
        if (vi[26].fn(o + vi[26].delta) != 0) {
            sMnVEntryM_357108* vm = *(sMnVEntryM_357108**)(o + 0xC);
            vu0CopyMtx_357108(self + 0x50, vm[29].fn(o + vm[29].delta, *(int*)(self + 0x90)));
        } else {
            func_0034FED8(*(void**)(self + 0xA0), *(int*)(self + 0x90), (sMnMtx_357108*)(self + 0x50));
        }
        *(sMnVec4_357108*)(self + 0x80) = vu0Add_357108(vel_357108(self), vu0MtxApply_357108((sMnMtx_357108*)(self + 0x50), (sMnVec4_357108*)(self + 0x30)));
    }
    *(int*)(self + 0x44) = 0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357210);
#ifdef SKIP_ASM
struct sMnVEntry7210 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

extern "C" void func_00357210(void* self, void* obj)
{
    void* p = *(void**)((char*)self + 0xA0);
    if (p == 0) {
        return;
    }
    void* q = *(void**)((char*)p + 0xC);
    if (q == 0) {
        return;
    }
    int saved = *(int*)((char*)obj + 0x5C);
    *(int*)((char*)obj + 0x5C) = *(int*)((char*)self + 0x90);
    sMnVEntry7210* vt = *(sMnVEntry7210**)((char*)q + 0xC);
    vt[42].fn((char*)q + vt[42].delta, obj);
    *(int*)((char*)obj + 0x5C) = saved;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00357278);
#ifdef SKIP_ASM
struct sMnVEntry7278a {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sMnVEntry7278b {
    short delta;
    short index;
    void (*fn)(void*, void*);
};


extern "C" void func_00357278(void* self, void* stream)
{
    func_00357000(self, (func_00357000_cObj*)stream);
    sMnVEntry7278a* vt1 = *(sMnVEntry7278a**)stream;
    vt1[1].fn((char*)stream + vt1[1].delta, (char*)self + 0x90, 4);
    sMnVEntry7278b* vt2 = *(sMnVEntry7278b**)stream;
    vt2[5].fn((char*)stream + vt2[5].delta, *(void**)((char*)self + 0xA0));
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003572E0);
#ifdef SKIP_ASM
extern char D_0048F420[];

extern "C" void* func_003572E0(void* self, void* a1, void* mat, float f40, float speed)
{
    char* s = (char*)self;
    *(void**)self = D_0048F420;
    *(void**)(s + 0xA0) = a1;
    *(float*)(s + 0x40) = f40;
    *(float*)(s + 0x48) = speed * 27.77777862548828f;
    *(int*)(s + 0x44) = -1;
    *(int*)(s + 0x4C) = 0;
    *(int*)(s + 0x54) = 0;
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy, mat -> self+0x60).
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(s + 0x60), "r"(mat)
        : "memory");
    *(int*)(s + 0x50) = 1;
    sMoveQuad v = *(sMoveQuad*)(s + 0x90);
    *(sMoveQuad*)(s + 0x10) = v;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357358);
#ifdef SKIP_ASM
struct sMnVEntrySer7358 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sMnVEntryRd7358 {
    short delta;
    short index;
    void* (*fn)(void*);
};

extern char D_0048F420[];

extern "C" void* func_00357358(void* self, void* stream)
{
    char* m = (char*)self + 0x10;
    *(void**)self = D_0048F420;
    sMnVEntryRd7358* r = &(*(sMnVEntryRd7358**)stream)[3];
    *(void**)((char*)self + 0xA0) = r->fn((char*)stream + r->delta);
    sMnVEntrySer7358* e = &(*(sMnVEntrySer7358**)stream)[2];
    e->fn((char*)stream + e->delta, m, 0x50);
    e = &(*(sMnVEntrySer7358**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x60, 0x40);
    *(int*)((char*)self + 0x50) = 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003573F8);
#ifdef SKIP_ASM
extern "C" float func_002D1C70();
extern "C" void* func_002D1B58(int id);

struct sMnVec4_3573F8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (a - b).
static inline sMnVec4_3573F8 vu0Sub_3573F8(const sMnVec4_3573F8& a, const sMnVec4_3573F8& b)
{
    sMnVec4_3573F8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vu0Length_3573F8(const sMnVec4_3573F8& v)
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
static inline sMnVec4_3573F8 vu0Scale_3573F8(const sMnVec4_3573F8& v, float s)
{
    sMnVec4_3573F8 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (dst += v).
static inline void vu0AddTo_3573F8(sMnVec4_3573F8& dst, const sMnVec4_3573F8& v)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(v));
}

struct sMnMover_3573F8 {
    char pad0[0x10];
    sMnVec4_3573F8 pos;
    char pad20[0x24];
    int target;
    float speed;
    float time;
    int moved;
    int arrived;
};

extern "C" void func_003573F8(sMnMover_3573F8* self)
{
    if (self->target < 0) {
        return;
    }
    self->time += func_002D1C70();
    sMnVec4_3573F8 d = vu0Sub_3573F8(*(sMnVec4_3573F8*)func_002D1B58(self->target), self->pos);
    float len = vu0Length_3573F8(d);
    if (len < 50.0f) {
        self->arrived = 1;
    } else {
        sMnVec4_3573F8 step = vu0Scale_3573F8(d, self->speed / len * self->time);
        if (len < vu0Length_3573F8(step)) {
            self->arrived = 1;
            step = d;
        }
        vu0AddTo_3573F8(self->pos, step);
    }
    self->moved = 1;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357528);
#ifdef SKIP_ASM
extern "C" void func_00357528(void* self)
{
    cQuad128 v = *(cQuad128*)((char*)self + 0x10);
    *(int*)((char*)self + 0x50) = 0;
    *(cQuad128*)((char*)self + 0x90) = v;
}
#endif

INCLUDE_ASM("object/movenode", func_00357538);

//100%
INCLUDE_ASM("object/movenode", func_00357660);
#ifdef SKIP_ASM
struct sMnVEntryI7660 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void* func_002D1B08(int id);

extern "C" int func_00357660(void* self, int id)
{
    int cur = *(int*)((char*)self + 0x44);
    if (cur >= 0) {
        if (cur == id) {
            return *(int*)((char*)self + 0x54);
        }
        return 0;
    }
    void* obj = func_002D1B08(id);
    sMnVEntryI7660* vt = *(sMnVEntryI7660**)obj;
    if (vt[8].fn((char*)obj + vt[8].delta) != 0) {
        *(int*)((char*)self + 0x44) = id;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003576D0);
#ifdef SKIP_ASM
struct sMnVEntryPtr76D0 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sMnVEntrySer76D0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_003576D0(void* self, void* stream)
{
    sMnVEntryPtr76D0* p = &(*(sMnVEntryPtr76D0**)stream)[5];
    p->fn((char*)stream + p->delta, *(void**)((char*)self + 0xA0));
    sMnVEntrySer76D0* e = &(*(sMnVEntrySer76D0**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 0x50);
    e = &(*(sMnVEntrySer76D0**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x60, 0x40);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357750);
#ifdef SKIP_ASM
extern void* D_0048F338[];

// PORT: PS2-only VU0 inline asm (4x4 matrix copy, src+0x10 -> self+0x40); the PC
// port needs a plain 64-byte copy.
extern "C" void* func_00357750(void* self, void* src)
{
    *(void***)self = D_0048F338;
    *(void**)((char*)self + 0x80) = src;
    *(int*)((char*)self + 0x30) = 0;
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"((char*)self + 0x40), "r"((char*)src + 0x10)
        : "memory");
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357798);
#ifdef SKIP_ASM
struct sMnVEntrySer7798 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sMnVEntryRd7798 {
    short delta;
    short index;
    void* (*fn)(void*);
};

// PORT: the project names this func_002D1CF0__FPv (one void* arg), but it is a
// pass-through wrapper and this caller passes two args (prototype mismatch).
void* func_002D1CF0_2(void*, void*) __asm__("func_002D1CF0__FPv");

extern "C" void* func_00357798(void* self, void* stream)
{
    char* m = (char*)self + 0x10;
    *(void***)self = D_0048F338;
    sMnVEntryRd7798* r = &(*(sMnVEntryRd7798**)stream)[3];
    *(void**)((char*)self + 0x80) = r->fn((char*)stream + r->delta);
    sMnVEntrySer7798* e = &(*(sMnVEntrySer7798**)stream)[2];
    e->fn((char*)stream + e->delta, m, 0x30);
    func_002D1CF0_2(*(void**)((char*)self + 0x80), (char*)self + 0x40);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357820);
#ifdef SKIP_ASM
// PORT: the project names this func_002D1CF0__FPv (one void* arg), but it is a
// pass-through wrapper and this caller passes two args (prototype mismatch).
void* func_002D1CF0_2(void*, void*) __asm__("func_002D1CF0__FPv");

extern "C" void func_00357820(void* self)
{
    func_002D1CF0_2(*(void**)((char*)self + 0x80), (char*)self + 0x40);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357848);
#ifdef SKIP_ASM
struct sMnVEntry7848a {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sMnVEntry7848b {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00357848(void* self, void* stream)
{
    sMnVEntry7848a* vt1 = *(sMnVEntry7848a**)stream;
    vt1[5].fn((char*)stream + vt1[5].delta, *(void**)((char*)self + 0x80));
    sMnVEntry7848b* vt2 = *(sMnVEntry7848b**)stream;
    vt2[1].fn((char*)stream + vt2[1].delta, (char*)self + 0x10, 0x30);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_003578A8);
#ifdef SKIP_ASM
extern "C" void* func_00355280(void* self, void* a1, int type, void* a3);
extern "C" void func_00355F10(cMoveNode* self, void* a1);
extern void* D_0048EE60[];

extern "C" void* func_003578A8(cMoveNode* self, void* a1, void* a2, void* particle, void* a4)
{
    func_00355280(self, a1, 0xD, a2);
    *(void***)((char*)self + 0xC) = D_0048EE60;
    func_00355F10(self, a4);
    cMoveNode_addParticle(self, particle);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00357918);
#ifdef SKIP_ASM
extern "C" void* cMoveNode_cMoveNode(void* self);
extern void* D_0048EE60[];

extern "C" void* func_00357918(void* self, void* bucket, void* stream)
{
    cMoveNode_cMoveNode(self);
    *(void***)((char*)self + 0xC) = D_0048EE60;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00357950);
#ifdef SKIP_ASM
struct sMnDtorVEntry7950 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00356198(void* self);

extern "C" void func_00357950(void* self)
{
    func_00356198(self);
    void* mb = *(void**)((char*)self + 0x1C);
    if (mb != 0 && *(int*)((char*)mb + 0x10) != 0) {
        return;
    }
    if (self != 0) {
        sMnDtorVEntry7950* vt = *(sMnDtorVEntry7950**)((char*)self + 0xC);
        vt[1].fn((char*)self + vt[1].delta, 3);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003579A8__FPv);
#ifdef SKIP_ASM
void* func_003579A8(void* self)
{
    return func_00356B30(self);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_003579C8);
#ifdef SKIP_ASM
extern void* D_004A4028;

extern "C" void* func_003579C8(void* self)
{
    int i;
    D_004A4028 = self;
    for (i = 0; i < 4; i++) {
        ((void**)self)[i] = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357A00);
#ifdef SKIP_ASM
extern void* D_004A4028;
extern "C" void func_00357FA0(void* p, int flags);
void operator_delete(int* ptr);

extern "C" void func_00357A00(void* self, int flags)
{
    int i;
    for (i = 0; i < 4; i++) {
        void* p = ((void**)self)[i];
        if (p != 0) {
            func_00357FA0(p, 3);
        }
    }
    D_004A4028 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357A78);
#ifdef SKIP_ASM
extern char D_0048EA00[];
extern "C" void* func_00357DD8(void* mem, void* a1, void* a2);

extern "C" void func_00357A78(void* self, int i, void* a2, void* a3)
{
    void** slot = (void**)((char*)self + (i << 2));
    if (*slot == 0) {
        *slot = func_00357DD8(cMemMan_alloc(0x50, D_0048EA00, 0x20000000, 0), a2, a3);
    }
}
#endif

extern "C" void func_003581B8(int, int);

//100%
INCLUDE_ASM("object/movenode", func_00357AE8__FPvii);
#ifdef SKIP_ASM
void func_00357AE8(void* self, int a1, int a2)
{
    func_003581B8(*(int*)((char*)self + (a1 << 2)), a2);
}
#endif

extern "C" void func_003581F0(int, int);

//100%
INCLUDE_ASM("object/movenode", func_00357B10__FPvii);
#ifdef SKIP_ASM
void func_00357B10(void* self, int a1, int a2)
{
    func_003581F0(*(int*)((char*)self + (a1 << 2)), a2);
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357B38);
#ifdef SKIP_ASM
extern "C" void func_00357FA0(void* p, int flags);

extern "C" void func_00357B38(void** self)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (self[i] != 0) {
            func_00357FA0(self[i], 3);
        }
        self[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357B90);
#ifdef SKIP_ASM
extern "C" void func_00358140(void* p, void* arg);

extern "C" void func_00357B90(void** self, void* arg)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (self[i] != 0) {
            func_00358140(self[i], arg);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357BF8);
#ifdef SKIP_ASM
extern "C" void func_00358120(void* p);

extern "C" void func_00357BF8(void** self)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (self[i] != 0) {
            func_00358120(self[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357C50);
#ifdef SKIP_ASM
extern "C" void func_00358260(void* p);

extern "C" void func_00357C50(void** self)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (self[i] != 0) {
            func_00358260(self[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357CA8);
#ifdef SKIP_ASM
struct sMnVEntrySer7CA8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00358380(void* obj, void* stream);

extern "C" void func_00357CA8(void** self, void* stream)
{
    int i;
    for (i = 0; i < 4; i++) {
        int has = self[i] != 0;
        sMnVEntrySer7CA8* e = &(*(sMnVEntrySer7CA8**)stream)[1];
        e->fn((char*)stream + e->delta, &has, 4);
        if (has) {
            func_00358380(self[i], stream);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/movenode", func_00357D28);
#ifdef SKIP_ASM
struct sMnVEntrySer7D28 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_00357E80(void* mem, void* stream);

extern "C" void func_00357D28(void** self, void* stream)
{
    int i;
    func_00357B38(self);
    for (i = 0; i < 4; i++) {
        int has;
        sMnVEntrySer7D28* e = &(*(sMnVEntrySer7D28**)stream)[2];
        e->fn((char*)stream + e->delta, &has, 4);
        if (has) {
            self[i] = func_00357E80(cMemMan_alloc(0x50, D_0048EA00, 0x20000000, 0), stream);
        } else {
            self[i] = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357DD8);
#ifdef SKIP_ASM
struct sQuad_7DD8 {
    float v[4];

    sQuad_7DD8() {}
    sQuad_7DD8(float x, float y, float z, float w)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
        v[3] = w;
    }
} __attribute__((aligned(16)));

struct sPartDesc_7DD8 {
    char pad_0x000[0xC0];
    float pos[3];           // 0xC0
    char pad_0x0cc[0x94];
    sQuad_7DD8 a;           // 0x160
    sQuad_7DD8 b;           // 0x170
};

struct sMultiPart_7DD8 {
    void* owner;            // 0x0
    int field_0x4;          // 0x4
    void* data;             // 0x8
    int field_0xc;          // 0xC
    sPartDesc_7DD8* desc;   // 0x10
    char pad_0x14[0xC];
    sQuad_7DD8 a;           // 0x20
    sQuad_7DD8 b;           // 0x30
    sQuad_7DD8 pos;         // 0x40
};

extern char D_0048EA10[];
extern "C" void func_003E6574(void* dst, const void* src, int n);
extern "C" void cMultiParticle_setupMultiParticle(void* self);

extern "C" void* func_00357DD8(void* mem, void* a1, void* a2)
{
    sMultiPart_7DD8* self = (sMultiPart_7DD8*)mem;
    self->owner = a2;
    self->field_0x4 = 0;
    void* buf = cMemMan_alloc(0xD8, D_0048EA10, 0x20000000, 0);
    self->data = buf;
    func_003E6574(buf, a1, 0xD8);
    cMultiParticle_setupMultiParticle(self);
    sPartDesc_7DD8* d = self->desc;
    self->a = d->a;
    self->b = d->b;
    self->pos = sQuad_7DD8(d->pos[0], d->pos[1], d->pos[2], 0.0f);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357E80);
#ifdef SKIP_ASM
extern "C" void func_00370AF8(void* self, void* stream);

struct sMnSerVEntry_357E80 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

static inline void read_357E80(void* stream, void* dst, int n)
{
    sMnSerVEntry_357E80* vt = *(sMnSerVEntry_357E80**)stream;
    vt[2].fn((char*)stream + vt[2].delta, dst, n);
}

extern "C" void* func_00357E80(void* mem, void* stream)
{
    sMultiPart_7DD8* self = (sMultiPart_7DD8*)mem;
    sQuad_7DD8* ab = &self->a;
    read_357E80(stream, self, 4);
    read_357E80(stream, &self->field_0x4, 4);
    void* buf = cMemMan_alloc(0xD8, D_0048EA10, 0x20000000, 0);
    self->data = buf;
    read_357E80(stream, buf, 0xD8);
    cMultiParticle_setupMultiParticle(self);
    func_00370AF8(self->desc, stream);
    read_357E80(stream, &self->pos, 0x10);
    read_357E80(stream, ab, 0x20);
    if (self->field_0x4 > 0) {
        read_357E80(stream, (void*)self->field_0xc, self->field_0x4 * 4);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/movenode", func_00357FA0);
#ifdef SKIP_ASM
struct sMnDtorVEntry7FA0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

void operator_delete(int* ptr);
void cMemMan_free(void*);

extern "C" void func_00357FA0(void* self, int flags)
{
    operator_delete(*(int**)((char*)self + 0x8));
    void* buf = *(void**)((char*)self + 0xC);
    if (buf != 0) {
        cMemMan_free(buf);
    }
    void* obj = *(void**)((char*)self + 0x10);
    if (obj != 0) {
        sMnDtorVEntry7FA0* vt = *(sMnDtorVEntry7FA0**)((char*)obj + 0x18C);
        vt[1].fn((char*)obj + vt[1].delta, 3);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

