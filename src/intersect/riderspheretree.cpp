#include "common.h"

// R5900 128-bit GPR quadword, for functions that copy a 16-byte block via a
// single lq/sq pair instead of word-by-word.
typedef int cQuad128 __attribute__((mode(TI)));

struct cRiderSphereTree {
    char pad_0x00[0x24];
    int field_0x24;
    int field_0x28;
};

//100%
INCLUDE_ASM("intersect/riderspheretree", cRiderSphereTree_cRiderSphereTree__FP16cRiderSphereTree);
#ifdef SKIP_ASM
inline void* operator new[](unsigned int, void* p) { return p; }

struct sRiderSphere_329910 {
    float pos[4];
    sRiderSphere_329910() {}
};

cRiderSphereTree* cRiderSphereTree_cRiderSphereTree(cRiderSphereTree* self)
{
    new ((char*)self + 0x2C) sRiderSphere_329910[20];
    self->field_0x24 = -1;
    *(unsigned int*)&self->field_0x28 = 0xFFFFFFFF;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329938);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00329A28_v(void* self) __asm__("func_00329A28");

// NOTE: the array's offset is unconstrained by the target: the empty-ctor loop is deleted
// (vec_mark), leaving only the dead `li 0x13; li -1` pair. 0x30 = sSphereNode children[].
extern "C" void* func_00329938(void* self)
{
    new ((char*)self + 0x30) sRiderSphere_329910[20];
    func_00329A28_v(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329970);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00329970(void* self, int flags)
{
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329998);
#ifdef SKIP_ASM
extern "C" void func_00329998(void* self, float radius)
{
    *(unsigned int*)((char*)self + 0x28) = 0xFFFFFFFF;
    *(int*)((char*)self + 0x2C) = 1;
    *(float*)((char*)self + 0x20) = radius;
    *(float*)((char*)self + 0x40) = radius;
    *(int*)((char*)self + 0x24) = -1;
    *(int*)((char*)self + 0x44) = -1;
    *(int*)((char*)self + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_003299C8);
#ifdef SKIP_ASM
struct sSphereLeaf_99C8 {
    int type;                       // 0x00
    char pad_0x04[0x1C];
    float radius;                   // 0x20
    int user;                       // 0x24
    unsigned int parent;            // 0x28
    int count;                      // 0x2C
};

extern "C" void func_003299C8(sSphereLeaf_99C8* s, int type, int n, int* ids, float* radii,
                              int user, float radius)
{
    s->parent = 0xFFFFFFFF;
    s->count = n;
    for (int i = 0; i < s->count; i++) {
        *(int*)((char*)s + i * 0x20 + 0x44) = ids[i];
        *(float*)((char*)s + i * 0x20 + 0x40) = radii[i];
    }
    s->type = type;
    s->radius = radius;
    s->user = user;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329A28);
#ifdef SKIP_ASM
struct sVec4_9A28 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSphereNode_9A28 {
    int type;            // 0x00
    char pad_0x04[0xC];
    sVec4_9A28 center;   // 0x10
    float radius;        // 0x20
    int user;            // 0x24
    int parent;          // 0x28
    int count;           // 0x2C
    char children[1];    // 0x30
};

extern "C" void func_003E6574(void* dst, void* src, int size);

extern "C" sSphereNode_9A28* func_00329A28(sSphereNode_9A28* self, sSphereNode_9A28* src)
{
    self->type = src->type;
    self->radius = src->radius;
    self->center = src->center;
    self->user = src->user;
    self->count = src->count;
    self->parent = src->parent;
    func_003E6574(self->children, src->children, self->count << 5);
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329A90);
#ifdef SKIP_ASM
struct sSphereVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSphereChild {
    sSphereVec4 pos;
    float radius;
    int pad[3];
};

struct sSphereTreeNode {
    char pad_0x00[0x10];
    sSphereVec4 center; // 0x10
    float radius;       // 0x20
    int pad_0x24;
    int pad_0x28;
    int count;          // 0x2C
    sSphereChild children[1]; // 0x30
};

extern "C" void func_00329A90(sSphereTreeNode* s, int n, sSphereVec4* pos, float* radii,
                              sSphereVec4* center, float radius)
{
    s->count = n;
    for (int i = 0; i < s->count; i++) {
        s->children[i].pos = pos[i];
        s->children[i].radius = radii[i];
    }
    s->center = *center;
    s->radius = radius;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329AE0);
#ifdef SKIP_ASM
struct sSphereSrc_9AE0 {
    sSphereVec4 pos;
    int pad[4];
};

extern "C" void func_00329AE0(sSphereTreeNode* s)
{
    sSphereSrc_9AE0** table = (sSphereSrc_9AE0**)s;
    for (int i = 0; i < s->count; i++) {
        s->children[i].pos = (*table)[s->children[i].pad[0]].pos;
    }
    s->center = (*table)[s->pad_0x24].pos;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329B40);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
static inline void sphereVecAdd(sSphereVec4* dst, sSphereVec4* v)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(*dst)
        : "m"(*dst), "m"(*v));
}

// self->center += *v, then every child's pos += *v
extern "C" void func_00329B40(sSphereTreeNode* s, sSphereVec4* v)
{
    sphereVecAdd(&s->center, v);
    for (int i = 0; i < s->count; i++) {
        sphereVecAdd(&s->children[i].pos, v);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329B90);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4x4 matrix * vector).
static inline sSphereVec4 mtxMulVec_9B90(sSphereVec4* m, sSphereVec4* v)
{
    sSphereVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*v), "r"(m)
        : "memory");
    return r;
}

struct sScale_9B90 {
    float x, y, z, w;
    sScale_9B90(float s) { x = s; y = s; z = s; w = 1.0f; }
};

