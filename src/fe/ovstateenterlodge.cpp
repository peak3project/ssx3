#include "common.h"

//100%
INCLUDE_ASM("fe/ovstateenterlodge", cOVState_ENTERLODGE_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void cOVStateManager_addPDATemplate();
extern "C" void func_0020A380(void* self);
extern char D_0046F4D0[];

extern "C" void cOVState_ENTERLODGE_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046F4D0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    cOVStateManager_addPDATemplate();
    func_0020A380(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7210);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A23E0[];
extern char D_004A23E8[];
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0039E4C0(void* self, void* a1);

extern "C" void func_001F7210(void* self, void* a1)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A23E0));
    if (obj != 0) {
        *(int*)((char*)obj + 0x18) = 0;
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A23E8));
    if (obj != 0) {
        *(int*)((char*)obj + 0x18) = 1;
    }
    func_0039E4C0(self, a1);
}
#endif

extern "C" void func_0020A430(void*);

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7298__FPv);
#ifdef SKIP_ASM
void func_001F7298(void* self)
{
    *(int*)((char*)self + 0x50) = 0;
    func_0020A430(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F72B8);
#ifdef SKIP_ASM
// Key filter: keys 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001F72B8(void* self, int a1, unsigned int key)
{
    int r = 0x101;
    if (key < 10) {
        if (key < 8) {
            r = 0x101;
        } else {
            return 0x100;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F72E0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A19C4;
extern "C" void cGame_exit(void* game, int a);
extern "C" void func_0039F190(void*, int);
struct sFlag001F72E0 {
    int f0;
    int f4;
    int active;
};
struct sGame001F72E0 {
    char pad[0x200];
    sFlag001F72E0* flag;
};
struct sSelf001F72E0 {
    char pad[0x10];
    char* mgr;
    char pad14[0x40];
    int done;
};

extern "C" void func_001F72E0(sSelf001F72E0* self, void* widget, int msg)
{
    if (widget != 0) {
        switch (msg) {
        case 5:
            (*(sGame001F72E0**)((char*)D_004A28A8 + 0x84))->flag->active = 1;
            switch (*(int*)((char*)widget + 0x18)) {
            case 0:
                {
                    void* game = *(void**)((char*)D_004A28A8 + 0x84);
                    D_004A19C4 = 0x27;
                    cGame_exit(game, 0);
                }
                break;
            case 1:
                self->done = 1;
                func_0039F190(self->mgr + 0x18, 1);
                break;
            }
            break;
        case 6:
            self->done = 1;
            (*(sGame001F72E0**)((char*)D_004A28A8 + 0x84))->flag->active = 1;
            func_0039F190(self->mgr + 0x18, 1);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", cOVState_BIGCHALLENGE_START_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void func_0020A380(void* self);
extern char D_0046F4E0[];

extern "C" void cOVState_BIGCHALLENGE_START_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046F4E0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", cOVState_BIGCHALLENGE_START_onGainTransition);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* func_00153C88(void* iface, int id);
extern "C" void* func_00153D28(void* iface, int id);
extern "C" void func_003A0E90(void* text, void* str);
extern "C" void func_003A0D00(void* text, void* str);
extern char D_0046F4F0[];
extern char D_004A23F0[];

extern "C" int cOVState_BIGCHALLENGE_START_onGainTransition(void* self, int gained)
{
    if (gained) {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 0xA);
        void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046F4F0));
        if (obj) {
            func_003A0E90(obj, func_00153C88(iface, *(int*)((char*)self + 0x9C)));
        }
        obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A23F0));
        if (obj) {
            func_003A0D00(obj, func_00153D28(iface, *(int*)((char*)self + 0x9C)));
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F74E0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A23E0[];
extern char D_004A23E8[];

extern "C" void func_001F74E0(void* self, void* item)
{
    int id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_004A23E0)) {
        *(int*)((char*)item + 0x18) = 0;
    } else {
        int id2 = *(int*)((char*)item + 0x38);
        if (id2 == GetHashValue32(D_004A23E8)) {
            *(int*)((char*)item + 0x18) = 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7548);
#ifdef SKIP_ASM
extern void* D_004A3DD8;
extern "C" int* func_0030C820(void* list);

extern "C" void func_001F7548(void* self)
{
    int* p = func_0030C820((char*)D_004A3DD8 + 0x1C4);
    if (p != 0) {
        *(int*)((char*)self + 0x9C) = *p;
    } else {
        *(int*)((char*)self + 0x9C) = *(int*)((char*)D_004A3DD8 + 0x2A0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7590);
#ifdef SKIP_ASM
extern "C" int func_001F7590(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F75A0);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
void func_0029D6D0(void* self);
extern "C" void func_0030B540(void* self);
extern "C" void func_0030B658(void* self);
extern "C" void func_0030B6F8(void* self);
extern "C" int func_0030B8C0(void* self);
extern void* D_004A3DD8;
extern int D_004A26FC;
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_004428F0[];

struct sMgr_75A0 {
    char pad[0x2A0];
    int f2A0;
};

extern "C" void func_001F75A0(void* self, void* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5:
        if (*(int*)((char*)item + 0x18) == 0) {
            if (func_0030B8C0(D_004A3DD8) != 0) {
                func_0030B6F8(D_004A3DD8);
            } else {
                ((sMgr_75A0*)D_004A3DD8)->f2A0 = *(int*)((char*)self + 0x9C);
                func_0030B540(D_004A3DD8);
            }
            D_004A26FC = 3;
            D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
            func_0029D6D0(func_0028B180());
            break;
        }
    case 6:
        ((sMgr_75A0*)D_004A3DD8)->f2A0 = *(int*)((char*)self + 0x9C);
        func_0030B658(D_004A3DD8);
        D_004A26FC = 3;
        D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F76B8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void func_0020A380(void* self);
extern char D_0046F500[];

extern "C" void func_001F76B8(void* self)
{
    void* engine;
    void* screen;
    *(int*)((char*)self + 0xC) = GetHashValue32(D_0046F500);
    engine = *(void**)((char*)self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046F500), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7738);
#ifdef SKIP_ASM
extern void* D_004A3DD8;
extern "C" int* func_0030C820(void* list);

extern "C" void func_001F7738(void* self)
{
    *(int*)((char*)self + 0x9C) = *func_0030C820((char*)D_004A3DD8 + 0x1C4);
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7770);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A23E0[];
extern char D_004A23E8[];
extern char D_004A23F8[];

extern "C" void func_001F7770(void* self, void* item)
{
    int id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_004A23E0)) {
        *(int*)((char*)item + 0x18) = 0;
    } else {
        int id2 = *(int*)((char*)item + 0x38);
        if (id2 == GetHashValue32(D_004A23E8)) {
            *(int*)((char*)item + 0x18) = 1;
        } else {
            int id3 = *(int*)((char*)item + 0x38);
            if (id3 == GetHashValue32(D_004A23F8)) {
                *(int*)((char*)item + 0x18) = 2;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F77F0);
#ifdef SKIP_ASM
extern "C" int func_001F77F0(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7800);
#ifdef SKIP_ASM
extern "C" void func_0020AB50(int id);
// PORT: func_0039F190 returns the last node; the unit declares it void.
void* func_0039F190_r(void* self, int a1) __asm__("func_0039F190");
struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* screen, int hash);
extern char D_0046E050[];

extern "C" void func_001F7800(void* self, void* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        int v = *(int*)((char*)item + 0x18);
        if (v == 0) {
            ((sMgr_75A0*)D_004A3DD8)->f2A0 = *(int*)((char*)self + 0x9C);
            func_0030B6F8(D_004A3DD8);
            func_0039F190_r((char*)*(void**)((char*)self + 0x10) + 0x18, 1);
            D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
            func_0029D6D0(func_0028B180());
            return;
        }
        if (v == 2) {
            func_0020AB50(0x1D);
            return;
        }
        break;
    }
    case 6: {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_0046E050));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame & 0xFFFF, 1);
        }
        break;
    }
    default:
        return;
    }
    func_0030B658(D_004A3DD8);
    func_0039F190_r((char*)*(void**)((char*)self + 0x10) + 0x18, 1);
    D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7958);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
// PORT: bound with an int return by asm label; the unit declares it void
int cUIText_setAsciiString_i(cUIText* self, const char* str) __asm__("cUIText_setAsciiString__FP7cUITextPCc");
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" int func_00144BF0(void* iface);
extern "C" char* func_00155130(void* iface, int i);
extern "C" char* func_00155190(void* iface, int i);
extern "C" char* func_00155208(void* iface, int i);
extern "C" int func_001FD190();
extern "C" char* func_0020A1A8(char* s);
extern "C" void func_0020A380(void* self);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void* p, int id);
extern "C" unsigned short* func_002C2508(void* str, int a1);
extern "C" unsigned short* func_002C2540(void* str, const char* s);
// PORT: func_002C26D0 is a varargs formatter (dst, fmt, ...)
extern "C" void func_002C26D0_1F7958(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern "C" void func_003A0E90(void* text, void* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern int D_004A2700;
extern char D_00535BC8[];
extern char D_0046F510[];
extern char D_0046E378[];
extern char D_0046F520[];
extern char D_0046F530[];
extern char D_0046E548[];
extern char D_0046E398[];
extern char D_0046E3A8[];
extern char D_0046E3C0[];
extern char D_004A2400[];
extern char D_004A2408[];
extern char D_004A2410[];
extern char D_0046F540[];
extern char D_0046F550[];
extern char D_0046E9F8[];
extern char D_0046E9E8[];
extern char D_004A2418[];
extern char D_004A2420[];
extern char D_004A2090[];
extern char D_004A2428[];
extern char D_004A2430[];
extern char D_004A2438[];
extern char D_004A2138[];

struct sVEntry_1F7958 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1F7958(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_1F7958* vt = *(sVEntry_1F7958**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

extern "C" void func_001F7958(char* self)
{
    char buf[0x40];
    char line[0x40];
    unsigned short wtext[0x68];
    unsigned short wfmt[0x10];
    int full;
    *(int*)(self + 0xA0) = 0;
    void* engine = *(void**)(self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046F510), 0);
    *(void**)(self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    engine = *(void**)(self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E378), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    full = 1;
    func_0020A380(self);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* stats = cBE_getInterface_Fv(cBE_getBE(), 8);
    signed char* g = (signed char*)D_00535BC8;
    int ev = g[0x4A];
    int mode = g[0x48];
    switch (ev) {
    case 6 ... 11:
        func_002C2508(wtext, func_001FD190());
        break;
    case 5:
        func_002C2540(wfmt, D_0046F520);
        func_002C26D0_1F7958(wtext, wfmt, func_00144BF0(race));
        break;
    default: {
        int name = 0;
        switch (mode) {
        case 0:
        case 5:
            name = Loc1F7958(D_0046E548);
            break;
        case 1:
            name = Loc1F7958(D_0046E398);
            break;
        case 2:
            name = Loc1F7958(D_0046E3A8);
            break;
        case 3:
            name = Loc1F7958(D_0046E3C0);
            break;
        }
        func_002C2540(wfmt, D_004A2400);
        func_002C26D0_1F7958(wtext, wfmt, func_00144BF0(race), name);
        break;
    }
    }
    func_003A0E90(cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0046F530)), wtext);
    signed char* g2 = (signed char*)D_00535BC8;
    int m = g2[0x48];
    if (m == 0 || m == 5) {
        cUIState_showObjSafe(self, D_004A2408);
        cUIState_hideObjSafe(self, D_004A2410);
        cUIState_showObjSafe(self, D_0046F540);
        cUIState_hideObjSafe(self, D_0046F550);
        cUIState_showObjSafe(self, D_0046E9F8);
        cUIState_hideObjSafe(self, D_0046E9E8);
    } else {
        cUIState_hideObjSafe(self, D_004A2408);
        cUIState_showObjSafe(self, D_004A2410);
        cUIState_hideObjSafe(self, D_0046F540);
        cUIState_showObjSafe(self, D_0046F550);
        cUIState_hideObjSafe(self, D_0046E9F8);
        cUIState_showObjSafe(self, D_0046E9E8);
        full = 0;
    }
    cUIState_showObjSafe(self, D_004A2418);
    cUIState_showObjSafe(self, D_004A2420);
    cUIState_showObjSafe(self, D_004A2090);
    if (D_004A2700 != 0) {
        cUIState_hideObjSafe(self, D_0046E9F8);
        cUIState_hideObjSafe(self, D_0046E9E8);
    }
    for (int i = 1; i < 6; i++) {
        sprintf(buf, D_004A2428, i);
        cUIText* t1 = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(buf));
        cUIText_setAsciiString_i(t1, func_00155208(stats, i - 1));
        sprintf(buf, D_004A2430, i);
        cUIText* t2 = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(buf));
        cUIText_setAsciiString_i(t2, func_00155190(stats, i - 1));
        sprintf(buf, D_004A2438, i);
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(buf));
        if (full == 1) {
            sprintf(line, func_0020A1A8(func_00155130(stats, i - 1)));
        } else {
            sprintf(line, D_004A2138, func_00155130(stats, i - 1));
        }
        cUIText_setAsciiString_i(t, line);
    }
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", cOVState_TOPTIMES_onWidgetCreate);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_0046F578[];
extern char D_0046F588[];
extern char D_0046F598[];
extern char D_0046F5A8[];
extern int D_004A2700;

static inline int isHashTOPTIMES(int id, char* s)
{
    return id == GetHashValue32(s);
}

extern "C" void cOVState_TOPTIMES_onWidgetCreate(void* self, cUIText* w)
{
    int id = *(int*)((char*)w + 0x38);
    if (isHashTOPTIMES(id, D_0046F578)) {
        if (D_004A2700 == 0) {
            cUIText_setUnicodeStringByID(w, GetHashValue32(D_0046F588));
        } else {
            cUIText_setUnicodeStringByID(w, GetHashValue32(D_0046F598));
        }
        *(int*)((char*)w + 0x18) = 0;
    } else if (isHashTOPTIMES(id, D_0046F5A8)) {
        *(int*)((char*)w + 0x18) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F7F08);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0039E4C0(void* self, void* a1);
extern "C" void func_0020A6F0(void* self, const char* name, const char* ext);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern signed char D_00535C11[];
extern char D_004A2428[];
extern char D_004A2430[];
extern char D_004A2438[];
extern char D_004A2440[];
extern char D_0046E4E8[];

static inline void LoadRider1F7F08(void* self, int n)
{
    char name[32];
    sprintf(name, D_004A2440, n);
    func_0020A6F0(self, name, D_0046E4E8);
    sprintf(name, D_004A2428, n);
    func_0020A6F0(self, name, D_0046E4E8);
    sprintf(name, D_004A2430, n);
    func_0020A6F0(self, name, D_0046E4E8);
    sprintf(name, D_004A2438, n);
    func_0020A6F0(self, name, D_0046E4E8);
}

extern "C" void func_001F7F08(void* self, void* a1)
{
    func_0039E4C0(self, a1);
    char* prof = (char*)cBE_getInterface_Fv(cBE_getBE(), 8);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int id = *(int*)(prof + 0x18);
    if (id >= 0) {
        LoadRider1F7F08(self, id + 1);
    }
    if (D_00535C11[0] == 2) {
        int id2 = *(int*)(prof + 0x1C);
        if (id2 >= 0) {
            LoadRider1F7F08(self, id2 + 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F80C8);
#ifdef SKIP_ASM
extern "C" int func_001F80C8(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F80D8);
#ifdef SKIP_ASM
struct sVEntry_001F80D8 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_001F80D8(void* self, void* a1, int a2)
{
    if (a1 != 0) {
        if (a2 == 5) {
            sVEntry_001F80D8* vt = *(sVEntry_001F80D8**)((char*)self + 0x8);
            vt[26].fn((char*)self + vt[26].delta);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstateenterlodge", func_001F8118);
#ifdef SKIP_ASM
extern int D_004A26FC;
extern "C" void func_0020AB50(int id);

extern "C" void func_001F8118(void* self, void* a1)
{
    if (*(int*)((char*)self + 0xA0) == 0) {
        int v = *(int*)((char*)a1 + 0x18);
        switch (v) {
        case 0:
            *(int*)((char*)self + 0xA0) = 1;
            D_004A26FC = 1;
            break;
        case 1:
            *(int*)((char*)self + 0xA0) = v;
            func_0020AB50(0x13);
            break;
        }
    }
}
#endif

