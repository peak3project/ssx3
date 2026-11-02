#include "common.h"

int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
int cBENewPlayerInterface_isMissionMan(int index);

// Per-profile character stat levels: one row of 10 characters x 7 stats per profile.
struct sPlayerStat7 {
    signed char v[7];
};
struct sPlayerStatRow {
    sPlayerStat7 e[10]; // 0x46 bytes
};
extern sPlayerStatRow D_00535538[];

// Per-character base stats (15 bytes each).
struct sCharStat {
    signed char v[15];
};
extern sCharStat D_005308D8[];

// One player slot (0x1C bytes), as in be/beintplayer; D_00535B20 is the saved table.
struct sPlayerCharEntry {
    char name[0xC];                 // 0x00
    int ctrlID;                     // 0x0C (-1 = none)
    unsigned int flag0 : 1;         // 0x10 bit 0
    unsigned int flag1 : 1;         // 0x10 bit 1
    unsigned int missionMan : 1;    // 0x10 bit 2
    unsigned int flag3 : 1;         // 0x10 bit 3
    signed char mCharID;            // 0x11
    signed char field_0x12;         // 0x12
    signed char field_0x13;         // 0x13
    int field_0x14;                 // 0x14
    int field_0x18;                 // 0x18
};
extern sPlayerCharEntry D_00535B20[];

// Race settings, as in be/beintplayer: two rider -> player slot maps, the event and the mode.
struct sRaceSettings {
    int playerID[6];            // 0x00
    int playerID2[6];           // 0x18
    char pad_0x30[0x40 - 0x30];
    int event;                  // 0x40
    char pad_0x44[4];
    signed char mode;           // 0x48
    char pad_0x49[0x4C - 0x49];
};
extern sRaceSettings D_005305B0;

//100%
INCLUDE_ASM("be/beintstat", cBEStatInterface_getCollisionAttrib);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[5] / 5;
    return (float)v / (float)D_005308D8[c].v[0xD];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149038);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[5] / 5;
    return (float)v / (float)D_005308D8[c].v[0xD];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149120);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[6] / 5;
    return (float)v / (float)D_005308D8[c].v[0xE];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149208);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[6] / 5;
    return (float)v / (float)D_005308D8[c].v[0xE];
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
        v = D_00535538[profile].e[c].v[6] / 5;
    return (float)v / (float)D_005308D8[c].v[0xE];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001493D8);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[1] / 5;
    return (float)v / (float)D_005308D8[c].v[0x9];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001494C0);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[0] / 5;
    return (float)v / (float)D_005308D8[c].v[0x8];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_001495A8);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[4] / 5;
    return (float)v / (float)D_005308D8[c].v[0xC];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149690);
#ifdef SKIP_ASM
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
        v = D_00535538[profile].e[c].v[2] / 5;
    return (float)v / (float)D_005308D8[c].v[0xA];
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149778);
#ifdef SKIP_ASM
extern "C" int func_00148950(void* iface, int id);

// Local threshold table; the original was likely an `int t[11] = {...};` whose
// compiler-generated initializer splat names D_0045A2B0.
struct sLevelTable_00149778
{
    int v[11];
};
extern const sLevelTable_00149778 D_0045A2B0;

static inline int clampLevel_149778(int v, int lo, int hi)
{
    int r;
    if (v >= lo)
    {
        r = v;
        if (r > hi)
            r = hi;
    }
    else
        r = lo;
    return r;
}

