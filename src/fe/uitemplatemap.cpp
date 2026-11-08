#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// A UI widget as cUIScreen_getObjectByHashName returns it: vptr at 0x8. Slot names from the prototype's
// _vt$8cUIThing (as in fe/feasyncfile); the other slots are known only by position.
class cUIThing {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void setEnabled(int on);
    virtual void setFocus(int on);
    virtual void setStatic(int on);
    virtual void setVisible(int on);
};

// Declarations shared by the functions of this unit.
struct cUITemplate_MAP;
struct cFEAsyncManager;
struct cUIText;
int GetHashValue32(char* str);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUITemplate_MAP_setShowInfo(void* self, int show);
extern "C" void cUITemplate_MAP_setupLayout(void* self);
extern "C" void cUITemplate_MAP_setupPeakInfo(void* self);
extern unsigned int D_004A2594;
extern int D_004A259C;
extern void* D_004A28A8;
extern char D_004A25B0[];
extern char D_00470518[];
extern char D_00470588[];
extern char D_00470598[];
extern char D_004705A8[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00144BC0(void* iface);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern char D_00470600[];
extern "C" void cUITemplate_MAP_setupMenuFocus(void* self, int focus);
extern "C" void func_00207430(void* self);
extern "C" void* func_0028B180(void);
extern "C" void cUITemplate_MAP_setupPeakGoals(void* self);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern int D_004A25A0;
extern int D_004A25A4;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_00470A20[];
extern char D_004706C8[];

// One 0x6C-byte goal entry of the per-peak goal tables (race: 4 per peak, freestyle: 5 per peak,
// freeride: 8 per peak).
struct sPeakGoal {
    int track;          // 0x00
    int f04;
    int kind;           // 0x08
    int f0C;
    int useTrackName;   // 0x10
    char name[0x1E];    // 0x14
    char help[0x23];    // 0x32 help-text key (func_00207430)
    char path[0x17];    // 0x55
};
extern sPeakGoal D_004781D0[3][4];
extern sPeakGoal D_004786E0[3][5];
extern sPeakGoal D_00478D38[3][8];

// The text database (D_004A28A8 + 0x8C): localised strings by hash through vtable slot 4 (as in func_00204FF0).
struct cTextDB_5098 {
    int pad;
    sVEntry<unsigned short*(void*, int)>* vt;
};
#define TextDB_5098 (*(cTextDB_5098**)((char*)D_004A28A8 + 0x8C))
// A macro, not an inline helper: an inline's key parameter is a pseudo that loop.c hoists out of case 0's loop.
#define Loc_5098(key) (TextDB_5098->vt[4].fn((char*)TextDB_5098 + TextDB_5098->vt[4].delta, GetHashValue32(key)))

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_onCreateScreen);
#ifdef SKIP_ASM
extern "C" void cOVStateManager_addPDATemplate();
extern "C" int func_001A3BF0(void* mgr);
extern "C" void cUITemplate_MAP_setupPeakUnlock(void* self);
void cUITemplate_MAP_setupEventUnlock(cUITemplate_MAP* self);
extern "C" void cUITemplate_MAP_setupMapPic(void* self);
extern "C" void cUITemplate_MAP_setupPopup(char* self);
extern int D_004A2598;
extern char D_004A25A8[];
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
extern char D_00470528[];
extern char D_00470538[];
extern char D_00470548[];
extern char D_00470558[];
extern char D_00470568[];
extern char D_00470578[];
extern char D_004705B8[];
extern char D_004705C8[];
extern char D_004705D8[];
extern char D_004705E8[];

struct sMapTmpl_200700 {
    char pad0[0x2CC];
    int popup;                  // 0x2CC
    int mode;                   // 0x2D0
    int pic;                    // 0x2D4
    int file;                   // 0x2D8
    int f2DC;
    int f2E0;
    cUIThing* map;         // 0x2E4
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
    cUIThing* o = (cUIThing*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A25A8));
    self->map = o;
    if (o != 0)
        o->setVisible(0);
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
extern "C" void cUITemplate_MAP_setupMenus(void* self);
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
extern "C" void func_0028F5B8(void* mgr);

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
extern "C" void func_0028F678(void* mgr, int a);

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

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupMenus);
#ifdef SKIP_ASM
extern "C" void func_00208438(void* self, void* obj, int on);
extern "C" int func_00200B50(void* self, sPeakGoal* loc, int peak);
extern "C" int func_00200D00(void* self, int kind, int x);
extern "C" int func_004165A8(const char*, const char*);
extern "C" const char* func_00144C60(void* iface, int id);
extern "C" unsigned short* func_002C2540(unsigned short* dst, const char* s);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" unsigned short* func_001FD190(int kind);
extern "C" void func_003A0E90(void* text, unsigned short* s);
void cUIText_setAsciiString(cUIText* text, const char* s);
extern "C" char* strcpy(char* d, const char* s);
extern char D_004A25E0[];
extern char D_004A25E8[];
extern char D_004A25F0[];
extern char D_00470610[];
extern char D_00470620[];
extern char D_00470630[];
extern char D_00470648[];
extern char D_00470660[];
extern char D_004A2560[];
extern char D_004A2590[];
extern char D_004706B8[];
extern char D_004C8B58[];

// A menu entry widget: cUIThing plus its menu index at 0x18; slot 11 sets the text colour.
class cUIObj_Menus : public cUIThing {
public:
    int f0C;
    int f10;
    int f14;
    int idx;            // 0x18
    void setIndex(int i) { idx = i; }
    virtual void v10();
    virtual void setColor(char* col);
};

// The MAP template as this function sees it.
struct sMapTmpl_200DE8 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int available[3][3][8];     // 0x20  [peak][mode][event]
    int f140[3][3][8];          // 0x140
    char pad260[0x2E8 - 0x260];
    void* screen;               // 0x2E8
};

// Location entries with track 0x17 have no event: no availability colour or text, the widget is made static.
static inline int hasEvent(int track) { return track != 0x17; }

