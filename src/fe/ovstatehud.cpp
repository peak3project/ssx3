#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

struct cOVStateHUDElem {
    int field_0x0;
    int field_0x4;
    float rangeMin; // 0x8
    float rangeMax; // 0xc
    float x; // 0x10
    float y; // 0x14
    float z; // 0x18
    float w; // 0x1c
};

// Declarations shared by the functions of this unit.
struct sGlyphTable_1F14B0;
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" float func_003921F0(void* self, const unsigned short* str, void* out, int n, float sx, float sy);
extern "C" void func_001E92A8(void* self);
extern "C" unsigned short* func_002C2508(unsigned short* dst, unsigned short* src);
extern "C" void* func_0039E2A0(void *, int);
extern char* D_004A289C;
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);
extern "C" void func_00391E30(void* self, float x, float y, const unsigned short* str);

//100%
INCLUDE_ASM("fe/ovstatehud", cOVStateHiScoreList_onCreateScreen);
#ifdef SKIP_ASM
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0020A380(void* self);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);
extern signed char D_00535C10[];
extern char D_0046E9D8[];
extern char D_0046E9E8[];
extern char D_0046E9F8[];
extern char D_0046EA08[];
extern char D_0046EA18[];

static inline int HasScores1E8FF0(char* hs)
{
    return *(int*)(hs + 0x18) >= 0 || *(int*)(hs + 0x1C) >= 0;
}

// Builds the hi-score list screen and shows/hides its panels for the current game mode.
extern "C" void cOVStateHiScoreList_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046E9D8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    switch (D_00535C10[0]) {
    case 0: case 5:
        cUIState_showObjSafe(self, D_0046E9E8);
        break;
    case 1: case 2: case 3: case 4: case 6:
    default:
        cUIState_hideObjSafe(self, D_0046E9F8);
        break;
    }
    char* hs = (char*)cBE_getInterface_Fv(cBE_getBE(), 8);
    if (!HasScores1E8FF0(hs)) {
        cUIState_hideObjSafe(self, D_0046EA08);
        cUIState_hideObjSafe(self, D_0046EA18);
    }
    func_00294F78(func_0028B180(), 0xE);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E9130);
#ifdef SKIP_ASM
struct sObj001E9130 {
    int field_0x0;
    sVEntry<void*(void*, void*, int)>* vt;
};

extern "C" void func_0039F400(void* list, void* item);

