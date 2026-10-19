#include "common.h"

//100%
INCLUDE_ASM("camera/cameraalgorithms", cChaseCameraController_createChaseAlgorithmBlend);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(unsigned int size, const char* tag, int flags, int d);
extern void* D_004A28A8;
extern char D_0045B250[], D_0045B278[], D_0045B298[], D_0045B2B0[], D_0045B2D8[], D_0045B300[];
extern char D_0045B328[], D_0045B348[], D_0045B370[], D_0045B390[], D_0045B3B0[];
extern char D_0045B3D0[], D_0045B3F8[], D_0045B420[], D_0045B448[], D_0045B470[], D_0045B498[], D_0045B4C0[], D_0045B4E8[];
extern char D_0045B510[], D_0045B538[], D_0045B558[], D_0045B578[], D_0045B598[];

struct sCamTmp_D0A0 { float x, y, z, w; } __attribute__((aligned(16)));

class cCamAlgo_D0A0 {
public:
    char pad[0x10];
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void activate();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void setTarget(void* target);
};

extern "C" void func_00170240(sCamTmp_D0A0* out, void* target);
extern "C" void func_001707B0(sCamTmp_D0A0* out, void* target);
extern "C" void func_00170D20(sCamTmp_D0A0* out, void* target, int corner);
extern "C" cCamAlgo_D0A0* func_00178520(void* mem, sCamTmp_D0A0* a, sCamTmp_D0A0* b);
extern "C" cCamAlgo_D0A0* func_00174190(void* mem);
extern "C" cCamAlgo_D0A0* func_00161060(void* mem, sCamTmp_D0A0* a, sCamTmp_D0A0* b, sCamTmp_D0A0* c, sCamTmp_D0A0* d,
                               float f0, float f1, float f2, float f3);
extern "C" cCamAlgo_D0A0* func_001616A8(void* mem);
extern "C" cCamAlgo_D0A0* func_001689C8(void* mem);
extern "C" cCamAlgo_D0A0* func_00168CD8(void* mem);
extern "C" cCamAlgo_D0A0* func_00160438(void* mem);
extern "C" cCamAlgo_D0A0* func_001682B8(void* mem);
extern "C" cCamAlgo_D0A0* func_001774C0(void* mem, int index);
extern "C" cCamAlgo_D0A0* func_00168650(void* mem);
extern "C" cCamAlgo_D0A0* func_00160760(void* mem);
extern "C" cCamAlgo_D0A0* func_00160B70(void* mem, float angle);
extern "C" cCamAlgo_D0A0* func_00176A68(void* mem);
extern "C" cCamAlgo_D0A0* func_00177068(void* mem);
extern "C" cCamAlgo_D0A0* func_00176D68(void* mem);
extern "C" cCamAlgo_D0A0* func_00177E50(void* mem);
extern "C" cCamAlgo_D0A0* func_001789E8(void* mem, void* target);
extern "C" void func_00161E58(char* self, cCamAlgo_D0A0* algo, float blend);

static inline int camNetActive_D0A0(int n) { return n != 0 && n < 10; }

