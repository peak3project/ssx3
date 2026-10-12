#include "common.h"

// R5900 128-bit GPR quadword, for functions that copy a 16-byte block via a
// single lq/sq pair instead of word-by-word.
typedef int cQuad128 __attribute__((mode(TI)));

INCLUDE_ASM("object/railmodifier", cRailModifier_buildXform);

//100%
INCLUDE_ASM("object/railmodifier", func_0035C4E0);
#ifdef SKIP_ASM
struct sBox0035C4E0 {
    float min[4];
    float max[4];
} __attribute__((aligned(16)));

struct sObj0035C4E0 {
    char pad_0x00[0x10];
    sBox0035C4E0 box;
    char pad_0x30[0x14];
    int id;
};

extern "C" void func_0035C040(void* self);
extern "C" void* func_002D1BE0();
extern "C" void func_003291E0(void* world, int type, int id, sBox0035C4E0* box, sBox0035C4E0* old);

extern "C" void func_0035C4E0(sObj0035C4E0* self)
{
    sBox0035C4E0* box = &self->box;
    sBox0035C4E0 old = self->box;
    func_0035C040(self);
    func_003291E0(func_002D1BE0(), 2, self->id, box, &old);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035C540);
#ifdef SKIP_ASM
class cStream0035C540 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
    virtual void v03(void* buf, int size);
    virtual void v04(void* buf, int size);
    virtual void v05(void* p);
};

extern "C" void func_0035C540(void* self, cStream0035C540* stream)
{
    stream->v01((char*)self + 0x10, 0x30);
    stream->v05(*(void**)((char*)self + 0x40));
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035C5A0);
#ifdef SKIP_ASM
struct sRmMat44C5A0 {
    float m[4][4];
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = b * a).
static inline void vu0MulMatC5A0(sRmMat44C5A0* d, const sRmMat44C5A0* a, const sRmMat44C5A0* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0CopyMatC5A0(sRmMat44C5A0* d, const sRmMat44C5A0* s)
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
        : "r"(d), "r"(s)
        : "memory");
}

extern "C" void func_0034FED8(void* model, int bone, sRmMat44C5A0* out);

extern "C" void func_0035C5A0(void* self, sRmMat44C5A0* m)
{
    func_0034FED8(*(void**)((char*)self + 0x40), *(int*)((char*)self + 0x34), m);
    sRmMat44C5A0* src = (sRmMat44C5A0*)((char*)self + 0x50);
    sRmMat44C5A0 t2;
    sRmMat44C5A0 t;
    vu0MulMatC5A0(&t, m, src);
    vu0CopyMatC5A0(&t2, &t);
    vu0CopyMatC5A0(m, &t2);
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035C698);

//100%
INCLUDE_ASM("object/railmodifier", func_0035CFE0__FPv);
#ifdef SKIP_ASM
void func_0035CFE0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035CFE8__FPv);
#ifdef SKIP_ASM
void* func_0035CFE8(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035CFF0);
#ifdef SKIP_ASM
struct sVec4CFF0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat33CFF0 {
    float m[3][3];
};

struct sBodyCFF0 {
    char pad_0x00[0x30];
    sVec4CFF0 pos;      // 0x30
    char pad_0x40[0x10];
    sMat33CFF0 rot;     // 0x50
    char pad_0x74[0x1C];
    sVec4CFF0 outPos;   // 0x90
};

static inline sMat33CFF0 scaleCFF0(const sMat33CFF0& a, float s)
{
    sMat33CFF0 r;
    r.m[0][0] = a.m[0][0] * s;
    r.m[0][1] = a.m[0][1] * s;
    r.m[0][2] = a.m[0][2] * s;
    r.m[1][0] = a.m[1][0] * s;
    r.m[1][1] = a.m[1][1] * s;
    r.m[1][2] = a.m[1][2] * s;
    r.m[2][0] = a.m[2][0] * s;
    r.m[2][1] = a.m[2][1] * s;
    r.m[2][2] = a.m[2][2] * s;
    return r;
}

static inline void invertCFF0(sMat33CFF0& a)
{
    sMat33CFF0 adj;
    adj.m[0][0] = a.m[1][1] * a.m[2][2] - a.m[1][2] * a.m[2][1];
    adj.m[0][1] = a.m[2][1] * a.m[0][2] - a.m[2][2] * a.m[0][1];
    adj.m[0][2] = a.m[0][1] * a.m[1][2] - a.m[0][2] * a.m[1][1];
    adj.m[1][0] = a.m[2][0] * a.m[1][2] - a.m[2][2] * a.m[1][0];
    adj.m[1][1] = a.m[0][0] * a.m[2][2] - a.m[0][2] * a.m[2][0];
    adj.m[1][2] = a.m[1][0] * a.m[0][2] - a.m[1][2] * a.m[0][0];
    adj.m[2][0] = a.m[1][0] * a.m[2][1] - a.m[1][1] * a.m[2][0];
    adj.m[2][1] = a.m[2][0] * a.m[0][1] - a.m[2][1] * a.m[0][0];
    adj.m[2][2] = a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
    float inv = a.m[0][0] * adj.m[0][0] + a.m[1][0] * adj.m[0][1] + a.m[2][0] * adj.m[0][2];
    inv = 1.0f / inv;
    a = scaleCFF0(adj, inv);
}

static inline sVec4CFF0 xformCFF0(const sMat33CFF0& m, sBodyCFF0* b)
{
    sVec4CFF0 r;
    float x = b->outPos.x;
    float y = b->outPos.y;
    float z = b->outPos.z;
    r.x = m.m[0][0] * x + m.m[1][0] * y + m.m[2][0] * z;
    r.y = m.m[0][1] * x + m.m[1][1] * y + m.m[2][1] * z;
    r.z = m.m[0][2] * x + m.m[1][2] * y + m.m[2][2] * z;
    r.w = b->outPos.w;
    return r;
}

