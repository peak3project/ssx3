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
extern "C" void func_002C2540(void* dst, void* src);
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

INCLUDE_ASM("seg/seg_CF758", setChallengeStats);

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

extern "C" void func_001CED90(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    void* r = cBE_getInterface_ED90(cBE_getBE(), 0xD);
    if (arg3 == 2)
    {
        if (arg4 == 0)
        {
            func_001589B0(r, arg0, arg1, arg2);
            return;
        }
        func_00158A50(r, arg0, arg1, arg2);
        return;
    }
    if (arg3 != 3)
    {
        int kind = D_0045AAD8_ED90[arg2][arg3][arg4].kind;
        int track = D_0045AAD8_ED90[arg2][arg3][arg4].track;
        cBERewardInterface_getTrackMedal(r, arg0, arg1, track, kind);
        return;
    }
    cBERewardInterface_getEarningsMedal(r, arg0, arg1, arg2);
}
#endif

INCLUDE_ASM("seg/seg_CF758", func_001CEEA0);
