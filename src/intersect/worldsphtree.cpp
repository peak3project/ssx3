#include "common.h"
#include "bx/math3d.h"

// ---- Shared declarations: one type per real thing, used by the functions below ----

// g++ 2.95 vtable entry with an untyped function slot (cast at the call).
struct sWsVtSlot { short delta; short index; void* fn; };

// g++ 2.95 vtable entry for a method taking (self, pointer, int).
struct sWsVtVPI {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// g++ 2.95 vtable entry for a method taking only self, returning float.
struct sWsVtF { short delta; short index; float (*fn)(void*); };

// g++ 2.95 vtable entry for a method taking (self, int).
struct sWsVtVI {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// Octree cell key: level and integer cell coordinates.
struct sWsCell {
    int level, x, y, z;
};

// Axis-aligned box as two float[4] corners (min, max).
struct sWsBox {
    float min[4];
    float max[4];
};

// A linked world object with its bounds at 0x158 (bmin, bmax).
struct sWsBoundObj {
    sWsBoundObj* next;              // 0x00
    char pad04[0x154];
    float bmin[3];                  // 0x158
    float bmax[3];                  // 0x164
};

// Query record with its box at 0x20 (max then min).
struct sWsQueryBox {
    char pad00[0x20];
    float max[4];
    float min[4];
};

// Ray / sphere hit record (distance at 0x40, object and triangle at 0x50; empty ctor).
struct sWsRayHit {
    float pad0[16];
    float dist;             // 0x40
    int pad44[3];
    char* obj;              // 0x50
    char* tri;              // 0x54
    int pad58[10];
    sWsRayHit() {}
} __attribute__((aligned(16)));

// Hit record with a direction at 0x10 and its length at 0x40.
struct sWsDirHit {
    char pad_0x00[0x10];
    t4Vector dir;      // 0x10
    char pad_0x20[0x20];
    float len;            // 0x40
};

// A triangle-mesh world object (id, flags, bounds at 0x158).
struct sWsTriObj {
    char pad00[8];
    short id;
    unsigned short flags;
    char pad0C[0x14C];
    float bmin[3];
    float bmax[3];
};

// Octree node with eight children and two object lists.
struct sWsOctNode2 {
    void* child[8];                 // 0x00
    void** listB;                   // 0x20
    void** listA;                   // 0x24
};

// Octree node with eight children and one object list.
struct sWsOctNode {
    void* child[8];                 // 0x00
    void** list;                    // 0x20
};

// Collector of found objects (array and count pointers).
struct sWsCollect {
    void** arr;
    int* count;
};

// Sphere definition record (type, time, position).
struct sWsSphDef {
    int f00;
    short type;
    short pad06;
    float time;
    float f0C;
    float f10;
    float x, y, z;
};

// A single float wrapped in a struct (written through a pointer by the rate setters).
struct sWsFloat {
    float v;
};

// Animated float parameter (speed, range, value, last value).
struct sWsAnimFloat {
    char pad_0x00[0x10];
    float speed;    // 0x10
    float min;      // 0x14
    float max;      // 0x18
    float value;    // 0x1C
    char pad_0x20[0x8];
    float last;     // 0x28
};

// Query box as two vectors (min, max) for the octree / cell visitors.
struct sWsBoxV {
    t4Vector min;
    t4Vector max;
};

// A polymorphic world object as the list walkers see it (vtable pointer at 0xC).
struct sWsVObj {
    int pad00[3];
    sWsVtSlot* vt;
};

// Interface of a moving object (getVelocity / setVelocity at slots 2 and 4).
class cWsMover {
public:
    virtual void v01();
    virtual t4Vector* getVelocity();
    virtual void v03();
    virtual void setVelocity(t4Vector* v);
};

// Triangle hit record (position, normal, distance, type, object, uv).
struct sWsTriHit {
    t4Vector pos;   // 0x00
    t4Vector nrm;   // 0x10
    t4Vector v20;   // 0x20
    t4Vector v30;   // 0x30
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

// Sphere query arguments (position, mask, count and distance outputs, box).
struct sWsSphQuery {
    t4Vector* pos;                   // 0x00
    int a7;                         // 0x04
    int mask;                       // 0x08
    int* cnt;                       // 0x0C
    float* dist;                    // 0x10
    sWsBoxV* box;             // 0x14
};

// A world-list node (next, flags, object, bounds at 0x60, active flag).
struct sWsListNode {
    sWsListNode* next;
    int pad04;
    int flags;
    sWsVObj* obj;
    int pad10[20];
    float bmin[3];
    float bmax[3];
    int pad78[4];
    int active;
};

// Empty helper object the cell visitors keep on the stack (one byte; its address is passed as a flag pointer).
struct sWsQH {};

// Output context of the list collectors: node array, count, and the query box.
struct sWsListCtx {
    sWsListNode** list;
    int* count;
    int pad08;
    sWsBox* box;
};

// Two list contexts (patches, then objects) handed to one cell visitor.
struct sWsListCtx2 {
    sWsListCtx a;
    sWsListCtx b;
};

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline int overlapBoundObj(const sWsBox* b, const sWsBoundObj* n)
{
    int r = 0;
    if (b->min[0] <= n->bmax[0] && b->max[0] >= n->bmin[0] &&
        b->min[1] <= n->bmax[1] && b->max[1] >= n->bmin[1] &&
        b->min[2] <= n->bmax[2] && b->max[2] >= n->bmin[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapNode(const sWsQueryBox* q, const sWsListNode* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector vu0Scale(const t4Vector& v, float s)
{
    t4Vector r;
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

static inline int isBetterHit(sWsRayHit* a, sWsRayHit* b)
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float wsLength(const t4Vector& v)
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
static inline t4Vector wsDiv(const t4Vector& v, float s)
{
    t4Vector r;
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float wsLengthT(const t4Vector& v)
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
static inline void wsDivEq(t4Vector& v, float s)
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

static inline void resetListCtx(sWsListCtx* cb)
{
    *cb->count = 0;
}

static inline int overlapTri(const sWsQueryBox* q, const sWsTriObj* n)
{
    int r = 0;
    if (q->max[0] > n->bmin[0] && q->min[0] < n->bmax[0] &&
        q->max[1] > n->bmin[1] && q->min[1] < n->bmax[1] &&
        q->max[2] > n->bmin[2] && q->min[2] < n->bmax[2]) {
        r = 1;
    }
    return r;
}

// Query box vs box; overlapBoxB is the same test with the z comparison written the other way round.
static inline int overlapBox(const sWsQueryBox* q, const sWsBox* o)
{
    int r = 0;
    if (q->max[0] > o->min[0] && q->min[0] < o->max[0] &&
        q->max[1] > o->min[1] && q->min[1] < o->max[1] &&
        q->max[2] > o->min[2] && o->max[2] > q->min[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapBoxB(const sWsQueryBox* q, const sWsBox* o)
{
    int r = 0;
    if (q->max[0] > o->min[0] && q->min[0] < o->max[0] &&
        q->max[1] > o->min[1] && q->min[1] < o->max[1] &&
        q->max[2] > o->min[2] && q->min[2] < o->max[2]) {
        r = 1;
    }
    return r;
}

static inline void setRate(sWsFloat* dst, float v, float dflt)
{
    float r;
    if (v >= 0.0f) {
        r = v * 0.03333333507180214f;
    } else {
        r = dflt;
    }
    dst->v = r;
}

static inline void setRateMax(sWsFloat* dst, float v, char* info)
{
    float r;
    if (v < 0.0f) {
        r = *(float*)(info + 0x14);
    } else {
        r = v * 0.03333333507180214f;
    }
    dst->v = r;
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot(const t4Vector& a, const t4Vector& b)
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

// Callees declared by several functions below.
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" int func_002D1AF0();
extern "C" void** func_002D1B08(int i);
extern "C" float func_002D1C70();
extern "C" void func_003279D0(void* cache, void* src, void** out);
extern "C" int func_0032B6E0(void* q, void* obj, void* node, t4Vector* pos, t4Vector* nrm, float* dist, t4Vector* uv, int arg);
extern "C" float func_0032C590(void* self);
extern "C" int func_00334888(void* q, void* node, void* buf, int cap, int mode);
extern "C" void func_00335960(void* ctx, void* obj);
extern "C" void func_00335B90(void* ctx, void* obj);
extern "C" void func_00336D40(void* ctx, void* obj);
extern "C" void func_00340FA0(void* self, void* ctx);
extern "C" void func_003410C0(void* self, void* ctx);
extern "C" void* func_0034D9B0(void* p, int a1, int a2, void* obj, int a4);
extern "C" void* func_0034DAC8(void* p, int a1, void* stream);
extern "C" void func_0034E3D8(void* p, void* stream);
extern "C" int func_0034EBA0(void* p);
extern "C" float func_00351508(void* inst);

// Globals declared by several functions below.
extern void* D_0048E5F0[];
extern void* D_00490898[];
extern void* D_004908F8[];
extern void* D_00490B10[];
extern void* D_004914E0[];
extern char* D_004A5B64;

// Constant vector table (0x004FF120; 00341388 also reads it through its ctor vector type).
extern t4Vector D_004FF120[];

// ---- end of shared declarations ----

//100%
INCLUDE_ASM("intersect/worldsphtree", cWorldSphTree_cWorldSphTree);
#ifdef SKIP_ASM
extern char D_0048E550[];
extern "C" void* func_0032C508(void* p);

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
    t4Vector c = *(t4Vector*)((char*)a1 + 0x80);
    float r = func_0032C590(a1);
    t4Vector t;
    *(t4Vector*)((char*)self + 0x40) = c;
    t.x = c.x + r;
    t.y = c.y + r;
    t.z = c.z + r;
    t.w = 1.0f;
    *(t4Vector*)((char*)self + 0x20) = t;
    t.x = c.x - r;
    t.y = c.y - r;
    t.z = c.z - r;
    t.w = 1.0f;
    *(t4Vector*)((char*)self + 0x30) = t;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline t4Vector add_330540(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
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
static inline t4Vector sub_330540(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
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


extern "C" int func_00330540(void* self, float* lo, float* hi)
{
    t4Vector ext;
    float rx = func_0032C590(*(void**)((char*)self + 0x60));
    float ry = func_0032C590(*(void**)((char*)self + 0x60));
    float rz = func_0032C590(*(void**)((char*)self + 0x60));
    ext.x = rx;
    ext.y = ry;
    ext.z = rz;
    ext.w = 0.0f;
    t4Vector mx = add_330540(*(t4Vector*)(*(char**)((char*)self + 0x60) + 0x80), ext);
    t4Vector mn = sub_330540(*(t4Vector*)(*(char**)((char*)self + 0x60) + 0x80), ext);
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

extern "C" int func_0032CA78(void* tree, int a1, int a2, int a3, int a4, t4Vector* out, int a6);

extern "C" int func_00330788(void* self, int a1, int a2, int a3, int a4, int a5, t4Vector* outDir, float* outLen)
{
    t4Vector v;
    int r = func_0032CA78(*(void**)((char*)self + 0x60), a1, a2, a3, a4, &v, a5);
    if (r != 0) {
        float len = wsLength(v);
        *outLen = len;
        *outDir = wsDiv(v, len);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330828);
#ifdef SKIP_ASM

extern "C" int func_00328030(void* tree, int a1, int a2, int a3, int a4, t4Vector* out, int a6);

extern "C" int func_00330828(void* self, int a1, int a2, int a3, int a4, int a5, t4Vector* outDir, float* outLen)
{
    t4Vector v;
    int r = func_00328030(*(void**)((char*)self + 0x60), a1, a2, a3, a4, &v, a5);
    if (r != 0) {
        float len = wsLength(v);
        *outLen = len;
        *outDir = wsDiv(v, len);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003308C8);
#ifdef SKIP_ASM

extern "C" int func_0032CB58(void* self, void* other, void* a2, void* a3);

extern "C" int func_003308C8(void* self, void* a1, sWsDirHit* hit)
{
    if (func_0032CB58(*(void**)((char*)self + 0x60), a1, &hit->dir, hit) != 0) {
        float len = wsLengthT(hit->dir);
        hit->len = len;
        wsDivEq(hit->dir, len);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330950);
#ifdef SKIP_ASM

extern "C" int func_0032C928(void* self, void* a1, void* a2, void* a3, void* a4);

extern "C" int func_00330950(void* self, void* a1, void* a2, sWsDirHit* hit)
{
    if (func_0032C928(*(void**)((char*)self + 0x60), a1, a2, &hit->dir, hit) != 0) {
        float len = wsLengthT(hit->dir);
        hit->len = len;
        wsDivEq(hit->dir, len);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003309D8);
#ifdef SKIP_ASM
typedef int (*Test_3309D8)(void*);

struct sWsBox;
typedef sWsBox* (*GetBox_3309D8)(void*);

static inline int overlapNode_3309D8(const sWsBox* b, const sWsListNode* n)
{
    int r = 0;
    if (b->min[0] <= n->bmax[0] && b->max[0] >= n->bmin[0] &&
        b->min[1] <= n->bmax[1] && b->max[1] >= n->bmin[1] &&
        b->min[2] <= n->bmax[2] && b->max[2] >= n->bmin[2]) {
        r = 1;
    }
    return r;
}

static inline int overlapBox_3309D8(const sWsBox* b, const sWsBox* o)
{
    int r = 0;
    if (b->min[0] <= o->max[0] && b->max[0] >= o->min[0] &&
        b->min[1] <= o->max[1] && b->max[1] >= o->min[1] &&
        b->min[2] <= o->max[2] && b->max[2] >= o->min[2]) {
        r = 1;
    }
    return r;
}

extern "C" void func_003309D8(sWsListCtx* ctx, void* tree)
{
    for (sWsListNode* p = *(sWsListNode**)((char*)tree + 0x20); p != 0; p = p->next) {
        int flags = p->flags;
        if (flags & 0x20) {
            if (overlapNode_3309D8(ctx->box, p)) {
                int* cnt = ctx->count;
                int n = *cnt;
                ctx->list[n] = p;
                *cnt = n + 1;
            }
        } else if (flags & 0x40) {
            sWsVtSlot* vt = p->obj->vt;
            if (((Test_3309D8)vt[44].fn)((char*)p->obj + vt[44].delta)) {
                sWsVtSlot* vt2 = p->obj->vt;
                sWsBox* b = ((GetBox_3309D8)vt2[45].fn)((char*)p->obj + vt2[45].delta);
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

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00330BA8);
#ifdef SKIP_ASM
struct sCell_330BA8 {
    int level, x, y, z;
    void** node;                    // 0x10
};

struct sRoot_330BA8 {
    sCell_330BA8 cell[8];           // 0x00
    int fA0;
};

struct sSelf_330BA8 {
    sRoot_330BA8* root;             // 0x00
    int f04;
    int count;                      // 0x08
    void* list[0x41];               // 0x0C
    void* list2[0x41];              // 0x110
};

struct sSphNode_340A40;
extern "C" void func_00340A40(sSphNode_340A40* node, sWsListCtx* ctx);
extern "C" int func_00328360(sCell_330BA8* c, void* box);
extern "C" void helpX_330BA8(char* flag, sWsListCtx* ctx, sWsListCtx* ctx2, void* box, void** node, sCell_330BA8* cell) __asm__("func_00338920");

static inline void visit_330BA8(sRoot_330BA8* t, int k, char* flags, sWsListCtx* ctx, void* box)
{
    sCell_330BA8* c = (sCell_330BA8*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = c->node;
        char* f = &flags[k];
        int r = func_00328360(c, box);
        if (r == 0) {
            func_003309D8(ctx, n);
            if (n[0] != 0) func_00340A40((sSphNode_340A40*)n[0], ctx);
            if (n[1] != 0) func_00340A40((sSphNode_340A40*)n[1], ctx);
            if (n[2] != 0) func_00340A40((sSphNode_340A40*)n[2], ctx);
            if (n[3] != 0) func_00340A40((sSphNode_340A40*)n[3], ctx);
            if (n[4] != 0) func_00340A40((sSphNode_340A40*)n[4], ctx);
            if (n[5] != 0) func_00340A40((sSphNode_340A40*)n[5], ctx);
            if (n[6] != 0) func_00340A40((sSphNode_340A40*)n[6], ctx);
            if (n[7] != 0) func_00340A40((sSphNode_340A40*)n[7], ctx);
        } else if (r == 2) {
            helpX_330BA8(f, ctx, ctx, box, n, c);
        }
    }
}

extern "C" void func_00330BA8(sSelf_330BA8* self, void* box)
{
    sWsListCtx ctx;
    char flags[8];
    sWsListCtx* c = &ctx;
    sRoot_330BA8* t = self->root;
    self->f04 = t->fA0;
    ctx.list = (sWsListNode**)self->list;
    ctx.count = &self->count;
    *(int*)&ctx.pad08 = 0x40;
    ctx.box = (sWsBox*)box;
    self->count = 0;
    visit_330BA8(t, 0, flags, c, box);
    visit_330BA8(t, 1, flags, c, box);
    visit_330BA8(t, 2, flags, c, box);
    visit_330BA8(t, 3, flags, c, box);
    visit_330BA8(t, 4, flags, c, box);
    visit_330BA8(t, 5, flags, c, box);
    visit_330BA8(t, 6, flags, c, box);
    visit_330BA8(t, 7, flags, c, box);
    self->list[0x40] = (void*)-1;
    self->list2[0x40] = (void*)-1;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00331450);
#ifdef SKIP_ASM
struct sSelf_1450 {
    sRoot_330BA8* root;             // 0x00
    int f04;
    void* f08;
    int pad0C[0x40];
    void* f10C;                     // 0x10C
    int pad110[0x40];
    int count;                      // 0x210
    void* arr[0x80];                // 0x214
};

struct sOct_1450 {
    void* child[8];                 // 0x00
    int pad20[2];
    void** all;                     // 0x28
};

extern "C" void descRec_1450(void* self, sWsListCtx* out) __asm__("func_00340B18");
extern "C" void helpX_1450(char* flag, sWsListCtx* ctx, sWsListCtx* ctx2, void* box, void** node, sCell_330BA8* cell) __asm__("func_00339598");

// nash::Cell::descend<OverlapListCallback>
static inline void descend_1450(void** n, sWsListCtx* ctx)
{
    void** p;
    for (p = ((sOct_1450*)n)->all; p != 0; p = (void**)*p) {
        int* cnt = ctx->count;
        int idx = *cnt;
        ctx->list[idx] = (sWsListNode*)p;
        *cnt = idx + 1;
    }
    if (n[0] != 0) descRec_1450(n[0], ctx);
    if (n[1] != 0) descRec_1450(n[1], ctx);
    if (n[2] != 0) descRec_1450(n[2], ctx);
    if (n[3] != 0) descRec_1450(n[3], ctx);
    if (n[4] != 0) descRec_1450(n[4], ctx);
    if (n[5] != 0) descRec_1450(n[5], ctx);
    if (n[6] != 0) descRec_1450(n[6], ctx);
    if (n[7] != 0) descRec_1450(n[7], ctx);
}

static inline void** cellNode_1450(sCell_330BA8* c)
{
    return c->node;
}

static inline void visit_1450(sRoot_330BA8* t, int k, sWsListCtx* ctx, void* box)
{
    sCell_330BA8* c = (sCell_330BA8*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = cellNode_1450(c);
        sWsQH h;
        char* f = (char*)&h;
        int r = func_00328360(c, box);
        if (r == 0) {
            descend_1450(n, ctx);
        } else if (r == 2) {
            helpX_1450(f, ctx, ctx, box, n, c);
        }
    }
}

extern "C" void func_00331450(sSelf_1450* self, void* box)
{
    sWsListCtx ctx;
    sWsListCtx* c = &ctx;
    sRoot_330BA8* t = self->root;
    self->f04 = t->fA0;
    ctx.list = (sWsListNode**)self->arr;
    ctx.count = &self->count;
    *(int*)&ctx.pad08 = 0x200;
    ctx.box = (sWsBox*)box;
    self->count = 0;
    visit_1450(t, 0, c, box);
    visit_1450(t, 1, c, box);
    visit_1450(t, 2, c, box);
    visit_1450(t, 3, c, box);
    visit_1450(t, 4, c, box);
    visit_1450(t, 5, c, box);
    visit_1450(t, 6, c, box);
    visit_1450(t, 7, c, box);
    self->f10C = (void*)-1;
    self->f08 = (void*)-1;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00331E90);
#ifdef SKIP_ASM
struct sSelf_1E90 {
    sRoot_330BA8* root;             // 0x00
    int f04;
    int count;                      // 0x08
    void* list[0x40];               // 0x0C
    int count2;                     // 0x10C
    void* list2[0x41];              // 0x110
};

extern "C" void descendRec_1E90(void* self, sWsListCtx2* ctx) __asm__("func_00340C20");
extern "C" void helpX_1E90(char* flag, sWsListCtx2* ctx, sWsListCtx2* ctx2, void* box, void** node, sCell_330BA8* cell) __asm__("func_0033A3D8");

static inline void addPatches_1E90(sWsListCtx* cb, sWsBoundObj* first)
{
    for (sWsBoundObj* p = first; p != 0; p = p->next) {
        if (overlapBoundObj(cb->box, p)) {
            int* cnt = cb->count;
            int idx = *cnt;
            cb->list[idx] = (sWsListNode*)p;
            *cnt = idx + 1;
        }
    }
}

static inline void visit_1E90(sRoot_330BA8* t, int k, sWsListCtx2* ctx, void* box)
{
    sCell_330BA8* c = (sCell_330BA8*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = c->node;
        sWsQH h;
        char* f = (char*)&h;
        int r = func_00328360(c, box);
        if (r == 0) {
            func_003309D8(&ctx->a, n);
            addPatches_1E90(&ctx->b, *(sWsBoundObj**)((char*)n + 0x24));
            if (n[0] != 0) descendRec_1E90(n[0], ctx);
            if (n[1] != 0) descendRec_1E90(n[1], ctx);
            if (n[2] != 0) descendRec_1E90(n[2], ctx);
            if (n[3] != 0) descendRec_1E90(n[3], ctx);
            if (n[4] != 0) descendRec_1E90(n[4], ctx);
            if (n[5] != 0) descendRec_1E90(n[5], ctx);
            if (n[6] != 0) descendRec_1E90(n[6], ctx);
            if (n[7] != 0) descendRec_1E90(n[7], ctx);
        } else if (r == 2) {
            helpX_1E90(f, ctx, ctx, box, n, c);
        }
    }
}

extern "C" void func_00331E90(sSelf_1E90* self, void* box)
{
    sWsListCtx2 ctx;
    sWsListCtx2* c = &ctx;
    self->f04 = self->root->fA0;
    ctx.a.list = (sWsListNode**)self->list;
    ctx.a.count = &self->count;
    ctx.b.list = (sWsListNode**)self->list2;
    ctx.b.count = &self->count2;
    *(int*)&ctx.a.pad08 = 0x40;
    *(int*)&ctx.b.pad08 = 0x40;
    ctx.a.box = (sWsBox*)box;
    ctx.b.box = (sWsBox*)box;
    self->count = 0;
    sWsListCtx* c2 = &ctx.b;
    *c2->count = 0;
    sRoot_330BA8* t = self->root;
    visit_1E90(t, 0, c, box);
    visit_1E90(t, 1, c, box);
    visit_1E90(t, 2, c, box);
    visit_1E90(t, 3, c, box);
    visit_1E90(t, 4, c, box);
    visit_1E90(t, 5, c, box);
    visit_1E90(t, 6, c, box);
    visit_1E90(t, 7, c, box);
    self->list2[0x40] = (void*)-1;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00332DB8);
#ifdef SKIP_ASM
struct sSelf_2DB8 {
    sRoot_330BA8* root;             // 0x00
    int f04;
    int count;                      // 0x08
    void* list[0x40];               // 0x0C
    int count2;                     // 0x10C
    void* list2[0x40];              // 0x110
    int count3;                     // 0x210
    void* list3[0x80];              // 0x214
};

struct sCtx2_2DB8 {
    sWsListCtx a;
    sWsListCtx b;
    sWsListCtx c;
};

extern "C" void descendRec_2DB8(void* self, sCtx2_2DB8* ctx) __asm__("func_00340DC0");
extern "C" void helpX_2DB8(char* flag, sCtx2_2DB8* ctx, sCtx2_2DB8* ctx2, void* box, void** node, sCell_330BA8* cell) __asm__("func_0033B748");

static inline void addPatches_2DB8(sWsListCtx* cb, sWsBoundObj* first)
{
    for (sWsBoundObj* p = first; p != 0; p = p->next) {
        if (overlapBoundObj(cb->box, p)) {
            int* cnt = cb->count;
            int idx = *cnt;
            cb->list[idx] = (sWsListNode*)p;
            *cnt = idx + 1;
        }
    }
}

static inline void addAll_2DB8(sWsListCtx* cb, sWsBoundObj* first)
{
    for (sWsBoundObj* p = first; p != 0; p = p->next) {
        int* cnt = cb->count;
        int idx = *cnt;
        cb->list[idx] = (sWsListNode*)p;
        *cnt = idx + 1;
    }
}

static inline void visit_2DB8(sRoot_330BA8* t, int k, sCtx2_2DB8* ctx, void* box)
{
    sCell_330BA8* c = (sCell_330BA8*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = c->node;
        sWsQH h;
        char* f = (char*)&h;
        int r = func_00328360(c, box);
        if (r == 0) {
            func_003309D8(&ctx->a, n);
            addPatches_2DB8(&ctx->b, *(sWsBoundObj**)((char*)n + 0x24));
            addAll_2DB8(&ctx->c, *(sWsBoundObj**)((char*)n + 0x28));
            if (n[0] != 0) descendRec_2DB8(n[0], ctx);
            if (n[1] != 0) descendRec_2DB8(n[1], ctx);
            if (n[2] != 0) descendRec_2DB8(n[2], ctx);
            if (n[3] != 0) descendRec_2DB8(n[3], ctx);
            if (n[4] != 0) descendRec_2DB8(n[4], ctx);
            if (n[5] != 0) descendRec_2DB8(n[5], ctx);
            if (n[6] != 0) descendRec_2DB8(n[6], ctx);
            if (n[7] != 0) descendRec_2DB8(n[7], ctx);
        } else if (r == 2) {
            helpX_2DB8(f, ctx, ctx, box, n, c);
        }
    }
}

extern "C" void func_00332DB8(sSelf_2DB8* self, void* box)
{
    sCtx2_2DB8 ctx;
    sCtx2_2DB8* c = &ctx;
    self->f04 = self->root->fA0;
    ctx.a.list = (sWsListNode**)self->list;
    ctx.a.count = &self->count;
    ctx.b.list = (sWsListNode**)self->list2;
    ctx.b.count = &self->count2;
    *(int*)&ctx.a.pad08 = 0x40;
    *(int*)&ctx.b.pad08 = 0x40;
    ctx.a.box = (sWsBox*)box;
    ctx.b.box = (sWsBox*)box;
    self->count = 0;
    sWsListCtx* c2 = &ctx.b;
    *c2->count = 0;
    ctx.c.list = (sWsListNode**)self->list3;
    ctx.c.count = &self->count3;
    *(int*)&ctx.c.pad08 = 0x200;
    ctx.c.box = (sWsBox*)box;
    sWsListCtx* c3 = &ctx.c;
    *c3->count = 0;
    sRoot_330BA8* t = self->root;
    visit_2DB8(t, 0, c, box);
    visit_2DB8(t, 1, c, box);
    visit_2DB8(t, 2, c, box);
    visit_2DB8(t, 3, c, box);
    visit_2DB8(t, 4, c, box);
    visit_2DB8(t, 5, c, box);
    visit_2DB8(t, 6, c, box);
    visit_2DB8(t, 7, c, box);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00333EF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.


struct sWsBox;
typedef int (*Test_333EF8)(void*);
typedef sWsBox* (*GetBox_333EF8)(void*);

struct sOwner_333EF8 {
    char pad00[0xA4];
    void* cache;
};

struct sTree_333EF8 {
    sOwner_333EF8* owner;           // 0x0
    int pad04;
    unsigned int count;             // 0x8
    sWsListNode* items[0x40];      // 0xC
    unsigned int ntris;             // 0x10C
    sWsTriObj* tris[1];        // 0x110
};

struct t4Vector;
struct sWsRayHit;

static inline void reset_333EF8(sWsTriHit* h)
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

extern "C" int func_00333EF8(void* vself, void* vq, sWsRayHit* vhits, int cap, int arg)
{
    sTree_333EF8* self = (sTree_333EF8*)vself;
    sWsQueryBox* q = (sWsQueryBox*)vq;
    sWsTriHit* hits = (sWsTriHit*)vhits;
    int n = 0;
    for (unsigned int i = 0; i < self->ntris; i++) {
        sWsTriObj* obj = self->tris[i];
        if ((obj->flags & 0x41) != 0x41) {
            continue;
        }
        if (!overlapTri(q, obj)) {
            continue;
        }
        t4Vector uv;
        t4Vector pos;
        t4Vector nrm;
        void* node;
        float dist;
        func_003279D0(self->owner->cache, obj, &node);
        if (!func_0032B6E0(q, obj, node, (t4Vector*)&pos, (t4Vector*)&nrm, &dist, (t4Vector*)&uv, arg)) {
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
        sWsListNode* node = self->items[j];
        if (node->active == 0) {
            continue;
        }
        int flags = node->flags;
        if (flags & 0x20) {
            if (overlapNode(q, node)) {
                n += func_00334888(q, node, (char*)hits + n * 0x80, cap - n, 2);
            }
        } else if (flags & 0x40) {
            if (node->obj == 0) {
                continue;
            }
            sWsVtSlot* vt = node->obj->vt;
            if (((Test_333EF8)vt[44].fn)((char*)node->obj + vt[44].delta)) {
                sWsVtSlot* vt2 = node->obj->vt;
                sWsBox* b = ((GetBox_333EF8)vt2[45].fn)((char*)node->obj + vt2[45].delta);
                if (overlapBox(q, b)) {
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

extern "C" int func_00333EF8(void* self, void* q, sWsRayHit* hits, int max, int a4);

extern "C" float func_003342D0(void* self, char* q, sWsRayHit* out, int a3)
{
    sWsRayHit hits[64];
    int n = func_00333EF8(self, q, hits, 0x40, a3);
    if (n == 0) {
        return -1.0f;
    }
    int best = 0;
    sWsVtF* vt = *(sWsVtF**)(q + 0x50);
    float ref = vt[3].fn(q + vt[3].delta);
    float bestDiff = absf(hits[0].dist - ref);
    for (int i = 1; i < n; i++) {
        float d = absf(hits[i].dist - ref);
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetterHit(&hits[i], &hits[best])) {
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
struct sWsBox;
typedef int (*Test_334458)(void*);
typedef sWsBox* (*GetBox_334458)(void*);

struct sList_334458 {
    int pad00[2];
    unsigned int count;
    sWsListNode* items[1];
};


extern "C" int func_00334458(sList_334458* self, sWsQueryBox* q, char* buf, int cap, int full)
{
    int mode = 1;
    if (full) mode = 2;
    int n = 0;
    for (unsigned int i = 0; i < self->count; i++) {
        sWsListNode* node = self->items[i];
        int flags = node->flags;
        if (flags & 0x20) {
            if (overlapNode(q, node)) {
                n += func_00334888(q, node, buf + n * 0x80, cap - n, mode);
            }
        } else if (flags & 0x40) {
            sWsVtSlot* vt = node->obj->vt;
            if (((Test_334458)vt[44].fn)((char*)node->obj + vt[44].delta)) {
                sWsVtSlot* vt2 = node->obj->vt;
                sWsBox* b = ((GetBox_334458)vt2[45].fn)((char*)node->obj + vt2[45].delta);
                if (overlapBox(q, b)) {
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
extern "C" void func_0035C698(void* a0, sWsBoxV* box, sWsBoxV* box2, t4Vector* pos, int mask, int* cnt, float* dist, int a7);
extern "C" void func_00348290(void* a0, sWsBoxV* box, sWsBoxV* box2, t4Vector* pos, int mask, int* cnt, float* dist, int a7);
extern "C" void func_00335128(void* obj, sWsBoxV* box, t4Vector* pos, int* cnt, float* dist, int a5);

// PORT: PS2-only VU0 inline asm (in-place vector subtract).
static inline void wsSubEq_334680(t4Vector& a, const t4Vector& b)
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
static inline void wsAddEq_334680(t4Vector& a, const t4Vector& b)
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

extern "C" int func_00334680(char* self, t4Vector* pos, int a2, int mask, float r)
{
    sWsBoxV box;
    t4Vector ext;
    int cnt;
    float dist;
    cnt = 0;
    dist = 0.0f;
    box.min = *pos;
    box.max = *pos;
    ext.x = r;
    ext.y = r;
    ext.z = r;
    ext.w = 0.0f;
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


struct sCtx_335960 {
    sWsQueryBox* q;
    sWsTriHit* hits;
    int cap;
    int* count;
    int arg;
    void* cache;
};


static inline void reset_335960(sWsTriHit* h)
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
    sWsTriObj* obj = (sWsTriObj*)vobj;
    t4Vector pos;
    t4Vector nrm;
    t4Vector uv;
    void* node;
    float dist;
    if ((obj->flags & 0x41) != 0x41) return;
    if (!overlapTri(ctx->q, obj)) return;
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
struct sWsBox;
typedef int (*Test_335B90)(void*);
typedef sWsBox* (*GetBox_335B90)(void*);

struct sCtx_335B90 {
    sWsQueryBox* q;
    char* buf;
    int cap;
    int* count;
};


static inline void collect_335B90(sCtx_335B90* ctx, sWsListNode* node)
{
    int n = *ctx->count;
    *ctx->count += func_00334888(ctx->q, node, ctx->buf + n * 0x80, ctx->cap - n, 2);
}

extern "C" void func_00335B90(void* vctx, void* vnode)
{
    sCtx_335B90* ctx = (sCtx_335B90*)vctx;
    sWsListNode* node = (sWsListNode*)vnode;
    if (node->active == 0) return;
    int flags = node->flags;
    if (flags & 0x20) {
        if (overlapNode(ctx->q, node)) {
            collect_335B90(ctx, node);
        }
    } else if (flags & 0x40) {
        if (node->obj == 0) return;
        sWsVtSlot* vt = node->obj->vt;
        if (((Test_335B90)vt[44].fn)((char*)node->obj + vt[44].delta)) {
            sWsVtSlot* vt2 = node->obj->vt;
            sWsBox* b = ((GetBox_335B90)vt2[45].fn)((char*)node->obj + vt2[45].delta);
            if (overlapBoxB(ctx->q, b)) {
                collect_335B90(ctx, node);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00335D78);
#ifdef SKIP_ASM

struct sCb_5D78 {
    void* q;                        // 0x00
    int f04;
    int f08;
    int* result;                    // 0x0C
    int f10;
    int f14;
};

struct sSelf_5D78 {
    sCell_330BA8 cell[8];           // 0x00
    char pad_A0[4];
    int fA4;
};

extern "C" void helpX_5D78(char* flag, sCb_5D78* cb, sCb_5D78* cb2, sWsBoxV* box, void** node, sCell_330BA8* cell) __asm__("func_0033CCF8");

// nash::Cell::descend<TerrainCallback>
static inline void descend_5D78(void** n, sCb_5D78* cb)
{
    sWsOctNode2* o = (sWsOctNode2*)n;
    void** p;
    for (p = o->listA; p != 0; p = (void**)*p) {
        func_00335960(cb, p);
    }
    for (p = o->listB; p != 0; p = (void**)*p) {
        func_00335B90(cb, p);
    }
    if (n[0] != 0) func_00340FA0(n[0], cb);
    if (n[1] != 0) func_00340FA0(n[1], cb);
    if (n[2] != 0) func_00340FA0(n[2], cb);
    if (n[3] != 0) func_00340FA0(n[3], cb);
    if (n[4] != 0) func_00340FA0(n[4], cb);
    if (n[5] != 0) func_00340FA0(n[5], cb);
    if (n[6] != 0) func_00340FA0(n[6], cb);
    if (n[7] != 0) func_00340FA0(n[7], cb);
}

static inline void visit_5D78(sSelf_5D78* t, int k, sCb_5D78* cb, sWsBoxV* box)
{
    sCell_330BA8* c = (sCell_330BA8*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = c->node;
        sWsQH h;
        char* f = (char*)&h;
        int r = func_00328360(c, box);
        if (r == 0) {
            descend_5D78(n, cb);
        } else if (r == 2) {
            helpX_5D78(f, cb, cb, box, n, c);
        }
    }
}

extern "C" int query_5D78(sSelf_5D78* self, char* q, int p3, int p4, int p5) __asm__("func_00335D78");
extern "C" int query_5D78(sSelf_5D78* self, char* q, int p3, int p4, int p5)
{
    sCb_5D78 cb;
    sWsBoxV box;
    int result;
    sCb_5D78* pcb = &cb;
    cb.q = q;
    cb.f04 = p3;
    cb.f08 = p4;
    cb.result = &result;
    cb.f10 = p5;
    cb.f14 = self->fA4;
    box.min = *(t4Vector*)(q + 0x30);
    box.max = *(t4Vector*)(q + 0x20);
    result = 0;
    visit_5D78(self, 0, pcb, &box);
    visit_5D78(self, 1, pcb, &box);
    visit_5D78(self, 2, pcb, &box);
    visit_5D78(self, 3, pcb, &box);
    visit_5D78(self, 4, pcb, &box);
    visit_5D78(self, 5, pcb, &box);
    visit_5D78(self, 6, pcb, &box);
    visit_5D78(self, 7, pcb, &box);
    return result;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/worldsphtree", func_00336850);
#ifdef SKIP_ASM

extern "C" int func_00335D78(void* self, void* q, sWsRayHit* hits, int max, int a4);

extern "C" float func_00336850(void* self, char* q, sWsRayHit* out, int a3)
{
    sWsRayHit hits[64];
    int n = func_00335D78(self, q, hits, 0x40, a3);
    if (n == 0) {
        return -1.0f;
    }
    int best = 0;
    sWsVtF* vt = *(sWsVtF**)(q + 0x50);
    float ref = vt[3].fn(q + vt[3].delta);
    float bestDiff = absf(hits[0].dist - ref);
    for (int i = 1; i < n; i++) {
        float d = absf(hits[i].dist - ref);
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetterHit(&hits[i], &hits[best])) {
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

struct sHit_003369D8 {
    t4Vector p;          // 0x00
    t4Vector n;          // 0x10
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

extern "C" void* func_0032E100(void* seg, const t4Vector& a, const t4Vector& b, int n, float r);
struct sCtx_369D8 {
    float* pos;             // 0x0
    char flags[8];          // 0x4
};

struct sTrav_369D8 {
    int count;              // 0x0
    sCtx_369D8 ctx;         // 0x4
};

extern "C" void func_0033DBE8(char* flag, sQuery_369D8* q, sQuery_369D8* q2, sCtx_369D8* ctx, void* node, sCell_369D8* cell);

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

extern "C" int func_003369D8(sCell_369D8* self, float* pos, t4Vector* outP, t4Vector* outN)
{
    char seg[0xB0];
    float lo = pos[2] - 100000.0f;
    float hi = pos[2] + 100000.0f;
    float t = clamp_003369D8((pos[2] + 20.0f - lo) / (hi - lo), 0.0f, 1.0f);
    {
        t4Vector a;
        a.x = pos[0];
        a.y = pos[1];
        a.z = lo;
        a.w = 1.0f;
        t4Vector b;
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
    float bestDiff = absf(hits[0].p.z - ref);
    for (int i = 1; i < tr.count; i++) {
        float d = absf((hits + i)->p.z - ref);
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
struct sWsBox;
typedef int (*Test_336D40)(void*);
typedef sWsBox* (*GetBox_336D40)(void*);

struct sCtx_336D40 {
    sWsQueryBox* q;
    char* buf;
    int cap;
    int* count;
    int full;
};


static inline void collect_336D40(sCtx_336D40* ctx, sWsListNode* node, int mode)
{
    int n = *ctx->count;
    *ctx->count += func_00334888(ctx->q, node, ctx->buf + n * 0x80, ctx->cap - n, mode);
}

extern "C" void func_00336D40(void* vctx, void* vnode)
{
    sCtx_336D40* ctx = (sCtx_336D40*)vctx;
    sWsListNode* node = (sWsListNode*)vnode;
    int mode = ctx->full ? 3 : 1;
    int flags = node->flags;
    if (flags & 0x20) {
        if (overlapNode(ctx->q, node)) {
            collect_336D40(ctx, node, mode);
        }
    } else if (flags & 0x40) {
        sWsVtSlot* vt = node->obj->vt;
        if (((Test_336D40)vt[44].fn)((char*)node->obj + vt[44].delta)) {
            sWsVtSlot* vt2 = node->obj->vt;
            sWsBox* b = ((GetBox_336D40)vt2[45].fn)((char*)node->obj + vt2[45].delta);
            if (overlapBoxB(ctx->q, b)) {
                collect_336D40(ctx, node, mode);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00336F30);
#ifdef SKIP_ASM

struct sCb_6F30 {
    void* q;                        // 0x00
    int f04;
    int f08;
    int* result;                    // 0x0C
    int f10;
};

struct sSelf_6F30 {
    sCell_330BA8 cell[8];           // 0x00
};

extern "C" void helpX_6F30(char* flag, sCb_6F30* cb, sCb_6F30* cb2, sWsBoxV* box, void** node, sCell_330BA8* cell) __asm__("func_0033DFD8");

// nash::Cell::descend<StaticObjectCallback>
static inline void descend_6F30(void** n, sCb_6F30* cb)
{
    sWsOctNode* o = (sWsOctNode*)n;
    void** p;
    for (p = o->list; p != 0; p = (void**)*p) {
        func_00336D40(cb, p);
    }
    if (n[0] != 0) func_003410C0(n[0], cb);
    if (n[1] != 0) func_003410C0(n[1], cb);
    if (n[2] != 0) func_003410C0(n[2], cb);
    if (n[3] != 0) func_003410C0(n[3], cb);
    if (n[4] != 0) func_003410C0(n[4], cb);
    if (n[5] != 0) func_003410C0(n[5], cb);
    if (n[6] != 0) func_003410C0(n[6], cb);
    if (n[7] != 0) func_003410C0(n[7], cb);
}

static inline void visit_6F30(sSelf_6F30* t, int k, sCb_6F30* cb, sWsBoxV* box)
{
    sCell_330BA8* c = (sCell_330BA8*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = c->node;
        sWsQH h;
        char* f = (char*)&h;
        int r = func_00328360(c, box);
        if (r == 0) {
            descend_6F30(n, cb);
        } else if (r == 2) {
            helpX_6F30(f, cb, cb, box, n, c);
        }
    }
}

extern "C" int query_6F30(sSelf_6F30* self, char* q, int p3, int p4, int p5) __asm__("func_00336F30");
extern "C" int query_6F30(sSelf_6F30* self, char* q, int p3, int p4, int p5)
{
    sCb_6F30 cb;
    sWsBoxV box;
    int result;
    sCb_6F30* pcb = &cb;
    cb.q = q;
    cb.f04 = p3;
    cb.f08 = p4;
    cb.result = &result;
    cb.f10 = p5;
    box.min = *(t4Vector*)(q + 0x30);
    box.max = *(t4Vector*)(q + 0x20);
    result = 0;
    visit_6F30(self, 0, pcb, &box);
    visit_6F30(self, 1, pcb, &box);
    visit_6F30(self, 2, pcb, &box);
    visit_6F30(self, 3, pcb, &box);
    visit_6F30(self, 4, pcb, &box);
    visit_6F30(self, 5, pcb, &box);
    visit_6F30(self, 6, pcb, &box);
    visit_6F30(self, 7, pcb, &box);
    return result;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/worldsphtree", func_003378C0);
#ifdef SKIP_ASM

extern "C" int func_00336F30(void* self, void* q, sWsRayHit* hits, int max, int a4);

extern "C" float func_003378C0(void* self, char* q, sWsRayHit* out, int a3)
{
    sWsRayHit hits[128];
    int n = func_00336F30(self, q, hits, 0x80, a3);
    if (n == 0) {
        return -1.0f;
    }
    int best = 0;
    sWsVtF* vt = *(sWsVtF**)(q + 0x50);
    float ref = vt[3].fn(q + vt[3].delta);
    float bestDiff = absf(hits[0].dist - ref);
    for (int i = 1; i < n; i++) {
        float d = absf(hits[i].dist - ref);
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetterHit(&hits[i], &hits[best])) {
                best = i;
            }
        }
    }
    *out = hits[best];
    return out->dist;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00337A48);
#ifdef SKIP_ASM
struct sOct_7A48 {
    void* child[8];                 // 0x00
    void* pad20[2];
    void** list;                    // 0x28
};

struct sCb_7A48 {
    t4Vector* pos;                   // 0x00
    int a2;
    int mask;
    int* cnt;
    float* dist;
    sWsBoxV* box;
};

extern "C" void descendRec_7A48(void* self, sCb_7A48* cb) __asm__("func_003411B8");
extern "C" void helpX_7A48(char* flag, sCb_7A48* cb, sCb_7A48* cb2, sWsBoxV* box, void** node, sCell_330BA8* cell) __asm__("func_0033ED60");

static inline void visit_7A48(sSelf_6F30* t, int k, sCb_7A48* cb, sWsBoxV* box)
{
    sCell_330BA8* c = (sCell_330BA8*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = c->node;
        sWsQH h;
        char* f = (char*)&h;
        int r = func_00328360(c, box);
        if (r == 0) {
            for (sWsListNode* o = *(sWsListNode**)((char*)n + 0x28); o != 0; o = o->next) {
                int type = o->flags;
                if (type == 2) {
                    func_0035C698(o->obj, cb->box, cb->box, cb->pos, cb->mask, cb->cnt, cb->dist, cb->a2);
                } else if (type == 3) {
                    func_00348290(o->obj, cb->box, cb->box, cb->pos, cb->mask, cb->cnt, cb->dist, cb->a2);
                } else if (type == 1) {
                    if (*(int*)(*(char**)((char*)o + 0x68) + 0x1C) & cb->mask) {
                        func_00335128(o, cb->box, cb->pos, cb->cnt, cb->dist, cb->a2);
                    }
                }
            }
            if (n[0] != 0) descendRec_7A48(n[0], cb);
            if (n[1] != 0) descendRec_7A48(n[1], cb);
            if (n[2] != 0) descendRec_7A48(n[2], cb);
            if (n[3] != 0) descendRec_7A48(n[3], cb);
            if (n[4] != 0) descendRec_7A48(n[4], cb);
            if (n[5] != 0) descendRec_7A48(n[5], cb);
            if (n[6] != 0) descendRec_7A48(n[6], cb);
            if (n[7] != 0) descendRec_7A48(n[7], cb);
        } else if (r == 2) {
            helpX_7A48(f, cb, cb, box, n, c);
        }
    }
}

extern "C" int func_00337A48(sSelf_6F30* self, t4Vector* pos, int a2, int mask, float r)
{
    sWsBoxV box;
    t4Vector ext;
    int cnt;
    float dist;
    sCb_7A48 cb;
    sWsBoxV* pbox = &box;
    box.min = *pos;
    box.max = *pos;
    ext.x = r;
    ext.y = r;
    ext.z = r;
    ext.w = 0.0f;
    wsSubEq_334680(box.min, ext);
    wsAddEq_334680(box.max, ext);
    cb.pos = pos;
    cb.a2 = a2;
    cb.mask = mask;
    cb.cnt = &cnt;
    cb.dist = &dist;
    cb.box = &box;
    dist = 0.0f;
    cnt = 0;
    visit_7A48(self, 0, &cb, pbox);
    visit_7A48(self, 1, &cb, pbox);
    visit_7A48(self, 2, &cb, pbox);
    visit_7A48(self, 3, &cb, pbox);
    visit_7A48(self, 4, &cb, pbox);
    visit_7A48(self, 5, &cb, pbox);
    visit_7A48(self, 6, &cb, pbox);
    visit_7A48(self, 7, &cb, pbox);
    return cnt;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003388E0);
#ifdef SKIP_ASM
extern "C" void* func_003388E0(void* self, ...)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00338920);
#ifdef SKIP_ASM
struct sSphNode_340A40;

extern "C" void func_00340A40(sSphNode_340A40* node, sWsListCtx* ctx);

// nash::Cell::descend<OverlapInstancesCallback>, one level inlined
static inline void descend_8920(void** n, sWsListCtx* cb)
{
    func_003309D8(cb, n);
    if (n[0] != 0) func_00340A40((sSphNode_340A40*)n[0], cb);
    if (n[1] != 0) func_00340A40((sSphNode_340A40*)n[1], cb);
    if (n[2] != 0) func_00340A40((sSphNode_340A40*)n[2], cb);
    if (n[3] != 0) func_00340A40((sSphNode_340A40*)n[3], cb);
    if (n[4] != 0) func_00340A40((sSphNode_340A40*)n[4], cb);
    if (n[5] != 0) func_00340A40((sSphNode_340A40*)n[5], cb);
    if (n[6] != 0) func_00340A40((sSphNode_340A40*)n[6], cb);
    if (n[7] != 0) func_00340A40((sSphNode_340A40*)n[7], cb);
}

extern "C" void func_00338920(char* self, sWsListCtx* cb, sWsListCtx* cb2, float* box, void** node, sWsCell* cell)
{
    func_003309D8(cb, node);
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sWsCell k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_8920(c, cb2);
                    else func_00338920(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif
//100%
INCLUDE_ASM("intersect/worldsphtree", func_00339598);
#ifdef SKIP_ASM

struct sOct_9598 {
    void* child[8];                 // 0x00
    int pad20[2];
    void** list;                    // 0x28
};
extern "C" void descendRec_9598(void* self, sWsCollect* out) __asm__("func_00340B18");

// nash::Cell::descend<OverlapListCallback>
static inline void descend_9598(void** n, sWsCollect* cb)
{
    sOct_9598* o = (sOct_9598*)n;
    void** p;
    for (p = o->list; p != 0; p = (void**)*p) {
        cb->arr[(*cb->count)++] = p;
    }
    if (n[0] != 0) descendRec_9598(n[0], cb);
    if (n[1] != 0) descendRec_9598(n[1], cb);
    if (n[2] != 0) descendRec_9598(n[2], cb);
    if (n[3] != 0) descendRec_9598(n[3], cb);
    if (n[4] != 0) descendRec_9598(n[4], cb);
    if (n[5] != 0) descendRec_9598(n[5], cb);
    if (n[6] != 0) descendRec_9598(n[6], cb);
    if (n[7] != 0) descendRec_9598(n[7], cb);
}

extern "C" void func_00339598(char* self, sWsCollect* cb, sWsCollect* cb2, float* box, void** node, sWsCell* cell)
{
    {
        void** p;
        sOct_9598* o = (sOct_9598*)node;
        for (p = o->list; p != 0; p = (void**)*p) {
            cb->arr[(*cb->count)++] = p;
        }
    }
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sWsCell k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_9598(c, cb2);
                    else func_00339598(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_0033A3D8);
#ifdef SKIP_ASM

struct sOct_A3D8 {
    void* child[8];                 // 0x00
    int pad20;
    void* objs;                     // 0x24
};

extern "C" void descRec_A3D8(void* self, sWsListCtx2* cb) __asm__("func_00340C20");

static inline void gather_A3D8(sWsBoundObj* p, sWsListCtx2* cb)
{
    sWsListCtx* q = &cb->b;
    for (; p != 0; p = p->next) {
        const sWsBox* bx = q->box;
        int hit = 0;
        if (bx->min[0] <= p->bmax[0] && bx->max[0] >= p->bmin[0] &&
            bx->min[1] <= p->bmax[1] && bx->max[1] >= p->bmin[1] &&
            bx->min[2] <= p->bmax[2] && bx->max[2] >= p->bmin[2]) {
            hit = 1;
        }
        if (hit) {
            int* cnt = q->count;
            int n = *cnt;
            q->list[n] = (sWsListNode*)p;
            *cnt = n + 1;
        }
    }
}

// nash::Cell::descend<OverlapBoxCallback>
static inline void descend_A3D8(void** n, sWsListCtx2* cb2)
{
    func_003309D8(&cb2->a, n);
    gather_A3D8((sWsBoundObj*)((sOct_A3D8*)n)->objs, cb2);
    if (n[0] != 0) descRec_A3D8(n[0], cb2);
    if (n[1] != 0) descRec_A3D8(n[1], cb2);
    if (n[2] != 0) descRec_A3D8(n[2], cb2);
    if (n[3] != 0) descRec_A3D8(n[3], cb2);
    if (n[4] != 0) descRec_A3D8(n[4], cb2);
    if (n[5] != 0) descRec_A3D8(n[5], cb2);
    if (n[6] != 0) descRec_A3D8(n[6], cb2);
    if (n[7] != 0) descRec_A3D8(n[7], cb2);
}

extern "C" void func_0033A3D8(char* self, sWsListCtx2* cb, sWsListCtx2* cb2, float* box, void** node, sWsCell* cell)
{
    func_003309D8(&cb->a, node);
    gather_A3D8((sWsBoundObj*)((sOct_A3D8*)node)->objs, cb);
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sWsCell k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_A3D8(c, cb2);
                    else func_0033A3D8(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_0033B748);
#ifdef SKIP_ASM

struct sOct_B748 {
    void* child[8];                 // 0x00
    int pad20;
    void* objs;                     // 0x24
    void** all;                     // 0x28
};

struct sSub_B748 {
    void** list;
    int* count;
};

struct sCb_B748 {
    sWsListCtx a;
    sWsListCtx b;                  // 0x10
    sSub_B748 c;                    // 0x20
};

extern "C" void descRec_B748(void* self, sCb_B748* cb) __asm__("func_00340DC0");

static inline void gather_B748(sWsBoundObj* p, sCb_B748* cb)
{
    sWsListCtx* q = &cb->b;
    for (; p != 0; p = p->next) {
        const sWsBox* bx = q->box;
        int hit = 0;
        if (bx->min[0] <= p->bmax[0] && bx->max[0] >= p->bmin[0] &&
            bx->min[1] <= p->bmax[1] && bx->max[1] >= p->bmin[1] &&
            bx->min[2] <= p->bmax[2] && bx->max[2] >= p->bmin[2]) {
            hit = 1;
        }
        if (hit) {
            int* cnt = q->count;
            int n = *cnt;
            q->list[n] = (sWsListNode*)p;
            *cnt = n + 1;
        }
    }
}

static inline void gatherAll_B748(void** p, sCb_B748* cb)
{
    sSub_B748* s = &cb->c;
    for (; p != 0; p = (void**)*p) {
        int* cnt = s->count;
        int n = *cnt;
        s->list[n] = p;
        *cnt = n + 1;
    }
}

// nash::Cell::descend<OverlapAllCallback>
static inline void descend_B748(void** n, sCb_B748* cb2)
{
    func_003309D8(&cb2->a, n);
    gather_B748((sWsBoundObj*)((sOct_B748*)n)->objs, cb2);
    gatherAll_B748(((sOct_B748*)n)->all, cb2);
    if (n[0] != 0) descRec_B748(n[0], cb2);
    if (n[1] != 0) descRec_B748(n[1], cb2);
    if (n[2] != 0) descRec_B748(n[2], cb2);
    if (n[3] != 0) descRec_B748(n[3], cb2);
    if (n[4] != 0) descRec_B748(n[4], cb2);
    if (n[5] != 0) descRec_B748(n[5], cb2);
    if (n[6] != 0) descRec_B748(n[6], cb2);
    if (n[7] != 0) descRec_B748(n[7], cb2);
}

extern "C" void func_0033B748(char* self, sCb_B748* cb, sCb_B748* cb2, float* box, void** node, sWsCell* cell)
{
    func_003309D8(&cb->a, node);
    gather_B748((sWsBoundObj*)((sOct_B748*)node)->objs, cb);
    gatherAll_B748(((sOct_B748*)node)->all, cb);
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sWsCell k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_B748(c, cb2);
                    else func_0033B748(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_0033CCF8);
#ifdef SKIP_ASM


// nash::Cell::descend<TerrainCallback>
static inline void descend_CCF8(void** n, void* cb)
{
    sWsOctNode2* o = (sWsOctNode2*)n;
    void** p;
    for (p = o->listA; p != 0; p = (void**)*p) {
        func_00335960(cb, p);
    }
    for (p = o->listB; p != 0; p = (void**)*p) {
        func_00335B90(cb, p);
    }
    if (n[0] != 0) func_00340FA0(n[0], cb);
    if (n[1] != 0) func_00340FA0(n[1], cb);
    if (n[2] != 0) func_00340FA0(n[2], cb);
    if (n[3] != 0) func_00340FA0(n[3], cb);
    if (n[4] != 0) func_00340FA0(n[4], cb);
    if (n[5] != 0) func_00340FA0(n[5], cb);
    if (n[6] != 0) func_00340FA0(n[6], cb);
    if (n[7] != 0) func_00340FA0(n[7], cb);
}

extern "C" void func_0033CCF8(char* self, void* cb, void* cb2, float* box, void** node, sWsCell* cell)
{
    {
        void** p;
        sWsOctNode2* o = (sWsOctNode2*)node;
        for (p = o->listA; p != 0; p = (void**)*p) {
            func_00335960(cb, p);
        }
        for (p = o->listB; p != 0; p = (void**)*p) {
            func_00335B90(cb, p);
        }
    }
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sWsCell k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_CCF8(c, cb2);
                    else func_0033CCF8(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_0033DBE8);
#ifdef SKIP_ASM
struct sQuery_369D8;
struct sCtx_369D8;
struct sCell_369D8;

struct sOct_DBE8 {
    sOct_DBE8* child[8];            // 0x00
    void** listB;                   // 0x20
    void** listA;                   // 0x24
};

struct sCtx_DBE8 {
    float* pos;                     // 0x0
};

static inline int Classify_DBE8(sCtx_DBE8* ctx, sWsCell* c)
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
    sWsCell* cell = (sWsCell*)vcell;
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
        sWsCell sub;
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

//100%
INCLUDE_ASM("intersect/worldsphtree", func_0033DFD8);
#ifdef SKIP_ASM


// nash::Cell::descend<StaticObjectCallback>
static inline void descend_DFD8(void** n, void* cb)
{
    sWsOctNode* o = (sWsOctNode*)n;
    void** p;
    for (p = o->list; p != 0; p = (void**)*p) {
        func_00336D40(cb, p);
    }
    if (n[0] != 0) func_003410C0(n[0], cb);
    if (n[1] != 0) func_003410C0(n[1], cb);
    if (n[2] != 0) func_003410C0(n[2], cb);
    if (n[3] != 0) func_003410C0(n[3], cb);
    if (n[4] != 0) func_003410C0(n[4], cb);
    if (n[5] != 0) func_003410C0(n[5], cb);
    if (n[6] != 0) func_003410C0(n[6], cb);
    if (n[7] != 0) func_003410C0(n[7], cb);
}

extern "C" void func_0033DFD8(char* self, void* cb, void* cb2, float* box, void** node, sWsCell* cell)
{
    {
        void** p;
        sWsOctNode* o = (sWsOctNode*)node;
        for (p = o->list; p != 0; p = (void**)*p) {
            func_00336D40(cb, p);
        }
    }
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sWsCell k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_DFD8(c, cb2);
                    else func_0033DFD8(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_0033ED60);
#ifdef SKIP_ASM

struct sOct_ED60 {
    void* child[8];                 // 0x00
    int pad20[2];
    char* objs;                     // 0x28
};

extern "C" void descRec_ED60(void* self, sWsSphQuery* q) __asm__("func_003411B8");

static inline void dispatch_ED60(char* o, sWsSphQuery* q)
{
    for (; o != 0; o = *(char**)o) {
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
}

// nash::Cell::descend<SplineCallback>
static inline void descend_ED60(void** n, sWsSphQuery* cb2)
{
    dispatch_ED60(((sOct_ED60*)n)->objs, cb2);
    if (n[0] != 0) descRec_ED60(n[0], cb2);
    if (n[1] != 0) descRec_ED60(n[1], cb2);
    if (n[2] != 0) descRec_ED60(n[2], cb2);
    if (n[3] != 0) descRec_ED60(n[3], cb2);
    if (n[4] != 0) descRec_ED60(n[4], cb2);
    if (n[5] != 0) descRec_ED60(n[5], cb2);
    if (n[6] != 0) descRec_ED60(n[6], cb2);
    if (n[7] != 0) descRec_ED60(n[7], cb2);
}

extern "C" void func_0033ED60(char* self, sWsSphQuery* cb, sWsSphQuery* cb2, float* box, void** node, sWsCell* cell)
{
    dispatch_ED60(((sOct_ED60*)node)->objs, cb);
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sWsCell k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_ED60(c, cb2);
                    else func_0033ED60(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003400D8);
#ifdef SKIP_ASM
extern float D_004FF2C0[4];
extern float D_004FF2D0[4];
extern float D_004FF2E0[4];
extern float D_004FF2F0[4];
extern float D_004FF300[4];
extern float D_004FF310[4];
extern float D_004FF320[4];
extern float D_004FF330[4];
extern float D_004FF340[4];
extern float D_004FF350[4];
extern float D_004FF360[4];
extern float D_004FF370[4];
extern float D_004FF380[4];
extern float D_004FF390[4];
extern float D_004FF3A0[4];
extern float D_004FF3B0[4];
extern float D_004FF3C0[4];
extern float D_004FF3D0[4];
extern float D_004FF3E0[4];
extern float D_004FF3F0[4];
extern float D_004FF400[4];
extern float D_004FF410[4];
extern float D_004FF420[4];
extern float D_004FF430[4];
extern float D_004FF440[4];
extern float D_004FF450[4];
extern float D_004FF460[4];
extern float D_004FF470[4];
extern float D_004FF480[4];
extern float D_004FF490[4];
extern float D_004FF4A0[4];
extern float D_004FF4B0[4];
extern float D_004FF4C0[4];
extern float D_004FF4D0[4];
extern float D_004FF4E0[4];
extern float D_004FF4F0[4];
extern float D_004FF500[4];
extern float D_004FF510[4];
extern float D_004FF520[4];
extern float D_004FF530[4];
extern float D_004FF540[4];
extern float D_004FF550[4];
extern float D_004FF560[4];
extern float D_004FF570[4];
extern float D_004FF580[4];
extern float D_004FF590[4];
extern float D_004FF5A0[4];
extern float D_004FF5B0[4];
extern float D_004FF5C0[4];
extern float D_004FF5D0[4];
extern float D_004FF5E0[4];
extern float D_004FF5F0[4];
extern float D_004FF600[4];
extern float D_004FF610[4];
extern float D_004FF620[4];
extern float D_004FF630[4];
extern float D_004FF640[32];
void sti_003400D8(int init, int prio) __asm__("func_003400D8");
void sti_003400D8(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004FF2C0[0] = 1.0f;
        D_004FF2C0[1] = 1.0f;
        D_004FF2C0[2] = 1.0f;
        D_004FF2C0[3] = 0.5f;
        D_004FF2D0[0] = 0.4998680055141449f;
        D_004FF2D0[1] = 1.0f;
        D_004FF2D0[2] = 1.0f;
        D_004FF2D0[3] = 0.0f;
        D_004FF2E0[0] = 0.12951700389385223f;
        D_004FF2E0[1] = 1.0f;
        D_004FF2E0[2] = 1.0f;
        D_004FF2E0[3] = 0.0f;
        D_004FF2F0[0] = 0.22426900267601013f;
        D_004FF2F0[1] = 0.9402310252189636f;
        D_004FF2F0[2] = 0.5425059795379639f;
        D_004FF2F0[3] = 0.0004030000127386302f;
        D_004FF300[0] = 0.4652079939842224f;
        D_004FF300[1] = 0.32170501351356506f;
        D_004FF300[2] = 0.9943439960479736f;
        D_004FF300[3] = 0.0f;
        D_004FF310[0] = 0.17792600393295288f;
        D_004FF310[1] = 1.0f;
        D_004FF310[2] = 1.0f;
        D_004FF310[3] = 0.0f;
        D_004FF320[0] = 0.4411740005016327f;
        D_004FF320[1] = 0.41388601064682007f;
        D_004FF320[2] = 0.3211260139942169f;
        D_004FF320[3] = 0.4398239850997925f;
        D_004FF330[0] = 0.500997006893158f;
        D_004FF330[1] = 0.24849599599838257f;
        D_004FF330[2] = 1.0f;
        D_004FF330[3] = 1.0f;
        D_004FF340[0] = 0.27687299251556396f;
        D_004FF340[1] = 0.6395620107650757f;
        D_004FF340[2] = 0.13423900306224823f;
        D_004FF340[3] = 0.0f;
        D_004FF350[0] = 0.8936439752578735f;
        D_004FF350[1] = 0.5263469815254211f;
        D_004FF350[2] = 0.5051450133323669f;
        D_004FF350[3] = 0.8687300086021423f;
        D_004FF360[0] = 1.0f;
        D_004FF360[1] = 1.0f;
        D_004FF360[2] = 1.0f;
        D_004FF360[3] = 1.0f;
        D_004FF370[0] = 1.0f;
        D_004FF370[1] = 0.0f;
        D_004FF370[2] = 0.0f;
        D_004FF370[3] = 0.0f;
        D_004FF380[0] = 1.0f;
        D_004FF380[1] = 0.550000011920929f;
        D_004FF380[2] = 0.5350000262260437f;
        D_004FF380[3] = 0.550000011920929f;
        D_004FF390[0] = 1.0f;
        D_004FF390[1] = 1.0f;
        D_004FF390[2] = 1.0f;
        D_004FF390[3] = 1.0f;
        D_004FF3A0[0] = 1.0f;
        D_004FF3A0[1] = 1.0f;
        D_004FF3A0[2] = 1.0f;
        D_004FF3A0[3] = 1.0f;
        D_004FF3B0[0] = 1.0f;
        D_004FF3B0[1] = 0.0f;
        D_004FF3B0[2] = 0.0f;
        D_004FF3B0[3] = 0.0f;
        D_004FF3C0[0] = 1.0f;
        D_004FF3C0[1] = 0.0f;
        D_004FF3C0[2] = 0.0f;
        D_004FF3C0[3] = 0.0f;
        D_004FF3D0[0] = 1.0f;
        D_004FF3D0[1] = 1.0f;
        D_004FF3D0[2] = 1.0f;
        D_004FF3D0[3] = 1.0f;
        D_004FF3E0[0] = 1.0f;
        D_004FF3E0[1] = 0.5f;
        D_004FF3E0[2] = 1.0f;
        D_004FF3E0[3] = 0.5f;
        D_004FF3F0[0] = 1.0f;
        D_004FF3F0[1] = 0.5f;
        D_004FF3F0[2] = 1.0f;
        D_004FF3F0[3] = 0.5f;
        D_004FF400[0] = 1.0f;
        D_004FF400[1] = 0.5f;
        D_004FF400[2] = 1.0f;
        D_004FF400[3] = 0.5f;
        D_004FF410[0] = 1.0f;
        D_004FF410[1] = 0.7828119993209839f;
        D_004FF410[2] = 0.06171900033950806f;
        D_004FF410[3] = 0.03984399884939194f;
        D_004FF420[0] = 1.0f;
        D_004FF420[1] = 1.0f;
        D_004FF420[2] = 0.7988259792327881f;
        D_004FF420[3] = 0.0f;
        D_004FF430[0] = 0.9886710047721863f;
        D_004FF430[1] = 0.9230499863624573f;
        D_004FF430[2] = 0.34311699867248535f;
        D_004FF430[3] = 0.0f;
        D_004FF440[0] = 1.0f;
        D_004FF440[1] = 1.0f;
        D_004FF440[2] = 1.0f;
        D_004FF440[3] = 1.0f;
        D_004FF450[0] = 1.0f;
        D_004FF450[1] = 1.0f;
        D_004FF450[2] = 0.7976430058479309f;
        D_004FF450[3] = 0.0f;
        D_004FF460[0] = 1.0f;
        D_004FF460[1] = 0.9222670197486877f;
        D_004FF460[2] = 0.34179699420928955f;
        D_004FF460[3] = 0.0f;
        D_004FF470[0] = 1.0f;
        D_004FF470[1] = 0.7847639918327332f;
        D_004FF470[2] = 0.06054700165987015f;
        D_004FF470[3] = 0.04062499850988388f;
        D_004FF480[0] = 1.0f;
        D_004FF480[1] = 0.800000011920929f;
        D_004FF480[2] = 0.44999998807907104f;
        D_004FF480[3] = 1.0f;
        D_004FF490[0] = 1.0f;
        D_004FF490[1] = 0.3281260132789612f;
        D_004FF490[2] = 1.0f;
        D_004FF490[3] = 0.3539060056209564f;
        D_004FF4A0[0] = 1.0f;
        D_004FF4A0[1] = 1.0f;
        D_004FF4A0[2] = 1.0f;
        D_004FF4A0[3] = 1.0f;
        D_004FF4B0[0] = 1.0f;
        D_004FF4B0[1] = 1.0f;
        D_004FF4B0[2] = 1.0f;
        D_004FF4B0[3] = 1.0f;
        D_004FF4C0[0] = 1.0f;
        D_004FF4C0[1] = 0.8613290190696716f;
        D_004FF4C0[2] = 0.38124799728393555f;
        D_004FF4C0[3] = 0.0f;
        D_004FF4D0[0] = 1.0f;
        D_004FF4D0[1] = 1.0f;
        D_004FF4D0[2] = 1.0f;
        D_004FF4D0[3] = 1.0f;
        D_004FF4E0[0] = 1.0f;
        D_004FF4E0[1] = 0.3244380056858063f;
        D_004FF4E0[2] = 1.0f;
        D_004FF4E0[3] = 0.0f;
        D_004FF4F0[0] = 1.0f;
        D_004FF4F0[1] = 1.0f;
        D_004FF4F0[2] = 1.0f;
        D_004FF4F0[3] = 1.0f;
        D_004FF500[0] = 1.0f;
        D_004FF500[1] = 1.0f;
        D_004FF500[2] = 0.0f;
        D_004FF500[3] = 0.0f;
        D_004FF510[0] = 0.7007060050964355f;
        D_004FF510[1] = 0.0f;
        D_004FF510[2] = 0.0f;
        D_004FF510[3] = 0.0f;
        D_004FF520[0] = 1.0f;
        D_004FF520[1] = 0.7828530073165894f;
        D_004FF520[2] = 0.06140600144863129f;
        D_004FF520[3] = 0.04146299883723259f;
        D_004FF530[0] = 1.0f;
        D_004FF530[1] = 0.32487601041793823f;
        D_004FF530[2] = 1.0f;
        D_004FF530[3] = 0.35280099511146545f;
        D_004FF540[0] = 1.0f;
        D_004FF540[1] = 1.0f;
        D_004FF540[2] = 0.7977359890937805f;
        D_004FF540[3] = 0.0f;
        D_004FF550[0] = 1.0f;
        D_004FF550[1] = 0.4937489926815033f;
        D_004FF550[2] = 1.0f;
        D_004FF550[3] = 0.49179700016975403f;
        D_004FF560[0] = 1.0f;
        D_004FF560[1] = 1.0f;
        D_004FF560[2] = 1.0f;
        D_004FF560[3] = 1.0f;
        D_004FF570[0] = 1.0f;
        D_004FF570[1] = 0.800000011920929f;
        D_004FF570[2] = 1.0f;
        D_004FF570[3] = 0.800000011920929f;
        D_004FF580[0] = 1.0f;
        D_004FF580[1] = 1.0f;
        D_004FF580[2] = 0.0f;
        D_004FF580[3] = 0.0f;
        D_004FF590[0] = 1.0f;
        D_004FF590[1] = 1.0f;
        D_004FF590[2] = 0.0f;
        D_004FF590[3] = 0.0f;
        D_004FF5A0[0] = 1.0f;
        D_004FF5A0[1] = 1.0f;
        D_004FF5A0[2] = 0.0f;
        D_004FF5A0[3] = 0.0f;
        D_004FF5B0[0] = 1.0f;
        D_004FF5B0[1] = 0.3273420035839081f;
        D_004FF5B0[2] = 1.0f;
        D_004FF5B0[3] = 0.35390499234199524f;
        D_004FF5C0[0] = 1.0f;
        D_004FF5C0[1] = 1.0f;
        D_004FF5C0[2] = 0.061000000685453415f;
        D_004FF5C0[3] = 0.039000000804662704f;
        D_004FF5D0[0] = 1.0f;
        D_004FF5D0[1] = 1.0f;
        D_004FF5D0[2] = 0.7999979853630066f;
        D_004FF5D0[3] = 0.0f;
        D_004FF5E0[0] = 1.0f;
        D_004FF5E0[1] = 0.9589840173721313f;
        D_004FF5E0[2] = 0.6143789887428284f;
        D_004FF5E0[3] = 0.0f;
        D_004FF5F0[0] = 1.0f;
        D_004FF5F0[1] = 0.9285150170326233f;
        D_004FF5F0[2] = 0.3399839997291565f;
        D_004FF5F0[3] = 0.0f;
        D_004FF600[0] = 1.0f;
        D_004FF600[1] = 0.8738250136375427f;
        D_004FF600[2] = 0.24931700527668f;
        D_004FF600[3] = 0.017578000202775f;
        D_004FF610[0] = 1.0f;
        D_004FF610[1] = 0.7843739986419678f;
        D_004FF610[2] = 0.06132800132036209f;
        D_004FF610[3] = 0.03945299983024597f;
        D_004FF620[0] = 1.0f;
        D_004FF620[1] = 0.0f;
        D_004FF620[2] = 1.0f;
        D_004FF620[3] = 0.0f;
        D_004FF630[0] = 1.0f;
        D_004FF630[1] = 1.0f;
        D_004FF630[2] = 0.0f;
        D_004FF630[3] = 0.0f;
        D_004FF640[0] = -1.0f;
        D_004FF640[1] = -1.0f;
        D_004FF640[2] = -1.0f;
        D_004FF640[3] = 0.0f;
        D_004FF640[4] = -1.0f;
        D_004FF640[5] = -1.0f;
        D_004FF640[6] = 1.0f;
        D_004FF640[7] = 0.0f;
        D_004FF640[8] = -1.0f;
        D_004FF640[9] = 1.0f;
        D_004FF640[10] = -1.0f;
        D_004FF640[11] = 0.0f;
        D_004FF640[12] = -1.0f;
        D_004FF640[13] = 1.0f;
        D_004FF640[14] = 1.0f;
        D_004FF640[15] = 0.0f;
        D_004FF640[16] = 1.0f;
        D_004FF640[17] = -1.0f;
        D_004FF640[18] = -1.0f;
        D_004FF640[19] = 0.0f;
        D_004FF640[20] = 1.0f;
        D_004FF640[21] = -1.0f;
        D_004FF640[22] = 1.0f;
        D_004FF640[23] = 0.0f;
        D_004FF640[24] = 1.0f;
        D_004FF640[25] = 1.0f;
        D_004FF640[26] = -1.0f;
        D_004FF640[27] = 0.0f;
        D_004FF640[28] = 1.0f;
        D_004FF640[29] = 1.0f;
        D_004FF640[30] = 1.0f;
        D_004FF640[31] = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00340970);
#ifdef SKIP_ASM
// The July 2003 prototype names this function tAIFwdDiff::tAIFwdDiff() (an out-of-line copy of the inline ctor).
struct tAIFwdDiffElem {
    float v;
    tAIFwdDiffElem() {}
};
class tAIFwdDiff {
public:
    tAIFwdDiffElem a[10][10];
    tAIFwdDiffElem b[9][9];
    tAIFwdDiffElem c[3][3];
    tAIFwdDiff();
};

tAIFwdDiff::tAIFwdDiff()
{
}
// PORT: the compiler names this ctor __10tAIFwdDiff; expose it under the address-derived name.
__asm__(".globl func_00340970\n.type func_00340970,@function\nfunc_00340970 = __10tAIFwdDiff\n.size func_00340970,0x98\n");
#endif

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

extern "C" void func_00340A40(sSphNode_340A40* node, sWsListCtx* ctx)
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

extern "C" void func_00340B18(void* self, sWsCollect* out)
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

struct sTree_340C20 {
    sTree_340C20* child[8];
    int pad20;
    sWsBoundObj* objs;          // 0x24
};

extern "C" void func_00340C20(sTree_340C20* tree, sWsListCtx* ctx)
{
    func_003309D8(ctx, tree);
    sWsListCtx* q = (sWsListCtx*)((char*)ctx + 0x10);
    for (sWsBoundObj* p = tree->objs; p != 0; p = p->next) {
        if (overlapBoundObj(q->box, p)) {
            int* cnt = q->count;
            int n = *cnt;
            q->list[n] = (sWsListNode*)p;
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
struct sWsListCtx;
extern "C" void func_003309D8(sWsListCtx* ctx, void* tree);

struct sSub_340DC0 {
    void** list;
    int* count;
    int pad08;
    sWsBox* box;
};

struct sCtx_340DC0 {
    sSub_340DC0 nodes;
    sSub_340DC0 objs;
    sSub_340DC0 all;
};

struct sTree_340DC0 {
    sTree_340DC0* child[8];
    void* nodes;
    sWsBoundObj* objs;
    void** all;
};

static inline void add_340DC0(sSub_340DC0* s, void* p)
{
    int* cnt = s->count;
    int n = *cnt;
    s->list[n] = p;
    *cnt = n + 1;
}

extern "C" void func_00340DC0(sTree_340DC0* self, sCtx_340DC0* ctx)
{
    func_003309D8((sWsListCtx*)ctx, self);
    sSub_340DC0* s = &ctx->objs;
    for (sWsBoundObj* p = self->objs; p != 0; p = p->next) {
        if (overlapBoundObj(s->box, p)) {
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

struct sTree_3411B8 {
    sTree_3411B8* child[8];
    int pad20[2];
    char* objs;                 // 0x28
};

extern "C" void func_003411B8(sTree_3411B8* tree, sWsSphQuery* q)
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

//100%
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

extern "C" sObj_341388* func_00341388(sObj_341388* self, void* a1, int a2, void* a3, sWsSphDef* def)
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

extern "C" void* func_00341548(void* self, void* a1, void* stream)
{
    cInstanceNode_cInstanceNode(self, a1, stream);
    *(void***)((char*)self + 0xC) = D_004914E0;
    sWsVtVPI* vt = *(sWsVtVPI**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x20, 0x30);
    return self;
}
#endif

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

typedef void (*Fn0_003415D0)(void*);
typedef void (*Fn1_003415D0)(void*, void*);
typedef void (*FnI_003415D0)(void*, int);
typedef int (*Test0_003415D0)(void*);
typedef int (*Test_003415D0)(void*, int);

struct sNode_003415D0 {
    int pad00[3];
    sWsVtSlot* vt;
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
    sWsVtSlot* vt = self->vt;
    ((Fn0_003415D0)vt[49].fn)((char*)self + vt[49].delta);
    if (self->type == 1 || self->t3C <= 0) {
        for (int i = 0; i < func_002D1AF0(); i++) {
            void** obj = func_002D1B08(i);
            if (self->type == 2) {
                sWsVtSlot* ovt = (sWsVtSlot*)*obj;
                if (((Test0_003415D0)ovt[9].fn)((char*)obj + ovt[9].delta) != 0) continue;
            }
            sWsVtSlot* ovt = (sWsVtSlot*)*obj;
            if (((Test_003415D0)ovt[3].fn)((char*)obj + ovt[3].delta, self->a18) != 0) {
                hit = 1;
                if (self->f34 < 0.0f) {
                    sWsVtSlot* v = self->vt;
                    ((Fn1_003415D0)v[48].fn)((char*)self + v[48].delta, obj);
                } else {
                    sWsVtSlot* v = self->vt;
                    ((Fn1_003415D0)v[47].fn)((char*)self + v[47].delta, obj);
                }
            }
        }
    }
    sWsVtSlot* v2 = self->vt;
    ((Fn0_003415D0)v2[50].fn)((char*)self + v2[50].delta);
    if (hit == 0) {
        sWsVtSlot* v3 = self->vt;
        ((FnI_003415D0)v3[34].fn)((char*)self + v3[34].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341770);
#ifdef SKIP_ASM


extern "C" void func_00341770(void* self, cWsMover* obj)
{
    t4Vector u = vu0Scale(vu0Scale(*obj->getVelocity(), *(float*)((char*)self + 0x34) + 1.0f), func_002D1C70());
    obj->setVelocity(&u);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341818);
#ifdef SKIP_ASM

// PORT: PS2-only VU0 inline asm (v / |v|).
static inline t4Vector vu0Normalize_341818(const t4Vector& v)
{
    t4Vector r;
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


struct sParams_341818 {
    t4Vector dir;
    float speed;
    float scale;
};

struct sSph_341818 {
    char pad00[0x20];
    sParams_341818 params;
    int type;
};

static inline void push_341818(sParams_341818* p, cWsMover* obj, const t4Vector& dir, float amount)
{
    t4Vector u = vu0Scale(vu0Scale(vu0Scale(dir, amount), p->scale), func_002D1C70());
    obj->setVelocity(&u);
}

extern "C" void func_00341818(sSph_341818* self, cWsMover* obj)
{
    t4Vector vel = *obj->getVelocity();
    t4Vector dir = self->params.dir;
    if (dir.x == 0.0f && dir.y == 0.0f && dir.z == 0.0f) {
        dir = vu0Normalize_341818(vel);
    }
    float d = vu0Dot(vel, dir);
    float diff = self->params.speed - d;
    sParams_341818* p = &self->params;
    if (self->type == 2) {
        if (d >= 0.0f) {
            t4Vector u = vu0Scale(vu0Scale(vu0Scale(dir, p->speed), p->scale), func_002D1C70());
            obj->setVelocity(&u);
        }
    } else if (diff > 0.0f) {
        t4Vector u = vu0Scale(vu0Scale(vu0Scale(dir, diff), p->scale), func_002D1C70());
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

extern "C" void func_0034FE90(void* self, void* stream);

extern "C" void func_00341A50(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sWsVtVPI* vt = *(sWsVtVPI**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x20, 0x30);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341AA0);
#ifdef SKIP_ASM
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
    setRate((sWsFloat*)&self->min, def->min, v);
    setRateMax((sWsFloat*)&self->max, def->max, info);
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


extern "C" void* func_00341C80(void* self, int a1, sWsVtVPI** stream)
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
struct sWsAnimFloat;
struct sWsAnimFloat;
struct sClampFloat_1F38;
extern "C" void func_00341E48(sWsAnimFloat* s);
extern "C" void func_00341EC0(sWsAnimFloat* s);
extern "C" void func_00341F38(sClampFloat_1F38* s);

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
                func_00341EC0((sWsAnimFloat*)self);
                break;
            case 1:
                func_00341E48((sWsAnimFloat*)self);
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
    sWsVtVI* vt = *(sWsVtVI**)((char*)self + 0x3C);
    vt[0x22].fn(obj + vt[0x22].delta, 1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00341E48);
#ifdef SKIP_ASM

extern "C" void func_00341E48(sWsAnimFloat* s)
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

extern "C" void func_00341EC0(sWsAnimFloat* s)
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

void* func_0034FCC0(void*);

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

extern "C" void func_00342150(void* self, void* stream)
{
    func_0034E3D8((char*)self + 0x1C, stream);
    sWsVtVPI* vt = *(sWsVtVPI**)stream;
    vt[1].fn((char*)stream + vt[1].delta, self, 0x1C);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003421A0);
#ifdef SKIP_ASM

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

extern "C" void* func_003421A0(sSphCtl_003421A0* self, int a1, char* obj, char* def)
{
    func_0034D9B0((char*)self + 0x30, a1, 4, obj, 0);
    self->vt = D_004908F8;
    float t = 0.0f;
    char* info = *(char**)(obj + 0x80);
    if (self->inst != 0) {
        t = func_00351508(self->inst);
    }
    setRate((sWsFloat*)&self->f10, *(float*)(def + 0x20), t);
    setRateMax((sWsFloat*)&self->f14, *(float*)(def + 0x24), info);
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


extern "C" void* func_003422E8(void* self, int a1, sWsVtVPI** stream)
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
    if (maxStep < absf(step)) {
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
        if (absf(nv) > 0.1f) {
            s->vel = nv * s->bounce;
        } else {
            s->step = 0.0f;
            s->vel = 0.0f;
        }
    } else if (s->max < pos) {
        s->pos = s->max;
        if (absf(nv) > 0.1f) {
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

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342538);
#ifdef SKIP_ASM
struct sVec4_342538 {
    float x, y, z, w;
    sVec4_342538() {}
} __attribute__((aligned(16)));

typedef char* (*GetMat_342538)(void*, int);

struct sBodyTbl_342538 { char pad00[8]; char* ents; };
struct sBodyInf_342538 { char pad00[0x80]; sBodyTbl_342538* tbl; };
struct sSub_342538 { char pad00[0x18]; sBodyInf_342538* inf; };

struct sSelf_342538 {
    float sum;                      // 0x00
    char pad04[4];
    float dir;                      // 0x08
    char pad0C[0x20];
    int mask;                       // 0x2C
    char pad30[0x2C];
    sBodyInf_342538* inf;            // 0x5C
};

struct sObj_342538 {
    sVec4_342538 pos;               // 0x00
    char pad10[0x4C];
    int idx;                        // 0x5C
};

extern sVec4_342538 D_004FF150_342538[] __asm__("D_004FF150");

// PORT: PS2-only VU0 inline asm (vector length via vsqrt).
static inline float vu0Length_342538(const sVec4_342538& v)
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline void vu0Sub_342538(sVec4_342538& r, const sVec4_342538& a, const sVec4_342538& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline void vu0Scale_342538(sVec4_342538& r, const sVec4_342538& v, float s)
{
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
}

// PORT: PS2-only VU0 inline asm (matrix times vector).
static inline void vu0Xform_342538(sVec4_342538& r, const sVec4_342538& v, const char* m)
{
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
        : "r"(m), "o"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (cross product xyz).
static inline void vu0Cross_342538(sVec4_342538& r, const sVec4_342538& a, const sVec4_342538& b)
{
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_342538(const sVec4_342538& a, const sVec4_342538& b)
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

extern "C" void func_00342538(sSelf_342538* self, sObj_342538* o, sVec4_342538* p)
{
    int idx = o->idx;
    if (idx >= 0) {
        sSub_342538* sub = (sSub_342538*)((char*)self + 0x44);
        char* ents = sub->inf->tbl->ents;
        if (*(int*)(ents + idx * 16 + 8) != 0) {
            sWsVtSlot* vt = *(sWsVtSlot**)((char*)self + 0x50);
            char* m = ((GetMat_342538)vt[29].fn)((char*)sub + vt[29].delta, idx);
            char* m2 = m;
            if (vu0Length_342538(*p) > 100.0f) {
                sVec4_342538 d;
                sVec4_342538 a;
                sVec4_342538 t;
                sVec4_342538 u;
                a = *(sVec4_342538*)(m + 0x30);
                vu0Sub_342538(t, o->pos, a);
                d = t;
                if (self->dir < 0.0f) {
                    vu0Scale_342538(t, d, -1.0f);
                    a = t;
                    d = t;
                }
                if ((self->mask >> o->idx) & 1) {
                    vu0Scale_342538(t, d, -1.0f);
                    a = t;
                    d = t;
                }
                vu0Xform_342538(t, D_004FF150_342538[0], m2);
                a = t;
                vu0Cross_342538(u, d, *p);
                t = u;
                self->sum += vu0Dot_342538(a, t);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342718);
#ifdef SKIP_ASM

extern "C" void func_00342718(void* self, void* stream)
{
    func_0034E3D8((char*)self + 0x30, stream);
    sWsVtVPI* vt = *(sWsVtVPI**)stream;
    vt[1].fn((char*)stream + vt[1].delta, self, 0x30);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342768);
#ifdef SKIP_ASM
struct sSph_342768 {
    int refs;
    void** vt;
    int pad08[2];
    t4Vector pos;
    float f20;
    float f24;
    int t28;
    int t2C;
    int type;
    int pad34[3];
    int a40;
};

extern "C" void* func_00342768(sSph_342768* self, sWsSphDef* def, int a2)
{
    self->refs = 1;
    self->vt = D_00490898;
    self->a40 = a2;
    int type = def->type;
    self->type = type;
    int t = (int)(def->time * (float)*(int*)(D_004A5B64 + 0x10));
    self->t28 = t;
    t4Vector v;
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

typedef void (*ReadFn00342808)(void*, void*, int);
typedef int (*ReadIntFn00342808)(void*);


extern "C" void* func_00342808(void* self, sWsVtSlot** stream)
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
    sWsVtSlot* vt = (sWsVtSlot*)self->vt;
    ((Fn0_00342880)vt[9].fn)((char*)self + vt[9].delta);
    if (self->type == 1 || self->t2C <= 0) {
        for (int i = 0; i < func_002D1AF0(); i++) {
            void** obj = func_002D1B08(i);
            sWsVtSlot* ovt = (sWsVtSlot*)*obj;
            if (((Test_00342880)ovt[3].fn)((char*)obj + ovt[3].delta, self->a40) != 0) {
                self->refs = 1;
                if (self->f24 < 0.0f) {
                    sWsVtSlot* v = (sWsVtSlot*)self->vt;
                    ((Fn1_00342880)v[8].fn)((char*)self + v[8].delta, obj);
                } else {
                    sWsVtSlot* v = (sWsVtSlot*)self->vt;
                    ((Fn1_00342880)v[7].fn)((char*)self + v[7].delta, obj);
                }
            }
        }
    }
    sWsVtSlot* v2 = (sWsVtSlot*)self->vt;
    ((Fn0_00342880)v2[10].fn)((char*)self + v2[10].delta);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_003429E0);
#ifdef SKIP_ASM


extern "C" void func_003429E0(void* self, cWsMover* obj)
{
    t4Vector u = vu0Scale(vu0Scale(*obj->getVelocity(), *(float*)((char*)self + 0x24) + 1.0f), func_002D1C70());
    obj->setVelocity(&u);
}
#endif

//100%
INCLUDE_ASM("intersect/worldsphtree", func_00342A88);
#ifdef SKIP_ASM


static inline void setVel_342A88(cWsMover* o, t4Vector* v)
{
    o->setVelocity(v);
}

struct sPlane_342A88 {
    t4Vector n;
    float d;
    float k;
};

struct sSelf_342A88 {
    char pad[0x10];
    sPlane_342A88 plane;
};

extern "C" void func_00342A88(sSelf_342A88* self, cWsMover* obj)
{
    float d = self->plane.d - vu0Dot(*obj->getVelocity(), self->plane.n);
    if (d > 0.0f) {
        // PORT: takes the address of a temporary (g++ 2.95 accepts it).
        sPlane_342A88* pl = &self->plane;
        setVel_342A88(obj, &vu0Scale(vu0Scale(vu0Scale(pl->n, d), pl->k), func_002D1C70()));
    }
}
#endif

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

extern "C" void func_00342BA0(void* self, void* stream)
{
    func_003584B8(self, stream);
    sWsVtVPI* vt = *(sWsVtVPI**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x10, 0x30);
    sWsVtVI* vt1 = *(sWsVtVI**)stream;
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

