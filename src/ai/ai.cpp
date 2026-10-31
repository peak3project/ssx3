#include "common.h"
#include "ai/rider.h"

//100%
INCLUDE_ASM("ai/ai", cAI_cAI);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is the game's tagged operator new(size, tag, flags, d); bound by asm label.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_004585A0[];
extern char D_00458550[];
extern char D_004585C8[];
extern char D_00458578[];
extern char D_00458488[];
extern char D_00458528[];
extern char D_00458500[];
extern char D_004584D8[];
extern char D_00457F00[];
extern char D_00457F10[];

struct sAIEntry_1286A0 {
    char pad[0x20];
    sAIEntry_1286A0() {}
};

struct sAIState_1286A0 {
    int f0;                     // 0x00
    char pad4[0xC];
    sAIEntry_1286A0 e[6];       // 0x10
    int d0;                     // 0xD0
    int d4;                     // 0xD4
    int d8;                     // 0xD8
    char padDC[0x8E0 - 0xDC];
    sAIState_1286A0() : f0(0) { d0 = -1; d4 = 1; d8 = 0; }
};

struct sAIObj_1286A0 {
    char pad[0xB60];
    sAIObj_1286A0(void* owner) __asm__("func_00101310");
};

extern "C" void* cAI_cAI(void* self)
{
    *(void**)((char*)self + 0xCC) = D_00458488;
    *(void**)((char*)self + 0xAC) = D_004585C8;
    *(void**)((char*)self + 0xB0) = D_004585A0;
    *(void**)((char*)self + 0xB4) = D_00458550;
    *(void**)((char*)self + 0xBC) = D_00458578;
    *(void**)((char*)self + 0xC0) = D_00458528;
    *(void**)((char*)self + 0xC4) = D_00458500;
    *(void**)((char*)self + 0xC8) = D_004584D8;
    sAIState_1286A0** slot = (sAIState_1286A0**)((char*)self + 0xA4);
    *slot = new (D_00457F00, 0, 0) sAIState_1286A0;
    *(sAIObj_1286A0**)((char*)self + 0xA8) = new (D_00457F10, 0, 0) sAIObj_1286A0(self);
    *(int*)((char*)self + 0x74) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001287B8);
#ifdef SKIP_ASM
extern "C" void func_0012B090(void*);
void operator_delete(int*);
extern char D_00458488[];

extern "C" void func_001287B8(void* self, int flags)
{
    *(void**)((char*)self + 0xCC) = D_00458488;
    func_0012B090(self);
    operator_delete(*(int**)((char*)self + 0xA4));
    operator_delete(*(int**)((char*)self + 0xA8));
    if (flags & 1)
    {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00128818);
#ifdef SKIP_ASM
extern "C" void func_00103358(void*);
extern "C" void func_00101688(void*);
extern "C" void cAI_setAIState(void*, int);
extern "C" void* func_001297C8(void*, int);
// PORT: cAI_loadAnims is defined (void) in this unit, but this caller passes self in $a0; bound by asm label.
void cAI_loadAnims_self(void* self) __asm__("cAI_loadAnims");

struct sVEntry128818 { short delta; short index; void (*fn)(void*); };

struct sAiObj128818
{
    int f0;             // 0x00
    char pad4[0xC];
    int f10;            // 0x10
    int f14;            // 0x14
    int f18;            // 0x18
    int f1C;            // 0x1C
    int a20[2];         // 0x20
    int a28[6];         // 0x28
    char pad40[0x8];
    int a48[5];         // 0x48
    char pad5C[0x14];
    int a70[1];         // 0x70
    int f74;            // 0x74
    int f78;            // 0x78
    int f7C;            // 0x7C
    int f80;            // 0x80
    int f84;            // 0x84
    int f88;            // 0x88
    int f8C;            // 0x8C
    int f90;            // 0x90
    int f94;            // 0x94
    int f98;            // 0x98
    char pad9C[0x8];
    void* fA4;          // 0xA4
    void* fA8;          // 0xA8
    char padAC[0x20];
    sVEntry128818* vt;  // 0xCC
};

extern "C" void func_00128818(sAiObj128818* self)
{
    int i;
    func_00103358(self->fA4);
    func_00101688(self->fA8);
    self->f10 = 0;
    self->f14 = 0;
    self->f90 = 0;
    self->f78 = 0;
    self->f7C = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f1C = 0;
    self->f98 = 0;
    self->f0 = 0;
    cAI_setAIState(self, 1);
    for (i = 0; i < 6; i++) self->a28[i] = 0;
    for (i = 0; i < 1; i++) self->a70[i] = 0;
    for (i = 0; i < 5; i++) self->a48[i] = 0;
    cAI_loadAnims_self(self);
    self->vt[6].fn((char*)self + self->vt[6].delta);
    func_001297C8(self, 1);
    for (i = 0; i < 2; i++) self->a20[i] = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00128958);
#ifdef SKIP_ASM
extern "C" void cAI_purgeMissionRiders(void*);
extern "C" void cAI_initComputerRiders(void*);

extern "C" void func_00128958(void* self)
{
    *(int*)((char*)self + 0x94) = 0;
    if (*(int*)((char*)self + 0x88) > 0)
    {
        cAI_purgeMissionRiders(self);
    }
    cAI_initComputerRiders(self);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00128998);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cAI_initComputerActors(void*);
extern signed char D_00535C11[];

extern "C" void func_00128998(void* self, int n)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 0)
    {
        *(int*)((char*)self + 0x94) = n;
        cAI_initComputerActors(self);
    }
}
#endif

extern "C" void* func_001297C8(void*, int);

//100%
INCLUDE_ASM("ai/ai", func_001289F0__FPv);
#ifdef SKIP_ASM
void func_001289F0(void* self)
{
    func_001297C8(self, 0);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00128A10);
#ifdef SKIP_ASM
struct sAiObj128A48;
extern "C" void func_00128A48(sAiObj128A48* self, int mode);

extern "C" void func_00128A10(void* self)
{
    func_001297C8(self, 0);
    func_00128A48((sAiObj128A48*)self, 0);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00128A48);
#ifdef SKIP_ASM
struct sAiObj128A48
{
    char pad0[0x28];
    char* mRiders[19];
    int mMode;
    int mCount;
};

