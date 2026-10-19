#include "common.h"

// Flag words at cUIVector + 0x14 and + 0x74. The setters take an int and store it into a
// bool bitfield: that int->bool conversion is the `sltu` in their asm.
struct sUIVectorFlags {
    bool bit0 : 1;
    bool bit1 : 1;
    bool bit2 : 1;
    bool bit3 : 1;
    bool bit4 : 1;
    bool bit5 : 1;
    bool bit6 : 1;
};

INCLUDE_ASM("ui/uivector", cUIVector_setUIData);

//100%
INCLUDE_ASM("ui/uivector", func_003A36D0);
#ifdef SKIP_ASM
struct sV3_36D0 { float x, y, z; };
struct sUV_36D0 { float u, v; };
struct sCol_36D0 { float r, g, b, a; };
struct sCount_36D0 {
    unsigned int flag : 1;
    unsigned int pad1 : 1;
    unsigned int mode : 15;
    unsigned int count : 15;
};
struct cUIVector_36D0 {
    char pad0[0x74];
    sCount_36D0 cnt;    // 0x74
    char pad78[0x4];
    sCol_36D0* cols;    // 0x7C
    sV3_36D0* verts;    // 0x80
    char pad84[0x4];
    sUV_36D0* uvs;      // 0x88
};
extern "C" void func_003A0048(void* self, unsigned short key, float v);

