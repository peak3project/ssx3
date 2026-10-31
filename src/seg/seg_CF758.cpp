#include "common.h"

//100%
INCLUDE_ASM("seg/seg_CF758", setChallengeName);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
void* cBE_getInterface_CE758(void* be, int kind) __asm__("cBE_getInterface__Fv");
void cUIText_setAsciiString(cUIText* text, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" const char* func_00144C60(void* iface, int track);
extern "C" unsigned short* func_002C2540(void* dst, void* src);
// PORT: func_002C26D0 is a varargs formatter (dst, fmt, ...)
extern "C" void func_002C26D0_CE758(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern "C" void func_003A0E90(cUIText* text, void* str);
extern void* D_004A28A8;

struct sReq_CE758
{
    signed char type;
    signed char track;
};
extern sReq_CE758 D_0045AAD8_CE758[][4][5] __asm__("D_0045AAD8");

extern char D_00466BB8[];
extern char D_00466BD0[];
extern char D_00466BE8[];
extern char D_00466C00[];
extern char D_00466C10[];
extern char D_00466C20[];
extern char D_00466C30[];
extern char D_00466C40[];
extern char D_00466C50[];
extern char D_00466C60[];
extern char D_00466C70[];
extern char D_00466C80[];
extern char D_00466C90[];
extern char D_00466CA8[];
extern char D_00466CB8[];
extern char D_00466CC8[];

struct sVEntry_CE758 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc_CE758(char* key)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_CE758* vt = *(sVEntry_CE758**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(key));
}

extern "C" void setChallengeName(cUIText* text, int peak, int kind, int idx)
{
    if (kind == 3) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466BB8));
        return;
    }
    if (kind == 2) {
        if (idx == 0) {
            cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466BD0));
        } else {
            cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466BE8));
        }
        return;
    }
    void* iface = cBE_getInterface_CE758(cBE_getBE(), 0);
    int type = D_0045AAD8_CE758[peak][kind][idx].type;
    int track = D_0045AAD8_CE758[peak][kind][idx].track;
    if (type == 4) {
        unsigned short buf[200];
        unsigned short fmt[32];
        if (peak == 0) {
            func_002C2540(fmt, D_00466C00);
        } else if (peak == 1) {
            func_002C2540(fmt, D_00466C10);
        } else if (peak == 2) {
            func_002C2540(fmt, D_00466C20);
        }
        func_002C26D0_CE758(buf, fmt, Loc_CE758(D_00466C30));
        func_003A0E90(text, buf);
    } else if (type == 5) {
        if (peak == 0) {
            cUIText_setAsciiString(text, D_00466C40);
        } else if (peak == 1) {
            cUIText_setAsciiString(text, D_00466C50);
        } else if (peak == 2) {
            cUIText_setAsciiString(text, D_00466C60);
        }
    } else if (type == 6) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466C70));
    } else if (type == 7) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466C80));
    } else if (type == 8) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466C90));
    } else if (type == 9) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466CA8));
    } else if (type == 10) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466CB8));
    } else if (type == 11) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466CC8));
    } else {
        cUIText_setAsciiString(text, func_00144C60(iface, track));
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_CF758", setChallengeStats);
#ifdef SKIP_ASM
int cBEEconInterface_getTotalMoneyEarned(void* econ, int a, int b);
extern "C" const char* func_00198AF0_price(int price) __asm__("func_00198AF0");
extern "C" int func_002C27C0(void* buf, const char* fmt, ...);
extern "C" int sprintf(char* buf, const char* fmt, ...);
// PORT: SN soft-float float->double helper called by name
extern "C" double func_00413AF8(float f);
extern "C" int func_00153390(void* iface, int peak);
extern "C" int func_00153688(void* iface, int a, int b, int peak);
extern "C" int func_00154368(void* iface, int peak);
extern "C" int func_001544D0(void* iface, int a, int b, int peak);
extern "C" int func_00158960(void* self, int b, int c, int d, int e);
extern char D_004A1EE0[];
extern char D_00466CE0[];
extern char D_00466CF8[];
extern char D_00466D10[];
extern char D_00466D28[];
extern char D_00466D38[];
extern char D_00466D50[];

static inline unsigned int udiv_CE758(unsigned int a, unsigned int b)
{
    return a / b;
}

static inline unsigned int umod_CE758(unsigned int a, unsigned int b)
{
    return a % b;
}

extern "C" void setChallengeStats(cUIText* text, int a1, int a2, int peak, int kind, int idx)
{
    unsigned short buf[100];
    char num[200];
    void* reward = cBE_getInterface_CE758(cBE_getBE(), 0xD);
    if (kind == 3) {
        int money = cBEEconInterface_getTotalMoneyEarned(cBE_getInterface_CE758(cBE_getBE(), 0xB), a1, a2);
        int fmt = Loc_CE758(D_00466CE0);
        func_002C27C0(num, D_004A1EE0, func_00198AF0_price(money));
        if (fmt != 0) {
            func_002C26D0_CE758(buf, (void*)fmt, num);
            func_003A0E90(text, buf);
        }
    } else if (kind == 2) {
        void* iface = cBE_getInterface_CE758(cBE_getBE(), 0xA);
        if (idx == 0) {
            int t = func_00153390(iface, peak);
            int v = func_00153688(iface, a1, a2, peak);
            int fmt = Loc_CE758(D_00466CF8);
            if (fmt != 0) {
                func_002C26D0_CE758(buf, (void*)fmt, v, t);
                func_003A0E90(text, buf);
            }
        } else {
            int t = func_00154368(iface, peak);
            int v = func_001544D0(iface, a1, a2, peak);
            int fmt = Loc_CE758(D_00466D10);
            if (fmt != 0) {
                func_002C26D0_CE758(buf, (void*)fmt, v, t);
                func_003A0E90(text, buf);
            }
        }
    } else if (kind == 0) {
        int track = D_0045AAD8_CE758[peak][kind][idx].track;
        int type = D_0045AAD8_CE758[peak][kind][idx].type;
        unsigned int time = func_00158960(reward, a1, a2, type, track);
        unsigned int min = udiv_CE758(time, 60);
        unsigned int sec = umod_CE758(time, 60);
        sprintf(num, D_00466D28, func_00413AF8((float)(int)min), func_00413AF8((float)(int)sec));
        int fmt = Loc_CE758(D_00466D38);
        if (fmt != 0) {
            func_002C26D0_CE758(buf, (void*)fmt, num);
            func_003A0E90(text, buf);
        }
    } else if (kind == 1) {
        int track = D_0045AAD8_CE758[peak][kind][idx].track;
        int type = D_0045AAD8_CE758[peak][kind][idx].type;
        int v = func_00158960(reward, a1, a2, type, track);
        int fmt = Loc_CE758(D_00466D50);
        if (fmt != 0) {
            func_002C26D0_CE758(buf, (void*)fmt, v);
            func_003A0E90(text, buf);
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_CF758", func_001CED90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_ED90(void* be, int kind) __asm__("cBE_getInterface__Fv");
signed char cBERewardInterface_getTrackMedal(void* self, int a, int b, int track, int kind);
extern "C" int cBERewardInterface_getEarningsMedal(void* self, int a, int b, int kind);
extern "C" int func_001589B0(void* self, int a, int b, int kind);
extern "C" int func_00158A50(void* self, int a, int b, int kind);
struct sReq_ED90
{
    signed char track;
    signed char kind;
};
extern sReq_ED90 D_0045AAD8_ED90[][4][5] __asm__("D_0045AAD8");

extern "C" int func_001CED90(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    void* r = cBE_getInterface_ED90(cBE_getBE(), 0xD);
    int result;
    if (arg3 == 2)
    {
        if (arg4 == 0)
        {
            result = func_001589B0(r, arg0, arg1, arg2);
        }
        else
        {
            result = func_00158A50(r, arg0, arg1, arg2);
        }
    }
    else if (arg3 != 3)
    {
        int kind = D_0045AAD8_ED90[arg2][arg3][arg4].kind;
        int track = D_0045AAD8_ED90[arg2][arg3][arg4].track;
        result = cBERewardInterface_getTrackMedal(r, arg0, arg1, track, kind);
    }
    else
    {
        result = cBERewardInterface_getEarningsMedal(r, arg0, arg1, arg2);
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("seg/seg_CF758", func_001CEEA0);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* parent);
extern "C" unsigned char func_001A1CD0(void* mgr, int player);
signed char cBENewPlayerInterface_getPlayerCharID(void* self, int index);
int cBELibrary_getRiderIndex(int flag);
extern "C" int func_00146D98(void* self, int index);
extern "C" int func_00150928(void* self, int a, int b);
extern char D_0046A3C8[];

struct sVEntry_1CEEA0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sChallenge_1CEEA0 {
    char pad0[0x8];
    void* vtbl;              // 0x8
    int type;                // 0xC
    void** mgr;              // 0x10
    char f14;
    signed char f15;         // 0x15
    char pad16[0x2E];
    signed char player;      // 0x44
    char pad45[3];
    int f48;                 // 0x48
    int f4C;                 // 0x4C
    int charId;              // 0x50
    int f54;                 // 0x54
    int f58;                 // 0x58
    int f5C;                 // 0x5C
    int f60;
    int f64;                 // 0x64
    int f68;                 // 0x68
    int f6C;                 // 0x6C
    int f70;                 // 0x70
    int f74;                 // 0x74
    int f78;                 // 0x78
    char pad7C[0x8EC - 0x7C];
    int f8EC;                // 0x8EC
    int f8F0;                // 0x8F0
    int f8F4;                // 0x8F4
    int f8F8;                // 0x8F8
    int f8FC[10];            // 0x8FC
    int a[4][8];             // 0x924
    int b[4][8];             // 0x9A4
};

extern "C" sChallenge_1CEEA0* func_001CEEA0(sChallenge_1CEEA0* self, void* parent, signed char player, int rank, int a4)
{
    int i;
    int j;
    func_0039E2A0(self, parent);
    self->type = 0x2F;
    self->vtbl = D_0046A3C8;
    self->player = player;
    self->f15 = func_001A1CD0(*self->mgr, player);
    self->f4C = a4;
    self->f58 = 4;
    self->f5C = 8;
    self->f8EC = -2;
    self->f48 = 0;
    self->f64 = 0;
    self->f8F4 = 0;
    self->f8F8 = 0;
    self->f70 = 0;
    self->f74 = 0;
    self->f8FC[0] = 0;
    self->f8FC[1] = 0;
    self->f8FC[2] = 0;
    self->f8FC[3] = 0;
    self->f8FC[4] = 0;
    self->f8FC[5] = 0;
    self->f8FC[6] = 0;
    self->f8FC[7] = 0;
    self->f8FC[8] = 0;
    self->f8FC[9] = 0;
    self->f68 = 0;
    self->f6C = 0;
    self->f78 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            self->a[i][j] = 0;
            self->b[i][j] = 0;
        }
    }
    char* iface = (char*)cBE_getInterface_ED90(cBE_getBE(), 1);
    self->charId = cBENewPlayerInterface_getPlayerCharID(iface, self->player);
    if (rank != 0) {
        switch (func_00146D98(iface, cBELibrary_getRiderIndex(self->player))) {
        case 17: self->f8F0 = 1; break;
        case 18: self->f8F0 = 1; break;
        case 19: self->f8F0 = 2; break;
        case 20: self->f8F0 = 2; break;
        case 21: self->f8F0 = 3; break;
        default: self->f8F0 = 1; break;
        }
    } else {
        self->f8F0 = -1;
    }
    sVEntry_1CEEA0* vt = *(sVEntry_1CEEA0**)(iface + 0xC);
    vt[2].fn(iface + vt[2].delta);
    self->f54 = func_00150928(cBE_getInterface_ED90(cBE_getBE(), 0xB), self->player, self->charId);
    return self;
}
#endif
