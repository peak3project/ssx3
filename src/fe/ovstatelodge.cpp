#include "common.h"

//100%
INCLUDE_ASM("fe/ovstatelodge", cFEStateMountainRoom_cFEStateMountainRoom);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0_3(void* self, void* a1, int a2) __asm__("func_0039E2A0");
extern "C" unsigned char func_001A1CD0(void* self, int a1);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" int cBENewPlayerInterface_isPeakLocked(void* self, int a, int b, int peak);
int cBELibrary_getRiderIndex(int rider) __asm__("cBELibrary_getRiderIndex__Fi");
extern "C" int func_00148950(void* iface, int rider);
extern "C" char* func_00156B28(void* self, int a1, int a2);
extern "C" int func_00398380(void* self, int id);
extern "C" void func_001D3160(void* self);
int GetHashValue32(char* str);
extern void* D_00469858[];
extern char D_00467208[];
extern char D_00467218[];

struct sMountainRoomK2678 {
    char pad_0x00[0x44];
    signed char player;      // 0x44
    char pad_0x45[0x3];
    int f48;
    int f4C;
    int f50;
    int f54;
    int a[5];                // 0x58
    int b[5][3];             // 0x6C
    int fA8;
    int fAC;
    int charID;              // 0xB0
    int fB4;
    int fB8;
    int fBC;
    char* fC0;
    int fC4;
};

extern "C" void* cFEStateMountainRoom_cFEStateMountainRoom(void* self, void* ui, int idx)
{
    signed char pl = idx;
    func_0039E2A0_3(self, ui, idx);
    *(int*)((char*)self + 0xC) = 0x2B;
    *(void***)((char*)self + 0x8) = D_00469858;
    sMountainRoomK2678* s = (sMountainRoomK2678*)self;
    s->player = pl;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), pl);
    s->f48 = 0;
    s->f50 = 0;
    s->f54 = 0;
    for (int i = 4; i >= 0; i--) {
        s->a[i] = 0;
    }
    int* r1 = s->b[1];
    int* r2 = s->b[2];
    int* r3 = s->b[3];
    int* r4 = s->b[4];
    for (int i = 2; i >= 0; i--) {
        s->b[0][i] = 0;
    }
    for (int i = 2; i >= 0; i--) {
        r1[i] = 0;
    }
    for (int i = 2; i >= 0; i--) {
        r2[i] = 0;
    }
    for (int i = 2; i >= 0; i--) {
        r3[i] = 0;
    }
    for (int i = 2; i >= 0; i--) {
        r4[i] = 0;
    }
    s->fA8 = 0;
    s->fAC = 0;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    s->charID = cBENewPlayerInterface_getPlayerCharID(iface, s->player);
    for (int i = 0; i < 3; i++) {
        if (cBENewPlayerInterface_isPeakLocked(iface, s->player, s->charID, i) == 0) {
            s->fB4 = i;
        }
    }
    void* iface3 = cBE_getInterface_Fv(cBE_getBE(), 3);
    s->fB8 = func_00148950(iface3, cBELibrary_getRiderIndex(s->player));
    void* iface13 = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    char* item = func_00156B28(iface13, s->fB4, s->charID);
    s->fBC = -1;
    s->fC4 = -1;
    s->fC0 = item;
    s->fAC = func_00398380((char*)ui + 0x58, GetHashValue32(D_00467208));
    s->fA8 = func_00398380((char*)ui + 0x58, GetHashValue32(D_00467218));
    func_001D3160(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D28F8);
#ifdef SKIP_ASM
struct sVEntry001D28F8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern void* D_00469858[];
extern void* D_0046D0D0[];
extern void* D_004A289C;
extern void* D_004A28A8;
extern "C" void func_0019DC20(void* self, int bank, int i);
extern "C" void func_0039E390(void* self, int flags);