extern "C" void func_0035CFF0(sBodyCFF0* self, const sVec4CFF0* v)
{
    self->outPos = *v;
    sMat33CFF0 m = self->rot;
    invertCFF0(m);
    self->pos = xformCFF0(m, self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035D288);
#ifdef SKIP_ASM
struct sRmVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRmMat33 {
    float m[3][3];
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sRmVec4 vu0ScaleRM(const sRmVec4& v, float s)
{
    sRmVec4 r;
    int t;
    __asm__ __volatile__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

struct sRmBody {
    char pad_0x00[0x20];
    sRmVec4 dir;        // 0x20
    sRmVec4 pos;        // 0x30
    float scale;        // 0x40
    char pad_0x44[0xC];
    sRmMat33 rot;       // 0x50
    char pad_0x74[0xC];
    sRmVec4 outDir;     // 0x80
    sRmVec4 outPos;     // 0x90
};

static inline sRmVec4 xformRM(sRmBody* b)
{
    sRmVec4 r;
    float x = b->pos.x;
    float y = b->pos.y;
    float z = b->pos.z;
    r.x = b->rot.m[0][0] * x + b->rot.m[1][0] * y + b->rot.m[2][0] * z;
    r.y = b->rot.m[0][1] * x + b->rot.m[1][1] * y + b->rot.m[2][1] * z;
    r.z = b->rot.m[0][2] * x + b->rot.m[1][2] * y + b->rot.m[2][2] * z;
    r.w = b->pos.w;
    return r;
}

extern "C" void func_0035D288(sRmBody* self)
{
    self->outDir = vu0ScaleRM(self->dir, self->scale);
    self->outPos = xformRM(self);
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035D340);

//100%
INCLUDE_ASM("object/railmodifier", func_0035D4A0);
#ifdef SKIP_ASM
extern "C" void func_0035D908(sRmBody* b, const sRmVec4* r, const sRmVec4* imp);

struct sRmRigid_D4A0 {
    sRmVec4 pos;        // 0x00
    char pad_0x10[0x30];
    float invMass;      // 0x40
    char pad_0x44[0xC];
    sRmMat33 invI;      // 0x50
    char pad_0x74[0xC];
    sRmVec4 vel;        // 0x80
    sRmVec4 angVel;     // 0x90
};

// PORT: PS2-only VU0 inline asm (a - b).
static inline sRmVec4 SubD4A0(const sRmVec4& a, const sRmVec4& b)
{
    sRmVec4 r;
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
static inline sRmVec4 AddD4A0(const sRmVec4& a, const sRmVec4& b)
{
    sRmVec4 r;
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

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sRmVec4 CrossD4A0(const sRmVec4& a, const sRmVec4& b)
{
    sRmVec4 r;
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

// PORT: PS2-only VU0 inline asm (dot product).
static inline float DotD4A0(const sRmVec4& a, const sRmVec4& b)
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float LengthD4A0(const sRmVec4& v)
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

// PORT: PS2-only VU0 inline asm (v / s).
static inline sRmVec4 DivD4A0(const sRmVec4& v, float s)
{
    sRmVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sRmVec4 ScaleD4A0(const sRmVec4& v, float s)
{
    sRmVec4 r;
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

static inline sRmVec4 MulID4A0(sRmRigid_D4A0* b, const sRmVec4& v)
{
    sRmVec4 r;
    float x = v.x;
    float y = v.y;
    float z = v.z;
    r.x = b->invI.m[0][0] * x + b->invI.m[1][0] * y + b->invI.m[2][0] * z;
    r.y = b->invI.m[0][1] * x + b->invI.m[1][1] * y + b->invI.m[2][1] * z;
    r.z = b->invI.m[0][2] * x + b->invI.m[1][2] * y + b->invI.m[2][2] * z;
    r.w = v.w;
    return r;
}

static inline sRmVec4 PointVelD4A0(sRmRigid_D4A0* b, const sRmVec4& p)
{
    return AddD4A0(b->vel, CrossD4A0(b->angVel, SubD4A0(p, b->pos)));
}

extern "C" void func_0035D4A0(sRmRigid_D4A0* b, sRmVec4* point, sRmVec4* n, float e, float mu)
{
    sRmVec4 r = SubD4A0(*point, b->pos);
    sRmVec4 vp = PointVelD4A0(b, *point);
    float d = DotD4A0(vp, *n);
    if (mu != 0.0f) {
        sRmVec4 t = SubD4A0(vp, ScaleD4A0(*n, d));
        float len = LengthD4A0(t);
        if (len > 0.0010000000474974513f) {
            sRmVec4 dir = DivD4A0(t, len);
            float j = -mu * len / (b->invMass + DotD4A0(dir, CrossD4A0(MulID4A0(b, CrossD4A0(r, dir)), r)));
            sRmVec4 imp = ScaleD4A0(dir, j);
            func_0035D908((sRmBody*)b, &r, &imp);
            vp = PointVelD4A0(b, *point);
            d = DotD4A0(vp, *n);
            if (d > 0.0f) {
                return;
            }
        }
    }
    float j = -(e + 1.0f) * d / (b->invMass + DotD4A0(*n, CrossD4A0(MulID4A0(b, CrossD4A0(r, *n)), r)));
    sRmVec4 imp = ScaleD4A0(*n, j);
    func_0035D908((sRmBody*)b, &r, &imp);
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035D908);

//100%
INCLUDE_ASM("object/railmodifier", func_0035DA00);
#ifdef SKIP_ASM
class func_0035DA00_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
};

extern "C" void func_0035DA00(void* self, func_0035DA00_cObj* obj)
{
    obj->v01(self, 0x50);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035DA38);
#ifdef SKIP_ASM
class func_0035DA38_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

extern "C" void func_0035DA38(void* self, func_0035DA38_cObj* obj)
{
    obj->v02(self, 0x50);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035DA70);
#ifdef SKIP_ASM
extern void* D_004913F8[];
extern void* D_0048F080[];
void* func_0035CFE8(void* self);
extern "C" void func_0032C508(void* p);
extern "C" void* func_00327CC8(void* self, void* src);
extern "C" void func_0035E248(void* self);

extern "C" void* func_0035DDE8_DA70(void* self, void* a1, void* a2) __asm__("func_0035DDE8");

struct sXf_DA70 {
    sRmVec4 pos;
    sRmVec4 quat;
};

extern "C" sXf_DA70 func_0031B748(void* m);
extern "C" sXf_DA70 func_0035E770_DA70(void* self) __asm__("func_0035E770");

struct sV4c_DA70 {
    float x, y, z, w;
    sV4c_DA70(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (v rotated by quaternion q).
static inline sRmVec4 QuatRot_DA70(const sRmVec4& q, const sRmVec4& v)
{
    sRmVec4 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsub.w    $vf8, $vf8, $vf8\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vopmsub.xyz $vf7, $vf6, $vf4\n"
        "vmulaw.xyz ACC, $vf5, $vf0w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf7, $vf0w\n"
        "vmaddw.xyz $vf8, $vf7, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(r)
        : "m"(q), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (dst = v rotated by quaternion q).
static inline void QuatRotTo_DA70(sRmVec4& dst, const sRmVec4& q, const sRmVec4& v)
{
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsub.w    $vf8, $vf8, $vf8\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vopmsub.xyz $vf7, $vf6, $vf4\n"
        "vmulaw.xyz ACC, $vf5, $vf0w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf7, $vf0w\n"
        "vmaddw.xyz $vf8, $vf7, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(dst)
        : "m"(q), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (dst += b).
static inline void AddTo_DA70(sRmVec4& dst, const sRmVec4& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (unit quaternion + position -> 4x4 matrix).
static inline void QuatPosToMtx_DA70(void* m, const sRmVec4& q, const sRmVec4& p)
{
    __asm__ __volatile__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf3, %2\n"
        "vaddw.xyz  $vf1, $vf0, $vf0w\n"
        "vadd.xyz   $vf5, $vf4, $vf4\n"
        "vsub.w     $vf10, $vf10, $vf10\n"
        "vsub.w     $vf11, $vf11, $vf11\n"
        "vsub.w     $vf12, $vf12, $vf12\n"
        "vmul.xyz   $vf6, $vf5, $vf4\n"
        "vmulw.xyz  $vf7, $vf5, $vf4w\n"
        "vopmula.xyz ACC, $vf5, $vf4\n"
        "vmadd.xyz  $vf8, $vf0, $vf0\n"
        "vsubay.x   ACC, $vf1, $vf6y\n"
        "vmsubz.x   $vf10, $vf1, $vf6z\n"
        "vsubaz.y   ACC, $vf1, $vf6z\n"
        "vmsubx.y   $vf11, $vf1, $vf6x\n"
        "vsubax.z   ACC, $vf1, $vf6x\n"
        "vmsuby.z   $vf12, $vf1, $vf6y\n"
        "vaddaz.y   ACC, $vf0, $vf8z\n"
        "vmaddz.y   $vf10, $vf1, $vf7z\n"
        "vaddax.z   ACC, $vf0, $vf8x\n"
        "vmaddx.z   $vf11, $vf1, $vf7x\n"
        "vaddax.y   ACC, $vf0, $vf8x\n"
        "vmsubx.y   $vf12, $vf1, $vf7x\n"
        "vadday.z   ACC, $vf0, $vf8y\n"
        "vmsuby.z   $vf10, $vf1, $vf7y\n"
        "vaddaz.x   ACC, $vf0, $vf8z\n"
        "vmsubz.x   $vf11, $vf1, $vf7z\n"
        "vadday.x   ACC, $vf0, $vf8y\n"
        "vmaddy.x   $vf12, $vf1, $vf7y\n"
        "sqc2       $vf3, 0x30(%0)\n"
        "sqc2       $vf10, 0x0(%0)\n"
        "sqc2       $vf11, 0x10(%0)\n"
        "sqc2       $vf12, 0x20(%0)\n"
        :
        : "r"(m), "m"(q), "m"(p)
        : "memory");
}

struct sFlags_DA70 {
    char pad0[0x8];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
};

static inline void SetBits_DA70(unsigned int* w, unsigned int mask, unsigned int bits)
{
    *w = (*w & mask) | bits;
}

extern "C" char* func_0035DA70(char* self, char* a1, char* a2, char* a3)
{
    float* timing = (float*)(self + 0x4);
    *(void***)self = D_004913F8;
    func_0035CFE8(self + 0x30);
    *(void***)self = D_0048F080;
    func_0032C508(self + 0xE0);
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 0xD0) = *(int*)(a2 + 0x50);
    func_00327CC8(self + 0xE0, *(void**)(a2 + 0x48));
    *(float*)(self + 0x8) = *(float*)(a1 + 0x4);
    char* t = *(char**)(self + 0x178);
    *(float*)(self + 0xC) = *(float*)(a1 + 0x8);
    *(float*)(self + 0x70) = 1.0f / timing[1];
    sRmVec4 v;
    v.x = *(float*)(t + 0x2C);
    v.y = *(float*)(t + 0x30);
    v.z = *(float*)(t + 0x34);
    v.w = 0.0f;
    *(sRmVec4*)(self + 0x2B0) = v;
    *(sRmMat33*)(self + 0x280) = *(sRmMat33*)(t + 0x5C);
    ((sRmMat33*)(self + 0x280))->m[0][0] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[0][1] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[0][2] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[1][0] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[1][1] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[1][2] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[2][0] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[2][1] *= 0.5f;
    ((sRmMat33*)(self + 0x280))->m[2][2] *= 0.5f;
    sXf_DA70 x = func_0031B748(*(char**)(self + 0xD0) + 0x10);
    {
        sRmVec4 r1;
        QuatRotTo_DA70(r1, x.quat, *(sRmVec4*)(self + 0x2B0));
        v = r1;
        sRmVec4 b;
        sRmVec4 r2;
        QuatRotTo_DA70(r2, x.quat, v);
        b = r2;
        AddTo_DA70(x.pos, b);
    }
    *(sXf_DA70*)(self + 0x30) = x;
    sXf_DA70 y = func_0035E770_DA70(self);
    QuatPosToMtx_DA70(self + 0x240, y.quat, y.pos);
    func_0035E248(self);
    func_0035D288((sRmBody*)(self + 0x30));
    *(float*)(self + 0x14) = 0.10000000149011612f;
    *(float*)(self + 0x18) = 0.4000000059604645f;
    *(float*)(self + 0x1C) = 277.77777099609375f;
    *(int*)(self + 0x10) = 0;
    SetBits_DA70((unsigned int*)(*(char**)(self + 0xD0) + 0x8), 0xFFFFFFDFu, 0x40);
    SetBits_DA70((unsigned int*)(*(char**)(self + 0xD0) + 0x8), 0xFFFFFFFDu, 0x4);
    *(unsigned int*)(*(char**)(self + 0xD0) + 0x8) |= 0x1;
    func_0035DDE8_DA70(self, a3, a2);
    return self;
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035DDE8);

INCLUDE_ASM("object/railmodifier", func_0035DF70);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_0035E1E0);
#ifdef SKIP_ASM
class func_0035E1E0_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
    virtual void v03();
    virtual void v04();
    virtual void v05(void* ptr);
};

extern "C" void func_0035E1E0(void* self, func_0035E1E0_cObj* obj)
{
    func_0035DA00((char*)self + 0x30, (func_0035DA00_cObj*)obj);
    obj->v01((char*)self + 0x4, 0x28);
    obj->v05(*(void**)((char*)self + 0xD0));
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035E248);

//100%
INCLUDE_ASM("object/railmodifier", func_0035E770);
#ifdef SKIP_ASM
struct sRmXform {
    sRmVec4 pos;    // 0x00
    sRmVec4 quat;   // 0x10
};

// PORT: PS2-only VU0 inline asm (dst = v * s).
static inline void vu0ScaleToRM(sRmVec4& dst, const sRmVec4& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst), "=&r"(t)
        : "m"(v), "f"(s));
}

// PORT: PS2-only VU0 inline asm (dst = v rotated by quaternion q).
static inline void vu0QuatRotToRM(sRmVec4& dst, const sRmVec4& q, const sRmVec4& v)
{
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsub.w    $vf8, $vf8, $vf8\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vopmsub.xyz $vf7, $vf6, $vf4\n"
        "vmulaw.xyz ACC, $vf5, $vf0w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf7, $vf0w\n"
        "vmaddw.xyz $vf8, $vf7, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(dst)
        : "m"(q), "m"(v));
}

// PORT: PS2-only VU0 inline asm (dst += b).
static inline void vu0AddToRM(sRmVec4& dst, const sRmVec4& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

extern "C" sRmXform func_0035E770(void* self)
{
    sRmXform r = *(sRmXform*)((char*)self + 0x30);
    sRmVec4 c;
    sRmVec4 b;
    sRmVec4 a;
    sRmVec4 e;
    sRmVec4 d;
    vu0QuatRotToRM(a, *(sRmVec4*)((char*)self + 0x40), *(sRmVec4*)((char*)self + 0x2B0));
    b = a;
    vu0ScaleToRM(a, b, -1.0f);
    c = a;
    vu0QuatRotToRM(d, r.quat, c);
    e = d;
    vu0AddToRM(r.pos, e);
    return r;
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035E850);

//100%
INCLUDE_ASM("object/railmodifier", func_0035ED88__FPv);
#ifdef SKIP_ASM
void func_0035ED88(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035ED90);
#ifdef SKIP_ASM
extern "C" void func_0032C630(void* p, const sRmVec4* d);

// PORT: PS2-only VU0 inline asm (dst += b).
static inline void vu0AddED90(sRmVec4& dst, const sRmVec4& b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

extern "C" void func_0035ED90(sRmBody* self, const sRmVec4* b)
{
    vu0AddED90(self->pos, *b);
    func_0032C630((char*)self + 0xE0, b);
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035EDC8);

//100%
INCLUDE_ASM("object/railmodifier", func_0035F0B8);
#ifdef SKIP_ASM
extern char* D_004A5B64;
int BXrand();
extern "C" void func_0035F218(void* self);

struct sRailTimer {
    int f0;
    int f4;
    float f8;
    float fC;
    int f10;
    int f14;
    void* f18;
    int f1C;
    int f20;
};

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ftrunc_0035F0B8(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    return t;
}

extern "C" sRailTimer* func_0035F0B8(sRailTimer* self, void* def, void* owner)
{
    char* d = (char*)def;
    float one = 1.0f;
    self->f18 = owner;
    self->f14 = 0;
    self->f1C = 0;
    self->f20 = 0;
    self->f0 = *(int*)(d + 0x4);
    float rate = *(float*)(d + 0x10) * (one / (float)*(int*)(D_004A5B64 + 0x10));
    self->f8 = rate;
    self->f10 = *(int*)(d + 0xC);
    self->fC = rate;
    self->f4 = 0;
    int n = *(int*)(d + 0x8);
    if ((float)n < *(float*)&self->f4) {
        union { int i; float f; } u;
        u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
        float x = (u.f - one) * 8.0f;
        float t = ftrunc_0035F0B8(x);
        if (t < x) {
            t += one;
        }
        self->f14 = (int)t;
    } else {
        self->f14 = n;
    }
    func_0035F218(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035F1A8);
#ifdef SKIP_ASM
class func_0035F1A8_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
    virtual void* v03();
};

extern "C" void func_0035F218(void* self);

extern "C" void* func_0035F1A8(void* self, func_0035F1A8_cObj* obj)
{
    obj->v02(self, 0x18);
    *(void**)((char*)self + 0x18) = obj->v03();
    func_0035F218(self);
    return self;
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035F218);

//100%
INCLUDE_ASM("object/railmodifier", func_0035F378);
#ifdef SKIP_ASM
struct sRailModSelect;
extern "C" void func_0035F3A8(sRailModSelect* self);

extern "C" void func_0035F378(sRailModSelect* self, int i)
{
    int n = *(int*)((char*)self + 0x20);
    if (i >= n) {
        i = n - 1;
    }
    *(int*)((char*)self + 0x14) = i;
    func_0035F3A8(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035F3A8);
#ifdef SKIP_ASM
struct sRailOut14 {
    unsigned short value;   // 0x0
    char pad_0x2[0x12];
};

struct sRailModSelect {
    char pad_0x0[0x14];
    int index;              // 0x14
    char* owner;            // 0x18
    int count;              // 0x1c
    char pad_0x20[0x28];
    sRailOut14 out[1];      // 0x48
};

extern "C" void func_0035F3A8(sRailModSelect* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        char* list = *(char**)(self->owner + 0x94);
        char* item = *(char**)(list + (i << 2) + 4);
        char* table = *(char**)(item + 0x10);
        if (table != 0) {
            self->out[i].value = *(unsigned short*)(table + (self->index << 2) + 4);
        }
    }
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035F410);

//100%
INCLUDE_ASM("object/railmodifier", func_0035F598);
#ifdef SKIP_ASM
struct sRailModSelect;
extern "C" void func_0035F378(sRailModSelect* self, int i);

struct sRailModSel_F598 {
    int field_0x0;
    int field_0x4;
    float speed;        // 0x8
    char pad_0xc[0x8];
    int index;          // 0x14
    char pad_0x18[0x8];
    int count;          // 0x20
};

// PORT: R5900 truncate-to-integer-valued float, kept in FPU registers (no GPR round trip).
static inline float fTrunc_F598(float x)
{
    float r;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=&f"(r) : "f"(x));
    return r;
}

extern "C" void func_0035F598(sRailModSel_F598* self, int id, float v)
{
    switch (id) {
    case 300:
        self->speed = v;
        break;
    case 301:
        if (v >= 0.0f && v < 9.0f) {
            float c = fTrunc_F598(v);
            if (c < v) {
                c += 1.0f;
            }
            int n = (int)c;
            self->index = n;
            func_0035F378((sRailModSelect*)self, n);
        }
        break;
    case 302:
        self->index++;
        if (self->index >= self->count) {
            self->index = 1;
        }
        func_0035F378((sRailModSelect*)self, self->index);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035F688);
#ifdef SKIP_ASM
class cStream0035F688 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
    virtual void v03(void* buf, int size);
    virtual void v04(void* buf, int size);
    virtual void v05(void* p);
};

extern "C" void func_0035F688(void* self, cStream0035F688* stream)
{
    stream->v01((char*)self + 0x0, 0x18);
    stream->v05(*(void**)((char*)self + 0x18));
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035F6E8);
#ifdef SKIP_ASM
extern char* D_004A5B64;

struct sRmQuad_F6E8 {
    float x, y, z, w;
    sRmQuad_F6E8(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));

struct sRmDesc_F6E8 {
    int f0;         // 0x0
    int f4;         // 0x4
    float f8;       // 0x8
    float fC;       // 0xC
    float f10;      // 0x10
    float f14;      // 0x14
    float f18;      // 0x18
    float f1C;      // 0x1C
    float f20;      // 0x20
    float f24;      // 0x24
    float f28;      // 0x28
    float f2C;      // 0x2C
};

struct sRmState_F6E8 {
    int f0;             // 0x0
    int f4;             // 0x4
    float f8;           // 0x8
    float fC;           // 0xC
    int f10;            // 0x10
    float f14;          // 0x14
    char pad_0x18[0x8];
    sRmQuad_F6E8 q;     // 0x20
    float f30;          // 0x30
    float f34;          // 0x34
    float f38;          // 0x38
    float f3C;          // 0x3C
    int f40;            // 0x40
};

extern "C" void* func_0035F6E8(sRmState_F6E8* self, sRmDesc_F6E8* d)
{
    self->f40 = 1;
    self->f0 = d->f4;
    self->f30 = d->f8;
    self->f34 = d->fC;
    self->f8 = d->f18;
    self->fC = d->f1C;
    self->f4 = 0;
    self->f10 = 0;
    self->f14 = d->f20 * (1.0f / (float)*(int*)(D_004A5B64 + 0x10));
    self->q = sRmQuad_F6E8(d->f24, d->f28, d->f2C, 0.0f);
    self->f38 = d->f10;
    self->f3C = d->f14;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035F788);
#ifdef SKIP_ASM
struct sRailSerVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_0035F788(void* self, void* stream)
{
    sRailSerVEntry* vt = *(sRailSerVEntry**)stream;
    vt[2].fn((char*)stream + vt[2].delta, self, 0x50);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035F7D0);
#ifdef SKIP_ASM
extern char* D_004A5B64;

struct sV2_F7D0 {
    float x, y;
    sV2_F7D0() {}
    sV2_F7D0(float ax, float ay) : x(ax), y(ay) {}
    sV2_F7D0 operator-() const { return sV2_F7D0(-x, -y); }
    sV2_F7D0 operator*(float s) const { return sV2_F7D0(x * s, y * s); }
    sV2_F7D0& operator+=(const sV2_F7D0& o)
    {
        x += o.x;
        y += o.y;
        return *this;
    }
};

struct sRmState_F7D0 {
    int f0;             // 0x0
    float t;            // 0x4
    float dur;          // 0x8
    float fC;           // 0xC
    float f10;          // 0x10
    float f14;          // 0x14
    char pad_0x18[0x18];
    sV2_F7D0 pos;       // 0x30
    sV2_F7D0 vel;       // 0x38
    int active;         // 0x40
};

extern "C" void func_0035F7D0(sRmState_F7D0* self)
{
    if (self->dur > 0.0f || self->fC > 0.0f) {
        self->t += 1.0f / (float)*(int*)(D_004A5B64 + 0x10);
        if (self->active) {
            if (self->f14 != 0.0f) {
                self->f10 += self->f14;
                if (self->f14 >= 6.2831854820251465f) {
                    self->f14 = self->f14 - 6.2831854820251465f;
                } else if (self->f14 <= 6.2831854820251465f) {
                    self->f14 = self->f14 + 6.2831854820251465f;
                }
            }
            if (self->t >= self->dur) {
                self->t = 0.0f;
                if (self->t < self->fC) {
                    self->active = 0;
                }
                if (self->f0 == 2 || self->f0 == 6) {
                    self->vel = -self->vel;
                }
            }
            if (self->active) {
                if (self->f0 == 6) {
                    if (self->vel.x < 0.0f) {
                        float t = self->t;
                        if (t < self->dur * 0.5f) {
                            sV2_F7D0 m = self->vel * t * (1.0f / self->dur);
                            self->pos.x += m.x;
                            self->pos.y += m.y;
                        } else {
                            sV2_F7D0 m = self->vel * (self->dur - t) * (1.0f / self->dur);
                            self->pos.x += m.x;
                            self->pos.y += m.y;
                        }
                    } else {
                        float u = self->dur - self->t;
                        if (u < self->dur * 0.5f) {
                            sV2_F7D0 m = self->vel * u * (1.0f / self->dur);
                            self->pos.x += m.x;
                            self->pos.y += m.y;
                        } else {
                            sV2_F7D0 m = self->vel * (self->dur - u) * (1.0f / self->dur);
                            self->pos.x += m.x;
                            self->pos.y += m.y;
                        }
                    }
                } else {
                    self->pos.x += self->vel.x;
                    self->pos.y += self->vel.y;
                }
                if (self->pos.x > 1.0f) {
                    self->pos.x = self->pos.x - 1.0f;
                } else if (self->pos.x < -1.0f) {
                    self->pos.x = self->pos.x + 1.0f;
                }
                if (self->pos.y > 1.0f) {
                    self->pos.y = self->pos.y - 1.0f;
                } else if (self->pos.y < -1.0f) {
                    self->pos.y = self->pos.y + 1.0f;
                }
            }
        } else if (self->t >= self->fC) {
            self->t = 0.0f;
            if (self->dur > 0.0f) {
                self->active = 1;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035FB30);
#ifdef SKIP_ASM
extern "C" void func_0035FB30(void* self, int id, float v)
{
    if (id == 200 || id == 201) {
        if (v >= -1.0f && v <= 1.0f) {
            if (id == 201) {
                *(float*)((char*)self + 0x38) = v;
            } else {
                *(float*)((char*)self + 0x3C) = v;
            }
        }
    } else if (id == 202 || id == 203) {
        if (v >= 0.0f && v <= 60.0f) {
            if (id == 202) {
                *(float*)((char*)self + 0x8) = v;
            } else {
                *(float*)((char*)self + 0xC) = v;
            }
        }
    } else if (id == 204 || id == 205) {
        if (v >= -4.0f && v <= 4.0f) {
            if (id == 204) {
                *(float*)((char*)self + 0x30) = v;
            } else {
                *(float*)((char*)self + 0x34) = v;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035FC20);
#ifdef SKIP_ASM
extern "C" void func_0031BE50(float* s, float* c, float angle);

struct sRmAxisRot_35FC20 {
    char pad_0x0[0x10];
    float angle;        // 0x10
    char pad_0x14[0xC];
    float ax, ay, az;   // 0x20
    char pad_0x2c[0x4];
    float tx, ty;       // 0x30
};

struct sRmMtx_35FC20 {
    float m[4][4];
} __attribute__((aligned(16)));

extern sRmMtx_35FC20 D_004FF1A0_35FC20[] __asm__("D_004FF1A0");

extern "C" sRmMtx_35FC20* func_0035FC20(sRmAxisRot_35FC20* self, sRmMtx_35FC20* m)
{
    float zero = 0.0f;
    if (self->angle != zero) {
        float s;
        float c;
        func_0031BE50(&s, &c, self->angle);
        float one = 1.0f;
        float t = one - c;
        float tx = t * self->ax;
        float sy = s * self->ay;
        float sz = s * self->az;
        float sx = s * self->ax;
        float ty = t * self->ay;
        float tz = t * self->az;
        m->m[0][0] = tx * self->ax + c;
        m->m[1][0] = tx * self->ay + sz;
        m->m[2][0] = tx * self->az - sy;
        m->m[3][0] = zero;
        m->m[0][1] = ty * self->ax - sz;
        m->m[1][1] = ty * self->ay + c;
        m->m[2][1] = ty * self->az + sx;
        m->m[3][1] = zero;
        m->m[0][2] = tz * self->ax + sy;
        m->m[1][2] = tz * self->ay - sx;
        m->m[2][2] = tz * self->az + c;
        m->m[3][2] = zero;
        m->m[0][3] = zero;
        m->m[1][3] = zero;
        m->m[2][3] = zero;
        m->m[3][3] = one;
        } else {
        // PORT: PS2-only VU0 inline asm (4x4 matrix copy, identity -> m).
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
            : "r"(m), "r"(D_004FF1A0_35FC20)
            : "memory");
    }
    m->m[3][0] = self->tx;
    m->m[3][1] = self->ty;
    return m;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_0035FD98);
#ifdef SKIP_ASM
class func_0035FD98_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
};

extern "C" void func_0035FD98(void* self, func_0035FD98_cObj* obj)
{
    obj->v01(self, 0x50);
}
#endif

INCLUDE_ASM("object/railmodifier", func_0035FE10);

//100%
INCLUDE_ASM("object/railmodifier", func_00360720__FPv);
#ifdef SKIP_ASM
void func_00360720(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360728__FPv);
#ifdef SKIP_ASM
void func_00360728(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360730__FPv);
#ifdef SKIP_ASM
void func_00360730(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360738__FPv);
#ifdef SKIP_ASM
void func_00360738(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360740__FPv);
#ifdef SKIP_ASM
int func_00360740(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360748__FPv);
#ifdef SKIP_ASM
int func_00360748(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360750__FPv);
#ifdef SKIP_ASM
int func_00360750(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360758__FPv);
#ifdef SKIP_ASM
int func_00360758(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360760__FPv);
#ifdef SKIP_ASM
int func_00360760(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360768);
#ifdef SKIP_ASM
extern "C" unsigned int func_00360768()
{
    return 0xFFFFFFFFU;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360778__FPv);
#ifdef SKIP_ASM
void func_00360778(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360780__FPv);
#ifdef SKIP_ASM
void func_00360780(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360788__FPv);
#ifdef SKIP_ASM
void func_00360788(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360790__FPv);
#ifdef SKIP_ASM
void func_00360790(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360798__FPv);
#ifdef SKIP_ASM
int func_00360798(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003607A0);
#ifdef SKIP_ASM
extern "C" int func_003607A0(void* self, int a1)
{
    return *(short*)((char*)self + 0x10) == a1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360800);
#ifdef SKIP_ASM
struct sRailVEntryU800 {
    short delta;
    short index;
    unsigned int (*fn)(void*);
};

extern "C" int func_00360800(void* self, void* obj)
{
    sRailVEntryU800* vt = *(sRailVEntryU800**)((char*)obj + 0xC);
    return vt[8].fn((char*)obj + vt[8].delta) >= *(unsigned int*)((char*)self + 0x14);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360840);
#ifdef SKIP_ASM
struct sRailVEntryU840 {
    short delta;
    short index;
    unsigned int (*fn)(void*);
};

extern "C" int func_00360840(void* self, void* obj)
{
    sRailVEntryU840* vt = *(sRailVEntryU840**)((char*)obj + 0xC);
    return *(unsigned int*)((char*)self + 0x14) == vt[8].fn((char*)obj + vt[8].delta);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360880__FPv);
#ifdef SKIP_ASM
int func_00360880(void* self)
{
    return *(int*)((char*)self + 0x14);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003608E8);
#ifdef SKIP_ASM
class cRailVirt {
public:
    int field_0x0;
    int field_0x4;
    int field_0x8;
    // vptr lands at 0xC (g++ 2.95 places it after the class's own data);
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
    virtual int v15();
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
};

extern "C" int func_003608E8(cRailVirt* self)
{
    return self->v15();
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360910__FPv);
#ifdef SKIP_ASM
int func_00360910(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360918__FPv);
#ifdef SKIP_ASM
int func_00360918(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360920__FPv);
#ifdef SKIP_ASM
unsigned char func_00360920(void* self)
{
    return *(unsigned char*)((char*)*(void**)((char*)self + 0x18) + 0x78);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360930__FPv);
#ifdef SKIP_ASM
int func_00360930(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360938__FPv);
#ifdef SKIP_ASM
void func_00360938(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360940__FPv);
#ifdef SKIP_ASM
int func_00360940(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360948__FPv);
#ifdef SKIP_ASM
int func_00360948(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360950__FPv);
#ifdef SKIP_ASM
int func_00360950(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360958__FPv);
#ifdef SKIP_ASM
int func_00360958(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360960__FPv);
#ifdef SKIP_ASM
int func_00360960(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360970__FPv);
#ifdef SKIP_ASM
void* func_00360970(void* self)
{
    return (char*)*(void**)((char*)self + 0x18) + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360980__FPv);
#ifdef SKIP_ASM
void* func_00360980(void* self)
{
    return (char*)*(void**)((char*)self + 0x18) + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360990__FPv);
#ifdef SKIP_ASM
int func_00360990(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360998__FPv);
#ifdef SKIP_ASM
int func_00360998(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609A0__FPv);
#ifdef SKIP_ASM
int func_003609A0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609A8__FPv);
#ifdef SKIP_ASM
int func_003609A8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609B0__FPv);
#ifdef SKIP_ASM
float func_003609B0(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609C0__FPv);
#ifdef SKIP_ASM
int func_003609C0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609C8__FPv);
#ifdef SKIP_ASM
int func_003609C8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609D0__FPv);
#ifdef SKIP_ASM
void func_003609D0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609D8__FPv);
#ifdef SKIP_ASM
void func_003609D8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609E0__FPv);
#ifdef SKIP_ASM
int func_003609E0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609E8__FPv);
#ifdef SKIP_ASM
int func_003609E8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609F0__FPv);
#ifdef SKIP_ASM
void func_003609F0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003609F8__FPv);
#ifdef SKIP_ASM
void func_003609F8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A00__FPv);
#ifdef SKIP_ASM
void func_00360A00(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A08__FPv);
#ifdef SKIP_ASM
void func_00360A08(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A10__FPv);
#ifdef SKIP_ASM
int func_00360A10(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A18__FPv);
#ifdef SKIP_ASM
int func_00360A18(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A20__FPv);
#ifdef SKIP_ASM
int func_00360A20(void* self)
{
    return 0;
}
#endif

extern void* D_00491B00[];
extern "C" void* func_0034FBF0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00360A28__FPv);
#ifdef SKIP_ASM
void* func_00360A28(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_00491B00;
    return func_0034FBF0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A50__FPv);
