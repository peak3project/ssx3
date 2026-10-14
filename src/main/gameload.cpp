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
extern "C" void cBigFile_open(void* bf, const char* name, int flags);
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
extern "C" void func_002DBF80(void* p);
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
extern "C" void func_0026F228(void* self);
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
extern "C" void func_00230338(void* self)
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

INCLUDE_ASM("main/gameload", func_00230430);

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
int func_00230698(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0x5C);
}
#endif

//100%
INCLUDE_ASM("main/gameload", func_002306A8__FPvi);
#ifdef SKIP_ASM
int func_002306A8(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0x68);
}
#endif

INCLUDE_ASM("main/gameload", func_002306B8);

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

INCLUDE_ASM("main/gameload", func_002314D0);

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

extern "C" int func_00231840(char* self)
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

extern "C" void* func_00231D18(void* self);

//100%
INCLUDE_ASM("main/gameload", func_00231CB0__FPv);
#ifdef SKIP_ASM
void* func_00231CB0(void* self)
{
    return func_00231D18(self);
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
extern "C" void* func_00231D18(void* self)
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

INCLUDE_ASM("main/gameload", func_00231FC0);

extern void* D_0047D938[];

//100%
INCLUDE_ASM("main/gameload", func_00232328__FPv);
#ifdef SKIP_ASM
void* func_00232328(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)self = (int)(void*)D_0047D938;
    *(int*)((char*)self + 0x8) = t0;
    return self;
}
#endif

