#include "common.h"

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cOVStateManager_addPDATemplate();
extern "C" void cUITemplate_MAP_setShowInfo(void* self, int show);
extern "C" int func_001A3BF0(void* mgr);
extern "C" void cUITemplate_MAP_setupPeakUnlock(void* self);
struct cUITemplate_MAP;
void cUITemplate_MAP_setupEventUnlock(cUITemplate_MAP* self);
extern "C" void cUITemplate_MAP_setupLayout(void* self);
extern "C" void cUITemplate_MAP_setupMapPic(void* self);
extern "C" void cUITemplate_MAP_setupPopup(char* self);
extern "C" void cUITemplate_MAP_setupPeakInfo(void* self);
extern unsigned int D_004A2594;
extern int D_004A2598;
extern int D_004A259C;
extern void* D_004A28A8;
extern char D_004A25A8[];
extern char D_004A25B0[];
extern char D_004A25B8[];
extern char D_004A25C0[];
extern char D_004A25C8[];
extern char D_004A25D0[];
extern char D_004A25D8[];
extern char D_004704C8[];
extern char D_004704D8[];
extern char D_004704E8[];
extern char D_004704F8[];
extern char D_00470508[];
extern char D_00470518[];
extern char D_00470528[];
extern char D_00470538[];
extern char D_00470548[];
extern char D_00470558[];
extern char D_00470568[];
extern char D_00470578[];
extern char D_00470588[];
extern char D_00470598[];
extern char D_004705A8[];
extern char D_004705B8[];
extern char D_004705C8[];
extern char D_004705D8[];
extern char D_004705E8[];

class cUIObj_200700 {
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
    virtual void v09(int on);
};

struct sMapTmpl_200700 {
    char pad0[0x2CC];
    int popup;                  // 0x2CC
    int mode;                   // 0x2D0
    int pic;                    // 0x2D4
    int file;                   // 0x2D8
    int f2DC;
    int f2E0;
    cUIObj_200700* map;         // 0x2E4
    void* screen;               // 0x2E8
    void* owner;                // 0x2EC
    int f2F0;                   // 0x2F0
};

extern "C" void cUITemplate_MAP_onCreateScreen(void* tmpl, void* screen, void* owner)
{
    sMapTmpl_200700* self = (sMapTmpl_200700*)tmpl;
    self->owner = owner;
    self->screen = screen;
    if (D_004A2594 == 1 || D_004A2594 == 3 || D_004A2594 == 4)
        cOVStateManager_addPDATemplate();
    if (D_004A2594 != 0 || D_004A2598 == 0)
        D_004A259C = 0;
    cUITemplate_MAP_setShowInfo(self, 0);
    self->popup = 0;
    self->mode = -1;
    self->file = func_001A3BF0(*(void**)((char*)D_004A28A8 + 0x11C));
    self->pic = 0;
    cUIObj_200700* o = (cUIObj_200700*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A25A8));
    self->map = o;
    if (o != 0)
        o->v09(0);
    self->f2F0 = 0;
    cUITemplate_MAP_setupPeakUnlock(self);
    cUITemplate_MAP_setupEventUnlock((cUITemplate_MAP*)self);
    cUITemplate_MAP_setupLayout(self);
    cUITemplate_MAP_setupMapPic(self);
    cUITemplate_MAP_setupPopup((char*)self);
    if (D_004A2594 >= 2)
        cUITemplate_MAP_setupPeakInfo(self);
    if (D_004A2594 < 2) {
        cUIState_hideObjSafe(self->owner, D_004704C8);
        cUIState_hideObjSafe(self->owner, D_004A25B0);
        if (D_004A2594 == 0) {
            cUIState_hideObjSafe(self->owner, D_004A25B8);
        } else {
            cUIState_hideObjSafe(self->owner, D_004704D8);
            cUIState_hideObjSafe(self->owner, D_004704E8);
            cUIState_hideObjSafe(self->owner, D_004704F8);
            cUIState_hideObjSafe(self->owner, D_00470508);
        }
    } else {
        cUIState_hideObjSafe(self->owner, D_004A25C0);
        cUIState_showObjSafe(self->owner, D_00470518);
    }
    if (D_004A2594 == 4) {
        cUIState_hideObjSafe(self->owner, D_00470528);
        cUIState_hideObjSafe(self->owner, D_00470538);
        cUIState_hideObjSafe(self->owner, D_004A25C8);
        cUIState_hideObjSafe(self->owner, D_004A25D0);
    }
    cUIState_hideObjSafe(self->owner, D_004A25D8);
    cUIState_hideObjSafe(self->owner, D_00470548);
    cUIState_hideObjSafe(self->owner, D_00470558);
    cUIState_hideObjSafe(self->owner, D_00470568);
    cUIState_hideObjSafe(self->owner, D_00470578);
    cUIState_hideObjSafe(self->owner, D_00470588);
    cUIState_hideObjSafe(self->owner, D_00470598);
    cUIState_hideObjSafe(self->owner, D_004705A8);
    cUIState_hideObjSafe(self->owner, D_004705B8);
    cUIState_hideObjSafe(self->owner, D_004705C8);
    cUIState_hideObjSafe(self->owner, D_004705D8);
    cUIState_hideObjSafe(self->owner, D_004705E8);
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_002009D0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00144BC0(void* iface);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
int GetHashValue32(char* str);
extern char D_00470600[];
extern unsigned int D_004A2594;
static inline int isLabel2009D0(int id, char* s)
{
    return id == GetHashValue32(s);
}
// PORT: the unit declares func_002009D0(void*); the body also takes the menu in $5.
extern "C" void func_002009D0_r(void* self, void* menu) __asm__("func_002009D0");