extern "C" void cUITemplate_MAP_setupMenus(void* tmpl)
{
    sMapTmpl_200DE8* self = (sMapTmpl_200DE8*)tmpl;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    cUIObj_Menus* o;
    o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A25E0));
    if (o != 0) {
        o->setIndex(2);
        func_00208438(self, o, self->fC);
    }
    o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A25E8));
    if (o != 0) {
        o->setIndex(1);
        func_00208438(self, o, self->f8);
    }
    o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A25F0));
    if (o != 0) {
        o->setIndex(0);
        func_00208438(self, o, self->f4);
    }
    o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470610));
    if (o != 0) {
        o->setIndex(3);
        func_00208438(self, o, 0);
    }
    char buf[32];
    for (int i = 0; i < 3; i++) {
        sprintf(buf, D_00470620, i + 1);
        o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(buf));
        o->setIndex(0);
        func_00208438(self, o, self->f10);
        sprintf(buf, D_00470630, i + 1);
        o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(buf));
        o->setIndex(1);
        func_00208438(self, o, self->f14);
        sprintf(buf, D_00470648, i + 1);
        o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(buf));
        o->setIndex(2);
        func_00208438(self, o, self->f18);
        if (D_004A2594 < 2) {
            o->setStatic(1);
            o->setVisible(0);
        }
        sprintf(buf, D_00470660, i + 1);
        o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(buf));
        o->setIndex(3);
        func_00208438(self, o, self->f1C);
        if (D_004A2594 < 2) {
            o->setStatic(1);
            o->setVisible(0);
        }
    }
    for (int peak = 0; peak < 3; peak++) {
        for (int mode = 0; mode < 3; mode++) {
            int count;
            char fmt[24];
            if (mode == 0) {
                count = 4;
                strcpy(fmt, "Peak%dRaceLoc%d");
            } else if (mode == 1) {
                count = 5;
                strcpy(fmt, "Peak%dFreestyleLoc%d");
            } else {
                count = 8;
                strcpy(fmt, "Peak%dFreerideLoc%d");
            }
            for (int j = 0; j < count; j++) {
                sPeakGoal g = D_004781D0[peak][j];
                if (mode == 1)
                    g = D_004786E0[peak][j];
                if (mode == 2)
                    g = D_00478D38[peak][j];
                if (mode == 0 || mode == 1)
                    self->f140[peak][mode][j] = func_00200B50(self, &g, peak);
                sprintf(buf, fmt, peak + 1, j);
                o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(buf));
                if (D_004A2594 < 2 && g.f0C != 0) {
                    self->available[peak][mode][j] = 0;
                    if (o != 0) {
                        o->setVisible(0);
                        o->setStatic(1);
                    }
                } else {
                    self->available[peak][mode][j] = func_00200D00(self, g.kind, peak) ^ 1;
                }
                if (hasEvent(g.track))
                    func_00208438(self, o, self->available[peak][mode][j]);
                if (hasEvent(g.track)) {
                    if (g.useTrackName == 1) {
                        cUIText_setAsciiString((cUIText*)o, func_00144C60(iface, g.track));
                    } else if (func_004165A8(g.name, D_004A2560)) {
                        cUIText_setAsciiString((cUIText*)o, g.name);
                    } else if (g.kind == 4) {
                        unsigned short text[200];
                        unsigned short wfmt[24];
                        func_002C2540(wfmt, D_004A2590);
                        func_002C26D0(text, wfmt, func_00144C60(iface, g.track));
                        func_003A0E90(o, text);
                    } else {
                        func_003A0E90(o, func_001FD190(g.kind));
                    }
                    o->setIndex(j);
                } else if (o != 0) {
                    o->setStatic(1);
                }
            }
        }
    }
    o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004706B8));
    if (o != 0) {
        o->setIndex(0);
        o->setColor(D_004C8B58);
    }
    o = (cUIObj_Menus*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004706C8));
    if (o != 0) {
        o->setIndex(1);
        o->setColor(D_004C8B58);
    }
}
#endif

struct cUITemplate_MAP {
    char pad_0x00[0x10];
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1C;
};

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
extern "C" void func_00201868(void* self)
{
    *(int*)((char*)self + 0x2F0) = 1;
    *(int*)((char*)self + 0x2DC) = 0;
    void* obj = *(void**)((char*)self + 0x2E4);
    if (obj != 0) {
        sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)((char*)obj + 8);
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
// PORT: the unit declares func_00202770(void*); the body also takes the menu object in $5.
extern "C" void func_00202770_r(void* self, void* menu) __asm__("func_00202770");

extern "C" void func_00202770_r(void* self, void* menu)
{
    sVEntry<int(void*)>* e = &(*(sVEntry<int(void*)>**)((char*)menu + 8))[17];
    if (e->fn((char*)menu + e->delta) == 0) {
        sVEntry<int(void*)>* e2 = &(*(sVEntry<int(void*)>**)((char*)menu + 8))[18];
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
int cFEAsyncManager_GetFileStatus(cFEAsyncManager* self, int index);
extern char D_004707A0[];
extern char D_004707B0[];

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

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupLayout);
#ifdef SKIP_ASM
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern char D_0046F9E0[], D_00470600[], D_004706D8[], D_004707A0[], D_004707C0[], D_004707D8[], D_004707E8[], D_004707F8[];
extern char D_00470808[], D_00470818[], D_00470828[], D_00470840[], D_00470850[], D_00470860[], D_00470870[], D_00470888[];
extern char D_004708A0[], D_004708B8[], D_004708D0[], D_004708E0[], D_004708F8[], D_00470908[];
extern char D_004A25B0[], D_004A2608[], D_004A2610[], D_004A2618[], D_004A2620[], D_004A2628[], D_004A2630[];

static inline void hideAll_2B00(char* self)
{
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A25B0);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470808);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470818);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2618);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2620);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2628);
}

static inline void showAll_2B00(char* self)
{
    cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A25B0);
    cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470808);
    cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470818);
    cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A2618);
    cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A2620);
    cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A2628);
}

extern "C" void cUITemplate_MAP_setupLayout(void* vself)
{
    char* self = (char*)vself;
    char buf[0x20];
    char buf2[0x20];
    char buf3[0x20];
    void* text = cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_0046F9E0));
    switch (D_004A259C) {
    case 0: {
        unsigned char c;
        char* obj;
        cUIText_setUnicodeStringByID((cUIText*)text, GetHashValue32(D_004707C0));
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004707D8);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2608);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707E8);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707F8);
        if (*(int*)(self + 0x2CC) == 0) {
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A2610);
        }
        c = 0;
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707A0);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2608);
        obj = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470600));
        if (obj) c = obj[0x95];
        if (*(int*)self != 0) {
            if (c != 3) {
                cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A2608);
            }
        }
        if (c == 3) {
            hideAll_2B00(self);
        } else if (D_004A2594 >= 2) {
            showAll_2B00(self);
        }
        break;
    }
    case 1: {
        unsigned char b;
        char* obj;
        b = 0;
        cUIText_setUnicodeStringByID((cUIText*)text, GetHashValue32(D_00470828));
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707D8);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004707E8);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707F8);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2610);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004707A0);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470840);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470850);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470860);
        sprintf(buf, D_00470870, D_004A25A4);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), buf);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470888);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004708A0);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004708B8);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004708D0);
        sprintf(buf2, D_004706D8, D_004A25A4 + 1);
        obj = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(buf2));
        if (obj) b = obj[0x95];
        if (*(int*)self != 0 || b == 3) {
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004708D0);
            switch (b) {
            case 0:
            case 1:
                cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470888);
                break;
            case 2:
                cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004708A0);
                break;
            case 3:
                cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004708B8);
                break;
            }
        }
        if (b == 3) {
            hideAll_2B00(self);
        } else if (D_004A2594 >= 2) {
            showAll_2B00(self);
        }
        break;
    }
    case 2: {
        if (D_004A25A0 == 0) {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2610);
            cUIText_setUnicodeStringByID((cUIText*)text, GetHashValue32(D_004708E0));
        } else if (D_004A25A0 == 1) {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2610);
            cUIText_setUnicodeStringByID((cUIText*)text, GetHashValue32(D_004708F8));
        } else {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2610);
            cUIText_setUnicodeStringByID((cUIText*)text, GetHashValue32(D_00470908));
        }
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707D8);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004707E8);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004707F8);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004707A0);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470840);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470850);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470860);
        sprintf(buf, D_00470870, D_004A25A4);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), buf);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004A2630);
        if (*(int*)self != 0) {
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A2630);
        }
        func_00207430(self);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470840);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470850);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470860);
        sprintf(buf3, D_00470870, D_004A25A4);
        cUIState_showObjSafe(*(void**)(self + 0x2EC), buf3);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupMenuFocus);
#ifdef SKIP_ASM
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
extern char D_004707C0[];
extern char D_00470A30[];
extern char D_00470A48[];
extern char D_004A2610[];

class cUIObj_MFocus : public cUIThing {
public:
    int f0C;
    int f10;
    unsigned flags;
};

static inline cUIObj_MFocus* hideObj(char* self, char* name)
{
    cUIObj_MFocus* o = (cUIObj_MFocus*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(name));
    if (o != 0) {
        o->setFocus(0);
        o->setVisible(0);
    }
    return o;
}

