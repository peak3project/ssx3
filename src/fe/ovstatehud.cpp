#include "common.h"

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

//100%
INCLUDE_ASM("fe/ovstatehud", cOVStateHiScoreList_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
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
struct sVEntry001E9130 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sObj001E9130 {
    int field_0x0;
    sVEntry001E9130* vt;
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
int GetHashValue32(char* str);
extern "C" float func_003921F0(void* self, const unsigned short* str, void* out, int n, float sx, float sy);

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
extern "C" void func_001E92A8(void* self);
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
extern "C" unsigned short* func_002C2508(unsigned short* dst, unsigned short* src);
extern "C" void func_001E92A8(void* self);
extern "C" void func_001E9540(void* self, unsigned short* str, int a2, sVec2f* pos)
{
    func_002C2508((unsigned short*)((char*)self + 0x4C), str);
    *(int*)((char*)self + 0x8) = a2;
    *(sVec2f*)((char*)self + 0x10) = *pos;
    func_001E92A8(self);
}
#endif

INCLUDE_ASM("fe/ovstatehud", func_001E95A0);

//100%
INCLUDE_ASM("fe/ovstatehud", func_001E9A30);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0_9A30(void* self, int a1) __asm__("func_0039E2A0");
extern "C" void func_0020EAA0(void*);
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
    func_0039E2A0_9A30(self, a1);
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

INCLUDE_ASM("fe/ovstatehud", cOVStateHUD1P_onCreateScreen);

INCLUDE_ASM("fe/ovstatehud", func_001EA930);

//100%
INCLUDE_ASM("fe/ovstatehud", func_001EC1F0);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C2508(unsigned short* dst, unsigned short* src);
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

struct sVEnt_001F1190 { short delta; short index; void (*fn)(void*, int, sHudVert_001F1190*, int); };
extern char* D_004A289C;

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
        sVEnt_001F1190* vt = *(sVEnt_001F1190**)(D_004A289C + 0x10D8);
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

struct sVEnt_001F1338 { short delta; short index; void (*fn)(void*, int, sHudVert_001F1338*, int); };
extern char* D_004A289C;

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
    sVEnt_001F1338* vt = *(sVEnt_001F1338**)(D_004A289C + 0x10D8);
    vt[71].fn(D_004A289C + vt[71].delta, 4, v, 0);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F14B0);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);
struct sGlyphTable_1F14B0;
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
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);

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

INCLUDE_ASM("fe/ovstatehud", func_001F1E28);

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F22E8);
#ifdef SKIP_ASM
extern "C" float func_003921F0(void* self, const unsigned short* str, void* out, int n, float sx, float sy);
extern "C" void func_00391E30(void* self, float x, float y, const unsigned short* str);

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

INCLUDE_ASM("fe/ovstatehud", func_001F25E0);

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F2AA0);
#ifdef SKIP_ASM
extern "C" char* func_00392430(void* f, const char* str, char* dst, int max, float sx, float width);
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);

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
extern "C" float func_003921F0(void* self, const unsigned short* str, void* out, int n, float sx, float sy);
extern "C" void func_00391E30(void* self, float x, float y, const unsigned short* str);

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
    int t0 = 0;
    e->field_0x0 = t0;
    *(int*)&e->rangeMax = t0;
    e->field_0x4 = t0;
    *(int*)&e->rangeMin = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F30D8);
#ifdef SKIP_ASM
struct sVEntry001F30D8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};
struct sHudIds001F30D8 {
    int a;
    int b;
    int c;
    int d;
};

int GetHashValue32(char* str);
extern "C" int func_003983F0(void* self, int key);
extern void* D_004A28A8;
extern char D_0046ED78[];
extern char D_004A21F0[];

extern "C" void func_001F30D8(void* p)
{
    sHudIds001F30D8* self = (sHudIds001F30D8*)p;
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001F30D8* vt = *(sVEntry001F30D8**)(o + 4);
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
    int t0 = 0;
    e->field_0x0 = t0;
    *(int*)&e->rangeMax = t0;
    e->field_0x4 = t0;
    *(int*)&e->rangeMin = t0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatehud", func_001F3188);
#ifdef SKIP_ASM
extern "C" void func_001F3188(void* self)
{
    if (*(int*)((char*)self + 4) != 0) {
        float* t = (float*)((char*)self + 8);
        float two = 2.0f;
        *t += 0.01666666753590107f;
        while (*t > two) {
            *t -= two;
        }
    }
}
#endif

INCLUDE_ASM("fe/ovstatehud", func_001F31E0);

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
extern "C" void* func_0039E2A0(void* self);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00147318(void* self, int a1);
extern "C" void func_001A1CB8(void* self, int a1, int val);
extern void* D_00473AA8[];

extern "C" void* func_001F3700(void* self)
{
    func_0039E2A0(self);
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