extern "C" void func_002009D0_r(void* self, void* menu)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    if (isLabel2009D0(*(int*)((char*)menu + 0x38), D_00470600)) {
        if (D_004A2594 < 2) {
            cUIMenu_setSelectedByIndex(menu, 2);
        } else {
            cUIMenu_setSelectedByIndex(menu, 2 - *(unsigned char*)((char*)func_00144BC0(iface) + 0x54));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00200A70);
#ifdef SKIP_ASM
extern "C" void cUITemplate_MAP_setupMenuFocus(void* self, int focus);
extern "C" void cUITemplate_MAP_setupMenus(void* self);
extern "C" void func_00207430(void* self);
extern "C" void cUITemplate_MAP_setShowInfo(void* self, int show);
extern int D_004A259C;
// PORT: the unit declares func_00200A70(void*); the body also takes a flag in $5.
extern "C" int func_00200A70_r(void* self, int on) __asm__("func_00200A70");

extern "C" int func_00200A70_r(void* self, int on)
{
    if (on != 0) {
        cUITemplate_MAP_setupMenuFocus(self, D_004A259C);
        cUITemplate_MAP_setupMenus(self);
        func_00207430(self);
        cUITemplate_MAP_setShowInfo(self, *(int*)self);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00200AC0);
#ifdef SKIP_ASM
extern "C" void cUITemplate_MAP_setupMenuFocus(void* self, int focus);
extern "C" void* func_0028B180(void);
extern "C" void func_0028F5B8(void* mgr);
extern int D_004A259C;

extern "C" void func_00200AC0(void* self)
{
    cUITemplate_MAP_setupMenuFocus(self, D_004A259C);
    func_0028F5B8(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00200AF0);
#ifdef SKIP_ASM
extern "C" void cFEAsyncManager_UnloadFEAsyncFile(void* mgr, int file);
extern "C" void func_0020D190(void);
extern "C" void* func_0028B180(void);
extern "C" void func_0028F678(void* mgr, int a);
extern void* D_004A28A8;
extern unsigned int D_004A2594;

extern "C" void func_00200AF0(void* self)
{
    cFEAsyncManager_UnloadFEAsyncFile(*(void**)((char*)D_004A28A8 + 0x11C), *(int*)((char*)self + 0x2D8));
    if (D_004A2594 == 1 || D_004A2594 == 3 || D_004A2594 == 4) {
        func_0020D190();
    }
    func_0028F678(func_0028B180(), 0);
}
#endif

INCLUDE_ASM("fe/uitemplatemap", func_00200B50);

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00200D00);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBELibrary_getCharacterID(int);
extern "C" int func_001464D0(void* iface, int player, int charID, int x, int flag);
extern "C" int func_00146A70(void* iface, int player, int charID, int x);

extern "C" int func_00200D00(void* self, int kind, int x)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    if (D_004A2594 < 2) {
        return 0;
    }
    if (kind == 4) {
        return func_001464D0(iface, 0, cBELibrary_getCharacterID(0), x, 1);
    }
    if (kind == 5) {
        return func_001464D0(iface, 0, cBELibrary_getCharacterID(0), x, 0);
    }
    if (kind >= 6 && kind <= 11) {
        return func_00146A70(iface, 0, cBELibrary_getCharacterID(0), kind);
    }
    return 0;
}
#endif

INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupMenus);

