#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// Declarations shared by the functions of this unit.
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004A2BC8[];
extern char D_004A2BD0[];
extern void* D_004A5B64;
extern "C" int func_002C27C0(char* buf, const char* fmt, ...);
extern "C" void func_003A0E90(void* obj, char* text);
extern "C" void func_0039E390(void *, int);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C11[];
extern unsigned int D_00536640[];
void cUIText_setAsciiString(cUIText* text, const char* str);
extern char D_004A2AC0[];
extern char D_004A2AC8[];
extern char D_004A2AD0[];
extern char D_0047B8F8[];
extern char D_0047B930[];
extern char D_0047B968[];
extern char* D_004A28A8;
extern "C" int func_00146E98(void* iface, int a1);
extern "C" const char* func_0014EE58(void* iface, int a1);
extern "C" int func_00148950(void* iface, int id);
extern "C" void* func_002C2508(void* dst, void* src);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern char D_0047BC80[];
extern "C" void* func_00242EB8(int, int);

//100%
INCLUDE_ASM("fe/festateloadhint", cFELoadHintState_onCreateScreen);
#ifdef SKIP_ASM
extern signed char D_004A2C38;
extern char D_0047BDD8[];
extern char D_0047BDE8[];
extern char D_0047BE00[];
extern char D_0047BE10[];
extern char D_0047BE20[];
extern char D_0047BE30[];

extern "C" void cFELoadHintState_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BDD8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    int n = D_004A2C38 + 1;
    if (n == 12) {
        D_004A2C38++;
        n = D_004A2C38 + 1;
    }
    char title[0x40];
    char body[0x40];
    sprintf(title, D_0047BDE8, n);
    sprintf(body, D_0047BE00, n);
    D_004A2C38 = (D_004A2C38 + 1) % 15;
    cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0047BE10));
    if (text != 0) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(title));
    }
    text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0047BE20));
    if (text != 0) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(body));
    }
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0047BE30));
    if (o != 0) {
        char* p = *(char**)((char*)self + 0x48);
        if (p != 0) {
            int q = *(int*)(p + 0x10);
            if (q != 0) {
                *(int*)(o + 0x78) = q;
                *(int*)(o + 0x7C) = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245AE0);
#ifdef SKIP_ASM
extern "C" int func_00245AE0(void* self)
{
    char buf[200];
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2BC8));
    if (obj != 0) {
        func_002C27C0(buf, D_004A2BD0, (int)*(float*)((char*)D_004A5B64 + 0x38));
        func_003A0E90(obj, buf);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245B50__FPv);
#ifdef SKIP_ASM
void func_00245B50(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245B58);
#ifdef SKIP_ASM
extern void* D_0047C608[];

extern "C" void func_00245B58(void* self, int flags)
{
    *(void**)((char*)self + 0x8) = D_0047C608;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", cFELoadState_onCreateScreen);
#ifdef SKIP_ASM
extern "C" void cFELoadState_InitwidgetMultiP(void* self, int idx);
extern char D_0047BE40[];
extern char D_0047BE50[];

extern "C" void cFELoadState_onCreateScreen(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        void* engine = *(void**)((char*)self + 0x10);
        void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BE40), 0);
        *(void**)((char*)self + 0x40) = screen;
        if (screen != 0) {
            cUIScreen_playFrame(screen, 0, 0);
            cFELoadState_InitwidgetMultiP(self, 0);
            cFELoadState_InitwidgetMultiP(self, 1);
        }
    } else {
        void* engine = *(void**)((char*)self + 0x10);
        void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BE50), 0);
        *(void**)((char*)self + 0x40) = screen;
        if (screen != 0) {
            cUIScreen_playFrame(screen, 0, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245C60);
#ifdef SKIP_ASM
extern "C" int func_00245C60(void* self)
{
    char buf[200];
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2BC8));
    if (obj != 0) {
        func_002C27C0(buf, D_004A2BD0, (int)*(float*)((char*)D_004A5B64 + 0x38));
        func_003A0E90(obj, buf);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245CD0);
#ifdef SKIP_ASM
extern "C" void cFELoadState_widgetCreateQP(void* self, void* widget);

extern "C" void func_00245CD0(void* self, void* widget)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] != 2) {
        cFELoadState_widgetCreateQP(self, widget);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245D28);
#ifdef SKIP_ASM
extern void* D_0047C538[];