// Creates the chase-camera algorithm for the given kind and blends it in.
extern "C" void cChaseCameraController_createChaseAlgorithmBlend(char* self, int kind, char* ctx, float blend)
{
    cCamAlgo_D0A0* r = 0;
    float b = blend;
    if (*(int*)(self + 0x30) & 2) {
        b = 1.0f;
    }
    switch (kind) {
    case 91: {
        int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
        if (!camNetActive_D0A0(n)) {
            char* target = *(char**)(ctx + 8);
            if (*(int*)(target + 0x28) == 2) {
                void* mem = cMemMan_alloc(0x3B0, D_0045B250, 0x20000000, 0);
                sCamTmp_D0A0 a;
                func_00170240(&a, target);
                sCamTmp_D0A0 c;
                func_001707B0(&c, target);
                r = func_00178520(mem, &a, &c);
                break;
            }
        }
        r = func_00174190(cMemMan_alloc(0x90, D_0045B278, 0x20000000, 0));
        *(char**)((char*)r + 0x80) = ctx;
        break;
    }
    case 92: {
        char* target = *(char**)(ctx + 8);
        void* mem = cMemMan_alloc(0x3D0, D_0045B298, 0x20000000, 0);
        sCamTmp_D0A0 c0;
        func_00170D20(&c0, target, 0);
        sCamTmp_D0A0 c1;
        func_00170D20(&c1, target, 1);
        sCamTmp_D0A0 c2;
        func_00170D20(&c2, target, 2);
        sCamTmp_D0A0 c3;
        func_00170D20(&c3, target, 3);
        r = func_00161060(mem, &c0, &c1, &c2, &c3,
                          *(float*)(ctx + 0x18), *(float*)(ctx + 0x14), *(float*)(ctx + 0x1C), *(float*)(ctx + 0x10));
        break;
    }
    case 7:
        r = func_001616A8(cMemMan_alloc(0x390, D_0045B328, 0x20000000, 0));
        break;
    case 9:
        r = func_001689C8(cMemMan_alloc(0x390, D_0045B348, 0x20000000, 0));
        break;
    case 10:
        r = func_00168CD8(cMemMan_alloc(0x390, D_0045B370, 0x20000000, 0));
        break;
    case 11:
        r = func_00160438(cMemMan_alloc(0x390, D_0045B390, 0x20000000, 0));
        break;
    case 13:
        r = func_001682B8(cMemMan_alloc(0x390, D_0045B3B0, 0x20000000, 0));
        break;
    case 18:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B3D0, 0x20000000, 0), 0);
        break;
    case 19:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B3F8, 0x20000000, 0), 1);
        break;
    case 20:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B420, 0x20000000, 0), 2);
        break;
    case 21:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B448, 0x20000000, 0), 3);
        break;
    case 22:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B470, 0x20000000, 0), 4);
        break;
    case 23:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B498, 0x20000000, 0), 5);
        break;
    case 24:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B4C0, 0x20000000, 0), 6);
        break;
    case 25:
        r = func_001774C0(cMemMan_alloc(0x3A0, D_0045B4E8, 0x20000000, 0), 7);
        break;
    case 32:
        r = func_00168650(cMemMan_alloc(0x390, D_0045B510, 0x20000000, 0));
        break;
    case 41:
        r = func_00160760(cMemMan_alloc(0x3A0, D_0045B538, 0x20000000, 0));
        break;
    case 33: case 34: case 35: case 36: case 37: case 38: case 39: case 40: {
        float angle = (float)(kind - 0x21) * 0.7853982f;
        r = func_00160B70(cMemMan_alloc(0x3C0, D_0045B558, 0x20000000, 0), angle);
        *(int*)((char*)r + 0xC) = kind;
        break;
    }
    case 2: case 60:
        r = func_00176A68(cMemMan_alloc(0x390, D_0045B2D8, 0x20000000, 0));
        break;
    case 1: case 62:
        r = func_00177068(cMemMan_alloc(0x390, D_0045B300, 0x20000000, 0));
        break;
    case 0: case 3: case 4: case 5: case 6: case 8: case 12: case 14: case 15: case 16: case 17:
    case 26: case 27: case 28: case 29: case 30: case 31:
    case 42: case 43: case 44: case 45: case 46: case 47: case 48: case 49: case 50:
    case 51: case 52: case 53: case 54: case 55: case 56: case 57: case 58: case 59:
    case 61: case 63: case 64: case 65: case 74:
        r = func_00176D68(cMemMan_alloc(0x390, D_0045B2B0, 0x20000000, 0));
        break;
    case 66:
        r = func_00177E50(cMemMan_alloc(0x3A0, D_0045B578, 0x20000000, 0));
        break;
    case 67:
        r = 0;
        break;
    case 68:
        r = func_001789E8(cMemMan_alloc(0x3B0, D_0045B598, 0x20000000, 0), *(void**)(self + 0x20));
        break;
    case 94:
        r = func_00160B70(cMemMan_alloc(0x3C0, D_0045B558, 0x20000000, 0), -0.3926991f);
        *(int*)((char*)r + 0xC) = kind;
        break;
    case 95:
        r = func_00160B70(cMemMan_alloc(0x3C0, D_0045B558, 0x20000000, 0), 0.3926991f);
        *(int*)((char*)r + 0xC) = kind;
        break;
    case 96:
        r = func_00160B70(cMemMan_alloc(0x3C0, D_0045B558, 0x20000000, 0), -2.3561945f);
        *(int*)((char*)r + 0xC) = kind;
        break;
    case 97:
        r = func_00160B70(cMemMan_alloc(0x3C0, D_0045B558, 0x20000000, 0), 2.3561945f);
        *(int*)((char*)r + 0xC) = kind;
        break;
    }
    r->setTarget(*(void**)(self + 0x20));
    func_00161E58(self, r, b);
    r->activate();
}
#endif

//100%
INCLUDE_ASM("camera/cameraalgorithms", func_0015D698);
#ifdef SKIP_ASM
struct func_0015D698_sVec4 { float x, y, z, w; } __attribute__((aligned(16)));

extern void* D_0045B8B0[];
extern func_0015D698_sVec4 D_004FF140;

