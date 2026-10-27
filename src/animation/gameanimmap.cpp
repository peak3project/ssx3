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

//100%
INCLUDE_ASM("animation/gameanimmap", func_003150F8);
#ifdef SKIP_ASM
extern float D_004FE420[4];
extern float D_004FE430[4];
extern float D_004FE440[4];
extern float D_004FE450[4];
extern float D_004FE460[4];
extern float D_004FE470[4];
extern float D_004FE480[4];
extern float D_004FE490[4];
extern float D_004FE4A0[4];
extern float D_004FE4B0[4];
extern float D_004FE4C0[4];
extern float D_004FE4D0[4];
extern float D_004FE4E0[4];
extern float D_004FE4F0[4];
extern float D_004FE500[4];
extern float D_004FE510[4];
extern float D_004FE520[4];
extern float D_004FE530[4];
extern float D_004FE540[4];
extern float D_004FE550[4];
extern float D_004FE560[4];
extern float D_004FE570[4];
extern float D_004FE580[4];
extern float D_004FE590[4];
extern float D_004FE5A0[4];
extern float D_004FE5B0[4];
extern float D_004FE5C0[4];
extern float D_004FE5D0[4];
extern float D_004FE5E0[4];
extern float D_004FE5F0[4];
extern float D_004FE600[4];
extern float D_004FE610[4];
extern float D_004FE620[4];
extern float D_004FE630[4];
extern float D_004FE640[4];
extern float D_004FE650[4];
extern float D_004FE660[4];
extern float D_004FE670[4];
extern float D_004FE680[4];
extern float D_004FE690[4];
extern float D_004FE6A0[4];
extern float D_004FE6B0[4];
extern float D_004FE6C0[4];
extern float D_004FE6D0[4];
extern float D_004FE6E0[4];
extern float D_004FE6F0[4];
extern float D_004FE700[4];
extern float D_004FE710[4];
extern float D_004FE720[4];
extern float D_004FE730[4];
extern float D_004FE740[4];
extern float D_004FE750[4];
extern float D_004FE760[4];
extern float D_004FE770[4];
extern float D_004FE780[4];
extern float D_004FE790[4];
extern int D_004A5950;
void sti_003150F8(int init, int prio) __asm__("func_003150F8");
void sti_003150F8(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        *(char*)&D_004A5950 = -1;
        D_004A5950 = (D_004A5950 & 0xFF) | 0xFFFFFF00u;
        D_004FE420[0] = 1.0f;
        D_004FE420[1] = 1.0f;
        D_004FE420[2] = 1.0f;
        D_004FE420[3] = 0.5f;
        D_004FE430[0] = 0.4998680055141449f;
        D_004FE430[1] = 1.0f;
        D_004FE430[2] = 1.0f;
        D_004FE430[3] = 0.0f;
        D_004FE440[0] = 0.12951700389385223f;
        D_004FE440[1] = 1.0f;
        D_004FE440[2] = 1.0f;
        D_004FE440[3] = 0.0f;
        D_004FE450[0] = 0.22426900267601013f;
        D_004FE450[1] = 0.9402310252189636f;
        D_004FE450[2] = 0.5425059795379639f;
        D_004FE450[3] = 0.0004030000127386302f;
        D_004FE460[0] = 0.4652079939842224f;
        D_004FE460[1] = 0.32170501351356506f;
        D_004FE460[2] = 0.9943439960479736f;
        D_004FE460[3] = 0.0f;
        D_004FE470[0] = 0.17792600393295288f;
        D_004FE470[1] = 1.0f;
        D_004FE470[2] = 1.0f;
        D_004FE470[3] = 0.0f;
        D_004FE480[0] = 0.4411740005016327f;
        D_004FE480[1] = 0.41388601064682007f;
        D_004FE480[2] = 0.3211260139942169f;
        D_004FE480[3] = 0.4398239850997925f;
        D_004FE490[0] = 0.500997006893158f;
        D_004FE490[1] = 0.24849599599838257f;
        D_004FE490[2] = 1.0f;
        D_004FE490[3] = 1.0f;
        D_004FE4A0[0] = 0.27687299251556396f;
        D_004FE4A0[1] = 0.6395620107650757f;
        D_004FE4A0[2] = 0.13423900306224823f;
        D_004FE4A0[3] = 0.0f;
        D_004FE4B0[0] = 0.8936439752578735f;
        D_004FE4B0[1] = 0.5263469815254211f;
        D_004FE4B0[2] = 0.5051450133323669f;
        D_004FE4B0[3] = 0.8687300086021423f;
        D_004FE4C0[0] = 1.0f;
        D_004FE4C0[1] = 1.0f;
        D_004FE4C0[2] = 1.0f;
        D_004FE4C0[3] = 1.0f;
        D_004FE4D0[0] = 1.0f;
        D_004FE4D0[1] = 0.0f;
        D_004FE4D0[2] = 0.0f;
        D_004FE4D0[3] = 0.0f;
        D_004FE4E0[0] = 1.0f;
        D_004FE4E0[1] = 0.550000011920929f;
        D_004FE4E0[2] = 0.5350000262260437f;
        D_004FE4E0[3] = 0.550000011920929f;
        D_004FE4F0[0] = 1.0f;
        D_004FE4F0[1] = 1.0f;
        D_004FE4F0[2] = 1.0f;
        D_004FE4F0[3] = 1.0f;
        D_004FE500[0] = 1.0f;
        D_004FE500[1] = 1.0f;
        D_004FE500[2] = 1.0f;
        D_004FE500[3] = 1.0f;
        D_004FE510[0] = 1.0f;
        D_004FE510[1] = 0.0f;
        D_004FE510[2] = 0.0f;
        D_004FE510[3] = 0.0f;
        D_004FE520[0] = 1.0f;
        D_004FE520[1] = 0.0f;
        D_004FE520[2] = 0.0f;
        D_004FE520[3] = 0.0f;
        D_004FE530[0] = 1.0f;
        D_004FE530[1] = 1.0f;
        D_004FE530[2] = 1.0f;
        D_004FE530[3] = 1.0f;
        D_004FE540[0] = 1.0f;
        D_004FE540[1] = 0.5f;
        D_004FE540[2] = 1.0f;
        D_004FE540[3] = 0.5f;
        D_004FE550[0] = 1.0f;
        D_004FE550[1] = 0.5f;
        D_004FE550[2] = 1.0f;
        D_004FE550[3] = 0.5f;
        D_004FE560[0] = 1.0f;
        D_004FE560[1] = 0.5f;
        D_004FE560[2] = 1.0f;
        D_004FE560[3] = 0.5f;
        D_004FE570[0] = 1.0f;
        D_004FE570[1] = 0.7828119993209839f;
        D_004FE570[2] = 0.06171900033950806f;
        D_004FE570[3] = 0.03984399884939194f;
        D_004FE580[0] = 1.0f;
        D_004FE580[1] = 1.0f;
        D_004FE580[2] = 0.7988259792327881f;
        D_004FE580[3] = 0.0f;
        D_004FE590[0] = 0.9886710047721863f;
        D_004FE590[1] = 0.9230499863624573f;
        D_004FE590[2] = 0.34311699867248535f;
        D_004FE590[3] = 0.0f;
        D_004FE5A0[0] = 1.0f;
        D_004FE5A0[1] = 1.0f;
        D_004FE5A0[2] = 1.0f;
        D_004FE5A0[3] = 1.0f;
        D_004FE5B0[0] = 1.0f;
        D_004FE5B0[1] = 1.0f;
        D_004FE5B0[2] = 0.7976430058479309f;
        D_004FE5B0[3] = 0.0f;
        D_004FE5C0[0] = 1.0f;
        D_004FE5C0[1] = 0.9222670197486877f;
        D_004FE5C0[2] = 0.34179699420928955f;
        D_004FE5C0[3] = 0.0f;
        D_004FE5D0[0] = 1.0f;
        D_004FE5D0[1] = 0.7847639918327332f;
        D_004FE5D0[2] = 0.06054700165987015f;
        D_004FE5D0[3] = 0.04062499850988388f;
        D_004FE5E0[0] = 1.0f;
        D_004FE5E0[1] = 0.800000011920929f;
        D_004FE5E0[2] = 0.44999998807907104f;
        D_004FE5E0[3] = 1.0f;
        D_004FE5F0[0] = 1.0f;
        D_004FE5F0[1] = 0.3281260132789612f;
        D_004FE5F0[2] = 1.0f;
        D_004FE5F0[3] = 0.3539060056209564f;
        D_004FE600[0] = 1.0f;
        D_004FE600[1] = 1.0f;
        D_004FE600[2] = 1.0f;
        D_004FE600[3] = 1.0f;
        D_004FE610[0] = 1.0f;
        D_004FE610[1] = 1.0f;
        D_004FE610[2] = 1.0f;
        D_004FE610[3] = 1.0f;
        D_004FE620[0] = 1.0f;
        D_004FE620[1] = 0.8613290190696716f;
        D_004FE620[2] = 0.38124799728393555f;
        D_004FE620[3] = 0.0f;
        D_004FE630[0] = 1.0f;
        D_004FE630[1] = 1.0f;
        D_004FE630[2] = 1.0f;
        D_004FE630[3] = 1.0f;
        D_004FE640[0] = 1.0f;
        D_004FE640[1] = 0.3244380056858063f;
        D_004FE640[2] = 1.0f;
        D_004FE640[3] = 0.0f;
        D_004FE650[0] = 1.0f;
        D_004FE650[1] = 1.0f;
        D_004FE650[2] = 1.0f;
        D_004FE650[3] = 1.0f;
        D_004FE660[0] = 1.0f;
        D_004FE660[1] = 1.0f;
        D_004FE660[2] = 0.0f;
        D_004FE660[3] = 0.0f;
        D_004FE670[0] = 0.7007060050964355f;
        D_004FE670[1] = 0.0f;
        D_004FE670[2] = 0.0f;
        D_004FE670[3] = 0.0f;
        D_004FE680[0] = 1.0f;
        D_004FE680[1] = 0.7828530073165894f;
        D_004FE680[2] = 0.06140600144863129f;
        D_004FE680[3] = 0.04146299883723259f;
        D_004FE690[0] = 1.0f;
        D_004FE690[1] = 0.32487601041793823f;
        D_004FE690[2] = 1.0f;
        D_004FE690[3] = 0.35280099511146545f;
        D_004FE6A0[0] = 1.0f;
        D_004FE6A0[1] = 1.0f;
        D_004FE6A0[2] = 0.7977359890937805f;
        D_004FE6A0[3] = 0.0f;
        D_004FE6B0[0] = 1.0f;
        D_004FE6B0[1] = 0.4937489926815033f;
        D_004FE6B0[2] = 1.0f;
        D_004FE6B0[3] = 0.49179700016975403f;
        D_004FE6C0[0] = 1.0f;
        D_004FE6C0[1] = 1.0f;
        D_004FE6C0[2] = 1.0f;
        D_004FE6C0[3] = 1.0f;
        D_004FE6D0[0] = 1.0f;
        D_004FE6D0[1] = 0.800000011920929f;
        D_004FE6D0[2] = 1.0f;
        D_004FE6D0[3] = 0.800000011920929f;
        D_004FE6E0[0] = 1.0f;
        D_004FE6E0[1] = 1.0f;
        D_004FE6E0[2] = 0.0f;
        D_004FE6E0[3] = 0.0f;
        D_004FE6F0[0] = 1.0f;
        D_004FE6F0[1] = 1.0f;
        D_004FE6F0[2] = 0.0f;
        D_004FE6F0[3] = 0.0f;
        D_004FE700[0] = 1.0f;
        D_004FE700[1] = 1.0f;
        D_004FE700[2] = 0.0f;
        D_004FE700[3] = 0.0f;
        D_004FE710[0] = 1.0f;
        D_004FE710[1] = 0.3273420035839081f;
        D_004FE710[2] = 1.0f;
        D_004FE710[3] = 0.35390499234199524f;
        D_004FE720[0] = 1.0f;
        D_004FE720[1] = 1.0f;
        D_004FE720[2] = 0.061000000685453415f;
        D_004FE720[3] = 0.039000000804662704f;
        D_004FE730[0] = 1.0f;
        D_004FE730[1] = 1.0f;
        D_004FE730[2] = 0.7999979853630066f;
        D_004FE730[3] = 0.0f;
        D_004FE740[0] = 1.0f;
        D_004FE740[1] = 0.9589840173721313f;
        D_004FE740[2] = 0.6143789887428284f;
        D_004FE740[3] = 0.0f;
        D_004FE750[0] = 1.0f;
        D_004FE750[1] = 0.9285150170326233f;
        D_004FE750[2] = 0.3399839997291565f;
        D_004FE750[3] = 0.0f;
        D_004FE760[0] = 1.0f;
        D_004FE760[1] = 0.8738250136375427f;
        D_004FE760[2] = 0.24931700527668f;
        D_004FE760[3] = 0.017578000202775f;
        D_004FE770[0] = 1.0f;
        D_004FE770[1] = 0.7843739986419678f;
        D_004FE770[2] = 0.06132800132036209f;
        D_004FE770[3] = 0.03945299983024597f;
        D_004FE780[0] = 1.0f;
        D_004FE780[1] = 0.0f;
        D_004FE780[2] = 1.0f;
        D_004FE780[3] = 0.0f;
        D_004FE790[0] = 1.0f;
        D_004FE790[1] = 1.0f;
        D_004FE790[2] = 0.0f;
        D_004FE790[3] = 0.0f;

    }
}
#endif

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

