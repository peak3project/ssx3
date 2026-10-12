#include "common.h"

//100%
INCLUDE_ASM("seg/seg_14B10", cAI_setAIState);
#ifdef SKIP_ASM
extern "C" void cAI_forceAIState(void *);

extern "C" void cAI_setAIState(void *arg0, int arg1) {
    int old = *(int *)((char*)arg0 + 0);
    if (arg1 != old) {
        *(int *)((char*)arg0 + 4) = old;
        *(int *)((char*)arg0 + 0x9C) = *(int *)((char*)arg0 + 0x98);
        cAI_forceAIState(arg0);
    }
}
#endif

INCLUDE_ASM("seg/seg_14B10", cAI_forceAIState);

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113C20);
#ifdef SKIP_ASM
class cAIState_3C20 {
public:
    virtual void m0(void *);
    virtual void m1(void *);
    virtual void m2(void *);
};

extern "C" void func_00113C20(char *self) {
    if (*(int *)(self + 4) != *(int *)(self + 0)) {
        cAIState_3C20 *prev = *(cAIState_3C20 **)(self + 0x9C);
        if (prev != 0)
            prev->m1(self);
        (*(cAIState_3C20 **)(self + 0x98))->m0(self);
        *(cAIState_3C20 **)(self + 0x9C) = 0;
        *(int *)(self + 4) = *(int *)(self + 0);
    }
    (*(cAIState_3C20 **)(self + 0x98))->m2(self);
}
#endif

extern "C" void func_00113CB8(void) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113CC0);
#ifdef SKIP_ASM
extern "C" void cAI_setAIState(void *, int);

extern "C" void func_00113CC0(void *arg0, void *arg1) {
    cAI_setAIState(arg1, 2);
}
#endif

