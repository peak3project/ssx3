#include "common.h"

INCLUDE_ASM("main/gameload", cGame_load);

//100%
INCLUDE_ASM("main/gameload", cGame_loadTrack);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sBXStr_F6B0 {
    char* p;
    sBXStr_F6B0() {}
    sBXStr_F6B0(const sBXStr_F6B0&);
};

extern char* D_004A3E90;
extern int D_004A11B8;
extern char D_0047B480[];
extern char D_004A2A90[];
extern char D_004A2A98[];
extern char D_0047B728[];
extern char D_0047B738[];
extern char D_0047B748[];
extern char D_0047B758[];
extern char D_004A2AA0[];
extern char D_004A2AA8[];
extern char D_004C5830[];
extern void* D_004882E0[];

extern "C" void* cBXString_cBXString2(sBXStr_F6B0* self, const char* s);
extern "C" sBXStr_F6B0* func_00318630(sBXStr_F6B0* self, sBXStr_F6B0* a, const char* str);
extern "C" sBXStr_F6B0* func_003186D0(sBXStr_F6B0* self, const char* str, sBXStr_F6B0* b);
extern "C" void cBXString__cBXString(sBXStr_F6B0* self, int flags);
extern "C" sBXStr_F6B0* cBXString_operatorE(sBXStr_F6B0* self, sBXStr_F6B0* o);
extern "C" char* func_00144BC0(void* iface);
extern "C" int cBigFile_open(void* bf, const char* name, int flags);
extern "C" void func_003A6AE0(void* a, const char* name, void* b);
void* func_00353AC0(void* p);
extern "C" void* func_0022CCE8(void* p, void* game);
extern "C" void func_002C2F18(void* p);
extern "C" void* func_002B6AA0(void* p, int a);
extern "C" void func_00334800(void* p);
extern "C" void func_0022D088(void* p, int id, int a);
extern "C" int func_0022D278(void* p, int id);
extern "C" void func_0022D8D8(void* p);
void func_003A6928(void* p);
extern "C" void func_003E5398(int a);
// PORT: func_0016CA10__FPv also receives the path string (passed through in $5)
void func_0016CA10_F6B0(void* p, const char* s) __asm__("func_0016CA10__FPv");
extern "C" void* func_002DBF80(void* p);
void* cLensFxMan_construct();
extern "C" void func_002ED048();

struct sElem4_F6B0 {
    int v;
    sElem4_F6B0() {}
};

struct sRow_F6B0 {
    sElem4_F6B0 e[4];
    char pad[0xB0 - 0x10];
    sRow_F6B0() {}
};

struct sTbl_F6B0 {
    sRow_F6B0 rows[19];
    static void* operator new(unsigned int size, const char* tag, unsigned int flags, int d)
    {
        return cMemMan_alloc(size, tag, flags, d);
    }
    sTbl_F6B0() {}
};

struct sElemFF_F6B0 {
    char b[0x30];
    sElemFF_F6B0() {}
    static void* operator new[](unsigned int, void* p) { return p; }
};

extern "C" void cGame_loadTrack(char* self)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    sBXStr_F6B0 name;
    name.p = D_004A3E90;
    if (D_004A11B8 != 0) {
        sBXStr_F6B0 a;
        sBXStr_F6B0 b;
        func_003186D0(&a, D_0047B480, (cBXString_cBXString2(&b, func_00144BC0(iface) + 0x44), &b));
        cBXString_operatorE(&name, &a);
        cBXString__cBXString(&a, 2);
        cBXString__cBXString(&b, 2);
    } else {
        sBXStr_F6B0 a;
        sBXStr_F6B0 b;
        func_003186D0(&a, D_0047B480, (cBXString_cBXString2(&b, func_00144BC0(iface) + 0x34), &b));
        cBXString_operatorE(&name, &a);
        cBXString__cBXString(&a, 2);
        cBXString__cBXString(&b, 2);
    }
    {
        sBXStr_F6B0 path;
        func_00318630(&path, &name, D_004A2A90);
        cBigFile_open(*(void**)(self + 0xA8), path.p, 0);
        cBXString__cBXString(&path, 2);
    }
    sTbl_F6B0*& tbl = *(sTbl_F6B0**)(self + 0x44);
    char*& ent = *(char**)(self + 0x18);
    func_003A6AE0(*(void**)(self + 0x10), name.p, *(void**)(self + 0x20));
    *(void**)(self + 0x14) = func_00353AC0(cMemMan_alloc(0x18, D_004A2A98, 0, 0));
    *(void**)(self + 0x78) = func_0022CCE8(cMemMan_alloc(0x1D4, D_0047B728, 0, 0), self);
    tbl = new (D_0047B738, 0, 0) sTbl_F6B0;
    func_002C2F18(*(void**)(self + 0x44));
    *(void**)(self + 0x4C) = func_002B6AA0(cMemMan_alloc(0x250, D_0047B748, 0, 0), 0);
    func_00334800(*(void**)(self + 0x20));
    sBXStr_F6B0 dir;
    dir.p = D_004A3E90;
    *(int*)(**(char***)(self + 0x10) + 0x3D4) = 0;
    {
        sBXStr_F6B0 a;
        sBXStr_F6B0 b;
        func_003186D0(&a, D_0047B480, (cBXString_cBXString2(&b, func_00144BC0(iface) + 0x34), &b));
        cBXString_operatorE(&dir, &a);
        cBXString__cBXString(&a, 2);
        cBXString__cBXString(&b, 2);
    }
    int id = *(int*)func_00144BC0(iface);
    func_0022D088(*(void**)(self + 0x78), id, 0);
    *(int*)(*(char**)(self + 0x78) + 0x1A4) = 1;
    while (!func_0022D278(*(void**)(self + 0x78), id)) {
        func_0022D8D8(*(void**)(self + 0x78));
        func_003A6928(*(void**)(self + 0x10));
        func_003E5398(0);
    }
    *(int*)(**(char***)(self + 0x10) + 0x3D4) = 1;
    {
        sBXStr_F6B0 a;
        sBXStr_F6B0 c;
        func_0016CA10_F6B0(D_004C5830, (func_003186D0(&c, D_004A2AA0, &dir), func_00318630(&a, &c, D_004A2AA8), a.p));
        cBXString__cBXString(&a, 2);
        cBXString__cBXString(&c, 2);
    }
    char* obj = (char*)cMemMan_alloc(0x3010, D_0047B758, 0, 0);
    func_002DBF80(obj);
    *(void***)(obj + 4) = D_004882E0;
    new (obj + 0x10) sElemFF_F6B0[256];
    ent = obj;
    *(void**)(self + 0x1C) = cLensFxMan_construct();
    func_002ED048();
    cBXString__cBXString(&dir, 2);
    cBXString__cBXString(&name, 2);
}
#endif

INCLUDE_ASM("main/gameload", func_0022FA98);

//100%
INCLUDE_ASM("main/gameload", func_00230050);
#ifdef SKIP_ASM
class cMgr230050 {
public:
    int pad;
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
};
extern "C" void func_00195D50(void* a);
extern "C" void func_001F30D8(void* a);
void func_00278710(void* a);
extern "C" void func_00369FF8(void* a);
extern "C" void func_003A67E0(void* a);
extern "C" void func_002B68D0(void* a);
extern "C" void func_002867E8(void* a);
extern void* D_004A28A8;
extern void* D_004A28A4;
extern void* D_004A289C;
extern void* D_004A52D4;
extern void* D_004A3500;
extern void* D_004A270C;
extern cMgr230050* D_004A4248;
extern int D_004A43C8;
extern int D_004A4324;
extern int D_004A45D8;