// Sets a keyframed property: keys < 0x15 go to the base thing, higher keys address per-vertex position/UV/colour.
extern "C" void func_003A36D0(cUIVector_36D0* self, unsigned short key, float v)
{
    if (self->verts == 0) {
        return;
    }
    if (key >= 0x15) {
        key -= 0x15;
        unsigned short idx = key / 9;
        if (idx >= self->cnt.count) {
            return;
        }
        switch ((unsigned short)(key % 9)) {
        case 0: self->verts[idx].x = v; break;
        case 1: self->verts[idx].y = v; break;
        case 2: self->verts[idx].z = v; break;
        case 3: self->uvs[idx].u = v; break;
        case 4: self->uvs[idx].v = v; break;
        case 5: self->cols[idx].r = v; break;
        case 6: self->cols[idx].g = v; break;
        case 7: self->cols[idx].b = v; break;
        case 8: self->cols[idx].a = v; break;
        }
    } else {
        func_003A0048(self, key, v);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A3808);
#ifdef SKIP_ASM
struct sV3_3808 { float x, y, z; };
struct sCol_3808 { float r, g, b, a; };
struct sCount_3808 {
    unsigned int flag : 1;
    unsigned int pad1 : 1;
    unsigned int mode : 15;
    unsigned int count : 15;
};
struct sBits_3808 {
    unsigned int lo : 13;
    unsigned int layer : 6;
    unsigned int hi : 13;
};
struct cUIVector_3808 {
    char pad0[0x14];
    sBits_3808 bits;    // 0x14
    char pad18[0x4];
    float r, g, b, a;   // 0x1C
    char pad2C[0x44 - 0x2C];
    float x;            // 0x44
    float y;            // 0x48
    char pad4C[0x4];
    float sx;           // 0x50
    float sy;           // 0x54
    char pad58[0x60 - 0x58];
    float w;            // 0x60
    float h;            // 0x64
    char pad68[0x74 - 0x68];
    sCount_3808 cnt;    // 0x74
    char pad78[0x4];
    sCol_3808* cols;    // 0x7C
    sV3_3808* verts;    // 0x80
};
struct sKey_3808 {
    short key;
    short value;
};

// Applies a list of (key, value) pairs: keys < 0x15 set base properties, higher keys address per-vertex data.
extern "C" void func_003A3808(cUIVector_3808* self, unsigned int n, sKey_3808* keys)
{
    if (self->verts == 0) {
        return;
    }
    for (unsigned int i = 0; i < n; i++, keys++) {
        float v = (float)keys->value;
        int key = keys->key;
        if (key >= 0x15) {
            key -= 0x15;
            unsigned short idx = key / 9;
            if (idx >= self->cnt.count) {
                continue;
            }
            switch (key % 9) {
            case 0: self->verts[idx].x = v; break;
            case 1: self->verts[idx].y = v; break;
            case 2: self->verts[idx].z = v; break;
            case 5: self->cols[idx].r = v; break;
            case 6: self->cols[idx].g = v; break;
            case 7: self->cols[idx].b = v; break;
            case 8: self->cols[idx].a = v; break;
            }
        } else {
            switch (key) {
            case 0: self->x = v; break;
            case 1: self->y = v; break;
            case 9: self->sx = v * 0.01f; break;
            case 10: self->sy = v * 0.01f; break;
            case 12: self->bits.layer = (int)v; break;
            case 13: self->r = v * (1.0f / 255.0f); break;
            case 14: self->g = v * (1.0f / 255.0f); break;
            case 15: self->b = v * (1.0f / 255.0f); break;
            case 16: self->a = v * (1.0f / 255.0f); break;
            case 6: self->w = v; break;
            case 7: self->h = v; break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A39F8);
#ifdef SKIP_ASM
// PORT: func_004139F8 is libgcc's __fixunssfsi (float -> unsigned); called by its address name.
extern "C" unsigned int func_004139F8(float f);
extern void* D_004A289C;

struct sV3_3A39F8 {
    float x, y, z;
};

struct sV4_3A39F8 {
    float v[4];
} __attribute__((aligned(16)));

struct sCol_3A39F8 {
    float r, g, b, a;
};

struct sVtx_3A39F8 {
    float s;
    float t;
    float q;
    int padC;
    int col[4];         // 0x10
    sV4_3A39F8 pos;     // 0x20
};

struct sCount_3A39F8 {
    unsigned int flag : 1;
    unsigned int pad1 : 1;
    unsigned int mode : 15;
    unsigned int count : 15;
};

struct sFlags14_3A39F8 {
    unsigned char b14;
    unsigned char layer : 5;
};

struct sRS_3A39F8 {
    int f0;
    int f4;
    int f8;
    int fC;
    short f10;
};

struct sVE_3A39F8 { short delta; short index; void* fn; };

typedef void (*tDraw_3A39F8)(void*, int, int, void*, void*, int, void*, void*);
typedef void (*tDraw2_3A39F8)(void*, int, void*, int);

static inline void SetCol_3A39F8(sVtx_3A39F8& vtx, int k, float v)
{
    vtx.col[k] = func_004139F8(v * 0.5f);
}

static inline void AddPos_3A39F8(sV4_3A39F8& p, int k, float d)
{
    p.v[k] += d;
}

extern "C" void func_003A39F8(char* self, float x, float y)
{
    if (*(sV3_3A39F8**)(self + 0x80) == 0)
        return;
    for (unsigned int i = 0; i < ((sCount_3A39F8*)(self + 0x74))->count; i++)
    {
        (*(sV3_3A39F8**)(self + 0x84))[i] = (*(sV3_3A39F8**)(self + 0x80))[i];
        (*(sV3_3A39F8**)(self + 0x84))[i].x *= *(float*)(self + 0x50);
        (*(sV3_3A39F8**)(self + 0x84))[i].y *= *(float*)(self + 0x54);
    }
    sRS_3A39F8* rs = *(sRS_3A39F8**)((char*)D_004A289C + 0xE84);
    rs->f8 = (rs->f8 & ~0x3E0) | (((((sFlags14_3A39F8*)(self + 0x14))->layer) + 9) << 5 & 0x3E0);
    *(short*)(*(char**)((char*)D_004A289C + 0xE84) + 0x10) = -1;
    if (((sCount_3A39F8*)(self + 0x74))->flag)
    {
        float pos[3];
        pos[0] = *(float*)(self + 0x44) + x;
        pos[1] = *(float*)(self + 0x48) + y;
        pos[2] = 0.0f;
        char* g = (char*)D_004A289C;
        sVE_3A39F8* vt = *(sVE_3A39F8**)(g + 0x10D8);
        ((tDraw_3A39F8)vt[72].fn)(g + vt[72].delta, ((sCount_3A39F8*)(self + 0x74))->mode, ((sCount_3A39F8*)(self + 0x74))->count,
                                  *(void**)(self + 0x78), *(void**)(self + 0x84), 0, *(void**)(self + 0x7C), pos);
        return;
    }
    if (*(sVtx_3A39F8**)(self + 0x8C) == 0)
        return;
    for (unsigned int i = 0; i < ((sCount_3A39F8*)(self + 0x74))->count; i++)
    {
        sV4_3A39F8 tt;
        tt.v[0] = (*(sV3_3A39F8**)(self + 0x84))[i].x;
        tt.v[1] = (*(sV3_3A39F8**)(self + 0x84))[i].y;
        tt.v[2] = (*(sV3_3A39F8**)(self + 0x84))[i].z;
        tt.v[3] = 1.0f;
        (*(sVtx_3A39F8**)(self + 0x8C))[i].pos = tt;
        AddPos_3A39F8((*(sVtx_3A39F8**)(self + 0x8C))[i].pos, 0, *(float*)(self + 0x44) + x);
        AddPos_3A39F8((*(sVtx_3A39F8**)(self + 0x8C))[i].pos, 1, *(float*)(self + 0x48) + y);
        (*(sVtx_3A39F8**)(self + 0x8C))[i].q = 1.0f;
        (*(sVtx_3A39F8**)(self + 0x8C))[i].s = 0.0f;
        (*(sVtx_3A39F8**)(self + 0x8C))[i].t = 0.0f;
        SetCol_3A39F8((*(sVtx_3A39F8**)(self + 0x8C))[i], 3, (*(sCol_3A39F8**)(self + 0x7C))[i].r);
        SetCol_3A39F8((*(sVtx_3A39F8**)(self + 0x8C))[i], 0, (*(sCol_3A39F8**)(self + 0x7C))[i].g);
        SetCol_3A39F8((*(sVtx_3A39F8**)(self + 0x8C))[i], 1, (*(sCol_3A39F8**)(self + 0x7C))[i].b);
        SetCol_3A39F8((*(sVtx_3A39F8**)(self + 0x8C))[i], 2, (*(sCol_3A39F8**)(self + 0x7C))[i].a);
    }
    char* g = (char*)D_004A289C;
    sVE_3A39F8* vt = *(sVE_3A39F8**)(g + 0x10D8);
    ((tDraw2_3A39F8)vt[73].fn)(g + vt[73].delta, ((sCount_3A39F8*)(self + 0x74))->count, *(void**)(self + 0x8C), 0);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A3D28);
#ifdef SKIP_ASM
extern "C" void func_003975E0(void*, void*, unsigned char, unsigned short);
extern "C" void func_003974B0(void*, unsigned char);

extern "C" void func_003A3D28(void* self, unsigned short ev)
{
    void* a = *(void**)((char*)self + 0xC);
    if (a != 0) {
        func_003975E0(a, self, *(unsigned char*)((char*)self + 0x10), ev);
        func_003974B0(*(void**)((char*)self + 0xC), *(unsigned char*)((char*)self + 0x10));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A3D70);
#ifdef SKIP_ASM
struct func_003A3D70_sVec3 {
    float x;
    float y;
    float z;
};

extern func_003A3D70_sVec3 D_004FF0D8;

extern "C" void func_003A3D70(void* self, func_003A3D70_sVec3* out)
{
    if (*(func_003A3D70_sVec3**)((char*)self + 0x80) == 0) {
        return;
    }
    *out = D_004FF0D8;
    float minX = 1000.0f;
    float maxX = -1000.0f;
    float minY = 1000.0f;
    float maxY = -1000.0f;
    unsigned int i;
    for (i = 0; i < *(unsigned int*)((char*)self + 0x74) >> 17; i++) {
        func_003A3D70_sVec3* p = &(*(func_003A3D70_sVec3**)((char*)self + 0x80))[i];
        if (p->x < minX) {
            minX = p->x;
        }
        if (maxX < p->x) {
            maxX = p->x;
        }
        if (p->y < minY) {
            minY = p->y;
        }
        if (maxY < p->y) {
            maxY = p->y;
        }
    }
    out->x = maxX - minX;
    out->y = maxY - minY;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A3E38);
#ifdef SKIP_ASM
struct func_003A3E38_sVec3 {
    float x;
    float y;
    float z;
};

struct func_003A3E38_sCount74 {
    unsigned int lo : 17;
    unsigned int count : 15;
};

extern "C" void func_003A3E38(void* self, func_003A3E38_sVec3* off)
{
    if (((func_003A3E38_sCount74*)((char*)self + 0x74))->count == 4) {
        signed char i;
        for (i = 1; i < 4; i++) {
            (*(func_003A3E38_sVec3**)((char*)self + 0x80))[i] = (*(func_003A3E38_sVec3**)((char*)self + 0x80))[0];
        }
        (*(func_003A3E38_sVec3**)((char*)self + 0x80))[1].x += off->x;
        (*(func_003A3E38_sVec3**)((char*)self + 0x80))[3].y += off->y;
        (*(func_003A3E38_sVec3**)((char*)self + 0x80))[2].x += off->x;
        (*(func_003A3E38_sVec3**)((char*)self + 0x80))[2].y += off->y;
    }
    *(func_003A3E38_sVec3*)((char*)self + 0x60) = *off;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A3F08);
#ifdef SKIP_ASM
extern "C" void* func_003A3F08(void* self, ...)
{
    return self;
}
#endif

INCLUDE_ASM("ui/uivector", func_003A3F48);

//100%
INCLUDE_ASM("ui/uivector", func_003A4778);
#ifdef SKIP_ASM
extern void* D_00494D08[];
extern "C" void* func_003A4778(void* self) {
    *(void***)((char*)self + 0x10) = D_00494D08;
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4790);
#ifdef SKIP_ASM
extern "C" int func_003A4790(void **arg0) {
    return (*(int *)((char*)(*arg0) + (8)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A47A0);
#ifdef SKIP_ASM
extern "C" void func_003A47A0(void *arg0, short arg1) {
    (*(short *)((char*)(arg0) + (0xA))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A47A8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern void* D_00494CE8[];

extern "C" void func_003A47A8(int* self, int flags)
{
    *(void***)self = D_00494CE8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A47D8);
#ifdef SKIP_ASM
extern void* D_00494CC0[];

extern "C" void *func_003A47D8(void *arg0) {
    (*(void **)((char*)(arg0) + (4))) = arg0;
    (*(int **)((char*)(arg0) + (8))) = &(*(int*)&D_00494CC0);
    (*(void **)((char*)(arg0) + (0))) = arg0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A47F8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_003A4868(void* self);

extern void* D_00494CC0[];

extern "C" void func_003A47F8(int* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00494CC0;
    func_003A4868(self);
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

extern "C" void cListNode_removeFromList(void*);

//100%
INCLUDE_ASM("ui/uivector", func_003A4848);
#ifdef SKIP_ASM
extern "C" int func_003A4848(int *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4850);
#ifdef SKIP_ASM
extern "C" int func_003A4850(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4858);
#ifdef SKIP_ASM
extern "C" void func_003A4858(int *arg0, int arg1) {
    *arg0 = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4860);
#ifdef SKIP_ASM
extern "C" void func_003A4860(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4868);
#ifdef SKIP_ASM
extern "C" void func_003A4868(void* self)
{
    cListNode_removeFromList(self);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4888);
#ifdef SKIP_ASM
extern "C" void* func_00397948(void*);
extern void* D_00494C98[];
extern void* D_00494CC0[];

extern "C" void func_003A4888(void* self, int flags)
{
    *(void***)((char*)self + 0x18) = D_00494C98;
    func_00397948(self);
    *(void***)((char*)self + 0x14) = D_00494CC0;
    func_003A4868((char*)self + 0xC);
    *(void***)((char*)self + 0x8) = D_00494CC0;
    func_003A4868(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4900);
#ifdef SKIP_ASM
struct sFlags_6548;
extern "C" sFlags_6548* func_003A6548(sFlags_6548* f);
extern void* D_00494BD8[];

extern "C" void* func_003A4900(char* self)
{
    *(char**)(self + 0x4) = self;
    *(char**)(self + 0x0) = self;
    *(void***)(self + 0x8) = D_00494BD8;
    func_003A6548((sFlags_6548*)(self + 0x14));
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4940);
#ifdef SKIP_ASM
extern "C" int func_003A4940(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC))) != 0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4950);
#ifdef SKIP_ASM
extern "C" int func_003A4950(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4958);
#ifdef SKIP_ASM
extern "C" int func_003A4958(void *arg0) {
    return ((*(int *)((char*)(arg0) + (0x14))) ^ 1) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4968);
#ifdef SKIP_ASM
extern "C" int func_003A4968(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14))) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4978);
#ifdef SKIP_ASM
extern "C" int func_003A4978(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x14))) >> 1) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4988);
#ifdef SKIP_ASM
extern "C" int func_003A4988(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x14))) >> 2) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4998);
#ifdef SKIP_ASM
extern "C" int func_003A4998(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x14))) >> 3) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A49A8);
#ifdef SKIP_ASM
extern "C" int func_003A49A8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x14))) >> 4) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A49B8);
#ifdef SKIP_ASM
extern "C" int func_003A49B8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x14))) >> 5) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A49C8);
#ifdef SKIP_ASM
extern "C" int func_003A49C8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x14))) >> 6) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A49D8);
#ifdef SKIP_ASM
extern "C" int func_003A49D8(void *arg0) {
    int f = *(int *)((char*)arg0 + 0x14) >> 7;
    return f & 1;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A49E8);
