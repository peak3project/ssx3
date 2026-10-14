#include "common.h"

//100%
INCLUDE_ASM("fe/festateoptions", cFEStateOptions_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0045DD30[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cFEStateOptions_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DD30), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00188870);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A14F8[];
extern char D_004A1500[];
extern char D_004A1508[];
extern char D_004A1510[];
extern char D_004A1518[];
extern char D_004A1520[];
extern char D_004A1528[];
extern char D_004A1530[];

static inline int Is_00188870(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void func_00188870(void* self, void* item)
{
    if (Is_00188870(*(int*)((char*)item + 0x38), D_004A14F8)) {
        *(int*)((char*)item + 0x18) = 0x1C;
    } else if (Is_00188870(*(int*)((char*)item + 0x38), D_004A1500)) {
        *(int*)((char*)item + 0x18) = 0x1D;
    } else if (Is_00188870(*(int*)((char*)item + 0x38), D_004A1508)) {
        *(int*)((char*)item + 0x18) = 0x1F;
    } else if (Is_00188870(*(int*)((char*)item + 0x38), D_004A1510)) {
        *(int*)((char*)item + 0x18) = 0x1E;
    } else if (Is_00188870(*(int*)((char*)item + 0x38), D_004A1518)) {
        *(int*)((char*)item + 0x18) = 0x20;
    } else if (Is_00188870(*(int*)((char*)item + 0x38), D_004A1520)) {
        *(int*)((char*)item + 0x18) = 0x24;
    } else if (Is_00188870(*(int*)((char*)item + 0x38), D_004A1528)) {
        *(int*)((char*)item + 0x18) = 0x24;
    } else if (Is_00188870(*(int*)((char*)item + 0x38), D_004A1530)) {
        *(int*)((char*)item + 0x18) = 0x22;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00188980);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001CB030(void* self, void* engine, void* owner, int a3, int a4);
extern "C" void func_001CB418(void* self, char* s);
extern "C" void func_001CCF00(void* self, char* s);
extern "C" void func_001CE3C8(void* self, int a1, int a2, int a3);
extern "C" int func_00187D38(void* self);
extern "C" void func_00188E58(void* self);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern char D_0045D8D8[];
extern char D_0045DC60[];
extern char D_004A1408[];
extern char D_004A1520[];
extern char D_004A1530[];
extern int D_004A14D0;
extern int D_004A14D4;
extern int D_004A14D8;
extern int D_004A14DC;
extern int D_004A14E0;
extern char D_004A5A58;

struct sVE_188980p {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

class cListener_188980 {
public:
    virtual void v01();
    virtual void v02(int msg);
};

struct sOpt_188980 {
    char pad0[0x10];
    char* engine;           // 0x10
    char pad14;
    unsigned char port;     // 0x15
    char pad16[0x1C - 0x16];
    int flags;              // 0x1C
    char pad20[0x40 - 0x20];
    cUIScreen* screen;      // 0x40
    int pad44;
    int f48;                // 0x48
    int pad4C;
    void* popup;            // 0x50
};

static inline int Is_00188980(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void func_00188980(sOpt_188980* self, char* widget, unsigned int event)
{
    switch (event) {
    case 5:
        if (Is_00188980(*(int*)(widget + 0x38), D_004A1520)) {
            void* p = cMemMan_alloc(0x444, D_0045D8D8, 0x100, 0);
            void* pop = func_001CB030(p, self->engine, self, 0, self->port);
            self->popup = pop;
            func_001CB418(pop, D_004A1408);
            func_001CCF00(self->popup, D_004A1408);
            func_001CE3C8(self->popup, 0x4B, 1, 2);
            func_0039F290(self->engine + 0x18, self->popup);
            break;
        } else if (Is_00188980(*(int*)(widget + 0x38), D_004A1530)) {
            if (D_004A14E0 == 0 && (D_004A14D0 != 0 || D_004A14D4 != 0 || D_004A14DC != 0 || D_004A14D8 != 0)) {
                func_00188E58(self);
                break;
            }
            D_004A14E0 = 0;
            self->flags |= 0x80;
            int f = cUIScreen_getFrameByLabel(self->screen, GetHashValue32(D_0045DC60));
            if (f != 0xFFFF)
                cUIScreen_playFrame(self->screen, f, 1);
            if (self->f48 == 0)
                break;
            char* o = *(char**)self->engine;
            if (o != 0)
                *(int*)(o + 0xC) = 0x18;
        }
        {
            char* obj = *(char**)self->engine;
            sVE_188980p* vt = *(sVE_188980p**)(obj + 4);
            void* r = vt[4].fn(obj + vt[4].delta, self, *(int*)(widget + 0x18));
            if (r != 0)
                func_0039F400(self->engine + 0x18, r);
        }
        break;
    case 6: {
        if (D_004A14E0 == 0 && (D_004A14D0 != 0 || D_004A14D4 != 0 || D_004A14DC != 0 || D_004A14D8 != 0)) {
            func_00188E58(self);
            break;
        }
        D_004A14E0 = 0;
        self->flags |= 0x80;
        int f = cUIScreen_getFrameByLabel(self->screen, GetHashValue32(D_0045DC60));
        if (f != 0xFFFF)
            cUIScreen_playFrame(self->screen, f, 1);
        break;
    }
    case 13: {
        int r = func_00187D38((char*)self->popup + 0x74);
        char* obj = &D_004A5A58;
        char* l = *(char**)(self->engine + 0x14);
        if (l != 0)
            obj = l;
        if (obj != 0) {
            if (r == 1) {
                ((cListener_188980*)obj)->v02(6);
            } else {
                ((cListener_188980*)obj)->v02(4);
            }
        }
        self->popup = 0;
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00188C58);
#ifdef SKIP_ASM
extern int D_004A3484;

extern "C" int func_00188C58(void* self, void* a1)
{
    D_004A3484 = *(unsigned char*)((char*)a1 + 4);
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00188C68);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_00397870(void* list, int index);
extern char D_004A1530[];

extern "C" int func_00188C68(void* self, void* menu, unsigned int key, int index)
{
    if (key < 10) {
        if (key >= 8) {
            return 0x100;
        }
    }
    if (key == 6) {
        int h = *(int*)((char*)func_00397870((char*)menu + 0x74, index) + 0x38);
        if (h == GetHashValue32(D_004A1530)) {
            goto check;
        }
    }
    if (key == 7) {
    check:
        int r = 0x101;
        if (*(int*)((char*)self + 0x4C) == 0) {
            r = 1;
        }
        return r;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00188D08);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_0045DD40[];
extern char D_0045DD50[];
extern char D_0045DD20[];
extern char D_004A1530[];

struct sVEK188D08a {
    short delta;
    short index;
    int (*fn)(void*, int);
};
struct sVEK188D08b {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

static inline int IsK188D08(int id, char* s)
{
    return id == GetHashValue32(s);
}

extern "C" void func_00188D08(void* self, char* popup, int event)
{
    switch (event) {
    case 0x15: {
        void* scr = *(void**)(popup + 0x40);
        cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(scr, GetHashValue32(D_0045DD40));
        if (text != 0) {
            cUIText_setUnicodeStringByID(text, GetHashValue32(D_0045DD50));
        }
        break;
    }
    case 0x16:
        if (IsK188D08(*(int*)(popup + 0xC), D_0045DD20)) {
            void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1530));
            sVEK188D08a* vt = *(sVEK188D08a**)(popup + 8);
            if (vt[23].fn(popup + vt[23].delta, 0)) {
                if (o != 0) {
                    *(int*)((char*)self + 0x48) = 1;
                    *(int*)((char*)self + 0x4C) = 1;
                    sVEK188D08b* vt2 = *(sVEK188D08b**)((char*)self + 8);
                    vt2[19].fn((char*)self + vt2[19].delta, o, 5);
                }
            } else {
                if (o != 0) {
                    *(int*)((char*)self + 0x48) = 0;
                    *(int*)((char*)self + 0x4C) = 1;
                    sVEK188D08b* vt2 = *(sVEK188D08b**)((char*)self + 8);
                    vt2[19].fn((char*)self + vt2[19].delta, o, 6);
                }
            }
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00188E58);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc bound as operator new so gcc treats it as malloc-like.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_0039F290(void* list, void* item);
extern char D_0045DD68[];
extern void* D_0046B3D0[];
extern int D_004A14D0;
extern int D_004A14D4;
extern int D_004A14D8;
extern int D_004A14DC;
extern int D_004A14E0;

extern "C" void func_00188E58(void* self)
{
    char* p = (char*)operator new(0x4C, D_0045DD68, 0x100, 0);
    func_0039E318(p, *(void**)((char*)self + 0x10), self);
    *(void***)(p + 8) = D_0046B3D0;
    *(char*)(p + 0x48) = 0;
    func_0039F290(*(char**)((char*)self + 0x10) + 0x18, p);
    D_004A14D8 = 0;
    D_004A14E0 = 1;
    D_004A14DC = 0;
    D_004A14D4 = 0;
    D_004A14D0 = 0;
    *(int*)((char*)self + 0x4C) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00188EE8);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern void* D_0046C6F0[];

extern "C" void* func_00188EE8(void* self)
{
    func_0039E2A0(self);
    *(void***)((char*)self + 0x8) = D_0046C6F0;
    *(int*)((char*)self + 0xC) = 0x1C;
    return self;
}
#endif

INCLUDE_ASM("fe/festateoptions", cFEStateOptionsGame_onCreateScreen);

extern "C" void* func_0039E4C0(void* self);

//100%
INCLUDE_ASM("fe/festateoptions", func_001895F0__FPv);
#ifdef SKIP_ASM
void* func_001895F0(void* self)
{
    return func_0039E4C0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00189610);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0014F4F8(void* iface);
extern "C" void func_00189D60(void* self);
extern "C" void* func_0028B180();
extern "C" void func_0029ED90(void* p, int a);
extern char D_0045DD20[];
extern char D_0045DDD8[];
extern int D_004A14D0;
extern void* D_004A289C;

struct sGameCfg_189610 {
    unsigned int flags;     // 0x0
    signed char f4;
    signed char f5;         // 0x5
    signed char f6;         // 0x6
    char pad7[0x288 - 7];
};
// PORT: D_00535610 is viewed with different types across the unit; view bound by asm label
extern sGameCfg_189610 D_00535610_189610 __asm__("D_00535610");

struct sVE_189610a {
    short delta;
    short index;
    int (*fn)(void*, int);
};
struct sVE_189610b {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};
struct sVE_189610c {
    short delta;
    short index;
    void (*fn)(void*);
};

static inline int Is_189610(int id, char* s)
{
    return id == GetHashValue32(s);
}

static inline int GetOpt_189610(char* w, int i)
{
    sVE_189610a* vt = *(sVE_189610a**)(w + 8);
    return vt[23].fn(w + vt[23].delta, i);
}

static inline sGameCfg_189610 Cfg_189610()
{
    return D_00535610_189610;
}

extern "C" void func_00189610(void* self, char* popup, int event)
{
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 4);
    switch (event) {
    case 0x15:
        break;
    case 0x16:
        if (Is_189610(*(int*)(popup + 0xC), D_0045DD20)) {
            if (GetOpt_189610(popup, 2)) {
                func_0014F4F8(iface);
                D_004A14D0 = 1;
                func_00189D60(self);
                func_0029ED90(func_0028B180(), 1);
            }
        } else if (Is_189610(*(int*)(popup + 0xC), D_0045DDD8)) {
            if (GetOpt_189610(popup, 2)) {
                int a = GetOpt_189610(popup, 0);
                int b = GetOpt_189610(popup, 1);
                sGameCfg_189610* c = &D_00535610_189610;
                D_004A14D0 = 1;
                c->f6 = a;
                c->f5 = b;
            } else {
                char* g = (char*)D_004A289C;
                sVE_189610b* vt = *(sVE_189610b**)(g + 0x10D8);
                char* thisp = g + vt[12].delta;
                void (**pf)(void*, int, int) = &vt[12].fn;
                (*pf)(thisp, Cfg_189610().f6, Cfg_189610().f5);
            }
        } else if (*(int*)(popup + 0xC) == 0x1B) {
            if (GetOpt_189610(popup, 2)) {
                func_0014F4F8(iface);
                D_004A14D0 = 1;
                func_00189D60(self);
            }
        }
        {
            sVE_189610c* vt = *(sVE_189610c**)(iface + 0xC);
            vt[1].fn(iface + vt[1].delta);
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00189958);
#ifdef SKIP_ASM
extern "C" int func_00189958(void* self, int a1, int a2)
{
    return a2 != 9 ? 0x101 : 0x100;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00189970);
#ifdef SKIP_ASM
extern "C" int func_00189970(void* self, int a1, int a2)
{
    return a2 ? 0x100 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", cFEStateOptionsGame_onWidgetEvent);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: cMemMan_alloc bound as operator new so gcc treats it as malloc-like.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_00228C08(void* p);
extern "C" void* func_0028B180();
extern "C" void func_0029ED90(void* p, int a);
extern "C" int func_0039A738(void* self);
extern "C" void func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern char D_0045DD68[];
extern char D_0045DF88[];
extern char D_0045DFA0[];
extern void* D_0046B230[];
extern void* D_0046B300[];
extern void* D_0046B3D0[];
extern char D_004A1520[];
extern char D_004A1528[];
extern char* D_00440FD8[];
extern int D_004A14D0;
extern void* D_004A28A8;

struct sGameCfg_189980 {
    unsigned int pad0 : 19;
    bool showHud : 1;           // bit 19
    unsigned int f20 : 2;       // bits 20-21
    unsigned int mode : 3;      // bits 22-24
    unsigned int pad25 : 7;
    char rest[0x288 - 4];
};
// PORT: D_00535610 is viewed with different types across the unit; view bound by asm label
extern sGameCfg_189980 D_00535610_189980 __asm__("D_00535610");

struct sVE_189980a {
    short delta;
    short index;
    void (*fn)(void*);
};
struct sVE_189980b {
    short delta;
    short index;
    void (*fn)(void*, char);
};
struct sVE_189980c {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sOptGame_189980 {
    char pad0[0x10];
    char* engine;           // 0x10
    char pad14[0x40 - 0x14];
    char* screen;           // 0x40
    char pad44[0x48 - 0x44];
    signed char item[3];    // 0x48
};

static inline int Is_189980(int id, char* s)
{
    return id == GetHashValue32(s);
}

static inline void Refresh_189980(sOptGame_189980* self)
{
    char* scr = self->screen;
    sVE_189980a* vt = *(sVE_189980a**)(scr + 0x48);
    char* sub = scr + 0x40;
    vt[16].fn(sub + vt[16].delta);
}

extern "C" void cFEStateOptionsGame_onWidgetEvent(sOptGame_189980* self, char* widget, unsigned int event)
{
    if (widget == 0) {
        return;
    }
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 4);
    switch (event) {
    case 7: {
        char* p = (char*)operator new(0x4C, D_0045DD68, 0x100, 0);
        func_0039E318(p, self->engine, self);
        *(void***)(p + 8) = D_0046B3D0;
        p[0x48] = 0;
        func_0039F290(self->engine + 0x18, p);
        break;
    }
    case 5:
        if (Is_189980(*(int*)(widget + 0x38), D_004A1520)) {
            char* p = (char*)operator new(0x54, D_0045DF88, 0x100, 0);
            func_0039E318(p, self->engine, self);
            *(void***)(p + 8) = D_0046B230;
            *(int*)(p + 0x4C) = 0;
            *(int*)(p + 0x48) = 0;
            p[0x50] = 0;
            func_0039F290(self->engine + 0x18, p);
        } else if (Is_189980(*(int*)(widget + 0x38), D_004A1528)) {
            char* p = (char*)operator new(0x4C, D_0045DFA0, 0x100, 0);
            func_0039E318(p, self->engine, self);
            *(void***)(p + 8) = D_0046B300;
            *(int*)(p + 0xC) = 0x1B;
            func_0039F290(self->engine + 0x18, p);
        }
        break;
    case 6: {
        {
            sVE_189980a* vt = *(sVE_189980a**)(iface + 0xC);
            vt[1].fn(iface + vt[1].delta);
        }
        func_00228C08(D_004A28A8);
        {
            char* o = *(char**)((char*)D_004A28A8 + 0x8C);
            sVE_189980b* vt = *(sVE_189980b**)(o + 4);
            vt[3].fn(o + vt[3].delta, D_00535610_189980.mode);
        }
        Refresh_189980(self);
        char* eng = *(char**)self->engine;
        sVE_189980c* vt = *(sVE_189980c**)(eng + 4);
        void* r = vt[5].fn(eng + vt[5].delta, self, *(int*)(widget + 0x18));
        if (r != 0) {
            func_0039F400(self->engine + 0x18, r);
        }
        break;
    }
    case 9:
        if (self->item[0] >= 0 && Is_189980(*(int*)(widget + 0x38), D_00440FD8[self->item[0]])) {
            D_00535610_189980.mode = func_0039A738(widget);
            char* o = *(char**)((char*)D_004A28A8 + 0x8C);
            sVE_189980b* vt = *(sVE_189980b**)(o + 4);
            char* thisp = o + vt[3].delta;
            vt[3].fn(thisp, func_0039A738(widget));
            Refresh_189980(self);
            func_0029ED90(func_0028B180(), 1);
        }
        if (self->item[1] >= 0 && Is_189980(*(int*)(widget + 0x38), D_00440FD8[self->item[1]])) {
            bool on = *(unsigned char*)(widget + 0x319);
            D_00535610_189980.showHud = on;
        }
        if (self->item[2] >= 0 && Is_189980(*(int*)(widget + 0x38), D_00440FD8[self->item[2]])) {
            D_00535610_189980.f20 = *(unsigned char*)(widget + 0x319);
        }
        func_00228C08(D_004A28A8);
        D_004A14D0 = 1;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_00189D60);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0039A7A8(void* self, int v);
extern "C" int func_0039A738(void* self);
extern "C" void func_00228C08(void* p);
extern char* D_00440FD8[];
extern void* D_004A28A8;
extern void* D_004A289C;

struct sGameCfg_189D60 {
    unsigned int pad0 : 19;
    unsigned int showHud : 1;       // bit 19
    unsigned int f20 : 2;           // bits 20-21
    unsigned int mode : 3;          // bits 22-24
    unsigned int pad25 : 7;
    signed char f4;
    signed char f5;                 // 0x5
    signed char f6;                 // 0x6
    char pad7[0x288 - 7];
};
// PORT: D_00535610 is viewed with different types across the unit; view bound by asm label
extern sGameCfg_189D60 D_00535610_189D60 __asm__("D_00535610");

struct sOptionIface_189D60 {
    sGameCfg_189D60 getOptions() { return D_00535610_189D60; }
};

struct sVE_189D60a {
    short delta;
    short index;
    void (*fn)(void*);
};
struct sVE_189D60b {
    short delta;
    short index;
    void (*fn)(void*, char);
};
struct sVE_189D60c {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

struct sOptGame_189D60 {
    char pad0[0x40];
    char* screen;                   // 0x40
    char pad44[0x4];
    signed char item[3];            // 0x48
};

static inline void* find_189D60(sOptGame_189D60* self, int i)
{
    return cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00440FD8[self->item[i]]));
}

// Pushes the current game options into the option widgets of the screen.
extern "C" void func_00189D60(void* self_)
{
    sOptGame_189D60* self = (sOptGame_189D60*)self_;
    sOptionIface_189D60* iface = (sOptionIface_189D60*)cBE_getInterface_Fv(cBE_getBE(), 4);
    if (self->item[0] >= 0) {
        void* w = find_189D60(self, 0);
        if (w != 0) {
            func_0039A7A8(w, iface->getOptions().mode);
            char* o = *(char**)((char*)D_004A28A8 + 0x8C);
            sVE_189D60b* vt = *(sVE_189D60b**)(o + 4);
            vt[3].fn(o + vt[3].delta, func_0039A738(w));
            char* scr = self->screen;
            sVE_189D60a* vt2 = *(sVE_189D60a**)(scr + 0x48);
            char* sub = scr + 0x40;
            vt2[16].fn(sub + vt2[16].delta);
        }
    }
    if (self->item[1] >= 0) {
        void* w = find_189D60(self, 1);
        if (w != 0)
            func_0039A7A8(w, iface->getOptions().showHud);
    }
    if (self->item[2] >= 0) {
        void* w = find_189D60(self, 2);
        if (w != 0)
            func_0039A7A8(w, iface->getOptions().f20);
    }
    char* g = (char*)D_004A289C;
    sVE_189D60c* vt = *(sVE_189D60c**)(g + 0x10D8);
    char* thisp = g + vt[12].delta;
    void (**pf)(void*, int, int) = &vt[12].fn;
    (*pf)(thisp, iface->getOptions().f6, iface->getOptions().f5);
    func_00228C08(D_004A28A8);
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018A258);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern void* D_0046C620[];
extern int D_004A14D4;

extern "C" void* func_0018A258(void* self)
{
    func_0039E2A0(self);
    *(void***)((char*)self + 8) = D_0046C620;
    *(int*)((char*)self + 0xC) = 0x1D;
    D_004A14D4 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", cFEStateOptionsSound_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void cFEStateOptionsSound_updateWidget(void* self);
extern char D_0045DFC0[];
extern char D_004A1580[];
extern char D_004A1588[];
extern char D_004A1528[];
extern int D_004A1A70;

class cUIObj_18A298 {
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

extern "C" void cFEStateOptionsSound_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DFC0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    cFEStateOptionsSound_updateWidget(self);
    int on = D_004A1A70 == 1;
    cUIObj_18A298* a = (cUIObj_18A298*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1580));
    if (a != 0) {
        a->setVisible(on);
    }
    cUIObj_18A298* b = (cUIObj_18A298*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1588));
    if (b != 0) {
        b->setVisible(on ^ 1);
    }
    cUIObj_18A298* c = (cUIObj_18A298*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1528));
    if (c != 0) {
        c->setVisible(on);
        c->setEnabled(on ^ 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018A3D8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0014F458(void* iface);
extern "C" void func_0018BEF8(void* self, unsigned int mode);
extern "C" void* func_0028B180();
extern "C" void func_00287410(void* snd, int v);
extern "C" void func_00287488(void* snd, int v);
extern "C" void func_00287520(void* snd, int v);
extern "C" void func_00287558(void* snd, int v);
extern "C" void func_002875D0(void* snd, int v);
extern "C" void cFEStateOptionsSound_updateWidget(void* self);
extern char D_0045DD20[];
extern int D_004A14D4;

struct sSndCfg_18A3D8 {
    unsigned int sfxVol : 4;        // bits 0-3
    unsigned int musicVol : 4;      // bits 4-7
    unsigned int speechVol : 4;     // bits 8-11
    unsigned int output : 2;        // bits 12-13
    unsigned int pad14 : 2;
    int f16 : 1;                    // bit 16
    int f17 : 1;                    // bit 17
    int pad18 : 14;
    char rest[0x288 - 4];
};
// PORT: D_00535610 is viewed with different types across the unit; view bound by asm label
extern sSndCfg_18A3D8 D_00535610_18A3D8 __asm__("D_00535610");

struct sVE_18A3D8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Is_18A3D8(int id, char* s)
{
    return id == GetHashValue32(s);
}

static inline int GetOpt_18A3D8(char* w, int i)
{
    sVE_18A3D8* vt = *(sVE_18A3D8**)(w + 8);
    return vt[23].fn(w + vt[23].delta, i);
}

static inline sSndCfg_18A3D8 Cfg_18A3D8()
{
    return D_00535610_18A3D8;
}

extern "C" void func_0018A3D8(void* self, char* popup, int event)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 4);
    switch (event) {
    case 0x15:
        break;
    case 0x16:
        if (Is_18A3D8(*(int*)(popup + 0xC), D_0045DD20)) {
            if (GetOpt_18A3D8(popup, 2)) {
                func_0014F458(iface);
                func_0018BEF8(self, D_00535610_18A3D8.output);
                func_00287410(func_0028B180(), Cfg_18A3D8().sfxVol);
                func_00287488(func_0028B180(), Cfg_18A3D8().speechVol);
                func_00287520(func_0028B180(), Cfg_18A3D8().musicVol);
                func_00287558(func_0028B180(), Cfg_18A3D8().f17 != 0);
                func_002875D0(func_0028B180(), Cfg_18A3D8().f16 != 0);
                cFEStateOptionsSound_updateWidget(self);
            }
            D_004A14D4 = 1;
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018A870__FPv);
#ifdef SKIP_ASM
void* func_0018A870(void* self)
{
    return func_0039E4C0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018A890);
#ifdef SKIP_ASM
extern "C" int func_0018A890(void* self, int a1, int a2)
{
    switch (a2) {
    case 9:
        return 0x100;
    case 6:
        return 0;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018A8C0);
#ifdef SKIP_ASM
extern "C" int func_0018A8C0(void* self, int a1, int a2)
{
    return a2 ? 0x100 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018A8D0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: cMemMan_alloc bound as operator new so gcc treats it as malloc-like.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern "C" int func_0039A738(void* self);
extern "C" void func_0018BEF8(void* self, unsigned int mode);
extern "C" void* func_0028B180();
extern "C" void func_00287410(void* snd, int v);
extern "C" void func_00287488(void* snd, int v);
extern "C" void func_00287520(void* snd, int v);
extern "C" void func_00287558(void* snd, int v);
extern "C" void func_002875D0(void* snd, int v);
extern char D_0045DD68[];
extern void* D_0046B3D0[];
extern char D_004A1568[];
extern char D_004A1590[];
extern char D_004A1598[];
extern char D_004A15A0[];
extern char D_004A15A8[];
extern char D_004A15B0[];
extern char D_004A15B8[];
extern int D_004A1A70;
extern int D_004A14D4;

struct sSndCfg_18A8D0 {
    unsigned int sfxVol : 4;        // bits 0-3
    unsigned int musicVol : 4;      // bits 4-7
    unsigned int speechVol : 4;     // bits 8-11
    unsigned int output : 2;        // bits 12-13
    unsigned int pad14 : 2;
    int f16 : 1;                    // bit 16
    int f17 : 1;                    // bit 17
    int f18 : 1;                    // bit 18
    int pad19 : 13;
    char rest[0x288 - 4];
};
// PORT: D_00535610 is viewed with different types across the unit; view bound by asm label
extern sSndCfg_18A8D0 D_00535610_18A8D0 __asm__("D_00535610");

struct sVE_18A8D0a {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE_18A8D0c {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

static inline int Is_18A8D0(int id, char* s)
{
    return id == GetHashValue32(s);
}

static inline sSndCfg_18A8D0 Cfg_18A8D0()
{
    return D_00535610_18A8D0;
}

struct sOptSound_18A8D0 {
    char pad0[0x10];
    char* engine;                   // 0x10
};

// Sound options screen: widget event handler (popup, apply on exit, value changes).
extern "C" void func_0018A8D0(sOptSound_18A8D0* self, char* widget, unsigned int event)
{
    if (widget == 0)
        return;
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 4);
    switch (event) {
    case 5: // empty case; needed for the original compare-tree shape
        break;
    case 7: {
        char* p = (char*)operator new(0x4C, D_0045DD68, 0x100, 0);
        func_0039E318(p, self->engine, self);
        *(void***)(p + 8) = D_0046B3D0;
        p[0x48] = 0;
        func_0039F290(self->engine + 0x18, p);
        break;
    }
    case 6: {
        {
            sVE_18A8D0a* vt = *(sVE_18A8D0a**)(iface + 0xC);
            vt[1].fn(iface + vt[1].delta);
        }
        func_00287410(func_0028B180(), Cfg_18A8D0().sfxVol);
        func_00287488(func_0028B180(), Cfg_18A8D0().speechVol);
        func_00287520(func_0028B180(), Cfg_18A8D0().musicVol);
        func_00287558(func_0028B180(), Cfg_18A8D0().f17 != 0);
        func_002875D0(func_0028B180(), Cfg_18A8D0().f16 != 0);
        char* eng = *(char**)self->engine;
        sVE_18A8D0c* vt = *(sVE_18A8D0c**)(eng + 4);
        void* r = vt[5].fn(eng + vt[5].delta, self, *(int*)(widget + 0x18));
        if (r != 0)
            func_0039F400(self->engine + 0x18, r);
        break;
    }
    case 9:
        if (Is_18A8D0(*(int*)(widget + 0x38), D_004A1568)) {
            D_00535610_18A8D0.output = func_0039A738(widget);
            func_0018BEF8(self, func_0039A738(widget));
        }
        else if (Is_18A8D0(*(int*)(widget + 0x38), D_004A1590)) {
            unsigned char vol = *(unsigned char*)(widget + 0x74);
            D_00535610_18A8D0.sfxVol = vol;
            func_00287410(func_0028B180(), Cfg_18A8D0().sfxVol);
        }
        else if (Is_18A8D0(*(int*)(widget + 0x38), D_004A1598)) {
            unsigned char vol = *(unsigned char*)(widget + 0x74);
            D_00535610_18A8D0.speechVol = vol;
            func_00287488(func_0028B180(), Cfg_18A8D0().speechVol);
        }
        else if (Is_18A8D0(*(int*)(widget + 0x38), D_004A15A0)) {
            unsigned char vol = *(unsigned char*)(widget + 0x74);
            D_00535610_18A8D0.musicVol = vol;
            func_00287520(func_0028B180(), Cfg_18A8D0().musicVol);
        }
        else if (Is_18A8D0(*(int*)(widget + 0x38), D_004A15A8)) {
            D_00535610_18A8D0.f17 = func_0039A738(widget) != 0;
            func_00287558(func_0028B180(), Cfg_18A8D0().f17 != 0);
        }
        else if (Is_18A8D0(*(int*)(widget + 0x38), D_004A15B0)) {
            D_00535610_18A8D0.f16 = func_0039A738(widget) != 0;
            func_002875D0(func_0028B180(), Cfg_18A8D0().f16 != 0);
        }
        bool on = D_004A1A70 == 1;
        if (on && Is_18A8D0(*(int*)(widget + 0x38), D_004A15B8))
            D_00535610_18A8D0.f18 = func_0039A738(widget) != 0;
        D_004A14D4 = 1;
        break;
    }
}
#endif

INCLUDE_ASM("fe/festateoptions", cFEStateOptionsSound_updateWidget);

//100%
INCLUDE_ASM("fe/festateoptions", func_0018BEF8);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" int func_00287670(void* snd);
extern "C" int func_002876A0(void* snd);
extern "C" int func_002876D0(void* snd);
extern "C" void func_00286200(void* snd);
extern "C" void func_00284C28();
extern "C" void SSXAUDIO_Init(int mode);
extern "C" void func_00287410(void* snd, int v);
extern "C" void func_00287488(void* snd, int v);
extern "C" void func_00287520(void* snd, int v);
extern "C" void func_00287558(void* snd, int v);
extern "C" void func_002875D0(void* snd, int v);
extern "C" void func_00285FB0(void* snd);

struct sVE_18BEF8i {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sVE_18BEF8v {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0018BEF8(void* self, unsigned int mode)
{
    int m;
    switch (mode) {
    case 1:
        m = 2;
        break;
    case 2:
        m = 0;
        break;
    case 3:
        m = 3;
        break;
    case 0:
    default:
        m = 1;
        break;
    }
    char* obj = *(char**)(**(char***)((char*)func_0028B180() + 0x118) + 0x1D8);
    sVE_18BEF8i* vt = *(sVE_18BEF8i**)(obj + 4);
    if (vt[2].fn(obj + vt[2].delta, m) == 1) {
        float a = func_00287670(func_0028B180());
        float b = func_002876A0(func_0028B180());
        float c = func_002876D0(func_0028B180());
        int s0 = *(int*)((char*)func_0028B180() + 0x62B8);
        int s1 = *(int*)((char*)func_0028B180() + 0x62B4);
        int s2 = *(int*)((char*)func_0028B180() + 0x534);
        func_00286200(func_0028B180());
        func_00284C28();
        SSXAUDIO_Init(m);
        func_00287410(func_0028B180(), (int)a);
        func_00287488(func_0028B180(), (int)b);
        func_00287520(func_0028B180(), (int)c);
        func_00287558(func_0028B180(), s0);
        func_002875D0(func_0028B180(), s1);
        func_00285FB0(func_0028B180());
        char* snd = (char*)func_0028B180();
        sVE_18BEF8v* vt2 = *(sVE_18BEF8v**)(snd + 0x5558);
        char* sub = snd + 0x118;
        vt2[4].fn(sub + vt2[4].delta, s2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C0E8);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern void* D_0046C550[];
extern int D_004A14D8;

extern "C" void* func_0018C0E8(void* self)
{
    func_0039E2A0(self);
    *(void***)((char*)self + 8) = D_0046C550;
    *(int*)((char*)self + 0xC) = 0x1E;
    D_004A14D8 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C128);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0045E038[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0018C478(void* self);

extern "C" void func_0018C128(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045E038), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0018C478(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C198__FPv);
#ifdef SKIP_ASM
void* func_0018C198(void* self)
{
    return func_0039E4C0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C1B8);
#ifdef SKIP_ASM
struct sVE_18C1B8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};
int GetHashValue32(char* str);
extern char D_0045DD20[];
extern int D_004A14D8;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0014F600(void* self);
extern "C" void func_0018C478(void* self);

extern "C" void func_0018C1B8(void* self, void* widget, int msg)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 4);
    switch (msg) {
    case 0x15:
        break;
    case 0x16: {
        int h = *(int*)((char*)widget + 0xC);
        if (h == GetHashValue32(D_0045DD20)) {
            sVE_18C1B8* e = &(*(sVE_18C1B8**)((char*)widget + 8))[23];
            if (e->fn((char*)widget + e->delta, 2) != 0) {
                func_0014F600(iface);
                func_0018C478(self);
                D_004A14D8 = 1;
            }
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C270);
#ifdef SKIP_ASM
extern "C" int func_0018C270(void* self, int a1, int a2)
{
    switch (a2) {
    case 9:
        return 0x100;
    case 6:
        return 0;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C2A0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: cMemMan_alloc bound as operator new so gcc treats it as malloc-like.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern char D_0045DD68[];
extern void* D_0046B3D0[];
extern int D_004A14D8;

struct sOptions_C2A0 {
    unsigned int pad0 : 30;
    unsigned int mode : 2;
    int data[(0x288 - 4) / 4];
};
extern sOptions_C2A0 D_00535610_C2A0 __asm__("D_00535610");

struct sVE_18C2A0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sVE_18C2A0n {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE_18C2A0p {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

static inline int Is_0018C2A0(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void func_0018C2A0(char* self, char* widget, unsigned int event)
{
    if (widget == 0) {
        return;
    }
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 4);
    switch (event) {
    case 7: {
        char* p = (char*)operator new(0x4C, D_0045DD68, 0x100, 0);
        func_0039E318(p, *(void**)(self + 0x10), self);
        *(void***)(p + 8) = D_0046B3D0;
        *(char*)(p + 0x48) = 0;
        func_0039F290(*(char**)(self + 0x10) + 0x18, p);
        break;
    }
    case 6: {
        sVE_18C2A0n* vt = *(sVE_18C2A0n**)(iface + 0xC);
        vt[1].fn(iface + vt[1].delta);
        char* obj = **(char***)(self + 0x10);
        sVE_18C2A0p* vt2 = *(sVE_18C2A0p**)(obj + 4);
        void* r = vt2[5].fn(obj + vt2[5].delta, self, *(int*)(widget + 0x18));
        if (r != 0) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        }
        break;
    }
    case 1: {
        sVE_18C2A0* vt = *(sVE_18C2A0**)(widget + 8);
        vt[9].fn(widget + vt[9].delta, 1);
        D_004A14D8 = 1;
        D_00535610_C2A0.mode = *(unsigned char*)(widget + 0x18);
        break;
    }
    case 2:
        if (Is_0018C2A0(*(int*)(widget + 0x38), D_004A14F8) || Is_0018C2A0(*(int*)(widget + 0x38), D_004A1500) ||
            Is_0018C2A0(*(int*)(widget + 0x38), D_004A1508)) {
            sVE_18C2A0* vt = *(sVE_18C2A0**)(widget + 8);
            vt[9].fn(widget + vt[9].delta, 0);
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C478);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern char D_004A1398[];

struct sName_C478 {
    char s[2];
};
extern char D_004A14F8[];

struct sOptions_C478 {
    unsigned int pad0 : 30;
    unsigned int mode : 2;
    int data[(0x288 - 4) / 4];
};
extern sOptions_C478 D_00535610_C478 __asm__("D_00535610");

static inline int optMode_C478(sOptions_C478 o)
{
    return o.mode;
}

struct sVE_18C478h {
    short delta;
    short index;
    char* (*fn)(void*, int);
};

struct sVE_18C478v {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0018C478(void* vself)
{
    char* self = (char*)vself;
    cBE_getInterface_Fv(cBE_getBE(), 4);
    sName_C478 name = *(sName_C478*)D_004A14F8;
    char* menu = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1398));
    if (menu != 0) {
        int i;
        for (i = 0; i < 3; i++) {
            name.s[0] = '1' + i;
            sVE_18C478h* vt = *(sVE_18C478h**)(menu + 8);
            char* item = vt[14].fn(menu + vt[14].delta, GetHashValue32(name.s));
            if (item != 0) {
                *(int*)(item + 0x18) = i;
                if (i == optMode_C478(D_00535610_C478)) {
                    sVE_18C478v* vt2 = *(sVE_18C478v**)(item + 8);
                    vt2[9].fn(item + vt2[9].delta, 1);
                    cUIMenu_setSelectedByIndex(menu, i);
                } else {
                    sVE_18C478v* vt2 = *(sVE_18C478v**)(item + 8);
                    vt2[9].fn(item + vt2[9].delta, 0);
                }
            }
        }
        *(int*)(menu + 0x14) &= ~1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C658);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern void* D_0046C480[];
extern int D_004A14DC;

extern "C" void* func_0018C658(void* self)
{
    func_0039E2A0(self);
    *(void***)((char*)self + 8) = D_0046C480;
    *(int*)((char*)self + 0xC) = 0x1F;
    *(char*)((char*)self + 0x50) = 0;
    D_004A14DC = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", cFEStateOptionsController_onCreateScreen);
#ifdef SKIP_ASM
extern "C" void cUIListBox_addEntryByStringID(void* box, int id, int idx);
extern "C" void func_0018D108(void* self, int idx, float x, float y);
extern "C" void func_0018CDC0(void* self);
extern char D_0045E068[];
extern char D_004A1568[];
extern char D_004A1570[];
extern char D_004A15C8[];
extern char D_004A1578[];
extern char D_0045DF40[];
extern char D_0045E028[];
extern char D_0045E078[];
extern char D_0045E090[];

extern "C" void cFEStateOptionsController_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045E068), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x48) = 0;
    void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1568));
    if (o != 0) {
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045DF40), 0);
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045E028), 1);
    }
    o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1570));
    if (o != 0) {
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045DF40), 0);
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045E028), 1);
    }
    o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15C8));
    if (o != 0) {
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045E078), 0);
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045E090), 1);
    }
    o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1578));
    if (o != 0) {
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045E078), 0);
        cUIListBox_addEntryByStringID(o, GetHashValue32(D_0045E090), 1);
    }
    float zero = 0.0f;
    func_0018D108(self, 0, zero, zero);
    func_0018D108(self, 1, zero, zero);
    func_0018CDC0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C8B8);
