#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cWorldPainterQuery_cWorldPainterQuery(void* self, void* arg);
extern const char D_00483DE8[];

struct cWorldPainterManArg {
    void* field_0x0;
};

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", cWorldPainterMan_getQuery__FPvP19cWorldPainterManArg);
#ifdef SKIP_ASM
void* cWorldPainterMan_getQuery(void* self, cWorldPainterManArg* x)
{
    void* mem = cMemMan_alloc(0x18, D_00483DE8, 0, 0);
    void* arg = x->field_0x0;
    return cWorldPainterQuery_cWorldPainterQuery(mem, arg);
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0AA0);
#ifdef SKIP_ASM
extern "C" void func_002C0AA0(void* self, int* dst, int* src, float t)
{
    if (t == 1.0f) {
        *dst = *src;
    } else {
        *dst = (int)((float)*dst * (1.0f - t) + (float)*src * t);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0AF0);
#ifdef SKIP_ASM
extern "C" void func_002C0AF0(void* self, float* dst, float* src, float t)
{
    if (t == 1.0f) {
        *dst = *src;
    } else {
        *dst = *dst * (1.0f - t) + *src * t;
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0B30);
#ifdef SKIP_ASM
extern "C" void* func_002C0B30(void* a, ...)
{
    return a;
}
#endif
//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0B70);
#ifdef SKIP_ASM
extern float D_004D4638[4];
extern float D_004D4648[4];
extern float D_004D4658[4];
extern float D_004D4668[4];
extern float D_004D4678[4];
extern float D_004D4688[4];
extern float D_004D4698[4];
extern float D_004D46A8[4];
extern float D_004D46B8[4];
extern float D_004D46C8[4];
extern float D_004D46D8[4];
extern float D_004D46E8[4];
extern float D_004D46F8[4];
extern float D_004D4708[4];
extern float D_004D4718[4];
extern float D_004D4728[4];
extern float D_004D4738[4];
extern float D_004D4748[4];
extern float D_004D4758[4];
extern float D_004D4768[4];
extern float D_004D4778[4];
extern float D_004D4788[4];
extern float D_004D4798[4];
extern float D_004D47A8[4];
extern float D_004D47B8[4];
extern float D_004D47C8[4];
extern float D_004D47D8[4];
extern float D_004D47E8[4];
extern float D_004D47F8[4];
extern float D_004D4808[4];
extern float D_004D4818[4];
extern float D_004D4828[4];
extern float D_004D4838[4];
extern float D_004D4848[4];
extern float D_004D4858[4];
extern float D_004D4868[4];
extern float D_004D4878[4];
extern float D_004D4888[4];
extern float D_004D4898[4];
extern float D_004D48A8[4];
extern float D_004D48B8[4];
extern float D_004D48C8[4];
extern float D_004D48D8[4];
extern float D_004D48E8[4];
extern float D_004D48F8[4];
extern float D_004D4908[4];
extern float D_004D4918[4];
extern float D_004D4928[4];
extern float D_004D4938[4];
extern float D_004D4948[4];
extern float D_004D4958[4];
extern float D_004D4968[4];
extern float D_004D4978[4];
extern float D_004D4988[4];
extern float D_004D4998[4];
extern float D_004D49A8[4];
extern int D_004A53D4;
extern int D_004A53D0;
extern int D_004A53D8[2];
extern int D_004A53E0[2];
extern int D_004A53E8[2];
extern int D_004A53F0[2];
extern int D_004A53F8[2];
extern int D_004A5400[2];
extern int D_004A5408[2];
extern int D_004A5410[2];
extern int D_004A5418[2];
extern int D_004A5420[2];
extern int D_004A5428[2];
extern int D_004A5430[2];
extern int D_004A5438[2];
extern int D_004A5440[2];
static inline void initE(int* p, int n)
{
    *(char*)p = n;
    *p = (*p & 0xFF) | (n << 8);
}
void sti_002C0B70(int init, int prio) __asm__("func_002C0B70");
void sti_002C0B70(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004D4638[0] = 1.0f;
        D_004D4638[1] = 1.0f;
        D_004D4638[2] = 1.0f;
        D_004D4638[3] = 0.5f;
        D_004D4648[0] = 0.4998680055141449f;
        D_004D4648[1] = 1.0f;
        D_004D4648[2] = 1.0f;
        D_004D4648[3] = 0.0f;
        D_004D4658[0] = 0.12951700389385223f;
        D_004D4658[1] = 1.0f;
        D_004D4658[2] = 1.0f;
        D_004D4658[3] = 0.0f;
        D_004D4668[0] = 0.22426900267601013f;
        D_004D4668[1] = 0.9402310252189636f;
        D_004D4668[2] = 0.5425059795379639f;
        D_004D4668[3] = 0.0004030000127386302f;
        D_004D4678[0] = 0.4652079939842224f;
        D_004D4678[1] = 0.32170501351356506f;
        D_004D4678[2] = 0.9943439960479736f;
        D_004D4678[3] = 0.0f;
        D_004D4688[0] = 0.17792600393295288f;
        D_004D4688[1] = 1.0f;
        D_004D4688[2] = 1.0f;
        D_004D4688[3] = 0.0f;
        D_004D4698[0] = 0.4411740005016327f;
        D_004D4698[1] = 0.41388601064682007f;
        D_004D4698[2] = 0.3211260139942169f;
        D_004D4698[3] = 0.4398239850997925f;
        D_004D46A8[0] = 0.500997006893158f;
        D_004D46A8[1] = 0.24849599599838257f;
        D_004D46A8[2] = 1.0f;
        D_004D46A8[3] = 1.0f;
        D_004D46B8[0] = 0.27687299251556396f;
        D_004D46B8[1] = 0.6395620107650757f;
        D_004D46B8[2] = 0.13423900306224823f;
        D_004D46B8[3] = 0.0f;
        D_004D46C8[0] = 0.8936439752578735f;
        D_004D46C8[1] = 0.5263469815254211f;
        D_004D46C8[2] = 0.5051450133323669f;
        D_004D46C8[3] = 0.8687300086021423f;
        D_004D46D8[0] = 1.0f;
        D_004D46D8[1] = 1.0f;
        D_004D46D8[2] = 1.0f;
        D_004D46D8[3] = 1.0f;
        D_004D46E8[0] = 1.0f;
        D_004D46E8[1] = 0.0f;
        D_004D46E8[2] = 0.0f;
        D_004D46E8[3] = 0.0f;
        D_004D46F8[0] = 1.0f;
        D_004D46F8[1] = 0.550000011920929f;
        D_004D46F8[2] = 0.5350000262260437f;
        D_004D46F8[3] = 0.550000011920929f;
        D_004D4708[0] = 1.0f;
        D_004D4708[1] = 1.0f;
        D_004D4708[2] = 1.0f;
        D_004D4708[3] = 1.0f;
        D_004D4718[0] = 1.0f;
        D_004D4718[1] = 1.0f;
        D_004D4718[2] = 1.0f;
        D_004D4718[3] = 1.0f;
        D_004D4728[0] = 1.0f;
        D_004D4728[1] = 0.0f;
        D_004D4728[2] = 0.0f;
        D_004D4728[3] = 0.0f;
        D_004D4738[0] = 1.0f;
        D_004D4738[1] = 0.0f;
        D_004D4738[2] = 0.0f;
        D_004D4738[3] = 0.0f;
        D_004D4748[0] = 1.0f;
        D_004D4748[1] = 1.0f;
        D_004D4748[2] = 1.0f;
        D_004D4748[3] = 1.0f;
        D_004D4758[0] = 1.0f;
        D_004D4758[1] = 0.5f;
        D_004D4758[2] = 1.0f;
        D_004D4758[3] = 0.5f;
        D_004D4768[0] = 1.0f;
        D_004D4768[1] = 0.5f;
        D_004D4768[2] = 1.0f;
        D_004D4768[3] = 0.5f;
        D_004D4778[0] = 1.0f;
        D_004D4778[1] = 0.5f;
        D_004D4778[2] = 1.0f;
        D_004D4778[3] = 0.5f;
        D_004D4788[0] = 1.0f;
        D_004D4788[1] = 0.7828119993209839f;
        D_004D4788[2] = 0.06171900033950806f;
        D_004D4788[3] = 0.03984399884939194f;
        D_004D4798[0] = 1.0f;
        D_004D4798[1] = 1.0f;
        D_004D4798[2] = 0.7988259792327881f;
        D_004D4798[3] = 0.0f;
        D_004D47A8[0] = 0.9886710047721863f;
        D_004D47A8[1] = 0.9230499863624573f;
        D_004D47A8[2] = 0.34311699867248535f;
        D_004D47A8[3] = 0.0f;
        D_004D47B8[0] = 1.0f;
        D_004D47B8[1] = 1.0f;
        D_004D47B8[2] = 1.0f;
        D_004D47B8[3] = 1.0f;
        D_004D47C8[0] = 1.0f;
        D_004D47C8[1] = 1.0f;
        D_004D47C8[2] = 0.7976430058479309f;
        D_004D47C8[3] = 0.0f;
        D_004D47D8[0] = 1.0f;
        D_004D47D8[1] = 0.9222670197486877f;
        D_004D47D8[2] = 0.34179699420928955f;
        D_004D47D8[3] = 0.0f;
        D_004D47E8[0] = 1.0f;
        D_004D47E8[1] = 0.7847639918327332f;
        D_004D47E8[2] = 0.06054700165987015f;
        D_004D47E8[3] = 0.04062499850988388f;
        D_004D47F8[0] = 1.0f;
        D_004D47F8[1] = 0.800000011920929f;
        D_004D47F8[2] = 0.44999998807907104f;
        D_004D47F8[3] = 1.0f;
        D_004D4808[0] = 1.0f;
        D_004D4808[1] = 0.3281260132789612f;
        D_004D4808[2] = 1.0f;
        D_004D4808[3] = 0.3539060056209564f;
        D_004D4818[0] = 1.0f;
        D_004D4818[1] = 1.0f;
        D_004D4818[2] = 1.0f;
        D_004D4818[3] = 1.0f;
        D_004D4828[0] = 1.0f;
        D_004D4828[1] = 1.0f;
        D_004D4828[2] = 1.0f;
        D_004D4828[3] = 1.0f;
        D_004D4838[0] = 1.0f;
        D_004D4838[1] = 0.8613290190696716f;
        D_004D4838[2] = 0.38124799728393555f;
        D_004D4838[3] = 0.0f;
        D_004D4848[0] = 1.0f;
        D_004D4848[1] = 1.0f;
        D_004D4848[2] = 1.0f;
        D_004D4848[3] = 1.0f;
        D_004D4858[0] = 1.0f;
        D_004D4858[1] = 0.3244380056858063f;
        D_004D4858[2] = 1.0f;
        D_004D4858[3] = 0.0f;
        D_004D4868[0] = 1.0f;
        D_004D4868[1] = 1.0f;
        D_004D4868[2] = 1.0f;
        D_004D4868[3] = 1.0f;
        D_004D4878[0] = 1.0f;
        D_004D4878[1] = 1.0f;
        D_004D4878[2] = 0.0f;
        D_004D4878[3] = 0.0f;
        D_004D4888[0] = 0.7007060050964355f;
        D_004D4888[1] = 0.0f;
        D_004D4888[2] = 0.0f;
        D_004D4888[3] = 0.0f;
        D_004D4898[0] = 1.0f;
        D_004D4898[1] = 0.7828530073165894f;
        D_004D4898[2] = 0.06140600144863129f;
        D_004D4898[3] = 0.04146299883723259f;
        D_004D48A8[0] = 1.0f;
        D_004D48A8[1] = 0.32487601041793823f;
        D_004D48A8[2] = 1.0f;
        D_004D48A8[3] = 0.35280099511146545f;
        D_004D48B8[0] = 1.0f;
        D_004D48B8[1] = 1.0f;
        D_004D48B8[2] = 0.7977359890937805f;
        D_004D48B8[3] = 0.0f;
        D_004D48C8[0] = 1.0f;
        D_004D48C8[1] = 0.4937489926815033f;
        D_004D48C8[2] = 1.0f;
        D_004D48C8[3] = 0.49179700016975403f;
        D_004D48D8[0] = 1.0f;
        D_004D48D8[1] = 1.0f;
        D_004D48D8[2] = 1.0f;
        D_004D48D8[3] = 1.0f;
        D_004D48E8[0] = 1.0f;
        D_004D48E8[1] = 0.800000011920929f;
        D_004D48E8[2] = 1.0f;
        D_004D48E8[3] = 0.800000011920929f;
        D_004D48F8[0] = 1.0f;
        D_004D48F8[1] = 1.0f;
        D_004D48F8[2] = 0.0f;
        D_004D48F8[3] = 0.0f;
        D_004D4908[0] = 1.0f;
        D_004D4908[1] = 1.0f;
        D_004D4908[2] = 0.0f;
        D_004D4908[3] = 0.0f;
        D_004D4918[0] = 1.0f;
        D_004D4918[1] = 1.0f;
        D_004D4918[2] = 0.0f;
        D_004D4918[3] = 0.0f;
        D_004D4928[0] = 1.0f;
        D_004D4928[1] = 0.3273420035839081f;
        D_004D4928[2] = 1.0f;
        D_004D4928[3] = 0.35390499234199524f;
        D_004D4938[0] = 1.0f;
        D_004D4938[1] = 1.0f;
        D_004D4938[2] = 0.061000000685453415f;
        D_004D4938[3] = 0.039000000804662704f;
        D_004D4948[0] = 1.0f;
        D_004D4948[1] = 1.0f;
        D_004D4948[2] = 0.7999979853630066f;
        D_004D4948[3] = 0.0f;
        D_004D4958[0] = 1.0f;
        D_004D4958[1] = 0.9589840173721313f;
        D_004D4958[2] = 0.6143789887428284f;
        D_004D4958[3] = 0.0f;
        D_004D4968[0] = 1.0f;
        D_004D4968[1] = 0.9285150170326233f;
        D_004D4968[2] = 0.3399839997291565f;
        D_004D4968[3] = 0.0f;
        D_004D4978[0] = 1.0f;
        D_004D4978[1] = 0.8738250136375427f;
        D_004D4978[2] = 0.24931700527668f;
        D_004D4978[3] = 0.017578000202775f;
        D_004D4988[0] = 1.0f;
        D_004D4988[1] = 0.7843739986419678f;
        D_004D4988[2] = 0.06132800132036209f;
        D_004D4988[3] = 0.03945299983024597f;
        D_004D4998[0] = 1.0f;
        D_004D4998[1] = 0.0f;
        D_004D4998[2] = 1.0f;
        D_004D4998[3] = 0.0f;
        D_004D49A8[0] = 1.0f;
        D_004D49A8[1] = 1.0f;
        D_004D49A8[2] = 0.0f;
        D_004D49A8[3] = 0.0f;
        D_004A53D4 = 0;
        D_004A53D0 = 0;
        initE(D_004A53D8, 0);
        initE(D_004A53E0, 1);
        initE(D_004A53E8, 2);
        initE(D_004A53F0, 3);
        initE(D_004A53F8, 4);
        initE(D_004A5400, 5);
        initE(D_004A5408, 6);
        initE(D_004A5410, 7);
        initE(D_004A5418, 8);
        initE(D_004A5420, 9);
        initE(D_004A5428, 10);
        initE(D_004A5430, 11);
        initE(D_004A5438, 12);
        initE(D_004A5440, 13);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1458__FPv);
#ifdef SKIP_ASM
void func_002C1458(void* self)
{
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1460);
#ifdef SKIP_ASM
extern void* D_00485D30[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_002C1460(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00485D30;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1490__FPv);
#ifdef SKIP_ASM
void* func_002C1490(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1498__FPv);
#ifdef SKIP_ASM
void* func_002C1498(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14A0__FPv);
#ifdef SKIP_ASM
void* func_002C14A0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14A8__FPv);
#ifdef SKIP_ASM
void* func_002C14A8(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14B0__FPv);
#ifdef SKIP_ASM
void* func_002C14B0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14B8__FPv);
#ifdef SKIP_ASM
void* func_002C14B8(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14C0__FPv);
#ifdef SKIP_ASM
void* func_002C14C0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14C8__FPv);
#ifdef SKIP_ASM
void* func_002C14C8(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14D0__FPv);
#ifdef SKIP_ASM
void* func_002C14D0(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14D8__FPv);
#ifdef SKIP_ASM
void* func_002C14D8(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14E0__FPv);
#ifdef SKIP_ASM
void* func_002C14E0(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14E8__FPv);
#ifdef SKIP_ASM
void* func_002C14E8(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14F0__FPv);
#ifdef SKIP_ASM
void* func_002C14F0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14F8__FPv);
#ifdef SKIP_ASM
void* func_002C14F8(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1500__FPv);
#ifdef SKIP_ASM
void* func_002C1500(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1508__FPv);
#ifdef SKIP_ASM
void* func_002C1508(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1510__FPv);
#ifdef SKIP_ASM
void* func_002C1510(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1518__FPv);
#ifdef SKIP_ASM
void* func_002C1518(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1520__FPv);
#ifdef SKIP_ASM
void* func_002C1520(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1528__FPv);
#ifdef SKIP_ASM
void* func_002C1528(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1530__FPv);
#ifdef SKIP_ASM
void* func_002C1530(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1538__FPv);
#ifdef SKIP_ASM
void* func_002C1538(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1540__FPv);
#ifdef SKIP_ASM
void* func_002C1540(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1548__FPv);
#ifdef SKIP_ASM
void* func_002C1548(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1550__FPv);
#ifdef SKIP_ASM
void* func_002C1550(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1558__FPv);
#ifdef SKIP_ASM
void* func_002C1558(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1560__FPv);
#ifdef SKIP_ASM
void* func_002C1560(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1568__FPv);
#ifdef SKIP_ASM
void* func_002C1568(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1570__FPv);
#ifdef SKIP_ASM
void* func_002C1570(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1578__FPv);
#ifdef SKIP_ASM
void* func_002C1578(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1580__FPv);
#ifdef SKIP_ASM
void* func_002C1580(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1588__FPv);
#ifdef SKIP_ASM
void* func_002C1588(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1590__FPv);
#ifdef SKIP_ASM
void* func_002C1590(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1598__FPv);
#ifdef SKIP_ASM
void* func_002C1598(void* self)
{
    return (char*)self + 0x40;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15A0__FPv);