extern "C" void func_00245D28(void* self, int flags)
{
    *(void**)((char*)self + 0x8) = D_0047C538;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", cFELoadStateInLodge_onCreateScreen);
#ifdef SKIP_ASM
extern char D_0047BFA0[];

extern "C" void cFELoadStateInLodge_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BFA0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245DB8__FPv);
#ifdef SKIP_ASM
void func_00245DB8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245DC0);
#ifdef SKIP_ASM
extern "C" int func_00245DC0(void* self)
{
    char buf[200];
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2BC8));
    if (obj != 0) {
        func_002C27C0(buf, D_004A2BD0, (int)*(float*)((char*)D_004A5B64 + 0x38));
        func_003A0E90(obj, buf);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245E30);
#ifdef SKIP_ASM
extern "C" int func_00245E30(int* a, int* b)
{
    unsigned int va = D_00536640[*a];
    unsigned int vb = D_00536640[*b];
    if (vb < va) {
        return -1;
    }
    return va != vb;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245E78);
#ifdef SKIP_ASM
extern "C" int func_00245E78(int* a, int* b)
{
    unsigned int va = D_00536640[*a];
    unsigned int vb = D_00536640[*b];
    if (va < vb) {
        return -1;
    }
    return va != vb;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245EC0);
#ifdef SKIP_ASM
extern int D_00536708[];

extern "C" int func_00245EC0(int* a, int* b)
{
    int va = D_00536708[*a];
    int vb = D_00536708[*b];
    if (vb < va) {
        return 1;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245F00);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0047DB28[];

extern "C" void func_00245F00(void* self, int flags)
{
    *(void**)self = D_0047DB28;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245F30__FPv);
#ifdef SKIP_ASM
// func_00245F30 is matched under the C++ symbol func_00245F30__FPv, which fixes its parameters at (void*); the destructor flags pass through in $5.
extern "C" void func_0039E390_noflags(void *) __asm__("func_0039E390");
void func_00245F30(void* self)
{
    func_0039E390_noflags(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00245F50);
#ifdef SKIP_ASM
extern char D_004A2AD8[];

extern "C" void func_00245F50(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A2AD8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2AC0));
    if (text != 0) {
        if (*(signed char*)((char*)self + 0x48) == 0)
            cUIText_setAsciiString(text, D_0047B8F8);
        else
            cUIText_setAsciiString(text, D_0047B930);
    }
    cUIText* text2 = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2AC8));
    if (text2 != 0) {
        cUIText_setUnicodeStringByID(text2, GetHashValue32(D_0047B968));
    }
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2AD0));
    if (o != 0) {
        sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(o + 8);
        vt[9].fn(o + vt[9].delta, 0);
        sVEntry<void(void*, int)>* vt2 = *(sVEntry<void(void*, int)>**)(o + 8);
        vt2[8].fn(o + vt2[8].delta, 1);
    }
    *(int*)((char*)self + 0x4C) = 300;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00246098);
#ifdef SKIP_ASM
extern "C" void func_0039E510(void* self);
extern void* D_004A5B80;

