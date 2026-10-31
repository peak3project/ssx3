#include "common.h"

//100%
INCLUDE_ASM("fe/festatecharequipdetail", cFEStateCharEquip_cFEStateCharEquip);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E2A0(void* self, void* parent);
extern "C" unsigned char func_001A1CD0(void* self, signed char a1);
extern "C" void* cBE_getBE();
void* cBE_getInterface(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
int cBELibrary_getRiderIndex(int index);
int GetHashValue32(char* str);
extern "C" void func_003E6448(void* dst, unsigned int value, int size);
extern "C" int func_00398380(void* list, int hash);
extern "C" void func_001A0508(void* mgr, int idx, int ch, int a3);
extern "C" int func_00150928(void* iface, int idx, int ch);
extern "C" void func_0014AEA8(void* self, int a1, int a2);
extern "C" int func_0014B478(void* self, int a1, int a2);
extern "C" char* func_0014B700(void* iface, int rider);
extern "C" int func_00146D98(void* iface, int a1);
extern "C" void func_0019B180(void* self, int id);
extern "C" int func_0019DA10(void* self, int bank, void* name, int a3, int a4, int a5);
extern void* D_004A28A8;
extern const int D_004A11D0_c __asm__("D_004A11D0");
extern void* D_0046A548[];
extern char D_004607A8[];
extern char D_004607B8[];
extern char D_0045DA48[];
extern char D_0045DA38[];

struct sVec4_8DB8 {
    float x, y, z, w;
};

struct sCharEquip_8DB8 {
    char pad0[0x8];
    void** vtbl;             // 0x8
    int fC;                  // 0xC
    char** mgr;              // 0x10
    char pad14;
    unsigned char f15;       // 0x15
    char pad16[0x44 - 0x16];
    signed char team;        // 0x44
    char pad45[3];
    int f48[11];             // 0x48..0x70
    int f74;                 // 0x74
    int f78;                 // 0x78
    int f7C;                 // 0x7C
    int f80;                 // 0x80
    int f84;                 // 0x84
    int f88;                 // 0x88
    int a8C[6];              // 0x8C
    int aA4[6];              // 0xA4
    int slot;                // 0xBC
    int fC0;                 // 0xC0
    int fC4;                 // 0xC4
    int fC8;                 // 0xC8
    int fCC;                 // 0xCC
    char bufD0[0x50];        // 0xD0
    int f120;                // 0x120
    char pad124[0x958 - 0x124];
    int f958;                // 0x958
    int f95C;                // 0x95C
    char f960;               // 0x960
    char pad961[0xA60 - 0x961];
    int fA60;                // 0xA60
    int fA64;                // 0xA64
    int fA68;                // 0xA68
    int fA6C;                // 0xA6C
    int fA70;                // 0xA70
    int fA74;                // 0xA74
    int aA78[6];             // 0xA78
    int fA90;                // 0xA90
    int fA94;                // 0xA94
    int fA98;                // 0xA98
    int fA9C;                // 0xA9C
    int fAA0;                // 0xAA0
    char padAA4[0xAB0 - 0xAA4];
    int fAB0;                // 0xAB0
    char padAB4[0xAC0 - 0xAB4];
    sVec4_8DB8 camPos;       // 0xAC0
    sVec4_8DB8 camTarget;    // 0xAD0
    int fAE0;                // 0xAE0
    int fAE4;                // 0xAE4
};

static inline int BoardClass_8DB8(int kind)
{
    switch (kind) {
    case 17:
        return 1;
    case 18:
        return 1;
    case 19:
        return 2;
    case 20:
        return 2;
    case 21:
        return 3;
    }
    return 1;
}

static inline int Find_8DB8(char* mgr, int hash)
{
    return func_00398380(mgr + 0x58, hash);
}

extern "C" void* cFEStateCharEquip_cFEStateCharEquip(void* p, void* owner, signed char team, int a3, int a4)
{
    sCharEquip_8DB8* self = (sCharEquip_8DB8*)p;
    func_0039E2A0(self, owner);
    self->vtbl = D_0046A548;
    self->camPos.x = -105.0f;
    self->camPos.y = -100.0f;
    self->camPos.z = -80.0f;
    self->camPos.w = 1.0f;
    self->camTarget.x = 265.75f;
    self->camTarget.y = -1073.5f;
    self->camTarget.z = -232.0f;
    self->camTarget.w = 1.0f;
    self->fC = 0xE;
    self->team = team;
    self->f15 = func_001A1CD0(*self->mgr, team);
    void* player = cBE_getInterface(cBE_getBE(), 1);
    self->slot = cBENewPlayerInterface_getPlayerCharID(player, self->team);
    if (a3 != 0) {
        self->fC8 = 1;
    } else {
        self->fC8 = 0;
    }
    self->f958 = 0;
    self->f960 = 0;
    self->fA60 = 0;
    self->f48[0] = 0;
    self->f48[1] = 0;
    self->f48[2] = 0;
    self->f48[3] = 0;
    self->f48[4] = 0;
    self->f48[5] = 0;
    self->f48[6] = 0;
    self->f48[7] = 0;
    self->f48[8] = 0;
    self->f48[9] = 0;
    self->f48[10] = 0;
    self->f78 = 0;
    self->f7C = 0;
    self->fAB0 = 0;
    self->f95C = -1;
    self->fA64 = -1;
    self->fA68 = -1;
    self->fA6C = -1;
    self->fA70 = -1;
    self->fA74 = -1;
    self->fAE0 = 1;
    func_003E6448(self->bufD0, D_004A11D0_c, 0x50);
    self->f120 = 0;
    for (int i = 0; i < 6; i++) {
        self->a8C[i] = 0;
        self->aA4[i] = 0;
        self->aA78[i] = -99999;
    }
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    {
        char* mgr = *(char**)&self->mgr;
        self->fA90 = Find_8DB8(mgr, GetHashValue32(D_004607A8));
    }
    {
        char* mgr = *(char**)&self->mgr;
        self->fA94 = Find_8DB8(mgr, GetHashValue32(D_004607B8));
    }
    {
        char* mgr = *(char**)&self->mgr;
        self->fA98 = Find_8DB8(mgr, GetHashValue32(D_0045DA48));
    }
    {
        char* mgr = *(char**)&self->mgr;
        self->fA9C = Find_8DB8(mgr, GetHashValue32(D_0045DA38));
    }
    self->fAA0 = 0;
    func_001A0508(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, self->team, self->slot, 1);
    self->fC0 = func_00150928(cBE_getInterface(cBE_getBE(), 0xB), self->team, self->slot);
    void* shop = cBE_getInterface(cBE_getBE(), 9);
    func_0014AEA8(shop, self->team, self->slot);
    self->fC4 = func_0014B478(shop, self->team, self->slot);
    self->fAE4 = a4;
    if (a3 != 0 || a4 != 0) {
        switch (func_00146D98(player, cBELibrary_getRiderIndex(self->team))) {
        case 17:
            self->fCC = 1;
            break;
        case 18:
            self->fCC = 1;
            break;
        case 19:
            self->fCC = 2;
            break;
        case 20:
            self->fCC = 2;
            break;
        case 21:
            self->fCC = 3;
            break;
        default:
            self->fCC = 1;
            break;
        }
    } else {
        self->fCC = -1;
    }
    func_0019B180(self, D_004A11D0_c);
    char* name = func_0014B700(shop, self->slot);
    self->fA64 = func_0019DA10(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70, self->slot, name, 9, 1, 0);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_00199148);
#ifdef SKIP_ASM
struct sEquipTable_DC20;
extern "C" void func_0019DC20(sEquipTable_DC20* self, int bank, int i);
extern "C" void func_0019A498(void* self);
extern "C" void func_0039E390(void* self, int flags);
extern void* D_004A28A8;
extern void* D_004A289C;
extern void* D_0046A548[];
extern void* D_0046D0D0[];

struct sVEntryK199148 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void releaseK199148(int id)
{
    if (id >= 0) {
        char* g = (char*)D_004A289C;
        sVEntryK199148* vt = *(sVEntryK199148**)(g + 0x10D8);
        vt[50].fn(g + vt[50].delta, id);
    }
}

extern "C" void func_00199148(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046A548;
    if (*(int*)((char*)self + 0xA64) >= 0) {
        func_0019DC20((sEquipTable_DC20*)(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70), *(int*)((char*)self + 0xBC),
                      *(int*)((char*)self + 0xA64));
        *(int*)((char*)self + 0xA64) = -1;
    }
    releaseK199148(*(int*)((char*)self + 0xA68));
    *(int*)((char*)self + 0xA68) = -1;
    func_0019A498(self);
    releaseK199148(*(int*)((char*)self + 0xA70));
    releaseK199148(*(int*)((char*)self + 0xA74));
    *(int*)((char*)self + 0xA70) = -1;
    *(int*)((char*)self + 0xA74) = -1;
    *(void***)((char*)self + 0x8) = D_0046D0D0;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", cFEStateCharEquip_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* func_001A0548(void* self, int a1);
extern "C" void func_00311A50(void* self);
extern "C" void cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0019BFE8(void* self);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* self, int a1);
extern void* D_004A28A8;
extern char D_004607E8[];

extern "C" void cFEStateCharEquip_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004607E8), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    char* r = (char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44));
    *(int*)(r + 0xC2C) = 0x11;
    *(int*)(r + 0xCCC) = 0;
    int ok = *(unsigned int*)r < 10 && *(int*)(r + 0xCB8) != 0 && *(int*)(r + 0xCB4) != 0;
    if (ok) {
        void* anim = *(void**)(r + 0xC);
        if (anim != 0) {
            func_00311A50(anim);
            cRiderAnimBase_play(anim, 0x1B2, 0, -1.0f);
        }
    }
    *(int*)((char*)self + 0xAA4) = 0;
    *(int*)((char*)self + 0xAAC) = 0;
    *(float*)((char*)self + 0xAA8) = -1.0f;
    func_0019BFE8(self);
    func_0028F140(func_0028B180(), 2);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_00199350);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_001A0548(void* self, int a1);
void func_0039E4A0(void* self);

extern "C" void func_00199350(void* self)
{
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C);
    if (mgr != 0) {
        char* r = (char*)func_001A0548(mgr + 0xB0, *(signed char*)((char*)self + 0x44));
        *(unsigned int*)(r + 0xC2C) = 0xFFFFFFFF;
    }
    func_0039E4A0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_001993A0);
#ifdef SKIP_ASM
extern "C" void func_0019A308(void* self);
extern "C" void func_0019A238(void* self);
extern "C" void func_0019BC90(void* self);
extern "C" void func_0019BD48(void* self, int a1);
extern "C" void func_0019B618(void* self, int a1, int a2);
extern "C" void func_00186518(void* self, int a1);

extern "C" void func_001993A0(void* self, int a1)
{
    bool off = !*(bool*)((char*)self + 0xC8);
    if (!off) {
        func_0019A308(self);
    } else {
        func_0019A238(self);
    }
    func_0019BC90(self);
    func_0019BD48(self, 0);
    func_0019B618(self, 1, 1);
    func_00186518(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_00199420);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_001A0548(void* self, int a1);
extern "C" void func_0019E538(void* rider, int a1);

extern "C" void func_00199420(void* self)
{
    func_0019E538(func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44)), 0);
}
#endif

INCLUDE_ASM("fe/festatecharequipdetail", cFEStateCharEquip_onWidgetCreate);

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_00199870);
#ifdef SKIP_ASM
extern "C" void func_0019BE80(void* self);
extern "C" void func_0019BBA0(void* self);
struct sEquipDetail;
extern "C" int func_0019B458(sEquipDetail* self, int idx);
extern "C" void func_0019B618(void* self, int a1, int a2);

