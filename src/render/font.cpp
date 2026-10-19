#include "common.h"

// R5900 128-bit GPR quadword, for functions that copy a 16-byte block via a
// single lq/sq pair instead of word-by-word.
typedef int cQuad128 __attribute__((mode(TI)));

//100%
INCLUDE_ASM("render/font", cFont_linkFont);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
struct sFontTexHdr;
extern "C" void cFont_downloadTexture(char* self, sFontTexHdr* img);
extern char D_004A46F8[];

struct sGlyph_1788 {
    unsigned short code;    // 0x0
    unsigned char w;        // 0x2
    unsigned char h;        // 0x3
    unsigned short u;       // 0x4
    unsigned short v;       // 0x6
    unsigned char adv;      // 0x8
    unsigned char xoff;     // 0x9
    signed char yoff;       // 0xA
    char pad;
};

struct sPad_1788 {
    float x, y;
};

struct sFont_1788 {
    int count;              // 0x0
    sGlyph_1788* table;     // 0x4
    sGlyph_1788* def;       // 0x8
    int first;              // 0xC
    int last;               // 0x10
    int maxH;               // 0x14
    sPad_1788 pad;          // 0x18
};

extern "C" void cFont_linkFont(void* vself, void* vdata, int flags)
{
    sFont_1788* self = (sFont_1788*)vself;
    char* data = (char*)vdata;
    sGlyph_1788* src = (sGlyph_1788*)(data + *(int*)(data + 0x14));
    sPad_1788 p;
    p.x = (float)data[0x10];
    p.y = (float)data[0x11];
    self->pad = p;
    self->count = *(short*)(data + 0xA);
    self->table = (sGlyph_1788*)operator_new_tag(self->count * 12, D_004A46F8, flags, 0);
    int space = 0;
    self->maxH = 0;
    self->last = self->first = src->code;
    for (int i = 0; i < self->count; i++) {
        self->table[i].code = src[i].code;
        self->table[i].w = src[i].w;
        self->table[i].h = src[i].h;
        self->table[i].u = src[i].u;
        self->table[i].v = src[i].v;
        self->table[i].adv = src[i].adv;
        self->table[i].xoff = src[i].xoff;
        self->table[i].yoff = src[i].yoff;
        if (i != 0 && self->table[i].code == self->last + 1) {
            self->last = self->table[i].code;
        }
        if (self->table[i].code == ' ') {
            space = i;
        }
        if (self->table[i].code == 0xAC) {
            self->def = &self->table[i];
        }
        if (self->table[i].code == 0xA0) {
            self->table[i].w = src[space].w;
            self->table[i].h = src[space].h;
            self->table[i].u = src[space].u;
            self->table[i].v = src[space].v;
            self->table[i].adv = src[space].adv;
            self->table[i].xoff = src[space].xoff;
            self->table[i].yoff = src[space].yoff;
        }
        if (self->maxH < self->table[i].h + self->table[i].yoff) {
            self->maxH = self->table[i].h + self->table[i].yoff;
        }
    }
    cFont_downloadTexture((char*)self, (sFontTexHdr*)(data + *(int*)(data + 0x1C)));
}
#endif

//100%
INCLUDE_ASM("render/font", func_003919E8);
#ifdef SKIP_ASM
void cMemMan_free(void*);

class sFontGfx_19E8 {
public:
    char pad_0x0[0x10D8];
    virtual void v1(int);
    virtual void v2(int);
    virtual void v3(int);
    virtual void v4(int);
    virtual void v5(int);
    virtual void v6(int);
    virtual void v7(int);
    virtual void v8(int);
    virtual void v9(int);
    virtual void v10(int);
    virtual void v11(int);
    virtual void v12(int);
    virtual void v13(int);
    virtual void v14(int);
    virtual void v15(int);
    virtual void v16(int);
    virtual void v17(int);
    virtual void v18(int);
    virtual void v19(int);
    virtual void v20(int);
    virtual void v21(int);
    virtual void v22(int);
    virtual void v23(int);
    virtual void v24(int);
    virtual void v25(int);
    virtual void v26(int);
    virtual void v27(int);
    virtual void v28(int);
    virtual void v29(int);
    virtual void v30(int);
    virtual void v31(int);
    virtual void v32(int);
    virtual void v33(int);
    virtual void v34(int);
    virtual void v35(int);
    virtual void v36(int);
    virtual void v37(int);
    virtual void v38(int);
    virtual void v39(int);
    virtual void v40(int);
    virtual void v41(int);
    virtual void v42(int);
    virtual void v43(int);
    virtual void v44(int);
    virtual void v45(int);
    virtual void v46(int);
    virtual void v47(int);
    virtual void v48(int);
    virtual void v49(int);
    virtual void v50(int);
};

extern sFontGfx_19E8* D_004A5B80_19E8 __asm__("D_004A5B80");

struct sFont_19E8 {
    int f0;
    void* pix;          // 0x4
    char pad_0x8[0x58];
    int handle;         // 0x60
};

