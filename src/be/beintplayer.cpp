#include "common.h"

extern int D_005305B0[];

struct sPlayerCharEntry {
    char pad_0x00[0xc];
    int field_0xc; // 0xc
    char pad_0x10[1];
    signed char mCharID; // 0x11
    signed char field_0x12; // 0x12
    char pad_0x13[0x1C - 0x12 - 1];
};
extern sPlayerCharEntry D_00534FE0[];

extern "C" void func_00145B20(void* self);
extern "C" void cBENewPlayerInterface_defaultCtrl(void* self);
extern void* D_0045AE28[16];

struct cBENewPlayerInterfaceCtor {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_cBENewPlayerInterface__FP25cBENewPlayerInterfaceCtor);
#ifdef SKIP_ASM
cBENewPlayerInterfaceCtor* cBENewPlayerInterface_cBENewPlayerInterface(cBENewPlayerInterfaceCtor* self)
{
    self->field_0x8 = 0;
    self->vtable = D_0045AE28;
    func_00145B20(self);
    cBENewPlayerInterface_defaultCtrl(self);
    return self;
}
#endif

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A1D8[];
extern void* D_004A11C0;

//99.24%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_getThis__Fv);
#ifdef SKIP_ASM
void* cBENewPlayerInterface_getThis()
{
    if (D_004A11C0 == 0) {
        void* mem = cMemMan_alloc(0x10, D_0045A1D8, 0, 0);
        D_004A11C0 = cBENewPlayerInterface_cBENewPlayerInterface((cBENewPlayerInterfaceCtor*)mem);
    }
    return D_004A11C0;
}
#endif

INCLUDE_ASM("be/beintplayer", func_001459B8);

//100%
INCLUDE_ASM("be/beintplayer", func_00145A98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);

struct sCharEntryBits_00145A98 {
    char name[0xC];          // 0x00
    int field_0xc;           // 0x0C
    unsigned int flag0 : 1;  // 0x10
    unsigned int flag1 : 1;
    unsigned int rest : 30;
    int pad_0x14[2];
};

// Bitfield views of the two 0x1C-byte character tables.
extern sCharEntryBits_00145A98 D_00534FE0_bits[] __asm__("D_00534FE0");
extern sCharEntryBits_00145A98 D_00535B20_bits[] __asm__("D_00535B20");

extern "C" void func_00145A98(void)
{
    for (int i = 0; i < 6; i++)
    {
        D_00535B20_bits[i].flag1 = D_00534FE0_bits[i].flag1;
        strncpy(D_00535B20_bits[i].name, D_00534FE0_bits[i].name, 0xC);
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00145B20);
#ifdef SKIP_ASM
struct sPlayerTable_00145B20
{
    sPlayerCharEntry entries[6];
};

extern sPlayerTable_00145B20 D_00535B20;

extern "C" void func_00145B20(void* self)
{
    *(sPlayerTable_00145B20*)D_00534FE0 = D_00535B20;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_defaultCtrl);
#ifdef SKIP_ASM
struct sVEntry00145BD8 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sCtrlEntry00145BD8 {
    char pad_0x00[0x10];
    unsigned int flag0 : 1;
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int rest : 29;
    char pad_0x14[0x8];
};

extern "C" void cBENewPlayerInterface_defaultCtrl(void* self)
{
    int i;
    sCtrlEntry00145BD8* e = (sCtrlEntry00145BD8*)&D_00535B20;
    for (i = 0; i < 6; i++)
    {
        ((char*)&e[i])[0x13] = 0;
        e[i].flag1 = 1;
    }
    sVEntry00145BD8* vt = *(sVEntry00145BD8**)((char*)self + 0xC);
    vt[2].fn((char*)self + vt[2].delta);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00145C38);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" int func_00145C38(void* self, int index)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    int off = c * 0xF88 + profile * 0x9B50;
    char* p = (char*)D_004A6CA8 + off;
    return *(int*)p;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00145CB0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" void func_00145CB0(void* self, int index, int value)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    int off = c * 0xF88 + profile * 0x9B50;
    char* p = (char*)D_004A6CA8 + off;
    *(int*)p = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00145D38);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" int func_00145D38(void* self, int index, int bit)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    int off = profile * 0x9B50 + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    int mask = 1 << bit;
    return (*(int*)(p + 0xACC) & mask) == 0;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00145DD0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];
extern "C" void func_00152430(void* self, int bit, int on);

struct sProfileSlot_00145DD0 {
    char data[0xF88];
};