static inline void showObj(cUIObj_MFocus* o)
{
    o->flags |= 1;
    o->setVisible(1);
    o->setFocus(1);
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
        o13->setFocus(1);
        o13->setVisible(1);
        if (*(int*)(self + 0x2D0) == 0) {
            cUIObj_MFocus* o = (cUIObj_MFocus*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004706C8));
            o->setVisible(1);
            o->setStatic(0);
        } else {
            cUIObj_MFocus* o = (cUIObj_MFocus*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004706C8));
            o->setVisible(0);
            o->setStatic(1);
        }
        return;
    }
    switch (D_004A259C) {
    case 0:
        cUITemplate_MAP_setupPeakInfo(self);
        if (o0 != 0) {
            o0->flags |= 1;
            o0->setFocus(1);
            o0->setVisible(1);
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
extern char D_0046FAA0[];
extern char D_004706B8[];
extern char D_00470700[];
extern char D_00470A60[];
extern char D_00470A70[];
extern char D_00470A80[];
extern char D_00470A98[];
extern char D_00470AA8[];
extern char D_004A2638[];
extern char D_004A2640[];

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
                ((cUIThing*)o)->setVisible(0);
                ((cUIThing*)o)->setStatic(1);
            }
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004706C8);
        } else {
            if (title != 0)
                cUIText_setUnicodeStringByID(title, GetHashValue32(D_00470AA8));
            if (o != 0) {
                ((cUIThing*)o)->setVisible(1);
                ((cUIThing*)o)->setStatic(0);
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

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupPeakInfo);
#ifdef SKIP_ASM
extern "C" int func_00157BF0(void* self, int a, int b, int c, int i);
int cBERewardInterface_getTrackMedal(void* self, int a, int charID, int kind, int track);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" void func_003A0E90(void* text, unsigned short* s);
extern "C" int func_001543E0(void* self, int peak);
extern "C" int func_00154368(void* self, int peak);
extern "C" int func_00153390(void* self, int peak);
extern "C" int cBEMissionInterface_getCurrentCollectForPeak(void* self, int rider, int peak);
extern "C" int func_00158890(void* self, int peak, int tier);
extern "C" int func_00158870(void* self, int peak, int tier);
int func_001588B0(void* self, int peak);
extern "C" int func_001509F8(void* self, int rider);
int cBEScoreInterface_getCurrentHighlightLevel(void* self, int i);
void cUIText_setAsciiString(cUIText* text, const char* str);
extern char D_00470AE8[], D_004A2648[], D_00470AF8[], D_00470B08[], D_004A2650[], D_00470B20[], D_00470610[];
extern char D_004A2658[], D_00470B38[], D_00470B50[], D_00470B68[], D_00470B80[], D_00470B98[], D_00470BB0[];
extern char D_00470BC8[], D_00470BE0[], D_00470BF8[], D_00470C10[], D_00470C20[], D_00470C30[], D_00470C48[];
extern char D_00470C60[], D_00470C70[], D_00470C88[], D_00470C98[], D_00470CB0[], D_00470CC8[], D_00470CD8[];
extern char D_00470CE8[], D_00470D00[], D_00470D10[], D_00470D28[], D_00470D40[], D_00470D58[], D_00470D68[];
extern char D_00470D80[], D_00470D90[], D_00470DA8[], D_00470DC0[], D_00470DD8[], D_00470DE8[], D_00470E00[];
extern char D_004A2398[], D_004A2660[], D_004A2668[], D_004A2670[], D_004A2678[], D_004A2680[], D_004A2688[];
extern char D_004A2690[];

// The peak list entry selected in the map menu (at widget + 0xA0).
struct sPeakSel_MAP {
    char pad[0x18];
    int peak;           // 0x18
};

struct sPeakInfo_MAP {
    int pad0;
    int unlocked[3];            // 0x4, indexed by peak
    char pad10[0x2CC - 0x10];
    int popup;                  // 0x2CC
    char pad2D0[0x2E8 - 0x2D0];
    void* screen;               // 0x2E8
    void* owner;                // 0x2EC
};



// Goal kind test; the kind constant is taken by const reference.
static inline int isKind(int kind, const int& k) { return kind == k; }
extern "C" void cUITemplate_MAP_setupPeakInfo(void* tmpl)
{
    sPeakInfo_MAP* self = (sPeakInfo_MAP*)tmpl;
    void* rew = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    void* mis = cBE_getInterface_Fv(cBE_getBE(), 10);
    void* econ = cBE_getInterface_Fv(cBE_getBE(), 0xB);
    void* score = cBE_getInterface_Fv(cBE_getBE(), 8);
    int ch = cBELibrary_getCharacterID(0);
    if (self->popup != 0) {
        cUIState_hideObjSafe(self->owner, D_00470AE8);
        cUIState_hideObjSafe(self->owner, D_004A2648);
        cUIState_hideObjSafe(self->owner, D_004A2610);
    } else {
        cUIState_showObjSafe(self->owner, D_00470AE8);
        cUIState_showObjSafe(self->owner, D_004A2648);
        cUIState_showObjSafe(self->owner, D_004A2610);
    }
    cUIState_hideObjSafe(self->owner, D_00470AF8);
    cUIState_hideObjSafe(self->owner, D_00470B08);
    cUIState_hideObjSafe(self->owner, D_004A2650);
    char name1[32];
    char name2[32];
    for (int i = 0; i < 3; i++) {
        sprintf(name1, D_00470B20, i + 1);
        if (func_00157BF0(rew, 0, ch, i, 0) && func_00157BF0(rew, 0, ch, i, 1)
            && func_00157BF0(rew, 0, ch, i, 2) && func_00157BF0(rew, 0, ch, i, 3)) {
            cUIState_showObjSafe(self->owner, name1);
        } else {
            cUIState_hideObjSafe(self->owner, name1);
        }
    }
    if (D_004A2594 < 2) {
        cUIThing* o = (cUIThing*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470610));
        o->setStatic(1);
        o->setVisible(0);
    }
    cUIState_hideObjSafe(self->owner, D_004A25D8);
    cUIState_hideObjSafe(self->owner, D_00470548);
    cUIState_hideObjSafe(self->owner, D_00470558);
    for (int i = 0; i < 3; i++) {
        sprintf(name1, D_004A2658, i + 1);
        sprintf(name2, D_00470B38, i + 1);
        if (D_004A259C == 0 && self->unlocked[i] == 0) {
            cUIState_hideObjSafe(self->owner, name2);
        } else {
            cUIState_hideObjSafe(self->owner, name1);
            if (D_004A2594 < 2)
                cUIState_hideObjSafe(self->owner, name2);
        }
    }
    cUIThing* title = (cUIThing*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470578));
    title->setVisible(0);
    char* list = (char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470600));
    if (list == 0)
        return;
    sPeakSel_MAP* sel = *(sPeakSel_MAP**)(list + 0xA0);
    if (sel == 0)
        return;
    if (sel->peak < 3) {
        cUIState_hideObjSafe(self->owner, D_00470568);
        int peak = sel->peak;
        title->setVisible(1);
        if (self->unlocked[peak] != 0) {
            if (D_004A2594 < 2)
                cUIText_setUnicodeStringByID((cUIText*)title, GetHashValue32(D_00470B50));
            else
                cUIText_setUnicodeStringByID((cUIText*)title, GetHashValue32(D_00470B68));
        } else if (peak == 1) {
            if (D_004A2594 < 2)
                cUIText_setUnicodeStringByID((cUIText*)title, GetHashValue32(D_00470B80));
            else
                cUIText_setUnicodeStringByID((cUIText*)title, GetHashValue32(D_00470B98));
        } else if (D_004A2594 < 2) {
            cUIText_setUnicodeStringByID((cUIText*)title, GetHashValue32(D_00470BB0));
        } else {
            cUIText_setUnicodeStringByID((cUIText*)title, GetHashValue32(D_00470BC8));
        }
        if (D_004A2594 < 2)
            return;
        unsigned short wbuf[200];
        int cnt = 4;
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470BE0));
        int found = 0;
        unsigned short* fmt = Loc_5098(D_00470BF8);
        func_002C26D0(wbuf, fmt, peak + 1);
        func_003A0E90(t, wbuf);
        if (peak == 2)
            cnt = 3;
        for (int k = 0; k < cnt; k++) {
            sPeakGoal g = D_004781D0[peak][k];
            if (cBERewardInterface_getTrackMedal(rew, 0, ch, g.kind, g.track) != -1)
                found++;
        }
        char buf[32];
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470C10));
        sprintf(buf, D_004A2398, found, cnt);
        cUIText_setAsciiString(t, buf);
        if (found >= cnt)
            cUIState_showObjSafe(self->owner, D_00470C20);
        else
            cUIState_hideObjSafe(self->owner, D_00470C20);
        int found2 = 0;
        for (int k = 0; k < 5; k++) {
            sPeakGoal g = D_004786E0[peak][k];
            if (cBERewardInterface_getTrackMedal(rew, 0, ch, g.kind, g.track) != -1)
                found2++;
        }
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470C30));
        sprintf(buf, D_004A2660, found2);
        cUIText_setAsciiString(t, buf);
        if (found2 >= 5)
            cUIState_showObjSafe(self->owner, D_00470C48);
        else
            cUIState_hideObjSafe(self->owner, D_00470C48);
        int medals = 0;
        if (func_001543E0(mis, peak) >= func_00158890(rew, peak, 3))
            medals++;
        if (cBEMissionInterface_getCurrentCollectForPeak(mis, 0, peak) >= func_00158870(rew, peak, 3))
            medals++;
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470C60));
        sprintf(buf, D_004A2668, medals);
        cUIText_setAsciiString(t, buf);
        if (medals >= 2)
            cUIState_showObjSafe(self->owner, D_00470C70);
        else
            cUIState_hideObjSafe(self->owner, D_00470C70);
        unsigned int money = func_001509F8(econ, 0);
        int ok = func_001588B0(rew, peak) < money;
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470C88));
        sprintf(buf, D_004A2670, ok);
        cUIText_setAsciiString(t, buf);
        if (ok > 0)
            cUIState_showObjSafe(self->owner, D_00470C98);
        else
            cUIState_hideObjSafe(self->owner, D_00470C98);
    } else {
        int done = 0;
        cUIState_showObjSafe(self->owner, D_00470568);
        cUIState_hideObjSafe(self->owner, D_004A2608);
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470CB0));
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470CC8));
        for (int p = 0; p < 3; p++) {
            int cnt = 4;
            if (p == 2)
                cnt = 3;
            for (int k = 0; k < cnt; k++) {
                sPeakGoal g = D_004781D0[p][k];
                if (!isKind(g.kind, 4) && !isKind(g.kind, 6) && !isKind(g.kind, 7) && !isKind(g.kind, 8)) {
                    if ((unsigned)cBERewardInterface_getTrackMedal(rew, 0, ch, g.kind, g.track) < 2)
                        done++;
                }
            }
            for (int k = 0; k < 5; k++) {
                sPeakGoal g = D_004786E0[p][k];
                if (!isKind(g.kind, 5) && !isKind(g.kind, 9) && !isKind(g.kind, 10) && !isKind(g.kind, 11)) {
                    if ((unsigned)cBERewardInterface_getTrackMedal(rew, 0, ch, g.kind, g.track) < 2)
                        done++;
                }
            }
        }
        char buf[32];
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470CD8));
        sprintf(buf, D_004A2678, done);
        cUIText_setAsciiString(t, buf);
        if (done >= 14)
            cUIState_showObjSafe(self->owner, D_00470CE8);
        else
            cUIState_hideObjSafe(self->owner, D_00470CE8);
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470D00));
        int gold = 0;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 4, 0xE) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 6, 0xE) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 5, 0xE) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 9, 0xE) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 4, 0xF) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 7, 0xF) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 5, 0xF) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 10, 0xF) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 4, 0x10) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 8, 0x10) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 5, 0x10) != -1)
            gold++;
        if (cBERewardInterface_getTrackMedal(rew, 0, ch, 11, 0x10) != -1)
            gold++;
        sprintf(buf, D_004A2680, gold);
        cUIText_setAsciiString(t, buf);
        if (gold >= 12)
            cUIState_showObjSafe(self->owner, D_00470D10);
        else
            cUIState_hideObjSafe(self->owner, D_00470D10);
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470D28));
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470D40));
        int cur = 0;
        int tot = 0;
        for (int p = 0; p < 3; p++) {
            cur += func_001543E0(mis, p);
            tot += func_00154368(mis, p);
        }
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470D58));
        sprintf(buf, D_004A2398, cur, tot);
        cUIText_setAsciiString(t, buf);
        if (cur >= tot)
            cUIState_showObjSafe(self->owner, D_00470D68);
        else
            cUIState_hideObjSafe(self->owner, D_00470D68);
        int col = 0;
        int colTot = 0;
        for (int p = 0; p < 3; p++) {
            col += cBEMissionInterface_getCurrentCollectForPeak(mis, 0, p);
            colTot += func_00153390(mis, p);
        }
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470D80));
        sprintf(buf, D_004A2398, col, colTot);
        cUIText_setAsciiString(t, buf);
        if (col >= colTot)
            cUIState_showObjSafe(self->owner, D_00470D90);
        else
            cUIState_hideObjSafe(self->owner, D_00470D90);
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470DA8));
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00470DC0));
        int hl = 0;
        for (int p = 0; p < 8; p++)
            hl += cBEScoreInterface_getCurrentHighlightLevel(score, p);
        sprintf(buf, D_004A2688, hl);
        cUIText_setAsciiString((cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470DD8)), buf);
        if (hl >= 24)
            cUIState_showObjSafe(self->owner, D_00470DE8);
        else
            cUIState_hideObjSafe(self->owner, D_00470DE8);
        float pct = ((float)done * (1.0f / 14.0f) + (float)gold * (1.0f / 12.0f) + (float)cur / (float)tot + (float)col / (float)colTot + (float)hl * (1.0f / 24.0f)) * 20.0f;
        int pctInt = 100;
        if (pct != 100.0f) {
            pctInt = (int)pct;
            if (pct >= 99.0f)
                pctInt = 99;
        }
        t = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470E00));
        sprintf(buf, D_004A2690, pctInt);
        cUIText_setAsciiString(t, buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00204FF0);
