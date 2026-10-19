#include "common.h"

INCLUDE_ASM("fe/debugfe", cDebugMenuScreen_draw);

//100%
INCLUDE_ASM("fe/debugfe", func_0017D008);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern void* D_004A28A8;
struct sDbgRaceSel17D008 {
    char pad_0x00[0x48];
    signed char mode;  // 0x48
    signed char slot;  // 0x49
};
extern sDbgRaceSel17D008 D_00535BC8;
class cBENewRaceIfaceK17D008 {
public:
    char pad_0x00[0xC];
    virtual int v01();
};
struct sDbgFE17D008 {
    char pad_0x0000[0x8C38];
    int modes[8]; // 0x8C38
};
extern "C" void func_00145108(void* iface, int idx);
extern "C" void cBENewRaceInterface_setGameMode(void* iface, int mode);

extern "C" void func_0017D008(void* self, int idx)
{
    cBENewRaceIfaceK17D008* iface = (cBENewRaceIfaceK17D008*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 0);
    ((sDbgFE17D008*)self)->modes[D_00535BC8.slot] = D_00535BC8.mode;
    func_00145108(iface, idx);
    cBENewRaceInterface_setGameMode(iface, ((sDbgFE17D008*)self)->modes[idx]);
    iface->v01();
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017D0A8);
#ifdef SKIP_ASM
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int cCommSystem_openDSockChannel(void* comm, const char* addr, int port, int host);
extern "C" void func_00256038(void* comm, int* info);
extern "C" int func_00255D50(void* comm, int ch);
extern "C" void func_00255A20(void* comm);
extern "C" void SYNCTASK_run(int a);
extern "C" void THREAD_yieldticks(int n);
extern "C" void cGameComm_construct(int ch, int host);
extern "C" void func_00266D58(void* p, int ip);
extern "C" void func_00266E30(void* p);
extern void* D_004A28A8;
extern void* D_004A2EB8;
extern void* D_004A33F4;
extern char D_0045D018[] __attribute__((aligned(8)));
extern char D_0045D028[] __attribute__((aligned(8)));

struct sNetCfg_D0A8 {
    int active;             // 0x0
    int f4;
    int host;               // 0x8
    unsigned short port;    // 0xC
};
extern sNetCfg_D0A8 D_00534B30_D0A8 __asm__("D_00534B30");

// Debug menu: opens the direct-socket link to the paired test console and starts the game comm.
extern "C" void func_0017D0A8(void)
{
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30_D0A8.active == 0) {
        return;
    }
    char addr[32];
    int info[4];
    func_00256038(D_004A2EB8, info);
    if (info[0] == 0x0A0A3519) {
        __builtin_memcpy(addr, D_0045D018, 12);
    } else {
        __builtin_memcpy(addr, D_0045D028, 12);
    }
    int ch;
    if (D_00534B30_D0A8.host) {
        ch = cCommSystem_openDSockChannel(D_004A2EB8, addr, D_00534B30_D0A8.port, 1);
    } else {
        ch = cCommSystem_openDSockChannel(D_004A2EB8, addr, D_00534B30_D0A8.port, 0);
    }
    while (func_00255D50(D_004A2EB8, ch) == 0) {
        func_00255A20(D_004A2EB8);
        SYNCTASK_run(0);
        THREAD_yieldticks(1);
    }
    cGameComm_construct(ch, D_00534B30_D0A8.host);
    func_00266D58(D_004A33F4, info[0]);
    func_00266E30(D_004A33F4);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017D1B8);
