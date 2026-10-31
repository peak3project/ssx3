#include "common.h"

INCLUDE_ASM("fe/festateaudiooptions", cFEStateAudioOptions_onWidgetCreate);

//100%
INCLUDE_ASM("fe/festateaudiooptions", cFEStateAudioOptions_onWidgetEvent);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" void func_001587F8(void* iface, int player, int a2, int a3);
extern "C" void* func_0028B180();
extern "C" void func_0028BF78(void* audio, int a1);
extern "C" void* func_00196B90(void* p, int a1, signed char idx, int a3);
extern "C" void cUIStateStack_pushSpecial(void* stack, void* state, int a2, int a3);
extern "C" void* func_0039F190(void* stack, int a1);
extern "C" void func_0039F400(void* stack, void* state);
extern void* D_004A28A8;
extern char D_00460470[];
extern char D_00460488[];
extern char D_00460498[];
extern char D_004604B0[];
extern char D_004604C0[];
extern char D_004604E0[];
extern char D_004604F8[];
extern char D_00460510[];
extern char D_00460528[];
extern char D_00460540[];

struct sVE_AOWE {
    short delta;
    short index;
    void* (*fn)(void*, ...);
};

struct sOption_AOWE {
    char pad_0x0[0x78];
    int state;                      // 0x78
    int color;                      // 0x7C
};

struct sToggle_AOWE {
    char pad_0x0[0x8];
    sVE_AOWE* vt;                   // 0x8
};

struct sAudioOptions_AOWE {
    char pad_0x0[0x10];
    char* owner;                    // 0x10
    char pad_0x14[0x2C];
    void* screen;                   // 0x40
    signed char player;             // 0x44
    char pad_0x45[0x7];
    sOption_AOWE* options[4];       // 0x4C
    int selColor;                   // 0x5C
    int normColor;                  // 0x60
    sToggle_AOWE* toggles[3];       // 0x64
    int f70;                        // 0x70
    int f74;                        // 0x74
    int sel;                        // 0x78
    int f7C;                        // 0x7C
};

struct sWidget_AOWE {
    char pad_0x0[0x18];
    int idx;                        // 0x18
};

static inline int online_AOWE()
{
    return *(int*)((char*)D_004A28A8 + 0x84);
}

static inline void setOption_AOWE(sOption_AOWE* o, int state, int color)
{
    o->state = state;
    o->color = color;
}

static inline void setText_AOWE(cUIText* t, char* str)
{
    cUIText_setUnicodeStringByID(t, GetHashValue32(str));
}

static inline void applyMode_AOWE(sAudioOptions_AOWE* self)
{
    func_001587F8(cBE_getInterface_Fv(cBE_getBE(), 0xD), self->player, self->f70, self->sel);
    func_0028BF78(func_0028B180(), self->sel);
}

static inline void* vcall_AOWE(sAudioOptions_AOWE* self, int slot, sWidget_AOWE* w)
{
    char* o = *(char**)self->owner;
    sVE_AOWE* vt = *(sVE_AOWE**)(o + 4);
    return vt[slot].fn(o + vt[slot].delta, self, w->idx);
}

static inline void setEnabled_AOWE(sToggle_AOWE* t, int on)
{
    ((void (*)(void*, int))t->vt[6].fn)((char*)t + t->vt[6].delta, on);
}