extern "C" void* func_0015D698(void* self)
{
    func_0015D698_sVec4 v;
    *(void***)((char*)self + 0x90) = D_0045B8B0;
    v.x = 0; v.y = 0; v.z = 0; v.w = 0;
    *(func_0015D698_sVec4*)((char*)self + 0x20) = v;
    v.w = 1.0f;
    v.x = 0;
    v.y = 1.0f;
    v.z = 0;
    *(func_0015D698_sVec4*)((char*)self + 0x30) = v;
    *(func_0015D698_sVec4*)((char*)self + 0x80) = D_004FF140;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/cameraalgorithms", func_0015D700);
#ifdef SKIP_ASM
extern "C" void* func_0015D928(void* self);

extern "C" void func_0015D700(void* self, float x, float y, float z)
{
    func_0015D698_sVec4 v;
    *(float*)((char*)self + 0xC) = x;
    *(float*)((char*)self + 0x10) = y;
    *(float*)((char*)self + 0x14) = z;
    *(float*)((char*)self + 0x0) = x;
    *(float*)((char*)self + 0x4) = y;
    *(float*)((char*)self + 0x8) = z;
    v.x = 0; v.y = 0; v.z = 0; v.w = 0;
    *(func_0015D698_sVec4*)((char*)self + 0x20) = v;
    v.w = 1.0f;
    v.x = 0;
    v.y = 1.0f;
    v.z = 0;
    *(func_0015D698_sVec4*)((char*)self + 0x30) = v;
    *(func_0015D698_sVec4*)((char*)self + 0x80) = D_004FF140;
    func_0015D928(self);
}
#endif

INCLUDE_ASM("camera/cameraalgorithms", func_0015D780);

INCLUDE_ASM("camera/cameraalgorithms", func_0015D880);

//100%
INCLUDE_ASM("camera/cameraalgorithms", func_0015D928);
#ifdef SKIP_ASM
struct sV_D928 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_D928 {
    float m[4][4];
} __attribute__((aligned(16)));

extern char D_004C53A0[];

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_D928(void* dst, void* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_D928(void* dst, void* a, void* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (unit quaternion -> rotation matrix, row 3 = identity).
static inline void vu0QuatToMtx_D928(void* m, const sV_D928& q)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2       $vf4, %1\n"
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
        "sqc2       $vf0, 0x30(%0)\n"
        "sqc2       $vf10, 0x0(%0)\n"
        "sqc2       $vf11, 0x10(%0)\n"
        "sqc2       $vf12, 0x20(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(q)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_D928(void* m, const sV_D928& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

extern "C" void func_0015D928_impl(void* self) __asm__("func_0015D928");
extern "C" void func_0015D928_impl(void* self)
{
    char* view = (char*)self + 0x40;
    vu0CopyMtx_D928(view, D_004C53A0);
    sM_D928 rot;
    vu0QuatToMtx_D928(&rot, *(sV_D928*)((char*)self + 0x30));
    vu0MulMtx_D928(view, view, &rot);
    sV_D928 t;
    sV_D928 neg;
    sV_D928 pos;
    pos.x = *(float*)((char*)self + 0x20);
    pos.y = *(float*)((char*)self + 0x24);
    pos.z = *(float*)((char*)self + 0x28);
    neg.x = -pos.x;
    neg.y = -pos.y;
    neg.z = -pos.z;
    t.x = neg.x;
    t.y = neg.y;
    t.z = neg.z;
    t.w = 1.0f;
    vu0TransMtx_D928(view, t);
}
#endif

//100%
INCLUDE_ASM("camera/cameraalgorithms", func_0015DAC0);
#ifdef SKIP_ASM
extern void* D_004A28A8;

extern "C" void func_0015DAC0(void)
{
    void* cam = *(void**)((char*)D_004A28A8 + 0x84);
    void* chase = *(void**)((char*)cam + 0x84);
    void* ctrl = *(void**)((char*)chase + 0x4);
    *(int*)((char*)ctrl + 0x4A4) = 1;
}
#endif

INCLUDE_ASM("camera/cameraalgorithms", func_0015DAE0);

//100%
INCLUDE_ASM("camera/cameraalgorithms", func_0015DB58);
#ifdef SKIP_ASM
extern "C" void func_0016C968(void* self);
void cCameraTriggerMan_setInGameTriggers(void* self);
extern "C" void func_00162170(void* cam);
extern char D_004C5830[];

struct sCamVE_0015DB58 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0015DB58(void)
{
    func_0016C968(D_004C5830);
    cCameraTriggerMan_setInGameTriggers(D_004C5830);
    char* riders = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84);
    int n = *(int*)riders;
    func_00162170(*(void**)(*(char**)(riders + 4) + 0xA8));
    char* cam = *(char**)(*(char**)(riders + 4) + 0xA8);
    sCamVE_0015DB58* e = &(*(sCamVE_0015DB58**)(cam + 0x14))[4];
    e->fn(cam + e->delta);
    *(int*)(*(char**)(riders + 4) + 0x460) = 0;
    *(int*)(*(char**)(riders + 4) + 0x4A4) = 1;
    if (n >= 2)
    {
        func_00162170(*(void**)(*(char**)(riders + 8) + 0xA8));
        char* cam2 = *(char**)(*(char**)(riders + 8) + 0xA8);
        sCamVE_0015DB58* e2 = &(*(sCamVE_0015DB58**)(cam2 + 0x14))[4];
        e2->fn(cam2 + e2->delta);
        *(int*)(*(char**)(riders + 8) + 0x460) = 0;
    }
}
#endif