extern "C" void func_00230050(void* self)
{
    func_00195D50(*(void**)((char*)D_004A28A8 + 0x8C));
    void* p94 = *(void**)((char*)self + 0x94);
    D_004A270C = 0;
    func_001F30D8(p94);
    func_00278710(D_004A28A4);
    D_004A4248->v17();
    D_004A4248->v04();
    func_00369FF8(D_004A289C);
    func_003A67E0(*(void**)((char*)self + 0x10));
    func_002B68D0(D_004A52D4);
    func_002867E8(D_004A3500);
    D_004A4324 = 1;
    D_004A45D8 = 1;
    D_004A43C8 = 1;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_002300F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0026CA90(void* a);
extern "C" void func_00309030(void* a);
extern "C" void func_00354C98(void* mgr, int a);
extern "C" void cBucketMan_purgeBucket(void* self, int index);
extern "C" void func_00103358(void* a);
extern "C" void func_002D9B40(void);
extern "C" void cWorld_resetMap(void* world);
extern "C" void func_00309F18(void* a);
extern "C" void func_00308C60(void* a);
extern void* D_004A3DD8;
// The unit declares D_004A5988 later as sGp2898 (8 bytes); bind a small-data alias here.
extern char D_004A5988_bm __asm__("D_004A5988");

extern "C" void func_002300F0(void* self)
{
    void* bm = &D_004A5988_bm;
    func_0026CA90(*(void**)((char*)self + 0x34));
    func_00309030(*(void**)((char*)self + 0x30));
    func_00354C98(bm, 1);
    cBucketMan_purgeBucket(bm, 1);
    cBucketMan_purgeBucket(bm, 8);
    func_00103358(*(void**)(*(char**)((char*)self + 0xC) + 0xA4));
    func_002D9B40();
    cWorld_resetMap(*(void**)((char*)self + 0x10));
    func_00309F18(D_004A3DD8);
    func_00308C60(*(void**)((char*)self + 0x30));
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230180);
#ifdef SKIP_ASM
extern "C" void func_0022E7C8(void* self);
extern "C" void* func_0026F228(void* self);
extern "C" void func_002789E0(void* self);
extern "C" void func_0015DB58(void);
extern "C" void func_00229498(void* self);
extern "C" void func_00343BC0(void* self);
extern "C" void func_00357B38(void* self);
extern "C" void* func_0039F9D8(void* list, int hash);
extern "C" void func_00287108(void* self);
extern "C" void* func_0028B180(void);
int GetHashValue32(char* s);
extern char D_004A2AB0[];

struct sVEntry_230180a {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sVEntry_230180b {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" void func_00230180(void* self)
{
    void* bm = &D_004A5988_bm;
    func_0026CA90(*(void**)((char*)self + 0x34));
    func_00309030(*(void**)((char*)self + 0x30));
    func_00354C98(bm, 1);
    cBucketMan_purgeBucket(bm, 1);
    cBucketMan_purgeBucket(bm, 8);
    char* o = *(char**)((char*)self + 0xC);
    sVEntry_230180a* vt = *(sVEntry_230180a**)(o + 0xCC);
    vt[5].fn(o + vt[5].delta, 3);
    func_002D9B40();
    func_0022E7C8(*(void**)((char*)self + 0x84));
    cWorld_resetMap(*(void**)((char*)self + 0x10));
    func_0026F228(*(void**)((char*)self + 0x28));
    func_002789E0(D_004A28A4);
    func_0015DB58();
    func_00229498(*(void**)((char*)self + 0x38));
    func_00343BC0(*(void**)((char*)self + 0x3C));
    func_00357B38(*(void**)((char*)self + 0x40));
    void* list = *(char**)((char*)self + 0x48) + 0x18;
    char* r = (char*)func_0039F9D8(list, GetHashValue32(D_004A2AB0));
    if (r != 0) {
        sVEntry_230180b* vt2 = *(sVEntry_230180b**)(r + 8);
        vt2[24].fn(r + vt2[24].delta, 7, 0);
    }
    func_00309F18(D_004A3DD8);
    func_00308C60(*(void**)((char*)self + 0x30));
    func_00287108(func_0028B180());
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/gameload", cGame_restart);
#ifdef SKIP_ASM
extern "C" void func_00230180(void* self);
extern "C" void cGameModeMan_restartHeat(void* gm);
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern "C" void* func_0028B180(void);
extern "C" void func_002870A0(void* mgr);
extern void* D_004A28A8;

static inline int numRiders_2302A8(void* game)
{
    return *(int*)(*(char**)((char*)game + 0xC) + 0x78);
}

static inline char* rider_2302A8(void* game, int i)
{
    return *(char**)(*(char**)((char*)game + 0xC) + (i << 2) + 0x28);
}

extern "C" void cGame_restart(void* self)
{
    func_00230180(self);
    cGameModeMan_restartHeat(*(void**)((char*)D_004A28A8 + 0xC0));
    int i;
    for (i = 0; i < numRiders_2302A8(self); i++) {
        *(int*)(rider_2302A8(self, i) + 0x2F8) = 0;
    }
    func_00231250(self, 1, 2, 1);
    func_002870A0(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230338);
#ifdef SKIP_ASM
extern "C" void func_00230338(void* self, int section)
{
    void* a = *(void**)((char*)self + 0xC);
    if (a != 0) {
        void* b = *(void**)((char*)a + 0xA4);
        if (b != 0) {
            *(int*)((char*)b + 0xD0) = -1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230360);
#ifdef SKIP_ASM
extern "C" void func_00358700(int kind);
extern "C" void func_00229408(void* self, int id);
extern "C" void func_00343C08(void* self, int arg);
extern "C" void func_00357B90(void* self, int arg);
extern "C" void func_003551A8(void* self, int index, int key);
extern "C" void func_00103308(void* p, int arg);
extern "C" void func_00308FE0(void* self, int i);
extern void* D_004A2A00;
extern void* D_004A3FF0;
extern void* D_004A4028;

extern "C" void func_00230360(void* self, int id)
{
    void* bm = &D_004A5988_bm;
    func_00358700(id);
    func_00229408(D_004A2A00, id);
    func_00343C08(D_004A3FF0, id);
    func_00357B90(D_004A4028, id);
    func_00354C98(bm, 1);
    func_003551A8(bm, 1, id);
    func_003551A8(bm, 8, id);
    void* p = *(void**)((char*)self + 0xC);
    if (p != 0) {
        void* q = *(void**)((char*)p + 0xA4);
        if (q != 0) {
            func_00103308(q, id);
            func_00103308(*(void**)(*(char**)((char*)self + 0xC) + 0xA4), 0x80);
        }
    }
    func_00308FE0(*(void**)((char*)self + 0x30), id);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230430);
#ifdef SKIP_ASM
// PORT: func_00308B58 is declared with one argument; it forwards the section id in $a1 to func_00308B78
void* func_00308B58_2(void* self, int sectionId) __asm__("func_00308B58__FPv");

struct sScriptSection_0430 {
    short state;
    short pad;
    int f4;
    void* data;
};

struct sScriptCache_0430 {
    int f0;
    sScriptSection_0430* sections;
};

struct sWorldCache_0430 {
    int f0;
    sScriptCache_0430* scripts;
};

extern sWorldCache_0430* D_004A47B8_0430 __asm__("D_004A47B8");

static inline bool isSectionLoaded_0430(sScriptCache_0430* c, int sectionId)
{
    return c->sections[sectionId].state >= 2 && c->sections[sectionId].data != 0;
}

extern "C" void func_00230430(void* self, int sectionId)
{
    if (isSectionLoaded_0430(D_004A47B8_0430->scripts, sectionId)) {
        func_00308B58_2(D_004A3DD8, sectionId);
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", cGame_exit);
#ifdef SKIP_ASM
struct cAppMan;
void cReplay_stopAutoReplay(void* self);
extern "C" void func_00258AE0(void* p);
extern "C" void func_00266DF8(void* p);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* func_00232720(void* self);
void* func_00232738(void* self);
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
extern void* D_004A2EEC;
extern void* D_004A33F4;
extern char D_0047B770[];
extern char D_0047B788[];

extern "C" void cGame_exit(void* self, int toFrontEnd)
{
    cReplay_stopAutoReplay(*(void**)((char*)self + 0x28));
    func_00231250(self, 6, 0, 0);
    if (D_004A2EEC != 0) {
        func_00258AE0(D_004A2EEC);
    }
    if (D_004A33F4 != 0) {
        func_00266DF8(D_004A33F4);
    }
    if (toFrontEnd != 0) {
        cAppMan_setNextModule((cAppMan*)D_004A28A8, (unsigned int)func_00232720(cMemMan_alloc(8, D_0047B770, 0x100, 0)));
    } else {
        cAppMan_setNextModule((cAppMan*)D_004A28A8, (unsigned int)func_00232738(cMemMan_alloc(8, D_0047B788, 0x100, 0)));
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230558);
#ifdef SKIP_ASM
extern "C" void func_0026F8A0(void* a, int b, int c, int d);
void func_002CC0B8(void* a, int b);
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_00442910[];

struct sGameLoad_0558 {
    char pad_0x00[0x28];
    void* field_0x28;       // 0x28
    char pad_0x2C[0xA4 - 0x2C];
    void* field_0xA4;       // 0xA4
};

extern "C" void func_00230558(sGameLoad_0558* self)
{
    D_005366E8[++D_004A2A54] = 8;
    D_004A2A50 = D_00442910[0];
    func_0026F8A0(self->field_0x28, 0, 0, 0);
    func_002CC0B8(self->field_0xA4, 0);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_002305C8);
#ifdef SKIP_ASM
extern "C" void func_0026F980(void* a);
void func_002CC0B8(void* a, int b);
extern "C" void func_002CC460(void* a);
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_004428F0[];

extern "C" void func_002305C8(void* self)
{
    func_0026F980(*(void**)((char*)self + 0x28));
    func_002CC0B8(*(void**)((char*)self + 0xA4), 1);
    func_002CC460(*(void**)((char*)self + 0xA4));
    D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230640);
#ifdef SKIP_ASM
extern "C" void func_003550A0(void* mgr, int id);
struct sGp2898 { int a, b; };
extern sGp2898 D_004A5988; // target: raw $gp+0x2898 (splat doesn't symbolize it)
extern int D_004428D8[];

extern "C" void func_00230640(void)
{
    int i;
    sGp2898* mgr = &D_004A5988;
    for (i = 0; i < 6; i++) {
        func_003550A0(mgr, D_004428D8[i]);
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230698__FPvi);
#ifdef SKIP_ASM
void* func_00230698(void* self, int i)
{
    return *(void**)((char*)self + (i << 2) + 0x5C);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_002306A8__FPvi);
#ifdef SKIP_ASM
void* func_002306A8(void* self, int i)
{
    return *(void**)((char*)self + (i << 2) + 0x68);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_002306B8);
#ifdef SKIP_ASM
extern "C" float func_002EE400(int id);
extern "C" void func_002570D8(void* p);
extern "C" void func_00278918(void* world);
extern "C" void func_00231D18(void* self);
extern "C" int func_0022E920(void* views);
extern "C" void cGameViewMan_updateAll(void* views);
extern "C" void func_00230F40(void* self);
extern "C" void func_0022E8B8(void* views);
extern "C" void func_003A88A8(void* p);
extern "C" void func_002373B8(void* p);
extern "C" void func_0020CFD0(void);
extern "C" int func_002CC098(void* p);
extern "C" void func_0020AB50(int id);
extern "C" void func_0029CED8(void* snd, int a, int b, float f);
extern "C" void func_0030A868(void* mgr, int a, int b, int c);
extern "C" void func_00398038(void* p);
extern "C" void func_0029ED18(void* snd);
extern "C" void func_002CC0C0(void* p);
extern "C" int func_00231840(char* self, int a);
extern "C" int func_0020CBE8(void);
extern "C" void func_00326AE0(void* p);
extern "C" void func_0020CA10(void);
extern "C" void func_00289B70(void* snd);
extern "C" void func_00294F48(void* snd);
extern "C" int func_0020CBA0(void);
extern "C" void cPlaybackMan_update(void* p);
extern "C" int func_00237950(void* p);
extern "C" void func_0026F4A8(void* p);
extern "C" int func_00270280(void* p);
extern "C" int func_002379C8(void* p);
extern "C" int func_0026CE50(void* p);
extern "C" void func_00354F98(void* mgr, int a);
extern "C" void func_00355028(void* mgr, int a);
extern "C" void func_00309270(void* p);
extern "C" void func_002294C8(void* p);
extern "C" void func_003440C8(void* p);
extern "C" void func_00357BF8(void* p);
extern "C" void func_002B7848(void* p, void* a, int i);
void func_00237948(void* p);
extern "C" void func_003F42A0(void);
extern "C" void func_001A39F0(void* p);
extern "C" void func_001E1458(void);
extern "C" void func_001F3188(void* p);
extern char* D_004A5B64;
extern void* D_004A2EB8;
extern void* D_004A28A0;
// Pending script pause request; 0xFFFFFFFF = none (the store is lui/ori, so the global is unsigned).
extern unsigned int D_004A20CC;
extern int D_004A2A50;
extern int D_004A2A54;
extern int D_005366E8[];
extern int D_004428F8[];
extern int D_004428FC[];
extern int D_00442920[];
extern char D_0047B798[];

// A script message (cWScriptQueueEntry).
struct sMsg_06B8 {
    int a;
    int type;
    int c;
};

// The script manager's message queue (wscript/wscriptman: cWScriptQueue).
struct sQueue_06B8 {
    int head;
    int tail;
    sMsg_06B8 entries[16];
};

extern "C" sMsg_06B8* func_0030C870(sQueue_06B8* self);
extern "C" sMsg_06B8* func_0030C820(sQueue_06B8* self);

// The script manager (D_004A3DD8); hasMessage / popMessage are inline here
// (out-of-line copies: func_0030D330, func_0030D348).
struct sScript_06B8 {
    char pad0[0x1C4];
    sQueue_06B8 queue;              // 0x1C4
    bool hasMessage() { return queue.head != queue.tail; }
    sMsg_06B8* popMessage() { return func_0030C820(&queue); }
};

struct sVSlot_06B8 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

struct sUIObj_06B8 {
    char pad0[0x8];
    sVSlot_06B8* vt;                // 0x8
};

struct sStateStack_06B8 {
    void* top;
};

struct sUIEngine_06B8 {
    char pad0[0xC];
    sUIObj_06B8* fC;                // 0xC
    char pad10[0x18 - 0x10];
    sStateStack_06B8 states;        // 0x18
};

struct sViews_06B8 {
    char pad0[0x4];
    char* players[3];               // 0x4
    unsigned int numPlayers;        // 0x10
    unsigned int getNumPlayers() { return numPlayers; }
    char* getPlayer(unsigned int id) { return players[id]; }
};

struct sRace_06B8 {
    char pad0[0x28];
    char* riders[0x14];             // 0x28
    int numRiders;                  // 0x78
    int getNumRiders() { return numRiders; }
    char* getRider(int idx) { return riders[idx]; }
    char pad7C[0xCC - 0x7C];
    sVSlot_06B8* vt;                // 0xCC
};

struct sGame_06B8 {
    char pad0[0x8];
    int quit;                       // 0x8
    sRace_06B8* race;               // 0xC
    char** f10;                     // 0x10
    char pad14[0x28 - 0x14];
    int* state;                     // 0x28
    char pad2C[0x30 - 0x2C];
    sScript_06B8* script;           // 0x30
    char* playback;                 // 0x34
    void* f38;                      // 0x38
    void* f3C;                      // 0x3C
    void* f40;                      // 0x40
    char pad44[0x48 - 0x44];
    sUIEngine_06B8* ui;             // 0x48
    void* f4C;                      // 0x4C
    char pad50[0x78 - 0x50];
    char* f78;                      // 0x78
    void* f7C;                      // 0x7C
    char pad80[0x84 - 0x80];
    sViews_06B8* views;             // 0x84
    char pad88[0x94 - 0x88];
    void* f94;                      // 0x94
    char pad98[0x9C - 0x98];
    int f9C;                        // 0x9C
    int fA0;                        // 0xA0
    void* fA4;                      // 0xA4
    char padA8[0xAC - 0xA8];
    int frame;                      // 0xAC
    char padB0[0x214 - 0xB0];
    int f214;                       // 0x214
    char pad218[0x228 - 0x218];
    unsigned char f228;             // 0x228
};

static inline bool racing_06B8(int s)
{
    return s != 0 && s < 10;
}

static inline bool pending_06B8()
{
    return D_004A20CC != 0xFFFFFFFF;
}

static inline bool playing_06B8(char* pb)
{
    return *(int*)(pb + 0x70) == 1;
}

static inline bool stateIs_06B8(int* st, int k)
{
    return *st == k;
}

// Returns false (and flags the game to quit) once the app asked to quit.
static inline bool checkQuit_06B8(sGame_06B8* self)
{
    if (*(int*)((char*)D_004A28A8 + 4) != 0) {
        self->quit = 1;
        return false;
    }
    return true;
}

// Runs the loading phase; returns true once the views and the world are ready.
static inline bool updateLoading_06B8(sGame_06B8* self)
{
    if (func_0022E920(self->views) == 0 || *(int*)(self->f78 + 0x1D0) == 0) {
        *(int*)(*self->f10 + 0x3D4) = 0;
        func_003A6928(self->f10);
        cGameViewMan_updateAll(self->views);
        if (*(int*)(self->f78 + 0x1D0) == 0) {
            func_00230F40(self);
            func_0022D8D8(self->f78);
        }
        if (self->f9C == 0 && func_0022E920(self->views) == 0) {
            self->fA0 = 1;
        }
        self->f9C = 1;
        if (self->fA0 != 0) {
            char* m = (char*)D_004A289C;
            sVSlot_06B8* vt = *(sVSlot_06B8**)(m + 0x10D8);
            vt[19].fn(m + vt[19].delta);
            func_0022E8B8(self->views);
            func_003A88A8(*self->f10);
            self->fA0 = 0;
        }
        return false;
    }
    *(int*)(*self->f10 + 0x3D4) = 1;
    self->f9C = 0;
    self->fA0 = 0;
    func_003A6928(self->f10);
    func_0022D8D8(self->f78);
    return true;
}

// Handles script messages and pause requests; returns true when the race should run this frame.
static inline bool updateMessages_06B8(sGame_06B8* self)
{
    if (func_002CC098(self->fA4) == 0) {
        sScript_06B8* sm = self->script;
        sQueue_06B8* q = &sm->queue;
        if (sm->hasMessage()) {
            sMsg_06B8* msg = func_0030C870(q);
            if (msg->type == 8) {
                func_0020AB50(0x1D);
                D_005366E8[++D_004A2A54] = 3;
                D_004A2A50 = D_004428FC[0];
                func_0029CED8(func_0028B180(), 4, 0, 1.0f);
                return false;
            }
            if (msg->type == 9) {
                func_0030A868(self->script, msg->a, 5, msg->c);
                if (func_0039F9D8(&self->ui->states, GetHashValue32(D_0047B798)) == 0) {
                    func_0020AB50(0x1E);
                    D_005366E8[++D_004A2A54] = 3;
                    D_004A2A50 = D_004428FC[0];
                    func_00398038(self->ui);
                } else {
                    ((sScript_06B8*)D_004A3DD8)->popMessage();
                }
                return false;
            }
        }
    }
    if (pending_06B8()) {
        func_0020AB50(0x22);
        D_005366E8[++D_004A2A54] = 0xC;
        D_004A2A50 = D_00442920[0];
        D_004A20CC = 0xFFFFFFFF;
        func_0029ED18(func_0028B180());
        return false;
    }
    if (func_002CC098(self->fA4) != 0) {
        func_00398038(self->ui);
        func_002CC0C0(self->fA4);
        return false;
    }
    if (func_00231840((char*)self, 0) != 0 && !racing_06B8(*self->state) && !playing_06B8(self->playback) && func_0020CBE8() != 0) {
        func_00326AE0(D_004A28A0);
        func_0020CA10();
        D_005366E8[++D_004A2A54] = 2;
        D_004A2A50 = D_004428F8[0];
        sUIObj_06B8* o = self->ui->fC;
        o->vt[44].fn((char*)o + o->vt[44].delta, self->f228);
        func_00289B70(func_0028B180());
        func_00294F48(func_0028B180());
        return false;
    }
    int wasPaused = D_004A2A50 & 1;
    func_00398038(self->ui);
    if (func_0020CBA0() != 0) {
        return false;
    }
    cPlaybackMan_update(self->playback);
    if (func_002CC098(self->fA4) != 0) {
        return false;
    }
    if (wasPaused && (D_004A2A50 & 1) == 0) {
        return false;
    }
    return true;
}

static inline void updateRace_06B8(sGame_06B8* self)
{
    if (self->f7C == 0 || func_00237950(self->f7C) != 0) {
        if (self->f214 == 3) {
            func_00230F40(self);
            func_00354C98(&D_004A5988, 1);
        } else {
            func_00230F40(self);
        }
        if ((D_004A2A50 & 1) == 0) {
            func_0026F4A8(self->state);
        }
        if (func_00270280(self->state) == 0 && (D_004A2A50 & 8) == 0) {
            char* w = (char*)D_004A28A4;
            sVSlot_06B8* vt = *(sVSlot_06B8**)(w + 0x2A8);
            vt[5].fn(w + vt[5].delta);
        }
    }
    int skip = 0;
    if ((D_004A2A50 & 1) != 0 || func_00270280(self->state) != 0) {
        skip = 1;
    }
    if (!skip && ((self->f7C != 0 && func_002379C8(self->f7C) == 0) || func_0026CE50(self->playback) != 0)) {
        skip = 1;
    }
    if (!skip) {
        if ((D_004A2A50 & 2) == 0) {
            func_00354F98(&D_004A5988, 1);
        }
        func_00354F98(&D_004A5988, 5);
        func_00354F98(&D_004A5988, 6);
        if ((D_004A2A50 & 2) == 0) {
            func_00355028(&D_004A5988, 1);
        }
        sRace_06B8* r = self->race;
        r->vt[3].fn((char*)r + r->vt[3].delta);
        if ((D_004A2A50 & 0x10) == 0) {
            func_00354F98(&D_004A5988, 2);
        }
        if ((D_004A2A50 & 4) == 0) {
            func_00354F98(&D_004A5988, 3);
        }
        func_00309270(self->script);
        func_002294C8(self->f38);
        func_003440C8(self->f3C);
        func_00357BF8(self->f40);
        func_00354C98(&D_004A5988, 1);
    } else {
        func_00354F98(&D_004A5988, 5);
        if ((D_004A2A50 & 4) == 0) {
            func_00354F98(&D_004A5988, 3);
        }
    }
    func_00354F98(&D_004A5988, 4);
    if (!racing_06B8(*self->state) || !stateIs_06B8(self->state, 3)) {
        cGameViewMan_updateAll(self->views);
    }
    self->frame++;
    unsigned int i;
    for (i = 0; i < self->views->getNumPlayers(); i++) {
        func_002B7848(self->f4C, self->views->getPlayer(i) + 0x20, i);
    }
    int j;
    for (j = 0; j < self->race->getNumRiders(); j++) {
        char* rd = self->race->getRider(j);
        sVSlot_06B8* vt = *(sVSlot_06B8**)(rd + 0x6C0);
        vt[19].fn(rd + vt[19].delta);
    }
}

extern "C" void func_002306B8(sGame_06B8* self)
{
    if (self->views->numPlayers >= 2) {
        *(int*)(D_004A5B64 + 0x34) = 1;
    } else {
        *(int*)(D_004A5B64 + 0x34) = func_002EE400(6) > 0.9f;
    }
    if (D_004A2EEC != 0) {
        func_002570D8(D_004A2EEC);
    }
    func_00278918(D_004A28A4);
    func_00231D18(self);
    if (checkQuit_06B8(self) && updateLoading_06B8(self)) {
        if (self->f7C != 0) {
            func_002373B8(self->f7C);
        }
        func_0020CFD0();
        if (updateMessages_06B8(self)) {
            updateRace_06B8(self);
        }
        if (self->f7C != 0) {
            func_00237948(self->f7C);
        }
    }
    if (D_004A2EB8 != 0) {
        func_003F42A0();
    }
    if (*(void**)((char*)D_004A28A8 + 0x11C) != 0) {
        func_001A39F0(*(void**)((char*)D_004A28A8 + 0x11C));
    }
    func_001E1458();
    func_001F3188(self->f94);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230E90);
#ifdef SKIP_ASM
extern "C" void func_00230E90(void) {

}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230E98);
#ifdef SKIP_ASM
extern "C" int func_00231CF0(void* self);
void func_00278718(void* self);
void func_001F3170(void* self);

struct sVEntry00230E98 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sVec3_00230E98 {
    float x, y, z;
    sVec3_00230E98(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
struct cMgr00230E98 {
    char pad0[0x270];
    int f270;
    char pad274[0x10D8 - 0x274];
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
    virtual void v15(const sVec3_00230E98& v);
};

extern "C" int func_00230E98(void* self)
{
    void* obj = *(void**)((char*)self + 0x98);
    sVEntry00230E98* vt = *(sVEntry00230E98**)obj;
    if (vt[3].fn((char*)obj + vt[3].delta) == 0) {
        return 0;
    }
    if (func_00231CF0(self) == 0) {
        return 0;
    }
    cMgr00230E98* mgr = (cMgr00230E98*)D_004A289C;
    mgr->v15(sVec3_00230E98(0.0f, 0.0f, 0.0f));
    ((cMgr00230E98*)D_004A289C)->f270 = 1;
    D_004A4324 = 0;
    D_004A45D8 = 0;
    D_004A43C8 = 0;
    func_00278718(D_004A28A4);
    func_001F3170(*(void**)((char*)self + 0x94));
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00230F40);
#ifdef SKIP_ASM
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0022E550(void* self);
extern void* D_004A28A8;
extern int D_004A2A50;
extern int D_00534B30[];

class cGameState_0F40 {
public:
    int pad[3];
    virtual void v01();
    virtual void enter();
    virtual void update();
    virtual void v04();
    virtual void start(int arg);
    virtual void tick();
    virtual void exit();
};

struct sGameLoad_0F40 {
    char pad0[0x84];
    void* loader;                   // 0x84
    char pad88[0x174];
    cGameState_0F40* prev;          // 0x1FC
    cGameState_0F40* cur;           // 0x200
    cGameState_0F40* pending;       // 0x204
    int pendingId;                  // 0x208
    int enteredId;                  // 0x20C
    int nextId;                     // 0x210
    int curId;                      // 0x214
    int prevId;                     // 0x218
    int nextArg;                    // 0x21C
    char pad220[0x4];
    int hold;                       // 0x224
};

// Game load state machine: runs the current state and switches to the requested one.
extern "C" void func_00230F40(void* self_)
{
    sGameLoad_0F40* self = (sGameLoad_0F40*)self_;
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] == 0 && self->hold != 0)
        return;
    if (D_004A2A50 & 0x20)
        return;
    if (self->cur != 0 && (self->curId != 3 || self->nextId == 0))
        self->cur->tick();
    if (self->pendingId != 0) {
        switch (self->pendingId) {
    case 1:
        self->pending = (cGameState_0F40*)((char*)self + 0xB0);
        break;
    case 2:
        self->pending = (cGameState_0F40*)((char*)self + 0xD0);
        break;
    case 3:
        self->pending = (cGameState_0F40*)((char*)self + 0xE0);
        break;
    case 4:
        self->pending = (cGameState_0F40*)((char*)self + 0xF0);
        break;
    case 5:
        self->pending = (cGameState_0F40*)((char*)self + 0x100);
        break;
    case 6:
        self->pending = (cGameState_0F40*)((char*)self + 0x118);
        break;
    case 7:
        self->pending = (cGameState_0F40*)((char*)self + 0x128);
        break;
    case 8:
        self->pending = (cGameState_0F40*)((char*)self + 0x138);
        break;
    case 9:
        self->pending = (cGameState_0F40*)((char*)self + 0x148);
        break;
    case 10:
        self->pending = (cGameState_0F40*)((char*)self + 0x158);
        break;
    case 11:
        self->pending = (cGameState_0F40*)((char*)self + 0x178);
        break;
    case 12:
        self->pending = (cGameState_0F40*)((char*)self + 0x18C);
        break;
    case 13:
        self->pending = (cGameState_0F40*)((char*)self + 0x19C);
        break;
    case 14:
        self->pending = (cGameState_0F40*)((char*)self + 0x1B8);
        break;
    case 15:
        self->pending = (cGameState_0F40*)((char*)self + 0x1DC);
        break;
    case 16:
        self->pending = (cGameState_0F40*)((char*)self + 0x1EC);
        break;
        }
        self->enteredId = self->pendingId;
        self->pendingId = 0;
        self->pending->enter();
    }
    if (self->pending != 0)
        self->pending->update();
    int next = self->nextId;
    if (next == 0)
        return;
    int arg = self->nextArg;
    if (self->cur != 0)
        self->cur->exit();
    self->prevId = self->curId;
    self->prev = self->cur;
    switch (next) {
    case 1:
        self->cur = (cGameState_0F40*)((char*)self + 0xB0);
        self->curId = 1;
        break;
    case 2:
        self->cur = (cGameState_0F40*)((char*)self + 0xD0);
        self->curId = 2;
        break;
    case 3:
        self->cur = (cGameState_0F40*)((char*)self + 0xE0);
        self->curId = 3;
        break;
    case 4:
        self->cur = (cGameState_0F40*)((char*)self + 0xF0);
        self->curId = 4;
        break;
    case 5:
        self->cur = (cGameState_0F40*)((char*)self + 0x100);
        self->curId = 5;
        break;
    case 6:
        self->cur = (cGameState_0F40*)((char*)self + 0x118);
        self->curId = 6;
        break;
    case 7:
        self->cur = (cGameState_0F40*)((char*)self + 0x128);
        self->curId = 7;
        break;
    case 8:
        self->cur = (cGameState_0F40*)((char*)self + 0x138);
        self->curId = 8;
        break;
    case 9:
        self->cur = (cGameState_0F40*)((char*)self + 0x148);
        self->curId = 9;
        break;
    case 10:
        self->cur = (cGameState_0F40*)((char*)self + 0x158);
        self->curId = 10;
        break;
    case 11:
        self->cur = (cGameState_0F40*)((char*)self + 0x178);
        self->curId = 11;
        break;
    case 12:
        self->cur = (cGameState_0F40*)((char*)self + 0x18C);
        self->curId = 12;
        break;
    case 13:
        self->cur = (cGameState_0F40*)((char*)self + 0x19C);
        self->curId = 13;
        break;
    case 14:
        self->cur = (cGameState_0F40*)((char*)self + 0x1B8);
        self->curId = 14;
        break;
    case 15:
        self->cur = (cGameState_0F40*)((char*)self + 0x1DC);
        self->curId = 15;
        break;
    case 16:
        self->cur = (cGameState_0F40*)((char*)self + 0x1EC);
        self->curId = 16;
        break;
    }
    self->nextId = 0;
    self->nextArg = 0;
    if (self->enteredId == self->curId) {
        self->enteredId = 0;
        self->pending = 0;
    }
    if (self->cur != 0) {
        func_0022E550(self->loader);
        self->cur->start(arg);
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231250);
#ifdef SKIP_ASM
extern "C" void func_00230F40(void* self);

extern "C" void func_00231250(void* self, int a, int b, int refresh)
{
    *(int*)((char*)self + 0x210) = a;
    *(int*)((char*)self + 0x21C) = b;
    if (refresh != 0) {
        func_00230F40(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231278__FPvi);
#ifdef SKIP_ASM
void func_00231278(void* self, int val)
{
    *(int*)((char*)self + 0x208) = val;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231280);
#ifdef SKIP_ASM
extern "C" void func_00231280(void *self) {
    void *obj;
    void *vtbl;

    if (*(int *)((char*)self + 0x208) != 0) {
        *(int *)((char*)self + 0x208) = 0;
    }
    if (*(int *)((char*)self + 0x20C) != 0) {
        obj = *(void **)((char*)self + 0x204);
        vtbl = *(void **)((char*)obj + 0xC);
        (*(void (**)(void *))((char*)vtbl + 0x24))((char*)obj + *(short *)((char*)vtbl + 0x20));
        *(int *)((char*)self + 0x20C) = 0;
        *(void **)((char*)self + 0x204) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_002312D8);
#ifdef SKIP_ASM
struct sVEntry_002312D8 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_002312D8(void* self)
{
    if (*(int*)((char*)self + 0x208) != 0) {
        return 0;
    }
    void* p = *(void**)((char*)self + 0x204);
    if (p == 0) {
        return 1;
    }
    sVEntry_002312D8* vt = *(sVEntry_002312D8**)((char*)p + 0xC);
    return vt[8].fn((char*)p + vt[8].delta);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231320);
#ifdef SKIP_ASM
extern "C" void func_00233AA0(void* p);

extern "C" void func_00231320(void* self)
{
    void* p = *(void**)((char*)self + 0x200);
    if (p != 0) {
        func_00233AA0(p);
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231348);
#ifdef SKIP_ASM
struct cSerObj_00231348 {
    int f0, f4, f8;
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
    virtual void serialize(void* stream);
};
struct cStream_00231348 {
    virtual void write(void* p, int n);
};

// PORT: these serializers take (self, stream); their mangled names say (void*).
void func_00233B90_s(void* p, void* s) __asm__("func_00233B90__FPv");
void func_00233BD0_s(void* p, void* s) __asm__("func_00233BD0__FPv");
void func_00234DE0_s(void* p, void* s) __asm__("func_00234DE0__FPv");
void func_00234EB8_s(void* p, void* s) __asm__("func_00234EB8__FPv");
void func_002361C8_s(void* p, void* s) __asm__("func_002361C8__FPv");
void func_00236AF8_s(void* p, void* s) __asm__("func_00236AF8__FPv");
void func_00236B70_s(void* p, void* s) __asm__("func_00236B70__FPv");
void func_00236D60_s(void* p, void* s) __asm__("func_00236D60__FPv");
void func_00236EC8_s(void* p, void* s) __asm__("func_00236EC8__FPv");
void func_00236FA8_s(void* p, void* s) __asm__("func_00236FA8__FPv");
extern "C" void func_002340B8(void* p, void* s);
extern "C" void func_00234990(void* p, void* s);
extern "C" void func_00235990(void* p, void* s);
extern "C" void func_00235F48(void* p, void* s);
extern "C" void func_00236728(void* p, void* s);

extern "C" void func_00231348(void* self, cStream_00231348* stream)
{
    (*(cSerObj_00231348**)((char*)self + 0x70))->serialize(stream);
    (*(cSerObj_00231348**)((char*)self + 0x74))->serialize(stream);
    stream->write((char*)self + 0x214, 4);
    stream->write((char*)self + 0x218, 4);
    stream->write((char*)self + 0x210, 4);
    stream->write((char*)self + 0x21C, 4);
    func_00234990((char*)self + 0xB0, stream);
    func_00236D60_s((char*)self + 0xD0, stream);
    func_00234DE0_s((char*)self + 0xE0, stream);
    func_00234EB8_s((char*)self + 0xF0, stream);
    func_002340B8((char*)self + 0x100, stream);
    func_00233B90_s((char*)self + 0x118, stream);
    func_00236EC8_s((char*)self + 0x128, stream);
    func_00233BD0_s((char*)self + 0x138, stream);
    func_00236B70_s((char*)self + 0x148, stream);
    func_00235990((char*)self + 0x158, stream);
    func_00236AF8_s((char*)self + 0x178, stream);
    func_00236FA8_s((char*)self + 0x18C, stream);
    func_00235F48((char*)self + 0x19C, stream);
    func_00236728((char*)self + 0x1B8, stream);
    func_002361C8_s((char*)self + 0x1DC, stream);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_002314D0);
#ifdef SKIP_ASM
// PORT: these state loaders are declared with one parameter in their units; this caller also passes the stream.
extern "C" void func_00234A30(void* state, void* stream);
void func_00236D80_14D0(void* state, void* stream) __asm__("func_00236D80__FPv");
void func_00234E00_14D0(void* state, void* stream) __asm__("func_00234E00__FPv");
void func_00234ED8_14D0(void* state, void* stream) __asm__("func_00234ED8__FPv");
extern "C" void func_00234120(void* state, void* stream);
void func_00233BB0_14D0(void* state, void* stream) __asm__("func_00233BB0__FPv");
void func_00236EE8_14D0(void* state, void* stream) __asm__("func_00236EE8__FPv");
void func_00233BF0_14D0(void* state, void* stream) __asm__("func_00233BF0__FPv");
void func_00236B90_14D0(void* state, void* stream) __asm__("func_00236B90__FPv");
extern "C" void func_00235A18(void* state, void* stream);
void func_00236B18_14D0(void* state, void* stream) __asm__("func_00236B18__FPv");
void func_00236FC8_14D0(void* state, void* stream) __asm__("func_00236FC8__FPv");
extern "C" void func_00235FD0(void* state, void* stream);
extern "C" void func_002367C8(void* state, void* stream);
void func_002361E8_14D0(void* state, void* stream) __asm__("func_002361E8__FPv");

class cGameState_14D0;

class cStream_14D0 {
public:
    virtual void v01();
    virtual void read(void* dst, int size);
};

class cLoadable_14D0 {
public:
    int pad[3];
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
    virtual void load(cStream_14D0* stream);
};

struct sGameLoad_14D0 {
    char pad0[0x70];
    cLoadable_14D0* a;              // 0x70
    cLoadable_14D0* b;              // 0x74
    char pad78[0x184];
    cGameState_14D0* prev;          // 0x1FC
    cGameState_14D0* cur;           // 0x200
    char pad204[0xC];
    int nextId;                     // 0x210
    int curId;                      // 0x214
    int prevId;                     // 0x218
    int nextArg;                    // 0x21C
};

// Game load state machine: restores the state ids and every state from a save stream.
extern "C" void func_002314D0(void* self_, cStream_14D0* stream)
{
    sGameLoad_14D0* self = (sGameLoad_14D0*)self_;
    self->a->load(stream);
    self->b->load(stream);
    stream->read(&self->curId, 4);
    stream->read(&self->prevId, 4);
    stream->read(&self->nextId, 4);
    stream->read(&self->nextArg, 4);
    func_00234A30((char*)self + 0xB0, stream);
    func_00236D80_14D0((char*)self + 0xD0, stream);
    func_00234E00_14D0((char*)self + 0xE0, stream);
    func_00234ED8_14D0((char*)self + 0xF0, stream);
    func_00234120((char*)self + 0x100, stream);
    func_00233BB0_14D0((char*)self + 0x118, stream);
    func_00236EE8_14D0((char*)self + 0x128, stream);
    func_00233BF0_14D0((char*)self + 0x138, stream);
    func_00236B90_14D0((char*)self + 0x148, stream);
    func_00235A18((char*)self + 0x158, stream);
    func_00236B18_14D0((char*)self + 0x178, stream);
    func_00236FC8_14D0((char*)self + 0x18C, stream);
    func_00235FD0((char*)self + 0x19C, stream);
    func_002367C8((char*)self + 0x1B8, stream);
    func_002361E8_14D0((char*)self + 0x1DC, stream);
    switch (self->curId) {
    case 0:
        self->cur = 0;
        break;
    case 1:
        self->cur = (cGameState_14D0*)((char*)self + 0xB0);
        break;
    case 2:
        self->cur = (cGameState_14D0*)((char*)self + 0xD0);
        break;
    case 3:
        self->cur = (cGameState_14D0*)((char*)self + 0xE0);
        break;
    case 4:
        self->cur = (cGameState_14D0*)((char*)self + 0xF0);
        break;
    case 5:
        self->cur = (cGameState_14D0*)((char*)self + 0x100);
        break;
    case 6:
        self->cur = (cGameState_14D0*)((char*)self + 0x118);
        break;
    case 7:
        self->cur = (cGameState_14D0*)((char*)self + 0x128);
        break;
    case 8:
        self->cur = (cGameState_14D0*)((char*)self + 0x138);
        break;
    case 9:
        self->cur = (cGameState_14D0*)((char*)self + 0x148);
        break;
    case 10:
        self->cur = (cGameState_14D0*)((char*)self + 0x158);
        break;
    case 11:
        self->cur = (cGameState_14D0*)((char*)self + 0x178);
        break;
    case 12:
        self->cur = (cGameState_14D0*)((char*)self + 0x18C);
        break;
    case 13:
        self->cur = (cGameState_14D0*)((char*)self + 0x19C);
        break;
    case 14:
        self->cur = (cGameState_14D0*)((char*)self + 0x1B8);
        break;
    case 15:
        self->cur = (cGameState_14D0*)((char*)self + 0x1DC);
        break;
    case 16:
        self->cur = (cGameState_14D0*)((char*)self + 0x1EC);
        break;
    default:
        self->cur = 0;
        self->curId = 0;
        break;
    }
    switch (self->prevId) {
    case 1:
        self->prev = (cGameState_14D0*)((char*)self + 0xB0);
        break;
    case 2:
        self->prev = (cGameState_14D0*)((char*)self + 0xD0);
        break;
    case 3:
        self->prev = (cGameState_14D0*)((char*)self + 0xE0);
        break;
    case 4:
        self->prev = (cGameState_14D0*)((char*)self + 0xF0);
        break;
    case 5:
        self->prev = (cGameState_14D0*)((char*)self + 0x100);
        break;
    case 6:
        self->prev = (cGameState_14D0*)((char*)self + 0x118);
        break;
    case 7:
        self->prev = (cGameState_14D0*)((char*)self + 0x128);
        break;
    case 8:
        self->prev = (cGameState_14D0*)((char*)self + 0x138);
        break;
    case 9:
        self->prev = (cGameState_14D0*)((char*)self + 0x148);
        break;
    case 10:
        self->prev = (cGameState_14D0*)((char*)self + 0x158);
        break;
    case 11:
        self->prev = (cGameState_14D0*)((char*)self + 0x178);
        break;
    case 12:
        self->prev = (cGameState_14D0*)((char*)self + 0x18C);
        break;
    case 13:
        self->prev = (cGameState_14D0*)((char*)self + 0x19C);
        break;
    case 14:
        self->prev = (cGameState_14D0*)((char*)self + 0x1B8);
        break;
    case 15:
        self->prev = (cGameState_14D0*)((char*)self + 0x1DC);
        break;
    case 16:
        self->prev = (cGameState_14D0*)((char*)self + 0x1EC);
        break;
    default:
        self->prevId = 0;
    case 0:
        self->prev = 0;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231840);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern void* D_004A2EEC;
extern int D_004A2E9C;
extern int D_00534B30[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00147290(void* iface, int i);
extern "C" int func_00231AB8(void* self);
int func_00320C48(void* obj, int a1);

static inline void** PlayerObj_1840(int p)
{
    return *(void***)((char*)D_004A28A8 + (p << 2) + 0xB0);
}

static inline int IsReady_1840(void** o)
{
    return *o && *(int*)*o;
}

static inline int Count_1840(char* self)
{
    return *(int*)(*(char**)(self + 0xC) + 0x7C);
}

static inline char* At_1840(char* self, int i)
{
    return *(char**)(*(char**)(self + 0xC) + (i << 2) + 0x40);
}

extern "C" int func_00231840(char* self, int a)
{
    if (D_004A2EEC != 0 && *(int*)((char*)D_004A2EEC + 0x8) > 0) {
        return 0;
    }
    int mask = 0;
    void* bi = cBE_getInterface_Fv(cBE_getBE(), 1);
    char* g = *(char**)(self + 0x28);
    int sel = -1;
    if (*(int*)(g + 0x608)) {
        int p = *(int*)(g + 0x28);
        void** o = PlayerObj_1840(p);
        if (!IsReady_1840(o)) {
            mask = 1 << p;
        } else if (D_004A2E9C == 0) {
            if (func_00320C48(o, 0x3C)) {
                sel = p;
            }
        }
    } else {
        int i;
        for (i = 0; i < Count_1840(self); i++) {
            char* r = At_1840(self, i);
            if (*(int*)(*(char**)(r + 0x18) + 0x87C)) {
                int p = func_00147290(bi, i);
                void** o = PlayerObj_1840(p);
                if (!IsReady_1840(o)) {
                    mask |= 1 << p;
                } else if (sel < 0 && D_004A2E9C == 0) {
                    if (func_00320C48(o, 0x3C)) {
                        sel = p;
                    }
                }
            }
        }
    }
    *(int*)(self + 0x224) = mask;
    if (mask) {
        if (sel < 0) {
            int i;
            sel = 0;
            for (i = 0; i < Count_1840(self); i++) {
                char* r = At_1840(self, i);
                if (*(int*)(*(char**)(r + 0x18) + 0x87C)) {
                    int p = func_00147290(bi, i);
                    if (IsReady_1840(PlayerObj_1840(p))) {
                        sel = p;
                        break;
                    }
                }
            }
        }
        *(int*)(self + 0x228) = sel;
        return 1;
    }
    if (sel >= 0) {
        cBE_getInterface_Fv(cBE_getBE(), 7);
        if (D_00534B30[0] != 0 || func_00231AB8(self)) {
            *(int*)(self + 0x228) = sel;
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231AB8);
#ifdef SKIP_ASM
extern "C" int func_00278DA0(void* a);
extern void* D_004A28A4;

extern "C" int func_00231AB8(void* self)
{
    int mode = *(int*)((char*)self + 0x210);
    if (mode != 0) {
        if (mode == 5 || mode == 14 || mode == 1 || mode == 10) {
            return 0;
        }
    }
    int r = 0;
    if (func_00278DA0(D_004A28A4) != 0) {
        int m = *(int*)((char*)self + 0x214);
        r = m != 5 && m != 14 && m != 1 && m != 10;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231B50);
#ifdef SKIP_ASM
struct sV4_231B50 {
    float v[4];
} __attribute__((aligned(16)));

struct sVtx_231B50 {
    float s;
    float t;
    float q;
    int padC;
    int col[4];
    sV4_231B50 pos;
    sVtx_231B50() {}
};

struct sVE_231B50 { short delta; short index; void* fn; };
typedef void (*tDraw_231B50)(void*, int, void*, int);
extern char* D_004A289C_231B50 __asm__("D_004A289C");

extern "C" void func_00231B50(int unused, int fb)
{
    sVtx_231B50 vtx[4];
    sV4_231B50 tt;
    for (int i = 0; i < 4; i++) {
        vtx[i].col[3] = 0x80;
        vtx[i].col[0] = 0x80;
        vtx[i].col[1] = 0x80;
        vtx[i].col[2] = 0x80;
        vtx[i].q = 1.0f;
    }
    tt.v[0] = 0.0f; tt.v[1] = 0.0f; tt.v[2] = 0.0f; tt.v[3] = 1.0f;
    vtx[0].pos = tt;
    tt.v[0] = 1.0f; tt.v[1] = 0.0f; tt.v[2] = 0.0f;
    vtx[1].pos = tt;
    tt.v[0] = 0.0f; tt.v[1] = 1.0f; tt.v[2] = 0.0f;
    vtx[2].pos = tt;
    tt.v[0] = 1.0f; tt.v[1] = 1.0f; tt.v[2] = 0.0f;
    vtx[3].pos = tt;
    vtx[0].s = 0.0f; vtx[0].t = 0.0f;
    vtx[1].s = 1.0f; vtx[1].t = 0.0f;
    vtx[2].s = 0.0f; vtx[2].t = 1.0f;
    vtx[3].s = 1.0f; vtx[3].t = 1.0f;
    *(short*)(*(char**)(D_004A289C_231B50 + 0xE84) + 0x10) = fb;
    sVE_231B50* vt = *(sVE_231B50**)(D_004A289C_231B50 + 0x10D8);
    ((tDraw_231B50)vt[71].fn)(D_004A289C_231B50 + vt[71].delta, 4, vtx, 0);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231C70);
#ifdef SKIP_ASM
extern "C" int func_00231CF0(void* self);
extern char* D_004A5B64;

extern "C" int func_00231C70(void* self)
{
    if (*(float*)(D_004A5B64 + 0x38) == 100.0f) {
        return func_00231CF0(self);
    }
    return 0;
}
#endif

extern "C" void func_00231D18(void* self);

//100%
INCLUDE_ASM("main/gameload", func_00231CB0__FPv);
#ifdef SKIP_ASM
void func_00231CB0(void* self)
{
    func_00231D18(self);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231CD0);
#ifdef SKIP_ASM
extern char D_0047D980[];

extern "C" void* func_00231CD0(void* self)
{
    *(void**)((char*)self + 0) = D_0047D980;
    *(float*)((char*)self + 4) = 0.20000000298023224f;
    *(int*)((char*)self + 8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231CF0);
#ifdef SKIP_ASM
extern "C" int func_00231CF0(void* self)
{
    *(int*)((char*)self + 8) = 1;
    return *(float*)((char*)self + 4) >= 0.20000000298023224f;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231D18);
#ifdef SKIP_ASM
// PORT: the unit declares this void*-returning; the body returns nothing meaningful.
extern "C" void func_00231D18(void* self)
{
    if (*(int*)((char*)self + 8) != 0) {
        *(float*)((char*)self + 4) += 0.01666666753590107f;
    } else {
        *(float*)((char*)self + 4) -= 0.01666666753590107f;
        if (*(float*)((char*)self + 4) < 0.0f) {
            *(float*)((char*)self + 4) = 0.0f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231D60);
#ifdef SKIP_ASM
extern "C" void func_0038EC40(void* self, float* p0, float* p1, float* col, float z);
extern int D_004A28AC;
extern char D_004FF1A0[];

struct sRS231D60 {
    int f0;
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
    unsigned int f8_10 : 22;
    int fC;
    int f10;
};

extern sRS231D60 D_00501420;

class cCtx231D60 {
public:
    char pad0[0xE84];
    sRS231D60* top;
    char pad1[0x10D8 - 0xE88];
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
    virtual void v26(int a, float x, float y, float w, float h, float zn, float zf, int b);
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34(void* p);
};

// Typed view of the render context (the unit declares D_004A289C as void*).
extern cCtx231D60* D_004A289C_231D60 __asm__("D_004A289C");

// PORT: `<?` (GNU min operator) gives the target's min.s
static inline float Clamp231D60(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

extern "C" int func_00231D60(void* self)
{
    if (*(float*)((char*)self + 4) > 0.0f) {
    cCtx231D60* ctx = D_004A289C_231D60;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *D_004A289C_231D60->top = D_00501420;
    D_004A289C_231D60->v26(0, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0);
    D_004A289C_231D60->v34(D_004FF1A0);
    D_004A289C_231D60->top->f8_5 = 31;
    D_004A289C_231D60->top->f4_23 = 2;
    D_004A289C_231D60->top->f4_20 = 0;
    D_004A289C_231D60->top->f4_12 = 0;
    float a = Clamp231D60(*(float*)((char*)self + 4) * 5.0f, 0.0f, 1.0f);
    float p0[2];
    float p1[2];
    float col[4];
    p0[0] = -1.0f;
    p0[1] = -1.0f;
    p1[0] = 1.0f;
    p1[1] = 1.0f;
    col[0] = a;
    col[1] = 0.0f;
    col[2] = 0.0f;
    col[3] = 0.0f;
    func_0038EC40((void*)D_004A28AC, p0, p1, col, 0.0f);
    *(int*)((char*)D_004A289C_231D60 + 0xE84) -= 0x14;
    return a >= 1.0f;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231F80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float floorf_231F80(float x)
{
    float f;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(f) : "f"(x));
    if (x < f) {
        f -= 1.0f;
    }
    return f;
}

extern "C" void func_00231F80(float* t)
{
    *t += 0.01666666753590107f;
    *t -= floorf_231F80(*t);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_00231FC0);
#ifdef SKIP_ASM
extern "C" float func_0031C040(float);
extern char D_004FF1A0[];

struct sV2_1FC0 {
    float x, y;
    sV2_1FC0() {}
    sV2_1FC0(const float& ax, const float& ay) : x(ax), y(ay) {}
};

struct sV4_1FC0 {
    float x, y, z, w;
    sV4_1FC0(const float& ax, const float& ay, const float& az, const float& aw) : x(ax), y(ay), z(az), w(aw) {}
};

struct sCol_1FC0 {
    float r, g, b, a;
};

struct sFade_1FC0 {
    float t;            // 0x0
    float f4;           // 0x4
    float f8;           // 0x8
    sCol_1FC0 col;      // 0xC
};

struct sGs_1FC0 {
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
    void SetF10(int v) { f10 = v; }
};

extern sGs_1FC0 D_00501420_1FC0 __asm__("D_00501420");

class cGfx_1FC0 {
public:
    char pad[0xE84];
    sGs_1FC0* stateTop;
    char padE88[0x10D8 - 0xE88];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19();
    virtual void BeginScene();
    virtual void EndScene();
    virtual void v22(float, float, float, float, int);
    virtual void v23(); virtual void v24();
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
    virtual void DrawSprite(const sV4_1FC0&, const sV2_1FC0&, const sV2_1FC0&, const sV2_1FC0&, const sCol_1FC0&);
};

struct sVE_1FC0 {
    short delta;
    short index;
    void (*fn)(void*, float, float, float, float, int);
};

extern cGfx_1FC0* D_004A289C_1FC0 __asm__("D_004A289C");
extern char* D_004A28A8_1FC0 __asm__("D_004A28A8");

extern "C" void func_00231FC0(sFade_1FC0* self)
{
    cGfx_1FC0* g = D_004A289C_1FC0;
    g->stateTop[1] = g->stateTop[0];
    g->stateTop++;
    D_004A289C_1FC0->BeginScene();
    D_004A289C_1FC0->Begin2D();
    *D_004A289C_1FC0->stateTop = D_00501420_1FC0;
    D_004A289C_1FC0->stateTop->f4_23 = 2;
    D_004A289C_1FC0->stateTop->f4_20 = 0;
    D_004A289C_1FC0->stateTop->f4_12 = 0x14;
    D_004A289C_1FC0->stateTop->f4_2 = 5;
    D_004A289C_1FC0->stateTop->f8_5 = 0x1F;
    D_004A289C_1FC0->SetTexture(D_004FF1A0);
    {
        sVE_1FC0* vt = *(sVE_1FC0**)((char*)D_004A289C_1FC0 + 0x10D8);
        char* thisp = (char*)D_004A289C_1FC0 + vt[23].delta;
        void (**pfn)(void*, float, float, float, float, int) = &vt[23].fn;
        (*pfn)(thisp, 0.0f, 0.0f, (float)D_004A289C_1FC0->GetWidth(), (float)D_004A289C_1FC0->GetHeight(), 1);
    }
    D_004A289C_1FC0->SetViewport(0.0f, 0.0f, 640.0f, 480.0f, 1, 0, 0.0f, 1.0f);
    float s = func_0031C040(self->t * 6.2831854820251465f);
    sV2_1FC0 size((s + 1.0f) * 9.0f, 18.0f);
    sV4_1FC0 pos(599.0f, 445.0f, 0.0f, 1.0f);
    int f10v = *(int*)(D_004A28A8_1FC0 + 0xA0);
    *(short*)((char*)D_004A289C_1FC0->stateTop + 0x10) = f10v;
    self->col.r = self->f4;
    sV2_1FC0 uv0(0.0f, 0.0f);
    sV2_1FC0 uv1(1.0f, 1.0f);
    D_004A289C_1FC0->DrawSprite(pos, size, uv0, uv1, self->col);
    D_004A289C_1FC0->End2D();
    D_004A289C_1FC0->EndScene();
    D_004A289C_1FC0->stateTop--;
}
#endif

extern void* D_0047D938[];

//100%
INCLUDE_ASM("main/gameload", func_00232328__FPv);
#ifdef SKIP_ASM
void* func_00232328(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    *(int*)self = (int)(void*)D_0047D938;
    *(int*)((char*)self + 0x8) = 0;
    return self;
}
#endif

