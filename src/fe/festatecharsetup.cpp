#include "common.h"

//100%
INCLUDE_ASM("fe/festatecharsetup", cFEStateCharSetup_onCreateScreen);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" void func_00182DB8(void* self);
extern "C" void func_001A0570(void* self, int i, int v);
extern "C" void func_001A0508(void* self, int idx, int a2, int a3);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* snd, int a);
extern void* D_004A28A8;
extern signed char D_00535C11[];
extern char D_0045D7C0[];
extern char D_004A1410[];
extern char D_0045D7D0[];
extern char D_0045D7F0[];
extern char D_0045D810[];
extern char D_0045D820[];
extern char D_0045D830[];
extern char D_0045D840[];
extern char D_0045D850[];

struct sVEntry_182928 {
    short delta;
    short index;
    void (*fn)(void*);
};

class cWidget_182928 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void enable(int on);
    virtual void show(int on);
};

struct sCharSetup_182928 {
    char pad_0x0[0x10];
    void* engine;               // 0x10
    char pad_0x14[0x2C];
    void* screen;               // 0x40
    signed char player;         // 0x44
};

static inline void showIdx_182928(sCharSetup_182928* self, char* name, int idx)
{
    cWidget_182928* o = (cWidget_182928*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(name));
    if (o != 0) {
        o->show(1);
        *(int*)((char*)o + 0x18) = idx;
    }
}

extern "C" void cFEStateCharSetup_onCreateScreen(sCharSetup_182928* self)
{
    void* engine = self->engine;
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045D7C0), 0);
    self->screen = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_00182DB8(self);
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
    int charId = cBENewPlayerInterface_getPlayerCharID(iface, self->player);
    sVEntry_182928* vt = *(sVEntry_182928**)(iface + 0xC);
    vt[2].fn(iface + vt[2].delta);
    func_001A0570(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, self->player, 0);
    func_001A0508(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, self->player, charId, 0);
    func_0028F140(func_0028B180(), 1);
    cUIText* txt = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A1410));
    if (txt != 0) {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        if (D_00535C11[0] == 2) {
            switch (self->player) {
            case 0:
                cUIText_setUnicodeStringByID(txt, GetHashValue32(D_0045D7D0));
                break;
            case 1:
                cUIText_setUnicodeStringByID(txt, GetHashValue32(D_0045D7F0));
                break;
            }
        }
    }
    showIdx_182928(self, D_0045D810, 0);
    showIdx_182928(self, D_0045D820, 1);
    showIdx_182928(self, D_0045D830, 2);
    showIdx_182928(self, D_0045D840, 3);
    cWidget_182928* o = (cWidget_182928*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_0045D850));
    if (o != 0) {
        o->show(0);
        o->enable(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_00182C08);
#ifdef SKIP_ASM
extern "C" void func_001831D0(void* self, int a1);
void* func_0039E4A0(void* self);

extern "C" void func_00182C08(void* self)
{
    func_001831D0(self, 0);
    func_0039E4A0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_00182C38);
#ifdef SKIP_ASM
extern "C" void* func_0039E510(void* self);
extern "C" void func_00182EC0(void* self);

extern "C" void func_00182C38(void* self)
{
    func_0039E510(self);
    func_00182EC0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_00182C68);
#ifdef SKIP_ASM
extern "C" int func_00182C68(void* self, int a1, int a2)
{
    return a2 != 9 ? 0x101 : 0x100;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_00182C80);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001887A0(void* self, void* engine, int reset);
extern "C" void cUIStateStack_pushSpecial(void* stack, void* st, int a2, int a3);
extern "C" void func_0039F400(void* list, void* item);
extern "C" void func_001831D0(void* self, int a1);
extern char D_0045D698[];

struct sVEntryK182C80 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sStateK182C80 {
    char pad_0x0[0x1C];
    unsigned lo : 8;
    unsigned mode : 6;
    unsigned hi : 18;
};

extern "C" void func_00182C80(void* self, void* item, unsigned int event)
{
    if (item == 0)
        return;
    switch (event) {
    case 5: {
        char* o = **(char***)((char*)self + 0x10);
        sVEntryK182C80* vt = *(sVEntryK182C80**)(o + 4);
        void* r = vt[4].fn(o + vt[4].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0)
            func_0039F400(*(char**)((char*)self + 0x10) + 0x18, r);
        func_001831D0(self, 0);
        break;
    }
    case 6: {
        char* o = **(char***)((char*)self + 0x10);
        sVEntryK182C80* vt = *(sVEntryK182C80**)(o + 4);
        void* r = vt[5].fn(o + vt[5].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400(*(char**)((char*)self + 0x10) + 0x18, r);
            func_001831D0(self, 0);
        }
        break;
    }
    case 7: {
        sStateK182C80* st = (sStateK182C80*)func_001887A0(cMemMan_alloc(0x54, D_0045D698, 0x100, 0),
                                                          *(void**)((char*)self + 0x10), 1);
        st->mode = 1;
        cUIStateStack_pushSpecial(*(char**)((char*)self + 0x10) + 0x18, st, 0, 0);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_00182DB8);
#ifdef SKIP_ASM
struct cUIText;
struct sVec4_182DB8 { float x, y, z, w; } __attribute__((aligned(16)));
struct sCam_182DB8 { char pad[0x10]; float fov; };
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* func_0014EEC8(void* self, int player, int index);
extern "C" void func_0015E050(void* cam, sVec4_182DB8* a, sVec4_182DB8* b);
extern "C" void func_001831D0(void* self, int a1);
extern "C" void func_00182EC0(void* self);
extern void* D_004A28A8;
extern char D_0045D860[];

extern "C" void func_00182DB8(void* self)
{
    cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D860));
    signed char cid = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)((char*)self + 0x44));
    cUIText_setAsciiString(text, (const char*)func_0014EEC8(cBE_getInterface_Fv(cBE_getBE(), 2), cid, 0));
    sCam_182DB8* cam = *(sCam_182DB8**)((char*)D_004A28A8 + 0x7C);
    sVec4_182DB8 pos;
    pos.x = 0.0f;
    pos.y = 200.0f;
    pos.z = 0.0f;
    pos.w = 1.0f;
    sVec4_182DB8 at;
    at.x = 0.0f;
    at.y = 0.0f;
    at.z = 0.0f;
    at.w = 1.0f;
    func_0015E050((char*)cam + 0x10, &pos, &at);
    cam->fov = 0.4363323450088501f;
    func_001831D0(self, 1);
    *(int*)((char*)self + 0x48) = 1;
    func_00182EC0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_00182EC0);
