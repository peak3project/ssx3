#include "common.h"
#include "ai/rider.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type).
// Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// Race settings (D_00535BC8; ai/ai's sRaceSettings). D_00535C10 / D_00535C11 are splat symbols for its
// fields at 0x48 / 0x49.
struct sRaceSettings {
    char pad0[0x30];
    int count;                  // 0x30
    int numberOfHumanRiders;    // 0x34
    char pad38[0x10];
    signed char mode48;         // 0x48
    signed char flag49;         // 0x49
    signed char f4A;            // 0x4A
};
extern sRaceSettings D_00535BC8;

// The race (seg/seg_1FBE38 / main/gamemode layout; players at 0x40 hold their rider at +0x18). It is a class
// with its vtable pointer at 0xCC.
struct sRacePlayer {
    char pad_0x0[0x18];
    cRider* rider;              // 0x18
};
class cRace {
public:
    char pad_0x0[0x14];
    int f14;                    // 0x14
    char pad_0x18[0x4];
    int f1C;                    // 0x1C frame counter
    char pad_0x20[0x20];
    sRacePlayer* players[12];   // 0x40
    char pad_0x70[0xC];
    int numPlayers;             // 0x7C
    int f80;                    // 0x80
    int f84;                    // 0x84
    char pad_0x88[0x4];
    int f8C;                    // 0x8C
    char pad_0x90[0x3C];
    virtual void v01();         // vtable pointer at 0xCC
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int);
};
// Two 0x50-byte slots at 0x250 (the table the game holds at 0x10); its +0x10 is the cache passed to
// func_003A9658 / func_003A9770.
struct sCacheSlot {
    int f0;
    char pad[0x4C];
};
struct sCacheTbl {
    char pad[0x250];
    sCacheSlot slot[2];         // 0x250
};
// The game's cameras (seg/seg_1FBE38 sCameras): one per view.
struct sCameras {
    int f0;                     // 0x0
    char* cam[3];               // 0x4
    int f10;                    // 0x10
};
// 16-byte vector (by-value results of func_00122C28 / func_00123F38).
struct sVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// The object func_00230698 returns has this class at +0x10 (vtable pointer at 0xC).
struct cRiderObj {
    int f0, f4, f8;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int isBusy();
};

// A recorder (func_00237140 / func_00237280 add tracks, func_002379C8 plays them back, func_002370A0 frees
// them): nFrames 100-byte frames per track, tracks of 0x18 bytes from 0x14.
struct sFrame {
    int type;                   // 0x00
    char data[0x60];            // 0x04
};
struct sTrack {
    sFrame* frames;             // 0x00
    int cur;                    // 0x04
    int max;                    // 0x08
    int fC;                     // 0x0C
    int* target;                // 0x10 (a 0x2A4-byte block)
    void* obj;                  // 0x14
};
struct sRecorder {
    int f0;                     // 0x00 track length
    int nFrames;                // 0x04
    int f8;                     // 0x08
    int fC;                     // 0x0C
    int count;                  // 0x10 tracks in use
    sTrack tracks[1];           // 0x14
};

// The game-mode manager (cGameModeMan, main/gamemode layout; D_004A28A8->gm).
struct cGameModeMan {
    int f0;             // 0x00 current heat (1..3)
    int mode;           // 0x04
    int type;           // 0x08
    int net;            // 0x0C
    int iNumberAI;      // 0x10
    int f14;            // 0x14
    int a18[10];        // 0x18 rider character IDs
    int a40[10];        // 0x40
    int f68;            // 0x68
    int f6C;            // 0x6C
    int f70;            // 0x70
    int f74;            // 0x74
    int f78;            // 0x78
    int f7C;            // 0x7C
    int f80;            // 0x80
    int f84;            // 0x84
    int f88;            // 0x88
    int f8C;            // 0x8C
    int f90;            // 0x90
    int f94;            // 0x94
    int f98;            // 0x98
    int f9C;            // 0x9C
};
// The game (D_004A2C68, also D_004A28A8->game).
struct sGame {
    char pad_0x0[0xC];
    cRace* race;                // 0xC
    sCacheTbl** cache;          // 0x10
    char pad_0x14[0x14];
    int* f28;                   // 0x28
    char pad_0x2C[0x1C];
    char* f48;                  // 0x48 (+0x18: the list for func_0039F840 / func_0039F9D8)
    char pad_0x4C[0x18];
    void* f64;                  // 0x64
    char pad_0x68[0x10];
    char* f78;                  // 0x78
    char pad_0x7C[0x8];
    sCameras* cameras;          // 0x84
    char pad_0x88[0xC];
    void* f94;                  // 0x94 (the HUD for func_001F36D8 / func_001F36C0)
};
extern sGame* D_004A2C68;
// The game singleton (D_004A28A8).
struct sApp {
    char pad_0x0[0x78];
    void* f78;                  // 0x78
    char pad_0x7C[0x8];
    sGame* game;                // 0x84
    char pad_0x88[0x38];
    cGameModeMan* gm;           // 0xC0
};
extern sApp* D_004A28A8;

// Packed form of a float list (func_00237B28 packs, func_00237BE8 unpacks): count, a bit mask of the non-zero
// values, then those values as bytes.
struct sPackSrc_7B28 {
    int count;
    float vals[1];
};

struct sPackDst_7B28 {
    unsigned char count;
    unsigned char mask[3];
    unsigned char vals[1];
};