#ifdef SKIP_ASM
void* func_002C15A0(void* self)
{
    return (char*)self + 0x48;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15A8__FPv);
#ifdef SKIP_ASM
void* func_002C15A8(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15B0__FPv);
#ifdef SKIP_ASM
void* func_002C15B0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15B8__FPv);
#ifdef SKIP_ASM
void* func_002C15B8(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15C0__FPv);
#ifdef SKIP_ASM
void* func_002C15C0(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15C8__FPv);
#ifdef SKIP_ASM
void* func_002C15C8(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15D0__FPv);
#ifdef SKIP_ASM
void* func_002C15D0(void* self)
{
    return (char*)self + 0x48;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15D8__FPv);
#ifdef SKIP_ASM
void* func_002C15D8(void* self)
{
    return (char*)self + 0x50;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15E0__FPv);
#ifdef SKIP_ASM
void* func_002C15E0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15E8__FPv);
#ifdef SKIP_ASM
void* func_002C15E8(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15F0__FPv);
#ifdef SKIP_ASM
void* func_002C15F0(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15F8__FPv);
#ifdef SKIP_ASM
void* func_002C15F8(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1600__FPv);
#ifdef SKIP_ASM
void* func_002C1600(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1608__FPv);
#ifdef SKIP_ASM
void* func_002C1608(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1610__FPv);
#ifdef SKIP_ASM
void* func_002C1610(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1618__FPv);
#ifdef SKIP_ASM
void* func_002C1618(void* self)
{
    return (char*)self + 0x40;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1620__FPv);