extern "C" void func_003919E8(sFont_19E8* self)
{
    if (self->pix != 0) {
        cMemMan_free(self->pix);
    }
    self->pix = 0;
    self->f0 = 0;
    sFontGfx_19E8* g = D_004A5B80_19E8;
    if (self->handle >= 0) {
        g->v50(self->handle);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", cFont_downloadTexture);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_003E6448(void* dst, int c, int n);
extern "C" void func_003E6574(void* dst, const void* src, int n);
extern char D_00492F40[];
extern char D_00492F50[];
void cMemMan_free(void*);

struct sFontVEntryDL {
    short delta;
    short index;
    int (*fn)(void*, void*, void*, int, int, int, int, int, void*, int, int, int);
};

struct sFontCtxDL {
    char pad_0x0[0x10D8];
    sFontVEntryDL* vtable;      // 0x10D8
};

extern sFontCtxDL* D_004A5B80_DL __asm__("D_004A5B80");

struct sFontTexHdr {
    int f0;
    short w;        // 0x4
    short h;        // 0x6
    int f8;
    int flags;      // 0xC
    int offset;     // 0x10
};

struct sFontUV {
    float u, v;
};

extern "C" void cFont_downloadTexture(char* self, sFontTexHdr* img)
{
    sFontCtxDL* g = D_004A5B80_DL;
    int p2 = 1;
    do {
        p2 <<= 1;
    } while (p2 <= img->h);
    sFontUV uv;
    uv.v = 1.0f / p2;
    uv.u = 1.0f / img->w;
    *(sFontUV*)(self + 0x20) = uv;
    unsigned char* pix = (unsigned char*)operator_new_tag((img->w * p2) >> 1, D_00492F40, 0x100, 0);
    unsigned char* pal = (unsigned char*)operator_new_tag(0x40, D_00492F50, 0x100, 0);
    func_003E6448(pix, 0, (img->w * p2) >> 1);
    func_003E6448(pal, 0, 0x40);
    char* src;
    if (img->flags & 0x1000)
        src = (char*)img + img->offset;
    else
        src = (char*)img + 0x10;
    func_003E6574(pix, src, (img->w * img->h) >> 1);
    int i;
    signed char* p;
    for (i = 0, p = (signed char*)pal; i < 16; i++) {
        p[0] = -0x80;
        p[1] = -0x80;
        p[2] = -0x80;
        p[3] = (i << 7) / 15;
        p += 4;
    }
    sFontVEntryDL* vt = g->vtable;
    *(int*)(self + 0x60) = vt[47].fn((char*)g + vt[47].delta, pix, self + 0x64, img->w, p2, 0, 0xB, 1, pal, 0, 1, -1);
    if (pix != 0)
        cMemMan_free(pix);
    if (pal != 0)
        cMemMan_free(pal);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00391C48);
#ifdef SKIP_ASM
struct sMat00391C48 {
    float m[4][4];
} __attribute__((aligned(16)));

extern sMat00391C48 D_00500CA0;
extern "C" void func_004186C8(sMat00391C48* m);
extern "C" void func_00391CB0(void* self, float x, float y, sMat00391C48* m);

extern "C" void func_00391C48(void* self, float x, float y)
{
    func_004186C8(&D_00500CA0);
    func_00391CB0(self, x, y, &D_00500CA0);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00391CB0);
#ifdef SKIP_ASM
struct sFontRS1CB0 {
    int field_0x0;          // 0x0
    int field_0x4;          // 0x4
    int flags;              // 0x8, bits 5..9 = alpha level
    int field_0xC;          // 0xC
    short tex;              // 0x10
    short pad;
};

struct sFontVEntry1CB0 {
    short delta;
    short index;
    void (*fn)(void*, void*, sMat00391C48*, void*, float, float, float, float, float, float, float);
};

struct sFontCtx1CB0 {
    char pad_0x0[0xE84];
    sFontRS1CB0* top;           // 0xE84
    char pad_0xE88[0x10D8 - 0xE88];
    sFontVEntry1CB0* vtable;    // 0x10D8
};

extern sFontCtx1CB0* D_004A5B80;

struct sFontPos1CB0 {
    float x, y, z, w;
    sFontPos1CB0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

static inline int fontGetTex(void* s)
{
    return *(int*)((char*)s + 0x60);
}

extern "C" void func_00391CB0(void* self, float x, float y, sMat00391C48* m)
{
    sFontCtx1CB0* g = D_004A5B80;
    char* s = (char*)self;
    g->top->tex = fontGetTex(self);
    sFontPos1CB0 pos(x + *(float*)(s + 0x18) * *(float*)(s + 0x38),
                     y + *(float*)(s + 0x1C) * *(float*)(s + 0x3C), 0.0f, 0.0f);
    if (*(float*)(s + 0x28) != 0.0f || *(float*)(s + 0x2C) != 0.0f) {
        sFontRS1CB0* top = g->top;
        int saved = (unsigned)(top->flags & 0x3E0) >> 5;
        int a = saved - 1;
        if (a < 0) a = 0;
        top->flags = (top->flags & ~0x3E0) | ((a << 5) & 0x3E0);
        sFontVEntry1CB0* vt = g->vtable;
        vt[80].fn((char*)g + vt[80].delta, self, m, s + 0x50,
                  pos.x + *(float*)(s + 0x28), pos.y + *(float*)(s + 0x2C),
                  *(float*)(s + 0x38), *(float*)(s + 0x3C), *(float*)(s + 0x20), *(float*)(s + 0x24), pos.z);
        sFontRS1CB0* top2 = g->top;
        top2->flags = (top2->flags & ~0x3E0) | (saved << 5);
    }
    sFontVEntry1CB0* vt = g->vtable;
    vt[80].fn((char*)g + vt[80].delta, self, m, s + 0x40, pos.x, pos.y,
              *(float*)(s + 0x38), *(float*)(s + 0x3C), *(float*)(s + 0x20), *(float*)(s + 0x24), pos.z);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00391E30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sFontRS1E30 {
    int field_0x0;          // 0x0
    int field_0x4;          // 0x4
    int flags;              // 0x8, bits 5..9 = alpha level
    int field_0xC;          // 0xC
    short tex;              // 0x10
    short pad;
};

struct sFontVEntry1E30 {
    short delta;
    short index;
    void (*fn)(void*, void*, void*, void*, float, float, float, float, float, float, float);
};

struct sFontCtx1E30 {
    char pad_0x0[0xE84];
    sFontRS1E30* top;           // 0xE84
    char pad_0xE88[0x10D8 - 0xE88];
    sFontVEntry1E30* vtable;    // 0x10D8
};

extern sFontCtx1E30* D_004A5B80_1E30 __asm__("D_004A5B80");

struct sFontPos1E30 {
    float x, y, z, w;
    sFontPos1E30(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

static inline int fontGetTex1E30(void* s)
{
    return *(int*)((char*)s + 0x60);
}

extern "C" void func_00391E30(void* self, float x, float y, void* m)
{
    sFontCtx1E30* g = D_004A5B80_1E30;
    char* s = (char*)self;
    g->top->tex = fontGetTex1E30(self);
    sFontPos1E30 pos(x + *(float*)(s + 0x18) * *(float*)(s + 0x38),
                     y + *(float*)(s + 0x1C) * *(float*)(s + 0x3C), 0.0f, 0.0f);
    if (*(float*)(s + 0x28) != 0.0f || *(float*)(s + 0x2C) != 0.0f) {
        sFontRS1E30* top = g->top;
        int saved = (unsigned)(top->flags & 0x3E0) >> 5;
        int a = saved - 1;
        if (a < 0) a = 0;
        top->flags = (top->flags & ~0x3E0) | ((a << 5) & 0x3E0);
        sFontVEntry1E30* vt = g->vtable;
        vt[81].fn((char*)g + vt[81].delta, self, m, s + 0x50,
                  pos.x + *(float*)(s + 0x28), pos.y + *(float*)(s + 0x2C),
                  *(float*)(s + 0x38), *(float*)(s + 0x3C), *(float*)(s + 0x20), *(float*)(s + 0x24), pos.z);
        sFontRS1E30* top2 = g->top;
        top2->flags = (top2->flags & ~0x3E0) | (saved << 5);
    }
    sFontVEntry1E30* vt = g->vtable;
    vt[81].fn((char*)g + vt[81].delta, self, m, s + 0x40, pos.x, pos.y,
              *(float*)(s + 0x38), *(float*)(s + 0x3C), *(float*)(s + 0x20), *(float*)(s + 0x24), pos.z);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00391FB0);
#ifdef SKIP_ASM
struct sGlyph1FB0 {
    unsigned short code;    // 0x0
    unsigned char w;        // 0x2
    unsigned char h;        // 0x3
    int f4;
    signed char adv;        // 0x8
    signed char xoff;       // 0x9
    signed char yoff;       // 0xA
    char pad;
};

struct sFontRes1FB0 {
    int count;              // 0x0
    sGlyph1FB0* table;      // 0x4
    sGlyph1FB0* def;        // 0x8
    int first;              // 0xC
    int last;               // 0x10
    char pad_0x14[0x28 - 0x14];
    float padX;             // 0x28
    float padY;             // 0x2C
};

struct sRect1FB0 {
    float x0, y0, x1, y1;
};

static inline sGlyph1FB0* sFontRes1FB0_find(sFontRes1FB0* f, int c)
{
    if (c < f->first)
        return 0;
    if (c <= f->last)
        return f->table + c - f->first;
    int lo = f->last - f->first;
    int hi = f->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph1FB0* p = f->table + mid;
        if (c == p->code)
            return p;
        if (c < p->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return f->def;
}

// PORT: g++ `<?`/`>?` (min/max) operators, removed in GCC 4.3.
extern "C" float func_00391FB0(void* f_, const char* s, void* r_, int mono, float sx, float sy)
{
    sFontRes1FB0* f = (sFontRes1FB0*)f_;
    sRect1FB0* r = (sRect1FB0*)r_;
    sRect1FB0 tmp;
    sRect1FB0* rc = r ? r : &tmp;
    rc->x0 = 0.0f;
    rc->y0 = 0.0f;
    rc->x1 = 0.0f;
    rc->y1 = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    for (; *s; s++) {
        sGlyph1FB0* g = sFontRes1FB0_find(f, *(unsigned char*)s);
        if (g) {
            float adv = g->adv * sx;
            rc->x0 = (x + g->xoff * sx) <? rc->x0;
            rc->y0 = (y + g->yoff * sy) <? rc->y0;
            rc->y1 = (y + (g->yoff + g->h) * sy) >? rc->y1;
            float nx;
            if (!mono) {
                rc->x1 = (x + (g->xoff + g->w) * sx) >? rc->x1;
                nx = x + adv;
            } else {
                rc->x1 = (x + adv) >? rc->x1;
                nx = x + adv;
            }
            x = nx;
        }
    }
    rc->x1 = rc->x1 + rc->x0;
    rc->y1 = rc->y1 + rc->y0;
    if (f->padX < 0.0f) {
        rc->x0 = rc->x0 - f->padX;
        rc->x1 = rc->x1 - f->padX;
    } else {
        rc->x1 = rc->x1 + f->padX;
    }
    if (f->padY < 0.0f) {
        rc->y0 = rc->y0 - f->padY;
        rc->y1 = rc->y1 - f->padY;
    } else {
        rc->y1 = rc->y1 + f->padY;
    }
    return rc->x1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003921F0);
#ifdef SKIP_ASM
struct sGlyph21F0 {
    unsigned short code;    // 0x0
    unsigned char w;        // 0x2
    unsigned char h;        // 0x3
    int f4;
    signed char adv;        // 0x8
    signed char xoff;       // 0x9
    signed char yoff;       // 0xA
    char pad;
};

struct sFontRes21F0 {
    int count;              // 0x0
    sGlyph21F0* table;      // 0x4
    sGlyph21F0* def;        // 0x8
    int first;              // 0xC
    int last;               // 0x10
    char pad_0x14[0x28 - 0x14];
    float padX;             // 0x28
    float padY;             // 0x2C
};

struct sRect21F0 {
    float x0, y0, x1, y1;
};

static inline sGlyph21F0* sFontRes21F0_find(sFontRes21F0* f, int c)
{
    if (c < f->first)
        return 0;
    if (c <= f->last)
        return f->table + c - f->first;
    int lo = f->last - f->first;
    int hi = f->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph21F0* p = f->table + mid;
        if (c == p->code)
            return p;
        if (c < p->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return f->def;
}

// PORT: g++ `<?`/`>?` (min/max) operators, removed in GCC 4.3.
extern "C" float func_003921F0(void* f_, const unsigned short* s, void* r_, int mono, float sx, float sy)
{
    sFontRes21F0* f = (sFontRes21F0*)f_;
    sRect21F0* r = (sRect21F0*)r_;
    sRect21F0 tmp;
    sRect21F0* rc = r ? r : &tmp;
    rc->x0 = 0.0f;
    rc->y0 = 0.0f;
    rc->x1 = 0.0f;
    rc->y1 = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    for (; *s; s++) {
        sGlyph21F0* g = sFontRes21F0_find(f, *s);
        if (g) {
            float adv = g->adv * sx;
            rc->x0 = (x + g->xoff * sx) <? rc->x0;
            rc->y0 = (y + g->yoff * sy) <? rc->y0;
            rc->y1 = (y + (g->yoff + g->h) * sy) >? rc->y1;
            float nx;
            if (!mono) {
                rc->x1 = (x + (g->xoff + g->w) * sx) >? rc->x1;
                nx = x + adv;
            } else {
                rc->x1 = (x + adv) >? rc->x1;
                nx = x + adv;
            }
            x = nx;
        }
    }
    rc->x1 = rc->x1 + rc->x0;
    rc->y1 = rc->y1 + rc->y0;
    if (f->padX < 0.0f) {
        rc->x0 = rc->x0 - f->padX;
        rc->x1 = rc->x1 - f->padX;
    } else {
        rc->x1 = rc->x1 + f->padX;
    }
    if (f->padY < 0.0f) {
        rc->y0 = rc->y0 - f->padY;
        rc->y1 = rc->y1 - f->padY;
    } else {
        rc->y1 = rc->y1 + f->padY;
    }
    return rc->x1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392430);
#ifdef SKIP_ASM
struct sGlyph2430 {
    unsigned short code;    // 0x0
    unsigned char w;        // 0x2
    unsigned char h;        // 0x3
    int f4;
    signed char adv;        // 0x8
    signed char xoff;       // 0x9
    signed char yoff;       // 0xA
    char pad;
};

struct sFontRes2430 {
    int count;              // 0x0
    sGlyph2430* table;      // 0x4
    sGlyph2430* def;        // 0x8
    int first;              // 0xC
    int last;               // 0x10
    char pad_0x14[0x28 - 0x14];
    float padX;             // 0x28
    float padY;             // 0x2C
};

static inline sGlyph2430* sFontRes2430_find(sFontRes2430* f, int c)
{
    if (c < f->first)
        return 0;
    if (c <= f->last)
        return f->table + c - f->first;
    int lo = f->last - f->first;
    int hi = f->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph2430* p = f->table + mid;
        if (c == p->code)
            return p;
        if (c < p->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return f->def;
}

// PORT: PS2-only abs.s asm helper (fabsf off-PS2).
static inline float fabs_2430(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// Copy as much of str into dst as fits in width; returns where the next line starts (0 when done).
extern "C" char* func_00392430(void* f_, const char* str, char* dst, int max, float sx, float width)
{
    sFontRes2430* f = (sFontRes2430*)f_;
    width -= fabs_2430(f->padX);
    if (width < 0.0f)
        width = 0.0f;
    const char* start = str;
    float w = 0.0f;
    float pend = w;
    int lastSpace = -1;
    int n = 0;
    int k = 0;
    while (*str) {
        int sp = *str == ' ';
        if (sp) {
            if (width <= w) {
                dst[lastSpace + 1] = 0;
                const char* p = start + lastSpace;
                do
                    p++;
                while (*p == ' ');
                return (char*)p;
            }
            if (k > 0 && start[k - 1] != ' ')
                lastSpace = k - 1;
        }
        sGlyph2430* g = sFontRes2430_find(f, *(unsigned char*)str);
        if (g) {
            float right = (g->xoff + g->w) * sx;
            w += pend + right;
            pend = g->adv * sx - right;
        }
        if (width <= w) {
            if (lastSpace == -1) {
                dst[n] = 0;
                return (char*)str;
            }
        }
        dst[n] = *str;
        n++;
        k++;
        str++;
        if (n == max - 1)
            break;
    }
    if (width <= w) {
        dst[lastSpace + 1] = 0;
        const char* p = start + lastSpace;
        do
            p++;
        while (*p == ' ');
        return (char*)p;
    }
    dst[n] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392680);
#ifdef SKIP_ASM
struct sGlyph2680 {
    unsigned short code;    // 0x0
    unsigned char w;        // 0x2
    unsigned char h;        // 0x3
    int f4;
    signed char adv;        // 0x8
    signed char xoff;       // 0x9
    signed char yoff;       // 0xA
    char pad;
};

struct sFontRes2680 {
    int count;              // 0x0
    sGlyph2680* table;      // 0x4
    sGlyph2680* def;        // 0x8
    int first;              // 0xC
    int last;               // 0x10
    char pad_0x14[0x28 - 0x14];
    float padX;             // 0x28
    float padY;             // 0x2C
};

static inline sGlyph2680* sFontRes2680_find(sFontRes2680* f, int c)
{
    if (c < f->first)
        return 0;
    if (c <= f->last)
        return f->table + c - f->first;
    int lo = f->last - f->first;
    int hi = f->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph2680* p = f->table + mid;
        if (c == p->code)
            return p;
        if (c < p->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return f->def;
}

// PORT: PS2-only abs.s asm helper (fabsf off-PS2).
static inline float fabs_2680(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// Unicode version of func_00392430: copies as much of str into dst as fits in width; returns the next line start (0 when done).
extern "C" unsigned short* func_00392680(void* f_, const unsigned short* str, unsigned short* dst, int max, float sx, float width)
{
    sFontRes2680* f = (sFontRes2680*)f_;
    width -= fabs_2680(f->padX);
    if (width < 0.0f)
        width = 0.0f;
    const unsigned short* start = str;
    float w = 0.0f;
    float pend = w;
    int lastSpace = -1;
    int n = 0;
    int k = 0;
    while (*str) {
        int sp = *str == ' ';
        if (sp) {
            if (width <= w) {
                dst[lastSpace + 1] = 0;
                const unsigned short* p = start + lastSpace;
                do
                    p++;
                while (*p == ' ');
                return (unsigned short*)p;
            }
            if (k > 0 && start[k - 1] != ' ')
                lastSpace = k - 1;
        }
        sGlyph2680* g = sFontRes2680_find(f, *str);
        if (g) {
            float right = (g->xoff + g->w) * sx;
            w += pend + right;
            pend = g->adv * sx - right;
        }
        if (width <= w) {
            if (lastSpace == -1) {
                dst[n] = 0;
                return (unsigned short*)str;
            }
        }
        dst[n] = *str;
        n++;
        k++;
        str++;
        if (n == max - 1)
            break;
    }
    if (width <= w) {
        dst[lastSpace + 1] = 0;
        const unsigned short* p = start + lastSpace;
        do
            p++;
        while (*p == ' ');
        return (unsigned short*)p;
    }
    dst[n] = 0;
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/font", func_00392908);
#ifdef SKIP_ASM
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);

extern "C" void func_00392908(void* self, const char* str, float x, float y)
{
    float w = func_00391FB0(self, str, 0, 0, *(float*)((char*)self + 0x38), *(float*)((char*)self + 0x3C));
    func_00391CB0(self, x - w * 0.5f, y, (sMat00391C48*)str);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392980);
#ifdef SKIP_ASM
extern "C" void func_00392980(void* self, const unsigned short* str, float x, float y)
{
    float w = func_003921F0(self, str, 0, 0, *(float*)((char*)self + 0x38), *(float*)((char*)self + 0x3C));
    func_00391E30(self, x - w * 0.5f, y, (void*)str);
}
#endif

//100%
INCLUDE_ASM("render/font", func_003929F8);
#ifdef SKIP_ASM
extern void* D_004A3E90;
extern "C" void func_003191C0(void* str, const char* fmt, void* ap);
extern "C" void cBXString__cBXString(void* self, int flags);

struct sBXStr_29F8 {
    char* p;
};

extern "C" void func_003929F8(void* self, const char* fmt, void* ap, float x, float y)
{
    sBXStr_29F8 s;
    s.p = (char*)D_004A3E90;
    func_003191C0(&s, fmt, ap);
    func_00392908(self, s.p, x, y);
    cBXString__cBXString(&s, 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/font", func_00392A60);
#ifdef SKIP_ASM
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);

extern "C" void func_00392A60(void* self, const char* str, float x, float y)
{
    float w = func_00391FB0(self, str, 0, 0, *(float*)((char*)self + 0x38), *(float*)((char*)self + 0x3C));
    func_00391CB0(self, x - w, y, (sMat00391C48*)str);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392AD0);
#ifdef SKIP_ASM
extern "C" void func_00392AD0(void* self, const unsigned short* str, float x, float y)
{
    float w = func_003921F0(self, str, 0, 0, *(float*)((char*)self + 0x38), *(float*)((char*)self + 0x3C));
    func_00391E30(self, x - w, y, (void*)str);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392B40);
#ifdef SKIP_ASM
extern void* D_004A3E90;
extern "C" void func_003191C0(void* str, const char* fmt, void* ap);
extern "C" void cBXString__cBXString(void* self, int flags);

struct sBXStr_2B40 {
    char* p;
};

extern "C" void func_00392B40(void* self, const char* fmt, void* ap, float x, float y)
{
    sBXStr_2B40 s;
    s.p = (char*)D_004A3E90;
    func_003191C0(&s, fmt, ap);
    func_00392A60(self, s.p, x, y);
    cBXString__cBXString(&s, 2);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392BA8);
#ifdef SKIP_ASM
struct sGlyph {
    unsigned short code;
    char pad_0x2[6];
    signed char width;
    char pad_0x9[3];
};

struct sGlyphTable {
    int count;
    sGlyph* glyphs;
    sGlyph* fallback;
    int first;
    int last;
};

static inline sGlyph* findGlyph(sGlyphTable* t, int c)
{
    if (c < t->first)
        return 0;
    if (c <= t->last)
        return t->glyphs + c - t->first;
    int lo = t->last - t->first;
    int hi = t->count;
    do {
        int mid = (lo + hi) >> 1;
        sGlyph* g = &t->glyphs[mid];
        if (c == g->code)
            return g;
        if (c < g->code)
            hi = mid;
        else
            lo = mid + 1;
    } while (lo < hi);
    return t->fallback;
}

extern "C" float func_00392BA8(sGlyphTable* t, char c)
{
    sGlyph* g = findGlyph(t, c);
    if (g)
        return g->width;
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392C60);
#ifdef SKIP_ASM
extern "C" float func_00392C60(sGlyphTable* t, unsigned short c)
{
    sGlyph* g = findGlyph(t, c);
    if (g)
        return g->width;
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392D18);
#ifdef SKIP_ASM
struct sFontVec3 {
    float x, y, z;
};

struct sFontQuad {
    int v[4];
} __attribute__((aligned(16)));

struct sFontState {
    sFontVec3 field_0x0;    // 0x0
    int count;              // 0xc
    sFontVec3 vecs[5];      // 0x10
    sFontQuad quads[5];     // 0x50
    int field_0xa0;         // 0xa0
    int field_0xa4;         // 0xa4
};

extern "C" void func_00392D18(sFontState* self)
{
    sFontVec3 t;
    t.x = 0.0f;
    t.y = 0.0f;
    t.z = 0.0f;
    self->count = 0;
    self->field_0x0 = t;
    self->field_0xa0 = 0;
    self->field_0xa4 = 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392D58);
#ifdef SKIP_ASM
extern "C" void func_00392D58(void *arg0, void *arg1) {
    (*(float *)((char*)(arg0) + (0))) = (float) ((*(float *)((char*)(arg0) + (0))) + (*(float *)((char*)(arg1) + (0))));
    (*(float *)((char*)(arg0) + (4))) = (float) ((*(float *)((char*)(arg0) + (4))) + (*(float *)((char*)(arg1) + (4))));
    (*(float *)((char*)(arg0) + (8))) = (float) ((*(float *)((char*)(arg0) + (8))) + (*(float *)((char*)(arg1) + (8))));
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392D90);
#ifdef SKIP_ASM
extern "C" void func_00392D90(sFontState* self, sFontQuad* q, sFontVec3* v)
{
    self->vecs[self->count] = *v;
    self->quads[self->count] = *q;
    self->count++;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392DE0);
#ifdef SKIP_ASM
extern "C" void func_00392DE0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xA0))) = arg1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392DE8__FPvi);
#ifdef SKIP_ASM
void func_00392DE8(void* self, int val)
{
    *(int*)((char*)self + 0xA4) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392DF0);
#ifdef SKIP_ASM
extern "C" float func_0031BF60(float a);

extern "C" void* func_00392DF0(void* self)
{
    int i;
    for (i = 0; i < 0x280; i++) {
        ((float*)self)[i] = func_0031BF60((float)i * 0.01227184571325779f);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00392E60);
#ifdef SKIP_ASM
extern "C" void func_00392E60(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    int cur = *(int *)arg0;
    *(int *)((char*)arg0 + 0x8) = cur;
    *(int *)((char*)arg0 + 0x2C) = 1;
    *(int *)((char*)arg0 + 0x18) = arg2;
    *(int *)((char*)arg0 + 0x24) = arg4;
    *(int *)((char*)arg0 + 0x1C) = arg1;
    *(int *)((char*)arg0 + 0x20) = arg3;
    *(int *)((char*)arg0 + 0x28) = arg4 != 0;
    *(int *)arg0 = cur + 0x10;
}
#endif

INCLUDE_ASM("render/font", func_00392E98);
//100%
INCLUDE_ASM("render/font", func_00393008);
#ifdef SKIP_ASM
extern "C" void* func_00393008(void* self, ...)
{
    return self;
}
#endif

INCLUDE_ASM("render/font", func_00393048);

//100%
INCLUDE_ASM("render/font", func_00393FA8__FPv);
#ifdef SKIP_ASM
void func_00393FA8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00393FB0__FPv);
#ifdef SKIP_ASM
int func_00393FB0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00393FB8);
#ifdef SKIP_ASM
extern "C" void func_00393FB8(void* self, int a1, int a2)
{
    *(float*)self = (float)a1;
    *(float*)((char*)self + 0x4) = (float)a2;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00393FD8);
#ifdef SKIP_ASM
extern "C" int func_00393FD8(void* self)
{
    return (int)*(float*)self;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00393FF0);
#ifdef SKIP_ASM
extern "C" int func_00393FF0(void* self)
{
    return (int)*(float*)((char*)self + 0x4);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394008__FPv);
#ifdef SKIP_ASM
void func_00394008(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394010__FPv);
#ifdef SKIP_ASM
int func_00394010(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394018__FPv);
#ifdef SKIP_ASM
int func_00394018(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394020);
#ifdef SKIP_ASM
extern "C" void func_00394020(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x270))) = arg1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394028);
#ifdef SKIP_ASM
extern "C" int func_00394028(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x270)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394030);
#ifdef SKIP_ASM
extern "C" void func_00394030(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x274))) = arg1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394038);
#ifdef SKIP_ASM
extern "C" int func_00394038(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x274)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394040);
#ifdef SKIP_ASM
extern "C" void func_00394040(char* base, int value, int idx) {
    *(int*)(base + (idx << 2) + 0xC) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394050);
