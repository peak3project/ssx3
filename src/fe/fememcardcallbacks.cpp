#include "common.h"

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_callbackSaveSuccess);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_004677B8[];
extern char D_0045F7E0[];
void func_001D8C38(void* self);

struct sVEntryS1D66B0 {
    short delta;
    short index;
    void* (*fn)(void*, ...);
};

struct sVEntryVS1D66B0 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

extern "C" void cFEMemCard_callbackSaveSuccess(void)
{
    func_001D8C38(D_004A2028);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x1F0) = 0;
    if (*(int*)(fe + 0x208) == 0) {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntryS1D66B0* ovt = *(sVEntryS1D66B0**)(o + 4);
        void* str = ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004677B8));
        char* fe2 = (char*)D_004A2028;
        *(int*)(fe2 + 0x19C) = 5;
        sVEntryVS1D66B0* vt = *(sVEntryVS1D66B0**)(fe2 + 8);
        vt[36].fn(fe2 + vt[36].delta, str, 1, 0, 0, 0, 0);
        char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntryS1D66B0* o2vt = *(sVEntryS1D66B0**)(o2 + 4);
        void* str2 = o2vt[4].fn(o2 + o2vt[4].delta, GetHashValue32(D_0045F7E0));
        char* m = *(char**)((char*)D_004A2028 + 0x218);
        sVEntryVS1D66B0* mvt = *(sVEntryVS1D66B0**)(m + 8);
        mvt[26].fn(m + mvt[26].delta, str2, 0);
    } else {
        sVEntryVS1D66B0* vt = *(sVEntryVS1D66B0**)(fe + 8);
        vt[40].fn(fe + vt[40].delta);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_callbackReadSuccess);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_004677D0[];
extern char D_0045F7E0[];
extern "C" void func_001D9308(void*, int);

struct sVEntryR1D67C8 {
    short delta;
    short index;
    void* (*fn)(void*, ...);
};

struct sVEntryVR1D67C8 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

extern "C" void cFEMemCard_callbackReadSuccess(void)
{
    func_001D9308(D_004A2028, 0);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x1B4) = 1;
    *(int*)(fe + 0x1A8) = 0;
    if (*(int*)(fe + 0x204) == 0) {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntryR1D67C8* ovt = *(sVEntryR1D67C8**)(o + 4);
        void* str = ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004677D0));
        char* fe2 = (char*)D_004A2028;
        *(int*)(fe2 + 0x19C) = 6;
        sVEntryVR1D67C8* vt = *(sVEntryVR1D67C8**)(fe2 + 8);
        vt[36].fn(fe2 + vt[36].delta, str, 1, 0, 0, 0, 0);
        char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntryR1D67C8* o2vt = *(sVEntryR1D67C8**)(o2 + 4);
        void* str2 = o2vt[4].fn(o2 + o2vt[4].delta, GetHashValue32(D_0045F7E0));
        char* m = *(char**)((char*)D_004A2028 + 0x218);
        sVEntryVR1D67C8* mvt = *(sVEntryVR1D67C8**)(m + 8);
        mvt[26].fn(m + mvt[26].delta, str2, 0);
    } else {
        sVEntryVR1D67C8* vt = *(sVEntryVR1D67C8**)(fe + 8);
        vt[40].fn(fe + vt[40].delta);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D68E8);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_004642F8[];

struct sVEntryK1D68E8 {
    short delta;
    short index;
    void* (*fn)(void*, ...);
};

struct sVEntryVK1D68E8 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

extern "C" void func_001D68E8(void)
{
    unsigned short name[0x28];
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x640, D_0045E2A0, 0x100, 0);
    char* mp = (char*)func_00227F80(D_004A28A8);
    char* s = *(char**)(mp + 0x434);
    sVEntryVK1D68E8* svt = *(sVEntryVK1D68E8**)s;
    svt[14].fn(s + svt[14].delta, *(int*)(mp + 0xF8), name);
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntryK1D68E8* ovt = *(sVEntryK1D68E8**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004642F8)), name);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 1;
    sVEntryVK1D68E8* vt = *(sVEntryVK1D68E8**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 0, 0, 0, 1, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D69E0);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_002C2508(void* dst, void* src);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_004641F0[];

struct sVEntry001D69E0 {
    short delta;
    short index;
    void* (*fn)(void*, ...);
};

struct sVEntryV001D69E0 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

extern "C" void func_001D69E0(void)
{
    void* buf = operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* vt = *(sVEntry001D69E0**)(o + 4);
    func_002C2508(buf, vt[4].fn(o + vt[4].delta, GetHashValue32(D_004641F0)));
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 2;
    sVEntryV001D69E0* vt2 = *(sVEntryV001D69E0**)(fe + 8);
    vt2[36].fn(fe + vt2[36].delta, buf, 0, 0, 0, 0, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* vt3 = *(sVEntryV001D69E0**)(m + 8);
    vt3[25].fn(m + vt3[25].delta, 1);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D6AD0);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_00464608[];
extern char D_0045F7E0[];

extern "C" void func_001D6AD0(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00464608)), name);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0xA;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 0, 0, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    char* o2this = o2 + o2vt[4].delta;
    void* str2 = o2vt[4].fn(o2this, GetHashValue32(D_0045F7E0));
    mvt[26].fn(mthis, str2, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D6C28);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_00464628[];
extern char D_0045F7E0[];

extern "C" void func_001D6C28(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    *(int*)((char*)D_004A2028 + 0x19C) = 0xB;
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00464628)), name);
    char* fe = (char*)D_004A2028;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 0, 0, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    char* o2this = o2 + o2vt[4].delta;
    void* str2 = o2vt[4].fn(o2this, GetHashValue32(D_0045F7E0));
    mvt[26].fn(mthis, str2, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D6D88);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_004644D8[];
extern char D_0045DCD8[];
extern char D_00462C88[];
extern char D_0045F7E0[];

static inline void* Str_1D6D88(char* key)
{
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    char* othis = o + ovt[4].delta;
    return ovt[4].fn(othis, GetHashValue32(key));
}

static inline void SetLine_1D6D88(char* key, int a)
{
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    void* str = Str_1D6D88(key);
    mvt[26].fn(mthis, str, a);
}

extern "C" void func_001D6D88(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004644D8)), name);
    *(int*)((char*)D_004A2028 + 0x19C) = 9;
    if (!(*(int*)(mp + 0xBC) || *(int*)(mp + 0xC0) || (*(int (**)())(mp + 0x78))())) {
        char* fe = (char*)D_004A2028;
        sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
        vt[36].fn(fe + vt[36].delta, buf, 0, 0, 0, 0, 0);
        SetLine_1D6D88(D_0045DCD8, 1);
        char* m = *(char**)((char*)D_004A2028 + 0x218);
        sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
        mvt[25].fn(m + mvt[25].delta, 1);
        SetLine_1D6D88(D_00462C88, 0);
    } else {
        char* fe = (char*)D_004A2028;
        sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
        vt[36].fn(fe + vt[36].delta, buf, 1, 0, 0, 0, 0);
        SetLine_1D6D88(D_0045F7E0, 0);
    }
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D7010);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_004677E8[];
extern char D_0045F7E0[];

