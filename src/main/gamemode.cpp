#include "common.h"
#include "ai/rider.h"

//100%
INCLUDE_ASM("main/gamemode", cGameModeMan_getGM);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_00536668[];
extern int* D_004A2C6C;
extern char* D_004A2C70;
extern char D_0047C0A8[];
extern char D_0047C0B8[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00416210(void* dst, int c, int n);
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern void* D_0047CC60[];
extern void* D_0047CCC8[];
extern void* D_0047CD30[];
extern void* D_0047CD98[];
extern void* D_0047CE00[];
extern void* D_0047CE68[];
extern void* D_0047CED0[];
extern void* D_0047CF38[];
extern void* D_0047CFA0[];

struct sGMMode_4 {
    void** vt;
    sGMMode_4(void** v) { vt = v; }
};

struct sGMMode_8 {
    void** vt;
    char pad[0x4];
    sGMMode_8(void** v) { vt = v; }
};

struct sGMMode_C {
    void** vt;
    char pad[0x8];
    sGMMode_C(void** v) { vt = v; }
};

struct sGMMode_2C {
    void** vt;
    char pad[0x28];
    sGMMode_2C(void** v) { vt = v; }
};

struct sGMMode_7C {
    void** vt;
    char pad[0x78];
    sGMMode_7C(void** v) { vt = v; }
};

struct sGMMode_D0 {
    void** vt;
    char pad[0xCC];
    sGMMode_D0(void** v) { vt = v; }
};

extern "C" int* cGameModeMan_getGM(void)
{
    if (D_004A2C6C == 0) {
        D_004A2C6C = (int*)cMemMan_alloc(0xA0, D_0047C0A8, 0, 0);
        func_00416210(D_00536668, 0, 0x28);
        if (D_00536668[0] == 0) {
            D_00536668[0] = new (D_0047C0B8, 0, 0) sGMMode_7C(D_0047CFA0);
            if (D_00536668[0] == 0) {
                D_00536668[0] = new (D_0047C0B8, 0, 0) sGMMode_7C(D_0047CFA0);
                if (D_00536668[0] == 0) {
                    D_00536668[0] = new (D_0047C0B8, 0, 0) sGMMode_7C(D_0047CFA0);
                }
            }
        }
        if (D_00536668[1] == 0) {
            D_00536668[1] = new (D_0047C0B8, 0, 0) sGMMode_D0(D_0047CF38);
        }
        if (D_00536668[2] == 0) {
            D_00536668[2] = new (D_0047C0B8, 0, 0) sGMMode_4(D_0047CE00);
        }
        if (D_00536668[5] == 0) {
            D_00536668[5] = new (D_0047C0B8, 0, 0) sGMMode_4(D_0047CD30);
        }
        if (D_00536668[4] == 0) {
            D_00536668[4] = new (D_0047C0B8, 0, 0) sGMMode_C(D_0047CD98);
            if (D_00536668[4] == 0) {
                D_00536668[4] = new (D_0047C0B8, 0, 0) sGMMode_C(D_0047CD98);
                if (D_00536668[4] == 0) {
                    D_00536668[4] = new (D_0047C0B8, 0, 0) sGMMode_C(D_0047CD98);
                }
            }
        }
        if (D_00536668[6] == 0) {
            D_00536668[6] = new (D_0047C0B8, 0, 0) sGMMode_4(D_0047CCC8);
        }
        if (D_00536668[7] == 0) {
            D_00536668[7] = new (D_0047C0B8, 0, 0) sGMMode_C(D_0047CC60);
            if (D_00536668[7] == 0) {
                D_00536668[7] = new (D_0047C0B8, 0, 0) sGMMode_C(D_0047CC60);
                if (D_00536668[7] == 0) {
                    D_00536668[7] = new (D_0047C0B8, 0, 0) sGMMode_C(D_0047CC60);
                }
            }
        }
        if (D_00536668[8] == 0) {
            D_00536668[8] = new (D_0047C0B8, 0, 0) sGMMode_2C(D_0047CED0);
        }
        if (D_00536668[9] == 0) {
            D_00536668[9] = new (D_0047C0B8, 0, 0) sGMMode_8(D_0047CE68);
            if (D_00536668[9] == 0) {
                D_00536668[9] = new (D_0047C0B8, 0, 0) sGMMode_8(D_0047CE68);
                if (D_00536668[9] == 0) {
                    D_00536668[9] = new (D_0047C0B8, 0, 0) sGMMode_8(D_0047CE68);
                }
            }
        }
        if (D_00536668[5] == 0) {
            D_00536668[5] = new (D_0047C0B8, 0, 0) sGMMode_4(D_0047CD30);
        }
        if (D_00536668[6] == 0) {
            D_00536668[6] = new (D_0047C0B8, 0, 0) sGMMode_4(D_0047CCC8);
        }
        int* gm = D_004A2C6C;
        D_004A2C70 = (char*)gm;
        gm[2] = -1;
        gm[0] = 0;
        gm[1] = 0;
        gm[0x20] = 0;
    }
    return D_004A2C6C;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_002380E8);
#ifdef SKIP_ASM
class cMode2380E8 {
public:
    virtual ~cMode2380E8();
};
void operator_delete(int*);
extern void* D_00536668[];
extern int* D_004A2C6C;

extern "C" void func_002380E8(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        delete (cMode2380E8*)D_00536668[i];
    }
    if (D_004A2C6C != 0) {
        operator_delete(D_004A2C6C);
    }
    D_004A2C6C = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", cGameModeMan_initGameMode);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C11[];
extern "C" void cGameModeMan_restartHeat(void* self);

struct sVE_initGameMode { short delta; short index; void (*fn)(void*); };

struct sGameModeMan {
    int f0;
    int mode;      // 0x4
    unsigned int type;  // 0x8
    int net;       // 0xC
    char pad[0x84 - 0x10];
    int f84;       // 0x84
};

extern "C" void cGameModeMan_initGameMode(sGameModeMan* self, unsigned int type)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    char* gm = (char*)D_00536668[self->mode];
    sVE_initGameMode* vt = *(sVE_initGameMode**)gm;
    vt[3].fn(gm + vt[3].delta);
    self->type = type;
    int net = D_00535C11[0];
    self->net = net;
    if (net == 2) {
        switch (type) {
        case 0: self->mode = 8; break;
        case 1: self->mode = 9; break;
        case 3: self->mode = 9; break;
        case 2: self->mode = 9; break;
        case 4: self->mode = 5; break;
        case 5: self->mode = 6; break;
        default: self->mode = 8; break;
        }
    } else {
        switch (type) {
        case 1:
        case 2:
        case 3:
            self->mode = 0;
            break;
        case 0: self->mode = 1; break;
        case 12: self->mode = 2; break;
        case 4: self->mode = 5; break;
        case 6: self->mode = 4; break;
        case 7: self->mode = 4; break;
        case 8: self->mode = 4; break;
        case 5: self->mode = 6; break;
        case 9:
        case 10:
        case 11:
            self->mode = 7;
            break;
        }
    }
    self->f84 = 1;
    cGameModeMan_restartHeat(self);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_002382B8);
#ifdef SKIP_ASM
extern int D_00536730[];