#ifdef SKIP_ASM
extern "C" int func_00394050(char* base, int idx) {
    return *(int*)(base + (idx << 2) + 0xC);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394060);
#ifdef SKIP_ASM
extern "C" void func_00394060(char* base, int value, int idx) {
    *(int*)(base + (idx << 2) + 0x2C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394070);
#ifdef SKIP_ASM
extern "C" int func_00394070(char* base, int idx) {
    return *(int*)(base + (idx << 2) + 0x2C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394080);
#ifdef SKIP_ASM
extern "C" void func_00394080(char* base, int value, int idx) {
    *(int*)(base + (idx << 2) + 0x4C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394090);
#ifdef SKIP_ASM
extern "C" int func_00394090(char* base, int idx) {
    return *(int*)(base + (idx << 2) + 0x4C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003940A0);
#ifdef SKIP_ASM
extern "C" void func_003940A0(char* base, int value, int idx) {
    *(int*)(base + (idx << 2) + 0x6C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003940B0);
#ifdef SKIP_ASM
extern "C" int func_003940B0(char* base, int idx) {
    return *(int*)(base + (idx << 2) + 0x6C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003940C0);
#ifdef SKIP_ASM
extern "C" void func_003940C0(char* base, int value, int idx) {
    *(int*)(base + (idx << 2) + 0x8C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003940D0);
#ifdef SKIP_ASM
extern "C" int func_003940D0(char* base, int idx) {
    return *(int*)(base + (idx << 2) + 0x8C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003940E0);
#ifdef SKIP_ASM
extern "C" void func_003940E0(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0xAC) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003940F0);
#ifdef SKIP_ASM
extern "C" float func_003940F0(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0xAC);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394100);
#ifdef SKIP_ASM
extern "C" void func_00394100(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0xCC) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394110);
#ifdef SKIP_ASM
extern "C" float func_00394110(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0xCC);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394120);
#ifdef SKIP_ASM
extern "C" void func_00394120(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0xEC) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394130);
#ifdef SKIP_ASM
extern "C" float func_00394130(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0xEC);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394140);
#ifdef SKIP_ASM
extern "C" void func_00394140(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x10C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394150);
#ifdef SKIP_ASM
extern "C" float func_00394150(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x10C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394160);
#ifdef SKIP_ASM
extern "C" void func_00394160(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x12C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394170);
#ifdef SKIP_ASM
extern "C" float func_00394170(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x12C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394180);
#ifdef SKIP_ASM
extern "C" void func_00394180(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x14C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394190);
#ifdef SKIP_ASM
extern "C" float func_00394190(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x14C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003941A0);
#ifdef SKIP_ASM
extern "C" void func_003941A0(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x16C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003941B0);
#ifdef SKIP_ASM
extern "C" float func_003941B0(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x16C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003941C0);
#ifdef SKIP_ASM
extern "C" void func_003941C0(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x18C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003941D0);
#ifdef SKIP_ASM
extern "C" float func_003941D0(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x18C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003941E0);
#ifdef SKIP_ASM
extern "C" void func_003941E0(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x1AC) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003941F0);
#ifdef SKIP_ASM
extern "C" float func_003941F0(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x1AC);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394200);
#ifdef SKIP_ASM
extern "C" void func_00394200(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x1CC) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394210);
#ifdef SKIP_ASM
extern "C" float func_00394210(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x1CC);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394220);
#ifdef SKIP_ASM
extern "C" void func_00394220(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x1EC) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394230);
#ifdef SKIP_ASM
extern "C" float func_00394230(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x1EC);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394240);
#ifdef SKIP_ASM
extern "C" void func_00394240(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x20C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394250);
#ifdef SKIP_ASM
extern "C" float func_00394250(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x20C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394260);
#ifdef SKIP_ASM
extern "C" void func_00394260(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x22C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394270);
#ifdef SKIP_ASM
extern "C" float func_00394270(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x22C);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394280);
#ifdef SKIP_ASM
extern "C" void func_00394280(char* base, int idx, float value) {
    *(float*)(base + (idx << 2) + 0x24C) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394290);
#ifdef SKIP_ASM
extern "C" float func_00394290(char* base, int idx) {
    return *(float*)(base + (idx << 2) + 0x24C);
}
#endif

//100%
INCLUDE_ASM("render/font", func_003942A0);
#ifdef SKIP_ASM
extern "C" void* func_003942A0(void* self)
{
    *(float*)self = 1.0f;
    *(float*)((char*)self + 0x4) = 1.0f;
    *(int*)((char*)self + 0x8) = 0;
    *(float*)((char*)self + 0xc) = 1.0f;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003942C0__FPv);
#ifdef SKIP_ASM
void func_003942C0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003942C8__FPv);
#ifdef SKIP_ASM
void func_003942C8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003942D0__FPv);
#ifdef SKIP_ASM
void func_003942D0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003942D8__FPv);
#ifdef SKIP_ASM
void* func_003942D8(void* self)
{
    return (char*)self + 0xED8;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003942E0__FPv);
#ifdef SKIP_ASM
void func_003942E0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003942E8);
#ifdef SKIP_ASM
struct sFontRS20_42E8 {
    int w[5];
};

extern sFontRS20_42E8 D_00501420;

extern "C" void func_003942E8(void* self)
{
    *(*(sFontRS20_42E8**)((char*)self + 0xE84)) = D_00501420;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394328);
#ifdef SKIP_ASM
struct sFontRS20_4328 {
    int w[5];
};

extern "C" void func_00394328(void* self, sFontRS20_4328* src)
{
    *(*(sFontRS20_4328**)((char*)self + 0xE84)) = *src;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394358);
#ifdef SKIP_ASM
extern "C" int func_00394358(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xE84)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394360);
#ifdef SKIP_ASM
extern "C" int func_00394360(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xE84)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394368);
#ifdef SKIP_ASM
extern "C" void func_00394368(void *arg0, int arg1) {
    int *p = *(int **)((char*)arg0 + 0xE84);
    int m = (arg1 << 22) & 0x400000;
    p[1] = (p[1] & ~0x400000) | m;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394398);
#ifdef SKIP_ASM
extern "C" void func_00394398(void *arg0, int arg1) {
    void *temp_6;

    temp_6 = (*(void **)((char*)(arg0) + (0xE84)));
    (*(int *)((char*)(temp_6) + (8))) = (int) (((*(int *)((char*)(temp_6) + (8))) & ~0x3E0) | ((arg1 << 5) & 0x3E0));
}
#endif
//100%
INCLUDE_ASM("render/font", func_003943C0);
#ifdef SKIP_ASM
struct sFontV4 {
    float x, y, z, w;
};

extern "C" void func_003943C0(void* self, sFontV4 v, int idx)
{
    // PORT: pointer arithmetic via int (index-first addu)
    *(sFontV4*)((char*)((idx << 4) + (int)self) + 0xF04) = v;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394418);
#ifdef SKIP_ASM
extern "C" sFontV4 func_00394418(void* self, sFontV4 v, int idx)
{
    // PORT: pointer arithmetic via int (index-first addu)
    return *(sFontV4*)((char*)((idx << 4) + (int)self) + 0xF04);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394470);
