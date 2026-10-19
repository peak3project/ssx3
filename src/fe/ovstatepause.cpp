#include "common.h"
#include "ai/rider.h"

INCLUDE_ASM("fe/ovstatepause", cOVState_PAUSE_OPTIONS_onCreateScreen);

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FA100);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_00194498(void* obj);
extern void* D_004A28A8;
extern int D_00534B30[];
extern char D_00535BC8[];
extern char D_004A24E0[];
extern char D_0046F970[];
extern char D_004A24A8[];
extern char D_004A24E8[];

class cUIObj_FA100 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};

static inline bool isField_FA100(signed char* g, int off, int v)
{
    return g[off] == v;
}

extern "C" void func_001FA100(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0 || !isField_FA100((signed char*)D_00535BC8, 0x49, 2)) {
        cUIObj_FA100* a = (cUIObj_FA100*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A24E0));
        if (a != 0) {
            a->setEnabled(1);
        }
        void* b = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046F970));
        if (b != 0) {
            func_00194498(b);
        }
        void* c = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A24A8));
        if (c != 0) {
            func_00194498(c);
        }
    }
    if (!isField_FA100((signed char*)D_00535BC8, 0x48, 4)) {
        void* d = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A24E8));
        if (d != 0) {
            func_00194498(d);
        }
    }
}
#endif

INCLUDE_ASM("fe/ovstatepause", func_001FA238);

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FA9E0);
#ifdef SKIP_ASM
struct cUIScreen;
int GetHashValue32(char* str);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* func_0020E900(void* self);
extern "C" void func_0039F190(void* self, int a1);
extern void* D_004A2EEC;
extern char D_0046E050[];

extern "C" void func_001FA9E0(void* self)
{
    func_0020E900(self);
    char* p = (char*)D_004A2EEC;
    if (p != 0) {
        int ok = *(int*)(p + 0x68) == 0 || *(int*)(p + 0x64) == 0;
        if (ok) {
            int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_0046E050));
            if (frame != 0xFFFF) {
                cUIScreen_playFrame(*(void**)((char*)self + 0x40), (unsigned short)frame, 1);
            }
            func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FAA78);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_00397870(void* list, int index);
extern char D_004A24E8[];

// Pause-menu key filter: returns 0x100 for keys 8/9 and for key 6 unless the item is D_004A24E8, else 0x101.
extern "C" int func_001FAA78(void* self, void* menu, unsigned int key, int index)
{
    switch (key) {
    case 6: {
        int id = *(int*)((char*)func_00397870((char*)menu + 0x74, index) + 0x38);
        if (id == GetHashValue32(D_004A24E8)) {
            break;
        }
    }
    case 8:
    case 9:
        return 0x100;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FAAF0);
#ifdef SKIP_ASM
extern "C" int func_001FAAF0(void* self, int a1, int a2)
{
    return a2 != 4 ? 0x101 : 0x100;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FAB08);
#ifdef SKIP_ASM
extern "C" int func_001FAB08(void* self, int a1, int a2)
{
    return a2 != 0 ? 0x101 : 0x100;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", cOVState_PAUSE_ONLINE_ERROR_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0020A380(void* self);
extern "C" void func_001FAFF8(void* self, bool on);
extern "C" void cOVState_PAUSE_ONLINE_ERROR_setContinueOptionVisible(void* self, int visible);
extern "C" void func_002583A8(void* self, int a1, int a2);
extern void* D_004A2EEC;
extern void* D_004A3028;
extern void* D_004A5B64;
extern char D_0046F9D0[];
extern char D_0046F9E0[];
extern char D_0046F9F0[];
extern char D_0046FA08[];
extern char D_0046FA18[];
extern char D_0046FA38[];
extern char D_0046FA58[];
extern char D_0046FA78[];
extern char D_0046FA90[];
extern char D_0046FAA0[];
extern char D_0046FAB0[];
extern char D_0046FAC8[];
extern char D_0046FAD8[];
extern char D_0046FAE8[];
extern char D_0046FB00[];
extern char D_0046FB18[];
extern char D_0046FB28[];

class cUIObj_1FAB18 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int v);
};

extern "C" void cOVState_PAUSE_ONLINE_ERROR_onCreateScreen(void* self)
{
    char* s = (char*)self;
    void* eng = *(void**)(s + 0x10);
    void* scr = cUIEngine_addScreenByHashName(eng, self, GetHashValue32(D_0046F9D0), 0);
    *(void**)(s + 0x40) = scr;
    if (scr != 0) {
        cUIScreen_playFrame(scr, 0, 0);
    }
    func_0020A380(self);
    cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046F9E0));
    if (t != 0) {
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_0046F9F0));
    }
    cUIObj_1FAB18* o = (cUIObj_1FAB18*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046FA08));
    if (o != 0) {
        o->setVisible(1);
        char* p = (char*)D_004A2EEC;
        *(int*)((char*)o + 0x14) |= 0x80;
        int e = *(int*)(p + 0x24);
        int one = 1;
        if (e != 0) {
            if (e == one) {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA18));
            } else if (e == 2) {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA18));
            } else if (e == 3) {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA18));
            } else {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA38));
            }
        } else if (*(int*)(p + 0x28) != 0) {
            *(int*)(s + 0xA0) = 0;
            int e2 = *(int*)(p + 0x28);
            if (e2 == one) {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA58));
            } else if (e2 == 2) {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA58));
            } else if (e2 == 3) {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA58));
            } else {
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA58));
            }
        } else if (*(int*)(p + 0x8C) != 0) {
            cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA78));
            *(int*)(s + 0xA0) = 0;
        } else if (*(int*)(p + 0x14) != 0) {
            *(int*)(s + 0xA0) = 0;
            cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA78));
        } else {
            *(int*)(s + 0xA0) = 0;
            cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FA58));
        }
        cUIObj_1FAB18* o2 = (cUIObj_1FAB18*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046FA90));
        if (o2 != 0) {
            if (*(int*)((char*)D_004A2EEC + 0xA0) != 0) {
                cUIText_setUnicodeStringByID((cUIText*)o2, GetHashValue32(D_0046FAA0));
            } else {
                cUIText_setUnicodeStringByID((cUIText*)o2, GetHashValue32(D_0046FAB0));
            }
            o2->setVisible(0);
            *(int*)((char*)o2 + 0x18) = 0;
        }
        o2 = (cUIObj_1FAB18*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046FAC8));
        if (o2 != 0) {
            o2->setVisible(0);
        }
        o2 = (cUIObj_1FAB18*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046FAD8));
        if (o2 != 0) {
            o2->setVisible(0);
        }
        o2 = (cUIObj_1FAB18*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046FAE8));
        if (o2 != 0) {
            o2->setVisible(0);
        }
        o2 = (cUIObj_1FAB18*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046FB00));
        if (o2 != 0) {
            o2->setVisible(0);
        }
        cOVState_PAUSE_ONLINE_ERROR_setContinueOptionVisible(self, 0);
    }
    if (D_004A2EEC != 0) {
        func_002583A8(D_004A2EEC, *(int*)((char*)D_004A3028 + 4), 3);
        *(int*)(s + 0x9C) = *(int*)((char*)D_004A5B64 + 0x18);
        func_001FAFF8(self, 0);
        cUIText* t2 = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_0046FB18));
        if (t2 != 0) {
            cUIText_setUnicodeStringByID(t2, GetHashValue32(D_0046FB28));
        }
    } else {
        func_001FAFF8(self, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FAF08__FPv);
#ifdef SKIP_ASM
int func_001FAF08(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FAF10);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* func_0020E900(void* self);
extern "C" void func_001FAFF8(void* self, bool on);
extern "C" void cOVState_PAUSE_ONLINE_ERROR_displayPingTimedOut(void* self);
extern "C" void cOVState_PAUSE_ONLINE_ERROR_displayPingReceived(void* self);
extern void* D_004A2EEC;
extern char D_0046FB18[];

class cUIObj_1FAF10 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int v);
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};

extern "C" void func_001FAF10(void* self)
{
    func_0020E900(self);
    char* p = (char*)D_004A2EEC;
    if (p != 0 && *(int*)((char*)self + 0x9C) != 0) {
        int timedOut = *(int*)(p + 0x138) <= 0 && *(int*)(p + 0x13C) == 0;
        if (timedOut) {
            *(int*)(p + 0x9C) = 0;
            cOVState_PAUSE_ONLINE_ERROR_displayPingTimedOut(self);
        } else {
            if (*(int*)(p + 0x13C) == 0) {
                return;
            }
            int received = *(int*)(p + 0x80) != 0 && *(int*)(p + 0xA0) == 0 && *(int*)(p + 0x24) == 0;
            if (received) {
                cOVState_PAUSE_ONLINE_ERROR_displayPingReceived(self);
            } else {
                ((cUIObj_1FAF10*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FB18)))->setVisible(0);
            }
        }
        func_001FAFF8(self, 1);
        *(int*)((char*)self + 0x9C) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FAFF8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0046FA90[];
extern char D_004A2470[];
extern "C" void cUIMenu_setSelectedByIndex(void* menu, int index);

class cUIObj_1FAFF8 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int v);
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};