struct sFEMC_001D7010 {
    char pad[0x19C];
    int f19C;
};

extern "C" void func_001D7010(void)
{
    unsigned short name[0x100];
    unsigned short name2[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* sf = *(char**)(mp + 0x434);
    sVEntryV001D69E0* sfvt = *(sVEntryV001D69E0**)sf;
    sfvt[14].fn(sf + sfvt[14].delta, *(int*)(mp + 0xF8), name2);
    ((sFEMC_001D7010*)D_004A2028)->f19C = 0xC;
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004677E8)), name);
    char* fe = (char*)D_004A2028;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 0, 1, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    char* o2this = o2 + o2vt[4].delta;
    void* str2 = o2vt[4].fn(o2this, GetHashValue32(D_0045F7E0));
    mvt[26].fn(mthis, str2, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D7190);
#ifdef SKIP_ASM
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern char D_00467800[];

extern "C" void func_001D7190(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    void* app = D_004A28A8;
    *(int*)((char*)D_004A2028 + 0x19C) = 0xD;
    char* o = *(char**)((char*)app + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00467800)), name);
    char* fe = (char*)D_004A2028;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 0, 0, 0, 1, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    mvt[25].fn(m + mvt[25].delta, 1);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D72A8);
#ifdef SKIP_ASM
struct sVEntry001D72A8 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

extern void* D_004A2028;
extern void* D_004A28A8;
extern "C" void* func_00227F80(void* app);
extern "C" void* func_0023D570(void*, int);

extern "C" void func_001D72A8(void)
{
    char* fe = (char*)D_004A2028;
    sVEntry001D72A8* vt = *(sVEntry001D72A8**)(fe + 8);
    vt[41].fn(fe + vt[41].delta);
    void* app = D_004A28A8;
    *(int*)((char*)D_004A2028 + 0x1E4) = 0;
    char* obj = (char*)func_00227F80(app);
    sVEntry001D72A8* vt2 = *(sVEntry001D72A8**)(obj + 0x748);
    vt2[1].fn(obj + vt2[1].delta, 0x24);
    func_0023D570(obj, 0);
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D7318);
#ifdef SKIP_ASM
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern char D_00464330[];

extern "C" void func_001D7318(void)
{
    unsigned short name[0x100];
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    char* mp = (char*)func_00227F80(D_004A28A8);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00464330)), name);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0xE;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 0, 0, 0, 1, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    mvt[25].fn(m + mvt[25].delta, 1);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_callbackConfirmFormatDone);
#ifdef SKIP_ASM
extern char D_00467818[];
extern char D_0045F7E0[];

extern "C" void cFEMemCard_callbackConfirmFormatDone(void)
{
    void* buf = operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    func_00227F80(D_004A28A8);
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* vt = *(sVEntry001D69E0**)(o + 4);
    func_002C2508(buf, vt[4].fn(o + vt[4].delta, GetHashValue32(D_00467818)));
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0x10;
    sVEntryV001D69E0* vt2 = *(sVEntryV001D69E0**)(fe + 8);
    vt2[36].fn(fe + vt2[36].delta, buf, 1, 0, 0, 0, 0);
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* vt4 = *(sVEntry001D69E0**)(o2 + 4);
    void* str = vt4[4].fn(o2 + vt4[4].delta, GetHashValue32(D_0045F7E0));
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* vt3 = *(sVEntryV001D69E0**)(m + 8);
    vt3[26].fn(m + vt3[26].delta, str, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D7548);
#ifdef SKIP_ASM
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern char D_004644F0[];
extern char D_0045F7E0[];

extern "C" void func_001D7548(void)
{
    unsigned short name[0x100];
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    char* mp = (char*)func_00227F80(D_004A28A8);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004644F0)), name);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0x11;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 0, 0, 0);
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    void* str2 = o2vt[4].fn(o2 + o2vt[4].delta, GetHashValue32(D_0045F7E0));
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    mvt[26].fn(m + mvt[26].delta, str2, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_callbackConfirmDelete);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_00467830[];

struct sVEntryI_001D7688 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

extern "C" void cFEMemCard_callbackConfirmDelete(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    char* sf = *(char**)(mp + 0x434);
    sVEntryI_001D7688* sfvt = *(sVEntryI_001D7688**)sf;
    if (sfvt[13].fn(sf + sfvt[13].delta) > 0) {
        unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
        *(int*)((char*)D_004A2028 + 0x19C) = 3;
        char* sf2 = *(char**)(mp + 0x434);
        sVEntryV001D69E0* sfvt2 = *(sVEntryV001D69E0**)sf2;
        sfvt2[14].fn(sf2 + sfvt2[14].delta, *(int*)(mp + 0xF8), name);
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
        func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00467830)), name);
        char* fe = (char*)D_004A2028;
        sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
        vt[36].fn(fe + vt[36].delta, buf, 0, 0, 0, 1, 0);
        char* m = *(char**)((char*)D_004A2028 + 0x218);
        sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
        mvt[25].fn(m + mvt[25].delta, 1);
        if (buf != 0) {
            cMemMan_free(buf);
        }
    } else {
        char* fe = (char*)D_004A2028;
        if (*(int*)(fe + 0x1C0) == 4) {
            *(int*)(fe + 0x1A8) = 0;
            *(int*)(fe + 0x1E0) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D77E8);
#ifdef SKIP_ASM
extern char D_004644D8[];
extern char D_0045DCD8[];
extern char D_00462C88[];

extern "C" void func_001D77E8(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004644D8)), name);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0x12;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 0, 0, 0, 0, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    char* o2this = o2 + o2vt[4].delta;
    void* str2 = o2vt[4].fn(o2this, GetHashValue32(D_0045DCD8));
    mvt[26].fn(mthis, str2, 0);
    char* m3 = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* m3vt = *(sVEntryV001D69E0**)(m3 + 8);
    char* m3this = m3 + m3vt[26].delta;
    char* o3 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o3vt = *(sVEntry001D69E0**)(o3 + 4);
    char* o3this = o3 + o3vt[4].delta;
    void* str3 = o3vt[4].fn(o3this, GetHashValue32(D_00462C88));
    m3vt[26].fn(m3this, str3, 1);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D7998);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_00467848[];
extern char D_0045F7E0[];

struct sVEntryI_001D7998 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