#ifdef SKIP_ASM
extern "C" void func_003A49E8(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x14))->bit1 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4A08);
#ifdef SKIP_ASM
extern "C" void func_003A4A08(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x14))->bit2 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4A28);
#ifdef SKIP_ASM
extern "C" void func_003A4A28(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x14))->bit3 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4A48);
#ifdef SKIP_ASM
extern "C" void func_003A4A48(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x14))->bit4 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4A68);
#ifdef SKIP_ASM
extern "C" void func_003A4A68(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x14))->bit5 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4A88);
#ifdef SKIP_ASM
extern "C" void func_003A4A88(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x14))->bit6 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4AA8);
#ifdef SKIP_ASM
struct sUIVectorFlags8 {
    bool bit0 : 1;
    bool bit1 : 1;
    bool bit2 : 1;
    bool bit3 : 1;
    bool bit4 : 1;
    bool bit5 : 1;
    bool bit6 : 1;
    bool bit7 : 1;
};
extern "C" void func_003A4AA8(void* self, int enable)
{
    ((sUIVectorFlags8*)((char*)self + 0x14))->bit7 = enable;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4AC8);
#ifdef SKIP_ASM
extern "C" int func_003A4AC8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4AD0);
#ifdef SKIP_ASM
extern "C" void func_003A4AD0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4AD8);
#ifdef SKIP_ASM
extern "C" void func_003A4AD8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = (int) (((*(int *)((char*)(arg0) + (0x14))) & ~1) | (arg1 & 1));
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4AF8);
#ifdef SKIP_ASM
// 16 bytes, 4-byte aligned (copied with ldl/ldr pairs). Float fields are a guess.
struct sVec4 {
    float x;
    float y;
    float z;
    float w;
};

extern "C" void func_003A4AF8(void* self, sVec4* in)
{
    *(sVec4*)((char*)self + 0x1C) = *in;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4B20);
#ifdef SKIP_ASM
extern "C" int func_003A4B20(int arg0) {
    return arg0 + 0x1C;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4B28);
#ifdef SKIP_ASM
extern "C" void func_003A4B28(char* self, sVec4* out)
{
    *out = *(sVec4*)(self + 0x1C);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4B50);
#ifdef SKIP_ASM
extern "C" void func_003A4B50(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x34))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4B58);
#ifdef SKIP_ASM
extern "C" float func_003A4B58(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x34)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4B60);
#ifdef SKIP_ASM
extern "C" int func_003A4B60(void *arg0) {
    return ((unsigned int) (*(unsigned int *)((char*)(arg0) + (0x14))) >> 8) & 0x1F;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4B70);
#ifdef SKIP_ASM
extern "C" void func_003A4B70(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = (int) (((*(int *)((char*)(arg0) + (0x14))) & ~0x1F00) | ((arg1 & 0x1F) << 8));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4B90);
#ifdef SKIP_ASM
extern "C" void func_003A4B90(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = (int) (((*(int *)((char*)(arg0) + (0x14))) & 0xFFF81FFF) | ((arg1 & 0x3F) << 0xD));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4BB8);
#ifdef SKIP_ASM
extern "C" int func_003A4BB8(void *arg0) {
    return ((unsigned int) (*(unsigned int *)((char*)(arg0) + (0x14))) >> 0xD) & 0x3F;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4BC8);
#ifdef SKIP_ASM
extern "C" void func_003A4BC8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x38))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4BD0);
#ifdef SKIP_ASM
extern "C" int func_003A4BD0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x38)));
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4BD8__FPv);
#ifdef SKIP_ASM
int func_003A4BD8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4BE0__FPv);
#ifdef SKIP_ASM
void func_003A4BE0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4BE8__FPv);
#ifdef SKIP_ASM
void func_003A4BE8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4BF0__FPv);
#ifdef SKIP_ASM
void func_003A4BF0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4BF8);
#ifdef SKIP_ASM
extern "C" void func_003A4BF8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x40))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4C00);
#ifdef SKIP_ASM
extern "C" int func_003A4C00(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x40)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4C08);
#ifdef SKIP_ASM
struct sVec3_003A4C08 { float x; float y; float z; };
extern "C" void func_003A4C08(char* self, sVec3_003A4C08* out)
{
    *out = *(sVec3_003A4C08*)(self + 0x44);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4C28);
#ifdef SKIP_ASM
struct sVec3_003A4C28 { float x; float y; float z; };
extern "C" void func_003A4C28(char* self, sVec3_003A4C28* out)
{
    *(sVec3_003A4C28*)(self + 0x44) = *out;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4C48);
#ifdef SKIP_ASM
struct sVec3_003A4C48 { float x; float y; float z; };
extern "C" void func_003A4C48(char* self, sVec3_003A4C48* out)
{
    *out = *(sVec3_003A4C48*)(self + 0x50);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4C68);
#ifdef SKIP_ASM
struct sVec3_003A4C68 { float x; float y; float z; };
extern "C" void func_003A4C68(char* self, sVec3_003A4C68* out)
{
    *(sVec3_003A4C68*)(self + 0x50) = *out;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4C88);
#ifdef SKIP_ASM
extern "C" int func_003A4C88(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5C)));
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4C90);
#ifdef SKIP_ASM
// 12 bytes, 4-byte aligned (copied with ldl/ldr + lw). Float fields are a guess.
struct sVec3 {
    float x;
    float y;
    float z;
};

extern "C" void func_003A4C90(void* self, sVec3* out)
{
    *out = *(sVec3*)((char*)self + 0x60);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4CB0);
#ifdef SKIP_ASM
extern "C" void func_003A4CB0(void* self, sVec3* in)
{
    *(sVec3*)((char*)self + 0x60) = *in;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4CD0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern void* D_00494CE8[];

extern "C" void func_003A4CD0(int* self, int flags)
{
    *(void***)self = D_00494CE8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4D00);
#ifdef SKIP_ASM
struct sVEntry3A4D00 {
    short delta;
    short index;
    int (*fn)(void*, void*);
};

extern "C" void* func_003A4D00(void* self, void* obj)
{
    sVEntry3A4D00* vt = *(sVEntry3A4D00**)((char*)obj + 8);
    if (vt[0xF].fn((char*)obj + vt[0xF].delta, *(void**)((char*)self + 4)) == 0) {
        return 0;
    }
    return obj;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4D40);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern void* D_00494CE8[];

extern "C" void func_003A4D40(int* self, int flags)
{
    *(void***)self = D_00494CE8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4D70);
#ifdef SKIP_ASM
class func_003A4D70_cVirt {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int);
};

extern "C" int func_003A4D70(void* self, func_003A4D70_cVirt* obj)
{
    obj->v07(*(int*)((char*)self + 0x4));
    return 0;
}
#endif