struct sProd_9B90 : sSphereVec4 {
    sProd_9B90(const sSphereVec4& a, const sScale_9B90& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
};

// PORT: callers declare the matrix as sSphereMtx*.
extern "C" void func_00329B90_impl(sSphereTreeNode* s, sSphereVec4* m, float scale) __asm__("func_00329B90");

extern "C" void func_00329B90_impl(sSphereTreeNode* s, sSphereVec4* m, float scale)
{
    sScale_9B90 sc(scale);
    s->center = sProd_9B90(mtxMulVec_9B90(m, &s->center), sc);
    s->radius = s->radius * scale;
    for (int i = 0; i < s->count; i++) {
        s->children[i].pos = sProd_9B90(mtxMulVec_9B90(m, &s->children[i].pos), sc);
        s->children[i].radius = s->children[i].radius * scale;
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329CE0);
#ifdef SKIP_ASM
struct sSphereBox_9CE0 {
    sSphereVec4 mn;
    sSphereVec4 mx;
};

// Bounding box of all child spheres, seeded with the node's own center.
extern "C" void func_00329CE0(sSphereTreeNode* self, sSphereBox_9CE0* box)
{
    box->mn = box->mx = self->center;
    for (int i = 0; i < self->count; i++) {
        sSphereChild* c = &self->children[i];
        float r = c->radius;
        float v;
        v = c->pos.x - r;
        if (v < box->mn.x)
            box->mn.x = v;
        v = c->pos.y - r;
        if (v < box->mn.y)
            box->mn.y = v;
        v = c->pos.z - r;
        if (v < box->mn.z)
            box->mn.z = v;
        v = c->pos.x + r;
        if (box->mx.x < v)
            box->mx.x = v;
        v = c->pos.y + r;
        if (box->mx.y < v)
            box->mx.y = v;
        v = c->pos.z + r;
        if (box->mx.z < v)
            box->mx.z = v;
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00329DC8);
#ifdef SKIP_ASM
struct sSphereV4_9DC8 {
    float x, y, z, w;
    sSphereV4_9DC8() {}
    sSphereV4_9DC8(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sSphereKid_9DC8 {
    sSphereV4_9DC8 pos;     // 0x00
    float radius;           // 0x10
    int pad[3];
};

struct sSphereBox_9DC8 {
    char pad_0x00[0x10];
    sSphereV4_9DC8 center;  // 0x10
    float radius;           // 0x20
    int pad_0x24;
    unsigned int mask;      // 0x28
    int count;              // 0x2C
    sSphereKid_9DC8 kids[1]; // 0x30
};

// PORT: PS2-only VU0 inline asm (a - b).
static inline sSphereV4_9DC8 Sub_9DC8(const sSphereV4_9DC8& a, const sSphereV4_9DC8& b)
{
    sSphereV4_9DC8 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sSphereV4_9DC8 Add_9DC8(const sSphereV4_9DC8& a, const sSphereV4_9DC8& b)
{
    sSphereV4_9DC8 r;
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

struct sVec4_2F650;

extern "C" void func_00329DC8(void* tree, sVec4_2F650* mnp, sVec4_2F650* mxp)
{
    sSphereBox_9DC8* node = (sSphereBox_9DC8*)tree;
    sSphereV4_9DC8* mn = (sSphereV4_9DC8*)mnp;
    sSphereV4_9DC8* mx = (sSphereV4_9DC8*)mxp;
    *mn = sSphereV4_9DC8(10000000000.0f, 10000000000.0f, 10000000000.0f, 1.0f);
    *mx = sSphereV4_9DC8(-10000000000.0f, -10000000000.0f, -10000000000.0f, 1.0f);
    if (node->mask == 0) {
        *mn = Sub_9DC8(node->center, sSphereV4_9DC8(node->radius, node->radius, node->radius, 0.0f));
        *mx = Add_9DC8(node->center, sSphereV4_9DC8(node->radius, node->radius, node->radius, 0.0f));
        return;
    }
    for (int i = 0; i < node->count; i++) {
        if (node->mask & (1 << i)) {
            sSphereV4_9DC8 r(node->kids[i].radius, node->kids[i].radius, node->kids[i].radius, 1.0f);
            sSphereV4_9DC8 t = Sub_9DC8(node->kids[i].pos, r);
            if (t.x < mn->x) mn->x = t.x;
            if (t.y < mn->y) mn->y = t.y;
            if (t.z < mn->z) mn->z = t.z;
            t = Add_9DC8(node->kids[i].pos, r);
            if (t.x > mx->x) mx->x = t.x;
            if (t.y > mx->y) mx->y = t.y;
            if (t.z > mx->z) mx->z = t.z;
        }
    }
}
#endif

INCLUDE_ASM("intersect/riderspheretree", func_00329F98);

INCLUDE_ASM("intersect/riderspheretree", func_0032A1C0);

INCLUDE_ASM("intersect/riderspheretree", func_0032AA28);

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032B2B8);
#ifdef SKIP_ASM
extern "C" int func_00329590(void* a, void* b, void* center, void* box, void* boxMin, void* boxMax, float radius);

struct sSphereHit_B2B8 {
    char pad_0x00[0x10];
    sSphereVec4 center; // 0x10
    float radius;       // 0x20
    int pad_0x24;
    unsigned int mask;  // 0x28
    int count;          // 0x2C
};

// PORT: PS2-only VU0 inline asm (v * s).
static inline sSphereVec4 Scale_B2B8(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
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

struct sSphereHit_32FAC0;

extern "C" int func_0032B2B8(void* tree, void* a, void* b, sSphereVec4* outPos, sSphereHit_32FAC0* hit)
{
    sSphereHit_B2B8* self = (sSphereHit_B2B8*)tree;
    sSphereVec4* outNormal = (sSphereVec4*)hit;
    sSphereVec4 normal;
    sSphereVec4 dir;
    float t;
    if (func_00329590(a, b, &self->center, &normal, &dir, &t, self->radius) == 0) {
        return 0;
    }
    if (self->mask == 0) {
        *outPos = Scale_B2B8(dir, t);
        *outNormal = normal;
        return 1;
    }
    float best = -1.0f;
    for (int i = 0; i < self->count; i++) {
        if (self->mask & (1 << i)) {
            if (func_00329590(a, b, &self->center, &normal, &dir, &t, self->radius) && best < t) {
                *outPos = Scale_B2B8(dir, t);
                *outNormal = normal;
                best = t;
            }
        }
    }
    return best != -1.0f;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032B460);
#ifdef SKIP_ASM
extern "C" void func_0032B460(void) {

}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032B468);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

extern "C" int func_0032B468(unsigned char* start, unsigned char* in, int len, int minRun)
{
    unsigned char* out = start;
    unsigned char* end = in + len;
    int one = 1;
    int min = 2;
    if (one < minRun) {
        min = minRun;
    }
    while (in < end) {
        unsigned char* p = in;
        int run = 0;
        int lit = 0;
        unsigned char* q;
        while (run == 0 && lit < 0x7F && p < end) {
            unsigned char c = *p;
            run = 1;
            q = p + 1;
            if (c == p[1] && q < end) {
                do {
                    do {
                        q++;
                        run++;
                    } while (c == *q && q < end && run < 0x7F);
                } while (0);
            }
            if (q == end && 1 < run) {
                run--;
                q = end - 1;
            }
            if (run < min) {
                lit += run;
                run = 0;
                p = q;
            }
        }
        if (0x7F < lit) {
            lit = 0x7F;
        }
        if (lit != 0) {
            func_003E6448(out++, -lit, 1);
            while (lit-- != 0) {
                *out++ = *in++;
            }
        }
        if (run != 0) {
            run--;
            func_003E6448(out++, run, 1);
            *out++ = *in++;
            in += run;
        }
    }
    func_003E6448(out++, 0, 1);
    return out - start;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032B620);
#ifdef SKIP_ASM
// Run-length decode (PackBits style) into dst: a negative count -n copies the next n bytes, a positive count n
// repeats the next byte n+1 times, 0 terminates. Returns the number of bytes written.
// PORT: the unit declares it later as void*(void*, void*); defined under its own name bound to the symbol.
extern "C" int func_0032B620_impl(char* dst, signed char* src) __asm__("func_0032B620");
extern "C" int func_0032B620_impl(char* dst, signed char* src)
{
    if (src == 0)
        return 0;
    char* d = dst;
    int c;
    do {
        c = *src++;
        if (c < 0) {
            int n = -c;
            do {
                *d++ = *src++;
            } while (--n);
        } else {
            int n = c + 1;
            if (c == 0)
                break;
            do {
                *d++ = *src;
            } while (--n);
            src++;
        }
    } while (c != 0);
    return d - dst;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032B6A8);
#ifdef SKIP_ASM
// VU0 microprogram entry (micro-memory address 0x6E0; resolved via undefined_syms_auto.txt)
extern char D_6E0[];

// Loads four vectors into vf10-vf13, runs the VU0 microprogram at D_6E0 and
// returns whether it left a nonzero result in vi2.
// PORT: PS2-only VU0 microprogram call (ctc2/vcallmsr/cfc2); the PC port needs a C version
// of the microprogram.
extern "C" int func_0032B6A8(sSphereVec4* a, sSphereVec4* b, sSphereVec4* c, sSphereVec4* d)
{
    int r;
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf10, 0x0(%1)\n"
        "lqc2      $vf11, 0x0(%2)\n"
        "lqc2      $vf12, 0x0(%3)\n"
        "lqc2      $vf13, 0x0(%4)\n"
        "ctc2.ni   %5, $vi27\n"
        "vnop\n"
        "vnop\n"
        "vcallmsr  $vi27\n"
        "cfc2.i    %0, $vi2\n"
        ".set pop\n"
        : "=r"(r)
        : "r"(a), "r"(b), "r"(c), "r"(d), "0"((int)D_6E0 >> 3));
    return r != 0;
}
#endif

INCLUDE_ASM("intersect/riderspheretree", func_0032B6E0);

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C0F8);
#ifdef SKIP_ASM
struct sV4_C0F8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sV4_C0F8 D_004FF120;

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vDot_C0F8(const sV4_C0F8& a, const sV4_C0F8& b)
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

struct sTriBox_C0F8 {
    float lo[3];
    float hi[3];
};

struct sTriMesh_C0F8 {
    unsigned short numTris;     // 0x0
    short pad2;
    unsigned char* indices;     // 0x4
    sTriBox_C0F8* boxes;        // 0x8
    sV4_C0F8* verts;            // 0xC
    sV4_C0F8* normals;          // 0x10
};

struct sTriHit_C0F8 {
    sV4_C0F8 pos;       // 0x00
    sV4_C0F8 nrm;       // 0x10
    sV4_C0F8 v20;       // 0x20
    sV4_C0F8 v30;       // 0x30
    float t;            // 0x40
    int type;           // 0x44
    int f48;
    int f4C;            // 0x4C
    int f50;            // 0x50
    int f54;            // 0x54
    int f58;            // 0x58
    int f5C;            // 0x5C
    int tri;            // 0x60
    int f64;            // 0x64
    int f68;            // 0x68
    int f6C;            // 0x6C
    int f70;            // 0x70
    int pad[3];
};

struct sVE_C0F8a {
    short delta;
    short index;
    int (*fn)(void*, sV4_C0F8*, sV4_C0F8*, sV4_C0F8*, sV4_C0F8*, sV4_C0F8*, sV4_C0F8*, float*);
};
struct sVE_C0F8b {
    short delta;
    short index;
    int (*fn)(void*, float*, float*);
};

struct sTriTester_C0F8 {
    char pad0[0x8];
    int useNormal;          // 0x8
    char padC[0x4];
    sV4_C0F8 dir;           // 0x10
    char pad20[0x30];
    sVE_C0F8a* vt;          // 0x50
};

extern "C" int func_0032C0F8(sTriTester_C0F8* self, sTriMesh_C0F8* mesh, int flag, sTriHit_C0F8* out)
{
    sV4_C0F8 pos;
    sV4_C0F8 hn;
    float t;
    int n = 0;
    if (mesh->numTris < 11) {
        for (int i = 0; i < mesh->numTris; i++) {
            sV4_C0F8* nrm = &mesh->normals[i];
            if (self->useNormal != 0 && vDot_C0F8(*nrm, self->dir) > 0.8f) {
                continue;
            }
                        sV4_C0F8* v = mesh->verts;
            sV4_C0F8* p0 = &v[mesh->indices[i * 3]];
            sV4_C0F8* p1 = &v[mesh->indices[i * 3 + 1]];
            sV4_C0F8* p2 = &v[mesh->indices[i * 3 + 2]];
            int r;
            if (flag != 0) {
                r = self->vt[5].fn((char*)self + self->vt[5].delta, p0, p1, p2, nrm, &pos, &hn, &t);
            } else {
                r = self->vt[4].fn((char*)self + self->vt[4].delta, p0, p1, p2, nrm, &pos, &hn, &t);
            }
            if (r == 0) {
                continue;
            }
            sTriHit_C0F8* h = &out[n];
            h->f54 = 0;
            h->type = 2;
            h->tri = -1;
            h->f50 = 0;
            h->f58 = 0;
            h->f5C = -1;
            h->f64 = -1;
            h->f4C = -1;
            h->v20 = D_004FF120;
            h->v30 = D_004FF120;
            h->f68 = 0;
            h->f6C = 0;
            h->f70 = 0;
            h->pos = pos;
            h->nrm = hn;
            h->t = t;
            h->tri = i;
            h->f54 = 0;
            n++;
        }
    } else {
        int nb = (mesh->numTris + 9) / 10;
        for (int b = 0; b < nb; b++) {
            sTriBox_C0F8* box = &mesh->boxes[b];
            sVE_C0F8b* vt = (sVE_C0F8b*)self->vt;
            if (!vt[9].fn((char*)self + vt[9].delta, box->lo, box->hi)) {
                continue;
            }
            int end = (b + 1) * 10 < mesh->numTris ? (b + 1) * 10 : mesh->numTris;
            for (int i = b * 10; i < end; i++) {
                sV4_C0F8* nrm = &mesh->normals[i];
                if (self->useNormal != 0 && vDot_C0F8(*nrm, self->dir) > 0.8f) {
                    continue;
                }
                                sV4_C0F8* v = mesh->verts;
                sV4_C0F8* p0 = &v[mesh->indices[i * 3]];
                sV4_C0F8* p1 = &v[mesh->indices[i * 3 + 1]];
                sV4_C0F8* p2 = &v[mesh->indices[i * 3 + 2]];
                int r;
                if (flag != 0) {
                    r = self->vt[5].fn((char*)self + self->vt[5].delta, p0, p1, p2, nrm, &pos, &hn, &t);
                } else {
                    r = self->vt[4].fn((char*)self + self->vt[4].delta, p0, p1, p2, nrm, &pos, &hn, &t);
                }
                if (r == 0) {
                    continue;
                }
                sTriHit_C0F8* h = &out[n];
                h->f54 = 0;
                h->type = 2;
                h->tri = -1;
                h->f50 = 0;
                h->f58 = 0;
                h->f5C = -1;
                h->f64 = -1;
                h->f4C = -1;
                h->v20 = D_004FF120;
                h->v30 = D_004FF120;
                h->f68 = 0;
                h->f6C = 0;
                h->f70 = 0;
                h->pos = pos;
                h->nrm = hn;
                h->t = t;
                h->tri = i;
                h->f54 = 0;
                n++;
            }
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C508);
#ifdef SKIP_ASM
// Eight-entry member array with an empty constructor (only the dead loop setup remains).
struct sTreeSlot_32C508 {
    int v;
    sTreeSlot_32C508() {}
};
extern "C" void func_0032C540(void* self);

extern "C" void* func_0032C508(void* self)
{
    new (self) sTreeSlot_32C508[8];
    *(int*)((char*)self + 0x98) = 0;
    func_0032C540(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C540);
#ifdef SKIP_ASM
extern sSphereVec4 D_004FF640[8];
extern sSphereVec4 D_004FF130;

extern "C" void func_0032C540(void* self)
{
    sSphereVec4* dst = (sSphereVec4*)self;
    for (int i = 0; i < 8; i++) {
        dst[i] = D_004FF640[i];
    }
    *(sSphereVec4*)((char*)self + 0x80) = D_004FF130;
    *(float*)((char*)self + 0x90) = 1.0f;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C590);
#ifdef SKIP_ASM
extern "C" float func_0032C590(void* self)
{
    void* p = *(void**)((char*)self + 0x98);
    void* q = *(void**)((char*)p + 0x20);
    return *(float*)q * *(float*)((char*)self + 0x90);
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C5A8);
#ifdef SKIP_ASM
struct sSphereRadius12 {
    float value;
    int pad[2];
};

extern "C" float func_0032C5A8(void* self)
{
    void* p = *(void**)((char*)self + 0x98);
    int idx = *(int*)((char*)p + 0xc);
    sSphereRadius12* tab = *(sSphereRadius12**)((char*)p + 0x20);
    return tab[idx].value * *(float*)((char*)self + 0x90) * 0.5f;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C5E0);
#ifdef SKIP_ASM
struct sSphereVec4_C5E0 {
    float x, y, z, w;
    sSphereVec4_C5E0() {}
    sSphereVec4_C5E0(float* n) { x = n[5]; y = n[6]; z = n[7]; w = 1.0f; }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (a + b).
static inline sSphereVec4_C5E0 Add_C5E0(const sSphereVec4_C5E0& a, const sSphereVec4_C5E0& b)
{
    sSphereVec4_C5E0 r;
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

extern "C" void func_0032C5E0(void* self, sSphereVec4_C5E0* v)
{
    float* n = *(float**)((char*)self + 0x98);
    sSphereVec4_C5E0 p = Add_C5E0(sSphereVec4_C5E0(n), *v);
    *(sSphereVec4_C5E0*)((char*)self + 0x80) = p;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C630);
#ifdef SKIP_ASM
// self->(0x80) += *v  (4-wide VU0 add, macro mode)
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
extern "C" void func_0032C630(void* self, void* v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf3, 0x80(%0)\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, 0x80(%0)\n"
        ".set reorder\n"
        :
        : "r"(self), "r"(v)
        : "memory");
}
#endif

INCLUDE_ASM("intersect/riderspheretree", func_0032C648);

INCLUDE_ASM("intersect/riderspheretree", func_0032C770);

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C898);
#ifdef SKIP_ASM
extern "C" int func_0032DF28(void* self);
extern "C" int func_0032CDB0(void* self, void* a1, float f, void* pos, int a4, int a5, void* a6, void* a7);

extern "C" int func_0032C898(void* self, void* a1, float f, void* a2, void* a3)
{
    void* t = *(void**)((char*)self + 0x98);
    if (*(int*)((char*)t + 0x8) != 0) {
        *(int*)((char*)*(void**)((char*)self + 0x98) + 0x28) = func_0032DF28(t);
    }
    return func_0032CDB0(self, a1, f, (char*)self + 0x80, 0, 0, a2, a3);
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C928);
#ifdef SKIP_ASM
extern "C" int func_0032DF28(void* self);
extern "C" int func_0032D028(void* self, void* a1, void* a2, void* pos, int a4, int a5, void* a6, void* a7);

extern "C" int func_0032C928(void* self, void* a1, void* a2, void* a3, void* a4)
{
    void* t = *(void**)((char*)self + 0x98);
    if (*(int*)((char*)t + 0x8) != 0) {
        *(int*)((char*)*(void**)((char*)self + 0x98) + 0x28) = func_0032DF28(t);
    }
    return func_0032D028(self, a1, a2, (char*)self + 0x80, 0, 0, a3, a4);
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032C9B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// Non-POD 16-byte vector: passed by reference to a caller-made copy.
struct sVecArg_C9B8 {
    float x, y, z, w;
    sVecArg_C9B8() {}
    sVecArg_C9B8(const sVecArg_C9B8& o) { *(cQuad128*)this = *(const cQuad128*)&o; }
} __attribute__((aligned(16)));

static inline sVecArg_C9B8 zeroW_C9B8(const sVecArg_C9B8& in)
{
    sVecArg_C9B8 r = in;
    r.w = 0;
    return r;
}

extern "C" void func_0032DB40_v(void* self, sVecArg_C9B8 v) __asm__("func_0032DB40");
extern "C" void func_0032D208(void* self, void* a1, void* pos, int a3, int a4, void* a5, void* a6);

extern "C" int func_0032C9B8(void* self, sVecArg_C9B8* a1, void* a2, void* a3)
{
    void* t = *(void**)((char*)self + 0x98);
    if (*(int*)((char*)t + 0x8) != 0) {
        *(int*)((char*)*(void**)((char*)self + 0x98) + 0x28) = func_0032DF28(t);
    }
    func_0032DB40_v(self, zeroW_C9B8(*a1));
    *(float*)((char*)self + 0x94) = 0.0f;
    func_0032D208(self, a1, (char*)self + 0x80, 0, 0, a2, a3);
    if (*(float*)((char*)self + 0x94) < 0.0f) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032CA78);
#ifdef SKIP_ASM
extern "C" int func_0032DF28(void* self);
extern "C" void func_0032DB40(void* self, void* v);
extern "C" int func_0032D470(void* self, void* a1, void* a2, void* a3, void* v, void* pos, int a6, int a7, void* a8, void* a9);

extern "C" int func_0032CA78(void* self, void* a1, void* a2, void* a3, void* v, void* a5, void* a6)
{
    void* t = *(void**)((char*)self + 0x98);
    if (*(int*)((char*)t + 0x8) != 0) {
        *(int*)((char*)*(void**)((char*)self + 0x98) + 0x28) = func_0032DF28(t);
    }
    func_0032DB40(self, v);
    *(float*)((char*)self + 0x94) = 0.0f;
    func_0032D470(self, a1, a2, a3, v, (char*)self + 0x80, 0, 0, a5, a6);
    if (*(float*)((char*)self + 0x94) < 0.0f) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032CB58);
#ifdef SKIP_ASM
extern "C" int func_0032DF28(void* self);
extern "C" int func_0032CBF8(void* self, void* other, void* pos, int a3, int a4, void* a5, void* a6);

extern "C" int func_0032CB58(void* self, void* other, void* a2, void* a3)
{
    void* t = *(void**)((char*)self + 0x98);
    if (*(int*)((char*)t + 0x8) != 0) {
        *(int*)((char*)*(void**)((char*)self + 0x98) + 0x28) = func_0032DF28(t);
    }
    t = *(void**)((char*)other + 0x98);
    if (*(int*)((char*)t + 0x8) != 0) {
        *(int*)((char*)*(void**)((char*)other + 0x98) + 0x28) = func_0032DF28(t);
    }
    return func_0032CBF8(self, other, (char*)self + 0x80, 0, 0, a2, a3);
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032CBF8);
#ifdef SKIP_ASM
extern "C" int func_0032CDB0(void* self, void* a1, float f, void* pos, int a4, int a5, void* a6, void* a7);
extern "C" int func_0032CBF8(void* self, void* other, void* pos, int a3, int a4, void* a5, void* a6);

struct sSphereLevel_CBF8 {
    float radius;   // 0x0
    float offset;   // 0x4
    int stride;     // 0x8
};

struct sSphereTreeInfo_CBF8 {
    char pad_0x00[0xC];
    int depth;                      // 0x0C
    char pad_0x10[0x10];
    sSphereLevel_CBF8* levels;      // 0x20
    char pad_0x24[4];
    unsigned char* masks;           // 0x28
};

struct sSphereOct_CBF8 {
    sSphereVec4 dirs[8];            // 0x00
    char pad_0x80[0x10];
    float scale;                    // 0x90
    char pad_0x94[4];
    sSphereTreeInfo_CBF8* tree;     // 0x98
};

// PORT: PS2-only VU0 inline asm (v * s).
static inline sSphereVec4 Scale_CBF8(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sSphereVec4 Add_CBF8(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
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

extern "C" int func_0032CBF8(void* selfp, void* other, void* posp, int depth, int base, void* a5, void* a6)
{
    sSphereOct_CBF8* self = (sSphereOct_CBF8*)selfp;
    sSphereVec4 p;
    unsigned char mask = self->tree->masks[base];
    if (depth < self->tree->depth) {
        if (depth >= 4) {
            return 1;
        }
        if (mask != 0) {
            float off = self->tree->levels[depth + 1].offset;
            for (int i = 0; i < 8; i++) {
                if ((mask >> i) & 1) {
                    p = Add_CBF8(*(sSphereVec4*)posp, Scale_CBF8(self->dirs[i], off));
                    if (func_0032CDB0(other, &p, self->tree->levels[depth].radius * self->scale, (char*)other + 0x80, 0, 0, a5, a6) &&
                        func_0032CBF8(self, other, &p, depth + 1, (i + 1) * self->tree->levels[depth].stride + base, a5, a6)) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032CDB0);
#ifdef SKIP_ASM
struct sSphereLevel_CDB0 {
    float radius;   // 0x0
    float offset;   // 0x4
    int stride;     // 0x8
};

struct sSphereTreeInfo_CDB0 {
    char pad_0x00[0xC];
    int depth;                      // 0x0C
    char pad_0x10[0x10];
    sSphereLevel_CDB0* levels;      // 0x20
    char pad_0x24[4];
    unsigned char* masks;           // 0x28
};

struct sSphereOct_CDB0 {
    sSphereVec4 dirs[8];            // 0x00
    char pad_0x80[0x10];
    float scale;                    // 0x90
    char pad_0x94[4];
    sSphereTreeInfo_CDB0* tree;     // 0x98
};

// PORT: PS2-only VU0 inline asm (v * s).
static inline sSphereVec4 Scale_CDB0(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sSphereVec4 Add_CDB0(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
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

// PORT: PS2-only VU0 inline asm (a - b).
static inline sSphereVec4 Sub_CDB0(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_CDB0(const sSphereVec4& a, const sSphereVec4& b)
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

// PORT: PS2-only VU0 inline asm (v / |v|).
static inline sSphereVec4 Normalize_CDB0(const sSphereVec4& v)
{
    sSphereVec4 r;
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

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_CDB0(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

extern "C" int func_0032CDB0(void* selfp, void* a1, float r, void* pos, int depth, int base, void* outA, void* outB)
{
    sSphereOct_CDB0* self = (sSphereOct_CDB0*)selfp;
    float sum = r + self->tree->levels[depth].radius * self->scale;
    sSphereVec4 d = Sub_CDB0(*(sSphereVec4*)a1, *(sSphereVec4*)pos);
    float dd = Dot_CDB0(d, d);
    if (!(dd < sum * sum))
        return 0;
    float f;
    unsigned char mask = self->tree->masks[base];
    if (depth < self->tree->depth && mask != 0) {
        f = self->tree->levels[depth + 1].offset;
        for (int i = 0; i < 8; i++) {
            if ((mask >> i) & 1) {
                sSphereVec4 p = Add_CDB0(*(sSphereVec4*)pos, Scale_CDB0(self->dirs[i], f));
                if (func_0032CDB0(self, a1, r, &p, depth + 1, (i + 1) * self->tree->levels[depth].stride + base, outA, outB))
                    return 1;
            }
        }
        return 0;
    }
    sSphereVec4 n = Normalize_CDB0(d);
    f = sum - Sqrt_CDB0(dd);
    *(sSphereVec4*)outA = Scale_CDB0(n, f);
    *(sSphereVec4*)outB = Sub_CDB0(*(sSphereVec4*)a1, Scale_CDB0(n, r - f));
    return 1;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032D028);
#ifdef SKIP_ASM
extern "C" int func_00329590(void* a, void* b, void* center, void* box, void* boxMin, void* boxMax, float radius);
extern "C" int func_0032D028(void* self, void* a1, void* a2, void* pos, int a4, int a5, void* a6, void* a7);

struct sSphereLevel_D028 {
    float radius;   // 0x0
    float offset;   // 0x4
    int stride;     // 0x8
};

struct sSphereTreeInfo_D028 {
    char pad_0x00[0xC];
    int depth;                      // 0x0C
    char pad_0x10[0x10];
    sSphereLevel_D028* levels;      // 0x20
    char pad_0x24[4];
    unsigned char* masks;           // 0x28
};

struct sSphereOct_D028 {
    sSphereVec4 dirs[8];            // 0x00
    char pad_0x80[0x10];
    float scale;                    // 0x90
    char pad_0x94[4];
    sSphereTreeInfo_D028* tree;     // 0x98
};

// PORT: PS2-only VU0 inline asm (v * s).
static inline sSphereVec4 Scale_D028(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sSphereVec4 Add_D028(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
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

extern "C" int func_0032D028(void* selfp, void* a1, void* a2, void* pos, int depth, int base, void* outPos, void* outNormal)
{
    sSphereOct_D028* self = (sSphereOct_D028*)selfp;
    sSphereVec4 normal;
    sSphereVec4 dir;
    float t;
    if (func_00329590(a1, a2, pos, &normal, &dir, &t, self->tree->levels[depth].radius * self->scale) == 0) {
        return 0;
    }
    unsigned char mask = self->tree->masks[base];
    if (depth < self->tree->depth && mask != 0) {
        float off = self->tree->levels[depth + 1].offset;
        for (int i = 0; i < 8; i++) {
            if ((mask >> i) & 1) {
                sSphereVec4 p = Add_D028(*(sSphereVec4*)pos, Scale_D028(self->dirs[i], off));
                if (func_0032D028(self, a1, a2, &p, depth + 1, (i + 1) * self->tree->levels[depth].stride + base, outPos, outNormal)) {
                    return 1;
                }
            }
        }
        return 0;
    }
    *(sSphereVec4*)outNormal = normal;
    *(sSphereVec4*)outPos = Scale_D028(dir, t);
    return 1;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032D208);
#ifdef SKIP_ASM
struct sVec4_2D208 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sLevel_2D208 {
    float scale;   // 0x0
    float child;   // 0x4
    int stride;    // 0x8
};
struct sGrid_2D208 {
    char pad0[0xC];
    int maxLevel;         // 0xC
    char pad10[0x10];
    sLevel_2D208* levels; // 0x20
    char pad24[4];
    unsigned char* bits;  // 0x28
};
struct sTree_2D208 {
    sVec4_2D208 dirs[8];   // 0x0
    char pad80[0x10];
    float unit;            // 0x90
    float radius;          // 0x94
    sGrid_2D208* grid;     // 0x98
    int order[8];          // 0x9C
};

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_2D208(const sVec4_2D208& a, const sVec4_2D208& b)
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
static inline void vu0Scale_2D208(sVec4_2D208& r, const sVec4_2D208& v, float s)
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline void vu0Add_2D208(sVec4_2D208& r, const sVec4_2D208& a, const sVec4_2D208& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline void vu0Sub_2D208(sVec4_2D208& r, const sVec4_2D208& a, const sVec4_2D208& b)
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

extern "C" void func_2D208(sTree_2D208* self, sVec4_2D208* a, sVec4_2D208* pos, int level, int off, sVec4_2D208* o1, sVec4_2D208* o2) __asm__("func_0032D208");
extern "C" void func_2D208(sTree_2D208* self, sVec4_2D208* a, sVec4_2D208* pos, int level, int off, sVec4_2D208* o1, sVec4_2D208* o2)
{
    float fv;
    sVec4_2D208 sum;
    sVec4_2D208 d;
    sVec4_2D208 t;
    sVec4_2D208 t2;
    float dot = vu0Dot_2D208(*a, *pos);
    sLevel_2D208* lv = (sLevel_2D208*)(level * 12 + (int)self->grid->levels);
    float edge = lv->scale * self->unit;
    if (dot < edge + self->radius) {
        int bits = self->grid->bits[off];
        if (level < self->grid->maxLevel && bits != 0) {
            fv = ((float*)lv)[4];
            int* p = self->order;
            for (int j = 7; j >= 0; j--, p++) {
                int idx = *p;
                if ((bits >> idx) & 1) {
                    vu0Scale_2D208(t, self->dirs[idx], fv);
                    d = t;
                    vu0Add_2D208(t, *pos, d);
                    sum = t;
                    func_2D208(self, a, &sum, level + 1, (idx + 1) * self->grid->levels[level].stride + off, o1, o2);
                }
            }
        } else {
            fv = dot - edge;
            if (fv < self->radius) {
                d = *a;
                d.w = 0.0f;
                sum = d;
                vu0Scale_2D208(t, sum, fv);
                *o1 = t;
                d = t;
                vu0Scale_2D208(t2, sum, dot);
                t = t2;
                vu0Sub_2D208(t2, *pos, t);
                d = *o2 = t2;
                self->radius = fv;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032D440);
#ifdef SKIP_ASM
// PORT: this caller passes a tolerance in $f12 that the unit's 4-arg func_0032B6A8 never reads;
// bind the 5-arg form to the same symbol.
extern "C" int func_0032B6A8_tol(sSphereVec4* a, sSphereVec4* b, sSphereVec4* c, sSphereVec4* d, float tol) __asm__("func_0032B6A8");

extern "C" int func_0032D440(void* self, sSphereVec4* a, sSphereVec4* b, sSphereVec4* c, sSphereVec4* d)
{
    return func_0032B6A8_tol(a, b, c, d, 9.999999747378752e-05f);
}
#endif

INCLUDE_ASM("intersect/riderspheretree", func_0032D470);

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032DA40);
#ifdef SKIP_ASM
extern int D_0044AF98[];

// Shell sort of keys[] (descending) carrying vals[] along, gap table D_0044AF98.
extern "C" void func_0032DA40(int n, int* keys, int* vals)
{
    int k = 1;
    while (D_0044AF98[k] < n) {
        k++;
    }
    int gap;
    for (;;) {
        gap = D_0044AF98[--k];
        for (int i = gap; i < n; i++) {
            int key = keys[i];
            int val = vals[i];
            int j = i - gap;
            do {
                if (keys[j] >= key) {
                    break;
                }
                keys[j + gap] = keys[j];
                vals[j + gap] = vals[j];
                j -= gap;
            } while (j >= 0);
            keys[j + gap] = key;
            vals[j + gap] = val;
        }
        if (gap < 2) {
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032DB40);
#ifdef SKIP_ASM
struct sV4_DB40 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_DB40(const sV4_DB40& a, const sV4_DB40& b)
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
static inline sV4_DB40 vu0Scale_DB40(const sV4_DB40& v, float s)
{
    sV4_DB40 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

extern "C" void func_0032DA40(int n, int* keys, int* idx);

struct sBox_DB40 {
    sV4_DB40 axes[4];   // 0x00
    char pad40[0x5C];
    int order[8];       // 0x9C
};

extern "C" void func_0032DB40(void* vself, void* vdir)
{
    sBox_DB40* self = (sBox_DB40*)vself;
    sV4_DB40* dir = (sV4_DB40*)vdir;
    int keys[8];
    sV4_DB40 v = vu0Scale_DB40(*dir, -1000.0f);
    int i;
    for (i = 0; i < 4; i++) {
        int n = (int)vu0Dot_DB40(self->axes[i], v);
        keys[i] = n;
        keys[7 - i] = -n;
        self->order[i] = i;
        self->order[7 - i] = 7 - i;
    }
    func_0032DA40(8, keys, self->order);
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032DC10);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label as a placement operator new[].
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_0048E540[];
extern void** D_004A3FC8;
extern void* D_004A3FCC;
extern int D_004A3FD0;
extern int D_004A3FD4;
extern void** D_004A3FD8;
extern void* D_004A3FDC;
extern int D_004A3FE0;
extern int D_004A3FE4;
extern int D_004A3FE8;

// Allocates the two decompression caches; each buffer holds a full octree of the given depth
// (1 + 8 + 64 + ... nodes).
extern "C" void func_0032DC10(int nSmall, int smallDepth, int nBig, int threshold)
{
    int smallSize = 0;
    int bigSize = 0;
    int i;
    int k;
    D_004A3FE8 = threshold;
    k = 1;
    for (i = 0; i <= smallDepth; i++) {
        smallSize += k;
        k <<= 3;
    }
    k = 1;
    for (i = 0; i <= D_004A3FE8; i++) {
        bigSize += k;
        k <<= 3;
    }
    D_004A3FC8 = 0;
    D_004A3FCC = 0;
    D_004A3FD8 = 0;
    D_004A3FDC = 0;
    if (nSmall != 0) {
        D_004A3FC8 = new (D_0048E540, 0, 0) void*[nSmall];
        D_004A3FCC = new (D_0048E540, 0, 0) int[nSmall];
    }
    if (nBig != 0) {
        D_004A3FD8 = new (D_0048E540, 0, 0) void*[nBig];
        D_004A3FDC = new (D_0048E540, 0, 0) int[nBig];
    }
    for (i = 0; i < nSmall; i++) {
        D_004A3FC8[i] = new (D_0048E540, 0, 0) char[smallSize];
        ((int*)D_004A3FCC)[i] = -1;
    }
    for (i = 0; i < nBig; i++) {
        D_004A3FD8[i] = new (D_0048E540, 0, 0) char[bigSize];
        ((int*)D_004A3FDC)[i] = -1;
    }
    D_004A3FD0 = nSmall;
    D_004A3FE0 = nBig;
    D_004A3FD4 = 0;
    D_004A3FE4 = 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032DE20);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
extern void** D_004A3FC8;
extern void* D_004A3FCC;
extern int D_004A3FD0;
extern void** D_004A3FD8;
extern void* D_004A3FDC;
extern int D_004A3FE0;

extern "C" void func_0032DE20(void)
{
    if (D_004A3FC8 != 0) {
        for (int i = 0; i < D_004A3FD0; i++) {
            if (D_004A3FC8[i] != 0) {
                cMemMan_free(D_004A3FC8[i]);
            }
        }
        if (D_004A3FC8 != 0) {
            cMemMan_free(D_004A3FC8);
        }
        D_004A3FC8 = 0;
    }
    if (D_004A3FCC != 0) {
        cMemMan_free(D_004A3FCC);
        D_004A3FCC = 0;
    }
    if (D_004A3FD8 != 0) {
        for (int i = 0; i < D_004A3FE0; i++) {
            if (D_004A3FD8[i] != 0) {
                cMemMan_free(D_004A3FD8[i]);
            }
        }
        if (D_004A3FD8 != 0) {
            cMemMan_free(D_004A3FD8);
        }
        D_004A3FD8 = 0;
    }
    if (D_004A3FDC != 0) {
        cMemMan_free(D_004A3FDC);
        D_004A3FDC = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032DF28);
#ifdef SKIP_ASM
extern void** D_004A3FC8;
extern void* D_004A3FCC;
extern int D_004A3FD0;
extern int D_004A3FD4;
extern void** D_004A3FD8;
extern void* D_004A3FDC;
extern int D_004A3FE0;
extern int D_004A3FE4;
extern int D_004A3FE8;
extern "C" void* func_0032B620(void* dst, void* src);

struct sSphereData_DF28 {
    int key;        // 0x00
    int slot;       // 0x04
    int pad_0x08;
    int size;       // 0x0C
    char pad_0x10[0x14];
    void* packed;   // 0x24
};

// PORT: returns the cached buffer pointer as int (the unit declares it int-returning).
extern "C" int func_0032DF28(void* selfp)
{
    sSphereData_DF28* self = (sSphereData_DF28*)selfp;
    int key = self->key;
    int* pslot = &self->slot;
    if (self->size < D_004A3FE8) {
        if (((int*)D_004A3FCC)[*pslot] == key) {
            return (int)D_004A3FC8[*pslot];
        }
        for (int i = 0; i < D_004A3FD0; i++) {
            if (((int*)D_004A3FCC)[i] == key) {
                *pslot = i;
                return (int)D_004A3FC8[i];
            }
        }
        func_0032B620(D_004A3FC8[D_004A3FD4], self->packed);
        ((int*)D_004A3FCC)[D_004A3FD4] = key;
        *pslot = D_004A3FD4;
        D_004A3FD4++;
        D_004A3FD4 %= D_004A3FD0;
        return (int)D_004A3FC8[*pslot];
    } else {
        if (((int*)D_004A3FDC)[*pslot] == key) {
            return (int)D_004A3FD8[*pslot];
        }
        for (int i = 0; i < D_004A3FE0; i++) {
            if (((int*)D_004A3FDC)[i] == key) {
                *pslot = i;
                return (int)D_004A3FD8[i];
            }
        }
        func_0032B620(D_004A3FD8[D_004A3FE4], self->packed);
        ((int*)D_004A3FDC)[D_004A3FE4] = key;
        *pslot = D_004A3FE4;
        D_004A3FE4++;
        D_004A3FE4 %= D_004A3FE0;
        return (int)D_004A3FD8[*pslot];
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032E100);
#ifdef SKIP_ASM
extern char D_0048E6A8[];

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float subs).
static inline sSphereVec4 sphereCapsuleSub(sSphereVec4* a, sSphereVec4* b)
{
    sSphereVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*a), "m"(*b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
static inline sSphereVec4 sphereCapsuleAdd(sSphereVec4* a, sSphereVec4* b)
{
    sSphereVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*a), "m"(*b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (v / s).
static inline sSphereVec4 sphereCapsuleDiv(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
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

struct sSphereV4_E100 : sSphereVec4 {
    sSphereV4_E100(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct sRiderCapsule_E100 {
    int state;          // 0x00
    int f4;             // 0x04
    int f8;             // 0x08
    int pad_0xC[5];
    sSphereVec4 max;    // 0x20
    sSphereVec4 min;    // 0x30
    sSphereVec4 center; // 0x40
    void* vtbl;         // 0x50
    int pad_0x54[3];
    sSphereVec4 p0;     // 0x60
    sSphereVec4 dir;    // 0x70
    sSphereVec4 p0b;    // 0x80
    sSphereVec4 dirb;   // 0x90
    float radius;       // 0xA0
};

extern "C" sRiderCapsule_E100* func_0032E100(sRiderCapsule_E100* self, sSphereVec4* p0, sSphereVec4* p1,
                                             int state, float r)
{
    self->state = state;
    self->vtbl = D_0048E6A8;
    self->f8 = 0;
    self->f4 = 0;
    self->p0b = *p0;
    self->p0 = self->p0b;
    self->dirb = sphereCapsuleSub(p1, p0);
    self->dir = self->dirb;
    self->radius = r;
    self->max = sSphereV4_E100(p0->x > p1->x ? p0->x : p1->x,
                               p0->y > p1->y ? p0->y : p1->y,
                               p0->z > p1->z ? p0->z : p1->z, 1.0f);
    self->min = sSphereV4_E100(p0->x < p1->x ? p0->x : p1->x,
                               p0->y < p1->y ? p0->y : p1->y,
                               p0->z < p1->z ? p0->z : p1->z, 1.0f);
    self->center = sphereCapsuleDiv(sphereCapsuleAdd(&self->min, &self->max), 2.0f);
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032E288);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
// segment self->p0 .. p0+dir overlaps the box [mn, mx]?
extern "C" int func_0032E288(sRiderCapsule_E100* self, sSphereVec4* mn, sSphereVec4* mx)
{
    sSphereVec4 e = sphereCapsuleAdd(&self->p0, &self->dir);
    if ((self->p0.x < mn->x && e.x < mn->x) || (mx->x < self->p0.x && mx->x < e.x) ||
        (self->p0.y < mn->y && e.y < mn->y) || (mx->y < self->p0.y && mx->y < e.y) ||
        (self->p0.z < mn->z && e.z < mn->z) || (mx->z < self->p0.z && mx->z < e.z)) {
        return 0;
    }
    return 1;
}
#endif

INCLUDE_ASM("intersect/riderspheretree", func_0032E398);

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032E4B8);
#ifdef SKIP_ASM
extern "C" void func_0032E4B8(void* self)
{
    cQuad128 a = *(cQuad128*)((char*)self + 0x80);
    cQuad128 b = *(cQuad128*)((char*)self + 0x90);
    *(cQuad128*)((char*)self + 0x60) = a;
    *(cQuad128*)((char*)self + 0x70) = b;
    *(int*)((char*)self + 0x4) = 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032E4D0);
#ifdef SKIP_ASM
// PORT: this caller passes a tolerance in $f12 that the unit's 4-arg func_0032B6A8 never reads;
// bind the 5-arg form to the same symbol.
extern "C" int func_0032B6A8_tol(sSphereVec4* a, sSphereVec4* b, sSphereVec4* c, sSphereVec4* d, float tol) __asm__("func_0032B6A8");

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_E4D0(const sSphereVec4& a, const sSphereVec4& b)
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sSphereVec4 vu0Sub_E4D0(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sSphereVec4 vu0Add_E4D0(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sSphereVec4 vu0Scale_E4D0(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

// segment origin(0x60)+t*dir(0x70) against the plane through *p with normal *n
extern "C" int func_0032E4D0(void* self, sSphereVec4* p, sSphereVec4* b, sSphereVec4* c, sSphereVec4* n,
                             sSphereVec4* hit, sSphereVec4* outN, float* outT)
{
    sSphereVec4* origin = (sSphereVec4*)((char*)self + 0x60);
    sSphereVec4* dir = (sSphereVec4*)((char*)self + 0x70);
    float denom = vu0Dot_E4D0(*dir, *n);
    if (__builtin_fabsf(denom) < 1.000000013351432e-10f) {
        return 0;
    }
    float t;
    {
        sSphereVec4 d = vu0Sub_E4D0(*p, *origin);
        t = vu0Dot_E4D0(d, *n) / denom;
    }
    *outT = t;
    if (t < 0.0f || 1.0f < t) {
        return 0;
    }
    *hit = vu0Add_E4D0(*origin, vu0Scale_E4D0(*dir, t));
    *outN = *n;
    return func_0032B6A8_tol(p, b, c, hit, 9.999999747378752e-05f);
}
#endif

INCLUDE_ASM("intersect/riderspheretree", func_0032E5E8);

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032E688__FPv);
#ifdef SKIP_ASM
int func_0032E688(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032E690);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A5978;
extern sSphereVec4 D_004FF260[];
extern sSphereVec4 D_004FF120_E690[] __asm__("D_004FF120");

struct sHit_E690 {
    sSphereVec4 pos;    // 0x00
    sSphereVec4 nrm;    // 0x10
    sSphereVec4 v20;    // 0x20
    sSphereVec4 v30;    // 0x30
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
    float f68;          // 0x68
    float u;            // 0x6C
    float v;            // 0x70
    int pad74[3];
};

static inline void reset_E690(sHit_E690* h)
{
    h->type = 2;
    h->obj = 0;
    h->f50 = 0;
    h->f58 = 0;
    h->f5C = -1;
    h->f60 = -1;
    h->f64 = -1;
    h->id = -1;
    h->v20 = *D_004FF120_E690;
    h->v30 = *D_004FF120_E690;
    h->f68 = 0;
    h->u = 0;
    h->v = 0;
}

struct sRay_E690 {
    char pad0[0x60];
    sSphereVec4 origin;     // 0x60
    sSphereVec4 dir;        // 0x70
};

extern "C" int func_0032E690(sRay_E690* self, float* bmin, float* bmax, sHit_E690* hits)
{
    float tmin = -1.0f;
    float tmax = 2.0f;
    float* pd = &self->dir.x;
    float* po = &self->origin.x;
    int fmin = -1;
    int fmax = -1;
    for (int i = 0; i < 3; i++, bmin++, bmax++, pd++, po++) {
        float d = *pd;
        if (__builtin_fabsf(d) > 1.000000013351432e-10f) {
            float o = *po;
            float t1 = (*bmin - o) / d;
            float t2 = (*bmax - o) / d;
            int face = i * 2;
            if (t2 < t1) {
                float tt = t1;
                face++;
                t1 = t2;
                t2 = tt;
            }
            if (tmin < t1) {
                tmin = t1;
                fmin = face;
            }
            if (t2 < tmax) {
                tmax = t2;
                fmax = face ^ 1;
            }
            if (tmax < tmin)
                return 0;
            if (tmax < 0.0f)
                return 0;
            if (1.0f < tmin)
                return 0;
        }
    }
    if (D_004A5978 == 0) {
        D_004FF260[0].x = -1.0f;
        D_004FF260[0].y = 0.0f;
        D_004FF260[0].z = 0.0f;
        D_004FF260[0].w = 0.0f;
        D_004FF260[1].x = 1.0f;
        D_004FF260[1].y = 0.0f;
        D_004FF260[1].z = 0.0f;
        D_004FF260[1].w = 0.0f;
        D_004FF260[2].x = 0.0f;
        D_004FF260[2].y = -1.0f;
        D_004FF260[2].z = 0.0f;
        D_004FF260[2].w = 0.0f;
        D_004FF260[3].x = 0.0f;
        D_004FF260[3].y = 1.0f;
        D_004FF260[3].z = 0.0f;
        D_004FF260[3].w = 0.0f;
        D_004FF260[4].x = 0.0f;
        D_004FF260[4].y = 0.0f;
        D_004FF260[4].z = -1.0f;
        D_004FF260[4].w = 0.0f;
        D_004FF260[5].x = 0.0f;
        D_004FF260[5].y = 0.0f;
        D_004FF260[5].z = 1.0f;
        D_004FF260[5].w = 0.0f;
        D_004A5978 = 1;
    }
    int n = 0;
    if (0.0f <= tmin) {
        sHit_E690* h = &hits[0];
        reset_E690(h);
        h->nrm = D_004FF260[fmin];
        h->pos = vu0Add_E4D0(self->origin, vu0Scale_E4D0(self->dir, tmin));
        h->dist = tmin;
        n = 1;
    }
    if (tmax < 1.0f) {
        reset_E690(&hits[n]);
        hits[n].nrm = D_004FF260[fmax];
        hits[n].pos = vu0Add_E4D0(self->origin, vu0Scale_E4D0(self->dir, tmax));
        hits[n].dist = tmax;
        n++;
    }
    return n;
}
#endif

INCLUDE_ASM("intersect/riderspheretree", func_0032E9A0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032F650);
#ifdef SKIP_ASM
struct sVec4_2F650 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
static inline sVec4_2F650 vecAdd_2F650(sVec4_2F650* a, sVec4_2F650* b)
{
    sVec4_2F650 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*a), "m"(*b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (v * s).
static inline sVec4_2F650 vecScale_2F650(const sVec4_2F650& v, float s)
{
    sVec4_2F650 r;
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
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

struct sRiderSphere_2F650 {
    int state;          // 0x00
    int f4;             // 0x04
    int f8;             // 0x08
    int pad_0xC[5];
    sVec4_2F650 max;    // 0x20
    sVec4_2F650 min;    // 0x30
    sVec4_2F650 center; // 0x40
    void** vtbl;        // 0x50
    int pad_0x54[3];
    void* tree;         // 0x60
    void* tree2;        // 0x64
    int pad_0x68[2];
    cRiderSphereTree node; // 0x70
};

cRiderSphereTree* cRiderSphereTree_cRiderSphereTree(cRiderSphereTree* self);
extern "C" void func_00329DC8(void* tree, sVec4_2F650* mn, sVec4_2F650* mx);
extern void* D_0048E590[];

extern "C" sRiderSphere_2F650* func_0032F650(sRiderSphere_2F650* self, void* tree, int flag)
{
    self->f8 = 0;
    self->f4 = 0;
    self->vtbl = D_0048E590;
    cRiderSphereTree_cRiderSphereTree(&self->node);
    self->tree2 = tree;
    self->tree = tree;
    self->state = flag == 0;
    func_00329DC8(tree, &self->min, &self->max);
    self->center = vecScale_2F650(vecAdd_2F650(&self->min, &self->max), 0.5f);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032F708);
#ifdef SKIP_ASM
extern "C" void func_00329970(void* p, int flags);
void operator_delete(int* ptr);
extern void* D_0048E590[];

extern "C" void func_0032F708(void* self, int flags)
{
    *(void***)((char*)self + 0x50) = D_0048E590;
    func_00329970((char*)self + 0x70, 2);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032F760);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float subs).
static inline sSphereVec4 sphereVecSub(sSphereVec4* a, sSphereVec4* b)
{
    sSphereVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*a), "m"(*b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
static inline sSphereVec4 sphereVecAddR(sSphereVec4* a, sSphereVec4* b)
{
    sSphereVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*a), "m"(*b)
        : "memory");
    return r;
}

// sphere (self+0x60) overlaps the box [mn, mx]?
extern "C" int func_0032F760(void* self, sSphereVec4* mn, sSphereVec4* mx)
{
    sSphereVec4 rv;
    int r = 0;
    float rad = (*(sSphereTreeNode**)((char*)self + 0x60))->radius;
    rv.x = rad;
    rv.y = rad;
    rv.z = rad;
    rv.w = 0;
    sSphereVec4 lo = sphereVecSub(&(*(sSphereTreeNode**)((char*)self + 0x60))->center, &rv);
    sSphereVec4 hi = sphereVecAddR(&(*(sSphereTreeNode**)((char*)self + 0x60))->center, &rv);
    if (mx->x >= lo.x && mn->x <= hi.x && mx->y >= lo.y && mn->y <= hi.y &&
        lo.z <= mx->z && mn->z <= hi.z) {
        r = 1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032F840);
#ifdef SKIP_ASM
struct sSphereNode_9A28;
struct sSphereMtx;
extern "C" sSphereNode_9A28* func_00329A28(sSphereNode_9A28* self, sSphereNode_9A28* src);
extern "C" void func_00329B90(sSphereTreeNode* s, sSphereMtx* m, float scale);

extern "C" void func_0032F840(void* self, sSphereMtx* m, float scale)
{
    sSphereTreeNode* node = (sSphereTreeNode*)((char*)self + 0x70);
    func_00329A28((sSphereNode_9A28*)node, *(sSphereNode_9A28**)((char*)self + 0x60));
    *(sSphereTreeNode**)((char*)self + 0x60) = node;
    func_00329B90(node, m, scale);
    *(int*)((char*)self + 0x4) = 1;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032F8B0__FPv);
#ifdef SKIP_ASM
int func_0032F8B0(void* self)
{
    int t0 = *(int*)((char*)self + 0x64);
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x60) = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032F8C0);
#ifdef SKIP_ASM
extern "C" float func_0032F8C0(void* self)
{
    if (*(int*)self == 0) {
        return -1.0f;
    }
    void* sphere = *(void**)((char*)self + 0x60);
    return *(float*)((char*)sphere + 0x20) * 2.0f;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032F8F0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float sphereLength_32F8F0(const sSphereVec4& v)
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

extern "C" int func_0032A1C0(void* tree, int a1, int a2, int a3, int a4, sSphereVec4* out, int a6);

extern "C" int func_0032F8F0(void* self, int a1, int a2, int a3, int a4, int a5, sSphereVec4* outDir, float* outLen)
{
    sSphereVec4 v;
    int r = func_0032A1C0(*(void**)((char*)self + 0x60), a1, a2, a3, a4, &v, a5);
    if (r != 0) {
        float len = sphereLength_32F8F0(v);
        *outLen = len;
        *outDir = sphereCapsuleDiv(v, len);
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032F990);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float sphereLength_32F990(const sSphereVec4& v)
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

extern "C" int func_0032AA28(void* tree, int a1, int a2, int a3, int a4, sSphereVec4* out, int a6);

extern "C" int func_0032F990(void* self, int a1, int a2, int a3, int a4, int a5, sSphereVec4* outDir, float* outLen)
{
    sSphereVec4 v;
    int r = func_0032AA28(*(void**)((char*)self + 0x60), a1, a2, a3, a4, &v, a5);
    if (r != 0) {
        float len = sphereLength_32F990(v);
        *outLen = len;
        *outDir = sphereCapsuleDiv(v, len);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FA30);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float sphereLength_32FA30(const sSphereVec4& v)
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
static inline void sphereDivEq_32FA30(sSphereVec4& v, float s)
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

struct sSphereHit_32FA30 {
    char pad_0x00[0x10];
    sSphereVec4 dir;      // 0x10
    char pad_0x20[0x20];
    float len;            // 0x40
};

extern "C" int func_00327F18(void* a, void* tree, sSphereVec4* dir, sSphereHit_32FA30* hit);

extern "C" int func_0032FA30(void* self, void* a1, sSphereHit_32FA30* hit)
{
    if (func_00327F18(a1, *(void**)((char*)self + 0x60), &hit->dir, hit) != 0) {
        float len = sphereLength_32FA30(hit->dir);
        hit->len = len;
        sphereDivEq_32FA30(hit->dir, len);
        return 1;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032FAC0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float sphereLength_32FAC0(const sSphereVec4& v)
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
static inline void sphereDivEq_32FAC0(sSphereVec4& v, float s)
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

struct sSphereHit_32FAC0 {
    char pad_0x00[0x10];
    sSphereVec4 dir;      // 0x10
    char pad_0x20[0x20];
    float len;            // 0x40
};

extern "C" int func_0032B2B8(void* tree, void* a1, void* a2, sSphereVec4* dir, sSphereHit_32FAC0* hit);

extern "C" int func_0032FAC0(void* self, void* a1, void* a2, sSphereHit_32FAC0* hit)
{
    if (func_0032B2B8(*(void**)((char*)self + 0x60), a1, a2, &hit->dir, hit) != 0) {
        float len = sphereLength_32FAC0(hit->dir);
        hit->len = len;
        sphereDivEq_32FAC0(hit->dir, len);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FB48);
#ifdef SKIP_ASM
extern char D_0048E650[];

struct sRiderSphere_FB48 {
    int state;              // 0x00
    int f4;                 // 0x04
    int f8;                 // 0x08
    int pad_0xC[5];
    sSphereVec4 max;        // 0x20
    sSphereVec4 min;        // 0x30
    sSphereVec4 center;     // 0x40
    void* vtbl;             // 0x50
    int pad_0x54[3];
    sSphereVec4 pos;        // 0x60
    float radius;           // 0x70
    int pad_0x74[3];
    sSphereVec4 pos0;       // 0x80
    float radius0;          // 0x90
};

extern "C" sRiderSphere_FB48* func_0032FB48(sRiderSphere_FB48* self, sSphereVec4* p, int flag, float r)
{
    sSphereVec4 t;
    self->vtbl = D_0048E650;
    self->f8 = 0;
    self->f4 = 0;
    if (flag != 0) {
        self->state = 0;
    } else {
        self->state = 1;
    }
    self->pos0 = *p;
    self->pos = self->pos0;
    self->radius = r;
    self->radius0 = r;
    t.x = p->x + r;
    t.y = p->y + r;
    t.z = p->z + r;
    t.w = 1.0f;
    self->max = t;
    t.x = p->x - r;
    t.y = p->y - r;
    t.z = p->z - r;
    self->min = t;
    self->center = *p;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FC08);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float subs).
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
// sphere (pos 0x60, radius 0x70) overlaps the box [mn, mx]?
extern "C" int func_0032FC08(void* self, sSphereVec4* mn, sSphereVec4* mx)
{
    sSphereVec4 rv;
    float rad = *(float*)((char*)self + 0x70);
    rv.x = rad;
    rv.y = rad;
    rv.z = rad;
    rv.w = 0;
    sSphereVec4 hi = sphereCapsuleAdd((sSphereVec4*)((char*)self + 0x60), &rv);
    sSphereVec4 lo = sphereCapsuleSub((sSphereVec4*)((char*)self + 0x60), &rv);
    if ((mn->x > hi.x && lo.x < mn->x) || (mx->x < hi.x && mx->x < lo.x) ||
        (mn->y > hi.y && lo.y < mn->y) || (mx->y < hi.y && mx->y < lo.y) ||
        (mn->z > hi.z && lo.z < mn->z) || (mx->z < hi.z && mx->z < lo.z)) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FD40);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4x4 matrix * vector).
static inline sSphereVec4 sphereMtxMulVec(sSphereVec4* m, sSphereVec4* v)
{
    sSphereVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(*v), "r"(m)
        : "memory");
    return r;
}

extern "C" void func_0032FD40(void* self, sSphereVec4* m, float scale)
{
    sSphereVec4 p = sphereMtxMulVec(m, (sSphereVec4*)((char*)self + 0x80));
    *(int*)((char*)self + 0x4) = 1;
    *(sSphereVec4*)((char*)self + 0x60) = p;
    *(float*)((char*)self + 0x70) = scale * *(float*)((char*)self + 0x90);
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FD98);
#ifdef SKIP_ASM
extern "C" void func_0032FD98(void* self)
{
    cQuad128 a = *(cQuad128*)((char*)self + 0x80);
    float f = *(float*)((char*)self + 0x90);
    *(cQuad128*)((char*)self + 0x60) = a;
    *(float*)((char*)self + 0x70) = f;
    *(int*)((char*)self + 0x4) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_0032FDB0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float sphereLength_32FDB0(const sSphereVec4& v)
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
static inline void sphereDivEq_32FDB0(sSphereVec4& v, float s)
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

struct sSphereHit_32FDB0 {
    char pad_0x00[0x10];
    sSphereVec4 dir;      // 0x10
    char pad_0x20[0x20];
    float len;            // 0x40
};

extern "C" int func_0032C898(void* self, void* a1, float f, void* a2, void* a3);

extern "C" int func_0032FDB0(void* self, void* a1, sSphereHit_32FDB0* hit)
{
    if (func_0032C898(a1, (char*)self + 0x60, *(float*)((char*)self + 0x70), &hit->dir, hit) != 0) {
        float len = sphereLength_32FDB0(hit->dir);
        hit->len = len;
        sphereDivEq_32FDB0(hit->dir, len);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FE40);
#ifdef SKIP_ASM
extern "C" int func_00329590(void* a, void* b, void* center, void* box, void* boxMin, void* boxMax, float radius);

extern "C" int func_0032FE40(void* self, void* a, void* b, void* box)
{
    return func_00329590(a, b, (char*)self + 0x60, box, (char*)box + 0x10, (char*)box + 0x40,
                         *(float*)((char*)self + 0x70)) != 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FE78);
#ifdef SKIP_ASM
extern "C" int func_00330360(void* self, sSphereVec4* plane, sSphereVec4* p, float* out);
extern "C" int func_00330250(void* self, sSphereVec4* a, sSphereVec4* b, sSphereVec4* c);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sSphereVec4 sphereScale_32FE78(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sSphereVec4 sphereSub_32FE78(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// Like func_0032FFA0 without the plane-side flip. The success tail is written out twice (jump2 merges the
// copies); the extra self reference keeps the target's register order for self and a.
extern "C" int func_0032FE78(void* self, sSphereVec4* a, sSphereVec4* b, sSphereVec4* c, sSphereVec4* plane,
                             sSphereVec4* outPos, sSphereVec4* outDir, float* outDist)
{
    float t;
    if (func_00330360(self, plane, a, &t) == 0) {
        return 0;
    }
    sSphereVec4 p = sphereSub_32FE78(*(sSphereVec4*)((char*)self + 0x60), sphereScale_32FE78(*plane, t));
    *outPos = p;
    if (func_0032B6A8_tol(a, b, c, outPos, 9.999999747378752e-05f) != 0) {
        *outDir = *plane;
        *outDist = *(float*)((char*)self + 0x70) - t;
        return 1;
    }
    if (func_00330250(self, a, b, c) == 0)
        return 0;
    *outDir = *plane;
    *outDist = *(float*)((char*)self + 0x70) - t;
    return 1;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_0032FFA0);
#ifdef SKIP_ASM
extern "C" int func_00330360(void* self, sSphereVec4* plane, sSphereVec4* p, float* out);
extern "C" int func_00330250(void* self, sSphereVec4* a, sSphereVec4* b, sSphereVec4* c);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sSphereVec4 sphereScale_32FFA0(const sSphereVec4& v, float s)
{
    sSphereVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void sphereScaleEq_32FFA0(sSphereVec4& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "lqc2      $vf4, %0\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s));
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sSphereVec4 sphereSub_32FFA0(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

extern "C" int func_0032FFA0(void* self, sSphereVec4* a, sSphereVec4* b, sSphereVec4* c, sSphereVec4* plane,
                             sSphereVec4* outPos, sSphereVec4* outDir, float* outDist)
{
    sSphereVec4 d = *plane;
    float t;
    if (func_00330360(self, plane, a, &t) == 0) {
        return 0;
    }
    if (t < 0.0f) {
        t = -t;
        sphereScaleEq_32FFA0(d, -1.0f);
    }
    sSphereVec4 p = sphereSub_32FFA0(*(sSphereVec4*)((char*)self + 0x60), sphereScale_32FFA0(d, t));
    *outPos = p;
    if (func_0032B6A8_tol(a, b, c, outPos, 9.999999747378752e-05f) != 0 || func_00330250(self, a, b, c) != 0) {
        *outDir = d;
        *outDist = *(float*)((char*)self + 0x70) - t;
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_003300F8);
#ifdef SKIP_ASM
// Returns -dot(*a, *b) (4-component dot product on VU0, macro mode).
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (-(ax*bx + ay*by + az*bz + aw*bw)).
extern "C" float func_003300F8(sSphereVec4* a, sSphereVec4* b)
{
    float d;
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, 0x0(%1)\n"
        "lqc2      $vf5, 0x0(%2)\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %0, $vf4\n"
        ".set pop\n"
        : "=r"(d)
        : "r"(a), "r"(b));
    return -d;
}
#endif

//100%
INCLUDE_ASM("intersect/riderspheretree", func_00330128);
#ifdef SKIP_ASM
// PORT: callers use this as a by-value struct return (hidden out pointer in $4).
sSphereVec4 func_00330128_def(sSphereVec4* a, sSphereVec4* b, sSphereVec4* p) __asm__("func_00330128");

sSphereVec4 func_00330128_def(sSphereVec4* a, sSphereVec4* b, sSphereVec4* p)
{
    sSphereVec4 d = Sub_CDB0(*p, *a);
    sSphereVec4 e = Sub_CDB0(*b, *a);
    sSphereVec4 n = Normalize_CDB0(e);
    float t = Dot_CDB0(n, d);
    float len = sphereLength_32FDB0(e);
    if (t <= 0.0f) {
        return *a;
    } else if (len <= t) {
        return *b;
    } else {
        sSphereVec4 r = Add_CDB0(*a, Scale_CDB0(n, t));
        return r;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_00330250);
#ifdef SKIP_ASM
// PORT: func_00330128 is defined as (out, a, b, p) returning out; this caller uses it as a by-value
// struct return (hidden out pointer in $4), so bind that view to the same symbol.
sSphereVec4 func_00330128_v(sSphereVec4* a, sSphereVec4* b, sSphereVec4* p) __asm__("func_00330128");

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sSphereVec4 vu0Sub_30250(const sSphereVec4& a, const sSphereVec4& b)
{
    sSphereVec4 r;
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vu0Length_30250(const sSphereVec4& v)
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

// does the sphere at self+0x60 (radius self+0x70) touch any edge of triangle a,b,c?
extern "C" int func_00330250(void* self, sSphereVec4* a, sSphereVec4* b, sSphereVec4* c)
{
    sSphereVec4 pt;
    sSphereVec4 tri[3];
    tri[0] = *a;
    tri[1] = *b;
    tri[2] = *c;
    for (int i = 0; i < 3; i++) {
        pt = func_00330128_v(&tri[i], &tri[(i + 1) % 3], (sSphereVec4*)((char*)self + 0x60));
        float dist = vu0Length_30250(vu0Sub_30250(*(sSphereVec4*)((char*)self + 0x60), pt));
        if (dist < *(float*)((char*)self + 0x70)) {
            return 1;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("intersect/riderspheretree", func_00330360);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float sphereDot_330360(const sSphereVec4& a, const sSphereVec4& b)
{
    float d;
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
        : "=f"(d), "=&r"(t)
        : "m"(a), "m"(b));
    return d;
}

// PORT: PS2-only inline asm (float absolute value).
static inline float sphereAbs_330360(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" int func_00330360(void* self, sSphereVec4* plane, sSphereVec4* p, float* out)
{
    float c = func_003300F8(plane, p);
    float d = sphereDot_330360(*plane, *(sSphereVec4*)((char*)self + 0x60)) + c;
    *out = d;
    return sphereAbs_330360(d) < *(float*)((char*)self + 0x70);
}
#endif

