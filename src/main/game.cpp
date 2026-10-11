#include "common.h"

// 16-byte array elements; indexing as arr[i].field (rather than manual
// pointer arithmetic) is what makes GCC emit the target's base-first addu
struct sGameEntry {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
};
extern sGameEntry D_00442168[];

//100%
INCLUDE_ASM("main/game", cGame_renderModels);
#ifdef SKIP_ASM
struct sRState_C078 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
};

struct sRVEntry_C078 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int, int);
};

struct sRCtx_C078 {
    char pad0[0x24];
    int cur;
    char pad28[0xE84 - 0x28];
    sRState_C078* top;
    char padE88[0xF50 - 0xE88];
    int tbl[(0x10D8 - 0xF50) / 4];
    sRVEntry_C078* vt;
};

extern sRCtx_C078* D_004A289C;

static inline int curLayer_C078(sRCtx_C078* c)
{
    return c->tbl[c->cur];
}

extern "C" void cGame_renderModels(void* self, void* world)
{
    *(short*)((char*)D_004A289C->top + 0x12) = curLayer_C078(D_004A289C);
    sRCtx_C078* ctx = D_004A289C;
    ctx->top->f4 = (ctx->top->f4 & ~0xF80) | 0x880;
    ctx->top->f0 |= 0x30;
    int flag = 0xC00;
    if (*(unsigned int*)(*(char**)((char*)self + 0x84) + 0x10) >= 2) {
        flag = 0x400;
    }
    int n = *(int*)((char*)world + 0x209C);
    int* items = (int*)((char*)world + 0x20A0);
    for (int i = 0; i < n; i++) {
        D_004A289C->vt[0x60].fn((char*)D_004A289C + D_004A289C->vt[0x60].delta, items[i], 0, 0, flag);
    }
    int n2 = *(int*)((char*)world + 0x40A0);
    items = (int*)((char*)world + 0x40A4);
    for (int i = 0; i < n2; i++) {
        D_004A289C->vt[0x60].fn((char*)D_004A289C + D_004A289C->vt[0x60].delta, items[i], 0, 0, flag | 0x20);
    }
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022C1B0);
#ifdef SKIP_ASM
extern void* D_004A4248;