#ifdef SKIP_ASM
extern "C" void func_00394470(void *arg0, int arg1, int arg2) {
    int temp_2;
    int temp_4;
    void *temp_7;

    temp_7 = (*(void **)((char*)(arg0) + (0xE84)));
    temp_2 = (arg2 * 5) + 2;
    temp_4 = 0x1F << temp_2;
    (*(int *)((char*)(temp_7) + (4))) = (int) (((*(int *)((char*)(temp_7) + (4))) & ~temp_4) | ((arg1 << temp_2) & temp_4));
}
#endif
//100%
INCLUDE_ASM("render/font", func_003944A8);
#ifdef SKIP_ASM
extern "C" void func_003944A8(void *arg0, int arg1, int arg2) {
    void *temp_3;
    void *temp_8;

    temp_8 = (*(void **)((char*)(arg0) + (0xE84)));
    (*(int *)((char*)(temp_8) + (4))) = (int) (((*(int *)((char*)(temp_8) + (4))) & ~3) | (arg1 & 3));
    temp_3 = (*(void **)((char*)(arg0) + (0xE84)));
    (*(int *)((char*)(temp_3) + (8))) = (int) (((*(int *)((char*)(temp_3) + (8))) & 0xE00003FF) | ((arg2 << 0xA) & 0x1FFFFC00));
}
#endif
//100%
INCLUDE_ASM("render/font", func_003944F8);
#ifdef SKIP_ASM
extern "C" void func_003944F8(void *arg0, int arg1, int arg2) {
    int *temp_7;
    int temp_4;
    int temp_6;

    temp_7 = (*(int **)((char*)(arg0) + (0xE84)));
    temp_6 = (arg2 * 2) + 2;
    temp_4 = 3 << temp_6;
    *temp_7 = (*temp_7 & ~temp_4) | ((arg1 << temp_6) & temp_4);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394530);
#ifdef SKIP_ASM
extern "C" void func_00394530(void *arg0, int arg1) {
    int *p = *(int **)((char*)arg0 + 0xE84);
    int m = arg1 & 0x3FFFFFFF;
    p[3] = (p[3] & 0xC0000000) | m;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394558);
#ifdef SKIP_ASM
extern "C" unsigned int func_00394558(void *arg0) {
    return (unsigned int) ((*(int *)((char*)((*(void **)((char*)(arg0) + (0xE84)))) + (8))) & 0x3E0) >> 5;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394570);
#ifdef SKIP_ASM
extern "C" unsigned int func_00394570(void *arg0) {
    return (unsigned int) ((*(int *)((char*)((*(void **)((char*)(arg0) + (0xE84)))) + (4))) & 0x7C) >> 2;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394588);
#ifdef SKIP_ASM
extern "C" int func_00394588(void *arg0) {
    return (*(int *)((char*)((*(void **)((char*)(arg0) + (0xE84)))) + (4))) & 3;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394598);
#ifdef SKIP_ASM
extern "C" unsigned int func_00394598(void *arg0) {
    return (unsigned int) ((*(int *)((char*)((*(void **)((char*)(arg0) + (0xE84)))) + (8))) & 0x1FFFFC00) >> 0xA;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945B8__FPv);
#ifdef SKIP_ASM
void func_003945B8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945C0__FPv);
#ifdef SKIP_ASM
void func_003945C0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945C8__FPv);
#ifdef SKIP_ASM
void func_003945C8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945D0__FPv);
#ifdef SKIP_ASM
void func_003945D0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945D8__FPv);
#ifdef SKIP_ASM
void func_003945D8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945E0__FPv);
#ifdef SKIP_ASM
void func_003945E0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945E8__FPv);
#ifdef SKIP_ASM
void func_003945E8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003945F0);
#ifdef SKIP_ASM
extern "C" int func_003945F0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xE80)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_003945F8);
#ifdef SKIP_ASM
extern "C" char* func_003945F8(char* base, int idx)
{
    return base + 0x280 + idx * 0xC;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394610__FPv);
#ifdef SKIP_ASM
void func_00394610(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394618__FPv);
#ifdef SKIP_ASM
void func_00394618(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394620__FPv);
#ifdef SKIP_ASM
void func_00394620(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394628__FPv);
#ifdef SKIP_ASM
void func_00394628(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394630__FPv);
#ifdef SKIP_ASM
void func_00394630(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394638__FPv);
#ifdef SKIP_ASM
void func_00394638(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394640__FPv);
#ifdef SKIP_ASM
void func_00394640(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394648__FPv);
#ifdef SKIP_ASM
void func_00394648(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394650__FPv);
#ifdef SKIP_ASM
void func_00394650(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394658__FPv);
#ifdef SKIP_ASM
void func_00394658(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394660__FPv);
#ifdef SKIP_ASM
void func_00394660(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394668__FPv);
#ifdef SKIP_ASM
void func_00394668(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394670__FPv);
#ifdef SKIP_ASM
void func_00394670(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394678__FPv);
#ifdef SKIP_ASM
int func_00394678(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394680__FPv);
#ifdef SKIP_ASM
void func_00394680(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394688__FPv);
#ifdef SKIP_ASM
void func_00394688(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394690);
#ifdef SKIP_ASM
extern "C" int func_00394690(void) {
    return (*(int*)&D_004A5B80);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394698);
#ifdef SKIP_ASM
extern "C" void func_00394698(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10A8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003946A0);
#ifdef SKIP_ASM
extern "C" int func_003946A0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10A8)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_003946A8);
#ifdef SKIP_ASM
extern "C" void func_003946A8(char* base, int idx, int value) {
    *(int*)(base + (idx << 2) + 0x10B0) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003946B8);
#ifdef SKIP_ASM
extern "C" int func_003946B8(char* base, int idx) {
    return *(int*)(base + (idx << 2) + 0x10B0);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003946C8);
#ifdef SKIP_ASM
extern "C" void func_003946C8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10AC))) = arg1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003946D0);
#ifdef SKIP_ASM
extern "C" int func_003946D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10AC)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_003946D8);
#ifdef SKIP_ASM
extern "C" void func_003946D8(void *arg0) {
    (*(int *)((char*)(arg0) + (0xF44))) = 1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003946E8__FPv);
#ifdef SKIP_ASM
void func_003946E8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003946F0);
#ifdef SKIP_ASM
extern "C" void func_003946F0(char* self, int a, int b, int c)
{
    int sa = (a << 23) & 0x01800000;
    *(int*)(*(char**)(self + 0xE84) + 4) = (*(int*)(*(char**)(self + 0xE84) + 4) & ~0x01800000) | sa;
    int sb = (b << 20) & 0x00300000;
    *(int*)(*(char**)(self + 0xE84) + 4) = (*(int*)(*(char**)(self + 0xE84) + 4) & ~0x00300000) | sb;
    int sc = (c << 12) & 0x000FF000;
    *(int*)(*(char**)(self + 0xE84) + 4) = (*(int*)(*(char**)(self + 0xE84) + 4) & ~0x000FF000) | sc;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394770);
#ifdef SKIP_ASM
extern "C" void func_00394770(char* self, short value, int idx) {
    *(short*)(*(char**)(self + 0xE84) + (idx << 1) + 0x10) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394788);
#ifdef SKIP_ASM
struct sFontRS20_4788 {
    int w[5];
};

extern "C" void func_00394788(void* self)
{
    sFontRS20_4788* top = *(sFontRS20_4788**)((char*)self + 0xE84);
    top[1] = top[0];
    *(sFontRS20_4788**)((char*)self + 0xE84) = *(sFontRS20_4788**)((char*)self + 0xE84) + 1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003947C8);
#ifdef SKIP_ASM
extern "C" void func_003947C8(void *arg0) {
    (*(int *)((char*)(arg0) + (0xE84))) = (int) ((*(int *)((char*)(arg0) + (0xE84))) - 0x14);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003947D8);
#ifdef SKIP_ASM
typedef char* (*sFontGetFn_47D8)(char*);

static inline short* sFontRS_shorts_47D8(char* st)
{
    return (short*)(st + 0x10);
}

extern "C" int func_003947D8(char* self)
{
    int i;
    unsigned int j;
    for (i = 0; i < 4; i++) {
        char* obj = *(char**)(self + 0x10D8);
        int* a = (int*)(*(char**)(self + 0xE84) + (i << 2));
        char* cmp = ((sFontGetFn_47D8) * (void**)(obj + 0x204))(self + *(short*)(obj + 0x200));
        if (*a != *(int*)(cmp + (i << 2))) return 1;
    }
    for (j = 0; j < 2; j++) {
        char* obj = *(char**)(self + 0x10D8);
        short* a = sFontRS_shorts_47D8(*(char**)(self + 0xE84)) + j;
        char* cmp = ((sFontGetFn_47D8) * (void**)(obj + 0x204))(self + *(short*)(obj + 0x200));
        if (*a != *(short*)(cmp + (j << 1) + 0x10)) return 1;
    }
    return 0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003948B0);
#ifdef SKIP_ASM
extern "C" void func_003948B0(char* base, int idx, int value) {
    *(int*)(base + (idx << 2) + 0xF50) = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003948C0);
#ifdef SKIP_ASM
extern "C" int func_003948C0(char* base, int idx) {
    return *(int*)(base + (idx << 2) + 0xF50);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003948D0);
#ifdef SKIP_ASM
extern "C" float func_003948D0(int mode, float t)
{
    switch (mode) {
    case 1:
        if (t < 100.0f) return 1.0f;
        return 100.0f / t;
    case 2:
        if (t < 100.0f) return 1.0f;
        return 10000.0f / (t * t);
    case 3:
        if (t < 100.0f) return 1.0f;
        return 1000000.0f / (t * t * t);
    }
    return 1.0f;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003949A0);
#ifdef SKIP_ASM
extern "C" float func_003949A0(int mode, float x)
{
    float t = x * 100.0f;
    if (t < 1.0f) {
        switch (mode) {
        case 1: return t;
        case 2: return t * t;
        case 3: return t * t * t;
        }
    }
    return 1.0f;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394A20);
#ifdef SKIP_ASM
extern "C" float func_00394A20(int n, float x) {
    float r;

    switch (n) {
    case 0:
        return 1.0f;
    case 1:
        return x;
    case 2:
        return x * x;
    case 3:
        return x * x * x;
    case 4:
        return x * x * x * x;
    default:
        r = 0.0f;
        if (x != 0.0f) {
            if (n < 0) {
                n = -n;
                x = 1.0f / x;
            }
            r = 1.0f;
            while (n != 0) {
                if (n & 1) {
                    r *= x;
                }
                n >>= 1;
                x *= x;
            }
        }
        return r;
    }
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394AD8);
#ifdef SKIP_ASM
extern "C" float func_00394AD8(float a, float b)
{
    float r;
    if (a < 5000.0f) return 1.0f;
    if (!(b <= 3750.0f)) r = 1.0f - (b - 3750.0f) * 0.0008f;
    else r = 1.0f;
    return r;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B38);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00493938[];

extern "C" void func_00394B38(int* self, int flags)
{
    *(void**)((char*)self + 0x4) = D_00493938;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B68__FPv);
#ifdef SKIP_ASM
void func_00394B68(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B70);
#ifdef SKIP_ASM
extern int D_004A4248;

extern "C" int func_00394B70(void) {
    return D_004A4248;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B78__FPv);
#ifdef SKIP_ASM
void func_00394B78(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B80__FPv);
#ifdef SKIP_ASM
void func_00394B80(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B88__FPvf);
#ifdef SKIP_ASM
void func_00394B88(void* self, float val)
{
    *(float*)((char*)self + 0x0) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B90__FPv);
#ifdef SKIP_ASM
float func_00394B90(void* self)
{
    return *(float*)((char*)self + 0x0);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394B98);
#ifdef SKIP_ASM
class cFontVirt {
public:
    int field_0x0;
    // vptr lands at 0x4 (g++ 2.95 places it after the class's own data);
    // slot N lives at vtable offset N*8 (delta at +0, function at +4)
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
    virtual void v22(int, int, int, int, int);
};

extern "C" void func_00394B98(cFontVirt* self, int a, int b, int c, int d, int e)
{
    self->v22(a, b, c, d, e);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BC0__FPvf);
#ifdef SKIP_ASM
void func_00394BC0(void* self, float val)
{
    *(float*)((char*)self + 0x33C) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BC8__FPvf);
#ifdef SKIP_ASM
void func_00394BC8(void* self, float val)
{
    *(float*)((char*)self + 0x340) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BD0__FPv);
#ifdef SKIP_ASM
float func_00394BD0(void* self)
{
    return *(float*)((char*)self + 0x33C);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BD8__FPv);
#ifdef SKIP_ASM
float func_00394BD8(void* self)
{
    return *(float*)((char*)self + 0x340);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BE0__FPvi);
#ifdef SKIP_ASM
void func_00394BE0(void* self, int val)
{
    *(int*)((char*)self + 0x354) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BE8__FPvi);
#ifdef SKIP_ASM
void func_00394BE8(void* self, int val)
{
    *(int*)((char*)self + 0x344) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BF0__FPvi);
#ifdef SKIP_ASM
void func_00394BF0(void* self, int val)
{
    *(int*)((char*)self + 0x34C) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394BF8__FPvi);
#ifdef SKIP_ASM
void func_00394BF8(void* self, int val)
{
    *(int*)((char*)self + 0x350) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C00__FPv);
#ifdef SKIP_ASM
int func_00394C00(void* self)
{
    return *(int*)((char*)self + 0x344);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C08__FPv);
#ifdef SKIP_ASM
int func_00394C08(void* self)
{
    return *(int*)((char*)self + 0x34C);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C10__FPv);
#ifdef SKIP_ASM
int func_00394C10(void* self)
{
    return *(int*)((char*)self + 0x350);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C18);
#ifdef SKIP_ASM
extern "C" int func_00394C18(char* base, int shift, int idx) {
    return *(int*)(base + (idx << 2) + 0x44C) + (shift << 8);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394C30);
#ifdef SKIP_ASM
extern "C" int func_00394C30(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1A0)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394C38);
#ifdef SKIP_ASM
extern "C" int func_00394C38(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x320)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00394C40);
#ifdef SKIP_ASM
extern int D_004A5B8C;

extern "C" int func_00394C40(void) {
    return D_004A5B8C;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C48__FPv);
