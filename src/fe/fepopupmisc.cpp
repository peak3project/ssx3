#include "common.h"

//100%
INCLUDE_ASM("fe/fepopupmisc", cFEPopupVideoCalibration_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_004A1548[];
extern char* D_004A1540;
extern char D_0045DD90[];
extern char D_0045DDA0[];

class cUIObjK1DEB90 {
public:
    char pad_0x000[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int);
};

extern "C" void cFEPopupVideoCalibration_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A1548), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    cUIObjK1DEB90* obj = (cUIObjK1DEB90*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1540));
    if (obj != 0) {
        obj->v09(1);
    }
    cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DD90));
    if (text != 0) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_0045DDA0));
    }
    *(char*)((char*)self + 0x48) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DEC68);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern "C" void* cUIScreen_getObjectByHashName_EC68(void* self, int hash) __asm__("cUIScreen_getObjectByHashName");
extern char* D_004A1540;
// PORT: the target re-reads this name pointer without filling the call delay slot; volatile view.
extern char* volatile D_004A1544_EC68 __asm__("D_004A1544");
extern char D_0045DD90[];
extern char D_0045DDB8[];
extern char D_0045DDC8[];

struct sVE_EC68 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sVEi_EC68 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sWidget_EC68 {
    int pad[2];
    sVEi_EC68* vt;
};

struct sObj_EC68 {
    int pad[2];
    sVE_EC68* vt;
};

struct sSnd_EC68 {
    sVE_EC68* vt;
};
extern sSnd_EC68 D_004A5A58_EC68 __asm__("D_004A5A58");

static inline void show_EC68(char* self, char* name, int on)
{
    sObj_EC68* o = (sObj_EC68*)cUIScreen_getObjectByHashName_EC68(*(void**)(self + 0x40), GetHashValue32(name));
    if (o != 0) {
        o->vt[9].fn((char*)o + o->vt[9].delta, on);
    }
}

// Popup gain-focus handler: on first activation shows the buttons and sets the help text.
extern "C" int func_001DEC68(char* self, sWidget_EC68* w)
{
    if (w->vt[5].fn((char*)w + w->vt[5].delta)) {
        if (*(signed char*)(self + 0x48) == 0) {
            show_EC68(self, D_004A1540, 0);
            show_EC68(self, D_004A1544_EC68, 1);
            cUIText* t = (cUIText*)cUIScreen_getObjectByHashName_EC68(*(void**)(self + 0x40), GetHashValue32(D_0045DD90));
            if (t != 0) {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DDB8));
            }
            show_EC68(self, D_0045DDC8, 0);
            *(signed char*)(self + 0x48) = 1;
        } else {
            *(int*)(self + 0x1C) = ((*(int*)(self + 0x1C) | 0x80) & ~0x3F00) | 0x700;
        }
        sSnd_EC68* s = *(sSnd_EC68**)(*(char**)(self + 0x10) + 0x14);
        if (s == 0) {
            s = &D_004A5A58_EC68;
        }
        if (s != 0) {
            s->vt[2].fn((char*)s + s->vt[2].delta, 6);
        }
    }
    return 1;
}
#endif

extern void* D_0046B230[];
extern "C" void func_0039E390(void *, int);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DEDE8__FPv);
#ifdef SKIP_ASM
// func_001DEDE8 is matched under the C++ symbol func_001DEDE8__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001DEDE8(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046B230;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DEE10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern char D_0045DDD8[];

struct sOptions_EE10 {
    unsigned int flags;
    int pad_4 : 8;
    int b5 : 8;
    int b6 : 8;
    int pad_7 : 8;
    int data[(0x288 - 8) / 4];
};
extern sOptions_EE10 D_00535610_EE10 __asm__("D_00535610");

static inline int optB6_EE10(sOptions_EE10 o)
{
    return o.b6;
}

static inline int optB5_EE10(sOptions_EE10 o)
{
    return o.b5;
}

extern "C" void func_001DEE10(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DDD8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        *(int*)((char*)self + 0xC) = GetHashValue32(D_0045DDD8);
    }
    void* be = cBE_getBE();
    cBE_getInterface_Fv(be, 4);
    int* p48 = (int*)((char*)self + 0x48);
    *p48 = optB6_EE10(D_00535610_EE10);
    int* p4C = (int*)((char*)self + 0x4C);
    *p4C = optB5_EE10(D_00535610_EE10);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF028);
#ifdef SKIP_ASM
extern "C" int func_001DF028(void* self, int i)
{
    switch (i) {
    case 0:
        return *(int*)((char*)self + 0x48);
    case 1:
        return *(int*)((char*)self + 0x4c);
    }
    return *(signed char*)((char*)self + 0x50);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", cFEPopupScreenPos_onUpdate);
#ifdef SKIP_ASM
struct cUIScreen;
// PORT: the unit declares cUIScreen_getFrameByLabel as returning int; the frame id is an unsigned short.
unsigned short cUIScreen_getFrameByLabel_us(cUIScreen* screen, int hash) __asm__("cUIScreen_getFrameByLabel__FP9cUIScreeni");
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0039F190(void* self, int a1);
extern char* D_004A289C;
extern char D_004A1550[];
extern char D_004A1558[];
extern char D_004A1560[];
extern char D_0045DDF0[];

struct sVEm_F050 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sDefObj_F050 {
    sVEm_F050* vt;
};
extern sDefObj_F050 D_004A5A58;

struct sVEi_F050 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sVEs_F050 {
    short delta;
    short index;
    void (*fn)(void*, unsigned char);
};

struct sVEp_F050 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

struct sPopup_F050 {
    char pad0[0x10];
    char* owner;                // 0x10
    char pad14[0x8];            // 0x14
    int flags;                  // 0x1C
    char pad20[0x20];           // 0x20
    void* screen;               // 0x40
    char pad44[0x4];            // 0x44
    int x;                      // 0x48
    int y;                      // 0x4C
    signed char accepted;       // 0x50
};

static inline int padCall_F050(char* in, int slot)
{
    sVEi_F050* vt = *(sVEi_F050**)(in + 8);
    return vt[slot].fn(in + vt[slot].delta);
}

static inline void sound_F050(sPopup_F050* s, int msg)
{
    sDefObj_F050* p = *(sDefObj_F050**)(s->owner + 0x14);
    if (p == 0)
        p = &D_004A5A58;
    if (p != 0)
        p->vt[2].fn((char*)p + p->vt[2].delta, msg);
}

static inline void playFrame_F050(sPopup_F050* s, char* name)
{
    unsigned short frame = cUIScreen_getFrameByLabel_us((cUIScreen*)s->screen, GetHashValue32(name));
    if (frame != 0xFFFF)
        cUIScreen_playFrame(s->screen, frame, 1);
}

static inline int clamp_F050(int v, int lo, int hi)
{
    if (v >= lo) {
        if (v > hi) {
            v = hi;
        }
    } else {
        v = lo;
    }
    return v;
}

extern "C" void cFEPopupScreenPos_onUpdate(sPopup_F050* self)
{
    char* in = *(char**)(self->owner + 0xC);
    for (int i = 0; i < 2; i++) {
        sVEs_F050* vt = *(sVEs_F050**)(in + 8);
        vt[44].fn(in + vt[44].delta, i);
        if (padCall_F050(in, 40) == 0) {
            continue;
        }
        if (padCall_F050(in, 5)) {
            sound_F050(self, 6);
            self->accepted = 1;
            self->flags |= 0x80;
            func_0039F190(self->owner + 0x18, 1);
        } else if (padCall_F050(in, 6)) {
            sound_F050(self, 3);
            self->accepted = 0;
            self->flags |= 0x80;
            func_0039F190(self->owner + 0x18, 1);
        } else if (padCall_F050(in, 19)) {
            self->x--;
            playFrame_F050(self, D_004A1550);
        } else if (padCall_F050(in, 20)) {
            self->x++;
            playFrame_F050(self, D_0045DDF0);
        } else if (padCall_F050(in, 17)) {
            self->y++;
            playFrame_F050(self, D_004A1558);
        } else if (padCall_F050(in, 18)) {
            self->y--;
            playFrame_F050(self, D_004A1560);
        }
        if (self->x < -20 || self->x > 20 || self->y < -20 || self->y > 20) {
            sound_F050(self, 4);
        }
        self->x = clamp_F050(self->x, -20, 20);
        self->y = clamp_F050(self->y, -20, 20);
        sVEp_F050* rv = *(sVEp_F050**)(D_004A289C + 0x10D8);
        rv[12].fn(D_004A289C + rv[12].delta, self->x, self->y);
        return;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF378__FPv);
#ifdef SKIP_ASM
int func_001DF378(void* self)
{
    return 0x1;
}
#endif

extern void* D_0046D0D0[];
extern "C" void func_0039E390(void *, int);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF380);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_0046B160[];

extern "C" void* func_001DF380(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_0046B160;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF3B8__FPv);
#ifdef SKIP_ASM
// func_001DF3B8 is matched under the C++ symbol func_001DF3B8__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001DF3B8(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

extern "C" void func_0039E390(void *, int);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF3E0);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_0046B090[];

extern "C" void* func_001DF3E0(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_0046B090;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF418__FPv);
#ifdef SKIP_ASM
// func_001DF418 is matched under the C++ symbol func_001DF418__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001DF418(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF440);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046B078[];

extern "C" void func_001DF440(void* self, int flags)
{
    *(void***)((char*)self + 0x30) = D_0046B078;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF470);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
inline void* operator new[](unsigned int, void* p) { return p; }
extern "C" void* func_001A8500(void*, int, int);
extern "C" void* func_001926F0(void* self);
extern void* D_0046AF68[];

// Element type of an inline-constructed array (0x34 bytes, constructed by func_001926F0).
struct sElem_F470 {
    char pad[0x34];
    sElem_F470() { func_001926F0(this); }
};

extern "C" void* func_001DF470(void* self)
{
    func_001A8500(self, 0, 0);
    *(void***)((char*)self + 0x8) = D_0046AF68;
    new ((char*)self + 0x6D0) sElem_F470[2];
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF4E8);
#ifdef SKIP_ASM
extern void* D_0046AF68[];
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

struct sVEntry001DF4E8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001DF4E8(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046AF68;
    if ((char*)self + 0x6D0 != 0) {
        char* p = (char*)self + 0x6D0 + 0x68;
        while ((char*)self + 0x6D0 != p) {
            p -= 0x34;
            sVEntry001DF4E8* vt = *(sVEntry001DF4E8**)(p + 0x30);
            vt[1].fn(p + vt[1].delta, 0);
        }
    }
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF578__FPv);
#ifdef SKIP_ASM
void func_001DF578(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF580);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_0046AE58[];

extern "C" void* func_001DF580(void* self)
{
    func_001A8500(self, 0, 0);
    *(int*)((char*)self + 0x6F8) = 0;
    *(void***)((char*)self + 0x8) = D_0046AE58;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF5C0__FPv);
#ifdef SKIP_ASM
void func_001DF5C0(void* self)
{
}
#endif

extern void* D_0046AD48[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF5C8);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001DF5C8(void *self) {
    func_001A8500(self, 0, 0);
    (*(void ***)((char*)(self) + (8))) = D_0046AD48;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF608__FPv);
#ifdef SKIP_ASM
void* func_001DF608(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046AD48;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF630__FPv);
#ifdef SKIP_ASM
int func_001DF630(void* self)
{
    return 0x1;
}
#endif

extern void* D_0046AB28[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF638);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001DF638(void *self) {
    func_001A8500(self, 0, 0);
    (*(int *)((char*)(self) + (0x6EC))) = 0;
    (*(void ***)((char*)(self) + (8))) = D_0046AB28;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF678__FPv);
#ifdef SKIP_ASM
void* func_001DF678(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046AB28;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF6A0__FPv);
#ifdef SKIP_ASM
int func_001DF6A0(void* self)
{
    return 0x1;
}
#endif

extern void* D_0046AA18[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF6A8);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001DF6A8(void *self) {
    func_001A8500(self, 0, 0);
    (*(void ***)((char*)(self) + (8))) = D_0046AA18;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF6E8__FPv);
#ifdef SKIP_ASM
void* func_001DF6E8(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046AA18;
    return func_001A85D0(self);
}
#endif

extern void* D_0046A908[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF710);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001DF710(void *self) {
    func_001A8500(self, 0, 0);
    (*(void ***)((char*)(self) + (8))) = D_0046A908;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF750__FPv);
#ifdef SKIP_ASM
void* func_001DF750(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046A908;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF778);
#ifdef SKIP_ASM
extern "C" int func_001DF778(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6D0)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF780);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_0046A7F8[];
extern int D_004A3E90;

extern "C" void* func_001DF780(void* self)
{
    func_001A8500(self, 0, 0);
    int g = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_0046A7F8;
    *(int*)((char*)self + 0x76C) = g;
    *(int*)((char*)self + 0xB80) = g;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF7C8);
#ifdef SKIP_ASM
extern void* D_0046A7F8[];
extern "C" void cBXString__cBXString(void* self, int flags);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001DF7C8(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A7F8;
    cBXString__cBXString((char*)self + 0xB80, 2);
    cBXString__cBXString((char*)self + 0x76C, 2);
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF828);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_0046A6E8[];
extern int D_004A3E90;

extern "C" void* func_001DF828(void* self)
{
    func_001A8500(self, 0, 0);
    int g = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_0046A6E8;
    *(int*)((char*)self + 0x6DC) = g;
    *(int*)((char*)self + 0x6E0) = g;
    *(int*)((char*)self + 0x6E4) = g;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF878);
#ifdef SKIP_ASM
extern void* D_0046A6E8[];
extern "C" void cBXString__cBXString(void* self, int flags);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001DF878(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A6E8;
    cBXString__cBXString((char*)self + 0x6E4, 2);
    cBXString__cBXString((char*)self + 0x6E0, 2);
    cBXString__cBXString((char*)self + 0x6DC, 2);
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF8E0__FPv);
#ifdef SKIP_ASM
int func_001DF8E0(void* self)
{
    return 0x1;
}
#endif

extern void* D_0046A618[];
extern "C" void func_0039E390(void *, int);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF8E8);
#ifdef SKIP_ASM
extern "C" int func_001DF8E8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6DC)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF8F0);
#ifdef SKIP_ASM
extern "C" int func_001DF8F0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6E0)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF8F8);
#ifdef SKIP_ASM
extern "C" int func_001DF8F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6E4)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF900);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_0046A618[];

// Element type of an inline-constructed array; its empty constructor leaves only the loop counters.
struct sSlot_F900 {
    int v;
    sSlot_F900() {}
};

extern "C" void* func_001DF900(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_0046A618;
    new ((char*)self + 0x20) sSlot_F900[7];
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF960__FPv);
#ifdef SKIP_ASM
// func_001DF960 is matched under the C++ symbol func_001DF960__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001DF960(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046A618;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF988__FPv);
#ifdef SKIP_ASM
int func_001DF988(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF990);
#ifdef SKIP_ASM
extern "C" void func_001DF990(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x54))) = arg1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF998);
#ifdef SKIP_ASM
extern "C" void func_001DF998(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x64))) = arg1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF9A0);
#ifdef SKIP_ASM
extern "C" void func_001DF9A0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x50))) = arg1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF9A8);
#ifdef SKIP_ASM
extern "C" int func_001DF9A8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x50)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF9B0);
#ifdef SKIP_ASM
extern "C" int func_001DF9B0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC8))) == 1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF9C0);
#ifdef SKIP_ASM
extern "C" int func_001DF9C0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA60)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF9C8);
#ifdef SKIP_ASM
extern "C" void func_001DF9C8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xAE4))) = arg1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF9D0);
#ifdef SKIP_ASM
extern "C" int func_001DF9D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAE4)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DF9D8);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_0046A3C8[];

extern "C" void* func_001DF9D8(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFA10);
#ifdef SKIP_ASM
extern void* D_0046A3C8[];
extern void* D_0046D0D0[];
void func_001DFAC8(void* self);
extern "C" void func_001D00C0(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001DFA10(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    func_001DFAC8(self);
    func_001D00C0(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFA70);
#ifdef SKIP_ASM
extern "C" int func_001DFA70(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x8F0)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFA78);
#ifdef SKIP_ASM
extern "C" unsigned int func_001DFA78(void *arg0) {
    return (unsigned int) ~(*(int *)((char*)(arg0) + (0x8F0))) >> 0x1F;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFA88__FPv);
#ifdef SKIP_ASM
int func_001DFA88(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFA90);
#ifdef SKIP_ASM
extern "C" int func_001DFA90(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x48))) >> 3) & 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAA0__FPv);
#ifdef SKIP_ASM
int func_001DFAA0(void* self)
{
    return -0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAA8__FPv);
#ifdef SKIP_ASM
int func_001DFAA8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAB0);
#ifdef SKIP_ASM
extern "C" int func_001DFAB0(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x48))) >> 1) & 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAC0__FPv);
#ifdef SKIP_ASM
void func_001DFAC0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAC8__FPv);
#ifdef SKIP_ASM
void func_001DFAC8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAD0__FPv);
#ifdef SKIP_ASM
int func_001DFAD0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAD8__FPv);
#ifdef SKIP_ASM
int func_001DFAD8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAE0__FPv);
#ifdef SKIP_ASM
int func_001DFAE0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAE8__FPv);
#ifdef SKIP_ASM
int func_001DFAE8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFAF0);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_0046A248[];