#ifdef SKIP_ASM
extern "C" int func_0017D1B8(void* self, int a, int b)
{
    int r = (a == 2) ? 4 : 5;
    switch (b) {
    case 0: case 4: case 5: case 6:
        r = 0;
        break;
    case 1: case 2: case 3:
        r = 1;
        break;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017D200);
#ifdef SKIP_ASM
extern void* D_0046D740[];
extern char D_0045D060[];
void* func_002CAA58(void* self);
extern "C" void* func_002CCDF0(void* self, void* text);
extern "C" void cMenu_addItem(void* menu, void* item, int index);

extern "C" void* func_0017D200(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D740;
    func_002CCDF0((char*)self + 0x130, D_0045D060);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017D260);
#ifdef SKIP_ASM
extern void* D_004A4E90;
extern "C" void func_0017D6F0(void* self, void* ev);
extern "C" void func_00259230(void* ev);

extern "C" void func_0017D260(void* self, void* ev)
{
    if (D_004A4E90 != 0)
        func_0017D6F0(D_004A4E90, ev);
    func_00259230(ev);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017D298);
#ifdef SKIP_ASM
extern void* D_0046D350[];
extern int D_004A3E90;
extern void* D_004A4E90;
extern "C" void* func_002CC018(void* self);
extern "C" void* func_001DA988(void* self, void* a, void* b);
extern "C" void* func_001DACB8(void* self, void* a, void* b, void* c);
extern "C" void* func_001DAE20(void* self, void* a);
extern "C" void* func_001DAF08(void* self, void* a, void* b);
extern "C" void* func_001DB028(void* self, void* a);
extern "C" void* __sti__all_in_one_main_cpp(void* self, void* a, void* b);
extern "C" void* func_001DB2B0(void* self, void* a);

// Owner reference handed to each debug sub-menu (a one-pointer functor).
struct sDbgOwner17D298 {
    void* owner;
};

extern "C" void* func_0017D298(char* self)
{
    *(void***)self = D_0046D350;
    *(int*)(self + 0x4) = 0;
    func_002CC018(self + 0x8);
    sDbgOwner17D298 o0;
    o0.owner = self;
    sDbgOwner17D298 o1;
    o1.owner = self;
    func_001DA988(self + 0x70, &o0, &o1);
    func_0017D200(self + 0x604);
    sDbgOwner17D298 o2;
    o2.owner = self;
    sDbgOwner17D298 o3;
    o3.owner = self;
    sDbgOwner17D298 o4;
    o4.owner = self;
    func_001DACB8(self + 0x74C, &o2, &o3, &o4);
    sDbgOwner17D298 o5;
    o5.owner = self;
    func_001DAE20(self + 0xD2C, &o5);
    sDbgOwner17D298 o6;
    o6.owner = self;
    sDbgOwner17D298 o7;
    o7.owner = self;
    func_001DAF08(self + 0x1044, &o6, &o7);
    sDbgOwner17D298 o8;
    o8.owner = self;
    func_001DB028(self + 0x1534, &o8);
    sDbgOwner17D298 o9;
    o9.owner = self;
    sDbgOwner17D298 o10;
    o10.owner = self;
    __sti__all_in_one_main_cpp(self + 0x18C0, &o9, &o10);
    sDbgOwner17D298 o11;
    o11.owner = self;
    func_001DB2B0(self + 0x1AAC, &o11);
    int g = D_004A3E90;
    char* app = (char*)D_004A28A8;
    *(int*)(self + 0x1C04) = g;
    *(int*)(self + 0x1C08) = g;
    *(int*)(self + 0x1C0C) = g;
    *(int*)(self + 0x60) = *(int*)(*(char**)(app + 0x80) + 0x18);
    *(int*)(self + 0x64) = *(int*)(app + 0xB0);
    *(int*)(self + 0x68) = *(int*)(*(char**)(app + 0x80) + 0x20);
    D_004A4E90 = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017D3B0);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void func_002CA280(void* self, int flags);
extern "C" void func_002CAA80(void* self, int flags);
extern "C" void func_001DD0C8(void* self, int flags);
extern "C" void func_001DCEA0(void* self, int flags);
extern "C" void func_002CC048(void* self, int flags);
void operator_delete(int* ptr);
extern void* D_0046D350[];
extern void* D_0046D948[];
extern void* D_004A4E90;

struct sVE_17D3B0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

#define DTOR_ARR_17D3B0(base, n)                                  \
    if ((base) != 0) {                                            \
        char* p = (base) + (n) * 0x24;                            \
        while ((base) != p) {                                     \
            p -= 0x24;                                            \
            sVE_17D3B0* vt = *(sVE_17D3B0**)(p + 0x10);           \
            vt[1].fn(p + vt[1].delta, 0);                         \
        }                                                         \
    }

static inline void dtorA_17D3B0(char* sub)
{
    func_002CA280(sub + 0x134, 2);
    func_002CAA80(sub, 2);
}

static inline void dtorB_17D3B0(char* sub)
{
    func_002CA280(sub + 0x1C8, 2);
    func_002CA280(sub + 0x1A4, 2);
    func_002CA280(sub + 0x18C, 2);
    func_002CA280(sub + 0x170, 2);
    func_002CA280(sub + 0x154, 2);
    func_002CA280(sub + 0x138, 2);
    func_002CAA80(sub, 2);
}

static inline void dtorC_17D3B0(char* sub)
{
    DTOR_ARR_17D3B0(sub + 0x194, 14)
    func_002CA280(sub + 0x168, 2);
    func_002CA280(sub + 0x150, 2);
    func_002CA280(sub + 0x134, 2);
    func_002CAA80(sub, 2);
}

static inline void dtorD_17D3B0(char* sub)
{
    func_002CA280(sub + 0x4CC, 2);
    DTOR_ARR_17D3B0(sub + 0x16C, 24)
    func_002CA280(sub + 0x154, 2);
    func_002CA280(sub + 0x138, 2);
    func_002CAA80(sub, 2);
}

static inline void dtorE_17D3B0(char* sub)
{
    DTOR_ARR_17D3B0(sub + 0x168, 12)
    func_002CA280(sub + 0x150, 2);
    func_002CA280(sub + 0x134, 2);
    func_002CAA80(sub, 2);
}

static inline void dtorF_17D3B0(char* sub)
{
    func_002CA280(sub + 0x130, 2);
    func_002CAA80(sub, 2);
}

extern "C" void func_0017D3B0(char* self, int flags)
{
    *(void***)self = D_0046D350;
    D_004A4E90 = 0;
    cBXString__cBXString(self + 0x1C0C, 2);
    cBXString__cBXString(self + 0x1C08, 2);
    cBXString__cBXString(self + 0x1C04, 2);
    dtorA_17D3B0(self + 0x1AAC);
    dtorB_17D3B0(self + 0x18C0);
    dtorC_17D3B0(self + 0x1534);
    dtorD_17D3B0(self + 0x1044);
    dtorE_17D3B0(self + 0xD2C);
    func_001DD0C8(self + 0x74C, 2);
    dtorF_17D3B0(self + 0x604);
    func_001DCEA0(self + 0x70, 2);
    func_002CC048(self + 0x8, 2);
    *(void***)self = D_0046D948;
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017D688);
#ifdef SKIP_ASM
extern void* D_004A2EB8;
extern void* D_004A3028;
extern "C" void func_00255A20(void*);
extern "C" void func_0025AC50(void*);
extern "C" void func_002CC0C0(void* stack);
extern "C" void func_0017DB18(void* self);

struct sMenuStack17D688 {
    int count;      // 0x0
    void* items[8]; // 0x4
};
struct sDebugFE17D688 {
    int f0;
    int f4;
    sMenuStack17D688 stack; // 0x8
};

static inline void* sMenuStack17D688_top(sMenuStack17D688* s)
{
    if (s->count > 0)
        return s->items[s->count - 1];
    return 0;
}

extern "C" void func_0017D688(sDebugFE17D688* self)
{
    func_00255A20(D_004A2EB8);
    func_0025AC50(D_004A3028);
    if (sMenuStack17D688_top(&self->stack) != 0)
        func_002CC0C0(&self->stack);
    func_0017DB18(self);
}
#endif

INCLUDE_ASM("fe/debugfe", func_0017D6F0);

//100%
INCLUDE_ASM("fe/debugfe", func_0017DA30);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern void* D_004A3028;
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_002CC3B8(void* menu, void* items);
extern "C" void func_0025C610(void* net);
static inline void SetMode0017DA30(void* self, int mode)
{
    *(int*)((char*)self + 0x4) = mode;
    func_002CC3B8((char*)self + 0x8, (char*)self + 0x604);
}
// Advances the debug menu to the follow-up screen for the current mode.
extern "C" void func_0017DA30(void* self, int a1)
{
    *(int*)((char*)self + 0x1C14) = a1;
    switch (*(int*)((char*)self + 0x4)) {
    case 2:
        SetMode0017DA30(self, 0x12);
        break;
    case 4:
        SetMode0017DA30(self, 0x14);
        break;
    case 5:
        if (*(int*)((char*)D_004A28A8 + 0x74) != 0) {
            cBXString_cBXString4((char*)D_004A3028 + 0x48, *(char**)((char*)D_004A28A8 + 0xC4));
            cBXString_cBXString4((char*)D_004A3028 + 0x4C, *(char**)((char*)D_004A28A8 + 0xC8));
            func_0025C610(D_004A3028);
        } else {
            SetMode0017DA30(self, 0x15);
        }
        break;
    case 7:
        SetMode0017DA30(self, 0x16);
        break;
    case 8:
        SetMode0017DA30(self, 0x16);
        break;
    case 9:
        SetMode0017DA30(self, 0x16);
        break;
    case 11:
        SetMode0017DA30(self, 0x17);
        break;
    case 13:
        SetMode0017DA30(self, 0x18);
        break;
    }
}
#endif

INCLUDE_ASM("fe/debugfe", func_0017DB18);

//100%
INCLUDE_ASM("fe/debugfe", func_0017DE70);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void func_00145108(void* iface, int idx);
extern "C" void cBENewRaceInterface_setGameMode(void* iface, int mode);
extern "C" int cBENewRaceInterface_setNumberAI(void* iface, int n);
extern "C" void cBENewPlayerInterface_setRiderCtrlID(void* iface, int rider, int ctrl);
extern "C" void cBENewPlayerInterface_setRiderCharID(void* iface, int rider, int id);
extern "C" void func_001472C8(void* iface, int a1, int a2);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int cCommSystem_openDSockChannel(void* comm, const char* addr, int port, int host);
extern void* D_004A28A8;
extern void* D_004A2EB8;
extern void* D_004A3028;
extern int D_004A11B8;
extern int D_00535C08[];
extern char D_0045CF98[];

struct sNetCfg_17DE70 {
    int active;
    int f4;
    int host;
    unsigned short port;
};
extern sNetCfg_17DE70 D_00534B30_cfg __asm__("D_00534B30");

struct sVEnt_17DE70 { short delta; short index; void (*fn)(void*); };

static inline void vcall1_17DE70(void* obj)
{
    sVEnt_17DE70* vt = *(sVEnt_17DE70**)((char*)obj + 0xC);
    vt[1].fn((char*)obj + vt[1].delta);
}

extern "C" void func_0017DE70(char* self)
{
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    func_00145108(race, 1);
    cBENewRaceInterface_setGameMode(race, 4);
    cBENewRaceInterface_setNumberAI(race, 0);
    D_00535C08[0] = 0;
    D_004A11B8 = 1;
    vcall1_17DE70(race);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    for (int i = 2; i < 6; i++) {
        cBENewPlayerInterface_setRiderCtrlID(player, i, -1);
        cBENewPlayerInterface_setRiderCharID(player, i, 0);
    }
    func_001472C8(player, 0, 0);
    func_001472C8(player, 1, -1);
    vcall1_17DE70(player);
    void* net = cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    sNetCfg_17DE70* cfg = &D_00534B30_cfg;
    D_00534B30_cfg.active = 1;
    cfg->host = *(int*)((char*)D_004A3028 + 0xB4);
    vcall1_17DE70(net);
    unsigned int ip;
    if (cfg->host) {
        ip = *(unsigned int*)((char*)D_004A3028 + 0xAC);
    } else {
        ip = *(unsigned int*)((char*)D_004A3028 + 0xA8);
    }
    char buf[256];
    sprintf(buf, D_0045CF98, ip >> 24, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
    *(int*)(self + 0x1C10) = cCommSystem_openDSockChannel(D_004A2EB8, buf, D_00534B30_cfg.port, D_00534B30_cfg.host);
    *(int*)(self + 4) = 0x10;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E030);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern "C" void func_002CC460(void* list);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_0025B9C8(void* mgr, void* req);
extern char D_0045D248[];

struct sDebugFEState17E030 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};

struct sDsReq17E030 {
    char pad_0x000[0x260];
    char* user;     // 0x260
    char* pass;     // 0x264
    char* pass2;    // 0x268
    char* host;     // 0x26C
    char pad_0x270[0x288 - 0x270];
    int f288;
    int f28C;
    int port;       // 0x290
    int f294;
    int f298;
    int f29C;
};

extern "C" void func_0017E030(sDebugFEState17E030* self, const char* a, const char* b)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    cBXString_cBXString4((char*)self + 0x1C04, a);
    cBXString_cBXString4((char*)self + 0x1C08, b);
    self->state = 0x4;
    sDsReq17E030* g = (sDsReq17E030*)D_004A3028;
    cBXString_cBXString4(&g->user, a);
    cBXString_cBXString4(&g->pass, b);
    cBXString_cBXString4(&g->pass2, b);
    cBXString_cBXString4(&g->host, D_0045D248);
    g->port = 0x79E;
    g->f294 = 1;
    g->f288 = 1;
    g->f29C = 0;
    g->f298 = 0;
    g->f28C = 1;
    func_0025B9C8(D_004A3028, &g->user);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E118);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern "C" void func_002CC460(void* list);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_0025C610(void* mgr);

