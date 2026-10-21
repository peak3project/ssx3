#include "common.h"

//100%
INCLUDE_ASM("main/loadscreens_prestart", cPreStartScreen_update);
#ifdef SKIP_ASM
struct cAppMan;
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_00231F80(void* fade);
extern "C" int func_00326CA0(void* pads, int port);
extern "C" char* func_00326CC8(void* pads, int port);
extern void* D_004A28A8;
extern char* D_004A28A0;
extern char D_0047B8C8[];
extern void* D_0047D8F0[];

struct sModule_232348 {
    void** vt;
    int f4;
    int f8;
};

struct sPreStart_232348 {
    int f0;
    float t;
    sModule_232348* next;
};

extern "C" void cPreStartScreen_update(sPreStart_232348* self)
{
    func_00231F80(*(void**)((char*)D_004A28A8 + 0xA4));
    float* f = (float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4);
    *f += 0.0833333358168602f;
    if (*f > 1.0f) {
        *f = 1.0f;
    }
    if (*(int*)((char*)D_004A28A8 + 4) == 0) {
        sModule_232348* m = (sModule_232348*)cMemMan_alloc(0xC, D_0047B8C8, 0x100, 0);
        cAppMan* app = (cAppMan*)D_004A28A8;
        m->vt = D_0047D8F0;
        m->f4 = 0;
        m->f8 = 0;
        self->next = m;
        // PORT: setNextModule takes the module pointer as an unsigned int
        cAppMan_setNextModule(app, (unsigned int)m);
    }
    self->t += 0.01666666753590107f;
    if (*(int*)(D_004A28A0 + 0x2EE8) > 0) {
        self->t += 0.15000000596046448f;
        if (func_00326CA0(D_004A28A0, 0) >= 11) {
            if (*(float*)(func_00326CC8(D_004A28A0, 0) + 0x20) != 0.0f && *(float*)(func_00326CC8(D_004A28A0, 0) + 0x28) != 0.0f) {
                self->next->f4 = 1;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232488);
#ifdef SKIP_ASM
struct sVec3_232488 {
    float x, y, z;
    sVec3_232488(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
class cWorld232488 {
public:
    char pad[0x10D8];
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
    virtual void v15(const sVec3_232488&);
    virtual void v16();
    virtual int v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
};
extern "C" void func_00231FC0(void* a);
extern void* D_004A289C;
extern void* D_004A28A8;

extern "C" int func_00232488(void)
{
    if (((cWorld232488*)D_004A289C)->v17() == 0) {
        return 0;
    }
    ((cWorld232488*)D_004A289C)->v15(sVec3_232488(0.0f, 0.0f, 0.0f));
    func_00231FC0(*(void**)((char*)D_004A28A8 + 0xA4));
    ((cWorld232488*)D_004A289C)->v20();
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232510);
#ifdef SKIP_ASM
extern "C" int func_00232510(void* self)
{
    if (*(float*)((char*)self + 0x4) < 0.75f) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232538);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046D970[];

extern "C" void func_00232538(void* self, int flags)
{
    *(void***)self = D_0046D970;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232568);
#ifdef SKIP_ASM
extern "C" void cSSXApp_initload(void* app);
extern void* D_004A28A8;

extern "C" void func_00232568(void)
{
    cSSXApp_initload(D_004A28A8);
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232588);
#ifdef SKIP_ASM
struct cAppMan;
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_00231F80(void* fade);
extern "C" void* func_00232AE0(void* self, int arg);
extern void* D_004A28A8;
extern char D_0047B8D8[];

extern "C" void func_00232588(void* self)
{
    func_00231F80(*(void**)((char*)D_004A28A8 + 0xA4));
    if (*(int*)((char*)self + 8) != 0) {
        float* f = (float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4);
        *f -= 0.0833333358168602f;
        if (*f < 0.0f) {
            *f = 0.0f;
        }
    } else {
        float* f = (float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4);
        *f += 0.0833333358168602f;
        if (*f > 1.0f) {
            *f = 1.0f;
        }
    }
    if (*(int*)((char*)D_004A28A8 + 4) == 0) {
        cAppMan_setNextModule((cAppMan*)D_004A28A8,
            (unsigned int)func_00232AE0(cMemMan_alloc(0x1C, D_0047B8D8, 0x100, 0), *(int*)((char*)self + 4) ? 2 : 0));
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232650);
#ifdef SKIP_ASM
struct sVec3_232650 {
    float x, y, z;
    sVec3_232650(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
class cWorld232650 {
public:
    char pad[0x10D8];
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
    virtual void v15(const sVec3_232650&);
    virtual void v16();
    virtual int v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
};
extern "C" void func_00231FC0(void* a);
extern void* D_004A289C;
extern void* D_004A28A8;

extern "C" int func_00232650(void)
{
    if (((cWorld232650*)D_004A289C)->v17() == 0) {
        return 0;
    }
    ((cWorld232650*)D_004A289C)->v15(sVec3_232650(0.0f, 0.0f, 0.0f));
    func_00231FC0(*(void**)((char*)D_004A28A8 + 0xA4));
    ((cWorld232650*)D_004A289C)->v20();
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_002326D8);
#ifdef SKIP_ASM
struct sLoadScreen2326D8 {
    int f0;
    int f4;
    int done;
};
extern void* D_004A28A8;

extern "C" int func_002326D8(sLoadScreen2326D8* self)
{
    self->done = 1;
    return *(float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4) == 0.0f;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232710__FPv);
#ifdef SKIP_ASM
void func_00232710(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232718__FPv);
#ifdef SKIP_ASM
void func_00232718(void* self)
{
}
#endif

extern void* D_0047D8A8[];

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232720__FPv);
#ifdef SKIP_ASM
void* func_00232720(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    *(int*)self = (int)(void*)D_0047D8A8;
    return self;
}
#endif

extern void* D_0047D860[];

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232738__FPv);
#ifdef SKIP_ASM
void* func_00232738(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    *(int*)self = (int)(void*)D_0047D860;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232750);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046D970[];

extern "C" void func_00232750(void* self, int flags)
{
    *(void***)self = D_0046D970;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232780);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046D970[];

extern "C" void func_00232780(void* self, int flags)
{
    *(void***)self = D_0046D970;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_002327B0);
#ifdef SKIP_ASM
struct sLoadScreen2327B0 {
    int f0;
    int done;
};
extern void* D_004A28A8;

extern "C" int func_002327B0(sLoadScreen2327B0* self)
{
    self->done = 1;
    return *(float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4) == 0.0f;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_002327E8);
#ifdef SKIP_ASM
struct sLoadScreen2327E8 {
    int f0;
    int done;
};
extern void* D_004A28A8;

extern "C" int func_002327E8(sLoadScreen2327E8* self)
{
    self->done = 1;
    return *(float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4) == 0.0f;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232820);
#ifdef SKIP_ASM
struct sVec3_232820 {
    float x, y, z;
    sVec3_232820(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
class cWorld232820 {
public:
    char pad[0x10D8];
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
    virtual void v15(const sVec3_232820&);
    virtual void v16();
    virtual int v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
};
extern "C" void func_00231FC0(void* a);
extern void* D_004A289C;
extern void* D_004A28A8;

extern "C" int func_00232820(void)
{
    if (((cWorld232820*)D_004A289C)->v17() == 0) {
        return 0;
    }
    ((cWorld232820*)D_004A289C)->v15(sVec3_232820(0.0f, 0.0f, 0.0f));
    func_00231FC0(*(void**)((char*)D_004A28A8 + 0xA4));
    ((cWorld232820*)D_004A289C)->v20();
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_002328A8);
#ifdef SKIP_ASM
struct sVec3_2328A8 {
    float x, y, z;
    sVec3_2328A8(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
class cWorld2328A8 {
public:
    char pad[0x10D8];
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
    virtual void v15(const sVec3_2328A8&);
    virtual void v16();
    virtual int v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
};
extern "C" void func_00231FC0(void* a);
extern void* D_004A289C;
extern void* D_004A28A8;

extern "C" int func_002328A8(void)
{
    if (((cWorld2328A8*)D_004A289C)->v17() == 0) {
        return 0;
    }
    ((cWorld2328A8*)D_004A289C)->v15(sVec3_2328A8(0.0f, 0.0f, 0.0f));
    func_00231FC0(*(void**)((char*)D_004A28A8 + 0xA4));
    ((cWorld2328A8*)D_004A289C)->v20();
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232930);
#ifdef SKIP_ASM
struct cAppMan;
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_00231F80(void* fade);
extern "C" int func_00231CD0_r(void* self) __asm__("func_00231CD0");
extern void* D_004A28A8;
extern char D_0047B8E8[];
extern void* D_0047D788[];

struct sModule_232930 {
    void** vt;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
};

// Matches only with exceptions enabled for this unit (UNIT_CFLAGS "-fexceptions" in configure.py).
// `tmp` is reused for the fade direction and the module handle: one variable spanning both blocks is what
// gives the retail register allocation (the handle is taken before the fields are filled in).
extern "C" void func_00232930(void* self)
{
    int tmp;
    func_00231F80(*(void**)((char*)D_004A28A8 + 0xA4));
    tmp = *(int*)((char*)self + 4) != 0;
    if (tmp) {
        float* f = (float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4);
        *f -= 0.0833333358168602f;
        if (*f < 0.0f) {
            *f = 0.0f;
        }
    } else {
        float* f = (float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4);
        *f += 0.0833333358168602f;
        if (*f > 1.0f) {
            *f = 1.0f;
        }
    }
    if (*(int*)((char*)D_004A28A8 + 4) == 0) {
        sModule_232930* m = (sModule_232930*)cMemMan_alloc(0x18, D_0047B8E8, 0x100, 0);
        func_00231CD0_r(m);
        tmp = (unsigned int)m;
        m->vt = D_0047D788;
        m->fC = 0;
        m->f10 = 0;
        m->f14 = 0;
        cAppMan_setNextModule((cAppMan*)D_004A28A8, tmp);
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", cPreFELoadScreen_update);
#ifdef SKIP_ASM
extern char D_004A2AB8[];
extern void* D_0047D740[];

struct sModule_232A00 {
    void** vt;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
};

// Same shape as func_00232930 (see the note there): exceptions enabled for this unit, `tmp` reused.
extern "C" void cPreFELoadScreen_update(void* self)
{
    int tmp;
    func_00231F80(*(void**)((char*)D_004A28A8 + 0xA4));
    tmp = *(int*)((char*)self + 4) != 0;
    if (tmp) {
        float* f = (float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4);
        *f -= 0.0833333358168602f;
        if (*f < 0.0f) {
            *f = 0.0f;
        }
    } else {
        float* f = (float*)(*(char**)((char*)D_004A28A8 + 0xA4) + 4);
        *f += 0.0833333358168602f;
        if (*f > 1.0f) {
            *f = 1.0f;
        }
    }
    if (*(int*)((char*)D_004A28A8 + 4) == 0) {
        sModule_232A00* m = (sModule_232A00*)cMemMan_alloc(0x1C, D_004A2AB8, 0x100, 0);
        func_00231CD0_r(m);
        tmp = (unsigned int)m;
        m->vt = D_0047D740;
        m->fC = 0;
        m->f10 = 0;
        m->f14 = 0;
        cAppMan_setNextModule((cAppMan*)D_004A28A8, tmp);
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232AE0);
#ifdef SKIP_ASM
extern "C" void func_00231CD0(void* self);
extern void* D_0047D7D0[];

extern "C" void* func_00232AE0(void* self, int arg)
{
    func_00231CD0(self);
    *(void***)self = D_0047D7D0;
    *(int*)((char*)self + 0x18) = arg;
    *(int*)((char*)self + 0xC) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232B28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cWorld_232B28 {
public:
    char pad[0x10D8];
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
    virtual void v44(int);
};

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// malloc-like allocation (gcc treats operator new results as unaliased)
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* func_00397B08(void* p);
extern "C" int cUIEngine_loadFile(void* ui, const char* name);
extern "C" void* func_00186A08(void* p, void* ui);
extern "C" void* func_0039E2A0(void* self, void* engine);
extern "C" void func_0039F400(void* list, void* item);
extern void* D_004A289C;
extern void* D_004A28A8;
extern char D_0047B698[];
extern char D_0047B9E0[];
extern char D_0047B9F0[];
extern char D_0047B978[];
extern char D_0047BA00[];
extern char D_0046D1D0[];
extern char D_0047CA18[];

struct sNode_232B28 {
    int f0;
    char f4;
    void* f8;
    int fC;
    int f10;
    int f14;
    int f18;
};

struct sUI_232B28 {
    int f0;
    int f4;
    int f8;
    sNode_232B28* fC;
    int f10;
    int f14;
    char list[4];
};

extern "C" void func_00232B28(void* self)
{
    ((cWorld_232B28*)D_004A289C)->v44(0x100);
    void* ui = func_00397B08(operator new(0x70, D_0047B698, 0x100, 0));
    *(void**)((char*)self + 0xC) = ui;
    cUIEngine_loadFile(ui, D_0047B9E0);
    (*(sUI_232B28**)((char*)self + 0xC))->f10 = *(int*)((char*)D_004A28A8 + 0x8C);
    sNode_232B28* n = (sNode_232B28*)operator new(0x1C, D_0047B9F0, 0x100, 0);
    n->f4 = 0;
    n->f8 = D_0046D1D0;
    n->f18 = 0;
    n->fC = 0;
    n->f10 = 0;
    n->f14 = 0;
    (*(sUI_232B28**)((char*)self + 0xC))->fC = n;
    (*(sUI_232B28**)((char*)self + 0xC))->f8 = *(int*)((char*)D_004A28A8 + 0x88);
    int mode = *(int*)((char*)self + 0x18);
    if (mode == 0) {
        void* item = func_00186A08(operator new(0x248, D_0047B978, 0, 0), *(void**)((char*)self + 0xC));
        func_0039F400(*(char**)((char*)self + 0xC) + 0x18, item);
    } else if (mode == 2) {
        void* p = operator new(0x48, D_0047BA00, 0, 0);
        func_0039E2A0(p, *(void**)((char*)self + 0xC));
        *(void**)((char*)p + 8) = D_0047CA18;
        func_0039F400(*(char**)((char*)self + 0xC) + 0x18, p);
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232C98);
#ifdef SKIP_ASM
extern int D_004A4324;
extern int D_004A45D8;
extern int D_004A43C8;
extern "C" void func_00369FF8(void* g);

struct sVec3i_2C98 {
    int x, y, z;
    sVec3i_2C98(int a, int b, int c) { x = a; y = b; z = c; }
};

struct sVE_2C98 {
    short delta;
    short index;
    void (*fn)(void*, sVec3i_2C98);
};

// Clearing through a pointer keeps the stores ahead of the reload of D_004A289C.
static inline void clear_2C98(int* p)
{
    *p = 0;
}

extern "C" void func_00232C98(void* self)
{
    func_00369FF8(D_004A289C);
    *(int*)((char*)self + 0x14) = 0;
    clear_2C98(&D_004A4324);
    clear_2C98(&D_004A45D8);
    clear_2C98(&D_004A43C8);
    char* g = (char*)D_004A289C;
    sVE_2C98* vt = *(sVE_2C98**)(g + 0x10D8);
    vt[15].fn(g + vt[15].delta, sVec3i_2C98(0, 0, 0));
}
#endif

extern "C" void* func_00231CF0(void* self);

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232CF8__FPv);
#ifdef SKIP_ASM
void* func_00232CF8(void* self)
{
    return func_00231CF0(self);
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232D18);
#ifdef SKIP_ASM
void func_00231CB0(void*);
extern "C" void func_00398038(void*);

extern "C" void func_00232D18(void* self)
{
    func_00231CB0(self);
    func_00398038(*(void**)((char*)self + 0xC));
    (*(int*)((char*)self + 0x14))++;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232D50);
#ifdef SKIP_ASM
class cWorld232D50 {
public:
    char pad[0x10D8];
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
};
extern "C" void func_00397B70(void* obj, int a);
extern "C" void func_0036A020(void* world);
extern void* D_004A289C;

extern "C" void func_00232D50(void* self)
{
    ((cWorld232D50*)D_004A289C)->v19();
    void* p = *(void**)((char*)self + 0xC);
    if (p != 0) {
        func_00397B70(p, 3);
    }
    *(void**)((char*)self + 0xC) = 0;
    func_0036A020(D_004A289C);
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232DA8);
#ifdef SKIP_ASM
class cWorld232DA8 {
public:
    char pad[0x10D8];
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
    virtual int v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
};
extern "C" int func_00231D60(void* self);
extern "C" void func_00397DF8(void* obj);
extern void* D_004A289C;

extern "C" int func_00232DA8(void* self)
{
    if (((cWorld232DA8*)D_004A289C)->v17() == 0) {
        return 0;
    }
    if (func_00231D60(self) == 0) {
        func_00397DF8(*(void**)((char*)self + 0xC));
    }
    ((cWorld232DA8*)D_004A289C)->v20();
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00232E20);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// malloc-like allocation (gcc treats operator new results as unaliased)
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* func_00397B08(void* p);
extern "C" int cUIEngine_loadFile(void* ui, const char* name);
extern "C" void* func_0039E2A0(void* self, void* engine);
extern "C" void func_0039F400(void* list, void* item);
// PORT: cGameLoadScreen_loadTexture takes (self) but this caller passes (self, 0).
extern "C" void cGameLoadScreen_loadTexture_2E20(void* self, int a1) __asm__("cGameLoadScreen_loadTexture");
extern void* D_004A289C;
extern void* D_004A28A8;
extern int D_004A19D8;
extern int D_004A19DC;
extern char D_00535BC8[];
extern char D_0047B698[];
extern char D_0047BD28[];
extern char D_0047B9F0[];
extern char D_0047BD38[];
extern char D_0047BD50[];
extern char D_0047BD68[];
extern char D_0046D1D0[];
extern char D_0047C878[];
extern char D_0047C7A8[];
extern char D_0047C948[];

struct sVE_2E20 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sNode_2E20 {
    int f0;
    char f4;
    void* f8;
    int fC;
    int f10;
    int f14;
    int f18;
};

struct sUI_2E20 {
    int f0;
    int f4;
    int f8;
    sNode_2E20* fC;
    int f10;
    int f14;
    char list[4];
};

struct cLoadItemA_2E20 {
    char pad[0x48];
    cLoadItemA_2E20(void* ui)
    {
        func_0039E2A0(this, ui);
        *(void**)(pad + 8) = D_0047C878;
        D_004A19D8 = 0;
    }
};

struct cLoadItemB_2E20 {
    char pad[0x48];
    cLoadItemB_2E20(void* ui)
    {
        func_0039E2A0(this, ui);
        *(void**)(pad + 8) = D_0047C7A8;
        D_004A19DC = 0;
    }
};

struct cLoadItemC_2E20 {
    char pad[0x48];
    void* owner;    // 0x48
    cLoadItemC_2E20(void* ui)
    {
        func_0039E2A0(this, ui);
        *(void**)(pad + 8) = D_0047C948;
        owner = 0;
    }
};

extern "C" void func_00232E20(void* self)
{
    char* w = (char*)D_004A289C;
    sVE_2E20* vt = *(sVE_2E20**)(w + 0x10D8);
    vt[44].fn(w + vt[44].delta, 0x100);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* ui = func_00397B08(operator new(0x70, D_0047B698, 0x100, 0));
    *(void**)((char*)self + 0xC) = ui;
    cUIEngine_loadFile(ui, D_0047BD28);
    (*(sUI_2E20**)((char*)self + 0xC))->f8 = *(int*)((char*)D_004A28A8 + 0x88);
    (*(sUI_2E20**)((char*)self + 0xC))->f10 = *(int*)((char*)D_004A28A8 + 0x8C);
    sNode_2E20* n = (sNode_2E20*)operator new(0x1C, D_0047B9F0, 0x100, 0);
    n->f4 = 0;
    n->f8 = D_0046D1D0;
    n->f18 = 0;
    n->fC = 0;
    n->f10 = 0;
    n->f14 = 0;
    (*(sUI_2E20**)((char*)self + 0xC))->fC = n;
    void* item;
    if (D_004A19D8 == 0) {
        signed char* g = (signed char*)D_00535BC8;
        if (g[0x49] != 0)
            goto other;
        if (g[0x48] == 5)
            goto makeA;
        if (g[0x48] != 6)
            goto other;
    }
makeA:
    item = new (D_0047BD38, 0, 0) cLoadItemA_2E20(*(void**)((char*)self + 0xC));
    goto done;
other:
    {
        signed char* g2 = (signed char*)D_00535BC8;
        int x = 0;
        if (g2[0x49] == 0) {
            int t = g2[0x48] != 5;
            if (t)
                x = g2[0x48] != 6;
        }
        if (x) {
            item = new (D_0047BD50, 0, 0) cLoadItemB_2E20(*(void**)((char*)self + 0xC));
        } else {
            cLoadItemC_2E20* c = new (D_0047BD68, 0, 0) cLoadItemC_2E20(*(void**)((char*)self + 0xC));
            item = c;
            c->owner = self;
            cGameLoadScreen_loadTexture_2E20(self, 0);
        }
    }
done:
    func_0039F400(*(char**)((char*)self + 0xC) + 0x18, item);
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", cGameLoadScreen_loadTexture);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getPlayerCharID(void* self, int idx);
struct cBigFile {
    int field_0x0;
    int field_0x4;
};
// PORT: cBigFile_cBigFile1 really takes (self, path, flags); bound by asm label.
cBigFile* cBigFile_cBigFile1_3048(cBigFile* self, const char* path, int flags) __asm__("cBigFile_cBigFile1__FP8cBigFile");
void cBigFile__cBigFile(cBigFile* self, int flags);
void cMemMan_free(void*);
extern "C" int func_00144BE0(void* self);
extern "C" char* func_003E2190(const char* name, int flags);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern signed char D_00535C11[];
extern char D_0047BD78[];
extern char D_0047BD90[];
extern char D_0047BDA0[];
extern char D_0047BDB0[];
extern char D_0047BDC8[];
extern char D_004A2C30[];
extern char* D_00442928[];
extern char* D_00442950[];
extern int D_004A2B3C;
extern char* D_004A289C_3048 __asm__("D_004A289C");

struct sVE_3048 {
    short delta;
    short index;
    int (*fn)(void*, void*, const char*, int, int, int);
};

static inline int loadTex_3048(char* data, const char* name)
{
    char* g = D_004A289C_3048;
    sVE_3048* vt = *(sVE_3048**)(g + 0x10D8);
    return vt[46].fn(g + vt[46].delta, data + *(int*)(data + 0x14), name, 0, 1, -1);
}

extern "C" void cGameLoadScreen_loadTexture(char* self)
{
    char name[0x70];
    cBigFile bf;
    void* plr = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* fe = cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        cBigFile_cBigFile1_3048(&bf, D_0047BD78, 0x100);
        int* slot = (int*)(self + 0x10);
        for (int i = 0; i < 2; i++) {
            sprintf(name, D_0047BD90, D_00442928[cBENewPlayerInterface_getPlayerCharID(plr, i != 0)], D_004A2B3C);
            char* data = func_003E2190(name, 0x3000100);
            *slot = loadTex_3048(data, D_0047BDA0);
            if (data != 0)
                cMemMan_free(data);
            slot++;
        }
        cBigFile__cBigFile(&bf, 2);
    } else {
        cBigFile_cBigFile1_3048(&bf, D_0047BDB0, 0x100);
        signed char n = func_00144BE0(fe);
        if (n > 16)
            n = 0;
        sprintf(name, D_004A2C30, D_00442950[n]);
        char* data = func_003E2190(name, 0x3000100);
        *(int*)(self + 0x10) = loadTex_3048(data, D_0047BDC8);
        if (data != 0)
            cMemMan_free(data);
        cBigFile__cBigFile(&bf, 2);
    }
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00233260);
#ifdef SKIP_ASM
extern void* D_004A289C;
extern void* D_004A28A8;
extern int D_004A4324;
extern "C" void func_00369FF8(void* g);
extern "C" void cSSXApp_startGameLoad(void* self);
extern "C" void* func_0028B180();
extern "C" void func_0028F768(void* snd);

struct sVec3i_3260 {
    int x, y, z;
    sVec3i_3260(int a, int b, int c) { x = a; y = b; z = c; }
};

struct sVE_3260 {
    short delta;
    short index;
    void (*fn)(void*, sVec3i_3260);
};

extern "C" void func_00233260(void)
{
    func_00369FF8(D_004A289C);
    cSSXApp_startGameLoad(D_004A28A8);
    // Storing through a pointer keeps the store ahead of the reload of D_004A289C.
    int* p = &D_004A4324;
    *p = 0;
    char* g = (char*)D_004A289C;
    sVE_3260* vt = *(sVE_3260**)(g + 0x10D8);
    vt[15].fn(g + vt[15].delta, sVec3i_3260(0, 0, 0));
    func_0028F768(func_0028B180());
}
#endif

extern "C" void* func_00231C70(void* self);

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_002332C8__FPv);
#ifdef SKIP_ASM
int func_002332C8(void* self)
{
    return (func_00231C70(self) != 0);
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_002332E8);
#ifdef SKIP_ASM
extern "C" void func_0036A020(void* world);
extern "C" void func_00397B70(void* obj, int a);
extern "C" void* func_0028B180(void);
extern "C" void func_0028FA98(void* self, float v);
extern void* D_004A289C;

class cWorld002332E8 {
public:
    char pad[0x10D8];
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
    virtual void v50(void* obj);
};

extern "C" void func_002332E8(void* self)
{
    ((cWorld002332E8*)D_004A289C)->v19();
    void* o = *(void**)((char*)self + 0xC);
    if (o != 0) {
        func_00397B70(o, 3);
    }
    int i;
    for (i = 0; i < 2; i++) {
        void* p = ((void**)((char*)self + 0x10))[i];
        if (p != 0) {
            ((cWorld002332E8*)D_004A289C)->v50(p);
        }
    }
    func_0036A020(D_004A289C);
    func_0028FA98(func_0028B180(), 1.0f);
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00233390);
#ifdef SKIP_ASM
class cWorld233390 {
public:
    char pad[0x10D8];
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
    virtual int v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
};
extern "C" int func_00231D60(void* self);
extern "C" void func_00397DF8(void* obj);
extern void* D_004A289C;

extern "C" int func_00233390(void* self)
{
    if (((cWorld233390*)D_004A289C)->v17() == 0) {
        return 0;
    }
    if (func_00231D60(self) == 0) {
        func_00397DF8(*(void**)((char*)self + 0xC));
    }
    ((cWorld233390*)D_004A289C)->v20();
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens_prestart", func_00233408);
#ifdef SKIP_ASM
extern "C" void func_00398038(void*);
void func_00231CB0(void*);

extern "C" void func_00233408(void* self)
{
    func_00398038(*(void**)((char*)self + 0xC));
    func_00231CB0(self);
}
#endif