extern "C" void func_001FAFF8(void* self, bool on)
{
    cUIObj_1FAFF8* o = (cUIObj_1FAFF8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FA90));
    o->setVisible(on);
    o->setEnabled(!on);
    if (on) {
        cUIObj_1FAFF8* m = (cUIObj_1FAFF8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2470));
        m->v07(1);
        cUIMenu_setSelectedByIndex(m, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FB0C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001FB2B8(void* self, void* item, int msg);
extern "C" void func_001FB458(void* self, int on);
extern "C" void func_001FB588(void* self, int on);
extern char D_0046FA90[];
extern char D_0046FB48[];

extern "C" void func_001FB0C0(void* self, void* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5:
        func_001FB2B8(self, item, msg);
        break;
    case 1: {
        int id = *(int*)((char*)item + 0x38);
        if (id == GetHashValue32(D_0046FA90)) {
            func_001FB588(self, 1);
            func_001FB458(self, 0);
        } else {
            int id2 = *(int*)((char*)item + 0x38);
            if (id2 == GetHashValue32(D_0046FB48)) {
                func_001FB458(self, 1);
                func_001FB588(self, 0);
            }
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", cOVState_PAUSE_ONLINE_ERROR_displayPingTimedOut);
#ifdef SKIP_ASM
struct cUIText;
struct sVE_FB180 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_0046FB18[];
extern char D_0046FB60[];

extern "C" void cOVState_PAUSE_ONLINE_ERROR_displayPingTimedOut(void* self)
{
    if (*(void**)((char*)self + 0x40) != 0) {
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FB18));
        if (t != 0 && *(int*)((char*)self + 0xA0) != 0) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0046FB60));
        }
        sVE_FB180* vt = *(sVE_FB180**)((char*)t + 0x8);
        vt[9].fn((char*)t + vt[9].delta, *(int*)((char*)self + 0xA0));
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", cOVState_PAUSE_ONLINE_ERROR_displayPingReceived);
#ifdef SKIP_ASM
struct cUIText;
struct sVE_FB218 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void cOVState_PAUSE_ONLINE_ERROR_setContinueOptionVisible(void* self, int visible);
extern char D_0046FB18[];
extern char D_0046FB88[];

extern "C" void cOVState_PAUSE_ONLINE_ERROR_displayPingReceived(void* self)
{
    if (*(void**)((char*)self + 0x40) != 0) {
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FB18));
        if (t != 0 && *(int*)((char*)self + 0xA0) != 0) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0046FB88));
        }
        sVE_FB218* vt = *(sVE_FB218**)((char*)t + 0x8);
        vt[9].fn((char*)t + vt[9].delta, *(int*)((char*)self + 0xA0));
        cOVState_PAUSE_ONLINE_ERROR_setContinueOptionVisible(self, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FB2B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void cGame_exit(void* game, int a);
extern "C" void func_0012B340(void* p);
// func_0039F190 returns its last list node in $v0; the unit declares it void.
void* func_0039F190_r(void* self, int a1) __asm__("func_0039F190");
extern void* D_004A28A8;
extern int D_004A2A50;
extern int D_004A2A54;
extern int D_005366E8[];
extern int D_004428F0[];

extern "C" void func_001FB2B8(void* self, void* item, int msg)
{
    func_0039F190_r(*(char**)((char*)self + 0x10) + 0x18, 1);
    *(int*)((char*)self + 0x1C) = (*(int*)((char*)self + 0x1C) & ~0x3F00) | 0x780;
    switch (*(int*)((char*)item + 0x18)) {
    case 4:
        func_0012B340(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
        D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
        break;
    case 0:
    default:
        cGame_exit(*(void**)((char*)D_004A28A8 + 0x84), 0);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", cOVState_PAUSE_ONLINE_ERROR_setContinueOptionVisible);
#ifdef SKIP_ASM
extern char D_0046FB48[];
extern char D_0046FBB0[];
extern char D_004A2470[];
extern "C" void cUIMenu_setSelectedByIndex(void* menu, int index);

class cUIObj_1FB378 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};

extern "C" void cOVState_PAUSE_ONLINE_ERROR_setContinueOptionVisible(void* self, int visible)
{
    cUIObj_1FB378* t = (cUIObj_1FB378*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FB48));
    if (t != 0) {
        cUIText_setUnicodeStringByID((cUIText*)t, GetHashValue32(D_0046FBB0));
        t->setEnabled(visible ^ 1);
        t->setVisible(visible);
        *(int*)((char*)t + 0x18) = 4;
    }
    t = (cUIObj_1FB378*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2470));
    if (t != 0 && visible) {
        cUIMenu_setSelectedByIndex(t, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FB458);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0046FB48[];
extern char D_0046FAD8[];
extern char D_0046FB00[];

struct sColor_FB458 {
    float r, g, b, a;
    sColor_FB458(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

class cUIObj_FB458 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
    virtual void v10();
    virtual int setColor(const sColor_FB458& c);
};

extern "C" void func_001FB458(void* self, int on)
{
    cUIObj_FB458* t = (cUIObj_FB458*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FB48));
    cUIObj_FB458* a = (cUIObj_FB458*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FAD8));
    cUIObj_FB458* b = (cUIObj_FB458*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FB00));
    if (on) {
        t->setColor(sColor_FB458(1.0f, 1.0f, 1.0f, 1.0f));
    } else {
        t->setColor(sColor_FB458(1.0f, 0.0f, 0.0f, 0.0f));
    }
    a->setVisible(on);
    b->setVisible(on);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FB588);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0046FA90[];
extern char D_0046FAC8[];
extern char D_0046FAE8[];

struct sColor_FB588 {
    float r, g, b, a;
    sColor_FB588(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

class cUIObj_FB588 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
    virtual void v10();
    virtual int setColor(const sColor_FB588& c);
};

extern "C" void func_001FB588(void* self, int on)
{
    cUIObj_FB588* t = (cUIObj_FB588*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FA90));
    cUIObj_FB588* a = (cUIObj_FB588*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FAC8));
    cUIObj_FB588* b = (cUIObj_FB588*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FAE8));
    if (on) {
        t->setColor(sColor_FB588(1.0f, 1.0f, 1.0f, 1.0f));
    } else {
        t->setColor(sColor_FB588(1.0f, 0.0f, 0.0f, 0.0f));
    }
    a->setVisible(on);
    b->setVisible(on);
}
#endif

INCLUDE_ASM("fe/ovstatepause", func_001FB6B8);

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FBBD8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int idx);
extern "C" void func_0020A6F0(void* self, char* text, char* label);
extern "C" void func_0039E4C0(void* self);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004A2170[];
extern char D_0046E4E8[];
extern signed char D_00535C11[];
extern void* D_004A2EEC;

extern "C" void func_001FBBD8(void* self)
{
    char buf[32];
    func_0039E4C0(self);
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    sprintf(buf, D_004A2170, func_00146E98(iface, 0) + 1);
    func_0020A6F0(self, buf, D_0046E4E8);
    if (D_00535C11[0] == 2) {
        sprintf(buf, D_004A2170, func_00146E98(iface, 1) + 1);
        func_0020A6F0(self, buf, D_0046E4E8);
    }
    char* p = (char*)D_004A2EEC;
    if (p != 0) {
        *(int*)(p + 0x64) = 0x4B0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FBCC8);
#ifdef SKIP_ASM
extern void* D_004A2EEC;

extern "C" void func_001FBCC8(void)
{
    char* p = (char*)D_004A2EEC;
    if (p != 0) {
        *(int*)(p + 0x64) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FBCE0);
#ifdef SKIP_ASM
extern void* D_004A2EEC;
extern int D_004A26FC;
extern "C" void* func_0020E900(void* self);

extern "C" void func_001FBCE0(void* self)
{
    func_0020E900(self);
    char* p = (char*)D_004A2EEC;
    if (p != 0 && *(int*)(p + 0x64) == 0) {
        *(int*)(p + 0x64) = -1;
        D_004A26FC = 1;
    }
}
#endif

INCLUDE_ASM("fe/ovstatepause", func_001FBD20);

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FC768);
#ifdef SKIP_ASM
extern "C" void func_0039E4C0(void* self);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0020A6F0(void* self, char* text, char* label);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);
extern "C" void func_002A31C0(void* self);
extern void* D_004A28A8;
extern signed char D_00535C11[];
extern char D_0046E4E8[];
extern char D_004A2508[];
extern char D_004A2510[];
extern char D_004A2518[];
extern char D_0046FDF8[];
extern char D_0046FDD8[];