struct cUITemplate_MAP {
    char pad_0x00[0x10];
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1C;
};
extern unsigned int D_004A2594;

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupEventUnlock__FP15cUITemplate_MAP);
#ifdef SKIP_ASM
void cUITemplate_MAP_setupEventUnlock(cUITemplate_MAP* self)
{
    self->field_0x1C = 0;
    self->field_0x10 = 1;
    self->field_0x14 = 1;
    if (D_004A2594 < 2) {
        self->field_0x18 = 0;
    } else {
        self->field_0x18 = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupPeakUnlock);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" int cBENewPlayerInterface_isPeakLocked(void* self, int a, int b, int peak);
extern "C" int cBENewPlayerInterface_isPeakLocked1(void* self, int rider, int peak);
extern char D_00535BC8[];

struct sPeakUnlock_MAP {
    int pad0;
    int unlocked[3];    // 0x4, indexed by peak
};

// Marks each peak as unlocked unless it is still locked for the active rider(s).
extern "C" void cUITemplate_MAP_setupPeakUnlock(void* p)
{
    sPeakUnlock_MAP* self = (sPeakUnlock_MAP*)p;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    self->unlocked[0] = 1;
    self->unlocked[1] = 1;
    self->unlocked[2] = 1;
    for (int peak = 1; peak < 3; peak++) {
        int locked;
        if (D_00535BC8[0x49] == 2) {
            locked = cBENewPlayerInterface_isPeakLocked(player, 0, cBENewPlayerInterface_getPlayerCharID(player, 0), peak);
            if (locked) {
                locked = cBENewPlayerInterface_isPeakLocked(player, 1, cBENewPlayerInterface_getPlayerCharID(player, 1), peak);
            }
        } else {
            locked = cBENewPlayerInterface_isPeakLocked1(player, 0, peak);
        }
        // The store sits in its own do { } while (0) block (macro-style); the extra loop level is what
        // gives the slot pointer priority over the peak counter in register allocation.
        do {
            if (locked) {
                self->unlocked[peak] = 0;
            }
        } while (0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00201868);
#ifdef SKIP_ASM
struct sVEntry00201868 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00201868(void* self)
{
    *(int*)((char*)self + 0x2F0) = 1;
    *(int*)((char*)self + 0x2DC) = 0;
    void* obj = *(void**)((char*)self + 0x2E4);
    if (obj != 0) {
        sVEntry00201868* vt = *(sVEntry00201868**)((char*)obj + 8);
        vt[9].fn((char*)obj + vt[9].delta, 0);
    }
}
#endif

INCLUDE_ASM("fe/uitemplatemap", func_002018A8);

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00202738);
#ifdef SKIP_ASM
extern "C" int func_00202738(void* self, int a1, int a2)
{
    if (a2 == 6 || a2 == 9 || a2 == 8) {
        return 0;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00202768__FPv);
#ifdef SKIP_ASM
int func_00202768(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00202770);
#ifdef SKIP_ASM
extern "C" void cUITemplate_MAP_setupPeakInfo(void* self);
extern "C" void cUITemplate_MAP_setupPeakGoals(void* self);
extern "C" void cUITemplate_MAP_setupLayout(void* self);
extern "C" void func_00207430(void* self);
extern int D_004A259C;

struct sVEntry00202770 {
    short delta;
    short index;
    int (*fn)(void*);
};

// PORT: the unit declares func_00202770(void*); the body also takes the menu object in $5.
extern "C" void func_00202770_r(void* self, void* menu) __asm__("func_00202770");

extern "C" void func_00202770_r(void* self, void* menu)
{
    sVEntry00202770* e = &(*(sVEntry00202770**)((char*)menu + 8))[17];
    if (e->fn((char*)menu + e->delta) == 0) {
        sVEntry00202770* e2 = &(*(sVEntry00202770**)((char*)menu + 8))[18];
        if (e2->fn((char*)menu + e2->delta) == 0) {
            return;
        }
    }
    if (D_004A259C == 0) {
        cUITemplate_MAP_setupPeakInfo(self);
        cUITemplate_MAP_setupLayout(self);
    }
    if (D_004A259C == 1) {
        cUITemplate_MAP_setupPeakGoals(self);
        cUITemplate_MAP_setupLayout(self);
    }
    if (D_004A259C == 2) {
        func_00207430(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_onUpdate);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00144BC0(void* iface);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" int sprintf(char* buf, const char* fmt, ...);
struct cFEAsyncManager;
int cFEAsyncManager_GetFileStatus(cFEAsyncManager* self, int index);
extern char D_00470588[];
extern char D_00470598[];
extern char D_004705A8[];
extern char D_004707A0[];
extern char D_004707B0[];
extern int D_004A259C;
extern unsigned int D_004A2594;
extern void* D_004A28A8;

struct sColor_202828 {
    float a, r, g, b;
};

class cUIPic_202828 {
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
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(sColor_202828* c);
};

extern "C" void cUITemplate_MAP_onUpdate(void* vself)
{
    char* self = (char*)vself;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    if (*(int*)(self + 0x2DC) != 0) {
        if (*(float*)(self + 0x2E0) < 1.0f)
            *(float*)(self + 0x2E0) += 0.1f;
        cUIPic_202828* pic = *(cUIPic_202828**)(self + 0x2E4);
        sColor_202828 c = *(sColor_202828*)((char*)pic + 0x1C);
        c.a = *(float*)(self + 0x2E0);
        pic->v11(&c);
        (*(cUIPic_202828**)(self + 0x2E4))->v09(1);
        if (D_004A259C == 0) {
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470588);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470598);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004705A8);
        } else {
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004707A0);
        }
    } else {
        *(float*)(self + 0x2E0) = 0.0f;
        (*(cUIPic_202828**)(self + 0x2E4))->v09(0);
        if (D_004A259C == 0) {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470588);
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470598);
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004705A8);
        } else {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707A0);
        }
    }
    if (*(int*)(self + 0x2F0) != 0)
        return;
    for (int i = 0; i < 3; i++) {
        char buf[0x20];
        sprintf(buf, D_004707B0, i + 1);
        if (*(int*)(self + 0x2DC) != 0 && D_004A259C == 0 && i == *(int*)((char*)func_00144BC0(iface) + 0x54) &&
            *(int*)self == 0 && D_004A2594 >= 2)
            cUIState_showObjSafe(*(void**)(self + 0x2EC), buf);
        else
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), buf);
    }
    char* mgr = *(char**)((char*)D_004A28A8 + 0x11C);
    if (cFEAsyncManager_GetFileStatus((cFEAsyncManager*)mgr, *(int*)(self + 0x2D8)) == 3 && *(int*)(self + 0x2DC) == 0) {
        char* pic = *(char**)(self + 0x2E4);
        if (pic != 0) {
            int tex = *(int*)(mgr + *(int*)(self + 0x2D8) * 0x11C + 0x110);
            *(int*)(pic + 0x7C) = 0;
            *(int*)(pic + 0x78) = tex;
            *(int*)(self + 0x2DC) = 1;
            *(float*)(self + 0x2E0) = 0.0f;
        }
    }
}
#endif

INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupLayout);

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupMenuFocus);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void cUITemplate_MAP_setShowInfo(void* self, int show);
extern "C" void cUITemplate_MAP_setupPeakInfo(void* self);
extern "C" void cUITemplate_MAP_setupPeakGoals(void* self);
extern char D_00470600[];
extern char D_00470918[];
extern char D_00470928[];
extern char D_00470938[];
extern char D_00470948[];
extern char D_00470960[];
extern char D_00470978[];
extern char D_00470990[];
extern char D_004709A8[];
extern char D_004709C0[];
extern char D_004709D8[];
extern char D_004709F0[];
extern char D_00470A08[];
extern char D_00470A20[];
extern char D_00470518[];
extern char D_004706C8[];
extern char D_004707C0[];
extern char D_00470A30[];
extern char D_00470A48[];
extern char D_004A2610[];
extern int D_004A259C;
extern int D_004A25A0;
extern int D_004A25A4;
extern unsigned int D_004A2594;

class cUIObj_MFocusB {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08(int on);
    virtual void v09(int on);
};
class cUIObj_MFocus : public cUIObj_MFocusB {
public:
    int f0C;
    int f10;
    unsigned flags;
};

static inline cUIObj_MFocus* hideObj(char* self, char* name)
{
    cUIObj_MFocus* o = (cUIObj_MFocus*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(name));
    if (o != 0) {
        o->v07(0);
        o->v09(0);
    }
    return o;
}

