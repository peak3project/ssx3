#include "common.h"
#include "ai/rider.h"

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", cWipeoutMotion_gainFocus);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void cAirPredictor_startLaunchIntoAir(void* self, void* a, void* b, float t);
struct cRiderSphereTree;
cRiderSphereTree* cRiderSphereTree_cRiderSphereTree(cRiderSphereTree* self);
extern char D_00458210[];

struct sVec4WG {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0DotWG(const sVec4WG& a, const sVec4WG& b)
{
    float r;
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf5, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %0, $vf4\n"
        : "=r"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4WG vu0ScaleMemWG(const sVec4WG& v, float s)
{
    sVec4WG r;
    int t;
    __asm__ __volatile__(
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline void vu0SubWG(sVec4WG& dst, const sVec4WG& a, const sVec4WG& b)
{
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(a), "m"(b));
}

extern "C" void cWipeoutMotion_gainFocus(char* self, int a1)
{
    if (*(void**)(self + 0x44) == 0)
    {
        *(void**)(self + 0x44) = cRiderSphereTree_cRiderSphereTree((cRiderSphereTree*)cMemMan_alloc(0x2B0, D_00458210, 0, 0));
    }
    char* r = *(char**)(self + 0x40);
    sVec4WG* pos = (sVec4WG*)(r + 0x110);
    *(sVec4WG*)(self + 0x50) = *pos;
    *(sVec4WG*)(self + 0x60) = *pos;
    if (a1 == 0)
    {
        sVec4WG* n = (sVec4WG*)(r + 0x370);
        float d = vu0DotWG(*(sVec4WG*)(r + 0x1E0), *n);
        sVec4WG t = vu0ScaleMemWG(*n, d);
        sVec4WG* p = (sVec4WG*)(*(char**)(self + 0x40) + 0x1E0);
        vu0SubWG(*p, *p, t);
        *(int*)self = 0;
    }
    else
    {
        *(int*)self = 1;
        cAirPredictor_startLaunchIntoAir(*(void**)(r + 0x788), pos, r + 0x1E0, 3333.33349609375f);
    }
    *(int*)(self + 0x4) = 0;
    *(int*)(*(char**)(self + 0x40) + 0x2DC) = 0;
    *(int*)(*(char**)(self + 0x40) + 0x2E0) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00136D40);
#ifdef SKIP_ASM
struct sVec4WM {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVecPairWM {
    sVec4WM a;
    sVec4WM b;
};

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0DotWM(const sVec4WM& a, const sVec4WM& b)
{
    float r;
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf5, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %0, $vf4\n"
        : "=r"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4WM vu0ScaleWM(const sVec4WM& v, float s)
{
    sVec4WM r;
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline void vu0SubWM(sVec4WM& dst, const sVec4WM& a, const sVec4WM& b)
{
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(a), "m"(b));
}

extern "C" void func_00136D40(char* self, sVec4WM* a, sVec4WM* b, sVecPairWM* c)
{
    *(sVecPairWM*)(*(char**)(self + 0x40) + 0x130) = *c;
    *(int*)(*(char**)(self + 0x40) + 0x150) = 1;
    *(sVec4WM*)(self + 0x20) = *b;
    *(sVec4WM*)(self + 0x10) = *a;
    if (*(int*)self == 0)
    {
        sVec4WM* n = (sVec4WM*)(*(char**)(self + 0x40) + 0x370);
        float d = vu0DotWM(*n, *a);
        sVec4WM t = vu0ScaleWM(*n, d);
        vu0SubWM(*(sVec4WM*)(self + 0x10), *(sVec4WM*)(self + 0x10), t);
    }
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00136DE0);
#ifdef SKIP_ASM
extern "C" void cAirPredictor_startLaunchIntoAir(void* self, void* a, void* b, float t);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4WM vu0ScaleMemWM_136DE0(const sVec4WM& v, float s)
{
    sVec4WM r;
    int t;
    __asm__ __volatile__(
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

extern "C" void func_00136DE0(char* self, sVec4WM* a, sVec4WM* b)
{
    *(sVec4WM*)(self + 0x30) = *b;
    *(sVec4WM*)(*(char**)(self + 0x40) + 0x1E0) = *a;
    if (*(int*)self == 0)
    {
        sVec4WM* n = (sVec4WM*)(*(char**)(self + 0x40) + 0x370);
        float d = vu0DotWM(*n, *a);
        sVec4WM t = vu0ScaleMemWM_136DE0(*n, d);
        sVec4WM* p = (sVec4WM*)(*(char**)(self + 0x40) + 0x1E0);
        vu0SubWM(*p, *p, t);
    }
    else
    {
        char* r = *(char**)(self + 0x40);
        cAirPredictor_startLaunchIntoAir(*(void**)(r + 0x788), r + 0x110, r + 0x1E0, 3333.33349609375f);
    }
    *(int*)(self + 0x4) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00136E98);
#ifdef SKIP_ASM
extern "C" void func_00136F30();
extern "C" void func_00137D18(void*);
extern "C" void func_00137750(void*);

extern "C" void func_00136E98(int* self)
{
    func_00136F30();
    if (*self == 0)
    {
        func_00137D18(self);
    }
    else
    {
        func_00137750(self);
    }
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00136EE0);
#ifdef SKIP_ASM
extern "C" void func_00137138();
extern "C" void func_00138640(void*);
extern "C" void func_00137860(void*);

extern "C" void func_00136EE0(int* self)
{
    func_00137138();
    if (*self == 0)
    {
        func_00138640(self);
    }
    else
    {
        func_00137860(self);
    }
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00136F28__FPv);
#ifdef SKIP_ASM
void func_00136F28(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00136F30);
#ifdef SKIP_ASM
struct sVec4_6F30 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRider_6F30 {
    char pad_0x0[0x130];
    sVec4_6F30 pos;         // 0x130
    sVec4_6F30 quat;        // 0x140
    int active;             // 0x150
    char pad_0x154[0x1AC];
    float rate;             // 0x300
};

struct sWipeout_6F30 {
    char pad_0x0[0x10];
    sVec4_6F30 vel;         // 0x10
    sVec4_6F30 angVel;      // 0x20
    char pad_0x30[0x10];
    sRider_6F30* rider;     // 0x40
};

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline void vu0Scale_6F30(sVec4_6F30& out, const sVec4_6F30& v, float s)
{
    sVec4_6F30 r;
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
    out = r;
}

// PORT: PS2-only VU0 inline asm (in-place vector * scalar).
static inline void vu0ScaleEq_6F30(sVec4_6F30& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "lqc2      $vf4, %0\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (a += b).
static inline void vu0AddEq_6F30(sVec4_6F30& a, const sVec4_6F30& b)
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vu0Length_6F30(const sVec4_6F30& v)
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

// PORT: PS2-only VU0 inline asm (quaternion derivative 0.5 * (0, w) * q).
static inline void vu0QuatDeriv_6F30(sVec4_6F30& out, const sVec4_6F30& q, const sVec4_6F30& w)
{
    sVec4_6F30 r;
    __asm__(
        "qmtc2.ni  %3, $vf1\n"
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsuba.w   ACC, $vf0, $vf0\n"
        "vmsubx.w  $vf2, $vf0, $vf1x\n"
        "vmul.xyz  $vf7, $vf4, $vf5\n"
        "vmulw.xyz $vf3, $vf5, $vf4w\n"
        "vopmula.xyz ACC, $vf5, $vf4\n"
        "vopmsub.xyz $vf6, $vf4, $vf5\n"
        "vmulax.w  ACC, $vf2, $vf7x\n"
        "vmadday.w ACC, $vf2, $vf7y\n"
        "vmaddz.w  $vf8, $vf2, $vf7z\n"
        "vmulax.xyz ACC, $vf3, $vf1x\n"
        "vmaddx.xyz $vf8, $vf6, $vf1x\n"
        "sqc2      $vf8, %0\n"
        : "=m"(r)
        : "m"(q), "m"(w), "r"(0x3F000000)
        : "memory");
    out = r;
}

// PORT: PS2-only VU0 inline asm (in-place normalize).
static inline void vu0NormalizeEq_6F30(sVec4_6F30& v)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v)
        :
        : "memory");
}

extern "C" void func_00136F30(sWipeout_6F30* self)
{
    if (self->rider->active == 0) {
        return;
    }
    float dt = self->rider->rate * 0.01666666753590107f;
    sVec4_6F30 tmp;
    vu0Scale_6F30(tmp, self->vel, dt);
    vu0AddEq_6F30(self->rider->pos, tmp);
    sVec4_6F30 v2;
    v2.x = self->vel.x * -0.20000000298023224f;
    v2.y = self->vel.y * -0.20000000298023224f;
    v2.z = -1800.0f;
    v2.w = 0.0f;
    vu0Scale_6F30(tmp, v2, dt);
    vu0AddEq_6F30(self->vel, tmp);
    float len = vu0Length_6F30(self->vel);
    if (3333.33349609375f < len) {
        vu0ScaleEq_6F30(self->vel, 3333.33349609375f / len);
    }
    vu0ScaleEq_6F30(self->angVel, 1.0f - dt * 0.5f);
    vu0QuatDeriv_6F30(v2, self->rider->quat, self->angVel);
    vu0Scale_6F30(tmp, v2, dt);
    sRider_6F30* r = self->rider;
    r->quat.x += tmp.x;
    r->quat.y += tmp.y;
    r->quat.z += tmp.z;
    r->quat.w += tmp.w;
    vu0NormalizeEq_6F30(self->rider->quat);
}
#endif

INCLUDE_ASM("ai/motion/wipeoutmotion", func_00137138);

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00137550);
#ifdef SKIP_ASM
struct sVec4_7550 {
    float x, y, z, w;
    sVec4_7550() {}
    sVec4_7550(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sQuat_7550 {
    float x, y, z, w;
};

struct sBone_7550 {
    sVec4_7550 pos;     // 0x00
    sQuat_7550 rot;     // 0x10
};

struct sRadii_7550 {
    float r[4];
};
extern const sRadii_7550 D_00458220;

extern "C" void func_00329A90(void* tree, int n, sVec4_7550* pos, float* radii, sVec4_7550* center, float radius);

// PORT: PS2-only VU0 inline asm (non-volatile) (vector times scalar).
static inline sVec4_7550 vu0Scale_7550(const sVec4_7550& v, float s)
{
    sVec4_7550 r;
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

// PORT: PS2-only VU0 inline asm (non-volatile) (vector add).
static inline sVec4_7550 vu0Add_7550(const sVec4_7550& a, const sVec4_7550& b)
{
    sVec4_7550 r;
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

// PORT: PS2-only VU0 inline asm (non-volatile) (vector subtract).
static inline sVec4_7550 vu0Sub_7550(const sVec4_7550& a, const sVec4_7550& b)
{
    sVec4_7550 r;
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

static inline sVec4_7550 xAxis_7550(const sBone_7550* b)
{
    return sVec4_7550(1.0f - 2.0f * (b->rot.y * b->rot.y + b->rot.z * b->rot.z),
                      2.0f * (b->rot.x * b->rot.y + b->rot.w * b->rot.z),
                      2.0f * (b->rot.x * b->rot.z - b->rot.w * b->rot.y),
                      0.0f);
}

extern "C" void func_00137550(char* self)
{
    sVec4_7550 pts[4];
    sRadii_7550 radii = D_00458220;
    char* r = *(char**)(self + 0x40);
    char* model = *(char**)(r + 0x780);
    sBone_7550* bone = &(*(sBone_7550**)(model + 0x2C))[*(int*)(r + 0x8A4)];
    float s = *(float*)(model + 0x140);
    sVec4_7550 d = vu0Scale_7550(xAxis_7550(bone), s);
    pts[0] = vu0Add_7550(bone->pos, vu0Scale_7550(d, 70.0f));
    pts[1] = vu0Add_7550(bone->pos, vu0Scale_7550(d, 30.0f));
    pts[2] = vu0Sub_7550(bone->pos, vu0Scale_7550(d, 30.0f));
    pts[3] = vu0Sub_7550(bone->pos, vu0Scale_7550(d, 70.0f));
    func_00329A90(*(void**)(self + 0x44), 4, pts, radii.r, &bone->pos,
                  *(float*)(*(char**)(*(char**)(self + 0x40) + 0x780) + 0x140) * 90.0f);
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00137750);
#ifdef SKIP_ASM
extern "C" void cRider_updateOrientationImplicit(void*);
extern "C" void func_00113648(void* ap, void* pos, void* vel, float dt);
extern "C" void func_00121AA0(void* rider, void* a, void* b, float x, float y);

struct sVec4W7 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector times-assign scalar).
static inline void vu0ScaleEqW7(sVec4W7& v, float s)
{
    int t;
    __asm__ __volatile__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(v), "=&r"(t)
        : "m"(v), "f"(s));
}

extern "C" void func_00137750(void* p)
{
    char* self = (char*)p;
    char* r = *(char**)(self + 0x40);
    float dt = *(float*)(r + 0x300) * 0.01666666753590107f;
    func_00113648(*(void**)(r + 0x788), r + 0x110, r + 0x1E0, dt);
    int st = *(int*)(*(char**)(*(char**)(self + 0x40) + 0x788) + 0xAC);
    int ok = 0;
    if (st == 1 || st == 3) ok = 1;
    if (ok)
    {
        char* r2 = *(char**)(self + 0x40);
        char* ap = *(char**)(r2 + 0x788);
        float d = *(float*)(ap + 0x98) - *(float*)(ap + 0xA0);
        float x = *(float*)(r2 + 0x300);
        if (d >= 0.01666666753590107f)
            x /= d;
        else
            x *= 59.999996185302734f;
        char* r3 = *(char**)(self + 0x40);
        float k = 6.632251739501953f;
        func_00121AA0(r3, *(char**)(r3 + 0x788) + 0x20, *(char**)(r3 + 0x788) + 0x10, x, *(float*)(r3 + 0x300) * k);
    }
    vu0ScaleEqW7(*(sVec4W7*)(self + 0x30), 1.0f - dt * 1.5f);
    cRider_updateOrientationImplicit(*(void**)(self + 0x40));
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00137860);
#ifdef SKIP_ASM
// self is a cWipeoutMotion (no header yet); +0x40 is its cRider virtual-base pointer, +0x0 its state.
struct sHit_137860 {
    t4Vector pos;       // 0x00
    t4Vector normal;    // 0x10
    t4Vector v20;       // 0x20
    float pad30[7];     // 0x30
    int material;       // 0x4C
    char* obj;          // 0x50
    char pad54[0x2C];   // 0x54
} __attribute__((aligned(16)));

struct sSphere_137860 {
    char data[0x320];
} __attribute__((aligned(16)));

struct sVEntR_137860 { short delta; short index; bool (*fn)(void*); };
struct sVEntH_137860 { short delta; short index; void (*fn)(void*, void*, const t4Vector&); };

extern "C" void* func_0032F650(void* self, void* tree, int flag);
extern "C" void func_0032F708(void* self, int flags);
extern "C" float func_003342D0(void* world, void* seg, void* hit, int flags);
extern "C" float func_00138960(void* self, char* hit, sVec4WG* dir);
// PORT: the project names these __FPv (one void* param); this caller passes more.
void func_00113998_137860(void* ap, void* pos, void* vel) __asm__("func_00113998__FPv");
void func_00111AA0_137860(void* self, void* a, void* b, int c, float x) __asm__("func_00111AA0__FPv");
extern "C" void func_00106538(void* rider, const t4Vector& v);
extern "C" void func_0011E150(void* rider, int a1);
extern "C" void func_00105398(void* rider, int a1);
extern "C" void func_00107888(void* rider);
extern char* D_004A28A8;

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_137860(const t4Vector& a, const t4Vector& b)
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
static inline t4Vector vu0Scale_137860(const t4Vector& v, float s)
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector vu0Sub_137860(const t4Vector& a, const t4Vector& b)
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

// PORT: PS2-only VU0 inline asm (a += b).
static inline void vu0AddEq_137860(t4Vector& a, const t4Vector& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b));
}

// PORT: PS2-only VU0 inline asm (a -= b).
static inline void vu0SubEq_137860(t4Vector& a, const t4Vector& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b));
}

static inline bool isHuman_137860(cRider* r)
{
    char* sub = (char*)&r->mVtbl;
    sVEntR_137860* vt = *(sVEntR_137860**)sub;
    return vt[kRiderVt_isHuman].fn(sub + vt[kRiderVt_isHuman].delta);
}

#define RIDER (*(cRider**)(self + 0x40))

extern "C" void func_00137860(void* vself)
{
    char* self = (char*)vself;
    sHit_137860 hitA;
    sSphere_137860 sph;
    sHit_137860 hitB;
    cRider* r = RIDER;
    func_0032F650(&sph, r->mSphereTree, !isHuman_137860(r));
    float d = func_003342D0(RIDER->unk_860, &sph, &hitA, (int)RIDER->unk_868);
    if (d >= 0.0f)
    {
        float t = func_00138960(self, (char*)&hitB, (sVec4WG*)&hitA.normal);
        float vn = 0.0f;
        float h = 0.0f;
        if (t >= 0.4000000059604645f)
        {
            vn = vu0Dot_137860(RIDER->mVelocity, hitB.normal);
            h = vu0Dot_137860(vu0Sub_137860(RIDER->mPosition, hitB.pos), hitB.normal);
        }
        if (t >= 0.4000000059604645f && vn <= 0.0f && h <= 10.0f)
        {
            func_00113998_137860(RIDER->mAirPredictor, &RIDER->mPosition, &RIDER->mVelocity);
            func_00111AA0_137860(RIDER->mRiderHandler, &hitB, &hitB.normal, hitB.material, vn);
            cRider* r2 = RIDER;
            char* hd = (char*)r2->mRiderHandler;
            *(int*)(hd + 0x314) = 1;
            *(t4Vector*)(hd + 0x320) = r2->mVelocity;
            RIDER->unk_3D0 = hitB.v20;
            RIDER->mGroundNormal = hitB.normal;
            RIDER->unk_438 = hitB.material;
            RIDER->unk_460 = hitB.pos;
            RIDER->unk_454 = vu0Dot_137860(vu0Sub_137860(RIDER->mPosition, hitB.pos), RIDER->mGroundNormal);
            t4Vector impulse = vu0Scale_137860(RIDER->mGroundNormal, -vn);
            vu0AddEq_137860(RIDER->mVelocity, impulse);
            if (hitB.obj != 0)
            {
                char* o = *(char**)(hitB.obj + 0xC);
                if (o != 0)
                {
                    sVEntH_137860* vt = *(sVEntH_137860**)(o + 0xC);
                    vt[43].fn(o + vt[43].delta, &hitB,
                              vu0Scale_137860(vu0Scale_137860(impulse, -1.0f), (float)*(int*)(D_004A28A8 + 0x10)));
                }
            }
            float pen = vu0Dot_137860(vu0Sub_137860(RIDER->mPosition, hitB.pos), hitB.normal);
            if (pen < 0.0f)
            {
                func_00106538(RIDER, vu0Scale_137860(hitB.normal, -pen));
            }
            *(int*)self = 0;
        }
        else
        {
            t4Vector push = vu0Scale_137860(vu0Scale_137860(hitA.normal, 1.100000023841858f), d);
            func_00106538(RIDER, push);
            if (t < 0.0f || vu0Dot_137860(hitB.normal, hitA.normal) < 0.8999999761581421f)
            {
                float v = vu0Dot_137860(hitA.normal, RIDER->mVelocity);
                if (v < 0.0f)
                {
                    vu0SubEq_137860(RIDER->mVelocity, vu0Scale_137860(hitA.normal, v));
                }
            }
            cAirPredictor_startLaunchIntoAir(RIDER->mAirPredictor, &RIDER->mPosition, &RIDER->mVelocity, 3333.33349609375f);
        }
    }
    func_0011E150(RIDER, 0);
    func_00105398(RIDER, 0);
    func_00107888(RIDER);
    func_0032F708(&sph, 2);
}

#undef RIDER
#endif

INCLUDE_ASM("ai/motion/wipeoutmotion", func_00137D18);

INCLUDE_ASM("ai/motion/wipeoutmotion", func_00138640);

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00138960);
#ifdef SKIP_ASM
extern "C" void* func_0032E100(void* seg, const sVec4WG& a, const sVec4WG& b, int n, float r);
extern "C" float func_003342D0(void* world, void* seg, void* hit, int flags);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4WG vu0Scale_138960(const sVec4WG& v, float s)
{
    sVec4WG r;
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec4WG vu0Sub_138960(const sVec4WG& a, const sVec4WG& b)
{
    sVec4WG r;
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
static inline sVec4WG vu0Add_138960(const sVec4WG& a, const sVec4WG& b)
{
    sVec4WG r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

struct sVEntry_138960 { short delta; short index; void (*fn)(void*, void*); };

extern "C" float func_00138960(void* self, char* hit, sVec4WG* dir)
{
    char* rider = *(char**)((char*)self + 0x40);
    char seg[0xB0];
    sVec4WG* pt = (sVec4WG*)(rider + 0x110);
    func_0032E100(seg, vu0Sub_138960(*pt, vu0Scale_138960(*dir, 200.0f)), vu0Add_138960(*pt, vu0Scale_138960(*dir, 200.0f)), 2, 0.574999988079071f);
    char* r2 = *(char**)((char*)self + 0x40);
    float d = func_003342D0(*(void**)(r2 + 0x860), seg, hit, *(int*)(r2 + 0x864));
    if (d >= 0.0f)
    {
        char* obj = *(char**)(hit + 0x54);
        if (obj)
        {
            *(int*)(*(char**)((char*)self + 0x40) + 0x430) = *(int*)(obj + 0x150);
            *(float*)(*(char**)((char*)self + 0x40) + 0xAAC) = *(float*)(hit + 0x6C);
            *(float*)(*(char**)((char*)self + 0x40) + 0xAB0) = *(float*)(hit + 0x70);
            *(unsigned short*)(*(char**)((char*)self + 0x40) + 0x2D4) = *(unsigned short*)(*(char**)(hit + 0x54) + 0xA);
        }
        else
        {
            *(unsigned int*)(*(char**)((char*)self + 0x40) + 0x430) = 0xFFFFFFFF;
        }
        char* o = *(char**)(hit + 0x50);
        if (o)
        {
            char* h = *(char**)(o + 0xC);
            if (h)
            {
                sVEntry_138960* vt = *(sVEntry_138960**)(h + 0xC);
                vt[42].fn(h + vt[42].delta, hit);
            }
        }
    }
    return d;
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00138AD8);
#ifdef SKIP_ASM
struct sVEntry00138AD8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00138AD8(void* self, void* obj)
{
    sVEntry00138AD8* vt = *(sVEntry00138AD8**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x40);
}
#endif

//100%
INCLUDE_ASM("ai/motion/wipeoutmotion", func_00138B10);
#ifdef SKIP_ASM
struct sVEntry00138B10 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00138B10(void* self, void* obj)
{
    sVEntry00138B10* vt = *(sVEntry00138B10**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x40);
}
#endif

