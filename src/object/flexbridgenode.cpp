#include "common.h"

//100%
INCLUDE_ASM("object/flexbridgenode", cFlexBridgeNode_setupGrid);
#ifdef SKIP_ASM
struct sBox00348058;
extern "C" void* func_002D1BE0();
extern "C" void func_003291E0(void* world, int type, int id, sBox00348058* box, sBox00348058* old);
void cMemMan_free(void*);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_0048E778[];
extern char D_0048E788[];
extern char D_0048E798[];
extern char D_0048E7A8[];
extern char D_0048E7B8[];

struct sGridV3 {
    float x, y, z;
    sGridV3() {}
    sGridV3(float a, float b, float c) : x(a), y(b), z(c) {}
};
inline sGridV3 operator-(const sGridV3& a, const sGridV3& b) { return sGridV3(a.x - b.x, a.y - b.y, a.z - b.z); }
inline sGridV3 operator+(const sGridV3& a, const sGridV3& b) { return sGridV3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline sGridV3 operator*(const sGridV3& a, const float& s) { return sGridV3(a.x * s, a.y * s, a.z * s); }

struct sGridV2 {
    float x, y;
    sGridV2() {}
    sGridV2(float a, float b) : x(a), y(b) {}
};
inline sGridV2 operator-(const sGridV2& a, const sGridV2& b) { return sGridV2(a.x - b.x, a.y - b.y); }
inline sGridV2 operator+(const sGridV2& a, const sGridV2& b) { return sGridV2(a.x + b.x, a.y + b.y); }
inline sGridV2 operator*(const sGridV2& a, const float& s) { return sGridV2(a.x * s, a.y * s); }

struct sGridV4 {
    float x, y, z, w;
    sGridV4() {}
    sGridV4(const sGridV3& v, const float& ww) : x(v.x), y(v.y), z(v.z), w(ww) {}
    sGridV4(const float& a, const float& b, const float& c, const float& d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

struct sGridCol {
    float a, r, g, b;
    sGridCol() {}
};

struct sGridBox {
    sGridV4 min;
    sGridV4 max;
};

// PORT: PS2-only VU0 inline asm (d = a - b)
static inline void gridVecSub(sGridV4& d, const sGridV4& a, const sGridV4& b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(d)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (d = a + b)
static inline void gridVecAdd(sGridV4& d, const sGridV4& a, const sGridV4& b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(d)
        : "m"(a), "m"(b)
        : "memory");
}

struct sGridVEntry {
    short delta;
    short index;
    void* (*fn)(...);
};

struct sGridVEntryV {
    short delta;
    short index;
    void (*fn)(...);
};

struct sGridDef {
    char pad_0x00[0x60];
    sGridV3 min;    // 0x60
    sGridV3 max;    // 0x6C
};

struct sGridMesh {
    char pad_0x00[0x4];
    sGridVEntryV* vt;
};

struct sFlexGrid {
    char pad_0x00[0x18];
    sGridDef* def;        // 0x18
    char pad_0x1C[0x50 - 0x1C];
    int count;            // 0x50
    char pad_0x54[0x78 - 0x54];
    sGridMesh* mesh;      // 0x78
    sGridV4* pts[2];      // 0x7C: current/previous points
    unsigned char* idx;   // 0x84
    char pad_0x88[0x90 - 0x88];
    sGridBox box;         // 0x90
};

extern char* D_004A5B80;

extern "C" void cFlexBridgeNode_setupGrid(sFlexGrid* self)
{
    char* world = D_004A5B80;
    int n = self->count;
    int nverts = n * 2;
    int ntris = (n - 1) * 2;
    sGridVEntry* e = &(*(sGridVEntry**)(world + 0x10D8))[76];
    self->mesh = (sGridMesh*)e->fn(world + e->delta, n, 2, 0x20000000);
    sGridV4*& p0 = self->pts[0];
    p0 = new (D_0048E778, 0x20000000, 0) sGridV4[nverts];
    sGridV4*& p1 = self->pts[1];
    p1 = new (D_0048E788, 0x20000000, 0) sGridV4[nverts];
    self->idx = new (D_0048E798, 0x20000000, 0) unsigned char[ntris * 3];
    sGridV3 pos[4];
    sGridV2 uvs[4];
    sGridCol cols[4];
    sGridV2* uv = new (D_0048E7A8, 0x100, 0) sGridV2[nverts];
    sGridCol* col = new (D_0048E7B8, 0x100, 0) sGridCol[nverts];
    sGridVEntryV* e2 = &(*(sGridVEntryV**)(world + 0x10D8))[97];
    e2->fn(world + e2->delta, self->def, 0, pos, uvs, cols);
    for (int i = 0; i < n; i++) {
        float t = (float)i;
        float inv = 1.0f / (float)(n - 1);
        self->pts[0][i] = sGridV4(pos[0] + (pos[1] - pos[0]) * t * inv, 1.0f);
        self->pts[0][n + i] = sGridV4(pos[2] + (pos[3] - pos[2]) * t * inv, 1.0f);
        uv[i] = uvs[0] + (uvs[1] - uvs[0]) * t * inv;
        uv[n + i] = uvs[2] + (uvs[3] - uvs[2]) * t * inv;
        col[i].a = 1.0f;
        col[i].r = cols[0].r + (cols[1].r - cols[0].r) * t * inv;
        col[i].g = cols[0].g + (cols[1].g - cols[0].g) * t * inv;
        col[i].b = cols[0].b + (cols[1].b - cols[0].b) * t * inv;
        col[n + i].a = 1.0f;
        col[n + i].r = cols[2].r + (cols[3].r - cols[2].r) * t * inv;
        col[n + i].g = cols[2].g + (cols[3].g - cols[2].g) * t * inv;
        col[n + i].b = cols[2].b + (cols[3].b - cols[2].b) * t * inv;
    }
    sGridVEntryV* e3 = &self->mesh->vt[6];
    e3->fn((char*)self->mesh + e3->delta, pos, col, uv);
    if (uv != 0) {
        cMemMan_free(uv);
    }
    if (col != 0) {
        cMemMan_free(col);
    }
    sGridDef* def = self->def;
    self->box.min = sGridV4(def->min.x, def->min.y, def->min.z, 1.0f);
    self->box.max = sGridV4(def->max.x, def->max.y, def->max.z, 1.0f);
    sGridBox old = self->box;
    sGridV4 ext(100.0f, 100.0f, 100.0f, 0.0f);
    gridVecSub(self->box.min, self->box.min, ext);
    gridVecAdd(self->box.max, self->box.max, ext);
    // PORT: the unit declares func_003291E0's third parameter as int; the def pointer is passed through it
    int id = (int)self->def;
    func_003291E0(func_002D1BE0(), 0, id, (sBox00348058*)&self->box, (sBox00348058*)&old);
    int v = 0;
    int j = 0;
    for (int k = 0; k < ntris - 1; k += 2) {
        self->idx[j + 0] = v;
        self->idx[j + 1] = v + n;
        self->idx[j + 2] = v + 1;
        self->idx[j + 3] = v + n;
        self->idx[j + 4] = v + n + 1;
        self->idx[j + 5] = v + 1;
        v++;
        j += 6;
    }
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00346D38);
#ifdef SKIP_ASM
struct sFlexVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float subs).
static inline sFlexVec4 flexVecSub(const sFlexVec4& a, const sFlexVec4& b)
{
    sFlexVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (4 float adds).
static inline sFlexVec4 flexVecAdd(const sFlexVec4& a, const sFlexVec4& b)
{
    sFlexVec4 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (v * s).
static inline sFlexVec4 flexVecScale(const sFlexVec4& v, float s)
{
    sFlexVec4 r;
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

struct sFlexSeg {
    sFlexVec4 pos;       // 0x00
    char pad_0x10[0x40];
};

struct sFlexBridge {
    char pad_0x00[0x20];
    sFlexVec4 end;       // 0x20
    sFlexVec4 start;     // 0x30
    char pad_0x40[0x10];
    int count;           // 0x50
    char pad_0x54[0x20];
    sFlexSeg* segs;      // 0x74
    char pad_0x78[0x4];
    sFlexVec4* pts;      // 0x7C: 2 * count points
};

extern "C" void func_00346D38(sFlexBridge* self)
{
    int n = self->count;
    sFlexSeg* seg = self->segs;
    for (int i = 0; i < self->count; i++, seg++) {
        seg->pos = flexVecAdd(self->pts[i], flexVecScale(flexVecSub(self->pts[n + i], self->pts[i]), 0.5f));
    }
    seg = self->segs;
    self->start = flexVecSub(self->pts[0], seg->pos);
    self->end = flexVecSub(self->pts[n], seg->pos);
}
#endif

INCLUDE_ASM("object/flexbridgenode", func_00346E38);

//100%
INCLUDE_ASM("object/flexbridgenode", func_003470D0);
#ifdef SKIP_ASM
struct sV4_70D0 {
    float x, y, z, w;
    sV4_70D0() {}
    sV4_70D0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

extern sV4_70D0 D_004FF140_70D0 __asm__("D_004FF140");

// PORT: PS2-only VU0 inline asm (a - b).
static inline sV4_70D0 vu0Sub_70D0(const sV4_70D0& a, const sV4_70D0& b)
{
    sV4_70D0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sV4_70D0 vu0Add_70D0(const sV4_70D0& a, const sV4_70D0& b)
{
    sV4_70D0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (a += b).
static inline void vu0AddEq_70D0(sV4_70D0& a, const sV4_70D0& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b));
}

// PORT: PS2-only VU0 inline asm (*v * s).
static inline sV4_70D0 vu0ScaleP_70D0(const sV4_70D0* v, float s)
{
    sV4_70D0 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "o"(*v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector).
static inline sV4_70D0 vu0MtxMul_70D0(const sV4_70D0* m, const sV4_70D0& v)
{
    sV4_70D0 r;
    __asm__(
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
        : "=m"(r)
        : "m"(v), "r"(m));
    return r;
}

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sV4_70D0 vu0Cross_70D0(const sV4_70D0& a, const sV4_70D0& b)
{
    sV4_70D0 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

struct sFlVE_70D0 {
    short delta;
    short index;
    sV4_70D0* (*fn)(void*);
};

struct sFlEnt_70D0 {
    sV4_70D0 a;         // 0x00
    sV4_70D0 b;         // 0x10
    char pad_0x20[4];
    float f24;          // 0x24
    char pad_0x28[0x28];
};

struct sFlBridge_70D0 {
    char pad_0x00[0xC];
    sFlVE_70D0* vt;     // 0x0C
    char pad_0x10[0x64];
    sFlEnt_70D0* ents;  // 0x74
};

struct sFlState_70D0 {
    sV4_70D0 v[6];
    int idx;            // 0x60
};

extern "C" void func_003470D0(sFlBridge_70D0* self, sFlState_70D0* p)
{
    int idx = p->idx;
    if (idx >= 0) {
        int h = idx / 2;
        sFlEnt_70D0* ents = self->ents;
        sFlVE_70D0* vt = self->vt;
        sV4_70D0* m = vt[24].fn((char*)self + vt[24].delta);
        sFlEnt_70D0* e = (sFlEnt_70D0*)(h * 0x50 + (int)ents);
        sV4_70D0 r = vu0MtxMul_70D0(m, vu0ScaleP_70D0(&D_004FF140_70D0, e->f24));
        sV4_70D0 d = vu0Sub_70D0(p->v[0], vu0MtxMul_70D0(m, e->a));
        sV4_70D0 t = vu0Add_70D0(vu0MtxMul_70D0(m, e->b), vu0Cross_70D0(d, r));
        vu0AddEq_70D0(p->v[2], t);
        vu0AddEq_70D0(p->v[3], r);
    }
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00347268);
#ifdef SKIP_ASM
struct sV4_7268 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// 4x4 matrix with an empty ctor and a VU0 copy (through vf1..vf4).
struct sMat_7268 {
    sV4_7268 row[4];
    sMat_7268() {}
    // PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
    sMat_7268(const sMat_7268& s)
    {
        __asm__ __volatile__(
            "lqc2      $vf1, 0x0(%1)\n"
            "lqc2      $vf2, 0x10(%1)\n"
            "lqc2      $vf3, 0x20(%1)\n"
            "lqc2      $vf4, 0x30(%1)\n"
            "sqc2      $vf1, 0x0(%0)\n"
            "sqc2      $vf2, 0x10(%0)\n"
            "sqc2      $vf3, 0x20(%0)\n"
            "sqc2      $vf4, 0x30(%0)\n"
            :
            : "r"(this), "r"(&s)
            : "memory");
    }
};

// PORT: PS2-only VU0 inline asm (vector * matrix, row-vector convention).
static inline sV4_7268 vu0MtxMul_7268(const sMat_7268* m, const sV4_7268& v)
{
    sV4_7268 r;
    __asm__(
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
        : "=m"(r)
        : "m"(v), "r"(m)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (d = v * s).
static inline void vu0ScaleVector_7268(sV4_7268& d, const sV4_7268& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(d), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
}

// d = v * s
static inline void ScaleTo_7268(sV4_7268& d, const sV4_7268& v, float s)
{
    vu0ScaleVector_7268(d, v, s);
}

// v * s
static inline sV4_7268 Scale_7268(const sV4_7268& v, float s)
{
    sV4_7268 r;
    ScaleTo_7268(r, v, s);
    return r;
}

// A vector built from four floats.
struct sVecK_7268 : public sV4_7268 {
    sVecK_7268(const float& ax, const float& ay, const float& az, const float& aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

// Component-wise product of x, y and z; keeps a's w.
static inline sVecK_7268 MulXYZ_7268(const sV4_7268& a, const sV4_7268& b)
{
    return sVecK_7268(a.x * b.x, a.y * b.y, a.z * b.z, a.w);
}

static inline sV4_7268 Row_7268(const sMat_7268& m, int i)
{
    return m.row[i];
}

// In-place inverse of a rigid transform: transpose the rotation, rotate the negated translation back.
static inline void InvertOrtho_7268(sMat_7268& m)
{
    float f;
    f = m.row[0].y;
    m.row[0].y = m.row[1].x;
    m.row[1].x = f;
    f = m.row[0].z;
    m.row[0].z = m.row[2].x;
    m.row[2].x = f;
    f = m.row[1].z;
    m.row[1].z = m.row[2].y;
    m.row[2].y = f;
    sV4_7268 v = Scale_7268(Row_7268(m, 3), -1.0f);
    v.w = 0.0f;
    v = vu0MtxMul_7268(&m, v);
    v.w = 1.0f;
    m.row[3] = v;
}

struct sVt_7268 { short delta; short index; void* fn; };

// Triangle hit record (0x80 bytes).
struct sHit_7268 {
    sV4_7268 pos;       // 0x00
    sV4_7268 nrm;       // 0x10
    sV4_7268 v20;       // 0x20
    sV4_7268 v30;       // 0x30
    float dist;         // 0x40
    int type;           // 0x44
    void* tri;          // 0x48
    int id;             // 0x4C
    void* inst;         // 0x50
    void* obj;          // 0x54
    int f58;            // 0x58
    int bone;           // 0x5C
    int f60;            // 0x60
    int f64;            // 0x64
    int f68;            // 0x68
    float u;            // 0x6C
    float v;            // 0x70
    int pad74[3];
};

// Triangle mesh view handed to the triangle tester.
struct sTriMesh_7268 {
    unsigned short numTris;     // 0x0
    unsigned short numVerts;    // 0x2
    unsigned char* indices;     // 0x4
    void* boxes;                // 0x8
    sV4_7268* verts;            // 0xC
    sV4_7268* normals;          // 0x10
};

struct sQuery_7268 {
    char pad00[0x50];
    sVt_7268* vt;               // 0x50
};

struct sPart_7268 {
    char pad00[0xA];
    short id;                   // 0xA
};

struct sInstDef_7268 {
    int type;
    int pad04[3];
    sPart_7268 parts[1];        // 0x10
};

struct sBoneTbl_7268 {
    int pad00;
    int count;                  // 0x4
};

struct sInst_7268 {
    char pad00[0x80];
    sBoneTbl_7268* tbl;         // 0x80
    float scale;                // 0x84
    sInstDef_7268* def;         // 0x88
};

struct sBridge_7268 {
    char pad00[0xC];
    sVt_7268* vt;               // 0x0C
    char pad10[0x8];
    sInst_7268* inst;           // 0x18
    char pad1C[0x34];
    int count;                  // 0x50
    char pad54[0x28];
    sV4_7268* pts;              // 0x7C
    sV4_7268* nrm;              // 0x80
    unsigned char* idx;         // 0x84
};

typedef sMat_7268* (*GetMat_7268)(void*);
typedef void (*SetXf_7268)(void*, float, sMat_7268*);
typedef void (*Reset_7268)(void*);

extern sV4_7268 D_004FF120_7268[] __asm__("D_004FF120");
// PORT: callers pass the hit capacity as a fifth argument the function never reads.
extern "C" int func_0032C0F8_7268(void* self, sTriMesh_7268* mesh, int flag, sHit_7268* out, int cap) __asm__("func_0032C0F8");

static inline void reset_7268(sHit_7268* h)
{
    h->obj = 0;
    h->inst = 0;
    h->f58 = 0;
    h->bone = -1;
    h->f60 = -1;
    h->f64 = -1;
    h->type = 2;
    h->id = -1;
    h->v20 = *D_004FF120_7268;
    h->v30 = *D_004FF120_7268;
    h->f68 = 0;
    h->u = 0;
    h->v = 0;
}

static inline sPart_7268* GetPart_7268(sInstDef_7268* def, int i)
{
    return &def->parts[i];
}

extern "C" int func_00347268(sBridge_7268* self, sQuery_7268* q, sHit_7268* hits, int cap, int flags)
{
    if (!(flags & 2))
        return 0;
    sTriMesh_7268 mesh;
    mesh.numTris = (self->count - 1) * 2;
    mesh.numVerts = self->count * 2;
    mesh.indices = self->idx;
    mesh.verts = self->pts;
    mesh.normals = self->nrm;
    sMat_7268* m = ((GetMat_7268)self->vt[24].fn)((char*)self + self->vt[24].delta);
    sMat_7268 inv = *m;
    InvertOrtho_7268(inv);
    ((SetXf_7268)q->vt[1].fn)((char*)q + q->vt[1].delta, 1.0f / self->inst->scale, &inv);
    int n = func_0032C0F8_7268(q, &mesh, 1, hits, cap);
    ((Reset_7268)q->vt[2].fn)((char*)q + q->vt[2].delta);
    for (int i = 0; i < n; i++) {
        sHit_7268* h = &hits[i];
        reset_7268(h);
        float s = self->inst->scale;
        h->pos = vu0MtxMul_7268(m, MulXYZ_7268(h->pos, sVecK_7268(s, s, s, 1.0f)));
        h->nrm = vu0MtxMul_7268(m, h->nrm);
        h->type = 1;
        h->inst = self->inst;
        h->bone = self->inst->tbl->count - 1;
        h->tri = 0;
        h->v20 = *D_004FF120_7268;
        h->v30 = *D_004FF120_7268;
        h->id = GetPart_7268(self->inst->def, h->bone)->id;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_003475A8);
#ifdef SKIP_ASM
extern "C" void func_00353FC0(void*);
extern "C" void func_003475D8(void*);

extern "C" void func_003475A8(void* self)
{
    func_00353FC0((char*)self + 0x50);
    func_003475D8(self);
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_003475D8);
#ifdef SKIP_ASM
struct sV4_75D8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sV3_75D8 {
    float x, y, z;
    sV3_75D8() {}
};

struct sSeg_75D8 {
    sV4_75D8 pos;           // 0x00
    char pad10[0x10];
    float angle;            // 0x20
    char pad24[0x2C];
};

struct sBox_75D8 {
    sV4_75D8 lo;
    sV4_75D8 hi;
};

struct sVE_75D8 {
    short delta;
    short index;
    void* fn;
};

struct sMesh_75D8 {
    char pad0[0x4];
    sVE_75D8* vt;           // 0x4
};

struct sBridge_75D8 {
    char pad00[0xC];
    sVE_75D8* vt;           // 0x0C
    char pad10[0x8];
    int id;                 // 0x18
    char pad1C[0x4];
    sV4_75D8 end;           // 0x20
    sV4_75D8 start;         // 0x30
    char pad40[0x10];
    int count;              // 0x50
    char pad54[0x20];
    sSeg_75D8* segs;        // 0x74
    sMesh_75D8* mesh;       // 0x78
    sV4_75D8* pts;          // 0x7C
    sV4_75D8* nrm;          // 0x80
    char pad84[0xC];
    sBox_75D8 box;          // 0x90
};

extern sV4_75D8 D_004FF160_75D8 __asm__("D_004FF160");
extern "C" void func_0031BE50(float a, float* s, float* c);
extern "C" void func_003291E0_75D8(void* world, int type, int id, sBox_75D8* box, sBox_75D8* old) __asm__("func_003291E0");

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len_75D8(const sV4_75D8& v)
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

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sV4_75D8 Scale_75D8(const sV4_75D8& v, float s)
{
    sV4_75D8 r;
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
static inline sV4_75D8 Add_75D8(const sV4_75D8& a, const sV4_75D8& b)
{
    sV4_75D8 r;
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
static inline sV4_75D8 Sub_75D8(const sV4_75D8& a, const sV4_75D8& b)
{
    sV4_75D8 r;
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

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sV4_75D8 Cross_75D8(const sV4_75D8& a, const sV4_75D8& b)
{
    sV4_75D8 r;
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
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize).
static inline sV4_75D8 Normalize_75D8(const sV4_75D8& v)
{
    sV4_75D8 r;
    __asm__(
        "lqc2       $vf3, %1\n"
        "vaddw.x    $vf6, $vf0, $vf0w\n"
        "vmul.xyzw  $vf4, $vf3, $vf3\n"
        "vadday.x   ACC, $vf4, $vf4y\n"
        "vmaddaz.x  ACC, $vf6, $vf4z\n"
        "vmaddw.x   $vf4, $vf6, $vf4w\n"
        "vrsqrt     Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2       $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector).
static inline sV4_75D8 MtxMul_75D8(const sV4_75D8* m, const sV4_75D8& v)
{
    sV4_75D8 r;
    __asm__(
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
        : "=m"(r)
        : "m"(v), "r"(m));
    return r;
}

static inline float Min_75D8(const float& a, const float& b) { return a < b ? a : b; }
static inline float Max_75D8(const float& a, const float& b) { return b < a ? a : b; }

extern "C" void func_003475D8(void* p)
{
    sBridge_75D8* self = (sBridge_75D8*)p;
    int n = self->count;
    int nverts = n * 2;
    int ntris = (n - 1) * 2;
    sV4_75D8 sa = Scale_75D8(D_004FF160_75D8, Len_75D8(self->start));
    sV4_75D8 sb = Scale_75D8(D_004FF160_75D8, Len_75D8(self->end));
    sSeg_75D8* seg = self->segs;
    for (int i = 0; i < n; i++, seg++) {
        float s, c;
        func_0031BE50(seg->angle, &s, &c);
        self->pts[i] = Add_75D8(Add_75D8(seg->pos, Scale_75D8(self->start, c)), Scale_75D8(sa, s));
        self->pts[n + i] = Sub_75D8(Add_75D8(seg->pos, Scale_75D8(self->end, c)), Scale_75D8(sb, s));
    }
    int v = 0;
    for (int k = 0; k < ntris; k += 2) {
        self->nrm[k] = Normalize_75D8(Cross_75D8(Sub_75D8(self->pts[n + v + 1], self->pts[v]), Sub_75D8(self->pts[n + v], self->pts[v])));
        self->nrm[k + 1] = Normalize_75D8(Cross_75D8(Sub_75D8(self->pts[v + 1], self->pts[v]), Sub_75D8(self->pts[n + v + 1], self->pts[v])));
        v++;
    }
    sV3_75D8 pts3[32];
    float mny = 10000000000.0f, mnx = 10000000000.0f, mnz = 10000000000.0f;
    float mxy = -10000000000.0f, mxx = -10000000000.0f, mxz = -10000000000.0f;
    sV4_75D8* m = ((sV4_75D8* (*)(void*))self->vt[24].fn)((char*)self + self->vt[24].delta);
    for (int k = 0; k < nverts; k++) {
        (pts3 + k)->x = self->pts[k].x;
        (pts3 + k)->y = self->pts[k].y;
        (pts3 + k)->z = self->pts[k].z;
        sV4_75D8 t = MtxMul_75D8(m, self->pts[k]);
        mnx = Min_75D8(t.x, mnx);
        mxx = Max_75D8(t.x, mxx);
        mny = Min_75D8(t.y, mny);
        mxy = Max_75D8(t.y, mxy);
        mnz = Min_75D8(t.z, mnz);
        mxz = Max_75D8(t.z, mxz);
    }
    sBox_75D8 old = self->box;
    sV4_75D8 e;
    e.x = mnx;
    e.y = mny;
    e.z = mnz;
    e.w = 1.0f;
    self->box.lo = e;
    e.x = mxx;
    e.y = mxy;
    e.z = mxz;
    self->box.hi = e;
    int id = self->id;
    func_003291E0_75D8(func_002D1BE0(), 0, id, &self->box, &old);
    sMesh_75D8* mesh = self->mesh;
    ((void (*)(void*, sV3_75D8*))mesh->vt[3].fn)((char*)mesh + mesh->vt[3].delta, pts3);
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00347B80);
#ifdef SKIP_ASM
extern void* D_004A47B8;
extern char* D_004A5B80;

struct sRS_7B80 {
    unsigned int f0_0 : 12;
    unsigned int f0_12 : 8;
    unsigned int f0_20 : 12;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 25;
    int f8;
    int fC;
    int f10;
};

struct sRow_7B80 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sModel_7B80 {
    char pad_0x0[0x7D];
    unsigned char page;     // 0x7D
    short slot;             // 0x7E
    char pad_0x80[0x14];
    void* mesh;             // 0x94
};

static inline int IsLoaded_7B80(sModel_7B80* m)
{
    char* wc = *(char**)D_004A47B8;
    if (m->page == 0xFF)
        return 1;
    int ok = *(int*)(wc + (m->page << 3) + 0x24) == 6;
    return ok ? *(int*)(wc + m->slot * 0x18 + 0x3F0) == 3 : 0;
}

struct sPair_7B80 { sRow_7B80 r[4]; };
struct sVE43_7B80 { short delta; short index; sPair_7B80 (*fn)(void*); };
struct sVE93_7B80 { short delta; short index; int (*fn)(void*, void*, void*, sPair_7B80*); };
struct sVE96_7B80 { short delta; short index; void (*fn)(void*, void*, int, int, int); };
struct sVE7_7B80 { short delta; short index; void (*fn)(void*, void*, void*, void*); };
struct sVE24_7B80 { short delta; short index; void* (*fn)(void*); };

#define TOP_7B80(c) (*(sRS_7B80**)((c) + 0xE84))

// Draws the bridge piece's model (through its handler if it has one) unless it is culled or not streamed in.
extern "C" void func_00347B80(char* self)
{
    sModel_7B80* m = *(sModel_7B80**)(self + 0x18);
    if (!IsLoaded_7B80(m)) {
        return;
    }
    char* ctx = D_004A5B80;
    {
        sVE93_7B80* vt = *(sVE93_7B80**)(ctx + 0x10D8);
        char* thisp = ctx + vt[93].delta;
        char* lo = self + 0x90;
        char* hi = self + 0xA0;
        sVE43_7B80* vt43 = *(sVE43_7B80**)(ctx + 0x10D8);
        sPair_7B80 c = vt43[43].fn(ctx + vt43[43].delta);
        if (vt[93].fn(thisp, lo, hi, &c) == 1) {
            return;
        }
    }
    sVE24_7B80* sv = *(sVE24_7B80**)(self + 0xC);
    void* mtx = sv[24].fn(self + sv[24].delta);
    TOP_7B80(ctx)[1] = TOP_7B80(ctx)[0];
    sRS_7B80* t = TOP_7B80(ctx);
    TOP_7B80(ctx) = t + 1;
    t[1].f4_2 = 5;
    char* h = *(char**)(self + 0x78);
    if (h != 0) {
        sVE7_7B80* hv = *(sVE7_7B80**)(h + 4);
        hv[7].fn(h + hv[7].delta, mtx, (*(sModel_7B80**)(self + 0x18))->mesh, 0);
    } else {
        sVE96_7B80* v96 = *(sVE96_7B80**)(ctx + 0x10D8);
        v96[96].fn(ctx + v96[96].delta, *(void**)(self + 0x18), 0, 0, 0);
    }
    TOP_7B80(ctx)--;
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00347D38);
#ifdef SKIP_ASM
struct sFlexBridgeVEntry7D38 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0034FE90(void* self, void* stream);
extern "C" void func_003545D8(void* p, void* stream);

extern "C" void func_00347D38(void* self, void* stream)
{
    func_0034FE90(self, stream);
    func_003545D8((char*)self + 0x50, stream);
    sFlexBridgeVEntry7D38* vt = *(sFlexBridgeVEntry7D38**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x20, 0x30);
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00347D90);
#ifdef SKIP_ASM
extern "C" void* func_0034FB00(void* self, int type, void* a2, void* a3);
extern "C" void* func_00372520(void* self, int n);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_004900D0[];
extern char D_0048E7C8[];
extern char D_004A4008[];

struct sFlexSeg_347D90 {
    int v[16];
    sFlexSeg_347D90() {}
};

struct sFlexDef_347D90 {
    int f0;
    unsigned int links[8];
    char pad24[0x44 - 0x24];
    int f44;
};

extern "C" void* func_00347D90(char* self, void* a2, void* a3, sFlexDef_347D90* def)
{
    func_0034FB00(self, 1, a2, a3);
    *(char**)(self + 0xC) = D_004900D0;
    int len = def->f44;
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 0x24) = len;
    for (int i = 0; i < 8; i++) {
        if (def->links[i] != 0xFFFFFFFF) {
            *(int*)(self + 0x20) += 1;
        }
    }
    sFlexSeg_347D90** segs = (sFlexSeg_347D90**)(self + 0x50);
    *segs = new (D_0048E7C8, 0x20000000, 0) sFlexSeg_347D90[*(int*)(self + 0x20) - 1];
    *(void**)(self + 0x58) = func_00372520(cMemMan_alloc(0xC, D_004A4008, 0x20000000, 0), *(int*)(self + 0x20) * 8 - 9);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00347EA8);
#ifdef SKIP_ASM
struct sSerVEntry_00347EA8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* cInstanceNode_cInstanceNode(void* self, void* a, void* stream);

extern "C" void* func_00347EA8(char* self, void* a, void* stream)
{
    sFlexSeg_347D90** segs = (sFlexSeg_347D90**)(self + 0x50);
    cInstanceNode_cInstanceNode(self, a, stream);
    *(char**)(self + 0xC) = D_004900D0;
    sSerVEntry_00347EA8* e = &(*(sSerVEntry_00347EA8**)stream)[2];
    e->fn((char*)stream + e->delta, self + 0x20, 0x30);
    *segs = new (D_0048E7C8, 0x20000000, 0) sFlexSeg_347D90[*(int*)(self + 0x20) - 1];
    *(void**)(self + 0x58) = func_00372520(cMemMan_alloc(0xC, D_004A4008, 0x20000000, 0), *(int*)(self + 0x20) * 8 - 9);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00347F90);
#ifdef SKIP_ASM
struct sFlexBridgeVEntry7F90 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

void cMemMan_free(void*);
extern "C" void func_0034FBF0(void* self, int flags);
extern char D_004900D0[];

extern "C" void func_00347F90(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_004900D0;
    void* buf = *(void**)((char*)self + 0x50);
    if (buf != 0) {
        cMemMan_free(buf);
    }
    void* obj = *(void**)((char*)self + 0x58);
    if (obj != 0) {
        sFlexBridgeVEntry7F90* vt = *(sFlexBridgeVEntry7F90**)obj;
        vt[1].fn((char*)obj + vt[1].delta, 3);
    }
    func_0034FBF0(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00348008);
#ifdef SKIP_ASM
struct sFlexBridgeVEntry8008 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00348058(void* self);

extern "C" void func_00348008(void* self)
{
    sFlexBridgeVEntry8008* vt1 = *(sFlexBridgeVEntry8008**)((char*)self + 0xC);
    vt1[47].fn((char*)self + vt1[47].delta);
    sFlexBridgeVEntry8008* vt2 = *(sFlexBridgeVEntry8008**)((char*)self + 0xC);
    vt2[48].fn((char*)self + vt2[48].delta);
    func_00348058(self);
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_00348058);
#ifdef SKIP_ASM
struct sBox00348058 {
    float min[4];
    float max[4];
} __attribute__((aligned(16)));

struct sFlexBridgeVEntry8058 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sObj00348058 {
    char pad_0x00[0xC];
    sFlexBridgeVEntry8058* vt;
    char pad_0x10[0x20];
    sBox00348058 box;
    char pad_0x50[0x4];
    int id;
};

extern "C" void* func_002D1BE0();
extern "C" void func_003291E0(void* world, int type, int id, sBox00348058* box, sBox00348058* old);

extern "C" void func_00348058(void* p)
{
    sObj00348058* self = (sObj00348058*)p;
    sBox00348058* box = &self->box;
    sBox00348058 old = self->box;
    self->vt[50].fn((char*)self + self->vt[50].delta);
    func_003291E0(func_002D1BE0(), 2, self->id, box, &old);
}
#endif

//100%
INCLUDE_ASM("object/flexbridgenode", func_003480C8);
#ifdef SKIP_ASM
struct sRS_80C8 {
    unsigned int f0;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 25;
    int f8;
    int fC;
    short f10;
};

struct sRow_80C8 { float x, y, z, w; } __attribute__((aligned(16)));
struct sPair_80C8 { sRow_80C8 r[4]; };
struct sVE43_80C8 { short delta; short index; sPair_80C8 (*fn)(void*); };
struct sVE93_80C8 { short delta; short index; int (*fn)(void*, void*, void*, sPair_80C8*); };

// Cubic basis rows (t^3, t^2, t, 1) for t = 0..3/7, filled once.
extern sRow_80C8 D_004FF6C0[8];
extern int D_004A5980;

// Bridge pre-draw: skips culled pieces, builds the curve basis once, resets the render state, then busy-waits
// per segment.
extern "C" void func_003480C8(char* self)
{
    char* ctx = D_004A5B80;
    {
        sVE93_80C8* vt = *(sVE93_80C8**)(ctx + 0x10D8);
        char* thisp = ctx + vt[93].delta;
        char* lo = self + 0x30;
        char* hi = self + 0x40;
        sVE43_80C8* vt43 = *(sVE43_80C8**)(ctx + 0x10D8);
        sPair_80C8 c = vt43[43].fn(ctx + vt43[43].delta);
        if (vt[93].fn(thisp, lo, hi, &c) == 1) {
            return;
        }
    }
    if (D_004A5980 == 0) {
        sRow_80C8* t = D_004FF6C0;
        t[0].x = 0.0f;
        t[0].y = 0.0f;
        t[0].z = 0.0f;
        t[0].w = 1.0f;
        t[1].x = 0.0029154522f;
        t[1].y = 0.020408165f;
        t[1].z = 0.14285715f;
        t[1].w = 1.0f;
        t[2].x = 0.023323618f;
        t[2].y = 0.08163266f;
        t[2].z = 0.2857143f;
        t[2].w = 1.0f;
        t[3].x = 0.078717224f;
        t[3].y = 0.1836735f;
        t[3].z = 0.42857146f;
        t[3].w = 1.0f;
        t[4].x = 0.078717224f;
        t[4].y = 0.1836735f;
        t[4].z = 0.42857146f;
        t[4].w = 1.0f;
        t[5].x = 0.078717224f;
        t[5].y = 0.1836735f;
        t[5].z = 0.42857146f;
        t[5].w = 1.0f;
        t[6].x = 0.078717224f;
        t[6].y = 0.1836735f;
        t[6].z = 0.42857146f;
        t[6].w = 1.0f;
        t[7].x = 0.078717224f;
        t[7].y = 0.1836735f;
        t[7].z = 0.42857146f;
        t[7].w = 1.0f;
        D_004A5980 = 1;
    }
    sRS_80C8* top = *(sRS_80C8**)(ctx + 0xE84);
    top->f10 = -1;
    (*(sRS_80C8**)(ctx + 0xE84))->f4_2 = 1;
    for (int i = 0; i < *(int*)(self + 0x20) - 1; i++) {
        int j = 7;
        while (j >= 0) {
            j--;
            // PORT: PS2-only pipeline delay.
            __asm__ __volatile__("nop\n\tnop\n\tnop\n\tnop\n\tnop");
        }
    }
}
#endif

INCLUDE_ASM("object/flexbridgenode", func_00348290);

//100%
INCLUDE_ASM("object/flexbridgenode", func_00348B40);
#ifdef SKIP_ASM
struct sSerVEntry_00348B40 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0034FE90(void* self, void* stream);

extern "C" void func_00348B40(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sSerVEntry_00348B40* vt = *(sSerVEntry_00348B40**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x20, 0x30);
}
#endif