extern "C" void func_00145DD0(void* self, bool flag, int index, int bit)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    func_00152430(&((sProfileSlot_00145DD0 (*)[10])D_004A6CA8)[profile][c], bit, !flag);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00145E68);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];
extern "C" int func_001523E8(void* self, int kind);

struct sProfileSlot_00145E68 {
    char data[0xF88];
};

extern "C" int func_00145E68(void* self, int index, int kind)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    return func_001523E8(&((sProfileSlot_00145E68 (*)[10])D_004A6CA8)[profile][c], kind);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00145EF0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];
void* cBECharProfileDB_getScoreStats(void* self, int a, int b);

struct sProfileSlot_00145EF0 {
    char data[0xF88];
};

extern "C" int func_00145EF0(void* self, int index, int a, int b)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    signed char* stats = (signed char*)cBECharProfileDB_getScoreStats(&((sProfileSlot_00145EF0 (*)[10])D_004A6CA8)[profile][c], a, b);
    return *stats != 0;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_isPeakLocked);
#ifdef SKIP_ASM
extern int D_004A6CA8[];

// PORT: 64-bit ulong flag word (bit 12 = peak 1 locked, bit 13 = peak 2).
extern "C" int cBENewPlayerInterface_isPeakLocked(void* self, int a, int b, int peak)
{
    if (peak != 0)
    {
        if (peak == 1)
        {
            int bOff = b * 0xF88;
            int aOff = a * 0x9B50;
            int off = bOff + aOff;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(ulong*)(p + 0x278) >> 12) & 1;
        }
        else
        {
            int bOff = b * 0xF88;
            int aOff = a * 0x9B50;
            int off = bOff + aOff;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(ulong*)(p + 0x278) >> 13) & 1;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_isPeakLocked1);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern "C" int cBENewPlayerInterface_isPeakLocked1(void* self, int rider, int peak)
{
    int profile = cBELibrary_getProfileIndex(rider);
    return cBENewPlayerInterface_isPeakLocked(self, profile, cBELibrary_getCharacterID(rider), peak);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00146150);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

// PORT: 64-bit `long` flag word (8 bytes on EE); use int64_t off-PS2.
extern "C" int func_00146150(void* self, int index, int kind, int flag)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    signed char c = D_00534FE0[id].mCharID;
    if (flag) {
        if (kind == 0) {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 3) & 1;
        } else if (kind == 1) {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 4) & 1;
        } else if (kind == 2) {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 5) & 1;
        }
    } else {
        if (kind == 0) {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 0) & 1;
        } else if (kind == 1) {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 1) & 1;
        } else if (kind == 2) {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 2) & 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00146320);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

// PORT: 64-bit `long` bitfield (8 bytes on EE); use uint64_t off-PS2.
struct sProfBits6320 {
    unsigned long b0 : 1;
    unsigned long b1 : 1;
    unsigned long b2 : 1;
    unsigned long b3 : 1;
    unsigned long b4 : 1;
    unsigned long b5 : 1;
};

extern "C" void func_00146320(void* self, int index, int kind, int flag, int value)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    signed char c = D_00534FE0[id].mCharID;
    if (flag) {
        if (kind == 0) {
            char* p = (char*)D_004A6CA8 + (c * 0xF88 + profile * 0x9B50);
            ((sProfBits6320*)(p + 0x278))->b3 = value;
        } else if (kind == 1) {
            char* p = (char*)D_004A6CA8 + (c * 0xF88 + profile * 0x9B50);
            ((sProfBits6320*)(p + 0x278))->b4 = value;
        } else if (kind == 2) {
            char* p = (char*)D_004A6CA8 + (c * 0xF88 + profile * 0x9B50);
            ((sProfBits6320*)(p + 0x278))->b5 = value;
        }
    } else {
        if (kind == 0) {
            char* p = (char*)D_004A6CA8 + (c * 0xF88 + profile * 0x9B50);
            ((sProfBits6320*)(p + 0x278))->b0 = value;
        } else if (kind == 1) {
            char* p = (char*)D_004A6CA8 + (c * 0xF88 + profile * 0x9B50);
            ((sProfBits6320*)(p + 0x278))->b1 = value;
        } else if (kind == 2) {
            char* p = (char*)D_004A6CA8 + (c * 0xF88 + profile * 0x9B50);
            ((sProfBits6320*)(p + 0x278))->b2 = value;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001464D0);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
extern int D_004A6CA8[];

// PORT: 64-bit `long` flag word (8 bytes on EE); use int64_t off-PS2.
extern "C" int func_001464D0(void* self, int index, int c, int kind, int flag)
{
    int profile = cBELibrary_getProfileIndex(index);
    if (flag) {
        switch (kind) {
        case 0:
            {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 6) & 1;
        }
        case 1:
            {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 7) & 1;
        }
        case 2:
            {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 8) & 1;
        }
        }
    } else {
        switch (kind) {
        case 0:
            {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 9) & 1;
        }
        case 1:
            {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 10) & 1;
        }
        case 2:
            {
            int off = c * 0xF88 + profile * 0x9B50;
            char* p = (char*)D_004A6CA8 + off;
            return (int)(*(long*)(p + 0x278) >> 11) & 1;
        }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00146A70);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
