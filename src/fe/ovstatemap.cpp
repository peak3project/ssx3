#include "common.h"

//100%
INCLUDE_ASM("fe/ovstatemap", cOVState_MAP_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct sSelf0020A380;
extern "C" void func_0020A380(sSelf0020A380* self);
extern "C" int func_001A3BF0(void* mgr);
extern "C" void func_00208F10(void* self);
extern "C" void cOVState_MAP_setupPopup(void* self);
extern "C" void cOVState_MAP_setupPlayerIndicator(void* self);
extern "C" void cOVState_MAP_setupLocalSessionList(void* self);
extern void* D_004A28A8;
extern char D_004717F8[];
extern char D_004A25A8[];

class cUIObj_86A8 {
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

struct sMap_86A8 {
    char pad_0x0[0x10];
    void* engine;       // 0x10
    char pad_0x14[0xA8];
    int fBC;            // 0xBC
    int fC0;            // 0xC0
    int fC4;            // 0xC4
    char pad_0xC8[0x8];
    cUIObj_86A8* obj;   // 0xD0
    void* screen;       // 0xD4
    char pad_0xD8[0x4];
    int fDC;            // 0xDC
    int fE0;            // 0xE0
    int a[8];           // 0xE4
    int b[8];           // 0x104
    char pad_0x124[0x60];
    int c[8];           // 0x184
    int d[8];           // 0x1A4
    char pad_0x1C4[0x8];
    float scale;        // 0x1CC
    float speed;        // 0x1D0
};

extern "C" void cOVState_MAP_onCreateScreen(sMap_86A8* self)
{
    void* engine = self->engine;
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004717F8), 0);
    self->screen = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380((sSelf0020A380*)self);
    self->fC4 = func_001A3BF0(*(void**)((char*)D_004A28A8 + 0x11C));
    self->fDC = 0;
    self->fBC = 0;
    self->scale = 1.0f;
    self->speed = 0.1599999964237213f;
    cUIObj_86A8* o = (cUIObj_86A8*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A25A8));
    self->obj = o;
    if (o != 0) {
        o->setVisible(0);
    }
    self->fC0 = 0;
    self->fE0 = 0;
    for (int i = 0; i < 8; i++) {
        self->a[i] = 0;
        self->b[i] = 0;
        self->c[i] = 0;
        self->d[i] = 0;
    }
    func_00208F10(self);
    cOVState_MAP_setupPopup(self);
    cOVState_MAP_setupPlayerIndicator(self);
    cOVState_MAP_setupLocalSessionList(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_002087E8__FPv);
#ifdef SKIP_ASM
void func_002087E8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", cOVState_MAP_onGainTransition);
#ifdef SKIP_ASM
struct sV3_87F0 {
    float x, y, z;
};

struct sV4_87F0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVE_87F0 {
    short delta;
    short index;
    void* fn;
};

struct sUIObj_87F0 {
    int pad_0x0[2];
    sVE_87F0* vt;               // 0x8
    char pad_0xC[0xC];
    int f18;                    // 0x18
};

struct sStrMgr_87F0 {
    int pad_0x0;
    sVE_87F0* vt;               // 0x4
};

class cRiderSub_87F0 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual sV4_87F0* v05();
};

struct sMapF_87F0 {
    char pad_0x0[0x9C];
    int flags[8];               // 0x9C
};

typedef void (*VIntFn_87F0)(void*, int);
typedef void (*VPtrFn_87F0)(void*, void*);
typedef void* (*VGetFn_87F0)(void*, int);

extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_00209E78(void* self);
extern char D_004C8B58[];
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" int func_001545F8(void* iface, int id);
extern "C" void func_002C27C0(void* buf, const char* fmt, void* str, int n);
extern "C" void func_003A0E90(void* t, void* str);
extern "C" int func_0026B680(void* tbl, sV3_87F0* pos);
extern void* D_004A28A8;
extern char D_00471808[];
extern char D_00471818[];
extern char D_00471828[];
extern char D_00471838[];
extern char D_00471850[];
extern char D_004706B8[];
extern char D_004706C8[];
extern char D_004A2558[];
extern char D_004D33A0[];