static inline void showObj(cUIObj_MFocus* o)
{
    o->flags |= 1;
    o->v09(1);
    o->v07(1);
}

extern "C" void cUITemplate_MAP_setupMenuFocus(void* self_, int mode)
{
    char* self = (char*)self_;
    cUITemplate_MAP_setShowInfo(self, 0);
    D_004A259C = mode;
    cUIObj_MFocus* o0 = hideObj(self, D_00470600);
    cUIObj_MFocus* o1 = hideObj(self, D_00470918);
    cUIObj_MFocus* o2 = hideObj(self, D_00470928);
    cUIObj_MFocus* o3 = hideObj(self, D_00470938);
    cUIObj_MFocus* o4 = hideObj(self, D_00470948);
    cUIObj_MFocus* o5 = hideObj(self, D_00470960);
    cUIObj_MFocus* o6 = hideObj(self, D_00470978);
    cUIObj_MFocus* o7 = hideObj(self, D_00470990);
    cUIObj_MFocus* o8 = hideObj(self, D_004709A8);
    cUIObj_MFocus* o9 = hideObj(self, D_004709C0);
    cUIObj_MFocus* o10 = hideObj(self, D_004709D8);
    cUIObj_MFocus* o11 = hideObj(self, D_004709F0);
    cUIObj_MFocus* o12 = hideObj(self, D_00470A08);
    cUIObj_MFocus* o13 = hideObj(self, D_00470A20);
    if (*(int*)(self + 0x2CC) != 0) {
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2610);
        o13->v07(1);
        o13->v09(1);
        if (*(int*)(self + 0x2D0) == 0) {
            cUIObj_MFocus* o = (cUIObj_MFocus*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004706C8));
            o->v09(1);
            o->v08(0);
        } else {
            cUIObj_MFocus* o = (cUIObj_MFocus*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004706C8));
            o->v09(0);
            o->v08(1);
        }
        return;
    }
    switch (D_004A259C) {
    case 0:
        cUITemplate_MAP_setupPeakInfo(self);
        if (o0 != 0) {
            o0->flags |= 1;
            o0->v07(1);
            o0->v09(1);
        }
        if (D_004A2594 < 2) {
            cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470518));
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_004707C0));
        }
        break;
    case 1:
        cUITemplate_MAP_setupPeakGoals(self);
        if (D_004A25A4 == 0 && o1 != 0) {
            showObj(o1);
        } else if (D_004A25A4 == 1 && o2 != 0) {
            showObj(o2);
        } else if (o3 != 0) {
            showObj(o3);
        }
        if (D_004A2594 < 2) {
            cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470518));
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470A30));
        }
        break;
    case 2: {
        cUIObj_MFocus* sel = 0;
        if (D_004A25A4 == 0) {
            if (D_004A25A0 == 0) sel = o4;
            else if (D_004A25A0 == 1) sel = o5;
            else if (D_004A25A0 == 2) sel = o6;
        } else if (D_004A25A4 == 1) {
            if (D_004A25A0 == 0) sel = o7;
            else if (D_004A25A0 == 1) sel = o8;
            else if (D_004A25A0 == 2) sel = o9;
        } else if (D_004A25A4 == 2) {
            if (D_004A25A0 == 0) sel = o10;
            else if (D_004A25A0 == 1) sel = o11;
            else if (D_004A25A0 == 2) sel = o12;
        }
        if (sel != 0) {
            showObj(sel);
        }
        if (D_004A2594 < 2) {
            cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470518));
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470A48));
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupMapPic);
#ifdef SKIP_ASM
extern "C" void cFEAsyncManager_Load3PeakPic(void* mgr, int file, int a);
extern "C" void cFEAsyncManager_Load1PeakPic(void* mgr, int peak, int file, int a);
extern int D_004A25A4;

