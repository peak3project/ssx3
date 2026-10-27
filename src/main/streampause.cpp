#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0047C520[];
extern void* D_0047D0E8[16];

struct cStreamPause {
    void* vtable;
};

//100%
INCLUDE_ASM("main/streampause", cStreamPause_construct__Fv);
#ifdef SKIP_ASM
cStreamPause* cStreamPause_construct()
{
    cStreamPause* self = (cStreamPause*)cMemMan_alloc(4, D_0047C520, 0x20000000, 0);
    self->vtable = D_0047D0E8;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/streampause", func_00242D50);
#ifdef SKIP_ASM
extern "C" void* func_00242D50(void* self, ...)
{
    return self;
}
#endif
//100%
INCLUDE_ASM("main/streampause", func_00242D90);
#ifdef SKIP_ASM
extern "C" int func_00242D90(signed char *first1, signed char *last1, signed char *first2, signed char *last2) {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (*first1 < *first2) return 1;
        if (*first2 < *first1) return 0;
    }
    return first1 == last1 && first2 != last2;
}
#endif
//100%
INCLUDE_ASM("main/streampause", func_00242DF8);
#ifdef SKIP_ASM
extern "C" int func_00242DF8(signed char *first1, signed char *last1, signed char *first2, signed char *last2) {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (*first1 < *first2) return -1;
        if (*first2 < *first1) return 1;
    }
    if (first2 == last2) return first1 != last1;
    return -1;
}
#endif
//100%
INCLUDE_ASM("main/streampause", func_00242E58);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00242E58(void *self) {
    int **head = *(int ***)((char*)self + 4);
    int **node = (int **)*head;
    int **next;

    while (node != head) {
        next = (int **)*node;
        operator_delete((int*)node);
        node = next;
        head = *(int ***)((char*)self + 4);
    }
    **(int ***)((char*)self + 4) = *(int **)((char*)self + 4);
    *(int ***)((char*)*(int ***)((char*)self + 4) + 4) = *(int ***)((char*)self + 4);
}
#endif