#ifdef SKIP_ASM
extern "C" void func_0018D108(void* self, int idx, float x, float y);
void* func_0039E4A0(void* self);

extern "C" void* func_0018C8B8(void* self)
{
    func_0018D108(self, 0, 0.0f, 0.0f);
    func_0018D108(self, 1, 0.0f, 0.0f);
    return func_0039E4A0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018C910);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBENewPlayerInterface_defaultCtrl(void* self);
extern "C" void func_0018CDC0(void* self);
extern "C" void func_0018D108(void* self, int idx, float x, float y);
extern char D_0045DD20[];
extern int D_004A14DC;

static inline int Is_0018C910(int id, char* s) { return id == GetHashValue32(s); }

class cUIObj_18C910 {
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
    virtual int v23(int a);
};

extern "C" void func_0018C910(void* self, cUIObj_18C910* obj, int msg)
{
    void* pi = cBE_getInterface_Fv(cBE_getBE(), 1);
    switch (msg) {
    case 0x15: {
        float zero = 0.0f;
        func_0018D108(self, 0, zero, zero);
        func_0018D108(self, 1, zero, zero);
        break;
    }
    case 0x16:
        if (Is_0018C910(*(int*)((char*)obj + 0xC), D_0045DD20)) {
            if (obj->v23(2) != 0) {
                cBENewPlayerInterface_defaultCtrl(pi);
                func_0018CDC0(self);
                D_004A14DC = 1;
            }
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018CA10);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: cMemMan_alloc bound as operator new so gcc treats it as malloc-like.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern "C" int func_0039A738(void* self);
extern "C" void func_00147528(void* self, int index, int value);
extern "C" void func_00147658(void* self, int index, int value);
extern "C" int func_001474E8(void* iface, int a1);
extern "C" void func_0018CF50(void* self, int on);
extern "C" void func_0018D108(void* self, int idx, float x, float y);
extern char D_0045DD68[];
extern void* D_0046B3D0[];
extern char D_004A1568[];
extern char D_004A1570[];
extern char D_004A15C8[];
extern char D_004A1578[];
extern int D_004A14DC;

struct sVE_18CA10n {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE_18CA10p {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

static inline int Is_0018CA10(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void func_0018CA10(char* self, char* widget, unsigned int event)
{
    if (widget == 0) {
        return;
    }
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
    switch (event) {
    case 7: {
        char* p = (char*)operator new(0x4C, D_0045DD68, 0x100, 0);
        func_0039E318(p, *(void**)(self + 0x10), self);
        *(void***)(p + 8) = D_0046B3D0;
        *(char*)(p + 0x48) = 0;
        func_0039F290(*(char**)(self + 0x10) + 0x18, p);
        break;
    }
    case 6: {
        sVE_18CA10n* vt = *(sVE_18CA10n**)(iface + 0xC);
        vt[1].fn(iface + vt[1].delta);
        char* obj = **(char***)(self + 0x10);
        sVE_18CA10p* vt2 = *(sVE_18CA10p**)(obj + 4);
        void* r = vt2[5].fn(obj + vt2[5].delta, self, *(int*)(widget + 0x18));
        if (r != 0) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        }
        break;
    }
    case 9:
        if (Is_0018CA10(*(int*)(widget + 0x38), D_004A1568)) {
            func_00147528(iface, 0, func_0039A738(widget) != 0);
            if (func_001474E8(iface, 0)) {
                func_0018D108(self, 0, 10.0f, 10.0f);
                *(int*)(self + 0x48) = 0x3C;
                *(unsigned char*)(self + 0x50) |= 1;
            } else {
                func_0018D108(self, 0, 0.0f, 0.0f);
            }
        } else if (Is_0018CA10(*(int*)(widget + 0x38), D_004A1570)) {
            func_00147528(iface, 1, func_0039A738(widget) != 0);
            if (func_001474E8(iface, 1)) {
                func_0018D108(self, 1, 10.0f, 10.0f);
                *(int*)(self + 0x4C) = 0x3C;
                *(unsigned char*)(self + 0x50) |= 2;
            } else {
                func_0018D108(self, 1, 0.0f, 0.0f);
            }
        } else if (Is_0018CA10(*(int*)(widget + 0x38), D_004A15C8)) {
            func_00147658(iface, 0, func_0039A738(widget));
            func_0018CF50(self, func_0039A738(widget) == 0);
        } else if (Is_0018CA10(*(int*)(widget + 0x38), D_004A1578)) {
            func_00147658(iface, 1, func_0039A738(widget));
            func_0018CF50(self, func_0039A738(widget) == 0);
        }
        D_004A14DC = 1;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018CCE0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00147618(void* player, int which);
// func_0018CF50 returns void; declaring it int ($v0 set by the call) reproduces the original argument scheduling.
extern "C" int func_0018CF50_CCE0(void* self, int on) __asm__("func_0018CF50");

// Options toggle row: accept flips the setting chosen by the cursor (items 2 and 3), back is consumed.
extern "C" int func_0018CCE0(void* self, char* menu, unsigned int key)
{
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    switch (key) {
    case 9:
        return 0x100;
    case 5: {
        int which;
        switch (*(unsigned char*)(menu + 0x95)) {
        case 2:
            which = 0;
            break;
        case 3:
            which = 1;
            break;
        default:
            return 0x101;
        }
        func_0018CF50_CCE0(self, func_00147618(player, which) == 0);
        return 0x101;
    }
    case 6:
        return 0;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018CDB0);
#ifdef SKIP_ASM
extern "C" int func_0018CDB0(void* self, int a1, int a2)
{
    return a2 ? 0x100 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018CDC0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_001474E8(void* iface, int a1);
extern "C" int func_00147618(void* iface, int a1);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern "C" void func_0018CF50(void* self, int on);
extern char D_004A1568[];
extern char D_004A1570[];
extern char D_004A15C8[];
extern char D_004A1578[];

extern "C" void func_0018CDC0(void* self)
{
    void* np = cBE_getInterface_Fv(cBE_getBE(), 1);
    unsigned char vals[4];
    void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1568));
    if (o != 0) {
        func_0039A768(o, func_001474E8(np, 0), &vals[0]);
        func_0039A7A8(o, vals[0]);
    }
    o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1570));
    if (o != 0) {
        func_0039A768(o, func_001474E8(np, 1), &vals[1]);
        func_0039A7A8(o, vals[1]);
    }
    o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15C8));
    if (o != 0) {
        func_0039A768(o, func_00147618(np, 0), &vals[2]);
        func_0039A7A8(o, vals[2]);
        func_0018CF50(self, func_00147618(np, 0) == 0);
    }
    o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1578));
    if (o != 0) {
        func_0039A768(o, func_00147618(np, 1), &vals[3]);
        func_0039A7A8(o, vals[3]);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018CF50);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char* D_004A15BC;
extern char* D_004A15C0;
extern char D_0045E0A0[];
extern char D_0045E0B0[];

class cUIObj_18CF50 {
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

extern "C" void func_0018CF50(void* self, int on)
{
    cUIObj_18CF50* a = (cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15BC));
    if (a != 0) {
        a->setVisible(on);
    }
    cUIObj_18CF50* b = (cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15C0));
    if (b != 0) {
        b->setVisible(on ^ 1);
    }
    cUIObj_18CF50* c = (cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E0A0));
    if (c != 0) {
        c->setVisible(on);
    }
    cUIObj_18CF50* d = (cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E0B0));
    if (d != 0) {
        d->setVisible(on ^ 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018D058);
#ifdef SKIP_ASM
extern "C" void* func_0039E510(void* self);
extern "C" void func_0018D108(void* self, int idx, float x, float y);

extern "C" void func_0018D058(void* self)
{
    func_0039E510(self);
    if (*(unsigned char*)((char*)self + 0x50) & 1) {
        if (*(int*)((char*)self + 0x48) > 0) {
            *(int*)((char*)self + 0x48) -= 1;
        } else {
            *(int*)((char*)self + 0x48) = 0;
            *(unsigned char*)((char*)self + 0x50) &= ~1;
            func_0018D108(self, 0, 0.0f, 0.0f);
        }
    }
    if (*(unsigned char*)((char*)self + 0x50) & 2) {
        if (*(int*)((char*)self + 0x4C) > 0) {
            *(int*)((char*)self + 0x4C) -= 1;
        } else {
            *(int*)((char*)self + 0x4C) = 0;
            *(unsigned char*)((char*)self + 0x50) &= ~2;
            func_0018D108(self, 1, 0.0f, 0.0f);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018D108);
#ifdef SKIP_ASM
extern char* D_004A28A0;

class cSnd_18D108 {
public:
    virtual void v01();
    virtual void v02();
    virtual int getState();
    virtual void setVolume(int ch, float v);
};

// PORT: uses g++'s >? (max) operator.
extern "C" void func_0018D108(void* self, int idx, float x, float y)
{
    signed char i = idx;
    float t = x * 0.9133333563804626f - 18.518518447875977f;
    float a = 0.0f;
    if (t >= 0.0f) {
        a = t;
    }
    y = y * 0.9916666746139526f;
    cSnd_18D108* s = 0;
    if (D_004A28A0 != 0) {
        s = *(cSnd_18D108**)(D_004A28A0 + (i << 2) + 0x2EEC);
    }
    if (s->getState() == 2) {
        s->setVolume(0, ((y - 0.5f) * 0.009999999776482582f >? (a - 2.0f) / 972.2222290039062f) >? 0.0f);
        s->setVolume(1, ((y - 70.0f) * 0.0062500000931322575f >? (a - 100.0f) / 5000.0f) >? 0.0f);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018D240);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern void* D_0046C3B0[];

extern "C" void* func_0018D240(void* self)
{
    func_0039E2A0(self);
    *(int*)((char*)self + 0xC) = 0x20;
    *(void***)((char*)self + 0x8) = D_0046C3B0;
    *(char*)((char*)self + 0x48) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", cFEStateOptionsSaveLoad_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0045E0C0[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cFEStateOptionsSaveLoad_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045E0C0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", cFEStateOptionsSaveLoad_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0045E0D0[];
extern char D_0045E0E0[];
extern char D_0045E0F0[];
extern char D_0045E100[];
extern char D_004A1508[];
extern char D_004A1500[];

static inline int IsHash_D2E8(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void cFEStateOptionsSaveLoad_onWidgetCreate(void* self, void* widget)
{
    if (IsHash_D2E8(*(int*)((char*)widget + 0x38), D_0045E0D0)) {
        *(int*)((char*)widget + 0x18) = 0;
    } else if (IsHash_D2E8(*(int*)((char*)widget + 0x38), D_0045E0E0)) {
        *(int*)((char*)widget + 0x18) = 2;
    } else if (IsHash_D2E8(*(int*)((char*)widget + 0x38), D_0045E0F0)) {
        *(int*)((char*)widget + 0x18) = 1;
    } else if (IsHash_D2E8(*(int*)((char*)widget + 0x38), D_0045E100)) {
        *(int*)((char*)widget + 0x18) = 3;
    } else if (IsHash_D2E8(*(int*)((char*)widget + 0x38), D_004A1508)) {
        *(int*)((char*)widget + 0x18) = 0x300;
    } else if (IsHash_D2E8(*(int*)((char*)widget + 0x38), D_004A1500)) {
        *(int*)((char*)widget + 0x18) = 0x200;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018D3C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_00194498(void* obj);
extern int D_004A19D8;
extern char D_0045E0F0[];
extern char D_0045E100[];

extern "C" void func_0018D3C0(void* self)
{
    if (D_004A19D8 != 0) {
        void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E0F0));
        if (obj != 0) {
            func_00194498(obj);
        }
        obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E100));
        if (obj != 0) {
            func_00194498(obj);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018D438);
#ifdef SKIP_ASM
// Key filter: keys 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_0018D438(void* self, int a1, unsigned int key)
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
INCLUDE_ASM("fe/festateoptions", func_0018D460);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0039F190(void* list, int a1);
extern "C" void func_0039F400(void* list, void* item);
extern "C" void func_00147138(void* self, int a1, const char* name);
extern "C" void func_0014DE28(void* self, int c);
extern "C" void* func_001A0548(void* self, int a1);
extern "C" void func_0019EBA0(void* self);
extern "C" int cFERider_init(void* self, int a1, int a2, int a3);
struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern void* D_004A28A8;
extern char D_004A1408[];
extern char D_0045DC60[];

struct sVE_18D460n {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE_18D460p {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

extern "C" void func_0018D460(char* self, char* widget, unsigned int event)
{
    switch (event) {
    case 0xF:
        *(int*)(widget + 0x18) = 1;
        func_0039F190(*(char**)(self + 0x10) + 0x18, 1);
        break;
    case 0x10:
        *(int*)(widget + 0x18) = 0;
        func_0039F190(*(char**)(self + 0x10) + 0x18, 1);
        break;
    case 0x15:
        break;
    case 0x16: {
        if (*(int*)(widget + 0x18) == 0) {
            break;
        }
        int sel = *(signed char*)(self + 0x44);
        if (sel < 0) {
            sel = 0;
        }
        char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
        func_00147138(iface, sel, D_004A1408);
        sVE_18D460n* vt = *(sVE_18D460n**)(iface + 0xC);
        vt[1].fn(iface + vt[1].delta);
        func_0014DE28(cBE_getBE(), sel);
        void* r = func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, 0);
        func_0019EBA0(r);
        cFERider_init(r, 0, 4, 0);
        r = func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, 1);
        func_0019EBA0(r);
        cFERider_init(r, 1, 0, 0);
        char* obj = **(char***)(self + 0x10);
        sVE_18D460p* vt2 = *(sVE_18D460p**)(obj + 4);
        void* x = vt2[4].fn(obj + vt2[4].delta, self, (1 << *(signed char*)(self + 0x48)) | 0x100);
        if (x != 0) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, x);
        }
        int f = cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_0045DC60));
        if (f != 0xFFFF) {
            cUIScreen_playFrame(*(void**)(self + 0x40), f, 1);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", cFEStateOptionsSaveLoad_onWidgetEvent);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc bound as operator new so gcc treats it as malloc-like.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern "C" void* func_001D99C8(void* self, void* engine, void* owner, unsigned short* text, int a4, int a5, int a6, int a7, int a8);
extern void* D_004A28A8;
extern char D_0045E110[];
extern char D_0045E130[];

struct sVE_18D648s {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

struct sVE_18D648p {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sVE_18D648v {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void cFEStateOptionsSaveLoad_onWidgetEvent(char* self, char* widget, int event)
{
    if (widget == 0) {
        return;
    }
    switch (event) {
    case 5: {
        unsigned int v = *(unsigned int*)(widget + 0x18);
        *(int*)(widget + 0x18) = 3;
        if (v == 3) {
            *(signed char*)(self + 0x48) = *(signed char*)(self + 0x14);
            char* mgr = *(char**)((char*)D_004A28A8 + 0x8C);
            sVE_18D648s* vt = *(sVE_18D648s**)(mgr + 4);
            unsigned short* text = vt[4].fn(mgr + vt[4].delta, GetHashValue32(D_0045E110));
            char* p = (char*)operator new(0xBFC, D_0045E130, 0x100, 0);
            char* o = (char*)func_001D99C8(p, *(void**)(self + 0x10), self, text, 0, 0, 0, 0, 0);
            sVE_18D648v* vt2 = *(sVE_18D648v**)(o + 8);
            vt2[25].fn(o + vt2[25].delta, 1);
            *(int*)(o + 0x18) = 0;
            func_0039F290(*(char**)(self + 0x10) + 0x18, o);
        } else {
            if (v > 3) {
                v |= 1 << *(signed char*)(self + 0x14);
            }
            char* obj = **(char***)(self + 0x10);
            sVE_18D648p* vt = *(sVE_18D648p**)(obj + 4);
            void* r = vt[4].fn(obj + vt[4].delta, self, v);
            if (r != 0) {
                func_0039F400(*(char**)(self + 0x10) + 0x18, r);
            }
        }
        break;
    }
    case 6: {
        char* obj = **(char***)(self + 0x10);
        sVE_18D648p* vt = *(sVE_18D648p**)(obj + 4);
        void* r = vt[5].fn(obj + vt[5].delta, self, *(int*)(widget + 0x18));
        if (r != 0) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018D7F0);
#ifdef SKIP_ASM
extern "C" void* func_001D53B0(void* self, int a1, int a2);
extern "C" void* func_00227F80(void* app);
extern void* D_0046C228[];
extern void* D_004A28A8;

extern "C" void* func_0018D7F0(void* self, int a1, int a2, int a3, int a4)
{
    func_001D53B0(self, a1, a2);
    *(int*)((char*)self + 0x230) = a4;
    *(void***)((char*)self + 8) = D_0046C228;
    *(int*)((char*)self + 0xC) = 0x21;
    *(int*)((char*)self + 0x22C) = a3;
    *(int*)((char*)self + 0x234) = 0;
    *(int*)((char*)self + 0x238) = 0;
    if (a3 == 0) {
        *(int*)((char*)func_00227F80(D_004A28A8) + 0x11C) = 0;
    }
    return self;
}
#endif

INCLUDE_ASM("fe/festateoptions", cFEStateOptionsDeviceSelect_onCreateScreen);

//100%
INCLUDE_ASM("fe/festateoptions", func_0018DDD0);
#ifdef SKIP_ASM
struct cList0018DDD0 {
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual int v54(int a);
};
extern "C" void* func_00227F80(void* app);
extern void* D_004A28A8;

extern "C" int func_0018DDD0(void* self, void* widget, unsigned int msg)
{
    char* app = (char*)func_00227F80(D_004A28A8);
    switch (msg) {
    case 8:
        if (*(int*)((char*)self + 0x22C) != 0 && (*(cList0018DDD0**)(app + 0x434))->v54(*(int*)(app + 0x428)) != 0) {
            return 0x101;
        }
    case 6:
        if ((*(cList0018DDD0**)(app + 0x434))->v54(*(int*)(app + 0x428)) == 0) {
            return 0x100;
        }
        break;
    case 9:
        return 0x100;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018DEA0);
#ifdef SKIP_ASM
extern "C" void* func_00227F80(void* app);
extern "C" void func_0023CAE8(void* app, int a1, int a2);
extern "C" void func_0023C8F0(void* app, int a1);
extern "C" void func_0023D570(void* app, int a1);
extern void* D_004A28A8;

struct sVE_18DEA0n {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE_18DEA0i {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sVE_18DEA0v {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sDevSel_18DEA0 {
    char pad0[8];
    sVE_18DEA0n* vt;        // 0x8
    char padC[0x1A8 - 0xC];
    int busy;               // 0x1A8
    char pad1AC[0x1BC - 0x1AC];
    int mode;               // 0x1BC
    int state;              // 0x1C0
    int slot;               // 0x1C4
    char pad1C8[0x1DC - 0x1C8];
    int f1DC;               // 0x1DC
    int pad1E0;
    int f1E4;               // 0x1E4
    char pad1E8[0x214 - 0x1E8];
    int f214;               // 0x214
    char pad218[0x224 - 0x218];
    int f224;               // 0x224
    int pad228;
    int f22C;               // 0x22C
    char pad230[0x238 - 0x230];
    int f238;               // 0x238
};

class cDev_18DEA0 {
public:
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual int v54(int a);
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual int v67(int a);
};

extern "C" void func_0018DEA0(sDevSel_18DEA0* self, char* widget, unsigned int event)
{
    char* app = (char*)func_00227F80(D_004A28A8);
    switch (event) {
    case 5: {
        if (widget == 0)
            return;
        if (self->busy != 0)
            return;
        self->f238 = 1;
        int st = self->f214;
        if (st != 3)
            return;
        if (self->f224 == 0)
            return;
        int v = *(int*)(widget + 0x18);
        self->slot = v;
        *(int*)(app + 0xF8) = v;
        if (self->mode == 2 && self->f22C != 0) {
            func_0023CAE8(app, 2, -1);
            self->f1DC = 1;
            self->busy = 1;
            self->state = st;
            self->vt[47].fn((char*)self + self->vt[47].delta);
        } else if (self->mode == 1) {
            if ((*(cDev_18DEA0**)(app + 0x434))->v67(self->slot)) {
                func_0023C8F0(app, 0);
                self->vt[44].fn((char*)self + self->vt[44].delta);
            } else {
                self->vt[47].fn((char*)self + self->vt[47].delta);
            }
        } else {
            if ((*(cDev_18DEA0**)(app + 0x434))->v67(self->slot)) {
                func_0023C8F0(app, 2);
                self->vt[44].fn((char*)self + self->vt[44].delta);
            } else {
                self->vt[47].fn((char*)self + self->vt[47].delta);
            }
        }
        break;
    }
    case 6: {
        self->f238 = 0;
        char* a = (char*)func_00227F80(D_004A28A8);
        if (self->busy == 1)
            return;
        int s = self->state;
        if (s == 6)
            return;
        self->f1E4 = 1;
        if (s == 0 || s == 2 || s == 1) {
            sVE_18DEA0v* vt = *(sVE_18DEA0v**)(a + 0x748);
            vt[1].fn(a + vt[1].delta, 0);
        }
        self->state = 6;
        break;
    }
    case 7: {
        if (self->busy == 1)
            return;
        if (self->state == 6)
            return;
        if (self->f22C == 0)
            return;
        char* a = (char*)func_00227F80(D_004A28A8);
        if ((*(cDev_18DEA0**)(a + 0x434))->v54(*(int*)(a + 0x428)) == 0)
            return;
        int v = *(int*)(widget + 0x18);
        self->slot = v;
        *(int*)(a + 0xF8) = v;
        int s = self->state;
        if (s != 1)
            return;
        if ((*(cDev_18DEA0**)(a + 0x434))->v67(self->slot)) {
            self->busy = s;
            self->state = 4;
            func_0023D570(a, 0);
            sVE_18DEA0v* vt = *(sVE_18DEA0v**)(a + 0x748);
            vt[1].fn(a + vt[1].delta, 0x18);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018E178);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A15E0[];
extern char D_004A15D0[];
extern char D_004A15D8[];
extern char D_004A1458[];
extern char D_004A1460[];

extern "C" void func_0018E178(void* self, int on)
{
    if (*(int*)((char*)self + 0x234) == on)
        return;
    int off = on ^ 1;
    ((cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15E0)))->setVisible(off);
    if (*(int*)((char*)self + 0x22C) != 0) {
        ((cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D0)))->setVisible(off);
        ((cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1458)))->setVisible(off);
        ((cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1460)))->setVisible(off);
    } else {
        ((cUIObj_18CF50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D8)))->setVisible(off);
    }
    *(int*)((char*)self + 0x234) = on;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018E2C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A1458[];
extern char D_004A1460[];
struct cUIObj_E2C0 {
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setActive(int on);
};

extern "C" void func_0018E2C0(void* self, bool on)
{
    if (*(int*)((char*)self + 0x22C) != 0) {
        int off = !on;
        ((cUIObj_E2C0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1458)))->setActive(off);
        ((cUIObj_E2C0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1460)))->setActive(off);
    }
    *(int*)((char*)self + 0x220) = !on;
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018E368);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A15D0[];
extern char D_004A15D8[];
extern char D_004A15E0[];

struct cUIObj_E368 {
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int on);
};

extern "C" void func_0018E368(void* self, bool a, bool b)
{
    cUIObj_E368* o = (cUIObj_E368*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15E0));
    if (*(int*)((char*)self + 0x22C) != 0) {
        int v = !b;
        ((cUIObj_E368*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D0)))->setVisible(v);
        *(int*)((char*)self + 0x224) = v;
        o->setVisible(v);
    } else {
        int v = !a;
        ((cUIObj_E368*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D8)))->setVisible(v);
        *(int*)((char*)self + 0x224) = v;
        o->setVisible(v);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateoptions", func_0018E478);
#ifdef SKIP_ASM
extern "C" void func_0039F4C0(void* list, void* item);

struct sVEntry0018E478 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

extern "C" void func_0018E478(void* self)
{
    if (*(int*)((char*)self + 0x1AC) == 0) {
        int mode = *(int*)((char*)self + 0x1BC) == 1;
        if (*(int*)((char*)self + 0x1E4) == 1) {
            mode = 0;
        }
        if (*(int*)((char*)self + 0x1B4) == 0) {
            mode = 0;
        }
        if (*(int*)((char*)self + 0x230) != 0) {
            mode = 2;
        }
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry0018E478* vt = *(sVEntry0018E478**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, mode);
        if (r != 0) {
            func_0039F4C0(*(char**)((char*)self + 0x10) + 0x18, r);
        }
    }
    *(int*)((char*)self + 0x1AC) = 1;
}
#endif

INCLUDE_ASM("fe/festateoptions", func_0018E510);

