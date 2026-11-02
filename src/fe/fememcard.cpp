#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// A UI widget as cUIScreen_getObjectByHashName returns it: vptr at 0x8. Slot names from the prototype's
// _vt$8cUIThing (as in fe/feasyncfile).
class cUIThing {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void setEnabled(int on);
    virtual void setFocus(int on);
    virtual void setStatic(int on);
    virtual void setVisible(int on);
};

// A UI state as these functions see it: vptr at 0x8 (cUIState in fe/feasyncfile). onPopupEvent (17) and
// onWidgetCreate (18) are named after the prototype's _vt$8cUIState; the FE states' own slots past it are known only
// by position.
class cUIState {
public:
    char pad[0x8];
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
    virtual void onPopupEvent(void* popup, int msg);
    virtual void onWidgetCreate(void* widget);
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
};

// Card-check result bits (cFEStateMemCard + 0x22C, saved copy at + 0x238): func_00187A38 clears one per check.
struct sMemCardBits {
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned rest : 29;
};
union uMemCardFlags {
    int all;
    sMemCardBits bits;
};

// The memory-card FE state (class name from the RTTI vtable list; the singleton is D_004A14B8).
class cFEStateMemCard : public cUIState {
public:
    char pad_0x00C[0x10 - 0xC];
    void* engine;                  // 0x10
    char pad_0x014[0x40 - 0x14];
    void* screen;                  // 0x40
    char pad_0x044[0x9C - 0x44];
    char f09C[0x11C - 0x9C];       // 0x9C
    unsigned short text[0x40];     // 0x11C
    int f19C;                      // 0x19C
    char pad_0x1A0[0x1A8 - 0x1A0];
    int f1A8;                      // 0x1A8
    int f1AC;                      // 0x1AC
    char pad_0x1B0[0x1BC - 0x1B0];
    int state;                     // 0x1BC
    int f1C0;                      // 0x1C0
    int f1C4;                      // 0x1C4
    char pad_0x1C8[0x218 - 0x1C8];
    char* box;                     // 0x218
    char pad_0x21C[0x22C - 0x21C];
    uMemCardFlags flags;           // 0x22C
    int needed;                    // 0x230
    int f234;                      // 0x234
    uMemCardFlags saved;           // 0x238
};
extern cFEStateMemCard* D_004A14B8;

// 32-byte text block func_00241DC8 fills for the card in a slot (passed on to the string formatter).
struct sCardText {
    int v[8];
};

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

extern "C" void cFEStateMemCard_onCreateScreen(cFEStateMemCard* self)
{
    void* engine = self->engine;
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DC70), 0);
    self->screen = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_00227F80(D_004A28A8);
    ((cUIThing*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_0045DC80)))->setVisible(0);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00186BF0);
#ifdef SKIP_ASM
extern char D_004A14C0[];
extern "C" void func_001D8DE0(void* self);
extern "C" int func_0023C898(void* mp);
extern "C" void func_0039FD38(void* obj);

extern "C" void func_00186BF0(cFEStateMemCard* self)
{
    func_001D8DE0(self);
    if (func_0023C898(func_00227F80(D_004A28A8)) != 0 || self->f1C0 == 6) {
        void* obj = cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A14C0));
        if (obj != 0) {
            func_0039FD38(obj);
        }
        ((cUIThing*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_0045DC80)))->setVisible(0);
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

