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

//100%
INCLUDE_ASM("util/objectinterface", func_002D20F8);
#ifdef SKIP_ASM
extern void* D_004A3A00;

extern "C" int func_002D20F8(void) {
    return (*(int*)&D_004A3A00);
}
#endif

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

//100%
INCLUDE_ASM("util/objectinterface", func_002D2138);
#ifdef SKIP_ASM
extern "C" void func_002D2138(void) {

}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2140);
#ifdef SKIP_ASM
extern "C" void func_002D2140(void) {

}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2148);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern long long D_004FF120;

extern "C" long long *func_002D2148(long long *arg0) {
    *arg0 = D_004FF120;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2160);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern long long D_004FF120;

extern "C" long long *func_002D2160(long long *arg0) {
    *arg0 = D_004FF120;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2178);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern long long D_004FF120;

extern "C" long long *func_002D2178(long long *arg0) {
    *arg0 = D_004FF120;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D2190);
#ifdef SKIP_ASM
extern "C" float func_002D2190(void) {
    return 0.0f;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D21A0);
#ifdef SKIP_ASM
extern "C" float func_002D21A0(void) {
    return 0.0f;
}
#endif

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
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2248);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D2248(void* self, float* v)
{
    int i;
    for (i = 0; i < 3; i++) {
        func_002D21D0(self, v[i]);
    }
    return 0xC;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D22A8);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D22A8(void* self, float* v)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_002D21D0(self, v[i]);
    }
    return 0x10;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2308);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D2308(void* self, float* v)
{
    int i;
    for (i = 0; i < 16; i++) {
        func_002D21D0(self, v[i]);
    }
    return 0x40;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2368);
#ifdef SKIP_ASM
extern "C" void func_002D21D0(void* self, float v);

extern "C" int func_002D2368(void* self, float* q)
{
    func_002D21D0(self, q[3]);
    func_002D21D0(self, q[0]);
    func_002D21D0(self, q[1]);
    func_002D21D0(self, q[2]);
    return 0x10;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D23C8);
#ifdef SKIP_ASM
extern "C" int func_002D23C8(signed char **arg0, signed char arg1) {
    **arg0 = arg1;
    *arg0 += 1;
    return 1;
}
#endif
//100%
INCLUDE_ASM("util/objectinterface", func_002D23E8);
#ifdef SKIP_ASM
extern "C" int func_002D23C8(signed char **arg0, signed char arg1);
extern "C" unsigned int strlen(const char* s);

extern "C" int func_002D23E8(signed char** out, const char* s)
{
    unsigned int i;
    int n = 0;
    for (i = 0; i < strlen(s); i++) {
        n += func_002D23C8(out, s[i]);
    }
    func_002D23C8(out, 0);
    return n + 1;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/objectinterface", func_002D2478);
#ifdef SKIP_ASM
extern "C" int func_002D2210(signed char** out, unsigned int len);

struct sStr_2478 {
    unsigned int len;
    signed char* data;
};

extern "C" int func_002D2478(signed char** out, sStr_2478** pp)
{
    unsigned int i;
    int n = func_002D2210(out, (*pp)->len);
    for (i = 0; i < (*pp)->len; i++) {
        n += func_002D23C8(out, (*pp)->data[i]);
    }
    return n;
}
#endif