//100%
INCLUDE_ASM("main/streampause", func_00242EB8);
#ifdef SKIP_ASM
extern float D_004C90A8[4];
extern float D_004C90B8[4];
extern float D_004C90C8[4];
extern float D_004C90D8[4];
extern float D_004C90E8[4];
extern float D_004C90F8[4];
extern float D_004C9108[4];
extern float D_004C9118[4];
extern float D_004C9128[4];
extern float D_004C9138[4];
extern float D_004C9148[4];
extern float D_004C9158[4];
extern float D_004C9168[4];
extern float D_004C9178[4];
extern float D_004C9188[4];
extern float D_004C9198[4];
extern float D_004C91A8[4];
extern float D_004C91B8[4];
extern float D_004C91C8[4];
extern float D_004C91D8[4];
extern float D_004C91E8[4];
extern float D_004C91F8[4];
extern float D_004C9208[4];
extern float D_004C9218[4];
extern float D_004C9228[4];
extern float D_004C9238[4];
extern float D_004C9248[4];
extern float D_004C9258[4];
extern float D_004C9268[4];
extern float D_004C9278[4];
extern float D_004C9288[4];
extern float D_004C9298[4];
extern float D_004C92A8[4];
extern float D_004C92B8[4];
extern float D_004C92C8[4];
extern float D_004C92D8[4];
extern float D_004C92E8[4];
extern float D_004C92F8[4];
extern float D_004C9308[4];
extern float D_004C9318[4];
extern float D_004C9328[4];
extern float D_004C9338[4];
extern float D_004C9348[4];
extern float D_004C9358[4];
extern float D_004C9368[4];
extern float D_004C9378[4];
extern float D_004C9388[4];
extern float D_004C9398[4];
extern float D_004C93A8[4];
extern float D_004C93B8[4];
extern float D_004C93C8[4];
extern float D_004C93D8[4];
extern float D_004C93E8[4];
extern float D_004C93F8[4];
extern float D_004C9408[4];
extern float D_004C9418[4];
extern int D_004A4F68;
extern int D_004A4F70;
extern int D_004A4F74;
extern int D_004A4F78[2];
extern int D_004A4F80[2];
extern int D_004A4F88[2];
extern int D_004A4F90[2];
extern int D_004A4F98[2];
extern int D_004A4FA0[2];
extern int D_004A4FA8[2];
extern int D_004A4FB0[2];
extern int D_004A4FB8[2];
extern int D_004A4FC0[2];
extern int D_004A4FC8[2];
extern int D_004A4FD0[2];
extern int D_004A4FD8[2];
extern int D_004A4FE0[2];
extern char D_004C9428[];
extern char D_004C9548[];
extern "C" void* cSSXApp_cSSXApp(void*);
void* func_00317930(void*);
extern "C" void cBXString__cBXString(void*, int);
void cAppMan__cAppMan(void*, int);
static inline void initE(int* p, int n)
{
    *(char*)p = n;
    *p = (*p & 0xFF) | (n << 8);
}
void sti_00242EB8(int init, int prio) __asm__("func_00242EB8");
void sti_00242EB8(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init) {
            D_004C90A8[0] = 1.0f;
            D_004C90A8[1] = 1.0f;
            D_004C90A8[2] = 1.0f;
            D_004C90A8[3] = 0.5f;
            D_004C90B8[0] = 0.4998680055141449f;
            D_004C90B8[1] = 1.0f;
            D_004C90B8[2] = 1.0f;
            D_004C90B8[3] = 0.0f;
            D_004C90C8[0] = 0.12951700389385223f;
            D_004C90C8[1] = 1.0f;
            D_004C90C8[2] = 1.0f;
            D_004C90C8[3] = 0.0f;
            D_004C90D8[0] = 0.22426900267601013f;
            D_004C90D8[1] = 0.9402310252189636f;
            D_004C90D8[2] = 0.5425059795379639f;
            D_004C90D8[3] = 0.0004030000127386302f;
            D_004C90E8[0] = 0.4652079939842224f;
            D_004C90E8[1] = 0.32170501351356506f;
            D_004C90E8[2] = 0.9943439960479736f;
            D_004C90E8[3] = 0.0f;
            D_004C90F8[0] = 0.17792600393295288f;
            D_004C90F8[1] = 1.0f;
            D_004C90F8[2] = 1.0f;
            D_004C90F8[3] = 0.0f;
            D_004C9108[0] = 0.4411740005016327f;
            D_004C9108[1] = 0.41388601064682007f;
            D_004C9108[2] = 0.3211260139942169f;
            D_004C9108[3] = 0.4398239850997925f;
            D_004C9118[0] = 0.500997006893158f;
            D_004C9118[1] = 0.24849599599838257f;
            D_004C9118[2] = 1.0f;
            D_004C9118[3] = 1.0f;
            D_004C9128[0] = 0.27687299251556396f;
            D_004C9128[1] = 0.6395620107650757f;
            D_004C9128[2] = 0.13423900306224823f;
            D_004C9128[3] = 0.0f;
            D_004C9138[0] = 0.8936439752578735f;
            D_004C9138[1] = 0.5263469815254211f;
            D_004C9138[2] = 0.5051450133323669f;
            D_004C9138[3] = 0.8687300086021423f;
            D_004C9148[0] = 1.0f;
            D_004C9148[1] = 1.0f;
            D_004C9148[2] = 1.0f;
            D_004C9148[3] = 1.0f;
            D_004C9158[0] = 1.0f;
            D_004C9158[1] = 0.0f;
            D_004C9158[2] = 0.0f;
            D_004C9158[3] = 0.0f;
            D_004C9168[0] = 1.0f;
            D_004C9168[1] = 0.550000011920929f;
            D_004C9168[2] = 0.5350000262260437f;
            D_004C9168[3] = 0.550000011920929f;
            D_004C9178[0] = 1.0f;
            D_004C9178[1] = 1.0f;
            D_004C9178[2] = 1.0f;
            D_004C9178[3] = 1.0f;
            D_004C9188[0] = 1.0f;
            D_004C9188[1] = 1.0f;
            D_004C9188[2] = 1.0f;
            D_004C9188[3] = 1.0f;
            D_004C9198[0] = 1.0f;
            D_004C9198[1] = 0.0f;
            D_004C9198[2] = 0.0f;
            D_004C9198[3] = 0.0f;
            D_004C91A8[0] = 1.0f;
            D_004C91A8[1] = 0.0f;
            D_004C91A8[2] = 0.0f;
            D_004C91A8[3] = 0.0f;
            D_004C91B8[0] = 1.0f;
            D_004C91B8[1] = 1.0f;
            D_004C91B8[2] = 1.0f;
            D_004C91B8[3] = 1.0f;
            D_004C91C8[0] = 1.0f;
            D_004C91C8[1] = 0.5f;
            D_004C91C8[2] = 1.0f;
            D_004C91C8[3] = 0.5f;
            D_004C91D8[0] = 1.0f;
            D_004C91D8[1] = 0.5f;
            D_004C91D8[2] = 1.0f;
            D_004C91D8[3] = 0.5f;
            D_004C91E8[0] = 1.0f;
            D_004C91E8[1] = 0.5f;
            D_004C91E8[2] = 1.0f;
            D_004C91E8[3] = 0.5f;
            D_004C91F8[0] = 1.0f;
            D_004C91F8[1] = 0.7828119993209839f;
            D_004C91F8[2] = 0.06171900033950806f;
            D_004C91F8[3] = 0.03984399884939194f;
            D_004C9208[0] = 1.0f;
            D_004C9208[1] = 1.0f;
            D_004C9208[2] = 0.7988259792327881f;
            D_004C9208[3] = 0.0f;
            D_004C9218[0] = 0.9886710047721863f;
            D_004C9218[1] = 0.9230499863624573f;
            D_004C9218[2] = 0.34311699867248535f;
            D_004C9218[3] = 0.0f;
            D_004C9228[0] = 1.0f;
            D_004C9228[1] = 1.0f;
            D_004C9228[2] = 1.0f;
            D_004C9228[3] = 1.0f;
            D_004C9238[0] = 1.0f;
            D_004C9238[1] = 1.0f;
            D_004C9238[2] = 0.7976430058479309f;
            D_004C9238[3] = 0.0f;
            D_004C9248[0] = 1.0f;
            D_004C9248[1] = 0.9222670197486877f;
            D_004C9248[2] = 0.34179699420928955f;
            D_004C9248[3] = 0.0f;
            D_004C9258[0] = 1.0f;
            D_004C9258[1] = 0.7847639918327332f;
            D_004C9258[2] = 0.06054700165987015f;
            D_004C9258[3] = 0.04062499850988388f;
            D_004C9268[0] = 1.0f;
            D_004C9268[1] = 0.800000011920929f;
            D_004C9268[2] = 0.44999998807907104f;
            D_004C9268[3] = 1.0f;
            D_004C9278[0] = 1.0f;
            D_004C9278[1] = 0.3281260132789612f;
            D_004C9278[2] = 1.0f;
            D_004C9278[3] = 0.3539060056209564f;
            D_004C9288[0] = 1.0f;
            D_004C9288[1] = 1.0f;
            D_004C9288[2] = 1.0f;
            D_004C9288[3] = 1.0f;
            D_004C9298[0] = 1.0f;
            D_004C9298[1] = 1.0f;
            D_004C9298[2] = 1.0f;
            D_004C9298[3] = 1.0f;
            D_004C92A8[0] = 1.0f;
            D_004C92A8[1] = 0.8613290190696716f;
            D_004C92A8[2] = 0.38124799728393555f;
            D_004C92A8[3] = 0.0f;
            D_004C92B8[0] = 1.0f;
            D_004C92B8[1] = 1.0f;
            D_004C92B8[2] = 1.0f;
            D_004C92B8[3] = 1.0f;
            D_004C92C8[0] = 1.0f;
            D_004C92C8[1] = 0.3244380056858063f;
            D_004C92C8[2] = 1.0f;
            D_004C92C8[3] = 0.0f;
            D_004C92D8[0] = 1.0f;
            D_004C92D8[1] = 1.0f;
            D_004C92D8[2] = 1.0f;
            D_004C92D8[3] = 1.0f;
            D_004C92E8[0] = 1.0f;
            D_004C92E8[1] = 1.0f;
            D_004C92E8[2] = 0.0f;
            D_004C92E8[3] = 0.0f;
            D_004C92F8[0] = 0.7007060050964355f;
            D_004C92F8[1] = 0.0f;
            D_004C92F8[2] = 0.0f;
            D_004C92F8[3] = 0.0f;
            D_004C9308[0] = 1.0f;
            D_004C9308[1] = 0.7828530073165894f;
            D_004C9308[2] = 0.06140600144863129f;
            D_004C9308[3] = 0.04146299883723259f;
            D_004C9318[0] = 1.0f;
            D_004C9318[1] = 0.32487601041793823f;
            D_004C9318[2] = 1.0f;
            D_004C9318[3] = 0.35280099511146545f;
            D_004C9328[0] = 1.0f;
            D_004C9328[1] = 1.0f;
            D_004C9328[2] = 0.7977359890937805f;
            D_004C9328[3] = 0.0f;
            D_004C9338[0] = 1.0f;
            D_004C9338[1] = 0.4937489926815033f;
            D_004C9338[2] = 1.0f;
            D_004C9338[3] = 0.49179700016975403f;
            D_004C9348[0] = 1.0f;
            D_004C9348[1] = 1.0f;
            D_004C9348[2] = 1.0f;
            D_004C9348[3] = 1.0f;
            D_004C9358[0] = 1.0f;
            D_004C9358[1] = 0.800000011920929f;
            D_004C9358[2] = 1.0f;
            D_004C9358[3] = 0.800000011920929f;
            D_004C9368[0] = 1.0f;
            D_004C9368[1] = 1.0f;
            D_004C9368[2] = 0.0f;
            D_004C9368[3] = 0.0f;
            D_004C9378[0] = 1.0f;
            D_004C9378[1] = 1.0f;
            D_004C9378[2] = 0.0f;
            D_004C9378[3] = 0.0f;
            D_004C9388[0] = 1.0f;
            D_004C9388[1] = 1.0f;
            D_004C9388[2] = 0.0f;
            D_004C9388[3] = 0.0f;
            D_004C9398[0] = 1.0f;
            D_004C9398[1] = 0.3273420035839081f;
            D_004C9398[2] = 1.0f;
            D_004C9398[3] = 0.35390499234199524f;
            D_004C93A8[0] = 1.0f;
            D_004C93A8[1] = 1.0f;
            D_004C93A8[2] = 0.061000000685453415f;
            D_004C93A8[3] = 0.039000000804662704f;
            D_004C93B8[0] = 1.0f;
            D_004C93B8[1] = 1.0f;
            D_004C93B8[2] = 0.7999979853630066f;
            D_004C93B8[3] = 0.0f;
            D_004C93C8[0] = 1.0f;
            D_004C93C8[1] = 0.9589840173721313f;
            D_004C93C8[2] = 0.6143789887428284f;
            D_004C93C8[3] = 0.0f;
            D_004C93D8[0] = 1.0f;
            D_004C93D8[1] = 0.9285150170326233f;
            D_004C93D8[2] = 0.3399839997291565f;
            D_004C93D8[3] = 0.0f;
            D_004C93E8[0] = 1.0f;
            D_004C93E8[1] = 0.8738250136375427f;
            D_004C93E8[2] = 0.24931700527668f;
            D_004C93E8[3] = 0.017578000202775f;
            D_004C93F8[0] = 1.0f;
            D_004C93F8[1] = 0.7843739986419678f;
            D_004C93F8[2] = 0.06132800132036209f;
            D_004C93F8[3] = 0.03945299983024597f;
            D_004C9408[0] = 1.0f;
            D_004C9408[1] = 0.0f;
            D_004C9408[2] = 1.0f;
            D_004C9408[3] = 0.0f;
            D_004C9418[0] = 1.0f;
            D_004C9418[1] = 1.0f;
            D_004C9418[2] = 0.0f;
            D_004C9418[3] = 0.0f;
            *(char*)&D_004A4F68 = -1;
            D_004A4F68 = (D_004A4F68 & 0xFF) | 0xFFFFFF00u;
            D_004A4F74 = 0;
            D_004A4F70 = 0;
            initE(D_004A4F78, 0);
            initE(D_004A4F80, 1);
            initE(D_004A4F88, 2);
            initE(D_004A4F90, 3);
            initE(D_004A4F98, 4);
            initE(D_004A4FA0, 5);
            initE(D_004A4FA8, 6);
            initE(D_004A4FB0, 7);
            initE(D_004A4FB8, 8);
            initE(D_004A4FC0, 9);
            initE(D_004A4FC8, 10);
            initE(D_004A4FD0, 11);
            initE(D_004A4FD8, 12);
            initE(D_004A4FE0, 13);
            cSSXApp_cSSXApp(D_004C9428);
            func_00317930(D_004C9548);
        } else {
            char* p = D_004C9428;
            cBXString__cBXString(p + 0xCC, 2);
            cBXString__cBXString(p + 0xC8, 2);
            cBXString__cBXString(p + 0xC4, 2);
            cAppMan__cAppMan(p, 2);
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/streampause", func_00243838);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0047D6E8[];
extern void* D_0046D970[];

extern "C" void func_00243838(void* self, int flags)
{
    void** m = D_0047D6E8;
    *(void***)((char*)self + 0x0) = D_0046D970;
    *(void***)((char*)self + 0x1F8) = m;
    *(void***)((char*)self + 0x1E8) = m;
    *(void***)((char*)self + 0x1C4) = m;
    *(void***)((char*)self + 0x1A8) = m;
    *(void***)((char*)self + 0x198) = m;
    *(void***)((char*)self + 0x184) = m;
    *(void***)((char*)self + 0x164) = m;
    *(void***)((char*)self + 0x154) = m;
    *(void***)((char*)self + 0x144) = m;
    *(void***)((char*)self + 0x134) = m;
    *(void***)((char*)self + 0x124) = m;
    *(void***)((char*)self + 0x10C) = m;
    *(void***)((char*)self + 0xFC) = m;
    *(void***)((char*)self + 0xEC) = m;
    *(void***)((char*)self + 0xDC) = m;
    *(void***)((char*)self + 0xBC) = m;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/streampause", func_002438B0);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_0046D970[];

extern "C" void func_002438B0(void *self, int flags) {
    *(void***)((char*)self + 0) = D_0046D970;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/streampause", func_002438E0);
#ifdef SKIP_ASM
extern "C" void func_002438E0(void) {

}
#endif
//100%
INCLUDE_ASM("main/streampause", func_002438E8);
#ifdef SKIP_ASM
extern "C" void func_002438E8(void) {

}
#endif
