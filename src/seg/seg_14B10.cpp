#include "common.h"
#include "ai/rider.h"

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

//100%
INCLUDE_ASM("seg/seg_14B10", cAI_forceAIState);
#ifdef SKIP_ASM
extern char D_00456C58[];
extern char D_00456C68[];
extern char D_004A0E90[];
extern char D_00456C78[];
extern char D_004A0E98[];
extern char D_004A0EA0[];
extern char D_00456C88[];

// PORT: the unit declares cAI_forceAIState(void*); defined under an asm label with its real type.
extern "C" void cAI_forceAIState_impl(char* self, int state) __asm__("cAI_forceAIState");

// Forces the AI into the given state: state id, its state block and its name.
extern "C" void cAI_forceAIState_impl(char* self, int state)
{
    switch (state) {
    case 1:
        *(int*)(self + 0x0) = 1;
        *(const char**)(self + 0xA0) = D_00456C58;
        *(void**)(self + 0x98) = self + 0xAC;
        break;
    case 2:
        *(int*)(self + 0x0) = 2;
        *(const char**)(self + 0xA0) = D_00456C68;
        *(void**)(self + 0x98) = self + 0xB0;
        break;
    case 3:
        *(int*)(self + 0x0) = 3;
        *(const char**)(self + 0xA0) = D_004A0E90;
        *(void**)(self + 0x98) = self + 0xB4;
        break;
    case 4:
        *(int*)(self + 0x0) = 4;
        *(const char**)(self + 0xA0) = D_00456C78;
        *(void**)(self + 0x98) = self + 0xBC;
        break;
    case 5:
        *(int*)(self + 0x0) = 5;
        *(const char**)(self + 0xA0) = D_004A0E98;
        *(void**)(self + 0x98) = self + 0xC0;
        break;
    case 6:
        *(int*)(self + 0x0) = 6;
        *(const char**)(self + 0xA0) = D_004A0EA0;
        *(void**)(self + 0x98) = self + 0xC4;
        break;
    case 7:
        *(int*)(self + 0x0) = 7;
        *(const char**)(self + 0xA0) = D_00456C88;
        *(void**)(self + 0x98) = self + 0xC8;
        break;
    default:
        *(void**)(self + 0x98) = 0;
        *(const char**)(self + 0xA0) = 0;
        *(int*)(self + 0x0) = 0;
        break;
    }
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_14B10", func_00113F88);
#ifdef SKIP_ASM
// PORT: PS2-only FPU asm (absolute value).
static inline float Abs_3F88(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float Clamp_3F88(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

struct sVec4_3F88 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_3F88(const sVec4_3F88& a, const sVec4_3F88& b)
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

// Steering flips when the board points backwards: |dir| within th while tilting back, or dir < -th while tilt < th.
static inline float flipBackwards_3F88(float b, char *self, float th)
{
    if (Abs_3F88(*(float *)(self + 0x214)) <= th && *(float *)(self + 0x1F0) < 0.0f)
        return -b;
    if (*(float *)(self + 0x214) < -th && *(float *)(self + 0x1F0) < th)
        return -b;
    return b;
}

extern "C" void func_00113F88(char *self, float a, float b) {
    if (0.0f < a && *(float *)(self + 0x214) != 0.0f) {
        *(float *)(self + 0x21C) = 0.0f;
        *(float *)(self + 0x218) = 0.04166241362690926f;
        return;
    }
    if (0.0f < b && *(float *)(self + 0x220) != 0.0f) {
        *(float *)(self + 0x228) = 0.0f;
        *(float *)(self + 0x224) = 0.10000182688236237f;
        return;
    }
    if (0.0f < a && *(float *)(self + 0x214) != 0.0f) {
        a = 0.0f;
    }
    float d = Abs_3F88(a - *(float *)(self + 0x220));
    float v = (0.1f <= d) ? d * 0.10000182688236237f : 0.010000183247029781f;
    *(float *)(self + 0x228) = a;
    *(float *)(self + 0x224) = v;
    if (0.0f < b) {
        if (0.0f < *(float *)(self + 0x220)) {
            b = 0.0f;
        } else if (vu0Dot_3F88(*(sVec4_3F88 *)(self + 0x1E0), *(sVec4_3F88 *)(self + 0x3A0)) < 0.0f) {
            b = 0.0f;
        }
    }
    b = flipBackwards_3F88(b, self, 0.1f);
    float e = Clamp_3F88(Abs_3F88(b - *(float *)(self + 0x214)), 0.1f, 1.0f);
    *(float *)(self + 0x21C) = b;
    *(float *)(self + 0x218) = e * 0.04166241362690926f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00114130);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_002F6AC8(char *, int);
extern "C" void func_00298D90(void* mgr, char* rider, int b);
extern "C" void func_00299368(void* mgr, char* rider);
extern "C" void func_002992D8(void* mgr, char* rider);

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

//100%
INCLUDE_ASM("seg/seg_14B10", func_00114298);
#ifdef SKIP_ASM
extern "C" float func_0031C040(float x);
extern "C" float func_0031BF60(float x);
int func_0011FE98(void* self);
extern "C" void func_002707E0(int a, int b, void* c);
extern "C" void func_00309848(void* self);
extern "C" float func_00119E38(void* self, int a, int b);
extern "C" void func_0010E098(void* self, int mask, float amt);
extern "C" int func_001298C8();
extern void* D_004A3DD8;

// 4-float vector with a component constructor.
struct sV4_4298 {
    float x, y, z, w;
    sV4_4298() {}
    sV4_4298(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

extern sV4_4298 D_004FF140_4298 __asm__("D_004FF140");
extern sV4_4298 D_004FF160_4298 __asm__("D_004FF160");

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len_4298(const sV4_4298& v)
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_4298(const sV4_4298& a, const sV4_4298& b)
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
static inline sV4_4298 Scale_4298(const sV4_4298& v, float s)
{
    sV4_4298 r;
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

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void ScaleEq_4298(sV4_4298& v, float s)
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

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar). Assembled in noreorder mode: retail
// leaves the final sqc2 out of a following branch delay slot (as btAddEq in visualfx/boardtrailfx).
static inline void DivEq_4298(sV4_4298& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        ".set push\n"
        ".set noreorder\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_4298 Add_4298(const sV4_4298& a, const sV4_4298& b)
{
    sV4_4298 r;
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

// PORT: PS2-only VU0 inline asm (a += b).
static inline void AddEq_4298(sV4_4298& a, const sV4_4298& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_4298 Sub_4298(const sV4_4298& a, const sV4_4298& b)
{
    sV4_4298 r;
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

// PORT: PS2-only VU0 inline asm (a -= b).
static inline void SubEq_4298(sV4_4298& a, const sV4_4298& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (cross product, w = 0). The first operand is "o" (offsettable): a global
// operand is then addressed through a base register (lui; addiu; lqc2 0($r)) as in retail.
static inline sV4_4298 Cross_4298(const sV4_4298& a, const sV4_4298& b)
{
    sV4_4298 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "o"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sV4_4298 Normalize_4298(const sV4_4298& v)
{
    sV4_4298 r;
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

// PORT: PS2-only FPU asm (absolute value).
static inline float Abs_4298(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float Clamp_4298(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

static inline sV4_4298 Up_4298(char* r) { return *(sV4_4298*)(r + 0x1C0); }
static inline int Flags_4298(char* r) { return *(short*)(r + 0x2D4); }

#define VEL_4298 (*(sV4_4298*)(self + 0x1E0))

// Applies the rider's push (speedFactor in [0, 1]; negative = no push) and the slope/heading corrections.
extern "C" void func_00114298(char* self, float speedFactor)
{
    int steered = 0;
    float speed = Len_4298(VEL_4298);
    sV4_4298 oldVel = VEL_4298;
    float push;
    if (speedFactor < 0.0f) {
        *(int*)(*(char**)(self + 0x77C) + 0x14) = -1;
        push = 0.16339834034442902f;
    } else {
        push = speedFactor * speedFactor;
        push *= speed < 972.1808471679688f ? speed * 0.357146680355072f + 361.203125f : 708.4142456054688f;
        push = Clamp_4298(push, 361.203125f, 708.4142456054688f);
    }
    float lo = func_0031C040(0.8726646900177002f);
    float hi = func_0031C040(1.2217305898666382f);
    if (func_0011FE98(self) == 4) {
        AddEq_4298(VEL_4298, Scale_4298(Up_4298(self), push));
    } else {
        float t = (*(float*)(self + 0x378) - lo) * (1.0f / (hi - lo));
        sV4_4298 dir = Normalize_4298(Add_4298(*(sV4_4298*)(self + 0x370), Scale_4298(*(sV4_4298*)(self + 0x3A0), 0.2f)));
        if (*(float*)(self + 0x3A8) < 0.0f || t < 0.0f || *(float*)(self + 0x1E8) < 0.0f) {
            AddEq_4298(VEL_4298, Scale_4298(dir, push));
        } else {
            sV4_4298 flat = Normalize_4298(sV4_4298(*(float*)(self + 0x370), *(float*)(self + 0x374), 0.0f, 0.0f));
            sV4_4298 side = Normalize_4298(Sub_4298(*(sV4_4298*)(self + 0x3A0), Scale_4298(flat, Dot_4298(*(sV4_4298*)(self + 0x3A0), flat))));
            sV4_4298 vdir = Normalize_4298(Sub_4298(VEL_4298, Scale_4298(flat, Dot_4298(VEL_4298, flat))));
            float s0 = func_0031BF60(0.0f);
            float s1 = func_0031BF60(0.349065899848938f);
            float f = t * (side.z - s0) * (1.0f / (s1 - s0));
            f = Clamp_4298(f, 0.0f, 0.949999988079071f);
            steered = 1;
            dir = Normalize_4298(Add_4298(Scale_4298(dir, 1.0f - f), Scale_4298(side, f)));
            VEL_4298 = Add_4298(Add_4298(Scale_4298(VEL_4298, 1.0f - f), Scale_4298(vdir, f * speed)), Scale_4298(Scale_4298(dir, push), 0.5f));
        }
    }
    func_002707E0(*(int*)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28), *(int*)(self + 0x86C), *(char**)(self + 0x790) + 0xFC);
    func_00309848(D_004A3DD8);
    func_0010E098(self, 1, func_00119E38(*(void**)(self + 0x790), *(int*)(self + 0x320) != *(int*)(self + 0x324), steered));
    if (*(float*)(self + 0x378) > hi + 0.019999999552965164f) {
        sV4_4298 dv = Sub_4298(VEL_4298, oldVel);
        sV4_4298 ov = oldVel;
        ov.z = 0.0f;
        dv.z = 0.0f;
        if (Dot_4298(ov, dv) < 0.0f) {
            float a = *(float*)(self + 0x2E4) * 0.5f;
            float b = *(float*)(self + 0x2E4) * 0.699999988079071f;
            float k;
            if (a <= speed) {
                if (speed <= b)
                    k = (speed - a) / (b - a);
                else
                    k = 1.0f;
            } else {
                k = 0.0f;
            }
            SubEq_4298(VEL_4298, Scale_4298(dv, k));
        }
    }
    float slope = *(float*)(self + 0x388);
    sV4_4298 h = *(sV4_4298*)(self + 0x380);
    h.z = 0.0f;
    if (Abs_4298(h.x) > 0.0f || Abs_4298(h.y) > 0.0f)
        DivEq_4298(h, Len_4298(h));
    else
        h = D_004FF140_4298;
    *(sV4_4298*)(self + 0x3C0) = h;
    if (slope < 0.05000000074505806f && slope > -0.05000000074505806f) {
        sV4_4298 lat = Scale_4298(h, Dot_4298(VEL_4298, h) / Dot_4298(h, h));
        SubEq_4298(VEL_4298, lat);
        AddEq_4298(*(sV4_4298*)(self + 0x110), Scale_4298(h, 4.0f));
        if (!(Flags_4298(self) & 0x20))
            ScaleEq_4298(VEL_4298, 0.799975574016571f);
    }
    float len = Len_4298(VEL_4298);
    if (*(float*)(self + 0x2E4) < len)
        ScaleEq_4298(VEL_4298, *(float*)(self + 0x2E4) / len);
    if (speedFactor >= 0.0f && (*(int*)(self + 0x434) < 0xB || *(int*)(self + 0x434) > 0xD)) {
        float t = (float)(func_001298C8() - *(int*)(*(char**)(self + 0x77C) + 0x10)) * 0.01666666753590107f;
        float k;
        if (t <= 0.5388872623443604f) {
            k = 0.6939882636070251f;
        } else {
            float u = (t - 0.5388872623443604f) * 1.2326725721359253f <? 1.0f; // PORT: g++ minimum operator
            k = u + (1.0f - u) * 0.6939882636070251f;
        }
        ScaleEq_4298(VEL_4298, k);
    }
    sV4_4298 c = Cross_4298(D_004FF160_4298, VEL_4298);
    float cl = Len_4298(c);
    if (cl > 0.0f) {
        ScaleEq_4298(c, 1.0f / cl);
        sV4_4298 side = Cross_4298(c, *(sV4_4298*)(self + 0x370));
        *(float*)(self + 0x5A4) = Dot_4298(VEL_4298, *(sV4_4298*)(self + 0x370)) * Len_4298(side);
    } else {
        *(float*)(self + 0x5A4) = 0.0f;
    }
    *(int*)(self + 0x5A8) = speedFactor > 0.0f;
}

#undef VEL_4298
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00114CC0);
#ifdef SKIP_ASM
struct Q_4CC0 {
    float x, y, z, w;
    Q_4CC0() {}
    Q_4CC0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct V3_4CC0 {
    float x, y, z;
    V3_4CC0() {}
    V3_4CC0(float ax, float ay, float az) { x = ax; y = ay; z = az; }
} __attribute__((aligned(16)));

static inline V3_4CC0 Vec3Of_4CC0(Q_4CC0 v)
{
    return V3_4CC0(v.x, v.y, v.z);
}

static inline Q_4CC0 Make_4CC0(const V3_4CC0& t)
{
    return Q_4CC0(t.x, t.y, t.z, 0.0f);
}

extern "C" void cRider_updateOrientationImplicit(void* self);
extern "C" void func_00115168(char* s);

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_4CC0(const Q_4CC0& a, const Q_4CC0& b)
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

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline Q_4CC0 QuatMul_4CC0(const Q_4CC0& a, const Q_4CC0& b)
{
    Q_4CC0 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

extern "C" int func_00114CC0_i(char* s) __asm__("func_00114CC0");

extern "C" int func_00114CC0_i(char* s)
{
    float k = 111.11111450195312f;
    if (*(float*)(s + 0x214) != 0.0f) {
        return 0;
    }
    float d = Dot_4CC0(*(Q_4CC0*)(s + 0x1E0), *(Q_4CC0*)(s + 0x3A0));
    if (-k < d) {
        return 0;
    }
    *(Q_4CC0*)(s + 0x120) = QuatMul_4CC0(Make_4CC0(Vec3Of_4CC0(*(Q_4CC0*)(s + 0x1C0))), *(Q_4CC0*)(s + 0x120));
    cRider_updateOrientationImplicit(s);
    func_00115168(s);
    return 1;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_14B10", func_00115640);
#ifdef SKIP_ASM
struct Q_5640 {
    float x, y, z, w;
    Q_5640() {}
    Q_5640(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void cRiderAnimBase_changeHeadingOffset(void* self, float angle);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0011DFE0(void* self, Q_5640 dir, float angle);
// PORT: the unit defines func_00116930 with no parameters; this caller passes the rider.
extern "C" void func_00116930(void* self);
int func_0011FE98(void* self);
extern Q_5640 D_004FF130_5640 __asm__("D_004FF130");
extern Q_5640 D_004FF160_5640 __asm__("D_004FF160");

static inline Q_5640 AxisAngle_5640(const Q_5640& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return Q_5640(s * axis.x, s * axis.y, s * axis.z, c);
}

static inline void SetHeading_5640(char* a, float angle)
{
    *(Q_5640*)(a + 0x30) = D_004FF130_5640;
    *(Q_5640*)(a + 0x40) = AxisAngle_5640(D_004FF160_5640, -angle);
}

// Finishes a pending turn-around request (state 3 = left, 4 = right) of the rider.
extern "C" void func_00115640(char* self)
{
    if (*(int*)(self + 0x328) == 0)
        return;
    if (func_0011FE98(self) == 1) {
        if (*(int*)(self + 0x328) == 3 || *(int*)(self + 0x328) == 4)
            SetHeading_5640(*(char**)(self + 0x784), 0.0f);
        if (*(int*)(self + 0x328) == 3)
            cRiderAnimBase_play(*(void**)(self + 0x784), 0x11A, 0, -1.0f);
        else if (*(int*)(self + 0x328) == 4)
            cRiderAnimBase_play(*(void**)(self + 0x784), 0x115, 0, -1.0f);
        else
            cRiderAnimBase_play(*(void**)(self + 0x784), 0x10C, 0, -1.0f);
    } else if (func_0011FE98(self) == 0) {
        if (*(int*)(self + 0x328) == 3) {
            func_0011DFE0(self, *(Q_5640*)(self + 0x1C0), 1.5707964f);
            cRiderAnimBase_changeHeadingOffset(*(void**)(self + 0x784), 1.5707964f);
            SetHeading_5640(*(char**)(self + 0x784), 0.0f);
        } else if (*(int*)(self + 0x328) == 4) {
            func_0011DFE0(self, *(Q_5640*)(self + 0x1C0), -1.5707964f);
            cRiderAnimBase_changeHeadingOffset(*(void**)(self + 0x784), -1.5707964f);
            SetHeading_5640(*(char**)(self + 0x784), 0.0f);
        }
        cRiderAnimBase_play(*(void**)(self + 0x784), 5, 0, -1.0f);
    }
    *(int*)(self + 0x328) = 0;
    func_00116930(self);
}
#endif

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
extern "C" void* cBE_getBE();
extern "C" int cBE_getInterface__Fv(void*, int);
extern "C" float func_0014EFA8(int, int);

extern "C" float func_00115AB0(void *arg0) {
    return (func_0014EFA8(cBE_getInterface__Fv(cBE_getBE(), 2), (*(int *)((char*)(arg0) + (0x86C)))) * -90.0f) + 75.0f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00115B08);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
extern "C" int cBE_getInterface__Fv(void*, int);
extern "C" float func_0014EFA8(int, int);

extern "C" float func_00115B08(void *arg0) {
    return (func_0014EFA8(cBE_getInterface__Fv(cBE_getBE(), 2), (*(int *)((char*)(arg0) + (0x86C)))) * 90.0f) - 90.0f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", func_00115B58);
#ifdef SKIP_ASM
extern "C" int func_00311AE8(void*, int);
extern "C" int func_001298C8();
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0029FF80(void* snd, void* rider, int side);
int func_0011FEE8(void* self);

// PORT: PS2-only abs.s asm helper (fabsf off-PS2).
static inline float vAbs_115B58(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_00115B58(char* self)
{
    if (*(int*)(self + 0x358) == 0) {
        return;
    }
    if (func_00311AE8(*(void**)(self + 0x784), 2) == 5) {
        return;
    }
    if (func_00311AE8(*(void**)(self + 0x784), 1) != 0) {
        return;
    }
    if (func_00311AE8(*(void**)(self + 0x784), 2) == 10) {
        return;
    }
    int d = func_001298C8() - *(int*)(self + 0x354);
    if (d < 180) {
        if (d < 0) {
            return;
        }
        switch (*(int*)(self + 0x358)) {
        case 1:
            *(long*)(*(char**)(self + 0x784) + 0x20) = *(long*)(self + 0x8C8);
            cRiderAnimBase_play(*(void**)(self + 0x784), 0x13B, 0, -1.0f);
            *(long*)(*(char**)(self + 0x784) + 0x20) = -1;
            func_0029FF80(func_0028B180(), self, 0);
            break;
        case 2:
            *(long*)(*(char**)(self + 0x784) + 0x20) = *(long*)(self + 0x8C8);
            cRiderAnimBase_play(*(void**)(self + 0x784), 0x13B, 0, -1.0f);
            *(long*)(*(char**)(self + 0x784) + 0x20) = -1;
            func_0029FF80(func_0028B180(), self, 1);
            break;
        case 3:
            *(long*)(*(char**)(self + 0x784) + 0x20) = *(long*)(self + 0x8C8);
            cRiderAnimBase_play(*(void**)(self + 0x784), 0x13B, 0, -1.0f);
            *(long*)(*(char**)(self + 0x784) + 0x20) = -1;
            break;
        case 4:
            *(long*)(*(char**)(self + 0x784) + 0x20) = *(long*)(self + 0x8C8);
            cRiderAnimBase_play(*(void**)(self + 0x784), 0x13A, 0, -1.0f);
            *(long*)(*(char**)(self + 0x784) + 0x20) = -1;
            break;
        case 5:
        case 6:
            if (vAbs_115B58(*(float*)(self + 0x1FC)) < 0.75f && func_0011FEE8(self) == 0) {
                cRiderAnimBase_play(*(void**)(self + 0x784), 0x13E, 0, -1.0f);
            }
            break;
        }
    }
    *(int*)(self + 0x358) = 0;
    *(int*)(self + 0x354) = -1;
}
#endif

INCLUDE_ASM("seg/seg_14B10", func_00115D48);

//100%
INCLUDE_ASM("seg/seg_14B10", func_00116120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void cRiderMetrix_evAutoResetSurface(void *);
extern "C" void func_0011FE78_6120(void *, int) __asm__("func_0011FE78__FPv");
extern "C" void func_0011FEC8_6120(void *, int) __asm__("func_0011FEC8__FPv");
extern "C" void* func_0028B180();
extern "C" void func_0029A220(void*, void *);
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
        cRiderAnimBase_play(*(void**)(s + 0x784), 0x18, 0, -1.0f);
        *(int*)(s + 0x330) = 1;
    } else {
        cRiderAnimBase_play(*(void**)(s + 0x784), 0x20, 0, -1.0f);
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

//100%
INCLUDE_ASM("seg/seg_14B10", func_001163B0);
#ifdef SKIP_ASM
struct Q_63B0 {
    float x, y, z, w;
    Q_63B0() {}
} __attribute__((aligned(16)));

struct cAnimSequence;
void cAnimSequence_fadeWeight(cAnimSequence* self, float weight, float target);
int func_00312AA0(void* self, int i);
extern "C" int func_00311AE8(void*, int);
extern "C" char* func_00311B20(void*, int);
extern "C" bool func_001446A0(void*, int);
extern "C" bool func_001446B8(void*, int);
extern "C" void func_00311E88(void*, int, float);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline Q_63B0 Scale_63B0(const Q_63B0& v, float s)
{
    Q_63B0 r;
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

static inline Q_63B0 Dir_63B0(char* self)
{
    return *(Q_63B0*)(self + 0x1A0);
}

// Starts a direction-change animation.
static inline void PlayTurn_63B0(char* self, int anim)
{
    *(long*)(*(char**)(self + 0x784) + 0x20) = *(long*)(self + 0x8C0);
    cRiderAnimBase_play(*(void**)(self + 0x784), anim, 1, -1.0f);
    *(long*)(*(char**)(self + 0x784) + 0x20) = -1;
    *(float*)(self + 0x350) = 0.0f;
}

extern "C" int func_001163B0(char* self, int a, int b)
{
    if (func_00311AE8(*(void**)(self + 0x784), 1) == 3) {
        if (a != 0 && b != 0) {
            int ok = 0;
            char* seq = func_00311B20(*(void**)(self + 0x784), 1) + 0xB0;
            if (func_001446A0(seq, 2) && func_001446B8(seq, 2)) {
                ok = 1;
            }
            if (ok) {
                *(int*)(func_00311B20(*(void**)(self + 0x784), 1) + 0x90) = 0;
                *(long*)(*(char**)(self + 0x784) + 0x20) = *(long*)(self + 0x8C0);
                cRiderAnimBase_play(*(void**)(self + 0x784), 0x145, 0, -1.0f);
                float w = *(float*)(func_00311B20(*(void**)(self + 0x784), 1) + 0x94);
                float weight = *(float*)(func_00311B20(*(void**)(self + 0x784), 1) + 0x98);
                float target = *(float*)(func_00311B20(*(void**)(self + 0x784), 1) + 0x9C);
                char* s = func_00311B20(*(void**)(self + 0x784), 0);
                *(float*)(s + 0x98) = w;
                *(float*)(s + 0x94) = w;
                if (target != 0.0f) {
                    cAnimSequence_fadeWeight((cAnimSequence*)func_00311B20(*(void**)(self + 0x784), 0), weight, target);
                }
                *(long*)(*(char**)(self + 0x784) + 0x20) = -1;
            }
        } else {
            *(float*)(func_00311B20(*(void**)(self + 0x784), 1) + 0x90) = 1.0f;
            func_00311E88(*(void**)(self + 0x784), 0, 0.1f);
        }
    }
    if (func_00311AE8(*(void**)(self + 0x784), 1) == 13) {
        int id = func_00312AA0(*(void**)(self + 0x784), 1);
        int same = *(int*)(self + 0x320) ? id == 0x143 : id == 0x144;
        if ((a != 0 && b == 0 && same) || (a == 0 && b != 0 && !same)) {
            int ok = 0;
            char* seq = func_00311B20(*(void**)(self + 0x784), 1) + 0xB0;
            if (func_001446A0(seq, 2) && func_001446B8(seq, 2)) {
                ok = 1;
            }
            if (ok) {
                *(int*)(func_00311B20(*(void**)(self + 0x784), 1) + 0x90) = 0;
                *(long*)(*(char**)(self + 0x784) + 0x20) = *(long*)(self + 0x8C0);
                if (id == 0x143) {
                    cRiderAnimBase_play(*(void**)(self + 0x784), 0x146, 0, -1.0f);
                } else {
                    cRiderAnimBase_play(*(void**)(self + 0x784), 0x147, 0, -1.0f);
                }
                *(long*)(*(char**)(self + 0x784) + 0x20) = -1;
            }
            if (func_00311AE8(*(void**)(self + 0x784), 0) == 13) {
                float step = *(float*)(self + 0x300) * 0.01111111231148243f;
                float cur = *(float*)(self + 0x350);
                float v = 1.0f;
                if (step + 1.0f < cur) {
                    v = cur - step;
                } else if (cur < 1.0f - step) {
                    v = cur + step;
                }
                *(float*)(self + 0x350) = v;
                char* s = func_00311B20(*(void**)(self + 0x784), 0);
                *(float*)(s + 0x94) = *(float*)(s + 0x98) = *(float*)(self + 0x350);
            }
            if (same) {
                *(Q_63B0*)(self + 0x340) = Scale_63B0(Dir_63B0(self), -1.0f);
            } else {
                *(Q_63B0*)(self + 0x340) = Dir_63B0(self);
            }
        } else {
            *(float*)(func_00311B20(*(void**)(self + 0x784), 1) + 0x90) = 1.0f;
            func_00311E88(*(void**)(self + 0x784), 0, 0.1f);
        }
    }
    if (a != 0 && b != 0) {
        if (func_00311AE8(*(void**)(self + 0x784), 1) == 13 && func_001446A0(func_00311B20(*(void**)(self + 0x784), 1) + 0xB0, 0) && !func_001446A0(func_00311B20(*(void**)(self + 0x784), 1) + 0xB0, 1)) {
            return 1;
        }
        if (func_00311AE8(*(void**)(self + 0x784), 1) == 3 && !func_001446A0(func_00311B20(*(void**)(self + 0x784), 1) + 0xB0, 1)) {
            return 1;
        }
        PlayTurn_63B0(self, 0x142);
    } else if (a != 0 || b != 0) {
        int anim;
        if (func_00311AE8(*(void**)(self + 0x784), 1) == 3 && func_001446A0(func_00311B20(*(void**)(self + 0x784), 1) + 0xB0, 0) && !func_001446A0(func_00311B20(*(void**)(self + 0x784), 1) + 0xB0, 1)) {
            return 1;
        }
        if (func_00311AE8(*(void**)(self + 0x784), 1) == 13 && !func_001446A0(func_00311B20(*(void**)(self + 0x784), 1) + 0xB0, 1)) {
            return 1;
        }
        if (a != 0) {
            anim = *(int*)(self + 0x320) ? 0x143 : 0x144;
            *(Q_63B0*)(self + 0x340) = Scale_63B0(Dir_63B0(self), -1.0f);
        } else {
            anim = *(int*)(self + 0x320) ? 0x144 : 0x143;
            *(Q_63B0*)(self + 0x340) = Dir_63B0(self);
        }
        PlayTurn_63B0(self, anim);
    }
    int r = 0;
    if (func_00311AE8(*(void**)(self + 0x784), 1) == 3 || func_00311AE8(*(void**)(self + 0x784), 1) == 13) {
        r = 1;
    }
    return r;
}
#endif

extern "C" void func_00116930(void* self) {
}

//100%
INCLUDE_ASM("seg/seg_14B10", func_00116938);
#ifdef SKIP_ASM
extern int D_0043D160[];

extern "C" int func_00116938(int arg0) {
    return D_0043D160[arg0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", gGenTrickName);
#ifdef SKIP_ASM
struct sTrickName_6950 {
    unsigned int a : 3;
    unsigned int b : 4;
    unsigned int c : 3;
    unsigned int d : 2;
    unsigned int e : 4;
    unsigned short f : 3;
    unsigned int g : 3;
    unsigned int h : 6;
    unsigned int i : 4;
    unsigned int j : 3;
    unsigned int k : 7;
    unsigned int l : 1;
    unsigned int m : 7;
    unsigned short n : 2;
    unsigned int o : 4;
    unsigned char p : 3;
    unsigned int q : 5;
};

extern char* D_0043D118[];
extern char* D_0043D130[];
extern char* D_0043CF40[];
extern char* D_0043CF60[];
extern char* D_0043CF70[];
extern char* D_0043CFB0[];
extern char* D_0043CFC8[];
extern char* D_0043CFE0[];
extern char* D_0043D0C0[];
extern char* D_0043D160_s[] __asm__("D_0043D160");
extern char* D_004A0FF0[2];
extern char* D_0043D2B8[];
extern char* D_0043D2D0[];
extern char* D_0043D2E0[];
extern char* D_0043D100[];
extern char* D_0043D320[];

extern "C" void gGenTrickName_6950(char* buf, sTrickName_6950* id) __asm__("gGenTrickName");
extern "C" void gGenTrickName_6950(char* buf, sTrickName_6950* id)
{
    const char* s;
    s = D_0043D118[id->a];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D130[id->b];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043CF40[id->c];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043CF60[id->d];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043CF70[id->e];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043CFB0[id->f];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043CFC8[id->g];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043CFE0[id->h];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D0C0[id->i];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D160_s[id->k];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_004A0FF0[id->l];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D160_s[id->m];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D2B8[id->j];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D2D0[id->n];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D2E0[id->o];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D100[id->p];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    s = D_0043D320[id->q];
    while (*s != 0) {
        *buf++ = *(const unsigned char*)s;
        s++;
    }
    *buf = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_14B10", gGenMonsterTrickReqName);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* p, int c, int n);

// Packed trick id (64-bit EE `long` bitfields).
struct sTrickBits_6E10 {
    unsigned long pad0 : 10;
    unsigned long kind : 2;     // 10
    unsigned long dir : 4;      // 12
    unsigned long spin : 3;     // 16
    unsigned long flip : 3;     // 19
    unsigned long pad22 : 6;
    unsigned long grab : 4;     // 28
    unsigned long pad32 : 3;
    unsigned long mod : 7;      // 35
    unsigned long hasExtra : 1; // 42
    unsigned long extra : 7;    // 43
    unsigned long pad50 : 14;
};

union sTrickId_6E10 {
    sTrickBits_6E10 b;
    unsigned int w[2];
};

extern "C" void gGenTrickName(char* buf, sTrickId_6E10* id, int size);

struct sMonsterReq_6E10 {
    int trick;
    int pad4;
    unsigned char kind;
    unsigned char dir;
    unsigned char spin;
    unsigned char flip;
    unsigned char grab;
    unsigned char mod;
    unsigned char extra;
    unsigned char padF;
};
extern sMonsterReq_6E10 D_0043D608[];

// Name of the monster trick required for `trick` (empty when it is not one).
extern "C" void gGenMonsterTrickReqName(char* buf, int trick, int size)
{
    sMonsterReq_6E10* r = D_0043D608;
    for (int i = 0; i < 0x18; i++, r++) {
        if (r->trick == trick) {
            sTrickId_6E10 id;
            func_003E6448(&id, 0, 8);
            id.b.kind = r->kind;
            id.b.dir = r->dir;
            id.b.spin = r->spin;
            id.b.flip = r->flip;
            id.b.grab = r->grab;
            id.b.mod = r->mod;
            id.b.extra = r->extra;
            if (id.w[1] & 0x3F800) {  // extra != 0
                id.b.hasExtra = 1;
            }
            gGenTrickName(buf, &id, size);
            return;
        }
    }
    buf[0] = 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_14B10", func_001171A8);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_00117008(char *, signed char *);
extern signed char D_004A5E20[];
extern char D_004A1070[];

// Variant of func_00117138 that names the entry from a number (formatted into a shared buffer).
extern "C" void func_001171A8(char *arg0, int arg1, int arg2, float fparg0, int arg3) {
    sprintf((char*)D_004A5E20, D_004A1070, arg2);
    func_00117008(arg0, D_004A5E20);
    *(int *)(arg0 + 0x14) = arg2;
    *(int *)(arg0 + 0) = arg1;
    *(float *)(arg0 + 8) = -fparg0;
    *(int *)(arg0 + 0xC) = arg3;
    *(float *)(arg0 + 4) = -1.0f;
}
#endif

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
