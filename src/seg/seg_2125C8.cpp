#include "common.h"

//100%
INCLUDE_ASM("seg/seg_2125C8", cAIAnimEventMap_getBlendInTime);
#ifdef SKIP_ASM
struct sEntry_15C8 {
    char b[0x1C];
};
extern sEntry_15C8 D_00446990[];

extern "C" void *cAIAnimEventMap_getBlendInTime(int arg0) {
    return &D_00446990[arg0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2125C8", func_003115E0);
#ifdef SKIP_ASM
struct Range_15E0 {
    short start;
    short count;
};

struct RangeTable_15E0 {
    Range_15E0 r[0x1B6];
};

struct Groups_15E0 {
    int v[0x1D8];
};

extern Groups_15E0 D_00489D60;

// PORT: the unit declares this as void(int); defined under an asm label with its real type
extern "C" void func_003115E0_impl(RangeTable_15E0* t) __asm__("func_003115E0");
extern "C" void func_003115E0_impl(RangeTable_15E0* t)
{
    Groups_15E0 tab = D_00489D60;
    int prev;
    int i, j;
    for (j = 0x1B4; j >= 0; j--) t->r[j].count = 0;
    prev = 0x1B6;
    for (i = 0; i < 0x1D8; i++) {
        int g = tab.v[i];
        if (g != prev) {
            prev = g;
            t->r[g].start = i;
        }
        t->r[prev].count++;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2125C8", func_00311710);
#ifdef SKIP_ASM
struct sAnimProbVar_1710 {
    int value;
    unsigned int prob;
    unsigned int FilterMask;
};

struct sAnimRange_1710 {
    short start;
    short count;
};

struct sAnimRangeTable_1710 {
    sAnimRange_1710 r[0x1B6];
};

extern sAnimProbVar_1710 D_00449960[];
unsigned int AIrand();

extern "C" int func_00311710(sAnimRangeTable_1710* tbl, int anid, unsigned int filterMask)
{
    int vStart = tbl->r[anid].start;
    int vNum = tbl->r[anid].count;
    if (vNum == 1) {
        return D_00449960[vStart].value;
    }
    int vEnd = vStart + vNum;
    unsigned int totProb = 0;
    for (int i = vStart; i < vEnd; i++) {
        if ((D_00449960[i].FilterMask & filterMask) == filterMask) {
            totProb += D_00449960[i].prob;
        }
    }
    int r = AIrand() % totProb;
    for (int i = vStart; i < vEnd; i++) {
        if ((D_00449960[i].FilterMask & filterMask) == filterMask) {
            r -= D_00449960[i].prob;
            if (r <= 0) {
                return D_00449960[i].value;
            }
        }
    }
    return D_00449960[vEnd - 1].value;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2125C8", func_00311860);
#ifdef SKIP_ASM
extern char D_0048A4C0[];

extern "C" void *func_00311860(int anim) {
    return D_0048A4C0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_2125C8", func_00311870);
#ifdef SKIP_ASM
extern "C" int cMemMan_alloc(int, char *, int, int);
extern "C" void func_003115E0(int);
extern char D_0048A4D0[];
extern int D_004A3DFC;

extern "C" void func_00311870(void) {
    int temp_2;

    temp_2 = cMemMan_alloc(0x6D4, D_0048A4D0, 0, 0);
    D_004A3DFC = temp_2;
    func_003115E0(temp_2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2125C8", func_003118A8);
#ifdef SKIP_ASM
extern "C" void operator_delete__FPi(int);
extern int D_004A3DFC;

extern "C" void func_003118A8(void) {
    operator_delete__FPi(D_004A3DFC);
    D_004A3DFC = 0;
}
#endif
