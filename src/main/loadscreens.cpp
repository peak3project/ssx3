#include "common.h"

//100%
INCLUDE_ASM("main/loadscreens", cBackgroundMan_loadImages);
#ifdef SKIP_ASM
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* ptr);
extern "C" void* func_003E1908(const char* name, int flags);
extern "C" void* SHAPE_unpack(void* shape);
extern char D_0045CE30[];
extern char D_004A12A0[];
extern char D_004A12A8[];

struct sRVEntry_17ACC8 {
    short delta;
    short index;
    int (*fn)(void*, void*, const char*, int, int, int);
};

struct sRCtx_17ACC8 {
    char pad[0x10D8];
    sRVEntry_17ACC8* vt;
};
extern sRCtx_17ACC8* D_004A289C;

struct sBgFile_17ACC8 {
    int f0;
    int f4;
    int count;
    int fC;
    int f10;
    struct {
        int offset;
        int f4;
    } shapes[1];
};

struct sBgMan_17ACC8 {
    int* images;
    int count;
};

extern "C" int cBackgroundMan_loadImages(sBgMan_17ACC8* self)
{
    sBgFile_17ACC8* file = (sBgFile_17ACC8*)func_003E1908(D_0045CE30, 0x100);
    if (file == 0) {
        return 0;
    }
    int n = file->count;
    self->count = n;
    self->images = (int*)operator_new__FUi(n * 4, D_004A12A0, 0, 0);
    for (int i = 0; i < self->count; i++) {
        char* shape = (char*)file + file->shapes[i].offset;
        void* img = SHAPE_unpack(shape);
        self->images[i] = D_004A289C->vt[46].fn((char*)D_004A289C + D_004A289C->vt[46].delta, img, D_004A12A8, 0, 1, -1);
        if (img != shape && img != 0) {
            cMemMan_free(img);
        }
    }
    if (file != 0) {
        cMemMan_free(file);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens", func_0017AE00);
#ifdef SKIP_ASM
extern char D_004FF1A0[];

struct sRS_AE00 {
    int f0;                     // 0x00
    unsigned int pad4a : 2;     // 0x04
    unsigned int mode : 5;
    unsigned int pad4b : 5;
    unsigned int func : 8;
    unsigned int test : 2;
    unsigned int pad4c : 1;
    unsigned int blend : 2;
    unsigned int pad4d : 7;
    unsigned int pad8a : 5;     // 0x08
    unsigned int alpha : 5;
    unsigned int pad8b : 22;
    int fC;                     // 0x0C
    short tex;                  // 0x10
    short pad12;
};

struct sVEnt_AE00 {
    short delta;
    short index;
    void (*fn)(void*, int, void*, int);
};

struct sCtx_AE00 {
    char pad[0xE84];
    sRS_AE00* top;              // 0xE84
    char pad_E88[0x10D8 - 0xE88];
    sVEnt_AE00* vt;             // 0x10D8
};

struct sPos_AE00 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVert_AE00 {
    float u, v, q, f0C;         // 0x00
    int r, g, b, a;             // 0x10
    sPos_AE00 pos;              // 0x20
    sVert_AE00() {}
};


struct sBgMan_AE00 {
    int* images;                // 0x0
    int count;                  // 0x4
    int cur;                    // 0x8
};

typedef void (*fnV_AE00)(void*);
typedef void (*fnRect_AE00)(void*, int, int, float, float, float, float, float, float);
typedef void (*fnP_AE00)(void*, void*);

static inline sCtx_AE00* ctx_AE00() { return (sCtx_AE00*)D_004A289C; }

static inline void call0_AE00(int slot)
{
    sCtx_AE00* g = ctx_AE00();
    sVEnt_AE00* e = &g->vt[slot];
    ((fnV_AE00)e->fn)((char*)g + e->delta);
}

static inline void setAlpha_AE00(sRS_AE00* rs, int v) { rs->alpha = v; }
static inline void setBlend_AE00(sRS_AE00* rs, int v) { rs->blend = v; }
static inline void setTest_AE00(sRS_AE00* rs, int v) { rs->test = v; }
static inline void setFunc_AE00(sRS_AE00* rs, int v) { rs->func = v; }
static inline void setMode_AE00(sRS_AE00* rs, int v) { rs->mode = v; }
static inline int imageOf_AE00(sBgMan_AE00* m) { return m->images[m->cur]; }

static inline void setState_AE00()
{
    setAlpha_AE00(ctx_AE00()->top, 9);
    setBlend_AE00(ctx_AE00()->top, 1);
    setTest_AE00(ctx_AE00()->top, 3);
    setFunc_AE00(ctx_AE00()->top, 0xD);
    setMode_AE00(ctx_AE00()->top, 5);
}

extern "C" void func_0017AE00(sBgMan_AE00* self)
{
    if (self->cur < 0 || self->cur >= self->count) {
        return;
    }
    call0_AE00(21);
    call0_AE00(31);
    sCtx_AE00* g = ctx_AE00();
    g->top[1] = g->top[0];
    g->top++;
    setState_AE00();
    {
        sCtx_AE00* c = ctx_AE00();
        sVEnt_AE00* e = &c->vt[26];
        ((fnRect_AE00)e->fn)((char*)c + e->delta, 0, 0, 0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    }
    {
        sCtx_AE00* c = ctx_AE00();
        sVEnt_AE00* e = &c->vt[34];
        ((fnP_AE00)e->fn)((char*)c + e->delta, D_004FF1A0);
    }
    setState_AE00();
    sVert_AE00 v[4];
    for (int i = 0; i < 4; i++) {
        v[i].a = 0x80;
        v[i].r = 0x80;
        v[i].g = 0x80;
        v[i].b = 0x80;
        v[i].q = 1.0f;
    }
    sPos_AE00 p;
    p.x = 0.0f;
    p.y = 0.0f;
    p.z = 0.0f;
    p.w = 1.0f;
    v[0].pos = p;
    p.x = 640.0f;
    p.y = 0.0f;
    p.z = 0.0f;
    p.w = 1.0f;
    v[1].pos = p;
    p.x = 0.0f;
    p.y = 480.0f;
    p.z = 0.0f;
    p.w = 1.0f;
    v[2].pos = p;
    p.x = 640.0f;
    p.y = 480.0f;
    p.z = 0.0f;
    p.w = 1.0f;
    v[3].pos = p;
    v[0].u = 0.0f;
    v[0].v = 0.0f;
    v[1].u = 1.0f;
    v[1].v = 0.0f;
    v[2].u = 0.0f;
    v[2].v = 1.0f;
    v[3].u = 1.0f;
    v[3].v = 1.0f;
    setAlpha_AE00(ctx_AE00()->top, 0x18);
    *(short*)((char*)ctx_AE00()->top + 0x10) = imageOf_AE00(self);
    {
        sCtx_AE00* c = ctx_AE00();
        sVEnt_AE00* e = &c->vt[71];
        e->fn((char*)c + e->delta, 4, v, 0);
    }
    ctx_AE00()->top--;
    call0_AE00(32);
    call0_AE00(22);
}
#endif

//100%
INCLUDE_ASM("main/loadscreens", func_0017B1B0);
#ifdef SKIP_ASM
extern char D_0046D798[];
extern char D_004A12B0[];
extern int D_004A29EC;
extern int D_004A2EB8;
extern int D_004A11B8;
extern float D_0049D5D0;
void* cBE_getInterface_B1B0(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void* func_0017ABC8(void*) __asm__("func_0017ABC8__FPv");
extern "C" void func_0017A638(void*);
extern "C" void cBENewRaceInterface_setNumberHumans(void* self, int n) __asm__("cBENewRaceInterface_setNumberHumans__FPvi");
extern "C" void func_00145108(void* iface, int mode);
extern "C" void cBENewRaceInterface_setGameMode(void* self, int mode);
extern "C" void cBENewRaceInterface_setGameEvent(void* self, int ev);
extern "C" void func_00266CD8();
extern "C" void func_00261008();
extern "C" void func_0025B688();
extern "C" void func_00255898();
extern "C" void cCommSystem_construct();
extern "C" void func_00255F20_ls(int a, const char* b) __asm__("func_00255F20");
extern "C" void func_0025B650();
extern "C" void func_00260F80();
extern "C" void func_00266CA0();
extern "C" void func_0017D008(void* self, int idx);
extern "C" int func_0017A028_ls(void* self, int i) __asm__("func_0017A028");
extern "C" void func_00144B20(void* self, const char* name);
extern "C" void func_001472C8(void* self, int a1, int a2);
extern "C" void func_00147448(void* self, int a1, int a2);
extern "C" int func_00147618(void* self, int a1);
extern "C" void* func_0028B180();
extern "C" void func_00289520(void* snd, void* entry);

struct sApp_B1B0 {
    char pad[0x78];
    void* be;
};
extern sApp_B1B0* D_004A28A8;

struct sNet_B1B0 {
    int f0;
    int f4;
    int f8;
    int fC;
    float f10;
};
extern sNet_B1B0 D_00534B30;

struct sG_B1B0 {
    char pad[0x40];
    int f40;
};
extern sG_B1B0 D_00535BC8;

struct sVE_B1B0 {
    short delta;
    short index;
    void (*fn)(void*);
};

// Load-screen entry table (see func_0017A028: `count` at 0, entries' `active` flag).
struct sLSEntry_B1B0 {
    char name[0x80];
    int kind;                    // 0x80
    int f84;
    int active;                  // 0x88
};                               // 0x8C

struct sLSSub_B1B0 {
    int count;
    sLSEntry_B1B0 e[256];        // 0x4
    int f8C04;
    int f8C08;
};                               // 0x8C0C

static inline int lsSubLoaded_B1B0(sLSSub_B1B0* s)
{
    return s->f8C08;
}

static inline char* lsEntryName_B1B0(sLSSub_B1B0* s, int i)
{
    return s->e[i].name;
}

struct sLS_B1B0 {
    void* vt;                    // 0x0
    sLSSub_B1B0 sub;             // 0x4
    char bg[8];                  // 0x8C10
    int pad8C18;
    int f8C1C;
    int f8C20;
    int f8C24;
    int f8C28;
    int f8C2C;
    int f8C30;
    int f8C34;
    int arr[3];                  // 0x8C38
    int f8C44;
};

// Load-screen constructor: sets up the race/player interfaces, picks the active entry and the sound entry.
extern "C" sLS_B1B0* func_0017B1B0(sLS_B1B0* self)
{
    self->vt = D_0046D798;
    func_0017ABC8(self->bg);
    func_0017A638(&self->sub);
    cBackgroundMan_loadImages((sBgMan_17ACC8*)self->bg);
    void* iface0 = cBE_getInterface_B1B0(cBE_getBE(), 0);
    void* iface7 = cBE_getInterface_B1B0(D_004A28A8->be, 7);
    self->f8C24 = 0;
    *(int*)cBE_getBE() = self->f8C24;
    self->f8C24 = 0;
    cBENewRaceInterface_setNumberHumans(iface0, 1);
    for (int i = 0; i < 3; i++) {
        self->arr[i] = 4;
    }
    func_00145108(iface0, 0);
    cBENewRaceInterface_setGameMode(iface0, 4);
    cBENewRaceInterface_setGameEvent(iface0, 0xC);
    self->f8C20 = 0;
    D_00534B30.f0 = 0;
    if (D_004A29EC != 0) {
        func_00266CD8();
        func_00261008();
        func_0025B688();
        func_00255898();
        cCommSystem_construct();
        func_00255F20_ls(D_004A2EB8, D_004A12B0);
        func_0025B650();
        func_00260F80();
        func_00266CA0();
    }
    if (lsSubLoaded_B1B0(&self->sub) != 0) {
        if (self->sub.e[self->f8C20].active == 0) {
            self->f8C20 = func_0017A028_ls(&self->sub, self->f8C20);
        }
    } else {
        func_0017D008(self, 1);
    }
    int idx = self->f8C20;
    int kind = self->sub.e[idx].kind;
    D_004A11B8 = 1;
    D_00535BC8.f40 = kind;
    if (self->sub.e[self->f8C20].f84 == 0) {
        D_004A11B8 = 0;
    }
    if (kind == 0x16) {
        func_00144B20(iface0, lsEntryName_B1B0(&self->sub, self->f8C20));
    }
    self->f8C1C = 4;
    D_00534B30.f10 = 0.016666668f;
    D_00534B30.fC = 0xE4A;
    D_00534B30.f8 = 0;
    sVE_B1B0* vt7 = *(sVE_B1B0**)((char*)iface7 + 0xC);
    vt7[1].fn((char*)iface7 + vt7[1].delta);
    self->f8C44 = 0;
    self->f8C34 = 0;
    self->f8C30 = -1;
    void* iface1 = cBE_getInterface_B1B0(cBE_getBE(), 1);
    func_001472C8(iface1, 0, 0);
    func_001472C8(iface1, 1, 1);
    self->f8C28 = 2;
    func_00147448(iface1, 0, 2);
    self->f8C2C = func_00147618(iface1, 0);
    void* snd = func_0028B180();
    func_00289520(snd, (char*)func_0028B180() + (self->f8C34 * 0x14 + 0x60A4));
    sVE_B1B0* vt1 = *(sVE_B1B0**)((char*)iface1 + 0xC);
    vt1[1].fn((char*)iface1 + vt1[1].delta);
    sVE_B1B0* vt0 = *(sVE_B1B0**)((char*)iface0 + 0xC);
    vt0[1].fn((char*)iface0 + vt0[1].delta);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/loadscreens", func_0017B4E0);
#ifdef SKIP_ASM
struct cAppMan;
int func_00320C48(void* pad, int button);
extern "C" float func_00320BF0(void* pad, int axis);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* func_00232738(void* self);
void* func_00232720(void* self);
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
extern "C" void func_0017D0A8(sLS_B1B0* self);
extern "C" int func_0017D1B8(sLS_B1B0* self, int quick, int mode, int event);
extern "C" int func_0017A0B8(sLSSub_B1B0* s, int i);
extern "C" int func_0017A158(sLSSub_B1B0* s, int i, int mode);
extern "C" int func_0017A220(sLSSub_B1B0* s, int i, int mode);
extern "C" int func_0017A2C8(sLSSub_B1B0* s, int i, int mode);
extern "C" int func_0017A028_b4(sLSSub_B1B0* s, int i) __asm__("func_0017A028");
extern "C" int cBENewRaceInterface_setGameMode_b4(void* self, int mode) __asm__("cBENewRaceInterface_setGameMode");
extern "C" int cBENewRaceInterface_setGameEvent_b4(void* self, int ev) __asm__("cBENewRaceInterface_setGameEvent");
extern "C" int cBENewRaceInterface_setNumberAI(void* self, int count);
extern "C" int func_00145C38(void* self, int a1);
extern "C" void func_00145CB0(void* self, int a1, int a2);
extern "C" void func_00145DD0(void* self, int a1, int a2, int a3);
extern "C" void func_00147658(void* self, int a1, int a2);
extern "C" void func_0017AC98(void* bg, int idx);
extern "C" void func_00256088();
extern "C" void func_002560B0();
extern "C" void func_00255FA0(void* comm);
extern "C" void func_00255F50(void* comm, int a1);
extern "C" void func_00255A20(void* comm);
extern "C" int SYNCTASK_run(int);
extern "C" void THREAD_yieldticks(int);
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern char D_0045CE48[];
extern char D_0045CE60[];
extern signed char D_00535C11[];
extern int D_004A2EBC;

struct sComm_B4E0 {
    char pad[0x20];
    int state;                   // 0x20
};
extern sComm_B4E0* D_004A2EB8_b4 __asm__("D_004A2EB8");

struct sTime_B4E0 {
    char pad[0x10];
    int f10;
    int f14;
};

struct sApp_B4E0 {
    char pad[0x60];
    int f60;                     // 0x60
    char pad64[0x78 - 0x64];
    int* be;                     // 0x78
    char pad7C[0x4];
    sTime_B4E0* f80;             // 0x80
    char pad84[0xB0 - 0x84];
    void* input;                 // 0xB0
};
extern sApp_B4E0* D_004A28A8_b4 __asm__("D_004A28A8");

struct sRace_B4E0 {
    char pad[0x3C];
    int numAI;                   // 0x3C
    int kind;                    // 0x40
    char pad44[0x4];
    signed char mode;            // 0x48
    signed char quick;           // 0x49
    signed char event;           // 0x4A
};
extern sRace_B4E0 D_00535BC8_b4 __asm__("D_00535BC8");

struct sVE_B4E0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sGfxVE_B4E0 {
    short delta;
    short index;
    void* fn;
};

struct sGfx_B4E0 {
    char pad[0x10D8];
    sGfxVE_B4E0* vt;
};
extern sGfx_B4E0* D_004A289C_b4 __asm__("D_004A289C");

static inline void update_B4E0(void* iface)
{
    sVE_B4E0* vt = *(sVE_B4E0**)((char*)iface + 0xC);
    vt[1].fn((char*)iface + vt[1].delta);
}

static inline bool commIdle_B4E0(sComm_B4E0* c)
{
    return c->state == 1;
}

static inline bool commBusy_B4E0(sComm_B4E0* c)
{
    return c->state == 3 || c->state == 4;
}

static inline bool netOn_B4E0(int mode)
{
    return mode != 0 && mode < 3;
}

static inline int numSongs_B4E0()
{
    return *(int*)((char*)func_0028B180() + 0x6234);
}

static inline void playSong_B4E0(sLS_B1B0* self)
{
    void* snd = func_0028B180();
    func_00289520(snd, (char*)func_0028B180() + (self->f8C34 * 0x14 + 0x60A4));
}

static inline int bgCount_B4E0(sBgMan_17ACC8* bg)
{
    return bg->count;
}

extern "C" void func_0017B4E0(sLS_B1B0* self)
{
    if (func_00320C48(D_004A28A8_b4->input, 0x65)) {
        func_0017D0A8(self);
        if (self->f8C1C == 14) {
            D_004A28A8_b4->f60 = 1;
            cAppMan_setNextModule((cAppMan*)D_004A28A8_b4, (unsigned int)func_00232738(cMemMan_alloc(8, D_0045CE48, 0x100, 0)));
        } else {
            cAppMan_setNextModule((cAppMan*)D_004A28A8_b4, (unsigned int)func_00232720(cMemMan_alloc(8, D_0045CE60, 0x100, 0)));
        }
    }
    int dir = (int)func_00320BF0(D_004A28A8_b4->input, 0x3D);
    if (dir == 0 && self->f8C30 == -1) {
        self->f8C1C = (self->f8C1C + 15 - 1) % 15;
        if (self->f8C1C == 13) {
            if (D_004A2EB8_b4 == 0) {
                self->f8C1C = (self->f8C1C + 15 - 2) % 15;
            } else if (D_004A2EBC <= 0) {
                self->f8C1C = (self->f8C1C + 15 - 1) % 15;
            }
        }
        return;
    }
    if (dir == 1 && self->f8C30 == -1) {
        self->f8C1C = (self->f8C1C + 1) % 15;
        if (self->f8C1C == 12 && D_004A2EB8_b4 == 0) {
            self->f8C1C = (self->f8C1C + 15 + 2) % 15;
        }
        if (self->f8C1C == 13) {
            if (D_004A2EB8_b4 == 0 || D_004A2EBC <= 0) {
                self->f8C1C = (self->f8C1C + 15 + 1) % 15;
            }
        }
        return;
    }
    switch (self->f8C1C) {
    case 0: {
        void* race = cBE_getInterface_B1B0(D_004A28A8_b4->be, 0);
        sRace_B4E0* r = &D_00535BC8_b4;
        int quick = r->quick;
        if (dir == 3) {
            quick = (quick + 1) % 3;
            if (quick == 0) {
                if (lsSubLoaded_B1B0(&self->sub) != 0) {
                    if (self->sub.e[self->f8C20].active == 0) {
                        self->f8C20 = func_0017A028_b4(&self->sub, self->f8C20);
                    }
                    int kind = self->sub.e[self->f8C20].kind;
                    D_004A11B8 = 1;
                    r->kind = kind;
                } else {
                    quick = (quick + 1) % 3;
                }
            }
            func_0017D008(self, quick);
        } else if (dir == 2) {
            quick = (quick + 2) % 3;
            if (quick == 0) {
                if (lsSubLoaded_B1B0(&self->sub) != 0) {
                    if (self->sub.e[self->f8C20].active == 0) {
                        self->f8C20 = func_0017A028_b4(&self->sub, self->f8C20);
                    }
                    int kind = self->sub.e[self->f8C20].kind;
                    D_004A11B8 = 1;
                    r->kind = kind;
                } else {
                    quick = (quick + 2) % 3;
                }
            }
            func_0017D008(self, quick);
        }
        int changed = 0;
        int mode = D_00535BC8_b4.mode;
        do {
            while (!cBENewRaceInterface_setGameMode_b4(race, mode)) {
                mode = (mode + 1) % 7;
            }
            if (!func_0017A158(&self->sub, self->f8C20, mode)) {
                changed = 1;
                self->f8C20 = func_0017A220(&self->sub, self->f8C20, mode);
            }
        } while (self->f8C20 < 0);
        if (changed) {
            int kind = self->sub.e[self->f8C20].kind;
            D_004A11B8 = 1;
            D_00535BC8_b4.kind = kind;
            if (self->sub.e[self->f8C20].f84 == 0) {
                D_004A11B8 = 0;
            }
            if (kind == 0x16) {
                func_00144B20(race, lsEntryName_B1B0(&self->sub, self->f8C20));
            }
        }
        update_B4E0(race);
        int ev = D_00535BC8_b4.event;
        if (!cBENewRaceInterface_setGameEvent_b4(race, ev)) {
            ev = (ev + 1) % 14;
            while (!cBENewRaceInterface_setGameEvent_b4(race, ev)) {
                ev = (ev + 1) % 14;
            }
            update_B4E0(race);
        }
        int numAI = D_00535BC8_b4.numAI;
        int maxAI = func_0017D1B8(self, D_00535BC8_b4.quick, D_00535BC8_b4.mode, D_00535BC8_b4.event);
        if (maxAI < numAI) {
            cBENewRaceInterface_setNumberAI(race, maxAI);
            update_B4E0(race);
        }
        break;
    }
    case 1: {
        void* race = cBE_getInterface_B1B0(D_004A28A8_b4->be, 0);
        sRace_B4E0* r = &D_00535BC8_b4;
        if (r->quick == 0) {
            cBENewRaceInterface_setGameMode_b4(race, 4);
            cBENewRaceInterface_setNumberAI(race, 0);
            update_B4E0(race);
            break;
        }
        int mode = r->mode;
        if (dir != 2 && dir != 3) {
            return;
        }
        int changed = 0;
        do {
            do {
                if (dir == 3) {
                    mode = (mode + 1) % 7;
                } else if (dir == 2) {
                    mode = (mode + 6) % 7;
                }
            } while (!cBENewRaceInterface_setGameMode_b4(race, mode));
            if (!func_0017A158(&self->sub, self->f8C20, mode)) {
                changed = 1;
                self->f8C20 = func_0017A220(&self->sub, self->f8C20, mode);
            }
        } while (self->f8C20 < 0);
        if (changed) {
            int kind = self->sub.e[self->f8C20].kind;
            D_004A11B8 = 1;
            D_00535BC8_b4.kind = kind;
            if (self->sub.e[self->f8C20].f84 == 0) {
                D_004A11B8 = 0;
            }
            if (kind == 0x16) {
                func_00144B20(race, lsEntryName_B1B0(&self->sub, self->f8C20));
            }
        }
        update_B4E0(race);
        int ev = D_00535BC8_b4.event;
        if (!cBENewRaceInterface_setGameEvent_b4(race, ev)) {
            ev = (ev + 1) % 14;
            while (!cBENewRaceInterface_setGameEvent_b4(race, ev)) {
                ev = (ev + 1) % 14;
            }
            update_B4E0(race);
        }
        int numAI = D_00535BC8_b4.numAI;
        int maxAI = func_0017D1B8(self, D_00535BC8_b4.quick, D_00535BC8_b4.mode, D_00535BC8_b4.event);
        if (maxAI < numAI) {
            cBENewRaceInterface_setNumberAI(race, maxAI);
            update_B4E0(race);
        }
        break;
    }
    case 2: {
        void* race = cBE_getInterface_B1B0(D_004A28A8_b4->be, 0);
        sRace_B4E0* r = &D_00535BC8_b4;
        int ev = r->event;
        if (r->quick == 0) {
            cBENewRaceInterface_setGameMode_b4(race, 4);
            cBENewRaceInterface_setNumberAI(race, 0);
        } else if (dir == 2 || dir == 3) {
            do {
                if (dir == 3) {
                    ev = (ev + 1) % 14;
                } else if (dir == 2) {
                    ev = (ev + 13) % 14;
                }
            } while (!cBENewRaceInterface_setGameEvent_b4(race, ev));
        }
        update_B4E0(race);
        int numAI = D_00535BC8_b4.numAI;
        int maxAI = func_0017D1B8(self, D_00535BC8_b4.quick, D_00535BC8_b4.mode, D_00535BC8_b4.event);
        if (maxAI < numAI) {
            cBENewRaceInterface_setNumberAI(race, maxAI);
            update_B4E0(race);
        }
        break;
    }
    case 3: {
        cBE_getInterface_B1B0(D_004A28A8_b4->be, 0);
        void* player = cBE_getInterface_B1B0(D_004A28A8_b4->be, 1);
        int v = func_00145C38(player, 0);
        if (D_00535C11[0] != 0) {
            break;
        }
        if (dir != 2 && dir != 3) {
            return;
        }
        if (dir == 3) {
            v = 1;
        } else if (dir == 2) {
            v = 0;
        }
        func_00145CB0(player, 0, v);
        func_00145DD0(player, v, 0, 14);
        update_B4E0(player);
        break;
    }
    case 4: {
        void* race = cBE_getInterface_B1B0(D_004A28A8_b4->be, 0);
        if (dir != 2 && dir != 3) {
            return;
        }
        sRace_B4E0* r = &D_00535BC8_b4;
        if (r->quick == 0) {
            if (dir == 3) {
                self->f8C20 = func_0017A028_b4(&self->sub, self->f8C20);
            } else if (dir == 2) {
                self->f8C20 = func_0017A0B8(&self->sub, self->f8C20);
            }
        } else {
            int mode = r->mode;
            do {
                if (dir == 3) {
                    self->f8C20 = func_0017A220(&self->sub, self->f8C20, D_00535BC8_b4.mode);
                } else {
                    self->f8C20 = func_0017A2C8(&self->sub, self->f8C20, D_00535BC8_b4.mode);
                }
                if (self->f8C20 < 0) {
                    do {
                        mode = (mode + 1) % 7;
                    } while (!cBENewRaceInterface_setGameMode_b4(race, mode));
                }
            } while (self->f8C20 < 0);
            update_B4E0(race);
        }
        sLSSub_B1B0* sub = &self->sub;
        int kind = sub->e[self->f8C20].kind;
        D_004A11B8 = 1;
        D_00535BC8_b4.kind = kind;
        if (sub->e[self->f8C20].f84 == 0) {
            D_004A11B8 = 0;
        }
        if (kind == 0x16) {
            func_00144B20(race, lsEntryName_B1B0(sub, self->f8C20));
        }
        update_B4E0(race);
        break;
    }
    case 7:
        // Wraps over a range of one value: both arms fold to 0 (the binary keeps both compares and one store).
        if (dir == 3) {
            self->f8C24 = (self->f8C24 + 1) % 1;
        } else if (dir == 2) {
            self->f8C24 = (self->f8C24 + 1 - 1) % 1;
        }
        *D_004A28A8_b4->be = self->f8C24;
        break;
    case 5: {
        void* player = cBE_getInterface_B1B0(cBE_getBE(), 1);
        if (dir == 3) {
            self->f8C28 = (self->f8C28 + 1) % 10;
        } else if (dir == 2) {
            self->f8C28 = (self->f8C28 + 9) % 10;
        }
        func_00147448(player, 0, self->f8C28);
        update_B4E0(player);
        break;
    }
    case 6: {
        if (dir == 2 || dir == 3) {
            self->f8C2C = !self->f8C2C;
        }
        void* player = cBE_getInterface_B1B0(cBE_getBE(), 1);
        func_00147658(player, 0, self->f8C2C);
        update_B4E0(player);
        break;
    }
    case 8: {
        void* race = cBE_getInterface_B1B0(D_004A28A8_b4->be, 0);
        int numAI = D_00535BC8_b4.numAI;
        int maxAI = func_0017D1B8(self, D_00535BC8_b4.quick, D_00535BC8_b4.mode, D_00535BC8_b4.event);
        if (maxAI < numAI) {
            numAI = maxAI;
        }
        for (;;) {
            if (dir == 3) {
                numAI = (D_00535BC8_b4.numAI + 1) % (maxAI + 1);
            } else if (dir == 2) {
                numAI = (D_00535BC8_b4.numAI + maxAI) % (maxAI + 1);
            }
            if (cBENewRaceInterface_setNumberAI(race, numAI)) {
                break;
            }
            if (dir != 2 && dir != 3) {
                break;
            }
        }
        update_B4E0(race);
        break;
    }
    case 9:
        if (dir == 3) {
            self->f8C30 = (self->f8C30 + 2) % (bgCount_B4E0((sBgMan_17ACC8*)self->bg) + 1) - 1;
        } else if (dir == 2) {
            self->f8C30 = (self->f8C30 + bgCount_B4E0((sBgMan_17ACC8*)self->bg) + 1) % (bgCount_B4E0((sBgMan_17ACC8*)self->bg) + 1) - 1;
        }
        func_0017AC98(self->bg, self->f8C30);
        break;
    case 10: {
        if (dir != 2 && dir != 3) {
            return;
        }
        sGfx_B4E0* g = D_004A289C_b4;
        sGfxVE_B4E0* vt = g->vt;
        ((void (*)(void*, int))vt[8].fn)((char*)g + vt[8].delta, !((bool (*)(void*))vt[9].fn)((char*)g + vt[9].delta));
        break;
    }
    case 11:
        if (dir == 3) {
            self->f8C34 = (self->f8C34 + 1) % numSongs_B4E0();
            playSong_B4E0(self);
        } else if (dir == 2) {
            self->f8C34 = (self->f8C34 + numSongs_B4E0() - 1) % numSongs_B4E0();
            playSong_B4E0(self);
        }
        break;
    case 12: {
        if (dir == 6) {
            if (self->f8C44 == 3) {
                func_00256088();
            }
            if (self->f8C44 == 4) {
                func_002560B0();
            }
        }
        if (D_004A2EB8_b4 == 0) {
            return;
        }
        if (dir == 3) {
            self->f8C44++;
            if (D_004A2EBC <= 0 && (self->f8C44 == 1 || self->f8C44 == 2)) {
                self->f8C44 = 3;
            }
        } else if (dir == 2) {
            self->f8C44--;
            if (D_004A2EBC <= 0 && (self->f8C44 == 1 || self->f8C44 == 2)) {
                self->f8C44 = 0;
            }
        }
        if (self->f8C44 > 4) {
            self->f8C44 = 0;
        }
        if (self->f8C44 < 0) {
            self->f8C44 = 4;
        }
        void* net = cBE_getInterface_B1B0(D_004A28A8_b4->be, 7);
        D_00534B30.f0 = netOn_B4E0(self->f8C44);
        D_00534B30.f8 = self->f8C44 == 1;
        update_B4E0(net);
        if (self->f8C44 != 0) {
            if (self->f8C44 != 3) {
                if (commIdle_B4E0(D_004A2EB8_b4)) {
                    func_00255F50(D_004A2EB8_b4, 0);
                    while (commBusy_B4E0(D_004A2EB8_b4)) {
                        func_00255A20(D_004A2EB8_b4);
                        SYNCTASK_run(0);
                        THREAD_yieldticks(1);
                    }
                }
            }
        } else {
            if (!commIdle_B4E0(D_004A2EB8_b4)) {
                func_00255FA0(D_004A2EB8_b4);
            }
        }
        break;
    }
    case 13:
        if (D_004A2EB8_b4 == 0) {
            return;
        }
        if (D_004A2EBC <= 0) {
            return;
        }
        if (dir == 6) {
            D_004A28A8_b4->f80->f14 = D_004A28A8_b4->f80->f10;
        }
        break;
    case 14:
        break;
    }
    if (dir == 2 || dir == 3) {
        void* player = cBE_getInterface_B1B0(cBE_getBE(), 1);
        self->f8C24 = *D_004A28A8_b4->be;
        self->f8C28 = cBENewPlayerInterface_getPlayerCharID(player, 0);
    }
}
#endif