#ifdef SKIP_ASM
extern char D_00470E10[];
extern char D_00470E20[];
extern char D_00470E30[];
extern char D_00470E40[];

static inline int setPic00204FF0(char* name)
{
    void* obj = *(void**)((char*)D_004A28A8 + 0x8C);
    sVEntry<int(void*, int)>* vt = *(sVEntry<int(void*, int)>**)((char*)obj + 4);
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

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_setupPeakGoals);
#ifdef SKIP_ASM
extern "C" void cUITemplate_MAP_showEventPath(void* tmpl, char* name);
extern "C" int func_004165A8(const char*, const char*);
extern "C" int func_00157BF0(void* self, int a, int b, int c, int i);
int cBERewardInterface_getTrackMedal(void* self, int a, int charID, int kind, int track);
extern "C" const char* func_00144C60(void* iface, int id);
extern "C" unsigned short* func_002C2540(unsigned short* dst, const char* s);
extern "C" unsigned short* func_002C2508(unsigned short* dst, const unsigned short* src);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" void func_002C27C0(unsigned short* dst, const char* fmt, ...);
extern "C" unsigned short* func_001FD190(int kind);
extern "C" void func_003A0E90(void* text, unsigned short* s);
extern "C" int func_001543E0(void* self, int peak);
extern "C" int func_00154368(void* self, int peak);
extern "C" int func_00153390(void* self, int peak);
extern "C" int cBEMissionInterface_getCurrentCollectForPeak(void* self, int rider, int peak);
extern "C" int func_00158890(void* self, int peak, int tier);
extern "C" int func_00158870(void* self, int peak, int tier);
int func_001588B0(void* self, int peak);
extern "C" int func_001509F8(void* self, int rider);
extern "C" const char* func_00198AF0(int value);
extern char D_004A2550[], D_004A2560[], D_004A23C0[], D_004A2698[], D_004A26A0[], D_0046E548[];
extern char D_00470E50[], D_00470E68[], D_00470E80[], D_00470E98[], D_00470EB0[], D_00470EC0[], D_00470ED0[];
extern char D_00470EE0[], D_00470EF0[], D_00470F00[], D_00470F18[], D_00470F28[], D_00470F38[], D_00470F48[];
extern char D_00470F58[], D_00470F70[], D_00470F90[], D_00470FA8[], D_00470FC0[], D_00470FD0[], D_00470FE0[];
extern char D_00470FF0[], D_00471000[], D_00471010[], D_00471020[], D_00471030[], D_00471040[], D_00471058[];
extern char D_00471068[], D_00471078[], D_00471088[], D_004710A0[], D_004710B8[], D_004710D0[], D_004710F0[];
extern char D_00471108[], D_00471128[], D_00471140[], D_00471158[], D_00471170[], D_00471188[], D_004711A0[];
extern char D_004711B8[], D_004711C8[], D_004711D8[], D_004711E8[], D_00471200[], D_00471218[], D_00471230[];
extern char D_00471248[], D_00471260[], D_00471278[], D_00471298[], D_004712B0[], D_004712C8[], D_004712E0[];
extern char D_004712F0[], D_00471300[], D_00471318[], D_00471330[];

