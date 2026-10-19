#include "common.h"

//100%
INCLUDE_ASM("intersect/worldsphtree", cWorldSphTree_cWorldSphTree);
#ifdef SKIP_ASM
extern void* D_0048E5F0[];
extern char D_0048E550[];
extern "C" void* func_0032C508(void* p);
extern "C" float func_0032C590(void* self);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sSphV4 { float x, y, z, w; } __attribute__((aligned(16)));

extern "C" void* cWorldSphTree_cWorldSphTree(void* self, void* a1, int a2)
{
    *(void***)((char*)self + 0x50) = D_0048E5F0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x4) = 0;
    if (a2 != 0) {
        *(int*)self = 0;
    } else {
        *(int*)self = 1;
    }
    *(void**)((char*)self + 0x64) = a1;
    *(void**)((char*)self + 0x60) = a1;
    sSphV4 c = *(sSphV4*)((char*)a1 + 0x80);
    float r = func_0032C590(a1);
    sSphV4 t;
    *(sSphV4*)((char*)self + 0x40) = c;
    t.x = c.x + r;
    t.y = c.y + r;
    t.z = c.z + r;
    t.w = 1.0f;
    *(sSphV4*)((char*)self + 0x20) = t;
    t.x = c.x - r;
    t.y = c.y - r;
    t.z = c.z - r;
    t.w = 1.0f;
    *(sSphV4*)((char*)self + 0x30) = t;
    void* p = cMemMan_alloc(0x140, D_0048E550, 0, 0);
    func_0032C508(p);
    *(void**)((char*)self + 0x68) = p;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003304E8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0048E5F0[];

