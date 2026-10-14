#include "common.h"

//100%
INCLUDE_ASM("fe/festatebigradio", cFEStateBraggingRights_onCreateScreen);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
// PORT: several callees are declared with other parameter types elsewhere; bind local views by asm label
extern "C" void func_00192740_2DB0(void* panel, int on) __asm__("func_00192740");
void func_00192968(void* panel, int mask);
extern "C" void func_00192970_2DB0(void* panel, void* screen) __asm__("func_00192970");
extern "C" int func_00193F38(void* self, int player, int which);
extern "C" unsigned char cUIListBox_addEntryByStringID_2DB0(void* box, int id, int idx) __asm__("cUIListBox_addEntryByStringID");
extern "C" unsigned char cUIListBox_addEntryByAsciiString_2DB0(void* box, const char* str, int data) __asm__("cUIListBox_addEntryByAsciiString");
extern "C" int func_0039A768_2DB0(void* item, int key, unsigned char* out) __asm__("func_0039A768");
extern "C" void func_0039A7A8_2DB0(void* item, int v) __asm__("func_0039A7A8");
extern int D_004A1A70;
extern signed char D_00535C12[];
extern signed char D_004A1710[6];
extern signed char D_004A1718[7];
extern signed char D_004A1720[7];
extern signed char D_004A1728[7];
extern signed char D_004A1730[5];
extern signed char D_004A1738[7];
extern char* D_00441108[];
extern char D_0045FCC8[];
extern char D_004A14F8[];
extern char D_0045FCD8[];
extern char D_0045DCC8[];
extern char D_0045DF40[];
extern char D_004A16E0[];
extern char D_004A16D8[];
extern char D_004A1758[];
extern char D_004A1760[];
extern char D_004A1768[];
extern char D_004A1770[];
extern char D_004A1778[];
extern char D_004A1780[];
extern char D_004A1580[];
extern char D_004A1588[];
extern char D_0045FCE8[];
extern char D_0045FCF8[];
extern char D_0045FD08[];

struct sStr2_2DB0 { char c[2]; };

