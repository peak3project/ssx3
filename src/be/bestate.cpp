#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sStateSingleton {
    void* field_0x0;
    void* vtable;
};

extern const char D_004A1230[];
extern void* D_0045ABE8[16];
extern void* D_004A122C;

//99.86%
INCLUDE_ASM("be/bestate", cBERaceState_getState__FPv);
#ifdef SKIP_ASM
void* cBERaceState_getState(void* self)
{
    if (D_004A122C == 0) {
        sStateSingleton* mem = (sStateSingleton*)cMemMan_alloc(8, D_004A1230, 0, 0);
        mem->field_0x0 = self;
        mem->vtable = D_0045ABE8;
        D_004A122C = mem;
    }
    return D_004A122C;
}
#endif

//100%
INCLUDE_ASM("be/bestate", func_001530E0);
#ifdef SKIP_ASM
void* cBENewRaceInterface_getThis();
void* cBENewPlayerInterface_getThis();
extern "C" void* func_0014EDD8();
extern "C" void* func_00147F78();
void* cBEOptionInterface_getThis();
void* cBEBAGTInterface_getThis();
void* cBENetworkInterface_getThis();
void* cBEScoreInterface_getThis();
extern "C" void* func_0014ABE0();
void* cBEMissionInterface_getThis();
void* cBEEconInterface_getThis();
void* cBEAggressionInterface_getThis();
void* cBERewardInterface_getThis();
void* cBESaveInterface_getThis();

// Returns the backend interface singleton for the given kind.
extern "C" void* func_001530E0(void* self, int kind)
{
    switch (kind) {
    case 0:
        return cBENewRaceInterface_getThis();
    case 1:
        return cBENewPlayerInterface_getThis();
    case 2:
        return func_0014EDD8();
    case 3:
        return func_00147F78();
    case 4:
        return cBEOptionInterface_getThis();
    case 6:
        return cBEBAGTInterface_getThis();
    case 7:
        return cBENetworkInterface_getThis();
    case 8:
        return cBEScoreInterface_getThis();
    case 9:
        return func_0014ABE0();
    case 10:
        return cBEMissionInterface_getThis();
    case 11:
        return cBEEconInterface_getThis();
    case 12:
        return cBEAggressionInterface_getThis();
    case 13:
        return cBERewardInterface_getThis();
    case 5:
        return cBESaveInterface_getThis();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/bestate", func_00153200);
#ifdef SKIP_ASM
struct sStateObj153200 {
    int f0;
    int f4;
    int f8;
};
extern sStateObj153200* D_004A11B4;
extern sStateObj153200* D_004A11C0;
extern sStateObj153200* D_004A11C8;
extern sStateObj153200* D_004A120C;
extern sStateObj153200* D_004A1214;
extern sStateObj153200* D_004A121C;
extern sStateObj153200* D_004A1238;
extern sStateObj153200* D_004A1248;
extern sStateObj153200* D_004A124C;
extern sStateObj153200* D_004A1264;

extern "C" void func_00153200(void) {
    D_004A120C->f8 = 0;
    D_004A1248->f8 = 0;
    D_004A11C8->f8 = 0;
    D_004A11C0->f8 = 0;
    D_004A11B4->f8 = 0;
    D_004A1238->f8 = 0;
    D_004A1214->f8 = 0;
    D_004A124C->f8 = 0;
    D_004A1264->f8 = 0;
    D_004A121C->f8 = 0;
}
#endif

//100%
INCLUDE_ASM("be/bestate", func_00153258);
#ifdef SKIP_ASM
extern sStateObj153200* D_004A11C8;
extern sStateObj153200* D_004A120C;
extern sStateObj153200* D_004A1214;
extern sStateObj153200* D_004A121C;
extern sStateObj153200* D_004A1238;
extern sStateObj153200* D_004A1248;
extern sStateObj153200* D_004A124C;
extern sStateObj153200* D_004A1264;

extern "C" void func_00153258(void) {
    D_004A120C->f8 = 1;
    D_004A1248->f8 = 1;
    D_004A11C8->f8 = 1;
    D_004A1238->f8 = 1;
    D_004A1214->f8 = 1;
    D_004A124C->f8 = 1;
    D_004A1264->f8 = 1;
    D_004A121C->f8 = 1;
}
#endif