struct sDebugFEState17E118 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
    char pad_0x0C[0x1C04 - 0xC];
    char* user;  // 0x1C04
    char* pass;  // 0x1C08
};

extern "C" void func_0017E118(sDebugFEState17E118* self, const char* a, const char* b)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    cBXString_cBXString4(&self->user, a);
    cBXString_cBXString4(&self->pass, b);
    self->state = 0x5;
    cBXString_cBXString4((char*)D_004A3028 + 0x48, self->user);
    cBXString_cBXString4((char*)D_004A3028 + 0x4C, self->pass);
    func_0025C610(D_004A3028);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E1C0);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E1C0 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
extern "C" void func_0025D1B8(void* a, int b);

extern "C" void func_0017E1C0(sDebugFEState17E1C0* self, int arg)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    self->state = 0x8;
    func_0025D1B8(D_004A3028, arg);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E228);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E228 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
extern "C" void func_0025D428(void* a, int b);

extern "C" void func_0017E228(sDebugFEState17E228* self, int arg)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    self->state = 0x9;
    func_0025D428(D_004A3028, arg);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E290);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E290 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
void func_0025CD28(void* a, int b);

extern "C" void func_0017E290(sDebugFEState17E290* self, int arg)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    self->state = 0x7;
    func_0025CD28(D_004A3028, arg);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E2F8);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E2F8 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
