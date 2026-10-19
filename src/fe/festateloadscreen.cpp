#include "common.h"

//100%
INCLUDE_ASM("fe/festateloadscreen", cFELoadScreen_load);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_3438(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00397B08(void* mem);
extern "C" void cUIEngine_loadFile(void* engine, const char* name);
extern "C" void* func_0039E2A0(void* self, void* engine);
extern "C" void func_00233640(void* self, int type);
extern "C" void func_0039F400(void* list, void* screen);
extern void* D_004A289C;
extern void* D_004A28A8;
extern int D_004A19C4;
extern signed char D_00535C11[];
extern char D_0047B698[];
extern char D_0047BFB0[];
extern char D_0047BFC0[];
extern char D_0047BFD0[];
extern char D_0047BFE8[];
extern char D_0047C000[];
extern void* D_0046D1D0[];
extern void* D_0047C538[];
extern void* D_0047C6D8[];
extern void* D_0047C608[];

struct sVE_233438 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sEngine_233438 {
    char pad0[0x8];
    int f8;
    void* fC;
    int f10;
};

struct sObj_233438 {
    int f0;
    char f4;
    void** vt;
    int fC;
    int f10;
    int f14;
    int f18;
};

static inline char* newScreenA_233438(void* self)
{
    char* p = (char*)cMemMan_alloc(0x48, D_0047BFD0, 0, 0);
    func_0039E2A0(p, *(void**)((char*)self + 0xC));
    *(void***)(p + 8) = D_0047C538;
    return p;
}

static inline char* newScreenB_233438(void* self)
{
    char* p = (char*)cMemMan_alloc(0x4C, D_0047BFE8, 0, 0);
    func_0039E2A0(p, *(void**)((char*)self + 0xC));
    *(int*)(p + 0x48) = 0;
    *(void***)(p + 8) = D_0047C6D8;
    return p;
}

static inline char* newScreenC_233438(void* self)
{
    char* p = (char*)cMemMan_alloc(0x4C, D_0047C000, 0, 0);
    func_0039E2A0(p, *(void**)((char*)self + 0xC));
    *(int*)(p + 0x48) = 0;
    *(void***)(p + 8) = D_0047C608;
    return p;
}

void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");

extern "C" void cFELoadScreen_load(void* self)
{
    {
        char* g = (char*)D_004A289C;
        sVE_233438* vt = *(sVE_233438**)(g + 0x10D8);
        vt[44].fn(g + vt[44].delta, 0x100);
    }
    void* eng = func_00397B08(cMemMan_alloc(0x70, D_0047B698, 0x100, 0));
    *(void**)((char*)self + 0xC) = eng;
    cUIEngine_loadFile(eng, D_0047BFB0);
    (*(sEngine_233438**)((char*)self + 0xC))->f8 = *(int*)((char*)D_004A28A8 + 0x88);
    (*(sEngine_233438**)((char*)self + 0xC))->f10 = *(int*)((char*)D_004A28A8 + 0x8C);
    {
        sObj_233438* o = new (D_0047BFC0, 0x100, 0) sObj_233438;
        o->f4 = 0;
        o->vt = D_0046D1D0;
        o->f18 = 0;
        o->fC = 0;
        o->f10 = 0;
        o->f14 = 0;
        (*(sEngine_233438**)((char*)self + 0xC))->fC = o;
    }
    char* gm = *(char**)((char*)D_004A28A8 + 0xC0);
    cBE_getInterface_3438(cBE_getBE(), 0);
    char* screen;
    if (D_004A19C4 == 0x27) {
        screen = newScreenA_233438(self);
    } else if (*(int*)(gm + 0x9C) == 0 || D_00535C11[0] == 0) {
        screen = newScreenB_233438(self);
        *(void**)(screen + 0x48) = self;
        func_00233640(self, 1);
    } else {
        screen = newScreenC_233438(self);
        *(void**)(screen + 0x48) = self;
        func_00233640(self, 2);
    }
    func_0039F400(*(char**)((char*)self + 0xC) + 0x18, screen);
    *(int*)((char*)self + 0x18) = -1;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233640);
#ifdef SKIP_ASM
int cBENewPlayerInterface_getPlayerCharID(void* self, int idx);
int cBENewPlayerInterface_getRiderCharID(void* self, int idx);
extern "C" int func_00146E98(void* player, int idx);
struct cBigFile {
    int field_0x0;
    int field_0x4;
};
// PORT: cBigFile_cBigFile1 really takes (self, path, flags); bound by asm label.
cBigFile* cBigFile_cBigFile1_3640(cBigFile* self, const char* path, int flags) __asm__("cBigFile_cBigFile1__FP8cBigFile");
void cBigFile__cBigFile(cBigFile* self, int flags);
void cMemMan_free(void*);
extern "C" char* func_003E2190(const char* name, int flags);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_0047BD78[];
extern char D_0047BD90[];
extern char D_0047BDA0[];
extern char* D_00442928[];
extern int D_004A2B38;
extern int D_004A2B3C;

struct sLsOpt_3640 {
    int on;         // 0x0
    int f4;
    int alt;        // 0x8
};
extern sLsOpt_3640 D_00534B30_3640[] __asm__("D_00534B30");

struct sVE_3640 {
    short delta;
    short index;
    int (*fn)(void*, void*, const char*, int, int, int);
};

static inline int loadTex_3640(char* data, const char* name)
{
    char* g = (char*)D_004A289C;
    sVE_3640* vt = *(sVE_3640**)(g + 0x10D8);
    return vt[46].fn(g + vt[46].delta, data + *(int*)(data + 0x14), name, 0, 1, -1);
}

extern "C" void func_00233640(void* self, int type)
{
    char name[0x70];
    cBigFile bf;
    void* plr = cBE_getInterface_3438(cBE_getBE(), 1);
    cBE_getInterface_3438(cBE_getBE(), 0);
    cBigFile_cBigFile1_3640(&bf, D_0047BD78, 0x100);
    if (type == 1) {
        const char* fmt = D_0047BD90;
        cBE_getInterface_3438(*(void**)((char*)D_004A28A8 + 0x78), 7);
        sLsOpt_3640* opt = D_00534B30_3640;
        if (opt->on != 0) {
            if (opt->alt != 0) {
                sprintf(name, fmt, D_00442928[cBENewPlayerInterface_getRiderCharID(plr, 0)], D_004A2B38);
            } else {
                sprintf(name, fmt, D_00442928[cBENewPlayerInterface_getRiderCharID(plr, 1)], D_004A2B38);
            }
        } else {
            sprintf(name, fmt, D_00442928[cBENewPlayerInterface_getRiderCharID(plr, func_00146E98(plr, 0))], D_004A2B38);
        }
        char* data = func_003E2190(name, 0x3000100);
        *(int*)((char*)self + 0x10) = loadTex_3640(data, D_0047BDA0);
        if (data != 0)
            cMemMan_free(data);
    } else if (type == 2 && D_00535C11[0] == 2) {
        int* slot = (int*)((char*)self + 0x10);
        for (int i = 0; i < 2; i++) {
            sprintf(name, D_0047BD90, D_00442928[cBENewPlayerInterface_getPlayerCharID(plr, i)], D_004A2B3C);
            char* data = func_003E2190(name, 0x3000100);
            *slot = loadTex_3640(data, D_0047BDA0);
            if (data != 0)
                cMemMan_free(data);
            slot++;
        }
    }
    cBigFile__cBigFile(&bf, 2);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_002338C8);
#ifdef SKIP_ASM
extern int D_004A4324;
extern "C" void func_00369FF8(void* g);
extern "C" void func_00228238(void* app);
extern "C" void* func_0028B180();
extern "C" void func_0028F768(void* snd);

struct sVec3i_38C8 {
    int x, y, z;
    sVec3i_38C8(int a, int b, int c) { x = a; y = b; z = c; }
};

struct sVE_38C8 {
    short delta;
    short index;
    void (*fn)(void*, sVec3i_38C8);
};

extern "C" void func_002338C8(void)
{
    func_00369FF8(D_004A289C);
    func_00228238(D_004A28A8);
    // Storing through a pointer keeps the store ahead of the reload of D_004A289C.
    int* p = &D_004A4324;
    *p = 0;
    char* g = (char*)D_004A289C;
    sVE_38C8* vt = *(sVE_38C8**)(g + 0x10D8);
    vt[15].fn(g + vt[15].delta, sVec3i_38C8(0, 0, 0));
    func_0028F768(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233930);
#ifdef SKIP_ASM
struct cGame00233930 {
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
    virtual void v50(int id);
};

extern void* D_004A289C;
extern "C" void func_00397B70(void* self, int a1);
extern "C" void func_0036A020(void* self);
extern "C" void* func_0028B180();
extern "C" void func_0028FA98(void* self, float f);

extern "C" void func_00233930(void* self)
{
    ((cGame00233930*)D_004A289C)->v19();
    int id = *(int*)((char*)self + 0x18);
    if (id >= 0) {
        ((cGame00233930*)D_004A289C)->v50(id);
    }
    void* o = *(void**)((char*)self + 0xC);
    if (o != 0) {
        func_00397B70(o, 3);
    }
    int i;
    for (i = 0; i < 2; i++) {
        int h = *(int*)((char*)self + 0x10 + i * 4);
        if (h != 0) {
            ((cGame00233930*)D_004A289C)->v50(h);
        }
    }
    func_0036A020(D_004A289C);
    func_0028FA98(func_0028B180(), 1.0f);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_002339F8);
#ifdef SKIP_ASM
struct sVEntryI002339F8 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sVEntryV002339F8 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern void* D_004A289C;
extern "C" int func_00231D60(void* self);
extern "C" void func_00397DF8(void* engine);

extern "C" int func_002339F8(void* self)
{
    char* g = (char*)D_004A289C;
    sVEntryI002339F8* vt = *(sVEntryI002339F8**)(g + 0x10D8);
    if (vt[17].fn(g + vt[17].delta) == 0) {
        return 0;
    }
    if (func_00231D60(self) == 0) {
        func_00397DF8(*(void**)((char*)self + 0xC));
    }
    g = (char*)D_004A289C;
    sVEntryV002339F8* vt2 = *(sVEntryV002339F8**)(g + 0x10D8);
    vt2[20].fn(g + vt2[20].delta);
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233A70);
#ifdef SKIP_ASM
extern "C" void func_00398038(void*);
void func_00231CB0(void*);

extern "C" void func_00233A70(void* self)
{
    func_00398038(*(void**)((char*)self + 0xC));
    func_00231CB0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233AA0);
#ifdef SKIP_ASM
extern void* D_004A2C68;
extern "C" void func_00231250(void* self, int a, int b, int refresh);

extern "C" void func_00233AA0(void* self)
{
    int a = *(int*)self;
    if (a != 0) {
        func_00231250(D_004A2C68, a, *(int*)((char*)self + 4), 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233AD0);
#ifdef SKIP_ASM
extern "C" void func_00231278__FPvi(int);

extern "C" void func_00233AD0(void) {
    func_00231278__FPvi((*(int*)&D_004A2C68));
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233AF0);
#ifdef SKIP_ASM
struct sVEntry_func_00233AF0 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

// PORT: the unit declares func_00233AF0 as `void* (void*)`; the body also uses $a1 (obj).
// Bound by asm label.
void* func_00233AF0_2(void* self, void* obj) __asm__("func_00233AF0");

void* func_00233AF0_2(void* self, void* obj)
{
    sVEntry_func_00233AF0* vt = *(sVEntry_func_00233AF0**)obj;
    return vt[1].fn((char*)obj + vt[1].delta, self, 4);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233B28);
#ifdef SKIP_ASM
struct sVEntry_func_00233B28 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

// PORT: the unit declares func_00233B28 as `void* (void*)`; the body also uses $a1 (obj).
// Bound by asm label.
void* func_00233B28_2(void* self, void* obj) __asm__("func_00233B28");

void* func_00233B28_2(void* self, void* obj)
{
    sVEntry_func_00233B28* vt = *(sVEntry_func_00233B28**)obj;
    return vt[2].fn((char*)obj + vt[2].delta, self, 4);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233B60);
#ifdef SKIP_ASM
extern void* D_004A2C68;
extern "C" void func_00231250(void* self, int a, int b, int refresh);

extern "C" void func_00233B60(void)
{
    func_00231250(D_004A2C68, 0xA, 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233B88__FPv);
#ifdef SKIP_ASM
void func_00233B88(void* self)
{
}
#endif

extern "C" void* func_00233AF0(void* self);

//99.29%
INCLUDE_ASM("fe/festateloadscreen", func_00233B90__FPv);
#ifdef SKIP_ASM
void* func_00233B90(void* self)
{
    return func_00233AF0(self);
}
#endif

extern "C" void* func_00233B28(void* self);

//99.29%
INCLUDE_ASM("fe/festateloadscreen", func_00233BB0__FPv);
#ifdef SKIP_ASM
void* func_00233BB0(void* self)
{
    return func_00233B28(self);
}
#endif

//99.29%
INCLUDE_ASM("fe/festateloadscreen", func_00233BD0__FPv);
#ifdef SKIP_ASM
void* func_00233BD0(void* self)
{
    return func_00233AF0(self);
}
#endif

//99.29%
INCLUDE_ASM("fe/festateloadscreen", func_00233BF0__FPv);
#ifdef SKIP_ASM
void* func_00233BF0(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233C10);
#ifdef SKIP_ASM
extern void* D_0047D6E8[];
extern void* D_0047D5E0[];
extern void* D_004A2C68;

extern "C" void* func_00233C10(void* self)
{
    *(int*)self = 0;
    *(void***)((char*)self + 0xC) = D_0047D6E8;
    D_004A2C68 = 0;
    *(void***)((char*)self + 0xC) = D_0047D5E0;
    *(int*)self = 7;
    *(int*)((char*)self + 0x10) = 2;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x14) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233C50);
#ifdef SKIP_ASM
extern void* D_004A2C68;
extern void* D_004A28A4;
extern void* D_004A28A8;
extern void* D_004A2EEC;
extern "C" void func_0026FA50(void* self);
extern "C" void func_0039F840(void* list);
extern "C" void func_002790A0(void* self, int i);
extern "C" void func_001F36C0(void* self, int bit);
void func_00244880(void* self);

extern "C" void func_00233C50(void* self)
{
    func_0026FA50(*(void**)((char*)D_004A2C68 + 0x28));
    func_0039F840(*(char**)((char*)D_004A2C68 + 0x48) + 0x18);
    func_002790A0(D_004A28A4, 0);
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0xB4;
    func_001F36C0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94), 4);
    void* p = D_004A2EEC;
    if (p != 0) {
        func_00244880(p);
        *(int*)((char*)p + 0x90) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00233CD8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
void* cBEAggressionInterface_getThis();
extern "C" void func_00155E58(void* p);
extern "C" void func_001F36D8(void* hud, int a);
extern "C" void func_0020CC60();
extern "C" void func_00233AA0(void* self);
extern "C" int func_00278F38(void* self, int i);
extern "C" void func_002790A0(void* self, int i);
extern "C" int func_002791D8(void* self, int i);
extern "C" int func_00279248(void* self, int i);
extern "C" void func_0027AC60(void* self);
extern "C" void* func_0039F9D8(void* list, int hash);
extern void* D_004A28A4;
extern void* D_004A28A8;
extern int D_005366A8[];
// PORT: function-local `static const float` with a dynamic initializer (guard D_004A4F64),
// spelled with splat's globals; the const object's loads are loop-invariant (RTX_UNCHANGING).
extern const float D_004A4F60;
extern int D_004A4F64;
extern char D_0047C010[];

struct sRace_233CD8 {
    char pad0[0x48];
    signed char mode48;
    signed char flag49;
};
extern sRace_233CD8 D_00535BC8_r233CD8 __asm__("D_00535BC8");

static inline int isMode_233CD8(sRace_233CD8* r, int m)
{
    return r->mode48 == m;
}

struct sVec4_233CD8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_233CD8(const sVec4_233CD8& v)
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

struct sVEntry_233CD8 {
    short delta;
    short index;
    sVec4_233CD8* (*fn)(void*);
};

static inline sVec4_233CD8* riderPos_233CD8(char* rider)
{
    char* obj = rider + 0x6C0;
    sVEntry_233CD8* vt = *(sVEntry_233CD8**)obj;
    return vt[2].fn(obj + vt[2].delta);
}

class cFEVObj_233CD8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
    virtual int v24(int on, int a2);
};


extern "C" void func_00233CD8(void* self)
{
    char* s = (char*)self;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (*(int*)(s + 0x14) != 0) {
        if (--*(int*)(s + 0x14) == 0) {
            int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
            int ok = n != 0 && n < 10;
            if (!ok) {
                func_0020CC60();
                if (*(int*)(s + 0x10) != 2) {
                    cFEVObj_233CD8* o = (cFEVObj_233CD8*)func_0039F9D8(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48) + 0x18, GetHashValue32(D_0047C010));
                    if (o != 0) {
                        o->v24(0, 0);
                    }
                }
            }
        }
    }
    int state = *(int*)(s + 0x10);
    switch (state) {
    case 0: {
        char* g = (char*)D_004A28A8;
        char* x = *(char**)(g + 0xC0);
        char* r = *(char**)(*(char**)(g + 0x84) + 0xC);
        int cnt = *(int*)(r + 0x7C);
        if (D_005366A8[0] == 0) {
            for (int i = 0; i < cnt; i++) {
                if (D_004A4F64 == 0) {
                    *(float*)&D_004A4F60 = 277.77777099609375f;
                    D_004A4F64 = 1;
                }
                if (D_004A4F60 < vLen_233CD8(*riderPos_233CD8(*(char**)(((char**)(r + 0x40))[i] + 0x18)))) {
                    return;
                }
            }
        }
        sRace_233CD8* rc = &D_00535BC8_r233CD8;
        int skip = !isMode_233CD8(rc, 4) && *(int*)(x + 0x98) != 0 && *(int*)(x + 0x9C) == 0;
        if (skip) {
            return;
        }
        func_002790A0(D_004A28A4, 0);
        func_0027AC60(D_004A28A4);
        func_00278F38(D_004A28A4, 0);
        if (func_00279248(D_004A28A4, 0) > 0) {
            *(int*)s = 0xC;
        }
        sRace_233CD8* rc2 = &D_00535BC8_r233CD8;
        if (rc2->mode48 == 0) {
            func_00155E58(cBEAggressionInterface_getThis());
        }
        *(int*)(s + 0x10) = 1;
        break;
    }
    case 1: {
        if (func_002791D8(D_004A28A4, 0) == 1) {
            break;
        }
        cFEVObj_233CD8* o = (cFEVObj_233CD8*)func_0039F9D8(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48) + 0x18, GetHashValue32(D_0047C010));
        if (o != 0) {
            o->v24(1, 0);
        }
        func_001F36D8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94), 4);
        *(int*)(s + 0x10) = 2;
        break;
    }
    case 2: {
        sRace_233CD8* rc = &D_00535BC8_r233CD8;
        if (rc->flag49 == 0 && rc->mode48 == 4) {
            func_00233AA0(self);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00234008);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sLoadScreen00234008 {
    int state;
    int pad4[3];
    int mode;
};
extern void* D_004A28A8;
extern void* D_004A28A4;
void func_00162290_v(void* self) __asm__("func_00162290__FPv");
extern "C" int func_00278F68(void* self, int i, int a, int b);
void func_00278DE8(void* self, int val);

extern "C" void func_00234008(sLoadScreen00234008* self)
{
    int n = *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84) + 0x10);
    int i;
    for (i = 0; i < n; i++) {
        char* list = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84);
        char* item = *(char**)(list + (i << 2) + 4);
        func_00162290_v(*(void**)(item + 0xA8));
    }
    self->mode = 2;
    func_00278F68(D_004A28A4, 0, 1, 0);
    func_00278DE8(D_004A28A4, 1);
    self->state = 7;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festateloadscreen", func_002340B8);
