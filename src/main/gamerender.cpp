#include "common.h"

//100%
INCLUDE_ASM("main/gamerender", cGameViewMan_cGameViewMan);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cCamera_cCamera(void* self, int idx);
extern "C" void func_0015DFD8(void* self, int mode);
extern char* D_004A289C;
extern char D_0047B538[];

struct sVECam22E3B8 {
    short delta;
    short index;
    void (*fn)(void*, int, float, float, float);
};

struct sCam22E3B8 {
    char pad[0x90];
    sVECam22E3B8* vt;
};

class cDisp22E3B8 {
public:
    char pad[0x10D8];
    // vptr at 0x10D8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual unsigned int v10();
    virtual unsigned int v11();
};

struct sCamRef22E3B8 {
    sCam22E3B8* p;
    sCamRef22E3B8() {}
    void* operator new[](unsigned int, void* where) { return where; }
};

struct cGameViewMan22E3B8 {
    unsigned int count;
    sCamRef22E3B8 cams[2];
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    float width;
    float height;
};

extern "C" cGameViewMan22E3B8* cGameViewMan_cGameViewMan(cGameViewMan22E3B8* self, unsigned int count)
{
    new ((char*)self + 4) sCamRef22E3B8[2];
    self->count = count;
    float farClip = 30000.0f;
    if (count >= 2) {
        farClip = 20000.0f;
    }
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (i < self->count) {
            self->cams[i].p = (sCam22E3B8*)cCamera_cCamera(cMemMan_alloc(0x4B0, D_0047B538, 0x20000000, 0), i);
            sCam22E3B8* c = self->cams[i].p;
            c->vt[2].fn((char*)c + c->vt[2].delta, i, 0.7853981852531433f, 30.0f, farClip);
            func_0015DFD8(self->cams[i].p, 2);
        } else {
            self->cams[i].p = 0;
        }
    }
    self->fC = 0;
    self->f10 = 1;
    self->f14 = 0;
    float w = (float)((cDisp22E3B8*)D_004A289C)->v10();
    float h = (float)((cDisp22E3B8*)D_004A289C)->v11();
    self->width = w;
    self->height = h;
    self->f18 = 0;
    self->f1C = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/gamerender", func_0022E550);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern char* D_004A289C;

class cDisp22E550 {
public:
    char pad[0x10D8];
    // vptr at 0x10D8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual unsigned int v10();
    virtual unsigned int v11();
};

struct sCam22E550 {
    char pad[0x14];
    float farClip;      // 0x14
    char pad18[0xB0 - 0x18];
    int index;          // 0xB0
};

struct sSlot22E550 {
    int active;
    char pad[0x4C];
};

struct sSlots22E550 {
    char pad[0x250];
    sSlot22E550 e[2];
};

struct sRect22E550 {
    float x, y, w, h;
};

struct cGameViewMan22E550 {
    unsigned int count;      // 0x0
    sCam22E550* cams[2];     // 0x4
    int mode;                // 0xC
    int views;               // 0x10
    int f14;                 // 0x14
    sRect22E550 rects[2];    // 0x18
};

