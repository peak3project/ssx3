#include "common.h"

//100%
INCLUDE_ASM("fe/ovstatetrophy", cOVStateTrophy_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern char D_00471CD8[];

extern "C" void cOVStateTrophy_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00471CD8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_0020E9A0);
#ifdef SKIP_ASM
extern "C" void func_0039F400(void* list, void* item);

struct sColor_20E9A0 {
    float r, g, b, a;
    sColor_20E9A0(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

class cUIObj_20E9A0 {
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
    virtual void v10();
    virtual int setColor(const sColor_20E9A0& c);
};

struct sVEntry_20E9A0 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

extern "C" void func_0020E9A0(void* self, cUIObj_20E9A0* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        item->setColor(sColor_20E9A0(1.0f, 1.0f, 0.0f, 0.0f));
        void* r = 0;
        if (*(int*)((char*)item + 0x18) == 1) {
            void* obj = **(void***)((char*)self + 0x10);
            sVEntry_20E9A0* vt = *(sVEntry_20E9A0**)((char*)obj + 4);
            r = vt[4].fn((char*)obj + vt[4].delta, self, 1);
        }
        func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        break;
    }
    case 6: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry_20E9A0* vt = *(sVEntry_20E9A0**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_0020EAA0);
#ifdef SKIP_ASM
struct sRect20EAA0 {
    float x, y, w, h;
};
extern char D_00474230[];
extern int D_004A276C;
extern "C" void func_0020EC18(void* self, sRect20EAA0* a, sRect20EAA0* r);

extern "C" void* func_0020EAA0(void* self)
{
    sRect20EAA0 r;
    *(void**)((char*)self + 0x38) = D_00474230;
    r.x = 0.0f;
    r.y = 0.0f;
    r.w = 640.0f;
    r.h = 480.0f;
    func_0020EC18(self, &r, &r);
    D_004A276C++;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_0020EB08);
#ifdef SKIP_ASM
extern char D_00474230[];
extern int D_004A276C;
extern int D_004A2768;
void operator_delete(int*);

extern "C" void func_0020EB08(void* self, int flags)
{
    int n = D_004A276C - 1;
    *(void**)((char*)self + 0x38) = D_00474230;
    D_004A276C = n;
    if (n == 0) {
        D_004A2768 = 0;
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_0020EB50);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_0020EC18(void* self, sRect20EAA0* a, sRect20EAA0* r);
extern "C" int func_00398380(void* bank, int name);
extern "C" int func_003983F0(void* bank, int hash);
extern void* D_004A28A8;
extern int D_004A2764;
extern int D_004A2768;
extern char D_004A21F0[];
struct sTex_20EB50 {
    int name;
    int f4;
    int f8;
    int handle;
};
extern sTex_20EB50 D_004C8C58[];

extern "C" void func_0020EB50(void* self, sRect20EAA0* a, sRect20EAA0* r)
{
    if (D_004A2768 == 0) {
        char* res = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48);
        int i;
        for (i = 0; i < 11; i++) {
            D_004C8C58[i].handle = func_00398380(res + 0x58, D_004C8C58[i].name);
        }
        void* bank = *(void**)(res + 8);
        D_004A2764 = func_003983F0(bank, GetHashValue32(D_004A21F0));
        D_004A2768 = 1;
    }
    func_0020EC18(self, a, r);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_0020EC18);
#ifdef SKIP_ASM
extern int D_004A2764;
extern int D_004A2768;
extern float D_004C8CA0[];

struct sVec2_20EC18 {
    float x, y;
    sVec2_20EC18(float x_, float y_) : x(x_), y(y_) {}
};
struct sTrophyBox_20EC18 {
    sVec2_20EC18 pos;     // 0x00
    float top;            // 0x08
    float bottom;         // 0x0C
    float cx;             // 0x10
    float y14;            // 0x14
    float y18;            // 0x18
    float s1C;            // 0x1C
    sRect20EAA0 rect;     // 0x20
    float s30;            // 0x30
};

// PORT: D_004A2764 holds a texture pointer in an int (declared int elsewhere in the unit).
extern "C" void func_0020EC18(void* self, sRect20EAA0* a, sRect20EAA0* r)
{
    float h;
    if (D_004A2768 != 0) {
        char* tex = (char*)D_004A2764;
        h = (float)*(int*)(tex + 0x14) * *(float*)(tex + 0x34) * 0.666700005531311f;
    } else {
        h = 30.0f;
    }
    float m = D_004C8CA0[0];
    ((sTrophyBox_20EC18*)self)->pos = sVec2_20EC18(r->x + r->w * 0.5f, (r->y + r->h) - h);
    ((sTrophyBox_20EC18*)self)->top = r->y;
    ((sTrophyBox_20EC18*)self)->bottom = r->y + r->h - h - m;
    ((sTrophyBox_20EC18*)self)->cx = r->x + r->w * 0.5f;
    ((sTrophyBox_20EC18*)self)->y14 = r->y + m;
    ((sTrophyBox_20EC18*)self)->y18 = ((sTrophyBox_20EC18*)self)->bottom;
    ((sTrophyBox_20EC18*)self)->s1C = (((sTrophyBox_20EC18*)self)->bottom - ((sTrophyBox_20EC18*)self)->top - m) * 9.999999747378752e-05f;
    ((sTrophyBox_20EC18*)self)->rect = *r;
    ((sTrophyBox_20EC18*)self)->s30 = ((sTrophyBox_20EC18*)self)->rect.h * 9.999999747378752e-05f;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_0020ED20);
#ifdef SKIP_ASM
struct sTrophySlot20ED20 {
    int active;
    int pad[5];
};
struct sPad16;
extern sPad16 D_004C8BC8;
extern char* D_004A2750;
extern int D_004A2760;
extern void* D_004A28A8;
extern "C" void func_00210618(int i);

extern "C" void func_0020ED20(void)
{
    if (D_004A2750 != 0) {
        char* race = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
        int i;
        for (i = 0; i < *(int*)(race + 0x78); i++) {
            func_00210618(i);
            ((sTrophySlot20ED20*)&D_004C8BC8)[i].active = 0;
        }
        D_004A2760 = 0;
    }
}
#endif

INCLUDE_ASM("fe/ovstatetrophy", func_0020EDA0);

INCLUDE_ASM("fe/ovstatetrophy", func_0020FB40);

struct sPad16 { char x; int pad[3]; };
extern sPad16 D_004C8BC8;

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_002105B0);
#ifdef SKIP_ASM
extern "C" void func_002105B0(int a0)
{
    char* p = (char*)&D_004C8BC8 + a0 * 0x18;
    *(int*)p = 1;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_002105D0);
#ifdef SKIP_ASM
extern char* D_004A2750;
extern char* D_004A2754;
extern char* D_004A2758;
extern "C" void func_002108F8(void);

extern "C" void func_002105D0(char* data)
{
    char* a = data + *(int*)(data + 4);
    char* b = data + *(int*)(data + 0xC);
    D_004A2750 = data;
    D_004A2754 = a;
    D_004A2758 = b;
    func_002108F8();
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210608);
#ifdef SKIP_ASM
extern char* D_004A2750;
extern char* D_004A2754;
extern char* D_004A2758;

extern "C" void func_00210608(void* data)
{
    D_004A2750 = 0;
    D_004A2754 = 0;
    D_004A2758 = 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210618);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char* D_004A2750;
extern char* D_004A2754;
extern void* D_004A28A8;
float func_00113128(void* rider);
extern "C" float func_00210820(int i);

struct sTrophyEntry_210618 {
    int active;
    int seg;
    float dist;
    float pos;
    int pad[2];
};

struct sTrophySeg_210618 {
    char pad[0x10];
    float dist;
};

// The unit declares D_004C8BC8 as a 16-byte pad struct; view it as the per-rider table by asm label.
extern sTrophyEntry_210618 D_004C8BC8_210618[] __asm__("D_004C8BC8");

extern "C" void func_00210618(int i)
{
    char* course = D_004A2750;
    sTrophySeg_210618* segs = (sTrophySeg_210618*)D_004A2754;
    if (course == 0)
        return;
    char* race = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    if (i >= *(int*)(race + 0x78))
        return;
    float d = *(float*)(course + 0x10) - func_00113128(*(void**)(race + (i << 2) + 0x28));
    if (D_004C8BC8_210618[i].active == 0)
    {
        float prev = D_004C8BC8_210618[i].dist;
        float dd = d - prev;
        float lim = 138.88890075683594f;
        if (dd > lim)
            d = prev + lim;
        else if (dd < -lim)
            d = prev - lim;
    }
    if (d <= 0.0f)
    {
        D_004C8BC8_210618[i].seg = 0;
        D_004C8BC8_210618[i].dist = 0.0f;
        D_004C8BC8_210618[i].pos = func_00210820(i);
    }
    else
    {
        int last = *(int*)course - 1;
        if (segs[last].dist <= d)
        {
            D_004C8BC8_210618[i].seg = last;
            D_004C8BC8_210618[i].dist = *(float*)(course + 0x10);
            D_004C8BC8_210618[i].pos = func_00210820(i);
        }
        else
        {
            int k = D_004C8BC8_210618[i].seg;
            while (segs[k].dist <= d)
                k++;
            while (d < segs[k].dist)
                k--;
            D_004C8BC8_210618[i].seg = k;
            D_004C8BC8_210618[i].dist = d;
            D_004C8BC8_210618[i].pos = func_00210820(i);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210820);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sQuad_210820 {
    float x, y, z, w;
} __attribute__((aligned(16)));
class cPosObj_210820 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual sQuad_210820* v05();
};
struct sZone_210820 {
    float sx, sy, ox, oy, f10;
};
struct sSlot_210820 {
    int active;
    int zone;
    int b, c, d, e;
};
extern sSlot_210820 D_slots210820[6] __asm__("D_004C8BC8");
extern char* D_004A2754;
extern void* D_004A28A8;

static inline float subx_210820(sZone_210820* z, sQuad_210820& p)
{
    return p.x - z->ox;
}
static inline float suby_210820(sZone_210820* z, sQuad_210820& p)
{
    return p.y - z->oy;
}

static inline float sx_210820(sZone_210820* z)
{
    return z->sx;
}
static inline float sy_210820(sZone_210820* z)
{
    return z->sy;
}

extern "C" float func_00210820(int idx)
{
    sZone_210820* zones = (sZone_210820*)D_004A2754;
    char* world = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    char* rider = *(char**)(world + (idx << 2) + 0x28);
    sQuad_210820 pos = *((cPosObj_210820*)(rider + 0x6C0))->v05();
    float dy = suby_210820(&zones[D_slots210820[idx].zone], pos);
    float dx = subx_210820(&zones[D_slots210820[idx].zone], pos);
    float r = dy * sy_210820(&zones[D_slots210820[idx].zone]) + dx * sx_210820(&zones[D_slots210820[idx].zone]);
    if (D_slots210820[idx].active) {
        D_slots210820[idx].e = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_002108F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sTrophySlot2108F8 {
    int active;
    int a, b, c, d, e;
};
extern sTrophySlot2108F8 D_slots2108F8[6] __asm__("D_004C8BC8");
extern int D_004A2760;

static inline void resetSlot2108F8(sTrophySlot2108F8* s)
{
    s->active = 1;
    s->a = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
}

extern "C" void func_002108F8(void)
{
    int i;
    for (i = 0; i < 6; i++) {
        resetSlot2108F8(&D_slots2108F8[i]);
    }
    D_004A2760 = 1;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210940);
#ifdef SKIP_ASM
struct sColor_210940 {
    float r, g, b, a;
    sColor_210940(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};
class cUIText;
class cUIObj_210940 {
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
    virtual void setVisible(int v);
    virtual void v10();
    virtual int setColor(const sColor_210940& c);
};

struct sRect_210940 { int a, b, c, d; };
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
void cUIText_setAsciiString(cUIText* text, const char* s);
extern "C" void func_0020A380(void* self);
extern "C" void func_003A1310(void* self, int a1);
extern void* D_004A28A8;
extern char D_00471CE8[];
extern char D_00471D00[];
extern char D_00471D10[];
extern char D_00471D20[];
extern char D_00471D30[];
extern char D_00471D40[];
extern char D_0046E808[];
extern char D_00534FC8[];
extern sRect_210940 D_004C8D08;

extern "C" void func_00210940(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00471CE8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen == 0)
        return;
    cUIScreen_playFrame(screen, 0, 0);
    cUIObj_210940* t = (cUIObj_210940*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00471D00));
    if (t != 0)
    {
        t->setVisible(1);
        cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
        cUIText_setAsciiString((cUIText*)t, D_00534FC8);
    }
    char* a = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00471D10));
    *(int*)(a + 0x14) |= 1;
    void* b = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00471D20));
    void* c = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00471D30));
    void* d = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00471D40));
    *(void**)(a + 0x7C) = b;
    *(void**)(a + 0x80) = c;
    *(void**)(a + 0x84) = d;
    *(int*)(a + 0x88) = 2;
    cUIObj_210940* e = (cUIObj_210940*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E808));
    if (e != 0)
    {
        *(int*)((char*)e + 0x74) |= 1;
        func_003A1310(e, 1);
        e->setVisible(1);
        *(int*)((char*)e + 0x14) |= 0x80;
        e->setColor(sColor_210940(1.0f, 0.0f, 0.0f, 0.0f));
        *(sRect_210940*)((char*)e + 0xA8) = D_004C8D08;
        *(char**)((char*)e + 0xB8) = a;
    }
    func_0020A380(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210B58);
