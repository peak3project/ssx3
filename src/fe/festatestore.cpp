#include "common.h"

//100%
INCLUDE_ASM("fe/festatestore", cFEStateUberTrick_costVisible);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList* list);
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0045D9B8[];
extern char D_0045D9C8[];
extern char D_0045D9D8[];
extern char D_0045D9E8[];

class cWidget_00184668 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int a);
};

extern "C" void cFEStateUberTrick_costVisible(void* self, int on)
{
    void* screen = cList_first((cList*)((char*)self + 0x24));
    cWidget_00184668* a = (cWidget_00184668*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D9B8));
    if (a) {
        a->setVisible(on);
    }
    cWidget_00184668* b = (cWidget_00184668*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D9D8));
    if (b) {
        b->setVisible(on);
    }
    cWidget_00184668* c = (cWidget_00184668*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D9C8));
    if (c) {
        c->setVisible(on);
    }
    cWidget_00184668* d = (cWidget_00184668*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D9E8));
    if (d) {
        d->setVisible(on);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00184780);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList* list);
int GetHashValue32(char* str);
extern char D_004A1458[];
extern char D_004A1460[];

class cWidget_00184780 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a);
};

extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);

extern "C" void func_00184780(void* self, int on)
{
    void* screen = cList_first((cList*)((char*)self + 0x24));
    cWidget_00184780* w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004A1458));
    if (w) {
        w->v09(on);
    }
    w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004A1460));
    if (w) {
        w->v09(on);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", cFEStateUberTrick_trickVisible);
#ifdef SKIP_ASM
extern char D_0045D9F8[];
extern char D_0045DA08[];
extern char D_0045DA18[];
extern char D_0045D960[];
extern char D_0045D970[];
extern char D_0045D980[];

extern "C" void cFEStateUberTrick_trickVisible(void* self, int on)
{
    void* screen = cList_first((cList*)((char*)self + 0x24));
    cWidget_00184780* w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D9F8));
    if (w) {
        w->v09(on);
    }
    w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045DA08));
    if (w) {
        w->v09(on);
    }
    w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045DA18));
    if (w) {
        w->v09(on);
    }
    w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D960));
    if (w) {
        w->v09(on);
    }
    w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D970));
    if (w) {
        w->v09(on);
    }
    w = (cWidget_00184780*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D980));
    if (w) {
        w->v09(on);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_001849B0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int GetHashValue32(char* str);
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_001A0508(void* self, int a1, int a2, int a3);
extern "C" void func_001A0570(void* self, int a1, int a2);
extern "C" void func_0015E050(void* cam, void* a, void* b);
extern "C" void* func_00398380(void* list, int hash);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* p, int a);
extern "C" void cFEStateUberTrick_costVisible(void* self, int on);
extern "C" void func_00184780(void* self, int on);
extern void* D_004A28A8;
extern char D_0045DA28[];
extern char D_0045DA38[];
extern char D_0045DA48[];
extern char D_0045DA58[];

struct sVec4_1849B0 {
    float x, y, z, w;
};

struct sVE_1849B0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_001849B0(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DA28), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0)
        cUIScreen_playFrame(screen, 0, 0);
    char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
    signed char charID = cBENewPlayerInterface_getPlayerCharID(player, *(signed char*)((char*)self + 0x44));
    {
        sVE_1849B0* vt = *(sVE_1849B0**)(player + 0xC);
        vt[2].fn(player + vt[2].delta);
    }
    func_001A0508(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44), charID, 0);
    func_001A0570(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44), 0);
    char* m = *(char**)((char*)D_004A28A8 + 0x7C);
    sVec4_1849B0 a;
    sVec4_1849B0 b;
    float z = 80.0f;
    float w = 1.0f;
    float y = 660.0f;
    a.x = 0.0f;
    a.y = y;
    a.z = z;
    a.w = w;
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = z;
    b.w = w;
    func_0015E050(m + 0x10, &a, &b);
    *(float*)(m + 0x10) = 0.4363323450088501f;
    {
        char* e = *(char**)((char*)self + 0x10);
        int h = GetHashValue32(D_0045DA38);
        *(void**)((char*)self + 0x58) = func_00398380(e + 0x58, h);
    }
    {
        char* e = *(char**)((char*)self + 0x10);
        int h = GetHashValue32(D_0045DA48);
        *(void**)((char*)self + 0x54) = func_00398380(e + 0x58, h);
    }
    {
        char* e = *(char**)((char*)self + 0x10);
        int h = GetHashValue32(D_0045DA58);
        *(void**)((char*)self + 0x5C) = func_00398380(e + 0x58, h);
    }
    func_0028F140(func_0028B180(), 5);
    cFEStateUberTrick_costVisible(self, 0);
    func_00184780(self, 0);
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00184B70);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void func_001A0570(void* self, int a1, int a2);
void* func_0039E4A0(void* self);

