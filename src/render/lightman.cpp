#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00492EE0[];
extern void* D_00493650[16];

struct cPSPLightMan;
cPSPLightMan* cPSPLightMan_cPSPLightMan(cPSPLightMan* self);

//100%
INCLUDE_ASM("render/lightman", cLightMan_construct__Fv);
#ifdef SKIP_ASM
void* cLightMan_construct()
{
    void* mem = cMemMan_alloc(0x14, D_00492EE0, 0, 0);
    cPSPLightMan_cPSPLightMan((cPSPLightMan*)mem);
    *(void**)mem = D_00493650;
    return mem;
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DC20);
#ifdef SKIP_ASM
extern "C" void func_0038DC20(void) {

}
#endif

INCLUDE_ASM("render/lightman", func_0038DC28);
//100%
INCLUDE_ASM("render/lightman", func_0038DC48);
#ifdef SKIP_ASM
extern "C" void func_0038DC48(void) {

}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DC50__FPv);
#ifdef SKIP_ASM
void func_0038DC50(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DC58__FPv);
#ifdef SKIP_ASM
void func_0038DC58(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DC60__FPv);
#ifdef SKIP_ASM
void func_0038DC60(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DC68__FPv);
#ifdef SKIP_ASM
void func_0038DC68(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DC70);
#ifdef SKIP_ASM
struct sV3_DC70 {
    float x, y, z;
    sV3_DC70() {}
    sV3_DC70(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    sV3_DC70(const sV3_DC70& o) : x(o.x), y(o.y), z(o.z) {}
};

struct sCol_DC70 {
    float a, r, g, b;
};

struct sLight_DC70 {
    char pad_0x0[0x10];
    int type;               // 0x10
    float intensity;        // 0x14
    char pad_0x18[0x8];
    float r, g, b;          // 0x20
    sV3_DC70 dir;           // 0x2C
    char pos[0x24];         // 0x38
    float cone;             // 0x5C
    char pad_0x60[0x4];
    signed char c64;        // 0x64
    signed char c65;        // 0x65
    char pad_0x66[0xA];
};

class cLightSrc_DC70 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void* v01(int a);
    virtual void* v02(int a);
};

extern "C" float func_0031C128(float x);
// PORT: the unit's empty stubs take (void*); these callers pass more, bound by asm label.
void func_0038DC50_DC70(void* p, sCol_DC70* c, float f) __asm__("func_0038DC50__FPv");
void func_0038DC58_DC70(void* p, sCol_DC70* c, sV3_DC70* d, float f) __asm__("func_0038DC58__FPv");
void func_0038DC60_DC70(void* p, sCol_DC70* c, void* pos, float f, int e) __asm__("func_0038DC60__FPv");
void func_0038DC68_DC70(void* p, sCol_DC70* c, void* pos, sV3_DC70* d, float x, float y, int e, float z) __asm__("func_0038DC68__FPv");

static inline sV3_DC70 Normalize_DC70(float x, float y, float z)
{
    float d2 = x * x + y * y + z * z;
    float d;
    // PORT: sqrt.s (sqrtf without errno check)
    __asm__("sqrt.s %0, %1" : "=f"(d) : "f"(d2));
    if (d != 0.0f) {
        float k = 1.0f / d;
        return sV3_DC70(x * k, y * k, z * k);
    }
    return sV3_DC70(x, y, z);
}

extern "C" void func_0038DC70(cLightSrc_DC70* self, sLight_DC70* lights, int n, int base)
{
    int i;
    for (i = 0; i < n; i++) {
        void** obj = (void**)self->v02(base + i);
        obj[0] = &lights[i];
        sCol_DC70 col;
        col.a = 1.0f;
        col.r = lights[i].r;
        col.g = lights[i].g;
        col.b = lights[i].b;
        switch (lights[i].type) {
        case 0: {
            sV3_DC70 dir = Normalize_DC70(lights[i].dir.x, lights[i].dir.y, lights[i].dir.z);
            func_0038DC58_DC70(obj, &col, &dir, lights[i].intensity);
            break;
        }
        case 2:
            func_0038DC60_DC70(obj, &col, lights[i].pos, lights[i].intensity, lights[i].c64);
            break;
        case 1: {
            char* pos = lights[i].pos;
            sV3_DC70 dir = Normalize_DC70(lights[i].dir.x, lights[i].dir.y, lights[i].dir.z);
            func_0038DC68_DC70(obj, &col, pos, &dir, 1.5707963705062866f - func_0031C128(lights[i].cone), lights[i].intensity, lights[i].c64, (float)lights[i].c65);
            break;
        }
        case 3:
            func_0038DC50_DC70(obj, &col, lights[i].intensity);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DEE8);
#ifdef SKIP_ASM
class cObj0038DEE8 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void* v01(int a);
    virtual void* v02(int a);
};

// PORT: the unit defines func_0038DC50(void*) (an empty stub), but this caller
// passes (void*, int, float); bind the 3-arg call by asm label.
void func_0038DC50_3(void* p, int b, float f) __asm__("func_0038DC50__FPv");

extern "C" void func_0038DEE8(cObj0038DEE8* obj, int a, int b, float f)
{
    func_0038DC50_3(obj->v02(a), b, f);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DF38);
#ifdef SKIP_ASM
class cObj0038DF38 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void* v01(int a);
    virtual void* v02(int a);
};

// PORT: the unit defines func_0038DC58(void*) (an empty stub), but this caller
// passes (void*, int, int, float); bind the 4-arg call by asm label.
void func_0038DC58_4(void* p, int b, int c, float f) __asm__("func_0038DC58__FPv");

extern "C" void func_0038DF38(cObj0038DF38* obj, int a, int b, int c, float f)
{
    func_0038DC58_4(obj->v02(a), b, c, f);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038DF98);
#ifdef SKIP_ASM
class cObj0038DF98 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void* v01(int a);
    virtual void* v02(int a);
};

