#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A0F0[];
extern void* D_0045AE58[16];
extern void* D_004A11B4;

struct cBENewRaceInterface {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

struct sRaceInterfaceGlobal {
    int arr1[6]; // 0x0
    int arr2[6]; // 0x18
    int field_0x30;
    int field_0x34;
    int field_0x38;
    int field_0x3C;
};
extern sRaceInterfaceGlobal D_00535BC8;

// padded past the 8-byte gp-relative threshold so the compiler emits
// absolute lui/lo addressing like the target, instead of assuming small data
struct sD_00535C08 { int value; int pad[2]; };
extern sD_00535C08 D_00535C08;

// padded past the 8-byte gp-relative threshold so the compiler emits
// absolute lui/lo addressing like the target, instead of assuming small data
struct sPad16 { char x; int pad[3]; };
extern sPad16 D_0043D984;

extern sPad16 D_0043D954;

// 0x64-byte array elements; arr[i].field indexing is what makes GCC emit the
// target's base-first addu (manual pointer arithmetic reverses the operands)
struct sRaceEntry {
    char pad_0x00[0x54];
    int field_0x54;
    int field_0x58;
    char pad_0x5c[4];
    int field_0x60;
};
extern sRaceEntry D_0043D950[];

extern sPad16 D_0043E254;

struct sRaceEntry18 {
    char pad_0x00[0x14];
    int field_0x14;
};
extern sRaceEntry18 D_0043E250[];

extern sPad16 D_0043E7D0;

//99.58%
INCLUDE_ASM("be/beintnewrace", cBENewRaceInterface_getThis__Fv);
#ifdef SKIP_ASM
void* cBENewRaceInterface_getThis()
{
    if (D_004A11B4 == 0) {
        cBENewRaceInterface* mem = (cBENewRaceInterface*)cMemMan_alloc(0x10, D_0045A0F0, 0, 0);
        mem->field_0x8 = 0;
        mem->vtable = D_0045AE58;
        D_004A11B4 = mem;
    }
    return D_004A11B4;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144928);
#ifdef SKIP_ASM
struct sRaceSettings_00144928
{
    int data[0x4C / 4];
};

extern sRaceSettings_00144928 D_005305B0;

extern "C" void func_00144928(void)
{
    D_005305B0 = *(sRaceSettings_00144928*)&D_00535BC8;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_001449E8);
#ifdef SKIP_ASM
extern sRaceSettings_00144928 D_005305B0;

extern "C" void func_001449E8(void)
{
    *(sRaceSettings_00144928*)&D_00535BC8 = D_005305B0;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", cBENewRaceInterface_setNumberHumans__FPvi);
#ifdef SKIP_ASM
void cBENewRaceInterface_setNumberHumans(void* self, int humans)
{
    D_00535BC8.field_0x34 = humans;
    D_00535BC8.field_0x30 = humans + D_00535BC8.field_0x3C + D_00535BC8.field_0x38;
    for (int i = 0; i < 6; i++) {
        D_00535BC8.arr1[i] = i;
        D_00535BC8.arr2[i] = i;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", cBENewRaceInterface_setNumberMission__FPvi);
#ifdef SKIP_ASM
void cBENewRaceInterface_setNumberMission(void* self, int mission)
{
    int a = D_00535BC8.field_0x34;
    int b = D_00535BC8.field_0x3C;
    D_00535BC8.field_0x38 = mission;
    D_00535BC8.field_0x30 = a + b + mission;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144B20);
#ifdef SKIP_ASM
extern "C" char* strcpy(char*, const char*);
extern char D_0043E6EC[];

extern "C" void func_00144B20(void* self, const char* name)
{
    char* base = (char*)&D_0043D984;
    char* g = (char*)&D_00535BC8;
    strcpy(base + *(int*)(g + 0x40) * 0x64, name);
    char* p1 = base + 0x10;
    strcpy(p1 + *(int*)(g + 0x40) * 0x64, name);
    char* p2 = base - 0x30;
    strcpy(p2 + *(int*)(g + 0x40) * 0x64, name);
    strcpy(D_0043E6EC, name);
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144BC0);
#ifdef SKIP_ASM
extern "C" void* func_00144BC0()
{
    return (char*)&D_0043D950[0] + D_00535C08.value * 0x64;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144BE0);
#ifdef SKIP_ASM
extern "C" int func_00144BE0()
{
    return D_00535C08.value;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144BF0);
#ifdef SKIP_ASM
extern "C" void* func_00144BF0()
{
    return (char*)&D_0043D954 + D_00535C08.value * 0x64;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144C48);
#ifdef SKIP_ASM
extern "C" void* func_00144C48(void* self, int a1)
{
    return (char*)&D_0043D984 + a1 * 0x64;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144C60);
#ifdef SKIP_ASM
extern "C" void* func_00144C60(void* self, int a1)
{
    return (char*)&D_0043D954 + a1 * 0x64;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144C78);
#ifdef SKIP_ASM
extern "C" int func_00144C78(void* self, int a1)
{
    return D_0043D950[a1].field_0x54;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144C98);
#ifdef SKIP_ASM
extern "C" int func_00144C98()
{
    return D_0043D950[D_00535C08.value].field_0x54;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144CC0);
#ifdef SKIP_ASM
extern "C" int func_00144CC0(void* self, int a1)
{
    return D_0043D950[a1].field_0x58;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144CE0);
#ifdef SKIP_ASM
struct sRaceEntryFull_00144CE0 {
    int field_0x0;
    char pad_0x04[0x58];
    int field_0x5C;
    int field_0x60;
};

extern "C" int func_00144CE0(void* self, int a1)
{
    sRaceEntryFull_00144CE0* t = (sRaceEntryFull_00144CE0*)D_0043D950;
    for (int i = 0; i < 23; i++) {
        if (t[i].field_0x5C == a1) {
            return t[i].field_0x0;
        }
    }
    return 22;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144D18);
#ifdef SKIP_ASM
extern "C" int func_00144D18(void* self, int a1)
{
    return D_0043D950[a1].field_0x60;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144D38);
#ifdef SKIP_ASM
extern "C" void* func_00144D38(void* self, int a1)
{
    return (char*)&D_0043E254 + a1 * 0x18;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144D50);
#ifdef SKIP_ASM
extern "C" int func_00144D50(void* self, int a1)
{
    return D_0043E250[a1].field_0x14;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00144D70__FPvii);
#ifdef SKIP_ASM
void* func_00144D70(void* self, int a1, int a2)
{
    *(int*)((char*)(void*)&D_00535BC8 + a1 * 4) = a2;
    *(int*)((char*)((char*)(void*)&D_00535BC8 + a2 * 4) + 0x18) = a1;
    return ((char*)(void*)&D_00535BC8 + a1 * 4);
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", cBENewRaceInterface_setNumberAI);
#ifdef SKIP_ASM
// Max AI riders per [gameType][eventKind] (7 event kinds per row).
extern unsigned int D_0043D8F8[][7];

extern "C" int cBENewRaceInterface_setNumberAI(void* self, int count)
{
    D_00535BC8.field_0x3C = count;
    D_00535BC8.field_0x30 = D_00535BC8.field_0x34 + count + D_00535BC8.field_0x38;
    signed char eventKind = *(signed char*)((char*)&D_00535BC8 + 0x48);
    signed char gameType = *(signed char*)((char*)&D_00535BC8 + 0x49);
    return (unsigned int)count <= D_0043D8F8[gameType][eventKind];
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", cBENewRaceInterface_setGameMode);
#ifdef SKIP_ASM
extern "C" int cBENewRaceInterface_setNumberAI(void* self, int count);
extern "C" int cBENewRaceInterface_setGameEvent(void* self, int event);
extern "C" void cBENewPlayerInterface_resetFromMissionMan(void* self, int a1);
extern "C" void func_00147828(int a0);
int cBENewPlayerInterface_isMissionMan(int a0);
void* cBENewPlayerInterface_getThis();

// Allowed game modes per game type (one byte per mode).
struct sModeRow_144DF0 {
    signed char allowed[0x43];
};
extern sModeRow_144DF0 D_0043E700[];

struct sVE_144DF0 {
    short delta;
    short index;
    void (*fn)(void*);
};

static inline char* Race_144DF0()
{
    return (char*)&D_00535BC8;
}

extern "C" int cBENewRaceInterface_setGameMode(void* self, int mode)
{
    sModeRow_144DF0 row = D_0043E700[*((signed char*)Race_144DF0() + 0x49)];
    int humans = 1;
    int ai = 5;
    if (*((signed char*)Race_144DF0() + 0x49) == 2) {
        humans = 2;
        ai = 4;
    }
    if (row.allowed[mode] != 1) {
        return 0;
    }
    if (mode == 4) {
        *((signed char*)Race_144DF0() + 0x48) = mode;
        cBENewRaceInterface_setNumberHumans(self, 1);
        cBENewRaceInterface_setNumberAI(self, 0);
        cBENewRaceInterface_setNumberMission(self, 1);
        char* p = (char*)cBENewPlayerInterface_getThis();
        func_00147828(1);
        sVE_144DF0* vt = *(sVE_144DF0**)(p + 0xC);
        vt[1].fn(p + vt[1].delta);
    } else if (*((signed char*)Race_144DF0() + 0x48) == 4) {
        cBENewRaceInterface_setNumberHumans(self, humans);
        cBENewRaceInterface_setNumberAI(self, 0);
        cBENewRaceInterface_setNumberMission(self, 0);
        char* p = (char*)cBENewPlayerInterface_getThis();
        if (cBENewPlayerInterface_isMissionMan(1) != 0) {
            cBENewPlayerInterface_resetFromMissionMan(p, 1);
            sVE_144DF0* vt = *(sVE_144DF0**)(p + 0xC);
            vt[1].fn(p + vt[1].delta);
        }
    }
    *((signed char*)Race_144DF0() + 0x48) = mode;
    if (mode == 3 || mode == 5 || mode == 6) {
        cBENewRaceInterface_setNumberHumans(self, humans);
        unsigned char ev = *((unsigned char*)Race_144DF0() + 0x4A);
        if (ev >= 4 && ev <= 5 && *((signed char*)Race_144DF0() + 0x49) != 2) {
            cBENewRaceInterface_setNumberAI(self, 1);
        } else {
            cBENewRaceInterface_setNumberAI(self, 0);
        }
        cBENewRaceInterface_setNumberMission(self, 0);
    }
    if (mode == 0) {
        cBENewRaceInterface_setNumberHumans(self, humans);
        cBENewRaceInterface_setNumberAI(self, ai);
        cBENewRaceInterface_setNumberMission(self, 0);
    }
    if (mode == 1) {
        cBENewRaceInterface_setNumberHumans(self, humans);
        cBENewRaceInterface_setNumberAI(self, 1);
        cBENewRaceInterface_setNumberMission(self, 0);
    }
    if (mode == 5) {
        cBENewRaceInterface_setGameEvent(self, 4);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145108);
#ifdef SKIP_ASM
extern "C" void func_00145108(void* self, int mode)
{
    sRaceInterfaceGlobal* g = &D_00535BC8;
    *((char*)g + 0x49) = mode;
    switch (mode)
    {
    case 0:
        cBENewRaceInterface_setNumberHumans(self, 1);
        cBENewRaceInterface_setNumberAI(self, 0);
        break;
    case 1:
        cBENewRaceInterface_setNumberHumans(self, 1);
        if (g->field_0x3C < 0)
            cBENewRaceInterface_setNumberAI(self, 0);
        if (g->field_0x3C >= 6)
            cBENewRaceInterface_setNumberAI(self, 5);
        break;
    case 2:
        cBENewRaceInterface_setNumberHumans(self, 2);
        cBENewRaceInterface_setNumberAI(self, 0);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", cBENewRaceInterface_setGameEvent);
#ifdef SKIP_ASM
extern "C" int cBENewRaceInterface_setNumberAI(void* self, int count);

struct sGameEvent_001451E8
{
    int kind;
    char rest[0x50];
};
extern sGameEvent_001451E8 D_0043E978[];

static inline char* Race_1451E8()
{
    return (char*)&D_00535BC8;
}

extern "C" int cBENewRaceInterface_setGameEvent(void* self, int event)
{
    sGameEvent_001451E8 e = D_0043E978[event];
    *((signed char*)Race_1451E8() + 0x4A) = event;
    if (event < 6)
    {
        if (event >= 4)
        {
            if (*((signed char*)Race_1451E8() + 0x49) == 2)
                cBENewRaceInterface_setNumberAI(self, 0);
            else
                cBENewRaceInterface_setNumberAI(self, 1);
        }
    }
    return e.kind == *((signed char*)Race_1451E8() + 0x48);
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145340);
#ifdef SKIP_ASM
extern signed char D_00535C12[];
extern sPad16 D_0043E97C;

extern "C" void* func_00145340()
{
    return (char*)&D_0043E97C + D_00535C12[0] * 0x54;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145378);
#ifdef SKIP_ASM
extern signed char D_00535C11[];
extern char D_0043E707[]; // 0x43-byte records at an odd address

extern "C" void* func_00145378()
{
    return D_0043E707 + D_00535C11[0] * 0x43;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145398);
#ifdef SKIP_ASM
extern signed char D_00535C10[];

extern "C" void* func_00145398()
{
    return (char*)&D_0043E7D0 + D_00535C10[0] * 0x3c;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_001453B8);
#ifdef SKIP_ASM
extern "C" void* func_001453B8(void* self, int a1)
{
    return (char*)&D_0043E7D0 + a1 * 0x3c;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_001453D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" unsigned int func_00237CD8(void);

struct sPrizeRow_1453D0
{
    short key;
    short kind;
    short prize[6];
};
// Typed view of D_00440B38 (declared later in this unit with another layout).
extern sPrizeRow_1453D0 D_00440B38_1453D0[] __asm__("D_00440B38");

extern "C" int func_001453D0(void* self, int kind, int place, int mode)
{
    int k = 1;
    if (kind) k = kind;
    float m = 1.0f;
    if (mode == 0 && place != 0)
        m = 0.8999999761581421f;
    else if (mode == 2 && place != 0)
        m = 1.2000000476837158f;
    int key = D_00535C08.value;
    for (int i = 0; i < 30; i++)
    {
        if (D_00440B38_1453D0[i].key == key && D_00440B38_1453D0[i].kind == k)
        {
            int base = (int)(D_00440B38_1453D0[i].prize[place] * 100 * m);
            int r = func_00237CD8() % 200;
            base += (int)(base * (r - 100) * 0.0005000000237487257f);
            return base - base % 20;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_001454F8);
#ifdef SKIP_ASM
extern "C" int func_00145600(void* self, int a1, int a2);
extern int D_004A11BC;

struct sRaceLookup_00440B38
{
    short key;
    short kind;
    char pad_0x04[0xA];
    short value;
};
extern sRaceLookup_00440B38 D_00440B38[];

extern "C" int func_001454F8(void* self, int kind)
{
    char* g = (char*)&D_00535BC8;
    unsigned char mode = *(unsigned char*)(g + 0x4A);
    if (mode >= 6 && mode < 12)
    {
        return func_00145600(self, (signed char)mode, kind);
    }
    if (kind == 0)
    {
        kind = 1;
    }
    int key = *(int*)(g + 0x40);
    for (int i = 0; i < 30; i++)
    {
        if (D_00440B38[i].key == key && D_00440B38[i].kind == kind)
        {
            return D_00440B38[i].value;
        }
    }
    for (int i = 0; i < 30; i++)
    {
        if (D_00440B38[i].key == D_004A11BC && D_00440B38[i].kind == kind)
        {
            return D_00440B38[i].value;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_001455D0);
#ifdef SKIP_ASM
struct sRaceTableEntry_00440D18
{
    char pad_0x00[4];
    unsigned short field_0x4;
    unsigned short field_0x6;
    unsigned short field_0x8[5];
    unsigned short field_0x12;
};

extern sRaceTableEntry_00440D18 D_00440D18[];

extern "C" int func_001455D0(void* self, int a1, int a2)
{
    return D_00440D18[a2 + (a1 - 6) * 3].field_0x4;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145600);
#ifdef SKIP_ASM
extern sRaceTableEntry_00440D18 D_00440D18[];

extern "C" int func_00145600(void* self, int a1, int a2)
{
    return D_00440D18[a2 + (a1 - 6) * 3].field_0x6;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145630);
#ifdef SKIP_ASM
extern sRaceTableEntry_00440D18 D_00440D18[];

extern "C" int func_00145630(void* self, int a1, int a2)
{
    return D_00440D18[a2 + (a1 - 6) * 3].field_0x12 * 100;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145668);
#ifdef SKIP_ASM
extern sRaceTableEntry_00440D18 D_00440D18[];

extern "C" int func_00145668(void* self, int a1, int a2, int a3)
{
    return D_00440D18[a2 + (a1 - 6) * 3].field_0x8[a3];
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_001456A0);
#ifdef SKIP_ASM
struct sRacePair_001456A0
{
    short a;
    short b;
};

extern sRacePair_001456A0 D_00440E80[];

extern "C" int func_001456A0(void* self, int idx, int mode)
{
    if (mode == 9 || mode == 10 || mode == 11 || mode == 6 || mode == 7 || mode == 8)
        return -1;
    if (idx < 14)
    {
        if (mode == 0)
            return D_00440E80[(short)idx].b;
        return D_00440E80[(short)idx].b * 100;
    }
    if (mode == 4)
        return D_00440E80[(short)idx].b;
    if (mode == 5)
        return D_00440E80[(short)idx + 3].b * 100;
    return -1;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145750);
#ifdef SKIP_ASM
void* cBENewPlayerInterface_getThis();
signed char cBENewPlayerInterface_getRiderCharID(void* self, int riderIndex);
extern "C" int func_00146E98(void* self, int a1);

extern "C" int func_00145750(void* self)
{
    void* players = cBENewPlayerInterface_getThis();
    int c = cBENewPlayerInterface_getRiderCharID(players, func_00146E98(cBENewPlayerInterface_getThis(), 0));
    switch (func_00144C78(self, D_00535C08.value))
    {
    case 0:
        return c == 3 ? 5 : 3;
    case 1:
        return c == 7 ? 4 : 7;
    case 2:
        return c == 8 ? 6 : 8;
    }
    return 3;
}
#endif

//100%
INCLUDE_ASM("be/beintnewrace", func_00145870);
#ifdef SKIP_ASM
extern "C" int func_00145870(void* self, int idx)
{
    switch (idx)
    {
    case 14:
    case 15:
    case 16:
        return 12;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return 0;
    case 5:
    case 6:
    case 7:
        return 1;
    case 8:
    case 9:
    case 10:
        return 3;
    case 11:
    case 12:
    case 13:
        return 2;
    }
    return 12;
}
#endif