extern "C" void func_001D7998(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    *(int*)((char*)D_004A2028 + 0x19C) = 0x13;
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    unsigned short* fmt = (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00467848));
    char* sf = *(char**)(mp + 0x434);
    sVEntryI_001D7998* sfvt = *(sVEntryI_001D7998**)sf;
    int n = sfvt[23].fn(sf + sfvt[23].delta);
    func_002C26D0(buf, fmt, name, n);
    char* fe = (char*)D_004A2028;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 3, 1, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    char* o2this = o2 + o2vt[4].delta;
    void* str2 = o2vt[4].fn(o2this, GetHashValue32(D_0045F7E0));
    mvt[26].fn(mthis, str2, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D7B18);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_00467848[];
extern char D_0045F7E0[];

struct sVEntryI_001D7B18 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

struct sLocal_001D7B18 {
    int v[8];
};

extern "C" void func_001D7B18(void)
{
    unsigned short buf[0x320];
    sLocal_001D7B18 name;
    char* mp = (char*)func_00227F80(D_004A28A8);
    *(int*)((char*)D_004A2028 + 0x19C) = 0x13;
    func_00241DC8(mp, &name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    unsigned short* fmt = (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00467848));
    char* sf = *(char**)(mp + 0x434);
    sVEntryI_001D7B18* sfvt = *(sVEntryI_001D7B18**)sf;
    int n = sfvt[23].fn(sf + sfvt[23].delta);
    func_002C26D0(buf, fmt, &name, n);
    char* fe = (char*)D_004A2028;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 3, 1, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    char* o2this = o2 + o2vt[4].delta;
    void* str2 = o2vt[4].fn(o2this, GetHashValue32(D_0045F7E0));
    mvt[26].fn(mthis, str2, 0);
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_callbackFileExists);
#ifdef SKIP_ASM
extern char D_00467860[];
extern char D_0045F7E0[];

extern "C" void cFEMemCard_callbackFileExists(void)
{
    void* app = D_004A28A8;
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0x17;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    char* o = *(char**)((char*)app + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    vt[36].fn(fe + vt[36].delta, ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00467860)), 1, 0, 0, 0, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    mvt[26].fn(m + mvt[26].delta, o2vt[4].fn(o2 + o2vt[4].delta, GetHashValue32(D_0045F7E0)), 0);
    *(int*)((char*)D_004A2028 + 0x1C0) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D7D70);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_00467878[];
extern char D_0045F7E0[];

extern "C" void func_001D7D70(void)
{
    unsigned short name[0x100];
    char* mp = (char*)func_00227F80(D_004A28A8);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x640, D_0045E2A0, 0x100, 0);
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00467878)), name);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0x18;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 0, 0, 0);
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    char* mthis = m + mvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    char* o2this = o2 + o2vt[4].delta;
    void* str2 = o2vt[4].fn(o2this, GetHashValue32(D_0045F7E0));
    mvt[26].fn(mthis, str2, 0);
    *(int*)((char*)D_004A2028 + 0x1C0) = 1;
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_callbackDeleteDone);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_002C2508(void* dst, void* src);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_00467898[];
extern char D_0045F7E0[];

extern "C" int cFEMemCard_callbackDeleteDone(void)
{
    if (*(int*)((char*)D_004A2028 + 0x204) == 0) {
        void* buf = operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry001D69E0* vt = *(sVEntry001D69E0**)(o + 4);
        func_002C2508(buf, vt[4].fn(o + vt[4].delta, GetHashValue32(D_00467898)));
        char* fe = (char*)D_004A2028;
        *(int*)(fe + 0x19C) = 7;
        sVEntryV001D69E0* vt2 = *(sVEntryV001D69E0**)(fe + 8);
        vt2[36].fn(fe + vt2[36].delta, buf, 1, 0, 0, 0, 0);
        char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
        void* str2 = o2vt[4].fn(o2 + o2vt[4].delta, GetHashValue32(D_0045F7E0));
        char* m = *(char**)((char*)D_004A2028 + 0x218);
        sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
        mvt[26].fn(m + mvt[26].delta, str2, 0);
        if (buf != 0) {
            cMemMan_free(buf);
        }
    }
    char* fe = (char*)D_004A2028;
    if (*(int*)(fe + 0x1C0) == 4) {
        *(int*)(fe + 0x1C0) = 1;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8020);
#ifdef SKIP_ASM
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern char D_00464640[];
extern char D_0045F7E0[];

extern "C" int func_001D8020(void)
{
    unsigned short name[0x100];
    unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
    char* mp = (char*)func_00227F80(D_004A28A8);
    func_00241DC8(mp, name, *(int*)(mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
    func_002C26D0(buf, (unsigned short*)ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_00464640)), name);
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x19C) = 0x8;
    sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
    vt[36].fn(fe + vt[36].delta, buf, 1, 0, 0, 0, 0);
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry001D69E0* o2vt = *(sVEntry001D69E0**)(o2 + 4);
    void* str2 = o2vt[4].fn(o2 + o2vt[4].delta, GetHashValue32(D_0045F7E0));
    char* m = *(char**)((char*)D_004A2028 + 0x218);
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(m + 8);
    mvt[26].fn(m + mvt[26].delta, str2, 0);
    if (buf != 0) {
        cMemMan_free(buf);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8160);
#ifdef SKIP_ASM
void func_0023FB18(void* mp, int a);
extern "C" void func_0023FAE0(void* mp);
extern "C" void func_00241400(void* mp);

class cMoviePlayerK1D8160 {
public:
    char pad_0x000[0x748];
    virtual void v01(int);
};

class cMovieStreamK1D8160 {
public:
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51();
    virtual int v52(int);
};

extern "C" void func_001D8160(void)
{
    cMoviePlayerK1D8160* mp = (cMoviePlayerK1D8160*)func_00227F80(D_004A28A8);
    int next = *(int*)((char*)mp + 0x428) + 1;
    if (next < *(int*)((char*)mp + 0x424)) {
        func_0023FB18(mp, next);
        mp->v01(0x31);
        return;
    }
    func_0023FB18(mp, 0);
    if ((*(cMovieStreamK1D8160**)((char*)mp + 0x434))->v52(0) == 0) {
        char* fe = (char*)D_004A2028;
        if (*(int*)(fe + 0x208) != 0) {
            *(int*)(fe + 0x1C0) = 6;
            mp->v01(2);
            return;
        }
        func_00241400(mp);
    }
    func_0023FAE0(mp);
    mp->v01(0x36);
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8240);
#ifdef SKIP_ASM
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_003A0D00(void* self, unsigned short* str);
extern char D_004678B0[];
extern char D_004678C8[];

struct sVEntryK1D8240 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001D8240(void)
{
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x1C0) = 1;
    if (*(int*)(fe + 0x214) != 1) {
        *(int*)(fe + 0x214) = 1;
        sVEntryK1D8240* vt = *(sVEntryK1D8240**)(fe + 8);
        vt[35].fn(fe + vt[35].delta, 1);
    }
    char* st = (char*)D_004A2028;
    char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)(st + 0x40), GetHashValue32(D_004678B0));
    if (obj) {
        unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
        func_002C2508(buf, ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004678C8)));
        func_003A0D00(obj, buf);
        sVEntryK1D8240* vt = *(sVEntryK1D8240**)(obj + 8);
        vt[9].fn(obj + vt[9].delta, 1);
        if (buf != 0) {
            cMemMan_free(buf);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8358);
