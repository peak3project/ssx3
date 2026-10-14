#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001549A8(void* self);
extern const char D_0045A858[];
extern void* D_004A1248;

struct cBEScoreInterface {
    char pad_0x00[8];
    int field_0x8;
    char pad_0xC[4];
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1C;
};

//100%
INCLUDE_ASM("be/beintscore", cBEScoreInterface_getThis__Fv);
#ifdef SKIP_ASM
// PORT: the unit declares func_001549A8 as returning void; the body returns self.
void* func_001549A8_impl(void* self) __asm__("func_001549A8");

void* cBEScoreInterface_getThis()
{
    if (D_004A1248 == 0) {
        void* mem = cMemMan_alloc(0x230, D_0045A858, 0, 0);
        cBEScoreInterface* s = (cBEScoreInterface*)func_001549A8_impl(mem);
        D_004A1248 = s;
        s->field_0x8 = 0;
        s->field_0x10 = 0;
        s->field_0x14 = 0;
        s->field_0x18 = -1;
        s->field_0x1C = -1;
    }
    return D_004A1248;
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_001549A8);
#ifdef SKIP_ASM
extern "C" void func_001549E8(void* self);
extern void* D_0045ACA8[];

// PORT: the unit declares func_001549A8 as returning void (used by getThis);
// the body returns self, so it is bound to the symbol with an asm label.
void* func_001549A8_impl(void* self) __asm__("func_001549A8");

void* func_001549A8_impl(void* self)
{
    *(void***)((char*)self + 0xC) = D_0045ACA8;
    func_001549E8(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_001549E0__FPv);
#ifdef SKIP_ASM
void func_001549E0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_001549E8);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);

struct sScoreSlot_001549E8 {
    char pad_0x00[0xAC];
    int last; // 0xAC
};

struct sScore_001549E8 {
    char pad_0x00[0x10];
    int a;    // 0x10
    int b;    // 0x14
    int c;    // 0x18
    int d;    // 0x1C
    sScoreSlot_001549E8 slots[2]; // 0x20
};