extern "C" void* func_001DFAF0(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_0046A248;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFB28);
#ifdef SKIP_ASM
extern void* D_0046A3C8[];
extern void* D_0046D0D0[];
void func_001DFAC8(void* self);
extern "C" void func_001D00C0(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001DFB28(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    func_001DFAC8(self);
    func_001D00C0(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFB88__FPvi);
#ifdef SKIP_ASM
int func_001DFB88(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0xA28);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFB98);
#ifdef SKIP_ASM
extern "C" int func_001DFB98(void* self, void* a1)
{
    int v = *(short*)((char*)a1 + 0xc);
    if (v > 0) v = v * 10;
    return v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFBB0__FPvT0);
#ifdef SKIP_ASM
signed char func_001DFBB0(void* self, void* other)
{
    return *(signed char*)((char*)other + 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFBB8__FPvT0);
#ifdef SKIP_ASM
int func_001DFBB8(void* self, void* other)
{
    return *(int*)((char*)other + 0x0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFBC0);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_0046A0C8[];

extern "C" void* func_001DFBC0(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_0046A0C8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFBF8);
#ifdef SKIP_ASM
extern void* D_0046A3C8[];
extern void* D_0046D0D0[];
void func_001DFAC8(void* self);
extern "C" void func_001D00C0(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001DFBF8(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    func_001DFAC8(self);
    func_001D00C0(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFC58__FPvi);
#ifdef SKIP_ASM
int func_001DFC58(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0xA28);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFC68);
#ifdef SKIP_ASM
extern "C" int func_001DFC68(void* self, void* a1)
{
    int v = *(short*)((char*)a1 + 0xc);
    if (v > 0) v = v * 10;
    return v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFC80__FPvT0);
#ifdef SKIP_ASM
signed char func_001DFC80(void* self, void* other)
{
    return *(signed char*)((char*)other + 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFC88__FPvT0);
#ifdef SKIP_ASM
int func_001DFC88(void* self, void* other)
{
    return *(int*)((char*)other + 0x0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFC90);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469F48[];

extern "C" void* func_001DFC90(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469F48;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFCC8);
#ifdef SKIP_ASM
extern void* D_0046A3C8[];
extern void* D_0046D0D0[];
void func_001DFAC8(void* self);
extern "C" void func_001D00C0(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001DFCC8(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    func_001DFAC8(self);
    func_001D00C0(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFD28__FPvi);
#ifdef SKIP_ASM
int func_001DFD28(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0xA28);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFD38);
#ifdef SKIP_ASM
extern "C" int func_001DFD38(void* self, void* a1)
{
    int v = *(short*)((char*)a1 + 0xc);
    if (v > 0) v = v * 10;
    return v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFD50__FPvT0);
#ifdef SKIP_ASM
signed char func_001DFD50(void* self, void* other)
{
    return *(signed char*)((char*)other + 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFD58__FPvT0);
#ifdef SKIP_ASM
int func_001DFD58(void* self, void* other)
{
    return *(int*)((char*)other + 0x0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFD60);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469DC8[];

extern "C" void* func_001DFD60(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469DC8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFD98);
#ifdef SKIP_ASM
extern void* D_0046A3C8[];
extern void* D_0046D0D0[];
void func_001DFAC8(void* self);
extern "C" void func_001D00C0(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001DFD98(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    func_001DFAC8(self);
    func_001D00C0(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFDF8__FPvi);
#ifdef SKIP_ASM
int func_001DFDF8(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0xA28);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFE08);
#ifdef SKIP_ASM
extern "C" int func_001DFE08(void* self, void* a1)
{
    int v = *(short*)((char*)a1 + 0xc);
    if (v > 0) v = v * 10;
    return v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFE20__FPvT0);
#ifdef SKIP_ASM
signed char func_001DFE20(void* self, void* other)
{
    return *(signed char*)((char*)other + 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFE28__FPvT0);
#ifdef SKIP_ASM
int func_001DFE28(void* self, void* other)
{
    return *(int*)((char*)other + 0x0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFE30);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469C48[];

extern "C" void* func_001DFE30(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469C48;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFE68);
#ifdef SKIP_ASM
extern void* D_0046A3C8[];
extern void* D_0046D0D0[];
void func_001DFAC8(void* self);
extern "C" void func_001D00C0(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001DFE68(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    func_001DFAC8(self);
    func_001D00C0(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFEC8__FPvi);
#ifdef SKIP_ASM
int func_001DFEC8(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0xA28);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFED8);
#ifdef SKIP_ASM
extern "C" int func_001DFED8(void* self, void* a1)
{
    int v = *(short*)((char*)a1 + 0xc);
    if (v > 0) v = v * 10;
    return v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFEF0__FPvT0);
#ifdef SKIP_ASM
signed char func_001DFEF0(void* self, void* other)
{
    return *(signed char*)((char*)other + 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFEF8__FPvT0);
#ifdef SKIP_ASM
int func_001DFEF8(void* self, void* other)
{
    return *(int*)((char*)other + 0x0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFF00);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469AC8[];

extern "C" void* func_001DFF00(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469AC8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFF38);
#ifdef SKIP_ASM
extern void* D_0046A3C8[];
extern void* D_0046D0D0[];
void func_001DFAC8(void* self);
extern "C" void func_001D00C0(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001DFF38(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A3C8;
    func_001DFAC8(self);
    func_001D00C0(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFF98__FPvi);
#ifdef SKIP_ASM
int func_001DFF98(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0xA28);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFFA8);
#ifdef SKIP_ASM
extern "C" int func_001DFFA8(void* self, void* a1)
{
    int v = *(short*)((char*)a1 + 0xc);
    if (v > 0) v = v * 10;
    return v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFFC0__FPvT0);
#ifdef SKIP_ASM
signed char func_001DFFC0(void* self, void* other)
{
    return *(signed char*)((char*)other + 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFFC8__FPvT0);
#ifdef SKIP_ASM
int func_001DFFC8(void* self, void* other)
{
    return *(int*)((char*)other + 0x0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001DFFD0);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_004699F8[];

extern "C" void* func_001DFFD0(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_004699F8;
    return self;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0008);
#ifdef SKIP_ASM
extern "C" int func_001E0008(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0010);
#ifdef SKIP_ASM
extern "C" int func_001E0010(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0018);
#ifdef SKIP_ASM
extern "C" int func_001E0018(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0020__FPv);
#ifdef SKIP_ASM
int func_001E0020(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0028__FPv);
#ifdef SKIP_ASM
int func_001E0028(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0030);
#ifdef SKIP_ASM
extern "C" void func_001E0030(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x270))) = arg1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0038);
#ifdef SKIP_ASM
extern "C" void func_001E0038(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x258))) = arg1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0040);
#ifdef SKIP_ASM
extern "C" void func_001E0040(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x254))) = arg1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0048);
#ifdef SKIP_ASM
struct sBlock24 {
    int w[9];
};

extern "C" void func_001E0048(void* self, void* src)
{
    *(sBlock24*)((char*)self + 0x24C) = *(sBlock24*)src;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0098);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469858[];

extern "C" void* func_001E0098(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469858;
    return self;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E00D0);
#ifdef SKIP_ASM
extern "C" int func_001E00D0(void *arg0) {
    return ~(*(int *)((char*)(arg0) + (0xBC))) == 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E00E0);
#ifdef SKIP_ASM
class cWidget_E00E0 {
    int pad0[2];
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a);
};

extern "C" void func_001E00E0(void* self)
{
    (*(cWidget_E00E0**)((char*)self + 0x48))->v9(0);
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0110);
#ifdef SKIP_ASM
extern "C" int func_001E0110(void *arg0) {
    int var_2;
    void *temp_3;

    temp_3 = (*(void **)((char*)(arg0) + (0x48)));
    var_2 = 0;
    if (temp_3 != 0) {
        var_2 = ((int) (*(int *)((char*)(temp_3) + (0x14))) >> 6) & 1;
    }
    return var_2;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0130);
#ifdef SKIP_ASM
extern "C" int func_001E0130(void *arg0) {
    int var_2;
    int var_5;
    void *temp_3;
    void *temp_4;

    temp_3 = (*(void **)((char*)(arg0) + (0x48)));
    var_5 = 0;
    var_2 = 0;
    if (temp_3 != 0) {
        var_2 = ((int) (*(int *)((char*)(temp_3) + (0x14))) >> 6) & 1;
    }
    if (var_2 != 0) {
        temp_4 = (*(void **)((char*)(arg0) + (0x4C)));
        if (temp_4 != 0) {
            var_5 = ((int) (*(int *)((char*)(temp_4) + (0x14))) >> 6) & 1;
        }
    }
    return var_5;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0178);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469788[];

extern "C" void* func_001E0178(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469788;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E01B0__FPv);
#ifdef SKIP_ASM
// func_001E01B0 is matched under the C++ symbol func_001E01B0__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001E01B0(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E01D8);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_004696B8[];

extern "C" void* func_001E01D8(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_004696B8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0210);
#ifdef SKIP_ASM
extern void* D_004696B8[];
extern void* D_0046D0D0[];
extern "C" void func_001D4B20(void* self);
extern "C" void func_0039E390(void *, int);

extern "C" void func_001E0210(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004696B8;
    func_001D4B20(self);
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0268);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_004695E8[];

extern "C" void* func_001E0268(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_004695E8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E02A0__FPv);
#ifdef SKIP_ASM
// func_001E02A0 is matched under the C++ symbol func_001E02A0__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001E02A0(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

extern void* D_00469518[];
extern "C" void func_0039E390(void *, int);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E02C8);
#ifdef SKIP_ASM
extern "C" int func_001E02C8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x4C)));
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E02D0__FPv);
#ifdef SKIP_ASM
// func_001E02D0 is matched under the C++ symbol func_001E02D0__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001E02D0(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_00469518;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", cFEPopupSelectMultiplayerMode_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00460008[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cFEPopupSelectMultiplayerMode_onCreateScreen(void* self)
{
    int hash = GetHashValue32(D_00460008);
    *(int*)((char*)self + 0xC) = hash;
    void* screen = cUIEngine_addScreenByHashName(*(void**)((char*)self + 0x10), self, hash, 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", cFEPopupSelectMultiplayerMode_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_0039B760(void* self, int a1);
extern char D_00460020[];
extern char D_004A13A0[];
extern char D_004A14F8[];

extern "C" void cFEPopupSelectMultiplayerMode_onWidgetCreate(void* self, void* item)
{
    int h1 = *(int*)((char*)item + 0x38);
    if (h1 == GetHashValue32(D_00460020)) {
        *(int*)((char*)item + 0x14) |= 1;
        func_0039B760(item, 2);
        *(int*)((char*)item + 0x14) |= 0x80;
        return;
    }
    int h2 = *(int*)((char*)item + 0x38);
    if (h2 == GetHashValue32(D_004A13A0)) {
        *(int*)((char*)item + 0x18) = 0;
        return;
    }
    int h3 = *(int*)((char*)item + 0x38);
    if (h3 == GetHashValue32(D_004A14F8)) {
        *(int*)((char*)item + 0x18) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E03F8);
#ifdef SKIP_ASM
extern int D_004A19D4;
extern "C" void func_0039F190(void* self, int a1);

extern "C" void func_001E03F8(void* self, void* a1, int a2)
{
    switch (a2) {
    case 5: {
        char* p = *(char**)((char*)self + 0x10);
        *(char*)((char*)self + 0x48) = 1;
        D_004A19D4 = *(int*)((char*)a1 + 0x18) != 0;
        func_0039F190(p + 0x18, 1);
        break;
    }
    case 6: {
        char* p = *(char**)((char*)self + 0x10);
        *(char*)((char*)self + 0x48) = 0;
        func_0039F190(p + 0x18, 1);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0470);
#ifdef SKIP_ASM
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);

extern "C" int func_001E0470(void* self, void* menu, unsigned int key, int idx)
{
    switch (key) {
    default:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (key < 6) {
            return 0x101;
        }
        break;
    case 2:
        cUIMenu_setSelectedByIndex(menu, idx - 1);
    case 3:
        cUIMenu_setSelectedByIndex(menu, idx + 1);
        break;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E04F8__FPv);
#ifdef SKIP_ASM
signed char func_001E04F8(void* self)
{
    return *(signed char*)((char*)self + 0x48);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0500__FPv);
#ifdef SKIP_ASM
int func_001E0500(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0508__FPv);
#ifdef SKIP_ASM
int func_001E0508(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0510);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469448[];

extern "C" void* func_001E0510(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469448;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0548__FPv);
#ifdef SKIP_ASM
// func_001E0548 is matched under the C++ symbol func_001E0548__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001E0548(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0570);
#ifdef SKIP_ASM
extern "C" int func_001E0570(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x74)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0578);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469378[];

extern "C" void* func_001E0578(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469378;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E05B0__FPv);
#ifdef SKIP_ASM
// func_001E05B0 is matched under the C++ symbol func_001E05B0__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001E05B0(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E05D8);
#ifdef SKIP_ASM
extern "C" int func_001E05D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x16C)));
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E05E0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" int func_001E05E0(void* unused, unsigned long bits) {
    int count;
    int i;
    int bit;

    count = 0;
    i = 0;
    do {
        bit = (bits >> i) & 1;
        i += 1;
        count += bit;
    } while (i < 0x40);
    return count;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0610);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_001E0610(void* self, int bit)
{
    *(long*)((char*)self + 0x158) |= 1L << bit;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0628);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_001E0628(void* self, int bit)
{
    *(long*)((char*)self + 0x158) &= ~(1L << bit);
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0648);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" int func_001E0648(void *arg0) {
    return (*(long *)((char*)(arg0) + (0x158))) == 0;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0658);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" int func_001E0658(void* self, int bit)
{
    return (*(long*)((char*)self + 0x158) & ~(1L << bit)) == 0;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0678);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" int func_001E0678(void* self, int bit)
{
    return (*(unsigned long*)((char*)self + 0x158) >> bit) & 1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0698);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" int func_001E0698(void *arg0) {
    int temp_2;
    int var_4;
    int var_5;

    var_5 = 0;
    var_4 = 0;
    do {
        temp_2 = ((unsigned long) (*(unsigned long *)((char*)(arg0) + (0x158))) >> var_4) & 1;
        var_4 += 1;
        var_5 += temp_2;
    } while (var_4 < 0x40);
    return var_5;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E06D0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" int func_001E06D0(void* self, int bit)
{
    return (*(unsigned long*)((char*)self + 0x160) >> bit) & 1;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E06F0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_001E06F0(void* self, int bit)
{
    *(long*)((char*)self + 0x160) |= 1L << bit;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0708);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" int func_001E0708(void *arg0) {
    int temp_2;
    int var_4;
    int var_5;

    var_5 = 0;
    var_4 = 0;
    do {
        temp_2 = ((unsigned long) (*(unsigned long *)((char*)(arg0) + (0x160))) >> var_4) & 1;
        var_4 += 1;
        var_5 += temp_2;
    } while (var_4 < 0x40);
    return var_5;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0740);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046DD60[];

extern "C" void func_001E0740(void* self, int flags)
{
    *(void***)self = D_0046DD60;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0770__FPv);
#ifdef SKIP_ASM
void func_001E0770(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0778__FPv);
#ifdef SKIP_ASM
void func_001E0778(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0780);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046DD60[];

extern "C" void func_001E0780(void* self, int flags)
{
    *(void***)self = D_0046DD60;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E07B0__FPv);
#ifdef SKIP_ASM
void func_001E07B0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E07B8__FPv);
#ifdef SKIP_ASM
void func_001E07B8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E07C0);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469248[];

extern "C" void* func_001E07C0(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469248;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E07F8__FPv);
#ifdef SKIP_ASM
// func_001E07F8 is matched under the C++ symbol func_001E07F8__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001E07F8(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0820);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern void* D_00469178[];

extern "C" void* func_001E0820(void* self)
{
    func_0039E2A0(self, 0);
    *(void***)((char*)self + 0x8) = D_00469178;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0858__FPv);
#ifdef SKIP_ASM
// func_001E0858 is matched under the C++ symbol func_001E0858__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_001E0858(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046D0D0;
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0880);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_00469068[];
extern int D_004A3E90;

extern "C" void* func_001E0880(void* self)
{
    func_001A8500(self, 0, 0);
    int g = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_00469068;
    *(int*)((char*)self + 0x6DC) = g;
    *(int*)((char*)self + 0x6D0) = 0;
    *(int*)((char*)self + 0x6E0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E08D0__FPv);
#ifdef SKIP_ASM
int func_001E08D0(void* self)
{
    return 0;
}
#endif

extern void* D_00468F50[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E08D8);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001E08D8(void *self) {
    func_001A8500(self, 0, 0);
    (*(void ***)((char*)(self) + (8))) = D_00468F50;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0918__FPv);
#ifdef SKIP_ASM
void* func_001E0918(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_00468F50;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0940__FPv);
#ifdef SKIP_ASM
int func_001E0940(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0948__FPv);
#ifdef SKIP_ASM
void func_001E0948(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0950);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_00468E38[];
extern int D_00441268[];

extern "C" void* func_001E0950(void* self)
{
    func_001A8500(self, 0, 0);
    *(void***)((char*)self + 0x8) = D_00468E38;
    *(int**)((char*)self + 0x6D8) = D_00441268;
    *(int*)((char*)self + 0x6D0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E09A0);
#ifdef SKIP_ASM
struct sVEntry001E09A0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern void* D_00468E38[];
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001E09A0(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00468E38;
    void* obj = *(void**)((char*)self + 0x20);
    sVEntry001E09A0* vt = *(sVEntry001E09A0**)((char*)obj + 8);
    vt[32].fn((char*)obj + vt[32].delta);
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0A00__FPv);
#ifdef SKIP_ASM
int func_001E0A00(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0A08);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_00468D20[];
extern int D_004A3E90;

extern "C" void* func_001E0A08(void* self)
{
    func_001A8500(self, 0, 0);
    int g = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_00468D20;
    *(int*)((char*)self + 0x6D0) = g;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0A50);
#ifdef SKIP_ASM
extern void* D_00468D20[];
extern "C" void cBXString__cBXString(void* self, int flags);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");
struct sVEntry001E0A50 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_001E0A50(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00468D20;
    void* obj = *(void**)((char*)self + 0x20);
    sVEntry001E0A50* vt = *(sVEntry001E0A50**)((char*)obj + 8);
    vt[32].fn((char*)obj + vt[32].delta);
    cBXString__cBXString((char*)self + 0x6D0, 2);
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0AB8__FPv);
#ifdef SKIP_ASM
int func_001E0AB8(void* self)
{
    return 0x1;
}
#endif

extern void* D_00468C10[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0AC0);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001E0AC0(void *self) {
    func_001A8500(self, 0, 0);
    (*(int *)((char*)(self) + (0x6DC))) = 0;
    (*(void ***)((char*)(self) + (8))) = D_00468C10;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0B00__FPv);
#ifdef SKIP_ASM
void* func_001E0B00(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_00468C10;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0B28);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_00468B00[];

extern "C" void* func_001E0B28(void* self)
{
    func_001A8500(self, 0, 0);
    *(int*)((char*)self + 0x6D0) = 0;
    *(void***)((char*)self + 0x8) = D_00468B00;
    *(int*)((char*)self + 0x6D4) = 0;
    *(int*)((char*)self + 0x6D8) = 0;
    *(int*)((char*)self + 0x6DC) = 0;
    *(int*)((char*)self + 0x6E4) = 0;
    *(int*)((char*)self + 0x6E8) = 0;
    *(int*)((char*)self + 0x6F0) = 0;
    *(int*)((char*)self + 0x6F4) = 0;
    *(int*)((char*)self + 0x6F8) = 0;
    *(int*)((char*)self + 0x6FC) = 0;
    *(int*)((char*)self + 0x700) = 0;
    *(int*)((char*)self + 0x704) = 0;
    *(int*)((char*)self + 0x710) = 0;
    *(int*)((char*)self + 0x714) = 0;
    *(int*)((char*)self + 0x718) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0BA0__FPv);
#ifdef SKIP_ASM
void func_001E0BA0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0BA8__FPv);
#ifdef SKIP_ASM
int func_001E0BA8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0BB0);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_004689F0[];

extern "C" void* func_001E0BB0(void* self)
{
    func_001A8500(self, 0, 0);
    *(void***)((char*)self + 0x8) = D_004689F0;
    *(int*)((char*)self + 0x6D0) = 0;
    *(int*)((char*)self + 0x6D4) = 0;
    *(int*)((char*)self + 0x6E4) = 0;
    *(int*)((char*)self + 0x6F4) = 2;
    *(int*)((char*)self + 0x6F8) = 0x1E;
    *(int*)((char*)self + 0x6FC) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C10__FPv);
#ifdef SKIP_ASM
int func_001E0C10(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C18__FPv);
#ifdef SKIP_ASM
int func_001E0C18(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C20__FPv);
#ifdef SKIP_ASM
void func_001E0C20(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C28__FPv);
#ifdef SKIP_ASM
int func_001E0C28(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C30);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_004688E0[];

