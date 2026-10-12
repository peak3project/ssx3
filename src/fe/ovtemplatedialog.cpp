#include "common.h"

//100%
INCLUDE_ASM("fe/ovtemplatedialog", cPDATemplate_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
// PORT: func_002C26D0 is a varargs formatter (dst, fmt, ...)
extern "C" void func_002C26D0_v(void* dst, int fmt, ...) __asm__("func_002C26D0");
extern "C" void func_003A0E90(void* text, char* str);
extern void* D_004A28A8;
extern char D_00471A10[];
extern char D_004A2718[];
extern char D_00471A20[];

struct sVEntry_PDA {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc_PDA(int hash)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_PDA* vt = *(sVEntry_PDA**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, hash);
}

static inline int div_PDA(int a, int b)
{
    return a / b;
}

extern "C" void cPDATemplate_onCreateScreen(char* self)
{
    *(int*)(self + 0xC) = 0x29;
    void* engine = *(void**)(self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00471A10), 0);
    *(void**)(self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    engine = *(void**)(self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A2718), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 1);
    }
    char* text = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_00471A20));
    if (text != 0) {
        int fmt = Loc_PDA(*(int*)(text + 0xB0));
        if (fmt != 0) {
            char buf[48];
            func_002C26D0_v(buf, fmt, -10 - div_PDA(*(int*)((char*)D_004A28A8 + 0x1C), 3600) % 15, 0x43);
            func_003A0E90(text, buf);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020A8B0);
#ifdef SKIP_ASM
extern "C" int func_0020A8B0(int a0, int a1)
{
    if ((unsigned int)(a0 - 6) < 6) {
        return 0x16;
    }
    if ((unsigned int)(a0 - 4) < 2 || a0 == 0 || a1 == 3) {
        return 0xb;
    }
    return 0xa;
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020A8F8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0020AB50(int state);
int func_00158F30(void* self);
extern "C" void func_002706B8(void* p);
extern void* D_004A28A8;
extern char* D_004A2EEC;
extern int D_00534B30[];
extern char D_00535BC8[];
extern int D_004A26FC;
extern int D_004A2704;
extern int D_004A2700;
extern int D_004A1228;

static inline bool isKind_A8F8(int k, int v)
{
    return k == v;
}

extern "C" void func_0020A8F8(int mode)
{
    int v = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = v != 0 && v < 10;
    if (busy) return;
    int state = 0;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    signed char* g = (signed char*)D_00535BC8;
    int type = **(int**)((char*)D_004A28A8 + 0xC0);
    int sub = g[0x48];
    int team = g[0x49];
    int kind = g[0x4A];
    switch (mode) {
    case 2:
        D_004A2704 = 0;
        if (D_004A1228 != 0) {
            state = 0x11;
        } else if (sub == 4) {
            D_004A26FC = mode;
        } else {
            D_004A26FC = 0;
            if (kind == 0) {
                state = 8;
            } else if (team == mode) {
                state = 0x15;
            } else {
                if (kind >= 4 && kind <= 11) state = 0x14;
                else state = 9;
            }
        }
        break;
    case 7:
        cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
        if (sub == 4) {
            D_004A26FC = sub;
            return;
        }
        D_004A26FC = 0;
        char* a = (char*)cBE_getInterface_Fv(cBE_getBE(), 8);
        char* b = (char*)cBE_getInterface_Fv(cBE_getBE(), 0xD);
        int any = 0;
        if (*(int*)(a + 0x18) >= 0 || *(int*)(a + 0x1C) >= 0) any = 1;
        if (any) {
            if (D_00534B30[0] != 0) {
                state = func_0020A8B0(kind, type);
            } else {
                D_004A2700 = 0;
                state = 0xF;
            }
        } else {
            if (func_00158F30(b) > 0 || *(int*)(b + 0x10) != 0) {
                state = 0x10;
            } else {
                state = func_0020A8B0(kind, type);
            }
        }
        int z = !isKind_A8F8(kind, 6) && !isKind_A8F8(kind, 7) && !isKind_A8F8(kind, 8) && !isKind_A8F8(kind, 9) &&
                !isKind_A8F8(kind, 10) && !isKind_A8F8(kind, 11);
        if (z) func_002706B8(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
        if (D_00534B30[0] != 0) *(int*)(D_004A2EEC + 0x64) = 0x8CA0;
        break;
    }
    if (state == 0) {
        D_004A26FC = 2;
    } else {
        func_0020AB50(state);
    }
}
#endif

INCLUDE_ASM("fe/ovtemplatedialog", func_0020AB50);

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020CA10);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0020AB50(int state);
extern "C" void func_00258C00(void* net);
extern "C" void func_00258790(void* net, int a1);
extern "C" int func_0030B8C0(void* self);
extern void* D_004A28A8;
extern void* D_004A3DD8;
extern char* D_004A2EEC;
extern char D_004A2468;
extern int D_00534B30[];
extern char D_00535BC8[];

static inline bool notMode4_0020CA10(signed char* g)
{
    return g[0x48] != 4;
}

extern "C" void func_0020CA10(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0) {
        char* net = D_004A2EEC;
        if (net != 0) {
            char* game = *(char**)((char*)D_004A28A8 + 0x84);
            if (game != 0 && *(int*)(game + 0x224) != 0) {
                func_00258C00(net);
            }
            func_00258790(D_004A2EEC, 1);
            char* n = D_004A2EEC;
            *(int*)(n + 0x68) = 0xE10;
            *(int*)(n + 0x64) = 0x708;
        }
        func_0020AB50(6);
    } else if (func_0030B8C0(D_004A3DD8) != 0) {
        func_0020AB50(2);
    } else {
        signed char* g = (signed char*)D_00535BC8;
        if (g[0x49] == 0 && notMode4_0020CA10(g)) {
            func_0020AB50(1);
        } else if (*(int*)(*(char**)((char*)D_004A28A8 + 0x84) + 0x214) == 0xB) {
            func_0020AB50(4);
        } else {
            signed char* g2 = (signed char*)D_00535BC8;
            if (g2[0x48] == 4) {
                func_0020AB50(3);
            } else {
                func_0020AB50(5);
            }
        }
    }
    D_004A2468 = 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020CBA0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int func_0039F9D8(void* stack, int hash);
extern void* D_004A28A8;
extern char D_0046F818[];

extern "C" int func_0020CBA0(void)
{
    char* stack = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48) + 0x18;
    return func_0039F9D8(stack, GetHashValue32(D_0046F818)) != 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020CBE8);
#ifdef SKIP_ASM
class cUIState20CBE8 {
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
    virtual void v24();
    virtual int v25();
};
extern "C" void* cUIStateStack_getCurrentState(void* stack);
extern "C" int func_0020CBA0(void);
extern void* D_004A28A8;

extern "C" int func_0020CBE8(void)
{
    char* mgr = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48);
    if (func_0020CBA0() == 0) {
        cUIState20CBE8* s = (cUIState20CBE8*)cUIStateStack_getCurrentState(mgr + 0x18);
        if (s != 0) {
            if (*(int*)((char*)s + 0x1C) & 1) {
                return 0;
            }
            return s->v25();
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020CC60);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0020AB50(int state);
extern char D_00535BC8[];
extern int D_004A26FC;

extern "C" void func_0020CC60(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    signed char* g = (signed char*)D_00535BC8;
    int mode = g[0x48];
    int players = g[0x49];
    if (mode == 0 || players == 2) {
        func_0020AB50(0xC);
    } else if ((mode >= 1 && mode <= 3) || mode == 6) {
        func_0020AB50(0xD);
    } else if (mode == 4) {
        D_004A26FC = 2;
    } else {
        func_0020AB50(0xC);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020CCF8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0020AB50(int state);
extern "C" int func_0020A8B0(int a0, int a1);
int func_00158F30(void* self);
extern "C" void* cUIStateStack_getCurrentState(void* stack);
extern void* D_004A28A8;
extern char* D_004A2EEC;
extern int D_00534B30[];
extern int D_004A26FC;
extern int D_004A2700;
//---
void cReplay_stopAutoReplay(void* self);
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern "C" void func_00257610(void* self, int a1);
extern "C" void cGame_exit(void* game, int a);
extern "C" void func_0026F8A0(void* self, void* a1, int a2, int a3);
extern signed char D_00535C12[];
extern unsigned int D_004A2594;
extern int D_004A2708;

struct sGame_CCF8 {
    char pad[0x48];
    char* mgr;
};

struct sGlobals_CCF8 {
    char pad[0x84];
    sGame_CCF8* game;
};

// Continues after a result dialog closes, depending on the current overlay state and the pending dialog.
extern "C" void func_0020CCF8(void)
{
    D_004A26FC = 0;
    char* st = (char*)cUIStateStack_getCurrentState(((sGlobals_CCF8*)D_004A28A8)->game->mgr + 0x18);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int kind = D_00535C12[0];
    int type = **(int**)((char*)D_004A28A8 + 0xC0);
    switch (*(int*)(st + 0x98)) {
    case 10:
    case 11:
        switch (D_004A2700) {
        case 3:
            cReplay_stopAutoReplay(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
            D_004A2594 = 1;
            func_0020AB50(0x21);
            break;
        case 1:
            cReplay_stopAutoReplay(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
            func_00231250(*(void**)((char*)D_004A28A8 + 0x84), 0xD, 0, 1);
            break;
        case 2:
            cReplay_stopAutoReplay(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
            D_004A26FC = 4;
            break;
        case 4:
            func_0020AB50(0x23);
            break;
        case 5:
            D_004A2708 = 0;
            func_0020AB50(0x17);
            break;
        case 6:
            cReplay_stopAutoReplay(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
            func_0020AB50(0x11);
            func_0026F8A0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28), 0, 0, 0);
            break;
        case 7:
            D_004A2700 = 1;
            func_0020AB50(0xF);
            break;
        case 8:
            cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
            if (D_00534B30[0] != 0) {
                if (D_004A2EEC != 0) {
                    func_00257610(D_004A2EEC, 0);
                }
                cGame_exit(*(void**)((char*)D_004A28A8 + 0x84), 0);
            } else {
                func_0020AB50(0x18);
            }
            break;
        }
        break;
    case 15:
        if (D_004A2700 == 0x13) {
            func_0020AB50(0x13);
        } else {
            char* b = (char*)cBE_getInterface_Fv(cBE_getBE(), 0xD);
            if (func_00158F30(b) > 0 || *(int*)(b + 0x10) != 0) {
                func_0020AB50(0x10);
            } else {
                func_0020AB50(func_0020A8B0(kind, type));
            }
        }
        break;
    case 16:
        func_0020AB50(func_0020A8B0(kind, type));
        break;
    case 8:
    case 9:
    case 20:
    case 21:
        D_004A26FC = 2;
        break;
    case 22:
        switch (D_004A2700) {
        case 2:
            cReplay_stopAutoReplay(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
            D_004A26FC = 4;
            break;
        case 5:
            D_004A2708 = 0;
            func_0020AB50(0x17);
            break;
        case 8:
            func_0020AB50(0x18);
            break;
        }
        break;
    case 35:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020CFD0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIStateStack_getCurrentState(void* stack);
extern "C" void func_0020CCF8(void);
void cReplay_stopAutoReplay(void* self);
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern void* D_004A28A8;
extern int D_00534B30[];
extern int D_004A26FC;
//---
extern "C" void func_0020D190(void);
extern "C" void func_0039F840(void* stack);

struct sFlag_CFD0 {
    int pad[2];
    int on;
};

struct sGame_CFD0 {
    char pad0[0x28];
    void* replay;
    char pad2C[0x48 - 0x2C];
    char* mgr;
    char pad4C[0x200 - 0x4C];
    sFlag_CFD0* flag;
    char pad204[0x214 - 0x204];
    int mode;
};

struct sGlobals_CFD0 {
    char pad0[0x78];
    void* be;
    char pad7C[0x84 - 0x7C];
    sGame_CFD0* game;
};

// Per-frame update of the dialog overlay: runs the action queued in D_004A26FC once the dialog has closed.
extern "C" void func_0020CFD0(void)
{
    char* mgr = ((sGlobals_CFD0*)D_004A28A8)->game->mgr;
    char* stack = mgr + 0x18;
    char* st = 0;
    if (stack != 0) {
        st = (char*)cUIStateStack_getCurrentState(stack);
    }
    switch ((unsigned int)D_004A26FC) {
    case 0:
        break;
    case 1:
        func_0020CCF8();
        break;
    case 2: {
        D_004A26FC = 0;
        cReplay_stopAutoReplay(((sGlobals_CFD0*)D_004A28A8)->game->replay);
        sGlobals_CFD0* g = (sGlobals_CFD0*)D_004A28A8;
        g->game->flag->on = 1;
        if (st == 0) {
            break;
        }
        if (g->game->mode != 2) {
            break;
        }
        if (*(int*)(st + 0x98) != 8) {
            break;
        }
        cBE_getInterface_Fv(g->be, 7);
        if (D_00534B30[0] == 0) {
            break;
        }
        func_0039F840(mgr + 0x18);
        break;
    }
    case 3:
        D_004A26FC = 0;
        func_0020D190();
        func_0039F840(((sGlobals_CFD0*)D_004A28A8)->game->mgr + 0x18);
        break;
    case 4:
        D_004A26FC = 0;
        func_00231250(((sGlobals_CFD0*)D_004A28A8)->game, 0xE, 2, 0);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", cOVStateManager_addPDATemplate);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0039E2A0(void* self, void* mgr);
extern "C" void cUIStateStack_pushExplicit(void* stack, void* state);
extern void* D_004A270C;
extern void* D_004A28A8;
extern char D_00471A10[];
extern char D_004743F0[];

extern "C" void cOVStateManager_addPDATemplate(void)
{
    if (D_004A270C == 0) {
        char* mgr = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48);
        void* t = cMemMan_alloc(0x48, D_00471A10, 0x100, 0);
        func_0039E2A0(t, mgr);
        *(void**)((char*)t + 8) = D_004743F0;
        D_004A270C = t;
        cUIStateStack_pushExplicit(mgr + 0x18, t);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020D190);
#ifdef SKIP_ASM
class cOVTemplate20D190 {
public:
    int pad[2];
    virtual ~cOVTemplate20D190();
};
extern "C" void cListNode_removeFromList(void* node);
extern void* D_004A270C;

extern "C" void func_0020D190(void)
{
    if (D_004A270C != 0) {
        cListNode_removeFromList(D_004A270C);
        delete (cOVTemplate20D190*)D_004A270C;
    }
    D_004A270C = 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020D1D8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern "C" void func_0020A380(void* self);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern int D_004A2860[2];
extern char* D_00441D10[];
extern char D_0046E510[];
extern char D_0046E4C0[];

class cUIObj_20D1D8 {
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

extern "C" void func_0020D1D8(void* self)
{
    func_0020A380(self);
    char* list = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E510));
    *(int*)(list + 0x90) |= 8;
    for (int i = 0; i < 5; i++) {
        char buf[32];
        sprintf(buf, D_0046E4C0, i);
        cUIObj_20D1D8* o = (cUIObj_20D1D8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        if (o != 0) {
            if (i < 1) {
                int v = D_004A2860[i];
                cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_00441D10[v]));
                *(int*)((char*)o + 0x18) = v;
            } else {
                o->setVisible(0);
                o->setEnabled(1);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020D308);
#ifdef SKIP_ASM
extern "C" int func_0020D308(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020D318);
#ifdef SKIP_ASM
extern int D_004A26FC;

extern "C" void func_0020D318(void* self, int a1, int key)
{
    if (a1 != 0 && key == 5) {
        D_004A26FC = 1;
    }
}
#endif

INCLUDE_ASM("fe/ovtemplatedialog", cOVTemplate_Dialog_onCreateScreen);

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020D4F0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, int idx);
extern char D_0046E818[];

extern "C" void func_0020D4F0(void* self, void* item)
{
    int id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_0046E818)) {
        if (*(int*)((char*)self + 0x9C) == 6) {
            cUIMenu_setSelectedByIndex(item, 0);
        } else {
            cUIMenu_setSelectedByIndex(item, 1);
        }
    }
}
#endif

INCLUDE_ASM("fe/ovtemplatedialog", func_0020D568);

INCLUDE_ASM("fe/ovtemplatedialog", cOVTemplate_Dialog_onWidgetEvent);

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020DBD0);
#ifdef SKIP_ASM
struct cUIScreen;
int GetHashValue32(char* str);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0020E900(void* self);
extern "C" void func_0039F190(void* self, int a1);
extern char* D_004A2EEC;
extern char D_0046E050[];

extern "C" void func_0020DBD0(void* self)
{
    func_0020E900(self);
    char* p = D_004A2EEC;
    if (p != 0) {
        int ok = *(int*)(p + 0x68) == 0 || *(int*)(p + 0x64) == 0;
        if (ok) {
            int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_0046E050));
            if (frame != 0xFFFF) {
                cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
            }
            func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovtemplatedialog", func_0020DC68);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0020A380(void* self);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cOVState_REPLAY_setupCameraName(void* self);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, int idx);
extern void* D_004A28A8;
extern char D_00471A40[];
extern char D_00471BA0[];
extern char D_00471BB0[];
extern char D_00471BC0[];
extern char D_00471BD0[];
extern char D_00471BE0[];
extern char D_00471BF0[];

struct sVE_20DC68 { short delta; short index; void (*fn)(void*, int); };

extern "C" void func_0020DC68(char* self)
{
    *(int*)(self + 0xC) = GetHashValue32(D_00471A40);
    void* engine = *(void**)(self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00471A40), 0);
    *(void**)(self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    *(int*)(self + 0xA0) = 0;
    *(int*)(self + 0x9C) = 0;
    cUIState_hideObjSafe(self, D_00471BA0);
    cUIState_hideObjSafe(self, D_00471BB0);
    if (*(int*)(self + 0xA0) != 0) {
        cUIState_hideObjSafe(self, D_00471BC0);
        cUIState_showObjSafe(self, D_00471BD0);
    } else {
        cUIState_showObjSafe(self, D_00471BC0);
        cUIState_hideObjSafe(self, D_00471BD0);
    }
    *(int*)(self + 0xA4) = 0xF5;
    *(int*)(self + 0xAC) = 0xF5;
    *(int*)(self + 0xB0) = 0x1E0;
    *(int*)(self + 0xA8) = 0;
    cOVState_REPLAY_setupCameraName(self);
    if (*(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28) + 0x608) != 0) {
        *(int*)(self + 0xB4) = 1;
    } else {
        *(int*)(self + 0xB4) = 0;
    }
    char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_00471BE0));
    *(int*)(obj + 0x90) |= 8;
    if (*(int*)(self + 0xB4) != 0) {
        if (obj != 0) cUIMenu_setSelectedByIndex(obj, 2);
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_00471BF0));
        if (o != 0) {
            sVE_20DC68* e = &(*(sVE_20DC68**)(o + 8))[9];
            e->fn(o + e->delta, 0);
            e = &(*(sVE_20DC68**)(o + 8))[8];
            e->fn(o + e->delta, 0);
        }
    }
}
#endif