#ifdef SKIP_ASM
struct sVEntry001D8358 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern void* D_004A2028;

extern "C" void func_001D8358(void)
{
    char* fe = (char*)D_004A2028;
    if (*(int*)(fe + 0x214) != 2 && *(int*)(fe + 0x1C0) == 0) {
        *(int*)(fe + 0x214) = 2;
        sVEntry001D8358* vt = *(sVEntry001D8358**)(fe + 8);
        vt[35].fn(fe + vt[35].delta, 2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D83A8);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void* func_002C2508(void* dst, void* src);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_003A0D00(void* self, unsigned short* str);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_004678B0[];
extern char D_004678C8[];

struct sVEntryI_001D83A8 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

static inline void SetMode_001D83A8(char* fe, int mode)
{
    if (*(int*)(fe + 0x214) != mode) {
        *(int*)(fe + 0x214) = mode;
        sVEntryV001D69E0* vt = *(sVEntryV001D69E0**)(fe + 8);
        vt[35].fn(fe + vt[35].delta, mode);
    }
}

extern "C" void func_001D83A8(void)
{
    char* mp = (char*)func_00227F80(D_004A28A8);
    *(int*)((char*)D_004A2028 + 0x1C0) = 1;
    sVEntryV001D69E0* mvt = *(sVEntryV001D69E0**)(mp + 0x748);
    mvt[1].fn(mp + mvt[1].delta, 2);
    char* sf = *(char**)(mp + 0x434);
    sVEntryI_001D83A8* sfvt = *(sVEntryI_001D83A8**)sf;
    int busy = sfvt[53].fn(sf + sfvt[53].delta);
    if (busy) {
        SetMode_001D83A8((char*)D_004A2028, 3);
    } else {
        SetMode_001D83A8((char*)D_004A2028, 1);
        char* st = (char*)D_004A2028;
        void* obj = cUIScreen_getObjectByHashName(*(void**)(st + 0x40), GetHashValue32(D_004678B0));
        if (obj) {
            unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
            char* o = *(char**)((char*)D_004A28A8 + 0x8C);
            sVEntry001D69E0* ovt = *(sVEntry001D69E0**)(o + 4);
            func_002C2508(buf, ovt[4].fn(o + ovt[4].delta, GetHashValue32(D_004678C8)));
            func_003A0D00(obj, buf);
            sVEntryV001D69E0* bvt = *(sVEntryV001D69E0**)((char*)obj + 8);
            bvt[9].fn((char*)obj + bvt[9].delta, 1);
            if (buf != 0) {
                cMemMan_free(buf);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8530);
#ifdef SKIP_ASM
extern void* D_004A2028;
extern char D_0045E130[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001D99C8_8530(void* self, void* engine, void* owner, int a3, int a4, int a5, int a6, int a7, int a8) __asm__("func_001D99C8");
extern "C" void func_0039F290(void* list, void* item);

class cPopup_8530 {
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
    virtual void v25(int);
    virtual void v26();
    virtual void v27();
    virtual void v28(int, int, int, int, int, int);
};

// Shows the memory-card popup: updates the existing one, or creates and registers a new one.
extern "C" void func_001D8530(void* self_, int a1, int a2, int a3, int a4, int a5, int a6)
{
    char* self = (char*)self_;
    if (*(int*)((char*)D_004A2028 + 0x19C) != 0x16) {
        *(int*)(self + 0x210) = 0;
    }
    cPopup_8530* p = *(cPopup_8530**)(self + 0x218);
    if (p != 0) {
        p->v28(a1, a2, a3, a4, a5, a6);
    } else {
        void* mem = cMemMan_alloc(0xBFC, D_0045E130, 0x100, 0);
        void* engine = *(void**)((char*)D_004A2028 + 0x10);
        cPopup_8530* n = (cPopup_8530*)func_001D99C8_8530(mem, engine, D_004A2028, a1, a2, a3, a4, a5, a6);
        *(cPopup_8530**)(self + 0x218) = n;
        func_0039F290(*(char**)(self + 0x10) + 0x18, n);
    }
    if (*(int*)((char*)D_004A2028 + 0x19C) == 1) {
        (*(cPopup_8530**)(self + 0x218))->v25(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8670);
#ifdef SKIP_ASM
extern void* D_004A2028;

extern "C" void func_001D8670(void)
{
    if (*(int*)((char*)D_004A2028 + 0x1C0) == 4) {
        *(int*)((char*)D_004A2028 + 0x1C0) = 1;
    }
    char* fe = (char*)D_004A2028;
    *(int*)(fe + 0x1A8) = 0;
    *(int*)(fe + 0x1E0) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D86A0__FPv);
#ifdef SKIP_ASM
void func_001D86A0(void* self)
{
    *(int*)((char*)self + 0x1C0) = 6;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D86B0);
#ifdef SKIP_ASM
struct sVEntry001D86B0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_001D9308(void*, int);

extern "C" void func_001D86B0(void* self)
{
    func_001D9308(self, 1);
    *(int*)((char*)self + 0x1A8) = 1;
    sVEntry001D86B0* vt = *(sVEntry001D86B0**)((char*)self + 8);
    *(int*)((char*)self + 0x1C0) = 5;
    vt[47].fn((char*)self + vt[47].delta);
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8700);
#ifdef SKIP_ASM
extern void* D_004A2028;
extern void* D_004A28A8;
extern "C" void* func_00227F80(void* app);
extern "C" void func_001D9308(void*, int);
extern "C" void func_001D7190(void);
extern "C" void* func_0039F190(void* list, int a1);

struct sVEntryK1D8700 {
    short delta;
    short index;
    void (*fn)(void*);
};

#define VCALL_K1D8700(obj, idx) ((*(sVEntryK1D8700**)((char*)(obj) + 8))[idx].fn((char*)(obj) + (*(sVEntryK1D8700**)((char*)(obj) + 8))[idx].delta))

static inline void notifyK1D8700(char* self, char* mp)
{
    if (*(int*)(self + 0x204) == 1) {
        *(int*)(mp + 0x440) = *(int*)(self + 0x204);
        VCALL_K1D8700(self, 40);
    }
}

// Popup button callback: 0xF/0x10/0x11 pick choice 0/1/2; 0x16 dismisses.
extern "C" void func_001D8700(void* self_, int a1, int button)
{
    char* self = (char*)self_;
    if (button >= 0xF && button <= 0x11) {
        int choice = 0;
        if (button == 0x10) {
            choice = 1;
        } else if (button == 0x11) {
            choice = 2;
        }
        char* mp = (char*)func_00227F80(D_004A28A8);
        switch (*(int*)(self + 0x19C)) {
        case 2:
            if (choice == 0) {
                VCALL_K1D8700(self, 45);
            } else {
                *(int*)(self + 0x1C0) = 1;
            }
            break;
        case 19:
            if (choice == 0) {
                *(int*)(self + 0x1F0) = 0;
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            } else {
                *(int*)(self + 0x1EC) = 1;
            }
            break;
        case 1:
            if (choice != 0) {
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            } else {
                *(int*)(self + 0x1C0) = 3;
                *(int*)(self + 0x1F0) = 1;
            }
            break;
        case 9:
            if (choice == 0) {
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            } else {
                *(int*)(self + 0x1EC) = 1;
            }
            break;
        case 18:
            if (choice == 0) {
                *(int*)(self + 0x1EC) = 1;
            } else {
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            }
            break;
        case 10:
            if (choice == 0) {
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            }
            break;
        case 11:
            *(int*)(self + 0x1F0) = 0;
            VCALL_K1D8700(self, 41);
            notifyK1D8700(self, mp);
            break;
        case 4:
        case 5:
        case 6:
            VCALL_K1D8700(self, 40);
            break;
        case 3:
            *(int*)(self + 0x1B0) = 0;
            if (choice == 0) {
                *(int*)(self + 0x1A8) = 1;
                *(int*)(self + 0x1E0) = 1;
            } else {
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            }
            break;
        case 12:
            if (choice == 0) {
                VCALL_K1D8700(self, 41);
                *(int*)(self + 0x1C0) = 1;
                notifyK1D8700(self, mp);
            } else if (choice == 1) {
                *(int*)(self + 0x1EC) = 1;
            } else {
                func_001D7190();
                return;
            }
            break;
        case 13:
            if (choice == 0) {
                *(int*)(self + 0x1C0) = 3;
                *(int*)(self + 0x1F0) = 1;
            } else {
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            }
            break;
        case 7:
            *(int*)(self + 0x1A8) = 0;
            *(int*)(self + 0x1E0) = 0;
            if (*(int*)(self + 0x1F4) != 0) {
                VCALL_K1D8700(self, 41);
            }
            if (*(int*)(self + 0x1DC) != 0) {
                *(int*)(self + 0x1A8) = 1;
            }
            notifyK1D8700(self, mp);
            break;
        case 16:
            *(int*)(self + 0x1E8) = 0;
            func_001D9308(self, 0);
            if (*(int*)(self + 0x1DC) != 0) {
                *(int*)(self + 0x1A8) = 1;
            } else {
                *(int*)(self + 0x1A8) = 0;
            }
            notifyK1D8700(self, mp);
            break;
        case 17:
            *(int*)(self + 0x1E8) = 0;
            VCALL_K1D8700(self, 41);
            break;
        case 14:
        case 15:
            *(int*)(self + 0x1B0) = 0;
            if (choice == 0) {
                *(int*)(self + 0x1A8) = 1;
                *(int*)(self + 0x1E8) = 1;
            } else if (choice == 1) {
                *(int*)(self + 0x1E8) = 0;
                VCALL_K1D8700(self, 41);
                notifyK1D8700(self, mp);
            }
            break;
        case 8:
        case 23:
            VCALL_K1D8700(self, 41);
            break;
        case 24:
            VCALL_K1D8700(self, 41);
            break;
        }
        if (*(int*)(self + 0x19C) != 0x16) {
            func_0039F190(*(char**)((char*)D_004A2028 + 0x10) + 0x18, 1);
        }
        *(int*)(self + 0x210) = 0;
    } else if (button == 0x16) {
        char* fe = (char*)D_004A2028;
        if (*(int*)(fe + 0x1A0) != 0) {
            *(int*)(fe + 0x1A4) = 0;
            *(int*)(fe + 0x1A0) = 0;
        } else {
            if (*(int*)(self + 0x19C) == button) {
                *(int*)(self + 0x210) = 0;
            }
            *(int*)((char*)D_004A2028 + 0x218) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8BE0);
#ifdef SKIP_ASM
extern "C" void func_001D9308(void*, int);

extern "C" void func_001D8BE0(void* self)
{
    *(int*)((char*)self + 0x1A8) = 0;
    *(int*)((char*)self + 0x1F0) = 0;
    *(int*)((char*)self + 0x1EC) = 0;
    *(int*)((char*)self + 0x1B0) = 0;
    *(int*)((char*)self + 0x1E4) = 1;
    func_001D9308(self, 0);
    *(int*)((char*)self + 0x1C0) = 2;
    *(int*)((char*)self + 0x1E0) = 0;
    *(int*)((char*)self + 0x1E8) = 0;
    *(int*)((char*)self + 0x1DC) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8C38__FPv);
#ifdef SKIP_ASM
void func_001D8C38(void* self)
{
    *(int*)((char*)self + 0x1A8) = 0;
    *(int*)((char*)self + 0x1C0) = 1;
    *(int*)((char*)self + 0x1DC) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_onInputBegin);
#ifdef SKIP_ASM
struct cUIScreen;
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
int GetHashValue32(char* str);
extern char D_00467940[];
extern char D_00467950[];

struct sVEntryK1D8C50 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int cFEMemCard_onInputBegin(void* self, void* input)
{
    int handled = 0;
    if (*(int*)((char*)self + 0x1A8) == 1)
        return 0;
    sVEntryK1D8C50* vt = *(sVEntryK1D8C50**)((char*)input + 8);
    if (vt[19].fn((char*)input + vt[19].delta)) {
        handled = 1;
        *(int*)((char*)self + 0x1FC) = handled;
        if (*(void**)((char*)self + 0x40)) {
            unsigned short frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_00467940));
            if (frame != 0xFFFF)
                cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
    } else {
        sVEntryK1D8C50* vt2 = *(sVEntryK1D8C50**)((char*)input + 8);
        if (vt2[20].fn((char*)input + vt2[20].delta)) {
            handled = 1;
            *(int*)((char*)self + 0x1F8) = handled;
            if (*(void**)((char*)self + 0x40)) {
                unsigned short frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_00467950));
                if (frame != 0xFFFF)
                    cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
            }
        }
    }
    return handled;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8D68);
#ifdef SKIP_ASM
struct sVEntry001D8D68 {
    short delta;
    short index;
    void (*fn)(void*, unsigned short*, int, int, int, int, int);
};

extern void* D_004A28A8;
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241E18(void*, unsigned short*, int);

extern "C" void func_001D8D68(void* self)
{
    unsigned short buf[0x320];
    void* obj = func_00227F80(D_004A28A8);
    *(int*)((char*)self + 0x19C) = 0x16;
    func_00241E18(obj, buf, 0x320);
    sVEntry001D8D68* vt = *(sVEntry001D8D68**)((char*)self + 8);
    vt[36].fn((char*)self + vt[36].delta, buf, 1, 1, 0, 0, 1);
    *(int*)((char*)self + 0x210) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D8DE0);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241E18(void*, unsigned short*, int);
extern "C" void func_0020E900(void* self);
extern "C" void func_0039E510(void*);
extern "C" void func_00241380(void*);
extern "C" int func_0023C898(void*);
extern "C" void func_0023D618(void*);
extern void* D_004A2028;
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_004A1600[];

class cStreamK1D8DE0 {
public:
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06();
    virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10();
    virtual int v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual bool v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66();
    virtual bool v67(int);
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74();
    virtual int v75();
};

class cSubK1D8DE0 {
public:
    virtual void v01(int);
};

class cPopupK1D8DE0 {
public:
    int pad[2];
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06();
    virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26();
    virtual void v27(unsigned short*);
};

class cMemCardK1D8DE0 {
public:
    int pad[2];
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06();
    virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(int);
    virtual void v36(); virtual void v37();
    virtual void v38(int);
    virtual void v39(int, int);
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46();
    virtual void v47();
};

struct sVEntryK1D8DE0 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

#define VCALL_K1D8DE0(obj, off, idx) (*(sVEntryK1D8DE0**)((char*)(obj) + (off)))[idx].fn((char*)(obj) + (*(sVEntryK1D8DE0**)((char*)(obj) + (off)))[idx].delta

#define BUSY_K1D8DE0(self, mp) ((*(int*)((self) + 0x1B0) == 1 && func_0023C898(mp) == 0) \
        || (*(int*)((self) + 0x1B0) == 0 && (*(cStreamK1D8DE0**)((mp) + 0x434))->v11() != 0))

extern "C" void func_001D8DE0(cMemCardK1D8DE0* card)
{
    char* self = (char*)card;
    if (*(void**)(self + 0x218) == 0 && *(int*)(self + 0x1A4) == 0) {
        if (*(int*)((char*)D_004A28A8 + 0x84) != 0) {
            func_0020E900(card);
        } else {
            func_0039E510(self);
        }
    }
    char* mp = (char*)func_00227F80(D_004A28A8);
    if (*(int*)(self + 0x1D8) == 0) {
        func_00241380(mp);
        *(int*)(self + 0x1D8) = 1;
        *(int*)(self + 0x214) = 1;
        VCALL_K1D8DE0(self, 8, 35), 1);
        VCALL_K1D8DE0(mp, 0x748, 1), 0x31);
    }
    if (*(int*)(self + 0x1C0) != 6 || BUSY_K1D8DE0(self, mp)) {
        func_0023D618(mp);
    }
    switch (*(int*)(self + 0x1C0)) {
    case 0:
        VCALL_K1D8DE0(self, 8, 31));
        break;
    case 1:
        VCALL_K1D8DE0(self, 8, 27));
        break;
    case 2:
        VCALL_K1D8DE0(self, 8, 32));
        break;
    case 3:
        VCALL_K1D8DE0(self, 8, 28));
        break;
    case 4:
        VCALL_K1D8DE0(self, 8, 30));
        break;
    case 5:
        VCALL_K1D8DE0(self, 8, 29));
        break;
    case 6:
        {
            char* mp2 = (char*)func_00227F80(D_004A28A8);
            if (!BUSY_K1D8DE0(self, mp2))
                VCALL_K1D8DE0(self, 8, 33));
        }
        break;
    }
    if (*(int*)((char*)D_004A2028 + 0x210) == 0 && *(int*)((char*)D_004A2028 + 0x208) == 0 && *(int*)((char*)D_004A2028 + 0x204) == 0) {
        int m = *(int*)(mp + 0x130);
        if (m == 0x28 || m == 0xB || m == 0xF || m == 0x10 || m == 0x11 || m == 0x12 || m == 0x1F
            || m == 0x21 || m == 0x20 || m == 0x22 || m == 0x2C || m == 0x19 || m == 0x1A) {
            VCALL_K1D8DE0(self, 8, 47));
        }
    }
    if (*(int*)((char*)D_004A2028 + 0x210) != 0) {
        unsigned short* buf = (unsigned short*)operator_new__FUi(0x7D0, D_0045E2A0, 0x100, 0);
        func_00241E18(mp, buf, 0x320);
        (*(cPopupK1D8DE0**)(self + 0x218))->v27(buf);
        if (buf != 0) {
            cMemMan_free(buf);
        }
    }
    VCALL_K1D8DE0(self, 8, 26));
    if (*(void**)(self + 0x218) == 0 && (*(cStreamK1D8DE0**)(mp + 0x434))->v75() != 0) {
        void* menu = cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1600));
        int sel = *(int*)(self + 0x1C4);
        if (menu != 0) {
            sel = *(unsigned char*)((char*)menu + 0x95);
        }
        sVEntryK1D8DE0* vt = *(sVEntryK1D8DE0**)(self + 8);
        void (**pf)(void*, ...) = &vt[38].fn;
        (*pf)(self + vt[38].delta, (*(cStreamK1D8DE0**)(mp + 0x434))->v67(sel) == 0 || (*(cStreamK1D8DE0**)(mp + 0x434))->v53() == 0);
        bool a = !(*(cStreamK1D8DE0**)(mp + 0x434))->v67(sel);
        bool b = !(*(cStreamK1D8DE0**)(mp + 0x434))->v53();
        VCALL_K1D8DE0(self, 8, 39), a, b);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9258);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A1600[];