#ifdef SKIP_ASM
extern int D_004A2EEC;
extern char D_004A2560[];
extern "C" int func_00258160(int a, char* name, int len);
extern "C" void func_00210BD8(void* self, char* name, int a);
extern "C" void func_00210F40(void* self, int a1, int a2, int a3, int a4, int a5, int a6);

extern "C" int func_00210B58(void* self, int ok)
{
    if (ok != 0) {
        char* name = (char*)self + 0x9C;
        if (func_00258160(D_004A2EEC, name, 0x41) != 0) {
            func_00210BD8(self, name, 0);
        } else {
            // PORT: func_00210F40's unit definition takes these string pointers as int.
            func_00210F40(self, 0, (int)D_004A2560, (int)D_004A2560, 0, 0, 0x3D);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210BD8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" void* cBXString_Concat(void* self, const char* str);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void func_003A19F8(void* text, char* str);
extern "C" void func_001A83D8(void* list, int keep, unsigned int sel, int a3, int pos, int a5, int a6, int trim);
extern void* D_004A28A8;
extern char D_0046E808[];
extern char D_00534FB8[];
extern char D_00534FC8[];
extern char D_004A2710[];

struct sBXString_00210BD8 {
    char* str;
    sBXString_00210BD8() {}
    sBXString_00210BD8(const sBXString_00210BD8& o);
};

extern "C" void func_00210BD8(void* self, char* name, int a)
{
    char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E808));
    if (obj == 0) {
        return;
    }
    unsigned short c8 = *(unsigned short*)(obj + 0xC8);
    unsigned short c4 = *(unsigned short*)(obj + 0xC4);
    unsigned short c6 = *(unsigned short*)(obj + 0xC6);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (a != 0) {
        sBXString_00210BD8 s;
        cBXString_cBXString2(&s, D_00534FB8);
        cBXString_Concat(&s, D_004A2710);
        cBXString_Concat(&s, name);
        func_003A19F8(obj, s.str);
        cBXString__cBXString(&s, 2);
    } else {
        sBXString_00210BD8 s;
        cBXString_cBXString2(&s, D_00534FC8);
        cBXString_Concat(&s, D_004A2710);
        cBXString_Concat(&s, name);
        func_003A19F8(obj, s.str);
        cBXString__cBXString(&s, 2);
    }
    func_001A83D8(obj, 0x1E, 8, c8, c4, c6, 0, 1);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210D20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A2EEC;
extern char* D_net210D20 __asm__("D_004A2EEC");
extern "C" void func_0020E900(void* self);
extern "C" void* func_0039F698(void* list);
extern "C" int func_00258160(int a, char* name, int len);
extern "C" void func_00210BD8(void* self, char* name, int a);

extern "C" void func_00210D20(void* self)
{
    func_0020E900(self);
    char* p = D_net210D20;
    if (p != 0) {
        int ok = *(int*)(p + 0x68) == 0 || *(int*)(p + 0x64) == 0;
        if (ok) {
            func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
            *(int*)((char*)self + 0x1C) = (*(int*)((char*)self + 0x1C) & ~0x3F00) | 0x780;
        }
    }
    if (*(int*)((char*)self + 0x40) != 0) {
        char* name = (char*)self + 0x9C;
        if (func_00258160(D_004A2EEC, name, 0x41) != 0) {
            func_00210BD8(self, name, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210DD0);
#ifdef SKIP_ASM
extern "C" void func_00210DD0(void* self, int a1, int a2)
{
    if (a2 == 0x16) {
        if (a1 == *(int*)((char*)self + 0xe0)) {
            *(int*)((char*)self + 0xe0) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210DF0);
#ifdef SKIP_ASM
extern int D_004A2EEC;
extern char D_004A2560[];
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_0020A6A8(void* self);
extern "C" void func_00258C50(int a, char* name);
// PORT: func_0039F190 returns the last node it touched; bound with its value return.
void* func_0039F190_r(void* list, int a1) __asm__("func_0039F190");
extern "C" int strlen(const char* s);

extern "C" void func_00210DF0(void* self, void* item, unsigned int key)
{
    if (*(int*)((char*)self + 0x40) == 0) {
        return;
    }
    switch (key) {
    case 6:
        if (*(int*)((char*)self + 0xE0) == 0) {
            func_0039F190_r(*(char**)((char*)self + 0x10) + 0x18, 1);
            *(int*)((char*)self + 0x1C) = (*(int*)((char*)self + 0x1C) & ~0x3F00) | 0x780;
        }
        break;
    case 5:
        if (*(int*)((char*)self + 0xE0) == 0) {
            // PORT: func_00210F40's unit definition takes these string pointers as int.
            func_00210F40(self, 0, (int)D_004A2560, (int)D_004A2560, 0, 0, 0x3D);
            func_001CE3C8(*(void**)((char*)self + 0xE0), 0x4B, 1, 2);
        }
        break;
    case 0xD: {
        char* name = (char*)self + 0x9C;
        if (func_00258160(D_004A2EEC, name, 0x41) != 0) {
            func_00210BD8(self, name, 0);
        }
        char* p = *(char**)((char*)self + 0xE0) + 0x74;
        if (strlen(p) != 0) {
            func_00258C50(D_004A2EEC, p);
            func_00210BD8(self, p, 1);
        }
        break;
    }
    default:
        func_0020A6A8(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210F40);
#ifdef SKIP_ASM
extern "C" void func_00210FA0(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_001CCF00(void* p, int a);
extern "C" void func_001CB418(void* p, int a);

extern "C" void func_00210F40(void* self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    func_00210FA0(self, a1, a4, a5, a6);
    func_001CCF00(*(void**)((char*)self + 0xE0), a2);
    func_001CB418(*(void**)((char*)self + 0xE0), a3);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00210FA0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001CB030(void* mem, void* engine, void* owner, int a3, int a4);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_001CD088(void* self, int v);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_001CE468(void* self, int v);
extern char D_0046EFD0[];

extern "C" void func_00210FA0(void* self, int a1, int a2, int a3, int a4)
{
    void* w = func_001CB030(cMemMan_alloc(0x444, D_0046EFD0, 0x100, 0), *(void**)((char*)self + 0x10), self, a2, 0xF);
    *(void**)((char*)self + 0xE0) = w;
    func_0039F290((char*)*(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, w);
    *(int*)((char*)*(void**)((char*)self + 0xE0) + 0x18) = a3;
    func_001CD088(*(void**)((char*)self + 0xE0), a4);
    *(int*)((char*)*(void**)((char*)self + 0xE0) + 0x43C) = 0;
    func_001CE3C8(*(void**)((char*)self + 0xE0), 0x4B, 1, 2);
    func_001CE468(*(void**)((char*)self + 0xE0), 1);
    *(int*)((char*)*(void**)((char*)self + 0xE0) + 0x440) = 1;
    *(int*)((char*)self + 0xDC) = a1;
}
#endif

INCLUDE_ASM("fe/ovstatetrophy", func_00211088);