#ifdef SKIP_ASM
void func_00394C48(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C50__FPv);
#ifdef SKIP_ASM
void func_00394C50(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C58__FPv);
#ifdef SKIP_ASM
void func_00394C58(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C60__FPv);
#ifdef SKIP_ASM
void func_00394C60(void* self)
{
}
#endif

extern "C" void* func_0038AE28(void* self);

//100%
INCLUDE_ASM("render/font", func_00394C68__FPv);
#ifdef SKIP_ASM
void* func_00394C68(void* self)
{
    return func_0038AE28(self);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C88__FPvi);
#ifdef SKIP_ASM
void* func_00394C88(void* self, int a1)
{
    return ((char*)*(void**)((char*)self + 0x4) + a1 * 4);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394C98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_00491FA0[];

extern "C" void func_00394C98(void* self, int n)
{
    *(int*)((char*)self + 0x8) = n;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = n + 0x32;
    *(void**)((char*)self + 0x4) = operator_new_tag((n + 0x32) * 4, D_00491FA0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394CE8);
#ifdef SKIP_ASM
void cMemMan_free(void*);

extern "C" void func_00394CE8(void* self)
{
    void* p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        cMemMan_free(p);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394D10__FPv);
#ifdef SKIP_ASM
void func_00394D10(void* self)
{
    *(int*)((char*)self + 0xC) = 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394D18);
#ifdef SKIP_ASM
extern "C" char* func_00394D18(void* self)
{
    return *(char**)((char*)self + 0x8) + (*(int*)((char*)self + 0xC))++;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394D30__FPv);
#ifdef SKIP_ASM
void func_00394D30(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394D38__FPv);
#ifdef SKIP_ASM
void func_00394D38(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394D40__FPv);
#ifdef SKIP_ASM
void func_00394D40(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394D48__FPv);
#ifdef SKIP_ASM
void func_00394D48(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394D50);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);

struct sFontTexKey {
    char block[0x10];       // 0x0
    short ids[2];           // 0x10
    sFontTexKey()
    {
        for (unsigned int i = 0; i < 2; i++) {
            ids[i] = -1;
        }
        func_00416210(block, 0, 0x10);
    }
};

struct sFontGlyph80 {
    sFontTexKey key;        // 0x0
    char pad_0x14[0x6C];
};

struct sFontGlyph18 {
    sFontTexKey key;        // 0x0
    int field_0x14;
};

struct sFontEmpty24 {
    int a;
    sFontEmpty24() {}
};

struct sFontEmptyC {
    int a;
    sFontEmptyC() {}
};

struct sFontCache {
    char pad_0x0[0x80];
    sFontGlyph80 glyphs[0xA28];     // 0x80
    int field_0x51480;
    sFontGlyph18 small[0x400];      // 0x51484
    sFontEmpty24 e1[0x800];         // 0x57484
    char pad_0x59484[0x69CA8 - 0x59484];
    sFontTexKey key;                // 0x69CA8
    sFontEmptyC e2[0xC];            // 0x69CBC
    sFontCache() {}
};

inline void* operator new(unsigned int, void* p) { return p; }

extern "C" void* func_00394D50(void* self)
{
    new (self) sFontCache;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00394ED0);
#ifdef SKIP_ASM
struct sGlyphKey {
    int k[4];
    int v;
};

struct sGlyphEntry {
    sGlyphKey key;          // 0x00
    sGlyphEntry* next;      // 0x14
};

struct sGlyphCache {
    char pad_0x00[0x51480];
    int count;                  // 0x51480
    sGlyphEntry entries[3755];  // 0x51484
    char pad_0x6748C[0x14];
    sGlyphEntry* buckets[256];  // 0x674A0
};

static inline int glyphKeyEq(const int* a, const int* b)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

extern "C" sGlyphEntry* func_00394ED0(sGlyphCache* self, sGlyphKey* key, unsigned char hash)
{
    sGlyphEntry** pp = &self->buckets[hash];
    while (*pp != 0) {
        sGlyphEntry* e = *pp;
        if (glyphKeyEq(e->key.k, key->k)) {
            if (e == self->buckets[hash]) {
                return e;
            }
            *pp = e->next;
            e->next = self->buckets[hash];
            self->buckets[hash] = e;
            return e;
        }
        pp = &e->next;
    }
    sGlyphEntry* e = &self->entries[self->count++];
    e->key = *key;
    e->next = self->buckets[hash];
    self->buckets[hash] = e;
    return e;
}
#endif

INCLUDE_ASM("render/font", func_00395000);

//100%
INCLUDE_ASM("render/font", func_003950C0);
#ifdef SKIP_ASM
struct sVec50C0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat50C0 {
    float m[16];
    // PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
    sMat50C0& operator=(const sMat50C0& o)
    {
        __asm__ __volatile__(
            ".set noreorder\n"
            "lqc2      $vf1, 0x0(%1)\n"
            "lqc2      $vf2, 0x10(%1)\n"
            "lqc2      $vf3, 0x20(%1)\n"
            "lqc2      $vf4, 0x30(%1)\n"
            "sqc2      $vf1, 0x0(%0)\n"
            "sqc2      $vf2, 0x10(%0)\n"
            "sqc2      $vf3, 0x20(%0)\n"
            "sqc2      $vf4, 0x30(%0)\n"
            ".set reorder\n"
            :
            : "r"(this), "r"(&o)
            : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct sPair50C0 {
    int a, b;
};

struct sFontState50C0 {
    float f00, f04, f08, f0C, f10, f14, f18, f1C;
    int i20;
    float f24, f28, f2C;
    sVec50C0 v30, v40, v50;
    sMat50C0 m60, mA0, mE0, m120;
    sVec50C0 v160, v170;
    sMat50C0 m180, m1C0;
    sVec50C0 v200, v210;
    sPair50C0 p220;
    int i228;
};

// Compiler-generated member-wise assignment of the font render state.
extern "C" sFontState50C0* func_003950C0(sFontState50C0* self, const sFontState50C0* o)
{
    *self = *o;
    return self;
}
#endif

extern "C" void* func_003695D8(void* self);

//100%
INCLUDE_ASM("render/font", func_00395268__FPv);
#ifdef SKIP_ASM
void* func_00395268(void* self)
{
    return func_003695D8(self);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395288);
#ifdef SKIP_ASM
extern "C" void* func_003691F8(void* self);
extern void* D_00493260[];

inline void* operator new[](unsigned int, void* p) { return p; }

struct sRenderSlot5288 {
    float v[4];
    sRenderSlot5288() {}
};

extern "C" void* func_00395288(void* self)
{
    func_003691F8(self);
    *(void***)((char*)self + 0x10D8) = D_00493260;
    new ((char*)self + 0x10E0) sRenderSlot5288[12];
    new ((char*)self + 0x11A0) sRenderSlot5288[8];
    new ((char*)self + 0x1220) sRenderSlot5288[2];
    new ((char*)self + 0x1240) sRenderSlot5288[2];
    new ((char*)self + 0x1260) sRenderSlot5288[4];
    return self;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395318__FPv);
#ifdef SKIP_ASM
int func_00395318(void* self)
{
    return *(int*)((char*)self + 0x59C4);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395320__FPv);
#ifdef SKIP_ASM
int func_00395320(void* self)
{
    return *(int*)((char*)self + 0x5A4C);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395328__FPv);
#ifdef SKIP_ASM
int func_00395328(void* self)
{
    return *(int*)((char*)self + 0x59C8);
}
#endif

// 0xa4-byte elements reached through a pointer at self+0x59cc, indexed by
// the counter at self+0x59c8
struct sFontEntry {
    char pad_0x00[0x88];
    int field_0x88;
    int field_0x8c;
    char pad_0x90[0x14];
};

//100%
INCLUDE_ASM("render/font", func_00395330);
#ifdef SKIP_ASM
extern "C" int func_00395330(void* self)
{
    int i = *(int*)((char*)self + 0x59c8);
    sFontEntry* p = *(sFontEntry**)((char*)self + 0x59cc);
    return p[i].field_0x88;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395350);
#ifdef SKIP_ASM
extern "C" int func_00395350(void* self)
{
    int i = *(int*)((char*)self + 0x59c8);
    sFontEntry* p = *(sFontEntry**)((char*)self + 0x59cc);
    return p[i].field_0x8c;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395370);
#ifdef SKIP_ASM
struct sFontVEntry23 {
    short delta;
    short index;
    void (*fn)(void*, int, float, float, float, float);
};

extern "C" void func_00395370(void* self, float* v, int a2)
{
    sFontVEntry23* vt = *(sFontVEntry23**)((char*)self + 0x10D8);
    vt[23].fn((char*)self + vt[23].delta, a2, v[0], v[1], v[2], v[3]);
}
#endif

//100%
INCLUDE_ASM("render/font", func_003953B0__FPv);
#ifdef SKIP_ASM
void* func_003953B0(void* self)
{
    return (char*)self + 0x6B94;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003953B8);
#ifdef SKIP_ASM
extern "C" void func_003956B0(void* self);

// Fetch the current (combined) matrix into out and return out.
// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
extern "C" void* func_003953B8(void* out, void* self)
{
    func_003956B0(self);
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(out), "r"((char*)self + 0x58A0)
        : "memory");
    return out;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395418);
#ifdef SKIP_ASM
extern "C" int func_00395418(int arg0) {
    return arg0 + 0x5800;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395420__FPv);
#ifdef SKIP_ASM
void func_00395420(void* self)
{
    *(int*)((char*)self + 0x13EC) = 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395428);
#ifdef SKIP_ASM
extern "C" int func_00395428(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x13EC)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395430);
#ifdef SKIP_ASM
extern "C" char* func_00395430(char* base, int idx)
{
    return base + 0x13F0 + idx * 0xA0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395448);
#ifdef SKIP_ASM
extern "C" void func_00395448(void *arg0, int arg1) {
    int *temp_6;

    temp_6 = (*(int **)((char*)(arg0) + (0xE84)));
    *temp_6 = (*temp_6 & ~0x3C0) | ((arg1 << 6) & 0x3C0);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395470);
#ifdef SKIP_ASM
extern "C" void func_00395470(void *arg0, int arg1) {
    int *temp_6;

    temp_6 = (*(int **)((char*)(arg0) + (0xE84)));
    *temp_6 = (*temp_6 & ~0xC00) | ((arg1 << 0xA) & 0xC00);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395498);
#ifdef SKIP_ASM
extern "C" void func_00395498(void *arg0, int arg1, int arg2) {
    int *temp_7;
    int temp_3;
    int temp_6;

    temp_7 = (*(int **)((char*)(arg0) + (0xE84)));
    temp_6 = (arg2 * 8) + 0xC;
    temp_3 = 0xFF << temp_6;
    *temp_7 = (*temp_7 & ~temp_3) | (((arg1 & 0xFF) << temp_6) & temp_3);
}
#endif

//100%
INCLUDE_ASM("render/font", func_003954D0);
#ifdef SKIP_ASM
struct sFontBlockA0 {
    float f[40];
} __attribute__((aligned(16)));

extern "C" void func_003954D0(void* self, sFontBlockA0* src)
{
    *(sFontBlockA0*)((char*)self + 0x6BB0) = *src;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395500__FPv);
#ifdef SKIP_ASM
void* func_00395500(void* self)
{
    return (char*)self + 0x6BB0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395508__FPv);
#ifdef SKIP_ASM
void func_00395508(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395510__FPv);
#ifdef SKIP_ASM
int func_00395510(void* self)
{
    return *(int*)((char*)self + 0x5A74);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395518);
#ifdef SKIP_ASM
extern "C" int func_00395518(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A84)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395520);
#ifdef SKIP_ASM
extern "C" int func_00395520(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A80)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395528);
#ifdef SKIP_ASM
extern "C" int func_00395528(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A3C)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395530);
#ifdef SKIP_ASM
extern "C" int func_00395530(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A40)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395538);
#ifdef SKIP_ASM
extern "C" int func_00395538(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18F4)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395540);
#ifdef SKIP_ASM
extern "C" void func_00395540(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x5AB8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395548);
#ifdef SKIP_ASM
extern "C" int func_00395548(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A88)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395550);
#ifdef SKIP_ASM
extern "C" int func_00395550(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A5C)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395558);
#ifdef SKIP_ASM
extern "C" int func_00395558(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A50)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395560);
#ifdef SKIP_ASM
extern "C" int func_00395560(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A3C)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395568);
#ifdef SKIP_ASM
extern "C" void func_00395568(void *arg0) {
    (*(int *)((char*)(arg0) + (0x59E8))) = 1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395578);
#ifdef SKIP_ASM
extern "C" void func_00395578(void *arg0) {
    (*(int *)((char*)(arg0) + (0x59E8))) = 0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395580);
#ifdef SKIP_ASM
// PORT: g++ `<?` (min) operator.
static inline float clamp_5580(float x, float hi)
{
    return x >= 0.0f ? (x <? hi) : 0.0f;
}

extern "C" void func_00395580(void* self, float x)
{
    *(float*)((char*)self + 0x59FC) = clamp_5580(x, 2.0f);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003955A8);
#ifdef SKIP_ASM
extern "C" float func_003955A8(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x59FC)));
}
#endif

INCLUDE_ASM("render/font", func_003955B0);
//100%
INCLUDE_ASM("render/font", func_00395658);
#ifdef SKIP_ASM
extern "C" int func_00395658(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18F0)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395660);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE); GS CSR hardware register.
extern "C" int func_00395660(void)
{
    return (int)((*(volatile unsigned long*)0x12001000 >> 16) & 0xFF);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00395688);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE); GS CSR hardware register.
extern "C" int func_00395688(void)
{
    return (int)((*(volatile unsigned long*)0x12001000 >> 24) & 0xFF);
}
#endif

