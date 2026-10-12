#include "common.h"

INCLUDE_ASM("fe/festateruleselect", cFEStateRuleSelect_setupMenu);

INCLUDE_ASM("fe/festateruleselect", cFEStateRuleSelect_onCreateScreen);

extern "C" void* func_0039E4C0(void* self);

//100%
INCLUDE_ASM("fe/festateruleselect", func_00191C48__FPv);
#ifdef SKIP_ASM
void* func_00191C48(void* self)
{
    return func_0039E4C0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00191C68);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void cUIStateStack_pushSpecial(void* stack, void* state, int a2, int a3);
extern "C" void* func_001887A0(void* mem, void* owner, int a2);
extern "C" void func_00192088(void* self, int idx, int a2);
struct sRuleSel_2380;
extern "C" void func_00192380(sRuleSel_2380* self, void* item);
extern "C" int func_0039A738(void* self);
extern "C" void func_0039F400(void* stack, void* state);
extern "C" void func_003E6448(void* dst, int c, int n);
extern char D_0045D698[];
extern char D_005308B8[];

struct sVE_1C68 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sMsg_1C68 {
    char pad_0x0[0x18];
    int id;             // 0x18
    char pad_0x1C[0x60];
    int* info;          // 0x7C
};

extern "C" void func_00191C68(char* self, sMsg_1C68* msg, unsigned int type)
{
    if (msg == 0) {
        return;
    }
    switch (type) {
    case 5:
        if (msg->info[6] == 0) {
            char* o = **(char***)(self + 0x10);
            sVE_1C68* vt = *(sVE_1C68**)(o + 0x4);
            void* st = vt[4].fn(o + vt[4].delta, self, msg->id);
            if (st) {
                func_0039F400(*(char**)(self + 0x10) + 0x18, st);
            }
        }
        break;
    case 6: {
        char* o = **(char***)(self + 0x10);
        sVE_1C68* vt = *(sVE_1C68**)(o + 0x4);
        void* st = vt[5].fn(o + vt[5].delta, self, msg->id);
        if (st) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, st);
        }
        func_003E6448(D_005308B8, 0, 0x20);
        break;
    }
    case 9: {
        int id = msg->id;
        func_00192088(self, id, func_0039A738(msg));
        func_00192380((sRuleSel_2380*)self, msg);
        break;
    }
    case 7: {
        char* st = (char*)func_001887A0(cMemMan_alloc(0x54, D_0045D698, 0x100, 0), *(void**)(self + 0x10), 1);
        *(int*)(st + 0x1C) = (*(int*)(st + 0x1C) & ~0x3F00) | 0x100;
        cUIStateStack_pushSpecial(*(char**)(self + 0x10) + 0x18, st, 0, 0);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00191E08);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A13A0[];

extern "C" int func_00191E08(void* self, void* msg)
{
    int id = *(int*)((char*)msg + 0x38);
    return (id == GetHashValue32(D_004A13A0)) ? 0x101 : 0x100;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festateruleselect", func_00191E48);
#ifdef SKIP_ASM
struct cUIScreen;
struct cUIText;
int GetHashValue32(char* str);
extern "C" void cFEStateRuleSelect_setupMenu(void* self, signed char idx);
int cUIScreen_getFrameByLabel(cUIScreen* self, int hash);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_0045E270[];
extern char D_0045E280[];
extern char D_0045FB20[];
extern char* D_00441058[];

// PORT: the frame labels are copied with the builtin block move (the original likely used
// strcpy on string literals); the two strings live at these symbols.
extern char D_0045FAD8[] __attribute__((aligned(8)));
extern char D_004A1708[] __attribute__((aligned(8)));

struct sVE_1E48 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void SetVisible_1E48(char* o, int on)
{
    sVE_1E48* vt = *(sVE_1E48**)(o + 0x8);
    vt[9].fn(o + vt[9].delta, on);
}

extern "C" int func_00191E48(char* self, void* unused, unsigned int type, int idx)
{
    switch (type) {
    case 9:
        return 0x100;
    case 1: {
        int sel = (*(signed char**)(self + 0x48))[idx];
        int play = 0;
        char* a = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0045E270));
        char* b = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0045E280));
        int locked = *(signed char*)(self + sel + 0x51) < 1;
        cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0045FB20));
        if (locked && t) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_00441058[sel]));
        }
        char label[32];
        if (sel) {
            if (locked) {
                if (a) SetVisible_1E48(a, 1);
                if (b) SetVisible_1E48(b, 1);
                play = 1;
                __builtin_memcpy(label, D_0045FAD8, 10);
            }
        } else {
            if (a) SetVisible_1E48(a, 0);
            if (b) SetVisible_1E48(b, 0);
            play = 1;
            __builtin_memcpy(label, D_004A1708, 7);
        }
        if (play) {
            int f = cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(label));
            if (f != 0xFFFF) {
                cUIScreen_playFrame(*(void**)(self + 0x40), f, 1);
            }
        }
        return locked;
    }
    case 4:
        cFEStateRuleSelect_setupMenu(self, idx);
        return 0x101;
    }
    return 0x101;
}
#endif