extern "C" void func_001FC768(void* self)
{
    func_0039E4C0(self);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int* mode = *(int**)((char*)D_004A28A8 + 0xC0);
    func_0020A6F0(self, D_004A2508, D_0046E4E8);
    if (*mode == 2) {
        func_0020A6F0(self, D_0046FDF8, D_0046E4E8);
    } else {
        func_0020A6F0(self, D_004A2510, D_0046E4E8);
    }
    if (D_00535C11[0] == 2) {
        func_0020A6F0(self, D_004A2518, D_0046E4E8);
        func_0020A6F0(self, D_0046FDD8, D_0046E4E8);
    }
    func_00294F78(func_0028B180(), 0xE);
    func_002A31C0(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FC878);
#ifdef SKIP_ASM
// self is a pause-menu UI state (no header yet): +0x10 its UI engine, +0x40 its screen.
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
void cUIText_setAsciiString(cUIText* text, const char* s);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void func_0020A380(void* self);
extern "C" char* func_00144BF0(void* iface);
extern "C" int func_00146E98(void* iface, int idx);
extern "C" char* func_00146F88(void* iface, int idx);
extern "C" char* func_0014EE58(void* iface, int id);
extern "C" void* func_00155130(void* iface, int idx);
extern "C" char* func_0020A1A8(void* p);
extern "C" void func_002C2540(unsigned short* dst, char* src);
extern "C" int func_002C27C0(unsigned short* buf, unsigned short* fmt, ...);
extern "C" void func_002C26D0(unsigned short* dst, unsigned short* fmt, ...);
extern "C" void func_003A0E90(void* obj, unsigned short* s);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern char D_00535BC8[];
extern char D_0046FE08[];
extern char D_0046E378[];
extern char D_004A21B0[];
extern char D_0046FC08[];
extern char D_004A21B8[];
extern char D_0046E398[];
extern char D_0046E3A8[];
extern char D_0046E3C0[];
extern char D_0046E548[];
extern unsigned short D_0046E558[];
extern unsigned short D_004A2140[];
extern char D_004A2520[];
extern char D_004A2528[];
extern char D_004A2530[];
extern char D_004A2538[];
extern char D_0046FD38[];
extern char D_0046FD58[];
extern char D_0046FE18[];
extern char D_004A2540[];
extern char D_0046FE28[];
extern char D_0046E888[];
extern char D_0046FE38[];
extern char D_0046FE50[];
extern char D_0046FE70[];
extern char D_0046FE80[];
extern char D_0046FE98[];
extern char D_0046FDE8[];
extern char D_004A2138[];

struct sVE_1FC878 { short delta; short index; unsigned short* (*fn)(void*, int); };

static inline unsigned short* lookupString_1FC878(char* name)
{
    char* g = *(char**)((char*)D_004A28A8 + 0x8C);
    sVE_1FC878* vt = *(sVE_1FC878**)(g + 4);
    char* t = g + vt[4].delta;
    return vt[4].fn(t, GetHashValue32(name));
}

static inline int getField_1FC878(signed char* g, int off)
{
    return g[off];
}

static inline bool isField_1FC878(signed char* g, int off, int v)
{
    return g[off] == v;
}

static inline void* getObj_1FC878(void* self, char* name)
{
    return cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

extern "C" void func_001FC878(void* self)
{
    unsigned short title[0x38];
    unsigned short line[0x68];
    char rider[0x20];
    unsigned short label[0x130];
    char num[0x20];
    char* s = (char*)self;
    void* eng = *(void**)(s + 0x10);
    void* scr = cUIEngine_addScreenByHashName(eng, self, GetHashValue32(D_0046FE08), 0);
    *(void**)(s + 0x40) = scr;
    if (scr != 0)
        cUIScreen_playFrame(scr, 0, 0);
    eng = *(void**)(s + 0x10);
    scr = cUIEngine_addScreenByHashName(eng, self, GetHashValue32(D_0046E378), 0);
    if (scr != 0)
        cUIScreen_playFrame(scr, 0, 0);
    func_0020A380(self);
    signed char* gs = (signed char*)D_00535BC8;
    void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* iface0 = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* iface2 = cBE_getInterface_Fv(cBE_getBE(), 2);
    void* iface8 = cBE_getInterface_Fv(cBE_getBE(), 8);
    int mode4A = getField_1FC878(gs, 0x4A);
    int mode48 = getField_1FC878(gs, 0x48);
    void* o = getObj_1FC878(self, D_004A21B0);
    cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FC08));
    o = getObj_1FC878(self, D_004A21B8);
    func_002C2540(title, func_00144BF0(iface0));
    unsigned short* str = 0;
    switch (getField_1FC878(gs, 0x48))
    {
    case 5:
        str = lookupString_1FC878(D_0046E548);
        break;
    case 1:
        str = lookupString_1FC878(D_0046E398);
        break;
    case 2:
        str = lookupString_1FC878(D_0046E3A8);
        break;
    case 3:
        str = lookupString_1FC878(D_0046E3C0);
        break;
    }
    unsigned short* lineFmt = D_004A2140;
    if (mode48 == 6)
        func_002C27C0(line, D_0046E558, title, str);
    else
        func_002C27C0(line, lineFmt, title);
    func_003A0E90(o, line);
    o = getObj_1FC878(self, D_004A2520);
    if (getField_1FC878((signed char*)D_00535BC8, 0x49) == 2)
        cUIText_setAsciiString((cUIText*)o, func_00146F88(iface1, 0));
    else
        cUIText_setAsciiString((cUIText*)o, func_0014EE58(iface2, func_00146E98(iface1, 0)));
    cUIText* status = (cUIText*)getObj_1FC878(self, D_004A2528);
    if (mode48 >= 1 && mode48 <= 3)
    {
        cUIState_showObjSafe(self, D_004A2530);
        cUIState_showObjSafe(self, D_004A2538);
        o = getObj_1FC878(self, D_004A2530);
        if (mode48 == 1)
            cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FD38));
        else
            cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FD58));
    }
    else
    {
        cUIState_hideObjSafe(self, D_004A2530);
        cUIState_hideObjSafe(self, D_004A2538);
    }
    o = getObj_1FC878(self, D_004A21B0);
    cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FC08));
    if (getField_1FC878((signed char*)D_00535BC8, 0x49) == 2)
        strcpy(rider, func_00146F88(iface1, 1));
    else
        strcpy(rider, func_0014EE58(iface2, func_00146E98(iface1, 1)));
    unsigned short* fmt = lookupString_1FC878(D_0046FE18);
    func_002C26D0(label, fmt, rider);
    func_003A0E90(getObj_1FC878(self, D_004A2540), label);
    if (mode48 >= 2 && mode48 <= 3)
    {
        cUIState_hideObjSafe(self, D_0046FE28);
    }
    else if (mode48 >= 5 && mode48 <= 6)
    {
        cUIState_hideObjSafe(self, D_0046E888);
        cUIState_hideObjSafe(self, D_0046FE28);
    }
    if (mode4A == 4)
        cUIText_setUnicodeStringByID(status, GetHashValue32(D_0046FE38));
    else
        cUIText_setUnicodeStringByID(status, GetHashValue32(D_0046FE50));
    o = getObj_1FC878(self, D_0046FE70);
    if (mode4A == 4 || mode4A == 0)
    {
        cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FE80));
        void* p = func_00155130(iface8, 0);
        o = getObj_1FC878(self, D_0046FDE8);
        cUIText_setAsciiString((cUIText*)o, func_0020A1A8(p));
    }
    else
    {
        cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046FE98));
        void* p = func_00155130(iface8, 0);
        o = getObj_1FC878(self, D_0046FDE8);
        sprintf(num, D_004A2138, p);
        cUIText_setAsciiString((cUIText*)o, num);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FCEC0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern signed char D_00535C10[];
extern char D_0046E888[];
extern char D_004A2548[];
extern char D_0046FEB0[];
extern char D_0046FEC0[];

struct sVec3_1FCEC0
{
    float x, y, z;
    sVec3_1FCEC0() {}
    sVec3_1FCEC0(float a, float b, float c) : x(a), y(b), z(c) {}
};