// Callees and globals shared by the functions below.
extern "C" void cAI_setAIState(void*, int);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBE_setState(int state);
extern "C" void func_0039F840(void* list);
extern "C" void func_00233AA0(void* self);
extern "C" void func_0026F228(void* p);
extern "C" void* func_0028B180(void);
extern "C" void func_00258968(void* p);
extern "C" void func_002300F0(void* self);
extern "C" void func_0026F7B8(void* p);
void func_0029C418(void* p);
extern "C" void func_0029C420(void* p, int secs);
extern "C" void func_00234BE8(void* self, int a1);
int GetHashValue32(char* str);
extern char* D_004A2EEC;
extern int D_00534B30[];
extern signed char D_00535C10[];
extern char D_0047C038[];
extern "C" int* func_00144BC0(void* iface);
extern "C" int func_0022E098(void* world, int id);
extern "C" int func_00309DD0(void* mgr, int id, int a);
extern "C" void func_00309E50(void* mgr, int id, int a);
extern void* D_004A3DD8;
extern "C" int func_00270280(void* p);
extern "C" void* func_0039F9D8(void* list, int hash);
extern "C" void func_0029C7B0(void* p);
void func_0028C8C0(void* self, int val);
extern char D_0047C048[];
extern char D_004A2AB0[];
extern char D_0047D6E8[];
extern char D_0047D428[];
extern "C" void func_00278CD8(void* a);
extern "C" void func_002790A0(void* a, int b);
extern "C" void func_00278B98(void* a);
extern "C" void func_0012AB20(void* self);
extern "C" void func_0012AC48(void* self);
extern "C" int func_00145D38(void* self, int index, int bit);
extern "C" void func_0027AAF8(void* a, int b);
extern void* D_004A28A4;
extern signed char D_00535C11[];
extern "C" int func_0027AA80(void* a);
extern "C" void func_00158E30(void* iface);
extern "C" void func_00309030(void* a);
extern "C" void func_00309F18(void* a);
extern "C" int func_00144BE0(void* race);
extern "C" int func_00144CC0(void* race, int a);
extern "C" void func_00146E10(void* player, int a, int b);
extern "C" void func_001F36D8(void* hud, int a);
extern "C" int func_00278F68(void* self, int i, int a, int b);
extern "C" void func_002B3A98(void* p);
extern "C" void func_002A4B68(void* p);
extern "C" int func_00279220(void* a, int b);
extern "C" void func_00308F38(void* a);
extern "C" void func_00308C60(void* a);
extern "C" void func_00145DD0(void* iface, int a1, int a2, int a3);
extern "C" int func_00238510(cGameModeMan* gm, int a1, int a2);
extern "C" void* func_00233AF0(void* self);
extern "C" void* func_00233B28(void* self);
// PORT: func_00233AF0 also reads $a1 (the stream); bound with its real arity.
void* func_00233AF0_2(void* self, void* obj) __asm__("func_00233AF0");
// PORT: func_00233B28 also reads $a1 (the stream); bound with its real arity.
void* func_00233B28_2(void* self, void* obj) __asm__("func_00233B28");
extern "C" void func_0030B7F8(void* self);
extern "C" void func_00230180(void* self);
// PORT: func_00278F38 returns func_00276270's result (ssxscriptengine defines it void).
extern "C" int func_00278F38(void* self, int i);
extern "C" void func_0027A860(void* a, int b, int c);
extern "C" void func_001F36C0(void* a, int b);
extern "C" void cGameModeMan_restartHeat(cGameModeMan* gm);
extern "C" int cBENewRaceInterface_setNumberAI(void* self, int count);
extern "C" void cBENewPlayerInterface_setRiderCharID(void* player, int i, int id);
extern "C" void func_001473D0(void* player, int i, int v);
extern "C" int func_0012ABD0(void* p);
extern "C" void func_0012B030(void* p);
extern "C" void func_0012B000(void* p);
extern "C" void func_00128958(void* p);
extern "C" int func_0012A180(void* p);
void func_001289F0(void* p);
extern "C" void func_001296F8(void* p);
extern "C" sVec4 func_00122C28(void* rider);
extern "C" void func_003A9658(void* cache, int idx, const sVec4* pos, float radius);
extern "C" int func_003A9770(void* cache, int idx, sVec4* pos, float* dist);
extern "C" int func_002791D8(void* p, int a);
extern "C" int func_00279298(void* p);
extern "C" bool func_0027A9F0(void* p);
void* func_00230698(void* self, int id);
extern int D_00535C04[];
extern "C" void cGameModeMan_initGameMode(cGameModeMan* gm, int mode);
extern "C" void func_0011DE60(void* self, int a1, int a2);
extern "C" void func_0011DF18(void* self, int notify);
// PORT: func_002E4CE8 is the wake pool's allocator; it ignores the size the caller passes
extern "C" void* func_002E4CE8(int size);
void* func_002E4D70(void* self);
extern "C" void func_002E4370(void* self, int a1, int a2, void* a3, float f0, float f1, int a4, int a5, float f2);
extern void* D_004880C0[];
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern char D_0047D320[];
extern "C" void func_0011D390(void* rider);
extern "C" void func_00278E50(void* self, int i, int a, int b, int c, int d, int f, int g);
extern int D_004A11BC;
extern char D_0047D2C8[];
extern "C" void func_00145CB0(void* iface, int i, int a);
extern "C" int func_0022D278(void* self, int idx);
extern "C" void func_0022D088(void* self, int idx, int mode);
extern "C" sVec4 func_00123F38(void* rider);
extern "C" void func_002EA820(void* p);
extern "C" void func_0020A8F8(int mode);
extern int D_004A2A50;
extern int D_004A2A54;
extern int D_005366E8[];
extern int D_004428F4[];
extern "C" void func_00236CD8(void* self);
extern int D_004428F0[];
extern "C" void func_002871B0(void* mgr);
extern "C" void func_0028CDF8(void* mgr);
extern "C" void func_0020AB50(int state);
void cMemMan_free(void*);
void operator_delete(int*);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_003E6448(void* dst, int value, int size);
// PORT: func_00244400__FPvi takes the 0x2A4-byte block as an int (pointer in int)
void func_00244400(void* self, int a1);
void func_00244408(void* self, int a1);
extern char D_0047C078[];
extern char D_0047C088[];
extern char D_0047C098[];
extern "C" void func_00321298(void* target, int a, void* data);
extern "C" int func_00237B28(void* self, sPackSrc_7B28* src, sPackDst_7B28* dst);
extern "C" void func_00237BE8(void* self, sPackSrc_7B28* src, char* buf);
extern "C" int func_00257E98(void* mgr, int a, char* buf, int len);
extern "C" void cBxPseudoRng_Seed(uint* state, uint seed);
extern uint D_004C9548[];
extern "C" uint cBxPseudoRng_NextInt(uint* state);