extern "C" void func_0025D800(void* a, int b, int c);

extern "C" void func_0017E2F8(sDebugFEState17E2F8* self, int arg)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    self->state = 0xB;
    func_0025D800(D_004A3028, arg, 0);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E368);
#ifdef SKIP_ASM
extern "C" void func_002CC460(void* list);

extern "C" void func_0017E368(void* self)
{
    int* list = (int*)((char*)self + 0x8);
    while (*list != 0) {
        func_002CC460(list);
    }
    *(int*)((char*)self + 0x4) = 0xD;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E3B8);
#ifdef SKIP_ASM
extern "C" void func_002CC460(void* list);
extern "C" void func_002CC3B8(void* list, void* item);

extern "C" void func_0017E3B8(void* self)
{
    int* list = (int*)((char*)self + 0x8);
    while (*list != 0) {
        func_002CC460(list);
    }
    *(int*)((char*)self + 0x4) = 0xE;
    func_002CC3B8((char*)self + 0x8, (char*)self + 0x1534);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E418);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E418 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
extern "C" void func_002CC3B8(void* list, void* item);
extern "C" void func_0025AAE0(void* a, int b);

extern "C" void func_0017E418(sDebugFEState17E418* self, int arg)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    func_002CC3B8((char*)self + 0x8, (char*)self + 0x1044);
    self->state = 0xC;
    func_0025AAE0(D_004A3028, arg);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E490);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E490 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
extern "C" void func_0025FB58(void* a, int b, int c);

extern "C" void func_0017E490(sDebugFEState17E490* self)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    self->state = 0xD;
    func_0025FB58(D_004A3028, *(int*)((char*)self + 0x1C0C), 0);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E4F0);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E4F0 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
extern "C" void func_002CC3B8(void* list, void* item);
void func_0025FC28(void* a, int b);

extern "C" void func_0017E4F0(sDebugFEState17E4F0* self)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    func_002CC3B8((char*)self + 0x8, (char*)self + 0x1044);
    self->state = 0xC;
    func_0025FC28(D_004A3028, *(int*)((char*)self + 0x1C0C));
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017E558);
#ifdef SKIP_ASM
extern void* D_004A3028;
struct sDebugFEState17E558 {
    int f0;
    int state; // 0x4
    int list;  // 0x8
};
extern "C" void func_002CC460(void* list);
extern "C" void func_002CC3B8(void* list, void* item);
extern "C" void func_0025F628(void* a, int b, int c);

extern "C" void func_0017E558(sDebugFEState17E558* self)
{
    int* list = &self->list;
    while (*list != 0) {
        func_002CC460(list);
    }
    func_002CC3B8((char*)self + 0x8, (char*)self + 0x1044);
    self->state = 0xC;
    func_0025F628(D_004A3028, 1, 0);
}
#endif

INCLUDE_ASM("fe/debugfe", func_0017E5C8);

//100%
INCLUDE_ASM("fe/debugfe", func_0017F2D0);
#ifdef SKIP_ASM
extern "C" float func_0031BF60(float x);

struct sVec2_17F2D0 {
    float x, y;
    sVec2_17F2D0() {}
    sVec2_17F2D0(float ax, float ay) : x(ax), y(ay) {}
    sVec2_17F2D0& operator+=(const sVec2_17F2D0& o)
    {
        x += o.x;
        y += o.y;
        return *this;
    }
    sVec2_17F2D0& operator+=(float s)
    {
        x += s;
        y += s;
        return *this;
    }
    sVec2_17F2D0& operator*=(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }
};