extern void* D_00494AA8[];
extern "C" void* func_0039FC48(void*);

//100%
INCLUDE_ASM("ui/uivector", func_003A4DA8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern void* D_0046DD60[];

extern "C" void func_003A4DA8(int* self, int flags)
{
    *(void***)self = D_0046DD60;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4DD8);
#ifdef SKIP_ASM
extern "C" void func_003A4DD8(void) {

}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4DE0);
#ifdef SKIP_ASM
extern "C" void func_003A4DE0(void) {

}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4DE8);
#ifdef SKIP_ASM
extern "C" void func_003A4DE8(void) {

}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4DF0);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern "C" void* func_0021CCC8(void* p);
extern void* D_00494AA8[];

extern "C" void* func_003A4DF0(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_00494AA8;
    func_0021CCC8(self + 0x74);
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4E38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039FB30_self(void* self) __asm__("func_0039FB30");
extern "C" void* func_0021CCC8(void* p);
extern void* D_00494AA8[];

extern "C" void* func_003A4E38(char* self)
{
    func_0039FB30_self(self);
    *(void***)(self + 0x8) = D_00494AA8;
    func_0021CCC8(self + 0x74);
    *(int*)(self + 0x78) = -1;
    *(int*)(self + 0x7C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4E80__FPv);
#ifdef SKIP_ASM
void* func_003A4E80(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_00494AA8;
    return func_0039FC48(self);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4EA8__FPv);
#ifdef SKIP_ASM
int func_003A4EA8(void* self)
{
    return 0x11;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A4EB0);
#ifdef SKIP_ASM
extern "C" unsigned char *func_003A4EB0(unsigned char *arg0) {
    *arg0 &= 0xF0;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4EC8);
#ifdef SKIP_ASM
extern "C" int func_003A4EC8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x74))) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4ED8);
#ifdef SKIP_ASM
extern "C" void func_003A4ED8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x74))) = (int) (((*(int *)((char*)(arg0) + (0x74))) & ~1) | (arg1 != 0));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4EF8);
#ifdef SKIP_ASM
extern "C" int func_003A4EF8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 1) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F08);
#ifdef SKIP_ASM
extern "C" void func_003A4F08(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit1 = enable;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F28);
#ifdef SKIP_ASM
extern "C" int func_003A4F28(void *arg0) {
    return ((*(int *)((char*)(arg0) + (0x74))) & 0xC) != 0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F38);
#ifdef SKIP_ASM
struct sUIVectorFlagsB {
    bool bit0 : 1;
    bool bit1 : 1;
    bool bits23 : 2;
};
extern "C" void func_003A4F38(void* self, int enable)
{
    ((sUIVectorFlagsB*)((char*)self + 0x74))->bits23 = enable;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F58);
#ifdef SKIP_ASM
extern "C" int func_003A4F58(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F60);
#ifdef SKIP_ASM
extern "C" void func_003A4F60(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x7C))) = arg1;
    (*(int *)((char*)(arg0) + (0x78))) = -1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F70);
#ifdef SKIP_ASM
extern "C" int func_003A4F70(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x78)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F78);
#ifdef SKIP_ASM
extern "C" void func_003A4F78(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x78))) = arg1;
    (*(int *)((char*)(arg0) + (0x7C))) = 0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4F88);
#ifdef SKIP_ASM
struct sVec2 { float x; float y; };
extern "C" sVec2* func_003A4F88(sVec2* out, char* self)
{
    *out = *(sVec2*)(self + 0x80);
    return out;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4FA0);
#ifdef SKIP_ASM
extern "C" void func_003A4FA0(char* self, sVec2* in)
{
    *(sVec2*)(self + 0x80) = *in;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4FB8);
#ifdef SKIP_ASM
extern "C" void func_003A4FB8(char* self, float x, float y)
{
    sVec2 v;
    v.x = x;
    v.y = y;
    *(sVec2*)(self + 0x80) = v;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A4FE0);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern "C" void* func_003977E8(void* p);
extern void* D_004949E8[];

extern "C" void* func_003A4FE0(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_004949E8;
    func_003977E8(self + 0x74);
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5028);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039FB30_self(void* self) __asm__("func_0039FB30");
extern "C" void* func_003977E8(void* p);
extern void* D_004949E8[];

extern "C" void* func_003A5028(char* self)
{
    func_0039FB30_self(self);
    *(void***)(self + 0x8) = D_004949E8;
    func_003977E8(self + 0x74);
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5068);
#ifdef SKIP_ASM
extern void* D_004949E8[];
extern void* D_00494C98[];
extern void* D_00494CC0[];
// PORT: called here for its side effect only; declared void so the scheduling matches.
extern "C" void func_00397948_v(void* p) __asm__("func_00397948");
extern "C" void func_003A4868(void* p);
// PORT: the unit declares func_0039FC48 with one argument; the dtor chain passes the delete flag too.
extern "C" void func_0039FC48_2(void* self, int flag) __asm__("func_0039FC48");

// Destructor: restores the vtables, destroys the two vertex lists, then the base thing.
extern "C" void func_003A5068(char* self, int flag)
{
    *(void***)(self + 0x8) = D_004949E8;
    *(void***)(self + 0x8C) = D_00494C98;
    func_00397948_v(self + 0x74);
    *(void***)(self + 0x88) = D_00494CC0;
    func_003A4868(self + 0x80);
    *(void***)(self + 0x7C) = D_00494CC0;
    func_003A4868(self + 0x74);
    func_0039FC48_2(self, flag);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A50F8__FPv);
#ifdef SKIP_ASM
int func_003A50F8(void* self)
{
    return 0x10;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5100);
#ifdef SKIP_ASM
extern "C" void cList_first__FP5cList(int);

extern "C" void func_003A5100(int arg0) {
    cList_first__FP5cList(arg0 + 0x74);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5120);
#ifdef SKIP_ASM
extern "C" void func_00397858(int);

extern "C" void func_003A5120(int arg0) {
    func_00397858(arg0 + 0x74);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5140);
#ifdef SKIP_ASM
extern "C" void func_00397870(int);

extern "C" void func_003A5140(int arg0) {
    func_00397870(arg0 + 0x74);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5160);
#ifdef SKIP_ASM
extern "C" void cList_addToFront__FP5cListP9cListNode(int);

extern "C" void func_003A5160(int arg0) {
    cList_addToFront__FP5cListP9cListNode(arg0 + 0x74);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5180);
#ifdef SKIP_ASM
extern "C" void cList_addToEnd__FP5cListP9cListNode(int);

extern "C" void func_003A5180(int arg0) {
    cList_addToEnd__FP5cListP9cListNode(arg0 + 0x74);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A51A0);
#ifdef SKIP_ASM
class func_003A51A0_cVirt {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(void*);
};

extern "C" int func_003A51A0(void* a, func_003A51A0_cVirt* obj)
{
    return obj->v02(a);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A51D0);
#ifdef SKIP_ASM
class func_003A51D0_cFunctor {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(void*);
};

extern "C" void* func_00397A68(void* list, func_003A51D0_cFunctor* fn);

extern "C" void* func_003A51D0(void* self, func_003A51D0_cFunctor* fn)
{
    if (fn->v02(self) != 0) {
        return self;
    }
    return func_00397A68((char*)self + 0x74, fn);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5230);
#ifdef SKIP_ASM
extern void* D_00494928[];
// PORT: the other ctor in the unit calls this base ctor with (self, 0, 0)
extern "C" void* func_0039FB30_self(void* self) __asm__("func_0039FB30");
extern "C" void* func_003977E8(void* p);
extern "C" void* func_003A5338(void* self);