extern "C" void cFEStateAudioOptions_onWidgetEvent(sAudioOptions_AOWE* self, sWidget_AOWE* w, unsigned int event)
{
    if (w == 0)
        return;
    switch (event) {
    case 5: {
        int idx = w->idx;
        if (idx != 0 && idx != 2) {
            if (idx != 1 && idx != 3)
                goto other;
            if (self->f7C == 0)
                return;
        }
        setOption_AOWE(self->options[self->sel], -1, self->normColor);
        self->sel = w->idx;
        setOption_AOWE(self->options[self->sel], -1, self->selColor);
        applyMode_AOWE(self);
        break;
    other:
        if (idx != 4)
            return;
        if (self->f74 == 0 && self->f7C == 0)
            return;
        char* popup = (char*)func_00196B90(cMemMan_alloc(0x210, D_00460470, 0, 0), (int)self->owner, self->player, self->f74);
        if (online_AOWE()) {
            *(int*)(popup + 0x1C) = (*(int*)(popup + 0x1C) & ~0x3F00) | 0x100;
            cUIStateStack_pushSpecial(self->owner + 0x18, popup, 0, 0);
        } else {
            func_0039F400(self->owner + 0x18, popup);
        }
        break;
    }
    case 6:
        applyMode_AOWE(self);
        if (online_AOWE()) {
            func_0039F190(self->owner + 0x18, 1);
        } else {
            void* r = vcall_AOWE(self, 5, w);
            if (r != 0)
                func_0039F400(self->owner + 0x18, r);
        }
        break;
    case 1: {
        cUIText* text = cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00460488));
        if (text == 0)
            return;
        bool a = false;
        bool c = false;
        bool b = false;
        switch (w->idx) {
        case 0:
            setText_AOWE(text, D_00460498);
            break;
        case 2:
            setText_AOWE(text, D_004604B0);
            break;
        case 1:
            if (self->f7C == 0) {
                b = online_AOWE();
                if (online_AOWE())
                    setText_AOWE(text, D_004604C0);
                else if (self->f74 == 0)
                    setText_AOWE(text, D_004604F8);
                else
                    setText_AOWE(text, D_004604E0);
            } else
                setText_AOWE(text, D_00460510);
            break;
        case 3:
            if (self->f7C == 0) {
                c = online_AOWE();
                if (online_AOWE())
                    setText_AOWE(text, D_004604C0);
                else if (self->f74 == 0)
                    setText_AOWE(text, D_004604F8);
                else
                    setText_AOWE(text, D_004604E0);
            } else
                setText_AOWE(text, D_00460528);
            break;
        case 4:
            if (self->f74 == 0 && self->f7C == 0) {
                a = online_AOWE();
                if (online_AOWE())
                    setText_AOWE(text, D_004604C0);
                else
                    setText_AOWE(text, D_004604F8);
            } else
                setText_AOWE(text, D_00460540);
            break;
        }
        if (online_AOWE()) {
            setEnabled_AOWE(self->toggles[0], a);
            setEnabled_AOWE(self->toggles[1], b);
            setEnabled_AOWE(self->toggles[2], c);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateaudiooptions", func_00196B08);
#ifdef SKIP_ASM
extern "C" int func_00196B08(void* self, int a1, int a2, int a3)
{
    if (a2 == 6 && (a3 == 2 || a3 == 3 || a3 == 4)) {
        if (a3 == 2 && *(int*)((char*)self + 0x7C) == 0) {
            goto ok;
        }
        if (a3 == 3 && *(int*)((char*)self + 0x7C) == 0) {
            goto ok;
        }
        if (a3 == 4 && *(int*)((char*)self + 0x74) == 0 && *(int*)((char*)self + 0x7C) == 0) {
        ok:
            return 0x10;
        }
    } else if (a2 == 8 || a2 == 9) {
        return 0;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festateaudiooptions", func_00196B90);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void *, int);
extern "C" unsigned char func_001A1CD0(void* self, signed char a1);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
int GetHashValue32(char* str);
extern "C" void* func_003E6448(void* p, int c, int n);
extern "C" int func_00398380(void* list, int hash);
extern "C" int func_00150928(void* iface, int idx, int ch);
// PORT: 64-bit results (long is 8 bytes on the EE).
extern "C" long func_00158728(void* iface, int idx, int ch);
extern "C" long func_00158750(void* iface, int idx, int ch);
extern "C" void* func_0028B180();
extern "C" void func_00197AD8(void* self);
extern void* D_00469378[];
extern char D_0045DA48[];
extern char D_0045DA38[];
extern char D_0045DA58[];

struct sAudioState_196B90
{
    char pad0[0x4C];
    char buf[0x100];        // 0x4C
    int f14C;               // 0x14C
    int f150;               // 0x150
    char pad154[4];
    long f158;              // 0x158
    long f160;              // 0x160
    int f168;               // 0x168
    int f16C;               // 0x16C
    int f170;               // 0x170
    int a174[8];            // 0x174
    int a194[8];            // 0x194
    int f1B4;               // 0x1B4
    int f1B8;               // 0x1B8
    int a1BC[6];            // 0x1BC
    int f1D4;               // 0x1D4
    int f1D8;               // 0x1D8
    int f1DC;               // 0x1DC
    int f1E0;               // 0x1E0
    int f1E4;
    int f1E8;
    int f1EC;
    int f1F0;
    int f1F4;
    int f1F8;
    int f1FC;
    int f200;
    int f204;               // 0x204
    int f208;               // 0x208
    int f20C;               // 0x20C
};

static inline int Find_196B90(char* mgr, int hash)
{
    return func_00398380(mgr + 0x58, hash);
}

extern "C" void* func_00196B90(void* p, int a1, signed char idx, int a3)
{
    sAudioState_196B90* self = (sAudioState_196B90*)p;
    func_0039E2A0(self, a1);
    *(int*)((char*)self + 0xC) = 0x11;
    *(void***)((char*)self + 0x8) = D_00469378;
    *(signed char*)((char*)self + 0x44) = idx;
    if (**(void***)((char*)self + 0x10) != 0)
        *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), idx);
    func_003E6448(self->buf, 0, 0x100);
    self->f14C = 0;
    self->f150 = 0;
    self->f170 = 0;
    for (int i = 0; i < 8; i++)
    {
        self->a174[i] = 0;
        self->a194[i] = 0;
    }
    self->f1B4 = 0;
    self->f1B8 = 0;
    for (int i = 5; i >= 0; i--)
        self->a1BC[i] = 0;
    self->f16C = a3;
    self->f1D4 = 0;
    self->f1DC = 0;
    self->f1D8 = 0;
    self->f1E0 = 0;
    self->f1E4 = 0;
    self->f1E8 = 0;
    self->f1EC = 0;
    self->f1F0 = 0;
    self->f1F4 = 0;
    self->f1F8 = 0;
    self->f1FC = 0;
    self->f200 = 0;
    self->f158 = 0;
    {
        char* mgr = *(char**)((char*)self + 0x10);
        self->f204 = Find_196B90(mgr, GetHashValue32(D_0045DA48));
    }
    {
        char* mgr = *(char**)((char*)self + 0x10);
        self->f208 = Find_196B90(mgr, GetHashValue32(D_0045DA38));
    }
    {
        char* mgr = *(char**)((char*)self + 0x10);
        self->f20C = Find_196B90(mgr, GetHashValue32(D_0045DA58));
    }
    *(int*)((char*)self + 0x48) = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)((char*)self + 0x44));
    self->f168 = func_00150928(cBE_getInterface_Fv(cBE_getBE(), 0xB), *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0x48));
    void* ifc = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    self->f160 = func_00158728(ifc, *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0x48));
    self->f158 = func_00158750(ifc, *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0x48));
    self->f14C = *(int*)((char*)func_0028B180() + 0x504);
    func_00197AD8(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateaudiooptions", func_00196DB0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0039B760(void* self, int a1);
extern "C" void* func_0039F9D8(void* self, int id);
extern void* D_004A28A8;
extern char D_004A18A8[];
extern char D_004A18B0[];
extern char D_00460578[];

struct sVEntry00196DB0 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" void func_00196DB0(void* self)
{
    char* name = D_004A18B0;
    if (*(void**)((char*)D_004A28A8 + 0x84) != 0) {
        name = D_00460578;
        void* list = *(char**)((char*)self + 0x10) + 0x18;
        char* obj = (char*)func_0039F9D8(list, GetHashValue32(D_004A18A8));
        if (obj != 0) {
            sVEntry00196DB0* vt = *(sVEntry00196DB0**)(obj + 8);
            vt[24].fn(obj + vt[24].delta, 3, 0);
        }
    }
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(name), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0039B760(*(void**)((char*)self + 0x170), *(unsigned char*)((char*)self + 0x14C));
}
#endif

//100%
INCLUDE_ASM("fe/festateaudiooptions", func_00196E80);
#ifdef SKIP_ASM
struct sVEntry00196E80 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

int GetHashValue32(char* str);
void func_0039E4A0(void* self);
extern "C" void* func_0039F9D8(void* self, int id);
extern char D_004A18A8[];
extern void* D_004A28A8;

extern "C" void func_00196E80(void* self)
{
    if (*(int*)((char*)D_004A28A8 + 0x84) != 0) {
        void* obj = func_0039F9D8(*(char**)((char*)self + 0x10) + 0x18, GetHashValue32(D_004A18A8));
        if (obj != 0) {
            sVEntry00196E80* e = &(*(sVEntry00196E80**)((char*)obj + 8))[24];
            e->fn((char*)obj + e->delta, 4, 0);
        }
    }
    func_0039E4A0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateaudiooptions", func_00196F00);
#ifdef SKIP_ASM
extern "C" void func_00186518(void* self, void* a1);
extern "C" void func_00197B88(void* self);
extern "C" void func_00197E70(void* self);
extern "C" void cFEStateRequestLine_updateButtonsText(void* self, int a1);
extern "C" void cFEStateRequestLine_updateHelpText(void* self, int a1);

extern "C" void func_00196F00(void* self, void* a1)
{
    func_00186518(self, a1);
    *(int*)((char*)self + 0x150) = 0;
    func_00197B88(self);
    func_00197E70(self);
    cFEStateRequestLine_updateButtonsText(self, 0);
    cFEStateRequestLine_updateHelpText(self, 0);
}
#endif

//100%
INCLUDE_ASM("fe/festateaudiooptions", func_00196F50);
#ifdef SKIP_ASM
extern "C" void func_00197DB8(void* self);
extern "C" void cFEStateRequestLine_updateButtonsText(void* self, int a1);
extern "C" void cFEStateRequestLine_updateHelpText(void* self, int a1);

extern "C" int func_00196F50(void* self, int a1)
{
    if (a1 != 0) {
        func_00197DB8(self);
        cFEStateRequestLine_updateButtonsText(self, 0);
        cFEStateRequestLine_updateHelpText(self, 0);
    }
    return 0;
}
#endif