struct sFirefly_17F2D0 {
    sVec2_17F2D0 pos;        // 0x0
    sVec2_17F2D0 phase;      // 0x8
    sVec2_17F2D0 trail[64];  // 0x10
    int head;                // 0x210
};

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_17F2D0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline float wrap_17F2D0(float x)
{
    return x - ffloor_17F2D0(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

extern "C" void func_0017F2D0(void* p)
{
    sFirefly_17F2D0* self = (sFirefly_17F2D0*)p;
    for (int i = 0; i < 2; i++) {
        sVec2_17F2D0 v(func_0031BF60(self->phase.x), func_0031BF60(self->phase.y));
        v += 1.899999976158142f;
        v *= 0.03200000151991844f;
        {
            sVec2_17F2D0 d;
            d.x = 0.004999999888241291f;
            d.y = 0.008999999612569809f;
            self->phase.x += d.x;
            self->phase.y += d.y;
        }
        self->pos += v;
        self->phase.x = wrap_17F2D0(self->phase.x);
        self->phase.y = wrap_17F2D0(self->phase.y);
        self->pos.x = wrap_17F2D0(self->pos.x);
        self->pos.y = wrap_17F2D0(self->pos.y);
        self->head = (self->head + 1) % 64;
        sVec2_17F2D0 pt(func_0031BF60(self->pos.x) * 20.0f + 550.0f,
                        func_0031BF60(self->pos.y) * 20.0f + 420.0f);
        self->trail[self->head] = pt;
    }
}
#endif

INCLUDE_ASM("fe/debugfe", func_0017F500);

//100%
INCLUDE_ASM("fe/debugfe", func_0017F7B8);
#ifdef SKIP_ASM
extern "C" void func_00231CD0(void* self);
extern "C" void func_003E6448(void* dst, int c, int n);
extern char D_0046D900[];

struct sDbgEntry17F7B8 {
    int a;
    int b;
    sDbgEntry17F7B8() {}
};

inline void* operator new[](unsigned int, void* p) { return p; }

struct sDbgList17F7B8 {
    int a;                      // 0x00
    int b;                      // 0x04
    int c;                      // 0x08
    int d;                      // 0x0C
    sDbgEntry17F7B8 e[64];      // 0x10
    int n;                      // 0x210
};

extern "C" void* func_0017F7B8(void* self)
{
    func_00231CD0(self);
    *(void**)self = D_0046D900;
    *(int*)((char*)self + 0x24) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x30) = 0;
    sDbgList17F7B8* l = (sDbgList17F7B8*)((char*)self + 0x24);
    new (l->e) sDbgEntry17F7B8[64];
    l->n = 0;
    func_003E6448(l->e, 0, 0x200);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017F838);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0046D970[];

extern "C" void func_0017F838(void* self, int flags)
{
    *(void**)self = D_0046D970;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017F868);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern char* D_004A289C;
extern char* D_004A5B80;
extern char D_0045D4B8[];
extern char D_0045D4C8[];
extern char D_0045D4E0[];
extern char D_0045D4F8[];
extern char D_0045D510[];
extern char D_0045D520[];
extern char D_004A1340[];
extern char D_004A1348[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* cMemMan_free(void* ptr);
extern "C" void* func_003915E8(void* self, const char* name, int a2);
extern "C" int* func_003E1908(const char* name, int flags);
extern "C" int* FILE_load(const char* name, int flags);
extern "C" void* func_0017B1B0(void* self);
extern "C" void* func_0017D298(char* self);

struct sVEnt_17F868 { short delta; short index; void* fn; };
typedef void (*Fn1_17F868)(void*, int);
typedef int (*Load_17F868)(void*, void*, const char*, int, int, int);

struct sVec2_17F868 {
    float x, y;
    sVec2_17F868(float ax, float ay) : x(ax), y(ay) {}
};

struct sDebugFE_17F868 {
    char pad_0x00[0xC];
    void* objs[2];      // 0xC
    void* cur;          // 0x14
    char* font;         // 0x18
    int snd1C;          // 0x1C
    int snd20;          // 0x20
};

extern "C" void func_0017F868(sDebugFE_17F868* self)
{
    char* m = D_004A289C;
    sVEnt_17F868* vt = *(sVEnt_17F868**)(m + 0x10D8);
    ((Fn1_17F868)vt[44].fn)(m + vt[44].delta, 0);
    self->font = (char*)func_003915E8(cMemMan_alloc(0x84, D_0045D4B8, 0, 0), D_0045D4C8, 0);
    sVec2_17F868 sc(1.600000023841858f, 1.600000023841858f);
    *(sVec2_17F868*)(self->font + 0x30) = sc;
    *(sVec2_17F868*)(self->font + 0x38) = *(sVec2_17F868*)(self->font + 0x30);
    self->snd1C = -1;
    int* data = func_003E1908(D_0045D4E0, 0x100);
    if (data) {
        char* p = (char*)data + data[5];
        if (p) {
            char* g = D_004A5B80;
            sVEnt_17F868* gvt = *(sVEnt_17F868**)(g + 0x10D8);
            self->snd1C = ((Load_17F868)gvt[46].fn)(g + gvt[46].delta, p, D_004A1340, 0, 1, -1);
        }
        cMemMan_free(data);
    }
    data = FILE_load(D_0045D4F8, 0x100);
    char* m2 = D_004A289C;
    sVEnt_17F868* vt2 = *(sVEnt_17F868**)(m2 + 0x10D8);
    self->snd20 = ((Load_17F868)vt2[46].fn)(m2 + vt2[46].delta, (char*)data + data[5], D_004A1348, 0, 1, -1);
    if (data) {
        cMemMan_free(data);
    }
    for (int i = 0; i < 2; i++) {
        self->objs[i] = 0;
    }
    self->cur = self->objs[0] = func_0017B1B0(cMemMan_alloc(0x8C48, D_0045D510, 0, 0));
    self->objs[1] = func_0017D298((char*)cMemMan_alloc(0x1C18, D_0045D520, 0, 0));
    if (*(int*)((char*)D_004A28A8 + 0x74)) {
        self->cur = self->objs[1];
    } else {
        self->cur = self->objs[0];
    }
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FA60);
#ifdef SKIP_ASM
extern "C" void func_00369FF8(void* world);
extern volatile int D_004A4324;
extern void* D_004A289C_17FA60 __asm__("D_004A289C");
extern void* volatile D_004A289C_v17FA60 __asm__("D_004A289C");

struct sVec3_17FA60 {
    int x, y, z;
    sVec3_17FA60(int a, int b, int c) { x = a; y = b; z = c; }
};

class cWorld_17FA60 {
public:
    char pad[0x10D8];
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void setCamera(const sVec3_17FA60& v);
};

// Resets the world camera to the origin.
extern "C" void func_0017FA60(void)
{
    func_00369FF8(D_004A289C_17FA60);
    // release-build assert leftover: the empty do/while(0) keeps the world pointer reload after the call
    do { } while (0);
    D_004A4324 = 0;
    ((cWorld_17FA60*)D_004A289C_v17FA60)->setCamera(sVec3_17FA60(0, 0, 0));
}
#endif

extern "C" void* func_00231CF0(void* self);

//100%
INCLUDE_ASM("fe/debugfe", func_0017FAB0__FPv);
#ifdef SKIP_ASM
int func_0017FAB0(void* self)
{
    return (func_00231CF0(self) != 0);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FAD0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern char* D_004A289C;
extern "C" void func_003916C0(void* p, int flags);

struct sVEi_0017FAD0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sDebugFE_0017FAD0 {
    char pad_0x00[0xC];
    char* objs[2];      // 0xC
    char pad_0x14[4];
    void* font;         // 0x18
    int snd1C;          // 0x1C
    int snd20;          // 0x20
};

extern "C" void func_0017FAD0(sDebugFE_0017FAD0* self)
{
    for (int i = 0; i < 2; i++)
    {
        char* o = self->objs[i];
        if (o != 0)
        {
            sVEi_0017FAD0* vt = *(sVEi_0017FAD0**)o;
            vt[1].fn(o + vt[1].delta, 3);
        }
    }
    char* g = (char*)D_004A28A8;
    *(int*)(g + 0x7C) = 0;
    *(int*)(g + 0x80) = 0;
    if (self->snd20 >= 0)
    {
        char* m = D_004A289C;
        sVEi_0017FAD0* vt = *(sVEi_0017FAD0**)(m + 0x10D8);
        vt[50].fn(m + vt[50].delta, self->snd20);
    }
    if (self->snd1C >= 0)
    {
        char* m = D_004A289C;
        sVEi_0017FAD0* vt = *(sVEi_0017FAD0**)(m + 0x10D8);
        vt[50].fn(m + vt[50].delta, self->snd1C);
    }
    if (self->font != 0)
        func_003916C0(self->font, 3);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/debugfe", func_0017FB98);
#ifdef SKIP_ASM
extern void* D_004A28A8;
class cFEObjK17FB98 {
public:
    virtual void v01();
    virtual void v02();
};
extern "C" void func_00231D18(void* self);
extern "C" void func_0017F2D0(void* p);

extern "C" void func_0017FB98(void* self)
{
    func_00231D18(self);
    if (*(int*)((char*)D_004A28A8 + 4) == 0)
        (*(cFEObjK17FB98**)((char*)self + 0x14))->v02();
    func_0017F2D0((char*)self + 0x24);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/debugfe", func_0017FBF0);
#ifdef SKIP_ASM
extern char* D_004A289C;
extern char D_004FF1A0[];
extern "C" int func_00231D60(void* self);
extern "C" void func_0017F500(void* self, int a1);

struct sVEnt_17FBF0 { short delta; short index; void* fn; };
typedef int (*FnI_17FBF0)(void*);
typedef void (*FnV_17FBF0)(void*);
typedef void (*FnP_17FBF0)(void*, void*);
typedef void (*FnView_17FBF0)(void*, int, int, float, float, float, float, float, float);

struct sVec4_17FBF0 {
    float x, y, z, w;
    sVec4_17FBF0() {}
    sVec4_17FBF0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

struct sRS_17FBF0 {
    int f0;
    unsigned int lo : 2;
    unsigned int b2 : 5;
    unsigned int b7 : 5;
    unsigned int b12 : 8;
    unsigned int b20 : 2;
    unsigned int b22 : 1;
    unsigned int b23 : 2;
    unsigned int hi : 7;
    unsigned int c0 : 5;
    unsigned int c5 : 5;
    unsigned int chi : 22;
};

static inline sRS_17FBF0* rs_17FBF0(char* m) { return *(sRS_17FBF0**)(m + 0xE84); }
static inline void setB23_17FBF0(sRS_17FBF0* r, int v) { r->b23 = v; }
static inline void setB20_17FBF0(sRS_17FBF0* r, int v) { r->b20 = v; }
static inline void setB12_17FBF0(sRS_17FBF0* r, int v) { r->b12 = v; }
static inline void setB2_17FBF0(sRS_17FBF0* r, int v) { r->b2 = v; }
static inline void setB22_17FBF0(sRS_17FBF0* r, int v) { r->b22 = v; }
static inline void setC5_17FBF0(sRS_17FBF0* r, int v) { r->c5 = v; }

extern "C" int func_0017FBF0(char* self)
{
    char* m = D_004A289C;
    sVEnt_17FBF0* vt = *(sVEnt_17FBF0**)(m + 0x10D8);
    if (!((FnI_17FBF0)vt[17].fn)(m + vt[17].delta)) {
        return 0;
    }
    if (func_00231D60(self) == 0) {
        char* m1 = D_004A289C;
        sVEnt_17FBF0* vt1 = *(sVEnt_17FBF0**)(m1 + 0x10D8);
        char* this1 = m1 + vt1[15].delta;
        sVec4_17FBF0 pos;
        float one = 1.0f;
        sVec4_17FBF0 col(one, 0.0f, 0.0f, 0.0f);
        float zero = 0.0f;
        pos.x = zero;
        pos.y = zero;
        pos.z = zero;
        ((FnP_17FBF0)vt1[15].fn)(this1, &pos);
        char* m2 = D_004A289C;
        sVEnt_17FBF0* vt2 = *(sVEnt_17FBF0**)(m2 + 0x10D8);
        ((FnView_17FBF0)vt2[26].fn)(m2 + vt2[26].delta, 0, 0, zero, zero, 640.0f, 480.0f, -1.0f, one);
        char* m3 = D_004A289C;
        sVEnt_17FBF0* vt3 = *(sVEnt_17FBF0**)(m3 + 0x10D8);
        ((FnP_17FBF0)vt3[34].fn)(m3 + vt3[34].delta, D_004FF1A0);
        char* m4 = D_004A289C;
        setB23_17FBF0(rs_17FBF0(m4), 2);
        setB20_17FBF0(rs_17FBF0(m4), 3);
        setB12_17FBF0(rs_17FBF0(m4), 0xD);
        setB2_17FBF0(rs_17FBF0(m4), 5);
        setB22_17FBF0(rs_17FBF0(m4), 1);
        func_0017F500(self + 0x24, *(int*)(self + 0x1C));
        setC5_17FBF0(rs_17FBF0(D_004A289C), 9);
        void* menu = *(void**)(self + 0x14);
        sVEnt_17FBF0* mvt = *(sVEnt_17FBF0**)menu;
        ((FnV_17FBF0)mvt[3].fn)((char*)menu + mvt[3].delta);
    }
    char* m5 = D_004A289C;
    sVEnt_17FBF0* vt5 = *(sVEnt_17FBF0**)(m5 + 0x10D8);
    ((FnV_17FBF0)vt5[20].fn)(m5 + vt5[20].delta);
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FDF0);
#ifdef SKIP_ASM
void* func_00320C48(int, int) __asm__("func_00320C48__FPvi");

extern "C" void func_0017FDF0(void* self, signed char k)
{
    int id = 0;
    switch (k) {
    case 0: id = 0x72; break;
    case 1: id = 0x73; break;
    case 2: id = 0x74; break;
    case 3: id = 0x75; break;
    case 4: id = 0x76; break;
    case 5: id = 0x77; break;
    case 6: id = 0x78; break;
    case 7: id = 0x79; break;
    }
    func_00320C48(*(int*)((char*)self + 0x18), id);
}
#endif

// PORT: the real function is C++ void* func_00320C48(void* self, int) (bx/execman); these thunks pass an int handle.
void* func_00320C48(int, int) __asm__("func_00320C48__FPvi");

//100%
INCLUDE_ASM("fe/debugfe", func_0017FE80__FPv);
#ifdef SKIP_ASM
void* func_0017FE80(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x70);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FEA0__FPv);
#ifdef SKIP_ASM
void* func_0017FEA0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x71);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FEC0__FPv);
#ifdef SKIP_ASM
void* func_0017FEC0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x7a);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FEE0__FPv);
#ifdef SKIP_ASM
void* func_0017FEE0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x7b);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FF00__FPv);
#ifdef SKIP_ASM
void* func_0017FF00(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x7c);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FF20__FPv);
#ifdef SKIP_ASM
void* func_0017FF20(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x7d);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FF40__FPv);
#ifdef SKIP_ASM
void* func_0017FF40(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x97);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FF60__FPv);
#ifdef SKIP_ASM
void* func_0017FF60(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x98);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FF80__FPv);
#ifdef SKIP_ASM
void* func_0017FF80(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x99);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FFA0__FPv);
#ifdef SKIP_ASM
void* func_0017FFA0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x9a);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FFC0__FPv);
#ifdef SKIP_ASM
void* func_0017FFC0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x9b);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_0017FFE0__FPv);
#ifdef SKIP_ASM
void* func_0017FFE0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x9c);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180000__FPv);
#ifdef SKIP_ASM
void* func_00180000(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x9d);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180020__FPv);
#ifdef SKIP_ASM
void* func_00180020(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x9e);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180040__FPv);
#ifdef SKIP_ASM
void* func_00180040(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x72);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180060__FPv);
#ifdef SKIP_ASM
void* func_00180060(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x73);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180080__FPv);
#ifdef SKIP_ASM
void* func_00180080(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x74);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001800A0__FPv);
#ifdef SKIP_ASM
void* func_001800A0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x75);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001800C0__FPv);
#ifdef SKIP_ASM
void* func_001800C0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x93);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001800E0__FPv);
#ifdef SKIP_ASM
void* func_001800E0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x94);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180100__FPv);
#ifdef SKIP_ASM
void* func_00180100(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x95);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180120__FPv);
#ifdef SKIP_ASM
void* func_00180120(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x96);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180140__FPv);
#ifdef SKIP_ASM
void* func_00180140(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x7e);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180160__FPv);
#ifdef SKIP_ASM
void* func_00180160(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x7f);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180180__FPv);
#ifdef SKIP_ASM
void* func_00180180(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x80);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001801A0__FPv);
#ifdef SKIP_ASM
void* func_001801A0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x81);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001801C0__FPv);
#ifdef SKIP_ASM
void* func_001801C0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x82);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001801E0__FPv);
#ifdef SKIP_ASM
void* func_001801E0(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x83);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180200__FPv);
#ifdef SKIP_ASM
void* func_00180200(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x84);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180220__FPv);
#ifdef SKIP_ASM
void* func_00180220(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x85);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180240__FPv);
#ifdef SKIP_ASM
void* func_00180240(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x90);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180260__FPv);
#ifdef SKIP_ASM
void* func_00180260(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x92);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180280__FPv);
#ifdef SKIP_ASM
void* func_00180280(void* self)
{
    return func_00320C48(*(int*)((char*)self + 0x18), 0x91);
}
#endif