extern "C" void func_00128A48(sAiObj128A48* self, int mode)
{
    self->mMode = mode;
    if (mode == 0)
    {
        for (int i = 0; i < self->mCount; i++)
        {
            *(int*)(self->mRiders[i] + 0xEC) = 0;
        }
    }
    else
    {
        for (int i = 0; i < self->mCount; i++)
        {
            *(int*)(self->mRiders[i] + 0xEC) = i;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00128AC0);
#ifdef SKIP_ASM
extern "C" void cAI_initMissionRiders(void*);

extern "C" void func_00128AC0(void* self)
{
    cAI_initMissionRiders(self);
    func_001297C8(self, 0);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00128AF0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A2A50;
// PORT: func_0012BB20 takes self (the caller's $4 is still in place); other callers declare it without parameters.
void func_0012BB20_28AF0(void* self) __asm__("func_0012BB20");
extern "C" void func_00113C20(void* p);
extern "C" void func_0010F560(void* p);
extern "C" void func_00120E30(void* p);
extern "C" void func_00120E88(void* p);
extern "C" void func_00101B60(void* p);
extern "C" void func_001013A8(void* p);
extern "C" void func_00120ED8(void* p);
extern "C" void func_00120F20(void* p);
extern "C" void func_00121068(void* p);
extern "C" void func_001210B0(void* p);
extern "C" void func_001211F8(void* p);
void func_001216E0_28AF0(void* p) __asm__("func_001216E0__FPv");
extern "C" void func_00121700(void* p);
extern "C" void func_00121728(void* p);
extern "C" void func_00121750(void* p);
void func_001217F8_28AF0(void* p) __asm__("func_001217F8__FPv");
extern "C" void func_00121818(void* p);
extern "C" void func_001218D0(void* p);
extern "C" void func_00121950(void* p);
extern "C" void func_002DD0B8(void* p);
extern "C" void func_002DABC8(void* p);
extern "C" void func_002E8938(void* p);
extern "C" void func_002E66B8(void* p);
extern "C" void func_002EADD0(void* p);
extern "C" void func_002EF6D0(void* p);
extern "C" void func_002D4C08(void* p);
extern "C" void func_002E39D8(void* p);
extern "C" void func_002DF920(void* p);
extern "C" void func_002F1150(void* p);
extern "C" void func_002F6518(void* p);

static inline void* riderOf_28AF0(char* obj)
{
    return obj ? *(void**)(obj + 0x18) : 0;
}

// cAI update: gather the active riders into a local list, then run every update stage over the list.
#define EACH_RIDER(fn) for (i = 0; i < n; i++) fn(riders[i])
#define EACH_HANDLER(fn, off) for (i = 0; i < n; i++) fn((char*)handlers[i] + off)

extern "C" void func_00128AF0(char* self)
{
    void* riders[8];
    void* handlers[8];
    int n = 0;
    int i;
    func_0012BB20_28AF0(self);
    func_00113C20(self);
    func_0010F560(self);
    if (*(int*)(self + 0x88) > 0 && *(int*)(self + 0x7C) > 0)
    {
        char* mission = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x34);
        if (mission != 0 && *(int*)(mission + 0x70) == 0)
        {
            n = 1;
            riders[0] = riderOf_28AF0(*(char**)(self + 0x40));
            func_00120E30(riderOf_28AF0(*(char**)(self + 0x70)));
        }
        else
        {
            void** slot = &riders[n];
            *slot = riderOf_28AF0(*(char**)(self + 0x40));
            n = 2;
            riders[1] = riderOf_28AF0(*(char**)(self + 0x70));
            func_00120E30(riderOf_28AF0(*(char**)(self + 0x40)));
        }
    }
    else
    {
        int cnt = *(int*)(self + 0x7C);
        for (int i = 0; i < cnt; i++)
        {
            int k = n++;
            riders[k] = riderOf_28AF0(((char**)(self + 0x40))[i]);
        }
        if (*(int*)(self + 0x14) != 0)
        {
            int cnt2 = *(int*)(self + 0x80);
            for (int i = 0; i < cnt2; i++)
            {
                int k = n++;
                riders[k] = riderOf_28AF0(((char**)(self + 0x48))[i]);
            }
        }
        if (*(int*)(self + 0x8C) != 0)
        {
            int cnt3 = *(int*)(self + 0x84);
            for (int i = 0; i < cnt3; i++)
            {
                int k = n++;
                riders[k] = riderOf_28AF0(((char**)(self + 0x5C))[i]);
            }
        }
    }
    if (D_004A2A50 & 1)
    {
        EACH_RIDER(func_00120ED8);
    }
    else
    {
        for (i = 0; i < n; i++)
            handlers[i] = *(void**)((char*)riders[i] + 0x77C);
        EACH_RIDER(func_00120F20);
        EACH_RIDER(func_00121068);
        EACH_RIDER(func_001210B0);
        EACH_RIDER(func_001211F8);
        EACH_RIDER(func_001216E0_28AF0);
        EACH_RIDER(func_00121700);
        EACH_RIDER(func_00121728);
        EACH_RIDER(func_00121750);
        EACH_RIDER(func_001217F8_28AF0);
        EACH_RIDER(func_00121818);
        EACH_RIDER(func_001218D0);
        EACH_RIDER(func_00121950);
        EACH_HANDLER(func_002DD0B8, 0x3B0);
        EACH_HANDLER(func_002DABC8, 0x470);
        EACH_HANDLER(func_002E8938, 0x520);
        EACH_HANDLER(func_002E66B8, 0x610);
        EACH_HANDLER(func_002EADD0, 0x9C0);
        EACH_HANDLER(func_002EF6D0, 0xAD0);
        EACH_HANDLER(func_002D4C08, 0xAF0);
        EACH_HANDLER(func_002E39D8, 0xB00);
        EACH_HANDLER(func_002DF920, 0xB40);
        EACH_HANDLER(func_002F1150, 0xC70);
        EACH_HANDLER(func_002F6518, 0xD20);
        EACH_RIDER(func_00120E88);
    }
    func_00101B60(*(void**)(self + 0xA4));
    func_001013A8(*(void**)(self + 0xA8));
    *(int*)(self + 8) = *(int*)(self + 8) + 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00129160);
#ifdef SKIP_ASM
extern "C" void func_0011EB60(void* self, float value);
extern "C" void func_0011EB98(void* self);
extern "C" void func_003103F0(void*);

extern "C" void func_00129160(sAiObj128A48* self)
{
    for (int i = 0; i < self->mCount; i++)
    {
        func_0011EB60(self->mRiders[i], 1.0f);
        func_0011EB98(self->mRiders[i]);
        func_003103F0(*(void**)(self->mRiders[i] + 0x780));
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001291E0);
#ifdef SKIP_ASM
extern void* D_004A289C;
extern void* D_004A28A8;
extern "C" int func_00122278(void*);
extern "C" void func_00122448(void*);
extern "C" int func_001225C0(void*);
extern "C" void func_001225F0(void*);
void func_00122638(void*);
extern "C" void func_002D5048(void*);
extern "C" void func_002DB478(void*);
extern "C" void func_002DDAB8(void*);
extern "C" void func_002E24D0(void*);
extern "C" void func_002E3AF8(void*);
extern "C" void func_002E7A10(void*);
extern "C" void func_002EA538(void*, int);
extern "C" void func_002EB198(void*);
extern "C" void func_002EF950(void*);
extern "C" void func_002F1510(void*);
void func_002F6908(void*);

struct sVEntry_91E0 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sHolder_91E0 {
    char pad[0x18];
    char* rider;
};

struct sAI_91E0 {
    char pad0[0x14];
    int f14;
    char pad18[0x28 - 0x18];
    char* list28[6];
    sHolder_91E0* a40[2];
    sHolder_91E0* a48[5];
    sHolder_91E0* a5C[5];
    sHolder_91E0* h70;
    char pad74[0x78 - 0x74];
    int n78;
    int n7C;
    int n80;
    int n84;
    int f88;
    int f8C;
};

extern "C" void func_001291E0(sAI_91E0* self)
{
    char* riders[8];
    char* sub[8];
    int active[8];
    char* ptrs[16];
    int n;
    int i;

    for (n = 0; n < self->n78; n++) {
        char* r = self->list28[n];
        if (*(int*)(r + 0x884) == 0 && *(int*)(r + 0x888) == -1) {
            char* g = (char*)D_004A289C;
            sVEntry_91E0* vt = *(sVEntry_91E0**)(g + 0x10D8);
            int v = vt[114].fn(g + vt[114].delta);
            *(int*)(self->list28[n] + 0x888) = v + 4;
        }
    }
    n = 0;
    if (self->f88 > 0 && self->n7C > 0) {
        char* x = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x34);
        if (x != 0 && *(int*)(x + 0x70) == 0) {
            riders[n++] = self->a40[0] ? self->a40[0]->rider : 0;
        } else {
            riders[n++] = self->h70 ? self->h70->rider : 0;
        }
    } else {
        for (i = 0; i < self->n7C; i++) {
            riders[n++] = self->a40[i] ? self->a40[i]->rider : 0;
        }
        if (self->f14 != 0) {
            for (i = 0; i < self->n80; i++) {
                riders[n++] = self->a48[i] ? self->a48[i]->rider : 0;
            }
        }
        if (self->f8C != 0) {
            for (i = 0; i < self->n84; i++) {
                riders[n++] = self->a5C[i] ? self->a5C[i]->rider : 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        active[i] = func_00122278(riders[i]);
        sub[i] = *(char**)(riders[i] + 0x77C);
    }
    for (i = 0; i < n; i++) {
        if (active[i]) func_001225C0(riders[i]);
    }
    for (i = 0; i < n; i++) {
        if (active[i]) func_00122448(riders[i]);
    }
    for (i = 0; i < n; i++) {
        if (active[i]) func_001225F0(riders[i]);
    }
    for (i = 0; i < n; i++) {
        ptrs[i] = sub[i] ? sub[i] + 0x520 : 0;
    }
    func_002EA538(ptrs, n);
    for (i = 0; i < n; i++) func_002E3AF8(sub[i] + 0xB00);
    for (i = 0; i < n; i++) func_002F6908(sub[i] + 0xD20);
    for (i = 0; i < n; i++) func_002DDAB8(sub[i] + 0x3B0);
    for (i = 0; i < n; i++) func_002EF950(sub[i] + 0xAD0);
    for (i = 0; i < n; i++) func_002E7A10(sub[i] + 0x610);
    for (i = 0; i < n; i++) func_002EB198(sub[i] + 0x9C0);
    for (i = 0; i < n; i++) {
        if (active[i]) func_002DB478(sub[i] + 0x470);
    }
    for (i = 0; i < n; i++) {
        if (active[i]) func_002D5048(sub[i] + 0xAF0);
    }
    for (i = 0; i < n; i++) {
        if (active[i]) func_002E24D0(sub[i] + 0xB40);
    }
    for (i = 0; i < n; i++) {
        if (active[i]) func_002F1510(sub[i] + 0xC70);
    }
    for (i = 0; i < n; i++) func_00122638(riders[i]);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001296F8);
#ifdef SKIP_ASM
extern "C" int func_0011D640(void* self);
extern "C" void func_0011C298(void* self);

extern "C" void func_001296F8(sAiObj128A48* self)
{
    for (int i = 0; i < self->mCount; i++)
    {
        if (func_0011D640(self->mRiders[i]) == 0)
        {
            func_0011C298(self->mRiders[i]);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00129768);
#ifdef SKIP_ASM
extern "C" void func_00103358(void*);
extern "C" void func_00101688(void*);
extern "C" void cAI_setAIState(void*, int);

extern "C" void func_00129768(void* self, int state)
{
    func_00103358(*(void**)((char*)self + 0xA4));
    func_00101688(*(void**)((char*)self + 0xA8));
    *(int*)((char*)self + 0x98) = 0;
    *(int*)((char*)self + 0x0) = 0;
    cAI_setAIState(self, state);
    func_001297C8(self, 1);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001297C8);
#ifdef SKIP_ASM
void* func_0010F398(void* self);
extern "C" void func_00154A58(int rider, int a);
extern "C" void func_0011D390(void* rider);

struct sVEntry1297C8 { short delta; short index; int (*fn)(void*); };

struct sAiObj1297C8
{
    char pad0[0x8];
    int f8;             // 0x08
    int fC;             // 0x0C
    char pad10[0x8];
    int f18;            // 0x18
    int f1C;            // 0x1C
    char pad20[0x8];
    char* mRiders[18];  // 0x28
    char* mList[2];     // 0x70
    int mCount;         // 0x78
    char pad7C[0xC];
    int mCount2;        // 0x88
};

extern "C" void* func_001297C8(void* p, int flag)
{
    sAiObj1297C8* self = (sAiObj1297C8*)p;
    func_0010F398(self);
    self->f8 = 0;
    if (flag != 0)
    {
        self->fC = 0;
    }
    self->f18 = -1;
    self->f1C = 0;
    for (int i = 0; i < self->mCount; i++)
    {
        char* obj = self->mRiders[i] + 0x6C0;
        sVEntry1297C8* vt = *(sVEntry1297C8**)obj;
        if (vt[9].fn(obj + vt[9].delta) != 0 || flag != 0)
        {
            func_00154A58(i, *(int*)(self->mRiders[i] + 0x790) + 0xFC);
            func_0011D390(self->mRiders[i]);
        }
    }
    for (int i = 0; i < self->mCount2; i++)
    {
        func_0011D390(*(void**)(self->mList[i] + 0x18));
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001298C8);
#ifdef SKIP_ASM
extern void* D_004A28A8;

extern "C" int func_001298C8()
{
    return *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x8);
}
#endif

INCLUDE_ASM("ai/ai", cAI_InitPlayers);

//100%
INCLUDE_ASM("ai/ai", cAI_initMissionRiders);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cRider_cRider(void* self);
extern "C" void* func_00125C70(void* self, int inChrg);
extern "C" void func_0030DBA0(void* self, float a, float b);
extern "C" void func_00148AA8(void* self, int rider, int value);
extern "C" void cRider_addFocusBox(void* self);
extern "C" void cRider_initOnce(void* self, int immediate);
struct cRider;
void cRider_addRiderMetrix(cRider* rider);
void func_00144D70(void*, int, int);
extern char D_00457F20[];

struct sVEntry_MR { short delta; short index; void* fn; };
struct sVtbl9_MR { sVEntry_MR e[9]; } __attribute__((aligned(8)));
struct sVtbl22_MR { sVEntry_MR e[22]; } __attribute__((aligned(8)));

extern const sVtbl9_MR D_00458240;
extern char D_00459B90[];
extern const sVtbl22_MR D_00458288;
extern char D_00458338[];

// PORT: g++ 2.95 most-derived constructor of a class deriving virtually from cRider (vbase at +0xE10,
// vbase pointers in every subobject), inlined here; the not-in-charge vtable fix-up is written out by hand.
static inline char* cMissionRider_ctor(char* self, int inChrg)
{
    if (inChrg)
    {
        char* vb = self + 0xE10;
        *(char**)(self + 0xD20) = vb;
        *(char**)(self + 0xC70) = vb;
        *(char**)(self + 0xB40) = vb;
        *(char**)(self + 0xB00) = vb;
        *(char**)(self + 0xAF0) = vb;
        *(char**)(self + 0xAD0) = vb;
        *(char**)(self + 0x9C0) = vb;
        *(char**)(self + 0x610) = vb;
        *(char**)(self + 0x520) = vb;
        *(char**)(self + 0x470) = vb;
        *(char**)(self + 0x3B0) = vb;
        *(char**)(self + 0x3A0) = vb;
        *(char**)(self + 0x398) = vb;
        *(char**)(self + 0x384) = vb;
        *(char**)(self + 0x364) = vb;
        *(char**)(self + 0x358) = vb;
        *(char**)(self + 0x340) = vb;
        *(char**)(self + 0x2B8) = vb;
        *(char**)(self + 0x2A4) = vb;
        *(char**)(self + 0x288) = vb;
        *(char**)(self + 0x224) = vb;
        *(char**)(self + 0x200) = vb;
        *(char**)(self + 0x1F0) = vb;
        *(char**)(self + 0x1E4) = vb;
        *(char**)(self + 0x1C0) = vb;
        *(char**)(self + 0x1B0) = vb;
        *(char**)(self + 0x100) = vb;
        *(char**)(self + 0xA0) = vb;
        *(char**)(self + 0x70) = vb;
        *(char**)(self + 0x24) = vb;
        *(char**)(self + 0x18) = vb;
        cRider_cRider(vb);
    }
    func_00125C70(self, 0);
    *(const void**)(*(char**)(self + 0x18) + 0x6E8) = &D_00458240;
    *(void**)(*(char**)(self + 0x18) + 0x6D0) = D_00459B90;
    *(const void**)(*(char**)(self + 0x18) + 0x6C0) = &D_00458288;
    *(void**)(self + 0xDE8) = D_00458338;
    if (!inChrg)
    {
        sVtbl9_MR t1 = D_00458240;
        *(void**)(*(char**)(self + 0x18) + 0x6E8) = &t1;
        char* base = *(char**)(self + 0x18) - 0xE10;
        int d = self - base;
        t1.e[1].delta = D_00458240.e[1].delta + d;
        sVtbl22_MR t2 = D_00458288;
        *(void**)(*(char**)(self + 0x18) + 0x6C0) = &t2;
        t2.e[1].delta = D_00458288.e[1].delta + d;
    }
    return self;
}

struct sRiderMR { char pad[0x86C]; int mIndex; int mCtrl; };

struct sAiObjMR
{
    char pad0[0x28];
    sRiderMR* mRiders[18];
    char* mMission[2];
    int mCount;
    char pad7C[0xC];
    int mNumMission;
};

extern "C" void cAI_initMissionRiders(void* p)
{
    sAiObjMR* self = (sAiObjMR*)p;
    if (self->mNumMission > 0)
        return;
    char* rm = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
    char* m = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x34);
    int idx = self->mCount;
    char* obj = cMissionRider_ctor((char*)cMemMan_alloc(0x1950, D_00457F20, 0x80000000, 0), 1);
    *(int*)(obj + 0xDF0) = *(int*)(m + 0x6C);
    *(int*)(obj + 0xDF4) = 0;
    func_0030DBA0(*(void**)(*(char**)(obj + 0x18) + 0x780), 0.5f, 0.5f);
    func_00148AA8(cBE_getInterface_Fv(cBE_getBE(), 3), idx, 5);
    self->mRiders[idx] = obj ? *(sRiderMR**)(obj + 0x18) : 0;
    self->mRiders[idx]->mIndex = idx;
    self->mRiders[idx]->mCtrl = 0;
    cRider_addFocusBox(*(void**)(obj + 0x18));
    cRider_addRiderMetrix(*(cRider**)(obj + 0x18));
    cRider_initOnce(self->mRiders[idx], 0);
    func_00144D70(rm, idx, idx);
    idx++;
    self->mMission[self->mNumMission] = obj;
    self->mCount = idx;
    self->mNumMission++;
}
#endif

//100%
INCLUDE_ASM("ai/ai", cAI_initComputerRiders);
#ifdef SKIP_ASM
extern "C" void* func_00108C80(void* mem, int a, int b);
extern "C" void cBENewPlayerInterface_setRiderCtrlID(void* iface, int rider, int ctrl);
extern "C" void cBENewPlayerInterface_setRiderCharID(void* iface, int rider, int ch);
int cBENewPlayerInterface_getRiderCharID(void* iface, int rider);
struct cRider;
void cRider_addRiderMetrix(cRider* rider);
extern "C" void func_0010C9A8(void*);
extern "C" void cComputer_updateRiderDifficulty(void*);
extern "C" void func_0012B698(void* self, void* rider);
void func_00144D70(void*, int, int);
extern char D_00457F30[];
extern int D_00535C04[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sRiderCR { char pad[0x86C]; int mIndex; int mCtrl; };
struct sVEntryCR { short delta; short index; void (*fn)(void*); };
class cBEIfaceCR {
public:
    int pad[3];
    virtual void update();
};

struct sAiObjCR
{
    char pad0[0x10];
    int f10;
    char pad14[0x14];
    sRiderCR* mRiders[8];
    char* mObjs[12];
    int mCount;
    char pad7C[4];
    int mNumComputers;
};

extern "C" void cAI_initComputerRiders(void* p)
{
    sAiObjCR* self = (sAiObjCR*)p;
    char* rm = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
    int n = D_00535C04[0] - self->mNumComputers;
    int idx = self->mCount;
    for (int i = 0; i < n; i++)
    {
        int ch = cBENewPlayerInterface_getRiderCharID(iface, idx);
        char* obj = (char*)func_00108C80(cMemMan_alloc(0x1A90, D_00457F30, 0x80000000, 0), 1, 0);
        sRiderCR** slot = &self->mRiders[idx];
        sRiderCR* rider = obj ? *(sRiderCR**)(obj + 0x18) : 0;
        *slot = rider;
        rider->mIndex = idx;
        cBENewPlayerInterface_setRiderCtrlID(iface, idx, -1);
        cBENewPlayerInterface_setRiderCharID(iface, idx, ch);
        ((cBEIfaceCR*)iface)->update();
        sRiderCR* r2 = *slot;
        int m1 = -1;
        r2->mCtrl = m1;
        cRider_addRiderMetrix(*(cRider**)(obj + 0x18));
        func_0010C9A8(obj);
        cComputer_updateRiderDifficulty(obj);
        func_0012B698(self, obj);
        func_00144D70(rm, idx, idx);
        self->mObjs[self->mNumComputers] = obj;
        self->mNumComputers++;
        idx++;
    }
    ((cBEIfaceCR*)rm)->update();
    ((cBEIfaceCR*)iface)->update();
    self->mCount = idx;
    self->f10 = 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", cAI_initComputerActors);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00108C80(void* mem, int a, int b);
extern "C" void cBENewPlayerInterface_setRiderCtrlID(void* iface, int rider, int ctrl);
extern "C" void cBENewPlayerInterface_setRiderCharID(void* iface, int rider, int ch);
extern "C" void func_001473D0(void* iface, int rider, int v);
struct cRider;
void cRider_addRiderMetrix(cRider* rider);
extern char D_00457F40[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sRiderCA { char pad[0x86C]; int mIndex; int mCtrl; };
struct sVEntryCA { short delta; short index; void (*fn)(void*); };

struct sAiObj129FF8
{
    char pad0[0x20];
    int mCharIds[2];
    sRiderCA* mRiders[13];
    char* mObjs[7];
    int mCount;
    char pad7C[8];
    int mNumActors;
    char pad88[0xC];
    int mMaxActors;
};

extern "C" void cAI_initComputerActors(void* p)
{
    sAiObj129FF8* self = (sAiObj129FF8*)p;
    char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
    int n = self->mMaxActors - self->mNumActors;
    int idx = self->mCount;
    for (int i = 0; i < n; i++)
    {
        int ch = self->mCharIds[self->mNumActors];
        char* obj = (char*)func_00108C80(cMemMan_alloc(0x1A90, D_00457F40, 0x80000000, 0), 1, 1);
        sRiderCA* rider = obj ? *(sRiderCA**)(obj + 0x18) : 0;
        self->mRiders[idx] = rider;
        rider->mIndex = idx;
        cBENewPlayerInterface_setRiderCtrlID(iface, idx, -1);
        cBENewPlayerInterface_setRiderCharID(iface, idx, ch);
        func_001473D0(iface, idx, 0);
        sVEntryCA* vt = *(sVEntryCA**)(iface + 0xC);
        vt[1].fn(iface + vt[1].delta);
        sRiderCA* r2 = self->mRiders[idx];
        int m1 = -1;
        r2->mCtrl = m1;
        cRider_addRiderMetrix(*(cRider**)(obj + 0x18));
        self->mObjs[self->mNumActors] = obj;
        self->mNumActors++;
        idx++;
    }
    sVEntryCA* vt = *(sVEntryCA**)(iface + 0xC);
    vt[1].fn(iface + vt[1].delta);
    self->mCount = idx;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A180);
#ifdef SKIP_ASM
extern "C" int func_0011D640(void* self);

extern "C" int func_0012A180(sAiObj128A48* self)
{
    int result = 1;
    for (int i = 0; i < self->mCount; i++)
    {
        if (func_0011D640(self->mRiders[i]) == 0)
        {
            result = 0;
        }
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A1F0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_00536708[];

struct sAiIds12A1F0 {
    char pad[0x18];
    int ids[1];
};
struct sAiApp12A1F0 {
    char pad[0xC0];
    sAiIds12A1F0* p;
};

extern "C" int func_0012A1F0(void* self, int idx) {
    int id = ((sAiApp12A1F0*)D_004A28A8)->p->ids[idx];
    int r = 0;
    for (int i = 0; i < 6; i++) if (id == D_00536708[i]) r = 1;
    return r;
}
#endif
//100%
INCLUDE_ASM("ai/ai", func_0012A240);
#ifdef SKIP_ASM
extern "C" int func_0012A240(int *arg0) {
    return *arg0 == 5;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A250);
#ifdef SKIP_ASM
struct sAiObj12A250
{
    char pad0[0x40];
    char* mRiders[15];
    int mCount;
};

static inline bool aiRiderOk12A250(char* rider)
{
    return *(float*)(*(char**)(rider + 0x18) + 0x470) >= 0.0f;
}

extern "C" int func_0012A250(sAiObj12A250* self)
{
    for (int i = 0; i < self->mCount; i++)
    {
        bool ok = aiRiderOk12A250(self->mRiders[i]);
        if (!ok)
        {
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A2B0);
#ifdef SKIP_ASM
extern "C" void func_00112180(void* rider, int v);
extern "C" void func_0026AF00(void* self);
extern "C" void func_0026ADA8(void*, int);
extern char D_004D33A0[];
extern "C" void func_0012A2B0(void* self, int arg1) {
    int i;
    func_0026AF00(D_004D33A0);
    func_0026ADA8(D_004D33A0, arg1);
    for (i = 0; i < *(int*)((char*)self + 0x78); i++) {
        func_00112180(*(void**)((char*)self + 0x28 + (i << 2)), 0);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A340);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern void* D_004A28A8;
extern "C" int func_0022E0E0(void* self);
extern char D_004D33A0[];
extern char D_00535BC8[];
extern "C" void func_0026AF00(void* self);
extern "C" int func_0026AD70(void* self, int v);
extern "C" void func_00112180(void* rider, int v);

struct sAiObj12A340
{
    char pad0[0x28];
    char* mRiders[19];
    int mMode;
    int mCount;
};

extern "C" int func_0012A340(sAiObj12A340* self, int unused, int mode, int arg)
{
    int lvl = func_0022E0E0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x78));
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if ((unsigned)(lvl - 0x11) < 5)
    {
        signed char* g = (signed char*)D_00535BC8;
        if (g[0x48] == 5 || g[0x4A] == 0xB)
        {
            if (mode != 1)
                return 0;
            goto ok;
        }
        if (g[0x48] == 6)
        {
            if (mode != 2)
                return 0;
            goto ok;
        }
    }
    if (mode == 1 || mode == 2)
        return 0;
ok:
    if (lvl < 0x16)
    {
        func_0026AF00(D_004D33A0);
        func_0026AD70(D_004D33A0, arg);
        if (*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) == 0)
            return 1;
        for (int i = 0; i < self->mCount; i++)
        {
            func_00112180(self->mRiders[i], 0);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A490);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_0022E0E0(void* self);
void func_0026ADA0(void* self);
extern char D_004D33A0[];

extern "C" void func_0012A490(void* p, unsigned char id)
{
    if (func_0022E0E0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x78)) < 0x16)
    {
        func_0026ADA0(D_004D33A0);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A4D0);
#ifdef SKIP_ASM
extern "C" int func_0026ADE8(int *);

extern "C" void func_0012A4D0(void) {
    func_0026ADE8(&(*(int*)&D_004D33A0));
}
#endif
//100%
INCLUDE_ASM("ai/ai", func_0012A4F0);
#ifdef SKIP_ASM
extern "C" void func_0012A4F0(void* self) {
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x78); i++) {
        func_00112180(*(void**)((char*)self + 0x28 + (i << 2)), 0);
    }
}
#endif
//100%
INCLUDE_ASM("ai/ai", func_0012A558);
#ifdef SKIP_ASM
extern "C" void func_0012A558(void) {

}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012A560);
#ifdef SKIP_ASM
extern "C" void* func_0026AF70(void* tree, int id);
extern "C" float func_0026A138(void* obj);
extern "C" void func_0011FEC8_2A560(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" void func_0011FE78_2A560(void* self, int v) __asm__("func_0011FE78__FPv");
struct sTree_2A560 { int pad[4]; int count; };
extern sTree_2A560 D_tree_2A560 __asm__("D_004D33A0");

struct sVec4_2A560
{
    float x, y, z, w;
} __attribute__((aligned(16)));

sVec4_2A560 func_0026AB20_2A560(void* path, int* inRange, float t) __asm__("func_0026AB20");
void func_0011D660_2A560(void* self, sVec4_2A560* a, sVec4_2A560* b, int n, float t) __asm__("func_0011D660");

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_2A560 vu0Sub_2A560(const sVec4_2A560& a, const sVec4_2A560& b)
{
    sVec4_2A560 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vu0Length_2A560(const sVec4_2A560& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector *= 1/len).
static inline void vu0Normalize_2A560(sVec4_2A560& v, float len)
{
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(v), "=&r"(t)
        : "m"(v), "f"(len));
}

struct sAi_2A560
{
    char pad00[0x28];
    char* riders[1];
};

extern "C" void func_0012A560(char* self, int which)
{
    int n = D_tree_2A560.count;
    int i;
    for (i = 0; i < n; i++)
    {
        void* obj = func_0026AF70(&D_tree_2A560, i);
        float f = func_0026A138(obj);
        if (f == -1.0f)
            continue;
        float t = f - 1000.0f;
        if (t < 0.0f)
            t = 0.0f;
        int j = 0;
        sVec4_2A560 a = func_0026AB20_2A560(obj, 0, f);
        sVec4_2A560 b = func_0026AB20_2A560(obj, 0, t);
        for (j = 0; j < *(int*)(self + 0x78); j++)
        {
            if (which == -1 || which == j)
            {
                func_0011FEC8_2A560(((sAi_2A560*)self)->riders[j], 0);
                func_0011FE78_2A560(((sAi_2A560*)self)->riders[j], 0);
                sVec4_2A560 d = vu0Sub_2A560(a, b);
                float len = vu0Length_2A560(d);
                if (1.0f < len)
                    vu0Normalize_2A560(d, len);
                else
                {
                    sVec4_2A560 t2 = *(sVec4_2A560*)(((sAi_2A560*)self)->riders[j] + 0x1B0);
                    d = t2;
                }
                func_0011D660_2A560(((sAi_2A560*)self)->riders[j], &b, &d, 5, 0.0f);
            }
        }
        return;
    }
}
#endif

INCLUDE_ASM("ai/ai", func_0012A768);
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ai", func_0012A998);
#ifdef SKIP_ASM
// self is a cAI (no header yet): +0x48 is a list of rider objects (count at +0x80), each holding
// its cRider virtual-base pointer at +0x18.
struct sVEntry0012A998 { short delta; short index; int (*fn)(void*); };

extern void* D_004A289C;
extern "C" int func_0012A1F0(void*, int);

extern "C" void func_0012A998(void* self)
{
    for (int i = 0; i < *(int*)((char*)self + 0x80); i++)
    {
        char** list = (char**)((char*)self + 0x48);
        cRider* rider = *(cRider**)(list[i] + 0x18);
        if (rider->mRenderFlag != 0)
        {
            char* sub = (char*)&rider->mVtbl;
            sVEntry0012A998* vt = *(sVEntry0012A998**)sub;
            if (func_0012A1F0(self, vt[kRiderVt_getAIIndex].fn(sub + vt[kRiderVt_getAIIndex].delta)) != 0)
            {
                cRider* r = *(cRider**)(list[i] + 0x18);
                r->mRenderFlag = 0;
                r->mSafeRenderTick = -1;
                char* g = (char*)D_004A289C;
                char* obj = list[i];
                sVEntry0012A998* gvt = *(sVEntry0012A998**)(g + 0x10D8);
                (*(cRider**)(obj + 0x18))->mSafeRenderTick = gvt[114].fn(g + gvt[114].delta) + 4;
            }
        }
    }
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ai", func_0012AA78);
#ifdef SKIP_ASM
extern "C" int func_0011C0E0(void*);
struct sVE_0012AA78 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sEnt_0012AA78 {
    char pad[0x18];
    cRider* rider;
};
struct sOwner_0012AA78 {
    char pad[0x48];
    sEnt_0012AA78* ent[8];
    char pad2[0x80 - 0x68];
    int count;
};

extern "C" int func_0012A1F0(void*, int);

extern "C" int func_0012AA78(sOwner_0012AA78* self) {
    int i;
    int ok = 1;
    for (i = 0; i < self->count; i++) {
        if (func_0011C0E0(self->ent[i]->rider) == 0) {
            char* obj = (char*)&self->ent[i]->rider->mVtbl;
            sVE_0012AA78* vt = *(sVE_0012AA78**)obj;
            if (func_0012A1F0(self, vt[kRiderVt_getAIIndex].fn(obj + vt[kRiderVt_getAIIndex].delta)) != 0)
                ok = 0;
        }
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012AB20);
#ifdef SKIP_ASM
struct sAiObj12AB20
{
    char pad0[0x14];
    int m14;
    char pad18[0x30];
    char* mRiders[14];
    int mCount;
};

struct sVEntry0012AB20 { short delta; short index; int (*fn)(void*); };

extern void* D_004A289C;

extern "C" void func_0012AB20(sAiObj12AB20* self)
{
    self->m14 = 0;
    for (int i = 0; i < self->mCount; i++)
    {
        char* r = *(char**)(self->mRiders[i] + 0x18);
        if (*(int*)(r + 0x884) != 0)
        {
            *(int*)(r + 0x884) = 0;
            *(int*)(r + 0x888) = -1;
            char* g = (char*)D_004A289C;
            char* rider = self->mRiders[i];
            sVEntry0012AB20* vt = *(sVEntry0012AB20**)(g + 0x10D8);
            *(int*)(*(char**)(rider + 0x18) + 0x888) = vt[114].fn(g + vt[114].delta) + 4;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012ABD0);
#ifdef SKIP_ASM
struct sAiObj12ABD0
{
    char pad0[0x48];
    char* mRiders[14];
    int mCount;
};

extern "C" int func_0011C0E0(void*);

extern "C" int func_0012ABD0(sAiObj12ABD0* self)
{
    int result = 1;
    for (int i = 0; i < self->mCount; i++)
    {
        if (func_0011C0E0(*(void**)(self->mRiders[i] + 0x18)) == 0)
        {
            result = 0;
        }
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012AC48);
#ifdef SKIP_ASM
struct sAiObj12AC48
{
    char pad0[0x5C];
    char* mRiders[10];
    int mCount;
    int m88;
    int m8C;
};

struct sVEntry0012AC48 { short delta; short index; int (*fn)(void*); };

extern void* D_004A289C;

extern "C" void func_0012AC48(sAiObj12AC48* self)
{
    self->m8C = 0;
    for (int i = 0; i < self->mCount; i++)
    {
        char* r = *(char**)(self->mRiders[i] + 0x18);
        if (*(int*)(r + 0x884) != 0)
        {
            *(int*)(r + 0x884) = 0;
            *(int*)(r + 0x888) = -1;
            char* g = (char*)D_004A289C;
            char* rider = self->mRiders[i];
            sVEntry0012AC48* vt = *(sVEntry0012AC48**)(g + 0x10D8);
            *(int*)(*(char**)(rider + 0x18) + 0x888) = vt[114].fn(g + vt[114].delta) + 4;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012ACF8);
#ifdef SKIP_ASM
struct sAiObj12ACF8
{
    char pad0[0x5C];
    char* mRiders[10];
    int mCount;
};

extern "C" int func_0011C0E0(void*);

extern "C" int func_0012ACF8(sAiObj12ACF8* self)
{
    int result = 1;
    for (int i = 0; i < self->mCount; i++)
    {
        if (func_0011C0E0(*(void**)(self->mRiders[i] + 0x18)) == 0)
        {
            result = 0;
        }
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012AD70);
#ifdef SKIP_ASM
// self is a cAI (no header yet); +0x70 is its list of rider objects (count at +0x88),
// each holding its cRider virtual-base pointer at +0x18.
extern "C" void func_0012AD70(void* self)
{
    for (int i = 0; i < *(int*)((char*)self + 0x88); i++)
    {
        char* obj = ((char**)((char*)self + 0x70))[i];
        cRider* rider = *(cRider**)(obj + 0x18);
        if (rider->mRenderFlag != 0)
        {
            rider->mRenderFlag = 0;
            rider->mSafeRenderTick = -1;
        }
    }
}
#endif
//100%
INCLUDE_ASM("ai/ai", func_0012ADC0);
#ifdef SKIP_ASM
extern "C" int func_0012ADC0(void* self) {
    int i;
    int ok = 1;
    for (i = 0; i < *(int*)((char*)self + 0x88); i++) {
        void* p = *(void**)((char*)self + 0x70 + (i << 2));
        if (func_0011C0E0(*(void**)((char*)p + 0x18)) == 0)
            ok = 0;
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012AE38);
#ifdef SKIP_ASM
struct sAiMissionVEntry { short delta; short index; void (*fn)(void*, int); };

struct sAiMission
{
    char pad0[0x14];
    int m14;
    char pad18[0x30];
    void* mListA[5];
    void* mListB[5];
    void* mListC[2];
    int mTotal;
    int pad7C;
    int mCountA;
    int mCountB;
    int mCountC;
    int m8C;
    int m90;
};

extern "C" void func_0012AE38(void* p)
{
    sAiMission* self = (sAiMission*)p;
    for (int i = 0; i < self->mCountA; i++)
    {
        void* m = self->mListA[i];
        if (m)
        {
            char* obj = *(char**)((char*)m + 0x18) + 0x6C0;
            sAiMissionVEntry* vt = *(sAiMissionVEntry**)obj;
            vt[1].fn(obj + vt[1].delta, 3);
        }
        self->mListA[i] = 0;
    }
    self->mTotal -= self->mCountA;
    self->mCountA = 0;
    self->m14 = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012AED0);
#ifdef SKIP_ASM
extern "C" void func_0012AED0(void* p)
{
    sAiMission* self = (sAiMission*)p;
    for (int i = 0; i < self->mCountB; i++)
    {
        void* m = self->mListB[i];
        if (m)
        {
            char* obj = *(char**)((char*)m + 0x18) + 0x6C0;
            sAiMissionVEntry* vt = *(sAiMissionVEntry**)obj;
            vt[1].fn(obj + vt[1].delta, 3);
        }
        self->mListB[i] = 0;
    }
    self->mTotal -= self->mCountB;
    self->mCountB = 0;
    self->m8C = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", cAI_purgeMissionRiders);
#ifdef SKIP_ASM
extern "C" void cAI_purgeMissionRiders(void* p)
{
    sAiMission* self = (sAiMission*)p;
    for (int i = 0; i < self->mCountC; i++)
    {
        void* m = self->mListC[i];
        if (m)
        {
            char* obj = *(char**)((char*)m + 0x18) + 0x6C0;
            sAiMissionVEntry* vt = *(sAiMissionVEntry**)obj;
            vt[1].fn(obj + vt[1].delta, 3);
        }
        self->mListC[i] = 0;
    }
    self->mTotal -= self->mCountC;
    self->mCountC = 0;
    self->m90 = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ai", func_0012B000);
#ifdef SKIP_ASM
extern "C" void func_0012AED0(void*);
extern "C" void* func_0010F3B8(void*);

extern "C" void func_0012B000(void* self)
{
    func_0012AED0(self);
    func_0010F3B8(self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ai", func_0012B030);
#ifdef SKIP_ASM
extern "C" void func_0012AE38(void*);
extern "C" void* func_0010F3B8(void*);

extern "C" void func_0012B030(void* self)
{
    func_0012AE38(self);
    func_0010F3B8(self);
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B060);
#ifdef SKIP_ASM
extern "C" void* func_0010F3B8(void*);

extern "C" void func_0012B060(void* self)
{
    cAI_purgeMissionRiders(self);
    func_0010F3B8(self);
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ai", func_0012B090);
#ifdef SKIP_ASM
extern "C" void func_00154A58(int rider, int a);
extern "C" void func_0012B200(void*);

struct sAiObj12B090
{
    char pad0[0x28];
    char* mRiders[6];
    void* mList[13];
    int m74;
    int mCount;
    int mCount2;
};

extern "C" void func_0012B090(void* p)
{
    sAiObj12B090* self = (sAiObj12B090*)p;
    for (int i = 0; i < self->mCount; i++)
    {
        func_00154A58(i, *(int*)(self->mRiders[i] + 0x790) + 0xFC);
    }
    for (int i = 0; i < self->mCount2; i++)
    {
        void* m = self->mList[i];
        if (m)
        {
            char* obj = *(char**)((char*)m + 0x18) + 0x6C0;
            sAiMissionVEntry* vt = *(sAiMissionVEntry**)obj;
            vt[1].fn(obj + vt[1].delta, 3);
        }
        self->mList[i] = 0;
    }
    cAI_purgeMissionRiders(self);
    func_0012AE38(self);
    func_0012AED0(self);
    self->mCount2 = 0;
    self->mCount = 0;
    func_0012B200(self);
    self->m74 = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B180);
#ifdef SKIP_ASM
extern "C" void func_00154A58(int rider, int a);
extern "C" void func_001175B8(char* self);

extern "C" void func_0012B180(sAiObj128A48* self)
{
    for (int i = 0; i < self->mCount; i++)
    {
        func_00154A58(i, *(int*)(self->mRiders[i] + 0x790) + 0xFC);
        func_001175B8(*(char**)(self->mRiders[i] + 0x790));
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B200);
#ifdef SKIP_ASM
extern void** D_004A3DF8;
extern void* D_004A3E7C;
extern "C" void func_00314FE8(void*, void*);
extern "C" void func_00311110(void*);
extern "C" void func_003112C8(void*, int);

extern "C" void func_0012B200(void* self)
{
    int i;
    for (i = 0; i < 1; i++)
    {
        void* p = *(void**)((char*)D_004A3DF8 + ((unsigned char)i << 2));
        if (p != 0)
        {
            func_00314FE8(D_004A3E7C, p);
            void** t = D_004A3DF8;
            *(void**)((char*)t + ((unsigned char)i << 2)) = 0;
            func_00311110(t);
            func_003112C8(p, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", cAI_loadAnims);
#ifdef SKIP_ASM
extern "C" int func_003DED50(char* name, int a1, int a2, void* out);
extern "C" int func_003DEDC0(void* handle, int arg);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00311250(void* mem, char* name);
extern "C" void func_00314F30(void* map, int i, void* anim);
// PORT: the original passes the map to cGameAnimMap_testResolve(), whose symbol is declared with no params.
void cGameAnimMap_testResolve_impl(void* map) __asm__("cGameAnimMap_testResolve__Fv");
struct sAnimTable { void* anims[1]; };
extern char D_00457F58[];
extern char D_00457F70[];
extern char* D_004A1100[1];

extern "C" void cAI_loadAnims(void)
{
    void* handle;
    int i;
    func_003DED50(D_00457F58, 0, 0x64, &handle);
    for (i = 0; i < 1; i++)
    {
        void* p = func_00311250(cMemMan_alloc(0x18, D_00457F70, 0, 0), D_004A1100[i]);
        ((sAnimTable*)D_004A3DF8)->anims[(unsigned char)i] = p;
        func_00314F30(D_004A3E7C, i, p);
    }
    cGameAnimMap_testResolve_impl(D_004A3E7C);
    func_003DEDC0(handle, 0x64);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B340);
#ifdef SKIP_ASM
extern char* D_004A2EEC;
extern void* D_004A28A8;
extern "C" void func_00258950(void* self);
extern "C" void func_0026FA50(void* self);
extern "C" void func_00125108(void* self);

static inline bool aiRiderFar12B340(char* r)
{
    return *(float*)(r + 0x470) >= 10.0f;
}

extern "C" void func_0012B340(sAiObj12A250* self)
{
    if (*(int*)self == 5)
    {
        func_00258950(D_004A2EEC);
        for (int i = 0; i < self->mCount; i++)
        {
            char* rider = self->mRiders[i];
            char* r = *(char**)(rider + 0x18);
            if (*(int*)(r + 0x87C) == 0)
            {
                bool far = aiRiderFar12B340(r);
                if (far)
                {
                    return;
                }
                func_0026FA50(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
                *(int*)(*(char**)(rider + 0x18) + 0x480) = 1;
                func_00125108(*(void**)(rider + 0x18));
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B420);
#ifdef SKIP_ASM
unsigned int AIrand();
extern "C" int func_00125AD8(void* self);

extern "C" int func_0012B420(sAiObj128A48* self)
{
    int sum = AIrand();
    for (int i = 0; i < self->mCount; i++)
    {
        sum += func_00125AD8(self->mRiders[i]);
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern "C" void func_00120D58(void* self);
extern "C" void func_00125958(void* self, int a1);
extern "C" void func_00117520(void* self, int a1);
extern "C" int func_0014F7A8(int i);
extern int D_00534B30[];

struct sRider_12B498
{
    char pad[0xB30];
    int fB30;
};

struct sOptEntry_12B498
{
    unsigned int f0;
    int x;
    int y;
};

struct sOptView_12B498
{
    sOptEntry_12B498 e[2];
    int f18;
};

// The unit declares D_005308B8 later with its own type; bind this view by asm label.
extern sOptView_12B498 D_005308B8_12B498 __asm__("D_005308B8");

static inline int OptBit_12B498(sOptView_12B498* o, int b)
{
    return (o->f18 >> b) & 1;
}

extern "C" void func_0012B498(void* self, void* obj, int i)
{
    int v = 1;
    if (OptBit_12B498(&D_005308B8_12B498, 3))
        v = 3;
    else if (OptBit_12B498(&D_005308B8_12B498, 0))
        v = 0;
    else
        if ((D_005308B8_12B498.e[i].f0 >> 5) & 1) v = 2;
    char* r = *(char**)((char*)obj + 0x18);
    *(int*)(r + 0x304) = v;
    func_00120D58(r);
    if ((D_005308B8_12B498.e[i].f0 >> 3) & 1)
        *(float*)(*(char**)((char*)obj + 0x18) + 0xB24) = 1.0f;
    if (OptBit_12B498(&D_005308B8_12B498, 4))
        *(int*)(*(char**)((char*)obj + 0x18) + 0xB28) = 2;
    if ((D_005308B8_12B498.e[i].f0 >> 4) & 1)
        func_00125958(*(void**)((char*)obj + 0x18), 0);
    else if (OptBit_12B498(&D_005308B8_12B498, 1))
        func_00125958(*(void**)((char*)obj + 0x18), 1);
    if (D_005308B8_12B498.e[i].f0 & 1)
        *(int*)(*(char**)((char*)obj + 0x18) + 0xB20) = 2;
    (*(sRider_12B498**)((char*)obj + 0x18))->fB30 = func_0014F7A8(i);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] != 0)
    {
        if (D_00534B30[1] != 0)
            *(int*)(*(char**)((char*)obj + 0x18) + 0xB34) = 8;
    }
    else if ((D_005308B8_12B498.e[i].f0 >> 1) & 1)
        *(int*)(*(char**)((char*)obj + 0x18) + 0xB34) = 1;
    char* m = *(char**)(*(char**)((char*)obj + 0x18) + 0x790);
    if ((D_005308B8_12B498.e[i].f0 >> 2) & 1)
        *(float*)(m + 0x1C4) = 0.5f;
    func_00117520(m, D_005308B8_12B498.e[i].x);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B698);
#ifdef SKIP_ASM
extern "C" void func_00120D58(void* self);
extern "C" void func_00125958(void* self, int a1);
extern "C" int func_0014F7E8();

struct sOptFlags_0012B698
{
    unsigned int f0;
    char pad4[0x14];
    int f18;
};
extern sOptFlags_0012B698 D_005308B8;

static inline int OptBit_0012B698(sOptFlags_0012B698* o, int b)
{
    return (o->f18 >> b) & 1;
}

extern "C" void func_0012B698(void* self, void* rider)
{
    int v = 1;
    if (OptBit_0012B698(&D_005308B8, 3))
        v = 3;
    else if (OptBit_0012B698(&D_005308B8, 0))
        v = 0;
    else
        if ((D_005308B8.f0 >> 5) & 1) v = 2;
    char* r = *(char**)((char*)rider + 0x18);
    *(int*)(r + 0x304) = v;
    func_00120D58(r);
    if ((D_005308B8.f0 >> 3) & 1)
        *(float*)(*(char**)((char*)rider + 0x18) + 0xB24) = 1.0f;
    if (OptBit_0012B698(&D_005308B8, 4))
        *(int*)(*(char**)((char*)rider + 0x18) + 0xB28) = 2;
    if (OptBit_0012B698(&D_005308B8, 1))
        func_00125958(*(void**)((char*)rider + 0x18), 1);
    *(int*)(*(char**)((char*)rider + 0x18) + 0xB30) = func_0014F7E8();
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B788);
#ifdef SKIP_ASM
extern "C" void func_00120E50(void*);

struct sAi12B788
{
    char pad0[0x28];
    void* items[20];
    int count;
};

extern "C" void func_0012B788(sAi12B788* self)
{
    int i;
    for (i = 0; i < self->count; i++)
    {
        func_00120E50(self->items[i]);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012B7F0);
#ifdef SKIP_ASM
extern "C" void func_002EF248(void* frame);

struct sVEntryWF { short delta; short index; void (*fn)(void*, void*, int); };
struct sVEntryWF2 { short delta; short index; void (*fn)(void*, void*); };

struct sAiObj12B7F0
{
    char pad0[0x40];
    char* mPlayers[2];
    char* mMission[5];
    char* mActors[7];
    int mCount;
    int mNumPlayers;
    int mNumMission;
    int mNumActors;
};

static inline void replayWriteObj(char* obj, void* frame)
{
    char* x = *(char**)(*(char**)(obj + 0x18) + 0x77C);
    sVEntryWF2* vt = *(sVEntryWF2**)(x + 0xDE8);
    vt[2].fn(x + vt[2].delta, frame);
}

extern "C" void func_0012B7F0(sAiObj12B7F0* self, void* frame)
{
    sVEntryWF* vt = *(sVEntryWF**)frame;
    vt[1].fn((char*)frame + vt[1].delta, self, 0x28);
    for (int i = 0; i < self->mNumPlayers; i++)
    {
        replayWriteObj(self->mPlayers[i], frame);
    }
    for (int i = 0; i < self->mNumMission; i++)
    {
        replayWriteObj(self->mMission[i], frame);
    }
    for (int i = 0; i < self->mNumActors; i++)
    {
        replayWriteObj(self->mActors[i], frame);
    }
    func_002EF248(frame);
}
#endif

//100%
INCLUDE_ASM("ai/ai", cAI_readFromReplayFrame);
#ifdef SKIP_ASM
extern "C" void cAI_forceAIState(void* self, int state);
extern "C" void cRenderStateMan_readFromReplayFrame(void* frame);

struct sVEntryRF { short delta; short index; void (*fn)(void*, void*, int); };
struct sVEntryRF2 { short delta; short index; void (*fn)(void*, void*); };

struct sAiObj12B948
{
    int mState;
    int mPrevState;
    char pad8[0x38];
    char* mPlayers[2];
    char* mMission[5];
    char* mActors[7];
    int mCount;
    int mNumPlayers;
    int mNumMission;
    int mNumActors;
    char pad88[0x10];
    int f98;
    int f9C;
};

static inline void replayReadObj(char* obj, void* frame)
{
    char* x = *(char**)(*(char**)(obj + 0x18) + 0x77C);
    sVEntryRF2* vt = *(sVEntryRF2**)(x + 0xDE8);
    vt[3].fn(x + vt[3].delta, frame);
}

extern "C" void cAI_readFromReplayFrame(sAiObj12B948* self, void* frame)
{
    sVEntryRF* vt = *(sVEntryRF**)frame;
    vt[2].fn((char*)frame + vt[2].delta, self, 0x28);
    int state = self->mState;
    cAI_forceAIState(self, self->mPrevState);
    self->f9C = self->f98;
    cAI_forceAIState(self, state);
    for (int i = 0; i < self->mNumPlayers; i++)
    {
        replayReadObj(self->mPlayers[i], frame);
    }
    for (int i = 0; i < self->mNumMission; i++)
    {
        replayReadObj(self->mMission[i], frame);
    }
    for (int i = 0; i < self->mNumActors; i++)
    {
        replayReadObj(self->mActors[i], frame);
    }
    cRenderStateMan_readFromReplayFrame(frame);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012BAC0);
#ifdef SKIP_ASM
extern "C" void func_0012BAC0(void* self, int* src)
{
    int* dst = (int*)((char*)self + 0x20);
    for (int i = 0; i < 2; i++)
    {
        dst[i] = src[i];
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012BAF0);
#ifdef SKIP_ASM
extern "C" void func_0012BAF0(void* self, int* dst)
{
    int* src = (int*)((char*)self + 0x20);
    for (int i = 0; i < 2; i++)
    {
        dst[i] = src[i];
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012BB20);
#ifdef SKIP_ASM
extern signed char D_00535C12[];
extern "C" void func_00258F20(void* self, int t, int seed);

struct sAi_12BB20
{
    int state;          // 0x00
    int f4;
    int timer;          // 0x08
    int fC[3];
    int countdown;      // 0x18
    char pad1C[0x24];
    char* riders[15];   // 0x40
    int count;          // 0x7C
};

static inline bool riderOk_12BB20(char* rider)
{
    return *(float*)(*(char**)(rider + 0x18) + 0x470) >= 0.0f;
}

extern "C" void func_0012BB20(sAi_12BB20* self)
{
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B30[0] == 0)
        return;
    int seed = 0;
    if (self->timer % 60 == 0)
        seed = func_0012B420((sAiObj128A48*)self);
    int st = self->state;
    if (st != 5) {
        if (st != 3)
            return;
        if (*(int*)(*(char**)((char*)D_004A28A8 + 0x84) + 0x214) != st)
            return;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    signed char m = D_00535C12[0];
    if (m == 0 || m == 4) {
        int t = self->countdown;
        if (t >= 0) {
            if (t > 0) {
                t--;
                self->countdown = t;
                if (t <= 0) {
                    for (int i = 0; i < self->count; i++) {
                        bool ok = riderOk_12BB20(self->riders[i]);
                        if (!ok) {
                            *(int*)(*(char**)(self->riders[i] + 0x18) + 0x480) = 1;
                            func_00125108(*(void**)(self->riders[i] + 0x18));
                        }
                    }
                    func_0026FA50(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
                    self->countdown = -1;
                }
            }
        } else {
            if (self->timer <= 0xD32B && func_0012A250((sAiObj12A250*)self) == 0) {
                int n = self->count;
                for (int j = 0; j < n; j++) {
                    bool ok = riderOk_12BB20(self->riders[j]);
                    if (ok && *(int*)(D_004A2EEC + 0x8C) == 0 && *(int*)(D_004A2EEC + 0x48) == 0) {
                        int d = 0xD3A4 - self->timer;
                        if (d > 0x1C20) d = 0x1C20;
                        self->countdown = d;
                    }
                }
            }
            if (self->timer > 0xD3A3 && func_0012A250((sAiObj12A250*)self) == 0) {
                for (int i = 0; i < self->count; i++) {
                    bool ok = riderOk_12BB20(self->riders[i]);
                    if (!ok) {
                        *(int*)(*(char**)(self->riders[i] + 0x18) + 0x480) = 1;
                        func_00125108(*(void**)(self->riders[i] + 0x18));
                    }
                }
                func_0026FA50(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
                self->countdown = -1;
            }
        }
    }
    int v = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    int busy = v != 0 && v < 10;
    if (busy)
        return;
    if (self->timer % 60 == 0)
        func_00258F20(D_004A2EEC, self->timer, seed);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012BE20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void func_00311A50(void* anim);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

struct sQuat_12BE20
{
    float x, y, z, w;
    sQuat_12BE20() {}
    sQuat_12BE20(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

extern sQuat_12BE20 D_004FF130_12BE20 __asm__("D_004FF130");
extern sQuat_12BE20 D_004FF160_12BE20 __asm__("D_004FF160");

static inline sQuat_12BE20 AxisAngle_12BE20(const sQuat_12BE20& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sQuat_12BE20(s * axis.x, s * axis.y, s * axis.z, c);
}

extern "C" void func_0012BE20(void* self)
{
    char* r0 = *(char**)((char*)self + 0x14);
    *(int*)(r0 + 0x320) = *(int*)(r0 + 0x324);
    func_00311A50(*(void**)(*(char**)((char*)self + 0x14) + 0x784));
    char* r1 = *(char**)((char*)self + 0x14);
    *(int*)(*(char**)(r1 + 0x784) + 0x18) = *(int*)(r1 + 0x320);
    char* r = *(char**)((char*)self + 0x14);
    float a = 0.0f;
    if (*(int*)(r + 0x320) != 0) a = 3.1415927410125732f;
    char* anim = *(char**)(r + 0x784);
    *(sQuat_12BE20*)(anim + 0x30) = D_004FF130_12BE20;
    *(sQuat_12BE20*)(anim + 0x40) = AxisAngle_12BE20(D_004FF160_12BE20, -a);
    if (*(int*)self == 2)
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 1, 0, -1.0f);
    }
    else
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0, 0, -1.0f);
        *(int*)self = 0;
    }
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012BF68);
#ifdef SKIP_ASM
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" void func_0012C0C0(void* self, void* a1);
extern "C" void func_0012C130(void* self, void* a1);
extern "C" void func_0012C230(void* self, void* a1);
extern "C" void func_0012C408(void* self, void* a1);

extern "C" void func_0012BF68(void* self, void* a1)
{
    func_00114130(*(void**)((char*)self + 0x14), 0, 0);
    switch (*(int*)self)
    {
    case 0:
        func_0012C230(self, a1);
        break;
    case 1:
        func_0012C408(self, a1);
        break;
    case 2:
        func_0012C0C0(self, a1);
        break;
    case 3:
        func_0012C130(self, a1);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C028);
#ifdef SKIP_ASM
extern void* D_004A28A8;

extern "C" int func_0012C028(void* self)
{
    int r = 0;
    char* s = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    if (*(int*)s == 5)
    {
        r = *(int*)(*(char**)((char*)self + 0x14) + 0xB30) <= (int)(*(int*)(s + 0xC) * 0.01666666753590107f);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C078);
#ifdef SKIP_ASM
extern void* D_004A28A8;

extern "C" int func_0012C078(void* self)
{
    if (**(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) == 5)
        return 1;
    if (*(float*)(*(char**)((char*)self + 0x14) + 0x470) >= 0.0f)
        return 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C0C0);
#ifdef SKIP_ASM
struct sAiBits0012C0C0
{
    int pad : 12;
    int v : 6;
};

extern "C" void func_0012C0C0(void* self, void* a1)
{
    if (((sAiBits0012C0C0*)a1)->v * 0.032258063554763794f > 0.0f)
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 2, 0, -1.0f);
        *(int*)self = 3;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C130);
#ifdef SKIP_ASM
extern "C" void func_00113F88(void* rider, float a, float b);
int func_00312AA0(void* self, int i);
extern "C" float func_00312AB0(void* self, int i);
int func_0011FE98(void* self);
// PORT: prototype mismatch. func_0011FEC8/func_0011FE78 are defined with one param, but callers pass a mode in $a1.
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
void func_0011FE78_impl(void* self, int v) __asm__("func_0011FE78__FPv");

struct sVec4_12C130
{
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_12C130 vu0Scale_12C130(const sVec4_12C130& in, float s)
{
    sVec4_12C130 v = in;
    sVec4_12C130 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

extern "C" void func_0012C130(void* self, void* a1)
{
    func_00113F88(*(void**)((char*)self + 0x14), 1.0f, 0.0f);
    if (func_00312AA0(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 2) == 2)
    {
        if (func_0011FE98(*(void**)((char*)self + 0x14)) == 3)
        {
            if (func_00312AB0(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 2) > 0.5f)
            {
                char* rider = *(char**)((char*)self + 0x14);
                *(sVec4_12C130*)(rider + 0x1E0) = vu0Scale_12C130(*(sVec4_12C130*)(rider + 0x1B0), 555.5555419921875f);
                func_0011FE78_impl(*(void**)((char*)self + 0x14), 0);
            }
        }
    }
    else
    {
        if (func_0011FE98(*(void**)((char*)self + 0x14)) == 1)
        {
            func_0011FEC8_impl(*(void**)((char*)self + 0x14), 4);
        }
        else
        {
            func_0011FEC8_impl(*(void**)((char*)self + 0x14), 0);
        }
        *(int*)self = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C230);
#ifdef SKIP_ASM
extern "C" float func_00115AB0(void* rider);
extern "C" int func_0012C028(void* self);
extern "C" int func_0012C078(void* self);

struct sAiBits0012C230
{
    int pad : 12;
    int v : 6;
};

extern "C" void func_0012C230(void* self, void* a1)
{
    float fy = ((sAiBits0012C230*)a1)->v * 0.032258063554763794f;
    float old = *(float*)((char*)self + 0x10);
    float target;
    if (fy > 0.0f)
        target = 0.6200000047683716f;
    else if (fy < 0.0f)
        target = 0.0f;
    else
        target = 0.3100000023841858f;
    float v = func_00115AB0(*(void**)((char*)self + 0x14));
    char* r = *(char**)((char*)self + 0x14);
    *(float*)(r + 0x2CC) = 0.0f;
    *(float*)(r + 0x2D0) = v;
    *(float*)(r + 0x2C8) = v;
    float d = __builtin_fabsf(target - *(float*)((char*)self + 0x10));
    float rate;
    if (d >= 0.20000000298023224f)
        rate = d * 4.5f;
    else
        rate = 0.9000000357627869f;
    float step = rate * 0.01666666753590107f;
    float t = *(float*)((char*)self + 0x10);
    float n;
    if (t > target + step)
    {
        n = t - step;
    }
    else
    {
        n = target;
        if (t < target - step)
            n = t + step;
    }
    *(float*)((char*)self + 0x10) = n;
    *(float*)((char*)self + 0x4) = *(float*)((char*)self + 0x4) + 0.01666666753590107f;
    if (old != n)
    {
        *(int*)((char*)self + 0x4) = 0;
        if (old < n)
            *(float*)((char*)self + 0xC) = n;
        else
            *(float*)((char*)self + 0x8) = n;
    }
    if (func_0012C028(self) == 0) return;
    if (func_0012C078(self) == 0) return;
    float z = 0.0f;
    if (target > 0.5f && *(float*)((char*)self + 0x4) < 0.4000000059604645f)
    {
        float e = *(float*)((char*)self + 0x4);
        z = (*(float*)((char*)self + 0xC) - *(float*)((char*)self + 0x8)) * 2027.77783203125f * (1.0f - *(float*)((char*)self + 0x10)) / (e + 1.0f);
    }
    if (z < 555.5555419921875f)
        z = 555.5555419921875f;
    *(float*)((char*)self + 0xC) = z;
    *(int*)self = 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C408);
#ifdef SKIP_ASM
extern "C" float func_00115AB0(void* rider);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" void func_0012C408(void* self, void* a1)
{
    float v = func_00115AB0(*(void**)((char*)self + 0x14));
    char* r = *(char**)((char*)self + 0x14);
    *(float*)(r + 0x2CC) = 0.0f;
    *(float*)(r + 0x2D0) = v;
    *(float*)(r + 0x2C8) = v;
    float d = 0.015000001527369022f;
    float t = *(float*)((char*)self + 0x10);
    float n;
    if (t > 1.0149999856948853f)
    {
        n = t - d;
    }
    else
    {
        n = 1.0f;
        if (t < 0.9850000143051147f)
            n = t + d;
    }
    *(float*)((char*)self + 0x10) = n;
    func_00113F88(*(void**)((char*)self + 0x14), 1.0f, 0.0f);
    if (func_0011FE98(*(void**)((char*)self + 0x14)) == 3 && *(float*)((char*)self + 0x10) >= 0.6200000047683716f)
    {
        char* rider = *(char**)((char*)self + 0x14);
        *(sVec4_12C130*)(rider + 0x1E0) = vu0Scale_12C130(*(sVec4_12C130*)(rider + 0x1B0), *(float*)((char*)self + 0xC));
        func_0011FE78_impl(*(void**)((char*)self + 0x14), 0);
    }
    if (*(float*)((char*)self + 0x10) == 1.0f)
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 6, 0, -1.0f);
        if (func_0011FE98(*(void**)((char*)self + 0x14)) == 1)
        {
            func_0011FEC8_impl(*(void**)((char*)self + 0x14), 4);
        }
        else
        {
            func_0011FEC8_impl(*(void**)((char*)self + 0x14), 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C558);
#ifdef SKIP_ASM
struct sAiVEntry12C558 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012C558(void* self, void* obj)
{
    sAiVEntry12C558* vt = *(sAiVEntry12C558**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C590);
#ifdef SKIP_ASM
struct sAiVEntry12C590 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012C590(void* self, void* obj)
{
    sAiVEntry12C590* vt = *(sAiVEntry12C590**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C5C8);
#ifdef SKIP_ASM
extern "C" float func_00119368(void* self, int a1);
extern float D_004A4C8C;

struct sAiVec4_12C5C8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float aiLength_12C5C8(const sAiVec4_12C5C8& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

struct sAiObj12C5C8
{
    int m0;
    char* mRider;
};

extern "C" void func_0012C5C8(sAiObj12C5C8* self)
{
    func_00119368(*(void**)(self->mRider + 0x790), 1);
    char* r = self->mRider;
    if (D_004A4C8C < aiLength_12C5C8(*(sAiVec4_12C5C8*)(r + 0x1E0)))
    {
        self->m0 = 0;
        return;
    }
    if (*(float*)(r + 0x2DC) != 0.0f)
    {
        self->m0 = 0;
        return;
    }
    if (*(float*)(r + 0x378) < 0.800000011920929f)
    {
        self->m0 = 0;
        return;
    }
    self->m0 = 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C678);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0010E028(void* self, int mode, float t);
extern "C" void func_00113E80(void*, float);
extern "C" void func_00113F88(void* rider, float a, float b);
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" int func_00114CC0(void* rider);
extern "C" void func_00115B58(void*);
int func_0011FE98(void* self);
extern "C" int func_00311AE8(void*, int);
int func_00312AA0(void* self, int i);
extern float D_004A4C8C;
extern char D_004FF120[];

struct sVec4_12C678
{
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector *= scalar).
static inline void vu0ScaleEq_12C678(sVec4_12C678& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(v), "=&r"(t)
        : "m"(v), "f"(s));
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float aiLength_12C678(const sVec4_12C678& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only inline asm (float absolute value).
static inline float aiAbs_12C678(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct sAiObj12C678
{
    int mState;
    char* mRider;
};

extern "C" void func_0012C678(sAiObj12C678* self)
{
    int anim = func_00312AA0(*(void**)(self->mRider + 0x784), 2);
    int prev = anim;
    char* r = self->mRider;
    *(float*)(r + 0x200) = 0.03333333507180214f;
    *(float*)(r + 0x204) = *(float*)(r + 0x1F0);
    switch (self->mState)
    {
    case 0:
        if (anim == 0x15 || (*(float*)(self->mRider + 0x2DC) == 0.0f && func_00114CC0(self->mRider)))
        {
            anim = 0x15;
            func_00113F88(self->mRider, 0.0f, 0.0f);
        }
        else
        {
            if (func_0011FE98(self->mRider) != 0)
                break;
            float zero = 0.0f;
            float t = -0.10000000149011612f;
            if (zero < *(float*)(self->mRider + 0x1F0))
                t = 0.10000000149011612f;
            anim = 0xB;
            func_00113E80(self->mRider, t);
            func_00114130(self->mRider, 0, 0);
            *(float*)(self->mRider + 0x2DC) = zero;
            if (*(float*)(self->mRider + 0x378) < 0.800000011920929f)
            {
                func_00113F88(self->mRider, zero, zero);
            }
            else
            {
                vu0ScaleEq_12C678(*(sVec4_12C678*)(self->mRider + 0x1E0), 0.9700000286102295f);
                if (aiAbs_12C678(*(float*)(self->mRider + 0x214)) == 1.0f ||
                    aiLength_12C678(*(sVec4_12C678*)(self->mRider + 0x1E0)) < D_004A4C8C)
                {
                    self->mState = 1;
                }
                else
                {
                    func_00113F88(self->mRider, zero, 1.0f);
                }
            }
        }
        break;
    case 1:
    {
        float zero = 0.0f;
        func_00113F88(self->mRider, zero, zero);
        func_00113E80(self->mRider, zero);
        vu0ScaleEq_12C678(*(sVec4_12C678*)(self->mRider + 0x1E0), 0.9300000071525574f);
        if (aiAbs_12C678(*(float*)(self->mRider + 0x214)) < 0.20000000298023224f &&
            *(float*)(self->mRider + 0x1F0) == zero)
        {
            self->mState = 2;
            anim = 4;
            if (*(int*)(self->mRider + 0x100) == 1)
                func_0010E028(self->mRider, 1, zero);
            else
                func_0010E028(self->mRider, 4, zero);
        }
        break;
    }
    case 2:
        *(sVec4_12C678*)(self->mRider + 0x1E0) = *(sVec4_12C678*)D_004FF120;
        *(float*)(*(char**)(self->mRider + 0x784) + 0x1C) = 0.75f;
        func_00115B58(self->mRider);
        *(float*)(*(char**)(self->mRider + 0x784) + 0x1C) = 1.0f;
        if (func_00311AE8(*(void**)(self->mRider + 0x784), 1) == 0)
        {
            *(float*)(self->mRider + 0x470) = *(float*)(self->mRider + 0x470) >? 10.0f;
            self->mState = 3;
        }
        break;
    case 3:
        *(sVec4_12C678*)(self->mRider + 0x1E0) = *(sVec4_12C678*)D_004FF120;
        break;
    }
    if (anim != prev)
        cRiderAnimBase_play(*(void**)(self->mRider + 0x784), anim, 0, -1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C9C0);
#ifdef SKIP_ASM
struct sVEntry0012C9C0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012C9C0(void* self, void* obj)
{
    sVEntry0012C9C0* vt = *(sVEntry0012C9C0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x4);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012C9F8);
#ifdef SKIP_ASM
struct sVEntry0012C9F8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012C9F8(void* self, void* obj)
{
    sVEntry0012C9F8* vt = *(sVEntry0012C9F8**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x4);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012CA30);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_0029E578(void* self, void* a1);
extern "C" int func_00311AE8(void*, int);
extern "C" void func_002708F0(void* self, int key, int id);
extern "C" void func_00309990(void* self);
extern void* D_004A28A8;
extern void* D_004A3DD8;
extern char D_004FF120[];

struct sVec4_12CA30
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVecPair_12CA30
{
    sVec4_12CA30 a;
    sVec4_12CA30 b;
};

extern "C" void func_00136D40(char* self, sVec4_12CA30* a, sVec4_12CA30* b, sVecPair_12CA30* c);

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vu0AddEq_12CA30(sVec4_12CA30& dst, const sVec4_12CA30& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

struct sAiObj12CA30
{
    int f0;                 // 0x00
    char pad4[0xC];
    sVecPair_12CA30 m10;    // 0x10
    sVecPair_12CA30 m30;    // 0x30
    char pad50[0x4];
    int f54;                // 0x54
    char pad58[0x18];
    int f70;                // 0x70
    char pad74[0xC];
    char* mRider;           // 0x80
};

extern "C" void func_0012CA30(sAiObj12CA30* self)
{
    sVecPair_12CA30* p30 = &self->m30;
    *(int*)(self->mRider + 0x2EC) = 0;
    *(int*)(self->mRider + 0x2E8) = 0;
    self->f54 = 0;
    self->f70 = 0;
    func_0029E578(func_0028B180(), self->mRider);
    char* r = self->mRider;
    self->m10 = (*(sVecPair_12CA30**)(*(char**)(r + 0x780) + 0x2C))[*(int*)(r + 0x89C)];
    self->m30 = (*(sVecPair_12CA30**)(*(char**)(r + 0x780) + 0x2C))[*(int*)(r + 0x8A4)];
    vu0AddEq_12CA30(self->m10.a, *(sVec4_12CA30*)(self->mRider + 0x9D0));
    vu0AddEq_12CA30(self->m30.a, *(sVec4_12CA30*)(self->mRider + 0x9D0));
    self->f0 = 0;
    if (func_00311AE8(*(void**)(self->mRider + 0x784), 2) == 0x16)
    {
        func_00136D40(*(char**)(self->mRider + 0x77C) + 0x30, (sVec4_12CA30*)(self->mRider + 0x1E0), (sVec4_12CA30*)D_004FF120, p30);
        *(int*)(self->mRider + 0x318) = 0;
    }
    func_002708F0(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28), *(int*)(self->mRider + 0x86C), *(int*)(self->mRider + 0x790) + 0xFC);
    func_00309990(D_004A3DD8);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012CB68);
#ifdef SKIP_ASM
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" void* func_0028B180();
extern "C" void func_0029E970(void* snd, void* rider);
extern "C" void func_0029E590(void* snd, void* rider, float t);
extern "C" void func_0012CD20_CB68(void* self) __asm__("func_0012CD20");
extern "C" void func_0012D4E8(void* self);
extern "C" void func_0012D160(void* self);
extern "C" void func_0012D848(void* self);
extern "C" void func_0012D9D8(void* self);

struct sAiObj12CB68
{
    int f0;                 // 0x00
    char pad4[0x6C];
    float f70;              // 0x70
    char pad74[0xC];
    char* mRider;           // 0x80
};

// Decays or charges the AI's 0x70 meter (updating its sound), then runs the current state's handler.
extern "C" void func_0012CB68(sAiObj12CB68* self, int* input)
{
    func_00114130(self->mRider, 0, 0);
    if (func_00116120(self->mRider, (*input >> 12) & 1, 0)) {
        return;
    }
    bool b = self->f0 == 3;
    if (!b) {
        float t = self->f70;
        float v;
        if (t > 0.00416986271739006f) {
            v = t - 0.00416986271739006f;
        } else {
            v = 0.0f;
            if (t < -0.00416986271739006f) {
                v = t + 0.00416986271739006f;
            }
        }
        self->f70 = v;
        if (*input & 0x2000) {
            float rate = 17.00261688232422f;
            switch (*(int*)(self->mRider + 0xB20)) {
            case 0:
                rate = 8.001495361328125f;
                break;
            case 2:
                rate = 34.00276565551758f;
                break;
            }
            self->f70 += rate * 0.01666666753590107f;
            if (self->f70 >= 1.0f) {
                func_0029E970(func_0028B180(), self->mRider);
            } else {
                func_0029E590(func_0028B180(), self->mRider, self->f70);
            }
        }
    }
    switch (self->f0) {
    case 0:
        func_0012CD20_CB68(self);
        break;
    case 1:
        func_0012D4E8(self);
        break;
    case 2:
        func_0012D160(self);
        break;
    case 3:
        func_0012D848(self);
        break;
    case 4:
        func_0012D9D8(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012CD20);
#ifdef SKIP_ASM
extern "C" int func_00312AE8(void* self, int i);
extern "C" char* func_00311B20(void*, int);
extern "C" float func_00312AB0(void* self, int i);
extern "C" int func_00311AE8(void*, int);
extern "C" int func_00312AE8(void* self, int i);
extern "C" char* func_00311B20(void*, int);
extern "C" float func_00312AB0(void* self, int i);
extern "C" int func_00311AE8(void*, int);
extern "C" void func_0012DA88(void* self);
extern "C" void func_00136DE0(char* self, void* vel, void* angvel);
extern "C" void func_00296868(void* mgr, void* self);
extern "C" void func_00296E80(void* mgr, void* self);

struct sV_12CD20
{
    float x, y, z, w;
    sV_12CD20() {}
    sV_12CD20(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sVP_12CD20
{
    sV_12CD20 a;
    sV_12CD20 b;
};

struct sAiObj12CD20
{
    int f0;              // 0x00
    char pad4[0xC];
    sVP_12CD20 m10;      // 0x10
    sVP_12CD20 m30;      // 0x30
    float f50;           // 0x50
    char pad54[0x2C];
    char* mRider;        // 0x80
};

// PORT: PS2-only VU0 inline asm (a - b).
static inline sV_12CD20 Sub_12CD20(const sV_12CD20& a, const sV_12CD20& b)
{
    sV_12CD20 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sV_12CD20 Scale_12CD20(const sV_12CD20& v, float s)
{
    sV_12CD20 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sV_12CD20 QuatMul_12CD20(const sV_12CD20& a, const sV_12CD20& b)
{
    sV_12CD20 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline sV_12CD20 Conj_12CD20(const sVP_12CD20& p)
{
    sV_12CD20 r;
    r.w = p.b.w;
    r.x = p.b.x;
    r.y = p.b.y;
    r.z = p.b.z;
    r.x = -r.x;
    r.y = -r.y;
    r.z = -r.z;
    return r;
}

extern "C" void func_0012CD20(sAiObj12CD20* self)
{
    char* r = self->mRider;
    sVP_12CD20* nodes = *(sVP_12CD20**)(*(char**)(r + 0x780) + 0x2C);
    sVP_12CD20* p1 = &nodes[*(int*)(r + 0x89C)];
    sVP_12CD20* p2 = &nodes[*(int*)(r + 0x8A4)];
    float t = func_00312AB0(*(void**)(r + 0x784), 2);
    if (func_00312AE8(*(void**)(self->mRider + 0x784), 2))
    {
        char* an = func_00311B20(*(void**)(self->mRider + 0x784), 2);
        float rate = *(float*)(an + 0x90);
        float s = rate / ((t - self->f50) * *(float*)(an + 0x10));
        sV_12CD20 vel = Scale_12CD20(Scale_12CD20(Sub_12CD20(p1->a, self->m10.a), *(float*)(*(char**)(self->mRider + 0x784) + 0x1C)), s);
        float s2 = s + s;
        sV_12CD20 d = Sub_12CD20(p1->b, self->m10.b);
        sV_12CD20 q = QuatMul_12CD20(d, Conj_12CD20(*p1));
        sV_12CD20 angvel = Scale_12CD20(sV_12CD20(q.x, q.y, q.z, 0.0f), s2);
        func_00136DE0(*(char**)(self->mRider + 0x77C) + 0x30, self->mRider + 0x1E0, &angvel);
        if (func_00311AE8(*(void**)(self->mRider + 0x784), 2) == 0x17)
        {
            vel = Scale_12CD20(Scale_12CD20(Sub_12CD20(p2->a, self->m30.a), *(float*)(*(char**)(self->mRider + 0x784) + 0x1C)), s);
            d = Sub_12CD20(p2->b, self->m30.b);
            q = QuatMul_12CD20(d, Conj_12CD20(*p2));
            angvel = Scale_12CD20(sV_12CD20(q.x, q.y, q.z, 0.0f), s2);
            func_00136D40(*(char**)(self->mRider + 0x77C) + 0x30, (sVec4_12CA30*)&vel, (sVec4_12CA30*)&angvel, (sVecPair_12CA30*)p2);
        }
        if (*(int*)(*(char**)(self->mRider + 0x77C) + 0x30) == 1)
        {
            self->f0 = 1;
            func_0012DA88(self);
        }
        else
        {
            self->f0 = 2;
            func_0012DA88(self);
            if (func_00311AE8(*(void**)(self->mRider + 0x784), 2) == 0x1D ||
                func_00311AE8(*(void**)(self->mRider + 0x784), 2) == 0x19)
                func_00296868(func_0028B180(), self);
            else
                func_00296E80(func_0028B180(), self);
        }
        return;
    }
    if (t < 0.949999988079071f)
    {
        self->f50 = t;
        self->m10 = *p1;
        self->m30 = *p2;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012D160);
#ifdef SKIP_ASM
extern "C" void func_0010F280(void* rider, int flag);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" void func_0012DCB0(void* self);
extern "C" void func_0012DD98(void* self);
extern "C" void func_0012DF48(void* self);
extern "C" void func_0012E010(void* self);
extern "C" float func_0012E528(void* self);
extern "C" void func_0015E360(void* obj, int mode, float a, float b);
extern "C" void* func_0028B180();
extern "C" void func_00296E20(void* mgr, void* rider);
extern "C" void func_00297438(void* mgr, void* rider);
extern "C" void func_0029F660(void* mgr, void* rider, int a, int b);
extern "C" int func_00311AE8(void*, int);
extern "C" int func_00312AE8(void* self, int i);
extern void* D_004A28A8;

struct sVEntry12D160 { short delta; short index; void (*fn)(void*, float); };

static inline bool aiOk_12D160(void* self)
{
    return *(float*)(*(char**)((char*)self + 0x80) + 0x470) >= 0.0f;
}

static inline int aiIsOne_12D160(char* r)
{
    return *(int*)(r + 0x150) == 1;
}

static inline float aiRatio_12D160(float v, float hi)
{
    float t = 0.0f;
    if (v >= 0.0f)
    {
        t = 1.0f;
        if (v <= hi)
            t = v / hi;
    }
    return t;
}

static inline void aiTail_12D160(void* self)
{
    func_00296E20(func_0028B180(), *(char**)((char*)self + 0x80));
    func_00297438(func_0028B180(), *(char**)((char*)self + 0x80));
}

extern "C" void func_0012D160(void* self)
{
    char* r = *(char**)((char*)self + 0x80);
    float speed = aiLength_12C5C8(*(sAiVec4_12C5C8*)(r + 0x1E0));
    if (*(int*)(r + 0x870) >= 0)
    {
        float v = speed * 0.035999998450279236f;
        float t = aiRatio_12D160(v, 100.0f);
        char* r2 = *(char**)((char*)self + 0x80);
        if (*(int*)(r2 + 0x87C) != 0)
        {
            func_0015E360(*(void**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84) + (*(int*)(r2 + 0x870) << 2) + 4), 4, t, 0.0f);
        }
    }
    float k = func_0012E528(self);
    {
        char* r3 = *(char**)((char*)self + 0x80);
        sVEntry12D160* vt = *(sVEntry12D160**)(r3 + 0x6C0);
        vt[18].fn(r3 + vt[18].delta, k * 0.5f);
    }
    if (*(int*)((char*)self + 0x54) != 0)
    {
        *(int*)((char*)self + 0x54) = 0;
        char* r4 = *(char**)((char*)self + 0x80);
        sVEntry12D160* vt = *(sVEntry12D160**)(r4 + 0x6C0);
        vt[17].fn(r4 + vt[17].delta, aiLength_12C5C8(*(sAiVec4_12C5C8*)((char*)self + 0x60)));
        return;
    }
    if (aiIsOne_12D160(*(char**)((char*)self + 0x80)) && speed < 27.77777862548828f)
    {
        func_0012E010(self);
        *(int*)self = 4;
        aiTail_12D160(self);
        return;
    }
    if (func_00312AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0 &&
        func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) != 0x1D &&
        func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) != 0x19)
        return;
    float lim = 694.4444580078125f;
    if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x1C)
        lim = 1666.666748046875f;
    int fast = *(float*)((char*)self + 0x70) >= 1.0f || aiOk_12D160(self);
    if ((!aiIsOne_12D160(*(char**)((char*)self + 0x80)) && speed < lim) || fast)
    {
        if (*(int*)(*(char**)((char*)self + 0x80) + 0x438) == 0x12 || aiIsOne_12D160(*(char**)((char*)self + 0x80)))
        {
            if (fast)
            {
                func_00116120(*(char**)((char*)self + 0x80), 0, 3);
                func_0010F280(*(char**)((char*)self + 0x80), 1);
            }
            else if (speed < 277.77777099609375f)
            {
                func_0012E010(self);
                *(int*)self = 4;
            }
        }
        else
        {
            func_0010F280(*(char**)((char*)self + 0x80), fast);
            if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x1C)
                func_0029F660(func_0028B180(), *(char**)((char*)self + 0x80), 1, 0);
            func_0012DF48(self);
            *(int*)self = 3;
        }
        aiTail_12D160(self);
    }
    else if (*(int*)(*(char**)(*(char**)((char*)self + 0x80) + 0x77C) + 0x30) == 1)
    {
        func_0012DCB0(self);
        *(int*)self = 1;
        aiTail_12D160(self);
    }
    else
    {
        if (func_00312AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) != 0)
            func_0012DD98(self);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012D4E8);
#ifdef SKIP_ASM
extern "C" void func_0010F280(void* rider, int flag);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" void func_0012DCB0(void* self);
extern "C" void func_0012DD98(void* self);
extern "C" void func_0012DE80(void* self);
extern "C" void func_0012E010(void* self);
extern "C" void func_0012E468(void* self);
extern "C" float func_0012E528(void* self);
extern "C" void* func_0028B180();
extern "C" void func_00296310(void* mgr, void* rider);
extern "C" void func_00296868(void* mgr, void* self);
extern "C" void func_00296E80(void* mgr, void* self);
extern "C" int func_00311AE8(void*, int);
extern "C" char* func_00311B20(void*, int);
extern "C" float func_00312AB0(void* self, int i);
extern "C" int func_00312AE8(void* self, int i);
extern "C" void func_00313CF0(void* self, int idx, float v);

struct sAiVec4_12D4E8
{
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float aiDot_12D4E8(const sAiVec4_12D4E8& a, const sAiVec4_12D4E8& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sAiVec4_12D4E8 aiScale_12D4E8(const sAiVec4_12D4E8& in, float s)
{
    sAiVec4_12D4E8 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(in), "f"(s));
    return r;
}

struct sVEntry12D4E8 { short delta; short index; void (*fn)(void*, float); };

static inline bool aiOk_12D4E8(void* self)
{
    return *(float*)(*(char**)((char*)self + 0x80) + 0x470) >= 0.0f;
}

static inline int aiIsOne_12D4E8(char* r)
{
    return *(int*)(r + 0x150) == 1;
}

extern "C" void func_0012D4E8(void* self)
{
    func_0012E528(self);
    if (*(int*)((char*)self + 0x54) != 0)
    {
        if (*(int*)(*(char**)(*(char**)((char*)self + 0x80) + 0x77C) + 0x30) == 0)
        {
            if (*(float*)(*(char**)((char*)self + 0x80) + 0x378) > 0.8999999761581421f &&
                aiDot_12D4E8(*(sAiVec4_12D4E8*)((char*)self + 0x60), *(sAiVec4_12D4E8*)(*(char**)((char*)self + 0x80) + 0x370)) <
                    aiLength_12C5C8(*(sAiVec4_12C5C8*)((char*)self + 0x60)) * -0.8999999761581421f)
            {
                func_0012E010(self);
                char* r2 = *(char**)((char*)self + 0x80);
                sAiVec4_12D4E8 v = aiScale_12D4E8(*(sAiVec4_12D4E8*)(r2 + 0x370),
                    aiDot_12D4E8(*(sAiVec4_12D4E8*)(r2 + 0x370), *(sAiVec4_12D4E8*)(r2 + 0x1E0)));
                *(sAiVec4_12D4E8*)(r2 + 0x1E0) = v;
                *(int*)self = 4;
            }
            else
            {
                if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x1D ||
                    func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x19)
                {
                    func_0012E468(self);
                    func_00296868(func_0028B180(), self);
                }
                else
                {
                    float t = func_00312AB0(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2);
                    func_0012DD98(self);
                    float a = *(float*)(func_00311B20(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) + 0x10);
                    func_00313CF0(func_00311B20(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2), 0, a * t);
                    func_00296E80(func_0028B180(), self);
                }
                *(int*)self = 2;
            }
            func_00296310(func_0028B180(), *(void**)((char*)self + 0x80));
        }
        *(int*)((char*)self + 0x54) = 0;
        char* r3 = *(char**)((char*)self + 0x80);
        sVEntry12D4E8* vt = *(sVEntry12D4E8**)(r3 + 0x6C0);
        vt[17].fn(r3 + vt[17].delta, aiLength_12C5C8(*(sAiVec4_12C5C8*)((char*)self + 0x60)));
        return;
    }
    if (func_00312AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) != 0 ||
        func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x1D ||
        func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x19)
    {
        int fast = *(float*)((char*)self + 0x70) >= 1.0f || aiOk_12D4E8(self);
        if (fast)
        {
            if (!aiIsOne_12D4E8(*(char**)((char*)self + 0x80)))
            {
                func_0010F280(*(char**)((char*)self + 0x80), fast);
                func_0012DE80(self);
                *(int*)self = 3;
            }
            else
            {
                func_00116120(*(char**)((char*)self + 0x80), 0, 3);
                func_0010F280(*(void**)((char*)self + 0x80), 1);
            }
        }
        else if (*(int*)(*(char**)(*(char**)((char*)self + 0x80) + 0x77C) + 0x30) == 0)
        {
            func_0012DD98(self);
            *(int*)self = 2;
        }
        else if (func_00312AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) != 0)
        {
            func_0012DCB0(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012D848);
#ifdef SKIP_ASM
extern "C" int func_00312AE8(void* self, int i);
extern "C" void func_002948D0(void* mgr, void* rider, float v);
extern "C" void func_00119E38(void* p, int flip, int c);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

struct sVEntry12D848 { short delta; short index; void (*fn)(void*, float); };

extern "C" void func_0012D848(void* self)
{
    if (*(int*)((char*)self + 0x54) != 0)
    {
        *(int*)((char*)self + 0x54) = 0;
        char* r = *(char**)((char*)self + 0x80);
        sVEntry12D848* vt = *(sVEntry12D848**)(r + 0x6C0);
        vt[17].fn(r + vt[17].delta, aiLength_12C5C8(*(sAiVec4_12C5C8*)((char*)self + 0x60)));
        func_002948D0(func_0028B180(), *(void**)((char*)self + 0x80), 0.0f);
    }
    char* r = *(char**)((char*)self + 0x80);
    if (*(int*)(*(char**)(r + 0x77C) + 0x30) == 0)
    {
        sVEntry12D848* vt = *(sVEntry12D848**)(r + 0x6C0);
        char* thisp = r + vt[18].delta;
        float t = 1.0f - func_00312AB0(*(void**)(r + 0x784), 2);
        vt[18].fn(thisp, t + t);
    }
    if (func_00312AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) != 0)
    {
        char* r2 = *(char**)((char*)self + 0x80);
        if (*(int*)(*(char**)(r2 + 0x77C) + 0x30) == 0)
        {
            cRiderAnimBase_play(*(void**)(r2 + 0x784), 5, 0, -1.0f);
            func_0011FEC8_impl(*(void**)((char*)self + 0x80), 0);
            func_0011FE78_impl(*(void**)((char*)self + 0x80), 0);
        }
        else
        {
            func_00119E38(*(void**)(r2 + 0x790), *(int*)(r2 + 0x320) != *(int*)(r2 + 0x324), 0);
            cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 0x11F, 0, -1.0f);
            func_0011FEC8_impl(*(void**)((char*)self + 0x80), 5);
            func_0011FE78_impl(*(void**)((char*)self + 0x80), 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012D9D8);
#ifdef SKIP_ASM
extern "C" void func_0010F280(void* rider, int flag);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" int func_00312AE8(void* self, int i);

static inline int AiCheck_0012D9D8(char* rider)
{
    return *(float*)(rider + 0x470) >= 0.0f;
}

extern "C" void func_0012D9D8(void* self)
{
    int flag = 0;
    if (*(float*)((char*)self + 0x70) >= 1.0f || AiCheck_0012D9D8(*(char**)((char*)self + 0x80)))
    {
        flag = 1;
    }
    if (func_00312AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) || flag)
    {
        func_0010F280(*(void**)((char*)self + 0x80), flag);
        func_00116120(*(void**)((char*)self + 0x80), 0, 2);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012DA88);
#ifdef SKIP_ASM
int func_00312AA0(void* anim, int layer);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
// Maps the rider's layer-2 animation to its base (or alternate) variant and replays it.
extern "C" void func_0012DA88(void* self)
{
    bool b = *(int*)self == 1;
    int cur = func_00312AA0(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2);
    int next = cur;
    switch (cur) {
    case 0x148:
        next = b ? 0x175 : 0x16A;
        break;
    case 0x149:
        next = b ? 0x176 : 0x16B;
        break;
    case 0x14A:
        next = b ? 0x177 : 0x16C;
        break;
    case 0x14B:
        next = b ? 0x17B : 0x170;
        break;
    case 0x14C:
        next = b ? 0x179 : 0x16E;
        break;
    case 0x14D:
        next = b ? 0x17A : 0x16F;
        break;
    case 0x14E:
        next = b ? 0x17D : 0x172;
        break;
    case 0x14F:
        next = b ? 0x17E : 0x173;
        break;
    case 0x150:
        next = b ? 0x178 : 0x16D;
        break;
    case 0x151:
        next = b ? 0x17C : 0x171;
        break;
    case 0x152:
        next = b ? 0x175 : 0x16A;
        break;
    case 0x153:
        next = b ? 0x176 : 0x16B;
        break;
    case 0x154:
        next = b ? 0x177 : 0x16C;
        break;
    case 0x155:
        next = b ? 0x17B : 0x170;
        break;
    case 0x156:
        next = b ? 0x179 : 0x16E;
        break;
    case 0x157:
        next = b ? 0x17E : 0x173;
        break;
    case 0x158:
        next = b ? 0x17C : 0x171;
        break;
    case 0x159:
        next = b ? 0x178 : 0x16D;
        break;
    case 0x15A:
        next = b ? 0x17A : 0x16F;
        break;
    case 0x15B:
        next = b ? 0x17D : 0x172;
        break;
    case 0x15C:
        next = b ? 0x17B : 0x170;
        break;
    case 0x15D:
        next = b ? 0x17C : 0x171;
        break;
    case 0x15E:
        next = b ? 0x177 : 0x16C;
        break;
    case 0x15F:
        next = b ? 0x179 : 0x16E;
        break;
    case 0x160:
        next = b ? 0x17E : 0x173;
        break;
    case 0x161:
        next = b ? 0x17B : 0x170;
        break;
    case 0x162:
        next = b ? 0x17B : 0x170;
        break;
    case 0x163:
        next = b ? 0x17D : 0x172;
        break;
    case 0x164:
        next = b ? 0x176 : 0x16B;
        break;
    case 0x165:
        next = b ? 0x175 : 0x16A;
        break;
    case 0x166:
        next = b ? 0x17B : 0x170;
        break;
    case 0x167:
        next = b ? 0x17D : 0x172;
        break;
    case 0x168: case 0x169:
        next = b ? 0x17F : 0x174;
        break;
    }
    if (next != cur) {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), next, 0, -1.0f);
        func_0012E528(self);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012DCB0);
#ifdef SKIP_ASM
int func_00312AA0(void* anim, int layer);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
// Picks the rider's layer-2 follow-up animation and replays it.
extern "C" void func_0012DCB0(void* self)
{
    int cur = func_00312AA0(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2);
    int next = cur;
    bool b = *(int*)(*(char**)((char*)self + 0x80) + 0x150) == 1;
    if (!b) {
        switch (cur) {
        case 0x16A: next = 0x175; break;
        case 0x16B: next = 0x176; break;
        case 0x16C: next = 0x177; break;
        case 0x16D: next = 0x178; break;
        case 0x16E: next = 0x179; break;
        case 0x16F: next = 0x17A; break;
        case 0x170: case 0x180: next = 0x17B; break;
        case 0x171: case 0x181: next = 0x17C; break;
        case 0x172: case 0x182: next = 0x17D; break;
        case 0x173: case 0x183: next = 0x17E; break;
        case 0x174: case 0x175: case 0x176: case 0x177: case 0x178: case 0x179:
        case 0x17A: case 0x17B: case 0x17C: case 0x17D: case 0x17E: case 0x17F:
            break;
        }
    } else {
        next = 0x17F;
    }
    if (next != cur) {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), next, 0, -1.0f);
        func_0012E528(self);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012DD98);
#ifdef SKIP_ASM
// Reverse of func_0012DCB0: maps follow-up animations back to their base.
extern "C" void func_0012DD98(void* self)
{
    int cur = func_00312AA0(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2);
    int next = cur;
    bool b = *(int*)(*(char**)((char*)self + 0x80) + 0x150) == 1;
    if (!b) {
        switch (cur) {
        case 0x175: next = 0x16A; break;
        case 0x176: next = 0x16B; break;
        case 0x177: next = 0x16C; break;
        case 0x178: next = 0x16D; break;
        case 0x179: next = 0x16E; break;
        case 0x17A: next = 0x16F; break;
        case 0x17B: case 0x180: next = 0x170; break;
        case 0x17C: case 0x181: next = 0x171; break;
        case 0x17D: case 0x182: next = 0x172; break;
        case 0x17E: case 0x183: next = 0x173; break;
        case 0x17F:
            break;
        }
    } else {
        next = 0x174;
    }
    if (next != cur) {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), next, 0, -1.0f);
        func_0012E528(self);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012DE80);
#ifdef SKIP_ASM
int func_00312AA0(void* anim, int layer);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
// Remaps the rider's current layer-2 animation to its follow-up and plays it.
extern "C" void func_0012DE80(void* self)
{
    int cur = func_00312AA0(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2);
    int next = cur;
    switch (cur) {
    case 0x175:
        next = 0x18F;
        break;
    case 0x176:
        next = 0x190;
        break;
    case 0x177:
        next = 0x191;
        break;
    case 0x178:
        next = 0x192;
        break;
    case 0x179:
        next = 0x193;
        break;
    case 0x17A:
        next = 0x194;
        break;
    case 0x17B:
        next = 0x195;
        break;
    case 0x17C:
        next = 0x196;
        break;
    case 0x17D:
        next = 0x197;
        break;
    case 0x17E:
        next = 0x198;
        break;
    }
    if (next != cur) {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), next, 0, -1.0f);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012DF48);
#ifdef SKIP_ASM
int func_00312AA0(void* anim, int layer);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
// Remaps the rider's current layer-2 animation to its follow-up and plays it.
extern "C" void func_0012DF48(void* self)
{
    int cur = func_00312AA0(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2);
    int next = cur;
    switch (cur) {
    case 0x16A:
        next = 0x185;
        break;
    case 0x16B:
        next = 0x186;
        break;
    case 0x16C:
        next = 0x187;
        break;
    case 0x16D:
        next = 0x188;
        break;
    case 0x16E:
        next = 0x189;
        break;
    case 0x16F:
        next = 0x18A;
        break;
    case 0x170: case 0x180:
        next = 0x18B;
        break;
    case 0x171: case 0x181:
        next = 0x18C;
        break;
    case 0x172: case 0x182:
        next = 0x18D;
        break;
    case 0x173: case 0x183:
        next = 0x18E;
        break;
    case 0x174: case 0x175: case 0x176: case 0x177: case 0x178: case 0x179: case 0x17A: case 0x17B: case 0x17C: case 0x17D: case 0x17E: case 0x17F:
        break;
    }
    if (next != cur) {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), next, 0, -1.0f);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E010);
#ifdef SKIP_ASM
extern "C" void func_00312660(void* buf, void* anim, int id, int a3, float t);
extern "C" void func_0030ECD8(void* xf, void* model, void* buf, int a3);
extern "C" void cRiderAnimBase_changeOrientationOffset(void* self, void* xf);
extern int D_004A4C00;
extern "C" void cRider_updateOrientationImplicit(void*);

struct sXf_12E010
{
    sQuat_12BE20 pos;
    sQuat_12BE20 rot;
};

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sQuat_12BE20 QuatMul_12E010(const sQuat_12BE20& a, const sQuat_12BE20& b)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sQuat_12BE20 Sub_12E010(const sQuat_12BE20& a, const sQuat_12BE20& b)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sQuat_12BE20 Add_12E010(const sQuat_12BE20& a, const sQuat_12BE20& b)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v rotated by quaternion q).
static inline sQuat_12BE20 Rot_12E010(const sQuat_12BE20& q, const sQuat_12BE20& v)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsub.w    $vf8, $vf8, $vf8\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vopmsub.xyz $vf7, $vf6, $vf4\n"
        "vmulaw.xyz ACC, $vf5, $vf0w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf7, $vf0w\n"
        "vmaddw.xyz $vf8, $vf7, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(r)
        : "m"(q), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sQuat_12BE20 Scale_12E010(const sQuat_12BE20& v, float s)
{
    sQuat_12BE20 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline sQuat_12BE20 Conj_12E010(const sXf_12E010& p)
{
    sQuat_12BE20 r;
    r.w = p.rot.w;
    r.x = p.rot.x;
    r.y = p.rot.y;
    r.z = p.rot.z;
    r.x = -r.x;
    r.y = -r.y;
    r.z = -r.z;
    return r;
}

static inline sXf_12E010 Invert_12E010(const sXf_12E010& a)
{
    sXf_12E010 r;
    r.rot = Conj_12E010(a);
    r.pos = Add_12E010(Scale_12E010(Rot_12E010(r.rot, Sub_12E010(a.pos, D_004FF130_12BE20)), -1.0f), D_004FF130_12BE20);
    return r;
}

static inline sXf_12E010 Combine_12E010(const sXf_12E010& a, const sXf_12E010& b)
{
    sXf_12E010 r;
    r.rot = QuatMul_12E010(a.rot, b.rot);
    r.pos = Add_12E010(Rot_12E010(a.rot, Sub_12E010(b.pos, D_004FF130_12BE20)), a.pos);
    return r;
}

extern "C" void func_0012E010(void* self)
{
    char* r = *(char**)((char*)self + 0x80);
    int anim = 0x199;
    if (*(int*)(r + 0x150) != 1)
        anim = 0x19A;
    char buf[0x50];
    func_00312660(buf, *(void**)(r + 0x784), anim, (&D_004A4C00)[2], 0.0f);
    sXf_12E010 a;
    func_0030ECD8(&a, *(void**)(*(char**)((char*)self + 0x80) + 0x780), buf, 0);
    char* rd = *(char**)((char*)self + 0x80);
    char* trk = *(char**)(rd + 0x780);
    sQuat_12BE20* n = (sQuat_12BE20*)((*(int*)(rd + 0x89C) << 4) + *(int*)(trk + 0x24));
    sXf_12E010 node;
    node.pos = sQuat_12BE20(n->x * *(float*)(trk + 0x140), n->y * *(float*)(trk + 0x144),
                            n->z * *(float*)(trk + 0x148), n->w * *(float*)(trk + 0x14C));
    node.rot = *(sQuat_12BE20*)(*(char**)(*(char**)(rd + 0x780) + 0x28) + (*(int*)(rd + 0x89C) << 4));
    sXf_12E010 y = Combine_12E010(node, Invert_12E010(a));
    sXf_12E010* rx = (sXf_12E010*)(*(char**)((char*)self + 0x80) + 0x110);
    *rx = Combine_12E010(*rx, y);
    cRider_updateOrientationImplicit(*(void**)((char*)self + 0x80));
    char* rd3 = *(char**)((char*)self + 0x80);
    sXf_12E010 w = Invert_12E010(y);
    cRiderAnimBase_changeOrientationOffset(*(void**)(rd3 + 0x784), &w);
    cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), anim, 0, -1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E468);
#ifdef SKIP_ASM
int func_00312AA0(void* anim, int layer);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" void func_0012E468(void* self)
{
    switch (func_00312AA0(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2)) {
    case 0x17B:
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 0x180, 0, -1.0f);
        break;
    case 0x17C:
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 0x181, 0, -1.0f);
        break;
    case 0x17D:
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 0x182, 0, -1.0f);
        break;
    case 0x17E:
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 0x183, 0, -1.0f);
        break;
    case 0x17F:
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 0x184, 0, -1.0f);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E528);
#ifdef SKIP_ASM
extern "C" int func_00311AE8(void*, int);
extern "C" char* func_00311B20(void*, int);

static inline bool aiOk_12E528(void* self)
{
    return *(float*)(*(char**)((char*)self + 0x80) + 0x470) >= 0.0f;
}

// PORT: g++ `<?` (min) operator.
static inline float aiClamp_12E528(float v, float lo, float hi)
{
    if (v >= lo) return v <? hi;
    return lo;
}

extern "C" float func_0012E528(void* self)
{
    char* r = *(char**)((char*)self + 0x80);
    char* m = *(char**)(r + 0x77C);
    char* a = func_00311B20(*(void**)(r + 0x784), 2);
    float v = aiLength_12C5C8(*(sAiVec4_12C5C8*)(m + 0x60)) * *(float*)(a + 0x10) * 0.15915493667125702f;
    float res = aiClamp_12E528(v, 0.5f, 2.0f);
    if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x1D ||
        func_00311AE8(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) == 0x19)
    {
        *(float*)(func_00311B20(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) + 0x90) = 1.0f;
    }
    else if (*(float*)((char*)self + 0x70) >= 1.0f || aiOk_12E528(self))
    {
        // PORT: g++ `>?` (max) operator.
        *(float*)(func_00311B20(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) + 0x90) = res >? 2.0f;
    }
    else
    {
        *(float*)(func_00311B20(*(void**)(*(char**)((char*)self + 0x80) + 0x784), 2) + 0x90) = res;
    }
    return res;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ai", func_0012E690);
#ifdef SKIP_ASM
struct sVEntry0012E690 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_001298C8();
extern "C" void func_0010E028(void* self, int mode, float t);
extern "C" void* func_0028B180();
extern "C" void func_002A02D8(void*, void*);

extern "C" void func_0012E690(void* self)
{
    if ((func_001298C8() & 1) == 0)
    {
        char* sub = *(char**)((char*)self + 0x80) + 0x6C0;
        sVEntry0012E690* vt = *(sVEntry0012E690**)sub;
        if (vt[8].fn(sub + vt[8].delta))
        {
            func_0010E028(*(void**)((char*)self + 0x80), 4, 0.0f);
        }
        func_002A02D8(func_0028B180(), *(void**)((char*)self + 0x80));
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E708);
#ifdef SKIP_ASM
struct sVEntry0012E708 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012E708(void* self, void* obj)
{
    sVEntry0012E708* vt = *(sVEntry0012E708**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x80);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E740);
#ifdef SKIP_ASM
struct sVEntry0012E740 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012E740(void* self, void* obj)
{
    sVEntry0012E740* vt = *(sVEntry0012E740**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x80);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E778);
#ifdef SKIP_ASM
extern "C" int func_00116378(void*);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" int func_00106848(void*);
int func_0011FE98(void* self);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" void func_00113E80(void*, float);
extern "C" void func_00113F38(void*, float);
extern "C" void func_00113F88(void* rider, float a, float b);
extern "C" int func_00312AE8(void* self, int i);
extern "C" void func_001326C8(void*, int);
extern "C" void func_00115640(void* rider);

struct sAiVec4_12E778
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sAiBitsA_12E778
{
    int pad : 21;
    int v : 6;
};

struct sAiBitsB_12E778
{
    int pad : 15;
    int v : 6;
};

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float aiDot_12E778(const sAiVec4_12E778& a, const sAiVec4_12E778& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

extern "C" void func_0012E778(void* self, void* in)
{
    if (func_00116378(*(void**)self))
        return;
    if (func_00116120(*(void**)self, (*(int*)in >> 12) & 1, 0))
        return;
    if (func_00106848(*(void**)self))
        return;
    if (func_0011FE98(*(void**)self) == 1)
    {
        func_00114130(*(void**)self, 0, 0);
        func_00113E80(*(void**)self, 0.0f);
    }
    else
    {
        int w = *(int*)in;
        func_00114130(*(void**)self, (w >> 14) & 1, (w >> 13) & 1);
        if (func_0011FE98(*(void**)self) == 4)
        {
            func_00113F38(*(void**)self, ((sAiBitsA_12E778*)in)->v * 0.032258063554763794f);
        }
        else
        {
            char* r = *(char**)self;
            float v = ((sAiBitsB_12E778*)in)->v * 0.032258063554763794f;
            if (aiDot_12E778(*(sAiVec4_12E778*)(r + 0x1E0), *(sAiVec4_12E778*)(r + 0x3A0)) < 0.0f)
                v = -v;
            func_00113E80(r, v);
        }
    }
    float z = 0.0f;
    func_00113F88(*(void**)self, z, z);
    char* r2 = *(char**)self;
    *(float*)(r2 + 0x204) = z;
    *(float*)(r2 + 0x200) = 0.03333333507180214f;
    if (func_00312AE8(*(void**)(*(char**)self + 0x784), 2) == 0)
        return;
    if (func_0011FE98(*(void**)self) == 4)
    {
        func_001326C8(*(char**)(*(char**)self + 0x77C) + 0x2B0, 0);
        func_0011FEC8_impl(*(void**)self, 7);
    }
    else
    {
        func_00115640(*(void**)self);
        if (func_0011FE98(*(void**)self) == 1)
            func_0011FEC8_impl(*(void**)self, 4);
        else
            func_0011FEC8_impl(*(void**)self, 0);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E980);
#ifdef SKIP_ASM
extern "C" void func_0012EE30(void*, void*);
extern char D_0043D788[];

extern "C" void func_0012E980(void* self)
{
    char* p = *(char**)self;
    *(float*)(p + 0x200) = 0.03333333507180214f;
    *(int*)(p + 0x204) = 0;
    func_0012EE30(self, D_0043D788);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E9B0__FPv);
#ifdef SKIP_ASM
void func_0012E9B0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012E9B8);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" int func_00106848(void*);
extern "C" void func_00113E80(void*, float);
extern "C" void func_00113F38(void*, float);
extern "C" void func_00113F88(void* rider, float a, float b);
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" void func_00114298(void* rider, float v);
extern "C" int func_00114CC0(void* rider);
extern "C" void func_001158B8(void* rider, void* a, void* b, float c, float d);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" int func_00116378(void*);
extern "C" void func_00116930(void* rider);
void func_0011FE78_impl(void* self, int v) __asm__("func_0011FE78__FPv");
int func_0011FE98(void* self);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" void func_0012EE30(void*, void*);
extern "C" void func_00294170(void* self, void* rider);
extern "C" int func_00311AE8(void*, int);
int func_00312AA0(void* self, int i);
extern void* D_004A3500;
extern char D_0043D840[];
extern char D_0043D788[];

struct sAiBits0_12E9B8 { int v : 6; };
struct sAiBits6_12E9B8 { int pad : 6; int v : 6; };
struct sAiBits15_12E9B8 { int pad : 15; int v : 6; };
struct sAiBits21_12E9B8 { int pad : 21; int v : 6; };

// PORT: g++ `<?` (min) operator.
static inline float aiClamp_12E9B8(float v, float lo, float hi)
{
    if (v >= lo) return v <? hi;
    return lo;
}

static inline float aiStep_12E9B8(float v)
{
    if (v < -0.20000000298023224f) return -1.0f;
    if (v > 0.20000000298023224f) return 1.0f;
    return 0.0f;
}

// PORT: PS2-only inline asm (float absolute value).
static inline float aiAbs_12E9B8(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_0012E9B8(void* self, void* in)
{
    if (func_00116378(*(void**)self))
        return;
    if (func_00116120(*(void**)self, (*(int*)in >> 12) & 1, 0))
        return;
    if (func_00106848(*(void**)self))
        return;
    int w = *(int*)in;
    if ((w & 0x2000) == 0)
    {
        char* r0 = *(char**)self;
        func_001158B8(r0, r0 + 0x2B0, r0 + 0x2A4, 0.7853982448577881f, 0.20000000298023224f);
        char* r = *(char**)self;
        if (*(int*)(r + 0x328) == 3 || *(int*)(r + 0x328) == 4)
        {
            float a = 0.0f;
            char* anim = *(char**)(r + 0x784);
            *(sQuat_12BE20*)(anim + 0x30) = D_004FF130_12BE20;
            *(sQuat_12BE20*)(anim + 0x40) = AxisAngle_12BE20(D_004FF160_12BE20, -a);
        }
        func_0012EE30(self, D_0043D840);
        *(int*)(*(char**)self + 0x328) = 0;
        func_00116930(*(void**)self);
        if (func_0011FE98(*(void**)self) != 1)
        {
            func_00114298(*(void**)self, *(float*)(*(char**)self + 0x220));
            func_0011FE78_impl(*(void**)self, 1);
            func_00294170(D_004A3500, *(void**)self);
        }
        float z = 0.0f;
        func_00113E80(*(void**)self, z);
        func_00113F88(*(void**)self, z, z);
        func_0011FEC8_impl(*(void**)self, 5);
        return;
    }
    func_00114130(*(void**)self, (w >> 14) & 1, 0);
    float zero = 0.0f;
    func_00113F88(*(void**)self, 1.0f, zero);
    float sx = aiClamp_12E9B8(((sAiBits0_12E9B8*)((char*)in + 4))->v * 0.032258063554763794f, -0.5f, 0.5f);
    float sy = aiClamp_12E9B8(((sAiBits6_12E9B8*)((char*)in + 4))->v * 0.032258063554763794f, -0.5f, 0.5f);
    if (func_00311AE8(*(void**)(*(char**)self + 0x784), 2) == 10)
    {
        char* r = *(char**)self;
        if (*(int*)(r + 0x328) == 0)
            func_00113E80(r, sx);
        else
            func_00113F38(r, sy);
        char* r1 = *(char**)self;
        *(float*)(r1 + 0x2AC) = 0.0f;
        *(float*)(r1 + 0x2A8) = 0.08333379030227661f;
        char* r2 = *(char**)self;
        *(float*)(r2 + 0x2B4) = 0.08333379030227661f;
        *(float*)(r2 + 0x2B8) = 0.0f;
        return;
    }
    if (func_00312AA0(*(void**)(*(char**)self + 0x784), 2) == 0x15)
    {
        func_00113E80(*(void**)self, zero);
        char* r1 = *(char**)self;
        *(float*)(r1 + 0x2AC) = zero;
        *(float*)(r1 + 0x2A8) = 0.08333379030227661f;
        char* r2 = *(char**)self;
        *(float*)(r2 + 0x2B8) = zero;
        *(float*)(r2 + 0x2B4) = 0.08333379030227661f;
        return;
    }
    char* r = *(char**)self;
    if (*(int*)(r + 0x328) == 0 && *(float*)(r + 0x2DC) == zero && func_00114CC0(r))
    {
        cRiderAnimBase_play(*(void**)(*(char**)self + 0x784), 0x15, 0, -1.0f);
        return;
    }
    float rate = 5.0000901222229f;
    if (*(int*)(*(char**)self + 0x328) == 0)
        rate = 5.000027179718018f;
    float tx = ((sAiBits15_12E9B8*)in)->v * 0.032258063554763794f;
    float ty = ((sAiBits21_12E9B8*)in)->v * 0.032258063554763794f;
    if (tx < -0.20000000298023224f)
        tx = -1.0f;
    else if (tx > 0.20000000298023224f)
        tx = 1.0f;
    else
        tx = 0.0f;
    if (ty < -0.20000000298023224f)
        ty = -1.0f;
    else if (ty > 0.20000000298023224f)
        ty = 1.0f;
    else
        ty = 0.0f;
    float ux = tx;
    float uy = ty;
    char* r3 = *(char**)self;
    float d = ux - *(float*)(r3 + 0x2A4);
    *(float*)(r3 + 0x2AC) = ux;
    *(float*)(r3 + 0x2A8) = rate * aiAbs_12E9B8(d) * 0.01666666753590107f;
    char* r4 = *(char**)self;
    *(float*)(r4 + 0x2B8) = uy;
    *(float*)(r4 + 0x2B4) = rate * aiAbs_12E9B8(uy - *(float*)(r4 + 0x2B0)) * 0.01666666753590107f;
    char* r5 = *(char**)self;
    if (*(int*)(r5 + 0x328) == 0)
        func_00113E80(r5, sx);
    else
        func_00113F38(r5, sy);
    func_0012EE30(self, D_0043D788);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012EE30);
#ifdef SKIP_ASM
extern "C" float func_0031C228(float x);
int func_00312AA0(void* self, int i);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

static inline float aiAtan2_12EE30(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_12EE30(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_0012EE30(void* self, void* tbl_)
{
    char* obj = *(char**)self;
    float x = *(float*)(obj + 0x2A4);
    float y = *(float*)(obj + 0x2B0);
    float ax = aiAbs_12EE30(x);
    float ay = aiAbs_12EE30(y);
    float mag = (ay < ax) ? ax : ay;
    float a;
    if (*(int*)(obj + 0x320))
        a = aiAtan2_12EE30(-y, -x);
    else
        a = aiAtan2_12EE30(-y, x);
    int cur = func_00312AA0(*(void**)(*(char**)self + 0x784), 2);
    int anim;
    if (mag == 0.0f)
        anim = ((int (*)[5])tbl_)[0][*(int*)(*(char**)self + 0x328)];
    else if (aiAbs_12EE30(a) > 2.7488937377929688f)
        anim = ((int (*)[5])tbl_)[1][*(int*)(*(char**)self + 0x328)];
    else if (a > 1.9634956121444702f)
        anim = ((int (*)[5])tbl_)[2][*(int*)(*(char**)self + 0x328)];
    else if (a > 1.1780973672866821f)
        anim = ((int (*)[5])tbl_)[3][*(int*)(*(char**)self + 0x328)];
    else if (a > 0.39269912242889404f)
        anim = ((int (*)[5])tbl_)[4][*(int*)(*(char**)self + 0x328)];
    else if (a < -1.9634956121444702f)
        anim = ((int (*)[5])tbl_)[5][*(int*)(*(char**)self + 0x328)];
    else if (a < -1.1780973672866821f)
        anim = ((int (*)[5])tbl_)[6][*(int*)(*(char**)self + 0x328)];
    else if (a < -0.39269912242889404f)
        anim = ((int (*)[5])tbl_)[7][*(int*)(*(char**)self + 0x328)];
    else
        anim = ((int (*)[5])tbl_)[8][*(int*)(*(char**)self + 0x328)];
    if (anim != cur)
        cRiderAnimBase_play(*(void**)(*(char**)self + 0x784), anim, 0, -1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F118);
#ifdef SKIP_ASM
extern "C" float func_0031C228(float x);

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_12F118(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float aiAtan2_12F118(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

extern "C" float func_0012F118(void* self, int* out)
{
    char* obj = *(char**)self;
    float y = *(float*)(obj + 0x2B0);
    float x = *(float*)(obj + 0x2A4);
    if (aiAbs_12F118(y) < 0.1f) y = 0.0f;
    if (aiAbs_12F118(x) < 0.1f) x = 0.0f;
    int zero = 0;
    if (y == 0.0f && x == 0.0f) zero = 1;
    *out = zero;
    if (zero) return 0.0f;
    return aiAtan2_12F118(y, x);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F230);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" char* func_00311B20(void*, int);
extern "C" int func_0012F588(void* self);
void* func_00230698(void* self, int id);
extern "C" void func_002E4578(void* obj);
void* func_002E4D70(void* self);
extern "C" void func_002E4370(void* self, int a1, void* a2, void* a3, float f0, float f1, float f2, int a4, void* a5);
extern void* D_004880C0[];

struct sColor_12F230
{
    float r, g, b, a;
    sColor_12F230() {}
    sColor_12F230(float ar, float ag, float ab, float aa) { r = ar; g = ag; b = ab; a = aa; }
};

struct sFx_12F230
{
    void** vt;
    sColor_12F230 c;
};

// PORT: the wake-fx pool allocator ignores its argument; callers pass the object size.
extern "C" void* func_002E4CE8(unsigned size);

static inline sFx_12F230* initFx_12F230(sFx_12F230* p, const sColor_12F230& col)
{
    func_002E4D70(p);
    p->vt = D_004880C0;
    p->c = col;
    return p;
}

extern "C" void func_0012F230(void* self)
{
    int* flag = (int*)((char*)self + 4);
    *flag = 0;
    *(int*)(func_00311B20(*(void**)(*(char**)((char*)self + 8) + 0x784), 2) + 0x90) = 0;
    if (func_0012F588(self))
    {
        char* obj = (char*)func_00230698(*(void**)((char*)D_004A28A8 + 0x84), *(int*)(*(char**)((char*)self + 8) + 0x870));
        if (*(int*)(obj + 0x44))
            func_002E4578(obj);
        sFx_12F230* a = (sFx_12F230*)func_002E4CE8(0x14);
        sColor_12F230 ca;
        ca.r = 1.0f;
        ca.g = 1.0f;
        ca.b = 1.0f;
        ca.a = 1.0f;
        initFx_12F230(a, ca);
        sFx_12F230* b = (sFx_12F230*)func_002E4CE8(0x14);
        sColor_12F230 cb;
        cb.r = 1.0f;
        cb.g = 1.0f;
        cb.b = 1.0f;
        cb.a = 1.0f;
        initFx_12F230(b, cb);
        func_002E4370(obj, 1, a, b, 0.5f, 0.0f, 0.5f, 0, flag);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F398);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
extern "C" char* func_00311B20(void*, int);
extern "C" int func_0012F588(void* self);
void* func_00230698(void* self, int id);
extern "C" void func_002E4578(void* obj);
extern "C" void func_0010E098(void*, int, float);
extern "C" float func_00119368(void* self, int a1);
extern "C" void func_00119E38(void* p, int flip, int c);
extern "C" void func_00112D58(void*);
extern "C" void func_0011DF18(void* self, int notify);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
void func_0011FE78_impl(void* self, int v) __asm__("func_0011FE78__FPv");
extern signed char D_00535C12[];

struct sVec4_12F398
{
    float x, y, z, w;
};

extern "C" sVec4_12F398 func_0026A8B8(void* self, float t);
extern "C" void func_0011D660_12F398(void* self, void* a, sVec4_12F398* b, int n, float t) __asm__("func_0011D660");

extern "C" void func_0012F398(void* self)
{
    float t = *(float*)((char*)self + 0x4);
    float step = *(float*)(*(char**)((char*)self + 0x8) + 0x300) * 0.02500000223517418f;
    float n;
    if (t > step + 1.0f)
        n = t - step;
    else if (t < 1.0f - step)
        n = t + step;
    else
        n = 1.0f;
    *(float*)((char*)self + 0x4) = n;
    if (t <= 0.5f && n > 0.5f)
    {
        float range = 200.0f;
        func_00112D58(*(void**)((char*)self + 0x8));
        char* r = *(char**)((char*)self + 0x8);
        const sVec4_12F398& dir = func_0026A8B8(*(void**)(r + 0xAB8), *(float*)(r + 0x4C4));
        if (cBE_getInterface_Fv(cBE_getBE(), 0) != 0 && D_00535C12[0] == 2)
            range = 1000.0f;
        func_0011D660_12F398(*(void**)((char*)self + 0x8), *(char**)((char*)self + 0x8) + 0x490, (sVec4_12F398*)&dir, 0x11F, range);
        func_0011DF18(*(void**)((char*)self + 0x8), 1);
        if (*(int*)self != 0)
            func_0010E098(*(void**)((char*)self + 0x8), 1, func_00119368(*(void**)(*(char**)((char*)self + 0x8) + 0x790), 0));
        else
            func_0010E098(*(void**)((char*)self + 0x8), 1, func_00119368(*(void**)(*(char**)((char*)self + 0x8) + 0x790), 1));
    }
    if (*(float*)((char*)self + 0x4) == 1.0f)
    {
        if (func_0012F588(self))
            func_002E4578(func_00230698(*(void**)((char*)D_004A28A8 + 0x84), *(int*)(*(char**)((char*)self + 8) + 0x870)));
        func_00119E38(*(void**)(*(char**)((char*)self + 8) + 0x790), 0, 0);
        *(float*)(func_00311B20(*(void**)(*(char**)((char*)self + 8) + 0x784), 2) + 0x90) = 1.0f;
        func_0011FEC8_impl(*(void**)((char*)self + 0x8), 4);
        func_0011FE78_impl(*(void**)((char*)self + 0x8), 1);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F588);
#ifdef SKIP_ASM
extern "C" int func_0012F588(void* self)
{
    void* p = *(void**)((char*)self + 0x8);
    return *(int*)((char*)p + 0x87C) != 0 && *(int*)((char*)p + 0x870) >= 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F5B0);
#ifdef SKIP_ASM
struct sVEntry0012F5B0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012F5B0(void* self, void* obj)
{
    sVEntry0012F5B0* vt = *(sVEntry0012F5B0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x8);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F5E8);
#ifdef SKIP_ASM
struct sVEntry0012F5E8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012F5E8(void* self, void* obj)
{
    sVEntry0012F5E8* vt = *(sVEntry0012F5E8**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x8);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F620);
#ifdef SKIP_ASM
extern "C" float func_0031C228(float x);

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_12F620(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float aiAtan2_12F620(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

extern "C" void func_0012F620(void* self)
{
    char* r = *(char**)((char*)self + 0x14);
    float b = *(float*)(r + 0x220);
    float a = aiAbs_12F620(*(float*)(r + 0x1F0));
    if (a < b) a = b;
    *(float*)((char*)self + 0x4) = a;
    float ang = aiAtan2_12F620(*(float*)(r + 0x220), *(float*)(r + 0x1F0));
    *(float*)((char*)self + 0x0) = ang;
    *(int*)((char*)self + 0x8) = 1;
    *(int*)((char*)self + 0xC) = 1;
    *(int*)((char*)self + 0x10) = -1;
    char* r1 = *(char**)((char*)self + 0x14);
    *(int*)(r1 + 0x2AC) = 0;
    *(float*)(r1 + 0x2A8) = 0.03333333507180214f;
    char* r2 = *(char**)((char*)self + 0x14);
    *(float*)(r2 + 0x2B4) = 0.03333333507180214f;
    *(int*)(r2 + 0x2B8) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012F730);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" int func_00106848(void*);
extern "C" int func_00107578(void* rider, int on);
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" int func_001163B0(void* rider, int a, int b);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" int func_00311AE8(void*, int);
int func_00312AA0(void* self, int i);
extern "C" float func_0031C228(float x);

struct sAiBitsX_12F730
{
    int pad : 24;
    int v : 6;
};

struct sAiBitsY_12F730
{
    int v : 6;
};

// PORT: PS2-only inline asm (float absolute value).
static inline float aiAbs_12F730(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float aiAtan2_12F730(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float aiFloor_12F730(float x)
{
    float t;
    __asm__("cvt.w.s %0, %1\n\tcvt.s.w %0, %0" : "=f"(t) : "f"(x));
    if (x < t)
    {
        t -= 1.0f;
    }
    return t;
}

static inline float aiWrap_12F730(float x)
{
    return x - aiFloor_12F730(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

struct sAiObj12F730
{
    float mHeading;  // 0x00
    float mTimer;    // 0x04
    int mFlag;       // 0x08
    int mHold;       // 0x0C
    int mId;         // 0x10
    char* mRider;    // 0x14
};

extern "C" void func_0012F730(sAiObj12F730* self, void* in)
{
    if (func_00116120(self->mRider, (*(int*)in >> 12) & 1, 0))
        return;
    if (self->mFlag != 0)
    {
        self->mFlag = (*(int*)in & 0xC000) != 0;
        if (func_001163B0(self->mRider, (*(int*)in >> 14) & 1, (*(int*)in >> 15) & 1))
            return;
    }
    else
    {
        func_001163B0(self->mRider, 0, 0);
    }
    int w = *(int*)in;
    float x = ((sAiBitsX_12F730*)&w)->v * 0.032258063554763794f;
    float y = ((sAiBitsY_12F730*)((char*)in + 4))->v * 0.032258063554763794f;
    if (w & 0x2000)
    {
        if (func_00107578(self->mRider, y > 0.5f))
            return;
        y = 1.0f;
    }
    if (func_00106848(self->mRider))
        return;
    func_00114130(self->mRider, 0, 0);
    if (self->mHold != 0 && self->mId == -1)
        self->mId = *((signed char*)in + 2);
    if (*((signed char*)in + 2) != self->mId || *((signed char*)in + 2) == -1)
        self->mHold = 0;
    if (self->mHold == 0 && self->mId != -1)
        self->mTimer = -1.0f;
    float ax = aiAbs_12F730(x);
    float lim = y;
    if (y <= ax)
        lim = ax;
    float ang = aiAtan2_12F730(y, x);
    if (self->mTimer < 0.0f || lim <= (self->mTimer - 0.5f >? 0.0f) ||
        __builtin_fabsf(aiWrap_12F730(ang - self->mHeading)) > 1.5707964897155762f)
    {
        self->mTimer = -1.0f;
        y = 0.0f;
        x = y;
    }
    char* r = self->mRider;
    *(float*)(r + 0x1F8) = x;
    *(float*)(r + 0x1F4) = 0.05000000447034836f;
    char* r2 = self->mRider;
    *(float*)(r2 + 0x200) = 0.05000000447034836f;
    *(float*)(r2 + 0x204) = *(float*)(r2 + 0x1F0);
    char* r3 = self->mRider;
    *(float*)(r3 + 0x224) = 0.05000000447034836f;
    *(float*)(r3 + 0x228) = y;
    char* r4 = self->mRider;
    *(float*)(r4 + 0x218) = 0.05000000447034836f;
    *(int*)(r4 + 0x21C) = 0;
    int anim = func_00312AA0(*(void**)(self->mRider + 0x784), 2);
    char* r5 = self->mRider;
    if (*(float*)(r5 + 0x220) == 0.0f && *(float*)(r5 + 0x214) == 0.0f && *(float*)(r5 + 0x1F0) == 0.0f && self->mHold == 0)
    {
        if (anim != 0x11F)
        {
            if (func_00311AE8(*(void**)(r5 + 0x784), 2) != 9)
                cRiderAnimBase_play(*(void**)(self->mRider + 0x784), 0x11F, 0, -1.0f);
        }
        func_0011FEC8_impl(self->mRider, 5);
        return;
    }
    if (func_00311AE8(*(void**)(self->mRider + 0x784), 2) == 9)
        return;
    int a = 10;
    char* r6 = self->mRider;
    if (*(float*)(r6 + 0x220) <= (1.0f - aiAbs_12F730(*(float*)(r6 + 0x1F0))) * 0.5f)
        a = 9;
    if (a != anim)
        cRiderAnimBase_play(*(void**)(r6 + 0x784), a, 0, -1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FB68);
#ifdef SKIP_ASM
extern "C" int func_00311AE8(void*, int);
extern "C" void func_00311E88(void*, int, float);
extern "C" char* func_00311B20(void*, int);

extern "C" void func_0012FB68(void* self, int a1)
{
    if (a1)
    {
        if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 1) == 3 ||
            func_00311AE8(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 1) == 0xD)
        {
            func_00311E88(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0, 0.10000000149011612f);
            *(float*)(func_00311B20(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 1) + 0x90) = 1.0f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FBF0);
#ifdef SKIP_ASM
struct sVEntry0012FBF0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012FBF0(void* self, void* obj)
{
    sVEntry0012FBF0* vt = *(sVEntry0012FBF0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FC28);
#ifdef SKIP_ASM
struct sVEntry0012FC28 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0012FC28(void* self, void* obj)
{
    sVEntry0012FC28* vt = *(sVEntry0012FC28**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FC60__FPv);
#ifdef SKIP_ASM
void func_0012FC60(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)*(void**)((char*)self + 0x14) + 0x360) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FC80);
#ifdef SKIP_ASM
extern "C" int func_00116378(void*);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" int func_00106848(void*);
extern "C" int func_0012FFF8(void*);
extern "C" int func_001162C8(void*, int, int);
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" void func_00113E80(void*, float);
extern "C" void func_00113F38(void*, float);
extern "C" void func_00113F88(void* rider, float a, float b);
extern "C" void func_00115B58(void*);
extern "C" void func_00115D48(void*);
struct sPadIn_130228;
extern "C" void func_00130228(void* self, sPadIn_130228* in);
extern "C" void func_001303E0(void* self, void* a1);
struct sPadIn_1304E0;
extern "C" void func_001304E0(void* self, sPadIn_1304E0* in);
// PORT: func_001304D0 is defined with one param, but this caller passes the input in $a1.
void func_001304D0_2(void* self, void* in) __asm__("func_001304D0__FPv");

struct sAiBitsC_12FC80
{
    int pad : 24;
    int v : 6;
};

struct sAiBitsD_12FC80
{
    int pad : 18;
    int v : 6;
};

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_12FC80(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float aiClamp_12FC80(float v, float lo, float hi)
{
    if (v >= lo)
        return v <? hi;
    return lo;
}

extern "C" void func_0012FC80(void* self, void* in)
{
    if (func_00116378(*(void**)((char*)self + 0x14)))
        return;
    if (func_00116120(*(void**)((char*)self + 0x14), (*(int*)in >> 12) & 1, 0))
        return;
    if (func_00106848(*(void**)((char*)self + 0x14)))
        return;
    if (func_0012FFF8(self))
        return;
    int w = *(int*)in;
    if (func_001162C8(*(void**)((char*)self + 0x14), (w >> 15) & 1, (w >> 16) & 1))
        return;
    int w2 = *(int*)in;
    func_00114130(*(void**)((char*)self + 0x14), (w2 >> 14) & 1, (w2 >> 13) & 1);
    func_00113F88(*(void**)((char*)self + 0x14), 0.0f, 0.0f);
    char* r = *(char**)((char*)self + 0x14);
    if (*(int*)(r + 0x328) != 0)
    {
        func_00113F38(r, aiClamp_12FC80(((sAiBitsC_12FC80*)in)->v * 0.032258063554763794f, -0.5f, 0.5f));
    }
    else
    {
        float a = aiAbs_12FC80(*(float*)(r + 0x280));
        float d;
        if (a > 0.5f)
            d = a - 0.5f;
        else
            d = 0.5f - a;
        func_00113E80(*(void**)((char*)self + 0x14), aiClamp_12FC80(((sAiBitsD_12FC80*)in)->v * 0.032258063554763794f, -d, d));
    }
    func_00115B58(*(void**)((char*)self + 0x14));
    func_00115D48(*(void**)((char*)self + 0x14));
    switch (*(int*)self)
    {
    case 0:
        func_00130228(self, (sPadIn_130228*)in);
        break;
    case 1:
        func_001303E0(self, in);
        break;
    case 2:
        func_001304D0_2(self, in);
        break;
    case 3:
        func_001304E0(self, (sPadIn_1304E0*)in);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FE98);
#ifdef SKIP_ASM
extern "C" void func_0012FE98(void* self)
{
    char* a = *(char**)((char*)self + 0x14);
    *(int*)(a + 0x330) = 0;
    char* b = *(char**)((char*)self + 0x14);
    *(float*)(b + 0x278) = 0.01666666753590107f;
    *(int*)(b + 0x27C) = 0;
    char* c = *(char**)((char*)self + 0x14);
    *(float*)(c + 0x26C) = 0.03333333507180214f;
    *(int*)(c + 0x270) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FEC8);
#ifdef SKIP_ASM
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void func_00116930(void* rider);

struct sQuat_12FEC8
{
    float x, y, z, w;
    sQuat_12FEC8() {}
    sQuat_12FEC8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

extern sQuat_12FEC8 D_004FF130;
extern sQuat_12FEC8 D_004FF160;

static inline sQuat_12FEC8 AxisAngle_12FEC8(const sQuat_12FEC8& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sQuat_12FEC8(s * axis.x, s * axis.y, s * axis.z, c);
}

extern "C" void func_0012FEC8(void* self)
{
    *(int*)(*(char**)((char*)self + 0x14) + 0x320) ^= 1;
    char* r = *(char**)((char*)self + 0x14);
    float a = 0.0f;
    if (*(int*)(r + 0x320) != 0) a = 3.1415927410125732f;
    char* anim = *(char**)(r + 0x784);
    *(sQuat_12FEC8*)(anim + 0x30) = D_004FF130;
    *(sQuat_12FEC8*)(anim + 0x40) = AxisAngle_12FEC8(D_004FF160, -a);
    char* r2 = *(char**)((char*)self + 0x14);
    *(int*)(*(char**)(r2 + 0x784) + 0x18) = *(int*)(r2 + 0x320);
    char* r3 = *(char**)((char*)self + 0x14);
    if (*(int*)(r3 + 0x328) == 1)
    {
        *(int*)(r3 + 0x328) = 2;
    }
    else if (*(int*)(r3 + 0x328) == 2)
    {
        *(int*)(r3 + 0x328) = 1;
    }
    *(float*)(*(char**)((char*)self + 0x14) + 0x280) = -*(float*)(*(char**)((char*)self + 0x14) + 0x280);
    *(float*)(*(char**)((char*)self + 0x14) + 0x288) = -*(float*)(*(char**)((char*)self + 0x14) + 0x288);
    func_00116930(*(void**)((char*)self + 0x14));
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_0012FFF8);
#ifdef SKIP_ASM
int func_00312AA0(void* self, int i);
int func_0011FE98(void* self);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0010E098(void*, int, float);
extern "C" void func_00116930(void* rider);
extern "C" float func_00119A38(void*);
extern "C" float func_00119AD8(void* p, int v);

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_12FFF8(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" int func_0012FFF8(void* self)
{
    int k = func_0011FE98(*(void**)((char*)self + 0x14));
    if (k != 1)
        return 0;
    char* r = *(char**)((char*)self + 0x14);
    if (*(int*)(r + 0x328) != 0)
    {
        *(int*)(r + 0x328) = 0;
        func_00116930(*(void**)((char*)self + 0x14));
    }
    int anim = func_00312AA0(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 2);
    if (*(int*)self == 2)
    {
        int ok = 0;
        if (anim == 0x25 || anim == 0x26)
        {
            char* p = *(char**)((char*)self + 0x14);
            *(float*)(p + 0x288) = 0.0f;
            *(float*)(p + 0x284) = *(float*)(p + 0x300) * 0.02500000223517418f;
            ok = aiAbs_12FFF8(*(float*)(*(char**)((char*)self + 0x14) + 0x280)) <= 0.15000000596046448f;
        }
        else if (anim == 0x1D || anim == 0x1E)
        {
            char* p = *(char**)((char*)self + 0x14);
            if (*(float*)(p + 0x280) < 0.0f)
            {
                *(float*)(p + 0x288) = -1.0f;
                *(float*)(p + 0x284) = *(float*)(p + 0x300) * 0.02500000223517418f;
            }
            else
            {
                *(float*)(p + 0x288) = 1.0f;
                *(float*)(p + 0x284) = *(float*)(p + 0x300) * 0.02500000223517418f;
            }
            ok = 0.8500000238418579f <= aiAbs_12FFF8(*(float*)(*(char**)((char*)self + 0x14) + 0x280));
        }
        if (ok == 0)
            return 1;
        char* q = *(char**)((char*)self + 0x14);
        func_0010E098(*(void**)((char*)self + 0x14), 1, func_00119AD8(*(void**)(q + 0x790), *(int*)(q + 0x330)));
        func_0010E098(*(void**)((char*)self + 0x14), 1, func_00119A38(*(void**)(*(char**)((char*)self + 0x14) + 0x790)));
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x11F, 0, -1.0f);
        func_0011FEC8_impl(*(void**)((char*)self + 0x14), 5);
        return 1;
    }
    if (anim == 0x25 || anim == 0x26 || anim == 0x1D || anim == 0x1E)
    {
        *(int*)self = 2;
    }
    else
    {
        char* s = *(char**)((char*)self + 0x14);
        if (*(int*)(s + 0x330) == 1)
            cRiderAnimBase_play(*(void**)(s + 0x784), 0x1B, 0, -1.0f);
        else
            cRiderAnimBase_play(*(void**)(s + 0x784), 0x23, 0, -1.0f);
        func_0011FEC8_impl(*(void**)((char*)self + 0x14), 5);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00130228);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0010E098(void*, int, float);
extern "C" float func_001199F8(void*, int);

// PORT: abs.s via inline asm (use fabsf off-PS2).
static inline float Abs_130228(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

struct sPadIn_130228
{
    int f0;
    int x : 6;
    int y : 6;
};

extern "C" void func_00130228(void* self, sPadIn_130228* in)
{
    float fx = in->x * 0.032258063554763794f;
    float fy = in->y * 0.032258063554763794f;
    if (fx == 0.0f && Abs_130228(fy) < 0.5f)
    {
        char* r = *(char**)((char*)self + 0x14);
        *(float*)(r + 0x270) = 0.0f;
        *(float*)(r + 0x26C) = *(float*)(r + 0x300) * 2.0f * 0.01666666753590107f;
        *(int*)self = 3;
        char* r2 = *(char**)((char*)self + 0x14);
        if (*(int*)(r2 + 0x330) == 2)
        {
            cRiderAnimBase_play(*(void**)(r2 + 0x784), 0x21, 0, -1.0f);
        }
        else
        {
            cRiderAnimBase_play(*(void**)(r2 + 0x784), 0x19, 0, -1.0f);
        }
        return;
    }
    char* r = *(char**)((char*)self + 0x14);
    *(float*)(r + 0x278) = *(float*)(r + 0x300) * 0.01666666753590107f;
    *(float*)(r + 0x27C) = 0.5f;
    char* r2 = *(char**)((char*)self + 0x14);
    *(float*)(r2 + 0x270) = 1.0f;
    *(float*)(r2 + 0x26C) = *(float*)(r2 + 0x300) * 2.0f * 0.01666666753590107f;
    char* r3 = *(char**)((char*)self + 0x14);
    if (*(float*)(r3 + 0x268) == 1.0f)
    {
        func_0010E098(*(void**)((char*)self + 0x14), 1, func_001199F8(*(void**)(r3 + 0x790), *(int*)(r3 + 0x330)));
        *(int*)self = 1;
        char* r4 = *(char**)((char*)self + 0x14);
        if (*(int*)(r4 + 0x330) == 2)
        {
            cRiderAnimBase_play(*(void**)(r4 + 0x784), 0x24, 0, -1.0f);
            char* r5 = *(char**)((char*)self + 0x14);
            *(float*)(r5 + 0x284) = 0.0f;
            *(float*)(r5 + 0x288) = 1.0f;
            *(float*)(r5 + 0x280) = 1.0f;
        }
        else
        {
            cRiderAnimBase_play(*(void**)(r4 + 0x784), 0x1C, 0, -1.0f);
            char* r5 = *(char**)((char*)self + 0x14);
            *(float*)(r5 + 0x288) = 0.0f;
            *(float*)(r5 + 0x280) = 0.0f;
            *(float*)(r5 + 0x284) = 0.0f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001303E0);
#ifdef SKIP_ASM
extern "C" int func_001306B0(void* self);
extern "C" int func_001307B8(void* self, void* a1);
extern "C" int func_001308D8(void* self, void* a1);
extern "C" int func_00130DD0(void* self, void* a1);
extern "C" int func_00131200(void* self, void* a1);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" void func_001303E0(void* self, void* a1)
{
    if (func_001306B0(self) != 0) return;
    if (func_001307B8(self, a1) != 0) return;
    if (func_001308D8(self, a1) != 0) return;
    if (func_00130DD0(self, a1) != 0) return;
    if (func_00131200(self, a1) != 0)
    {
        char* r = *(char**)((char*)self + 0x14);
        *(int*)(r + 0x270) = 0;
        *(float*)(r + 0x26C) = *(float*)(r + 0x300) * 2.0f * 0.01666666753590107f;
        char* r2 = *(char**)((char*)self + 0x14);
        if (*(int*)(r2 + 0x330) == 2)
        {
            cRiderAnimBase_play(*(void**)(r2 + 0x784), 0x21, 0, -1.0f);
        }
        else
        {
            cRiderAnimBase_play(*(void**)(r2 + 0x784), 0x19, 0, -1.0f);
        }
        *(int*)self = 3;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001304D0__FPv);
#ifdef SKIP_ASM
void func_001304D0(void* self)
{
    *(int*)self = 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001304E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_00312AA0(void* self, int i);
int func_0011FE98(void* self);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0010E098(void*, int, float);
extern "C" void func_00115640(void* rider);
extern "C" float func_00119A38(void*);
extern "C" void func_001326C8(void*, int);

struct sPadIn_1304E0
{
    int f0;
    int x : 6;
    int y : 6;
};

extern "C" void func_001304E0(void* self, sPadIn_1304E0* in)
{
    int anim = func_00312AA0(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 2);
    char* r;
    if ((anim == 0x21 || anim == 0x19) && 0.0f < *(float*)((r = *(char**)((char*)self + 0x14)) + 0x268))
    {
        float fx = in->x * 0.032258063554763794f;
        if ((fx < -0.5f && anim == 0x21) || (0.5f < fx && anim == 0x19))
        {
            if (fx < 0.0f)
            {
                cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x20, 0, -1.0f);
                *(int*)(*(char**)((char*)self + 0x14) + 0x330) = 2;
            }
            else
            {
                cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x18, 0, -1.0f);
                *(int*)(*(char**)((char*)self + 0x14) + 0x330) = 1;
            }
            char* r2 = *(char**)((char*)self + 0x14);
            *(float*)(r2 + 0x270) = 1.0f;
            *(float*)(r2 + 0x26C) = *(float*)(r2 + 0x300) * 2.0f * 0.01666666753590107f;
            *(int*)self = 0;
        }
        return;
    }
    r = *(char**)((char*)self + 0x14);
    if (*(int*)(r + 0x330) == 1 || *(int*)(r + 0x330) == 2)
    {
        func_0010E098(*(void**)((char*)self + 0x14), 1, func_00119A38(*(void**)(r + 0x790)));
    }
    if (func_0011FE98(*(void**)((char*)self + 0x14)) == 4)
    {
        func_001326C8(*(char**)(*(char**)((char*)self + 0x14) + 0x77C) + 0x2B0, 0);
        func_0011FEC8_impl(*(void**)((char*)self + 0x14), 7);
    }
    else
    {
        func_00115640(*(void**)((char*)self + 0x14));
        func_0011FEC8_impl(*(void**)((char*)self + 0x14), 0);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001306B0);
#ifdef SKIP_ASM
int func_00312AA0(void* self, int i);
int func_0011FE98(void* self);
extern "C" int func_00114CC0(void* rider);
// PORT: cRiderAnimBase_play returns a value (the unit declares it void); int-returning view bound by asm label.
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" int func_001306B0(void* self)
{
    int s = func_00312AA0(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 2);
    if (s == 0x17 || s == 0x1F) return 1;
    if (s == 0x25 || s == 0x26 || s == 0x1D || s == 0x1E) return 0;
    if (func_0011FE98(*(void**)((char*)self + 0x14)) != 0) return 0;
    char* r = *(char**)((char*)self + 0x14);
    if (*(float*)(r + 0x2DC) != 0.0f) return 0;
    if (func_00114CC0(r) != 0)
    {
        char* r2 = *(char**)((char*)self + 0x14);
        if (*(int*)(r2 + 0x330) == 1)
        {
            cRiderAnimBase_play(*(void**)(r2 + 0x784), 0x17, 0, -1.0f);
            *(int*)(*(char**)((char*)self + 0x14) + 0x330) = 2;
        }
        else
        {
            cRiderAnimBase_play(*(void**)(r2 + 0x784), 0x1F, 0, -1.0f);
            *(int*)(*(char**)((char*)self + 0x14) + 0x330) = 1;
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001307B8);
#ifdef SKIP_ASM
extern "C" void func_00131428(void*);
extern "C" void func_00116930(void* rider);
extern "C" void func_00114298(void* rider, float v);
extern "C" void func_00294170(void* self, void* rider);
// PORT: prototype mismatch. func_0011FEC8/func_0011FE78 are defined with one param, but callers pass a mode in $a1.
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
void func_0011FE78_impl(void* self, int v) __asm__("func_0011FE78__FPv");
extern void* D_004A3500;

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_1307B8(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" int func_001307B8(void* self, void* a1)
{
    int mask = 0x20000;
    if (*(int*)a1 & mask) *(int*)((char*)self + 0x10) = 1;
    int ok = *(int*)((char*)self + 0x10) != 0 && (*(int*)a1 & mask) == 0;
    float speed = aiAbs_1307B8(*(float*)(*(char**)((char*)self + 0x14) + 0x280));
    if (!ok) return 0;
    func_00131428(self);
    if (speed > 0.5f)
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x23, 0, -1.0f);
    }
    else
    {
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x1B, 0, -1.0f);
    }
    char* r = *(char**)((char*)self + 0x14);
    if (*(int*)(r + 0x328) != 0)
    {
        *(int*)(r + 0x328) = 0;
        func_00116930(*(void**)((char*)self + 0x14));
    }
    func_00114298(*(void**)((char*)self + 0x14), 1.0f);
    func_0011FE78_impl(*(void**)((char*)self + 0x14), 1);
    func_0011FEC8_impl(*(void**)((char*)self + 0x14), 5);
    func_00294170(D_004A3500, *(void**)((char*)self + 0x14));
    return 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001308D8);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0012FEC8(void* self);
extern "C" void func_001313A8(void*);
extern "C" void func_00131428(void*);
int func_00312AA0(void* self, int i);
extern "C" float func_0031C228(float x);

struct sAiVec4_08D8
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sAiBits_08D8
{
    int lo : 6;
    int hi : 6;
};

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float aiDot_08D8(const sAiVec4_08D8& a, const sAiVec4_08D8& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only inline asm (float absolute value).
static inline float aiAbs_08D8(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float aiAtan2_08D8(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float aiFloor_08D8(float x)
{
    float t;
    __asm__("cvt.w.s %0, %1\n\tcvt.s.w %0, %0" : "=f"(t) : "f"(x));
    if (x < t)
    {
        t -= 1.0f;
    }
    return t;
}

static inline float aiWrap_08D8(float x)
{
    return x - aiFloor_08D8(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

static inline void aiSetLean_08D8(char* r, float v)
{
    *(float*)(r + 0x284) = 0.0f;
    *(float*)(r + 0x280) = *(float*)(r + 0x288) = v;
}

struct sAiObj_08D8
{
    float mHeading;  // 0x00
    float mTimer;    // 0x04
    int mFlag;       // 0x08
    float mC;        // 0x0C
    int mId;         // 0x10
    char* mRider;    // 0x14
};

extern "C" int func_001308D8(void* vself, void* in)
{
    sAiObj_08D8* self = (sAiObj_08D8*)vself;
    sAiBits_08D8* bits = (sAiBits_08D8*)((char*)in + 4);
    float b = bits->lo * 0.032258063554763794f;
    float a = bits->hi * 0.032258063554763794f;
    float aa = aiAbs_08D8(a);
    float ab = aiAbs_08D8(b);
    float m = aa < ab ? ab : aa;
    char* r0;
    if (m < 0.1f || aiDot_08D8(*(sAiVec4_08D8*)((r0 = self->mRider) + 0x1E0), *(sAiVec4_08D8*)(r0 + 0x3A0)) < 0.0f || self->mId != 0)
    {
        func_001313A8(self);
        float ra = aiAbs_08D8(*(float*)(self->mRider + 0x280));
        if (ra <= 0.2f || ra >= 0.8f)
        {
            if (m < 0.1f)
                self->mC = 1.0f;
            func_00131428(self);
            return 0;
        }
        return 1;
    }
    if (*(int*)(r0 + 0x320) != 0)
        a = -a;
    float ang = aiAtan2_08D8(a, b);
    float h = *(float*)(self->mRider + 0x280) * 3.1415927410125732f;
    float d = aiWrap_08D8(ang - h);
    int anim = func_00312AA0(*(void**)(self->mRider + 0x784), 2);
    int special = anim == 0x25 || anim == 0x26 || anim == 0x1D || anim == 0x1E;
    if (!special && aiAbs_08D8(d) >= 0.4712389409542084f)
    {
        char* r = self->mRider;
        if (aiAbs_08D8(*(float*)(r + 0x280)) > 0.5f)
        {
            if (d > 0.0f)
                aiSetLean_08D8(r, -0.8500000238418579f);
            else
                aiSetLean_08D8(r, 0.8500000238418579f);
        }
        else
        {
            if (d < 0.0f)
                aiSetLean_08D8(r, -0.15000000596046448f);
            else
                aiSetLean_08D8(r, 0.15000000596046448f);
        }
    }
    else
    {
        char* r = self->mRider;
        float step = d * 0.01666666753590107f * (*(float*)(r + 0x300) * 2.0f);
        float nh;
        if (h < 0.0f && step > 0.0f)
            nh = aiWrap_08D8(h + step - 6.2831854820251465f);
        else if (h > 0.0f && step < 0.0f)
            nh = aiWrap_08D8(h + step + 6.2831854820251465f);
        else
            nh = aiWrap_08D8(h + step);
        aiSetLean_08D8(self->mRider, nh * 0.31830987334251404f);
    }
    char* r3 = self->mRider;
    float ra = aiAbs_08D8(*(float*)(r3 + 0x280));
    if (ra >= 0.15000000596046448f && ra <= 0.8500000238418579f)
    {
        *(float*)(r3 + 0x27C) = 0.5f;
        *(float*)(r3 + 0x278) = *(float*)(r3 + 0x300) * 0.01666666753590107f;
        char* r2 = self->mRider;
        int na;
        if (*(int*)(r2 + 0x330) == 1)
            na = *(float*)(r2 + 0x280) > 0.0f ? 0x1D : 0x1E;
        else
            na = *(float*)(r2 + 0x280) > 0.0f ? 0x25 : 0x26;
        if (anim == na)
            return 1;
        if (!special)
            func_0012FEC8(self);
        cRiderAnimBase_play(*(void**)(self->mRider + 0x784), na, 0, -1.0f);
        return 1;
    }
    func_00131428(self);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00130DD0);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_002A1560(void* mgr, void* rider);
extern "C" void func_0010EB30(void* rider, int id, int a, int b, void* info);

struct sAiBitsA_130DD0
{
    int v : 6;
};

struct sAiBitsB_130DD0
{
    int pad : 6;
    int v : 6;
};

struct sCurvePt_130DD0
{
    float x, y;
};

struct sCurve_130DD0
{
    sCurvePt_130DD0 p[4];
};

extern sCurve_130DD0* D_004A1114;
extern sCurve_130DD0* D_004A111C;

struct sInfo_130DD0
{
    sQuat_12FEC8 pos;
    sQuat_12FEC8 dir;
    sQuat_12FEC8 up;
    float speed;
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sQuat_12FEC8 Scale_130DD0(const sQuat_12FEC8& v, float s)
{
    sQuat_12FEC8 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector divided by scalar).
static inline sQuat_12FEC8 Div_130DD0(const sQuat_12FEC8& v, float s)
{
    sQuat_12FEC8 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only inline asm (float absolute value).
static inline float aiAbs_130DD0(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline float Lerp_130DD0(float x0, float y0, float x1, float y1, float x)
{
    return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
}

static inline float Curve_130DD0(const sCurve_130DD0* c, float x)
{
    if (c->p[1].x < x)
    {
        if (c->p[2].x < x)
        {
            if (c->p[3].x < x)
                return c->p[3].y;
            return Lerp_130DD0(c->p[2].x, c->p[2].y, c->p[3].x, c->p[3].y, x);
        }
        return Lerp_130DD0(c->p[1].x, c->p[1].y, c->p[2].x, c->p[2].y, x);
    }
    if (x < c->p[0].x)
        return c->p[0].y;
    return Lerp_130DD0(c->p[0].x, c->p[0].y, c->p[1].x, c->p[1].y, x);
}

extern "C" int func_00130DD0(void* self, void* in)
{
    char* r = *(char**)((char*)self + 0x14);
    float k = *(float*)(r + 0x300) * 0.01666666753590107f;
    *(float*)((char*)self + 0x4) += k;
    if (*(float*)(r + 0x274) == 1.0f)
        *(float*)((char*)self + 0x8) += k;
    else
        *(float*)((char*)self + 0x8) = 0.0f;
    float a = ((sAiBitsA_130DD0*)((char*)in + 4))->v * 0.032258063554763794f;
    if (*(int*)(*(char**)((char*)self + 0x14) + 0x330) == 2)
        a = -a >? 0.0f;
    else
        a = a >? 0.0f;
    if (*(float*)((char*)self + 0x4) <= 1.0f)
    {
        a = a <? *(float*)((char*)self + 0x4) * 0.5f + 0.5f;
    }
    else
    {
        float b = aiAbs_130DD0(((sAiBitsB_130DD0*)((char*)in + 4))->v * 0.032258063554763794f);
        float m = (a <= b) ? b : a;
        a = 0.0f;
        if (m > 0.5f)
            a = 1.0f;
    }
    float s;
    if ((a <= 0.5f && *(float*)(*(char**)((char*)self + 0x14) + 0x274) > 0.5f) || (a >= 0.5f && *(float*)(*(char**)((char*)self + 0x14) + 0x274) < 0.5f))
    {
        s = 1.0f;
    }
    else
    {
        float s1 = Curve_130DD0(D_004A1114, *(float*)(*(char**)((char*)self + 0x14) + 0x274));
        float s2 = Curve_130DD0(D_004A111C, *(float*)(*(char**)((char*)self + 0x14) + 0x274));
        float mix = *(float*)((char*)self + 0x4) * 0.20000895857810974f <? 1.0f;
        s = s1 * (1.0f - mix) + s2 * mix;
        if (*(float*)(*(char**)((char*)self + 0x14) + 0x274) > 0.800000011920929f)
            func_002A1560(func_0028B180(), *(void**)((char*)self + 0x14));
    }
    char* r3 = *(char**)((char*)self + 0x14);
    *(float*)(r3 + 0x27C) = a;
    *(float*)(r3 + 0x278) = s * k;
    if (*(float*)((char*)self + 0x8) > 1.0f)
    {
        sInfo_130DD0 info;
        char* r4 = *(char**)((char*)self + 0x14);
        float speed = aiLength_12C5C8(*(sAiVec4_12C5C8*)(r4 + 0x1E0));
        info.pos = *(sQuat_12FEC8*)(r4 + 0x110);
        info.up = Scale_130DD0(D_004FF160, -1.0f);
        info.speed = speed;
        if (speed > 0.0010000000474974513f)
            info.dir = Div_130DD0(*(sQuat_12FEC8*)(*(char**)((char*)self + 0x14) + 0x1E0), speed);
        else
            info.dir = D_004FF160;
        char* r5 = *(char**)((char*)self + 0x14);
        if (*(int*)(r5 + 0x330) == 2)
            func_0010EB30(r5, 0x167, 0, *(int*)(r5 + 0x438), &info);
        else
            func_0010EB30(r5, 0x166, 0, *(int*)(r5 + 0x438), &info);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131200);
#ifdef SKIP_ASM
struct sAiStick_131200
{
    int pad0;
    int x : 6;
    int y : 6;
};

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_131200(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" int func_00131200(void* self, void* a1)
{
    float x = ((sAiStick_131200*)a1)->x * 0.032258063554763794f;
    float y = ((sAiStick_131200*)a1)->y * 0.032258063554763794f;
    if (x == 0.0f && aiAbs_131200(y) < 0.5f)
    {
        *(float*)((char*)self + 0xC) += *(float*)(*(char**)((char*)self + 0x14) + 0x300) * 0.01666666753590107f;
    }
    else
    {
        *(float*)((char*)self + 0xC) = 0.0f;
    }
    char* r = *(char**)((char*)self + 0x14);
    if (*(float*)((char*)self + 0xC) > 0.5f ||
        (*(int*)(r + 0x330) == 2 && x > 0.8f) ||
        (*(int*)(r + 0x330) == 1 && x < -0.8f))
    {
        *(int*)(r + 0x27C) = 0;
        *(float*)(r + 0x278) = *(float*)(r + 0x300) * 2.0f * 0.01666666753590107f;
        if (*(float*)(*(char**)((char*)self + 0x14) + 0x274) < 0.5f) return 1;
    }
    if (*(float*)(*(char**)((char*)self + 0x14) + 0x274) == 0.0f) return 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131348);
#ifdef SKIP_ASM
extern "C" void func_001313A8(void*);
extern "C" void func_00131428(void*);
extern "C" float func_00119A38(void*);
extern "C" void func_0010E098(void*, int, float);

extern "C" void func_00131348(void* self)
{
    func_001313A8(self);
    func_00131428(self);
    void* r = *(void**)((char*)self + 0x14);
    int s = *(int*)((char*)r + 0x330);
    if (s >= 1 && s <= 2)
    {
        func_0010E098(*(void**)((char*)self + 0x14), 1, func_00119A38(*(void**)((char*)r + 0x790)));
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001313A8);
#ifdef SKIP_ASM
extern "C" void func_001313A8(void* self)
{
    char* r = *(char**)((char*)self + 0x14);
    if (*(float*)(r + 0x280) < -0.5f)
    {
        *(float*)(r + 0x288) = -1.0f;
        *(float*)(r + 0x284) = *(float*)(r + 0x300) * 0.02500000223517418f;
    }
    else if (*(float*)(r + 0x280) > 0.5f)
    {
        *(float*)(r + 0x288) = 1.0f;
        *(float*)(r + 0x284) = *(float*)(r + 0x300) * 0.02500000223517418f;
    }
    else
    {
        *(float*)(r + 0x288) = 0.0f;
        *(float*)(r + 0x284) = *(float*)(r + 0x300) * 0.02500000223517418f;
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131428);
#ifdef SKIP_ASM
extern "C" void func_0010E098(void*, int, float);
extern "C" float func_00119AD8(void* p, int v);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" void func_00131428(void* self)
{
    int s = func_00312AA0(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 2);
    if (s >= 0x25 && s <= 0x26)
    {
        char* r = *(char**)((char*)self + 0x14);
        if (aiAbs_12F118(*(float*)(r + 0x280)) <= 0.5f)
        {
            func_0010E098(*(void**)((char*)self + 0x14), 1, func_00119AD8(*(void**)(r + 0x790), *(int*)(r + 0x330)));
            cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x1C, 0, -1.0f);
            *(int*)(*(char**)((char*)self + 0x14) + 0x330) = 1;
        }
        else
        {
            func_0012FEC8(self);
            cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x24, 0, -1.0f);
        }
    }
    else if (s >= 0x1D && s <= 0x1E)
    {
        char* r = *(char**)((char*)self + 0x14);
        if (aiAbs_12F118(*(float*)(r + 0x280)) >= 0.5f)
        {
            func_0010E098(*(void**)((char*)self + 0x14), 1, func_00119AD8(*(void**)(r + 0x790), *(int*)(r + 0x330)));
            cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x24, 0, -1.0f);
            *(int*)(*(char**)((char*)self + 0x14) + 0x330) = 2;
        }
        else
        {
            func_0012FEC8(self);
            cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0x1C, 0, -1.0f);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131598);
#ifdef SKIP_ASM
struct sVEntry00131598 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00131598(void* self, void* obj)
{
    sVEntry00131598* vt = *(sVEntry00131598**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001315D0);
#ifdef SKIP_ASM
struct sVEntry001315D0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001315D0(void* self, void* obj)
{
    sVEntry001315D0* vt = *(sVEntry001315D0**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131608__FPv);
#ifdef SKIP_ASM
void func_00131608(void* self)
{
    *(int*)((char*)*(void**)self + 0x35c) = 0;
    *(int*)((char*)*(void**)self + 0x360) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131620);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" int func_00116378(void*);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" int func_00131CC0(void* self);
extern "C" int func_00106848(void*);
extern "C" int func_00107578(void* rider, int on);
extern "C" int func_001162C8(void*, int, int);
extern "C" int func_001161D0(void* rider, float v);
extern "C" int func_001163B0(void* rider, int a, int b);
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" void func_00113E80(void*, float);
extern "C" void func_00113F88(void* rider, float a, float b);
extern "C" void func_00115B58(void*);
extern "C" void func_00115D48(void*);
extern "C" int func_00114CC0(void* rider);
extern "C" int func_00311AE8(void*, int);
int func_00312AA0(void* self, int i);
unsigned int AIrand();

struct sAiVec4_1620
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sAiBitsX_1620
{
    int pad : 20;
    int v : 6;
};

struct sAiBitsY_1620
{
    int pad : 26;
    int v : 6;
};

struct sAiBitsC_1620
{
    int v : 6;
};

struct sAiBitsD_1620
{
    int pad : 6;
    int v : 6;
};

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float aiDot_1620(const sAiVec4_1620& a, const sAiVec4_1620& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float aiLength_1620(const sAiVec4_1620& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only inline asm (float absolute value).
static inline float aiAbs_1620(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ `<?` (min) operator.
static inline float aiClamp_1620(float v, float lo, float hi)
{
    float r = lo;
    if (v >= lo)
        r = v <? hi;
    return r;
}

extern "C" void func_00131620(void* self, void* in)
{
    float zero = 0.0f;
    float x = ((sAiBitsX_1620*)in)->v * 0.032258063554763794f;
    float y = ((sAiBitsY_1620*)in)->v * 0.032258063554763794f;
    float c = ((sAiBitsC_1620*)((char*)in + 4))->v * 0.032258063554763794f;
    char* r = *(char**)self;
    if (aiDot_1620(*(sAiVec4_1620*)(r + 0x1E0), *(sAiVec4_1620*)(r + 0x3A0)) < zero)
        c = zero;
    if (func_00116378(r))
        return;
    if (func_00116120(*(void**)self, (*(int*)in >> 12) & 1, 0))
        return;
    if (func_00131CC0(self))
        return;
    if (*(int*)in & 0x2000)
    {
        if (func_00107578(*(void**)self, y > 0.5f))
            return;
        x = aiClamp_1620(x, -0.5f, 0.5f);
        y = 1.0f;
        c = zero;
    }
    else
    {
        if (func_00106848(*(void**)self))
            return;
    }
    int w = *(int*)in;
    if (func_001162C8(*(void**)self, (w >> 15) & 1, (w >> 14) & 1))
        return;
    if (*(int*)in & 0x8000)
    {
        y = 1.0f;
        c = 0.0f;
    }
    if (func_001161D0(*(void**)self, ((sAiBitsD_1620*)((char*)in + 4))->v * 0.032258063554763794f))
        return;
    int w2 = *(int*)in;
    if (func_001163B0(*(void**)self, (w2 >> 18) & 1, (w2 >> 19) & 1))
        x = aiClamp_1620(x, -0.5f, 0.5f);
    int w3 = *(int*)in;
    func_00114130(*(void**)self, (w3 >> 17) & 1, (w3 >> 16) & 1);
    func_00113E80(*(void**)self, x);
    func_00113F88(*(void**)self, y, c);
    func_00115B58(*(void**)self);
    func_00115D48(*(void**)self);
    int cur = func_00312AA0(*(void**)(*(char**)self + 0x784), 2);
    int anim = cur;
    if (cur == 0x16)
    {
        char* r1 = *(char**)self;
        *(int*)(r1 + 0x204) = 0;
        *(float*)(r1 + 0x200) = 0.03333333507180214f;
        char* r2 = *(char**)self;
        *(int*)(r2 + 0x21C) = 0;
        *(float*)(r2 + 0x218) = 0.03333333507180214f;
        char* r3 = *(char**)self;
        *(float*)(r3 + 0x224) = 0.03333333507180214f;
        *(int*)(r3 + 0x228) = 0;
    }
    else if (cur == 0x15 || (*(float*)(*(char**)self + 0x2DC) == 0.0f && func_00114CC0(*(void**)self)))
    {
        anim = 0x15;
        char* r1 = *(char**)self;
        *(int*)(r1 + 0x204) = 0;
        *(float*)(r1 + 0x200) = 0.03333333507180214f;
        char* r2 = *(char**)self;
        *(float*)(r2 + 0x218) = 0.03333333507180214f;
        *(int*)(r2 + 0x21C) = 0;
    }
    else if (func_00311AE8(*(void**)(*(char**)self + 0x784), 2) == 10)
    {
        char* r1 = *(char**)self;
        *(int*)(r1 + 0x204) = 0;
        *(float*)(r1 + 0x200) = 0.03333333507180214f;
    }
    else if (func_00311AE8(*(void**)(*(char**)self + 0x784), 2) == 5)
    {
        char* r1 = *(char**)self;
        *(float*)(r1 + 0x200) = 0.03333333507180214f;
        *(float*)(r1 + 0x204) = *(float*)(r1 + 0x1F0);
        char* r2 = *(char**)self;
        *(float*)(r2 + 0x218) = 0.03333333507180214f;
        *(int*)(r2 + 0x21C) = 0;
    }
    else
    {
        char* r1 = *(char**)self;
        float spd = aiLength_1620(*(sAiVec4_1620*)(r1 + 0x1E0));
        if (*(float*)(r1 + 0x214) == 0.0f)
        {
            *(float*)(r1 + 0x204) = *(float*)(r1 + 0x1F0);
            *(float*)(r1 + 0x200) = 0.03333333507180214f;
            if (spd < 833.3333740234375f && (y > 0.0f || aiAbs_1620(x) > 0.2f))
            {
                anim = 0x16;
            }
            else
            {
                char* r2 = *(char**)self;
                if (*(int*)(r2 + 0x438) == 4)
                {
                    float a = aiAbs_1620(*(float*)(r2 + 0x1F0));
                    if (*(float*)(r2 + 0x220) <= (1.0f - a) * 0.5f)
                        anim = 0xE;
                    else if (*(float*)(r2 + 0x2FC) > 0.0f && a < 0.30000001192092896f)
                        anim = 8;
                    else
                        anim = 0xF;
                }
                else if (aiAbs_1620(*(float*)(r2 + 0x1FC)) > 0.6000000238418579f &&
                         aiAbs_1620(*(float*)(r2 + 0x3B8)) > 0.699999988079071f &&
                         (AIrand() & 1) == 0)
                {
                    char* r3 = *(char**)self;
                    float v = *(float*)(r3 + 0x1FC);
                    if (*(int*)(r3 + 0x320) != 0)
                        v = -v;
                    anim = v < 0.0f ? 0x10 : 0x11;
                }
                else
                {
                    char* r3 = *(char**)self;
                    if (*(float*)(r3 + 0x220) <= (1.0f - aiAbs_1620(*(float*)(r3 + 0x1F0))) * 0.5f)
                        anim = 5;
                    else if (*(float*)(r3 + 0x2FC) > 0.0f)
                        anim = 8;
                    else if (spd < 1666.666748046875f || (unsigned int)(*(int*)(r3 + 0x438) - 2) < 2)
                        anim = 7;
                    else
                        anim = 6;
                }
            }
        }
        else
        {
            *(float*)(r1 + 0x204) = 0.0f;
            *(float*)(r1 + 0x200) = 0.03333333507180214f;
            float lim = 694.4444580078125f;
            if (cur == 0xC || cur == 0xD)
                lim = 972.2222290039062f;
            if (lim < spd)
            {
                anim = 0xB;
            }
            else
            {
                char* r2 = *(char**)self;
                float t = *(float*)(r2 + 0x214);
                if (aiAbs_1620(t) < 0.800000011920929f)
                    anim = 0xB;
                else if (t > 0.0f)
                    anim = *(int*)(r2 + 0x320) ? 0xC : 0xD;
                else
                    anim = *(int*)(r2 + 0x320) ? 0xD : 0xC;
            }
        }
    }
    if (anim != cur)
        cRiderAnimBase_play(*(void**)(*(char**)self + 0x784), anim, 0, -1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131C30);
#ifdef SKIP_ASM
extern "C" int func_00311AE8(void*, int);
extern "C" void func_00311E88(void*, int, float);
extern "C" char* func_00311B20(void*, int);

extern "C" void func_00131C30(void* self, int a1)
{
    if (a1 != 4)
    {
        if (func_00311AE8(*(void**)(*(char**)self + 0x784), 1) == 3 ||
            func_00311AE8(*(void**)(*(char**)self + 0x784), 1) == 0xD)
        {
            func_00311E88(*(void**)(*(char**)self + 0x784), 0, 0.10000000149011612f);
            *(float*)(func_00311B20(*(void**)(*(char**)self + 0x784), 1) + 0x90) = 1.0f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131CC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_0011FE98(void* self);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");

extern "C" int func_00131CC0(void* self)
{
    if (func_0011FE98(*(void**)self) == 1)
    {
        func_0011FEC8_impl(*(void**)self, 4);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131D08);
#ifdef SKIP_ASM
extern "C" void func_00131D08(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(int*)(*(char**)((char*)self + 0x8) + 0x360) = 0;
    *(int*)((char*)self + 0x4) = -1;
    char* r = *(char**)((char*)self + 0x8);
    *(float*)(r + 0x200) = 0.06666667014360428f;
    *(int*)(r + 0x204) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00131D30);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
extern "C" bool func_001446A0(void* self, int bit);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" int func_001161D0(void* rider, float v);
extern "C" void func_00132060(void* self, int neg);
extern "C" int func_00132620(void* self, int id);
extern "C" int func_00132770(void* self, void* a1);

struct sPadA_131D30
{
    int pad : 17;
    int id : 8;
};

struct sPadB_131D30
{
    int pad : 25;
    int v : 6;
};

struct sPadC_131D30
{
    int x : 6;
    int y : 6;
};

static inline float clamp_131D30(float v, float lo, float hi)
{
    if (v >= lo)
        return v <? hi;
    return lo;
}

extern "C" void func_00131D30(void* self, void* in)
{
    if (func_00116120(*(void**)((char*)self + 0x8), (*(int*)in >> 12) & 1, 0))
        return;
    if (func_00132770(self, in))
        return;
    int w = *(int*)in;
    if (func_001162C8(*(void**)((char*)self + 0x8), (w >> 14) & 1, (w >> 13) & 1))
        return;
    if (func_00132620(self, ((sPadA_131D30*)in)->id))
        return;
    int w2 = *(int*)in;
    float k = 0.032258063554763794f;
    float zero = 0.0f;
    func_00114130(*(void**)((char*)self + 0x8), (w2 >> 16) & 1, (w2 >> 15) & 1);
    func_00113F38(*(void**)((char*)self + 0x8), ((sPadB_131D30*)in)->v * k);
    func_00113F88(*(void**)((char*)self + 0x8), zero, zero);
    func_00115B58(*(void**)((char*)self + 0x8));
    func_00115D48(*(void**)((char*)self + 0x8));
    sPadC_131D30* in2 = (sPadC_131D30*)((char*)in + 4);
    if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 2) == 0xE) {
        if (!func_001446A0(func_00311B20(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 2) + 0xB0, 0))
            return;
        if (func_001161D0(*(void**)((char*)self + 0x8), in2->y * k))
            return;
        float fy = in2->x * k;
        if (fy == zero)
            return;
        func_00132060(self, fy < zero);
        return;
    }
    if (func_001161D0(*(void**)((char*)self + 0x8), in2->y * k))
        return;
    float fx = in2->y * k;
    float fy = in2->x * k;
    float v = fy;
    if (fx != zero && fy == zero)
        v = fx;
    if (v != 0.0f) {
        char* r = *(char**)((char*)self + 0x8);
        *(float*)(r + 0x240) = 0.0f;
        *(float*)(r + 0x23C) = 0.06666667014360428f;
        func_00132060(self, v < 0.0f);
        return;
    }
    if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 2) == 0xA) {
        char* r = *(char**)((char*)self + 0x8);
        *(float*)(r + 0x240) = 0.0f;
        *(float*)(r + 0x23C) = 0.06666667014360428f;
        return;
    }
    char* r = *(char**)((char*)self + 0x8);
    *(float*)(r + 0x240) = clamp_131D30(*(float*)(*(char**)(r + 0x77C) + 0xC8) * 1.2000000476837158f, -1.0f, 1.0f);
    *(float*)(r + 0x23C) = 0.06666667014360428f;
    int cur = func_00312AA0(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 2);
    char* r2 = *(char**)((char*)self + 0x8);
    int s = *(int*)(r2 + 0x328);
    int anim;
    if (s == 4)
        anim = 0x14;
    else {
        anim = 0x12;
        if (s == 3) anim = 0x13;
    }
    if (cur != anim)
        cRiderAnimBase_play(*(void**)(r2 + 0x784), anim, 0, -1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00132048);
#ifdef SKIP_ASM
extern "C" void func_00132048(void* self)
{
    char* r = *(char**)((char*)self + 0x8);
    *(float*)(r + 0x23C) = 0.06666667014360428f;
    *(int*)(r + 0x240) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00132060);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void func_0010E098(void*, int, float);
extern "C" void func_00116930(void* rider);
float func_00119918_2060(void* p, int st, float h) __asm__("func_00119918__FPvi");

struct sQuat_2060
{
    float x, y, z, w;
    sQuat_2060() {}
    sQuat_2060(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

extern sQuat_2060 D_004FF130_2060 __asm__("D_004FF130");
extern sQuat_2060 D_004FF160_2060 __asm__("D_004FF160");

static inline sQuat_2060 AxisAngle_2060(const sQuat_2060& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sQuat_2060(s * axis.x, s * axis.y, s * axis.z, c);
}

#define RIDER_2060 (*(char**)((char*)self + 8))

static inline void setRot_2060(char* anim, float a)
{
    *(sQuat_2060*)(anim + 0x30) = D_004FF130_2060;
    *(sQuat_2060*)(anim + 0x40) = AxisAngle_2060(D_004FF160_2060, -a);
}

static inline void flip_2060(void* self, int f)
{
    *(int*)(RIDER_2060 + 0x320) = f;
    *(int*)(*(char**)(RIDER_2060 + 0x784) + 0x18) = f;
    *(float*)(RIDER_2060 + 0x238) = -*(float*)(RIDER_2060 + 0x238);
    *(float*)(RIDER_2060 + 0x240) = -*(float*)(RIDER_2060 + 0x240);
}
extern "C" void func_00132060(void* self, int dir)
{
    if (dir != 0) {
        *(float*)self -= 1.5707964897155762f;
        switch (*(int*)(RIDER_2060 + 0x328)) {
    case 1:
        setRot_2060(*(char**)(RIDER_2060 + 0x784), -1.5707963705062866f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x31, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 3;
        break;
    case 2:
        flip_2060(self, 0);
        setRot_2060(*(char**)(RIDER_2060 + 0x784), 1.5707963705062866f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x35, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 4;
        break;
    case 3:
        flip_2060(self, 1);
        setRot_2060(*(char**)(RIDER_2060 + 0x784), 3.1415927410125732f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x33, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 2;
        break;
    case 4:
        setRot_2060(*(char**)(RIDER_2060 + 0x784), 0.0f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x36, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 1;
        break;
        }
    } else {
        *(float*)self += 1.5707964897155762f;
        switch (*(int*)(RIDER_2060 + 0x328)) {
    case 1:
        setRot_2060(*(char**)(RIDER_2060 + 0x784), 1.5707963705062866f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x32, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 4;
        break;
    case 2:
        flip_2060(self, 0);
        setRot_2060(*(char**)(RIDER_2060 + 0x784), -1.5707963705062866f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x34, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 3;
        break;
    case 3:
        setRot_2060(*(char**)(RIDER_2060 + 0x784), 0.0f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x33, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 1;
        break;
    case 4:
        flip_2060(self, 1);
        setRot_2060(*(char**)(RIDER_2060 + 0x784), 3.1415927410125732f);
        cRiderAnimBase_play(*(void**)(RIDER_2060 + 0x784), 0x36, 0, -1.0f);
        *(int*)(RIDER_2060 + 0x328) = 2;
        break;
        }
    }
    func_0010E098(RIDER_2060, 1, func_00119918_2060(*(void**)(RIDER_2060 + 0x790), *(int*)(RIDER_2060 + 0x328), *(float*)self));
    func_00116930(RIDER_2060);
}
#undef RIDER_2060
#endif

//100%
INCLUDE_ASM("ai/ai", func_00132620);
#ifdef SKIP_ASM
// PORT: prototype mismatch. func_0011FEC8 is defined with one param, but its body
// forwards $5 to func_00111538.
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" void* func_0028B180();
extern "C" void func_00299B70(void* snd, void* rider);

extern "C" int func_00132620(void* self, int id)
{
    if (id != -1)
    {
        char* r = *(char**)((char*)self + 0x8);
        if (*(float*)(r + 0x2F0) > 0.0f && ((*(int*)(r + 0xB2C) >> 1) & 1))
        {
            *(int*)(*(char**)(r + 0x77C) + 0x394) = id;
            func_0011FEC8_impl(*(void**)((char*)self + 0x8), 0xC);
            return 1;
        }
        if (id != *(int*)((char*)self + 0x4))
        {
            func_00299B70(func_0028B180(), *(void**)((char*)self + 0x8));
        }
    }
    *(int*)((char*)self + 0x4) = id;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001326C8);
#ifdef SKIP_ASM
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" void func_001326C8(void* self, int alt)
{
    char* r = *(char**)((char*)self + 0x8);
    int s = *(int*)(r + 0x328);
    if (s == 4)
    {
        if (alt)
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x45, 0, -1.0f);
        else
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x14, 0, -1.0f);
    }
    else if (s == 3)
    {
        if (alt)
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x46, 0, -1.0f);
        else
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x13, 0, -1.0f);
    }
    else
    {
        if (alt)
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x44, 0, -1.0f);
        else
            cRiderAnimBase_play(*(void**)(r + 0x784), 0x12, 0, -1.0f);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00132770);
#ifdef SKIP_ASM
int func_0011FE98(void* self);
// PORT: prototype mismatch. func_0011FEC8 is defined with one param, but its body
// forwards $5 to func_00111538.
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" int func_00311AE8(void*, int);
extern "C" char* func_00311B20(void*, int);
extern "C" bool func_001446A0(void* self, int bit);
extern "C" void func_00115640(void* rider);

struct sAiBits00132770
{
    int v : 6;
};

extern "C" int func_00132770(void* self, void* a1)
{
    if (func_0011FE98(*(void**)((char*)self + 0x8)) != 1)
    {
        return 0;
    }
    if (func_00311AE8(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 2) == 0xE)
    {
        if (!func_001446A0(func_00311B20(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 2) + 0xB0, 0))
        {
            return 0;
        }
    }
    func_00115640(*(void**)((char*)self + 0x8));
    if (((sAiBits00132770*)((char*)a1 + 4))->v * 0.032258063554763794f != 0.0f)
    {
        func_0011FEC8_impl(*(void**)((char*)self + 0x8), 5);
    }
    else
    {
        func_0011FEC8_impl(*(void**)((char*)self + 0x8), 4);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00132840);
#ifdef SKIP_ASM
struct sVEntry00132840 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00132840(void* self, void* obj)
{
    sVEntry00132840* vt = *(sVEntry00132840**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x8);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00132878);
#ifdef SKIP_ASM
struct sVEntry00132878 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00132878(void* self, void* obj)
{
    sVEntry00132878* vt = *(sVEntry00132878**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x8);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001328B0);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_0029DC48(void* self, void* rider);
extern "C" float func_00312790(char* self, int a1);
extern "C" void func_00132FB8(void* self, int a1, int a2);
extern "C" void func_00311E88(void*, int, float);
extern char D_00459FC8[];

extern "C" void func_001328B0(void* self)
{
    float k = 0.05000000447034836f;
    float blend = 0.33000001311302185f;
    char* r = *(char**)((char*)self + 0x14);
    *(float*)(r + 0x200) = k;
    *(int*)(r + 0x204) = 0;
    char* r2 = *(char**)((char*)self + 0x14);
    *(float*)(r2 + 0x1F4) = k;
    *(int*)(r2 + 0x1F8) = 0;
    *(int*)(*(char**)((char*)self + 0x14) + 0x32C) = 1;
    func_0029DC48(func_0028B180(), *(void**)((char*)self + 0x14));
    char* r3 = *(char**)((char*)self + 0x14);
    float d = func_00312790(*(char**)(r3 + 0x784), *(int*)(D_00459FC8 + *(int*)((char*)self + 0x10) * 8 + *(int*)(r3 + 0x32C) * 16));
    *(float*)(*(char**)(*(char**)((char*)self + 0x14) + 0x784) + 0x1C) = d / *(float*)self;
    func_00132FB8(self, *(int*)(*(char**)((char*)self + 0x14) + 0x32C), *(int*)((char*)self + 0x10));
    *(float*)(*(char**)(*(char**)((char*)self + 0x14) + 0x784) + 0x1C) = 1.0f;
    *(int*)((char*)self + 0x4) = 0;
    func_00311E88(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 1, blend);
    func_00311E88(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 0, blend);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001329B0);
#ifdef SKIP_ASM
struct sV4_29B0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector length via vsqrt).
static inline float Length_29B0(const sV4_29B0& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

struct sRider_29B0 {
    char pad[0x1E0];
    sV4_29B0 vel;
};

struct sFlags_29B0 {
    char pad[0x1C];
    int flags;
};

struct sOwner_29B0 {
    char pad[0x58];
    sFlags_29B0* ctl;
};

struct sState_29B0 {
    float t;            // 0x0
    int f4;             // 0x4
    int fast;           // 0x8
    int ctl;            // 0xC
    int flag;           // 0x10
    sRider_29B0* rider; // 0x14
};

extern "C" void func_001329B0(sState_29B0* s, sOwner_29B0* o, int flag, float t)
{
    int on = 1;
    s->t = t;
    s->flag = flag ? on : 0;
    s->fast = Length_29B0(s->rider->vel) > 2222.2222f;
    bool c = false;
    sFlags_29B0* f = o->ctl;
    if (f != 0)
        c = (f->flags & 1) ? on : 0;
    s->ctl = c;
}
#endif

INCLUDE_ASM("ai/ai", func_00132A30);

//100%
INCLUDE_ASM("ai/ai", func_00132F98);
#ifdef SKIP_ASM
extern "C" void func_00132F98(void* self)
{
    char* a = *(char**)((char*)self + 0x14);
    *(int*)(a + 0x32C) = 0;
    char* b = *(char**)((char*)self + 0x14);
    *(float*)(b + 0x248) = 0.05000000447034836f;
    *(int*)(b + 0x24C) = 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00132FB8);
#ifdef SKIP_ASM
extern "C" void cRider_updateOrientationImplicit(void*);
extern "C" void cRiderAnimBase_changeHeadingOffset(void* self, float angle);

struct sAnimEntry_132FB8
{
    int anim;
    int flip;
};
// Typed view of D_00459FC8 (func_001328B0 reads it as raw bytes); bound by asm label.
extern sAnimEntry_132FB8 D_00459FC8_tbl[][2] __asm__("D_00459FC8");

struct sVec4_132FB8
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVec3_132FB8
{
    float x, y, z;
    sVec3_132FB8(sVec4_132FB8 v) { x = v.x; y = v.y; z = v.z; }
};

struct sQuat_132FB8
{
    float x, y, z, w;
    sQuat_132FB8() {}
    sQuat_132FB8(const sVec3_132FB8& v, float aw) { x = v.x; y = v.y; z = v.z; w = aw; }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sQuat_132FB8 QuatMul_132FB8(const sQuat_132FB8& a, const sQuat_132FB8& b)
{
    sQuat_132FB8 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

extern "C" void func_00132FB8(void* self, int a1, int a2)
{
    if (D_00459FC8_tbl[a1][a2].flip != 0)
    {
        char* r = *(char**)((char*)self + 0x14);
        sQuat_132FB8 t = QuatMul_132FB8(sQuat_132FB8(sVec3_132FB8(*(sVec4_132FB8*)(r + 0x1C0)), 0.0f), *(sQuat_132FB8*)(r + 0x120));
        *(sQuat_132FB8*)(*(char**)((char*)self + 0x14) + 0x120) = t;
        cRider_updateOrientationImplicit(*(void**)((char*)self + 0x14));
        cRiderAnimBase_changeHeadingOffset(*(void**)(*(char**)((char*)self + 0x14) + 0x784), 3.1415927410125732f);
    }
    cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x14) + 0x784), D_00459FC8_tbl[a1][a2].anim, 0, -1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001330B8);
#ifdef SKIP_ASM
struct sVEntry001330B8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001330B8(void* self, void* obj)
{
    sVEntry001330B8* vt = *(sVEntry001330B8**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001330F0);
#ifdef SKIP_ASM
struct sVEntry001330F0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001330F0(void* self, void* obj)
{
    sVEntry001330F0* vt = *(sVEntry001330F0**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00133128);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" float func_001495A8(void* self, int rider, int value);
extern "C" char* func_00311B20(void*, int);
extern "C" float func_00135180(void* self);
extern "C" void func_00135B30(void* self, float a, float b);

extern "C" void func_00133128(void* self)
{
    float lo = 4.499661445617676f;
    *(int*)((char*)self + 0x8) = -1;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x30) = 0;
    *(int*)((char*)self + 0x34) = 0;
    *(float*)((char*)self + 0x38) = lo;
    *(float*)((char*)self + 0x3C) = lo;
    *(float*)((char*)self + 0x40) = 0.0f;
    *(float*)((char*)self + 0x44) = 0.0f;
    *(float*)(*(char**)((char*)self + 0x58) + 0x2DC) = 0.0f;
    *(float*)(*(char**)((char*)self + 0x58) + 0x2E0) = 0.0f;
    *(float*)((char*)self + 0x48) = 0.0f;
    *(float*)((char*)self + 0x50) = 1.0000000150474662e+30f;
    char* r = *(char**)((char*)self + 0x58);
    *(float*)((char*)self + 0x4C) = 0.0f;
    *(float*)((char*)self + 0x54) = 0.0f;
    if (*(float*)(r + 0x2A4) != 0.0f || *(float*)(r + 0x2B0) != 0.0f)
    {
        *(int*)((char*)self + 0xC) = 0;
        float x = *(float*)(r + 0x2A4);
        float a = __builtin_fabsf(x);
        float b = __builtin_fabsf(*(float*)(r + 0x2B0));
        float m;
        if (b < a)
            m = a;
        else
            m = b;
        if (x != 0.0f)
        {
            float v = m * 7.00038480758667f >? lo;
            *(float*)((char*)self + 0x38) = v;
            *(float*)(r + 0x2DC) = v;
        }
        r = *(char**)((char*)self + 0x58);
        if (*(float*)(r + 0x2B0) != 0.0f)
        {
            float v = (m * 7.00038480758667f >? lo) * 0.6666666865348816f;
            *(float*)((char*)self + 0x3C) = v;
            *(float*)(r + 0x2E0) = v;
        }
        *(float*)((char*)self + 0x40) = func_00135180(self);
        char* r2 = *(char**)((char*)self + 0x58);
        func_00135B30(self, *(float*)(r2 + 0x2B0), *(float*)(r2 + 0x2A4));
        float s = func_001495A8(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(*(char**)((char*)self + 0x58) + 0x86C), *(int*)(*(char**)((char*)self + 0x58) + 0xB34));
        char* r4 = *(char**)((char*)self + 0x58);
        float t = (s * 0.5002591609954834f + 1.0f) * (*(float*)(r4 + 0x2E0) >? *(float*)(r4 + 0x2DC)) * 0.14284929633140564f;
        *(float*)(func_00311B20(*(void**)(r4 + 0x784), 2) + 0x90) = t;
        *(int*)self = 1;
    }
    else
    {
        *(int*)self = 0;
        *(int*)((char*)self + 0xC) = 3;
    }
}
#endif

INCLUDE_ASM("ai/ai", func_00133308);

//100%
INCLUDE_ASM("ai/ai", func_00134CB0);
#ifdef SKIP_ASM
extern "C" void func_00311E88(void*, int, float);
extern "C" void cRider_updateOrientationImplicit(void*);
extern "C" void func_00134DD0(void* self, void* pos);

extern "C" void func_00134CB0(void* self)
{
    func_00311E88(*(void**)(*(char**)((char*)self + 0x58) + 0x784), 1, 0.33000001311302185f);
    char* r = *(char**)((char*)self + 0x58);
    *(int*)(r + 0x2AC) = 0;
    *(int*)(r + 0x2A4) = 0;
    *(int*)(r + 0x2A8) = 0;
    char* r2 = *(char**)((char*)self + 0x58);
    *(int*)(r2 + 0x2B8) = 0;
    *(int*)(r2 + 0x2B0) = 0;
    *(int*)(r2 + 0x2B4) = 0;
    char* r3 = *(char**)((char*)self + 0x58);
    *(float*)(r3 + 0x290) = 0.01666666753590107f;
    *(int*)(r3 + 0x294) = 0;
    char* r4 = *(char**)((char*)self + 0x58);
    *(float*)(r4 + 0x29C) = 0.01666666753590107f;
    *(int*)(r4 + 0x2A0) = 0;
    func_00134DD0(self, *(char**)((char*)self + 0x58) + 0x110);
    cRider_updateOrientationImplicit(*(void**)((char*)self + 0x58));
    *(float*)(*(char**)((char*)self + 0x58) + 0x2DC) *= 0.7500380277633667f;
    char* r5 = *(char**)((char*)self + 0x58);
    float a = *(float*)(r5 + 0x2DC);
    if (a > 4.7123894691467285f)
        *(float*)(r5 + 0x2DC) = 7.853982448577881f;
    else if (a > 3.1415929794311523f)
        *(float*)(r5 + 0x2DC) = 4.7123894691467285f;
    else if (a > 0.0f)
        *(float*)(r5 + 0x2DC) = 1.5707964897155762f;
    else
        *(float*)(r5 + 0x2DC) = 0.0f;
    *(int*)(*(char**)((char*)self + 0x58) + 0x2E0) = 0;
    if (*(float*)((char*)self + 0x1C) > *(float*)((char*)self + 0x14))
    {
        *(float*)(*(char**)((char*)self + 0x58) + 0x2DC) = -*(float*)(*(char**)((char*)self + 0x58) + 0x2DC);
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00134DD0);
#ifdef SKIP_ASM
extern "C" float func_00135180(void* self);
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern sQuat_12BE20 D_004FF140_134DD0 __asm__("D_004FF140");
extern sQuat_12BE20 D_004FF150_134DD0 __asm__("D_004FF150");

struct sXf_134DD0
{
    sQuat_12BE20 pos;
    sQuat_12BE20 rot;
};

// PORT: PS2-only VU0 inline asm (vector times scalar, constant vector through a register).
static inline sQuat_12BE20 ScaleO_134DD0(const sQuat_12BE20& v, float s)
{
    sQuat_12BE20 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "o"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a - b, constant b through a register).
static inline sQuat_12BE20 SubO_134DD0(const sQuat_12BE20& a, const sQuat_12BE20& b)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "o"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (dst = a - b).
static inline void SubTo_134DD0(sQuat_12BE20& dst, const sQuat_12BE20& a, const sQuat_12BE20& b)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    dst = r;
}

// PORT: PS2-only VU0 inline asm (dst = normalize via rsqrt).
static inline void NormTo_134DD0(sQuat_12BE20& dst, const sQuat_12BE20& v)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    dst = r;
}

// PORT: PS2-only VU0 inline asm (dst += b).
static inline void AddTo_134DD0(sQuat_12BE20& dst, const sQuat_12BE20& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (dst += b, label before a call).
static inline void AddToL_134DD0(sQuat_12BE20& dst, const sQuat_12BE20& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        "1:\n"
        : "=m"(dst)
        : "m"(dst), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sQuat_12BE20 Norm_134DD0(const sQuat_12BE20& v)
{
    sQuat_12BE20 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

static inline sQuat_12BE20 AxisAngleB_134DD0(const sQuat_12BE20& axis, float angle) return r
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    r.w = c;
    r.x = s * axis.x;
    r.y = s * axis.y;
    r.z = s * axis.z;
}

extern "C" void func_00134DD0_x(void* self, sXf_134DD0* xf) __asm__("func_00134DD0");
extern "C" void func_00134DD0_x(void* self, sXf_134DD0* xf)
{
    char* rd = *(char**)((char*)self + 0x58);
    char* trk = *(char**)(rd + 0x780);
    sQuat_12BE20* n = (sQuat_12BE20*)((*(int*)(rd + 0x89C) << 4) + *(int*)(trk + 0x24));
    float a1 = -(*(float*)((char*)self + 0x20) + *(float*)((char*)self + 0x28));
    float a2 = *(float*)((char*)self + 0x24) + *(float*)((char*)self + 0x2C);
    sQuat_12BE20 d = SubO_134DD0(sQuat_12BE20(n->x * *(float*)(trk + 0x140), n->y * *(float*)(trk + 0x144),
                                              n->z * *(float*)(trk + 0x148), n->w * *(float*)(trk + 0x14C)),
                                 D_004FF130_12BE20);
    {
        sQuat_12BE20 v = Rot_12E010(xf->rot, d);
        AddToL_134DD0(xf->pos, v);
        sQuat_12BE20 pad;
        sQuat_12BE20 q1;
        (q1 = AxisAngle_12BE20(D_004FF160_12BE20, a1)), (xf->rot = QuatMul_12E010(xf->rot, q1));
    }
    float cur = func_00135180(self);
    float old = *(float*)((char*)self + 0x40);
    float delta = __builtin_fabsf(old - cur) * 0.03333333507180214f;
    float nv;
    if (cur + delta < old)
        nv = old - delta;
    else if (old < cur - delta)
        nv = old + delta;
    else
        nv = cur;
    *(float*)((char*)self + 0x40) = nv;
    sQuat_12BE20 ax = Norm_134DD0(Sub_12E010(ScaleO_134DD0(D_004FF150_134DD0, nv),
                                             ScaleO_134DD0(D_004FF140_134DD0, 1.0f - *(float*)((char*)self + 0x40))));
    {
        sQuat_12BE20 q3;
        (q3 = AxisAngleB_134DD0(ax, a2)), (xf->rot = QuatMul_12E010(xf->rot, q3));
    }
    sQuat_12BE20 w = Scale_12E010(d, -1.0f);
    sQuat_12BE20 u = Rot_12E010(xf->rot, w);
    AddTo_134DD0(xf->pos, u);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135180);
#ifdef SKIP_ASM
extern "C" float func_0031C228(float x);

static inline float aiAtan2_135180(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_135180(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: sqrt.s (sqrtf without errno check)
static inline float aiSqrt_135180(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

// PORT: g++ `<?` (min) operator.
static inline float aiClamp_135180(float v, float lo, float hi)
{
    if (v >= lo) return v <? hi;
    return lo;
}

extern "C" float func_00135180(void* self)
{
    char* r = *(char**)((char*)self + 0x58);
    float x = *(float*)(r + 0x2DC);
    float y = *(float*)(r + 0x2E0);
    float ax = aiAbs_135180(x);
    float ay = aiAbs_135180(y);
    float mag = aiSqrt_135180(x * x + y * y) * 0.14284929633140564f;
    float ang = aiAtan2_135180(ay, ax);
    float c = aiClamp_135180(mag - 0.30000001192092896f, 0.0f, 0.699999988079071f);
    return c * 1.4285714626312256f * (1.0f - aiAbs_135180(ang - 0.7853982448577881f) / 0.7853982448577881f);
}
#endif

INCLUDE_ASM("ai/ai", func_001352A8);

//100%
INCLUDE_ASM("ai/ai", func_00135B30);
#ifdef SKIP_ASM
extern "C" void func_00135B30(void* self, float a, float b)
{
    char* s = (char*)self;
    if (b > 0.0f)
        *(float*)(s + 0x14) = 3.1415929794311523f;
    else if (b < 0.0f)
        *(float*)(s + 0x14) = -3.1415929794311523f;
    else
        *(float*)(s + 0x14) = 0.0f;
    if (a > 0.0f)
        *(float*)(s + 0x10) = 6.283185958862305f;
    else if (a < 0.0f)
        *(float*)(s + 0x10) = -6.283185958862305f;
    else
        *(float*)(s + 0x10) = 0.0f;
    *(float*)(s + 0x1C) += *(float*)(s + 0x28);
    *(float*)(s + 0x18) += *(float*)(s + 0x2C);
    *(float*)(s + 0x20) += *(float*)(s + 0x28);
    *(float*)(s + 0x24) += *(float*)(s + 0x2C);
    *(float*)(s + 0x28) = 0.0f;
    *(float*)(s + 0x2C) = 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135BE0);
#ifdef SKIP_ASM
extern "C" int func_00114DB8(void* rider);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float aiFloor_135BE0(float x)
{
    float t;
    __asm__("cvt.w.s %0, %1\n\tcvt.s.w %0, %0" : "=f"(t) : "f"(x));
    if (x < t)
    {
        t -= 1.0f;
    }
    return t;
}

static inline float aiWrap_135BE0(float x)
{
    return x - aiFloor_135BE0(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

extern "C" int func_00135BE0(void* self)
{
    char* s = (char*)self;
    if (func_00114DB8(*(void**)(s + 0x58)) != 0)
    {
    *(float*)(s + 0x20) = aiWrap_135BE0(*(float*)(s + 0x20) + 3.1415927410125732f);
    *(float*)(s + 0x24) = -*(float*)(s + 0x24);
    *(float*)(s + 0x2C) = -*(float*)(s + 0x2C);
    *(float*)(s + 0x18) = -*(float*)(s + 0x18);
    *(float*)(s + 0x10) = -*(float*)(s + 0x10);
    cRiderAnimBase_play(*(void**)(*(char**)(s + 0x58) + 0x784), 0x120, 0, -1.0f);
    return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135CB0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" float func_001495A8(void* self, int rider, int value);

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_135CB0(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_00135CB0(void* self, float* a, float* b)
{
    float pi = 3.1415929794311523f;
    float d = aiAbs_135CB0(*(float*)((char*)self + 0x1C) - *(float*)((char*)self + 0x14));
    if (d > pi) d -= pi;
    *a = d / *(float*)((char*)self + 0x38);
    *b = pi / *(float*)((char*)self + 0x38);
    if (*(float*)(*(char**)((char*)self + 0x58) + 0x2EC) > 0.0f)
    {
        *b *= 0.5000624656677246f;
        *a *= 0.5000624656677246f;
    }
    float s = func_001495A8(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(*(char**)((char*)self + 0x58) + 0x86C), *(int*)(*(char**)((char*)self + 0x58) + 0xB34));
    float m = 1.0f / (s * 0.5002591609954834f + 1.0f);
    *b *= m;
    *a *= m;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135DB0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" float func_001495A8(void* self, int rider, int value);

// PORT: PS2-only inline asm (float absolute value), as an SDK math-header fabsf would.
static inline float aiAbs_135DB0(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_00135DB0(void* self, float* a, float* b)
{
    float twopi = 6.283185958862305f;
    float d = aiAbs_135DB0(*(float*)((char*)self + 0x18) - *(float*)((char*)self + 0x10));
    if (d > twopi) d -= twopi;
    *a = d / *(float*)((char*)self + 0x3C);
    *b = twopi / *(float*)((char*)self + 0x3C);
    if (*(float*)(*(char**)((char*)self + 0x58) + 0x2EC) > 0.0f)
    {
        *b *= 0.5000624656677246f;
        *a *= 0.5000624656677246f;
    }
    float s = func_001495A8(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(*(char**)((char*)self + 0x58) + 0x86C), *(int*)(*(char**)((char*)self + 0x58) + 0xB34));
    float m = 1.0f / (s * 0.5002591609954834f + 1.0f);
    *b *= m;
    *a *= m;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135EB0);
#ifdef SKIP_ASM
extern "C" int func_00311AE8(void*, int);

extern "C" int func_00135EB0(void* self)
{
    int r = 0;
    if (*(int*)((char*)self + 0x4) == 2)
    {
        r = func_00311AE8(*(void**)(*(char**)((char*)self + 0x58) + 0x784), 2) == 0x12;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135EF0);
#ifdef SKIP_ASM
extern "C" int func_00311AE8(void*, int);

extern "C" int func_00135EF0(void* self)
{
    int r = 0;
    if (*(int*)((char*)self + 0x4) == 4)
    {
        r = func_00311AE8(*(void**)(*(char**)((char*)self + 0x58) + 0x784), 2) == 0x13;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135F30);
#ifdef SKIP_ASM
extern "C" int func_00311AE8(void*, int);

extern "C" int func_00135F30(void* self)
{
    int r = 0;
    if (*(int*)((char*)self + 0x4) == 4)
    {
        r = func_00311AE8(*(void**)(*(char**)((char*)self + 0x58) + 0x784), 2) == 0x14;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00135F70);
#ifdef SKIP_ASM
static inline float aiSign_135F70(float v)
{
    if (v >= 0.0f)
    {
        if (v > 0.0f) return 1.0f;
        return 0.0f;
    }
    return -1.0f;
}

extern "C" float func_00135F70(void* self, int* out)
{
    float y = aiSign_135F70(*(float*)((char*)self + 0x18));
    float x = aiSign_135F70(*(float*)((char*)self + 0x1C));
    int zero = 0;
    if (y == 0.0f && x == 0.0f) zero = 1;
    *out = zero;
    if (zero) return 0.0f;
    return aiAtan2_135180(y, x);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001360C8);
#ifdef SKIP_ASM
extern "C" float func_001360C8(void* self, int* out)
{
    int b = *(float*)((char*)self + 0x50) == 1.0000000150474662e+30f;
    *out = b;
    if (b)
        return 0.0f;
    return *(float*)((char*)self + 0x50);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136100);
#ifdef SKIP_ASM
// PORT: g++ `>?` (max) operator. aiWrap_135BE0 uses the FPU-only cvt.w.s/cvt.s.w asm helper.
extern "C" float func_00136100(void* self)
{
    float d = __builtin_fabsf(aiWrap_135BE0(*(float*)((char*)self + 0x18))) * 0.31830987334251404f - 0.5f;
    d = d >? 0.0f;
    return d * 2.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136168);
#ifdef SKIP_ASM
// PORT: g++ `>?` (max) operator. aiWrap_135BE0 uses the FPU-only cvt.w.s/cvt.s.w asm helper.
extern "C" float func_00136168(void* self)
{
    float d = __builtin_fabsf(aiWrap_135BE0(*(float*)((char*)self + 0x1C))) * 0.6366197466850281f;
    if (d > 1.0f)
        d = 2.0f - d;
    d = d - 0.25f;
    d = d >? 0.0f;
    return d * 1.3333333730697632f;
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001361F8);
#ifdef SKIP_ASM
struct sVEntry001361F8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001361F8(void* self, void* obj)
{
    sVEntry001361F8* vt = *(sVEntry001361F8**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x58);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136230);
#ifdef SKIP_ASM
struct sVEntry00136230 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00136230(void* self, void* obj)
{
    sVEntry00136230* vt = *(sVEntry00136230**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x58);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136268);
#ifdef SKIP_ASM
float func_00119938(void* self, int a1, int a2);

struct sAnimSet_00136268 {
    int anims[4];       // 0x00
    char pad10[0x10];
    int x20;            // 0x20
};
extern sAnimSet_00136268 D_0045A038[];

extern "C" void func_00136268(void* self)
{
    sAnimSet_00136268* e = &D_0045A038[*(int*)((char*)self + 0x4)];
    char* r = *(char**)((char*)self + 0x8);
    int s = *(int*)(r + 0x328);
    if (s == 4) {
        char* anim = *(char**)(r + 0x784);
        *(sQuat_12FEC8*)(anim + 0x30) = D_004FF130;
        *(sQuat_12FEC8*)(anim + 0x40) = AxisAngle_12FEC8(D_004FF160, 1.5707963705062866f);
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x8) + 0x784), e->anims[0], 0, -1.0f);
    } else if (s == 3) {
        cRiderAnimBase_play(*(void**)(r + 0x784), e->anims[1], 0, -1.0f);
    } else if (s == 2) {
        *(int*)(r + 0x320) = 0;
        *(int*)(*(char**)(*(char**)((char*)self + 0x8) + 0x784) + 0x18) = 0;
        char* anim = *(char**)(*(char**)((char*)self + 0x8) + 0x784);
        *(sQuat_12FEC8*)(anim + 0x30) = D_004FF130;
        *(sQuat_12FEC8*)(anim + 0x40) = AxisAngle_12FEC8(D_004FF160, 1.5707963705062866f);
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x8) + 0x784), e->anims[2], 0, -1.0f);
    } else {
        char* anim = *(char**)(r + 0x784);
        *(sQuat_12FEC8*)(anim + 0x30) = D_004FF130;
        *(sQuat_12FEC8*)(anim + 0x40) = AxisAngle_12FEC8(D_004FF160, 1.5707963705062866f);
        cRiderAnimBase_play(*(void**)(*(char**)((char*)self + 0x8) + 0x784), e->anims[3], 0, -1.0f);
    }
    float k = 0.33000001311302185f;
    func_0010E098(*(void**)((char*)self + 0x8), 1, func_00119938(*(void**)(*(char**)((char*)self + 0x8) + 0x790), e->x20, *(int*)(*(char**)((char*)self + 0x8) + 0x328)));
    *(int*)(*(char**)((char*)self + 0x8) + 0x328) = 3;
    *(int*)self = 0;
    func_00116930(*(void**)((char*)self + 0x8));
    func_00311E88(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 1, k);
    func_00311E88(*(void**)(*(char**)((char*)self + 0x8) + 0x784), 0, k);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136508);
#ifdef SKIP_ASM
extern "C" int func_00106848(void*);
extern "C" void func_0010E098(void*, int, float);
extern "C" void func_00113F38(void*, float);
extern "C" void func_00113F88(void* rider, float a, float b);
extern "C" void func_00114130(void* rider, int a, int b);
extern "C" void func_00115640(void* rider);
extern "C" int func_00116120(void* rider, int a, int b);
extern "C" float func_00119958(void* p, int v);
int func_0011FE98(void* self);
void func_0011FEC8_impl(void* self, int v) __asm__("func_0011FEC8__FPv");
extern "C" void func_001326C8(void*, int);
extern "C" bool func_001446A0(void* self, int bit);
extern "C" int func_00311AE8(void*, int);
extern "C" char* func_00311B20(void*, int);
int func_00312AA0(void* self, int i);
extern "C" int func_00312AE8(void* self, int i);


struct sAiBitsA_136508
{
    int pad : 23;
    int v : 6;
};

struct sAiBitsB_136508
{
    int pad : 15;
    int v : 8;
};

// PORT: PS2-only inline asm (float absolute value).
static inline float aiAbs_136508(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct sAiObj136508
{
    int mState;
    int mIndex;
    char* mRider;
};

extern "C" void func_00136508(sAiObj136508* self, void* in)
{
    if (func_00116120(self->mRider, (*(int*)in >> 12) & 1, 0))
        return;
    char* tbl = (char*)D_0045A038 + self->mIndex * 0x24;
    if (func_00106848(self->mRider))
    {
        if (self->mState == 1)
            cRiderAnimBase_play(*(void**)(self->mRider + 0x784), *(int*)(tbl + 0x18), 0, -1.0f);
        return;
    }
    int w = *(int*)in;
    float zero = 0.0f;
    func_00114130(self->mRider, (w >> 14) & 1, (w >> 13) & 1);
    func_00113F38(self->mRider, ((sAiBitsA_136508*)in)->v * 0.032258063554763794f);
    func_00113F88(self->mRider, zero, zero);
    if (self->mState == 0)
    {
        char* r0 = self->mRider;
        *(float*)(r0 + 0x240) = zero;
        *(float*)(r0 + 0x23C) = 0.05833333730697632f;
        if (func_00312AE8(*(void**)(self->mRider + 0x784), 2))
        {
            cRiderAnimBase_play(*(void**)(self->mRider + 0x784), *(int*)(tbl + 0x10), 0, -1.0f);
            *(float*)(func_00311B20(*(void**)(self->mRider + 0x784), 2) + 0x90) = 1.0f;
            self->mState = 1;
        }
    }
    if (self->mState == 1)
    {
        if (((sAiBitsB_136508*)in)->v != self->mIndex || func_0011FE98(self->mRider) == 0)
        {
            cRiderAnimBase_play(*(void**)(self->mRider + 0x784), *(int*)(tbl + 0x1C), 0, -1.0f);
            *(float*)(func_00311B20(*(void**)(self->mRider + 0x784), 2) + 0x90) = 1.0f;
            self->mState = 2;
        }
        else if (func_00312AA0(*(void**)(self->mRider + 0x784), 2) != *(int*)(tbl + 0x18) ||
                 func_00312AE8(*(void**)(self->mRider + 0x784), 2))
        {
            if (func_0011FE98(self->mRider) != 4)
            {
                char* r = self->mRider;
                *(float*)(r + 0x240) = 0.0f;
                *(float*)(r + 0x23C) = 0.05833333730697632f;
            }
            else
            {
                char* r = self->mRider;
                *(float*)(r + 0x240) = *(float*)(*(char**)(r + 0x77C) + 0xC8);
                *(float*)(r + 0x23C) = 0.05833333730697632f;
            }
            int cur = func_00312AA0(*(void**)(self->mRider + 0x784), 2);
            int a;
            if (aiAbs_136508(*(float*)(self->mRider + 0x238)) < 0.10000000149011612f)
                a = *(int*)(tbl + 0x10);
            else
                a = *(int*)(tbl + 0x14);
            if (a != cur)
                cRiderAnimBase_play(*(void**)(self->mRider + 0x784), a, 0, -1.0f);
        }
    }
    if (self->mState == 2)
    {
        char* r2 = self->mRider;
        *(float*)(r2 + 0x240) = 0.0f;
        *(float*)(r2 + 0x23C) = 0.05833333730697632f;
        if (func_00311AE8(*(void**)(self->mRider + 0x784), 2) == 0x15 &&
            !func_00312AE8(*(void**)(self->mRider + 0x784), 2) &&
            !func_001446A0(func_00311B20(*(void**)(self->mRider + 0x784), 2) + 0xB0, 0))
            return;
        if (func_0011FE98(self->mRider) == 4)
        {
            func_001326C8(*(char**)(self->mRider + 0x77C) + 0x2B0, 0);
            func_0011FEC8_impl(self->mRider, 7);
        }
        else
        {
            func_00115640(self->mRider);
            if (func_0011FE98(self->mRider) == 1)
                func_0011FEC8_impl(self->mRider, 5);
            else
                func_0011FEC8_impl(self->mRider, 0);
        }
        func_0010E098(self->mRider, 1, func_00119958(*(void**)(self->mRider + 0x790), *(int*)(self->mRider + 0x328)));
        char* r = self->mRider;
        if (*(int*)(r + 0x2F4) < 10)
        {
            *(int*)(r + 0x2F4) = *(int*)(r + 0x2F4) + 1;
            if (*(int*)(self->mRider + 0x2F4) == 10)
                *(float*)(self->mRider + 0x2F0) = 60.0f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_001368E8);
#ifdef SKIP_ASM
struct sVEntry001368E8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001368E8(void* self, void* obj)
{
    sVEntry001368E8* vt = *(sVEntry001368E8**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x8);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136920);
#ifdef SKIP_ASM
struct sVEntry00136920 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00136920(void* self, void* obj)
{
    sVEntry00136920* vt = *(sVEntry00136920**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x8);
}
#endif

extern "C" void cRider_updateOrientationImplicit(void*);

//100%
INCLUDE_ASM("ai/ai", func_00136958);
#ifdef SKIP_ASM
extern "C" void func_00136958(void* self)
{
    cRider_updateOrientationImplicit(*(void**)self);
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136978__FPv);
#ifdef SKIP_ASM
void func_00136978(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136980);
#ifdef SKIP_ASM
extern "C" void* cRider_cRider(void* self);

struct sVEntry_136980 { short delta; short index; void* fn; };
struct sVtbl9_136980 { sVEntry_136980 e[9]; } __attribute__((aligned(8)));
struct sVtbl22_136980 { sVEntry_136980 e[22]; } __attribute__((aligned(8)));

extern const sVtbl9_136980 D_004597B0;
extern char D_00459B90[];
extern const sVtbl22_136980 D_004597F8;

// PORT: g++ 2.95 virtual-base construction. The class derives virtually from cRider (vbase pointer at
// +0x40, vbase at +0x70); when not most-derived, g++ copies cRider's overridden vtables to the stack and
// fixes up the this-deltas (expand_upcast_fixups). Written out by hand here.
extern "C" void* func_00136980(void* self, int inChrg)
{
    if (inChrg)
    {
        char* vb = (char*)self + 0x70;
        *(char**)((char*)self + 0x40) = vb;
        cRider_cRider(vb);
    }
    *(void**)(*(char**)((char*)self + 0x40) + 0x6E8) = (void*)&D_004597B0;
    *(void**)(*(char**)((char*)self + 0x40) + 0x6D0) = D_00459B90;
    *(void**)(*(char**)((char*)self + 0x40) + 0x6C0) = (void*)&D_004597F8;
    if (!inChrg)
    {
        sVtbl9_136980 t1 = D_004597B0;
        *(void**)(*(char**)((char*)self + 0x40) + 0x6E8) = &t1;
        char* base = *(char**)((char*)self + 0x40) - 0x70;
        int d = (char*)self - base;
        t1.e[1].delta = D_004597B0.e[1].delta + d;
        sVtbl22_136980 t2 = D_004597F8;
        *(void**)(*(char**)((char*)self + 0x40) + 0x6C0) = &t2;
        t2.e[1].delta = D_004597F8.e[1].delta + d;
    }
    *(int*)((char*)self + 0x44) = 0;
    return self;
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_ai {
public:
    virtual ~cRiderVbA0_ai();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_ai : public cRiderVbA0_ai { public: char padA[0xC]; };
class cRiderVbB0_ai { public: virtual void b01(); };
class cRiderVbB_ai : public cRiderVbB0_ai { public: char padB[0x14]; };
class cRiderVbC0_ai {
public:
    virtual ~cRiderVbC0_ai();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_ai : public cRiderVbC0_ai { public: char padC[0x10]; };
class cRiderVbBC_ai : public cRiderVbB_ai, public cRiderVbC_ai { public: };
class cRiderVbPad_ai { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_ai : public cRiderVbPad_ai, public cRiderVbA_ai, public cRiderVbBC_ai {
public:
    virtual ~cRiderVb_ai();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("ai/ai", func_00136AD0);
#ifdef SKIP_ASM
class cVbMember00136AD0 {
public:
    ~cVbMember00136AD0();
};

struct cVbHead00136AD0 {
    char pad[0x40];
};

class cVbDtor00136AD0 : public cVbHead00136AD0, virtual public cRiderVb_ai {
public:
    cVbMember00136AD0* m44;     // 0x44
    char body[0x28];
    virtual ~cVbDtor00136AD0();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor00136AD0::~cVbDtor00136AD0()
{
    delete m44;
}
// PORT: the compiler names this dtor _$_15cVbDtor00136AD0; expose it under the address-derived name.
__asm__(".globl func_00136AD0\n.type func_00136AD0,@function\nfunc_00136AD0 = _$_15cVbDtor00136AD0\n.size func_00136AD0,0x170\n");
#endif