extern "C" char* strcpy(char* d, const char* s);

extern "C" void cUITemplate_MAP_setupPeakGoals(void* tmpl)
{
    char* self = (char*)tmpl;
    unsigned short wbuf[200];
    char buf[32];
    cUIText* title = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470578));
    if (D_004A2594 < 2) {
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470E50);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470E68);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470E80);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470E98);
    }
    cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004A25D8);
    if (D_004A2594 == 0) {
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470558);
    } else {
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470548);
    }
    cUIText* name = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004A25D8));
    if (D_004A25A4 == 0) {
        cUIText_setUnicodeStringByID(name, GetHashValue32(D_00470EB0));
    } else if (D_004A25A4 == 1) {
        cUIText_setUnicodeStringByID(name, GetHashValue32(D_00470EC0));
    } else {
        cUIText_setUnicodeStringByID(name, GetHashValue32(D_00470ED0));
    }
    cUIThing* o;
    unsigned char b = 0;
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* rew = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    void* mis = cBE_getInterface_Fv(cBE_getBE(), 10);
    void* econ = cBE_getInterface_Fv(cBE_getBE(), 0xB);
    int ch = cBELibrary_getCharacterID(0);
    sprintf(buf, D_004706D8, D_004A25A4 + 1);
    char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(buf));
    if (obj) b = obj[0x95];
    if (D_004A259C == 1) {
        char path[24];
        if (b == 0) {
            sprintf(path, D_00470EE0, D_004A25A4 + 1);
            cUITemplate_MAP_showEventPath(self, path);
        } else if (b == 1) {
            sprintf(path, D_00470EF0, D_004A25A4 + 1);
            cUITemplate_MAP_showEventPath(self, path);
        } else {
            sprintf(path, D_00470F00, D_004A25A4 + 1);
            cUITemplate_MAP_showEventPath(self, path);
        }
    }
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470F18);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470F28);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470F38);
    cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470F48);
    if (D_004A2594 < 2) {
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_00470F58));
        return;
    }
    if (func_00157BF0(rew, 0, ch, D_004A25A4, 0))
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470F18);
    if (func_00157BF0(rew, 0, ch, D_004A25A4, 1))
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470F28);
    if (func_00157BF0(rew, 0, ch, D_004A25A4, 2))
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470F38);
    if (func_00157BF0(rew, 0, ch, D_004A25A4, 3))
        cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00470F48);
    switch (b) {
    case 0: {
        int cnt = 4;
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_00470F70));
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470F90));
        func_002C26D0(wbuf, Loc_5098(D_00470FA8), D_004A25A4 + 1);
        func_003A0E90(o, wbuf);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470FC0);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470FD0);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470FE0);
        cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00470FF0);
        if (D_004A25A4 == 2) {
            cnt = 3;
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00471000);
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00471010);
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00471020);
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00471030);
        }
        int done = 0;
        for (int k = 0; k < cnt; k++) {
            char name1[24];
            unsigned short ev[50];
            unsigned short medal[50];
            sPeakGoal g = D_004781D0[D_004A25A4][k];
            if (g.useTrackName) {
                func_002C27C0(ev, func_00144C60(race, g.track));
            } else if (func_004165A8(g.name, D_004A2560)) {
                func_002C2540(ev, g.name);
            } else if (g.kind == 4) {
                unsigned short fmt[20];
                func_002C2540(fmt, D_004A2698);
                func_002C26D0(ev, fmt, func_00144C60(race, g.track), Loc_5098(D_0046E548));
            } else {
                func_002C2508(ev, func_001FD190(g.kind));
            }
            sprintf(name1, D_00471040, k);
            char name2[24];
            sprintf(name2, D_00471058, k);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), name2);
            char name3[24];
            sprintf(name3, D_00471068, k);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), name3);
            func_002C2540(medal, D_004A2560);
            int m = cBERewardInterface_getTrackMedal(rew, 0, ch, g.kind, g.track);
            if (m != -1) {
                unsigned short fmt[8];
                done++;
                func_002C2540(fmt, D_004A23C0);
                func_002C26D0(medal, fmt, func_00204FF0(self, m));
                cUIState_showObjSafe(*(void**)(self + 0x2EC), name1);
            } else {
                cUIState_hideObjSafe(*(void**)(self + 0x2EC), name1);
            }
            char name4[24];
            sprintf(name4, D_00471078, k);
            o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(name4));
            unsigned short fmt[8];
            func_002C2540(fmt, D_004A2550);
            func_002C26D0(wbuf, fmt, ev, medal);
            func_003A0E90(o, wbuf);
        }
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471088));
        func_002C26D0(wbuf, Loc_5098(D_004710A0), done, cnt);
        func_003A0E90(o, wbuf);
        break;
    }
    case 1: {
        int done = 0;
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_004710B8));
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00470F90));
        func_002C26D0(wbuf, Loc_5098(D_004710D0), D_004A25A4 + 1);
        func_003A0E90(o, wbuf);
        for (int k = 0; k < 5; k++) {
            unsigned short ev[50];
            unsigned short medal[50];
            sPeakGoal g = D_004786E0[D_004A25A4][k];
            if (g.useTrackName) {
                func_002C27C0(ev, func_00144C60(race, g.track));
            } else if (func_004165A8(g.name, D_004A2560)) {
                func_002C2540(ev, g.name);
            } else if (g.kind == 5) {
                unsigned short fmt[20];
                func_002C2540(fmt, D_004A26A0);
                func_002C26D0(ev, fmt, func_00144C60(race, g.track));
            } else {
                func_002C2508(ev, func_001FD190(g.kind));
            }
            char name1[24];
            sprintf(name1, D_00471040, k);
            char name2[24];
            sprintf(name2, D_00471058, k);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), name2);
            char name3[24];
            sprintf(name3, D_00471068, k);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), name3);
            func_002C2540(medal, D_004A2560);
            int m = cBERewardInterface_getTrackMedal(rew, 0, ch, g.kind, g.track);
            char medalFmt[16];
            if (m != -1) {
                strcpy(medalFmt, "[%s]");
                done++;
                func_002C27C0(medal, medalFmt, func_00204FF0(self, m));
                cUIState_showObjSafe(*(void**)(self + 0x2EC), name1);
            } else {
                cUIState_hideObjSafe(*(void**)(self + 0x2EC), name1);
            }
            char name4[24];
            sprintf(name4, D_00471078, k);
            o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(name4));
            char fmt[16];
            strcpy(fmt, "%s %s");
            func_002C27C0(wbuf, fmt, ev, medal);
            func_003A0E90(o, wbuf);
            o->setVisible(1);
            char name5[24];
            sprintf(name5, D_004710F0, k);
            cUIState_showObjSafe(*(void**)(self + 0x2EC), name5);
        }
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471088));
        func_002C26D0(wbuf, Loc_5098(D_004710A0), done, 5);
        func_003A0E90(o, wbuf);
        break;
    }
    case 2: {
        int count = 0;
        int ok = 0;
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_00471108));
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471128));
        func_002C26D0(wbuf, Loc_5098(D_00471140), D_004A25A4 + 1);
        func_003A0E90(o, wbuf);
        int cur = func_001543E0(mis, D_004A25A4);
        int tot = func_00154368(mis, D_004A25A4);
        func_002C26D0(wbuf, Loc_5098(D_00471158), cur, tot);
        func_003A0E90(cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471170)), wbuf);
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471188));
        if (cur >= func_00158890(rew, D_004A25A4, 0)) {
            o->setVisible(0);
            ok = 1;
        } else if (cur >= func_00158890(rew, D_004A25A4, 1)) {
            ok = 1;
            func_002C26D0(wbuf, Loc_5098(D_004711A0), func_00158890(rew, D_004A25A4, 0));
            func_003A0E90(o, wbuf);
        } else if (cur >= func_00158890(rew, D_004A25A4, 2)) {
            ok = 1;
            func_002C26D0(wbuf, Loc_5098(D_004711B8), func_00158890(rew, D_004A25A4, 1));
            func_003A0E90(o, wbuf);
        } else if (cur >= func_00158890(rew, D_004A25A4, 3)) {
            ok = 1;
            func_002C26D0(wbuf, Loc_5098(D_004711C8), func_00158890(rew, D_004A25A4, 2));
            func_003A0E90(o, wbuf);
        } else {
            func_002C26D0(wbuf, Loc_5098(D_004711D8), func_00158890(rew, D_004A25A4, 3));
            func_003A0E90(o, wbuf);
        }
        if (ok) {
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_004711E8);
            count++;
        } else {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_004711E8);
        }
        ok = 0;
        cur = cBEMissionInterface_getCurrentCollectForPeak(mis, 0, D_004A25A4);
        tot = func_00153390(mis, D_004A25A4);
        func_002C26D0(wbuf, Loc_5098(D_00471200), cur, tot);
        func_003A0E90(cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471218)), wbuf);
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471230));
        if (cur >= func_00158870(rew, D_004A25A4, 0)) {
            o->setVisible(0);
            ok = 1;
        } else if (cur >= func_00158870(rew, D_004A25A4, 1)) {
            ok = 1;
            func_002C26D0(wbuf, Loc_5098(D_004711A0), func_00158870(rew, D_004A25A4, 0));
            func_003A0E90(o, wbuf);
        } else if (cur >= func_00158870(rew, D_004A25A4, 2)) {
            ok = 1;
            func_002C26D0(wbuf, Loc_5098(D_004711B8), func_00158870(rew, D_004A25A4, 1));
            func_003A0E90(o, wbuf);
        } else if (cur >= func_00158870(rew, D_004A25A4, 3)) {
            ok = 1;
            func_002C26D0(wbuf, Loc_5098(D_004711C8), func_00158870(rew, D_004A25A4, 2));
            func_003A0E90(o, wbuf);
        } else {
            func_002C26D0(wbuf, Loc_5098(D_004711D8), func_00158870(rew, D_004A25A4, 3));
            func_003A0E90(o, wbuf);
        }
        if (ok) {
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00471248);
            count++;
        } else {
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00471248);
        }
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471260));
        func_002C26D0(wbuf, Loc_5098(D_004710A0), count, 2);
        func_003A0E90(o, wbuf);
        break;
    }
    case 3: {
        unsigned short num[16];
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_00471278));
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471298));
        func_002C26D0(wbuf, Loc_5098(D_004712B0), D_004A25A4 + 1);
        func_003A0E90(o, wbuf);
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004712C8));
        int cost = func_001588B0(rew, D_004A25A4);
        unsigned short* fmt = Loc_5098(D_004712E0);
        func_002C2540(num, func_00198AF0(cost));
        func_002C26D0(wbuf, fmt, num);
        func_003A0E90(o, wbuf);
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004712F0));
        int money = func_001509F8(econ, 0);
        fmt = Loc_5098(D_00471300);
        func_002C2540(num, func_00198AF0(money));
        func_002C26D0(wbuf, fmt, num);
        func_003A0E90(o, wbuf);
        int ok;
        if (cost > money)
            ok = 0;
        else
            ok = 1;
        o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00471318));
        func_002C26D0(wbuf, Loc_5098(D_004710A0), ok, 1);
        func_003A0E90(o, wbuf);
        if (ok > 0)
            cUIState_showObjSafe(*(void**)(self + 0x2EC), D_00471330);
        else
            cUIState_hideObjSafe(*(void**)(self + 0x2EC), D_00471330);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", cUITemplate_MAP_showEventPath);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const char*, const char*);