//100%
INCLUDE_ASM("main/gamestate", cGFGateState_gainFocus);
#ifdef SKIP_ASM
extern "C" void cGFGateState_gainFocus(void* self)
{
    D_004A2C68->race->f8C = 0;
    if (D_004A2EEC != 0) {
        func_00258968(D_004A2EEC);
    }
    cBE_setState(0);
    cBE_getInterface_Fv(D_004A28A8->f78, 7);
    if (D_00534B30[0] != 0) {
        func_002300F0(D_004A2C68);
    }
    func_0026F228(D_004A2C68->f28);
    func_0026F7B8(D_004A2C68->f28);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int mode = D_00535C10[0];
    if (mode >= 4 && mode <= 6) {
        func_00233AA0(self);
        return;
    }
    cAI_setAIState(D_004A2C68->race, 4);
    func_0029C418(func_0028B180());
    func_0029C420(func_0028B180(), 3);
    func_00234BE8(self, GetHashValue32(D_0047C038));
    func_0039F840(D_004A2C68->f48 + 0x18);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234BE8);
#ifdef SKIP_ASM
extern "C" void func_00234BE8(void* self, int a1)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* world = D_004A28A8->game->f78;
    int id = func_0022E098(world, *func_00144BC0(iface));
    if (func_00309DD0(D_004A3DD8, id, a1) != 0) {
        func_00309E50(D_004A3DD8, id, a1);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", cGFGateState_update);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_00234C68(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

extern "C" void cGFGateState_update(void* self)
{
    if (func_00270280(D_004A2C68->f28) != 0) {
        return;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C10[0] == 4) {
        return;
    }
    if (D_004A2C68->race->f1C <= 0) {
        func_00234BE8(self, GetHashValue32(D_0047C048));
        char* obj = (char*)func_0039F9D8(D_004A2C68->f48 + 0x18, GetHashValue32(D_004A2AB0));
        if (obj != 0) {
            sVEntry<int(void*, int, int)>* e = &(*(sVEntry<int(void*, int, int)>**)(obj + 8))[24];
            e->fn(obj + e->delta, 6, 0);
        }
        func_0029C7B0(func_0028B180());
        func_0028C8C0(func_0028B180(), 0x78);
        func_00233AA0(self);
    }
    int frames = D_004A2C68->race->f1C;
    float secs = frames / 60;
    if (frames % 60 == 0) {
        func_0029C420(func_0028B180(), (int)ffloor_00234C68(secs));
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234DE0__FPv);
#ifdef SKIP_ASM
void* func_00234DE0(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234E00__FPv);
#ifdef SKIP_ASM
void* func_00234E00(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234E20);
#ifdef SKIP_ASM
extern "C" void func_00234E20(void)
{
    cAI_setAIState(D_004A2C68->race, 5);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C10[0] != 4) {
        sGame* g = D_004A2C68;
        g->race->f14 = 1;
        g->race->f8C = 0;
    }
    cBE_setState(1);
    sGame* gs = D_004A2C68;
    int n = *gs->f28;
    int ok = n != 0 && n < 10;
    if (!ok) {
        func_0039F840(gs->f48 + 0x18);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234EB8__FPv);
#ifdef SKIP_ASM
void* func_00234EB8(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234ED8__FPv);
#ifdef SKIP_ASM
void* func_00234ED8(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234EF8);
#ifdef SKIP_ASM
extern "C" void* func_00234EF8(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    D_004A2C68 = 0;
    *(void**)((char*)self + 0xC) = D_0047D428;
    *(int*)((char*)self + 0x0) = 4;
    *(int*)((char*)self + 0x10) = 5;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234F40);
#ifdef SKIP_ASM
struct sState_234F40 {
    int pad0[4];
    int f10;
    int f14;
    int f18;
};

extern "C" void func_00234F40(sState_234F40* self)
{
    self->f18 = 0;
    func_0026F228(D_004A2C68->f28);
    func_002790A0(D_004A28A4, 0);
    func_00278CD8(D_004A28A4);
    func_00278B98(D_004A28A4);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    self->f14 = 0;
    int m = D_00535C11[0];
    func_0012AB20(D_004A2C68->race);
    func_0012AC48(D_004A2C68->race);
    if (m == 0) {
        int t = *(int*)(D_004A28A8->game->f78 + 0x1BC);
        if (t >= 14 && t <= 16) {
            void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
            char* sub = (char*)D_004A2C68->race->players[0]->rider + 0x6C0;
            sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)sub;
            if (func_00145D38(iface, vt[7].fn(sub + vt[7].delta), t) != 0) {
                char* g = (char*)func_0028B180();
                *(int*)(g + 0x5790) = 0;
                *(int*)(g + 0x578C) = 1;
                *(int*)(g + 0x6254) = 1;
                self->f14 = 1;
            }
        }
    } else {
        func_0027AAF8(D_004A28A4, 0);
    }
    self->f10 = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235080);
#ifdef SKIP_ASM
extern "C" int func_00278D58(void* self);
extern "C" void func_00278E20(void* self, int i, int a, int b);
extern "C" void func_0028CD48(void* self);
extern "C" void func_002B3A70(void* self);
extern "C" int func_0012ACF8(void* p);
extern "C" void func_00128998(void* self, int n);
extern "C" void func_00128A10(void* self);

static inline int isOne_235080(int v)
{
    return v == 1;
}

extern "C" void func_00235080(void* self)
{
    *(int*)((char*)self + 0x18) += 1;
    switch (*(int*)((char*)self + 0x10)) {
    case 0: {
        if (func_00278D58(D_004A28A4) == 0)
            break;
        func_00278F38(D_004A28A4, 0);
        char* g = D_004A28A8->game->f78;
        int t = *(int*)(g + 0x1BC);
        int range = t >= 14 && t <= 16;
        if (*(int*)((char*)self + 0x14) != 0) {
            if (t == 14) {
                func_00278E20(D_004A28A4, 1, 0x1D, 3);
                func_0028CD48(func_0028B180());
                func_002B3A70((char*)func_0028B180() + 0x118);
                func_00278E50(D_004A28A4, 1, 0, 3, 0, -1, -1, -1);
                func_00278E50(D_004A28A4, 1, 1, 3, 0, -1, -1, -1);
            } else {
                func_00278E20(D_004A28A4, 1, t == 15 ? 0x1E : 0x1F, 3);
                func_00278E50(D_004A28A4, 1, 0x10, 3, 0, -1, -1, -1);
                func_00278E50(D_004A28A4, 1, 0x11, 3, 0, -1, -1, -1);
            }
            func_00278F38(D_004A28A4, 1);
        } else if (*(int*)(g + 0x1C8) != 0 && range) {
            func_00278E50(D_004A28A4, 1, 0x10, 3, 0, -1, -1, -1);
            func_00278E50(D_004A28A4, 1, 0x11, 3, 0, -1, -1, -1);
        }
        *(int*)((char*)self + 0x10) = 1;
        break;
    }
    case 1: {
        long done = 0;
        if (!isOne_235080(func_002791D8(D_004A28A4, 0))) {
            if (!isOne_235080(func_002791D8(D_004A28A4, 1)))
                done = 1;
        }
        if (done)
            *(int*)((char*)self + 0x10) = 2;
        break;
    }
    case 2: {
        // last stays a variable: the binary compares it as li 11; slt (a literal 11 gives slti 12, and
        // mode < 6 || mode > 11 folds into one unsigned range test).
        int last = 11;
        if (func_0012ABD0(D_004A2C68->race) == 0)
            break;
        if (func_0012ACF8(D_004A2C68->race) == 0)
            break;
        char* newRace = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
        char* newPlayer = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
        sRaceSettings* r = &D_00535BC8;
        cGameModeMan* gm = D_004A28A8->gm;
        int mode = r->f4A;
        if (mode < 6 || mode > last)
            cGameModeMan_initGameMode(gm, mode);
        int numAI = gm->iNumberAI - gm->f14;
        int base = D_004A2C68->race->numPlayers;
        int i = 0;
        cBENewRaceInterface_setNumberAI(newRace, numAI);
        {
            sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)(newRace + 0xC);
            vt[1].fn(newRace + vt[1].delta);
        }
        for (; i < numAI; i++) {
            cBENewPlayerInterface_setRiderCharID(newPlayer, i + base, gm->a18[base + i]);
            func_001473D0(newPlayer, i + base, gm->a40[base + i]);
        }
        {
            sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)(newPlayer + 0xC);
            vt[1].fn(newPlayer + vt[1].delta);
        }
        sRaceSettings* r2 = &D_00535BC8;
        int quick = 0;
        func_0012B030(D_004A2C68->race);
        func_0012B000(D_004A2C68->race);
        if (r2->mode48 == 0)
            quick = r2->flag49 == 0;
        func_00128958(D_004A2C68->race);
        if (numAI == 0 && quick) {
            if (r2->mode48 == 0)
                func_00128998(D_004A2C68->race, 0);
            else
                func_00128998(D_004A2C68->race, 2);
        }
        *(int*)((char*)self + 0x10) = 3;
        break;
    }
    case 3: {
        if (func_0012A180(D_004A2C68->race)) {
            cBE_getInterface_Fv(cBE_getBE(), 0);
            sRaceSettings* r = &D_00535BC8;
            int m = r->mode48;
            if (m == 0) {
                func_001289F0(D_004A2C68->race);
                if (D_004A2C68->race->f80 > 0)
                    D_004A2C68->race->f14 = 1;
                if (D_004A2C68->race->f84 > 0)
                    D_004A2C68->race->f8C = 1;
            }
            if (m == 5) {
                sRaceSettings* r2 = &D_00535BC8;
                if (r2->flag49 == 0)
                    func_00128A10(D_004A2C68->race);
            }
            *(int*)((char*)self + 0x10) = 4;
        } else {
            func_001296F8(D_004A2C68->race);
        }
        break;
    }
    case 4:
        if (*(int*)((char*)self + 0x14) != 0 && *(int*)((char*)self + 0x18) < 180)
            break;
        *(int*)((char*)self + 0x10) = 5;
        break;
    case 5:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235570);
