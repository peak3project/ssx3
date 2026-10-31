#include "common.h"

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", __sti__all_in_one_scripter_cpp);
#ifdef SKIP_ASM
extern float D_004D3798[4];
extern float D_004D37A8[4];
extern float D_004D37B8[4];
extern float D_004D37C8[4];
extern float D_004D37D8[4];
extern float D_004D37E8[4];
extern float D_004D37F8[4];
extern float D_004D3808[4];
extern float D_004D3818[4];
extern float D_004D3828[4];
extern float D_004D3838[4];
extern float D_004D3848[4];
extern float D_004D3858[4];
extern float D_004D3868[4];
extern float D_004D3878[4];
extern float D_004D3888[4];
extern float D_004D3898[4];
extern float D_004D38A8[4];
extern float D_004D38B8[4];
extern float D_004D38C8[4];
extern float D_004D38D8[4];
extern float D_004D38E8[4];
extern float D_004D38F8[4];
extern float D_004D3908[4];
extern float D_004D3918[4];
extern float D_004D3928[4];
extern float D_004D3938[4];
extern float D_004D3948[4];
extern float D_004D3958[4];
extern float D_004D3968[4];
extern float D_004D3978[4];
extern float D_004D3988[4];
extern float D_004D3998[4];
extern float D_004D39A8[4];
extern float D_004D39B8[4];
extern float D_004D39C8[4];
extern float D_004D39D8[4];
extern float D_004D39E8[4];
extern float D_004D39F8[4];
extern float D_004D3A08[4];
extern float D_004D3A18[4];
extern float D_004D3A28[4];
extern float D_004D3A38[4];
extern float D_004D3A48[4];
extern float D_004D3A58[4];
extern float D_004D3A68[4];
extern float D_004D3A78[4];
extern float D_004D3A88[4];
extern float D_004D3A98[4];
extern float D_004D3AA8[4];
extern float D_004D3AB8[4];
extern float D_004D3AC8[4];
extern float D_004D3AD8[4];
extern float D_004D3AE8[4];
extern float D_004D3AF8[4];
extern float D_004D3B08[4];
extern int D_004A51E0;
extern int D_004A51E8;
extern int D_004A51EC;
extern int D_004A51F0[2];
extern int D_004A51F8[2];
extern int D_004A5200[2];
extern int D_004A5208[2];
extern int D_004A5210[2];
extern int D_004A5218[2];
extern int D_004A5220[2];
extern int D_004A5228[2];
extern int D_004A5230[2];
extern int D_004A5238[2];
extern int D_004A5240[2];
extern int D_004A5248[2];
extern int D_004A5250[2];
extern int D_004A5258[2];
extern int D_004A525C;
extern char D_004825F8[];
int GetHashValue32(char*);
static inline void initE(int* p, int n)
{
    *(char*)p = n;
    *p = (*p & 0xFF) | (n << 8);
}
void sti_scr(int init, int prio) __asm__("__sti__all_in_one_scripter_cpp");
void sti_scr(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        *(char*)&D_004A51E0 = -1;
        D_004A51E0 = (D_004A51E0 & 0xFF) | 0xFFFFFF00u;
        D_004D3798[0] = 1.0f;
        D_004D3798[1] = 1.0f;
        D_004D3798[2] = 1.0f;
        D_004D3798[3] = 0.5f;
        D_004D37A8[0] = 0.4998680055141449f;
        D_004D37A8[1] = 1.0f;
        D_004D37A8[2] = 1.0f;
        D_004D37A8[3] = 0.0f;
        D_004D37B8[0] = 0.12951700389385223f;
        D_004D37B8[1] = 1.0f;
        D_004D37B8[2] = 1.0f;
        D_004D37B8[3] = 0.0f;
        D_004D37C8[0] = 0.22426900267601013f;
        D_004D37C8[1] = 0.9402310252189636f;
        D_004D37C8[2] = 0.5425059795379639f;
        D_004D37C8[3] = 0.0004030000127386302f;
        D_004D37D8[0] = 0.4652079939842224f;
        D_004D37D8[1] = 0.32170501351356506f;
        D_004D37D8[2] = 0.9943439960479736f;
        D_004D37D8[3] = 0.0f;
        D_004D37E8[0] = 0.17792600393295288f;
        D_004D37E8[1] = 1.0f;
        D_004D37E8[2] = 1.0f;
        D_004D37E8[3] = 0.0f;
        D_004D37F8[0] = 0.4411740005016327f;
        D_004D37F8[1] = 0.41388601064682007f;
        D_004D37F8[2] = 0.3211260139942169f;
        D_004D37F8[3] = 0.4398239850997925f;
        D_004D3808[0] = 0.500997006893158f;
        D_004D3808[1] = 0.24849599599838257f;
        D_004D3808[2] = 1.0f;
        D_004D3808[3] = 1.0f;
        D_004D3818[0] = 0.27687299251556396f;
        D_004D3818[1] = 0.6395620107650757f;
        D_004D3818[2] = 0.13423900306224823f;
        D_004D3818[3] = 0.0f;
        D_004D3828[0] = 0.8936439752578735f;
        D_004D3828[1] = 0.5263469815254211f;
        D_004D3828[2] = 0.5051450133323669f;
        D_004D3828[3] = 0.8687300086021423f;
        D_004D3838[0] = 1.0f;
        D_004D3838[1] = 1.0f;
        D_004D3838[2] = 1.0f;
        D_004D3838[3] = 1.0f;
        D_004D3848[0] = 1.0f;
        D_004D3848[1] = 0.0f;
        D_004D3848[2] = 0.0f;
        D_004D3848[3] = 0.0f;
        D_004D3858[0] = 1.0f;
        D_004D3858[1] = 0.550000011920929f;
        D_004D3858[2] = 0.5350000262260437f;
        D_004D3858[3] = 0.550000011920929f;
        D_004D3868[0] = 1.0f;
        D_004D3868[1] = 1.0f;
        D_004D3868[2] = 1.0f;
        D_004D3868[3] = 1.0f;
        D_004D3878[0] = 1.0f;
        D_004D3878[1] = 1.0f;
        D_004D3878[2] = 1.0f;
        D_004D3878[3] = 1.0f;
        D_004D3888[0] = 1.0f;
        D_004D3888[1] = 0.0f;
        D_004D3888[2] = 0.0f;
        D_004D3888[3] = 0.0f;
        D_004D3898[0] = 1.0f;
        D_004D3898[1] = 0.0f;
        D_004D3898[2] = 0.0f;
        D_004D3898[3] = 0.0f;
        D_004D38A8[0] = 1.0f;
        D_004D38A8[1] = 1.0f;
        D_004D38A8[2] = 1.0f;
        D_004D38A8[3] = 1.0f;
        D_004D38B8[0] = 1.0f;
        D_004D38B8[1] = 0.5f;
        D_004D38B8[2] = 1.0f;
        D_004D38B8[3] = 0.5f;
        D_004D38C8[0] = 1.0f;
        D_004D38C8[1] = 0.5f;
        D_004D38C8[2] = 1.0f;
        D_004D38C8[3] = 0.5f;
        D_004D38D8[0] = 1.0f;
        D_004D38D8[1] = 0.5f;
        D_004D38D8[2] = 1.0f;
        D_004D38D8[3] = 0.5f;
        D_004D38E8[0] = 1.0f;
        D_004D38E8[1] = 0.7828119993209839f;
        D_004D38E8[2] = 0.06171900033950806f;
        D_004D38E8[3] = 0.03984399884939194f;
        D_004D38F8[0] = 1.0f;
        D_004D38F8[1] = 1.0f;
        D_004D38F8[2] = 0.7988259792327881f;
        D_004D38F8[3] = 0.0f;
        D_004D3908[0] = 0.9886710047721863f;
        D_004D3908[1] = 0.9230499863624573f;
        D_004D3908[2] = 0.34311699867248535f;
        D_004D3908[3] = 0.0f;
        D_004D3918[0] = 1.0f;
        D_004D3918[1] = 1.0f;
        D_004D3918[2] = 1.0f;
        D_004D3918[3] = 1.0f;
        D_004D3928[0] = 1.0f;
        D_004D3928[1] = 1.0f;
        D_004D3928[2] = 0.7976430058479309f;
        D_004D3928[3] = 0.0f;
        D_004D3938[0] = 1.0f;
        D_004D3938[1] = 0.9222670197486877f;
        D_004D3938[2] = 0.34179699420928955f;
        D_004D3938[3] = 0.0f;
        D_004D3948[0] = 1.0f;
        D_004D3948[1] = 0.7847639918327332f;
        D_004D3948[2] = 0.06054700165987015f;
        D_004D3948[3] = 0.04062499850988388f;
        D_004D3958[0] = 1.0f;
        D_004D3958[1] = 0.800000011920929f;
        D_004D3958[2] = 0.44999998807907104f;
        D_004D3958[3] = 1.0f;
        D_004D3968[0] = 1.0f;
        D_004D3968[1] = 0.3281260132789612f;
        D_004D3968[2] = 1.0f;
        D_004D3968[3] = 0.3539060056209564f;
        D_004D3978[0] = 1.0f;
        D_004D3978[1] = 1.0f;
        D_004D3978[2] = 1.0f;
        D_004D3978[3] = 1.0f;
        D_004D3988[0] = 1.0f;
        D_004D3988[1] = 1.0f;
        D_004D3988[2] = 1.0f;
        D_004D3988[3] = 1.0f;
        D_004D3998[0] = 1.0f;
        D_004D3998[1] = 0.8613290190696716f;
        D_004D3998[2] = 0.38124799728393555f;
        D_004D3998[3] = 0.0f;
        D_004D39A8[0] = 1.0f;
        D_004D39A8[1] = 1.0f;
        D_004D39A8[2] = 1.0f;
        D_004D39A8[3] = 1.0f;
        D_004D39B8[0] = 1.0f;
        D_004D39B8[1] = 0.3244380056858063f;
        D_004D39B8[2] = 1.0f;
        D_004D39B8[3] = 0.0f;
        D_004D39C8[0] = 1.0f;
        D_004D39C8[1] = 1.0f;
        D_004D39C8[2] = 1.0f;
        D_004D39C8[3] = 1.0f;
        D_004D39D8[0] = 1.0f;
        D_004D39D8[1] = 1.0f;
        D_004D39D8[2] = 0.0f;
        D_004D39D8[3] = 0.0f;
        D_004D39E8[0] = 0.7007060050964355f;
        D_004D39E8[1] = 0.0f;
        D_004D39E8[2] = 0.0f;
        D_004D39E8[3] = 0.0f;
        D_004D39F8[0] = 1.0f;
        D_004D39F8[1] = 0.7828530073165894f;
        D_004D39F8[2] = 0.06140600144863129f;
        D_004D39F8[3] = 0.04146299883723259f;
        D_004D3A08[0] = 1.0f;
        D_004D3A08[1] = 0.32487601041793823f;
        D_004D3A08[2] = 1.0f;
        D_004D3A08[3] = 0.35280099511146545f;
        D_004D3A18[0] = 1.0f;
        D_004D3A18[1] = 1.0f;
        D_004D3A18[2] = 0.7977359890937805f;
        D_004D3A18[3] = 0.0f;
        D_004D3A28[0] = 1.0f;
        D_004D3A28[1] = 0.4937489926815033f;
        D_004D3A28[2] = 1.0f;
        D_004D3A28[3] = 0.49179700016975403f;
        D_004D3A38[0] = 1.0f;
        D_004D3A38[1] = 1.0f;
        D_004D3A38[2] = 1.0f;
        D_004D3A38[3] = 1.0f;
        D_004D3A48[0] = 1.0f;
        D_004D3A48[1] = 0.800000011920929f;
        D_004D3A48[2] = 1.0f;
        D_004D3A48[3] = 0.800000011920929f;
        D_004D3A58[0] = 1.0f;
        D_004D3A58[1] = 1.0f;
        D_004D3A58[2] = 0.0f;
        D_004D3A58[3] = 0.0f;
        D_004D3A68[0] = 1.0f;
        D_004D3A68[1] = 1.0f;
        D_004D3A68[2] = 0.0f;
        D_004D3A68[3] = 0.0f;
        D_004D3A78[0] = 1.0f;
        D_004D3A78[1] = 1.0f;
        D_004D3A78[2] = 0.0f;
        D_004D3A78[3] = 0.0f;
        D_004D3A88[0] = 1.0f;
        D_004D3A88[1] = 0.3273420035839081f;
        D_004D3A88[2] = 1.0f;
        D_004D3A88[3] = 0.35390499234199524f;
        D_004D3A98[0] = 1.0f;
        D_004D3A98[1] = 1.0f;
        D_004D3A98[2] = 0.061000000685453415f;
        D_004D3A98[3] = 0.039000000804662704f;
        D_004D3AA8[0] = 1.0f;
        D_004D3AA8[1] = 1.0f;
        D_004D3AA8[2] = 0.7999979853630066f;
        D_004D3AA8[3] = 0.0f;
        D_004D3AB8[0] = 1.0f;
        D_004D3AB8[1] = 0.9589840173721313f;
        D_004D3AB8[2] = 0.6143789887428284f;
        D_004D3AB8[3] = 0.0f;
        D_004D3AC8[0] = 1.0f;
        D_004D3AC8[1] = 0.9285150170326233f;
        D_004D3AC8[2] = 0.3399839997291565f;
        D_004D3AC8[3] = 0.0f;
        D_004D3AD8[0] = 1.0f;
        D_004D3AD8[1] = 0.8738250136375427f;
        D_004D3AD8[2] = 0.24931700527668f;
        D_004D3AD8[3] = 0.017578000202775f;
        D_004D3AE8[0] = 1.0f;
        D_004D3AE8[1] = 0.7843739986419678f;
        D_004D3AE8[2] = 0.06132800132036209f;
        D_004D3AE8[3] = 0.03945299983024597f;
        D_004D3AF8[0] = 1.0f;
        D_004D3AF8[1] = 0.0f;
        D_004D3AF8[2] = 1.0f;
        D_004D3AF8[3] = 0.0f;
        D_004D3B08[0] = 1.0f;
        D_004D3B08[1] = 1.0f;
        D_004D3B08[2] = 0.0f;
        D_004D3B08[3] = 0.0f;
        D_004A51EC = 0;
        D_004A51E8 = 0;
        initE(D_004A51F0, 0);
        initE(D_004A51F8, 1);
        initE(D_004A5200, 2);
        initE(D_004A5208, 3);
        initE(D_004A5210, 4);
        initE(D_004A5218, 5);
        initE(D_004A5220, 6);
        initE(D_004A5228, 7);
        initE(D_004A5230, 8);
        initE(D_004A5238, 9);
        initE(D_004A5240, 10);
        initE(D_004A5248, 11);
        initE(D_004A5250, 12);
        initE(D_004A5258, 13);
        D_004A525C = GetHashValue32(D_004825F8);
    }
}
#endif