extern "C" void func_00184B70(void* self)
{
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C);
    if (mgr != 0) {
        func_001A0570(mgr + 0xB0, *(signed char*)((char*)self + 0x44), 0);
    }
    func_0039E4A0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00184BB8);
#ifdef SKIP_ASM
extern "C" void cWScriptMan_checkGate(void* self);

extern "C" int func_00184BB8(void* self, int on)
{
    if (on != 0) {
        cWScriptMan_checkGate(self);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00184BE0);
#ifdef SKIP_ASM
struct sVEntry00184BE0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj00184BE0 {
    int pad[2];
    sVEntry00184BE0* vt;
};

extern "C" void func_00183B08(void* self);
extern "C" void func_0039E4C0(void* self, int a1);

extern "C" void func_00184BE0(void* self, int a1)
{
    sObj00184BE0* o;
    func_00183B08(self);
    o = *(sObj00184BE0**)((char*)self + 0x4C);
    if (o != 0) {
        o->vt[7].fn((char*)o + o->vt[7].delta, 1);
    }
    o = *(sObj00184BE0**)((char*)self + 0x50);
    if (o != 0) {
        o->vt[7].fn((char*)o + o->vt[7].delta, 0);
    }
    func_0039E4C0(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00184C60);
#ifdef SKIP_ASM
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void* func_001A0548(void* self, int idx);
extern "C" void func_00311A50(void* anim);
extern "C" void cRiderAnimBase_play(void* anim, int id, int a2, float t);
extern "C" void func_0039E510(void* self);
extern void* D_004A28A8;

struct sQuat_184C60
{
    float x, y, z, w;
    sQuat_184C60() {}
    sQuat_184C60(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sXform_184C60
{
    sQuat_184C60 pos;
    sQuat_184C60 rot;
};

extern sQuat_184C60 D_004FF140;
extern sQuat_184C60 D_004FF150;
extern sQuat_184C60 D_004FF160;
extern "C" void func_0019F3E8(void* rider, sXform_184C60* xf);

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sQuat_184C60 QuatMul_184C60(const sQuat_184C60& a, const sQuat_184C60& b)
{
    sQuat_184C60 r;
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

static inline sQuat_184C60 AxisAngle_184C60(const sQuat_184C60& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sQuat_184C60(s * axis.x, s * axis.y, s * axis.z, c);
}

extern "C" void func_00184C60(char* self)
{
    if (*(int*)(self + 0x48) == 0) {
        char* rider = (char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)(self + 0x44));
        int ok = 0;
        if (*(unsigned int*)rider < 10 && *(int*)(rider + 0xCB8) != 0) {
            ok = *(int*)(rider + 0xCB4) != 0;
        }
        if (ok) {
            *(int*)(rider + 0xCCC) = 1;
            void* anim = *(void**)(rider + 0xC);
            if (anim != 0) {
                func_00311A50(anim);
                cRiderAnimBase_play(anim, 0x1B4, 0, -1.0f);
            }
            sQuat_184C60 pos;
            sXform_184C60 xf;
            {
                sQuat_184C60 p;
                p.x = -228.0f;
                p.y = -205.0f;
                p.z = 63.0f;
                p.w = 1.0f;
                pos = p;
                xf.pos = p;
                *(int*)(self + 0x48) = 1;
                xf.rot.x = 0.0f;
                xf.rot.y = 0.0f;
                xf.rot.z = 0.0f;
                xf.rot.w = 1.0f;
                xf.rot = QuatMul_184C60(xf.rot, AxisAngle_184C60(D_004FF140, 0.0f));
            }
            xf.rot = QuatMul_184C60(xf.rot, AxisAngle_184C60(D_004FF150, 0.0f));
            xf.rot = QuatMul_184C60(xf.rot, AxisAngle_184C60(D_004FF160, 1.082104206085205f));
            func_0019F3E8(rider, &xf);
            func_001A0570(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)(self + 0x44), 1);
        }
    }
    func_0039E510(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00184F40);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern "C" int func_00150B48(void* self, int a, int b, int amount);
extern "C" int func_0014FE08(void* self, int rider, int idx, int bit);
extern "C" void func_00184520(void* self);
extern "C" void cWScriptMan_checkGate(void* self);
extern char D_0045D930[];
extern char D_0045DA70[];

struct sVE_4F40 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_00184F40(void* self, void* item, int msg)
{
    switch (msg) {
    case 0x15:
        break;
    case 0x16:
        if (*(int*)((char*)item + 0x6C) != 0) {
            int charID = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)((char*)self + 0x44));
            func_00150B48(cBE_getInterface_Fv(cBE_getBE(), 0xB), *(signed char*)((char*)self + 0x44), charID, *(int*)((char*)item + 0x48));
            int a = *(signed char*)(*(char**)(*(char**)((char*)self + 0x4C) + 0xA0) + 0x18);
            int b = *(signed char*)(*(char**)(*(char**)((char*)self + 0x50) + 0xA0) + 0x18);
            void* pi = cBE_getInterface_Fv(cBE_getBE(), 6);
            func_0014FE08(pi, *(signed char*)((char*)self + 0x44), a, b);
            sVE_4F40* vt = *(sVE_4F40**)((char*)pi + 0xC);
            vt[1].fn((char*)pi + vt[1].delta);
            void* t = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D930));
            if (t != 0) {
                cUIText_setUnicodeStringByID((cUIText*)t, GetHashValue32(D_0045DA70));
            }
            func_00184520(self);
        }
        cWScriptMan_checkGate(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", cFEStateUberTrick_onWidgetCreate);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_004A1468[];
extern char D_004A1470[];
extern char D_004A1478[];
extern char D_004A1480[];
extern char D_0045DA88[];
extern char D_0045DA98[];
extern char D_004A1488[];
extern char D_004A1490[];
extern char D_004A1498[];
extern char D_0045DAA8[];
extern char D_004A14A0[];
extern char D_0045DAB8[];
extern char D_004A14A8[];
extern char D_0045DAC8[];
extern char D_0045DA18[];

static inline int Is_185080(int id, char* s)
{
    return id == GetHashValue32(s);
}

extern "C" void cFEStateUberTrick_onWidgetCreate(void* self, void* widget)
{
    cUIText* text = (cUIText*)widget;
    for (int i = 0; i < 6; i++) {
        if (Is_185080(*(int*)((char*)widget + 0x38), D_004A1468)) {
            cUIText_setAsciiString(text, D_004A1470);
            *(int*)((char*)widget + 0x18) = 1;
            return;
        }
        if (Is_185080(*(int*)((char*)widget + 0x38), D_004A1478)) {
            cUIText_setAsciiString(text, D_004A1480);
            *(int*)((char*)widget + 0x18) = 3;
            return;
        }
        if (Is_185080(*(int*)((char*)widget + 0x38), D_0045DA88)) {
            cUIText_setAsciiString(text, D_0045DA98);
            *(int*)((char*)widget + 0x18) = 2;
            return;
        }
        if (Is_185080(*(int*)((char*)widget + 0x38), D_004A1488)) {
            cUIText_setAsciiString(text, D_004A1490);
            *(int*)((char*)widget + 0x18) = 0;
            return;
        }
        if (Is_185080(*(int*)((char*)widget + 0x38), D_004A1498)) {
            cUIText_setAsciiString(text, D_0045DAA8);
            *(int*)((char*)widget + 0x18) = 4;
            return;
        }
        if (Is_185080(*(int*)((char*)widget + 0x38), D_004A14A0)) {
            cUIText_setAsciiString(text, D_0045DAB8);
            *(int*)((char*)widget + 0x18) = 9;
            return;
        }
    }
    if (Is_185080(*(int*)((char*)widget + 0x38), D_004A14A8)) {
        *(int*)((char*)widget + 0x18) = -1;
    } else if (Is_185080(*(int*)((char*)widget + 0x38), D_0045DAC8)) {
        *(void**)((char*)self + 0x4C) = widget;
    } else if (Is_185080(*(int*)((char*)widget + 0x38), D_0045DA18)) {
        *(void**)((char*)self + 0x50) = widget;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00185268);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern "C" void cFEStateUberTrick_costVisible(void* self, int on);
extern "C" void cFEStateUberTrick_trickVisible(void* self, int on);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void cRiderAnimBase_play(void* anim, int id, int a2, float t);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" void cUIStateBuyPopup_initBuyTrick(void* popup, int trick, int cost, int points);
extern "C" void cWScriptMan_checkGate(void* self);
extern "C" int func_00116938(int id);
extern "C" void func_0014FD80(void* iface, int rider, int a, int b);
struct sTrick_185268;
extern "C" sTrick_185268* func_0014FF90(void* iface, int rider, int a, int* out);
extern "C" int func_0014FFB8(void* iface, int rider, int a, int b);
extern "C" int func_00150048(void* iface, int rider, int a, int b);
extern "C" int func_00150928(void* iface, int a1, int charID);
extern "C" void func_00183B08(void* self);
extern "C" void func_00183C08(void* self);
extern "C" void func_00184520(void* self);
extern "C" void func_00184780(void* self, int on);
extern "C" void* func_001A0548(void* self, int idx);
extern "C" void* func_001CABA8(void* mem, void* owner, void* state, int a3);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern void* D_004A28A8;
extern signed char D_00535C11[];
extern char D_004A14A8[];
extern char D_0045D920[];
extern char D_0045D930[];
extern char D_0045DA70[];
extern char D_0045DAD8[];
extern char D_0045DAE8[];
extern char D_0045DB00[];
extern char D_0045DB18[];
extern char D_0045DB30[];
extern char D_0045DB48[];

struct sVE_185268 {
    short delta;
    short index;
    void* fn;
};
struct sSnd_185268 {
    sVE_185268* vt;
};
extern sSnd_185268 D_004A5A58;

struct sColor_185268 {
    float a, r, g, b;
    sColor_185268(float a_, float r_, float g_, float b_) : a(a_), r(r_), g(g_), b(b_) {}
};
class cUIObj_185268 {
public:
    char pad[0x8];
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
    virtual void SetColor(const sColor_185268& c);
};

struct sTrick_185268 {
    unsigned short anim;
    unsigned short f2;
    unsigned short id;
    unsigned short cost;
};

static inline int Is_185268(int id, char* s)
{
    return id == GetHashValue32(s);
}

static inline void SetActive_185268(char* menu, int on)
{
    sVE_185268* vt = *(sVE_185268**)(menu + 8);
    ((void (*)(void*, int))vt[7].fn)(menu + vt[7].delta, on);
}

static inline void PlaySound_185268(char* self, int id)
{
    sSnd_185268* snd = *(sSnd_185268**)(*(char**)(self + 0x10) + 0x14);
    if (snd == 0)
        snd = &D_004A5A58;
    if (snd != 0)
        ((void (*)(void*, int))snd->vt[2].fn)((char*)snd + snd->vt[2].delta, id);
}

static inline void Back_185268(char* self)
{
    char* mgr = **(char***)(self + 0x10);
    sVE_185268* vt = *(sVE_185268**)(mgr + 4);
    void* r = ((void* (*)(void*, void*, int))vt[5].fn)(mgr + vt[5].delta, self, 0);
    if (r != 0)
        func_0039F400(*(char**)(self + 0x10) + 0x18, r);
}

extern "C" void func_00185268(char* self, char* item, int msg)
{
    switch (msg) {
    case 5:
        if (*(char**)(item + 0x40) == *(char**)(self + 0x4C)) {
            if (Is_185268(*(int*)(item + 0x38), D_004A14A8)) {
                Back_185268(self);
            } else {
                SetActive_185268(*(char**)(self + 0x4C), 0);
                cUIMenu_setSelectedByIndex(*(void**)(self + 0x50), 0);
                SetActive_185268(*(char**)(self + 0x50), 1);
                func_00183C08(self);
                cFEStateUberTrick_costVisible(self, 1);
                func_00184780(self, 1);
            }
        } else if (*(char**)(item + 0x40) == *(char**)(self + 0x50)) {
            char* a = *(char**)(*(char**)(self + 0x4C) + 0xA0);
            char* b = *(char**)(*(char**)(self + 0x50) + 0xA0);
            if (a != 0 && b != 0) {
                int ai = *(signed char*)(a + 0x18);
                int bi = *(signed char*)(b + 0x18);
                char* pi = (char*)cBE_getInterface_Fv(cBE_getBE(), 6);
                cBE_getInterface_Fv(cBE_getBE(), 0);
                if (func_00150048(pi, *(signed char*)(self + 0x44), ai, bi) && !func_0014FFB8(pi, *(signed char*)(self + 0x44), ai, bi)) {
                    func_0014FD80(pi, *(signed char*)(self + 0x44), ai, bi);
                    sVE_185268* vt = *(sVE_185268**)(pi + 0xC);
                    ((int (*)(void*))vt[1].fn)(pi + vt[1].delta);
                    cWScriptMan_checkGate(self);
                } else if (D_00535C11[0] != 0) {
                    PlaySound_185268(self, 4);
                } else if (func_0014FFB8(pi, *(signed char*)(self + 0x44), ai, bi)) {
                    char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
                    signed char charID = cBENewPlayerInterface_getPlayerCharID(player, *(signed char*)(self + 0x44));
                    {
                        sVE_185268* vt = *(sVE_185268**)(player + 0xC);
                        ((void (*)(void*))vt[2].fn)(player + vt[2].delta);
                    }
                    int points = func_00150928(cBE_getInterface_Fv(cBE_getBE(), 0xB), *(signed char*)(self + 0x44), charID);
                    int n;
                    sTrick_185268* tbl = func_0014FF90(pi, *(signed char*)(self + 0x44), ai, &n);
                    int trick = func_00116938(tbl[bi].id);
                    if (points >= tbl[bi].cost) {
                        void* popup = func_001CABA8(cMemMan_alloc(0x70, D_0045DAD8, 0x100, 0), *(void**)(self + 0x10), self, *(signed char*)(self + 0x44));
                        cUIStateBuyPopup_initBuyTrick(popup, trick, tbl[bi].cost, points);
                        func_0039F290(*(char**)(self + 0x10) + 0x18, popup);
                    } else {
                        PlaySound_185268(self, 4);
                    }
                }
            }
        }
        break;
    case 6:
        if (*(char**)(item + 0x40) == *(char**)(self + 0x50)) {
            SetActive_185268(*(char**)(self + 0x4C), 1);
            SetActive_185268(*(char**)(self + 0x50), 0);
            {
                cUIObj_185268* o = *(cUIObj_185268**)(*(char**)(self + 0x50) + 0xA0);
                if (o != 0)
                    o->SetColor(sColor_185268(1.0f, 0.0f, 0.0f, 0.0f));
            }
            cUIMenu_setSelectedByIndex(*(void**)(self + 0x50), 0xFF);
            func_00183B08(self);
            cFEStateUberTrick_costVisible(self, 0);
            func_00184780(self, 0);
        } else {
            Back_185268(self);
        }
        break;
    case 7:
        if (*(char**)(item + 0x40) == *(char**)(self + 0x50)) {
            char* a = *(char**)(*(char**)(self + 0x4C) + 0xA0);
            char* b = *(char**)(*(char**)(self + 0x50) + 0xA0);
            if (a != 0 && b != 0) {
                char* pi = (char*)cBE_getInterface_Fv(cBE_getBE(), 6);
                int bi = *(signed char*)(b + 0x18);
                int ai = *(signed char*)(a + 0x18);
                int n = 0;
                sTrick_185268* tbl = func_0014FF90(pi, *(signed char*)(self + 0x44), ai, &n);
                if (*(int*)(self + 0x48) != 0) {
                    char* r = (char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)(self + 0x44));
                    cRiderAnimBase_play(*(void**)(r + 0xC), tbl[bi].anim, 0, -1.0f);
                }
            }
        }
        break;
    case 1:
        *(int*)((char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)(self + 0x44)) + 0xCD0) = 1;
        if (*(char**)(item + 0x40) == *(char**)(self + 0x4C)) {
            if (*(void**)(self + 0x50) != 0 && *(int*)(item + 0x18) != -1) {
                cFEStateUberTrick_trickVisible(self, 1);
                cWScriptMan_checkGate(self);
                cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0045D920));
                if (t != 0)
                    cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DAE8));
            } else {
                cFEStateUberTrick_trickVisible(self, 0);
                cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0045D920));
                if (t != 0)
                    cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DB00));
            }
        } else if (*(char**)(self + 0x50) != 0 && *(char**)(item + 0x40) == *(char**)(self + 0x50)) {
            cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0045D930));
            char* a = *(char**)(*(char**)(self + 0x4C) + 0xA0);
            char* b = *(char**)(*(char**)(self + 0x50) + 0xA0);
            if (a != 0 && b != 0 && t != 0) {
                int ai = *(signed char*)(a + 0x18);
                int bi = *(signed char*)(b + 0x18);
                char* pi = (char*)cBE_getInterface_Fv(cBE_getBE(), 6);
                cBE_getInterface_Fv(cBE_getBE(), 0);
                if (func_00150048(pi, *(signed char*)(self + 0x44), ai, bi) && !func_0014FFB8(pi, *(signed char*)(self + 0x44), ai, bi)) {
                    cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DA70));
                } else if (D_00535C11[0] == 0) {
                    if (func_0014FFB8(pi, *(signed char*)(self + 0x44), ai, bi)) {
                        char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
                        signed char charID = cBENewPlayerInterface_getPlayerCharID(player, *(signed char*)(self + 0x44));
                        {
                            sVE_185268* vt = *(sVE_185268**)(player + 0xC);
                            ((void (*)(void*))vt[2].fn)(player + vt[2].delta);
                        }
                        int points = func_00150928(cBE_getInterface_Fv(cBE_getBE(), 0xB), *(signed char*)(self + 0x44), charID);
                        int n;
                        sTrick_185268* tbl = func_0014FF90(pi, *(signed char*)(self + 0x44), ai, &n);
                        if (points >= tbl[bi].cost)
                            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DB18));
                        else
                            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DB30));
                    }
                } else {
                    cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DB48));
                }
                func_00184520(self);
            }
        }
        break;
    case 2:
        *(int*)((char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)(self + 0x44)) + 0xCD0) = 0;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_001859D8);
#ifdef SKIP_ASM
extern "C" int func_001859D8(void* self, int a1, unsigned int a2)
{
    if (a1 == *(int*)((char*)self + 0x50)) {
        switch (a2) {
        case 9:
            return 0x100;
        }
    } else {
        switch (a2) {
        case 8:
        case 9:
            return 0x100;
        }
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festatestore", func_00185A18);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern void* D_0046BDF8[];

extern "C" void* func_00185A18(void* self)
{
    func_0039E2A0(self);
    *(void***)((char*)self + 0x8) = D_0046BDF8;
    *(int*)((char*)self + 0x60) = -100;
    *(int*)((char*)self + 0x64) = 1;
    *(int*)((char*)self + 0xC) = 0x24;
    *(int*)((char*)self + 0x58) = 0;
    *(int*)((char*)self + 0x5C) = 0;
    *(int*)((char*)self + 0x48) = 0;
    return self;
}
#endif

extern void* D_0046D0D0[];
extern "C" void* func_0039E390(void*);

//100%
INCLUDE_ASM("fe/festatestore", func_00185A70__FPv);
#ifdef SKIP_ASM
void* func_00185A70(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    return func_0039E390(self);
}
#endif

