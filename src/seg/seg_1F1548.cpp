#include "common.h"

//100%
INCLUDE_ASM("seg/seg_1F1548", cPSPVisualEffectsMan_cPSPVisualEffectsMan);
#ifdef SKIP_ASM
extern "C" void *cMemMan_alloc(int, const char *, int, int);
extern "C" void* func_002EFF98(void*);
extern "C" void* func_00372AA0(void*);
void* func_003759E8(void*);
extern char D_00487D28[];
extern char D_00487BB8[];
extern char D_00487BC8[];
extern char D_00487BE0[];
extern char D_00487BF0[];
extern char D_00487C00[];
extern char D_00487C10[];
extern char D_00487C20[];
extern char D_00487C30[];
extern char D_00487C40[];
extern char D_00487C50[];
extern char D_00487C68[];
extern char D_00487C78[];
extern char D_00487C88[];
extern char D_00487DC8[];
extern char D_00487DF8[];
extern char D_00487E28[];
extern char D_00487E58[];
extern char D_00487E88[];
extern char D_00487EB8[];
extern char D_00487FA8[];
extern char D_00488050[];
extern char D_004882B0[];
extern char D_00488330[];
extern char D_00492FA0[];
extern char D_00492FD0[];
extern char D_004930A0[];
extern char D_00493178[];
extern char D_004931A8[];
extern char D_004A3B88[];
extern char D_004A3B90[];
extern char D_004A3B98[];
extern char D_004A3BA0[];

struct sMgr_0548 {
    void* objs[17];
    char* vptr;
};

extern "C" sMgr_0548* cPSPVisualEffectsMan_cPSPVisualEffectsMan(sMgr_0548* self)
{
    func_002EFF98(self);
    self->vptr = D_00487D28;
    { void* p = cMemMan_alloc(4, D_00487BB8, 0, 0); *(char**)p = D_004931A8; self->objs[0] = p; }
    { void* p = cMemMan_alloc(4, D_00487BC8, 0, 0); *(char**)p = D_00492FD0; self->objs[1] = p; }
    { void* p = cMemMan_alloc(4, D_00487BE0, 0, 0); *(char**)p = D_00487EB8; self->objs[2] = p; }
    { void* p = cMemMan_alloc(4, D_004A3B88, 0, 0); *(char**)p = D_00493178; self->objs[3] = p; }
    { void* p = cMemMan_alloc(4, D_00487BF0, 0, 0); *(char**)p = D_00487E88; self->objs[4] = p; }
    { void* p = cMemMan_alloc(4, D_00487C00, 0, 0); *(char**)p = D_00487E58; self->objs[5] = p; }
    self->objs[6] = func_003759E8(cMemMan_alloc(4, D_00487C10, 0, 0));
    { void* p = cMemMan_alloc(4, D_00487C20, 0, 0); *(char**)p = D_00492FA0; self->objs[7] = p; }
    { void* p = cMemMan_alloc(4, D_004A3B90, 0, 0); *(char**)p = D_00487E28; self->objs[8] = p; }
    { void* p = cMemMan_alloc(4, D_00487C30, 0, 0); *(char**)p = D_00487DF8; self->objs[9] = p; }
    { void* p = cMemMan_alloc(4, D_00487C40, 0, 0); *(char**)p = D_00487FA8; self->objs[10] = p; }
    { void* p = cMemMan_alloc(4, D_004A3B98, 0, 0); *(char**)p = D_00487DC8; self->objs[11] = p; }
    { void* p = cMemMan_alloc(4, D_00487C50, 0, 0); *(char**)p = D_00488330; self->objs[12] = p; }
    { void* p = cMemMan_alloc(4, D_00487C68, 0, 0); *(char**)p = D_00488050; self->objs[13] = p; }
    { void* p = cMemMan_alloc(4, D_00487C78, 0, 0); *(char**)p = D_004882B0; self->objs[14] = p; }
    { void* p = cMemMan_alloc(4, D_004A3BA0, 0, 0); *(char**)p = D_004930A0; self->objs[15] = p; }
    self->objs[16] = func_00372AA0(cMemMan_alloc(4, D_00487C88, 0, 0));
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F0820);
#ifdef SKIP_ASM
void operator_delete(int *);
struct Obj0820 {
    virtual ~Obj0820();
};
extern char D_00487D28[];
extern char D_00487DA0[];

struct sMgr_0820 {
    Obj0820* objs[17];
    char* vptr;
};

extern "C" void func_002F0820(sMgr_0820* self, int arg1)
{
    self->vptr = D_00487D28;
    delete self->objs[0];
    delete self->objs[1];
    delete self->objs[2];
    delete self->objs[3];
    delete self->objs[4];
    delete self->objs[5];
    delete self->objs[6];
    delete self->objs[7];
    delete self->objs[8];
    delete self->objs[9];
    delete self->objs[10];
    delete self->objs[11];
    delete self->objs[12];
    delete self->objs[13];
    delete self->objs[14];
    delete self->objs[15];
    delete self->objs[16];
    self->vptr = D_00487DA0;
    if (arg1 & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F0A98);
#ifdef SKIP_ASM
class cObj_0A98 {
public:
    virtual void v0();
    virtual void Reset();
};

class cWorld_0A98 {
public:
    char pad[0x10D8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v26();
    virtual void v27();
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
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void ResetSlot(int i);
};

struct sMgr_0A98 {
    cObj_0A98* objs[17];
};

extern void* D_004A28A8;
extern char* D_004A289C;
extern int D_004A3BA8;
extern "C" void func_002F00A0(void*, int);

extern "C" void func_002F0A98(sMgr_0A98* self)
{
    self->objs[0]->Reset();
    self->objs[1]->Reset();
    self->objs[2]->Reset();
    self->objs[3]->Reset();
    self->objs[4]->Reset();
    self->objs[5]->Reset();
    self->objs[6]->Reset();
    self->objs[7]->Reset();
    self->objs[8]->Reset();
    self->objs[9]->Reset();
    self->objs[10]->Reset();
    self->objs[11]->Reset();
    self->objs[12]->Reset();
    self->objs[13]->Reset();
    self->objs[14]->Reset();
    self->objs[15]->Reset();
    self->objs[16]->Reset();
    for (int i = 0; i < *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84) + 0x10); i++) {
        func_002F00A0(self, (&D_004A3BA8)[i]); // PORT: D_004A3BA8 is an int array ($gp-addressed)
        ((cWorld_0A98*)D_004A289C)->ResetSlot(i);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F0CD0);
#ifdef SKIP_ASM
class cObj_0CD0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void Update();
};

