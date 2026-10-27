#include "common.h"

//100%
INCLUDE_ASM("sound/ssxAudio", SSXAUDIO_Init);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" char* func_00284C68(void* mem, int a1, int a2, int a3, int a4);
void func_002ADBF0(void*);
extern const char D_004828B0[];
extern char* D_004A3500;

extern "C" void SSXAUDIO_Init(int a)
{
    if (D_004A3500 == 0) {
        D_004A3500 = func_00284C68(cMemMan_alloc(0x7780, D_004828B0, 0x80000400, 0), 1, 0x1C, 3, a);
    }
    func_002ADBF0(**(char***)(D_004A3500 + 0x118) + 0x1D8);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00284C28);
#ifdef SKIP_ASM
class func_00284C28_cObj {
public:
    char data[0x1D4];
    virtual void v01(int flags);
};

extern char* D_004A3500;

extern "C" void func_00284C28()
{
    if (D_004A3500 != 0) {
        (**(func_00284C28_cObj***)(D_004A3500 + 0x118))->v01(3);
    }
    D_004A3500 = 0;
}
#endif

INCLUDE_ASM("sound/ssxAudio", func_00284C68);

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285210);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);
extern "C" void func_00289650(void* msg);
extern "C" void func_0028F730(void* self);
extern "C" void func_003B5A60(void (*cb)(void*));
extern "C" void func_002B0DA0(void* p);
extern "C" void func_003DEDC0(void* h, int a);
extern "C" void func_002AB478(void* self, int flags);
extern "C" void func_002AA648(void* self, int flags);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern void* D_00483688[];
extern void* D_004836B8[];
extern void* D_004836D8[];

struct sSaVEntry285210 {
    short delta;
    short index;
    void* fn;
};
struct sSaVtbl4_285210 {
    sSaVEntry285210 e[4];
} __attribute__((aligned(8)));
struct sSaVtbl8_285210 {
    sSaVEntry285210 e[8];
} __attribute__((aligned(8)));
struct sSaVtbl7_285210 {
    sSaVEntry285210 e[7];
} __attribute__((aligned(8)));
extern const sSaVtbl4_285210 D_00483708_285210 __asm__("D_00483708");
extern const sSaVtbl8_285210 D_00483648_285210 __asm__("D_00483648");
extern const sSaVtbl7_285210 D_00483728_285210 __asm__("D_00483728");

#define S_285210 ((char*)self)
#define BM_285210 (**(char***)(S_285210 + 0x118))

extern "C" void func_00285210(void* self, int flags)
{
    char* p5560 = S_285210 + 0x5560;
    *(void***)(S_285210 + 0x5558) = D_00483688;
    *(void***)(S_285210 + 0x571C) = D_004836D8;
    *(void***)(S_285210 + 0xC) = D_004836B8;
    *(const sSaVtbl4_285210**)(*(char**)(BM_285210 + 0x1D8) + 4) = &D_00483708_285210;
    *(const sSaVtbl8_285210**)(BM_285210 + 0xAB0) = &D_00483648_285210;
    *(const sSaVtbl7_285210**)(BM_285210 + 0x1D4) = &D_00483728_285210;
    if (flags == 0) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtables on the stack), written out by hand.
        sSaVtbl4_285210 v1 = D_00483708_285210;
        *(sSaVtbl4_285210**)(*(char**)(BM_285210 + 0x1D8) + 4) = &v1;
        char* base1 = *(char**)(BM_285210 + 0x1D8) - 0x6C90;
        int d1 = S_285210 - base1;
        v1.e[1].delta = D_00483708_285210.e[1].delta + d1;
        v1.e[2].delta = D_00483708_285210.e[2].delta + d1;
        sSaVtbl8_285210 v2 = D_00483648_285210;
        *(sSaVtbl8_285210**)(BM_285210 + 0xAB0) = &v2;
        char* base2 = BM_285210 - 0x6C98;
        int d2 = S_285210 - base2;
        v2.e[1].delta = D_00483648_285210.e[1].delta + d2;
        v2.e[2].delta = D_00483648_285210.e[2].delta + d2;
        v2.e[3].delta = D_00483648_285210.e[3].delta + d2;
        v2.e[5].delta = D_00483648_285210.e[5].delta + d2;
        v2.e[6].delta = D_00483648_285210.e[6].delta + d2;
        sSaVtbl7_285210 v3 = D_00483728_285210;
        *(sSaVtbl7_285210**)(BM_285210 + 0x1D4) = &v3;
        v3.e[1].delta = D_00483728_285210.e[1].delta + d2;
    }
    func_0028F730(self);
    func_003B5A60(func_00289650);
    func_002B0DA0(p5560);
    if (*(void**)(S_285210 + 0x5728))
        func_003DEDC0(*(void**)(S_285210 + 0x5728), 100);
    if (*(void**)(S_285210 + 0x5980))
        cMemMan_free(*(void**)(S_285210 + 0x5980));
    func_002AB478(self, 0);
    if (flags & 2) {
        func_002AA648(*(void**)(S_285210 + 0x118), 0);
        func_0028BB10(BM_285210, 0);
        func_002ADEE8(*(void**)(BM_285210 + 0x1D8), 0);
    }
    if (flags & 1)
        operator_delete((int*)self);
}
#undef S_285210
#undef BM_285210
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002854A8);
#ifdef SKIP_ASM
// PORT: the target leaves value in $a1 for this call; bind a 2-arg form.
extern "C" int func_002ADF80_2(void* bank, int a1) __asm__("func_002ADF80");