// PORT: the unit defines func_0038DC60(void*) (an empty stub), but this caller
// passes (void*, int, int, float, int); bind the 5-arg call by asm label.
void func_0038DC60_5(void* p, int b, int c, float f, int d) __asm__("func_0038DC60__FPv");

extern "C" void func_0038DF98(cObj0038DF98* obj, int a, int b, int c, float f, int d)
{
    func_0038DC60_5(obj->v02(a), b, c, f, d);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038E008);
#ifdef SKIP_ASM
class cObj0038E008 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void* v01(int a);
    virtual void* v02(int a);
};

// PORT: the unit defines func_0038DC68(void*) (an empty stub), but this caller
// passes (void*, int, int, int, float, float, int, float); bind the call by asm label.
void func_0038DC68_8(void* p, int b, int c, int d, float x, float y, int e, float z) __asm__("func_0038DC68__FPv");

extern "C" void func_0038E008(cObj0038E008* obj, int a, int b, int c, int d, float x, float y, int e, float z)
{
    func_0038DC68_8(obj->v02(a), b, c, d, x, y, e, z);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038E0A8);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
struct sLmQuadVec4_E118 {
    float x, y, z, w;
    sLmQuadVec4_E118() {}
    sLmQuadVec4_E118(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

// Transforms the 2D point p by the 3x3 row-vector matrix m (rows at +0, +0xC, +0x18).
// Returned by value: the caller passes the hidden result pointer in a0.
extern "C" sLmQuadVec4_E118 func_0038E0A8(float* p, float* m)
{
    sLmQuadVec4_E118 r;
    float x = p[0];
    float y = p[1];
    r.z = 0.0f;
    r.w = 1.0f;
    r.x = m[0] * x + m[3] * y + m[6];
    r.y = m[1] * x + m[4] * y + m[7];
    return r;
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038E118);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
struct sLmQuadVtx_E118 {
    float s;                // 0x0
    float t;                // 0x4
    float q;                // 0x8
    int pad_0xC;
    int c[4];               // 0x10
    sLmQuadVec4_E118 pos;   // 0x20
};

struct sLmQuadVEntry_E118 {
    short delta;
    short index;
    void (*fn)(void*, int, sLmQuadVtx_E118*, int);
};

struct sLmQuadCtx_E118 {
    char pad_0x0[0x10D8];
    sLmQuadVEntry_E118* vtable;      // 0x10D8
};

extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

// Fills the four corner positions of a quad from a rect {x, y, w, h}, then submits it.
extern "C" void func_0038E118(void* self, sLmQuadVtx_E118* v, float* r)
{
    v[0].pos = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    v[1].pos = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    v[2].pos = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    v[3].pos = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, v, 0);
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038E200);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

// Fills the four corner positions of a vertically flipped quad from a rect {x, y, w, h}, then submits it.
extern "C" void func_0038E200(void* self, sLmQuadVtx_E118* v, float* r)
{
    v[1].pos = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    v[3].pos = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    v[0].pos = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    v[2].pos = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, v, 0);
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038E2E8);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

extern "C" sLmQuadVec4_E118 func_0038E0A8(float* p, float* m);

// Builds the four corner positions of a quad from a rect {x, y, w, h}, transforms each by the 3x3 matrix m, then submits it.
extern "C" void func_0038E2E8(void* self, sLmQuadVtx_E118* v, float* r, float* m)
{
    sLmQuadVec4_E118* p0 = &v[0].pos;
    sLmQuadVec4_E118* p1 = &v[1].pos;
    sLmQuadVec4_E118* p2 = &v[2].pos;
    sLmQuadVec4_E118* p3 = &v[3].pos;
    *p0 = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    *p1 = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    *p2 = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    *p3 = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    *p0 = func_0038E0A8(&p0->x, m);
    *p1 = func_0038E0A8(&p1->x, m);
    *p2 = func_0038E0A8(&p2->x, m);
    *p3 = func_0038E0A8(&p3->x, m);
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, v, 0);
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038E468);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

extern "C" sLmQuadVec4_E118 func_0038E0A8(float* p, float* m);

// Builds the four corner positions of a vertically flipped quad from a rect {x, y, w, h}, transforms each by the 3x3 matrix m, then submits it.
extern "C" void func_0038E468(void* self, sLmQuadVtx_E118* v, float* r, float* m)
{
    sLmQuadVec4_E118* p0 = &v[0].pos;
    sLmQuadVec4_E118* p1 = &v[1].pos;
    sLmQuadVec4_E118* p2 = &v[2].pos;
    sLmQuadVec4_E118* p3 = &v[3].pos;
    *p1 = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    *p3 = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    *p0 = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    *p2 = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    *p0 = func_0038E0A8(&p0->x, m);
    *p1 = func_0038E0A8(&p1->x, m);
    *p2 = func_0038E0A8(&p2->x, m);
    *p3 = func_0038E0A8(&p3->x, m);
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, v, 0);
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038E5E8);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

// Fills the four corner positions (from rect {x, y, w, h}) and texture coords (from rect uv {u, v, w, h}) of a quad, then submits it.
extern "C" void func_0038E5E8(void* self, sLmQuadVtx_E118* vtx, float* r, float* uv)
{
    vtx[0].pos = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    vtx[0].s = uv[0];
    vtx[0].t = uv[1];
    vtx[1].pos = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    vtx[1].s = uv[0] + uv[2];
    vtx[1].t = uv[1];
    vtx[2].pos = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    vtx[2].s = uv[0];
    vtx[2].t = uv[1] + uv[3];
    vtx[3].pos = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    vtx[3].s = uv[0] + uv[2];
    vtx[3].t = uv[1] + uv[3];
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, vtx, 0);
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038E738);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