extern "C" int func_00149778(void* self, int rider, int value)
{
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0;
    sLevelTable_00149778 t = D_0045A2B0;
    int n = func_00148950(self, rider) - 1;
    int lvl = clampLevel_149778(n, 0, 10);
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
extern char D_004A6CA8[];

struct sVEntry_149A88
{
    short delta;
    short index;
    int (*fn)(void*, ...);
};

static inline void vreset_149A88(char* o)
{
    sVEntry_149A88* vt = *(sVEntry_149A88**)(o + 0xC);
    vt[2].fn(o + vt[2].delta);
}

extern "C" void func_00149A88(void* self, signed char idx)
{
    char buf[64];
    sPlayerCharEntry* e = &D_00535B20[idx];
    func_00416210(e, 0, 0x1C);
    e->flag1 = 1;
    e->mCharID = 4;
    char* o = *(char**)(D_004A28A8 + 0x8C);
    sVEntry_149A88* vt = *(sVEntry_149A88**)(o + 4);
    func_002C2580(buf, vt[4].fn(o + vt[4].delta, GetHashValue32(D_0045A268)));
    sprintf(e->name, buf, idx + 1);
    func_001567B8(D_004A6CA8 + idx * 0x9B50, 1);
    vreset_149A88((char*)cBENewPlayerInterface_getThis());
    vreset_149A88((char*)func_00147F78());
    vreset_149A88((char*)cBEBAGTInterface_getThis());
}
#endif

//100%
INCLUDE_ASM("be/beintstat", func_00149BB8);
#ifdef SKIP_ASM
struct sCharBase {
    unsigned char v[7];
};
extern sCharBase D_00440F00[];

struct sRange_9BB8 {
    int lo;
    int hi;
};

struct sStatRanges_9BB8 {
    int f0;
    int f4;
    int pad8[4];
    sRange_9BB8 a[16];          // 0x18
    sRange_9BB8 b[16];          // 0x98
    sRange_9BB8 c[6][3][2];     // 0x118
    sRange_9BB8 d[10];          // 0x238
    int e[8];                   // 0x288
};

extern sStatRanges_9BB8 D_00530600_9BB8 __asm__("D_00530600");

static inline void setRange_9BB8(sRange_9BB8* r, int lo, int hi)
{
    r->lo = lo;
    r->hi = hi;
}
extern "C" void* func_0041605C(void* dst, const void* src, int n);
extern "C" void* func_0014C6A0(void*);
extern "C" void cBERewardDB_init(void* db, int flag);
extern "C" void* FILE_load(const char* name, int flags);
void cMemMan_free(void*);
extern char D_004A6750[];
extern char D_004C3E98[];
extern char D_0045A2E0[];
extern char D_00530970[];
extern char D_00535898[];

extern "C" void func_00149BB8(void)
{
    int i;
    void* f;
    func_0014C6A0(D_004A6750);
    cBERewardDB_init(D_004C3E98, 0);
    func_00416210(&D_005305B0, 0, 0x4C);
    for (i = 0; i < 6; i++) {
        D_005305B0.playerID[i] = i;
        D_005305B0.playerID2[i] = i;
    }
    func_00416210(D_00535B20, 0, 0xA8);
    for (i = 0; i < 6; i++) {
        sPlayerCharEntry* e = &D_00535B20[i];
        e->name[0] = 0;
        e->flag1 = 1;
        e->mCharID = 4;
    }
    f = FILE_load(D_0045A2E0, 0x100);
    func_0041605C(D_00530970, f, 0x550);
    if (f != 0)
        cMemMan_free(f);
    for (i = 0; i < 10; i++) {
        D_005308D8[i].v[0] = i;
        D_005308D8[i].v[1] = D_00440F00[i].v[0] + 5;
        D_005308D8[i].v[2] = D_00440F00[i].v[1] + 5;
        D_005308D8[i].v[3] = D_00440F00[i].v[2] + 5;
        D_005308D8[i].v[4] = D_00440F00[i].v[3] + 5;
        D_005308D8[i].v[5] = D_00440F00[i].v[4] + 5;
        D_005308D8[i].v[6] = D_00440F00[i].v[5] + 5;
        D_005308D8[i].v[7] = D_00440F00[i].v[6] + 5;
        // the default stats are written in this (non-index) order; the retail store order follows it
        D_005308D8[i].v[9] = 0xB;
        D_005308D8[i].v[11] = 0xB;
        D_005308D8[i].v[8] = 0xB;
        D_005308D8[i].v[12] = 0xB;
        D_005308D8[i].v[14] = 0xB;
        D_005308D8[i].v[13] = 0xB;
        D_005308D8[i].v[10] = 0xB;
    }
    func_00416210(D_00535898, 0, 0x288);
    for (i = 0; i < 3; i++)
        func_001567B8(D_004A6CA8 + i * 0x9B50, 1);
    D_00530600_9BB8.f0 = 0;
    D_00530600_9BB8.f4 = 0;
    setRange_9BB8(&D_00530600_9BB8.a[0], 200, 400);
    setRange_9BB8(&D_00530600_9BB8.a[1], 200, 400);
    setRange_9BB8(&D_00530600_9BB8.a[2], 200, 400);
    setRange_9BB8(&D_00530600_9BB8.a[3], 200, 400);
    setRange_9BB8(&D_00530600_9BB8.a[4], 250, 400);
    setRange_9BB8(&D_00530600_9BB8.a[5], 250, 400);
    setRange_9BB8(&D_00530600_9BB8.a[6], 250, 400);
    setRange_9BB8(&D_00530600_9BB8.a[7], 300, 400);
    setRange_9BB8(&D_00530600_9BB8.a[8], 300, 400);
    setRange_9BB8(&D_00530600_9BB8.a[9], 300, 400);
    setRange_9BB8(&D_00530600_9BB8.a[10], 300, 400);
    setRange_9BB8(&D_00530600_9BB8.a[11], 350, 400);
    setRange_9BB8(&D_00530600_9BB8.a[12], 300, 400);
    setRange_9BB8(&D_00530600_9BB8.a[13], 300, 400);
    setRange_9BB8(&D_00530600_9BB8.a[14], 300, 400);
    setRange_9BB8(&D_00530600_9BB8.b[0], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[1], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[2], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[3], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[4], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[5], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[6], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[7], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[8], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[9], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[10], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[11], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[12], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[13], 200, 500);
    setRange_9BB8(&D_00530600_9BB8.b[14], 200, 500);
    // c[group][level][side]: groups written 1, 2, 3, 0, 5, 4; per group side 0 then side 1
    setRange_9BB8(&D_00530600_9BB8.c[1][0][0], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[1][1][0], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[1][2][0], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[1][0][1], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[1][1][1], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[1][2][1], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[2][0][0], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[2][1][0], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[2][2][0], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[2][0][1], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[2][1][1], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[2][2][1], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[3][0][0], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[3][1][0], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[3][2][0], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[3][0][1], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[3][1][1], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[3][2][1], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[0][0][0], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[0][1][0], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[0][2][0], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[0][0][1], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[0][1][1], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[0][2][1], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[5][0][0], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[5][1][0], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[5][2][0], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[5][0][1], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[5][1][1], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[5][2][1], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[4][0][0], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[4][1][0], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[4][2][0], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[4][0][1], 1000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[4][1][1], 2000, 3000);
    setRange_9BB8(&D_00530600_9BB8.c[4][2][1], 2500, 3000);
    setRange_9BB8(&D_00530600_9BB8.d[0], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[1], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[2], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[3], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[4], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[5], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[6], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[7], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[8], 3000, 4000);
    setRange_9BB8(&D_00530600_9BB8.d[9], 3000, 4000);
    D_00530600_9BB8.e[0] = 5000;
    D_00530600_9BB8.e[1] = 5000;
    D_00530600_9BB8.e[2] = 5000;
    D_00530600_9BB8.e[3] = 5000;
    D_00530600_9BB8.e[4] = 5000;
    D_00530600_9BB8.e[5] = 5000;
    D_00530600_9BB8.e[6] = 5000;
    D_00530600_9BB8.e[7] = 5000;
}
#endif


//100%
INCLUDE_ASM("be/beintstat", func_0014A078);
#ifdef SKIP_ASM
extern "C" void func_0014A078(int a0) {

}
#endif