#ifdef SKIP_ASM
void func_00360A50(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A58__FPv);
#ifdef SKIP_ASM
void func_00360A58(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A60__FPv);
#ifdef SKIP_ASM
void func_00360A60(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A68__FPv);
#ifdef SKIP_ASM
void func_00360A68(void* self)
{
}
#endif

extern void* D_00491800[];
extern "C" void* func_0034FBF0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00360A70__FPv);
#ifdef SKIP_ASM
void* func_00360A70(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_00491800;
    return func_0034FBF0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360A98__FPv);
#ifdef SKIP_ASM
void func_00360A98(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360AA0__FPv);
#ifdef SKIP_ASM
void func_00360AA0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360AA8__FPv);
#ifdef SKIP_ASM
void func_00360AA8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360AB0__FPv);
#ifdef SKIP_ASM
void func_00360AB0(void* self)
{
}
#endif

extern void* D_00491680[];
extern "C" void* func_0034FBF0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00360AB8__FPv);
#ifdef SKIP_ASM
void* func_00360AB8(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_00491680;
    return func_0034FBF0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360AE0__FPv);
#ifdef SKIP_ASM
void func_00360AE0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360AE8__FPv);
#ifdef SKIP_ASM
void func_00360AE8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360AF0__FPv);
#ifdef SKIP_ASM
void func_00360AF0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360AF8__FPv);
#ifdef SKIP_ASM
void func_00360AF8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B00);
#ifdef SKIP_ASM
extern void* D_004913F8[];
void operator_delete(int*);

extern "C" void func_00360B00(void* self, int flags)
{
    *(void***)self = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B30__FPv);