struct sVec_C1B0 {
    float x, y, z, w;
    sVec_C1B0() {}
    sVec_C1B0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sMat_C1B0 {
    float m[4][4];
};

struct sVEm_C1B0 { short delta; short index; sMat_C1B0* (*fn)(void*); };
struct sVEf_C1B0 { short delta; short index; float (*fn)(void*); };
struct sVEv_C1B0 { short delta; short index; void (*fn)(void*); };

struct sRCtx_C1B0 {
    char pad0[0x10D8];
    sVEm_C1B0* vt;      // 0x10D8
};
extern sRCtx_C1B0* D_004A289C_C1B0 __asm__("D_004A289C");

struct sCamObj_C1B0 {
    char pad0[4];
    sVEf_C1B0* vt;      // 0x4
};

struct sRenderCam_C1B0 {
    sCamObj_C1B0* cam;  // 0x0
    char pad4[0xC];
    sVec_C1B0 pos;      // 0x10
    float k;            // 0x20
    float c;            // 0x24
    float n;            // 0x28
    float f;            // 0x2C
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec_C1B0 Scale_C1B0(const sVec_C1B0& v, float s)
{
    sVec_C1B0 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline sVec_C1B0 MulVec_C1B0(const sMat_C1B0* m, const sVec_C1B0& v)
{
    return sVec_C1B0(v.x * m->m[0][0] + v.y * m->m[0][1] + v.z * m->m[0][2] + v.w * m->m[0][3],
                     v.x * m->m[1][0] + v.y * m->m[1][1] + v.z * m->m[1][2] + v.w * m->m[1][3],
                     v.x * m->m[2][0] + v.y * m->m[2][1] + v.z * m->m[2][2] + v.w * m->m[2][3],
                     v.x * m->m[3][0] + v.y * m->m[3][1] + v.z * m->m[3][2] + v.w * m->m[3][3]);
}

static inline sMat_C1B0* viewMat_C1B0()
{
    sRCtx_C1B0* c = D_004A289C_C1B0;
    return c->vt[35].fn((char*)c + c->vt[35].delta);
}

// PORT: the unit declares func_0022C1B0 as void(void*); the body returns self, bound by asm label.
sRenderCam_C1B0* func_0022C1B0_impl(sRenderCam_C1B0* self) __asm__("func_0022C1B0");

sRenderCam_C1B0* func_0022C1B0_impl(sRenderCam_C1B0* self)
{
    self->cam = (sCamObj_C1B0*)D_004A4248;
    self->pos = Scale_C1B0(sVec_C1B0(*(sVec_C1B0*)viewMat_C1B0()->m[3]), -1.0f);
    sMat_C1B0* m = viewMat_C1B0();
    self->pos = sVec_C1B0(self->pos.x * m->m[0][0] + self->pos.y * m->m[0][1] + self->pos.z * m->m[0][2] + self->pos.w * m->m[0][3],
                          self->pos.x * m->m[1][0] + self->pos.y * m->m[1][1] + self->pos.z * m->m[1][2] + self->pos.w * m->m[1][3],
                          self->pos.x * m->m[2][0] + self->pos.y * m->m[2][1] + self->pos.z * m->m[2][2] + self->pos.w * m->m[2][3],
                          self->pos.x * m->m[3][0] + self->pos.y * m->m[3][1] + self->pos.z * m->m[3][2] + self->pos.w * m->m[3][3]);
    self->n = 1.0f;
    self->f = 3.0f;
    self->pos.w = 1.0f;
    sCamObj_C1B0* o = self->cam;
    float a = o->vt[8].fn((char*)o + o->vt[8].delta);
    o = self->cam;
    float b = o->vt[9].fn((char*)o + o->vt[9].delta);
    a = a * a * 2.0f;
    b = b * b * 2.0f;
    self->k = (self->n - self->f) / (b - a);
    self->c = self->f - self->k * a;
    o = self->cam;
    ((sVEv_C1B0*)o->vt)[17].fn((char*)o + o->vt[17].delta);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022C3B8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
struct sVEntry_func_0022C3B8 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0022C3B8(void* self, int flags)
{
    void* obj = *(void**)self;
    sVEntry_func_0022C3B8* vt = *(sVEntry_func_0022C3B8**)((char*)obj + 0x4);
    vt[18].fn((char*)obj + vt[18].delta);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("main/game", func_0022C410);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/game", cGame_renderPatches);
#ifdef SKIP_ASM
extern "C" void func_0022C1B0(void* ctx);
extern "C" void func_0022C410(void* ctx, int patch, int flag);
extern "C" void func_0022C3B8(void* self, int flags);
extern void* D_004A4248;

struct sVEntry0022C620 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void cGame_renderPatches(void* self, void* world)
{
    char ctx[0x30];
    func_0022C1B0(ctx);
    int n = *(int*)((char*)world + 0x50A8);
    int* items = (int*)((char*)world + 0x50AC);
    for (int i = 0; i < n; i++) {
        func_0022C410(ctx, items[i], 0);
    }
    n = *(int*)((char*)world + 0x70AC);
    items = (int*)((char*)world + 0x70B0);
    for (int i = 0; i < n; i++) {
        func_0022C410(ctx, items[i], 1);
    }
    if (*(int*)(*(char**)((char*)self + 0x84) + 0x14) == 0) {
        void* obj = D_004A4248;
        sVEntry0022C620* vt = *(sVEntry0022C620**)((char*)obj + 4);
        vt[5].fn((char*)obj + vt[5].delta);
    }
    func_0022C3B8(ctx, 2);
}
#endif

//100%
INCLUDE_ASM("main/game", cGame_renderFogVolumes);
#ifdef SKIP_ASM
struct sVEntry_renderFog {
    short delta;
    short index;
    void (*fn)(void*, void*, int, int);
};
extern "C" void func_002DBF98(void* r);

extern "C" void cGame_renderFogVolumes(void* self, void* world)
{
    void* fog = (char*)world + 0x78B8;
    int n = *(int*)((char*)world + 0x78B4);
    if (n != 0) {
        void* r = *(void**)((char*)self + 0x18);
        sVEntry_renderFog* vt = *(sVEntry_renderFog**)((char*)r + 0x4);
        vt[2].fn((char*)r + vt[2].delta, fog, n, 0);
    }
    fog = (char*)world + 0x7AC0;
    n = *(int*)((char*)world + 0x7ABC);
    if (n != 0) {
        void* r = *(void**)((char*)self + 0x18);
        sVEntry_renderFog* vt = *(sVEntry_renderFog**)((char*)r + 0x4);
        vt[2].fn((char*)r + vt[2].delta, fog, n, 2);
    }
    func_002DBF98(*(void**)((char*)self + 0x18));
}
#endif

//100%
INCLUDE_ASM("main/game", cGame_renderLightHalos);
#ifdef SKIP_ASM
void func_002E2F98(void* self, int a1);
extern "C" void func_002E2FF8(void* self, void* list, int n, int mode, int a4);
extern "C" void func_002E30D0(void* self, int a1);

extern "C" void cGame_renderLightHalos(void* self, void* world, int a2)
{
    *(int*)((char*)*(void**)((char*)self + 0x1C) + 0x6494) = 1;
    func_002E2F98(*(void**)((char*)self + 0x1C), a2);
    void* p = (char*)world + 0x7BC4;
    int n = *(int*)((char*)world + 0x7BC0);
    if (n != 0) {
        func_002E2FF8(*(void**)((char*)self + 0x1C), p, n, 0, a2);
    }
    p = (char*)world + 0x7FC8;
    n = *(int*)((char*)world + 0x7FC4);
    if (n != 0) {
        func_002E2FF8(*(void**)((char*)self + 0x1C), p, n, 2, a2);
    }
    func_002E30D0(*(void**)((char*)self + 0x1C), a2);
    *(int*)((char*)*(void**)((char*)self + 0x1C) + 0x6494) = 0;
}
#endif

INCLUDE_ASM("main/game", func_0022C830);

//100%
INCLUDE_ASM("main/game", func_0022CCE8);
#ifdef SKIP_ASM
extern "C" void func_0022CD40(void* self);

extern "C" void* func_0022CCE8(void* self, int a1)
{
    *(int*)((char*)self + 0x1B0) = a1;
    func_0022CD40(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022CD18);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_0022CD18(void* self, int flags)
{
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022CD40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
struct cWorldView;
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cWorldView_getNumSections(cWorldView* view);
extern "C" void* func_003A9820(cWorldView* self, unsigned int i);
extern "C" int func_004165A8(const void* a, const void* b);
extern "C" void* func_00144D38(void* iface, int i);
extern "C" void func_0022E228(void* self);

static inline cWorldView* gameWorldView_22CD40(void* self)
{
    return (cWorldView*)(*(char**)*(char**)(*(char**)((char*)self + 0x1B0) + 0x10) + 0x10);
}

extern "C" void func_0022CD40(void* self)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    int i;
    unsigned int j;

    for (int k = 0; k < 50; k++) {
        D_00442168[k].field_0x4 = -1;
        D_00442168[k].field_0x8 = 0;
    }
    D_00442168[49].field_0x4 = 0;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < (unsigned int)cWorldView_getNumSections(gameWorldView_22CD40(self)); j++) {
            void* name = func_00144D38(iface, i);
            if (func_004165A8(name, func_003A9820(gameWorldView_22CD40(self), j)) == 0) {
                D_00442168[i].field_0x4 = j;
            }
        }
    }
    *(int*)((char*)self + 0x1B8) = 0;
    *(int*)((char*)self + 0x1B4) = 0;
    *(int*)((char*)self + 0x1C0) = 0;
    *(int*)((char*)self + 0x1C8) = 0;
    *(int*)((char*)self + 0x1CC) = 0;
    *(int*)((char*)self + 0x1BC) = 0x16;
    *(int*)((char*)self + 0x1D0) = 1;
    func_0022E228(self);
    *(int*)((char*)self + 0x1AC) = -1;
    *(int*)((char*)self + 0x1A4) = 0;
    *(int*)((char*)self + 0x1A8) = 0;
    *(int*)((char*)self + 0x1C4) = 0;
}
#endif

INCLUDE_ASM("main/game", func_0022CEA8);

INCLUDE_ASM("main/game", func_0022D088);

//100%
INCLUDE_ASM("main/game", func_0022D278);
#ifdef SKIP_ASM
struct sGroup_D278 {
    int f0;
    int count;
    int a;
    int b;
    int ids[6];
};
extern sGroup_D278 D_00442488_D278[] __asm__("D_00442488");
extern "C" int func_0022E078(void* self, int id);

// PORT: the unit declares func_0022D278(void*) for its callers; the body reads a1, bound by asm label
int func_0022D278_impl(void* self, int idx) __asm__("func_0022D278");

int func_0022D278_impl(void* self, int idx)
{
    int ok = 1;
    for (int i = 0; i < D_00442488_D278[idx].count; i++) {
        if (func_0022E078(self, D_00442488_D278[idx].ids[i]) == 0) {
            ok = 0;
            break;
        }
    }
    int a = D_00442488_D278[idx].a;
    if (a >= 0 && D_00442168[a].field_0x4 >= 0) {
        if (func_0022E078(self, a) == 0) {
            ok = 0;
        }
    }
    int b = D_00442488_D278[idx].b;
    if (b >= 0 && D_00442168[b].field_0x4 >= 0) {
        if (func_0022E078(self, b) == 0) {
            ok = 0;
        }
    }
    return ok;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/game", func_0022D390);
#ifdef SKIP_ASM
extern "C" int func_0022D278(void* self);

extern "C" int func_0022D390(void* self)
{
    int r = 0;
    if (func_0022D278(self) != 0) {
        r = *(int*)((char*)self + 0x1C0) != 0;
    }
    return r;
}
#endif

INCLUDE_ASM("main/game", func_0022D3D8);

INCLUDE_ASM("main/game", func_0022D478);

INCLUDE_ASM("main/game", func_0022D598);

//100%
INCLUDE_ASM("main/game", func_0022D640);
#ifdef SKIP_ASM
extern "C" void func_0022D640(void* self, int a1)
{
    if (a1 != 0 && *(int*)((char*)self + 0x1B4) == 0) {
        *(int*)((char*)self + 0x1B4) = 1;
        *(int*)((char*)self + 0x1B8) = a1;
    }
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022D668);
#ifdef SKIP_ASM
extern "C" void func_0022D668(void* self, int flag)
{
    if (flag == 0) {
        return;
    }
    switch (*(int*)((char*)self + 0x1B4)) {
    case 0:
        *(int*)((char*)self + 0x1B8) = flag;
        *(int*)((char*)self + 0x1B4) = 3;
        break;
    case 1:
        *(int*)((char*)self + 0x1B4) = 3;
        break;
    case 2:
        *(int*)((char*)self + 0x1B4) = 4;
        break;
    case 3:
    case 4:
        break;
    }
}
#endif

INCLUDE_ASM("main/game", func_0022D6C8);

INCLUDE_ASM("main/game", func_0022D8D8);

//100%
INCLUDE_ASM("main/game", func_0022DE58);
#ifdef SKIP_ASM
extern "C" void func_0022D478(void* self, int v);

extern "C" void func_0022DE58(void* self, int v)
{
    if (*(int*)((char*)self + 0x1AC) != v) {
        *(int*)((char*)self + 0x1AC) = v;
        func_0022D478(self, v);
        *(int*)((char*)self + 0x1A8) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022DE98);
#ifdef SKIP_ASM
extern "C" void func_0022D598(void* self, int id);
void func_00353D98(void* self);
extern "C" void func_00353CF0(void* self, int id);

extern "C" void func_0022DE98(void* self)
{
    if (*(int*)((char*)self + 0x1A8) == 0) {
        return;
    }
    if (*(int*)((char*)self + 0x1A4) == 0) {
        return;
    }
    int i;
    for (i = 0x2C; i < 0x31; i++) {
        if (i != *(int*)((char*)self + 0x1AC)) {
            func_0022D598(self, i);
        }
    }
    int id = D_00442168[*(int*)((char*)self + 0x1AC)].field_0x4;
    void* o = *(void**)((char*)*(void**)((char*)self + 0x1B0) + 0x14);
    if (*(int*)((char*)o + 0x10) != id) {
        func_00353D98(o);
        func_00353CF0(*(void**)((char*)*(void**)((char*)self + 0x1B0) + 0x14), id);
    }
    *(int*)((char*)self + 0x1A4) = 0;
    *(int*)((char*)self + 0x1A8) = 0;
    *(int*)((char*)self + 0x1AC) = -1;
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022DF50);
#ifdef SKIP_ASM
class cBEIface22DF50 {
public:
    int pad[3];
    virtual void v01();
};
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00231250(void* gm, int state, int a, int b);
void func_00231278(void* gm, int state);
extern int D_00535C08[];
extern int D_004A11B8;

extern "C" void func_0022DF50(void* self)
{
    func_00231250(*(void**)((char*)self + 0x1B0), 0xB, 0, 1);
    cBEIface22DF50* iface = (cBEIface22DF50*)cBE_getInterface_Fv(cBE_getBE(), 0);
    D_00535C08[0] = *(int*)((char*)self + 0x1BC);
    D_004A11B8 = 1;
    iface->v01();
    func_00231278(*(void**)((char*)self + 0x1B0), 0xA);
}
#endif

extern "C" void* func_002312D8(int);

//100%
INCLUDE_ASM("main/game", func_0022DFD0__FPv);
#ifdef SKIP_ASM
void* func_0022DFD0(void* self)
{
    return func_002312D8(*(int*)((char*)self + 0x1b0));
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022DFF0);
#ifdef SKIP_ASM
class cRace22DFF0 {
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
extern "C" int* func_00144BC0(void* iface);
extern "C" void cSectionMan_setSky(void* self, int sky);
extern "C" void func_00231250(void* gm, int state, int a, int b);
extern void* D_004A28A8;

extern "C" void func_0022DFF0(void* self)
{
    cSectionMan_setSky(self, *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0)));
    if (*(int*)((char*)self + 0x1CC) != 0) {
        *(int*)((char*)self + 0x1CC) = 0;
        (*(cRace22DFF0**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC))->v05(3);
    }
    func_00231250(*(void**)((char*)self + 0x1B0), 0xA, 0, 0);
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022E078);
#ifdef SKIP_ASM
extern "C" int func_0022E078(void* self, int a1)
{
    int v = D_00442168[a1].field_0x8;
    return (unsigned int)(v - 1) < 2;
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022E098);
#ifdef SKIP_ASM
struct sGameEntry2 {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
    int field_0x24;
};
extern sGameEntry2 D_00442488[];

extern "C" int func_0022E098(void* self, int a1)
{
    return D_00442168[D_00442488[a1].field_0x10].field_0x4;
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022E0C8);
#ifdef SKIP_ASM
extern "C" int func_0022E0C8(void* self, int a1)
{
    return D_00442168[a1].field_0x4;
}
#endif

//100%
INCLUDE_ASM("main/game", func_0022E0E0);
#ifdef SKIP_ASM
extern "C" int func_0022E0E0(void* self, int a1)
{
    int i;
    for (i = 0; i < 50; i++) {
        if (a1 == D_00442168[i].field_0x4) {
            return i;
        }
    }
    return 50;
}
#endif

