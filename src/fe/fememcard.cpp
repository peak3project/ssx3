#include "common.h"

//100%
INCLUDE_ASM("fe/fememcard", cFEStateMemCard_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0045DC70[];
extern char D_0045DC80[];
extern void* D_004A28A8;
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* func_00227F80(void* p);

class cUIObjK186B50 {
public:
    char pad_0x00[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int);
};

extern "C" void cFEStateMemCard_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DC70), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_00227F80(D_004A28A8);
    ((cUIObjK186B50*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DC80)))->v09(0);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00186BF0);
#ifdef SKIP_ASM
extern char D_004A14C0[];
extern "C" void func_001D8DE0(void* self);
extern "C" int func_0023C898(void* mp);
extern "C" void func_0039FD38(void* obj);

class cUIObjK186BF0 {
public:
    char pad_0x000[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int);
};

extern "C" void func_00186BF0(void* self)
{
    func_001D8DE0(self);
    if (func_0023C898(func_00227F80(D_004A28A8)) != 0 || *(int*)((char*)self + 0x1C0) == 6) {
        void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A14C0));
        if (obj != 0) {
            func_0039FD38(obj);
        }
        ((cUIObjK186BF0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DC80)))->v09(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00186C98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0045DC90[];
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);

class cUIObjK186C98 {
public:
    char pad_0x000[0x4];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int v04(int hash);
};

class cFEMemCardStateK186C98 {
public:
    char pad_0x000[0x8];
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
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36(void* buf, int a, int b, int c, int d, int e);
};
extern cFEMemCardStateK186C98* D_004A14B8_K186C98 __asm__("D_004A14B8");

struct sVtEntK186C98 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

struct sLocalK186C98 {
    int v[8];
};