#ifdef SKIP_ASM
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void* func_001A0548(void* self, int idx);
extern "C" void func_00311A50(void* anim);
extern "C" void cRiderAnimBase_play(void* anim, int id, int a2, float t);
extern "C" void func_001A0358(void* rider);
extern "C" void func_0019E538(void* self, int a1);
extern void* D_004A28A8;

struct sQuat_182EC0
{
    float x, y, z, w;
    sQuat_182EC0() {}
    sQuat_182EC0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sXform_182EC0
{
    sQuat_182EC0 pos;
    sQuat_182EC0 rot;
};

extern sQuat_182EC0 D_004FF140;
extern sQuat_182EC0 D_004FF150;
extern sQuat_182EC0 D_004FF160;
extern "C" void func_0019F3E8(void* rider, sXform_182EC0* xf);
extern "C" void func_0019F548(void* rider, sXform_182EC0* xf);

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sQuat_182EC0 QuatMul_182EC0(const sQuat_182EC0& a, const sQuat_182EC0& b)
{
    sQuat_182EC0 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline sQuat_182EC0 AxisAngle_182EC0(const sQuat_182EC0& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sQuat_182EC0(s * axis.x, s * axis.y, s * axis.z, c);
}

// Places the rider on the setup screen's podium and, when requested, restarts its idle animation.
extern "C" void func_00182EC0(void* self_)
{
    char* self = (char*)self_;
    char* rider = (char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)(self + 0x44));
    int ok = 0;
    if (*(unsigned int*)rider < 10 && *(int*)(rider + 0xCB8) != 0) {
        ok = *(int*)(rider + 0xCB4) != 0;
    }
    if (ok && *(int*)(self + 0x4C) != 0) {
        sQuat_182EC0 pos;
        sXform_182EC0 xf;
        {
            sQuat_182EC0 p;
            p.x = 136.0f;
            p.y = -250.0f;
            p.z = -82.0f;
            p.w = 1.0f;
            pos = p;
            xf.pos = p;
            xf.rot.x = 0.0f;
            xf.rot.w = 1.0f;
            xf.rot.y = 0.0f;
            xf.rot.z = 0.0f;
            xf.rot = QuatMul_182EC0(xf.rot, AxisAngle_182EC0(D_004FF140, 0.0f));
        }
        xf.rot = QuatMul_182EC0(xf.rot, AxisAngle_182EC0(D_004FF150, 0.0f));
        xf.rot = QuatMul_182EC0(xf.rot, AxisAngle_182EC0(D_004FF160, 1.7453293800354004f));
        func_0019F3E8(rider, &xf);
        {
            sQuat_182EC0 p;
            p.x = 0.0f;
            p.y = 10000.0f;
            p.z = 0.0f;
            p.w = 1.0f;
            xf.pos = p;
        }
        func_0019F548(rider, &xf);
        if (*(int*)(self + 0x48) != 0) {
            void* anim = *(void**)(rider + 0xC);
            if (anim != 0) {
                func_00311A50(anim);
                cRiderAnimBase_play(anim, 0x1B3, 0, -1.0f);
            }
            *(int*)(rider + 0xCCC) = 0;
            *(int*)(self + 0x48) = 0;
            func_001A0358(rider);
        }
        func_0019E538(rider, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_001831D0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_001A0548(void* self, int a1);
extern "C" void func_0019E538(void* self, int a1);

extern "C" void func_001831D0(void* self, int on)
{
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C);
    if (mgr != 0) {
        void* r = func_001A0548(mgr + 0xB0, *(signed char*)((char*)self + 0x44));
        if (on == 0) {
            func_0019E538(r, 0);
        }
        *(int*)((char*)self + 0x4C) = on;
        if (on == 0) {
            *(int*)((char*)self + 0x48) = 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharsetup", func_00183238);
#ifdef SKIP_ASM
extern "C" void* func_001828C0(void* self, void* engine, signed char idx);
extern "C" unsigned char func_001A1CD0(void* self, int a1);
extern void* D_0046CD90[];

extern "C" void* func_00183238(void* self, void* engine, signed char idx)
{
    func_001828C0(self, engine, idx);
    *(int*)((char*)self + 0xC) = 0xD;
    *(void***)((char*)self + 0x8) = D_0046CD90;
    *(signed char*)((char*)self + 0x44) = idx;
    *(unsigned char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), idx);
    *(int*)((char*)self + 0x4C) = 0;
    return self;
}
#endif