extern "C" void* func_00320BF0(int, int);

//100%
INCLUDE_ASM("fe/debugfe", func_001802A0__FPv);
#ifdef SKIP_ASM
void* func_001802A0(void* self)
{
    return func_00320BF0(*(int*)((char*)self + 0x18), 0x90);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001802C0__FPv);
#ifdef SKIP_ASM
void* func_001802C0(void* self)
{
    return func_00320BF0(*(int*)((char*)self + 0x18), 0x92);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001802E0__FPv);
#ifdef SKIP_ASM
void* func_001802E0(void* self)
{
    return func_00320BF0(*(int*)((char*)self + 0x18), 0x91);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180300);
#ifdef SKIP_ASM
extern "C" int func_00180300(void* self)
{
    int r = 0;
    if (func_00320C48(*(int*)((char*)self + 0x18), 0x72) || func_00320C48(*(int*)((char*)self + 0x18), 0x73) ||
        func_00320C48(*(int*)((char*)self + 0x18), 0x74) || func_00320C48(*(int*)((char*)self + 0x18), 0x75) ||
        func_00320C48(*(int*)((char*)self + 0x18), 0x76) || func_00320C48(*(int*)((char*)self + 0x18), 0x77) ||
        func_00320C48(*(int*)((char*)self + 0x18), 0x78) || func_00320C48(*(int*)((char*)self + 0x18), 0x79) ||
        func_00320C48(*(int*)((char*)self + 0x18), 0x7A) || func_00320C48(*(int*)((char*)self + 0x18), 0x7B) ||
        func_00320C48(*(int*)((char*)self + 0x18), 0x7D) || func_00320C48(*(int*)((char*)self + 0x18), 0x7C) ||
        func_00320C48(*(int*)((char*)self + 0x18), 0x90) || func_00320C48(*(int*)((char*)self + 0x18), 0x92) ||
        func_00320C48(*(int*)((char*)self + 0x18), 0x91) || func_00320C48(*(int*)((char*)self + 0x18), 0x71))
        r = 1;
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180478);
#ifdef SKIP_ASM
extern void* D_004A28A8;

