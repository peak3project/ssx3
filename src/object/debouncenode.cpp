#include "common.h"

//100%
INCLUDE_ASM("object/debouncenode", cDebounceNode_cDebounceNode);
#ifdef SKIP_ASM
struct sDebounceVEntry2D10 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* cMoveNode_cMoveNode(void* self, void*, void*);
extern char D_004906F0[];

extern "C" void* cDebounceNode_cDebounceNode(void* self, void* unused, void* stream)
{
    cMoveNode_cMoveNode(self, unused, stream);
    *(void**)((char*)self + 0xC) = D_004906F0;
    sDebounceVEntry2D10* e = &(*(sDebounceVEntry2D10**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x2C, 4);
    e = &(*(sDebounceVEntry2D10**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x30, 4);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00342D88);
#ifdef SKIP_ASM
struct sDebounceVEntry2D88 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" int func_00342D88(void* self)
{
    int n = *(int*)((char*)self + 0x2C);
    if (n > 0) {
        n--;
        *(int*)((char*)self + 0x2C) = n;
        if (n == 0) {
            sDebounceVEntry2D88* vt = *(sDebounceVEntry2D88**)((char*)self + 0xC);
            vt[34].fn((char*)self + vt[34].delta, 1);
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00342DD8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_003506D8(void* self, void* parent);
extern const char D_0048E738[];

struct sDebounceVEntry2DD8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00342DD8(void* self)
{
    if (*(int*)((char*)self + 0x2C) >= 0) {
        if (*(int*)((char*)self + 0x30) == 0) {
            void* parent = *(void**)((char*)self + 0x18);
            if (self != 0) {
                sDebounceVEntry2DD8* vt = *(sDebounceVEntry2DD8**)((char*)self + 0xC);
                vt[1].fn((char*)self + vt[1].delta, 3);
            }
            func_003506D8(cMemMan_alloc(0x1C, D_0048E738, 0x20000000, 0), parent);
        } else {
            if (self != 0) {
                sDebounceVEntry2DD8* vt = *(sDebounceVEntry2DD8**)((char*)self + 0xC);
                vt[1].fn((char*)self + vt[1].delta, 3);
            }
        }
    }
}
#endif

extern "C" void func_00356B08(void* self);

//100%
INCLUDE_ASM("object/debouncenode", func_00342E78__FPv);
#ifdef SKIP_ASM
void func_00342E78(void* self)
{
    func_00356B08(self);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00342E98);
#ifdef SKIP_ASM
int func_0034FCC0(void* self);
extern "C" void* func_00350F60(void* self, void* parent);
extern const char D_0048E748[];

extern "C" void func_00342E98(void* self, int check)
{
    if (check != 0 && func_0034FCC0(self) != 0) {
        return;
    }
    if (*(int*)((char*)self + 0x2C) >= 0) {
        int mode = *(int*)((char*)self + 0x30);
        if (mode == 0) {
            void* parent = *(void**)((char*)self + 0x18);
            if (self != 0) {
                sDebounceVEntry2DD8* vt = *(sDebounceVEntry2DD8**)((char*)self + 0xC);
                vt[1].fn((char*)self + vt[1].delta, 3);
            }
            func_003506D8(cMemMan_alloc(0x1C, D_0048E738, 0x20000000, 0), parent);
        } else if (mode == 3) {
            void* parent = *(void**)((char*)self + 0x18);
            if (self != 0) {
                sDebounceVEntry2DD8* vt = *(sDebounceVEntry2DD8**)((char*)self + 0xC);
                vt[1].fn((char*)self + vt[1].delta, 3);
            }
            func_00350F60(cMemMan_alloc(0x1C, D_0048E748, 0x20000000, 0), parent);
        } else {
            if (self != 0) {
                sDebounceVEntry2DD8* vt = *(sDebounceVEntry2DD8**)((char*)self + 0xC);
                vt[1].fn((char*)self + vt[1].delta, 3);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00342FA8);
#ifdef SKIP_ASM
struct sDebounceVEntry2FA8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00356B30(void* self, void* stream);

extern "C" void func_00342FA8(void* self, void* stream)
{
    func_00356B30(self, stream);
    sDebounceVEntry2FA8* e = &(*(sDebounceVEntry2FA8**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x2C, 4);
    e = &(*(sDebounceVEntry2FA8**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x30, 4);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343010);
#ifdef SKIP_ASM
struct sVec2_3010 {
    float x;
    float y;
};

struct sDesc_3010 {
    int f0;
    float f4;
    float f8;
    float fC;
    int f10[8];
};

struct sFlags_3010 {
    char pad_0x00[0x8];
    unsigned int w;
};

struct sDebounce_3010 {
    char pad_0x00[0xC];
    char* vt;               // 0xC
    char pad_0x10[0x8];
    sFlags_3010* flags;     // 0x18
    float f1C;              // 0x1C
    unsigned char c20[8];   // 0x20
    char pad_0x28[0x10];
    sVec2_3010 v38;         // 0x38
    int f40;
    int f44;
};

extern char D_00490570[];
extern "C" void* func_0034FB00(void* self, void* a1, int type, void* a3);

extern "C" void* func_00343010(sDebounce_3010* self, void* a1, void* a2, sDesc_3010* desc)
{
    func_0034FB00(self, a1, 0xF, a2);
    self->vt = D_00490570;
    self->f1C = desc->f4;
    sVec2_3010 v;
    v.x = desc->f8;
    v.y = desc->fC;
    self->v38 = v;
    self->f40 = 0;
    self->f44 = 0;
    for (int i = 0; i < 8; i++) {
        self->c20[i] = desc->f10[i];
    }
    self->flags->w = (self->flags->w & ~2) | 4;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_003430D0);
#ifdef SKIP_ASM
struct sDebounceVEntry30D0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* cInstanceNode_cInstanceNode(void* self, void*, void*);
extern char D_00490570[];

extern "C" void* func_003430D0(void* self, void* unused, void* stream)
{
    cInstanceNode_cInstanceNode(self, unused, stream);
    *(void**)((char*)self + 0xC) = D_00490570;
    sDebounceVEntry30D0* vt = *(sDebounceVEntry30D0**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x1C, 0x2C);
    return self;
}
#endif

INCLUDE_ASM("object/debouncenode", func_00343130);

//100%
INCLUDE_ASM("object/debouncenode", func_003434E8);
#ifdef SKIP_ASM
struct sDebounceScroll {
    char pad_0x0[0x38];
    float du; // 0x38
    float dv; // 0x3c
    float u;  // 0x40
    float v;  // 0x44
};

extern "C" void func_003434E8(sDebounceScroll* self)
{
    self->u += self->du;
    self->v += self->dv;
    if (self->u > 1.0f) {
        self->u -= 1.0f;
    } else if (self->u < -1.0f) {
        self->u += 1.0f;
    }
    if (self->v > 1.0f) {
        self->v -= 1.0f;
    } else if (self->v < -1.0f) {
        self->v += 1.0f;
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343588);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sDfVec_343588 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sDfMat_343588 {
    sDfVec_343588 r[4];
};

struct sDfSlot_343588 {
    int f0;
    int type;
};

struct sDfCam_343588 {
    char pad_0x0[0x20];
    sDfSlot_343588 slots[(0x3F0 - 0x20) / 8];  // 0x20
    struct {
        int kind;
        char pad[0x14];
    } paths[1];                     // 0x3F0
};

struct sDfObj_343588 {
    char pad_0x0[0x60];
    float pos[3];                   // 0x60
    float scl[3];                   // 0x6C
    char pad_0x78[0x7D - 0x78];
    unsigned char slot;             // 0x7D
    short path;                     // 0x7E
    char pad_0x80[0x94 - 0x80];
    void* light;                    // 0x94
};

struct sDfGfxVt_343588 {
    short delta;
    short index;
    void* fn;
};

struct cDfGfx_343588 {
    char pad_0x0[0x10D8];
    sDfGfxVt_343588* vt;            // 0x10D8
};

typedef sDfMat_343588 (*DfViewFn_343588)(void*);
typedef int (*DfCullFn_343588)(void*, sDfVec_343588*, sDfVec_343588*, const sDfMat_343588&);
typedef void (*DfDrawFn_343588)(void*, void*, void*, void*, int);

extern sDfCam_343588** D_004A47B8_343588 __asm__("D_004A47B8");
extern cDfGfx_343588* D_004A5B80_343588 __asm__("D_004A5B80");
extern sDfMat_343588 D_004FF1A0_343588 __asm__("D_004FF1A0");

#define OBJ_343588(s) (*(sDfObj_343588**)((char*)(s) + 0x18))

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void MatCopy_343588(sDfMat_343588* d, const sDfMat_343588* s)
{
    __asm__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

static inline bool IsT6_343588(sDfCam_343588* c, int i)
{
    return c->slots[i].type == 6;
}

static inline int Visible_343588(sDfCam_343588* cam, sDfObj_343588* obj)
{
    if (obj->slot == 0xFF) {
        return 1;
    }
    if (IsT6_343588(cam, obj->slot)) {
        return cam->paths[obj->path].kind == 3;
    }
    return 0;
}

// Draws the debounce node's object: culls its box, then draws it offset in x/y by the values at 0x40.
extern "C" void func_00343588(char* self)
{
    sDfCam_343588* cam = *D_004A47B8_343588;
    if (!Visible_343588(cam, OBJ_343588(self))) {
        return;
    }
    cDfGfx_343588* gfx = D_004A5B80_343588;
    {
        sDfGfxVt_343588* vt = gfx->vt;
        char* thisp = (char*)gfx + vt[93].delta;
        sDfVec_343588 b[2];
        b[0].x = OBJ_343588(self)->pos[0];
        b[0].y = OBJ_343588(self)->pos[1];
        b[0].z = OBJ_343588(self)->pos[2];
        b[0].w = 1.0f;
        b[1].x = OBJ_343588(self)->scl[0];
        b[1].y = OBJ_343588(self)->scl[1];
        b[1].z = OBJ_343588(self)->scl[2];
        b[1].w = 1.0f;
        int res = ((DfCullFn_343588)vt[93].fn)(thisp, &b[0], &b[1], ((DfViewFn_343588)gfx->vt[43].fn)((char*)gfx + gfx->vt[43].delta));
        if (res == 1) {
            return;
        }
    }
    sDfMat_343588 xf;
    MatCopy_343588(&xf, &D_004FF1A0_343588);
    xf.r[3].x = *(float*)(self + 0x40);
    xf.r[3].y = *(float*)(self + 0x44);
    ((DfDrawFn_343588)gfx->vt[96].fn)((char*)gfx + gfx->vt[96].delta, OBJ_343588(self), 0, &xf, 2);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343718);
#ifdef SKIP_ASM
struct sDebounceVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0034FE90(void* self, void* stream);

extern "C" void func_00343718(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sDebounceVEntry* vt = *(sDebounceVEntry**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x1C, 0x2C);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343768);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, void* a1, int type, void* a3);
extern char D_004903F0[];

extern "C" void* func_00343768(void* self, void* a1, void* a2, void* a3)
{
    func_0034FB00(self, a1, 7, a2);
    *(void**)((char*)self + 0xC) = D_004903F0;
    *(int*)((char*)self + 0x1C) = *(short*)((char*)a3 + 0x4);
    *(int*)((char*)self + 0x20) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_003437C0);
#ifdef SKIP_ASM
struct sDebounceVEntry37C0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* cInstanceNode_cInstanceNode(void* self, void*, void*);
extern char D_004903F0[];

extern "C" void* func_003437C0(void* self, void* unused, void* stream)
{
    cInstanceNode_cInstanceNode(self, unused, stream);
    *(void**)((char*)self + 0xC) = D_004903F0;
    sDebounceVEntry37C0* vt = *(sDebounceVEntry37C0**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x1C, 0x8);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343820);
#ifdef SKIP_ASM
struct sDebounceVEntry1 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00343820(void* self)
{
    if (*(int*)((char*)self + 0x1C) == 0) {
        *(int*)((char*)self + 0x1C) = -1;
        sDebounceVEntry1* vt = *(sDebounceVEntry1**)((char*)self + 0xC);
        vt[34].fn((char*)self + vt[34].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343868);
#ifdef SKIP_ASM
extern "C" void func_00343868(void* self, int msg, float level)
{
    int bit = 0;
    int fire = 0;
    if (level == 1.0f)
        bit = 1;
    else if (level == 2.0f)
        bit = 2;
    else if (level == 3.0f)
        bit = 4;
    else if (level == 4.0f)
        bit = 8;
    else if (level == 5.0f)
        bit = 0x10;
    else if (level == 6.0f)
        bit = 0x20;
    else if (level == 7.0f)
        bit = 0x40;
    else if (level == 8.0f)
        bit = 0x80;
    else if (level == 9.0f)
        bit = 0x100;
    else if (level == 10.0f)
        bit = 0x200;
    if (msg == 0x1F4)
    {
        int f = *(int*)((char*)self + 0x20);
        if ((f & bit) == 0)
        {
            fire = 1;
            *(int*)((char*)self + 0x20) = f | bit;
        }
    }
    else if (msg == 0x1F5)
    {
        int f = *(int*)((char*)self + 0x20);
        if ((f & bit) == 0)
        {
            if (level == 1.0f)
            {
                fire = 1;
                *(int*)((char*)self + 0x20) = f | 1;
            }
            else if (f & (bit >> 1))
            {
                fire = 1;
                *(int*)((char*)self + 0x20) = f | bit;
            }
        }
    }
    else
    {
        fire = msg == 0x1F6;
    }
    if (fire)
    {
        int c = *(int*)((char*)self + 0x1C);
        if (c > 0)
            *(int*)((char*)self + 0x1C) = c - 1;
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343A18);
#ifdef SKIP_ASM
struct sDebounceVEntryA18 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0034FE90(void* self, void* stream);

extern "C" void func_00343A18(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sDebounceVEntryA18* vt = *(sDebounceVEntryA18**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x1C, 0x8);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343A68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sDebounceState;
extern "C" void func_003442E0(sDebounceState* self);
extern void* D_004A3FF0_p __asm__("D_004A3FF0");

struct sSlot00343A68 {
    unsigned int id;
    int value;
};
struct sState00343A68 {
    int f0;
    unsigned int f4;
    unsigned int f8;
    sSlot00343A68 slots[32];
    char rest[0x1F4 - 0x10C];
};

extern "C" sState00343A68* func_00343A68(sState00343A68* self)
{
    sState00343A68* p = self;
    int i;
    for (i = 4; i != -1; i--) {
        sState00343A68* next = p + 1;
        p->f4 = 0xFFFFFFFF;
        sSlot00343A68* q = p->slots;
        int j;
        for (j = 31; j != -1; j--) {
            q->id = 0xFFFFFFFF;
            q++;
        }
        func_003442E0((sDebounceState*)p);
        p = next;
    }
    D_004A3FF0_p = self;
    for (i = 0; i < 5; i++) {
        func_003442E0((sDebounceState*)&self[i]);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343B28);
#ifdef SKIP_ASM
extern int D_004A3FF0;
void operator_delete(int*);
void* func_00344348(void* self);

struct sDebounceElem_343B28 {
    char data[0x1F4];
};

struct sDebounce_343B28 {
    sDebounceElem_343B28 elems[5];
};

extern "C" void func_00343B28(void* self, int flags)
{
    sDebounce_343B28* d = (sDebounce_343B28*)self;
    int i;
    for (i = 0; i < 5; i++) {
        func_00344348(&d->elems[i]);
    }
    D_004A3FF0 = 0;
    if (d->elems != 0) {
        sDebounceElem_343B28* p = d->elems + 5;
        while (d->elems != p) {
            p--;
            func_00344348(p);
        }
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343BC0);
#ifdef SKIP_ASM
struct sDebounceState;
extern "C" void func_003442E0(sDebounceState* self);
void* func_00344348(void* self);

struct sDebounceBlock {
    char data[0x1F4];
};

extern "C" void func_00343BC0(sDebounceBlock* self)
{
    int i;
    for (i = 0; i < 5; i++) {
        func_00344348(&self[i]);
        func_003442E0((sDebounceState*)&self[i]);
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00343C08);
#ifdef SKIP_ASM
struct sDebounceElem3C08 {
    char data[0x1F4];
};

extern "C" void func_00344898(void* elem, void* arg);

extern "C" void func_00343C08(sDebounceElem3C08* self, void* arg)
{
    int i;
    for (i = 0; i < 5; i++) {
        func_00344898(&self[i], arg);
    }
}
#endif

INCLUDE_ASM("object/debouncenode", func_00343C60);

INCLUDE_ASM("object/debouncenode", func_00343F38);

//100%
INCLUDE_ASM("object/debouncenode", func_003440C8);
#ifdef SKIP_ASM
struct sDebounceElem40C8 {
    int field_0x0;
    unsigned int field_0x4;
    unsigned int field_0x8;
    char pad_0xc[0x1E8];
};

extern "C" void func_003449F0(void* elem);

extern "C" void func_003440C8(sDebounceElem40C8* self)
{
    int i;
    sDebounceElem40C8* p = self;
    for (i = 0; i < 5; i++) {
        if (self[i].field_0x8 != 0xFFFFFFFF) {
            func_003449F0(p);
        }
        p++;
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00344138);
#ifdef SKIP_ASM
struct sDebounceElem4138 {
    int field_0x0;
    unsigned int field_0x4;
    unsigned int field_0x8;
    char pad_0xc[0x1E8];
};

extern "C" void func_00344E18(void* elem);

extern "C" void func_00344138(sDebounceElem4138* self)
{
    int i;
    sDebounceElem4138* p = self;
    for (i = 0; i < 5; i++) {
        if (self[i].field_0x8 != 0xFFFFFFFF) {
            func_00344E18(p);
        }
        p++;
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_003441A8);
#ifdef SKIP_ASM
class cDebounceStream;
extern "C" void func_00344FC0(void* self, cDebounceStream* s);

struct sDebounceElem41A8 {
    int field_0x0;
    unsigned int field_0x4;
    unsigned int field_0x8;
    char pad_0xc[0x1E8];
};

struct sDebounceVEntry41A8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_003441A8(sDebounceElem41A8* self, cDebounceStream* s)
{
    int i;
    for (i = 0; i < 5; i++) {
        sDebounceVEntry41A8* e = &(*(sDebounceVEntry41A8**)s)[1];
        e->fn((char*)s + e->delta, &self[i].field_0x8, 4);
        if (self[i].field_0x8 != 0xFFFFFFFF) {
            func_00344FC0(&self[i], s);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/debouncenode", func_00344240);
#ifdef SKIP_ASM
class cDebounceStream;
extern "C" void func_00344FF8(void* self, cDebounceStream* s);

struct sDebounceElem4240 {
    int field_0x0;
    unsigned int field_0x4;
    unsigned int field_0x8;
    char pad_0xc[0x1E8];
};

struct sDebounceVEntry4240 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00344240(sDebounceElem4240* self, cDebounceStream* s)
{
    int i;
    func_00343BC0((sDebounceBlock*)self);
    for (i = 0; i < 5; i++) {
        sDebounceVEntry4240* e = &(*(sDebounceVEntry4240**)s)[2];
        e->fn((char*)s + e->delta, &self[i].field_0x8, 4);
        if (self[i].field_0x8 != 0xFFFFFFFF) {
            func_00344FF8(&self[i], s);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_003442E0);
#ifdef SKIP_ASM
struct sDebounceSlot {
    unsigned int id; // 0x0
    int value;       // 0x4
};

struct sDebounceState {
    int field_0x0;            // 0x000
    unsigned int field_0x4;   // 0x004
    unsigned int field_0x8;   // 0x008
    sDebounceSlot slots[32];  // 0x00c
    int field_0x10c;          // 0x10c
    int field_0x110;          // 0x110
    int field_0x114;          // 0x114
    char pad_0x118[0xc4];     // 0x118
    int field_0x1dc;          // 0x1dc
    int field_0x1e0;          // 0x1e0
    int field_0x1e4;          // 0x1e4
    int field_0x1e8;          // 0x1e8
    int field_0x1ec;          // 0x1ec
    int field_0x1f0;          // 0x1f0
};

extern "C" void func_003442E0(sDebounceState* self)
{
    int i;
    self->field_0x0 = 0;
    self->field_0x1dc = 0;
    self->field_0x8 = 0xFFFFFFFF;
    self->field_0x4 = 0xFFFFFFFF;
    self->field_0x1e8 = 0;
    self->field_0x1ec = 0;
    self->field_0x1f0 = 0;
    self->field_0x114 = 0;
    self->field_0x110 = 0;
    for (i = 0; i < 32; i++) {
        self->slots[i].id = 0xFFFFFFFF;
        self->slots[i].value = 0;
    }
}
#endif

extern "C" void* func_00344800(void* self);

//100%
INCLUDE_ASM("object/debouncenode", func_00344348__FPv);
#ifdef SKIP_ASM
void* func_00344348(void* self)
{
    return func_00344800(self);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00344368);
#ifdef SKIP_ASM
extern char* D_004A5B64;
extern "C" void func_003443A8(void* self);

extern "C" void func_00344368(void* self, int a1)
{
    char* s = (char*)self;
    char* g = D_004A5B64;
    *(int*)(s + 0x4) = a1;
    *(int*)(s + 0x1DC) = 0;
    *(float*)(s + 0x1E4) = 1.0f / (float)*(int*)(g + 0x10);
    func_003443A8(self);
}
#endif

INCLUDE_ASM("object/debouncenode", func_003443A8);

//100%
INCLUDE_ASM("object/debouncenode", func_00344730);
#ifdef SKIP_ASM
struct sTrackWorld51C0;
extern "C" sTrackWorld51C0** func_002D1BD8();

struct sItem4730 {
    char pad_0x0[0x10];
    char* data;             // 0x10
};

struct sItemList4730 {
    int count;              // 0x0
    sItem4730* items[1];    // 0x4
};

struct sModel4730 {
    char pad_0x0[0x94];
    sItemList4730* list;    // 0x94
};

static inline sModel4730* refToPtr4730(unsigned int p)
{
    return (sModel4730*)(p << 2);
}

struct sModelSet4730 {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C

    sModel4730* lookup(unsigned int idx)
    {
        unsigned int p = refs[idx] >> 8;
        if (p == 0) {
            return 0;
        }
        return refToPtr4730(p);
    }
};

struct sWorld4730 {
    char pad_0x0[0x8];
    sModelSet4730** sets;   // 0x8
};


struct sModelRef4730 {
    unsigned int id;

    sModel4730* get()
    {
        sModelSet4730* set = (*(sWorld4730**)func_002D1BD8())->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        return set->lookup(id >> 8);
    }
};

struct sSlot4730 {
    unsigned short value;   // 0x0
    char pad_0x2[0x12];
};

struct sDebounce4730 {
    int field_0x0;
    sModelRef4730 model;    // 0x4
    char pad_0x8[0x108];
    int count;              // 0x110
    char pad_0x114[0x28];
    sSlot4730 slots[1];     // 0x13C
};

extern "C" void func_00344730(sDebounce4730* self, int index)
{
    sModel4730* m = self->model.get();
    for (int i = 0; i < self->count; i++) {
        char* d = m->list->items[i]->data;
        if (d != 0) {
            self->slots[i].value = *(unsigned short*)(d + (index << 2) + 4);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00344800);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void cMemMan_free(void*);

struct sDebounceVEntry4800 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sDebounceItem4800 {
    char pad_0x0[0x84];
    sDebounceVEntry4800* vt;    // 0x84
    char pad_0x88[0x48];
};

struct sDebounceOwner4800 {
    char pad_0x0[0x1E8];
    void* buf;                  // 0x1E8
    sDebounceItem4800* items;   // 0x1EC, array-new block (count at -0x10)
};

// The unit declares func_00344800 as `void* (void*)`, but the body returns nothing
// (its wrapper func_00344348 only forwards). Bound by asm label.
void func_00344800_v(sDebounceOwner4800* self) __asm__("func_00344800");

void func_00344800_v(sDebounceOwner4800* self)
{
    sDebounceItem4800* items = self->items;
    if (items != 0) {
        sDebounceItem4800* p = items + ((int*)items)[-4];
        while (self->items != p) {
            p--;
            p->vt[1].fn((char*)p + p->vt[1].delta, 0);
        }
        cMemMan_free((char*)self->items - 0x10);
    }
    if (self->buf != 0) {
        cMemMan_free(self->buf);
    }
    self->items = 0;
    self->buf = 0;
}
#endif

INCLUDE_ASM("object/debouncenode", func_00344898);

//100%
INCLUDE_ASM("object/debouncenode", func_003449F0);
#ifdef SKIP_ASM
struct sDebounceVEntry49F0 {
    short delta;
    short index;
    void (*fn)(void*, float);
};

struct sDebounceItem49F0 {
    char pad_0x0[0x84];
    sDebounceVEntry49F0* vt;    // 0x84
    char pad_0x88[0x48];
};

struct sDebounceOwner49F0 {
    char pad_0x0[0x10C];
    int count;                  // 0x10C
    char pad_0x110[0xCC];
    float time;                 // 0x1DC
    float period;               // 0x1E0
    float step;                 // 0x1E4
    void* buf;                  // 0x1E8
    sDebounceItem49F0* items;   // 0x1EC
};

extern "C" void func_00344AA0(sDebounceOwner49F0* self);

// PORT: pointer held in int for the element address (index-first addu); not 64-bit safe.
extern "C" void func_003449F0(void* elem)
{
    sDebounceOwner49F0* self = (sDebounceOwner49F0*)elem;
    float t = self->time + self->step;
    self->time = t;
    if (t > self->period) {
        self->time = t - self->period;
    }
    for (int i = 0; i < self->count; i++) {
        sDebounceItem49F0* p = (sDebounceItem49F0*)(i * 0xD0 + (int)self->items);
        p->vt[2].fn((char*)p + p->vt[2].delta, self->time);
    }
    func_00344AA0(self);
}
#endif

INCLUDE_ASM("object/debouncenode", func_00344AA0);

//100%
INCLUDE_ASM("object/debouncenode", func_00344E18);
#ifdef SKIP_ASM
struct sTrackWorld51C0;
extern "C" sTrackWorld51C0** func_002D1BD8();
extern "C" void func_00344730(sDebounce4730* self, int index);
extern char* D_004A47B8;
extern char* D_004A5B80;

struct sModel_44E18 {
    char pad_0x0[0x7D];
    unsigned char page;     // 0x7D
    short slot;             // 0x7E
};

struct sModelSet_44E18 {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};

struct sWorld_44E18 {
    char pad_0x0[0x8];
    sModelSet_44E18** sets; // 0x8
};

static inline sModel_44E18* GetModel_44E18(unsigned int* ref)
{
    return (sModel_44E18*)((sModelRef4730*)ref)->get();
}

static inline int IsLoaded_44E18(sModel_44E18* m)
{
    char* wc = *(char**)D_004A47B8;
    if (m->page == 0xFF)
        return 1;
    int ok = *(int*)(wc + (m->page << 3) + 0x24) == 6;
    return ok ? *(int*)(wc + m->slot * 0x18 + 0x3F0) == 3 : 0;
}

struct sVE7_44E18 { short delta; short index; void (*fn)(void*, void*, float, void*, void*, void*, int, int); };
struct sVE5_44E18 { short delta; short index; void (*fn)(void*, void*, void*, int, int); };

extern "C" void func_00344E18(void* self)
{
    char* r = D_004A5B80;
    unsigned int* ref = (unsigned int*)((char*)self + 0xC);
    int off = 0;
    for (int i = 0; i < 32; ref += 2, i++, off += 8)
    {
        if (~*ref == 0)
            continue;
        sModel_44E18* m = GetModel_44E18(ref);
        if (!IsLoaded_44E18(m))
            continue;
        if (*(int*)((char*)self + 0x114) >= 2)
        {
            func_00344730((sDebounce4730*)self, *(int*)((char*)self + off + 0x10));
            sVE7_44E18* vt = *(sVE7_44E18**)(r + 0x10D8);
            vt[95].fn(r + vt[95].delta, m, 1.0f, (char*)self + 0x118, (char*)m + 0x10, *(void**)((char*)self + 0x1E8), 0, 0);
        }
        else
        {
            sVE5_44E18* vt = *(sVE5_44E18**)(r + 0x10D8);
            vt[96].fn(r + vt[96].delta, m, *(void**)((char*)self + 0x1E8), 0, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00344FC0);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
class cDebounceStream {
public:
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

extern "C" void func_00344FC0(void* self, cDebounceStream* s)
{
    s->v01(self, 0x10C);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00344FF8);
#ifdef SKIP_ASM
extern "C" void func_003443A8(void* self);

extern "C" void func_00344FF8(void* self, cDebounceStream* s)
{
    s->v02(self, 0x10C);
    func_00344800(self);
    func_003443A8(self);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00345048);
#ifdef SKIP_ASM
struct sDebVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sDebMtx {
    sDebVec4 r[4];
};

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (matrix * vector).
static inline sDebVec4 debMtxApply(sDebMtx* m, const sDebVec4& v)
{
    sDebVec4 out;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf8, %1\n"
        "lqc2      $vf4, 0x0(%2)\n"
        "lqc2      $vf5, 0x10(%2)\n"
        "lqc2      $vf6, 0x20(%2)\n"
        "lqc2      $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        ".set pop\n"
        : "=m"(out)
        : "m"(v), "r"(m)
        : "memory");
    return out;
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (v * s).
static inline sDebVec4 debVecScale(const sDebVec4& v, float s)
{
    sDebVec4 out;
    int t;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(out), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return out;
}

struct sDebCurve {
    char pad_0x00[0x10];
    sDebMtx basis;   // 0x10
    float coef[4];   // 0x50: time-warp cubic
    char pad_0x60[0x24];
    float t0;        // 0x84
};

// Evaluate the curve at time t: position, velocity and acceleration.
extern "C" void func_00345048(sDebCurve* self, float t, sDebVec4* pos, sDebVec4* vel, sDebVec4* acc)
{
    t -= self->t0;
    float u = ((self->coef[0] * t + self->coef[1]) * t + self->coef[2]) * t + self->coef[3];
    float du = (self->coef[0] * (t * 3.0f) + self->coef[1] * 2.0f) * t + self->coef[2];
    sDebVec4 a;
    a.x = u * 6.0f;
    a.y = 2.0f;
    a.z = 0.0f;
    a.w = 0.0f;
    *acc = debVecScale(debMtxApply(&self->basis, a), du);
    sDebVec4 p;
    p.x = u * u * u;
    p.y = u * u;
    p.z = u;
    p.w = 1.0f;
    *pos = debMtxApply(&self->basis, p);
    sDebVec4 v;
    v.x = u * u * 3.0f;
    v.y = u * 2.0f;
    v.z = 1.0f;
    v.w = 0.0f;
    *vel = debMtxApply(&self->basis, v);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_003451C0);
#ifdef SKIP_ASM
struct cSpline;
float cSpline_calcLength(cSpline* self);

struct sTrackNode51C0 {
    char pad_0x0[0x24];
    int value;              // 0x24
};

struct sTrackSet51C0 {
    char pad_0x0[0x44];
    unsigned int* refs;     // 0x44, (node >> 2) << 8 | low byte
};

struct sTrackWorld51C0 {
    char pad_0x0[0x8];
    sTrackSet51C0** sets;   // 0x8
};

extern "C" sTrackWorld51C0** func_002D1BD8();

static inline sTrackNode51C0* refToNode51C0(unsigned int p)
{
    return (sTrackNode51C0*)(p << 2);
}

struct sTrackRef51C0 {
    unsigned int id;

    sTrackNode51C0* get()
    {
        sTrackSet51C0* set = (*func_002D1BD8())->sets[id & 0xFF];
        if (set != 0) {
            unsigned int p = set->refs[id >> 8] >> 8;
            if (p != 0) {
                return refToNode51C0(p);
            }
        }
        return 0;
    }
};

struct sSplineFollow51C0 {
    sTrackRef51C0 ref;      // 0x0
    int field_0x4;          // 0x4
    int field_0x8;          // 0x8
    float length;           // 0xC
};

extern "C" void func_003451C0(sSplineFollow51C0* self, unsigned int id)
{
    self->ref.id = id;
    sTrackNode51C0* node = self->ref.get();
    self->field_0x8 = node->value;
    self->field_0x4 = 0;
    self->length = cSpline_calcLength((cSpline*)self);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00345248);
#ifdef SKIP_ASM
struct sDebKey5248 {
    char pad_0x00[0x60];
    sDebKey5248* prev;  // 0x60
    sDebKey5248* next;  // 0x64
    char pad_0x68[0x1C];
    float t0;           // 0x84
};

struct sDebTrack5248 {
    int field_0x0;
    int index;          // 0x4
    sDebKey5248* key;   // 0x8
    float length;       // 0xC

    void back()
    {
        sDebKey5248* p = key->prev;
        index--;
        key = p;
    }
    void forward()
    {
        sDebKey5248* n = key->next;
        index++;
        key = n;
    }
};

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ftrunc_00345248(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    return t;
}

extern "C" void func_00345248(sDebTrack5248* self, float t, sDebVec4* pos, sDebVec4* vel, sDebVec4* acc)
{
    float len = self->length;
    float q = t / len;
    float f = ftrunc_00345248(q);
    if (q < f) {
        f -= 1.0f;
    }
    t -= f * len;
    while (t < self->key->t0 && self->key->prev != 0) {
        self->back();
    }
    sDebKey5248* next = self->key->next;
    while (next != 0 && next->t0 <= t) {
        self->forward();
        next = self->key->next;
    }
    func_00345048((sDebCurve*)self->key, t, pos, vel, acc);
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00345320);
#ifdef SKIP_ASM
extern "C" int func_00345320(sTrackRef51C0* self)
{
    float* v = (float*)self->get();
    sDfVec_343588 b[2];
    b[0].x = v[1];
    b[0].y = v[2];
    b[0].z = v[3];
    b[0].w = 1.0f;
    b[1].x = v[4];
    b[1].y = v[5];
    b[1].z = v[6];
    b[1].w = 1.0f;
    cDfGfx_343588* gfx = D_004A5B80_343588;
    sDfGfxVt_343588* vt = gfx->vt;
    char* thisp = (char*)gfx + vt[93].delta;
    int res = ((DfCullFn_343588)vt[93].fn)(thisp, &b[0], &b[1], ((DfViewFn_343588)gfx->vt[43].fn)((char*)gfx + gfx->vt[43].delta));
    return res != 1;
}
#endif

//100%
INCLUDE_ASM("object/debouncenode", func_00345430);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00345638(void* node);

class cWorld00345430 {
public:
    char pad[0x10D8];
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
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75(void* a, int b, int c);
};
extern cWorld00345430* D_004A5B80_w345430 __asm__("D_004A5B80");

struct sCtl00345430 {
    int f0;
    unsigned int lo : 2;
    unsigned int mode : 5;
    unsigned int hi : 25;
    int f8;
    int fC;
    short f10;
};

extern "C" void func_00345430(void* self, int arg)
{
    cWorld00345430* w = D_004A5B80_w345430;
    char* list = *(char**)(*(char**)((char*)self + 8) + 0x68);
    int n = *(int*)(list + 0x20);
    char* node = *(char**)(list + 0x24);
    (*(sCtl00345430**)((char*)w + 0xE84))->f10 = -1;
    (*(sCtl00345430**)((char*)w + 0xE84))->mode = 1;
    int i;
    for (i = 0; i < n; i++) {
        if (func_00345638(node) != 0) {
            w->v75(node + 0x10, arg, 10);
        }
        node = *(char**)(node + 0x64);
    }
}
#endif