// Fills the four corner positions (from rect {x, y, w, h}) and texture coords (from rect uv {u, v, w, h}) of a quad, (rotated mapping), then submits it.
extern "C" void func_0038E738(void* self, sLmQuadVtx_E118* vtx, float* r, float* uv)
{
    vtx[0].pos = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    vtx[0].s = uv[0] + uv[2];
    vtx[0].t = uv[1];
    vtx[1].pos = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    vtx[1].s = uv[0] + uv[2];
    vtx[1].t = uv[1] + uv[3];
    vtx[2].pos = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    vtx[2].s = uv[0];
    vtx[2].t = uv[1];
    vtx[3].pos = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    vtx[3].s = uv[0];
    vtx[3].t = uv[1] + uv[3];
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, vtx, 0);
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038E880);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

extern "C" sLmQuadVec4_E118 func_0038E0A8(float* p, float* m);

// Fills the four corner positions (from rect {x, y, w, h}) and texture coords (from rect uv {u, v, w, h}) of a quad, transforms each position by the 3x3 matrix m, then submits it.
extern "C" void func_0038E880(void* self, sLmQuadVtx_E118* vtx, float* r, float* uv, float* m)
{
    sLmQuadVec4_E118* p0 = &vtx[0].pos;
    sLmQuadVec4_E118* p1 = &vtx[1].pos;
    sLmQuadVec4_E118* p2 = &vtx[2].pos;
    sLmQuadVec4_E118* p3 = &vtx[3].pos;
    *p0 = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    vtx[0].s = uv[0];
    vtx[0].t = uv[1];
    *p1 = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    vtx[1].s = uv[0] + uv[2];
    vtx[1].t = uv[1];
    *p2 = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    vtx[2].s = uv[0];
    vtx[2].t = uv[1] + uv[3];
    *p3 = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    vtx[3].s = uv[0] + uv[2];
    vtx[3].t = uv[1] + uv[3];
    *p0 = func_0038E0A8(&p0->x, m);
    *p1 = func_0038E0A8(&p1->x, m);
    *p2 = func_0038E0A8(&p2->x, m);
    *p3 = func_0038E0A8(&p3->x, m);
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, vtx, 0);
}
#endif
//100%
INCLUDE_ASM("render/lightman", func_0038EA60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

extern "C" sLmQuadVec4_E118 func_0038E0A8(float* p, float* m);

// Fills the four corner positions (from rect {x, y, w, h}) and texture coords (from rect uv {u, v, w, h}) of a quad (rotated mapping), transforms each position by the 3x3 matrix m, then submits it.
extern "C" void func_0038EA60(void* self, sLmQuadVtx_E118* vtx, float* r, float* uv, float* m)
{
    sLmQuadVec4_E118* p0 = &vtx[0].pos;
    sLmQuadVec4_E118* p1 = &vtx[1].pos;
    sLmQuadVec4_E118* p2 = &vtx[2].pos;
    sLmQuadVec4_E118* p3 = &vtx[3].pos;
    *p0 = sLmQuadVec4_E118(r[0], r[1], 0.0f, 1.0f);
    vtx[0].s = uv[0] + uv[2];
    vtx[0].t = uv[1];
    *p1 = sLmQuadVec4_E118(r[0] + r[2], r[1], 0.0f, 1.0f);
    vtx[1].s = uv[0] + uv[2];
    vtx[1].t = uv[1] + uv[3];
    *p2 = sLmQuadVec4_E118(r[0], r[1] + r[3], 0.0f, 1.0f);
    vtx[2].s = uv[0];
    vtx[2].t = uv[1];
    *p3 = sLmQuadVec4_E118(r[0] + r[2], r[1] + r[3], 0.0f, 1.0f);
    vtx[3].s = uv[0];
    vtx[3].t = uv[1] + uv[3];
    *p0 = func_0038E0A8(&p0->x, m);
    *p1 = func_0038E0A8(&p1->x, m);
    *p2 = func_0038E0A8(&p2->x, m);
    *p3 = func_0038E0A8(&p3->x, m);
    sLmQuadCtx_E118* g = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, vtx, 0);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038EC40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sLmQuadVec4 {
    float x, y, z, w;
    sLmQuadVec4() {}
    sLmQuadVec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sLmQuadVtx {
    float s;                // 0x0
    float t;                // 0x4
    float q;                // 0x8
    int pad_0xC;
    int c[4];               // 0x10
    sLmQuadVec4 pos;        // 0x20
};

struct sLmQuadVEntry {
    short delta;
    short index;
    void (*fn)(void*, int, sLmQuadVtx*, int);
};

struct sLmQuadCtx {
    char pad_0x0[0x10D8];
    sLmQuadVEntry* vtable;      // 0x10D8
};

extern sLmQuadCtx* D_004A5B80_EC40 __asm__("D_004A5B80");

extern "C" void func_0038EC40(void* self, float* p0, float* p1, float* col, float z)
{
    sLmQuadVtx v[4];
    float zero = 0.0f;
    float one = 1.0f;
    v[0].q = one;
    v[0].c[0] = (int)(col[1] * 255.0f);
    v[0].c[1] = (int)(col[2] * 255.0f);
    v[0].c[2] = (int)(col[3] * 255.0f);
    v[0].c[3] = (int)(col[0] * 128.0f);
    v[0].pos = sLmQuadVec4(p0[0], p0[1], z, one);
    v[3] = v[0];
    v[2] = v[0];
    v[1] = v[0];
    v[3].pos.x = p1[0];
    v[1].pos.x = p1[0];
    v[3].pos.y = p1[1];
    v[2].pos.y = p1[1];
    v[0].t = zero;
    v[0].s = zero;
    v[1].s = one;
    v[1].t = zero;
    v[2].s = zero;
    v[2].t = one;
    v[3].s = one;
    v[3].t = one;
    sLmQuadCtx* g = D_004A5B80_EC40;
    sLmQuadVEntry* vt = g->vtable;
    vt[71].fn((char*)g + vt[71].delta, 4, v, 0);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038ED90);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
extern sLmQuadCtx_E118* D_004A5B80_E118 __asm__("D_004A5B80");

// Submits two coloured points/vertices at the positions *p0 and *p1; col is {alpha, r, g, b} in 0..1.
extern "C" void func_0038ED90(void* self, sLmQuadVec4_E118* p0, sLmQuadVec4_E118* p1, float* col)
{
    sLmQuadVtx_E118 v[2];
    int r = (int)(col[1] * 255.0f);
    int g = (int)(col[2] * 255.0f);
    int b = (int)(col[3] * 255.0f);
    int a = (int)(col[0] * 128.0f);
    v[0].pos = *p0;
    v[1].pos = *p1;
    v[1].c[0] = r;
    v[1].c[1] = g;
    v[1].c[2] = b;
    v[1].c[3] = a;
    v[0].c[0] = r;
    v[0].c[1] = g;
    v[0].c[2] = b;
    v[0].c[3] = a;
    sLmQuadCtx_E118* ctx = D_004A5B80_E118;
    sLmQuadVEntry_E118* vt = ctx->vtable;
    vt[73].fn((char*)ctx + vt[73].delta, 2, v, 0);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038EE78);
#ifdef SKIP_ASM
extern "C" float func_0031BF60(float a);
extern "C" float func_0031C040(float a);
extern "C" void func_0031BE50(float* s, float* c, float angle);

struct sLmMat_EE78 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sLmVEntry_EE78 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sLmCtx_EE78 {
    char pad_0x0[0x10D8];
    sLmVEntry_EE78* vtable;      // 0x10D8
};

extern sLmCtx_EE78* D_004A5B80_EE78 __asm__("D_004A5B80");
extern sLmMat_EE78 D_00504D80_EE78[] __asm__("D_00504D80");
extern sLmMat_EE78 D_004FF1A0;
extern float D_004FF160[3];
extern int D_004A445C;
extern float D_004A4448;
extern float D_004A444C;
extern float D_004A4450;
extern float D_004A4454;
extern float D_004A4460;
extern float D_004A4464;
extern float D_004A4468;
extern float D_004A446C;
extern float D_004A4470;

// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
static inline void lmCopy_EE78(void* dst, const void* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply); the PC port needs a plain matrix multiply.
static inline void lmMul_EE78(void* out, const void* a, const void* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
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
        : "r"(out), "r"(a), "r"(b)
        : "memory");
}


// PORT: PS2-only VU0 inline asm (in-place 4x4 matrix multiply m = m * b); the PC port needs a plain matrix multiply.
static inline void lmMulIn_EE78(void* m, const void* b)
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
        : "r"(m), "r"(b)
        : "memory");
}

