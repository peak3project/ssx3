#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sStateSingleton {
    void* field_0x0;
    void* vtable;
};

extern const char D_0045A8A8[];
extern void* D_0045ABB8[16];
extern void* D_004A1254;

//100%
INCLUDE_ASM("be/beprepoststate", cBEPostRaceState_getState__FPv);
#ifdef SKIP_ASM
void* cBEPostRaceState_getState(void* self)
{
    if (D_004A1254 == 0) {
        sStateSingleton* mem = (sStateSingleton*)cMemMan_alloc(8, D_0045A8A8, 0, 0);
        mem->field_0x0 = self;
        mem->vtable = D_0045ABB8;
        D_004A1254 = mem;
    }
    return D_004A1254;
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_00156390);
#ifdef SKIP_ASM
void* cBENewRaceInterface_getThis();
void* cBENewPlayerInterface_getThis();
extern "C" void* func_0014EDD8();
extern "C" void* func_00147F78();
void* cBEOptionInterface_getThis();
void* cBESaveInterface_getThis();
void* cBENetworkInterface_getThis();
void* cBEScoreInterface_getThis();
extern "C" void* func_0014ABE0();
void* cBEBAGTInterface_getThis();
void* cBEEconInterface_getThis();
void* cBEMissionInterface_getThis();
void* cBEAggressionInterface_getThis();
void* cBERewardInterface_getThis();
// Returns the backend interface singleton for the given kind.
extern "C" void* func_00156390(void* self, int kind)
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
    case 5:
        return cBESaveInterface_getThis();
    case 7:
        return cBENetworkInterface_getThis();
    case 8:
        return cBEScoreInterface_getThis();
    case 9:
        return func_0014ABE0();
    case 6:
        return cBEBAGTInterface_getThis();
    case 11:
        return cBEEconInterface_getThis();
    case 10:
        return cBEMissionInterface_getThis();
    case 12:
        return cBEAggressionInterface_getThis();
    case 13:
        return cBERewardInterface_getThis();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_001564B0);
#ifdef SKIP_ASM
extern void* D_004A11C0;
extern void* D_004A1208;
extern void* D_004A11C4;
extern void* D_004A120C;
extern void* D_004A121C;
extern void* D_004A1204;
extern void* D_004A11C8;
extern void* D_004A1210;
extern void* D_004A1214;
extern void* D_004A124C;
extern void* D_004A1264;

struct sBEIface_001564B0
{
    char pad_0x00[8];
    int active;
};

extern "C" void func_001564B0(void)
{
    ((sBEIface_001564B0*)D_004A11C0)->active = 0;
    ((sBEIface_001564B0*)D_004A1208)->active = 0;
    ((sBEIface_001564B0*)D_004A11C4)->active = 0;
    ((sBEIface_001564B0*)D_004A120C)->active = 0;
    ((sBEIface_001564B0*)D_004A121C)->active = 0;
    ((sBEIface_001564B0*)D_004A1204)->active = 0;
    ((sBEIface_001564B0*)D_004A11C8)->active = 0;
    ((sBEIface_001564B0*)D_004A1210)->active = 0;
    ((sBEIface_001564B0*)D_004A1214)->active = 0;
    ((sBEIface_001564B0*)D_004A124C)->active = 0;
    ((sBEIface_001564B0*)D_004A1264)->active = 0;
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_00156510);
#ifdef SKIP_ASM
extern void* D_004A11C0;
extern void* D_004A1208;
extern void* D_004A11C4;
extern void* D_004A120C;
extern void* D_004A121C;
extern void* D_004A1204;
extern void* D_004A11C8;
extern void* D_004A1210;
extern void* D_004A1214;
extern void* D_004A124C;
extern void* D_004A1264;

struct sBEIface_00156510
{
    char pad_0x00[8];
    int active;
};

extern "C" void func_00156510(void)
{
    ((sBEIface_00156510*)D_004A11C0)->active = 1;
    ((sBEIface_00156510*)D_004A1208)->active = 1;
    ((sBEIface_00156510*)D_004A11C4)->active = 1;
    ((sBEIface_00156510*)D_004A120C)->active = 1;
    ((sBEIface_00156510*)D_004A121C)->active = 1;
    ((sBEIface_00156510*)D_004A1204)->active = 1;
    ((sBEIface_00156510*)D_004A11C8)->active = 1;
    ((sBEIface_00156510*)D_004A1210)->active = 1;
    ((sBEIface_00156510*)D_004A1214)->active = 1;
    ((sBEIface_00156510*)D_004A124C)->active = 1;
    ((sBEIface_00156510*)D_004A1264)->active = 1;
}
#endif

extern void* D_0045AC18[16];
extern void* D_004A1258;

//100%
INCLUDE_ASM("be/beprepoststate", cBEPreRaceState_getState__FPv);
#ifdef SKIP_ASM
void* cBEPreRaceState_getState(void* self)
{
    if (D_004A1258 == 0) {
        sStateSingleton* mem = (sStateSingleton*)cMemMan_alloc(8, D_0045A8A8, 0, 0);
        mem->field_0x0 = self;
        mem->vtable = D_0045AC18;
        D_004A1258 = mem;
    }
    return D_004A1258;
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_001565C8);
#ifdef SKIP_ASM
void* cBENewRaceInterface_getThis();
void* cBENewPlayerInterface_getThis();
extern "C" void* func_0014EDD8();
extern "C" void* func_00147F78();
void* cBEOptionInterface_getThis();
void* cBESaveInterface_getThis();
void* cBENetworkInterface_getThis();
void* cBEScoreInterface_getThis();
extern "C" void* func_0014ABE0();
void* cBEBAGTInterface_getThis();
void* cBEEconInterface_getThis();
void* cBEMissionInterface_getThis();
void* cBEAggressionInterface_getThis();
void* cBERewardInterface_getThis();
// Returns the backend interface singleton for the given kind.
extern "C" void* func_001565C8(void* self, int kind)
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
    case 5:
        return cBESaveInterface_getThis();
    case 7:
        return cBENetworkInterface_getThis();
    case 8:
        return cBEScoreInterface_getThis();
    case 9:
        return func_0014ABE0();
    case 6:
        return cBEBAGTInterface_getThis();
    case 11:
        return cBEEconInterface_getThis();
    case 10:
        return cBEMissionInterface_getThis();
    case 12:
        return cBEAggressionInterface_getThis();
    case 13:
        return cBERewardInterface_getThis();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_001566E8);