extern "C" void func_002847A8(void) {
}

extern "C" void func_002847B0(void) {
}

extern "C" void func_002847B8(void) {
}

extern "C" void func_002847C0(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847C8);
#ifdef SKIP_ASM
extern "C" int func_002847C8(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847D0);
#ifdef SKIP_ASM
extern "C" int func_002847D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847D8);
#ifdef SKIP_ASM
extern "C" int func_002847D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (8))) > 0;
}
#endif

extern "C" void func_002847E8(void) {
}

extern "C" void func_002847F0(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847F8);
#ifdef SKIP_ASM
extern "C" int func_002847F8(void) {
    return 1;
}
#endif

extern "C" void func_00284800(void) {
}

extern "C" void func_00284808(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284810);
#ifdef SKIP_ASM
extern "C" int func_00284810(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284818);
#ifdef SKIP_ASM
extern "C" int func_00284818(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2B4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284820);
#ifdef SKIP_ASM
extern "C" int func_00284820(void) {
    return 0;
}
#endif

extern "C" void func_00284828(void) {
}

extern "C" void func_00284830(void) {
}

extern "C" void func_00284838(void) {
}

extern "C" void func_00284840(void) {
}

extern "C" void func_00284848(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284850);
#ifdef SKIP_ASM
extern "C" int func_00284850(void *arg0) {
    return (*(int *)((char*)(arg0) + (8)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284858);
#ifdef SKIP_ASM
extern "C" int func_00284858(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284860);
#ifdef SKIP_ASM
extern "C" void func_00284860(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284868);
#ifdef SKIP_ASM
extern "C" void func_00284868(void *arg0) {
    (*(int *)((char*)(arg0) + (4))) = -1;
}
#endif

extern "C" void func_00284878(void) {
}

extern "C" void func_00284880(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284888);
#ifdef SKIP_ASM
extern "C" int func_00284888(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284890);
#ifdef SKIP_ASM
extern "C" void func_00284890(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284898);
#ifdef SKIP_ASM
extern "C" int func_00284898(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002848A0);
#ifdef SKIP_ASM
extern "C" void func_00283228(void *, int);
extern char D_00482360[];
extern char D_00482398[];

extern "C" void func_002848A0(void *arg0, int flags) {
    *(char **)((char*)arg0 + 0x10) = D_00482360;
    *(char **)((char*)arg0 + 0xC) = D_00482398;
    func_00283228(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002848D0);
#ifdef SKIP_ASM
extern "C" int func_002848D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xF8)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002848D8);
#ifdef SKIP_ASM
extern "C" void func_00283228(void *, int);
void operator_delete(int *);
extern char D_004822E0[];
extern char D_00482318[];

extern "C" void func_002848D8(void *arg0, int arg1) {
    *(char **)((char*)arg0 + 0x18) = D_00482318;
    *(char **)((char*)arg0 + 0x0) = D_004822E0;
    func_00283228((char*)arg0 + 0xC, 0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284940);
#ifdef SKIP_ASM
extern "C" int func_00284940(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284948);
#ifdef SKIP_ASM
extern "C" int func_00284948(int arg0) {
    return arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284950);
#ifdef SKIP_ASM
extern "C" void func_00283228(void *, int);
void operator_delete(int *);
extern char D_00482260[];
extern char D_00482298[];

extern "C" void func_00284950(void *arg0, int arg1) {
    *(char **)((char*)arg0 + 0x18) = D_00482298;
    *(char **)((char*)arg0 + 0x0) = D_00482260;
    func_00283228((char*)arg0 + 0xC, 0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849B8);
#ifdef SKIP_ASM
extern "C" int func_002849B8(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849C0);
#ifdef SKIP_ASM
extern "C" int func_002849C0(int arg0) {
    return arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849C8);
#ifdef SKIP_ASM
extern "C" int func_002849C8(int *arg0) {
    return *arg0 != 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849D8);
#ifdef SKIP_ASM
extern "C" int func_002849D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849E0);
#ifdef SKIP_ASM
extern "C" int func_002849E0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x550))) != 2;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849F0);
#ifdef SKIP_ASM
extern "C" int func_002849F0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x550)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849F8);
#ifdef SKIP_ASM
struct sSlot_49F8 {
    int f0;     // 0x628
    int f4;
    int f8;     // 0x630
    int fC;
};