#ifdef SKIP_ASM
extern "C" void func_00235570(void* self)
{
    func_00278CD8(D_004A28A4);
    func_002790A0(D_004A28A4, 1);
    *(int*)((char*)self + 0x10) = 5;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002355B0);
#ifdef SKIP_ASM
extern "C" int func_002355B0(void* self)
{
    return *(int*)((char*)self + 0x10) == 5;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002355C0);
#ifdef SKIP_ASM
static inline int inRange_2355C0(int t)
{
    return t >= 14 && t <= 16;
}

static inline int isMode2_2355C0(void* s)
{
    return *(int*)((char*)s + 0x550) == 2;
}

extern "C" void func_002355C0(void* self)
{
    *(int*)((char*)self + 0x1C) = 0;
    if (func_0027AA80(D_004A28A4))
        *(int*)((char*)self + 0x1C) = 1;
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    func_00158E30(cBE_getInterface_Fv(cBE_getBE(), 0xD));
    sRaceSettings* r = &D_00535BC8;
    int flag = r->flag49;
    int mode = r->mode48;
    if (flag == 0 && !inRange_2355C0(*(int*)(D_004A28A8->game->f78 + 0x1BC))) {
        *(int*)((char*)self + 0x4) = 0;
        *(int*)((char*)self + 0x0) = 4;
    } else {
        *(int*)((char*)self + 0x0) = 1;
        *(int*)((char*)self + 0x4) = flag == 0;
    }
    if (mode == 4)
        cAI_setAIState(D_004A2C68->race, 3);
    cBE_setState(0);
    func_00309030(D_004A3DD8);
    func_00309F18(D_004A3DD8);
    if (func_00144CC0(race, func_00144BE0(race)) == 1) {
        char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
        func_00146E10(player, 0, func_00144BE0(race));
        sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)(player + 0xC);
        vt[1].fn(player + vt[1].delta);
    }
    D_004A2C68->race->f14 = mode != 4;
    func_001F36D8(D_004A28A8->game->f94, 0);
    if (flag) {
        *(int*)((char*)self + 0x0) = 1;
        *(int*)((char*)self + 0x4) = 0;
        if (isMode2_2355C0(D_004A28A4)) {
            func_00278F68(D_004A28A4, 1, 0, 1);
            if (isMode2_2355C0(D_004A28A4))
                func_00278F68(D_004A28A4, 0, 0, 1);
        }
    } else if (*(int*)((char*)self + 0x14)) {
        func_00278F68(D_004A28A4, 1, 1, 0);
    }
    func_002B3A98((char*)func_0028B180() + 0x118);
    func_002A4B68(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002357F8);
