#include "common.h"

//100%
INCLUDE_ASM("ui/uitext", cUIText_render2D);
#ifdef SKIP_ASM
extern "C" void* func_003A04F0(void* self);
extern "C" float func_00392BA8(void* font, int ch);
extern "C" float func_003921F0_r2d(void* font, const void* str, void* out, int flags, float sx, float sy) __asm__("func_003921F0");
extern "C" void func_0039FEB8_r2d(void* self, void* pos, void* size) __asm__("func_0039FEB8");
extern "C" void func_00391E30_r2d(void* font, float x, float y, const void* str) __asm__("func_00391E30");
extern "C" int USTR_length(unsigned short* s);
extern "C" void func_002C2718(void* dst, const char* fmt, const void* s);
void cMemMan_free(void*);
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char* D_004A289C;
extern char D_00494078[];
extern char D_004A47B0[];
extern unsigned short D_00508750[];

struct sV2_R2D {
    float x, y;
    sV2_R2D() {}
    sV2_R2D(float ax, float ay) : x(ax), y(ay) {}
};
struct sV3_R2D {
    float x, y, z;
    sV3_R2D() {}
    sV3_R2D(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
struct sCol_R2D {
    float r, g, b, a;
};
struct sFont_R2D {
    char pad0[0x14];
    int height;             // 0x14
    char pad18[0x10];
    sV2_R2D shadowOfs;      // 0x28
    sV2_R2D scale;          // 0x30
    sV2_R2D cur;            // 0x38
    sCol_R2D color;         // 0x40
    sCol_R2D shadowColor;   // 0x50
};
struct sLayerBits_R2D {
    unsigned char lo;
    unsigned char layer : 5;
};
struct sVE_R2D { short delta; short index; void (*fn)(void*); };
struct sText_R2D {
    char pad0[0x8];
    sVE_R2D* vt;            // 0x08
    char padC[0x8];
    int flags14;            // 0x14
    char pad18[0x4];
    sCol_R2D color;         // 0x1C
    char pad2C[0x18];
    float x;                // 0x44
    float y;                // 0x48
    char pad4C[0x4];
    float sx;               // 0x50
    float sy;               // 0x54
    char pad58[0x4];
    char* parent;           // 0x5C
    float width;            // 0x60
    char pad64[0x10];
    int flags;              // 0x74
    sCol_R2D shadowColor;   // 0x78
    sCol_R2D colA;          // 0x88
    sCol_R2D colB;          // 0x98
    int count;              // 0xA8
    unsigned short** lines; // 0xAC
    char padB0[0x4];
    unsigned short* text;   // 0xB4
};
extern sV2_R2D D_004A5A60;

extern "C" void cUIText_render2D(sText_R2D* self, float x, float y)
{
    if (self->text == 0 || ((self->flags14 >> 2) & 1) == 0) {
        self->vt[16].fn((char*)self + self->vt[16].delta);
    }
    int* loc = *(int**)(*(char**)(*(char**)(self->parent + 0xD0) + 0x10) + 0x10);
    if (loc != 0 && ((*loc >> 27) & 1)) {
        void* f = func_003A04F0(self);
        if (f == 0) {
            return;
        }
        int n = (int)(self->width / (func_00392BA8(f, 0x57) * self->sx));
        int k = 0;
        if (n < 0x400) {
            for (k = 0; k < n; k++) {
                D_00508750[k] = 0x57;
            }
        }
        D_00508750[k] = 0;
    }
    if (self->text == 0) {
        return;
    }
    sFont_R2D* font = (sFont_R2D*)func_003A04F0(self);
    if (font == 0) {
        return;
    }
    sV2_R2D s(self->sx, self->sy);
    font->cur.x = font->scale.x * s.x;
    font->cur.y = font->scale.y * s.y;
    if (((self->flags14 >> 5) & 1) && ((self->flags >> 4) & 1)) {
        font->color = self->colA;
    } else if (((self->flags14 >> 3) & 1) == 0 && ((self->flags >> 5) & 1)) {
        font->color = self->colB;
    } else {
        font->color = self->color;
    }
    if ((self->flags >> 2) & 1) {
        sCol_R2D c = self->shadowColor;
        c.r = self->color.r;
        font->shadowColor = c;
        font->shadowOfs = D_004A5A60;
    } else {
        font->shadowOfs = sV2_R2D(0.0f, 0.0f);
    }
    int* d = (int*)(*(char**)(D_004A289C + 0xE84) + 8);
    *d = (*d & ~0x3E0) | (((((sLayerBits_R2D*)&self->flags14)->layer + 9) << 5) & 0x3E0);
    sV3_R2D pos(self->x + x, self->y + y, 0.0f);
    int i = 0;
    if (self->count > 0) do {
        unsigned short* str;
        if (i != 0) {
            str = self->lines[i];
        } else {
            str = self->text;
        }
        if (loc != 0 && ((*loc >> 27) & 1)) {
            str = D_00508750;
        }
        if (((self->flags >> 6) & 1) && self->count > 1) {
            unsigned short* buf = (unsigned short*)operator_new__FUi((USTR_length(str) + 5) * 2, D_00494078, 0x100, 0);
            func_002C2718(buf, D_004A47B0, str);
            float r[4];
            func_003921F0_r2d(font, buf, r, 0, s.x, s.y);
            sV3_R2D size(r[2], self->sy * ((float)font->height * font->scale.y), 0.0f);
            sV3_R2D p = pos;
            func_0039FEB8_r2d(self, &p, &size);
            pos.y += ((float)font->height * font->scale.y) * s.y + 3.0f;
            func_00391E30_r2d(font, p.x, p.y, buf);
            if (buf != 0) {
                cMemMan_free(buf);
            }
            return;
        }
        float r[4];
        func_003921F0_r2d(font, str, r, 0, s.x, s.y);
        i++;
        sV3_R2D size(r[2], self->sy * ((float)font->height * font->scale.y), 0.0f);
        sV3_R2D p = pos;
        func_0039FEB8_r2d(self, &p, &size);
        pos.y += ((float)font->height * font->scale.y) * s.y + 3.0f;
        func_00391E30_r2d(font, p.x, p.y, str);
    } while (i < self->count);
}
#endif

//100%
INCLUDE_ASM("ui/uitext", cUIText_deleteText);
#ifdef SKIP_ASM
void cMemMan_free(void*);

extern "C" void cUIText_deleteText(void* self)
{
    *(int*)((char*)self + 0xA8) = 0;
    if (*(void**)((char*)self + 0xAC) != 0) {
        cMemMan_free(*(void**)((char*)self + 0xAC));
        *(void**)((char*)self + 0xAC) = 0;
    }
    if (*(void**)((char*)self + 0xB4) != 0) {
        cMemMan_free(*(void**)((char*)self + 0xB4));
        *(void**)((char*)self + 0xB4) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", cUIText_getNumTextLines);
#ifdef SKIP_ASM
extern unsigned short D_004A47A8;
extern "C" char cUIText_getNumTextLines_(void* self) __asm__("cUIText_getNumTextLines");
extern "C" char cUIText_getNumTextLines_(void* self)
{
    unsigned short* text = *(unsigned short**)((char*)self + 0xB4);
    if (text == 0) return 0;
    unsigned short* p = text;
    int n = 1;
    while (*p != 0) {
        unsigned short c = *p;
        unsigned short next = p[1];
        if (c == D_004A47A8 && next == c) {
            p += 2;
            n++;
        } else if (c == 13) {
            p++;
            n++;
        } else {
            p++;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A0C00);
#ifdef SKIP_ASM
extern "C" int func_003A0C00(void* self)
{
    if (((*(int*)((char*)self + 0x74) >> 3) & 1) == 0) {
        return *(int*)((char*)self + 0xb4);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A0C28);
#ifdef SKIP_ASM
extern "C" int func_003A0C28(void* self)
{
    if (((*(int*)((char*)self + 0x74) >> 3) & 1) != 0) {
        return *(int*)((char*)self + 0xb4);
    }
    return 0;
}
#endif

struct cUITextManager {
    char pad_0x00[0x28];
    short field_0x28;
    char pad_0x2A[2];
    void (*fn)(void*, int); // 0x2C
};

struct cUIText {
    char pad_0x00[0x8];
    cUITextManager* mMgr; // 0x8
    char pad_0xC[0xB0 - 0xC];
    int field_0xB0;
};

extern "C" void cUIText_setAsciiStringPrivate(void* self, const char* str);

//100%
INCLUDE_ASM("ui/uitext", cUIText_setAsciiString__FP7cUITextPCc);
#ifdef SKIP_ASM
void cUIText_setAsciiString(cUIText* self, const char* str)
{
    self->field_0xB0 = 0;
    cUIText_setAsciiStringPrivate(self, str);
}
#endif

//100%
INCLUDE_ASM("ui/uitext", cUIText_setAsciiStringPrivate);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);
void UIAsciiToUnicode(unsigned short* dst, const char* src);
extern "C" void cUIText_setUnicodeStringPrivate(void* self, const unsigned short* str);

class cUIText_3A0C70 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int);
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
    virtual void v24(int);
};

extern "C" void cUIText_setAsciiStringPrivate(void* self, const char* str)
{
    unsigned short buf[0x200];
    ((cUIText_3A0C70*)self)->v05(1);
    ((cUIText_3A0C70*)self)->v24(0);
    if (strlen(str) + 1 < 0x200) {
        UIAsciiToUnicode(buf, str);
        cUIText_setUnicodeStringPrivate(self, buf);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A0D00);
#ifdef SKIP_ASM
extern "C" void* func_003A04F0(void* self);
extern "C" float func_00392C60(void* font, unsigned short ch);
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
extern "C" void cUIText_setUnicodeStringPrivate(void* self, const unsigned short* str);
void cMemMan_free(void*);
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_00494078[];
extern unsigned short D_004A47A8;

extern "C" void func_003A0D00(void* self, unsigned short* str)
{
    ((cUIText_3A0C70*)self)->v05(1);
    void* font = func_003A04F0(self);
    if (font == 0) {
        return;
    }
    int last = -1;
    float w = 0.0f;
    int len = USTR_length(str);
    unsigned short* buf = (unsigned short*)operator_new__FUi((len + 1) * 2, D_00494078, 0x100, 0);
    int i = 0;
    USTR_copy(buf, str);
    while (i < len) {
        if (buf[i] == D_004A47A8 && buf[i + 1] == buf[i]) {
            last = -1;
            w = 0.0f;
            i += 2;
        } else {
            w += func_00392C60(font, buf[i]) * *(float*)((char*)self + 0x50);
            if (buf[i] == 0x20) {
                last = i;
            }
            if (w > *(float*)((char*)self + 0x60) && last >= 0) {
                buf[last] = 0xD;
                i = last;
                w = 0.0f;
                last = -1;
            }
            i++;
        }
    }
    cUIText_setUnicodeStringPrivate(self, buf);
    if (buf) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A0E90);
#ifdef SKIP_ASM
extern "C" void cUIText_setUnicodeStringPrivate(void* self, const unsigned short* str);

extern "C" void func_003A0E90(void* self, const unsigned short* str)
{
    *(int*)((char*)self + 0xB0) = 0;
    cUIText_setUnicodeStringPrivate(self, str);
}
#endif

//100%
INCLUDE_ASM("ui/uitext", cUIText_setUnicodeStringPrivate);
#ifdef SKIP_ASM
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
extern "C" void cUIText_deleteText(void* self);
extern "C" int cUIText_getNumTextLines(void* self);
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_00494088[];
extern char D_00494098[];
extern unsigned short D_004A47A8;

// Stores a copy of the string and splits it into lines at CR and at doubled line-break markers.
extern "C" void cUIText_setUnicodeStringPrivate(void* self_, const unsigned short* str)
{
    char* self = (char*)self_;
    ((cUIText_3A0C70*)self)->v05(1);
    ((cUIText_3A0C70*)self)->v24(1);
    cUIText_deleteText(self);
    int len = USTR_length((unsigned short*)str);
    if (len < 0x321) {
        *(short*)(self + 0xB8) = len + 1;
        *(unsigned short**)(self + 0xB4) = (unsigned short*)operator_new__FUi((len + 1) * 2, D_00494088, 0x100, 0);
        USTR_copy(*(unsigned short**)(self + 0xB4), (unsigned short*)str);
        int n = cUIText_getNumTextLines(self);
        *(int*)(self + 0xA8) = n;
        if (n >= 2) {
            unsigned short** lines = (unsigned short**)operator_new__FUi(n * 4, D_00494098, 0x100, 0);
            unsigned short* text = *(unsigned short**)(self + 0xB4);
            *(unsigned short***)(self + 0xAC) = lines;
            *(short*)(self + 0xBA) = *(unsigned short*)(self + 0xA8);
            lines[0] = text;
            int k = 1;
            unsigned short* p = text;
            while (*p != 0) {
                unsigned short c = *p;
                unsigned short next = p[1];
                if (c == D_004A47A8 && next == c) {
                    *p = 0;
                    p += 2;
                    lines[k++] = p;
                } else if (c == 0xD) {
                    *p = 0;
                    p++;
                    lines[k++] = p;
                } else {
                    p++;
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", cUIText_setUnicodeStringByID__FP7cUITexti);
#ifdef SKIP_ASM
void cUIText_setUnicodeStringByID(cUIText* self, int id)
{
    self->field_0xB0 = id;
    cUITextManager* mgr = self->mMgr;
    mgr->fn((char*)self + mgr->field_0x28, 0);
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1030);
#ifdef SKIP_ASM
extern "C" void* func_003A04F0(void* self);
extern "C" float func_003921F0(void* font, int str, void* out, int flags, float sx, float sy);

struct func_003A1030_sVec3 {
    float x;
    float y;
    float z;
};
extern func_003A1030_sVec3 D_004FF0D8;

struct func_003A1030_sRect {
    float x0;
    float y0;
    float x1;
    float y1;
};

struct func_003A1030_sVEntry {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_003A1030(void* self, func_003A1030_sVec3* out)
{
    if (*(int*)((char*)self + 0xB4) == 0 || ((*(int*)((char*)self + 0x14) >> 2) & 1) == 0) {
        func_003A1030_sVEntry* vt = *(func_003A1030_sVEntry**)((char*)self + 8);
        vt[16].fn((char*)self + vt[16].delta);
    }
    void* font = func_003A04F0(self);
    int str = *(int*)((char*)self + 0xB4);
    if (str != 0 && font != 0) {
        func_003A1030_sRect r;
        func_003921F0(font, str, &r, 0, *(float*)((char*)self + 0x50), *(float*)((char*)self + 0x54));
        out->x = r.x1;
        out->y = r.y1;
    } else {
        *out = D_004FF0D8;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A10F0);
#ifdef SKIP_ASM
struct func_003A10F0_sVEntry {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" int func_003A10F0(void* self)
{
    if (*(int*)((char*)self + 0xB4) == 0 || ((*(int*)((char*)self + 0x14) >> 2) & 1) == 0) {
        func_003A10F0_sVEntry* vt = *(func_003A10F0_sVEntry**)((char*)self + 8);
        vt[16].fn((char*)self + vt[16].delta);
    }
    return *(int*)((char*)self + 0xA8);
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1148);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a1, int a2);
extern "C" void* func_003977E8(void* self);
extern "C" void func_003A1310(void* self, char a1);
extern void* D_00494278[];

extern "C" void* func_003A1148(void* self, int a1, int a2)
{
    char* s = (char*)self;
    func_0039FB30(self, a1, a2);
    *(void***)(s + 0x8) = D_00494278;
    *(unsigned char*)(s + 0x74) &= 0xC6;
    func_003977E8(s + 0x8C);
    *(int*)(s + 0xB8) = 0;
    *(int*)(s + 0xBC) = 0;
    *(int*)(s + 0xC0) = 0;
    *(short*)(s + 0xC4) = 0;
    *(short*)(s + 0xC6) = 0;
    *(short*)(s + 0xC8) = 0;
    *(int*)(s + 0xCC) = 0;
    func_003A1310(self, 0);
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A11B8);
#ifdef SKIP_ASM
// PORT: func_0039FE00 really takes (self, data); other units declare it with one argument.
void* func_0039FE00_2(void* self, void* data) __asm__("func_0039FE00");
// PORT: called with only self here (the unit declares two arguments).
void func_003A18C0_1(void* self) __asm__("func_003A18C0");
extern "C" void func_003A1F18(void* self, int id);

struct sUIColor11B8 {
    float r, g, b, a;
    sUIColor11B8() {}
    sUIColor11B8(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};
struct sUIVt11B8 { short delta; short index; void (*fn)(void*, int); };
struct sUIText11B8 {
    char pad0[0x8];
    sUIVt11B8* vt;              // 0x8
    char padC[0x74 - 0xC];
    unsigned int b0 : 1;        // 0x74
    unsigned int mode : 2;
    unsigned int rest : 29;
    sUIColor11B8 color;         // 0x78
};
struct sUIData11B8 {
    char pad0[0x20];
    unsigned char mode;         // 0x20
    unsigned char vis;          // 0x21
    char pad22[2];
    int textId;                 // 0x24
    unsigned char r, g, b, a;   // 0x28
};

extern "C" void func_003A11B8(sUIText11B8* self, sUIData11B8* data)
{
    func_0039FE00_2(self, data);
    self->mode = data->mode & 3;
    self->vt[23].fn((char*)self + self->vt[23].delta, data->vis & 1);
    if (data->textId != 0) {
        func_003A18C0_1(self);
        func_003A1F18(self, data->textId);
    }
    int f = *(int*)((char*)self + 0x74) >> 3;
    if (f & 1) {
        self->color = sUIColor11B8(data->r * 0.003921568859368563f, data->g * 0.003921568859368563f,
                                   data->b * 0.003921568859368563f, data->a * 0.003921568859368563f);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A12D0);
#ifdef SKIP_ASM
extern "C" int func_003A12D0(void* self)
{
    void* p = *(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x5c) + 0xd0) + 0x10);
    if (p != 0) {
        return *(int*)((char*)*(void**)((char*)p + 0x8) + ((*(unsigned int*)((char*)self + 0x74) >> 1) & 3) * 12 + 0xC);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1310);
#ifdef SKIP_ASM
extern "C" void func_003A1310(void* self, char a1)
{
    if (a1 == 0) {
        *(char*)((char*)self + 0x88) = 0;
        *(char*)((char*)self + 0x89) = 1;
        *(char*)((char*)self + 0x8A) = 2;
        *(char*)((char*)self + 0x8B) = 3;
    } else {
        *(char*)((char*)self + 0x88) = 4;
        *(char*)((char*)self + 0x89) = 5;
        *(char*)((char*)self + 0x8A) = 6;
        *(char*)((char*)self + 0x8B) = 7;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1360);
#ifdef SKIP_ASM
extern "C" void func_003A1CF0(void* self, void* a1);

class func_003A1360_cVirtA {
public:
    char pad[0x4];
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* v04(int);
};

class func_003A1360_cVirtB {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int);
};

extern "C" void func_003A1360(void* self)
{
    int id = *(int*)((char*)self + 0xC0);
    if (id != 0) {
        func_003A1360_cVirtA* a = *(func_003A1360_cVirtA**)((char*)*(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x5C) + 0xD0) + 0x10) + 0x10);
        if (a != 0) {
            void* r = a->v04(id);
            if (r != 0) {
                func_003A1CF0(self, r);
            }
            ((func_003A1360_cVirtB*)self)->v05(1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A13E0);
#ifdef SKIP_ASM
struct sUIInputVE13E0 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sUIFont13E0 {
    char pad_0x0[0x14];
    int height;             // 0x14
    char pad_0x18[0x1C];
    float scale;            // 0x34
};

struct sUIText13E0 {
    char pad_0x0[0x54];
    float scale;            // 0x54
    char pad_0x58[0xC];
    float height;           // 0x64
    char pad_0x68[0xC];
    unsigned int flags;     // 0x74
    char pad_0x78[0x10];
    signed char keyUp;      // 0x88
    signed char keyDown;    // 0x89
    char pad_0x8A[0x3A];
    unsigned short cur;     // 0xC4
    unsigned short top;     // 0xC6
    unsigned short count;   // 0xC8
};

static inline int pressed13E0(char* input, int key)
{
    sUIInputVE13E0* e = &(*(sUIInputVE13E0**)(input + 8))[2];
    return e->fn(input + e->delta, key);
}

extern "C" int func_003A13E0(sUIText13E0* self, char* input)
{
    sUIFont13E0* font = (sUIFont13E0*)func_003A12D0(self);
    if (font == 0) {
        return 0;
    }
    signed char rows = (int)(self->height / (self->scale * ((float)font->height * font->scale) + 3.0f));
    if (self->flags & 1) {
        if (pressed13E0(input, self->keyUp) != 0) {
            if (self->cur != 0) {
                self->cur--;
            }
            return 1;
        }
        if (pressed13E0(input, self->keyDown) != 0) {
            if (self->cur < self->count - 1) {
                self->cur++;
            }
            return 1;
        }
        short d = self->cur - self->top;
        if (d < 0) {
            self->top = self->cur;
        } else if (d >= rows) {
            self->top = self->cur - rows + 1;
        }
    } else {
        if (pressed13E0(input, self->keyUp) != 0) {
            if (self->top != 0) {
                self->top--;
            }
            return 1;
        }
        if (pressed13E0(input, self->keyDown) == 0) {
            return 0;
        }
        if (self->top < self->count - rows) {
            self->top++;
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1588);
#ifdef SKIP_ASM
extern "C" int func_003A12D0(void* self);
extern "C" float func_003921F0(void* font, int str, void* out, int flags, float sx, float sy);
extern "C" void func_0039FEB8(void* self, void* pos, void* size);
extern "C" void func_00391E30(void* font, float x, float y, int str);
extern "C" void func_0039DA20(void* sb, int top, int rows, int count);
extern char* D_004A289C;

struct sV2_1588 {
    float x, y;
    sV2_1588() {}
    sV2_1588(float ax, float ay) : x(ax), y(ay) {}
};
struct sV3_1588 {
    float x, y, z;
    sV3_1588() {}
    sV3_1588(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
struct sCol_1588 {
    float r, g, b, a;
};
struct sRect_1588 {
    float x0, y0, x1, y1;
};

struct sFont_1588 {
    char pad0[0x14];
    int height;             // 0x14
    char pad18[0x10];
    sV2_1588 shadowOfs;     // 0x28
    sV2_1588 scale;         // 0x30
    sV2_1588 cur;           // 0x38
    sCol_1588 color;        // 0x40
    sCol_1588 shadowColor;  // 0x50
};

struct sLayerBits_1588 {
    unsigned char lo;
    unsigned char layer : 5;
};
struct sDrawBits_1588 {
    unsigned int lo : 5;
    unsigned int layer : 5;
};

struct sVE_1588 { short delta; short index; void (*fn)(void*); };

struct sText_1588 {
    char pad0[0x8];
    sVE_1588* vt;           // 0x08
    char padC[0x8];
    int flags14;            // 0x14
    char pad18[0x4];
    sCol_1588 color;        // 0x1C
    char pad2C[0x18];
    float x;                // 0x44
    float y;                // 0x48
    char pad4C[0x4];
    float sx;               // 0x50
    float sy;               // 0x54
    char pad58[0xC];
    float height;           // 0x64
    char pad68[0xC];
    int flags;              // 0x74
    sCol_1588 shadowColor;  // 0x78
    char pad88[0x20];
    sCol_1588 selColor;     // 0xA8
    void* scroll;           // 0xB8
    int* strs;              // 0xBC
    char padC0[0x4];
    unsigned short cur;     // 0xC4
    unsigned short top;     // 0xC6
    unsigned short count;   // 0xC8
    char padCA[0x2];
    float yofs;             // 0xCC
};

extern "C" void func_003A1588(sText_1588* self, float x, float y)
{
    if (((self->flags14 >> 2) & 1) == 0) {
        self->vt[16].fn((char*)self + self->vt[16].delta);
    }
    sFont_1588* font = (sFont_1588*)func_003A12D0(self);
    if (font == 0) {
        return;
    }
    sV2_1588 s(self->sx, self->sy);
    font->cur.x = font->scale.x * s.x;
    font->cur.y = font->scale.y * s.y;
    if ((self->flags >> 3) & 1) {
        sCol_1588 c = self->shadowColor;
        c.r = self->color.r;
        font->shadowColor = c;
        font->shadowOfs = sV2_1588(2.0f, 2.0f);
    } else {
        font->shadowOfs = sV2_1588(0.0f, 0.0f);
    }
    int* d = (int*)(*(char**)(D_004A289C + 0xE84) + 8);
    *d = (*d & ~0x3E0) | (((((sLayerBits_1588*)&self->flags14)->layer + 9) << 5) & 0x3E0);
    sV3_1588 pos(self->x + x, self->y + y, 0.0f);
    float lineH = self->sy * ((float)font->height * font->scale.y) + 3.0f;
    signed char rows = (int)(self->height / lineH);
    int i = 0;
    if (rows > 0) do {
        unsigned short idx = self->top + i;
        if (idx >= self->count) {
            break;
        }
        if ((self->flags & 1) && idx == self->cur) {
            font->color = self->selColor;
        } else {
            font->color = self->color;
        }
        int str = self->strs[i + self->top];
        i++;
        sRect_1588 r;
        func_003921F0(font, str, &r, 0, self->sx, self->sy);
        sV3_1588 size(r.x1, self->sy * ((float)font->height * font->scale.y), 0.0f);
        sV3_1588 p = pos;
        func_0039FEB8(self, &p, &size);
        pos.y += lineH;
        func_00391E30(font, p.x, p.y + self->yofs, str);
    } while (i < rows);
    if (self->scroll != 0) {
        func_0039DA20(self->scroll, self->top, rows, self->count);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A18C0);
#ifdef SKIP_ASM
void cMemMan_free(void*);

extern "C" void func_003A18C0(void* self, void* a1)
{
    if (*(void***)((char*)self + 0xBC) != 0) {
        unsigned short i;
        for (i = 0; i < *(unsigned short*)((char*)self + 0xC8); i++) {
            if ((*(void***)((char*)self + 0xBC))[i] != 0) {
                cMemMan_free((*(void***)((char*)self + 0xBC))[i]);
            }
        }
        if (*(void***)((char*)self + 0xBC) != 0) {
            cMemMan_free(*(void***)((char*)self + 0xBC));
        }
        *(void***)((char*)self + 0xBC) = 0;
    }
    *(unsigned short*)((char*)self + 0xC6) = 0;
    *(unsigned short*)((char*)self + 0xC8) = 0;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1958);
#ifdef SKIP_ASM
extern "C" void* func_0041605C(void* dst, const void* src, int n);
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_004940A8[];

extern "C" int func_003A1958(void* self)
{
    unsigned short old = *(unsigned short*)((char*)self + 0xC8);
    *(unsigned short*)((char*)self + 0xC8) = old + 1;
    void** arr = (void**)operator_new__FUi(*(unsigned short*)((char*)self + 0xC8) * 4, D_004940A8, 0x100, 0);
    if (*(void***)((char*)self + 0xBC) != 0) {
        func_0041605C(arr, *(void***)((char*)self + 0xBC), old * 4);
        void** prev = *(void***)((char*)self + 0xBC);
        arr[old] = 0;
        if (prev != 0) {
            cMemMan_free(prev);
        }
    }
    *(void***)((char*)self + 0xBC) = arr;
    return old;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A19F8);
#ifdef SKIP_ASM
extern "C" void cUITextScroll_addUnicodeString(void* self, unsigned short* str);
extern "C" unsigned short* func_002C2540(void* dst, void* src);

extern "C" void func_003A19F8(void* self, char* str)
{
    ((cUIText_3A0C70*)self)->v05(1);
    void* font = (void*)func_003A12D0(self);
    if (font == 0) {
        return;
    }
    int last = -1;
    int len = strlen(str);
    int i = 0;
    unsigned short* buf = (unsigned short*)operator_new__FUi((len + 1) * 2, D_00494078, 0x100, 0);
    float w = 0.0f;
    int start = 0;
    func_002C2540(buf, str);
    while (i < len) {
        if (buf[i] == 0x5C && buf[i + 1] == buf[i]) {
            buf[i] = 0;
            i += 2;
            cUITextScroll_addUnicodeString(self, &buf[start]);
            last = -1;
            w = 0.0f;
            start = i;
        } else if (buf[i] == 0xD) {
            buf[i] = 0;
            i += 1;
            cUITextScroll_addUnicodeString(self, &buf[start]);
            last = -1;
            w = 0.0f;
            start = i;
        } else {
            w += func_00392C60(font, buf[i]) * *(float*)((char*)self + 0x50);
            if (buf[i] == 0x20) {
                last = i;
            }
            if (w > *(float*)((char*)self + 0x60)) {
                if (last < 0) {
                    last = i - 1;
                }
                if (last > 0) {
                    buf[last] = 0;
                    i = last;
                    w = 0.0f;
                    cUITextScroll_addUnicodeString(self, &buf[start]);
                    last = -1;
                    start = i + 1;
                }
            }
            i++;
        }
    }
    if (start != i) {
        cUITextScroll_addUnicodeString(self, &buf[start]);
    }
    if (buf) {
        cMemMan_free(buf);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ui/uitext", cUITextScroll_addUnicodeString);
#ifdef SKIP_ASM
extern "C" int func_003A1958(void* self);
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_004940B8[];

extern "C" void cUITextScroll_addUnicodeString(void* self, unsigned short* str)
{
    int idx = func_003A1958(self);
    unsigned short* copy = (unsigned short*)operator_new__FUi((USTR_length(str) + 1) * 2, D_004940B8, 0x100, 0);
    USTR_copy(copy, str);
    (*(unsigned short***)((char*)self + 0xBC))[idx] = copy;
}
#endif

INCLUDE_ASM("ui/uitext", func_003A1C80);

//100%
INCLUDE_ASM("ui/uitext", func_003A1CF0);
#ifdef SKIP_ASM
extern "C" void func_003A18C0(void*, void*);
extern "C" void func_003A1D30(void*, void*);

extern "C" void func_003A1CF0(void* self, void* a1)
{
    func_003A18C0(self, a1);
    func_003A1D30(self, a1);
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1D30);
#ifdef SKIP_ASM
extern "C" void cUITextScroll_addUnicodeString(void* self, unsigned short* str);

extern "C" void func_003A1D30(void* self, void* vstr)
{
    unsigned short* str = (unsigned short*)vstr;
    ((cUIText_3A0C70*)self)->v05(1);
    void* font = (void*)func_003A12D0(self);
    if (font == 0) {
        return;
    }
    int last = -1;
    int len = USTR_length(str);
    int i = 0;
    unsigned short* buf = (unsigned short*)operator_new__FUi((len + 1) * 2, D_00494078, 0x100, 0);
    float w = 0.0f;
    int start = 0;
    USTR_copy(buf, str);
    while (i < len) {
        if (buf[i] == 0x5C && buf[i + 1] == buf[i]) {
            buf[i] = 0;
            i += 2;
            cUITextScroll_addUnicodeString(self, &buf[start]);
            last = -1;
            w = 0.0f;
            start = i;
        } else {
            w += func_00392C60(font, buf[i]) * *(float*)((char*)self + 0x50);
            if (buf[i] == 0x20) {
                last = i;
            }
            if (w > *(float*)((char*)self + 0x60)) {
                if (last < 0) {
                    last = i - 1;
                }
                if (last > 0) {
                    buf[last] = 0;
                    i = last;
                    w = 0.0f;
                    cUITextScroll_addUnicodeString(self, &buf[start]);
                    last = -1;
                    start = i + 1;
                }
            }
            i++;
        }
    }
    if (start != i) {
        cUITextScroll_addUnicodeString(self, &buf[start]);
    }
    if (buf) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1F18);
#ifdef SKIP_ASM
extern "C" void func_003A1D30(void*, void*);

class func_003A1F18_cVirtA {
public:
    char pad[0x4];
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* v04(int);
};

class func_003A1F18_cVirtB {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int);
};

extern "C" void func_003A1F18(void* self, int id)
{
    *(int*)((char*)self + 0xC0) = id;
    func_003A1F18_cVirtA* a = *(func_003A1F18_cVirtA**)((char*)*(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x5C) + 0xD0) + 0x10) + 0x10);
    if (a != 0) {
        void* r = a->v04(id);
        if (r != 0) {
            func_003A1D30(self, r);
        }
        ((func_003A1F18_cVirtB*)self)->v05(1);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A1F90);
#ifdef SKIP_ASM
extern "C" void func_003A1F90(void* self, int idx)
{
    if (*(void***)((char*)self + 0xBC) != 0) {
        unsigned short n = *(unsigned short*)((char*)self + 0xC8);
        if (idx < n) {
            void** arr = (void**)operator_new__FUi((n - 1) * 4, D_004940A8, 0x100, 0);
            if (idx > 0) {
                func_0041605C(arr, *(void***)((char*)self + 0xBC), idx * 4);
            }
            if (idx < *(unsigned short*)((char*)self + 0xC8) - 1) {
                // PORT: pointer held in int (only spelling found that gives idx-first addu)
                func_0041605C((void*)(idx * 4 + (int)arr), (void*)(idx * 4 + *(int*)((char*)self + 0xBC) + 4), (*(unsigned short*)((char*)self + 0xC8) - idx - 1) * 4);
            }
            if (*(void***)((char*)self + 0xBC) != 0) {
                cMemMan_free(*(void***)((char*)self + 0xBC));
            }
            *(void***)((char*)self + 0xBC) = arr;
            (*(unsigned short*)((char*)self + 0xC8))--;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A2068);
#ifdef SKIP_ASM
extern "C" int func_003A2068(void* self, int i)
{
    int* arr = *(int**)((char*)self + 0xBC);
    if (arr != 0 && i >= 0 && i < *(unsigned short*)((char*)self + 0xC8)) {
        return arr[i];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A20A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sRect_20A0 {
    float x, y, w, h;
};
struct sColor_20A0 {
    float a, r, g, b;
};
struct sRS_20A0 {
    char pad[0x10];
    short tex;              // 0x10
};
struct sGfx_20A0 {
    char pad[0xE84];
    sRS_20A0* top;          // 0xE84
};
// One vertex of a submitted quad (stride 0x30).
struct sQuadVtx_20A0 {
    float s, t, q;
    int pad;
    int r, g, b, a;
    float pos[4];
    sQuadVtx_20A0() {}
};
struct sSprite_20A0 {
    int tex;                // 0x0
    char pad[8];
    float v0;               // 0xC
    float u0;               // 0x10
    float u1;               // 0x14
    float v1;               // 0x18
};
// The unit declares D_004A289C as char*; typed view by asm label.
extern sGfx_20A0* D_004A289C_20A0 __asm__("D_004A289C");
extern int D_004A28AC_20A0 __asm__("D_004A28AC");
extern "C" void func_0038E118(int ctx, sQuadVtx_20A0* v, sRect_20A0* r);
extern "C" void func_0038E200(int ctx, sQuadVtx_20A0* v, sRect_20A0* r);

extern "C" void func_003A20A0(sSprite_20A0* o, sRect_20A0 r, sColor_20A0 c, int flags)
{
    int tex = o->tex;
    if (tex < 0) {
        return;
    }
    D_004A289C_20A0->top->tex = tex;
    float v0 = o->v0;
    float v1 = o->v1;
    float u0 = o->u0;
    float u1 = o->u1;
    if (flags & 1) {
        u0 = u1;
        u1 = o->u0;
    }
    if (flags & 2) {
        v0 = v1;
        v1 = o->v0;
    }
    sQuadVtx_20A0 v[4];
    for (int i = 0; i < 4; i++) {
        sQuadVtx_20A0* p = &v[i];
        p->a = (int)(c.a * 128.0f);
        p->r = (int)(c.r * 128.0f);
        p->g = (int)(c.g * 128.0f);
        p->b = (int)(c.b * 128.0f);
        p->q = 1.0f;
    }
    v[0].s = u0;
    v[0].t = v0;
    v[1].s = u1;
    v[1].t = v0;
    v[2].s = u0;
    v[2].t = v1;
    v[3].s = u1;
    v[3].t = v1;
    if (flags & 4) {
        func_0038E200(D_004A28AC_20A0, v, &r);
    } else {
        func_0038E118(D_004A28AC_20A0, v, &r);
    }
}
#endif
//100%
INCLUDE_ASM("ui/uitext", func_003A2220);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sRect_2220 {
    float x, y, w, h;
};
struct sColor_2220 {
    float a, r, g, b;
};
struct sRS_2220 {
    char pad[0x10];
    short tex;              // 0x10
};
struct sGfx_2220 {
    char pad[0xE84];
    sRS_2220* top;          // 0xE84
};
// One vertex of a submitted quad (stride 0x30).
struct sQuadVtx_2220 {
    float s, t, q;
    int pad;
    int r, g, b, a;
    float pos[4];
    sQuadVtx_2220() {}
};
struct sSprite_2220 {
    int tex;                // 0x0
    char pad[8];
    float v0;               // 0xC
    float u0;               // 0x10
    float u1;               // 0x14
    float v1;               // 0x18
};
// The unit declares D_004A289C as char*; typed views by asm label.
extern sGfx_2220* D_004A289C_2220 __asm__("D_004A289C");
extern int D_004A28AC_2220 __asm__("D_004A28AC");
extern void func_0038E118_2220(int ctx, sQuadVtx_2220* v, sRect_2220* r) __asm__("func_0038E118");
extern void func_0038E200_2220(int ctx, sQuadVtx_2220* v, sRect_2220* r) __asm__("func_0038E200");

extern "C" void func_003A2220(sSprite_2220* o, sRect_2220 r, sColor_2220 c, int flags, float t)
{
    float k = 1.0f - t;
    int tex = o->tex;
    D_004A289C_2220->top->tex = tex;
    float v0 = o->v0;
    float v1 = o->v1;
    float u0 = o->u0;
    float u1 = o->u1;
    r.y += k * r.h;
    r.h *= 1.0f - k;
    v0 += k * (v1 - v0);
    sQuadVtx_2220 v[4];
    for (int i = 0; i < 4; i++) {
        sQuadVtx_2220* p = &v[i];
        p->a = (int)(c.a * 128.0f);
        p->r = (int)(c.r * 255.0f);
        p->g = (int)(c.g * 255.0f);
        p->b = (int)(c.b * 255.0f);
        p->q = 1.0f;
    }
    v[0].s = u0;
    v[0].t = v0;
    v[1].s = u1;
    v[1].t = v0;
    v[2].s = u0;
    v[2].t = v1;
    v[3].s = u1;
    v[3].t = v1;
    if (flags & 4) {
        func_0038E200_2220(D_004A28AC_2220, v, &r);
    } else {
        func_0038E118_2220(D_004A28AC_2220, v, &r);
    }
}
#endif

INCLUDE_ASM("ui/uitext", func_003A23B8);
//100%
INCLUDE_ASM("ui/uitext", func_003A2A00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sRect_2A00 {
    float x, y, w, h;
};
struct sColor_2A00 {
    float a, r, g, b;
};
struct sMat3_2A00 {
    float m[9];
};
struct sRS_2A00 {
    char pad[0x10];
    short tex;              // 0x10
};
struct sGfx_2A00 {
    char pad[0xE84];
    sRS_2A00* top;          // 0xE84
};
// One vertex of a submitted quad (stride 0x30).
struct sQuadVtx_2A00 {
    float s, t, q;
    int pad;
    int r, g, b, a;
    float pos[4];
    sQuadVtx_2A00() {}
};
struct sSprite_2A00 {
    int tex;                // 0x0
    char pad[8];
    float v0;               // 0xC
    float u0;               // 0x10
    float u1;               // 0x14
    float v1;               // 0x18
};
// The unit declares D_004A289C as char*; typed views by asm label.
extern sGfx_2A00* D_004A289C_2A00 __asm__("D_004A289C");
extern int D_004A28AC_2A00 __asm__("D_004A28AC");
extern "C" void func_0038E2E8(int ctx, sQuadVtx_2A00* v, sRect_2A00* r, sMat3_2A00* m);
extern "C" void func_0038E468(int ctx, sQuadVtx_2A00* v, sRect_2A00* r, sMat3_2A00* m);

extern "C" void func_003A2A00(sSprite_2A00* o, sRect_2A00 r, sMat3_2A00 m, sColor_2A00 c, int flags)
{
    int tex = o->tex;
    D_004A289C_2A00->top->tex = tex;
    float v0 = o->v0;
    float v1 = o->v1;
    float u0 = o->u0;
    float u1 = o->u1;
    if (flags & 1) {
        u0 = u1;
        u1 = o->u0;
    }
    if (flags & 2) {
        v0 = v1;
        v1 = o->v0;
    }
    sQuadVtx_2A00 v[4];
    for (int i = 0; i < 4; i++) {
        sQuadVtx_2A00* p = &v[i];
        p->a = (int)(c.a * 128.0f);
        p->r = (int)(c.r * 255.0f);
        p->g = (int)(c.g * 255.0f);
        p->b = (int)(c.b * 255.0f);
        p->q = 1.0f;
    }
    v[0].s = u0;
    v[0].t = v0;
    v[1].s = u1;
    v[1].t = v0;
    v[2].s = u0;
    v[2].t = v1;
    v[3].s = u1;
    v[3].t = v1;
    if (flags & 4) {
        func_0038E468(D_004A28AC_2A00, v, &r, &m);
    } else {
        func_0038E2E8(D_004A28AC_2A00, v, &r, &m);
    }
}
#endif

INCLUDE_ASM("ui/uitext", func_003A2BC8);
//100%
INCLUDE_ASM("ui/uitext", func_003A3280);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a1, int a2);
extern void* D_004941B8[];

struct func_003A3280_s {
    char pad0[0x8];
    void** vtbl; // 0x8
    char padC[0x74 - 0xC];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int mid : 15;
    unsigned int hi : 15;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

extern "C" func_003A3280_s* func_003A3280(func_003A3280_s* self, int a1, int a2)
{
    func_0039FB30(self, a1, a2);
    self->vtbl = D_004941B8;
    self->b0 = 0;
    self->b1 = 0;
    self->hi = 0;
    self->unk78 = 0;
    self->unk7C = 0;
    self->unk80 = 0;
    self->unk84 = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A32F0);
#ifdef SKIP_ASM
extern "C" void func_0039FC48(void* self, int flags);
extern void* D_004941B8[];

extern "C" void func_003A32F0(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004941B8;
    if (*(void**)((char*)self + 0x7C) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x7C));
    }
    if (*(void**)((char*)self + 0x80) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x80));
    }
    if (*(void**)((char*)self + 0x84) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x84));
    }
    if (*(void**)((char*)self + 0x88) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x88));
    }
    if (*(void**)((char*)self + 0x8C) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x8C));
    }
    func_0039FC48(self, flags);
}
#endif

//100%
INCLUDE_ASM("ui/uitext", func_003A3398);
#ifdef SKIP_ASM
struct func_003A3398_sColor {
    float r;
    float g;
    float b;
    float a;
};

extern "C" void func_003A3398(void* self, func_003A3398_sColor* c)
{
    func_003A3398_sColor tmp = *c;
    unsigned int i;
    *(func_003A3398_sColor*)((char*)self + 0x1C) = *c;
    if (*(func_003A3398_sColor**)((char*)self + 0x7C) == 0) {
        return;
    }
    tmp.r = (int)(c->r * 255.0f);
    tmp.g = (int)(c->g * 255.0f);
    tmp.b = (int)(c->b * 255.0f);
    tmp.a = (int)(c->a * 255.0f);
    for (i = 0; i < *(unsigned int*)((char*)self + 0x74) >> 17; i++) {
        (*(func_003A3398_sColor**)((char*)self + 0x7C))[i] = tmp;
    }
}
#endif

