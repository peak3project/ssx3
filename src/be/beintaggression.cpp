#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A898[];
extern void* D_0045AC48[16];
extern void* D_004A124C;

struct cBEAggressionInterface {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

//100%
INCLUDE_ASM("be/beintaggression", cBEAggressionInterface_getThis__Fv);
#ifdef SKIP_ASM
void* cBEAggressionInterface_getThis()
{
    if (D_004A124C == 0) {
        cBEAggressionInterface* mem = (cBEAggressionInterface*)cMemMan_alloc(0x10, D_0045A898, 0, 0);
        mem->field_0x8 = 0;
        mem->vtable = D_0045AC48;
        D_004A124C = mem;
    }
    return D_004A124C;
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_00155AA0__FPv);
#ifdef SKIP_ASM
void func_00155AA0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_00155AA8__FPv);
#ifdef SKIP_ASM
void func_00155AA8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_00155AB0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
void* cBENewRaceInterface_getThis();
extern "C" int func_00145750(void* race);

struct sAggrTriple {
    signed char v[3];
};

struct sAggrCharProfile {
    char pad_0x000[0xBC1];
    sAggrTriple aggression[16]; // 0xBC1
    char pad_0xBF1[0xF88 - 0xBC1 - 16 * 3];
};

extern sAggrCharProfile D_004A6CA8[][10];

extern "C" int func_00155AB0(void* self, int a, int b)
{
    int profile = cBELibrary_getProfileIndex(b);
    int ca = cBELibrary_getCharacterID(a);
    int cb = cBELibrary_getCharacterID(b);
    if (func_00145750(cBENewRaceInterface_getThis()) == ca)
        return 2;
    return D_004A6CA8[profile][cb].aggression[ca].v[0];
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_00155B50);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
void* cBENewRaceInterface_getThis();
extern "C" int func_00145750(void* race);

extern sAggrCharProfile D_004A6CA8[][10];