extern "C" int func_001FCEC0(void* self, void* msg)
{
    if (msg != 0)
    {
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int mode = D_00535C10[0];
    if (mode == 2 || mode == 3)
    {
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E888));
        sVec3_1FCEC0 p = *(sVec3_1FCEC0*)(o + 0x44);
        *(sVec3_1FCEC0*)(o + 0x44) = sVec3_1FCEC0(p.x + 130.0f, p.y, p.z);
    }
    else if (mode == 5 || mode == 6)
    {
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2548));
        sVec3_1FCEC0 p = *(sVec3_1FCEC0*)(o + 0x44);
        *(sVec3_1FCEC0*)(o + 0x44) = sVec3_1FCEC0(p.x, p.y + 40.0f, p.z);
        o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FEB0));
        p = *(sVec3_1FCEC0*)(o + 0x44);
        *(sVec3_1FCEC0*)(o + 0x44) = sVec3_1FCEC0(p.x, p.y + 67.0f, p.z);
        o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046FEC0));
        p = *(sVec3_1FCEC0*)(o + 0x44);
        *(sVec3_1FCEC0*)(o + 0x44) = sVec3_1FCEC0(p.x, p.y - 48.0f, p.z);
    }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FD0D8);
#ifdef SKIP_ASM
extern void* D_004A2EEC;
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);
extern "C" void func_0039E4C0(void* self);

extern "C" void func_001FD0D8(void* self)
{
    func_0039E4C0(self);
    char* p = (char*)D_004A2EEC;
    if (p != 0) {
        *(int*)(p + 0x64) = 0x4B0;
    }
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FD118);
#ifdef SKIP_ASM
extern void* D_004A2EEC;
extern "C" void* func_0028B180();
extern "C" void func_002872A8(void* self);

