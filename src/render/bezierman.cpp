#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* cPSPBezierMan_cPSPBezierMan(void* self);
extern const char D_00492EA0[];

//99.23%
INCLUDE_ASM("render/bezierman", cBezierMan_construct__Fv);
#ifdef SKIP_ASM
void* cBezierMan_construct()
{
    void* mem = cMemMan_alloc(0x9C90, D_00492EA0, 0, 0);
    return cPSPBezierMan_cPSPBezierMan(mem);
}
#endif

INCLUDE_ASM("render/bezierman", func_0038AF30);

//100%
INCLUDE_ASM("render/bezierman", func_0038B0F8);
#ifdef SKIP_ASM
void func_0038D660(void*);
void cMemMan_free(void*);

extern "C" void func_0038B0F8(void* self)
{
    func_0038D660(self);
    if (*(void**)((char*)self + 0x440) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x440));
    }
    if (*(void**)((char*)self + 0x444) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x444));
    }
    if (*(void**)((char*)self + 0x448) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x448));
    }
}
#endif

extern "C" void* func_003739D0(void*);

//100%
INCLUDE_ASM("render/bezierman", func_0038B158__FPv);
#ifdef SKIP_ASM
void* func_0038B158(void* self)
{
    return func_003739D0((char*)self + 0x10);
}
#endif

//100%
INCLUDE_ASM("render/bezierman", func_0038B178__FPv);
#ifdef SKIP_ASM
void func_0038B178(void* self)
{
    *(int*)((char*)self + 0x458) = 0;
    *(int*)((char*)self + 0x3c9c) = 0;
    *(int*)((char*)self + 0x4a60) = 0;
    *(int*)((char*)self + 0x4d84) = 0;
}
#endif

//100%
INCLUDE_ASM("render/bezierman", func_0038B190);
#ifdef SKIP_ASM
struct sBezPatch_B190 {
    void* obj;              // 0x0
    int extra;              // 0x4
    int kind;               // 0x8
    unsigned short tex;     // 0xC
    short pad;
};

struct sBezMixPatch_B190 {
    void* obj;              // 0x0
    int extra;              // 0x4
    int kind;               // 0x8
    unsigned short tex;     // 0xC
    short pad;
    unsigned char types[4]; // 0x10
};

struct sBezMan_B190 {
    char pad_0x0[0x458];
    int n4;                         // 0x458
    sBezPatch_B190 list4[900];      // 0x45C
    int n6;                         // 0x3C9C
    sBezPatch_B190 list6[220];      // 0x3CA0
    int n8;                         // 0x4A60
    sBezPatch_B190 list8[50];       // 0x4A64
    int nMix;                       // 0x4D84
    sBezMixPatch_B190 mix[75];      // 0x4D88
};

struct sBezObj_B190 {
    char pad_0x0[0x1A6];
    unsigned short tex4;    // 0x1A6
    unsigned short tex6;    // 0x1A8
    unsigned short tex8;    // 0x1AA
};