extern "C" unsigned char func_0039B7B0(void* menu, unsigned char start);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);

extern "C" void func_001D9258(void* self)
{
    void* menu = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1600));
    if (menu != 0) {
        void* item = *(void**)((char*)menu + 0xA0);
        int idx = *(unsigned char*)((char*)menu + 0x95);
        if (item == 0 || ((*(int*)((char*)item + 0x14) >> 5) & 1)) {
            idx = func_0039B7B0(menu, 0);
        }
        if (idx != 0xFF) {
            cUIMenu_setSelectedByIndex(menu, idx);
            *(int*)((char*)self + 0x1C4) = idx;
        } else {
            cUIMenu_setSelectedByIndex(menu, 0);
            *(int*)((char*)self + 0x1C4) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9308);
#ifdef SKIP_ASM
struct sVEntry001D9308 {
    short delta;
    short index;
    void (*fn)(void*, void*, void*);
};

extern void* D_004A28A8;
extern "C" void* func_00227F80(void* app);

extern "C" void func_001D9308(void* self, int on)
{
    *(int*)((char*)self + 0x1F4) = on;
    if (on) {
        char* r = (char*)func_00227F80(D_004A28A8);
        char* obj = *(char**)(r + 0x434);
        sVEntry001D9308* vt = *(sVEntry001D9308**)obj;
        vt[14].fn(obj + vt[14].delta, *(void**)(r + 0xF8), (char*)self + 0x9C);
    } else {
        *(short*)((char*)self + 0x9C) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9368);
#ifdef SKIP_ASM
struct sVEntry001D9368 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001D9368(void* self)
{
    if (*(int*)((char*)self + 0x214) != 1) {
        *(int*)((char*)self + 0x214) = 1;
        sVEntry001D9368* vt = *(sVEntry001D9368**)((char*)self + 8);
        vt[35].fn((char*)self + vt[35].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D93A8__FPv);
#ifdef SKIP_ASM
void func_001D93A8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D93B0__FPv);
#ifdef SKIP_ASM
void func_001D93B0(void* self)
{
    *(int*)((char*)self + 0x1C0) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D93C0__FPv);
#ifdef SKIP_ASM
void func_001D93C0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D93C8__FPv);
#ifdef SKIP_ASM
void func_001D93C8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D93D0__FPv);
#ifdef SKIP_ASM
void func_001D93D0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D93D8);
#ifdef SKIP_ASM
extern "C" int func_001D93D8(void* self)
{
    return *(int*)((char*)self + 0x1c0) == 6;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D93E8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cUIAnimationBank_getAnimationByHashName(void* self, int hash);
extern "C" void func_0039FCC8(void* obj, void* anim, int a, int b, int c);

extern "C" void func_001D93E8(void* self, char* objName, char* animName)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(objName));
    if (obj != 0) {
        void* bank = (char*)*(void**)((char*)self + 0x10) + 0x50;
        void* anim = cUIAnimationBank_getAnimationByHashName(bank, GetHashValue32(animName));
        if (anim != 0) {
            func_0039FCC8(obj, anim, 3, 0, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_triggerDisplayState);
#ifdef SKIP_ASM
struct cUIScreen;
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
void cUIScreen_jumpToFrame(void* self, unsigned short frame);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
int GetHashValue32(char* str);
extern "C" void* func_00227F80(void* app);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" void func_003A0D00(void* self, unsigned short* str);
extern void* D_004A28A8;
extern char D_0045E2A0[];
extern char D_004A1600[];
extern char D_004A1608[];
extern char D_004A2030[];
extern char D_004A2038[];
extern char D_004678B0[];
extern char D_00467980[];
extern char D_00463F58[];

struct sVEntryT1D9470 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sVEntryF1D9470 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern "C" void cFEMemCard_triggerDisplayState(char* self, int state)
{
    unsigned short buf[0x100];
    int frame = 0xFFFF;
    *(int*)(self + 0x214) = state;
    switch (state) {
    case 1: {
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1600));
        if (o) {
            sVEntryT1D9470* vt = *(sVEntryT1D9470**)(o + 8);
            vt[7].fn(o + vt[7].delta, 0);
        }
        o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1608));
        if (o) {
            sVEntryT1D9470* vt = *(sVEntryT1D9470**)(o + 8);
            vt[7].fn(o + vt[7].delta, 1);
        }
        frame = cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_004A2030));
        char* text = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004678B0));
        if (text) {
            unsigned short* str = (unsigned short*)operator_new__FUi(0x640, D_0045E2A0, 0x100, 0);
            char* mp = (char*)func_00227F80(D_004A28A8);
            func_00241DC8(mp, buf, *(int*)(mp + 0x428));
            char* m = *(char**)((char*)D_004A28A8 + 0x8C);
            sVEntryF1D9470* mvt = *(sVEntryF1D9470**)(m + 4);
            func_002C26D0(str, mvt[4].fn(m + mvt[4].delta, GetHashValue32(D_00463F58)), buf);
            func_003A0D00(text, str);
            sVEntryT1D9470* tvt = *(sVEntryT1D9470**)(text + 8);
            tvt[9].fn(text + tvt[9].delta, 1);
            if (str)
                cMemMan_free(str);
        }
        break;
    }
    case 2: {
        char* mp = (char*)func_00227F80(D_004A28A8);
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1600));
        if (o) {
            sVEntryT1D9470* vt = *(sVEntryT1D9470**)(o + 8);
            vt[7].fn(o + vt[7].delta, 0);
        }
        o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1608));
        if (o) {
            sVEntryT1D9470* vt = *(sVEntryT1D9470**)(o + 8);
            vt[7].fn(o + vt[7].delta, 1);
        }
        frame = cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_00467980));
        char* text = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004678B0));
        if (text) {
            unsigned short* str = (unsigned short*)operator_new__FUi(0x640, D_0045E2A0, 0x100, 0);
            func_00241DC8(mp, buf, *(int*)(mp + 0x428));
            char* m = *(char**)((char*)D_004A28A8 + 0x8C);
            sVEntryF1D9470* mvt = *(sVEntryF1D9470**)(m + 4);
            func_002C26D0(str, mvt[4].fn(m + mvt[4].delta, GetHashValue32(D_00463F58)), buf);
            func_003A0D00(text, str);
            sVEntryT1D9470* tvt = *(sVEntryT1D9470**)(text + 8);
            tvt[9].fn(text + tvt[9].delta, 1);
            if (str)
                cMemMan_free(str);
        }
        break;
    }
    case 3: {
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1600));
        if (o) {
            sVEntryT1D9470* vt = *(sVEntryT1D9470**)(o + 8);
            vt[7].fn(o + vt[7].delta, 1);
        }
        o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_004A1608));
        if (o) {
            sVEntryT1D9470* vt = *(sVEntryT1D9470**)(o + 8);
            vt[7].fn(o + vt[7].delta, 0);
        }
        frame = cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_004A2038));
        break;
    }
    }
    if (frame != 0xFFFF)
        cUIScreen_jumpToFrame(*(void**)(self + 0x40), frame);
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D97E0);
#ifdef SKIP_ASM
extern "C" int func_001D97E0(void* self, void* list, int idx, int back)
{
    int step = 1;
    if (back) {
        step = -1;
    }
    idx += step;
    if (idx >= 0 && idx <= *(int*)((char*)list + 0x424) - 1) {
        return 1;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9818);
#ifdef SKIP_ASM
struct sVEntry001D9818 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0039E4C0(void* self, int a1);
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004678B0[];

extern "C" void func_001D9818(void* self, int a1)
{
    func_0039E4C0(self, a1);
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004678B0));
    if (obj != 0) {
        sVEntry001D9818* vt = *(sVEntry001D9818**)((char*)obj + 8);
        vt[9].fn((char*)obj + vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9878__FPv);
#ifdef SKIP_ASM
void func_001D9878(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9880);
#ifdef SKIP_ASM
class cMovieStreamK1D9880 {
public:
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); virtual void v10();
    virtual int v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74();
    virtual int v75();
};