extern "C" void func_0022E550(cGameViewMan22E550* self)
{
    char* game = *(char**)((char*)D_004A28A8 + 0x84);
    int mode = *(int*)(game + 0x214);
    if (self->mode == mode) {
        return;
    }
    int n = **(int**)(game + 0x28);
    int busy = n && n < 10;
    if (busy) {
        return;
    }
    self->mode = mode;
    if (self->count == 1) {
        return;
    }
    float w = (float)((cDisp22E550*)D_004A289C)->v10();
    float h = (float)((cDisp22E550*)D_004A289C)->v11();
    switch (self->mode) {
    case 3:
    case 4:
    case 5: {
        float hw = w * 0.5f;
        self->views = 2;
        self->f14 = 0;
        self->rects[0].x = 0.0f;
        self->rects[0].y = 0.0f;
        self->rects[0].w = hw;
        self->rects[0].h = h;
        self->rects[1].x = hw;
        self->rects[1].y = 0.0f;
        self->rects[1].w = hw;
        self->rects[1].h = h;
        self->cams[0]->farClip = 20000.0f;
        self->cams[1]->farClip = 20000.0f;
        break;
    }
    default:
        self->views = 1;
        self->rects[0].w = w;
        self->rects[0].h = h;
        self->f14 = 0;
        self->rects[0].x = 0.0f;
        self->rects[0].y = 0.0f;
        self->cams[0]->farClip = 30000.0f;
        break;
    }
    if (self->views == 1) {
        int idx = self->cams[1]->index;
        (**(sSlots22E550***)(*(char**)((char*)D_004A28A8 + 0x84) + 0x10))->e[idx].active = 0;
    } else {
        (**(sSlots22E550***)(*(char**)((char*)D_004A28A8 + 0x84) + 0x10))->e[0].active = 0;
        (**(sSlots22E550***)(*(char**)((char*)D_004A28A8 + 0x84) + 0x10))->e[1].active = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamerender", func_0022E730);
#ifdef SKIP_ASM
struct sVEntry0022E730 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sItem0022E730 {
    char pad[0x90];
    sVEntry0022E730* vt;
};
struct sList0022E730 {
    unsigned int count;
    sItem0022E730* items[3];
    int field_0x10;
};
void operator_delete(int* p);

extern "C" void func_0022E730(sList0022E730* self, int flags)
{
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        sItem0022E730* it = self->items[i];
        if (it != 0) {
            it->vt[1].fn((char*)it + it->vt[1].delta, 3);
        }
    }
    self->field_0x10 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamerender", func_0022E7C8);
#ifdef SKIP_ASM
struct sVEntry_0022E7C8 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0022E7C8(void* self)
{
    unsigned int i;
    for (i = 0; i < *(unsigned int*)((char*)self + 0x10); i++) {
        void* v = ((void**)((char*)self + 0x4))[i];
        void* o = *(void**)((char*)v + 0xA0);
        sVEntry_0022E7C8* vt = *(sVEntry_0022E7C8**)((char*)o + 0x14);
        vt[4].fn((char*)o + vt[4].delta);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamerender", cGameViewMan_updateAll);
#ifdef SKIP_ASM
struct sVEntry_0022E840 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void cGameViewMan_updateAll(void* self)
{
    unsigned int i;
    for (i = 0; i < *(unsigned int*)((char*)self + 0x10); i++) {
        void* v = ((void**)((char*)self + 0x4))[i];
        sVEntry_0022E840* vt = *(sVEntry_0022E840**)((char*)v + 0x90);
        vt[3].fn((char*)v + vt[3].delta);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamerender", func_0022E8B8);
#ifdef SKIP_ASM
extern "C" void func_0015EC98(void* p);

extern "C" void func_0022E8B8(void* self)
{
    unsigned int i;
    for (i = 0; i < *(unsigned int*)((char*)self + 0x10); i++) {
        func_0015EC98(((void**)((char*)self + 0x4))[i]);
    }
}
#endif

//100%
INCLUDE_ASM("main/gamerender", func_0022E920);
#ifdef SKIP_ASM
struct sRenderList {
    int field_0x0;
    void* items[3];
    unsigned int count;
};

extern "C" int func_0022E920(sRenderList* self)
{
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        if (*(int*)((char*)self->items[i] + 0xb4) == 0) {
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gamerender", func_0022E968);
#ifdef SKIP_ASM
extern char D_0047D110[];
extern char D_0047D168[];
extern char D_0047D1C0[];
extern char D_0047D218[];
extern char D_0047D270[];
extern char D_0047D378[];
extern char D_0047D3D0[];
extern char D_0047D480[];
extern char D_0047D4D8[];
extern char D_0047D588[];
extern char D_0047D638[];
extern char D_0047D690[];
extern char D_0047D6E8[];
extern char* D_004A2C68;
extern int D_004A2A54;
extern "C" void* func_00231CD0(void* self);
extern "C" void* func_00233C10(void* self);
extern "C" void* func_00234188(void* self);
extern "C" void* func_00234EF8(void* self);
extern "C" void* func_00236208(void* self);
extern "C" void* func_00236868(void* self);
extern "C" void func_00244240(int a);

struct sArr_22E968 {
    char pad[0x5C];
    int a[2];
    int pad64;
    int b[2];
};

static inline void Base_22E968(char* s, int off)
{
    *(void**)(s + off + 0xC) = D_0047D6E8;
    *(int*)(s + off + 0x0) = 0;
    D_004A2C68 = 0;
}

static inline void Init_22E968(char* s, int off, void* vt, int id)
{
    Base_22E968(s, off);
    *(void**)(s + off + 0xC) = vt;
    *(int*)(s + off + 0x4) = 0;
    *(int*)(s + off + 0x0) = id;
}

extern "C" char* func_0022E968(char* self)
{
    func_00231CD0(self);
    *(int*)(self + 0xC) = 0;
    *(int*)(self + 0x24) = 0;
    *(void**)(self + 0x0) = D_0047D110;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x7C) = 0;
    D_004A2A54 = 0;
    func_00244240(0);
    *(int*)(self + 0x84) = 0;
    func_00234188(self + 0xB0);
    Init_22E968(self, 0xD0, D_0047D270, 3);
    Init_22E968(self, 0xE0, D_0047D4D8, 4);
    Init_22E968(self, 0xF0, D_0047D480, 5);
    func_00233C10(self + 0x100);
    Init_22E968(self, 0x118, D_0047D690, 8);
    Init_22E968(self, 0x128, D_0047D218, 8);
    Init_22E968(self, 0x138, D_0047D638, 11);
    Init_22E968(self, 0x148, D_0047D588, 10);
    func_00234EF8(self + 0x158);
    func_00236868(self + 0x178);
    Init_22E968(self, 0x18C, D_0047D1C0, 7);
    Base_22E968(self, 0x19C);
    *(void**)(self + 0x1A8) = D_0047D3D0;
    *(int*)(self + 0x1A0) = 3;
    *(int*)(self + 0x1B0) = 0;
    *(int*)(self + 0x1B4) = 0;
    *(int*)(self + 0x19C) = 1;
    func_00236208(self + 0x1B8);
    Init_22E968(self, 0x1DC, D_0047D378, 10);
    Init_22E968(self, 0x1EC, D_0047D168, 4);
    *(int*)(self + 0x228) = -1;
    *(int*)(self + 0x224) = 0;
    for (int i = 0; i < 2; i++) {
        ((sArr_22E968*)self)->a[i] = 0;
        ((sArr_22E968*)self)->b[i] = 0;
    }
    return self;
}
#endif