#ifdef SKIP_ASM
extern "C" void func_002357F8(void* self)
{
    if (*(int*)((char*)self + 0x1C) != 0 && func_0027AA80(D_004A28A4) == 0) {
        *(int*)(D_004A28A8->game->f78 + 0x1A4) = 1;
        *(int*)((char*)self + 0x1C) = 0;
    }
    if (func_00279220(D_004A28A4, 1) == 0) {
        func_00233AA0(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235868);
#ifdef SKIP_ASM
static inline int otherSide_235868(char* p)
{
    return *(int*)(p + 0xB0) == 0;
}

extern "C" void func_00235868(void* self)
{
    func_00308F38(D_004A3DD8);
    func_00308C60(D_004A3DD8);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    func_0026F228(D_004A2C68->f28);
    func_0026F7B8(D_004A2C68->f28);
    *(int*)((char*)self + 0x14) = 0;
    sRaceSettings* r = &D_00535BC8;
    if (r->flag49 == 0) {
        void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
        func_00145DD0(player, 0, 0, *func_00144BC0(race));
    }
    int m = r->mode48;
    if (m == 5) {
        goto restart;
    }
    if (m == 6) {
    restart:
        func_00238510(D_004A28A8->gm, 0, 0);
    }
    sGame* g = D_004A28A8->game;
    sCameras* x = g->cameras;
    if (x->f10 == 1) {
        sCacheTbl* t = *g->cache;
        t->slot[otherSide_235868(x->cam[0])].f0 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235990);
#ifdef SKIP_ASM
extern "C" void func_00235990(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235A18);
#ifdef SKIP_ASM
extern "C" void func_00235A18(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235AA0);
#ifdef SKIP_ASM
extern "C" void func_00235AA0(void* self)
{
    cBE_setState(0);
    func_0030B7F8(D_004A3DD8);
    char* race = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
    char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
    cGameModeMan* gm = D_004A28A8->gm;
    cGameModeMan_restartHeat(gm);
    func_00230180(D_004A28A8->game);
    sRaceSettings* r = &D_00535BC8;
    int m = r->mode48;
    if (m == 5)
        goto bail;
    if (m == 6)
        goto bail;
    if (r->flag49 != 0) {
    bail:
        *(int*)((char*)self + 0x10) = 3;
        return;
    }
    int n = gm->iNumberAI - gm->f14;
    int base = D_004A2C68->race->numPlayers;
    int i = 0;
    cBENewRaceInterface_setNumberAI(race, n);
    {
        sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)(race + 0xC);
        vt[1].fn(race + vt[1].delta);
    }
    for (; i < n; i++) {
        cBENewPlayerInterface_setRiderCharID(player, i + base, gm->a18[base + i]);
        func_001473D0(player, i + base, gm->a40[base + i]);
    }
    {
        sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)(player + 0xC);
        vt[1].fn(player + vt[1].delta);
    }
    func_0012AB20(D_004A28A8->game->race);
    if (n >= 2)
        func_0012AC48(D_004A28A8->game->race);
    *(int*)((char*)self + 0x18) = 0;
    sRaceSettings* r2 = &D_00535BC8;
    if (r2->mode48 == 0) {
        void* sc = D_004A28A4;
        *(int*)((char*)self + 0x18) = 1;
        func_0027A860(sc, 1, 0);
    }
    func_002790A0(D_004A28A4, 0);
    func_0027AAF8(D_004A28A4, gm->f98 ? 3 : 2);
    func_00278F38(D_004A28A4, 0);
    func_001F36C0(D_004A28A8->game->f94, 3);
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235CC8);
#ifdef SKIP_ASM
extern "C" void func_00235CC8(void* self)
{
    *(int*)((char*)self + 0x14) += 1;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    sGame* g84 = D_004A28A8->game;
    int state = *(int*)((char*)self + 0x10);
    sCacheTbl** cache = g84->cache;
    int idx = *(int*)(g84->cameras->cam[0] + 0xB0) == 0;
    switch (state) {
    case 0:
        if (func_0012ABD0(g84->race)) {
            func_0012B030(D_004A28A8->game->race);
            if (D_00535C04[0] >= 2)
                func_0012B000(D_004A28A8->game->race);
            func_00128958(D_004A28A8->game->race);
            *(int*)((char*)self + 0x10) = 1;
        }
        break;
    case 1:
        if (func_0012A180(g84->race)) {
            func_001289F0(D_004A28A8->game->race);
            D_004A2C68->race->f14 = 1;
            (*cache)->slot[idx].f0 = 1;
            sRacePlayer* r = D_004A28A8->game->race->players[0];
            sVec4 pos = func_00122C28(r->rider);
            func_003A9658((char*)*cache + 0x10, idx, &pos, 45000.0f);
            *(int*)((char*)self + 0x10) = 2;
        } else {
            func_001296F8(D_004A28A8->game->race);
        }
        break;
    case 2:
        if (*(int*)((char*)self + 0x18) != 0) {
            sVec4 v;
            float dist;
            func_003A9770((char*)*cache + 0x10, idx, &v, &dist);
            if (dist < 20000.0f)
                break;
            if (*(int*)((char*)self + 0x14) < 120)
                break;
            if (func_002791D8(D_004A28A4, 0) == 1)
                break;
            char* o = (char*)func_00230698(D_004A28A8->game, 0);
            if (func_00279298(D_004A28A4) != 0)
                break;
            if (((cRiderObj*)(o + 0x10))->isBusy() != 0)
                break;
            if (*(int*)(o + 0x44) != 0)
                break;
            func_0027A9F0(D_004A28A4);
        }
        *(int*)((char*)self + 0x10) = 3;
        break;
    case 3:
        func_00233AA0(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235F20);
#ifdef SKIP_ASM
extern "C" void func_00235F20(void)
{
    func_001F36D8(D_004A28A8->game->f94, 3);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235F48);
#ifdef SKIP_ASM
extern "C" void func_00235F48(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235FD0);
#ifdef SKIP_ASM
extern "C" void func_00235FD0(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236058);
#ifdef SKIP_ASM
struct sColor_236058 {
    float r, g, b, a;
};

extern "C" void func_00236058(void* self)
{
    cGameModeMan* gm = D_004A28A8->gm;
    func_0030B7F8(D_004A3DD8);
    cGameModeMan_initGameMode(gm, 0xC);
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 0xA);
    func_00230180(D_004A28A8->game);
    func_0011DE60(D_004A28A8->game->race->players[0]->rider, *(int*)(iface + 0x10), 2);
    func_0011DF18(D_004A28A8->game->race->players[0]->rider, 1);
    void* r = func_00230698(D_004A28A8->game, 0);
    char* o = (char*)func_002E4CE8(0x14);
    sColor_236058 c;
    c.r = 1.0f;
    c.g = 1.0f;
    c.b = 1.0f;
    c.a = 1.0f;
    func_002E4D70(o);
    *(void***)o = D_004880C0;
    *(sColor_236058*)(o + 4) = c;
    func_002E4370(r, 1, 0, o, 0.0f, 0.0f, 0, 0, 1.0f);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236198);
#ifdef SKIP_ASM
extern "C" void func_00236198(void)
{
    func_00231250(D_004A28A8->game, 1, 0, 0);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002361C8__FPv);
#ifdef SKIP_ASM
void* func_002361C8(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002361E8__FPv);
#ifdef SKIP_ASM
void* func_002361E8(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236208);
#ifdef SKIP_ASM
extern "C" void* func_00236208(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    D_004A2C68 = 0;
    *(void**)((char*)self + 0xC) = D_0047D320;
    *(int*)((char*)self + 0x0) = 4;
    *(int*)((char*)self + 0x18) = 0x17;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x14) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236250);
#ifdef SKIP_ASM
static inline int isOne_6250(int m)
{
    return m == 1;
}

extern "C" void func_00236250(void* self, int mode)
{
    func_0030B7F8(D_004A3DD8);
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    cAI_setAIState(D_004A2C68->race, 3);
    D_004A2C68->race->players[0]->rider->unk_2F8 = 0;
    *(int*)((char*)self + 0x18) = 0x17;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = mode;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    if (mode == 1) {
        *(int*)((char*)self + 0x8) = mode;
        cBE_getInterface_Fv(cBE_getBE(), 0);
        *(int*)((char*)self + 0x18) = D_004A11BC;
    }
    if (*(int*)((char*)self + 0x18) == *func_00144BC0(iface))
        func_00230180(D_004A28A8->game);
    int m = *(int*)((char*)self + 0x14);
    if (m == 0) {
        func_00278E50(D_004A28A4, 1, 0x16, 3, 0, -1, -1, -1);
        func_00278E50(D_004A28A4, 1, 0x17, 1, 0, -1, -1, -1);
        func_00278F38(D_004A28A4, 1);
        func_00278F68(D_004A28A4, 1, 1, 0);
    } else if (m >= 0) {
        if (m < 4) {
            if (!isOne_6250(m))
                func_00278E50(D_004A28A4, 1, 0xB, 3, 0, -1, -1, -1);
            func_00278F38(D_004A28A4, 1);
            func_0011D390(D_004A28A8->game->race->players[0]->rider);
            func_00278F68(D_004A28A4, 1, *(int*)((char*)self + 0x14) == 2, 0);
        }
    }
}
#endif

INCLUDE_ASM("main/gamestate", func_00236418);

//100%
INCLUDE_ASM("main/gamestate", func_00236728);
#ifdef SKIP_ASM
extern "C" void func_00236728(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x8, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002367C8);
#ifdef SKIP_ASM
extern "C" void func_002367C8(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x8, 4);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236868);
#ifdef SKIP_ASM
extern "C" void* func_00236868(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    D_004A2C68 = 0;
    *(void**)((char*)self + 0xC) = D_0047D2C8;
    *(int*)((char*)self + 0x0) = 0xA;
    *(int*)((char*)self + 0x4) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002368A0);
