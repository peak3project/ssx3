#include "common.h"

INCLUDE_ASM("seg/seg_1218", func_00100218);

//100%
INCLUDE_ASM("seg/seg_1218", func_00100250);
#ifdef SKIP_ASM
struct sVec4_0250 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vDot_0250(const sVec4_0250& a, const sVec4_0250& b)
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
static inline sVec4_0250 vScale_0250(const sVec4_0250& v, float s)
{
    sVec4_0250 r;
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
static inline sVec4_0250 vSub_0250(const sVec4_0250& a, const sVec4_0250& b)
{
    sVec4_0250 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4_0250 vNorm_0250(const sVec4_0250& v)
{
    sVec4_0250 r;
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

extern "C" float func_00100250(void* self, const sVec4_0250* v)
{
    char* p = *(char**)((char*)self + 0x18);
    sVec4_0250 a = *(sVec4_0250*)(p + 0x1A0);
    sVec4_0250 b = *(sVec4_0250*)(p + 0x1C0);
    sVec4_0250 u = vSub_0250(*v, vScale_0250(a, vDot_0250(*v, a)));
    float r = -vDot_0250(vNorm_0250(u), b);
    float f = *(float*)((char*)self + 0xDF4);
    if (f == 1.0f)
        return r;
    return r * 0.12667641043663025f * f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00100348);
#ifdef SKIP_ASM
struct sV4_0348
{
    float x, y, z, w;
} __attribute__((aligned(16)));

class cObj_0348 {
public:
    virtual void vm1();
    virtual sV4_0348* GetDir();
    virtual void v1();
    virtual void v2();
    virtual sV4_0348* GetPos();
};

extern sV4_0348 D_004FF160_v0348 __asm__("D_004FF160");
extern "C" float func_0031C228(float);

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sV4_0348 Cross_0348(const sV4_0348& a, const sV4_0348& b)
{
    sV4_0348 r;
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_0348 Sub_0348(const sV4_0348& a, const sV4_0348& b)
{
    sV4_0348 r;
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_0348 Scale_0348(const sV4_0348& v, float s)
{
    sV4_0348 r;
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sV4_0348 Norm_0348(const sV4_0348& v)
{
    sV4_0348 r;
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
static inline float Dot_0348(const sV4_0348& a, const sV4_0348& b)
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

// PORT: PS2-only FPU asm (absolute value).
static inline float Abs_0348(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline float Atan2_0348(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f)
            r += 3.1415927410125732f;
        else
            r -= 3.1415927410125732f;
    }
    return r;
}

static inline cObj_0348* Obj_0348(char* self) { return (cObj_0348*)(*(char**)(self + 0x18) + 0x6C0); }

extern "C" float func_00100348_0348(char* self, sV4_0348* target) __asm__("func_00100348");
extern "C" float func_00100348_0348(char* self, sV4_0348* target)
{
    sV4_0348 up = *(sV4_0348*)(*(char**)(self + 0x18) + 0x1C0);
    if (up.z <= 0.0f)
        up = D_004FF160_v0348;
    sV4_0348 fwd = *Obj_0348(self)->GetDir();
    sV4_0348 side = Cross_0348(fwd, up);
    sV4_0348 d = Sub_0348(*target, *Obj_0348(self)->GetPos());
    d.z = 0.0f;
    d = Norm_0348(d);
    d = Norm_0348(Sub_0348(d, Scale_0348(up, Dot_0348(d, up))));
    float x = Dot_0348(d, fwd);
    float y = Dot_0348(d, side);
    float a = Atan2_0348(y, x);
    float t = Abs_0348(a) * 6.289702415466309f;
    if (t < 0.019999999552965164f) {
        t = 0.0f;
    } else {
        if (t > 0.9800000190734863f)
            t = 0.9800000190734863f;
        if (a < 0.0f)
            t = -t;
    }
    return t;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00100610);
#ifdef SKIP_ASM
struct sV4_0610 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_0610 Add_0610(const sV4_0610& a, const sV4_0610& b)
{
    sV4_0610 r;
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
static inline sV4_0610 Sub_0610(const sV4_0610& a, const sV4_0610& b)
{
    sV4_0610 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_0610 Scale_0610(const sV4_0610& v, float s)
{
    sV4_0610 r;
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

struct sCam_0610 {
    char pad0[0x110];
    sV4_0610 pos;       // 0x110
    char pad120[0x490 - 0x120];
    sV4_0610 target;    // 0x490
    char pad4A0[0x10];
    sV4_0610 base;      // 0x4B0
};

// PORT: the unit later declares func_00100610 with the out-pointer spelled out; same symbol, by-value return here
sV4_0610 func_00100610_0610(char* self) __asm__("func_00100610");

sV4_0610 func_00100610_0610(char* self)
{
    sV4_0610 d = Sub_0610((*(sCam_0610**)(self + 0x18))->target, (*(sCam_0610**)(self + 0x18))->pos);
    d = Scale_0610(d, 0.1f);
    return Add_0610((*(sCam_0610**)(self + 0x18))->base, d);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_00100680);
#ifdef SKIP_ASM
struct sV4_0680 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPad_0680 {
    unsigned int pad0 : 17;
    unsigned int b17 : 1;
    unsigned int pad18 : 2;
    int b20 : 6;
    unsigned int pad26 : 6;
    int w0 : 6;
    int w6 : 6;
};

class cObj_0680;
typedef void (cObj_0680::*Fn_0680)();
extern "C" Fn_0680 D_0043CF20_0680[4] __asm__("D_0043CF20");

class cAI_0680 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int Busy();
};

struct sRiders_0680 {
    char pad[0x28];
    char* riders[1];
};

struct sGame_0680 {
    char pad[0xC];
    sRiders_0680* list;
};

struct sWorld_0680 {
    char pad[0x84];
    sGame_0680* game;
};

extern sWorld_0680* D_004A28A8_0680 __asm__("D_004A28A8");

extern "C" void func_00100610_0680(sV4_0680*, void*) __asm__("func_00100610");
extern "C" float func_00100348_0680(void*, sV4_0680*) __asm__("func_00100348");
extern "C" int func_0010BB18_0680(void*, float*, int*) __asm__("func_0010BB18");
extern "C" int func_0010BBF8_0680(void*, int*) __asm__("func_0010BBF8");
extern "C" void func_0010C140_0680(void*, void*) __asm__("func_0010C140");
extern "C" void func_0010C0A8_0680(void*, void*) __asm__("func_0010C0A8");
extern "C" int func_0010B980_0680(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6) __asm__("func_0010B980");
extern "C" int func_0010BD10_0680(char* self, int* out) __asm__("func_0010BD10");
extern "C" void func_00100680_0680(char* self, sPad_0680* pad) __asm__("func_00100680");

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len_0680(const sV4_0680& v)
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

extern "C" void func_00100680_0680(char* self, sPad_0680* pad)
{
    sV4_0680 v;
    int x;
    int y;
    int below, o3, o4, o5, o6;
    int z;
    func_00100610_0680(&v, self);
    pad->b20 = (int)(func_00100348_0680(self, &v) * 31.0f);
    if (func_0010BB18_0680(self, (float*)(self + 0xDF0), &x)) {
        float sp = *(float*)(self + 0xDF0);
        float len = Len_0680(*(sV4_0680*)(*(char**)(self + 0x18) + 0x1E0));
        if (sp + 138.88890075683594f < len) {
            if (x)
                pad->w0 = 0x1F;
        } else if (len < sp - 138.88890075683594f) {
            if (x)
                func_0010C140_0680(self, pad);
            else
                func_0010C0A8_0680(self, pad);
        }
    } else if (func_0010BBF8_0680(self, &y)) {
        float s = 1.0f;
        if (y)
            s = -1.0f;
        int c = *(int*)(self + 0xE40);
        if (c == 0) {
            pad->w6 = (int)(-s * 31.0f);
            *(int*)(self + 0xE40) = 60;
        } else if (c > 0) {
            *(int*)(self + 0xE40) = c - 1;
            if (c - 1 <= 0)
                *(int*)(self + 0xE40) = -1;
            pad->w6 = (int)(-s * 31.0f);
        } else {
            pad->w6 = (int)(s * 31.0f);
        }
    } else {
        *(int*)(self + 0xE40) = 0;
        char* r = *(char**)(self + 0x18);
        if (*(float*)(r + 0x2F8) >= 0.8999999761581421f && *(float*)(r + 0x2F0) > 0.0f && *(float*)(self + 0xDF8) > 50.0f)
            pad->b17 = 1;
        func_0010C0A8_0680(self, pad);
    }
    float* spd = (float*)(self + 0xDF0);
    z = 0;
    if (func_0010B980_0680(self, spd, &below, &o3, &o4, &o5, &o6)) {
        *(int*)(self + 0xE70) = -1;
        *(Fn_0680*)(self + 0xF44) = D_0043CF20_0680[0];
        *(short*)(self + 0xF38) = 0;
    } else if (func_0010BD10_0680(self, &z)) {
        if (z) {
            *(Fn_0680*)(self + 0xF44) = D_0043CF20_0680[3];
            *(short*)(self + 0xF38) = 3;
        } else if (!((cAI_0680*)(D_004A28A8_0680->game->list->riders[*(int*)((char*)spd + 0x80)] + 0x6C0))->Busy()) {
            *(Fn_0680*)(self + 0xF44) = D_0043CF20_0680[2];
            *(short*)(self + 0xF38) = 2;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_001009E0);
#ifdef SKIP_ASM
struct sVec4_09E0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPad_09E0 {
    unsigned int pad0 : 14;
    unsigned int b14 : 2;
    unsigned int pad16 : 4;
    int b20 : 6;
    unsigned int pad26 : 6;
    int w0 : 6;
};

class cObj_8E88;
typedef void (cObj_8E88::*Fn_8E88)();
extern "C" Fn_8E88 D_0043CF20[4];

extern "C" int func_0010B980(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6);
extern "C" void func_0010BFA8_09E0(char*, int, int, int, int) __asm__("func_0010BFA8");
extern "C" void func_00100610_09E0(sVec4_09E0*, void*) __asm__("func_00100610");
extern "C" float func_00100348_09E0(void*, sVec4_09E0*) __asm__("func_00100348");
extern "C" void func_00100680(void*, void*);
extern "C" void func_0010C140(void*, void*);

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_09E0(const sVec4_09E0& v)
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

// PORT: PS2 abs.s helper (stands in for fabsf).
static inline float vAbs_09E0(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_001009E0(char* self, sPad_09E0* pad)
{
    int below, o3, o4, o5, o6;
    if (!func_0010B980(self, (float*)(self + 0xDF0), &below, &o3, &o4, &o5, &o6)) {
        *(Fn_8E88*)(self + 0xF44) = D_0043CF20[1];
        *(short*)(self + 0xF38) = 1;
        func_00100680(self, pad);
        return;
    }
    sVec4_09E0 v;
    func_00100610_09E0(&v, self);
    float f = func_00100348_09E0(self, &v);
    pad->b20 = (int)(f * 31.0f);
    char* rider = *(char**)(self + 0x18);
    float len = vLen_09E0(*(sVec4_09E0*)(rider + 0x1E0));
    if (below && *(float*)(rider + 0x4C8) < 10000.0f && vAbs_09E0(f) < 1.0f) {
        func_0010BFA8_09E0(self, o5, o6, o4, o3);
        pad->b14 = 3;
        return;
    }
    float sp = *(float*)(self + 0xDF0);
    if (len < sp - 138.88890075683594f) {
        func_0010C140(self, pad);
        return;
    }
    if (sp + 138.88890075683594f < len)
        pad->w0 = 0x1F;
}
#endif

INCLUDE_ASM("seg/seg_1218", func_00100B90);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_00100F88);
#ifdef SKIP_ASM
struct sV4_0F88 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPad_0F88 {
    unsigned int pad0 : 20;
    int b20 : 6;
};

struct sRec_0F88 {
    int active;
    int pad4;
    float dist;
    float angle;
    char pad10[0x24 - 0x10];
};

class cObj_0F88;
typedef void (cObj_0F88::*Fn_0F88)();
extern "C" Fn_0F88 D_0043CF20_0F88[4] __asm__("D_0043CF20");

class cAI_0F88 {
public:
    virtual void vm1();
    virtual sV4_0F88* GetVel();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Ready();
};

class cRiderBase_0F88 {
public:
    char pad[0x6C0];
};

class cRider_0F88 : public cRiderBase_0F88, public cAI_0F88 {
};

struct sRiders_0F88 {
    char pad[0x28];
    cRider_0F88* riders[1];
};

struct sGame_0F88 {
    char pad[0xC];
    sRiders_0F88* list;
};

struct sWorld_0F88 {
    char pad[0x84];
    sGame_0F88* game;
};

struct sCtl_0F88 {
    float speed;
    char pad4[0x80 - 4];
    int target;
};

extern sWorld_0F88* D_004A28A8_0F88 __asm__("D_004A28A8");

extern "C" void func_00100610_0F88(sV4_0F88*, void*) __asm__("func_00100610");
extern "C" float func_00100348_0F88(void*, sV4_0F88*) __asm__("func_00100348");
extern "C" void func_0010C140_0F88(void*, void*) __asm__("func_0010C140");
extern "C" void func_0010C0A8_0F88(void*, void*) __asm__("func_0010C0A8");
extern "C" int func_0010B980_0F88(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6) __asm__("func_0010B980");
extern "C" int func_0010BD10_0F88(char* self, int* out) __asm__("func_0010BD10");
extern "C" float func_0031C228(float);
extern "C" void func_00112A50(void*, int);

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len_0F88(const sV4_0F88& v)
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
static inline float Abs_0F88(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: PS2-only FPU asm (float -> int -> float truncation).
static inline float Trunc_0F88(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    return t;
}

static inline float Floor_0F88(float x)
{
    float t = Trunc_0F88(x);
    if (x < t)
        t -= 1.0f;
    return t;
}

static inline sRec_0F88* Rec_0F88(char* self) { return &((sRec_0F88*)*(char**)(self + 0x18))[*(int*)(self + 0xE70)]; }

extern "C" void func_00100F88(char* self, sPad_0F88* pad)
{
    sV4_0F88 v;
    int below, o3, o4, o5, o6;
    int z;
    sCtl_0F88* ctl = (sCtl_0F88*)(self + 0xDF0);
    sRec_0F88* rec = Rec_0F88(self);
    cRider_0F88* tgt = D_004A28A8_0F88->game->list->riders[ctl->target];
    float diff = rec->angle - *(float*)(*(char**)(self + 0x18) + 0x4CC);
    float ang = diff - Floor_0F88(diff * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
    float mySpd = Len_0F88(*(sV4_0F88*)(*(char**)(self + 0x18) + 0x1E0));
    float hisSpd = Len_0F88(*tgt->GetVel());
    float steer = 0.0f;
    if (Abs_0F88(ang) > 1.5707964897155762f) {
        func_00100610_0F88(&v, self);
        steer = func_00100348_0F88(self, &v);
        if (mySpd < hisSpd)
            func_0010C140_0F88(self, pad);
        else
            func_0010C0A8_0F88(self, pad);
    } else {
        float d = Rec_0F88(self)->dist;
        float lim;
        if (d == 0.0f) {
            lim = 1.5707963705062866f;
        } else {
            lim = func_0031C228(150.0f / d);
            if (d < 0.0f)
                lim += 3.1415927410125732f;
        }
        if (Abs_0F88(ang) > lim || mySpd <= hisSpd) {
            func_00100610_0F88(&v, self);
            steer = func_00100348_0F88(self, &v);
            func_0010C0A8_0F88(self, pad);
        } else if (tgt->Ready()) {
            if (*(int*)((char*)tgt + 0xAB8) == *(int*)(*(char**)(self + 0x18) + 0xAB8))
                func_00112A50(*(char**)(self + 0x18), 0);
            func_00100610_0F88(&v, self);
            steer = func_00100348_0F88(self, &v);
            func_0010C0A8_0F88(self, pad);
        }
    }
    pad->b20 = (int)(steer * 31.0f);
    z = 0;
    if (func_0010B980_0F88(self, (float*)(self + 0xDF0), &below, &o3, &o4, &o5, &o6)) {
        *(int*)(self + 0xE70) = -1;
        *(Fn_0F88*)(self + 0xF44) = D_0043CF20_0F88[0];
        *(short*)(self + 0xF38) = 0;
    } else if (!func_0010BD10_0F88(self, &z)) {
        *(Fn_0F88*)(self + 0xF44) = D_0043CF20_0F88[1];
        *(short*)(self + 0xF38) = 1;
    } else if (z) {
        *(Fn_0F88*)(self + 0xF44) = D_0043CF20_0F88[3];
        *(short*)(self + 0xF38) = 3;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101310);
#ifdef SKIP_ASM
extern "C" void func_00101688(void* self);

struct sSlotA_101310 {
    char pad[0x18];
    unsigned int id;
    sSlotA_101310() : id(0xFFFFFFFF) {}
};

struct sSlotB_101310 {
    unsigned int id;
    char pad[0xC];
    sSlotB_101310() : id(0xFFFFFFFF) {}
};

class cTable_101310 {
public:
    void* owner;
    sSlotA_101310 a[64];
    char pad704[0x50];
    sSlotB_101310 b[64];
    cTable_101310(void* o);
};

cTable_101310::cTable_101310(void* o)
{
    owner = o;
    func_00101688(this);
}
// PORT: the compiler names this ctor __13cTable_101310Pv; expose it under the address-derived name.
__asm__(".globl func_00101310\n.type func_00101310,@function\nfunc_00101310 = __13cTable_101310Pv\n.size func_00101310,0x94\n");
#endif

INCLUDE_ASM("seg/seg_1218", func_001013A8);

//100%
INCLUDE_ASM("seg/seg_1218", func_00101688);
#ifdef SKIP_ASM
struct sSlotA_101688 {
    int f0;
    int f4;
    int state;          // 0x8
    char padC[0x10];
};

struct sPair_101688 {
    int a;
    int b;
    int c;
};

struct sNode_101688 {
    int f0;
    int f4;
    int f8;
    sNode_101688* next; // 0xC
};

struct sTable_101688 {
    void* owner;                // 0x000
    sSlotA_101688 slots[64];    // 0x004
    int count;                  // 0x704
    int f708;                   // 0x708
    sPair_101688 pairs[6];      // 0x70C
    sNode_101688 nodes[64];     // 0x754
    sNode_101688* freeList;     // 0xB54
    int fB58;                   // 0xB58
    int fB5C;                   // 0xB5C
};

extern "C" void func_00101688(void* vself)
{
    sTable_101688* self = (sTable_101688*)vself;
    int i;
    self->count = 0;
    int j;
    for (j = 0; j < 64; j++)
        self->slots[j].state = 2;
    for (i = 0; i < 6; i++) {
        self->pairs[i].a = 0;
        self->pairs[i].b = 0;
    }
    for (i = 0; i < 63; i++)
        self->nodes[i].next = &self->nodes[i + 1];
    self->freeList = self->nodes;
    self->nodes[63].next = 0;
    self->fB58 = 0;
    self->fB5C = 0;
    self->f708 = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101728);
#ifdef SKIP_ASM
struct sVec4_1728 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sXform_1728 {
    char pad[0x30];
    sVec4_1728 pos;
};

class cComp_1728 {
public:
    int f0;
    int f4;
    int f8;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int IsDead();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual sXform_1728* GetXform();
};

struct sObj_1728 {
    int pad[3];
    cComp_1728* comp;
};

struct sBank_1728 {
    char pad[0x1C];
    unsigned int* handles;
};

struct sWorld_1728 {
    int pad[2];
    sBank_1728** banks;
};

struct sEnt_1728 {
    float x;
    float y;
    int state;
    float px, py, pz;
    unsigned int id;
};

struct sMgr_1728 {
    int f0;
    sEnt_1728 ents[64];
    int count;
};

extern sWorld_1728** D_004A47B8;
extern "C" void func_00101888(sMgr_1728*, unsigned int*);

static inline sObj_1728* lookup_1728(unsigned int id)
{
    sBank_1728* b = (*D_004A47B8)->banks[id & 0xFF];
    if (b) {
        unsigned int v = b->handles[id >> 8] >> 8;
        if (v)
            return (sObj_1728*)(v << 2); // PORT: packed pointer in a 32-bit handle
    }
    return 0;
}

extern "C" void func_00101728(sMgr_1728* self, unsigned int* idp, float x, float y)
{
    cComp_1728* c = lookup_1728(*idp)->comp;
    if (c == 0)
        return;
    if (c->IsDead())
        return;
    func_00101888(self, idp);
    for (int i = 0; i < 64; i++) {
        sEnt_1728* e = &self->ents[i];
        if (e->state == 2) {
            e->state = 0;
            e->id = *idp;
            e->x = x;
            e->y = y;
            sVec4_1728 p = c->GetXform()->pos;
            e->px = p.x;
            e->py = p.y;
            e->pz = p.z;
            self->count++;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101888);
#ifdef SKIP_ASM
void func_001441A0(void*, void*);

extern "C" void func_00101888(sMgr_1728* self, unsigned int* idp)
{
    int n = self->count;
    if (n != 0) {
        int remaining = n;
        for (int i = 0; i < 64 && remaining != 0; i++) {
            sEnt_1728* e = &self->ents[i];
            if (e->state != 2) {
                remaining--;
                if (e->id == *idp) {
                    func_001441A0(self, e);
                    return;
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101900);
#ifdef SKIP_ASM
struct N_1900 { int key; int val; int refs; N_1900 *next; };
struct P_1900 { char pad[0xB54]; N_1900 *freelist; N_1900 *used; };

extern "C" void func_00101900(P_1900 *arg0, int *arg1, int arg2) {
    N_1900 *p;
    N_1900 *n;

    for (p = arg0->used; p != 0; p = p->next) {
        if (p->key == *arg1) {
            p->refs++;
            return;
        }
    }
    n = arg0->freelist;
    arg0->freelist = n->next;
    n->key = *arg1;
    n->val = arg2;
    n->refs = 1;
    n->next = arg0->used;
    arg0->used = n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101970);
#ifdef SKIP_ASM
struct sNode_1970 { int key; int pad; int ref; sNode_1970* next; };
struct sC_1970 { int x, a, b; };
struct sSelf_1970 {
    char pad0[0x708];
    sC_1970 arrC[6];
    char pad1[0x754 - 0x750];
    char pad2[0xB54 - 0x754];
    sNode_1970* freeList;
    sNode_1970* used;
};
extern "C" void func_00101970(sSelf_1970* self, int* key) {
    sNode_1970* prev = 0;
    sNode_1970* n = self->used;
    while (n) {
        if (n->key == *key) {
            if (--n->ref == 0) {
                if (prev) prev->next = n->next;
                else self->used = n->next;
                n->next = self->freeList;
                self->freeList = n;
                if (self->used == 0) {
                    for (int k = 0; k < 6; k++) { self->arrC[k].a = 0; self->arrC[k].b = 0; }
                }
            }
            return;
        }
        prev = n;
        n = n->next;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101A10);
#ifdef SKIP_ASM
extern "C" int func_00101A10(int arg0, int arg1) {
    return (*(int *)((char*)(((arg1 * 0xC) + arg0)) + (0x710)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101A28);
#ifdef SKIP_ASM
struct sLink_1A28 {
    sLink_1A28* next;
};

struct sNode_1A28 {
    sNode_1A28* kids[8];
    sLink_1A28* items;
};

struct sList_1A28 {
    int n;
    sLink_1A28* items[1];
};

extern int D_004A3DD8;
extern "C" int func_0030A310(int, sLink_1A28*);

extern "C" void func_00101A28(sList_1A28* list, sNode_1A28* node, int recurse)
{
    sLink_1A28* p;
    for (p = node->items; p; p = p->next) {
        if (func_0030A310(D_004A3DD8, p))
            list->items[list->n++] = p;
    }
    if (recurse) {
        if (node->kids[0]) func_00101A28(list, node->kids[0], 1);
        if (node->kids[1]) func_00101A28(list, node->kids[1], 1);
        if (node->kids[2]) func_00101A28(list, node->kids[2], 1);
        if (node->kids[3]) func_00101A28(list, node->kids[3], 1);
        if (node->kids[4]) func_00101A28(list, node->kids[4], 1);
        if (node->kids[5]) func_00101A28(list, node->kids[5], 1);
        if (node->kids[6]) func_00101A28(list, node->kids[6], 1);
        if (node->kids[7]) func_00101A28(list, node->kids[7], 1);
    }
}
#endif

INCLUDE_ASM("seg/seg_1218", func_00101B60);

//100%
INCLUDE_ASM("seg/seg_1218", func_001032C0);
#ifdef SKIP_ASM
struct S_32C0 {
    char pad[0xD4];
    int flag;
    int n;
    void *arr[8];
};

extern "C" void func_001032C0(S_32C0 *arg0, void *arg1) {
    int temp_3;
    int temp_6;
    int var_2;
    int n;

    temp_3 = (*(int *)((char*)(arg1) + (8)));
    temp_6 = temp_3 | 0x100;
    (*(int *)((char*)(arg1) + (8))) = temp_6;
    if (arg0->flag != 0) {
        var_2 = temp_6 & 0xFFFFFDFF;
    } else {
        var_2 = temp_3 | 0x300;
    }
    (*(int *)((char*)(arg1) + (8))) = var_2;
    n = arg0->n;
    arg0->arr[n] = arg1;
    arg0->n = n + 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103308);
#ifdef SKIP_ASM
struct S_3308 { char pad[0xD8]; int cnt; void *arr[8]; };
extern "C" void func_00103308(S_3308 *arg0, int arg1) {
    int n = 0;
    int i;

    for (i = 0; i < arg0->cnt; i++) {
        void *e = arg0->arr[i];
        if (*(unsigned char *)((char*)e + 0x78) != arg1) {
            arg0->arr[n] = e;
            n++;
        }
    }
    arg0->cnt = n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103358);
#ifdef SKIP_ASM
struct S_3358 { char pad[0xD0]; int f_d0; int pad2; int cnt; void *arr[8]; };
extern "C" void func_00103358(S_3358 *arg0) {
    int i;

    for (i = 0; i < arg0->cnt; i++) {
        *(int *)((char*)arg0->arr[i] + 8) &= 0xFFFFFEFF;
    }
    arg0->cnt = 0;
    arg0->f_d0 = -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001033B0);
#ifdef SKIP_ASM
struct V_33B0 { int x, y, z, w; } __attribute__((aligned(16)));

extern "C" void func_001033B0(void *arg0, V_33B0 *arg1) {
    V_33B0 sp0;

    (*(int *)((char*)(arg0) + (0xD0))) = -1;
    (*(V_33B0 **)((char*)(arg0) + ((*(int *)((char*)(arg0) + (0))) << 5) + (0x10))) = arg1;
    sp0 = *arg1;
    (*(V_33B0 *)((char*)((((*(int *)((char*)(arg0) + (0))) << 5) + (int)arg0)) + (0x20))) = sp0;
    (*(int *)((char*)(arg0) + (0))) = (int) ((*(int *)((char*)(arg0) + (0))) + 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001033F8);
#ifdef SKIP_ASM
struct sEntry1033F8 {
    int id;
    int data[7];
} __attribute__((aligned(16)));

struct sList1033F8 {
    int count;
    char pad4[0xC];
    sEntry1033F8 entries[6];    // 0x10
    int fD0;                    // 0xD0
};

// Removes the entry with the given id from the list, shifting the rest down.
extern "C" void func_001033F8(sList1033F8* self, int id)
{
    int i;
    self->fD0 = -1;
    for (i = 0; i < self->count; i++) {
        if (self->entries[i].id == id) {
            for (i++; i < self->count; i++) {
                self->entries[i - 1] = self->entries[i];
            }
            self->count--;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103480);
#ifdef SKIP_ASM
class cStream_3480 {
public:
    virtual void Write(void* p, int n);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void WriteInt(int v);
};

struct sEnt_3480 {
    char d[0x20];
};

struct sObj_3480 {
    int n;
    char pad4[0x1C];
    sEnt_3480 ents[5];
    char padC0[0x10];
    int fD0;
    int pad;
    int m;
    int vals[1];
};

extern "C" void func_00103480(sObj_3480* self, cStream_3480* s)
{
    s->Write(&self->fD0, 4);
    for (int i = 0; i < self->n; i++)
        s->Write(&self->ents[i], 0x10);
    s->Write(&self->m, 4);
    for (int j = 0; j < self->m; j++)
        s->WriteInt(self->vals[j]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103578);
#ifdef SKIP_ASM
struct sItem_3578 {
    int f0;
    int f4;
    unsigned int flags;
};

class cStream_3578 {
public:
    virtual void v0();
    virtual void Read(void* p, int n);
    virtual sItem_3578* ReadPtr();
};

struct sEnt_3578 {
    char d[0x20];
};

struct sObj_3578 {
    int n;
    char pad4[0x1C];
    sEnt_3578 ents[5];
    char padC0[0x10];
    int fD0;
    int fD4;
    int m;
    sItem_3578* items[1];
};

extern "C" void func_00103578(sObj_3578* self, cStream_3578* s)
{
    s->Read(&self->fD0, 4);
    for (int i = 0; i < self->n; i++)
        s->Read(&self->ents[i], 0x10);
    self->fD4 = 1;
    s->Read(&self->m, 4);
    for (int j = 0; j < self->m; j++) {
        sItem_3578* it = s->ReadPtr();
        it->flags = (it->flags | 0x100) & 0xFFFFFDFF;
        self->items[j] = it;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001036A0);
#ifdef SKIP_ASM
extern "C" char* cAIAnimEventMap_getBlendInTime(int id);
// PORT: the handlers are defined later in the unit with mixed parameter/return types; bind uniform views by asm label
extern "C" int f_001048C0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001048C0");
extern "C" int f_00104940_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104940");
extern "C" int f_001049C0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001049C0");
extern "C" int f_00104110_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104110");
extern "C" int f_00104178_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104178");
extern "C" int f_00104238_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104238");
extern "C" int f_001042A8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001042A8");
extern "C" int f_00104358_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104358");
extern "C" int f_001045D8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001045D8");
extern "C" int f_00104660_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104660");
extern "C" int f_001042E0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001042E0");
extern "C" int f_001043F8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001043F8");
extern "C" int f_001045B8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001045B8");
extern "C" int f_001047F0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001047F0");
extern "C" int f_00104728_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104728");
extern "C" int f_001046B0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001046B0");
extern "C" void func_00103AA0_36A0(void* self, void* anim) __asm__("func_00103AA0");

extern "C" void func_001036A0(char* self, void* x, int* anim, float dt)
{
    int done = 0;
    switch (*(int*)(cAIAnimEventMap_getBlendInTime(*anim) + 4)) {
    case 0:
        done = f_001048C0_36A0(self, x, anim, dt);
        break;
    case 1:
        done = f_00104940_36A0(self, x, anim, dt);
        break;
    case 2:
        done = f_001049C0_36A0(self, x, anim, dt);
        break;
    case 3:
        done = f_00104110_36A0(self, x, anim, dt);
        break;
    case 4:
        done = f_00104178_36A0(self, x, anim, dt);
        break;
    case 5:
        done = f_00104238_36A0(self, x, anim, dt);
        break;
    case 6:
        done = f_001042A8_36A0(self, x, anim, dt);
        break;
    case 7:
        done = f_00104358_36A0(self, x, anim, dt);
        break;
    case 8:
        done = f_001045D8_36A0(self, x, anim, dt);
        break;
    case 9:
        done = f_00104660_36A0(self, x, anim, dt);
        break;
    case 10:
        done = f_001042E0_36A0(self, x, anim, dt);
        break;
    case 11:
        done = f_001043F8_36A0(self, x, anim, dt);
        break;
    case 12:
        done = f_001045B8_36A0(self, x, anim, dt);
        break;
    case 13:
        done = f_001047F0_36A0(self, x, anim, dt);
        break;
    case 14:
        done = f_00104728_36A0(self, x, anim, dt);
        break;
    case 15:
        done = f_001046B0_36A0(self, x, anim, dt);
        break;
    }
    if (done == 0) {
        char* r = *(char**)(self + 0x60);
        if (r != 0) {
            int ok = 0;
            if (*(int*)(r + 0x874) != 0) {
                ok = *(int*)(r + 0x87C) != 0;
            }
            if (ok) {
                func_00103AA0_36A0(self, anim);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103918);
#ifdef SKIP_ASM
extern "C" char* cAIAnimEventMap_getBlendInTime(int id);
extern "C" int func_00104CA0_3918(void* self, void* ev, void* data) __asm__("func_00104CA0");
extern "C" int func_00104A40_3918(void* self, void* ev, void* data) __asm__("func_00104A40");
extern "C" int func_00104A60_3918(void* self, void* ev, void* data) __asm__("func_00104A60");
extern "C" int func_00104B78_3918(void* self, void* ev, void* data) __asm__("func_00104B78");
extern "C" int func_00104C18_3918(void* self, void* ev, void* data) __asm__("func_00104C18");
extern "C" int func_00104B48_3918(void* self, void* ev, void* data) __asm__("func_00104B48");
extern "C" int func_00104C38_3918(void* self, void* ev, void* data) __asm__("func_00104C38");
extern "C" int func_00104B98_3918(void* self, void* ev, void* data) __asm__("func_00104B98");
extern "C" int func_00104BB8_3918(void* self, void* ev, void* data) __asm__("func_00104BB8");
extern "C" int func_00104BD8_3918(void* self, void* ev, void* data) __asm__("func_00104BD8");
extern "C" int func_00104C80_3918(void* self, void* ev, void* data) __asm__("func_00104C80");

struct sEvent3918 { int a; int b; };

struct sEventOwner3918 {
    int results[20];        // 0x00
    sEvent3918* events;     // 0x50
};

// Runs the handler for an animation event's type and stores its result in the per-event slot.
extern "C" void func_00103918(sEventOwner3918* self, sEvent3918* ev, int* data)
{
    int idx = ev - self->events;
    char* info = cAIAnimEventMap_getBlendInTime(*data);
    switch (*(int*)(info + 8)) {
    case 0:
        self->results[idx] = func_00104CA0_3918(self, ev, data);
        break;
    case 1:
        self->results[idx] = func_00104A40_3918(self, ev, data);
        break;
    case 2:
        self->results[idx] = func_00104A60_3918(self, ev, data);
        break;
    case 3:
        self->results[idx] = func_00104B78_3918(self, ev, data);
        break;
    case 4:
        self->results[idx] = func_00104C18_3918(self, ev, data);
        break;
    case 5:
        self->results[idx] = func_00104B48_3918(self, ev, data);
        break;
    case 6:
        self->results[idx] = func_00104C38_3918(self, ev, data);
        break;
    case 7:
        self->results[idx] = func_00104B98_3918(self, ev, data);
        break;
    case 8:
        self->results[idx] = func_00104BB8_3918(self, ev, data);
        break;
    case 9:
        self->results[idx] = func_00104BD8_3918(self, ev, data);
        break;
    case 10:
        self->results[idx] = func_00104C80_3918(self, ev, data);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103AA0);
#ifdef SKIP_ASM
struct sEnt_3AA0 {
    char pad[0x10];
    unsigned short first;
    unsigned short count;
};

struct sRec_3AA0 {
    unsigned short a;
    unsigned short b;
};

struct sBank_3AA0 {
    int pad[2];
    sEnt_3AA0* ents;
    int padC;
    sRec_3AA0* recs;
};

struct sObj_3AA0 {
    int f0;
    unsigned int id;
    char pad[0xA8];
    char sub[1];
};

struct sBankTab_3AA0 {
    sBank_3AA0* banks[1];
};

extern sBankTab_3AA0* D_004A3DF8;
extern "C" int func_001446A0(void*, int);
extern "C" int func_001446B8(void*, int);
extern "C" void func_00144670(void*, int);
extern "C" void func_00104CC8(void*, int);

extern "C" void func_00103AA0(void* self, sObj_3AA0* o)
{
    int n = D_004A3DF8->banks[o->id & 0xFF]->ents[o->id >> 8].count;
    for (int i = 0; i < n; i++) {
        int ok = 0;
        if (func_001446A0(o->sub, i) && func_001446B8(o->sub, i))
            ok = 1;
        if (ok) {
            sBank_3AA0* b = D_004A3DF8->banks[o->id & 0xFF];
            unsigned short r = b->recs[b->ents[o->id >> 8].first + i].b;
            if (r & 0x8000) {
                func_00144670(o->sub, i);
                func_00104CC8(self, r & 0x7FFF);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103BE0);
#ifdef SKIP_ASM
extern char* D_004A3E7C;
extern "C" void func_00313C50(void*, int, int);
extern "C" void func_00313CF0(void*, int, float);
extern "C" int func_00313800(void*, float);
extern "C" void func_003145F8(void*, void*);
extern "C" int func_00103BE0(void* self, void* x, char* anim, int a, int b, float dt, float v)
{
    if (v < 0.0f) {
        func_00313C50(anim, 0, *(int*)(D_004A3E7C + b * 4 + 0x1030));
        func_00313CF0(anim, 0, -v * *(float*)(anim + 0x10));
    } else {
        func_00313C50(anim, 0, *(int*)(D_004A3E7C + a * 4 + 0x1030));
        func_00313CF0(anim, 0, v * *(float*)(anim + 0x10));
    }
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103CC8);
#ifdef SKIP_ASM
extern char* D_004A3E7C;
extern "C" void func_00313D40(void*, int, int);
extern "C" void func_003135B0(void*, int, float);
extern "C" void func_00313C50(void*, int, int);
extern "C" void func_00313CF0(void*, int, float);
extern "C" void func_00313D28(void*, int, float);
extern "C" int func_00313800(void*, float);
extern "C" void func_003145F8(void*, void*);

extern "C" int func_00103CC8(void* self, void* x, char* anim, int a, int b, float dt, float w, int c)
{
    func_00313C50(anim, 0, *(int*)(D_004A3E7C + b * 4 + 0x1030));
    if (0.0f < w) {
        func_00313C50(anim, 1, *(int*)(D_004A3E7C + c * 4 + 0x1030));
    } else {
        w = -w;
        func_00313C50(anim, 1, *(int*)(D_004A3E7C + a * 4 + 0x1030));
    }
    func_00313D28(anim, 0, 1.0f - w);
    func_00313D28(anim, 1, w);
    func_00313D40(anim, 0, 1);
    float t = dt * 0.01666666753590107f;
    func_003135B0(anim, 0, t);
    func_00313CF0(anim, 1, *(float*)(anim + 8) / *(float*)(anim + 0x10) * *(float*)(anim + 0x2C));
    if (func_00313800(anim, t)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103E28);
#ifdef SKIP_ASM
extern char* D_004A3E7C;
extern "C" void func_00313D40(void*, int, int);
extern "C" void func_003135B0(void*, int, float);
extern "C" void func_00313C50(void*, int, int);
extern "C" void func_00313CF0(void*, int, float);
extern "C" void func_00313D28(void*, int, float);
extern "C" int func_00313800(void*, float);
extern "C" void func_003145F8(void*, void*);

extern "C" int func_00103E28(void* self, void* x, char* anim, int i0, int i1, int i2, int i3, int i4, float dt, float v)
{
    int from, to;
    float w;
    if (v > 0.5f) {
        from = i4;
        to = i3;
        w = (v - 0.5f) * 2.0f;
    } else if (v > 0.0f) {
        from = i3;
        to = i2;
        w = v * 2.0f;
    } else if (v > -0.5f) {
        from = i2;
        to = i1;
        w = v * 2.0f + 1.0f;
    } else {
        from = i1;
        to = i0;
        w = (v + 1.0f) * 2.0f;
    }
    if (*(int*)(D_004A3E7C + from * 4 + 0x1030) != *(int*)(anim + 4)) {
        float r = *(float*)(anim + 8) / *(float*)(anim + 0x10);
        func_00313C50(anim, 0, *(int*)(D_004A3E7C + from * 4 + 0x1030));
        func_00313CF0(anim, 0, *(float*)(anim + 0x10) * r);
    }
    func_00313C50(anim, 1, *(int*)(D_004A3E7C + to * 4 + 0x1030));
    func_00313D28(anim, 0, w);
    func_00313D28(anim, 1, 1.0f - w);
    func_00313D40(anim, 0, 1);
    float t = dt * 0.01666666753590107f;
    func_003135B0(anim, 0, t);
    func_00313CF0(anim, 1, *(float*)(anim + 8) / *(float*)(anim + 0x10) * *(float*)(anim + 0x2C));
    if (func_00313800(anim, t)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103FF8);
#ifdef SKIP_ASM
extern char* D_004A3E7C;
extern "C" void func_00313D40(void*, int, int);
extern "C" void func_003135B0(void*, int, float);
extern "C" void func_00313C50(void*, int, int);
extern "C" void func_00313CF0(void*, int, float);
extern "C" int func_00313800(void*, float);
extern "C" void func_003145F8(void*, void*);

extern "C" int func_00103FF8(void* self, void* x, char* anim, int a, float dt, int b)
{
    if (*(int*)(anim + 4) == *(int*)(D_004A3E7C + a * 4 + 0x1030)) {
        func_00313D40(anim, 0, 0);
        func_003135B0(anim, 0, dt * 0.01666666753590107f);
        if (*(float*)(anim + 8) >= *(float*)(anim + 0x10)) {
            func_00313C50(anim, 0, *(int*)(D_004A3E7C + b * 4 + 0x1030));
            func_00313D40(anim, 0, 1);
            func_00313CF0(anim, 0, 0.0f);
        }
    } else {
        func_003135B0(anim, 0, dt * 0.01666666753590107f);
    }
    if (func_00313800(anim, dt * 0.01666666753590107f)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104110);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00103CC8_4110(void*, void*, int*, int, int, int, float, float) __asm__("func_00103CC8");

extern "C" int func_00104110(void *arg0, void *a1, int *arg2, float f12) {
    float var_f13;
    void *temp_3;

    temp_3 = (*(void **)((char*)(arg0) + (0x60)));
    var_f13 = (*(float *)((char*)(temp_3) + (0x1FC)));
    if ((*(int *)((char*)(temp_3) + (0x320))) != 0) {
        var_f13 = -var_f13;
    }
    if (*arg2 == 7) {
        return func_00103CC8_4110(arg0, a1, arg2, 0x11, 0xF, 0x10, f12, var_f13);
    }
    if (*arg2 == 0xA) {
        return func_00103CC8_4110(arg0, a1, arg2, 0x1A, 0x17, 0x19, f12, var_f13);
    }
    return func_00103CC8_4110(arg0, a1, arg2, 0x1A, 0x18, 0x19, f12, var_f13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104178);
#ifdef SKIP_ASM
extern "C" int func_00103E28(void* self, void* x, char* anim, int i0, int i1, int i2, int i3, int i4, float dt, float v);
extern "C" int func_00104178(char* self, void* x, int* anim, float dt)
{
    char* p = *(char**)(self + 0x60);
    float v = *(float*)(p + 0x1FC);
    if (*(int*)(p + 0x320) != 0)
        v = -v;
    int a, b, c, d, e;
    int s = *anim;
    if (s == 6) {
        a = 0xE; b = 0xD; c = 0xA; d = 0xB; e = 0xC;
    } else if (s == 8) {
        a = 0x16; b = 0x15; c = 0x12; d = 0x13; e = 0x14;
    } else if (s == 14) {
        a = 0x20; b = 0x1F; c = 0x1B; d = 0x1D; e = 0x1E;
    } else if (s != 15) {
        a = 9; b = 8; c = 5; d = 6; e = 7;
    } else {
        a = 0x20; b = 0x1F; c = 0x1C; d = 0x1D; e = 0x1E;
    }
    return func_00103E28(self, x, (char*)anim, a, b, c, d, e, dt, v);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104238);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00103CC8_4238(void*, void*, int*, int, int, int, float, float) __asm__("func_00103CC8");

extern "C" void func_00104238(void *arg0, void *a1, int *arg2, float f12) {
    int var_7;
    int var_8;
    int var_9;
    float var_f13;
    void *temp_3;

    temp_3 = (*(void **)((char*)(arg0) + (0x60)));
    var_f13 = (*(float *)((char*)(temp_3) + (0x238)));
    if ((*(int *)((char*)(temp_3) + (0x320))) != 0) {
        var_f13 = -var_f13;
    }
    switch (*arg2) {
    case 0x12:
        var_7 = 0x41;
        var_8 = 0x3F;
        var_9 = 0x40;
        break;
    default:
        var_7 = 0x47;
        var_8 = 0x45;
        var_9 = 0x46;
        break;
    case 0x13:
        var_7 = 0x44;
        var_8 = 0x42;
        var_9 = 0x43;
        break;
    }
    func_00103CC8_4238(arg0, a1, arg2, var_7, var_8, var_9, f12, var_f13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001042A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00103CC8_42A8(void*, void*, char*, int, int, int, float, float) __asm__("func_00103CC8");

extern "C" void func_001042A8(void *arg0, void *a1, char *a2, float dt) {
    float var_f13;
    void *temp_3;

    temp_3 = (*(void **)((char*)(arg0) + (0x60)));
    var_f13 = (*(float *)((char*)(temp_3) + (0x214)));
    if ((*(int *)((char*)(temp_3) + (0x320))) == 0) {
        var_f13 = -var_f13;
    }
    func_00103CC8_42A8(arg0, a1, a2, 0x24, 0x21, 0x22, dt, var_f13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001042E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00103BE0_42E0(void *, void *, int *, int, int, float, float) __asm__("func_00103BE0");

extern "C" int func_001042E0(void *arg0, void *a1, int *arg2, float f12) {
    int x = *arg2;
    if (x == 0xDA) {
        return func_00103BE0_42E0(arg0, a1, arg2, 0x16A, 0x16B, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
    }
    if (x == 0xE2) {
        return func_00103BE0_42E0(arg0, a1, arg2, 0x173, 0x174, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
    }
    if (x == 0xEA) {
        return func_00103BE0_42E0(arg0, a1, arg2, 0x17C, 0x17D, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
    }
    return func_00103BE0_42E0(arg0, a1, arg2, 0x185, 0x186, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104358);
#ifdef SKIP_ASM
// PORT: PS2 abs.s helper (stands in for fabsf).
static inline float vAbs_4358(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}
extern "C" int func_00104358(char* self, void* x, char* anim, float dt) {
    char* p = *(char**)(self + 0x60);
    float b = vAbs_4358(*(float*)(p + 0x2A4));
    float a = vAbs_4358(*(float*)(p + 0x2B0));
    float m = (a < b) ? b : a;
    func_00313CF0(anim, 0, m * *(float*)(anim + 0x10));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001043F8);
#ifdef SKIP_ASM
// PORT: PS2 abs.s helper (stands in for fabsf).
static inline float vAbs_43F8(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}
// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float clamp_43F8(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

extern "C" int func_001043F8(char* self, void* x, char* anim, float dt)
{
    int slot = 0xA5;
    switch (*(int*)anim) {
    case 0x129: slot = 0xA5; break;
    case 0x12A: slot = 0xAB; break;
    case 0x12B: slot = 0xA8; break;
    case 0x12C: slot = 0xAC; break;
    case 0x12D: slot = 0xA6; break;
    case 0x12E: slot = 0xAA; break;
    case 0x12F: slot = 0xA7; break;
    case 0x130: slot = 0xA9; break;
    }
    func_00313C50(anim, 1, *(int*)(D_004A3E7C + slot * 4 + 0x1030));
    func_00313D40(anim, 1, 1);
    char* rider = *(char**)(self + 0x60);
    float b = vAbs_43F8(*(float*)(rider + 0x298));
    float a = vAbs_43F8(*(float*)(rider + 0x28C));
    float m = (a < b) ? b : a;
    m = clamp_43F8(m, 0.0f, 1.0f);
    float w = m * 0.75f + 0.25f;
    func_00313D28(anim, 0, 1.0f - w);
    func_00313D28(anim, 1, w);
    func_00313CF0(anim, 0, m * *(float*)(anim + 0x10));
    float t = dt * 0.01666666753590107f;
    func_003135B0(anim, 1, t);
    if (func_00313800(anim, t)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001045B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00103FF8_45B8(int, int, int, int, int) __asm__("func_00103FF8");

extern "C" void func_001045B8(int a, int b, int c) {
    func_00103FF8_45B8(a, b, c, 0x89, 0x8A);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001045D8);
#ifdef SKIP_ASM
extern "C" int func_001045D8(char* self, void* x, char* anim, float dt) {
    func_00313CF0(anim, 0, *(float*)(anim + 0x10) * *(float*)(*(char**)(*(char**)(self + 0x60) + 0x77C) + 0x2A0));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104660);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00103BE0_4660(void *, void *, int *, int, int, float, float) __asm__("func_00103BE0");

extern "C" int func_00104660(void *arg0, void *arg1, int *arg2, float f12) {
    float w = (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x244)));

    if (*arg2 == 0x2D) {
        return func_00103BE0_4660(arg0, arg1, arg2, 0x161, 0x160, f12, w);
    }
    return func_00103BE0_4660(arg0, arg1, arg2, 0x15B, 0x15A, f12, w);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001046B0);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
extern "C" int func_00103CC8(void* self, void* x, char* anim, int a, int b, float dt, float w, int c);
extern "C" int func_001046B0(char* self, void* x, int* anim, float dt)
{
    float v = *(float*)(*(char**)(self + 0x60) + 0x274);
    v = v + v - 1.0f;
    float w;
    if (v >= -1.0f) {
        w = v <? 1.0f;
    } else {
        w = -1.0f;
    }
    int a, b, c;
    a = 0x3C;
    if (*anim != 0x1C) {
        b = 0x3A; c = 0x3B;
    } else {
        a = 0x31; b = 0x30; c = 0x32;
    }
    return func_00103CC8(self, x, (char*)anim, a, b, dt, w, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104728);
#ifdef SKIP_ASM
// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float clamp_4728(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}
extern "C" int func_00104728(char* self, void* x, char* anim, float dt) {
    float v;
    int s = *(int*)anim;
    if (s == 0x19 || s == 0x21) {
        v = clamp_4728(1.0f - *(float*)(*(char**)(self + 0x60) + 0x268), 0.0f, 1.0f);
    } else {
        v = *(float*)(*(char**)(self + 0x60) + 0x268);
    }
    func_00313CF0(anim, 0, v * *(float*)(anim + 0x10));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001047F0);
#ifdef SKIP_ASM
// PORT: PS2 abs.s helper (stands in for fabsf).
static inline float vAbs_47F0(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}
// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float clamp_47F0(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}
extern "C" int func_001047F0(char* self, void* x, char* anim, float dt) {
    float v;
    int s = *(int*)anim;
    if (s == 0x25) {
        v = 1.0f - vAbs_47F0(*(float*)(*(char**)(self + 0x60) + 0x280));
    } else if (s == 0x26) {
        v = 1.0f - vAbs_47F0(*(float*)(*(char**)(self + 0x60) + 0x280));
    } else {
        v = vAbs_47F0(*(float*)(*(char**)(self + 0x60) + 0x280));
    }
    func_00313CF0(anim, 0, clamp_47F0(v, 0.0f, 1.0f) * *(float*)(anim + 0x10));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001048C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003135B0_48C0(void*, int, float) __asm__("func_003135B0");
extern "C" int func_001048C0(void* self, void* x, void* anim, float dt) {
    float t = dt * 0.01666666753590107f;
    int done;
    if (func_003135B0_48C0(anim, 0, t) != 0) {
        done = 1;
    } else {
        done = func_00313800(anim, t);
    }
    if (done == 0) {
        return 0;
    }
    func_003145F8(x, anim);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104940);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003135B0_4940(void*, int, float) __asm__("func_003135B0");
extern "C" int func_00104940(void* self, void* x, void* anim, float dt) {
    float t = dt * 0.01666666753590107f;
    int done;
    if (func_003135B0_4940(anim, 0, t) != 0) {
        done = 1;
    } else {
        done = func_00313800(anim, t);
    }
    if (done == 0) {
        return 0;
    }
    func_003145F8(x, anim);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001049C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003135B0_49C0(void*, int, float) __asm__("func_003135B0");
extern "C" int func_001049C0(void* self, void* x, void* anim, float dt) {
    float t = dt * 0.01666666753590107f;
    int done;
    if (func_003135B0_49C0(anim, 0, t) != 0) {
        done = 1;
    } else {
        done = func_00313800(anim, t);
    }
    if (done == 0) {
        return 0;
    }
    func_003145F8(x, anim);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104A40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00312B18_4A40(int, int, int, int) __asm__("func_00312B18");

extern "C" void func_00104A40(int a, int b, int c) {
    func_00312B18_4A40(a, b, c, 0x11F);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104A60);
#ifdef SKIP_ASM
extern "C" int func_00312B18_4A60(void*, void*, int*, int) __asm__("func_00312B18");

// Plays the landing animation that matches the current trick state.
extern "C" int func_00104A60(void* a, void* b, int* c)
{
    switch (*c) {
    case 0x10F: case 0x11D:
        return func_00312B18_4A60(a, b, c, 0x123);
    case 0x110: case 0x118: case 0x119: case 0x11E:
        return func_00312B18_4A60(a, b, c, 0x124);
    case 0x10D: case 0x116: case 0x11B:
        return func_00312B18_4A60(a, b, c, 0x121);
    case 0x10E: case 0x117: case 0x11C:
        return func_00312B18_4A60(a, b, c, 0x122);
    case 0x111:
        return func_00312B18_4A60(a, b, c, 0x125);
    case 0x112:
        return func_00312B18_4A60(a, b, c, 0x126);
    case 0x113:
        return func_00312B18_4A60(a, b, c, 0x127);
    case 0x114:
        return func_00312B18_4A60(a, b, c, 0x128);
    }
    return 0x1B6;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104B48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00312BD0_4B48(void*, int, int, int) __asm__("func_00312BD0");

extern "C" int func_00104B48(void *arg0, int b, int c) {
    if (*(int *)((char*)arg0 + 0x64) != 0) {
        return func_00312BD0_4B48(arg0, b, c, 0x1B4);
    }
    return func_00312BD0_4B48(arg0, b, c, 0x11F);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104B78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00312B18_4B78(int, int, int, int) __asm__("func_00312B18");

extern "C" void func_00104B78(int a, int b, int c) {
    func_00312B18_4B78(a, b, c, 5);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104B98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00312B18_4B98(int, int, int, int) __asm__("func_00312B18");

extern "C" void func_00104B98(int a, int b, int c) {
    func_00312B18_4B98(a, b, c, 3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104BB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00312B18_4BB8(int, int, int, int) __asm__("func_00312B18");

extern "C" void func_00104BB8(int a, int b, int c) {
    func_00312B18_4BB8(a, b, c, 0x13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104BD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00312BD0_4BD8(void *, int, int, int) __asm__("func_00312BD0");

extern "C" int func_00104BD8(void *arg0, int a1, int a2) {
    if ((*(int *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x330))) == 1) {
        return func_00312BD0_4BD8(arg0, a1, a2, 0x1C);
    }
    return func_00312BD0_4BD8(arg0, a1, a2, 0x24);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104C18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00312BD0_4C18(int, int, int, int) __asm__("func_00312BD0");

extern "C" void func_00104C18(int a, int b, int c) {
    func_00312BD0_4C18(a, b, c, 5);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104C38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00312BD0_4C38(int, int, int*, int) __asm__("func_00312BD0");

extern "C" void func_00104C38(int a0, int a1, int *arg2) {
    int var_7;
    switch (*arg2) {
    case 0x45:
        var_7 = 0x14;
        break;
    case 0x46:
        var_7 = 0x13;
        break;
    default:
        var_7 = 0x12;
        break;
    }
    func_00312BD0_4C38(a0, a1, arg2, var_7);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104C80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00312BD0_4C80(int, int, int, int) __asm__("func_00312BD0");

extern "C" void func_00104C80(int a, int b, int c) {
    func_00312BD0_4C80(a, b, c, 0x1B2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104CA0);
#ifdef SKIP_ASM
extern "C" int func_00104CA0(int arg0, void* arg1, void* arg2) {
    func_003145F8(arg1, arg2);
    return 0x1B6;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104CC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00289B18_4CC8(int, int, int) __asm__("func_00289B18");
extern int D_004A3500;

extern "C" void func_00104CC8(void *arg0, int arg1) {
    int temp_2 = (*(int *)((char*)(arg0) + (0x60)));
    int s = arg1 & 0xFFFF;
    if (temp_2 != 0) {
        func_00289B18_4CC8(D_004A3500, temp_2, s);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104CF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00311710_4CF8(int, int, int) __asm__("func_00311710");
extern int D_004A3DFC;

extern "C" void func_00104CF8(void *arg0, int a1) {
    int var_6;
    void *temp_2;
    void *temp_4;

    temp_2 = (*(void **)((char*)(arg0) + (0x64)));
    var_6 = 0;
    if (temp_2 != 0) {
        var_6 = (*(int *)((char*)(temp_2) + (0xCD8)));
    } else {
        temp_4 = (*(void **)((char*)(arg0) + (0x60)));
        if (temp_4 != 0) {
            var_6 = (*(int *)((char*)(temp_4) + (0x364)));
        }
    }
    func_00311710_4CF8(D_004A3DFC, a1, var_6);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104D38);
#ifdef SKIP_ASM
extern "C" void func_00104D38(void *arg0, void *arg1) {
    (*(int *)((char*)(arg0) + (0x64))) = 0;
    (*(void **)((char*)(arg0) + (0x60))) = arg1;
    (*(int *)((char*)(arg0) + (0x54))) = (int) (*(int *)((char*)(arg1) + (0x780)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104D50);
#ifdef SKIP_ASM
extern "C" void func_00104D50(void *arg0, void *arg1) {
    (*(void **)((char*)(arg0) + (0x64))) = arg1;
    (*(int *)((char*)(arg0) + (0x60))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = (int) (*(int *)((char*)(arg1) + (8)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104D68);
#ifdef SKIP_ASM
class cStream_4D68 {
public:
    virtual void Read(void* dst, int n);
};
extern "C" void func_003147F0(void*, cStream_4D68*);
extern "C" void func_00104D68(char* self, cStream_4D68* s) {
    s->Read(self, 0x50);
    for (int i = 0; i < 6; i++) {
        func_003147F0(*(char**)(self + 0x50) + i * 8, s);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104DE0);
#ifdef SKIP_ASM
class cStream_4DE0 {
public:
    virtual void v0();
    virtual void Read(void* dst, int n);
};
extern "C" void func_00314668(void*);
extern "C" void func_00314880(void*, cStream_4DE0*);
extern "C" void func_00104DE0(char* self, cStream_4DE0* s) {
    s->Read(self, 0x50);
    for (int i = 0; i < 6; i++) {
        func_00314668(*(char**)(self + 0x50) + i * 8);
        func_00314880(*(char**)(self + 0x50) + i * 8, s);
    }
}
#endif

INCLUDE_ASM("seg/seg_1218", func_00104E70);

INCLUDE_ASM("seg/seg_1218", func_00105398);

INCLUDE_ASM("seg/seg_1218", func_001057B8);

INCLUDE_ASM("seg/seg_1218", func_00105D98);

//100%
INCLUDE_ASM("seg/seg_1218", func_00106538);
#ifdef SKIP_ASM
struct sV4_6538 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (a += b).
static inline void AddEq_6538(sV4_6538& a, const sV4_6538& b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}

extern "C" void func_00329B40(void* p, const sV4_6538* d);

extern "C" void func_00106538(char* self, const sV4_6538* d)
{
    AddEq_6538(*(sV4_6538*)(self + 0x110), *d);
    AddEq_6538(*(sV4_6538*)(self + 0x9D0), *d);
    func_00329B40(*(void**)(self + 0xAA0), d);
    AddEq_6538(*(sV4_6538*)(self + 0x400), *d);
    AddEq_6538(*(sV4_6538*)(self + 0x410), *d);
}
#endif

INCLUDE_ASM("seg/seg_1218", func_001065B0);

//100%
INCLUDE_ASM("seg/seg_1218", func_00106828);
#ifdef SKIP_ASM
extern "C" void func_00329AE0(int);

extern "C" void func_00106828(void *arg0) {
    func_00329AE0((*(int *)((char*)(arg0) + (0xAA0))));
}
#endif

INCLUDE_ASM("seg/seg_1218", func_00106848);

INCLUDE_ASM("seg/seg_1218", func_00106F78);

INCLUDE_ASM("seg/seg_1218", func_00107578);

INCLUDE_ASM("seg/seg_1218", func_00107888);

//100%
INCLUDE_ASM("seg/seg_1218", func_00107E70);
#ifdef SKIP_ASM
struct sV4_7E70 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sInfo_7E70 {
    sV4_7E70 pos;
    sV4_7E70 dir;
    sV4_7E70 normal;
    float speed;
} __attribute__((aligned(16)));

struct sRec_7E70 {
    int active;
    int pad4;
    float dist;
    float angle;
    char pad10[0x24 - 0x10];
};

class cAI_7E70 {
public:
    virtual void vm1();
    virtual sV4_7E70* GetDir();
    virtual void v1();
    virtual void v2();
    virtual sV4_7E70* GetPos();
};

int func_0011FEE8_7E70(void*) __asm__("func_0011FEE8__FPv");
int func_0011FE98(void*);
int AIrand();
extern "C" int func_001231A8(void*);
extern "C" void cAirPredictor_startLaunchIntoAir(void*, sV4_7E70*, sV4_7E70*, float);
extern "C" void func_0010EB30_7E70(char*, int, int, int, sInfo_7E70*) __asm__("func_0010EB30");
extern "C" void func_00108388_7E70(char*, sInfo_7E70*, int) __asm__("func_00108388");
extern "C" void func_0010E468(void*, void*);
extern "C" void func_0010E2E8(void*, void*);
extern "C" void func_0010E3A8(void*, void*);
extern "C" void func_0010E228(void*, void*);
extern float D_004A4C84_7E70 __asm__("D_004A4C84");
extern int D_005308D0_7E70[] __asm__("D_005308D0");

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_7E70(const sV4_7E70& a, const sV4_7E70& b)
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
static inline float Len_7E70(const sV4_7E70& v)
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

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_7E70 Add_7E70(const sV4_7E70& a, const sV4_7E70& b)
{
    sV4_7E70 r;
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
static inline void AddEq_7E70(sV4_7E70& a, const sV4_7E70& b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sV4_7E70 Sub_7E70(const sV4_7E70& a, const sV4_7E70& b)
{
    sV4_7E70 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_7E70 Scale_7E70(const sV4_7E70& v, float s)
{
    sV4_7E70 r;
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sV4_7E70 Norm_7E70(const sV4_7E70& v)
{
    sV4_7E70 r;
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
static inline float Abs_7E70(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float Clamp_7E70(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

static inline sV4_7E70 Get_7E70(char* p) { return *(sV4_7E70*)p; }

extern "C" void func_00107E70(char* self, char* other, sV4_7E70* n, int flag, float speed)
{
    if (func_0011FEE8_7E70(self) == 10)
        return;
    float absSpd = Abs_7E70(speed);
    float lim = 555.5555419921875f;
    float s = Clamp_7E70(speed, -lim, lim);
    sV4_7E70 imp = Scale_7E70(*n, s);
    if (func_001231A8(self)) {
        AddEq_7E70(*(sV4_7E70*)(self + 0x1E0),
                   Sub_7E70(imp, Scale_7E70(*(sV4_7E70*)(self + 0x370), Dot_7E70(imp, *(sV4_7E70*)(self + 0x370)))));
    } else {
        AddEq_7E70(*(sV4_7E70*)(self + 0x1E0), imp);
        if (func_0011FE98(self) == 1 || (func_0011FE98(self) == 2 && *(int*)(*(char**)(self + 0x77C) + 0x30) == 1)) {
            cAI_7E70* ai = (cAI_7E70*)(self + 0x6C0);
            sV4_7E70* pos = ai->GetPos();
            cAirPredictor_startLaunchIntoAir(*(void**)(self + 0x788), pos, ai->GetDir(), *(float*)(self + 0x2E4));
            if (Dot_7E70(*n, Get_7E70(self + 0x1C0)) * s > 0.0f)
                absSpd = 0.0f;
        }
    }
    if (func_0011FE98(self) == 2)
        return;
    if (func_0011FEE8_7E70(self) == 9)
        return;
    if (absSpd < 39.99532699584961f)
        return;
    float r = ((sRec_7E70*)self)[*(int*)(other + 0x86C)].dist;
    sInfo_7E70 info;
    info.pos = Add_7E70(*(sV4_7E70*)(self + 0x110), Scale_7E70(*n, r));
    info.dir = Norm_7E70(*(sV4_7E70*)(self + 0x1E0));
    info.normal = *n;
    info.speed = s;
    if ((D_005308D0_7E70[0] >> 5) & 1)
        absSpd = 599.9739990234375f;
    if (absSpd > 599.9739990234375f) {
        float dz = Dot_7E70(Get_7E70(self + 0x160), *n);
        float dy = Dot_7E70(Get_7E70(self + 0x170), *n);
        float dx = Dot_7E70(Get_7E70(self + 0x180), *n);
        int anim;
        if (Abs_7E70(dz) < Abs_7E70(dy) && Abs_7E70(dx) < Abs_7E70(dy)) {
            if (dy < 0.0f) {
                unsigned int k;
                if (Len_7E70(*(sV4_7E70*)(self + 0x1E0)) > D_004A4C84_7E70)
                    k = (unsigned int)AIrand() % 6;
                else
                    k = (unsigned int)AIrand() % 3;
                if (k == 0)
                    anim = 0x14E;
                else if (k == 1)
                    anim = 0x14F;
                else if (k == 2)
                    anim = 0x151;
                else if (k == 3)
                    anim = 0x14D;
                else
                    anim = 0x150;
            } else {
                anim = (AIrand() & 1) == 0 ? 0x14A : 0x14B;
            }
        } else if (Abs_7E70(dz) < Abs_7E70(dx) && Abs_7E70(dy) < Abs_7E70(dx)) {
            anim = 0x14B;
        } else if (dz < 0.0f) {
            anim = 0x149;
        } else {
            anim = 0x148;
        }
        func_0010EB30_7E70(self, anim, flag, 0, &info);
        if (flag)
            func_0010E468(self, other);
        else
            func_0010E2E8(self, other);
    } else {
        func_00108388_7E70(self, &info, 0);
        if (flag)
            func_0010E3A8(self, other);
        else
            func_0010E228(self, other);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108388);
#ifdef SKIP_ASM
struct sV4_8388
{
    float x, y, z, w;
} __attribute__((aligned(16)));

int func_0011FE98(void*);
int func_0011FEE8_8388(void*) __asm__("func_0011FEE8__FPv");
void func_0011FEC8_8388(void* self, int v) __asm__("func_0011FEC8__FPv");
int AIrand();
extern "C" void func_00131348(void*);
extern "C" void cRiderAnimBase_play(void*, int, int, float);
extern "C" void* func_0028B180();
extern "C" void func_002A0E70(void*, void*, int);

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len_8388(const sV4_8388& v)
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
static inline float Dot_8388(const sV4_8388& a, const sV4_8388& b)
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

// PORT: PS2-only FPU asm (absolute value).
static inline float Abs_8388(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline sV4_8388 Get_8388(char* p) { return *(sV4_8388*)p; }

extern "C" void func_00108388(char* self, char* info, int flag)
{
    if (func_0011FE98(self) != 0 && func_0011FE98(self) != 4)
        return;
    if (func_0011FEE8_8388(self) == 1) {
        func_00131348(*(char**)(self + 0x77C) + 0x1D0);
    } else if (func_0011FEE8_8388(self) != 0 && func_0011FEE8_8388(self) != 2 && func_0011FEE8_8388(self) != 7) {
        return;
    }
    int played = 0;
    float d = Dot_8388(Get_8388(self + 0x1B0), *(sV4_8388*)(info + 0x20));
    if (d > 0.7071067690849304f) {
        cRiderAnimBase_play(*(void**)(self + 0x784), 0x37, 0, -1.0f);
    } else if (d < -0.7071067690849304f) {
        cRiderAnimBase_play(*(void**)(self + 0x784), 0x38, 0, -1.0f);
    } else {
        float side = Dot_8388(Get_8388(self + 0x1A0), *(sV4_8388*)(info + 0x20));
        if (*(int*)(self + 0x320))
            side = -side;
        if (*(float*)(info + 0x30) < 1111.111083984375f && Len_8388(*(sV4_8388*)(self + 0x1E0)) > 1388.888916015625f &&
            func_0011FE98(self) != 4) {
            float a = *(float*)(self + 0x2DC);
            if (Abs_8388(a) < 6.2831854820251465f) {
                if (a < 0.0f)
                    *(float*)(self + 0x2DC) += (int)((unsigned int)AIrand() % 3) * -3.1415927410125732f;
                else if (a > 0.0f)
                    *(float*)(self + 0x2DC) += (int)((unsigned int)AIrand() % 3) * 3.1415927410125732f;
                else
                    *(float*)(self + 0x2DC) += ((int)((unsigned int)AIrand() % 5) - 2) * 3.1415927410125732f;
            }
            cRiderAnimBase_play(*(void**)(self + 0x784), side < 0.0f ? 0x3A : 0x3C, 0, -1.0f);
            played = 1;
        } else {
            cRiderAnimBase_play(*(void**)(self + 0x784), side < 0.0f ? 0x39 : 0x3B, 0, -1.0f);
        }
    }
    if (flag)
        func_002A0E70(func_0028B180(), self, played);
    func_0011FEC8_8388(self, 3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001086B8);
#ifdef SKIP_ASM
struct sV4_86B8
{
    float x, y, z, w;
    sV4_86B8() {}
    sV4_86B8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sNode_86B8 {
    sV4_86B8 pos;
    float qx, qy, qz, qw;
};

struct sPath_86B8 {
    char pad[0x2C];
    sNode_86B8* nodes;
};

struct sHit_86B8 {
    sV4_86B8 pos;
    char pad[0x80 - 0x10];
};

extern "C" int func_00334680_86B8(void*, sV4_86B8*, sV4_86B8*, int, float) __asm__("func_00334680");

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV4_86B8 Add_86B8(const sV4_86B8& a, const sV4_86B8& b)
{
    sV4_86B8 r;
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
static inline sV4_86B8 Sub_86B8(const sV4_86B8& a, const sV4_86B8& b)
{
    sV4_86B8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_86B8 Scale_86B8(const sV4_86B8& v, float s)
{
    sV4_86B8 r;
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

// PORT: PS2-only VU0 inline asm (vector divided by scalar).
static inline sV4_86B8 Div_86B8(const sV4_86B8& v, float s)
{
    sV4_86B8 r;
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
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len_86B8(const sV4_86B8& v)
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
static inline float Dot_86B8(const sV4_86B8& a, const sV4_86B8& b)
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

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float Clamp_86B8(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

static inline float Lerp_86B8(float a, float b, float t)
{
    return t * a + (1.0f - t) * b;
}

static inline sV4_86B8 Fwd_86B8(const sNode_86B8* n)
{
    return sV4_86B8(1.0f - (n->qy * n->qy + n->qz * n->qz) * 2.0f,
                    (n->qx * n->qy + n->qw * n->qz) * 2.0f,
                    (n->qx * n->qz - n->qw * n->qy) * 2.0f,
                    0.0f);
}

extern "C" int func_001086B8_86B8(char* self, sV4_86B8* tgt, sV4_86B8* dir) __asm__("func_001086B8");
extern "C" int func_001086B8_86B8(char* self, sV4_86B8* tgt, sV4_86B8* dir)
{
    sNode_86B8* n = &(*(sPath_86B8**)(self + 0x780))->nodes[*(int*)(self + 0x8A0)];
    const sV4_86B8& fwd = Fwd_86B8(n);
    sV4_86B8 pos = Add_86B8(n->pos, *(sV4_86B8*)(self + 0x9D0));
    float t = *(float*)(self + 0x25C);
    float nearR = Lerp_86B8(50.0f, 30.0f, t);
    float farR;
    if (!*(int*)(self + 0x330))
        farR = Lerp_86B8(170.0f, 100.0f, t);
    else
        farR = Lerp_86B8(170.0f, 50.0f, t);
    float proj = Dot_86B8(fwd, Sub_86B8(*tgt, pos));
    float lo = nearR - farR;
    float hi = farR - nearR;
    sV4_86B8 d = Sub_86B8(Add_86B8(pos, Scale_86B8(fwd, Clamp_86B8(proj, lo, hi))), *tgt);
    if (Len_86B8(d) <= nearR)
        return 1;
    float dd = Dot_86B8(*dir, fwd);
    float den = 1.0f - dd * dd;
    if (den < 0.0010000000474974513f)
        return 0;
    sV4_86B8 b = Div_86B8(Sub_86B8(pos, *tgt), den);
    float u = Dot_86B8(b, Sub_86B8(Scale_86B8(*dir, dd), fwd));
    sV4_86B8 p = Add_86B8(pos, Scale_86B8(fwd, Clamp_86B8(u, lo, hi)));
    sHit_86B8 hit;
    if (!func_00334680_86B8(*(void**)(self + 0x860), &p, &hit.pos, 1, 300.0f))
        return 0;
    d = Sub_86B8(p, hit.pos);
    return Len_86B8(d) <= nearR;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_00108A48);
#ifdef SKIP_ASM
struct sVec4_8A48 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sNode_8A48 {
    sVec4_8A48 pos;
    char pad[0x10];
};

struct sPath_8A48 {
    char pad[0x2C];
    sNode_8A48* nodes;
};

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec4_8A48 vAdd_8A48(const sVec4_8A48& a, const sVec4_8A48& b)
{
    sVec4_8A48 r;
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
static inline sVec4_8A48 vSub_8A48(const sVec4_8A48& a, const sVec4_8A48& b)
{
    sVec4_8A48 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_8A48(const sVec4_8A48& v)
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
static inline float vDot_8A48(const sVec4_8A48& a, const sVec4_8A48& b)
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

int func_0011FE98(void*);
extern "C" int func_00334680(void*, sVec4_8A48*, sVec4_8A48*, int, float);
extern "C" int func_00311AE8(void*, int);
extern "C" char* func_00311B20(void*, int);
extern "C" int func_001446A0(void*, int);
extern "C" int func_001086B8(void*, sVec4_8A48*, sVec4_8A48*);

extern "C" int func_00108A48(char* self, sVec4_8A48* tgt)
{
    if (func_0011FE98(self) != 0 && func_0011FE98(self) != 1)
        return 0;
    sVec4_8A48 p = vAdd_8A48(*(sVec4_8A48*)((char*)(*(sPath_8A48**)(self + 0x780))->nodes + (*(int*)(self + 0x8A0) << 5)),
                             *(sVec4_8A48*)(self + 0x9D0));
    if (!func_00334680(*(void**)(self + 0x860), &p, tgt, 1, 300.0f))
        return 0;
    float spd = vLen_8A48(*(sVec4_8A48*)(self + 0x1E0));
    if (0.001f < spd) {
        sVec4_8A48 d = vSub_8A48(*tgt, p);
        if (vDot_8A48(d, *(sVec4_8A48*)(self + 0x1E0)) < spd * -0.20000000298023224f)
            return 0;
    }
    if (func_00311AE8(*(void**)(self + 0x784), 2) == 0x12) {
        if (!func_001446A0(func_00311B20(*(void**)(self + 0x784), 2) + 0xB0, 2) &&
            func_001446A0(func_00311B20(*(void**)(self + 0x784), 2) + 0xB0, 0))
            return 0;
    } else if (func_00311AE8(*(void**)(self + 0x784), 2) == 0x13 ||
               func_00311AE8(*(void**)(self + 0x784), 2) == 0x14) {
        if (!func_001446A0(func_00311B20(*(void**)(self + 0x784), 2) + 0xB0, 2))
            return 0;
    }
    return func_001086B8(self, tgt, tgt + 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108C28);
#ifdef SKIP_ASM
struct S_8C28 { char pad[0x5B8]; unsigned arr[64]; };
extern "C" int func_00108C28(S_8C28 *arg0, void *arg1) {
    int i = 0;
    if (~arg0->arr[0]) {
        do {
            if (arg0->arr[i] == *(unsigned *)((char*)arg1 + 0x78)) {
                return 1;
            }
            i++;
        } while (i < 64 && arg0->arr[i] != 0xFFFFFFFF);
    }
    return 0;
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_s12 {
public:
    virtual ~cRiderVbA0_s12();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_s12 : public cRiderVbA0_s12 { public: char padA[0xC]; };
class cRiderVbB0_s12 { public: virtual void b01(); };
class cRiderVbB_s12 : public cRiderVbB0_s12 { public: char padB[0x14]; };
class cRiderVbC0_s12 {
public:
    virtual ~cRiderVbC0_s12();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_s12 : public cRiderVbC0_s12 { public: char padC[0x10]; };
class cRiderVbBC_s12 : public cRiderVbB_s12, public cRiderVbC_s12 { public: };
class cRiderVbPad_s12 { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_s12 : public cRiderVbPad_s12, public cRiderVbA_s12, public cRiderVbBC_s12 {
public:
    cRiderVb_s12();
    virtual ~cRiderVb_s12();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108C80);
#ifdef SKIP_ASM
// PORT: the rider class below derives from a composite of 31 parts that each derive virtually from cRider;
// only the parts' vbase-pointer offsets (and the composite's vptr at 0xDE8) matter to this ctor.
struct cCompHead00_s12 { char pad[0x18]; };
class cCompPart00_s12 : public cCompHead00_s12, virtual public cRiderVb_s12 { };
struct cCompHead01_s12 { char pad[0x4]; };
class cCompPart01_s12 : public cCompHead01_s12, virtual public cRiderVb_s12 { };
struct cCompHead02_s12 { char pad[0x40]; };
class cCompPart02_s12 : public cCompHead02_s12, virtual public cRiderVb_s12 { };
struct cCompHead03_s12 { char pad[0x20]; };
class cCompPart03_s12 : public cCompHead03_s12, virtual public cRiderVb_s12 { };
struct cCompHead04_s12 { char pad[0x50]; };
class cCompPart04_s12 : public cCompHead04_s12, virtual public cRiderVb_s12 { };
struct cCompHead05_s12 { char pad[0xA0]; };
class cCompPart05_s12 : public cCompHead05_s12, virtual public cRiderVb_s12 { };
class cCompPart06_s12 : virtual public cRiderVb_s12 { };
struct cCompHead07_s12 { char pad[0x14]; };
class cCompPart07_s12 : public cCompHead07_s12, virtual public cRiderVb_s12 { };
class cCompPart08_s12 : virtual public cRiderVb_s12 { };
class cCompPart09_s12 : virtual public cRiderVb_s12 { };
struct cCompHead10_s12 { char pad[0x14]; };
class cCompPart10_s12 : public cCompHead10_s12, virtual public cRiderVb_s12 { };
struct cCompHead11_s12 { char pad[0x58]; };
class cCompPart11_s12 : public cCompHead11_s12, virtual public cRiderVb_s12 { };
struct cCompHead12_s12 { char pad[0x14]; };
class cCompPart12_s12 : public cCompHead12_s12, virtual public cRiderVb_s12 { };
struct cCompHead13_s12 { char pad[0x8]; };
class cCompPart13_s12 : public cCompHead13_s12, virtual public cRiderVb_s12 { };
struct cCompHead14_s12 { char pad[0x80]; };
class cCompPart14_s12 : public cCompHead14_s12, virtual public cRiderVb_s12 { };
struct cCompHead15_s12 { char pad[0x8]; };
class cCompPart15_s12 : public cCompHead15_s12, virtual public cRiderVb_s12 { };
struct cCompHead16_s12 { char pad[0x4]; };
class cCompPart16_s12 : public cCompHead16_s12, virtual public cRiderVb_s12 { };
struct cCompHead17_s12 { char pad[0x14]; };
class cCompPart17_s12 : public cCompHead17_s12, virtual public cRiderVb_s12 { };
struct cCompHead18_s12 { char pad[0x8]; };
class cCompPart18_s12 : public cCompHead18_s12, virtual public cRiderVb_s12 { };
class cCompPart19_s12 : virtual public cRiderVb_s12 { };
class cCompPart20_s12 : virtual public cRiderVb_s12 { };
struct cCompHead21_s12 { char pad[0xB0]; };
class cCompPart21_s12 : public cCompHead21_s12, virtual public cRiderVb_s12 { };
struct cCompHead22_s12 { char pad[0xA0]; };
class cCompPart22_s12 : public cCompHead22_s12, virtual public cRiderVb_s12 { };
struct cCompHead23_s12 { char pad[0xE0]; };
class cCompPart23_s12 : public cCompHead23_s12, virtual public cRiderVb_s12 { };
struct cCompHead24_s12 { char pad[0x3A0]; };
class cCompPart24_s12 : public cCompHead24_s12, virtual public cRiderVb_s12 { };
struct cCompHead25_s12 { char pad[0x100]; };
class cCompPart25_s12 : public cCompHead25_s12, virtual public cRiderVb_s12 { };
struct cCompHead26_s12 { char pad[0x10]; };
class cCompPart26_s12 : public cCompHead26_s12, virtual public cRiderVb_s12 { };
class cCompPart27_s12 : virtual public cRiderVb_s12 { };
struct cCompHead28_s12 { char pad[0x30]; };
class cCompPart28_s12 : public cCompHead28_s12, virtual public cRiderVb_s12 { };
struct cCompHead29_s12 { char pad[0x120]; };
class cCompPart29_s12 : public cCompHead29_s12, virtual public cRiderVb_s12 { };
struct cCompHead30_s12 { char pad[0xA0]; };
class cCompPart30_s12 : public cCompHead30_s12, virtual public cRiderVb_s12 { };
class cComp_s12 : public cCompPart00_s12, public cCompPart01_s12, public cCompPart02_s12, public cCompPart03_s12, public cCompPart04_s12, public cCompPart05_s12, public cCompPart06_s12, public cCompPart07_s12, public cCompPart08_s12, public cCompPart09_s12, public cCompPart10_s12, public cCompPart11_s12, public cCompPart12_s12, public cCompPart13_s12, public cCompPart14_s12, public cCompPart15_s12, public cCompPart16_s12, public cCompPart17_s12, public cCompPart18_s12, public cCompPart19_s12, public cCompPart20_s12, public cCompPart21_s12, public cCompPart22_s12, public cCompPart23_s12, public cCompPart24_s12, public cCompPart25_s12, public cCompPart26_s12, public cCompPart27_s12, public cCompPart28_s12, public cCompPart29_s12, public cCompPart30_s12 {
public:
    char tail[0xC4];
    // PORT: func_0010FCD8 constructs this part (fields up to 0xDE8 and the vptr at 0xDE8)
    cComp_s12();
    virtual void v01();
};
// PORT: func_00108E88 takes the rider; declared elsewhere in this file without parameters
void func_00108E88_self(void* self) __asm__("func_00108E88");

class cRiderE_108C80 : public cComp_s12 {
public:
    char tail[0x160];
    cRiderE_108C80(int flag);
    virtual ~cRiderE_108C80();
    virtual void a19();
};

cRiderE_108C80::cRiderE_108C80(int flag)
{
    if (flag)
        *(int*)((char*)(cRiderVb_s12*)this + 0x878) = 1;
    func_00108E88_self(this);
}
// PORT: the compiler names this ctor __14cRiderE_108C80ii; expose it under the address-derived name.
__asm__(".globl func_00108C80\n.type func_00108C80,@function\nfunc_00108C80 = __14cRiderE_108C80ii\n.size func_00108C80,0x208\n");
#endif

INCLUDE_ASM("seg/seg_1218", func_00108E88);

//100%
INCLUDE_ASM("seg/seg_1218", func_00108F88);
#ifdef SKIP_ASM
extern "C" void func_00108E88();

extern "C" void func_00108F88(void) {
    func_00108E88();
}
#endif

INCLUDE_ASM("seg/seg_1218", func_00108FA8);

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A768);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);
extern "C" float func_0010DEF0(void* self);
extern "C" void func_00120090(void* self, float v);
int func_0011FEE8_A768(void*) __asm__("func_0011FEE8__FPv");
extern "C" void func_0010A960_A768(void* self, void* pad) __asm__("func_0010A960");
extern "C" void func_0010AA70_A768(void* self, void* pad) __asm__("func_0010AA70");
extern "C" void func_0010B790_A768(void* self, void* pad) __asm__("func_0010B790");
extern "C" void func_0010B590_A768(void* self, void* pad) __asm__("func_0010B590");
extern "C" void func_0010AED8_A768(void* self, void* pad) __asm__("func_0010AED8");
extern "C" void func_0010B250_A768(void* self, void* pad) __asm__("func_0010B250");
extern "C" void func_0010B750_A768(void* self, void* pad) __asm__("func_0010B750");
extern "C" void func_0010AD78_A768(void* self, void* pad) __asm__("func_0010AD78");

// Clears the pad input, updates the rider, then runs the input handler for the rider state.
extern "C" void func_0010A768(char* self, void* pad)
{
    func_003E6448(pad, 0, 8);
    func_00120090(*(void**)(self + 0x18), func_0010DEF0(self));
    int state = func_0011FEE8_A768(*(void**)(self + 0x18));
    switch (state) {
    case 0:
        func_0010A960_A768(self, pad);
        break;
    case 2:
        func_0010AA70_A768(self, pad);
        break;
    case 6:
        func_0010B790_A768(self, pad);
        break;
    case 4:
        func_0010B590_A768(self, pad);
        break;
    case 7:
        func_0010AED8_A768(self, pad);
        break;
    case 5:
        func_0010B250_A768(self, pad);
        break;
    case 8:
        func_0010B750_A768(self, pad);
        break;
    case 1:
        func_0010AD78_A768(self, pad);
        break;
    case 3: case 9: case 10: case 11: case 12: case 13:
        break;
    }
    if (state != 5) {
        *(int*)(self + 0xE34) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A898);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00111AC0_A898(char*, void*) __asm__("func_00111AC0");

struct C_A898 {
    virtual void m0(char*, int);
};

extern "C" void func_0010A898(char *arg0, C_A898 *arg1) {
    func_00111AC0_A898(arg0, arg1);
    arg1->m0(arg0 + 0xDF0, 0x150);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A8E8);
#ifdef SKIP_ASM
class cObj_A8E8;
typedef void (cObj_A8E8::*Fn_A8E8)();
extern "C" Fn_A8E8 D_0043CF20_A8E8[4] __asm__("D_0043CF20");
extern "C" void func_00111D98(void* self, void* src);

class cStream_A8E8 {
public:
    virtual void v1();
    virtual void read(void* dst, int size);
};

extern "C" void func_0010A8E8(char* self, cStream_A8E8* in)
{
    func_00111D98(self, in);
    in->read(self + 0xDF0, 0x150);
    short state = *(short*)(self + 0xF38);
    *(Fn_A8E8*)(self + 0xF44) = D_0043CF20_A8E8[state];
    *(short*)(self + 0xF38) = state;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A960);
#ifdef SKIP_ASM
struct sFlags_A960 {
    unsigned int pad0 : 12;
    unsigned int b12 : 1;
    unsigned int pad13 : 5;
    unsigned int b18 : 1;
    unsigned int b19 : 1;
};

class cObj_A960;
typedef void (cObj_A960::*Fn_A960)(sFlags_A960*);

class cObj_A960 {
public:
    virtual void v0();
    char pad[0xE20];
    int fE20;
    char padE24[0xF44 - 0xE24];
    Fn_A960 state;
};

extern "C" int func_0010D1A0(void*);
extern "C" int func_0010DA10(void*);
extern "C" int func_0010DBF0(void*, int*);

extern "C" void func_0010A960(cObj_A960* self, sFlags_A960* f)
{
    int t;
    f->b12 = func_0010D1A0(self);
    self->fE20 = 0;
    if (func_0010DBF0(self, &t)) {
        if (t)
            f->b19 = 1;
        else
            f->b18 = 1;
    } else if (func_0010DA10(self)) {
        f->b19 = 1;
        f->b18 = 1;
    }
    (self->*(self->state))(f);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010AA70);
#ifdef SKIP_ASM
struct sV4_AA70
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRec_AA70 {
    int type;
    int flags;
    float a;
    float b;
};

class cTrack_AA70 {
public:
    char pad[0x34];
    virtual int Query(sRec_AA70* buf, int max, float x, float y);
};

struct sPad_AA70 {
    unsigned int pad0 : 13;
    unsigned int b13 : 1;
    unsigned int b14 : 1;
    int b15 : 6;
    int b21 : 6;
    unsigned int pad27 : 5;
    int w0 : 6;
};

extern "C" sV4_AA70 func_0026AB20_AA70(cTrack_AA70*, int, float) __asm__("func_0026AB20");
extern "C" float func_00100348_AA70(void*, sV4_AA70*) __asm__("func_00100348");

// PORT: PS2-only VU0 inline asm (vector length via vsqrt).
static inline float Len_AA70(const sV4_AA70& v)
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
static inline sV4_AA70 Sub_AA70(const sV4_AA70& a, const sV4_AA70& b)
{
    sV4_AA70 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV4_AA70 Scale_AA70(const sV4_AA70& v, float s)
{
    sV4_AA70 r;
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

extern "C" void func_0010AA70(char* self, sPad_AA70* pad)
{
    sRec_AA70 buf[12];
    char* rider = *(char**)(self + 0x18);
    cTrack_AA70* trk = *(cTrack_AA70**)(rider + 0xAB8);
    int n = trk->Query(buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 50.0f);
    int sel = -1;
    if (Len_AA70(*(sV4_AA70*)(*(char**)(self + 0x18) + 0x1E0)) < *(float*)(self + 0xDF0) - 138.88890075683594f)
        pad->b14 = 1;
    if (*(int*)(self + 0xE1C)) {
        sV4_AA70 a = Sub_AA70(*(sV4_AA70*)(self + 0xE60), *(sV4_AA70*)(self + 0xE50));
        sV4_AA70 b = Sub_AA70(*(sV4_AA70*)(*(char**)(self + 0x18) + 0x110), *(sV4_AA70*)(self + 0xE50));
        if (Len_AA70(b) < Len_AA70(a) - 50.0f)
            pad->b13 = 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x10) {
            sel = i;
            pad->b13 = 1;
            break;
        }
    }
    float* ctl = (float*)(self + 0xDF0);
    if (sel != -1) {
        char* r = *(char**)(self + 0x18);
        sV4_AA70 half = Sub_AA70(*(sV4_AA70*)(r + 0x490), *(sV4_AA70*)(r + 0x110));
        half = Scale_AA70(half, 0.5f);
        sV4_AA70 pos = func_0026AB20_AA70(trk, 0, buf[sel].b);
        sV4_AA70 d = Sub_AA70(pos, half);
        pad->w0 = (int)(func_00100348_AA70(self, &d) * 31.0f);
    }
    pad->b15 = (int)(ctl[0x12] * 31.0f);
    pad->b21 = (int)(ctl[0x13] * 31.0f);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_0010AD78);
#ifdef SKIP_ASM
struct sVec4_AD78 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPad_AD78 {
    unsigned int pad0 : 18;
    int b18 : 6;
    int b24 : 6;
    unsigned int pad30 : 2;
    int w0 : 6;
};

extern "C" int func_0010BBF8(void*, int*);
extern "C" void func_00100610(sVec4_AD78*, void*);
extern "C" float func_00100348(void*, sVec4_AD78*);

// PORT: PS2 abs.s helper (stands in for fabsf).
static inline float vAbs_AD78(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float clamp_AD78(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

extern "C" void func_0010AD78(char* self, sPad_AD78* pad)
{
    int flag;
    int r = func_0010BBF8(self, &flag);
    float s = 1.0f;
    if (flag)
        s = -1.0f;
    {
        sVec4_AD78 v;
        func_00100610(&v, self);
        pad->b18 = (int)(func_00100348(self, &v) * 31.0f);
    }
    if (r) {
        pad->w0 = (int)(s * 31.0f);
        sVec4_AD78 p = *(sVec4_AD78*)(*(char**)(self + 0x18) + 0x1A0);
        float z = p.z + p.z;
        float y = clamp_AD78(z, -1.0f, 1.0f);
        if (vAbs_AD78(y) > 0.1f)
            pad->b24 = (int)(y * 31.0f);
    } else {
        pad->w0 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010AED8);
#ifdef SKIP_ASM
struct sVec4_AED8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPad_AED8 {
    unsigned int pad0 : 25;
    int b25 : 6;
    unsigned int pad31 : 1;
    int w0 : 6;
};

extern "C" int func_0010B980(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6);
extern "C" void func_0010BFA8_AED8(char*, int, int, int, int) __asm__("func_0010BFA8");
extern "C" int func_00311AE8(void*, int);
extern "C" int func_0010BB18(void*, float*, int*);

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_AED8(const sVec4_AED8& v)
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

// PORT: PS2 abs.s helper (stands in for fabsf).
static inline float vAbs_AED8(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float clamp_AED8(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

extern "C" void func_0010AED8(char* self, sPad_AED8* pad)
{
    int below, o3, o4, o5, o6, ok;
    int r = func_0010B980(self, (float*)(self + 0xDF0), &below, &o3, &o4, &o5, &o6);
    *(int*)(self + 0xE20) = o4;
    *(unsigned int*)pad |= 0x1FE0000;
    if (r && below) {
        *(unsigned int*)pad |= 0x6000;
        func_0010BFA8_AED8(self, o5, o6, o4, o3);
        return;
    }
    sVec4_AED8 p = *(sVec4_AED8*)(*(char**)(self + 0x18) + 0x1A0);
    float z = p.z + p.z;
    float y = clamp_AED8(z, -1.0f, 1.0f);
    if (vAbs_AED8(y) > 0.1f)
        pad->b25 = (int)(y * 31.0f);
    char* rider = *(char**)(self + 0x18);
    if ((unsigned int)(*(int*)(rider + 0x328) - 3) >= 2 &&
        func_00311AE8(*(void**)(rider + 0x784), 2) != 0xE) {
        float s = (*(float*)(self + 0xE38) < 0.0f) ? 1.0f : -1.0f;
        pad->w0 = (int)(s * 31.0f);
    }
    int r2 = func_0010BB18(self, (float*)(self + 0xDF0), &ok);
    float len = vLen_AED8(*(sVec4_AED8*)(*(char**)(self + 0x18) + 0x1E0));
    if (r2 && ok && len < *(float*)(self + 0xDF0) - 138.88890075683594f)
        *(unsigned int*)pad |= 0x10000;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B0E8);
#ifdef SKIP_ASM
extern "C" void func_00135CB0(void*, float*, float*);
extern "C" void func_00135DB0(void*, float*, float*);

extern "C" void func_0010B0E8(char* self, float t)
{
    float a, b, c, d;
    func_00135CB0(*(char**)(*(char**)(self + 0x18) + 0x77C) + 0x230, &a, &b);
    func_00135DB0(*(char**)(*(char**)(self + 0x18) + 0x77C) + 0x230, &c, &d);
    int stop = 0;
    if (*(int*)(self + 0xE20) && t < 1.0f)
        stop = 1;
    if (stop) {
        *(float*)(self + 0xE3C) = 0.0f;
        *(float*)(self + 0xE38) = 0.0f;
        return;
    }
    if (!*(int*)(self + 0xE10))
        return;
    if (*(float*)(self + 0xE38) != 0.0f) {
        float lim = t + 0.1f;
        if (lim < a)
            *(float*)(self + 0xE38) = 0.0f;
        else if (lim < b && a - 0.4f < 0.0f)
            *(float*)(self + 0xE38) = 0.0f;
    }
    if (*(float*)(self + 0xE3C) != 0.0f) {
        float lim = t + 0.1f;
        if (lim < c) {
            *(float*)(self + 0xE3C) = 0.0f;
            *(float*)(self + 0xE38) = 0.0f;
        } else if (lim < d && c - 0.4f < 0.0f) {
            *(float*)(self + 0xE3C) = 0.0f;
            *(float*)(self + 0xE38) = 0.0f;
        }
    }
}
#endif

INCLUDE_ASM("seg/seg_1218", func_0010B250);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_0010B590);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sVec4_B590 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPad_B590 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};

struct sPadBits_B590 {
    unsigned int pad0 : 24;
    int b24 : 6;
};

int AIrand();
extern "C" void func_00100610_B590(sVec4_B590*, void*) __asm__("func_00100610");
extern "C" float func_00100348_B590(void*, sVec4_B590*) __asm__("func_00100348");

extern "C" void func_0010B590(char* self, sPad_B590* pad)
{
    char* o = *(char**)(*(char**)(self + 0x18) + 0x788);
    int st = *(int*)(o + 0xAC);
    int ok = 0;
    if (st == 1 || st == 3)
        ok = 1;
    float d;
    if (ok)
        d = *(float*)(o + 0x98) - *(float*)(o + 0xA0);
    else
        d = 0.0f;
    *(int*)(self + 0xE10) = 0;
    *(int*)(self + 0xE14) = 0;
    *(int*)(self + 0xE18) = 1;
    *(int*)(self + 0xE20) = 0;
    *(int*)(self + 0xE0C) = -1;
    if (d > 1.0f) {
        *(int*)(self + 0xE10) = 1;
        *(float*)(self + 0xE38) = 1.0f;
        if (AIrand() & 1)
            *(float*)(self + 0xE38) = -*(float*)(self + 0xE38);
    } else {
        *(float*)(self + 0xE38) = 0.0f;
    }
    if (d > 3.0f) {
        *(int*)(self + 0xE10) = 1;
        *(float*)(self + 0xE3C) = 1.0f;
        if (AIrand() & 1)
            *(float*)(self + 0xE3C) = -*(float*)(self + 0xE3C);
    } else {
        *(float*)(self + 0xE3C) = 0.0f;
    }
    if (d < 0.5f && *(float*)(self + 0xE3C) == 0.0f && *(float*)(self + 0xE38) == 0.0f) {
        sVec4_B590 v;
        func_00100610_B590(&v, self);
        ((sPadBits_B590*)pad)->b24 = (int)(-func_00100348_B590(self, &v) * 31.0f);
        *(int*)(self + 0xE0C) = -1;
    }
    pad->b2 = *(int*)(self + 0xE0C);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B750);
#ifdef SKIP_ASM
extern "C" void func_0010B750(void *arg0, int *arg1) {
    *arg1 = (*arg1 & ~0x1000) | ((func_0010D1A0(arg0) & 1) << 0xC);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B790);
#ifdef SKIP_ASM
struct sPad_B790 {
    unsigned int pad0 : 12;
    int b12 : 6;
};

class cLvl_B790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int Level();
};

int AIrand();
extern "C" int func_001298C8();

extern "C" void func_0010B790(char* self, sPad_B790* pad)
{
    float t = 180.0f - (float)func_001298C8();
    float th = 33.0f;
    th -= (float)((((cLvl_B790*)(*(char**)(self + 0x18) + 0x6C0))->Level() - 1) * 10);
    if (t < th && ((cLvl_B790*)(*(char**)(self + 0x18) + 0x6C0))->Level() < 4) {
        pad->b12 = 0x1F;
        return;
    }
    if (t < 72.0f && ((cLvl_B790*)(*(char**)(self + 0x18) + 0x6C0))->Level() < 3) {
        pad->b12 = -0x1F;
        return;
    }
    if (func_001298C8() % 20 == 0) {
        unsigned int r = AIrand();
        float* p = (float*)(self + 0xDF0);
        *p = (float)r * 0.009999999776482582f;
        if ((AIrand() & 1) == 0)
            *(float*)(self + 0xDF0) = -*(float*)(self + 0xDF0);
    }
    pad->b12 = (int)(*(float*)(self + 0xDF0) * 31.0f);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B980);
#ifdef SKIP_ASM
struct sVec4_B980 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRec_B980 {
    int type;
    int flags;
    float a;
    float b;
};

class cTrack_B980 {
public:
    char pad[0x34];
    virtual int Query(sRec_B980* buf, int max, float x, float y);
};

extern "C" sVec4_B980 func_0026AB20(cTrack_B980*, int, float);

extern "C" int func_0010B980(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6)
{
    sRec_B980 buf[12];
    char* rider = *(char**)(self + 0x18);
    cTrack_B980* trk = *(cTrack_B980**)(rider + 0xAB8);
    int n = trk->Query(buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 300.0f);
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x10) {
            int fl = buf[i].flags;
            *speed = (float)(fl >> 4) * 27.777780532836914f;
            *o3 = (fl >> 3) & 1;
            *o4 = (fl >> 2) & 1;
            *o5 = (fl >> 1) & 1;
            *o6 = fl & 1;
            *below = (buf[i].a <= *(float*)(*(char**)(self + 0x18) + 0x4C4)) ? 1 : 0;
            *(sVec4_B980*)(self + 0xE50) = func_0026AB20(trk, 0, buf[i].a);
            *(sVec4_B980*)(self + 0xE60) = func_0026AB20(trk, 0, buf[i].b);
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BB18);
#ifdef SKIP_ASM
struct sHit_BB18 { int type; int val; float lim; int d; };
extern "C" int func_0010BB18(void* self_, float* out, int* ok) {
    char* self = (char*)self_;
    sHit_BB18 buf[12];
    char* rider = *(char**)(self + 0x18);
    char* q = *(char**)(rider + 0xAB8);
    char* vt = *(char**)(q + 0x34);
    int n = (*(int (**)(char*, sHit_BB18*, int, float, float))(vt + 0xC))(q + *(short*)(vt + 8), buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 600.0f);
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x11) {
            *out = (float)buf[i].val * 27.777780532836914f;
            *ok = buf[i].lim <= *(float*)(*(char**)(self + 0x18) + 0x4C4);
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BBF8);
#ifdef SKIP_ASM
struct sHit_BBF8 { int type; int val; int d[2]; };
extern "C" int func_0010BBF8(void* self_, int* out) {
    char* self = (char*)self_;
    sHit_BBF8 buf[12];
    char* rider = *(char**)(self + 0x18);
    char* q = *(char**)(rider + 0xAB8);
    char* vt = *(char**)(q + 0x34);
    int n = (*(int (**)(char*, sHit_BBF8*, int, float, float))(vt + 0xC))(q + *(short*)(vt + 8), buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 50.0f);
    *out = 0;
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x13) {
            *out = buf[i].val > 0;
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BC98);
#ifdef SKIP_ASM
struct sHit_BC98 { int type; int d[3]; };
extern "C" int func_0010BC98(char* self) {
    sHit_BC98 buf[12];
    char* rider = *(char**)(self + 0x18);
    char* q = *(char**)(rider + 0xAB8);
    char* vt = *(char**)(q + 0x34);
    int n = (*(int (**)(char*, sHit_BC98*, int, float, float))(vt + 0xC))(q + *(short*)(vt + 8), buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4));
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0xF) return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_1218", func_0010BD10);

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BFA8);
#ifdef SKIP_ASM
int AIrand();
extern "C" int func_0010C1D0(void*);

struct sObj_BFA8 {
    char pad[0xE0C];
    int fE0C;
    int fE10;
    int fE14;
    int fE18;
    int fE1C;
    int fE20;
    char padE24[0x14];
    float fE38;
    float fE3C;
};

extern "C" void func_0010BFA8(sObj_BFA8* self, int a, int b, int c, int d)
{
    self->fE0C = -1;
    int* p = &self->fE10;
    *p = (a || b);
    self->fE14 = func_0010C1D0(self);
    self->fE20 = c;
    self->fE1C = d;
    self->fE18 = 0;
    if (self->fE10) {
        self->fE38 = a ? 1.0f : 0.0f;
        self->fE3C = b ? 1.0f : 0.0f;
        if (AIrand() & 1)
            self->fE38 = -self->fE38;
        if (AIrand() & 1)
            self->fE3C = -self->fE3C;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C0A8);
#ifdef SKIP_ASM
struct sVec4_C0A8 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sPad_C0A8 {
    unsigned int pad0 : 16;
    unsigned int b16 : 1;
    unsigned int b17 : 1;
    unsigned int pad18 : 8;
    int w0 : 6;
};
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_C0A8(const sVec4_C0A8& v)
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
extern "C" void func_0010C0A8(void* self, void* padp)
{
    sPad_C0A8* pad = (sPad_C0A8*)padp;
    float len = vLen_C0A8(*(sVec4_C0A8*)(*(char**)((char*)self + 0x18) + 0x1E0));
    float s = 0.97f;
    if (len < 833.3334350585938f)
        s = 1.0f;
    if (*(float*)((char*)self + 0xDF8) < 20.0f)
        s = 0.0f;
    pad->w0 = (int)(s * 31.0f);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C140);
#ifdef SKIP_ASM
struct sVec4_C140 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sPad_C140 {
    unsigned int pad0 : 16;
    unsigned int b16 : 1;
    unsigned int b17 : 1;
    unsigned int pad18 : 8;
    int w0 : 6;
};
// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_C140(const sVec4_C140& v)
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
extern "C" void func_0010C140(void* self, void* padp)
{
    sPad_C140* pad = (sPad_C140*)padp;
    float len = vLen_C140(*(sVec4_C140*)(*(char**)((char*)self + 0x18) + 0x1E0));
    float s = 0.97f;
    if (len < 833.3334350585938f)
        s = 1.0f;
    pad->w0 = (int)(s * 31.0f);
    pad->b16 = 1;
    pad->b17 = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C1D0);
#ifdef SKIP_ASM
extern "C" int func_0010C1D0(void* self) {
    unsigned int r = AIrand();
    float thr = *(float*)((char*)self + 0xDFC) * 100.0f;
    return thr <= (float)(r % 100U);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C258);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_C258(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144BE0(void* iface);
extern "C" int func_0010C258(void* self) {
    if (*(unsigned int*)(*(char**)((char*)self + 0x18) + 0xB2C) & 1) {
        if (func_00144BE0(cBE_getInterface_C258(cBE_getBE(), 0)) != 0xE) {
            unsigned int r = AIrand();
            float thr = *(float*)((char*)self + 0xDFC) * 100.0f;
            return (float)(r % 100U) < thr;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C320);
#ifdef SKIP_ASM
extern "C" int func_0010C320(void* self) {
    unsigned int r = AIrand();
    float thr = *(float*)((char*)self + 0xDFC) * 70.0f + 30.0f;
    return (float)(r % 100U) < thr;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C3B8);
#ifdef SKIP_ASM
extern "C" int func_0010C3B8(void* self) {
    unsigned int r = AIrand();
    float thr = *(float*)((char*)self + 0xDFC) * 40.0f + 60.0f;
    return (float)(r % 100U) < thr;
}
#endif

INCLUDE_ASM("seg/seg_1218", func_0010C450);