extern "C" void func_00186C98(void)
{
    unsigned short buf[0x320];
    sCardText loc;
    void* mp = func_00227F80(D_004A28A8);
    func_00241DC8(mp, &loc, *(int*)((char*)mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<unsigned short*(void*, int)>* vt = *(sVEntry<unsigned short*(void*, int)>**)(o + 4);
    unsigned short* r = vt[4].fn(o + vt[4].delta, GetHashValue32(D_0045DC90));
    func_002C26D0(buf, r, &loc);
    cFEStateMemCard* st = D_004A14B8;
    st->f19C = 4;
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

extern "C" void func_00186D60(void)
{
    sCardText loc;
    unsigned short buf[0x320];
    void* mp = func_00227F80(D_004A28A8);
    func_00241DC8(mp, &loc, *(int*)((char*)mp + 0x428));
    cBE_getInterface_Fv(cBE_getBE(), 5);
    char* o = *(char**)((char*)mp + 0x434);
    sVEntry<int(void*, int)>* vt = *(sVEntry<int(void*, int)>**)o;
    o += vt[22].delta;
    int need = vt[22].fn(o, func_00152BA8());
    unsigned short* b = buf;
    char* lo = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<unsigned short*(void*, int)>* lvt = *(sVEntry<unsigned short*(void*, int)>**)(lo + 4);
    lo += lvt[4].delta;
    unsigned short* fmt = lvt[4].fn(lo, GetHashValue32(D_0045DCA8));
    func_002C26D0(b, fmt, &loc, need);
    cFEStateMemCard* st = D_004A14B8;
    st->f19C = 9;
    sVEntry<void(void*, void*, int, int, int, int, int)>* svt = *(sVEntry<void(void*, void*, int, int, int, int, int)>**)((char*)st + 8);
    svt[36].fn((char*)st + svt[36].delta, b, 0, 0, 0, 0, 0);

    {
        char* w = D_004A14B8->box;
        char* lo2 = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry<void(void*, unsigned short*, int)>* wvt = *(sVEntry<void(void*, unsigned short*, int)>**)(w + 8);
        sVEntry<unsigned short*(void*, int)>* lvt2 = *(sVEntry<unsigned short*(void*, int)>**)(lo2 + 4);
        w += wvt[26].delta;
        lo2 += lvt2[4].delta;
        wvt[26].fn(w, lvt2[4].fn(lo2, GetHashValue32(D_0045DCC8)), 0);
    }
    {
        char* w = D_004A14B8->box;
        char* lo2 = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry<void(void*, unsigned short*, int)>* wvt = *(sVEntry<void(void*, unsigned short*, int)>**)(w + 8);
        sVEntry<unsigned short*(void*, int)>* lvt2 = *(sVEntry<unsigned short*(void*, int)>**)(lo2 + 4);
        w += wvt[26].delta;
        lo2 += lvt2[4].delta;
        wvt[26].fn(w, lvt2[4].fn(lo2, GetHashValue32(D_0045DCD8)), 1);
    }
    char* w2 = D_004A14B8->box;
    sVEntry<void(void*, int)>* vvt = *(sVEntry<void(void*, int)>**)(w2 + 8);
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
extern "C" void func_00187270(cFEStateMemCard* self);
extern "C" void* func_00227F80(void* p);
extern "C" int func_0023C8D0(void* mp);
extern "C" int func_002419D8(void* mp, int card);
extern void* D_004A28A8;
extern int D_004A14BC;

extern "C" void func_00186F90(void)
{
    if (D_004A14B8->f234 != 0) {
        if (D_004A14BC < 4)
            return;
        char* mp = (char*)func_00227F80(D_004A28A8);
        char* o = *(char**)(mp + 0x434);
        sVEntry<void(void*, int, void*)>* vt = *(sVEntry<void(void*, int, void*)>**)o;
        vt[14].fn(o + vt[14].delta, *(int*)(mp + 0xF8), D_004A14B8->f09C);
        return;
    }
    char* mp = (char*)func_00227F80(D_004A28A8);
    if (func_0023C8D0(mp) == 0) {
        int fail = 0;
        cBE_getInterface_Fv(cBE_getBE(), 5);
        int extra = 0;
        int avail = func_002419D8(mp, *(int*)(mp + 0x428));
        cFEStateMemCard* st = D_004A14B8;
        int flags = st->flags.all;
        st->needed = 0;
        if (flags & 1) {
            extra = 1;
            char* o = *(char**)(mp + 0x434);
            sVEntry<int(void*, int)>* vt = *(sVEntry<int(void*, int)>**)o;
            char* thisp = o + vt[22].delta;
            int r = vt[22].fn(thisp, func_00152BA8());
            D_004A14B8->needed += r;
        }
        char* o;
        if (avail < D_004A14B8->needed
            || ((o = *(char**)(mp + 0x434), (*(sVEntry<int(void*)>**)o)[25].fn(o + (*(sVEntry<int(void*)>**)o)[25].delta) != -1)
                && (o = *(char**)(mp + 0x434), (*(sVEntry<int(void*)>**)o)[25].fn(o + (*(sVEntry<int(void*)>**)o)[25].delta) < extra)))
            fail = 1;
        if (fail) {
            D_004A14B8->f234 = 1;
            sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(mp + 0x748);
            vt[1].fn(mp + vt[1].delta, 0x17);
            return;
        }
    }
    func_00187270(D_004A14B8);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187148);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

extern "C" void func_00187148(void)
{
    D_004A14B8->v41();
    D_004A14B8->f1C0 = 6;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187180);
#ifdef SKIP_ASM
extern "C" void func_001D83A8(void);
extern "C" void func_00187A38(cFEStateMemCard* self);

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
    D_004A14B8->flags.all = -1;
    D_004A14B8->f234 = 0;
    func_0023C8F0(mp, 2);
    D_004A14B8->state = 2;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187230);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_004A28A8;
extern int D_004A14BC;
extern "C" void* func_00227F80(void* p);
extern "C" void func_0023C8F0(void* mp, int mode);

extern "C" void func_00187230(void)
{
    void* mp = func_00227F80(D_004A28A8);
    D_004A14BC = 0;
    D_004A14B8->flags.all = -1;
    D_004A14B8->f234 = 0;
    func_0023C8F0(mp, 2);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187270);
#ifdef SKIP_ASM
extern "C" void func_00187318(cFEStateMemCard* self);
extern "C" void func_001877B0(void);
extern "C" void func_00187920(void);

extern "C" void func_00187270(cFEStateMemCard* self)
{
    self->f234 = 1;
    void* mp = func_00227F80(D_004A28A8);
    int flags = self->saved.all;
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

extern "C" void func_00187318(cFEStateMemCard* self)
{
    self->f1C0 = 6;
    if (self->f1AC == 0)
        func_00228238(D_004A28A8);
    self->f1AC = 1;
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_00187360);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern char D_0045DCE8[];
extern char D_0045DCD8[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00152BA8();
extern "C" void* func_00227F80(void* p);
extern "C" void func_00241DC8(void* mp, void* out, int a2);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);

extern "C" void func_00187360(void)
{
    unsigned short buf[0x320];
    sCardText loc;
    void* mp = func_00227F80(D_004A28A8);
    cBE_getInterface_Fv(cBE_getBE(), 5);
    D_004A14B8->f19C = 0x14;
    char* sf = *(char**)((char*)mp + 0x434);
    sVEntry<int(void*, int)>* sfvt = *(sVEntry<int(void*, int)>**)sf;
    int size = sfvt[22].fn(sf + sfvt[22].delta, func_00152BA8());
    func_00241DC8(mp, &loc, *(int*)((char*)mp + 0x428));
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<unsigned short*(void*, int)>* vt = *(sVEntry<unsigned short*(void*, int)>**)(o + 4);
    unsigned short* fmt = vt[4].fn(o + vt[4].delta, GetHashValue32(D_0045DCE8));
    func_002C26D0(buf, fmt, &loc, size);
    D_004A14B8->v36(buf, 0, 0, 0, 0, 0);
    char* box = D_004A14B8->box;
    sVEntry<void(void*, int, int)>* bvt = *(sVEntry<void(void*, int, int)>**)(box + 8);
    char* bthis = box + bvt[26].delta;
    char* o2 = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<int(void*, int)>* vt2 = *(sVEntry<int(void*, int)>**)(o2 + 4);
    char* o2this = o2 + vt2[4].delta;
    int id = vt2[4].fn(o2this, GetHashValue32(D_0045DCD8));
    bvt[26].fn(bthis, id, 1);
    char* box2 = D_004A14B8->box;
    sVEntry<void(void*, int)>* bvt2 = *(sVEntry<void(void*, int)>**)(box2 + 8);
    bvt2[25].fn(box2 + bvt2[25].delta, 1);
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_001874E8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A14BC;
extern "C" void* func_00227F80(void* p);
extern "C" void* func_0023FB58(void* mp);
extern "C" void func_001877B0(void);
extern "C" void func_00187318(cFEStateMemCard* self);

static inline int moviePlaying_K1874E8(void* mp)
{
    int r = 0;
    if (*(int*)((char*)mp + 0x440) == 0)
        r = *(int*)((char*)mp + 0x43C) != 0;
    return r;
}

extern "C" void func_001874E8(cFEStateMemCard* self)
{
    if (self->f1AC != 0)
        return;
    void* mp = func_00227F80(D_004A28A8);
    if (moviePlaying_K1874E8(mp))
        return;
    if (D_004A14BC == 4 && ((self->saved.all ^ 1) & 1)) {
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
extern "C" void func_00241E18(void*, unsigned short*, int);
extern "C" void func_003A0D00(void* self, unsigned short* str);

extern "C" void func_001876A8(void)
{
    cFEStateMemCard* st = D_004A14B8;
    void* obj = cUIScreen_getObjectByHashName(st->screen, GetHashValue32(D_0045DC80));
    void* mp = func_00227F80(D_004A28A8);
    int e = *(int*)((char*)mp + 0x130);
    if (e == 0x1F || e == 0x21 || e == 0x20 || e == 0x22 || e == 0x31 || e == 0x32 || e == 0x33
        || e == 0x35 || e == 0x36 || e == 0x34 || e == 2 || e == 3 || e == 6) {
        unsigned short buf[0x320];
        func_00241E18(mp, buf, 0x320);
        func_003A0D00(obj, buf);
        sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)((char*)obj + 8);
        vt[9].fn((char*)obj + vt[9].delta, 1);
    } else {
        sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)((char*)obj + 8);
        vt[9].fn((char*)obj + vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fememcard", func_001877B0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
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
extern "C" unsigned short* func_002C2540(void*, void*);
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_00241D40(void* self, int mode, void* buf, int size);
extern "C" void func_00241AA0(void* buf, int size);
extern "C" void func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
extern "C" void* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* cUIAnimationBank_getAnimationByHashName(void* bank, int hash);
extern "C" void func_0039FCC8(void* obj, void* anim, int a, int b, int c);
extern "C" void func_001D9308(void*, int);

extern "C" void func_001877B0(void)
{
    unsigned short name[0x14];
    unsigned short desc[0x10];
    unsigned short fmt[8];
    D_004A14BC = 5;
    D_004A14B8->f1C0 = 5;
    cBE_getInterface_Fv(cBE_getBE(), 5);
    void* mp = func_00227F80(D_004A28A8);
    D_004A14B8->state = 0;
    D_004A14BC = 5;
    func_0023CAA0(mp, func_00152BA8());
    func_0023C8F0(mp, 1);
    cFEStateMemCard* s1 = D_004A14B8;
    int t = D_004A14B4;
    *(int*)((char*)mp + 0xF8) = t;
    s1->f1C4 = t;
    s1->state = 0;
    sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)((char*)mp + 0x748);
    vt[1].fn((char*)mp + vt[1].delta, 0x35);
    func_00241D40(mp, 1, name, 0x14);
    func_002C2540(fmt, D_004A14C8);
    func_00241AA0(desc, 0x10);
    func_002C26D0(D_004A14B8->text, fmt, desc, name);
    func_001D9308(D_004A14B8, 1);
    cFEStateMemCard* st = D_004A14B8;
    st->f1A8 = 1;
    void* obj = cUIScreen_getObjectByHashName(st->screen, GetHashValue32(D_004A14C0));
    if (obj) {
        void* bank = (char*)D_004A14B8->engine + 0x50;
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

extern "C" void func_00187920(void)
{
    D_004A14BC = 4;
    D_004A14B8->f1C0 = 5;
    cBE_getInterface_Fv(cBE_getBE(), 5);
    void* mp = func_00227F80(D_004A28A8);
    cFEStateMemCard* s1 = D_004A14B8;
    s1->state = 2;
    s1->f1C4 = 0;
    func_0023CAA0(mp, func_00152948_K187920());
    func_0023C8F0(mp, 2);
    sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)((char*)mp + 0x748);
    vt[1].fn((char*)mp + vt[1].delta, 0x35);
    cFEStateMemCard* st = D_004A14B8;
    st->state = 2;
    void* obj = cUIScreen_getObjectByHashName(st->screen, GetHashValue32(D_004A14C0));
    if (obj) {
        void* bank = (char*)D_004A14B8->engine + 0x50;
        void* anim = cUIAnimationBank_getAnimationByHashName(bank, GetHashValue32(D_0045DD00));
        if (anim)
            func_0039FCC8(obj, anim, 9, 0, 0);
    }
    func_001D9308(D_004A14B8, 1);
    D_004A14B8->f1A8 = 1;
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

static inline int cardCall_87A38(char* o, int slot)
{
    sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)o;
    return vt[slot].fn(o + vt[slot].delta);
}

static inline void mpNotify_87A38(char* mp, int msg)
{
    sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(mp + 0x748);
    vt[1].fn(mp + vt[1].delta, msg);
}

extern "C" void func_00187A38(cFEStateMemCard* self)
{
    char* mp = (char*)func_00227F80(D_004A28A8);
    char* card = *(char**)(mp + 0x434);
    if (func_0023C8D0(mp))
        D_004A14BC = 3;
    switch (D_004A14BC) {
    case 0:
        if (cardCall_87A38(card, 13))
            self->flags.bits.b1 = 0;
        func_0023C8F0(mp, 1);
        mpNotify_87A38(mp, 0x33);
        D_004A14BC++;
        self->state = 0;
        break;
    case 1:
        if (cardCall_87A38(card, 13))
            self->flags.bits.b0 = 0;
        if (*(int*)(mp + 0x428) == 0) {
            int r = cardCall_87A38(*(char**)(mp + 0x434), 17);
            D_004A14B4 = r;
            if (r == -1)
                D_004A14B4 = 0;
        }
        func_0023C8F0(mp, 0);
        mpNotify_87A38(mp, 0x33);
        D_004A14BC++;
        self->state = 1;
        break;
    case 2:
        if (cardCall_87A38(card, 13))
            self->flags.bits.b2 = 0;
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

//100%
INCLUDE_ASM("fe/fememcard", func_00187C18);
#ifdef SKIP_ASM
extern "C" void* func_0039E318(void* self, void* engine, void* owner);
extern void* D_0046B4A0[];

extern "C" void* func_00187C18(void* self, void* engine, void* owner)
{
    func_0039E318(self, engine, owner);
    *(int*)((char*)self + 0x48) = 0;
    *(void***)((char*)self + 0x8) = D_0046B4A0;
    return self;
}
#endif