extern int D_004A6CA8[];

// Returns one of the character's unlock flags (kinds 6-11, bits 14-19 of the 64-bit flag word).
// PORT: 64-bit `long` flag word (8 bytes on EE); use int64_t off-PS2.
extern "C" int func_00146A70(void* self, int index, int c, int kind)
{
    int profile = cBELibrary_getProfileIndex(index);
    switch (kind) {
    case 6: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return (int)(*(long*)(p + 0x278) >> 14) & 1;
    }
    case 7: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return (int)(*(long*)(p + 0x278) >> 15) & 1;
    }
    case 8: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return (int)(*(long*)(p + 0x278) >> 16) & 1;
    }
    case 9: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return (int)(*(long*)(p + 0x278) >> 17) & 1;
    }
    case 10: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return (int)(*(long*)(p + 0x278) >> 18) & 1;
    }
    case 11: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return (int)(*(long*)(p + 0x278) >> 19) & 1;
    }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00146D98);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" int func_00146D98(void* self, int index)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    int off = c * 0xF88 + profile * 0x9B50;
    char* p = (char*)D_004A6CA8 + off;
    return *(int*)(p + 0x27C);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00146E10);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" void func_00146E10(void* self, int index, int value)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    int off = c * 0xF88 + profile * 0x9B50;
    char* p = (char*)D_004A6CA8 + off;
    *(int*)(p + 0x27C) = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00146E98);
#ifdef SKIP_ASM
int cBENewPlayerInterface_getPlayerID(int index);

struct sPlayerSlot_00146E98
{
    int state;          // 0x0 (0xC in sPlayerCharEntry)
    char pad_0x04[0x18];
};

extern sPlayerSlot_00146E98 D_00534FEC[];

extern "C" int func_00146E98(void* self, int second)
{
    int n = 0;
    for (int i = 0; i < 6; i++)
    {
        int id = cBENewPlayerInterface_getPlayerID(i);
        if (D_00534FEC[id].state >= 0)
        {
            if (second == 0)
                return i;
            if (n == 1)
                return i;
            n++;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00146F88);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int sprintf(char* buf, const char* fmt, ...);
int cBENewPlayerInterface_getPlayerID(int index);
extern char* D_004A28A8;
extern char D_00534B30[];
extern unsigned int D_00535610[];
extern char D_0045A228[];
extern char D_0045A238[];
extern char D_0045A248[];
extern char D_0045A258[];

// Returns the display name for player idx (network names in a net game, else a default "Player N").
extern "C" char* func_00146F88(void* self, int idx)
{
    cBE_getInterface_Fv(*(void**)(D_004A28A8 + 0x78), 7);
    char* net = D_00534B30;
    if (*(int*)net != 0 && idx < 2) {
        if (*(int*)(net + 0x8) != 0) {
            if (idx == 0)
                return net + 0x488;
            return net + 0x498;
        }
        if (idx == 0)
            return net + 0x498;
        return net + 0x488;
    }
    if (D_00534FE0[cBENewPlayerInterface_getPlayerID(idx)].pad_0x00[0] == 0) {
        cBE_getInterface_Fv(cBE_getBE(), 4);
        switch ((int)((D_00535610[0] >> 22) & 7)) {
        case 0:
            sprintf(D_00534FE0[cBENewPlayerInterface_getPlayerID(idx)].pad_0x00, D_0045A228, idx + 1);
            break;
        case 1:
            sprintf(D_00534FE0[cBENewPlayerInterface_getPlayerID(idx)].pad_0x00, D_0045A238, idx + 1);
            break;
        case 2:
            sprintf(D_00534FE0[cBENewPlayerInterface_getPlayerID(idx)].pad_0x00, D_0045A248, idx + 1);
            break;
        case 3:
            sprintf(D_00534FE0[cBENewPlayerInterface_getPlayerID(idx)].pad_0x00, D_0045A258, idx + 1);
            break;
        }
    }
    return D_00534FE0[cBENewPlayerInterface_getPlayerID(idx)].pad_0x00;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147138);
#ifdef SKIP_ASM
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);

extern "C" void func_00147138(void* self, int a1, const char* name)
{
    strncpy(D_00534FE0[a1].pad_0x00, name, 0xC);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147170);
#ifdef SKIP_ASM
extern "C" unsigned int strlen(const char* s);
int GetHashValue32(char* str);
extern "C" void func_002C26D0(unsigned short* dst, unsigned short* fmt, int n);
extern "C" char* func_002C2580(char* dst, unsigned short* src);
extern char D_0045A268[];

struct sVtEntry_00147170 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern char* D_004A28A8;

extern "C" char* func_00147170(void* self, int idx)
{
    char* name = (char*)&D_00534FE0[idx];
    if (strlen(name) == 0)
    {
        unsigned short buf[0x68];
        char* db = *(char**)(D_004A28A8 + 0x8C);
        sVtEntry_00147170* vt = *(sVtEntry_00147170**)(db + 4);
        func_002C26D0(buf, vt[4].fn(db + vt[4].delta, GetHashValue32(D_0045A268)), idx + 1);
        func_002C2580(name, buf);
    }
    return name;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_setRiderCtrlID);
#ifdef SKIP_ASM
int cBENewPlayerInterface_getPlayerID(int index);

struct sPlayerCharFlags_00147220 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int rest : 29;
};