extern "C" int func_00155B50(void* self, int a, int b)
{
    int profile = cBELibrary_getProfileIndex(b);
    int ca = cBELibrary_getCharacterID(a);
    int cb = cBELibrary_getCharacterID(b);
    if (func_00145750(cBENewRaceInterface_getThis()) == ca)
        return 3;
    return D_004A6CA8[profile][cb].aggression[ca].v[1];
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_00155BF0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern "C" void func_001E2A08(int charID, int level);
extern signed char D_005305F9[];

extern "C" void func_00155BF0(void* self, int a, int b, int event)
{
    int profile = cBELibrary_getProfileIndex(a);
    int ca = cBELibrary_getCharacterID(a);
    int cb = cBELibrary_getCharacterID(b);
    int add = 0;
    int oldLvl = D_004A6CA8[profile][ca].aggression[cb].v[1];
    int pts = D_004A6CA8[profile][ca].aggression[cb].v[2];
    int st = D_004A6CA8[profile][ca].aggression[cb].v[0];
    switch (event) {
    case 0:
        add = 1;
        break;
    case 1:
        add = 2;
        break;
    case 2:
        add = 4;
        break;
    case 3:
        add = 6;
        break;
    }
    pts += add;
    int lv = pts / 5;
    int lvl = lv;
    if (oldLvl < lvl) {
        if (a == 0 && D_005305F9[0] == 0) {
            func_001E2A08(cb, pts);
        }
        switch (st) {
        case 0:
            if (lv >= 3) {
                lvl = 2;
                pts = 10;
            }
            break;
        case 1:
            if (lv >= 4) {
                lvl = 2;
                pts = 10;
                st = 3;
            }
            break;
        case 2:
            if (lv <= 0) {
                lvl = 1;
                pts = 5;
            } else if (lv >= 4) {
                lvl = 3;
                pts = 15;
            }
            break;
        case 3:
            if (lv <= 0) {
                lvl = 1;
                pts = 5;
            } else if (lv >= 5) {
                lvl = 4;
                pts = 20;
            }
            break;
        }
    }
    D_004A6CA8[profile][ca].aggression[cb].v[2] = pts;
    D_004A6CA8[profile][ca].aggression[cb].v[1] = lvl;
    D_004A6CA8[profile][ca].aggression[cb].v[0] = st;
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_00155E58);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern "C" void func_001E2A08(int charID, int level);
extern sAggrCharProfile D_004A6CA8[][10];

struct sRaceSettings_155E58 {
    char pad_0x00[0x30];
    int numPlayers;     // 0x30
    char pad_0x34[0x15];
    signed char b49;    // 0x49
};
extern sRaceSettings_155E58 D_005305B0;

// Re-clamps every player's aggression level towards the other riders to the limits of its current state.
extern "C" void func_00155E58(void)
{
    for (int i = 0; i < D_005305B0.numPlayers; i++) {
        int profile = cBELibrary_getProfileIndex(i);
        for (int j = 0; j < 10; j++) {
            int ca = cBELibrary_getCharacterID(i);
            int pts = D_004A6CA8[profile][ca].aggression[j].v[2] - 3;
            if (pts < 0)
                pts = 0;
            int st = D_004A6CA8[profile][ca].aggression[j].v[0];
            int lvl = pts / 5;
            if (D_005305B0.b49 == 0) {
                func_001E2A08(j, pts);
            }
            switch (st) {
            case 0:
                if (lvl >= 3) {
                    lvl = 2;
                    pts = 10;
                }
                break;
            case 1:
                if (lvl >= 4) {
                    lvl = 2;
                    pts = 10;
                    st = 3;
                }
                break;
            case 2:
                if (lvl <= 0) {
                    lvl = 1;
                } else if (lvl >= 4) {
                    lvl = 3;
                    pts = 15;
                }
                break;
            case 3:
                if (lvl == 0) {
                    st = 1;
                    lvl = 3;
                    pts = 15;
                } else if (lvl >= 5) {
                    lvl = 4;
                    pts = 20;
                }
                break;
            }
            D_004A6CA8[profile][ca].aggression[j].v[0] = st;
            D_004A6CA8[profile][ca].aggression[j].v[2] = pts;
            D_004A6CA8[profile][ca].aggression[j].v[1] = lvl;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_001560A0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern int D_005305E0[];

struct sStreamVE_1560A0 { short delta; short index; void (*fn)(void*, void*, int); };

extern "C" void func_001560A0(void* self, void* stream)
{
    int n = D_005305E0[0];
    sStreamVE_1560A0* vt = *(sStreamVE_1560A0**)stream;
    vt[1].fn((char*)stream + vt[1].delta, &n, 4);
    for (int i = 0; i < n; i++)
    {
        int profile = cBELibrary_getProfileIndex(i);
        for (int j = 0; j < 10; j++)
        {
            int c = cBELibrary_getCharacterID(i);
            sStreamVE_1560A0* vt2 = *(sStreamVE_1560A0**)stream;
            vt2[1].fn((char*)stream + vt2[1].delta, &D_004A6CA8[profile][c].aggression[j], 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/beintaggression", func_001561B0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

struct sStreamVE_1561B0 { short delta; short index; void (*fn)(void*, void*, int); };

extern "C" void func_001561B0(void* self, void* stream)
{
    int n;
    sStreamVE_1561B0* vt = *(sStreamVE_1561B0**)stream;
    vt[2].fn((char*)stream + vt[2].delta, &n, 4);
    for (int i = 0; i < n; i++)
    {
        int profile = cBELibrary_getProfileIndex(i);
        for (int j = 0; j < 10; j++)
        {
            int c = cBELibrary_getCharacterID(i);
            sStreamVE_1561B0* vt2 = *(sStreamVE_1561B0**)stream;
            vt2[2].fn((char*)stream + vt2[2].delta, &D_004A6CA8[profile][c].aggression[j], 3);
        }
    }
}
#endif


//100%
INCLUDE_ASM("be/beintaggression", func_001562B8);
#ifdef SKIP_ASM
extern int D_004A11F4;
extern char* D_005308A8[];

extern "C" void func_001562B8(int *self) {
    char* obj;
    char* vtbl;
    char* obj2;
    char* vtbl2;
    int next;

    obj = D_005308A8[D_004A11F4];
    vtbl = *(char**)(obj + 4);
    (*(void (**)(void*))(vtbl + 0x1C))(obj + *(short*)(vtbl + 0x18));
    next = *self;
    D_004A11F4 = next;
    obj2 = D_005308A8[next];
    vtbl2 = *(char**)(obj2 + 4);
    (*(void (**)(void*))(vtbl2 + 0x24))(obj2 + *(short*)(vtbl2 + 0x20));
}
#endif