extern "C" void* func_003A5230(char* self)
{
    func_0039FB30_self(self);
    *(void***)(self + 0x8) = D_004949E8;
    func_003977E8(self + 0x74);
    *(void***)(self + 0x8) = D_00494928;
    func_003A5338(self + 0x90);
    *(unsigned char*)(self + 0xA4) = 0xFF;
    *(unsigned char*)(self + 0x95) = 0;
    *(unsigned char*)(self + 0x96) = 0;
    *(unsigned char*)(self + 0x97) = 0;
    *(unsigned char*)(self + 0x98) = 0;
    *(int*)(self + 0x9C) = 0;
    *(int*)(self + 0xA0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A52A0);
#ifdef SKIP_ASM
extern void* D_004949E8[];
extern void* D_00494C98[];
extern void* D_00494CC0[];
// PORT: called here for its side effect only; declared void so the scheduling matches.
extern "C" void func_00397948_v(void* p) __asm__("func_00397948");
extern "C" void func_003A4868(void* p);
// PORT: the unit declares func_0039FC48 with one argument; the dtor chain passes the delete flag too.
extern "C" void func_0039FC48_2(void* self, int flag) __asm__("func_0039FC48");

// Second destructor variant; same body as func_003A5068.
extern "C" void func_003A52A0(char* self, int flag)
{
    *(void***)(self + 0x8) = D_004949E8;
    *(void***)(self + 0x8C) = D_00494C98;
    func_00397948_v(self + 0x74);
    *(void***)(self + 0x88) = D_00494CC0;
    func_003A4868(self + 0x80);
    *(void***)(self + 0x7C) = D_00494CC0;
    func_003A4868(self + 0x74);
    func_0039FC48_2(self, flag);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5330__FPv);
#ifdef SKIP_ASM
int func_003A5330(void* self)
{
    return 0x13;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5338);
#ifdef SKIP_ASM
extern "C" void* func_003A5338(void* self)
{
    *(unsigned char*)self &= 0xf0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5350);
#ifdef SKIP_ASM
extern "C" int func_003A5350(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x90))) >> 1) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5360);
#ifdef SKIP_ASM
extern "C" void func_003A5360(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x90))->bit1 = enable;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5380);
#ifdef SKIP_ASM
extern "C" int func_003A5380(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x90))) >> 3) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5390);
#ifdef SKIP_ASM
extern "C" void func_003A5390(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x90))->bit3 = enable;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A53B0);
#ifdef SKIP_ASM
extern "C" int func_003A53B0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x90))) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A53C0);
#ifdef SKIP_ASM
extern "C" void func_003A53C0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x90))) = (int) (((*(int *)((char*)(arg0) + (0x90))) & ~1) | (arg1 != 0));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A53E0);
#ifdef SKIP_ASM
extern "C" unsigned char func_003A53E0(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x95)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A53E8);
#ifdef SKIP_ASM
extern "C" unsigned char func_003A53E8(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x98)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A53F0);
#ifdef SKIP_ASM
extern "C" unsigned char func_003A53F0(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x96)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A53F8);
#ifdef SKIP_ASM
extern "C" void func_003A53F8(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x95))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5400);
#ifdef SKIP_ASM
extern "C" void func_003A5400(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x96))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5408);
#ifdef SKIP_ASM
extern "C" void func_003A5408(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x98))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5410);
#ifdef SKIP_ASM
extern "C" int func_003A5410(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA0)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5418);
#ifdef SKIP_ASM
extern "C" unsigned char func_003A5418(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x95)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5420);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern "C" void* func_003A5508(void* p);
extern void* D_00494868[];

extern "C" void* func_003A5420(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_00494868;
    func_003A5508(self + 0x74);
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5468);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039FB30_self(void* self) __asm__("func_0039FB30");
extern "C" void* func_003A5508(void* self);
extern void* D_00494868[];

extern "C" void* func_003A5468(char* self)
{
    func_0039FB30_self(self);
    *(void***)(self + 0x8) = D_00494868;
    func_003A5508(self + 0x74);
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x7C) = 0;
    ((sUIVectorFlags*)(self + 0x14))->bit1 = 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A54B8);
#ifdef SKIP_ASM
extern void* D_00494868[];
extern "C" void func_0039BE70(void* self);
// PORT: the unit declares func_0039FC48 with one parameter; the real body is a
// destructor taking (self, flags). Bound to the same symbol with an asm label.
extern "C" void* func_0039FC48_dtor(void* self, int flags) __asm__("func_0039FC48");

extern "C" void func_003A54B8(void* self, int flags)
{
    *(void***)((char*)self + 8) = D_00494868;
    func_0039BE70(self);
    func_0039FC48_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5500__FPv);
#ifdef SKIP_ASM
int func_003A5500(void* self)
{
    return 0x15;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5508);
#ifdef SKIP_ASM
extern "C" void* func_003A5508(void* self)
{
    *(unsigned char*)((char*)self + 0x1) &= 0xc0;
    *(unsigned char*)((char*)self + 0x0) &= 0xc0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5528);
#ifdef SKIP_ASM
extern "C" int func_003A5528(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x78)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5530);
#ifdef SKIP_ASM
struct sVEntry5530 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_003A5530(char* self, void* obj)
{
    char* old = *(char**)(self + 0x78);
    if (old != 0) {
        sVEntry5530* vt = *(sVEntry5530**)(old + 8);
        vt[1].fn(old + vt[1].delta, 3);
    }
    *(void**)(self + 0x78) = obj;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5580);
#ifdef SKIP_ASM
extern "C" int func_003A5580(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5588);
#ifdef SKIP_ASM
struct sVEntry5588 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_003A5588(char* self, void* obj)
{
    char* old = *(char**)(self + 0x7C);
    if (old != 0) {
        sVEntry5588* vt = *(sVEntry5588**)(old + 8);
        vt[1].fn(old + vt[1].delta, 3);
    }
    *(void**)(self + 0x7C) = obj;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A55D8);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern "C" unsigned char *func_003A65A0(unsigned char *arg0);
extern "C" void *func_003A65B8(void *arg0);
extern void* D_00494798[];

extern "C" void* func_003A55D8(char* self)
{
    int i;
    func_0039FB30(self, 0, 0);
    *(void***)(self + 8) = D_00494798;
    func_003A65A0((unsigned char*)(self + 0x74));
    char* p = self + 0x98;
    for (i = 0x1F; i != -1; i--) {
        func_003A65B8(p);
        p += 0x14;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5658);
#ifdef SKIP_ASM
extern void* D_00494798[];
extern "C" void func_0039A670(void* self);
// PORT: the unit declares func_0039FC48 with one parameter; the real body is a
// destructor taking (self, flags). Bound to the same symbol with an asm label.
extern "C" void* func_0039FC48_dtor(void* self, int flags) __asm__("func_0039FC48");

extern "C" void func_003A5658(void* self, int flags)
{
    *(void***)((char*)self + 8) = D_00494798;
    func_0039A670(self);
    func_0039FC48_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A56A0__FPv);
#ifdef SKIP_ASM
int func_003A56A0(void* self)
{
    return 0x12;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A56A8);
#ifdef SKIP_ASM
extern "C" void func_003A56A8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x74))) = (int) (((*(int *)((char*)(arg0) + (0x74))) & ~3) | (arg1 & 3));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A56C8);
#ifdef SKIP_ASM
extern "C" int func_003A56C8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 2) & 1;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A56D8);
#ifdef SKIP_ASM
extern "C" void func_003A56D8(void* self, int enable) {
    ((sUIVectorFlags*)((char*)self + 0x74))->bit2 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A56F8);
#ifdef SKIP_ASM
extern "C" int func_003A56F8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 5) & 1;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5708);
#ifdef SKIP_ASM
extern "C" void func_003A5708(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit5 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5728);
#ifdef SKIP_ASM
extern "C" int func_003A5728(void *arg0) {
    int f = *(int *)((char*)arg0 + 0x14) >> 7;
    return f & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5738);
#ifdef SKIP_ASM
extern "C" void func_003A5738(void* self, int enable)
{
    ((sUIVectorFlags8*)((char*)self + 0x14))->bit7 = enable;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5758);
#ifdef SKIP_ASM
extern "C" void func_003A5758(char* self, sVec4* in)
{
    *(sVec4*)(self + 0x78) = *in;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5780);
#ifdef SKIP_ASM
extern "C" void func_003A5780(char* self, sVec4* in)
{
    *(sVec4*)(self + 0x88) = *in;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A57A8);