extern "C" void func_00199870(void* self, void* widget, int msg)
{
    switch (msg) {
    case 0x15:
        if (*(int*)((char*)widget + 0xC) != 7) {
            *(int*)((char*)self + 0x1C) &= ~8;
        }
        break;
    case 0x16:
        if (((*(int*)((char*)self + 0x1C) >> 3) & 1) == 0) {
            *(int*)((char*)self + 0x1C) |= 8;
        }
        if (*(int*)((char*)widget + 0xC) == 7 && *(int*)((char*)widget + 0x6C) != 0) {
            func_0019BE80(self);
            func_0019BBA0(self);
            if (func_0019B458((sEquipDetail*)self, *(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x95))) {
                func_0019B618(self, 0, 1);
            }
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", cFEStateCharEquip_onUpdate);
#ifdef SKIP_ASM
struct cList;
struct sEquipTable;
int GetHashValue32(char* str);
void* cList_first(cList* list);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0039E510(void* self);
extern "C" int func_0019E238(sEquipTable* self, int a1, int a2);
extern "C" void func_0019A9B8(void* self);
extern "C" void func_0019A638(void* self);
extern "C" void func_0019BFE8(void* self);
extern "C" void* func_001A0548(void* self, int a1);
extern void* D_004A28A8;
extern char D_004608A0[];

struct sVEntryK199938 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void cFEStateCharEquip_onUpdate(void* self)
{
    func_0039E510(self);
    if (*(int*)((char*)self + 0xA60) == 0
        && func_0019E238((sEquipTable*)(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70), *(int*)((char*)self + 0xBC),
                         *(int*)((char*)self + 0xA64))) {
        *(int*)((char*)self + 0xA60) = 1;
        func_0019A9B8(self);
    }
    void* screen = cList_first((cList*)((char*)self + 0x24));
    char* obj = (char*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004608A0));
    if (obj != 0) {
        char* r = (char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44));
        int on = 0;
        int mode1 = *(int*)((char*)self + 0xC8) == 1;
        if (mode1) {
            if (*(int*)((char*)self + 0xA6C) >= 0 || *(int*)((char*)self + 0x95C) > 0)
                on = 1;
        } else {
            on = *(int*)(r + 0xCC8);
            on ^= 1;
        }
        sVEntryK199938* vt = *(sVEntryK199938**)(obj + 8);
        vt[9].fn(obj + vt[9].delta, on);
    }
    func_0019A638(self);
    func_0019BFE8(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_00199A38);
#ifdef SKIP_ASM
class cPad_9A38 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual float v36();
    virtual float v37();
    virtual float v38();
};

static inline int isMode1_9A38(void* self)
{
    return *(int*)((char*)self + 0xC8) == 1;
}

static inline float clamp_9A38(float v, float lo, float hi)
{
    if (v >= lo)
        return v <? hi;
    return lo;
}

extern "C" int func_00199A38(void* self, cPad_9A38* in)
{
    int r = 0;
    if (!isMode1_9A38(self)) {
    int m = *(int*)((char*)self + 0xAE0);
    if (m == 1 || m == 4) {
    if (in->v35()) {
        *(float*)((char*)self + 0xAAC) += in->v38() * 3.0f;
        while (*(float*)((char*)self + 0xAAC) >= 360.0f)
            *(float*)((char*)self + 0xAAC) -= 360.0f;
        while (*(float*)((char*)self + 0xAAC) < 0.0f)
            *(float*)((char*)self + 0xAAC) += 360.0f;
        r = 1;
    }
    if (in->v33()) {
        // PORT: <? (GNU min operator)
        *(float*)((char*)self + 0xAA4) = clamp_9A38(*(float*)((char*)self + 0xAA4) + in->v36() * -0.10000000149011612f, 0.0f, 1.0f);
        r = 1;
    }
    if (in->v34()) {
        *(float*)((char*)self + 0xAA8) = clamp_9A38(*(float*)((char*)self + 0xAA8) + in->v37() * -0.10000000149011612f, -1.0f, 1.0f);
        r = 1;
    }
    }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_00199C28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void cFEStateCharEquip_updateHeading(void* self, int id);
extern "C" void func_0019B180(void* self, int id);
extern "C" void func_0019B618(void* self, int a1, int a2);
extern "C" void func_0019A4E8(void* self, int a1);
extern "C" void func_0019A9B8(void* self);
extern "C" void func_0019ACA0(void* self);
extern "C" int func_0019BEE8(void* self);
extern "C" void func_0019C7E8(void* self, void* item);
extern "C" void func_0019BC90(void* self);
extern "C" void func_0019BD48(void* self, int a1);
extern "C" int func_0014B478(void* self, int a1, int a2);
extern "C" void func_0039F400(void* list, void* item);
extern "C" void* cBE_getBE();
void* cBE_getInterface(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_001A0548(void* self, int a1);
extern int D_004A11E0;
extern int D_004A18D8;
extern void* D_004A28A8;

struct sList_9C28 {
    char pad_0x0[0x98];
    unsigned char top;   // 0x98
};

struct sItem_9C28 {
    int f0;
    short id;           // 0x4
    char pad6[0xE - 0x6];
    short cost;         // 0xE
    char pad10[0x34 - 0x10];
    int flags;          // 0x34
};

struct sVE_9C28 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sCharEquip_9C28 {
    char pad0[0x10];
    char* menu;                     // 0x10
    char pad14[0x44 - 0x14];
    signed char team;               // 0x44
    char pad45[0x5C - 0x45];
    sList_9C28* list;               // 0x5C
    char pad60[0xBC - 0x60];
    int slot;                       // 0xBC
    int money;                      // 0xC0
    int spent;                      // 0xC4
    int mode;                       // 0xC8
    char padCC[0xD0 - 0xCC];
    int stack[(0x120 - 0xD0) / 4];  // 0xD0
    int depth;                      // 0x120
    sItem_9C28* items[(0x958 - 0x124) / 4]; // 0x124
    int count;                      // 0x958
    char pad95C[0xA78 - 0x95C];
    int vals[6];                    // 0xA78
    char padA90[0xAE0 - 0xA90];
    int state;                      // 0xAE0
};

static inline int isMode1_9C28(sCharEquip_9C28* self)
{
    return self->mode == 1;
}

extern "C" void func_00199C28(void* selfv, char* w, unsigned int ev)
{
    sCharEquip_9C28* self = (sCharEquip_9C28*)selfv;
    if (w == 0)
        return;
    switch (ev) {
    case 5: {
        if (self->list == 0)
            return;
        int idx = self->list->top + *(int*)(w + 0x18);
        if (idx >= self->count)
            return;
        sItem_9C28* item = self->items[idx];
        int id = item->id;
        if (item->flags & 0x20) {
            self->depth++;
            cFEStateCharEquip_updateHeading(self, id);
            self->stack[self->depth] = id;
            func_0019B180(self, id);
            func_0019B618(self, 1, 1);
            if (id == D_004A11E0)
                self->state = 3;
            return;
        }
        if (!(item->flags & 4))
            return;
        if (isMode1_9C28(self)) {
            int cost = item->cost;
            if (cost > 0)
                cost *= 10;
            if (self->money < cost)
                return;
            func_0019C7E8(self, item);
            return;
        }
        int* vals = self->vals;
        void* iface = cBE_getInterface(cBE_getBE(), 9);
        if (D_004A18D8 < *(int*)((char*)vals + (*(int*)(w + 0x18) << 2)) + self->spent)
            return;
        if (!func_0019BEE8(self))
            return;
        self->spent = func_0014B478(iface, self->team, self->slot);
        func_0019B618(self, 0, 1);
        func_0019BC90(self);
        func_0019BD48(self, *(int*)((char*)vals + (*(int*)(w + 0x18) << 2)));
        func_0019ACA0(self);
        return;
    }
    case 6: {
        if (self->depth > 0) {
            int* stack = self->stack;
            if (*(int*)((char*)stack + (self->depth << 2)) == D_004A11E0)
                self->state = 4;
            cFEStateCharEquip_updateHeading(self, *(int*)((char*)stack + ((self->depth - 1) << 2)));
            func_0019B180(self, *(int*)((char*)stack + ((self->depth - 1) << 2)));
            func_0019B618(self, 1, 1);
        } else {
            char* r = (char*)func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, self->team);
            *(int*)(r + 0xC20) = 0;
            *(int*)(r + 0xC1C) = 1;
            char* obj = *(char**)self->menu;
            sVE_9C28* vt = *(sVE_9C28**)(obj + 4);
            void* x = vt[5].fn(obj + vt[5].delta, self, 0);
            if (x)
                func_0039F400(self->menu + 0x18, x);
        }
        break;
    }
    case 1:
        if (isMode1_9C28(self))
            func_0019A4E8(self, 1);
        func_0019A9B8(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_00199F20);
#ifdef SKIP_ASM
extern "C" void func_0019A3D0(void* self);
extern int D_004A18D8;

struct sEquipItem_9F20 {
    char pad0[0xE];
    short cost;      // 0xE
    char pad10[0x24];
    int flags;       // 0x34
};

struct sEquipDetail_9F20 {
    char pad0[0x5C];
    char* sel;                    // 0x5C
    char pad60[0x60];
    int fC0;                      // 0xC0
    int fC4;                      // 0xC4
    int fC8;                      // 0xC8
    char padCC[0x54];
    int f120;                     // 0x120
    sEquipItem_9F20* items[0x20D]; // 0x124
    int count;                    // 0x958
    char pad95C[0x11C];
    int prices[27];               // 0xA78
    int fAE4;                     // 0xAE4
};

static inline bool isMode_9F20(int m, int v)
{
    return m == v;
}

static inline bool hasFlag_9F20(sEquipItem_9F20* item, int f)
{
    return (item->flags & f) != 0;
}

extern "C" int func_00199F20(sEquipDetail_9F20* self, int a1, int kind, int idx)
{
    switch (kind) {
    case 2:
    case 3:
        func_0019B618(self, 0, 0);
        return 1;
    case 0:
        if (idx < self->count) {
            return hasFlag_9F20(self->items[idx], 4);
        }
        return 0;
    case 1:
        if (idx == 0 || self->count == 0 || idx < self->count) return 1;
        return 0;
    case 6: {
        char* p = self->sel;
        int v = *(unsigned char*)(p + 0x95);
        if (v < 0) return 0x110;
        if (v < self->count) {
            sEquipItem_9F20* item = self->items[v];
            if (item->flags & 0x20) return 0x101;
            if (isMode_9F20(self->fC8, 1)) {
                int cost = item->cost;
                if (cost > 0) cost *= 10;
                if (cost >= self->fC0) break;
                return 0x101;
            } else {
                if (D_004A18D8 >= self->prices[v - *(unsigned char*)(p + 0x98)] + self->fC4) break;
            }
        }
        return 0x110;
    }
    case 7:
        if (self->f120 > 0) {
            self->f120 = self->f120 - 1;
            return 1;
        }
        break;
    case 8:
        if (self->fAE4 != 0) {
            func_0019A3D0(self);
            return 0x101;
        }
        return 0x100;
    case 9:
        return 0x100;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A098);
#ifdef SKIP_ASM
struct sEquipTable;
// PORT: func_0019E2B0 returns a pointer through int (the unit defines it as int).
extern "C" int func_0019E2B0(sEquipTable* self, int a1, int a2);
extern "C" void func_003B3D00(void* pkg, int i, char* name);
extern "C" int func_004165A8(const void* a, const void* b);
extern void* D_004A28A8;
extern void* D_004A289C;
extern char D_004A1950[];

struct sPkgEntK19A098 {
    int off;
    int f4;
};
struct sPkgK19A098 {
    int f0;
    int f4;
    int count;      // 0x8
    int fC;
    int f10;
    sPkgEntK19A098 ents[1];   // 0x14
};
struct sVEK19A098a {
    short delta;
    short index;
    int (*fn)(void*, char*, char*, int, int, int);
};
struct sVEK19A098b {
    short delta;
    short index;
    void (*fn)(void*, int, char*, int);
};

extern "C" int func_0019A098(void* self, const char* name)
{
    if (*(int*)((char*)self + 0xA60) == 0)
        return -1;
    sPkgK19A098* pkg = (sPkgK19A098*)func_0019E2B0((sEquipTable*)(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70), *(int*)((char*)self + 0xBC), *(int*)((char*)self + 0xA64));
    if (pkg == 0)
        return -1;
    int n = pkg->count;
    int i;
    for (i = 0; i < n; i++) {
        char nm[16];
        func_003B3D00(pkg, i, nm);
        nm[4] = 0;
        if (func_004165A8(nm, name) == 0) {
            sPkgEntK19A098* e = &pkg->ents[i];
            char* data = (char*)pkg + e->off;
            int id = *(int*)((char*)self + 0xA68);
            if (id == -1) {
                char* g = (char*)D_004A289C;
                sVEK19A098a* vt = *(sVEK19A098a**)(g + 0x10D8);
                *(int*)((char*)self + 0xA68) = vt[46].fn(g + vt[46].delta, data, D_004A1950, 0, 1, -1);
            } else {
                char* g = (char*)D_004A289C;
                sVEK19A098b* vt = *(sVEK19A098b**)(g + 0x10D8);
                vt[48].fn(g + vt[48].delta, id, data, 1);
            }
            return *(int*)((char*)self + 0xA68);
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A1E0);
#ifdef SKIP_ASM
struct sEquipTable;
extern "C" int func_0019E238(sEquipTable* self, int a1, int a2);
extern "C" void func_0019A9B8(void* self);
extern void* D_004A28A8;

extern "C" void func_0019A1E0(void* self)
{
    if (*(int*)((char*)self + 0xA60) == 0
        && func_0019E238((sEquipTable*)(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70), *(int*)((char*)self + 0xBC),
                         *(int*)((char*)self + 0xA64))) {
        *(int*)((char*)self + 0xA60) = 1;
        func_0019A9B8(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A238);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_00460820[];

struct sVEntry0019A238 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0019A238(void* self)
{
    if (*(cUIText**)((char*)self + 0x48) != 0) {
        cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x48), GetHashValue32(D_00460820));
    }
    char* o = *(char**)((char*)self + 0x60);
    if (o != 0) {
        sVEntry0019A238* vt = *(sVEntry0019A238**)(o + 8);
        vt[9].fn(o + vt[9].delta, 0);
    }
    o = *(char**)((char*)self + 0x88);
    if (o != 0) {
        sVEntry0019A238* vt = *(sVEntry0019A238**)(o + 8);
        vt[9].fn(o + vt[9].delta, 0);
    }
    o = *(char**)((char*)self + 0x80);
    if (o != 0) {
        sVEntry0019A238* vt = *(sVEntry0019A238**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
    }
    func_0019E538(func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44)), 1);
    *(int*)((char*)self + 0xAE0) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A308);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_00460810[];

struct sVEntry0019A308 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0019A308(void* self)
{
    if (*(cUIText**)((char*)self + 0x48) != 0) {
        cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x48), GetHashValue32(D_00460810));
    }
    char* o = *(char**)((char*)self + 0x80);
    if (o != 0) {
        sVEntry0019A308* vt = *(sVEntry0019A308**)(o + 8);
        vt[9].fn(o + vt[9].delta, 0);
    }
    o = *(char**)((char*)self + 0x6C);
    if (o != 0) {
        sVEntry0019A308* vt = *(sVEntry0019A308**)(o + 8);
        vt[9].fn(o + vt[9].delta, 0);
    }
    func_0019E538(func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44)), 0);
    o = *(char**)((char*)self + 0x60);
    if (o != 0) {
        sVEntry0019A308* vt = *(sVEntry0019A308**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A3D0);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void func_003E6448(void* dst, unsigned int value, int size);
extern "C" void cFEStateCharEquip_updateHeading(void* self, int id);
extern "C" void func_0019B180(void* self, int id);
extern int D_004A11D0;
extern char D_00460810[];
extern char D_00460820[];

struct sEquipDetailK19A3D0 {
    char pad_0x000[0x120];
    int f120;      // 0x120
};

static inline int isDetailK19A3D0(void* self)
{
    return *(int*)((char*)self + 0xC8) == 1;
}

extern "C" void func_0019A3D0(void* self)
{
    if (isDetailK19A3D0(self)) {
        *(int*)((char*)self + 0xC8) = 0;
        func_0019A238(self);
        if (*(cUIText**)((char*)self + 0x50) != 0) {
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x50), GetHashValue32(D_00460810));
        }
    } else {
        *(int*)((char*)self + 0xC8) = 1;
        func_0019A308(self);
        if (*(cUIText**)((char*)self + 0x50) != 0) {
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x50), GetHashValue32(D_00460820));
        }
    }
    ((sEquipDetailK19A3D0*)self)->f120 = 0;
    func_003E6448((char*)self + 0xD0, D_004A11D0, 0x50);
    cFEStateCharEquip_updateHeading(self, D_004A11D0);
    func_0019B180(self, D_004A11D0);
    func_0019B618(self, 1, 1);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A498);
#ifdef SKIP_ASM
extern void* D_004A28A8;
struct sEquipTable_DC20;
extern "C" void func_0019DC20(sEquipTable_DC20* self, int bank, int i);

extern "C" void func_0019A498(void* self)
{
    int idx = *(int*)((char*)self + 0xA6C);
    if (idx >= 0) {
        func_0019DC20((sEquipTable_DC20*)(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70), *(int*)((char*)self + 0xBC), idx);
    }
    *(char*)((char*)self + 0x960) = 0;
    *(int*)((char*)self + 0xA6C) = -1;
    *(int*)((char*)self + 0x95C) = -1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A4E8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" char* func_0014B700(void* iface, int rider);
extern "C" char* func_0041ACC0(const char* s, int c);
extern "C" char* strncpy(char* dst, const char* src, int n);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_0019A498(void* self);
extern char D_004A1958[];

static inline int isDigitK19A4E8(unsigned char c)
{
    return c >= '0' && c <= '9';
}

extern "C" void func_0019A4E8(void* self, int flag)
{
    if (*(void**)((char*)self + 0x5C) == 0)
        return;
    func_0019A498(self);
    releaseK199148(*(int*)((char*)self + 0xA74));
    *(int*)((char*)self + 0xA74) = *(int*)((char*)self + 0xA70);
    *(int*)((char*)self + 0xA70) = -1;
    int idx = *(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x95);
    if (idx < 0)
        return;
    if (idx >= *(int*)((char*)self + 0x958))
        return;
    char* p = *(char**)(*(char**)((char*)self + (idx << 2) + 0x124) + 0x30);
    if (p == 0)
        return;
    if (flag)
        *(int*)((char*)self + 0x95C) = 0x14;
    else
        *(int*)((char*)self + 0x95C) = 1;
    char* buf = (char*)self + 0x960;
    char* s = func_0014B700(cBE_getInterface_Fv(cBE_getBE(), 9), *(int*)((char*)self + 0xBC));
    char* dot = func_0041ACC0(s, '.');
    int len = dot - s - 1;
    strncpy(buf, s, len);
    buf[len] = 0;
    while (*p != 0) {
        if (*p >= '0' && *p <= '9')
            break;
        p++;
    }
    sprintf((char*)self + 0x960, D_004A1958, (char*)self + 0x960, p, dot);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A638);
#ifdef SKIP_ASM
struct sEquipTable;
struct sEquipTable_DC20;
extern "C" void func_0019DC20(sEquipTable_DC20* self, int bank, int i);
extern "C" int func_0019E238(sEquipTable* self, int a1, int a2);
// PORT: func_0019E2B0 returns a pointer through int (the unit defines it as int).
extern "C" int func_0019E2B0(sEquipTable* self, int a1, int a2);
extern "C" int func_0019DA10(void* self, int bank, void* name, int a3, int a4, int a5);
extern "C" void func_0019A9B8(void* self);
extern void* D_004A28A8;
extern void* D_004A289C;
extern char D_004A1960[];

struct sVEntryK19A638 {
    short delta;
    short index;
    int (*fn)(void*, void*, char*, int, int, int);
};

extern "C" void func_0019A638(void* self)
{
    int mode1 = *(int*)((char*)self + 0xC8) == 1;
    if (!mode1)
        return;
    if (*(int*)((char*)self + 0x95C) > 0) {
        if (--*(int*)((char*)self + 0x95C) == 0) {
            *(int*)((char*)self + 0xA6C) = func_0019DA10(*(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70,
                                                         *(int*)((char*)self + 0xBC), (char*)self + 0x960, 9, 1, 0);
            *(int*)((char*)self + 0x95C) = -1;
        }
    } else if (*(int*)((char*)self + 0xA6C) >= 0) {
        char* tbl = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
        if (func_0019E238((sEquipTable*)tbl, *(int*)((char*)self + 0xBC), *(int*)((char*)self + 0xA6C))) {
            char* e = (char*)func_0019E2B0((sEquipTable*)tbl, *(int*)((char*)self + 0xBC), *(int*)((char*)self + 0xA6C));
            if (e != 0) {
                char* g = (char*)D_004A289C;
                sVEntryK19A638* vt = *(sVEntryK19A638**)(g + 0x10D8);
                *(int*)((char*)self + 0xA70) = vt[46].fn(g + vt[46].delta, e + *(int*)(e + 0x14), D_004A1960, 0, 1, -1);
            } else {
                *(int*)((char*)self + 0xA70) = -1;
            }
            func_0019DC20((sEquipTable_DC20*)tbl, *(int*)((char*)self + 0xBC), *(int*)((char*)self + 0xA6C));
            *(int*)((char*)self + 0xA6C) = -1;
            func_0019A9B8(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A758);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_001A0548(void* self, int a1);
extern "C" void func_0019FA78(void* self, int a1);

extern "C" void func_0019A758(void* self)
{
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C);
    if (mgr != 0) {
        func_0019FA78(func_001A0548(mgr + 0xB0, *(signed char*)((char*)self + 0x44)), 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A798);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cUIText;
class cUIObj_A798 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};
struct sEquipEntry_A798 {
    unsigned short f0;
    unsigned short flags;
};
struct sEquipDb_A798 {
    char pad_0x0[0x288];
    short* map;     // 0x288
    char pad_0x28c[4];
    sEquipEntry_A798 entries[1];  // 0x290
};
struct sEquipItem_A798 {
    short f0;
    signed char slot;   // 0x2
    char f3;
    short id;       // 0x4
    char pad_0x6[0xE - 0x6];
    short cost;     // 0xE
    char pad_0x10[0x34 - 0x10];
    int flags;      // 0x34
};
struct sList_A798 {
    char pad_0x0[0x95];
    unsigned char sel;   // 0x95
    unsigned char count; // 0x96
    char pad_0x97;
    unsigned char top;   // 0x98
};
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void* cBE_getBE();
void* cBE_getInterface(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern int D_004A18D8;
extern char D_004608D8[];
extern char D_004608F0[];
extern char D_00460908[];
extern char D_00460920[];
extern char D_00460940[];
extern char D_00460958[];
extern char D_00460970[];
extern char D_00460988[];

static inline int isMode1_A798(void* self)
{
    return *(int*)((char*)self + 0xC8) == 1;
}

static inline sEquipEntry_A798* getEntry_A798(sEquipDb_A798* db, int id)
{
    short idx = db->map[id];
    if (idx >= 0) {
        return &db->entries[idx];
    }
    return 0;
}

static inline void setText_A798(void* self, char* s)
{
    cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x4C), GetHashValue32(s));
}

extern "C" void func_0019A798(void* self)
{
    if (*(cUIObj_A798**)((char*)self + 0x4C) == 0)
        return;
    (*(cUIObj_A798**)((char*)self + 0x4C))->setVisible(0);
    int sel = (*(sList_A798**)((char*)self + 0x5C))->sel;
    if (sel < 0 || sel >= *(int*)((char*)self + 0x958)) {
        (*(cUIObj_A798**)((char*)self + 0x4C))->setVisible(1);
        if (!isMode1_A798(self)) {
            if (*(int*)((char*)self + 0xAE4) != 0)
                setText_A798(self, D_004608D8);
            else
                setText_A798(self, D_004608F0);
        } else {
            setText_A798(self, D_00460908);
        }
        return;
    }
    sEquipItem_A798* item = *(sEquipItem_A798**)((char*)self + (sel << 2) + 0x124);
    if (item->flags & 0x20) {
        setText_A798(self, D_00460920);
    } else if (isMode1_A798(self)) {
        int cost = item->cost;
        if (cost > 0)
            cost *= 10;
        if (*(int*)((char*)self + 0xC0) >= cost)
            setText_A798(self, D_00460940);
        else
            setText_A798(self, D_00460958);
    } else {
        sEquipDb_A798* db = (sEquipDb_A798*)func_0014AD28(cBE_getInterface(cBE_getBE(), 9), *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0xBC));
        sEquipEntry_A798* e = getEntry_A798(db, item->id);
        int idx = sel - (*(sList_A798**)((char*)self + 0x5C))->top;
        if (D_004A18D8 >= *(int*)((char*)self + 0xC4) + *(int*)((char*)self + (idx << 2) + 0xA78)) {
            if (e->flags & 4)
                setText_A798(self, D_00460970);
            else
                setText_A798(self, D_00460970);
        } else {
            setText_A798(self, D_00460988);
        }
    }
    (*(cUIObj_A798**)((char*)self + 0x4C))->setVisible(1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019A9B8);
#ifdef SKIP_ASM
extern "C" void func_0019AB78(void* self);
extern "C" void func_0019AA08(void* self);
extern "C" void func_0019A798(void* self);

extern "C" void func_0019A9B8(void* self)
{
    bool b = *(int*)((char*)self + 0xC8) == 1;
    if (b) {
        func_0019AB78(self);
    } else {
        func_0019AA08(self);
    }
    func_0019A798(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019AA08);
#ifdef SKIP_ASM
extern "C" int func_0019A098(void* self, const char* name);
extern "C" void func_0019BD48(void* self, int a1);

struct sVEK19AA08 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void showK19AA08(char* o, int on)
{
    sVEK19AA08* vt = *(sVEK19AA08**)(o + 8);
    vt[9].fn(o + vt[9].delta, on);
}

extern "C" void func_0019AA08(void* self)
{
    if (*(void**)((char*)self + 0x5C) == 0)
        return;
    char* o = *(char**)((char*)self + 0x6C);
    if (o != 0)
        showK19AA08(o, 0);
    o = *(char**)((char*)self + 0x84);
    if (o != 0)
        showK19AA08(o, 0);
    o = *(char**)((char*)self + 0x7C);
    if (o != 0)
        showK19AA08(o, 0);
    int idx = *(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x95);
    int arg = 0;
    if (idx < *(int*)((char*)self + 0x958)) {
        char* e = *(char**)((char*)self + (idx << 2) + 0x124);
        unsigned int f = *(unsigned int*)(e + 0x34);
        if (f & 4) {
            if (!(f & 0x20)) {
                showK19AA08(*(char**)((char*)self + 0x6C), 1);
                int b = *(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x98);
                char* o2 = *(char**)((char*)self + 0x84);
                arg = *(int*)((char*)self + ((idx - b) << 2) + 0xA78);
                if (o2 != 0 && *(char**)(e + 0x30) != 0 && *(int*)((char*)self + 0xA60) != 0) {
                    showK19AA08(o2, 1);
                    int r = func_0019A098(self, *(char**)(e + 0x30));
                    char* o3 = *(char**)((char*)self + 0x84);
                    *(int*)(o3 + 0x78) = r;
                    *(int*)(o3 + 0x7C) = 0;
                }
            }
        }
    }
    func_0019BD48(self, arg);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019AB78);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
// PORT: the unit declares func_00198AF0(void*), but it formats an int price; bind an int view.
extern "C" const char* func_00198AF0_price(int price) __asm__("func_00198AF0");

struct sVEntryK19AB78 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void showK19AB78(void* o, int on)
{
    sVEntryK19AB78* vt = *(sVEntryK19AB78**)((char*)o + 8);
    vt[9].fn((char*)o + vt[9].delta, on);
}

extern "C" void func_0019AB78(void* self)
{
    char* menu = *(char**)((char*)self + 0x5C);
    if (menu == 0)
        return;
    int sel = *(unsigned char*)(menu + 0x95);
    char* item = 0;
    if (sel >= 0 && sel < *(int*)((char*)self + 0x958))
        item = *(char**)((char*)self + (sel << 2) + 0x124);
    if (*(void**)((char*)self + 0x88) != 0) {
        showK19AB78(*(void**)((char*)self + 0x88), 0);
        if (item != 0 && *(int*)((char*)self + 0xA70) >= 0) {
            char* o = *(char**)((char*)self + 0x88);
            *(int*)(o + 0x78) = *(int*)((char*)self + 0xA70);
            *(int*)(o + 0x7C) = 0;
            showK19AB78(*(void**)((char*)self + 0x88), 1);
        }
    }
    if (*(void**)((char*)self + 0x68) != 0) {
        showK19AB78(*(void**)((char*)self + 0x68), 0);
        if (item != 0 && !(*(int*)(item + 0x34) & 0x20)) {
            int price = *(short*)(item + 0xE);
            if (price > 0)
                price *= 10;
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x68), func_00198AF0_price(price));
            showK19AB78(*(void**)((char*)self + 0x68), 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019ACA0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_001A0548(void* self, int a1);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" void func_0019FBE0(void* rider, void* item, int a2, int a3);

extern "C" void func_0019ACA0(void* self)
{
    void* rider = func_001A0548(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44));
    func_0019FBE0(rider, func_0014AD28(cBE_getInterface_Fv(cBE_getBE(), 9), *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0xBC)), 0, 1);
}
#endif

INCLUDE_ASM("fe/festatecharequipdetail", func_0019AD18);

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019AFD0);
#ifdef SKIP_ASM
struct sEquipEntry_AFD0 {
    unsigned short f0;
    unsigned short flags;
};
struct sEquipDb_AFD0 {
    char pad_0x0[0x288];
    short* map;     // 0x288
    char pad_0x28c[4];
    sEquipEntry_AFD0 entries[1];  // 0x290
};
struct sEquipItem_AFD0 {
    int f0;
    short id;       // 0x4
    char pad_0x6[0x34 - 0x6];
    int flags;      // 0x34
};
extern "C" int func_0014D7E8(int a0, int a1, int a2, void* out, int a4, int a5);

static inline sEquipEntry_AFD0* getEntry_AFD0(sEquipDb_AFD0* db, int id)
{
    short idx = db->map[id];
    if (idx >= 0) {
        return &db->entries[idx];
    }
    return 0;
}

extern "C" int func_0019AFD0(void* self, int a1, sEquipDb_AFD0* db, int a3)
{
    sEquipItem_AFD0* items[528];
    int n = func_0014D7E8(a1, *(int*)((char*)self + 0xBC), a3, items, -1, 1);
    int i;
    for (i = 0; i < n; i++) {
        sEquipItem_AFD0* it = items[i];
        if (it->flags & 4) {
            if (getEntry_AFD0(db, it->id)->flags & 2) {
                if (!(it->flags & 0x20)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019B098);
#ifdef SKIP_ASM
struct sEquipEntry_B098 {
    unsigned short f0;
    unsigned short flags;
};
struct sEquipDb_B098 {
    char pad_0x0[0x288];
    short* map;     // 0x288
    char pad_0x28c[4];
    sEquipEntry_B098 entries[1];  // 0x290
};
struct sEquipItem_B098 {
    short f0;
    signed char slot;   // 0x2
    char f3;
    short id;       // 0x4
    char pad_0x6[0x34 - 0x6];
    int flags;      // 0x34
};
extern "C" int func_0014D7E8(int a0, int a1, int a2, void* out, int a4, int a5);

static inline sEquipEntry_B098* getEntry_B098(sEquipDb_B098* db, int id)
{
    short idx = db->map[id];
    if (idx >= 0) {
        return &db->entries[idx];
    }
    return 0;
}

extern "C" int func_0019B098(void* self, int a1, sEquipDb_B098* db, int a3)
{
    sEquipItem_B098* items[528];
    int n = func_0014D7E8(a1, *(int*)((char*)self + 0xBC), a3, items, -1, 1);
    int i;
    for (i = 0; i < n; i++) {
        sEquipItem_B098* it = items[i];
        if (it->flags & 4) {
            if (!(getEntry_B098(db, it->id)->flags & 2)) {
                if (it->slot == *(int*)((char*)self + 0xCC)) {
                    if (!(it->flags & 0x20)) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
#endif

INCLUDE_ASM("fe/festatecharequipdetail", func_0019B180);

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019B458);
#ifdef SKIP_ASM
struct sEquipListWidget {
    char pad_0x0[0x95];
    unsigned char sel;   // 0x95
    char pad_0x96[2];
    unsigned char top;   // 0x98
};

struct sEquipDetail {
    char pad_0x0[0x5C];
    sEquipListWidget* list;   // 0x5C
    char pad_0x60[0x124 - 0x60];
    int items[(0x958 - 0x124) / 4];  // 0x124
    int count;   // 0x958
};

extern "C" int func_0019B458(sEquipDetail* self, int idx)
{
    int top, sel, n;
    if (idx >= self->count) {
        return 0;
    }
    for (; idx < self->count - 1; idx++) {
        self->items[idx] = self->items[idx + 1];
    }
    self->count--;
    self->items[self->count] = 0;
    n = self->count;
    top = self->list->top;
    sel = self->list->sel;
    if (n < top + 6) {
        top = n - 6;
    }
    if (sel >= n) {
        sel = n - 1;
    }
    if (top < 0) {
        top = 0;
    }
    self->list->top = top;
    if (sel < 0) {
        sel = 0;
    }
    self->list->sel = sel;
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019B518);
#ifdef SKIP_ASM
extern "C" void func_0019B7E0(void* self, int idx);

extern "C" int func_0019B518(void* self)
{
    int j = *(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x98);
    int i = 0;
    while (i < 6 && j < *(int*)((char*)self + 0x958)) {
        func_0019B7E0(self, i);
        i++;
        j++;
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019B598);
#ifdef SKIP_ASM
extern "C" void func_0019BA60(void* self, int idx);

extern "C" int func_0019B598(void* self)
{
    int j = *(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x98);
    int i = 0;
    while (i < 6 && j < *(int*)((char*)self + 0x958)) {
        func_0019BA60(self, i);
        i++;
        j++;
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019B618);
#ifdef SKIP_ASM
struct cUIText;
class cUIObj_B618 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
    virtual void v10();
    virtual void setColor(void* c);
};
struct sList_B618 {
    char pad_0x0[0x95];
    unsigned char sel;   // 0x95
    unsigned char count; // 0x96
    char pad_0x97;
    unsigned char top;   // 0x98
};
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" int func_0019B518(void* self);
extern "C" int func_0019B598(void* self);
extern "C" void func_0039B760(void* menu, int n);
extern char D_004C6708[];
extern char D_004609A0[];

static inline int isMode1_B618(void* self)
{
    return *(int*)((char*)self + 0xC8) == 1;
}

extern "C" void func_0019B618(void* self, int reset, int select)
{
    if (*(void**)((char*)self + 0x5C) == 0)
        return;
    cUIObj_B618** a = (cUIObj_B618**)((char*)self + 0x8C);
    cUIObj_B618** b = (cUIObj_B618**)((char*)self + 0xA4);
    for (int i = 0; i < 6; i++) {
        a[i]->setVisible(0);
        b[i]->setVisible(0);
    }
    if (reset) {
        if (*(int*)((char*)self + 0x958) == 0)
            func_0039B760(*(void**)((char*)self + 0x5C), 1);
        else
            func_0039B760(*(void**)((char*)self + 0x5C), *(unsigned char*)((char*)self + 0x958));
    }
    int n;
    if (isMode1_B618(self))
        n = func_0019B598(self);
    else
        n = func_0019B518(self);
    int v;
    if (n == 0) {
        (*(cUIObj_B618**)((char*)self + 0x8C))->setVisible(1);
        (*(cUIObj_B618**)((char*)self + 0x8C))->setColor(D_004C6708);
        cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x8C), GetHashValue32(D_004609A0));
        (*(sList_B618**)((char*)self + 0x5C))->count = 1;
        (*(sList_B618**)((char*)self + 0x5C))->top = 0;
        v = 0;
        n = 1;
    } else {
        sList_B618* l = *(sList_B618**)((char*)self + 0x5C);
        v = l->sel - l->top;
    }
    if (v >= n)
        v = n - 1;
    if (v < 0)
        v = 0;
    if (reset)
        v = 0;
    if (select) {
        sList_B618* l = *(sList_B618**)((char*)self + 0x5C);
        cUIMenu_setSelectedByIndex(l, l->top + v);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019B7E0);
#ifdef SKIP_ASM
extern "C" int func_0014AFB0(void* self, int a1, int a2, int id, int locked);
extern "C" void func_003E6574(void* dst, void* src, int n);
extern "C" void func_0014ACB0(void* self, int a1, int a2, void* src);
extern "C" int func_0014B478(void* self, int a1, int a2);

struct sFlagEntry_19B7E0
{
    short id;
    unsigned short flags;
    sFlagEntry_19B7E0() : id(-1), flags(0) {}
};

struct sProfile_19B7E0
{
    char pad[0x288];
    short* index;
    int count;
    sFlagEntry_19B7E0 entries[0x20D];
};

static inline sFlagEntry_19B7E0* getEntry_19B7E0(sProfile_19B7E0* p, int idx)
{
    short k = p->index[idx];
    if (k >= 0)
        return &p->entries[k];
    return 0;
}

static inline int IsSet_19B7E0(sFlagEntry_19B7E0* e)
{
    return e->flags & 4;
}

struct sItem_19B7E0 {
    int f0;
    short id;           // 0x4
    char pad6[0x14 - 0x6];
    char* name;         // 0x14
    char pad18[0x34 - 0x18];
    int flags;          // 0x34
};

struct sCharEquip_19B7E0 {
    char pad0[0x44];
    signed char team;               // 0x44
    char pad45[0x5C - 0x45];
    sList_B618* list;               // 0x5C
    char pad60[0x8C - 0x60];
    cUIObj_B618* texts[6];          // 0x8C
    cUIObj_B618* icons[6];          // 0xA4
    int slot;                       // 0xBC
    char padC0[0x124 - 0xC0];
    sItem_19B7E0* items[(0xA78 - 0x124) / 4]; // 0x124
    int vals[6];                    // 0xA78
    char padA90[0xA98 - 0xA90];
    int colLocked;                  // 0xA98
    int colFree;                    // 0xA9C
    int colOwned;                   // 0xAA0
};

extern "C" void func_0019B7E0(void* selfv, int i)
{
    sCharEquip_19B7E0* self = (sCharEquip_19B7E0*)selfv;
    sList_B618* l = self->list;
    int top = l ? l->top : 0;
    sItem_19B7E0* item = self->items[top + i];
    cUIObj_B618* text = self->texts[i];
    cUIObj_B618* icon = self->icons[i];
    self->vals[i] = 0xFFFE7961;
    int col = 0;
    if (item->flags & 0x20) {
        col = self->colOwned;
    } else {
        void* iface = cBE_getInterface(cBE_getBE(), 9);
        sProfile_19B7E0* prof = (sProfile_19B7E0*)func_0014AD28(iface, self->team, self->slot);
        sFlagEntry_19B7E0* e = getEntry_19B7E0(prof, item->id);
        sFlagEntry_19B7E0 save[0x20D];
        func_003E6574(save, prof->entries, 0x834);
        int before = func_0014B478(iface, self->team, self->slot);
        if (func_0014AFB0(iface, self->team, self->slot, item->id, !IsSet_19B7E0(e))) {
            self->vals[i] = func_0014B478(iface, self->team, self->slot) - before;
            if (IsSet_19B7E0(e))
                col = self->colLocked;
            else
                col = self->colFree;
        }
        func_0014ACB0(iface, self->team, self->slot, save);
    }
    if (text) {
        if (item->flags & 0x20)
            cUIText_setUnicodeStringByID((cUIText*)text, GetHashValue32(item->name));
        else
            cUIText_setAsciiString((cUIText*)text, item->name);
        text->setVisible(1);
    }
    if (icon) {
        if (col) {
            icon->setVisible(1);
            *(int*)((char*)icon + 0x7C) = col;
            *(int*)((char*)icon + 0x78) = -1;
        } else {
            icon->setVisible(0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019BA60);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);

struct sVEntryK19BA60 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void showK19BA60(void* o, int on)
{
    sVEntryK19BA60* vt = *(sVEntryK19BA60**)((char*)o + 8);
    vt[9].fn((char*)o + vt[9].delta, on);
}

struct sCharEquipK19BA60 {
    char pad_0x0[0x5C];
    char* menu;             // 0x5C
    char pad_0x60[0x8C - 0x60];
    cUIText* texts[6];      // 0x8C
    char* icons[6];         // 0xA4
    int bank;               // 0xBC
    int money;              // 0xC0
    char pad_0xC4[0x124 - 0xC4];
    char* items[1];         // 0x124
};

extern "C" void func_0019BA60(void* p, int i)
{
    sCharEquipK19BA60* self = (sCharEquipK19BA60*)p;
    char* menu = self->menu;
    int top = 0;
    if (menu != 0)
        top = *(unsigned char*)(menu + 0x98);
    char* item = self->items[top + i];
    cUIText* text = self->texts[i];
    char* icon = self->icons[i];
    int tex;
    if (*(int*)(item + 0x34) & 0x20) {
        tex = *(int*)((char*)self + 0xAA0);
    } else {
        int price = *(short*)(item + 0xE);
        if (price > 0)
            price *= 10;
        if (self->money < price)
            tex = *(int*)((char*)self + 0xA94);
        else
            tex = *(int*)((char*)self + 0xA90);
    }
    if (text != 0) {
        if (*(int*)(item + 0x34) & 0x20)
            cUIText_setUnicodeStringByID(text, GetHashValue32(*(char**)(item + 0x14)));
        else
            cUIText_setAsciiString(text, *(char**)(item + 0x14));
        showK19BA60(text, 1);
    }
    if (icon != 0) {
        if (tex != 0) {
            showK19BA60(icon, 1);
            *(int*)(icon + 0x7C) = tex;
            *(int*)(icon + 0x78) = -1;
        } else {
            showK19BA60(icon, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019BBA0);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" const char* func_00198AF0(void* a0);

extern "C" void func_0019BBA0(void* self)
{
    if (*(cUIText**)((char*)self + 0x64) != 0) {
        cUIText_setAsciiString(*(cUIText**)((char*)self + 0x64), func_00198AF0(*(void**)((char*)self + 0xC0)));
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", cFEStateCharEquip_updateHeading);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
// PORT: func_0014BDB8 is declared (void*) but never reads its argument; called here with none
void* func_0014BDB8_noarg() __asm__("func_0014BDB8__FPv");
extern "C" int func_0014D448(void* self, int g, int key);
extern int D_004A11D0;
extern char D_004609B0[];

struct sBEEntry38K19BBE0 {
    char pad_0x00[0x14];
    char* name;    // 0x14
    char pad_0x18[0x38 - 0x18];
};
struct sBETableK19BBE0 {
    char pad_0x00[4];
    sBEEntry38K19BBE0* entries; // 0x4
};

static inline sBEEntry38K19BBE0* findEntryK19BBE0(sBETableK19BBE0* t, int g, int key)
{
    int idx = func_0014D448(t, g, key);
    if (idx < 0) {
        return 0;
    }
    return &t->entries[idx];
}

extern "C" void cFEStateCharEquip_updateHeading(void* self, int id)
{
    if (*(cUIText**)((char*)self + 0x58) != 0) {
        if (id == D_004A11D0) {
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x58), GetHashValue32(D_004609B0));
        } else {
            sBEEntry38K19BBE0* e = findEntryK19BBE0((sBETableK19BBE0*)func_0014BDB8_noarg(), *(int*)((char*)self + 0xBC), id);
            cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x58), GetHashValue32(e->name));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019BC90);
#ifdef SKIP_ASM
extern int D_004A18D8;

struct sVEntry0019BC90 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sVec3K19BC90 {
    float x, y, z;
    sVec3K19BC90(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

extern "C" void func_0019BC90(void* self)
{
    char* o = *(char**)((char*)self + 0x70);
    if (o != 0) {
        float t = (float)(*(int*)((char*)self + 0xC4) - 0x5DC) / (float)(D_004A18D8 - 0x5DC);
        if (t < 0.0f) {
            t = 0.0f;
        }
        sVEntry0019BC90* vt = *(sVEntry0019BC90**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
        *(sVec3K19BC90*)(*(char**)((char*)self + 0x70) + 0x50) = sVec3K19BC90(1.0f, -t, 1.0f);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019BD48);
#ifdef SKIP_ASM
extern int D_004A18D8;
extern char D_004C66E8[];
extern char D_004C66F8[];

struct sVec3K19BD48 {
    float x, y, z;
    sVec3K19BD48(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sVEntryK19BD48 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sVEntryIK19BD48 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0019BD48(void* self, int delta)
{
    if (*(void**)((char*)self + 0x74) == 0)
        return;
    float t = (float)(*(int*)((char*)self + 0xC4) + delta - 1500) / (float)(D_004A18D8 - 1500);
    if (t > 1.0f)
        t = 1.0f;
    else if (t < 0.0f)
        t = 0.0f;
    if (D_004A18D8 < *(int*)((char*)self + 0xC4) + delta) {
        char* o = *(char**)((char*)self + 0x74);
        sVEntryK19BD48* vt = *(sVEntryK19BD48**)(o + 8);
        vt[11].fn(o + vt[11].delta, D_004C66E8);
    } else {
        char* o = *(char**)((char*)self + 0x74);
        sVEntryK19BD48* vt = *(sVEntryK19BD48**)(o + 8);
        vt[11].fn(o + vt[11].delta, D_004C66F8);
    }
    {
        char* o = *(char**)((char*)self + 0x74);
        sVEntryIK19BD48* vt = *(sVEntryIK19BD48**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
    }
    *(sVec3K19BD48*)(*(char**)((char*)self + 0x74) + 0x50) = sVec3K19BD48(1.0f, -t, 1.0f);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019BE80);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014B560(void* iface, int a1, int a2, int a3, int a4);

extern "C" void func_0019BE80(void* self)
{
    int idx = *(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x95);
    char* item = *(char**)((char*)self + (idx << 2) + 0x124);
    *(void**)((char*)self + 0xC0) = func_0014B560(cBE_getInterface_Fv(cBE_getBE(), 9),
        *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0xBC), *(short*)(item + 4), 1);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019BEE8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" int func_0014AFB0(void* self, int a1, int a2, int id, int locked);
extern "C" void func_0014AEA8(void* self, int a1, int a2);

struct sItemK19BEE8 {
    short id;
    unsigned short flags;
};
struct sItemListK19BEE8 {
    char pad_0x0[0x288];
    short* map;                 // 0x288
    int count;                  // 0x28C
    sItemK19BEE8 items[1];      // 0x290
};

static inline sItemK19BEE8* getItemK19BEE8(sItemListK19BEE8* l, int id)
{
    int idx = l->map[id];
    if (idx >= 0)
        return &l->items[idx];
    return 0;
}

extern "C" int func_0019BEE8(void* self)
{
    if (*(int*)((char*)self + 0x958) <= 0)
        return 0;
    char* item = *(char**)((char*)self + (*(unsigned char*)(*(char**)((char*)self + 0x5C) + 0x95) << 2) + 0x124);
    if (!(*(int*)(item + 0x34) & 4))
        return 0;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    sItemListK19BEE8* list = (sItemListK19BEE8*)func_0014AD28(iface, *(signed char*)((char*)self + 0x44),
                                                              *(int*)((char*)self + 0xBC));
    sItemK19BEE8* e = getItemK19BEE8(list, *(short*)(item + 4));
    int mask = 4;
    if (func_0014AFB0(iface, *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0xBC), *(short*)(item + 4),
                      (e->flags & mask) == 0)) {
        func_0014AEA8(iface, *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0xBC));
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019BFE0);
#ifdef SKIP_ASM
extern "C" void func_0019BFE0(void) {

}
#endif

INCLUDE_ASM("fe/festatecharequipdetail", func_0019BFE8);

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019C7E8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001CABA8(void* self, void* engine, void* owner, signed char idx);
extern "C" void cBuyPopupInfo_initBuyBolt(int* self, int a1, int a2, int a3);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00460790[];

extern "C" void func_0019C7E8(void* self, void* item)
{
    void* popup = func_001CABA8(cMemMan_alloc(0x70, D_00460790, 0, 0), *(void**)((char*)self + 0x10), self, *(signed char*)((char*)self + 0x44));
    int price = *(short*)((char*)item + 0xE);
    int id = *(int*)((char*)item + 0x14);
    if (price > 0) {
        price *= 10;
    }
    cBuyPopupInfo_initBuyBolt((int*)((char*)popup + 0x48), id, price, *(int*)((char*)self + 0xC0));
    func_0039F290(*(char**)((char*)self + 0x10) + 0x18, popup);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019C880);
#ifdef SKIP_ASM
extern "C" void* func_0019C8F8(void* self, void* item);

extern "C" void* func_0019C880(void* self)
{
    char* item = *(char**)((char*)self + 0x1F40);
    *(void**)((char*)self + 0x1F40) = func_0019C8F8(self, item);
    *(short*)(item + 0xE) = -1;
    char* head = *(char**)((char*)self + 0x1F40);
    if (head != 0) {
        *(short*)(head + 0xC) = -1;
    }
    return item;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019C8D0);
#ifdef SKIP_ASM
extern "C" void* func_0019C8D0(void* self, void* item)
{
    if (item != 0) {
        short idx = *(short*)((char*)item + 0xc);
        if (idx >= 0) {
            return (char*)self + (idx << 4);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019C8F8);
#ifdef SKIP_ASM
extern "C" void* func_0019C8F8(void* self, void* item)
{
    if (item != 0) {
        short idx = *(short*)((char*)item + 0xe);
        if (idx >= 0) {
            return (char*)self + (idx << 4);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019C920);
#ifdef SKIP_ASM
extern "C" int func_0019C920(void* self, int a1)
{
    int diff = a1 - (int)self;
    if (a1 != 0) return diff >> 4;
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019C938);
#ifdef SKIP_ASM
struct sNodeK19C938 {
    int key;
    short f4;
    short f6;
    short f8;
    short fA;
    short prev;   // 0xC
    short next;   // 0xE
};

extern "C" void* func_0019C880(void* self);
extern "C" void* func_0019C8F8(void* self, void* item);
// PORT: func_0019C920 takes the node pointer as an int.
extern "C" int func_0019C920(void* self, int a1);

extern "C" void* func_0019C938(void* self, int hi, int lo, int create)
{
    int key = (hi << 16) | lo;
    int b = key % 400;
    sNodeK19C938* prev = 0;
    sNodeK19C938* n = *(sNodeK19C938**)((char*)self + (b << 2) + 0x1900);
    while (*(void**)((char*)self + 0x1F40) != 0 || n != 0) {
        if (n == 0) {
            if (create) {
                n = (sNodeK19C938*)func_0019C880(self);
                n->prev = func_0019C920(self, (int)prev);
                if (prev != 0) {
                    n->prev = func_0019C920(self, (int)prev);
                    prev->next = func_0019C920(self, (int)n);
                } else {
                    n->prev = -1;
                    *(sNodeK19C938**)((char*)self + (b << 2) + 0x1900) = n;
                }
                n->next = -1;
            }
            break;
        }
        if (n->key == key)
            break;
        prev = n;
        n = (sNodeK19C938*)func_0019C8F8(self, prev);
    }
    if (n != 0)
        n->key = key;
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CA70);
#ifdef SKIP_ASM
struct sNode_CA70 {
    int key;
    short f4;
    short f6;
    short f8;
    short fA;
    short prev;
    short next;
};
extern "C" void* func_0019C8D0(void* self, void* item);
extern "C" void* func_0019C8F8(void* self, void* item);
extern "C" int func_0019C920(void* self, int a1);

extern "C" void func_0019CA70(void* self, void* nodep)
{
    sNode_CA70* node = (sNode_CA70*)nodep;
    if (node != 0) {
        int h = node->key % 400;
        if (node->prev < 0) {
            *(void**)((char*)self + (h << 2) + 0x1900) = func_0019C8F8(self, node);
        } else {
            ((sNode_CA70*)func_0019C8D0(self, node))->next = node->next;
        }
        if (node->next >= 0) {
            ((sNode_CA70*)func_0019C8F8(self, node))->prev = node->prev;
        }
        node->key = -1;
        node->fA = -1;
        node->f8 = -1;
        node->prev = -1;
        // PORT: free-list head pointer passed as int (unit declares func_0019C920(void*, int))
        node->next = func_0019C920(self, *(int*)((char*)self + 0x1F40));
        *(sNode_CA70**)((char*)self + 0x1F40) = node;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CB38);
#ifdef SKIP_ASM
extern "C" void func_0019CB60(void* self);

extern "C" void* func_0019CB38(void* self)
{
    func_0019CB60(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CB60);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, unsigned int value, int size);

struct sNode0019CB60 {
    int field_0x0;
    short field_0x4;
    short field_0x6;
    int field_0x8;
    short prev;
    short next;
};

extern "C" void func_0019CB60(void* self)
{
    func_003E6448(self, 0xFFFFFFFF, 0x1900);
    func_003E6448((char*)self + 0x1900, 0, 0x640);
    *(void**)((char*)self + 0x1F40) = self;
    sNode0019CB60* n = (sNode0019CB60*)self;
    for (int i = 0; i < 400; i++) {
        n[i].next = i + 1;
        n[i].prev = i - 1;
        n[i].field_0x4 = 0;
        n[i].field_0x6 = 0;
    }
    n[399].next = -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CBE0);
#ifdef SKIP_ASM
extern "C" void* func_0019C938(void* self, int a1, int a2, int a3);

extern "C" int func_0019CBE0(void* self, int a1, int a2)
{
    void* p = func_0019C938(self, a1, a2, 0);
    if (p != 0) {
        if ((*(short*)((char*)p + 6) >> a1) & 1) {
            return *(short*)((char*)p + 0xA);
        }
    }
    return -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CC30);
#ifdef SKIP_ASM
extern "C" void* func_0019C938(void* self, int a1, int a2, int a3);

extern "C" void func_0019CA70(void* self, void* node);
struct sNode_CC30 {
    int key;
    short f4;
    short mask;
    short f8;
    short val;
    short prev;
    short next;
};

extern "C" void func_0019CC30(void* self, int bit, int a2, int val)
{
    sNode_CC30* p = (sNode_CC30*)func_0019C938(self, bit, a2, val != -1);
    if (p != 0) {
        if (val < 0) {
            if ((p->mask >> bit) & 1) {
                p->mask &= ~(1 << bit);
                if (p->mask == 0 && p->f8 < 0) {
                    func_0019CA70(self, p);
                }
            }
        } else {
            p->val = val;
            p->mask |= 1 << bit;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CCE8);
#ifdef SKIP_ASM
extern "C" void* func_0019C938(void* self, int a1, int a2, int a3);

extern "C" int func_0019CCE8(void* self, int a1, int a2)
{
    void* p = func_0019C938(self, a1, a2, 0);
    if (p != 0) {
        if ((*(short*)((char*)p + 4) >> a1) & 1) {
            return *(short*)((char*)p + 0x8);
        }
    }
    return -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CD38);
#ifdef SKIP_ASM
extern "C" void* func_0019C938(void* self, int a1, int a2, int a3);
extern "C" void func_0019CA70(void* self, void* node);
struct sNode_CD38 {
    int key;
    short mask;
    short f6;
    short val;
    short fA;
    short prev;
    short next;
};

extern "C" void func_0019CD38(void* self, int bit, int a2, int val)
{
    sNode_CD38* p = (sNode_CD38*)func_0019C938(self, bit, a2, val != -1);
    if (p != 0) {
        if (val < 0) {
            if ((p->mask >> bit) & 1) {
                p->mask &= ~(1 << bit);
                if (p->mask == 0 && p->fA < 0) {
                    func_0019CA70(self, p);
                }
            }
        } else {
            p->val = val;
            p->mask |= 1 << bit;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CDF0);
#ifdef SKIP_ASM
extern void* D_004A196C;
extern "C" void func_0019CE68(void* self);

extern "C" void* func_0019CDF0(void* self)
{
    D_004A196C = self;
    func_0019CE68(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CE20);
#ifdef SKIP_ASM
extern void* D_004A196C;
extern "C" void func_0019CF40(void* self);
void operator_delete(int* p);

extern "C" void func_0019CE20(void* self, int flags)
{
    D_004A196C = 0;
    func_0019CF40(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CE68);
#ifdef SKIP_ASM
extern void* D_004A1968;
extern char D_004609C0[];

struct sEquipEntryK19CE68 {
    int f0;                // 0x0
    char b4;               // 0x4
    char pad_0x005[0x104 - 0x5];
    int f104;              // 0x104
    int f108;              // 0x108
    int pad_0x10C;
    int f110;              // 0x110
    int f114;              // 0x114
    int f118;              // 0x118
    int pad_0x11C;
};
struct sEquipSlotK19CE68 {
    sEquipEntryK19CE68 e[256];
};
struct sEquipTableK19CE68 {
    sEquipSlotK19CE68 slots[10]; // 0x0
    int fB4000;                  // 0xB4000
    int fB4004;                  // 0xB4004
    int counts[10];              // 0xB4008
};

extern "C" void func_0019CE68(void* self)
{
    sEquipTableK19CE68* t = (sEquipTableK19CE68*)self;
    int i;
    int j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 256; j++) {
            sEquipEntryK19CE68* e = &t->slots[i].e[j];
            e->f0 = 0;
            e->b4 = 0;
            e->f104 = 0;
            e->f118 = 0;
            e->f108 = 0;
            e->f114 = 0;
            e->f110 = -1;
        }
        t->counts[i] = 1;
    }
    t->fB4004 = 0;
    t->fB4000 = 0;
    if (D_004A1968 == 0) {
        D_004A1968 = func_0019CB38(cMemMan_alloc(0x1F44, D_004609C0, 0, 0));
    } else {
        func_0019CB60(D_004A1968);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019CF40);
#ifdef SKIP_ASM
struct sEquipTable_D4B8;
extern "C" void func_0019D4B8(sEquipTable_D4B8* self, int bank, int i);
void operator_delete(int* p);
extern void* D_004A1968;

struct sEquipTableK19CF40 {
    char slots[0xB4008];
    int counts[10];    // 0xB4008
};

extern "C" void func_0019CF40(void* self)
{
    sEquipTableK19CF40* t = (sEquipTableK19CF40*)self;
    int i;
    int j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 256; j++) {
            func_0019D4B8((sEquipTable_D4B8*)self, i, j);
        }
        t->counts[i] = 1;
    }
    if (D_004A1968 != 0) {
        operator_delete((int*)D_004A1968);
    }
    D_004A1968 = 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D000);
#ifdef SKIP_ASM
struct sEquipTable_DC20;
struct sEquipSlot_DC20;
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* ptr);
extern "C" int func_003B4818(void* data);
extern "C" void func_003B47F8(void* src, void* dst);
extern "C" void func_0019D578(sEquipTable_DC20* self, int bank, int size);
extern "C" void func_0019D738(sEquipTable_DC20* self, int bank, int size);
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern char D_004609D8[];
extern char D_00538B00[];

struct sSlotK19D000 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int timer;      // 0x114
    int size;       // 0x118
};

extern "C" void func_0019D000(sEquipTable_DC20* self, int bank, sEquipSlot_DC20* p)
{
    sSlotK19D000* slot = (sSlotK19D000*)p;
    if (slot == 0)
        return;
    if (slot->data == 0)
        return;
    int size = func_003B4818(slot->data);
    if (size <= 0)
        return;
    func_0019D578(self, bank, size);
    void* buf = operator_new__FUi(size, D_004609D8, 0x60000000, 0);
    while (buf == 0) {
        MUTEX_lock(D_00538B00);
        MUTEX_unlock(D_00538B00);
        func_0019D738(self, bank, size);
        buf = operator_new__FUi(size, D_004609D8, 0x60000000, 0);
    }
    func_003B47F8(slot->data, buf);
    if (slot->data != 0)
        cMemMan_free(slot->data);
    slot->data = buf;
    *(int*)((char*)self + 0xB4000) += size - slot->size;
    slot->size = size;
}
#endif

INCLUDE_ASM("fe/festatecharequipdetail", func_0019D140);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D250);
#ifdef SKIP_ASM
struct sEquipTable_DC20;
struct sEquipSlot_DC20;
extern "C" int func_003DF980(int handle);
extern "C" int ASYNCFILE_release(int handle, int a1, void* status);
extern "C" void func_0019D000(sEquipTable_DC20* self, int bank, sEquipSlot_DC20* slot);
extern "C" void func_0019D140(void* self, int bank);
extern "C" void func_0019D8B8(sEquipTable_DC20* self, int bank, int i);

struct sSlotK19D250 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int timer;      // 0x114
    int size;       // 0x118
    unsigned int stamp; // 0x11C
};
struct sBankK19D250 {
    sSlotK19D250 e[256];
};
struct sTableK19D250 {
    sBankK19D250 banks[10];      // 0x0
    int fB4000;                  // 0xB4000
    int nPending;                // 0xB4004
};

extern "C" void func_0019D250(void* p)
{
    sTableK19D250* self = (sTableK19D250*)p;
    int i;
    int j;
    for (i = 0; i < 10; i++) {
        sSlotK19D250* s = (sSlotK19D250*)((char*)self + i * 0x12000);
        for (j = 0; j < 256; j++, s++) {
            if (s->pending != 0 && s->state == 2) {
                int r = func_003DF980(s->handle);
                if (r == 1) {
                    int status[4];
                    ASYNCFILE_release(s->handle, 0, status);
                    func_0019D000((sEquipTable_DC20*)self, i, (sEquipSlot_DC20*)s);
                    if (s->timer == 0)
                        s->state = 0;
                    else
                        s->state = r;
                    s->pending = 0;
                    if (--self->nPending <= 0)
                        func_0019D140(self, i);
                }
            } else if (self->nPending <= 0 && s->state == 3) {
                func_0019D8B8((sEquipTable_DC20*)self, i, j);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D3B0);
#ifdef SKIP_ASM
struct sEquipSlot_D3B0 {
    int used;               // 0x000
    char pad_0x4[0x100];
    int valid;              // 0x104
    char pad_0x108[0x14];
    unsigned int stamp;     // 0x11C
};

extern "C" int func_0019D3B0(void* self, int bank)
{
    unsigned int best = 0;
    int bestIdx = -1;
    sEquipSlot_D3B0* p = (sEquipSlot_D3B0*)((char*)self + bank * 0x12000);
    for (int i = 0; i < 256; i++, p++) {
        if (p->used == 0) {
            if (p->valid == 0) {
                return i;
            }
            if (bestIdx < 0 || p->stamp < best) {
                best = p->stamp;
                bestIdx = i;
            }
        }
    }
    return bestIdx;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D428);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const void* a, const void* b);

struct sEquipSlot_D428 {
    int state;
    char name[0x100];
    int value;
    char pad108[0x18];
};
struct sEquipRow_D428 {
    sEquipSlot_D428 slots[0x100];
};
struct sEquipTable_D428 {
    sEquipRow_D428 rows[1];
};

extern "C" int func_0019D428(sEquipTable_D428* self, int bank, const char* name)
{
    for (int i = 0; i < 256; i++) {
        sEquipSlot_D428* s = &self->rows[bank].slots[i];
        if (s->name[0] != 0 && func_004165A8(self->rows[bank].slots[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D4B8);
#ifdef SKIP_ASM
extern "C" int ASYNCFILE_release(int handle, int a1, void* status);
void cMemMan_free(void* ptr);
struct sEquipSlot_D4B8 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int f114;
    int size;       // 0x118
    int f11C;
};
struct sEquipRow_D4B8 {
    sEquipSlot_D4B8 slots[0x100];
};
struct sEquipTable_D4B8 {
    sEquipRow_D4B8 rows[1];
};

extern "C" void func_0019D4B8(sEquipTable_D4B8* self, int bank, int i)
{
    int status;
    sEquipSlot_D4B8* s = &self->rows[bank].slots[i];
    if (s->state == 2) {
        if (s->pending != 0) {
            ASYNCFILE_release(s->handle, 0, &status);
        }
    }
    *(int*)((char*)self + 0xB4000) -= s->size;
    if (s->data != 0) {
        cMemMan_free(s->data);
    }
    s->data = 0;
    s->size = 0;
    s->state = 0;
    s->name[0] = 0;
    s->handle = 0;
    s->pending = 0;
    s->f114 = 0;
    s->f110 = -1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D578);
#ifdef SKIP_ASM
struct sEquipTable_D4B8;
struct sEquipTable_DC20;
extern "C" void func_0019D4B8(sEquipTable_D4B8* self, int bank, int i);

struct sSlotK19D578 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int timer;      // 0x114
    int size;       // 0x118
    unsigned int stamp; // 0x11C
};
struct sBankK19D578 {
    sSlotK19D578 e[256];
};
struct sTableK19D578 {
    sBankK19D578 banks[10];      // 0x0
    int used;                    // 0xB4000
};

extern "C" void func_0019D578(sEquipTable_DC20* p, int bank, int size)
{
    sTableK19D578* self = (sTableK19D578*)p;
    if (self->used + size <= 9999999)
        return;
    int b;
    int j;
    for (b = 0; b < 10; b++) {
        if (b == bank)
            continue;
        for (j = 0; j < 256; j++) {
            sSlotK19D578* s = &self->banks[b].e[j];
            if (s->data != 0 && s->timer == 0 && s->state == 0) {
                func_0019D4B8((sEquipTable_D4B8*)self, b, j);
                if (self->used + size <= 9999999)
                    return;
            }
        }
    }
    do {
        int best = -1;
        unsigned int stamp = 0;
        for (int k = 0; k < 256; k++) {
            sSlotK19D578* s = &self->banks[bank].e[k];
            if (s->data != 0 && s->state == 0 && s->timer == 0) {
                if (best < 0 || s->stamp < stamp) {
                    stamp = s->stamp;
                    best = k;
                }
            }
        }
        if (best < 0)
            return;
        func_0019D4B8((sEquipTable_D4B8*)self, bank, best);
    } while (self->used + size > 9999999);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D738);
#ifdef SKIP_ASM
struct sEquipTable_D4B8;
struct sEquipTable_DC20;
extern "C" void func_0019D4B8(sEquipTable_D4B8* self, int bank, int i);

struct sSlotK19D738 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int timer;      // 0x114
    int size;       // 0x118
    unsigned int stamp; // 0x11C
};
struct sBankK19D738 {
    sSlotK19D738 e[256];
};
struct sTableK19D738 {
    sBankK19D738 banks[10];      // 0x0
};

extern "C" void func_0019D738(sEquipTable_DC20* p, int bank, int size)
{
    sTableK19D738* self = (sTableK19D738*)p;
    int b;
    int j;
    for (b = 0; b < 10; b++) {
        if (b == bank)
            continue;
        for (j = 0; j < 256; j++) {
            sSlotK19D738* s = &self->banks[b].e[j];
            if (s->data != 0 && s->timer == 0 && s->state == 0) {
                size -= s->size;
                func_0019D4B8((sEquipTable_D4B8*)self, b, j);
                if (size <= 0)
                    return;
            }
        }
    }
    do {
        int best = -1;
        unsigned int stamp = 0;
        for (int k = 0; k < 256; k++) {
            sSlotK19D738* s = &self->banks[bank].e[k];
            if (s->data != 0 && s->state == 0 && s->timer == 0) {
                if (best < 0 || s->stamp < stamp) {
                    stamp = s->stamp;
                    best = k;
                }
            }
        }
        if (best < 0)
            return;
        size -= self->banks[bank].e[best].size;
        func_0019D4B8((sEquipTable_D4B8*)self, bank, best);
    } while (size > 0);
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019D8B8);
#ifdef SKIP_ASM
struct sEquipTable_DC20;
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern "C" int func_00317F60(const char* name);
extern "C" int func_003DF748(const char* name, void* data, int size);
extern "C" int func_003E1BB8(const char* name, void* data, int size);
extern "C" void func_0019D578(sEquipTable_DC20* self, int bank, int size);
extern "C" void func_0019D738(sEquipTable_DC20* self, int bank, int size);
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern char D_004609F0[];
extern char D_00538B00[];

struct sSlotK19D8B8 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int timer;      // 0x114
    int size;       // 0x118
    unsigned int stamp; // 0x11C
};

extern "C" void func_0019D8B8(sEquipTable_DC20* self, int bank, int i)
{
    sSlotK19D8B8* s = &((sSlotK19D8B8*)((char*)self + bank * 0x12000))[i];
    int size = func_00317F60(s->name);
    func_0019D578(self, bank, size);
    s->data = operator_new__FUi(size, D_004609F0, 0x60000000, 0);
    while (s->data == 0) {
        MUTEX_lock(D_00538B00);
        MUTEX_unlock(D_00538B00);
        func_0019D738(self, bank, size);
        s->data = operator_new__FUi(size, D_004609F0, 0x60000000, 0);
    }
    *(int*)((char*)self + 0xB4000) += size;
    if (s->pending != 0) {
        s->size = size;
        s->state = 2;
        s->handle = func_003DF748(s->name, s->data, size);
        *(int*)((char*)self + 0xB4004) += 1;
    } else {
        s->size = size;
        func_003E1BB8(s->name, s->data, size);
        s->state = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019DA10);
#ifdef SKIP_ASM
struct sEquipTable_D4B8;
struct sEquipTable_DC20;
struct sEquipTable_D428;
extern "C" void func_0019D4B8(sEquipTable_D4B8* self, int bank, int i);
extern "C" void func_0019D8B8(sEquipTable_DC20* self, int bank, int i);
extern "C" int func_0019D3B0(void* self, int bank);
extern "C" int func_0019D428(sEquipTable_D428* self, int bank, const char* name);
extern "C" int ASYNCFILE_release(int handle, int a1, void* status);
extern "C" char* strcpy(char* dst, const char* src);

struct sSlotK19DA10 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int timer;      // 0x114
    int size;       // 0x118
    unsigned int stamp; // 0x11C
};
struct sBankK19DA10 {
    sSlotK19DA10 e[256];
};
struct sTableK19DA10 {
    sBankK19DA10 banks[10];      // 0x0
    int used;                    // 0xB4000
    int nPending;                // 0xB4004
    int counts[10];              // 0xB4008
};

extern "C" int func_0019DA10(void* p, int bank, void* namep, int a3, int a4, int a5)
{
    sTableK19DA10* self = (sTableK19DA10*)p;
    const char* name = (const char*)namep;
    int i = func_0019D428((sEquipTable_D428*)self, bank, name);
    if (i >= 0) {
        sSlotK19DA10* s = &self->banks[bank].e[i];
        if (a5)
            s->stamp = 0;
        else
            s->stamp = self->counts[bank]++;
        if (a4) {
            if (s->state == 0)
                s->state = 1;
        } else {
            s->pending = 0;
            if (s->state == 2) {
                int status;
                ASYNCFILE_release(s->handle, 0, &status);
            } else if (s->state == 3) {
                func_0019D8B8((sEquipTable_DC20*)self, bank, i);
            }
            s->state = 1;
            s->handle = -1;
        }
        s->timer++;
    } else {
    i = func_0019D3B0(self, bank);
    sSlotK19DA10* s = &self->banks[bank].e[i];
    func_0019D4B8((sEquipTable_D4B8*)self, bank, i);
    if (a5)
        s->stamp = 0;
    else
        s->stamp = self->counts[bank]++;
    strcpy(s->name, name);
    s->timer++;
    s->f110 = a3;
    s->pending = a4;
    if (a5 == 0 && (a4 == 0 || self->nPending <= 0))
        func_0019D8B8((sEquipTable_DC20*)self, bank, i);
    else
        s->state = 3;
    }
    return i;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatecharequipdetail", func_0019DC20);
#ifdef SKIP_ASM
extern "C" int ASYNCFILE_release(int handle, int a1, void* status);
extern "C" int func_003DF980(int handle);
struct sEquipSlot_DC20 {
    int state;
    char name[0x100];
    void* data;     // 0x104
    int handle;     // 0x108
    int pending;    // 0x10C
    int f110;
    int timer;      // 0x114
    int size;       // 0x118
    int f11C;
};
struct sEquipRow_DC20 {
    sEquipSlot_DC20 slots[0x100];
};
struct sEquipTable_DC20 {
    sEquipRow_DC20 rows[1];
};
extern "C" void func_0019D000(sEquipTable_DC20* self, int bank, sEquipSlot_DC20* slot);
struct sEquipTable_D4B8;
extern "C" void func_0019D4B8(sEquipTable_D4B8* self, int bank, int i);

extern "C" void func_0019DC20(sEquipTable_DC20* self, int bank, int i)
{
    int status;
    sEquipSlot_DC20* s = &self->rows[bank].slots[i];
    if (--s->timer > 0) {
        return;
    }
    if (s->state == 2) {
        if (func_003DF980(s->handle) != 1) {
            return;
        }
        ASYNCFILE_release(s->handle, 0, &status);
        func_0019D000(self, bank, s);
        s->pending = 0;
        s->state = 0;
        *(int*)((char*)self + 0xB4004) -= 1;
    }
    if (s->data == 0) {
        func_0019D4B8((sEquipTable_D4B8*)self, bank, i);
    } else {
        s->state = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019DD10);
#ifdef SKIP_ASM
extern void* D_004A196C;
extern "C" int func_0041AA88(const char* a, const char* b);

struct sSlotK19DD10 {
    int state;
    char name[0x10C];
    int type;           // 0x110
    int f114;
    int f118;
    int f11C;           // 0x11C
};
struct sRowK19DD10 {
    sSlotK19DD10 slots[0x100];
};

extern "C" int func_0019DD10(const int* a, const int* b)
{
    int ka = *a;
    sRowK19DD10* row = (sRowK19DD10*)D_004A196C + (ka >> 16);
    sSlotK19DD10* sa = &row->slots[ka & 0xFFFF];
    sSlotK19DD10* sb = &row->slots[*b & 0xFFFF];
    if (sa->state == 3 && sa->type == 8 && sa->f11C == 0) {
        if (sb->state == 3 && sb->type == 8 && sb->f11C == 0)
            return func_0041AA88(sa->name, sb->name);
        return -1;
    }
    if (sb->state == 3 && sb->type == 8 && sb->f11C == 0) {
        if (sa->state == 3 && sa->type == 8 && sa->f11C == 0)
            return func_0041AA88(sa->name, sb->name);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019DE18);
#ifdef SKIP_ASM
extern void* D_004A196C;
extern "C" int func_0041AA88(const char* a, const char* b);

struct sSlotK19DE18 {
    int state;
    char name[0x10C];
    int type;           // 0x110
    int f114;
    int f118;
    int f11C;           // 0x11C
};
struct sRowK19DE18 {
    sSlotK19DE18 slots[0x100];
};

extern "C" int func_0019DE18(const int* a, const int* b)
{
    int ka = *a;
    sRowK19DE18* row = (sRowK19DE18*)D_004A196C + (ka >> 16);
    sSlotK19DE18* sa = &row->slots[ka & 0xFFFF];
    sSlotK19DE18* sb = &row->slots[*b & 0xFFFF];
    if (sa->state == 3 && sa->type == 0xB && sa->f11C == 0) {
        if (sb->state == 3 && sb->type == 0xB && sb->f11C == 0)
            return func_0041AA88(sa->name, sb->name);
        return -1;
    }
    if (sb->state == 3 && sb->type == 0xB && sb->f11C == 0) {
        if (sa->state == 3 && sa->type == 0xB && sa->f11C == 0)
            return func_0041AA88(sa->name, sb->name);
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("fe/festatecharequipdetail", func_0019DF20);

INCLUDE_ASM("fe/festatecharequipdetail", func_0019E070);

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E1C0);
#ifdef SKIP_ASM
struct sSlot120_E1C0 {
    unsigned int state;
    char pad04[0x11C];
};
struct sRow12000_E1C0 {
    sSlot120_E1C0 slots[0x100];
};
struct sTable_E1C0 {
    sRow12000_E1C0 rows[1];
};

extern "C" int func_0019E1C0(sTable_E1C0* self, int a1)
{
    int i;
    for (i = 0; i < 0x100; i++) {
        if (self->rows[a1].slots[i].state >= 2) {
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E208);
#ifdef SKIP_ASM
struct sSlot120_E208 {
    int state;
    char pad04[0x11C];
};
struct sRow12000_E208 {
    sSlot120_E208 slots[0x100];
};
struct sTable_E208 {
    sRow12000_E208 rows[1];
};

extern "C" int func_0019E208(sTable_E208* self, int a1, int a2)
{
    return self->rows[a1].slots[a2].state == 2;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E238);
#ifdef SKIP_ASM
struct sEquipSlot120 {
    int state;
    char pad04[0x100];
    int value;
    char pad108[8];
    int f110;
    int f114;
    int f118;
    int f11C;
};
struct sEquipRow12000 {
    sEquipSlot120 slots[0x100];
};
struct sEquipTable {
    sEquipRow12000 rows[1];
};

extern "C" int func_0019E238(sEquipTable* self, int a1, int a2)
{
    return self->rows[a1].slots[a2].state == 1;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E268);
#ifdef SKIP_ASM
extern "C" void* func_0019E268(sEquipTable* self, int a1, int a2)
{
    if (self->rows[a1].slots[a2].state == -1) {
        return 0;
    }
    return (char*)&self->rows[a1].slots[a2] + 4;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E2B0);
#ifdef SKIP_ASM
extern "C" int func_0019E2B0(sEquipTable* self, int a1, int a2)
{
    if (self->rows[a1].slots[a2].state != 1) {
        return 0;
    }
    return self->rows[a1].slots[a2].value;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E2F0);
#ifdef SKIP_ASM
extern "C" int func_0019E2F0(sEquipTable* self, int a1, int a2)
{
    if (self->rows[a1].slots[a2].state != 1) {
        return 0;
    }
    return self->rows[a1].slots[a2].value;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E330);
#ifdef SKIP_ASM
extern "C" int func_0019E330(sEquipTable* self, int a1, int a2)
{
    int v = self->rows[a1].slots[a2].value;
    self->rows[a1].slots[a2].value = 0;
    *(int*)((char*)self + 0xB4000) -= self->rows[a1].slots[a2].f118;
    self->rows[a1].slots[a2].f118 = 0;
    return v;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E380);
#ifdef SKIP_ASM
extern "C" int func_0019E380(sEquipTable* self, int a1, int a2)
{
    return self->rows[a1].slots[a2].f110;
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E3A8);
#ifdef SKIP_ASM
extern "C" int func_0019E3A8(sEquipTable* self, int a1, int a2)
{
    return self->rows[a1].slots[a2].f114;
}
#endif
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E3D0);

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E498);
#ifdef SKIP_ASM
struct sVEntry0019E498 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sSlot0019E498 {
    int id;
    char flag;
    char pad[7];
};

extern void* D_004A289C;
extern "C" void func_0019EBA0(void* self);
void operator_delete(int* p);

extern "C" void func_0019E498(void* self, int flags)
{
    sSlot0019E498* s = (sSlot0019E498*)((char*)self + 0x1C);
    func_0019EBA0(self);
    int i;
    int none = -1;
    for (i = 0xFF; i >= 0; i--, s++) {
        if (s->id >= 0) {
            char* g = (char*)D_004A289C;
            sVEntry0019E498* vt = *(sVEntry0019E498**)(g + 0x10D8);
            vt[50].fn(g + vt[50].delta, s->id);
        }
        s->id = none;
        s->flag = 0;
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E538);
#ifdef SKIP_ASM
extern "C" void func_0019E538(void* self, int a1)
{
    if (a1 != 0) {
        if (*(int*)((char*)self + 0xcc0) != 0 && *(int*)((char*)self + 0xcb8) != 0 &&
            *(int*)((char*)self + 0xcb4) != 0 && *(int*)((char*)self + 0xcd4) < 0) {
            *(int*)((char*)self + 0xcc8) = 1;
        } else {
            *(int*)((char*)self + 0xcc4) = 1;
        }
    } else {
        *(int*)((char*)self + 0xcc8) = 0;
        *(int*)((char*)self + 0xcc4) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecharequipdetail", func_0019E588);
#ifdef SKIP_ASM
extern void* D_004A289C;

struct sVE_E588 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sRider_E588 {
    unsigned int item;  // 0x0
    char pad4[0xC];
    int f10;            // 0x10
    char pad14[0xC24 - 0x14];
    int reqItem;        // 0xC24
    int reqFlag;        // 0xC28
    char padC2C[0xCB4 - 0xC2C];
    int fCB4;           // 0xCB4
    int fCB8;           // 0xCB8
    char padCBC[0xCC4 - 0xCBC];
    int fCC4;           // 0xCC4
    int fCC8;           // 0xCC8
    char padCCC[0xCD4 - 0xCCC];
    int timer;          // 0xCD4
};

// Item request for a rider slot: applies it straight away when allowed, otherwise arms a delayed retry.
extern "C" void func_0019E588(sRider_E588* self, unsigned int item, int flag)
{
    self->reqItem = item;
    self->reqFlag = flag;
    // The three-way flag test (equivalent to f10 != 0 || flag == 0) is kept as written for codegen.
    if (self->item == item
        && ((self->f10 != 0 && flag != 0) || (self->f10 == 0 && flag == 0) || !(self->f10 == 0 || flag != 0))) {
        int ok = 0;
        if (self->item < 10 && self->fCB8 != 0) {
            ok = self->fCB4 != 0;
        }
        if (ok) {
            self->timer = -1;
            int* p = &self->fCC8;
            int v = 0;
            if (*p != 0 || self->fCC4 != 0) {
                v = 1;
            }
            *p = v;
            self->fCC4 = 0;
        }
        return;
    }
    if (self->timer < 0) {
        char* w = (char*)D_004A289C;
        sVE_E588* vt = *(sVE_E588**)(w + 0x10D8);
        self->timer = vt[114].fn(w + vt[114].delta) + 4;
        self->fCC4 = self->fCC8;
        self->fCC8 = 0;
    }
}
#endif