extern "C" void func_003304E8(void* self, int flags)
{
    *(void***)((char*)self + 0x50) = D_0048E5F0;
    operator_delete(*(int**)((char*)self + 0x68));
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330540);
#ifdef SKIP_ASM
struct sV4_330540 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_330540 add_330540(const sV4_330540& a, const sV4_330540& b)
{
    sV4_330540 r;
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_330540 sub_330540(const sV4_330540& a, const sV4_330540& b)
{
    sV4_330540 r;
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

extern "C" float func_0032C590(void* self);

extern "C" int func_00330540(void* self, float* lo, float* hi)
{
    sV4_330540 ext;
    float rx = func_0032C590(*(void**)((char*)self + 0x60));
    float ry = func_0032C590(*(void**)((char*)self + 0x60));
    float rz = func_0032C590(*(void**)((char*)self + 0x60));
    ext.x = rx;
    ext.y = ry;
    ext.z = rz;
    ext.w = 0.0f;
    sV4_330540 mx = add_330540(*(sV4_330540*)(*(char**)((char*)self + 0x60) + 0x80), ext);
    sV4_330540 mn = sub_330540(*(sV4_330540*)(*(char**)((char*)self + 0x60) + 0x80), ext);
    float lx = lo[0];
    float tx = mx.x;
    if (tx < lx && mn.x < lx) return 0;
    if (hi[0] < tx && hi[0] < mn.x) return 0;
    float ly = lo[1];
    float ty = mx.y;
    if (ty < ly && mn.y < ly) return 0;
    if (hi[1] < ty && hi[1] < mn.y) return 0;
    float lz = lo[2];
    float tz = mx.z;
    if (tz < lz && mn.z < lz) return 0;
    if (!(hi[2] < tz) || !(hi[2] < mn.z)) return 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003306D8);
#ifdef SKIP_ASM
extern "C" float func_0032C590(void* self);

extern "C" float func_003306D8(void* self)
{
    float r;
    if (*(int*)self != 0) {
        r = func_0032C590(*(void**)((char*)self + 0x60)) * 2.0f;
    } else {
        r = -1.0f;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330710);
#ifdef SKIP_ASM
extern "C" void* func_00327CC8(void* self, void* src);
extern "C" void func_0032C770(void* p, void* a, float f);

extern "C" void func_00330710(void* self, void* a1, float f)
{
    func_00327CC8(*(void**)((char*)self + 0x68), *(void**)((char*)self + 0x60));
    *(void**)((char*)self + 0x60) = *(void**)((char*)self + 0x68);
    func_0032C770(*(void**)((char*)self + 0x60), a1, f);
    *(int*)((char*)self + 0x4) = 1;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330778__FPv);
#ifdef SKIP_ASM
int func_00330778(void* self)
{
    int t0 = *(int*)((char*)self + 0x64);
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x60) = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330788);
#ifdef SKIP_ASM
struct sWsVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float wsLength_330788(const sWsVec4& v)
{
    float r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %0, $vi22\n"
        : "=r"(r)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (v / s).
static inline sWsVec4 wsDiv_330788(const sWsVec4& v, float s)
{
    sWsVec4 r;
    int t;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        ".set pop\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

extern "C" int func_0032CA78(void* tree, int a1, int a2, int a3, int a4, sWsVec4* out, int a6);

extern "C" int func_00330788(void* self, int a1, int a2, int a3, int a4, int a5, sWsVec4* outDir, float* outLen)
{
    sWsVec4 v;
    int r = func_0032CA78(*(void**)((char*)self + 0x60), a1, a2, a3, a4, &v, a5);
    if (r != 0) {
        float len = wsLength_330788(v);
        *outLen = len;
        *outDir = wsDiv_330788(v, len);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330828);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float wsLength_330828(const sWsVec4& v)
{
    float r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %0, $vi22\n"
        : "=r"(r)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (v / s).
static inline sWsVec4 wsDiv_330828(const sWsVec4& v, float s)
{
    sWsVec4 r;
    int t;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        ".set pop\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

extern "C" int func_00328030(void* tree, int a1, int a2, int a3, int a4, sWsVec4* out, int a6);

extern "C" int func_00330828(void* self, int a1, int a2, int a3, int a4, int a5, sWsVec4* outDir, float* outLen)
{
    sWsVec4 v;
    int r = func_00328030(*(void**)((char*)self + 0x60), a1, a2, a3, a4, &v, a5);
    if (r != 0) {
        float len = wsLength_330828(v);
        *outLen = len;
        *outDir = wsDiv_330828(v, len);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003308C8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float wsLength_3308C8(const sWsVec4& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void wsDivEq_3308C8(sWsVec4& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

struct sWsHit_3308C8 {
    char pad_0x00[0x10];
    sWsVec4 dir;      // 0x10
    char pad_0x20[0x20];
    float len;            // 0x40
};

extern "C" int func_0032CB58(void* self, void* other, void* a2, void* a3);

extern "C" int func_003308C8(void* self, void* a1, sWsHit_3308C8* hit)
{
    if (func_0032CB58(*(void**)((char*)self + 0x60), a1, &hit->dir, hit) != 0) {
        float len = wsLength_3308C8(hit->dir);
        hit->len = len;
        wsDivEq_3308C8(hit->dir, len);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330950);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float wsLength_330950(const sWsVec4& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void wsDivEq_330950(sWsVec4& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

struct sWsHit_330950 {
    char pad_0x00[0x10];
    sWsVec4 dir;      // 0x10
    char pad_0x20[0x20];
    float len;            // 0x40
};

extern "C" int func_0032C928(void* self, void* a1, void* a2, void* a3, void* a4);

extern "C" int func_00330950(void* self, void* a1, void* a2, sWsHit_330950* hit)
{
    if (func_0032C928(*(void**)((char*)self + 0x60), a1, a2, &hit->dir, hit) != 0) {
        float len = wsLength_330950(hit->dir);
        hit->len = len;
        wsDivEq_330950(hit->dir, len);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003309D8);
#ifdef SKIP_ASM
struct sVEnt_3309D8 { short delta; short index; void* fn; };
typedef int (*Test_3309D8)(void*);

struct sBox_3309D8 {
    float min[4];
    float max[4];
};

struct sBox_3309D8;
typedef sBox_3309D8* (*GetBox_3309D8)(void*);
struct sObj_3309D8 {
    int pad00[3];
    sVEnt_3309D8* vt;
};

struct sNode_3309D8 {
    sNode_3309D8* next;
    int pad04;
    int flags;
    sObj_3309D8* obj;
    int pad10[20];
    float bmin[3];
    float bmax[3];
};

struct sCtx_3309D8 {
    sNode_3309D8** list;
    int* count;
    int pad08;
    sBox_3309D8* box;
};

static inline int overlapNode_3309D8(const sBox_3309D8* b, const sNode_3309D8* n)
{
    int r = 0;
    if (b->min[0] <= n->bmax[0] && b->max[0] >= n->bmin[0] &&
        b->min[1] <= n->bmax[1] && b->max[1] >= n->bmin[1] &&
        b->min[2] <= n->bmax[2] && b->max[2] >= n->bmin[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapBox_3309D8(const sBox_3309D8* b, const sBox_3309D8* o)
{
    int r = 0;
    if (b->min[0] <= o->max[0] && b->max[0] >= o->min[0] &&
        b->min[1] <= o->max[1] && b->max[1] >= o->min[1] &&
        b->min[2] <= o->max[2] && b->max[2] >= o->min[2]) {
        r = 1;
    }
    return r;
}

extern "C" void func_003309D8(sCtx_3309D8* ctx, void* tree)
{
    for (sNode_3309D8* p = *(sNode_3309D8**)((char*)tree + 0x20); p != 0; p = p->next) {
        int flags = p->flags;
        if (flags & 0x20) {
            if (overlapNode_3309D8(ctx->box, p)) {
                int* cnt = ctx->count;
                int n = *cnt;
                ctx->list[n] = p;
                *cnt = n + 1;
            }
        } else if (flags & 0x40) {
            sVEnt_3309D8* vt = p->obj->vt;
            if (((Test_3309D8)vt[44].fn)((char*)p->obj + vt[44].delta)) {
                sVEnt_3309D8* vt2 = p->obj->vt;
                sBox_3309D8* b = ((GetBox_3309D8)vt2[45].fn)((char*)p->obj + vt2[45].delta);
                if (overlapBox_3309D8(ctx->box, b)) {
                    int* cnt = ctx->count;
                    int n = *cnt;
                    ctx->list[n] = p;
                    *cnt = n + 1;
                }
            }
        }
    }
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00330BA8);

INCLUDE_ASM("intersect/worldsphtree", func_00331450);

INCLUDE_ASM("intersect/worldsphtree", func_00331E90);

INCLUDE_ASM("intersect/worldsphtree", func_00332DB8);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00333EF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sVec4_333EF8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sVec4_333EF8 D_004FF120_333EF8[] __asm__("D_004FF120");

struct sQuery_333EF8 {
    char pad00[0x20];
    float max[4];
    float min[4];
};

struct sTriObj_333EF8 {
    char pad00[8];
    short id;
    unsigned short flags;
    char pad0C[0x14C];
    float bmin[3];
    float bmax[3];
};

struct sHit_333EF8 {
    sVec4_333EF8 pos;   // 0x00
    sVec4_333EF8 nrm;   // 0x10
    sVec4_333EF8 v20;   // 0x20
    sVec4_333EF8 v30;   // 0x30
    float dist;         // 0x40
    int type;           // 0x44
    int pad48;
    int id;             // 0x4C
    int f50;            // 0x50
    void* obj;          // 0x54
    int f58;            // 0x58
    int f5C;            // 0x5C
    int f60;            // 0x60
    int f64;            // 0x64
    int f68;            // 0x68
    float u;            // 0x6C
    float v;            // 0x70
    int pad74[3];
};

struct sVEnt_333EF8 { short delta; short index; void* fn; };
struct sBox_333EF8;
typedef int (*Test_333EF8)(void*);
typedef sBox_333EF8* (*GetBox_333EF8)(void*);

struct sBox_333EF8 {
    float min[4];
    float max[4];
};

struct sObj_333EF8 {
    int pad00[3];
    sVEnt_333EF8* vt;
};

struct sNode_333EF8 {
    void* next;
    int pad04;
    int flags;
    sObj_333EF8* obj;
    int pad10[20];
    float bmin[3];
    float bmax[3];
    int pad78[4];
    int active;
};

struct sOwner_333EF8 {
    char pad00[0xA4];
    void* cache;
};

struct sTree_333EF8 {
    sOwner_333EF8* owner;           // 0x0
    int pad04;
    unsigned int count;             // 0x8
    sNode_333EF8* items[0x40];      // 0xC
    unsigned int ntris;             // 0x10C
    sTriObj_333EF8* tris[1];        // 0x110
};

extern "C" void func_003279D0(void* cache, void* src, void** out);
struct sVec4_335960;
struct sHit_003342D0;
extern "C" int func_0032B6E0(void* q, void* obj, void* node, sVec4_335960* pos, sVec4_335960* nrm, float* dist, sVec4_335960* uv, int arg);
extern "C" int func_00334888(void* q, void* node, void* buf, int cap, int mode);

static inline int overlapTri_333EF8(const sQuery_333EF8* q, const sTriObj_333EF8* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapNode_333EF8(const sQuery_333EF8* q, const sNode_333EF8* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapBox_333EF8(const sQuery_333EF8* q, const sBox_333EF8* o)
{
    int r = 0;
    if (q->max[0] > o->min[0] && q->min[0] < o->max[0] &&
        q->max[1] > o->min[1] && q->min[1] < o->max[1] &&
        q->max[2] > o->min[2] && o->max[2] > q->min[2]) {
        r = 1;
    }
    return r;
}

static inline void reset_333EF8(sHit_333EF8* h)
{
    h->type = 2;
    h->obj = 0;
    h->f50 = 0;
    h->f58 = 0;
    h->f5C = -1;
    h->f60 = -1;
    h->f64 = -1;
    h->id = -1;
    h->v20 = *D_004FF120_333EF8;
    h->v30 = *D_004FF120_333EF8;
    h->f68 = 0;
    h->u = 0;
    h->v = 0;
}

extern "C" int func_00333EF8(void* vself, void* vq, sHit_003342D0* vhits, int cap, int arg)
{
    sTree_333EF8* self = (sTree_333EF8*)vself;
    sQuery_333EF8* q = (sQuery_333EF8*)vq;
    sHit_333EF8* hits = (sHit_333EF8*)vhits;
    int n = 0;
    for (unsigned int i = 0; i < self->ntris; i++) {
        sTriObj_333EF8* obj = self->tris[i];
        if ((obj->flags & 0x41) != 0x41) {
            continue;
        }
        if (!overlapTri_333EF8(q, obj)) {
            continue;
        }
        sVec4_333EF8 uv;
        sVec4_333EF8 pos;
        sVec4_333EF8 nrm;
        void* node;
        float dist;
        func_003279D0(self->owner->cache, obj, &node);
        if (!func_0032B6E0(q, obj, node, (sVec4_335960*)&pos, (sVec4_335960*)&nrm, &dist, (sVec4_335960*)&uv, arg)) {
            continue;
        }
        reset_333EF8(&hits[n]);
        hits[n].pos = pos;
        hits[n].nrm = nrm;
        hits[n].id = obj->id;
        hits[n].obj = obj;
        hits[n].dist = dist;
        hits[n].u = uv.x;
        hits[n].v = uv.y;
        n++;
    }
    for (unsigned int j = 0; j < self->count; j++) {
        sNode_333EF8* node = self->items[j];
        if (node->active == 0) {
            continue;
        }
        int flags = node->flags;
        if (flags & 0x20) {
            if (overlapNode_333EF8(q, node)) {
                n += func_00334888(q, node, (char*)hits + n * 0x80, cap - n, 2);
            }
        } else if (flags & 0x40) {
            if (node->obj == 0) {
                continue;
            }
            sVEnt_333EF8* vt = node->obj->vt;
            if (((Test_333EF8)vt[44].fn)((char*)node->obj + vt[44].delta)) {
                sVEnt_333EF8* vt2 = node->obj->vt;
                sBox_333EF8* b = ((GetBox_333EF8)vt2[45].fn)((char*)node->obj + vt2[45].delta);
                if (overlapBox_333EF8(q, b)) {
                    n += func_00334888(q, node, (char*)hits + n * 0x80, cap - n, 2);
                }
            }
        }
    }
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/worldsphtree", func_003342D0);
#ifdef SKIP_ASM
struct sHit_003342D0 {
    float pad0[16];
    float dist;             // 0x40
    int pad44[3];
    char* obj;              // 0x50
    char* tri;              // 0x54
    int pad58[10];
    sHit_003342D0() {}
} __attribute__((aligned(16)));

struct sVEnt_003342D0 { short delta; short index; float (*fn)(void*); };
extern "C" int func_00333EF8(void* self, void* q, sHit_003342D0* hits, int max, int a4);

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_003342D0(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline int isBetter_003342D0(sHit_003342D0* a, sHit_003342D0* b)
{
    if (a->obj != 0) {
        if (b->obj == 0) {
            return 1;
        }
        return *(unsigned int*)(a->obj + 0x78) < *(unsigned int*)(b->obj + 0x78);
    }
    if (b->obj != 0) {
        return 0;
    }
    return *(unsigned int*)(a->tri + 0x150) < *(unsigned int*)(b->tri + 0x150);
}

extern "C" float func_003342D0(void* self, char* q, sHit_003342D0* out, int a3)
{
    sHit_003342D0 hits[64];
    int n = func_00333EF8(self, q, hits, 0x40, a3);
    if (n == 0) {
        return -1.0f;
    }
    int best = 0;
    sVEnt_003342D0* vt = *(sVEnt_003342D0**)(q + 0x50);
    float ref = vt[3].fn(q + vt[3].delta);
    float bestDiff = absf_003342D0(hits[0].dist - ref);
    for (int i = 1; i < n; i++) {
        float d = absf_003342D0(hits[i].dist - ref);
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetter_003342D0(&hits[i], &hits[best])) {
                best = i;
            }
        }
    }
    *out = hits[best];
    return out->dist;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00334458);
#ifdef SKIP_ASM
struct sVEnt_334458 { short delta; short index; void* fn; };
struct sBox_334458;
typedef int (*Test_334458)(void*);
typedef sBox_334458* (*GetBox_334458)(void*);

struct sBox_334458 {
    float min[4];
    float max[4];
};

struct sQuery_334458 {
    char pad00[0x20];
    float max[4];
    float min[4];
};

struct sObj_334458 {
    int pad00[3];
    sVEnt_334458* vt;
};

struct sNode_334458 {
    void* next;
    int pad04;
    int flags;
    sObj_334458* obj;
    int pad10[20];
    float bmin[3];
    float bmax[3];
};

struct sList_334458 {
    int pad00[2];
    unsigned int count;
    sNode_334458* items[1];
};

extern "C" int func_00334888(void* q, void* node, void* buf, int cap, int mode);

static inline int overlapNode_334458(const sQuery_334458* q, const sNode_334458* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapBox_334458(const sQuery_334458* q, const sBox_334458* o)
{
    int r = 0;
    if (q->max[0] > o->min[0] && q->min[0] < o->max[0] &&
        q->max[1] > o->min[1] && q->min[1] < o->max[1] &&
        q->max[2] > o->min[2] && o->max[2] > q->min[2]) {
        r = 1;
    }
    return r;
}

extern "C" int func_00334458(sList_334458* self, sQuery_334458* q, char* buf, int cap, int full)
{
    int mode = 1;
    if (full) mode = 2;
    int n = 0;
    for (unsigned int i = 0; i < self->count; i++) {
        sNode_334458* node = self->items[i];
        int flags = node->flags;
        if (flags & 0x20) {
            if (overlapNode_334458(q, node)) {
                n += func_00334888(q, node, buf + n * 0x80, cap - n, mode);
            }
        } else if (flags & 0x40) {
            sVEnt_334458* vt = node->obj->vt;
            if (((Test_334458)vt[44].fn)((char*)node->obj + vt[44].delta)) {
                sVEnt_334458* vt2 = node->obj->vt;
                sBox_334458* b = ((GetBox_334458)vt2[45].fn)((char*)node->obj + vt2[45].delta);
                if (overlapBox_334458(q, b)) {
                    n += func_00334888(q, node, buf + n * 0x80, cap - n, mode);
                }
            }
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00334680);
#ifdef SKIP_ASM
struct sBox_00334680 {
    sWsVec4 min;
    sWsVec4 max;
};
extern "C" void func_0035C698(void* a0, sBox_00334680* box, sBox_00334680* box2, sWsVec4* pos, int mask, int* cnt, float* dist, int a7);
extern "C" void func_00348290(void* a0, sBox_00334680* box, sBox_00334680* box2, sWsVec4* pos, int mask, int* cnt, float* dist, int a7);
extern "C" void func_00335128(void* obj, sBox_00334680* box, sWsVec4* pos, int* cnt, float* dist, int a5);

// PORT: PS2-only VU0 inline asm (in-place vector subtract).
static inline void wsSubEq_334680(sWsVec4& a, const sWsVec4& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (in-place vector add).
static inline void wsAddEq_334680(sWsVec4& a, const sWsVec4& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

extern "C" int func_00334680(char* self, sWsVec4* pos, int a2, int mask, float r)
{
    sBox_00334680 box;
    sWsVec4 ext;
    int cnt;
    float dist;
    float zero = 0.0f;
    cnt = 0;
    dist = zero;
    box.min = *pos;
    box.max = *pos;
    ext.x = r;
    ext.y = r;
    ext.z = r;
    ext.w = zero;
    wsSubEq_334680(box.min, ext);
    wsAddEq_334680(box.max, ext);
    for (unsigned int i = 0; i < *(unsigned int*)(self + 0x210); i++) {
        char* o = ((char**)(self + 0x214))[i];
        int type = *(int*)(o + 8);
        if (type == 2) {
            func_0035C698(*(void**)(o + 0xC), &box, &box, pos, mask, &cnt, &dist, a2);
        } else if (type == 3) {
            func_00348290(*(void**)(o + 0xC), &box, &box, pos, mask, &cnt, &dist, a2);
        } else if (type == 1) {
            if (*(int*)(*(char**)(o + 0x68) + 0x1C) & mask) {
                func_00335128(o, &box, pos, &cnt, &dist, a2);
            }
        }
    }
    return cnt;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00334800);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* func_00327810(void* self);
extern "C" void cAIFwdDiffCache_Init(void* cache, int n);
extern char D_0048E4F8[];

extern "C" void func_00334800(void* self)
{
    void* c = func_00327810(cMemMan_alloc(0x10, D_0048E4F8, 0, 0));
    *(void**)((char*)self + 0xA4) = c;
    cAIFwdDiffCache_Init(c, 0x28);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00334850);
#ifdef SKIP_ASM
extern "C" void func_00327828(void* p, int flags);

extern "C" void func_00334850(void* self)
{
    void* p = *(void**)((char*)self + 0xA4);
    if (p != 0) {
        func_00327828(p, 3);
    }
    *(void**)((char*)self + 0xA4) = 0;
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00334888);

INCLUDE_ASM("intersect/worldsphtree", func_00335128);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00335960);
#ifdef SKIP_ASM
struct sVec4_335960 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sVec4_335960 D_004FF120[];

struct sQuery_335960 {
    char pad00[0x20];
    float max[4];
    float min[4];
};

struct sTriObj_335960 {
    char pad00[8];
    short id;
    unsigned short flags;
    char pad0C[0x14C];
    float bmin[3];
    float bmax[3];
};

struct sHit_335960 {
    sVec4_335960 pos;   // 0x00
    sVec4_335960 nrm;   // 0x10
    sVec4_335960 v20;   // 0x20
    sVec4_335960 v30;   // 0x30
    float dist;         // 0x40
    int type;           // 0x44
    int pad48;
    int id;             // 0x4C
    int f50;            // 0x50
    void* obj;          // 0x54
    int f58;            // 0x58
    int f5C;            // 0x5C
    int f60;            // 0x60
    int f64;            // 0x64
    int f68;            // 0x68
    float u;            // 0x6C
    float v;            // 0x70
    int pad74[3];
};

struct sCtx_335960 {
    sQuery_335960* q;
    sHit_335960* hits;
    int cap;
    int* count;
    int arg;
    void* cache;
};

extern "C" void func_003279D0(void* cache, void* src, void** out);
extern "C" int func_0032B6E0(void* q, void* obj, void* node, sVec4_335960* pos, sVec4_335960* nrm, float* dist, sVec4_335960* uv, int arg);

static inline int overlap_335960(const sQuery_335960* q, const sTriObj_335960* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

static inline void reset_335960(sHit_335960* h)
{
    h->type = 2;
    h->obj = 0;
    h->f50 = 0;
    h->f58 = 0;
    h->f5C = -1;
    h->f60 = -1;
    h->f64 = -1;
    h->id = -1;
    h->v20 = *D_004FF120;
    h->v30 = *D_004FF120;
    h->f68 = 0;
    h->u = 0;
    h->v = 0;
}

extern "C" void func_00335960(void* vctx, void* vobj)
{
    sCtx_335960* ctx = (sCtx_335960*)vctx;
    sTriObj_335960* obj = (sTriObj_335960*)vobj;
    sVec4_335960 pos;
    sVec4_335960 nrm;
    sVec4_335960 uv;
    void* node;
    float dist;
    if ((obj->flags & 0x41) != 0x41) return;
    if (!overlap_335960(ctx->q, obj)) return;
    func_003279D0(ctx->cache, obj, &node);
    if (!func_0032B6E0(ctx->q, obj, node, &pos, &nrm, &dist, &uv, ctx->arg)) return;
    reset_335960(&ctx->hits[*ctx->count]);
    ctx->hits[*ctx->count].pos = pos;
    ctx->hits[*ctx->count].nrm = nrm;
    ctx->hits[*ctx->count].id = obj->id;
    ctx->hits[*ctx->count].obj = obj;
    ctx->hits[*ctx->count].dist = dist;
    ctx->hits[*ctx->count].u = uv.x;
    ctx->hits[*ctx->count].v = uv.y;
    (*ctx->count)++;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00335B90);
#ifdef SKIP_ASM
struct sVEnt_335B90 { short delta; short index; void* fn; };
struct sBox_335B90;
typedef int (*Test_335B90)(void*);
typedef sBox_335B90* (*GetBox_335B90)(void*);

struct sBox_335B90 {
    float min[4];
    float max[4];
};

struct sQuery_335B90 {
    char pad00[0x20];
    float max[4];
    float min[4];
};

struct sObj_335B90 {
    int pad00[3];
    sVEnt_335B90* vt;
};

struct sNode_335B90 {
    void* next;
    int pad04;
    int flags;
    sObj_335B90* obj;
    int pad10[20];
    float bmin[3];
    float bmax[3];
    int pad78[4];
    int active;
};

struct sCtx_335B90 {
    sQuery_335B90* q;
    char* buf;
    int cap;
    int* count;
};

extern "C" int func_00334888(void* q, void* node, void* buf, int cap, int mode);

static inline int overlapNode_335B90(const sQuery_335B90* q, const sNode_335B90* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapBox_335B90(const sQuery_335B90* q, const sBox_335B90* o)
{
    int r = 0;
    if (q->max[0] > o->min[0] && q->min[0] < o->max[0] &&
        q->max[1] > o->min[1] && q->min[1] < o->max[1] &&
        q->max[2] > o->min[2] && q->min[2] < o->max[2]) {
        r = 1;
    }
    return r;
}

static inline void collect_335B90(sCtx_335B90* ctx, sNode_335B90* node)
{
    int n = *ctx->count;
    *ctx->count += func_00334888(ctx->q, node, ctx->buf + n * 0x80, ctx->cap - n, 2);
}

extern "C" void func_00335B90(void* vctx, void* vnode)
{
    sCtx_335B90* ctx = (sCtx_335B90*)vctx;
    sNode_335B90* node = (sNode_335B90*)vnode;
    if (node->active == 0) return;
    int flags = node->flags;
    if (flags & 0x20) {
        if (overlapNode_335B90(ctx->q, node)) {
            collect_335B90(ctx, node);
        }
    } else if (flags & 0x40) {
        if (node->obj == 0) return;
        sVEnt_335B90* vt = node->obj->vt;
        if (((Test_335B90)vt[44].fn)((char*)node->obj + vt[44].delta)) {
            sVEnt_335B90* vt2 = node->obj->vt;
            sBox_335B90* b = ((GetBox_335B90)vt2[45].fn)((char*)node->obj + vt2[45].delta);
            if (overlapBox_335B90(ctx->q, b)) {
                collect_335B90(ctx, node);
            }
        }
    }
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00335D78);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/worldsphtree", func_00336850);
#ifdef SKIP_ASM
struct sHit_00336850 {
    float pad0[16];
    float dist;             // 0x40
    int pad44[3];
    char* obj;              // 0x50
    char* tri;              // 0x54
    int pad58[10];
    sHit_00336850() {}
} __attribute__((aligned(16)));

struct sVEnt_00336850 { short delta; short index; float (*fn)(void*); };
extern "C" int func_00335D78(void* self, void* q, sHit_00336850* hits, int max, int a4);

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_00336850(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline int isBetter_00336850(sHit_00336850* a, sHit_00336850* b)
{
    if (a->obj != 0) {
        if (b->obj == 0) {
            return 1;
        }
        return *(unsigned int*)(a->obj + 0x78) < *(unsigned int*)(b->obj + 0x78);
    }
    if (b->obj != 0) {
        return 0;
    }
    return *(unsigned int*)(a->tri + 0x150) < *(unsigned int*)(b->tri + 0x150);
}

extern "C" float func_00336850(void* self, char* q, sHit_00336850* out, int a3)
{
    sHit_00336850 hits[64];
    int n = func_00335D78(self, q, hits, 0x40, a3);
    if (n == 0) {
        return -1.0f;
    }
    int best = 0;
    sVEnt_00336850* vt = *(sVEnt_00336850**)(q + 0x50);
    float ref = vt[3].fn(q + vt[3].delta);
    float bestDiff = absf_00336850(hits[0].dist - ref);
    for (int i = 1; i < n; i++) {
        float d = absf_00336850(hits[i].dist - ref);
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetter_00336850(&hits[i], &hits[best])) {
                best = i;
            }
        }
    }
    *out = hits[best];
    return out->dist;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003369D8);
#ifdef SKIP_ASM
struct sQuad_369D8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sHit_003369D8 {
    sQuad_369D8 p;          // 0x00
    sQuad_369D8 n;          // 0x10
    float pad20[8];         // 0x20
    float dist;             // 0x40
    int pad44[3];
    char* obj;              // 0x50
    char* tri;              // 0x54
    int pad58[10];
    sHit_003369D8() {}
} __attribute__((aligned(16)));

struct sQuery_369D8 {
    void* seg;              // 0x00
    sHit_003369D8* hits;    // 0x04
    int max;                // 0x08
    int* count;             // 0x0C
    int f10;                // 0x10
    void* f14;              // 0x14
};

struct sCell_369D8 {
    int f0, f4, f8, fC;
    void* node;             // 0x10
};

extern "C" void* func_0032E100(void* seg, const sQuad_369D8& a, const sQuad_369D8& b, int n, float r);
struct sCtx_369D8 {
    float* pos;             // 0x0
    char flags[8];          // 0x4
};

struct sTrav_369D8 {
    int count;              // 0x0
    sCtx_369D8 ctx;         // 0x4
};

extern "C" void func_0033DBE8(char* flag, sQuery_369D8* q, sQuery_369D8* q2, sCtx_369D8* ctx, void* node, sCell_369D8* cell);

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_003369D8(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ `<?` (min) operator.
static inline float clamp_003369D8(float v, float lo, float hi)
{
    if (v >= lo) return v <? hi;
    return lo;
}

static inline int isBetter_003369D8(sHit_003369D8* a, sHit_003369D8* b)
{
    if (a->obj != 0) {
        if (b->obj == 0) {
            return 1;
        }
        return *(unsigned int*)(a->obj + 0x78) < *(unsigned int*)(b->obj + 0x78);
    }
    if (b->obj != 0) {
        return 0;
    }
    return *(unsigned int*)(a->tri + 0x150) < *(unsigned int*)(b->tri + 0x150);
}

static inline void visit_003369D8(sCell_369D8* c, char* flag, sQuery_369D8* q, sCtx_369D8* p)
{
    func_0033DBE8(flag, q, q, p, c->node, c);
}

extern "C" int func_003369D8(sCell_369D8* self, float* pos, sQuad_369D8* outP, sQuad_369D8* outN)
{
    char seg[0xB0];
    float lo = pos[2] - 100000.0f;
    float hi = pos[2] + 100000.0f;
    float t = clamp_003369D8((pos[2] + 20.0f - lo) / (hi - lo), 0.0f, 1.0f);
    {
        sQuad_369D8 a;
        a.x = pos[0];
        a.y = pos[1];
        a.z = lo;
        a.w = 1.0f;
        sQuad_369D8 b;
        b.x = pos[0];
        b.y = pos[1];
        b.z = hi;
        b.w = 1.0f;
        func_0032E100(seg, a, b, 2, t);
    }
    sHit_003369D8 hits[64];
    sQuery_369D8 q;
    q.seg = seg;
    q.hits = hits;
    q.max = 0x40;
    sTrav_369D8 tr;
    q.count = &tr.count;
    q.f10 = 0;
    q.f14 = *(void**)((char*)self + 0xA4);
    tr.count = 0;
    tr.ctx.pos = pos;
    sCtx_369D8* ctx = &tr.ctx;
    sCell_369D8* c0 = &self[0];
    sCell_369D8* c1 = &self[1];
    sCell_369D8* c2 = &self[2];
    sCell_369D8* c3 = &self[3];
    sCell_369D8* c4 = &self[4];
    sCell_369D8* c5 = &self[5];
    sCell_369D8* c6 = &self[6];
    sCell_369D8* c7 = &self[7];
    if (self[0].node) visit_003369D8(c0, &tr.ctx.flags[0], &q, ctx);
    if (self[1].node) visit_003369D8(c1, &tr.ctx.flags[1], &q, ctx);
    if (self[2].node) visit_003369D8(c2, &tr.ctx.flags[2], &q, ctx);
    if (self[3].node) visit_003369D8(c3, &tr.ctx.flags[3], &q, ctx);
    if (self[4].node) visit_003369D8(c4, &tr.ctx.flags[4], &q, ctx);
    if (self[5].node) visit_003369D8(c5, &tr.ctx.flags[5], &q, ctx);
    if (self[6].node) visit_003369D8(c6, &tr.ctx.flags[6], &q, ctx);
    if (self[7].node) visit_003369D8(c7, &tr.ctx.flags[7], &q, ctx);
    if (tr.count == 0) {
        return 0;
    }
    float ref = pos[2];
    int best = 0;
    float bestDiff = absf_003369D8(hits[0].p.z - ref);
    for (int i = 1; i < tr.count; i++) {
        float d = absf_003369D8((hits + i)->p.z - ref);
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetter_003369D8(hits + i, hits + best)) {
                best = i;
            }
        }
    }
    *outP = (hits + best)->p;
    *outN = (hits + best)->n;
    return 1;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00336D40);
#ifdef SKIP_ASM
struct sVEnt_336D40 { short delta; short index; void* fn; };
struct sBox_336D40;
typedef int (*Test_336D40)(void*);
typedef sBox_336D40* (*GetBox_336D40)(void*);

struct sBox_336D40 {
    float min[4];
    float max[4];
};

struct sQuery_336D40 {
    char pad00[0x20];
    float max[4];
    float min[4];
};

struct sObj_336D40 {
    int pad00[3];
    sVEnt_336D40* vt;
};

struct sNode_336D40 {
    void* next;
    int pad04;
    int flags;
    sObj_336D40* obj;
    int pad10[20];
    float bmin[3];
    float bmax[3];
    int pad78[4];
    int active;
};

struct sCtx_336D40 {
    sQuery_336D40* q;
    char* buf;
    int cap;
    int* count;
    int full;
};

extern "C" int func_00334888(void* q, void* node, void* buf, int cap, int mode);

static inline int overlapNode_336D40(const sQuery_336D40* q, const sNode_336D40* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapBox_336D40(const sQuery_336D40* q, const sBox_336D40* o)
{
    int r = 0;
    if (q->max[0] > o->min[0] && q->min[0] < o->max[0] &&
        q->max[1] > o->min[1] && q->min[1] < o->max[1] &&
        q->max[2] > o->min[2] && q->min[2] < o->max[2]) {
        r = 1;
    }
    return r;
}

static inline void collect_336D40(sCtx_336D40* ctx, sNode_336D40* node, int mode)
{
    int n = *ctx->count;
    *ctx->count += func_00334888(ctx->q, node, ctx->buf + n * 0x80, ctx->cap - n, mode);
}

extern "C" void func_00336D40(void* vctx, void* vnode)
{
    sCtx_336D40* ctx = (sCtx_336D40*)vctx;
    sNode_336D40* node = (sNode_336D40*)vnode;
    int mode = ctx->full ? 3 : 1;
    int flags = node->flags;
    if (flags & 0x20) {
        if (overlapNode_336D40(ctx->q, node)) {
            collect_336D40(ctx, node, mode);
        }
    } else if (flags & 0x40) {
        sVEnt_336D40* vt = node->obj->vt;
        if (((Test_336D40)vt[44].fn)((char*)node->obj + vt[44].delta)) {
            sVEnt_336D40* vt2 = node->obj->vt;
            sBox_336D40* b = ((GetBox_336D40)vt2[45].fn)((char*)node->obj + vt2[45].delta);
            if (overlapBox_336D40(ctx->q, b)) {
                collect_336D40(ctx, node, mode);
            }
        }
    }
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00336F30);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/worldsphtree", func_003378C0);
#ifdef SKIP_ASM
struct sHit_003378C0 {
    float pad0[16];
    float dist;             // 0x40
    int pad44[3];
    char* obj;              // 0x50
    char* tri;              // 0x54
    int pad58[10];
    sHit_003378C0() {}
} __attribute__((aligned(16)));

struct sVEnt_003378C0 { short delta; short index; float (*fn)(void*); };
extern "C" int func_00336F30(void* self, void* q, sHit_003378C0* hits, int max, int a4);

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_003378C0(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline int isBetter_003378C0(sHit_003378C0* a, sHit_003378C0* b)
{
    if (a->obj != 0) {
        if (b->obj == 0) {
            return 1;
        }
        return *(unsigned int*)(a->obj + 0x78) < *(unsigned int*)(b->obj + 0x78);
    }
    if (b->obj != 0) {
        return 0;
    }
    return *(unsigned int*)(a->tri + 0x150) < *(unsigned int*)(b->tri + 0x150);
}

extern "C" float func_003378C0(void* self, char* q, sHit_003378C0* out, int a3)
{
    sHit_003378C0 hits[128];
    int n = func_00336F30(self, q, hits, 0x80, a3);
    if (n == 0) {
        return -1.0f;
    }
    int best = 0;
    sVEnt_003378C0* vt = *(sVEnt_003378C0**)(q + 0x50);
    float ref = vt[3].fn(q + vt[3].delta);
    float bestDiff = absf_003378C0(hits[0].dist - ref);
    for (int i = 1; i < n; i++) {
        float d = absf_003378C0(hits[i].dist - ref);
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetter_003378C0(&hits[i], &hits[best])) {
                best = i;
            }
        }
    }
    *out = hits[best];
    return out->dist;
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00337A48);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003388E0);
#ifdef SKIP_ASM
extern "C" void* func_003388E0(void* self, ...)
{
    return self;
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00338920);
INCLUDE_ASM("intersect/worldsphtree", func_00339598);

INCLUDE_ASM("intersect/worldsphtree", func_0033A3D8);

INCLUDE_ASM("intersect/worldsphtree", func_0033B748);

INCLUDE_ASM("intersect/worldsphtree", func_0033CCF8);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_0033DBE8);
#ifdef SKIP_ASM
struct sQuery_369D8;
struct sCtx_369D8;
struct sCell_369D8;
extern "C" void func_00335960(void* ctx, void* obj);
extern "C" void func_00335B90(void* ctx, void* obj);
extern "C" void func_00340FA0(void* self, void* ctx);

struct sOct_DBE8 {
    sOct_DBE8* child[8];            // 0x00
    void** listB;                   // 0x20
    void** listA;                   // 0x24
};

struct sCell_DBE8 {
    int level;                      // 0x0
    int x;                          // 0x4
    int y;                          // 0x8
    int z;                          // 0xC
};

struct sCtx_DBE8 {
    float* pos;                     // 0x0
};

static inline int Classify_DBE8(sCtx_DBE8* ctx, sCell_DBE8* c)
{
    int bits = (c->level + 0x7F) << 23;
    float s = *(float*)&bits;
    float* p = ctx->pos;
    if (p[0] < ((float)c->x - 0.2f) * s) {
        return 1;
    }
    if (((float)(c->x + 1) + 0.2f) * s < p[0]) {
        return 1;
    }
    if (p[1] < ((float)c->y - 0.2f) * s) {
        return 1;
    }
    if (((float)(c->y + 1) + 0.2f) * s < p[1]) {
        return 1;
    }
    return 2;
}

extern "C" void func_0033DBE8(char* flag, sQuery_369D8* q, sQuery_369D8* q2, sCtx_369D8* vctx, void* vnode, sCell_369D8* vcell)
{
    sCtx_DBE8* ctx = (sCtx_DBE8*)vctx;
    sOct_DBE8* node = (sOct_DBE8*)vnode;
    sCell_DBE8* cell = (sCell_DBE8*)vcell;
    int r = Classify_DBE8(ctx, cell);
    if (r == 0) {
        void** o;
        for (o = node->listA; o != 0; o = (void**)*o) {
            func_00335960(q2, o);
        }
        for (o = node->listB; o != 0; o = (void**)*o) {
            func_00335B90(q2, o);
        }
        if (node->child[0]) {
            func_00340FA0(node->child[0], q2);
        }
        if (node->child[1]) {
            func_00340FA0(node->child[1], q2);
        }
        if (node->child[2]) {
            func_00340FA0(node->child[2], q2);
        }
        if (node->child[3]) {
            func_00340FA0(node->child[3], q2);
        }
        if (node->child[4]) {
            func_00340FA0(node->child[4], q2);
        }
        if (node->child[5]) {
            func_00340FA0(node->child[5], q2);
        }
        if (node->child[6]) {
            func_00340FA0(node->child[6], q2);
        }
        if (node->child[7]) {
            func_00340FA0(node->child[7], q2);
        }
    } else if (r == 2) {
        void** o;
        for (o = node->listA; o != 0; o = (void**)*o) {
            func_00335960(q, o);
        }
        for (o = node->listB; o != 0; o = (void**)*o) {
            func_00335B90(q, o);
        }
        if (cell->level == 11) {
            return;
        }
        sCell_DBE8 sub;
        sub.level = cell->level - 1;
        sub.x = cell->x * 2;
        sub.y = cell->y * 2;
        sub.z = cell->z * 2;
        if (node->child[0]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[0], (sCell_369D8*)&sub);
        }
        sub.x++;
        if (node->child[4]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[4], (sCell_369D8*)&sub);
        }
        sub.y++;
        if (node->child[6]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[6], (sCell_369D8*)&sub);
        }
        sub.x--;
        if (node->child[2]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[2], (sCell_369D8*)&sub);
        }
        sub.z++;
        if (node->child[3]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[3], (sCell_369D8*)&sub);
        }
        sub.x++;
        if (node->child[7]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[7], (sCell_369D8*)&sub);
        }
        sub.y--;
        if (node->child[5]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[5], (sCell_369D8*)&sub);
        }
        sub.x--;
        if (node->child[1]) {
            func_0033DBE8(flag, q, q2, vctx, node->child[1], (sCell_369D8*)&sub);
        }
    }
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_0033DFD8);

INCLUDE_ASM("intersect/worldsphtree", func_0033ED60);

INCLUDE_ASM("intersect/worldsphtree", func_003400D8);

INCLUDE_ASM("intersect/worldsphtree", func_00340970);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340A08__FPv);
#ifdef SKIP_ASM
void func_00340A08(void* self)
{
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340A10__FPv);
#ifdef SKIP_ASM
float func_00340A10(void* self)
{
    return *(float*)((char*)self + 0xA0);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340A18);
#ifdef SKIP_ASM
extern "C" float func_00340A18(void* self)
{
    if (*(int*)self == 0) {
        return -1.0f;
    }
    return *(float*)((char*)self + 0x70) * 2.0f;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340A40);
#ifdef SKIP_ASM
struct sSphNode_340A40 {
    sSphNode_340A40* child[8];
};

extern "C" void func_00340A40(sSphNode_340A40* node, sCtx_3309D8* ctx)
{
    func_003309D8(ctx, node);
    if (node->child[0] != 0) func_00340A40(node->child[0], ctx);
    if (node->child[1] != 0) func_00340A40(node->child[1], ctx);
    if (node->child[2] != 0) func_00340A40(node->child[2], ctx);
    if (node->child[3] != 0) func_00340A40(node->child[3], ctx);
    if (node->child[4] != 0) func_00340A40(node->child[4], ctx);
    if (node->child[5] != 0) func_00340A40(node->child[5], ctx);
    if (node->child[6] != 0) func_00340A40(node->child[6], ctx);
    if (node->child[7] != 0) func_00340A40(node->child[7], ctx);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340B18);
#ifdef SKIP_ASM
struct sOctCollect {
    void** arr;
    int* count;
};

extern "C" void func_00340B18(void* self, sOctCollect* out)
{
    void** p;
    for (p = *(void***)((char*)self + 0x28); p != 0; p = (void**)*p) {
        out->arr[(*out->count)++] = p;
    }
    if (*(void**)((char*)self + 0x0)) func_00340B18(*(void**)((char*)self + 0x0), out);
    if (*(void**)((char*)self + 0x4)) func_00340B18(*(void**)((char*)self + 0x4), out);
    if (*(void**)((char*)self + 0x8)) func_00340B18(*(void**)((char*)self + 0x8), out);
    if (*(void**)((char*)self + 0xC)) func_00340B18(*(void**)((char*)self + 0xC), out);
    if (*(void**)((char*)self + 0x10)) func_00340B18(*(void**)((char*)self + 0x10), out);
    if (*(void**)((char*)self + 0x14)) func_00340B18(*(void**)((char*)self + 0x14), out);
    if (*(void**)((char*)self + 0x18)) func_00340B18(*(void**)((char*)self + 0x18), out);
    if (*(void**)((char*)self + 0x1C)) func_00340B18(*(void**)((char*)self + 0x1C), out);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340C20);
#ifdef SKIP_ASM
struct sObj_340C20 {
    sObj_340C20* next;
    char pad04[0x154];
    float bmin[3];              // 0x158
    float bmax[3];              // 0x164
};

struct sTree_340C20 {
    sTree_340C20* child[8];
    int pad20;
    sObj_340C20* objs;          // 0x24
};

static inline int overlapObj_340C20(const sBox_3309D8* b, const sObj_340C20* n)
{
    int r = 0;
    if (b->min[0] <= n->bmax[0] && b->max[0] >= n->bmin[0] &&
        b->min[1] <= n->bmax[1] && b->max[1] >= n->bmin[1] &&
        b->min[2] <= n->bmax[2] && b->max[2] >= n->bmin[2]) {
        r = 1;
    }
    return r;
}

extern "C" void func_00340C20(sTree_340C20* tree, sCtx_3309D8* ctx)
{
    func_003309D8(ctx, tree);
    sCtx_3309D8* q = (sCtx_3309D8*)((char*)ctx + 0x10);
    for (sObj_340C20* p = tree->objs; p != 0; p = p->next) {
        if (overlapObj_340C20(q->box, p)) {
            int* cnt = q->count;
            int n = *cnt;
            q->list[n] = (sNode_3309D8*)p;
            *cnt = n + 1;
        }
    }
    if (tree->child[0] != 0) func_00340C20(tree->child[0], ctx);
    if (tree->child[1] != 0) func_00340C20(tree->child[1], ctx);
    if (tree->child[2] != 0) func_00340C20(tree->child[2], ctx);
    if (tree->child[3] != 0) func_00340C20(tree->child[3], ctx);
    if (tree->child[4] != 0) func_00340C20(tree->child[4], ctx);
    if (tree->child[5] != 0) func_00340C20(tree->child[5], ctx);
    if (tree->child[6] != 0) func_00340C20(tree->child[6], ctx);
    if (tree->child[7] != 0) func_00340C20(tree->child[7], ctx);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340DC0);
#ifdef SKIP_ASM
struct sCtx_3309D8;
extern "C" void func_003309D8(sCtx_3309D8* ctx, void* tree);

struct sBox_340DC0 {
    float min[4];
    float max[4];
};

struct sSub_340DC0 {
    void** list;
    int* count;
    int pad08;
    sBox_340DC0* box;
};

struct sCtx_340DC0 {
    sSub_340DC0 nodes;
    sSub_340DC0 objs;
    sSub_340DC0 all;
};

struct sObjNode_340DC0 {
    sObjNode_340DC0* next;
    int pad04[85];
    float bmin[3];
    float bmax[3];
};

struct sTree_340DC0 {
    sTree_340DC0* child[8];
    void* nodes;
    sObjNode_340DC0* objs;
    void** all;
};

static inline void add_340DC0(sSub_340DC0* s, void* p)
{
    int* cnt = s->count;
    int n = *cnt;
    s->list[n] = p;
    *cnt = n + 1;
}

static inline int overlap_340DC0(const sBox_340DC0* b, const sObjNode_340DC0* n)
{
    int r = 0;
    if (b->min[0] <= n->bmax[0] && b->max[0] >= n->bmin[0] &&
        b->min[1] <= n->bmax[1] && b->max[1] >= n->bmin[1] &&
        b->min[2] <= n->bmax[2] && b->max[2] >= n->bmin[2]) {
        r = 1;
    }
    return r;
}

extern "C" void func_00340DC0(sTree_340DC0* self, sCtx_340DC0* ctx)
{
    func_003309D8((sCtx_3309D8*)ctx, self);
    sSub_340DC0* s = &ctx->objs;
    for (sObjNode_340DC0* p = self->objs; p != 0; p = p->next) {
        if (overlap_340DC0(s->box, p)) {
            add_340DC0(s, p);
        }
    }
    s = &ctx->all;
    for (void** q = self->all; q != 0; q = (void**)*q) {
        add_340DC0(s, q);
    }
    if (self->child[0]) func_00340DC0(self->child[0], ctx);
    if (self->child[1]) func_00340DC0(self->child[1], ctx);
    if (self->child[2]) func_00340DC0(self->child[2], ctx);
    if (self->child[3]) func_00340DC0(self->child[3], ctx);
    if (self->child[4]) func_00340DC0(self->child[4], ctx);
    if (self->child[5]) func_00340DC0(self->child[5], ctx);
    if (self->child[6]) func_00340DC0(self->child[6], ctx);
    if (self->child[7]) func_00340DC0(self->child[7], ctx);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/worldsphtree", func_00340FA0);
#ifdef SKIP_ASM
extern "C" void func_00335960(void* ctx, void* obj);
extern "C" void func_00335B90(void* ctx, void* obj);

extern "C" void func_00340FA0(void* self, void* ctx)
{
    void** p;
    for (p = *(void***)((char*)self + 0x24); p != 0; p = (void**)*p) {
        func_00335960(ctx, p);
    }
    for (p = *(void***)((char*)self + 0x20); p != 0; p = (void**)*p) {
        func_00335B90(ctx, p);
    }
    if (*(void**)((char*)self + 0x0)) func_00340FA0(*(void**)((char*)self + 0x0), ctx);
    if (*(void**)((char*)self + 0x4)) func_00340FA0(*(void**)((char*)self + 0x4), ctx);
    if (*(void**)((char*)self + 0x8)) func_00340FA0(*(void**)((char*)self + 0x8), ctx);
    if (*(void**)((char*)self + 0xC)) func_00340FA0(*(void**)((char*)self + 0xC), ctx);
    if (*(void**)((char*)self + 0x10)) func_00340FA0(*(void**)((char*)self + 0x10), ctx);
    if (*(void**)((char*)self + 0x14)) func_00340FA0(*(void**)((char*)self + 0x14), ctx);
    if (*(void**)((char*)self + 0x18)) func_00340FA0(*(void**)((char*)self + 0x18), ctx);
    if (*(void**)((char*)self + 0x1C)) func_00340FA0(*(void**)((char*)self + 0x1C), ctx);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/worldsphtree", func_003410C0);
#ifdef SKIP_ASM
extern "C" void func_00336D40(void* ctx, void* obj);

extern "C" void func_003410C0(void* self, void* ctx)
{
    void** p;
    for (p = *(void***)((char*)self + 0x20); p != 0; p = (void**)*p) {
        func_00336D40(ctx, p);
    }
    if (*(void**)((char*)self + 0x0)) func_003410C0(*(void**)((char*)self + 0x0), ctx);
    if (*(void**)((char*)self + 0x4)) func_003410C0(*(void**)((char*)self + 0x4), ctx);
    if (*(void**)((char*)self + 0x8)) func_003410C0(*(void**)((char*)self + 0x8), ctx);
    if (*(void**)((char*)self + 0xC)) func_003410C0(*(void**)((char*)self + 0xC), ctx);
    if (*(void**)((char*)self + 0x10)) func_003410C0(*(void**)((char*)self + 0x10), ctx);
    if (*(void**)((char*)self + 0x14)) func_003410C0(*(void**)((char*)self + 0x14), ctx);
    if (*(void**)((char*)self + 0x18)) func_003410C0(*(void**)((char*)self + 0x18), ctx);
    if (*(void**)((char*)self + 0x1C)) func_003410C0(*(void**)((char*)self + 0x1C), ctx);
}
#endif

extern "C" void* func_003400D8(int, int);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003411B8);
#ifdef SKIP_ASM
struct sQuery_3411B8 {
    sWsVec4* pos;               // 0x00
    int a7;                     // 0x04
    int mask;                   // 0x08
    int* cnt;                   // 0x0C
    float* dist;                // 0x10
    sBox_00334680* box;         // 0x14
};

struct sTree_3411B8 {
    sTree_3411B8* child[8];
    int pad20[2];
    char* objs;                 // 0x28
};

extern "C" void func_003411B8(sTree_3411B8* tree, sQuery_3411B8* q)
{
    for (char* o = tree->objs; o != 0; o = *(char**)o) {
        int type = *(int*)(o + 8);
        if (type == 2) {
            func_0035C698(*(void**)(o + 0xC), q->box, q->box, q->pos, q->mask, q->cnt, q->dist, q->a7);
        } else if (type == 3) {
            func_00348290(*(void**)(o + 0xC), q->box, q->box, q->pos, q->mask, q->cnt, q->dist, q->a7);
        } else if (type == 1) {
            if (*(int*)(*(char**)(o + 0x68) + 0x1C) & q->mask) {
                func_00335128(o, q->box, q->pos, q->cnt, q->dist, q->a7);
            }
        }
    }
    if (tree->child[0] != 0) func_003411B8(tree->child[0], q);
    if (tree->child[1] != 0) func_003411B8(tree->child[1], q);
    if (tree->child[2] != 0) func_003411B8(tree->child[2], q);
    if (tree->child[3] != 0) func_003411B8(tree->child[3], q);
    if (tree->child[4] != 0) func_003411B8(tree->child[4], q);
    if (tree->child[5] != 0) func_003411B8(tree->child[5], q);
    if (tree->child[6] != 0) func_003411B8(tree->child[6], q);
    if (tree->child[7] != 0) func_003411B8(tree->child[7], q);
}
#endif

//99.38%
INCLUDE_ASM("intersect/worldsphtree", func_00341368__FPv);
#ifdef SKIP_ASM
void* func_00341368(void* self)
{
    return func_003400D8(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341388);
#ifdef SKIP_ASM
struct sVec4_341388 {
    float x, y, z, w;
    sVec4_341388() {}
    sVec4_341388(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sDef_341388 {
    int f00;
    short type;
    short pad06;
    float time;
    float f0C;
    float f10;
    float x, y, z;
};

struct sObj_341388 {
    int pad00[3];
    void** vt;
    int pad10[2];
    char* mtx;
    int pad1C;
    sVec4_341388 pos;
    float speed;
    float f34;
    int t38;
    int t3C;
    int type;
};

extern void* D_004914E0[];
extern char* D_004A5B64;
extern sVec4_341388 D_004FF120_341388[] __asm__("D_004FF120");
extern sVec4_341388 D_004FF150_341388[] __asm__("D_004FF150");
extern "C" void* func_0034FB00(void* self, void* a1, int type, void* a3);

// PORT: PS2-only VU0 inline asm (v / |v|).
static inline sVec4_341388 vu0Normalize_341388(const sVec4_341388& v)
{
    sVec4_341388 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_341388 vu0Scale_341388(const sVec4_341388& v, float s)
{
    sVec4_341388 r;
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

// PORT: PS2-only VU0 inline asm (matrix * vector).
static inline sVec4_341388 vu0Xform_341388(const sVec4_341388& v, const char* m)
{
    sVec4_341388 r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

extern "C" sObj_341388* func_00341388(sObj_341388* self, void* a1, int a2, void* a3, sDef_341388* def)
{
    func_0034FB00(self, a1, a2, a3);
    self->vt = D_004914E0;
    int type = def->type;
    self->type = type;
    self->t38 = (int)(def->time * (float)*(int*)(D_004A5B64 + 0x10));
    if (def->x == 0.0f && def->y == 0.0f && def->z == 0.0f) {
        if (type == 2) {
            self->pos = *D_004FF150_341388;
        } else {
            self->pos = *D_004FF120_341388;
        }
    } else {
        self->pos = vu0Normalize_341388(sVec4_341388(def->x, def->y, def->z, 0.0f));
    }
    self->speed = def->f10 * 27.77777862548828f;
    self->f34 = def->f0C;
    self->t3C = self->type ? self->t38 : 0;
    if (self->type == 2) {
        char* m = self->mtx + 0x10;
        self->pos = vu0Xform_341388(vu0Scale_341388(self->pos, -1.0f), m);
        self->speed = -self->speed;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341548);
#ifdef SKIP_ASM
extern "C" void* cInstanceNode_cInstanceNode(void* self, void* a1, void* stream);
extern void* D_004914E0[];
struct sVEntry_func_00341548 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_00341548(void* self, void* a1, void* stream)
{
    cInstanceNode_cInstanceNode(self, a1, stream);
    *(void***)((char*)self + 0xC) = D_004914E0;
    sVEntry_func_00341548* vt = *(sVEntry_func_00341548**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x20, 0x30);
    return self;
}
#endif

extern void* D_004914E0[];
extern "C" void* func_0034FBF0(void*);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003415A8__FPv);
#ifdef SKIP_ASM
void* func_003415A8(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_004914E0;
    return func_0034FBF0(self);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003415D0);
#ifdef SKIP_ASM
extern "C" int func_002D1AF0();
extern "C" void** func_002D1B08(int i);

struct sVEnt_003415D0 { short delta; short index; void* fn; };
typedef void (*Fn0_003415D0)(void*);
typedef void (*Fn1_003415D0)(void*, void*);
typedef void (*FnI_003415D0)(void*, int);
typedef int (*Test0_003415D0)(void*);
typedef int (*Test_003415D0)(void*, int);

struct sNode_003415D0 {
    int pad00[3];
    sVEnt_003415D0* vt;
    int pad10[2];
    int a18;
    int pad1C[6];
    float f34;
    int pad38;
    int t3C;
    int type;
};

extern "C" void func_003415D0(sNode_003415D0* self)
{
    int hit = 0;
    if (self->type != 1) {
        hit = 1;
    }
    int t = self->t3C;
    if (t > 0) {
        int n = t - 1;
        self->t3C = n;
        if (n > 0) {
            hit = 1;
        }
    }
    sVEnt_003415D0* vt = self->vt;
    ((Fn0_003415D0)vt[49].fn)((char*)self + vt[49].delta);
    if (self->type == 1 || self->t3C <= 0) {
        for (int i = 0; i < func_002D1AF0(); i++) {
            void** obj = func_002D1B08(i);
            if (self->type == 2) {
                sVEnt_003415D0* ovt = (sVEnt_003415D0*)*obj;
                if (((Test0_003415D0)ovt[9].fn)((char*)obj + ovt[9].delta) != 0) continue;
            }
            sVEnt_003415D0* ovt = (sVEnt_003415D0*)*obj;
            if (((Test_003415D0)ovt[3].fn)((char*)obj + ovt[3].delta, self->a18) != 0) {
                hit = 1;
                if (self->f34 < 0.0f) {
                    sVEnt_003415D0* v = self->vt;
                    ((Fn1_003415D0)v[48].fn)((char*)self + v[48].delta, obj);
                } else {
                    sVEnt_003415D0* v = self->vt;
                    ((Fn1_003415D0)v[47].fn)((char*)self + v[47].delta, obj);
                }
            }
        }
    }
    sVEnt_003415D0* v2 = self->vt;
    ((Fn0_003415D0)v2[50].fn)((char*)self + v2[50].delta);
    if (hit == 0) {
        sVEnt_003415D0* v3 = self->vt;
        ((FnI_003415D0)v3[34].fn)((char*)self + v3[34].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341770);
#ifdef SKIP_ASM
struct sVec4_341770 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_341770 vu0Scale_341770(const sVec4_341770& v, float s)
{
    sVec4_341770 r;
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

class cMover_341770 {
public:
    virtual void v01();
    virtual sVec4_341770* getVelocity();
    virtual void v03();
    virtual void setVelocity(sVec4_341770* v);
};

extern "C" float func_002D1C70();

extern "C" void func_00341770(void* self, cMover_341770* obj)
{
    sVec4_341770 u = vu0Scale_341770(vu0Scale_341770(*obj->getVelocity(), *(float*)((char*)self + 0x34) + 1.0f), func_002D1C70());
    obj->setVelocity(&u);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341818);
#ifdef SKIP_ASM
struct sVec4_341818 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (v / |v|).
static inline sVec4_341818 vu0Normalize_341818(const sVec4_341818& v)
{
    sVec4_341818 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_341818(const sVec4_341818& a, const sVec4_341818& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_341818 vu0Scale_341818(const sVec4_341818& v, float s)
{
    sVec4_341818 r;
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

class cMover_341818 {
public:
    virtual void v01();
    virtual sVec4_341818* getVelocity();
    virtual void v03();
    virtual void setVelocity(sVec4_341818* v);
};

extern "C" float func_002D1C70();

struct sParams_341818 {
    sVec4_341818 dir;
    float speed;
    float scale;
};

struct sSph_341818 {
    char pad00[0x20];
    sParams_341818 params;
    int type;
};

static inline void push_341818(sParams_341818* p, cMover_341818* obj, const sVec4_341818& dir, float amount)
{
    sVec4_341818 u = vu0Scale_341818(vu0Scale_341818(vu0Scale_341818(dir, amount), p->scale), func_002D1C70());
    obj->setVelocity(&u);
}

extern "C" void func_00341818(sSph_341818* self, cMover_341818* obj)
{
    sVec4_341818 vel = *obj->getVelocity();
    sVec4_341818 dir = self->params.dir;
    if (dir.x == 0.0f && dir.y == 0.0f && dir.z == 0.0f) {
        dir = vu0Normalize_341818(vel);
    }
    float d = vu0Dot_341818(vel, dir);
    float diff = self->params.speed - d;
    sParams_341818* p = &self->params;
    if (self->type == 2) {
        if (d >= 0.0f) {
            sVec4_341818 u = vu0Scale_341818(vu0Scale_341818(vu0Scale_341818(dir, p->speed), p->scale), func_002D1C70());
            obj->setVelocity(&u);
        }
    } else if (diff > 0.0f) {
        sVec4_341818 u = vu0Scale_341818(vu0Scale_341818(vu0Scale_341818(dir, diff), p->scale), func_002D1C70());
        obj->setVelocity(&u);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341A30);
#ifdef SKIP_ASM
extern "C" void func_00341A30(void* self, int a1)
{
    if (a1 == 1) {
        *(int*)((char*)self + 0x3c) = *(int*)((char*)self + 0x38);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341A50);
#ifdef SKIP_ASM
struct sSerVEntry_00341A50 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0034FE90(void* self, void* stream);

extern "C" void func_00341A50(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sSerVEntry_00341A50* vt = *(sSerVEntry_00341A50**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x20, 0x30);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341AA0);
#ifdef SKIP_ASM
extern char* D_004A5B64;
extern void* D_00490B10[];
extern "C" void func_0034D9B0(void* p, int a1, int a2, void* obj, int a4);
extern "C" float func_00351508(void* inst);
float AIrandf(float lo, float hi);
float func_00317890(float a, float b);

struct sSphFloat_1AA0 {
    unsigned short id;  // 0x00
    char pad02[0x2];
    int active;         // 0x04
    int atLimit;        // 0x08
    int fC;             // 0x0C
    float speed;        // 0x10
    float min;          // 0x14
    float max;          // 0x18
    float value;        // 0x1C
    float start;        // 0x20
    char pad24[0x18];
    void** vt;          // 0x3C
    char pad40[0x2];
    unsigned short flags; // 0x42
    char pad44[0x20];
    void* inst;         // 0x64
};

struct sSphFloatDef_1AA0 {
    int f0;
    unsigned short id;  // 0x04
    char pad06[0x2];
    int dir;            // 0x08
    float min;          // 0x0C
    float max;          // 0x10
    float speed;        // 0x14
    float speedVar;     // 0x18
    float value;        // 0x1C
    int random;         // 0x20
    int f24;            // 0x24
};

struct sFloat_1AA0 {
    float v;
};

static inline void setRate_1AA0(sFloat_1AA0* dst, float v, float dflt)
{
    float r;
    if (v >= 0.0f) {
        r = v * 0.03333333507180214f;
    } else {
        r = dflt;
    }
    dst->v = r;
}

static inline void setRateMax_1AA0(sFloat_1AA0* dst, float v, char* info)
{
    float r;
    if (v < 0.0f) {
        r = *(float*)(info + 0x14);
    } else {
        r = v * 0.03333333507180214f;
    }
    dst->v = r;
}

// Animated float constructor: range and start value (frames -> seconds), optional random start and speed.
extern "C" void* func_00341AA0(sSphFloat_1AA0* self, int a1, int a2, char* obj, sSphFloatDef_1AA0* def)
{
    func_0034D9B0((char*)self + 0x1C, a1, a2, obj, def->f24 != 0);
    self->vt = D_00490B10;
    float v = 0.0f;
    char* info = *(char**)(obj + 0x80);
    if (self->inst != 0) {
        v = func_00351508(self->inst);
    }
    self->id = def->id;
    setRate_1AA0((sFloat_1AA0*)&self->min, def->min, v);
    setRateMax_1AA0((sFloat_1AA0*)&self->max, def->max, info);
    v = def->value;
    if (v < 0.0f) {
        v = self->min;
    } else {
        v *= 0.03333333507180214f;
    }
    if (v < self->min) {
        v = self->min;
    }
    if (self->max < v) {
        v = self->max;
    }
    if (def->random != 0) {
        v = AIrandf(self->min, self->max);
    }
    self->value = v;
    if (def->speedVar != 0.0f) {
        self->speed = func_00317890(def->speed * 0.03333333507180214f, def->speedVar * 0.03333333507180214f) / (float)*(int*)(D_004A5B64 + 0x10);
    } else {
        self->speed = def->speed * 0.03333333507180214f / (float)*(int*)(D_004A5B64 + 0x10);
    }
    if (def->dir == 1) {
        self->speed = -self->speed;
    }
    self->start = self->value;
    self->active = 1;
    self->flags |= 1;
    self->fC = 0;
    self->atLimit = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341C80);
#ifdef SKIP_ASM
struct sVEntry00341C80 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_0034DAC8(void* p, int a1, void* stream);
extern void* D_00490B10[];

extern "C" void* func_00341C80(void* self, int a1, sVEntry00341C80** stream)
{
    func_0034DAC8((char*)self + 0x1C, a1, stream);
    *(void***)((char*)self + 0x3C) = D_00490B10;
    (*stream)[2].fn((char*)stream + (*stream)[2].delta, self, 0x1C);
    *(unsigned short*)((char*)self + 0x42) |= 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341CF0);
#ifdef SKIP_ASM
extern "C" void func_0034DBA8(void* p, int flags);
void operator_delete(int* ptr);
extern void* D_00490B10[];

extern "C" void func_00341CF0(void* self, int flags)
{
    *(void***)((char*)self + 0x3C) = D_00490B10;
    func_0034DBA8((char*)self + 0x1C, 0);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341D48);
#ifdef SKIP_ASM
struct sWrapFloat_1E48;
struct sBounceFloat_1EC0;
struct sClampFloat_1F38;
extern "C" void func_00341E48(sWrapFloat_1E48* s);
extern "C" void func_00341EC0(sBounceFloat_1EC0* s);
extern "C" void func_00341F38(sClampFloat_1F38* s);
extern "C" int func_0034EBA0(void* p);

struct sVEntry_00341D48 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" int func_00341D48(void* self)
{
    *(float*)((char*)self + 0x24) = 10000000000.0f;
    *(float*)((char*)self + 0x28) = 10000000000.0f;
    if (*(int*)((char*)self + 0x8) != 0) {
        return 1;
    }
    if (*(int*)((char*)self + 0x4) != 0 && *(int*)((char*)self + 0xC) >= 0) {
        if (*(int*)((char*)self + 0xC) > 0) {
            *(int*)((char*)self + 0xC) -= 1;
        } else {
            *(float*)((char*)self + 0x24) = *(float*)((char*)self + 0x1C);
            switch (*(short*)self) {
            case 2:
                func_00341EC0((sBounceFloat_1EC0*)self);
                break;
            case 1:
                func_00341E48((sWrapFloat_1E48*)self);
                break;
            default:
                func_00341F38((sClampFloat_1F38*)self);
                break;
            }
            if (func_0034EBA0((char*)self + 0x1C) == 0) {
                return 0;
            }
        }
    }
    char* obj = (char*)self + 0x30;
    *(unsigned short*)((char*)self + 0x42) |= 1;
    *(float*)((char*)self + 0x20) = *(float*)((char*)self + 0x1C);
    if (*(int*)((char*)self + 0x8) == 0) {
        return 1;
    }
    sVEntry_00341D48* vt = *(sVEntry_00341D48**)((char*)self + 0x3C);
    vt[0x22].fn(obj + vt[0x22].delta, 1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341E48);
#ifdef SKIP_ASM
struct sWrapFloat_1E48 {
    char pad_0x00[0x10];
    float speed;    // 0x10
    float min;      // 0x14
    float max;      // 0x18
    float value;    // 0x1C
    char pad_0x20[0x8];
    float last;     // 0x28
};

extern "C" void func_00341E48(sWrapFloat_1E48* s)
{
    if (s->speed >= 0.0f) {
        s->value += s->speed;
        s->last = s->value;
        if (s->value > s->max) {
            s->value = s->min + (s->value - s->max);
        }
    } else {
        s->value += s->speed;
        s->last = s->value;
        if (s->value < s->min) {
            s->value = s->max - (s->min - s->value);
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341EC0);
#ifdef SKIP_ASM
struct sBounceFloat_1EC0 {
    char pad_0x00[0x10];
    float speed;    // 0x10
    float min;      // 0x14
    float max;      // 0x18
    float value;    // 0x1C
    char pad_0x20[0x8];
    float last;     // 0x28
};

extern "C" void func_00341EC0(sBounceFloat_1EC0* s)
{
    if (s->speed >= 0.0f) {
        s->value += s->speed;
        s->last = s->value;
        if (s->value > s->max) {
            s->speed = -s->speed;
            s->value = s->max - (s->value - s->max);
        }
    } else {
        s->value += s->speed;
        s->last = s->value;
        if (s->value < s->min) {
            s->speed = -s->speed;
            s->value = s->min + (s->min - s->value);
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341F38);
#ifdef SKIP_ASM
struct sClampFloat_1F38 {
    char pad_0x00[0x8];
    int atLimit;    // 0x08
    char pad_0x0C[0x4];
    float speed;    // 0x10
    float min;      // 0x14
    float max;      // 0x18
    float value;    // 0x1C
    char pad_0x20[0x8];
    float last;     // 0x28
};

extern "C" void func_00341F38(sClampFloat_1F38* s)
{
    if (s->speed >= 0.0f) {
        if (s->value == s->max) {
            s->atLimit = 1;
        }
        s->value += s->speed;
        s->last = s->value;
        if (s->value > s->max) {
            s->value = s->max;
        }
    } else {
        if (s->value == s->min) {
            s->atLimit = 1;
        }
        s->value += s->speed;
        s->last = s->value;
        if (s->value < s->min) {
            s->value = s->min;
        }
    }
}
#endif

void func_0034FCC0(void*);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341FC8);
#ifdef SKIP_ASM
extern "C" void func_00341FC8(void* self, int a1)
{
    if (a1 != 0) {
        func_0034FCC0((char*)self + 0x30);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341FE8);
#ifdef SKIP_ASM
extern char* D_004A5B64;
extern "C" void func_00356B08(void* p);

extern "C" void func_00341FE8(sClampFloat_1F38* self, int msg, float v)
{
    if (msg == 0x64) {
        *(int*)((char*)self + 0xC) = (int)(v * (float)*(int*)(D_004A5B64 + 0x10));
    } else if (msg == 0x65) {
        v = v * 0.03333333507180214f;
        if (self->min <= v && v <= self->max) {
            self->value = v;
        }
    } else if (msg == 0x66) {
        v = v * 0.03333333507180214f;
        self->speed = v / (float)*(int*)(D_004A5B64 + 0x10);
    } else if (msg == 0x67) {
        v = v * 0.03333333507180214f;
        float lim = *(float*)(*(char**)(*(char**)((char*)self + 0x48) + 0x80) + 0x14);
        if (lim < v) {
            v = lim;
        }
        if (v < 0.0f) {
            v = 0.0f;
        }
        self->max = v;
        if (v < self->value) {
            self->value = v;
        }
    } else if (msg == 0x68) {
        v = v * 0.03333333507180214f;
        float lim = *(float*)(*(char**)(*(char**)((char*)self + 0x48) + 0x80) + 0x14);
        if (lim < v) {
            v = lim;
        }
        if (v < 0.0f) {
            v = 0.0f;
        }
        self->min = v;
        if (self->value < v) {
            self->value = v;
        }
    } else if (msg == 0x69) {
        *(short*)self = 0;
    } else {
        func_00356B08((char*)self + 0x30);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342150);
#ifdef SKIP_ASM
extern "C" void func_0034E3D8(void* p, void* stream);
struct sVEntry_func_00342150 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00342150(void* self, void* stream)
{
    func_0034E3D8((char*)self + 0x1C, stream);
    sVEntry_func_00342150* vt = *(sVEntry_func_00342150**)stream;
    vt[1].fn((char*)stream + vt[1].delta, self, 0x1C);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003421A0);
#ifdef SKIP_ASM
extern char* D_004A5B64;
extern void* D_004908F8[];
extern "C" void func_0034D9B0(void* p, int a1, int a2, void* obj, int a4);
extern "C" float func_00351508(void* inst);

struct sSphCtl_003421A0 {
    int f00;            // 0x00
    int f04;            // 0x04
    float f08;          // 0x08
    float f0C;          // 0x0C
    float f10;          // 0x10
    float f14;          // 0x14
    float f18;          // 0x18
    float f1C;          // 0x1C
    float f20;          // 0x20
    float f24;          // 0x24
    int f28;            // 0x28
    int f2C;            // 0x2C
    char pad30[0x20];
    void** vt;          // 0x50
    char pad54[2];
    unsigned short flags; // 0x56
    char pad58[0x20];
    void* inst;         // 0x78
};

struct sFloat_003421A0 {
    float v;
};

static inline void setRate_003421A0(sFloat_003421A0* dst, float v, float dflt)
{
    float r;
    if (v >= 0.0f) {
        r = v * 0.03333333507180214f;
    } else {
        r = dflt;
    }
    dst->v = r;
}

static inline void setRateMax_003421A0(sFloat_003421A0* dst, float v, char* info)
{
    float r;
    if (v < 0.0f) {
        r = *(float*)(info + 0x14);
    } else {
        r = v * 0.03333333507180214f;
    }
    dst->v = r;
}

extern "C" void* func_003421A0(sSphCtl_003421A0* self, int a1, char* obj, char* def)
{
    func_0034D9B0((char*)self + 0x30, a1, 4, obj, 0);
    self->vt = D_004908F8;
    float t = 0.0f;
    char* info = *(char**)(obj + 0x80);
    if (self->inst != 0) {
        t = func_00351508(self->inst);
    }
    setRate_003421A0((sFloat_003421A0*)&self->f10, *(float*)(def + 0x20), t);
    setRateMax_003421A0((sFloat_003421A0*)&self->f14, *(float*)(def + 0x24), info);
    self->f0C = *(float*)(def + 0x8);
    self->f08 = *(float*)(def + 0x4) * 9.999999974752427e-07f;
    self->f18 = *(float*)(def + 0xC) * 0.03333333507180214f / (float)*(int*)(D_004A5B64 + 0x10);
    self->f2C = *(int*)(def + 0x1C);
    self->f24 = *(float*)(def + 0x14) * 0.03333333507180214f;
    self->f1C = *(float*)(def + 0x18);
    self->f20 = *(float*)(def + 0x10);
    self->flags |= 1;
    self->f00 = 0;
    self->f04 = 0;
    self->f28 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003422E8);
#ifdef SKIP_ASM
struct sVEntry003422E8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_0034DAC8(void* p, int a1, void* stream);
extern void* D_004908F8[];

extern "C" void* func_003422E8(void* self, int a1, sVEntry003422E8** stream)
{
    func_0034DAC8((char*)self + 0x30, a1, stream);
    *(void***)((char*)self + 0x50) = D_004908F8;
    (*stream)[2].fn((char*)stream + (*stream)[2].delta, self, 0x30);
    *(unsigned short*)((char*)self + 0x56) |= 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342358);
#ifdef SKIP_ASM
extern "C" float func_002D1C70();
extern "C" int func_0034EBA0(void* p);

struct sSphCtl_00342358 {
    float force;        // 0x00
    float step;         // 0x04
    float gain;         // 0x08
    float bounce;       // 0x0C
    float min;          // 0x10
    float max;          // 0x14
    float maxStep;      // 0x18
    float damping;      // 0x1C
    float stiffness;    // 0x20
    float rest;         // 0x24
    float vel;          // 0x28
    int f2C;            // 0x2C
    float pos;          // 0x30
    float pos34;        // 0x34
    float prev;         // 0x38
    float pos3C;        // 0x3C
    char pad40[0x16];
    unsigned short flags; // 0x56
};

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_00342358(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" int func_00342358(sSphCtl_00342358* s)
{
    s->prev = s->pos;
    float dt = func_002D1C70();
    float force = s->gain * s->force;
    if (s->gain < 0.0f) {
        force = -force;
    }
    float vel = s->vel;
    float maxStep = s->maxStep;
    float step = vel * dt;
    float acc = -s->stiffness * (s->pos - s->rest);
    acc += force;
    acc += -s->damping * vel;
    s->step = step;
    if (maxStep < absf_00342358(step)) {
        if (step < 0.0f) {
            s->step = -maxStep;
        } else {
            s->step = maxStep;
        }
    }
    float pos = s->pos + s->step;
    float nv = s->vel + acc * dt;
    s->pos = pos;
    s->pos3C = pos;
    s->vel = nv;
    if (pos < s->min) {
        s->pos = s->min;
        if (absf_00342358(nv) > 0.1f) {
            s->vel = nv * s->bounce;
        } else {
            s->step = 0.0f;
            s->vel = 0.0f;
        }
    } else if (s->max < pos) {
        s->pos = s->max;
        if (absf_00342358(nv) > 0.1f) {
            s->vel = nv * s->bounce;
        } else {
            s->step = 0.0f;
            s->vel = 0.0f;
        }
    }
    s->force = 0.0f;
    s->pos34 = s->pos;
    if (func_0034EBA0(&s->pos) == 0) {
        return 0;
    }
    s->flags |= 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003424D0);
#ifdef SKIP_ASM
extern "C" float func_003424D0(void* self)
{
    if (*(float*)((char*)self + 0x30) <= *(float*)((char*)self + 0x10) && *(float*)((char*)self + 0x4) < 0.0f) {
        return 0.0f;
    }
    if (*(float*)((char*)self + 0x30) >= *(float*)((char*)self + 0x14) && *(float*)((char*)self + 0x4) > 0.0f) {
        return 0.0f;
    }
    return *(float*)((char*)self + 0x4);
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00342538);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342718);
#ifdef SKIP_ASM
extern "C" void func_0034E3D8(void* p, void* stream);
struct sVEntry_func_00342718 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00342718(void* self, void* stream)
{
    func_0034E3D8((char*)self + 0x30, stream);
    sVEntry_func_00342718* vt = *(sVEntry_func_00342718**)stream;
    vt[1].fn((char*)stream + vt[1].delta, self, 0x30);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342768);
#ifdef SKIP_ASM
struct sVec4_342768 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sSphDef_342768 {
    int f00;
    short type;
    short pad06;
    float time;
    float f0C;
    float f10;
    float x, y, z;
};
struct sSph_342768 {
    int refs;
    void** vt;
    int pad08[2];
    sVec4_342768 pos;
    float f20;
    float f24;
    int t28;
    int t2C;
    int type;
    int pad34[3];
    int a40;
};
extern void* D_00490898[];
extern char* D_004A5B64;

extern "C" void* func_00342768(sSph_342768* self, sSphDef_342768* def, int a2)
{
    self->refs = 1;
    self->vt = D_00490898;
    self->a40 = a2;
    int type = def->type;
    self->type = type;
    int t = (int)(def->time * (float)*(int*)(D_004A5B64 + 0x10));
    self->t28 = t;
    sVec4_342768 v;
    v.x = def->x;
    v.y = def->y;
    v.z = def->z;
    v.w = 0.0f;
    self->pos = v;
    self->f20 = def->f10 * 100.0f;
    self->f24 = def->f0C;
    self->t2C = type == 1 ? t : 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342808);
#ifdef SKIP_ASM
struct sVEntry00342808 {
    short delta;
    short index;
    void* fn;
};

typedef void (*ReadFn00342808)(void*, void*, int);
typedef int (*ReadIntFn00342808)(void*);

extern void* D_00490898[];

extern "C" void* func_00342808(void* self, sVEntry00342808** stream)
{
    *(int*)((char*)self + 0x0) = 1;
    *(void***)((char*)self + 0x4) = D_00490898;
    ((ReadFn00342808)(*stream)[2].fn)((char*)stream + (*stream)[2].delta, (char*)self + 0x10, 0x30);
    *(int*)((char*)self + 0x40) = ((ReadIntFn00342808)(*stream)[3].fn)((char*)stream + (*stream)[3].delta);
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342880);
#ifdef SKIP_ASM
extern "C" int func_002D1AF0();
extern "C" void** func_002D1B08(int i);

struct sVEnt_00342880 { short delta; short index; void* fn; };
typedef void (*Fn0_00342880)(void*);
typedef void (*Fn1_00342880)(void*, void*);
typedef int (*Test_00342880)(void*, int);

extern "C" void func_00342880(sSph_342768* self)
{
    self->refs = 0;
    if (self->type == 0) {
        self->refs = 1;
    }
    int t = self->t2C;
    if (t > 0) {
        t--;
        self->t2C = t;
        if (t > 0) {
            self->refs = 1;
        }
    }
    sVEnt_00342880* vt = (sVEnt_00342880*)self->vt;
    ((Fn0_00342880)vt[9].fn)((char*)self + vt[9].delta);
    if (self->type == 1 || self->t2C <= 0) {
        for (int i = 0; i < func_002D1AF0(); i++) {
            void** obj = func_002D1B08(i);
            sVEnt_00342880* ovt = (sVEnt_00342880*)*obj;
            if (((Test_00342880)ovt[3].fn)((char*)obj + ovt[3].delta, self->a40) != 0) {
                self->refs = 1;
                if (self->f24 < 0.0f) {
                    sVEnt_00342880* v = (sVEnt_00342880*)self->vt;
                    ((Fn1_00342880)v[8].fn)((char*)self + v[8].delta, obj);
                } else {
                    sVEnt_00342880* v = (sVEnt_00342880*)self->vt;
                    ((Fn1_00342880)v[7].fn)((char*)self + v[7].delta, obj);
                }
            }
        }
    }
    sVEnt_00342880* v2 = (sVEnt_00342880*)self->vt;
    ((Fn0_00342880)v2[10].fn)((char*)self + v2[10].delta);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003429E0);
#ifdef SKIP_ASM
struct sVec4_3429E0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_3429E0 vu0Scale_3429E0(const sVec4_3429E0& v, float s)
{
    sVec4_3429E0 r;
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

class cMover_3429E0 {
public:
    virtual void v01();
    virtual sVec4_3429E0* getVelocity();
    virtual void v03();
    virtual void setVelocity(sVec4_3429E0* v);
};

extern "C" float func_002D1C70();

extern "C" void func_003429E0(void* self, cMover_3429E0* obj)
{
    sVec4_3429E0 u = vu0Scale_3429E0(vu0Scale_3429E0(*obj->getVelocity(), *(float*)((char*)self + 0x24) + 1.0f), func_002D1C70());
    obj->setVelocity(&u);
}
#endif

INCLUDE_ASM("intersect/worldsphtree", func_00342A88);

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342B80);
#ifdef SKIP_ASM
extern "C" void func_00342B80(void* self, int a1)
{
    if (a1 == 0x258) {
        *(int*)((char*)self + 0x2c) = *(int*)((char*)self + 0x28);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342BA0);
#ifdef SKIP_ASM
extern "C" void func_003584B8(void* self, void* stream);
struct sVEntry_func_00342BA0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};
struct sVEntry1_func_00342BA0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00342BA0(void* self, void* stream)
{
    func_003584B8(self, stream);
    sVEntry_func_00342BA0* vt = *(sVEntry_func_00342BA0**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x10, 0x30);
    sVEntry1_func_00342BA0* vt1 = *(sVEntry1_func_00342BA0**)stream;
    vt1[5].fn((char*)stream + vt1[5].delta, *(int*)((char*)self + 0x40));
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342C08);
#ifdef SKIP_ASM
extern "C" void* func_00355280(void* self, void* a1, int type, void* a3);
extern "C" void func_00355F10(void* self, void* a1);
extern void* D_004906F0[];

struct sNode_342C08 {
    int pad00[2];
    unsigned int flags;
};

struct sDef_342C08 {
    int f00;
    float time;
    int f08;
    int mode;
};

struct sSelf_342C08 {
    int pad00[3];
    void** vt;
    int pad10[2];
    sNode_342C08* node;
    int pad1C[4];
    int t2C;
    int t30;
};

extern "C" void* func_00342C08(sSelf_342C08* self, void* a1, void* a2, sDef_342C08* def, void* a4)
{
    func_00355280(self, a1, 0, a2);
    self->vt = D_004906F0;
    self->t2C = (int)(def->time * (float)*(int*)(D_004A5B64 + 0x10));
    self->t30 = def->f08;
    func_00355F10(self, a4);
    if (def->mode == 0) {
        self->node->flags &= 0xFFFFFFF0;
    } else if (def->mode == 1) {
        self->node->flags |= 1;
        self->node->flags = (self->node->flags & ~2u) | 4;
    } else {
        sNode_342C08* n = self->node;
        if ((n->flags & 3) == 3) {
            n->flags = (n->flags & ~2u) | 4;
        }
    }
    return self;
}
#endif

