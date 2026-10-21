#include "common.h"

//100%
INCLUDE_ASM("animation/gameanimmap", cGameAnimMap_testResolve__Fv);
#ifdef SKIP_ASM
void cGameAnimMap_testResolve()
{
}
#endif

//100%
INCLUDE_ASM("animation/gameanimmap", func_003150B8);
#ifdef SKIP_ASM
extern "C" void* func_003150B8(void* self, ...) {
    return self;
}
#endif

INCLUDE_ASM("animation/gameanimmap", func_003150F8);

extern "C" void* func_003150F8(int, int);

//100%
INCLUDE_ASM("animation/gameanimmap", func_003158B8);
#ifdef SKIP_ASM
extern "C" float func_003158B8(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x1C)));
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003158C0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long func_003158C0(void *arg0) {
    return (*(long *)((char*)(arg0) + (0x20)));
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003158C8);
#ifdef SKIP_ASM
extern "C" int func_003158C8(int arg0) {
    return arg0 + 0x30;
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003158D0);
#ifdef SKIP_ASM
extern "C" int func_003158D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003158D8);
#ifdef SKIP_ASM
extern "C" void func_003158D8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003158E0);
#ifdef SKIP_ASM
extern "C" void func_003158E0(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x1C))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003158E8);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" void func_0031BE50(float *, float *, float);
extern t4Vector D_004FF130;
extern t4Vector D_004FF160;

extern "C" void func_003158E8(void *self, float angle) {
    t4Vector q;
    float s;
    float c;
    const t4Vector* axis = &D_004FF160;

    *(t4Vector *)((char*)self + 0x30) = D_004FF130;
    func_0031BE50(&s, &c, -angle * 0.5f);
    q.w = c;
    q.x = s * axis->x;
    q.y = s * axis->y;
    q.z = s * axis->z;
    *(t4Vector *)((char*)self + 0x40) = q;
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_00315988);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_00315988(void *arg0, void *arg1) {
    (*(long long *)((char*)(arg0) + (0x30))) = (long long) (*(long long *)((char*)(arg1) + (0)));
    (*(long long *)((char*)(arg0) + (0x40))) = (long long) (*(long long *)((char*)(arg1) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003159A0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_003159A0(void *arg0, long arg1) {
    (*(long *)((char*)(arg0) + (0x20))) = arg1;
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_003159A8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_003159A8(void *arg0) {
    (*(long *)((char*)(arg0) + (0x20))) = -1;
}
#endif

//100%
INCLUDE_ASM("animation/gameanimmap", func_003159B8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_003159B8(long *self, int bit) {
    long mask = 1L << bit;
    long a = self[0];
    self[1] |= mask & a;
    self[0] = a & ~mask;
}
#endif

//100%
INCLUDE_ASM("animation/gameanimmap", func_003159E8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
static inline int testBits_59E8(long v, long mask) {
    return (v & mask) != 0;
}
extern "C" int func_003159E8(long *self, int bit) {
    return testBits_59E8(self[0], 1L << bit);
}
#endif
//100%
INCLUDE_ASM("animation/gameanimmap", func_00315A00__FPv);
#ifdef SKIP_ASM
void* func_00315A00(void* self)
{
    return func_003150F8(1, 0xffff);
}
#endif

INCLUDE_ASM("animation/gameanimmap", func_00315A20);

extern "C" void* func_00315A20(int, int);

//100%
INCLUDE_ASM("animation/gameanimmap", func_00316878__FPv);
#ifdef SKIP_ASM
void* func_00316878(void* self)
{
    return func_00315A20(1, 0xffff);
}
#endif