#ifdef SKIP_ASM
struct sVEntry_func_002340B8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_002340B8(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry_func_002340B8* e = &(*(sVEntry_func_002340B8**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_002340B8**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festateloadscreen", func_00234120);
#ifdef SKIP_ASM
struct sVEntry_func_00234120 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00234120(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry_func_00234120* e = &(*(sVEntry_func_00234120**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00234120**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00234188);
#ifdef SKIP_ASM
extern void* D_0047D6E8[];
extern void* D_0047D530[];
extern void* D_004A2C68;

extern "C" void* func_00234188(void* self)
{
    *(int*)self = 0;
    *(void***)((char*)self + 0xC) = D_0047D6E8;
    D_004A2C68 = 0;
    *(void***)((char*)self + 0xC) = D_0047D530;
    *(int*)self = 2;
    *(int*)((char*)self + 0x1C) = 4;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_002341D0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_41D0(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void cBE_setState(int state);
extern "C" void cAI_setAIState(void*, int);
extern "C" void func_001F36D8(void* hud, int a);
extern "C" void func_0026F228(void* p);
extern "C" int cBENewRaceInterface_setNumberAI(void* self, int count);
extern "C" void cBENewPlayerInterface_setRiderCharID(void* player, int i, int id);
extern "C" void func_001473D0(void* player, int i, int v);
extern "C" void func_002790A0(void* self, int i);
extern "C" void func_0027AAF8(void* a, int b);
// PORT: func_00278F38 returns func_00276270's result (ssxscriptengine defines it void).
extern "C" int func_00278F38(void* self, int i);
extern void* D_004A2C68;
extern void* D_004A28A4;
extern void* D_004A28A8;
extern signed char D_00535C10[];

struct sVE_2341D0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sGM_2341D0 {
    char pad0[0x10];
    int total;      // 0x10
    int humans;     // 0x14
    int chars[10];  // 0x18
    int boards[10]; // 0x40
};

static inline int isMode4_2341D0()
{
    return D_00535C10[0] == 4;
}

extern "C" void func_002341D0(void* self, int mode)
{
    int i = 0;
    char* race = (char*)cBE_getInterface_41D0(cBE_getBE(), 0);
    char* player = (char*)cBE_getInterface_41D0(cBE_getBE(), 1);
    cAI_setAIState(*(void**)((char*)D_004A2C68 + 0xC), 3);
    func_001F36D8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94), 0);
    cBE_setState(0);
    sGM_2341D0* gm = *(sGM_2341D0**)((char*)D_004A28A8 + 0xC0);
    func_0026F228(*(void**)((char*)D_004A2C68 + 0x28));
    int n = gm->total - gm->humans;
    int base = *(int*)(*(char**)((char*)D_004A2C68 + 0xC) + 0x7C);
    cBENewRaceInterface_setNumberAI(race, n);
    {
        sVE_2341D0* vt = *(sVE_2341D0**)(race + 0xC);
        vt[1].fn(race + vt[1].delta);
    }
    for (; i < n; i++) {
        cBENewPlayerInterface_setRiderCharID(player, i + base, gm->chars[base + i]);
        func_001473D0(player, i + base, gm->boards[base + i]);
    }
    {
        sVE_2341D0* vt = *(sVE_2341D0**)(player + 0xC);
        vt[1].fn(player + vt[1].delta);
    }
    switch (mode) {
    case 0:
        break;
    case 2:
        func_002790A0(D_004A28A4, 0);
        func_0027AAF8(D_004A28A4, 1);
        func_00278F38(D_004A28A4, 0);
        break;
    case 1:
        if (!isMode4_2341D0()) {
            func_002790A0(D_004A28A4, 0);
            func_0027AAF8(D_004A28A4, 0);
            func_00278F38(D_004A28A4, 0);
        }
        break;
    }
    *(int*)((char*)self + 0x1C) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_002343B0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001F36C0(void* self, int bit);
extern "C" void func_001F36D8(void* self, int bit);
extern "C" int func_00279220(void* snd, int a1);
extern "C" void func_00279040(void* snd, int a1, int a2);
extern "C" int func_00279298(void* snd);
extern "C" int func_002791D8(void* snd, int a1);
extern "C" int func_00278F68(void* snd, int a1, int a2, int a3);
extern "C" int func_00279148(void* snd, int a1, int a2);
extern "C" void func_00234910(void* self);
extern "C" void func_00233AA0(void* self);
extern "C" void func_0012AB20(void* o);
extern "C" void func_0012AC48(void* o);
extern "C" void func_00128958(void* o);
extern "C" void func_00128998(void* o, int a1);
extern "C" void func_00128A48(void* o, int a1);
extern "C" int func_0012A180(void* o);
extern "C" void func_001296F8(void* o);
void func_001289F0(void* o);
extern "C" int func_0012ABD0(void* o);
extern "C" int func_0012ACF8(void* o);
extern "C" void func_0012B030(void* o);
extern "C" void func_0012B000(void* o);
extern void* D_004A28A8;
extern void* D_004A28A4;
extern void* D_004A2C68;
extern signed char D_00535BC8[];
extern signed char D_00535C10[];

struct sLoadObj_43B0 {
    char pad0[0x14];
    int f14;                        // 0x14
    char pad18[0x80 - 0x18];
    int f80;                        // 0x80
    int f84;                        // 0x84
    char pad88[0x4];
    int f8C;                        // 0x8C
};

struct sLoadMgr_43B0 {
    char pad0[0xC];
    sLoadObj_43B0* obj;             // 0xC
};

struct sLoadScreen_43B0 {
    char pad0[0x10];
    int pending;                    // 0x10
    int f14;                        // 0x14
    char pad18[0x4];
    int state;                      // 0x1C
};

#define MGR_43B0 ((sLoadMgr_43B0*)D_004A2C68)

static inline void* hud_43B0()
{
    return *(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94);
}

// Load screen update: drives the loading state machine (stream start, track setup, wait for load, finish).
extern "C" void func_002343B0(sLoadScreen_43B0* self)
{
    if (self->state < 3) {
        func_001F36C0(hud_43B0(), 2);
        if (func_00279220(D_004A28A4, 0) == 4)
            func_00279040(D_004A28A4, 0, 1);
    } else {
        if (func_00279220(D_004A28A4, 0) == 3)
            func_00279040(D_004A28A4, 0, 0);
        func_001F36D8(hud_43B0(), 2);
    }
    switch (self->state) {
    case 0:
        if (func_00279298(D_004A28A4) == 0)
            self->state = 1;
        break;
    case 1: {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        func_00234910(self);
        signed char* cfg = D_00535BC8;
        int mode = cfg[0x48];
        int skip = cfg[0x49];
        int sub = cfg[0x4A];
        if (mode == 4 || (mode == 5 && sub != 4) || (mode == 6 && sub != 5)) {
            func_0012AB20(MGR_43B0->obj);
            func_0012AC48(MGR_43B0->obj);
            self->pending = 1;
        } else if (skip == 0) {
            func_00128958(MGR_43B0->obj);
            sLoadObj_43B0* o = MGR_43B0->obj;
            if (o->f80 == 0) {
                if (mode == 0)
                    func_00128998(o, 0);
                else
                    func_00128998(o, 2);
            }
            MGR_43B0->obj->f8C = 0;
        }
        func_00128A48(MGR_43B0->obj, 0);
        if (mode == 5 || mode == 0)
            func_00128A48(MGR_43B0->obj, 1);
        else if (mode != 4)
            func_00128A48(MGR_43B0->obj, 2);
        self->state = 2;
        break;
    }
    case 2:
        if (!func_0012A180(MGR_43B0->obj))
            func_001296F8(MGR_43B0->obj);
        else
            self->state = 3;
        break;
    case 3: {
        if (func_00279220(D_004A28A4, 1) != 0)
            break;
        if (MGR_43B0->obj->f84 > 0)
            MGR_43B0->obj->f8C = 1;
        if (MGR_43B0->obj->f80 > 0)
            MGR_43B0->obj->f14 = 1;
        if (func_002791D8(D_004A28A4, 0) == 2) {
            func_00278F68(D_004A28A4, 0, self->f14 == 0, 1);
            break;
        }
        int r1 = func_00279220(D_004A28A4, 0);
        int r2 = func_00279148(D_004A28A4, 0, 0);
        int busy = r1 && r2 != 5;
        if (busy)
            break;
        cBE_getInterface_Fv(cBE_getBE(), 0);
        if (D_00535C10[0] != 4) {
            func_001289F0(MGR_43B0->obj);
            if (MGR_43B0->obj->f80 > 0)
                MGR_43B0->obj->f14 = 1;
        }
        if (self->pending) {
            if (!func_0012ABD0(MGR_43B0->obj))
                break;
            if (!func_0012ACF8(MGR_43B0->obj))
                break;
            func_0012B030(MGR_43B0->obj);
            func_0012B000(MGR_43B0->obj);
            self->pending = 0;
        }
        self->state = 4;
        func_00233AA0(self);
        break;
    }
    case 4:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00234750);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_4750(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void cBE_setState(int state);
extern "C" void cAI_setAIState(void*, int);
void* cBEAggressionInterface_getThis();
extern "C" void func_002790A0(void* self, int i);
extern "C" void func_00128958(void* p);
void func_001289F0(void* p);
extern "C" void func_00128A10(void* p);
extern "C" void func_0026F7B8(void* p);
extern "C" void func_00128A48(void* p, int a);
extern "C" void func_00308F38(void* a);
extern "C" void func_00308C60(void* a);
extern "C" void func_00129160(void* p);
extern "C" void func_00155E58(void* p);
extern void* D_004A2C68;
extern void* D_004A28A4;
extern void* D_004A28A8;
extern void* D_004A3DD8;

struct sRace_234750 {
    char pad0[0x48];
    signed char mode48;
    signed char flag49;
};
extern sRace_234750 D_00535BC8_r234750 __asm__("D_00535BC8");

struct sRaceMan_234750 {
    char pad0[0x8C];
    int f8C;
};

struct sVE_234750 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sTbl_234750 {
    char pad[0x250];
    struct { int f0; char pad[0x4C]; } slot[2];
};

static inline int otherSide_234750(char* p)
{
    return *(int*)(p + 0xB0) == 0;
}

extern "C" void func_00234750(void* self)
{
    func_002790A0(D_004A28A4, 1);
    cBE_getInterface_4750(cBE_getBE(), 0);
    sRace_234750* r = &D_00535BC8_r234750;
    int mode = r->mode48;
    if (mode == 0) {
        func_00128958(*(void**)((char*)D_004A2C68 + 0xC));
        func_001289F0(*(void**)((char*)D_004A2C68 + 0xC));
    } else {
        func_00128A10(*(void**)((char*)D_004A2C68 + 0xC));
        func_0026F7B8(*(void**)((char*)D_004A2C68 + 0x28));
    }
    if (mode != 4) {
        char* o = *(char**)((char*)D_004A2C68 + 0xC);
        sVE_234750* vt = *(sVE_234750**)(o + 0xCC);
        vt[5].fn(o + vt[5].delta, 3);
        *(int*)(*(char**)((char*)D_004A2C68 + 0xC) + 0x14) = 1;
    }
    func_00128A48(*(void**)((char*)D_004A2C68 + 0xC), 0);
    if (mode == 5 || mode == 0)
        func_00128A48(*(void**)((char*)D_004A2C68 + 0xC), 1);
    else if (mode != 4)
        func_00128A48(*(void**)((char*)D_004A2C68 + 0xC), 2);
    func_00308F38(D_004A3DD8);
    func_00308C60(D_004A3DD8);
    (*(sRaceMan_234750**)((char*)D_004A2C68 + 0xC))->f8C = 0;
    cAI_setAIState(*(void**)((char*)D_004A2C68 + 0xC), 3);
    cBE_setState(1);
    func_00129160(*(void**)((char*)D_004A2C68 + 0xC));
    sRace_234750* r2 = &D_00535BC8_r234750;
    if (r2->flag49 != 0)
        func_00155E58(cBEAggressionInterface_getThis());
    *(int*)((char*)self + 0x14) = 0;
    char* g = *(char**)((char*)D_004A28A8 + 0x84);
    char* x = *(char**)(g + 0x84);
    if (*(int*)(x + 0x10) == 1) {
        sTbl_234750* t = **(sTbl_234750***)(g + 0x10);
        t->slot[otherSide_234750(*(char**)(x + 4))].f0 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadscreen", func_00234910);
#ifdef SKIP_ASM
extern void* D_004A28A4;
extern "C" int func_00278F68(void* self, int i, int a, int b);

static inline int isState00234910(void* e, int s)
{
    return *(int*)((char*)e + 0x550) == s;
}

extern "C" void func_00234910(void* self)
{
    if (isState00234910(D_004A28A4, 2)) {
        func_00278F68(D_004A28A4, 1, 1, 1);
    }
    if (isState00234910(D_004A28A4, 2)) {
        func_00278F68(D_004A28A4, 0, 1, 1);
    }
    *(int*)((char*)self + 0x14) = 0;
    if (*(int*)((char*)D_004A28A4 + 0x550) == 1) {
        *(int*)((char*)self + 0x14) = 1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festateloadscreen", func_00234990);
#ifdef SKIP_ASM
// PORT: the unit declares func_00233AF0 as `void* (void*)`; the body also uses $a1 (obj).
void* func_00233AF0_2(void* self, void* obj) __asm__("func_00233AF0");

struct sVEntry_func_00234990 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00234990(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry_func_00234990* e = &(*(sVEntry_func_00234990**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00234990**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_00234990**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x1C, 4);
    e = &(*(sVEntry_func_00234990**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x8, 4);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festateloadscreen", func_00234A30);
#ifdef SKIP_ASM
// PORT: the unit declares func_00233B28 as `void* (void*)`; the body also uses $a1 (obj).
void* func_00233B28_2(void* self, void* obj) __asm__("func_00233B28");

struct sVEntry_func_00234A30 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00234A30(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry_func_00234A30* e = &(*(sVEntry_func_00234A30**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00234A30**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_00234A30**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x1C, 4);
    e = &(*(sVEntry_func_00234A30**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x8, 4);
}
#endif