#ifdef SKIP_ASM
extern "C" unsigned char func_003A57A8(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x319)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A57B0);
#ifdef SKIP_ASM
extern "C" unsigned char func_003A57B0(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x318)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A57B8);
#ifdef SKIP_ASM
extern "C" void* func_003977E8(void* p);
extern "C" void* func_003A65D8(void* p);
extern void* D_004946C8[];

extern "C" void* func_003A57B8(char* self)
{
    *(char**)(self + 0x4) = self;
    *(char**)(self + 0x0) = self;
    *(void***)(self + 0x8) = D_004946C8;
    func_003A65D8(self + 0x1C);
    func_003977E8(self + 0x24);
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5800);
#ifdef SKIP_ASM
extern "C" void func_003A5800(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5808);
#ifdef SKIP_ASM
extern "C" int func_003A5808(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5810);
#ifdef SKIP_ASM
extern "C" int func_003A5810(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5818);
#ifdef SKIP_ASM
extern "C" void func_003A5818(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x14))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5820);
#ifdef SKIP_ASM
extern "C" signed char func_003A5820(void *arg0) {
    return (*(signed char *)((char*)(arg0) + (0x14)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5828);
#ifdef SKIP_ASM
extern "C" void func_003A5828(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x15))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5830);
#ifdef SKIP_ASM
extern "C" unsigned char func_003A5830(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x15)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5838);
#ifdef SKIP_ASM
extern "C" int func_003A5838(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5840);
#ifdef SKIP_ASM
extern "C" void func_003A5840(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5848);
#ifdef SKIP_ASM
extern "C" int func_003A5848(void *arg0) {
    return (*(unsigned char *)((char*)(arg0) + (0x1D))) & 0x3F;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5858);
#ifdef SKIP_ASM
extern "C" void func_003A5858(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~0x3F00) | ((arg1 & 0x3F) << 8));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5878);
#ifdef SKIP_ASM
extern "C" int func_003A5878(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x1C))) >> 4) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5888);
#ifdef SKIP_ASM
extern "C" void func_003A5888(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~0x10) | ((arg1 & 1) * 0x10));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A58A8);
#ifdef SKIP_ASM
extern "C" int func_003A58A8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x1C))) >> 5) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A58B8);
#ifdef SKIP_ASM
extern "C" void func_003A58B8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~0x20) | ((arg1 & 1) << 5));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A58D8);
#ifdef SKIP_ASM
extern "C" int func_003A58D8(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x1C))) >> 0xE) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A58E8);
#ifdef SKIP_ASM
extern "C" void func_003A58E8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~0x4000) | ((arg1 & 1) << 0xE));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5908);
#ifdef SKIP_ASM
extern "C" int func_003A5908(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x1C))) >> 0xF) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5918);
#ifdef SKIP_ASM
extern "C" void func_003A5918(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & 0xFFFF7FFF) | ((arg1 & 1) << 0xF));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5940);
#ifdef SKIP_ASM
extern "C" int func_003A5940(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x1C))) >> 6) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5950);
#ifdef SKIP_ASM
extern "C" void func_003A5950(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~0x40) | ((arg1 & 1) << 6));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5970);
#ifdef SKIP_ASM
extern "C" int func_003A5970(void *arg0) {
    int f = *(int *)((char*)arg0 + 0x1C) >> 7;
    return f & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5980);
#ifdef SKIP_ASM
extern "C" void func_003A5980(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~0x80) | ((arg1 & 1) << 7));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A59A0);
#ifdef SKIP_ASM
extern "C" int func_003A59A0(void *arg0) {
    return ((*(int *)((char*)(arg0) + (0x1C))) & 6) != 0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A59B0);
#ifdef SKIP_ASM
extern "C" int func_003A59B0(void *arg0) {
    return ((unsigned int) (*(unsigned int *)((char*)(arg0) + (0x1C))) >> 1) & 3;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A59C0);
#ifdef SKIP_ASM
extern "C" void func_003A59C0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~6) | ((arg1 & 3) * 2));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A59E0);
#ifdef SKIP_ASM
struct sUIVecMode1C {
    unsigned int bit0 : 1;
    unsigned int mode : 2;
};
extern "C" void func_003A59E0(char* self)
{
    sUIVecMode1C* f = (sUIVecMode1C*)(self + 0x1C);
    f->mode = f->mode + 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5A10);
#ifdef SKIP_ASM
extern "C" void func_003A5A10(char* self)
{
    sUIVecMode1C* f = (sUIVecMode1C*)(self + 0x1C);
    if (f->mode != 0)
        f->mode = f->mode - 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5A48);
#ifdef SKIP_ASM
extern "C" int func_003A5A48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C))) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5A58);
#ifdef SKIP_ASM
extern "C" void func_003A5A58(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~1) | (arg1 & 1));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5A78);
#ifdef SKIP_ASM
extern "C" int func_003A5A78(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x1C))) >> 3) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5A88);
#ifdef SKIP_ASM
extern "C" void func_003A5A88(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (((*(int *)((char*)(arg0) + (0x1C))) & ~8) | ((arg1 & 1) * 8));
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AA8__FPv);
#ifdef SKIP_ASM
void func_003A5AA8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AB0__FPv);
#ifdef SKIP_ASM
int func_003A5AB0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AB8__FPv);
#ifdef SKIP_ASM
int func_003A5AB8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AC0__FPv);
#ifdef SKIP_ASM
int func_003A5AC0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AC8__FPv);
#ifdef SKIP_ASM
void func_003A5AC8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AD0__FPv);
#ifdef SKIP_ASM
void func_003A5AD0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AD8__FPv);
#ifdef SKIP_ASM
int func_003A5AD8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5AE0);
#ifdef SKIP_ASM
extern "C" void func_003A5AE0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5AE8);
#ifdef SKIP_ASM
extern "C" int func_003A5AE8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5AF0);
#ifdef SKIP_ASM
extern "C" int func_003A5AF0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x40)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5AF8);
#ifdef SKIP_ASM
extern "C" void func_003A5AF8(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x44))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5B00);
#ifdef SKIP_ASM
extern "C" signed char func_003A5B00(void *arg0) {
    return (*(signed char *)((char*)(arg0) + (0x44)));
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B08__FPv);
#ifdef SKIP_ASM
void func_003A5B08(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B10__FPv);
#ifdef SKIP_ASM
void func_003A5B10(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B18__FPv);
#ifdef SKIP_ASM
void func_003A5B18(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B20__FPv);
#ifdef SKIP_ASM
int func_003A5B20(void* self)
{
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B28__FPv);
#ifdef SKIP_ASM
int func_003A5B28(void* self)
{
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B30__FPv);
#ifdef SKIP_ASM
int func_003A5B30(void* self)
{
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B38__FPv);
#ifdef SKIP_ASM
int func_003A5B38(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B40__FPv);
#ifdef SKIP_ASM
int func_003A5B40(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B48);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_003A4868(void* self);

extern void* D_00494CC0[];

extern "C" void func_003A5B48(int* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00494CC0;
    func_003A4868(self);
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5B98);
#ifdef SKIP_ASM
extern "C" void* func_001DD580(void* self);
extern "C" void* func_003977E8(void* p);
extern "C" void* func_0039FB30(void* self, int a, int b);
extern void* D_00494670[];

extern "C" void* func_003A5B98(char* self)
{
    *(void**)(self + 4) = self;
    *(void**)(self + 0) = self;
    *(void***)(self + 8) = D_00494670;
    func_001DD580(self + 0x14);
    func_003977E8(self + 0x18);
    func_0039FB30(self + 0x40, 0, 0);
    *(void***)(self + 0x48) = D_004949E8;
    func_003977E8(self + 0xB4);
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5C08);
#ifdef SKIP_ASM
extern "C" void* func_001DD580(void* self);
extern "C" void* func_003977E8(void* p);
extern "C" void* func_0039FB30(void* self, int a, int b);
extern void* D_00494670[];

