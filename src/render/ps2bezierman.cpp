#include "common.h"

extern "C" void* func_00374C90(void* self);
extern "C" void* func_00372B30(void* self);
extern "C" void func_0038AF30(void* self);
extern void* D_00493760[16];

//100%
INCLUDE_ASM("render/ps2bezierman", cPSPBezierMan_cPSPBezierMan__FPv);
#ifdef SKIP_ASM
extern "C" void* func_00374C90(void* self);
inline void* operator new[](unsigned int, void* p) { return p; }

// Element type of an inline-constructed array; its empty constructor leaves only the loop counters.
struct sBezSlot_8AE0 {
    void* p;
    sBezSlot_8AE0() {}
};

void* cPSPBezierMan_cPSPBezierMan(void* self)
{
    func_00374C90(self);
    *(void**)((char*)self + 0x4) = D_00493760;
    func_00372B30((char*)self + 0x10);
    new ((char*)self + 0x8) sBezSlot_8AE0[2];
    func_0038AF30(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("render/ps2bezierman", func_0038AEB0);
#ifdef SKIP_ASM
extern "C" void func_0038B0F8(void* self);
extern "C" void func_00374CA8(void* self, int flags);

extern "C" void func_0038AEB0(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00493760;
    func_0038B0F8(self);
    func_00374CA8(self, flags);
}
#endif