class cUIObj_2DB0 {
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

struct sRadioPanel_2DB0 {
    void* menu;          // 0x0
    char pad4[4];
    void* items[11];     // 0x8
};

struct sBragging_2DB0 {
    char pad0[0x10];
    void* engine;                   // 0x10
    char pad14[0x8];
    int flags;                      // 0x1C
    char pad20[0x20];
    void* screen;                   // 0x40
    char pad44[0x68C];
    sRadioPanel_2DB0 panels[2];     // 0x6D0
    signed char* rules;             // 0x738
};

static inline void* find_2DB0(sBragging_2DB0* self, char* name)
{
    return cUIScreen_getObjectByHashName(self->screen, GetHashValue32(name));
}

static inline bool isNet_2DB0()
{
    return D_004A1A70 == 1;
}

// Bragging rights screen: builds the rule rows of both player panels for the current mode.
extern "C" void cFEStateBraggingRights_onCreateScreen(sBragging_2DB0* self)
{
    void* engine = self->engine;
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045FCC8), 0);
    self->screen = screen;
    if (screen != 0)
        cUIScreen_playFrame(screen, 0, 0);
    sRadioPanel_2DB0* a = &self->panels[0];
    sRadioPanel_2DB0* b = &self->panels[1];
    if ((self->flags >> 4) & 1) {
        func_00192740_2DB0(a, 0);
        func_00192740_2DB0(b, 0);
    }
    int n = 0;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    unsigned int mask = 0;
    switch (D_00535C12[0]) {
    case 0:
        self->rules = D_004A1710;
        n = 6;
        break;
    case 1:
        self->rules = D_004A1718;
        n = 7;
        break;
    case 3:
        self->rules = D_004A1720;
        n = 7;
        break;
    case 2:
        self->rules = D_004A1728;
        n = 7;
        break;
    case 4:
        self->rules = D_004A1730;
        n = 5;
        break;
    case 5:
        self->rules = D_004A1738;
        n = 7;
        break;
    }
    for (int i = 0; i < n; i++)
        mask |= 1 << i;
    func_00192968(a, mask);
    func_00192968(b, mask);
    func_00192970_2DB0(a, self->screen);
    func_00192970_2DB0(b, self->screen);
    sStr2_2DB0 name = *(sStr2_2DB0*)D_004A14F8;
    for (int row = 0; row < n; row++) {
        name.c[0] = row + '1';
        cUIText* txt = (cUIText*)find_2DB0(self, name.c);
        if (txt != 0)
            cUIText_setUnicodeStringByID(txt, GetHashValue32(D_00441108[self->rules[row]]));
        for (int p = 0; p < 2; p++) {
            unsigned char out = 0;
            void* lb = ((sRadioPanel_2DB0*)((char*)self + 0x6D0))[p].items[row];
            switch (self->rules[row]) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                cUIListBox_addEntryByStringID_2DB0(lb, GetHashValue32(D_0045FCD8), 0);
                cUIListBox_addEntryByStringID_2DB0(lb, GetHashValue32(D_0045DCC8), 1);
                func_0039A768_2DB0(lb, func_00193F38(self, p, self->rules[row]), &out);
                func_0039A7A8_2DB0(lb, out);
                break;
            case 0:
                cUIListBox_addEntryByStringID_2DB0(lb, GetHashValue32(D_0045DF40), 0);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A16E0, 5);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A16D8, 10);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A1758, 15);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A1760, 20);
                func_0039A768_2DB0(lb, func_00193F38(self, p, self->rules[row]), &out);
                func_0039A7A8_2DB0(lb, out);
                break;
            case 7:
                cUIListBox_addEntryByStringID_2DB0(lb, GetHashValue32(D_0045DF40), 0);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A1768, 3000);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A1770, 5000);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A1778, 10000);
                cUIListBox_addEntryByAsciiString_2DB0(lb, D_004A1780, 15000);
                func_0039A768_2DB0(lb, func_00193F38(self, p, self->rules[row]), &out);
                func_0039A7A8_2DB0(lb, out);
                break;
            }
        }
    }
    cUIObj_2DB0* o = (cUIObj_2DB0*)find_2DB0(self, D_004A1580);
    if (o != 0) {
        if (isNet_2DB0()) {
            o->setVisible(1);
            cUIObj_2DB0* c = (cUIObj_2DB0*)find_2DB0(self, D_0045FCE8);
            if (c != 0)
                c->setVisible(0);
            cUIObj_2DB0* d = (cUIObj_2DB0*)find_2DB0(self, D_0045FCF8);
            if (d != 0)
                d->setVisible(0);
        } else {
            o->setVisible(0);
        }
    }
    if (isNet_2DB0()) {
        cUIObj_2DB0* c = (cUIObj_2DB0*)find_2DB0(self, D_004A1588);
        if (c != 0)
            c->setVisible(0);
        cUIObj_2DB0* d = (cUIObj_2DB0*)find_2DB0(self, D_0045FD08);
        if (d != 0)
            d->setVisible(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00193310__FPv);
#ifdef SKIP_ASM
int func_00193310(void* self)
{
    return 0;
}
#endif

extern "C" void* func_0039E6B8(void* self);

//100%
INCLUDE_ASM("fe/festatebigradio", func_00193318__FPv);
#ifdef SKIP_ASM
void* func_00193318(void* self)
{
    return func_0039E6B8(self);
}
#endif

INCLUDE_ASM("fe/festatebigradio", func_00193338);

//100%
INCLUDE_ASM("fe/festatebigradio", func_00193568);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cUIScreen;
int GetHashValue32(char* str);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern char D_004A1790[];
extern char D_004A1798[];
extern int D_004A1A70;
extern "C" void func_001A87D0(void* self, int a1);
extern "C" void func_001927B0(void* p);
// func_0039E4C0 returns nothing (ends in a void vcall).
void func_0039E4C0_v(void* self) __asm__("func_0039E4C0");

static inline int isOn00193568()
{
    return D_004A1A70 == 1;
}

static inline int get6F8_3568(void* p) { return *(int*)((char*)p + 0x6F8); }

extern "C" void func_00193568(void* self, int a1)
{
    if (isOn00193568()) {
        func_001A87D0(self, a1);
        return;
    }
    func_0039E4C0_v(self);
    if (*(int*)((char*)self + 0x6F8) != 0 && *(int*)((char*)self + 0x72C) == 0) {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_004A1790));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
    } else if (get6F8_3568(self) == 0 && *(int*)((char*)self + 0x72C) != 0) {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_004A1798));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
    }
    func_001927B0((char*)self + 0x6D0);
    func_001927B0((char*)self + 0x704);
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", cFEStateBraggingRights_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
struct cUIText;
void cUIText_setAsciiString(cUIText* text, const char* s);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" const char* func_0014EE58(void* iface, int a1);
extern char D_004A17A0[];
extern char D_004A17A8[];
extern char D_0045FD38[];
extern char D_0045FD48[];
extern char D_0045FD58[];
extern char D_0045FD68[];
extern char D_0045FD78[];
extern char D_0045FD88[];