extern "C" void* func_003A5C08(char* self, int arg)
{
    *(void**)(self + 4) = self;
    *(void**)(self + 0) = self;
    *(int*)(self + 0xC) = 0;
    *(int*)(self + 0x10) = 0;
    *(void***)(self + 8) = D_00494670;
    func_001DD580(self + 0x14);
    func_003977E8(self + 0x18);
    *(int*)(self + 0x34) = 0;
    *(int*)(self + 0x38) = 0;
    *(int*)(self + 0x3C) = 0;
    func_0039FB30(self + 0x40, 0, 0);
    *(void***)(self + 0x48) = D_004949E8;
    func_003977E8(self + 0xB4);
    *(int*)(self + 0xD0) = arg;
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5C98);
#ifdef SKIP_ASM
extern "C" int func_003A5C98(void *arg0) {
    return *(*(int **)((char*)(arg0) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5CA8);
#ifdef SKIP_ASM
extern "C" unsigned short *func_003A5CA8(unsigned short *arg0) {
    *arg0 = (*arg0 | 1) & 0xFFFD;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5CC0);
#ifdef SKIP_ASM
extern "C" int func_003A5CC0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14))) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5CD0);
#ifdef SKIP_ASM
extern "C" void func_003A5CD0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = (int) (((*(int *)((char*)(arg0) + (0x14))) & ~1) | (arg1 != 0));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5CF0);
#ifdef SKIP_ASM
extern "C" void cList_addToEnd__FP5cListP9cListNode(int);

extern "C" void func_003A5CF0(int arg0) {
    cList_addToEnd__FP5cListP9cListNode(arg0 + 0xB4);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5D10);
#ifdef SKIP_ASM
extern "C" int func_003A5D10(int arg0) {
    return arg0 + 0x40;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5D18);
#ifdef SKIP_ASM
extern "C" void func_003A5D18(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x54))->bit6 = enable;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5D38);
#ifdef SKIP_ASM
extern "C" int func_003A5D38(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x54))) >> 6) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5D48);
#ifdef SKIP_ASM
extern "C" int func_003A5D48(void *arg0) {
    return (*(int *)((char*)((*(void **)((char*)(arg0) + (0xD0)))) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5D58);
#ifdef SKIP_ASM
extern "C" int func_003A5D58(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xD0)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5D60);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern "C" unsigned char* func_003A65E8(unsigned char* p);
extern void* D_00494588[];

extern "C" void* func_003A5D60(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_00494588;
    func_003A65E8((unsigned char*)(self + 0x74));
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5DA8);
#ifdef SKIP_ASM
extern void* D_00494588[];
extern "C" void cUIText_deleteText(void* self);
// PORT: the unit declares func_0039FC48 with one parameter; the real body is a
// destructor taking (self, flags). Bound to the same symbol with an asm label.
extern "C" void* func_0039FC48_dtor(void* self, int flags) __asm__("func_0039FC48");

extern "C" void func_003A5DA8(void* self, int flags)
{
    *(void***)((char*)self + 8) = D_00494588;
    cUIText_deleteText(self);
    func_0039FC48_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5DF0__FPv);
#ifdef SKIP_ASM
int func_003A5DF0(void* self)
{
    return 0x17;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5DF8);
#ifdef SKIP_ASM
extern "C" void func_003A5DF8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x74))) = (int) (((*(int *)((char*)(arg0) + (0x74))) & ~3) | (arg1 & 3));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5E18);
#ifdef SKIP_ASM
extern "C" int func_003A5E18(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 2) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5E28);
#ifdef SKIP_ASM
extern "C" int func_003A5E28(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 3) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5E38);
#ifdef SKIP_ASM
extern "C" int func_003A5E38(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 4) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5E48);
#ifdef SKIP_ASM
extern "C" int func_003A5E48(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 5) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5E58);
#ifdef SKIP_ASM
extern "C" int func_003A5E58(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 6) & 1;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5E68);
#ifdef SKIP_ASM
extern "C" void func_003A5E68(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit2 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5E88);
#ifdef SKIP_ASM
extern "C" void func_003A5E88(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit3 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5EA8);
#ifdef SKIP_ASM
extern "C" void func_003A5EA8(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit4 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5EC8);
#ifdef SKIP_ASM
extern "C" void func_003A5EC8(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit5 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5EE8);
#ifdef SKIP_ASM
extern "C" void func_003A5EE8(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit6 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A5F08);
#ifdef SKIP_ASM
extern "C" void func_003A5F08(char* self, sVec4* in)
{
    *(sVec4*)(self + 0x78) = *in;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5F30);
#ifdef SKIP_ASM
extern "C" void func_003A5F30(char* self, sVec4* in)
{
    *(sVec4*)(self + 0x88) = *in;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5F58);
#ifdef SKIP_ASM
extern "C" int func_003A5F58(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB0)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5F60);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern void* D_004944C8[];

extern "C" void* func_003A5F60(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_004944C8;
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A5FA0);
#ifdef SKIP_ASM
extern void* D_004944C8[];
// PORT: the other ctors in the unit call this base ctor with (self, 0, 0)
extern "C" void* func_0039FB30_self(void* self) __asm__("func_0039FB30");

extern "C" void* func_003A5FA0(char* self)
{
    func_0039FB30_self(self);
    *(int*)(self + 0x74) = 0;
    *(void***)(self + 0x8) = D_004944C8;
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x7C) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x84) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0xC0) = 0;
    *(int*)(self + 0xC4) = 0;
    *(int*)(self + 0xC8) = 0;
    *(char*)(self + 0x8C) = 0;
    *(char*)(self + 0xA5) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6000__FPv);
#ifdef SKIP_ASM
int func_003A6000(void* self)
{
    return 0x21;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6008);
#ifdef SKIP_ASM
extern "C" void func_003A6008(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x74))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6010);
#ifdef SKIP_ASM
extern "C" void func_003A6010(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x78))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6018);
#ifdef SKIP_ASM
extern "C" void func_003A6018(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x7C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6020);
#ifdef SKIP_ASM
extern "C" void func_003A6020(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x80))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6028);
#ifdef SKIP_ASM
extern "C" void func_003A6028(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x84))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6030);
#ifdef SKIP_ASM
extern "C" void func_003A6030(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x88))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6038);
#ifdef SKIP_ASM
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);

extern "C" void func_003A6038(char* self, char* str)
{
    if (strlen(str) >= 0x19U) {
        *(self + 0x8C) = 0;
        return;
    }
    strcpy(self + 0x8C, str);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6088);
#ifdef SKIP_ASM
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);

extern "C" void func_003A6088(char* self, char* str)
{
    if (strlen(str) >= 0x19U) {
        self[0xA5] = 0;
        return;
    }
    strcpy(self + 0xA5, str);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A60D8);
#ifdef SKIP_ASM
extern "C" int func_003A60D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC0)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A60E0);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern void* D_00494408[];

extern "C" void* func_003A60E0(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_00494408;
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039FB30_self(void* self) __asm__("func_0039FB30");
extern void* D_00494408[];

extern "C" void* func_003A6120(char* self)
{
    func_0039FB30_self(self);
    *(void***)(self + 0x8) = D_00494408;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x7C) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x84) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6168__FPv);
#ifdef SKIP_ASM
int func_003A6168(void* self)
{
    return 0x19;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6170);
#ifdef SKIP_ASM
extern "C" void func_003A6170(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x74))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6178);
#ifdef SKIP_ASM
extern "C" void func_003A6178(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x78))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6180);
#ifdef SKIP_ASM
extern "C" int func_003A6180(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6188);
#ifdef SKIP_ASM
extern "C" void func_003A6188(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x80))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6190);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern void* D_00494348[];

extern "C" void* func_003A6190(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_00494348;
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A61D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039FB30_self(void* self) __asm__("func_0039FB30");
extern void* D_00494348[];

extern "C" void* func_003A61D0(char* self)
{
    func_0039FB30_self(self);
    *(void***)(self + 0x8) = D_00494348;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x7C) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0x8C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6220__FPv);
#ifdef SKIP_ASM
int func_003A6220(void* self)
{
    return 0x16;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6228);