extern "C" int func_002854A8(void* self, int value)
{
    char* s = (char*)self;
    int r = func_002ADF80_2(*(void**)(**(char***)(s + 0x118) + 0x1D8), value);
    if (r == 2) {
        *(int*)(s + 0x62B0) = value;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002854F8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBankMonitor_BANKMONITOR_Create(void* sub, int id, int vol, int a3);
extern "C" int func_00288940(void* self, int id);
extern "C" int func_00288AE0(void* self);
extern "C" void func_002A9988(void* self, float a, float b);
extern "C" int func_002AAD78(void* self, int i, int a, int b, int c);
int func_002AB188(void* self, int a1);
extern "C" void func_002ABCF8(void* self, int a, const char* name, int b);
extern "C" void* func_00416210(void* dst, int c, int n);
extern signed char D_00535C11[];

struct sSnd54F8Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd54F8E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd54F8Sub {
    char pad0[4];
    sSnd54F8Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd54F8Ch* ch;          // 0x20
    int tgt[4];              // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    float* p68;              // 0x68
    float* p6C;              // 0x6C
    sSnd54F8E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd54F8Mgr {
    char pad0[0x1D8];
    sSnd54F8Sub sub;         // 0x1D8
};
struct sSnd54F8Sys {
    char pad0[0x118];
    sSnd54F8Mgr** p118;      // 0x118
};

extern "C" int func_002854F8(void* vself, int a1, const char* a2, int a3, int a4, int a5, int a6, int a7, float f, int a8)
{
    sSnd54F8Sys* self = (sSnd54F8Sys*)vself;
    // PORT: a2 (a name pointer) is passed through func_002AAD78 as an int
    int r = func_002AAD78(self->p118, a1, a5, (int)a2, a3);
    if (r < 0) {
        return r;
    }
    sSnd54F8Mgr* m = *self->p118;
    sSnd54F8Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0.0f;
    s->p6C[m->sub.cur] = 0.0f;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    if (f <= 0.0f) {
        if (a7 != 0) {
            func_002A9988(&(*self->p118)->sub, 29.997713088989258f, -1.0f);
        } else {
            func_002A9988(&(*self->p118)->sub, 100.0f, -1.0f);
        }
    } else {
        func_002A9988(&(*self->p118)->sub, f, -1.0f);
    }
    (*self->p118)->sub.p60[(*self->p118)->sub.cur] = a6;
    if (a4 != 0) {
        (*self->p118)->sub.tgt[(*self->p118)->sub.cur] = a4;
        sSnd54F8Mgr** pp = self->p118;
        int v = func_00288940(self, a4);
        (*pp)->sub.p64[(*pp)->sub.cur] = v;
    }
    if (cBE_getInterface_Fv(cBE_getBE(), 0) != 0 && D_00535C11[0] == 2 && a7 != 0 && func_00288AE0(self) == 0) {
        (*self->p118)->sub.p80[(*self->p118)->sub.cur] = 1;
        (*self->p118)->sub.p84[(*self->p118)->sub.cur] = a8;
    }
    void* bm = cBankMonitor_BANKMONITOR_Create(&(*self->p118)->sub, r, 0x7F, 3);
    if (bm != 0) {
        func_002ABCF8(bm, func_002AB188(self->p118, a1), a2, a3);
    }
    (*self->p118)->sub.cur--;
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285930);
#ifdef SKIP_ASM
extern "C" void* func_0028B1C0();
extern "C" void* func_0028B1C8();
extern "C" float func_0031C228(float);

// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
struct sV4_5930 {
    float x, y, z, w;
    sV4_5930() {}
    sV4_5930(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sObjList_5930 {
    int count;
    char* items[1];
};

struct sV3_5930 {
    float x, y, z;
};

// PORT: PS2-only VU0 inline asm (matrix * vector).
static inline sV4_5930 vu0MtxApply_5930(char* m, const sV4_5930& v)
{
    sV4_5930 out;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf8, %1\n"
        "lqc2      $vf4, 0x0(%2)\n"
        "lqc2      $vf5, 0x10(%2)\n"
        "lqc2      $vf6, 0x20(%2)\n"
        "lqc2      $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        ".set pop\n"
        : "=m"(out)
        : "m"(v), "r"(m)
        : "memory");
    return out;
}

// PORT: PS2 sqrt.s asm helper.
static inline float sqrt_5930(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline float Atan2_5930(float y, float x)
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

extern "C" float func_00285930(char* a1, char* a2, char* a3)
{
    if (*(int*)((char*)func_0028B1C0() + 0x84) == 0)
        return 1.0f;
    char* g = (char*)func_0028B1C8();
    char* obj = (*(sObjList_5930**)(g + 0x84))->items[*(int*)(a2 + 0x84)];
    float* src = *(float**)(a2 + 0x68);
    sV3_5930 d;
    sV4_5930 tp = vu0MtxApply_5930(obj + 0x40, sV4_5930(src[0], src[1], src[2], 1.0f));
    float cy;
    float cz = -100.0f;
    d.x = tp.x * 0.009999999776482582f;
    cy = 25.0f;
    d.y = (tp.y + cy) * 0.009999999776482582f;
    d.z = (tp.z + cz) * 0.009999999776482582f;
    if (*(int*)(a1 + 0x62B0) == 0) {
        *(short*)(a3 + 8) = 0;
        *(short*)(a3 + 10) = 0;
    } else {
        if (*(int*)(a2 + 0xA0) != 0) {
            if (*(int*)(a2 + 0xA4) != 0)
                *(short*)(a3 + 8) = 0x4000;
            else
                *(unsigned short*)(a3 + 8) = 0xC000;
        } else {
            *(short*)(a3 + 8) = (int)(Atan2_5930(d.x, d.z) * 10430.3779296875f);
        }
        float len = sqrt_5930(d.x * d.x + d.z * d.z);
        *(short*)(a3 + 10) = (int)(Atan2_5930(d.y, len) * 10430.3779296875f);
    }
    return d.x * d.x + d.y * d.y + d.z * d.z;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285BE0);
#ifdef SKIP_ASM
extern "C" void func_00285BE0(void* self, int a1)
{
    int* p = (int*)((char*)self + 0x6474);
    if (*p != a1) {
        *p = a1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285BF8);
#ifdef SKIP_ASM
extern int D_004A2A50;
extern "C" int func_00390EF8();
extern "C" void* func_0028B180();
extern "C" void func_00291438(void* p, float f);
extern "C" void func_002AB958(void* self, float dt);
extern "C" int func_002AB028(void* p, int idx);
extern "C" void func_00287C48(void* self);
struct sSaMix87F8;
extern "C" void func_002887F8(sSaMix87F8* self);
extern "C" void func_0028C8C8(void* self);
extern "C" void func_0028F000(void* self);
extern "C" void func_00295208(void* self);
extern "C" void func_002947B0(void* self);
extern "C" void func_00297FA0(void* self);
extern "C" void func_0028E100(void* self);
extern "C" void func_0029D290(void* self);
extern "C" void func_0029AB40(void* self);
extern "C" void func_0029B738(void* self);
extern "C" void func_0029CCA8(void* self);
extern "C" void func_0029D610(void* self);
extern "C" void func_00289688(void* self);
extern "C" void func_00287F00(void* self, int a1, float f0, float f1);
extern "C" void* func_0028B1C0();
extern "C" void* func_0028B1C8();
extern "C" void func_002948A0(void* self);
extern "C" void func_00289BB8(void* self);

extern "C" void func_00285BF8(char* self, float dt)
{
    if (func_00390EF8() != 0)
        func_00291438(func_0028B180(), 0.0f);
    func_002AB958(self, dt);
    int st = *(int*)(self + 0x63D4);
    if (st != 3) {
        if (*(int*)(self + 0x63E0) == 0) {
            if (func_002AB028(*(void**)(self + 0x118), st) != 0)
                *(int*)(self + 0x63E0) = 1;
        } else if (func_002AB028(*(void**)(self + 0x118), st) == 0) {
            func_00287F00(self, 3, 0.5f, 1.0f);
        }
    }
    func_00287C48(self);
    func_002887F8((sSaMix87F8*)self);
    if (*(int*)((char*)func_0028B1C0() + 0x84) != 0) {
        func_0028C8C8(self);
        if (*(int*)(self + 0x6474) == 6) {
            if (*(int*)(self + 0x5FB4) == 0)
                func_0028F000(self);
            func_00295208(self);
            if (*(int*)((char*)func_0028B1C8() + 0x214) == 4)
                func_002947B0(self);
            else
                func_002948A0(self);
            func_00297FA0(self);
            func_0028E100(self);
            func_0029D290(self);
            func_0029AB40(self);
            func_0029B738(self);
            func_0029CCA8(self);
            func_0029D610(self);
            if (*(int*)(self + 0x5FB4) != 0 && !(D_004A2A50 & 2))
                func_00289BB8(self);
        }
    }
    func_00289688(self);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285D98);
#ifdef SKIP_ASM
extern "C" int func_00288AE0(void* self);
extern "C" char* func_0028B1D8();

struct sAudVoice5D98 {
    char pad_0x0[0xEC];
    int prio;           // 0xEC
    char pad_0xF0[0x870 - 0xF0];
    int id;             // 0x870
    int active;         // 0x874
    int f878;
    int enabled;        // 0x87C
};

struct sAudSys5D98 {
    char pad_0x0[0x28];
    sAudVoice5D98* voices[6];   // 0x28
    char* cur;                  // 0x40
    char pad_0x44[0x78 - 0x44];
    int numVoices;              // 0x78
    int numUsed;                // 0x7C
};

static inline int sAudVoice5D98_isOn(sAudVoice5D98* v)
{
    return v->active && v->enabled;
}

// PORT: returns a voice pointer; the unit declares the return type as int.
extern "C" int func_00285D98(void* self, int which)
{
    if (func_00288AE0(self) != 0) {
        char* cur = ((sAudSys5D98*)func_0028B1D8())->cur;
        return cur ? *(int*)(cur + 0x18) : 0;
    }
    if (which == -1) {
        int best = 0;
        int bestPrio = 30000;
        for (int i = 0; i < ((sAudSys5D98*)func_0028B1D8())->numUsed; i++) {
            sAudVoice5D98* v = ((sAudSys5D98*)func_0028B1D8())->voices[i];
            if (sAudVoice5D98_isOn(v) && v->prio < bestPrio) {
                bestPrio = v->prio;
                best = i;
            }
        }
        return (int)((sAudSys5D98*)func_0028B1D8())->voices[best];
    }
    if (which == -2) {
        for (int i = 0; i < ((sAudSys5D98*)func_0028B1D8())->numVoices; i++) {
            sAudVoice5D98* v = ((sAudSys5D98*)func_0028B1D8())->voices[i];
            if (sAudVoice5D98_isOn(v))
                return (int)v;
        }
    } else {
        for (int i = 0; i < ((sAudSys5D98*)func_0028B1D8())->numVoices; i++) {
            sAudVoice5D98* v = ((sAudSys5D98*)func_0028B1D8())->voices[i];
            if (v->id == which)
                return (int)v;
        }
    }
    return (int)((sAudSys5D98*)func_0028B1D8())->voices[0];
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285F48);
#ifdef SKIP_ASM
extern "C" void func_002A7718(void*);
extern "C" void func_002AD3C0(void*);

extern "C" void func_00285F48(void* self)
{
    func_002A7718(self);
    void* inner = **(void***)((char*)self + 0x118);
    func_002AD3C0((char*)inner + 0x1D8);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285F80);
#ifdef SKIP_ASM
// PORT: callee declared variadic to reproduce the original by-value struct passing; real signature takes an 8-byte struct.
struct func_00285F80_sPair {
    int a;
    int b;
};

extern "C" void func_002AD410(void* obj, ...);

extern "C" void func_00285F80(void* self, func_00285F80_sPair p)
{
    void* inner = **(void***)((char*)self + 0x118);
    func_002AD410((char*)inner + 0x1D8, p);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00285FB0);
#ifdef SKIP_ASM
extern "C" void func_00288D18(void* self, int a1);
extern "C" void func_00285BE0(void* self, int a1);
// PORT: func_002A77F8/func_002A7FF8 return values (the unit declares them void); bound by asm label.
extern "C" void* func_002A77F8_r(void* self, char* name, int size) __asm__("func_002A77F8");
extern "C" int func_002A7BF8(void* self, const char* section);
extern "C" int func_002A7F90(void* self);
extern "C" char* func_002A7DA0(void* self);
extern "C" int func_002A7FF8_r(void* self, const char* key, char* out) __asm__("func_002A7FF8");
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void func_0028BC58(void* p, int a1, char* msg, int a3);
extern "C" void func_00287F00(void* self, int a1, float f0, float f1);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" void func_002B49C0(void* mon, int id);
extern "C" void func_00289BB8(void* self);
extern "C" void func_002A7890(void* self, int flags);
extern char* D_004A3554;
extern char D_004A3570[];
extern char D_004A3578[];
extern char D_004A3580[];
extern char D_004A3588[];
extern char D_004A3590[];
extern char D_004A3598[];
extern char D_004828C0[];

struct sIniParser5FB0 {
    int f0;
    char* start;    // 0x4
    char* cur;      // 0x8
    char pad[0x810 - 0xC];
};

struct sSaVt5FB0 { short delta; short index; void (*fn)(void*, char*, int, void*, int); };

extern "C" void func_00285FB0(char* self)
{
    sIniParser5FB0 parser;
    char key[0x80];
    char name[0x80];
    char val[0x60];
    char msg[0x40];
    func_00288D18(self, 0);
    func_00285BE0(self, 1);
    func_002A77F8_r(&parser, D_004A3554, 0x100);
    parser.cur = parser.start;
    if (func_002A7BF8(&parser, D_004A3570)) {
        while (func_002A7F90(&parser) == 0) {
            func_002A7DA0(&parser);
            func_002A7FF8_r(&parser, D_004828C0, key);
        }
    }
    parser.cur = parser.start;
    if (func_002A7BF8(&parser, D_004A3578)) {
        strcpy(name, key);
        while (func_002A7F90(&parser) == 0) {
            char* k = func_002A7DA0(&parser);
            func_002A7FF8_r(&parser, D_004828C0, name);
            if (func_0041AA88(k, D_004A3580) == 0) {
                func_002A7FF8_r(&parser, D_004A3580, val);
                sprintf(msg, D_004A3588, D_004A3590, name, val);
                func_0028BC58(**(void***)(self + 0x118), 0, msg, 0);
            }
        }
    }
    func_00287F00(self, 3, 0.5f, 1.0f);
    char* mon = self + 0x118;
    sSaVt5FB0* vt = *(sSaVt5FB0**)(self + 0x5558);
    char* thisp = mon + vt[2].delta;
    vt[2].fn(thisp, D_004A3598, 0xC, func_00287968(self, 1, 0), 1);
    func_002B49C0(mon, 0x12D);
    *(int*)(self + 0x6290) = 10;
    *(int*)(self + 0x6090) = *(int*)(self + 0x608C);
    func_00289BB8(self);
    func_002A7890(&parser, 2);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002861D0);
#ifdef SKIP_ASM
struct func_002861D0_vte { short delta; short index; int (*fn)(void*, int); };
extern "C" void func_002861D0(char* self)
{
    func_002861D0_vte* vt = *(func_002861D0_vte**)(self + 0x5558);
    char* mon = self + 0x118;
    vt[4].fn(mon + vt[4].delta, 1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_00286200);
#ifdef SKIP_ASM
struct func_00286200_vte { short delta; short index; void (*fn)(void*); };
extern "C" void func_002B3AC0(void*);
extern "C" void func_002B3D48(void*, float);
extern "C" void func_002ADDA0(void*);
extern "C" void func_0028BCE8(void*, int);

extern "C" void func_00286200(void* self)
{
    if (*(int*)((char*)self + 0x608C) == 2 || *(int*)((char*)self + 0x6090) == 2) {
        func_002B3AC0((char*)self + 0x118);
    } else {
        func_002B3D48((char*)self + 0x118, 1.0f);
    }
    func_00285BE0(self, 0);
    func_002ADDA0(**(char***)((char*)self + 0x118) + 0x1D8);
    char* in = **(char***)((char*)self + 0x118);
    char* obj = in + 0x1D8;
    func_00286200_vte* vt = *(func_00286200_vte**)(in + 0xAB0);
    vt[2].fn(obj + vt[2].delta);
    func_0028BCE8(**(void***)((char*)self + 0x118), 0);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", cSSXAudio_FrontEndLoad);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_004165A8(const void* a, const void* b);
extern "C" char* strcpy(char* d, const char* s);
extern "C" int func_002A7F90(void* self);
extern "C" int func_002A7FF8_r(void* self, const char* key, char* out) __asm__("func_002A7FF8");
extern "C" char* func_002A7DA0(void* self);
extern "C" void* func_002A77F8_r(void* self, char* name, int size) __asm__("func_002A77F8");
extern "C" int func_002A7BF8(void* self, const char* name);
extern "C" char* func_002A7B08(void*);
extern "C" void func_002A7890(void* self, int flags);
extern "C" void func_0028BC58(void* bank, int slot, char* name, int a3);
extern "C" void func_0028BDA8(void* self, int i, int a, int b, int c);
extern "C" void func_0029F3F8_2(char* self, int a) __asm__("func_0029F3F8");
extern "C" void func_002A6D78(char* self, const char* name, const char* key, int n, int v);
extern "C" void func_00288D18(void* self, int a1);
void ASYNCSYS_Init_FE(void* self, unsigned int x, int flags) __asm__("cAsyncSys_ASYNCSYS_Init__FP9cAsyncSysUi");
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern char D_00535BC8[];
extern unsigned char D_004A35A8[];
extern char* D_004A3554;
extern char* D_004A3558;
extern char D_004A3570[];
extern char D_004828C0[];
extern char D_004A3580[];
extern char D_004A3588[];
extern char D_004A3590[];
extern char D_004A35B0[];
extern char D_004828D0[];
extern char D_004A35B8[];
extern char D_004A35C0[];
extern char D_004A35C8[];
extern char D_004828E0[];
extern char D_004828F0[];
extern char D_004A35D0[];

struct sFeParser {
    int size;
    char* data;
    char* cur;
    char token[0x800];
};

static inline int sa_state_FE()
{
    signed char* g = (signed char*)D_00535BC8;
    return g[0x49];
}

extern "C" void cSSXAudio_FrontEndLoad(char* self)
{
    char name[0x40];
    strcpy(name, "WORLD");
    func_00288D18(self, 1);
    ASYNCSYS_Init_FE(**(void***)(self + 0x118), 0, 0);
    *(char*)(self + 0x5838) = D_004A35A8[0];
    *(int*)(self + 0x5878) = 0;
    char buf40[0x80];
    sFeParser p;
    char dir[0x80];
    char val[0x60];
    char key[0x70];
    func_002A77F8_r(&p, D_004A3554, 0x100);
    p.cur = p.data;
    if (func_002A7BF8(&p, D_004A3570)) {
        while (!func_002A7F90(&p)) {
            const char* t = func_002A7DA0(&p);
            if (func_0041AA88(t, D_004828C0) == 0) {
                func_002A7FF8_r(&p, D_004828C0, buf40);
            }
        }
    }
    p.cur = p.data;
    char* tok;
    while ((tok = func_002A7B08(&p)) != 0) {
        if (func_004165A8(tok, name) == 0) {
            strcpy(dir, buf40);
            strcpy(self + 0x587C, dir);
            while (!func_002A7F90(&p)) {
                const char* t = func_002A7DA0(&p);
                func_002A7FF8_r(&p, D_004828C0, dir);
                if (func_0041AA88(t, D_004A3580) == 0) {
                    func_002A7FF8_r(&p, D_004A3580, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 0, key, 0);
                } else if (func_0041AA88(t, D_004A35B0) == 0) {
                    func_002A7FF8_r(&p, D_004A35B0, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 1, key, 0);
                } else if (func_0041AA88(t, D_004828D0) == 0) {
                    func_002A7FF8_r(&p, D_004828D0, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 0x10, key, 0);
                } else if (func_0041AA88(t, D_004A35B8) == 0) {
                    func_002A7FF8_r(&p, D_004A35B8, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 5, key, 0);
                } else if (func_0041AA88(t, D_004A35C0) == 0) {
                    func_002A7FF8_r(&p, D_004A35C0, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 6, key, 0);
                } else if (func_0041AA88(t, D_004A35C8) == 0) {
                    func_002A7FF8_r(&p, D_004A35C8, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 7, key, 0);
                } else if (func_0041AA88(t, D_004828E0) == 0) {
                    func_002A7FF8_r(&p, D_004828E0, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 2, key, 0);
                } else if (func_0041AA88(t, D_004828F0) == 0) {
                    func_002A7FF8_r(&p, D_004828F0, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 4, key, 0);
                } else if (func_0041AA88(t, D_004A35D0) == 0) {
                    func_002A7FF8_r(&p, D_004A35D0, val);
                    sprintf(key, D_004A3588, D_004A3590, dir, val);
                    func_0028BC58(**(void***)(self + 0x118), 10, key, 0);
                }
            }
        }
    }
    func_0028BDA8(**(void***)(self + 0x118), 3, 0x19000, 0, 0);
    func_0028BDA8(**(void***)(self + 0x118), 12, 0x6A400, 0, 0);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (sa_state_FE() == 2) {
        func_002A6D78(self, D_004A3558, name, 2, 5);
    } else {
        func_002A6D78(self, D_004A3558, name, 1, 5);
    }
    func_0029F3F8_2(self, 0);
    *(int*)(self + 0x627C) = 1;
    func_002A7890(&p, 2);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002867E8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" char* func_0028B1D8();
extern "C" void* func_00123128(void*);
extern "C" int func_00158750(void* self, int a1, int a2);
extern "C" int func_00158700(void* self, int a1, int a2);
extern "C" void func_0028BF78(void* self, int a1);
extern "C" void func_0028C2D0(void* self, int a1);
extern "C" int func_002B49E0(void*);
extern "C" void func_0028D488(void* self);
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_002948A0(void* self);
extern "C" void func_00287F00(void* self, int a1, float f0, float f1);
extern "C" int func_00145D38(void* self, int index, int bit);
void func_0028DF08_C7B0(void* p) __asm__("func_0028DF08__FPv");
extern "C" void func_00286E20(void* self);
extern "C" void func_002A4A78(void* self);
struct cWorldPainterManArg;
void* cWorldPainterMan_getQuery(void*, cWorldPainterManArg*);
extern char D_004A5268;
extern char D_004A5270;
extern char D_004A5278;
extern void* D_004A28A8;
extern char D_00535BC8[];

static inline int sa_state_867E8()
{
    signed char* g = (signed char*)D_00535BC8;
    return g[0x49];
}

class func_002867E8_cObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

extern "C" void func_002867E8(char* self)
{
    void* be = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    char* bm = func_0028B1D8();
    void* rider = func_00123128(*(void**)(bm + 0x28));
    int a = func_00158750(be, 0, (int)rider);
    func_0028BF78(self, func_00158700(be, 0, (int)rider));
    func_0028C2D0(self, a);
    char* t118 = self + 0x118;
    if (*(int*)(self + 0x530) == 0 || func_002B49E0(t118) != 0x191) {
        func_0028D488(self);
        cBE_getInterface_Fv(cBE_getBE(), 0);
        if (sa_state_867E8() == 0) {
            func_0028CF98(self, 0, 0, -1, 0);
        } else {
            func_0028CF98(self, 0x24, 0, -1, 0);
        }
    }
    func_002948A0(self);
    cWorldPainterManArg* pa = (cWorldPainterManArg*)&D_004A5268;
    cWorldPainterManArg* pb = (cWorldPainterManArg*)&D_004A5278;
    cWorldPainterManArg* pc = (cWorldPainterManArg*)&D_004A5270;
    void* q = *(void**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x10) + 8);
    *(void**)(self + 0x625C) = cWorldPainterMan_getQuery(q, pa);
    *(void**)(self + 0x6260) = cWorldPainterMan_getQuery(q, pa);
    *(void**)(self + 0x5FA0) = cWorldPainterMan_getQuery(q, pb);
    *(void**)(self + 0x5FA4) = cWorldPainterMan_getQuery(q, pb);
    *(void**)(self + 0x6C80) = cWorldPainterMan_getQuery(q, pc);
    void* q2 = cWorldPainterMan_getQuery(q, pc);
    *(int*)(self + 0x626C) = 0;
    *(int*)(self + 0x6274) = 0;
    *(int*)(self + 0x5FC4) = 0;
    *(int*)(self + 0x6264) = -1;
    *(int*)(self + 0x6268) = -1;
    *(int*)(self + 0x6270) = 1;
    *(char*)(self + 0x5FC0) = 50;
    *(void**)(self + 0x6C84) = q2;
    func_00287F00(self, 3, 0.5f, 1.0f);
    *(int*)(self + 0x6288) = 0;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (sa_state_867E8() == 0) {
        int i = 0;
        int* p = (int*)(self + 0x579C);
        do {
            void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
            char* o = *(char**)(func_0028B1D8() + 0x28);
            *p = func_00145D38(iface, ((func_002867E8_cObj*)(o + 0x6C0))->v6(), i);
            i++;
            p++;
        } while (i < 23);
    }
    func_0028DF08_C7B0(self);
    func_00286E20(self);
    func_002A4A78(self);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00286A80);
#ifdef SKIP_ASM
extern "C" void func_00289BB8(void* self);
extern "C" void func_00285BE0(void* self, int a1);
extern "C" void func_002B3AC0(void*);
extern "C" void func_0029D678(void* self, float v);
extern "C" void func_002A4550(void*);
extern "C" void func_00292B48(void* self);
extern "C" void func_002980B0(void* self);
extern "C" void func_002883B0(void* self, int id);
extern "C" void func_002ADDA0(void*);
extern "C" void func_002B11B0(void*, int);

struct sSaDelVt6A80 { short delta; short index; void (*fn)(void*, int); };

static inline void saDeleteObj(void** slot)
{
    char* p = (char*)*slot;
    if (p) {
        sSaDelVt6A80* vt = *(sSaDelVt6A80**)(p + 4);
        vt[1].fn(p + vt[1].delta, 3);
    }
    *slot = 0;
}

extern "C" void func_00286A80(void* self)
{
    func_00289BB8(self);
    func_00285BE0(self, 0);
    func_002B3AC0((char*)self + 0x118);
    func_0029D678(self, 0.0f);
    func_002A4550(self);
    func_00292B48(self);
    saDeleteObj((void**)((char*)self + 0x625C));
    saDeleteObj((void**)((char*)self + 0x6260));
    saDeleteObj((void**)((char*)self + 0x5FA0));
    saDeleteObj((void**)((char*)self + 0x5FA4));
    saDeleteObj((void**)((char*)self + 0x6C80));
    saDeleteObj((void**)((char*)self + 0x6C84));
    func_002980B0(self);
    func_002883B0(self, 0);
    func_002ADDA0(**(char***)((char*)self + 0x118) + 0x1D8);
    char* in = **(char***)((char*)self + 0x118);
    char* obj = in + 0x1D8;
    func_00286200_vte* vt = *(func_00286200_vte**)(in + 0xAB0);
    vt[2].fn(obj + vt[2].delta);
    func_002B11B0((char*)self + 0x5560, 0);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00286C00);
#ifdef SKIP_ASM
extern "C" void func_002A6F38(void*);
extern "C" void func_00289DF0(void*, int);
extern "C" void func_0028BCE8(void*, int);
extern "C" void func_0028BDE0(void*, int);
extern "C" void func_0028A230(void*);
extern "C" void func_0029F5E0(void*);

extern "C" void func_00286C00(void* self)
{
    int i;
    func_002A6F38(self);
    func_00289DF0(**(void***)((char*)self + 0x118), 1);
    for (i = 0; i < 17; i++) {
        if (i != 13) {
            func_0028BCE8(**(void***)((char*)self + 0x118), i);
        }
    }
    func_0028BDE0(**(void***)((char*)self + 0x118), 3);
    func_0028BDE0(**(void***)((char*)self + 0x118), 12);
    func_0028A230(**(void***)((char*)self + 0x118));
    func_0029F5E0(self);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00286CA8);
#ifdef SKIP_ASM
struct sSsxAudioBanks {
    char pad[0x6C70];
    int loaded[2];
    int sub[2];
};
extern "C" void func_0028BE60(void* self, int i, int a, int b);

extern "C" void func_00286CA8(sSsxAudioBanks* self, unsigned int id, int on)
{
    unsigned int bank = id >> 8;
    if (on != 0) {
        func_0028BE60(**(void***)((char*)self + 0x118), bank + 8, on, 0x20000);
        self->loaded[bank] = 1;
        self->sub[bank] = id & 0xFF;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00286D18);
#ifdef SKIP_ASM
extern "C" void func_002AD650(void* p, int id, float v);
extern "C" void func_0029D678(void* self, float v);
extern "C" void func_0028BE90(void* mgr, int i);

static inline int saIsOn(char* cfg, int off) { return *(int*)(cfg + off) == 1; }

extern "C" void func_00286D18(void* self, unsigned int handle)
{
    unsigned int slot = handle >> 8;
    if (*(unsigned int*)((char*)self + (slot << 2) + 0x6C78) != (handle & 0xFF)) return;
    if (slot == 0) {
        char* mgr = **(char***)((char*)self + 0x118);
        char* cfg = *(char**)(mgr + 0xACC);
        char* bm = mgr + 0x1D8;
        int id = saIsOn(cfg, 0x300);
        if (id) id = *(int*)(cfg + 0x304); else id = -1;
        func_002AD650(bm, id, 0.0f);
    } else {
        func_0029D678(self, 0.0f);
        char* mgr = **(char***)((char*)self + 0x118);
        char* cfg = *(char**)(mgr + 0xACC);
        char* bm = mgr + 0x1D8;
        int id = saIsOn(cfg, 0x360);
        if (id) id = *(int*)(cfg + 0x364); else id = -1;
        func_002AD650(bm, id, 0.0f);
    }
    int off = slot << 2;
    char* tbl = (char*)self + 0x6C70;
    int* p = (int*)(tbl + off);
    if (*p != 0) {
        func_0028BE90(**(void***)((char*)self + 0x118), slot + 8);
        *p = 0;
        *(int*)((char*)self + (slot << 2) + 0x6C78) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00286E20);
#ifdef SKIP_ASM
extern "C" void func_00285BE0(void* self, int a1);
void func_002B6900(void* self);
extern "C" void func_002929D8(void* self);
extern "C" void* func_0028B1C8();
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_002A39E0(void* self);
extern signed char D_00535C11[];
extern void* D_004A52D4;

extern "C" void func_00286E20(void* self)
{
    func_00285BE0(self, 6);
    func_002B6900(D_004A52D4);
    func_002929D8(self);
    *(int*)((char*)self + 0x582C) = *(int*)(*(char**)((char*)func_0028B1C8() + 0xC) + 0x8);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int mode = D_00535C11[0];
    if (mode == 1) {
        goto load;
    }
    if (mode == 2) {
    load:
        func_002A39E0(self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00286EA0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00285D98(void* self, int which);
extern "C" int func_00288AE0(void* self);
extern "C" void func_002A73A8(void* p, int a1, int id);
extern "C" void func_00296E20(void* self, int id);
extern "C" void func_00297438(void* self, int id);
extern "C" void func_0029B3C0(void* self, int a1);
extern "C" int func_0028D960(void* self);
extern "C" int func_002A4078(void* self);
extern "C" int func_0012A250(void* p);
extern "C" char* func_0028B1D8();
extern "C" void func_002A3708(void* self, void* rider);
extern "C" void func_002A34D0(void* self, void* rider, int a2, int a3);
extern "C" void func_002A45C0(void* self);
extern char* D_004A3500;
extern void* D_004A28A8;
extern char D_00535BC8[];

static inline int sa_state6EA0()
{
    signed char* g = (signed char*)D_00535BC8;
    return g[0x49];
}

struct sSaVt6EA0 { short delta; short index; int (*fn)(void*, int); };

// PORT: rider pointers passed through int parameters of some callees.
extern "C" void func_00286EA0(char* self, char* rider)
{
    if (rider != (char*)func_00285D98(self, *(int*)(rider + 0x870)))
        return;
    func_002A73A8(D_004A3500, 2, func_00288AE0(self) ? 0 : *(int*)(rider + 0x870));
    int flag = 1;
    func_00296E20(self, (int)rider);
    func_00297438(self, (int)rider);
    func_0029B3C0(self, (int)rider);
    char* cfg = *(char**)((char*)D_004A28A8 + 0xC0);
    int b = *(int*)(cfg + 0x70);
    int a = *(int*)(cfg + 0x0);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    signed char* g = (signed char*)D_00535BC8;
    int mode = g[0x48];
    if ((mode == 2 || mode == 3) && a < b) {
        if (func_0028D960(self)) {
            char* mon = self + 0x118;
            sSaVt6EA0* vt = *(sSaVt6EA0**)(self + 0x5558);
            vt[4].fn(mon + vt[4].delta, 0x24);
            flag = 0;
            *(int*)(self + 0x627C) = 0;
        }
    }
    if (flag) {
        if (func_0028D960(self)) {
            char* mon = self + 0x118;
            sSaVt6EA0* vt = *(sSaVt6EA0**)(self + 0x5558);
            vt[4].fn(mon + vt[4].delta, 0xA);
        }
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (*(int*)(rider + 0x480) == 0) {
        if (func_002A4078(self))
            func_002A3708(self, rider);
        else if (sa_state6EA0() == 2) {
            if (func_0012A250(func_0028B1D8()))
                func_002A3708(self, rider);
            else
                func_002A34D0(self, rider, 0, -1);
        } else if (a < 3)
            func_002A34D0(self, rider, 0, -1);
        else
            func_002A3708(self, rider);
    }
    if (sa_state6EA0() == 0)
        func_002A45C0(self);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002870A0);
#ifdef SKIP_ASM
extern "C" void func_002871B0(void* self);
extern "C" int func_002A4040(void* self);
extern "C" int func_00295028(void* self, int a, int b);
extern "C" void func_00295628(void* self, int a, int b, int c, int d, int e);

extern "C" void func_002870A0(void* self)
{
    func_002871B0(self);
    if (func_002A4040(self) == 0 && func_00295028(self, 0, 0) == 0) {
        func_00295628(self, 0, 0, -1, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287108);
#ifdef SKIP_ASM
extern "C" void func_002871B0(void* self);
extern "C" int func_002A4040(void* self);
extern "C" int func_00295028(void* self, int a, int b);
extern "C" void func_00295628(void* self, int a, int b, int c, int d, int e);
extern "C" int func_002A4168(void* self);
extern "C" int func_002A41D8(void* self);
extern void* D_004A28A8;

extern "C" void func_00287108(void* self)
{
    func_002871B0(self);
    if (func_002A4168(self) != 0 || func_002A41D8(self) != 0) {
        if (func_002A4040(self) == 0
            && *(int*)((char*)self + 0x5824) >= *(int*)(*(char**)((char*)D_004A28A8 + 0xC0) + 0x70)
            && func_00295028(self, 0, 0) == 0) {
            func_00295628(self, 0, 0, -1, 0, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002871B0);
#ifdef SKIP_ASM
extern "C" void func_002948A0(void* self);
extern "C" void func_0029B3C0(void* self, int a1);
extern "C" void func_00287F00(void* self, int a1, float f0, float f1);
extern "C" char* func_0028B1D8();
extern "C" void func_00296E20(void* self, int id);
extern "C" void func_00297438(void* self, int id);
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_002871B0(void* self)
{
    int i = 0;
    func_002948A0(self);
    func_0029B3C0(self, 0);
    func_00287F00(self, 3, 0.5f, 1.0f);
    func_002B6900(D_004A52D4);
    int n = *(int*)(func_0028B1D8() + 0x78);
    for (; i < n; i++) {
        func_00296E20(self, *(int*)(func_0028B1D8() + (i << 2) + 0x28));
        func_00297438(self, *(int*)(func_0028B1D8() + (i << 2) + 0x28));
    }
    *(int*)((char*)self + 0x6074) = 0;
    *(int*)((char*)self + 0x6078) = 0;
    if (*(int*)((char*)self + 0x59E4) > 0) {
        func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + 0x59E0), 1, *(float*)((char*)self + 0x6074));
        *(int*)((char*)self + 0x59E4) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002872A8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0028D488(void* self);
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_002A26F0(void* self, int a1, int a2);
void func_002B1758(void* self, int a1);
int func_002B4908(void* mon);
extern char D_00535BC8[];

struct sSaVt72A8 { short delta; short index; int (*fn)(void*, int); };

extern "C" void func_002872A8(void* self)
{
    *(int*)((char*)self + 0x582C) = *(int*)(*(char**)((char*)func_0028B1C8() + 0xC) + 0x8);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    signed char* g = (signed char*)D_00535BC8;
    int mode = g[0x48];
    if (mode != 5 && mode != 6) return;
    char* mon = (char*)self + 0x118;
    if (*(int*)((char*)self + 0x530) != 0) {
        sSaVt72A8* vt = *(sSaVt72A8**)((char*)self + 0x5558);
        vt[4].fn(mon + vt[4].delta, 0);
    } else {
        func_0028D488(self);
        func_0028CF98(self, 0, 0, -1, 0);
    }
    if (func_00295028(self, 0, 0) != 0) return;
    signed char* g2 = (signed char*)D_00535BC8;
    int a = g2[0x4A];
    if (a == 4 || a == 5) {
        if (g2[0x49] != 2) {
            *(int*)((char*)self + 0x5788) = 1;
        } else {
            func_002A26F0(self, 0, 0);
            func_002B1758((char*)self + 0x5560, 0);
        }
    }
    *(int*)((char*)self + 0x5774) = 1;
    *(int*)((char*)self + 0x5778) = func_002B4908(mon);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002873D8);
#ifdef SKIP_ASM
// PORT: real arity is (self, n); the unit declares func_002873D8(void*) for its callers.
// PORT: g++ `<?` (min) operator, removed in GCC 4.3.
static inline float clamp_73D8(float f, float lo, float hi)
{
    if (f >= lo) {
        return f <? hi;
    }
    return lo;
}

extern "C" float func_002873D8_impl(void* self, int n) __asm__("func_002873D8");
extern "C" float func_002873D8_impl(void* self, int n)
{
    return clamp_73D8(n * 0.09090909361839294f, 0.0f, 1.0f);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_00287410);
#ifdef SKIP_ASM
extern "C" float func_002873D8(void*);
// PORT: func_00287700's real parameter order is (self, int, float); the unit declares (self, float, int).
void func_00287700_if(void*, int, float) __asm__("func_00287700");

extern "C" void func_00287410(void* self)
{
    float v = func_002873D8(self);
    func_00287700_if(self, 1, v);
    func_00287700_if(self, 8, v);
    if (*(int*)((char*)self + 0x62B8) != 0 && *(int*)((char*)self + 0x608C) != 2) {
        func_00287700_if(self, 2, v);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_00287488);
#ifdef SKIP_ASM
extern "C" float func_002873D8(void*);
// PORT: func_00287700's real parameter order is (self, int, float); the unit declares (self, float, int).
void func_00287700_if(void*, int, float) __asm__("func_00287700");

extern "C" void func_00287488(void* self)
{
    float v = func_002873D8(self);
    func_00287700_if(self, 5, v);
    func_00287700_if(self, 3, v);
    func_00287700_if(self, 6, v);
    func_00287700_if(self, 7, v);
    if (*(int*)((char*)self + 0x62B4) != 0) {
        func_00287700_if(self, 9, v);
        func_00287700_if(self, 10, v);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_00287520);
#ifdef SKIP_ASM
extern "C" float func_002873D8(void*);
extern "C" void func_00287700(void*, float, int);

extern "C" void func_00287520(void* self)
{
    func_00287700(self, func_002873D8(self), 4);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287558);
#ifdef SKIP_ASM
extern "C" void func_00287700(void*, float, int);
extern "C" float func_00287920(void* self, int a1);

extern "C" void func_00287558(void* self, int on)
{
    if (on != 0 && *(int*)((char*)self + 0x608C) != 2 && *(int*)((char*)self + 0x608C) != 3) {
        func_00287700(self, func_00287920(self, 1), 2);
        *(int*)((char*)self + 0x62B8) = 1;
    } else {
        func_00287700(self, 0.0f, 2);
        *(int*)((char*)self + 0x62B8) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002875D0);
#ifdef SKIP_ASM
extern "C" void func_00287700(void*, float, int);
extern "C" float func_00287920(void* self, int a1);

extern "C" void func_002875D0(void* self, int on)
{
    if (on != 0) {
        func_00287700(self, func_00287920(self, 5), 9);
        func_00287700(self, func_00287920(self, 5), 10);
    } else {
        func_00287700(self, 0.0f, 9);
        func_00287700(self, 0.0f, 10);
    }
    *(int*)((char*)self + 0x62B4) = on;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287670);
#ifdef SKIP_ASM
extern "C" float func_00287920(void* self, int a1);

extern "C" int func_00287670(void* self)
{
    return (int)(func_00287920(self, 1) * 11.0f);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002876A0);
#ifdef SKIP_ASM
extern "C" float func_00287920(void* self, int a1);

extern "C" int func_002876A0(void* self)
{
    return (int)(func_00287920(self, 5) * 11.0f);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002876D0);
#ifdef SKIP_ASM
extern "C" float func_00287920(void* self, int a1);

extern "C" int func_002876D0(void* self)
{
    return (int)(func_00287920(self, 4) * 11.0f);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287700);
#ifdef SKIP_ASM
extern float D_004A3504;
extern float D_004A3508;
extern float D_004A350C;
extern float D_004A3510;
extern float D_004A3514;
extern float D_004A3518;
extern float D_004A351C;
extern float D_004A3520;
extern float D_004A3524;
extern float D_004A3528;
extern float D_004A352C;
extern float D_004A3530;
extern float D_004A3534;
extern float D_004A3538;
extern float D_004A353C;
extern float D_004A3540;
extern float D_004A3544;
extern float D_004A3548;
extern float D_004A354C;
extern float D_004A3550;
extern "C" void func_002B4388(void* mon);
extern "C" void func_003B8160(signed char vol);

struct sSaChan7700 {
    float user;     // +0x0
    float base;     // +0x4
    float gain;     // +0x8
    float out;      // +0xC
};

struct sSaMix7700 {
    char pad0[0x62BC];
    sSaChan7700 chan[11];   // 0x62BC
    char pad636C[0x636C - 0x636C];
    float mix[10];          // 0x636C
    char pad6394[0x6394 - 0x6394];
    float vol[11];          // 0x6394
    char pad63C0[0x63E4 - 0x63C0];
    float cur[11];          // 0x63E4
};

// PORT: `<?`/`>?` are the g++ min/max operators (EE min.s/max.s).
extern "C" void func_00287700(void* self_, float v, int ch)
{
    sSaMix7700* self = (sSaMix7700*)self_;
    v = (v <? 1.0f) >? 0.0f;
    sSaChan7700* c = &self->chan[ch];
    switch (ch) {
    case 0:
        c->user = v;
        c->base = v;
        break;
    case 1:
        c->user = v;
        c->base = v * D_004A3508;
        func_002B4388((char*)self + 0x118);
        break;
    case 2:
        c->user = v;
        c->base = v * D_004A3510;
        break;
    case 3:
        c->user = v;
        c->base = v * D_004A3514;
        break;
    case 4:
        c->user = v;
        c->base = v * D_004A350C;
        break;
    case 5:
        c->user = v;
        c->base = v * D_004A3504;
        break;
    case 6:
        c->user = v;
        c->base = v * D_004A3518;
        break;
    case 7:
        c->user = v;
        c->base = v * D_004A351C;
        break;
    case 8:
        c->user = v;
        c->base = v * D_004A3520;
        break;
    case 9:
        c->user = v;
        c->base = v * D_004A3524;
        break;
    case 10:
        c->user = v;
        c->base = v * D_004A3528;
        break;
    }
    c->gain = c->base * self->vol[ch];
    c->out = c->gain * self->cur[ch];
    switch (ch) {
    case 0:
        func_003B8160((int)(c->out * 127.0f));
        break;
    case 1:
        func_002B4388((char*)self + 0x118);
        break;
    case 4:
        self->mix[0] = c->out * D_004A352C;
        self->mix[1] = c->out * D_004A3530;
        self->mix[2] = c->out * D_004A3534;
        self->mix[3] = c->out * D_004A3538;
        self->mix[4] = c->out * D_004A353C;
        self->mix[5] = c->out * D_004A3540;
        self->mix[6] = c->out * D_004A3544;
        self->mix[7] = c->out * D_004A3548;
        self->mix[8] = c->out * D_004A354C;
        self->mix[9] = c->out * D_004A3550;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287920);
#ifdef SKIP_ASM
extern "C" float func_00287920(void* self, int a1)
{
    self = (char*)self + (a1 << 4);
    return *(float*)((char*)self + 0x62bc);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287930);
#ifdef SKIP_ASM
extern "C" float func_00287930(void* self, int a1, int a2)
{
    if (a1 != 4 || a2 >= 10) {
        return *(float*)((char*)self + (a1 << 4) + 0x62C8);
    }
    return *(float*)((char*)self + (a2 << 2) + 0x636C);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287968);
#ifdef SKIP_ASM
extern "C" void* func_00287968(void* self, int a1, int a2)
{
    if (a1 != 4 || a2 >= 10) {
        // PORT: pointer held in int (only spelling found that gives idx-first addu)
        return (char*)((a1 << 4) + (int)self + 0x62C8);
    }
    return (char*)self + ((a2 << 2) + 0x636C);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002879A0);
#ifdef SKIP_ASM
extern "C" void* func_002879A0(void* self, int a1)
{
    return (char*)self + ((a1 << 4) + 0x62BC);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002879B0);
#ifdef SKIP_ASM
extern "C" void func_002879B0(void* self, int ch)
{
    func_00287700(self, *(float*)((char*)self + (ch << 4) + 0x62BC) + 0.09090909f, ch);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002879E0);
#ifdef SKIP_ASM
extern "C" void func_002879E0(void* self, int ch)
{
    func_00287700(self, *(float*)((char*)self + (ch << 4) + 0x62BC) - 0.09090909f, ch);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287A10);
#ifdef SKIP_ASM
extern float D_004A352C;
extern float D_004A3530;
extern float D_004A3534;
extern float D_004A3538;
extern float D_004A353C;
extern float D_004A3540;
extern float D_004A3544;
extern float D_004A3548;
extern float D_004A354C;
extern float D_004A3550;

struct sSaChan7A10 {
    float base;     // +0x0
    float gain;     // +0x4
    float out;      // +0x8
    float pad;
};

struct sSaMixOut7A10 {
    char pad0[0x636C];
    float mix[10];          // 0x636C
};

struct sSaMix7A10 {
    char pad0[0x62C0];
    sSaChan7A10 chan[11];   // 0x62C0 (chan[10].pad overlaps mix[0])
    char pad6370[0x6398 - 0x6370];
    float vol[10];          // 0x6398 (vol[j-1])
    int fading;             // 0x63C0
    int fadeMask;           // 0x63C4
    float fadeRate;         // 0x63C8
    float fadeTarget;       // 0x63CC
    float fadeCur;          // 0x63D0
    char pad63D4[0x63E8 - 0x63D4];
    float cur[10];          // 0x63E8 (cur[j-1])
};

static inline void sSaMix7A10_set(sSaMix7A10* s, int j, float v)
{
    s->vol[j - 1] = v;
    s->chan[j].gain = s->chan[j].base * v;
    s->chan[j].out = s->chan[j].gain * s->cur[j - 1];
}

extern "C" void func_00287A10(void* self_, int mask, float v, float time)
{
    sSaMix7A10* self = (sSaMix7A10*)self_;
    if (time == 0.0f) {
        if (mask & 1)
            sSaMix7A10_set(self, 1, v);
        if (mask & 2)
            sSaMix7A10_set(self, 5, v);
        if (mask & 4) {
            sSaMix7A10_set(self, 4, v);
            float m = self->chan[4].out;
            sSaMixOut7A10* o = (sSaMixOut7A10*)self;
            o->mix[0] = m * D_004A352C;
            o->mix[1] = m * D_004A3530;
            o->mix[2] = m * D_004A3534;
            o->mix[3] = m * D_004A3538;
            o->mix[4] = m * D_004A353C;
            o->mix[5] = m * D_004A3540;
            o->mix[6] = m * D_004A3544;
            o->mix[7] = m * D_004A3548;
            o->mix[8] = m * D_004A354C;
            o->mix[9] = m * D_004A3550;
        }
        if (mask & 8)
            sSaMix7A10_set(self, 2, v);
        if (mask & 0x80)
            sSaMix7A10_set(self, 3, v);
        if (mask & 0x20)
            sSaMix7A10_set(self, 6, v);
        if (mask & 0x40)
            sSaMix7A10_set(self, 7, v);
        if (mask & 0x10)
            sSaMix7A10_set(self, 8, v);
        if (mask & 0x100)
            sSaMix7A10_set(self, 9, v);
        if (mask & 0x200)
            sSaMix7A10_set(self, 10, v);
    } else {
        self->fadeMask = mask;
        self->fadeTarget = v;
        self->fadeRate = (v - self->fadeCur) / time * 0.01666666753590107f;
        if (self->fadeRate != 0.0f)
            self->fading = 1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287C48);
#ifdef SKIP_ASM
extern float D_004A352C;
extern float D_004A3530;
extern float D_004A3534;
extern float D_004A3538;
extern float D_004A353C;
extern float D_004A3540;
extern float D_004A3544;
extern float D_004A3548;
extern float D_004A354C;
extern float D_004A3550;

struct sSaChan7C48 {
    float base;     // +0x0
    float gain;     // +0x4
    float out;      // +0x8
    float pad;
};

struct sSaMixOut7C48 {
    char pad0[0x636C];
    float mix[10];          // 0x636C
};

struct sSaMix7C48 {
    char pad0[0x62C0];
    sSaChan7C48 chan[11];   // 0x62C0 (chan[10].pad overlaps mix[0])
    char pad6370[0x6398 - 0x6370];
    float vol[10];          // 0x6398 (vol[j-1])
    int fading;             // 0x63C0
    int fadeMask;           // 0x63C4
    float fadeRate;         // 0x63C8
    float fadeTarget;       // 0x63CC
    float fadeCur;          // 0x63D0
    char pad63D4[0x63E8 - 0x63D4];
    float cur[10];          // 0x63E8 (cur[j-1])
};

static inline void sSaMix7C48_set(sSaMix7C48* s, int j, float v)
{
    s->vol[j - 1] = v;
    s->chan[j].gain = s->chan[j].base * v;
    s->chan[j].out = s->chan[j].gain * s->cur[j - 1];
}

extern "C" void func_00287C48(void* self_)
{
    sSaMix7C48* self = (sSaMix7C48*)self_;
    if (self->fading) {
        self->fadeCur += self->fadeRate;
        if (self->fadeRate < 0.0f) {
            if (self->fadeCur < self->fadeTarget) {
                self->fadeCur = self->fadeTarget;
                self->fading = 0;
            }
        } else if (self->fadeCur > self->fadeTarget) {
            self->fadeCur = self->fadeTarget;
            self->fading = 0;
        }
        if (self->fadeMask & 1)
            sSaMix7C48_set(self, 1, self->fadeCur);
        if (self->fadeMask & 2)
            sSaMix7C48_set(self, 5, self->fadeCur);
        if (self->fadeMask & 4) {
            sSaMix7C48_set(self, 4, self->fadeCur);
            float m = self->chan[4].out;
            sSaMixOut7C48* o = (sSaMixOut7C48*)self;
            o->mix[0] = m * D_004A352C;
            o->mix[1] = m * D_004A3530;
            o->mix[2] = m * D_004A3534;
            o->mix[3] = m * D_004A3538;
            o->mix[4] = m * D_004A353C;
            o->mix[5] = m * D_004A3540;
            o->mix[6] = m * D_004A3544;
            o->mix[7] = m * D_004A3548;
            o->mix[8] = m * D_004A354C;
            o->mix[9] = m * D_004A3550;
        }
        if (self->fadeMask & 8)
            sSaMix7C48_set(self, 2, self->fadeCur);
        if (self->fadeMask & 0x80)
            sSaMix7C48_set(self, 3, self->fadeCur);
        if (self->fadeMask & 0x20)
            sSaMix7C48_set(self, 6, self->fadeCur);
        if (self->fadeMask & 0x40)
            sSaMix7C48_set(self, 7, self->fadeCur);
        if (self->fadeMask & 0x10)
            sSaMix7C48_set(self, 8, self->fadeCur);
        if (self->fadeMask & 0x100)
            sSaMix7C48_set(self, 9, self->fadeCur);
        if (self->fadeMask & 0x200)
            sSaMix7C48_set(self, 10, self->fadeCur);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_00287F00);
#ifdef SKIP_ASM
extern "C" void func_00287A10(void* self, int a1, float a2, float a3);
extern "C" int func_00284BA0(int);

extern "C" void func_00287F00(void* self, int a1, float f0, float f1)
{
    if (a1 == 3) {
        if (*(int*)((char*)self + 0x63DC) != 0) {
            func_00287A10(self, func_00284BA0(*(int*)((char*)self + 0x63D4)), 1.0f, f0);
            *(float*)((char*)self + 0x63D8) = f1;
            *(int*)((char*)self + 0x63D4) = a1;
            *(int*)((char*)self + 0x63DC) = 0;
        }
    } else if (*(int*)((char*)self + 0x63DC) == 0) {
        func_00287A10(self, func_00284BA0(a1), f1, f0);
        *(int*)((char*)self + 0x63D4) = a1;
        *(int*)((char*)self + 0x63DC) = 1;
        *(float*)((char*)self + 0x63D8) = f1;
        *(int*)((char*)self + 0x63E0) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00287FC8);
#ifdef SKIP_ASM
// PORT: func_002A77F8 returns a value (the unit declares it void); bound by asm label.
extern "C" void* func_002A77F8_r(void* self, char* name, int size) __asm__("func_002A77F8");
extern "C" void func_002A7890(void* self, int flags);
extern "C" char* func_002A7B08(void* self);
extern "C" char* func_002A7DA0(void* self);
extern "C" int func_002A7F90(void* self);
extern "C" int func_002A80D8(void* self, const char* key, int* out);
extern "C" int func_0041AA88(const char* a, const char* b);
extern char* D_004A3560;
extern char D_004A35D8[];
extern char D_004A35E0[];
extern char D_004A35E8[];
extern char D_00482930[];
extern char D_004A35B0[];
extern char D_00482940[];
extern char D_004A35F0[];
extern char D_00482950[];
extern char D_00482960[];
extern char D_004A35F8[];

struct sIniParser7FC8 {
    int f0;
    char* start;    // 0x4
    char* cur;      // 0x8
    char pad[0x810 - 0xC];
};

struct sSfxEntry7FC8 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    float f24;
};

struct sAudio7FC8 {
    char pad[0x6478];
    int count;                      // 0x6478
    sSfxEntry7FC8 entries[25];      // 0x647C
};

extern "C" void func_00287FC8(sAudio7FC8* self)
{
    sIniParser7FC8 parser;
    int val;
    self->count = 0;
    func_002A77F8_r(&parser, D_004A3560, 0x100);
    parser.cur = parser.start;
    for (int i = 0; i < 25; i++) {
        self->entries[i].f0 = 100;
        self->entries[i].f4 = 100;
        self->entries[i].f8 = 100;
        self->entries[i].fC = 100;
        self->entries[i].f10 = 100;
        self->entries[i].f14 = 100;
        self->entries[i].f18 = 100;
        self->entries[i].f1C = 100;
        self->entries[i].f20 = 100;
        self->entries[i].f24 = 0.0f;
    }
    while (self->count < 25 && func_002A7B08(&parser) != 0) {
        while (func_002A7F90(&parser) == 0) {
            char* key = func_002A7DA0(&parser);
            if (func_0041AA88(key, D_004A35D8) == 0) {
                func_002A80D8(&parser, D_004A35D8, &val);
                self->entries[self->count].f0 = val;
            } else if (func_0041AA88(key, D_004A35E0) == 0) {
                func_002A80D8(&parser, D_004A35E0, &val);
                self->entries[self->count].f4 = val;
            } else if (func_0041AA88(key, D_004A35E8) == 0) {
                func_002A80D8(&parser, D_004A35E8, &val);
                self->entries[self->count].f8 = val;
            } else if (func_0041AA88(key, D_00482930) == 0) {
                func_002A80D8(&parser, D_00482930, &val);
                self->entries[self->count].fC = val;
            } else if (func_0041AA88(key, D_004A35B0) == 0) {
                func_002A80D8(&parser, D_004A35B0, &val);
                self->entries[self->count].f10 = val;
            } else if (func_0041AA88(key, D_00482940) == 0) {
                func_002A80D8(&parser, D_00482940, &val);
                self->entries[self->count].f14 = val;
            } else if (func_0041AA88(key, D_004A35F0) == 0) {
                func_002A80D8(&parser, D_004A35F0, &val);
                self->entries[self->count].f18 = val;
            } else if (func_0041AA88(key, D_00482950) == 0) {
                func_002A80D8(&parser, D_00482950, &val);
                self->entries[self->count].f1C = val;
            } else if (func_0041AA88(key, D_00482960) == 0) {
                func_002A80D8(&parser, D_00482960, &val);
                self->entries[self->count].f20 = val;
            } else if (func_0041AA88(key, D_004A35F8) == 0) {
                func_002A80D8(&parser, D_004A35F8, &val);
                self->entries[self->count].f24 = (float)val * 0.0010000000474974513f;
            }
        }
        self->count++;
    }
    func_002A7890(&parser, 2);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288370);
#ifdef SKIP_ASM
extern "C" float func_00288370(void* self, int i, int pct)
{
    if (pct >= 0) {
        return pct * 0.009999999776482582f;
    }
    if (*(int*)((char*)self + 0x6410) != 0) {
        return *(float*)((char*)self + (i << 2) + 0x6440);
    }
    return *(float*)((char*)self + (i << 2) + 0x63E4);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002883B0);
#ifdef SKIP_ASM
extern "C" float func_00288370(void* self, int i, int pct);
struct sAudioFade_87A8;
extern "C" void func_002887A8(sAudioFade_87A8* self, int i, int smooth, float target, float time);
extern float D_004A352C;
extern float D_004A3530;
extern float D_004A3534;
extern float D_004A3538;
extern float D_004A353C;
extern float D_004A3540;
extern float D_004A3544;
extern float D_004A3548;
extern float D_004A354C;
extern float D_004A3550;

struct sSaChan83B0 {
    float base;     // +0x0
    float gain;     // +0x4
    float out;      // +0x8
    float pad;
};

struct sSfxEntry83B0 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    float f24;
};

struct sSaMixOut83B0 {
    char pad0[0x636C];
    float mix[10];          // 0x636C
};

struct sAudio83B0 {
    char pad0[0x62C0];
    sSaChan83B0 chan[11];   // 0x62C0
    char pad6370[0x63E4 - 0x6370];
    float cur[11];          // 0x63E4
    int faded;              // 0x6410
    char pad6414[0x646C - 0x6414];
    int preset;             // 0x646C
    char pad6470[0x647C - 0x6470];
    sSfxEntry83B0 entries[25];      // 0x647C
};

extern "C" void func_002883B0(void* vself, int id)
{
    sAudio83B0* self = (sAudio83B0*)vself;
    if (id < 0) {
        id = 0;
    }
    if (id == self->preset) {
        return;
    }
    self->preset = id;
    float v1 = func_00288370(self, 1, self->entries[id].f0);
    float v2 = func_00288370(self, 2, self->entries[id].f4);
    float v3 = func_00288370(self, 3, self->entries[id].f8);
    float v4 = func_00288370(self, 4, self->entries[id].fC);
    float v6 = func_00288370(self, 6, self->entries[id].f10);
    float v7 = func_00288370(self, 7, self->entries[id].f14);
    float v8 = func_00288370(self, 8, self->entries[id].f18);
    float v9 = func_00288370(self, 9, self->entries[id].f1C);
    float v10 = func_00288370(self, 10, self->entries[id].f20);
    float t = self->entries[id].f24;
    if (t == 0.0f) {
        self->cur[1] = v1;
        self->cur[2] = v2;
        self->cur[3] = v3;
        self->cur[4] = v4;
        self->cur[6] = v6;
        self->cur[7] = v7;
        self->cur[8] = v8;
        self->cur[9] = v9;
        self->cur[10] = v10;
        for (int k = 0; k < 11; k++) {
            self->chan[k].out = self->chan[k].gain * self->cur[k];
        }
        float m = self->chan[4].out;
        sSaMixOut83B0* o = (sSaMixOut83B0*)self;
        o->mix[0] = m * D_004A352C;
        o->mix[1] = m * D_004A3530;
        o->mix[2] = m * D_004A3534;
        o->mix[3] = m * D_004A3538;
        o->mix[4] = m * D_004A353C;
        o->mix[5] = m * D_004A3540;
        o->mix[6] = m * D_004A3544;
        o->mix[7] = m * D_004A3548;
        o->mix[8] = m * D_004A354C;
        o->mix[9] = m * D_004A3550;
    } else {
        sAudioFade_87A8* f = (sAudioFade_87A8*)self;
        func_002887A8(f, 1, self->entries[id].f0 != -1, v1, t);
        func_002887A8(f, 2, self->entries[id].f4 != -1, v2, t);
        func_002887A8(f, 3, self->entries[id].f8 != -1, v3, t);
        func_002887A8(f, 4, self->entries[id].fC != -1, v4, t);
        func_002887A8(f, 6, self->entries[id].f10 != -1, v6, t);
        func_002887A8(f, 7, self->entries[id].f14 != -1, v7, t);
        func_002887A8(f, 8, self->entries[id].f18 != -1, v8, t);
        func_002887A8(f, 9, self->entries[id].f1C != -1, v9, t);
        func_002887A8(f, 10, self->entries[id].f20 != -1, v10, t);
        self->faded = 1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002887A8);
#ifdef SKIP_ASM
struct sAudioFade_87A8 {
    char pad[0x63E4];
    float cur[12];     // 0x63E4
    float rate[11];    // 0x6414
    float target[11];  // 0x6440
};

extern "C" void func_002887A8(sAudioFade_87A8* self, int i, int smooth, float target, float time)
{
    self->target[i] = target;
    float cur = self->cur[i];
    if (target != cur) {
        if (smooth != 0) {
            self->rate[i] = (target - cur) / time * 0.01666666753590107f;
        }
    } else {
        self->rate[i] = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002887F8);
#ifdef SKIP_ASM
extern float D_004A352C;
extern float D_004A3530;
extern float D_004A3534;
extern float D_004A3538;
extern float D_004A353C;
extern float D_004A3540;
extern float D_004A3544;
extern float D_004A3548;
extern float D_004A354C;
extern float D_004A3550;

struct sSaMix87F8 {
    char pad0[0x62C4];
    float chan[11][4];          // 0x62C4 (gain, out, -, -)
    char pad6374[0x63E4 - 0x6374];
    float cur[11];              // 0x63E4
    int dirty;                  // 0x6410
    float delta[11];            // 0x6414
    float target[11];           // 0x6440
};

struct sSaMixOut87F8 {
    char pad0[0x6308];
    float master;               // 0x6308
    char pad630C[0x636C - 0x630C];
    float out[10];              // 0x636C
};

extern "C" void func_002887F8(sSaMix87F8* self)
{
    if (self->dirty == 0) return;
    self->dirty = 0;
    for (int i = 0; i < 11; i++) {
        if (self->delta[i] == 0.0f) continue;
        float v = self->cur[i] + self->delta[i];
        self->cur[i] = v;
        if (self->delta[i] < 0.0f) {
            if (v <= self->target[i]) {
                self->cur[i] = self->target[i];
                self->delta[i] = 0.0f;
            } else {
                self->dirty = 1;
            }
        } else {
            if (self->target[i] <= v) {
                self->cur[i] = self->target[i];
                self->delta[i] = 0.0f;
            } else {
                self->dirty = 1;
            }
        }
        self->chan[i][1] = self->chan[i][0] * self->cur[i];
    }
    sSaMixOut87F8* o = (sSaMixOut87F8*)self;
    float m = o->master;
    o->out[0] = m * D_004A352C;
    o->out[1] = m * D_004A3530;
    o->out[2] = m * D_004A3534;
    o->out[3] = m * D_004A3538;
    o->out[4] = m * D_004A353C;
    o->out[5] = m * D_004A3540;
    o->out[6] = m * D_004A3544;
    o->out[7] = m * D_004A3548;
    o->out[8] = m * D_004A354C;
    o->out[9] = m * D_004A3550;
}
#endif

INCLUDE_ASM("sound/ssxAudio", func_00288940);

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288A20);
#ifdef SKIP_ASM
extern "C" int func_0028B1B0(void);
extern "C" int func_00288940(void* self, int id);
// PORT: callers pass self, but func_00288CE8's body takes no arguments (the unit declares it ()).
int func_00288CE8_self(void* self) __asm__("func_00288CE8");

struct sAudVtEnt { short delta; short index; int (*fn)(void*); };

extern "C" int func_00288A20(void* self, void* obj)
{
    if (func_0028B1B0() == 0) {
        return 0;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        return *(int*)((char*)obj + 0x870);
    }
    if (func_00288CE8_self(self) == 1) {
        return 0;
    }
    char* o = (char*)obj + 0x6C0;
    sAudVtEnt* e = &(*(sAudVtEnt**)o)[5];
    return func_00288940(self, e->fn(o + e->delta));
}
#endif

extern "C" void* func_0028B210(int);

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288AC0__FPvi);
#ifdef SKIP_ASM
void* func_00288AC0(void* self, int a1)
{
    return (char*)func_0028B210(a1) + 0x20;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288AE0);
#ifdef SKIP_ASM
extern "C" int func_0028B1B0(void);
extern "C" void* func_0028B1C8();

extern "C" int func_00288AE0(void* self)
{
    if (func_0028B1B0() != 0) {
        if (*(int**)((char*)func_0028B1C8() + 0x28) != 0) {
            int v = **(int**)((char*)func_0028B1C8() + 0x28);
            int busy = v != 0 && v < 10;
            if (busy) {
                return 1;
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288B40);
#ifdef SKIP_ASM
struct sAudV4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

void* func_00288AC0(void* self, int a1);

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sAudV4 audVu0Sub(const sAudV4& a, const sAudV4& b)
{
    sAudV4 r;
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float audVu0Dot(const sAudV4& a, const sAudV4& b)
{
    float r;
    int t;
    __asm__ __volatile__(
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

extern "C" int func_00288B40(void* self, sAudV4* pos, float radius)
{
    float r = radius * 100.0f;
    r = r * r;
    int i;
    for (i = 0; i < func_00288CE8_self(self); i++) {
        sAudV4 d = audVu0Sub(*(sAudV4*)func_00288AC0(self, i), *pos);
        if (audVu0Dot(d, d) < r) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288C08);
#ifdef SKIP_ASM
void* func_00288AC0(void* self, int a1);

// PORT: PS2-only VU0 inline asm (vector subtract).
// PORT: PS2-only VU0 inline asm (4-component dot product).
extern "C" int func_00288C08(void* self, sAudV4* pos, float radius)
{
    float r = radius * 100.0f;
    r = r * r;
    int i;
    for (i = 0; i < func_00288CE8_self(self); i++) {
        sAudV4 d = audVu0Sub(*(sAudV4*)func_00288AC0(self, i), *pos);
        if (audVu0Dot(d, d) < r && 0.0f < d.z) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288CE8);
#ifdef SKIP_ASM
extern "C" void* func_0028B1C0();
extern "C" int func_0028B1F8();

extern "C" int func_00288CE8()
{
    if (*(int*)((char*)func_0028B1C0() + 0x84) != 0) {
        return func_0028B1F8();
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288D18);
#ifdef SKIP_ASM
extern float D_004A3504;
extern float D_004A3508;
extern float D_004A350C;
extern float D_004A3510;
extern float D_004A3514;
extern float D_004A3518;
extern float D_004A351C;
extern float D_004A3520;
extern float D_004A3524;
extern float D_004A3528;
extern float D_004A352C;
extern float D_004A3530;
extern float D_004A3534;
extern float D_004A3538;
extern float D_004A353C;
extern float D_004A3540;
extern float D_004A3544;
extern float D_004A3548;
extern float D_004A354C;
extern float D_004A3550;
extern "C" void func_00287700(void*, float, int);
extern "C" float func_00287920(void* self, int a1);

extern "C" void func_00288D18(void* self, int mode)
{
    if (mode == 0) {
        D_004A3504 = 1.0f;
        D_004A3508 = 1.0f;
        D_004A350C = 0.5999999642372131f;
        D_004A3510 = 1.0f;
        D_004A3514 = 1.0f;
        D_004A3518 = 1.0f;
        D_004A351C = 1.0f;
        D_004A3520 = 1.0f;
        D_004A3524 = 1.0f;
        D_004A3528 = 1.0f;
        D_004A352C = 1.0f;
        D_004A3530 = 1.0f;
        D_004A3534 = 1.0f;
        D_004A3538 = 1.0f;
        D_004A353C = 1.0f;
        D_004A3540 = 1.0f;
        D_004A3544 = 1.0f;
        D_004A3548 = 1.0f;
        D_004A354C = 1.0f;
        D_004A3550 = 1.0f;
    } else if (mode == 1) {
        D_004A3504 = 0.7999999523162842f;
        D_004A3508 = 1.0f;
        D_004A350C = 0.7999999523162842f;
        D_004A3510 = 0.550000011920929f;
        D_004A3514 = 0.429999977350235f;
        D_004A3518 = 0.75f;
        D_004A351C = 0.7999999523162842f;
        D_004A3520 = 0.5f;
        D_004A3524 = 0.75f;
        D_004A3528 = 0.75f;
        D_004A352C = 0.8999999761581421f;
        D_004A3530 = 0.8999999761581421f;
        D_004A3534 = 0.8999999761581421f;
        D_004A3538 = 0.8999999761581421f;
        D_004A353C = 0.7999999523162842f;
        D_004A3540 = 0.8499999642372131f;
        D_004A3544 = 0.8999999761581421f;
        D_004A3548 = 1.0f;
        D_004A354C = 1.0f;
        D_004A3550 = 0.949999988079071f;
    }
    func_00287700(self, func_00287920(self, 0), 0);
    func_00287700(self, func_00287920(self, 1), 1);
    func_00287700(self, func_00287920(self, 2), 2);
    func_00287700(self, func_00287920(self, 3), 3);
    func_00287700(self, func_00287920(self, 4), 4);
    func_00287700(self, func_00287920(self, 5), 5);
    func_00287700(self, func_00287920(self, 6), 6);
    func_00287700(self, func_00287920(self, 7), 7);
    func_00287700(self, func_00287920(self, 8), 8);
    func_00287700(self, func_00287920(self, 9), 9);
    func_00287700(self, func_00287920(self, 10), 10);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00288F60);
#ifdef SKIP_ASM
// PORT: func_00287700's real parameter order is (self, int, float); the unit declares (self, float, int).
void func_00287700_if(void*, int, float) __asm__("func_00287700");

extern "C" void func_00288F60(void* self, int mode)
{
    *(int*)((char*)self + 0x6470) = mode;
    switch (mode) {
    case 0:
        func_00287700_if(self, 1, 0.9090909361839294f);
        func_00287700_if(self, 5, 0.9090909361839294f);
        func_00287700_if(self, 2, 0.9090909361839294f);
        func_00287700_if(self, 3, 0.9090909361839294f);
        func_00287700_if(self, 4, 0.9090909361839294f);
        func_00287700_if(self, 6, 0.9090909361839294f);
        func_00287700_if(self, 7, 0.9090909361839294f);
        func_00287700_if(self, 8, 0.9090909361839294f);
        func_00287700_if(self, 9, 0.9090909361839294f);
        func_00287700_if(self, 10, 0.9090909361839294f);
        func_002875D0(self, 1);
        break;
    case 1:
        func_00287700_if(self, 1, 0.9090909361839294f);
        func_00287700_if(self, 5, 0.9090909361839294f);
        func_00287700_if(self, 2, 0.0f);
        func_00287700_if(self, 3, 0.0f);
        func_00287700_if(self, 4, 0.0f);
        func_00287700_if(self, 6, 0.9090909361839294f);
        func_00287700_if(self, 7, 0.9090909361839294f);
        func_00287700_if(self, 8, 0.9090909361839294f);
        func_00287700_if(self, 9, 0.0f);
        func_00287700_if(self, 10, 0.0f);
        func_002875D0(self, 1);
        break;
    case 2:
        func_00287700_if(self, 1, 0.0f);
        func_00287700_if(self, 5, 0.9090909361839294f);
        func_00287700_if(self, 2, 0.9090909361839294f);
        func_00287700_if(self, 3, 0.9090909361839294f);
        func_00287700_if(self, 4, 0.9090909361839294f);
        func_00287700_if(self, 6, 0.9090909361839294f);
        func_00287700_if(self, 7, 0.9090909361839294f);
        func_00287700_if(self, 8, 0.9090909361839294f);
        func_00287700_if(self, 9, 0.9090909361839294f);
        func_00287700_if(self, 10, 0.9090909361839294f);
        func_002875D0(self, 1);
        break;
    case 3:
        func_00287700_if(self, 1, 0.0f);
        func_00287700_if(self, 5, 0.9090909361839294f);
        func_00287700_if(self, 2, 0.0f);
        func_00287700_if(self, 3, 0.0f);
        func_00287700_if(self, 4, 0.0f);
        func_00287700_if(self, 6, 0.9090909361839294f);
        func_00287700_if(self, 7, 0.9090909361839294f);
        func_00287700_if(self, 8, 0.9090909361839294f);
        func_00287700_if(self, 9, 0.0f);
        func_00287700_if(self, 10, 0.0f);
        func_002875D0(self, 1);
        break;
    case 4:
        func_00287700_if(self, 1, 0.9090909361839294f);
        func_00287700_if(self, 5, 0.0f);
        func_00287700_if(self, 2, 0.0f);
        func_00287700_if(self, 3, 0.0f);
        func_00287700_if(self, 4, 0.0f);
        func_00287700_if(self, 6, 0.0f);
        func_00287700_if(self, 7, 0.0f);
        func_00287700_if(self, 8, 0.0f);
        func_00287700_if(self, 9, 0.0f);
        func_00287700_if(self, 10, 0.0f);
        func_002875D0(self, 0);
        break;
    case 5:
        func_00287700_if(self, 1, 0.0f);
        func_00287700_if(self, 5, 0.0f);
        func_00287700_if(self, 2, 0.0f);
        func_00287700_if(self, 3, 0.0f);
        func_00287700_if(self, 4, 0.0f);
        func_00287700_if(self, 6, 0.0f);
        func_00287700_if(self, 7, 0.0f);
        func_00287700_if(self, 8, 0.0f);
        func_00287700_if(self, 9, 0.0f);
        func_00287700_if(self, 10, 0.0f);
        func_002875D0(self, 0);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289398);
#ifdef SKIP_ASM
extern "C" void func_00289398(char* self)
{
    if (*(int*)(self + 0x6470) == 0) {
        *(int*)(self + 0x6470) = 5;
    } else {
        *(int*)(self + 0x6470) = *(int*)(self + 0x6470) - 1;
    }
    func_00288F60(self, *(int*)(self + 0x6470));
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002893C8);
#ifdef SKIP_ASM
extern "C" void func_002893C8(char* self)
{
    *(int*)(self + 0x6470) = *(int*)(self + 0x6470) + 1;
    if (*(int*)(self + 0x6470) == 6) {
        *(int*)(self + 0x6470) = 0;
    }
    func_00288F60(self, *(int*)(self + 0x6470));
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289400);
#ifdef SKIP_ASM
struct func_00289400_key { long v; } __attribute__((packed));
extern func_00289400_key D_004A3600[];
extern "C" int func_002ADCA0_k(void*, int, long, int, int, int, int, int) __asm__("func_002ADCA0");

extern "C" void func_00289400(char* self)
{
    func_002ADCA0_k(**(char***)(self + 0x118) + 0x1D8, 0xFA, D_004A3600[0].v, 0, 0, 0, 0, 0);
}
#endif
//100%
INCLUDE_ASM("sound/ssxAudio", func_00289448);
#ifdef SKIP_ASM
extern "C" void func_002B6950(int, int, int);

extern "C" int func_00289448(void) {
    func_002B6950((*(int*)&D_004A52D4), 1, 0);
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289470);
#ifdef SKIP_ASM
extern "C" int BXFILE_exists(char* name);
extern "C" void func_002A77F8(void* self, char* name, int size);
extern "C" char* func_002A7B08(void* self);
extern "C" void func_002A7890(void* self, int flags);
extern "C" char* strcpy(char* dst, const char* src);
extern char* D_004A355C;
struct sAudio_9470 { char pad[0x60A4]; char names[20][0x14]; };

extern "C" void func_00289470(void* self)
{
    if (BXFILE_exists(D_004A355C) != 0) {
        char parser[0x810];
        func_002A77F8(parser, D_004A355C, 0x100);
        *(int*)((char*)self + 0x6234) = 0;
        while (*(int*)((char*)self + 0x6234) < 0x14) {
            char* s = func_002A7B08(parser);
            if (s == 0) {
                break;
            }
            strcpy(((sAudio_9470*)self)->names[*(int*)((char*)self + 0x6234)], s);
            *(int*)((char*)self + 0x6234) = *(int*)((char*)self + 0x6234) + 1;
        }
        func_002A7890(parser, 2);
        return;
    }
    *(int*)((char*)self + 0x6234) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289520);
#ifdef SKIP_ASM
extern "C" void func_002A77F8(void* self, char* name, int size);
extern "C" void func_002A7890(void* self, int flags);
extern "C" int func_002A7C68(void* self, const char* section);
extern "C" void func_002A7A20(void* self);
extern "C" int func_002A7F90(void* self);
extern "C" char* func_002A7DA0(void* self);
extern "C" void func_002A7FF8(void* self, const char* key, char* out);
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_004165A8(const void* a, const void* b);
extern "C" void func_002B3EB0(void* self);
extern "C" void func_002B3EE8(void* self, const char* name);
void func_002B4060(void* self);
extern char* D_004A355C;
extern char D_004A3608[];

// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t off-PS2.
extern "C" void func_00289520(void* self, const char* name)
{
    char parser[0x810];
    char buf[0x40];
    func_002B3EB0((char*)self + 0x118);
    func_002A77F8(parser, D_004A355C, 0x100);
    if (func_002A7C68(parser, name) != 0) {
        func_002A7A20(parser);
        while (func_002A7F90(parser) == 0) {
            char* key = func_002A7DA0(parser);
            if (func_0041AA88(D_004A3608, key) == 0) {
                func_002A7FF8(parser, D_004A3608, buf);
                func_002B3EE8((char*)self + 0x118, buf);
            }
        }
    }
    *(int*)((char*)self + 0x6238) = 20;
    for (int i = 0; i < 20; i++) {
        if (func_004165A8(((sAudio_9470*)self)->names[i], name) == 0) {
            *(int*)((char*)self + 0x6238) = i;
            break;
        }
    }
    func_002B4060((char*)self + 0x118);
    *(long*)((char*)self + 0x518) = *(long*)((char*)self + 0x510);
    func_002A7890(parser, 2);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289650);
#ifdef SKIP_ASM
// PORT: func_00289680 is defined (void*) but this caller passes (system, msg).
void func_00289680_2(void* self, void* msg) __asm__("func_00289680__FPv");
extern char* D_004A3500;

extern "C" void func_00289650(void* msg)
{
    if (*(int*)msg == 3) {
        func_00289680_2(D_004A3500, msg);
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289680__FPv);
#ifdef SKIP_ASM
void func_00289680(void* self)
{
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289688);
#ifdef SKIP_ASM
extern void* D_004A5B64;
extern "C" int func_0029F088(void* self, int a1);
extern "C" void func_00289830(void* self, float v);

struct sAud9688 {
    char pad0[0x6864];
    int f6864;
    char pad6868[0x3E8];
    int f6C50;
    int f6C54;
    int f6C58;
    char pad6C5C[0x4];
    int f6C60;
    float f6C64;
    float f6C68;
    float f6C6C;
};

extern "C" void func_00289688(void* self_)
{
    char* self = (char*)self_;
    sAud9688* s = (sAud9688*)self;
    if (s->f6C58 != 0) {
        int frame = s->f6864;
        if (frame == (frame / 2) * 2) {
            s->f6C60 = 0;
            s->f6C68 = s->f6C6C;
            int idx = (int)((float)(frame * s->f6C54) / *(float*)((char*)D_004A5B64 + 0x2C));
            if (idx < s->f6C50) {
                int val = *(signed char*)(self + idx + 0x6868);
                if (val > 0) {
                    int t0, t1, t2;
                    float vb, va;
                    switch (func_0029F088(self, 0)) {
                    case 2:
                        t0 = 0;
                        t1 = 0;
                        t2 = 30;
                        vb = 1.0f;
                        va = 0.0f;
                        break;
                    case 3:
                        va = 1.0f;
                        t0 = 30;
                        t1 = 40;
                        t2 = 50;
                        vb = 1.0f;
                        break;
                    default:
                        va = 1.0f;
                        t0 = 30;
                        t1 = 40;
                        t2 = 50;
                        vb = 1.0f;
                        break;
                    }
                    if (val < t0)
                        s->f6C6C = 1.0f;
                    else if (val < t1)
                        s->f6C6C = vb;
                    else if (val < t2)
                        s->f6C6C = vb;
                    else
                        s->f6C6C = va;
                } else {
                    s->f6C6C = 1.0f;
                }
            } else {
                s->f6C58 = 0;
                s->f6C6C = 1.0f;
            }
            s->f6C64 = s->f6C6C - s->f6C68;
        }
        (s->f6864)++;
    }
    int c = s->f6C60;
    if (c <= 0) {
        if (c == 0) {
            func_00289830(self, s->f6C6C);
            (s->f6C60)++;
        } else {
            s->f6C68 = s->f6C68 + s->f6C64;
            func_00289830(self, s->f6C68);
            (s->f6C60)++;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_00289830);
#ifdef SKIP_ASM
extern "C" void func_00287A10(void* self, int a1, float a2, float a3);

extern "C" void func_00289830(void* self, float v)
{
    if (*(float*)((char*)self + 0x6C5C) != v) {
        func_00287A10(self, 1, v, 0.0f);
        *(float*)((char*)self + 0x6C5C) = v;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289880);
#ifdef SKIP_ASM
extern "C" void func_00289880(void *arg0) {
    (*(int *)((char*)(arg0) + (0x6C58))) = 0;
    (*(float *)((char*)(arg0) + (0x6C6C))) = 1.0f;
    (*(int *)((char*)(arg0) + (0x6C60))) = 0;
    (*(float *)((char*)(arg0) + (0x6C64))) = (float) (1.0f - (*(float *)((char*)(arg0) + (0x6C68))));
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002898A8);
#ifdef SKIP_ASM
extern "C" int func_0028D960(void* self);
extern "C" void func_0028D988(void* self, void* rider, void* obj);
extern "C" int func_002899E8(void* self);
extern "C" void func_002899F8(void* self, void* rider, void* obj);
extern "C" void func_00289C98(void* self, int id, void* obj);

struct sSaVec98A8 { float x, y, z, w; } __attribute__((aligned(16)));
struct sSaVt98A8a { short delta; short index; sSaVec98A8* (*fn)(void*); };
struct sSaVt98A8b { short delta; short index; void* (*fn)(void*, float, float, float); };

struct sSaObjs98A8 {
    char pad0[0x5FA0];
    char* c[2];                 // 0x5FA0
    char pad5FA8[0x625C - 0x5FA8];
    char* a[2];                 // 0x625C
    char pad6264[0x6C80 - 0x6264];
    char* b[2];                 // 0x6C80
};

extern "C" void func_002898A8(void* self, char* rider)
{
    unsigned int idx = *(unsigned int*)(rider + 0x870);
    if (idx >= 2) return;
    sSaVec98A8 pos;
    {
        char* o = rider + 0x6C0;
        sSaVt98A8a* vt = *(sSaVt98A8a**)o;
        pos = *vt[5].fn(o + vt[5].delta);
    }
    if (func_0028D960(self) != 0) {
        float k = -99999.0f;
        char* a = ((sSaObjs98A8*)self)->a[idx];
        sSaVt98A8b* va = *(sSaVt98A8b**)(a + 4);
        func_0028D988(self, rider, va[2].fn(a + va[2].delta, pos.x, pos.y, k));
        char* b = ((sSaObjs98A8*)self)->b[idx];
        sSaVt98A8b* vb = *(sSaVt98A8b**)(b + 4);
        // PORT: func_00289C98's unit declaration takes the rider as int
        func_00289C98(self, (int)rider, vb[2].fn(b + vb[2].delta, pos.x, pos.y, k));
    }
    if (func_002899E8(self) != 0) {
        char* c = ((sSaObjs98A8*)self)->c[idx];
        sSaVt98A8b* vc = *(sSaVt98A8b**)(c + 4);
        func_002899F8(self, rider, vc[2].fn(c + vc[2].delta, pos.x, pos.y, -99999.0f));
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_002899E8);
#ifdef SKIP_ASM
extern "C" int func_002899E8(void* self)
{
    return *(int*)((char*)self + 0x608c) == 2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_002899F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" int func_002B49E0(void* monitor);
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");

struct sSaVt99F8a { short delta; short index; int* (*fn)(void*); };
struct sSaVt99F8b { short delta; short index; int (*fn)(void*, int); };

extern "C" void func_002899F8(void* self, void* rider, void* obj)
{
    if (rider != func_00285D98_p(self, -1)) return;
    if (obj == 0) return;
    sSaVt99F8a* vt = *(sSaVt99F8a**)((char*)obj + 4);
    int id = *vt[4].fn((char*)obj + vt[4].delta);
    if (id == -1) return;
    if (id == 0x1F) {
        if (func_002B49E0((char*)self + 0x118) != 0x65) {
            func_0028CF98(self, 0, 0, 1, 0);
        }
    } else if (id == 0x20) {
        if (func_002B49E0((char*)self + 0x118) != 0x66) {
            func_0028CF98(self, 0, 0, 2, 0);
        }
    } else if (id != 0x21) {
        char* mon = (char*)self + 0x118;
        sSaVt99F8b* vb = *(sSaVt99F8b**)((char*)self + 0x5558);
        vb[4].fn(mon + vb[4].delta, id);
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289AF0__FPv);
#ifdef SKIP_ASM
void func_00289AF0(void* self)
{
}
#endif

extern "C" void* func_00292AE8(void* self);

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289AF8__FPv);
#ifdef SKIP_ASM
void* func_00289AF8(void* self)
{
    return func_00292AE8(self);
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289B18);
#ifdef SKIP_ASM
extern "C" void func_0029BCF8(void* a0, void* a1);
extern "C" void func_0029B968(void* a0, void* a1);
extern "C" void func_0029C088(void* a0, void* a1);

extern "C" void func_00289B18(void* a0, void* a1, int type)
{
    if (type == 0x50) {
        func_0029BCF8(a0, a1);
    } else if (type == 0x51) {
        func_0029B968(a0, a1);
    } else if (type == 0x52) {
        func_0029C088(a0, a1);
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289B70);
#ifdef SKIP_ASM
extern "C" void func_0029CE28(void* self);
extern "C" void func_002B3A70(void*);

extern "C" void func_00289B70(void* self)
{
    if (*(int*)((char*)self + 0x5FB4) == 0) {
        func_0029CE28(self);
        func_002B3A70((char*)self + 0x118);
        *(int*)((char*)self + 0x5FB4) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289BB8);
#ifdef SKIP_ASM
extern "C" void func_002B3A98(void*);
extern "C" void func_0029CE70(void*);
extern "C" void func_002B11B0(void*, int);
extern "C" void func_002A4550(void*);

extern "C" void func_00289BB8(void* self)
{
    if (*(int*)((char*)self + 0x5FB4) != 0) {
        func_002B3A98((char*)self + 0x118);
        func_0029CE70(self);
        *(int*)((char*)self + 0x5FB4) = 0;
        if (*(int*)((char*)self + 0x5828) != 0) {
            func_002B11B0((char*)self + 0x5560, 0);
            func_002A4550(self);
            *(int*)((char*)self + 0x5828) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289C18);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00148950(void* iface, int id);

struct sSsxAudioVEntryI {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_00289C18(void* self, void* src)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 3);
    char* obj = (char*)src + 0x6C0;
    sSsxAudioVEntryI* vt = *(sSsxAudioVEntryI**)obj;
    int n = func_00148950(iface, vt[7].fn(obj + vt[7].delta));
    if (n < 4) {
        return 0;
    }
    if (n < 8) {
        return 1;
    }
    return 2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/ssxAudio", func_00289C98);
#ifdef SKIP_ASM
extern "C" int func_00285D98(void* self, int which);
extern "C" void func_002883B0(void* self, int id);

struct sSsxAudioVEntryP {
    short delta;
    short index;
    int* (*fn)(void*);
};

extern "C" void func_00289C98(void* self, int id, void* obj)
{
    if (id == func_00285D98(self, -1) && obj != 0) {
        sSsxAudioVEntryP* vt = *(sSsxAudioVEntryP**)((char*)obj + 0x4);
        func_002883B0(self, *vt[3].fn((char*)obj + vt[3].delta));
    }
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289D08);
#ifdef SKIP_ASM
extern "C" int func_00289D08(void* self, unsigned char a1)
{
    int r = 1;
    switch (a1) {
    case 0:
        break;
    case 1:
        r = 2;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 3;
        break;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289D60);
#ifdef SKIP_ASM
extern "C" void* func_00289D60(void* self, int a1)
{
    int r = 0;
    switch (a1) {
    case 1:
        break;
    case 2:
        r = 1;
        break;
    case 0:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    }
    return (void*)r;
}
#endif

extern "C" void* func_00289D60(void*, int);

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289DC0__FPv);
#ifdef SKIP_ASM
void* func_00289DC0(void* self)
{
    return func_00289D60(self, *(int*)((char*)self + 0x62b0));
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_00289DE0__FPv);
#ifdef SKIP_ASM
int func_00289DE0(void* self)
{
    int old = *(int*)((char*)self + 0x6c88);
    *(int*)((char*)self + 0x6c88) = 0;
    return old;
}
#endif

INCLUDE_ASM("sound/ssxAudio", func_00289DF0);

//100%
INCLUDE_ASM("sound/ssxAudio", func_0028A058);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00483B10[];
extern char D_00482820[];
extern void* D_004A3610;

extern "C" void* func_0028A058(void* self)
{
    *(int*)((char*)self + 0x18C) = 6;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x194) = 0;
    *(int*)((char*)self + 0x198) = 0;
    *(void**)((char*)self + 0x1D4) = D_00483B10;
    *(void**)((char*)self + 0x190) = operator_new_tag(0x18, D_00482820, 0, 0);
    *(int*)((char*)self + 0x19C) = 6;
    *(int*)((char*)self + 0x1A4) = 0;
    *(int*)((char*)self + 0x1A8) = 0;
    *(void**)((char*)self + 0x1A0) = operator_new_tag(0x18, D_00482820, 0, 0);
    *(int*)((char*)self + 0x1AC) = 6;
    *(int*)((char*)self + 0x1B4) = 0;
    *(int*)((char*)self + 0x1B8) = 0;
    *(void**)((char*)self + 0x1B0) = operator_new_tag(0x18, D_00482820, 0, 0);
    *(int*)((char*)self + 0x1BC) = 6;
    *(int*)((char*)self + 0x1C4) = 0;
    *(int*)((char*)self + 0x1C8) = 0;
    *(void**)((char*)self + 0x1C0) = operator_new_tag(0x18, D_00482820, 0, 0);
    *(int*)((char*)self + 0x1CC) = 0;
    *(int*)((char*)self + 0x1D0) = 0;
    D_004A3610 = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/ssxAudio", func_0028A148);
#ifdef SKIP_ASM
extern "C" void func_0028A230(void*);
void cMemMan_free(void*);
void operator_delete(int*);
extern char D_00483B10[];
extern void* D_004A3610;

struct sAudioSys_A148 {
    char pad0[0x190];
    void* buf190;       // 0x190
    char pad194[0xC];
    void* buf1A0;       // 0x1A0
    char pad1A4[0xC];
    void* buf1B0;       // 0x1B0
    char pad1B4[0xC];
    void* buf1C0;       // 0x1C0
    char pad1C4[0x10];
    void* vtbl;         // 0x1D4
};

extern "C" void func_0028A148(sAudioSys_A148* self, int flags)
{
    self->vtbl = D_00483B10;
    func_0028A230(self);
    D_004A3610 = 0;
    if (self->buf1C0 != 0) {
        cMemMan_free(self->buf1C0);
    }
    if (self->buf1B0 != 0) {
        cMemMan_free(self->buf1B0);
    }
    if (self->buf1A0 != 0) {
        cMemMan_free(self->buf1A0);
    }
    if (self->buf190 != 0) {
        cMemMan_free(self->buf190);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

