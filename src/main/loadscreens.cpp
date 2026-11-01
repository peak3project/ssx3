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

INCLUDE_ASM("main/loadscreens", func_0017B4E0);