static inline bool IsModeK1D9880(char* mp, int m) { return *(int*)(mp + 0x130) == m; }

extern "C" int func_001D9880(void* self)
{
    int r = 0;
    int one = 1;
    char* mp = (char*)func_00227F80(D_004A28A8);
    int st = *(int*)((char*)self + 0x1C0);
    if (st != 0 && st != 6 && *(int*)(mp + 0x340) != 0 && *(int*)(mp + 0xE0) == 0
        && (*(cMovieStreamK1D9880**)(mp + 0x434))->v11() == 0) {
        if (!IsModeK1D9880(mp, 6) && !IsModeK1D9880(mp, 1)) {
            if ((*(cMovieStreamK1D9880**)(mp + 0x434))->v75() != 0) {
                r = one;
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", cFEMemCard_createReadBuffer);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
void cMemMan_free(void* p);
extern char D_00467990[];

extern "C" void cFEMemCard_createReadBuffer(void* self, unsigned int size)
{
    if (*(int*)((char*)self + 0x228) == 1) {
        void* buf = *(void**)((char*)self + 0x1D4);
        if (buf != 0) {
            cMemMan_free(buf);
        }
        *(void**)((char*)self + 0x1D4) = 0;
        *(int*)((char*)self + 0x228) = 0;
    }
    void* p = operator_new__FUi(size, D_00467990, 0x100, 0);
    *(void**)((char*)self + 0x1D0) = p;
    *(void**)((char*)self + 0x1D4) = p;
    *(int*)((char*)self + 0x228) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D99C8);
#ifdef SKIP_ASM
extern "C" void* cScreenPopup_cScreenPopup(void* mem, void* engine, void* owner);
extern "C" void func_001D9A80(void* self, int a1, int a2, int a3, int a4, int a5, int a6);
extern char D_0046C890[];
extern int D_004A203C;

struct sMemCardPopupK1D99C8 {
    char pad_0x000[0x8];
    void* vtbl;    // 0x8
    char pad_0x00C[0x14C - 0xC];
    int f14C;      // 0x14C
    char pad_0x150[0x17C - 0x150];
    int f17C;      // 0x17C
};

extern "C" sMemCardPopupK1D99C8* func_001D99C8(sMemCardPopupK1D99C8* self, void* engine, void* owner, int a3, int a4, int a5, int a6, int a7, int a8)
{
    cScreenPopup_cScreenPopup(self, engine, owner);
    self->vtbl = D_0046C890;
    if (D_004A203C == 0) {
        self->f17C = 1;
    } else {
        self->f17C = 2;
        self->f14C = 4;
    }
    func_001D9A80(self, a3, a4, a5, a6, a7, a8);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9A80);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001C57C0(void* self, int a1, int a2);
// PORT: func_001C5DD8 takes only self; the unit's later (void*, int) declaration is a guess. Bound by asm label.
void func_001C5DD8_self(void* self) __asm__("func_001C5DD8");
extern "C" void* func_002C2508(void* dst, void* src);
extern "C" unsigned short* func_002C2540(void*, void*);
extern char D_0045DCC8[];
extern char D_0045FCD8[];
extern char D_004A1408[];

// PORT: the unit declares the string pointer as int; a6 is unused
extern "C" void func_001D9A80(void* self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    void* str = (void*)a1;
    char* s = (char*)self;
    char* sub = s + 0xBC;
    func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
    func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
    *(int*)(s + 0xBC) = 2;
    *(int*)(s + 0x14C) = a4;
    *(int*)(s + 0x168) = 0;
    *(int*)(s + 0x154) = 0;
    *(int*)(s + 0x164) = 0;
    char* p;
    if (str) {
        func_002C2508(s + 0x360, str);
        p = s + 0x360;
    } else {
        p = s + 0x360;
        func_002C2540(p, D_004A1408);
    }
    func_002C2508(p, str);
    if (a3) {
        *(int*)(s + 0xBF8) = 0;
        *(int*)(sub + 0x98) = 1;
        *(int*)(sub + 0) = 0;
    } else if (a2) {
        *(int*)(s + 0xBF8) = 1;
        *(int*)(sub + 0) = 1;
        *(int*)(sub + 0x98) = a5;
    } else {
        *(int*)(s + 0xBF8) = 2;
        *(int*)(sub + 0x98) = a5;
    }
    *(char**)(sub + 8) = p;
    *(int*)(sub + 4) = 1;
    if (*(int*)(s + 0x40)) {
        func_001C5DD8_self(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9BD0);
#ifdef SKIP_ASM
extern "C" void* func_002C2508(void* dst, void* src);
void func_001C57A0(void* slots, int idx, int data);
// PORT: func_001C5DD8 takes only self; the unit's later (void*, int) declaration is a guess. Bound by asm label.
void func_001C5DD8_self(void* self) __asm__("func_001C5DD8");

extern "C" void func_001D9BD0(void* self, void* src, int mode)
{
    void* slots = (char*)self + 0xBC;
    if (mode == 0) {
        void* d = (char*)self + 0x9A0;
        func_002C2508(d, src);
        func_001C57A0(slots, 0, (int)d); // PORT: pointer passed as int
    } else if (mode == 1) {
        if (*(int*)((char*)self + 0xBF8) >= 2) {
            void* d = (char*)self + 0xA68;
            func_002C2508(d, src);
            func_001C57A0(slots, 1, (int)d);
        }
    } else {
        void* d = (char*)self + 0xB30;
        *(int*)((char*)self + 0xBF8) = 3;
        *(int*)((char*)self + 0xBC) = 3;
        func_002C2508(d, src);
        func_001C57A0(slots, 2, (int)d);
    }
    if (*(int*)((char*)self + 0x40) != 0) {
        func_001C5DD8_self(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9CA8);
#ifdef SKIP_ASM
extern "C" int func_002C24D0(void* p);
extern "C" void* func_002C2508(void* dst, void* src);
// PORT: func_001C5DD8 takes only self; the unit's later (void*, int) declaration is a guess. Bound by asm label.
void func_001C5DD8_self(void* self) __asm__("func_001C5DD8");

extern "C" void func_001D9CA8(void* self, void* src)
{
    if (src != 0 && func_002C24D0(src) != 0) {
        void* dst = (char*)self + 0x360;
        func_002C2508(dst, src);
        *(void**)((char*)self + 0xC4) = dst;
        *(int*)((char*)self + 0xC0) = 1;
        if (*(int*)((char*)self + 0x40) != 0) {
            func_001C5DD8_self(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9D18);
#ifdef SKIP_ASM
extern "C" void func_001C5DD8(void*, int);

extern "C" void func_001D9D18(void* self, int a1)
{
    *(int*)((char*)self + 0x168) = a1;
    if (*(int*)((char*)self + 0x40) != 0) {
        func_001C5DD8(self, a1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcardcallbacks", func_001D9D48);
#ifdef SKIP_ASM
extern "C" void* func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_001DA4A8(void* self);
extern char D_0046A618[];

inline void* operator new[](unsigned int, void* p) { return p; }

struct sMcSlot9D48 {
    int v[2];
    sMcSlot9D48() {}
};

extern "C" void* func_001D9D48(void* self, void* engine, void* owner)
{
    func_0039E318(self, engine, owner);
    *(void**)((char*)self + 0x8) = D_0046A618;
    new ((char*)self + 0x54) sMcSlot9D48[7];
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0xC) = 0x4C;
    func_001DA4A8(self);
    return self;
}
#endif