struct sEngine_49F8 {
    char pad[0x628];
    sSlot_49F8 slots[1];
};

extern "C" int func_002849F8(sEngine_49F8* self, int idx)
{
    int r = 0;
    if (self->slots[idx].f8 == 0) {
        r = self->slots[idx].f0 == 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A28);
#ifdef SKIP_ASM
extern "C" void func_00283228(void* self, int flags);

extern "C" void func_00284A28(void* self, int flags) {
    func_00283228(self, flags);
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A48);
#ifdef SKIP_ASM
extern "C" int func_00284A48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A50);
#ifdef SKIP_ASM
extern "C" float func_00284A50(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x18)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A58);
#ifdef SKIP_ASM
extern "C" int func_00284A58(int arg0) {
    return arg0 + 0x30;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A60);
#ifdef SKIP_ASM
extern "C" float func_00284A60(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x70)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A68);
#ifdef SKIP_ASM
extern "C" float func_00284A68(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x74)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A70);
#ifdef SKIP_ASM
extern "C" float func_00284A70(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x78)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A78);
#ifdef SKIP_ASM
extern "C" int func_00284A78(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A80);
#ifdef SKIP_ASM
extern "C" int func_00284A80(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A88);
#ifdef SKIP_ASM
extern "C" int func_00284A88(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A90);
#ifdef SKIP_ASM
extern "C" int func_00284A90(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A98);
#ifdef SKIP_ASM
extern "C" void func_00284A98(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AA0);
#ifdef SKIP_ASM
extern "C" int func_00284AA0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AA8);
#ifdef SKIP_ASM
extern "C" void func_00283228(void* self, int flags);