struct sMgr_0CD0 {
    cObj_0CD0* objs[17];
};

extern "C" void func_002F0CD0(sMgr_0CD0* self)
{
    self->objs[0]->Update();
    self->objs[1]->Update();
    self->objs[2]->Update();
    self->objs[3]->Update();
    self->objs[4]->Update();
    self->objs[5]->Update();
    self->objs[6]->Update();
    self->objs[7]->Update();
    self->objs[8]->Update();
    self->objs[9]->Update();
    self->objs[10]->Update();
    self->objs[11]->Update();
    self->objs[12]->Update();
    self->objs[13]->Update();
    self->objs[14]->Update();
    self->objs[15]->Update();
    self->objs[16]->Update();
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F0E88);

INCLUDE_ASM("seg/seg_1F1548", func_002F0FE8);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1148);
#ifdef SKIP_ASM
extern "C" void func_002F1148(void *arg0) {
    (*(int *)((char*)(arg0) + (0xA0))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1150);
#ifdef SKIP_ASM
int func_00312AA0(void* self, int i);
extern "C" int func_00311AE8(void*, int);
extern "C" char* func_00311B20(void*, int);
extern "C" int func_001446A0(void*, int);
extern int D_004A3AFC;

struct sVec4_1150 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCol_1150 {
    float r, g, b, a;
};

struct sMat_1150 {
    sVec4_1150 r[4];
};

extern sVec4_1150 D_004FF120;

struct sFx_1150 {
    char* owner;
    char pad4[0xC];
    sVec4_1150 pos[4];
    sCol_1150 col[4];
    float size[4];
    int active;
};

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void CopyMat_1150(sMat_1150* dst, sMat_1150* src)
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
static inline void MulMat_1150(sVec4_1150* out, const sMat_1150* m, const sVec4_1150& v)
{
    sVec4_1150 r;
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
    *out = r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline void Add_1150(sVec4_1150* out, const sVec4_1150& a, const sVec4_1150& b)
{
    sVec4_1150 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    *out = r;
}

// PORT: float bit-pattern random number in [0,1) (seed reused as float storage).
static inline float randf_1150()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

static inline float randRange_1150(float lo, float hi)
{
    return lo + (hi - lo) * randf_1150();
}

extern "C" void func_002F1150(sFx_1150* self)
{
    int active = 0.0f < *(float*)(self->owner + 0x350);
    self->active = active;
    if (!active)
        return;
    int bone = *(int*)(self->owner + 0x8B0);
    int flag = 0;
    int a = func_00312AA0(*(void**)(self->owner + 0x784), 0);
    int b = func_00312AA0(*(void**)(self->owner + 0x784), 1);
    if (func_00311AE8(*(void**)(self->owner + 0x784), 1) == 0xD) {
        if (func_001446A0(func_00311B20(*(void**)(self->owner + 0x784), 1) + 0xB0, 1) == 0) {
            flag = func_001446A0(func_00311B20(*(void**)(self->owner + 0x784), 1) + 0xB0, 0) != 0;
        }
    }
    if (a == 0x146 || (b == 0x143 && flag)) {
        if (*(int*)(self->owner + 0x320))
            bone = *(int*)(self->owner + 0x8B0);
        else
            bone = *(int*)(self->owner + 0x8B8);
    } else if (a == 0x147 || (b == 0x144 && flag)) {
        if (*(int*)(self->owner + 0x320))
            bone = *(int*)(self->owner + 0x8B8);
        else
            bone = *(int*)(self->owner + 0x8B0);
    } else {
        self->active = 0;
    }
    if (self->active) {
        sVec4_1150 base = *(sVec4_1150*)(*(char**)(*(char**)(self->owner + 0x780) + 0x30) + (bone << 6) + 0x30);
        sMat_1150 m;
        CopyMat_1150(&m, &(*(sMat_1150**)(*(char**)(self->owner + 0x780) + 0x30))[bone]);
        m.r[3] = D_004FF120;
        sVec4_1150 v;
        sVec4_1150 rnd;
        {
            sVec4_1150 dir;
            dir.x = 8.0f;
            dir.y = 0.0f;
            dir.z = 0.0f;
            dir.w = 0.0f;
            MulMat_1150(&rnd, &m, dir);
            Add_1150(&v, base, rnd);
            base = v;
        }
        for (int i = 0; i < 4; i++) {
            float s = *(float*)(self->owner + 0x350);
            float a = s * 3.0f;
            float hi = s * 15.0f + 15.0f;
            rnd.w = 0.0f;
            rnd.x = randRange_1150(-a, a);
            rnd.y = randRange_1150(-a, a);
            rnd.z = randRange_1150(-a, a);
            Add_1150(&v, base, rnd);
            self->pos[i] = v;
            self->size[i] = randRange_1150(15.0f, hi);
            float c = *(float*)(self->owner + 0x350) * 0.9f;
            c *= randf_1150();
            v.x = 1.0f;
            v.y = c;
            v.z = c;
            v.w = c;
            self->col[i] = *(sCol_1150*)&v;
        }
    }
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F1510);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1768);
#ifdef SKIP_ASM
extern "C" void func_00370B60();
extern char D_004881E8[];

extern "C" void *func_002F1768(void *arg0) {
    func_00370B60();
    *(int *)((char*)arg0 + 0x200) = 0;
    *(char **)((char*)arg0 + 0x1F8) = D_004881E8;
    *(int *)((char*)arg0 + 0x204) = 0;
    *(int *)((char*)arg0 + 0x208) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F17A8);
#ifdef SKIP_ASM
extern "C" void func_00370C08(void *);
extern char D_004881E8[];

extern "C" void func_002F17A8(void *arg0) {
    *(char **)((char*)arg0 + 0x1F8) = D_004881E8;
    func_00370C08(arg0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F17D0);
#ifdef SKIP_ASM
extern "C" void func_002F83B0();
extern "C" void func_002F9838();
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi_17D0(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00487C98[];
extern int D_004A3BB0;

extern "C" void func_002F17D0(void) {
    D_004A3BB0 = (int)operator_new__FUi_17D0(0x1540, D_00487C98, 0, 0);
    func_002F83B0();
    func_002F9838();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1810);
#ifdef SKIP_ASM
extern "C" void cMemMan_free__FPv(int);
extern "C" void func_002F8FF8__FPv();
extern "C" void func_002FA5F8__FPv();
extern int D_004A3BB0;

extern "C" void func_002F1810(void) {
    func_002F8FF8__FPv();
    func_002FA5F8__FPv();
    if (D_004A3BB0 != 0) {
        cMemMan_free__FPv(D_004A3BB0);
    }
    D_004A3BB0 = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1850);
#ifdef SKIP_ASM
extern "C" void func_002F18D8(void *);
extern char D_004881D0[];

extern "C" void *func_002F1850(void *arg0, int arg1) {
    *(int *)((char*)arg0 + 0x94) = 0;
    *(int *)((char*)arg0 + 0x9C) = 0;
    *(char **)((char*)arg0 + 0xA4) = D_004881D0;
    *(int *)((char*)arg0 + 0x98) = arg1;
    func_002F18D8(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1890);
#ifdef SKIP_ASM
extern "C" void func_002F18D8(void *);
extern "C" void func_002F1A00(void *);
extern char D_004881D0[];

extern "C" void *func_002F1890(void *arg0, int arg1) {
    *(int *)((char*)arg0 + 0x94) = 0;
    *(int *)((char*)arg0 + 0x98) = 0;
    *(int *)((char*)arg0 + 0x9C) = arg1;
    *(char **)((char*)arg0 + 0xA4) = D_004881D0;
    func_002F18D8(arg0);
    func_002F1A00(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F18D8);
#ifdef SKIP_ASM
extern "C" void func_002F17D0();
extern int D_004A3BB4;

extern "C" void func_002F18D8(void *arg0) {
    if (D_004A3BB4 == 0) {
        func_002F17D0();
    }
    D_004A3BB4 += 1;
    for (int i = 9; i >= 0; i--)
        *(int *)((char*)arg0 + 0x6C + i * 4) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1940);
#ifdef SKIP_ASM
extern "C" void func_002F1810();
void operator_delete(int *);
extern char D_004881D0[];
extern int D_004A3BB4;
struct Base1940 { char pad[0x1F8]; };
struct Obj1940 : Base1940 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Obj1940();
};

extern "C" void func_002F1940(void *arg0, int arg1) {
    int c = D_004A3BB4 - 1;
    *(char **)((char*)arg0 + 0xA4) = D_004881D0;
    D_004A3BB4 = c;
    if (c == 0) {
        func_002F1810();
    }
    Obj1940 **p = (Obj1940 **)((char*)arg0 + 0x6C);
    int n = 9;
    do {
        if (*p != 0) {
            delete *p;
        }
        *p = 0;
        n--;
        p++;
    } while (n >= 0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F19F0);
#ifdef SKIP_ASM
extern "C" void func_002F19F0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x94))) = arg1;
    (*(int *)((char*)(arg0) + (0))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F1A00);
#ifdef SKIP_ASM
extern "C" void func_002F1A00(void *arg0) {
    (*(int *)((char*)(arg0) + (0xA0))) = 0;
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F1A08);

INCLUDE_ASM("seg/seg_1F1548", func_002F2088);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2130);
#ifdef SKIP_ASM
struct Base2130 { char pad[0x1F8]; };
struct Obj2130 : Base2130 {
    virtual void v0();
    virtual void v1();
    virtual void v2(int, float);
};
extern "C" void *cMemMan_alloc(int, const char *, int, int);
extern "C" void *func_002F1768(void *);
extern char D_00487CB0[];
extern int D_004A3BB0;

extern "C" int func_002F2130(void *arg0, int arg1, int arg2) {
    Obj2130 **p = (Obj2130 **)((char*)arg0 + 0x6C);
    int i;
    for (i = 0; i < 10; i++, p++) {
        if (*p == 0) {
            Obj2130 *n = (Obj2130 *)func_002F1768(cMemMan_alloc(0x210, D_00487CB0, 0, 0));
            int t = D_004A3BB0 + arg1 * 0x110;
            *p = n;
            *(int *)((char*)*p + 0x200) = arg2;
            *(int *)((char*)*p + 0x204) = 0;
            *(int *)((char*)*p + 0x20C) = t;
            Obj2130 *o = *p;
            o->v2(*(int *)((char*)o + 0x20C), *(float *)((char*)o + 0x58));
            (*p)->v1();
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2218);
#ifdef SKIP_ASM
struct sVE_2F2218 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_002F2218(char* self, int idx)
{
    int off = idx * 4;
    self += 0x6C;
    char** slot = (char**)(self + off);
    char* o = *slot;
    if (o != 0) {
        sVE_2F2218* vt = *(sVE_2F2218**)(o + 0x1F8);
        vt[4].fn(o + vt[4].delta, 3);
    }
    *slot = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2268);
#ifdef SKIP_ASM
extern "C" void func_002F2268(void *arg0, int arg1) {
    *(int *)((char *)(*(void **)((char *)arg0 + (arg1 << 2) + 0x6C)) + 0x204) = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2280);
#ifdef SKIP_ASM
extern "C" void func_002F2280(void *arg0, int arg1) {
    *(int *)((char *)(*(void **)((char *)arg0 + (arg1 << 2) + 0x6C)) + 0x204) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2298);
#ifdef SKIP_ASM
extern "C" void func_002F2298(void *arg0, int arg1) {
    *(int *)((char *)(*(void **)((char *)arg0 + (arg1 << 2) + 0x6C)) + 0x174) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F22B0);
#ifdef SKIP_ASM
extern "C" void func_002F22B0(void *arg0, int arg1) {
    *(int *)((char *)(*(void **)((char *)arg0 + (arg1 << 2) + 0x6C)) + 0x174) = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F22C8);
#ifdef SKIP_ASM
extern "C" int func_00310C48(void*, int, const char*);
extern char D_004879D8[];
extern char D_004879E8[];
extern char D_004879F8[];
extern char D_00487A08[];
extern char D_00487A18[];
extern char D_00487A28[];
extern char D_00487A38[];
extern char D_00487A48[];
extern char D_00487A58[];
extern char D_00487A68[];
extern char D_00487A78[];
extern char D_00487A88[];
extern char D_00487A98[];
extern char D_00487AA8[];
extern char D_00487AB8[];
extern char D_00487AC8[];
extern char D_00487AD8[];
extern char D_00487AE8[];
extern char D_00487AF8[];
extern char D_004A3B00[];
extern char D_004A3B08[];
extern char D_004A3BB8[];
extern char D_00487CC8[];


struct sObj_22C8 {
    int ready;
    int h[26];
    char pad[0x94 - 0x6C];
    void* model;
};

extern "C" void func_002F22C8(sObj_22C8* self)
{
    self->h[0] = func_00310C48(self->model, 0, D_004A3BB8);
    self->h[1] = func_00310C48(self->model, 0, D_004A3B08);
    self->h[2] = func_00310C48(self->model, 0, D_00487A58);
    self->h[3] = func_00310C48(self->model, 0, D_00487A48);
    self->h[4] = func_00310C48(self->model, 0, D_00487A38);
    self->h[5] = func_00310C48(self->model, 0, D_004A3B00);
    self->h[6] = func_00310C48(self->model, 0, D_00487A68);
    self->h[7] = func_00310C48(self->model, 0, D_00487A88);
    self->h[8] = func_00310C48(self->model, 0, D_00487A98);
    self->h[9] = func_00310C48(self->model, 0, D_00487AA8);
    self->h[10] = func_00310C48(self->model, 0, D_00487AB8);
    self->h[11] = func_00310C48(self->model, 0, D_00487AC8);
    self->h[12] = func_00310C48(self->model, 0, D_00487AD8);
    self->h[13] = func_00310C48(self->model, 0, D_00487AE8);
    self->h[14] = func_00310C48(self->model, 0, D_00487AF8);
    self->h[15] = func_00310C48(self->model, 0, D_00487A78);
    self->h[16] = func_00310C48(self->model, 0, D_00487A18);
    self->h[17] = func_00310C48(self->model, 0, D_004879D8);
    self->h[18] = func_00310C48(self->model, 0, D_004879E8);
    self->h[19] = func_00310C48(self->model, 0, D_00487A28);
    self->h[20] = func_00310C48(self->model, 0, D_004879F8);
    self->h[21] = func_00310C48(self->model, 0, D_00487A08);
    self->h[22] = func_00310C48(self->model, 1, D_00487CC8);
    self->h[23] = func_00310C48(self->model, 1, D_00487CC8);
    self->h[24] = func_00310C48(self->model, 1, D_00487CC8);
    self->h[25] = func_00310C48(self->model, 1, D_00487CC8);
    for (int i = 0; i < 26; i++) {
        // NOTE: empty in retail (likely a compiled-out per-handle assert)
    }
    self->ready = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2588);
#ifdef SKIP_ASM
extern "C" int *func_002F2588(int *arg0) {
    *arg0 = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2598);
#ifdef SKIP_ASM
extern int D_004A3AFC;
// NOTE: tunables are float members of global records; splat names each field separately.
struct sTun_2598 {
    float v;
};
extern sTun_2598 D_004A428C_2598 __asm__("D_004A428C");
extern sTun_2598 D_004A4290_2598 __asm__("D_004A4290");
extern sTun_2598 D_004A4294_2598 __asm__("D_004A4294");
extern sTun_2598 D_004A429C_2598 __asm__("D_004A429C");
extern sTun_2598 D_004A42CC_2598 __asm__("D_004A42CC");

struct sV2_2598 {
    float x, y;
    sV2_2598() {}
    sV2_2598(float ax, float ay) : x(ax), y(ay) {}
};

struct sV4_2598 {
    float x, y, z, w;
    sV4_2598() {}
    sV4_2598(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

extern sV4_2598 D_005046E0;
extern sV4_2598 D_005046F0;
extern sV2_2598 D_004A5960[]; // PORT: 8-byte object, declared unsized so it is not $gp-addressed

struct sPart_2598 {
    int active;
    sV2_2598 pos;
    sV2_2598 size;
    sV2_2598 vel;
    int age;
    float life;
    sV4_2598 color;
    float angle;
    float spin;
};

// PORT: float bit-pattern random number in [0,1) (seed reused as float storage).
static inline float randf_2598()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

static inline float randRange_2598(float lo, float hi)
{
    return lo + (hi - lo) * randf_2598();
}

static inline sV4_2598 operator*(const sV4_2598& a, float s)
{
    return sV4_2598(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline sV4_2598 operator+(const sV4_2598& a, const sV4_2598& b)
{
    return sV4_2598(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

extern "C" void func_002F2598_2598(sPart_2598* p, const sV2_2598& pos, sV2_2598* range) __asm__("func_002F2598");
extern "C" void func_002F2598_2598(sPart_2598* p, const sV2_2598& pos, sV2_2598* range)
{
    float maxY = range->y;
    float maxX = range->x;
    float x = randRange_2598(D_004A4294_2598.v, maxX);
    float v = x + randRange_2598(-D_004A429C_2598.v, D_004A429C_2598.v);
    float y = (v >= D_004A4294_2598.v) ? (v <? maxY) : D_004A4294_2598.v; // PORT: g++ <? operator
    p->age = 0;
    p->life = randRange_2598(D_004A428C_2598.v, D_004A4290_2598.v);
    p->active = 1;
    p->size = sV2_2598(x, y);
    p->pos = pos;
    p->vel = D_004A5960[0];
    p->angle = randf_2598() * 360.0f;
    p->spin = randRange_2598(-D_004A42CC_2598.v, D_004A42CC_2598.v);
    float t = randf_2598();
    p->color = D_005046E0 * (1.0f - t) + D_005046F0 * t;
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F2810);

INCLUDE_ASM("seg/seg_1F1548", func_002F2C30);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2D60);
#ifdef SKIP_ASM
extern "C" void *func_002F2D60(void *arg0) {
    (*(int *)((char*)(arg0) + (4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F2D70);
#ifdef SKIP_ASM
extern int D_004A3AFC;
// NOTE: tunables are float members of global records; splat names each field separately.
struct sTun_2D70 {
    float v;
};
extern sTun_2D70 D_004A42D8_2D70 __asm__("D_004A42D8");
extern sTun_2D70 D_004A42DC_2D70 __asm__("D_004A42DC");
extern sTun_2D70 D_004A42E0_2D70 __asm__("D_004A42E0");
extern sTun_2D70 D_004A42E4_2D70 __asm__("D_004A42E4");
extern sTun_2D70 D_004A42E8_2D70 __asm__("D_004A42E8");
extern sTun_2D70 D_004A4318_2D70 __asm__("D_004A4318");

struct sV2_2D70 {
    float x, y;
    sV2_2D70() {}
    sV2_2D70(float ax, float ay) : x(ax), y(ay) {}
};

struct sV4_2D70 {
    float x, y, z, w;
    sV4_2D70() {}
    sV4_2D70(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

extern sV4_2D70 D_00504700;
extern sV4_2D70 D_00504710;
extern sV2_2D70 D_004A5960_2D70[] __asm__("D_004A5960"); // PORT: 8-byte object, declared unsized so it is not $gp-addressed

struct sPart_2D70 {
    int dead;
    int active;
    sV2_2D70 pos;
    sV2_2D70 size;
    sV2_2D70 vel;
    int age;
    float life;
    sV4_2D70 color;
    float angle;
    float spin;
    int f40;
    int f44;
    int f48;
};

// PORT: float bit-pattern random number in [0,1) (seed reused as float storage).
static inline float randf_2D70()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

static inline float randRange_2D70(float lo, float hi)
{
    return lo + (hi - lo) * randf_2D70();
}

static inline float randSym_2D70(const float s)
{
    return randRange_2D70(-s, s);
}

static inline float clamp_2D70(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo; // PORT: g++ <? operator
}

static inline sV4_2D70 operator*(const sV4_2D70& a, float s)
{
    return sV4_2D70(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline sV4_2D70 operator+(const sV4_2D70& a, const sV4_2D70& b)
{
    return sV4_2D70(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

extern "C" void func_002F2D70_2D70(sPart_2D70* p, const sV2_2D70& pos, int n) __asm__("func_002F2D70");
extern "C" void func_002F2D70_2D70(sPart_2D70* p, const sV2_2D70& pos, int n)
{
    float x = randRange_2D70(D_004A42E0_2D70.v, D_004A42E4_2D70.v);
    float v = x + randSym_2D70(D_004A42E8_2D70.v);
    float y = clamp_2D70(v, D_004A42E0_2D70.v, D_004A42E4_2D70.v);
    for (int i = 0; i < n; i++) {
        x *= 0.699999988079071f;
        y *= 0.699999988079071f;
    }
    p->age = 0;
    p->life = randRange_2D70(D_004A42D8_2D70.v, D_004A42DC_2D70.v);
    p->active = 1;
    p->size = sV2_2D70(x, y);
    p->pos = pos;
    p->vel = D_004A5960_2D70[0];
    float t = randf_2D70();
    p->color = D_00504700 * (1.0f - t) + D_00504710 * t;
    p->angle = randf_2D70() * 360.0f;
    p->spin = randSym_2D70(D_004A4318_2D70.v);
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = 0;
    p->dead = 0;
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F3030);

INCLUDE_ASM("seg/seg_1F1548", func_002F3418);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F3550);
#ifdef SKIP_ASM
extern "C" void* func_00354648(void* self, void* a1);
extern "C" int* func_002F2588(int* arg0);
extern "C" void* func_002F2D60(void* arg0);
extern "C" void func_002F39C8(void* arg0);
extern char D_00488230[];

// Particle emitter constructor: builds the two 30-entry element pools and resets the emitter state.
extern "C" void* func_002F3550(void* p, void* a1, int a2)
{
    char* self = (char*)p;
    func_00354648(self, a1);
    *(int*)(self + 0x10) = a2;
    *(int*)(self + 0x14) = 0;
    *(char**)(self + 0xC) = D_00488230;
    *(int*)(self + 0x18) = 0;
    {
        char* e = self + 0x1C;
        int i = 29;
        do {
            func_002F2588((int*)e);
            i--;
            e += 0x3C;
        } while (i != -1);
    }
    {
        char* e = self + 0x724;
        int i = 29;
        do {
            func_002F2D60(e);
            i--;
            e += 0x4C;
        } while (i != -1);
    }
    *(int*)(self + 0x100C) = 0;
    *(int*)(self + 0x1010) = 0;
    *(int*)(self + 0x1014) = 0;
    *(int*)(self + 0x1018) = 0;
    *(float*)(self + 0x101C) = 1.0f;
    *(int*)(self + 0x1020) = 0;
    *(int*)(self + 0x1024) = 0;
    func_002F39C8(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F3618);
#ifdef SKIP_ASM
extern "C" void func_003546C8(void *);
extern char D_00488230[];

extern "C" void func_002F3618(void *arg0) {
    *(char **)((char*)arg0 + 0xC) = D_00488230;
    func_003546C8(arg0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1F1548", func_002F3640);
#ifdef SKIP_ASM
struct sVec2_3640 {
    float x, y;
};

struct sPart_3640 {
    char d[0x4C];
};

struct sEmit_3640 {
    char pad[0x18];
    int count;
    char pad1C[0x724 - 0x1C];
    sPart_3640 parts[1];
};

extern int D_004A3AFC;
extern int D_004A4258;
extern float D_004A42D0;
extern float D_004A42D4;
extern "C" void func_002F2D70(sPart_3640*, sVec2_3640*, int);

// PORT: float bit-pattern random number in [0,1) (seed reused as float storage).
static inline float randf_3640()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

static inline float randRange_3640(float lo, float hi)
{
    return lo + (hi - lo) * randf_3640();
}

extern "C" void func_002F3640(sEmit_3640* self, sVec2_3640* p, int n)
{
    for (int i = 0; i < n; i++) {
        if (self->count < D_004A4258) {
            sVec2_3640 off;
            off.x = randRange_3640(-D_004A42D0, D_004A42D0);
            off.y = randRange_3640(-D_004A42D4, D_004A42D4);
            sVec2_3640 pos;
            pos.x = p->x + off.x;
            pos.y = p->y + off.y;
            func_002F2D70(&self->parts[self->count], &pos, i);
            self->count++;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1F1548", func_002F37A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S37A8 { int a, b; S37A8() {} S37A8(const S37A8 &o) { *this = o; } };
extern "C" void func_002F2598(void *, S37A8, void *);
extern int D_004A4254;

extern "C" void func_002F37A8_37A8(void *arg0, S37A8 *arg1, void *arg2) __asm__("func_002F37A8");
extern "C" void func_002F37A8_37A8(void *arg0, S37A8 *arg1, void *arg2) {
    int n = *(int *)((char*)arg0 + 0x14);
    if (n < D_004A4254) {
        func_002F2598((char*)arg0 + (n * 0x3C + 0x1C), *arg1, arg2);
        *(int *)((char*)arg0 + 0x14) = *(int *)((char*)arg0 + 0x14) + 1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1F1548", func_002F3810);
#ifdef SKIP_ASM
struct sVec2_3810 {
    float x, y;
};

extern int D_004A3AFC;
extern float D_004A425C;
extern int D_004A4264;
extern int D_004A4268;
extern float D_004A4298;
unsigned int BXrand();
extern "C" void func_002F3640_3810(void*, sVec2_3810*, int) __asm__("func_002F3640");
extern "C" void func_002F37A8(void*, sVec2_3810*, sVec2_3810*);

// PORT: float bit-pattern random number in [0,1) (seed reused as float storage).
static inline float randf_3810()
{
    D_004A3AFC = ((D_004A3AFC * 0x18FCD + 0xE9507C) & 0x7FFFFF) | 0x3F800000;
    return *(float*)&D_004A3AFC - 1.0f;
}

static inline float randScaled_3810(float s)
{
    return randf_3810() * s;
}

extern "C" void func_002F3810(char* self)
{
    float acc = *(float*)(self + 0x1024);
    int n = (int)acc;
    *(float*)(self + 0x1024) = acc - (float)n;
    while (n > 0) {
        sVec2_3810 pos;
        pos.x = randScaled_3810(640.0f);
        pos.y = randScaled_3810(480.0f);
        if (randf_3810() < D_004A425C) {
            int k = D_004A4264 + BXrand() % (unsigned int)(D_004A4268 - D_004A4264);
            if (k <= 0)
                k = 1;
            n -= k;
            func_002F3640_3810(self, &pos, k);
        } else {
            sVec2_3810 v;
            v.x = D_004A4298;
            v.y = D_004A4298;
            func_002F37A8(self, &pos, &v);
            n--;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F39C8);
#ifdef SKIP_ASM
extern "C" void func_002F39C8(void *arg0) {
    *(int *)((char*)arg0 + 0x100C) = 0;
    *(int *)((char*)arg0 + 0x1024) = 0;
    *(int *)((char*)arg0 + 0x14) = 0;
    *(int *)((char*)arg0 + 0x18) = 0;
    *(int *)((char*)arg0 + 0x1028) = 0;
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F39E0);

INCLUDE_ASM("seg/seg_1F1548", func_002F3E28);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F4118);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void *func_002306A8(void *, int);
extern "C" void func_002F4260_4118(void *, float, void *) __asm__("func_002F4260");
extern void *D_004A28A8;
struct N4118 { char pad[0x84]; N4118 *c; };
struct M4118 { char pad[0x10]; unsigned int cnt; };

extern "C" void func_002F4118(void *arg0, float arg1) {
    unsigned int i = 0;
    if (((M4118 *)((N4118 *)((N4118 *)D_004A28A8)->c)->c)->cnt != 0) {
        do {
            func_002F4260_4118(func_002306A8(((N4118 *)D_004A28A8)->c, i++), arg1, arg0);
        } while (i < ((M4118 *)((N4118 *)((N4118 *)D_004A28A8)->c)->c)->cnt);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F41A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Base41A8 { int pad[3]; };
struct Obj41A8 : Base41A8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
};
Obj41A8 *func_002306A8_41A8(void *, int) __asm__("func_002306A8__FPvi");
extern void *D_004A28A8;
#define F84(p) (*(char **)((char*)(p) + 0x84))

extern "C" void func_002F41A8(int arg0) {
    unsigned int i = 0;
    if (*(unsigned int *)(F84(F84(D_004A28A8)) + 0x10) != 0) {
        do {
            char *t5 = F84(D_004A28A8);
            if (arg0 == *(int *)(F84(t5) + (i << 2) + 4)) {
                if (func_002306A8_41A8(t5, i) != 0) {
                    Obj41A8 *o = func_002306A8_41A8(F84(D_004A28A8), i);
                    o->v13();
                }
            }
            i += 1;
        } while (i < *(unsigned int *)(F84(F84(D_004A28A8)) + 0x10));
    }
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F4260);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F4330);
#ifdef SKIP_ASM
extern float D_004A4280;
extern float D_004A4284;

extern "C" void func_002F4330(void *arg0, float arg1) {
    *(float *)((char*)arg0 + 0x1028) = arg1;
    if (D_004A4280 < arg1) {
        *(float *)((char*)arg0 + 0x1024) += arg1 * (*(float *)((char*)arg0 + 0x1020) + 10.0f) * (D_004A4284 * 0.007692307699471712f);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F4380);
#ifdef SKIP_ASM
extern void func_002E2860(void *);
extern "C" void func_002F43E0(void *);
inline void* operator new[](unsigned int, void* p) { return p; }
struct Elem4380 { Elem4380() {} };

extern "C" void *func_002F4380(void *arg0) {
    func_002E2860(arg0);
    new ((char*)arg0 + 0x40) Elem4380[16];
    *(int *)((char*)arg0 + 0x204) = 0;
    *(short *)((char*)arg0 + 0x2E) = 0;
    *(short *)((char*)arg0 + 0x2C) = 0;
    func_002F43E0(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F43E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sCol_43E0 {
    float r, g, b, a;
};

extern sCol_43E0 D_004FAB80;
extern sCol_43E0 D_004FABA0;
extern sCol_43E0 D_004FABC0;
extern sCol_43E0 D_004FABE0;
extern sCol_43E0 D_004FAC00;
extern sCol_43E0 D_004FAC20;
extern sCol_43E0 D_004FAC40;
extern sCol_43E0 D_004FAC60;
extern sCol_43E0 D_004FAC80;

struct sLight_43E0 {
    int type;
    float a;
    float b;
    sCol_43E0 col;
};

struct sLightSet_43E0 {
    char pad[0x30];
    sLight_43E0 lights[16];
    char pad1F0[0x10];
    int count;
};

extern "C" void func_002F43E0_43E0(sLightSet_43E0* self) __asm__("func_002F43E0");
extern "C" void func_002F43E0_43E0(sLightSet_43E0* self)
{
    self->count = 0;
    self->lights[0].type = 1;
    self->lights[0].a = 1.2999999523162842f;
    self->lights[0].b = 0.03999999910593033f;
    self->lights[0].col = D_004FAB80;
    self->count++;
    self->lights[1].type = 3;
    self->lights[1].a = 0.595413327217102f;
    self->lights[1].b = 0.03453768044710159f;
    self->lights[1].col = D_004FABA0;
    self->count++;
    self->lights[2].type = 0;
    self->lights[2].a = 0.5f;
    self->lights[2].b = 0.20000000298023224f;
    self->lights[2].col = D_004FABC0;
    self->count++;
    self->lights[3].type = 2;
    self->lights[3].a = 0.20000000298023224f;
    self->lights[3].b = 0.025077050551772118f;
    self->lights[3].col = D_004FABE0;
    self->count++;
    self->lights[4].type = 0;
    self->lights[4].a = 0.0f;
    self->lights[4].b = 0.03999999910593033f;
    self->lights[4].col = D_004FAC00;
    self->count++;
    self->lights[5].type = 0;
    self->lights[5].a = -0.5141515731811523f;
    self->lights[5].b = 0.06998095661401749f;
    self->lights[5].col = D_004FAC20;
    self->count++;
    self->lights[6].type = 1;
    self->lights[6].a = -0.40145567059516907f;
    self->lights[6].b = 0.030118949711322784f;
    self->lights[6].col = D_004FAC40;
    self->count++;
    self->lights[7].type = 3;
    self->lights[7].a = -0.6160849332809448f;
    self->lights[7].b = 0.03999999910593033f;
    self->lights[7].col = D_004FAC60;
    self->count++;
    self->lights[8].type = 1;
    self->lights[8].a = -1.0f;
    self->lights[8].b = 0.0206892192363739f;
    self->lights[8].col = D_004FAC80;
    self->count++;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F4690);
#ifdef SKIP_ASM
extern "C" float func_002EE268(int);

struct sV2_4690 {
    float x, y;
    sV2_4690() {}
    sV2_4690(const float& ax, const float& ay) : x(ax), y(ay) {}
};

static inline sV2_4690 operator-(const sV2_4690& a, const sV2_4690& b)
{
    return sV2_4690(a.x - b.x, a.y - b.y);
}

static inline sV2_4690 operator+(const sV2_4690& a, const sV2_4690& b)
{
    return sV2_4690(a.x + b.x, a.y + b.y);
}

static inline sV2_4690 operator*(const sV2_4690& a, float s)
{
    return sV2_4690(a.x * s, a.y * s);
}

struct sV4_4690 {
    float x, y, z, w;
    sV4_4690(const float& ax, const float& ay, const float& az, const float& aw) : x(ax), y(ay), z(az), w(aw) {}
};

struct sCol_4690 {
    float r, g, b, a;
};

struct sLight_4690 {
    int type;
    float dist;
    float size;
    sCol_4690 col;
};

struct sFlare_4690 {
    char pad[0x30];
    sLight_4690 lights[16];
    float sunX;
    float sunY;
    char pad1F8[0x8];
    int count;
    float intensity;
};

struct sGs_4690 {
    unsigned int w0, w4, w8, wC;
    unsigned int f10 : 16;
    unsigned int f10hi : 16;
    void SetF10(int v) { f10 = v; }
};

class cWorld_4690 {
public:
    char pad[0xE84];
    sGs_4690* stateTop;
    char padE88[0x1004 - 0xE88];
    int f1004;
    int GetF1004() { return f1004; }
    char pad1008[0x10D8 - 0x1008];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62();
    virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
    virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76();
    virtual void DrawSprite(const sV4_4690&, const sV2_4690&, const sV2_4690&, const sV2_4690&, const sCol_4690&);
};

extern char* D_004A289C;

extern "C" void func_002F4690(sFlare_4690* self)
{
    float cx = (float)((cWorld_4690*)D_004A289C)->GetWidth() * 0.5f;
    float cy = (float)((cWorld_4690*)D_004A289C)->GetHeight() * 0.5f;
    sV2_4690 center(cx, cy);
    sV2_4690 sun(self->sunX, self->sunY);
    sV2_4690 dir = sun - center;
    cWorld_4690* w = (cWorld_4690*)D_004A289C;
    w->stateTop->SetF10(w->GetF1004());
    for (int i = 0; i < self->count; i++) {
        sV2_4690 pos = center + dir * self->lights[i].dist;
        sV2_4690 uv0;
        sCol_4690 col = self->lights[i].col;
        col.r *= self->intensity * func_002EE268(6);
        sV2_4690 uv1;
        switch (self->lights[i].type) {
        case 0:
            uv0 = sV2_4690(0.0f, 0.0f);
            uv1 = sV2_4690(0.5f, 0.5f);
            break;
        case 1:
            uv0 = sV2_4690(0.5f, 0.0f);
            uv1 = sV2_4690(1.0f, 0.5f);
            break;
        case 2:
            uv0 = sV2_4690(0.0f, 0.5f);
            uv1 = sV2_4690(0.5f, 1.0f);
            break;
        case 3:
            uv0 = sV2_4690(0.5f, 0.5f);
            uv1 = sV2_4690(1.0f, 1.0f);
            break;
        default:
            uv0 = sV2_4690(0.0f, 0.0f);
            uv1 = sV2_4690(0.5f, 1.0f);
            break;
        }
        float s = self->lights[i].size * 300.0f;
        sV2_4690 sz(s, s);
        ((cWorld_4690*)D_004A289C)->DrawSprite(sV4_4690(pos.x, pos.y, 0.0f, 1.0f), sz, uv0, uv1, col);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F4A08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" float func_002EE100(int);
extern "C" float func_002EE148(int);
extern "C" float func_002EE190(int);
extern "C" float func_002EE1D8(int);
extern "C" int func_002EE220(int);
extern "C" float func_002EE2B0(int);
extern "C" void func_002F4690_4A08(void*, void*) __asm__("func_002F4690");
extern char D_004FF1A0[];

struct sV2_4A08 {
    float x, y;
    sV2_4A08(const float& ax, const float& ay) : x(ax), y(ay) {}
};

struct sV4_4A08 {
    float x, y, z, w;
    sV4_4A08() {}
    sV4_4A08(const float& ax, const float& ay, const float& az, const float& aw) : x(ax), y(ay), z(az), w(aw) {}
};

struct sGsState_4A08 {
    unsigned int w0;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 5;
    unsigned int f4_12 : 8;
    unsigned int f4_20 : 2;
    unsigned int f4_22 : 1;
    unsigned int f4_23 : 2;
    unsigned int f4_25 : 7;
    unsigned int f8_0 : 5;
    unsigned int f8_5 : 5;
    unsigned int f8_10 : 19;
    unsigned int f8_29 : 3;
    unsigned int wC;
    unsigned int f10 : 16;
    unsigned int f10hi : 16;
    void SetF22(int v) { f4_22 = v; }
};

extern sGsState_4A08 D_00501420_4A08 __asm__("D_00501420");

class cGfx_4A08 {
public:
    char pad[0xE84];
    sGsState_4A08* stateTop;
    char padE88[0xF50 - 0xE88];
    int texTab[(0x10D8 - 0xF50) / 4];
    int GetTexId(int i) { return texTab[i + 0x33]; }
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void BeginScene();
    virtual void EndScene();
    virtual void v22(); virtual void v23(); virtual void v24();
    virtual void SetViewport(float, float, float, float, int, int, float, float);
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void Begin2D();
    virtual void End2D();
    virtual void v32();
    virtual void SetTexture(void*);
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76();
    virtual void DrawSprite(const sV4_4A08&, const sV2_4A08&, const sV2_4A08&, const sV2_4A08&, const sV4_4A08&);
};

extern cGfx_4A08* D_004A5B80_4A08 __asm__("D_004A5B80");

struct sSun_4A08 {
    char pad[0x2C];
    unsigned short visible;
    char pad2E[0x1F0 - 0x2E];
    float sunX;
    float sunY;
    char pad1F8[0x204 - 0x1F8];
    float intensity;
};

extern "C" void func_002F4A08(sSun_4A08* self, sV4_4A08* vp, int flag)
{
    if (self->visible == 0)
        return;
    int id = !flag ? 6 : 7;
    float r = func_002EE100(id);
    float g = func_002EE148(id);
    float b = func_002EE190(id);
    sV4_4A08 col;
    col = sV4_4A08(1.0f, r, g, b);
    col.x *= self->intensity * func_002EE1D8(id);
    float size = func_002EE2B0(id);
    int tex = func_002EE220(id);
    if (size == 1.0f)
        size = 320.0f;
    if (col.x <= 0.0f)
        return;
    cGfx_4A08* gfx = D_004A5B80_4A08;
    gfx->stateTop[1] = gfx->stateTop[0];
    gfx->stateTop++;
    *gfx->stateTop = D_00501420_4A08;
    gfx->BeginScene();
    gfx->SetViewport(vp->x, vp->y, vp->z, vp->w, 1, 0, 0.0f, 1.0f);
    gfx->Begin2D();
    gfx->SetTexture(D_004FF1A0);
    gfx->stateTop->SetF22(1);
    gfx->stateTop->f4_23 = 2;
    gfx->stateTop->f4_20 = 0;
    gfx->stateTop->f4_12 = 0x14;
    gfx->stateTop->f4_0 = 0;
    gfx->stateTop->f8_10 = 0;
    gfx->stateTop->f4_2 = 7;
    gfx->stateTop->f8_5 = 8;
    gfx->stateTop->f10 = gfx->GetTexId(tex);
    sV4_4A08 pos(self->sunX, self->sunY, 0.0f, 1.0f);
    gfx->DrawSprite(pos, sV2_4A08(size, size),
                    sV2_4A08(0.0f, 0.0f), sV2_4A08(1.0f, 1.0f), col);
    func_002F4690_4A08(self, vp);
    gfx->stateTop--;
    gfx->End2D();
    gfx->EndScene();
}
#endif

INCLUDE_ASM("seg/seg_1F1548", func_002F4DB8);

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F5148);
#ifdef SKIP_ASM
extern "C" void func_002F5400(int, void *, int);
extern void *D_004A28A8;

extern "C" void func_002F5148(void *arg0) {
    func_002F5400((*(int *)((char*)((*(void **)((char*)(D_004A28A8) + (0x84)))) + (0x90))), arg0, ((int) (*(int *)((char*)(arg0) + (8))) >> 0xC) & 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F5180);
#ifdef SKIP_ASM
extern "C" void cWorldLightMan_initLightCache(void *);
struct cWorldPainterManArg;
void *cWorldPainterMan_getQuery(void *, cWorldPainterManArg *);
extern char D_004A5598;
extern void *D_004A28A8;
struct A5180 { unsigned int v; char pad[0x3C]; A5180() { v = 0xFFFFFFFF; } };
struct B5180 { unsigned int v; char pad[0x17C]; B5180() { v = 0xFFFFFFFF; } };

extern "C" void *func_002F5180(void *arg0, int arg1) {
    new ((char*)arg0 + 0x10) A5180[8];
    new ((char*)arg0 + 0x210) B5180[32];
    *(int *)arg0 = arg1;
    cWorldLightMan_initLightCache(arg0);
    char *t = *(char **)(*(char **)((char*)D_004A28A8 + 0x84) + 0x10);
    *(void **)((char*)arg0 + 4) = cWorldPainterMan_getQuery(*(void **)(t + 8), (cWorldPainterManArg *)&D_004A5598);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1F1548", func_002F5230);
#ifdef SKIP_ASM
extern "C" void func_002F53B0(void *);
void operator_delete(int *);
struct Base5230 { int pad; };
struct Inner5230 : Base5230 { virtual ~Inner5230(); };
struct Outer5230 { int pad; Inner5230 *p; };

extern "C" void func_002F5230(Outer5230 *arg0, int arg1) {
    if (arg0->p != 0) {
        delete arg0->p;
    }
    func_002F53B0(arg0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif
