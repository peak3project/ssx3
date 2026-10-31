#include "common.h"

//100%
INCLUDE_ASM("ai/control/handplantcontrol", cHandplantMotion_gainFocus);
#ifdef SKIP_ASM
struct sVec4HP {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec4HP vu0SubHP(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector divided by scalar).
static inline sVec4HP vu0DivHP(const sVec4HP& v, float s)
{
    sVec4HP r;
    int t;
    __asm__ __volatile__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

extern "C" void cHandplantMotion_gainFocus(char* self)
{
    char* rider = *(char**)(self + 0xA0);
    *(sVec4HP*)(rider + 0x1E0) = vu0DivHP(vu0SubHP(*(sVec4HP*)(self + 0x30), *(sVec4HP*)(rider + 0x110)), *(float*)(self + 0x84));
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_00138BA0);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00139178);
#ifdef SKIP_ASM
// func_00139548 returns a value in $2 that is unused here; declaring it int keeps $2 free as the target has it.
extern "C" int func_00139548(void* self);

struct sVec4_9178 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// Updates the hand plant and copies its position into the rider's hand target.
extern "C" void func_00139178(void* self)
{
    func_00139548(self);
    *(sVec4_9178*)(*(char**)((char*)self + 0xA0) + 0x1E0) = *(sVec4_9178*)((char*)self + 0x10);
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_001391A8);

extern "C" void* func_0011E150(void*, int);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00139528__FPv);
#ifdef SKIP_ASM
void* func_00139528(void* self)
{
    return func_0011E150(*(void**)((char*)self + 0xa0), 0);
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_00139548);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00139970);
#ifdef SKIP_ASM
struct sVEntry00139970 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00139970(void* self, void* obj)
{
    sVEntry00139970* vt = *(sVEntry00139970**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0xA0);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001399A8);
#ifdef SKIP_ASM
struct sVEntry001399A8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001399A8(void* self, void* obj)
{
    sVEntry001399A8* vt = *(sVEntry001399A8**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0xA0);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001399E0);
#ifdef SKIP_ASM
extern "C" void cAirPredictor_startLaunchIntoAir(void* self, void* a, void* b, float t);

extern "C" void func_001399E0(void* self, int state)
{
    *(int*)self = state == 5;
    char* r = *(char**)((char*)self + 0x4);
    cAirPredictor_startLaunchIntoAir(*(void**)(r + 0x788), r + 0x110, r + 0x1E0, 3333.33349609375f);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00139A18__FPv);
#ifdef SKIP_ASM
void func_00139A18(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00139A20);
#ifdef SKIP_ASM
extern "C" void cRider_updateOrientationImplicit(void*);
extern "C" void func_00113648(void* ap, void* pos, void* vel, float dt);
extern "C" void func_00121AA0(void* rider, void* a, void* b, float x, float y);
extern "C" void func_00125970(char* self);
int func_0011FEE8(void* rider);
extern void* D_004A28A8;
extern void* D_004FF120[];

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void vu0ScaleEq_139A20(sVec4HP& v, float s)
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

// PORT: PS2-only VU0 inline asm (4-component dot product, by-value second operand).
static inline float vu0Dot_139A20(const sVec4HP& a, sVec4HP b)
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

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_139A20(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_00139A20(void* p)
{
    char* self = (char*)p;
    func_00125970(*(char**)(self + 0x4));
    char* r = *(char**)(self + 0x4);
    func_00113648(*(void**)(r + 0x788), r + 0x110, r + 0x1E0, *(float*)(r + 0x300) * 0.01666666753590107f);
    char* r1 = *(char**)(self + 0x4);
    {
        sVec4HP up = *(sVec4HP*)(r1 + 0x180);
        *(sVec4HP*)(r1 + 0x370) = up;
    }
    *(sVec4HP*)(*(char**)(self + 0x4) + 0x3D0) = *(sVec4HP*)D_004FF120;
    int st = *(int*)(*(char**)(*(char**)(self + 0x4) + 0x788) + 0xAC);
    int ok = 0;
    if (st == 1 || st == 3) ok = 1;
    if (ok) {
        char* r2 = *(char**)(self + 0x4);
        char* ap = *(char**)(r2 + 0x788);
        int idx = *(int*)(ap + 0x90);
        char* e = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x44) + idx * 0xB0;
        int flag = 0;
        short sf = *(short*)(ap + 0x94);
        if (sf != -1) {
            int m = sf & 8;
            flag = m != 0;
        }
        if (idx != 0x12 && *(int*)(e + 0x44) == 0 && flag) {
            float d = *(float*)(ap + 0x98) - *(float*)(ap + 0xA0);
            float t = *(float*)(r2 + 0x300);
            float x;
            if (d >= 0.01666666753590107f)
                x = t / d;
            else
                x = t * 59.999996185302734f;
            float y = *(float*)(*(char**)(self + 0x4) + 0x300) * 1.396263599395752f;
            if (func_0011FEE8(*(void**)(self + 0x4)) == 5) {
                char* r3 = *(char**)(self + 0x4);
                int big = 1;
                if (!(0.0872664749622345f < absf_139A20(*(float*)(*(char**)(r3 + 0x77C) + 0x258)))) big = 0;
                if (big) {
                    func_00121AA0(r3, *(char**)(r3 + 0x788) + 0x20, D_004FF120, x, y);
                    goto done;
                }
            }
            char* r4 = *(char**)(self + 0x4);
            char* ap4 = *(char**)(r4 + 0x788);
            char* tgt = ap4 + 0x20;
            if (*(float*)(ap4 + 0x28) < 0.30000001192092896f || *(int*)self != 0) {
                sVec4HP v = *(sVec4HP*)(ap4 + 0x10);
                if (vu0Dot_139A20(v, *(sVec4HP*)(r4 + 0x1B0)) < 0.0f) {
                    vu0ScaleEq_139A20(v, -1.0f);
                }
                char* r5 = *(char**)(self + 0x4);
                func_00121AA0(r5, *(char**)(r5 + 0x788) + 0x20, &v, x, y);
            } else {
                func_00121AA0(r4, tgt, D_004FF120, x, y);
            }
        }
    }
done:
    cRider_updateOrientationImplicit(*(void**)(self + 0x4));
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_00139C88);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013A7B0);
#ifdef SKIP_ASM
extern "C" void* func_0032E100(void* seg, const sVec4HP& a, const sVec4HP& b, int n, float r);
extern "C" float func_003342D0(void* world, void* seg, void* hit, int flags);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4HP vu0Scale_13A7B0(const sVec4HP& v, float s)
{
    sVec4HP r;
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
static inline sVec4HP vu0Add_13A7B0(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec4HP vu0Sub_13A7B0(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

struct sVEntry_13A7B0 { short delta; short index; void (*fn)(void*, void*); };

extern "C" float func_0013A7B0(void* self, char* hit)
{
    char* rider = *(char**)((char*)self + 0x4);
    sVec4HP* pt = (sVec4HP*)(*(char**)(*(char**)(rider + 0x780) + 0x2C) + (*(int*)(rider + 0x8A0) << 5));
    sVec4HP dir = *(sVec4HP*)(rider + 0x180);
    char seg[0xB0];
    func_0032E100(seg, vu0Sub_13A7B0(*pt, vu0Scale_13A7B0(dir, 200.0f)), vu0Add_13A7B0(*pt, vu0Scale_13A7B0(dir, 200.0f)), 2, 0.574999988079071f);
    char* r2 = *(char**)((char*)self + 0x4);
    float d = func_003342D0(*(void**)(r2 + 0x860), seg, hit, *(int*)(r2 + 0x864));
    if (d >= 0.0f)
    {
        char* o = *(char**)(hit + 0x50);
        if (o)
        {
            char* h = *(char**)(o + 0xC);
            if (h)
            {
                sVEntry_13A7B0* vt = *(sVEntry_13A7B0**)(h + 0xC);
                vt[42].fn(h + vt[42].delta, hit);
            }
        }
    }
    return d;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013A8F8);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" void func_0013A8F8(void* self, float v)
{
    if (v < -2222.22216796875f)
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x4) + 0x784), 0x41, 0, -1.0f);
        *(int*)(*(char**)((char*)self + 0x4) + 0x2DC) = 0;
    }
    else
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x4) + 0x784), 0x40, 0, -1.0f);
    }
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013A968);
#ifdef SKIP_ASM
extern "C" void func_0013A968(void* self, float v)
{
    if (v < -2222.22216796875f)
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x4) + 0x784), 0x3F, 0, -1.0f);
        *(int*)(*(char**)((char*)self + 0x4) + 0x2DC) = 0;
    }
    else
    {
        char* r = *(char**)((char*)self + 0x4);
        float pi = 3.1415929794311523f;
        float a = *(float*)(r + 0x2DC);
        if (a < -pi)
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x42, 0, -1.0f);
        else if (a > pi)
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x43, 0, -1.0f);
        else if (v < -1250.0f)
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x3E, 0, -1.0f);
        else
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x3D, 0, -1.0f);
    }
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_0013AA48);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013ACB0);
#ifdef SKIP_ASM
struct sVEntry0013ACB0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0013ACB0(void* self, void* obj)
{
    sVEntry0013ACB0* vt = *(sVEntry0013ACB0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x4);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013ACE8);
#ifdef SKIP_ASM
struct sVEntry0013ACE8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0013ACE8(void* self, void* obj)
{
    sVEntry0013ACE8* vt = *(sVEntry0013ACE8**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x4);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013AD20);
#ifdef SKIP_ASM
extern "C" void cRider_updateOrientationImplicit(void*);
extern "C" void cRider_doLeanPoseAdjust(void* self, void* q);
struct sQuadHP_0013AD20 { float x, y, z, w; } __attribute__((aligned(16)));

extern "C" void func_0013AD20(void* self)
{
    char* s = (char*)self;
    char* r = *(char**)(s + 0x50);
    cRider_doLeanPoseAdjust(r, r + 0x110);
    cRider_updateOrientationImplicit(*(void**)(s + 0x50));
    char* a = *(char**)(s + 0x50);
    // G1
    *(float*)(a + 0x1F8) = 0.0f;
    *(float*)(a + 0x1F0) = 0.0f;
    *(float*)(a + 0x1F4) = 0.0f;
    // E1
    char* b = *(char**)(s + 0x50);
    *(float*)(b + 0x210) = 0.0f;
    *(float*)(b + 0x208) = 0.0f;
    *(float*)(b + 0x20C) = 0.0f;
    char* c = *(char**)(s + 0x50);
    *(float*)(c + 0x258) = 0.0f;
    *(float*)(c + 0x250) = 0.0f;
    *(float*)(c + 0x254) = 0.0f;
    *(int*)(s + 0x10) = 0;
    *(int*)(s + 0x14) = 0;
    *(int*)(s + 0x18) = 0;
    *(int*)(*(char**)(s + 0x50) + 0x2DC) = 0;
    char* d = *(char**)(s + 0x50);
    *(float*)(d + 0x260) = 0.05000000447034836f;
    *(int*)(d + 0x264) = 0;
    *(int*)(s + 0x20) = 0;
    *(int*)(s + 0x1C) = 0;
    *(sQuadHP_0013AD20*)(s + 0x30) = *(sQuadHP_0013AD20*)(*(char**)(s + 0x50) + 0x110);
    *(int*)(s + 0x40) = 0;
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_0013ADC0);

INCLUDE_ASM("ai/control/handplantcontrol", func_0013AF28);

INCLUDE_ASM("ai/control/handplantcontrol", func_0013BD80);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013BFA8);
#ifdef SKIP_ASM
extern "C" void func_00114298(void* rider, float v);
// PORT: func_0011E150 is declared void* in this unit; this caller ignores the result (void call).
extern "C" void func_0011E150_v(void* rider, int a1) __asm__("func_0011E150");
extern "C" void func_00105398(void* rider, int a1);
extern "C" void func_00107888(void* rider);
extern "C" void func_0013C140(void* self);
extern "C" void func_00294170(void* snd, void* rider);
int func_0011FEE8(void* rider);
int func_0011FE98(void* rider);
// PORT: func_0011FE78 is defined with one parameter but this caller passes (rider, 1).
void func_0011FE78_impl_BFA8(void* rider, int v) __asm__("func_0011FE78__FPv");
extern char* D_004A3500;

struct sTbl_BFA8 {
    int v[4];
};
extern sTbl_BFA8 D_00458230;

struct sVec4_BFA8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vu0Length_BFA8(const sVec4_BFA8& v)
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

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void vu0ScaleEq_BFA8(sVec4_BFA8& v, float s)
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

#define RIDER_BFA8 (*(char**)((char*)self + 0x50))

extern "C" void func_0013BFA8(void* self)
{
    func_0011E150_v(RIDER_BFA8, 0);
    if (*(int*)((char*)self + 0x20) != 0) {
        char* r = RIDER_BFA8;
        *(int*)(r + 0x234) = 0;
        *(float*)(r + 0x230) = 0.03333333507180214f;
        func_00114298(RIDER_BFA8, -1.0f);
    }
    sTbl_BFA8 tbl = D_00458230;
    if (func_0011FEE8(RIDER_BFA8) == 0xC) {
        char* r = RIDER_BFA8;
        *(int*)(*(char**)(r + 0xAA0) + 0x28) = tbl.v[*(int*)(*(char**)(r + 0x77C) + 0x394)];
    } else {
        *(int*)(*(char**)(RIDER_BFA8 + 0xAA0) + 0x28) = 0x16;
    }
    func_00105398(RIDER_BFA8, 0);
    *(int*)(*(char**)(RIDER_BFA8 + 0xAA0) + 0x28) = 3;
    func_0013C140(self);
    *(unsigned int*)(*(char**)(RIDER_BFA8 + 0xAA0) + 0x28) = 0xFFFFFFFF;
    func_00107888(RIDER_BFA8);
    if (*(int*)((char*)self + 0x20) != 0 && func_0011FE98(RIDER_BFA8) == 4) {
        func_0011FE78_impl_BFA8(RIDER_BFA8, 1);
        func_00294170(D_004A3500, RIDER_BFA8);
    }
    char* r = RIDER_BFA8;
    float len = vu0Length_BFA8(*(sVec4_BFA8*)(r + 0x1E0));
    if (*(float*)(r + 0x2E4) < len)
        vu0ScaleEq_BFA8(*(sVec4_BFA8*)(r + 0x1E0), *(float*)(r + 0x2E4) / len);
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_0013C140);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013C5A0);
#ifdef SKIP_ASM
extern "C" void func_0013C5A0(void* self)
{
    char* a = *(char**)((char*)self + 0x50);
    *(float*)(a + 0x25C) = *(float*)(a + 0x264) = -0.25f;
    *(float*)(a + 0x260) = 0.0f;
    char* b = *(char**)((char*)self + 0x50);
    *(float*)(b + 0x264) = 1.0f;
    *(float*)(b + 0x260) = 0.03333333507180214f;
    *(int*)(*(char**)((char*)self + 0x50) + 0x5AC) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013C5E0);
#ifdef SKIP_ASM
struct sVEntry0013C5E0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0013C5E0(void* self, void* obj)
{
    sVEntry0013C5E0* vt = *(sVEntry0013C5E0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x50);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013C618);
#ifdef SKIP_ASM
struct sVEntry0013C618 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0013C618(void* self, void* obj)
{
    sVEntry0013C618* vt = *(sVEntry0013C618**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x50);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013C650);
#ifdef SKIP_ASM
extern "C" void* cRider_cRider(void* self);

struct sVEntry_13C650 { short delta; short index; void* fn; };
struct sVtbl9_13C650 { sVEntry_13C650 e[9]; } __attribute__((aligned(8)));
struct sVtbl22_13C650 { sVEntry_13C650 e[22]; } __attribute__((aligned(8)));

extern const sVtbl9_13C650 D_00459A98;
extern char D_00459B90[];
extern const sVtbl22_13C650 D_00459AE0;

// PORT: g++ 2.95 virtual-base construction. The class derives virtually from cRider (vbase pointer at
// +0x18, vbase at +0x20); when not most-derived, g++ copies cRider's overridden vtables to the stack and
// fixes up the this-deltas (expand_upcast_fixups). Written out by hand here.
extern "C" void* func_0013C650(void* self, int inChrg)
{
    if (inChrg)
    {
        char* vb = (char*)self + 0x20;
        *(char**)((char*)self + 0x18) = vb;
        cRider_cRider(vb);
    }
    *(void**)(*(char**)((char*)self + 0x18) + 0x6E8) = (void*)&D_00459A98;
    *(void**)(*(char**)((char*)self + 0x18) + 0x6D0) = D_00459B90;
    *(void**)(*(char**)((char*)self + 0x18) + 0x6C0) = (void*)&D_00459AE0;
    if (!inChrg)
    {
        sVtbl9_13C650 t1 = D_00459A98;
        *(void**)(*(char**)((char*)self + 0x18) + 0x6E8) = &t1;
        char* base = *(char**)((char*)self + 0x18) - 0x20;
        int d = (char*)self - base;
        t1.e[1].delta = D_00459A98.e[1].delta + d;
        sVtbl22_13C650 t2 = D_00459AE0;
        *(void**)(*(char**)((char*)self + 0x18) + 0x6C0) = &t2;
        t2.e[1].delta = D_00459AE0.e[1].delta + d;
    }
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)(*(char**)((char*)self + 0x18) + 0x31C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013C7A8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_001298C8();

struct sHpVec4_13C7A8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sHpEntry_13C7A8 {
    char pad0[0x14];
    float m14;
    float m18;
    char pad1C[0xB0 - 0x1C];
};

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void vu0ScaleEq_13C7A8(sHpVec4_13C7A8& v, float s)
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

struct sHpCtl_13C7A8 {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
    int m14;
    char* mRider;
};

extern "C" void func_0013C7A8(sHpCtl_13C7A8* self)
{
    self->m0 = 0;
    char* r = self->mRider;
    sHpEntry_13C7A8* tbl = *(sHpEntry_13C7A8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x44);
    sHpEntry_13C7A8* e = &tbl[*(int*)(r + 0x438)];
    float k = *(float*)(*(char**)(r + 0x780) + 0x140);
    self->m4 = k * e->m14;
    self->m8 = k * e->m18;
    *(sHpVec4_13C7A8*)(r + 0x390) = *(sHpVec4_13C7A8*)(r + 0x370);
    self->mC = 0;
    int t = func_001298C8();
    self->m10 = t;
    int d = t - self->m14;
    float f;
    if (d > 0x28)
        f = (d - 0x28) * 0.010000000707805157f + 0.699999988079071f;
    else
        f = 0.699999988079071f;
    vu0ScaleEq_13C7A8(*(sHpVec4_13C7A8*)(self->mRider + 0x1E0), f <? 1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013C878);
#ifdef SKIP_ASM
struct sPhys_C878 {
    int pad0;
    float f4;
    float f8;
    char padC[0xC];
    char* p18;
};

extern "C" float func_0013C878(sPhys_C878* self, float* cfg, float a, float b)
{
    float r;
    if (a > 0.0f) {
        r = cfg[0] * (a * -0.033333f);
        if (b > 0.0f) {
            r -= cfg[7] * b;
        }
    } else {
        float s4 = self->f4;
        if (-s4 < a) {
            r = (-cfg[0] * a) / s4;
            r -= cfg[7] * b;
        } else {
            a = (-self->f8) >? a;
            r = cfg[0] * (1.0f - ((a + s4) * 2.0f) / (self->f8 - s4));
            r -= cfg[7] * b;
        }
    }
    *(float*)(self->p18 + 0x758) = ((-a) / self->f8) >? 0.0f;
    return r;
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_0013C948);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013CCF0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" float func_001494C0(void* self, int rider, int value);
extern "C" float func_001493D8(void* self, int rider, int value);
extern "C" float func_00148D80(void* self, int rider, int value);

struct sCurvePt_13CCF0 { float x, y; };

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float hpAbs_13CCF0(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float hpLerp_13CCF0(const sCurvePt_13CCF0& a, const sCurvePt_13CCF0& b, float x)
{
    float y0 = a.y;
    x -= a.x;
    return y0 + (b.y - y0) * x / (b.x - a.x);
}

struct sHpCfg_13CCF0 { char pad[0x90]; sCurvePt_13CCF0 p[4]; };

static inline float hpCurve_13CCF0(const sHpCfg_13CCF0* c, float x)
{
    if (c->p[1].x < x)
    {
        if (c->p[2].x < x)
        {
            if (c->p[3].x < x)
                return c->p[3].y;
            return hpLerp_13CCF0(c->p[2], c->p[3], x);
        }
        return hpLerp_13CCF0(c->p[1], c->p[2], x);
    }
    if (x < c->p[0].x)
        return c->p[0].y;
    return hpLerp_13CCF0(c->p[0], c->p[1], x);
}

static inline float hpClamp_13CCF0(float v, float lo, float hi)
{
    if (v >= lo)
        return v <? hi;
    return lo;
}

static inline float hpRamp_13CCF0(float v, float lo, float hi)
{
    if (v >= lo)
    {
        if (v <= hi)
            return (v - lo) / (hi - lo);
        return 1.0f;
    }
    return 0.0f;
}

#define RIDER (*(char**)((char*)self + 0x18))

extern "C" float func_0013CCF0(void* self, sHpCfg_13CCF0* cfg, float a)
{
    float one = 1.0f;
    float spd = hpAbs_13CCF0(*(float*)(RIDER + 0x214));
    func_001494C0(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(RIDER + 0x86C), *(int*)(RIDER + 0xB34));
    float k1 = one / (func_001493D8(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(RIDER + 0x86C), *(int*)(RIDER + 0xB34)) * 0.31941401958465576f + one);
    float k2 = func_00148D80(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(RIDER + 0x86C), *(int*)(RIDER + 0xB34)) * 0.46218693256378174f + one;
    float c = hpCurve_13CCF0(cfg, hpAbs_13CCF0(a) * 0.035999998450279236f);
    float t = hpClamp_13CCF0(hpAbs_13CCF0(a) / 1666.666748046875f, 0.0f, 1.0f);
    c = c * (one * (k1 * (1.0f - t) + one * t));
    float ramp = hpRamp_13CCF0(*(float*)(RIDER + 0x378), 0.10000000149011612f, 0.20000000298023224f);
    float lift = ramp * (spd * 3.0004208087921143f) * spd * k2;
    float drag = ramp * (spd * 999.9600219726562f);
    float f8 = 1.0f;
    if (*(int*)(RIDER + 0x438) == 2 || *(int*)(RIDER + 0x438) == 3 || *(int*)(RIDER + 0x438) == 13)
        f8 = 0.5f - *(float*)(RIDER + 0x454) / *(float*)((char*)self + 8);
    float f12 = 1.0f;
    if (0.0f < *(float*)(RIDER + 0x1E8) - *(float*)(RIDER + 0x3D8))
        f12 = 0.5999583005905151f;
    float f2 = 1.0f;
    if (*(int*)(RIDER + 0x320) != *(int*)(RIDER + 0x324) && *(float*)(RIDER + 0x2FC) == 0.0f)
        f2 = 1.1147289276123047f;
    float f5 = 1.0f;
    if (0.0f < a && 0.0f < *(float*)(RIDER + 0x1E8) - *(float*)(RIDER + 0x3D8) && *(int*)(RIDER + 0x438) == 13)
        f5 = 34.84144592285156f;
    return ((-a * f8) * (c + lift) * f12 * f2 - drag) * f5;
}
#undef RIDER
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013D028);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void func_00148E68(void* iface, int rider, int b);

struct sCurvePt_13D028 { float x, y; };
extern sCurvePt_13D028* D_004A1140;

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float hpAbs_13D028(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float hpLerp_13D028(const sCurvePt_13D028& a, const sCurvePt_13D028& b, float x)
{
    float y0 = a.y;
    x -= a.x;
    return y0 + (b.y - y0) * x / (b.x - a.x);
}

static inline float hpCurve_13D028(const sCurvePt_13D028* p, float x)
{
    if (p[1].x < x)
    {
        if (p[2].x < x)
        {
            if (p[3].x < x)
                return p[3].y;
            return hpLerp_13D028(p[2], p[3], x);
        }
        return hpLerp_13D028(p[1], p[2], x);
    }
    if (x < p[0].x)
        return p[0].y;
    return hpLerp_13D028(p[0], p[1], x);
}

extern "C" float func_0013D028(void* self, float* v, float a, float b, float c)
{
    if (a < 0.0f && 0.0f < c)
    {
        a = a * c;
    }
    else if (0.0f < a && c < 0.0f)
    {
        a = a * -c;
    }
    else
    {
        return 0.0f;
    }
    a = a * hpCurve_13D028(D_004A1140, hpAbs_13D028(b) * 0.035999998450279236f);
    a = a * -v[2];
    func_00148E68(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(*(char**)((char*)self + 0x18) + 0x86C), *(int*)(*(char**)((char*)self + 0x18) + 0xB34));
    float s = *(float*)(*(char**)((char*)self + 0x18) + 0x2FC);
    float one = 1.0f;
    if (0.0f < s)
        a = a * (one / (s * 4.008637428283691f + one));
    return a;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013D1B8);
#ifdef SKIP_ASM
extern "C" void* func_0032E100(void* seg, const sVec4HP& a, const sVec4HP& b, int n, float r);
extern void* D_004FF120[];

struct sHit_13D1B8 {
    sVec4HP pos;            // 0x00
    sVec4HP normal;         // 0x10
    sVec4HP v20;            // 0x20
    float pad30[4];         // 0x30
    float dist;             // 0x40
    int pad44[2];           // 0x44
    int m4C;                // 0x4C
    char* obj;              // 0x50
    char* tri;              // 0x54
    int pad58[5];           // 0x58
    float m6C;              // 0x6C
    float m70;              // 0x70
    int pad74[3];           // 0x74
    sHit_13D1B8() {}
} __attribute__((aligned(16)));

extern "C" int func_00333EF8(void* world, void* seg, sHit_13D1B8* hits, int max, int flags);
extern sVec4HP D_004FF160;
extern sVec4HP D_004FF120_v __asm__("D_004FF120");

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4HP vu0Scale_13D1B8(const sVec4HP& v, float s)
{
    sVec4HP r;
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
static inline sVec4HP vu0Add_13D1B8(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
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
static inline sVec4HP vu0Sub_13D1B8(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
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
static inline float vu0Dot_13D1B8(const sVec4HP& a, const sVec4HP& b)
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

// PORT: PS2-only VU0 inline asm (4-component dot product, by-value first operand).
static inline float vu0DotV_13D1B8(sVec4HP a, const sVec4HP& b)
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4HP vu0Normalize_13D1B8(const sVec4HP& v)
{
    sVec4HP r;
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

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sVec4HP vu0Cross_13D1B8(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vu0Length_13D1B8(const sVec4HP& v)
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

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_13D1B8(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}


// Non-POD by-value vector (user copy ctor => passed by invisible reference, no callee copy).
struct sVec4P_13D1B8 {
    float x, y, z, w;
    sVec4P_13D1B8(const sVec4HP& v) { *(sVec4HP*)this = v; }
    sVec4P_13D1B8(const sVec4P_13D1B8& v) { *(sVec4HP*)this = *(const sVec4HP*)&v; }
} __attribute__((aligned(16)));

static inline sVec4HP vu0SubV_13D1B8(sVec4P_13D1B8 a, const sVec4HP& b)
{
    return vu0Sub_13D1B8(*(sVec4HP*)&a, b);
}

static inline int isBetter_13D1B8(sHit_13D1B8* a, sHit_13D1B8* b)
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

struct sVEnt_13D1B8 { short delta; short index; void (*fn)(void*, void*); };

#define RIDER (*(char**)((char*)self + 0x18))
#define RV(off) (*(sVec4HP*)(RIDER + (off)))

extern "C" int func_0013D1B8(void* self, sHit_13D1B8* out, float* dist)
{
    RV(0x380) = RV(0x370);
    sVec4HP pos = vu0Add_13D1B8(RV(0x110), vu0Scale_13D1B8(RV(0x3B0), *(float*)(*(char**)(RIDER + 0x780) + 0x140) * (*(float*)(RIDER + 0x1F0) * 45.0f)));
    sVec4HP a = vu0Add_13D1B8(pos, vu0Scale_13D1B8(RV(0x370), -100.0f));
    sVec4HP b = vu0Add_13D1B8(pos, vu0Scale_13D1B8(RV(0x370), 200.0f));
    char seg[0xB0];
    func_0032E100(seg, a, b, 2, 0.5f);
    sHit_13D1B8 hits[64];
    int n = func_00333EF8(*(void**)(RIDER + 0x860), seg, hits, 0x40, *(int*)(RIDER + 0x864));
    if (n == 0) {
        RV(0x370) = D_004FF160;
        RV(0x3D0) = D_004FF120_v;
        RV(0x3A0) = vu0Normalize_13D1B8(vu0SubV_13D1B8(RV(0x1B0), vu0Scale_13D1B8(RV(0x370), vu0DotV_13D1B8(RV(0x1B0), RV(0x370)))));
        RV(0x3B0) = vu0Cross_13D1B8(RV(0x370), RV(0x3A0));
        *(int*)(RIDER + 0x438) = 0;
        *dist = 0.0f;
        return 0;
    }
    int best = 0;
    float up0 = vu0Dot_13D1B8(hits[0].normal, RV(0x370));
    float bestDiff = absf_13D1B8(hits[0].dist - 0.5f);
    int ok = up0 >= 0.3f;
    for (int i = 1; i < n; i++) {
        float d = absf_13D1B8(hits[i].dist - 0.5f);
        float up = vu0Dot_13D1B8(hits[i].normal, RV(0x370));
        if (!ok) {
            if (up >= 0.3f) {
                bestDiff = d;
                best = i;
                ok = 1;
                continue;
            }
        } else if (up < 0.3f) {
            continue;
        }
        if (d < bestDiff) {
            bestDiff = d;
            best = i;
        } else if (d == bestDiff) {
            if (isBetter_13D1B8(&hits[i], &hits[best])) {
                best = i;
            }
        }
    }
    *out = hits[best];
    if (out->tri != 0) {
        *(int*)(RIDER + 0x430) = *(int*)(out->tri + 0x150);
        *(float*)(RIDER + 0xAAC) = out->m6C;
        *(float*)(RIDER + 0xAB0) = out->m70;
        *(short*)(RIDER + 0x2D4) = *(short*)(out->tri + 0xA);
    } else {
        *(unsigned int*)(RIDER + 0x430) = 0xFFFFFFFF;
    }
    if (out->obj != 0) {
        char* h = *(char**)(out->obj + 0xC);
        if (h) {
            sVEnt_13D1B8* vt = *(sVEnt_13D1B8**)(h + 0xC);
            vt[42].fn(h + vt[42].delta, out);
        }
    }
    *(int*)(RIDER + 0x438) = out->m4C;
    if (*(int*)(RIDER + 0x438) == -1) {
        *(int*)(RIDER + 0x438) = 0;
    }
    RV(0x370) = out->normal;
    RV(0x460) = out->pos;
    RV(0x3D0) = out->v20;
    RV(0x3A0) = vu0Normalize_13D1B8(vu0SubV_13D1B8(RV(0x1B0), vu0Scale_13D1B8(RV(0x370), vu0DotV_13D1B8(RV(0x1B0), RV(0x370)))));
    RV(0x3B0) = vu0Cross_13D1B8(RV(0x370), RV(0x3A0));
    sVec4HP delta = vu0Sub_13D1B8(pos, out->pos);
    *(float*)(RIDER + 0x454) = vu0Dot_13D1B8(delta, RV(0x370));
    *dist = vu0Length_13D1B8(vu0Sub_13D1B8(delta, vu0Scale_13D1B8(RV(0x370), *(float*)(RIDER + 0x454))));
    return 1;
}
#undef RV
#undef RIDER
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_0013D818);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013F178);
#ifdef SKIP_ASM
extern "C" void func_00114298(void* rider, float v);
// PORT: func_0011E150 is declared void* in this unit; this caller ignores the result (void call).
extern "C" void func_0011E150_v13F178(void* rider, int a1) __asm__("func_0011E150");
extern "C" void func_00105398(void* rider, int a1);
extern "C" void func_00107888(void* rider);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" void func_0013F488(void* self);
extern "C" void func_00294170(void* snd, void* rider);
int func_0011FE98(void* rider);
// PORT: func_0011FE78 is defined with one parameter but this caller passes (rider, 1).
void func_0011FE78_impl_13F178(void* rider, int v) __asm__("func_0011FE78__FPv");
extern char* D_004A3500;
extern int D_004A115C;
extern void* D_004A28A8;

struct sInfo_13F178 {
    sVec4HP pos;
    sVec4HP dir;
    sVec4HP up;
    int f30;
} __attribute__((aligned(16)));

extern "C" void func_0010EB30(void* rider, int a1, int a2, int a3, sInfo_13F178* info);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4HP vu0Scale_13F178(const sVec4HP& v, float s)
{
    sVec4HP r;
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
static inline sVec4HP vu0Add_13F178(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4HP vu0Normalize_13F178(const sVec4HP& v)
{
    sVec4HP r;
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vu0Length_13F178(const sVec4HP& v)
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

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void vu0ScaleEq_13F178(sVec4HP& v, float s)
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

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_13F178(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

#define RIDER_13F178 (*(char**)((char*)self + 0x18))

extern "C" void func_0013F178(void* self)
{
    if (*(int*)((char*)self + 0xC) != 0) {
        func_00114298(RIDER_13F178, -1.0f);
    } else {
        char* r = RIDER_13F178;
        int idx = *(int*)(r + 0x438);
        char* e = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x44) + idx * 0xB0;
        int fl;
        if (idx == 0x12) {
            sInfo_13F178 info;
            info.pos = *(sVec4HP*)(r + 0x110);
            info.dir = vu0Normalize_13F178(*(sVec4HP*)(r + 0x1E0));
            info.up = *(sVec4HP*)(RIDER_13F178 + 0x370);
            info.f30 = 0;
            func_0010EB30(RIDER_13F178, 0x168, 0, *(int*)(RIDER_13F178 + 0x438), &info);
        } else if (*(int*)(e + 0x44) != 0 || (fl = *(short*)(r + 0x2D4), (fl & 2) != 0)) {
            func_00116120(r, 0, 1);
        }
    }
    func_0011E150_v13F178(RIDER_13F178, 0);
    *(int*)(*(char**)(RIDER_13F178 + 0xAA0) + 0x28) = D_004A115C;
    func_0013F488(self);
    *(unsigned int*)(*(char**)(RIDER_13F178 + 0xAA0) + 0x28) = 0xFFFFFFFF;
    func_00105398(RIDER_13F178, 0);
    func_00107888(RIDER_13F178);
    if (*(int*)((char*)self + 0xC) != 0 && func_0011FE98(RIDER_13F178) == 0) {
        func_0011FE78_impl_13F178(RIDER_13F178, 1);
        func_00294170(D_004A3500, RIDER_13F178);
    }
    char* r = RIDER_13F178;
    *(sVec4HP*)(r + 0x390) = vu0Normalize_13F178(vu0Add_13F178(*(sVec4HP*)(RIDER_13F178 + 0x390), vu0Scale_13F178(*(sVec4HP*)(r + 0x370), 0.5f)));
    char* r3 = RIDER_13F178;
    float len = vu0Length_13F178(*(sVec4HP*)(r3 + 0x1E0));
    if (*(float*)(r3 + 0x2E4) < len) {
        vu0ScaleEq_13F178(*(sVec4HP*)(r3 + 0x1E0), *(float*)(r3 + 0x2E4) / len);
    }
    float k = 0.0f;
    float vmax = 3333.33349609375f;
    if (0.0f <= len) {
        k = 1.0f;
        if (len <= vmax) {
            k = len / vmax;
        }
    }
    *(float*)(RIDER_13F178 + 0x75C) = k;
    char* r4 = RIDER_13F178;
    *(float*)(r4 + 0x754) = absf_13F178(*(float*)(r4 + 0x1F0));
    char* r5 = RIDER_13F178;
    *(float*)(r5 + 0x750) = absf_13F178(*(float*)(r5 + 0x214));
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013F410);
#ifdef SKIP_ASM
extern "C" int func_001298C8();

extern "C" void func_0013F410(void* self)
{
    char* a = *(char**)((char*)self + 0x18);
    *(int*)(a + 0x2C4) = 0;
    *(float*)(a + 0x2C0) = 0.05000000447034836f;
    char* b = *(char**)((char*)self + 0x18);
    *(float*)(b + 0x20C) = 0.05000000447034836f;
    *(int*)(b + 0x210) = 0;
    char* c = *(char**)((char*)self + 0x18);
    *(float*)(c + 0x2CC) = 1.6666667461395264f;
    *(int*)(c + 0x2D0) = 0;
    if (*(int*)((char*)self + 0x14) == -1)
        *(int*)((char*)self + 0x14) = func_001298C8() - 500;
    else
        *(int*)((char*)self + 0x14) = func_001298C8();
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013F488);
#ifdef SKIP_ASM
extern "C" void cRider_updateOrientationImplicit(void*);
int func_0011FEE8(void* rider);
extern "C" float func_003342D0(void* world, void* seg, void* hit, int flags);
extern "C" void func_00106538(void* rider, void* v);
extern "C" void func_001065B0(void* rider, void* hit);
extern "C" void func_00105D98(void* rider, void* info, int id);
extern "C" void* func_0028B180();
extern "C" void func_002989A8(void* snd, void* rider);
extern "C" void* func_0032F650(void* self, void* tree, int flag);
extern "C" void func_0032F708(void* self, int flags);

struct sHit_13F488 {
    sVec4HP pos;            // 0x00
    sVec4HP normal;         // 0x10
    sVec4HP v20;            // 0x20
    float pad30[4];         // 0x30
    float dist;             // 0x40
    int pad44[2];           // 0x44
    int m4C;                // 0x4C
    char* obj;              // 0x50
    char* tri;              // 0x54
    int pad58[5];           // 0x58
    float m6C;              // 0x6C
    float m70;              // 0x70
    int pad74[3];           // 0x74
} __attribute__((aligned(16)));

struct sSphere_13F488 {
    int state;              // 0x00
    int f4;                 // 0x04
    int f8;                 // 0x08
    int padC;               // 0x0C
    sVec4HP dir;            // 0x10
    char rest[0x320 - 0x20];
} __attribute__((aligned(16)));

struct sInfo_13F488 {
    sVec4HP pos;
    sVec4HP dir;
    sVec4HP normal;
    float depth;
} __attribute__((aligned(16)));

struct sVEnt_13F488 { short delta; short index; bool (*fn)(void*); };
struct sVEntH_13F488 { short delta; short index; void (*fn)(void*, void*); };

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4HP vu0Scale_13F488(const sVec4HP& v, float s)
{
    sVec4HP r;
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
static inline sVec4HP vu0Sub_13F488(const sVec4HP& a, const sVec4HP& b)
{
    sVec4HP r;
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

// PORT: PS2-only VU0 inline asm (in-place vector add).
static inline void vu0AddEq_13F488(sVec4HP& a, const sVec4HP& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b));
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_13F488(const sVec4HP& a, const sVec4HP& b)
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4HP vu0Normalize_13F488(const sVec4HP& v)
{
    sVec4HP r;
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

// PORT: PS2 FPU abs.s via inline asm; use fabsf off-PS2.
static inline float absf_13F488(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline bool riderFlag_13F488(char* r)
{
    char* sub = r + 0x6C0;
    sVEnt_13F488* vt = *(sVEnt_13F488**)sub;
    return vt[8].fn(sub + vt[8].delta);
}

#define RIDER (*(char**)((char*)self + 0x18))
#define RV(off) (*(sVec4HP*)(RIDER + (off)))

extern "C" void func_0013F488(void* self)
{
    if (func_0011FEE8(RIDER) == 9)
        return;
    if (!riderFlag_13F488(RIDER)) {
        char* r = RIDER;
        if (*(float*)(r + 0x4C8) < 50.0f && absf_13F488(*(float*)(r + 0x498) - *(float*)(r + 0x118)) < 50.0f)
            return;
    }
    sHit_13F488 hit;
    sSphere_13F488 sph;
    char* r = RIDER;
    func_0032F650(&sph, *(void**)(r + 0xAA0), !riderFlag_13F488(r));
    sph.f8 = 1;
    sph.dir = RV(0x370);
    float d = func_003342D0(*(void**)(RIDER + 0x860), &sph, &hit, *(int*)(RIDER + 0x868));
    if (d < 0.0f)
        { func_0032F708(&sph, 2); return; }
    if (hit.obj != 0) {
        char* h = *(char**)(hit.obj + 0xC);
        if (h) {
            sVEntH_13F488* vt = *(sVEntH_13F488**)(h + 0xC);
            vt[42].fn(h + vt[42].delta, &hit);
        }
    }
    {
        float dot = vu0Dot_13F488(RV(0x370), hit.normal);
        if (dot < -0.9998999834060669f)
            { func_0032F708(&sph, 2); return; }
        if (dot < 0.0f)
            hit.normal = vu0Normalize_13F488(vu0Sub_13F488(hit.normal, vu0Scale_13F488(RV(0x370), dot)));
    }
    {
        sVec4HP push = vu0Scale_13F488(vu0Scale_13F488(hit.normal, 1.100000023841858f), d);
        func_00106538(RIDER, &push);
        sVec4HP a = vu0Sub_13F488(RV(0x1E0), hit.v20);
        float dot2 = vu0Dot_13F488(vu0Scale_13F488(hit.normal, -1.0f), a);
        if (dot2 < 0.0f)
            { func_0032F708(&sph, 2); return; }
        sVec4HP n = vu0Normalize_13F488(a);
        float k = dot2 * 0.05000000074505806f;
        if (k < 27.77777862548828f)
            k = 27.77777862548828f;
        vu0AddEq_13F488(RV(0x1E0), vu0Scale_13F488(hit.normal, dot2 + k));
        func_001065B0(RIDER, &hit);
        cRider_updateOrientationImplicit(RIDER);
        sInfo_13F488 info;
        info.pos = hit.pos;
        info.dir = n;
        info.normal = hit.normal;
        info.depth = dot2;
        func_00105D98(RIDER, &info, hit.m4C);
        func_002989A8(func_0028B180(), RIDER);
    }
    func_0032F708(&sph, 2);
}
#undef RV
#undef RIDER
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013F848);
#ifdef SKIP_ASM
struct sVEntry0013F848 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0013F848(void* self, void* obj)
{
    sVEntry0013F848* vt = *(sVEntry0013F848**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x18);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013F880);
#ifdef SKIP_ASM
struct sVEntry0013F880 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0013F880(void* self, void* obj)
{
    sVEntry0013F880* vt = *(sVEntry0013F880**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x18);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013F8B8);
#ifdef SKIP_ASM
extern "C" void* func_0013F8B8(void* self, ...)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013F8F8);
#ifdef SKIP_ASM
struct sSortObj_F8F8 {
    char pad[0x78];
    unsigned int key;   // 0x78
};

// Merge sort of an object-pointer array by key, using buf as scratch; the sorted result ends up in buf.
extern "C" void func_0013F8F8(sSortObj_F8F8** first, sSortObj_F8F8** last, sSortObj_F8F8** buf, void* cmp)
{
    int n = last - first;
    if (n == 2) {
        if (first[0]->key < first[1]->key) {
            buf[0] = first[0];
            buf[1] = first[1];
        } else {
            buf[0] = first[1];
            buf[1] = first[0];
        }
        return;
    }
    sSortObj_F8F8** mid = first + (n + 1) / 2;
    sSortObj_F8F8** bmid = buf + n / 2;
    sSortObj_F8F8** bend = buf + n;
    if (n < 3)
        *bmid = *first;
    else
        func_0013F8F8(first, mid, bmid, cmp);
    if (n < 4)
        *first = *mid;
    else
        func_0013F8F8(mid, last, first, cmp);
    sSortObj_F8F8** b = bmid;
    sSortObj_F8F8** bend2 = bmid + (n + 1) / 2;
    sSortObj_F8F8** a = first;
    sSortObj_F8F8** aend = first + n / 2;
    sSortObj_F8F8** out = buf;
    while (out < bend) {
        if (a < aend) {
            if (b < bend2 && (*b)->key < (*a)->key)
                *out++ = *b++;
            else
                *out++ = *a++;
        } else {
            *out++ = *b++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_0013FAD8);
#ifdef SKIP_ASM
// Sort entry point: small ranges are handled inline, larger ones go to the merge sort.
struct sSortObj_FAD8;
extern "C" void func_0013F8F8_FAD8(sSortObj_FAD8**, sSortObj_FAD8**, sSortObj_FAD8**, void*) __asm__("func_0013F8F8");
extern "C" void func_0013FAD8(sSortObj_FAD8** first, sSortObj_FAD8** last, sSortObj_FAD8** buf, void* cmp)
{
    int n = last - first;
    if (n >= 2)
        func_0013F8F8_FAD8(first, last, buf, cmp);
    else if (n == 1)
        *buf = *first;
}
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_0013FB20);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140680);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern void* D_00459CC8[];

extern "C" void func_00140680(int* self, int flags)
{
    *(void***)self = D_00459CC8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

extern void* D_004FF120[];

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001406B0__FPv);
#ifdef SKIP_ASM
void* func_001406B0(void* self)
{
    return (void*)D_004FF120;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001406C0__FPv);
#ifdef SKIP_ASM
int func_001406C0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001406C8__FPv);
#ifdef SKIP_ASM
void func_001406C8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001406D0__FPv);
#ifdef SKIP_ASM
void* func_001406D0(void* self)
{
    return (void*)D_004FF120;
}
#endif

extern void* D_004FF1A0[];

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001406E0__FPv);
#ifdef SKIP_ASM
void* func_001406E0(void* self)
{
    return (void*)D_004FF1A0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001406F0__FPv);
#ifdef SKIP_ASM
int func_001406F0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001406F8__FPv);
#ifdef SKIP_ASM
int func_001406F8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140700__FPv);
#ifdef SKIP_ASM
int func_00140700(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140708__FPv);
#ifdef SKIP_ASM
void func_00140708(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140710__FPv);
#ifdef SKIP_ASM
void func_00140710(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140718__FPv);
#ifdef SKIP_ASM
void func_00140718(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140720__FPv);
#ifdef SKIP_ASM
void func_00140720(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140728__FPv);
#ifdef SKIP_ASM
void func_00140728(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140730__FPv);
#ifdef SKIP_ASM
void func_00140730(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140738);
#ifdef SKIP_ASM
struct sHPC140738 {
    char pad0[0x1F0];
    int v[19][3];           // 0x1F0
    char pad2D4[0x430 - 0x2D4];
    unsigned int u430;      // 0x430
    char pad434[0x5B8 - 0x434];
    unsigned int arr[64];   // 0x5B8
};

extern "C" sHPC140738* func_00140738(sHPC140738* self)
{
    self->v[0][2] = 0;
    self->v[0][0] = 0;
    self->v[0][1] = 0;
    self->v[1][2] = 0;
    self->v[1][0] = 0;
    self->v[1][1] = 0;
    self->v[2][2] = 0;
    self->v[2][0] = 0;
    self->v[2][1] = 0;
    self->v[3][2] = 0;
    self->v[3][0] = 0;
    self->v[3][1] = 0;
    self->v[4][2] = 0;
    self->v[4][0] = 0;
    self->v[4][1] = 0;
    self->v[5][2] = 0;
    self->v[5][0] = 0;
    self->v[5][1] = 0;
    self->v[6][2] = 0;
    self->v[6][0] = 0;
    self->v[6][1] = 0;
    self->v[7][2] = 0;
    self->v[7][0] = 0;
    self->v[7][1] = 0;
    self->v[8][2] = 0;
    self->v[8][0] = 0;
    self->v[8][1] = 0;
    self->v[9][2] = 0;
    self->v[9][0] = 0;
    self->v[9][1] = 0;
    self->v[10][2] = 0;
    self->v[10][0] = 0;
    self->v[10][1] = 0;
    self->v[11][2] = 0;
    self->v[11][0] = 0;
    self->v[11][1] = 0;
    self->v[12][2] = 0;
    self->v[12][0] = 0;
    self->v[12][1] = 0;
    self->v[13][2] = 0;
    self->v[13][0] = 0;
    self->v[13][1] = 0;
    self->v[14][2] = 0;
    self->v[14][0] = 0;
    self->v[14][1] = 0;
    self->v[15][2] = 0;
    self->v[15][0] = 0;
    self->v[15][1] = 0;
    self->v[16][2] = 0;
    self->v[16][0] = 0;
    self->v[16][1] = 0;
    self->v[17][2] = 0;
    self->v[17][0] = 0;
    self->v[17][1] = 0;
    self->v[18][2] = 0;
    self->v[18][0] = 0;
    self->v[18][1] = 0;
    self->u430 = 0xFFFFFFFF;
    unsigned int* p = self->arr;
    for (int i = 63; i != -1; i--, p++) {
        *p = 0xFFFFFFFF;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140868);
#ifdef SKIP_ASM
extern "C" void func_00140868(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x87C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140870);
#ifdef SKIP_ASM
extern "C" int func_00140870(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x87C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140878);
#ifdef SKIP_ASM
extern "C" float func_00140878(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x5A4)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140880);
#ifdef SKIP_ASM
extern "C" int func_00140880(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5A8)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140888);
#ifdef SKIP_ASM
extern "C" int func_00140888(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5AC)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140890);
#ifdef SKIP_ASM
extern "C" float func_00140890(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x750)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140898);
#ifdef SKIP_ASM
extern "C" float func_00140898(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x754)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408A0);
#ifdef SKIP_ASM
extern "C" float func_001408A0(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x758)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408A8);
#ifdef SKIP_ASM
extern "C" float func_001408A8(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x75C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408B0);
#ifdef SKIP_ASM
extern "C" int func_001408B0(int arg0) {
    return arg0 + 0x400;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408B8);
#ifdef SKIP_ASM
extern "C" int func_001408B8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAA0)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408C0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long long *func_001408C0(long long *arg0, void *arg1) {
    *arg0 = (*(long long *)((char*)(arg1) + (0x1B0)));
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408D0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long long *func_001408D0(long long *arg0, void *arg1) {
    *arg0 = (*(long long *)((char*)(arg1) + (0x1A0)));
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408E0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long long *func_001408E0(long long *arg0, void *arg1) {
    *arg0 = (*(long long *)((char*)(arg1) + (0x1C0)));
    return arg0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408F0__FPv);
#ifdef SKIP_ASM
void* func_001408F0(void* self)
{
    return (char*)self + 0x110;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001408F8);
#ifdef SKIP_ASM
extern "C" int func_001408F8(int arg0) {
    return arg0 + 0x110;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140900);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long long *func_00140900(long long *arg0, void *arg1) {
    *arg0 = (*(long long *)((char*)(arg1) + (0x120)));
    return arg0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140910__FPv);
#ifdef SKIP_ASM
void* func_00140910(void* self)
{
    return (char*)self + 0x1E0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140918);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_00140918(void *arg0, long long *arg1) {
    (*(long long *)((char*)(arg0) + (0x1E0))) = (long long) *arg1;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140928);
#ifdef SKIP_ASM
struct sMat4HP {
    float m[16];
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMat_140928(sMat4HP& dst, const sMat4HP& src)
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
        "1:\n"
        : : "r"(&dst), "r"(&src) : "memory");
}

extern "C" sMat4HP* func_00140928(sMat4HP* dst, void* self)
{
    vu0CopyMat_140928(*dst, *(sMat4HP*)((char*)self + 0x160));
    return dst;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140958);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long long *func_00140958(long long *arg0, void *arg1) {
    *arg0 = (*(long long *)((char*)(arg1) + (0x370)));
    return arg0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140968);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" float func_0031C228(float);

static inline t4Vector getVec_0968(void* self) {
    return *(t4Vector*)((char*)self + 0x1B0);
}

static inline float atan2_0968(float y, float x) {
    float a;

    if (x == 0.0f) {
        if (y == 0.0f) {
            return y;
        }
        if (y >= 0.0f) {
            return 1.5707963705062866f;
        }
        return -1.5707963705062866f;
    }
    a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f) {
            a += 3.1415927410125732f;
        } else {
            a -= 3.1415927410125732f;
        }
    }
    return a;
}

extern "C" float func_00140968(void* self) {
    return atan2_0968(getVec_0968(self).y, getVec_0968(self).x);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A28);
#ifdef SKIP_ASM
extern "C" int func_00140A28(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x780)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A30);
#ifdef SKIP_ASM
extern "C" int func_00140A30(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x784)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A38);
#ifdef SKIP_ASM
extern "C" int func_00140A38(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x77C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A40);
#ifdef SKIP_ASM
extern "C" int func_00140A40(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x430)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A48);
#ifdef SKIP_ASM
extern "C" int func_00140A48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x434)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A50);
#ifdef SKIP_ASM
extern "C" int func_00140A50(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x434))) < 0x11;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A60);
#ifdef SKIP_ASM
extern "C" int func_00140A60(void *arg0) {
    return (unsigned int) ((*(int *)((char*)(arg0) + (0x434))) - 0xB) < 3U;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A70);
#ifdef SKIP_ASM
extern "C" int func_00140A70(int arg0) {
    return arg0 + 0xAAC;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A78);
#ifdef SKIP_ASM
extern "C" int func_00140A78(int arg0) {
    return arg0 + 0x490;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A80);
#ifdef SKIP_ASM
extern "C" int func_00140A80(int arg0) {
    return arg0 + 0x4A0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A88);
#ifdef SKIP_ASM
extern "C" int func_00140A88(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAB4)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A90);
#ifdef SKIP_ASM
extern "C" void func_00140A90(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xAB4))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140A98);
#ifdef SKIP_ASM
extern "C" int func_00140A98(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAB8)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140AA0);
#ifdef SKIP_ASM
extern "C" void func_00140AA0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xAB8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140AA8);
#ifdef SKIP_ASM
extern "C" void func_00140AA8(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x4D8))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140AB0);
#ifdef SKIP_ASM
extern "C" void func_00140AB0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xE8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140AB8);
#ifdef SKIP_ASM
extern "C" int func_00140AB8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xE8)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140AC0);
#ifdef SKIP_ASM
extern "C" void func_00140AC0(void *arg0) {
    (*(float *)((char*)(arg0) + (0x470))) = -1.0f;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140AD0);
#ifdef SKIP_ASM
extern "C" void func_00140AD0(void *arg0) {
    if ((*(float *)((char*)(arg0) + (0x470))) < 0.0f) {
        (*(float *)((char*)(arg0) + (0x470))) = 0.0f;
    }
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140AF0);
#ifdef SKIP_ASM
extern "C" int func_00140AF0(void *arg0) {
    int var_2;

    var_2 = 1;
    if (!((*(float *)((char*)(arg0) + (0x470))) >= 0.0f)) {
        var_2 = 0;
    }
    return var_2;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B18);
#ifdef SKIP_ASM
extern "C" int func_00140B18(void *arg0) {
    int var_2;

    var_2 = 1;
    if (!((*(float *)((char*)(arg0) + (0x470))) >= 10.0f)) {
        var_2 = 0;
    }
    return var_2;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B40);
#ifdef SKIP_ASM
extern "C" void func_00140B40(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x474))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B48);
#ifdef SKIP_ASM
extern "C" int func_00140B48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x474)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B50);
#ifdef SKIP_ASM
extern "C" void func_00140B50(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x478))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B58);
#ifdef SKIP_ASM
extern "C" int func_00140B58(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x478)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B60);
#ifdef SKIP_ASM
extern "C" void func_00140B60(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x47C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B68);
#ifdef SKIP_ASM
extern "C" int func_00140B68(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x47C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B70);
#ifdef SKIP_ASM
extern "C" void func_00140B70(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x480))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B78);
#ifdef SKIP_ASM
extern "C" int func_00140B78(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x480)));
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B80__FPv);
#ifdef SKIP_ASM
int func_00140B80(void* self)
{
    return *(int*)((char*)self + 0x86C);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B88);
#ifdef SKIP_ASM
extern "C" void func_00140B88(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x86C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B90);
#ifdef SKIP_ASM
extern "C" int func_00140B90(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x870)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140B98);
#ifdef SKIP_ASM
extern "C" void func_00140B98(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x870))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140BA0);
#ifdef SKIP_ASM
extern "C" void func_00140BA0(void *arg0) {
    (*(int *)((char*)(arg0) + (0x874))) = 1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140BB0);
#ifdef SKIP_ASM
extern "C" void func_00140BB0(void *arg0) {
    (*(int *)((char*)(arg0) + (0x878))) = 1;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140BC0__FPv);
#ifdef SKIP_ASM
int func_00140BC0(void* self)
{
    return *(int*)((char*)self + 0x874);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140BC8);
#ifdef SKIP_ASM
extern "C" int func_00140BC8(void* self)
{
    return *(int*)((char*)self + 0x874) ^ 1;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140BD8);
#ifdef SKIP_ASM
extern "C" int func_00140BD8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x878)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140BE0);
#ifdef SKIP_ASM
extern "C" int func_00140BE0(void *arg0) {
    int var_3;

    var_3 = 0;
    if ((*(int *)((char*)(arg0) + (0x874))) != 0) {
        var_3 = (*(int *)((char*)(arg0) + (0x87C))) != 0;
    }
    return var_3;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C00);
#ifdef SKIP_ASM
extern "C" int func_00140C00(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x884)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C08);
#ifdef SKIP_ASM
extern "C" void func_00140C08(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x884))) = arg1;
    (*(int *)((char*)(arg0) + (0x888))) = -1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C18);
#ifdef SKIP_ASM
extern "C" int func_00140C18(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x888)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C20);
#ifdef SKIP_ASM
extern "C" void func_00140C20(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x888))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C28);
#ifdef SKIP_ASM
extern "C" int func_00140C28(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3FC)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C30);
#ifdef SKIP_ASM
extern "C" void func_00140C30(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x3FC))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C38);
#ifdef SKIP_ASM
extern "C" int func_00140C38(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x790)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C40);
#ifdef SKIP_ASM
extern "C" int func_00140C40(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x788)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C48);
#ifdef SKIP_ASM
extern "C" int func_00140C48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x774)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C50);
#ifdef SKIP_ASM
extern "C" void func_00140C50(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x774))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C58);
#ifdef SKIP_ASM
extern "C" int func_00140C58(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x778)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C60);
#ifdef SKIP_ASM
extern "C" void func_00140C60(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x778))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C68__FPv);
#ifdef SKIP_ASM
void func_00140C68(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C70__FPv);
#ifdef SKIP_ASM
void func_00140C70(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C78__FPv);
#ifdef SKIP_ASM
void func_00140C78(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C80__FPv);
#ifdef SKIP_ASM
void func_00140C80(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C88);
#ifdef SKIP_ASM
extern "C" int func_00140C88(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x898)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C90);
#ifdef SKIP_ASM
extern "C" int func_00140C90(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x78C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140C98);
#ifdef SKIP_ASM
extern "C" int func_00140C98(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAA8)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140CA0);
#ifdef SKIP_ASM
extern "C" float func_00140CA0(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x5B4)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140CA8);
#ifdef SKIP_ASM
extern "C" int func_00140CA8(void *arg0) {
    int var_3;

    var_3 = 0;
    if (((*(int *)((char*)(arg0) + (0xAC4))) != 0) && ((*(int *)((char*)(arg0) + (0xAD0))) == 0)) {
        var_3 = (*(int *)((char*)(arg0) + (0xAFC))) != 0;
    }
    return var_3;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140CD0);
#ifdef SKIP_ASM
extern "C" int func_00140CD0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB00)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140CD8);
#ifdef SKIP_ASM
extern "C" int func_00140CD8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAC4)));
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140CE0__FPv);
#ifdef SKIP_ASM
void* func_00140CE0(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140CE8);
#ifdef SKIP_ASM
extern "C" int func_00140CE8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB18)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140CF0);
#ifdef SKIP_ASM
extern "C" void func_00120D58(void * self);

extern "C" void func_00140CF0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x304))) = arg1;
    func_00120D58(arg0);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D10);
#ifdef SKIP_ASM
extern "C" void func_00140D10(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xB20))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D18);
#ifdef SKIP_ASM
extern "C" void func_00140D18(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0xB24))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D20);
#ifdef SKIP_ASM
extern "C" void func_00140D20(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xB28))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D28);
#ifdef SKIP_ASM
extern "C" void func_00140D28(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xB30))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D30);
#ifdef SKIP_ASM
extern "C" void func_00140D30(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xB34))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D38);
#ifdef SKIP_ASM
extern "C" void func_00140D38(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x308))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D40);
#ifdef SKIP_ASM
extern "C" int func_00140D40(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x304)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D48);
#ifdef SKIP_ASM
extern "C" int func_00140D48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB20)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D50);
#ifdef SKIP_ASM
extern "C" int func_00140D50(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB2C))) & 1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D60);
#ifdef SKIP_ASM
extern "C" int func_00140D60(void *arg0) {
    return ((int) (*(int *)((char*)(arg0) + (0xB2C))) >> 1) & 1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D70);
#ifdef SKIP_ASM
extern "C" int func_00140D70(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB30)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D78);
#ifdef SKIP_ASM
extern "C" int func_00140D78(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x308)));
}
#endif