#ifdef SKIP_ASM
extern "C" int func_003A6228(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x74)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6230);
#ifdef SKIP_ASM
extern "C" void func_003A6230(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x74))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6238);
#ifdef SKIP_ASM
extern "C" void func_003A6238(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x78))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6240);
#ifdef SKIP_ASM
extern "C" void func_003A6240(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x88))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6248);
#ifdef SKIP_ASM
extern "C" void func_003A6248(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x8C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6250);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern "C" void* func_003977E8(void* p);
extern "C" unsigned char* func_003A6600(unsigned char* p);
extern void* D_00494278[];

extern "C" void* func_003A6250(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_00494278;
    func_003A6600((unsigned char*)(self + 0x74));
    func_003977E8(self + 0x8C);
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A62A0);
#ifdef SKIP_ASM
extern void* D_00494278[];
extern void* D_00494C98[];
extern void* D_00494CC0[];
extern "C" void func_003A4868(void* self);
extern "C" void func_003A18C0(void* self);
// PORT: the unit declares func_00397948 as returning void*; its body (util/list) is void.
extern "C" void func_00397948_v(void* self) __asm__("func_00397948");
// PORT: the unit declares func_0039FC48 with one parameter; the real body is a
// destructor taking (self, flags). Bound to the same symbol with an asm label.
extern "C" void* func_0039FC48_dtor(void* self, int flags) __asm__("func_0039FC48");

extern "C" void func_003A62A0(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00494278;
    func_003A18C0(self);
    *(void***)((char*)self + 0xA4) = D_00494C98;
    func_00397948_v((char*)self + 0x8C);
    *(void***)((char*)self + 0xA0) = D_00494CC0;
    func_003A4868((char*)self + 0x98);
    *(void***)((char*)self + 0x94) = D_00494CC0;
    func_003A4868((char*)self + 0x8C);
    func_0039FC48_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6330__FPv);
#ifdef SKIP_ASM
int func_003A6330(void* self)
{
    return 0x20;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6338);
#ifdef SKIP_ASM
extern "C" void func_003A6338(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x74))) = (int) (((*(int *)((char*)(arg0) + (0x74))) & ~6) | ((arg1 & 3) * 2));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6358);
#ifdef SKIP_ASM
extern "C" int func_003A6358(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 3) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6368);
#ifdef SKIP_ASM
extern "C" int func_003A6368(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0x74))) >> 4) & 1;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6378);
#ifdef SKIP_ASM
extern "C" void func_003A6378(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit3 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6398);
#ifdef SKIP_ASM
extern "C" void func_003A6398(void* self, int enable)
{
    ((sUIVectorFlags*)((char*)self + 0x74))->bit4 = enable;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A63B8);
#ifdef SKIP_ASM
extern "C" void func_003A63B8(char* self, sVec4* in)
{
    *(sVec4*)(self + 0x78) = *in;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A63E0);
#ifdef SKIP_ASM
extern "C" void cList_first__FP5cList(int);

extern "C" void func_003A63E0(int arg0) {
    cList_first__FP5cList(arg0 + 0x8C);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6400);
#ifdef SKIP_ASM
extern "C" void func_00397858(int);

extern "C" void func_003A6400(int arg0) {
    func_00397858(arg0 + 0x8C);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6420);
#ifdef SKIP_ASM
extern "C" void func_00397870(int);

extern "C" void func_003A6420(int arg0) {
    func_00397870(arg0 + 0x8C);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6440);
#ifdef SKIP_ASM
extern "C" void cList_addToFront__FP5cListP9cListNode(int);

extern "C" void func_003A6440(int arg0) {
    cList_addToFront__FP5cListP9cListNode(arg0 + 0x8C);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6460);
#ifdef SKIP_ASM
extern "C" void cList_addToEnd__FP5cListP9cListNode(int);

extern "C" void func_003A6460(int arg0) {
    cList_addToEnd__FP5cListP9cListNode(arg0 + 0x8C);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6480);
#ifdef SKIP_ASM
extern "C" void func_003A6480(void *arg0) {
    (*(int *)((char*)(arg0) + (0x74))) = (int) ((*(int *)((char*)(arg0) + (0x74))) | 1);
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6490);
#ifdef SKIP_ASM
extern "C" int func_003A6490(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x74))) & 1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64A0);
#ifdef SKIP_ASM
extern "C" void func_003A64A0(char* self, sVec4* in)
{
    *(sVec4*)(self + 0xA8) = *in;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64C8);
#ifdef SKIP_ASM
extern "C" void func_003A64C8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xB8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64D0);
#ifdef SKIP_ASM
extern "C" void func_003A64D0(void *arg0, short arg1) {
    (*(short *)((char*)(arg0) + (0xC6))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64D8);
#ifdef SKIP_ASM
extern "C" unsigned short func_003A64D8(void *arg0) {
    return (*(unsigned short *)((char*)(arg0) + (0xC6)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64E0);
#ifdef SKIP_ASM
extern "C" unsigned short func_003A64E0(void *arg0) {
    return (*(unsigned short *)((char*)(arg0) + (0xC8)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64E8);
#ifdef SKIP_ASM
extern "C" void func_003A64E8(void *arg0, short arg1) {
    (*(short *)((char*)(arg0) + (0xC4))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64F0);
#ifdef SKIP_ASM
extern "C" unsigned short func_003A64F0(void *arg0) {
    return (*(unsigned short *)((char*)(arg0) + (0xC4)));
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A64F8);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self, int a, int b);
extern "C" void* func_003A6618(void* p);
extern void* D_004941B8[];

extern "C" void* func_003A64F8(char* self)
{
    func_0039FB30(self, 0, 0);
    *(void***)(self + 0x8) = D_004941B8;
    func_003A6618(self + 0x74);
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uivector", func_003A6540__FPv);
#ifdef SKIP_ASM
int func_003A6540(void* self)
{
    return 0x18;
}
#endif

extern "C" void* func_003A3F48(int, int);

//100%
INCLUDE_ASM("ui/uivector", func_003A6548);
#ifdef SKIP_ASM
struct sFlags_6548 {
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
    unsigned b6 : 1;
    unsigned b7 : 1;
    unsigned f8 : 5;
    unsigned f13 : 6;
};

extern "C" sFlags_6548* func_003A6548(sFlags_6548* f)
{
    f->b0 = 1;
    f->b7 = 0;
    f->f8 = 0;
    f->b5 = 0;
    f->b4 = 0;
    f->b2 = 0;
    f->b1 = 1;
    f->b3 = 1;
    f->b6 = 1;
    f->f13 = 9;
    return f;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A65A0);
#ifdef SKIP_ASM
extern "C" unsigned char *func_003A65A0(unsigned char *arg0) {
    *arg0 = (*arg0 | 4) & 0xC4;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A65B8);
#ifdef SKIP_ASM
extern "C" void *func_003A65B8(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(signed char *)((char*)(arg0) + (0x10))) = 0;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A65D8);
#ifdef SKIP_ASM
extern "C" void* func_003A65D8(void* self)
{
    *(short*)self = 0x218;
    return self;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A65E8);
#ifdef SKIP_ASM
extern "C" unsigned char *func_003A65E8(unsigned char *arg0) {
    *arg0 = (*arg0 | 4) & 0x87;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6600);
#ifdef SKIP_ASM
extern "C" unsigned char *func_003A6600(unsigned char *arg0) {
    *arg0 &= 0xC6;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ui/uivector", func_003A6618);
#ifdef SKIP_ASM
struct sCount_6618 {
    unsigned int flag : 1;
    unsigned int pad1 : 1;
    unsigned int mode : 15;
    unsigned int count : 15;
};
extern "C" void* func_003A6618(void* p)
{
    sCount_6618* self = (sCount_6618*)p;
    self->flag = 0;
    self->pad1 = 0;
    self->count = 0;
    return self;
}
#endif

//99.38%
INCLUDE_ASM("ui/uivector", func_003A6648__FPv);
#ifdef SKIP_ASM
void* func_003A6648(void* self)
{
    return func_003A3F48(1, 0xffff);
}
#endif

extern "C" void* func_003A3F48(int, int);

//99.38%
INCLUDE_ASM("ui/uivector", func_003A6668__FPv);
#ifdef SKIP_ASM
void* func_003A6668(void* self)
{
    return func_003A3F48(0, 0xffff);
}
#endif

