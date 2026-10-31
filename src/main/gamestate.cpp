#include "common.h"

//100%
INCLUDE_ASM("main/gamestate", cGFGateState_gainFocus);
#ifdef SKIP_ASM
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
extern "C" void func_0029C420(void* p, int a1);
extern "C" void func_00234BE8(void* self, int a1);
int GetHashValue32(char* s);
extern char* D_004A2C68;
extern char* D_004A2EEC;
extern void* D_004A28A8;
extern int D_00534B30[];
extern signed char D_00535C10[];
extern char D_0047C038[];

struct sRace_234AD0 {
    char pad[0x8C];
    int f8C;
};

extern "C" void cGFGateState_gainFocus(void* self)
{
    (*(sRace_234AD0**)(D_004A2C68 + 0xC))->f8C = 0;
    if (D_004A2EEC != 0) {
        func_00258968(D_004A2EEC);
    }
    cBE_setState(0);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0) {
        func_002300F0(D_004A2C68);
    }
    func_0026F228(*(void**)(D_004A2C68 + 0x28));
    func_0026F7B8(*(void**)(D_004A2C68 + 0x28));
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int mode = D_00535C10[0];
    if (mode >= 4 && mode <= 6) {
        func_00233AA0(self);
        return;
    }
    cAI_setAIState(*(void**)(D_004A2C68 + 0xC), 4);
    func_0029C418(func_0028B180());
    func_0029C420(func_0028B180(), 3);
    func_00234BE8(self, GetHashValue32(D_0047C038));
    func_0039F840(*(char**)(D_004A2C68 + 0x48) + 0x18);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00234BE8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void* iface);
extern "C" int func_0022E098(void* world, int id);
extern "C" int func_00309DD0(void* mgr, int id, int a);
extern "C" void func_00309E50(void* mgr, int id, int a);
extern void* D_004A28A8;
extern void* D_004A3DD8;

extern "C" void func_00234BE8(void* self, int a1)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* world = *(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x78);
    int id = func_0022E098(world, *func_00144BC0(iface));
    if (func_00309DD0(D_004A3DD8, id, a1) != 0) {
        func_00309E50(D_004A3DD8, id, a1);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", cGFGateState_update);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int GetHashValue32(char* str);
extern "C" int func_00270280(void* p);
extern "C" void func_00234BE8(void* self, int a1);
extern "C" void* func_0039F9D8(void* list, int hash);
extern "C" void* func_0028B180(void);
extern "C" void func_0029C7B0(void* p);
void func_0028C8C0(void* self, int val);
extern "C" void func_00233AA0(void* self);
extern "C" void func_0029C420(void* p, int secs);
extern char* D_004A2C68;
extern signed char D_00535C10[];
extern char D_0047C048[];
extern char D_004A2AB0[];

struct sVEntry00234C68 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

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
    if (func_00270280(*(void**)(D_004A2C68 + 0x28)) != 0) {
        return;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C10[0] == 4) {
        return;
    }
    if (*(int*)(*(char**)(D_004A2C68 + 0xC) + 0x1C) <= 0) {
        func_00234BE8(self, GetHashValue32(D_0047C048));
        char* obj = (char*)func_0039F9D8(*(char**)(D_004A2C68 + 0x48) + 0x18, GetHashValue32(D_004A2AB0));
        if (obj != 0) {
            sVEntry00234C68* e = &(*(sVEntry00234C68**)(obj + 8))[24];
            e->fn(obj + e->delta, 6, 0);
        }
        func_0029C7B0(func_0028B180());
        func_0028C8C0(func_0028B180(), 0x78);
        func_00233AA0(self);
    }
    int frames = *(int*)(*(char**)(D_004A2C68 + 0xC) + 0x1C);
    float secs = frames / 60;
    if (frames % 60 == 0) {
        func_0029C420(func_0028B180(), (int)ffloor_00234C68(secs));
    }
}
#endif

extern "C" void* func_00233AF0(void* self);

//100%
INCLUDE_ASM("main/gamestate", func_00234DE0__FPv);
#ifdef SKIP_ASM
void* func_00234DE0(void* self)
{
    return func_00233AF0(self);
}
#endif

extern "C" void* func_00233B28(void* self);

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
extern "C" void cAI_setAIState(void*, int);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBE_setState(int state);
extern "C" void func_0039F840(void* list);
extern char* D_004A2C68;
extern signed char D_00535C10[];