extern "C" int cOVState_MAP_onGainTransition(void* selfp, int on)
{
    char* self = (char*)selfp;
    if (on != 0) {
        int i = 0;
        sUIObj_87F0* t;
        void* ifGame = cBE_getInterface_Fv(cBE_getBE(), 0);
        void* ifMap = cBE_getInterface_Fv(cBE_getBE(), 10);
        int n = func_001545F8(ifMap, *func_00144BC0(ifGame));
        for (i = 0; i < 8; i++) {
            char buf[0x20];
            unsigned short text[0x28];
            sprintf(buf, D_00471808, i);
            t = (sUIObj_87F0*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(buf));
            if (i < n) {
                ((sMapF_87F0*)self)->flags[i] = 1;
                sStrMgr_87F0* g = *(sStrMgr_87F0**)((char*)D_004A28A8 + 0x8C);
                sVE_87F0* vt = g->vt;
                void* str = ((VGetFn_87F0)vt[4].fn)((char*)g + vt[4].delta, GetHashValue32(D_00471818));
                if (str == 0) {
                    continue;
                }
                func_002C27C0(text, D_004A2558, str, i + 1);
                if (t == 0) {
                    continue;
                }
                if (i == 0) {
                    cUIText_setUnicodeStringByID((cUIText*)t, GetHashValue32(D_00471828));
                } else if (i == n - 1 && n != 2) {
                    cUIText_setUnicodeStringByID((cUIText*)t, GetHashValue32(D_00471838));
                } else {
                    func_003A0E90(t, text);
                }
                t->f18 = i + 1;
            } else {
                ((sMapF_87F0*)self)->flags[i] = 0;
                ((VIntFn_87F0)t->vt[9].fn)((char*)t + t->vt[9].delta, 0);
                ((VIntFn_87F0)t->vt[8].fn)((char*)t + t->vt[8].delta, 1);
            }
        }
        void* menu = cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_00471850));
        char* game = *(char**)((char*)D_004A28A8 + 0x84);
        if (game != 0) {
            char* rider = *(char**)(*(char**)(game + 0xC) + 0x28);
            sV4_87F0 p = *((cRiderSub_87F0*)(rider + 0x6C0))->v05();
            sV3_87F0 q;
            q.x = p.x;
            q.y = p.y;
            q.z = p.z;
            int r = func_0026B680(D_004D33A0, &q);
            int idx = r - 1;
            if (r == 0) {
                idx = 0;
            }
            cUIMenu_setSelectedByIndex(menu, idx);
        }
        func_00209E78(self);
        t = (sUIObj_87F0*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004706B8));
        if (t != 0) {
            t->f18 = 0;
            ((VPtrFn_87F0)t->vt[11].fn)((char*)t + t->vt[11].delta, D_004C8B58);
        }
        t = (sUIObj_87F0*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004706C8));
        if (t != 0) {
            t->f18 = 1;
            ((VPtrFn_87F0)t->vt[11].fn)((char*)t + t->vt[11].delta, D_004C8B58);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00208B00);
#ifdef SKIP_ASM
struct sVEntry00208B00 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj00208B00 {
    int pad[2];
    sVEntry00208B00* vt;
};

int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0039E4C0(void* self, int a1);
extern char D_00470A20[];