extern "C" void func_001FD118(void)
{
    char* p = (char*)D_004A2EEC;
    if (p != 0) {
        *(int*)(p + 0x64) = -1;
    }
    func_002872A8(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FD150);
#ifdef SKIP_ASM
extern void* D_004A2EEC;
extern int D_004A26FC;
extern "C" void* func_0020E900(void* self);

extern "C" void func_001FD150(void* self)
{
    func_0020E900(self);
    char* p = (char*)D_004A2EEC;
    if (p != 0 && *(int*)(p + 0x64) == 0) {
        *(int*)(p + 0x64) = -1;
        D_004A26FC = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FD190);
#ifdef SKIP_ASM
extern char D_0046FED0[];
extern char D_0046FEE0[];
extern char D_0046FEF0[];
extern char D_0046FF08[];
extern char D_0046FF18[];
extern char D_0046FF28[];
struct sVEnt_1FD190 { short delta; short index; int (*fn)(void*, int); };

// Sends the hash of the named pause-menu item to the front end's screen object.
static inline int sendHash_1FD190(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEnt_1FD190* vt = *(sVEnt_1FD190**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}
extern "C" int func_001FD190(int id)
{
    switch (id) {
    case 6: return sendHash_1FD190(D_0046FED0);
    case 7: return sendHash_1FD190(D_0046FEE0);
    case 8: return sendHash_1FD190(D_0046FEF0);
    case 9: return sendHash_1FD190(D_0046FF08);
    case 10: return sendHash_1FD190(D_0046FF18);
    case 11: return sendHash_1FD190(D_0046FF28);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FD268);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void func_0020A380(void* self);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);
extern char D_0046FF58[];
extern char D_0046E378[];

extern "C" void func_001FD268(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046FF58), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    engine = *(void**)((char*)self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E378), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FD320);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getCharacterID(int idx);
extern "C" int func_00144BE0(void* iface);
extern "C" int func_00145750(void* iface);
extern "C" char* func_0014EEC8(void* iface, int id, int a2);
extern "C" int func_00146A70(void* iface, int a1, int charId, int item);
extern "C" int func_00157B08(void* iface, int a1, int a2);
extern "C" void* func_004139F8(float x);
extern "C" void func_003A0D00(void* obj, unsigned short* s);
// func_002C2540 returns dst (the unit declares it void)
unsigned short* func_002C2540_r(unsigned short* dst, char* src) __asm__("func_002C2540");
extern char D_0046E5F0[];
extern char D_0046FF68[];
extern char D_0046FF80[];
extern char D_0046FF98[];
extern char D_0046FFB0[];
extern char D_0046FFD0[];
extern char D_0046FFE0[];
extern char D_00470000[];
extern char D_0046E918[];
extern char D_004A2550[];
extern char D_00470018[];
extern char D_00470030[];
extern char D_00470048[];
extern char D_0046E950[];
extern char D_004A2558[];
extern char D_00470068[];
extern char D_00470080[];
extern char D_00470098[];

struct sVE_1FD320 { short delta; short index; unsigned short* (*fn)(void*, int); };

static inline unsigned short* lookupString_1FD320(char* name)
{
    char* g = *(char**)((char*)D_004A28A8 + 0x8C);
    sVE_1FD320* vt = *(sVE_1FD320**)(g + 4);
    char* t = g + vt[4].delta;
    return vt[4].fn(t, GetHashValue32(name));
}

static inline int getField_1FD320(signed char* g, int off)
{
    return g[off];
}

static inline void* getObj_1FD320(void* self, char* name)
{
    return cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

extern "C" int func_001FD320(void* self, void* msg)
{
    unsigned short out[0x130];
    unsigned short fmt[0x18];
    unsigned short title[0x18];
    unsigned short name[0x20];
    unsigned short line[0x190];
    unsigned short num[0x20];
    unsigned short text[0x130];
    if (msg != 0) {
        void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
        void* iface0 = cBE_getInterface_Fv(cBE_getBE(), 0);
        void* iface2 = cBE_getInterface_Fv(cBE_getBE(), 2);
        void* iface13 = cBE_getInterface_Fv(cBE_getBE(), 0xD);
        char* stats = *(char**)((char*)D_004A28A8 + 0xC0);
        int mode = getField_1FD320((signed char*)D_00535BC8, 0x4A);
        void* o = getObj_1FD320(self, D_004A2520);
        cUIText_setAsciiString((cUIText*)o, func_0014EE58(iface2, func_00146E98(iface1, 0)));
        o = getObj_1FD320(self, D_004A21B8);
        switch (mode) {
        case 4:
            func_002C2540_r(title, func_00144BF0(iface0));
            func_002C2540_r(fmt, (char*)D_004A2140);
            func_002C26D0(out, fmt, title, lookupString_1FD320(D_0046E548));
            func_003A0E90(o, out);
            break;
        case 5:
            func_002C2540_r(title, func_00144BF0(iface0));
            func_002C2540_r(fmt, (char*)D_0046E558);
            func_002C26D0(out, fmt, title);
            func_003A0E90(o, out);
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            func_003A0E90(o, (unsigned short*)func_001FD190(mode));
            break;
        }
        cUIText* statusA = (cUIText*)getObj_1FD320(self, D_004A2528);
        cUIText* statusB = (cUIText*)getObj_1FD320(self, D_004A2530);
        o = getObj_1FD320(self, D_004A21B0);
        cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046E5F0));
        func_002C2540_r(name, func_0014EEC8(iface2, func_00145750(iface0), 0));
        unsigned short* lineFmt;
        if (mode >= 4 && mode <= 5)
            lineFmt = lookupString_1FD320(D_0046FF68);
        else if (mode >= 6 && mode <= 8)
            lineFmt = lookupString_1FD320(D_0046FF80);
        else
            lineFmt = lookupString_1FD320(D_0046FF98);
        func_002C26D0(line, lineFmt, name);
        func_003A0D00(getObj_1FD320(self, D_004A2520), line);
        switch (mode) {
        case 4:
            cUIText_setUnicodeStringByID(statusA, GetHashValue32(D_0046FE38));
            cUIText_setUnicodeStringByID(statusB, GetHashValue32(D_0046FFB0));
            if (getField_1FD320((signed char*)D_00535BC8, 0x49) == 1
                || (func_00144BE0(iface0) == 0xE && !func_00146A70(iface1, 0, cBELibrary_getCharacterID(0), 6))
                || (func_00144BE0(iface0) == 0xF && !func_00146A70(iface1, 0, cBELibrary_getCharacterID(0), 7))
                || (func_00144BE0(iface0) == 0x10 && !func_00146A70(iface1, 0, cBELibrary_getCharacterID(0), 8))) {
                cUIState_hideObjSafe(self, D_004A2530);
                cUIState_hideObjSafe(self, D_004A2538);
            }
            cUIState_hideObjSafe(self, D_0046FFD0);
            break;
        case 5:
            cUIText_setUnicodeStringByID(statusA, GetHashValue32(D_0046FFE0));
            cUIText_setUnicodeStringByID(statusB, GetHashValue32(D_00470000));
            if (getField_1FD320((signed char*)D_00535BC8, 0x49) == 1
                || (func_00144BE0(iface0) == 0xE && !func_00146A70(iface1, 0, cBELibrary_getCharacterID(0), 9))
                || (func_00144BE0(iface0) == 0xF && !func_00146A70(iface1, 0, cBELibrary_getCharacterID(0), 10))
                || (func_00144BE0(iface0) == 0x10 && !func_00146A70(iface1, 0, cBELibrary_getCharacterID(0), 11))) {
                cUIState_hideObjSafe(self, D_004A2530);
                cUIState_hideObjSafe(self, D_004A2538);
            }
            cUIState_hideObjSafe(self, D_0046FFD0);
            break;
        case 6:
        case 7:
        case 8: {
            o = getObj_1FD320(self, D_0046FFD0);
            float mins = (float)*(unsigned int*)(stats + 0x78) * 0.01666666753590107f;
            void* r = func_004139F8(mins);
            func_002C2540_r(num, func_0020A1A8(r));
            unsigned short* f = lookupString_1FD320(D_0046E918);
            func_002C2540_r(title, D_004A2550);
            func_002C26D0(text, title, f, num);
            func_003A0D00(o, text);
            cUIText_setUnicodeStringByID(statusA, GetHashValue32(D_00470018));
            if (mode == 8 || (mode == 7 && !func_00157B08(iface13, 0, 2)) || (mode == 6 && !func_00157B08(iface13, 0, 1)))
                cUIText_setUnicodeStringByID(statusB, GetHashValue32(D_00470030));
            else
                cUIText_setUnicodeStringByID(statusB, GetHashValue32(D_00470048));
            break;
        }
        case 9:
        case 10:
        case 11: {
            int n = *(int*)(stats + 0x7C);
            unsigned short* f = lookupString_1FD320(D_0046E950);
            func_002C2540_r(title, D_004A2558);
            func_002C26D0(num, title, f, n);
            func_003A0D00(getObj_1FD320(self, D_0046FFD0), num);
            cUIText_setUnicodeStringByID(statusA, GetHashValue32(D_00470068));
            if (mode == 11 || (mode == 10 && !func_00157B08(iface13, 0, 2)) || (mode == 9 && !func_00157B08(iface13, 0, 1)))
                cUIText_setUnicodeStringByID(statusB, GetHashValue32(D_00470080));
            else
                cUIText_setUnicodeStringByID(statusB, GetHashValue32(D_00470098));
            break;
        }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FDB78);
#ifdef SKIP_ASM
extern "C" int func_001FDB78(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FDB88);
#ifdef SKIP_ASM
struct sPauseMgr_DB88 {
    char pad[0x8];
    int f8;
};
struct sGame_DB88 {
    char pad[0x200];
    sPauseMgr_DB88* mgr;
};
struct sApp_DB88 {
    char pad[0x84];
    sGame_DB88* game;
};

extern void* D_004A28A8;
extern "C" void func_002872A8(void* snd);

extern "C" void func_001FDB88(void* self, int a1, int a2)
{
    if (a1 != 0 && a2 == 5) {
        D_004A26FC = 3;
        ((sApp_DB88*)D_004A28A8)->game->mgr->f8 = 1;
        func_002872A8(func_0028B180());
        func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FDBF0);
#ifdef SKIP_ASM
extern "C" void* func_001D5330(void* self, int a1, int a2, int a3);
extern void* D_00472440[];

extern "C" void* func_001FDBF0(void* self, int a1, int a2)
{
    func_001D5330(self, a1, 1, a2);
    *(void***)((char*)self + 0x8) = D_00472440;
    *(int*)((char*)self + 0x22C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FDC30);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* cUIEngine_addScreenByHashName_DC30(void* engine, void* owner, int hash, int a3) __asm__("cUIEngine_addScreenByHashName");
extern "C" void* cUIScreen_playFrame_DC30(void* self, unsigned short frame, int flag) __asm__("cUIScreen_playFrame");
extern "C" void* cUIScreen_getObjectByHashName_DC30(void* self, int hash) __asm__("cUIScreen_getObjectByHashName");
extern "C" void func_0020A380_DC30(void* self) __asm__("func_0020A380");
extern int D_004A2A50;
extern int D_004A2A54;
extern int D_005366E8[];
extern int D_004428F0[];
extern char D_004A2560[];
extern char D_004700E0[];
extern char D_004700F0[];
extern char D_00470100[];
extern char D_00470118[];
extern char D_0046E9F8[];
extern char D_00470130[];
extern char D_00470148[];
extern char D_0046E378[];

struct cUIObj_DC30 {
    int pad[2];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void setVisible(int on);
};

static inline cUIObj_DC30* getObj_DC30(char* self, char* name)
{
    return (cUIObj_DC30*)cUIScreen_getObjectByHashName_DC30(*(void**)(self + 0x40), GetHashValue32(name));
}

// Builds the memory-card device-select overlay and pushes its menu state.
extern "C" void func_001FDC30(char* self)
{
    void* engine = *(void**)(self + 0x10);
    void* screen = cUIEngine_addScreenByHashName_DC30(engine, self, GetHashValue32(D_004700E0), 0);
    *(void**)(self + 0x40) = screen;
    if (screen != 0) {
        cUIObj_DC30* o;
        cUIScreen_playFrame_DC30(screen, 0, 0);
        o = getObj_DC30(self, D_004700F0);
        cUIText_setAsciiString((cUIText*)o, D_004A2560);
        o = getObj_DC30(self, D_00470100);
        o->setVisible(1);
        o = getObj_DC30(self, D_00470118);
        o->setVisible(0);
        o = getObj_DC30(self, D_0046E9F8);
        o->setVisible(0);
        o = getObj_DC30(self, D_00470130);
        cUIText_setAsciiString((cUIText*)o, D_004A2560);
        char name[0x20];
        for (int i = 1; i < 5; i++) {
            sprintf(name, D_00470148, i);
            o = getObj_DC30(self, name);
            *(int*)((char*)o + 0x18) = i - 1;
        }
    }
    engine = *(void**)(self + 0x10);
    screen = cUIEngine_addScreenByHashName_DC30(engine, self, GetHashValue32(D_0046E378), 0);
    if (screen != 0) {
        cUIScreen_playFrame_DC30(screen, 0, 0);
    }
    D_005366E8[++D_004A2A54] = 2;
    D_004A2A50 = D_004428F0[2];
    func_0020A380_DC30(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FDE60);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_004428F0[];
void func_00270ED8(void* self);
extern "C" void* func_001D58B8(void* self);
extern "C" void func_0026F8A0(void* self, void* a1, int a2, int a3);

extern "C" void func_001FDE60(void* self)
{
    if (*(int*)((char*)self + 0x1C8) == 1) {
        func_00270ED8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
        *(int*)((char*)self + 0x1C8) = 0;
    }
    D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
    func_001D58B8(self);
    func_0026F8A0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28), 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FDF00);
#ifdef SKIP_ASM
extern "C" void func_0039F718(void* self);

extern "C" void func_001FDF00(void* self)
{
    if (*(int*)((char*)self + 0x1AC) == 0) {
        func_0039F718(*(char**)((char*)self + 0x10) + 0x18);
    }
    *(int*)((char*)self + 0x1AC) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FDF40);
#ifdef SKIP_ASM
class cMCSub_DF40 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual void v14(int, void*);
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54(int);
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual void v64(void*);
    virtual int v65();
    virtual int v66(int);
    virtual int v67(int);
};

class cState_DF40 {
public:
    int pad[2];
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual void v35(int);
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual void v43();
};

class cUIObj_DF40 {
public:
    int pad[2];
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual void v08(int);
    virtual void v09(int);
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual void v25(int);
};

struct sVE_DF40 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

class cG_DF40 {
public:
    int pad;
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual void v04(int);
};

extern "C" void func_001D8240();
extern "C" int func_001D97E0(void* self, void* mp, int dev, int a3);
extern "C" void cMCOverlayManager_GetDeviceDisplayString(void* mp, int dev, unsigned short* buf, int len);
extern "C" void func_003A0D00(void* obj, unsigned short* s);
extern "C" void func_003A0E90(void* obj, unsigned short* s);
extern "C" void* func_00227F80(void* self);
extern void* D_004A28A8;
extern char D_004700F0[];
extern char D_00470130[];
extern char D_00470148[];
extern char D_00470158[];
extern char D_00470168[];
extern char D_00470178[];

static inline cUIObj_DF40* getObj_DF40(cState_DF40* self, char* name)
{
    return (cUIObj_DF40*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

extern "C" void func_001FDF40(cState_DF40* self)
{
    unsigned short buf[0x320];
    char name[0x40];
    char* mp = (char*)func_00227F80(D_004A28A8);
    if (self->v42()) {
        if (!(*(cMCSub_DF40**)(mp + 0x434))->v53()) {
            func_001D8240();
        } else if (*(int*)((char*)self + 0x214) != 3) {
            self->v35(3);
        }
    }
    if (self->v42()) {
        int sel = 0;
        self->v43();
        cMCOverlayManager_GetDeviceDisplayString(mp, *(int*)(mp + 0x428), buf, 0x320);
        func_003A0D00(getObj_DF40(self, D_00470130), buf);
        cUIObj_DF40* o = getObj_DF40(self, D_004700F0);
        (*(cMCSub_DF40**)(mp + 0x434))->v64(buf);
        func_003A0E90(o, buf);
        o->v09(0);
        char* g = *(char**)((char*)D_004A28A8 + 0x8C);
        sVE_DF40* vt = *(sVE_DF40**)(g + 4);
        char* t = g + vt[4].delta;
        vt[4].fn(t, GetHashValue32(D_00470158));
        for (int i = 1; i < 5; i++) {
            sprintf(name, D_00470148, i);
            o = getObj_DF40(self, name);
            (*(cMCSub_DF40**)(mp + 0x434))->v14(i - 1, (char*)self + 0x230);
            func_003A0E90(o, (unsigned short*)((char*)self + 0x230));
            if (!(*(cMCSub_DF40**)(mp + 0x434))->v67(i - 1) && !(*(cMCSub_DF40**)(mp + 0x434))->v66(i - 1)
                && (*(cMCSub_DF40**)(mp + 0x434))->v55()) {
                if (sel == 0) {
                    sel = 1;
                    o->v25(0);
                    o->v08(0);
                } else {
                    o->v25(1);
                    o->v08(1);
                }
            } else if ((*(cMCSub_DF40**)(mp + 0x434))->v54(*(int*)(mp + 0x428))) {
                if ((*(cMCSub_DF40**)(mp + 0x434))->v66(i - 1)) {
                    o->v08(1);
                    o->v25(1);
                } else {
                    o->v08(0);
                    o->v25(0);
                }
            } else {
                o->v25(1);
                o->v08(1);
            }
        }
        if (func_001D97E0(self, mp, *(int*)(mp + 0x428), 1) == -1)
            getObj_DF40(self, D_00470168)->v09(0);
        else
            getObj_DF40(self, D_00470168)->v09(1);
        if (func_001D97E0(self, mp, *(int*)(mp + 0x428), 0) == -1)
            getObj_DF40(self, D_00470178)->v09(0);
        else
            getObj_DF40(self, D_00470178)->v09(1);
    }
    if (*(int*)((char*)self + 0x214) != 3) {
        for (int i = 1; i < 5; i++) {
            sprintf(name, D_00470148, i);
            cUIObj_DF40* o = getObj_DF40(self, name);
            o->v25(0);
            o->v08(1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FE4A8);
#ifdef SKIP_ASM
class cUIObj_1FE4A8 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int v);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A2090[];
extern char D_004A2568[];
extern char D_00470188[];
extern char D_004A20A0[];

extern "C" void func_001FE4A8(void* self, bool on)
{
    if (*(int*)((char*)self + 0x22C) != on) {
        int off = !on;
        ((cUIObj_1FE4A8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2090)))->setVisible(off);
        ((cUIObj_1FE4A8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2568)))->setVisible(off);
        ((cUIObj_1FE4A8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00470188)))->setVisible(off);
        ((cUIObj_1FE4A8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A20A0)))->setVisible(off);
        *(int*)((char*)self + 0x22C) = on;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FE5B0);
#ifdef SKIP_ASM
class cUIObj_1FE5B0 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int v);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_00470188[];
extern char D_004A20A0[];

extern "C" void func_001FE5B0(void* self, bool on)
{
    ((cUIObj_1FE5B0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00470188)))->setVisible(!on);
    ((cUIObj_1FE5B0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A20A0)))->setVisible(!on);
    *(int*)((char*)self + 0x220) = !on;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FE648);
#ifdef SKIP_ASM
class cUIObj_1FE648 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int v);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A2090[];
extern char D_004A2568[];

extern "C" void func_001FE648(void* self, int a1, bool on)
{
    cUIObj_1FE648* a = (cUIObj_1FE648*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2090));
    ((cUIObj_1FE648*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2568)))->setVisible(!on);
    *(int*)((char*)self + 0x224) = !on;
    a->setVisible(!on);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FE6E8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_00227F80(void* self);
