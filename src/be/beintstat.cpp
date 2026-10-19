#include "common.h"

//100%
INCLUDE_ASM("be/beintstat", cBEStatInterface_getCollisionAttrib);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_getCollisionAttrib
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_getCollisionAttrib
{
    signed char v[15];
};
extern sPlayerStatRow_getCollisionAttrib D_00535538_getCollisionAttrib[] __asm__("D_00535538");
extern sCharStat_getCollisionAttrib D_005308D8_getCollisionAttrib[] __asm__("D_005308D8");

extern "C" float cBEStatInterface_getCollisionAttrib(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_getCollisionAttrib[profile].e[c][5] / 5;
    return (float)v / (float)D_005308D8_getCollisionAttrib[c].v[0xD];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149038);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_func_00149038
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_func_00149038
{
    signed char v[15];
};
extern sPlayerStatRow_func_00149038 D_00535538_func_00149038[] __asm__("D_00535538");
extern sCharStat_func_00149038 D_005308D8_func_00149038[] __asm__("D_005308D8");

extern "C" float func_00149038(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_00149038[profile].e[c][5] / 5;
    return (float)v / (float)D_005308D8_func_00149038[c].v[0xD];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_func_00149120
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_func_00149120
{
    signed char v[15];
};
extern sPlayerStatRow_func_00149120 D_00535538_func_00149120[] __asm__("D_00535538");
extern sCharStat_func_00149120 D_005308D8_func_00149120[] __asm__("D_005308D8");

extern "C" float func_00149120(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_00149120[profile].e[c][6] / 5;
    return (float)v / (float)D_005308D8_func_00149120[c].v[0xE];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149208);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_func_00149208
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_func_00149208
{
    signed char v[15];
};
extern sPlayerStatRow_func_00149208 D_00535538_func_00149208[] __asm__("D_00535538");
extern sCharStat_func_00149208 D_005308D8_func_00149208[] __asm__("D_005308D8");

extern "C" float func_00149208(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_00149208[profile].e[c][6] / 5;
    return (float)v / (float)D_005308D8_func_00149208[c].v[0xE];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001492F0);
#ifdef SKIP_ASM
extern "C" float func_001492F0(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_00149038[profile].e[c][6] / 5;
    return (float)v / (float)D_005308D8_func_00149038[c].v[0xE];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001493D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_func_001493D8
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_func_001493D8
{
    signed char v[15];
};
extern sPlayerStatRow_func_001493D8 D_00535538_func_001493D8[] __asm__("D_00535538");
extern sCharStat_func_001493D8 D_005308D8_func_001493D8[] __asm__("D_005308D8");

extern "C" float func_001493D8(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_001493D8[profile].e[c][1] / 5;
    return (float)v / (float)D_005308D8_func_001493D8[c].v[0x9];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001494C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_func_001494C0
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_func_001494C0
{
    signed char v[15];
};
extern sPlayerStatRow_func_001494C0 D_00535538_func_001494C0[] __asm__("D_00535538");
extern sCharStat_func_001494C0 D_005308D8_func_001494C0[] __asm__("D_005308D8");

extern "C" float func_001494C0(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_001494C0[profile].e[c][0] / 5;
    return (float)v / (float)D_005308D8_func_001494C0[c].v[0x8];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001495A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_func_001495A8
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_func_001495A8
{
    signed char v[15];
};
extern sPlayerStatRow_func_001495A8 D_00535538_func_001495A8[] __asm__("D_00535538");
extern sCharStat_func_001495A8 D_005308D8_func_001495A8[] __asm__("D_005308D8");

extern "C" float func_001495A8(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_001495A8[profile].e[c][4] / 5;
    return (float)v / (float)D_005308D8_func_001495A8[c].v[0xC];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149690);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

struct sPlayerStatRow_func_00149690
{
    signed char e[10][7]; // 0x46 bytes
};
struct sCharStat_func_00149690
{
    signed char v[15];
};
extern sPlayerStatRow_func_00149690 D_00535538_func_00149690[] __asm__("D_00535538");
extern sCharStat_func_00149690 D_005308D8_func_00149690[] __asm__("D_005308D8");

extern "C" float func_00149690(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538_func_00149690[profile].e[c][2] / 5;
    return (float)v / (float)D_005308D8_func_00149690[c].v[0xA];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149778);
#ifdef SKIP_ASM
int cBENewPlayerInterface_isMissionMan(int index);
extern "C" int func_00148950(void* iface, int id);

// Local threshold table; the original was likely an `int t[11] = {...};` whose
// compiler-generated initializer splat names D_0045A2B0.
struct sLevelTable_00149778
{
    int v[11];
};
extern const sLevelTable_00149778 D_0045A2B0;

extern "C" int func_00149778(void* self, int rider, int value)
{
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0;
    sLevelTable_00149778 t = D_0045A2B0;
    int n = func_00148950(self, rider) - 1;
    int lvl;
    int hi = 10;
    if (n >= 0)
    {
        lvl = n;
        if (lvl > hi)
            lvl = hi;
    }
    else
        lvl = 0;
    return value >= t.v[lvl];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149860);
#ifdef SKIP_ASM
extern "C" void func_00149BB8();
extern "C" void* func_0014EDD8();
extern "C" void* func_00147F78(void);
extern "C" void* func_0014ABE0();
void* cBENewRaceInterface_getThis();
void* cBENewPlayerInterface_getThis();
void* cBEOptionInterface_getThis();
void* cBESaveInterface_getThis();
void* cBEBAGTInterface_getThis();
void* cBENetworkInterface_getThis();
void* cBEScoreInterface_getThis();
void* cBEMissionInterface_getThis();
void* cBEEconInterface_getThis();
void* cBEAggressionInterface_getThis();
void* cBERewardInterface_getThis();

struct sStatDefaults_149860
{
    int v[0xA28 / 4];
};
extern sStatDefaults_149860 D_00535C18;
extern sStatDefaults_149860 D_0043FB28;

extern "C" void* func_00149860(void* self)
{
    func_00149BB8();
    D_00535C18 = D_0043FB28;
    cBENewRaceInterface_getThis();
    cBENewPlayerInterface_getThis();
    func_0014EDD8();
    func_00147F78();
    cBEOptionInterface_getThis();
    cBESaveInterface_getThis();
    cBEBAGTInterface_getThis();
    cBENetworkInterface_getThis();
    cBEScoreInterface_getThis();
    func_0014ABE0();
    cBEMissionInterface_getThis();
    cBEEconInterface_getThis();
    cBEAggressionInterface_getThis();
    cBERewardInterface_getThis();
    return self;
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001499A8);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void func_00153050(void);
extern int* D_004A11B4;
extern int* D_004A11C0;
extern int* D_004A11C4;
extern int* D_004A11C8;
extern int* D_004A1204;
extern int* D_004A1208;
extern int* D_004A120C;
extern int* D_004A1210;
extern int* D_004A1214;
extern int* D_004A1238;
extern int* D_004A1248;
extern int* D_004A124C;
extern int* D_004A1264;

extern "C" void func_001499A8(void* self, int flags)
{
    operator_delete(D_004A11B4);
    D_004A11B4 = 0;
    operator_delete(D_004A11C0);
    D_004A11C0 = 0;
    operator_delete(D_004A1208);
    D_004A1208 = 0;
    operator_delete(D_004A11C4);
    D_004A11C4 = 0;
    operator_delete(D_004A120C);
    D_004A120C = 0;
    func_00153050();
    operator_delete(D_004A1210);
    D_004A1210 = 0;
    operator_delete(D_004A1204);
    D_004A1204 = 0;
    operator_delete(D_004A1248);
    D_004A1248 = 0;
    operator_delete(D_004A11C8);
    D_004A11C8 = 0;
    operator_delete(D_004A1238);
    D_004A1238 = 0;
    operator_delete(D_004A1214);
    D_004A1214 = 0;
    operator_delete(D_004A124C);
    D_004A124C = 0;
    operator_delete(D_004A1264);
    D_004A1264 = 0;
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149A88);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_002C2580(char* buf, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_001567B8(void* p, int v);
extern "C" void* func_00147F78(void);
int GetHashValue32(char*);
void* cBENewPlayerInterface_getThis();
void* cBEBAGTInterface_getThis();
extern char* D_004A28A8;
extern char D_0045A268[];
extern char D_00535B20[];
extern char D_004A6CA8[];

struct sVEntry_149A88
{
    short delta;
    short index;
    int (*fn)(void*, ...);
};

struct sRiderEntry_149A88
{
    char name[0x10];
    unsigned f0 : 1;
    unsigned f1 : 1;
    unsigned pad : 6;
    unsigned char c11;
};

static inline void vreset_149A88(char* o)
{
    sVEntry_149A88* vt = *(sVEntry_149A88**)(o + 0xC);
    vt[2].fn(o + vt[2].delta);
}

extern "C" void func_00149A88(void* self, signed char idx)
{
    char buf[64];
    sRiderEntry_149A88* e = (sRiderEntry_149A88*)(D_00535B20 + idx * 0x1C);
    func_00416210(e, 0, 0x1C);
    e->f1 = 1;
    e->c11 = 4;
    char* o = *(char**)(D_004A28A8 + 0x8C);
    sVEntry_149A88* vt = *(sVEntry_149A88**)(o + 4);
    func_002C2580(buf, vt[4].fn(o + vt[4].delta, GetHashValue32(D_0045A268)));
    sprintf((char*)e, buf, idx + 1);
    func_001567B8(D_004A6CA8 + idx * 0x9B50, 1);
    vreset_149A88((char*)cBENewPlayerInterface_getThis());
    vreset_149A88((char*)func_00147F78());
    vreset_149A88((char*)cBEBAGTInterface_getThis());
}
#endif

INCLUDE_ASM("be/beintstat", func_00149BB8);


//100%
INCLUDE_ASM("be/beintstat", func_0014A078);
#ifdef SKIP_ASM
extern "C" void func_0014A078(void) {

}
#endif