#ifdef SKIP_ASM
// Controller classes derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable
// fix-ups for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted
// when not most-derived). Only the cRider layout that matters to that code is modelled: polymorphic bases at
// +0x6C0 (primary, 21 virtuals), +0x6D0 and +0x6E8 (7 virtuals), each with a virtual dtor except +0x6D0.
class cRiderVbA0_hpc {
public:
    virtual ~cRiderVbA0_hpc();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_hpc : public cRiderVbA0_hpc { public: char padA[0xC]; };
class cRiderVbB0_hpc { public: virtual void b01(); };
class cRiderVbB_hpc : public cRiderVbB0_hpc { public: char padB[0x14]; };
class cRiderVbC0_hpc {
public:
    virtual ~cRiderVbC0_hpc();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_hpc : public cRiderVbC0_hpc { public: char padC[0x10]; };
class cRiderVbBC_hpc : public cRiderVbB_hpc, public cRiderVbC_hpc { public: };
class cRiderVbPad_hpc { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_hpc : public cRiderVbPad_hpc, public cRiderVbA_hpc, public cRiderVbBC_hpc {
public:
    virtual ~cRiderVb_hpc();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140D80);
#ifdef SKIP_ASM
struct cVbHead00140D80 {
    char pad[0x18];
};

class cVbDtor00140D80 : public cVbHead00140D80, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00140D80();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00140D80::~cVbDtor00140D80()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00140D80; expose it under the address-derived name.
__asm__(".globl func_00140D80\n.type func_00140D80,@function\nfunc_00140D80 = _$_15cVbDtor00140D80\n.size func_00140D80,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00140EE0);
#ifdef SKIP_ASM
struct cVbHead00140EE0 {
    char pad[0x4];
};

class cVbDtor00140EE0 : public cVbHead00140EE0, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00140EE0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00140EE0::~cVbDtor00140EE0()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00140EE0; expose it under the address-derived name.
__asm__(".globl func_00140EE0\n.type func_00140EE0,@function\nfunc_00140EE0 = _$_15cVbDtor00140EE0\n.size func_00140EE0,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141040);
#ifdef SKIP_ASM
struct cVbHead00141040 {
    char pad[0x50];
};

class cVbDtor00141040 : public cVbHead00141040, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141040();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141040::~cVbDtor00141040()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141040; expose it under the address-derived name.
__asm__(".globl func_00141040\n.type func_00141040,@function\nfunc_00141040 = _$_15cVbDtor00141040\n.size func_00141040,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001411A0);
#ifdef SKIP_ASM
extern "C" int func_001411A0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x44)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001411A8);
#ifdef SKIP_ASM
extern "C" int func_001411A8(int arg0) {
    return arg0 + 0x50;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001411B0);
#ifdef SKIP_ASM
extern "C" int func_001411B0(int *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001411B8);
#ifdef SKIP_ASM
extern "C" int func_001411B8(int arg0) {
    return arg0 + 0x30;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001411C0);
#ifdef SKIP_ASM
class cHandPlant11C0 : virtual public cRiderVb_hpc {
public:
    virtual ~cHandPlant11C0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cHandPlant11C0::~cHandPlant11C0()
{
}
// PORT: the compiler names this dtor _$_14cHandPlant11C0; expose it under the address-derived name.
__asm__(".globl func_001411C0\n.type func_001411C0,@function\nfunc_001411C0 = _$_14cHandPlant11C0\n.size func_001411C0,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141320);
#ifdef SKIP_ASM
struct cVbHead00141320 {
    char pad[0xA0];
};

class cVbDtor00141320 : public cVbHead00141320, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141320();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141320::~cVbDtor00141320()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141320; expose it under the address-derived name.
__asm__(".globl func_00141320\n.type func_00141320,@function\nfunc_00141320 = _$_15cVbDtor00141320\n.size func_00141320,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141480);
#ifdef SKIP_ASM
extern "C" void* cRider_cRider(void* self);

struct sVEntry_00141480 { short delta; short index; void* fn; };
struct sVtblA_00141480 { sVEntry_00141480 e[9]; } __attribute__((aligned(8)));
struct sVtblB_00141480 { sVEntry_00141480 e[22]; } __attribute__((aligned(8)));

extern const sVtblA_00141480 D_004595C0_00141480 __asm__("D_004595C0");
extern char D_00459B90[];
extern const sVtblB_00141480 D_00459608_00141480 __asm__("D_00459608");

// PORT: g++ 2.95 virtual-base construction. The class derives virtually from cRider (vbase pointer at
// +0xA0, vbase at +0xB0); when not most-derived, g++ copies cRider's overridden vtables to the stack
// and fixes up the this-deltas (expand_upcast_fixups). Written out by hand here.
extern "C" void* func_00141480(void* self, int inChrg)
{
    if (inChrg)
    {
        char* vb = (char*)self + 0xB0;
        *(char**)((char*)self + 0xA0) = vb;
        cRider_cRider(vb);
    }
    *(void**)(*(char**)((char*)self + 0xA0) + 0x6E8) = (void*)&D_004595C0_00141480;
    *(void**)(*(char**)((char*)self + 0xA0) + 0x6D0) = D_00459B90;
    *(void**)(*(char**)((char*)self + 0xA0) + 0x6C0) = (void*)&D_00459608_00141480;
    if (!inChrg)
    {
        sVtblA_00141480 t1 = D_004595C0_00141480;
        *(void**)(*(char**)((char*)self + 0xA0) + 0x6E8) = &t1;
        char* base = *(char**)((char*)self + 0xA0) - 0xB0;
        int d = (char*)self - base;
        t1.e[1].delta = D_004595C0_00141480.e[1].delta + d;
        sVtblB_00141480 t2 = D_00459608_00141480;
        *(void**)(*(char**)((char*)self + 0xA0) + 0x6C0) = &t2;
        t2.e[1].delta = D_00459608_00141480.e[1].delta + d;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001415C8);
#ifdef SKIP_ASM
class cVbDtor001415C8 : virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor001415C8();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor001415C8::~cVbDtor001415C8()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor001415C8; expose it under the address-derived name.
__asm__(".globl func_001415C8\n.type func_001415C8,@function\nfunc_001415C8 = _$_15cVbDtor001415C8\n.size func_001415C8,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141728);
#ifdef SKIP_ASM
struct cVbHead00141728 {
    char pad[0x14];
};

class cVbDtor00141728 : public cVbHead00141728, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141728();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141728::~cVbDtor00141728()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141728; expose it under the address-derived name.
__asm__(".globl func_00141728\n.type func_00141728,@function\nfunc_00141728 = _$_15cVbDtor00141728\n.size func_00141728,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141888);
#ifdef SKIP_ASM
class cVbDtor00141888 : virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141888();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141888::~cVbDtor00141888()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141888; expose it under the address-derived name.
__asm__(".globl func_00141888\n.type func_00141888,@function\nfunc_00141888 = _$_15cVbDtor00141888\n.size func_00141888,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001419E8);
#ifdef SKIP_ASM
class cVbDtor001419E8 : virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor001419E8();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor001419E8::~cVbDtor001419E8()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor001419E8; expose it under the address-derived name.
__asm__(".globl func_001419E8\n.type func_001419E8,@function\nfunc_001419E8 = _$_15cVbDtor001419E8\n.size func_001419E8,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141B48);
#ifdef SKIP_ASM
struct cVbHead00141B48 {
    char pad[0x14];
};

class cVbDtor00141B48 : public cVbHead00141B48, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141B48();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141B48::~cVbDtor00141B48()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141B48; expose it under the address-derived name.
__asm__(".globl func_00141B48\n.type func_00141B48,@function\nfunc_00141B48 = _$_15cVbDtor00141B48\n.size func_00141B48,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141CA8);
#ifdef SKIP_ASM
struct cVbHead00141CA8 {
    char pad[0x58];
};

class cVbDtor00141CA8 : public cVbHead00141CA8, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141CA8();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141CA8::~cVbDtor00141CA8()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141CA8; expose it under the address-derived name.
__asm__(".globl func_00141CA8\n.type func_00141CA8,@function\nfunc_00141CA8 = _$_15cVbDtor00141CA8\n.size func_00141CA8,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141E08);
#ifdef SKIP_ASM
struct cVbHead00141E08 {
    char pad[0x14];
};

class cVbDtor00141E08 : public cVbHead00141E08, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141E08();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141E08::~cVbDtor00141E08()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141E08; expose it under the address-derived name.
__asm__(".globl func_00141E08\n.type func_00141E08,@function\nfunc_00141E08 = _$_15cVbDtor00141E08\n.size func_00141E08,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00141F68);
#ifdef SKIP_ASM
struct cVbHead00141F68 {
    char pad[0x8];
};

class cVbDtor00141F68 : public cVbHead00141F68, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00141F68();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00141F68::~cVbDtor00141F68()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00141F68; expose it under the address-derived name.
__asm__(".globl func_00141F68\n.type func_00141F68,@function\nfunc_00141F68 = _$_15cVbDtor00141F68\n.size func_00141F68,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001420C8);
#ifdef SKIP_ASM
struct cVbHead001420C8 {
    char pad[0x8];
};

class cVbDtor001420C8 : public cVbHead001420C8, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor001420C8();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor001420C8::~cVbDtor001420C8()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor001420C8; expose it under the address-derived name.
__asm__(".globl func_001420C8\n.type func_001420C8,@function\nfunc_001420C8 = _$_15cVbDtor001420C8\n.size func_001420C8,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00142228);
#ifdef SKIP_ASM
struct cVbHead00142228 {
    char pad[0x80];
};

class cVbDtor00142228 : public cVbHead00142228, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00142228();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00142228::~cVbDtor00142228()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00142228; expose it under the address-derived name.
__asm__(".globl func_00142228\n.type func_00142228,@function\nfunc_00142228 = _$_15cVbDtor00142228\n.size func_00142228,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00142388);
#ifdef SKIP_ASM
extern "C" void* cRider_cRider(void* self);

struct sVEntry_00142388 { short delta; short index; void* fn; };
struct sVtblA_00142388 { sVEntry_00142388 e[9]; } __attribute__((aligned(8)));
struct sVtblB_00142388 { sVEntry_00142388 e[22]; } __attribute__((aligned(8)));

extern const sVtblA_00142388 D_00458C10_00142388 __asm__("D_00458C10");
extern char D_00459B90[];
extern const sVtblB_00142388 D_00458C58_00142388 __asm__("D_00458C58");

// PORT: g++ 2.95 virtual-base construction. The class derives virtually from cRider (vbase pointer at
// +0x80, vbase at +0x90); when not most-derived, g++ copies cRider's overridden vtables to the stack
// and fixes up the this-deltas (expand_upcast_fixups). Written out by hand here.
extern "C" void* func_00142388(void* self, int inChrg)
{
    if (inChrg)
    {
        char* vb = (char*)self + 0x90;
        *(char**)((char*)self + 0x80) = vb;
        cRider_cRider(vb);
    }
    *(void**)(*(char**)((char*)self + 0x80) + 0x6E8) = (void*)&D_00458C10_00142388;
    *(void**)(*(char**)((char*)self + 0x80) + 0x6D0) = D_00459B90;
    *(void**)(*(char**)((char*)self + 0x80) + 0x6C0) = (void*)&D_00458C58_00142388;
    if (!inChrg)
    {
        sVtblA_00142388 t1 = D_00458C10_00142388;
        *(void**)(*(char**)((char*)self + 0x80) + 0x6E8) = &t1;
        char* base = *(char**)((char*)self + 0x80) - 0x90;
        int d = (char*)self - base;
        t1.e[1].delta = D_00458C10_00142388.e[1].delta + d;
        sVtblB_00142388 t2 = D_00458C58_00142388;
        *(void**)(*(char**)((char*)self + 0x80) + 0x6C0) = &t2;
        t2.e[1].delta = D_00458C58_00142388.e[1].delta + d;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001424D0);
#ifdef SKIP_ASM
struct cVbHead001424D0 {
    char pad[0x4];
};

class cVbDtor001424D0 : public cVbHead001424D0, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor001424D0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor001424D0::~cVbDtor001424D0()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor001424D0; expose it under the address-derived name.
__asm__(".globl func_001424D0\n.type func_001424D0,@function\nfunc_001424D0 = _$_15cVbDtor001424D0\n.size func_001424D0,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00142630);
#ifdef SKIP_ASM
struct cVbHead00142630 {
    char pad[0x8];
};

class cVbDtor00142630 : public cVbHead00142630, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00142630();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00142630::~cVbDtor00142630()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00142630; expose it under the address-derived name.
__asm__(".globl func_00142630\n.type func_00142630,@function\nfunc_00142630 = _$_15cVbDtor00142630\n.size func_00142630,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00142790);
#ifdef SKIP_ASM
class cVbDtor00142790 : virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor00142790();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00142790::~cVbDtor00142790()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor00142790; expose it under the address-derived name.
__asm__(".globl func_00142790\n.type func_00142790,@function\nfunc_00142790 = _$_15cVbDtor00142790\n.size func_00142790,0x15C\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001428F0);
#ifdef SKIP_ASM
struct cVbHead001428F0 {
    char pad[0x14];
};

class cVbDtor001428F0 : public cVbHead001428F0, virtual public cRiderVb_hpc {
public:
    virtual ~cVbDtor001428F0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor001428F0::~cVbDtor001428F0()
{
}
// PORT: the compiler names this dtor _$_15cVbDtor001428F0; expose it under the address-derived name.
__asm__(".globl func_001428F0\n.type func_001428F0,@function\nfunc_001428F0 = _$_15cVbDtor001428F0\n.size func_001428F0,0x15C\n");
#endif

INCLUDE_ASM("ai/control/handplantcontrol", func_00142A50);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00143FF0);
#ifdef SKIP_ASM
extern "C" int func_00143FF0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xDE0)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00143FF8);
#ifdef SKIP_ASM
extern "C" int func_00143FF8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xDE4)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144000);
#ifdef SKIP_ASM
extern "C" void func_00144000(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xF40))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144008);
#ifdef SKIP_ASM
extern "C" int func_00144008(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xE70)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144010);
#ifdef SKIP_ASM
extern "C" int func_00144010(void *arg0, float fparg0) {
    int var_3;

    var_3 = 0;
    if (((*(int *)((char*)(arg0) + (0xE20))) != 0) && (fparg0 < 1.0f)) {
        var_3 = 1;
    }
    return var_3;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144040);
#ifdef SKIP_ASM
class cObj_4040;
typedef void (cObj_4040::*Fn_4040)();
extern Fn_4040 D_0043CF20_4040[] __asm__("D_0043CF20");

extern "C" void func_00144040(char* self, int idx)
{
    *(Fn_4040*)(self + 0xF44) = D_0043CF20_4040[idx];
    *(short*)(self + 0xF38) = idx;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144068__FPv);
#ifdef SKIP_ASM
void func_00144068(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144070);
#ifdef SKIP_ASM
extern "C" int func_00144070(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA8)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144078);
#ifdef SKIP_ASM
extern "C" int func_00144078(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x78)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144080);
#ifdef SKIP_ASM
extern "C" int func_00144080(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144088);
#ifdef SKIP_ASM
extern "C" int func_00144088(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x80)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144090);
#ifdef SKIP_ASM
extern "C" int func_00144090(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x84)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144098);
#ifdef SKIP_ASM
extern "C" int func_00144098(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x88)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001440A0);
#ifdef SKIP_ASM
extern "C" int func_001440A0(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x28);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001440B0);
#ifdef SKIP_ASM
extern "C" int func_001440B0(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x40);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001440C0);
#ifdef SKIP_ASM
extern "C" int func_001440C0(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x48);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001440D0);
#ifdef SKIP_ASM
extern "C" int func_001440D0(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x5C);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001440E0);
#ifdef SKIP_ASM
extern "C" int func_001440E0(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x70);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001440F0);
#ifdef SKIP_ASM
extern "C" void func_001440F0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001440F8);
#ifdef SKIP_ASM
extern "C" void func_001440F8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x8C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144100);
#ifdef SKIP_ASM
extern "C" int func_00144100(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x8C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144108);
#ifdef SKIP_ASM
extern "C" int func_00144108(void *arg0) {
    return (*(int *)((char*)(arg0) + (8)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144110);
#ifdef SKIP_ASM
extern "C" void func_00144110(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144118);
#ifdef SKIP_ASM
extern "C" int func_00144118(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144120);
#ifdef SKIP_ASM
extern "C" void func_00144120(void *arg0) {
    (*(int *)((char*)(arg0) + (0xC))) = (int) ((*(int *)((char*)(arg0) + (0xC))) + 1);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144130);
#ifdef SKIP_ASM
extern "C" void func_00144130(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144138);
#ifdef SKIP_ASM
extern "C" int func_00144138(void* self)
{
    return (int)((float)*(int*)((char*)self + 0xC) * 0.016666668f);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144158);
#ifdef SKIP_ASM
extern "C" int func_00144158(int *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144160);
#ifdef SKIP_ASM
extern "C" int func_00144160(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144168);
#ifdef SKIP_ASM
extern "C" void func_00144168(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144170);
#ifdef SKIP_ASM
extern "C" void func_00144170(void *self, int index, int value) {
    *(int *)((char *)self + (index << 2) + 0x20) = value;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144180);
#ifdef SKIP_ASM
extern "C" int func_00144180(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x20);
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144190);
#ifdef SKIP_ASM
extern "C" int func_00144190(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144198);
#ifdef SKIP_ASM
extern "C" int func_00144198(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA4)));
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001441A0__FPvT0);
#ifdef SKIP_ASM
int func_001441A0(void* self, void* a1)
{
    int t0 = 2;
    *(int*)((char*)a1 + 0x8) = t0;
    *(int*)((char*)self + 0x704) = (int)((char*)*(void**)((char*)self + 0x704) - 0x1);
    return t0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001441B8);
#ifdef SKIP_ASM
struct sHpVE_41B8 {
    short delta;
    short index;
    float* (*fn)(void*);
};

struct sHpVec3_41B8 {
    float x, y, z;
};

struct sHpGround_41B8 {
    char pad_0x0[0x14];
    float height;           // 0x14
    char pad_0x18[0x8];
};

// Handplant zone: a sphere (type 2 = disabled).
struct sHpZone_41B8 {
    float radius;           // 0x0
    int f4;
    int type;               // 0x8
    sHpVec3_41B8 center;    // 0xC
    int f18;
};

struct sHpLevel_41B8 {
    int level;
    int f4;
    int f8;
};

struct sHpGame_41B8 {
    char pad_0x0[0x28];
    char* riders[8];        // 0x28
};

struct sHpCtl_41B8 {
    sHpGame_41B8* game;     // 0x0
    sHpZone_41B8 zones[64]; // 0x4
    int numZones;           // 0x704
    int useHeight;          // 0x708
    sHpLevel_41B8 levels[4];// 0x70C
};

extern "C" void func_002DA1C0(sHpGround_41B8* out, sHpVec3_41B8* pos);

// Handplant difficulty level for player pl: at least the height band's level, and only above 1 when the rider is
// inside one of the enabled zones.
extern "C" int func_001441B8(sHpCtl_41B8* self, int pl)
{
    int lvl = self->levels[pl].level;
    char* rider = self->game->riders[pl];
    if (lvl == 0) {
        return 0;
    }
    char* o = rider + 0x6C0;
    sHpVE_41B8* vt = *(sHpVE_41B8**)o;
    float* pos = vt[5].fn(o + vt[5].delta);
    if (self->useHeight != 0) {
        sHpGround_41B8 g;
        sHpVec3_41B8 p;
        p.x = pos[0];
        p.y = pos[1];
        p.z = pos[2];
        func_002DA1C0(&g, &p);
        int band = 1;
        if (g.height < 1200.446f) {
            band = 3;
        } else if (g.height < 2999.697f) {
            band = 2;
        }
        if (lvl < band) {
            return band;
        }
    }
    if (lvl < 2) {
        return 1;
    }
    if (self->numZones == 0) {
        return 1;
    }
    int n = self->numZones;
    sHpZone_41B8* z = self->zones;
    for (int i = 0; i < 64 && n != 0; i++, z++) {
        if (z->type == 2) {
            continue;
        }
        n--;
        float d = z->center.x - pos[0];
        float r2 = z->radius * z->radius;
        d = d * d;
        if (r2 < d) {
            continue;
        }
        float dy = z->center.y - pos[1];
        dy = dy * dy;
        if (r2 < dy) {
            continue;
        }
        float dz = z->center.z - pos[2];
        d = d + dy + dz * dz;
        if (!(r2 < d)) {
            return lvl;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144368);
#ifdef SKIP_ASM
struct sKey_144368 {
    int level;
    int x;
    int y;
    int z;
};

struct sBox_144368 {
    float min[4];
    float max[4];
};

struct sTree_144368 {
    void* f0;
    sBox_144368* boxes;
    int count;
};

struct sNode_144368 {
    sNode_144368* child[8];
};

extern "C" void func_00101A28(void* a, sNode_144368* node, int leaf);

extern "C" void func_00144368(sTree_144368* self, sNode_144368* node, sKey_144368* key)
{
    int n = self->count;
    int i = 0;
    int ok;
    do {
        if (i == n) {
            return;
        }
        union { int i; float f; } u;
        u.i = (key->level + 0x7F) << 23;
        float s = u.f;
        // PORT: pointer arithmetic through int
        sBox_144368* b = (sBox_144368*)((i << 5) + (int)self->boxes);
        ok = 0;
        if (((float)key->x - 0.2f) * s <= b->max[0] && ((float)key->y - 0.2f) * s <= b->max[1] && ((float)key->z - 0.2f) * s <= b->max[2]
            && b->min[0] <= ((float)(key->x + 1) + 0.2f) * s && b->min[1] <= ((float)(key->y + 1) + 0.2f) * s && b->min[2] <= ((float)(key->z + 1) + 0.2f) * s) {
            ok = 1;
        }
        i++;
    } while (!ok);
    int leaf = key->level < 14;
    func_00101A28(self->f0, node, leaf);
    if (leaf) {
        return;
    }
    if (key->level == 11) {
        return;
    }
    sKey_144368 k;
    k.level = key->level - 1;
    k.x = key->x * 2;
    k.y = key->y * 2;
    k.z = key->z * 2;
    if (node->child[0]) func_00144368(self, node->child[0], &k);
    k.x++;
    if (node->child[4]) func_00144368(self, node->child[4], &k);
    k.y++;
    if (node->child[6]) func_00144368(self, node->child[6], &k);
    k.x--;
    if (node->child[2]) func_00144368(self, node->child[2], &k);
    k.z++;
    if (node->child[3]) func_00144368(self, node->child[3], &k);
    k.x++;
    if (node->child[7]) func_00144368(self, node->child[7], &k);
    k.y--;
    if (node->child[5]) func_00144368(self, node->child[5], &k);
    k.x--;
    if (node->child[1]) func_00144368(self, node->child[1], &k);
}
#endif

extern "C" void* func_00311958(void* self);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144610__FPv);
#ifdef SKIP_ASM
void* func_00144610(void* self)
{
    return func_00311958(self);
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144630);
#ifdef SKIP_ASM
extern "C" void* cRiderAnimBase_cRiderAnimBase(void* self);
extern void* D_00458458[];

extern "C" void* func_00144630(void* self)
{
    cRiderAnimBase_cRiderAnimBase(self);
    *(void***)((char*)self + 0x58) = D_00458458;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_00144670);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_00144670(void* self, int bit)
{
    ulong mask = (ulong)1 << bit;
    ulong a = *(ulong*)self;
    *(ulong*)self = a & ~mask;
    *(ulong*)((char*)self + 0x8) |= mask & a;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001446A0);
#ifdef SKIP_ASM
extern "C" bool func_001446A0(void* self, int bit)
{
    ulong mask = (ulong)1 << bit;
    return (*(ulong*)self & mask) != 0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001446B8);
#ifdef SKIP_ASM
extern "C" bool func_001446B8(void* self, int bit)
{
    ulong mask = (ulong)1 << bit;
    return (*(ulong*)((char*)self + 0x8) & mask) != 0;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001446D0);
#ifdef SKIP_ASM
extern "C" void func_001446D0(void *self, int a, int b) {
    *(int *)((char *)self + 0xDF0) = a;
    *(int *)((char *)self + 0xDF4) = b;
}
#endif
//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001446E0);
#ifdef SKIP_ASM
extern "C" int func_001446E0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xDF0)));
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001446E8__FPv);
#ifdef SKIP_ASM
float func_001446E8(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001446F8);
#ifdef SKIP_ASM
struct cHpHead_1446F8 { char pad[0x18]; };
class cHpB_1446F8 : public cHpHead_1446F8, virtual public cRiderVb_hpc {
public:
    char body[0xDCC];
    // PORT: overrides of the last five cRider virtuals (their vtable entries get this-adjusted copies)
    virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
    ~cHpB_1446F8();
};
class cHpD1_1446F8 : public cHpB_1446F8 {
public:
    virtual void d01();
};
class cHpD_1446F8 : public cHpD1_1446F8 {
public:
    char tail[0x20];
    virtual ~cHpD_1446F8();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cHpD_1446F8::~cHpD_1446F8()
{
}
// PORT: the compiler names this dtor _$_11cHpD_1446F8; expose it under the address-derived name.
__asm__(".globl func_001446F8\n.type func_001446F8,@function\nfunc_001446F8 = _$_11cHpD_1446F8\n.size func_001446F8,0x1B0\n");
#endif

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001448A8);
#ifdef SKIP_ASM
extern "C" int func_001448A8(void* self)
{
    return *(int*)((char*)self + 0x70) == 3;
}
#endif

extern "C" void* func_0013FB20(int, int);

//100%
INCLUDE_ASM("ai/control/handplantcontrol", func_001448B8__FPv);
#ifdef SKIP_ASM
void* func_001448B8(void* self)
{
    return func_0013FB20(1, 0xffff);
}
#endif