extern "C" void func_0023CAE8(void* self, int a, int b);
void func_00270ED8(void* self);
// PORT: the unit declares func_0023D570 as returning void*; this caller ignores the result (void view by asm label).
extern "C" void func_0023D570_v(void* self, int mode) __asm__("func_0023D570");

class cMovieSub434_1FE6E8 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54(int);
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67(int);
};

class cMoviePlayer_1FE6E8 {
public:
    char pad[0x748];
    virtual void v01(int);
};

extern "C" void func_001FE6E8(void* self, void* msg, unsigned int type)
{
    if (msg == 0)
        return;
    if (*(int*)((char*)self + 0x1A8) != 0)
        return;
    switch (type)
    {
    case 5:
    {
        int one = 1;
        if (*(int*)((char*)self + 0x1C0) == 6)
            return;
        char* mp = (char*)func_00227F80(D_004A28A8);
        int st = *(int*)((char*)self + 0x214);
        if (st != 3)
            return;
        int v = *(int*)((char*)msg + 0x18);
        *(int*)((char*)self + 0x1C4) = v;
        *(int*)(mp + 0xF8) = v;
        *(int*)((char*)self + 0x1A8) = one;
        if (*(int*)((char*)self + 0x1C8) == one)
        {
            func_00270ED8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
            *(int*)((char*)self + 0x1C8) = 0;
        }
        func_0023CAE8(mp, 0, -1);
        *(int*)((char*)self + 0x1DC) = one;
        *(int*)((char*)self + 0x1A8) = one;
        *(int*)((char*)self + 0x1C0) = st;
        break;
    }
    case 6:
    {
        char* mp = (char*)func_00227F80(D_004A28A8);
        if (*(int*)((char*)self + 0x1A8) == 1)
            return;
        int s = *(int*)((char*)self + 0x1C0);
        if (s == 6)
            return;
        *(int*)((char*)self + 0x1E4) = 1;
        if (s == 0 || s == 2 || s == 1)
            ((cMoviePlayer_1FE6E8*)mp)->v01(0);
        *(int*)((char*)self + 0x1C0) = 6;
        break;
    }
    case 7:
    {
        int one = 1;
        if (*(int*)((char*)self + 0x1C0) == 6)
            return;
        char* mp = (char*)func_00227F80(D_004A28A8);
        if (!(*(cMovieSub434_1FE6E8**)(mp + 0x434))->v54(*(int*)(mp + 0x428)))
            return;
        int v = *(int*)((char*)msg + 0x18);
        *(int*)((char*)self + 0x1C4) = v;
        *(int*)(mp + 0xF8) = v;
        int s = *(int*)((char*)self + 0x1C0);
        if (s != one)
            return;
        if (!(*(cMovieSub434_1FE6E8**)(mp + 0x434))->v67(*(int*)((char*)self + 0x1C4)))
            return;
        *(int*)((char*)self + 0x1A8) = s;
        *(int*)((char*)self + 0x1C0) = 4;
        func_0023D570_v(mp, 0);
        ((cMoviePlayer_1FE6E8*)mp)->v01(0x18);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FE8F0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
void func_00270ED8(void* self);
extern "C" void func_001D8700(void* self, void* a1, int key);

extern "C" void func_001FE8F0(void* self, void* a1, int key)
{
    if (key == 0x16) {
        if (*(int*)((char*)self + 0x19C) == 5) {
            func_00270ED8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
            *(int*)((char*)self + 0x1C8) = 0;
        }
    }
    func_001D8700(self, a1, key);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FE968);
#ifdef SKIP_ASM
extern "C" void* func_001D5330(void* self, int a1, int a2, int a3);
extern void* D_004722B8[];

extern "C" void* func_001FE968(void* self, int a1, int a2)
{
    func_001D5330(self, a1, 2, a2);
    *(void***)((char*)self + 0x8) = D_004722B8;
    *(int*)((char*)self + 0x22C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FE9A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
struct cUIText;
void cUIText_setAsciiString(cUIText* text, const char* s);
extern "C" void func_0020A380(void* self);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_0046E378[];
extern char D_0046E9F8[];
extern char D_004700E0[];
extern char D_004700F0[];
extern char D_00470100[];
extern char D_00470118[];
extern char D_00470130[];
extern char D_00470148[];
extern char D_004A2138[];
extern char D_004A2560[];

class cUIObj_1FE9A8 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
    virtual void v09(int on);
};

static inline void* engine_1FE9A8(char* self)
{
    return *(void**)(self + 0x10);
}

extern "C" void func_001FE9A8(char* self)
{
    void* scr = cUIEngine_addScreenByHashName(engine_1FE9A8(self), self, GetHashValue32(D_004700E0), 0);
    *(void**)(self + 0x40) = scr;
    if (scr != 0) {
        cUIScreen_playFrame(scr, 0, 0);
        cUIText_setAsciiString((cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004700F0)), D_004A2560);
        cUIObj_1FE9A8* o = (cUIObj_1FE9A8*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_00470100));
        o->v09(0);
        o = (cUIObj_1FE9A8*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_00470118));
        o->v09(1);
        o = (cUIObj_1FE9A8*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0046E9F8));
        o->v09(1);
        cUIText_setAsciiString((cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_00470130)), D_004A2560);
        for (int i = 1; i < 5; i++) {
            char buf[0x20];
            sprintf(buf, D_00470148, i);
            o = (cUIObj_1FE9A8*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(buf));
            if (i == 1) {
                *(int*)((char*)o + 0x18) = 0;
            } else {
                o->v08(1);
                o->v09(0);
            }
            sprintf(buf, D_004A2138, i);
            o = (cUIObj_1FE9A8*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(buf));
            if (i >= 2)
                o->v09(0);
        }
    }
    void* s2 = cUIEngine_addScreenByHashName(engine_1FE9A8(self), self, GetHashValue32(D_0046E378), 0);
    if (s2 != 0)
        cUIScreen_playFrame(s2, 0, 0);
    func_0020A380(self);
}
#endif

