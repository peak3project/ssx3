#include "common.h"

INCLUDE_ASM("fe/festatebigradio", cFEStateBraggingRights_onCreateScreen);

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

INCLUDE_ASM("fe/festatebigradio", func_001938F8);

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

INCLUDE_ASM("fe/festatebigradio", func_001941B0);

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