extern "C" void func_00234E20(void)
{
    cAI_setAIState(*(void**)(D_004A2C68 + 0xC), 5);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C10[0] != 4) {
        char* g = D_004A2C68;
        *(int*)(*(char**)(g + 0xC) + 0x14) = 1;
        *(int*)(*(char**)(g + 0xC) + 0x8C) = 0;
    }
    cBE_setState(1);
    char* gs = D_004A2C68;
    int n = **(int**)(gs + 0x28);
    int ok = n != 0 && n < 10;
    if (!ok) {
        func_0039F840(*(char**)(gs + 0x48) + 0x18);
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
extern char D_0047D6E8[];
extern char D_0047D428[];
extern char* D_004A2C68;

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
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0026F228(void* p);
extern "C" void func_00278CD8(void* a);
extern "C" void func_002790A0(void* a, int b);
extern "C" void func_00278B98(void* a);
extern "C" void func_0012AB20(void* self);
extern "C" void func_0012AC48(void* self);
extern "C" int func_00145D38(void* self, int index, int bit);
extern "C" void func_0027AAF8(void* a, int b);
extern "C" void* func_0028B180(void);
extern void* D_004A28A4;
extern void* D_004A28A8;
extern char* D_004A2C68;
extern signed char D_00535C11[];

struct sVEntry_234F40 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sState_234F40 {
    int pad0[4];
    int f10;
    int f14;
    int f18;
};

extern "C" void func_00234F40(sState_234F40* self)
{
    self->f18 = 0;
    func_0026F228(*(void**)(D_004A2C68 + 0x28));
    func_002790A0(D_004A28A4, 0);
    func_00278CD8(D_004A28A4);
    func_00278B98(D_004A28A4);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    self->f14 = 0;
    int m = D_00535C11[0];
    func_0012AB20(*(void**)(D_004A2C68 + 0xC));
    func_0012AC48(*(void**)(D_004A2C68 + 0xC));
    if (m == 0) {
        int t = *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x78) + 0x1BC);
        if (t >= 14 && t <= 16) {
            void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
            char* sub = *(char**)(*(char**)(*(char**)(D_004A2C68 + 0xC) + 0x40) + 0x18) + 0x6C0;
            sVEntry_234F40* vt = *(sVEntry_234F40**)sub;
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

INCLUDE_ASM("main/gamestate", func_00235080);

//100%
INCLUDE_ASM("main/gamestate", func_00235570);
#ifdef SKIP_ASM
extern "C" void func_00278CD8(void* a);
extern "C" void func_002790A0(void* a, int b);
extern void* D_004A28A4;

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
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void cBE_setState(int state);
extern "C" void cAI_setAIState(void*, int);
extern "C" int func_0027AA80(void* a);
extern "C" void func_00158E30(void* iface);
extern "C" void func_00309030(void* a);
extern "C" void func_00309F18(void* a);
extern "C" int func_00144BE0(void* race);
extern "C" int func_00144CC0(void* race, int a);
extern "C" void func_00146E10(void* player, int a, int b);
extern "C" void func_001F36D8(void* hud, int a);
extern "C" int func_00278F68(void* self, int i, int a, int b);
extern "C" void* func_0028B180(void);
extern "C" void func_002B3A98(void* p);
extern "C" void func_002A4B68(void* p);
extern char* D_004A2C68;
extern void* D_004A3DD8;
extern void* D_004A28A8;
extern void* D_004A28A4;

struct sRace_2355C0 {
    char pad0[0x48];
    signed char mode48;
    signed char flag49;
};
extern sRace_2355C0 D_00535BC8_r2355C0 __asm__("D_00535BC8");

struct sRaceMan_2355C0 {
    char pad0[0x14];
    int f14;
};

struct sVE_2355C0 {
    short delta;
    short index;
    void (*fn)(void*);
};

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
    sRace_2355C0* r = &D_00535BC8_r2355C0;
    int flag = r->flag49;
    int mode = r->mode48;
    if (flag == 0 && !inRange_2355C0(*(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x78) + 0x1BC))) {
        *(int*)((char*)self + 0x4) = 0;
        *(int*)((char*)self + 0x0) = 4;
    } else {
        *(int*)((char*)self + 0x0) = 1;
        *(int*)((char*)self + 0x4) = flag == 0;
    }
    if (mode == 4)
        cAI_setAIState(*(void**)(D_004A2C68 + 0xC), 3);
    cBE_setState(0);
    func_00309030(D_004A3DD8);
    func_00309F18(D_004A3DD8);
    if (func_00144CC0(race, func_00144BE0(race)) == 1) {
        char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
        func_00146E10(player, 0, func_00144BE0(race));
        sVE_2355C0* vt = *(sVE_2355C0**)(player + 0xC);
        vt[1].fn(player + vt[1].delta);
    }
    (*(sRaceMan_2355C0**)(D_004A2C68 + 0xC))->f14 = mode != 4;
    func_001F36D8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94), 0);
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
extern "C" int func_0027AA80(void* a);
extern "C" int func_00279220(void* a, int b);
extern "C" void func_00233AA0(void* self);
extern void* D_004A28A4;
extern void* D_004A28A8;

