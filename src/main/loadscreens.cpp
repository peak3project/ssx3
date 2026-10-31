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

INCLUDE_ASM("main/loadscreens", func_0017B1B0);

INCLUDE_ASM("main/loadscreens", func_0017B4E0);