extern "C" void cUITemplate_MAP_setupMapPic(void* self)
{
    void* mgr = *(void**)((char*)D_004A28A8 + 0x11C);
    if (D_004A259C == 0) {
        if (*(int*)((char*)self + 0x2D4) != 1) {
            cFEAsyncManager_UnloadFEAsyncFile(mgr, *(int*)((char*)self + 0x2D8));
            cFEAsyncManager_Load3PeakPic(mgr, *(int*)((char*)self + 0x2D8), 1);
            *(int*)((char*)self + 0x2D4) = 1;
            *(int*)((char*)self + 0x2DC) = 0;
        }
    } else if (D_004A259C >= 0) {
        if (D_004A259C < 3) {
            if (*(int*)((char*)self + 0x2D4) != D_004A25A4 + 2) {
                cFEAsyncManager_UnloadFEAsyncFile(mgr, *(int*)((char*)self + 0x2D8));
                cFEAsyncManager_Load1PeakPic(mgr, D_004A25A4, *(int*)((char*)self + 0x2D8), 1);
                int v = D_004A25A4 + 2;
                *(int*)((char*)self + 0x2DC) = 0;
                *(int*)((char*)self + 0x2D4) = v;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupPopup);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_0046FAA0[];
extern char D_004706B8[];
extern char D_004706C8[];
extern char D_00470700[];
extern char D_00470A20[];
extern char D_00470A60[];
extern char D_00470A70[];
extern char D_00470A80[];
extern char D_00470A98[];
extern char D_00470AA8[];
extern char D_004A25B0[];
extern char D_004A2638[];
extern char D_004A2640[];
extern int D_004A259C;

class cUIObj_203A58 {
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

extern "C" void cUITemplate_MAP_setupPopup(char* self)
{
    if (*(int*)(self + 0x2CC) != 0) {
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470A60);
        void* menu = cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470A20));
        if (menu != 0)
            cUIMenu_setSelectedByIndex(menu, 0);
        if (*(int*)(self + 0x2CC) != 0) {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2638);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A2640);
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A25B0);
            cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470A70));
            if (D_004A259C == 0) {
                if (t != 0)
                    cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470A80));
            } else {
                if (t != 0)
                    cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470A98));
            }
        }
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470700);
        cUIText* title = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004706B8));
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004706C8));
        if (*(int*)(self + 0x2D0) == 1) {
            if (title != 0)
                cUIText_setUnicodeStringByID(title, GetHashValue32(D_0046FAA0));
            if (o != 0) {
                ((cUIObj_203A58*)o)->v09(0);
                ((cUIObj_203A58*)o)->v08(1);
            }
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004706C8);
        } else {
            if (title != 0)
                cUIText_setUnicodeStringByID(title, GetHashValue32(D_00470AA8));
            if (o != 0) {
                ((cUIObj_203A58*)o)->v09(1);
                ((cUIObj_203A58*)o)->v08(0);
            }
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004706C8);
        }
    } else {
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470A60);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A25B0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setShowInfo);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_00470AB8[];
extern char D_00470AC8[];
extern char D_00470AD8[];

extern "C" void cUITemplate_MAP_setShowInfo(void* self, int show)
{
    *(int*)self = show;
    cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x2E8), GetHashValue32(D_00470AB8));
    if (*(int*)self != 0) {
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470AC8));
    } else {
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470AD8));
    }
}
#endif

INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupPeakInfo);

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00204FF0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern void* D_004A28A8;
extern char D_00470E10[];
extern char D_00470E20[];
extern char D_00470E30[];
extern char D_00470E40[];

struct sVEntry00204FF0 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int setPic00204FF0(char* name)
{
    void* obj = *(void**)((char*)D_004A28A8 + 0x8C);
    sVEntry00204FF0* vt = *(sVEntry00204FF0**)((char*)obj + 4);
    return vt[4].fn((char*)obj + vt[4].delta, GetHashValue32(name));
}

extern "C" int func_00204FF0(void* self, int peak)
{
    switch (peak) {
    case 0:
    default:
        return setPic00204FF0(D_00470E10);
    case 1:
        return setPic00204FF0(D_00470E20);
    case 2:
        return setPic00204FF0(D_00470E30);
    case 3:
        return setPic00204FF0(D_00470E40);
    }
}
#endif

INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupPeakGoals);

INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_showEventPath);

INCLUDE_ASM("fe/uitemplatemap", func_00207430);

//100%
INCLUDE_ASM("fe/uitemplatemap", func_002083D8);
#ifdef SKIP_ASM
struct sVEntry_func_002083D8 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};
extern char D_004C8B38[];
extern char D_004C8B28[];

extern "C" void func_002083D8(void* self, void* obj, int on)
{
    if (obj != 0) {
        if (on != 0) {
            sVEntry_func_002083D8* vt = *(sVEntry_func_002083D8**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B38);
        } else {
            sVEntry_func_002083D8* vt = *(sVEntry_func_002083D8**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B28);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00208438);
#ifdef SKIP_ASM
struct sVEntry_func_00208438 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};
extern char D_004C8B58[];
extern char D_004C8B48[];

extern "C" void func_00208438(void* self, void* obj, int on)
{
    if (obj != 0) {
        if (on != 0) {
            sVEntry_func_00208438* vt = *(sVEntry_func_00208438**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B58);
        } else {
            sVEntry_func_00208438* vt = *(sVEntry_func_00208438**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B48);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/uitemplatemap", func_00208498);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void func_0020A380(void* self);
extern "C" void cUITemplate_MAP_onCreateScreen(void* tmpl, void* screen, void* owner);
extern char D_004A26E8[];

extern "C" void func_00208498(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A26E8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    cUITemplate_MAP_onCreateScreen((char*)self + 0x9C, *(void**)((char*)self + 0x40), self);
}
#endif

extern "C" void* func_002009D0(void*);

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00208518__FPv);
#ifdef SKIP_ASM
void* func_00208518(void* self)
{
    return func_002009D0((char*)self + 0x9c);
}
#endif

extern "C" void* func_00200A70(void*);

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00208538__FPv);
#ifdef SKIP_ASM
void* func_00208538(void* self)
{
    return func_00200A70((char*)self + 0x9c);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/uitemplatemap", func_00208558);
#ifdef SKIP_ASM
extern "C" void func_0039E4C0(void* self, int a1);
extern "C" void func_00200AC0(void* self);

extern "C" void func_00208558(void* self, int a1)
{
    func_0039E4C0(self, a1);
    func_00200AC0((char*)self + 0x9C);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/uitemplatemap", func_00208588);
#ifdef SKIP_ASM
extern "C" void func_00200AF0(void* self);
extern "C" void func_0020A430(void* self);

extern "C" void func_00208588(void* self)
{
    func_00200AF0((char*)self + 0x9C);
    func_0020A430(self);
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_002085B8);
#ifdef SKIP_ASM
extern "C" int func_002018A8(void* p, void* obj, int msg);
// PORT: returns int (value unused here); the int return type keeps the target's register choice after the call.
extern "C" int func_0039F190(void* self, int a1);

extern "C" void func_002085B8(char* self, void* obj, int msg)
{
    if (func_002018A8(self + 0x9C, obj, msg) == 1) {
        func_0039F190(*(char**)(self + 0x10) + 0x18, 1);
        *(int*)(self + 0x1C) = (*(int*)(self + 0x1C) & ~0x3F00) | 0x780;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/uitemplatemap", func_00208610);
#ifdef SKIP_ASM
extern "C" int func_00208610(void* self, int a1, int a2)
{
    if (func_00202738((char*)self + 0x9C, a1, a2) != 0) {
        return 0x101;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00208638);
#ifdef SKIP_ASM
extern "C" void func_00208638(void* self)
{
    func_00202768((char*)self + 0x9c);
}
#endif

extern "C" void* func_00202770(void*);

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00208658__FPv);
#ifdef SKIP_ASM
void* func_00208658(void* self)
{
    return func_00202770((char*)self + 0x9c);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/uitemplatemap", func_00208678);
#ifdef SKIP_ASM
extern "C" void func_0020E900(void* self);
extern "C" void cUITemplate_MAP_onUpdate(void* self);

extern "C" void func_00208678(void* self)
{
    func_0020E900(self);
    cUITemplate_MAP_onUpdate((char*)self + 0x9C);
}
#endif