extern "C" void cBENewPlayerInterface_setRiderCtrlID(void* self, int index, int ctrl)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    D_00534FE0[id].field_0xc = ctrl;
    if (ctrl >= 0) {
        char* p = (char*)&D_00534FE0[0] + id * 0x1c;
        sPlayerCharFlags_00147220* f = (sPlayerCharFlags_00147220*)(p + 0x10);
        f->bit0 = id;
        f->bit2 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147290);
#ifdef SKIP_ASM
int cBENewPlayerInterface_getPlayerID(int index);

extern "C" int func_00147290(void* self, int index)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    return D_00534FE0[id].field_0xc;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001472C8);
#ifdef SKIP_ASM
struct sPlayerCharFlags_001472C8 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int rest : 29;
};

extern "C" void func_001472C8(void* self, int a1, int a2)
{
    D_00534FE0[a1].field_0xc = a2;
    if (a2 >= 0) {
        char* p = (char*)&D_00534FE0[0] + a1 * 0x1c;
        sPlayerCharFlags_001472C8* f = (sPlayerCharFlags_001472C8*)(p + 0x10);
        f->bit0 = a1;
        f->bit2 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147318);
#ifdef SKIP_ASM
extern "C" int func_00147318(void* self, int a1)
{
    return D_00534FE0[a1].field_0xc;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_setRiderCharID);
#ifdef SKIP_ASM
static inline int func_00147338_isLocked(sPlayerCharEntry* e)
{
    return (*(unsigned int*)((char*)e + 0x10) >> 2) & 1;
}

extern "C" void cBENewPlayerInterface_setRiderCharID(void* self, int index, int charID)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    sPlayerCharEntry* e = &D_00534FE0[id];
    if (func_00147338_isLocked(e) == 1)
    {
        e->mCharID = D_00534FE0[0].mCharID;
    }
    else
    {
        e->mCharID = charID;
    }
}
#endif

int cBENewPlayerInterface_getPlayerID(int index);

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_getRiderCharID__FPvi);
#ifdef SKIP_ASM
signed char cBENewPlayerInterface_getRiderCharID(void* self, int riderIndex)
{
    int playerID = cBENewPlayerInterface_getPlayerID(riderIndex);
    sPlayerCharEntry* entry = &D_00534FE0[playerID];
    return entry->mCharID;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001473D0);
#ifdef SKIP_ASM
extern "C" void func_001473D0(void* self, int index, int value)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    D_00534FE0[id].field_0x12 = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147410);
#ifdef SKIP_ASM
extern "C" signed char func_00147410(void* self, int index)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    return D_00534FE0[id].field_0x12;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147448);
#ifdef SKIP_ASM
struct sPlayerCharFlags_00147448 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int rest : 29;
};