#ifdef SKIP_ASM
extern "C" void func_002368A0(void* self)
{
    cBE_setState(0);
    func_0026F228(D_004A2C68->f28);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BC8.flag49 == 0) {
        int i = 0;
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        for (; i < D_00535BC8.count; i++) {
            func_00145CB0(iface, i, 0);
        }
    }
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236960);
#ifdef SKIP_ASM
extern "C" void func_00236960(void* self)
{
    sGame* g84 = D_004A28A8->game;
    char* game = g84->f78;
    if (*(int*)(game + 0x1C8) == 0) {
        return;
    }
    int state = *(int*)((char*)self + 0x10);
    sCacheTbl** cache = g84->cache;
    int idx = *(int*)(g84->cameras->cam[0] + 0xB0) == 0;
    switch (state) {
    case 0:
        if (func_0022D278(game, *(int*)(game + 0x1BC)) != 0) {
            sRacePlayer* r = D_004A28A8->game->race->players[0];
            sVec4 pos = func_00123F38(r->rider);
            (*cache)->slot[idx].f0 = 1;
            func_003A9658((char*)*cache + 0x10, idx, &pos, 45000.0f);
            *(int*)((char*)self + 0x10) = 1;
        }
        break;
    case 1: {
        sVec4 v;
        float dist;
        func_003A9770((char*)*cache + 0x10, idx, &v, &dist);
        if (dist < 20000.0f) {
            break;
        }
        char* o = (char*)func_00230698(D_004A28A8->game, 0);
        if (((cRiderObj*)(o + 0x10))->isBusy() != 0) {
            break;
        }
        if (*(int*)(o + 0x44) != 0) {
            break;
        }
        if (func_00279298(D_004A28A4) != 0) {
            break;
        }
        func_0027A9F0(D_004A28A4);
        *(int*)(game + 0x1C8) = 0;
        func_0022D088(game, *(int*)(game + 0x1BC), 7);
        *(int*)((char*)self + 0x10) = 2;
        break;
    }
    case 2:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236AF0__FPv);
#ifdef SKIP_ASM
void func_00236AF0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236AF8__FPv);
#ifdef SKIP_ASM
void* func_00236AF8(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236B18__FPv);
#ifdef SKIP_ASM
void* func_00236B18(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236B38);
#ifdef SKIP_ASM
extern "C" void func_00236B38(void)
{
    D_004A2C68->race->v05(3);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236B70__FPv);