#ifdef SKIP_ASM
void func_00360B30(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B38__FPv);
#ifdef SKIP_ASM
void func_00360B38(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B40__FPv);
#ifdef SKIP_ASM
void func_00360B40(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B48__FPv);
#ifdef SKIP_ASM
void func_00360B48(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B50__FPv);
#ifdef SKIP_ASM
int func_00360B50(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B58__FPv);
#ifdef SKIP_ASM
void func_00360B58(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B60__FPv);
#ifdef SKIP_ASM
int func_00360B60(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B68__FPv);
#ifdef SKIP_ASM
int func_00360B68(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B70__FPv);
#ifdef SKIP_ASM
void func_00360B70(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B78__FPv);
#ifdef SKIP_ASM
void func_00360B78(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B80__FPv);
#ifdef SKIP_ASM
int func_00360B80(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B88__FPv);
#ifdef SKIP_ASM
void func_00360B88(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360B90__FPv);
#ifdef SKIP_ASM
float func_00360B90(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BA0__FPv);
#ifdef SKIP_ASM
void func_00360BA0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BA8__FPv);
#ifdef SKIP_ASM
int func_00360BA8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BB0__FPv);
#ifdef SKIP_ASM
int func_00360BB0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BB8__FPv);
#ifdef SKIP_ASM
int func_00360BB8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BC0__FPv);
#ifdef SKIP_ASM
int func_00360BC0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BC8__FPv);
#ifdef SKIP_ASM
int func_00360BC8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BD0__FPv);
#ifdef SKIP_ASM
int func_00360BD0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BD8__FPv);
#ifdef SKIP_ASM
void func_00360BD8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BE0__FPv);
#ifdef SKIP_ASM
int func_00360BE0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BE8__FPv);
#ifdef SKIP_ASM
void func_00360BE8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BF0__FPv);
#ifdef SKIP_ASM
int func_00360BF0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360BF8__FPv);
#ifdef SKIP_ASM
int func_00360BF8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360C00__FPv);
#ifdef SKIP_ASM
void func_00360C00(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360C28);
#ifdef SKIP_ASM
extern void* D_004913B8[];
void operator_delete(int*);

extern "C" void func_00360C28(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004913B8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360C58__FPv);
#ifdef SKIP_ASM
void func_00360C58(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360C60__FPv);
#ifdef SKIP_ASM
void func_00360C60(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360C68__FPv);
#ifdef SKIP_ASM
int func_00360C68(void* self)
{
    return *(int*)((char*)self + 0x0);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360C70__FPv);
#ifdef SKIP_ASM
int func_00360C70(void* self)
{
    return 0;
}
#endif

extern "C" void* func_00370C08(void* self);

//100%
INCLUDE_ASM("object/railmodifier", func_00360C78__FPv);
#ifdef SKIP_ASM
void* func_00360C78(void* self)
{
    return func_00370C08(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360C98);
#ifdef SKIP_ASM
extern "C" void func_00345760(void* self);
void operator_delete(int*);
extern void* D_00491340[];

extern "C" void func_00360C98(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00491340;
    func_00345760(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360CE8__FPv);
#ifdef SKIP_ASM
int func_00360CE8(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360CF0__FPv);
#ifdef SKIP_ASM
void func_00360CF0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360CF8__FPv);
#ifdef SKIP_ASM
void func_00360CF8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D00__FPv);
#ifdef SKIP_ASM
void func_00360D00(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D08__FPv);
#ifdef SKIP_ASM
void func_00360D08(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D10__FPv);
#ifdef SKIP_ASM
void func_00360D10(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D20__FPv);
#ifdef SKIP_ASM
int func_00360D20(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D28__FPv);
#ifdef SKIP_ASM
int func_00360D28(void* self)
{
    return 0x2;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D38__FPv);
#ifdef SKIP_ASM
int func_00360D38(void* self)
{
    return 0x3;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D40);
#ifdef SKIP_ASM
extern "C" void func_0035B6D0(void* self);
void operator_delete(int*);
extern void* D_00491200[];

extern "C" void func_00360D40(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00491200;
    func_0035B6D0(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360D90__FPv);
#ifdef SKIP_ASM
void func_00360D90(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360DA0);
#ifdef SKIP_ASM
extern "C" void func_00360DA0(cRailVirt* self)
{
    self->v50();
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360DC8__FPv);
#ifdef SKIP_ASM
void func_00360DC8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360DD0__FPv);
#ifdef SKIP_ASM
int func_00360DD0(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00360DD8);
#ifdef SKIP_ASM
extern "C" void func_00360DD8(void* self)
{
    unsigned short* p = (unsigned short*)((char*)self + 0x12);
    *p &= 0xFFFE;
}
#endif

extern void* D_00490E80[];
extern "C" void* func_003553C0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00361038__FPv);
#ifdef SKIP_ASM
void* func_00361038(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_00490E80;
    return func_003553C0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361060__FPv);
#ifdef SKIP_ASM
int func_00361060(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361068);
#ifdef SKIP_ASM
extern "C" float func_00361068(void* self)
{
    float input = *(float*)((char*)self + 0x0);
    return input * 30.0f;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361080__FPv);
#ifdef SKIP_ASM
float func_00361080(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361090__FPv);
#ifdef SKIP_ASM
int func_00361090(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361098);
#ifdef SKIP_ASM
struct sRailVEntry1098 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" int func_00361098(void* self)
{
    if (*(unsigned short*)((char*)self + 0x26) & 1) {
        void* sub = (char*)self + 0x14;
        sRailVEntry1098* vt = *(sRailVEntry1098**)((char*)self + 0x20);
        vt[51].fn((char*)sub + vt[51].delta);
    }
    return *(int*)((char*)self + 0x44);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003610E0);
#ifdef SKIP_ASM
struct sVEntry003610E0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sElem003610E0 {
    char data[0x40];
};

extern "C" sElem003610E0* func_003610E0(void* self, int i)
{
    char* obj = (char*)self + 0x14;
    if (*(unsigned short*)((char*)self + 0x26) & 1) {
        sVEntry003610E0* vt = *(sVEntry003610E0**)((char*)self + 0x20);
        vt[51].fn(obj + vt[51].delta);
    }
    return &(*(sElem003610E0**)((char*)self + 0x44))[i];
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361150__FPv);
#ifdef SKIP_ASM
void* func_00361150(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361158);
#ifdef SKIP_ASM
extern "C" float func_00361158(void* self)
{
    return *(int*)((char*)self + 0x8) == 0 ? *(float*)((char*)self + 0x10) : 0.0f;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361170);
#ifdef SKIP_ASM
extern "C" int func_00361170(void* self)
{
    int r = -1;
    if (*(float*)((char*)self + 0x10) >= 0.0f) {
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361198__FPv);
#ifdef SKIP_ASM
int func_00361198(void* self)
{
    return *(int*)((char*)self + 0x8);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003611D8);
#ifdef SKIP_ASM
extern void* D_00490AF0[];
void operator_delete(int*);

extern "C" void func_003611D8(void* self, int flags)
{
    *(void***)((char*)self + 0x84) = D_00490AF0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361290);
#ifdef SKIP_ASM
extern void* D_00490AF0[];
void operator_delete(int*);

extern "C" void func_00361290(void* self, int flags)
{
    *(void***)((char*)self + 0x84) = D_00490AF0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003612C0);
#ifdef SKIP_ASM
extern char D_004FF1A0[];

// Copy the 4x4 matrix D_004FF1A0 into self+0x90.
// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
extern "C" void func_003612C0(void* self)
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
        : "r"((char*)self + 0x90), "r"(D_004FF1A0)
        : "memory");
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361340);
#ifdef SKIP_ASM
extern void* D_00490AF0[];
void operator_delete(int*);

extern "C" void func_00361340(void* self, int flags)
{
    *(void***)((char*)self + 0x84) = D_00490AF0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361400);
#ifdef SKIP_ASM
extern "C" void func_0034DBA8(void* self, int flags);
void operator_delete(int*);
extern void* D_004908F8[];

extern "C" void func_00361400(void* self, int flags)
{
    *(void***)((char*)self + 0x50) = D_004908F8;
    func_0034DBA8((char*)self + 0x30, 0);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361458__FPv);
#ifdef SKIP_ASM
void* func_00361458(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361460);
#ifdef SKIP_ASM
extern "C" int func_00361460(void* self)
{
    int r = -1;
    if (*(float*)((char*)self + 0x4) >= 0.0f) {
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361488);
#ifdef SKIP_ASM
extern void* D_004913B8[];
void operator_delete(int*);

extern "C" void func_00361488(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004913B8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003614B8__FPv);
#ifdef SKIP_ASM
int func_003614B8(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003614C0__FPv);
#ifdef SKIP_ASM
void func_003614C0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003614C8__FPv);
#ifdef SKIP_ASM
void func_003614C8(void* self)
{
}
#endif

extern void* D_004906F0[];
extern "C" void* func_003553C0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_003614D0__FPv);
#ifdef SKIP_ASM
void* func_003614D0(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_004906F0;
    return func_003553C0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003614F8__FPv);
#ifdef SKIP_ASM
void func_003614F8(void* self)
{
}
#endif

extern void* D_00490570[];
extern "C" void* func_0034FBF0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00361500__FPv);
#ifdef SKIP_ASM
void* func_00361500(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_00490570;
    return func_0034FBF0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361528__FPv);
#ifdef SKIP_ASM
void* func_00361528(void* self)
{
    return (char*)self + 0x1C;
}
#endif

extern void* D_004903F0[];
extern "C" void* func_0034FBF0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00361530__FPv);
#ifdef SKIP_ASM
void* func_00361530(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_004903F0;
    return func_0034FBF0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361558__FPv);
#ifdef SKIP_ASM
void* func_00361558(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361560__FPv);
#ifdef SKIP_ASM
int func_00361560(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361568__FPv);
#ifdef SKIP_ASM
int func_00361568(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361570__FPv);
#ifdef SKIP_ASM
void* func_00361570(void* self)
{
    return (char*)self + 0x90;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361578__FPv);
#ifdef SKIP_ASM
void func_00361578(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361580__FPv);
#ifdef SKIP_ASM
void func_00361580(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361588__FPv);
#ifdef SKIP_ASM
void func_00361588(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361590__FPv);
#ifdef SKIP_ASM
void func_00361590(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361598__FPv);
#ifdef SKIP_ASM
int func_00361598(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003615A0__FPv);
#ifdef SKIP_ASM
int func_003615A0(void* self)
{
    return 0x1;
}
#endif

// 0x50-byte elements reached through a pointer at self+0x70; indexing the
// real element type is what reproduces the target's addu operand order
struct sRailEntry50 {
    char pad_0x00[0x44];
    int field_0x44;
    char pad_0x48[8];
};

//100%
INCLUDE_ASM("object/railmodifier", func_003615A8);
#ifdef SKIP_ASM
extern "C" int func_003615A8(void* self, int a1)
{
    sRailEntry50* p = *(sRailEntry50**)((char*)self + 0x70);
    return p[a1].field_0x44;
}
#endif

struct sRailEntry60 {
    char pad_0x00[0x54];
    int field_0x54;
    char pad_0x58[8];
};

//100%
INCLUDE_ASM("object/railmodifier", func_003615C0);
#ifdef SKIP_ASM
extern "C" int func_003615C0(void* self, int a1)
{
    sRailEntry60* p = *(sRailEntry60**)((char*)self + 0x70);
    return p[a1].field_0x54;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361768__FPv);
#ifdef SKIP_ASM
void* func_00361768(void* self)
{
    return (char*)self + 0x2C;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361770__FPv);
#ifdef SKIP_ASM
int func_00361770(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361778);
#ifdef SKIP_ASM
extern "C" int func_00352B88(void* p);

extern "C" int func_00361778(void* self)
{
    void* p = *(void**)((char*)self + 0x1C);
    if (p != 0) {
        return func_00352B88(p);
    }
    return *(int*)((char*)self + 0x78);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003617B0__FPv);
#ifdef SKIP_ASM
int func_003617B0(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003617B8);
#ifdef SKIP_ASM
struct sRailVEntry17B8 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" int func_003617B8(void* self)
{
    if (*(unsigned short*)((char*)self + 0x12) & 1) {
        sRailVEntry17B8* vt = *(sRailVEntry17B8**)((char*)self + 0xC);
        vt[51].fn((char*)self + vt[51].delta);
    }
    return *(int*)((char*)self + 0x74);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361800);
#ifdef SKIP_ASM
struct sVEntry00361800 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sElem00361800 {
    char data[0x40];
};

extern "C" sElem00361800* func_00361800(void* self, int i)
{
    if (*(unsigned short*)((char*)self + 0x12) & 1) {
        sVEntry00361800* vt = *(sVEntry00361800**)((char*)self + 0xC);
        vt[51].fn((char*)self + vt[51].delta);
    }
    return &(*(sElem00361800**)((char*)self + 0x74))[i];
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361858);
#ifdef SKIP_ASM
struct sRmVEntryP1858 {
    short delta;
    short index;
    void* (*fn)(void*);
};

struct sRmVEntry2_1858 {
    short delta;
    short index;
    void (*fn)(void*, void*, void*);
};

struct sRmVtbl1858 {
    sRmVEntryP1858 pad[24];
    sRmVEntryP1858 get;      // slot 24 (0xC0)
    sRmVEntryP1858 pad2[8];
    sRmVEntry2_1858 set;     // slot 33 (0x108)
};

extern "C" void func_00361858(void* self)
{
    sRmVtbl1858* vt = *(sRmVtbl1858**)((char*)self + 0xC);
    void* obj = (char*)self + vt->set.delta;
    void* r = vt->get.fn((char*)self + vt->get.delta);
    vt->set.fn(obj, r, *(void**)((char*)self + 0x74));
    *(unsigned short*)((char*)self + 0x12) &= ~1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003618C8);
#ifdef SKIP_ASM
extern void* D_004913F8[];
void operator_delete(int*);

extern "C" void func_003618C8(void* self, int flags)
{
    *(void***)self = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003618F8__FPv);
#ifdef SKIP_ASM
void func_003618F8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361900__FPv);
#ifdef SKIP_ASM
int func_00361900(void* self)
{
    return *(int*)((char*)self + 0x44);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361908__FPv);
#ifdef SKIP_ASM
int func_00361908(void* self)
{
    return 0x3;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361910__FPv);