extern "C" void func_00180478(void* self, unsigned char idx)
{
    int v = *(int*)((char*)D_004A28A8 + (idx << 2) + 0xB0);
    *(unsigned char*)((char*)self + 0x4) = idx;
    *(int*)((char*)self + 0x18) = v;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180498);
#ifdef SKIP_ASM
extern "C" int func_00180498(void* self)
{
    void* p = *(void**)((char*)self + 0x18);
    if (p != 0) {
        return **(int**)p != 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001804B8);
#ifdef SKIP_ASM
extern void* D_004A33F0;
extern "C" int func_00266BA8(void* mgr, int a1, int* out0, int* out1);

struct sDebugFE1804B8 {
    char pad_0x00[0xC];
    int found; // 0xC
    int a;     // 0x10
    int b;     // 0x14
};

extern "C" void func_001804B8(sDebugFE1804B8* self)
{
    self->found = 0;
    if (D_004A33F0 != 0) {
        self->b = 0;
        self->a = 0;
        if (func_00266BA8(D_004A33F0, 0, &self->a, &self->b) != 0)
            self->found = 1;
    }
}
#endif

INCLUDE_ASM("fe/debugfe", func_00180508);

//100%
INCLUDE_ASM("fe/debugfe", func_001805D8);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);

extern "C" void func_001805D8(void* self, const char* text)
{
    char* buf = (char*)self + 0xEC;
    strcpy(buf, text);
    *(int*)((char*)self + 0x16C) = strlen(buf);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180618);