extern "C" void func_001E9130(void* self, void* item, int a2)
{
    if (item != 0 && a2 == 5) {
        void* r = 0;
        if (*(int*)((char*)item + 0x18) == 1) {
            sObj001E9130* o = **(sObj001E9130***)((char*)self + 0x10);
            r = o->vt[4].fn((char*)o + o->vt[4].delta, self, 1);
        }
        func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E91A8__FPvT0);
#ifdef SKIP_ASM
void func_001E91A8(void* self, void* a1)
{
    cOVStateHUDElem* e = (cOVStateHUDElem*)self;
    float* out = (float*)a1;
    out[0] = e->x;
    out[1] = e->y;
    out[2] = e->z;
    out[3] = e->w;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E91D0__FPvT0);
#ifdef SKIP_ASM
void func_001E91D0(void* self, void* a1)
{
    cOVStateHUDElem* e = (cOVStateHUDElem*)self;
    float* out = (float*)a1;
    out[3] = e->x;
    out[0] = e->y;
    out[1] = e->z;
    out[2] = e->w;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E91F8);
#ifdef SKIP_ASM
extern "C" void func_001E91F8(void* self, void* a1)
{
    short* in = (short*)self;
    float* out = (float*)a1;
    out[0] = in[0];
    out[1] = in[1];
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E9220);
#ifdef SKIP_ASM
extern "C" void func_001E9220(void* self, void* a1, void* a2)
{
    short* in = (short*)self;
    float* out = (float*)a1;
    float* def = (float*)a2;
    float x = in[2];
    if (x >= 0.0f) {
        out[0] = x;
    } else {
        out[0] = 0.0f;
        if (def != 0) {
            out[0] = def[1];
        }
    }
    float y = in[3];
    if (y >= 0.0f) {
        out[1] = y;
    } else {
        out[1] = 0.0f;
        if (def != 0) {
            out[1] = def[2];
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E9290__FPvT0);
#ifdef SKIP_ASM
float func_001E9290(void* self, void* a1)
{
    cOVStateHUDElem* e = (cOVStateHUDElem*)self;
    float t0 = e->rangeMin;
    *(float*)a1 = t0;
    *(float*)((char*)a1 + 0x4) = e->rangeMax;
    return t0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E92A8);
#ifdef SKIP_ASM
struct sFont_92A8 {
    char pad0[0x14];
    int lineCount;      // 0x14
    char pad18[0x18];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
};

struct sTok_92A8 {
    int hash;           // 0x00
    char pad4[8];
    float width;        // 0x0C
    float height;       // 0x10
    char pad14[0x24 - 0x14];
};

extern sTok_92A8 D_004C8980[];

struct sLine_92A8 {
    float w;
    void* str;
};

struct sBox_92A8 {
    float total;        // 0x00
    float height;       // 0x04
    sFont_92A8* font;   // 0x08
    float pad0C;        // 0x0C
    float scaleX;       // 0x10
    float scaleY;       // 0x14
    int count;          // 0x18
    sLine_92A8 lines[6]; // 0x1C
    unsigned short text[1]; // 0x4C
};

extern "C" void func_001E92A8(void* vself)
{
    sBox_92A8* self = (sBox_92A8*)vself;
    sFont_92A8* font = self->font;
    font->f38 = font->f30 * self->scaleX;
    font->f3C = font->f34 * self->scaleY;
    self->lines[0].w = 0;
    int n = 0;
    float maxH = self->lines[0].w;
    self->count = 0;
    self->lines[0].str = self->text;
    unsigned short* p = self->text;
    sLine_92A8* lines = self->lines;
    float total = maxH;
    unsigned short tmp[8];
    if (*p != 0) {
        do {
            if (*p == '@') {
                *p = 0;
                sLine_92A8* l = (sLine_92A8*)(n * 8 + (int)lines);
                p++;
                if (*(unsigned short*)l->str != 0) {
                    float w = func_003921F0(font, (unsigned short*)l->str, tmp, 1, font->f38, font->f3C);
                    total += w;
                    l->w = w;
                }
                n++;
                char name[0x20];
                char* d = name;
                do {
                    if (*p == 0x20) break;
                    if (*p == 0) break;
                    *d++ = *(char*)p;
                    p++;
                } while (1);
                *d = 0;
                int h = GetHashValue32(name);
                sTok_92A8* found = 0;
                sTok_92A8* t = D_004C8980;
                while (t->hash != 0) {
                    if (t->hash == h) {
                        found = t;
                        break;
                    }
                    t++;
                }
                lines[n].str = found;
                float fw = found->width;
                lines[n].w = fw;
                total += fw;
                n++;
                if (maxH < found->height)
                    maxH = found->height;
                lines[n].str = p;
                lines[n].w = 0;
                if (*p != 0)
                    p++;
            } else {
                p++;
            }
        } while (*p != 0);
    }
    sLine_92A8* l = (sLine_92A8*)(n * 8 + (int)lines);
    if (*(unsigned short*)l->str != 0) {
        float w = func_003921F0(font, (unsigned short*)l->str, tmp, 0, font->f38, font->f3C);
        n++;
        total += w;
        l->w = w;
    }
    self->count = n;
    float lineH = (float)font->lineCount * font->f34 * self->scaleY;
    self->total = total;
    float hh = lineH >? maxH;
    self->height = hh;
    self->pad0C = (hh - lineH) * 0.5f;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/ovstatehud", func_001E94E0);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C2540(unsigned short* dst, char* src);
struct sVec2f { float x, y; };

extern "C" void func_001E94E0(void* self, char* str, int a2, sVec2f* pos)
{
    func_002C2540((unsigned short*)((char*)self + 0x4C), str);
    *(int*)((char*)self + 0x8) = a2;
    *(sVec2f*)((char*)self + 0x10) = *pos;
    func_001E92A8(self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/ovstatehud", func_001E9540);
#ifdef SKIP_ASM
extern "C" void func_001E9540(void* self, unsigned short* str, int a2, sVec2f* pos)
{
    func_002C2508((unsigned short*)((char*)self + 0x4C), str);
    *(int*)((char*)self + 0x8) = a2;
    *(sVec2f*)((char*)self + 0x10) = *pos;
    func_001E92A8(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E95A0);
#ifdef SKIP_ASM
struct sColour_95A0 {
    float r, g, b, a;
};

// 2-float vector (EA's t2Vector) with an index operator; read through a const reference it returns by value.
struct t2Vector_95A0 {
    float x, y;
    float& operator[](int i) { return (&x)[i]; }
    float operator[](int i) const { return (&x)[i]; }
};

struct sVtxPos_95A0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sHudVertex_95A0 {
    float u, v, q, pad;     // 0x00
    int g, b, a, r;         // 0x10
    sVtxPos_95A0 pos;       // 0x20
    sHudVertex_95A0() {}
};

struct sFont_95A0 {
    char pad0[0x30];
    float f30;              // 0x30
    float f34;              // 0x34
    float f38;              // 0x38
    float f3C;              // 0x3C
    sColour_95A0 color;     // 0x40
    sColour_95A0 color2;    // 0x50
};

// An inline icon of the text: texture, size and UV rectangle.
struct sHudIcon_95A0 {
    int hash;               // 0x00
    int pad4;
    int tex;                // 0x08
    float width;            // 0x0C
    float height;           // 0x10
    float u0, v0, u1, v1;   // 0x14..0x20
};

// One run of the laid-out text: even runs are text, odd runs are icons.
struct sLine_95A0 {
    float w;
    void* str;
};

struct sBox_95A0 {
    float total;            // 0x00
    float height;           // 0x04
    sFont_95A0* font;       // 0x08
    float pad0C;            // 0x0C
    float scaleX;           // 0x10
    float scaleY;           // 0x14
    int count;              // 0x18
    sLine_95A0 lines[6];    // 0x1C
};

static inline int texOf_95A0(sHudIcon_95A0* e)
{
    return e->tex;
}

// The font's character scale: base size (0x30) times s.
static inline void setScale_95A0(sFont_95A0* f, const t2Vector_95A0& s)
{
    f->f38 = f->f30 * s.x;
    f->f3C = f->f34 * s.y;
}

// Draws the text laid out by func_001E92A8 at pos (moved by the alignment: 0 centre, > 0 right/bottom), scaled and
// tinted; icons are drawn as sprite quads between the text runs.
extern "C" void func_001E95A0(sBox_95A0* self, t2Vector_95A0& pos, const t2Vector_95A0& scale, sColour_95A0* col, int alignX, int alignY)
{
    if (self->count != 0) {
        sFont_95A0* font = self->font;
        sColour_95A0 saved = font->color2;
        sColour_95A0 mod = saved;
        t2Vector_95A0 sc;
        mod.r *= col->r;
        sc.x = self->scaleX * scale[0];
        sc.y = self->scaleY * scale[1];
        setScale_95A0(font, sc);
        self->font->color = *col;
        self->font->color2 = mod;
        if (alignX == 0) {
            pos[0] -= self->total * scale[0] * 0.5f;
        } else if (alignX > 0) {
            pos[0] -= self->total * scale[0];
        }
        if (alignY == 0) {
            pos[1] -= self->height * scale[1] * 0.5f;
        } else if (alignY > 0) {
            pos[1] -= self->height * scale[1];
        }
        float lh = self->pad0C * scale[1];
        float cy = pos[1] + self->height * scale[1] * 0.5f;
        sHudVertex_95A0 v[4];
        t2Vector_95A0 sz;
        for (int i = 0; i < 4; i++) {
            int r = (int)(col->r * 128.0f);
            int g = (int)(col->g * 128.0f);
            int b = (int)(col->b * 128.0f);
            int a = (int)(col->a * 128.0f);
            v[i].r = r;
            v[i].g = g;
            v[i].b = b;
            v[i].a = a;
            v[i].q = 1.0f;
        }
        sLine_95A0* l = self->lines;
        for (int i = 0; i < self->count; i++, l++) {
            if (!(i & 1)) {
                unsigned short* s = (unsigned short*)l->str;
                if (*s != 0) {
                    func_00391E30(self->font, pos[0], pos[1] + lh, s);
                    pos[0] += l->w * scale[0];
                }
            } else {
                sHudIcon_95A0* e = (sHudIcon_95A0*)l->str;
                float w = e->width * scale[0];
                float h = e->height * scale[1];
                sz.x = w;
                sz.y = h;
                float x0 = pos[0];
                float x1 = x0 + w;
                float y0 = cy - h * 0.5f;
                float y1 = y0 + h;
                v[0].u = e->u0;
                v[0].v = e->v0;
                v[1].u = e->u1;
                v[1].v = e->v0;
                v[2].u = e->u0;
                v[2].v = e->v1;
                v[3].u = e->u1;
                v[3].v = e->v1;
                sVtxPos_95A0 p;
                p.x = x0;
                p.y = y0;
                p.z = 0.0f;
                p.w = 1.0f;
                v[0].pos = p;
                p.x = x1;
                p.y = y0;
                p.z = 0.0f;
                p.w = 1.0f;
                v[1].pos = p;
                p.x = x0;
                p.y = y1;
                p.z = 0.0f;
                p.w = 1.0f;
                v[2].pos = p;
                p.x = x1;
                p.y = y1;
                p.z = 0.0f;
                p.w = 1.0f;
                v[3].pos = p;
                *(short*)(*(char**)(D_004A289C + 0xE84) + 0x10) = texOf_95A0(e);
                sVEntry<void(void*, int, sHudVertex_95A0*, int)>* vt = *(sVEntry<void(void*, int, sHudVertex_95A0*, int)>**)(D_004A289C + 0x10D8);
                vt[71].fn(D_004A289C + vt[71].delta, 4, v, 0);
                pos[0] += sz.x;
            }
        }
        self->font->color2 = saved;
        sz.x = 1.0f;
        sz.y = 1.0f;
        setScale_95A0(self->font, sz);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E9A30);
#ifdef SKIP_ASM
extern "C" void* func_0020EAA0(void*);
extern char D_00474160[];

struct sElem_9A30 {
    void* operator new[](unsigned int, void* p) { return p; }
    char pad[8];
    char sub[0x84];
    sElem_9A30() { func_0020EAA0(sub); }
};

// HUD overlay state constructor: base state, vtable, the two sub-panels and default scales.
extern "C" void* func_001E9A30(void* arg0, int a1)
{
    char* self = (char*)arg0;
    func_0039E2A0(self, a1);
    *(char**)(self + 8) = D_00474160;
    new (self + 0x48) sElem_9A30[2];
    *(int*)(self + 0x474) = -1;
    *(int*)(self + 0x3D4) = 0;
    *(int*)(self + 0x3D8) = 0;
    *(float*)(self + 0x478) = 1.0f;
    *(float*)(self + 0x47C) = 1.0f;
    *(int*)(self + 0x480) = 0;
    *(int*)(self + 0x484) = 0;
    *(float*)(self + 0x488) = 1.0f;
    *(float*)(self + 0x48C) = 1.0f;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", cOVStateHUD1P_onCreateScreen);
#ifdef SKIP_ASM
extern "C" void* func_00398380(void* self, int id);
extern "C" int func_003983F0(void* self, int key);
extern "C" void func_001F10F8(void* self, float* out, float* pos, float* size, float* scale, int alignX, int alignY, int flags);
extern "C" void func_0020EB50(void* self, void* screen, void* rect);
extern "C" void func_003DCA40(unsigned short* dst, const char* src);
extern "C" void func_003DC9F8(unsigned short* dst, const unsigned short* fmt, ...);
unsigned int BXrand();
extern void* D_004A28A8;
extern char D_004A2108[];
extern char D_004A21F0[];
extern char D_004A20D0[];
extern char D_004A21F8[];
extern char D_004A2200[];
extern char D_004A2208[];
extern char D_004A2210[];
extern char D_004A2218[];
extern char D_004A2220[];
extern char D_004A2228[];
extern char D_004A2230[];
extern char D_004A2238[];
extern char D_004A2240[];
extern char D_004A2248[];
extern char D_004A2250[];
extern char D_004A2258[];
extern char D_004A2260[];
extern char D_004A2268[];
extern char D_004A2270[];
extern char D_004A2278[];
extern char D_0046EAB8[];
extern char D_0046EAC8[];
extern char D_0046EAD8[];
extern int D_004C88D8[26];
extern int D_004C8940[5][3];
extern char* D_004A21E4;
extern char* D_004A21EC;
extern char* D_004A21D0[2];
extern char* D_004A21D8;
extern sVec2f D_004A4F50;
extern sVec2f D_004A4F58;

struct t2Vector {
    float x, y;
    t2Vector() {}
    t2Vector(float x_, float y_) : x(x_), y(y_) {}
};

// HUD element layout record (0x24 bytes, const tables in .rodata).
struct sHudElem_9AD0 {
    short x, y;         // 0x00
    short w, h;         // 0x04
    float sx, sy;       // 0x08
    float col[4];       // 0x10
    char alignX;        // 0x20
    char alignY;        // 0x21
    char blend;         // 0x22
};
extern const sHudElem_9AD0 D_00477000;
extern const sHudElem_9AD0 D_00477B40;
extern const sHudElem_9AD0 D_00476940;
extern const sHudElem_9AD0 D_00477480;
extern const sHudElem_9AD0 D_00477048;
extern const sHudElem_9AD0 D_00477B88;
void getElemPos_9AD0(const sHudElem_9AD0* e, t2Vector* out) __asm__("func_001E91F8");
void getElemSize_9AD0(const sHudElem_9AD0* e, t2Vector* out, void* def) __asm__("func_001E9220");
void getElemScale_9AD0(const sHudElem_9AD0* e, t2Vector* out) __asm__("func_001E9290__FPvT0");

struct tARGB_9AD0 {
    float r, g, b, a;
    tARGB_9AD0() {}
    tARGB_9AD0(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

struct tRect_9AD0 {
    float x, y, w, h;
};

struct sUIItem_9AD0 {
    int handle;     // 0x00
    int f04;
    int f08;
    float y0;           // 0x0C
    float x0;           // 0x10
    float x1;           // 0x14
    float y1;           // 0x18
    float getX0() const { return x0; }
    float getY0() const { return y0; }
    float getX1() const { return x1; }
    float getY1() const { return y1; }
};

struct sTok_9AD0 {
    int hash;       // 0x00
    int name;       // 0x04
    int tex;        // 0x08
    float width;    // 0x0C
    float height;   // 0x10
    t2Vector uv0;   // 0x14
    t2Vector uv1;   // 0x1C
};
extern sTok_9AD0 D_004C8980_9AD0[] __asm__("D_004C8980");

class cBeing_9AD0 {
public:
    virtual ~cBeing_9AD0();
    virtual const void* getVelocity() const;
    virtual int isIntersecting(void* rec) const;
    virtual void applyBoost(const void* impulse);
    virtual const void* getPosition() const;
    virtual const void* getTransform() const;
    virtual int getAIIndex() const;
};

struct sRiderPanel {
    int aiIndex;        // 0x00
    int rider;          // 0x04
    char trophy[0x3C];  // 0x08
    int f44;            // 0x44
    float f48;          // 0x48
    float f4C;          // 0x4C
    int f50;            // 0x50
    tARGB_9AD0 col;     // 0x54
    float f64;          // 0x64
    float f68;          // 0x68
    int f6C;            // 0x6C
    float f70;          // 0x70
    int f74;            // 0x74
    float f78;          // 0x78
    int f7C;            // 0x7C
    int f80;            // 0x80
    int f84;            // 0x84
    int f88;            // 0x88
};

struct sSlot_9AD0 {
    int pad0[3];
    int id;
    int pad10[2];
};

struct tBarConfig {
    float scale;
    int count;
};

struct sGameOpts_9AD0 {
    unsigned int flags;         // 0x000: bits 22-24 = language
    char pad[0x284];
};
extern sGameOpts_9AD0 D_00535610;

// One screen dimension in pixels, set from the unsigned value the renderer reports.
// (The stores are aggregate-member stores: the target schedules the D_004A289C reload above them.)
struct sScreenDim_9AD0 {
    float pixels;
    void set(unsigned int v) { pixels = v; }
};
struct sHUD1P {
    char pad0[0xC];
    int hash;                   // 0x00C
    char* engine;               // 0x010
    char pad14[0x48 - 0x14];
    sRiderPanel panels[2];      // 0x048
    int f160, f164, f168;       // 0x160
    float w16C, w170, w174, w178; // 0x16C
    int f17C, f180, f184, f188; // 0x17C
    unsigned f18C;              // 0x18C
    float f190;                 // 0x190
    int f194, f198;             // 0x194
    char pad19C[0x3A4 - 0x19C];
    int f3A4, f3A8;             // 0x3A4
    char pad3AC[0x3B4 - 0x3AC];
    unsigned f3B4;              // 0x3B4
    char pad3B8[0x3C0 - 0x3B8];
    float f3C0;                 // 0x3C0
    int f3C4, f3C8, f3CC;       // 0x3C4
    float f3D0;                 // 0x3D0
    char pad3D4[0x3E0 - 0x3D4];
    sSlot_9AD0 slots[3];        // 0x3E0
    int bank428;                // 0x428
    void* font;                 // 0x42C
    char* fontName;             // 0x430
    void* w434, *w438, *w43C, *w440; // 0x434
    void* w444[11];             // 0x444
    void* w470;                 // 0x470
    int mode;                   // 0x474
    sScreenDim_9AD0 scrW, scrH; // 0x478
    char pad480[0x490 - 0x480];
    unsigned f490;              // 0x490
    void* icons[26];            // 0x494
    void* boost[5][3];          // 0x4FC
    void* w538;                 // 0x538
    tBarConfig bars[4];         // 0x53C
    int rnd;                    // 0x55C
    char box560[0x14C];         // 0x560
    char box6AC[0x14C];         // 0x6AC
    char box7F8[0x14C];         // 0x7F8
    char pad944[0xA44 - 0x944];
    int fA44;                   // 0xA44
    char padA48[0xB48 - 0xA48];
    char boxB48[0x14C];         // 0xB48
    float fC94;                 // 0xC94
};

class cGfx_9AD0 {
public:
    char pad[0xF50];
    int mode;           // 0xF50
};


static inline void* findElem_9AD0(char* engine, char* name)
{
    int hash = GetHashValue32(name);
    return func_00398380(engine + 0x58, hash);
}
static inline int findFont_9AD0(void* bank, char* name) { return func_003983F0(bank, GetHashValue32(name)); }

struct sRace_9AD0 {
    char pad0[0x40];
    char* riders[15];       // 0x40
    int numRiders;          // 0x7C
};
static inline sRace_9AD0* getRace_9AD0() { return *(sRace_9AD0**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC); }

// Segment count of a vertical bar: one 23-pixel segment per 23 pixels of height d above the base (rounded).
static inline void calcBarSegments_9AD0(int& n, float d)
{
    if (d > 23.0f) {
        n = (int)(d * (1.0f / 23.0f));
        if (((float)n + 0.5f) * 23.0f < d) {
            n++;
        }
    } else {
        n = 1;
    }
}

// A vertical bar of 23-pixel segments over a 54-pixel base: segment count and scale for an element height h.
static inline void setupVertBar_9AD0(tBarConfig* b, const float& h)
{
    calcBarSegments_9AD0(b->count, h - 54.0f);
    b->scale = h / ((float)b->count * 23.0f + 54.0f);
}

// Localised string by name from the game's text table (D_004A28A8 + 0x8C; vptr at 0x4, slot 4 = lookup by hash).
static inline unsigned short* getLocString_9AD0(char* id)
{
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<unsigned short*(void*, int)>* vt = *(sVEntry<unsigned short*(void*, int)>**)(o + 4);
    o += vt[4].delta;
    int h = GetHashValue32(id);
    return vt[4].fn(o, h);
}

extern "C" void cOVStateHUD1P_onCreateScreen(void* vself)
{
    sHUD1P* self = (sHUD1P*)vself;
    self->hash = GetHashValue32(D_004A20D0);
    sTok_9AD0* t = D_004C8980_9AD0;
    while (t->hash != 0) {
        sUIItem_9AD0* it = (sUIItem_9AD0*)func_00398380(self->engine + 0x58, t->name);
        t->tex = it->handle;
        t->uv0 = t2Vector(it->getX0(), it->getY0());
        t->uv1 = t2Vector(it->getX1(), it->getY1());
        t++;
    }
    self->f3C4 = 0x50;
    self->f3B4 = 0xF0000000;
    self->f3D0 = -1.0f;
    self->f3C0 = -1.0f;
    self->f3C8 = 0;
    self->f190 = -1.0f;
    self->f194 = 0;
    self->f198 = 0;
    self->f3A4 = 0;
    self->f3A8 = 0;
    self->fA44 = 0;
    self->fC94 = -1.0f;
    self->f3CC = 0;
    for (int i = 0; i < 2; i++) {
        self->panels[i].f44 = -1;
        self->panels[i].aiIndex = -1;
        self->panels[i].rider = -1;
        self->panels[i].f48 = 1.0f;
        self->panels[i].f4C = -1.0f;
        tARGB_9AD0 white;
        white.r = 1.0f;
        white.g = 1.0f;
        white.b = 1.0f;
        white.a = 1.0f;
        self->panels[i].col = white;
        self->panels[i].f64 = -1.0f;
        self->panels[i].f68 = 0.5f;
        self->panels[i].f6C = -1;
        self->panels[i].f70 = -1.0f;
        self->panels[i].f74 = 0;
        self->panels[i].f78 = -1.0f;
        self->panels[i].f80 = 0;
        self->panels[i].f84 = 0;
        self->panels[i].f88 = 0;
        self->panels[i].f7C = 0;
    }
    self->f160 = 0;
    self->f164 = 0;
    self->f168 = 0;
    for (int i = 0; i < 3; i++) {
        self->slots[i].id = -1;
    }
    signed char n = 0;
    for (int i = 0; i < getRace_9AD0()->numRiders; i++) {
        char* r = getRace_9AD0()->riders[i];
        if (*(int*)(*(char**)(r + 0x18) + 0x87C) != 0) {
            self->panels[n].rider = i;
            self->panels[n].aiIndex = ((cBeing_9AD0*)(*(char**)(r + 0x18) + 0x6C0))->getAIIndex();
            n++;
        }
    }
    tRect_9AD0 scr;
    scr.x = 0.0f;
    scr.y = 0.0f;
    scr.w = 640.0f;
    scr.h = 480.0f;
    if (n == 1) {
        t2Vector a;
        t2Vector size;
        t2Vector sc;
        getElemPos_9AD0(&D_00477000, &a);
        getElemSize_9AD0(&D_00477000, &size, 0);
        getElemScale_9AD0(&D_00477000, &sc);
        size.x *= sc.x;
        size.y *= sc.y;
        t2Vector p;
        p.x = 1.0f;
        p.y = 1.0f;
        sc = p;
        func_001F10F8(self, &p.x, &a.x, &size.x, &sc.x, D_00477000.alignX, D_00477000.alignY, 0);
        tRect_9AD0 r;
        r.x = p.x;
        r.y = p.y;
        r.w = size.x;
        r.h = size.y;
        func_0020EB50(self->panels[0].trophy, &scr, &r);
        func_0020EB50(self->panels[1].trophy, &scr, &r);
    } else {
        t2Vector a;
        t2Vector size;
        t2Vector sc;
        getElemPos_9AD0(&D_00477B40, &a);
        getElemSize_9AD0(&D_00477B40, &size, 0);
        getElemScale_9AD0(&D_00477B40, &sc);
        size.x *= sc.x;
        size.y *= sc.y;
        t2Vector p;
        p.x = 1.0f;
        p.y = 1.0f;
        sc = p;
        func_001F10F8(self, &p.x, &a.x, &size.x, &sc.x, D_00477B40.alignX, D_00477B40.alignY, 0);
        tRect_9AD0 r0;
        r0.x = p.x;
        r0.y = p.y;
        r0.w = size.x;
        r0.h = size.y;
        func_0020EB50(self->panels[0].trophy, &scr, &r0);
        func_001F10F8(self, &p.x, &a.x, &size.x, &sc.x, D_00477B40.alignX, D_00477B40.alignY, 1);
        tRect_9AD0 r1;
        r1.x = p.x;
        r1.y = p.y;
        r1.w = size.x;
        r1.h = size.y;
        func_0020EB50(self->panels[1].trophy, &scr, &r1);
    }
    cBE_getInterface_Fv(cBE_getBE(), 4);
    self->bank428 = findFont_9AD0(*(void**)(self->engine + 8), D_004A21F0);
    self->font = (void*)findFont_9AD0(*(void**)(self->engine + 8), D_004A21F8);
    self->w440 = findElem_9AD0(self->engine, D_004A2200);
    self->w43C = findElem_9AD0(self->engine, D_004A2208);
    self->w438 = findElem_9AD0(self->engine, D_004A2210);
    self->w434 = findElem_9AD0(self->engine, D_004A2218);
    self->w470 = findElem_9AD0(self->engine, D_004A2220);
    for (int i = 0; i < 26; i++) {
        self->icons[i] = func_00398380(self->engine + 0x58, D_004C88D8[i]);
    }
    cGfx_9AD0* gfx = (cGfx_9AD0*)D_004A289C;
    self->mode = gfx->mode;
    self->f490 = 0xDEEDDEED;
    {
        sVEntry<unsigned int(void*, int)>* vt = *(sVEntry<unsigned int(void*, int)>**)(D_004A289C + 0x10D8);
        self->scrW.set(vt[56].fn(D_004A289C + vt[56].delta, self->mode));
    }
    {
        sVEntry<unsigned int(void*, int)>* vt = *(sVEntry<unsigned int(void*, int)>**)(D_004A289C + 0x10D8);
        self->scrH.set(vt[57].fn(D_004A289C + vt[57].delta, self->mode));
    }
    self->w444[0] = findElem_9AD0(self->engine, D_004A2210);
    self->w444[1] = findElem_9AD0(self->engine, D_004A2208);
    self->w444[2] = findElem_9AD0(self->engine, D_004A2200);
    self->w444[3] = findElem_9AD0(self->engine, D_004A2228);
    self->w444[4] = findElem_9AD0(self->engine, D_004A2230);
    self->w444[5] = findElem_9AD0(self->engine, D_004A2238);
    self->w444[6] = findElem_9AD0(self->engine, D_004A2240);
    self->w444[7] = findElem_9AD0(self->engine, D_004A2248);
    self->w444[8] = findElem_9AD0(self->engine, D_004A2250);
    self->w444[9] = findElem_9AD0(self->engine, D_004A2258);
    self->w444[10] = findElem_9AD0(self->engine, D_004A2260);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            self->boost[i][j] = func_00398380(self->engine + 0x58, D_004C8940[i][j]);
        }
    }
    self->w538 = findElem_9AD0(self->engine, D_004A2268);
    {
    t2Vector a;
    getElemSize_9AD0(&D_00476940, &a, 0);
    setupVertBar_9AD0(&self->bars[0], a.y);
    getElemSize_9AD0(&D_00477480, &a, 0);
    setupVertBar_9AD0(&self->bars[1], a.y);
    getElemSize_9AD0(&D_00477048, &a, 0);
    self->bars[2].count = 1;
    self->bars[2].scale = 1.0f;
    a.x -= 23.0f;
    if (a.x - 18.0f < 0.0f) {
        self->bars[2].count = 0;
        self->bars[2].scale = a.x * (1.0f / 18.0f);
    }
    getElemSize_9AD0(&D_00477B88, &a, 0);
    self->bars[3].count = 1;
    self->bars[3].scale = 1.0f;
    a.x -= 23.0f;
    if (a.x - 18.0f < 0.0f) {
        self->bars[3].count = 0;
        self->bars[3].scale = a.x * (1.0f / 18.0f);
    }
    }
    {
    sGameOpts_9AD0 opts = D_00535610;
    switch ((opts.flags >> 22) & 7) {
    case 0:
    case 2:
        self->fontName = D_004A21E4;
        break;
    case 1:
    case 3:
        self->fontName = D_004A21EC;
        break;
    }
    }
    self->w16C = func_00391FB0(self->font, self->fontName, 0, 0, 1.0f, 1.0f);
    self->w170 = func_00391FB0(self->font, D_004A2270, 0, 0, 1.0f, 1.0f);
    self->w174 = func_00391FB0(self->font, D_004A2108, 0, 0, 1.0f, 1.0f);
    self->w178 = (self->w170 - func_00391FB0(self->font, D_004A2278, 0, 0, 1.0f, 1.0f)) * 0.25f;
    self->f17C = 0;
    self->f180 = 0;
    self->f184 = 0;
    self->f188 = 0;
    self->f18C = 0xFFFFFFFF;
    self->rnd = BXrand() & 1;
    func_001E94E0(self->box560, D_004A21D0[self->rnd], self->bank428, &D_004A4F50);
    func_001E94E0(self->box6AC, D_004A21D8, self->bank428, &D_004A4F50);
    func_001E94E0(self->box7F8, D_004A21D8, self->bank428, &D_004A4F50);
    unsigned short fmt[32];
    func_003DCA40(fmt, D_0046EAB8);
    unsigned short* name = getLocString_9AD0(D_0046EAC8);
    unsigned short* skip = getLocString_9AD0(D_0046EAD8);
    unsigned short buf[32];
    func_003DC9F8(buf, fmt, name, skip);
    func_001E9540(self->boxB48, buf, self->bank428, &D_004A4F58);
}
#endif

INCLUDE_ASM("fe/ovstatehud", func_001EA930);

//100%
INCLUDE_ASM("fe/ovstatehud", func_001EC1F0);
#ifdef SKIP_ASM
extern "C" void* func_002B40F0(void* self, int i);

// HUD overlay message handler: flags, counters, the two message strings and the track-name hash.
extern "C" int func_001EC1F0(char* self, int msg, unsigned short* str)
{
    switch (msg) {
    case 0:
        *(int*)(self + 0x3D4) = 1;
        break;
    case 1:
        *(int*)(self + 0x3D4) = 0;
        break;
    case 2:
        *(int*)(self + 0x3D8) = 0;
        break;
    case 3:
        *(int*)(self + 0x3D8) += 1;
        break;
    case 4:
        if (*(int*)(self + 0x3D8) > 0) {
            *(int*)(self + 0x3D8) -= 1;
        }
        break;
    case 12:
        *(unsigned int*)(self + 0x3CC) |= 0x20000;
        *(int*)(self + 0xA44) = 0;
        func_002C2508((unsigned short*)(self + 0x944), str);
        break;
    case 13:
        *(unsigned short*)(self + 0x944) = 0;
        *(int*)(self + 0xA44) = 0;
        *(unsigned int*)(self + 0x3CC) &= ~0x20000;
        break;
    case 14:
        *(unsigned int*)(self + 0x3CC) |= 0x40000;
        func_002C2508((unsigned short*)(self + 0xA48), str);
        break;
    case 15:
        *(unsigned short*)(self + 0xA48) = 0;
        *(unsigned int*)(self + 0x3CC) &= ~0x40000;
        break;
    case 5: {
        *(unsigned int*)(self + 0x3CC) &= ~0x10000;
        char* name = (char*)func_002B40F0((char*)func_0028B180() + 0x118, -1);
        unsigned int hash = 0xF0000000;
        if (name != 0 && *name != 0) {
            *(unsigned int*)(self + 0x3CC) |= 0x10000;
            hash = GetHashValue32(name);
        }
        if (!(*(unsigned int*)(self + 0x3CC) & 0x10000) || hash != *(unsigned int*)(self + 0x3B4)) {
            *(int*)(self + 0x3B4) = hash;
            *(float*)(self + 0x190) = -1.0f;
            *(int*)(self + 0x198) = 0;
            *(int*)(self + 0x3A4) = 0;
            *(int*)(self + 0x3A8) = 0;
            *(int*)(self + 0x194) = 0;
        }
        break;
    }
    case 6:
        *(int*)(self + 0x3C8) = 0;
        *(int*)(self + 0x3C0) = 0;
        *(int*)(self + 0x3C4) = 8;
        break;
    case 7:
        *(unsigned int*)(self + 0x3CC) &= 0xFFBDC3FF;
        *(int*)(self + 0x3C4) = 0x50;
        *(int*)(self + 0x3C0) = 0;
        *(int*)(self + 0xA44) = 0;
        *(unsigned short*)(self + 0x944) = 0;
        *(unsigned int*)(self + 0x18C) = 0xFFFFFFFF;
        break;
    case 8:
        *(int*)(self + 0x168) = 0;
        *(int*)(self + 0x160) = 1;
        break;
    case 9:
        *(int*)(self + 0x160) = 0;
        *(int*)(self + 0x168) = 0;
        *(int*)(self + 0x164) = 0;
        break;
    }
    return 0;
}
#endif

INCLUDE_ASM("fe/ovstatehud", cOVStateHUD1P_onRender2D);

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F10F8);
#ifdef SKIP_ASM
extern "C" float func_0021E750(void* self, int align, int flags, float pos, float size, float scale);
extern "C" float func_0021E7A8(void* self, int align, float pos, float size, float scale);

extern "C" void func_001F10F8(void* self, float* out, float* pos, float* size, float* scale, int alignX, int alignY, int flags)
{
    out[0] = func_0021E750(self, alignX, flags, pos[0], size[0], scale[0]);
    out[1] = func_0021E7A8(self, alignY, pos[1], size[1], scale[1]);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F1190);
#ifdef SKIP_ASM
struct sPos_001F1190 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sHudVert_001F1190 {
    float u, v, q, f0C;     // 0x00
    int r, g, b, a;         // 0x10
    sPos_001F1190 pos;      // 0x20
    sHudVert_001F1190() {}
};

static inline int texOf_001F1190(cOVStateHUDElem* e) { return e->field_0x0; }

extern "C" void func_001F1190(void* self, cOVStateHUDElem* e, float* pos, float* size, float* scale, float* color)
{
    if (e != 0) {
        *(short*)(*(char**)(D_004A289C + 0xE84) + 0x10) = texOf_001F1190(e);
        sHudVert_001F1190 v[4];
        int a = (int)(color[0] * 128.0f);
        int r = (int)(color[1] * 128.0f);
        int g = (int)(color[2] * 128.0f);
        int b = (int)(color[3] * 128.0f);
        for (int i = 0; i < 4; i++) {
            v[i].a = a;
            v[i].r = r;
            v[i].g = g;
            v[i].b = b;
            v[i].q = 1.0f;
        }
        float x0 = pos[0];
        float y0 = pos[1];
        float x1 = x0 + size[0] * scale[0];
        float y1 = y0 + size[1] * scale[1];
        v[0].u = e->x;
        v[0].v = e->rangeMax;
        v[1].u = e->y;
        v[1].v = e->rangeMax;
        v[2].u = e->x;
        v[2].v = e->z;
        v[3].u = e->y;
        v[3].v = e->z;
        sPos_001F1190 p;
        p.x = x0;
        p.y = y0;
        p.z = 0.0f;
        p.w = 1.0f;
        v[0].pos = p;
        p.x = x1;
        p.y = y0;
        p.z = 0.0f;
        p.w = 1.0f;
        v[1].pos = p;
        p.x = x0;
        p.y = y1;
        p.z = 0.0f;
        p.w = 1.0f;
        v[2].pos = p;
        p.x = x1;
        p.y = y1;
        p.z = 0.0f;
        p.w = 1.0f;
        v[3].pos = p;
        sVEntry<void(void*, int, sHudVert_001F1190*, int)>* vt = *(sVEntry<void(void*, int, sHudVert_001F1190*, int)>**)(D_004A289C + 0x10D8);
        vt[71].fn(D_004A289C + vt[71].delta, 4, v, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F1338);
#ifdef SKIP_ASM
struct sPos_001F1338 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sHudVert_001F1338 {
    float u, v, q, f0C;     // 0x00
    int r, g, b, a;         // 0x10
    sPos_001F1338 pos;      // 0x20
    sHudVert_001F1338() {}
};

extern "C" void func_001F1338(void* self, float* pos, float* size, float* scale, float* color)
{
    sHudVert_001F1338 v[4];
    int a = (int)(color[0] * 128.0f);
    int r = (int)(color[1] * 255.0f);
    int g = (int)(color[2] * 255.0f);
    int b = (int)(color[3] * 255.0f);
    for (int i = 0; i < 4; i++) {
        v[i].a = a;
        v[i].r = r;
        v[i].g = g;
        v[i].b = b;
        v[i].q = 1.0f;
    }
    float x0 = pos[0];
    float y0 = pos[1];
    float x1 = x0 + size[0] * scale[0];
    float y1 = y0 + size[1] * scale[1];
    sPos_001F1338 p;
    p.x = x0;
    p.y = y0;
    p.z = 0.0f;
    p.w = 1.0f;
    v[0].pos = p;
    p.x = x1;
    p.y = y0;
    p.z = 0.0f;
    p.w = 1.0f;
    v[1].pos = p;
    p.x = x0;
    p.y = y1;
    p.z = 0.0f;
    p.w = 1.0f;
    v[2].pos = p;
    p.x = x1;
    p.y = y1;
    p.z = 0.0f;
    p.w = 1.0f;
    v[3].pos = p;
    *(short*)(*(char**)(D_004A289C + 0xE84) + 0x10) = -1;
    sVEntry<void(void*, int, sHudVert_001F1338*, int)>* vt = *(sVEntry<void(void*, int, sHudVert_001F1338*, int)>**)(D_004A289C + 0x10D8);
    vt[71].fn(D_004A289C + vt[71].delta, 4, v, 0);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F14B0);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);
extern "C" void func_00391CB0(void* self, float x, float y, const char* str);

struct sGlyph_1F14B0 {
    unsigned short code;
    unsigned char lead;
    char pad_0x3[6];
    signed char width;
    char pad_0xA[2];
};

struct sGlyphTable_1F14B0 {
    int count;
    sGlyph_1F14B0* glyphs;
    sGlyph_1F14B0* fallback;
    int first;
    int last;
    char pad14[0x1C];
    float f30;
    float f34;
    float f38;
    float f3C;
};

static inline sGlyph_1F14B0* findGlyph_1F14B0(sGlyphTable_1F14B0* t, int c)
{
    if (c < t->first)
        return 0;
    if (c <= t->last)
        return t->glyphs + c - t->first;
    int lo = t->last - t->first;
    int hi = t->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph_1F14B0* g = &t->glyphs[mid];
        if (c == g->code)
            return g;
        if (c < g->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return t->fallback;
}

struct sVec2_1F14B0 {
    float x, y;
};

extern "C" void func_001F14B0(void* self, const char* str, sGlyphTable_1F14B0* font, float amp, float x, float y)
{
    sVec2_1F14B0 sc;
    sc.x = font->f38 / font->f30;
    sc.y = font->f3C / font->f34;
    int len = strlen(str);
    char buf[2];
    buf[1] = 0;
    for (int i = 0; i < len; i++) {
        buf[0] = str[i];
        int d = i - (len >> 1);
        int neg = 0;
        if (d == 0) {
            d = 1;
        } else if (d < 0) {
            neg = 1;
            d = -d;
        }
        unsigned char ch = buf[0];
        int d2 = d * 2;
        int half = (ch & 0x7F) >> 1;
        int a = (d2 * half * 5) & 0x7F;
        int b = (d * (ch & 0xF) * 4) & 0x7F;
        float oy = (float)a;
        float ox = (float)b;
        oy = -oy;
        if (neg) {
            ox = -ox;
        }
        func_00391CB0(font, x + amp * ox, y + amp * oy, buf);
        sGlyph_1F14B0* g = findGlyph_1F14B0(font, buf[0]);
        x += (float)(g->width + g->lead) * sc.x;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F16C0);
#ifdef SKIP_ASM
struct sColor_001F16C0 {
    float r, g, b, a;
};
struct sHudElemDef_001F16C0 {
    char pad[0x20];
    signed char align;      // 0x20
    signed char flags;      // 0x21
    char pad22[2];
};
extern "C" void cOVStateHUD1P_renderTime(void* self, int a1, int a2, int a3, int a4, int a5, float* pos, float* scale, sColor_001F16C0* color, int align, int flags, int a11);

extern "C" void func_001F16C0(void* self, int a1, int a2, int a3, int a4, int a5, sHudElemDef_001F16C0* defs, int idx, int a8, float* scaleMul, float* posOff, sColor_001F16C0* color)
{
    float pos[4];
    float scale[4];
    sColor_001F16C0 col;
    sHudElemDef_001F16C0* e = &defs[idx];
    func_001E91F8(e, pos);
    func_001E9290(e, scale);
    if (scaleMul != 0) {
        scale[0] *= scaleMul[0];
        scale[1] *= scaleMul[1];
    }
    if (posOff != 0) {
        pos[0] += posOff[0];
        pos[1] += posOff[1];
    }
    if (color == 0) {
        func_001E91A8(e, &col);
    } else {
        col = *color;
    }
    cOVStateHUD1P_renderTime(self, a1, a2, a3, a4, a5, pos, scale, &col, defs[idx].align, defs[idx].flags, a8);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", cOVStateHUD1P_renderTime);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_001DC990(void* font, float x, float y, const char* fmt, ...);
extern char D_004A2100[];
extern char D_004A2108[];
extern char D_004A22F0[];
extern char D_004A22F8[];

struct sFont_001F1840 {
    char pad0[0x14];
    int count;          // 0x14
    char pad18[0x18];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sColor_001F16C0 color; // 0x40
};

struct sHUD_001F1840 {
    char pad0[0x16C];
    float digitW;       // 0x16C
    float f170;         // 0x170
    float f174;         // 0x174
    float oneW;         // 0x178
    char pad17C[0x42C - 0x17C];
    sFont_001F1840* font; // 0x42C
    const char* sep;    // 0x430
};

static inline float oneAdj_001F1840(const char* s, float w)
{
    float adj = 0.0f;
    if (s[0] == '1') adj = w;
    if (s[1] == '1') adj += w;
    return adj;
}

extern "C" void cOVStateHUD1P_renderTime(void* self_, int a1, int a2, int a3, int a4, int a5, float* pos, float* scale, sColor_001F16C0* color, int align, int flags, int a11)
{
    sHUD_001F1840* self = (sHUD_001F1840*)self_;
    float size[2];
    float out[2];
    char bufs[3][4];
    float n = 3.0f;
    if (a5 & 1) n = 4.0f;
    size[1] = (float)self->font->count * self->font->f34;
    size[0] = self->f170 * n + (self->digitW + 2.0f + 2.0f) * (n - 1.0f);
    func_001F10F8(self, out, pos, size, scale, align, flags, a11);
    sFont_001F1840* font = self->font;
    font->f38 = font->f30 * scale[0];
    font->f3C = font->f34 * scale[1];
    self->font->color = *color;
    float sepW = (self->f170 + 2.0f) * scale[0];
    float digW = (self->digitW + 2.0f) * scale[0];
    float oneW = self->oneW * scale[0];
    if (a5 & 6) {
        if (a5 & 2)
            func_00391CB0(self->font, out[0], out[1], D_004A2108);
        else
            func_00391CB0(self->font, out[0], out[1], D_004A2100);
        out[0] += self->f174;
    }
    sprintf(bufs[0], D_004A22F0, a1);
    sprintf(bufs[1], D_004A22F0, a2);
    sprintf(bufs[2], D_004A22F0, a3);
    func_00391CB0(self->font, out[0] + oneAdj_001F1840(bufs[0], oneW), out[1], bufs[0]);
    out[0] += sepW;
    for (int i = 1; i < 3; i++) {
        func_00391CB0(self->font, out[0], out[1], self->sep);
        out[0] += digW;
        char* p = bufs[i];
        func_00391CB0(self->font, out[0] + oneAdj_001F1840(p, oneW), out[1], p);
        out[0] += sepW;
    }
    if (a5 & 1)
        func_001DC990(self->font, out[0], out[1], D_004A22F8, a4);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F1B30);
#ifdef SKIP_ASM
struct sVec4_001F1B30 {
    float x, y, z, w;
    sVec4_001F1B30(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};

struct sFont_001F1B30 {
    char pad0[0x30];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sColor_001F16C0 color; // 0x40
    sVec4_001F1B30 tint;   // 0x50
};

struct sRS_001F1B30 {
    int f0;
    int f4;
    int f8;
};

extern "C" void func_001F1B30(void* ctx, sFont_001F1B30* font, sHudElemDef_001F16C0* defs, int idx, const char* str, int a5, float* scaleMul, float* posOff, sColor_001F16C0* color, float* rect, int align, int flags)
{
    float scale[2];
    float pos[4];
    float escale[2];
    float r[4];
    float out[2];
    float size[2];
    sColor_001F16C0 col;
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    sHudElemDef_001F16C0* e = &defs[idx];
    func_001E91F8(e, pos);
    func_001E9290(e, escale);
    if (scaleMul != 0) {
        escale[0] *= scaleMul[0];
        escale[1] *= scaleMul[1];
    }
    font->f38 = font->f30 * escale[0];
    font->f3C = font->f34 * escale[1];
    func_00391FB0(font, str, r, 0, font->f38, font->f3C);
    int ax = (align == 0x7F) ? e->align : align;
    int ay = (flags == 0x7F) ? defs[idx].flags : flags;
    size[0] = r[2];
    size[1] = r[3];
    func_001F10F8(ctx, out, pos, size, scale, ax, ay, a5);
    if (posOff != 0) {
        out[0] += posOff[0];
        out[1] += posOff[1];
    }
    if (rect != 0) {
        rect[0] = out[0];
        rect[1] = out[1];
        rect[2] = r[2];
        rect[3] = r[3];
    }
    if (color == 0) {
        func_001E91A8(&defs[idx], &col);
    } else {
        col = *color;
    }
    sVec4_001F1B30 t(col.r, 0.0f, 0.0f, 0.0f);
    sRS_001F1B30* rs = *(sRS_001F1B30**)(D_004A289C + 0xE84);
    rs->f8 = (rs->f8 & ~0x3E0) | ((defs[idx].pad22[0] << 5) & 0x3E0);
    font->color = col;
    font->tint = t;
    func_00391CB0(font, out[0], out[1], str);
    font->tint = sVec4_001F1B30(1.0f, 0.0f, 0.0f, 0.0f);
    font->f38 = font->f30 * scale[0];
    font->f3C = font->f34 * scale[1];
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F1E28);
#ifdef SKIP_ASM
// NOTE w1 2026-10-21: func_001F1E28 best 99.94 (not committed). Only residual: 4 insns at the start of the
// last block before the jal func_00391CB0: $f0..$f3 numbering of the font->f38/f3C = f30/f34 * resEsc[] loads
// is swapped (local alloc; sx regs reports nothing). Tried operand order / statement order / locals (99.78-99.94).
// Sibling func_001F25E0 is identical except: func_003921F0 instead of func_00391FB0 (str is const unsigned short*),
// func_00391E30 instead of func_00391CB0. Needs sColor_001F16C0, sHudElemDef_001F16C0 from func_001F16C0's block.
// Lessons: dead stores of dOutT/dOut land in the frame because arrays are written; col shares the slot of dOutT when
// dOutT/dOut live in an inner block; nested by-value VU0 helper calls in ONE expression share one temp slot;
// a 4-float ctor temp + struct copy gives the 'swc1 x4; ldl/ldr/sdl/sdr' colour build.

struct sV4_001F1E28 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCol_001F1E28 {
    float r, g, b, a;
    sCol_001F1E28() {}
    sCol_001F1E28(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};

struct sFont_001F1E28 {
    char pad0[0x30];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sCol_001F1E28 color; // 0x40
};

struct sRS_001F1E28 {
    int f0;
    int f4;
    int f8;
};

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_001F1E28 vu0Sub_1E28(const sV4_001F1E28& a, const sV4_001F1E28& b)
{
    sV4_001F1E28 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_001F1E28 vu0Add_1E28(const sV4_001F1E28& a, const sV4_001F1E28& b)
{
    sV4_001F1E28 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_001F1E28 vu0Scale_1E28(const sV4_001F1E28& v, float s)
{
    sV4_001F1E28 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// Draws text blended between two HUD element layouts (t = 0 is element idx1, t = 1 is element idx2).
extern "C" void func_001F1E28(void* ctx, float t, sFont_001F1E28* font, sHudElemDef_001F16C0* defs, int idx1, int idx2, const char* str, int a5, float* scaleMul, float* posOff, sColor_001F16C0* color, float* rect, int align, int flags)
{
    float scale[2];
    float r[4];
    float pos1[4];
    float esc1[2];
    float pos2[4];
    float esc2[2];
    float out1[2];
    float out2[2];
    float size1[2];
    float size2[2];
    float resEsc[2];
    float resPos[2];
    float dEsc[2];
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    font->f38 = font->f30;
    font->f3C = font->f34;
    func_00391FB0(font, str, r, 0, font->f38, font->f3C);
    sHudElemDef_001F16C0* e1 = &defs[idx1];
    func_001E91F8(e1, pos1);
    func_001E9290(e1, esc1);
    if (scaleMul != 0) {
        esc1[0] *= scaleMul[0];
        esc1[1] *= scaleMul[1];
    }
    sHudElemDef_001F16C0* e2 = &defs[idx2];
    func_001E91F8(e2, pos2);
    func_001E9290(e2, esc2);
    if (scaleMul != 0) {
        esc2[0] *= scaleMul[0];
        esc2[1] *= scaleMul[1];
    }
    size1[0] = r[2] * esc1[0];
    size1[1] = r[3] * esc1[1];
    size2[0] = r[2] * esc2[0];
    size2[1] = r[3] * esc2[1];
    int ax1 = (align == 0x7F) ? e1->align : (signed char)align;
    int ay1 = (flags == 0x7F) ? defs[idx1].flags : (signed char)flags;
    int ax2 = (align == 0x7F) ? defs[idx2].align : (signed char)align;
    int ay2 = (flags == 0x7F) ? defs[idx2].flags : (signed char)flags;
    func_001F10F8(ctx, out1, pos1, size1, scale, ax1, ay1, a5);
    func_001F10F8(ctx, out2, pos2, size2, scale, ax2, ay2, a5);
    dEsc[0] = esc2[0] - esc1[0];
    dEsc[1] = esc2[1] - esc1[1];
    {
        float dOutT[2];
        float dOut[2];
        dOut[0] = out2[0] - out1[0];
        dOut[1] = out2[1] - out1[1];
        dOutT[0] = dOut[0] * t;
        dOutT[1] = dOut[1] * t;
        resPos[0] = dOutT[0] + out1[0];
        resPos[1] = dOutT[1] + out1[1];
        resEsc[0] = dEsc[0] * t + esc1[0];
        resEsc[1] = dEsc[1] * t + esc1[1];
    }
    if (posOff != 0) {
        resPos[0] = resPos[0] + posOff[0];
        resPos[1] = resPos[1] + posOff[1];
    }
    if (rect != 0) {
        rect[0] = resPos[0];
        rect[1] = resPos[1];
        rect[2] = r[2] * resEsc[0];
        rect[3] = r[3] * resEsc[1];
    }
    sCol_001F1E28 col;
    if (color == 0) {
        sV4_001F1E28 c1;
        sV4_001F1E28 c2;
        func_001E91D0(&defs[idx1], &c1);
        func_001E91D0(&defs[idx2], &c2);
        c2.w = 0.0f;
        sV4_001F1E28 v = vu0Add_1E28(vu0Scale_1E28(vu0Sub_1E28(c2, c1), t), c1);
        col = sCol_001F1E28(v.w, v.x, v.y, v.z);
    } else {
        col = *(sCol_001F1E28*)color;
        col.r = col.r * (1.0f - t);
    }
    sRS_001F1E28* rs = *(sRS_001F1E28**)(D_004A289C + 0xE84);
    rs->f8 = (rs->f8 & ~0x3E0) | ((defs[26].pad22[0] << 5) & 0x3E0);
    font->color = col;
    float g0 = font->f30;
    float q0 = resEsc[0];
    float q1 = resEsc[1];
    float g1 = font->f34;
    font->f3C = g1 * q1;
    font->f38 = g0 * q0;
    func_00391CB0(font, resPos[0], resPos[1], str);
    font->f38 = font->f30 * scale[0];
    font->f3C = font->f34 * scale[1];
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F22E8);
#ifdef SKIP_ASM
struct sVec4_001F22E8 {
    float x, y, z, w;
    sVec4_001F22E8(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};

struct sFont_001F22E8 {
    char pad0[0x30];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sColor_001F16C0 color; // 0x40
    sVec4_001F22E8 tint;   // 0x50
};

struct sRS_001F22E8 {
    int f0;
    int f4;
    int f8;
};

extern "C" void func_001F22E8(void* ctx, sFont_001F22E8* font, sHudElemDef_001F16C0* defs, int idx, const unsigned short* str, int a5, float* scaleMul, float* posOff, sColor_001F16C0* color, float* rect, int align, int flags)
{
    float scale[2];
    float pos[4];
    float escale[2];
    float r[4];
    float out[2];
    float size[2];
    sColor_001F16C0 col;
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    sHudElemDef_001F16C0* e = &defs[idx];
    func_001E91F8(e, pos);
    func_001E9290(e, escale);
    if (scaleMul != 0) {
        escale[0] *= scaleMul[0];
        escale[1] *= scaleMul[1];
    }
    font->f38 = font->f30 * escale[0];
    font->f3C = font->f34 * escale[1];
    func_003921F0(font, str, r, 0, font->f38, font->f3C);
    int ax = (align == 0x7F) ? e->align : align;
    int ay = (flags == 0x7F) ? defs[idx].flags : flags;
    size[0] = r[2];
    size[1] = r[3];
    func_001F10F8(ctx, out, pos, size, scale, ax, ay, a5);
    if (posOff != 0) {
        out[0] += posOff[0];
        out[1] += posOff[1];
    }
    if (rect != 0) {
        rect[0] = out[0];
        rect[1] = out[1];
        rect[2] = r[2];
        rect[3] = r[3];
    }
    if (color == 0) {
        func_001E91A8(&defs[idx], &col);
    } else {
        col = *color;
    }
    sVec4_001F22E8 t(col.r, 0.0f, 0.0f, 0.0f);
    sRS_001F22E8* rs = *(sRS_001F22E8**)(D_004A289C + 0xE84);
    rs->f8 = (rs->f8 & ~0x3E0) | ((defs[idx].pad22[0] << 5) & 0x3E0);
    font->color = col;
    font->tint = t;
    func_00391E30(font, out[0], out[1], str);
    font->tint = sVec4_001F22E8(1.0f, 0.0f, 0.0f, 0.0f);
    font->f38 = font->f30 * scale[0];
    font->f3C = font->f34 * scale[1];
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F25E0);
#ifdef SKIP_ASM
struct sV4_001F25E0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCol_001F25E0 {
    float r, g, b, a;
    sCol_001F25E0() {}
    sCol_001F25E0(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};

struct sFont_001F25E0 {
    char pad0[0x30];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sCol_001F25E0 color; // 0x40
};

struct sRS_001F25E0 {
    int f0;
    int f4;
    int f8;
};

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_001F25E0 vu0Sub_25E0(const sV4_001F25E0& a, const sV4_001F25E0& b)
{
    sV4_001F25E0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_001F25E0 vu0Add_25E0(const sV4_001F25E0& a, const sV4_001F25E0& b)
{
    sV4_001F25E0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_001F25E0 vu0Scale_25E0(const sV4_001F25E0& v, float s)
{
    sV4_001F25E0 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// Draws text blended between two HUD element layouts (t = 0 is element idx1, t = 1 is element idx2).
extern "C" void func_001F25E0(void* ctx, float t, sFont_001F25E0* font, sHudElemDef_001F16C0* defs, int idx1, int idx2, const unsigned short* str, int a5, float* scaleMul, float* posOff, sColor_001F16C0* color, float* rect, int align, int flags)
{
    float scale[2];
    float r[4];
    float pos1[4];
    float esc1[2];
    float pos2[4];
    float esc2[2];
    float out1[2];
    float out2[2];
    float size1[2];
    float size2[2];
    float resEsc[2];
    float resPos[2];
    float dEsc[2];
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    font->f38 = font->f30;
    font->f3C = font->f34;
    func_003921F0(font, str, r, 0, font->f38, font->f3C);
    sHudElemDef_001F16C0* e1 = &defs[idx1];
    func_001E91F8(e1, pos1);
    func_001E9290(e1, esc1);
    if (scaleMul != 0) {
        esc1[0] *= scaleMul[0];
        esc1[1] *= scaleMul[1];
    }
    sHudElemDef_001F16C0* e2 = &defs[idx2];
    func_001E91F8(e2, pos2);
    func_001E9290(e2, esc2);
    if (scaleMul != 0) {
        esc2[0] *= scaleMul[0];
        esc2[1] *= scaleMul[1];
    }
    size1[0] = r[2] * esc1[0];
    size1[1] = r[3] * esc1[1];
    size2[0] = r[2] * esc2[0];
    size2[1] = r[3] * esc2[1];
    int ax1 = (align == 0x7F) ? e1->align : (signed char)align;
    int ay1 = (flags == 0x7F) ? defs[idx1].flags : (signed char)flags;
    int ax2 = (align == 0x7F) ? defs[idx2].align : (signed char)align;
    int ay2 = (flags == 0x7F) ? defs[idx2].flags : (signed char)flags;
    func_001F10F8(ctx, out1, pos1, size1, scale, ax1, ay1, a5);
    func_001F10F8(ctx, out2, pos2, size2, scale, ax2, ay2, a5);
    dEsc[0] = esc2[0] - esc1[0];
    dEsc[1] = esc2[1] - esc1[1];
    {
        float dOutT[2];
        float dOut[2];
        dOut[0] = out2[0] - out1[0];
        dOut[1] = out2[1] - out1[1];
        dOutT[0] = dOut[0] * t;
        dOutT[1] = dOut[1] * t;
        resPos[0] = dOutT[0] + out1[0];
        resPos[1] = dOutT[1] + out1[1];
        resEsc[0] = dEsc[0] * t + esc1[0];
        resEsc[1] = dEsc[1] * t + esc1[1];
    }
    if (posOff != 0) {
        resPos[0] = resPos[0] + posOff[0];
        resPos[1] = resPos[1] + posOff[1];
    }
    if (rect != 0) {
        rect[0] = resPos[0];
        rect[1] = resPos[1];
        rect[2] = r[2] * resEsc[0];
        rect[3] = r[3] * resEsc[1];
    }
    sCol_001F25E0 col;
    if (color == 0) {
        sV4_001F25E0 c1;
        sV4_001F25E0 c2;
        func_001E91D0(&defs[idx1], &c1);
        func_001E91D0(&defs[idx2], &c2);
        c2.w = 0.0f;
        sV4_001F25E0 v = vu0Add_25E0(vu0Scale_25E0(vu0Sub_25E0(c2, c1), t), c1);
        col = sCol_001F25E0(v.w, v.x, v.y, v.z);
    } else {
        col = *(sCol_001F25E0*)color;
        col.r = col.r * (1.0f - t);
    }
    sRS_001F25E0* rs = *(sRS_001F25E0**)(D_004A289C + 0xE84);
    rs->f8 = (rs->f8 & ~0x3E0) | ((defs[26].pad22[0] << 5) & 0x3E0);
    font->color = col;
    float g0 = font->f30;
    float q0 = resEsc[0];
    float q1 = resEsc[1];
    float g1 = font->f34;
    font->f3C = g1 * q1;
    font->f38 = g0 * q0;
    func_00391E30(font, resPos[0], resPos[1], str);
    font->f38 = font->f30 * scale[0];
    font->f3C = font->f34 * scale[1];
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F2AA0);
#ifdef SKIP_ASM
extern "C" char* func_00392430(void* f, const char* str, char* dst, int max, float sx, float width);

struct sFont_001F2AA0 {
    char pad0[0x14];
    int count;          // 0x14
    char pad18[0x18];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sColor_001F16C0 color; // 0x40
};

struct sRS_001F2AA0 {
    int f0;
    int f4;
    int f8;
};

static inline float alignPos_001F2AA0(float v, int a, float size)
{
    if (a == 0)
        v -= size * 0.5f;
    else if (a > 0)
        v -= size;
    return v;
}

extern "C" void func_001F2AA0(void* self, sFont_001F2AA0* font, sHudElemDef_001F16C0* defs, int idx, const char* str, int flags, float* rect)
{
    float wrap[2];
    float pos[2];
    float escale[2];
    char lines[5][50];
    sColor_001F16C0 col;
    float scale[2];
    int n = 0;
    sHudElemDef_001F16C0* e = &defs[idx];
    func_001E9220(e, wrap, 0);
    func_001E91F8(e, pos);
    func_001E9290(e, escale);
    sFont_001F2AA0* sf = *(sFont_001F2AA0**)((char*)self + 0x428);
    sf->f38 = sf->f30 * escale[0];
    sf->f3C = sf->f34 * escale[1];
    const char* p = str;
    while (p != 0) {
        p = func_00392430(*(sFont_001F2AA0**)((char*)self + 0x428), p, lines[n], 0x32, (*(sFont_001F2AA0**)((char*)self + 0x428))->f38, wrap[0]);
        n++;
    }
    func_001E91A8(&defs[idx], &col);
    font->color = col;
    float fn = (float)n;
    sRS_001F2AA0* rs = *(sRS_001F2AA0**)(D_004A289C + 0xE84);
    rs->f8 = (rs->f8 & ~0x3E0) | ((defs[idx].pad22[0] << 5) & 0x3E0);
    float lineH = (float)font->count * font->f34 * escale[1];
    float totalH = lineH * fn;
    float y = alignPos_001F2AA0(pos[1], defs[idx].flags, totalH);
    if (rect != 0) {
        rect[0] = 65536.0f;
        rect[1] = y;
        rect[2] = 0.0f;
        rect[3] = totalH;
    }
    int i = 0;
    if (n > 0) do {
        char* line = lines[i];
        float w = func_00391FB0(font, line, 0, 0, font->f38, font->f3C);
        float x = pos[0];
        int al = defs[idx].align;
        if (flags & 1) {
            x = 640.0f - x;
            if (!(flags & 2)) al = -al;
        }
        if (al == 0)
            x -= w * 0.5f;
        else if (al > 0)
            x -= w;
        func_00391CB0(font, x, y, line);
        if (rect != 0) {
            if (x < rect[0]) rect[0] = x;
            if (rect[2] < w) rect[2] = w;
        }
        y += lineH;
    } while (++i < n);
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    font->f38 = font->f30 * scale[0];
    font->f3C = font->f34 * scale[1];
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F2DB0);
#ifdef SKIP_ASM
extern "C" unsigned short* func_00392680(void* f, const unsigned short* str, unsigned short* dst, int max, float sx, float width);

struct sFont_001F2DB0 {
    char pad0[0x14];
    int count;          // 0x14
    char pad18[0x18];
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sColor_001F16C0 color; // 0x40
};

struct sRS_001F2DB0 {
    int f0;
    int f4;
    int f8;
};

static inline float alignPos_001F2DB0(float v, int a, float size)
{
    if (a == 0)
        v -= size * 0.5f;
    else if (a > 0)
        v -= size;
    return v;
}

extern "C" void func_001F2DB0(void* self, sFont_001F2DB0* font, sHudElemDef_001F16C0* defs, int idx, const unsigned short* str, int flags, float* rect)
{
    float wrap[2];
    float pos[2];
    float escale[2];
    unsigned short lines[5][50];
    sColor_001F16C0 col;
    float scale[2];
    int n = 0;
    func_001E9220(&defs[29], wrap, 0);
    sHudElemDef_001F16C0* e = &defs[idx];
    func_001E91F8(e, pos);
    func_001E9290(e, escale);
    sFont_001F2DB0* sf = *(sFont_001F2DB0**)((char*)self + 0x428);
    sf->f38 = sf->f30 * escale[0];
    sf->f3C = sf->f34 * escale[1];
    const unsigned short* p = str;
    while (p != 0) {
        p = func_00392680(*(sFont_001F2DB0**)((char*)self + 0x428), p, lines[n], 0x32, (*(sFont_001F2DB0**)((char*)self + 0x428))->f38, wrap[0]);
        n++;
    }
    func_001E91A8(&defs[idx], &col);
    font->color = col;
    float fn = (float)n;
    sRS_001F2DB0* rs = *(sRS_001F2DB0**)(D_004A289C + 0xE84);
    rs->f8 = (rs->f8 & ~0x3E0) | ((defs[idx].pad22[0] << 5) & 0x3E0);
    float lineH = (float)font->count * font->f34 * escale[1];
    float totalH = lineH * fn;
    float y = alignPos_001F2DB0(pos[1], defs[idx].flags, totalH);
    if (rect != 0) {
        rect[0] = 65536.0f;
        rect[1] = y;
        rect[2] = 0.0f;
        rect[3] = totalH;
    }
    int i = 0;
    if (n > 0) do {
        unsigned short* line = lines[i];
        float w = func_003921F0(font, line, 0, 0, font->f38, font->f3C);
        float x = pos[0];
        int al = defs[idx].align;
        if (flags & 1) {
            x = 640.0f - x;
            if (!(flags & 2)) al = -al;
        }
        if (al == 0)
            x -= w * 0.5f;
        else if (al > 0)
            x -= w;
        func_00391E30(font, x, y, line);
        if (rect != 0) {
            if (x < rect[0]) rect[0] = x;
            if (rect[2] < w) rect[2] = w;
        }
        y += lineH;
    } while (++i < n);
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    font->f38 = font->f30 * scale[0];
    font->f3C = font->f34 * scale[1];
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F30C0__FPv);
#ifdef SKIP_ASM
void* func_001F30C0(void* self)
{
    cOVStateHUDElem* e = (cOVStateHUDElem*)self;
    e->field_0x0 = 0;
    *(int*)&e->rangeMax = 0;
    e->field_0x4 = 0;
    *(int*)&e->rangeMin = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F30D8);
#ifdef SKIP_ASM
struct sHudIds001F30D8 {
    int a;
    int b;
    int c;
    int d;
};

extern "C" int func_003983F0(void* self, int key);
extern void* D_004A28A8;
extern char D_0046ED78[];
extern char D_004A21F0[];

extern "C" void func_001F30D8(void* p)
{
    sHudIds001F30D8* self = (sHudIds001F30D8*)p;
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<int(void*, int)>* vt = *(sVEntry<int(void*, int)>**)(o + 4);
    char* adj = o + vt[4].delta;
    int h = GetHashValue32(D_0046ED78);
    self->a = vt[4].fn(adj, h);
    void* tbl = *(void**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x48) + 8);
    self->d = func_003983F0(tbl, GetHashValue32(D_004A21F0));
    self->b = 0;
    self->c = 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F3170__FPv);
#ifdef SKIP_ASM
void func_001F3170(void* self)
{
    cOVStateHUDElem* e = (cOVStateHUDElem*)self;
    e->field_0x0 = 0;
    *(int*)&e->rangeMax = 0;
    e->field_0x4 = 0;
    *(int*)&e->rangeMin = 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F3188);
#ifdef SKIP_ASM
static inline void wrap_1F3188(float* t, float range)
{
    while (*t > range) {
        *t -= range;
    }
}

extern "C" void func_001F3188(void* self)
{
    if (*(int*)((char*)self + 4) != 0) {
        float* t = (float*)((char*)self + 8);
        *t += 0.01666666753590107f;
        wrap_1F3188(t, 2.0f);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F31E0);
#ifdef SKIP_ASM
struct sVec4_31E0 {
    float x, y, z, w;
    sVec4_31E0() {}
    sVec4_31E0(const float& ax, const float& ay, const float& az, const float& aw) : x(ax), y(ay), z(az), w(aw) {}
};
struct sV2_31E0 {
    float x, y;
    sV2_31E0() {}
    sV2_31E0(const float& ax, const float& ay) : x(ax), y(ay) {}
};
struct sCol_31E0 {
    float r, g, b, a;
    sCol_31E0(const float& ar, const float& ag, const float& ab, const float& aa) : r(ar), g(ag), b(ab), a(aa) {}
};

struct sGs_31E0 {
    unsigned int w0;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 5;
    unsigned int f4_12 : 8;
    unsigned int f4_20 : 2;
    unsigned int f4_22 : 1;
    unsigned int f4_23 : 2;
    unsigned int f4_25 : 7;
    unsigned int f8_0 : 5;
    unsigned int f8_5 : 5;
    unsigned int f8_10 : 19;
    unsigned int f8_29 : 3;
    unsigned int wC;
    unsigned int f10 : 16;
    unsigned int f10hi : 16;
};

extern sGs_31E0 D_00501420_31E0 __asm__("D_00501420");
extern char D_004FF1A0[];
extern int D_004A4EB0;
extern sV2_31E0 D_004A4EA8;
extern "C" float func_003921F0(void* obj, const unsigned short* txt, void* a, int b, float x, float y);

class cGfx_31E0 {
public:
    char pad[0xE84];
    sGs_31E0* stateTop;
    char padE88[0x1068 - 0xE88];
    int f1068;
    int GetF1068() { return f1068; }
    char pad106C[0x10D8 - 0x106C];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19();
    virtual void BeginScene();
    virtual void EndScene();
    virtual void v22(float, float, float, float, int);
    virtual void v23(); virtual void v24();
    virtual void SetViewport(float, float, float, float, int, int, float, float);
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
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
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76();
    virtual void DrawSprite(const sVec4_31E0&, const sV2_31E0&, const sV2_31E0&, const sV2_31E0&, const sCol_31E0&);
};

extern cGfx_31E0* D_004A289C_31E0 __asm__("D_004A289C");

struct sFont_001F31E0 {
    char pad0[0x14];
    int count;          // 0x14
    char pad18[0x10];
    sV2_31E0 scale;     // 0x28
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    sVec4_31E0 color;   // 0x40
    sVec4_31E0 color2;  // 0x50
    void SetScale(float sx, float sy) { f38 = f30 * sx; f3C = f34 * sy; }
};

struct sHudTimer_001F31E0 {
    const unsigned short* text; // 0x0
    int active;                 // 0x4
    float t;                    // 0x8
    sFont_001F31E0* font;       // 0xC
};

extern "C" void func_001F31E0(sHudTimer_001F31E0* self)
{
    if (self->active == 0) {
        return;
    }
    if (D_004A4EB0 == 0) {
        D_004A4EB0 = 1;
        D_004A4EA8.y = D_004A4EA8.x = 3.0f;
    }
    float f = self->t - 1.0f;
    if (f < 0.0f) {
        f = -f;
    }
    cGfx_31E0* g = D_004A289C_31E0;
    g->stateTop[1] = g->stateTop[0];
    g->stateTop++;
    D_004A289C_31E0->BeginScene();
    D_004A289C_31E0->Begin2D();
    *D_004A289C_31E0->stateTop = D_00501420_31E0;
    D_004A289C_31E0->stateTop->f4_23 = 2;
    D_004A289C_31E0->stateTop->f4_20 = 0;
    D_004A289C_31E0->stateTop->f4_12 = 0x14;
    D_004A289C_31E0->stateTop->f4_2 = 5;
    D_004A289C_31E0->SetTexture(D_004FF1A0);
    {
        sVEntry<void(void*, float, float, float, float, int)>* vt = *(sVEntry<void(void*, float, float, float, float, int)>**)((char*)D_004A289C_31E0 + 0x10D8);
        char* thisp = (char*)D_004A289C_31E0 + vt[23].delta;
        void (**pfn)(void*, float, float, float, float, int) = &vt[23].fn;
        (*pfn)(thisp, 0.0f, 0.0f, (float)D_004A289C_31E0->GetWidth(), (float)D_004A289C_31E0->GetHeight(), 1);
    }
    D_004A289C_31E0->SetViewport(0.0f, 0.0f, 640.0f, 480.0f, 1, 0, 0.0f, 1.0f);
    self->font->color = sVec4_31E0(1.0f, 1.0f, 1.0f, 0.0f);
    self->font->SetScale(0.7f, 0.7f);
    self->font->color2 = sVec4_31E0(1.0f, 0.0f, 0.0f, 0.0f);
    self->font->scale = D_004A4EA8;
    float w = func_003921F0(self->font, self->text, 0, 0, self->font->f38, self->font->f3C);
    sVec4_31E0 pos(620.0f - w, 445.0f - (float)self->font->count * self->font->f34 * 0.35f, 0.0f, 1.0f);
    D_004A289C_31E0->stateTop->f8_5 = 0x1F;
    func_00391E30(self->font, pos.x, pos.y, self->text);
    self->font->scale = sV2_31E0(2.0f, 2.0f);
    pos.x = pos.x - 17.0f;
    pos.y = 445.0f;
    sV2_31E0 size;
    sV2_31E0 uv0(0.0f, 0.0f);
    sV2_31E0 uv1(1.0f, 1.0f);
    size.x = f * 18.0f;
    size.y = 18.0f;
    *(short*)((char*)D_004A289C_31E0->stateTop + 0x10) = D_004A289C_31E0->GetF1068();
    D_004A289C_31E0->DrawSprite(pos, size, uv0, uv1, sCol_31E0(1.0f, 1.0f, 1.0f, 1.0f));
    D_004A289C_31E0->End2D();
    D_004A289C_31E0->EndScene();
    D_004A289C_31E0->stateTop--;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F36C0);
#ifdef SKIP_ASM
extern "C" void func_001F36C0(void* self, int bit)
{
    *(int*)((char*)self + 0x4) |= (1 << bit);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F36D8);
#ifdef SKIP_ASM
extern "C" void func_001F36D8(void* self, int bit)
{
    *(int*)((char*)self + 0x4) &= ~(1 << bit);
    if (*(int*)((char*)self + 0x4) == 0) {
        *(int*)((char*)self + 0x8) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F3700);
#ifdef SKIP_ASM
extern "C" int func_00147318(void* self, int a1);
extern "C" void func_001A1CB8(void* self, int a1, int val);
extern void* D_00473AA8[];

extern "C" void* func_001F3700(void* self, int a1)
{
    func_0039E2A0(self, a1);
    *(int*)((char*)self + 0xC) = 0x27;
    *(void***)((char*)self + 0x8) = D_00473AA8;
    int idx = func_00147318(cBE_getInterface_Fv(cBE_getBE(), 1), 0);
    *(signed char*)((char*)self + 0x44) = 0;
    void* p = **(void***)((char*)self + 0x10);
    if (p != 0) {
        unsigned char mask = 1 << idx;
        func_001A1CB8(p, 0, mask);
        *(unsigned char*)((char*)self + 0x15) = mask;
    }
    return self;
}
#endif