extern "C" void func_001D28F8(void* self, int flags)
{
    *(void***)((char*)self + 8) = D_00469858;
    int slot = *(int*)((char*)self + 0xBC);
    if (slot >= 0) {
        func_0019DC20(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70, *(int*)((char*)self + 0xB0), slot);
        *(int*)((char*)self + 0xBC) = -1;
    }
    int id = *(int*)((char*)self + 0xC4);
    if (id >= 0) {
        char* g = (char*)D_004A289C;
        sVEntry001D28F8* vt = *(sVEntry001D28F8**)(g + 0x10D8);
        vt[50].fn(g + vt[50].delta, id);
    }
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", cFEStateMountainRoom_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* self, int a1);
extern char D_00467228[];
extern char D_004A1F08[];
extern char D_004A1F10[];
extern char D_004A1F18[];
extern char D_004A14F8[];
extern char D_004A1500[];
extern char D_004A1508[];

extern "C" void cFEStateMountainRoom_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00467228), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    cUIText* a = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1F08));
    if (a != 0) {
        cUIText_setAsciiString(a, D_004A14F8);
    }
    cUIText* b = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1F10));
    if (b != 0) {
        cUIText_setAsciiString(b, D_004A1500);
    }
    cUIText* c = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1F18));
    if (c != 0) {
        cUIText_setAsciiString(c, D_004A1508);
    }
    func_0028F140(func_0028B180(), 7);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D2A90);
#ifdef SKIP_ASM
extern "C" void func_001D3340(void* self);
extern "C" void func_00186518(void* self, int a1);