extern "C" void func_00113CE0(void) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113CE8);
#ifdef SKIP_ASM
extern "C" void func_00113CE8(void *arg0, void *arg1) {
    (*(int *)((char*)(arg1) + (0x14))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113CF0);
#ifdef SKIP_ASM
extern "C" void cAI_setAIState(void *, int);

extern "C" void func_00113CF0(void *arg0, void *arg1) {
    cAI_setAIState(arg1, 5);
}
#endif

extern "C" void func_00113D10(void) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113D18);
#ifdef SKIP_ASM
extern "C" void func_00113D18(void *arg0, void *arg1) {
    (*(int *)((char*)(arg1) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
}
#endif

extern "C" void func_00113D28(void) {
}

extern "C" void func_00113D30(void) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113D38);
#ifdef SKIP_ASM
extern "C" void func_00113D38(void *arg0, void *arg1) {
    (*(int *)((char*)(arg1) + (0x1C))) = 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113D48);
#ifdef SKIP_ASM
extern "C" void cAI_setAIState(void *, int);

extern "C" void func_00113D48(void *arg0, void *arg1) {
    int temp_2;

    temp_2 = (*(int *)((char*)(arg1) + (0x1C)));
    if (temp_2 <= 0) {
        cAI_setAIState(arg1, 5);
        return;
    }
    (*(int *)((char*)(arg1) + (0x1C))) = (int) (temp_2 - 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113D80);
#ifdef SKIP_ASM
extern "C" void func_00113D80(void *arg0, void *arg1) {
    (*(int *)((char*)(arg1) + (0x1C))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113D88);
#ifdef SKIP_ASM
extern "C" void func_00258988(int);
extern int D_004A2EEC;

extern "C" void func_00113D88(void) {
    if (D_004A2EEC != 0) {
        func_00258988(D_004A2EEC);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113DB0);
#ifdef SKIP_ASM
extern "C" void cAI_setAIState(void *, int);
extern "C" int func_0012A250(void *);
extern "C" void func_00231250(int, int, int, int);
extern void *D_004A28A8;

extern "C" void func_00113DB0(void *arg0, void *arg1) {
    (*(int *)((char*)(arg1) + (0xC))) = (int) ((*(int *)((char*)(arg1) + (0xC))) + 1);
    if (func_0012A250(arg1) == 1) {
        cAI_setAIState(arg1, 6);
        func_00231250((*(int *)((char*)(D_004A28A8) + (0x84))), 5, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113E18);
#ifdef SKIP_ASM
extern "C" void func_00258A48(int);
extern int D_004A2EEC;

extern "C" void func_00113E18(void) {
    if (D_004A2EEC != 0) {
        func_00258A48(D_004A2EEC);
    }
}
#endif

extern "C" void func_00113E40(void) {
}

extern "C" void func_00113E48(void) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113E50);
#ifdef SKIP_ASM
extern "C" void func_0012B090(int);

extern "C" void func_00113E50(int arg0, int arg1) {
    func_0012B090(arg1);
}
#endif

extern "C" void func_00113E70(void) {
}

extern "C" void func_00113E78(void) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113E80);
#ifdef SKIP_ASM
struct sV4_3E80 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len_3E80(const sV4_3E80& v)
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

// PORT: PS2-only FPU asm (absolute value).
static inline float Abs_3E80(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float Clamp_3E80(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

extern "C" void func_00113E80(char *self, float arg1) {
    float r = Len_3E80(*(sV4_3E80 *)(self + 0x1E0)) / 694.538818359375f;
    if (r < 1.0f)
        arg1 = arg1 * r;
    float d = Abs_3E80(arg1 - *(float *)(self + 0x1F0)) * 12.002403259277344f;
    float m = Clamp_3E80(d, 0.10000000149011612f, 14.001209259033203f);
    int st = *(int *)(self + 0x438);
    if (st == 2 || st == 3 || st == 0xD)
        m = m * 0.7561339735984802f;
    *(float *)(self + 0x1F8) = arg1;
    *(float *)(self + 0x1F4) = m * 0.01666666753590107f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113F38);
#ifdef SKIP_ASM
// PORT: PS2-only FPU asm (absolute value).
static inline float Abs_3F38(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float Clamp_3F38(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

extern "C" void func_00113F38(void *self, float arg1) {
    float d = Abs_3F38(arg1 - *(float *)((char*)self + 0x22C)) * 7.0f;
    float m = Clamp_3F38(d, 0.1f, 8.0f);
    *(float *)((char*)self + 0x234) = arg1;
    *(float *)((char*)self + 0x230) = m * 0.01666666753590107f;
}
#endif

INCLUDE_ASM("seg/seg_14B10", func_00113F88);

//100%
INCLUDE_ASM("seg/seg_14B10", func_00114130);
#ifdef SKIP_ASM
extern "C" int func_0028B180();
extern "C" void func_002F6AC8(char *, int);
extern "C" void func_00298D90(int mgr, char* rider, int b);
extern "C" void func_00299368(int mgr, char* rider);
extern "C" void func_002992D8(int mgr, char* rider);

extern "C" void func_00114130(char* s, int a, int b)
{
    if (b) func_002F6AC8(*(char**)(s + 0x77C) + 0xD20, 0);
    if (a) {
        if (*(float*)(s + 0x2F8) > 0.0f) {
            if (*(float*)(s + 0x2FC) == 0.0f) {
                float x = *(float*)(s + 0x2F8);
                if (x > 0.6666666865348816f) *(float*)(s + 0x2FC) = 1.0f;
                else if (x > 0.3333333432674408f) *(float*)(s + 0x2FC) = 0.625f;
                else *(float*)(s + 0x2FC) = 0.25f;
                func_00298D90(func_0028B180(), s, b);
            }
            if (*(float*)(s + 0x2E8) == 0.0f && *(int*)(s + 0x304) != 0 && *(int*)(s + 0x2F4) < 10) {
                *(float*)(s + 0x2F8) -= 0.00150679936632514f;
            }
            return;
        }
        if (b) func_00299368(func_0028B180(), s);
    }
    if (*(float*)(s + 0x2FC) > 0.0f) func_002992D8(func_0028B180(), s);
    *(float*)(s + 0x2FC) = 0.0f;
}
#endif

INCLUDE_ASM("seg/seg_14B10", func_00114298);

INCLUDE_ASM("seg/seg_14B10", func_00114CC0);

INCLUDE_ASM("seg/seg_14B10", func_00114DB8);

//100%
INCLUDE_ASM("seg/seg_14B10", func_00115168);
#ifdef SKIP_ASM
struct Q_5168 {
    float x, y, z, w;
    Q_5168() {}
    Q_5168(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void cRiderAnimBase_changeHeadingOffset(void* self, float angle);
extern Q_5168 D_004FF130;
extern Q_5168 D_004FF160;

static inline Q_5168 AxisAngle_5168(const Q_5168& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return Q_5168(s * axis.x, s * axis.y, s * axis.z, c);
}

static inline void SetHeading_5168(char* a, float angle)
{
    *(Q_5168*)(a + 0x30) = D_004FF130;
    *(Q_5168*)(a + 0x40) = AxisAngle_5168(D_004FF160, -angle);
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline Q_5168 Scale_5168(const Q_5168& v, float s)
{
    Q_5168 r;
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

extern "C" void func_00115168(char* s)
{
    *(int*)(s + 0x320) ^= 1;
    cRiderAnimBase_changeHeadingOffset(*(void**)(s + 0x784), 3.1415927410125732f);
    if (*(int*)(s + 0x320)) {
        SetHeading_5168(*(char**)(s + 0x784), 3.1415927410125732f);
    } else {
        SetHeading_5168(*(char**)(s + 0x784), 0.0f);
    }
    *(int*)(*(char**)(s + 0x784) + 0x18) = *(int*)(s + 0x320);
    *(Q_5168*)(s + 0x3A0) = Scale_5168(*(Q_5168*)(s + 0x3A0), -1.0f);
    *(Q_5168*)(s + 0x3B0) = Scale_5168(*(Q_5168*)(s + 0x3B0), -1.0f);
    *(float*)(s + 0x1F0) = -*(float*)(s + 0x1F0);
    *(float*)(s + 0x1F8) = -*(float*)(s + 0x1F8);
    *(float*)(s + 0x214) = -*(float*)(s + 0x214);
    *(float*)(s + 0x21C) = -*(float*)(s + 0x21C);
    *(float*)(s + 0x208) = -*(float*)(s + 0x208);
    *(float*)(s + 0x210) = -*(float*)(s + 0x210);
    *(float*)(s + 0x1FC) = -*(float*)(s + 0x1FC);
    *(float*)(s + 0x204) = -*(float*)(s + 0x204);
    *(float*)(s + 0x280) = -*(float*)(s + 0x280);
    *(float*)(s + 0x288) = -*(float*)(s + 0x288);
}
#endif

INCLUDE_ASM("seg/seg_14B10", func_00115358);

INCLUDE_ASM("seg/seg_14B10", func_00115640);

//100%
INCLUDE_ASM("seg/seg_14B10", func_001158B8);
#ifdef SKIP_ASM
extern "C" float func_0031C228(float x);
extern "C" void func_0031BE50(float* s, float* c, float angle);

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_58B8(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float Atan2_58B8(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f)
            a += 3.1415927410125732f;
        else
            a -= 3.1415927410125732f;
    }
    return a;
}

// PORT: PS2-only abs.s asm helper (fabsf off-PS2).
static inline float Abs_58B8(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ minimum operator
static inline float Clamp_58B8(float v, float lo, float hi)
{
    return v >= lo ? v <? hi : lo;
}

extern "C" void func_001158B8(void* self, float* y, float* x, float step, float eps)
{
    float px, py, len, ang, t, r;
    float sc[2];
    if (Abs_58B8(*x) <= eps) *x = 0.0f;
    if (Abs_58B8(*y) <= eps) *y = 0.0f;
    px = *x;
    py = *y;
    len = Sqrt_58B8(px * px + py * py);
    if (len == 0.0f) return;
    ang = Atan2_58B8(py, px);
    t = ang / step;
    if (ang < 0.0f) r = t + -0.5f;
    else r = t + 0.5f;
    func_0031BE50(&sc[0], &sc[1], (float)(int)r * step);
    *x = Clamp_58B8(sc[1] * len, -1.0f, 1.0f);
    *y = Clamp_58B8(sc[0] * len, -1.0f, 1.0f);
    if (__builtin_fabsf(*x) < 0.001f) *x = 0.0f;
    if (__builtin_fabsf(*y) < 0.001f) *y = 0.0f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00115AB0);
#ifdef SKIP_ASM
extern "C" int cBE_getBE();
extern "C" int cBE_getInterface__Fv(int, int);
extern "C" float func_0014EFA8(int, int);

extern "C" float func_00115AB0(void *arg0) {
    return (func_0014EFA8(cBE_getInterface__Fv(cBE_getBE(), 2), (*(int *)((char*)(arg0) + (0x86C)))) * -90.0f) + 75.0f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00115B08);
#ifdef SKIP_ASM
extern "C" int cBE_getBE();
extern "C" int cBE_getInterface__Fv(int, int);
extern "C" float func_0014EFA8(int, int);

extern "C" float func_00115B08(void *arg0) {
    return (func_0014EFA8(cBE_getInterface__Fv(cBE_getBE(), 2), (*(int *)((char*)(arg0) + (0x86C)))) * 90.0f) - 90.0f;
}
#endif

INCLUDE_ASM("seg/seg_14B10", func_00115B58);

INCLUDE_ASM("seg/seg_14B10", func_00115D48);

//100%
INCLUDE_ASM("seg/seg_14B10", func_00116120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void cRiderMetrix_evAutoResetSurface(void *);
extern "C" void func_0011FE78_6120(void *, int) __asm__("func_0011FE78__FPv");
extern "C" void func_0011FEC8_6120(void *, int) __asm__("func_0011FEC8__FPv");
extern "C" int func_0028B180();
extern "C" void func_0029A220(int, void *);
extern "C" void func_00270970(int, int);
extern void *D_004A28A8;

extern "C" int func_00116120(char *self, int arg1, int arg2) {
    if (arg1 != 0 || arg2 != 0) {
        *(int *)(self + 0x2E8) = 0;
        *(int *)(self + 0x2EC) = 0;
        if (arg2 == 1 || arg2 == 4)
            cRiderMetrix_evAutoResetSurface(*(void **)(self + 0x790));
        *(int *)(*(char **)(self + 0x77C) + 0x350) = (arg2 != 0);
        func_0011FEC8_6120(self, 9);
        func_0011FE78_6120(self, 3);
        func_0029A220(func_0028B180(), self);
        func_00270970(*(int *)(*(char **)((char *)D_004A28A8 + 0x84) + 0x28), *(int *)(self + 0x86C));
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_001161D0);
#ifdef SKIP_ASM
struct V4_61D0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4D dot product).
static inline float Dot4_61D0(const V4_61D0& a, const V4_61D0& b)
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

// PORT: returns a value (target keeps the state in v1 across the call)
extern "C" int cRiderAnimBase_play_61D0(void* self, int anim, int flags, float blend) __asm__("cRiderAnimBase_play");
int func_0011FE98(void* self);
// PORT: func_0011FEC8__FPv takes a second argument; bound by asm label
void func_0011FEC8_61D0(void* self, int on) __asm__("func_0011FEC8__FPv");

extern "C" int func_001161D0(char* s, float dir)
{
    int st;
    if (dir == 0.0f) return 0;
    if (*(int*)(s + 0x328) == 3 || *(int*)(s + 0x328) == 4) return 0;
    if (!func_0011FE98(s)) {
        if (Dot4_61D0(*(V4_61D0*)(s + 0x1E0), *(V4_61D0*)(s + 0x3A0)) < 0.0f) return 0;
    }
    if (dir > 0.0f) {
        cRiderAnimBase_play_61D0(*(void**)(s + 0x784), 0x18, 0, -1.0f);
        *(int*)(s + 0x330) = 1;
    } else {
        cRiderAnimBase_play_61D0(*(void**)(s + 0x784), 0x20, 0, -1.0f);
        *(int*)(s + 0x330) = 2;
    }
    func_0011FEC8_61D0(s, 1);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_001162C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0011FEC8_62C8(void *, int) __asm__("func_0011FEC8__FPv");
extern "C" int func_0011FEE8_62C8(void *) __asm__("func_0011FEE8__FPv");
extern "C" void func_00131348(char *);
extern "C" void func_002F6AC8(char *, int);

extern "C" int func_001162C8(char *self, int arg1, int arg2) {
    if (arg2 != 0)
        func_002F6AC8(*(char **)(self + 0x77C) + 0xD20, 1);
    if ((*(float *)(self + 0x360) == 0.0f && arg1 != 0) || arg2 != 0) {
        if (func_0011FEE8_62C8(self) == 1)
            func_00131348(*(char **)(self + 0x77C) + 0x1D0);
        func_0011FEC8_62C8(self, 2);
        return 1;
    }
    *(float *)(self + 0x360) = 1.0f;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00116378);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0011FEC8_6378(void *, int) __asm__("func_0011FEC8__FPv");

extern "C" int func_00116378(void *arg0) {
    if (*(float *)((char*)arg0 + 0x470) >= 0.0f) {
        func_0011FEC8_6378(arg0, 10);
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_14B10", func_001163B0);

extern "C" void func_00116930(void) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00116938);
#ifdef SKIP_ASM
extern int D_0043D160[];

extern "C" int func_00116938(int arg0) {
    return D_0043D160[arg0];
}
#endif

INCLUDE_ASM("seg/seg_14B10", gGenTrickName);

INCLUDE_ASM("seg/seg_14B10", gGenMonsterTrickReqName);

//100%
INCLUDE_ASM("seg/seg_14B10", func_00116FA8);
#ifdef SKIP_ASM
extern "C" int* func_00116FA8(int *arg0) {
    *arg0 = 0x34;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00116FB8);
#ifdef SKIP_ASM
extern "C" void func_00116FB8(void *self) {
    if (*(int *)((char*)self + 0) != 0x34) {
        float lim = *(float *)((char*)self + 4);
        if (lim != -1.0f) {
            float t = *(float *)((char*)self + 8) + 0.01666666753590107f;
            *(float *)((char*)self + 8) = t;
            if (lim <= t)
                *(int *)((char*)self + 0) = 0x34;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00117008);
#ifdef SKIP_ASM
extern "C" void func_00117008(char *arg0, signed char *arg1) {
    signed char *s = arg1;
    unsigned char *d = (unsigned char*)(arg0 + 0x18);
    if (s != 0) {
        while (*s != 0) {
            *d = *s;
            s++;
            d++;
        }
    }
    *d = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00117048);
#ifdef SKIP_ASM
extern "C" void func_00117008(char *, signed char *);

extern "C" void func_00117048(char *arg0, int arg1, signed char *arg2, int arg3, float fparg0) {
    func_00117008(arg0, arg2);
    *(int *)(arg0 + 0) = arg1;
    *(float *)(arg0 + 4) = fparg0;
    *(int *)(arg0 + 0xC) = arg3;
    *(int *)(arg0 + 8) = 0;
    *(int *)(arg0 + 0x14) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_001170A8);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_00117008(char *, signed char *);
extern signed char D_004A5E20[];
extern char D_004A1070[];

// Variant of func_00117048 that names the entry from a number (formatted into a shared buffer).
extern "C" void func_001170A8(char *arg0, int arg1, int arg2, float fparg0, int arg3) {
    sprintf((char*)D_004A5E20, D_004A1070, arg2);
    func_00117008(arg0, D_004A5E20);
    *(int *)(arg0 + 0x14) = arg2;
    *(int *)(arg0 + 0) = arg1;
    *(float *)(arg0 + 4) = fparg0;
    *(int *)(arg0 + 0xC) = arg3;
    *(int *)(arg0 + 8) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00117138);
#ifdef SKIP_ASM
extern "C" void func_00117008(char *, signed char *);

extern "C" void func_00117138(char *arg0, int arg1, signed char *arg2, int arg3, float fparg0) {
    func_00117008(arg0, arg2);
    *(int *)(arg0 + 0) = arg1;
    *(int *)(arg0 + 0xC) = arg3;
    *(float *)(arg0 + 8) = -fparg0;
    *(float *)(arg0 + 4) = -1.0f;
    *(int *)(arg0 + 0x14) = 0;
}
#endif

INCLUDE_ASM("seg/seg_14B10", func_001171A8);

//100%
INCLUDE_ASM("seg/seg_14B10", func_00117248);
#ifdef SKIP_ASM
extern "C" void func_00117540(void *);

extern "C" void *func_00117248(void *arg0) {
    *(int *)((char*)arg0 + 0x1AC) = 0;
    *(int *)((char*)arg0 + 0x1B0) = 0;
    *(int *)((char*)arg0 + 0x1B4) = 0;
    *(int *)((char*)arg0 + 0x1C8) = 0;
    *(float *)((char*)arg0 + 0x1C4) = 1.0f;
    func_00117540(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00117290);
#ifdef SKIP_ASM
extern "C" void cMemMan_free__FPv(int);
extern "C" void operator_delete__FPi(void *);

extern "C" void func_00117290(void *arg0, int arg1) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1B0)));
    if (temp_4 != 0) {
        cMemMan_free__FPv(temp_4);
    }
    if (arg1 & 1) {
        operator_delete__FPi(arg0);
    }
}
#endif