extern "C" void* func_001E0C30(void* self)
{
    func_001A8500(self, 0, 0);
    *(int*)((char*)self + 0x6D0) = 0;
    *(void***)((char*)self + 0x8) = D_004688E0;
    *(int*)((char*)self + 0x6D4) = 0;
    *(int*)((char*)self + 0x6D8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C78__FPv);
#ifdef SKIP_ASM
int func_001E0C78(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C80__FPv);
#ifdef SKIP_ASM
void func_001E0C80(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C88__FPv);
#ifdef SKIP_ASM
int func_001E0C88(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C90__FPv);
#ifdef SKIP_ASM
int func_001E0C90(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0C98__FPv);
#ifdef SKIP_ASM
int func_001E0C98(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0CA0);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_004686C0[];
extern int D_004A3E90;

extern "C" void* func_001E0CA0(void* self)
{
    func_001A8500(self, 0, 0);
    int v = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_004686C0;
    *(int*)((char*)self + 0x6D4) = v;
    *(int*)((char*)self + 0x6D8) = v;
    *(int*)((char*)self + 0x6DC) = v;
    *(int*)((char*)self + 0x6EC) = 1;
    *(int*)((char*)self + 0x6F0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0CF8);
#ifdef SKIP_ASM
extern void* D_004686C0[];
extern "C" void cBXString__cBXString(void* self, int flags);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001E0CF8(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004686C0;
    cBXString__cBXString((char*)self + 0x6DC, 2);
    cBXString__cBXString((char*)self + 0x6D8, 2);
    cBXString__cBXString((char*)self + 0x6D4, 2);
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0D60__FPv);
#ifdef SKIP_ASM
int func_001E0D60(void* self)
{
    return 0;
}
#endif

extern void* D_004685B0[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0D68);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001E0D68(void *self) {
    func_001A8500(self, 0, 0);
    (*(void ***)((char*)(self) + (8))) = D_004685B0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0DA8__FPv);
#ifdef SKIP_ASM
void* func_001E0DA8(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_004685B0;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0DD0__FPv);
#ifdef SKIP_ASM
int func_001E0DD0(void* self)
{
    return 0;
}
#endif

extern void* D_004684A0[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0DD8);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);

extern "C" void *func_001E0DD8(void *self) {
    func_001A8500(self, 0, 0);
    (*(void ***)((char*)(self) + (8))) = D_004684A0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0E18__FPv);
#ifdef SKIP_ASM
void* func_001E0E18(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_004684A0;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0E40__FPv);
#ifdef SKIP_ASM
int func_001E0E40(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0E48);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_00468388[];

extern "C" void* func_001E0E48(void* self)
{
    func_001A8500(self, 0, 0);
    *(int*)((char*)self + 0x6D0) = 0;
    *(void***)((char*)self + 0x8) = D_00468388;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0E88__FPv);
#ifdef SKIP_ASM
void func_001E0E88(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0E90__FPv);
#ifdef SKIP_ASM
int func_001E0E90(void* self)
{
    return 0;
}
#endif

extern void* D_00468278[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0E98__FPv);
#ifdef SKIP_ASM
void* func_001E0E98(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_00468278;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0EC0__FPv);
#ifdef SKIP_ASM
void func_001E0EC0(void* self)
{
}
#endif

extern void* D_00468168[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0EC8__FPv);
#ifdef SKIP_ASM
void* func_001E0EC8(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_00468168;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0EF0__FPv);
#ifdef SKIP_ASM
int func_001E0EF0(void* self)
{
    return 0x1;
}
#endif

extern void* D_00468050[];
extern "C" void* func_001BEE78(void*);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0EF8);
#ifdef SKIP_ASM
extern "C" void* func_001BEE30(void* self, int);
extern void* D_00468050[];

extern "C" void* func_001E0EF8(void* self)
{
    func_001BEE30(self, 0);
    *(void***)((char*)self + 0x8) = D_00468050;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0F30__FPv);
#ifdef SKIP_ASM
void* func_001E0F30(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_00468050;
    return func_001BEE78(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0F58__FPv);
#ifdef SKIP_ASM
int func_001E0F58(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0F60);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_00467F28[];
extern int D_004A3E90;

extern "C" void* func_001E0F60(void* self)
{
    int unused[4];
    func_001A8500(self, 0, 0);
    int g = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_00467F28;
    *(int*)((char*)self + 0x6D0) = g;
    *(int*)((char*)self + 0x6D4) = g;
    *(int*)((char*)self + 0x6E0) = g;
    *(int*)((char*)self + 0x6E8) = 0;
    *(int*)((char*)self + 0x6EC) = 0;
    *(int*)((char*)self + 0x6F0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0FB8__FPv);
#ifdef SKIP_ASM
int func_001E0FB8(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0FC0);
#ifdef SKIP_ASM
class func_001E0FC0_cObj {
public:
    char pad[0x8];
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
};

extern "C" int func_001E0FC0(func_001E0FC0_cObj* self)
{
    self->v32();
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E0FF0);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void*, int, int);
extern void* D_00467E18[];
extern int D_004A3E90;

extern "C" void* func_001E0FF0(void* self)
{
    int unused[4];
    func_001A8500(self, 0, 0);
    int g = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_00467E18;
    *(int*)((char*)self + 0x6D0) = g;
    *(int*)((char*)self + 0x6DC) = 0;
    *(int*)((char*)self + 0x6E0) = 0;
    *(int*)((char*)self + 0x6E4) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1040__FPv);
#ifdef SKIP_ASM
int func_001E1040(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1048);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046DD60[];

extern "C" void func_001E1048(void* self, int flags)
{
    *(void***)self = D_0046DD60;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1078__FPv);
#ifdef SKIP_ASM
void func_001E1078(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1080__FPv);
#ifdef SKIP_ASM
void func_001E1080(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1088__FPv);
#ifdef SKIP_ASM
void func_001E1088(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1090);
#ifdef SKIP_ASM
struct sFlags_001E1090 {
    unsigned int pad : 27;
    unsigned int flag : 1;
};

extern "C" void func_001E1090(void* self, int e)
{
    ((sFlags_001E1090*)self)->flag = (e != 0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E10B8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046DD28[];

extern "C" void func_001E10B8(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_0046DD28;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E10E8__FPv);
#ifdef SKIP_ASM
void func_001E10E8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E10F0__FPv);
#ifdef SKIP_ASM
int func_001E10F0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E10F8__FPv);
#ifdef SKIP_ASM
int func_001E10F8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1100__FPv);
#ifdef SKIP_ASM
int func_001E1100(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1108);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046DBA8[];

extern "C" void func_001E1108(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046DBA8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1138__FPv);
#ifdef SKIP_ASM
int func_001E1138(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1140__FPv);
#ifdef SKIP_ASM
int func_001E1140(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1148__FPv);
#ifdef SKIP_ASM
int func_001E1148(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1150__FPv);
#ifdef SKIP_ASM
int func_001E1150(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1158__FPv);
#ifdef SKIP_ASM
int func_001E1158(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1160__FPv);
#ifdef SKIP_ASM
int func_001E1160(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1168__FPv);
#ifdef SKIP_ASM
int func_001E1168(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1170__FPv);
#ifdef SKIP_ASM
int func_001E1170(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1178__FPv);
#ifdef SKIP_ASM
int func_001E1178(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1180__FPv);
#ifdef SKIP_ASM
int func_001E1180(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1188__FPv);
#ifdef SKIP_ASM
int func_001E1188(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1190__FPv);
#ifdef SKIP_ASM
int func_001E1190(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1198__FPv);
#ifdef SKIP_ASM
int func_001E1198(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11A0__FPv);
#ifdef SKIP_ASM
int func_001E11A0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11A8__FPv);
#ifdef SKIP_ASM
int func_001E11A8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11B0__FPv);
#ifdef SKIP_ASM
int func_001E11B0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11B8__FPv);
#ifdef SKIP_ASM
int func_001E11B8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11C0__FPv);
#ifdef SKIP_ASM
int func_001E11C0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11C8__FPv);
#ifdef SKIP_ASM
int func_001E11C8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11D0__FPv);
#ifdef SKIP_ASM
int func_001E11D0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11D8__FPv);
#ifdef SKIP_ASM
int func_001E11D8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11E0__FPv);
#ifdef SKIP_ASM
int func_001E11E0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11E8__FPv);
#ifdef SKIP_ASM
int func_001E11E8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11F0__FPv);
#ifdef SKIP_ASM
int func_001E11F0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E11F8__FPv);
#ifdef SKIP_ASM
int func_001E11F8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1200__FPv);
#ifdef SKIP_ASM
int func_001E1200(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1208__FPv);
#ifdef SKIP_ASM
int func_001E1208(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1210__FPv);
#ifdef SKIP_ASM
int func_001E1210(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1218__FPv);
#ifdef SKIP_ASM
int func_001E1218(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1220__FPv);
#ifdef SKIP_ASM
int func_001E1220(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1228__FPv);
#ifdef SKIP_ASM
int func_001E1228(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1230__FPv);
#ifdef SKIP_ASM
int func_001E1230(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1238__FPv);
#ifdef SKIP_ASM
int func_001E1238(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1240__FPv);
#ifdef SKIP_ASM
int func_001E1240(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1248__FPv);
#ifdef SKIP_ASM
float func_001E1248(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1258__FPv);
#ifdef SKIP_ASM
float func_001E1258(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1268__FPv);
#ifdef SKIP_ASM
float func_001E1268(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1278__FPv);
#ifdef SKIP_ASM
int func_001E1278(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1280__FPv);
#ifdef SKIP_ASM
int func_001E1280(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1288__FPv);
#ifdef SKIP_ASM
int func_001E1288(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1290__FPv);
#ifdef SKIP_ASM
int func_001E1290(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1298__FPvi);
#ifdef SKIP_ASM
void func_001E1298(void* self, int val)
{
    *(char*)((char*)self + 0x4) = (char)val;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E12A0__FPv);
#ifdef SKIP_ASM
int func_001E12A0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E12A8__FPv);
#ifdef SKIP_ASM
void func_001E12A8(void* self)
{
}
#endif

extern "C" void* func_001DBC98(int, int);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E12B0__FPv);
#ifdef SKIP_ASM
void* func_001E12B0(void* self)
{
    return func_001DBC98(1, 0xffff);
}
#endif

extern "C" void* func_001DBC98(int, int);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E12D0__FPv);
#ifdef SKIP_ASM
void* func_001E12D0(void* self)
{
    return func_001DBC98(0, 0xffff);
}
#endif

INCLUDE_ASM("fe/fepopupmisc", func_001E12F0);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1450);
#ifdef SKIP_ASM
extern "C" void func_001E1450(void) {

}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E1458);
#ifdef SKIP_ASM
extern int D_004A20C0;
extern int D_004A20C8;
extern int D_004A20BC;
extern void* D_004A5B64;
extern "C" void func_001E12F0(void);
extern "C" void func_001E14C0(int type);