#ifdef SKIP_ASM
void* func_00361910(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361918);
#ifdef SKIP_ASM
extern "C" void func_00361918(void* self, void* a1)
{
    *(cQuad128*)((char*)self + 0x10) = *(cQuad128*)a1;
    *(cQuad128*)((char*)self + 0x20) = *(cQuad128*)((char*)a1 + 0x10);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361930__FPv);
#ifdef SKIP_ASM
float func_00361930(void* self)
{
    return *(float*)((char*)self + 0x40);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361938__FPvf);
#ifdef SKIP_ASM
void func_00361938(void* self, float val)
{
    *(float*)((char*)self + 0x40) = val;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361940);
#ifdef SKIP_ASM
struct sRailVEntry1940 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void* func_00361940(void* self)
{
    if (*(int*)((char*)self + 0x44) != 0) {
        sRailVEntry1940* vt = *(sRailVEntry1940**)self;
        vt[3].fn((char*)self + vt[3].delta);
    }
    return (char*)self + 0x50;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361988);
#ifdef SKIP_ASM
extern void* D_004913F8[];
void operator_delete(int*);

extern "C" void func_00361988(void* self, int flags)
{
    *(void***)self = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003619B8__FPv);
#ifdef SKIP_ASM
void func_003619B8(void* self)
{
    *(int*)((char*)self + 0x44) = 1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003619C8__FPv);
#ifdef SKIP_ASM
int func_003619C8(void* self)
{
    return *(int*)((char*)self + 0x90);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003619D0__FPv);
#ifdef SKIP_ASM
int func_003619D0(void* self)
{
    return 0x4;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003619E0);
#ifdef SKIP_ASM
extern void* D_004913F8[];
void operator_delete(int*);

extern "C" void func_003619E0(void* self, int flags)
{
    *(void***)self = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A10__FPv);
#ifdef SKIP_ASM
int func_00361A10(void* self)
{
    return (*(int*)((char*)self + 0x50) != 0);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A20__FPv);
#ifdef SKIP_ASM
int func_00361A20(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A28__FPv);
#ifdef SKIP_ASM
void* func_00361A28(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A30);
#ifdef SKIP_ASM
extern "C" void func_00361A30(void* self, void* a1)
{
    *(cQuad128*)((char*)self + 0x20) = *(cQuad128*)a1;
    *(cQuad128*)((char*)self + 0x30) = *(cQuad128*)((char*)a1 + 0x10);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A48__FPv);
#ifdef SKIP_ASM
float func_00361A48(void* self)
{
    return *(float*)((char*)self + 0x40);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A50__FPv);
#ifdef SKIP_ASM
void func_00361A50(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A58__FPv);
#ifdef SKIP_ASM
int func_00361A58(void* self)
{
    return 0x6;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361A60);
#ifdef SKIP_ASM
struct sRailVEntry1A60 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void* func_00361A60(void* self)
{
    if (*(int*)((char*)self + 0x50) != 0) {
        sRailVEntry1A60* vt = *(sRailVEntry1A60**)self;
        vt[3].fn((char*)self + vt[3].delta);
    }
    return (char*)self + 0x60;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361AA8);
#ifdef SKIP_ASM
extern void* D_004913F8[];
void operator_delete(int*);

extern "C" void func_00361AA8(void* self, int flags)
{
    *(void***)self = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361AD8__FPv);
#ifdef SKIP_ASM
void* func_00361AD8(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361AE0);
#ifdef SKIP_ASM
extern "C" void func_00361AE0(void* self, void* a1)
{
    *(cQuad128*)((char*)self + 0x10) = *(cQuad128*)a1;
    *(cQuad128*)((char*)self + 0x20) = *(cQuad128*)((char*)a1 + 0x10);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361AF8__FPv);
#ifdef SKIP_ASM
float func_00361AF8(void* self)
{
    return *(float*)((char*)self + 0x30);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B00__FPvf);
#ifdef SKIP_ASM
void func_00361B00(void* self, float val)
{
    *(float*)((char*)self + 0x30) = val;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B08__FPv);
#ifdef SKIP_ASM
int func_00361B08(void* self)
{
    return 0x7;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B10__FPv);
#ifdef SKIP_ASM
void* func_00361B10(void* self)
{
    return (char*)self + 0x40;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B18);
#ifdef SKIP_ASM
extern void* D_004913F8[];
void operator_delete(int*);

extern "C" void func_00361B18(void* self, int flags)
{
    *(void***)self = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B48__FPv);
#ifdef SKIP_ASM
int func_00361B48(void* self)
{
    return *(int*)((char*)self + 0x50);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B50__FPv);
#ifdef SKIP_ASM
void func_00361B50(void* self)
{
    *(int*)((char*)self + 0x50) = 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B58__FPv);
#ifdef SKIP_ASM
void* func_00361B58(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B60);
#ifdef SKIP_ASM
extern "C" void func_00361B60(void* self, void* a1)
{
    *(cQuad128*)((char*)self + 0x10) = *(cQuad128*)a1;
    *(cQuad128*)((char*)self + 0x20) = *(cQuad128*)((char*)a1 + 0x10);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B78__FPv);
#ifdef SKIP_ASM
float func_00361B78(void* self)
{
    return *(float*)((char*)self + 0x4C);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B80__FPvf);
#ifdef SKIP_ASM
void func_00361B80(void* self, float val)
{
    *(float*)((char*)self + 0x4C) = val;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B88__FPv);
#ifdef SKIP_ASM
int func_00361B88(void* self)
{
    return *(int*)((char*)self + 0x58);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361B90);
#ifdef SKIP_ASM
struct sRailVEntry1B90 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void* func_00361B90(void* self)
{
    if (*(int*)((char*)self + 0x58) != 0) {
        sRailVEntry1B90* vt = *(sRailVEntry1B90**)self;
        vt[3].fn((char*)self + vt[3].delta);
    }
    return (char*)self + 0x60;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361BD8__FPv);
#ifdef SKIP_ASM
int func_00361BD8(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361BE0__FPv);
#ifdef SKIP_ASM
void* func_00361BE0(void* self)
{
    return (char*)*(void**)((char*)self + 0x3c) + 0x30;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361BF0);
#ifdef SKIP_ASM
extern "C" void func_00361BF0(void* self, void* a1)
{
    void* p = *(void**)((char*)self + 0x3c);
    *(cQuad128*)((char*)p + 0x30) = *(cQuad128*)a1;
    *(cQuad128*)((char*)p + 0x40) = *(cQuad128*)((char*)a1 + 0x10);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361C10__FPv);
#ifdef SKIP_ASM
float func_00361C10(void* self)
{
    return *(float*)((char*)self + 0x18);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361C18__FPvf);
#ifdef SKIP_ASM
void func_00361C18(void* self, float val)
{
    *(float*)((char*)self + 0x18) = val;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361C20);
#ifdef SKIP_ASM
struct sRailVEntry1C20 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void* func_00361C20(void* self)
{
    if (*(int*)((char*)self + 0x30) != 0) {
        sRailVEntry1C20* vt = *(sRailVEntry1C20**)self;
        vt[3].fn((char*)self + vt[3].delta);
    }
    return **(char***)((char*)self + 0x44) + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361C70__FPv);
#ifdef SKIP_ASM
int func_00361C70(void* self)
{
    return 0x2;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361C78);
#ifdef SKIP_ASM
extern void* D_004913F8[];
void operator_delete(int*);

extern "C" void func_00361C78(void* self, int flags)
{
    *(void***)self = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361CA8__FPv);
#ifdef SKIP_ASM
int func_00361CA8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361CB0);
#ifdef SKIP_ASM
extern "C" int func_00361CB0(void* self)
{
    return *(float*)((char*)self + 0x20) >= 17.0f;
}
#endif

extern "C" void* func_0035DDE8(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00361CD8__FPv);
#ifdef SKIP_ASM
void* func_00361CD8(void* self)
{
    *(int*)((char*)self + 0x20) = 0;
    return func_0035DDE8(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361CF8__FPv);
#ifdef SKIP_ASM
int func_00361CF8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D00);
#ifdef SKIP_ASM
extern "C" void func_00361D00(void* self, void* a1)
{
    *(cQuad128*)((char*)self + 0x220) = *(cQuad128*)a1;
    *(cQuad128*)((char*)self + 0x230) = *(cQuad128*)((char*)a1 + 0x10);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D18__FPv);
#ifdef SKIP_ASM
void* func_00361D18(void* self)
{
    return (char*)self + 0x220;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D20__FPv);
#ifdef SKIP_ASM
float func_00361D20(void* self)
{
    return *(float*)((char*)self + 0x24);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D28__FPvf);
#ifdef SKIP_ASM
void func_00361D28(void* self, float val)
{
    *(float*)((char*)self + 0x24) = val;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D30__FPv);
#ifdef SKIP_ASM
void* func_00361D30(void* self)
{
    return (char*)self + 0x240;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D38__FPv);
#ifdef SKIP_ASM
void* func_00361D38(void* self)
{
    return (char*)self + 0x240;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D40__FPv);
#ifdef SKIP_ASM
int func_00361D40(void* self)
{
    return 0x5;
}
#endif

extern void* D_0048EE60[];
extern "C" void* func_003553C0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00361D50__FPv);
#ifdef SKIP_ASM
void* func_00361D50(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_0048EE60;
    return func_003553C0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D78);
#ifdef SKIP_ASM
extern "C" unsigned int func_00361D78()
{
    return 0xFFFFFFFFU;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D88__FPv);
#ifdef SKIP_ASM
void* func_00361D88(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361D90);
#ifdef SKIP_ASM
extern "C" int func_00361D90(void* self)
{
    int r;
    if (*(signed char*)((char*)self + 0x14) != 0) {
        r = -1;
        if (*(float*)((char*)self + 0x0) >= 0.0f) {
            r = 1;
        }
        return r;
    }
    r = -1;
    if (*(float*)((char*)self + 0x28) >= 0.0f) {
        r = 1;
    }
    return r;
}
#endif

extern void* D_0048EA70[];
extern "C" void* func_00341CF0(void*);