#ifdef SKIP_ASM
void* func_00236B70(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236B90__FPv);
#ifdef SKIP_ASM
void* func_00236B90(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236BB0);
#ifdef SKIP_ASM
struct sGameState_6BB0 {
    char pad0[8];
    int done;   // 0x8
};

// Ends the game state: pushes front-end state 1 unless D_004A2EEC is active, then hands control back.
extern "C" void func_00236BB0(sGameState_6BB0* self)
{
    self->done = 0;
    if (D_004A2EEC != 0 && *(int*)(D_004A2EEC + 4) != 0) {
        func_002EA820(D_004A28A8->game->f64);
        cBE_setState(0);
        return;
    }
    func_0020A8F8(2);
    D_005366E8[++D_004A2A54] = 1;
    D_004A2A50 = D_004428F4[0];
    func_002EA820(D_004A28A8->game->f64);
    cBE_setState(0);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236C48);
#ifdef SKIP_ASM
extern "C" void func_00236C48(void* self)
{
    if (D_004A2EEC == 0 || *(int*)(D_004A2EEC + 4) == 0) {
        if (*(int*)((char*)self + 8) == 1) {
            func_00233AA0(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236C88);
#ifdef SKIP_ASM
extern "C" void func_00236C88(void* self)
{
    D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
    func_00236CD8(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236CD8);
#ifdef SKIP_ASM
static inline int isMode4_236CD8()
{
    return D_00535C10[0] == 4;
}

extern "C" void func_00236CD8(void* self)
{
    func_002790A0(D_004A28A4, 0);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (!isMode4_236CD8()) {
        D_004A2C68->race->v05(3);
        D_004A2C68->race->f14 = 1;
    }
    func_002871B0(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236D60__FPv);
#ifdef SKIP_ASM
void* func_00236D60(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236D80__FPv);
#ifdef SKIP_ASM
void* func_00236D80(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236DA0);
#ifdef SKIP_ASM
extern "C" void func_00236DA0(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BC8.flag49 == 0) {
        int i = 0;
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        for (; i < D_00535BC8.count; i++) {
            func_00145CB0(iface, i, 0);
        }
    }
    func_002790A0(D_004A28A4, 0);
    *(int*)((char*)self + 0x8) = 0;
    func_0020A8F8(7);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236E60);
#ifdef SKIP_ASM
extern "C" void func_00236E60(void* self)
{
    if (*(int*)((char*)self + 8) == 1) {
        func_00231250(D_004A28A8->game, 0xE, 2, 0);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236EA0);
#ifdef SKIP_ASM
extern "C" void func_00236EA0(void)
{
    func_0039F840(D_004A2C68->f48 + 0x18);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236EC8__FPv);
#ifdef SKIP_ASM
void* func_00236EC8(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236EE8__FPv);
#ifdef SKIP_ASM
void* func_00236EE8(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236F08);
#ifdef SKIP_ASM
extern "C" void func_00236F08(void)
{
    func_0028CDF8(func_0028B180());
    D_004A28A8->game->race->f8C = 1;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236F40);
#ifdef SKIP_ASM
extern "C" void func_00236F40(void* self)
{
    int r = func_00279220(D_004A28A4, 0);
    int busy = r != 0 && r != 5;
    if (!busy) {
        func_00233AA0(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236F90);
#ifdef SKIP_ASM
extern "C" void func_00236F90(void)
{
    D_004A28A8->game->race->f8C = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236FA8__FPv);
#ifdef SKIP_ASM
void* func_00236FA8(void* self)
{
    return func_00233AF0(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236FC8__FPv);
#ifdef SKIP_ASM
void* func_00236FC8(void* self)
{
    return func_00233B28(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236FE8);
#ifdef SKIP_ASM
extern "C" void func_00236FE8(void)
{
    func_00309030(D_004A3DD8);
    func_00309F18(D_004A3DD8);
    func_001F36D8(D_004A28A8->game->f94, 0);
    func_0020AB50(0x11);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237030__FPv);
#ifdef SKIP_ASM
void func_00237030(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237038);
#ifdef SKIP_ASM
extern "C" void func_00237038(void)
{
    func_00308F38(D_004A3DD8);
    func_00308C60(D_004A3DD8);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237060);
#ifdef SKIP_ASM
extern "C" void* func_00237060(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x4) = a1;
    *(int*)((char*)self + 0x8) = a2;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x0) = a1 * a2;
    *(int*)((char*)self + 0x4) = (60 / a2) * a2;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002370A0);
#ifdef SKIP_ASM
extern "C" void func_002370A0(sRecorder* self, int flags)
{
    int i;
    for (i = 0; i < self->count; i++) {
        sTrack* e = &self->tracks[i];
        if (e->frames)
            cMemMan_free(e->frames);
        operator_delete(e->target);
        operator_delete((int*)e->obj);
    }
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237140);
#ifdef SKIP_ASM
static inline void* initObj_237140(void* o, int a, int b)
{
    func_00244400(o, a);
    func_00244408(o, b);
    return o;
}

extern "C" void* func_00237140(sRecorder* self, int* a1)
{
    sTrack* e = &self->tracks[self->count++];
    e->frames = (sFrame*)operator_new__FUi(self->nFrames * 100, D_0047C078, 0, 0);
    func_003E6448(e->frames, 0, self->nFrames * 100);
    for (int i = 0; i < self->nFrames; i++) {
        e->frames[i].type = 0x18;
    }
    e->cur = 0;
    e->max = self->f0;
    e->fC = a1[0];
    e->target = (int*)cMemMan_alloc(0x2A4, D_0047C088, 0, 0);
    *e->target = 0;
    void* o = initObj_237140(cMemMan_alloc(8, D_0047C098, 0, 0), (int)e->target, a1[1]);
    e->obj = o;
    return o;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237280);
#ifdef SKIP_ASM
static inline void* initObj_237280(void* o, int a, int b)
{
    func_00244400(o, a);
    func_00244408(o, b);
    return o;
}

extern "C" void* func_00237280(sRecorder* self, int a1)
{
    sTrack* e = &self->tracks[self->count++];
    e->frames = (sFrame*)operator_new__FUi(self->nFrames * 100, D_0047C078, 0, 0);
    func_003E6448(e->frames, 0, self->nFrames * 100);
    for (int i = 0; i < self->nFrames; i++) {
        e->frames[i].type = 0x18;
    }
    e->cur = 0;
    e->max = self->f0;
    e->fC = 0;
    e->target = (int*)cMemMan_alloc(0x2A4, D_0047C088, 0, 0);
    *e->target = 0;
    void* o = initObj_237280(cMemMan_alloc(8, D_0047C098, 0, 0), (int)e->target, a1);
    e->obj = o;
    return o;
}
#endif

INCLUDE_ASM("main/gamestate", func_002373B8);

//100%
INCLUDE_ASM("main/gamestate", func_00237948__FPv);
#ifdef SKIP_ASM
void func_00237948(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237950);
#ifdef SKIP_ASM
extern "C" int func_00237950(sRecorder* self)
{
    char* p = D_004A2EEC;
    if (*(int*)(p + 0x70) < 14) {
        return 0;
    }
    int busy = *(int*)(p + 0x3F8) != 0 || *(int*)(p + 0x3FC) > 0;
    if (busy) {
        return 0;
    }
    int i;
    for (i = 0; i < self->count; i++) {
        sTrack* s = &self->tracks[i];
        if (s->cur == s->max) {
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002379C8);
#ifdef SKIP_ASM
extern "C" int func_002379C8(sRecorder* self)
{
    if (*(int*)(D_004A2EEC + 0x70) < 14) {
        return 0;
    }
    if (func_00237950(self) == 0) {
        return 0;
    }
    int i;
    for (i = 0; i < self->count; i++) {
        sTrack* t = &self->tracks[i];
        sFrame* f = &t->frames[t->cur % self->nFrames];
        func_00321298(t->target, f->type, f->data);
        t->cur++;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237A98);
#ifdef SKIP_ASM
extern "C" void func_00237A98(void* self, sPackSrc_7B28* src)
{
    char buf[32];
    int len = func_00237B28(self, src, (sPackDst_7B28*)buf);
    func_00237BE8(self, src, buf);
    char* p = D_004A2EEC;
    int ok = *(int*)(p + 0x40) != 0 && *(int*)(p + 4) == 0 && *(int*)(p + 0) != 0;
    if (ok) {
        func_00257E98(D_004A2EEC, 0, buf, len);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237B28);
#ifdef SKIP_ASM
extern "C" int func_00237B28(void* self, sPackSrc_7B28* src, sPackDst_7B28* dst)
{
    int i;
    int j;
    int n;
    dst->count = src->count;
    for (j = 0; j < 3; j++) {
        dst->mask[j] = 0;
    }
    n = 0;
    for (i = 0; i < src->count; i++) {
        unsigned char v = (int)(src->vals[i] * 255.0f);
        if (v != 0) {
            dst->mask[i >> 3] |= 1 << (i & 7);
            dst->vals[n++] = v;
        }
    }
    return n + 4;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237BE8);
#ifdef SKIP_ASM
extern "C" void func_00237BE8(void* self, sPackSrc_7B28* out, char* buf)
{
    sPackDst_7B28* in = (sPackDst_7B28*)buf;
    out->count = in->count;
    func_003E6448(out->vals, 0, 0x60);
    int k = 0;
    int i;
    for (i = 0; i < out->count; i++) {
        if ((in->mask[i >> 3] >> (i & 7)) & 1) {
            out->vals[i] = in->vals[k++] * 0.003921568859368563f;
        } else {
            out->vals[i] = 0.0f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237CB0);
#ifdef SKIP_ASM
extern "C" void func_00237CB0(uint seed)
{
    cBxPseudoRng_Seed(D_004C9548, seed);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237CD8);
#ifdef SKIP_ASM
extern "C" uint func_00237CD8(void)
{
    return cBxPseudoRng_NextInt(D_004C9548);
}
#endif