extern char D_004A2560[];
extern char D_004714B0[];
extern char D_004714C0[];
extern char D_004714D0[];
extern char D_004714E0[];
extern char D_004714F0[];
extern char D_00471500[];
extern char D_00471510[];
extern char D_00471520[];
extern char D_00471530[];
extern char D_00471548[];
extern char D_00471558[];
extern char D_00471568[];
extern char D_00471580[];
extern char D_00471590[];
extern char D_004715A0[];
// The path-name lists the function copies onto the stack (retail rodata/sdata tables).
struct sPaths6 { char* p[6]; };
struct sPaths5 { char* p[5]; };
struct sPaths3 { char* p[3]; };
struct sPaths2 { char* p[2]; };
extern const sPaths6 D_004713A8;
extern const sPaths6 D_00471420;
extern const sPaths5 D_00471488;
extern const sPaths3 D_004714A0;
extern const sPaths2 D_004A26A8[];
extern const sPaths2 D_004A26B0[];
extern const sPaths2 D_004A26B8[];
extern const sPaths2 D_004A26C0[];
extern const sPaths2 D_004A26C8[];
// One 0x6C-byte entry of the event path tables; the symbols point at its path-name field.
struct sPathName {
    char name[0x6C];
};
extern sPathName D_00478225[];
extern sPathName D_00478735[];
extern sPathName D_004783D5[];
extern sPathName D_00478951[];
extern sPathName D_00478585[];
extern sPathName D_00478B6D[];

// Path widget: a cUIThing whose slot 11 is setColor (as in fe/feasyncfile).
class cUIObj_ShowPath : public cUIThing {
public:
    virtual void v10();
    virtual void setColor(float* c);
};