extern "C" void func_002357F8(void* self)
{
    if (*(int*)((char*)self + 0x1C) != 0 && func_0027AA80(D_004A28A4) == 0) {
        *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x78) + 0x1A4) = 1;
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
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00308F38(void* a);
extern "C" void func_00308C60(void* a);
extern "C" void func_0026F228(void* p);
extern "C" void func_0026F7B8(void* p);
extern "C" void func_00145DD0(void* iface, int a1, int a2, int a3);
extern "C" void func_00238510(void* gm, int a1, int a2);

struct sRace_235868 {
    char pad0[0x48];
    signed char mode48;
    signed char flag49;
};
extern sRace_235868 D_00535BC8_r235868 __asm__("D_00535BC8");

struct sSlot_235868 {
    char pad[0x50];
};
struct sTbl_235868 {
    char pad[0x250];
    struct { int f0; char pad[0x4C]; } slot[2];
};

static inline int otherSide_235868(char* p)
{
    return *(int*)(p + 0xB0) == 0;
}

extern "C" void func_00235868(void* self)
{
    func_00308F38(D_004A3DD8);
    func_00308C60(D_004A3DD8);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    func_0026F228(*(void**)(D_004A2C68 + 0x28));
    func_0026F7B8(*(void**)(D_004A2C68 + 0x28));
    *(int*)((char*)self + 0x14) = 0;
    sRace_235868* r = &D_00535BC8_r235868;
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
        func_00238510(*(void**)((char*)D_004A28A8 + 0xC0), 0, 0);
    }
    char* g = *(char**)((char*)D_004A28A8 + 0x84);
    char* x = *(char**)(g + 0x84);
    if (*(int*)(x + 0x10) == 1) {
        sTbl_235868* t = **(sTbl_235868***)(g + 0x10);
        t->slot[otherSide_235868(*(char**)(x + 4))].f0 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235990);
#ifdef SKIP_ASM
struct sVEntry_func_00235990 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// PORT: func_00233AF0 also reads $a1 (the stream); bound with its real arity.
void* func_00233AF0_2(void* self, void* obj) __asm__("func_00233AF0");