static inline int func_00147448_getBit2(char* p)
{
    return ((sPlayerCharFlags_00147448*)(p + 0x10))->bit2;
}

extern "C" void func_00147448(void* self, int a1, int charID)
{
    char* p = (char*)&D_00534FE0[0] + a1 * 0x1c;
    if (func_00147448_getBit2(p) == 1) {
        *(signed char*)(p + 0x11) = D_00534FE0[0].mCharID;
    } else {
        *(signed char*)(p + 0x11) = charID;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_getPlayerCharID__FPvi);
#ifdef SKIP_ASM
signed char cBENewPlayerInterface_getPlayerCharID(void* self, int index)
{
    index *= sizeof(sPlayerCharEntry);
    return ((sPlayerCharEntry*)((char*)D_00534FE0 + index))->mCharID;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001474A8);
#ifdef SKIP_ASM
extern "C" void func_001474A8(void* self, int a1, int a2)
{
    char* p = (char*)&D_00534FE0[0] + a1 * 0x1c;
    *(char*)(p + 0x12) = a2;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001474C8);
#ifdef SKIP_ASM
extern "C" signed char func_001474C8(void* self, int a1)
{
    char* p = (char*)&D_00534FE0[0] + a1 * 0x1c;
    return *(signed char*)(p + 0x12);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001474E8);
#ifdef SKIP_ASM
struct sPlayerCharFlags_0x10 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int rest : 28;
};

extern "C" int func_001474E8(void* self, int index)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    char* p = (char*)&D_00534FE0[0] + id * 0x1c;
    return ((sPlayerCharFlags_0x10*)(p + 0x10))->bit1;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147528);
#ifdef SKIP_ASM
struct sPlayerCharFlags_00147528 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int rest : 28;
};

extern "C" void func_00147528(void* self, int index, int value)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    sPlayerCharEntry* e = &D_00534FE0[id];
    ((sPlayerCharFlags_00147528*)((char*)e + 0x10))->bit1 = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147580);
#ifdef SKIP_ASM
extern "C" int func_00147580(void* self, int index)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    char* p = (char*)&D_00534FE0[0] + id * 0x1c;
    return ((sPlayerCharFlags_0x10*)(p + 0x10))->bit3;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001475C0);
#ifdef SKIP_ASM
struct sPlayerCharFlags_001475C0 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int rest : 28;
};

extern "C" void func_001475C0(void* self, int index, int value)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    sPlayerCharEntry* e = &D_00534FE0[id];
    ((sPlayerCharFlags_001475C0*)((char*)e + 0x10))->bit3 = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147618);
#ifdef SKIP_ASM
extern "C" signed char func_00147618(void* self, int index)
{
    return D_00534FE0[cBENewPlayerInterface_getPlayerID(index)].pad_0x13[0];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147658);
#ifdef SKIP_ASM
extern "C" void func_00147658(void* self, int index, int value)
{
    int id = cBENewPlayerInterface_getPlayerID(index);
    D_00534FE0[id].pad_0x13[0] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_getPlayerID__Fi);
#ifdef SKIP_ASM
int cBENewPlayerInterface_getPlayerID(int index)
{
    return D_005305B0[index];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_isMissionMan__Fi);
#ifdef SKIP_ASM
struct sPlayerFlags_001477E8
{
    char pad_0x00[0x10];
    unsigned int flag0 : 1;       // 0x10 bit 0
    unsigned int flag1 : 1;       // 0x10 bit 1
    unsigned int missionMan : 1;  // 0x10 bit 2
    unsigned int rest : 29;
    char pad_0x14[0x1C - 0x14];
};

int cBENewPlayerInterface_isMissionMan(int index)
{
    int playerID = cBENewPlayerInterface_getPlayerID(index);
    return ((sPlayerFlags_001477E8*)D_00534FE0)[playerID].missionMan;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147828);