extern "C" void cUITemplate_MAP_showEventPath(void* tmpl, char* name)
{
    char* self = (char*)tmpl;
    float colA[4];
    float colB[4];
    colA[0] = 1.0f;
    colA[1] = 0.8901961445808411f;
    colA[2] = 0.16470588743686676f;
    colA[3] = 0.03529411926865578f;
    colB[0] = 1.0f;
    colB[1] = 0.8705883026123047f;
    colB[2] = 0.5176470875740051f;
    colB[3] = 0.13333334028720856f;
    sPaths6 a0 = D_004713A8;
    sPaths6 a1 = D_00471420;
    sPaths5 a2 = D_00471488;
    sPaths3 a3 = D_004714A0;
    sPaths2 b0 = D_004A26A8[0];
    sPaths2 b1 = D_004A26B0[0];
    sPaths2 b2 = D_004A26B8[0];
    sPaths2 b3 = D_004A26C0[0];
    sPaths2 b4 = D_004A26C8[0];
    cUIObj_ShowPath* o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(name));
    if (o != 0 || func_004165A8(name, D_004A2560) == 0) {
        switch (D_004A25A4) {
        case 0: {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a0.p[i]));
                if (o != 0) {
                    if (func_004165A8(a0.p[i], name) == 0)
                        o->setColor(colA);
                    else
                        o->setColor(colB);
                }
            }
            break;
        }
        case 1: {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a1.p[i]));
                if (o != 0) {
                    if (func_004165A8(a1.p[i], name) == 0)
                        o->setColor(colA);
                    else
                        o->setColor(colB);
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < 5; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a2.p[i]));
                if (o != 0) {
                    if (func_004165A8(a2.p[i], name) == 0)
                        o->setColor(colA);
                    else
                        o->setColor(colB);
                }
            }
            break;
        }
        }
    } else {
        if (func_004165A8(name, D_004714B0) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a0.p[i]));
                if (o != 0) {
                    o->setColor(colB);
                    for (int j = 0; j < 3; j++) {
                        if (func_004165A8(a0.p[i], a3.p[j]) == 0)
                            o->setColor(colA);
                    }
                }
            }
        } else if (func_004165A8(name, D_004714C0) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a0.p[i]));
                if (o != 0) {
                    o->setColor(colB);
                    for (int j = 0; j < 2; j++) {
                        if (func_004165A8(a0.p[i], b0.p[j]) == 0)
                            o->setColor(colA);
                    }
                }
            }
        } else if (func_004165A8(name, D_004714D0) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a1.p[i]));
                if (o != 0) {
                    o->setColor(colB);
                    for (int j = 0; j < 2; j++) {
                        if (func_004165A8(a1.p[i], b1.p[j]) == 0)
                            o->setColor(colA);
                    }
                }
            }
        } else if (func_004165A8(name, D_004714E0) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a1.p[i]));
                if (o != 0) {
                    o->setColor(colB);
                    for (int j = 0; j < 2; j++) {
                        if (func_004165A8(a1.p[i], b2.p[j]) == 0)
                            o->setColor(colA);
                    }
                }
            }
        } else if (func_004165A8(name, D_004714F0) == 0) {
            for (int i = 0; i < 5; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a2.p[i]));
                if (o != 0) {
                    o->setColor(colB);
                    for (int j = 0; j < 2; j++) {
                        if (func_004165A8(a2.p[i], b3.p[j]) == 0)
                            o->setColor(colA);
                    }
                }
            }
        } else if (func_004165A8(name, D_00471500) == 0) {
            for (int i = 0; i < 5; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a2.p[i]));
                if (o != 0) {
                    o->setColor(colB);
                    for (int j = 0; j < 2; j++) {
                        if (func_004165A8(a2.p[i], b4.p[j]) == 0)
                            o->setColor(colA);
                    }
                }
            }
        } else if (func_004165A8(name, D_00471510) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a0.p[i]));
                if (o != 0)
                    o->setColor(colB);
            }
            for (int k = 0; k < 3; k++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00478225[k].name));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_00471520) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a0.p[i]));
                if (o != 0)
                    o->setColor(colB);
            }
            for (int k = 0; k < 4; k++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00478735[k].name));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_00471530) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a0.p[i]));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_00471548) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a1.p[i]));
                if (o != 0)
                    o->setColor(colB);
            }
            for (int k = 0; k < 3; k++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_004783D5[k].name));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_00471558) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a1.p[i]));
                if (o != 0)
                    o->setColor(colB);
            }
            for (int k = 0; k < 4; k++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00478951[k].name));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_00471568) == 0) {
            for (int i = 0; i < 6; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a1.p[i]));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_00471580) == 0) {
            for (int i = 0; i < 5; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a2.p[i]));
                if (o != 0)
                    o->setColor(colB);
            }
            for (int k = 0; k < 2; k++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00478585[k].name));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_00471590) == 0) {
            for (int i = 0; i < 5; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a2.p[i]));
                if (o != 0)
                    o->setColor(colB);
            }
            for (int k = 0; k < 4; k++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(D_00478B6D[k].name));
                if (o != 0)
                    o->setColor(colA);
            }
        } else if (func_004165A8(name, D_004715A0) == 0) {
            for (int i = 0; i < 5; i++) {
                o = (cUIObj_ShowPath*)cUIScreen_getObjectByHashName(*(void**)(self + 0x2E8), GetHashValue32(a2.p[i]));
                if (o != 0)
                    o->setColor(colA);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00207430);
#ifdef SKIP_ASM
void cUIText_setAsciiString(cUIText* text, const char* s);
extern "C" void func_003A0D00(void* text, unsigned short* s);
extern "C" int func_00145870(void* race, int track);
extern "C" int func_00153520(void* mis, int a, int track);
extern "C" int func_00153350(void* mis, int track);
extern "C" int func_001542E0(void* mis, int track);
extern "C" int func_001542A0(void* mis, int track);
extern "C" int func_001550E8(void* stats, int a, int track, int kind);
extern "C" const char* func_0020A1A8(int value);
extern sPeakGoal D_00478D38[3][8];
extern char D_004715B8[], D_004A2600[], D_004A26D0[], D_00471640[], D_00471650[], D_00471608[], D_004715D0[];
extern char D_00471628[], D_004715E8[], D_004715F8[], D_00471668[], D_00471680[], D_00471698[], D_004A2590[];
extern char D_004716B0[], D_0046E398[], D_0046E3A8[], D_004716C8[], D_0046E5F0[], D_004716D8[], D_004716E8[];
extern char D_004716F8[], D_004A26D8[], D_00471710[], D_00471720[], D_00471738[], D_004A2398[], D_00471748[];
extern char D_00471758[], D_00471770[], D_004A26E0[], D_00471780[], D_00471790[], D_004717A0[], D_004717B0[];
extern char D_004A2108[], D_004A2138[];

// The MAP template as this function sees it: per-event flags indexed [peak][mode][event].
struct sMapTmpl_207430 {
    char pad0[0x20];
    int available[3][3][8];     // 0x20  challenge available (kT_HELPChalAvail)
    int completed[3][3][8];     // 0x140 SE_check%d shown
    char pad260[0x2CC - 0x260];
    int popup;                  // 0x2CC
    char pad2D0[0x2E8 - 0x2D0];
    void* screen;               // 0x2E8
    void* owner;                // 0x2EC
};

extern "C" void func_00207430(void* tmpl)
{
    sMapTmpl_207430* self = (sMapTmpl_207430*)tmpl;
    char buf[200];
    sPeakGoal g;
    char name[32];
    cUIThing* help = (cUIThing*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00470578));
    if (D_004A259C == 2)
        help->setVisible(1);
    void* mis = cBE_getInterface_Fv(cBE_getBE(), 10);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* rew = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    void* stats = cBE_getInterface_Fv(cBE_getBE(), 8);
    int ch = cBELibrary_getCharacterID(0);
    if (self->popup != 0) {
        cUIState_hideObjSafe(self->owner, D_004715B8);
        cUIState_hideObjSafe(self->owner, D_004A2600);
    } else {
        cUIState_showObjSafe(self->owner, D_004715B8);
        cUIState_showObjSafe(self->owner, D_004A2600);
    }
    if (D_004A259C == 2) {
        cUIState_showObjSafe(self->owner, D_004A25D8);
        if (D_004A2594 == 0) {
            cUIState_showObjSafe(self->owner, D_00470558);
        } else {
            cUIState_showObjSafe(self->owner, D_00470548);
        }
    }
    cUIText* title = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A25D8));
    g = D_004781D0[0][0];
    unsigned char b = 0;
    switch (D_004A25A0) {
    case 0: {
        sprintf(name, D_004715D0, D_004A25A4 + 1);
        b = ((char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(name)))[0x95];
        g = D_004781D0[D_004A25A4][b];
        int cnt = 4;
        if (D_004A25A4 == 2)
            cnt = 3;
        for (int i = 0; i < 8; i++) {
            if (i < cnt && D_004A2594 >= 2) {
                sprintf(buf, D_004715E8, i);
                cUIState_showObjSafe(self->owner, buf);
                sprintf(buf, D_004715F8, i);
                if (self->completed[D_004A25A4][D_004A25A0][i])
                    cUIState_showObjSafe(self->owner, buf);
                else
                    cUIState_hideObjSafe(self->owner, buf);
            } else {
                sprintf(buf, D_004715E8, i);
                cUIState_hideObjSafe(self->owner, buf);
                sprintf(buf, D_004715F8, i);
                cUIState_hideObjSafe(self->owner, buf);
            }
        }
        break;
    }
    case 1: {
        sprintf(name, D_00471608, D_004A25A4 + 1);
        b = ((char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(name)))[0x95];
        g = D_004786E0[D_004A25A4][b];
        for (int i = 0; i < 8; i++) {
            if (i < 5 && D_004A2594 >= 2) {
                sprintf(buf, D_004715E8, i);
                cUIState_showObjSafe(self->owner, buf);
                sprintf(buf, D_004715F8, i);
                if (self->completed[D_004A25A4][D_004A25A0][i])
                    cUIState_showObjSafe(self->owner, buf);
                else
                    cUIState_hideObjSafe(self->owner, buf);
            } else {
                sprintf(buf, D_004715E8, i);
                cUIState_hideObjSafe(self->owner, buf);
                sprintf(buf, D_004715F8, i);
                cUIState_hideObjSafe(self->owner, buf);
            }
        }
        break;
    }
    case 2: {
        sprintf(name, D_00471628, D_004A25A4 + 1);
        b = ((char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(name)))[0x95];
        g = D_00478D38[D_004A25A4][b];
        char obj[32];
        for (int i = 0; i < 8; i++) {
            sprintf(obj, D_004715F8, i);
            cUIState_hideObjSafe(self->owner, obj);
            sprintf(obj, D_004715E8, i);
            cUIState_hideObjSafe(self->owner, obj);
        }
        break;
    }
    }
    cUIText* o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A26D0));
    cUIText_setAsciiString(o, func_00144C60(race, g.track));
    o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471640));
    unsigned int kind = g.kind;
    if (g.track >= 17 && g.track <= 21) {
        kind = 12;
        if (D_004A259C == 2)
            cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(D_00471650));
    } else {
        if (func_004165A8(g.help, D_004A2560)) {
            if (D_004A259C == 2)
                cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(g.help));
        } else if (g.kind == 4) {
            if (self->available[D_004A25A4][D_004A25A0][b])
                cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(D_00471668));
            else
                cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(D_00471680));
        } else if (g.kind == 5) {
            if (self->available[D_004A25A4][D_004A25A0][b])
                cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(D_00471668));
            else
                cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(D_00471698));
        } else if (g.kind >= 6 && g.kind <= 8) {
            if (self->available[D_004A25A4][D_004A25A0][b]) {
                cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(D_00471668));
            } else {
                unsigned short fmt[16];
                unsigned short ev[300];
                func_002C2540(fmt, D_004A2590);
                func_002C26D0(ev, fmt, func_00144C60(race, g.track));
                unsigned short loc[300];
                func_002C2508(loc, Loc_5098(D_004716B0));
                unsigned short text[300];
                func_002C26D0(text, loc, ev);
                func_003A0D00(help, text);
            }
        } else if (g.kind >= 9 && g.kind <= 11) {
            if (self->available[D_004A25A4][D_004A25A0][b]) {
                cUIText_setUnicodeStringByID((cUIText*)help, GetHashValue32(D_00471668));
            } else {
                unsigned short ev[300];
                unsigned short fmt[16];
                func_002C2540(fmt, D_004A26A0);
                func_002C26D0(ev, fmt, func_00144C60(race, g.track));
                unsigned short loc[300];
                func_002C2508(loc, Loc_5098(D_004716B0));
                unsigned short text[300];
                func_002C26D0(text, loc, ev);
                func_003A0D00(help, text);
            }
        }
        if (kind == 12)
            kind = func_00145870(race, g.track);
    }
    switch (kind) {
    case 0:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_0046E548));
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_0046E548));
        break;
    case 1:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_0046E398));
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_0046E398));
        break;
    case 3:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_0046E3A8));
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_0046E3A8));
        break;
    case 2:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_004716C8));
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_004716C8));
        break;
    case 4:
    case 5:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_0046E5F0));
        cUIText_setAsciiString(title, D_004A26D8);
        break;
    case 6:
    case 7:
    case 8:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_004716D8));
        cUIText_setAsciiString(title, D_004A26D8);
        break;
    case 9:
    case 10:
    case 11:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_004716E8));
        cUIText_setAsciiString(title, D_004A26D8);
        break;
    case 12:
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_004716F8));
        cUIText_setUnicodeStringByID(title, GetHashValue32(D_004716F8));
        break;
    }
    if (D_004A259C == 2)
        cUITemplate_MAP_showEventPath(self, g.path);
    if (D_004A25A0 == 2) {
        o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471710));
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_00471720));
        o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471738));
        sprintf(buf, D_004A2398, func_00153520(mis, 0, g.track), func_00153350(mis, g.track));
        cUIText_setAsciiString(o, buf);
        o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471748));
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_00471758));
        o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471770));
        sprintf(buf, D_004A2398, func_001542E0(mis, g.track), func_001542A0(mis, g.track));
        cUIText_setAsciiString(o, buf);
        if (func_001542A0(mis, g.track) == 0)
            cUIText_setAsciiString(o, D_004A26E0);
    } else {
        cUIState_showObjSafe(self->owner, D_00471710);
        cUIState_showObjSafe(self->owner, D_00471738);
        o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471710));
        cUIText_setUnicodeStringByID(o, GetHashValue32(D_00471780));
        int medal = cBERewardInterface_getTrackMedal(rew, 0, ch, g.kind, g.track);
        o = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471738));
        if (medal != -1)
            func_003A0E90(o, (unsigned short*)func_00204FF0(self, medal));
        else
            cUIText_setUnicodeStringByID(o, GetHashValue32(D_00471790));
        cUIText* label = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471748));
        cUIText* value = (cUIText*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471770));
        if (D_004A25A0 == 0) {
            cUIText_setUnicodeStringByID(label, GetHashValue32(D_004717A0));
            int v = func_001550E8(stats, 0, g.track, g.kind);
            cUIText_setAsciiString(value, func_0020A1A8(v));
            if (v == 0)
                cUIText_setAsciiString(value, D_004A2108);
        } else {
            cUIText_setUnicodeStringByID(label, GetHashValue32(D_004717B0));
            int v = func_001550E8(stats, 0, g.track, g.kind);
            char num[32];
            sprintf(num, D_004A2138, v);
            cUIText_setAsciiString(value, num);
            if (v == 0)
                cUIText_setAsciiString(value, D_004A2108);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_002083D8);
#ifdef SKIP_ASM
extern char D_004C8B38[];
extern char D_004C8B28[];

extern "C" void func_002083D8(void* self, void* obj, int on)
{
    if (obj != 0) {
        if (on != 0) {
            sVEntry<void(void*, void*)>* vt = *(sVEntry<void(void*, void*)>**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B38);
        } else {
            sVEntry<void(void*, void*)>* vt = *(sVEntry<void(void*, void*)>**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B28);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/uitemplatemap", func_00208438);
#ifdef SKIP_ASM
extern char D_004C8B58[];
extern char D_004C8B48[];

extern "C" void func_00208438(void* self, void* obj, int on)
{
    if (obj != 0) {
        if (on != 0) {
            sVEntry<void(void*, void*)>* vt = *(sVEntry<void(void*, void*)>**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B58);
        } else {
            sVEntry<void(void*, void*)>* vt = *(sVEntry<void(void*, void*)>**)((char*)obj + 0x8);
            vt[11].fn((char*)obj + vt[11].delta, D_004C8B48);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/uitemplatemap", func_00208498);
#ifdef SKIP_ASM
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
extern "C" void* func_0039F190(void* self, int a1);

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