extern "C" void func_00284AA8(void* self, int flags) {
    func_00283228(self, flags);
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AC8);
#ifdef SKIP_ASM
extern "C" int func_00284AC8(int arg0) {
    return arg0 + 0x18;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AD0);
#ifdef SKIP_ASM
extern "C" int func_00284AD0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AD8);
#ifdef SKIP_ASM
extern "C" int func_00284AD8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AE0);
#ifdef SKIP_ASM
extern "C" int func_00284AE0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AE8);
#ifdef SKIP_ASM
extern "C" void func_00283228(void *, int);
void operator_delete(int *);
extern char D_00481FD8[];
extern char D_00482018[];

extern "C" void func_00284AE8(void *arg0, int arg1) {
    *(char **)((char*)arg0 + 0x18) = D_00482018;
    *(char **)((char*)arg0 + 0x0) = D_00481FD8;
    func_00283228((char*)arg0 + 0xC, 0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B50);
#ifdef SKIP_ASM
extern "C" int func_00284B50(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B58);
#ifdef SKIP_ASM
extern "C" int func_00284B58(int arg0) {
    return arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B60);
#ifdef SKIP_ASM
extern "C" int func_00284B60(int arg0) {
    return arg0 + 0x30;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B68);
#ifdef SKIP_ASM
extern "C" float func_00284B68(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x70)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B70);
#ifdef SKIP_ASM
extern "C" float func_00284B70(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x74)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B78);
#ifdef SKIP_ASM
extern "C" float func_00284B78(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x78)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B80);
#ifdef SKIP_ASM
extern "C" void __sti__all_in_one_scripter_cpp(int, int);

extern "C" void func_00284B80(void) {
    __sti__all_in_one_scripter_cpp(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284BA0);
#ifdef SKIP_ASM
extern "C" int func_00284BA0(int arg0) {
    return (arg0 != 0) ? 0 : 0x173;
}
#endif