extern "C" void func_00235990(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry_func_00235990* e = &(*(sVEntry_func_00235990**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00235990**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_00235990**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235A18);
#ifdef SKIP_ASM
struct sVEntry_func_00235A18 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// PORT: func_00233B28 also reads $a1 (the stream); bound with its real arity.
void* func_00233B28_2(void* self, void* obj) __asm__("func_00233B28");

extern "C" void func_00235A18(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry_func_00235A18* e = &(*(sVEntry_func_00235A18**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00235A18**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_00235A18**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235AA0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void cBE_setState(int state);
extern "C" void func_0030B7F8(void* self);
extern "C" void func_00230180(void* self);
extern "C" void func_0012AB20(void* self);
extern "C" void func_0012AC48(void* self);
extern "C" void func_002790A0(void* a, int b);
extern "C" void func_0027AAF8(void* a, int b);
// PORT: func_00278F38 returns func_00276270's result (ssxscriptengine defines it void).
extern "C" int func_00278F38(void* self, int i);
extern "C" void func_0027A860(void* a, int b, int c);
extern "C" void func_001F36C0(void* a, int b);
extern "C" void cGameModeMan_restartHeat(void* gm);
extern "C" int cBENewRaceInterface_setNumberAI(void* self, int count);
extern "C" void cBENewPlayerInterface_setRiderCharID(void* player, int i, int id);
extern "C" void func_001473D0(void* player, int i, int v);
extern char* D_004A2C68;
extern void* D_004A3DD8;
extern void* D_004A28A8;
extern void* D_004A28A4;

struct sRace_235AA0 {
    char pad0[0x48];
    signed char mode48;
    signed char flag49;
};
extern sRace_235AA0 D_00535BC8_r235AA0 __asm__("D_00535BC8");

struct sVE_235AA0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sGM_235AA0 {
    char pad0[0x10];
    int total;      // 0x10
    int humans;     // 0x14
    int chars[10];  // 0x18
    int boards[10]; // 0x40
};

extern "C" void func_00235AA0(void* self)
{
    cBE_setState(0);
    func_0030B7F8(D_004A3DD8);
    char* race = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
    char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
    sGM_235AA0* gm = *(sGM_235AA0**)((char*)D_004A28A8 + 0xC0);
    cGameModeMan_restartHeat(gm);
    func_00230180(*(void**)((char*)D_004A28A8 + 0x84));
    sRace_235AA0* r = &D_00535BC8_r235AA0;
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
    int n = gm->total - gm->humans;
    int base = *(int*)(*(char**)(D_004A2C68 + 0xC) + 0x7C);
    int i = 0;
    cBENewRaceInterface_setNumberAI(race, n);
    {
        sVE_235AA0* vt = *(sVE_235AA0**)(race + 0xC);
        vt[1].fn(race + vt[1].delta);
    }
    for (; i < n; i++) {
        cBENewPlayerInterface_setRiderCharID(player, i + base, gm->chars[base + i]);
        func_001473D0(player, i + base, gm->boards[base + i]);
    }
    {
        sVE_235AA0* vt = *(sVE_235AA0**)(player + 0xC);
        vt[1].fn(player + vt[1].delta);
    }
    func_0012AB20(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
    if (n >= 2)
        func_0012AC48(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
    *(int*)((char*)self + 0x18) = 0;
    sRace_235AA0* r2 = &D_00535BC8_r235AA0;
    if (r2->mode48 == 0) {
        void* sc = D_004A28A4;
        *(int*)((char*)self + 0x18) = 1;
        func_0027A860(sc, 1, 0);
    }
    func_002790A0(D_004A28A4, 0);
    func_0027AAF8(D_004A28A4, *(int*)((char*)gm + 0x98) ? 3 : 2);
    func_00278F38(D_004A28A4, 0);
    func_001F36C0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94), 3);
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235CC8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
struct sVec4_236960;
struct sVec4_235CC8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRaceMan_235CC8 {
    char pad0[0x14];
    int f14;
};

struct sCacheTbl_235CC8 {
    char pad[0x250];
    struct { int f0; char pad[0x4C]; } slot[2];
};

struct cRiderObj_235CC8 {
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

extern "C" int func_0012ABD0(void* p);
extern "C" void func_0012B030(void* p);
extern "C" void func_0012B000(void* p);
extern "C" void func_00128958(void* p);
extern "C" int func_0012A180(void* p);
void func_001289F0(void* p);
extern "C" void func_001296F8(void* p);
extern "C" sVec4_235CC8 func_00122C28(void* rider);
extern "C" void func_003A9658(void* cache, int idx, const sVec4_236960* pos, float radius);
extern "C" int func_003A9770(void* cache, int idx, sVec4_236960* pos, float* dist);
extern "C" int func_002791D8(void* p, int a);
extern "C" int func_00279298(void* p);
extern "C" bool func_0027A9F0(void* p);
extern "C" void func_00233AA0(void* self);
void* func_00230698(void* self, int id);
extern char* D_004A2C68;
extern void* D_004A28A8;
extern void* D_004A28A4;
extern int D_00535C04[];

extern "C" void func_00235CC8(void* self)
{
    *(int*)((char*)self + 0x14) += 1;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    char* g84 = *(char**)((char*)D_004A28A8 + 0x84);
    int state = *(int*)((char*)self + 0x10);
    char** cache = *(char***)(g84 + 0x10);
    int idx = *(int*)(*(char**)(*(char**)(g84 + 0x84) + 4) + 0xB0) == 0;
    switch (state) {
    case 0:
        if (func_0012ABD0(*(void**)(g84 + 0xC))) {
            func_0012B030(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
            if (D_00535C04[0] >= 2)
                func_0012B000(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
            func_00128958(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
            *(int*)((char*)self + 0x10) = 1;
        }
        break;
    case 1:
        if (func_0012A180(*(void**)(g84 + 0xC))) {
            func_001289F0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
            (*(sRaceMan_235CC8**)(D_004A2C68 + 0xC))->f14 = 1;
            ((sCacheTbl_235CC8*)*cache)->slot[idx].f0 = 1;
            char* r = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x40);
            sVec4_235CC8 pos = func_00122C28(*(void**)(r + 0x18));
            func_003A9658(*cache + 0x10, idx, (const sVec4_236960*)&pos, 45000.0f);
            *(int*)((char*)self + 0x10) = 2;
        } else {
            func_001296F8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
        }
        break;
    case 2:
        if (*(int*)((char*)self + 0x18) != 0) {
            sVec4_235CC8 v;
            float dist;
            func_003A9770(*cache + 0x10, idx, (sVec4_236960*)&v, &dist);
            if (dist < 20000.0f)
                break;
            if (*(int*)((char*)self + 0x14) < 120)
                break;
            if (func_002791D8(D_004A28A4, 0) == 1)
                break;
            char* o = (char*)func_00230698(*(void**)((char*)D_004A28A8 + 0x84), 0);
            if (func_00279298(D_004A28A4) != 0)
                break;
            if (((cRiderObj_235CC8*)(o + 0x10))->isBusy() != 0)
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
extern "C" void func_001F36D8(void* hud, int a);
extern void* D_004A28A8;

extern "C" void func_00235F20(void)
{
    func_001F36D8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94), 3);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235F48);
#ifdef SKIP_ASM
struct sVEntry_func_00235F48 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// PORT: func_00233AF0 also reads $a1 (the stream); bound with its real arity.
void* func_00233AF0_2(void* self, void* obj) __asm__("func_00233AF0");

extern "C" void func_00235F48(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry_func_00235F48* e = &(*(sVEntry_func_00235F48**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00235F48**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_00235F48**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00235FD0);
#ifdef SKIP_ASM
struct sVEntry_func_00235FD0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// PORT: func_00233B28 also reads $a1 (the stream); bound with its real arity.
void* func_00233B28_2(void* self, void* obj) __asm__("func_00233B28");

extern "C" void func_00235FD0(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry_func_00235FD0* e = &(*(sVEntry_func_00235FD0**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00235FD0**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_00235FD0**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236058);
#ifdef SKIP_ASM
extern "C" void func_0030B7F8(void* self);
extern "C" void cGameModeMan_initGameMode(void* gm, int mode);
extern "C" void func_00230180(void* self);
extern "C" void func_0011DE60(void* self, int a1, int a2);
extern "C" void func_0011DF18(void* self, int notify);
void* func_00230698(void* self, int id);
// PORT: func_002E4CE8 is the wake pool's allocator; it ignores the size the caller passes
extern "C" void* func_002E4CE8(int size);
void* func_002E4D70(void* self);
extern "C" void func_002E4370(void* self, int a1, int a2, void* a3, float f0, float f1, int a4, int a5, float f2);
extern void* D_004880C0[];

struct sColor_236058 {
    float r, g, b, a;
};

extern "C" void func_00236058(void* self)
{
    void* gm = *(void**)((char*)D_004A28A8 + 0xC0);
    func_0030B7F8(D_004A3DD8);
    float one = 1.0f;
    cGameModeMan_initGameMode(gm, 0xC);
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 0xA);
    func_00230180(*(void**)((char*)D_004A28A8 + 0x84));
    func_0011DE60(*(void**)(*(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x40) + 0x18), *(int*)(iface + 0x10), 2);
    func_0011DF18(*(void**)(*(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x40) + 0x18), 1);
    void* r = func_00230698(*(void**)((char*)D_004A28A8 + 0x84), 0);
    char* o = (char*)func_002E4CE8(0x14);
    sColor_236058 c;
    c.r = one;
    c.g = one;
    c.b = one;
    c.a = one;
    func_002E4D70(o);
    *(void***)o = D_004880C0;
    *(sColor_236058*)(o + 4) = c;
    func_002E4370(r, 1, 0, o, 0.0f, 0.0f, 0, 0, one);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236198);
#ifdef SKIP_ASM
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern void* D_004A28A8;

extern "C" void func_00236198(void)
{
    func_00231250(*(void**)((char*)D_004A28A8 + 0x84), 1, 0, 0);
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
extern char D_0047D6E8[];
extern char D_0047D320[];
extern char* D_004A2C68;

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
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void cAI_setAIState(void*, int);
extern "C" int* func_00144BC0(void* iface);
extern "C" void func_00230180(void* self);
extern "C" void func_0030B7F8(void* self);
extern "C" void func_0011D390(void* rider);
extern "C" void func_00278E50(void* self, int i, int a, int b, int c, int d, int f, int g);
// PORT: func_00278F38 returns func_00276270's result (ssxscriptengine defines it void).
extern "C" int func_00278F38(void* self, int i);
extern "C" int func_00278F68(void* self, int i, int a, int b);
extern char* D_004A2C68;
extern void* D_004A3DD8;
extern void* D_004A28A8;
extern void* D_004A28A4;
extern int D_004A11BC;

static inline int isOne_6250(int m)
{
    return m == 1;
}

extern "C" void func_00236250(void* self, int mode)
{
    func_0030B7F8(D_004A3DD8);
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    cAI_setAIState(*(void**)(D_004A2C68 + 0xC), 3);
    *(int*)(*(char**)(*(char**)(*(char**)(D_004A2C68 + 0xC) + 0x40) + 0x18) + 0x2F8) = 0;
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
        func_00230180(*(void**)((char*)D_004A28A8 + 0x84));
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
            func_0011D390(*(void**)(*(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x40) + 0x18));
            func_00278F68(D_004A28A4, 1, *(int*)((char*)self + 0x14) == 2, 0);
        }
    }
}
#endif

INCLUDE_ASM("main/gamestate", func_00236418);

//100%
INCLUDE_ASM("main/gamestate", func_00236728);
#ifdef SKIP_ASM
struct sVEntry_func_00236728 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// PORT: func_00233AF0 also reads $a1 (the stream); bound with its real arity.
void* func_00233AF0_2(void* self, void* obj) __asm__("func_00233AF0");

extern "C" void func_00236728(void* self, void* stream)
{
    func_00233AF0_2(self, stream);
    sVEntry_func_00236728* e = &(*(sVEntry_func_00236728**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_00236728**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_00236728**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x8, 4);
    e = &(*(sVEntry_func_00236728**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_002367C8);
#ifdef SKIP_ASM
struct sVEntry_func_002367C8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// PORT: func_00233B28 also reads $a1 (the stream); bound with its real arity.
void* func_00233B28_2(void* self, void* obj) __asm__("func_00233B28");

extern "C" void func_002367C8(void* self, void* stream)
{
    func_00233B28_2(self, stream);
    sVEntry_func_002367C8* e = &(*(sVEntry_func_002367C8**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x10, 4);
    e = &(*(sVEntry_func_002367C8**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x14, 4);
    e = &(*(sVEntry_func_002367C8**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x8, 4);
    e = &(*(sVEntry_func_002367C8**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x18, 4);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236868);
#ifdef SKIP_ASM
extern char D_0047D6E8[];
extern char D_0047D2C8[];
extern char* D_004A2C68;

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
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBE_setState(int state);
extern "C" void func_0026F228(void* p);
extern "C" void func_00145CB0(void* iface, int i, int a);
extern char* D_004A2C68;

struct sRace002368A0 {
    char pad0[0x30];
    int count;
    char pad34[0x15];
    signed char flag49;
};
extern sRace002368A0 D_00535BC8_r002368A0 __asm__("D_00535BC8");

extern "C" void func_002368A0(void* self)
{
    cBE_setState(0);
    func_0026F228(*(void**)(D_004A2C68 + 0x28));
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BC8_r002368A0.flag49 == 0) {
        int i = 0;
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        for (; i < D_00535BC8_r002368A0.count; i++) {
            func_00145CB0(iface, i, 0);
        }
    }
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236960);
#ifdef SKIP_ASM
struct sVec4_236960 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct cRiderObj_236960 {
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

extern "C" int func_0022D278(void* self, int idx);
extern "C" void func_0022D088(void* self, int idx, int mode);
extern "C" sVec4_236960 func_00123F38(void* rider);
extern "C" void func_003A9658(void* cache, int idx, const sVec4_236960* pos, float radius);
extern "C" int func_003A9770(void* cache, int idx, sVec4_236960* pos, float* dist);
extern "C" int func_00279298(void* p);
extern "C" bool func_0027A9F0(void* p);
extern void* D_004A28A4;

extern "C" void func_00236960(void* self)
{
    char* g84 = *(char**)((char*)D_004A28A8 + 0x84);
    char* game = *(char**)(g84 + 0x78);
    if (*(int*)(game + 0x1C8) == 0) {
        return;
    }
    int state = *(int*)((char*)self + 0x10);
    char** cache = *(char***)(g84 + 0x10);
    int idx = *(int*)(*(char**)(*(char**)(g84 + 0x84) + 4) + 0xB0) == 0;
    switch (state) {
    case 0:
        if (func_0022D278(game, *(int*)(game + 0x1BC)) != 0) {
            char* r = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x40);
            sVec4_236960 pos = func_00123F38(*(void**)(r + 0x18));
            char* e = *cache + idx * 0x50;
            *(int*)(e + 0x250) = 1;
            func_003A9658(*cache + 0x10, idx, &pos, 45000.0f);
            *(int*)((char*)self + 0x10) = 1;
        }
        break;
    case 1: {
        sVec4_236960 v;
        float dist;
        func_003A9770(*cache + 0x10, idx, &v, &dist);
        if (dist < 20000.0f) {
            break;
        }
        char* o = (char*)func_00230698(*(void**)((char*)D_004A28A8 + 0x84), 0);
        if (((cRiderObj_236960*)(o + 0x10))->isBusy() != 0) {
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
class cRace236B38 {
public:
    char pad[0xCC];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int);
};
extern char* D_004A2C68;

extern "C" void func_00236B38(void)
{
    (*(cRace236B38**)(D_004A2C68 + 0xC))->v05(3);
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
extern "C" void cBE_setState(int state);
extern "C" void func_002EA820(void* p);
extern "C" void func_0020A8F8(int mode);
extern char* D_004A2EEC;
struct sMgr_6BB0 {
    char pad0[0x64];
    void* world;    // 0x64
};
struct sApp_6BB0 {
    char pad0[0x84];
    sMgr_6BB0* mgr; // 0x84
};
extern sApp_6BB0* D_004A28A8_s __asm__("D_004A28A8");
extern int D_004A2A50;
extern int D_004A2A54;
extern int D_005366E8[];
extern int D_004428F4[];

struct sGameState_6BB0 {
    char pad0[8];
    int done;   // 0x8
};

// Ends the game state: pushes front-end state 1 unless D_004A2EEC is active, then hands control back.
extern "C" void func_00236BB0(sGameState_6BB0* self)
{
    self->done = 0;
    if (D_004A2EEC != 0 && *(int*)(D_004A2EEC + 4) != 0) {
        func_002EA820(D_004A28A8_s->mgr->world);
        cBE_setState(0);
        return;
    }
    func_0020A8F8(2);
    D_005366E8[++D_004A2A54] = 1;
    D_004A2A50 = D_004428F4[0];
    func_002EA820(D_004A28A8_s->mgr->world);
    cBE_setState(0);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236C48);
#ifdef SKIP_ASM
extern "C" void func_00233AA0(void* self);
extern char* D_004A2EEC;

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
extern "C" void func_00236CD8(void* self);
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_004428F0[];

extern "C" void func_00236C88(void* self)
{
    D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
    func_00236CD8(self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236CD8);
#ifdef SKIP_ASM
class cRace236CD8 {
public:
    char pad[0xCC];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int);
};
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_002790A0(void* a, int b);
extern "C" void* func_0028B180(void);
extern "C" void func_002871B0(void* mgr);
extern void* D_004A28A4;
extern char* D_004A2C68;
extern signed char D_00535C10[];

static inline int isMode4_236CD8()
{
    return D_00535C10[0] == 4;
}

extern "C" void func_00236CD8(void* self)
{
    func_002790A0(D_004A28A4, 0);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (!isMode4_236CD8()) {
        (*(cRace236CD8**)(D_004A2C68 + 0xC))->v05(3);
        *(int*)(*(char**)(D_004A2C68 + 0xC) + 0x14) = 1;
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
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00145CB0(void* iface, int i, int a);
extern "C" void func_002790A0(void* a, int b);
extern "C" void func_0020A8F8(int a);
extern void* D_004A28A4;

struct sRace00236DA0 {
    char pad0[0x30];
    int count;
    char pad34[0x15];
    signed char flag49;
};
extern sRace00236DA0 D_00535BC8_r00236DA0 __asm__("D_00535BC8");

extern "C" void func_00236DA0(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BC8_r00236DA0.flag49 == 0) {
        int i = 0;
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        for (; i < D_00535BC8_r00236DA0.count; i++) {
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
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern void* D_004A28A8;

extern "C" void func_00236E60(void* self)
{
    if (*(int*)((char*)self + 8) == 1) {
        func_00231250(*(void**)((char*)D_004A28A8 + 0x84), 0xE, 2, 0);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236EA0);
#ifdef SKIP_ASM
extern "C" void func_0039F840(void* list);
extern char* D_004A2C68;

extern "C" void func_00236EA0(void)
{
    func_0039F840(*(char**)(D_004A2C68 + 0x48) + 0x18);
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
extern "C" void* func_0028B180(void);
extern "C" void func_0028CDF8(void* mgr);
extern void* D_004A28A8;

extern "C" void func_00236F08(void)
{
    func_0028CDF8(func_0028B180());
    *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x8C) = 1;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00236F40);
#ifdef SKIP_ASM
extern "C" int func_00279220(void* a, int b);
extern "C" void func_00233AA0(void* self);
extern void* D_004A28A4;

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
extern void* D_004A28A8;

extern "C" void func_00236F90(void)
{
    *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x8C) = 0;
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
extern "C" void func_00309030(void* a);
extern "C" void func_00309F18(void* a);
extern "C" void func_001F36D8(void* hud, int a);
extern "C" void func_0020AB50(int state);
extern void* D_004A3DD8;
extern void* D_004A28A8;

extern "C" void func_00236FE8(void)
{
    func_00309030(D_004A3DD8);
    func_00309F18(D_004A3DD8);
    func_001F36D8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x94), 0);
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
extern "C" void func_00308F38(void* a);
extern "C" void func_00308C60(void* a);
extern void* D_004A3DD8;

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
void cMemMan_free(void*);
void operator_delete(int*);

struct sEntry_func_002370A0 {
    void* buf;
    int pad[3];
    int* a;
    int* b;
};

struct sObj_func_002370A0 {
    char pad[0x10];
    int count;
    sEntry_func_002370A0 entries[1];
};

extern "C" void func_002370A0(sObj_func_002370A0* self, int flags)
{
    int i;
    for (i = 0; i < self->count; i++) {
        sEntry_func_002370A0* e = &self->entries[i];
        if (e->buf)
            cMemMan_free(e->buf);
        operator_delete(e->a);
        operator_delete(e->b);
    }
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237140);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_003E6448(void* dst, int value, int size);
// PORT: func_00244400__FPvi takes the 0x2A4-byte block as an int (pointer in int)
void func_00244400(void* self, int a1);
void func_00244408(void* self, int a1);
extern char D_0047C078[];
extern char D_0047C088[];
extern char D_0047C098[];

struct sRec_237140 {
    int type;
    char pad[0x60];
};

struct sEntry_237140 {
    sRec_237140* recs;
    int f4;
    int f8;
    int fC;
    int* f10;
    void* f14;
};

struct sOwner_237140 {
    int f0;
    int count;
    int pad8[2];
    int n;
    sEntry_237140 entries[1];
};

static inline void* initObj_237140(void* o, int a, int b)
{
    func_00244400(o, a);
    func_00244408(o, b);
    return o;
}

extern "C" void* func_00237140(sOwner_237140* self, int* a1)
{
    sEntry_237140* e = &self->entries[self->n++];
    e->recs = (sRec_237140*)operator_new_tag(self->count * 100, D_0047C078, 0, 0);
    func_003E6448(e->recs, 0, self->count * 100);
    for (int i = 0; i < self->count; i++) {
        e->recs[i].type = 0x18;
    }
    e->f4 = 0;
    e->f8 = self->f0;
    e->fC = a1[0];
    e->f10 = (int*)cMemMan_alloc(0x2A4, D_0047C088, 0, 0);
    *e->f10 = 0;
    void* o = initObj_237140(cMemMan_alloc(8, D_0047C098, 0, 0), (int)e->f10, a1[1]);
    e->f14 = o;
    return o;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237280);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_003E6448(void* dst, int value, int size);
// PORT: func_00244400__FPvi takes the 0x2A4-byte block as an int (pointer in int)
void func_00244400(void* self, int a1);
void func_00244408(void* self, int a1);
extern char D_0047C078[];
extern char D_0047C088[];
extern char D_0047C098[];

struct sRec_237280 {
    int type;
    char pad[0x60];
};

struct sEntry_237280 {
    sRec_237280* recs;
    int f4;
    int f8;
    int fC;
    int* f10;
    void* f14;
};

struct sOwner_237280 {
    int f0;
    int count;
    int pad8[2];
    int n;
    sEntry_237280 entries[1];
};

static inline void* initObj_237280(void* o, int a, int b)
{
    func_00244400(o, a);
    func_00244408(o, b);
    return o;
}

extern "C" void* func_00237280(sOwner_237280* self, int a1)
{
    sEntry_237280* e = &self->entries[self->n++];
    e->recs = (sRec_237280*)operator_new_tag(self->count * 100, D_0047C078, 0, 0);
    func_003E6448(e->recs, 0, self->count * 100);
    for (int i = 0; i < self->count; i++) {
        e->recs[i].type = 0x18;
    }
    e->f4 = 0;
    e->f8 = self->f0;
    e->fC = 0;
    e->f10 = (int*)cMemMan_alloc(0x2A4, D_0047C088, 0, 0);
    *e->f10 = 0;
    void* o = initObj_237280(cMemMan_alloc(8, D_0047C098, 0, 0), (int)e->f10, a1);
    e->f14 = o;
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
struct sSlot237950 {
    int f0;
    int cur;
    int max;
    int pad[3];
};
struct sOwner237950 {
    char pad[0x10];
    int count;
    sSlot237950 slots[1];
};
extern char* D_004A2EEC;

extern "C" int func_00237950(sOwner237950* self)
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
        sSlot237950* s = &self->slots[i];
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
extern "C" void func_00321298(void* target, int a, void* data);

struct sFrame002379C8 {
    int first;
    char data[0x60];
};
struct sTrack002379C8 {
    sFrame002379C8* frames;
    int cur;
    int f8;
    int fC;
    void* target;
    int f14;
};
struct sPlayer002379C8 {
    int f0;
    int nFrames;
    int f8;
    int fC;
    int count;
    sTrack002379C8 tracks[1];
};

extern "C" int func_002379C8(sPlayer002379C8* self)
{
    if (*(int*)(D_004A2EEC + 0x70) < 14) {
        return 0;
    }
    if (func_00237950((sOwner237950*)self) == 0) {
        return 0;
    }
    int i;
    for (i = 0; i < self->count; i++) {
        sTrack002379C8* t = &self->tracks[i];
        sFrame002379C8* f = &t->frames[t->cur % self->nFrames];
        func_00321298(t->target, f->first, f->data);
        t->cur++;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237A98);
#ifdef SKIP_ASM
struct sPackSrc_7B28;
struct sPackDst_7B28;
extern "C" int func_00237B28(void* self, sPackSrc_7B28* src, sPackDst_7B28* dst);
extern "C" void func_00237BE8(void* self, sPackSrc_7B28* src, char* buf);
extern "C" int func_00257E98(void* mgr, int a, char* buf, int len);
extern char* D_004A2EEC;

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
struct sPackSrc_7B28 {
    int count;
    float vals[1];
};

struct sPackDst_7B28 {
    unsigned char count;
    unsigned char mask[3];
    unsigned char vals[1];
};

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
extern "C" void func_003E6448(void* dst, int value, int size);

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
extern "C" void cBxPseudoRng_Seed(uint* state, uint seed);
extern uint D_004C9548[];

extern "C" void func_00237CB0(uint seed)
{
    cBxPseudoRng_Seed(D_004C9548, seed);
}
#endif

//100%
INCLUDE_ASM("main/gamestate", func_00237CD8);
#ifdef SKIP_ASM
extern "C" uint cBxPseudoRng_NextInt(uint* state);
extern uint D_004C9548[];

extern "C" uint func_00237CD8(void)
{
    return cBxPseudoRng_NextInt(D_004C9548);
}
#endif