extern "C" void* func_001D58B8(void* self);

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FEC40__FPv);
#ifdef SKIP_ASM
void* func_001FEC40(void* self)
{
    return func_001D58B8(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FEC60);
#ifdef SKIP_ASM
extern "C" void func_0039F718(void* self);

extern "C" void func_001FEC60(void* self)
{
    if (*(int*)((char*)self + 0x1AC) == 0) {
        func_0039F718(*(char**)((char*)self + 0x10) + 0x18);
    }
    *(int*)((char*)self + 0x1AC) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FECA0);
#ifdef SKIP_ASM
class cMCSub_ECA0 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual void v14(int, void*);
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54(int);
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual void v64(void*);
    virtual int v65();
    virtual int v66(int);
    virtual int v67(int);
};

class cState_ECA0 {
public:
    int pad[2];
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual void v35(int);
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual void v43();
};

class cUIObj_ECA0 {
public:
    int pad[2];
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual void v08(int);
    virtual void v09(int);
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual void v25(int);
};

struct sVE_ECA0 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

class cG_ECA0 {
public:
    int pad;
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual void v04(int);
};

extern "C" void func_001D8240();
extern "C" int func_001D97E0(void* self, void* mp, int dev, int a3);
extern "C" void cMCOverlayManager_GetDeviceDisplayString(void* mp, int dev, unsigned short* buf, int len);
extern "C" void func_003A0D00(void* obj, unsigned short* s);
extern "C" void func_003A0E90(void* obj, unsigned short* s);
extern "C" void* func_00227F80(void* self);
extern void* D_004A28A8;
extern char D_004700F0[];
extern char D_00470130[];
extern char D_00470148[];
extern char D_00470158[];
extern char D_00470168[];
extern char D_00470178[];

static inline cUIObj_ECA0* getObj_ECA0(cState_ECA0* self, char* name)
{
    return (cUIObj_ECA0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

extern "C" void func_001FECA0(cState_ECA0* self)
{
    unsigned short buf[0x320];
    char name[0x40];
    char* mp = (char*)func_00227F80(D_004A28A8);
    if (self->v42()) {
        if (!(*(cMCSub_ECA0**)(mp + 0x434))->v53()) {
            func_001D8240();
        } else if (*(int*)((char*)self + 0x214) != 3) {
            self->v35(3);
        }
    }
    if (self->v42()) {
        self->v43();
        cMCOverlayManager_GetDeviceDisplayString(mp, *(int*)(mp + 0x428), buf, 0x320);
        func_003A0D00(getObj_ECA0(self, D_00470130), buf);
        cUIObj_ECA0* o = getObj_ECA0(self, D_004700F0);
        (*(cMCSub_ECA0**)(mp + 0x434))->v64(buf);
        func_003A0E90(o, buf);
        o->v09(0);
        char* g = *(char**)((char*)D_004A28A8 + 0x8C);
        sVE_ECA0* vt = *(sVE_ECA0**)(g + 4);
        char* t = g + vt[4].delta;
        vt[4].fn(t, GetHashValue32(D_00470158));
        sprintf(name, D_00470148, 1);
        o = getObj_ECA0(self, name);
        (*(cMCSub_ECA0**)(mp + 0x434))->v14(0, (char*)self + 0x230);
        func_003A0E90(o, (unsigned short*)((char*)self + 0x230));
        if (!(*(cMCSub_ECA0**)(mp + 0x434))->v67(0) && !(*(cMCSub_ECA0**)(mp + 0x434))->v66(0)
            && (*(cMCSub_ECA0**)(mp + 0x434))->v55()) {
            o->v25(0);
            o->v08(0);
        } else if ((*(cMCSub_ECA0**)(mp + 0x434))->v54(*(int*)(mp + 0x428))) {
            if ((*(cMCSub_ECA0**)(mp + 0x434))->v66(0)) {
                o->v08(1);
                o->v25(1);
            } else {
                o->v08(0);
                o->v25(0);
            }
        } else {
            o->v25(1);
            o->v08(1);
        }
        if (func_001D97E0(self, mp, *(int*)(mp + 0x428), 1) == -1)
            getObj_ECA0(self, D_00470168)->v09(0);
        else
            getObj_ECA0(self, D_00470168)->v09(1);
        if (func_001D97E0(self, mp, *(int*)(mp + 0x428), 0) == -1)
            getObj_ECA0(self, D_00470178)->v09(0);
        else
            getObj_ECA0(self, D_00470178)->v09(1);
    }
    if (*(int*)((char*)self + 0x214) != 3) {
        sprintf(name, D_00470148, 1);
        cUIObj_ECA0* o = getObj_ECA0(self, name);
        o->v25(0);
        o->v08(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FF170);
#ifdef SKIP_ASM
class cUIObj_1FF170 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int v);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A2090[];
extern char D_004A2568[];
extern char D_00470188[];
extern char D_004A20A0[];

extern "C" void func_001FF170(void* self, bool on)
{
    if (*(int*)((char*)self + 0x22C) != on) {
        int off = !on;
        ((cUIObj_1FF170*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2090)))->setVisible(off);
        ((cUIObj_1FF170*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2568)))->setVisible(off);
        ((cUIObj_1FF170*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00470188)))->setVisible(off);
        ((cUIObj_1FF170*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A20A0)))->setVisible(off);
        *(int*)((char*)self + 0x22C) = on;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FF278);
#ifdef SKIP_ASM
class cUIObj_1FF278 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int v);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_00470188[];
extern char D_004A20A0[];

extern "C" void func_001FF278(void* self, bool on)
{
    ((cUIObj_1FF278*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00470188)))->setVisible(!on);
    ((cUIObj_1FF278*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A20A0)))->setVisible(!on);
    *(int*)((char*)self + 0x220) = !on;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FF310);
#ifdef SKIP_ASM
class cUIObj_1FF310 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int v);
};
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A2090[];
extern char D_004A2568[];

extern "C" void func_001FF310(void* self, int a1, bool on)
{
    cUIObj_1FF310* a = (cUIObj_1FF310*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2090));
    ((cUIObj_1FF310*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2568)))->setVisible(!on);
    *(int*)((char*)self + 0x224) = !on;
    a->setVisible(!on);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FF3B0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_00227F80(void* self);
extern "C" void func_0023CAE8(void* self, int a, int b);
// PORT: the unit declares func_0023D570 as returning void*; this caller ignores the result (void view by asm label).
extern "C" void func_0023D570_v(void* self, int mode) __asm__("func_0023D570");

class cMovieSub434_1FF3B0 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54(int);
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67(int);
};

class cMoviePlayer_1FF3B0 {
public:
    char pad[0x748];
    virtual void v01(int);
};