extern "C" void func_00246098(void* self)
{
    if (*(int*)((char*)self + 0x4C) != 0) {
        if (--*(int*)((char*)self + 0x4C) == 0) {
            if (*(signed char*)((char*)self + 0x48) == 0) {
                *(signed char*)((char*)self + 0x48) = 1;
                cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2AC0));
                if (text != 0) {
                    if (*(signed char*)((char*)self + 0x48) == 0)
                        cUIText_setAsciiString(text, D_0047B8F8);
                    else
                        cUIText_setAsciiString(text, D_0047B930);
                }
                cUIText* text2 = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2AC8));
                if (text2 != 0) {
                    cUIText_setUnicodeStringByID(text2, GetHashValue32(D_0047B968));
                }
                char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2AD0));
                if (o != 0) {
                    sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(o + 8);
                    vt[9].fn(o + vt[9].delta, 0);
                    sVEntry<void(void*, int)>* vt2 = *(sVEntry<void(void*, int)>**)(o + 8);
                    vt2[8].fn(o + vt2[8].delta, 1);
                }
                char* g = (char*)D_004A5B80;
                sVEntry<void(void*, int)>* vt3 = *(sVEntry<void(void*, int)>**)(g + 0x10D8);
                vt3[8].fn(g + vt3[8].delta, 0);
            }
        }
    }
    func_0039E510(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_002461E0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00186A08(void* self, void* engine);
extern "C" void func_0039F400(void* list, void* item);
extern char D_0047B978[];

extern "C" void func_002461E0(void* self, void* item, int msg)
{
    if (item != 0) {
        if (msg == 5) {
            int hash = *(int*)((char*)item + 0x38);
            if (hash == GetHashValue32(D_004A2AC8)) {
                void* state = func_00186A08(cMemMan_alloc(0x248, D_0047B978, 0, 0), *(void**)((char*)self + 0x10));
                func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, state);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00246268);
#ifdef SKIP_ASM
extern "C" int func_00246268(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00246278);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" int func_00144C98(void* iface);
extern "C" const char* func_00144BF0(void* iface);
extern signed char D_00535C10[];
extern char D_004A2BD8[];
extern char D_0047BA48[];
extern char D_0047BA58[];
extern char D_0047BA68[];
extern char D_0047BA78[];
extern char D_0047BA88[];
extern char D_0047BAA0[];
extern char D_0047BAB0[];
extern char D_0047BAC0[];
extern char D_0047BAD0[];

static inline int Loc_246278(char* key)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<int(void*, int)>* vt = *(sVEntry<int(void*, int)>**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(key));
}

static inline void Fmt_246278(char* buf, char* fmt, char* key, void* iface)
{
    int str = Loc_246278(key);
    func_002C27C0(buf, fmt, str, func_00144BF0(iface));
}

static inline void Activate_246278(char* obj)
{
    sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(obj + 8);
    vt[9].fn(obj + vt[9].delta, 1);
}

static inline bool IsId_246278(char* obj, char* key)
{
    int id = *(int*)(obj + 0x38);
    return id == GetHashValue32(key);
}

extern "C" void func_00246278(void* self, char* obj)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    if (IsId_246278(obj, D_0047BA48)) {
        char buf[200];
        func_00416210(buf, 0, 200);
        char* fmt = D_004A2BD8;
        switch (func_00144C98(iface)) {
        case 0:
            Fmt_246278(buf, fmt, D_0047BA58, iface);
            break;
        case 1:
            Fmt_246278(buf, fmt, D_0047BA68, iface);
            break;
        case 2:
            Fmt_246278(buf, fmt, D_0047BA78, iface);
            break;
        }
        func_003A0E90(obj, buf);
        return;
    }
    switch (D_00535C10[0]) {
    case 0:
        if (IsId_246278(obj, D_0047BA88)) Activate_246278(obj);
        break;
    case 1:
        if (IsId_246278(obj, D_0047BAA0)) Activate_246278(obj);
        break;
    case 2:
        if (IsId_246278(obj, D_0047BAB0)) Activate_246278(obj);
        break;
    case 3:
        if (IsId_246278(obj, D_0047BAC0)) Activate_246278(obj);
        break;
    case 4:
        if (IsId_246278(obj, D_0047BA88)) Activate_246278(obj);
        break;
    case 5:
        if (IsId_246278(obj, D_0047BAD0)) Activate_246278(obj);
        break;
    case 6:
        if (IsId_246278(obj, D_0047BAD0)) Activate_246278(obj);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_002464E8);
#ifdef SKIP_ASM
extern "C" int func_00144BE0(void* iface);
extern "C" int func_00144D18(void* iface, int idx);
extern signed char D_00535BC8[];
extern char D_0047BB70[];
extern char D_0047BB80[];
extern char D_0047BB98[];
extern char D_0047BBA8[];
extern char D_0047BBB8[];
extern char D_0047BBC8[];
extern char D_004A2BE0[];
extern char D_004A2BE8[];
extern char D_004A2BF0[];
extern char D_004A2BF8[];
extern char D_0047BBD8[];
extern char D_0047BBE8[];
extern char D_004A2C00[];
extern char D_0047BBF8[];
extern char D_0047BC08[];
extern char D_0047BC18[];
extern char D_0047BC30[];
extern char D_0047BC48[];
extern char D_0047BC60[];
extern char D_0047BC70[];
extern char D_004A2C08[];

// 17 per-event values (two rodata tables copied to the stack)
struct sTable17_2464E8 {
    int v[17];
};
extern sTable17_2464E8 D_0047BAE0;
extern sTable17_2464E8 D_0047BB28;

struct sOptTriple_2464E8 {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    int b;
    int c;
};
extern sOptTriple_2464E8 D_005308B8[];

static inline void* Loc_2464E8(char* key)
{
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<void*(void*, int)>* vt = *(sVEntry<void*(void*, int)>**)(o + 4);
    return vt[4].fn(o + vt[4].delta, GetHashValue32(key));
}

static inline bool IsId_2464E8(char* obj, char* key)
{
    int id = *(int*)(obj + 0x38);
    return id == GetHashValue32(key);
}

static inline void Activate_2464E8(char* obj)
{
    sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(obj + 8);
    vt[9].fn(obj + vt[9].delta, 1);
}

static inline void Fmt_2464E8(char* buf, char* fmt, char* key, void* iface)
{
    void* str = Loc_2464E8(key);
    func_002C27C0(buf, fmt, str, func_00144BF0(iface));
}

extern "C" void func_002464E8(void* self, char* obj)
{
    sTable17_2464E8 tA = D_0047BAE0;
    sTable17_2464E8 tB = D_0047BB28;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    char buf[200];
    unsigned short fmtA[100];
    unsigned short fmtB[100];
    if (IsId_2464E8(obj, D_0047BB70)) {
        func_00416210(buf, 0, 200);
        char* fmt = D_004A2BD8;
        switch (func_00144C98(iface)) {
        case 0:
            Fmt_2464E8(buf, fmt, D_0047BA58, iface);
            break;
        case 1:
            Fmt_2464E8(buf, fmt, D_0047BA68, iface);
            break;
        case 2:
            Fmt_2464E8(buf, fmt, D_0047BA78, iface);
            break;
        }
        func_003A0E90(obj, buf);
        return;
    }
    switch (D_00535BC8[0x48]) {
    case 0:
        if (IsId_2464E8(obj, D_0047BB80)) { Activate_2464E8(obj); return; }
        break;
    case 1:
        if (IsId_2464E8(obj, D_0047BB98)) { Activate_2464E8(obj); return; }
        break;
    case 2:
        if (IsId_2464E8(obj, D_0047BBA8)) { Activate_2464E8(obj); return; }
        break;
    case 3:
        if (IsId_2464E8(obj, D_0047BBB8)) { Activate_2464E8(obj); return; }
        break;
    case 4:
        if (IsId_2464E8(obj, D_0047BB80)) { Activate_2464E8(obj); return; }
        break;
    case 5:
        if (IsId_2464E8(obj, D_0047BBC8)) { Activate_2464E8(obj); return; }
        break;
    case 6:
        if (IsId_2464E8(obj, D_0047BBC8)) { Activate_2464E8(obj); return; }
        break;
    }
    switch (D_00535BC8[0x48]) {
    case 0:
        if (IsId_2464E8(obj, D_004A2BE0)) { Activate_2464E8(obj); return; }
        break;
    case 1:
        if (IsId_2464E8(obj, D_004A2BE8)) { Activate_2464E8(obj); return; }
        break;
    case 2:
        if (IsId_2464E8(obj, D_004A2BF0)) { Activate_2464E8(obj); return; }
        break;
    case 3:
        if (IsId_2464E8(obj, D_004A2BF8)) { Activate_2464E8(obj); return; }
        break;
    case 5:
        if (IsId_2464E8(obj, D_0047BBD8)) { Activate_2464E8(obj); return; }
        break;
    case 6:
        if (IsId_2464E8(obj, D_0047BBE8)) { Activate_2464E8(obj); return; }
        break;
    case 7:
        break;
    }
    switch (func_00144D18(iface, func_00144BE0(iface))) {
    case 0:
        if (IsId_2464E8(obj, D_004A2C00)) { Activate_2464E8(obj); return; }
        break;
    case 1:
        if (IsId_2464E8(obj, D_0047BBF8)) { Activate_2464E8(obj); return; }
        break;
    case 2:
        if (IsId_2464E8(obj, D_0047BC08)) { Activate_2464E8(obj); return; }
        break;
    }
    if (IsId_2464E8(obj, D_0047BC18)) {
        func_002C2508(fmtA, Loc_2464E8(D_0047BC30));
        func_002C26D0((unsigned short*)buf, fmtA, tB.v[func_00144BE0(iface)]);
        func_003A0E90(obj, buf);
    } else if (IsId_2464E8(obj, D_0047BC48)) {
        func_002C2508(fmtB, Loc_2464E8(D_0047BC30));
        func_002C26D0((unsigned short*)buf, fmtB, tA.v[func_00144BE0(iface)]);
        func_003A0E90(obj, buf);
    } else if (IsId_2464E8(obj, D_0047BC60)) {
        void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
        void* iface2 = cBE_getInterface_Fv(cBE_getBE(), 2);
        cUIText_setAsciiString((cUIText*)obj, func_0014EE58(iface2, func_00146E98(iface1, 0)));
    } else if (IsId_2464E8(obj, D_0047BC70)) {
        void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
        void* iface3 = cBE_getInterface_Fv(cBE_getBE(), 3);
        func_002C2508(fmtA, Loc_2464E8(D_0047BC80));
        int v = func_00148950(iface3, func_00146E98(iface1, 0));
        int idx = func_00146E98(iface1, 0);
        func_002C26D0((unsigned short*)buf, fmtA, D_005308B8[idx].b1 ? 1 : v);
        func_003A0E90(obj, buf);
    } else if (IsId_2464E8(obj, D_004A2C08)) {
        char* p = *(char**)((char*)self + 0x48);
        if (p != 0) {
            int v = *(int*)(p + 0x10);
            if (v != 0) {
                *(int*)(obj + 0x78) = v;
                *(int*)(obj + 0x7C) = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00246CF8);
#ifdef SKIP_ASM
extern "C" signed char func_00148410(void* self, int rider);
extern "C" signed char func_001484E0(void* self, int rider);
extern "C" signed char func_001485B0(void* self, int rider);
extern "C" signed char func_00148680(void* self, int rider);
extern "C" signed char func_00148750(void* self, int rider);
extern "C" signed char func_00148820(void* self, int rider);
extern "C" signed char func_001488F0(void* self, int rider);
extern "C" void func_0039C428(void* self, int pos);
extern void* D_004A2EB8;
extern char D_004A2C10[];
extern char D_004A2C18[];
extern char D_004A2C20[];
extern char D_004A2C28[];
extern char D_0047BC98[];
extern char D_0047BCA8[];
extern char D_0047BCB8[];
// The network game state (dirtysock/tagsunk sNetState); the unit declares D_00534B30 as int[] below.
struct sNetState_6CF8 {
    int active;                     // 0x000
    int f4;                         // 0x004
    char pad_0x008[0x4A8 - 0x8];
    unsigned char stats[7];         // 0x4A8 (D_00534FD8)
};
extern sNetState_6CF8 D_00534B30_6CF8 __asm__("D_00534B30");
extern unsigned char D_00534FD8[];
// Inline copy of the BE stat-block getter (func_0015C600).
static inline unsigned char* GetStats_6CF8() { return D_00534FD8; }
struct sLoadInfo_6CF8 {
    char pad0[0x10];
    int image[2];                   // 0x10: per-player image
};
// PORT: the widget name templates are splat-named literals; copied from the symbols as char-array structs.
struct sName4_6CF8 { char c[4]; };
struct sName2_6CF8 { char c[2]; };
struct sName5_6CF8 { char c[5]; };

extern "C" void func_00246CF8(void* self, char player)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        sName4_6CF8 statName = *(sName4_6CF8*)D_004A2C10;
        sName2_6CF8 picName = *(sName2_6CF8*)D_004A2C18;
        sName5_6CF8 barName = *(sName5_6CF8*)D_004A2C20;
        int stats[12];                  // 7 used; the frame has room for 12 (buf sits at sp+0x60)
        char buf[0x20];
        unsigned short text[100];
        picName.c[0] = player + '0';
        statName.c[0] = player + '1';
        void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
        int idx = func_00146E98(iface1, player != 0);
        void* iface3 = cBE_getInterface_Fv(cBE_getBE(), 3);
        int rank = func_00148950(iface3, func_00146E98(iface1, player != 0));
        if (D_005308B8[func_00146E98(iface1, player != 0)].b1) {
            rank = 1;
        }
        cBE_getInterface_Fv(*(void**)(D_004A28A8 + 0x78), 7);
        if (D_004A2EB8 != 0 && (player == 1 || D_00534B30_6CF8.f4 != 0)) {
            if (D_00534B30_6CF8.f4 != 0) {
                rank = 8;
                for (int i = 0; i < 7; i++) {
                    stats[i] = 40;
                }
            } else if (D_005308B8[idx].b1) {
                for (int i = 0; i < 7; i++) {
                    stats[i] = 5;
                }
            } else {
                int sum = 0;
                for (int i = 0; i < 7; i++) {
                    sum += D_00534B30_6CF8.stats[i];
                }
                rank = sum / 35;
                unsigned char* s = GetStats_6CF8();
                for (int i = 0; i < 7; i++) {
                    stats[i] = s[i];
                }
            }
        } else {
            if (D_005308B8[idx].b1) {
                for (int i = 0; i < 7; i++) {
                    stats[i] = 5;
                }
            } else {
                stats[0] = func_001484E0(iface3, idx);
                stats[1] = func_00148680(iface3, idx);
                stats[2] = func_00148410(iface3, idx);
                stats[3] = func_00148750(iface3, idx);
                stats[4] = func_001488F0(iface3, idx);
                stats[5] = func_00148820(iface3, idx);
                stats[6] = func_001485B0(iface3, idx);
            }
        }
        // fmt stays in $18 across both GetHashValue32/getObjectByHashName calls: the target computes
        // the full address before the player test (a literal is rematerialised at the sprintf).
        char* fmt = D_004A2C28;
        void* obj;
        if (player == 0) {
            obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0047BC98));
        } else {
            obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0047BCA8));
        }
        sprintf(buf, fmt, rank);
        if (obj != 0) {
            cUIText_setAsciiString((cUIText*)obj, buf);
        }
        for (int i = 0; i < 7; i++) {
            statName.c[2] = i + '0';
            char* label = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(statName.c));
            barName.c[0] = player + '0';
            barName.c[1] = i + '0';
            char* bar = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(barName.c));
            if (label != 0 && bar != 0) {
                int v = stats[i];
                int level = v / 5;
                char* o = *(char**)(D_004A28A8 + 0x8C);
                sVEntry<void*(void*, int)>* vt = *(sVEntry<void*(void*, int)>**)(o + 4);
                func_002C26D0(text, (unsigned short*)vt[4].fn(o + vt[4].delta, GetHashValue32(D_0047BCB8)), level);
                sVEntry<void(void*, int)>* vt2 = *(sVEntry<void(void*, int)>**)(label + 8);
                vt2[9].fn(label + vt2[9].delta, 1);
                func_003A0E90(label, (char*)text);
                *(int*)(bar + 0x80) = 0x37;
                func_0039C428(bar, v);
            }
        }
        char* pic = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(picName.c));
        sLoadInfo_6CF8* p = *(sLoadInfo_6CF8**)((char*)self + 0x48);
        if (p != 0 && pic != 0) {
            int q = p->image[player];
            if (q != 0) {
                *(int*)(pic + 0x78) = q;
                *(int*)(pic + 0x7C) = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", cFELoadState_InitwidgetMultiP);
#ifdef SKIP_ASM
// PORT: the widget name templates are splat-named literals; copied from the symbols as char-array structs.
struct sName19_72C0 { char c[19]; };
struct sName12_72C0 { char c[12]; };
struct sName10_72C0 { char c[10]; };
struct sName8_72C0 { char c[8]; };
struct sName7_72C0 { char c[7]; };
struct sName2_72C0 { char c[2]; };
extern char D_0047BE60[];
extern char D_004A2C40[];
extern char D_004A2C48[];
extern char D_0047BE78[];
extern char D_0047BE88[];
extern char D_004A2C50[];
extern char D_0047BE98[];
extern char D_0047BEA8[];
extern char D_0047BEB8[];
extern char D_004A2C18[];
// PORT: the literal "%d" (strcpy of a constant expands to an aligned 3-byte copy).
extern char D_004A2C28[] __attribute__((aligned(8)));
extern char D_004A2C58[];
extern char D_004A2C60[];
extern int D_00534B30[];
extern int D_00536730[];
extern "C" void* cGameModeMan_getGM();
extern "C" char* func_00155270(void* iface, int a1);
extern "C" unsigned int func_004139F8(float f);
extern "C" char* func_0020A1A8(int v);
extern "C" char* strcpy(char* dst, const char* src);

struct sLoadInfo_72C0 {
    char pad0[0x10];
    int image[2];                   // 0x10: per-player image
};

static inline void Activate_72C0(char* obj)
{
    sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(obj + 8);
    vt[9].fn(obj + vt[9].delta, 1);
}

// The player index is a char parameter (the caller in onCreateScreen declares it int); bound by asm label.
extern "C" void cFELoadState_InitwidgetMultiP_72C0(void* self, char player) __asm__("cFELoadState_InitwidgetMultiP");

extern "C" void cFELoadState_InitwidgetMultiP_72C0(void* self, char player)
{
    sName19_72C0 rankNumName = *(sName19_72C0*)D_0047BE60;
    sName7_72C0 rankName = *(sName7_72C0*)D_004A2C40;
    sName7_72C0 timeName = *(sName7_72C0*)D_004A2C48;
    sName12_72C0 knockdownsName = *(sName12_72C0*)D_0047BE78;
    sName10_72C0 wipeoutsName = *(sName10_72C0*)D_0047BE88;
    sName8_72C0 tricksName = *(sName8_72C0*)D_004A2C50;
    sName12_72C0 handplantsName = *(sName12_72C0*)D_0047BE98;
    sName12_72C0 ubertricksName = *(sName12_72C0*)D_0047BEA8;
    sName12_72C0 ubergrindsName = *(sName12_72C0*)D_0047BEB8;
    char buf[0x20];
    char fmt[0x20];
    char side = player;
    cBE_getInterface_Fv(*(void**)(D_004A28A8 + 0x78), 7);
    if (D_00534B30[2] == 0 && D_00534B30[0] != 0) {
        player = !player;
    }
    if (side == 1) {
        rankNumName.c[0] = '2';
        rankName.c[0] = '2';
        timeName.c[0] = '2';
        knockdownsName.c[0] = '2';
        wipeoutsName.c[0] = '2';
        tricksName.c[0] = '2';
        handplantsName.c[0] = '2';
        ubertricksName.c[0] = '2';
        ubergrindsName.c[0] = '2';
    }
    void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    void* iface3 = cBE_getInterface_Fv(cBE_getBE(), 3);
    cGameModeMan_getGM();
    void* iface8 = cBE_getInterface_Fv(cBE_getBE(), 8);
    char* st = func_00155270(iface8, func_00146E98(iface1, player != 0));
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(rankNumName.c));
    if (obj != 0) {
        __builtin_memcpy(fmt, D_004A2C28, sizeof("%d"));
        sprintf(buf, fmt, D_00536730[player] + 1);
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(rankName.c));
    if (obj != 0) {
        cBE_getInterface_Fv(*(void**)(D_004A28A8 + 0x78), 7);
        int rank;
        if (D_00534B30[0] != 0 && D_00534B30[1] != 0) {
            rank = 8;
        } else {
            rank = func_00148950(iface3, func_00146E98(iface1, player != 0));
        }
        unsigned short fmtw[50];
        unsigned short text[100];
        char* o = *(char**)(D_004A28A8 + 0x8C);
        sVEntry<void*(void*, int)>* vt = *(sVEntry<void*(void*, int)>**)(o + 4);
        func_002C2508(fmtw, vt[4].fn(o + vt[4].delta, GetHashValue32(D_0047BC80)));
        func_002C26D0(text, fmtw, rank);
        func_003A0E90(obj, (char*)text);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(timeName.c));
    if (obj != 0) {
        if (D_00535C10[0] == 0 || D_00535C10[0] == 5) {
            int i = func_00146E98(iface1, player != 0);
            unsigned int t = func_004139F8((float)D_00536640[i] * (1.0f / 60.0f));
            char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2C58));
            if (o != 0) {
                Activate_72C0(o);
            }
            strcpy(buf, func_0020A1A8(t));
        } else {
            int i = func_00146E98(iface1, player != 0);
            unsigned int score = D_00536640[i];
            char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2C60));
            if (o != 0) {
                Activate_72C0(o);
            }
            sprintf(buf, D_004A2C28, score);
        }
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(knockdownsName.c));
    if (obj != 0) {
        __builtin_memcpy(fmt, D_004A2C28, sizeof("%d"));
        sprintf(buf, fmt, *(int*)(st + 0x2C));
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(wipeoutsName.c));
    if (obj != 0) {
        __builtin_memcpy(fmt, D_004A2C28, sizeof("%d"));
        sprintf(buf, fmt, *(int*)(st + 0x28));
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(tricksName.c));
    if (obj != 0) {
        __builtin_memcpy(fmt, D_004A2C28, sizeof("%d"));
        sprintf(buf, fmt, *(int*)(st + 0x14));
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(handplantsName.c));
    if (obj != 0) {
        __builtin_memcpy(fmt, D_004A2C28, sizeof("%d"));
        sprintf(buf, fmt, *(int*)(st + 0xC));
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(ubertricksName.c));
    if (obj != 0) {
        __builtin_memcpy(fmt, D_004A2C28, sizeof("%d"));
        sprintf(buf, fmt, *(int*)(st + 0x18));
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(ubergrindsName.c));
    if (obj != 0) {
        __builtin_memcpy(fmt, D_004A2C28, sizeof("%d"));
        sprintf(buf, fmt, *(int*)(st + 0x20));
        cUIText_setAsciiString((cUIText*)obj, buf);
    }
    sName2_72C0 picName = *(sName2_72C0*)D_004A2C18;
    picName.c[0] = side + '0';
    char* pic = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(picName.c));
    sLoadInfo_72C0* p = *(sLoadInfo_72C0**)((char*)self + 0x48);
    if (p != 0 && pic != 0) {
        int q = p->image[player];
        if (q != 0) {
            *(int*)(pic + 0x78) = q;
            *(int*)(pic + 0x7C) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", cFELoadState_widgetCreateQP);
#ifdef SKIP_ASM
extern "C" char* func_00155270(void* iface, int a1);
extern "C" unsigned short* func_002C2540(void* dst, const char* s);
extern "C" double func_00413AF8(float f);
extern char D_004A2C28[];
extern char D_0047BEC8[];
extern char D_0047BED8[];
extern char D_0047BEE8[];
extern char D_0047BF00[];
extern char D_0047BF18[];
extern char D_0047BF30[];
extern char D_0047BF48[];
extern char D_0047BF60[];
extern char D_0047BF88[];
// PORT: the literal "%02.0f:%02.0f" (strcpy of a constant expands to an aligned 14-byte copy);
// splat names it, so copy from the symbol with the literal's length and rodata alignment.
extern char D_0047BF78[] __attribute__((aligned(8)));

static inline int wHash_7AB0(char* w) { return *(int*)(w + 0x38); }

extern "C" void cFELoadState_widgetCreateQP(void* self, void* widget)
{
    char* w = (char*)widget;
    void* iface1 = cBE_getInterface_Fv(cBE_getBE(), 1);
    void* iface2 = cBE_getInterface_Fv(cBE_getBE(), 2);
    void* iface3 = cBE_getInterface_Fv(cBE_getBE(), 3);
    void* iface8 = cBE_getInterface_Fv(cBE_getBE(), 8);
    char* st = func_00155270(iface8, func_00146E98(iface1, 0));
    unsigned short text[0x18];
    unsigned short fmtw[0x20];
    if (wHash_7AB0(w) == GetHashValue32(D_0047BEC8)) {
        func_002C2540(text, func_0014EE58(iface2, func_00146E98(iface1, 0)));
        func_003A0E90(widget, (char*)text);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BED8)) {
        char* o = *(char**)(D_004A28A8 + 0x8C);
        sVEntry<void*(void*, int)>* vt = *(sVEntry<void*(void*, int)>**)(o + 4);
        func_002C2508(fmtw, vt[4].fn(o + vt[4].delta, GetHashValue32(D_0047BC80)));
        func_002C26D0(text, fmtw, func_00148950(iface3, func_00146E98(iface1, 0)));
        func_003A0E90(widget, (char*)text);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BEE8)) {
        func_002C2540(fmtw, D_004A2C28);
        func_002C26D0(text, fmtw, *(int*)(st + 0x2C));
        func_003A0E90(widget, (char*)text);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BF00)) {
        func_002C2540(fmtw, D_004A2C28);
        func_002C26D0(text, fmtw, *(int*)(st + 0x28));
        func_003A0E90(widget, (char*)text);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BF18)) {
        func_002C2540(fmtw, D_004A2C28);
        func_002C26D0(text, fmtw, *(int*)(st + 0x18));
        func_003A0E90(widget, (char*)text);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BF30)) {
        func_002C2540(fmtw, D_004A2C28);
        func_002C26D0(text, fmtw, *(int*)(st + 0x20));
        func_003A0E90(widget, (char*)text);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BF48)) {
        func_002C2540(fmtw, D_004A2C28);
        func_002C26D0(text, fmtw, *(int*)(st + 0xC));
        func_003A0E90(widget, (char*)text);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BF60)) {
        int t = (int)*(float*)(st + 0x48);
        int min = t / 60;
        int sec = t % 60;
        char fmt[0x20];
        char buf[0x20];
        __builtin_memcpy(fmt, D_0047BF78, sizeof("%02.0f:%02.0f"));
        sprintf(buf, fmt, func_00413AF8((float)min), func_00413AF8((float)sec));
        cUIText_setAsciiString((cUIText*)widget, buf);
    } else if (wHash_7AB0(w) == GetHashValue32(D_0047BF88)) {
        func_002C2540(fmtw, D_004A2C28);
        func_002C26D0(text, fmtw, *(int*)(st + 0x88));
        func_003A0E90(widget, (char*)text);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00247E20__FPv);
#ifdef SKIP_ASM
void* func_00247E20(void* self)
{
    return func_00242EB8(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("fe/festateloadhint", func_00247E40__FPv);
#ifdef SKIP_ASM
void* func_00247E40(void* self)
{
    return func_00242EB8(0, 0xffff);
}
#endif

