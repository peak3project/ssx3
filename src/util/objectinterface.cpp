#include "common.h"

struct cObjectInterface {
    char pad_0x00[0x84];
    struct cObjectInterface_Impl* mImpl; // offset 0x84
};

struct cObjectInterface_Impl {
    char pad_0x00[0x88];
    void* mInstanceMan; // offset 0x88
};

extern cObjectInterface* D_004A28A8;

//100%
INCLUDE_ASM("util/objectinterface", cObjectInterface_getInstanceMan__Fv);
#ifdef SKIP_ASM
void* cObjectInterface_getInstanceMan()
{
    return D_004A28A8->mImpl->mInstanceMan;
}
#endif

extern "C" void* func_002D9C00(void* self);

//100%
INCLUDE_ASM("util/objectinterface", func_002D1CF0__FPv);
#ifdef SKIP_ASM
void* func_002D1CF0(void* self)
{
    return func_002D9C00(self);
}
#endif

INCLUDE_ASM("util/objectinterface", func_002D1D10);

//100%
INCLUDE_ASM("util/objectinterface", func_002D2058);
#ifdef SKIP_ASM
// VU0 microprogram entry (micro-memory address 0x828)
extern char D_828[];

struct sQ128 { float v[4]; } __attribute__((aligned(16)));

// PORT: PS2-only VU0 microprogram call (ctc2/vcallmsr/cfc2); the PC port needs a C version.
extern "C" int func_002D2058(sQ128* v)
{
    char* inst = (char*)*(void**)((char*)D_004A28A8->mImpl + 0x8C);
    int mask = *(int*)(inst + 0x110);
    for (int i = 0; i < *(int*)(inst + 0x10C); i++) {
        int bit = 1 << i;
        if (mask & bit) {
            sQ128* m = (sQ128*)(*(char**)(inst + 8 + i * 8) + 0x50);
            int r;
            __asm__ __volatile__(
                ".set push\n"
                ".set noreorder\n"
                "lqc2      $vf1, %1\n"
                "lqc2      $vf2, %2\n"
                "lqc2      $vf3, %3\n"
                "lqc2      $vf4, %4\n"
                "lqc2      $vf5, %5\n"
                "lqc2      $vf6, %6\n"
                "ctc2.ni   %7, $vi27\n"
                "vnop\n"
                "vnop\n"
                "vcallmsr  $vi27\n"
                "cfc2.i    %0, $vi1\n"
                ".set pop\n"
                : "=&r"(r)
                : "m"(m[0]), "m"(m[1]), "m"(m[2]), "m"(m[3]), "m"(m[4]), "m"(*v), "r"((int)D_828 >> 3)
                : "memory");
            int ok = r == 1;
            if (ok) return 1;
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("util/objectinterface", func_002D20F8);

//100%
INCLUDE_ASM("util/objectinterface", func_002D2100);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00486758[];
extern "C" void* func_002D21C0(void* p);

extern "C" void* func_002D2100(void)
{
    return func_002D21C0(cMemMan_alloc(1, D_00486758, 0, 0));
}
#endif

INCLUDE_ASM("util/objectinterface", func_002D2148);

INCLUDE_ASM("util/objectinterface", func_002D2160);

INCLUDE_ASM("util/objectinterface", func_002D2178);

INCLUDE_ASM("util/objectinterface", func_002D2190);

INCLUDE_ASM("util/objectinterface", func_002D21A0);

//100%
INCLUDE_ASM("util/objectinterface", func_002D21B0__FPv);
#ifdef SKIP_ASM
void func_002D21B0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D21B8__FPv);
#ifdef SKIP_ASM
void func_002D21B8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("util/objectinterface", func_002D21C0);
#ifdef SKIP_ASM
extern void* D_004A3A00;

extern "C" void* func_002D21C0(void* p)
{
    D_004A3A00 = p;
    return p;
}
#endif

INCLUDE_ASM("util/objectinterface", func_002D21D0);

INCLUDE_ASM("util/objectinterface", func_002D2210);

INCLUDE_ASM("util/objectinterface", func_002D2248);

INCLUDE_ASM("util/objectinterface", func_002D22A8);

INCLUDE_ASM("util/objectinterface", func_002D2308);

INCLUDE_ASM("util/objectinterface", func_002D2368);

INCLUDE_ASM("util/objectinterface", func_002D23C8);

INCLUDE_ASM("util/objectinterface", func_002D23E8);

INCLUDE_ASM("util/objectinterface", func_002D2478);

