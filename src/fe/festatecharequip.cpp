#include "common.h"

// Declarations shared by the functions of this unit.
extern void* D_0046D878[];
void operator_delete(int* p);
extern void* D_0046BF98[];
extern void* D_0046D848[];

//100%
INCLUDE_ASM("fe/festatecharequip", cFE_cFE);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is the game's tagged operator new(size, tag, flags, d); bound by asm label.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* func_00231CD0(void* self);
extern "C" void* func_0015D698(void* self);
extern "C" void* func_001A03C0(void* self);
extern "C" void* func_0019CDF0(void* self);
// PORT: called with an extra int in $a1 here; func_0015D700's body is (self, x, y, z). Bound by asm label.
void func_0015D700_i(void* self, int a1, float x, float y, float z) __asm__("func_0015D700");
extern void* D_0046D8D8[];
extern char D_004601F0[];
extern char D_00460200[];

// Constructors bound to their unmangled symbols (g++ 2.95 ctors return this).
class cFEObjK1956F8_70 {
public:
    char pad_0x000[0x70];
    cFEObjK1956F8_70() __asm__("func_00397B08");
};
class cFEObjK1956F8_1 {
public:
    cFEObjK1956F8_1(int a) __asm__("func_002DBD10");
};

extern "C" void* cFE_cFE(void* self)
{
    func_00231CD0(self);
    *(void***)((char*)self + 0x0) = D_0046D878;
    func_0015D698((char*)self + 0x10);
    *(void***)((char*)self + 0xA0) = D_0046D8D8;
    func_001A03C0((char*)self + 0xB0);
    func_0019CDF0((char*)self + 0x1A70);
    *(cFEObjK1956F8_70**)((char*)self + 0xC) = new (D_004601F0, 0, 0) cFEObjK1956F8_70;
    func_0015D700_i((char*)self + 0x10, 0, 0.7853981852531433f, 5.0f, 5000.0f);
    *(cFEObjK1956F8_1**)((char*)self + 0xB5AA0) = new (D_00460200, 0, 0) cFEObjK1956F8_1(1);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequip", func_001957D0);
#ifdef SKIP_ASM
extern "C" void func_00397B70(void* p, int flags);
extern "C" void func_0036A020(void* p);
extern "C" void func_002DBEE0(void* p, int flags);
extern "C" void func_0019CE20(void* p, int flags);
extern "C" void func_001A0420(void* p, int flags);
extern void* D_004A289C;
extern void* D_0046D970[];
extern void* D_0045B8B0[];

extern "C" void func_001957D0(void* self, int flags)
{
    *(void***)((char*)self + 0x0) = D_0046D878;
    if (*(void**)((char*)self + 0xC) != 0) {
        func_00397B70(*(void**)((char*)self + 0xC), 3);
    }
    func_0036A020(D_004A289C);
    if (*(void**)((char*)self + 0xB5AA0) != 0) {
        func_002DBEE0(*(void**)((char*)self + 0xB5AA0), 3);
    }
    func_0019CE20((char*)self + 0x1A70, 2);
    func_001A0420((char*)self + 0xB0, 2);
    *(void***)((char*)self + 0xA0) = D_0045B8B0;
    *(void***)((char*)self + 0x0) = D_0046D970;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequip", func_00195880);
#ifdef SKIP_ASM
extern "C" void* func_001DCC40(void* p);
extern "C" void func_00416210(void* dst, int value, int size);

extern "C" void* func_00195880(void* self)
{
    *(char*)((char*)self + 0x0) = 0;
    *(char*)((char*)self + 0x1) = 0;
    *(char*)((char*)self + 0x2) = 0;
    *(void***)((char*)self + 0x4) = D_0046D848;
    func_001DCC40((char*)self + 3);
    *(char*)((char*)self + 0x58) = 0;
    *(void***)((char*)self + 0x4) = D_0046BF98;
    *(char*)((char*)self + 0x2) = 4;
    func_00416210((char*)self + 8, 0, 0x50);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequip", func_001958F0);
#ifdef SKIP_ASM
extern "C" void func_00195948(void* self);

extern "C" void func_001958F0(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_0046BF98;
    func_00195948(self);
    *(void***)((char*)self + 0x4) = D_0046D848;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequip", func_00195948);
#ifdef SKIP_ASM
extern "C" void func_00195A50(void* self, int i);

extern "C" void func_00195948(void* self)
{
    signed char i;
    for (i = 0; i < 20; i++) {
        func_00195A50(self, i);
    }
}
#endif