//100%
INCLUDE_ASM("render/font", func_003956B0);
#ifdef SKIP_ASM
extern "C" void func_0037D968(void* self);

extern "C" void func_003956B0(void* self)
{
    if (*(int*)((char*)self + 0x6B90) == 0) {
        func_0037D968(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_003956D8);
#ifdef SKIP_ASM
extern "C" int func_003956D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x59C0)));
}
#endif

//100%
INCLUDE_ASM("render/font", func_003956E0__FPvi);
#ifdef SKIP_ASM
void func_003956E0(void* self, int val)
{
    *(int*)((char*)self + 0x6D14) = val;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003956E8);
#ifdef SKIP_ASM
// Matrix stack push: duplicate the top 4x4 matrix into the next slot, then advance.
// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
extern "C" void func_003956E8(void* self)
{
    char* top = *(char**)((char*)self + 0x13e4);
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(top + 0x40), "r"(top)
        : "memory");
    *(char**)((char*)self + 0x13e4) += 0x40;
    *(int*)((char*)self + 0x13e0) += 1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395730__FPv);
#ifdef SKIP_ASM
void func_00395730(void* self)
{
    *(int*)((char*)self + 0x6b90) = 0;
    *(char**)((char*)self + 0x13e4) -= 0x40;
    *(int*)((char*)self + 0x13e0) -= 1;
}
#endif

INCLUDE_ASM("render/font", func_00395750);

//100%
INCLUDE_ASM("render/font", func_00395C38);
#ifdef SKIP_ASM
// Load matrix m into the top of the matrix stack and clear the cached flag at 0x6b90.
// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
extern "C" void func_00395C38(void* self, void* m)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(*(char**)((char*)self + 0x13e4)), "r"(m)
        : "memory");
    *(int*)((char*)self + 0x6b90) = 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395C68__FPv);
#ifdef SKIP_ASM
int func_00395C68(void* self)
{
    return *(int*)((char*)self + 0x13E4);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395C70);
#ifdef SKIP_ASM
// Multiply the top of the matrix stack by m in place (top = top * m) and clear
// the cached flag at 0x6b90.
// PORT: PS2-only VU0 inline asm (4x4 matrix multiply); the PC port needs a plain matrix multiply.
extern "C" void func_00395C70(void* self, void* m)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(*(char**)((char*)self + 0x13e4)), "r"(m)
        : "memory");
    *(int*)((char*)self + 0x6b90) = 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395CF0);
#ifdef SKIP_ASM
extern char D_004FF1A0[];

// Load the matrix D_004FF1A0 (likely identity) into the top of the matrix stack
// and clear the cached flag at 0x6b90.
// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
extern "C" void func_00395CF0(void* self)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(*(char**)((char*)self + 0x13e4)), "r"(D_004FF1A0)
        : "memory");
    *(int*)((char*)self + 0x6b90) = 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395D28);
#ifdef SKIP_ASM
// Translate the top matrix of the stack: row 3 = top * v (v is a 4-vector),
// then clear the cached flag at 0x6b90.
// PORT: PS2-only VU0 inline asm (vmula/vmadd matrix-vector product); the PC port
// needs a C fallback.
extern "C" void func_00395D28(void* self, void* v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, 0x0(%1)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(*(char**)((char*)self + 0x13e4)), "r"(v)
        : "memory");
    *(int*)((char*)self + 0x6b90) = 0;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395D60);
#ifdef SKIP_ASM
struct sFontRotMat {
    float m[4][4];
} __attribute__((aligned(16)));

extern "C" void func_0031BE50(float* s, float* c, float angle);

// Multiply the top of the matrix stack by a rotation of `angle` about `axis`.
// PORT: PS2-only VU0 inline asm (4x4 matrix multiply); the PC port needs a plain matrix multiply.
extern "C" void func_00395D60(void* self, float* axis, float angle)
{
    sFontRotMat r;
    float s;
    float c;
    char* top = *(char**)((char*)self + 0x13e4);
    func_0031BE50(&s, &c, angle);
    float t = 1.0f - c;
    float x = axis[0];
    float y = axis[1];
    float z = axis[2];
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    r.m[0][0] = tx * x + c;
    r.m[1][0] = tx * y + sz;
    r.m[2][0] = tx * z - sy;
    r.m[0][1] = ty * x - sz;
    r.m[1][1] = ty * y + c;
    r.m[2][1] = ty * z + sx;
    r.m[0][2] = tz * x + sy;
    r.m[1][2] = tz * y - sx;
    r.m[2][2] = tz * z + c;
    r.m[3][0] = 0.0f;
    r.m[3][1] = 0.0f;
    r.m[3][2] = 0.0f;
    r.m[3][3] = 1.0f;
    r.m[0][3] = 0.0f;
    r.m[1][3] = 0.0f;
    r.m[2][3] = 0.0f;
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(top), "r"(&r)
        : "memory");
    *(int*)((char*)self + 0x6b90) = 0;
}
#endif

extern "C" void* func_003826E0(void* self);

//100%
INCLUDE_ASM("render/font", func_00395ED8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (matrix * vector, clamp, clip flags read back from vi1).
extern "C" int func_00395ED8(void* self, void* vec)
{
    long r;
    if (*(int*)((char*)self + 0x6B90) == 0) {
        func_0037D968(self);
    }
    __asm__ __volatile__(
        "lqc2      $vf5, 0x5920(%1)\n"
        "lqc2      $vf10, 0x0(%2)\n"
        "lqc2      $vf1, 0x0(%3)\n"
        "lqc2      $vf2, 0x10(%3)\n"
        "lqc2      $vf3, 0x20(%3)\n"
        "lqc2      $vf4, 0x30(%3)\n"
        "vmulax.xyzw ACC, $vf1, $vf10x\n"
        "vmadday.xyzw ACC, $vf2, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf10z\n"
        "vmaddw.xyzw $vf11, $vf4, $vf10w\n"
        "vmulw.w    $vf11, $vf11, $vf5w\n"
        "vmaxx.w    $vf11, $vf11, $vf0x\n"
        "vminix.w   $vf11, $vf11, $vf5x\n"
        "vftoi0.xyzw $vf11, $vf11\n"
        "vmtir      $vi1, $vf11w\n"
        "cfc2.ni    %0, $vi1\n"
        : "=&r"(r)
        : "r"(self), "r"(vec), "r"((char*)self + 0x58A0)
        : "memory");
    return (int)r;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395F60__FPv);
#ifdef SKIP_ASM
void* func_00395F60(void* self)
{
    return func_003826E0(self);
}
#endif

extern "C" void* func_00382730(void* self);

//100%
INCLUDE_ASM("render/font", func_00395F80__FPv);
#ifdef SKIP_ASM
void* func_00395F80(void* self)
{
    return func_00382730(self);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395FA0__FPv);
#ifdef SKIP_ASM
void func_00395FA0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00395FA8);
#ifdef SKIP_ASM
extern "C" int func_00395FA8(char* self, char* vec) {
    float x = *(float*)(vec + 0);
    int flags = 0;
    if (x < *(float*)(self + 0x6B70)) {
        flags = 2;
    }
    if (*(float*)(self + 0x6B80) < x) {
        flags |= 1;
    }
    float y = *(float*)(vec + 4);
    if (y < *(float*)(self + 0x6B74)) {
        flags |= 8;
    }
    if (*(float*)(self + 0x6B84) < y) {
        flags |= 4;
    }
    if (*(float*)(vec + 0xC) < 0.0f) {
        return flags ^ 0x2F;
    }
    float z = *(float*)(vec + 8);
    if (*(float*)(self + 0x6B78) < z) {
        flags |= 0x20;
    }
    if (z < *(float*)(self + 0x6B88)) {
        flags |= 0x10;
    }
    return flags;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396058);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE); GS CSR hardware register.
extern "C" int func_00396058(void)
{
    return (int)((*(volatile unsigned long*)0x12001000 >> 13) & 1);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396080);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
#define GS_CSR (*(volatile unsigned long*)0x12001000)
extern "C" int func_00396080(void)
{
    GS_CSR = 8;
    if (!(GS_CSR & 8)) {
        do {
        } while (!(GS_CSR & 8));
    }
    return (int)((GS_CSR >> 13) & 1);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003960E8);
#ifdef SKIP_ASM
extern "C" void func_00382AF0(void* self, int arg1, int arg2);

extern "C" void func_003960E8(void* self, int arg1) {
    func_00382AF0(self, arg1, 1);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396108__FPv);
#ifdef SKIP_ASM
int func_00396108(void* self)
{
    return *(int*)((char*)self + 0x1C8);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396110);
#ifdef SKIP_ASM
extern "C" void func_00396110(void* self, float range)
{
    *(float*)((char*)self + 0x194) = range;
    *(float*)((char*)self + 0x198) = 32767.0f / range;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396128);
#ifdef SKIP_ASM
extern "C" void func_00396128(void* self)
{
    int i;
    for (i = 0; i < 2; i++) {
        ((int*)((char*)self + 0x1f4c))[i] = -1;
    }
    *(int*)((char*)self + 0x1f54) = -1;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396160);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_00396160(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396190);
#ifdef SKIP_ASM
extern "C" void func_00396190(void) {

}
#endif
//100%
INCLUDE_ASM("render/font", func_00396198);
#ifdef SKIP_ASM
extern "C" void func_00396198(void) {

}
#endif
//100%
INCLUDE_ASM("render/font", func_003961A0);
#ifdef SKIP_ASM
extern "C" void func_003961A0(void) {

}
#endif