class cUIObj_193650 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08();
    virtual void v09();
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int on);
};

static inline int Is_193650(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void cFEStateBraggingRights_onWidgetCreate(char* self, cUIObj_193650* w)
{
    char* wp = (char*)w;
    if (Is_193650(*(int*)(wp + 0x38), D_004A17A0)) {
        *(void**)(self + 0x6D0) = 0;
        w->v07(1);
        *(void**)(self + 0x6D0) = w;
        *(int*)(wp + 0x14) |= 1;
        *(int*)(wp + 0x90) |= 1;
    } else if (Is_193650(*(int*)(wp + 0x38), D_004A17A8)) {
        *(void**)(self + 0x704) = 0;
        w->v07(1);
        *(void**)(self + 0x704) = w;
        *(int*)(wp + 0x14) |= 1;
        *(int*)(wp + 0x90) |= 1;
    } else if (Is_193650(*(int*)(wp + 0x38), D_0045FD38) || Is_193650(*(int*)(wp + 0x38), D_0045FD48)) {
        void* p1 = cBE_getInterface_Fv(cBE_getBE(), 1);
        void* p2 = cBE_getInterface_Fv(cBE_getBE(), 2);
        cUIText_setAsciiString((cUIText*)w, func_0014EE58(p2, func_00146E98(p1, 0)));
    } else if (Is_193650(*(int*)(wp + 0x38), D_0045FD58) || Is_193650(*(int*)(wp + 0x38), D_0045FD68)) {
        void* p1 = cBE_getInterface_Fv(cBE_getBE(), 1);
        void* p2 = cBE_getInterface_Fv(cBE_getBE(), 2);
        cUIText_setAsciiString((cUIText*)w, func_0014EE58(p2, func_00146E98(p1, 1)));
    } else if (Is_193650(*(int*)(wp + 0x38), D_0045FD78)) {
        *(void**)(self + 0x6D4) = w;
    } else if (Is_193650(*(int*)(wp + 0x38), D_0045FD88)) {
        *(void**)(self + 0x708) = w;
    } else {
        char name[3];
        name[2] = 0;
        for (int i = 0; i < 2; i++) {
            void** slots = (void**)(self + i * 0x34 + 0x6D8);
            for (int j = 0; j < 8; j++) {
                name[0] = '1' + i;
                name[1] = '1' + j;
                if (*(int*)(wp + 0x38) == GetHashValue32(name)) {
                    slots[j] = w;
                    *(int*)(wp + 0x18) = i;
                    *(int*)(wp + 0x14) &= ~1;
                    w->v24(1);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_001938F8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern int D_004A1A70;
extern void* D_004A33CC;
extern "C" void func_001927B0(void* p);
extern "C" void func_00194080(void* self);
extern "C" void func_00193DE0(void* self, int player, int which, int value);
extern "C" int func_00192918_38F8(void* panel, void* item) __asm__("func_00192918");
extern "C" int func_0039A738_38F8(void* item) __asm__("func_0039A738");
extern "C" void func_00192740_38F8(void* panel, int on) __asm__("func_00192740");
extern "C" void func_00265688(void* snd);
extern "C" void func_00265568(void* snd, int slot, int value);
extern "C" void func_0039F400(void* list, void* obj);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_001A8918(void* self, void* widget);
extern "C" void func_003E6448(void* dst, int c, int n);
extern char D_0045FD98[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];
extern char D_005308B8[];

struct sVE_38F8 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sVObj_38F8 {
    int f0;
    sVE_38F8* vt;                   // 0x4
};

struct sWidget_38F8 {
    char pad_0x0[0x18];
    int panel;                      // 0x18
};

static inline int isOn_38F8()
{
    return D_004A1A70 == 1;
}

static inline void* vcall_38F8(char* self, int slot, sWidget_38F8* w)
{
    sVObj_38F8* o = **(sVObj_38F8***)(self + 0x10);
    return o->vt[slot].fn((char*)o + o->vt[slot].delta, self, w->panel);
}

// Widget event handler of the big radio-button screen (two radio panels at self+0x6D0).
extern "C" void func_001938F8(char* self, sWidget_38F8* w, int event)
{
    int panel;
    switch (event) {
    case 5: {
        int i = 0;
        do {
            if (func_00192918_38F8(self + 0x6D0 + i * 0x34, w) != -1) {
                if (isOn_38F8() && i == 0)
                    func_00265688(D_004A33CC);
                func_00192740_38F8(self + 0x6D0 + i * 0x34, 1);
                func_00194080(self);
                break;
            }
            i++;
        } while (i < 2);
        if (isOn_38F8())
            break;
        if (*(int*)(self + 0x6F8) == 0)
            break;
        if (*(int*)(self + 0x72C) == 0)
            break;
        void* r = vcall_38F8(self, 4, w);
        if (r != 0)
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        break;
    }
    case 6:
        if (isOn_38F8()) {
            char* p = (char*)func_001A9C50(self);
            char* sub = p + 0xBC;
            *(int*)(p + 0xBC) = 2;
            *(int*)(p + 0xC4) = GetHashValue32(D_0045FD98);
            *(int*)(p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
            func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
            *(int*)(p + 0x150) = 0x838;
            *(int*)(p + 0x168) = 1;
            func_001A9BC0(self, p);
        } else {
            void* r = vcall_38F8(self, 5, w);
            if (r != 0)
                func_0039F400(*(char**)(self + 0x10) + 0x18, r);
            func_003E6448(D_005308B8, 0, 0x20);
        }
        break;
    case 1:
    case 2:
        panel = w->panel;
        func_001927B0(self + 0x6D0 + panel * 0x34);
        break;
    case 7:
        if (isOn_38F8())
            func_001A8918(self, w);
        break;
    case 9:
        if (isOn_38F8()) {
            void* snd = D_004A33CC;
            int slot = func_00192918_38F8(self + 0x6D0, w);
            func_00265568(snd, slot, func_0039A738_38F8(w));
        } else {
            panel = w->panel;
            int slot = func_00192918_38F8(self + 0x6D0 + panel * 0x34, w);
            int which = (*(signed char**)(self + 0x738))[slot];
            if (which != -1)
                func_00193DE0(self, panel, which, func_0039A738_38F8(w));
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00193C00);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_0045FDE8[];
extern char D_0045FE00[];
extern char D_0045FE20[];
extern char D_0045FE40[];
extern char D_0045FE60[];
extern char D_0045FE80[];
extern char D_0045FE98[];

extern "C" void func_00193C00(void* self, void* popup)
{
    func_001DA528(popup, 4);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_0045FDE8);
    func_001DA530(popup, 0, GetHashValue32(D_0045FE00));
    func_001DA530(popup, 1, GetHashValue32(D_0045FE20));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE40), 4);
    func_001DA510(popup, 1, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 2, GetHashValue32(D_0045FE80), 0);
    func_001DA510(popup, 3, GetHashValue32(D_0045FE98), 1);
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00193CF8);
#ifdef SKIP_ASM
extern int D_004A1A70;
extern void* D_004A33CC;
extern "C" void func_001927B0(void* p);
extern "C" void func_00265458(void* snd, int id);
static inline int isOn00193CF8()
{
    return D_004A1A70 == 1;
}
// Handles a menu event for one of the two radio list controls.
extern "C" int func_00193CF8(void* self, void* ctrl, int msg)
{
    int found = 0;
    void** item;
    void** p = (void**)((char*)self + 0x6D0);
    if (*p == ctrl) {
        item = p;
        found = 1;
    } else {
        item = (void**)((char*)self + 0x704);
        if (*item != ctrl) item = 0;
    }
    switch (msg) {
    case 8: case 9:
        return 0x100;
    case 5:
        if (isOn00193CF8() && found) {
            func_00265458(D_004A33CC, *((unsigned char*)ctrl + 0x95));
        }
        func_001927B0(item);
        return 0x101;
    case 6:
        if (*(int*)((char*)self + 0x6F8) == 0 || *(int*)((char*)self + 0x72C) == 0) return 1;
        return 0x101;
    case 7:
        if (isOn00193CF8()) return 0;
        break;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00193DE0);
#ifdef SKIP_ASM
struct sPlayerOpts_193DE0 {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int pad : 26;
    int f4;     // 0x4
    int f8;     // 0x8
};
extern sPlayerOpts_193DE0 D_005308B8_193DE0[] __asm__("D_005308B8");

static inline int other_193DE0(int p)
{
    return p == 0;
}

// Sets one of the per-player radio/HUD options.
extern "C" void func_00193DE0(void* self, int player, int which, int value)
{
    switch (which) {
    case 0: D_005308B8_193DE0[other_193DE0(player)].f8 = value; break;
    case 1: D_005308B8_193DE0[other_193DE0(player)].b3 = value; break;
    case 2: D_005308B8_193DE0[other_193DE0(player)].b0 = value; break;
    case 3: D_005308B8_193DE0[player].b4 = value; break;
    case 4: D_005308B8_193DE0[player].b5 = value; break;
    case 5: D_005308B8_193DE0[player].b1 = value; break;
    case 6: D_005308B8_193DE0[player].b2 = value; break;
    case 7: D_005308B8_193DE0[other_193DE0(player)].f4 = value; break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00193F38);
#ifdef SKIP_ASM
// Returns one of the per-player radio/HUD options, or -1 for an unknown option.
extern "C" int func_00193F38(void* self, int player, int which)
{
    switch (which) {
    case 0: return D_005308B8_193DE0[other_193DE0(player)].f8;
    case 1: return D_005308B8_193DE0[other_193DE0(player)].b3;
    case 2: return D_005308B8_193DE0[other_193DE0(player)].b0;
    case 3: return D_005308B8_193DE0[player].b4;
    case 4: return D_005308B8_193DE0[player].b5;
    case 5: return D_005308B8_193DE0[player].b1;
    case 6: return D_005308B8_193DE0[player].b2;
    case 7: return D_005308B8_193DE0[other_193DE0(player)].f4;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00194080);
#ifdef SKIP_ASM
struct cUIScreen;
int GetHashValue32(char* str);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern char D_004A1790[];
extern char D_004A1798[];

static inline int get6F8_4080(void* p) { return *(int*)((char*)p + 0x6F8); }
extern "C" void func_00194080(void* self)
{
    if (*(int*)((char*)self + 0x6F8) != 0 && *(int*)((char*)self + 0x72C) == 0) {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_004A1790));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
    } else if (get6F8_4080(self) == 0 && *(int*)((char*)self + 0x72C) != 0) {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_004A1798));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00194138);
#ifdef SKIP_ASM
extern int D_004A1A70;
extern "C" void* func_001A8B88(void* self, int size, int a2);

static inline int isOn00194138()
{
    return D_004A1A70 == 1;
}

extern "C" void* func_00194138(void* self, int a1, int a2)
{
    if (isOn00194138()) {
        return func_001A8B88(self, a1, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00194168);
#ifdef SKIP_ASM
extern int D_004A1A70;
extern "C" void func_00194440(void* self, void* a1, int a2);
extern "C" int func_001A97B8(void* self, void* a1, int a2);

static inline int isOn00194168()
{
    return D_004A1A70 == 1;
}

extern "C" void func_00194168(void* self, void* a1, int a2)
{
    if (isOn00194168()) {
        if (*(int*)((char*)a1 + 0x18) == 0x838) {
            func_00194440(self, a1, a2);
        } else {
            func_001A97B8(self, a1, a2);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_001941B0);
#ifdef SKIP_ASM
// PORT: several callees are declared with other parameter types elsewhere; bind local views by asm label
extern "C" void cUIMenu_setSelectedByIndex_41B0(void* menu, int idx) __asm__("cUIMenu_setSelectedByIndex");
extern "C" int func_0039A768_41B0(void* item, int key, unsigned char* out) __asm__("func_0039A768");
extern "C" void func_0039A7A8_41B0(void* item, int v) __asm__("func_0039A7A8");
extern "C" int func_00192918_41B0(void* panel, void* item) __asm__("func_00192918");
extern "C" int func_0039A738_41B0(void* item) __asm__("func_0039A738");
extern "C" void func_00192740_41B0(void* panel, int on) __asm__("func_00192740");
extern "C" void func_00192970_41B0(void* panel, void* screen) __asm__("func_00192970");
extern "C" void func_001AB288_41B0(void* self) __asm__("func_001AB288");
extern "C" int func_0025DA90_41B0(void* self) __asm__("func_0025DA90");
extern "C" void* func_001B1F88_41B0(void* mem, int a1) __asm__("func_001B1F88");
extern "C" void* func_001BFBB8_41B0(void* mem, int a1) __asm__("func_001BFBB8");
extern "C" void func_001A8A40_41B0(void* self, void* obj) __asm__("func_001A8A40");
extern "C" int func_001A8E40_41B0(void* self, int msg, void* data) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc_41B0(int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern void* D_004A3028;
extern char D_0045FF10[];
extern char D_0045FF28[];
extern char D_004A1788[];
extern char D_004A17B0[];

struct sRadioPanel_41B0 {
    void* menu;          // 0x0
    char pad4[4];
    void* items[11];     // 0x8
};

struct sRadioMsg_41B0 {
    char pad0[8];
    int panel;           // 0x8
    int idx;             // 0xC
    int key;             // 0x10
};

extern "C" int func_001941B0(char* self, int msg, sRadioMsg_41B0* data)
{
    switch (msg) {
    case 251:
        cUIMenu_setSelectedByIndex_41B0(((sRadioPanel_41B0*)(self + 0x6D0))[data->panel].menu, *(unsigned char*)&data->idx);
        break;
    case 252: {
        unsigned char out;
        void* item = ((sRadioPanel_41B0*)(self + 0x6D0))[data->panel].items[data->idx];
        if (!func_0039A768_41B0(item, data->key, &out)) {
            break;
        }
        func_0039A7A8_41B0(item, out);
        int slot = func_00192918_41B0(&((sRadioPanel_41B0*)(self + 0x6D0))[data->panel], item);
        int which = (*(signed char**)(self + 0x738))[slot];
        if (which == -1) {
            break;
        }
        int panel = data->panel;
        func_00193DE0(self, panel, which, func_0039A738_41B0(item));
        break;
    }
    case 253:
        func_00192740_41B0(&((sRadioPanel_41B0*)(self + 0x6D0))[data->panel], 1);
        func_00194080(self);
        break;
    case 238: case 241: case 248: case 250: case 274: case 275:
        func_001AB288_41B0(self);
        break;
    case 268:
        if (func_0025DA90_41B0(D_004A3028)) {
            func_001A8A40_41B0(self, func_001B1F88_41B0(cMemMan_alloc_41B0(0x73C, D_0045FF10, 0, 0), *(int*)(self + 0x10)));
        } else {
            func_001A8A40_41B0(self, func_001BFBB8_41B0(cMemMan_alloc_41B0(0x6D0, D_0045FF28, 0, 0), *(int*)(self + 0x10)));
        }
        break;
    case 254: {
        func_00192740_41B0(&((sRadioPanel_41B0*)(self + 0x6D0))[data->panel], 0);
        func_00192970_41B0(&((sRadioPanel_41B0*)(self + 0x6D0))[data->panel], *(void**)(self + 0x40));
        cUIMenu_setSelectedByIndex_41B0(((sRadioPanel_41B0*)(self + 0x6D0))[data->panel].menu, 0);
        int frame = data->panel == 0 ? cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_004A1788)) : cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_004A17B0));
        if (frame == 0xFFFF) {
            break;
        }
        cUIScreen_playFrame(*(void**)(self + 0x40), frame, 1);
        break;
    }
    default:
        return func_001A8E40_41B0(self, msg, data);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00194440);
#ifdef SKIP_ASM
extern void* D_004A33CC;
extern "C" void func_00265768(void* snd, int id);
void func_001A94D8(void* self);
extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_00194440(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        if (D_004A33CC != 0) {
            func_00265768(D_004A33CC, 0xF9);
        }
        func_001A94D8(self);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebigradio", func_00194498);
#ifdef SKIP_ASM
struct sColor4_4498 {
    float x, y, z, w;
};

struct sVEntry00194498a {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sVEntry00194498b {
    short delta;
    short index;
    void (*fn)(void*, sColor4_4498*);
};

extern "C" void func_00194498(void* self)
{
    sVEntry00194498a* vt = *(sVEntry00194498a**)((char*)self + 8);
    vt[8].fn((char*)self + vt[8].delta, 1);
    sColor4_4498 c = *(sColor4_4498*)((char*)self + 0x1C);
    if (c.x > 0.5f) {
        c.x = 0.5f;
        sVEntry00194498b* vt2 = *(sVEntry00194498b**)((char*)self + 8);
        vt2[11].fn((char*)self + vt2[11].delta, &c);
    }
}
#endif