extern "C" void func_00208B00(void* self, int a1)
{
    sObj00208B00* o;
    func_0039E4C0(self, a1);
    o = (sObj00208B00*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0xD4), GetHashValue32(D_00470A20));
    if (o != 0) {
        o->vt[7].fn((char*)o + o->vt[7].delta, 0);
        o->vt[9].fn((char*)o + o->vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00208B78);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void cFEAsyncManager_UnloadFEAsyncFile(void* mgr, int file);
extern "C" void func_0020A088(void* self);
extern "C" void func_0020A430(void* self);

extern "C" void func_00208B78(void* self)
{
    cFEAsyncManager_UnloadFEAsyncFile(*(void**)((char*)D_004A28A8 + 0x11C), *(int*)((char*)self + 0xC4));
    func_0020A088(self);
    func_0020A430(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00208BB8);
#ifdef SKIP_ASM
struct sVEntry00208BB8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj00208BB8 {
    int pad[2];
    sVEntry00208BB8* vt;
};

extern "C" void func_00208BB8(void* self)
{
    sObj00208BB8* o;
    *(int*)((char*)self + 0xDC) = 1;
    *(int*)((char*)self + 0xC8) = 0;
    o = *(sObj00208BB8**)((char*)self + 0xD0);
    if (o != 0) {
        o->vt[9].fn((char*)o + o->vt[9].delta, 0);
    }
    o = *(sObj00208BB8**)((char*)self + 0xE0);
    if (o != 0) {
        o->vt[9].fn((char*)o + o->vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00208C28);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_0028FAE0(void* self);
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern "C" void func_002095E8(void* self, void* obj, int on);
extern "C" void func_00209648(void* self, void* obj, int on);
void* func_0039F190_8C28(void* self, int a1) __asm__("func_0039F190");
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_004A26FC;
extern int D_005366E8[];
extern int D_004428F0[];
extern char D_004706E8[];
extern char D_00470700[];
extern char D_00470718[];
extern char D_00470730[];
extern char D_00470748[];
extern char D_00470760[];

struct cVec_00208C28 {
    float x, y, z, w;
    cVec_00208C28(float a, float b, float c, float e) { x = a; y = b; z = c; w = e; }
};

class cObjV_00208C28 {
public:
    int pad[2];
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10();
    virtual void set(const cVec_00208C28& v);
};

// Map overlay message handler: confirm/cancel of the map popup and toggling of the legend objects.
extern "C" void func_00208C28(void* selfp, void* a1, int a2)
{
    char* self = (char*)selfp;
    if (a1 == 0) {
        return;
    }
    switch (a2) {
    case 5:
        if (*(int*)(self + 0xBC) != 0) {
            if (*(int*)((char*)a1 + 0x18) != 0) {
                *(int*)(self + 0xBC) = 0;
                cOVState_MAP_setupPopup(self);
                break;
            }
            void* iface = cBE_getInterface_Fv(cBE_getBE(), 10);
            *(int*)((char*)iface + 0x10) = *(int*)(self + 0xD8);
            func_0028FAE0(func_0028B180());
            void* m = *(void**)((char*)D_004A28A8 + 0x84);
            D_004A26FC = 3;
            D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
            func_00231250(m, 0xF, 0, 0);
            func_0020A088(self);
            func_00208BB8(self);
        } else {
            *(int*)(self + 0xBC) = 1;
            *(int*)(self + 0xD8) = *(int*)((char*)a1 + 0x18);
            cOVState_MAP_setupPopup(self);
            cObjV_00208C28* o = (cObjV_00208C28*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004706C8));
            o->set(cVec_00208C28(1.0f, 0.0f, 0.0f, 0.0f));
        }
        break;
    case 6:
        if (*(int*)(self + 0xBC) != 0) {
            *(int*)(self + 0xBC) = 0;
            cOVState_MAP_setupPopup(self);
        } else {
            func_0020A088(self);
            func_00208BB8(self);
            func_0039F190_8C28(*(char**)(self + 0x10) + 0x18, 1);
            *(int*)(self + 0x1C) = (*(int*)(self + 0x1C) & ~0x3F00) | 0x780;
        }
        break;
    case 1:
        if (*(int*)(self + 0xBC) != 0) {
            func_002095E8(self, a1, 1);
            if (*(int*)((char*)a1 + 0x18) == 0) {
                cUIState_showObjSafe(self, D_004706E8);
                cUIState_hideObjSafe(self, D_00470700);
                cUIState_showObjSafe(self, D_00470718);
                cUIState_hideObjSafe(self, D_00470730);
                cUIState_showObjSafe(self, D_00470748);
                cUIState_hideObjSafe(self, D_00470760);
            } else {
                cUIState_showObjSafe(self, D_00470700);
                cUIState_hideObjSafe(self, D_004706E8);
                cUIState_showObjSafe(self, D_00470730);
                cUIState_hideObjSafe(self, D_00470718);
                cUIState_showObjSafe(self, D_00470760);
                cUIState_hideObjSafe(self, D_00470748);
            }
        }
        break;
    case 2:
        if (*(int*)(self + 0xBC) != 0) {
            func_00209648(self, a1, 1);
        }
        break;
    case 7:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00208EF8);
#ifdef SKIP_ASM
extern "C" int func_00208EF8(void* self, int a1, int a2)
{
    return ((unsigned int)(a2 - 8) < 2) ? 0 : 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00208F10);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cFEAsyncManager_UnloadFEAsyncFile(void* mgr, int file);
extern "C" int* func_00144BC0(void*);
extern "C" void func_001A37F8(void* mgr, int a1, int file, int a3);

extern "C" void func_00208F10(void* self)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* mgr = *(void**)((char*)D_004A28A8 + 0x11C);
    cFEAsyncManager_UnloadFEAsyncFile(mgr, *(int*)((char*)self + 0xC4));
    func_001A37F8(mgr, *func_00144BC0(iface), *(int*)((char*)self + 0xC4), 1);
    *(int*)((char*)self + 0xC8) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", cOVState_MAP_setupPopup);
#ifdef SKIP_ASM
struct sVE_9010 {
    short delta;
    short index;
    void* fn;
};

struct sUIObj_9010 {
    int pad_0x0[2];
    sVE_9010* vt;               // 0x8
    char pad_0xC[0x95 - 0xC];
    unsigned char f95;          // 0x95
};

struct sStrMgr_9010 {
    int pad_0x0;
    sVE_9010* vt;               // 0x4
};

typedef void (*VIntFn_9010)(void*, int);
typedef void* (*VGetFn_9010)(void*, int);

extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int sprintf(char* buf, const char* fmt, ...);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* t, int id);
void cUIText_setAsciiString(cUIText* self, const char* str);
int cBELibrary_getCharacterID(int);
extern "C" int func_00150928(void* self, int a, int b);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" void func_002C27C0(void* buf, const char* fmt, void* str, int n);
extern "C" void func_003A0E90(void* t, void* str);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern void* D_004A28A8;
extern char D_00470A20[];
extern char D_00471850[];
extern char D_00470A60[];
extern char D_004A2638[];
extern char D_004A2640[];
extern char D_00471818[];
extern char D_004A26F0[];
extern char D_00471890[];
extern char D_004A26F8[];
extern char D_004718A0[];
extern char D_004718B8[];
extern char D_004718C8[];
extern char D_004718D8[];
extern char D_00470700[];
extern char D_004706B8[];
extern char D_004706C8[];
extern char D_00470AA8[];

extern "C" void cOVState_MAP_setupPopup(void* selfp)
{
    char* self = (char*)selfp;
    sUIObj_9010* menu = (sUIObj_9010*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_00470A20));
    sUIObj_9010* list = (sUIObj_9010*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_00471850));
    if (*(int*)(self + 0xBC) != 0) {
        unsigned short text[0x28];
        char buf[0x10];
        cUIState_showObjSafe(self, D_00470A60);
        if (menu != 0) {
            cUIMenu_setSelectedByIndex(menu, 0);
        }
        unsigned char n = 0;
        cUIState_showObjSafe(self, D_004A2638);
        cUIState_hideObjSafe(self, D_004A2640);
        if (list != 0) {
            ((VIntFn_9010)list->vt[7].fn)((char*)list + list->vt[7].delta, 0);
            n = list->f95;
        }
        if (menu != 0) {
            ((VIntFn_9010)menu->vt[7].fn)((char*)menu + menu->vt[7].delta, 1);
            ((VIntFn_9010)menu->vt[9].fn)((char*)menu + menu->vt[9].delta, 1);
        }
        sStrMgr_9010* g = *(sStrMgr_9010**)((char*)D_004A28A8 + 0x8C);
        sVE_9010* vt = g->vt;
        void* str = ((VGetFn_9010)vt[4].fn)((char*)g + vt[4].delta, GetHashValue32(D_00471818));
        if (str != 0) {
            func_002C27C0(text, D_004A26F0, str, n + 1);
            void* t = cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_00471890));
            if (t != 0) {
                func_003A0E90(t, text);
            }
        }
        int id = func_00150928(cBE_getInterface_Fv(cBE_getBE(), 0xB), 0, cBELibrary_getCharacterID(0));
        sprintf(buf, D_004A26F8, id);
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004718A0));
        if (t != 0) {
            cUIText_setAsciiString(t, buf);
        }
        sprintf(buf, D_004A26F8, 500);
        t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004718B8));
        if (t != 0) {
            cUIText_setAsciiString(t, buf);
        }
        t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004718C8));
        if (t != 0) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_004718D8));
        }
        cUIState_hideObjSafe(self, D_00470700);
        cUIText* a = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004706B8));
        sUIObj_9010* b = (sUIObj_9010*)cUIScreen_getObjectByHashName(*(void**)(self + 0xD4), GetHashValue32(D_004706C8));
        if (a != 0) {
            cUIText_setUnicodeStringByID(a, GetHashValue32(D_00470AA8));
        }
        if (b != 0) {
            ((VIntFn_9010)b->vt[9].fn)((char*)b + b->vt[9].delta, 1);
            ((VIntFn_9010)b->vt[8].fn)((char*)b + b->vt[8].delta, 0);
        }
        cUIState_showObjSafe(self, D_004706C8);
    } else {
        cUIState_hideObjSafe(self, D_00470A60);
        if (list != 0) {
            ((VIntFn_9010)list->vt[7].fn)((char*)list + list->vt[7].delta, 1);
        }
        if (menu != 0) {
            ((VIntFn_9010)menu->vt[7].fn)((char*)menu + menu->vt[7].delta, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00209300);
#ifdef SKIP_ASM
struct sVEntry00209300 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sObj00209300 {
    int pad[2];
    sVEntry00209300* vt;
};

extern "C" void func_00209E78(void* self);

extern "C" void func_00209300(void* self, sObj00209300* o)
{
    if (o->vt[17].fn((char*)o + o->vt[17].delta) != 0 || o->vt[18].fn((char*)o + o->vt[18].delta) != 0) {
        func_00209E78(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00209370);
#ifdef SKIP_ASM
struct sCol_9370 {
    float a, r, g, b;
};

struct sV3_9370 {
    float x, y, z;
    sV3_9370() {}
    sV3_9370(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

class cFEObj_9370 {
public:
    int pad_0x0[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void SetVisible(int on);
    virtual void v10();
    virtual void SetColor(const sCol_9370* c);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetScale(const sV3_9370& s);
};

struct sFEObjData_9370 {
    char pad_0x0[0x1C];
    sCol_9370 col;              // 0x1C
    char pad_0x2C[0x18];
    sV3_9370 pos;               // 0x44
    char pad_0x50[0x28];
    int f78;                    // 0x78
    int f7C;                    // 0x7C
};

struct sAsyncFile_9370 {
    char pad_0x0[0x110];
    int data;                   // 0x110
    char pad_0x114[0x8];
};

struct sMap_9370 {
    char pad_0x0[0xC4];
    int file;                   // 0xC4
    int loaded;                 // 0xC8
    float fade;                 // 0xCC
    cFEObj_9370* img;           // 0xD0
    char pad_0xD4[0x8];
    int busy;                   // 0xDC
    char pad_0xE0[0x24];
    cFEObj_9370* icons[8];      // 0x104
    sV3_9370 iconPos[8];        // 0x124
    char pad_0x184[0x48];
    float bob;                  // 0x1CC
    float bobVel;               // 0x1D0
};

struct cFEAsyncManager;
int cFEAsyncManager_GetFileStatus(cFEAsyncManager* self, int index);
extern "C" void func_0020E900(void* self);
extern void* D_004A28A8;

extern "C" void func_00209370(sMap_9370* self)
{
    func_0020E900(self);
    if (self->busy != 0) {
        return;
    }
    if (self->loaded != 0) {
        if (self->fade < 1.0f) {
            self->fade += 0.10000000149011612f;
        }
        cFEObj_9370* o = self->img;
        sCol_9370 c = ((sFEObjData_9370*)o)->col;
        c.a = self->fade;
        o->SetColor(&c);
        self->img->SetVisible(1);
    } else {
        self->fade = 0.0f;
        self->img->SetVisible(0);
    }
    sAsyncFile_9370* am = *(sAsyncFile_9370**)((char*)D_004A28A8 + 0x11C);
    if (cFEAsyncManager_GetFileStatus((cFEAsyncManager*)am, self->file) == 3 && self->loaded == 0) {
        cFEObj_9370* o = self->img;
        if (o != 0) {
            int data = am[self->file].data;
            ((sFEObjData_9370*)o)->f7C = 0;
            ((sFEObjData_9370*)o)->f78 = data;
            self->loaded = 1;
            self->fade = 0.0f;
        }
    }
    if (0.0f < self->bobVel) {
        if (21.5f < self->bob) {
            self->bobVel = -0.1599999964237213f;
        }
    } else if (self->bob < 18.0f) {
        self->bobVel = 0.1599999964237213f;
    }
    self->bob += self->bobVel;
    int i;
    for (i = 0; i < 8; i++) {
        cFEObj_9370* o = self->icons[i];
        if (o != 0) {
            sV3_9370* bp = &self->iconPos[i];
            float d = (self->bob - 18.0f) * 0.5f;
            sV3_9370 p;
            p.x = bp->x - d;
            p.y = bp->y - d;
            ((sFEObjData_9370*)o)->pos = p;
            self->icons[i]->SetScale(sV3_9370(self->bob, self->bob, 0.0f));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_002095E8);
#ifdef SKIP_ASM
struct sVEntry_func_002095E8 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};
extern char D_004C8B38[];
extern char D_004C8B28[];

extern "C" void func_002095E8(void* self, void* obj, int on)
{
    if (on != 0) {
        sVEntry_func_002095E8* vt = *(sVEntry_func_002095E8**)((char*)obj + 0x8);
        vt[11].fn((char*)obj + vt[11].delta, D_004C8B38);
    } else {
        sVEntry_func_002095E8* vt = *(sVEntry_func_002095E8**)((char*)obj + 0x8);
        vt[11].fn((char*)obj + vt[11].delta, D_004C8B28);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_00209648);
#ifdef SKIP_ASM
struct sVEntry_func_00209648 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};
extern char D_004C8B58[];
extern char D_004C8B48[];

extern "C" void func_00209648(void* self, void* obj, int on)
{
    if (on != 0) {
        sVEntry_func_00209648* vt = *(sVEntry_func_00209648**)((char*)obj + 0x8);
        vt[11].fn((char*)obj + vt[11].delta, D_004C8B58);
    } else {
        sVEntry_func_00209648* vt = *(sVEntry_func_00209648**)((char*)obj + 0x8);
        vt[11].fn((char*)obj + vt[11].delta, D_004C8B48);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", cOVState_MAP_setupPlayerIndicator);
#ifdef SKIP_ASM
struct sV3_96A8 {
    float x, y, z;
    sV3_96A8() {}
    sV3_96A8(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    sV3_96A8(const float& ax, const float& ay) : x(ax), y(ay), z(0.0f) {}
};

struct sV4_96A8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBounds_96A8 {
    char pad_0x0[0x1C];
    float minX;                 // 0x1C
    float minY;                 // 0x20
    float maxX;                 // 0x24
    float maxY;                 // 0x28
    char pad_0x2C[0x4];
};

class cFEObj_96A8 {
public:
    int pad_0x0[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void SetVisible(int on);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetScale(const sV3_96A8& s);
};

struct sFEObjData_96A8 {
    char pad_0x0[0x14];
    int flags;                  // 0x14
    char pad_0x18[0x2C];
    sV3_96A8 pos;               // 0x44
};

class cRiderSub_96A8 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual sV4_96A8* v05();
};

struct sMapSt_96A8 {
    char pad_0x0[0xD0];
    cFEObj_96A8* img;           // 0xD0
    char* screen;               // 0xD4
    char pad_0xD8[0x8];
    cFEObj_96A8* ind;           // 0xE0
};

struct cList;
struct cListNode;
void cList_addToEnd(cList* list, cListNode* node);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_00154678(sBounds_96A8* out, void* iface, int id);
extern "C" void* func_0039FB30(void* self, void* parent, int a2);
extern "C" void func_0021CCC8(void* p);
extern "C" void func_00399730(void* obj, int hash);
extern void* D_004A28A8;
extern char D_004718F0[];
extern char D_00471908[];
extern void* D_00494AA8[];

static inline float Absf_96A8(float v)
{
    if (v < 0.0f) {
        v = -v;
    }
    return v;
}

extern "C" void cOVState_MAP_setupPlayerIndicator(void* selfp)
{
    sMapSt_96A8* self = (sMapSt_96A8*)selfp;
    void* ifMap = cBE_getInterface_Fv(cBE_getBE(), 10);
    void* ifGame = cBE_getInterface_Fv(cBE_getBE(), 0);
    sV3_96A8 mapPos = ((sFEObjData_96A8*)self->img)->pos;
    char* rider = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x28);
    sV4_96A8 pp = *((cRiderSub_96A8*)(rider + 0x6C0))->v05();
    sBounds_96A8 b;
    func_00154678(&b, ifMap, *func_00144BC0(ifGame));
    float fx = Absf_96A8((pp.x - b.minX) / (b.maxX - b.minX));
    int px = (int)(fx * 356.0f);
    float fy = Absf_96A8((pp.y - b.minY) / (b.maxY - b.minY));
    int py = (int)(fy * 266.0f);
    char* ind = (char*)cMemMan_alloc(0x88, D_004718F0, 0x20000000, 0);
    func_0039FB30(ind, self->screen, 0);
    *(void***)(ind + 0x8) = D_00494AA8;
    func_0021CCC8(ind + 0x74);
    *(int*)(ind + 0x78) = -1;
    self->ind = (cFEObj_96A8*)ind;
    *(int*)(ind + 0x7C) = 0;
    {
        sV3_96A8 p((float)(unsigned int)(px + 0xFC) - 5.0f, (float)(unsigned int)(py + 0x61) - 5.0f, mapPos.z);
        ((sFEObjData_96A8*)self->ind)->pos = p;
    }
    self->ind->SetScale(sV3_96A8(17.0f, 17.0f));
    func_00399730(self->ind, GetHashValue32(D_00471908));
    self->ind->SetVisible(0);
    sFEObjData_96A8* d = (sFEObjData_96A8*)self->ind;
    d->flags = (d->flags & ~0x1F00) | 0xD00;
    cList_addToEnd((cList*)(self->screen + 0xB4), (cListNode*)self->ind);
}
#endif

INCLUDE_ASM("fe/ovstatemap", cOVState_MAP_setupLocalSessionList);

//100%
INCLUDE_ASM("fe/ovstatemap", func_00209E78);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_00471850[];

class cUIObj_9E78 {
public:
    int pad[2];
    virtual ~cUIObj_9E78();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};
struct sMap_9E78 {
    char pad_0x0[0xC0];
    int count;              // 0xC0
    char pad_0xC4[0x10];
    void* screen;           // 0xD4
    char pad_0xD8[0x8];
    cUIObj_9E78* cursor;    // 0xE0
    cUIObj_9E78* a[8];      // 0xE4
    cUIObj_9E78* b[8];      // 0x104
};

extern "C" void func_00209E78(void* p)
{
    sMap_9E78* self = (sMap_9E78*)p;
    if (self->cursor != 0) {
        self->cursor->setVisible(1);
    }
    void* list = *(void**)((char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471850)) + 0xA0);
    int sel = 1;
    if (list != 0) {
        sel = *(int*)((char*)list + 0x18);
    }
    for (int i = 0; i < self->count; i++) {
        int cur = sel - 1;
        if (i == cur) {
            if (self->a[i] != 0) {
                self->a[i]->setVisible(0);
            }
            if (self->b[i] != 0) {
                self->b[i]->setVisible(1);
            }
        } else {
            if (self->a[i] != 0) {
                self->a[i]->setVisible(1);
            }
            if (self->b[i] != 0) {
                self->b[i]->setVisible(0);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_0020A088);
#ifdef SKIP_ASM
class cUIObj_A088 {
public:
    int pad[2];
    virtual ~cUIObj_A088();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};

struct sMap_A088 {
    char pad_0x0[0xE0];
    cUIObj_A088* cursor;    // 0xE0
    cUIObj_A088* a[8];      // 0xE4
    cUIObj_A088* b[8];      // 0x104
};

extern "C" void func_0020A088(void* p)
{
    sMap_A088* self = (sMap_A088*)p;
    if (self->cursor != 0) {
        self->cursor->setVisible(0);
        delete self->cursor;
        self->cursor = 0;
    }
    for (int i = 0; i < 8; i++) {
        if (self->a[i] != 0) {
            self->a[i]->setVisible(0);
            delete self->a[i];
            self->a[i] = 0;
        }
        if (self->b[i] != 0) {
            self->b[i]->setVisible(0);
            delete self->b[i];
            self->b[i] = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_0020A1A8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int sprintf(char* buf, const char* fmt, ...);
// PORT: SN soft-float float->double conversion (the source passed floats to sprintf).
extern "C" double func_00413AF8(float f);
extern char D_004C6848[];
extern char D_004719F0[];
extern char D_00471A00[];

struct sGameSettings_A1A8 {
    unsigned int flags;     // 0x0, bits 22..24 = language
    int pad[0x288 / 4 - 1];
};
extern sGameSettings_A1A8 D_00535610_A1A8 __asm__("D_00535610");

// Format a time in seconds as minutes/seconds for the current language.
extern "C" char* func_0020A1A8(int secs)
{
    cBE_getInterface_Fv(cBE_getBE(), 4);
    int m = secs / 60;
    int s = secs % 60;
    sGameSettings_A1A8 set = D_00535610_A1A8;
    switch ((set.flags >> 22) & 7) {
    case 0:
    case 2:
        sprintf(D_004C6848, D_004719F0, func_00413AF8((float)m), func_00413AF8((float)s));
        break;
    case 1:
    case 3:
        sprintf(D_004C6848, D_00471A00, func_00413AF8((float)m), func_00413AF8((float)s));
        break;
    }
    return D_004C6848;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_0020A380);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A20D0[];
extern void* D_004A28A8;
extern "C" void func_002EA820(void* self);
extern "C" void* func_0039F9D8(void* list, int hash);
struct sVEntry0020A380 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

struct sSelf0020A380 {
    char pad[0x10];
    char* mgr;
    char pad14[0x3C];
    int pdaOn;
};

extern "C" void func_0020A380(sSelf0020A380* self)
{
    self->pdaOn = 0;
    char* game = *(char**)((char*)D_004A28A8 + 0x84);
    if (game != 0) {
        char* p = *(char**)(game + 0x64);
        int mode = *(int*)(p + 0x10);
        if (mode != 0) {
            func_002EA820(p);
            if (mode == 1 || mode == 3) {
                self->pdaOn = 1;
            }
        }
    }
    char* obj = (char*)func_0039F9D8(self->mgr + 0x18, GetHashValue32(D_004A20D0));
    if (obj != 0) {
        sVEntry0020A380* e = &(*(sVEntry0020A380**)(obj + 8))[24];
        e->fn(obj + e->delta, 3, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_0020A430);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A20D0[];
extern void* D_004A28A8;
extern "C" void func_002EA860(void* self);
extern "C" void* func_0039F9D8(void* list, int hash);
extern "C" void func_0020D190();
void* func_0039E4A0(void* self);
struct sVEntry0020A430 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" void func_0020A430(void* self)
{
    if (*(int*)((char*)self + 0x50) != 0) {
        char* game = *(char**)((char*)D_004A28A8 + 0x84);
        if (game != 0) {
            func_002EA860(*(void**)(game + 0x64));
            *(int*)((char*)self + 0x50) = 0;
        }
    }
    char* obj = (char*)func_0039F9D8(*(char**)((char*)self + 0x10) + 0x18, GetHashValue32(D_004A20D0));
    if (obj != 0) {
        sVEntry0020A430* e = &(*(sVEntry0020A430**)(obj + 8))[24];
        e->fn(obj + e->delta, 4, 0);
    }
    if (*(int*)((char*)self + 0x54) != 0) {
        func_0020D190();
    }
    func_0039E4A0(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_0020A4E0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" void* cBXString_Concat(void* self, const char* str);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void func_003A19F8(void* text, char* str);
extern "C" void func_001A83D8(void* list, int keep, unsigned int sel, int a3, int pos, int a5, int a6, int trim);
extern "C" int func_00258160(int a, char* name, int len);
extern void* D_004A28A8;
extern int* D_004A2EEC_A4E0 __asm__("D_004A2EEC");
extern char D_00534B30[];
extern char D_0046E660[];
extern char D_0046E7F8[];
extern char D_0046E808[];
extern char D_004A2710[];

struct sBXString_A4E0 {
    char* str;
    sBXString_A4E0() {}
    sBXString_A4E0(const sBXString_A4E0& o);
};

struct sVE_A4E0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void show_A4E0(char* o, int on)
{
    sVE_A4E0* vt = *(sVE_A4E0**)(o + 8);
    vt[9].fn(o + vt[9].delta, on);
}

// PORT: the session pointer is passed through func_00258160's int parameter.
extern "C" int func_0020A4E0(char* self)
{
    int ret = 0;
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    char* net = D_00534B30;
    if (*(int*)net != 0 && *(void**)(self + 0x40) != 0) {
        int* sess = D_004A2EEC_A4E0;
        if (sess != 0 && *sess != 0) {
            char* name = self + 0x58;
            if (func_00258160((int)sess, name, 0x41) != 0) {
                char* a = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0046E660));
                if (a != 0)
                    show_A4E0(a, 0);
                char* b = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0046E7F8));
                if (b != 0)
                    show_A4E0(b, 0);
                ret = 1;
                char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0046E808));
                unsigned short c8 = *(unsigned short*)(obj + 0xC8);
                unsigned short c4 = *(unsigned short*)(obj + 0xC4);
                unsigned short c6 = *(unsigned short*)(obj + 0xC6);
                int none = c8 == 0;
                sBXString_A4E0 s;
                cBXString_cBXString2(&s, net + 0x498);
                cBXString_Concat(&s, D_004A2710);
                cBXString_Concat(&s, name);
                func_003A19F8(obj, s.str);
                func_001A83D8(obj, 0x28, 4, c8, c4, c6, none, 1);
                show_A4E0(obj, 1);
                cBXString__cBXString(&s, 2);
            }
        }
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_0020A6A8);
#ifdef SKIP_ASM
struct sVEntry0020A6A8 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern void* D_004A28A8;

extern "C" void func_0020A6A8(void* self, int a1, int a2)
{
    char* w = *(char**)((char*)D_004A28A8 + 0x84);
    if (w != 0) {
        char* o = *(char**)(w + 0x200);
        if (o != 0) {
            sVEntry0020A6A8* vt = *(sVEntry0020A6A8**)(o + 0xC);
            vt[9].fn(o + vt[9].delta, a1, a2);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemap", func_0020A6F0);
#ifdef SKIP_ASM
extern "C" void* cUIAnimationBank_getAnimationByHashName(void* self, int hash);
extern "C" void func_0039FCC8(void* self, void* anim, int mode, int v, int a4);

extern "C" void func_0020A6F0(void* self, char* objName, char* animName)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(objName));
    if (obj != 0) {
        void* bank = (char*)*(void**)((char*)self + 0x10) + 0x50;
        void* anim = cUIAnimationBank_getAnimationByHashName(bank, GetHashValue32(animName));
        if (anim != 0) {
            func_0039FCC8(obj, anim, 3, 0, 0);
        }
    }
}
#endif