extern "C" void func_002382B8(void* self, int idx)
{
    D_00536730[idx] = -1;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", cGameModeMan_restartHeat);
#ifdef SKIP_ASM
struct sVEntry_002382D8 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern void* D_00536668[];
extern int D_005366D0[];

extern "C" void cGameModeMan_restartHeat(void* self)
{
    int i;
    void* obj = D_00536668[*(int*)((char*)self + 0x4)];
    sVEntry_002382D8* vt = *(sVEntry_002382D8**)obj;
    vt[2].fn((char*)obj + vt[2].delta);
    for (i = 5; i >= 0; i--) {
        D_005366D0[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238348__FPv);
#ifdef SKIP_ASM
int func_00238348(void* self)
{
    int t0 = *(int*)((char*)self + 0x74);
    *(int*)((char*)self + 0x70) = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238358);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern void* D_00536668[];
extern unsigned int D_00536640[];
extern int D_00536730[];
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int* func_00144BC0(void* iface);
extern "C" void func_00154AB8(void* self, int idx, int a2, unsigned int v);
extern "C" void func_00154EE8(void* self, int idx, int a2, unsigned int v);
extern "C" int func_001577E0(void* self, int a, int b);
extern "C" int func_0015A2E0(void* self, int a1, int a2, int bit);
extern "C" void func_00159CD0(void* self, int a1, int a2, int bit);
int cBELibrary_getProfileIndex(int);
signed char cBELibrary_getCharacterID(int index);

struct sVEntry_00238358 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00238358(void* self, int idx, int a2)
{
    void* obj = D_00536668[*(int*)((char*)self + 4)];
    sVEntry_00238358* vt = *(sVEntry_00238358**)obj;
    vt[8].fn((char*)obj + vt[8].delta, idx);
    if (*func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0)) < 0x11) {
        int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
        int ok = n != 0 && n < 10;
        if (!ok) {
            void* score = cBE_getInterface_Fv(cBE_getBE(), 8);
            unsigned int v = D_00536640[idx];
            func_00154AB8(score, idx, a2, v);
            if (idx == 0) {
                int prof = cBELibrary_getProfileIndex(0);
                int ch = cBELibrary_getCharacterID(0);
                void* p = cBE_getInterface_Fv(cBE_getBE(), 0xD);
                if (func_001577E0(p, prof, ch)) {
                    if (func_0015A2E0(p, prof, prof, 0) == 0) {
                        func_00159CD0(p, prof, ch, 0);
                    }
                }
            }
            if (*(int*)((char*)self + 0x9C)) {
                func_00154EE8(score, idx, D_00536730[idx], v);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238510);
#ifdef SKIP_ASM
struct sVEntry_00238510 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern void* D_00536668[];

extern "C" void func_00238510(void* self, int a, int b)
{
    void* obj = D_00536668[*(int*)((char*)self + 0x4)];
    sVEntry_00238510* vt = *(sVEntry_00238510**)obj;
    vt[6].fn((char*)obj + vt[6].delta, a, b);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238550);
#ifdef SKIP_ASM
struct sVEntry_00238550 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern void* D_00536668[];

extern "C" void func_00238550(void* self, int a, int b)
{
    void* obj = D_00536668[*(int*)((char*)self + 0x4)];
    sVEntry_00238550* vt = *(sVEntry_00238550**)obj;
    vt[7].fn((char*)obj + vt[7].delta, a, b);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238590);
#ifdef SKIP_ASM
struct sVEntry_00238590 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern void* D_00536668[];

extern "C" void func_00238590(void* self, int a, int b)
{
    void* obj = D_00536668[*(int*)((char*)self + 0x4)];
    sVEntry_00238590* vt = *(sVEntry_00238590**)obj;
    vt[9].fn((char*)obj + vt[9].delta, a, b);
}
#endif

INCLUDE_ASM("main/gamemode", func_002385D0);

INCLUDE_ASM("main/gamemode", func_002388A0);
//100%
INCLUDE_ASM("main/gamemode", func_00238B70);
#ifdef SKIP_ASM
extern int D_00536730[];
extern int D_00536708[];
extern "C" int func_00245E30(const void* a, const void* b);
extern "C" int func_00245EC0(const void* a, const void* b);
extern "C" void func_00418EF8(void* base, int n, int size, int (*cmp)(const void*, const void*));

extern "C" void func_00238B70(void* self, int n)
{
    int i;
    for (i = 0; i < 10; i++) {
        D_00536730[i] = i;
        D_00536708[i] = i;
    }
    func_00418EF8(D_00536708, n, 4, func_00245E30);
    func_00418EF8(D_00536730, n, 4, func_00245EC0);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238BF8);
#ifdef SKIP_ASM
extern int D_00536730[];
extern int D_00536708[];
extern "C" int func_00245E78(const void* a, const void* b);
extern "C" int func_00245EC0(const void* a, const void* b);
extern "C" void func_00418EF8(void* base, int n, int size, int (*cmp)(const void*, const void*));

extern "C" void func_00238BF8(void* self, int n)
{
    int i;
    for (i = 0; i < 10; i++) {
        D_00536730[i] = i;
        D_00536708[i] = i;
    }
    func_00418EF8(D_00536708, n, 4, func_00245E78);
    func_00418EF8(D_00536730, n, 4, func_00245EC0);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238C80);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);

struct sGM00238C80 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
};
extern char* D_004A2C70;

struct sVEntry00238C80 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00238C80(void* self)
{
    sGM00238C80* gm = (sGM00238C80*)D_004A2C70;
    gm->f84 = 1;
    gm->f4 = -1;
    gm->f68 = -1;
    gm->f6C = -1;
    gm->f8 = -1;
    gm->f98 = 0;
    gm->f0 = 0;
    gm->f70 = 0;
    gm->f74 = 0;
    gm->f10 = 0;
    gm->f14 = 0;
    gm->f78 = 0;
    gm->f7C = 0;
    gm->f80 = 0;
    gm->f88 = 0;
    gm->f8C = 0;
    gm->f90 = 0;
    gm->f94 = 0;
    func_00416210(gm->a18, 0, 0x28);
    func_00416210(((sGM00238C80*)D_004A2C70)->a40, 0, 0x28);
    sVEntry00238C80* e = &(*(sVEntry00238C80**)self)[5];
    e->fn((char*)self + e->delta);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238D30);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern int D_00536730[];
extern int D_00536708[];
extern unsigned int D_00536640[];
extern int D_005366A8[];
extern int D_005366D0[];

extern "C" void func_00238D30(void)
{
    func_00416210(D_00536730, 9, 0x28);
    func_00416210(D_00536708, 0, 0x28);
    func_00416210(D_00536640, 0, 0x28);
    func_00416210(D_005366A8, 0, 0x28);
    func_00416210(D_005366D0, 0, 0x18);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238DA8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern int D_00536730[];
extern int D_00536708[];
extern unsigned int D_00536640[];
extern int D_005366A8[];
extern int D_005366D0[];

extern "C" void func_00238DA8(void)
{
    func_00416210(D_00536730, 9, 0x28);
    func_00416210(D_00536708, 0, 0x28);
    func_00416210(D_00536640, 9, 0x28);
    func_00416210(D_005366A8, 0, 0x28);
    func_00416210(D_005366D0, 0, 0x18);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00238E20);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_001454F8(void* iface, int a1);
extern "C" void func_00238B70(void* self, int n);
// PORT: func_00239938 is defined as (void); this caller passes self.
extern "C" void func_00239938_self(void* self) __asm__("func_00239938");
struct sScore_239AA0;
extern "C" void func_00239AA0(sScore_239AA0* self);
extern "C" void* func_00416210(void* dst, int c, int n);
extern void* D_004A28A8;
extern char* D_004A2C70;
extern signed char D_00535C11[];
extern unsigned int D_00536640[];
extern int D_00536708[];

struct sGM_238E20 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_238E20 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sScore_238E20 {
    sVEntry_238E20* vt;
    int t[3][10];
};

struct sRace_238E20 {
    char pad00[0x20];
    int f20;
    int f24;
};

static inline sRace_238E20* race_238E20()
{
    return *(sRace_238E20**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
}

extern "C" void func_00238E20(sScore_238E20* self)
{
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    int i;
    sGM_238E20* gm = (sGM_238E20*)D_004A2C70;
    int quick = D_00535C11[0];
    gm->f8C = 0;
    gm->f7C = 0;
    if (quick != 0) {
        gm->f10 = 5;
        if (gm->f8 == 1) {
            gm->f14 = 4;
        } else {
            gm->f14 = 5;
        }
        sGM_238E20* g1 = (sGM_238E20*)D_004A2C70;
        g1->f6C = -1;
        g1->f90 = 0;
        if (g1->f8 == 1) {
            g1->f94 = g1->f8;
        } else {
            g1->f94 = 0;
        }
        func_00416210(self->t, 0, 0x78);
        self->vt[4].fn((char*)self + self->vt[4].delta);
        if (((sGM_238E20*)D_004A2C70)->f84 == 1) {
            func_00239938_self(self);
        }
        sGM_238E20* g2 = (sGM_238E20*)D_004A2C70;
        g2->f70 = 3;
        g2->f74 = 3;
        func_00239AA0((sScore_239AA0*)self);
    }
    ((sGM_238E20*)D_004A2C70)->f78 = func_001454F8(race, ((sGM_238E20*)D_004A2C70)->f0) * 60;
    sGM_238E20* g3 = (sGM_238E20*)D_004A2C70;
    if (g3->f8 == 2) {
        g3->f94 = 0;
    } else {
        g3->f94 = 1;
    }
    sGM_238E20* g = (sGM_238E20*)D_004A2C70;
    int s = g->f70;
    g->f0 = s;
    switch (s) {
    case 0:
    case 1: {
        g->f0 = 1;
        g->f70 = 1;
        g->f74 = 1;
        g->f10 = 5;
        g->f88 = 1;
        g->f90 = 0;
        g->f9C = 0;
        g->f98 = 0;
        g->f80 = 0;
        g->f14 = 5;
        g->f6C = -1;
        self->t[0][0] = 0;
        self->t[1][0] = 0;
        self->t[2][0] = 0;
        int* t0 = self->t[0];
        if (g->f84 == 1) {
            func_00416210(t0, 0, 0x78);
            self->vt[4].fn((char*)self + self->vt[4].delta);
            func_00239938_self(self);
            func_00239AA0((sScore_239AA0*)self);
        }
        D_00536640[0] = 0;
        for (i = 1; i < ((sGM_238E20*)D_004A2C70)->f10 + 1; i++) {
            D_00536640[i] = self->t[2][i];
        }
        func_00238B70(D_004A2C70, ((sGM_238E20*)D_004A2C70)->f10 + 1);
        {
            sGM_238E20* h = (sGM_238E20*)D_004A2C70;
            race_238E20()->f20 = h->a18[D_00536708[0]];
            race_238E20()->f24 = h->a18[D_00536708[1]];
            for (i = 1; i < ((sGM_238E20*)D_004A2C70)->f10 + 1; i++) {
                D_00536640[i] = t0[i];
            }
        }
        func_00238B70(D_004A2C70, ((sGM_238E20*)D_004A2C70)->f10 + 1);
        ((sGM_238E20*)D_004A2C70)->f84 = 0;
        break;
    }
    case 2:
        g->f9C = 0;
        g->f70 = 1;
        g->f74 = 1;
        g->f98 = 0;
        D_00536640[0] = 0;
        for (i = 1; i < ((sGM_238E20*)D_004A2C70)->f10 + 1; i++) {
            D_00536640[i] = self->t[1][i] + self->t[0][i];
        }
        func_00238B70(D_004A2C70, ((sGM_238E20*)D_004A2C70)->f10 + 1);
        break;
    case 3:
        g->f98 = 1;
        g->f70 = 3;
        g->f74 = 3;
        g->f88 = 1;
        g->f9C = 0;
        g->f84 = 0;
        D_00536640[0] = 0;
        for (i = 1; i < ((sGM_238E20*)D_004A2C70)->f10 + 1; i++) {
            D_00536640[i] = self->t[2][i];
        }
        func_00238B70(D_004A2C70, ((sGM_238E20*)D_004A2C70)->f10 + 1);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00239230);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_00122E50(void* self);
extern "C" int func_0012A250(void* race);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_00147D20(void* iface, int a1);
extern "C" void func_00147E18(void* iface, int a1);
extern "C" void func_00238B70(void* self, int n);
extern char* D_004A2C70;
extern void* D_004A28A8;
extern unsigned int D_00536640[];
extern int D_005366A8[];
extern int D_00536730[];
extern signed char D_00535C11[];

struct sGM_239230 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sScore_239230 {
    void* vt;
    int t[3][10];
};

// cRiderMetrix block copied out of the rider (0xAC bytes; finish time at 0x9C).
struct sStats_239230 {
    int v[0x9C / 4];
    int time;           // 0x9C
    int w[3];
};

// The race (*(D_004A28A8 + 0x84) + 0xC): rider list at 0x28, player objects at 0x40, last index at 0x80.
struct sRace_239230 {
    char pad_0x0[0x28];
    cRider* riders[6];  // 0x28
    char* players[16];  // 0x40: each holds its cRider virtual-base pointer at +0x18
    int f80;            // 0x80
};

static inline sRace_239230* Race_239230()
{
    return *(sRace_239230**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
}

static inline cRider* Rider_239230(int i)
{
    return Race_239230()->riders[i];
}

extern "C" void func_00239230(sScore_239230* self, int idx)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    int quick = D_00535C11[0];
    int n = func_00146E98(player, 0);
    sStats_239230 st = *(sStats_239230*)((char*)Rider_239230(idx)->mMetrix + 0xFC);
    if (Rider_239230(idx)->mDidNotFinish != 0) {
        self->t[((sGM_239230*)D_004A2C70)->f0 - 1][idx] = 0;
        D_005366A8[idx] = 1;
    } else {
        self->t[((sGM_239230*)D_004A2C70)->f0 - 1][idx] = st.time;
        D_005366A8[idx] = 0;
    }
    if (func_0012A250(Race_239230()) == 0)
        return;
    sGM_239230* gm = (sGM_239230*)D_004A2C70;
    switch (gm->f0) {
    case 1:
        gm->f74 = gm->f70;
        for (int i = 0; i < ((sGM_239230*)D_004A2C70)->f10 + 1; i++)
            D_00536640[i] = self->t[0][i] + self->t[1][i];
        func_00238B70(D_004A2C70, ((sGM_239230*)D_004A2C70)->f10 + 1);
        if (D_00536730[idx] < 3)
            ((sGM_239230*)D_004A2C70)->f70 = 3;
        else
            ((sGM_239230*)D_004A2C70)->f70 = ((sGM_239230*)D_004A2C70)->f0 + 1;
        for (int i = 0; i < ((sGM_239230*)D_004A2C70)->f10 + 1; i++)
            D_00536640[i] = self->t[0][i];
        if (D_00536730[idx] >= 3) {
            func_00238B70(D_004A2C70, ((sGM_239230*)D_004A2C70)->f10 + 1);
            if (D_00536730[idx] >= 3) {
                Rider_239230(idx)->unk_100 = 0;
                break;
            }
        }
        Rider_239230(idx)->unk_100 = 1;
        break;
    case 2:
        for (int i = 0; i < ((sGM_239230*)D_004A2C70)->f10 + 1; i++)
            D_00536640[i] = self->t[0][i] + self->t[1][i];
        func_00238B70(D_004A2C70, ((sGM_239230*)D_004A2C70)->f10 + 1);
        for (int i = 0; i < ((sGM_239230*)D_004A2C70)->f10 + 1; i++)
            D_00536640[i] = self->t[1][i];
        gm = (sGM_239230*)D_004A2C70;
        gm->f74 = gm->f70;
        if (D_00536730[idx] < 3) {
            gm->f70 = 3;
            Rider_239230(idx)->unk_100 = 1;
            if (quick == 0 && D_00536730[idx] == 0)
                func_00147D20(player, 0);
        } else {
            gm->f70 = 1;
            Rider_239230(idx)->unk_100 = 0;
            if (quick == 0)
                func_00147E18(player, 0);
        }
        break;
    case 3: {
        gm->f9C = 1;
        int last = Race_239230()->f80;
        for (int i = 0; i < last + 1; i++) {
            cRider* r = Rider_239230(i);
            int done = r->mFinishTime >= 0.0f;
            if (!done)
                self->t[2][i] = func_00122E50(r);
        }
        for (int i = 0; i < ((sGM_239230*)D_004A2C70)->f10 + 1; i++)
            D_00536640[i] = self->t[2][i];
        func_00238B70(D_004A2C70, ((sGM_239230*)D_004A2C70)->f10 + 1);
        gm = (sGM_239230*)D_004A2C70;
        gm->f74 = gm->f70;
        int lost = !(D_00536730[idx] < 3);
        if (quick == 0 && !lost) {
            gm->f70 = 0;
            gm->f74 = 0;
        } else {
            gm->f70 = 3;
        }
        if (lost) {
            Rider_239230(idx)->unk_100 = 0;
            if (quick == 0)
                func_00147E18(player, 0);
        } else {
            Rider_239230(idx)->unk_100 = 1;
            if (quick == 0)
                func_00147D20(player, 0);
        }
        break;
    }
    }
    int place = D_00536730[n];
    if (place == 0)
        (*(cRider**)(Race_239230()->players[0] + 0x18))->unk_2F8 = 0.699999988079071f;
    else if (place == 1)
        (*(cRider**)(Race_239230()->players[0] + 0x18))->unk_2F8 = 0.3499999940395355f;
    else
        (*(cRider**)(Race_239230()->players[0] + 0x18))->unk_2F8 = 0.0f;
}
#endif

INCLUDE_ASM("main/gamemode", func_002398E8);

//100%
INCLUDE_ASM("main/gamemode", func_00239938);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" int func_00145750(void* iface);
extern "C" int func_00147410(void* iface, int player);
extern "C" void func_0023C770(int* arr, unsigned int n);
extern signed char D_00535BC8[];

struct sGM_239938 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
};

extern "C" void func_00239938(void)
{
    int n = 0;
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    int p = func_00146E98(player, 0);
    int charA = cBENewPlayerInterface_getRiderCharID(player, p);
    int charB = func_00145750(race);
    int list[10];

    for (int i = 0; i < 10; i++) {
        if (i != charA && i != charB) {
            list[n] = i;
            n++;
        }
    }
    func_0023C770(list, n);
    ((sGM_239938*)D_004A2C70)->a18[0] = charA;
    ((sGM_239938*)D_004A2C70)->a40[0] = func_00147410(player, p);
    ((sGM_239938*)D_004A2C70)->a18[1] = charB;
    ((sGM_239938*)D_004A2C70)->a40[1] = 0;
    for (int j = 0; j < n && j + 2 < 10; j++) {
        ((sGM_239938*)D_004A2C70)->a18[j + 2] = list[j];
        ((sGM_239938*)D_004A2C70)->a40[j + 2] = 0;
    }
    if (D_00535BC8[0x49] != 0) {
        ((sGM_239938*)D_004A2C70)->a18[1] = list[n - 1];
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00239AA0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" short func_00147CB8(void* self, int which);
extern "C" int func_001453D0(void* self, int kind, int place, int mode);
extern "C" void func_00238B70(void* self, int n);
extern char* D_004A2C70;
extern signed char D_00535BC8[];
extern unsigned int D_00536640[];
extern int D_00536730[];

struct sOpts_239AA0 {
    char pad00[0x49];
    signed char f49;
};

struct sScore_239AA0 {
    int f0;
    int t[3][10];
};

static inline int opt49_239AA0(sOpts_239AA0* o)
{
    return o->f49;
}

extern "C" void func_00239AA0(sScore_239AA0* self)
{
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    int nB = *(int*)(D_004A2C70 + 0x14);
    int d = *(int*)(D_004A2C70 + 0x10) - nB;
    int k = 0;
    for (int i = 0; i < d + 1; i++) {
        D_00536730[i] = 5 - i;
        for (int j = 0; j < 3; j++) {
            self->t[j][i] = 0;
        }
        D_00536640[i] = self->t[0][i];
        k++;
    }
    int nA = d + 1;
    for (int r = 0; r < nB; r++) {
        for (int c = 0; c < 3; c++) {
            int b = opt49_239AA0((sOpts_239AA0*)D_00535BC8);
            int same = 0;
            if (c != 0) same = 1;
            if (b == 0) same = 0;
            if (same) {
                self->t[c][k] = self->t[0][k];
            } else {
                self->t[c][k] = func_001453D0(race, c + 1, r, func_00147CB8(player, 0));
            }
        }
        D_00536640[k] = self->t[0][k];
        D_00536730[k] = r;
        k++;
    }
    func_00238B70(D_004A2C70, nA + nB);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00239CE0);
#ifdef SKIP_ASM
struct sScoreTable239CE0 {
    int f0;
    int tbl[8][10];
};
extern char* D_004A2C70;

extern "C" int func_00239CE0(sScoreTable239CE0* self, int col, int row)
{
    if (*(int*)D_004A2C70 < row) {
        return 0;
    }
    return self->tbl[row][col];
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00239D18);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
class cGameModeStream {
public:
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

extern "C" void func_00239D18(void* self, cGameModeStream* s)
{
    s->v01((char*)self + 0x4, 0xA0);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00239D50);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
extern "C" void func_00239D50(void* self, cGameModeStream* s)
{
    s->v02((char*)self + 0x4, 0xA0);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_00239D88);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getPlayerCharID(void* iface, int player);
extern "C" int func_001454F8(void* iface, int a1);
extern "C" int func_001474C8(void* iface, int player);

struct sGM_239D88 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_239D88 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00239D88(void* self)
{
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    sGM_239D88* gm = (sGM_239D88*)D_004A2C70;
    gm->f80 = 0;
    gm->f84 = 0;
    gm->f94 = 0;
    gm->f90 = 0;
    gm->f9C = 0;
    gm->f10 = 0;
    gm->f14 = 0;
    gm->f98 = 1;
    gm->f68 = -1;
    gm->f6C = -1;
    gm->f0 = 3;
    gm->f70 = 3;
    gm->f74 = 3;
    gm->f88 = 1;
    int t = func_001454F8(race, 3);
    sGM_239D88* gm2 = (sGM_239D88*)D_004A2C70;
    gm2->f7C = 0;
    gm2->f8C = 0;
    gm2->f78 = t * 60;
    func_00416210(gm2->a18, -1, 0x28);
    sVEntry_239D88* e = &(*(sVEntry_239D88**)self)[4];
    e->fn((char*)self + e->delta);
    ((sGM_239D88*)D_004A2C70)->a18[0] = cBENewPlayerInterface_getPlayerCharID(player, 0);
    ((sGM_239D88*)D_004A2C70)->a18[1] = cBENewPlayerInterface_getPlayerCharID(player, 1);
    ((sGM_239D88*)D_004A2C70)->a40[0] = func_001474C8(player, 0);
    ((sGM_239D88*)D_004A2C70)->a40[1] = func_001474C8(player, 1);
    *(short*)((char*)self + 0x4) = 0;
    *(short*)((char*)self + 0x6) = 0;
}
#endif

INCLUDE_ASM("main/gamemode", func_00239EC8);

//100%
INCLUDE_ASM("main/gamemode", func_0023A070);
#ifdef SKIP_ASM
extern char* D_004A2C70;
extern void* D_004A28A8;

extern "C" int func_0023A070(char* self, int player, int secs)
{
    short* score = (short*)(self + 4);
    short* mine = (short*)((char*)score + (player << 1));
    short s = ++*mine;
    int other = 0;
    if (player == 0) {
        other = 1;
    }
    if (*(short*)((char*)score + (other << 1)) >= s) {
        return 0;
    }
    char* m = D_004A2C70;
    if (*(int*)(m + 8) == 1) {
        unsigned int t = *(unsigned int*)(m + 0x78);
        if (t < *(unsigned int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 8)) {
            return 0;
        }
        *(unsigned int*)(m + 0x78) = secs * 60 + t;
        return 1;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023A108);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" int func_00145750(void* iface);
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void func_0023A4F0(void* self);
extern "C" void func_0023A668(void* self);
extern char* D_004A2C70;
extern signed char D_00535C11[];
extern unsigned int D_00536640[];
extern int D_00536730[];
extern int D_00536708[];

struct sGM_23A108 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23A108 {
    short delta;
    short index;
    void (*fn)(void*);
};

class cGameModeBase_23A108 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

struct sMode_23A108 : public cGameModeBase_23A108 {
    int f4;                     // 0x04
    int f8;                     // 0x08
    int fC;                     // 0x0C
    char pad10[0x18];           // 0x10
    int charA;                  // 0x28
    int othersA[5];             // 0x2C
    int charB;                  // 0x40
    int charC;                  // 0x44
    int othersB[4];             // 0x48
    int tbl[3][10];             // 0x58
};

static inline void fillOthers_23A108(int* dst, int p)
{
    for (int i = 0; i < 3; i++) {
        int v = D_00536708[i];
        if (v != p) {
            sGM_23A108* gm = (sGM_23A108*)D_004A2C70;
            int x = gm->a40[v];
            if (x == 0) {
                *dst = gm->a18[v];
            } else {
                *dst = x;
            }
            dst++;
        }
    }
}

extern "C" void func_0023A108(sMode_23A108* self)
{
    sGM_23A108* g0 = (sGM_23A108*)D_004A2C70;
    g0->f9C = 0;
    g0->f0 = g0->f70;
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    int quick = D_00535C11[0];
    if (quick != 0 && ((sGM_23A108*)D_004A2C70)->f0 != 3) {
        ((sGM_23A108*)D_004A2C70)->f0 = 3;
        self->fC = 0;
    }
    sGM_23A108* gm = (sGM_23A108*)D_004A2C70;
    int state = gm->f0;
    gm->f7C = 0;
    gm->f8C = 0;
    switch (state) {
    case 0:
    case 1:
        gm->f98 = 0;
        gm->f0 = 1;
        gm->f14 = 0;
        gm->f10 = 5;
        if (gm->f84 == 1) {
            func_0023A4F0(self);
            func_0023A668(self);
        }
        func_00416210(self->tbl, 9, 0x78);
        self->v05();
        {
            sGM_23A108* g = (sGM_23A108*)D_004A2C70;
            g->f6C = -1;
            g->f70 = 1;
            g->f74 = 1;
            g->f78 = 0;
            g->f80 = 0;
            g->f84 = 0;
            g->f88 = 0;
            g->f90 = 1;
            g->f94 = 0;
        }
        self->f8 = 0;
        self->fC = 0;
        break;
    case 2:
        gm->f98 = 0;
        gm->f10 = 5;
        gm->f14 = 0;
        if (self->f8 == 0) {
            int p = func_00146E98(player, 0);
            self->charA = cBENewPlayerInterface_getRiderCharID(player, p);
            fillOthers_23A108(self->othersA, p);
            func_0023A668(self);
        }
        {
            sGM_23A108* g = (sGM_23A108*)D_004A2C70;
            g->f6C = -1;
            g->f70 = 2;
            g->f74 = 2;
        }
        func_00416210(D_00536640, 9, 0x28);
        func_00416210(D_00536730, 0, 0x28);
        func_00416210(self->tbl[1], 9, 0x28);
        {
            sGM_23A108* g = (sGM_23A108*)D_004A2C70;
            g->f78 = 0;
            g->f80 = 0;
            g->f84 = 0;
            g->f88 = 0;
            g->f90 = 0;
            g->f94 = 0;
        }
        self->f8 = 1;
        self->fC = 0;
        break;
    case 3:
        gm->f10 = 5;
        gm->f14 = 0;
        gm->f98 = 1;
        if (self->fC == 0) {
            if (quick != 0) {
                func_0023A4F0(self);
                ((sGM_23A108*)D_004A2C70)->f0 = 1;
                func_0023A668(self);
                ((sGM_23A108*)D_004A2C70)->f0 = state;
                func_00416210(self->tbl, 9, 0x78);
                self->v05();
            } else {
                int p = func_00146E98(player, 0);
                self->charB = cBENewPlayerInterface_getRiderCharID(player, p);
                self->charC = func_00145750(race);
                fillOthers_23A108(self->othersB, p);
                func_0023A668(self);
            }
        }
        {
            sGM_23A108* g = (sGM_23A108*)D_004A2C70;
            g->f6C = -1;
            g->f70 = 3;
            g->f74 = 3;
        }
        func_00416210(D_00536640, 9, 0x28);
        func_00416210(D_00536730, 9, 0x28);
        func_00416210(self->tbl[2], 9, 0x28);
        {
            sGM_23A108* g = (sGM_23A108*)D_004A2C70;
            g->f78 = 0;
            g->f80 = 0;
            g->f84 = 0;
            g->f88 = 0;
            g->f90 = 0;
            g->f94 = 0;
        }
        self->fC = 1;
        self->f8 = 0;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023A4F0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" int func_00145750(void* iface);
extern "C" unsigned int func_00237CD8(void);
extern "C" void func_0023C770(int* arr, unsigned int n);

extern "C" void func_0023A4F0(void* self)
{
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    int charA = cBENewPlayerInterface_getRiderCharID(player, func_00146E98(player, 0));
    int charB = func_00145750(race);
    int arr[10];
    arr[0] = func_00237CD8() % 7 + 10;
    unsigned int t = func_00237CD8() % 6;
    arr[1] = t + 10;
    if (arr[1] >= arr[0]) {
        arr[1] = t + 11;
    }
    int n = 0;
    for (int i = 0; i < 10; i++) {
        if (i != charA && i != charB) {
            arr[n + 2] = i;
            n++;
        }
        if (n + 2 >= 10) {
            break;
        }
    }
    func_0023C770(arr, 10);
    *(int*)((char*)self + 0x10) = charA;
    *(int*)((char*)self + 0x14) = arr[0];
    *(int*)((char*)self + 0x18) = arr[1];
    *(int*)((char*)self + 0x1C) = arr[2];
    *(int*)((char*)self + 0x20) = arr[3];
    *(int*)((char*)self + 0x24) = arr[4];
    *(int*)((char*)self + 0x34) = arr[5];
    *(int*)((char*)self + 0x38) = arr[6];
    *(int*)((char*)self + 0x3C) = arr[7];
    *(int*)((char*)self + 0x50) = arr[8];
    *(int*)((char*)self + 0x54) = arr[9];
}
#endif

INCLUDE_ASM("main/gamemode", func_0023A668);

INCLUDE_ASM("main/gamemode", func_0023A760);

//100%
INCLUDE_ASM("main/gamemode", func_0023AC10__FPv);
#ifdef SKIP_ASM
void func_0023AC10(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023AC18);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
extern "C" void func_0023AC18(void* self, cGameModeStream* s)
{
    s->v01(self, 0xD0);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023AC50);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
extern "C" void func_0023AC50(void* self, cGameModeStream* s)
{
    s->v02(self, 0xD0);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023AC88);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getPlayerCharID(void* iface, int player);
extern "C" int func_001474C8(void* iface, int player);
extern "C" void func_0023B0A8(void* self);
extern void* D_004A28A8;
extern int D_00534B30[];
extern int D_00535C04[];

struct sGM_23AC88 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23AC88 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023AC88(void* self)
{
    int one = 1;
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    sGM_23AC88* gm = (sGM_23AC88*)D_004A2C70;
    gm->fC = 2;
    gm->f94 = 0;
    gm->f90 = 0;
    gm->f9C = 0;
    gm->f98 = one;
    gm->f88 = 0;
    gm->f8 = 0;
    gm->f0 = 3;
    gm->f70 = 3;
    gm->f74 = 3;
    gm->f6C = -1;
    gm->f10 = 4;
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0) {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        ((sGM_23AC88*)D_004A2C70)->f10 = D_00535C04[0];
    }
    sGM_23AC88* gm2 = (sGM_23AC88*)D_004A2C70;
    gm2->f14 = 0;
    gm2->f80 = 0;
    gm2->f78 = 0;
    gm2->f7C = 0;
    gm2->f8C = 0;
    func_00416210((char*)self + 4, 9, 0x28);
    sVEntry_23AC88* e = &(*(sVEntry_23AC88**)self)[5];
    e->fn((char*)self + e->delta);
    ((sGM_23AC88*)D_004A2C70)->a18[0] = cBENewPlayerInterface_getPlayerCharID(player, 0);
    ((sGM_23AC88*)D_004A2C70)->a18[1] = cBENewPlayerInterface_getPlayerCharID(player, 1);
    ((sGM_23AC88*)D_004A2C70)->a40[0] = func_001474C8(player, 0);
    ((sGM_23AC88*)D_004A2C70)->a40[1] = func_001474C8(player, 1);
    if (((sGM_23AC88*)D_004A2C70)->f84 == one) {
        func_0023B0A8(self);
    }
    ((sGM_23AC88*)D_004A2C70)->f84 = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023AE00);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern char* D_004A2C70;
extern unsigned int D_00536640[];
extern int D_005366A8[];
extern int D_00536730[];
extern "C" int func_0012A250(void* race);
extern "C" int func_00122D78(void* self);
extern "C" void func_00238BF8(void* self, int n);

struct sVEnt_23AE00 { short delta; short index; int (*fn)(void*); };

struct sRider_23AE00 {
    char pad000[0x100];
    int f100;
    char pad104[0x36C];
    float f470;
    int pad474;
    int f478;
    int pad47C;
    int f480;
    char pad484[0x23C];
    sVEnt_23AE00* subvt;
};

struct sRace_23AE00 {
    char pad00[0x28];
    sRider_23AE00* riders[8];
};

struct sSelf_23AE00 {
    int f0;
    int times[8];
};

static inline sRace_23AE00* race_23AE00()
{
    return *(sRace_23AE00**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
}

static inline int subActive_23AE00(char* obj)
{
    sVEnt_23AE00* vt = *(sVEnt_23AE00**)obj;
    return vt[9].fn(obj + vt[9].delta);
}

static inline int finished_23AE00(sRider_23AE00* r)
{
    return r->f470 >= 0.0f;
}

extern "C" void func_0023AE00(sSelf_23AE00* self, int idx)
{
    sRace_23AE00* rc = race_23AE00();
    if (func_0012A250(rc) == 0 || subActive_23AE00((char*)rc->riders[idx] + 0x6C0) == 0) {
        if (race_23AE00()->riders[idx]->f480) {
            D_00536640[idx] = self->times[idx] = 360000;
            D_005366A8[idx] = 1;
        } else {
            int v = rc->riders[idx]->f478;
            self->times[idx] = v;
            D_00536640[idx] = v;
            D_005366A8[idx] = 0;
        }
    }
    if (func_0012A250(rc)) {
        for (int i = 0; i < *(int*)(D_004A2C70 + 0x10) + 2; i++) {
            if (!finished_23AE00(rc->riders[i]) && i != idx) {
                self->times[i] = func_00122D78(rc->riders[i]);
            }
            D_00536640[i] = self->times[i];
        }
        func_00238BF8(D_004A2C70, 10);
        if (D_00536730[idx] >= 3) {
            race_23AE00()->riders[idx]->f100 = 0;
        }
        *(int*)(D_004A2C70 + 0x9C) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023B038);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
extern "C" void func_0023B038(void* self, cGameModeStream* s)
{
    s->v01(self, 0x2C);
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023B070);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
extern "C" void func_0023B070(void* self, cGameModeStream* s)
{
    s->v02(self, 0x2C);
}
#endif

INCLUDE_ASM("main/gamemode", func_0023B0A8);

//100%
INCLUDE_ASM("main/gamemode", func_0023B170);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);

struct sGM_23B170 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23B170 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023B170(void* self)
{
    int one = 1;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    sGM_23B170* gm = (sGM_23B170*)D_004A2C70;
    gm->f0 = one;
    gm->f98 = one;
    gm->f10 = 0;
    gm->f14 = 0;
    func_00416210(gm->a18, -1, 0x28);
    int p = func_00146E98(iface, 0);
    ((sGM_23B170*)D_004A2C70)->a18[p] = cBENewPlayerInterface_getRiderCharID(iface, func_00146E98(iface, 0));
    sVEntry_23B170* e = &(*(sVEntry_23B170**)self)[4];
    e->fn((char*)self + e->delta);
    sGM_23B170* gm2 = (sGM_23B170*)D_004A2C70;
    gm2->f70 = one;
    gm2->f74 = one;
    gm2->f9C = one;
    gm2->f78 = 0;
    gm2->f7C = 0;
    gm2->f80 = 0;
    gm2->f84 = 0;
    gm2->f88 = 0;
    gm2->f8C = 0;
    gm2->f90 = 0;
    gm2->f94 = 0;
    gm2->f6C = -1;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023B268);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" int func_001455D0(void* iface, int mode, int a2);
extern "C" int func_001558F8(void* iface, int a1, int a2, int a3);
extern "C" void* func_00416210(void* dst, int c, int n);
extern char* D_004A2C70;
extern signed char D_00535C12[];

struct sGM_23B268 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23B268 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sMode_23B268 {
    sVEntry_23B268* vt;
    int f4;
    short f8;
    short fA;
};

extern "C" void func_0023B268(void* self)
{
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* score = cBE_getInterface_Fv(cBE_getBE(), 8);
    sGM_23B268* gm = (sGM_23B268*)D_004A2C70;
    gm->f0 = 1;
    int mode = D_00535C12[0];
    gm->f10 = 0;
    gm->f8 = mode;
    gm->f14 = 0;
    gm->f8C = 0;
    switch (mode) {
    case 6:
        gm->f6C = 0;
        gm->f68 = 14;
        break;
    case 7:
        gm->f68 = 15;
        gm->f6C = 3;
        break;
    case 8:
        gm->f68 = 16;
        gm->f6C = 4;
        break;
    }
    int r = func_001558F8(score, 0, ((sGM_23B268*)D_004A2C70)->f68, ((sGM_23B268*)D_004A2C70)->f8);
    *(short*)((char*)self + 0xA) = 0;
    if (r == 1 || r == 2) {
        *(short*)((char*)self + 0xA) = 2;
    } else if (r == 3) {
        *(short*)((char*)self + 0xA) = 1;
    }
    int t = func_001455D0(race, ((sGM_23B268*)D_004A2C70)->f8, *(short*)((char*)self + 0xA));
    sGM_23B268* gm2 = (sGM_23B268*)D_004A2C70;
    *(int*)((char*)self + 4) = t * 60;
    gm2->f88 = 1;
    gm2->f78 = *(int*)((char*)self + 4);
    gm2->f7C = *(int*)((char*)self + 4);
    gm2->f70 = 2;
    gm2->f74 = 2;
    sVEntry_23B268* vt = *(sVEntry_23B268**)self;
    vt[5].fn((char*)self + vt[5].delta);
    func_00416210(((sGM_23B268*)D_004A2C70)->a18, -1, 0x28);
    int p = func_00146E98(player, 0);
    ((sGM_23B268*)D_004A2C70)->a18[p] = cBENewPlayerInterface_getRiderCharID(player, func_00146E98(player, 0));
    sGM_23B268* gm3 = (sGM_23B268*)D_004A2C70;
    gm3->f80 = 0;
    gm3->f84 = 0;
    gm3->f90 = 0;
    gm3->f94 = 0;
    gm3->f98 = 0;
    gm3->f9C = 0;
    *(short*)((char*)self + 8) = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023B468);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_001455D0(void* iface, int mode, int a2);
extern void* D_004A28A8;
extern int D_00536730[];
extern unsigned int D_00536640[];
extern int D_005366A8[];

struct sGM_23B468 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

static inline char* rider_23B468(char* g, int off)
{
    return *(char**)(*(char**)(*(char**)(g + 0x84) + 0xC) + off + 0x28);
}

extern "C" void func_0023B468(void* self, int p)
{
    int one = 1;
    int off = p << 2;
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    char* g = (char*)D_004A28A8;
    sGM_23B468* gm = (sGM_23B468*)D_004A2C70;
    unsigned int* t = &D_00536640[p];
    *t = *(unsigned int*)(rider_23B468(g, off) + 0x478);
    gm->f9C = one;
    char* r = rider_23B468(g, off);
    if (*(int*)(r + 0x480) != 0) {
        *t = 0x57E40;
        *(int*)(rider_23B468(g, off) + 0x100) = 0;
        gm->f70 = one;
        D_005366A8[p] = one;
    } else if (*(unsigned int*)((char*)self + 4) < *t) {
        *(int*)(r + 0x100) = 0;
        gm->f70 = one;
        D_005366A8[p] = 0;
    } else {
        *(int*)(r + 0x100) = one;
        gm->f84 = one;
        unsigned int a = func_001455D0(race, gm->f8, 2) * 60;
        unsigned int b = func_001455D0(race, ((sGM_23B468*)D_004A2C70)->f8, 1) * 60;
        if (a >= *t) {
            D_00536730[p] = 0;
        } else if (b >= *t) {
            D_00536730[p] = one;
        } else {
            D_00536730[p] = 2;
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023B5F8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144BE0(void* iface);
extern "C" int func_00145668(void* iface, int a1, int a2, int a3);
extern "C" float func_001195A8(void* self, int value);
extern signed char D_00535C12[];

extern "C" int func_0023B5F8(void* self)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    int state = func_00144BE0(iface);
    int ok = 0;
    int t = state >= 17;
    if (t) {
        ok = state;
        ok = ok < 22;
    }
    if (ok) {
        int d = func_00145668(iface, D_00535C12[0], *(short*)((char*)self + 0xA), *(unsigned short*)((char*)self + 8));
        void* clk = *(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
        int secs = (int)((float)*(int*)((char*)clk + 0xC) * 0.01666666753590107f);
        if (d != 0) {
            func_001195A8(*(void**)(*(char**)((char*)clk + 0x28) + 0x790), secs - d);
        }
        (*(unsigned short*)((char*)self + 8))++;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023B6C0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" int func_00145750(void* iface);
extern "C" int func_00147410(void* iface, int player);
extern "C" void* func_00416210(void* dst, int c, int n);
extern char* D_004A2C70;
extern signed char D_00535C11[];

struct sGM_23B6C0 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23B6C0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023B6C0(void* self)
{
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    int one = 1;
    sGM_23B6C0* gm = (sGM_23B6C0*)D_004A2C70;
    gm->f0 = one;
    gm->f10 = one;
    gm->f14 = 0;
    gm->f68 = -1;
    gm->f70 = one;
    gm->f74 = one;
    gm->f78 = 0;
    gm->f7C = 0;
    gm->f80 = 0;
    gm->f84 = 0;
    gm->f88 = 0;
    gm->f8C = 0;
    gm->f90 = 0;
    gm->f94 = 0;
    gm->f6C = -1;
    gm->f98 = one;
    gm->f9C = 0;
    sVEntry_23B6C0* vt = *(sVEntry_23B6C0**)self;
    vt[5].fn((char*)self + vt[5].delta);
    if (D_00535C11[0] == 2) {
        ((sGM_23B6C0*)D_004A2C70)->f10 = 0;
        int p0 = func_00146E98(player, 0);
        int p1 = func_00146E98(player, 1);
        ((sGM_23B6C0*)D_004A2C70)->a18[p0] = cBENewPlayerInterface_getRiderCharID(player, p0);
        ((sGM_23B6C0*)D_004A2C70)->a40[p0] = func_00147410(player, p0);
        ((sGM_23B6C0*)D_004A2C70)->a18[p1] = cBENewPlayerInterface_getRiderCharID(player, p1);
        ((sGM_23B6C0*)D_004A2C70)->a40[p1] = func_00147410(player, p1);
    } else {
        func_00416210(((sGM_23B6C0*)D_004A2C70)->a18, -1, 0x28);
        int p = func_00146E98(player, 0);
        ((sGM_23B6C0*)D_004A2C70)->a18[p] = cBENewPlayerInterface_getRiderCharID(player, func_00146E98(player, 0));
        ((sGM_23B6C0*)D_004A2C70)->a18[func_00146E98(player, 0) + 1] = func_00145750(race);
        ((sGM_23B6C0*)D_004A2C70)->a40[func_00146E98(player, 0) + 1] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023B8C8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_00122D78(void* self);
extern "C" int func_0012A250(void* race);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_00238BF8(void* self, int n);
extern char* D_004A2C70;
extern void* D_004A28A8;
extern unsigned int D_00536640[];
extern int D_005366A8[];
extern int D_00536730[];
extern signed char D_00535C11[];

struct sGM_23B8C8 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

class cRiderState_23B8C8 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int isActive();
    virtual int isFinished();
};

struct sClk_23B8C8 {
    char pad_0x0[0x28];
    char* riders[1];    // 0x28
};

static inline char* Rider_23B8C8(int i)
{
    return (*(sClk_23B8C8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC))->riders[i];
}

extern "C" void func_0023B8C8(void* self, int idx)
{
    if (func_0012A250(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC)) == 0 ||
        ((cRiderState_23B8C8*)(Rider_23B8C8(idx) + 0x6C0))->isFinished() == 0) {
        char* r = Rider_23B8C8(idx);
        if (*(int*)(r + 0x480) != 0) {
            D_00536640[idx] = 0x57E40;
            D_005366A8[idx] = 1;
        } else {
            D_00536640[idx] = *(int*)(r + 0x478);
            D_005366A8[idx] = 0;
        }
    }
    if (func_0012A250(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC)) == 0) {
        return;
    }
    if (((cRiderState_23B8C8*)(Rider_23B8C8(idx) + 0x6C0))->isActive() == 0) {
        return;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        func_00238BF8(D_004A2C70, 10);
        ((sGM_23B8C8*)D_004A2C70)->f9C = 1;
        int w = 1;
        if (D_00536640[0] < D_00536640[1]) {
            w = 0;
        }
        if (idx == w) {
            return;
        }
    } else {
        for (int i = 0; i < ((sGM_23B8C8*)D_004A2C70)->f10 + 1; i++) {
            char* r = Rider_23B8C8(i);
            int done = *(float*)(r + 0x470) >= 0.0f;
            if (!done) {
                D_00536640[i] = func_00122D78(r);
            }
        }
        void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
        int n = func_00146E98(player, 0);
        sGM_23B8C8* gm = (sGM_23B8C8*)D_004A2C70;
        gm->f9C = 1;
        func_00238BF8(gm, 10);
        if (D_00536730[n] == 0 && *(int*)(Rider_23B8C8(idx) + 0x480) == 0) {
            *(int*)(Rider_23B8C8(idx) + 0x100) = 1;
            sGM_23B8C8* gm2 = (sGM_23B8C8*)D_004A2C70;
            gm2->f84 = 1;
            gm2->f74 = gm2->f70;
            gm2->f70 = 0;
            return;
        }
    }
    *(int*)(Rider_23B8C8(idx) + 0x100) = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023BB98);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" int func_00145750(void* iface);
extern "C" int func_00147410(void* iface, int player);
extern "C" int func_001454F8(void* iface, int a1);
extern "C" void* func_00416210(void* dst, int c, int n);
extern char* D_004A2C70;
extern signed char D_00535C11[];

struct sGM_23BB98 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23BB98 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023BB98(void* self)
{
    int one = 1;
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    sGM_23BB98* gm = (sGM_23BB98*)D_004A2C70;
    gm->f68 = -1;
    gm->f74 = one;
    gm->f0 = one;
    gm->f10 = one;
    gm->f14 = 0;
    gm->f70 = one;
    gm->f6C = -1;
    int t = func_001454F8(race, 1);
    sGM_23BB98* gm2 = (sGM_23BB98*)D_004A2C70;
    gm2->f9C = 0;
    gm2->f7C = 0;
    gm2->f78 = t * 60;
    gm2->f80 = 0;
    gm2->f84 = 0;
    gm2->f88 = one;
    gm2->f8C = 0;
    gm2->f90 = 0;
    gm2->f94 = 0;
    gm2->f98 = one;
    sVEntry_23BB98* vt = *(sVEntry_23BB98**)self;
    vt[4].fn((char*)self + vt[4].delta);
    if (D_00535C11[0] == 2) {
        ((sGM_23BB98*)D_004A2C70)->f10 = 0;
        int p0 = func_00146E98(player, 0);
        int p1 = func_00146E98(player, 1);
        ((sGM_23BB98*)D_004A2C70)->a18[p0] = cBENewPlayerInterface_getRiderCharID(player, p0);
        ((sGM_23BB98*)D_004A2C70)->a40[p0] = func_00147410(player, p0);
        ((sGM_23BB98*)D_004A2C70)->a18[p1] = cBENewPlayerInterface_getRiderCharID(player, p1);
        ((sGM_23BB98*)D_004A2C70)->a40[p1] = func_00147410(player, p1);
    } else {
        func_00416210(((sGM_23BB98*)D_004A2C70)->a18, -1, 0x28);
        int p = func_00146E98(player, 0);
        ((sGM_23BB98*)D_004A2C70)->a18[p] = cBENewPlayerInterface_getRiderCharID(player, func_00146E98(player, 0));
        ((sGM_23BB98*)D_004A2C70)->a18[func_00146E98(player, 0) + 1] = func_00145750(race);
        ((sGM_23BB98*)D_004A2C70)->a40[func_00146E98(player, 0) + 1] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023BDB8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_00122E50(void* self);
extern "C" int func_0012A250(void* race);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_00238B70(void* self, int n);
extern char* D_004A2C70;
extern void* D_004A28A8;
extern unsigned int D_00536640[];
extern int D_005366A8[];
extern int D_00536730[];
extern signed char D_00535C11[];

struct sGM_23BDB8 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sStats_23BDB8 {
    int v[0x9C / 4];
    int time;           // 0x9C
    int w[3];
};

struct sClk_23BDB8 {
    char pad_0x0[0x28];
    char* riders[1];    // 0x28
};

static inline char* Rider_23BDB8(int i)
{
    return (*(sClk_23BDB8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC))->riders[i];
}

extern "C" void func_0023BDB8(void* self, int idx)
{
    char* r = Rider_23BDB8(idx);
    if (*(int*)(r + 0x480) != 0) {
        D_00536640[idx] = 0;
        D_005366A8[idx] = 1;
    } else {
        sStats_23BDB8 st = *(sStats_23BDB8*)(*(char**)(r + 0x790) + 0xFC);
        D_005366A8[idx] = 0;
        D_00536640[idx] = st.time;
    }
    if (func_0012A250(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC)) == 0) {
        return;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        func_00238B70(D_004A2C70, 2);
        ((sGM_23BDB8*)D_004A2C70)->f9C = 1;
        int w = 1;
        if (D_00536640[0] > D_00536640[1]) {
            w = 0;
        }
        if (idx == w) {
            return;
        }
        *(int*)(Rider_23BDB8(idx) + 0x100) = 0;
    } else {
        for (int i = 0; i < ((sGM_23BDB8*)D_004A2C70)->f10 + 1; i++) {
            char* r = Rider_23BDB8(i);
            int done = *(float*)(r + 0x470) >= 0.0f;
            if (!done) {
                D_00536640[i] = func_00122E50(r);
            }
        }
        void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
        int n = func_00146E98(player, 0);
        sGM_23BDB8* gm = (sGM_23BDB8*)D_004A2C70;
        gm->f9C = 1;
        func_00238B70(gm, 2);
        if (D_00536730[n] == 0 && *(int*)(Rider_23BDB8(idx) + 0x480) == 0) {
            *(int*)(Rider_23BDB8(idx) + 0x100) = 1;
            sGM_23BDB8* gm2 = (sGM_23BDB8*)D_004A2C70;
            gm2->f84 = 1;
            gm2->f74 = gm2->f70;
            gm2->f70 = 0;
            return;
        }
        *(int*)(Rider_23BDB8(idx) + 0x100) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023C0D0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" int func_001455D0(void* iface, int mode, int a2);
extern "C" int func_00145600(void* iface, int mode, int a2);
extern "C" int func_001558F8(void* iface, int a1, int a2, int a3);
extern "C" void* func_00416210(void* dst, int c, int n);
extern char* D_004A2C70;
extern signed char D_00535C12[];

struct sGM_23C0D0 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23C0D0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023C0D0(void* self)
{
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* score = cBE_getInterface_Fv(cBE_getBE(), 8);
    sGM_23C0D0* gm = (sGM_23C0D0*)D_004A2C70;
    gm->f0 = 1;
    int mode = D_00535C12[0];
    gm->f10 = 0;
    gm->f8 = mode;
    gm->f14 = 0;
    switch (mode) {
    case 9:
        gm->f68 = 14;
        gm->f6C = 5;
        break;
    case 10:
        gm->f68 = 15;
        gm->f6C = 6;
        break;
    case 11:
        gm->f68 = 16;
        gm->f6C = 4;
        break;
    }
    unsigned int r = (unsigned int)func_001558F8(score, 0, ((sGM_23C0D0*)D_004A2C70)->f68, ((sGM_23C0D0*)D_004A2C70)->f8);
    *(short*)((char*)self + 0xA) = 0;
    if (r < 3) {
        *(short*)((char*)self + 0xA) = 2;
    } else if (r == 3) {
        *(short*)((char*)self + 0xA) = 1;
    }
    int t = func_001455D0(race, ((sGM_23C0D0*)D_004A2C70)->f8, *(short*)((char*)self + 0xA)) * 100;
    sGM_23C0D0* gm2 = (sGM_23C0D0*)D_004A2C70;
    *(int*)((char*)self + 4) = t;
    gm2->f7C = t;
    int u = func_00145600(race, gm2->f8, *(short*)((char*)self + 0xA));
    sGM_23C0D0* gm3 = (sGM_23C0D0*)D_004A2C70;
    gm3->f70 = 2;
    gm3->f74 = 2;
    gm3->f78 = u * 60;
    sVEntry_23C0D0* vt = *(sVEntry_23C0D0**)self;
    vt[4].fn((char*)self + vt[4].delta);
    func_00416210(((sGM_23C0D0*)D_004A2C70)->a18, -1, 0x28);
    int p = func_00146E98(player, 0);
    ((sGM_23C0D0*)D_004A2C70)->a18[p] = cBENewPlayerInterface_getRiderCharID(player, func_00146E98(player, 0));
    sGM_23C0D0* gm4 = (sGM_23C0D0*)D_004A2C70;
    gm4->f80 = 0;
    gm4->f84 = 0;
    gm4->f88 = 1;
    gm4->f8C = 1;
    gm4->f90 = 0;
    gm4->f94 = 0;
    gm4->f98 = 0;
    gm4->f9C = 0;
    *(short*)((char*)self + 8) = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023C2D8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_001455D0(void* iface, int mode, int a2);
extern char* D_004A2C70;
extern void* D_004A28A8;
extern unsigned int D_00536640[];
extern int D_005366A8[];
extern int D_00536730[];

struct sGM_23C2D8 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sStats_23C2D8 {
    int v[0x9C / 4];
    int time;           // 0x9C
    int w[3];
};

struct sClk_23C2D8 {
    char pad_0x0[0x28];
    char* riders[1];    // 0x28
};

extern "C" void func_0023C2D8(void* self, int idx)
{
    sClk_23C2D8* clk = *(sClk_23C2D8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    sStats_23C2D8 st = *(sStats_23C2D8*)(*(char**)(clk->riders[idx] + 0x790) + 0xFC);
    void* race = cBE_getInterface_Fv(cBE_getBE(), 0);
    char* r = (*(sClk_23C2D8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC))->riders[idx];
    if (*(int*)(r + 0x480) != 0) {
        D_00536640[idx] = 0;
        ((sGM_23C2D8*)D_004A2C70)->f70 = 1;
        *(int*)((*(sClk_23C2D8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC))->riders[idx] + 0x100) = 0;
        D_005366A8[idx] = 1;
    } else {
        sGM_23C2D8* gm = (sGM_23C2D8*)D_004A2C70;
        if (st.time < gm->f7C) {
            *(int*)(r + 0x100) = 0;
            D_00536640[idx] = st.time;
            gm->f70 = 1;
            D_005366A8[idx] = 0;
        } else {
            int a = func_001455D0(race, gm->f8, 2) * 100;
            int b = func_001455D0(race, ((sGM_23C2D8*)D_004A2C70)->f8, 1) * 100;
            sGM_23C2D8* gm2 = (sGM_23C2D8*)D_004A2C70;
            *(int*)((*(sClk_23C2D8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC))->riders[idx] + 0x100) = 1;
            D_00536640[idx] = st.time;
            gm2->f84 = 1;
            if (st.time >= a) {
                D_00536730[idx] = 0;
            } else if (st.time >= b) {
                D_00536730[idx] = 1;
            } else {
                D_00536730[idx] = 2;
            }
        }
    }
    ((sGM_23C2D8*)D_004A2C70)->f9C = 1;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023C560);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144BE0(void* iface);
extern "C" int func_00145668(void* iface, int a1, int a2, int a3);
extern "C" float func_001195D8(void* self, int value);
extern signed char D_00535C12[];

extern "C" int func_0023C560(void* self)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    int state = func_00144BE0(iface);
    int ok = 0;
    int t = state >= 17;
    if (t) {
        ok = state;
        ok = ok < 22;
    }
    if (ok) {
        int d = func_00145668(iface, D_00535C12[0], *(short*)((char*)self + 0xA), *(unsigned short*)((char*)self + 8)) * 100;
        void* m = *(void**)(*(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x28) + 0x790);
        int v = *(int*)((char*)m + 0x198);
        if (d != 0) {
            func_001195D8(m, v - d);
        }
        (*(unsigned short*)((char*)self + 8))++;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023C618);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getRiderCharID(void* iface, int player);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void func_0023C770(int* arr, unsigned int n);
extern int D_00535C04[];

struct sGM_23C618 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int a18[10];
    int a40[10];
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
};

struct sVEntry_23C618 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023C618(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* player = cBE_getInterface_Fv(cBE_getBE(), 1);
    sGM_23C618* gm = (sGM_23C618*)D_004A2C70;
    gm->f0 = 1;
    gm->f98 = 1;
    gm->f10 = D_00535C04[0];
    gm->f14 = 0;
    int p = func_00146E98(player, 0);
    int ch = cBENewPlayerInterface_getRiderCharID(player, p);
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    func_0023C770(arr, 10);
    int j = 0;
    int* src = arr;
    for (; j < 10; j++) {
        if (j != p) {
            int v = *src;
            if (v == ch) {
                src++;
                v = *src;
            }
            ((sGM_23C618*)D_004A2C70)->a18[j] = v;
            src++;
        } else {
            ((sGM_23C618*)D_004A2C70)->a18[j] = ch;
        }
    }
    sVEntry_23C618* e = &(*(sVEntry_23C618**)self)[4];
    e->fn((char*)self + e->delta);
    sGM_23C618* gm2 = (sGM_23C618*)D_004A2C70;
    gm2->f70 = 1;
    gm2->f78 = 0;
    gm2->f7C = 0;
    gm2->f80 = 0;
    gm2->f84 = 0;
    gm2->f88 = 0;
    gm2->f8C = 0;
    gm2->f90 = 0;
    gm2->f6C = -1;
    gm2->f74 = 1;
    gm2->f94 = 0;
}
#endif

//100%
INCLUDE_ASM("main/gamemode", func_0023C770);
#ifdef SKIP_ASM
extern "C" unsigned int func_00237CD8(void);

extern "C" void func_0023C770(int* arr, unsigned int n)
{
    int i;
    for (i = 0; i < 25; i++) {
        unsigned int a = func_00237CD8() % n;
        unsigned int b = func_00237CD8() % n;
        int t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }
}
#endif