#ifdef SKIP_ASM
extern "C" void func_00147828(int index)
{
    D_00534FE0[cBENewPlayerInterface_getPlayerID(index)].mCharID = D_00534FE0[0].mCharID;
    sPlayerCharEntry* e = &D_00534FE0[cBENewPlayerInterface_getPlayerID(index)];
    ((sPlayerCharFlags_0x10*)((char*)e + 0x10))->bit2 = 1;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", cBENewPlayerInterface_resetFromMissionMan);
#ifdef SKIP_ASM
extern "C" void cBENewPlayerInterface_resetFromMissionMan(void* self, int index)
{
    D_00534FE0[cBENewPlayerInterface_getPlayerID(index)].mCharID = 0;
    sPlayerCharEntry* e = &D_00534FE0[cBENewPlayerInterface_getPlayerID(index)];
    ((sPlayerCharFlags_0x10*)((char*)e + 0x10))->bit2 = 0;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147908);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" void* func_00147908(void* self, int index)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    char* p = (char*)D_004A6CA8 + profile * 0x9B50 + c * 0xF88;
    return p + 0xE38;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147980);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" int func_00147980(void* self, int index, int bit)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    int off = profile * 0x9B50 + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    p = p + (bit / 32) * 4;
    int mask = 1 << bit;
    return (*(unsigned int*)(p + 0xF08) & mask) != 0;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147A30);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBENewPlayerInterface_getPlayerID(int index);
extern int D_004A6CA8[];

extern "C" void func_00147A30(void* self, int index, int bit, int on)
{
    int profile = cBELibrary_getProfileIndex(index);
    int id = cBENewPlayerInterface_getPlayerID(index);
    int c = D_00534FE0[id].mCharID;
    int off = profile * 0x9B50 + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    p += 0xF08;
    int w = bit / 32;
    int b = bit - w * 32;
    if (on)
        *(unsigned int*)(p + (w << 2)) |= 1 << b;
    else
        *(unsigned int*)(p + (w << 2)) &= ~(1 << b);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147CB8);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);