//100%
INCLUDE_ASM("object/railmodifier", func_00361DE0__FPv);
#ifdef SKIP_ASM
void* func_00361DE0(void* self)
{
    *(int*)((char*)self + 0x3c) = (int)(void*)D_0048EA70;
    return func_00341CF0(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361E08__FPv);
#ifdef SKIP_ASM
void* func_00361E08(void* self)
{
    return self;
}
#endif

extern "C" void* func_0035FE10(int, int);

//99.38%
INCLUDE_ASM("object/railmodifier", func_00361E10__FPv);
#ifdef SKIP_ASM
void* func_00361E10(void* self)
{
    return func_0035FE10(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361E30);
#ifdef SKIP_ASM
extern "C" int func_00362340(void);
extern "C" int func_003623A8(void);
extern "C" void func_00361F98(void* self, int cause, int (*handler)(void), int arg);

extern "C" void func_00361E30(void* self)
{
    func_00361F98(self, 5, func_00362340, 0);
    func_00361F98(self, 7, func_003623A8, 0);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361E80);
#ifdef SKIP_ASM
extern "C" void* func_00362008(void* self, int id);

extern "C" void* func_00361E80(void* self)
{
    func_00362008(self, 5);
    return func_00362008(self, 7);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_00361EB8);
#ifdef SKIP_ASM
struct sRailPairs;
extern "C" void func_00361F60(sRailPairs* self);
extern "C" void func_00361E30(void* self);

static inline void func_00361EB8_fill(int* p, int v)
{
    int i;
    for (i = 15; i >= 0; i--) {
        p[i] = v;
    }
}

extern "C" void func_00361EB8(void* self)
{
    func_00361EB8_fill((int*)self, -1);
    func_00361EB8_fill((int*)((char*)self + 0x40), -1);
    func_00361F60((sRailPairs*)self);
    func_00361E30(self);
}
#endif

extern "C" void* func_00361E80(void* self);

//99.29%
INCLUDE_ASM("object/railmodifier", func_00361F40__FPv);
#ifdef SKIP_ASM
void* func_00361F40(void* self)
{
    return func_00361E80(self);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361F60);
#ifdef SKIP_ASM
struct sRailPair {
    int a;
    int b;
};

struct sRailPairs {
    char pad_0x00[0x80];
    sRailPair pairs[3];
};

extern "C" void func_00361F60(sRailPairs* self)
{
    int i;
    for (i = 0; i < 3; i++) {
        self->pairs[i].a = 0;
        self->pairs[i].b = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361F90__FPv);
#ifdef SKIP_ASM
void func_00361F90(void* self)
{
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00361F98);
#ifdef SKIP_ASM
extern "C" int func_00424880(int ch);
extern "C" int func_00423A80(int cause, int (*handler)(void), int arg);
extern "C" int func_004248E8(int ch);

extern "C" void func_00361F98(void* self, int cause, int (*handler)(void), int arg)
{
    func_00424880(cause);
    *(int*)((char*)self + (cause << 2)) = func_00423A80(cause, handler, arg);
    func_004248E8(cause);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00362008);
#ifdef SKIP_ASM
extern "C" int func_00424880(int ch);
extern "C" void* func_00423AA0(int ch, int id);

extern "C" void* func_00362008(void* self, int ch)
{
    func_00424880(ch);
    int* p = (int*)((char*)self + (ch << 2));
    int id = *p;
    *p = -1;
    return func_00423AA0(ch, id);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00362120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (dump all 32 FPU registers as 64-bit words into buf).
extern "C" void func_00362120(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "por       $2, $0, $0\n"
        "mfc1      $2, $f0\n"
        "sd        $2, 0x0(%0)\n"
        "mfc1      $2, $f1\n"
        "sd        $2, 0x8(%0)\n"
        "mfc1      $2, $f2\n"
        "sd        $2, 0x10(%0)\n"
        "mfc1      $2, $f3\n"
        "sd        $2, 0x18(%0)\n"
        "mfc1      $2, $f4\n"
        "sd        $2, 0x20(%0)\n"
        "mfc1      $2, $f5\n"
        "sd        $2, 0x28(%0)\n"
        "mfc1      $2, $f6\n"
        "sd        $2, 0x30(%0)\n"
        "mfc1      $2, $f7\n"
        "sd        $2, 0x38(%0)\n"
        "mfc1      $2, $f8\n"
        "sd        $2, 0x40(%0)\n"
        "mfc1      $2, $f9\n"
        "sd        $2, 0x48(%0)\n"
        "mfc1      $2, $f10\n"
        "sd        $2, 0x50(%0)\n"
        "mfc1      $2, $f11\n"
        "sd        $2, 0x58(%0)\n"
        "mfc1      $2, $f12\n"
        "sd        $2, 0x60(%0)\n"
        "mfc1      $2, $f13\n"
        "sd        $2, 0x68(%0)\n"
        "mfc1      $2, $f14\n"
        "sd        $2, 0x70(%0)\n"
        "mfc1      $2, $f15\n"
        "sd        $2, 0x78(%0)\n"
        "mfc1      $2, $f16\n"
        "sd        $2, 0x80(%0)\n"
        "mfc1      $2, $f17\n"
        "sd        $2, 0x88(%0)\n"
        "mfc1      $2, $f18\n"
        "sd        $2, 0x90(%0)\n"
        "mfc1      $2, $f19\n"
        "sd        $2, 0x98(%0)\n"
        "mfc1      $2, $f20\n"
        "sd        $2, 0xA0(%0)\n"
        "mfc1      $2, $f21\n"
        "sd        $2, 0xA8(%0)\n"
        "mfc1      $2, $f22\n"
        "sd        $2, 0xB0(%0)\n"
        "mfc1      $2, $f23\n"
        "sd        $2, 0xB8(%0)\n"
        "mfc1      $2, $f24\n"
        "sd        $2, 0xC0(%0)\n"
        "mfc1      $2, $f25\n"
        "sd        $2, 0xC8(%0)\n"
        "mfc1      $2, $f26\n"
        "sd        $2, 0xD0(%0)\n"
        "mfc1      $2, $f27\n"
        "sd        $2, 0xD8(%0)\n"
        "mfc1      $2, $f28\n"
        "sd        $2, 0xE0(%0)\n"
        "mfc1      $2, $f29\n"
        "sd        $2, 0xE8(%0)\n"
        "mfc1      $2, $f30\n"
        "sd        $2, 0xF0(%0)\n"
        "mfc1      $2, $f31\n"
        "sd        $2, 0xF8(%0)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$2", "memory");
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00362230);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (reload all 32 FPU registers from buf; deliberately
// no FPU clobbers so the compiler doesn't save/restore $f20-$f31 around it).
extern "C" void func_00362230(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "por       $2, $0, $0\n"
        "ld        $2, 0x0(%0)\n"
        "mtc1      $2, $f0\n"
        "ld        $2, 0x8(%0)\n"
        "mtc1      $2, $f1\n"
        "ld        $2, 0x10(%0)\n"
        "mtc1      $2, $f2\n"
        "ld        $2, 0x18(%0)\n"
        "mtc1      $2, $f3\n"
        "ld        $2, 0x20(%0)\n"
        "mtc1      $2, $f4\n"
        "ld        $2, 0x28(%0)\n"
        "mtc1      $2, $f5\n"
        "ld        $2, 0x30(%0)\n"
        "mtc1      $2, $f6\n"
        "ld        $2, 0x38(%0)\n"
        "mtc1      $2, $f7\n"
        "ld        $2, 0x40(%0)\n"
        "mtc1      $2, $f8\n"
        "ld        $2, 0x48(%0)\n"
        "mtc1      $2, $f9\n"
        "ld        $2, 0x50(%0)\n"
        "mtc1      $2, $f10\n"
        "ld        $2, 0x58(%0)\n"
        "mtc1      $2, $f11\n"
        "ld        $2, 0x60(%0)\n"
        "mtc1      $2, $f12\n"
        "ld        $2, 0x68(%0)\n"
        "mtc1      $2, $f13\n"
        "ld        $2, 0x70(%0)\n"
        "mtc1      $2, $f14\n"
        "ld        $2, 0x78(%0)\n"
        "mtc1      $2, $f15\n"
        "ld        $2, 0x80(%0)\n"
        "mtc1      $2, $f16\n"
        "ld        $2, 0x88(%0)\n"
        "mtc1      $2, $f17\n"
        "ld        $2, 0x90(%0)\n"
        "mtc1      $2, $f18\n"
        "ld        $2, 0x98(%0)\n"
        "mtc1      $2, $f19\n"
        "ld        $2, 0xA0(%0)\n"
        "mtc1      $2, $f20\n"
        "ld        $2, 0xA8(%0)\n"
        "mtc1      $2, $f21\n"
        "ld        $2, 0xB0(%0)\n"
        "mtc1      $2, $f22\n"
        "ld        $2, 0xB8(%0)\n"
        "mtc1      $2, $f23\n"
        "ld        $2, 0xC0(%0)\n"
        "mtc1      $2, $f24\n"
        "ld        $2, 0xC8(%0)\n"
        "mtc1      $2, $f25\n"
        "ld        $2, 0xD0(%0)\n"
        "mtc1      $2, $f26\n"
        "ld        $2, 0xD8(%0)\n"
        "mtc1      $2, $f27\n"
        "ld        $2, 0xE0(%0)\n"
        "mtc1      $2, $f28\n"
        "ld        $2, 0xE8(%0)\n"
        "mtc1      $2, $f29\n"
        "ld        $2, 0xF0(%0)\n"
        "mtc1      $2, $f30\n"
        "ld        $2, 0xF8(%0)\n"
        "mtc1      $2, $f31\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$2", "memory");
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_00362340);
#ifdef SKIP_ASM
extern "C" void func_00362120(void*);
extern "C" void func_00362230(void*);

struct sIntcStats00362340 {
    char pad_0x00[0x80];
    int count;
};
extern sIntcStats00362340 D_005059D8;

extern "C" int func_00362340(void)
{
    char buf[0x100];
    func_00362120(buf);
    sIntcStats00362340* stats = &D_005059D8;
    if (*(int*)0x10003C00 & 0x400) {
        *(volatile int*)0x10003C10 = 8;
    }
    stats->count++;
    func_00362230(buf);
    // PORT: PS2-only: re-enable interrupts (EI).
    __asm__ __volatile__("sync.l\n\tei");
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_003623A8);
#ifdef SKIP_ASM
extern "C" void func_00362120(void*);
extern "C" void func_00362230(void*);

extern "C" int func_003623A8(void)
{
    char buf[0x100];
    func_00362120(buf);
    func_00362230(buf);
    // PORT: PS2-only: re-enable interrupts (EI).
    __asm__ __volatile__("sync.l\n\tei");
    return 1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003623D8);
#ifdef SKIP_ASM
struct sGifPacket {
    int qwc;        // 0x0
    ulong* cur;     // 0x4
};

// PORT: 64-bit GS register writes (ulong).
extern "C" void func_003623D8(sGifPacket* pkt, int x, int w, int y, int h)
{
    ulong scissor = (ulong)x | ((ulong)(x + (w - 1)) << 16) | ((ulong)y << 32) | ((ulong)(y + (h - 1)) << 48);
    pkt->cur[0] = scissor;
    pkt->cur[1] = 0x40;
    pkt->cur[2] = scissor;
    pkt->cur[3] = 0x41;
    pkt->cur += 4;
    pkt->qwc += 2;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00362478);
#ifdef SKIP_ASM
// PORT: 64-bit GS register writes (ulong).
// Emits one GS ALPHA register write (0x42 for context 1, 0x43 for context 2) for the given blend mode.
extern "C" void func_00362478(sGifPacket* pkt, int mode, int fix, int ctx)
{
    switch (ctx) {
    case 0:
        pkt->cur[1] = 0x42;
        break;
    case 1:
        pkt->cur[1] = 0x43;
        break;
    default:
        pkt->cur[1] = 0x42;
        break;
    }
    switch (mode) {
    case 0: pkt->cur[0] = 0xAA; break;
    case 1: pkt->cur[0] = 0x2A; break;
    case 5: pkt->cur[0] = 0x44; break;
    case 6: pkt->cur[0] = 0x46; break;
    case 7: pkt->cur[0] = 0x48; break;
    case 8: pkt->cur[0] = 0x81; break;
    case 9: pkt->cur[0] = 0x42; break;
    case 4: pkt->cur[0] = 0x89; break;
    case 3: pkt->cur[0] = 0x6A; break;
    case 11: pkt->cur[0] = ((ulong)fix << 32) | 0x64; break;
    case 12: pkt->cur[0] = ((ulong)fix << 32) | 0x68; break;
    case 13:
    case 14: pkt->cur[0] = ((ulong)fix << 32) | 0x88; break;
    case 2: pkt->cur[0] = ((ulong)0x80 << 32) | 0x68; break;
    case 16: pkt->cur[0] = 0x98; break;
    case 17: pkt->cur[0] = 0x58; break;
    case 10:
    case 21: pkt->cur[0] = 0x49; break;
    case 15:
    case 18:
    case 19:
    case 20:
        break;
    }
    pkt->cur += 2;
    pkt->qwc++;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003625C0);
#ifdef SKIP_ASM
// PORT: 64-bit GS register writes (ulong).
extern "C" void func_003625C0(sGifPacket* pkt, int mode, int ctx)
{
    ulong reg;
    switch (ctx) {
    case 0:
        reg = 8;
        break;
    case 1:
        reg = 9;
        break;
    default:
        reg = 8;
        break;
    }
    switch (mode) {
    case 3:
        pkt->cur[0] = 5;
        break;
    case 1:
        pkt->cur[0] = 4;
        break;
    case 2:
        pkt->cur[0] = 1;
        break;
    default:
        pkt->cur[0] = 0;
        break;
    }
    pkt->cur[1] = reg;
    pkt->cur += 2;
    pkt->qwc++;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00362660);
#ifdef SKIP_ASM
// PORT: 64-bit GS register writes (ulong).
extern "C" void func_00362660(sGifPacket* pkt, unsigned int zbp, unsigned int psm, int zmsk, int ctx)
{
    ulong reg;
    switch (ctx) {
    case 0:
        reg = 0x4E;
        break;
    case 1:
        reg = 0x4F;
        break;
    default:
        reg = 0x4E;
        break;
    }
    pkt->cur[0] = (ulong)zbp | ((ulong)(psm - 0x30) << 24) | ((zmsk == 1) ? ((ulong)1 << 32) : 0);
    pkt->cur[1] = reg;
    pkt->cur += 2;
    pkt->qwc++;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003626D8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sRmGsPacket {
    int count;      // 0x0
    ulong* ptr;     // 0x4
};

// GS TEST register (TEST_1 = 0x47, TEST_2 = 0x48), as in libgraph's SCE_GS_SET_TEST.
extern "C" void func_003626D8(sRmGsPacket* pkt, int ztest, int atest, unsigned int aref, int ctx)
{
    ulong reg;
    int atst;
    int ztst;

    switch (ctx) {
    case 0:
        reg = 0x47;
        break;
    case 1:
        reg = 0x48;
        break;
    default:
        reg = 0x47;
        break;
    }

    switch (atest) {
    case 0:
    case 1:
        atst = 1;
        break;
    case 2:
        atst = 2;
        break;
    case 3:
        atst = 6;
        break;
    default:
        atst = 1;
        break;
    }

    ztst = 1;
    switch (ztest) {
    case 1:
        ztst = 2;
        break;
    case 0:
        ztst = 3;
        break;
    case 2:
        break;
    }

    pkt->ptr[0] = (ulong)1 | ((ulong)atst << 1) | ((ulong)aref << 4) | ((ulong)1 << 12)
                | ((ulong)0 << 14) | ((ulong)0 << 15) | ((ulong)1 << 16) | ((ulong)ztst << 17);
    pkt->ptr[1] = reg;
    pkt->ptr += 2;
    pkt->count++;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003627A8);
#ifdef SKIP_ASM
extern ulong D_00505A80[];

struct sRmPkt27A8 {
    int count;      // 0x0
    ulong* cur;     // 0x4
    ulong* base;    // 0x8
};

// PORT: 64-bit DMA/VIF/GIF tag writes (ulong) and addresses held in int.
extern "C" void func_003627A8(sRmPkt27A8* self, ulong** pp, int mode)
{
    if (self->count == 0) {
        return;
    }
    switch (mode) {
    case 0:
        self->cur = D_00505A80;
        self->cur[0] = (self->count + 2) | 0x60000000;
        self->cur[1] = 0;
        self->cur[2] = 0;
        self->cur[3] = (ulong)(unsigned int)((self->count + 1) | 0x50000000) << 32;
        self->cur[4] = (ulong)(self->count | 0x8000) | ((ulong)1 << 60);
        self->cur[5] = 0xE;
        self->cur += 6;
        (*pp)[0] = ((ulong)(unsigned int)D_00505A80 << 32) | 0x50000000;
        (*pp)[1] = 0;
        *pp += 2;
        break;
    case 1:
        *pp = self->cur;
        self->cur = self->base;
        self->cur[0] = (self->count + 2) | 0x10000000;
        self->cur[1] = 0;
        self->cur[2] = 0;
        self->cur[3] = (ulong)(unsigned int)((self->count + 1) | 0x50000000) << 32;
        self->cur[4] = (ulong)(self->count | 0x8000) | ((ulong)1 << 60);
        self->cur[5] = 0xE;
        self->cur += 6;
        break;
    case 2:
        *pp = self->cur;
        self->cur = self->base;
        self->cur[0] = (self->count + 2) | 0x10000000;
        self->cur[1] = 0;
        self->cur[2] = 0;
        self->cur[3] = (ulong)(unsigned int)(((self->count + 1) << 16) | 0x6C0003F2) << 32;
        self->cur[4] = (ulong)(self->count | 0x8000) | ((ulong)1 << 60);
        self->cur[5] = 0xE;
        self->cur += 6;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00362978);
#ifdef SKIP_ASM
// Append a DMA packet to a chain: the first one becomes the head, later ones are
// linked by patching the previous tail's tag (via the uncached-accelerated
// mirror, | 0x30000000) into a NEXT tag pointing at the new packet.
// PORT: 64-bit DMA tag writes (ulong) and addresses held in int.
extern "C" void func_00362978(void* self, int packet, int tail)
{
    if (*(int*)((char*)self + 0xc) != 0) {
        ulong* tag = (ulong*)(*(int*)((char*)self + 0x10) | 0x30000000);
        tag[0] = ((ulong)packet << 32) | 0x20000000;
        tag[1] = 0;
        *(int*)((char*)self + 0x10) = tail;
    } else {
        *(int*)((char*)self + 0xc) = packet;
        *(int*)((char*)self + 0x10) = tail;
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003629B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00362CC8(char* self);

struct sRmState_29B8 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    short tex[2];
};

struct sRmCtx_29B8 {
    char pad0[0xE84];
    sRmState_29B8* top;     // 0xE84
};

struct sRmSaved_29B8 {
    sRmState_29B8 st;
    int pad;
};

struct sRmBatch_29B8 {
    char pad_0x0[0x51480];
    int count;                      // 0x51480
    sRmSaved_29B8 saved[1024];      // 0x51484
    int base;                       // 0x57484
    sRmSaved_29B8* a;               // 0x57488
    sRmSaved_29B8* b;               // 0x5748C
    sRmSaved_29B8* c;               // 0x57490
};

extern sRmCtx_29B8* D_004A5B80_29B8 __asm__("D_004A5B80");
extern sRmState_29B8 D_00501420_29B8 __asm__("D_00501420");

static inline void set0_29B8(sRmCtx_29B8* ctx, unsigned int mask, int shift, unsigned int v)
{
    ctx->top->w0 = (ctx->top->w0 & ~mask) | ((v << shift) & mask);
}

static inline void set1_29B8(sRmCtx_29B8* ctx, unsigned int mask, int shift, unsigned int v)
{
    ctx->top->w1 = (ctx->top->w1 & ~mask) | ((v << shift) & mask);
}

static inline void set2_29B8(sRmCtx_29B8* ctx, unsigned int mask, int shift, unsigned int v)
{
    ctx->top->w2 = (ctx->top->w2 & ~mask) | ((v << shift) & mask);
}

static inline sRmSaved_29B8* save_29B8(sRmBatch_29B8* self, sRmCtx_29B8* ctx)
{
    sRmState_29B8* src = ctx->top;
    sRmSaved_29B8* d = &self->saved[self->count++];
    d->st = *src;
    return d;
}

extern "C" void func_003629B8(sRmBatch_29B8* self)
{
    self->base = 0;
    func_00362CC8((char*)self);
    sRmCtx_29B8* ctx = D_004A5B80_29B8;
    *ctx->top = D_00501420_29B8;
    set1_29B8(ctx, 0x3, 0, 0);
    set2_29B8(ctx, 0x1FFFFC00, 10, 0);
    set1_29B8(ctx, 0x1800000, 23, 1);
    set1_29B8(ctx, 0x300000, 20, 0);
    set1_29B8(ctx, 0xFF000, 12, 0x14);
    set0_29B8(ctx, 0x30, 4, 3);
    set0_29B8(ctx, 0x3C0, 6, 3);
    set1_29B8(ctx, 0x7C, 2, 1);
    set1_29B8(ctx, 0xF80, 7, 0x11);
    self->a = save_29B8(self, ctx);
    set1_29B8(ctx, 0xF80, 7, 2);
    self->b = save_29B8(self, ctx);
    set1_29B8(ctx, 0x7C, 2, 5);
    set1_29B8(ctx, 0xF80, 7, 3);
    set1_29B8(ctx, 0x3, 0, 1);
    set2_29B8(ctx, 0x1FFFFC00, 10, 0);
    set1_29B8(ctx, 0x1800000, 23, 1);
    set1_29B8(ctx, 0x300000, 20, 3);
    set1_29B8(ctx, 0xFF000, 12, 0x5C);
    self->c = save_29B8(self, ctx);
    self->base = self->count;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00362CC8);
#ifdef SKIP_ASM
extern "C" void func_004247D8(void* begin, void* end);
extern "C" void func_0038F738(void* base, int size, int mode);
extern "C" void func_003E6448(void* dst, int c, int n);
extern void* D_004A5B84;

struct sRail20_2CC8 {
    int v[5];
};

extern sRail20_2CC8 D_00501420;

extern "C" void func_00362CC8(char* self)
{
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x57494) = 0;
    *(int*)(self + 0x51480) = *(int*)(self + 0x57484);
    char* a = self + 0x674A0;
    func_004247D8(a, self + 0x6789F);
    char* b = self + 0x678A0;
    func_004247D8(b, self + 0x67C9F);
    func_003E6448(D_004A5B84, 0, 0x400);
    func_0038F738(a, 0x400, 2);
    func_0038F738(b, 0x400, 2);
    *(int*)(self + 0x67CA4) = 0;
    sRail20_2CC8* d = (sRail20_2CC8*)(self + 0x69CA8);
    *d = D_00501420;
    *(int*)(self + 0x6AED0) = 0;
    *(int*)(self + 0x69CC0) = -1;
    *(int*)(self + 0x69CC8) = 0;
    *(int*)(self + 0x69CC4) = -1;
}
#endif

INCLUDE_ASM("object/railmodifier", func_00362DE8);

INCLUDE_ASM("object/railmodifier", func_00363490);

INCLUDE_ASM("object/railmodifier", func_00363C20);

//100%
INCLUDE_ASM("object/railmodifier", func_00364050);
#ifdef SKIP_ASM
struct sRmSortItem4050 {
    unsigned int key;
    int val;
};

extern sRmSortItem4050 D_00505B70[];
extern void* D_004A4474;
extern "C" void* func_0038F460(void* ring, unsigned int addr, int size, int flags);
extern "C" void func_0038F6A8(void* ring);

// 4-pass 8-bit radix sort of the item list at self+0x67CA8 (count at +0x67CA4).
extern "C" void func_00364050(char* self)
{
    void* ring = D_004A4474;
    sRmSortItem4050* dst = D_00505B70;
    int n = *(int*)(self + 0x67CA4);
    sRmSortItem4050* src = (sRmSortItem4050*)(self + 0x67CA8);
    int (*hist)[257] = (int (*)[257])func_0038F460(ring, 0, -1, 0);
    func_003E6448(hist, 0, 0x1010);
    for (int i = 0; i < n; i++) {
        unsigned int key = src[i].key;
        hist[0][(key & 0xFF) + 1]++;
        hist[1][((key >> 8) & 0xFF) + 1]++;
        hist[2][((key >> 16) & 0xFF) + 1]++;
        hist[3][(key >> 24) + 1]++;
    }
    for (int i = 1; i < 256; i++) {
        hist[0][i] += hist[0][i - 1];
        hist[1][i] += hist[1][i - 1];
        hist[2][i] += hist[2][i - 1];
        hist[3][i] += hist[3][i - 1];
    }
    int shift;
    for (shift = 0; shift < 32; shift += 8) {
        int* h = (int*)hist + ((shift << 5) + (shift >> 3));
        for (int i = 0; i < n; i++) {
            int idx = h[(src[i].key >> shift) & 0xFF]++;
            dst[idx] = src[i];
        }
        sRmSortItem4050* t = dst;
        dst = src;
        src = t;
    }
    func_0038F6A8(ring);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00364240);
#ifdef SKIP_ASM
// Packs the rail's blend/test state into a negated register word.
extern "C" unsigned int func_00364240(unsigned int* self, int key)
{
    int a = 31 - ((self[2] & 0x3E0) >> 5);
    int b;
    int sel = self[1] & 3;
    switch (sel) {
    case 0:
        b = 0x3FF;
        break;
    case 1:
        b = 0x3FE;
        break;
    case 2:
        b = (self[2] & 0x1FFFFC00) >> 10;
        break;
    default:
        b = 0;
        break;
    }
    int c;
    switch ((self[0] & 0x3C0) >> 6) {
    case 5: c = 6; break;
    case 2: c = 5; break;
    case 1: c = 4; break;
    case 3: c = 3; break;
    case 6:
    case 7: c = 2; break;
    case 4:
    case 8: c = 1; break;
    case 0:
    default: c = 0; break;
    }
    int lo = (short)key;
    int hi = key >> 16;
    int d = 0;
    if (lo >= 0) {
        d = lo;
    }
    if (hi >= 0) {
        d |= (hi & 0xF) << 6;
    }
    d &= 0x3FF;
    return ~((a << 26) | (b << 16) | (c << 13) | (d << 3));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_00364360);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void func_00362478(sGifPacket* pkt, int a, int b, int ctx);
extern "C" void func_00364CD0(void* self, int a, int b, unsigned int c, ulong** pp);
// PORT: bound by asm label so this caller's packet type doesn't conflict with the definition.
extern "C" void func_003627A8_4360(void* pkt, ulong** pp, int mode) __asm__("func_003627A8");
extern char* D_004A5B80;

struct sRmGsState4360 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    short tex[2];
    sRmGsState4360()
    {
        unsigned int i;
        for (i = 0; i < 2; i++) {
            tex[i] = -1;
        }
        func_00416210(this, 0, 0x10);
    }
};

struct sRmPkt4360 {
    int count;      // 0x0
    ulong* cur;     // 0x4
    ulong* base;    // 0x8
};

// PORT: 64-bit DMA/GIF tag writes (ulong).
extern "C" void func_00364360(void* self, ulong** pp)
{
    char* gs = D_004A5B80;
    sRmGsState4360 st;
    sRmPkt4360 pkt;
    st = *(sRmGsState4360*)&D_00501420;
    (*pp)[0] = 0x10000001;
    (*pp)[1] = 0;
    (*pp)[2] = 0;
    (*pp)[3] = (ulong)1 << 60;
    *pp += 4;
    func_00364CD0(self, (st.w0 & 0x3C0) >> 6, 0, st.w3 & 0x3FFFFFFF, pp);
    pkt.count = 0;
    pkt.base = *pp;
    pkt.cur = *pp + 6;
    func_003625C0((sGifPacket*)&pkt, (st.w0 & 0xC) >> 2, 0);
    func_00362478((sGifPacket*)&pkt, (st.w1 & 0x7C) >> 2, (st.w0 >> 12) & 0xFF, 0);
    func_00362660((sGifPacket*)&pkt, *(unsigned int*)(gs + 0x5A80), *(unsigned int*)(gs + 0x5A40), (st.w1 >> 22) & 1, 0);
    func_003626D8((sRmGsPacket*)&pkt, (st.w1 >> 23) & 3, (st.w1 >> 20) & 3, (st.w1 & 0xFF000) >> 12, 0);
    func_003625C0((sGifPacket*)&pkt, (st.w0 & 0x30) >> 4, 1);
    func_00362478((sGifPacket*)&pkt, (st.w1 & 0xF80) >> 7, (st.w0 >> 20) & 0xFF, 1);
    func_00362660((sGifPacket*)&pkt, *(unsigned int*)(gs + 0x5A80), *(unsigned int*)(gs + 0x5A40), (st.w1 >> 23) & 1, 1);
    func_003626D8((sRmGsPacket*)&pkt, (st.w1 >> 25) & 3, (st.w1 >> 22) & 3, (st.w1 & 0xFF000) >> 12, 1);
    func_003627A8_4360(&pkt, pp, 1);
}
#endif

INCLUDE_ASM("object/railmodifier", func_003645B8);

//100%
INCLUDE_ASM("object/railmodifier", func_00364B88);
#ifdef SKIP_ASM
struct sRailKey4 {
    unsigned short a, b, c, d;
};

struct sRailKeyTable {
    char pad_0x00[0x69CC4];
    int found;                  // 0x69CC4
    char pad_0x69CC8[0x6AED0 - 0x69CC8];
    int count;                  // 0x6AED0
    sRailKey4 keys[1];          // 0x6AED4
};

extern "C" void func_00364B88(sRailKeyTable* self, sRailKey4* k)
{
    int i;
    self->found = -1;
    for (i = 0; i < self->count; i++) {
        if (self->keys[i].a == k->a && self->keys[i].b == k->b &&
            self->keys[i].c == k->c && self->keys[i].d == k->d) {
            self->found = i;
            break;
        }
    }
    if (self->found < 0) {
        self->keys[self->count].a = k->a;
        self->keys[self->count].b = k->b;
        self->keys[self->count].c = k->c;
        self->keys[self->count].d = k->d;
        self->found = self->count;
        self->count++;
    }
}
#endif

INCLUDE_ASM("object/railmodifier", func_00364CD0);

//100%
INCLUDE_ASM("object/railmodifier", func_00365E40);
#ifdef SKIP_ASM
extern "C" void func_003660A8(void* self, int idx);

struct sRailLinkE40 {
    int flags;      // 0x0
    int f4;         // 0x4
    int prev;       // 0x8
    int fC;         // 0xC
    int next;       // 0x10
    int f14;        // 0x14
    int f18;        // 0x18
};

struct sRailSlotE40 {
    char pad_0x0[0x14];
    int a;          // 0x14
    int b;          // 0x18
};

struct sRailModE40 {
    sRailLinkE40 store[0x124];  // 0x0
    sRailLinkE40* links;        // 0x1FF0
    int f1FF4;                  // 0x1FF4
    sRailSlotE40 slotsA[17];    // 0x1FF8
    sRailSlotE40 slotsB[17];    // 0x21D4
    char pad_0x23B0[0xC];
    int f23BC;                  // 0x23BC
    int f23C0;                  // 0x23C0
    int f23C4;                  // 0x23C4
    int f23C8;                  // 0x23C8
    char pad_0x23CC[0xC];
    int f23D8;                  // 0x23D8
    int f23DC;                  // 0x23DC
    int f23E0;                  // 0x23E0
    int f23E4;                  // 0x23E4
    void* pool;                 // 0x23E8
};

extern "C" void func_00365E40(void* list, int a1, int a2, void* pool)
{
    sRailModE40* self = (sRailModE40*)list;
    int i;
    self->f1FF4 = a2;
    self->links[0].flags = a1;
    self->links[0].f4 = a2;
    self->links[0].fC = -1;
    self->links[0].next = -1;
    self->links[0].prev = -1;
    for (i = 1; i < 0x123; i++) {
        self->links[i].flags &= ~1;
        self->links[i].next = i + 1;
    }
    self->links[0x123].next = -1;
    for (i = 0; i < 17; i++) {
        self->slotsA[i].b = -1;
        self->slotsA[i].a = -1;
        self->slotsB[i].b = -1;
        self->slotsB[i].a = -1;
    }
    self->f23C0 = 0;
    self->f23BC = -1;
    self->f23C4 = -1;
    self->f23C8 = -1;
    func_003660A8(self, 0);
    self->pool = pool;
    self->f23D8 = -1;
    self->f23E0 = -1;
    self->f23E4 = -1;
    self->f23DC = 1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00365F68);
#ifdef SKIP_ASM
extern "C" void func_00424698(void* begin, void* end);
extern "C" int func_0038F708(void* base, int size, int mode);

extern "C" void func_00365F68(void* self)
{
    func_00424698(self, (char*)self + 0x1FEF);
    *(int*)((char*)self + 0x1FF0) = func_0038F708(self, 0x1FF0, 2);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00365FA8);
#ifdef SKIP_ASM
extern "C" void func_004247D8(void* begin, void* end);
extern "C" void func_0038F738(void* base, int size, int mode);

extern "C" void func_00365FA8(void* self)
{
    func_004247D8(self, (char*)self + 0x1FEF);
    func_0038F738(self, 0x1FF0, 2);
    *(void**)((char*)self + 0x1FF0) = self;
}
#endif

// 0x1c-byte elements reached through a pointer at self+0x1ff0, indexed by
// the cursor at self+0x23dc (which the function then advances)
struct sRailLink {
    char pad_0x00[0x10];
    int field_0x10;
    char pad_0x14[0x8];
};

//95.0% - logic verified correct; the target puts the mult result in v1 and
// ours lands in v0. Reordering the locals does not shift the allocation.
INCLUDE_ASM("object/railmodifier", func_00365FE8);
#ifdef SKIP_ASM
extern "C" void func_00365FE8(void* self)
{
    int i = *(int*)((char*)self + 0x23dc);
    sRailLink* b = *(sRailLink**)((char*)self + 0x1ff0);
    *(int*)((char*)self + 0x23dc) = b[i].field_0x10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00366008);
#ifdef SKIP_ASM
struct sRailNode {
    int field_0x0;
    int size;               // 0x04
    int field_0x8;
    int prev;               // 0x0c
    int next;               // 0x10
    int prev2;              // 0x14
    int next2;              // 0x18
};

struct sRailNodeMan {
    char pad_0x0[0x1ff0];
    sRailNode* nodes;       // 0x1ff0
    int field_0x1ff4;
    sRailNode headsA[17];   // 0x1ff8
    sRailNode headsB[18];   // 0x21d4
    char pad_0x23cc[0x10];
    int freeHead;           // 0x23dc
};

extern "C" void func_00366008(sRailNodeMan* self, int idx)
{
    sRailNode* node = &self->nodes[idx];
    sRailNode* prev;
    int link = node->prev;
    if (link < 0) {
        if ((link & 0x70000000) == 0x10000000) {
            prev = &self->headsA[link & 0x0FFFFFFF];
        } else {
            prev = &self->headsB[link & 0x0FFFFFFF];
        }
    } else {
        prev = &self->nodes[link];
    }
    prev->next = node->next;
    if (node->next >= 0) {
        self->nodes[node->next].prev = node->prev;
    }
    node->next = self->freeHead;
    self->freeHead = idx;
}
#endif

INCLUDE_ASM("object/railmodifier", func_003660A8);

//100%
INCLUDE_ASM("object/railmodifier", func_00366238);
#ifdef SKIP_ASM
extern "C" void func_00366238(sRailNodeMan* self, int idx)
{
    sRailNode* node = &self->nodes[idx];
    sRailNode* prev;
    int link = node->prev2;
    if (link < 0) {
        if ((link & 0x70000000) == 0x10000000) {
            prev = &self->headsA[link & 0x0FFFFFFF];
        } else {
            prev = &self->headsB[link & 0x0FFFFFFF];
        }
    } else {
        prev = &self->nodes[link];
    }
    prev->next2 = node->next2;
    if (node->next2 >= 0) {
        self->nodes[node->next2].prev2 = node->prev2;
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003662D0);
#ifdef SKIP_ASM
extern "C" void func_003660A8(void* self, int idx);
// PORT: the unit declares func_00365FE8 as void; it returns the popped free index.
extern "C" int func_00365FE8_pop(void* self) __asm__("func_00365FE8");

extern "C" void func_003662D0(sRailNodeMan* self, int idx, int size)
{
    sRailNode* node = &self->nodes[idx];
    func_00366238(self, idx);
    if (size == node->size || self->freeHead == -1) {
        node->field_0x0 |= 1;
    } else {
        int n = func_00365FE8_pop(self);
        sRailNode* nn = &self->nodes[n];
        nn->field_0x0 = node->field_0x0 + size;
        nn->size = node->size - size;
        nn->field_0x8 = -1;
        nn->prev = idx;
        int next = node->next;
        nn->next = next;
        if (next >= 0) {
            self->nodes[next].prev = n;
        }
        node->next = n;
        func_003660A8(self, n);
        node->size = size;
        node->field_0x0 |= 1;
    }
    func_003660A8(self, idx);
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003663D8);
#ifdef SKIP_ASM
extern "C" void func_003663D8(void* selfp, int idx)
{
    sRailNodeMan* self = (sRailNodeMan*)selfp;
    sRailNode* n = &self->nodes[idx];
    if (n->field_0x8 != 0x7FFFFFFF) {
        char* owner = (*(char***)((char*)self + 0x23E8))[n->field_0x8];
        if ((n->field_0x0 >> 2) & 1) {
            *(int*)(owner + 0x2C) = -1;
            *(int*)(owner + 0x34) = -1;
        } else {
            *(int*)(owner + 0x28) = -1;
            *(int*)(owner + 0x30) = -1;
        }
    }
    n->field_0x0 &= ~0x3F;
    func_00366238(self, idx);
    func_003660A8(self, idx);
    for (;;) {
        int l = n->prev;
        if (l >= 0 && (self->nodes[l].field_0x0 & 1) == 0) {
            idx = l;
            n = &self->nodes[l];
        } else {
            int r = n->next;
            if (r < 0 || (self->nodes[r].field_0x0 & 1)) {
                return;
            }
        }
        func_00366238(self, idx);
        func_00366238(self, n->next);
        n->size += self->nodes[n->next].size;
        func_00366008(self, n->next);
        func_003660A8(self, idx);
    }
}
#endif

INCLUDE_ASM("object/railmodifier", func_00366548);

INCLUDE_ASM("object/railmodifier", func_00366618);

//100%
INCLUDE_ASM("object/railmodifier", func_003666F8);
#ifdef SKIP_ASM
extern void* D_004A5B84;
extern char D_0053AB80[];
extern char D_0053E9FF[];

struct sRailPair66F8 {
    int a;
    int b;
};

// PORT: 128-bit fill pattern built through a union of two 64-bit halves.
static inline cQuad128 makeFill66F8(ulong lo, ulong hi)
{
    union {
        ulong l[2];
        cQuad128 q;
    } u;
    u.l[0] = lo;
    u.l[1] = hi;
    return u.q;
}

// PORT: scratchpad (0x70000000..0x70004000) free space, pointer held in int.
static inline unsigned int spadFree66F8()
{
    char* p = (char*)D_004A5B84;
    return p ? 0x70004000 - (int)p : 0;
}

extern "C" void func_003666F8()
{
    cQuad128 fill = makeFill66F8(0xFFFFFFFF, 0xFFFFFFFF);
    func_004247D8(D_0053AB80, D_0053E9FF);
    cQuad128* p = (cQuad128*)D_004A5B84;
    unsigned int n = spadFree66F8() >> 4;
    for (; n != 0; n--) {
        *p++ = fill;
    }
    int chunk = spadFree66F8() >> 3;
    for (int i = 0; i < 2000; i += chunk) {
        int left = 2000 - i;
        if (left < chunk) {
            chunk = left;
        }
        func_0038F738(&((sRailPair66F8*)D_0053AB80)[i], chunk * 8, 2);
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003667F8);
#ifdef SKIP_ASM
// PORT: PS2-only MMI count-leading-sign-bits (plzcw); off-PS2 use a clz builtin.
static inline int railFloorLog2(int x)
{
    long r;
    __asm__("plzcw %0, %1\n\txori %0, %0, 0x1f\n\taddiu %0, %0, -1" : "=r"(r) : "0"(x));
    return r;
}

extern "C" int func_003667F8(sRailNodeMan* self, int size)
{
    int b;
    for (b = railFloorLog2(size) - 6; b < 17; b++) {
        int i = self->headsB[b].next2;
        while (i >= 0) {
            if (self->nodes[i].size >= size) {
                return i;
            }
            i = self->nodes[i].next2;
        }
    }
    return -1;
}
#endif

INCLUDE_ASM("object/railmodifier", func_003668F8);

INCLUDE_ASM("object/railmodifier", func_003669F0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_00366CE0);
#ifdef SKIP_ASM
extern "C" void func_003662D0(sRailNodeMan* self, int idx, int size);
extern "C" int func_003668F8(sRailNodeMan* self, int size, int skipA, int skipB, int level);
extern "C" void func_003669F0(sRailNodeMan* self, int size, int skipA, int skipB, int level);

extern "C" int func_00366CE0(sRailNodeMan* self, int size, int owner, int skipB, int level, int align)
{
    int idx;
    if (align) {
        size += -size & 0x1FFF;
    }
    if (size < 0x100) {
        size = 0x100;
    }
    for (;;) {
        idx = func_003667F8(self, size);
        if (idx >= 0) {
            func_003662D0(self, idx, size);
            self->nodes[idx].field_0x8 = owner;
            return idx;
        }
        if (func_003668F8(self, size, owner, skipB, level) == 0) {
            func_003669F0(self, size, owner, skipB, level);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_00366E30);
#ifdef SKIP_ASM
extern "C" void func_003663D8(void* self, int id);

extern "C" void func_00366E30(void* self, int i)
{
    char* e = (*(char***)((char*)self + 0x23E8))[i];
    if (*(int*)(e + 0x30) >= 0) {
        func_003663D8(self, *(int*)(e + 0x30));
    }
    if (*(int*)(e + 0x34) >= 0) {
        func_003663D8(self, *(int*)(e + 0x34));
    }
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00366E90);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
void cMemMan_free(void* p);
extern "C" void func_003E6574(void* dst, void* src, int size);
extern "C" void func_00390198(void* self, int w, int h, void* buf, char* src);
extern char D_004A4060[];

struct sRmTex_366E90 {
    char pad_0x0[0xC];
    int state;          // 0xC
    int size;           // 0x10
    char pad_0x14[0x4];
    int bpp;            // 0x18
    char* data;         // 0x1C
    char pad_0x20[0x4];
    int mipCount;           // 0x24
    char pad_0x28[0x10];
    unsigned long tex0; // 0x38
};

extern "C" void func_00366E90(char* self, sRmTex_366E90* tex)
{
    int n = 0;
    char* buf = new (D_004A4060, *(int*)(self + 0x1F58) ^ 0x100, 0) char[tex->size];
    int tw = (tex->tex0 >> 26) & 0xF;
    int th = (tex->tex0 >> 30) & 0xF;
    int bpp = tex->bpp;
    int w = 1 << tw;
    int h = 1 << th;
    char* src = tex->data;
    if (tex->mipCount >= 0) {
        do {
            n++;
            int bytes = w * h * bpp / 8;
            if (bytes <= 0xFF) {
                bytes = 0x100;
            }
            func_003E6574(buf, src, bytes);
            func_00390198(self, w, h, buf, src);
            src += bytes;
            w >>= 1;
            h >>= 1;
        } while (n <= tex->mipCount);
    }
    if (buf != 0) {
        cMemMan_free(buf);
    }
    tex->state = 10;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_00366FE0__FPvi);
#ifdef SKIP_ASM
void func_00366FE0(void* self, int val)
{
    *(int*)((char*)self + 0x1F58) = val;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_00366FE8);
#ifdef SKIP_ASM
extern "C" void func_003670E0(void* self);
extern "C" void func_00365E40(void* list, int a, int size, void* pool);

extern "C" void func_00366FE8(void* self)
{
    *(int*)((char*)self + 0x1F58) = 0;
    func_003670E0(self);
    int* a = (int*)((char*)self + 0x1F4C);
    for (int i = 1; i >= 0; i--) {
        a[i] = -1;
    }
    *(int*)((char*)self + 0x1F54) = -1;
    func_00365E40((char*)self + 0x1F60, 0, 0x400000, (char*)self + 0x8);
    func_00365E40((char*)self + 0x4350, 0, 0x1000, (char*)self + 0x8);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/railmodifier", func_00367078);
#ifdef SKIP_ASM
extern "C" void func_00366618(void* list);

extern "C" void func_00367078(void* self)
{
    func_00366618((char*)self + 0x4350);
    func_00366618((char*)self + 0x1F60);
    int* a = (int*)((char*)self + 0x1F4C);
    for (int i = 1; i >= 0; i--) {
        a[i] = -1;
    }
    *(int*)((char*)self + 0x1F54) = -1;
}
#endif

//100%
INCLUDE_ASM("object/railmodifier", func_003670E0);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

extern "C" void func_003670E0(void* self)
{
    int i;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    func_003E6448((char*)self + 0x8, 0, 0x1F40);
    *(void***)((char*)self + 0x1F48) = (void**)((char*)self + 0x1778);
    for (i = 0; i < 499; i++) {
        void** list = *(void***)((char*)self + 0x1F48);
        list[i] = &list[i + 1];
    }
}
#endif

