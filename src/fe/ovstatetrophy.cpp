#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

struct sColour {
    float r, g, b, a;
    sColour(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

// A UI widget as cUIScreen_getObjectByHashName returns it: vptr at 0x8. Slot names from the prototype's
// _vt$8cUIThing (as in fe/feasyncfile); the other slots are known only by position.
class cUIThing {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void setEnabled(int on);
    virtual void setFocus(int on);
    virtual void setStatic(int v);
    virtual void setVisible(int v);
    virtual void v10();
    virtual int v11(const sColour& c);
};

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

extern "C" void func_0020E9A0(void* self, cUIThing* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        item->v11(sColour(1.0f, 1.0f, 0.0f, 0.0f));
        void* r = 0;
        if (*(int*)((char*)item + 0x18) == 1) {
            void* obj = **(void***)((char*)self + 0x10);
            sVEntry<void*(void*, void*, int)>* vt = *(sVEntry<void*(void*, void*, int)>**)((char*)obj + 4);
            r = vt[4].fn((char*)obj + vt[4].delta, self, 1);
        }
        func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        break;
    }
    case 6: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry<void*(void*, void*, int)>* vt = *(sVEntry<void*(void*, void*, int)>**)((char*)obj + 4);
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

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_0020EDA0);
#ifdef SKIP_ASM
// The render device's 2D state block (as in fe/ovstatehud and render/lightman).
struct sGs_EDA0 {
    unsigned int w0;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 5;
    unsigned int f4_12 : 8;
    unsigned int f4_20 : 2;
    unsigned int f4_22 : 1;
    unsigned int f4_23 : 2;
    unsigned int f4_25 : 7;
    int w8;
    unsigned int wC;
    unsigned int f10 : 16;
    unsigned int f10hi : 16;
    // Replace the bits under mask (bits 5..9 of word 8 = the primitive/alpha mode).
    void SetBits(int mask, int bits) { int w = w8 & ~mask; w8 = w | bits; }
    void SetPrim(int t) { SetBits(0x3E0, t << 5); }
};

struct sPos_EDA0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVert_EDA0 {
    float u, v, q, f0C;
    int r, g, b, a;
    sPos_EDA0 pos;
    sVert_EDA0() {}
};

class cGfx_EDA0 {
public:
    char pad[0xE84];
    sGs_EDA0* stateTop;
    char padE88[0x10D8 - 0xE88];
    void PushState() { stateTop[1] = stateTop[0]; stateTop++; }
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual void Begin2D();
    virtual void End2D();
    virtual void v32();
    virtual void SetTexture(void*);
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void DrawPrims(int n, sVert_EDA0* v, int flags);
};
extern cGfx_EDA0* D_004A289C_EDA0 __asm__("D_004A289C");
extern sGs_EDA0 D_00501420_EDA0 __asm__("D_00501420");
extern char D_004FF1A0[];

// The rider's cBeing interface (rider + 0x6C0), slots in the prototype's order (as in seg/seg_1FBE38).
struct t4Vector;
struct t4Matrix;
struct tInstanceRecord;
class cBeing_EDA0 {
public:
    virtual ~cBeing_EDA0();
    virtual const t4Vector* getVelocity() const;
    virtual int isIntersecting(tInstanceRecord* rec) const;
    virtual void applyBoost(const t4Vector& impulse);
    virtual const t4Vector* getPosition() const;
    virtual const t4Matrix* getTransform() const;
    virtual int getAIIndex() const;
    virtual bool isHuman() const;
};

struct sTex_EDA0 {
    int handle;     // 0x00
    char pad4[8];
    int GetHandle() { return handle; }
    float v0;       // 0x0C
    float u0;       // 0x10
    float u1;       // 0x14
    float v1;       // 0x18
};
// Trophy-room icon table (func_0020EB50 loads the textures): name hash, icon size, texture.
struct sIcon_EDA0 {
    int name;
    float w;
    float h;
    sTex_EDA0* tex;
};
extern sIcon_EDA0 D_004C8C58_EDA0[] __asm__("D_004C8C58");

struct sSlot_EDA0 {
    int active;
    int seg;
    float dist;
    float pos;
    float rel;
    int relValid;
};
extern sSlot_EDA0 D_004C8BC8_EDA0[6] __asm__("D_004C8BC8");

struct sMarker_EDA0 {
    int type;
    float dist;
};

// The trophy box (func_0020EC18 lays it out).
struct sTrophyBox_EDA0 {
    float x, y;         // 0x00 text position
    float top;          // 0x08
    float bottom;       // 0x0C
    float cx;           // 0x10
    float y14;          // 0x14
    float y18;          // 0x18
    float s1C;          // 0x1C
    float rx, ry, rw, rh; // 0x20
    float scale;        // 0x30
    int last;           // 0x34
};

struct sColour_EDA0 {
    float r, g, b, a;
};
struct sV2_EDA0 {
    float x, y;
};
struct sFont_EDA0 {
    char pad0[0x28];
    sV2_EDA0 scale;     // 0x28
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sColour_EDA0 color; // 0x40
    sColour_EDA0 color2; // 0x50
    // Written through float pointers: typed member stores (f38 = f30 * sx) leave the global font
    // pointer cached across them, where the target reloads it (96.7%).
    void SetScale(float sx, float sy)
    {
        *(float*)((char*)this + 0x38) = *(float*)((char*)this + 0x30) * sx;
        *(float*)((char*)this + 0x3C) = *(float*)((char*)this + 0x34) * sy;
    }
};
extern sFont_EDA0* D_004A2764_EDA0 __asm__("D_004A2764");
extern int D_004A4EB4;
extern int D_004A4EB8;
extern int D_004A4EC8;
extern sColour_EDA0 D_004C6868;
extern sColour_EDA0 D_004C6878;
extern sV2_EDA0 D_004A4EC0;
extern char D_004A2690[];
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_00392908(void* font, const char* str, float x, float y);

extern int D_004A275C;
extern char* D_004A2758;
extern int D_005308D0[];

// The race (D_004A28A8->0x84->0xC; as in seg/seg_1FBE38): rider objects at 0x28, rider count at 0x78.
struct sRace_EDA0 {
    char pad[0x28];
    char* riders[6];    // 0x28
    char* players[12];  // 0x40
    char pad70[0x8];
    int count;          // 0x78
};
static inline float limitStep_EDA0(float v, float prev, float lim)
{
    float dd = v - prev;
    if (dd > lim)
        v = prev + lim;
    else if (dd < -lim)
        v = prev - lim;
    return v;
}


extern "C" void func_0020EDA0(sTrophyBox_EDA0* self, char* rider)
{
    if (D_004A2760 != 0)
        return;
    if (D_004A275C == 0)
        return;
    if (rider == 0)
        return;
    sMarker_EDA0* markers = (sMarker_EDA0*)D_004A2758;
    char* course = D_004A2750;
    if (course == 0)
        return;
    int me = ((cBeing_EDA0*)(rider + 0x6C0))->getAIIndex();
    sRace_EDA0* race = *(sRace_EDA0**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    float myDist = D_004C8BC8_EDA0[me].dist;
    float myPos = D_004C8BC8_EDA0[me].pos;
    int n = race->count;
    for (int i = 0; i < 6; i++) {
        if (self->last != me)
            D_004C8BC8_EDA0[i].relValid = 0;
        if (i < n) {
            float d = D_004C8BC8_EDA0[i].pos - myPos;
            if (d < -2000.0f)
                d = -2000.0f;
            else if (d > 2000.0f)
                d = 2000.0f;
            if (D_004C8BC8_EDA0[i].relValid != 0)
                d = limitStep_EDA0(d, D_004C8BC8_EDA0[i].rel, 46.29629898071289f);
            D_004C8BC8_EDA0[i].rel = d;
            D_004C8BC8_EDA0[i].relValid = 1;
        }
    }
    sVert_EDA0 v[4];
    for (int i = 0; i < 4; i++) {
        v[i].r = 0x80;
        v[i].g = 0x80;
        v[i].b = 0x80;
        v[i].a = 0x80;
        v[i].q = 1.0f;
    }
    D_004A289C_EDA0->Begin2D();
    D_004A289C_EDA0->PushState();
    *D_004A289C_EDA0->stateTop = D_00501420_EDA0;
    D_004A289C_EDA0->stateTop->f4_23 = 2;
    D_004A289C_EDA0->stateTop->f4_20 = 0;
    D_004A289C_EDA0->stateTop->f4_12 = 0x14;
    D_004A289C_EDA0->stateTop->f4_2 = 5;
    D_004A289C_EDA0->SetTexture(D_004FF1A0);

    float lo = myDist - 5000.0f;
    float hi = lo + 10000.0f;
    float frac = D_004C8BC8_EDA0[me].dist / *(float*)(course + 0x10);
    if (D_004A4EB4 == 0) {
        D_004C6868.r = 1.0f;
        D_004C6868.g = 1.0f;
        D_004C6868.b = 1.0f;
        D_004C6868.a = 1.0f;
        D_004A4EB4 = 1;
    }
    if (D_004A4EB8 == 0) {
        D_004C6878.r = 1.0f;
        D_004C6878.g = 0.0f;
        D_004C6878.b = 0.0f;
        D_004C6878.a = 0.0f;
        D_004A4EB8 = 1;
    }
    if (D_004A4EC8 == 0) {
        D_004A4EC0.x = 2.0f;
        D_004A4EC0.y = 2.0f;
        D_004A4EC8 = 1;
    }
    char buf[16];
    sprintf(buf, D_004A2690, (int)(frac * 100.0f + 0.5f));
    D_004A2764_EDA0->color = D_004C6868;
    D_004A2764_EDA0->SetScale(0.666700005531311f, 0.666700005531311f);
    D_004A2764_EDA0->color2 = D_004C6878;
    D_004A2764_EDA0->scale = D_004A4EC0;
    D_004A289C_EDA0->stateTop->SetPrim(10);
    func_00392908(D_004A2764_EDA0, buf, self->x, self->y);
    D_004A2764_EDA0->SetScale(1.0f, 1.0f);

    sIcon_EDA0* arrow = &D_004C8C58_EDA0[4];
    sTex_EDA0* atex = arrow->tex;
    for (int i = 0; i < n; i++) {
        float d = D_004C8BC8_EDA0[i].dist;
        if (lo <= d && d <= hi)
            continue;
        float va = atex->v1;
        float vb = atex->v0;
        float y = self->bottom;
        // retail scale literal is 0x3BA3D70B, one ulp above 0.005f
        float ax = self->cx + -D_004C8BC8_EDA0[i].rel * 0.0050000004f;
        float hw = arrow->w * 0.5f;
        if (d > hi) {
            y = self->top;
            va = atex->v0;
            vb = atex->v1;
        }
        v[0].u = atex->u0;
        v[0].v = va;
        v[1].u = atex->u1;
        v[1].v = va;
        v[2].u = atex->u0;
        v[2].v = vb;
        v[3].u = atex->u1;
        v[3].v = vb;
        sPos_EDA0 p;
        p.x = ax - hw;
        p.y = y;
        p.z = 0.0f;
        p.w = 1.0f;
        v[0].pos = p;
        p.x = ax + hw;
        p.y = y;
        p.z = 0.0f;
        p.w = 1.0f;
        v[1].pos = p;
        p.x = ax - hw;
        p.y = y + arrow->h;
        p.z = 0.0f;
        p.w = 1.0f;
        v[2].pos = p;
        p.x = ax + hw;
        p.y = y + arrow->h;
        p.z = 0.0f;
        p.w = 1.0f;
        v[3].pos = p;
        D_004A289C_EDA0->stateTop->SetPrim(10);
        *(short*)((char*)D_004A289C_EDA0->stateTop + 0x10) = atex->GetHandle();
        D_004A289C_EDA0->DrawPrims(4, v, 0);
    }

    sTex_EDA0* tex = D_004C8C58_EDA0[0].tex;
    float barTop = self->y18;
    float barBottom = self->y14;
    if (*(float*)(course + 0x10) < hi)
        barBottom += (hi - *(float*)(course + 0x10)) * self->s1C;
    if (lo < 0.0f)
        barTop += lo * self->s1C;
    v[0].u = tex->u0;
    v[0].v = tex->v0;
    v[1].u = tex->u1;
    v[1].v = tex->v0;
    v[2].u = tex->u0;
    v[2].v = tex->v1;
    v[3].u = tex->u1;
    v[3].v = tex->v1;
    sPos_EDA0 p;
    p.x = self->cx - 5.499532222747803f;
    p.y = barTop;
    p.z = 0.0f;
    p.w = 1.0f;
    v[0].pos = p;
    p.x = self->cx + 5.499532222747803f;
    p.y = barTop;
    p.z = 0.0f;
    p.w = 1.0f;
    v[1].pos = p;
    p.x = self->cx - 5.499532222747803f;
    p.y = barBottom;
    p.z = 0.0f;
    p.w = 1.0f;
    v[2].pos = p;
    p.x = self->cx + 5.499532222747803f;
    p.y = barBottom;
    p.z = 0.0f;
    p.w = 1.0f;
    v[3].pos = p;
    D_004A289C_EDA0->stateTop->SetPrim(9);
    *(short*)((char*)D_004A289C_EDA0->stateTop + 0x10) = tex->GetHandle();
    D_004A289C_EDA0->DrawPrims(4, v, 0);

    float markY = barTop + (barBottom - barTop) * frac;
    p.x = self->cx - 2.7497661113739014f;
    p.y = barTop;
    p.z = 0.0f;
    p.w = 1.0f;
    v[0].pos = p;
    p.x = self->cx + 2.7497661113739014f;
    p.y = barTop;
    p.z = 0.0f;
    p.w = 1.0f;
    v[1].pos = p;
    p.x = self->cx - 2.7497661113739014f;
    p.y = markY;
    p.z = 0.0f;
    p.w = 1.0f;
    v[2].pos = p;
    p.x = self->cx + 2.7497661113739014f;
    p.y = markY;
    p.z = 0.0f;
    p.w = 1.0f;
    v[3].pos = p;
    for (int i = 0; i < 4; i++) {
        v[i].r = 0x80;
        v[i].g = 0;
        v[i].b = 0;
    }
    D_004A289C_EDA0->stateTop->SetPrim(10);
    *(short*)((char*)D_004A289C_EDA0->stateTop + 0x10) = -1;
    D_004A289C_EDA0->DrawPrims(4, v, 0);
    for (int i = 0; i < 4; i++) {
        v[i].r = 0x80;
        v[i].g = 0x80;
        v[i].b = 0x80;
    }

    float margin = 20.0f / self->s1C;
    float lo2 = lo - margin;
    float hi2 = hi + margin;
    for (int i = 0; i < n; i++) {
        float d = D_004C8BC8_EDA0[i].dist;
        if (d < lo2)
            continue;
        if (d > hi2)
            continue;
        float x = self->cx;
        float y = self->y18 - (d - lo) * self->s1C;
        int prim = 0xC;
        int icon = 1;
        if (me != i) {
            x -= D_004C8BC8_EDA0[i].rel * 0.0050000004f;
            char* r = race->riders[i];
            if (((cBeing_EDA0*)(r + 0x6C0))->isHuman()) {
                prim = 0xD;
                icon = 3;
            } else {
                prim = 0xE;
                icon = 2;
            }
        }
        sIcon_EDA0* e = &D_004C8C58_EDA0[icon];
        sTex_EDA0* t = e->tex;
        float hh = e->h * 0.5f;
        float y0 = y - hh;
        float y1 = y + hh;
        if (self->y18 <= y0)
            continue;
        if (y1 <= self->y14)
            continue;
        float va = t->v0;
        float vb = t->v1;
        if (y0 < self->y14) {
            va = vb + (va - vb) * (y1 - self->y14) / (hh * 2.0f);
            y0 = self->y14;
        } else if (self->y18 < y1) {
            vb = va + (vb - va) * (self->y18 - y0) / (hh * 2.0f);
            y1 = self->y18;
        }
        v[0].u = t->u0;
        v[0].v = va;
        v[1].u = t->u1;
        v[1].v = va;
        v[2].u = t->u0;
        v[2].v = vb;
        v[3].u = t->u1;
        v[3].v = vb;
        float hw = e->w * 0.5f;
        p.x = x - hw;
        p.y = y0;
        p.z = 0.0f;
        p.w = 1.0f;
        v[0].pos = p;
        p.x = x + hw;
        p.y = y0;
        p.z = 0.0f;
        p.w = 1.0f;
        v[1].pos = p;
        p.x = x - hw;
        p.y = y1;
        p.z = 0.0f;
        p.w = 1.0f;
        v[2].pos = p;
        p.x = x + hw;
        p.y = y1;
        p.z = 0.0f;
        p.w = 1.0f;
        v[3].pos = p;
        D_004A289C_EDA0->stateTop->SetPrim(prim);
        *(short*)((char*)D_004A289C_EDA0->stateTop + 0x10) = t->GetHandle();
        D_004A289C_EDA0->DrawPrims(4, v, 0);
    }

    if (*(int*)(course + 8) != 0) {
        int show = 1;
        if ((D_005308D0[0] >> 9) & 1) {
            if (*(int*)(*(char**)((char*)D_004A28A8 + 0xC0) + 0x88) != 0)
                show = 0;
        }
        for (int i = 0; i < *(int*)(course + 8); i++) {
            float d = markers[i].dist;
            if (d < lo2)
                continue;
            if (d > hi2)
                continue;
            if (markers[i].type == 1 && !show)
                continue;
            sIcon_EDA0* e = &D_004C8C58_EDA0[markers[i].type + 5];
            sTex_EDA0* t = e->tex;
            float y = self->y18 - (d - lo) * self->s1C;
            float hw = e->w * 0.5f;
            float hh = e->h * 0.5f;
            float y0 = y - hh;
            float y1 = y + hh;
            if (self->y18 <= y0)
                continue;
            if (y1 <= self->y14)
                continue;
            float va = t->v0;
            float vb = t->v1;
            if (y0 < self->y14) {
                va = vb + (va - vb) * (y1 - self->y14) / e->h;
                y0 = self->y14;
            } else if (self->y18 < y1) {
                vb = va + (vb - va) * (self->y18 - y0) / e->h;
                y1 = self->y18;
            }
            v[0].u = t->u0;
            v[0].v = va;
            v[1].u = t->u1;
            v[1].v = va;
            v[2].u = t->u0;
            v[2].v = vb;
            v[3].u = t->u1;
            v[3].v = vb;
            p.x = self->cx - hw;
            p.y = y0;
            p.z = 0.0f;
            p.w = 1.0f;
            v[0].pos = p;
            p.x = self->cx + hw;
            p.y = y0;
            p.z = 0.0f;
            p.w = 1.0f;
            v[1].pos = p;
            p.x = self->cx - hw;
            p.y = y1;
            p.z = 0.0f;
            p.w = 1.0f;
            v[2].pos = p;
            p.x = self->cx + hw;
            p.y = y1;
            p.z = 0.0f;
            p.w = 1.0f;
            v[3].pos = p;
            D_004A289C_EDA0->stateTop->SetPrim(0xB);
            *(short*)((char*)D_004A289C_EDA0->stateTop + 0x10) = t->GetHandle();
            D_004A289C_EDA0->DrawPrims(4, v, 0);
        }
    }
    D_004A289C_EDA0->stateTop--;
    D_004A289C_EDA0->End2D();
    self->last = me;
}
#endif

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

static inline float limitStep_210618(float v, float prev, const float& lim)
{
    float dd = v - prev;
    if (dd > lim)
        v = prev + lim;
    else if (dd < -lim)
        v = prev - lim;
    return v;
}

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
        d = limitStep_210618(d, D_004C8BC8_210618[i].dist, 138.88890075683594f);
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
class cUIText;

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
    cUIThing* t = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00471D00));
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
    cUIThing* e = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046E808));
    if (e != 0)
    {
        *(int*)((char*)e + 0x74) |= 1;
        func_003A1310(e, 1);
        e->setVisible(1);
        *(int*)((char*)e + 0x14) |= 0x80;
        e->v11(sColour(1.0f, 0.0f, 0.0f, 0.0f));
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

//100%
INCLUDE_ASM("fe/ovstatetrophy", func_00211088);
#ifdef SKIP_ASM
extern char D_00535BC8[];
extern char D_00472928[];
extern "C" void func_001D53B0(void* self, int a, int b);
extern "C" int func_00147318(void* iface, int i);
struct sOVTrophy_1088 {
    char pad_0x0[8];
    void* vtable;           // 0x8
    int f0C;                // 0xC
    char pad_0x10[0x1CC - 0x10];
    int f1CC;               // 0x1CC
    char pad_0x1D0[0x22C - 0x1D0];
    int f22C;               // 0x22C
    int f230;               // 0x230
    char pad_0x234[0x278 - 0x234];
    int f278;               // 0x278
};
extern "C" sOVTrophy_1088* func_00211088(sOVTrophy_1088* self, int a, unsigned char b, int c)
{
    int idx = 0;
    func_001D53B0(self, a, 0);
    self->f0C = 0x24;
    self->vtable = D_00472928;
    self->f278 = c;
    self->f1CC = 0;
    self->f22C = 0;
    self->f230 = 0;
    int i;
    for (i = 1; i < 9; i++) {
        b >>= i;
        if (b == 0) {
            idx = i - 1;
            break;
        }
    }
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int lim = 1;
    if (D_00535BC8[0x49] == 2) lim = 2;
    for (int n = 0; n < lim; n++) {
        if (func_00147318(iface, n) == idx) {
            self->f1CC = n;
            break;
        }
    }
    return self;
}
#endif