extern "C" void func_001FF3B0(void* self, void* msg, unsigned int type)
{
    if (msg == 0)
        return;
    if (*(int*)((char*)self + 0x1A8) != 0)
        return;
    switch (type)
    {
    case 5:
    {
        int one = 1;
        if (*(int*)((char*)self + 0x1C0) == 6)
            return;
        char* mp = (char*)func_00227F80(D_004A28A8);
        int st = *(int*)((char*)self + 0x214);
        if (st != 3)
            return;
        int v = *(int*)((char*)msg + 0x18);
        *(int*)((char*)self + 0x1C4) = v;
        *(int*)(mp + 0xF8) = v;
        *(int*)((char*)self + 0x1A8) = one;
        func_0023CAE8(mp, 2, -1);
        *(int*)((char*)self + 0x1DC) = one;
        *(int*)((char*)self + 0x1A8) = one;
        *(int*)((char*)self + 0x1C0) = st;
        break;
    }
    case 6:
    {
        char* mp = (char*)func_00227F80(D_004A28A8);
        if (*(int*)((char*)self + 0x1A8) == 1)
            return;
        int s = *(int*)((char*)self + 0x1C0);
        if (s == 6)
            return;
        *(int*)((char*)self + 0x1E4) = 1;
        if (s == 0 || s == 2 || s == 1)
            ((cMoviePlayer_1FF3B0*)mp)->v01(0);
        *(int*)((char*)self + 0x1C0) = 6;
        break;
    }
    case 7:
    {
        int one = 1;
        if (*(int*)((char*)self + 0x1C0) == 6)
            return;
        char* mp = (char*)func_00227F80(D_004A28A8);
        if (!(*(cMovieSub434_1FF3B0**)(mp + 0x434))->v54(*(int*)(mp + 0x428)))
            return;
        int v = *(int*)((char*)msg + 0x18);
        *(int*)((char*)self + 0x1C4) = v;
        *(int*)(mp + 0xF8) = v;
        int s = *(int*)((char*)self + 0x1C0);
        if (s != one)
            return;
        if (!(*(cMovieSub434_1FF3B0**)(mp + 0x434))->v67(*(int*)((char*)self + 0x1C4)))
            return;
        *(int*)((char*)self + 0x1A8) = s;
        *(int*)((char*)self + 0x1C0) = 4;
        func_0023D570_v(mp, 0);
        ((cMoviePlayer_1FF3B0*)mp)->v01(0x18);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", cOVState_REWARDS_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0020A380(void* self);
extern "C" void func_001FF7B8(void* self, int a1, int a2);
extern "C" void func_0039B760(void* self, unsigned char a1);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern char D_004703C8[];
extern char D_0046E378[];
extern char D_0046E818[];
extern char D_004A2570[];
extern char D_004A2578[];

extern "C" void cOVState_REWARDS_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004703C8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    void* engine2 = *(void**)((char*)self + 0x10);
    void* bg = cUIEngine_addScreenByHashName(engine2, self, GetHashValue32(D_0046E378), 0);
    if (bg != 0) {
        cUIScreen_playFrame(bg, 0, 0);
    }
    func_0020A380(self);
    *(int*)((char*)self + 0x9C) = 0;
    func_001FF7B8(self, 0, -1);
    char* menu = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E818));
    if (menu != 0) {
        *(int*)(menu + 0x14) &= ~0x80;
        if (*(unsigned char*)(menu + 0x96) < *(int*)((char*)self + 0x9C)) {
            func_0039B760(menu, *(int*)((char*)self + 0x9C));
        } else {
            *(int*)(menu + 0x90) |= 8;
        }
    }
    cUIState_hideObjSafe(self, D_004A2570);
    cUIState_hideObjSafe(self, D_004A2578);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FF6D0);
#ifdef SKIP_ASM
extern "C" void func_0039E4C0(void* self);
extern "C" void func_001FFD08(void* self, int a1);

extern "C" void func_001FF6D0(void* self)
{
    func_0039E4C0(self);
    func_001FFD08(self, 0);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FF700);
#ifdef SKIP_ASM
extern int D_004A26FC;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00158E30(void* iface);

extern "C" void func_001FF700(void* self, void* a1, int key)
{
    if (a1 != 0) {
        if (key == 5) {
            D_004A26FC = 1;
            func_00158E30(cBE_getInterface_Fv(cBE_getBE(), 0xD));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatepause", func_001FF748);
#ifdef SKIP_ASM
extern "C" void func_001FFD08(void* self, int a);

extern "C" int func_001FF748(void* self, int id, int event, int arg)
{
    switch (event) {
    case 4:
        func_001FFD08(self, arg);
        return 1;
    case 7: case 8: case 9:
        return 0;
    case 2: case 3:
        if (*(int*)((char*)self + 0x9C) < 10) {
            return 0;
        }
        /* fall through */
    case 5: case 6:
        break;
    }
    return 0x101;
}
#endif

INCLUDE_ASM("fe/ovstatepause", func_001FF7B8);

INCLUDE_ASM("fe/ovstatepause", func_001FFD08);

//100%
INCLUDE_ASM("fe/ovstatepause", cOVState_REWARDS_onGainTransition);
#ifdef SKIP_ASM
extern "C" int func_001FD190(int id);
extern "C" unsigned short* func_002C2508(unsigned short* dst, unsigned short* src);
extern "C" void func_002C2540_m2715(unsigned short* dst, const char* src) __asm__("func_002C2540");
extern "C" int func_002C26D0_m2716(unsigned short* dst, const unsigned short* fmt, ...) __asm__("func_002C26D0");
extern "C" void func_002C27C0_m2717(unsigned short* dst, const char* fmt, ...) __asm__("func_002C27C0");
extern "C" const char* func_00144BF0_m2718(void* iface) __asm__("func_00144BF0");
extern "C" const char* func_0014EE58_m2719(void* iface, int a1) __asm__("func_0014EE58");
extern char D_0046F520[];
extern char D_004A2400[];
extern char D_0046E548[];
extern char D_0046E398[];
extern char D_0046E3A8[];
extern char D_0046E3C0[];
extern char D_00470468[];
extern char D_00470480[];
extern char D_004A2588[];
extern char D_004A2590[];

struct sVE_REWARDS {
    short delta;
    short index;
    unsigned short* (*fn)(void* self, int hash);
};

// Looks up the localised string for a hashed name through the front end's text table.
static inline unsigned short* getText_REWARDS(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVE_REWARDS* vt = *(sVE_REWARDS**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

// Fills in the event title and the reward line the first time the rewards screen gains focus.
extern "C" int cOVState_REWARDS_onGainTransition(void* self)
{
    if (*(int*)((char*)self + 0x48) == 0) {
        unsigned short title[0x68];
        unsigned short fmt[0x10];
        unsigned short line[0x68];
        unsigned short num[0x20];
        void* ifA = cBE_getInterface_Fv(cBE_getBE(), 2);
        void* ifB = cBE_getInterface_Fv(cBE_getBE(), 1);
        void* ifC = cBE_getInterface_Fv(cBE_getBE(), 0);
        signed char* g = (signed char*)D_00535BC8;
        int kind = g[0x4A];
        int mode = g[0x48];
        switch (kind) {
        case 6: case 7: case 8: case 9: case 10: case 11:
            func_002C2508(title, (unsigned short*)func_001FD190(kind));
            break;
        case 5:
            func_002C2540_m2715(fmt, D_0046F520);
            func_002C26D0_m2716(title, fmt, func_00144BF0_m2718(ifC));
            break;
        default: {
            unsigned short* sub = 0;
            switch (mode) {
            case 0:
            case 5:
                sub = getText_REWARDS(D_0046E548);
                break;
            case 1:
                sub = getText_REWARDS(D_0046E398);
                break;
            case 2:
                sub = getText_REWARDS(D_0046E3A8);
                break;
            case 3:
                sub = getText_REWARDS(D_0046E3C0);
                break;
            }
            func_002C2540_m2715(fmt, D_004A2400);
            func_002C26D0_m2716(title, fmt, func_00144BF0_m2718(ifC), sub);
            break;
        }
        }
        func_003A0E90(cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00470468)), title);
        int idx = func_00146E98(ifB, 0);
        void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2588));
        func_002C27C0_m2717(num, D_004A2590, func_0014EE58_m2719(ifA, idx));
        unsigned short* lfmt = getText_REWARDS(D_00470480);
        func_002C26D0_m2716(line, lfmt, num);
        func_003A0E90(o, line);
    }
    *(int*)((char*)self + 0x48) = 1;
    return 0;
}
#endif