//100%
INCLUDE_ASM("render/font", func_003961A8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_003961A8(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_003961D8);
#ifdef SKIP_ASM
extern int D_004A44C0;

extern "C" int *func_003961D8(void) {
    return &D_004A44C0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003961E8);
#ifdef SKIP_ASM
extern int D_004A44C4;

extern "C" int *func_003961E8(void) {
    return &D_004A44C4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003961F8);
#ifdef SKIP_ASM
extern int D_004A44C8;

extern "C" int *func_003961F8(void) {
    return &D_004A44C8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396208);
#ifdef SKIP_ASM
extern int D_004A44CC;

extern "C" int *func_00396208(void) {
    return &D_004A44CC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396218);
#ifdef SKIP_ASM
extern int D_004A44D0;

extern "C" int *func_00396218(void) {
    return &D_004A44D0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396228);
#ifdef SKIP_ASM
extern int D_004A44D4;

extern "C" int *func_00396228(void) {
    return &D_004A44D4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396238);
#ifdef SKIP_ASM
extern int D_004A44D8;

extern "C" int *func_00396238(void) {
    return &D_004A44D8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396248);
#ifdef SKIP_ASM
extern int D_004A44DC;

extern "C" int *func_00396248(void) {
    return &D_004A44DC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396258);
#ifdef SKIP_ASM
extern int D_004A44E0;

extern "C" int *func_00396258(void) {
    return &D_004A44E0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396268);
#ifdef SKIP_ASM
extern int D_004A44E4;

extern "C" int *func_00396268(void) {
    return &D_004A44E4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396278);
#ifdef SKIP_ASM
extern int D_004A44E8;

extern "C" int *func_00396278(void) {
    return &D_004A44E8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396288);
#ifdef SKIP_ASM
extern int D_004A44EC;

extern "C" int *func_00396288(void) {
    return &D_004A44EC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396298);
#ifdef SKIP_ASM
extern int D_004A44F0;

extern "C" int *func_00396298(void) {
    return &D_004A44F0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003962A8);
#ifdef SKIP_ASM
extern int D_004A44F4;

extern "C" int *func_003962A8(void) {
    return &D_004A44F4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003962B8);
#ifdef SKIP_ASM
extern int D_004A44F8;

extern "C" int *func_003962B8(void) {
    return &D_004A44F8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003962C8);
#ifdef SKIP_ASM
extern int D_004A44FC;

extern "C" int *func_003962C8(void) {
    return &D_004A44FC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003962D8);
#ifdef SKIP_ASM
extern int D_004A4500;

extern "C" int *func_003962D8(void) {
    return &D_004A4500;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003962E8);
#ifdef SKIP_ASM
extern int D_004A4504;

extern "C" int *func_003962E8(void) {
    return &D_004A4504;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003962F8);
#ifdef SKIP_ASM
extern int D_004A4508;

extern "C" int *func_003962F8(void) {
    return &D_004A4508;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396308);
#ifdef SKIP_ASM
extern int D_004A450C;

extern "C" int *func_00396308(void) {
    return &D_004A450C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396318);
#ifdef SKIP_ASM
extern int D_004A4510;

extern "C" int *func_00396318(void) {
    return &D_004A4510;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396328);
#ifdef SKIP_ASM
extern int D_004A4514;

extern "C" int *func_00396328(void) {
    return &D_004A4514;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396338);
#ifdef SKIP_ASM
extern int D_004A4518;

extern "C" int *func_00396338(void) {
    return &D_004A4518;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396348);
#ifdef SKIP_ASM
extern int D_004A451C;

extern "C" int *func_00396348(void) {
    return &D_004A451C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396358);
#ifdef SKIP_ASM
extern int D_004A4520;

extern "C" int *func_00396358(void) {
    return &D_004A4520;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396368);
#ifdef SKIP_ASM
extern int D_004A4524;

extern "C" int *func_00396368(void) {
    return &D_004A4524;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396378);
#ifdef SKIP_ASM
extern int D_004A4528;

extern "C" int *func_00396378(void) {
    return &D_004A4528;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396388);
#ifdef SKIP_ASM
extern int D_004A452C;

extern "C" int *func_00396388(void) {
    return &D_004A452C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396398);
#ifdef SKIP_ASM
extern int D_004A4530;

extern "C" int *func_00396398(void) {
    return &D_004A4530;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003963A8);
#ifdef SKIP_ASM
extern int D_004A4534;

extern "C" int *func_003963A8(void) {
    return &D_004A4534;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003963B8);
#ifdef SKIP_ASM
extern int D_004A4538;

extern "C" int *func_003963B8(void) {
    return &D_004A4538;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003963C8);
#ifdef SKIP_ASM
extern int D_004A453C;

extern "C" int *func_003963C8(void) {
    return &D_004A453C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003963D8);
#ifdef SKIP_ASM
extern int D_004A4540;

extern "C" int *func_003963D8(void) {
    return &D_004A4540;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003963E8);
#ifdef SKIP_ASM
extern int D_004A4544;

extern "C" int *func_003963E8(void) {
    return &D_004A4544;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003963F8);
#ifdef SKIP_ASM
extern int D_004A4548;

extern "C" int *func_003963F8(void) {
    return &D_004A4548;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396408);
#ifdef SKIP_ASM
extern int D_004A454C;

extern "C" int *func_00396408(void) {
    return &D_004A454C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396418);
#ifdef SKIP_ASM
extern int D_004A4550;

extern "C" int *func_00396418(void) {
    return &D_004A4550;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396428);
#ifdef SKIP_ASM
extern int D_004A4554;

extern "C" int *func_00396428(void) {
    return &D_004A4554;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396438);
#ifdef SKIP_ASM
extern int D_004A4558;

extern "C" int *func_00396438(void) {
    return &D_004A4558;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396448);
#ifdef SKIP_ASM
extern int D_004A455C;

extern "C" int *func_00396448(void) {
    return &D_004A455C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396458);
#ifdef SKIP_ASM
extern int D_004A4560;

extern "C" int *func_00396458(void) {
    return &D_004A4560;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396468);
#ifdef SKIP_ASM
extern int D_004A4564;

extern "C" int *func_00396468(void) {
    return &D_004A4564;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396478);
#ifdef SKIP_ASM
extern int D_004A4568;

extern "C" int *func_00396478(void) {
    return &D_004A4568;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396488);
#ifdef SKIP_ASM
extern int D_004A456C;

extern "C" int *func_00396488(void) {
    return &D_004A456C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396498);
#ifdef SKIP_ASM
extern int D_004A4570;

extern "C" int *func_00396498(void) {
    return &D_004A4570;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003964A8);
#ifdef SKIP_ASM
extern int D_004A4574;

extern "C" int *func_003964A8(void) {
    return &D_004A4574;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003964B8);
#ifdef SKIP_ASM
extern int D_004A4578;

extern "C" int *func_003964B8(void) {
    return &D_004A4578;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003964C8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_003964C8(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_003964F8);
#ifdef SKIP_ASM
extern int D_004A4444;

extern "C" int *func_003964F8(void) {
    return &D_004A4444;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396508);
#ifdef SKIP_ASM
extern int D_004A4448;

extern "C" int *func_00396508(void) {
    return &D_004A4448;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396518);
#ifdef SKIP_ASM
extern int D_004A444C;

extern "C" int *func_00396518(void) {
    return &D_004A444C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396528);
#ifdef SKIP_ASM
extern int D_004A4450;

extern "C" int *func_00396528(void) {
    return &D_004A4450;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396538);
#ifdef SKIP_ASM
extern int D_004A4454;

extern "C" int *func_00396538(void) {
    return &D_004A4454;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396548);
#ifdef SKIP_ASM
extern int D_004A4458;

extern "C" int *func_00396548(void) {
    return &D_004A4458;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396558);
#ifdef SKIP_ASM
extern int D_004A445C;

extern "C" int *func_00396558(void) {
    return &D_004A445C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396568);
#ifdef SKIP_ASM
extern int D_004A4460;

extern "C" int *func_00396568(void) {
    return &D_004A4460;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396578);
#ifdef SKIP_ASM
extern int D_004A4464;

extern "C" int *func_00396578(void) {
    return &D_004A4464;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396588);
#ifdef SKIP_ASM
extern int D_004A4468;

extern "C" int *func_00396588(void) {
    return &D_004A4468;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396598);
#ifdef SKIP_ASM
extern int D_004A446C;

extern "C" int *func_00396598(void) {
    return &D_004A446C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965A8);
#ifdef SKIP_ASM
extern int D_004A4470;

extern "C" int *func_003965A8(void) {
    return &D_004A4470;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965B8);
#ifdef SKIP_ASM
extern "C" int func_003965B8(int arg0) {
    return arg0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965C0);
#ifdef SKIP_ASM
extern "C" int func_003965C0(int arg0) {
    return arg0 + 0x160;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965C8);
#ifdef SKIP_ASM
extern "C" int func_003965C8(int arg0) {
    return arg0 + 0xC0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965D0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_003965D0(void *arg0, long long *arg1) {
    (*(long long *)((char*)(arg0) + (0xC0))) = (long long) *arg1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965E0);
#ifdef SKIP_ASM
extern "C" int func_003965E0(int arg0) {
    return arg0 + 0x20;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965E8);
#ifdef SKIP_ASM
extern "C" void func_003965E8(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x58))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965F0);
#ifdef SKIP_ASM
extern "C" int func_003965F0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x178)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_003965F8);
#ifdef SKIP_ASM
extern "C" int func_003965F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x17C)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396600);
#ifdef SKIP_ASM
extern "C" int func_00396600(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x174)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396608);
#ifdef SKIP_ASM
extern "C" void func_00396608(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x174))) = arg1;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396610);
#ifdef SKIP_ASM
extern "C" int func_00396610(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1E0)));
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396618);
#ifdef SKIP_ASM
struct sFontQuad_6618 {
    int v[4];
} __attribute__((aligned(16)));

extern "C" sFontQuad_6618 func_00396618(void* self, int idx)
{
    int next = *(int*)((char*)self + 0x17C) + 1;
    return (*(sFontQuad_6618**)((char*)self + 0x1A0))[(idx + next) % *(int*)((char*)self + 0x178)];
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396658);
#ifdef SKIP_ASM
struct sFontQuad_6658 {
    int v[4];
} __attribute__((aligned(16)));

extern "C" sFontQuad_6658 func_00396658(void* self, int idx)
{
    int next = *(int*)((char*)self + 0x17C) + 1;
    return (*(sFontQuad_6658**)((char*)self + 0x1A4))[(idx + next) % *(int*)((char*)self + 0x178)];
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396698);
#ifdef SKIP_ASM
extern "C" void func_00396698(void* self, int idx, int** outA, int** outB)
{
    int next = *(int*)((char*)self + 0x17C) + 1;
    int off = ((idx + next) % *(int*)((char*)self + 0x178)) * 0x10;
    *outA = (int*)(*(char**)((char*)self + 0x1A0) + off);
    *outB = (int*)(*(char**)((char*)self + 0x1A4) + off);
}
#endif
//100%
INCLUDE_ASM("render/font", func_003966D8);
#ifdef SKIP_ASM
struct sFontQuad_66D8 {
    int v[4];
} __attribute__((aligned(16)));

extern "C" void func_003966D8(void* self, int idx, sFontQuad_66D8* outA, sFontQuad_66D8* outB)
{
    int next = *(int*)((char*)self + 0x17C) + 1;
    int i = (idx + next) % *(int*)((char*)self + 0x178);
    *outA = (*(sFontQuad_66D8**)((char*)self + 0x1A0))[i];
    *outB = (*(sFontQuad_66D8**)((char*)self + 0x1A4))[i];
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396720);
#ifdef SKIP_ASM
extern "C" void func_00396720(void* self, int idx, int** outA, int** outB, int** outC)
{
    int next = *(int*)((char*)self + 0x17C) + 1;
    int i = (idx + next) % *(int*)((char*)self + 0x178);
    int off = i * 0x10;
    *outA = (int*)(*(char**)((char*)self + 0x1A0) + off);
    *outB = (int*)(*(char**)((char*)self + 0x1A4) + off);
    *outC = (int*)(*(char**)((char*)self + 0x204) + i * 4);
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396770);
#ifdef SKIP_ASM
struct sFontQ4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sFontRGBA {
    char r, g, b, a;
};

extern "C" void func_00396770(char* self, int idx, sFontQ4* out0, sFontQ4* out1, sFontRGBA* out2)
{
    int i = (idx + 1 + *(int*)(self + 0x17C)) % *(int*)(self + 0x178);
    *out0 = (*(sFontQ4**)(self + 0x1A0))[i];
    *out1 = (*(sFontQ4**)(self + 0x1A4))[i];
    *out2 = (*(sFontRGBA**)(self + 0x204))[i];
}
#endif
//100%
INCLUDE_ASM("render/font", func_003967D8);
#ifdef SKIP_ASM
struct sFontP_67D8 {
    int v;
} __attribute__((packed));

struct sFontWord_67D8 {
    sFontP_67D8 p;
    sFontWord_67D8() {}
    sFontWord_67D8(const sFontWord_67D8& o) : p(o.p) {}
};

extern "C" sFontWord_67D8 func_003967D8(void* self, int idx)
{
    int next = *(int*)((char*)self + 0x17C) + 1;
    return (*(sFontWord_67D8**)((char*)self + 0x204))[(idx + next) % *(int*)((char*)self + 0x178)];
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396820);
#ifdef SKIP_ASM
extern char D_004930A0[];

extern "C" void* func_00396820(void** self)
{
    *self = D_004930A0;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396838);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_00396838(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396868);
#ifdef SKIP_ASM
extern int D_004A41D4;

extern "C" int *func_00396868(void) {
    return &D_004A41D4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396878);
#ifdef SKIP_ASM
extern int D_004A41D8;

extern "C" int *func_00396878(void) {
    return &D_004A41D8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396888);
#ifdef SKIP_ASM
extern int D_004A41DC;

extern "C" int *func_00396888(void) {
    return &D_004A41DC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396898);
#ifdef SKIP_ASM
extern int D_004A41E0;

extern "C" int *func_00396898(void) {
    return &D_004A41E0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003968A8);
#ifdef SKIP_ASM
extern int D_004A41E4;

extern "C" int *func_003968A8(void) {
    return &D_004A41E4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003968B8);
#ifdef SKIP_ASM
extern int D_004A41E8;

extern "C" int *func_003968B8(void) {
    return &D_004A41E8;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003968C8__FPv);
#ifdef SKIP_ASM
void func_003968C8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_003968D0);
#ifdef SKIP_ASM
extern "C" void func_003968D0(void* self, int a1, void* a2)
{
    cQuad128* p = *(cQuad128**)((char*)self + 0x8);
    p[a1] = *(cQuad128*)a2;
}
#endif