extern "C" short func_00147CB8(void* self, int which)
{
    int c = cBELibrary_getCharacterID(0);
    if (which != 0)
    {
        char* p = (char*)D_004A6CA8 + c * 0xF88;
        return *(short*)(p + 0x280);
    }
    else
    {
        char* p = (char*)D_004A6CA8 + c * 0xF88;
        return *(short*)(p + 0x284);
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147D20);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern int D_004A6CA8[];

struct sCharRec_147D20 {
    char pad0[0x280];
    short b0;       // 0x280
    short a0;       // 0x282
    short b1;       // 0x284
    short a1;       // 0x286
    char pad288[0xF88 - 0x288];
};

extern "C" void func_00147D20(void* self, int which)
{
    int profile = 0;
    int c = cBELibrary_getCharacterID(0);
    short a, b;
    if (which)
    {
        b = (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b0;
        a = (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a0;
    }
    else
    {
        b = (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b1;
        a = (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a1;
    }
    a++;
    if (a >= 2)
    {
        if (b < 2) b++;
        a = 0;
    }
    if (which)
    {
        (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b0 = b;
        (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a0 = a;
    }
    else
    {
        (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b1 = b;
        (*(sCharRec_147D20*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a1 = a;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147E18);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern int D_004A6CA8[];

struct sCharRec_147E18 {
    char pad0[0x280];
    short b0;       // 0x280
    short a0;       // 0x282
    short b1;       // 0x284
    short a1;       // 0x286
    char pad288[0xF88 - 0x288];
};

extern "C" void func_00147E18(void* self, int which)
{
    int profile = 0;
    int c = cBELibrary_getCharacterID(0);
    short a, b;
    if (which)
    {
        b = (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b0;
        a = (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a0;
    }
    else
    {
        b = (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b1;
        a = (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a1;
    }
    a--;
    if (a < -1)
    {
        if (b != 0) b--;
        a = 0;
    }
    if (which)
    {
        (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b0 = b;
        (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a0 = a;
    }
    else
    {
        (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).b1 = b;
        (*(sCharRec_147E18*)((char*)D_004A6CA8 + (profile * 0x9B50 + c * 0xF88))).a1 = a;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147F78);
#ifdef SKIP_ASM
struct sVTablePlayer_00147F78
{
    char pad_0x00[0x10];
    short delta;
    char pad_0x12[2];
    void (*fn)(void*);
};
struct cBEIface_00147F78
{
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A280[];
extern sVTablePlayer_00147F78 D_0045AD68;
extern void* D_004A11C4;

extern "C" void* func_00147F78(void)
{
    if (D_004A11C4 == 0) {
        cBEIface_00147F78* mem = (cBEIface_00147F78*)cMemMan_alloc(0x10, D_0045A280, 0, 0);
        D_004A11C4 = mem;
        sVTablePlayer_00147F78* vt = &D_0045AD68;
        short d = vt->delta;
        void (*fn)(void*) = vt->fn;
        mem->vtable = vt;
        mem->field_0x8 = 0;
        fn((char*)mem + d);
    }
    return D_004A11C4;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00147FD8);
#ifdef SKIP_ASM
struct sCtrl7_00147FD8
{
    signed char b[7];
};

struct sPlayerSlot_00147FD8
{
    sCtrl7_00147FD8 ctrl;
    char pad[0xF88 - 7];
};

struct sPlayerStatRow;
extern sPlayerStatRow D_00535538[];
extern sPlayerSlot_00147FD8 D_004A7887[];
extern sPlayerSlot_00147FD8 D_004B13D7[];
extern sPlayerSlot_00147FD8 D_004BAF27[];

extern "C" void func_00147FD8(void)
{
    for (int i = 0; i < 10; i++)
    {
        D_004A7887[i].ctrl = ((sCtrl7_00147FD8 (*)[10])D_00535538)[0][i];
        D_004B13D7[i].ctrl = ((sCtrl7_00147FD8 (*)[10])D_00535538)[1][i];
        D_004BAF27[i].ctrl = ((sCtrl7_00147FD8 (*)[10])D_00535538)[2][i];
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148098);
#ifdef SKIP_ASM
struct sPlayerStatRow;
extern sPlayerStatRow D_00535538[];
extern sPlayerSlot_00147FD8 D_004A7887[];
extern sPlayerSlot_00147FD8 D_004B13D7[];
extern sPlayerSlot_00147FD8 D_004BAF27[];

extern "C" void func_00148098(void)
{
    for (int i = 0; i < 10; i++)
    {
        ((sCtrl7_00147FD8 (*)[10])D_00535538)[0][i] = D_004A7887[i].ctrl;
        ((sCtrl7_00147FD8 (*)[10])D_00535538)[1][i] = D_004B13D7[i].ctrl;
        ((sCtrl7_00147FD8 (*)[10])D_00535538)[2][i] = D_004BAF27[i].ctrl;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148158);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern int D_004A6CA8[];

// Returns one of a character's seven stat levels for the given profile, or -1.
extern "C" int func_00148158(void* self, int profile, unsigned int stat)
{
    int c = cBELibrary_getCharacterID(profile);
    switch (stat) {
    case 0: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return *(signed char*)(p + 0xBDF);
    }
    case 1: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return *(signed char*)(p + 0xBE0);
    }
    case 2: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return *(signed char*)(p + 0xBE1);
    }
    case 3: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return *(signed char*)(p + 0xBE2);
    }
    case 4: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return *(signed char*)(p + 0xBE3);
    }
    case 5: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return *(signed char*)(p + 0xBE4);
    }
    case 6: {
        int off = c * 0xF88 + profile * 0x9B50;
        char* p = (char*)D_004A6CA8 + off;
        return *(signed char*)(p + 0xBE5);
    }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001483A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

// Same layout as the unit's sPlayerStatRowView_00148410 (defined later in the unit).
struct sPlayerStat7View_001483A0 {
    signed char v[7];
};
struct sPlayerStatRowView_001483A0 {
    sPlayerStat7View_001483A0 e[10];
};
extern sPlayerStatRowView_001483A0 D_00535538_view001483A0[] __asm__("D_00535538");

extern "C" void func_001483A0(void* self, int rider, int value)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00535538_view001483A0[a].e[c].v[0] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148410);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

struct sPlayerStat7View_00148410 {
    signed char v[7];
};
struct sPlayerStatRowView_00148410 {
    sPlayerStat7View_00148410 e[10];
};
extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" signed char func_00148410(void* self, int rider)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return D_00535538_view[a].e[c].v[0];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148470);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" void func_00148470(void* self, int rider, int value)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00535538_view[a].e[c].v[1] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001484E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" signed char func_001484E0(void* self, int rider)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return D_00535538_view[a].e[c].v[1];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148540);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" void func_00148540(void* self, int rider, int value)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00535538_view[a].e[c].v[2] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001485B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" signed char func_001485B0(void* self, int rider)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return D_00535538_view[a].e[c].v[2];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148610);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" void func_00148610(void* self, int rider, int value)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00535538_view[a].e[c].v[3] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148680);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" signed char func_00148680(void* self, int rider)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return D_00535538_view[a].e[c].v[3];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001486E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" void func_001486E0(void* self, int rider, int value)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00535538_view[a].e[c].v[4] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148750);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" signed char func_00148750(void* self, int rider)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return D_00535538_view[a].e[c].v[4];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001487B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" void func_001487B0(void* self, int rider, int value)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00535538_view[a].e[c].v[5] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148820);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" signed char func_00148820(void* self, int rider)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return D_00535538_view[a].e[c].v[5];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148880);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" void func_00148880(void* self, int rider, int value)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00535538_view[a].e[c].v[6] = value;
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_001488F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sPlayerStatRowView_00148410 D_00535538_view[] __asm__("D_00535538");

extern "C" signed char func_001488F0(void* self, int rider)
{
    int a = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return D_00535538_view[a].e[c].v[6];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148950);
#ifdef SKIP_ASM
extern "C" signed char func_00148410(void* self, int rider);
extern "C" signed char func_001484E0(void* self, int rider);
extern "C" signed char func_001485B0(void* self, int rider);
extern "C" signed char func_00148680(void* self, int rider);
extern "C" signed char func_00148750(void* self, int rider);
extern "C" signed char func_00148820(void* self, int rider);
extern "C" signed char func_001488F0(void* self, int rider);

extern "C" int func_00148950(void* self, int rider)
{
    int v;
    v = func_001484E0(self, rider);
    int sum = v / 5;
    v = func_00148680(self, rider);
    sum += v / 5;
    v = func_00148410(self, rider);
    sum += v / 5;
    v = func_00148750(self, rider);
    sum += v / 5;
    v = func_00148820(self, rider);
    sum += v / 5;
    v = func_001488F0(self, rider);
    sum += v / 5;
    v = func_001485B0(self, rider);
    sum += v / 5;
    int r = sum / 7;
    if (r > 0)
        return r;
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/beintplayer", func_00148AA8);
#ifdef SKIP_ASM
extern "C" void func_00148AA8(void* self, int rider, int value)
{
    int v = value * 5;
    func_00148470(self, rider, v);
    func_00148610(self, rider, v);
    func_001483A0(self, rider, v);
    func_001486E0(self, rider, v);
    func_001487B0(self, rider, v);
    func_00148880(self, rider, v);
    func_00148540(self, rider, v);
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148B78);
#ifdef SKIP_ASM
struct sPlayerStat7 {
    signed char v[7];
};
struct sPlayerStatRow {
    sPlayerStat7 e[10]; // 0x46 bytes
};
extern sPlayerStatRow D_00535538[];

extern "C" signed char func_00148B78(void* self, int a1, int a2)
{
    return D_00535538[a1].e[a2].v[0];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148BC8);
#ifdef SKIP_ASM
extern "C" signed char func_00148BC8(void* self, int a1, int a2)
{
    return D_00535538[a1].e[a2].v[1];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148C18);
#ifdef SKIP_ASM
extern "C" signed char func_00148C18(void* self, int a1, int a2)
{
    return D_00535538[a1].e[a2].v[2];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148C68);
#ifdef SKIP_ASM
extern "C" signed char func_00148C68(void* self, int a1, int a2)
{
    return D_00535538[a1].e[a2].v[3];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148CB8);
#ifdef SKIP_ASM
extern "C" signed char func_00148CB8(void* self, int a1, int a2)
{
    return D_00535538[a1].e[a2].v[4];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148D08);
#ifdef SKIP_ASM
extern "C" signed char func_00148D08(void* self, int a1, int a2)
{
    return D_00535538[a1].e[a2].v[5];
}
#endif

//100%
INCLUDE_ASM("be/beintplayer", func_00148D58);
#ifdef SKIP_ASM
extern "C" signed char func_00148D58(void* self, int a1, int a2)
{
    return D_00535538[a1].e[a2].v[6];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/beintplayer", func_00148D80);
#ifdef SKIP_ASM
int cBENewPlayerInterface_isMissionMan(int index);

struct sCharStat_005308D8
{
    signed char v[15];
};
extern sCharStat_005308D8 D_005308D8[];

extern "C" float func_00148D80(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538[profile].e[c].v[3] / 5;
    return (float)v / (float)D_005308D8[c].v[0xB];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/beintplayer", func_00148E68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBENewPlayerInterface_isMissionMan(int index);

struct sCharStat_00148E68
{
    signed char v[15];
};
extern sCharStat_00148E68 D_005308D8_00148E68[] __asm__("D_005308D8");

extern "C" float func_00148E68(void* self, int rider, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    if (cBENewPlayerInterface_isMissionMan(rider))
        return 0.5f;
    int v;
    if (value > 0)
        v = value;
    else
        v = D_00535538[profile].e[c].v[3] / 5;
    return (float)v / (float)D_005308D8_00148E68[c].v[0xB];
}
#endif

