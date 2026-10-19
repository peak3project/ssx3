#include "common.h"

// R5900 128-bit GPR quadword, for functions that copy a 16-byte block via a
// single lq/sq pair instead of word-by-word.
typedef int cQuad128 __attribute__((mode(TI)));

//100%
INCLUDE_ASM("camera/camera", cCamera_resetChaseControllerSwitches);
#ifdef SKIP_ASM
struct sCam162138;
extern "C" void func_00162138(sCam162138* self);
extern void* D_004A28A8;

extern "C" void cCamera_resetChaseControllerSwitches(void)
{
    void* cam = *(void**)((char*)D_004A28A8 + 0x84);
    int* chase = *(int**)((char*)cam + 0x84);
    if (chase != 0) {
        func_00162138(*(sCam162138**)(*(char**)((char*)chase + 4) + 0xA8));
        if (*chase >= 2) {
            func_00162138(*(sCam162138**)(*(char**)((char*)chase + 8) + 0xA8));
        }
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", cCamera_cCamera);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0015D698(void* self);
extern "C" void* func_00176D68(void* self);
extern "C" void* cManualCameraController_cManualCameraController(void* self, void* cam);
extern "C" void* func_001619A8(void* self, int idx, int a);
extern "C" void* cScriptCameraController_cScriptCameraController(void* self, int idx, void* cam);
extern void* D_0045B888[];
extern const char D_0045B748[];
extern const char D_0045B760[];
extern const char D_0045B778[];
// PORT: cQuad128 (the unit's 128-bit TImode typedef) is a 16-byte register copy.
extern cQuad128 D_004FF160;
extern cQuad128 D_004FF130;

extern "C" void* cCamera_cCamera(void* self, int idx)
{
    func_0015D698(self);
    *(void***)((char*)self + 0x90) = D_0045B888;
    func_00176D68((char*)self + 0xC0);
    *(void**)((char*)self + 0xA4) = cManualCameraController_cManualCameraController(cMemMan_alloc(0x20, D_0045B748, 0, 0), self);
    *(void**)((char*)self + 0xA8) = func_001619A8(cMemMan_alloc(0x44, D_0045B760, 0, 0), idx, (int)self);
    *(void**)((char*)self + 0xAC) = cScriptCameraController_cScriptCameraController(cMemMan_alloc(0x20, D_0045B778, 0, 0), idx, self);
    *(int*)((char*)self + 0xB0) = -1;
    *(int*)((char*)self + 0xB4) = 0;
    *(int*)((char*)self + 0x454) = 0;
    *(int*)((char*)self + 0x458) = 0;
    *(int*)((char*)self + 0x45C) = 0;
    *(int*)((char*)self + 0x450) = 0;
    *(int*)((char*)self + 0x460) = 0;
    *(cQuad128*)((char*)self + 0x470) = D_004FF160;
    *(cQuad128*)((char*)self + 0x490) = D_004FF130;
    *(int*)((char*)self + 0x4A4) = 1;
    *(int*)((char*)self + 0x4A0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015DD88);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0045B888[];
extern void* D_0045B8B0[];
void func_0015CD60(void* p);
void func_00176DA8_2(void* self, int flags) __asm__("func_00176DA8__FPv");

class cCamPartK2 {
public:
    char pad[0x14];
    // vptr at 0x14
    virtual ~cCamPartK2();
};

// PORT: func_00176DA8__FPv is a destructor taking (self, flags); bind the 2-arg form.
extern "C" void func_0015DD88(void* self, int flags)
{
    *(void***)((char*)self + 0x90) = D_0045B888;
    func_0015CD60(*(cCamPartK2**)((char*)self + 0xA4));
    func_0015CD60(*(cCamPartK2**)((char*)self + 0xA8));
    func_0015CD60(*(cCamPartK2**)((char*)self + 0xAC));
    delete *(cCamPartK2**)((char*)self + 0xA4);
    delete *(cCamPartK2**)((char*)self + 0xA8);
    delete *(cCamPartK2**)((char*)self + 0xAC);
    func_00176DA8_2((char*)self + 0xC0, 2);
    *(void***)((char*)self + 0x90) = D_0045B8B0;
    if (flags & 1)
    {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", cCamera_init);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is the game's tagged operator new(size, tag, flags, d); bound by asm label.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0015CF80(void* self, int msg);
extern "C" void func_00161A60(void* self, int* p);
struct sCam162060;
extern "C" void func_00162060(sCam162060* self, int mode, int arg, float blend);
void func_00162310(void* self, int val);
void* func_0015E030(void* self);
extern void* D_004A28A8;
extern const char D_0045B790[];
extern void* D_0045B7A8[];

struct sCamCtrl_15DE60
{
    char pad_0x00[0xC];
    int viewport;   // 0xC
};

struct sCamera_15DE60
{
    char pad_0x00[0xC];
    float f0C;      // 0xC
    float f10;      // 0x10
    float f14;      // 0x14
    int index;      // 0x18
    char pad_0x1C[0xA4 - 0x1C];
    sCamCtrl_15DE60* manual;   // 0xA4
    sCamCtrl_15DE60* chase;    // 0xA8
    sCamCtrl_15DE60* script;   // 0xAC
    int fB0;        // 0xB0
    int fB4;        // 0xB4
    char pad_0xB8[0x454 - 0xB8];
    int f454;       // 0x454
    int f458;       // 0x458
    int f45C;       // 0x45C
    int f460;       // 0x460
};

struct sCamWorld_15DE60
{
    char pad_0x00[0xC];
    char* riders;   // 0xC
};

struct sApp_15DE60
{
    char pad_0x00[0x84];
    sCamWorld_15DE60* world;   // 0x84
    char pad_0x88[0xB0 - 0x88];
    int viewports[4];          // 0xB0
};

struct sRiderRef_15DE60
{
    void** vt;
    int rider;
};

extern "C" void cCamera_init(sCamera_15DE60* self, int idx, float a, float b, float c)
{
    self->f0C = a;
    self->f10 = b;
    self->f14 = c;
    self->index = idx;
    self->f460 = 0;
    self->manual->viewport = ((sApp_15DE60*)D_004A28A8)->viewports[0];
    func_0015CF80(self->manual, 0x51);
    self->chase->viewport = ((sApp_15DE60*)D_004A28A8)->viewports[idx];
    sRiderRef_15DE60* p = (sRiderRef_15DE60*)operator new(8, D_0045B790, 0, 0);
    p->vt = D_0045B7A8;
    p->rider = *(int*)(((sApp_15DE60*)D_004A28A8)->world->riders + (idx << 2) + 0x28);
    func_00161A60(self->chase, (int*)p);
    func_00162060((sCam162060*)self->chase, 0x4C, 0, 1.0f);
    func_00162310((char*)self + 0xC0, (int)p);
    func_0015E030(self);
    self->f454 = 0;
    self->f458 = 0;
    self->f45C = 0;
    switch (idx) {
    case 0:
        self->fB0 = 0;
        break;
    case 1:
        self->fB0 = 1;
        break;
    }
    self->fB4 = 0;
    self->script->viewport = ((sApp_15DE60*)D_004A28A8)->viewports[0];
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015DF98);
#ifdef SKIP_ASM
class cCamVObj_0015DF98 {
public:
    char pad[0x14];
    // vptr at 0x14
    virtual void v01();
    virtual void v02();
};

extern "C" void* func_0015E668(void* self);

extern "C" void func_0015DF98(void* self)
{
    (*(cCamVObj_0015DF98**)((char*)self + 0xA0))->v02();
    func_0015E668(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015DFD8);
#ifdef SKIP_ASM
extern "C" void func_0015DFD8(void* self, int mode)
{
    switch (mode) {
    case 1:
        *(int*)((char*)self + 0xA0) = *(int*)((char*)self + 0xA4);
        break;
    case 2:
        *(int*)((char*)self + 0xA0) = *(int*)((char*)self + 0xA8);
        break;
    case 3:
        *(int*)((char*)self + 0xA0) = *(int*)((char*)self + 0xAC);
        break;
    }
}
#endif

extern "C" void* func_00166F28(void*);

//100%
INCLUDE_ASM("camera/camera", func_0015E030__FPv);
#ifdef SKIP_ASM
void* func_0015E030(void* self)
{
    return func_00166F28((char*)self + 0xc0);
}
#endif

INCLUDE_ASM("camera/camera", func_0015E050);

//100%
INCLUDE_ASM("camera/camera", func_0015E2A8);
#ifdef SKIP_ASM
struct sCamLag_15E2A8 {
    float f0, f4, f8, fC;
    struct {
        float a, b, c, d;
    } group[3];             // 0x10
    float f40, f44, f48, f4C;
};
extern sCamLag_15E2A8 D_004C53E0;
extern int D_004C5430[5];

// Resets the chase camera's tuning constants.
extern "C" void func_0015E2A8(void)
{
    D_004C53E0.f0 = 0.05f;
    D_004C53E0.f4 = 0.01f;
    D_004C53E0.f8 = 0.4f;
    D_004C53E0.fC = 20000.0f;
    D_004C5430[0] = 0;
    D_004C53E0.group[0].a = 0.02f;
    D_004C53E0.group[0].b = 0.01366f;
    D_004C53E0.group[0].c = 0.07f;
    D_004C53E0.group[0].d = -1.0f;
    D_004C5430[1] = 1;
    D_004C53E0.group[1].a = 0.02f;
    D_004C53E0.group[1].b = 0.01366f;
    D_004C53E0.group[1].c = 0.08f;
    D_004C53E0.group[1].d = -1.0f;
    D_004C5430[2] = 1;
    D_004C53E0.group[2].a = 0.02f;
    D_004C53E0.group[2].b = 0.01366f;
    D_004C53E0.group[2].c = 0.09f;
    D_004C53E0.group[2].d = -1.0f;
    D_004C5430[3] = 1;
    D_004C53E0.f40 = 0.1f;
    D_004C53E0.f44 = 0.03f;
    D_004C53E0.f48 = 1.4f;
    D_004C53E0.f4C = -1.0f;
    D_004C5430[4] = 1;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015E360);
#ifdef SKIP_ASM
extern void* D_004A28A8;
struct sCamShake_E360 {
    float f0;
    float f4;
    float weight;   // 0x8
    float range;    // 0xC
};
// View of the tuning block initialised by func_0015E2A8 as one entry per shake type.
extern sCamShake_E360 D_004C53E0_E360[] __asm__("D_004C53E0");

#define MIN_E360(a, b) ((a) <= (b) ? (a) : (b))
#define MAX_E360(a, b) ((b) <= (a) ? (a) : (b))

// Requests a camera shake of 'type' with strength 'amount' at 'dist' from the camera; keeps the strongest request.
// Replays ignore types 1-4.
extern "C" void func_0015E360(char* self, int type, float amount, float dist)
{
    int state = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int replay = state != 0 && state < 10;
    if (replay && (unsigned int)(type - 1) < 4) {
        return;
    }
    float scale;
    float range = D_004C53E0_E360[type].range;
    if (0.0f < dist && 0.0f < range) {
        float t = 2.0f - (dist + dist) / range;
        scale = MAX_E360(MIN_E360(t, 1.0f), 0.0f);
    } else {
        scale = 1.0f;
    }
    float v = amount * scale * D_004C53E0_E360[type].weight;
    if (*(float*)(self + 0x454) < v) {
        *(int*)(self + 0x450) = type;
        *(float*)(self + 0x454) = v;
    }
    *(int*)(self + 0x458) = 1;
}
#endif

INCLUDE_ASM("camera/camera", func_0015E460);

INCLUDE_ASM("camera/camera", func_0015E668);

//100%
INCLUDE_ASM("camera/camera", func_0015EC98);
#ifdef SKIP_ASM
struct sVec4_15EC98
{
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" void func_003A9658(void* self, unsigned int i, sVec4_15EC98* v, float f);
extern "C" int func_003A96E0(void* self, int i, sVec4_15EC98* outPos, float* outT);
extern void* D_004A28A8;

struct sCacheSlot_15EC98
{
    int active;
    char pad[0x4C];
};

struct sWorld_15EC98
{
    char pad[0x250];
    sCacheSlot_15EC98 slots[2];
};
extern char** D_004A47B8;

// PORT: g++ min operator (<?), removed in GCC 4.3.
static inline float clamp_15EC98(float v, float lo, float hi)
{
    float r;
    if (v >= lo)
        r = v <? hi;
    else
        r = lo;
    return r;
}

extern "C" void func_0015EC98(char* self)
{
    float r;
    if (*(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84) + 0x10) == 1)
        r = *(float*)(self + 0x8);
    else
        r = clamp_15EC98(*(float*)(self + 0x8), 0.0f, 15000.0f);
    float r15 = r * 1.5f;
    float far = clamp_15EC98(r * 0.6666666865348816f, 15000.0f, 30000.0f);
    char** sys = D_004A47B8;
    ((sWorld_15EC98*)*sys)->slots[*(int*)(self + 0xB0)].active = 1;
    func_003A9658(*sys + 0x10, *(int*)(self + 0xB0), (sVec4_15EC98*)(self + 0x20), r15);
    *(int*)(self + 0xB4) = 0;
    sVec4_15EC98 pos;
    float t;
    if (func_003A96E0(*sys + 0x10, *(int*)(self + 0xB0), &pos, &t)) {
        if (far <= t || r <= t)
            *(int*)(self + 0xB4) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015EDC8);
#ifdef SKIP_ASM
class cCamVObj_0015EDC8 {
public:
    char pad[0x14];
    // vptr at 0x14 (g++ 2.95 places it after the class's own data)
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
};

extern "C" void func_0015EDC8(void* self, int value)
{
    char* obj = *(char**)((char*)self + 0xA8);
    *(int*)(*(char**)(obj + 0x20) + 0x4) = value;
    (*(cCamVObj_0015EDC8**)((char*)self + 0xA8))->v04();
}
#endif

INCLUDE_ASM("camera/camera", func_0015EE00);

//100%
INCLUDE_ASM("camera/camera", func_0015F568);
#ifdef SKIP_ASM
extern "C" void* func_0011FF48(void* dst, void* self);

extern "C" void* func_0015F568(void* self, void* a1)
{
    func_0011FF48(self, *(void**)((char*)a1 + 0x4));
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F598);
#ifdef SKIP_ASM
extern "C" void* func_0015F598(void* self, void* a1)
{
    void* p = *(void**)((char*)a1 + 0x4);
    *(cQuad128*)self = *(cQuad128*)((char*)p + 0x120);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F5B0);
#ifdef SKIP_ASM
struct sQuad_0015F5B0 {
    float v[4];
} __attribute__((aligned(16)));

class cCamVObj_0015F5B0 {
public:
    // vptr at 0x0
    virtual void v01();
    virtual sQuad_0015F5B0* v02();
};

extern "C" void* func_0015F5B0(void* self, void* a1)
{
    char* p = *(char**)((char*)a1 + 0x4);
    *(sQuad_0015F5B0*)self = *((cCamVObj_0015F5B0*)(p + 0x6C0))->v02();
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F5F8);
#ifdef SKIP_ASM
extern "C" void* func_0015F5F8(void* self, void* a1)
{
    void* p = *(void**)((char*)a1 + 0x4);
    *(cQuad128*)self = *(cQuad128*)((char*)p + 0x1b0);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F610);
#ifdef SKIP_ASM
extern "C" void* func_0015F610(void* self, void* a1)
{
    void* p = *(void**)((char*)a1 + 0x4);
    *(cQuad128*)self = *(cQuad128*)((char*)p + 0x1a0);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F628);
#ifdef SKIP_ASM
extern "C" void* func_0015F628(void* self, void* a1)
{
    void* p = *(void**)((char*)a1 + 0x4);
    *(cQuad128*)self = *(cQuad128*)((char*)p + 0x1c0);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F640__FPv);
#ifdef SKIP_ASM
float func_0015F640(void* self)
{
    return *(float*)((char*)*(void**)((char*)self + 0x4) + 0x1f0);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F650);
#ifdef SKIP_ASM
extern "C" void* func_0015F650(void* self, void* a1)
{
    void* p = *(void**)((char*)a1 + 0x4);
    *(cQuad128*)self = *(cQuad128*)((char*)p + 0x370);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F668);
#ifdef SKIP_ASM
extern "C" void* func_0015F668(void* self, void* a1)
{
    void* p = *(void**)((char*)a1 + 0x4);
    *(cQuad128*)self = *(cQuad128*)((char*)p + 0x380);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F680__FPv);
#ifdef SKIP_ASM
void* func_0015F680(void* self)
{
    return (char*)*(void**)((char*)*(void**)((char*)self + 0x4) + 0x77c) + 0x130;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F690__FPv);
#ifdef SKIP_ASM
void* func_0015F690(void* self)
{
    return (char*)*(void**)((char*)*(void**)((char*)self + 0x4) + 0x77c) + 0x140;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F6A0__FPv);
#ifdef SKIP_ASM
float func_0015F6A0(void* self)
{
    return *(float*)((char*)*(void**)((char*)*(void**)((char*)self + 0x4) + 0x788) + 0x98);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F6B0);
#ifdef SKIP_ASM
extern "C" float func_0015F6B0(void* self)
{
    void* p = *(void**)((char*)self + 0x4);
    void* p2 = *(void**)((char*)p + 0x788);
    return *(float*)((char*)p2 + 0x98) - *(float*)((char*)p2 + 0xa0);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F6C8);
#ifdef SKIP_ASM
extern "C" float func_0015F6C8(void* self)
{
    void* p = *(void**)((char*)self + 0x4);
    void* p2 = *(void**)((char*)p + 0x788);
    return *(float*)((char*)p2 + 0x9c) - *(float*)((char*)p2 + 0xa0);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F6E0__FPv);
#ifdef SKIP_ASM
void* func_0015F6E0(void* self)
{
    return (char*)*(void**)((char*)*(void**)((char*)self + 0x4) + 0x788) + 0x40;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F6F0__FPv);
#ifdef SKIP_ASM
void* func_0015F6F0(void* self)
{
    return (char*)*(void**)((char*)self + 0x4) + 0x3c0;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F700__FPv);
#ifdef SKIP_ASM
float func_0015F700(void* self)
{
    return *(float*)((char*)*(void**)((char*)self + 0x4) + 0x2fc);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F710__FPv);
#ifdef SKIP_ASM
float func_0015F710(void* self)
{
    return *(float*)((char*)*(void**)((char*)self + 0x4) + 0x220);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F720);
#ifdef SKIP_ASM
extern "C" int func_0015F720(void* self)
{
    void* a = *(void**)((char*)self + 0x4);
    void* b = *(void**)((char*)a + 0x788);
    int s = *(int*)((char*)b + 0xAC);
    int r = 0;
    if (s == 1 || s == 3) {
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F750__FPv);
#ifdef SKIP_ASM
int func_0015F750(void* self)
{
    return *(int*)((char*)*(void**)((char*)self + 0x4) + 0x438);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F760__FPv);
#ifdef SKIP_ASM
float func_0015F760(void* self)
{
    return *(float*)((char*)*(void**)((char*)self + 0x4) + 0x5a4);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F770__FPv);
#ifdef SKIP_ASM
int func_0015F770(void* self)
{
    return *(int*)((char*)*(void**)((char*)self + 0x4) + 0x5a8);
}
#endif

INCLUDE_ASM("camera/camera", func_0015F780);

//100%
INCLUDE_ASM("camera/camera", func_0015F908__FPv);
#ifdef SKIP_ASM
int func_0015F908(void* self)
{
    return *(int*)((char*)*(void**)((char*)self + 0x4) + 0x5ac);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F918__FPv);
#ifdef SKIP_ASM
void* func_0015F918(void* self)
{
    return (char*)*(void**)((char*)*(void**)((char*)self + 0x4) + 0x788) + 0x20;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F928__FPv);
#ifdef SKIP_ASM
void* func_0015F928(void* self)
{
    return (char*)*(void**)((char*)*(void**)((char*)self + 0x4) + 0x788) + 0x10;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F938);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
extern void* D_0045BD78[];
// PORT: cQuad128 (the unit's 128-bit TImode typedef) is a 16-byte register copy.
extern cQuad128 D_004FF130;
extern "C" float func_00167E30(void* self);

extern "C" void* func_0015F938(void* self)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    *(float*)self = func_00167E30(self);
    *(int*)((char*)self + 0xC) = 0x4E;
    *(float*)((char*)self + 0x4) = 10.0f;
    *(float*)((char*)self + 0x8) = 30000.0f;
    *(void***)((char*)self + 0x10) = D_0045BD78;
    *(int*)((char*)self + 0x30) = 0;
    *(int*)((char*)self + 0x34) = 0;
    cQuad128 v = D_004FF130;
    *(int*)((char*)self + 0xC) = 0x4F;
    *(cQuad128*)((char*)self + 0x20) = v;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015F9B8);
#ifdef SKIP_ASM
struct sV_15F9B8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_15F9B8 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPair_15F9B8 {
    sV_15F9B8 a;
    sV_15F9B8 b;
};

extern sM_15F9B8 D_004FF1A0_15F9B8 __asm__("D_004FF1A0");
extern sV_15F9B8 D_004FF150_15F9B8 __asm__("D_004FF150");
extern sV_15F9B8 D_004FF160_v15F9B8 __asm__("D_004FF160");
extern "C" void func_0031BE50(float* sout, float* cout, float x);
extern "C" sPair_15F9B8 func_0031B748_15F9B8(sM_15F9B8* m) __asm__("func_0031B748");

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_15F9B8(sM_15F9B8* dst, const sM_15F9B8* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_15F9B8(sM_15F9B8* dst, const sM_15F9B8* a, const sM_15F9B8* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_15F9B8(sM_15F9B8* m, const sV_15F9B8& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

static inline void SinCos_15F9B8(float* s, float* c, float angle)
{
    func_0031BE50(s, c, angle);
}

static inline void RotAxis_15F9B8(sM_15F9B8* m, const sV_15F9B8& axis, float angle)
{
    sM_15F9B8 r;
    float s;
    float c;
    float one = 1.0f;
    SinCos_15F9B8(&s, &c, angle);
    float t = one - c;
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    r.m[0][0] = tx * x + c;
    r.m[1][0] = tx * y + sz;
    r.m[2][0] = tx * z - sy;
    r.m[0][1] = ty * x - sz;
    r.m[1][1] = ty * y + c;
    r.m[2][1] = ty * z + sx;
    r.m[0][2] = tz * x + sy;
    r.m[1][2] = tz * y - sx;
    r.m[2][2] = tz * z + c;
    r.m[3][0] = 0.0f;
    r.m[3][1] = 0.0f;
    r.m[3][2] = 0.0f;
    r.m[0][3] = 0.0f;
    r.m[1][3] = 0.0f;
    r.m[2][3] = 0.0f;
    r.m[3][3] = one;
    vu0MulMtx_15F9B8(m, m, &r);
}

extern "C" sPair_15F9B8 func_0015F9B8(char* src)
{
    sM_15F9B8 m;
    vu0CopyMtx_15F9B8(&m, &D_004FF1A0_15F9B8);
    vu0TransMtx_15F9B8(&m, *(sV_15F9B8*)(src + 0x20));
    RotAxis_15F9B8(&m, D_004FF150_15F9B8, -*(float*)(src + 0x30));
    RotAxis_15F9B8(&m, D_004FF160_v15F9B8, *(float*)(src + 0x34));
    return func_0031B748_15F9B8(&m);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/camera", func_0015FD08);
#ifdef SKIP_ASM
extern "C" void* func_0015F938(void* self);
extern void* D_0045BD10[];

extern "C" void* func_0015FD08(void* self)
{
    func_0015F938(self);
    *(int*)((char*)self + 0xC) = 0x51;
    *(void***)((char*)self + 0x10) = D_0045BD10;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015FD48__FPv);
#ifdef SKIP_ASM
void func_0015FD48(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015FD50);
#ifdef SKIP_ASM
extern void* D_004A28A8;
// PORT: func_00320BF0 returns a float (input axis value, $f0).
extern "C" float func_00320BF0(int pad, int axis);
extern "C" float func_0031BF60(float x);
extern "C" float func_0031C040(float x);

struct sVec_0015FD50 {
    float x, y, z, w;
    sVec_0015FD50() {}
    sVec_0015FD50(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    sVec_0015FD50& operator+=(const sVec_0015FD50& b);
} __attribute__((aligned(16)));

struct sFreeCam_0015FD50 {
    char pad0[0x20];
    sVec_0015FD50 pos;  // 0x20
    float pitch;        // 0x30
    float yaw;          // 0x34
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec_0015FD50 fcScale_0015FD50(const sVec_0015FD50& v, float s)
{
    sVec_0015FD50 r;
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

// PORT: PS2-only VU0 inline asm (vector add, in place).
inline sVec_0015FD50& sVec_0015FD50::operator+=(const sVec_0015FD50& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(*this)
        : "m"(*this), "m"(b)
        : "memory");
    return *this;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec_0015FD50 fcAdd_0015FD50(const sVec_0015FD50& a, const sVec_0015FD50& b)
{
    sVec_0015FD50 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline float fcClamp_0015FD50(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_0015FD50(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

// PORT: g++ `>?` / `<?` (max/min) operators.
extern "C" void func_0015FD50(sFreeCam_0015FD50* self)
{
    int pad = *(int*)(*(char**)(*(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84) + 0x4) + 0xA4) + 0xC);
    float speed = func_00320BF0(pad, 0x34);
    float ry = func_00320BF0(pad, 0x31);
    float rx = func_00320BF0(pad, 0x30);
    float mf = func_00320BF0(pad, 0x32);
    float ms = func_00320BF0(pad, 0x33);
    float rs = speed >? 2.0f;
    float pitch = fcClamp_0015FD50(self->pitch + rs * (ry * 0.6283185482025146f) * 0.01666666753590107f,
                                   -1.5707963705062866f, 1.5707963705062866f);
    float yaw = self->yaw + rs * (rx * 0.6283185482025146f) * 0.01666666753590107f;
    yaw -= ffloor_0015FD50(yaw * 0.15915493667125702f) * 6.2831854820251465f;
    sVec_0015FD50 fwd(func_0031C040(pitch) * func_0031C040(yaw), func_0031C040(pitch) * func_0031BF60(yaw),
                      func_0031BF60(pitch), 0.0f);
    sVec_0015FD50 right(func_0031BF60(yaw), -func_0031C040(yaw), 0.0f, 0.0f);
    sVec_0015FD50 pos = fcAdd_0015FD50(sVec_0015FD50(self->pos), fcScale_0015FD50(fwd, speed * (mf * 25.0f)));
    pos += fcScale_0015FD50(right, speed * (ms * -25.0f));
    self->pitch = pitch;
    self->yaw = yaw;
    self->pos = pos;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/camera", func_0015FFB0);
#ifdef SKIP_ASM
extern "C" void* func_0015F938(void* self);
extern void* D_0045BCA8[];

extern "C" void* func_0015FFB0(void* self)
{
    func_0015F938(self);
    *(int*)((char*)self + 0xC) = 0x50;
    *(void***)((char*)self + 0x10) = D_0045BCA8;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_0015FFF0);
#ifdef SKIP_ASM
extern "C" void* func_0015FFF0(void* self)
{
    *(float*)((char*)self + 0x28) = 0.05000000074505806f;
    *(float*)((char*)self + 0x2C) = 0.05000000074505806f;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(float*)((char*)self + 0x20) = 1.0499999523162842f;
    *(float*)((char*)self + 0x24) = 1.0499999523162842f;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160028);
#ifdef SKIP_ASM
int BXrand();

struct sShake_160028
{
    float x;        // 0x0
    float y;        // 0x4
    float pad8;
    float nx;       // 0xC
    float ny;       // 0x10
    float pad14;
    float amount;   // 0x18
    float pad1C;
    float timer;    // 0x20
    float pad24;
    float period;   // 0x28
};

// Uniform float in [0, 1) built from the random mantissa bits.
static inline float randf_160028()
{
    union {
        int i;
        float f;
    } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

extern "C" void func_00160028(sShake_160028* self, float amount)
{
    self->amount = amount;
    if (amount != 0.0f) {
        if (self->timer > self->period) {
            self->x = self->nx;
            self->y = self->ny;
            self->nx = (randf_160028() - 0.5f) * 2.0f;
            self->ny = (randf_160028() - 0.5f) * 2.0f;
            self->timer = 0.0f;
        } else {
            self->timer = self->timer + 0.01666666753590107f;
        }
    } else {
        self->x = 0.0f;
        self->y = 0.0f;
        self->nx = 0.0f;
        self->ny = 0.0f;
        self->timer = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160130);
#ifdef SKIP_ASM
int BXrand();

struct sRollShake_160130
{
    float pad0[2];
    float cur;      // 0x8
    float pad0C[2];
    float next;     // 0x14
    float pad18;
    float amount;   // 0x1C
    float pad20;
    float timer;    // 0x24
    float pad28;
    float period;   // 0x2C
};

// Uniform float in [0, 1) built from the random mantissa bits.
static inline float randf_160130()
{
    union {
        int i;
        float f;
    } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

// PORT: abs.s via inline asm (as an SDK math-header fabsf would).
static inline float fabs_160130(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_00160130(sRollShake_160130* self, float amount)
{
    self->amount = amount;
    if (amount != 0.0f) {
        if (self->timer > self->period) {
            self->cur = self->next;
            while (fabs_160130(self->cur - self->next) < 0.5f)
                self->next = (randf_160130() - 0.5f) * 2.0f;
            self->timer = 0.0f;
        } else {
            self->timer = self->timer + 0.01666666753590107f;
        }
    } else {
        self->timer = 0.0f;
        self->next = 0.0f;
        self->cur = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160228);
#ifdef SKIP_ASM
extern "C" float func_0031BF60(float x);
extern "C" float func_0031C040(float x);

struct sVec_00160228 {
    float x, y, z, w;
    sVec_00160228() {}
    sVec_00160228(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

extern sVec_00160228 D_004FF120_v160228 __asm__("D_004FF120");

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec_00160228 Scale_00160228(const sVec_00160228& v, float s)
{
    sVec_00160228 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec_00160228 Add_00160228(const sVec_00160228& a, const sVec_00160228& b)
{
    sVec_00160228 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sVec_00160228 Cross_00160228(const sVec_00160228& a, const sVec_00160228& b)
{
    sVec_00160228 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

extern "C" sVec_00160228 func_00160228(char* p, float a, float b)
{
    float zero = 0.0f;
    if (*(float*)(p + 0x18) == zero) return D_004FF120_v160228;
    sVec_00160228 fwd(func_0031C040(b) * func_0031C040(a), func_0031C040(b) * func_0031BF60(a), -func_0031BF60(b), zero);
    sVec_00160228 right(func_0031BF60(a), -func_0031C040(a), zero, zero);
    sVec_00160228 up = Cross_00160228(fwd, right);
    float k = *(float*)(p + 0x20) / *(float*)(p + 0x28);
    float sx = k * (*(float*)(p + 0xC) - *(float*)(p + 0x0));
    float sy = k * (*(float*)(p + 0x10) - *(float*)(p + 0x4));
    float sz = *(float*)(p + 0x18) * 10.0f;
    sVec_00160228 res = Scale_00160228(Add_00160228(Scale_00160228(right, sx), Scale_00160228(up, sy)), sz);
    return res;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001603F0);
#ifdef SKIP_ASM
extern "C" float func_001603F0(void* self)
{
    float s = *(float*)((char*)self + 0x1C);
    if (s == 0.0f)
        return 0.0f;
    return s * (*(float*)((char*)self + 0x24) / *(float*)((char*)self + 0x2C) * 0.007853982038795948f)
             * (*(float*)((char*)self + 0x14) - *(float*)((char*)self + 0x8));
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160438);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045BAD0[];

extern "C" void* func_00160438(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0xB;
    *(void***)((char*)self + 0x10) = D_0045BAD0;
    return self;
}
#endif

extern void* D_0045BAD0[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_00160478__FPv);
#ifdef SKIP_ASM
void* func_00160478(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045BAD0;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001604A0__FPv);
#ifdef SKIP_ASM
float func_001604A0(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001604B0__FPvT0);
#ifdef SKIP_ASM
void func_001604B0(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001604B8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" float func_00320BF0(int pad, int axis);
extern "C" void func_00162568(void* self, struct sCamInfo_001607E0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);
extern "C" void func_001668B8(void* self, void* out);
extern float D_004A127C;
extern float D_004A1280;
extern float D_004A1284;

struct sVec_1604B8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCamInfo_1604B8 {
    char pad0[0x10];
    sVec_1604B8 pos;    // 0x10
    char pad20[0x50];
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec_1604B8 Scale_1604B8(const sVec_1604B8& v, float s)
{
    sVec_1604B8 r;
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec_1604B8 Sub_1604B8(const sVec_1604B8& a, const sVec_1604B8& b)
{
    sVec_1604B8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place v /= s).
static inline void DivEq_1604B8(sVec_1604B8& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_1604B8(const sVec_1604B8& v)
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

// PORT: PS2-only inline asm (float absolute value).
static inline float Abs_1604B8(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ `<?` (min) operator.
static inline float Clamp_1604B8(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

struct sCamYP_1604B8 {
    char pad0[0x50];
    float yaw;          // 0x50
    float pitch;        // 0x54
};

struct sGame_1604B8 {
    char pad0[0x84];
    char* f84;          // 0x84
    char pad88[0xB0 - 0x88];
    int pads[4];        // 0xB0
};

extern "C" void func_001604B8(char* self)
{
    sCamInfo_1604B8 info;
    func_00162568(self, (sCamInfo_001607E0*)&info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    sGame_1604B8* g = (sGame_1604B8*)D_004A28A8;
    int pad = g->pads[*(int*)(*(char**)(g->f84 + 0x28) + 0x28)];
    float ax = func_00320BF0(pad, 0xBE);
    float ay = func_00320BF0(pad, 0xBF);
    float az = -func_00320BF0(pad, 0xC0);
    ax *= Abs_1604B8(ax);
    ay *= Abs_1604B8(ay);
    az *= Abs_1604B8(az);
    ax *= 0.05000000074505806f;
    D_004A127C += ax;
    if (D_004A127C > 6.2831854820251465f) {
        D_004A127C = D_004A127C - 6.2831854820251465f;
    } else if (D_004A127C < 0.0f) {
        D_004A127C = D_004A127C + 6.2831854820251465f;
    }
    float k = 0.05000000074505806f;
    D_004A1280 += ay * k;
    D_004A1280 = Clamp_1604B8(D_004A1280, 0.0f, 1.5079644918441772f);
    ((sCamYP_1604B8*)self)->pitch = D_004A1280;
    ((sCamYP_1604B8*)self)->yaw = D_004A127C;
    sVec_1604B8 dir;
    func_001668B8(self, &dir);
    DivEq_1604B8(dir, Length_1604B8(dir));
    D_004A1284 = Clamp_1604B8(D_004A1284 * (az * k + 1.0f), 150.0f, 850.0f);
    *(sVec_1604B8*)(self + 0x20) = info.pos;
    *(sVec_1604B8*)(self + 0x40) = Sub_1604B8(*(sVec_1604B8*)(self + 0x20), Scale_1604B8(dir, D_004A1284));
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001606D8);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);

struct sCamVEntryIntA {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sCamVEntryVoidA {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_001606D8(void* self, int id)
{
    char* obj = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sCamVEntryIntA* vt = *(sCamVEntryIntA**)obj;
    if (id == vt[7].fn(obj + vt[7].delta))
    {
        func_00166C60(self, id);
        func_00166550(self, 100.0f, 100.0f);
        sCamVEntryVoidA* vt2 = *(sCamVEntryVoidA**)((char*)self + 0x10);
        vt2[5].fn((char*)self + vt2[5].delta);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160760);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045BA58[];

extern "C" void* func_00160760(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x29;
    *(void***)((char*)self + 0x10) = D_0045BA58;
    *(int*)((char*)self + 0x390) = 0;
    return self;
}
#endif

extern void* D_0045BA58[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_001607A0__FPv);
#ifdef SKIP_ASM
void* func_001607A0(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045BA58;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001607C8__FPv);
#ifdef SKIP_ASM
float func_001607C8(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001607D8__FPvT0);
#ifdef SKIP_ASM
void func_001607D8(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001607E0);
#ifdef SKIP_ASM
extern "C" float func_0031BF60(float x);
extern "C" float func_0031C040(float x);

struct sVec_001607E0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCamInfo_001607E0 {
    char pad0[0x20];
    sVec_001607E0 dir;  // 0x20
    char pad30[0x38];
} __attribute__((aligned(16)));

// asm-label views: camera.cpp declares these globals as cQuad128
extern sVec_001607E0 D_004FF140_v1607E0 __asm__("D_004FF140");
extern sVec_001607E0 D_004FF160_v1607E0 __asm__("D_004FF160");
extern "C" void func_00162568(void* self, sCamInfo_001607E0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);

struct sVEv_001607E0 {
    short delta;
    short index;
    sVec_001607E0 (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec_001607E0 cmScale_001607E0(const sVec_001607E0& v, float s)
{
    sVec_001607E0 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec_001607E0 cmAdd_001607E0(const sVec_001607E0& a, const sVec_001607E0& b)
{
    sVec_001607E0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sVec_001607E0 cmCross_001607E0(const sVec_001607E0& a, const sVec_001607E0& b)
{
    sVec_001607E0 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float cmLength_001607E0(const sVec_001607E0& v)
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

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void cmDivEq_001607E0(sVec_001607E0& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

static inline void cmNormalize_001607E0(sVec_001607E0& v)
{
    cmDivEq_001607E0(v, cmLength_001607E0(v));
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_001607E0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline sVec_001607E0 cmGet_001607E0(char* self, int slot)
{
    char* o = *(char**)(self + 0x30);
    sVEv_001607E0* e = &(*(sVEv_001607E0**)o)[slot];
    return e->fn(o + e->delta);
}

extern "C" void func_001607E0(char* self)
{
    sCamInfo_001607E0 info;
    func_00162568(self, &info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    float eps = 0.0010000000474974513f;
    sVec_001607E0 dir;
    if (__builtin_fabsf(info.dir.x) > eps || __builtin_fabsf(info.dir.y) > eps) {
        dir = info.dir;
    } else {
        dir = cmGet_001607E0(self, 4);
        if (__builtin_fabsf(dir.x) < eps && __builtin_fabsf(dir.y) < eps) {
            dir = D_004FF140_v1607E0;
        }
    }
    dir.z = 0.0f;
    sVec_001607E0 side = cmCross_001607E0(D_004FF160_v1607E0, dir);
    cmNormalize_001607E0(dir);
    cmNormalize_001607E0(side);
    float* ang = (float*)(self + 0x390);
    *ang += 0.061352409422397614f;
    *ang -= ffloor_001607E0(*ang * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
    float r = 216.23182678222656f;
    *(sVec_001607E0*)(self + 0x20) = cmAdd_001607E0(cmGet_001607E0(self, 1), cmScale_001607E0(D_004FF160_v1607E0, 0.0f));
    *(sVec_001607E0*)(self + 0x40) = cmAdd_001607E0(
        cmAdd_001607E0(cmAdd_001607E0(*(sVec_001607E0*)(self + 0x20), cmScale_001607E0(dir, func_0031C040(*ang) * r)),
                       cmScale_001607E0(side, func_0031BF60(*ang) * r)),
        cmScale_001607E0(D_004FF160_v1607E0, -0.5597707033157349f));
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160AE8);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);

extern "C" void func_00160AE8(void* self, int id)
{
    char* obj = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sCamVEntryIntA* vt = *(sCamVEntryIntA**)obj;
    if (id == vt[7].fn(obj + vt[7].delta))
    {
        func_00166C60(self, id);
        func_00166550(self, 100.0f, 100.0f);
        sCamVEntryVoidA* vt2 = *(sCamVEntryVoidA**)((char*)self + 0x10);
        vt2[5].fn((char*)self + vt2[5].delta);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160B70);
#ifdef SKIP_ASM
extern void* D_0045B9E0[];
extern "C" void* func_00162318(void* self);

extern "C" void* func_00160B70(void* self, float f)
{
    func_00162318(self);
    *(float*)((char*)self + 0x390) = f;
    *(void***)((char*)self + 0x10) = D_0045B9E0;
    *(int*)((char*)self + 0x394) = 0;
    return self;
}
#endif

extern void* D_0045B9E0[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_00160BB8__FPv);
#ifdef SKIP_ASM
void* func_00160BB8(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045B9E0;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160BE0__FPv);
#ifdef SKIP_ASM
float func_00160BE0(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160BF0__FPvT0);
#ifdef SKIP_ASM
void func_00160BF0(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160BF8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec_001607E0 cmSub_00160BF8(const sVec_001607E0& a, const sVec_001607E0& b)
{
    sVec_001607E0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

extern "C" void func_00160BF8(char* self)
{
    sCamInfo_001607E0 info;
    func_00162568(self, &info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    float eps = 0.0010000000474974513f;
    sVec_001607E0 dir;
    if (__builtin_fabsf(info.dir.x) > eps || __builtin_fabsf(info.dir.y) > eps) {
        dir = info.dir;
    } else {
        dir = cmGet_001607E0(self, 4);
        if (__builtin_fabsf(dir.x) < eps && __builtin_fabsf(dir.y) < eps) {
            dir = D_004FF140_v1607E0;
        }
    }
    dir.z = 0.0f;
    sVec_001607E0 side = cmCross_001607E0(D_004FF160_v1607E0, dir);
    cmNormalize_001607E0(dir);
    cmNormalize_001607E0(side);
    *(sVec_001607E0*)(self + 0x20) = cmAdd_001607E0(cmGet_001607E0(self, 1), cmScale_001607E0(D_004FF160_v1607E0, 0.0f));
    if (*(int*)(self + 0x394)) {
        *(sVec_001607E0*)(self + 0x20) = cmAdd_001607E0(cmScale_001607E0(*(sVec_001607E0*)(self + 0x3B0), 0.6399999856948853f),
                                                    cmScale_001607E0(*(sVec_001607E0*)(self + 0x20), 0.36000001430511475f));
    }
    *(sVec_001607E0*)(self + 0x3B0) = *(sVec_001607E0*)(self + 0x20);
    float r = 385.91839599609375f;
    *(sVec_001607E0*)(self + 0x40) = cmAdd_001607E0(
        cmAdd_001607E0(cmAdd_001607E0(*(sVec_001607E0*)(self + 0x20), cmScale_001607E0(dir, func_0031C040(*(float*)(self + 0x390)) * r)),
                       cmScale_001607E0(side, func_0031BF60(*(float*)(self + 0x390)) * r)),
        cmScale_001607E0(D_004FF160_v1607E0, 53.241573333740234f));
    if (*(int*)(self + 0x394)) {
        sVec_001607E0 d = cmSub_00160BF8(*(sVec_001607E0*)(self + 0x20), *(sVec_001607E0*)(self + 0x40));
        sVec_001607E0 e = cmAdd_001607E0(cmScale_001607E0(*(sVec_001607E0*)(self + 0x3A0), 0.9700000286102295f),
                                         cmScale_001607E0(d, 0.029999971389770508f));
        *(sVec_001607E0*)(self + 0x40) = cmSub_00160BF8(*(sVec_001607E0*)(self + 0x20), e);
    }
    *(sVec_001607E0*)(self + 0x3A0) = cmSub_00160BF8(*(sVec_001607E0*)(self + 0x20), *(sVec_001607E0*)(self + 0x40));
    *(int*)(self + 0x394) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00160FD0);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);

extern "C" void func_00160FD0(void* self, int id)
{
    char* obj = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sCamVEntryIntA* vt = *(sCamVEntryIntA**)obj;
    if (id == vt[7].fn(obj + vt[7].delta))
    {
        func_00166C60(self, id);
        func_00166550(self, 100.0f, 100.0f);
        *(int*)((char*)self + 0x394) = 0;
        sCamVEntryVoidA* vt2 = *(sCamVEntryVoidA**)((char*)self + 0x10);
        vt2[5].fn((char*)self + vt2[5].delta);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161060);
#ifdef SKIP_ASM
extern void* D_0045B968[];
extern "C" void func_0031D5E8(void* spline);
// PORT: func_0031D700 is declared (void*) but forwards a second argument (the key count) in $a1.
void func_0031D700_2(void* spline, int n) __asm__("func_0031D700__FPv");
extern "C" void func_0031D7E0(void* spline, float x, float y);
extern "C" float func_0031DEE0(void* spline, float x);

struct sVec_161060 {
    float x, y, z, w;
    sVec_161060() {}
    sVec_161060(float a, float b, float c, const float& d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec_161060 Sub_161060(const sVec_161060& a, const sVec_161060& b)
{
    sVec_161060 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_161060(const sVec_161060& v)
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

extern "C" void* func_00161060(char* self, float* p0, float* p1, float* p2, float* p3, float dur, float a, float b,
                               float c)
{
    func_00162318(self);
    *(void***)(self + 0x10) = D_0045B968;
    char* sx = self + 0x390;
    char* sy = self + 0x39C;
    char* sz = self + 0x3A8;
    func_0031D5E8(sx);
    func_0031D5E8(sy);
    func_0031D5E8(sz);
    *(float*)(self + 0x3C0) = a;
    *(float*)(self + 0x3C4) = b;
    *(float*)(self + 0x0) = c;
    *(int*)(self + 0xC) = 0x4B;
    func_0031D700_2(sx, 4);
    func_0031D700_2(sy, 4);
    func_0031D700_2(sz, 4);
    float t1 = dur * 0.33333298563957214f;
    float t2 = dur * 0.6666669845581055f;
    func_0031D7E0(sx, 0.0f, p0[0]);
    func_0031D7E0(sx, t1, p1[0]);
    func_0031D7E0(sx, t2, p2[0]);
    func_0031D7E0(sx, dur, p3[0]);
    func_0031D7E0(sy, 0.0f, p0[1]);
    func_0031D7E0(sy, t1, p1[1]);
    func_0031D7E0(sy, t2, p2[1]);
    func_0031D7E0(sy, dur, p3[1]);
    func_0031D7E0(sz, 0.0f, p0[2]);
    func_0031D7E0(sz, t1, p1[2]);
    func_0031D7E0(sz, t2, p2[2]);
    func_0031D7E0(sz, dur, p3[2]);
    *(float*)(self + 0x3B4) = dur;
    *(float*)(self + 0x3B8) = 0.0f;
    float total = 0.0f;
    sVec_161060 prev(func_0031DEE0(sx, total), func_0031DEE0(sy, total), func_0031DEE0(sz, total), 1.0f);
    for (int i = 1; i < 101; i++) {
        float t = (dur * (float)i * 0.009999999776482582f) <? dur;
        sVec_161060 cur(func_0031DEE0(self + 0x390, t), func_0031DEE0(self + 0x39C, t), func_0031DEE0(self + 0x3A8, t), 1.0f);
        sVec_161060 d = Sub_161060(cur, prev);
        total += Length_161060(d);
        prev = cur;
    }
    *(float*)(self + 0x3BC) = total * 0.8999999761581421f / dur;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161370);
#ifdef SKIP_ASM
extern void* D_0045B968[];
extern "C" void func_0031D618(void* p, int flags);
// PORT: func_00162458 is the base deleting dtor (self, flags); the unit declares it with one arg.
void func_00162458_dtor(void* self, int flags) __asm__("func_00162458");

extern "C" void func_00161370(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045B968;
    func_0031D618((char*)self + 0x3A8, 2);
    func_0031D618((char*)self + 0x39C, 2);
    func_0031D618((char*)self + 0x390, 2);
    func_00162458_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001613D8__FPv);
#ifdef SKIP_ASM
float func_001613D8(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001613E8__FPvT0);
#ifdef SKIP_ASM
void func_001613E8(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

INCLUDE_ASM("camera/camera", func_001613F0);

//100%
INCLUDE_ASM("camera/camera", func_00161630);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);

struct sCamVEntryInt {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sCamVEntryVoid {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00161630(void* self, int id)
{
    char* obj = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sCamVEntryInt* vt = *(sCamVEntryInt**)obj;
    if (id == vt[7].fn(obj + vt[7].delta))
    {
        func_00166C60(self, id);
        sCamVEntryVoid* vt2 = *(sCamVEntryVoid**)((char*)self + 0x10);
        vt2[5].fn((char*)self + vt2[5].delta);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001616A8);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045BB48[];

extern "C" void* func_001616A8(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x7;
    *(void***)((char*)self + 0x10) = D_0045BB48;
    return self;
}
#endif

extern void* D_0045BB48[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_001616E8__FPv);
#ifdef SKIP_ASM
void* func_001616E8(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045BB48;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161710__FPv);
#ifdef SKIP_ASM
float func_00161710(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161720__FPvT0);
#ifdef SKIP_ASM
void func_00161720(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

INCLUDE_ASM("camera/camera", func_00161728);

INCLUDE_ASM("camera/camera", func_00161848);

//100%
INCLUDE_ASM("camera/camera", func_00161950);
#ifdef SKIP_ASM
struct func_00161950_flags {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
};

extern int D_004A4DD0[2];

extern "C" void func_00161950(void* self, int i)
{
    *(int*)((char*)self + 0x1C) = 0x3D;
    *(int*)((char*)self + 0x38) = 0;
    ((func_00161950_flags*)((char*)self + 0x30))->b1 = 0; ((func_00161950_flags*)((char*)self + 0x30))->b0 = 0; ((func_00161950_flags*)((char*)self + 0x30))->b2 = 0;
    *(int*)((char*)self + 0x3C) = 0;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x2C) = 0x3D;
    *(int*)((char*)self + 0x24) = D_004A4DD0[i];
    *(int*)((char*)self + 0x28) = 0x3D;
    *(int*)((char*)self + 0x34) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/camera", func_001619A8);
#ifdef SKIP_ASM
extern void* D_0045B908[];
extern "C" void* cCameraController_cCameraController(void* self, int a);
extern "C" void func_00161950(void* self, int idx);

extern "C" void* func_001619A8(void* self, int idx, int a)
{
    cCameraController_cCameraController(self, a);
    *(void***)((char*)self + 0x14) = D_0045B908;
    *(int*)((char*)self + 0x0) = 2;
    *(int*)((char*)self + 0x4) = 1;
    *(int*)((char*)self + 0x20) = 0;
    func_00161950(self, idx);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161A10);
#ifdef SKIP_ASM
extern void* D_0045B908[];
void operator_delete(int* ptr);
extern "C" void func_0015CC10(void* self, int flags);

extern "C" void func_00161A10(void* self, int flags)
{
    *(void***)((char*)self + 0x14) = D_0045B908;
    operator_delete(*(int**)((char*)self + 0x20));
    func_0015CC10(self, flags);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161A60);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00161A60(void* self, int* p)
{
    int* old = *(int**)((char*)self + 0x20);
    if (old != 0) {
        operator_delete(old);
    }
    *(int**)((char*)self + 0x20) = p;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161AA0);
#ifdef SKIP_ASM
extern "C" int func_00161AA0(void *arg0) {
    return (*(int *)((char*)((*(void **)((char*)(arg0) + (0x20)))) + (4)));
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161AB0);
#ifdef SKIP_ASM
struct sCam162138;
extern "C" void func_00161EF0(void* self, int v);
extern "C" void func_001621A8(sCam162138* self);
extern "C" void func_00162218(sCam162138* self);
int func_0011FE98(void*);

struct sCamVec4_161AB0
{
    float x, y, z, w;
} __attribute__((aligned(16)));

class cCamRider_161AB0
{
public:
    virtual void v01();
    virtual void v02();
    virtual sCamVec4_161AB0 getVelocity();
};

// PORT: VU0 macro-mode vector length; the PC port needs plain C.
static inline float vlength_161AB0(const sCamVec4_161AB0& v)
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

extern "C" void func_00161AB0(char* self)
{
    int mode = 0x3D;
    if (*(int*)(self + 0x1C) != mode && *(int*)(self + 0x18) != 0x4A)
        func_00161EF0(self, mode);
    *(int*)(self + 0x1C) = mode;
    float speed = vlength_161AB0((*(cCamRider_161AB0**)(self + 0x20))->getVelocity()) * 0.035999998450279236f;
    int boarding = func_0011FE98(*(void**)(*(char**)(self + 0x20) + 4)) == 5;
    if (*(int*)(self + 0x3C) == 0) {
        if (boarding) {
            *(int*)(self + 0x3C) = 1;
            func_001621A8((sCam162138*)self);
        }
    } else if (speed > 35.0f) {
        *(int*)(self + 0x3C) = 0;
        func_00162218((sCam162138*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161BB8);
#ifdef SKIP_ASM
struct sCam162060;
extern "C" void func_00162060(sCam162060* self, int mode, int arg, float blend);
extern int D_004A2A50;

class cCamAlgo_161BB8 {
public:
    char pad_0x00[0xC];
    int type;  // 0xC
    // vptr at 0x10
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

struct sAlgoNode_161BB8 {
    cCamAlgo_161BB8* algo;    // 0x0
    float weight;             // 0x4
    float rate;               // 0x8
    float blend;              // 0xC
    sAlgoNode_161BB8* prev;   // 0x10
    sAlgoNode_161BB8* next;   // 0x14
};

struct sAlgoList_161BB8 {
    sAlgoNode_161BB8* head;
    int count;
};

extern "C" sAlgoNode_161BB8* func_0015CA50(sAlgoList_161BB8* list, sAlgoNode_161BB8* n);

static inline float Approach_161BB8(float cur, float target, float rate)
{
    if (target + rate < cur)
        return cur - rate;
    if (cur < target - rate)
        return cur + rate;
    return target;
}

static inline float ApproachZero_161BB8(float cur, float rate)
{
    if (rate < cur)
        return cur - rate;
    if (cur < -rate)
        return cur + rate;
    return 0.0f;
}

static inline void Smooth_161BB8(sAlgoNode_161BB8* n, float u)
{
    float u2 = u * u;
    float s = u2 * 3.0f - (u2 + u2) * u;
    n->weight = u;
    if (s > 1.0f)
        s = 1.0f;
    n->blend = s;
}

static inline int InRace_161BB8(int* st)
{
    return *st && *st < 10;
}

extern "C" void func_00161BB8(char* self)
{
    if ((D_004A2A50 & 1) == 0) {
        func_00161AB0(self);
        sAlgoNode_161BB8* n = (*(sAlgoList_161BB8**)(self + 0x8))->head;
        n->algo->v09(0);
        float rate = n->rate;
        Smooth_161BB8(n, Approach_161BB8(n->weight, 1.0f, rate));
        n = n->next;
        while (n) {
            Smooth_161BB8(n, ApproachZero_161BB8(n->weight, rate));
            if (n->algo->type == 0x4A)
                n->weight = 0.0f;
            if (n->weight <= 0.0f || n->blend <= 0.0f) {
                n = func_0015CA50(*(sAlgoList_161BB8**)(self + 0x8), n);
            } else {
                n->algo->v09(1);
                n = n->next;
            }
        }
    }
    int* st = *(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int idle = InRace_161BB8(st) && st[0x484 / 4] == 0;
    if (idle)
        *(float*)(self + 0x38) = 0.0f;
    if (InRace_161BB8(st) && *(int*)(self + 0x2C) == 0x5D && *(int*)(self + 0x18) != *(int*)(self + 0x24)) {
        *(float*)(self + 0x38) += 0.01666666753590107f;
        if (*(float*)(self + 0x38) > 10.0f) {
            *(float*)(self + 0x38) = 0.0f;
            func_00162060((sCam162060*)self, *(int*)(self + 0x24), 0, 1.0f);
        }
    } else {
        *(float*)(self + 0x38) = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161E58);
#ifdef SKIP_ASM
extern "C" void cCameraAlgoList_insert(void* list, void* algo, int b, float w);
extern "C" void func_0015CB08(void* list);

extern "C" void func_00161E58(void* self, void* algo, float w)
{
    *(int*)((char*)self + 0x18) = *(int*)((char*)algo + 0xC);
    void* list = *(void**)((char*)self + 0x8);
    if (*(int*)((char*)list + 0x4) == 0) {
        cCameraAlgoList_insert(list, algo, 1, 1.0f);
        return;
    }
    if (w == 1.0f) {
        func_0015CB08(*(void**)((char*)self + 0x8));
    }
    cCameraAlgoList_insert(*(void**)((char*)self + 0x8), algo, 1, w);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161EF0);
#ifdef SKIP_ASM
extern int D_004A4DD0[2];
extern "C" void* func_0015D050(void*, int, int);

extern "C" void func_00161EF0(void* self, int v)
{
    *(int*)((char*)self + 0x24) = v;
    D_004A4DD0[*(int*)(*(char**)(*(char**)((char*)self + 0x20) + 0x4) + 0x870)] = v;
    if ((*(int*)((char*)self + 0x30) & 7) == 0) {
        func_0015D050(self, v, 0);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161F50);
#ifdef SKIP_ASM
struct sCam161F50 {
    char pad_0x00[0x24];
    int field_0x24;
    int field_0x28;
    int pad_0x2C;
    unsigned int b0 : 1; // 0x30
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int rest : 29;
    int field_0x34;
};

extern "C" void* func_0015D050(void*, int, int);

extern "C" void func_00161F50(sCam161F50* self)
{
    int mode;
    self->b1 = 0;
    self->b0 = 0;
    mode = 0x42;
    if (!self->b2) {
        mode = self->field_0x24;
    }
    func_0015D050(self, mode, self->field_0x34);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00161FA0);
#ifdef SKIP_ASM
extern "C" void func_00161FA0(void* self, int mode)
{
    int flags = *(int*)((char*)self + 0x30) | 2;
    *(int*)((char*)self + 0x30) = flags;
    if (mode == 0x4C) {
        mode = *(int*)((char*)self + 0x24);
        func_0015D050(self, mode, 0);
    } else if (mode == 0x5D) {
        if (flags & 1)
            func_0015D050(self, *(int*)((char*)self + 0x28), *(int*)((char*)self + 0x34));
        else if (flags & 4)
            func_0015D050(self, 0x42, 0);
        else
            func_0015D050(self, *(int*)((char*)self + 0x24), 0);
    } else {
        func_0015D050(self, mode, 0);
    }
    *(int*)((char*)self + 0x2C) = mode;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162060);
#ifdef SKIP_ASM
struct sCam162060 {
    char pad_0x00[0x24];
    int field_0x24;
    int field_0x28;
    int field_0x2C;
    unsigned int b0 : 1; // 0x30
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int rest : 29;
    int field_0x34;
};

extern "C" void* cChaseCameraController_createChaseAlgorithmBlend(void*, int, int, float);

extern "C" void func_00162060(sCam162060* self, int mode, int arg, float blend)
{
    if (mode == 0x4C) {
        self->b0 = 0;
        mode = self->field_0x24;
    } else {
        self->field_0x28 = mode;
        self->b0 = 1;
        self->field_0x34 = arg;
    }
    int ok = !self->b1 ? 1 : self->field_0x2C == 0x5D;
    if (ok) {
        cChaseCameraController_createChaseAlgorithmBlend(self, mode, arg, blend);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001620D0);
#ifdef SKIP_ASM
struct sCam1620D0 {
    char pad_0x00[0x24];
    int field_0x24;
    int field_0x28;
    int field_0x2C;
    unsigned int b0 : 1; // 0x30
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int rest : 29;
    int field_0x34;
};

extern "C" void func_0015DAC0();
extern "C" void* cChaseCameraController_createChaseAlgorithmBlend(void*, int, int, float);

extern "C" void func_001620D0(sCam1620D0* self)
{
    int mode = self->field_0x2C;
    self->b0 = 0;
    if (mode == 0x5D)
        mode = self->field_0x24;
    func_0015DAC0();
    cChaseCameraController_createChaseAlgorithmBlend(self, mode, 0, 1.0f);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162138);
#ifdef SKIP_ASM
struct sCam162138 {
    char pad_0x00[0x24];
    int field_0x24;
    int field_0x28;
    int pad_0x2C;
    unsigned int b0 : 1; // 0x30
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int rest : 29;
    int field_0x34;
    int pad_0x38;
    int field_0x3C;
    int field_0x40;
};


extern "C" void func_00162138(sCam162138* self)
{
    self->b1 = 0;
    self->b0 = 0;
    self->b2 = 0;
    self->field_0x28 = self->field_0x24;
    self->field_0x3C = 0;
    self->field_0x40 = 0;
    self->field_0x34 = 0;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162170);
#ifdef SKIP_ASM
extern "C" void* func_0015D050(void*, int, int);

extern "C" void* func_00162170(sCam162138* self)
{
    func_00162138(self);
    return func_0015D050(self, self->field_0x24, 0);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001621A8);
#ifdef SKIP_ASM
int func_0011FE98(void*);

extern "C" void func_001621A8(sCam162138* self)
{
    self->b2 = 1;
    if (!self->b0 && !self->b1) {
        float t = func_0011FE98(*(void**)(*(char**)((char*)self + 0x20) + 4)) == 5 ? 1.2000000476837158f : 0.6000000238418579f;
        cChaseCameraController_createChaseAlgorithmBlend(self, 0x42, 0, t * 0.01666666753590107f);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162218);
#ifdef SKIP_ASM
extern "C" void func_00162218(sCam162138* self)
{
    self->b2 = 0;
    if (!self->b0 && !self->b1) {
        cChaseCameraController_createChaseAlgorithmBlend(self, self->field_0x24, 0, 0.0066666672937572f);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162258);
#ifdef SKIP_ASM
extern "C" void func_00162258(sCam162138* self)
{
    if (!self->b0) {
        cChaseCameraController_createChaseAlgorithmBlend(self, 0x44, 0, 0.016793444752693176f);
    }
}
#endif

extern "C" void* func_0015D050(void*, int, int);

//100%
INCLUDE_ASM("camera/camera", func_00162290__FPv);
#ifdef SKIP_ASM
void* func_00162290(void* self)
{
    return func_0015D050(self, *(int*)((char*)self + 0x24), 0);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001622B0);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
extern void* D_0045BC38[];
extern "C" float func_00167E30(void* self);

extern "C" void* func_001622B0(void* self)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    *(float*)self = func_00167E30(self);
    *(int*)((char*)self + 0xC) = 0x4E;
    *(float*)((char*)self + 0x4) = 10.0f;
    *(float*)((char*)self + 0x8) = 30000.0f;
    *(void***)((char*)self + 0x10) = D_0045BC38;
    *(int*)((char*)self + 0xC) = 0x53;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162310__FPvi);
#ifdef SKIP_ASM
void func_00162310(void* self, int val)
{
    *(int*)((char*)self + 0x30) = val;
}
#endif

INCLUDE_ASM("camera/camera", func_00162318);

//100%
INCLUDE_ASM("camera/camera", func_00162458);
#ifdef SKIP_ASM
extern void* D_0045BBC0[];
extern void* D_0045BDE0[];

// PORT: func_00162458 is the base deleting dtor (self, flags); the unit declares it with one arg
// (func_00162458_dtor is declared earlier in the unit with this asm label).
void func_00162458_dtor(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BBC0;
    func_0031D618((char*)self + 0x334, 2);
    func_0031D618((char*)self + 0x328, 2);
    func_0031D618((char*)self + 0x31C, 2);
    func_0031D618((char*)self + 0x310, 2);
    func_0031D618((char*)self + 0x304, 2);
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001624E8);
#ifdef SKIP_ASM
struct sCamVE1624E8 {
    short delta;
    short index;
    void (*fn)(void*);
};
struct sCamVE1624E8i {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001624E8(void* self, int a1)
{
    if (*(int*)((char*)self + 0x2F0) != 0) {
        sCamVE1624E8* vt = *(sCamVE1624E8**)((char*)self + 0x10);
        vt[4].fn((char*)self + vt[4].delta);
    }
    sCamVE1624E8* vt = *(sCamVE1624E8**)((char*)self + 0x10);
    vt[5].fn((char*)self + vt[5].delta);
    sCamVE1624E8i* vt2 = *(sCamVE1624E8i**)((char*)self + 0x10);
    vt2[8].fn((char*)self + vt2[8].delta, a1);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162560);
#ifdef SKIP_ASM
extern "C" void func_00162560(void) {

}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162568);
#ifdef SKIP_ASM
int func_0011FE98(void*);
extern sVec_001607E0 D_004FF120_v162568 __asm__("D_004FF120");

struct sVEi_162568 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sVEf_162568 {
    short delta;
    short index;
    float (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec_001607E0 cmSub_162568(const sVec_001607E0& a, const sVec_001607E0& b)
{
    sVec_001607E0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (dot product).
static inline float cmDot_162568(const sVec_001607E0& a, const sVec_001607E0& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (v / |v| via vrsqrt).
static inline sVec_001607E0 cmNormalized_162568(const sVec_001607E0& v)
{
    sVec_001607E0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

static inline int cmGetI_162568(char* self, int slot)
{
    char* o = *(char**)(self + 0x30);
    sVEi_162568* e = &(*(sVEi_162568**)o)[slot];
    return e->fn(o + e->delta);
}

static inline float cmGetF_162568(char* self, int slot)
{
    char* o = *(char**)(self + 0x30);
    sVEf_162568* e = &(*(sVEf_162568**)o)[slot];
    return e->fn(o + e->delta);
}

static inline sVec_001607E0 cmLerp_162568(const sVec_001607E0& a, const sVec_001607E0& b, float t)
{
    sVec_001607E0 r = cmAdd_001607E0(cmScale_001607E0(a, t), cmScale_001607E0(b, 1.0f - t));
    return r;
}

static inline sVec_001607E0 cmGetR_162568(char* self, int slot)
{
    char* o = *(char**)(self + 0x30);
    sVEv_001607E0* e = &(*(sVEv_001607E0**)o)[slot];
    sVec_001607E0 r = e->fn(o + e->delta);
    return r;
}

static inline void SetFrame_162568(char* out, const sVec_001607E0& pos, sVec_001607E0 dir, sVec_001607E0 vel)
{
    *(sVec_001607E0*)(out + 0x0) = pos;
    *(sVec_001607E0*)(out + 0x10) = vel;
    *(sVec_001607E0*)(out + 0x20) = dir;
}

extern "C" void func_00162568_impl(char* self, char* out, float a, float b, float c, float d, float e, float f,
                                   float g, float h) __asm__("func_00162568");
extern "C" void func_00162568_impl(char* self, char* out, float a, float b, float c, float d, float e, float f,
                                   float g, float h)
{
    sVec_001607E0 v = cmGet_001607E0(self, 3);
    int mode = func_0011FE98(*(void**)(*(char**)(self + 0x30) + 4));
    if (cmLength_001607E0(v) < 27.77777862548828f) {
        v = *(sVec_001607E0*)(self + 0x1B0);
    }
    *(sVec_001607E0*)(self + 0x1B0) = v;
    sVec_001607E0 w = v;
    w.z = 0.0f;
    sVec_001607E0 dz = cmSub_162568(v, w);
    sVec_001607E0 n = cmDot_162568(v, v) > 0.0f ? cmNormalized_162568(v) : D_004FF120_v162568;
    int k = cmGetI_162568(self, 20);
    float lo, hi, t0, t1;
    if ((unsigned)(k - 2) < 2 || k == 13) {
        lo = e;
        hi = f;
        t0 = g;
        t1 = h;
    } else {
        lo = a;
        hi = b;
        t0 = c;
        t1 = d;
    }
    float x = __builtin_fabsf(n.z);
    float frac;
    if (x >= t0) {
        if (x <= t1) {
            frac = (x - t0) / (t1 - t0);
        } else {
            frac = 1.0f;
        }
    } else {
        frac = 0.0f;
    }
    float r = lo + (hi - lo) * frac;
    if (mode == 1) {
        if (cmLength_001607E0(w) < 27.77777862548828f) {
            w = *(sVec_001607E0*)(self + 0x100);
        }
    }
    sVec_001607E0 nf = cmLerp_162568(*(sVec_001607E0*)(self + 0x100), w, r);
    *(sVec_001607E0*)(self + 0x100) = nf;
    sVec_001607E0 p = cmAdd_001607E0(nf, dz);
    *(int*)(out + 0x64) = mode == 4;
    *(int*)(out + 0x58) = mode == 2;
    *(int*)(out + 0x5C) = mode == 5;
    *(int*)(out + 0x60) = mode == 1;
    *(int*)(out + 0x40) = mode;
    *(float*)(out + 0x4C) = cmGetF_162568(self, 17);
    *(float*)(out + 0x54) = cmGetF_162568(self, 18);
    SetFrame_162568(out, *(sVec_001607E0*)(self + 0x40), p, cmGetR_162568(self, 1));
    *(float*)(out + 0x44) = cmLength_001607E0(*(sVec_001607E0*)(out + 0x20));
    float s;
    if (*(float*)(out + 0x4C) > 0.0f) {
        s = (*(float*)(out + 0x4C) + 1.0f) * 0.5f;
    } else {
        s = 0.0f;
    }
    *(float*)(out + 0x50) = s;
    *(float*)(self + 0x2F4) = *(float*)(out + 0x4C);
    *(float*)(self + 0x2F8) = *(float*)(out + 0x50);
    *(int*)(self + 0x2FC) = *(int*)(out + 0x5C);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162998);
#ifdef SKIP_ASM
extern "C" void func_00162998(void* self, void* obj)
{
    float v;
    if (*(int*)((char*)obj + 0x5C) == 0) {
        if (*(int*)((char*)self + 0x2C0) < 0x334)
            *(int*)((char*)self + 0x2C0) = *(int*)((char*)self + 0x2C0) + 1;
        int t = *(int*)((char*)self + 0x2C0);
        v = 1.0f;
        if (t >= 0x78)
            v = 1.0f - ((float)t - 120.0f) * 0.0014285714132711291f;
        if (v < 0.0f)
            v = 0.0f;
    } else {
        *(int*)((char*)self + 0x2C0) = 0;
        v = 1.0f;
    }
    *(float*)((char*)obj + 0x48) = v;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162A20);
#ifdef SKIP_ASM
extern "C" int func_001298C8();

struct sVec4_162A20
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVEntry_162A20 { short delta; short index; sVec4_162A20 (*fn)(void*); };

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_162A20(const sVec4_162A20& v)
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

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void DivEq_162A20(sVec4_162A20& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

static inline void Normalize_162A20(sVec4_162A20& v)
{
    DivEq_162A20(v, Length_162A20(v));
}

extern "C" void func_00162A20(char* self, char* trig)
{
    if (*(int*)(trig + 0x60))
    {
        if (*(int*)(self + 0x2D4) == 0)
        {
            sVec4_162A20 dir = *(sVec4_162A20*)(trig + 0x20);
            if (*(float*)(trig + 0x44) > 0.0f)
            {
                Normalize_162A20(dir);
                if (dir.z > 0.8500000238418579f)
                {
                    void* obj = *(void**)(self + 0x30);
                    sVEntry_162A20* vt = *(sVEntry_162A20**)obj;
                    sVec4_162A20 v = vt[9].fn((char*)obj + vt[9].delta);
                    if (v.z < 0.10000000149011612f)
                    {
                        *(float*)(self + 0x22C) = 0.0f;
                        *(int*)(self + 0x2D0) = 1;
                    }
                }
            }
            *(int*)(self + 0x2D4) = 1;
            int late = func_001298C8() - *(int*)(self + 0x2CC) >= 31;
            if (*(int*)(self + 0x2E0) == 0 && late)
                *(int*)(self + 0x2C4) = 15;
        }
        else
        {
            *(int*)(self + 0x2CC) = func_001298C8();
            return;
        }
    }
    else if (*(int*)(self + 0x2D4))
    {
        *(int*)(self + 0x2D4) = 0;
        *(int*)(self + 0x2D0) = 0;
        *(int*)(self + 0x2D8) = 0;
    }
    if (*(int*)(trig + 0x60))
        *(int*)(self + 0x2CC) = func_001298C8();
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00162B80);
#ifdef SKIP_ASM
extern "C" cQuad128 func_00162B80(void* self, void* a1)
{
    cQuad128 v = *(cQuad128*)((char*)a1 + 0x10);
    *(cQuad128*)((char*)self + 0x20) = v;
    return v;
}
#endif

INCLUDE_ASM("camera/camera", func_00162B90);

//100%
INCLUDE_ASM("camera/camera", func_00162C78);
#ifdef SKIP_ASM
struct sV_162C78 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVE_162C78 {
    short delta;
    short index;
    sV_162C78 (*fn)(void*);
};

struct sInfo_162C78 {
    char pad0[0x20];
    sV_162C78 dir;      // 0x20
    sV_162C78 out;      // 0x30
    char pad40[0x4];
    float speed;        // 0x44
};

struct sHist_162C78 {
    float a[5];         // 0x00
    float b[5];         // 0x14
    float c[5];         // 0x28
    int idx;            // 0x3C
    float k0;           // 0x40
    float k1;           // 0x44
    float k2;           // 0x48
};

extern "C" float func_0031C128(float x);

// PORT: PS2-only VU0 inline asm (dot product).
static inline float Dot_162C78(const sV_162C78& a, const sV_162C78& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV_162C78 Scale_162C78(const sV_162C78& v, float s)
{
    sV_162C78 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV_162C78 Add_162C78(const sV_162C78& a, const sV_162C78& b)
{
    sV_162C78 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_162C78(const sV_162C78& v)
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

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void DivEq_162C78(sV_162C78& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

static inline void Normalize_162C78(sV_162C78& v)
{
    DivEq_162C78(v, Length_162C78(v));
}

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_162C78(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ `<?` / `>?` operators.
static inline float Clamp_162C78(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

static inline sV_162C78 Get_162C78(char* self, int slot)
{
    char* o = *(char**)(self + 0x30);
    sVE_162C78* e = &(*(sVE_162C78**)o)[slot];
    return e->fn(o + e->delta);
}

static inline sV_162C78 Lerp_162C78(const sV_162C78& p, const sV_162C78& q, float t)
{
    return Add_162C78(Scale_162C78(p, t), Scale_162C78(q, 1.0f - t));
}

static inline void LerpTo_162C78(sV_162C78& out, const sV_162C78& p, const sV_162C78& q, float t)
{
    out = Add_162C78(Scale_162C78(p, t), Scale_162C78(q, 1.0f - t));
}

extern "C" void func_00162C78_impl(char* self, sInfo_162C78* info) __asm__("func_00162C78");
extern "C" void func_00162C78_impl(char* self, sInfo_162C78* info)
{
    sV_162C78 n;
    if (info->speed > 27.77777862548828f) {
        sV_162C78 v = Get_162C78(self, 3);
        if (Dot_162C78(v, v) < 1.0f) {
            v = *(sV_162C78*)(self + 0x1C0);
        }
        *(sV_162C78*)(self + 0x1C0) = v;
        float ang;
        float len = Sqrt_162C78(Dot_162C78(*(sV_162C78*)(self + 0x80), *(sV_162C78*)(self + 0x80)) *
                                Dot_162C78(*(sV_162C78*)(self + 0x1C0), *(sV_162C78*)(self + 0x1C0)));
        if (len < 0.0010000000474974513f) {
            ang = 0.0f;
        } else {
            ang = 1.5707963705062866f -
                  func_0031C128(Clamp_162C78(
                      Dot_162C78(*(sV_162C78*)(self + 0x80), *(sV_162C78*)(self + 0x1C0)) / len, -1.0f, 1.0f));
        }
        ang = (ang - 0.19082477688789368f) >? 0.0f;
        float prev = ((sHist_162C78*)(self + 0x340))->b[(((sHist_162C78*)(self + 0x340))->idx + 4) % 5];
        float d = ang - ((sHist_162C78*)(self + 0x340))->b[(((sHist_162C78*)(self + 0x340))->idx + 4) % 5];
        sHist_162C78* h = (sHist_162C78*)(self + 0x340);
        float sum = 0.0f;
        for (int i = 0; i < 5; i++) {
            sum += h->c[i];
        }
        int p2 = (h->idx + 4) % 5;
        float val = prev + d * h->k0 + sum * h->k1 + (h->a[p2] - ang) * h->k2;
        h->a[h->idx] = ang;
        h->b[h->idx] = val;
        h->c[h->idx] = ang - val;
        float s = (1.0f - ((val * 2.5214130878448486f) <? 1.0f >? 0.0f)) * 0.03946405649185181f +
                  0.95552659034729f;
        h->idx = (h->idx + 1) % 5;
        if ((unsigned)(*(int*)(*(char**)(*(char**)(self + 0x30) + 4) + 0x434) - 0xB) < 3) {
            s = Sqrt_162C78(Sqrt_162C78(s));
        }
        LerpTo_162C78(n, *(sV_162C78*)(self + 0x80), Scale_162C78(info->dir, 1.0f / info->speed), s);
        *(sV_162C78*)(self + 0x80) = n;
    } else {
        n = *(sV_162C78*)(self + 0x80);
    }
    Normalize_162C78(n);
    info->out = n;
}
#endif

INCLUDE_ASM("camera/camera", func_00163010);

INCLUDE_ASM("camera/camera", func_00163158);

INCLUDE_ASM("camera/camera", func_00163270);

//100%
INCLUDE_ASM("camera/camera", func_001633B0);
#ifdef SKIP_ASM
extern "C" void* func_00168150(void* self);
extern "C" void func_001633B0(void* self, void* obj, float a, float b, float c, float d)
{
    float k = *(float*)((char*)obj + 0x44);
    float x = a * (k * 1.0000000116860974e-07f) * k + 1.0f + (c - 1.0f) * *(float*)((char*)obj + 0x4C);
    int mode = *(int*)((char*)obj + 0x40);
    if (mode == 1)
        d = 1.0f;
    else if (mode != 0)
        d = 0.9990000128746033f;
    *(float*)((char*)self + 0x1DC) = d * *(float*)((char*)self + 0x1DC) + (1.0f - d) * x;
    *(float*)self = b * 0.7853981852531433f * *(float*)((char*)self + 0x1DC);
    func_00168150(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00163450);
#ifdef SKIP_ASM
extern "C" void* func_00168150(void* self);

struct sVec4_163450
{
    float v[4];
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_163450 Sub_163450(const sVec4_163450& a, const sVec4_163450& b)
{
    sVec4_163450 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_163450 Add_163450(const sVec4_163450& a, const sVec4_163450& b)
{
    sVec4_163450 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_163450 Scale_163450(const sVec4_163450& v, float s)
{
    sVec4_163450 r;
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

extern "C" void func_00163450(char* self, char* trig, float a, float b, float c, float d, float e, float f, float g)
{
    if (*(int*)(trig + 0x5C))
    {
        sVec4_163450 t = Sub_163450(*(sVec4_163450*)(self + 0x20), *(sVec4_163450*)(self + 0x40));
        *(float*)(self + 0x1E0) = 0.0f;
        *(sVec4_163450*)(self + 0xB0) = t;
    }
    else if (*(float*)(self + 0x1E0) < 5.0f)
    {
        *(float*)(self + 0x1E0) += 0.01666666753590107f;
        if (*(float*)(self + 0x1E0) < d)
        {
            float u = *(float*)(self + 0x1E0) / d;
            float u2 = u * u;
            float s = u2 * 3.0f - (u2 + u2) * u;
            if (s > 1.0f)
                s = 1.0f;
            sVec4_163450 t = Add_163450(Scale_163450(Sub_163450(*(sVec4_163450*)(self + 0x20), *(sVec4_163450*)(self + 0xB0)), 1.0f - s),
                                        Scale_163450(*(sVec4_163450*)(self + 0x40), s));
            *(sVec4_163450*)(self + 0x40) = t;
        }
    }
    *(sVec4_163450*)(self + 0xA0) = *(sVec4_163450*)(trig + 0x10);
    float z;
    if (*(int*)(trig + 0x5C))
        z = f * *(float*)(self + 0x2B8) + (1.0f - f) * e;
    else
        z = g * *(float*)(self + 0x2B8);
    *(float*)(self + 0x2B8) = z;
    *(float*)(self + 0x48) += z;
    func_00168150(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001635C0);
#ifdef SKIP_ASM
extern "C" void func_001635C0(void) {

}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001635C8);
#ifdef SKIP_ASM
extern "C" float func_001635C8(void) {
    return 0.0f;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001635D8);
#ifdef SKIP_ASM
extern "C" int func_001635D8(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001635E0);
#ifdef SKIP_ASM
extern "C" int func_001635E0(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001635E8);
#ifdef SKIP_ASM
extern int D_004A4DD8;

extern "C" int func_001635E8(void) {
    return D_004A4DD8;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001635F0);
#ifdef SKIP_ASM
extern int D_004A4DDC;

extern "C" int func_001635F0(void) {
    return D_004A4DDC;
}
#endif

INCLUDE_ASM("camera/camera", func_001635F8);

INCLUDE_ASM("camera/camera", func_001641C0);

//100%
INCLUDE_ASM("camera/camera", func_001643A8);
#ifdef SKIP_ASM
struct sVec_1643A8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec_1643A8 Sub_1643A8(const sVec_1643A8& a, const sVec_1643A8& b)
{
    sVec_1643A8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec_1643A8 Add_1643A8(const sVec_1643A8& a, const sVec_1643A8& b)
{
    sVec_1643A8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec_1643A8 Scale_1643A8(const sVec_1643A8& v, float s)
{
    sVec_1643A8 r;
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

// PORT: PS2-only VU0 inline asm (in-place v *= s).
static inline void ScaleEq_1643A8(sVec_1643A8& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "lqc2      $vf4, %0\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_1643A8(const sVec_1643A8& v)
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

#define S_1643A8 ((char*)self)
#define I_1643A8 ((char*)info)
extern "C" void func_001643A8(void* self, void* info, float a, float b, float c)
{
    int trig = *(float*)(I_1643A8 + 0x44) * 0.035999998450279236f < a && *(int*)(I_1643A8 + 0x60) == 0 &&
               *(int*)(I_1643A8 + 0x5C) == 0;
    if (*(int*)(S_1643A8 + 0x300) == 3 && trig) {
        *(int*)(S_1643A8 + 0x300) = 0;
        *(float*)(S_1643A8 + 0x248) = 0.0f;
        *(sVec_1643A8*)(S_1643A8 + 0x1A0) = Sub_1643A8(*(sVec_1643A8*)(S_1643A8 + 0x20), *(sVec_1643A8*)(S_1643A8 + 0x40));
    } else if (*(int*)(S_1643A8 + 0x300) == 2 && !trig) {
        *(int*)(S_1643A8 + 0x300) = 1;
        *(float*)(S_1643A8 + 0x248) = 1.0f;
    } else if (*(int*)(S_1643A8 + 0x300) == 0 && !trig) {
        *(int*)(S_1643A8 + 0x300) = 1;
    } else if (*(int*)(S_1643A8 + 0x300) == 1 && trig) {
        *(int*)(S_1643A8 + 0x300) = 0;
    }
    if (*(int*)(S_1643A8 + 0x300) == 0) {
        *(float*)(S_1643A8 + 0x248) = (*(float*)(S_1643A8 + 0x248) + 0.01666666753590107f / b) <? 1.0f;
        if (*(float*)(S_1643A8 + 0x248) == 1.0f)
            *(int*)(S_1643A8 + 0x300) = 2;
    } else if (*(int*)(S_1643A8 + 0x300) == 1) {
        *(float*)(S_1643A8 + 0x248) = (*(float*)(S_1643A8 + 0x248) - 0.01666666753590107f / c) >? 0.0f;
        if (*(float*)(S_1643A8 + 0x248) == 0.0f)
            *(int*)(S_1643A8 + 0x300) = 3;
    }
    if (*(int*)(S_1643A8 + 0x300) != 3) {
        float t = *(float*)(S_1643A8 + 0x248);
        float t2 = t * t;
        float s = t2 * 3.0f - (t2 + t2) * t;
        if (s > 1.0f)
            s = 1.0f;
        sVec_1643A8 d = Sub_1643A8(*(sVec_1643A8*)(S_1643A8 + 0x20), *(sVec_1643A8*)(S_1643A8 + 0x40));
        sVec_1643A8 e = Add_1643A8(Scale_1643A8(d, 1.0f - s), Scale_1643A8(*(sVec_1643A8*)(S_1643A8 + 0x1A0), s));
        float l1 = Length_1643A8(d);
        float l2 = Length_1643A8(e);
        ScaleEq_1643A8(e, (l1 * 0.5f + l2 * 0.5f) / l2);
        *(sVec_1643A8*)(S_1643A8 + 0x20) =
            Add_1643A8(Scale_1643A8(*(sVec_1643A8*)(S_1643A8 + 0x20), 1.0f - s), Scale_1643A8(*(sVec_1643A8*)(I_1643A8 + 0x10), s));
        *(sVec_1643A8*)(S_1643A8 + 0x40) = Sub_1643A8(*(sVec_1643A8*)(S_1643A8 + 0x20), e);
    }
    func_00168150(self);
}
#undef S_1643A8
#undef I_1643A8
#endif

INCLUDE_ASM("camera/camera", func_001646A0);

//100%
INCLUDE_ASM("camera/camera", func_00164868);
#ifdef SKIP_ASM
extern "C" int func_00164868(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00164870);
#ifdef SKIP_ASM
extern int D_004A4DE0;

extern "C" int func_00164870(void) {
    return D_004A4DE0;
}
#endif

INCLUDE_ASM("camera/camera", func_00164878);

//100%
INCLUDE_ASM("camera/camera", func_00165540);
#ifdef SKIP_ASM
extern "C" void* func_00168150(void* self);
extern "C" void func_0031BE50(float* sout, float* cout, float x);

struct sVec4_165540
{
    float x, y, z, w;
    sVec4_165540() {}
    sVec4_165540(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

extern sVec4_165540 D_004FF140_v165540 __asm__("D_004FF140");
extern sVec4_165540 D_004FF160_v165540 __asm__("D_004FF160");

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_165540 Sub_165540(const sVec4_165540& a, const sVec4_165540& b)
{
    sVec4_165540 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_165540(const sVec4_165540& v)
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

// PORT: PS2-only VU0 inline asm (in-place v *= s).
static inline void ScaleEq_165540(sVec4_165540& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "lqc2      $vf4, %0\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (rotate v by quaternion q).
static inline sVec4_165540 Rot_165540(const sVec4_165540& q, const sVec4_165540& v)
{
    sVec4_165540 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsub.w    $vf8, $vf8, $vf8\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vopmsub.xyz $vf7, $vf6, $vf4\n"
        "vmulaw.xyz ACC, $vf5, $vf0w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf7, $vf0w\n"
        "vmaddw.xyz $vf8, $vf7, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(r)
        : "m"(q), "m"(v)
        : "memory");
    return r;
}

static inline sVec4_165540 AxisAngle_165540(const sVec4_165540& axis, float ang)
{
    float s, c;
    func_0031BE50(&s, &c, ang * 0.5f);
    sVec4_165540 r(s * axis.x, s * axis.y, s * axis.z, c);
    return r;
}

extern "C" void func_00165540(char* self, float ang)
{
    sVec4_165540 off = Sub_165540(*(sVec4_165540*)(self + 0x20), *(sVec4_165540*)(self + 0x40));
    sVec4_165540 dir = D_004FF140_v165540;
    float z = off.z;
    off.z = 0.0f;
    float len = Length_165540(off);
    if (off.z < len)
    {
        ScaleEq_165540(dir, len);
        dir.z = z;
        sVec4_165540 q = AxisAngle_165540(D_004FF160_v165540, ang);
        sVec4_165540 rd = Rot_165540(q, dir);
        sVec4_165540 t = Sub_165540(*(sVec4_165540*)(self + 0x20), rd);
        *(sVec4_165540*)(self + 0x40) = t;
    }
    func_00168150(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001656B0);
#ifdef SKIP_ASM
// Uniform float in [0, 1) built from the random mantissa bits.
static inline float randf_1656B0()
{
    union {
        int i;
        float f;
    } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

static inline float RandRange_1656B0(float lo, float hi)
{
    return lo + (hi - lo) * randf_1656B0();
}

extern "C" void func_001656B0(char* self, float base, float spread, float r)
{
    *(float*)(self + 0x254) = base + spread * randf_1656B0();
    *(float*)(self + 0x258) = base + spread * randf_1656B0();
    *(float*)(self + 0x25C) = base + spread * randf_1656B0();
    float rz = r * 1.600000023841858f;
    *(float*)(self + 0x260) = RandRange_1656B0(-r, r);
    *(float*)(self + 0x264) = RandRange_1656B0(-r, r);
    *(float*)(self + 0x268) = RandRange_1656B0(-rz, rz);
    *(float*)(self + 0x26C) = 0.0f;
    *(float*)(self + 0x270) = 0.0f;
    *(float*)(self + 0x274) = 0.0f;
    *(float*)(self + 0x278) = 0.0f;
    *(float*)(self + 0x27C) = 0.0f;
    *(float*)(self + 0x280) = 0.0f;
    base *= 0.5f;
    spread *= 0.5f;
    r *= 0.5f;
    rz *= 0.5f;
    *(float*)(self + 0x284) = base + spread * randf_1656B0();
    *(float*)(self + 0x288) = base + spread * randf_1656B0();
    *(float*)(self + 0x28C) = base + spread * randf_1656B0();
    *(float*)(self + 0x290) = RandRange_1656B0(-r, r);
    *(float*)(self + 0x294) = RandRange_1656B0(-r, r);
    *(float*)(self + 0x298) = RandRange_1656B0(-rz, rz);
    *(float*)(self + 0x29C) = 0.0f;
    *(float*)(self + 0x2A0) = 0.0f;
    *(float*)(self + 0x2A4) = 0.0f;
    *(float*)(self + 0x2A8) = 0.0f;
    *(float*)(self + 0x2AC) = 0.0f;
    *(float*)(self + 0x2B0) = 0.0f;
    *(int*)(self + 0x2EC) = 0;
    *(float*)(self + 0x2B4) = 0.0f;
}
#endif

INCLUDE_ASM("camera/camera", func_00165938);

//100%
INCLUDE_ASM("camera/camera", func_00166228);
#ifdef SKIP_ASM
struct sCamTarget166228 {
    float x, y, z, w;
    int valid; // 0x10
};

struct sCamVE166228 {
    short delta;
    short index;
    void (*fn)(void*, sCamTarget166228*);
};

extern "C" void func_00166640(void* self, int a1);
extern "C" void func_001662A0(void* self, float x, float y, float z, float w);
void* func_00166530(void* self);
extern "C" void func_00166F90(void* self);

extern "C" void func_00166228(void* self)
{
    sCamTarget166228 t;
    sCamVE166228* vt = *(sCamVE166228**)((char*)self + 0x10);
    vt[7].fn((char*)self + vt[7].delta, &t);
    func_00166640(self, 0);
    if (t.valid != 0)
        func_001662A0(self, t.x, t.y, t.z, t.w);
    func_00166530(self);
    func_00166F90(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001662A0);
#ifdef SKIP_ASM
extern "C" float func_0031C128(float x);

struct sVec_1662A0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVEv_1662A0 {
    short delta;
    short index;
    sVec_1662A0 (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec_1662A0 Sub_1662A0(const sVec_1662A0& a, const sVec_1662A0& b)
{
    sVec_1662A0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec_1662A0 Add_1662A0(const sVec_1662A0& a, const sVec_1662A0& b)
{
    sVec_1662A0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec_1662A0 Scale_1662A0(const sVec_1662A0& v, float s)
{
    sVec_1662A0 r;
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_1662A0(const sVec_1662A0& a, const sVec_1662A0& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2 sqrt.s asm helper; use sqrtf on PC.
static inline float Sqrt_1662A0(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline float Clamp_1662A0(float v, float lo, float hi)
{
    if (v >= lo)
        return v <? hi;
    return lo;
}

static inline float Angle_1662A0(const sVec_1662A0& a, const sVec_1662A0& b)
{
    float l = Sqrt_1662A0(Dot_1662A0(a, a) * Dot_1662A0(b, b));
    if (l < 0.0010000000474974513f)
        return 0.0f;
    return 1.5707963705062866f - func_0031C128(Clamp_1662A0(Dot_1662A0(a, b) / l, -1.0f, 1.0f));
}

static inline sVec_1662A0 Get_1662A0(char* self, int slot)
{
    char* o = *(char**)(self + 0x30);
    sVEv_1662A0* e = &(*(sVEv_1662A0**)o)[slot];
    return e->fn(o + e->delta);
}

#define S_1662A0 ((char*)self)
extern "C" void func_001662A0(void* self, float x, float y, float z, float w)
{
    float k, ang;
    int up = *(float*)(S_1662A0 + 0x1D8) < *(float*)(S_1662A0 + 0x54);
    if (up) {
        k = w;
        ang = y;
    } else {
        k = z;
        ang = x;
    }
    float old = *(float*)(S_1662A0 + 0x54);
    *(float*)(S_1662A0 + 0x54) = k * *(float*)(S_1662A0 + 0x1D8) + (1.0f - k) * old;
    sVec_1662A0 d = Sub_1662A0(*(sVec_1662A0*)(S_1662A0 + 0x20), *(sVec_1662A0*)(S_1662A0 + 0x40));
    sVec_1662A0 v;
    func_001668B8(self, &v);
    float a = Angle_1662A0(d, v);
    float lim = ang * 0.01745329424738884f;
    float k2;
    if (lim < a)
        k2 = k / (a / lim);
    else
        k2 = k;
    *(float*)(S_1662A0 + 0x1D8) = *(float*)(S_1662A0 + 0x54) = k2 * *(float*)(S_1662A0 + 0x1D8) + (1.0f - k2) * old;
    sVec_1662A0 v2;
    func_001668B8(self, &v2);
    sVec_1662A0 off = Sub_1662A0(Get_1662A0(S_1662A0, 1), *(sVec_1662A0*)(S_1662A0 + 0x40));
    float t = Dot_1662A0(off, v2) / Dot_1662A0(v2, v2);
    sVec_1662A0 sc = Scale_1662A0(v2, t);
    *(sVec_1662A0*)(S_1662A0 + 0x20) = Add_1662A0(*(sVec_1662A0*)(S_1662A0 + 0x40), sc);
    func_00168150(self);
}
#undef S_1662A0
#endif

extern "C" void* func_00168150(void* self);

//100%
INCLUDE_ASM("camera/camera", func_00166530__FPv);
#ifdef SKIP_ASM
void* func_00166530(void* self)
{
    return func_00168150(self);
}
#endif

INCLUDE_ASM("camera/camera", func_00166550);

INCLUDE_ASM("camera/camera", func_00166640);

//100%
INCLUDE_ASM("camera/camera", func_001668B8);
#ifdef SKIP_ASM
struct sV_1668B8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_1668B8 {
    float m[4][4];
} __attribute__((aligned(16)));


extern sM_1668B8 D_004FF1A0_1668B8 __asm__("D_004FF1A0");
extern sV_1668B8 D_004FF150_1668B8 __asm__("D_004FF150");
extern sV_1668B8 D_004FF160_v1668B8 __asm__("D_004FF160");
extern sV_1668B8 D_004FF130_v1668B8 __asm__("D_004FF130");
extern "C" void func_0031BE50(float* sout, float* cout, float x);

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_1668B8(sM_1668B8* dst, const sM_1668B8* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_1668B8(sM_1668B8* dst, const sM_1668B8* a, const sM_1668B8* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply in place, m = m * b).
static inline void vu0MulEqMtx_1668B8(sM_1668B8* m, const sM_1668B8* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_1668B8(sM_1668B8* m, const sV_1668B8& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

static inline void SinCos_1668B8(float* s, float* c, float angle)
{
    func_0031BE50(s, c, angle);
}

static inline void Rotate_1668B8(sM_1668B8* m, const sV_1668B8& axis, float angle)
{
    sM_1668B8 tm;
    vu0CopyMtx_1668B8(&tm, m);
    sV_1668B8 pos = *(sV_1668B8*)tm.m[3];
    *(sV_1668B8*)tm.m[3] = D_004FF130_v1668B8;
    float s;
    float c;
    SinCos_1668B8(&s, &c, angle);
    float one = 1.0f;
    float t = one - c;
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    m->m[0][0] = tx * x + c;
    m->m[1][0] = tx * y + sz;
    m->m[2][0] = tx * z - sy;
    m->m[0][1] = ty * x - sz;
    m->m[1][1] = ty * y + c;
    m->m[2][1] = ty * z + sx;
    m->m[0][2] = tz * x + sy;
    m->m[1][2] = tz * y - sx;
    m->m[2][2] = tz * z + c;
    m->m[3][0] = 0.0f;
    m->m[3][1] = 0.0f;
    m->m[3][2] = 0.0f;
    m->m[3][3] = one;
    m->m[0][3] = 0.0f;
    m->m[1][3] = 0.0f;
    m->m[2][3] = 0.0f;
    *(sV_1668B8*)m->m[3] = pos;
    vu0MulEqMtx_1668B8(m, &tm);
}

static inline sV_1668B8 Row_1668B8(const sM_1668B8& m, int i)
{
    return *(const sV_1668B8*)m.m[i];
}

extern "C" void func_001668B8_impl(char* self, sV_1668B8* out) __asm__("func_001668B8");
extern "C" void func_001668B8_impl(char* self, sV_1668B8* out)
{
    sM_1668B8 m;
    vu0CopyMtx_1668B8(&m, &D_004FF1A0_1668B8);
    Rotate_1668B8(&m, D_004FF150_1668B8, -*(float*)(self + 0x54));
    Rotate_1668B8(&m, D_004FF160_v1668B8, -*(float*)(self + 0x50));
    *out = Row_1668B8(m, 0);
}
#endif

INCLUDE_ASM("camera/camera", func_00166C60);

//100%
INCLUDE_ASM("camera/camera", func_00166F28);
#ifdef SKIP_ASM
struct sVE166F28a {
    short delta;
    short index;
    void* (*fn)(void*);
};

struct sVE166F28b {
    short delta;
    short index;
    void* (*fn)(void*, void*);
};

extern "C" void* func_00166F28(void* self)
{
    sVE166F28b* vt = *(sVE166F28b**)((char*)self + 0x10);
    char* o = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sVE166F28a* vt2 = *(sVE166F28a**)o;
    return vt[3].fn((char*)self + vt[3].delta, vt2[7].fn(o + vt2[7].delta));
}
#endif

INCLUDE_ASM("camera/camera", func_00166F90);

//100%
INCLUDE_ASM("camera/camera", func_001673A0);
#ifdef SKIP_ASM
extern "C" void* func_001673A0(void* self, void* a1)
{
    *(cQuad128*)self = *(cQuad128*)((char*)a1 + 0x60);
    *(cQuad128*)((char*)self + 0x10) = *(cQuad128*)((char*)a1 + 0x70);
    return self;
}
#endif

INCLUDE_ASM("camera/camera", func_001673B8);

INCLUDE_ASM("camera/camera", func_001673F8);

//100%
INCLUDE_ASM("camera/camera", func_00167D88);
#ifdef SKIP_ASM
extern "C" float func_00167D88(void)
{
    return 0.1f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167D98);
#ifdef SKIP_ASM
extern "C" float func_00167D98(void* self)
{
    return 0.10000000149011612f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167DA8);
#ifdef SKIP_ASM
extern "C" float func_00167DA8(void* self)
{
    return 0.10000000149011612f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167DB8);
#ifdef SKIP_ASM
struct sCamFilter {
    float field_0x00[5];
    float field_0x14[5];
    int field_0x28[5];
    int field_0x3C;
};

extern "C" void func_00167DB8(sCamFilter* self, float value)
{
    int i;
    self->field_0x3C = 0;
    for (i = 0; i < 5; i++) {
        self->field_0x00[i] = value;
        self->field_0x14[i] = value;
        self->field_0x28[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167DE8);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00167DE8(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E18__FPv);
#ifdef SKIP_ASM
void func_00167E18(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E20__FPv);
#ifdef SKIP_ASM
void func_00167E20(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E28__FPv);
#ifdef SKIP_ASM
void func_00167E28(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E30);
#ifdef SKIP_ASM
extern "C" float func_00167E30(void* self)
{
    return 0.7853981852531433f;
}
#endif

extern cQuad128 D_004FF120;

//100%
INCLUDE_ASM("camera/camera", func_00167E40);
#ifdef SKIP_ASM
extern "C" void* func_00167E40(void* self)
{
    *(cQuad128*)self = D_004FF120;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E58__FPv);
#ifdef SKIP_ASM
void func_00167E58(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E60__FPv);
#ifdef SKIP_ASM
void func_00167E60(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E68);
#ifdef SKIP_ASM
class func_00167E68_cObj {
public:
    char pad[0x10];
    // vptr lands at 0x10 (g++ 2.95 places it after the class's own data);
    // slot N lives at vtable offset N*8 (delta at +0, function at +4)
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" void func_00167E68(func_00167E68_cObj* self)
{
    self->v05();
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E90__FPv);
#ifdef SKIP_ASM
void func_00167E90(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167E98__FPv);
#ifdef SKIP_ASM
int func_00167E98(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167EA0);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00167EA0(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167ED0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_00167ED0(void *arg0, long long *arg1) {
    (*(long long *)((char*)(arg0) + (0x20))) = (long long) *arg1;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167EE0);
#ifdef SKIP_ASM
extern "C" void func_00167EE0(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x30))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167EE8);
#ifdef SKIP_ASM
extern "C" void func_00167EE8(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x34))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167EF0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long long *func_00167EF0(long long *arg0, void *arg1) {
    *arg0 = (*(long long *)((char*)(arg1) + (0x20)));
    return arg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167F00);
#ifdef SKIP_ASM
extern "C" float func_00167F00(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x30)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167F08);
#ifdef SKIP_ASM
extern "C" float func_00167F08(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x34)));
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167F10);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00167F10(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167F40);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00167F40(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167F70);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00167F70(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167FA0);
#ifdef SKIP_ASM
extern "C" void* func_00167FA0(void* self, void* a1)
{
    *(cQuad128*)self = *(cQuad128*)((char*)a1 + 0x20);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167FB0__FPv);
#ifdef SKIP_ASM
int func_00167FB0(void* self)
{
    return *(int*)((char*)self + 0x2F0);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167FB8__FPv);
#ifdef SKIP_ASM
void func_00167FB8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00167FC0);
#ifdef SKIP_ASM
extern "C" void func_00167FC0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167FC8);
#ifdef SKIP_ASM
extern "C" int func_00167FC8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167FD0);
#ifdef SKIP_ASM
extern "C" int func_00167FD0(int *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167FD8);
#ifdef SKIP_ASM
extern "C" int func_00167FD8(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167FE0);
#ifdef SKIP_ASM
extern "C" int func_00167FE0(void *arg0) {
    return (*(int *)((char*)(arg0) + (8)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167FE8);
#ifdef SKIP_ASM
extern "C" int func_00167FE8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167FF0);
#ifdef SKIP_ASM
extern "C" int func_00167FF0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00167FF8);
#ifdef SKIP_ASM
extern "C" void func_00167FF8(void) {

}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168000);
#ifdef SKIP_ASM
extern "C" void func_00168000(void) {

}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168008);
#ifdef SKIP_ASM
extern "C" void func_00168008(void) {

}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168010);
#ifdef SKIP_ASM
extern "C" void func_00168010(void) {

}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168018);
#ifdef SKIP_ASM
extern "C" int func_00168018(void) {
    return 0x3D;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168020);
#ifdef SKIP_ASM
extern "C" int func_00168020(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168028);
#ifdef SKIP_ASM
extern "C" int func_00168028(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C)));
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168030);
#ifdef SKIP_ASM
extern void* D_0045B8B0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00168030(void* self, int flags)
{
    *(void***)((char*)self + 0x90) = D_0045B8B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_0015D928(void* self);

//100%
INCLUDE_ASM("camera/camera", func_00168060__FPv);
#ifdef SKIP_ASM
void* func_00168060(void* self)
{
    return func_0015D928(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168080);
#ifdef SKIP_ASM
extern "C" float func_00168080(float *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168088);
#ifdef SKIP_ASM
extern "C" float func_00168088(void *arg0) {
    return (*(float *)((char*)(arg0) + (4)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168090);
#ifdef SKIP_ASM
extern "C" float func_00168090(void *arg0) {
    return (*(float *)((char*)(arg0) + (8)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168098);
#ifdef SKIP_ASM
extern "C" int func_00168098(int arg0) {
    return arg0 + 0x40;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680A0);
#ifdef SKIP_ASM
extern "C" int func_001680A0(int arg0) {
    return arg0 + 0x20;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680A8);
#ifdef SKIP_ASM
extern "C" int func_001680A8(int arg0) {
    return arg0 + 0x20;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680B0);
#ifdef SKIP_ASM
extern "C" int func_001680B0(int arg0) {
    return arg0 + 0x80;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680B8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_001680B8(void *arg0, long long *arg1) {
    (*(long long *)((char*)(arg0) + (0x20))) = (long long) *arg1;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680C8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_001680C8(void *arg0, long long *arg1) {
    (*(long long *)((char*)(arg0) + (0x30))) = (long long) *arg1;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680D8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_001680D8(void *arg0, void *arg1) {
    (*(long long *)((char*)(arg0) + (0x20))) = (long long) (*(long long *)((char*)(arg1) + (0)));
    (*(long long *)((char*)(arg0) + (0x30))) = (long long) (*(long long *)((char*)(arg1) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680F0);
#ifdef SKIP_ASM
extern "C" void func_001680F0(float *arg0, float fparg0) {
    *arg0 = fparg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_001680F8);
#ifdef SKIP_ASM
extern "C" void func_001680F8(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x14))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168100);
#ifdef SKIP_ASM
extern "C" void func_00168100(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x10))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168108);
#ifdef SKIP_ASM
extern "C" void func_00168108(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0xC))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168110);
#ifdef SKIP_ASM
extern "C" int func_00168110(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA0)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168118);
#ifdef SKIP_ASM
extern "C" int func_00168118(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA4)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168120);
#ifdef SKIP_ASM
extern "C" int func_00168120(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA8)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168128);
#ifdef SKIP_ASM
extern "C" int func_00168128(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAC)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168130);
#ifdef SKIP_ASM
extern "C" int func_00168130(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB4)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168138);
#ifdef SKIP_ASM
extern "C" int func_00168138(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB0)));
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168140);
#ifdef SKIP_ASM
extern "C" void func_00168140(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (4))) = arg1;
}
#endif
//100%
INCLUDE_ASM("camera/camera", func_00168148);
#ifdef SKIP_ASM
extern "C" int func_00168148(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

INCLUDE_ASM("camera/camera", func_00168150);

extern "C" void* func_001673F8(int, int);

//99.38%
INCLUDE_ASM("camera/camera", func_00168298__FPv);
#ifdef SKIP_ASM
void* func_00168298(void* self)
{
    return func_001673F8(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001682B8);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045C628[];

extern "C" void* func_001682B8(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0xD;
    *(void***)((char*)self + 0x10) = D_0045C628;
    return self;
}
#endif

extern void* D_0045C628[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_001682F8__FPv);
#ifdef SKIP_ASM
void* func_001682F8(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045C628;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168320__FPv);
#ifdef SKIP_ASM
float func_00168320(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168330__FPvT0);
#ifdef SKIP_ASM
void func_00168330(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

INCLUDE_ASM("camera/camera", func_00168338);

INCLUDE_ASM("camera/camera", func_00168508);

//100%
INCLUDE_ASM("camera/camera", func_00168650);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045C6A0[];

extern "C" void* func_00168650(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x20;
    *(void***)((char*)self + 0x10) = D_0045C6A0;
    return self;
}
#endif

extern void* D_0045C6A0[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_00168690__FPv);
#ifdef SKIP_ASM
void* func_00168690(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045C6A0;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001686B8__FPv);
#ifdef SKIP_ASM
float func_001686B8(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001686C8__FPvT0);
#ifdef SKIP_ASM
void func_001686C8(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/camera", func_001686D0);
#ifdef SKIP_ASM
extern "C" void func_00162C78(void* self, void* info);
extern "C" void func_00163010(void* self, void* info, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_00163270(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_00162B90(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001643A8(void* self, void* info, float a, float b, float c);
extern "C" void func_00163158(void* self, void* info, float a, float b);

struct sVec_1686D0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVEv_1686D0 {
    short delta;
    short index;
    sVec_1686D0 (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec_1686D0 Sub_1686D0(const sVec_1686D0& a, const sVec_1686D0& b)
{
    sVec_1686D0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec_1686D0 Add_1686D0(const sVec_1686D0& a, const sVec_1686D0& b)
{
    sVec_1686D0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec_1686D0 Scale_1686D0(const sVec_1686D0& v, float s)
{
    sVec_1686D0 r;
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

// PORT: PS2-only VU0 inline asm (in-place v *= s).
static inline void ScaleEq_1686D0(sVec_1686D0& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "lqc2      $vf4, %0\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_1686D0(const sVec_1686D0& v)
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_1686D0(const sVec_1686D0& a, const sVec_1686D0& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

static inline sVec_1686D0 Get_1686D0(char* self, int slot)
{
    char* o = *(char**)(self + 0x30);
    sVEv_1686D0* e = &(*(sVEv_1686D0**)o)[slot];
    return e->fn(o + e->delta);
}

extern "C" void func_001686D0(char* self)
{
    sCamInfo_001607E0 info;
    func_00162568(self, &info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f, 0.8513929843902588f,
                  0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f, 0.6000000238418579f);
    float zero = 0.0f;
    func_00162A20(self, (char*)&info);
    func_00162B80(self, &info);
    func_00162C78(self, &info);
    func_00163010(self, &info, 193.1998291015625f, zero, 76.68663024902344f, zero, 1.7668397426605225f,
                  0.9239780306816101f, 0.907414972782135f);
    func_00163270(self, &info, zero, 1.2432044744491577f, zero, zero, 0.9783917665481567f);
    func_001633B0(self, &info, zero, 0.9927757978439331f, 1.0f, 0.949999988079071f);
    func_00162B90(self, &info, 0.721226155757904f, 0.01082259975373745f, 0.22186216711997986f, 0.5425665378570557f,
                  0.9241908192634583f);
    func_001643A8(self, &info, 15.0f, 1.5f, 1.5f);
    func_00163158(self, &info, 0.13458502292633057f, 1.7663990259170532f);

    sVec_1686D0 d = Sub_1686D0(*(sVec_1686D0*)(self + 0x20), *(sVec_1686D0*)(self + 0x40));
    float len = Length_1686D0(d);
    ScaleEq_1686D0(d, (len + 294.9358825683594f) / len);
    sVec_1686D0 pos = Add_1686D0(*(sVec_1686D0*)(self + 0x40), d);
    sVec_1686D0 off = Sub_1686D0(Get_1686D0(self, 1), pos);
    float t = Dot_1686D0(off, d) / Dot_1686D0(d, d);
    sVec_1686D0 np = Add_1686D0(Scale_1686D0(d, t), pos);
    *(sVec_1686D0*)(self + 0x20) = np;
    *(sVec_1686D0*)(self + 0x40) = pos;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168940);
#ifdef SKIP_ASM
class cCamTargetK8940 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
};
class cCamCtrlK8940 {
public:
    char pad_0x00[0x10];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" void func_00168940(cCamCtrlK8940* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTargetK8940*)(rider + 0x6C0))->v07()) {
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_001689C8);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045C538[];

extern "C" void* func_001689C8(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x9;
    *(void***)((char*)self + 0x10) = D_0045C538;
    return self;
}
#endif

extern void* D_0045C538[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_00168A08__FPv);
#ifdef SKIP_ASM
void* func_00168A08(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045C538;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168A30);
#ifdef SKIP_ASM
extern "C" float func_00168A30(void* self)
{
    return 61.68796157836914f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168A40);
#ifdef SKIP_ASM
extern "C" void func_00168A40(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/camera", func_00168A70);
#ifdef SKIP_ASM
extern "C" void func_00162C78(void* self, void* info);
extern "C" void func_00163010(void* self, void* info, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_00163270(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_00162B90(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001635F8(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00164878(void* self, void* info, float a);
extern "C" void func_001646A0(char* self, char* p, float k, float t);
extern "C" void func_001641C0(char* self, char* p, float a, float b, float c, float d);
extern "C" void func_001643A8(void* self, void* info, float a, float b, float c);
extern "C" void func_00163158(void* self, void* info, float a, float b);
// PORT: func_00163450 is defined with 7 float parameters; this caller passes 8.
void func_00163450_8(char* self, char* trig, float a, float b, float c, float d, float e, float f, float g,
                     float h) __asm__("func_00163450");

extern "C" void func_00168A70(char* self)
{
    sCamInfo_001607E0 info;
    func_00162568(self, &info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f, 0.8513929843902588f,
                  0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f, 0.6000000238418579f);
    float zero = 0.0f;
    float k = 0.9800000190734863f;
    func_00162998(self, &info);
    func_00162A20(self, (char*)&info);
    func_00162B80(self, &info);
    func_00162C78(self, &info);
    func_00163010(self, &info, 555.0844116210938f, 11.549837112426758f, 76.68663024902344f, 307.0549621582031f,
                  1.7668397426605225f, 0.9239780306816101f, 0.907414972782135f);
    func_00163270(self, &info, 12.331472396850586f, 84.0909652709961f, 38.64322280883789f, 93.62934875488281f,
                  0.9783917665481567f);
    func_001633B0(self, &info, zero, 0.8567028641700745f, 1.0f, 0.949999988079071f);
    func_00163450_8(self, (char*)&info, 348.64111328125f, 66.33821868896484f, 162.2997283935547f, 2.00368070602417f,
                    zero, k, 0.9599999785423279f, 0.4552607834339142f);
    func_00162B90(self, &info, -8.730510711669922f, 64.15198516845703f, 58.114906311035156f, 5.931424617767334f,
                  0.9241908192634583f);
    func_001635F8(self, &info, 1.878627061843872f, 2.494720935821533f, 0.34134337306022644f, 0.8672914505004883f);
    func_00164878(self, &info, 1.5269116163253784f);
    func_001646A0(self, (char*)&info, 200.33114624023438f, 0.9706981778144836f);
    func_001641C0(self, (char*)&info, 600.0f, 300.0f, 100.0f, k);
    func_001643A8(self, &info, 15.0f, 1.5f, 1.5f);
    func_00163158(self, &info, -0.2944446802139282f, 0.6521888375282288f);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168C50);
#ifdef SKIP_ASM
extern "C" void func_00168C50(cCamCtrlK8940* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTargetK8940*)(rider + 0x6C0))->v07()) {
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168CD8);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045C5B0[];

extern "C" void* func_00168CD8(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x9;
    *(void***)((char*)self + 0x10) = D_0045C5B0;
    return self;
}
#endif

extern void* D_0045C5B0[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/camera", func_00168D18__FPv);
#ifdef SKIP_ASM
void* func_00168D18(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045C5B0;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168D40);
#ifdef SKIP_ASM
extern "C" float func_00168D40(void* self)
{
    return 61.68796157836914f;
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168D50);
#ifdef SKIP_ASM
extern "C" void func_00168D50(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/camera", func_00168D80);
#ifdef SKIP_ASM
extern "C" void func_00162C78(void* self, void* info);
extern "C" void func_00163010(void* self, void* info, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_00163270(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_00162B90(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001635F8(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00164878(void* self, void* info, float a);
extern "C" void func_001646A0(char* self, char* p, float k, float t);
extern "C" void func_001641C0(char* self, char* p, float a, float b, float c, float d);
extern "C" void func_001643A8(void* self, void* info, float a, float b, float c);
extern "C" void func_00163158(void* self, void* info, float a, float b);
// PORT: func_00163450 is defined with 7 float parameters; this caller passes 8.
void func_00163450_8(char* self, char* trig, float a, float b, float c, float d, float e, float f, float g,
                     float h) __asm__("func_00163450");

extern "C" void func_00168D80(char* self)
{
    sCamInfo_001607E0 info;
    func_00162568(self, &info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f, 0.8513929843902588f,
                  0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f, 0.6000000238418579f);
    float zero = 0.0f;
    float k = 0.9800000190734863f;
    func_00162998(self, &info);
    func_00162A20(self, (char*)&info);
    func_00162B80(self, &info);
    func_00162C78(self, &info);
    func_00163010(self, &info, 555.0844116210938f, 11.549837112426758f, 76.68663024902344f, 307.0549621582031f,
                  1.7668397426605225f, 0.9239780306816101f, 0.907414972782135f);
    func_00163270(self, &info, 12.331472396850586f, 84.0909652709961f, 38.64322280883789f, 93.62934875488281f,
                  0.9783917665481567f);
    func_001633B0(self, &info, zero, 0.8567028641700745f, 1.0f, 0.949999988079071f);
    func_00163450_8(self, (char*)&info, 348.64111328125f, 66.33821868896484f, 162.2997283935547f, 2.00368070602417f,
                    zero, k, 0.9599999785423279f, 0.4552607834339142f);
    func_00162B90(self, &info, -8.730510711669922f, 64.15198516845703f, 58.114906311035156f, 5.931424617767334f,
                  0.9241908192634583f);
    func_001635F8(self, &info, 1.878627061843872f, 2.494720935821533f, 0.34134337306022644f, 0.8672914505004883f);
    func_00164878(self, &info, 1.5269116163253784f);
    func_001646A0(self, (char*)&info, 200.33114624023438f, 0.9706981778144836f);
    func_001641C0(self, (char*)&info, 600.0f, 300.0f, 100.0f, k);
    func_001643A8(self, &info, 15.0f, 1.5f, 1.5f);
    func_00163158(self, &info, 0.2944446802139282f, 0.6521888375282288f);
}
#endif

//100%
INCLUDE_ASM("camera/camera", func_00168F60);
#ifdef SKIP_ASM
extern "C" void func_00168F60(cCamCtrlK8940* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTargetK8940*)(rider + 0x6C0))->v07()) {
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