extern "C" void func_001549E8(void* p)
{
    sScore_001549E8* self = (sScore_001549E8*)p;
    self->a = 0;
    self->b = 0;
    self->c = -1;
    self->d = -1;
    func_003E6448(self->slots, 0, sizeof(self->slots));
    for (int i = 1; i >= 0; i--)
    {
        self->slots[i].last = -1;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00154A58);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
extern "C" void func_00155420(int rider, int a, int b, int c);
extern signed char D_005305F9[];

extern "C" void func_00154A58(int rider, int a)
{
    int profile = cBELibrary_getProfileIndex(rider);
    if (D_005305F9[0] == 0 && profile < 2)
    {
        func_00155420(rider, a, -1, -1);
    }
}
#endif

INCLUDE_ASM("be/beintscore", func_00154AB8);

//100%
INCLUDE_ASM("be/beintscore", func_00154EE8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBELibrary_getProfileIndex(int);
signed char cBELibrary_getCharacterID(int index);
extern "C" int func_00155328(void* self, int a);
extern "C" void func_001E25D8(int mode, int event, int result);
extern "C" void func_001E1EB8(void);
extern "C" void func_001E1550(void);
extern "C" int func_001456A0(void* self, int idx, int mode);
extern "C" void func_001591E8(void* iface, int profile, int charID, int mode, int event, int medal);
extern signed char D_00535C12[];

struct sRaceSettings_154EE8 {
    char pad_0x00[0x40];
    int event;          // 0x40
    char pad_0x44[0x4];
    signed char b48;    // 0x48
    signed char b49;    // 0x49
};
extern sRaceSettings_154EE8 D_005305B0;

struct sEvent_154EE8 {
    int id;
    char pad_0x4[0x60];
};
extern sEvent_154EE8 D_0043D950[];

// Race result: records it, refreshes the event popups and passes the medal (cleared when the record is not beaten) to the reward interface.
extern "C" void func_00154EE8(char* self, int rider, int result, int score)
{
    int profile = cBELibrary_getProfileIndex(rider);
    if (profile >= 2)
        return;
    *(int*)(self + profile * 0xB0 + 0xCC) = result;
    void* be = cBE_getInterface_Fv(cBE_getBE(), 0);
    int charID = cBELibrary_getCharacterID(rider);
    int mode = D_00535C12[0];
    int event = D_0043D950[D_005305B0.event].id;
    if (event == 0x16)
        event = 0;
    int medal = func_00155328(self, result);
    if (mode == 4 || mode == 5)
        medal = result == 0 ? 1 : -1;
    if (D_005305B0.b49 == 0)
        func_001E25D8(mode, event, result);
    if (medal == -1)
        return;
    if (D_005305B0.b49 == 0) {
        func_001E1EB8();
        if (D_005305B0.b49 == 0 && mode != 4 && mode != 5)
            func_001E1550();
    }
    void* reward = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    if (D_005305B0.b49 != 0)
        return;
    if (D_005305B0.b48 == 4)
        return;
    int best = func_001456A0(be, event, mode);
    if (best != -1) {
        if (mode == 0 || mode == 4) {
            if (best * 60 >= score)
                medal = 0;
        } else {
            if (score >= best)
                medal = 0;
        }
    }
    func_001591E8(reward, profile, charID, mode, event, medal);
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_001550E8);
#ifdef SKIP_ASM
struct sScoreEntry_001550E8 {
    int value;
    char pad[0x10];
};
extern "C" sScoreEntry_001550E8* func_0014AB20(int a, int b);

extern "C" int func_001550E8(void* self, int i, int a, int b)
{
    sScoreEntry_001550E8* t = func_0014AB20(a, b);
    if (t != 0) {
        return t[i].value;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155130);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern int D_005305F0[];
extern signed char D_00535C12[];

extern "C" int func_00155130(void* self, int i)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    sScoreEntry_001550E8* t = func_0014AB20(D_005305F0[0], D_00535C12[0]);
    if (t != 0)
    {
        return t[i].value;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155190);
#ifdef SKIP_ASM
struct sScoreEntryB_00155190
{
    int value;
    int idx;
    char pad[0xC];
};
struct sScoreSlot_00155190
{
    char data[0x88];
};
extern sScoreSlot_00155190 D_00530990[];
extern void* D_004A1244;

extern "C" void* func_00155190(void* self, int i)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    sScoreEntryB_00155190* t = (sScoreEntryB_00155190*)func_0014AB20(D_005305F0[0], D_00535C12[0]);
    if (t == 0)
        return D_004A1244;
    return &D_00530990[t[i].idx];
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155208);
#ifdef SKIP_ASM
struct sScoreEntryB_00155208
{
    int value;
    int idx;
    char f8[0xC];
};
extern void* D_004A1244;

extern "C" void* func_00155208(void* self, int i)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    sScoreEntryB_00155208* t = (sScoreEntryB_00155208*)func_0014AB20(D_005305F0[0], D_00535C12[0]);
    if (t != 0)
        return t[i].f8;
    return D_004A1244;
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155270);
#ifdef SKIP_ASM
extern "C" void* func_00155270(void* self, int a1)
{
    return (char*)self + (a1 * 0xb0 + 0x20);
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155288);
#ifdef SKIP_ASM
extern char D_004A6CA8[];

extern "C" void* func_00155288(void* self, int a1, int a2)
{
    char* p = D_004A6CA8 + (a1 * 0x9b50 + a2 * 0xf88);
    return p + 0xde4;
}
#endif

signed char cBELibrary_getCharacterID(int index);
extern char D_004A6CA8[];

//97.94%
INCLUDE_ASM("be/beintscore", cBEScoreInterface_getCurrentHighlightLevel__FPvi);
#ifdef SKIP_ASM
signed char cBEScoreInterface_getCurrentHighlightLevel(void* self, int riderIndex)
{
    int charID = cBELibrary_getCharacterID(0);
    char* p = D_004A6CA8 + riderIndex + charID * 0xF88;
    return p[0xBB8];
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155328);
#ifdef SKIP_ASM
extern "C" int func_00155328(void* self, int a)
{
    switch (a) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155380__FPv);
#ifdef SKIP_ASM
void func_00155380(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155388__FPv);
#ifdef SKIP_ASM
void func_00155388(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_00155390);
#ifdef SKIP_ASM
extern short D_00440ED0[][3];

extern "C" void func_00155390(char* self, int idx, int score)
{
    signed char cur = *(signed char*)(self + idx + 0xBB8);
    int level = 0;
    int i;
    for (i = 2; i >= 0; i--) {
        if (score >= D_00440ED0[idx][i]) {
            level = i + 1;
            break;
        }
    }
    if (cur < level) {
        *(signed char*)(self + idx + 0xBB8) = level;
    }
}
#endif

INCLUDE_ASM("be/beintscore", func_00155420);

//100%
INCLUDE_ASM("be/beintscore", func_001557E0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" bool func_0014F810(int i);
extern int D_00535BFC[];

extern "C" bool func_001557E0(void* self, int rider)
{
    if (rider >= 2 || func_0014F810(0))
        return false;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BFC[0] >= 2)
        return !func_0014F810(0);
    return true;
}
#endif

//100%
INCLUDE_ASM("be/beintscore", func_001558F8);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
signed char cBELibrary_getCharacterID(int index);
void* cBECharProfileDB_getScoreStats(void* self, int a, int b);
extern signed char D_005305F9[];
extern char D_004A6CA8[];

extern "C" int func_001558F8(void* self, int rider, int a, int b)
{
    if (D_005305F9[0] != 0)
        return -1;
    int profile = cBELibrary_getProfileIndex(rider);
    if ((unsigned int)profile >= 3)
        return -1;
    int c = cBELibrary_getCharacterID(rider);
    signed char* stats = (signed char*)cBECharProfileDB_getScoreStats(D_004A6CA8 + profile * 0x9b50 + c * 0xf88, a, b);
    if (stats == 0)
        return -1;
    return stats[1];
}
#endif