#ifdef SKIP_ASM
extern "C" void func_00180618(void* self)
{
    int s = *(int*)((char*)self + 0x170);
    if (s == 0 || s == 10 || s == 20 || s == 30) {
        *(int*)((char*)self + 0x170) += 9;
    } else if (s == 39 && *(int*)((char*)self + 0xE0) == 0) {
        *(int*)((char*)self + 0x170) = 37;
    } else {
        *(int*)((char*)self + 0x170) -= 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180678);
#ifdef SKIP_ASM
extern "C" void func_00180678(void* self)
{
    int s = *(int*)((char*)self + 0x170);
    if (s == 9 || s == 19 || s == 29 || s == 39) {
        *(int*)((char*)self + 0x170) -= 9;
    } else if (s == 37 && *(int*)((char*)self + 0xE0) == 0) {
        *(int*)((char*)self + 0x170) = 39;
    } else {
        *(int*)((char*)self + 0x170) += 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001806D8);
#ifdef SKIP_ASM
extern "C" void func_001806D8(void* self)
{
    int s = *(int*)((char*)self + 0x170);
    if (s >= 0 && s < 10) {
        if (s == 8 && *(int*)((char*)self + 0xE0) == 0) {
            *(int*)((char*)self + 0x170) = 39;
        } else {
            *(int*)((char*)self + 0x170) += 30;
        }
    } else if (s >= 10 && s < 20 && *(int*)((char*)self + 0xD8) == 0) {
        if (s == 18 && *(int*)((char*)self + 0xE0) == 0) {
            *(int*)((char*)self + 0x170) = 39;
        } else {
            *(int*)((char*)self + 0x170) += 20;
        }
    } else {
        *(int*)((char*)self + 0x170) -= 10;
    }
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180768);
#ifdef SKIP_ASM
extern "C" void func_00180768(void* self)
{
    int s = *(int*)((char*)self + 0x170);
    if (s >= 30 && s < 40) {
        if (*(int*)((char*)self + 0xD8) != 0) {
            *(int*)((char*)self + 0x170) = s - 30;
        } else {
            *(int*)((char*)self + 0x170) = s - 20;
        }
    } else if (s == 28 && *(int*)((char*)self + 0xE0) == 0) {
        *(int*)((char*)self + 0x170) = 39;
    } else {
        *(int*)((char*)self + 0x170) += 10;
    }
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001807C8);
#ifdef SKIP_ASM
extern "C" int func_001807C8(void* self)
{
    int v = *(int*)((char*)self + 0xe4) ^ 1;
    *(int*)((char*)self + 0xe4) = v;
    return v;
}
#endif

INCLUDE_ASM("fe/debugfe", func_001807D8);

//100%
INCLUDE_ASM("fe/debugfe", func_00180840);
#ifdef SKIP_ASM
struct cDbgKbdTarget {
    int f0;
    int f4;
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
    virtual void v19(int, int);
};

struct sDbgKbd {
    char pad0[0xD0];
    cDbgKbdTarget* obj;
    int maxLen;
    char padD8[0xC];
    int caps;
    char padE8[4];
    char buf[0x80];
    int cur;
    int key;
};

extern "C" void func_00180840(sDbgKbd* self)
{
    int k = self->key;
    if (k >= 0 && k < 10) {
        self->buf[self->cur] = self->key + '0';
        if (self->cur + 1 < self->maxLen)
            self->cur = self->cur + 1;
    } else if (k >= 10 && k < 36) {
        int c = !self->caps ? 'a' : 'A';
        self->buf[self->cur] = c + (self->key - 10);
        if (self->cur + 1 < self->maxLen)
            self->cur = self->cur + 1;
        self->buf[self->cur] = 0;
    } else if (k == 36) {
        if (self->cur > 0)
            self->cur = self->cur - 1;
        self->buf[self->cur] = 0;
    } else if (k == 37) {
        if (self->cur + 1 < self->maxLen)
            self->cur = self->cur + 1;
        self->buf[self->cur] = 0;
    } else if (k == 38) {
        self->buf[self->cur] = ' ';
        if (self->cur + 1 < self->maxLen)
            self->cur = self->cur + 1;
    }
    if (self->key == 39)
        self->obj->v19(0, 13);
    else
        self->obj->v19(0, 12);
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_001809B0);
#ifdef SKIP_ASM
struct sStr10 { char c[10]; };
extern sStr10 D_0045D550;
extern char D_004A1350[];
extern char D_0045D560[];
extern char D_004A1358[];
extern char D_004A1360[];
extern "C" char* func_004162D0(char*, const char*);

extern "C" void func_001809B0(void* self, int c, char* dst)
{
    char buf[2];
    *(sStr10*)dst = D_0045D550;
    if (c < 10) {
        buf[0] = c + '0';
        buf[1] = 0;
        func_004162D0(dst, buf);
    } else if (c < 36) {
        buf[0] = c + 'A' - 10;
        buf[1] = 0;
        func_004162D0(dst, buf);
    } else if (c == 36) {
        func_004162D0(dst, D_004A1350);
    } else if (c == 37) {
        func_004162D0(dst, D_0045D560);
    } else if (c == 38) {
        func_004162D0(dst, D_004A1358);
    } else if (c == 39) {
        func_004162D0(dst, D_004A1360);
    }
}
#endif

//100%
INCLUDE_ASM("fe/debugfe", func_00180A90);
#ifdef SKIP_ASM
struct sStr8 { char c[8]; };
extern char D_004A1368[];
extern char D_004A1350[];
extern char D_0045D560[];
extern char D_004A1358[];
extern char D_004A1360[];
extern "C" char* func_004162D0(char*, const char*);

extern "C" void func_00180A90(void* self, int c, char* dst)
{
    char buf[2];
    *(sStr8*)dst = *(sStr8*)D_004A1368;
    if (c < 10) {
        buf[0] = c + '0';
        buf[1] = 0;
        func_004162D0(dst, buf);
    } else if (c < 36) {
        buf[0] = c + 'A' - 10;
        buf[1] = 0;
        func_004162D0(dst, buf);
    } else if (c == 36) {
        func_004162D0(dst, D_004A1350);
    } else if (c == 37) {
        func_004162D0(dst, D_0045D560);
    } else if (c == 38) {
        func_004162D0(dst, D_004A1358);
    } else if (c == 39) {
        func_004162D0(dst, D_004A1360);
    }
}
#endif

