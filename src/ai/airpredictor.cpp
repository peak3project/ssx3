#include "common.h"

//100%
INCLUDE_ASM("ai/airpredictor", cAirPredictor_reset);
#ifdef SKIP_ASM
struct sQuadR {
    int x[4];
} __attribute__((aligned(16)));

struct sPair8 {
    int x[2];
};

extern sQuadR D_004FF160;
extern sQuadR D_004FF120;
extern sPair8 D_004A5960[];

extern "C" void cAirPredictor_reset(char* self)
{
    *(int*)(self + 0xAC) = 0;
    *(int*)(self + 0xA0) = 0;
    *(int*)(self + 0x98) = 0;
    *(int*)(self + 0x9C) = 0;
    *(int*)(self + 0xA4) = 0;
    *(sQuadR*)(self + 0x20) = D_004FF160;
    *(sQuadR*)(self + 0x10) = D_004FF120;
    *(int*)(self + 0x90) = -1;
    *(unsigned int*)(self + 0x30) = 0xFFFFFFFF;
    *(sPair8*)(self + 0x34) = D_004A5960[0];
}
#endif

INCLUDE_ASM("ai/airpredictor", func_00113200);

//100%
INCLUDE_ASM("ai/airpredictor", cAirPredictor_startLaunchIntoAir);
#ifdef SKIP_ASM
struct sQuad;
void cAirPredictor_initLaunch(char* self, sQuad* a, sQuad* b);

extern "C" void cAirPredictor_startLaunchIntoAir(char* self, sQuad* a, sQuad* b, float t)
{
    cAirPredictor_reset(self);
    *(float*)(self + 0xA8) = t;
    cAirPredictor_initLaunch(self, a, b);
}
#endif

// 16-byte aligned: the original copies these with lq/sq, which require it
// (PS2 VU-style quadword).
struct sQuad {
    int x[4];
} __attribute__((aligned(16)));

//100%
INCLUDE_ASM("ai/airpredictor", cAirPredictor_initLaunch__FPcP5sQuadT1);
#ifdef SKIP_ASM
void cAirPredictor_initLaunch(char* self, sQuad* a, sQuad* b)
{
    *(int*)(self + 0xAC) = 0;
    *(sQuad*)(self + 0x70) = *a;
    *(sQuad*)(self + 0x80) = *b;
    *(sQuad*)(self + 0x50) = *a;
    *(sQuad*)(self + 0x60) = *b;
    *(float*)(self + 0x98) = *(float*)(self + 0xA0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/airpredictor", func_00113648);
#ifdef SKIP_ASM
extern sQuadR D_004FF130;
extern sQuadR D_004FF140;
extern sQuadR D_004FF160;
extern "C" void func_00113200(char* self);

struct sVec4_3648
{
    float x, y, z, w;
    sVec4_3648() {}
} __attribute__((aligned(16)));

// func_001139A0 is defined later in the unit (with its own vector type).
float func_001139A0_3648(char* self, sVec4_3648* pos, sVec4_3648* vel, sVec4_3648* outPos, sVec4_3648* outVel) __asm__("func_001139A0");

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_3648 vu0Scale_3648(const sVec4_3648& v, float s)
{
    sVec4_3648 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec4_3648 vu0Add_3648(const sVec4_3648& a, const sVec4_3648& b)
{
    sVec4_3648 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

extern "C" void func_00113648(char* self, sQuad* a, sQuad* b, float dt)
{
    if (*(float*)(self + 0x98) > 60.0f) {
        if (*(int*)(self + 0xAC) == 2) {
            *(int*)(self + 0xAC) = 3;
            *(sQuadR*)(self + 0x0) = D_004FF130;
            *(sQuadR*)(self + 0x10) = D_004FF140;
            *(sQuadR*)(self + 0x20) = D_004FF160;
            *(int*)(self + 0x90) = 0xD;
        } else {
            cAirPredictor_initLaunch(self, a, b);
            *(int*)(self + 0xAC) = 2;
        }
    } else {
        if (*(int*)(self + 0xAC) == 1 && *(float*)(self + 0x98) - *(float*)(self + 0xA0) < -0.2f) {
            cAirPredictor_initLaunch(self, a, b);
        }
        int st = *(int*)(self + 0xAC);
        if (st == 0) {
            func_00113200(self);
            while (*(int*)(self + 0xAC) == 0 && *(float*)(self + 0x98) < *(float*)(self + 0xA0) + dt) {
                func_00113200(self);
            }
        } else if (st == 2) {
            func_00113200(self);
            while (*(int*)(self + 0xAC) == 2 && *(float*)(self + 0x98) < *(float*)(self + 0xA0) + dt) {
                func_00113200(self);
            }
        }
    }
    float t = *(float*)(self + 0xA0) - *(float*)(self + 0xA4) + dt;
    while (t >= 0.01666666753590107f) {
        t -= 0.01666666753590107f;
        func_001139A0_3648(self, (sVec4_3648*)(self + 0x70), (sVec4_3648*)(self + 0x80), (sVec4_3648*)(self + 0x70), (sVec4_3648*)(self + 0x80));
        *(float*)(self + 0xA4) += 0.01666666753590107f;
    }
    if (t > 0.009999999776482582f) {
        sVec4_3648 p;
        sVec4_3648 v;
        func_001139A0_3648(self, (sVec4_3648*)(self + 0x70), (sVec4_3648*)(self + 0x80), &p, &v);
        float k = t * 59.999996185302734f;
        *(sVec4_3648*)a = vu0Add_3648(vu0Scale_3648(p, k), vu0Scale_3648(*(sVec4_3648*)(self + 0x70), 1.0f - k));
        *(sVec4_3648*)b = vu0Add_3648(vu0Scale_3648(v, k), vu0Scale_3648(*(sVec4_3648*)(self + 0x80), 1.0f - k));
        ((float*)a)[3] = 1.0f;
    } else {
        *(sQuad*)a = *(sQuad*)(self + 0x70);
        *(sQuad*)b = *(sQuad*)(self + 0x80);
    }
    *(float*)(self + 0xA0) += dt;
}
#endif

//100%
INCLUDE_ASM("ai/airpredictor", func_00113998__FPv);
#ifdef SKIP_ASM
void func_00113998(void* self)
{
    *(int*)((char*)self + 0x98) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/airpredictor", func_001139A0);
#ifdef SKIP_ASM
struct sVec4_1139A0
{
    float x, y, z, w;
    sVec4_1139A0() {}
    sVec4_1139A0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_1139A0 vu0Scale_1139A0(const sVec4_1139A0& v, float s)
{
    sVec4_1139A0 r;
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec4_1139A0 vu0Add_1139A0(const sVec4_1139A0& a, const sVec4_1139A0& b)
{
    sVec4_1139A0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times-assign scalar).
static inline void vu0ScaleEq_1139A0(sVec4_1139A0& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(v), "=&r"(t)
        : "m"(v), "f"(s));
}

// PORT: PS2-only VU0 inline asm (4-component length).
static inline float vu0Length_1139A0(const sVec4_1139A0& v)
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

extern "C" float func_001139A0(void* self, sVec4_1139A0* pos, sVec4_1139A0* vel, sVec4_1139A0* outPos, sVec4_1139A0* outVel)
{
    *outPos = vu0Add_1139A0(*pos, vu0Scale_1139A0(*vel, 0.01666666753590107f));
    float dx = vel->x * -0.0033333336468786f;
    float dy = vel->y * -0.0033333336468786f;
    float g = -31.666667938232422f;
    if (vel->z > 0.0f) g = -14.166666984558105f;
    *outVel = vu0Add_1139A0(*vel, sVec4_1139A0(dx, dy, g, 0.0f));
    float len = vu0Length_1139A0(*outVel);
    if (*(float*)((char*)self + 0xA8) < len)
    {
        vu0ScaleEq_1139A0(*outVel, *(float*)((char*)self + 0xA8) / len);
        len = *(float*)((char*)self + 0xA8);
    }
    return len;
}
#endif

//100%
INCLUDE_ASM("ai/airpredictor", func_00113A98);
#ifdef SKIP_ASM
extern "C" void func_00113A98(void) {

}
#endif

//100%
INCLUDE_ASM("ai/airpredictor", func_00113AA0);
#ifdef SKIP_ASM
struct sVEntry00113AA0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00113AA0(void* self, void* obj)
{
    sVEntry00113AA0* vt = *(sVEntry00113AA0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0xB0);
}
#endif

//100%
INCLUDE_ASM("ai/airpredictor", func_00113AD8);
#ifdef SKIP_ASM
struct sVEntry00113AD8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00113AD8(void* self, void* obj)
{
    sVEntry00113AD8* vt = *(sVEntry00113AD8**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0xB0);
}
#endif

