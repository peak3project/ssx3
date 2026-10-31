#include "common.h"

struct cUIThing {
    char pad_0x00[0x3C];
    unsigned short* mEvents; // 0x3C
};

//100%
INCLUDE_ASM("ui/uithing", cUIThing_getKeyframerEvent__FP8cUIThingi);
#ifdef SKIP_ASM
unsigned short cUIThing_getKeyframerEvent(cUIThing* self, int x)
{
    signed char idx = (signed char)x;
    if (self->mEvents != 0) {
        return self->mEvents[idx];
    }
    return 0xFFFF;
}
#endif

INCLUDE_ASM("ui/uithing", func_0039FFA0);

//100%
INCLUDE_ASM("ui/uithing", func_003A0000);
#ifdef SKIP_ASM
extern "C" void func_003975E0(void*, void*, unsigned char, unsigned short);
extern "C" void func_003974B0(void*, unsigned char);

extern "C" void func_003A0000(void* self, unsigned short ev)
{
    void* a = *(void**)((char*)self + 0xC);
    if (a != 0) {
        func_003975E0(a, self, *(unsigned char*)((char*)self + 0x10), ev);
        func_003974B0(*(void**)((char*)self + 0xC), *(unsigned char*)((char*)self + 0x10));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A0048);
#ifdef SKIP_ASM
struct sUIThing0048 {
    char pad0[0x14];
    unsigned int b0 : 13;
    unsigned int frame : 6;   // 0x14 bits 13..18
    unsigned int b19 : 13;
    char pad18[0x4];
    float r;                  // 0x1C
    float g;                  // 0x20
    float b;                  // 0x24
    float a;                  // 0x28
    float rotX;               // 0x2C
    float rotY;               // 0x30
    float rotZ;               // 0x34
    char pad38[0xC];
    float x;                  // 0x44
    float y;                  // 0x48
    char pad4C[0x4];
    float scaleX;             // 0x50
    float scaleY;             // 0x54
    char pad58[0x8];
    float f60;                // 0x60
    float f64;                // 0x64
};

// Sets one animatable property (position, rotation, scale, colour, frame...) from a keyframe value.
extern "C" void func_003A0048(sUIThing0048* self, unsigned short key, float v)
{
    switch (key) {
    case 0:
        self->x = v;
        break;
    case 1:
        self->y = v;
        break;
    case 9:
        self->scaleX = v * 0.01f;
        break;
    case 10:
        self->scaleY = v * 0.01f;
        break;
    case 3:
        self->rotX = v * 0.017444444820284843f;
        break;
    case 4:
        self->rotY = v * 0.017444444820284843f;
        break;
    case 5:
        self->rotZ = v * 0.017444444820284843f;
        break;
    case 12:
        self->frame = (int)v;
        break;
    case 13:
        self->r = v * 0.003921568859368563f;
        break;
    case 14:
        self->g = v * 0.003921568859368563f;
        break;
    case 15:
        self->b = v * 0.003921568859368563f;
        break;
    case 16:
        self->a = v * 0.003921568859368563f;
        break;
    case 6:
        self->f60 = v;
        break;
    case 7:
        self->f64 = v;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A0158);
#ifdef SKIP_ASM
struct sUIKey0158 {
    short key;
    short value;
};

// Applies a list of (property, value) keyframe pairs; same mapping as func_003A0048.
extern "C" void func_003A0158(sUIThing0048* self, unsigned int count, sUIKey0158* keys)
{
    for (unsigned int i = 0; i < count; i++, keys++) {
        float v = keys->value;
        switch (keys->key) {
        case 0:
            self->x = v;
            break;
        case 1:
            self->y = v;
            break;
        case 9:
            self->scaleX = v * 0.01f;
            break;
        case 10:
            self->scaleY = v * 0.01f;
            break;
        case 3:
            self->rotX = v * 0.017444444820284843f;
            break;
        case 4:
            self->rotY = v * 0.017444444820284843f;
            break;
        case 5:
            self->rotZ = v * 0.017444444820284843f;
            break;
        case 12:
            self->frame = (int)v;
            break;
        case 13:
            self->r = v * 0.003921568859368563f;
            break;
        case 14:
            self->g = v * 0.003921568859368563f;
            break;
        case 15:
            self->b = v * 0.003921568859368563f;
            break;
        case 16:
            self->a = v * 0.003921568859368563f;
            break;
        case 6:
            self->f60 = v;
            break;
        case 7:
            self->f64 = v;
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A0290);
#ifdef SKIP_ASM
struct sUIVec3 {
    float x, y, z;
};

struct sUIThingPos {
    char pad0[0x40];
    sUIThingPos* parent;    // 0x40
    sUIVec3 pos;            // 0x44
};

extern "C" void func_003A0290(sUIThingPos* self, sUIVec3* out)
{
    *out = self->pos;
    for (sUIThingPos* p = self->parent; p != 0; p = p->parent) {
        sUIVec3 v = p->pos;
        out->x += v.x;
        out->y += v.y;
        out->z += v.z;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A0318);
#ifdef SKIP_ASM
extern "C" int func_003A0318(void* self, int a1)
{
    self = (char*)self + ((signed char)a1 << 2);
    return *(int*)((char*)self + 0x6c);
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A0330);
#ifdef SKIP_ASM
extern "C" void func_003A0330(void* self, int a1, int a2)
{
    self = (char*)self + ((signed char)a1 << 2);
    *(int*)((char*)self + 0x6c) = a2;
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A0348);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a1, int a2);
extern void* D_00494588[];

struct func_003A0348_sQuad {
    int a, b, c, d;
};
extern func_003A0348_sQuad D_004C66C8;

struct func_003A0348_sObj {
    char base[0x74];
    unsigned char flags;
    char pad75[0x88 - 0x75];
    func_003A0348_sQuad q88;
    func_003A0348_sQuad q98;
    int fA8;
    int fAC;
    int fB0;
    int fB4;
    short fB8;
    short fBA;
};

extern "C" func_003A0348_sObj* func_003A0348(func_003A0348_sObj* self, int a1, int a2)
{
    func_0039FB30(self, a1, a2);
    *(void***)((char*)self + 8) = D_00494588;
    self->flags = (self->flags | 4) & 0x87;
    self->fA8 = 0;
    self->fAC = 0;
    self->fB0 = 0;
    self->fB4 = 0;
    self->fB8 = 0;
    self->fBA = 0;
    self->q88 = D_004C66C8;
    self->q98 = D_004C66C8;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A03F0);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText*, int);
// PORT: func_0039FE00 really takes (self, data); other units declare it with one argument.
void* func_0039FE00_2(void* self, void* data) __asm__("func_0039FE00");

struct sUIColor03F0 {
    float r, g, b, a;
    sUIColor03F0() {}
    sUIColor03F0(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};
struct sUIVt03F0 { short delta; short index; void (*fn)(void*, int); };
struct sUIThing03F0 {
    char pad0[0x8];
    sUIVt03F0* vt;              // 0x8
    char padC[0x74 - 0xC];
    unsigned int mode : 2;      // 0x74
    unsigned int rest : 30;
    sUIColor03F0 color;         // 0x78
};
struct sUIData03F0 {
    char pad0[0x20];
    unsigned char mode;         // 0x20
    char pad21;
    unsigned char vis;          // 0x22
    char pad23;
    int textId;                 // 0x24
    unsigned char r, g, b, a;   // 0x28
};

extern "C" void func_003A03F0(sUIThing03F0* self, sUIData03F0* data)
{
    func_0039FE00_2(self, data);
    self->mode = data->mode & 3;
    self->vt[23].fn((char*)self + self->vt[23].delta, data->vis & 1);
    cUIText_setUnicodeStringByID((cUIText*)self, data->textId);
    int f = *(int*)((char*)self + 0x74) >> 2;
    if (f & 1) {
        self->color = sUIColor03F0(data->r * 0.003921568859368563f, data->g * 0.003921568859368563f,
                                   data->b * 0.003921568859368563f, data->a * 0.003921568859368563f);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A04F0);
#ifdef SKIP_ASM
extern "C" int func_003A04F0(void* self)
{
    void* p = *(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x5c) + 0xd0) + 0x10);
    if (p != 0) {
        return *(int*)((char*)*(void**)((char*)p + 0x8) + (*(unsigned char*)((char*)self + 0x74) & 3) * 12 + 0xC);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uithing", func_003A0528);
#ifdef SKIP_ASM
extern "C" void func_003A0D00(void* self, unsigned short* str);
extern "C" void cUIText_setUnicodeStringPrivate(void* self, unsigned short* str);

struct func_003A0528_sVEntry {
    short delta;
    short index;
    void* fn;
};

extern "C" void func_003A0528(void* self)
{
    int id = *(int*)((char*)self + 0xB0);
    if (id != 0) {
        void* a = *(void**)((char*)self + 0x5C);
        void* b = *(void**)((char*)a + 0xD0);
        void* c = *(void**)((char*)b + 0x10);
        char* loc = *(char**)((char*)c + 0x10);
        if (loc != 0) {
            func_003A0528_sVEntry* vt = *(func_003A0528_sVEntry**)(loc + 4);
            unsigned short* str = ((unsigned short* (*)(void*, int))vt[4].fn)(loc + vt[4].delta, id);
            if (str != 0) {
                int f14 = *(int*)((char*)self + 0x14) >> 7;
                if ((f14 & 1) || ((*(int*)((char*)self + 0x74) >> 6) & 1)) {
                    func_003A0D00(self, str);
                } else {
                    cUIText_setUnicodeStringPrivate(self, str);
                }
            }
            func_003A0528_sVEntry* vt2 = *(func_003A0528_sVEntry**)((char*)self + 8);
            ((void (*)(void*, int))vt2[5].fn)((char*)self + vt2[5].delta, 1);
        }
    }
}
#endif