INCLUDE_ASM("fe/festateruleselect", func_00192088);

//100%
INCLUDE_ASM("fe/festateruleselect", func_00192240);
#ifdef SKIP_ASM
extern unsigned int D_005308B8_192240[] __asm__("D_005308B8");
extern int D_005308D0[];
extern int D_005308D4[];

// Returns the current setting of a race rule (1-14), or -1 for an unknown rule.
extern "C" int func_00192240(void* self, int rule)
{
    switch (rule) {
    case 4:
        return D_005308D0[0] & 1;
    case 3:
        return (D_005308B8_192240[0] >> 3) & 1;
    case 5:
        return (D_005308D0[0] >> 3) & 1;
    case 14:
        return (D_005308B8_192240[0] >> 5) & 1;
    case 7:
        return (D_005308B8_192240[0] >> 4) & 1;
    case 8:
        return (D_005308D0[0] >> 1) & 1;
    case 1:
        return (D_005308D0[0] >> 2) & 1;
    case 2:
        return D_005308D4[0];
    case 6:
        return (D_005308D0[0] >> 4) & 1;
    case 9:
        return (D_005308D0[0] >> 5) & 1;
    case 10:
        return (D_005308D0[0] >> 6) & 1;
    case 11: {
        int f = D_005308D0[0] >> 7;
        return f & 1;
    }
    case 12:
        return (D_005308D0[0] >> 8) & 1;
    case 13:
        return (D_005308D0[0] >> 9) & 1;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00192380);
#ifdef SKIP_ASM
extern "C" int func_0039A738(void* self);
extern "C" void func_00192088(void* self, int idx, int a2);
extern "C" void cFEStateRuleSelect_updateMenuColor(void* self);
extern int D_004410C8[];

struct sRuleSel_2380 {
    char pad[0x51];
    unsigned char count[15];
};

extern "C" void func_00192380(sRuleSel_2380* self, void* item)
{
    int mask = D_004410C8[*(int*)((char*)item + 0x18)] << 1;
    if (func_0039A738(item) == 0) {
        for (int i = 1; i < 15; i++) {
            int bit = 1 << i;
            if ((bit & mask) == 0) {
                int v = self->count[i] - 1;
                self->count[i] = v;
                if ((signed char)v <= 0) {
                    self->count[i] = 0;
                }
            }
        }
    } else {
        for (int i = 1; i < 15; i++) {
            int bit = 1 << i;
            if ((bit & mask) == 0) {
                self->count[i] += 1;
                func_00192088(self, i, 0);
            }
        }
    }
    cFEStateRuleSelect_updateMenuColor(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", cFEStateRuleSelect_updateMenuColor);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);

struct sVE_2488 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sQuad_2488 {
    int a, b, c, d;
};
extern sQuad_2488 D_004C66C8;

struct sObj_2488 {
    char pad0[0x8];
    sVE_2488* vt;
    char padC[0x18 - 0xC];
    int idx;
    char pad1C[0x88 - 0x1C];
    sQuad_2488 q88;
};

// PORT: the names are built with the builtin block move (the original likely used
// strcpy on string literals); the two strings live at these symbols.
extern char D_004A16A8[];
extern char D_004A16B0[];

extern "C" void cFEStateRuleSelect_updateMenuColor(void* selfp)
{
    char* self = (char*)selfp;
    char name0[16];
    char name1[16];
    __builtin_memcpy(name0, D_004A16A8, 3);
    __builtin_memcpy(name1, D_004A16B0, 3);
    signed char n = *(signed char*)(self + 0x50) < 12 ? *(signed char*)(self + 0x50) : 11;
    for (signed char i = 0; i < n; i++) {
        sObj_2488* a = (sObj_2488*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(name0));
        sObj_2488* b = (sObj_2488*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(name1));
        if (a && b) {
            if (*(signed char*)(self + a->idx + 0x51) > 0) {
                b->vt[25].fn((char*)b + b->vt[25].delta, 1);
                b->q88 = D_004C66C8;
                b->vt[8].fn((char*)b + b->vt[8].delta, 1);
                a->vt[24].fn((char*)a + a->vt[24].delta, 1);
                a->q88 = D_004C66C8;
                a->vt[8].fn((char*)a + a->vt[8].delta, 1);
            } else {
                b->vt[25].fn((char*)b + b->vt[25].delta, 0);
                b->vt[8].fn((char*)b + b->vt[8].delta, 0);
                a->vt[24].fn((char*)a + a->vt[24].delta, 0);
                a->vt[8].fn((char*)a + a->vt[8].delta, 0);
            }
        }
        if (i < 9) {
            name0[0]++;
            name1[0]++;
        } else {
            name1[0] = name0[0] = i + 0x58;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_001926F0);
#ifdef SKIP_ASM
extern void* D_0046B078[];

extern "C" void* func_001926F0(void* self)
{
    int i;
    *(void***)((char*)self + 0x30) = D_0046B078;
    for (i = 7; i >= 0; i--) {
        ((int*)((char*)self + 0x8))[i] = 0;
    }
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x2c) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x4) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00192740);
#ifdef SKIP_ASM
struct sVEntry00192740 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj00192740 {
    int pad[2];
    sVEntry00192740* vt;
};

extern "C" void func_00192740(void* self, int a1)
{
    int i;
    *(int*)((char*)self + 0x28) = a1;
    for (i = 0; i < 8; i++) {
        sObj00192740* o = ((sObj00192740**)((char*)self + 0x8))[i];
        if (o != 0) {
            o->vt[8].fn((char*)o + o->vt[8].delta, a1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_001927B0);
#ifdef SKIP_ASM
extern "C" int func_0039A738(void* self);
extern "C" int func_00192948(void* self, int idx);

struct sColor_001927B0 {
    float r, g, b, a;
    sColor_001927B0(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};
struct sVEnt_001927B0 { short delta; short index; void (*fn)(void*, const sColor_001927B0&); };
struct sObj_001927B0 { int pad[2]; sVEnt_001927B0* vt; };
struct sRuleSel_001927B0 { void* owner; int f4; sObj_001927B0* items[8]; };

extern "C" void func_001927B0(sRuleSel_001927B0* self)
{
    void* owner = self->owner;
    if (owner == 0) {
        return;
    }
    int sel = *(signed char*)((char*)owner + 0x95);
    for (int i = 0; i < 8; i++) {
        if (self->items[i] == 0) {
            continue;
        }
        if (func_00192948(self, i) == 0) {
            continue;
        }
        if (i == sel) {
            sObj_001927B0* o = self->items[i];
            sVEnt_001927B0* e = &o->vt[11];
            e->fn((char*)o + e->delta, sColor_001927B0(1.0f, 1.0f, 1.0f, 1.0f));
        } else if (func_0039A738(self->items[i])) {
            sObj_001927B0* o = self->items[i];
            sVEnt_001927B0* e = &o->vt[11];
            e->fn((char*)o + e->delta, sColor_001927B0(1.0f, 0.5921568870544434f, 0.04313725605607033f, 0.0f));
        } else {
            sObj_001927B0* o = self->items[i];
            sVEnt_001927B0* e = &o->vt[11];
            e->fn((char*)o + e->delta, sColor_001927B0(1.0f, 0.14509804546833038f, 0.027450982481241226f, 0.019607843831181526f));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00192918);
#ifdef SKIP_ASM
extern "C" int func_00192918(void* self, int val)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (((int*)((char*)self + 0x8))[i] == val) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00192948);
#ifdef SKIP_ASM
extern "C" int func_00192948(void* self, int a1)
{
    int mask = (int)(0x1000000 << a1) >> 24;
    return (*(int*)((char*)self + 0x2c) & mask) != 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00192968__FPvi);
#ifdef SKIP_ASM
void func_00192968(void* self, int val)
{
    *(int*)((char*)self + 0x2C) = val;
}
#endif

//100%
INCLUDE_ASM("fe/festateruleselect", func_00192970);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);

struct sName11_00192970 { char c[11]; };
struct sName12_00192970 { char c[12]; };
struct sName13_00192970 { char c[13]; };
struct sName4_00192970 { char c[4]; };
struct sName2_00192970 { char c[2]; };
struct sName5_00192970 { char c[5]; };

extern char D_0045FC88[];
extern char D_0045FC98[];
extern char D_0045FCA8[];
extern char D_0045FCB8[];
extern char D_004A1740[];
extern char D_004A1748[];
extern char D_004A14F8[];
extern char D_004A1750[];

class cFEVObj_00192970 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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

static inline void Hide_00192970(void* screen, char* name)
{
    cFEVObj_00192970* t = (cFEVObj_00192970*)cUIScreen_getObjectByHashName(screen, GetHashValue32(name));
    if (t != 0) {
        t->v09(0);
    }
}

struct sOwner_00192970 {
    char pad[0x8];
    cFEVObj_00192970* items[8];     // 0x8
    int f28;                        // 0x28
    int mask;                       // 0x2C
};

extern "C" void func_00192970(sOwner_00192970* self, void* screen)
{
    sName11_00192970 n0 = *(sName11_00192970*)D_0045FC88;
    sName12_00192970 n1 = *(sName12_00192970*)D_0045FC98;
    sName12_00192970 n2 = *(sName12_00192970*)D_0045FCA8;
    sName13_00192970 n3 = *(sName13_00192970*)D_0045FCB8;
    sName4_00192970 n4 = *(sName4_00192970*)D_004A1740;
    sName4_00192970 n5 = *(sName4_00192970*)D_004A1748;
    sName2_00192970 n6 = *(sName2_00192970*)D_004A14F8;
    sName5_00192970 n7 = *(sName5_00192970*)D_004A1750;
    for (int i = 0; i < 8; i++) {
        if (((self->mask >> i) & 1) == 0) {
            if (self->items[i] != 0) {
                self->items[i]->v08(1);
                self->items[i]->v09(0);
                n0.c[0] = i + '0';
                n1.c[0] = i + '0';
                n2.c[0] = i + '0';
                n3.c[0] = i + '0';
                n6.c[0] = i + '1';
                n7.c[3] = i + '1';
                n4.c[2] = i + '1';
                n5.c[2] = i + '1';
                Hide_00192970(screen, n0.c);
                Hide_00192970(screen, n1.c);
                Hide_00192970(screen, n2.c);
                Hide_00192970(screen, n3.c);
                Hide_00192970(screen, n6.c);
                Hide_00192970(screen, n7.c);
                Hide_00192970(screen, n4.c);
                Hide_00192970(screen, n5.c);
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festateruleselect", func_00192D00);
#ifdef SKIP_ASM
extern void* D_0046AF68[];
extern "C" void* func_001A8500(void* self, int a1, int a2);

extern "C" void* func_00192D00(void* self, int a1)
{
    char* p;
    int i;
    func_001A8500(self, a1, 0);
    *(void***)((char*)self + 0x8) = D_0046AF68;
    p = (char*)self + 0x6D0;
    for (i = 1; i != -1; i--, p += 0x34) {
        func_001926F0(p);
    }
    *(int*)((char*)self + 0xC) = 0x14;
    *(int*)((char*)self + 0x738) = 0;
    return self;
}
#endif