extern "C" void func_00186C98(void)
{
    unsigned short buf[0x320];
    sLocalK186C98 loc;
    void* mp = func_00227F80(D_004A28A8);
    func_00241DC8(mp, &loc, *(int*)((char*)mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVtEntK186C98* vt = *(sVtEntK186C98**)(o + 4);
    unsigned short* r = vt[4].fn(o + vt[4].delta, GetHashValue32(D_0045DC90));
    func_002C26D0(buf, r, &loc);
    cFEMemCardStateK186C98* st = D_004A14B8_K186C98;
    *(int*)((char*)st + 0x19C) = 4;
    st->v36(buf, 1, 1, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00186D60);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00152BA8();
extern char D_0045DCA8[];
extern char D_0045DCC8[];
extern char D_0045DCD8[];
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
// Typed view of D_004A14B8 (other functions in this unit declare it as void*).
extern char* D_004A14B8_86D60 __asm__("D_004A14B8");

struct sVtI_86D60 { short delta; short index; int (*fn)(void*, int); };
struct sVtS_86D60 { short delta; short index; unsigned short* (*fn)(void*, int); };
struct sVtB_86D60 { short delta; short index; void (*fn)(void*, void*, int, int, int, int, int); };
struct sVtW_86D60 { short delta; short index; void (*fn)(void*, unsigned short*, int); };
struct sVtV_86D60 { short delta; short index; void (*fn)(void*, int); };
struct sLocal_86D60 { int v[8]; };

extern "C" void func_00186D60(void)
{
    sLocal_86D60 loc;
    unsigned short buf[0x320];
    void* mp = func_00227F80(D_004A28A8);
    func_00241DC8(mp, &loc, *(int*)((char*)mp + 0x428));
    cBE_getInterface_Fv(cBE_getBE(), 5);
    char* o = *(char**)((char*)mp + 0x434);
    sVtI_86D60* vt = *(sVtI_86D60**)o;
    o += vt[22].delta;
    int need = vt[22].fn(o, func_00152BA8());
    unsigned short* b = buf;
    char* lo = *(char**)((char*)D_004A28A8 + 0x8C);
    sVtS_86D60* lvt = *(sVtS_86D60**)(lo + 4);
    lo += lvt[4].delta;
    unsigned short* fmt = lvt[4].fn(lo, GetHashValue32(D_0045DCA8));
    func_002C26D0(b, fmt, &loc, need);
    char* st = D_004A14B8_86D60;
    *(int*)(st + 0x19C) = 9;
    sVtB_86D60* svt = *(sVtB_86D60**)(st + 8);
    svt[36].fn(st + svt[36].delta, b, 0, 0, 0, 0, 0);

    {
        char* w = *(char**)(D_004A14B8_86D60 + 0x218);
        char* lo2 = *(char**)((char*)D_004A28A8 + 0x8C);
        sVtW_86D60* wvt = *(sVtW_86D60**)(w + 8);
        sVtS_86D60* lvt2 = *(sVtS_86D60**)(lo2 + 4);
        w += wvt[26].delta;
        lo2 += lvt2[4].delta;
        wvt[26].fn(w, lvt2[4].fn(lo2, GetHashValue32(D_0045DCC8)), 0);
    }
    {
        char* w = *(char**)(D_004A14B8_86D60 + 0x218);
        char* lo2 = *(char**)((char*)D_004A28A8 + 0x8C);
        sVtW_86D60* wvt = *(sVtW_86D60**)(w + 8);
        sVtS_86D60* lvt2 = *(sVtS_86D60**)(lo2 + 4);
        w += wvt[26].delta;
        lo2 += lvt2[4].delta;
        wvt[26].fn(w, lvt2[4].fn(lo2, GetHashValue32(D_0045DCD8)), 1);
    }
    char* w2 = *(char**)(D_004A14B8_86D60 + 0x218);
    sVtV_86D60* vvt = *(sVtV_86D60**)(w2 + 8);
    vvt[25].fn(w2 + vvt[25].delta, 1);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00186F40);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A14BC;
extern "C" void* func_00227F80(void* p);
extern "C" int func_0023C8D0(void* game);

extern "C" bool func_00186F40(void)
{
    void* game = func_00227F80(D_004A28A8);
    if (D_004A14BC >= 4) {
        if (func_0023C8D0(game)) {
            return true;
        }
    }
    return false;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00186F90);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00152BA8();
struct sFEMemCardK187270;
extern "C" void func_00187270(sFEMemCardK187270* self);
extern "C" void* func_00227F80(void* p);
extern "C" int func_0023C8D0(void* mp);
extern "C" int func_002419D8(void* mp, int card);
extern void* D_004A28A8;
// Typed view of D_004A14B8 (other functions in this unit declare it as void*).
extern char* D_004A14B8_86F90 __asm__("D_004A14B8");
extern int D_004A14BC;

struct sVtA_86F90 { short delta; short index; void (*fn)(void*, int, void*); };
struct sVtI_86F90 { short delta; short index; int (*fn)(void*, int); };
struct sVtV_86F90 { short delta; short index; void (*fn)(void*, int); };
struct sVt0_86F90 { short delta; short index; int (*fn)(void*); };

extern "C" void func_00186F90(void)
{
    if (*(int*)(D_004A14B8_86F90 + 0x234) != 0) {
        if (D_004A14BC < 4)
            return;
        char* mp = (char*)func_00227F80(D_004A28A8);
        char* o = *(char**)(mp + 0x434);
        sVtA_86F90* vt = *(sVtA_86F90**)o;
        vt[14].fn(o + vt[14].delta, *(int*)(mp + 0xF8), D_004A14B8_86F90 + 0x9C);
        return;
    }
    char* mp = (char*)func_00227F80(D_004A28A8);
    if (func_0023C8D0(mp) == 0) {
        int fail = 0;
        cBE_getInterface_Fv(cBE_getBE(), 5);
        int extra = 0;
        int avail = func_002419D8(mp, *(int*)(mp + 0x428));
        char* st = D_004A14B8_86F90;
        int flags = *(int*)(st + 0x22C);
        *(int*)(st + 0x230) = 0;
        if (flags & 1) {
            extra = 1;
            char* o = *(char**)(mp + 0x434);
            sVtI_86F90* vt = *(sVtI_86F90**)o;
            char* thisp = o + vt[22].delta;
            int r = vt[22].fn(thisp, func_00152BA8());
            *(int*)(D_004A14B8_86F90 + 0x230) += r;
        }
        char* o;
        if (avail < *(int*)(D_004A14B8_86F90 + 0x230)
            || ((o = *(char**)(mp + 0x434), (*(sVt0_86F90**)o)[25].fn(o + (*(sVt0_86F90**)o)[25].delta) != -1)
                && (o = *(char**)(mp + 0x434), (*(sVt0_86F90**)o)[25].fn(o + (*(sVt0_86F90**)o)[25].delta) < extra)))
            fail = 1;
        if (fail) {
            *(int*)(D_004A14B8_86F90 + 0x234) = 1;
            sVtV_86F90* vt = *(sVtV_86F90**)(mp + 0x748);
            vt[1].fn(mp + vt[1].delta, 0x17);
            return;
        }
    }
    func_00187270((sFEMemCardK187270*)D_004A14B8_86F90);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187148);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cFEMemCardStateK187148 {
public:
    char pad_0x000[0x8];
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
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
};
// Typed view of D_004A14B8 (other functions in this unit declare it as void*).
extern cFEMemCardStateK187148* D_004A14B8_K187148 __asm__("D_004A14B8");

extern "C" void func_00187148(void)
{
    D_004A14B8_K187148->v41();
    *(int*)((char*)D_004A14B8_K187148 + 0x1C0) = 6;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187180);
#ifdef SKIP_ASM
extern void* D_004A14B8;
extern "C" void func_001D83A8(void);
extern "C" void func_00187A38(void* self);

extern "C" void func_00187180(void)
{
    func_001D83A8();
    func_00187A38(D_004A14B8);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_001871A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
struct sFEMemCardK1871A8 {
    char pad_0x000[0x1BC];
    int state;     // 0x1BC
    char pad_0x1C0[0x22C - 0x1C0];
    int f22C;      // 0x22C
    int pad_0x230;
    int f234;      // 0x234
};
// Typed view of D_004A14B8 (other functions in this unit declare it as void*).
extern sFEMemCardK1871A8* D_004A14B8_K1871A8 __asm__("D_004A14B8");
extern int D_004A14BC;
extern "C" void* func_00227F80(void* p);
void func_0023FB18(void* mp, int a);
extern "C" void func_0023FAE0(void* mp);
extern "C" void func_0023C8F0(void* mp, int mode);

class cMoviePlayerK1871A8 {
public:
    char pad_0x000[0x748];
    virtual void v01(int);
};

extern "C" void func_001871A8(void)
{
    cMoviePlayerK1871A8* mp = (cMoviePlayerK1871A8*)func_00227F80(D_004A28A8);
    func_0023FB18(mp, 0);
    func_0023FAE0(mp);
    mp->v01(0x36);
    D_004A14BC = 0;
    D_004A14B8_K1871A8->f22C = -1;
    D_004A14B8_K1871A8->f234 = 0;
    func_0023C8F0(mp, 2);
    D_004A14B8_K1871A8->state = 2;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187230);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern int D_004A14BC;
struct sFEMemCardK187230 {
    char pad_0x000[0x22C];
    int f22C;      // 0x22C
    int pad_0x230;
    int f234;      // 0x234
};
// Typed view of D_004A14B8 (other functions in this unit declare it as void*).
extern sFEMemCardK187230* D_004A14B8_K187230 __asm__("D_004A14B8");
extern "C" void* func_00227F80(void* p);
extern "C" void func_0023C8F0(void* mp, int mode);

extern "C" void func_00187230(void)
{
    void* mp = func_00227F80(D_004A28A8);
    D_004A14BC = 0;
    D_004A14B8_K187230->f22C = -1;
    D_004A14B8_K187230->f234 = 0;
    func_0023C8F0(mp, 2);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187270);
#ifdef SKIP_ASM
extern "C" void func_00187318(void* self);
extern "C" void func_001877B0(void);
extern "C" void func_00187920(void);

struct sFEMemCardK187270 {
    char pad_0x000[0x234];
    int f234;      // 0x234
    int flags;     // 0x238
};

extern "C" void func_00187270(sFEMemCardK187270* self)
{
    self->f234 = 1;
    void* mp = func_00227F80(D_004A28A8);
    int flags = self->flags;
    if (!(flags & 2)) {
        func_0023FB18(mp, 0);
        func_0023FAE0(mp);
        func_00187920();
    } else if (!(flags & 1)) {
        func_0023FB18(mp, 0);
        func_0023FAE0(mp);
        func_001877B0();
    } else {
        func_00187318(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187318);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void func_00228238(void* p);

extern "C" void func_00187318(void* self)
{
    *(int*)((char*)self + 0x1C0) = 6;
    if (*(int*)((char*)self + 0x1AC) == 0)
        func_00228238(D_004A28A8);
    *(int*)((char*)self + 0x1AC) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187360);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern void* D_004A14B8;
extern char D_0045DCE8[];
extern char D_0045DCD8[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00152BA8();
extern "C" void* func_00227F80(void* p);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);

struct sVtI_00187360 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sVtS_00187360 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

struct sVtB_00187360 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

struct sVtV_00187360 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sLocal_00187360 {
    int v[8];
};

extern "C" void func_00187360(void)
{
    unsigned short buf[0x320];
    sLocal_00187360 loc;
    void* mp = func_00227F80(D_004A28A8);
    cBE_getInterface_Fv(cBE_getBE(), 5);
    *(int*)((char*)D_004A14B8 + 0x19C) = 0x14;
    char* sf = *(char**)((char*)mp + 0x434);
    sVtI_00187360* sfvt = *(sVtI_00187360**)sf;
    int size = sfvt[22].fn(sf + sfvt[22].delta, func_00152BA8());
    func_00241DC8(mp, &loc, *(int*)((char*)mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVtS_00187360* vt = *(sVtS_00187360**)(o + 4);
    unsigned short* fmt = vt[4].fn(o + vt[4].delta, GetHashValue32(D_0045DCE8));
    func_002C26D0(buf, fmt, &loc, size);
    D_004A14B8_K186C98->v36(buf, 0, 0, 0, 0, 0);
    char* box = *(char**)((char*)D_004A14B8 + 0x218);
    sVtB_00187360* bvt = *(sVtB_00187360**)(box + 8);
    char* bthis = box + bvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVtI_00187360* vt2 = *(sVtI_00187360**)(o2 + 4);
    char* o2this = o2 + vt2[4].delta;
    int id = vt2[4].fn(o2this, GetHashValue32(D_0045DCD8));
    bvt[26].fn(bthis, id, 1);
    char* box2 = *(char**)((char*)D_004A14B8 + 0x218);
    sVtV_00187360* bvt2 = *(sVtV_00187360**)(box2 + 8);
    bvt2[25].fn(box2 + bvt2[25].delta, 1);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_001874E8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A14BC;
extern "C" void* func_00227F80(void* p);
extern "C" void func_0023FB58(void* mp);
extern "C" void func_001877B0(void);
extern "C" void func_00187318(void* self);

static inline int moviePlaying_K1874E8(void* mp)
{
    int r = 0;
    if (*(int*)((char*)mp + 0x440) == 0)
        r = *(int*)((char*)mp + 0x43C) != 0;
    return r;
}

extern "C" void func_001874E8(void* self)
{
    if (*(int*)((char*)self + 0x1AC) != 0)
        return;
    void* mp = func_00227F80(D_004A28A8);
    if (moviePlaying_K1874E8(mp))
        return;
    if (D_004A14BC == 4 && ((*(int*)((char*)self + 0x238) ^ 1) & 1)) {
        func_0023FB58(mp);
        func_001877B0();
        return;
    }
    func_00187318(self);
}
#endif

INCLUDE_ASM("fe/fememcard", func_00187580);

//100%
INCLUDE_ASM("fe/fememcard", func_001876A8);
#ifdef SKIP_ASM
extern void* D_004A14B8;
extern "C" void func_00241E18(void*, unsigned short*, int);
extern "C" void func_003A0D00(void* self, unsigned short* str);

struct sVtEntK1876A8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001876A8(void)
{
    void* st = D_004A14B8;
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)st + 0x40), GetHashValue32(D_0045DC80));
    void* mp = func_00227F80(D_004A28A8);
    int e = *(int*)((char*)mp + 0x130);
    if (e == 0x1F || e == 0x21 || e == 0x20 || e == 0x22 || e == 0x31 || e == 0x32 || e == 0x33
        || e == 0x35 || e == 0x36 || e == 0x34 || e == 2 || e == 3 || e == 6) {
        unsigned short buf[0x320];
        func_00241E18(mp, buf, 0x320);
        func_003A0D00(obj, buf);
        sVtEntK1876A8* vt = *(sVtEntK1876A8**)((char*)obj + 8);
        vt[9].fn((char*)obj + vt[9].delta, 1);
    } else {
        sVtEntK1876A8* vt = *(sVtEntK1876A8**)((char*)obj + 8);
        vt[9].fn((char*)obj + vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_001877B0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern void* D_004A14B8;
extern int D_004A14BC;
extern int D_004A14B4;
extern char D_004A14C0[];
extern char D_004A14C8[];
extern char D_0045DD00[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00152BA8();
extern "C" void* func_00227F80(void* p);
extern "C" void func_0023CAA0(void* mp, int a);
extern "C" void func_0023C8F0(void* mp, int mode);
extern "C" void func_002C2540(void*, void*);
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_00241D40_r(void* self, int mode, void* buf, int size) __asm__("func_00241D40");
extern "C" void func_00241AA0_r(void* buf, int size) __asm__("func_00241AA0");
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" void* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* cUIAnimationBank_getAnimationByHashName(void* bank, int hash);
extern "C" void func_0039FCC8(void* obj, void* anim, int a, int b, int c);
extern "C" void func_001D9308(void*, int);

struct sVtEnt_001877B0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001877B0(void)
{
    unsigned short name[0x14];
    unsigned short desc[0x10];
    unsigned short fmt[8];
    int five = 5;
    D_004A14BC = five;
    *(int*)((char*)D_004A14B8 + 0x1C0) = five;
    cBE_getInterface_Fv(cBE_getBE(), 5);
    void* mp = func_00227F80(D_004A28A8);
    *(int*)((char*)D_004A14B8 + 0x1BC) = 0;
    D_004A14BC = five;
    func_0023CAA0(mp, func_00152BA8());
    func_0023C8F0(mp, 1);
    void* s1 = D_004A14B8;
    int t = D_004A14B4;
    *(int*)((char*)mp + 0xF8) = t;
    *(int*)((char*)s1 + 0x1C4) = t;
    *(int*)((char*)s1 + 0x1BC) = 0;
    sVtEnt_001877B0* vt = *(sVtEnt_001877B0**)((char*)mp + 0x748);
    vt[1].fn((char*)mp + vt[1].delta, 0x35);
    func_00241D40_r(mp, 1, name, 0x14);
    func_002C2540(fmt, D_004A14C8);
    func_00241AA0_r(desc, 0x10);
    func_002C26D0((unsigned short*)((char*)D_004A14B8 + 0x11C), fmt, desc, name);
    func_001D9308(D_004A14B8, 1);
    void* st = D_004A14B8;
    *(int*)((char*)st + 0x1A8) = 1;
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)st + 0x40), GetHashValue32(D_004A14C0));
    if (obj) {
        void* bank = (char*)*(void**)((char*)D_004A14B8 + 0x10) + 0x50;
        void* anim = cUIAnimationBank_getAnimationByHashName(bank, GetHashValue32(D_0045DD00));
        if (anim)
            func_0039FCC8(obj, anim, 9, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187920);
#ifdef SKIP_ASM
extern char D_0045DD00[];
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_00152948__FPv ignores its argument; this caller passes none.
int func_00152948_K187920() __asm__("func_00152948__FPv");
extern "C" void func_0023CAA0(void* mp, int a);
extern "C" void* cUIAnimationBank_getAnimationByHashName(void* bank, int hash);
extern "C" void func_0039FCC8(void* obj, void* anim, int a, int b, int c);
extern "C" void func_001D9308(void*, int);

struct sVtEntK187920 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00187920(void)
{
    int two = 2;
    D_004A14BC = 4;
    *(int*)((char*)D_004A14B8 + 0x1C0) = 5;
    cBE_getInterface_Fv(cBE_getBE(), 5);
    void* mp = func_00227F80(D_004A28A8);
    void* s1 = D_004A14B8;
    *(int*)((char*)s1 + 0x1BC) = two;
    *(int*)((char*)s1 + 0x1C4) = 0;
    func_0023CAA0(mp, func_00152948_K187920());
    func_0023C8F0(mp, 2);
    sVtEntK187920* vt = *(sVtEntK187920**)((char*)mp + 0x748);
    vt[1].fn((char*)mp + vt[1].delta, 0x35);
    void* st = D_004A14B8;
    *(int*)((char*)st + 0x1BC) = two;
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)st + 0x40), GetHashValue32(D_004A14C0));
    if (obj) {
        void* bank = (char*)*(void**)((char*)D_004A14B8 + 0x10) + 0x50;
        void* anim = cUIAnimationBank_getAnimationByHashName(bank, GetHashValue32(D_0045DD00));
        if (anim)
            func_0039FCC8(obj, anim, 9, 0, 0);
    }
    func_001D9308(D_004A14B8, 1);
    *(int*)((char*)D_004A14B8 + 0x1A8) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187A38);
#ifdef SKIP_ASM
extern "C" void* func_00227F80(void* p);
extern "C" int func_0023C8D0(void* mp);
extern "C" void func_0023C8F0(void* mp, int mode);
extern void* D_004A28A8;
extern int D_004A14BC;
extern int D_004A14B4;

struct sVt0_87A38 { short delta; short index; int (*fn)(void*); };
struct sVtV_87A38 { short delta; short index; void (*fn)(void*, int); };
struct sMcFlags_87A38 { unsigned b0 : 1; unsigned b1 : 1; unsigned b2 : 1; unsigned rest : 29; };
struct sMemCard_87A38 {
    char pad0[0x1BC];
    int f1BC;                   // 0x1BC
    char pad1C0[0x22C - 0x1C0];
    sMcFlags_87A38 flags;       // 0x22C
    int f230;
    int f234;                   // 0x234
    sMcFlags_87A38 saved;       // 0x238
};

static inline int cardCall_87A38(char* o, int slot)
{
    sVt0_87A38* vt = *(sVt0_87A38**)o;
    return vt[slot].fn(o + vt[slot].delta);
}

static inline void mpNotify_87A38(char* mp, int msg)
{
    sVtV_87A38* vt = *(sVtV_87A38**)(mp + 0x748);
    vt[1].fn(mp + vt[1].delta, msg);
}

extern "C" void func_00187A38(void* p)
{
    sMemCard_87A38* self = (sMemCard_87A38*)p;
    char* mp = (char*)func_00227F80(D_004A28A8);
    char* card = *(char**)(mp + 0x434);
    if (func_0023C8D0(mp))
        D_004A14BC = 3;
    switch (D_004A14BC) {
    case 0:
        if (cardCall_87A38(card, 13))
            self->flags.b1 = 0;
        func_0023C8F0(mp, 1);
        mpNotify_87A38(mp, 0x33);
        D_004A14BC++;
        self->f1BC = 0;
        break;
    case 1:
        if (cardCall_87A38(card, 13))
            self->flags.b0 = 0;
        if (*(int*)(mp + 0x428) == 0) {
            int r = cardCall_87A38(*(char**)(mp + 0x434), 17);
            D_004A14B4 = r;
            if (r == -1)
                D_004A14B4 = 0;
        }
        func_0023C8F0(mp, 0);
        mpNotify_87A38(mp, 0x33);
        D_004A14BC++;
        self->f1BC = 1;
        break;
    case 2:
        if (cardCall_87A38(card, 13))
            self->flags.b2 = 0;
        D_004A14BC++;
    case 3:
        if (*(int*)(mp + 0x428) == 0)
            self->saved = self->flags;
        self->f234 = 0;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187C10__FPv);
#ifdef SKIP_ASM
int func_00187C10(void* self)
{
    return 0;
}
#endif

INCLUDE_ASM("fe/fememcard", func_00187C18);

