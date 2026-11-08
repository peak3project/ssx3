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

//100%
INCLUDE_ASM("animation/gameanimmap", func_00315A20);
#ifdef SKIP_ASM
extern float D_004FE920[8];
extern float D_004FE940[8];
extern float D_004FE960[8];
extern float D_004FE980[8];
extern float D_004FE9A0[8];
extern float D_004FE9C0[8];
extern float D_004FE9E0[8];
extern float D_004FEA00[8];
extern float D_004FEA20[8];
extern float D_004FEA40[4];
extern float D_004FEA50[4];
extern float D_004FEA60[4];
extern float D_004FEA70[4];
extern float D_004FEA80[4];
extern float D_004FEA90[4];
extern float D_004FEAA0[4];
extern float D_004FEAB0[4];
extern float D_004FEAC0[4];
extern float D_004FEAD0[4];
extern float D_004FEAE0[4];
extern float D_004FEAF0[4];
extern float D_004FEB00[4];
extern float D_004FEB10[4];
extern float D_004FEB20[4];
extern float D_004FEB30[8];
extern float D_004FEB50[8];
extern float D_004FEB70[8];
extern float D_004FEB90[8];
extern float D_004FEBB0[8];
extern float D_004FEBD0[8];
extern float D_004FEBF0[8];
extern float D_004FEC10[8];
extern float D_004FEC30[8];
extern float D_004FEC50[8];
extern float D_004FEC70[8];
extern float D_004FEC90[8];
extern float D_004FECB0[8];
extern float D_004FECD0[8];
extern float D_004FECF0[8];
extern float D_004FED10[8];
extern float D_004FED30[8];
extern float D_004FED50[8];
extern float D_004FED70[4];
extern float D_004FED80[4];
extern float D_004FED90[4];
extern float D_004FEDA0[4];
extern float D_004FEDB0[4];
extern float D_004FEDC0[4];
extern float D_004FEDD0[4];
extern float D_004FEDE0[4];
extern float D_004FEDF0[4];
extern float D_004FEE00[4];
extern float D_004FEE10[4];
extern float D_004FEE20[4];
extern float D_004FEE30[4];
extern float D_004FEE40[4];
extern float D_004FEE50[4];
extern float D_004FEE60[4];
extern float D_004FEE70[4];
extern float D_004FEE80[4];
extern float D_004FEE90[4];
extern float D_004FEEA0[4];
extern float D_004FEEB0[4];
extern float D_004FEEC0[4];
extern float D_004FEED0[4];
extern float D_004FEEE0[4];
extern float D_004FEEF0[4];
extern float D_004FEF00[4];
extern float D_004FEF10[4];
extern float D_004FEF20[4];
extern float D_004FEF30[4];
extern float D_004FEF40[4];
extern float D_004FEF50[4];
extern float D_004FEF60[4];
extern float D_004FEF70[4];
extern float D_004FEF80[4];
extern float D_004FEF90[4];
extern float D_004FEFA0[4];
extern float D_004FEFB0[4];
extern float D_004FEFC0[4];
extern float D_004FEFD0[4];
extern float D_004FEFE0[4];
extern float D_004FEFF0[4];
void sti_00315A20(int init, int prio) __asm__("func_00315A20");
void sti_00315A20(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004FE920[0] = 0.0f;
        D_004FE920[1] = 0.20000000298023224f;
        D_004FE920[2] = 0.4000000059604645f;
        D_004FE920[3] = 0.4000000059604645f;
        D_004FE920[4] = 0.6000000238418579f;
        D_004FE920[5] = 0.4000000059604645f;
        D_004FE920[6] = 1.0f;
        D_004FE920[7] = 0.20000000298023224f;
        D_004FE940[0] = 0.0f;
        D_004FE940[1] = 0.30000001192092896f;
        D_004FE940[2] = 0.4000000059604645f;
        D_004FE940[3] = 1.2000000476837158f;
        D_004FE940[4] = 0.6000000238418579f;
        D_004FE940[5] = 1.2000000476837158f;
        D_004FE940[6] = 1.0f;
        D_004FE940[7] = 0.30000001192092896f;
        D_004FE960[0] = 0.0f;
        D_004FE960[1] = 0.20000000298023224f;
        D_004FE960[2] = 40.517601013183594f;
        D_004FE960[3] = 0.8055530190467834f;
        D_004FE960[4] = 50.945098876953125f;
        D_004FE960[5] = 0.35607799887657166f;
        D_004FE960[6] = 120.0f;
        D_004FE960[7] = 0.2501629889011383f;
        D_004FE980[0] = 0.0f;
        D_004FE980[1] = 1.750789999961853f;
        D_004FE980[2] = 49.37540054321289f;
        D_004FE980[3] = 1.7348599433898926f;
        D_004FE980[4] = 79.97119903564453f;
        D_004FE980[5] = 1.7510600090026855f;
        D_004FE980[6] = 120.0f;
        D_004FE980[7] = 0.885142982006073f;
        D_004FE9A0[0] = 0.0f;
        D_004FE9A0[1] = 40.959598541259766f;
        D_004FE9A0[2] = 20.827800750732422f;
        D_004FE9A0[3] = 10.0f;
        D_004FE9A0[4] = 50.08369827270508f;
        D_004FE9A0[5] = 10.0f;
        D_004FE9A0[6] = 120.0f;
        D_004FE9A0[7] = 10.0f;
        D_004FE9C0[0] = 0.0f;
        D_004FE9C0[1] = 1.0614099502563477f;
        D_004FE9C0[2] = 20.654800415039062f;
        D_004FE9C0[3] = 1.1025999784469604f;
        D_004FE9C0[4] = 68.0f;
        D_004FE9C0[5] = 1.022879958152771f;
        D_004FE9C0[6] = 120.0f;
        D_004FE9C0[7] = 1.0f;
        D_004FE9E0[0] = 0.0f;
        D_004FE9E0[1] = 0.0f;
        D_004FE9E0[2] = 22.6156005859375f;
        D_004FE9E0[3] = 0.0f;
        D_004FE9E0[4] = 41.7135009765625f;
        D_004FE9E0[5] = 0.0f;
        D_004FE9E0[6] = 120.0f;
        D_004FE9E0[7] = 0.0f;
        D_004FEA00[0] = 0.0f;
        D_004FEA00[1] = 0.9511110186576843f;
        D_004FEA00[2] = 45.61130142211914f;
        D_004FEA00[3] = 0.952904999256134f;
        D_004FEA00[4] = 100.22699737548828f;
        D_004FEA00[5] = 0.9505529999732971f;
        D_004FEA00[6] = 120.0f;
        D_004FEA00[7] = 0.9033470153808594f;
        D_004FEA20[0] = 0.0f;
        D_004FEA20[1] = 0.8039699792861938f;
        D_004FEA20[2] = 40.09749984741211f;
        D_004FEA20[3] = 0.7641159892082214f;
        D_004FEA20[4] = 90.90560150146484f;
        D_004FEA20[5] = 0.7656030058860779f;
        D_004FEA20[6] = 120.0f;
        D_004FEA20[7] = 0.7000259757041931f;
        D_004FEA40[0] = 1.0f;
        D_004FEA40[1] = 1.0f;
        D_004FEA40[2] = 1.0f;
        D_004FEA40[3] = 0.5f;
        D_004FEA50[0] = 0.4998680055141449f;
        D_004FEA50[1] = 1.0f;
        D_004FEA50[2] = 1.0f;
        D_004FEA50[3] = 0.0f;
        D_004FEA60[0] = 0.12951700389385223f;
        D_004FEA60[1] = 1.0f;
        D_004FEA60[2] = 1.0f;
        D_004FEA60[3] = 0.0f;
        D_004FEA70[0] = 0.22426900267601013f;
        D_004FEA70[1] = 0.9402310252189636f;
        D_004FEA70[2] = 0.5425059795379639f;
        D_004FEA70[3] = 0.0004030000127386302f;
        D_004FEA80[0] = 0.4652079939842224f;
        D_004FEA80[1] = 0.32170501351356506f;
        D_004FEA80[2] = 0.9943439960479736f;
        D_004FEA80[3] = 0.0f;
        D_004FEA90[0] = 0.17792600393295288f;
        D_004FEA90[1] = 1.0f;
        D_004FEA90[2] = 1.0f;
        D_004FEA90[3] = 0.0f;
        D_004FEAA0[0] = 0.4411740005016327f;
        D_004FEAA0[1] = 0.41388601064682007f;
        D_004FEAA0[2] = 0.3211260139942169f;
        D_004FEAA0[3] = 0.4398239850997925f;
        D_004FEAB0[0] = 0.500997006893158f;
        D_004FEAB0[1] = 0.24849599599838257f;
        D_004FEAB0[2] = 1.0f;
        D_004FEAB0[3] = 1.0f;
        D_004FEAC0[0] = 0.27687299251556396f;
        D_004FEAC0[1] = 0.6395620107650757f;
        D_004FEAC0[2] = 0.13423900306224823f;
        D_004FEAC0[3] = 0.0f;
        D_004FEAD0[0] = 0.8936439752578735f;
        D_004FEAD0[1] = 0.5263469815254211f;
        D_004FEAD0[2] = 0.5051450133323669f;
        D_004FEAD0[3] = 0.8687300086021423f;
        D_004FEAE0[0] = 1.0f;
        D_004FEAE0[1] = 1.0f;
        D_004FEAE0[2] = 1.0f;
        D_004FEAE0[3] = 1.0f;
        D_004FEAF0[0] = 1.0f;
        D_004FEAF0[1] = 0.0f;
        D_004FEAF0[2] = 0.0f;
        D_004FEAF0[3] = 0.0f;
        D_004FEB00[0] = 1.0f;
        D_004FEB00[1] = 0.550000011920929f;
        D_004FEB00[2] = 0.5350000262260437f;
        D_004FEB00[3] = 0.550000011920929f;
        D_004FEB10[0] = 1.0f;
        D_004FEB10[1] = 1.0f;
        D_004FEB10[2] = 1.0f;
        D_004FEB10[3] = 1.0f;
        D_004FEB20[0] = 1.0f;
        D_004FEB20[1] = 1.0f;
        D_004FEB20[2] = 1.0f;
        D_004FEB20[3] = 1.0f;
        D_004FEB30[0] = 0.0f;
        D_004FEB30[1] = 0.004000000189989805f;
        D_004FEB30[2] = 40.0f;
        D_004FEB30[3] = 0.017000000923871994f;
        D_004FEB30[4] = 80.0f;
        D_004FEB30[5] = 0.03999999910593033f;
        D_004FEB30[6] = 120.0f;
        D_004FEB30[7] = 0.07000000029802322f;
        D_004FEB50[0] = 0.0f;
        D_004FEB50[1] = 0.004000000189989805f;
        D_004FEB50[2] = 40.0f;
        D_004FEB50[3] = 0.017000000923871994f;
        D_004FEB50[4] = 80.0f;
        D_004FEB50[5] = 0.03999999910593033f;
        D_004FEB50[6] = 120.0f;
        D_004FEB50[7] = 0.07000000029802322f;
        D_004FEB70[0] = 0.0f;
        D_004FEB70[1] = 0.011993000283837318f;
        D_004FEB70[2] = 25.0f;
        D_004FEB70[3] = 0.13333700597286224f;
        D_004FEB70[4] = 81.0f;
        D_004FEB70[5] = 0.26667100191116333f;
        D_004FEB70[6] = 120.0f;
        D_004FEB70[7] = 0.3500039875507355f;
        D_004FEB90[0] = 0.0f;
        D_004FEB90[1] = 0.004000000189989805f;
        D_004FEB90[2] = 40.0f;
        D_004FEB90[3] = 0.017000000923871994f;
        D_004FEB90[4] = 80.0f;
        D_004FEB90[5] = 0.03999999910593033f;
        D_004FEB90[6] = 120.0f;
        D_004FEB90[7] = 0.07000000029802322f;
        D_004FEBB0[0] = 0.0f;
        D_004FEBB0[1] = 0.0f;
        D_004FEBB0[2] = 67.0f;
        D_004FEBB0[3] = 0.1464100033044815f;
        D_004FEBB0[4] = 101.0f;
        D_004FEBB0[5] = 0.4130750000476837f;
        D_004FEBB0[6] = 120.0f;
        D_004FEBB0[7] = 0.9000040292739868f;
        D_004FEBD0[0] = 0.0f;
        D_004FEBD0[1] = 0.0038499999791383743f;
        D_004FEBD0[2] = 18.0f;
        D_004FEBD0[3] = 0.07051700353622437f;
        D_004FEBD0[4] = 82.0f;
        D_004FEBD0[5] = 0.07051700353622437f;
        D_004FEBD0[6] = 120.0f;
        D_004FEBD0[7] = 0.07051700353622437f;
        D_004FEBF0[0] = 0.0f;
        D_004FEBF0[1] = 0.017000000923871994f;
        D_004FEBF0[2] = 67.0f;
        D_004FEBF0[3] = 0.25666698813438416f;
        D_004FEBF0[4] = 97.0f;
        D_004FEBF0[5] = 0.7566670179367065f;
        D_004FEBF0[6] = 120.0f;
        D_004FEBF0[7] = 1.6699999570846558f;
        D_004FEC10[0] = 0.0f;
        D_004FEC10[1] = 0.0f;
        D_004FEC10[2] = 67.0f;
        D_004FEC10[3] = 0.1464100033044815f;
        D_004FEC10[4] = 101.0f;
        D_004FEC10[5] = 0.4130750000476837f;
        D_004FEC10[6] = 120.0f;
        D_004FEC10[7] = 0.9000040292739868f;
        D_004FEC30[0] = 0.0f;
        D_004FEC30[1] = 0.0f;
        D_004FEC30[2] = 67.0f;
        D_004FEC30[3] = 0.1464100033044815f;
        D_004FEC30[4] = 101.0f;
        D_004FEC30[5] = 0.4130750000476837f;
        D_004FEC30[6] = 120.0f;
        D_004FEC30[7] = 0.9000040292739868f;
        D_004FEC50[0] = 0.0f;
        D_004FEC50[1] = 0.0f;
        D_004FEC50[2] = 30.0f;
        D_004FEC50[3] = 0.05000000074505806f;
        D_004FEC50[4] = 80.0f;
        D_004FEC50[5] = 0.11666599661111832f;
        D_004FEC50[6] = 120.0f;
        D_004FEC50[7] = 0.1333329975605011f;
        D_004FEC70[0] = 0.0f;
        D_004FEC70[1] = 0.004000000189989805f;
        D_004FEC70[2] = 40.0f;
        D_004FEC70[3] = 0.017000000923871994f;
        D_004FEC70[4] = 80.0f;
        D_004FEC70[5] = 0.03999999910593033f;
        D_004FEC70[6] = 120.0f;
        D_004FEC70[7] = 0.07000000029802322f;
        D_004FEC90[0] = 0.0f;
        D_004FEC90[1] = 0.012039000168442726f;
        D_004FEC90[2] = 28.0f;
        D_004FEC90[3] = 0.1333339959383011f;
        D_004FEC90[4] = 83.0f;
        D_004FEC90[5] = 0.2666670083999634f;
        D_004FEC90[6] = 120.0f;
        D_004FEC90[7] = 0.31666699051856995f;
        D_004FECB0[0] = 0.0f;
        D_004FECB0[1] = 0.056666601449251175f;
        D_004FECB0[2] = 50.0f;
        D_004FECB0[3] = 0.056666601449251175f;
        D_004FECB0[4] = 80.5999984741211f;
        D_004FECB0[5] = 0.12333299964666367f;
        D_004FECB0[6] = 120.0f;
        D_004FECB0[7] = 0.12333299964666367f;
        D_004FECD0[0] = 0.0f;
        D_004FECD0[1] = 0.0f;
        D_004FECD0[2] = 67.0f;
        D_004FECD0[3] = 0.1464100033044815f;
        D_004FECD0[4] = 101.0f;
        D_004FECD0[5] = 0.4130750000476837f;
        D_004FECD0[6] = 120.0f;
        D_004FECD0[7] = 0.9000040292739868f;
        D_004FECF0[0] = 0.0f;
        D_004FECF0[1] = 0.0f;
        D_004FECF0[2] = 67.0f;
        D_004FECF0[3] = 0.1464100033044815f;
        D_004FECF0[4] = 101.0f;
        D_004FECF0[5] = 0.4130750000476837f;
        D_004FECF0[6] = 120.0f;
        D_004FECF0[7] = 0.9000040292739868f;
        D_004FED10[0] = 0.0f;
        D_004FED10[1] = 0.0f;
        D_004FED10[2] = 67.0f;
        D_004FED10[3] = 0.1464100033044815f;
        D_004FED10[4] = 101.0f;
        D_004FED10[5] = 0.4130750000476837f;
        D_004FED10[6] = 120.0f;
        D_004FED10[7] = 0.9000040292739868f;
        D_004FED30[0] = 0.0f;
        D_004FED30[1] = 0.004000000189989805f;
        D_004FED30[2] = 40.0f;
        D_004FED30[3] = 0.017000000923871994f;
        D_004FED30[4] = 80.0f;
        D_004FED30[5] = 0.03999999910593033f;
        D_004FED30[6] = 120.0f;
        D_004FED30[7] = 0.07000000029802322f;
        D_004FED50[0] = 0.0f;
        D_004FED50[1] = 0.0f;
        D_004FED50[2] = 67.0f;
        D_004FED50[3] = 0.1464100033044815f;
        D_004FED50[4] = 101.0f;
        D_004FED50[5] = 0.4130750000476837f;
        D_004FED50[6] = 120.0f;
        D_004FED50[7] = 0.9000040292739868f;
        D_004FED70[0] = 1.0f;
        D_004FED70[1] = 0.0f;
        D_004FED70[2] = 0.0f;
        D_004FED70[3] = 0.0f;
        D_004FED80[0] = 1.0f;
        D_004FED80[1] = 0.0f;
        D_004FED80[2] = 0.0f;
        D_004FED80[3] = 0.0f;
        D_004FED90[0] = 1.0f;
        D_004FED90[1] = 1.0f;
        D_004FED90[2] = 1.0f;
        D_004FED90[3] = 1.0f;
        D_004FEDA0[0] = 1.0f;
        D_004FEDA0[1] = 0.5f;
        D_004FEDA0[2] = 1.0f;
        D_004FEDA0[3] = 0.5f;
        D_004FEDB0[0] = 1.0f;
        D_004FEDB0[1] = 0.5f;
        D_004FEDB0[2] = 1.0f;
        D_004FEDB0[3] = 0.5f;
        D_004FEDC0[0] = 1.0f;
        D_004FEDC0[1] = 0.5f;
        D_004FEDC0[2] = 1.0f;
        D_004FEDC0[3] = 0.5f;
        D_004FEDD0[0] = 1.0f;
        D_004FEDD0[1] = 0.7828119993209839f;
        D_004FEDD0[2] = 0.06171900033950806f;
        D_004FEDD0[3] = 0.03984399884939194f;
        D_004FEDE0[0] = 1.0f;
        D_004FEDE0[1] = 1.0f;
        D_004FEDE0[2] = 0.7988259792327881f;
        D_004FEDE0[3] = 0.0f;
        D_004FEDF0[0] = 0.9886710047721863f;
        D_004FEDF0[1] = 0.9230499863624573f;
        D_004FEDF0[2] = 0.34311699867248535f;
        D_004FEDF0[3] = 0.0f;
        D_004FEE00[0] = 1.0f;
        D_004FEE00[1] = 1.0f;
        D_004FEE00[2] = 1.0f;
        D_004FEE00[3] = 1.0f;
        D_004FEE10[0] = 1.0f;
        D_004FEE10[1] = 1.0f;
        D_004FEE10[2] = 0.7976430058479309f;
        D_004FEE10[3] = 0.0f;
        D_004FEE20[0] = 1.0f;
        D_004FEE20[1] = 0.9222670197486877f;
        D_004FEE20[2] = 0.34179699420928955f;
        D_004FEE20[3] = 0.0f;
        D_004FEE30[0] = 1.0f;
        D_004FEE30[1] = 0.7847639918327332f;
        D_004FEE30[2] = 0.06054700165987015f;
        D_004FEE30[3] = 0.04062499850988388f;
        D_004FEE40[0] = 1.0f;
        D_004FEE40[1] = 0.800000011920929f;
        D_004FEE40[2] = 0.44999998807907104f;
        D_004FEE40[3] = 1.0f;
        D_004FEE50[0] = 1.0f;
        D_004FEE50[1] = 0.3281260132789612f;
        D_004FEE50[2] = 1.0f;
        D_004FEE50[3] = 0.3539060056209564f;
        D_004FEE60[0] = 1.0f;
        D_004FEE60[1] = 1.0f;
        D_004FEE60[2] = 1.0f;
        D_004FEE60[3] = 1.0f;
        D_004FEE70[0] = 1.0f;
        D_004FEE70[1] = 1.0f;
        D_004FEE70[2] = 1.0f;
        D_004FEE70[3] = 1.0f;
        D_004FEE80[0] = 1.0f;
        D_004FEE80[1] = 0.8613290190696716f;
        D_004FEE80[2] = 0.38124799728393555f;
        D_004FEE80[3] = 0.0f;
        D_004FEE90[0] = 1.0f;
        D_004FEE90[1] = 1.0f;
        D_004FEE90[2] = 1.0f;
        D_004FEE90[3] = 1.0f;
        D_004FEEA0[0] = 1.0f;
        D_004FEEA0[1] = 0.3244380056858063f;
        D_004FEEA0[2] = 1.0f;
        D_004FEEA0[3] = 0.0f;
        D_004FEEB0[0] = 1.0f;
        D_004FEEB0[1] = 1.0f;
        D_004FEEB0[2] = 1.0f;
        D_004FEEB0[3] = 1.0f;
        D_004FEEC0[0] = 1.0f;
        D_004FEEC0[1] = 1.0f;
        D_004FEEC0[2] = 0.0f;
        D_004FEEC0[3] = 0.0f;
        D_004FEED0[0] = 0.7007060050964355f;
        D_004FEED0[1] = 0.0f;
        D_004FEED0[2] = 0.0f;
        D_004FEED0[3] = 0.0f;
        D_004FEEE0[0] = 1.0f;
        D_004FEEE0[1] = 0.7828530073165894f;
        D_004FEEE0[2] = 0.06140600144863129f;
        D_004FEEE0[3] = 0.04146299883723259f;
        D_004FEEF0[0] = 1.0f;
        D_004FEEF0[1] = 0.32487601041793823f;
        D_004FEEF0[2] = 1.0f;
        D_004FEEF0[3] = 0.35280099511146545f;
        D_004FEF00[0] = 1.0f;
        D_004FEF00[1] = 1.0f;
        D_004FEF00[2] = 0.7977359890937805f;
        D_004FEF00[3] = 0.0f;
        D_004FEF10[0] = 1.0f;
        D_004FEF10[1] = 0.4937489926815033f;
        D_004FEF10[2] = 1.0f;
        D_004FEF10[3] = 0.49179700016975403f;
        D_004FEF20[0] = 1.0f;
        D_004FEF20[1] = 1.0f;
        D_004FEF20[2] = 1.0f;
        D_004FEF20[3] = 1.0f;
        D_004FEF30[0] = 1.0f;
        D_004FEF30[1] = 0.800000011920929f;
        D_004FEF30[2] = 1.0f;
        D_004FEF30[3] = 0.800000011920929f;
        D_004FEF40[0] = 1.0f;
        D_004FEF40[1] = 1.0f;
        D_004FEF40[2] = 0.0f;
        D_004FEF40[3] = 0.0f;
        D_004FEF50[0] = 1.0f;
        D_004FEF50[1] = 1.0f;
        D_004FEF50[2] = 0.0f;
        D_004FEF50[3] = 0.0f;
        D_004FEF60[0] = 1.0f;
        D_004FEF60[1] = 1.0f;
        D_004FEF60[2] = 0.0f;
        D_004FEF60[3] = 0.0f;
        D_004FEF70[0] = 1.0f;
        D_004FEF70[1] = 0.3273420035839081f;
        D_004FEF70[2] = 1.0f;
        D_004FEF70[3] = 0.35390499234199524f;
        D_004FEF80[0] = 1.0f;
        D_004FEF80[1] = 1.0f;
        D_004FEF80[2] = 0.061000000685453415f;
        D_004FEF80[3] = 0.039000000804662704f;
        D_004FEF90[0] = 1.0f;
        D_004FEF90[1] = 1.0f;
        D_004FEF90[2] = 0.7999979853630066f;
        D_004FEF90[3] = 0.0f;
        D_004FEFA0[0] = 1.0f;
        D_004FEFA0[1] = 0.9589840173721313f;
        D_004FEFA0[2] = 0.6143789887428284f;
        D_004FEFA0[3] = 0.0f;
        D_004FEFB0[0] = 1.0f;
        D_004FEFB0[1] = 0.9285150170326233f;
        D_004FEFB0[2] = 0.3399839997291565f;
        D_004FEFB0[3] = 0.0f;
        D_004FEFC0[0] = 1.0f;
        D_004FEFC0[1] = 0.8738250136375427f;
        D_004FEFC0[2] = 0.24931700527668f;
        D_004FEFC0[3] = 0.017578000202775f;
        D_004FEFD0[0] = 1.0f;
        D_004FEFD0[1] = 0.7843739986419678f;
        D_004FEFD0[2] = 0.06132800132036209f;
        D_004FEFD0[3] = 0.03945299983024597f;
        D_004FEFE0[0] = 1.0f;
        D_004FEFE0[1] = 0.0f;
        D_004FEFE0[2] = 1.0f;
        D_004FEFE0[3] = 0.0f;
        D_004FEFF0[0] = 1.0f;
        D_004FEFF0[1] = 1.0f;
        D_004FEFF0[2] = 0.0f;
        D_004FEFF0[3] = 0.0f;
    }
}
#endif

extern "C" void* func_00315A20(int, int);

//100%
INCLUDE_ASM("animation/gameanimmap", func_00316878__FPv);
#ifdef SKIP_ASM
void* func_00316878(void* self)
{
    return func_00315A20(1, 0xffff);
}
#endif