extern "C" void func_001E1458(void)
{
    if (D_004A20C0 == 0) {
        if (D_004A20C8 == 0) {
            D_004A20C8 = 1;
            func_001E12F0();
        }
        int t = *(int*)((char*)D_004A5B64 + 0x1C);
        if (t - D_004A20BC > 0x258) {
            func_001E14C0(1);
            D_004A20BC = t;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E14C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_001E3A30(void* self);
void func_001E1548(void* self);

struct sEntry14_14C0 {
    int type;
    char pad_0x4[0x14 - 0x4];
};
extern sEntry14_14C0 D_00441630_14C0[] __asm__("D_00441630");

extern "C" void func_001E14C0(int type)
{
    int i;
    for (i = 0; i < 0x3D; i++) {
        if (func_001E3A30((void*)i) == 0) {
            int t = D_00441630_14C0[i].type;
            if (t == type || t == 5) {
                func_001E1548((void*)i);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1548__FPv);
#ifdef SKIP_ASM
void func_001E1548(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1550);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
int cBENewPlayerInterface_getRiderCharID(void* self, int player);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E2FE0(int a, unsigned char b);
extern "C" void func_001E3A78(int a, int b);
extern "C" int func_001464D0(void* iface, int a, int ch, int b, int c);
extern "C" int func_00145EF0(void* iface, int a, int b, int c);
unsigned int BXrand();

extern "C" void func_001E1550(void)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        int ch = cBENewPlayerInterface_getRiderCharID(iface, func_00146E98(iface, 0));
        if (func_001E3A30((void*)1) == 0) {
            if (func_001464D0(iface, 0, ch, 0, 1) == 0 && func_00145EF0(iface, 0, 0xE, 4) == 0) {
                func_001E3A78(1, 1);
                if (ch != 3) {
                    func_001E2FE0(BXrand() % 3, 0);
                } else {
                    func_001E2FE0(BXrand() % 3 + 3, 0);
                }
            }
        } else if (func_001E3A30((void*)2) == 0) {
            if (func_001464D0(iface, 0, ch, 1, 1) == 0 && func_00145EF0(iface, 0, 0xF, 4) == 0) {
                func_001E3A78(2, 1);
                if (ch != 7) {
                    func_001E2FE0(BXrand() % 3 + 6, 0);
                } else {
                    func_001E2FE0(BXrand() % 3 + 9, 0);
                }
            }
        } else if (func_001E3A30((void*)3) == 0) {
            if (func_001464D0(iface, 0, ch, 2, 1) == 0 && func_00145EF0(iface, 0, 0x10, 4) == 0) {
                func_001E3A78(3, 1);
                if (ch != 8) {
                    func_001E2FE0(BXrand() % 3 + 0xC, 0);
                } else {
                    func_001E2FE0(BXrand() % 3 + 0xF, 0);
                }
            }
        }
        if (func_001E3A30((void*)4) == 0) {
            if (func_001464D0(iface, 0, ch, 0, 0) == 0 && func_00145EF0(iface, 0, 0xE, 5) == 0) {
                func_001E3A78(4, 1);
                if (ch != 3) {
                    func_001E2FE0(BXrand() % 3 + 0x12, 0);
                } else {
                    func_001E2FE0(BXrand() % 3 + 0x15, 0);
                }
            }
        } else if (func_001E3A30((void*)5) == 0) {
            if (func_001464D0(iface, 0, ch, 1, 0) == 0 && func_00145EF0(iface, 0, 0xF, 5) == 0) {
                func_001E3A78(5, 1);
                if (ch != 7) {
                    func_001E2FE0(BXrand() % 3 + 0x18, 0);
                } else {
                    func_001E2FE0(BXrand() % 3 + 0x1B, 0);
                }
            }
        } else if (func_001E3A30((void*)6) == 0) {
            if (func_001464D0(iface, 0, ch, 2, 0) == 0 && func_00145EF0(iface, 0, 0x10, 5) == 0) {
                func_001E3A78(6, 1);
                if (ch != 8) {
                    func_001E2FE0(BXrand() % 3 + 0x1E, 0);
                } else {
                    func_001E2FE0(BXrand() % 3 + 0x21, 0);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1A30);
#ifdef SKIP_ASM
extern "C" int func_001E1A30(int x, int y)
{
    switch (x) {
    case 0: return y == 0;
    case 1: return y == 1;
    case 2: return y == 2;
    case 3: return y == 3;
    case 4: return y == 4;
    case 5: return y == 5;
    case 6: return y == 6;
    case 7: return y == 7;
    case 8: return y == 8;
    case 9: return y == 9;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E1AD0);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void cMemMan_free(void* p);
unsigned int BXrand();
extern "C" int func_001E1A30(int kind, int arg);
extern "C" int func_001E3388(int id);
extern char D_0046DDF8[];

struct sPopupEntry18_1AD0 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
};
extern sPopupEntry18_1AD0 D_004C6C08_1AD0[] __asm__("D_004C6C08");

struct sRangeK1E1AD0 {
    int f0;
    int start;   // 0x4
    int count;   // 0x8
};

extern "C" int func_001E1AD0(sRangeK1E1AD0* r, int arg)
{
    int* list = (int*)operator_new_tag(r->count * 4, D_0046DDF8, 0x100, 0);
    int n = 0;
    int i;
    for (i = r->start; i < r->count + r->start; i++) {
        if (func_001E1A30(D_004C6C08_1AD0[i].fC, arg) == 0 && func_001E3388(i) == -1) {
            list[n++] = i;
        }
    }
    if (n == 0)
        return 0x100;
    int id = list[BXrand() % n];
    if (list != 0)
        cMemMan_free(list);
    return id;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1C10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
int cBENewPlayerInterface_getRiderCharID(void* self, int player);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E2FE0(int a, unsigned char b);

struct sEntry14_1C10 {
    int type;
    int f4;
    char pad_0x8[0x14 - 0x8];
};
extern sEntry14_1C10 D_00441630_1C10[] __asm__("D_00441630");



extern "C" void func_001E1C10(int which)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        int ch = cBENewPlayerInterface_getRiderCharID(iface, func_00146E98(iface, 0));
        int id;
        switch (which) {
        case 0: {
            if (func_001E3A30((void*)0x1C) != 0) {
                break;
            }
            if (func_001E3A30((void*)0x1D) != 0) {
                break;
            }
            sEntry14_1C10* r;
            if (ch != 3) {
                sEntry14_1C10* tbl = D_00441630_1C10;
                r = &tbl[0x1C];
            } else {
                sEntry14_1C10* tbl = D_00441630_1C10;
                r = &tbl[0x1D];
            }
            id = func_001E1AD0((sRangeK1E1AD0*)r, ch);
            if (id != 0x100) {
                func_001E2FE0(id, 0);
            }
            break;
        }
        case 1: {
            if (func_001E3A30((void*)0x1E) != 0) {
                break;
            }
            if (func_001E3A30((void*)0x1F) != 0) {
                break;
            }
            sEntry14_1C10* r;
            if (ch != 7) {
                sEntry14_1C10* tbl = D_00441630_1C10;
                r = &tbl[0x1E];
            } else {
                sEntry14_1C10* tbl = D_00441630_1C10;
                r = &tbl[0x1F];
            }
            id = func_001E1AD0((sRangeK1E1AD0*)r, ch);
            if (id != 0x100) {
                func_001E2FE0(id, 0);
            }
            break;
        }
        case 2: {
            if (func_001E3A30((void*)0x20) != 0) {
                break;
            }
            if (func_001E3A30((void*)0x21) != 0) {
                break;
            }
            sEntry14_1C10* r;
            if (ch != 8) {
                sEntry14_1C10* tbl = D_00441630_1C10;
                r = &tbl[0x20];
            } else {
                sEntry14_1C10* tbl = D_00441630_1C10;
                r = &tbl[0x21];
            }
            id = func_001E1AD0((sRangeK1E1AD0*)r, ch);
            if (id != 0x100) {
                func_001E2FE0(id, 0);
            }
            break;
        }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1DD0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int id, int a1);
static inline int IsBusy001E1DD0()
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    return n != 0 && n < 10;
}
// Queues the follow-up popup for an event kind unless one is already pending.
extern "C" void func_001E1DD0(void* self, int kind, int alt)
{
    if (IsBusy001E1DD0()) return;
    int id = 0;
    switch (kind) {
    case 6: id = func_001E3A30((void*)0x22) == 0 ? 0x28 : 0; break;
    case 7: id = func_001E3A30((void*)0x24) == 0 ? 0x2C : 0; break;
    case 8: id = func_001E3A30((void*)0x26) == 0 ? 0x30 : 0; break;
    case 9: id = func_001E3A30((void*)0x23) == 0 ? 0x2A : 0; break;
    case 10: id = func_001E3A30((void*)0x25) == 0 ? 0x2E : 0; break;
    case 11: id = func_001E3A30((void*)0x27) == 0 ? 0x32 : 0; break;
    }
    if (id != 0) {
        if (alt != 0) id++;
        func_001E3A78(id, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E1EB8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E20D0(int which, int flag);
extern "C" void func_001E2220(int which, int flag);

extern "C" void func_001E1EB8(void)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        if (func_001E3A30((void*)0x28) != 0) {
            func_001E2220(0, 0);
            func_001E3A78(0x28, 0);
        } else if (func_001E3A30((void*)0x29) != 0) {
            func_001E2220(0, 1);
            func_001E3A78(0x29, 0);
        }
        if (func_001E3A30((void*)0x2C) != 0) {
            func_001E2220(1, 0);
            func_001E3A78(0x2C, 0);
        } else if (func_001E3A30((void*)0x2D) != 0) {
            func_001E2220(1, 1);
            func_001E3A78(0x2D, 0);
        }
        if (func_001E3A30((void*)0x30) != 0) {
            func_001E2220(2, 0);
            func_001E3A78(0x30, 0);
        } else if (func_001E3A30((void*)0x31) != 0) {
            func_001E2220(2, 1);
            func_001E3A78(0x31, 0);
        }
        if (func_001E3A30((void*)0x2A) != 0) {
            func_001E20D0(0, 0);
            func_001E3A78(0x2A, 0);
        } else if (func_001E3A30((void*)0x2B) != 0) {
            func_001E20D0(0, 1);
            func_001E3A78(0x2B, 0);
        }
        if (func_001E3A30((void*)0x2E) != 0) {
            func_001E20D0(1, 0);
            func_001E3A78(0x2E, 0);
        } else if (func_001E3A30((void*)0x2F) != 0) {
            func_001E20D0(1, 1);
            func_001E3A78(0x2F, 0);
        }
        if (func_001E3A30((void*)0x32) != 0) {
            func_001E20D0(2, 0);
            func_001E3A78(0x32, 0);
        } else if (func_001E3A30((void*)0x33) != 0) {
            func_001E20D0(2, 1);
            func_001E3A78(0x33, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E20D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);

struct sEntry14_20D0 {
    int type;
    int f4;
    char pad_0x8[0x14 - 0x8];
};
extern sEntry14_20D0 D_00441630_20D0[] __asm__("D_00441630");

extern "C" void func_001E20D0(int which, int flag)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        switch (which) {
        case 0:
            if (func_001E3A30((void*)0x23) == 0) {
                sEntry14_20D0* tbl = D_00441630_20D0;
                if (flag) {
                    func_001E3A78(0x23, 1);
                    func_001E2FE0(tbl[0x23].f4 + 1, 0);
                } else {
                    func_001E2FE0(tbl[0x23].f4, 0);
                }
            }
            break;
        case 1:
            if (func_001E3A30((void*)0x25) == 0) {
                sEntry14_20D0* tbl = D_00441630_20D0;
                if (flag) {
                    func_001E3A78(0x25, 1);
                    func_001E2FE0(tbl[0x25].f4 + 1, 0);
                } else {
                    func_001E2FE0(tbl[0x25].f4, 0);
                }
            }
            break;
        case 2:
            if (func_001E3A30((void*)0x27) == 0) {
                sEntry14_20D0* tbl = D_00441630_20D0;
                if (flag) {
                    func_001E3A78(0x27, 1);
                    func_001E2FE0(tbl[0x27].f4 + 1, 0);
                } else {
                    func_001E2FE0(tbl[0x27].f4, 0);
                }
            }
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2220);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);

struct sEntry14_2220 {
    int type;
    int f4;
    char pad_0x8[0x14 - 0x8];
};
extern sEntry14_2220 D_00441630_2220[] __asm__("D_00441630");

extern "C" void func_001E2220(int which, int flag)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        switch (which) {
        case 0:
            if (func_001E3A30((void*)0x22) == 0) {
                sEntry14_2220* tbl = D_00441630_2220;
                if (flag) {
                    func_001E3A78(0x22, 1);
                    func_001E2FE0(tbl[0x22].f4 + 1, 0);
                } else {
                    func_001E2FE0(tbl[0x22].f4, 0);
                }
            }
            break;
        case 1:
            if (func_001E3A30((void*)0x24) == 0) {
                sEntry14_2220* tbl = D_00441630_2220;
                if (flag) {
                    func_001E3A78(0x24, 1);
                    func_001E2FE0(tbl[0x24].f4 + 1, 0);
                } else {
                    func_001E2FE0(tbl[0x24].f4, 0);
                }
            }
            break;
        case 2:
            if (func_001E3A30((void*)0x26) == 0) {
                sEntry14_2220* tbl = D_00441630_2220;
                if (flag) {
                    func_001E3A78(0x26, 1);
                    func_001E2FE0(tbl[0x26].f4 + 1, 0);
                } else {
                    func_001E2FE0(tbl[0x26].f4, 0);
                }
            }
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2370);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void func_001E3A78(int a, int b);

extern "C" void func_001E2370(int which)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        switch (which) {
        case 0:
            func_001E3A78(0x1C, 1);
            func_001E3A78(0x1D, 1);
            break;
        case 1:
            func_001E3A78(0x1E, 1);
            func_001E3A78(0x1F, 1);
            break;
        case 2:
            func_001E3A78(0x20, 1);
            func_001E3A78(0x21, 1);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2428);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);

extern "C" void func_001E2428(int which)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        switch (which) {
        case 0:
            if (func_001E3A30((void*)0x39) == 0) {
                func_001E3A78(0x39, 1);
                func_001E2FE0(0xFC, 0);
            }
            break;
        case 1:
            if (func_001E3A30((void*)0x3A) == 0) {
                func_001E3A78(0x39, 1);
                func_001E2FE0(0xFD, 0);
            }
            break;
        case 2:
            if (func_001E3A30((void*)0x3B) == 0) {
                func_001E3A78(0x3B, 1);
                func_001E2FE0(0xFE, 0);
            }
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2518);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);

extern "C" void func_001E2518(void)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0 && func_001E3A30((void*)0x3C) == 0) {
        func_001E3A78(0x3C, 1);
        func_001E2FE0(0xFF, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2578);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);

extern "C" void func_001E2578(void)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0 && func_001E3A30((void*)0x38) == 0) {
        func_001E3A78(0x38, 1);
        func_001E2FE0(0xFB, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E25D8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void func_001E2648(void* a, int b);
extern "C" void func_001E2828(void* a, int b);

extern "C" void func_001E25D8(int key, void* a1, int a2)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        switch (key) {
        case 4:
            func_001E2648(a1, a2);
            break;
        case 5:
            func_001E2828(a1, a2);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2648);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
int cBENewPlayerInterface_getRiderCharID(void* self, int player);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);
extern "C" void func_001E32C8(int type);

// PORT: the unit declares func_001E2648(void*, int); the first arg is really an int id.
extern "C" void func_001E2648_impl(int which, int flag) __asm__("func_001E2648");
extern "C" void func_001E2648_impl(int which, int flag)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        int ch = cBENewPlayerInterface_getRiderCharID(iface, func_00146E98(iface, 0));
        switch (which) {
        case 0xE:
            if (func_001E3A30((void*)0x16) != 0) {
                break;
            }
            func_001E32C8(1);
            func_001E32C8(0x16);
            if (flag == 0) {
                func_001E3A78(0x16, 1);
                if (ch != 3) {
                    func_001E2FE0(0x74, 0);
                } else {
                    func_001E2FE0(0x76, 0);
                }
            } else {
                if (ch != 3) {
                    func_001E2FE0(0x73, 0);
                } else {
                    func_001E2FE0(0x75, 0);
                }
            }
            break;
        case 0xF:
            if (func_001E3A30((void*)0x17) != 0) {
                break;
            }
            func_001E32C8(2);
            func_001E32C8(0x17);
            if (flag == 0) {
                func_001E3A78(0x17, 1);
                if (ch != 7) {
                    func_001E2FE0(0x78, 0);
                } else {
                    func_001E2FE0(0x7A, 0);
                }
            } else {
                if (ch != 7) {
                    func_001E2FE0(0x77, 0);
                } else {
                    func_001E2FE0(0x79, 0);
                }
            }
            break;
        case 0x10:
            if (func_001E3A30((void*)0x18) != 0) {
                break;
            }
            func_001E32C8(3);
            func_001E32C8(0x18);
            if (flag == 0) {
                func_001E3A78(0x18, 1);
                if (ch != 8) {
                    func_001E2FE0(0x7C, 0);
                } else {
                    func_001E2FE0(0x7E, 0);
                }
            } else {
                if (ch != 8) {
                    func_001E2FE0(0x7B, 0);
                } else {
                    func_001E2FE0(0x7D, 0);
                }
            }
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2828);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
int cBENewPlayerInterface_getRiderCharID(void* self, int player);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);
extern "C" void func_001E32C8(int type);

// PORT: the unit declares func_001E2828(void*, int); the first arg is really an int id.
extern "C" void func_001E2828_impl(int which, int flag) __asm__("func_001E2828");
extern "C" void func_001E2828_impl(int which, int flag)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy == 0) {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        int ch = cBENewPlayerInterface_getRiderCharID(iface, func_00146E98(iface, 0));
        switch (which) {
        case 0xE:
            if (func_001E3A30((void*)0x19) != 0) {
                break;
            }
            func_001E32C8(4);
            func_001E32C8(0x19);
            if (flag == 0) {
                func_001E3A78(0x19, 1);
                if (ch != 3) {
                    func_001E2FE0(0x80, 0);
                } else {
                    func_001E2FE0(0x82, 0);
                }
            } else {
                if (ch != 3) {
                    func_001E2FE0(0x7F, 0);
                } else {
                    func_001E2FE0(0x81, 0);
                }
            }
            break;
        case 0xF:
            if (func_001E3A30((void*)0x1A) != 0) {
                break;
            }
            func_001E32C8(5);
            func_001E32C8(0x1A);
            if (flag == 0) {
                func_001E3A78(0x1A, 1);
                if (ch != 7) {
                    func_001E2FE0(0x84, 0);
                } else {
                    func_001E2FE0(0x86, 0);
                }
            } else {
                if (ch != 7) {
                    func_001E2FE0(0x83, 0);
                } else {
                    func_001E2FE0(0x85, 0);
                }
            }
            break;
        case 0x10:
            if (func_001E3A30((void*)0x1B) != 0) {
                break;
            }
            func_001E32C8(6);
            func_001E32C8(0x1B);
            if (flag == 0) {
                func_001E3A78(0x1B, 1);
                if (ch != 8) {
                    func_001E2FE0(0x88, 0);
                } else {
                    func_001E2FE0(0x8A, 0);
                }
            } else {
                if (ch != 8) {
                    func_001E2FE0(0x87, 0);
                } else {
                    func_001E2FE0(0x89, 0);
                }
            }
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2A08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
int cBENewPlayerInterface_getRiderCharID(void* self, int player);
extern "C" int func_001E2B38(int charID);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);
unsigned int BXrand();

struct sEntry14_2A08 {
    int type;
    int start;   // 0x4
    int count;   // 0x8
    char pad_0xC[0x14 - 0xC];
};
extern sEntry14_2A08 D_00441630_2A08[] __asm__("D_00441630");

extern "C" void func_001E2A08(int charID, int level)
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = n != 0 && n < 10;
    if (busy)
        return;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    if (cBENewPlayerInterface_getRiderCharID(iface, func_00146E98(iface, 0)) == charID)
        return;
    int id = func_001E2B38(charID);
    sEntry14_2A08* e = &D_00441630_2A08[id];
    if (func_001E3A30((void*)id)) {
        if (level < 5)
            func_001E3A78(id, 0);
    } else if ((int)((BXrand() & 7) + 0xF) < level) {
        func_001E2FE0(e->start + BXrand() % e->count, 0);
        func_001E3A78(id, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2B38);
#ifdef SKIP_ASM
extern "C" int func_001E2B38(int x)
{
    switch (x) {
    case 0: return 0xC;
    case 1: return 0xD;
    case 2: return 0xE;
    case 3: return 0xF;
    case 4: return 0x10;
    case 5: return 0x11;
    case 6: return 0x12;
    case 7: return 0x13;
    case 8: return 0x14;
    case 9: return 0x15;
    case 10:
    default:
        return 0x3D;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2BB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_001E3A30(void* self);

struct sEntry14_2BB8 {
    int type;
    int f4;
    int count;
    int fC;
    int f10;
};
extern sEntry14_2BB8 D_00441630_2BB8[] __asm__("D_00441630");

extern "C" int func_001E2BB8(int type, int all)
{
    int total = 0;
    int i;
    for (i = 0; i < 0x3D; i++) {
        sEntry14_2BB8* e = &D_00441630_2BB8[i];
        if (e->type == type) {
            if (all != 0 || (e->f10 != 0 && func_001E3A30((void*)i) != 0)) {
                total += e->count;
            } else {
                total += 1;
            }
        }
    }
    return total;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2C60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sEntry14_2C60 {
    int type;
    int start;   // 0x4
    int count;   // 0x8
    int fC;
    int f10;
};
extern sEntry14_2C60 D_00441630_2C60[] __asm__("D_00441630");

extern "C" int func_001E2C60(int i)
{
    return D_00441630_2C60[i].count;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2C80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_001E3A30(void* self);

struct sEntry14_2C80 {
    int type;
    int first;
    int count;
    int fC;
    int f10;
};
extern sEntry14_2C80 D_00441630_2C80[] __asm__("D_00441630");

extern "C" int func_001E2C80(int type, int idx, int mode)
{
    int base = 0;
    int result = -1;
    int i;
    for (i = 0; i < 0x3D; i++) {
        sEntry14_2C80* e = &D_00441630_2C80[i];
        if (e->type == type) {
            int n;
            if (mode == 0 || e->f10 == 0 || func_001E3A30((void*)i) != 0) {
                n = e->count;
            } else {
                n = 1;
            }
            n += base;
            if (idx < n) {
                result = e->first + (idx - base);
                goto done;
            }
            base = n;
        }
    }
done:
    return result;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2D58);
#ifdef SKIP_ASM
struct sPopupEntry18 {
    int field_0x0;
    int field_0x4;
    char pad_0x8[0x18 - 0x8];
};
extern sPopupEntry18 D_004C6C08[];

struct sPopupEntry14 {
    char pad_0x0[0xC];
    int field_0xC;
    int field_0x10;
};
extern sPopupEntry14 D_00441630[];

extern "C" int func_001E2D58(int v, int i)
{
    sPopupEntry18* a = &D_004C6C08[i];
    sPopupEntry14* b = &D_00441630[a->field_0x4];
    return b->field_0xC == v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2D98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern sEntry14_2C60 D_00441630_2C60[] __asm__("D_00441630");

extern "C" int func_001E2D98(int v, int i)
{
    int* p = (int*)&D_00441630_2C60[0] + i * 5;
    return p[3] == v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2DC0);
#ifdef SKIP_ASM
extern "C" int func_001E2DC0(int idx)
{
    sPopupEntry18* ta = &D_004C6C08[idx];
    sPopupEntry14* target = &D_00441630[ta->field_0x4];
    int r = 0;
    int i = 0;
    while (i <= idx) {
        sPopupEntry18* a = &D_004C6C08[i];
        sPopupEntry14* e = &D_00441630[a->field_0x4];
        int start = *(int*)((char*)e + 4);
        int count = *(int*)((char*)e + 8);
        if (start + count - 1 < idx) {
            if (e->field_0xC == target->field_0xC) r += count;
            i += count;
        } else {
            if (e->field_0xC == target->field_0xC) r += idx - start + 1;
            break;
        }
    }
    return r - 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2E80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern sEntry14_2C60 D_00441630_2C60[] __asm__("D_00441630");

extern "C" int func_001E2E80(int i, int n)
{
    return D_00441630_2C60[i].start + n;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2EA0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0046DE60[];
extern char D_0046DE70[];
extern char D_0046DE80[];
extern char D_0046DE90[];
extern char D_0046DEA0[];
extern char D_0046DEB0[];
extern char D_0046DEC0[];
extern char D_0046DED0[];
extern char D_0046DEE0[];
extern char D_0046DEF0[];
extern char D_0046DF00[];
extern char D_0046DF10[];
extern char D_0046DF20[];

// Returns the string hash of the title for popup message kind (0-12), or 0.
extern "C" int func_001E2EA0(int kind)
{
    switch ((unsigned int)kind) {
    case 0:
        return GetHashValue32(D_0046DE60);
    case 1:
        return GetHashValue32(D_0046DE70);
    case 2:
        return GetHashValue32(D_0046DE80);
    case 3:
        return GetHashValue32(D_0046DE90);
    case 4:
        return GetHashValue32(D_0046DEA0);
    case 5:
        return GetHashValue32(D_0046DEB0);
    case 6:
        return GetHashValue32(D_0046DEC0);
    case 7:
        return GetHashValue32(D_0046DED0);
    case 8:
        return GetHashValue32(D_0046DEE0);
    case 9:
        return GetHashValue32(D_0046DEF0);
    case 10:
        return GetHashValue32(D_0046DF00);
    case 11:
        return GetHashValue32(D_0046DF10);
    case 12:
        return GetHashValue32(D_0046DF20);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E2FE0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern void* D_004A28A8;
extern char D_004A20D0[];
extern "C" void func_001E31B8(int idx);
extern "C" unsigned char func_001E3100(int i);
extern "C" void* func_0039F9D8(void* list, int hash);

struct sPopupListEntry_2FE0 {
    int id;
    unsigned char flag;
    char pad_0x5[3];
};
struct sPopupList_2FE0 {
    sPopupListEntry_2FE0 entries[25];
    int mask;
    unsigned char count;
};
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupList_2FE0* func_001E39F8_list2FE0() __asm__("func_001E39F8");

struct sPopupEntry18_2FE0 {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    char pad_0xC[0x18 - 0xC];
};
extern sPopupEntry18_2FE0 D_004C6C08_2FE0[] __asm__("D_004C6C08");

struct sVEntryK1E2FE0 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" void func_001E2FE0(int id, unsigned char flag)
{
    sPopupList_2FE0* t = func_001E39F8_list2FE0();
    if (t->count == 0x19)
        func_001E31B8(0);
    if (D_004C6C08_2FE0[id].field_0x8 == 1)
        flag = func_001E3100(id);
    t->entries[t->count].id = id;
    t->entries[t->count].flag = flag;
    t->mask &= ~(1 << t->count);
    char* o = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48);
    if (o != 0) {
        char* obj = (char*)func_0039F9D8(o + 0x18, GetHashValue32(D_004A20D0));
        if (obj != 0) {
            sVEntryK1E2FE0* vt = *(sVEntryK1E2FE0**)(obj + 8);
            vt[24].fn(obj + vt[24].delta, 8, 0);
        }
    }
    t->count++;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E3100);
#ifdef SKIP_ASM
extern "C" int func_001E2D58(int v, int i);
unsigned int BXrand();

extern "C" unsigned char func_001E3100(int i)
{
    unsigned char r = 0xFF;
    if (func_001E2D58(3, i)) {
        r = BXrand() % 10;
    } else if (func_001E2D58(5, i)) {
        r = BXrand() % 11;
    } else if (func_001E2D58(8, i)) {
        r = BXrand() % 4;
    } else if (func_001E2D58(4, i)) {
        r = BXrand() % 10;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E31B8);
#ifdef SKIP_ASM
struct sPopupListEntry_31B8 {
    int id;
    unsigned char field_0x4;
    char pad_0x5[3];
};
struct sPopupList_31B8 {
    sPopupListEntry_31B8 entries[25];
    int mask;
    unsigned char count;
};
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupList_31B8* func_001E39F8_list31B8() __asm__("func_001E39F8");

extern "C" void func_001E31B8(int idx)
{
    sPopupList_31B8* t = func_001E39F8_list31B8();
    int i;
    for (i = idx; i < t->count - 1; i++) {
        t->entries[i] = t->entries[i + 1];
        int bit = 1 << (i + 1);
        if (t->mask & bit) {
            t->mask |= 1 << i;
        } else {
            t->mask &= ~(1 << i);
        }
    }
    t->count--;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3268);
#ifdef SKIP_ASM
struct sPopupListEntry {
    int id;
    unsigned char field_0x4;
    char pad_0x5[3];
};
struct sPopupList {
    sPopupListEntry entries[25];
    int mask;
    unsigned char count;
};
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupList* func_001E39F8_list() __asm__("func_001E39F8");
extern "C" void func_001E31B8(int idx);

extern "C" void func_001E3268(int id)
{
    sPopupList* t = func_001E39F8_list();
    int i;
    for (i = 0; i < t->count; i++) {
        if (id == t->entries[i].id) {
            func_001E31B8(i);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E32C8);
#ifdef SKIP_ASM
struct sPopupEntry18_32C8 {
    int field_0x0;
    int field_0x4;
    char pad_0x8[0x18 - 0x8];
};
extern sPopupEntry18_32C8 D_004C6C08_32C8[] __asm__("D_004C6C08");
struct sPopupListEntry_32C8 {
    int id;
    unsigned char field_0x4;
    char pad_0x5[3];
};
struct sPopupList_32C8 {
    sPopupListEntry_32C8 entries[25];
    int mask;
    unsigned char count;
};
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupList_32C8* func_001E39F8_list32C8() __asm__("func_001E39F8");
extern "C" void func_001E31B8(int idx);

extern "C" void func_001E32C8(int type)
{
    int n = 0;
    int j = 0;
    sPopupList_32C8* t = func_001E39F8_list32C8();
    for (; n < t->count; n++) {
        sPopupEntry18_32C8* a = &D_004C6C08_32C8[t->entries[j].id];
        if (type == a->field_0x4) {
            func_001E31B8(j);
        } else {
            j++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3388);
#ifdef SKIP_ASM
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupList* func_001E39F8_list() __asm__("func_001E39F8");

extern "C" int func_001E3388(int id)
{
    sPopupList* t = func_001E39F8_list();
    int i;
    for (i = 0; i < t->count; i++) {
        if (id == t->entries[i].id) {
            return i;
        }
    }
    return -1;
}
#endif

extern "C" void* func_001E39F8(void* self);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E33E8__FPv);
#ifdef SKIP_ASM
unsigned char func_001E33E8(void* self)
{
    return *(unsigned char*)((char*)func_001E39F8(self) + 0xcc);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3408);
#ifdef SKIP_ASM
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupList* func_001E39F8_list() __asm__("func_001E39F8");

extern "C" int func_001E3408()
{
    sPopupList* t = func_001E39F8_list();
    int n = 0;
    int i;
    for (i = 0; i < t->count; i++) {
        int bit = 1 << i;
        if (!(t->mask & bit)) {
            n++;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3460);
#ifdef SKIP_ASM
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupList* func_001E39F8_list() __asm__("func_001E39F8");
extern "C" int func_001E3620(int idx);

extern "C" int func_001E3460(int* out)
{
    sPopupList* t = func_001E39F8_list();
    int i;
    for (i = 0; i < t->count; i++) {
        int bit = 1 << i;
        if (!(t->mask & bit)) {
            *out = i;
            return func_001E3620(i);
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E34D8);
#ifdef SKIP_ASM
extern "C" int func_001E34D8(int i)
{
    sPopupEntry18* a = &D_004C6C08[i];
    int n = i + 1;
    sPopupEntry18* b = &D_004C6C08[n];
    int r = -1;
    if (b->field_0x4 == a->field_0x4) {
        r = n;
    }
    return r;
}
#endif
//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3510);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001475C0(void* iface, int a1, int a2);
extern int D_004A20CC;
extern signed char D_00535C11[];

extern "C" void func_001E3510(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 0) {
        D_004A20CC = 0;
        func_001475C0(cBE_getInterface_Fv(cBE_getBE(), 1), 0, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3570);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00147580(void* iface, int a1);
extern signed char D_00535BC8[];

extern "C" int func_001E3570(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BC8[0x49] != 0) {
        return 0;
    }
    if (D_00535BC8[0x4A] == 6 || D_00535BC8[0x4A] == 9) {
        return 0;
    }
    return func_00147580(cBE_getInterface_Fv(cBE_getBE(), 1), 0) == 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E35F0);
#ifdef SKIP_ASM
extern "C" void* func_001E39F8(void* self);

extern "C" int func_001E35F0(void* self)
{
    return (int)func_001E39F8(self) + ((int)self << 3);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3620);
#ifdef SKIP_ASM
struct sPopupEntry8 {
    int field_0x0;
    unsigned char field_0x4;
    char pad_0x5[3];
};
struct sPopupTable8 {
    sPopupEntry8 entries[1];
};
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupTable8* func_001E39F8_get() __asm__("func_001E39F8");

extern "C" int func_001E3620(int idx)
{
    return func_001E39F8_get()->entries[idx].field_0x0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3650);
#ifdef SKIP_ASM
// PORT: unit declares func_001E39F8(void*), but its body takes no arguments
extern "C" sPopupTable8* func_001E39F8_get() __asm__("func_001E39F8");

extern "C" unsigned char func_001E3650(int idx)
{
    return func_001E39F8_get()->entries[idx].field_0x4;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3680);
#ifdef SKIP_ASM
// PORT: func_001E33E8 is declared (void*) but never reads its argument; called here with none
unsigned char func_001E33E8_noarg() __asm__("func_001E33E8__FPv");
extern int D_004A20C4;

extern "C" unsigned char func_001E3680(int id)
{
    if (D_004A20C4 != 0) {
        return id;
    }
    int n1 = func_001E2BB8(4, 0);
    int n2 = func_001E33E8_noarg();
    int i;
    for (i = 0; i < n1 + n2; i++) {
        int k = i + 1;
        int idx = n2 - k;
        if (idx >= 0) {
            if (func_001E3620(idx) == id) {
                return i;
            }
        } else if (idx + n1 >= 0) {
            if (func_001E2C80(4, ~idx, 1) == id) {
                return i;
            }
        }
    }
    return 0xFF;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3760);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int cBENewPlayerInterface_isPeakLocked1(void* self, int rider, int peak);
extern "C" int func_001509F8(void* self, int rider);
int func_001588B0(void* self, int a1);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);

extern "C" void func_001E3760(int rider, int amt)
{
    if (rider == 0) {
        void* econ = cBE_getInterface_Fv(cBE_getBE(), 0xB);
        void* rew = cBE_getInterface_Fv(cBE_getBE(), 0xD);
        void* pl = cBE_getInterface_Fv(cBE_getBE(), 1);
        if (cBENewPlayerInterface_isPeakLocked1(pl, 0, 1)) {
            if ((unsigned)(func_001509F8(econ, 0) + amt) >= (unsigned)func_001588B0(rew, 0) && func_001E3A30((void*)0x34) == 0) {
                func_001E3A78(0x34, 1);
                func_001E2FE0(0xF7, 0);
            }
        }
        if (cBENewPlayerInterface_isPeakLocked1(pl, rider, 2)) {
            if ((unsigned)(func_001509F8(econ, rider) + amt) >= (unsigned)func_001588B0(rew, 1) && func_001E3A30((void*)0x35) == 0) {
                func_001E3A78(0x35, 1);
                func_001E2FE0(0xF8, 0);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E38B8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
int cBENewPlayerInterface_getRiderCharID(void* self, int player);
extern "C" int cBENewPlayerInterface_isPeakLocked1(void* self, int rider, int peak);
extern "C" int func_00157BF0(void* self, int rider, int a, int b, int c);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E2FE0(int a, unsigned char b);

extern "C" void func_001E38B8(int player)
{
    if (player == 0) {
        void* stats = cBE_getInterface_Fv(cBE_getBE(), 0xD);
        void* np = cBE_getInterface_Fv(cBE_getBE(), 1);
        int charID = cBENewPlayerInterface_getRiderCharID(np, func_00146E98(np, 0));
        if (cBENewPlayerInterface_isPeakLocked1(np, player, 1)) {
            if (func_00157BF0(stats, player, charID, 0, 2) && func_001E3A30((void*)0x36) == 0) {
                func_001E3A78(0x36, 1);
                func_001E2FE0(0xF9, 0);
            }
        }
        if (cBENewPlayerInterface_isPeakLocked1(np, player, 2)) {
            if (func_00157BF0(stats, player, charID, 1, 2) && func_001E3A30((void*)0x37) == 0) {
                func_001E3A78(0x37, 1);
                func_001E2FE0(0xFA, 0);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E39F8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00147908(void* iface, int a1);

extern "C" void* func_001E39F8(void* self)
{
    return func_00147908(cBE_getInterface_Fv(cBE_getBE(), 1), 0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3A30);
#ifdef SKIP_ASM
extern "C" int func_00147980(void* iface, int a1, void* a2);
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");

extern "C" int func_001E3A30(void* self)
{
    return func_00147980(cBE_getInterface_Fv(cBE_getBE(), 1), 0, self) != 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3A78);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00147A30(void* iface, int a1, int a2, int a3);

extern "C" void func_001E3A78(int a, int b)
{
    func_00147A30(cBE_getInterface_Fv(cBE_getBE(), 1), 0, a, b);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3AC8);
#ifdef SKIP_ASM
extern char* D_004A28A0;

class cSnd_3AC8 {
public:
    virtual void v01();
    virtual void v02();
    virtual int getState();
    virtual void setVolume(int ch, float v);
};

// PORT: uses g++'s >? (max) operator.
extern "C" void func_001E3AC8(int idx, float x, float y)
{
    signed char i = idx;
    float t = x * 0.9133333563804626f - 18.518518447875977f;
    float a = 0.0f;
    if (t >= 0.0f) {
        a = t;
    }
    y = y * 0.9916666746139526f;
    cSnd_3AC8* s = 0;
    if (D_004A28A0 != 0) {
        s = *(cSnd_3AC8**)(D_004A28A0 + (i << 2) + 0x2EEC);
    }
    if (s->getState() == 2) {
        s->setVolume(0, ((y - 0.5f) * 0.009999999776482582f >? (a - 2.0f) / 972.2222290039062f) >? 0.0f);
        s->setVolume(1, ((y - 70.0f) * 0.0062500000931322575f >? (a - 100.0f) / 5000.0f) >? 0.0f);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3C00);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* engine);
extern "C" int func_00398380(void* self, int hash);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E3A78(int a, int b);
int GetHashValue32(char* str);
extern void* D_00474E08[];
extern void* D_00474318[];
extern unsigned short D_004A2088[];
extern char D_004A20D8[];
extern char D_0046DF68[];
extern char D_0046DF78[];
extern int D_004A20CC;

struct sObj_3C00 {
    char pad_0x0[0x9C];
    int a[8];   // 0x9C
    int b[8];   // 0xBC
    int c[8];   // 0xDC
    int d[8];   // 0xFC
    int e[8];   // 0x11C
    char pad_0x13C[0x164 - 0x13C];
    int h164;   // 0x164
    int h168;   // 0x168
    int h16C;   // 0x16C
};

extern "C" void* func_001E3C00(void* self, void* engine, int a2)
{
    sObj_3C00* o = (sObj_3C00*)self;
    func_0039E2A0(self, engine);
    *(int*)((char*)self + 0x98) = a2;
    *(void***)((char*)self + 0x8) = D_00474E08;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(unsigned short*)((char*)self + 0x58) = D_004A2088[0];
    *(void***)((char*)self + 0x8) = D_00474318;
    int i;
    for (i = 0; i < 8; i++) {
        o->a[i] = 0;
        o->b[i] = 0;
        o->c[i] = 0;
        o->d[i] = 0;
        o->e[i] = 0;
    }
    *(int*)((char*)self + 0x13C) = 0;
    *(int*)((char*)self + 0x140) = 0;
    *(int*)((char*)self + 0x144) = 0;
    *(int*)((char*)self + 0x14C) = 0;
    *(int*)((char*)self + 0x150) = 0;
    *(int*)((char*)self + 0x154) = 0;
    *(int*)((char*)self + 0x158) = 0;
    *(int*)((char*)self + 0x15C) = 0;
    *(int*)((char*)self + 0x160) = 0;
    {
        char* eng = *(char**)((char*)self + 0x10);
        int h = GetHashValue32(D_004A20D8);
        o->h164 = func_00398380(eng + 0x58, h);
    }
    {
        char* eng = *(char**)((char*)self + 0x10);
        int h = GetHashValue32(D_0046DF68);
        o->h168 = func_00398380(eng + 0x58, h);
    }
    {
        char* eng = *(char**)((char*)self + 0x10);
        int h = GetHashValue32(D_0046DF78);
        o->h16C = func_00398380(eng + 0x58, h);
    }
    if (~D_004A20CC != 0) {
        if (func_001E3A30((void*)7) != 0)
            *(int*)((char*)self + 0x18) = 0;
        else
            *(int*)((char*)self + 0x18) = 1;
        func_001E3A78(7, 1);
    } else {
        *(int*)((char*)self + 0x18) = 2;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3D58);
#ifdef SKIP_ASM
// PORT: func_001E33E8 is declared (void*) but never reads its argument; called here with none
unsigned char func_001E33E8_noarg() __asm__("func_001E33E8__FPv");
extern "C" void func_0020A380(void* self);
extern "C" void cOVStateManager_addPDATemplate();
extern "C" void func_001E48B0(void*);
extern "C" void func_001E4758(void*);
extern "C" void func_001E4458(void*);
extern "C" void func_001E4658(void*);
extern char D_0046DF88[];

extern "C" void func_001E3D58(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046DF88), 0);
    *(void**)((char*)self + 0x17C) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    int mode = *(int*)((char*)self + 0x18);
    if (mode == 0) {
        goto add;
    }
    if (mode == 1) {
    add:
        cOVStateManager_addPDATemplate();
    }
    *(int*)((char*)self + 0x174) = 0;
    int n = func_001E33E8_noarg();
    n += func_001E2BB8(4, 1);
    func_0039B760(*(void**)((char*)self + 0x144), (unsigned char)n);
    func_001E48B0(self);
    func_001E4758(self);
    func_001E4458(self);
    func_001E4658(self);
    D_004A20C0 = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3E30);
#ifdef SKIP_ASM
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_0020D190(void);
extern "C" void func_0020A430(void* self);
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_004428F0[];

extern "C" void func_001E3E30(void* self)
{
    int s = *(int*)((char*)self + 0x18);
    if (s == 1) {
        func_001E3A78(7, 0);
        func_0020D190();
        D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
    } else if (s == 0) {
        func_001E3A78(7, 1);
        func_0020D190();
        D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
    }
    func_0020A430(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E3EC0);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char* D_004A20A8;
extern char* D_004A2098;
extern char D_004A20E0[];
extern char D_004A20E8[];
extern char D_0046DFA0[];
extern char D_0046DFB8[];
extern char D_0046DFD0[];
extern char D_0046DFE0[];
extern char D_0046DFF0[];
extern char D_004A20F0[];
extern char D_0046E000[];
extern char D_0046E010[];
extern char D_0046E020[];
extern char D_004A20F8[];
extern char D_0046E030[];
extern char D_0046E040[];

struct sVEntry_1E3EC0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sPopup_1E3EC0 {
    char pad0[0x9C];
    void* a9C[8];       // 0x9C
    void* aBC[8];       // 0xBC
    void* aDC[8];       // 0xDC
    void* aFC[8];       // 0xFC
    void* a11C[8];      // 0x11C
    void* f13C;         // 0x13C
    void* f140;         // 0x140
    void* f144;         // 0x144
    void* f148;         // 0x148
    void* f14C;         // 0x14C
    void* f150;         // 0x150
    void* f154;         // 0x154
    void* f158;         // 0x158
    void* f15C;         // 0x15C
    void* f160;         // 0x160
};

extern "C" void func_001E3EC0(sPopup_1E3EC0* self, void* w)
{
    char buf[32];
    int h = *(int*)((char*)w + 0x38);
    if (h == GetHashValue32(D_004A20A8))
        self->f14C = w;
    else if (h == GetHashValue32(D_004A20E0))
        self->f150 = w;
    if (h == GetHashValue32(D_004A2098)) {
        self->f154 = w;
        return;
    }
    if (h == GetHashValue32(D_004A20E8)) {
        self->f158 = w;
        return;
    }
    if (h == GetHashValue32(D_0046DFA0)) {
        self->f13C = w;
        return;
    }
    if (h == GetHashValue32(D_0046DFB8)) {
        self->f140 = w;
        return;
    }
    if (h == GetHashValue32(D_0046DFD0)) {
        sVEntry_1E3EC0* vt = *(sVEntry_1E3EC0**)((char*)w + 8);
        vt[9].fn((char*)w + vt[9].delta, 0);
        return;
    }
    if (h == GetHashValue32(D_0046DFE0)) {
        self->f144 = w;
        return;
    }
    if (h == GetHashValue32(D_0046DFF0)) {
        self->f160 = w;
        return;
    }
    if (h == GetHashValue32(D_004A20F0)) {
        self->f15C = w;
        return;
    }
    if (h == GetHashValue32(D_0046E000)) {
        self->f148 = w;
        sVEntry_1E3EC0* vt = *(sVEntry_1E3EC0**)((char*)w + 8);
        vt[9].fn((char*)w + vt[9].delta, 0);
        return;
    }
    for (int i = 0; i < 8; i++) {
        sprintf(buf, D_0046E010, i);
        if (h == GetHashValue32(buf)) {
            self->a9C[i] = w;
            break;
        }
        sprintf(buf, D_0046E020, i);
        if (h == GetHashValue32(buf)) {
            self->aBC[i] = w;
            return;
        }
        sprintf(buf, D_004A20F8, i);
        if (h == GetHashValue32(buf)) {
            self->aDC[i] = w;
            return;
        }
        sprintf(buf, D_0046E030, i);
        if (h == GetHashValue32(buf)) {
            self->aFC[i] = w;
            sVEntry_1E3EC0* vt = *(sVEntry_1E3EC0**)((char*)w + 8);
            vt[27].fn((char*)w + vt[27].delta, 1);
            return;
        }
        sprintf(buf, D_0046E040, i);
        if (h == GetHashValue32(buf)) {
            self->a11C[i] = w;
            return;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E4168);
#ifdef SKIP_ASM
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" unsigned char func_001E3680(int id);
extern "C" void func_001E50C8(void* self, int a1, int a2);

struct sVEntry001E4168 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001E4168(void* self)
{
    int state = *(int*)((char*)self + 0x18);
    if (state == 0) {
        goto reset;
    }
    if (state == 1) {
    reset:
        cUIMenu_setSelectedByIndex(*(void**)((char*)self + 0x144), func_001E3680(0x25));
        void* menu = *(void**)((char*)self + 0x144);
        sVEntry001E4168* vt = *(sVEntry001E4168**)((char*)menu + 8);
        vt[7].fn((char*)menu + vt[7].delta, 1);
        func_001E50C8(self, 0x25, -1);
    } else {
        void* menu = *(void**)((char*)self + 0x144);
        sVEntry001E4168* vt = *(sVEntry001E4168**)((char*)menu + 8);
        vt[7].fn((char*)menu + vt[7].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4200);
#ifdef SKIP_ASM
struct sPopupEntry18_4200 {
    int field_0x0;
    int id;                         // 0x4
    char pad_0x8[0x10];
};
extern sPopupEntry18_4200 D_004C6C08_4200[] __asm__("D_004C6C08");

struct sPopupEntry14_4200 {
    int type;
    int start;                      // 0x4
    int count;                      // 0x8
    int field_0xC;
    int enabled;                    // 0x10
};
extern sPopupEntry14_4200 D_00441630_4200[] __asm__("D_00441630");

struct sVEntry001E4200 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* screen, int hash);
extern char D_0046E050[];
extern int D_004A20C0;

// PORT: func_001E33E8 is declared (void*) but never reads its argument; called here with none
unsigned char func_001E33E8_noarg() __asm__("func_001E33E8__FPv");
// PORT: func_001E3A30 is declared int; its result is used as a bool here
extern "C" bool func_001E3A30_b(int id) __asm__("func_001E3A30");
extern "C" int func_001E3620(int idx);
extern "C" void func_001E3A78(int a, int b);
extern "C" void func_001E48B0(void*);
extern "C" void func_001E4458(void*);
extern "C" void func_001E4658(void*);
extern "C" void func_001E50C8(void* self, int a1, int a2);
extern "C" void func_001E5148(void* self, int idx);

extern "C" void func_001E4200(void* self, void* widget, unsigned int event)
{
    if (widget == 0) {
        return;
    }
    sPopupList* list = func_001E39F8_list();
    int n1 = func_001E2BB8(4, 1);
    int n2 = func_001E33E8_noarg();
    switch (event) {
    case 5:
        if (n1 + n2 > 0) {
            int k = *(unsigned char*)(*(char**)((char*)self + 0x144) + 0x95);
            int idx = n2 - k - 1;
            if (idx >= 0) {
                int id = func_001E3620(idx);
                list->mask |= 1 << idx;
                func_001E50C8(self, id, k + 1);
            } else if (idx + n1 >= 0) {
                int w = *(int*)((char*)widget + 0x18);
                sPopupEntry18_4200* a = &D_004C6C08_4200[w];
                sPopupEntry14_4200* e = &D_00441630_4200[a->id];
                if (e->enabled != 0 && w == e->start) {
                    func_001E3A78(a->id, !func_001E3A30_b(a->id));
                    func_001E48B0(self);
                    func_001E4658(self);
                    func_001E4458(self);
                } else {
                    func_001E50C8(self, w, k + 1);
                }
            }
        }
        break;
    case 7:
        *(int*)((char*)self + 0x170) = 0;
        if (n2 > 0) {
            int idx = n2 - *(unsigned char*)(*(char**)((char*)self + 0x144) + 0x95) - 1;
            if (idx >= 0) {
                func_001E5148(self, idx);
                *(int*)((char*)self + 0x170) = 1;
            }
            func_001E4458(self);
        }
        break;
    case 6: {
        int f = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x17C), GetHashValue32(D_0046E050));
        if (f != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x17C), f, 1);
        }
        func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
        D_004A20C0 = 0;
        break;
    }
    case 1: {
        int i;
        for (i = 0; i < 8; i++) {
            void* o = ((void**)((char*)self + 0xFC))[i];
            sVEntry001E4200* vt = *(sVEntry001E4200**)((char*)o + 8);
            vt[5].fn((char*)o + vt[5].delta, 0);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4458);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
// PORT: func_001E33E8 is declared (void*) but never reads its argument; called here with none
unsigned char func_001E33E8_noarg() __asm__("func_001E33E8__FPv");
extern "C" int func_001E2C80(int type, int idx, int mode);
extern "C" int func_001E3A30(void* self);
extern "C" void func_001E4840(void* self, void* obj);
extern "C" void func_001E4878(void* self, void* obj);
extern char D_0046E060[];
extern char D_0046E070[];
extern char D_0046E080[];

struct sEntry18_4458 {
    int field_0x0;
    int field_0x4;
    char pad_0x8[0x18 - 0x8];
};
extern sEntry18_4458 D_004C6C08_4458[] __asm__("D_004C6C08");
struct sEntry14_4458 {
    int field_0x0;
    int field_0x4;
    char pad_0x8[0x14 - 0x8];
};
extern sEntry14_4458 D_00441630_4458[] __asm__("D_00441630");

extern "C" void func_001E4458(void* self)
{
    int base = *(unsigned char*)(*(char**)((char*)self + 0x144) + 0x95);
    int diff = func_001E33E8_noarg() - base;
    if (diff - 1 >= 0) {
        func_001E4878(self, *(void**)((char*)self + 0x14C));
        func_001E4878(self, *(void**)((char*)self + 0x150));
        if (*(cUIText**)((char*)self + 0x158) != 0)
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x158), GetHashValue32(D_0046E060));
    } else {
        func_001E4840(self, *(void**)((char*)self + 0x14C));
        func_001E4840(self, *(void**)((char*)self + 0x150));
        if (*(cUIText**)((char*)self + 0x158) != 0) {
            int id = func_001E2C80(4, -diff, 1);
            sEntry18_4458* a = &D_004C6C08_4458[id];
            int t = a->field_0x4;
            sEntry14_4458* b = &D_00441630_4458[t];
            if (id == b->field_0x4) {
                if (func_001E3A30((void*)t))
                    cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x158), GetHashValue32(D_0046E070));
                else
                    cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x158), GetHashValue32(D_0046E080));
            } else {
                cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x158), GetHashValue32(D_0046E060));
            }
        }
    }
}
#endif

INCLUDE_ASM("fe/fepopupmisc", func_001E4578);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4610);
#ifdef SKIP_ASM
extern "C" void func_001E48B0(void*);
extern "C" void func_001E4758(void*);
extern "C" void func_0039F190(void* self, int a1);

extern "C" void func_001E4610(void* self, int a1, int a2)
{
    if (a2 == 0x14) {
        func_001E48B0(self);
        func_001E4758(self);
        func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4658);
#ifdef SKIP_ASM
// PORT: func_001E33E8 is declared (void*) but never reads its argument; called here with none
unsigned char func_001E33E8_noarg() __asm__("func_001E33E8__FPv");
extern "C" int func_001E2BB8(int type, int all);
extern int D_004A20C4;

struct sVEntryK1E4658 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001E4658(void* self)
{
    if (*(int*)((char*)self + 0x174) == 0) {
        char* o = *(char**)((char*)self + 0x15C);
        sVEntryK1E4658* vt = *(sVEntryK1E4658**)(o + 8);
        vt[9].fn(o + vt[9].delta, 0);
    } else {
        char* o = *(char**)((char*)self + 0x15C);
        sVEntryK1E4658* vt = *(sVEntryK1E4658**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
    }
    int n;
    if (D_004A20C4 != 0) {
        n = func_001E33E8_noarg();
        n += func_001E2BB8(4, 1);
    } else {
        n = func_001E33E8_noarg();
        n += func_001E2BB8(4, 0);
    }
    if (*(int*)((char*)self + 0x174) + 8 >= n) {
        char* o = *(char**)((char*)self + 0x160);
        sVEntryK1E4658* vt = *(sVEntryK1E4658**)(o + 8);
        vt[9].fn(o + vt[9].delta, 0);
    } else {
        char* o = *(char**)((char*)self + 0x160);
        sVEntryK1E4658* vt = *(sVEntryK1E4658**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4758);
#ifdef SKIP_ASM
// PORT: func_001E33E8 is declared (void*) but never reads its argument; called here with none
unsigned char func_001E33E8_noarg() __asm__("func_001E33E8__FPv");
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" void func_003A0E90(void* text, void* p);
extern void* D_004A28A8;
extern char D_0046E0A8[];
extern char D_0046E0C0[];

struct sVEntry001E4758 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern "C" void func_001E4758(void* self)
{
    unsigned short buf[0x38];
    if (*(void**)((char*)self + 0x13C) != 0) {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry001E4758* vt = *(sVEntry001E4758**)(o + 4);
        unsigned short* fmt = vt[4].fn(o + vt[4].delta, GetHashValue32(D_0046E0A8));
        func_002C26D0(buf, fmt, func_001E33E8_noarg());
        func_003A0E90(*(void**)((char*)self + 0x13C), buf);
    }
    if (*(void**)((char*)self + 0x140) != 0) {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry001E4758* vt = *(sVEntry001E4758**)(o + 4);
        unsigned short* fmt = vt[4].fn(o + vt[4].delta, GetHashValue32(D_0046E0C0));
        func_002C26D0(buf, fmt, func_001E3408());
        func_003A0E90(*(void**)((char*)self + 0x140), buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4840);
#ifdef SKIP_ASM
struct sVEntry_func_001E4840 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001E4840(void* self, void* obj)
{
    if (obj != 0) {
        sVEntry_func_001E4840* vt = *(sVEntry_func_001E4840**)((char*)obj + 0x8);
        vt[9].fn((char*)obj + vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4878);
#ifdef SKIP_ASM
struct sVEntry_func_001E4878 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001E4878(void* self, void* obj)
{
    if (obj != 0) {
        sVEntry_func_001E4878* vt = *(sVEntry_func_001E4878**)((char*)obj + 0x8);
        vt[9].fn((char*)obj + vt[9].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E48B0);
#ifdef SKIP_ASM
extern "C" void cUIState_showObjSafe_48B0(void* self, char* name) __asm__("cUIState_showObjSafe");
extern "C" void cUIState_hideObjSafe_48B0(void* self, char* name) __asm__("cUIState_hideObjSafe");
extern "C" int func_001E2BB8_48B0(int kind, int online) __asm__("func_001E2BB8");
extern "C" int func_001E33E8_48B0() __asm__("func_001E33E8__FPv");
extern "C" void func_001E4840_48B0(void* self, int obj) __asm__("func_001E4840");
extern "C" void func_001E4878_48B0(void* self, int obj) __asm__("func_001E4878");
extern "C" int func_001E3620_48B0(int idx) __asm__("func_001E3620");
extern "C" unsigned char func_001E3650(int idx);
extern "C" void func_001E4C78_48B0(void* self, int idx, int row, int a3, int a4) __asm__("func_001E4C78");
extern "C" int func_001E2C80_48B0(int kind, int idx, int local) __asm__("func_001E2C80");
extern "C" int func_001E4B80_48B0(void* self, int entry) __asm__("func_001E4B80");
extern "C" void func_0039B760_48B0(void* menu, unsigned char n) __asm__("func_0039B760");
extern int D_004A20C4;
extern char D_0046E0D0[];
extern char D_0046E0E0[];
extern char D_0046E0F0[];
extern char D_0046E100[];
extern char D_0046E118[];
extern char D_0046E130[];

struct sList_48B0 {
    char pad0[0x9C];
    int a[8];       // 0x9C
    int b[8];       // 0xBC
    int c[8];       // 0xDC
    int d[8];       // 0xFC
    int e[8];       // 0x11C
    char pad13C[0x144 - 0x13C];
    char* menu;     // 0x144
    char pad148[0x14C - 0x148];
    int f14C;       // 0x14C
    int f150;       // 0x150
    int f154;       // 0x154
    int f158;       // 0x158
    char pad15C[0x174 - 0x15C];
    int scroll;     // 0x174
};

// Rebuilds the eight rows of the friends/buddies list from the local and online entries.
extern "C" void func_001E48B0(void* selfp)
{
    sList_48B0* self = (sList_48B0*)selfp;
    int online;
    if (D_004A20C4) {
        online = func_001E2BB8_48B0(4, 1);
    } else {
        online = func_001E2BB8_48B0(4, 0);
    }
    int local = func_001E33E8_48B0();
    int total = local + online;
    int sel;
    if (total == 0) {
        sel = 0;
        cUIState_hideObjSafe_48B0(self, D_0046E0D0);
        cUIState_hideObjSafe_48B0(self, D_0046E0E0);
        cUIState_hideObjSafe_48B0(self, D_0046E0F0);
        cUIState_hideObjSafe_48B0(self, D_0046E100);
        cUIState_hideObjSafe_48B0(self, D_0046E118);
        cUIState_showObjSafe_48B0(self, D_0046E130);
        func_001E4840_48B0(self, self->f154);
        func_001E4840_48B0(self, self->f158);
        func_001E4840_48B0(self, self->f14C);
        func_001E4840_48B0(self, self->f150);
    } else {
        cUIState_showObjSafe_48B0(self, D_0046E0D0);
        sel = total;
        cUIState_showObjSafe_48B0(self, D_0046E0E0);
        cUIState_showObjSafe_48B0(self, D_0046E0F0);
        cUIState_showObjSafe_48B0(self, D_0046E100);
        cUIState_hideObjSafe_48B0(self, D_0046E130);
        func_001E4878_48B0(self, self->f154);
        func_001E4878_48B0(self, self->f158);
        for (int i = 0; i < 8; i++) {
            int n = i + 1;
            int k = local - self->scroll - n;
            if (k >= 0) {
                int r1 = func_001E3620_48B0(k);
                func_001E4C78_48B0(self, k, i, r1, func_001E3650(k));
            } else if (k + online >= 0) {
                int nk = ~k;
                int r;
                if (D_004A20C4) {
                    r = func_001E2C80_48B0(4, nk, 0);
                } else {
                    r = func_001E2C80_48B0(4, nk, 1);
                }
                func_001E4C78_48B0(self, -1, i, r, (unsigned char)func_001E4B80_48B0(self, r));
            } else {
                func_001E4840_48B0(self, self->a[i]);
                func_001E4840_48B0(self, self->b[i]);
                func_001E4840_48B0(self, self->c[i]);
                func_001E4840_48B0(self, self->e[i]);
                func_001E4840_48B0(self, self->d[i]);
            }
        }
    }
    unsigned char keep = self->menu[0x95];
    func_0039B760_48B0(self->menu, sel);
    self->menu[0x95] = keep;
    unsigned char s = self->scroll;
    self->menu[0x98] = s;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4B80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A20C4;
extern "C" int func_001E2DC0(int idx);

struct sPopupEntry18_4B80 {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    char pad_0xC[0x18 - 0xC];
};
extern sPopupEntry18_4B80 D_004C6C08_4B80[] __asm__("D_004C6C08");

extern "C" unsigned char func_001E4B80(void* self, int idx)
{
    unsigned char r = 0xFF;
    if (D_004A20C4 == 0) {
        return 0xFF;
    }
    sPopupEntry18_4B80* a = &D_004C6C08_4B80[idx];
    if (a->field_0x8 == 1) {
        int v = func_001E2DC0(idx);
        int div = 1;
        sPopupEntry14* b = &D_00441630[a->field_0x4];
        switch (b->field_0xC) {
        case 3:
            div = 10;
            v = v / 2;
            break;
        case 5:
            div = 11;
            break;
        case 4:
            div = 10;
            break;
        case 8:
            div = 4;
            break;
        }
        r = v % div;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E4C78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int sprintf(char* buf, const char* fmt, ...);
struct cUIText;
void cUIText_setAsciiString(cUIText* text, const char* str);
extern "C" int func_001E2EA0(int id);
extern "C" void func_001E4F70(void* self, int slot, int id, unsigned char sub);
extern char D_004A2100[];
extern char D_004A2108[];
extern char D_004A2110[];
extern char D_004A2118[];

struct sEnt18_4C78 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
};
extern sEnt18_4C78 D_004C6C08_4C78[] __asm__("D_004C6C08");

struct sEnt14_4C78 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
};
extern sEnt14_4C78 D_00441630_4C78[] __asm__("D_00441630");

struct sVEntry_4C78 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj_4C78 {
    int f0;
    int f4;
    sVEntry_4C78* vt;   // 0x08
    char padC[0xC];
    int f18;            // 0x18
    char pad1C[0x5C];
    int f78;            // 0x78
    int f7C;            // 0x7C
};

struct sPopup_4C78 {
    char pad0[0x9C];
    sObj_4C78* a9C[8];  // 0x9C
    sObj_4C78* aBC[8];  // 0xBC
    sObj_4C78* aDC[8];  // 0xDC
    sObj_4C78* aFC[8];  // 0xFC
    sObj_4C78* a11C[8]; // 0x11C
    char pad13C[0x28];
    int f164;           // 0x164
    int f168;           // 0x168
    int f16C;           // 0x16C
    char pad170[4];
    int f174;           // 0x174
};

static inline void setTint_4C78(sObj_4C78* o, int v, int idx)
{
    o->f78 = idx;
    o->f7C = v;
}

static inline void show_4C78(sObj_4C78* o)
{
    o->vt[9].fn((char*)o + o->vt[9].delta, 1);
}

extern "C" void func_001E4C78(void* self_, int idx, int slot, int id, unsigned char sub)
{
    sPopup_4C78* self = (sPopup_4C78*)self_;
    char buf[16];
    sEnt18_4C78* a = &D_004C6C08_4C78[id];
    sEnt14_4C78* b = &D_00441630_4C78[a->f4];
    char* p = (char*)func_001E39F8(self);
    if (idx == -1) {
        if (b->f10 != 0) {
            if (id == b->f4) {
                if (func_001E3A30((void*)a->f4) == 0)
                    setTint_4C78(self->aBC[slot], self->f164, idx);
                else
                    setTint_4C78(self->aBC[slot], self->f168, idx);
            } else {
                setTint_4C78(self->aBC[slot], self->f16C, idx);
            }
        }
        func_001E4840(self, self->a9C[slot]);
        func_001E4878(self, self->aBC[slot]);
    } else {
        int mask = 1 << idx;
        if (*(int*)(p + 0xC8) & mask) {
            func_001E4840(self, self->a9C[slot]);
            func_001E4840(self, self->aBC[slot]);
        } else {
            func_001E4878(self, self->a9C[slot]);
            func_001E4840(self, self->aBC[slot]);
        }
    }
    if (self->a11C[slot] != 0) {
        if (b->f10 != 0) {
            if (id == b->f4) {
                if (func_001E3A30((void*)a->f4) == 0)
                    sprintf(buf, D_004A2100);
                else
                    sprintf(buf, D_004A2108);
            } else {
                sprintf(buf, D_004A2110);
            }
        } else {
            sprintf(buf, D_004A2118, self->f174 + slot + 1);
        }
        cUIText_setAsciiString((cUIText*)self->a11C[slot], buf);
        show_4C78(self->a11C[slot]);
    }
    if (self->aDC[slot] != 0) {
        cUIText_setUnicodeStringByID((cUIText*)self->aDC[slot], func_001E2EA0(a->fC));
        show_4C78(self->aDC[slot]);
        self->aDC[slot]->f18 = id;
    }
    if (a->f8 == 1) {
        func_001E4F70(self, slot, id, sub);
    } else if (self->aFC[slot] != 0) {
        cUIText_setUnicodeStringByID((cUIText*)self->aFC[slot], a->f10);
        show_4C78(self->aFC[slot]);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E4F70);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" unsigned char func_001E5AA0(void* self, int idx);
extern "C" int func_001E3388(int id);
extern "C" unsigned char func_001E3650(int idx);
extern "C" int func_001E2D58(int v, int i);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern int D_004A20C4;
extern char D_0046E140[];
extern char D_0046E160[];
extern char D_0046E180[];
extern char D_0046E1A0[];
extern char D_0046E1C0[];

struct sPopup1E4F70 {
    char pad0[0xFC];
    cUIText* texts[4];  // 0xFC
};

struct sVE1E4F70 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// Fills text slot `slot` with the "level N" string for the reward id and shows it.
extern "C" void func_001E4F70(void* self, int slot, int id, unsigned char lvl)
{
    char buf[48];
    if (func_001E2D58(3, id)) {
        switch (id) {
        case 0x73: case 0x75: case 0x77: case 0x79: case 0x7B: case 0x7D: case 0x7F: case 0x81: case 0x83: case 0x85: case 0x87: case 0x89:
            sprintf(buf, D_0046E140, lvl);
            break;
        case 0x74: case 0x76: case 0x78: case 0x7A: case 0x7C: case 0x7E: case 0x80: case 0x82: case 0x84: case 0x86: case 0x88: case 0x8A:
            sprintf(buf, D_0046E160, lvl);
            break;
        }
    } else if (func_001E2D58(5, id)) {
        sprintf(buf, D_0046E180, lvl);
    } else if (func_001E2D58(4, id)) {
        sprintf(buf, D_0046E1A0, lvl);
    } else if (func_001E2D58(8, id)) {
        sprintf(buf, D_0046E1C0, lvl);
    }
    sPopup1E4F70* p = (sPopup1E4F70*)self;
    if (p->texts[slot] != 0) {
        cUIText_setUnicodeStringByID(p->texts[slot], GetHashValue32(buf));
        char* o = (char*)p->texts[slot];
        sVE1E4F70* vt = *(sVE1E4F70**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E50C8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001E51D0(void* self, void* a1, void* owner, int a3, int a4);
extern "C" void func_0039F290(void* list, void* item);
extern char D_0046E240[];

extern "C" void func_001E50C8(void* self, int a1, int a2)
{
    void* item = func_001E51D0(cMemMan_alloc(0x70, D_0046E240, 0, 0), *(void**)((char*)self + 0x10), self, a1, a2);
    void* a = *(void**)((char*)self + 0x17C);
    void* b = *(void**)((char*)a + 0xD0);
    void* c = *(void**)((char*)b + 0x10);
    func_0039F290((char*)c + 0x18, item);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E5148);
#ifdef SKIP_ASM
extern "C" void func_001E31B8(int idx);
extern "C" int func_001E2BB8(int a0, int a1);
// PORT: func_001E33E8 is declared (void*) but never reads its argument; called here with none
unsigned char func_001E33E8_noarg() __asm__("func_001E33E8__FPv");
extern "C" void func_001E48B0(void*);
extern "C" void func_001E4758(void*);
extern "C" void func_001E4658(void*);

extern "C" void func_001E5148(void* self, int idx)
{
    func_001E31B8(idx);
    int cur = *(unsigned char*)(*(char**)((char*)self + 0x144) + 0x95);
    int n = func_001E2BB8(4, 1);
    n += func_001E33E8_noarg();
    if (cur >= n) {
        cur--;
    }
    *(unsigned char*)(*(char**)((char*)self + 0x144) + 0x95) = cur;
    func_001E48B0(self);
    func_001E4758(self);
    func_001E4658(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E51D0);
#ifdef SKIP_ASM
extern "C" void* func_0039E318(void* self, void* engine, void* owner);
extern void* D_00474248[];

extern "C" void* func_001E51D0(void* self, void* engine, void* owner, int a3, int a4)
{
    func_0039E318(self, engine, owner);
    *(int*)((char*)self + 0x68) = a3;
    *(int*)((char*)self + 0x6C) = a4;
    *(void***)((char*)self + 0x8) = D_00474248;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x5C) = 0;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x58) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E5248);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0046E258[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void func_001E5248(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E258), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

extern "C" void func_0039E510(void* self);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E52B0__FPv);
#ifdef SKIP_ASM
void func_001E52B0(void* self)
{
    func_0039E510(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E52D0);
#ifdef SKIP_ASM
extern "C" void func_001E5428(void* self);

extern "C" int func_001E52D0(void* self, int on)
{
    if (on != 0) {
        func_001E5428(self);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E52F8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A2120[];
extern char D_004A2128[];
extern char D_0046E268[];
extern char D_004A2130[];
extern char D_0046E278[];
extern char* D_004A20A8;
extern char D_0046E288[];
extern char D_0046E2A0[];
extern char D_0046E2B0[];

struct sVEntryK1E52F8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001E52F8(void* self, void* widget)
{
    int h = *(int*)((char*)widget + 0x38);
    sVEntryK1E52F8* vt = *(sVEntryK1E52F8**)((char*)widget + 8);
    vt[9].fn((char*)widget + vt[9].delta, 1);
    if (h == GetHashValue32(D_004A2120)) {
        *(void**)((char*)self + 0x50) = widget;
    } else if (h == GetHashValue32(D_004A2128)) {
        *(void**)((char*)self + 0x54) = widget;
    } else if (h == GetHashValue32(D_0046E268)) {
        *(void**)((char*)self + 0x48) = widget;
    } else if (h == GetHashValue32(D_004A2130)) {
        *(void**)((char*)self + 0x4C) = widget;
    } else if (h == GetHashValue32(D_0046E278)) {
        *(void**)((char*)self + 0x64) = widget;
    } else if (h == GetHashValue32(D_004A20A8)) {
        *(void**)((char*)self + 0x5C) = widget;
    } else if (h == GetHashValue32(D_0046E288)) {
        *(void**)((char*)self + 0x60) = widget;
    } else if (h == GetHashValue32(D_0046E2A0)) {
        *(void**)((char*)self + 0x58) = widget;
    } else if (h == GetHashValue32(D_0046E2B0)) {
        *(int*)((char*)widget + 0x90) |= 8;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E5428);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPopupEntry18_5428 {
    int field_0x0;
    int field_0x4;
    char pad_0x8[0x4];
    int field_0xC;
    char pad_0x10[0x8];
};
extern sPopupEntry18_5428 D_004C6C08_5428[] __asm__("D_004C6C08");

struct sPopupEntry14_5428 {
    int type;
    char pad_0x4[0x10];
};
extern sPopupEntry14_5428 D_00441630_5428[] __asm__("D_00441630");

struct sVEntryK1E5428 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sVEntryS1E5428 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern char D_0046E2C0[];
extern char D_0046E2D0[];
extern char D_004A2138[];

void cUIText_setAsciiString(cUIText* text, const char* str);
extern "C" int func_001E2EA0(int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_001E55D0(void* self, int idx);
extern "C" void func_001E5780(void* self, int idx);

extern "C" void func_001E5428(void* self)
{
    sPopupEntry18_5428* a = &D_004C6C08_5428[*(int*)((char*)self + 0x68)];
    sPopupEntry14_5428* e = &D_00441630_5428[a->field_0x4];
    if (e->type == 4) {
        void* o = *(void**)((char*)self + 0x5C);
        if (o != 0) {
            sVEntryK1E5428* vt = *(sVEntryK1E5428**)((char*)o + 8);
            vt[9].fn((char*)o + vt[9].delta, 0);
        }
        o = *(void**)((char*)self + 0x60);
        if (o != 0) {
            sVEntryK1E5428* vt = *(sVEntryK1E5428**)((char*)o + 8);
            vt[9].fn((char*)o + vt[9].delta, 0);
        }
        if (*(cUIText**)((char*)self + 0x64) != 0) {
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x64), GetHashValue32(D_0046E2C0));
        }
    }
    if (*(void**)((char*)self + 0x4C) != 0) {
        if (e->type == 4) {
            unsigned short buf[0x18];
            char* mgr = *(char**)((char*)D_004A28A8 + 0x8C);
            sVEntryS1E5428* vt = *(sVEntryS1E5428**)(mgr + 4);
            unsigned short* fmt = vt[4].fn(mgr + vt[4].delta, GetHashValue32(D_0046E2D0));
            func_002C26D0(buf, fmt, func_001E2DC0(*(int*)((char*)self + 0x68)));
            func_003A0E90(*(void**)((char*)self + 0x4C), buf);
        } else {
            char buf[0x30];
            sprintf(buf, D_004A2138, *(int*)((char*)self + 0x6C));
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x4C), buf);
        }
    }
    if (*(cUIText**)((char*)self + 0x50) != 0) {
        cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x50), func_001E2EA0(a->field_0xC));
    }
    func_001E55D0(self, *(int*)((char*)self + 0x68));
    func_001E5780(self, *(int*)((char*)self + 0x68));
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E55D0);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void func_001E5638(void* self, int idx);

extern "C" void func_001E55D0(void* self, int idx)
{
    char* e = (char*)&D_004C6C08[idx];
    if (*(int*)(e + 0x8) == 1) {
        func_001E5638(self, idx);
    } else {
        cUIText* t = *(cUIText**)((char*)self + 0x54);
        if (t != 0) {
            cUIText_setUnicodeStringByID(t, *(int*)(e + 0x10));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E5638);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" unsigned char func_001E5AA0(void* self, int idx);
extern "C" int func_001E3388(int id);
extern "C" unsigned char func_001E3650(int idx);
extern "C" int func_001E2D58(int v, int i);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern int D_004A20C4;
extern char D_0046E140[];
extern char D_0046E160[];
extern char D_0046E180[];
extern char D_0046E1A0[];
extern char D_0046E1C0[];

// Sets the popup text to the "level N" string matching the reward id's category.
extern "C" void func_001E5638(void* self, int id)
{
    char buf[32];
    unsigned char lvl;
    if (D_004A20C4 != 0) {
        lvl = func_001E5AA0(self, id);
    } else {
        lvl = func_001E3650(func_001E3388(id));
    }
    if (func_001E2D58(3, id)) {
        switch (id) {
        case 0x73: case 0x75: case 0x77: case 0x79: case 0x7B: case 0x7D: case 0x7F: case 0x81: case 0x83: case 0x85: case 0x87: case 0x89:
            sprintf(buf, D_0046E140, lvl);
            break;
        case 0x74: case 0x76: case 0x78: case 0x7A: case 0x7C: case 0x7E: case 0x80: case 0x82: case 0x84: case 0x86: case 0x88: case 0x8A:
            sprintf(buf, D_0046E160, lvl);
            break;
        }
    } else if (func_001E2D58(5, id)) {
        sprintf(buf, D_0046E180, lvl);
    } else if (func_001E2D58(4, id)) {
        sprintf(buf, D_0046E1A0, lvl);
    } else if (func_001E2D58(8, id)) {
        sprintf(buf, D_0046E1C0, lvl);
    }
    if (*(cUIText**)((char*)self + 0x54) != 0) {
        cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x54), GetHashValue32(buf));
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E5780);
#ifdef SKIP_ASM
struct sVEntry001E5780 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001E5780(void* self, int idx)
{
    char* e = (char*)&D_004C6C08[idx];
    int kind = *(int*)(e + 0x8);
    if (kind < 2) {
        if (kind >= 0) {
            char* t = *(char**)((char*)self + 0x58);
            *(int*)(t + 0x14) |= 0x80;
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x58), *(int*)(e + 0x14));
            void* obj = *(void**)((char*)self + 0x58);
            sVEntry001E5780* vt = *(sVEntry001E5780**)((char*)obj + 8);
            vt[9].fn((char*)obj + vt[9].delta, 1);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopupmisc", func_001E5800);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPopupEntry18_5800 {
    int field_0x0;
    int field_0x4;
    char pad_0x8[0x18 - 0x8];
};
extern sPopupEntry18_5800 D_004C6C08_5800[] __asm__("D_004C6C08");
struct sEntry14_5800 {
    int type;
    char pad_0x4[0x14 - 0x4];
};
extern sEntry14_5800 D_00441630_5800[] __asm__("D_00441630");
extern "C" void func_001E3268(int id);
struct sVE5800 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001E5800(void* self, void* a1, unsigned int msg)
{
    switch (msg) {
    case 7: {
        int id = *(int*)((char*)self + 0x68);
        sPopupEntry18_5800* a = &D_004C6C08_5800[id];
        sEntry14_5800* b = &D_00441630_5800[a->field_0x4];
        if (b->type == 4) {
            return;
        }
        func_001E3268(id);
    }
    case 5: {
        char* o = *(char**)((char*)self + 0x20);
        sVE5800* vt = *(sVE5800**)(o + 8);
        vt[17].fn(o + vt[17].delta, self, 0x14);
        break;
    }
    case 6: {
        char* o = *(char**)((char*)self + 0x20);
        sVE5800* vt = *(sVE5800**)(o + 8);
        vt[17].fn(o + vt[17].delta, self, 0x14);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E58E0);
#ifdef SKIP_ASM
extern "C" char* func_001E39F8_58E0() __asm__("func_001E39F8");
extern "C" int func_001E33E8_58E0() __asm__("func_001E33E8__FPv");

extern "C" void func_001E58E0(void* self)
{
    int id = *(int*)((char*)self + 0x68);
    sPopupEntry18_5800* a = &D_004C6C08_5800[id];
    sEntry14_5800* b = &D_00441630_5800[a->field_0x4];
    if (b->type == 4) {
        int next = func_001E34D8(id);
        if (next == -1) {
            char* o = *(char**)((char*)self + 0x20);
            sVE5800* vt = *(sVE5800**)(o + 8);
            vt[17].fn(o + vt[17].delta, self, 0x14);
            return;
        }
        *(int*)((char*)self + 0x68) = next;
        *(int*)((char*)self + 0x6C) = *(int*)((char*)self + 0x6C) + 1;
        func_001E5428(self);
    } else if (func_001E3408() > 0) {
        char* h = func_001E39F8_58E0();
        int bit;
        *(int*)((char*)self + 0x68) = func_001E3460(&bit);
        *(int*)(h + 0xC8) |= 1 << bit;
        *(int*)((char*)self + 0x6C) = func_001E33E8_58E0() - bit;
        func_001E5428(self);
    } else {
        char* o = *(char**)((char*)self + 0x20);
        sVE5800* vt = *(sVE5800**)(o + 8);
        vt[17].fn(o + vt[17].delta, self, 0x14);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E5A18);
#ifdef SKIP_ASM
extern "C" int func_001E5A18(void* self, int a1, unsigned int a2)
{
    switch (a2) {
    case 6:
    case 7:
        return 1;
    case 9:
        return 0;
    case 8: {
        sPopupEntry18* a = &D_004C6C08[*(int*)((char*)self + 0x68)];
        sPopupEntry14* b = &D_00441630[a->field_0x4];
        return *(int*)b->pad_0x0 != 4;
    }
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E5AA0);
#ifdef SKIP_ASM
extern int D_004A20C4;

extern "C" unsigned char func_001E5AA0(void* self, int idx)
{
    if (D_004A20C4 == 0) {
        return 0xFF;
    }
    int v = func_001E2DC0(idx);
    int div = 1;
    sPopupEntry18* a = &D_004C6C08[idx];
    sPopupEntry14* b = &D_00441630[a->field_0x4];
    switch (b->field_0xC) {
    case 3:
        div = 10;
        v = v / 2;
        break;
    case 5:
        div = 11;
        break;
    case 4:
        div = 10;
        break;
    case 8:
        div = 4;
        break;
    }
    return v % div;
}
#endif

INCLUDE_ASM("fe/fepopupmisc", func_001E5B80);

extern "C" void func_0020E900(void* self);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E64A8__FPv);
#ifdef SKIP_ASM
void func_001E64A8(void* self)
{
    func_0020E900(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E64C8);
#ifdef SKIP_ASM
// func_0039E4C0 returns nothing (ends in a void vcall); the unit's later void* declaration is a guess.
void func_0039E4C0_v(void* self) __asm__("func_0039E4C0");
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_0020A6F0(void* self, char* text, char* name);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern int D_00536730[];
extern char D_0046E418[];
extern char D_0046E4E8[];
extern char D_0046E500[];

extern "C" void func_001E64C8(void* self)
{
    char buf[32];
    func_0039E4C0_v(self);
    int* p = *(int**)((char*)D_004A28A8 + 0xC0);
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    int x = *p;
    int n = D_00536730[func_00146E98(iface, 0)] + 1;
    if (n >= 7) {
        n = 6;
    }
    sprintf(buf, D_0046E418, n);
    func_0020A6F0(self, buf, D_0046E4E8);
    sprintf(buf, D_0046E500, x, n);
    func_0020A6F0(self, buf, D_0046E4E8);
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E65B8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0046E510[];
extern void* D_004A28A8;
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void func_0026F898(void* self, int val);

extern "C" int func_001E65B8(void* self, void* a1)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E510));
    if (obj != 0) {
        if (*(unsigned char*)((char*)obj + 0x95) == 2) {
            func_0026F898(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28), *(unsigned char*)((char*)a1 + 4));
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E6630);
#ifdef SKIP_ASM
extern "C" int func_001E6630(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E6640);
#ifdef SKIP_ASM
extern int D_004A26FC;
extern int D_004A2700;

extern "C" void func_001E6640(void* self, void* a1, int a2)
{
    if (a1 != 0 && a2 == 5) {
        int v = *(int*)((char*)a1 + 0x18);
        D_004A26FC = 1;
        D_004A2700 = v;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E6668);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0046E520[];
extern char D_0046E378[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0020A380(void* self);

extern "C" void func_001E6668(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E520), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    engine = *(void**)((char*)self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E378), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    *(int*)((char*)self + 0x9C) = 1;
}
#endif

INCLUDE_ASM("fe/fepopupmisc", func_001E6718);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E7558);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0046E510[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern signed char D_00535C11[];

extern "C" void func_001E7558(void* self, void* menu)
{
    int hash = *(int*)((char*)menu + 0x38);
    if (hash == GetHashValue32(D_0046E510)) {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        if (D_00535C11[0] == 1) {
            cUIMenu_setSelectedByIndex(menu, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E75D0);
#ifdef SKIP_ASM
// func_0039E4C0 returns nothing (ends in a void vcall); the unit's later void* declaration is a guess.
void func_0039E4C0_v(void* self) __asm__("func_0039E4C0");
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_0020A6F0(void* self, char* text, char* name);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void func_003A1310(void* self, int a1);
extern void* D_004A28A8;
extern int* D_004A2EEC;
extern int D_00534B30[];
extern int D_00536730[];
extern signed char D_00535BC8[];
extern char D_004A2170[];
extern char D_0046E4E8[];
extern char D_0046E638[];
extern char D_0046E7C8[];
extern char D_0046E7D8[];
extern char D_0046E7E8[];
extern char D_0046E7F8[];
extern char D_0046E808[];

struct sRect_75D0 {
    int a, b, c, d;
};
extern sRect_75D0 D_004C8408;

extern "C" void func_001E75D0(void* self)
{
    char buf[32];
    int second = 0;
    func_0039E4C0_v(self);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int mode = D_00535BC8[0x49];
    int track = D_00535BC8[0x48];
    int first = 1;
    if (mode == 2) {
        second = 1;
        if ((track >= 1 && track <= 3) || track == 5 || track == 6) {
            first = 0;
            second = 0;
        }
    }
    if (first) {
        sprintf(buf, D_004A2170, D_00536730[func_00146E98(player, 0)] + 1);
        func_0020A6F0(self, buf, D_0046E4E8);
        sprintf(buf, D_0046E638, D_00536730[func_00146E98(player, 0)] + 1);
        func_0020A6F0(self, buf, D_0046E4E8);
    }
    if (second) {
        sprintf(buf, D_004A2170, D_00536730[func_00146E98(player, 1)] + 1);
        func_0020A6F0(self, buf, D_0046E4E8);
        sprintf(buf, D_0046E638, D_00536730[func_00146E98(player, 1)] + 1);
        func_0020A6F0(self, buf, D_0046E4E8);
    }
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0 && D_004A2EEC != 0 && *D_004A2EEC != 0) {
        cUIObjK1DEB90* o = (cUIObjK1DEB90*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E7C8));
        if (o != 0) {
            o->v09(1);
        }
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E7D8));
        if (t != 0) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0046E7E8));
        }
        o = (cUIObjK1DEB90*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E7F8));
        if (o != 0) {
            o->v09(1);
        }
        char* p = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E808));
        *(int*)(p + 0x74) |= 1;
        *(sRect_75D0*)(p + 0xA8) = D_004C8408;
        func_003A1310(p, 1);
        ((cUIObjK1DEB90*)p)->v09(0);
    }
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E7920__FPv);
#ifdef SKIP_ASM
void func_001E7920(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E7928);
#ifdef SKIP_ASM
extern int* D_004A2EEC;
extern void* D_004A5B64;
extern int D_004A26FC;
extern int D_004A2700;
extern "C" int func_0020A4E0(void* self);
extern char D_0046E660[];
extern char D_0046E7F8[];
extern char D_0046E7C8[];
extern char D_0046E7D8[];
extern char D_0046E7E8[];

extern "C" void func_001E7928(void* self)
{
    func_0020E900(self);
    if (D_004A2EEC != 0) {
        if (*D_004A2EEC != 0) {
            if (func_0020A4E0(self) != 0) {
                cUIObjK1DEB90* o = (cUIObjK1DEB90*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E660));
                if (o != 0) {
                    o->v09(0);
                }
                o = (cUIObjK1DEB90*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E7F8));
                if (o != 0) {
                    o->v09(0);
                }
            }
        }
        if (*(int*)((char*)D_004A5B64 + 0x18) % 30 == 0 && *D_004A2EEC == 0) {
            cUIObjK1DEB90* o = (cUIObjK1DEB90*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E7C8));
            if (o != 0) {
                o->v09(0);
            }
            cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E7D8));
            if (text != 0) {
                cUIText_setUnicodeStringByID(text, GetHashValue32(D_0046E7E8));
            }
        }
        if (D_004A2EEC[0x19] == 0) {
            D_004A2EEC[0x19] = -1;
            D_004A2700 = 8;
            D_004A26FC = 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E7AA8);
#ifdef SKIP_ASM
extern "C" void func_0020AB50(int state);
extern int D_00534B30[];
extern int* D_004A2EEC;

struct sVEntry001E7AA8 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_001E7AA8(void* self, void* a1)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E510));
    if (obj != 0) {
        if (*(unsigned char*)((char*)obj + 0x95) == 2) {
            func_0026F898(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28), *(unsigned char*)((char*)a1 + 4));
        }
    }
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0 && D_004A2EEC != 0 && *D_004A2EEC != 0) {
        sVEntry001E7AA8* vt = *(sVEntry001E7AA8**)((char*)a1 + 8);
        if (vt[27].fn((char*)a1 + vt[27].delta) != 0) {
            func_0020AB50(0x28);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E7B78);
#ifdef SKIP_ASM
extern "C" int func_001E7B78(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E7B88);
#ifdef SKIP_ASM
extern int D_004A26FC;
extern int D_004A2700;

extern "C" void func_001E7B88(void* self, void* a1, int a2)
{
    if (a1 != 0 && a2 == 5) {
        int v = *(int*)((char*)a1 + 0x18);
        D_004A26FC = 1;
        D_004A2700 = v;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E7BB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0020A380(void* self);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void cUIState_showObjSafe(void* self, char* name);
void cUIText_setAsciiString(cUIText* text, const char* str);
extern "C" int func_004139F8(float f);
extern "C" char* func_0020A1A8(int v);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);
extern void* D_004A28A8;
extern signed char D_00535BC8[];
extern int D_004A213C;
extern int D_00536730[];
extern unsigned int D_00536640[];
extern char D_0046E340[];
extern char D_0046E818[];
extern char D_0046E828[];
extern char D_0046E838[];
extern char D_0046E848[];
extern char D_0046E858[];
extern char D_0046E868[];
extern char D_0046E878[];
extern char D_0046E888[];
extern char D_0046E7A0[];
extern char D_004A2180[];
extern char D_004A2188[];
extern char D_004A2190[];
extern char D_004A2198[];
extern char D_004A21A0[];

class cUIObj_7BB0 {
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
    virtual void setVisible(int on);
};

extern "C" void func_001E7BB0(void* self)
{
    char buf[32];
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E340), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    *(int*)((char*)self + 0x9C) = 0;
    char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E818));
    if (obj != 0) {
        *(int*)(obj + 0x90) |= 8;
    }
    int* p = *(int**)((char*)D_004A28A8 + 0xC0);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
    char* iface8 = (char*)cBE_getInterface_Fv(cBE_getBE(), 8);
    char* ifaceD = (char*)cBE_getInterface_Fv(cBE_getBE(), 0xD);
    int pl = func_00146E98(iface1, 0);
    int mode = *p;
    int sel = D_00536730[pl];
    cUIState_hideObjSafe(self, D_0046E828);
    cUIState_hideObjSafe(self, D_0046E838);
    cUIState_hideObjSafe(self, D_0046E848);
    cUIState_hideObjSafe(self, D_0046E858);
    cUIObj_7BB0* o = (cUIObj_7BB0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E868));
    cUIText_setAsciiString((cUIText*)o, func_0020A1A8(func_004139F8(D_00536640[pl] * 0.01666666753590107f)));
    int off = pl * 4;
    int i;
    for (i = 1; i < 7; i++) {
        sprintf(buf, D_004A2198, i);
        o = (cUIObj_7BB0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        o->setVisible(0);
        if (i == sel + 1) {
            o->setVisible(1);
        }
    }
    if (*(int*)(ifaceD + 0x14) == 0 && (mode == 3 || D_00535BC8[0x4A] == 4)) {
        D_004A213C = 1;
        cUIState_showObjSafe(self, D_0046E7A0);
    } else {
        D_004A213C = 0;
        cUIState_hideObjSafe(self, D_0046E7A0);
    }
    if (*(int*)(ifaceD + 0x14) == 1 && (mode == 3 || D_00535BC8[0x4A] == 4)) {
        cUIState_showObjSafe(self, D_004A2180);
    } else {
        cUIState_hideObjSafe(self, D_004A2180);
    }
    if (*(int*)(ifaceD + 0x14) == 2 && (mode == 3 || D_00535BC8[0x4A] == 4)) {
        cUIState_showObjSafe(self, D_004A2188);
    } else {
        cUIState_hideObjSafe(self, D_004A2188);
    }
    if (*(int*)(ifaceD + 0x14) == 3 && (mode == 3 || D_00535BC8[0x4A] == 4)) {
        cUIState_showObjSafe(self, D_004A2190);
    } else {
        cUIState_hideObjSafe(self, D_004A2190);
    }
    o = (cUIObj_7BB0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E878));
    int vis = 0;
    if (*(int*)(iface8 + 0x18) >= 0 || *(int*)(iface8 + 0x1C) >= 0) {
        vis = 1;
    }
    if (vis) {
        o->setVisible(1);
    } else {
        o->setVisible(0);
    }
    char* r = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + off + 0x28);
    if (D_00535BC8[0x49] == 2
        || *(int*)(r + 0x480) != 0
        || D_00535BC8[0x4A] == 6 || D_00535BC8[0x4A] == 7 || D_00535BC8[0x4A] == 8) {
        cUIState_hideObjSafe(self, D_0046E888);
        cUIState_hideObjSafe(self, D_004A21A0);
    } else {
        func_00294F78(func_0028B180(), 0xE);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8098);
#ifdef SKIP_ASM
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_0039F840(void* list);
extern "C" void func_00231320(void* self);

extern "C" void func_001E8098(void* self)
{
    float limit = 3.0f;
    int idx = func_00146E98(cBE_getInterface_Fv(cBE_getBE(), 1), 0);
    char* riders = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    char* rider = *(char**)(riders + (idx << 2) + 0x28);
    if (*(int*)(rider + 0x480) != 0) {
        limit = 1.0f;
    }
    func_0020E900(self);
    *(float*)((char*)self + 0x9C) += 0.01666666753590107f;
    if (*(int*)((char*)self + 0xA0) != 0 && *(float*)((char*)self + 0x9C) >= limit) {
        func_0039F840(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48) + 0x18);
        func_00231320(*(void**)((char*)D_004A28A8 + 0x84));
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8160);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void func_0039F840(void* list);
extern "C" void func_00231320(void* self);

extern "C" void func_001E8160(void* self, void* a1, int a2)
{
    if (a1 != 0) {
        if (a2 == 5 && *(int*)((char*)self + 0xA0) != 0) {
            char* g = *(char**)((char*)D_004A28A8 + 0x84);
            func_0039F840(*(char**)(g + 0x48) + 0x18);
            func_00231320(g);
        }
    }
}
#endif

//88.13% - logic verified correct; GCC allocates v0 to the comparison
// constant and v1 to the result, the target does the reverse. No source
// shape tried (temp local, early return, nested ternary) flips it.
INCLUDE_ASM("fe/fepopupmisc", func_001E81B0);
#ifdef SKIP_ASM
extern "C" int func_001E81B0(void* self, int a1, int a2)
{
    int r = 0;
    if (a2 == 6) {
        r = *(int*)((char*)self + 0xa0) != 0 ? 0x101 : 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E81D0);
#ifdef SKIP_ASM
extern "C" int func_001E81D0(void* self, int a1)
{
    switch (a1) {
    case 0:
        *(int*)((char*)self + 0xA0) = 0;
        break;
    case 1:
        *(int*)((char*)self + 0xA0) = 1;
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8200);
#ifdef SKIP_ASM
// Wide-string copy; returns dst.
extern "C" unsigned short* func_002C2508(unsigned short* dst, const unsigned short* src);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" void func_003A0E90(void* text, void* p);
extern char D_0046E898[];
extern char D_004A21A8[];

class cUIObj_8200 {
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
    virtual void setVisible(int on);
};

struct sVEntry8200 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern "C" void func_001E8200(void* self)
{
    char buf[32];
    unsigned short fmt[0x68];
    unsigned short text[0x68];
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E340), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    *(int*)((char*)self + 0x9C) = 0;
    char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E818));
    if (obj != 0) {
        *(int*)(obj + 0x90) |= 8;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
    char* iface8 = (char*)cBE_getInterface_Fv(cBE_getBE(), 8);
    char* ifaceD = (char*)cBE_getInterface_Fv(cBE_getBE(), 0xD);
    int* p = *(int**)((char*)D_004A28A8 + 0xC0);
    signed char event = D_00535BC8[0x48];
    cUIState_hideObjSafe(self, D_0046E828);
    cUIState_hideObjSafe(self, D_0046E838);
    cUIState_hideObjSafe(self, D_0046E848);
    cUIState_hideObjSafe(self, D_0046E858);
    int mode = *p;
    if (event != 6) {
        switch (mode) {
        case 0:
        case 1:
            cUIState_showObjSafe(self, D_0046E828);
            break;
        case 2:
            cUIState_showObjSafe(self, D_0046E838);
            break;
        case 3:
            cUIState_showObjSafe(self, D_0046E858);
            break;
        }
    }
    int pl = func_00146E98(iface1, 0);
    int sel = D_00536730[pl];
    if (*(int*)(ifaceD + 0x14) == 0 && (mode == 3 || D_00535BC8[0x4A] == 4 || D_00535BC8[0x4A] == 5)) {
        D_004A213C = 1;
        cUIState_showObjSafe(self, D_0046E7A0);
    } else {
        D_004A213C = 0;
        cUIState_hideObjSafe(self, D_0046E7A0);
    }
    if (*(int*)(ifaceD + 0x14) == 1 && (mode == 3 || D_00535BC8[0x4A] == 5)) {
        cUIState_showObjSafe(self, D_004A2180);
    } else {
        cUIState_hideObjSafe(self, D_004A2180);
    }
    if (*(int*)(ifaceD + 0x14) == 2 && (mode == 3 || D_00535BC8[0x4A] == 5)) {
        cUIState_showObjSafe(self, D_004A2188);
    } else {
        cUIState_hideObjSafe(self, D_004A2188);
    }
    if (*(int*)(ifaceD + 0x14) == 3 && (mode == 3 || D_00535BC8[0x4A] == 5)) {
        cUIState_showObjSafe(self, D_004A2190);
    } else {
        cUIState_hideObjSafe(self, D_004A2190);
    }
    int off = pl * 4;
    int i;
    cUIObj_8200* o;
    for (i = 1; i < 7; i++) {
        sprintf(buf, D_004A2198, i);
        o = (cUIObj_8200*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        o->setVisible(0);
        if (i == sel + 1) {
            o->setVisible(1);
        }
    }
    if ((unsigned int)sel >= 6) {
        cUIState_showObjSafe(self, D_004A21A8);
    }
    o = (cUIObj_8200*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E868));
    char* loc = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry8200* vt = *(sVEntry8200**)(loc + 4);
    func_002C2508(fmt, vt[4].fn(loc + vt[4].delta, GetHashValue32(D_0046E898)));
    func_002C26D0(text, fmt, *(unsigned int*)((char*)D_00536640 + off));
    func_003A0E90(o, text);
    o = (cUIObj_8200*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E878));
    int vis = 0;
    if (*(int*)(iface8 + 0x18) >= 0 || *(int*)(iface8 + 0x1C) >= 0) {
        vis = 1;
    }
    if (vis) {
        o->setVisible(1);
    } else {
        o->setVisible(0);
    }
    char* r = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + off + 0x28);
    if (D_00535BC8[0x49] == 2
        || *(int*)(r + 0x480) != 0
        || D_00535BC8[0x4A] == 9 || D_00535BC8[0x4A] == 10 || D_00535BC8[0x4A] == 11
        || (mode == 1 && p[0x70 / 4] == 3)) {
        cUIState_hideObjSafe(self, D_0046E888);
        cUIState_hideObjSafe(self, D_004A21A0);
    }
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E87B8);
#ifdef SKIP_ASM
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_0039F840(void* list);
extern "C" void func_00231320(void* self);

extern "C" void func_001E87B8(void* self)
{
    float limit = 3.0f;
    int idx = func_00146E98(cBE_getInterface_Fv(cBE_getBE(), 1), 0);
    char* riders = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    char* rider = *(char**)(riders + (idx << 2) + 0x28);
    if (*(int*)(rider + 0x480) != 0) {
        limit = 1.0f;
    }
    func_0020E900(self);
    *(float*)((char*)self + 0x9C) += 0.01666666753590107f;
    if (*(int*)((char*)self + 0xA0) != 0 && *(float*)((char*)self + 0x9C) >= limit) {
        func_0039F840(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48) + 0x18);
        func_00231320(*(void**)((char*)D_004A28A8 + 0x84));
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8880);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void func_0039F840(void* list);
extern "C" void func_00231320(void* self);

extern "C" void func_001E8880(void* self, void* a1, int a2)
{
    if (a1 != 0) {
        if (a2 == 5 && *(int*)((char*)self + 0xA0) != 0) {
            char* g = *(char**)((char*)D_004A28A8 + 0x84);
            func_0039F840(*(char**)(g + 0x48) + 0x18);
            func_00231320(g);
        }
    }
}
#endif

INCLUDE_ASM("fe/fepopupmisc", func_001E88D0);

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E88F0);
#ifdef SKIP_ASM
extern "C" int func_001E88F0(void* self, int a1)
{
    switch (a1) {
    case 0:
        *(int*)((char*)self + 0xA0) = 0;
        break;
    case 1:
        *(int*)((char*)self + 0xA0) = 1;
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8920);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0020A380(void* self);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void* iface, int a1);
void cUIText_setAsciiString(cUIText* text, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" int func_004139F8(float f);
extern "C" char* func_0020A1A8(int v);
extern "C" void* func_001FD190(int v);
extern "C" void func_003A0E90(void* text, void* p);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern signed char D_00535C12[];
extern int D_005366A8[];
extern int D_00536730[];
extern int D_005366D0[];
extern unsigned int D_00536640[];
extern char* D_00441D10[];
struct sIdx3_8920 {
    int v[3];
};
extern sIdx3_8920 D_0046E9B0;
extern char D_0046E8B0[];
extern char D_0046E378[];
extern char D_004A21B0[];
extern char D_004A21B8[];
extern char D_0046E5F0[];
extern char D_0046E8C8[];
extern char D_0046E8E0[];
extern char D_0046E8F8[];
extern char D_0046E908[];
extern char D_0046E918[];
extern char D_0046E938[];
extern char D_0046E950[];
extern char D_0046E970[];
extern char D_004A2138[];
extern char D_004A2160[];
extern char D_0046E660[];
extern char D_0046E670[];
extern char D_0046E980[];
extern char D_0046E998[];
extern char D_0046E4C0[];

class cUIObj_8920 {
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
    virtual void setVisible(int on);
};

extern "C" void func_001E8920(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E8B0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    engine = *(void**)((char*)self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E378), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
    char* p = *(char**)((char*)D_004A28A8 + 0xC0);
    int trk = D_00535C12[0];
    int pl = func_00146E98(iface1, 0);
    cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A21B0));
    cUIText_setUnicodeStringByID(t, GetHashValue32(D_0046E5F0));
    t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A21B8));
    if (trk < 12) {
        if (trk >= 6) {
            func_003A0E90(t, func_001FD190(trk));
        }
    }
    cUIText* a = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E8C8));
    cUIText* b = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E8E0));
    cUIText* c = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E8F8));
    cUIText* d = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E908));
    if (trk >= 6 && trk <= 8) {
        cUIText_setUnicodeStringByID(a, GetHashValue32(D_0046E918));
        cUIText_setUnicodeStringByID(c, GetHashValue32(D_0046E938));
        cUIText_setAsciiString(b, func_0020A1A8(func_004139F8(*(unsigned int*)(p + 0x78) * 0.01666666753590107f)));
        if (D_005366A8[0] != 0) {
            cUIText_setAsciiString(d, D_004A2160);
        } else {
            cUIText_setAsciiString(d, func_0020A1A8(func_004139F8(D_00536640[0] * 0.01666666753590107f)));
        }
    } else {
        char buf[32];
        cUIText_setUnicodeStringByID(a, GetHashValue32(D_0046E950));
        cUIText_setUnicodeStringByID(c, GetHashValue32(D_0046E970));
        sprintf(buf, D_004A2138, *(int*)(p + 0x7C));
        cUIText_setAsciiString(b, buf);
        if (D_005366A8[0] != 0) {
            cUIText_setAsciiString(d, D_004A2160);
        } else {
            sprintf(buf, D_004A2138, D_00536640[0]);
            cUIText_setAsciiString(d, buf);
        }
    }
    cUIObj_8920* o = (cUIObj_8920*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E660));
    int s = D_00536730[pl];
    if (s == 0) goto yes;
    if (s == 1) goto yes;
    if (s == 2) goto yes;
    if (s != 3) goto no;
yes:
    cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046E670));
    goto done;
no:
    if (trk >= 6 && trk <= 8) {
        cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046E980));
    } else {
        cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_0046E998));
    }
done:
    if (D_005366D0[pl] != 0) {
        o->setVisible(0);
    }
    {
        sIdx3_8920 ids = D_0046E9B0;
        char name[32];
        int i;
        for (i = 0; i < 5; i++) {
            sprintf(name, D_0046E4C0, i);
            o = (cUIObj_8920*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
            if (o != 0) {
                if (i < 3) {
                    cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_00441D10[ids.v[i]]));
                    *(int*)((char*)o + 0x18) = ids.v[i];
                } else {
                    o->setVisible(0);
                    o->v08(1);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8E70__FPv);
#ifdef SKIP_ASM
void func_001E8E70(void* self)
{
    func_0020E900(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8E90__FPv);
#ifdef SKIP_ASM
int func_001E8E90(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8E98);
#ifdef SKIP_ASM
extern "C" int func_001E8E98(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8EA8);
#ifdef SKIP_ASM
extern int D_004A26FC;
extern int D_004A2700;

extern "C" void func_001E8EA8(void* self, void* a1, int a2)
{
    if (a1 != 0 && a2 == 5) {
        int v = *(int*)((char*)a1 + 0x18);
        D_004A26FC = 1;
        D_004A2700 = v;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8ED0);
#ifdef SKIP_ASM
extern "C" void* func_0039E4C0(void* self);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);

extern "C" void func_001E8ED0(void* self)
{
    func_0039E4C0(self);
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8F00);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0046E9C0[];
extern char D_0046E378[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0020A380(void* self);
void func_001E8FC0(void* self);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);

extern "C" void func_001E8F00(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E9C0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    engine = *(void**)((char*)self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E378), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_001E8FC0(self);
    func_0020A380(self);
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8FC0__FPv);
#ifdef SKIP_ASM
void func_001E8FC0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fepopupmisc", func_001E8FC8);
#ifdef SKIP_ASM
extern int D_004A26FC;
extern int D_004A2700;

extern "C" void func_001E8FC8(void* self, void* a1, int a2)
{
    if (a1 != 0 && a2 == 5) {
        int v = *(int*)((char*)a1 + 0x18);
        D_004A26FC = 1;
        D_004A2700 = v;
    }
}
#endif