#ifdef SKIP_ASM
extern void* D_004A11B4;
extern void* D_004A11C0;
extern void* D_004A1208;
extern void* D_004A11C4;
extern void* D_004A120C;
extern void* D_004A121C;
extern void* D_004A1204;
extern void* D_004A11C8;
extern void* D_004A1210;
extern void* D_004A1214;
extern void* D_004A124C;
extern void* D_004A1264;

struct sBEIface_001566E8
{
    char pad_0x00[8];
    int active;
};

extern "C" void func_001566E8(void)
{
    ((sBEIface_001566E8*)D_004A11B4)->active = 0;
    ((sBEIface_001566E8*)D_004A11C0)->active = 0;
    ((sBEIface_001566E8*)D_004A1208)->active = 0;
    ((sBEIface_001566E8*)D_004A11C4)->active = 0;
    ((sBEIface_001566E8*)D_004A120C)->active = 0;
    ((sBEIface_001566E8*)D_004A121C)->active = 0;
    ((sBEIface_001566E8*)D_004A1204)->active = 0;
    ((sBEIface_001566E8*)D_004A11C8)->active = 0;
    ((sBEIface_001566E8*)D_004A1210)->active = 0;
    ((sBEIface_001566E8*)D_004A1214)->active = 0;
    ((sBEIface_001566E8*)D_004A124C)->active = 0;
    ((sBEIface_001566E8*)D_004A1264)->active = 0;
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_00156750);
#ifdef SKIP_ASM
extern void* D_004A11B4;
extern void* D_004A11C0;
extern void* D_004A1208;
extern void* D_004A11C4;
extern void* D_004A120C;
extern void* D_004A121C;
extern void* D_004A1204;
extern void* D_004A11C8;
extern void* D_004A1210;
extern void* D_004A1214;
extern void* D_004A124C;
extern void* D_004A1264;

struct sBEIface_00156750
{
    char pad_0x00[8];
    int active;
};

extern "C" void func_00156750(void)
{
    ((sBEIface_00156750*)D_004A11B4)->active = 1;
    ((sBEIface_00156750*)D_004A11C0)->active = 1;
    ((sBEIface_00156750*)D_004A1208)->active = 1;
    ((sBEIface_00156750*)D_004A11C4)->active = 1;
    ((sBEIface_00156750*)D_004A120C)->active = 1;
    ((sBEIface_00156750*)D_004A121C)->active = 1;
    ((sBEIface_00156750*)D_004A1204)->active = 1;
    ((sBEIface_00156750*)D_004A11C8)->active = 1;
    ((sBEIface_00156750*)D_004A1210)->active = 1;
    ((sBEIface_00156750*)D_004A1214)->active = 1;
    ((sBEIface_00156750*)D_004A124C)->active = 1;
    ((sBEIface_00156750*)D_004A1264)->active = 1;
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_001567B8);
#ifdef SKIP_ASM
extern "C" void func_00151600(void* p, int i, int arg);

extern "C" void func_001567B8(void* self, int arg)
{
    int i;
    for (i = 0; i < 10; i++) {
        func_00151600((char*)self + i * 0xF88, i, arg);
    }
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_00156810);
#ifdef SKIP_ASM
extern "C" void func_001519E0(void* p, int i);

extern "C" void func_00156810(void* self)
{
    int i;
    for (i = 0; i < 10; i++) {
        func_001519E0((char*)self + i * 0xF88, i);
    }
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_00156858);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int n);
extern int D_004A11E8;

struct sEnt_156858
{
    short id;
    unsigned short flags;
};

struct sProfile_156858
{
    char pad[0x288];
    short* index;       // 0x288
};

extern "C" void func_00156858(char* dst, char* src)
{
    int i;
    for (i = 0; i < 10; i++) {
        char* d = dst + i * 0xF88;
        short* index = ((sProfile_156858*)d)->index;
        func_003E6574(d, src + i * 0xF88, 0xF88);
        ((sProfile_156858*)d)->index = index;
        int j;
        for (j = 0; j < D_004A11E8; j++)
            index[j] = -1;
        sEnt_156858* e = (sEnt_156858*)(dst + i * 0xF88 + 0x290);
        int n;
        for (n = 0; n < 0x20D; n++, e++) {
            short k = e->id;
            if (k >= 0)
                index[k] = n;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_00156950);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int n);
extern signed char D_004A125C;
extern char D_004C4090[];

extern "C" void func_00156950(char* base, int idx)
{
    D_004A125C = idx;
    func_003E6574(D_004C4090, base + idx * 0xF88, 0xF88);
}
#endif

//100%
INCLUDE_ASM("be/beprepoststate", func_00156988);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int n);
extern signed char D_004A125C;
extern char D_004C4090[];

extern "C" void func_00156988(char* base)
{
    func_003E6574(base + D_004A125C * 0xF88, D_004C4090, 0xF88);
}
#endif