extern "C" void func_001D2A90(void* self, int a1)
{
    func_001D3340(self);
    func_00186518(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", cFEStateMountainRoom_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" int func_00398380(void* self, int id);
// The array-initializer clear (memset) is a void libcall here.
extern "C" void func_00416210(void* dst, int c, int n);

struct sName5_2AD0 { char c[5]; };
extern sName5_2AD0 D_00467298[];
extern char D_00466E60[];
extern char D_00467238[];
extern char D_00467250[];
extern char D_004A1F20[];
extern char D_00467260[];
extern char D_00467270[];
extern char D_00467280[];
extern char D_004672A0[];
extern char D_004672B0[];
extern char D_004672C0[];
extern char D_004672D0[];
extern char D_004672E0[];
extern char D_004672F0[];
extern char D_00467308[];
extern char D_00467320[];
extern char D_00467338[];
extern char D_00467348[];
extern char D_00467358[];
extern char D_00467368[];
extern char D_00467380[];
extern char D_00467398[];
extern char D_004673B0[];
extern char D_004673D0[];
extern char D_004673F0[];
extern char D_00467410[];
extern char D_00467420[];
extern char D_00467430[];
extern char D_00467440[];
extern char D_004A1F28[];
extern char D_004A1F30[];
extern char D_004A1F38[];
extern char D_00460488[];

struct sWVEnt_2AD0 { short delta; short index; void (*fn)(void*, int); };

struct sWidget_2AD0 {
    char pad0[8];
    sWVEnt_2AD0* vt;    // 0x08
    char padC[0x18 - 0xC];
    int index;          // 0x18
    char pad1C[0x38 - 0x1C];
    int hash;           // 0x38
    char pad3C[0x78 - 0x3C];
    int f78;            // 0x78
    int f7C;            // 0x7C
};

static inline void wShow_2AD0(sWidget_2AD0* w, int on)
{
    w->vt[9].fn((char*)w + w->vt[9].delta, on);
}

static inline void setW_2AD0(char* s, int off, sWidget_2AD0* w)
{
    *(sWidget_2AD0**)(s + off) = w;
    wShow_2AD0(w, 0);
}

extern "C" void cFEStateMountainRoom_onWidgetCreate(void* self, sWidget_2AD0* w)
{
    char* s = (char*)self;
    int h = w->hash;
    if (h == GetHashValue32(D_00466E60)) {
        cUIText_setUnicodeStringByID((cUIText*)w, GetHashValue32(D_00467238));
        return;
    }
    if (h == GetHashValue32(D_00467250)) {
        setW_2AD0(s, 0x48, w);
        return;
    }
    if (h == GetHashValue32(D_004A1F20)) {
        setW_2AD0(s, 0x4C, w);
        return;
    }
    if (h == GetHashValue32(D_00467260)) {
        *(sWidget_2AD0**)(s + 0x50) = w;
        return;
    }
    if (h == GetHashValue32(D_00467270) || h == GetHashValue32(D_00467280)) {
        char buf[20];
        *(sName5_2AD0*)buf = D_00467298[0];
        func_00416210(buf + 5, 0, 15);
        char* eng = *(char**)(s + 0x10);
        buf[2] = *(unsigned char*)(s + 0xB8) + '0';
        int hash = GetHashValue32(buf);
        int r = func_00398380(eng + 0x58, hash);
        w->f78 = -1;
        w->f7C = r;
        return;
    }
    if (h == GetHashValue32(D_004672A0)) {
        setW_2AD0(s, 0x58, w);
        return;
    }
    if (h == GetHashValue32(D_004672B0)) {
        setW_2AD0(s, 0x5C, w);
        return;
    }
    if (h == GetHashValue32(D_004672C0)) {
        setW_2AD0(s, 0x60, w);
        return;
    }
    if (h == GetHashValue32(D_004672D0)) {
        setW_2AD0(s, 0x64, w);
        return;
    }
    if (h == GetHashValue32(D_004672E0)) {
        setW_2AD0(s, 0x68, w);
        return;
    }
    if (h == GetHashValue32(D_004672F0)) {
        setW_2AD0(s, 0x6C, w);
        return;
    }
    if (h == GetHashValue32(D_00467308)) {
        setW_2AD0(s, 0x70, w);
        return;
    }
    if (h == GetHashValue32(D_00467320)) {
        setW_2AD0(s, 0x74, w);
        return;
    }
    if (h == GetHashValue32(D_00467338)) {
        setW_2AD0(s, 0x90, w);
        return;
    }
    if (h == GetHashValue32(D_00467348)) {
        setW_2AD0(s, 0x94, w);
        return;
    }
    if (h == GetHashValue32(D_00467358)) {
        setW_2AD0(s, 0x98, w);
        return;
    }
    if (h == GetHashValue32(D_00467368)) {
        setW_2AD0(s, 0x78, w);
        return;
    }
    if (h == GetHashValue32(D_00467380)) {
        setW_2AD0(s, 0x7C, w);
        return;
    }
    if (h == GetHashValue32(D_00467398)) {
        setW_2AD0(s, 0x80, w);
        return;
    }
    if (h == GetHashValue32(D_004673B0)) {
        setW_2AD0(s, 0x84, w);
        return;
    }
    if (h == GetHashValue32(D_004673D0)) {
        setW_2AD0(s, 0x88, w);
        return;
    }
    if (h == GetHashValue32(D_004673F0)) {
        setW_2AD0(s, 0x8C, w);
        return;
    }
    if (h == GetHashValue32(D_00467410)) {
        setW_2AD0(s, 0x9C, w);
        return;
    }
    if (h == GetHashValue32(D_00467420)) {
        setW_2AD0(s, 0xA0, w);
        return;
    }
    if (h == GetHashValue32(D_00467430)) {
        setW_2AD0(s, 0xA4, w);
        return;
    }
    if (h == GetHashValue32(D_00467440)) {
        w->index = 0;
        return;
    }
    if (h == GetHashValue32(D_004A1F28)) {
        w->index = 1;
        return;
    }
    if (h == GetHashValue32(D_004A1F30)) {
        w->index = 2;
        return;
    }
    if (h == GetHashValue32(D_004A1F38)) {
        w->index = 3;
        return;
    }
    if (h == GetHashValue32(D_00460488)) {
        setW_2AD0(s, 0x54, w);
        return;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D2EA0);
#ifdef SKIP_ASM
struct sVEi1D2EA0 { short delta; short index; int (*fn)(void*); };
struct sVEv1D2EA0 { short delta; short index; void (*fn)(void*, int); };
extern char D_004A5A58;

static inline int IsShown1D2EA0(char* self)
{
    char* w = *(char**)(self + 0x48);
    return w != 0 && ((*(int*)(w + 0x14) >> 6) & 1);
}

// Lodge menu: when the detail panel is shown and the widget accepts, plays the select sound and closes the panel.
extern "C" int func_001D2EA0(char* self, char* widget)
{
    if (IsShown1D2EA0(self)) {
    sVEi1D2EA0* wvt = *(sVEi1D2EA0**)(widget + 8);
    if (wvt[6].fn(widget + wvt[6].delta)) {
        char* snd = *(char**)(*(char**)(self + 0x10) + 0x14);
        if (snd == 0) {
            snd = &D_004A5A58;
        }
        sVEv1D2EA0* svt = *(sVEv1D2EA0**)snd;
        svt[2].fn(snd + svt[2].delta, 3);
        char* w = *(char**)(self + 0x48);
        sVEv1D2EA0* vt = *(sVEv1D2EA0**)(w + 8);
        vt[9].fn(w + vt[9].delta, 0);
    }
    return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D2F40);
#ifdef SKIP_ASM
// Key filter: keys 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001D2F40(void* self, int a1, unsigned int key)
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
INCLUDE_ASM("fe/ovstatelodge", cFEStateMountainRoom_onWidgetEvent);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern "C" void func_001D32E0_MR(void* self) __asm__("func_001D32E0");
extern "C" void func_0039F400_MR(void* list, void* item) __asm__("func_0039F400");
extern char D_00467450[];
extern char D_00467460[];
extern char D_00467478[];
extern char D_00467490[];

struct sVE_MR {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sFactory_MR {
    int pad0;
    sVE_MR* vt;
};

struct sTVE_MR {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sText_MR {
    int pad[2];
    sTVE_MR* vt;
};

// Widget events of the mountain-room menu: opens sub-screens and updates the description text.
extern "C" void cFEStateMountainRoom_onWidgetEvent(char* self, char* w, unsigned int msg)
{
    if (w == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        int idx = *(int*)(w + 0x18);
        if (idx == 0) {
            func_001D32E0_MR(self);
            break;
        }
        sFactory_MR* f = **(sFactory_MR***)(self + 0x10);
        void* s = f->vt[4].fn((char*)f + f->vt[4].delta, self, idx - 1);
        func_0039F400_MR(*(char**)(self + 0x10) + 0x18, s);
        break;
    }
    case 6: {
        sFactory_MR* f = **(sFactory_MR***)(self + 0x10);
        void* s = f->vt[5].fn((char*)f + f->vt[5].delta, self, *(int*)(w + 0x18));
        if (s == 0) {
            break;
        }
        func_0039F400_MR(*(char**)(self + 0x10) + 0x18, s);
        break;
    }
    case 1: {
        if (*(void**)(self + 0x54) == 0) {
            break;
        }
        int h = 0;
        switch (*(int*)(w + 0x18)) {
        case 0:
            h = GetHashValue32(D_00467450);
            break;
        case 1:
            h = GetHashValue32(D_00467460);
            break;
        case 2:
            if (*(int*)(self + 0xB4) > 0) {
                h = GetHashValue32(D_00467460);
            } else {
                h = GetHashValue32(D_00467478);
            }
            break;
        case 3:
            if (*(int*)(self + 0xB4) >= 2) {
                h = GetHashValue32(D_00467460);
            } else {
                h = GetHashValue32(D_00467490);
            }
            break;
        }
        sText_MR* t = *(sText_MR**)(self + 0x54);
        t->vt[9].fn((char*)t + t->vt[9].delta, 1);
        cUIText_setUnicodeStringByID(*(cUIText**)(self + 0x54), h);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D3120);
#ifdef SKIP_ASM
extern "C" void func_001D31C0(void* self);
extern "C" void* func_0039E510(void* self);

extern "C" void func_001D3120(void* self)
{
    if (~*(int*)((char*)self + 0xBC) != 0) {
        func_001D31C0(self);
    }
    func_0039E510(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D3160);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_0019DA10(void* self, int bank, int id, int a3, int a4, int a5);

extern "C" void func_001D3160(void* self)
{
    if (*(int*)((char*)self + 0xBC) < 0) {
        void* item = *(void**)((char*)self + 0xC0);
        if (item != 0) {
            *(int*)((char*)self + 0xBC) = func_0019DA10(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70, *(int*)((char*)self + 0xB0), *(int*)((char*)item + 4), 0xA, 1, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D31C0);
#ifdef SKIP_ASM
extern "C" int func_0019E238(void* mgr, int bank, int i);
extern "C" void* func_0019E2B0(void* mgr, int bank, int i);
extern "C" void func_001D32E0(void* self);
extern char D_004A1F40[];

struct sVE_31C0 {
    short delta;
    short index;
    int (*fn)(void*, void*, void*, int, int, int);
};

struct sWidget_31C0 {
    char pad0[0x14];
    int flags;      // 0x14
};

static inline int isActive_31C0(sWidget_31C0* w)
{
    return w != 0 && ((w->flags >> 6) & 1);
}

// Starts the preview sound of the selected lodge item once its bank entry has loaded.
extern "C" void func_001D31C0(void* p)
{
    char* self = (char*)p;
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    if (*(void**)(self + 0x50) == 0) {
        return;
    }
    if (func_0019E238(mgr, *(int*)(self + 0xB0), *(int*)(self + 0xBC)) == 0) {
        return;
    }
    char* e = (char*)func_0019E2B0(mgr, *(int*)(self + 0xB0), *(int*)(self + 0xBC));
    char* g = (char*)D_004A289C;
    sVE_31C0* vt = *(sVE_31C0**)(g + 0x10D8);
    int id = vt[46].fn(g + vt[46].delta, e + *(int*)(e + 0x14), D_004A1F40, 0, 1, -1);
    char* snd = *(char**)(self + 0x50);
    *(int*)(self + 0xC4) = id;
    *(int*)(snd + 0x78) = id;
    *(int*)(snd + 0x7C) = 0;
    sWidget_31C0* a = *(sWidget_31C0**)(self + 0x48);
    if (isActive_31C0(a)) {
        int both = 0;
        if (isActive_31C0(a)) {
            sWidget_31C0* b = *(sWidget_31C0**)(self + 0x4C);
            if (b != 0) {
                both = (b->flags >> 6) & 1;
            }
        }
        if (!both) {
            func_001D32E0(self);
        }
    }
    func_0019DC20(mgr, *(int*)(self + 0xB0), *(int*)(self + 0xBC));
    *(int*)(self + 0xBC) = -1;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D32E0);
#ifdef SKIP_ASM
struct sVEntry_func_001D32E0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001D32E0(void* self)
{
    {
        void* obj = *(void**)((char*)self + 0x48);
        sVEntry_func_001D32E0* vt = *(sVEntry_func_001D32E0**)((char*)obj + 0x8);
        vt[9].fn((char*)obj + vt[9].delta, 1);
    }
    if (*(int*)((char*)self + 0xC4) >= 0) {
        void* obj = *(void**)((char*)self + 0x4C);
        sVEntry_func_001D32E0* vt = *(sVEntry_func_001D32E0**)((char*)obj + 0x8);
        vt[9].fn((char*)obj + vt[9].delta, 1);
    }
}
#endif

INCLUDE_ASM("fe/ovstatelodge", func_001D3340);

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D3780);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern "C" unsigned char func_001A1CD0(void* self, int a1);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern void* D_00469788[];

struct sLodge_3780 {
    char pad_0x0[0x48];
    int slots[4];       // 0x48
    int grid[6][5];     // 0x58
    int fD0;            // 0xD0
    char pad_0xD4[0x8];
    int charID;         // 0xDC
    int fE0;            // 0xE0
};

extern "C" void* func_001D3780(void* self, int a1, int a2, int a3)
{
    signed char idx = a2;
    func_0039E2A0(self);
    *(int*)((char*)self + 0xC) = 0x2C;
    *(void***)((char*)self + 0x8) = D_00469788;
    *(signed char*)((char*)self + 0x44) = idx;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), idx);
    sLodge_3780* s = (sLodge_3780*)self;
    s->charID = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)((char*)self + 0x44));
    s->fE0 = a3;
    for (int i = 3; i >= 0; i--) {
        s->slots[i] = 0;
    }
    for (int j = 0; j < 5; j++) {
        s->grid[0][j] = 0;
        s->grid[1][j] = 0;
        s->grid[2][j] = 0;
        s->grid[3][j] = 0;
        s->grid[4][j] = 0;
        s->grid[5][j] = 0;
    }
    s->fD0 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", cFEStatePeakRoom_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern char D_00467648[];

extern "C" void cFEStatePeakRoom_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00467648), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", cFEStatePeakRoom_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" char* func_00156A90(void* self, int a1, int a2);
extern "C" int func_00157BF0(void* self, int rider, int a, int b, int c);
extern "C" int func_00398380(void* self, int id);
extern char D_00466E60[];
extern char D_00467658[];
extern char D_00467668[];
extern char D_00467678[];
extern char D_004A1FA8[];
extern char D_004A1FB0[];
extern char D_00460488[];
extern char* D_004415E0[];
extern char* D_004415F0[];
extern char* D_00441540[];
extern char* D_00441558[];
extern char* D_00441570[];
extern char* D_00441588[];
extern char* D_004415A0[];
extern char* D_004415B8[];

struct sWVEnt_38F8 { short delta; short index; void (*fn)(void*, int); };

struct sWidget_38F8 {
    char pad0[8];
    sWVEnt_38F8* vt;    // 0x08
    char padC[0x18 - 0xC];
    int index;          // 0x18
    char pad1C[0x38 - 0x1C];
    int hash;           // 0x38
    char pad3C[0x78 - 0x3C];
    int f78;            // 0x78
    int f7C;            // 0x7C
};

struct sPeak_38F8 {
    char pad0[0x10];
    char* engine;               // 0x10
    char pad14[0x44 - 0x14];
    signed char player;         // 0x44
    char pad45[0x48 - 0x45];
    sWidget_38F8* slots[4];     // 0x48
    sWidget_38F8* grid[6][5];   // 0x58
    sWidget_38F8* fD0;          // 0xD0
    int fD4;                    // 0xD4
    int fD8;                    // 0xD8
    int charID;                 // 0xDC
    int mode;                   // 0xE0
};

static inline void wShow_38F8(sWidget_38F8* w, int on)
{
    w->vt[9].fn((char*)w + w->vt[9].delta, on);
}

extern "C" void cFEStatePeakRoom_onWidgetCreate(sPeak_38F8* self, sWidget_38F8* w)
{
    int h = w->hash;
    if (h == GetHashValue32(D_00466E60)) {
        int m = self->mode;
        if (m == 2)
            cUIText_setUnicodeStringByID((cUIText*)w, GetHashValue32(D_00467658));
        else if (m == 1)
            cUIText_setUnicodeStringByID((cUIText*)w, GetHashValue32(D_00467668));
        else
            cUIText_setUnicodeStringByID((cUIText*)w, GetHashValue32(D_00467678));
    }
    if (h == GetHashValue32(D_004A1FA8)) {
        self->fD4 = w->f7C;
        return;
    }
    if (h == GetHashValue32(D_004A1FB0)) {
        self->fD8 = w->f7C;
        return;
    }
    if (h == GetHashValue32(D_00460488)) {
        self->fD0 = w;
        wShow_38F8(w, 0);
        return;
    }
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    for (int i = 0; i < 4; i++) {
        if (h == GetHashValue32(D_004415F0[i])) {
            self->slots[i] = w;
            if (func_00157BF0(iface, self->player, self->charID, self->mode, i)) {
                char* info = func_00156A90(iface, self->mode, i);
                char* eng = self->engine;
                int hash = GetHashValue32(*(char**)(info + 8));
                int r = func_00398380(eng + 0x58, hash);
                sWidget_38F8* sw = self->slots[i];
                sw->f78 = -1;
                sw->f7C = r;
            } else {
                wShow_38F8(self->slots[i], 0);
            }
            return;
        }
        if (h == GetHashValue32(D_004415E0[i])) {
            w->index = i;
            return;
        }
    }
    for (int j = 0; j < 5; j++) {
        if (h == GetHashValue32(D_00441588[j])) {
            self->grid[1][j] = w;
            wShow_38F8(w, 0);
            w->index = j;
            return;
        }
        if (h == GetHashValue32(D_00441570[j])) {
            self->grid[0][j] = w;
            wShow_38F8(w, 0);
            w->index = j;
            return;
        }
        if (h == GetHashValue32(D_00441540[j])) {
            self->grid[2][j] = w;
            wShow_38F8(w, 0);
            w->index = j;
            return;
        }
        if (h == GetHashValue32(D_00441558[j])) {
            self->grid[3][j] = w;
            wShow_38F8(w, 0);
            w->index = j;
            return;
        }
        if (h == GetHashValue32(D_004415A0[j])) {
            self->grid[4][j] = w;
            wShow_38F8(w, 0);
            w->index = j;
            return;
        }
        if (h == GetHashValue32(D_004415B8[j])) {
            self->grid[5][j] = w;
            wShow_38F8(w, 0);
            w->index = j;
            return;
        }
    }
}
#endif

extern "C" void* func_0039E4C0(void* self);

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D3C60__FPv);
#ifdef SKIP_ASM
void* func_001D3C60(void* self)
{
    return func_0039E4C0(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D3C80);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00157BF0(void* self, int rider, int a, int b, int c);
extern "C" void cFEStatePeakRoom_updateHelpText(void* self, int id);
extern "C" void func_001D3F80(void* self, int id);
extern "C" void func_0039F400(void* list, void* item);

struct sVEntA_001D3C80 { short delta; short index; void* (*fn)(void*, void*, int); };
struct sVEntB_001D3C80 { short delta; short index; void (*fn)(void*, int); };
struct sItem_001D3C80 { int pad[2]; sVEntB_001D3C80* vt; };

extern "C" void func_001D3C80(void* self, void* item, unsigned int key)
{
    if (item == 0) {
        return;
    }
    switch (key) {
    case 5:
        if (func_00157BF0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(signed char*)((char*)self + 0x44),
                          *(int*)((char*)self + 0xDC), *(int*)((char*)self + 0xE0), *(int*)((char*)item + 0x18)) != 0) {
            void* obj = **(void***)((char*)self + 0x10);
            sVEntA_001D3C80* vt = *(sVEntA_001D3C80**)((char*)obj + 4);
            void* r = vt[4].fn((char*)obj + vt[4].delta, self, (*(int*)((char*)self + 0xE0) << 16) | *(int*)((char*)item + 0x18));
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    case 6: {
        int id = (*(int*)((char*)self + 0xE0) << 16) | *(int*)((char*)item + 0x18);
        for (int i = 0; i < 4; i++) {
            sItem_001D3C80* o = ((sItem_001D3C80**)((char*)self + 0x48))[i];
            if (o != 0) {
                o->vt[9].fn((char*)o + o->vt[9].delta, 0);
            }
        }
        void* obj = **(void***)((char*)self + 0x10);
        sVEntA_001D3C80* vt = *(sVEntA_001D3C80**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, id);
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    case 1:
        cFEStatePeakRoom_updateHelpText(self, *(int*)((char*)item + 0x18));
        func_001D3F80(self, *(int*)((char*)item + 0x18));
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D3E08);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00157BF0(void* self, int rider, int a, int b, int c);
extern "C" void* func_00397870(void* list, int id);

extern "C" int func_001D3E08(void* self, void* item, unsigned int key, int id)
{
    switch (key) {
    default:
        break;
    case 8:
    case 9:
        return 0x100;
    case 6: {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 0xD);
        void* e = func_00397870((char*)item + 0x74, id);
        if (func_00157BF0(iface, *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0xDC),
                          *(int*)((char*)self + 0xE0), *(int*)((char*)e + 0x18)) == 0) {
            return 0x10;
        }
        break;
    }
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", cFEStatePeakRoom_updateHelpText);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00157BF0(void* self, int rider, int a, int b, int c);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_00467688[];
extern char D_004676A0[];

class cPeakWidget_3EC8 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

extern "C" void cFEStatePeakRoom_updateHelpText(void* self, int index)
{
    if (*(void**)((char*)self + 0xD0) != 0) {
        if (func_00157BF0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(signed char*)((char*)self + 0x44),
                          *(int*)((char*)self + 0xDC), *(int*)((char*)self + 0xE0), index) != 0) {
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0xD0), GetHashValue32(D_00467688));
        } else {
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0xD0), GetHashValue32(D_004676A0));
        }
        (*(cPeakWidget_3EC8**)((char*)self + 0xD0))->show(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D3F80);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv_3F80(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_001CE6F0(int mountain);
extern "C" int func_001CED90(int player, int charId, int mountain, int peak, int i);
extern "C" void setChallengeName(void* text, int mountain, int peak, int i);
extern "C" char* func_00156AE0(void* iface, int peak, int ch);
extern "C" int func_00398380(void* self, int id);

class cWidget_3F80 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

struct sRoom_3F80 {
    char pad_0x0[0x10];
    char* engine;                   // 0x10
    char pad_0x14[0x30];
    signed char player;             // 0x44
    char pad_0x45[0x13];
    cWidget_3F80* icon[5];          // 0x58
    cWidget_3F80* box[5];           // 0x6C
    cWidget_3F80* name[5];          // 0x80
    cWidget_3F80* bar[5];           // 0x94
    cWidget_3F80* medal[5];         // 0xA8
    cWidget_3F80* lock[5];          // 0xBC
    char pad_0xD0[0xC];
    int charId;                     // 0xDC
    int mountain;                   // 0xE0
};

extern "C" void func_001D3F80(void* vself, int peak)
{
    sRoom_3F80* self = (sRoom_3F80*)vself;
    int n;
    void* iface;
    int i;
    cWidget_3F80** icon = self->icon;
    cWidget_3F80** box = self->box;
    cWidget_3F80** name = self->name;
    cWidget_3F80** bar = self->bar;
    cWidget_3F80** medal = self->medal;
    cWidget_3F80** lock = self->lock;
    n = func_001CE6F0(self->mountain);
    for (int j = 0; j < 5; j++) {
        self->icon[j]->show(0);
        self->box[j]->show(0);
        self->name[j]->show(0);
        self->bar[j]->show(0);
        self->medal[j]->show(0);
        self->lock[j]->show(0);
    }
    iface = cBE_getInterface_Fv_3F80(cBE_getBE(), 0xD);
    for (i = 0; i < n; i++) {
        int ch = func_001CED90(self->player, self->charId, self->mountain, peak, i);
        setChallengeName(name[i], self->mountain, peak, i);
        name[i]->show(1);
        bar[i]->show(1);
        box[i]->show(1);
        if (ch != -1) {
            char* o = func_00156AE0(iface, peak, ch);
            char* eng = self->engine;
            int hash = GetHashValue32(*(char**)(o + 8));
            int h = func_00398380(eng + 0x58, hash);
            cWidget_3F80* w = icon[i];
            *(int*)((char*)w + 0x7C) = h;
            *(int*)((char*)w + 0x78) = -1;
            icon[i]->show(1);
            medal[i]->show(1);
        } else {
            lock[i]->show(1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatelodge", func_001D4268);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern "C" unsigned char func_001A1CD0(void* self, int a1);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" void func_001D4918(void* self);
extern void* D_004696B8[];

struct sVE_4268 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sTrophy_4268 {
    char pad_0x0[0x48];
    int f48;            // 0x48
    char pad_0x4C[0x4];
    int charID;         // 0x50
    int f54;            // 0x54
    int bank;           // 0x58
    int count;          // 0x5C
    int snd[5];         // 0x60
    int tex[5];         // 0x74
    char pad_0x88[0x14];
    int f9C;            // 0x9C
};

extern "C" void* func_001D4268(void* self, int a1, int a2, int a3, int a4)
{
    signed char idx = a2;
    func_0039E2A0(self);
    *(int*)((char*)self + 0xC) = 0x2D;
    *(void***)((char*)self + 0x8) = D_004696B8;
    *(signed char*)((char*)self + 0x44) = idx;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), idx);
    sTrophy_4268* s = (sTrophy_4268*)self;
    s->f48 = 0;
    void* pi = cBE_getInterface_Fv(cBE_getBE(), 1);
    s->charID = cBENewPlayerInterface_getPlayerCharID(pi, *(signed char*)((char*)self + 0x44));
    sVE_4268* vt = *(sVE_4268**)((char*)pi + 0xC);
    vt[2].fn((char*)pi + vt[2].delta);
    s->f54 = a3;
    s->bank = a4;
    s->count = 0;
    for (int i = 0; i < 5; i++) {
        s->snd[i] = -1;
        s->tex[i] = -1;
    }
    s->f9C = -1;
    func_001D4918(self);
    return self;
}
#endif