extern "C" void func_0038EE78(void)
{
    sLmMat_EE78 m0;
    sLmMat_EE78 r;
    sLmMat_EE78 tmp;
    float s;
    float c;
    sLmCtx_EE78* g = D_004A5B80_EE78;
    sLmVEntry_EE78* vt = g->vtable;
    float t = (float)vt[114].fn((char*)g + vt[114].delta);
    int i;
    for (i = 0; i < 8; i++) {
        sLmMat_EE78* pm = &m0;
        float fi = (float)i * 0.125f;
        float amp = D_004A4448 * func_0031BF60(fi + t * (float)D_004A445C * 0.0016666667f) + D_004A444C;
        float b = func_0031BF60(fi + t * D_004A4464 * 0.0016666667f);
        float amp2 = D_004A4450 * func_0031BF60(fi * D_004A4468 * 0.0016666667f + b);
        float angle = D_004A4454 * func_0031BF60(fi + t * D_004A4460 * 0.0016666667f);
        lmCopy_EE78(&m0, &D_004FF1A0);
        func_0031BE50(&s, &c, angle);
        float tc = 1.0f - c;
        float x = D_004FF160[0];
        float y = D_004FF160[1];
        float z = D_004FF160[2];
        float tx = tc * x;
        float ty = tc * y;
        float tz = tc * z;
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
        r.m[0][3] = 0.0f;
        r.m[1][3] = 0.0f;
        r.m[2][3] = 0.0f;
        r.m[3][3] = 1.0f;
        lmMulIn_EE78(pm, &r);
        sLmMat_EE78* cell = &D_00504D80_EE78[i];
        lmCopy_EE78(cell, &D_004FF1A0);
        cell->m[2][0] += func_0031BF60(D_004A446C * 0.017453294f) * amp;
        cell->m[2][1] += func_0031C040(D_004A446C * 0.017453294f) * amp;
        m0.m[0][2] += amp2 * func_0031BF60(D_004A4470 * 0.017453294f);
        m0.m[1][2] += amp2 * func_0031C040(D_004A4470 * 0.017453294f);
        lmMul_EE78(&tmp, cell, &m0);
        lmCopy_EE78(&r, &tmp);
        lmCopy_EE78(cell, &r);
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F2A8);
#ifdef SKIP_ASM
extern float D_004A4458;

struct sLmCell_F2A8 {
    char data[0x40];
};
extern sLmCell_F2A8 D_00504D80[];

extern "C" sLmCell_F2A8* func_0038F2A8(float* pos)
{
    float d2 = pos[0] * pos[0] + pos[1] * pos[1];
    float d;
    // PORT: sqrt.s (sqrtf without errno check)
    __asm__("sqrt.s %0, %1" : "=f"(d) : "f"(d2));
    int i = (int)(D_004A4458 * d);
    return &D_00504D80[i % 8];
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F300);
#ifdef SKIP_ASM
extern "C" void func_0038F768(void);
extern "C" void func_0038F7B0(void);
// PORT: the unit declares D_004A5B84 as int further down; bind a pointer view by asm label
extern char* D_004A5B84_F300 __asm__("D_004A5B84");

struct sLightBufs_F300 {
    int mode;        // 0x0
    int count;       // 0x4
    int f8;          // 0x8
    int fC;          // 0xC
    int stride;      // 0x10
    char* buf[3];    // 0x14
    int f20[3];      // 0x20
    int f2C[3];      // 0x2C
};

extern "C" void func_0038F300(sLightBufs_F300* self, int mode)
{
    int i;
    if (self->mode == mode) {
        return;
    }
    self->mode = mode;
    switch (mode) {
    case 1: self->count = 1; break;
    case 2: self->count = 2; break;
    case 3: self->count = 2; break;
    case 4: self->count = 2; break;
    case 5: self->count = 2; break;
    case 6:
    case 7:
        self->count = 3;
        break;
    }
    self->f8 = 0;
    self->fC = 0;
    switch (mode) {
    case 1: self->stride = 0x400; break;
    case 2: self->stride = 0x200; break;
    case 3: self->stride = 0x1C0; break;
    case 4: self->stride = 0x180; break;
    case 6: self->stride = 0x140; break;
    case 5:
    case 7:
        self->stride = 0x100;
        break;
    }
    for (i = 0; i < self->count; i++) {
        self->buf[i] = (char*)0x70000000 + self->stride * i * 16;
        self->f20[i] = 0;
        self->f2C[i] = 0;
    }
    int total = self->stride * self->count;
    if (total < 0x400) {
        D_004A5B84_F300 = (char*)0x70000000 + total * 16;
    } else {
        D_004A5B84_F300 = 0;
    }
    func_0038F768();
    func_0038F7B0();
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F460);
#ifdef SKIP_ASM
struct sLightRing {
    int field_0x0;
    int count;        // 0x4
    int next;         // 0x8
    int field_0xC;
    int defSize;      // 0x10
    int result[3];    // 0x14
    unsigned int addr[3]; // 0x20
    int size[3];      // 0x2C
};

extern "C" void func_0038F768(void);

extern "C" int func_0038F460(void* self, unsigned int addr, int size, int flags)
{
    sLightRing* r = (sLightRing*)self;
    if (flags & 4) {
        func_0038F768();
    }
    if (size < 0) {
        size = r->defSize;
    } else {
        size >>= 4;
    }
    int i = r->next++;
    r->next %= r->count;
    r->addr[i] = addr;
    r->size[i] = size;
    return r->result[i];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/lightman", func_0038F4F8);
#ifdef SKIP_ASM
extern "C" int func_0038F460(void* self, unsigned int addr, int size, int flags);
extern "C" void func_00371D10(unsigned int madr, int sadr, int qwc, int flags);

extern "C" int func_0038F4F8(void* self, unsigned int addr, int size, int flags)
{
    int r = func_0038F460(self, addr, size, 0);
    func_00371D10(addr, r, size >> 4, flags);
    return r;
}
#endif

INCLUDE_ASM("render/lightman", func_0038F560);

//100%
INCLUDE_ASM("render/lightman", func_0038F598);
#ifdef SKIP_ASM
struct sLightDma_F598 {
    int field_0x0;
    int count;              // 0x4
    int next;               // 0x8
    int cur;                // 0xC
    int defSize;            // 0x10
    int result[3];          // 0x14
    unsigned int addr[3];   // 0x20
};

extern "C" void func_0038F768(void);
extern "C" void func_0038F6A8(void* self);
extern "C" void func_00371DD8(int sadr, unsigned int madr, int qwc, int flags);

// PORT: the unit declares func_0038F598 as `void (sLmStack*, int, int, int)`; the body takes
// (self, size, flags) and returns the buffer address, so it is bound by asm label.
unsigned int func_0038F598_impl(sLightDma_F598* self, int size, int flags) __asm__("func_0038F598");

unsigned int func_0038F598_impl(sLightDma_F598* self, int size, int flags)
{
    if (size == 0) {
        if (flags & 6) {
            func_0038F768();
        }
        unsigned int r = self->addr[self->cur];
        func_0038F6A8(self);
        return r;
    }
    size >>= 4;
    // PORT: EE sync (memory barrier before kicking the DMA)
    __asm__ __volatile__("sync");
    unsigned int* addrs = self->addr;
    func_00371DD8(self->result[self->cur], *(unsigned int*)((char*)addrs + (self->cur << 2)), size, flags);
    int cur = self->cur;
    unsigned int r = *(unsigned int*)((char*)addrs + (cur << 2)) + (size << 4);
    self->cur = (cur + 1) % self->count;
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/lightman", func_0038F668);
#ifdef SKIP_ASM
struct sLmStack {
    char pad_0x00[0xC];
    int depth;          // 0x0C
    char pad_0x10[4];
    int marks[1];       // 0x14
};

extern "C" void func_0038F598(sLmStack* self, int size, int arg, int base);

extern "C" void func_0038F668(sLmStack* self, int end, int arg)
{
    int base = self->marks[self->depth];
    int size = end - base;
    func_0038F598(self, size + (-size & 0xF), arg, base);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F6A8);
#ifdef SKIP_ASM
extern "C" void func_0038F6A8(void* self)
{
    *(int*)((char*)self + 0xC) = (*(int*)((char*)self + 0xC) + 1) % *(int*)((char*)self + 0x4);
}
#endif

INCLUDE_ASM("render/lightman", func_0038F6D0);

//100%
INCLUDE_ASM("render/lightman", func_0038F708);
#ifdef SKIP_ASM
extern int D_004A5B84;
extern "C" void func_00371D10(unsigned int madr, int sadr, int qwc, int flags);

extern "C" int func_0038F708(unsigned int madr, int size, int flags)
{
    func_00371D10(madr, D_004A5B84, size >> 4, flags);
    return D_004A5B84;
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F738);
#ifdef SKIP_ASM
extern int D_004A5B84;
extern "C" void func_00371DD8(int sadr, unsigned int madr, int qwc, int flags);

extern "C" void func_0038F738(unsigned int madr, int size, int flags)
{
    func_00371DD8(D_004A5B84, madr, size >> 4, flags);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F768);
#ifdef SKIP_ASM
// PORT: polls PS2 hardware register 0x1000D000 directly; needs a platform shim.
extern "C" void func_0038F768(void)
{
    while (*(volatile int*)0x1000D000 & 0x100) {
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F7B0);
#ifdef SKIP_ASM
// PORT: polls PS2 hardware register 0x1000D400 directly; needs a platform shim.
extern "C" void func_0038F7B0(void)
{
    while (*(volatile int*)0x1000D400 & 0x100) {
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_0038F7F8__FPv);
#ifdef SKIP_ASM
void func_0038F7F8(void* self)
{
}
#endif

extern "C" void* func_002BB6B8(void* self);

//100%
INCLUDE_ASM("render/lightman", func_0038F800__FPv);
#ifdef SKIP_ASM
void* func_0038F800(void* self)
{
    return func_002BB6B8(self);
}
#endif

INCLUDE_ASM("render/lightman", func_0038F820);

//100%
INCLUDE_ASM("render/lightman", func_0038F930);
#ifdef SKIP_ASM
extern int D_0044BDE0[];

extern "C" int func_0038F930(void* self, unsigned char* src, unsigned char* dst)
{
    unsigned int n = 0;
    unsigned int i;
    for (i = 0; i < 4; i++) {
        unsigned int k = (i & 1) * 64;
        unsigned int j;
        for (j = 0; j < 16; j++) {
            unsigned int m;
            for (m = 0; m < 4; m++) {
                dst[n] = src[D_0044BDE0[k]];
                k++;
                n++;
            }
        }
        src += 0x40;
    }
    return 0;
}
#endif

INCLUDE_ASM("render/lightman", func_0038F9C0);

//100%
INCLUDE_ASM("render/lightman", func_0038FC48);
#ifdef SKIP_ASM
struct sRow16_FC48 {
    unsigned char b[16];
};

struct sRow32_FC48 {
    unsigned char b[32];
};

extern int D_0044C160[];
extern int D_0044C0E0[];
extern "C" void* func_00416210(void* dst, int c, int n);

extern "C" int func_0038FC48(void* self, int w, int h, unsigned char* src, unsigned char* dst)
{
    int xmap[32];
    int ymap[32];
    unsigned char block[0x100];
    unsigned char out[0x100];
    int n = 0;
    int i;
    int j;
    int k;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            int t = D_0044C160[n++];
            xmap[t] = j;
            ymap[t] = i;
        }
    }
    int bw = w / 16;
    int bh = h / 16;
    int spitch = 0x80;
    int dpitch = 0x100;
    func_00416210(block, 0, 0x100);
    func_00416210(out, 0, 0x100);
    for (i = 0; i < bh; i++) {
        for (j = 0; j < bw; j++) {
            int id = D_0044C0E0[i * bw + j];
            sRow16_FC48* s = (sRow16_FC48*)(src + (i * 16) * spitch + j * 16);
            sRow16_FC48* d = (sRow16_FC48*)block;
            for (k = 0; k < 16; k++) {
                *d = *s;
                d++;
                s += 8;
            }
            func_0038F930(self, block, out);
            sRow32_FC48* s2 = (sRow32_FC48*)out;
            sRow32_FC48* d2 = (sRow32_FC48*)(dst + (ymap[id] * 8) * dpitch + xmap[id] * 32);
            for (k = 0; k < 8; k++) {
                *d2 = *s2;
                s2++;
                d2 += 8;
            }
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("render/lightman", func_0038FED0);

INCLUDE_ASM("render/lightman", func_00390198);

//100%
INCLUDE_ASM("render/lightman", func_00390458);
#ifdef SKIP_ASM
extern float D_004A45E4;
extern float D_004A45E8;
extern float D_004A45EC;
extern float D_004A45F0;
extern float D_004A45F4;
extern float D_004A45F8;

struct sLmEntry_0458 {
    float v[6];
};

struct sLmOwner_0458 {
    char pad[0x6CA4];
    sLmEntry_0458 entries[1];
};

extern "C" void func_00390458(void* self, int idx)
{
    char* e = (char*)&((sLmOwner_0458*)self)->entries[idx];
    *(float*)(e + 0x0) = D_004A45E4;
    *(float*)(e + 0x4) = D_004A45E8;
    *(float*)(e + 0x8) = D_004A45EC;
    *(float*)(e + 0xC) = D_004A45F0;
    *(float*)(e + 0x10) = D_004A45F4;
    *(float*)(e + 0x14) = D_004A45F8;
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_003904A0);
#ifdef SKIP_ASM
extern int D_004A45D8;
extern int D_004A45DC;
extern void* D_004A4474;

extern "C" void func_003905E8(void* self, int idx, int* mark);
// PORT: func_0038F668 is declared void in this unit, but it returns its tail call's
// value and this caller uses it; bind an int-returning view to the same symbol.
extern "C" int func_0038F668_r(void* self, int end, int arg) __asm__("func_0038F668");
extern "C" void func_00368138(void* self, void* pkt);

extern "C" void func_003904A0(void* self, int idx, void* pkt, int* addr)
{
    if (D_004A45D8 == 0) {
        return;
    }
    if (D_004A45DC != 0) {
        func_00390458(self, idx);
    }
    float* e = ((sLmOwner_0458*)self)->entries[idx].v;
    if (e[0] == 1.0f && e[1] == 1.0f && e[2] == 1.0f && e[3] == 0.0f && e[4] == 0.0f && e[5] == 0.0f) {
        return;
    }
    void* ring = D_004A4474;
    int mark = func_0038F460(ring, *addr, -1, 0);
    func_003905E8(self, idx, &mark);
    *addr = func_0038F668_r(ring, mark, 4);
    func_00368138(*(void**)((char*)self + 0x18F4), pkt);
}
#endif

INCLUDE_ASM("render/lightman", func_003905E8);

//100%
INCLUDE_ASM("render/lightman", func_00390C20);
#ifdef SKIP_ASM
extern char* D_004A5B80;
extern int D_004A44C0;
extern int D_004A44C8;

struct sLmVEntry_0C20 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00390C20()
{
    char* mgr = D_004A5B80;
    sLmVEntry_0C20* vt = *(sLmVEntry_0C20**)(mgr + 0x10D8);
    vt[16].fn(mgr + vt[16].delta, D_004A44C0);
    if (D_004A44C8 != 0) {
        D_004A44C8 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00390C60);
#ifdef SKIP_ASM
extern int D_004A460C;
extern int D_004A46B4;
extern int D_004A4698;
extern int D_004A469C;
extern int D_004A4610;
extern float D_004A4614;
extern int D_004A4618;
extern int D_004A461C;
extern int D_004A4620;
extern int D_004A4624;
extern float D_004A4628;
extern float D_004A462C;
extern float D_004A4630;
extern float D_004A4634;
extern float D_004A4638;
extern float D_004A463C;
extern float D_004A4640;
extern float D_004A4644;
extern float D_004A4648;
extern float D_004A464C;
extern float D_004A4650;
extern float D_004A4654;
extern float D_004A45E4;
extern float D_004A45E8;
extern float D_004A45EC;
extern float D_004A46A0;
extern float D_004A46A4;
extern float D_004A46A8;
extern int D_004A46AC;
int BXrand();
extern "C" void func_00390EC8(float t);

static inline float RandF_0C60()
{
    union {
        int i;
        float f;
    } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

static inline float RandRange_0C60(float lo, float hi)
{
    return RandF_0C60() * (hi - lo) + lo;
}

// PORT: D_004A469C holds a float (declared int elsewhere in the unit).
extern "C" void func_00390C60()
{
    if (D_004A460C == 0) {
        return;
    }
    if (D_004A46B4 > 0) {
        D_004A46B4--;
    }
    int t = D_004A4698;
    int trig = D_004A4610;
    if (t < 0) {
        if (RandF_0C60() < D_004A4614 * D_004A4614) {
            func_00390EC8(RandRange_0C60(0.019999999552965164f, 2.0f) * 100000.0f);
        }
        return;
    }
    if (trig < 0 || D_004A4618 + D_004A461C + D_004A4620 + D_004A4624 < trig) {
        D_004A4698 = t + 1;
    } else {
        D_004A4698 = trig;
    }
    int cur = D_004A4698;
    int d0 = D_004A4618;
    if (cur <= d0) {
        *(float*)&D_004A469C = ((float)cur / (float)d0) * D_004A4628;
        D_004A46A0 = D_004A4634;
        D_004A46A4 = D_004A4638;
        D_004A46A8 = D_004A463C;
        D_004A46AC = 5;
    } else if (cur <= d0 + D_004A461C) {
        *(float*)&D_004A469C = D_004A4628;
        D_004A46A0 = D_004A4634;
        D_004A46A4 = D_004A4638;
        D_004A46A8 = D_004A463C;
        D_004A46AC = 5;
    } else if (cur <= d0 + D_004A461C + D_004A4620) {
        *(float*)&D_004A469C = D_004A462C;
        D_004A46A0 = D_004A4640;
        D_004A46A4 = D_004A4644;
        D_004A46A8 = D_004A4648;
        D_004A46AC = 5;
    } else if (cur <= d0 + D_004A461C + D_004A4620 + D_004A4624) {
        *(float*)&D_004A469C = (1.0f - ((float)cur - (float)d0 - (float)D_004A461C - (float)D_004A4620) / (float)D_004A4624) * D_004A4630;
        D_004A46A0 = D_004A464C;
        D_004A46A4 = D_004A4650;
        D_004A46A8 = D_004A4654;
        D_004A46AC = 5;
    } else {
        D_004A4698 = -1;
        D_004A46A0 = D_004A45E4;
        D_004A46A4 = D_004A45E8;
        D_004A46A8 = D_004A45EC;
        D_004A46AC = 5;
        *(float*)&D_004A469C = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00390EC8);
#ifdef SKIP_ASM
extern int D_004A460C;
extern int D_004A4698;
extern int D_004A469C;
extern float D_004A46B0;
extern int D_004A46B4;

extern "C" void func_00390EC8(float t)
{
    if (D_004A460C != 0) {
        D_004A4698 = 0;
        D_004A469C = 0;
        D_004A46B0 = t;
        D_004A46B4 = (int)(t * 0.0018072288949042559f);
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00390EF8);
#ifdef SKIP_ASM
extern int D_004A460C;
extern int D_004A46B4;

extern "C" int func_00390EF8()
{
    if (D_004A460C != 0 && D_004A46B4 == 0) {
        D_004A46B4 = -1;
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("render/lightman", func_00390F20);

//100%
INCLUDE_ASM("render/lightman", func_003912A8);
#ifdef SKIP_ASM
extern char D_0043BD00[];
extern "C" void func_00424020(int);

// PORT: kicks a DMA chain on channel 0 (VIF0) through the PS2 hardware registers at
// 0x10008000 (CHCR), 0x10008020 (QWC) and 0x10008030 (TADR); needs a platform shim.
extern "C" void func_003912A8(void)
{
    while (*(volatile int*)0x10008000 & 0x100) {
    }
    *(volatile int*)0x10008030 = (int)D_0043BD00;
    *(volatile int*)0x10008020 = 0;
    *(volatile int*)0x10008000 = 0x104;
    while (*(volatile int*)0x10008000 & 0x100) {
    }
    func_00424020(0);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00391360);
#ifdef SKIP_ASM
extern char D_0043CCA0[];
extern "C" void func_00424020(int);

// PORT: kicks a DMA chain on channel 0 (VIF0) through the PS2 hardware registers at
// 0x10008000 (CHCR), 0x10008020 (QWC) and 0x10008030 (TADR); needs a platform shim.
extern "C" void func_00391360(void)
{
    while (*(volatile int*)0x10008000 & 0x100) {
    }
    *(volatile int*)0x10008030 = (int)D_0043CCA0;
    *(volatile int*)0x10008020 = 0;
    *(volatile int*)0x10008000 = 0x104;
    while (*(volatile int*)0x10008000 & 0x100) {
    }
    func_00424020(0);
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00391418);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (lqc2 x16 into vf1-vf16, then vcallmsr of the
// microprogram at VU0 micro-memory address 0); the PC port needs a C version.
extern "C" void func_00391418(void* self, void* m)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "lqc2      $vf5, 0x40(%0)\n"
        "lqc2      $vf6, 0x50(%0)\n"
        "lqc2      $vf7, 0x60(%0)\n"
        "lqc2      $vf8, 0x70(%0)\n"
        "lqc2      $vf9, 0x80(%0)\n"
        "lqc2      $vf10, 0x90(%0)\n"
        "lqc2      $vf11, 0xA0(%0)\n"
        "lqc2      $vf12, 0xB0(%0)\n"
        "lqc2      $vf13, 0xC0(%0)\n"
        "lqc2      $vf14, 0xD0(%0)\n"
        "lqc2      $vf15, 0xE0(%0)\n"
        "lqc2      $vf16, 0xF0(%0)\n"
        "lui       $2, 0\n"
        "addiu     $2, $2, 0\n"
        "srl       $2, $2, 3\n"
        "ctc2.ni   $2, $vi27\n"
        "vnop\n"
        "vnop\n"
        "vcallmsr  $vi27\n"
        ".set pop\n"
        :
        : "r"(m)
        : "$2", "memory");
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00391480);
#ifdef SKIP_ASM
struct sQuad16 {
    int w[4];
} __attribute__((aligned(16)));

extern "C" void func_00391480(void* self, sQuad16* dst)
{
    sQuad16* src = (sQuad16*)0x11004200;
    int i;
    for (i = 0; i < 10; i++) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
        dst[8] = src[8];
        dst[9] = src[9];
        src += 10;
        dst += 10;
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_003914F8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 integer register read (vi1); the PC port needs a C fallback.
extern "C" int func_003914F8(void)
{
    int r;
    __asm__ __volatile__("cfc2.i %0, $vi1" : "=r"(r));
    return r;
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00391508);
#ifdef SKIP_ASM
struct sV2_1508 {
    float x, y;
    sV2_1508() {}
    sV2_1508(float ax, float ay) : x(ax), y(ay) {}
};
struct sV4_1508 {
    float x, y, z, w;
    sV4_1508() {}
    sV4_1508(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

extern "C" void* func_00391508(char* self)
{
    *(sV2_1508*)(self + 0x28) = sV2_1508(0.0f, 0.0f);
    *(sV2_1508*)(self + 0x30) = sV2_1508(1.0f, 1.0f);
    *(sV2_1508*)(self + 0x38) = *(sV2_1508*)(self + 0x30);
    {
        sV4_1508 t;
        t.x = 1.0f; t.y = 1.0f; t.z = 1.0f; t.w = 1.0f;
        *(sV4_1508*)(self + 0x40) = t;
    }
    *(sV4_1508*)(self + 0x50) = sV4_1508(1.0f, 0.0f, 0.0f, 0.0f);
    *(int*)(self + 0x60) = -1;
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x4) = 0;
    *(int*)(self + 0x8) = 0;
    *(int*)(self + 0x14) = 0;
    *(int*)(self + 0xC) = 0;
    *(int*)(self + 0x10) = 0;
    *(char*)(self + 0x64) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_003915E8);
#ifdef SKIP_ASM
struct sLmVec2_15E8 {
    float x, y;

    sLmVec2_15E8() {}
    sLmVec2_15E8(float a, float b)
    {
        x = a;
        y = b;
    }
};

struct sLmVec4_15E8 {
    float x, y, z, w;

    sLmVec4_15E8() {}
    sLmVec4_15E8(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct sLmLight_15E8 {
    char pad_0x0[0x8];
    int field_0x8;          // 0x8
    char pad_0xc[0x1C];
    sLmVec2_15E8 v28;       // 0x28
    sLmVec2_15E8 v30;       // 0x30
    sLmVec2_15E8 v38;       // 0x38
    sLmVec4_15E8 v40;       // 0x40
    sLmVec4_15E8 v50;       // 0x50
    char pad_0x60[0x4];
    unsigned char b64;      // 0x64
};

extern "C" void func_00391708(void* self, const char* name, int flags);

extern "C" sLmLight_15E8* func_003915E8(sLmLight_15E8* self, const char* name, int flags)
{
    self->field_0x8 = 0;
    self->v28 = sLmVec2_15E8(0.0f, 0.0f);
    self->v30 = sLmVec2_15E8(1.0f, 1.0f);
    self->v38 = self->v30;
    {
        sLmVec4_15E8 t;
        t.x = 1.0f;
        t.y = 1.0f;
        t.z = 1.0f;
        t.w = 1.0f;
        self->v40 = t;
    }
    self->v50 = sLmVec4_15E8(1.0f, 0.0f, 0.0f, 0.0f);
    self->b64 = 0;
    func_00391708(self, name, flags);
    return self;
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_003916C0);
#ifdef SKIP_ASM
extern "C" void func_003919E8(void* self);
void operator_delete(int* ptr);

extern "C" void func_003916C0(int* self, int flags)
{
    func_003919E8(self);
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("render/lightman", func_00391708);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* FILE_load(const char* name, int flags);
extern "C" void cFont_linkFont(void* self, void* data, int flags);
void cMemMan_free(void*);
extern const char D_00492F30[];

extern "C" void func_00391708(void* self, const char* name, int flags)
{
    void* data;

    sprintf((char*)self + 0x64, D_00492F30, name);
    data = FILE_load(name, flags ^ 0x100);
    cFont_linkFont(self, data, flags);
    if (data != 0) {
        cMemMan_free(data);
    }
}
#endif