extern "C" void func_0038B190(sBezMan_B190* m, sBezObj_B190* o, unsigned char* t, int unused, int extra)
{
    if (t[0] == t[2] && t[1] == t[3] && t[0] == t[1]) {
        switch (t[0]) {
        case 4:
            if (m->n4 < 900) {
                sBezPatch_B190* e = &m->list4[m->n4++];
                e->extra = extra;
                e->obj = o;
                e->kind = 0;
                e->tex = o->tex4;
            }
            break;
        case 6:
            if (m->n6 < 220) {
                sBezPatch_B190* e = &m->list6[m->n6++];
                e->extra = extra;
                e->kind = 1;
                e->obj = o;
                e->tex = o->tex6;
            }
            break;
        case 8:
            if (m->n8 < 50) {
                sBezPatch_B190* e = &m->list8[m->n8++];
                e->extra = extra;
                e->kind = 2;
                e->obj = o;
                e->tex = o->tex8;
            }
            break;
        }
        return;
    }
    if (m->nMix < 75) {
        sBezMixPatch_B190* e = &m->mix[m->nMix++];
        e->extra = extra;
        e->obj = o;
        int* pk = &e->kind;
        *pk = (t[0] == 8 || t[1] == 8 || t[2] == 8 || t[3] == 8) ? 2 : 0;
        e->tex = o->tex8;
        for (int i = 0; i < 4; i++) {
            e->types[i] = t[i];
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/bezierman", func_0038B338);
#ifdef SKIP_ASM
extern int D_004A44D4;

struct sBezVEntry_B338 {
    short delta;
    short index;
    void (*fn)(void*, void*, void*, void*, void*, int);
};

extern "C" void func_0038B338(void* self, void* a, void* b, void* c, void* d)
{
    if (D_004A44D4 == 0) {
        sBezVEntry_B338* vt = *(sBezVEntry_B338**)((char*)self + 0x4);
        vt[22].fn((char*)self + vt[22].delta, a, b, c, d, 0);
    }
}
#endif

INCLUDE_ASM("render/bezierman", func_0038B370);

INCLUDE_ASM("render/bezierman", func_0038C590);

INCLUDE_ASM("render/bezierman", func_0038C788);

//100%
INCLUDE_ASM("render/bezierman", func_0038CA08);
#ifdef SKIP_ASM
extern void* D_004A5B80;
extern "C" unsigned int func_0037DF88(void* self, void* a1, void* a2);

struct sBezVec4_CA08 {
    float x, y, z, w;
};

extern "C" void func_0038CA08(void* self, void* obj)
{
    char* o = (char*)obj;
    sBezVec4_CA08 a;
    sBezVec4_CA08 b;
    a.x = *(float*)(o + 0x158);
    a.y = *(float*)(o + 0x15C);
    a.z = *(float*)(o + 0x160);
    a.w = 1.0f;
    b.x = *(float*)(o + 0x164);
    b.y = *(float*)(o + 0x168);
    b.z = *(float*)(o + 0x16C);
    b.w = 1.0f;
    func_0037DF88(D_004A5B80, &a, &b);
}
#endif

INCLUDE_ASM("render/bezierman", func_0038CA70);

//100%
INCLUDE_ASM("render/bezierman", func_0038CE20);
#ifdef SKIP_ASM
// func_0038CE20 NEAR 99.95%: only diff is target reloc %lo(D_30000040)/%lo(D_30000030) (p += 0x40 / 0x30) vs our plain immediate; needs splat symbol fix
struct sRS_CE20 {
    unsigned int pad0 : 2;
    unsigned int blend : 2;
    unsigned int rest : 28;
    int f4;
    int f8;
    int fC;
    short tex;
    short tex2;
};
struct sEnt_CE20 {
    sRS_CE20 rs;                    // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};
struct sRing_CE20 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sEnt_CE20 ents[1];              // 0x80
};
struct sGfx_CE20 {
    char pad_0x0[0xE84];
    sRS_CE20* top;                  // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sRing_CE20* ring;               // 0x18F0
};
struct sObj_CE20 {
    char pad_0x0[0xC];
    int flags;                      // 0xC
    char pad_0x10[0x1A0 - 0x10];
    short tex;                      // 0x1A0
    short tex2;                     // 0x1A2
};
struct sPatch_CE20 {
    void* obj;
    int extra;
    int kind;
};
struct sTbl_CE20 {
    int lo;
    int hi;
};
extern sGfx_CE20* D_004A5B80_CE20 __asm__("D_004A5B80");
extern int D_004A44D8;
extern int D_004A44DC;
extern sTbl_CE20 D_00504960[];
extern "C" void* func_0038F708(void* obj, int a1, int a2);
extern "C" unsigned int func_0038CA08_r(void* self, void* obj) __asm__("func_0038CA08");
extern "C" void func_0038D168(void* self, int base, void* obj, int a3, sTbl_CE20* tbl, sPatch_CE20* patch, unsigned int* handle);
extern "C" void func_0038D448(void* self, int a1, sTbl_CE20* tbl, sPatch_CE20* patch, unsigned int a4, unsigned int* handle);

extern "C" void func_0038CE20(void* self, int idx, sPatch_CE20* patch, int* vals, unsigned int* handle)
{
    int base = *(int*)((char*)self + 0x30) + idx * 12;
    sObj_CE20* obj = (sObj_CE20*)func_0038F708(patch->obj, 0x1B0, 2);
    int addr = *(int*)((char*)self + 0x454) + (idx << 8);
    sGfx_CE20* gfx = D_004A5B80_CE20;
    int f18 = (obj->flags & 0x600000) != 0;
    if (f18) {
        if (D_004A44D8 != 0)
            f18 = 0;
    }
    unsigned int r = func_0038CA08_r(self, obj);
    int f23 = r != 0;
    int tex = obj->tex;
    gfx->top->tex = tex;
    if (D_004A44DC != 0)
        f23 = 0;
    int tex2 = obj->tex2;
    gfx->top->tex2 = tex2;
    switch (obj->flags & 0x180000) {
    case 0x80000:
        gfx->top->blend = 2;
        break;
    case 0x100000:
        gfx->top->blend = 1;
        break;
    case 0x180000:
        gfx->top->blend = 3;
        break;
    default:
        gfx->top->blend = 0;
        break;
    }
    unsigned int buf = *handle;
    long* p = (long*)(buf | 0x30000000);
    if (vals != 0) {
        p[0] = 0x10000002;
        p[1] = 0;
        p[2] = ((long)vals[0] << 32) | 0x6E0180D0;
        p[3] = 0;
        p[4] = 0;
        p[5] = (long)0x6C1080C0 << 32;
        p[6] = ((long)((int)patch->obj + 0x40) << 32) | 0x30000010;
        p[7] = 0;
        p += 8;
    }
    p[0] = ((long)addr << 32) | 0x50000000;
    p[2] = 0x10000001;
    p[1] = 0;
    sTbl_CE20* tbl = D_00504960;
    p[3] = 0;
    int ti = patch->extra + 2;
    p[4] = 0;
    p[5] = (long)(tbl[ti].lo | 0x14000000) << 32;
    p += 6;
    unsigned int next = (unsigned int)p & 0x0FFFFFFF;
    *handle = next;
    sRing_CE20* ring = gfx->ring;
    sRS_CE20* rs = gfx->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sEnt_CE20* e = (sEnt_CE20*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    *handle += 0x10;
    if (f18) {
        func_0038D168(self, base, obj, 2, tbl, patch, handle);
    }
    if (f23) {
        func_0038D448(self, 2, tbl, patch, r, handle);
    }
}
#endif

INCLUDE_ASM("render/bezierman", func_0038D168);

INCLUDE_ASM("render/bezierman", func_0038D448);

//100%
INCLUDE_ASM("render/bezierman", func_0038D638);
#ifdef SKIP_ASM
class cBezierVirt {
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
};

extern "C" void func_0038D638(cBezierVirt* self)
{
    self->v17();
}
#endif

//100%
INCLUDE_ASM("render/bezierman", func_0038D660__FPv);
#ifdef SKIP_ASM
void func_0038D660(void* self)
{
}
#endif

INCLUDE_ASM("render/bezierman", func_0038D668);

//100%
INCLUDE_ASM("render/bezierman", func_0038D690);
#ifdef SKIP_ASM
struct sVec3_D690 { float x, y, z; };
struct sQuad_D690 { long lo; long hi; } __attribute__((aligned(16)));
struct sRS_D690 {
    int f0;
    int f4;
    int f8;
    int fC;
    short tex;
    short pad;
};
struct sEnt_D690 {
    sRS_D690 rs;                    // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};
struct sRing_D690 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sEnt_D690 ents[1];              // 0x80
};
struct sGfx_D690 {
    char pad_0x0[0xC4];
    float detailScale;              // 0xC4
    char pad_0xC8[0xE84 - 0xC8];
    sRS_D690* top;                  // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sRing_D690* ring;               // 0x18F0
};
extern float D_004A4348;
extern void* D_004A4474;
extern sGfx_D690* D_004A5B80_D690 __asm__("D_004A5B80");
extern char D_1460[];
extern "C" char* func_0038F460(void* self, unsigned int addr, int size, int flags);
extern "C" unsigned int func_0038F668(void* self, char* end, int arg);

static inline void CopyQuads_D690(char** pp, sQuad_D690* src, int n)
{
    sQuad_D690* d = (sQuad_D690*)*pp;
    sQuad_D690* end = d + n;
    while (d != end) {
        *d++ = *src++;
    }
    *pp = (char*)d;
}

// PORT: uncached (0x30000000) pointers and VU microprogram addresses held in int.
extern "C" void func_0038D690(void* self, void* obj, void* patch, unsigned int* handle)
{
    char* s = (char*)self;
    char* o = (char*)obj;
    if ((*(int*)(o + 0xC) & 0x800000) == 0) {
        return;
    }
    sVec3_D690 d;
    d.z = *(float*)(o + 0x160) - *(float*)(o + 0x16C);
    sGfx_D690* gfx = D_004A5B80_D690;
    d.x = *(float*)(o + 0x158) - *(float*)(o + 0x164);
    d.y = *(float*)(o + 0x15C) - *(float*)(o + 0x168);
    int n = (int)((d.x * d.x + d.y * d.y + d.z * d.z) * (D_004A4348 * 3.3333333249174757e-07f) * gfx->detailScale);
    if (*(int*)((char*)patch + 8) < 2) {
        n /= 2;
    }
    if (n <= 0) {
        return;
    }
    unsigned int buf = *handle;
    char* p = func_0038F460(D_004A4474, buf, -1, 0);
    ((long*)p)[0] = 0x10000018;
    ((long*)p)[1] = 0;
    ((long*)p)[2] = 0;
    ((long*)p)[3] = (long)0x6C168000 << 32;
    *(int*)(s + 0x43C) = n;
    p += 0x20;
    CopyQuads_D690(&p, (sQuad_D690*)(o + 0x40), 16);
    CopyQuads_D690(&p, (sQuad_D690*)(s + 0x3E0), 4);
    CopyQuads_D690(&p, (sQuad_D690*)(s + 0x420), 2);
    ((long*)p)[0] = (long)(((unsigned int)D_1460 >> 3) | 0x14000000) << 32;
    ((long*)p)[1] = (long)0x11000000 << 32;
    p += 0x10;
    unsigned int next = func_0038F668(D_004A4474, p, 4);
    *handle = next;
    sRing_D690* ring = gfx->ring;
    sRS_D690* rs = gfx->top;
    if (ring->count < 0xA28) {
        rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
        int key = *(int*)((char*)ring + 0x69CC0);
        sEnt_D690* e = (sEnt_D690*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
        e->rs = *rs;
        e->buf = buf;
        e->next = next;
        e->key = key;
        e->flag = 0;
    }
    *handle += 0x10;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/bezierman", func_0038D968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sRS_D968 {
    int field_0x0;
    int flagsA;
    int flagsB;
    int field_0xC;
    short tex;
    short pad;
};
struct sCtx_D968 {
    char pad_0x0[0x64];
    int texSel;                                 // 0x64
    char pad_0x68[0xE84 - 0x68];
    sRS_D968* top;                              // 0xE84
    char pad_0xE88[0xF50 - 0xE88];
    int texIds[(0x6B90 - 0xF50) / 4];           // 0xF50
    int field_0x6B90;                           // 0x6B90
};
struct sBezPatch_D968 {
    void* obj;
    int extra;
    int kind;
    unsigned short tex;
    short pad;
};
struct sBezMixPatch_D968 {
    void* obj;
    int extra;
    int kind;
    unsigned short tex;
    short pad;
    unsigned char types[4];
};
struct sBezMan_D968 {
    char pad_0x0[0x4A60];
    int n8;                         // 0x4A60
    sBezPatch_D968 list8[50];       // 0x4A64
    int nMix;                       // 0x4D84
    sBezMixPatch_D968 mix[75];      // 0x4D88
};
extern int D_004A44E0;
extern sCtx_D968* D_004A5B80_D968 __asm__("D_004A5B80");
extern "C" void func_0037D968(sCtx_D968* ctx);
extern "C" void* func_0038F708(void* obj, int a1, int a2);
extern "C" void func_0038D690(void* self, void* obj, void* patch, unsigned int* handle);

extern "C" void func_0038D968(sBezMan_D968* self, unsigned int* a1)
{
    if (D_004A44E0 != 0) {
        return;
    }
    sCtx_D968* ctx = D_004A5B80_D968;
    ctx->top[1] = ctx->top[0];
    sRS_D968* t = ctx->top;
    ctx->top = t + 1;
    int tex = ctx->texIds[ctx->texSel];
    t[1].tex = tex;
    ctx->top->flagsA = (ctx->top->flagsA & ~0x7C) | 0x54;
    ctx->top->flagsB = (ctx->top->flagsB & ~0x3E0) | 0x80;
    ctx->top->flagsA = (ctx->top->flagsA & 0xFE7FFFFF) | 0x800000;
    ctx->top->flagsA = (ctx->top->flagsA & 0xFFCFFFFF) | 0x300000;
    ctx->top->flagsA = (ctx->top->flagsA & 0xFFF00FFF) | 0x5C000;
    ctx->top->flagsA = (ctx->top->flagsA & 0xFFBFFFFF) | 0x400000;
    if (ctx->field_0x6B90 == 0) {
        func_0037D968(ctx);
    }
    ctx->top->field_0x0 = (ctx->top->field_0x0 & ~0x3C0) | 0x100;
    ctx->top->field_0xC = ctx->top->field_0xC & 0xC0000000;
    ctx->top->flagsA = (ctx->top->flagsA & ~3) | 2;
    ctx->top->flagsB = ctx->top->flagsB & 0xE00003FF;
    for (int i = 0; i < self->n8; i++) {
        sBezPatch_D968* e = &self->list8[i];
        func_0038D690(self, func_0038F708(e->obj, 0x1B0, 2), e, a1);
    }
    for (int i = 0; i < self->nMix; i++) {
        sBezMixPatch_D968* e = &self->mix[i];
        if (e->kind > 0) {
            func_0038D690(self, func_0038F708(e->obj, 0x1B0, 2), e, a1);
        }
    }
    ctx->top--;
}
#endif