#ifdef SKIP_ASM
void* func_002C1620(void* self)
{
    return (char*)self + 0x48;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1628__FPv);
#ifdef SKIP_ASM
void* func_002C1628(void* self)
{
    return (char*)self + 0x50;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1630__FPv);
#ifdef SKIP_ASM
void* func_002C1630(void* self)
{
    return (char*)self + 0x58;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1638__FPv);
#ifdef SKIP_ASM
void* func_002C1638(void* self)
{
    return (char*)self + 0x60;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1640__FPv);
#ifdef SKIP_ASM
void* func_002C1640(void* self)
{
    return (char*)self + 0x68;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1648__FPv);
#ifdef SKIP_ASM
void* func_002C1648(void* self)
{
    return (char*)self + 0x70;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1650__FPv);
#ifdef SKIP_ASM
void* func_002C1650(void* self)
{
    return (char*)self + 0x78;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1658__FPv);
#ifdef SKIP_ASM
void* func_002C1658(void* self)
{
    return (char*)self + 0x80;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1660__FPv);
#ifdef SKIP_ASM
void* func_002C1660(void* self)
{
    return (char*)self + 0x88;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1668__FPv);
#ifdef SKIP_ASM
void* func_002C1668(void* self)
{
    return (char*)self + 0x90;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1670__FPv);
