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

INCLUDE_ASM("ui/uivector", func_003A3808);

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

INCLUDE_ASM("ui/uivector", func_003A3F48);

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

INCLUDE_ASM("ui/uivector", func_003A5068);

//100%
INCLUDE_ASM("ui/uivector", func_003A50F8__FPv);
#ifdef SKIP_ASM
int func_003A50F8(void* self)
{
    return 0x10;
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

INCLUDE_ASM("ui/uivector", func_003A52A0);

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
INCLUDE_ASM("ui/uivector", func_003A56D8);
#ifdef SKIP_ASM
extern "C" void func_003A56D8(void* self, int enable) {
    ((sUIVectorFlags*)((char*)self + 0x74))->bit2 = enable;
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
INCLUDE_ASM("ui/uivector", func_003A6000__FPv);
#ifdef SKIP_ASM
int func_003A6000(void* self)
{
    return 0x21;
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
INCLUDE_ASM("ui/uivector", func_003A6220__FPv);
#ifdef SKIP_ASM
int func_003A6220(void* self)
{
    return 0x16;
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
INCLUDE_ASM("ui/uivector", func_003A6540__FPv);
#ifdef SKIP_ASM
int func_003A6540(void* self)
{
    return 0x18;
}
#endif

extern "C" void* func_003A3F48(int, int);

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