//100%
INCLUDE_ASM("render/font", func_003968E8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_003968E8(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396918__FPv);
#ifdef SKIP_ASM
void func_00396918(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396920__FPv);
#ifdef SKIP_ASM
void func_00396920(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396928);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_00396928(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396958__FPv);
#ifdef SKIP_ASM
void func_00396958(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396960);
#ifdef SKIP_ASM
extern int D_004A4340;

extern "C" int *func_00396960(void) {
    return &D_004A4340;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396970);
#ifdef SKIP_ASM
extern int D_004A4344;

extern "C" int *func_00396970(void) {
    return &D_004A4344;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396980);
#ifdef SKIP_ASM
extern int D_004A4348;

extern "C" int *func_00396980(void) {
    return &D_004A4348;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396990);
#ifdef SKIP_ASM
extern int D_004A434C;

extern "C" int *func_00396990(void) {
    return &D_004A434C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003969A0);
#ifdef SKIP_ASM
extern int D_004A4350;

extern "C" int *func_003969A0(void) {
    return &D_004A4350;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003969B0);
#ifdef SKIP_ASM
extern int D_004A4354;

extern "C" int *func_003969B0(void) {
    return &D_004A4354;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003969C0);
#ifdef SKIP_ASM
extern int D_004A4358;

extern "C" int *func_003969C0(void) {
    return &D_004A4358;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003969D0);
#ifdef SKIP_ASM
extern int D_004A435C;

extern "C" int *func_003969D0(void) {
    return &D_004A435C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003969E0);
#ifdef SKIP_ASM
extern int D_004A4360;

extern "C" int *func_003969E0(void) {
    return &D_004A4360;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003969F0);
#ifdef SKIP_ASM
extern int D_004A4364;

extern "C" int *func_003969F0(void) {
    return &D_004A4364;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396A00);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_00396A00(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396A30);
#ifdef SKIP_ASM
extern int D_004A4478;

extern "C" int *func_00396A30(void) {
    return &D_004A4478;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396A40);
#ifdef SKIP_ASM
extern int D_004A447C;

extern "C" int *func_00396A40(void) {
    return &D_004A447C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396A50);
#ifdef SKIP_ASM
extern int D_004A4480;

extern "C" int *func_00396A50(void) {
    return &D_004A4480;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396A60);
#ifdef SKIP_ASM
extern int D_004A4484;

extern "C" int *func_00396A60(void) {
    return &D_004A4484;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396A70);
#ifdef SKIP_ASM
extern int D_004A4488;

extern "C" int *func_00396A70(void) {
    return &D_004A4488;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396A80);
#ifdef SKIP_ASM
extern int D_004A448C;

extern "C" int *func_00396A80(void) {
    return &D_004A448C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396A90);
#ifdef SKIP_ASM
extern int D_004A4490;

extern "C" int *func_00396A90(void) {
    return &D_004A4490;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396AA0);
#ifdef SKIP_ASM
extern int D_004A4494;

extern "C" int *func_00396AA0(void) {
    return &D_004A4494;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396AB0);
#ifdef SKIP_ASM
extern int D_004A4498;

extern "C" int *func_00396AB0(void) {
    return &D_004A4498;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396AC0);
#ifdef SKIP_ASM
extern int D_004A449C;

extern "C" int *func_00396AC0(void) {
    return &D_004A449C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396AD0);
#ifdef SKIP_ASM
extern int D_004A44A0;

extern "C" int *func_00396AD0(void) {
    return &D_004A44A0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396AE0);
#ifdef SKIP_ASM
extern int D_004A44A4;

extern "C" int *func_00396AE0(void) {
    return &D_004A44A4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396AF0);
#ifdef SKIP_ASM
extern int D_004A44A8;

extern "C" int *func_00396AF0(void) {
    return &D_004A44A8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396B00);
#ifdef SKIP_ASM
extern int D_004A44AC;

extern "C" int *func_00396B00(void) {
    return &D_004A44AC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396B10);
#ifdef SKIP_ASM
extern int D_004A44B0;

extern "C" int *func_00396B10(void) {
    return &D_004A44B0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396B20);
#ifdef SKIP_ASM
extern int D_004A44B4;

extern "C" int *func_00396B20(void) {
    return &D_004A44B4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396B30);
#ifdef SKIP_ASM
extern int D_004A44B8;

extern "C" int *func_00396B30(void) {
    return &D_004A44B8;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396B40);
#ifdef SKIP_ASM
// PORT: PS2-only GS packet build; uncached (0x30000000) pointers held in int and 128-bit qword copies.
typedef int cQuad128_6B40 __attribute__((mode(TI)));
extern char D_1150[];

struct sRS_6B40 {
    int f0;
    int f4;
    int f8;
    int fC;
};

// Emits the font's GS setup packet (register set + the 10 cached qwords) and a VU call for the glyph program.
extern "C" void func_00396B40(char* self)
{
    sRS_6B40* rs = *(sRS_6B40**)(self + 0xE84);
    unsigned int addrMask = 0x3FFFFFFF;
    rs->f0 = (rs->f0 & ~0x3C0) | 0x180;
    sRS_6B40* rs2 = *(sRS_6B40**)(self + 0xE84);
    rs2->fC = (rs2->fC & 0xC0000000) | (*(unsigned int*)(self + 0x5A00) & addrMask);
    unsigned long* p = (unsigned long*)(*(unsigned int*)(self + 0x5A00) | 0x30000000);
    p[0] = 0x6000000C;
    p[2] = (unsigned long)0x8000 << 45;
    p[3] = 0x6C0A000701000101;
    p[1] = 0;
    p += 4;
    cQuad128_6B40* src = (cQuad128_6B40*)(self + 0x6BB0);
    for (int i = 0; i < 10; i++) {
        ((cQuad128_6B40*)p)[i] = src[i];
    }
    p[20] = 0;
    p[21] = (unsigned long)(((unsigned int)D_1150 >> 3) | 0x14000000) << 32;
    p += 22;
    *(unsigned int*)(self + 0x5A00) = (unsigned int)p & 0x0FFFFFFF;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396C30);
#ifdef SKIP_ASM
extern char D_80[];
extern char D_70[];

struct sMtx_6C30 {
    float m[16];
};

struct sMtxList_6C30 {
    int count;
    int* index;
};

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMtx_6C30(void* dst, const void* src)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// Emits a DMA chain that uploads count 4x4 matrices (selected by index) and then a closing tag.
extern "C" void func_00396C30(void* self, sMtxList_6C30* list, sMtx_6C30* mats, unsigned long** cur)
{
    int n = list->count;
    int* idx = list->index;
    unsigned long* p = *cur;
    p[0] = (n << 2) | 0x10000002;
    p[2] = (unsigned long)0x8000 << 45;
    p[3] = ((unsigned long)(unsigned int)((n << 18) | 0x6C000011) << 32) | 0x1000101;
    p[1] = 0;
    p += 4;
    for (int i = 0; i < n; i++) {
        vu0CopyMtx_6C30(p, &mats[idx[i]]);
        p += 8;
    }
    p[0] = ((unsigned long)n << 32) | 0x600103FF;
    p[1] = (unsigned long)(((unsigned int)D_80 >> 3) | 0x14000000) | ((unsigned long)(((unsigned int)D_70 >> 3) | 0x14000000) << 32);
    p += 2;
    *cur = p;
}
#endif

//100%
INCLUDE_ASM("render/font", func_00396D30);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00488680[];

extern "C" void func_00396D30(int* self, int flags)
{
    *(void**)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

extern "C" void* func_00393048(int, int);

//100%
INCLUDE_ASM("render/font", func_00396D60);
#ifdef SKIP_ASM
extern int D_004A45D8;

extern "C" int *func_00396D60(void) {
    return &D_004A45D8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396D70);
#ifdef SKIP_ASM
extern int D_004A45DC;

extern "C" int *func_00396D70(void) {
    return &D_004A45DC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396D80);
#ifdef SKIP_ASM
extern int D_004A45E0;

extern "C" int *func_00396D80(void) {
    return &D_004A45E0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396D90);
#ifdef SKIP_ASM
extern int D_004A45E4;

extern "C" int *func_00396D90(void) {
    return &D_004A45E4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396DA0);
#ifdef SKIP_ASM
extern int D_004A45E8;

extern "C" int *func_00396DA0(void) {
    return &D_004A45E8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396DB0);
#ifdef SKIP_ASM
extern int D_004A45EC;

extern "C" int *func_00396DB0(void) {
    return &D_004A45EC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396DC0);
#ifdef SKIP_ASM
extern int D_004A45F0;

extern "C" int *func_00396DC0(void) {
    return &D_004A45F0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396DD0);
#ifdef SKIP_ASM
extern int D_004A45F4;

extern "C" int *func_00396DD0(void) {
    return &D_004A45F4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396DE0);
#ifdef SKIP_ASM
extern int D_004A45F8;

extern "C" int *func_00396DE0(void) {
    return &D_004A45F8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396DF0);
#ifdef SKIP_ASM
extern int D_004A45FC;

extern "C" int *func_00396DF0(void) {
    return &D_004A45FC;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E00);
#ifdef SKIP_ASM
extern int D_004A4600;

extern "C" int *func_00396E00(void) {
    return &D_004A4600;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E10);
#ifdef SKIP_ASM
extern int D_004A4604;

extern "C" int *func_00396E10(void) {
    return &D_004A4604;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E20);
#ifdef SKIP_ASM
extern int D_004A4608;

extern "C" int *func_00396E20(void) {
    return &D_004A4608;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E30);
#ifdef SKIP_ASM
extern int D_004A460C;

extern "C" int *func_00396E30(void) {
    return &D_004A460C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E40);
#ifdef SKIP_ASM
extern int D_004A4610;

extern "C" int *func_00396E40(void) {
    return &D_004A4610;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E50);
#ifdef SKIP_ASM
extern int D_004A4614;

extern "C" int *func_00396E50(void) {
    return &D_004A4614;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E60);
#ifdef SKIP_ASM
extern int D_004A4618;

extern "C" int *func_00396E60(void) {
    return &D_004A4618;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E70);
#ifdef SKIP_ASM
extern int D_004A461C;

extern "C" int *func_00396E70(void) {
    return &D_004A461C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E80);
#ifdef SKIP_ASM
extern int D_004A4620;

extern "C" int *func_00396E80(void) {
    return &D_004A4620;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396E90);
#ifdef SKIP_ASM
extern int D_004A4624;

extern "C" int *func_00396E90(void) {
    return &D_004A4624;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396EA0);
#ifdef SKIP_ASM
extern int D_004A4628;

extern "C" int *func_00396EA0(void) {
    return &D_004A4628;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396EB0);
#ifdef SKIP_ASM
extern int D_004A462C;

extern "C" int *func_00396EB0(void) {
    return &D_004A462C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396EC0);
#ifdef SKIP_ASM
extern int D_004A4630;

extern "C" int *func_00396EC0(void) {
    return &D_004A4630;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396ED0);
#ifdef SKIP_ASM
extern int D_004A4634;

extern "C" int *func_00396ED0(void) {
    return &D_004A4634;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396EE0);
#ifdef SKIP_ASM
extern int D_004A4638;

extern "C" int *func_00396EE0(void) {
    return &D_004A4638;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396EF0);
#ifdef SKIP_ASM
extern int D_004A463C;

extern "C" int *func_00396EF0(void) {
    return &D_004A463C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F00);
#ifdef SKIP_ASM
extern int D_004A4640;

extern "C" int *func_00396F00(void) {
    return &D_004A4640;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F10);
#ifdef SKIP_ASM
extern int D_004A4644;

extern "C" int *func_00396F10(void) {
    return &D_004A4644;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F20);
#ifdef SKIP_ASM
extern int D_004A4648;

extern "C" int *func_00396F20(void) {
    return &D_004A4648;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F30);
#ifdef SKIP_ASM
extern int D_004A464C;

extern "C" int *func_00396F30(void) {
    return &D_004A464C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F40);
#ifdef SKIP_ASM
extern int D_004A4650;

extern "C" int *func_00396F40(void) {
    return &D_004A4650;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F50);
#ifdef SKIP_ASM
extern int D_004A4654;

extern "C" int *func_00396F50(void) {
    return &D_004A4654;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F60);
#ifdef SKIP_ASM
extern int D_004A4658;

extern "C" int *func_00396F60(void) {
    return &D_004A4658;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F70);
#ifdef SKIP_ASM
extern int D_004A465C;

extern "C" int *func_00396F70(void) {
    return &D_004A465C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F80);
#ifdef SKIP_ASM
extern int D_004A4660;

extern "C" int *func_00396F80(void) {
    return &D_004A4660;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396F90);
#ifdef SKIP_ASM
extern int D_004A4664;

extern "C" int *func_00396F90(void) {
    return &D_004A4664;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396FA0);
#ifdef SKIP_ASM
extern int D_004A4668;

extern "C" int *func_00396FA0(void) {
    return &D_004A4668;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396FB0);
#ifdef SKIP_ASM
extern int D_004A466C;

extern "C" int *func_00396FB0(void) {
    return &D_004A466C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396FC0);
#ifdef SKIP_ASM
extern int D_004A4670;

extern "C" int *func_00396FC0(void) {
    return &D_004A4670;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396FD0);
#ifdef SKIP_ASM
extern int D_004A4674;

extern "C" int *func_00396FD0(void) {
    return &D_004A4674;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00396FE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern float colR __asm__("D_004A45E4");
extern float colG __asm__("D_004A45E8");
extern float colB __asm__("D_004A45EC");

extern "C" int func_00396FE0(void)
{
    int r = (int)(colR * 255.0f);
    int g = (int)(colG * 255.0f);
    int b = (int)(colB * 255.0f);
    return (0xFF << 24) | (r << 16) | (g << 8) | b;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00397038);
#ifdef SKIP_ASM
extern float D_004A469C;
extern float D_004A46A0;

extern "C" float func_00397038(void) {
    return D_004A469C * D_004A46A0;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00397048);
#ifdef SKIP_ASM
extern float D_004A469C;
extern float D_004A46A4;

extern "C" float func_00397048(void) {
    return D_004A469C * D_004A46A4;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00397058);
#ifdef SKIP_ASM
extern float D_004A469C;
extern float D_004A46A8;

extern "C" float func_00397058(void) {
    return D_004A469C * D_004A46A8;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00397068);
#ifdef SKIP_ASM
extern "C" void func_00397068(float value) {
    *(float*)&D_004A45F8 = value;
    *(float*)&D_004A45F4 = value;
    *(float*)&D_004A45F0 = value;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00397078);
#ifdef SKIP_ASM
extern int D_004A4678;

extern "C" int *func_00397078(void) {
    return &D_004A4678;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00397088);
#ifdef SKIP_ASM
extern int D_004A467C;

extern "C" int *func_00397088(void) {
    return &D_004A467C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_00397098);
#ifdef SKIP_ASM
extern int D_004A4680;

extern "C" int *func_00397098(void) {
    return &D_004A4680;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003970A8);
#ifdef SKIP_ASM
extern int D_004A4684;

extern "C" int *func_003970A8(void) {
    return &D_004A4684;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003970B8);
#ifdef SKIP_ASM
extern int D_004A4688;

extern "C" int *func_003970B8(void) {
    return &D_004A4688;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003970C8);
#ifdef SKIP_ASM
extern int D_004A468C;

extern "C" int *func_003970C8(void) {
    return &D_004A468C;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003970D8);
#ifdef SKIP_ASM
extern int D_004A4690;

extern "C" int *func_003970D8(void) {
    return &D_004A4690;
}
#endif
//100%
INCLUDE_ASM("render/font", func_003970E8);
#ifdef SKIP_ASM
extern int D_004A4694;

extern "C" int *func_003970E8(void) {
    return &D_004A4694;
}
#endif

//99.38%
INCLUDE_ASM("render/font", func_003970F8__FPv);
#ifdef SKIP_ASM
void* func_003970F8(void* self)
{
    return func_00393048(1, 0xffff);
}
#endif

extern "C" void* func_00393048(int, int);

//99.38%
INCLUDE_ASM("render/font", func_00397118__FPv);
#ifdef SKIP_ASM
void* func_00397118(void* self)
{
    return func_00393048(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("render/font", func_00397138__FPvi);
#ifdef SKIP_ASM
void func_00397138(void* self, int val)
{
    *(int*)((char*)self + 0x0) = val;
}
#endif