#ifdef SKIP_ASM
void* func_002C1670(void* self)
{
    return (char*)self + 0x98;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1678__FPv);
#ifdef SKIP_ASM
void* func_002C1678(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1680__FPv);
#ifdef SKIP_ASM
void* func_002C1680(void* self)
{
    return (char*)self + 0x10;
}
#endif

extern "C" void* func_002C0B70(int, int);

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1688__FPv);
#ifdef SKIP_ASM
void* func_002C1688(void* self)
{
    return func_002C0B70(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C16A8);
#ifdef SKIP_ASM
extern "C" void func_002C16A8(int self, int a, int b)
{
    *(int*)(self + 4) = a;
    *(int*)self = b;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C16B8);
#ifdef SKIP_ASM
extern "C" void func_002C16B8(unsigned short* p, unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    p[0] = (a << 1) | 1;
    p[1] = (b << 1) | (p[1] & 1);
    p[2] = (c << 1) | (p[2] & 1);
    p[3] = (d << 1) | (p[3] & 1);
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1718);
#ifdef SKIP_ASM
extern "C" void func_002C1718(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1728);
#ifdef SKIP_ASM
extern "C" unsigned short cQuadTree_getFreeNode();
extern "C" void func_002C16A8(int, int, int);

extern "C" void *func_002C1728(void *arg0, int arg1, int arg2, float fparg0, float fparg1, float fparg2) {
    (*(int *)((char*)(arg0) + (0x24))) = 0;
    (*(int *)((char*)(arg0) + (0x20))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(float *)((char*)(arg0) + (4))) = fparg0;
    (*(float *)((char*)(arg0) + (8))) = fparg1;
    (*(float *)((char*)(arg0) + (0))) = (float) (32768.0f / fparg2);
    (*(unsigned short *)((char*)(arg0) + (0x14))) = cQuadTree_getFreeNode();
    (*(short *)((char*)(arg0) + (0x16))) = 0;
    func_002C16A8((*(int *)((char*)(arg0) + (0x20))) + ((*(unsigned short *)((char*)(arg0) + (0x14))) * 8), arg1, arg2);
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
    (*(int *)((char*)(arg0) + (0x18))) = arg2;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C17C0__FPv);
#ifdef SKIP_ASM
void func_002C17C0(void* self)
{
    void* t0 = (char*)self + 0x28;
    *(void**)((char*)self + 0x20) = t0;
    *(void**)((char*)self + 0x24) = t0;
}
#endif

