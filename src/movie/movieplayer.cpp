#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00242288(void* self);
extern const char D_0047C128[];
extern void* D_004A2C74;

//100%
INCLUDE_ASM("movie/movieplayer", cMCOverlayManager_getManager__Fv);
#ifdef SKIP_ASM
void* cMCOverlayManager_getManager()
{
    if (D_004A2C74 == 0) {
        void* mem = cMemMan_alloc(0x74C, D_0047C128, 0, 0);
        D_004A2C74 = func_00242288(mem);
    }
    return D_004A2C74;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023C850);
#ifdef SKIP_ASM
extern "C" int func_0023C850(void) {
    return D_004A2C74 != 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023C860);
#ifdef SKIP_ASM
struct sMovieObj_23C860 {
    char pad[0x748];
    virtual void v01();
    virtual ~sMovieObj_23C860();
};

extern "C" void func_0023C860(void* self)
{
    delete (sMovieObj_23C860*)D_004A2C74;
    D_004A2C74 = 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023C898);
#ifdef SKIP_ASM
extern "C" int func_0023C898(void* self)
{
    return *(int*)((char*)self + 0x130) == 1;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023C8A8);
#ifdef SKIP_ASM
extern "C" int func_0023C8A8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x130))) == 0x23;
}
#endif
//100%
INCLUDE_ASM("movie/movieplayer", func_0023C8B8);
#ifdef SKIP_ASM
extern "C" int func_0023C8B8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xDC)));
}
#endif
//100%
INCLUDE_ASM("movie/movieplayer", func_0023C8C0);
#ifdef SKIP_ASM
extern int D_004A2C78;

extern "C" int func_0023C8C0(void) {
    return D_004A2C78 != 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023C8D0);
#ifdef SKIP_ASM
extern "C" int func_0023C8D0(void* self)
{
    // masks applied as separate statements; folding them into one
    // expression collapses the two `and` instructions into one
    int v = *(int*)((char*)self + 0x43c);
    v &= -5;
    v &= -481;
    return v != 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023C8F0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_00152948__FPv ignores its argument; this caller passes none.
int func_00152948_r() __asm__("func_00152948__FPv");
extern "C" int func_00152BA8();
extern "C" void* func_0023D570(void* self, int mode);
extern "C" unsigned short* func_002C2540(void*, void*);
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_00241D40(void* self, int mode, void* buf, int size);
extern "C" void func_00241AA0(void* buf, int size);
extern "C" void func_002C26D0_v(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern char D_004A2C80[];

struct sMovieVEntry_23C8F0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023C8F0(void* self, int mode)
{
    char desc[0x200];
    char name[0x200];
    char fmt[0x200];
    char* s = (char*)self;
    *(int*)(s + 0xB4) = mode;
    func_0023D570(self, 1);
    *(int*)(s + 0xFC) = -1;
    *(int*)(s + 0xBC) = 0;
    int m = *(int*)(s + 0xB4);
    if (m == 0) {
        *(int*)(s + 0xEC) = 4;
        char* o = *(char**)(s + 0x434);
        sMovieVEntry_23C8F0* vt = *(sMovieVEntry_23C8F0**)o;
        vt[19].fn(o + vt[19].delta, 0x80000);
    } else if (m == 1) {
        *(int*)(s + 0xEC) = 6;
        cBE_getInterface_Fv(cBE_getBE(), 5);
        int v = func_00152BA8();
        char* o = *(char**)(s + 0x434);
        sMovieVEntry_23C8F0* vt = *(sMovieVEntry_23C8F0**)o;
        vt[19].fn(o + vt[19].delta, v);
    } else {
        *(int*)(s + 0xEC) = 1;
        cBE_getInterface_Fv(cBE_getBE(), 5);
        int v = func_00152948_r();
        char* o = *(char**)(s + 0x434);
        sMovieVEntry_23C8F0* vt = *(sMovieVEntry_23C8F0**)o;
        vt[19].fn(o + vt[19].delta, v);
    }
    func_002C2540(fmt, D_004A2C80);
    func_00241AA0(desc, 0x200);
    func_00241D40(self, *(int*)(s + 0xB4), name, 0x100);
    func_002C26D0_v(s + 0x1B4, fmt, desc, name);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023CA28);
#ifdef SKIP_ASM
struct sMovieVEntryCA28 {
    short delta;
    short index;
    void (*fn)(void*, int, int, int);
};

extern "C" void func_0023CA28(void* self, int a, int b, int c)
{
    void* obj = *(void**)((char*)self + 0x434);
    sMovieVEntryCA28* vt = *(sMovieVEntryCA28**)obj;
    vt[29].fn((char*)obj + vt[29].delta, a, b, c);
    *(int*)((char*)self + 0xE8) = c;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023CA70);
#ifdef SKIP_ASM
struct sMovieVEntry {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023CA70(void* self)
{
    void* obj = *(void**)((char*)self + 0x434);
    sMovieVEntry* vt = *(sMovieVEntry**)obj;
    vt[32].fn((char*)obj + vt[32].delta);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023CAA0);
#ifdef SKIP_ASM
struct sMovieVEntryCAA0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// PORT: the unit declares func_0023CAA0(void* self), but the body takes a
// second argument (callers pass it in $5); the real body is bound by asm label.
void func_0023CAA0_impl(void* self, int a) __asm__("func_0023CAA0");

void func_0023CAA0_impl(void* self, int a)
{
    void* obj = *(void**)((char*)self + 0x434);
    sMovieVEntryCAA0* vt = *(sMovieVEntryCAA0**)obj;
    vt[19].fn((char*)obj + vt[19].delta, a);
    *(int*)((char*)self + 0xF0) = a;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023CAE8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_00152948__FPv ignores its argument; this caller passes none.
int func_00152948_r() __asm__("func_00152948__FPv");
extern "C" int func_00152BA8();
extern "C" void* func_0023D570(void* self, int mode);
extern "C" unsigned short* func_002C2540(void*, void*);
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_00241D40(void* self, int mode, void* buf, int size);
extern "C" void func_00241AA0(void* buf, int size);
extern "C" void func_002C26D0_v(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern char D_004A2C80[];

struct sMovieVEntry_23CAE8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023CAE8(void* self, int mode, int a2)
{
    char desc[0x200];
    char name[0x200];
    char fmt[0x200];
    char* s = (char*)self;
    *(int*)(s + 0xB4) = mode;
    func_0023D570(self, 1);
    *(int*)(s + 0xFC) = a2;
    *(int*)(s + 0xBC) = 1;
    int m = *(int*)(s + 0xB4);
    if (m == 0) {
        *(int*)(s + 0xEC) = 4;
        char* o = *(char**)(s + 0x434);
        sMovieVEntry_23CAE8* vt = *(sMovieVEntry_23CAE8**)o;
        vt[19].fn(o + vt[19].delta, 0x80000);
    } else if (m == 1) {
        *(int*)(s + 0xEC) = 6;
        cBE_getInterface_Fv(cBE_getBE(), 5);
        int v = func_00152BA8();
        char* o = *(char**)(s + 0x434);
        sMovieVEntry_23CAE8* vt = *(sMovieVEntry_23CAE8**)o;
        vt[19].fn(o + vt[19].delta, v);
    } else {
        *(int*)(s + 0xEC) = 1;
        cBE_getInterface_Fv(cBE_getBE(), 5);
        int v = func_00152948_r();
        char* o = *(char**)(s + 0x434);
        sMovieVEntry_23CAE8* vt = *(sMovieVEntry_23CAE8**)o;
        vt[19].fn(o + vt[19].delta, v);
    }
    func_002C2540(fmt, D_004A2C80);
    func_00241AA0(desc, 0x200);
    func_00241D40(self, *(int*)(s + 0xB4), name, 0x100);
    func_002C26D0_v(s + 0x1B4, fmt, desc, name);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023CC20);
#ifdef SKIP_ASM
extern "C" void func_0023CC20(void* self)
{
    if (*(int*)((char*)self + 0x118) != 0) {
        void* obj = *(void**)((char*)self + 0x434);
        sMovieVEntry* vt = *(sMovieVEntry**)obj;
        vt[43].fn((char*)obj + vt[43].delta);
    }
}
#endif

extern "C" void* func_0023CAA0(void* self);

//100%
INCLUDE_ASM("movie/movieplayer", func_0023CC58__FPv);
#ifdef SKIP_ASM
void* func_0023CC58(void* self)
{
    return func_0023CAA0(self);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023CC78);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C2540(void*, void*);
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_00241D40(void* self, int mode, void* buf, int size);
extern "C" void func_002C26D0_v(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern "C" void* func_002C2508(void* dst, void* src);
int GetHashValue32(char* s);
extern void* D_004A28A8;
extern char D_004A2C88[];
extern char D_0047C138[];

struct sLocVEntry_23CC78 {
    short delta;
    short index;
    void* (*fn)(void*, int);
};

extern "C" void func_0023CC78(void* self, int n, char* dst)
{
    char name[0x100];
    char fmt[0x200];
    switch (*(int*)((char*)self + 0xB4)) {
    case 0:
        func_002C2540(fmt, D_004A2C88);
        func_00241D40(self, *(int*)((char*)self + 0xB4), name, 0x80);
        func_002C26D0_v(dst, fmt, name, n + 1);
        break;
    case 2: {
        char* loc = *(char**)((char*)D_004A28A8 + 0x8C);
        sLocVEntry_23CC78* vt = *(sLocVEntry_23CC78**)(loc + 4);
        char* thisp = loc + vt[4].delta;
        func_002C2508(dst, vt[4].fn(thisp, GetHashValue32(D_0047C138)));
        break;
    }
    case 1:
        func_002C2540(fmt, D_004A2C88);
        func_00241D40(self, *(int*)((char*)self + 0xB4), name, 0x80);
        func_002C26D0_v(dst, fmt, name, n + 1);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", cMCOverlayManager_setTitleString);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_002C26D0_v(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern "C" void* func_002C2508(void* dst, void* src);
extern "C" void func_0023CC78(void* self, int n, char* dst);
extern "C" void* func_00147170(void* iface, int id);
int GetHashValue32(char* s);
extern void* D_004A28A8;
extern char D_0047C138[];
extern char D_0047C150[];
extern char D_0047C160[];

struct sLocVEntry_23CDB0 {
    short delta;
    short index;
    void* (*fn)(void*, int);
};

struct sMovieVEntry_23CDB0 {
    short delta;
    short index;
    void (*fn)(void*, char*);
};

extern "C" void cMCOverlayManager_setTitleString(void* self, int n)
{
    char out[0x200];
    char title[0x200];
    char fmt[0x200];
    char name[0x200];
    func_0023CC78(self, n, title);
    func_002C2540(fmt, D_0047C150);
    switch (*(int*)((char*)self + 0xB4)) {
    case 0: {
        char* loc = *(char**)((char*)D_004A28A8 + 0x8C);
        sLocVEntry_23CDB0* vt = *(sLocVEntry_23CDB0**)(loc + 4);
        char* thisp = loc + vt[4].delta;
        func_002C26D0_v(title, fmt, vt[4].fn(thisp, GetHashValue32(D_0047C160)));
        func_002C26D0_v(out, title, n);
        break;
    }
    case 1: {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
        func_002C2540(name, func_00147170(iface, *(int*)((char*)self + 0xFC)));
        func_002C26D0_v(out, fmt, name);
        break;
    }
    default: {
        char* loc = *(char**)((char*)D_004A28A8 + 0x8C);
        sLocVEntry_23CDB0* vt = *(sLocVEntry_23CDB0**)(loc + 4);
        char* thisp = loc + vt[4].delta;
        func_002C2508(title, vt[4].fn(thisp, GetHashValue32(D_0047C138)));
        func_002C26D0_v(out, fmt, title);
        break;
    }
    }
    char* o = *(char**)((char*)self + 0x434);
    sMovieVEntry_23CDB0* mvt = *(sMovieVEntry_23CDB0**)o;
    mvt[45].fn(o + mvt[45].delta, out);
    func_002C2508((char*)self + 0x234, out);
}
#endif

INCLUDE_ASM("movie/movieplayer", func_0023CF38);

//100%
INCLUDE_ASM("movie/movieplayer", func_0023D570);
#ifdef SKIP_ASM
extern "C" void* func_0023D570(void* self, int mode)
{
    char* s = (char*)self;
    *(int*)(s + 0xB8) = mode;
    switch (mode) {
    case 0:
        break;
    case 1:
        *(float*)(s + 0x110) = 1.0f;
        *(float*)(s + 0x114) = 0.016669999808073044f;
        *(int*)(s + 0x108) = 0x3C;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023D5A8);
#ifdef SKIP_ASM
extern "C" void* func_002C22C8(void);

extern "C" void func_0023D5A8(void* self)
{
    char* s = (char*)self;
    void* q = func_002C22C8();
//START
    *(void**)(s + 0x434) = q;
    *(int*)(s + 0x104) = 0;
    *(float*)(s + 0x110) = 1.0f;
    *(float*)(s + 0x114) = 0.016669999808073044f;
//END
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023D5E8);
#ifdef SKIP_ASM
extern "C" void func_002C2300(void*);

extern "C" void func_0023D5E8(void* self)
{
    func_002C2300(*(void**)((char*)self + 0x434));
    *(void**)((char*)self + 0x434) = 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023D618);
#ifdef SKIP_ASM
extern "C" void func_0023D7D8(void* self);
extern "C" void func_0023D660(void* self);

extern "C" void func_0023D618(void* self)
{
    switch (*(int*)((char*)self + 0xB8)) {
    case 0:
        func_0023D7D8(self);
        break;
    case 1:
        func_0023D660(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023D660);
#ifdef SKIP_ASM
extern "C" int func_00241AC0(void* self);
extern "C" void func_0023E268(void* self);
extern "C" void func_0023E320(void* self);
extern "C" void func_0023E498(void* self);

struct sVoidVEntry_23D660 {
    short delta;
    short index;
    void (*fn)(void*);
};
struct sIntVEntry_23D660 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sArgVEntry_23D660 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline bool isState_23D660(char* s, int k)
{
    return *(int*)(s + 0x130) == k;
}

extern "C" void func_0023D660(void* self)
{
    char* s = (char*)self;
    char* o = *(char**)(s + 0x434);
    sVoidVEntry_23D660* vt = *(sVoidVEntry_23D660**)o;
    vt[3].fn(o + vt[3].delta);
    if (*(int*)(s + 0x338) != 0) {
        o = *(char**)(s + 0x434);
        sIntVEntry_23D660* ivt = *(sIntVEntry_23D660**)o;
        if (ivt[11].fn(o + ivt[11].delta) != 0) {
            return;
        }
        *(int*)(s + 0x338) = 0;
    }
    if (*(int*)(s + 0x424) == -1) {
        *(int*)(s + 0x424) = func_00241AC0(self);
    }
    o = *(char**)(s + 0x434);
    sIntVEntry_23D660* ivt = *(sIntVEntry_23D660**)o;
    if (ivt[11].fn(o + ivt[11].delta) == 0) {
        func_0023D570(self, 0);
        int ok = !(isState_23D660(s, 0x31) || isState_23D660(s, 0x32) || isState_23D660(s, 0x33) || isState_23D660(s, 0x34) || isState_23D660(s, 0x36));
        if (ok) {
            sArgVEntry_23D660* avt = *(sArgVEntry_23D660**)(s + 0x748);
            avt[1].fn(s + avt[1].delta, 3);
        }
    }
    int st = *(int*)(s + 0x130);
    if (st == 0x31) {
        func_0023E268(self);
    } else if (st == 0x33) {
        func_0023E498(self);
    } else if (st == 0x36) {
        func_0023E320(self);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023D7A8);
#ifdef SKIP_ASM
extern "C" int func_0023D7A8(void* self)
{
    int f = *(int*)((char*)self + 0x43C);
    f &= ~4;
    f &= ~0x10;
    return *(int*)((char*)self + 0x440) == 0 && f != 0;
}
#endif

INCLUDE_ASM("movie/movieplayer", func_0023D7D8);

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E268);
#ifdef SKIP_ASM
struct sMovieVEntryE268a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryE268b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023E268(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE268a* vt = *(sMovieVEntryE268a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        sMovieVEntryE268b* vt2 = *(sMovieVEntryE268b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x32);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E2C0__FPv);
#ifdef SKIP_ASM
void func_0023E2C0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E2C8);
#ifdef SKIP_ASM
struct sMovieVEntryE2C8a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryE2C8b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023E2C8(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE2C8a* vt = *(sMovieVEntryE2C8a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        sMovieVEntryE2C8b* vt2 = *(sMovieVEntryE2C8b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x33);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E320);
#ifdef SKIP_ASM
struct sMovieVEntryE320a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryE320b {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sMovieVEntryE320c {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00241FD0(void* self);

extern "C" void func_0023E320(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE320a* vt = *(sMovieVEntryE320a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        void* o2 = *(void**)((char*)self + 0x434);
        sMovieVEntryE320b* vtb = *(sMovieVEntryE320b**)o2;
        if (vtb[52].fn((char*)o2 + vtb[52].delta, *(int*)((char*)self + 0x428)) == 0) {
            sMovieVEntryE320c* vt2 = *(sMovieVEntryE320c**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 2);
            (*(void (**)())((char*)self + 0x9C))();
        } else {
            func_00241FD0(self);
            (*(void (**)())((char*)self + 0x98))();
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E3C0);
#ifdef SKIP_ASM
struct sMovieVEntryE3C0a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryE3C0b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023E3C0(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE3C0a* vt = *(sMovieVEntryE3C0a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            sMovieVEntryE3C0b* vt2 = *(sMovieVEntryE3C0b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E428);
#ifdef SKIP_ASM
struct sMovieVEntryE428 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_00242050(void* self);

extern "C" void func_0023E428(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE428* vt = *(sMovieVEntryE428**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 0);
            *(int*)((char*)self + 0xC8) = 0;
            func_00242050(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E498);
#ifdef SKIP_ASM
struct sMovieVEntryE498a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryE498b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023E498(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE498a* vt = *(sMovieVEntryE498a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        sMovieVEntryE498b* vt2 = *(sMovieVEntryE498b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x34);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E4F0__FPv);
#ifdef SKIP_ASM
void func_0023E4F0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E4F8);
#ifdef SKIP_ASM
struct sMovieVEntryE4F8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023E4F8(void* self)
{
    if ((*(int*)((char*)self + 0x108))-- <= 0) {
        sMovieVEntryE4F8* vt = *(sMovieVEntryE4F8**)((char*)self + 0x748);
        vt[1].fn((char*)self + vt[1].delta, 3);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E540);
#ifdef SKIP_ASM
extern "C" int func_00241CD8(void* self);
extern "C" void func_0023EB50(void* self);
extern "C" void func_00241FD0(void* self);
extern "C" void func_00242050(void* self);

struct sMovieVEntryE540a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryE540b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline int Pad_E540(void* self, int slot)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE540a* vt = *(sMovieVEntryE540a**)o;
    return vt[slot].fn((char*)o + vt[slot].delta);
}

static inline void Post_E540(void* self, int code)
{
    sMovieVEntryE540b* vt = *(sMovieVEntryE540b**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, code);
}

static inline int Ready_E540(void* self)
{
    return Pad_E540(self, 55) && Pad_E540(self, 58) && !Pad_E540(self, 51) && !Pad_E540(self, 59);
}

#define S_E540 ((char*)self)

extern "C" void func_0023E540(void* self)
{
    if (Pad_E540(self, 11))
        return;
    int quit = 0;
    if (*(int*)(S_E540 + 0xBC) || *(int*)(S_E540 + 0xC0) || (*(int (**)())(S_E540 + 0x78))())
        quit = 1;
    if (*(int*)(S_E540 + 0x128) && *(int*)(S_E540 + 0xC8) && quit) {
        Post_E540(self, 0x38);
        return;
    }
    int held = *(int*)(S_E540 + 0x43C);
    if (func_00241CD8(self)) {
        if ((*(int*)(S_E540 + 0x124) || quit) && (*(int*)(S_E540 + 0x43C) & 8)) {
            func_0023EB50(self);
            return;
        }
        if (!(*(int*)(S_E540 + 0x43C) & 8)) {
            if (*(int*)(S_E540 + 0x43C) & 1) {
                Post_E540(self, 5);
                return;
            }
            if (*(int*)(S_E540 + 0x120) && (*(int*)(S_E540 + 0x43C) & 0x10)) {
                Post_E540(self, 0x27);
                return;
            }
        }
        int rel;
        if ((!(*(int*)(S_E540 + 0x43C) & 8) && (held & 8)) || (rel = held & ~4, *(int*)(S_E540 + 0x43C) == 0 && rel)) {
            func_00241FD0(self);
            return;
        }
    }
    if (!quit) {
        if (*(int*)(S_E540 + 0xC8)) {
            *(int*)(S_E540 + 0xC8) = 0;
            func_00242050(self);
            return;
        }
        if (*(int*)(S_E540 + 0x43C) & 8) {
            Post_E540(self, 0x31);
            return;
        }
    }
    if (*(int*)(S_E540 + 0xBC)) {
        if (Pad_E540(self, 55) && Pad_E540(self, 58) && !Pad_E540(self, 51) && !Pad_E540(self, 59))
            Post_E540(self, 6);
        else
            Post_E540(self, 7);
    } else {
        if (Pad_E540(self, 55) && Pad_E540(self, 58) && !Pad_E540(self, 51) && !Pad_E540(self, 59))
            Post_E540(self, 6);
        else
            Post_E540(self, 0x1D);
    }
}
#undef S_E540
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E820);
#ifdef SKIP_ASM
struct sMovieVEntryE820 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_0023E820(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryE820* vt = *(sMovieVEntryE820**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 0);
        } else if ((*(int (**)())((char*)self + 0x84))() != 0) {
            func_0023EA90(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023E8A0);
#ifdef SKIP_ASM
struct sMovieVEntry_E8A0 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sMovieDelegate_E8A0 {
    char pad[8];
    short delta;
    short pad2;
    void (*fn)(void*, int);
};

static inline int vq_E8A0(char* s, int k)
{
    char* o = *(char**)(s + 0x434);
    sMovieVEntry_E8A0* vt = *(sMovieVEntry_E8A0**)o;
    return vt[k].fn(o + vt[k].delta);
}

static inline void notify_E8A0(char* s, int v)
{
    sMovieDelegate_E8A0* d = *(sMovieDelegate_E8A0**)(s + 0x748);
    d->fn(s + d->delta, v);
}

extern "C" void func_0023E8A0(void* self, int flag)
{
    char* s = (char*)self;

    if (vq_E8A0(s, 53) == 0) {
        if (vq_E8A0(s, 49) != 0 || vq_E8A0(s, 51) != 0 || vq_E8A0(s, 59) != 0) {
            notify_E8A0(s, 5);
        } else {
            int ok = *(int*)(s + 0x130) != 4;
            if (ok) {
                notify_E8A0(s, 4);
            }
        }
    } else {
        if (vq_E8A0(s, 55) != 0 && vq_E8A0(s, 58) != 0 && vq_E8A0(s, 51) == 0 && vq_E8A0(s, 59) == 0) {
            if (flag != 0) {
                notify_E8A0(s, 6);
            }
        } else if (*(int*)(s + 0xBC) != 0) {
            notify_E8A0(s, 7);
        } else {
            notify_E8A0(s, 0x1D);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023EA30);
#ifdef SKIP_ASM
extern int D_004A2C78;
extern "C" void func_00241180(void* self, int a1);

struct sMovieVEntryEA30 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023EA30(void* self, int v)
{
    char* s = (char*)self;
    int on = *(int*)(s + 0xBC);
    D_004A2C78 = 0;
    if (on != 0) {
        *(int*)(s + 0xBC) = 0;
        func_00241180(self, v);
    }
    *(int*)(s + 0xC0) = 0;
    *(int*)(s + 0x440) = 1;
    *(int*)(s + 0xC4) = 0;
    sMovieVEntryEA30* vt = *(sMovieVEntryEA30**)(s + 0x748);
    vt[1].fn(s + vt[1].delta, 1);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023EA90);
#ifdef SKIP_ASM
extern "C" int func_0023C8D0(void* self);
extern "C" void func_0023FAE0(void* self);
void func_0023FB18(void* self, int val);
extern "C" void func_00241FD0(void* self);
extern "C" void func_00242050(void* self);
extern int D_004A2C78;

struct sMovieVEntryEA90 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sMovieVEntryEA90b {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0023EA90(void* self)
{
    char* s = (char*)self;
    if (*(int*)(s + 0xBC) != 0) {
        int playing = *(int*)(s + 0x118);
        D_004A2C78 = 0;
        if (playing != 0) {
            void* o = *(void**)(s + 0x434);
            sMovieVEntryEA90b* vt2 = *(sMovieVEntryEA90b**)o;
            vt2[44].fn((char*)o + vt2[44].delta);
        }
        sMovieVEntryEA90* vt = *(sMovieVEntryEA90**)(s + 0x748);
        vt[1].fn(s + vt[1].delta, 2);
    } else {
        *(int*)(s + 0x440) = 0;
        if (*(int*)(s + 0x12C) != 0) {
            func_0023FB18(self, 0);
            func_0023FAE0(self);
            sMovieVEntryEA90* vt = *(sMovieVEntryEA90**)(s + 0x748);
            vt[1].fn(s + vt[1].delta, 0x31);
        } else if (func_0023C8D0(self) == 0) {
            func_00241FD0(self);
        } else {
            func_00242050(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023EB50);
#ifdef SKIP_ASM
struct sMovieVEntry2 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023EB50(void* self)
{
    sMovieVEntry2* vt = *(sMovieVEntry2**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, 4);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023EB80);
#ifdef SKIP_ASM
struct sMovieVEntryEB80 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_0023EB80(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryEB80* vt = *(sMovieVEntryEB80**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 1);
        } else if ((*(int (**)())((char*)self + 0x84))() != 0) {
            func_0023EA90(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023EC00);
#ifdef SKIP_ASM
extern "C" void func_0023EB50(void* self);
extern "C" int func_00241CD8(void* self);
// PORT: the target calls func_00241FB0 as a void function here (the unit defines it returning void*).
void func_00241FB0_v(void* self) __asm__("func_00241FB0__FPv");

struct sMovieVEntryEC00 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sMovieVEntryEC00b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline int ovCall_EC00(char* s, int slot)
{
    void* o = *(void**)(s + 0x434);
    sMovieVEntryEC00* vt = *(sMovieVEntryEC00**)o;
    return vt[slot].fn((char*)o + vt[slot].delta);
}

static inline void post_EC00(char* s, int code)
{
    sMovieVEntryEC00b* vt = *(sMovieVEntryEC00b**)(s + 0x748);
    vt[1].fn(s + vt[1].delta, code);
}

extern "C" void func_0023EC00(void* self)
{
    char* s = (char*)self;
    int ready = func_00241CD8(self);
    if ((*(int*)(s + 0x108))-- > 0)
        return;
    if (ovCall_EC00(s, 11))
        return;
    if (*(int*)(s + 0xC8)) {
        int busy = 0;
        if (*(int*)(s + 0xBC) || *(int*)(s + 0xC0) || (*(int (**)())(s + 0x78))())
            busy = 1;
        if (*(int*)(s + 0x128) && busy) {
            post_EC00(s, 0x38);
            return;
        }
        if (ovCall_EC00(s, 55) && ovCall_EC00(s, 58) && !ovCall_EC00(s, 51) && !ovCall_EC00(s, 59)) {
            post_EC00(s, 6);
            return;
        }
    }
    if (*(int*)(s + 0xBC)) {
        int f = *(int*)(s + 0x43C);
        if (!(f & 8)) {
            if (f & 1) {
                post_EC00(s, 0x14);
                return;
            }
            if (ovCall_EC00(s, 55) && ovCall_EC00(s, 58) && !ovCall_EC00(s, 51) && !ovCall_EC00(s, 59) && !ovCall_EC00(s, 13)) {
                int a = ovCall_EC00(s, 23);
                if (ovCall_EC00(s, 20) < a || !ovCall_EC00(s, 25)) {
                    post_EC00(s, 0x15);
                    return;
                }
            }
        } else if (ready) {
            func_0023EB50(self);
            return;
        }
        func_00241FB0_v(self);
        post_EC00(s, 7);
        return;
    }
    {
        int busy = 0;
        if (*(int*)(s + 0xC0) || (*(int (**)())(s + 0x78))())
            busy = 1;
        if (*(int*)(s + 0x124) || busy) {
            if (*(int*)(s + 0x43C) & 8) {
                func_0023EB50(self);
                return;
            }
        } else if (*(int*)(s + 0x43C) & 8) {
            goto fail;
        }
        if (*(int*)(s + 0x43C) & 1) {
            if ((*(int (**)())(s + 0x78))())
                post_EC00(s, 0x24);
            else
                post_EC00(s, 5);
            return;
        }
    fail:
        func_00241FB0_v(self);
        post_EC00(s, 0x1D);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023EF68);
#ifdef SKIP_ASM
class cMovieSub434 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual void v05(int);
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
    virtual int v74();
    virtual int v75();
    virtual int v76();
    virtual int v77();
    virtual int v78();
    virtual int v79();
    virtual int v80();
};
class cMoviePlayerVt {
public:
    char pad[0x748];
    virtual void v01(int);
};

extern "C" void func_0023EA30(void* self, int v);

extern "C" void func_0023EF68(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    if (*(int*)((char*)self + 0x338) == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v53() == 0) {
            me->v01(4);
            return;
        }
        if ((*(cMovieSub434**)((char*)self + 0x434))->v09() != 0) {
            me->v01(0xC);
            return;
        }
        if (*(int*)((char*)self + 0xC4) != 0) {
            *(int*)((char*)self + 0xC4) = 0;
            me->v01(0xB);
            return;
        }
    }
    if ((*(int (**)())((char*)self + 0x6C))() != 0) {
        func_0023EA30(self, 0);
        return;
    }
    if ((*(int (**)())((char*)self + 0x88))() != 0) {
        *(int*)((char*)self + 0xC4) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F050);
#ifdef SKIP_ASM
extern "C" void func_0023F050(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    int t = (*(int*)((char*)self + 0x108))--;
    if (t <= 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
            if ((*(cMovieSub434**)((char*)self + 0x434))->v09() != 0) {
                me->v01(0xC);
            } else {
                me->v01(0xD);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F0F8);
#ifdef SKIP_ASM
extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023FB20(void* self, int v);

extern "C" void func_0023F0F8(void* self)
{
    if ((*(int (**)())((char*)self + 0x6C))() != 0) {
        func_0023EA30(self, 0);
        func_0023FB20(self, *(int*)((char*)self + 0x428));
        *(int*)((char*)self + 0x338) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F150);
#ifdef SKIP_ASM
struct sMovieVEntryF150 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_0023F150(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryF150* vt = *(sMovieVEntryF150**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 0);
        } else if ((*(int (**)())((char*)self + 0x84))() != 0) {
            *(int*)((char*)self + 0xBC) = 1;
            func_0023EA90(self);
            *(int*)((char*)self + 0x440) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F1D8);
#ifdef SKIP_ASM
struct sMovieVEntryF1D8 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_0023F1D8(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryF1D8* vt = *(sMovieVEntryF1D8**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 0);
        } else if ((*(int (**)())((char*)self + 0x84))() != 0) {
            func_0023EA90(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F258);
#ifdef SKIP_ASM
struct sMovieVEntryF258 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_0023F258(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryF258* vt = *(sMovieVEntryF258**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x84))() != 0) {
            func_0023EA90(self);
        } else if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F2D8);
#ifdef SKIP_ASM
extern "C" void func_0023F2D8(void* self)
{
    sMovieVEntry2* vt = *(sMovieVEntry2**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, 1);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F308);
#ifdef SKIP_ASM
struct sMovieVEntryF308a {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sMovieVEntryF308b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023F308(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryF308a* vt = *(sMovieVEntryF308a**)o;
    void* o2;
    sMovieVEntryF308a* vtb;
    if (vt[67].fn((char*)o + vt[67].delta, *(int*)((char*)self + 0xF8)) != 0
        || (o2 = *(void**)((char*)self + 0x434), vtb = *(sMovieVEntryF308a**)o2,
            vtb[65].fn((char*)o2 + vtb[65].delta, *(int*)((char*)self + 0xF8)) != 0)) {
        sMovieVEntryF308b* vt2 = *(sMovieVEntryF308b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0xE);
    } else {
        sMovieVEntryF308b* vt2 = *(sMovieVEntryF308b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0xF);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F3A0);
#ifdef SKIP_ASM
struct sMovieVEntryF3A0a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryF3A0b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023F3A0(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryF3A0a* vt = *(sMovieVEntryF3A0a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        void* o2 = *(void**)((char*)self + 0x434);
        sMovieVEntryF3A0a* vtb = *(sMovieVEntryF3A0a**)o2;
        if (vtb[73].fn((char*)o2 + vtb[73].delta) != 0) {
            sMovieVEntryF3A0b* vt2 = *(sMovieVEntryF3A0b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 0x14);
        } else {
            sMovieVEntryF3A0b* vt2 = *(sMovieVEntryF3A0b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 0xF);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F438);
#ifdef SKIP_ASM
extern "C" void func_0023F438(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v73() != 0) {
            if ((*(cMovieSub434**)((char*)self + 0x434))->v74() != 0) {
                me->v01(0x37);
            } else {
                me->v01(0x14);
            }
        } else {
            me->v01(0x10);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F4F8);
#ifdef SKIP_ASM
struct sMovieVEntryF4F8a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryF4F8b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00241180(void* self, int a1);

extern "C" void func_0023F4F8(void* self)
{
    void* o;
    sMovieVEntryF4F8a* vt;
    *(float*)((char*)self + 0x10C) = (float)*(int*)((char*)self + 0xE4) / (float)*(int*)((char*)self + 0xF0);
    o = *(void**)((char*)self + 0x434);
    vt = *(sMovieVEntryF4F8a**)o;
    if (vt[73].fn((char*)o + vt[73].delta) != 0) {
        func_00241180(self, 1);
    } else {
        sMovieVEntryF4F8b* vt2 = *(sMovieVEntryF4F8b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x11);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F578);
#ifdef SKIP_ASM
extern "C" void func_0023CC20(void* self);
extern "C" void func_00241180(void* self, int a1);

class cMovieDecoder_23F578 {
public:
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
    virtual int isPlaying();          // slot 42 (0x150)
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual int isFinished();         // slot 73 (0x248)
};
struct sMovieVEntry1_23F578 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023F578(char* self)
{
    *(int*)(self + 0x108) -= 1;
    *(float*)(self + 0x10C) = (float)*(int*)(self + 0xE4) / (float)*(int*)(self + 0xF0);
    if ((*(cMovieDecoder_23F578**)(self + 0x434))->isFinished() != 0) {
        func_00241180(self, 1);
        return;
    }
    if ((*(cMovieDecoder_23F578**)(self + 0x434))->isPlaying() == 1) {
        int a = *(int*)(self + 0xE4);
        int b = *(int*)(self + 0xF0);
        if (a < b) {
            if ((*(int (**)(int))(self + 4))(b - a) == 0) {
                func_00241180(self, 1);
            }
        } else {
            func_0023CC20(self);
            (*(void (**)())(self + 8))();
            sMovieVEntry1_23F578* vt1 = *(sMovieVEntry1_23F578**)(self + 0x748);
            vt1[1].fn(self + vt1[1].delta, 0x12);
        }
    } else {
        if ((*(cMovieDecoder_23F578**)(self + 0x434))->isFinished() != 0) {
            func_00241180(self, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023F698);
#ifdef SKIP_ASM
extern "C" void func_0023EB50(void* self);
extern "C" int func_00241CD8(void* self);
extern "C" void func_00242050(void* self);
extern "C" int func_003DBDB0(void* a, void* b);

struct sMovieVEntryF698 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sMovieVEntryF698i {
    short delta;
    short index;
    int (*fn)(void*, int);
};
struct sMovieVEntryF698ip {
    short delta;
    short index;
    void (*fn)(void*, int, void*);
};
struct sMovieVEntryF698b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline int ovCall_F698(char* s, int slot)
{
    void* o = *(void**)(s + 0x434);
    sMovieVEntryF698* vt = *(sMovieVEntryF698**)o;
    return vt[slot].fn((char*)o + vt[slot].delta);
}

static inline int ovCallI_F698(char* s, int slot, int a)
{
    void* o = *(void**)(s + 0x434);
    sMovieVEntryF698i* vt = *(sMovieVEntryF698i**)o;
    return vt[slot].fn((char*)o + vt[slot].delta, a);
}

static inline void ovCallIP_F698(char* s, int slot, int a, void* p)
{
    void* o = *(void**)(s + 0x434);
    sMovieVEntryF698ip* vt = *(sMovieVEntryF698ip**)o;
    vt[slot].fn((char*)o + vt[slot].delta, a, p);
}

static inline void post_F698(char* s, int code)
{
    sMovieVEntryF698b* vt = *(sMovieVEntryF698b**)(s + 0x748);
    vt[1].fn(s + vt[1].delta, code);
}

extern "C" void func_0023F698(void* self)
{
    char* s = (char*)self;
    if (*(int*)(s + 0x338))
        return;
    if (*(int*)(s + 0x128) && *(int*)(s + 0xC8)) {
        post_F698(s, 0x38);
        return;
    }
    int ready = func_00241CD8(self);
    if (!(*(int (**)())(s + 0x64))() && ready) {
        int f = *(int*)(s + 0x43C);
        if (f & 8) {
            func_0023EB50(self);
            return;
        }
        if (f & 0x10) {
            post_F698(s, 0x27);
            return;
        }
        if (f & 2) {
            post_F698(s, 0x30);
            return;
        }
        if (f & 1) {
            post_F698(s, 5);
            return;
        }
        if (f & 4) {
            post_F698(s, 0x17);
            return;
        }
    }
    if (*(int*)(s + 0xC8)) {
        *(int*)(s + 0xC8) = 0;
        func_00242050(self);
        return;
    }
    if ((*(int (**)())(s + 0x6C))()) {
        post_F698(s, 1);
        return;
    }
    if ((*(int (**)())(s + 0x64))()) {
        *(float*)(s + 0x110) = 1.0f;
        *(float*)(s + 0x114) = 0.016669999808073044f;
        if (*(int*)(s + 0xCC)) {
            if (ovCall_F698(s, 55) && ovCall_F698(s, 58) && !ovCall_F698(s, 51) && !ovCall_F698(s, 59)) {
                if (!ovCallI_F698(s, 67, *(int*)(s + 0xF8))) {
                    int a = ovCall_F698(s, 23);
                    if (ovCall_F698(s, 20) < a || !ovCall_F698(s, 25)) {
                        post_F698(s, 0x15);
                        return;
                    }
                }
                for (int i = 0; i < 6; i++) {
                    if (ovCallI_F698(s, 67, i)) {
                        char buf[0x200];
                        ovCallIP_F698(s, 14, i, buf);
                        if (func_003DBDB0(s + 0x276, buf) == 0 && i != *(int*)(s + 0xF8)) {
                            post_F698(s, 0x37);
                            return;
                        }
                    }
                }
                if (ovCallI_F698(s, 67, *(int*)(s + 0xF8))) {
                    ovCallIP_F698(s, 14, *(int*)(s + 0xF8), s + 0x234);
                    post_F698(s, 9);
                    return;
                }
                post_F698(s, 0xD);
            } else {
                post_F698(s, 0xA);
                return;
            }
        } else if (ovCallI_F698(s, 65, *(int*)(s + 0xF8))) {
            post_F698(s, 0x16);
        } else if (ovCallI_F698(s, 66, *(int*)(s + 0xF8))) {
            post_F698(s, 0x17);
        } else if (!ovCall_F698(s, 53)) {
            post_F698(s, 0x14);
        }
    }
    if ((*(int (**)())(s + 0x68))() && *(int*)(s + 0xD4)) {
        ovCallIP_F698(s, 14, *(int*)(s + 0xF8), s + 0x234);
        post_F698(s, 0x18);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FAE0);
#ifdef SKIP_ASM
extern "C" void func_0023FB20(void* self, int v);

extern "C" void func_0023FAE0(void* self)
{
    int cur = *(int*)((char*)self + 0x428);
    if (*(int*)((char*)self + 0x444) != cur) {
        *(int*)((char*)self + 0x444) = cur;
        *(int*)((char*)self + 0x43C) = 0;
        *(int*)((char*)self + 0x440) = 0;
    }
    func_0023FB20(self, *(int*)((char*)self + 0x428));
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FB18__FPvi);
#ifdef SKIP_ASM
void func_0023FB18(void* self, int val)
{
    *(int*)((char*)self + 0x428) = val;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FB20);
#ifdef SKIP_ASM
extern "C" void func_0023FB20(void* self, int v)
{
    *(int*)((char*)self + 0x42C) = v;
    void* obj = *(void**)((char*)self + 0x434);
    sMovieVEntry2* vt = *(sMovieVEntry2**)obj;
    vt[5].fn((char*)obj + vt[5].delta, v);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FB58);
#ifdef SKIP_ASM
struct sMovieVEntryFB58 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void* func_0023D570(void* self, int v);

extern "C" void* func_0023FB58(void* self)
{
    *(int*)((char*)self + 0x430) = -1;
    *(int*)((char*)self + 0x42C) = 0;
    *(int*)((char*)self + 0xBC) = 0;
    *(int*)((char*)self + 0xC0) = 0;
    *(int*)((char*)self + 0xC4) = 0;
    sMovieVEntryFB58* vt = *(sMovieVEntryFB58**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, 0);
    return func_0023D570(self, 1);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FBB8);
#ifdef SKIP_ASM
extern "C" void func_0023FBB8(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    (*(int*)((char*)self + 0x108))--;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v73() != 0) {
            me->v01(0x14);
            return;
        }
        if (*(int*)((char*)self + 0x108) <= 0) {
            (*(void (**)())((char*)self + 0xC))();
            me->v01(0x13);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FC70);
#ifdef SKIP_ASM
struct sMovieVEntryFC70a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntryFC70b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023FC70(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryFC70a* vt = *(sMovieVEntryFC70a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            sMovieVEntryFC70b* vt2 = *(sMovieVEntryFC70b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 3);
        } else if ((*(int (**)())((char*)self + 0x84))() != 0) {
            sMovieVEntryFC70b* vt2 = *(sMovieVEntryFC70b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 6);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FD08);
#ifdef SKIP_ASM
extern "C" void func_0023EA30(void* self, int v);

extern "C" void func_0023FD08(void* self)
{
    func_0023EA30(self, 1);
    (*(void (**)())((char*)self + 0x38))();
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FD40);
#ifdef SKIP_ASM
extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

class cMovieDecoder_23FD40 {
public:
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
    virtual int isBusy();                      // slot 11 (0x58)
    virtual void v12();
    virtual void v13();
    virtual void play(int a, void* b);          // slot 14 (0x70)
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
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual int isReady();                     // slot 53 (0x1A8)
};

struct sMovieVEntry_23FD40 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void setState_23FD40(char* self, int s)
{
    sMovieVEntry_23FD40* vt = *(sMovieVEntry_23FD40**)(self + 0x748);
    vt[1].fn(self + vt[1].delta, s);
}

extern "C" void func_0023FD40(char* self)
{
    if ((*(cMovieDecoder_23FD40**)(self + 0x434))->isBusy() != 0) {
        return;
    }
    if (*(int*)(self + 0x338) == 0 && (*(cMovieDecoder_23FD40**)(self + 0x434))->isReady() == 0) {
        setState_23FD40(self, 4);
        return;
    }
    if ((*(int (**)())(self + 0x6C))() != 0) {
        func_0023EA30(self, 0);
        return;
    }
    if ((*(int (**)())(self + 0x84))() != 0) {
        func_0023EA90(self);
        return;
    }
    if ((*(int (**)())(self + 0x68))() != 0) {
        (*(cMovieDecoder_23FD40**)(self + 0x434))->play(*(int*)(self + 0xF8), self + 0x234);
        setState_23FD40(self, 0x19);
        return;
    }
    if ((*(int (**)())(self + 0x70))() != 0) {
        setState_23FD40(self, 0xD);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FE70);
#ifdef SKIP_ASM
struct sMovieVEntryFE70 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_0023FE70(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntryFE70* vt = *(sMovieVEntryFE70**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 1);
        } else if ((*(int (**)())((char*)self + 0x84))() != 0) {
            func_0023EA90(self);
        } else {
            (*(void (**)())((char*)self + 0x68))();
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FF00);
#ifdef SKIP_ASM
extern "C" void func_0023FF00(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    int n = *(int*)((char*)self + 0x108);
    if (n > 0) {
        *(int*)((char*)self + 0x108) = n - 1;
        return;
    }
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v73() != 0) {
            me->v01(0x24);
            (*(void (**)())((char*)self + 0x2C))();
        } else {
            me->v01(0x23);
            (*(void (**)())((char*)self + 0x28))();
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FFC0);
#ifdef SKIP_ASM
extern "C" void func_0023FFC0(void* self)
{
    sMovieVEntry2* vt = *(sMovieVEntry2**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, 1);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_0023FFF0);
#ifdef SKIP_ASM
extern "C" void func_0023FFF0(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v53() == 0) {
            me->v01(4);
            return;
        }
        if ((*(int (**)())((char*)self + 0x78))() != 0) {
            me->v01(0x1F);
            return;
        }
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            me->v01(0x1D);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002400B0);
#ifdef SKIP_ASM
struct sMovieVEntry00B0a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntry00B0b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_002400B0(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry00B0a* vt = *(sMovieVEntry00B0a**)o;
    if (vt[73].fn((char*)o + vt[73].delta) != 0) {
        sMovieVEntry00B0b* vt2 = *(sMovieVEntry00B0b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x24);
        (*(void (**)())((char*)self + 0x2C))();
    } else {
        sMovieVEntry00B0b* vt2 = *(sMovieVEntry00B0b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x20);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240130);
#ifdef SKIP_ASM
extern "C" void func_0023CA70(void* self);
extern "C" void func_00241240(void* self);

class cMovieSub434_0130 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual void v40(int);
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
};

extern "C" void func_00240130(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    *(int*)((char*)self + 0x108) -= 1;
    int n = (*(cMovieSub434_0130**)((char*)self + 0x434))->v18();
    *(float*)((char*)self + 0x10C) = (float)n / (float)*(int*)((char*)self + 0xF0);
    if ((*(cMovieSub434_0130**)((char*)self + 0x434))->v73() != 0) {
        me->v01(0x24);
        (*(void (**)())((char*)self + 0x2C))();
        return;
    }
    if ((*(cMovieSub434_0130**)((char*)self + 0x434))->v31() == 1) {
        int a = *(int*)((char*)self + 0xE8);
        int b = *(int*)((char*)self + 0xF0);
        if (a < b) {
            if ((*(int (**)(int))((char*)self + 0x1C))(b - a) == 0)
                func_00241240(self);
        } else if ((*(int (**)())((char*)self + 0x20))() == 0) {
            (*(cMovieSub434_0130**)((char*)self + 0x434))->v40(*(int*)((char*)self + 0xF8));
            func_00241240(self);
        } else {
            func_0023CA70(self);
            me->v01(0x21);
        }
        return;
    }
    if ((*(cMovieSub434_0130**)((char*)self + 0x434))->v73() != 0) {
        (*(void (**)())((char*)self + 0x2C))();
        me->v01(0x24);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002402D0);
#ifdef SKIP_ASM
extern "C" int func_00241CD8(void* self);
extern "C" void func_0023EB50(void* self);
extern "C" void func_00241FD0(void* self);
extern "C" void func_00242050(void* self);

struct sMovieVEntry02D0a {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

struct sMovieVEntry02D0b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline sMovieVEntry02D0a* Pad_02D0(void* self, char** po)
{
    *po = *(char**)((char*)self + 0x434);
    return *(sMovieVEntry02D0a**)*po;
}

static inline int Pad0_02D0(void* self, int slot)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry02D0a* vt = *(sMovieVEntry02D0a**)o;
    return vt[slot].fn((char*)o + vt[slot].delta);
}

static inline int Pad1_02D0(void* self, int slot, int a)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry02D0a* vt = *(sMovieVEntry02D0a**)o;
    return vt[slot].fn((char*)o + vt[slot].delta, a);
}

static inline void Post_02D0(void* self, int code)
{
    sMovieVEntry02D0b* vt = *(sMovieVEntry02D0b**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, code);
}

#define S_02D0 ((char*)self)
#define CB_02D0(off) (*(int (**)())(S_02D0 + (off)))()

extern "C" void func_002402D0(void* self)
{
    if (*(int*)(S_02D0 + 0x338))
        return;
    int quit = 0;
    if (*(int*)(S_02D0 + 0xBC) || *(int*)(S_02D0 + 0xC0) || CB_02D0(0x78))
        quit = 1;
    int held = *(int*)(S_02D0 + 0x43C);
    int ready = func_00241CD8(self);
    if (!CB_02D0(0x78) && ready) {

        if (*(int*)(S_02D0 + 0x43C) & 8) {
            if (*(int*)(S_02D0 + 0x124) || CB_02D0(0x78) || CB_02D0(0x68) || quit) {
                func_0023EB50(self);
                return;
            }
        } else {
            if (*(int*)(S_02D0 + 0x120) && (*(int*)(S_02D0 + 0x43C) & 0x10)) {
                Post_02D0(self, 0x27);
                return;
            }
            if (*(int*)(S_02D0 + 0x43C) & 1) {
                Post_02D0(self, 5);
                return;
            }
            if (*(int*)(S_02D0 + 0x11C) && (*(int*)(S_02D0 + 0x43C) & 4)) {
                Post_02D0(self, 0x17);
                return;
            }
        }
        if (!(*(int*)(S_02D0 + 0x43C) & 8) && (held & 8)) {
            func_00241FD0(self);
            return;
        }
        int rel = held & ~4;
        if (*(int*)(S_02D0 + 0x43C) == 0 && rel) {
            func_00241FD0(self);
            return;
        }
    }
    if (!quit) {
        if (*(int*)(S_02D0 + 0xC8)) {
            *(int*)(S_02D0 + 0xC8) = 0;
            func_00242050(self);
        }
        if (*(int*)(S_02D0 + 0x43C) & 8) {
            Post_02D0(self, 0x31);
            return;
        }
    }
    (*(void (**)())(S_02D0 + 0xA4))();
    if ((*(int*)(S_02D0 + 0x130) ^ 0x1D) != 0)
        return;
    if (CB_02D0(0x78)) {
        if (*(int*)(S_02D0 + 0xD0)) {
            Post_02D0(self, 0x1F);
            return;
        }
        if (!Pad0_02D0(self, 53)) {
            Post_02D0(self, 0x24);
            return;
        }
        if (!Pad1_02D0(self, 67, *(int*)(S_02D0 + 0xF8))) {
            Post_02D0(self, 0x25);
            return;
        }
        if (!Pad1_02D0(self, 65, *(int*)(S_02D0 + 0xF8)))
            return;
        Post_02D0(self, 0x25);
        return;
    }
    if (CB_02D0(0x68)) {
        if (!*(int*)(S_02D0 + 0xD4))
            return;
        char* o;
        sMovieVEntry02D0a* vt = Pad_02D0(self, &o);
        ((void (*)(void*, int, char*))vt[14].fn)(o + vt[14].delta, *(int*)(S_02D0 + 0xF8), S_02D0 + 0x234);
        Post_02D0(self, 0x18);
        return;
    }
    if (CB_02D0(0x6C))
        Post_02D0(self, 1);
}
#undef CB_02D0
#undef S_02D0
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002405D0);
#ifdef SKIP_ASM
extern "C" void func_002405D0(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    (*(int*)((char*)self + 0x108))--;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v73() != 0) {
            me->v01(0x24);
            (*(void (**)())((char*)self + 0x2C))();
            return;
        }
        if (*(int*)((char*)self + 0x108) <= 0) {
            me->v01(0x22);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240688);
#ifdef SKIP_ASM
extern "C" void func_0023EA30(void* self, int v);

extern "C" void func_00240688(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v53() == 0) {
            me->v01(4);
            return;
        }
        if ((*(cMovieSub434**)((char*)self + 0x434))->v73() != 0) {
            me->v01(0x1C);
            return;
        }
        if ((*(int (**)())((char*)self + 0x68))() != 0) {
            me->v01(0x19);
            return;
        }
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240768);
#ifdef SKIP_ASM
struct sMovieVEntry0768a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntry0768b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00240768(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry0768a* vt = *(sMovieVEntry0768a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        void* o2 = *(void**)((char*)self + 0x434);
        sMovieVEntry0768a* vtb = *(sMovieVEntry0768a**)o2;
        if (vtb[73].fn((char*)o2 + vtb[73].delta) != 0) {
            sMovieVEntry0768b* vt2 = *(sMovieVEntry0768b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 0x1C);
        } else {
            sMovieVEntry0768b* vt2 = *(sMovieVEntry0768b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 0x1A);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240800);
#ifdef SKIP_ASM
struct sMovieVEntry0800 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);

extern "C" void func_00240800(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry0800* vt = *(sMovieVEntry0800**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240860);
#ifdef SKIP_ASM
class cMovieDecoder_240860 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void setVolume(int v);  // slot 5 (0x28)
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual int isBusy();  // slot 11 (0x58)
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
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual int isFinished();  // slot 73 (0x248)
};

struct sMovieVEntry_240860 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void setState_240860(char* self, int s)
{
    sMovieVEntry_240860* vt = *(sMovieVEntry_240860**)(self + 0x748);
    vt[1].fn(self + vt[1].delta, s);
}

extern "C" void func_00240860(char* self)
{
    cMovieDecoder_240860* d = *(cMovieDecoder_240860**)(self + 0x434);
    if (*(int*)(self + 0x108) > 0) {
        if (d->isBusy() == 0) {
            if ((*(cMovieDecoder_240860**)(self + 0x434))->isFinished() != 0) {
                setState_240860(self, 0x1C);
                return;
            }
            (*(cMovieDecoder_240860**)(self + 0x434))->setVolume(*(int*)(self + 0x428));
        }
        *(int*)(self + 0x108) -= 1;
    } else {
        if (d->isBusy() != 0) {
            return;
        }
        if ((*(cMovieDecoder_240860**)(self + 0x434))->isFinished() != 0) {
            setState_240860(self, 0x1C);
        } else {
            setState_240860(self, 0x1B);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240960);
#ifdef SKIP_ASM
struct sMovieVEntry0960a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntry0960b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00240960(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry0960a* vt = *(sMovieVEntry0960a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x30))() != 0) {
            sMovieVEntry0960b* vt2 = *(sMovieVEntry0960b**)((char*)self + 0x748);
            vt2[1].fn((char*)self + vt2[1].delta, 6);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002409C8);
#ifdef SKIP_ASM
extern "C" void func_002409C8(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v53() == 0) {
            me->v01(4);
            return;
        }
        if ((*(cMovieSub434**)((char*)self + 0x434))->v73() != 0) {
            me->v01(0x14);
            return;
        }
        if ((*(int (**)())((char*)self + 0x70))() != 0) {
            me->v01(0xD);
            return;
        }
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            me->v01(1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240AB0);
#ifdef SKIP_ASM
extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_00240AB0(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v53() == 0) {
            me->v01(4);
            return;
        }
        if ((*(int (**)())((char*)self + 0x88))() != 0) {
            me->v01(0x28);
            return;
        }
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 1);
            return;
        }
        if ((*(int (**)())((char*)self + 0x84))() != 0) {
            func_0023EA90(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240B88);
#ifdef SKIP_ASM
extern "C" void func_00240B88(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    int t = (*(int*)((char*)self + 0x108))--;
    if (t <= 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
            if ((*(cMovieSub434**)((char*)self + 0x434))->v09() != 0) {
                me->v01(0x29);
            } else {
                me->v01(0x2A);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240C30);
#ifdef SKIP_ASM
struct sMovieVEntry0C30 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0023FB20(void* self, int v);

extern "C" void func_00240C30(void* self)
{
    if ((*(int (**)())((char*)self + 0x6C))() != 0) {
        sMovieVEntry0C30* vt = *(sMovieVEntry0C30**)((char*)self + 0x748);
        vt[1].fn((char*)self + vt[1].delta, 1);
        func_0023FB20(self, *(int*)((char*)self + 0x428));
        *(int*)((char*)self + 0x338) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240C90);
#ifdef SKIP_ASM
extern "C" void func_00240C90(void* self)
{
    sMovieVEntry2* vt = *(sMovieVEntry2**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, 6);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240CC0);
#ifdef SKIP_ASM
extern "C" void func_00240CC0(void* self)
{
    cMoviePlayerVt* me = (cMoviePlayerVt*)self;
    if ((*(cMovieSub434**)((char*)self + 0x434))->v11() == 0) {
        if ((*(cMovieSub434**)((char*)self + 0x434))->v53() == 0) {
            me->v01(4);
            return;
        }
        if ((*(int (**)())((char*)self + 0x68))() != 0) {
            me->v01(0x2C);
            return;
        }
        if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            me->v01(6);
            return;
        }
        (*(cMovieSub434**)((char*)self + 0x434))->v05(*(int*)((char*)self + 0x428));
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240D90);
#ifdef SKIP_ASM
class cMovieDecoder_240D90 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void seek(int i);  // slot 10 (0x50)
    virtual int isBusy();  // slot 11 (0x58)
    virtual void v12();
    virtual int getCount();  // slot 13 (0x68)
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
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual int canSeek(int i);  // slot 65 (0x208)
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual int isFinished();  // slot 73 (0x248)
};

struct sMovieVEntry_240D90 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void setState_240D90(char* self, int s)
{
    sMovieVEntry_240D90* vt = *(sMovieVEntry_240D90**)(self + 0x748);
    vt[1].fn(self + vt[1].delta, s);
}

extern "C" void func_00240D90(char* self)
{
    *(int*)(self + 0x108) -= 1;
    if ((*(cMovieDecoder_240D90**)(self + 0x434))->isBusy() != 0) {
        return;
    }
    if (*(int*)(self + 0x108) > 0) {
        return;
    }
    if ((*(cMovieDecoder_240D90**)(self + 0x434))->isFinished() != 0) {
        setState_240D90(self, 0x2D);
        return;
    }
    if (*(int*)(self + 0x438) < (*(cMovieDecoder_240D90**)(self + 0x434))->getCount()) {
        if ((*(cMovieDecoder_240D90**)(self + 0x434))->canSeek(*(int*)(self + 0x438)) != 0) {
            (*(cMovieDecoder_240D90**)(self + 0x434))->seek(*(int*)(self + 0x438));
        }
        *(int*)(self + 0x438) += 1;
    } else {
        setState_240D90(self, 0x2E);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240EB0);
#ifdef SKIP_ASM
extern "C" void func_00240EB0(void* self)
{
    sMovieVEntry2* vt = *(sMovieVEntry2**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, 1);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240EE0);
#ifdef SKIP_ASM
extern "C" void func_00240EE0(void* self)
{
    sMovieVEntry2* vt = *(sMovieVEntry2**)((char*)self + 0x748);
    vt[1].fn((char*)self + vt[1].delta, 6);
}
#endif

extern "C" void* func_0023FB58(void* self);

//100%
INCLUDE_ASM("movie/movieplayer", func_00240F10__FPv);
#ifdef SKIP_ASM
void* func_00240F10(void* self)
{
    return func_0023FB58(self);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240F30);
#ifdef SKIP_ASM
struct sMovieVEntry0F30 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0023EA30(void* self, int v);
extern "C" void func_0023EA90(void* self);

extern "C" void func_00240F30(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry0F30* vt = *(sMovieVEntry0F30**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        if ((*(int (**)())((char*)self + 0x84))() != 0) {
            func_0023EA90(self);
        } else if ((*(int (**)())((char*)self + 0x6C))() != 0) {
            func_0023EA30(self, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00240FB0);
#ifdef SKIP_ASM
struct sMovieVEntry0FB0 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int);
};

extern "C" void func_00240FB0(void* self, int a, int b, int c)
{
    void* o = *(void**)((char*)self + 0x434);
    D_004A2C78 = 1;
    sMovieVEntry0FB0* vt = *(sMovieVEntry0FB0**)o;
    vt[36].fn((char*)o + vt[36].delta, a, b, c);
    *(int*)((char*)self + 0xE4) = c;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241000);
#ifdef SKIP_ASM
extern int D_004A2C78;

struct sMovieVEntry1000 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int);
};

extern "C" void func_00241000(void* self, int a, int b, int c)
{
    void* o = *(void**)((char*)self + 0x434);
    D_004A2C78 = 1;
    sMovieVEntry1000* vt = *(sMovieVEntry1000**)o;
    vt[37].fn((char*)o + vt[37].delta, a, b, c);
    *(int*)((char*)self + 0xE4) = c;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241050);
#ifdef SKIP_ASM
struct sMovieVEntry1050 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int);
};

extern "C" void func_00241050(void* self, int a, int b, int c)
{
    void* o = *(void**)((char*)self + 0x434);
    D_004A2C78 = 1;
    sMovieVEntry1050* vt = *(sMovieVEntry1050**)o;
    vt[38].fn((char*)o + vt[38].delta, a, b, c);
    *(int*)((char*)self + 0xE4) = c;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002410A0);
#ifdef SKIP_ASM
extern "C" void func_002410A0(void* self)
{
    void* obj = *(void**)((char*)self + 0x434);
    sMovieVEntry* vt = *(sMovieVEntry**)obj;
    vt[12].fn((char*)obj + vt[12].delta);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002410D0);
#ifdef SKIP_ASM
struct sMovieVEntry_2410D0 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_002410D0(void* self)
{
    char* s = (char*)self;
    char* o = *(char**)(s + 0x434);
    sMovieVEntry_2410D0* vt = *(sMovieVEntry_2410D0**)o;
    if (*(int*)(s + 0xEC) < vt[68].fn(o + vt[68].delta)) {
        return *(int*)(s + 0xEC);
    }
    char* o2 = *(char**)(s + 0x434);
    sMovieVEntry_2410D0* vt2 = *(sMovieVEntry_2410D0**)o2;
    return vt2[68].fn(o2 + vt2[68].delta);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241138);
#ifdef SKIP_ASM
extern int D_004A2C78;

struct sMovieVEntry1138 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern "C" void func_00241138(void* self, int a, int b)
{
    void* o = *(void**)((char*)self + 0x434);
    int one = 1;
    *(int*)((char*)self + 0xE4) += b;
    D_004A2C78 = one;
    sMovieVEntry1138* vt = *(sMovieVEntry1138**)o;
    vt[41].fn((char*)o + vt[41].delta, a, b);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241180);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A2C78;
extern "C" void func_0023D570_v(void* self, int v) __asm__("func_0023D570");

struct sMovieVEntry1180a {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sMovieVEntry1180b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00241180(void* self, int a1)
{
    int on = *(int*)((char*)self + 0x118);
    D_004A2C78 = 0;
    if (on != 0) {
        void* o = *(void**)((char*)self + 0x434);
        sMovieVEntry1180a* vt = *(sMovieVEntry1180a**)o;
        vt[44].fn((char*)o + vt[44].delta);
    }
    if (a1 != 0) {
        func_0023D570_v(self, 0);
        sMovieVEntry1180b* vt2 = *(sMovieVEntry1180b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x14);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241200);
#ifdef SKIP_ASM
struct sMovieVEntry3 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern "C" void func_00241200(void* self, int a, int n)
{
    *(int*)((char*)self + 0xE8) += n;
    void* obj = *(void**)((char*)self + 0x434);
    sMovieVEntry3* vt = *(sMovieVEntry3**)obj;
    vt[30].fn((char*)obj + vt[30].delta, a, n);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241240);
#ifdef SKIP_ASM
struct sMovieVEntry1240a {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sMovieVEntry1240b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00241240(void* self)
{
    void* o = *(void**)((char*)self + 0x434);
    sMovieVEntry1240a* vt = *(sMovieVEntry1240a**)o;
    vt[33].fn((char*)o + vt[33].delta);
    sMovieVEntry1240b* vt2 = *(sMovieVEntry1240b**)((char*)self + 0x748);
    vt2[1].fn((char*)self + vt2[1].delta, 0x24);
    (*(void (**)())((char*)self + 0x2C))();
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002412A0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00152758(void* iface);
// PORT: func_00152948__FPv ignores its argument; this caller passes none.
int func_00152948_r() __asm__("func_00152948__FPv");
extern "C" unsigned short* func_002C2540(void*, void*);
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_00241D40(void* self, int mode, void* buf, int size);
extern "C" void func_00241AA0(void* buf, int size);
extern "C" void func_002C26D0_v(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern "C" void func_00241000_r(void* self, char* text, int a, int b) __asm__("func_00241000");
extern int D_004A2C78;
extern char D_0047C178[];

extern "C" void func_002412A0(void* self)
{
    char text[0x82];
    char name[0x82];
    char desc[0x200];
    char fmt[0x200];
    D_004A2C78 = 1;
    int a = func_00152758(cBE_getInterface_Fv(cBE_getBE(), 5));
    int b = func_00152948_r();
    func_002C2540(fmt, D_0047C178);
    func_00241D40(self, 2, name, 0x82);
    func_00241AA0(desc, 0x200);
    func_002C26D0_v(text, fmt, desc, name, *(int*)((char*)self + 0xF8) + 1);
    func_00241000_r(self, text, a, b);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241380);
#ifdef SKIP_ASM
struct sMovieVEntry1380 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00241380(void* self)
{
    int one = 1;
    void* o;
    sMovieVEntry1380* vt;
    *(int*)((char*)self + 0x340) = one;
    *(int*)((char*)self + 0xDC) = 0;
    *(int*)((char*)self + 0x42C) = 0;
    *(int*)((char*)self + 0xF8) = 0;
    *(int*)((char*)self + 0x430) = -1;
    *(int*)((char*)self + 0xFC) = -1;
    *(int*)((char*)self + 0x444) = -1;
    func_0023FB18(self, 0);
    func_0023FAE0(self);
    *(int*)((char*)self + 0x338) = one;
    *(int*)((char*)self + 0x130) = 2;
    o = *(void**)((char*)self + 0x434);
    vt = *(sMovieVEntry1380**)o;
    vt[3].fn((char*)o + vt[3].delta);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241400);
#ifdef SKIP_ASM
class cMovieDecoder_241400 {
public:
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
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual int hasChapter(int i);  // slot 52 (0x1A0)
};

extern "C" void func_0023FAE0(void* self);
void func_0023FB18(void* self, int val);

static inline int nextChapter_241400(char* self, int i)
{
    if (i < *(int*)(self + 0x424) - 1) {
        return i + 1;
    }
    if (*(int*)(self + 0x100) != 0) {
        return 0;
    }
    return i;
}

extern "C" void func_00241400(char* self)
{
    int i = *(int*)(self + 0x428);
    if (*(int*)(self + 0x424) == -1) {
        return;
    }
    while (i = nextChapter_241400(self, i), (*(cMovieDecoder_241400**)(self + 0x434))->hasChapter(i) == 0) {
        if (i == *(int*)(self + 0x424) - 1 || *(int*)(self + 0x100) != 0) {
            if (i == *(int*)(self + 0x428)) {
                break;
            }
            if (*(int*)(self + 0x100) != 1) {
                break;
            }
        }
    }
    if (*(int*)(self + 0x100) == 0 && i == *(int*)(self + 0x424) - 1 && (*(cMovieDecoder_241400**)(self + 0x434))->hasChapter(i) == 0) {
        i = *(int*)(self + 0x428);
        if ((*(cMovieDecoder_241400**)(self + 0x434))->hasChapter(i) == 0) {
            i = 0;
        }
    }
    if (*(int*)(self + 0x428) != i) {
        func_0023FB18(self, i);
        func_0023FAE0(self);
    }
    *(int*)(self + 0xE0) = 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241540);
#ifdef SKIP_ASM
class cMovieDecoder_241540 {
public:
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
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual int hasChapter(int i);  // slot 52 (0x1A0)
};

extern "C" void func_0023FAE0(void* self);
void func_0023FB18(void* self, int val);

static inline int prevChapter_241540(char* self, int i)
{
    if (i > 0) {
        return i - 1;
    }
    if (*(int*)(self + 0x100) != 0) {
        return *(int*)(self + 0x424) - 1;
    }
    return i;
}

extern "C" void func_00241540(char* self)
{
    int i = *(int*)(self + 0x428);
    if (*(int*)(self + 0x424) == -1) {
        return;
    }
    while (i = prevChapter_241540(self, i), (*(cMovieDecoder_241540**)(self + 0x434))->hasChapter(i) == 0) {
        if (i == 0 || *(int*)(self + 0x100) != 0) {
            if (i == *(int*)(self + 0x428)) {
                break;
            }
            if (*(int*)(self + 0x100) != 1) {
                break;
            }
        }
    }
    if (*(int*)(self + 0x100) == 0 && i == 0 && (*(cMovieDecoder_241540**)(self + 0x434))->hasChapter(0) == 0) {
        i = *(int*)(self + 0x428);
        if ((*(cMovieDecoder_241540**)(self + 0x434))->hasChapter(i) == 0) {
            i = 0;
        }
    }
    if (*(int*)(self + 0x428) != i) {
        func_0023FB18(self, i);
        func_0023FAE0(self);
    }
    *(int*)(self + 0xE0) = 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241678);
#ifdef SKIP_ASM
extern "C" void func_00241678(void* self)
{
    int n = *(int*)((char*)self + 0xF8);
    if (n > 0) {
        *(int*)((char*)self + 0xF8) = n - 1;
    } else if (*(int*)((char*)self + 0x100) != 0) {
        *(int*)((char*)self + 0xF8) = func_002410D0(self) - 1;
    }
}
#endif
//100%
INCLUDE_ASM("movie/movieplayer", func_002416C0);
#ifdef SKIP_ASM
extern "C" void func_002416C0(void* self)
{
    int n = func_002410D0(self) - 1;
    int cur = *(int*)((char*)self + 0xF8);
    if (cur < n) {
        *(int*)((char*)self + 0xF8) = cur + 1;
    } else if (*(int*)((char*)self + 0x100) != 0) {
        *(int*)((char*)self + 0xF8) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", cMCOverlayManager_GetDeviceDisplayString);
#ifdef SKIP_ASM
// PORT: callers pass more args than the unit's declarations of these take.
extern "C" void func_002C26D0_v(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern "C" void* func_002C2508(void* dst, void* src);
extern "C" int func_002C24D0(void* s);
extern "C" void func_00241DC8(void* self, void* dst, int n);
int GetHashValue32(char* s);
extern void* D_004A28A8;
extern char D_0047C360[];
extern char D_0047C378[];
extern char D_0047C390[];

class cMovieSub434_1710 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48(int);
    virtual int v49();
    virtual int v50(int);
    virtual int v51();
    virtual int v52(int);
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56(int);
    virtual int v57(int);
    virtual int v58();
    virtual int v59();
    virtual int v60(int);
};

struct sLocVEntry_241710 {
    short delta;
    short index;
    void* (*fn)(void*, int);
};

struct sMCDev_241710 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    char name[0xE0 - 0x18];
};

struct sMCOverlayMgr_241710 {
    char pad[0x344];
    sMCDev_241710 dev[1];
};

static inline void* Loc_241710(char* key)
{
    char* loc = *(char**)((char*)D_004A28A8 + 0x8C);
    sLocVEntry_241710* vt = *(sLocVEntry_241710**)(loc + 4);
    char* thisp = loc + vt[4].delta;
    return vt[4].fn(thisp, GetHashValue32(key));
}

extern "C" void cMCOverlayManager_GetDeviceDisplayString(void* self, int idx, char* dst, int len)
{
    char buf[0x200];
    if ((*(cMovieSub434_1710**)((char*)self + 0x434))->v52(idx))
    {
        if ((*(cMovieSub434_1710**)((char*)self + 0x434))->v48(idx) || (*(cMovieSub434_1710**)((char*)self + 0x434))->v50(idx) || (*(cMovieSub434_1710**)((char*)self + 0x434))->v60(idx))
        {
            func_00241DC8(self, buf, idx);
            func_002C26D0_v(dst, Loc_241710(D_0047C360), buf);
        }
        else if (!(*(cMovieSub434_1710**)((char*)self + 0x434))->v56(idx))
        {
            func_00241DC8(self, buf, idx);
            func_002C26D0_v(dst, Loc_241710(D_0047C378), buf);
        }
        else if ((*(cMovieSub434_1710**)((char*)self + 0x434))->v57(idx))
        {
            func_00241DC8(self, buf, idx);
            char* name = ((sMCOverlayMgr_241710*)self)->dev[idx].name;
            if (func_002C24D0(name) == 0)
                func_002C26D0_v(dst, Loc_241710(D_0047C390), buf);
            else
                func_002C2508(dst, name);
        }
    }
    else
    {
        func_00241DC8(self, buf, idx);
        func_002C26D0_v(dst, Loc_241710(D_0047C360), buf);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241928);
#ifdef SKIP_ASM
extern char D_004A2C90[];
extern char D_004A2C98[];
// PORT: this caller treats func_002C2540 (a string copy) as returning int.
unsigned short* func_002C2540_i(void*, void*) __asm__("func_002C2540");
struct sMovieItem1928 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    char pad[0xE0 - 0x14];
};
struct sMovie1928 {
    char pad[0x344];
    sMovieItem1928 items[1];
};
extern "C" void func_00241928(sMovie1928* self, int idx, void* dst)
{
    char a[0x200];
    char b[0x200];
    if (self->items[idx].fC != 0 && self->items[idx].f0 != 0 && self->items[idx].f4 != 0 && self->items[idx].f8 != 0) {
        func_002C2540_i(a, D_004A2C90);
        func_002C2540_i(b, D_004A2C98);
        func_002C26D0_v(dst, b, self->items[idx].f10, a);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002419D8);
#ifdef SKIP_ASM
extern "C" int func_002419D8(void* self, int a1)
{
    char* p = (char*)self + a1 * 0xe0;
    return *(int*)(p + 0x354);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", cMCOverlayManager_GetDeviceTotalString);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" unsigned short* func_002C2540_r(void*, void*) __asm__("func_002C2540");
extern "C" void func_002C26D0_v(void* dst, void* fmt, ...) __asm__("func_002C26D0");
extern char D_004A2CA0[];
extern char D_004A2C98[];

struct sMCDev {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    char pad[0xE0 - 0x18];
};
struct sMCOverlayMgr {
    char pad[0x344];
    sMCDev dev[1];
};

extern "C" void cMCOverlayManager_GetDeviceTotalString(sMCOverlayMgr* self, int idx, void* dst)
{
    unsigned short str[256];
    unsigned short fmt[256];
    if (self->dev[idx].fC == 0) return;
    if (self->dev[idx].f0 && self->dev[idx].f4 && self->dev[idx].f8) {
        func_002C2540_r(str, D_004A2CA0);
        func_002C2540_r(fmt, D_004A2C98);
        func_002C26D0_v(dst, fmt, self->dev[idx].f14, str);
    }
}
#endif

struct sPad16 { char x; int pad[3]; };
extern sPad16 D_0047C3A8;
extern "C" unsigned short* func_002C2540(void*, void*);

//100%
INCLUDE_ASM("movie/movieplayer", func_00241AA0);
#ifdef SKIP_ASM
extern "C" void func_00241AA0(void* self, int n)
{
    func_002C2540(self, &D_0047C3A8);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241AC0);
#ifdef SKIP_ASM
struct sMovieVEntry1AC0 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_00241AC0(void* self)
{
    if (*(int*)((char*)self + 0x424) < 0) {
        void* o = *(void**)((char*)self + 0x434);
        sMovieVEntry1AC0* vt = *(sMovieVEntry1AC0**)o;
        int n = vt[69].fn((char*)o + vt[69].delta);
        *(int*)((char*)self + 0x424) = n;
        if (n >= 2) {
            *(int*)((char*)self + 0x424) = 1;
        }
    }
    return *(int*)((char*)self + 0x424);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241B20);
#ifdef SKIP_ASM
class cMovieSub434_1B20 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual bool v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
};

struct sMovieFlags_1B20
{
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int c : 1;
    unsigned int d : 1;
    unsigned int e : 1;
    unsigned int f : 4;
    unsigned int rest : 23;
};

// PORT: the unit declares func_00241B20 as returning int; it really returns this 4-byte flags struct in $v0.
extern "C" sMovieFlags_1B20 func_00241B20_s(void* self) __asm__("func_00241B20");

extern "C" sMovieFlags_1B20 func_00241B20_s(void* self)
{
    if (*(int*)((char*)self + 0x42C) != *(int*)((char*)self + 0x428))
        return *(sMovieFlags_1B20*)((char*)self + 0x43C);
    sMovieFlags_1B20 s = {0, 0, 0, 0, 0, 0, 0};
    s.a = (*(cMovieSub434_1B20**)((char*)self + 0x434))->v49();
    int b = (*(cMovieSub434_1B20**)((char*)self + 0x434))->v51() || (*(cMovieSub434_1B20**)((char*)self + 0x434))->v59();
    s.b = b;
    int c = !(*(cMovieSub434_1B20**)((char*)self + 0x434))->v13() && (*(cMovieSub434_1B20**)((char*)self + 0x434))->v20() < (*(cMovieSub434_1B20**)((char*)self + 0x434))->v23();
    s.c = c;
    s.d = !(*(cMovieSub434_1B20**)((char*)self + 0x434))->v53();
    int e = !(*(cMovieSub434_1B20**)((char*)self + 0x434))->v55() || !(*(cMovieSub434_1B20**)((char*)self + 0x434))->v58();
    s.e = e;
    s.f = 0;
    return s;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("movie/movieplayer", func_00241CD8);
#ifdef SKIP_ASM
extern "C" int func_00241B20(void* self);

extern "C" int func_00241CD8(void* self)
{
    int v = func_00241B20(self);
    int changed = *(int*)((char*)self + 0x43C) != v;
    if (*(int*)((char*)self + 0x440) == 0 || changed) {
        *(int*)((char*)self + 0x43C) = v;
        if (changed) {
            *(int*)((char*)self + 0x440) = (*(int (**)(int))((char*)self + 0xB0))(v);
        }
        return *(int*)((char*)self + 0x440) ^ 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241D40);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C2540(void*, void*);
extern char D_004A2CA8[];
extern char D_004A2CB0[];
extern char D_004A2CB8[];

extern "C" void func_00241D40(void* self, int mode, void* buf, int n)
{
    switch (mode) {
    case 0:
        func_002C2540(buf, D_004A2CA8);
        break;
    case 1:
        func_002C2540(buf, D_004A2CB0);
        break;
    case 2:
        func_002C2540(buf, D_004A2CB8);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241DC0);
#ifdef SKIP_ASM
extern "C" int func_00241DC0(void) {
    return 0x30;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241DC8);
#ifdef SKIP_ASM
extern "C" void func_002C26D0(void* dst, void* src, int n);
extern char D_004A2C28[];

extern "C" void func_00241DC8(void* self, void* dst, int n)
{
    unsigned short buf[256];
    func_002C2540(buf, D_004A2C28);
    func_002C26D0(dst, buf, n + 1);
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241E18);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_00241DC8(void* self, void* dst, int n);
extern "C" void* func_002C2508(void* dst, void* src);
extern void* D_004A28A8;
extern char D_004A29E8[];
extern char D_0047C3B8[];
extern char D_0047C360[];
extern char D_0047C3D0[];
extern char D_0047C3E8[];
extern char D_0047C408[];
extern char D_0047C420[];

struct sVEntry_00241E18 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc_00241E18(char* key)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_00241E18* vt = *(sVEntry_00241E18**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(key));
}

static inline void SetText_00241E18(void* out, char* key, void* arg)
{
    int str = Loc_00241E18(key);
    func_002C26D0_v(out, (void*)str, arg);
}

extern "C" void func_00241E18(char* self, void* out, int n)
{
    unsigned short num[256];
    unsigned short num2[256];
    func_002C2540(out, D_004A29E8);
    func_00241DC8(self, num, *(int*)(self + 0x428));
    switch (*(int*)(self + 0x130)) {
    case 0: case 2: case 3: case 6: case 7: case 13: case 29:
    case 49: case 50: case 51: case 52: case 53: case 54:
        SetText_00241E18(out, D_0047C3B8, num);
        break;
    case 4:
        func_00241DC8(self, num2, *(int*)(self + 0x428));
        SetText_00241E18(out, D_0047C360, num2);
        break;
    case 10: case 11: case 39: case 40:
        SetText_00241E18(out, D_0047C3D0, num);
        break;
    case 15: case 16: case 17: case 18:
        SetText_00241E18(out, D_0047C3E8, num);
        break;
    case 31: case 32: case 33: case 34:
        SetText_00241E18(out, D_0047C408, num);
        break;
    case 25: case 26: case 44:
        func_002C2508(out, (void*)Loc_00241E18(D_0047C420));
        break;
    case 55:
        break;
    }
}
#endif

extern "C" void* func_002420C8(void*, int);

//100%
INCLUDE_ASM("movie/movieplayer", func_00241FB0__FPv);
#ifdef SKIP_ASM
void* func_00241FB0(void* self)
{
    return func_002420C8(self, *(int*)((char*)self + 0x42c));
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00241FD0);
#ifdef SKIP_ASM
struct sMovieVEntry1FD0a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntry1FD0b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00241FD0(void* self)
{
    void* o;
    sMovieVEntry1FD0a* vt;
    (*(void (**)())((char*)self + 0xAC))();
    o = *(void**)((char*)self + 0x434);
    vt = *(sMovieVEntry1FD0a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        sMovieVEntry1FD0b* vt2 = *(sMovieVEntry1FD0b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x33);
    } else {
        sMovieVEntry1FD0b* vt2 = *(sMovieVEntry1FD0b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 0x35);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00242050);
#ifdef SKIP_ASM
struct sMovieVEntry2050a {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMovieVEntry2050b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00242050(void* self)
{
    void* o;
    sMovieVEntry2050a* vt;
    *(int*)((char*)self + 0x338) = 0;
    o = *(void**)((char*)self + 0x434);
    vt = *(sMovieVEntry2050a**)o;
    if (vt[11].fn((char*)o + vt[11].delta) == 0) {
        sMovieVEntry2050b* vt2 = *(sMovieVEntry2050b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 2);
    } else {
        sMovieVEntry2050b* vt2 = *(sMovieVEntry2050b**)((char*)self + 0x748);
        vt2[1].fn((char*)self + vt2[1].delta, 3);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002420C8);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* p, int c, int n);

class cMovieSub434_20C8 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48(int);
    virtual int v49();
    virtual int v50(int);
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56(int);
    virtual int v57(int);
    virtual int v58();
    virtual int v59();
    virtual int v60(int);
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual void v70(int, char*, int);
};

struct sSlot_20C8
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    char name[200];
};

struct sMP_20C8
{
    char pad0[0x344];
    sSlot_20C8 slots[1];
    int f424;
    int f428;
    int cur;
};

// PORT: the unit declares func_002420C8 as returning void*, but it returns nothing; bind the void body by asm label.
extern "C" void func_002420C8_v(void* self, int i) __asm__("func_002420C8");

extern "C" void func_002420C8_v(void* self, int i)
{
    sMP_20C8* me = (sMP_20C8*)self;
    me->slots[i].a = 1;
    char* bb = (char*)self + 0x348;
    int* pb = (int*)(bb + i * 0xE0);
    char* bc = (char*)self + 0x34C;
    int* pc = (int*)(bc + i * 0xE0);
    *pb = 1;
    *pc = 1;
    char* name = me->slots[i].name;
    me->slots[i].d = 1;
    func_003E6448(name, 0, 200);
    if ((*(cMovieSub434_20C8**)((char*)self + 0x434))->v48(i) || (*(cMovieSub434_20C8**)((char*)self + 0x434))->v50(i) || (*(cMovieSub434_20C8**)((char*)self + 0x434))->v60(i))
    {
        me->slots[i].a = 0;
        return;
    }
    if (!(*(cMovieSub434_20C8**)((char*)self + 0x434))->v56(i))
    {
        *pb = 0;
        return;
    }
    if (!(*(cMovieSub434_20C8**)((char*)self + 0x434))->v57(i))
    {
        *pc = 0;
        return;
    }
    if (i == me->cur)
        me->slots[me->cur].e = (*(cMovieSub434_20C8**)((char*)self + 0x434))->v20();
    (*(cMovieSub434_20C8**)((char*)self + 0x434))->v70(i, name, 100);
}
#endif

INCLUDE_ASM("movie/movieplayer", func_00242288);

//100%
INCLUDE_ASM("movie/movieplayer", func_002424C8);
#ifdef SKIP_ASM
extern int D_004A2C78;
extern void* D_0047CBD8[];
void operator_delete(int*);

extern "C" void func_002424C8(void* self, int flags)
{
    *(void***)((char*)self + 0x748) = D_0047CBD8;
    D_004A2C78 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00242500__FPv);
#ifdef SKIP_ASM
void* func_00242500(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)((char*)self + 0x108) = t0;
    *(int*)((char*)self + 0x10c) = t0;
    *(int*)self = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00242518);
#ifdef SKIP_ASM
void operator_delete(int*);

extern "C" void func_00242518(void* self, int flags)
{
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00242540);
#ifdef SKIP_ASM
struct sMovieNode {
    char pad_0x0[0xbc];
    sMovieNode* next; // 0xbc
    sMovieNode* prev; // 0xc0
};

struct sMovieList {
    sMovieNode* head; // 0x0
    int count;        // 0x4
};

extern "C" void func_00242540(sMovieList* list, sMovieNode* node)
{
    node->next = list->head;
    node->prev = 0;
    if (list->head != 0) {
        list->head->prev = node;
    }
    list->head = node;
    list->count++;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00242570);
#ifdef SKIP_ASM
extern "C" void func_00242570(sMovieList* list, sMovieNode* node)
{
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node == list->head) {
        list->head = node->next;
    }
    list->count--;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002425C0);
#ifdef SKIP_ASM
extern "C" void func_002429B0(void* self, const void* eye, void* frustum);
extern "C" void func_00229F88(int index, void* v, void* m);
extern "C" int func_00418EF8(void* base, int n, int size, int (*cmp)(const void*, const void*));
extern "C" int func_00242978(const void* a, const void* b);

struct sVec4_25C0 {
    float x, y, z, w;
    sVec4_25C0() {}
    sVec4_25C0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sMtx_25C0 {
    sVec4_25C0 r[4];
};

struct sBox_25C0 {
    sVec4_25C0 min;
    sVec4_25C0 max;
};

struct sBounds_25C0 {
    float minx, miny, minz, pad0C;
    float maxx, maxy, maxz;
};

struct sView_25C0 {
    sVec4_25C0 pos;         // 0x00
    char pad10[0x50 - 0x10];
    sVec4_25C0 normal;      // 0x50
    char pad60[0xA0 - 0x60];
    float minx, miny, minz; // 0xA0
    float maxx, maxy, maxz; // 0xAC
    char padB8[4];
    sView_25C0* next;       // 0xBC
};

struct sVisEnt_25C0 {
    sView_25C0* view;
    float dist;
};

struct sVisMgr_25C0 {
    sView_25C0* head;       // 0x00
    int enabled;            // 0x04
    sVisEnt_25C0 ents[32];  // 0x08
    int count;              // 0x108
    int nvis;               // 0x10C
    int mask;               // 0x110
};

struct sCamVt_25C0 {
    short delta;
    short index;
    void* fn;
};

struct sCam_25C0 {
    char pad0[0x10D8];
    sCamVt_25C0* vt;        // 0x10D8
};

extern sCam_25C0* D_004A289C;

typedef sMtx_25C0 (*tCamMtx_25C0)(void*);
typedef sMtx_25C0* (*tCamMtxP_25C0)(void*);
typedef bool (*tCamCull_25C0)(void*, sVec4_25C0*, sVec4_25C0*, sMtx_25C0*);

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_25C0 vu0Scale_25C0(const sVec4_25C0& v, float s)
{
    sVec4_25C0 r;
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_25C0(const sVec4_25C0& a, const sVec4_25C0& b)
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

// PORT: PS2-only VU0 inline asm (squared 3D distance).
static inline float vu0DistSq_25C0(const sVec4_25C0& a, const sVec4_25C0& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf4, %3\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf7, $vf5, $vf5\n"
        "vadday.x  ACC, $vf7, $vf7y\n"
        "vmaddz.x  $vf7, $vf6, $vf7z\n"
        "qmfc2.ni  %1, $vf7\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

static inline sVec4_25C0 rowPos_25C0(const sMtx_25C0* m)
{
    return m->r[3];
}

static inline sVec4_25C0 mulT_25C0(const sMtx_25C0* m, const sVec4_25C0& v)
{
    return sVec4_25C0(v.x * m->r[0].x + v.y * m->r[0].y + v.z * m->r[0].z + v.w * m->r[0].w,
                      v.x * m->r[1].x + v.y * m->r[1].y + v.z * m->r[1].z + v.w * m->r[1].w,
                      v.x * m->r[2].x + v.y * m->r[2].y + v.z * m->r[2].z + v.w * m->r[2].w,
                      v.x * m->r[3].x + v.y * m->r[3].y + v.z * m->r[3].z + v.w * m->r[3].w);
}

static inline sMtx_25C0* camMtx_25C0()
{
    sCam_25C0* c = D_004A289C;
    return ((tCamMtxP_25C0)c->vt[0x23].fn)((char*)c + c->vt[0x23].delta);
}

extern "C" void func_002425C0(sVisMgr_25C0* self, sBounds_25C0* bb)
{
    self->nvis = 0;
    self->mask = 0;
    if (self->enabled == 0)
        return;
    sCam_25C0* c = D_004A289C;
    sMtx_25C0 mtx = ((tCamMtx_25C0)c->vt[0x2B].fn)((char*)c + c->vt[0x2B].delta);
    sVec4_25C0 p = vu0Scale_25C0(rowPos_25C0(camMtx_25C0()), -1.0f);
    p = mulT_25C0(camMtx_25C0(), p);
    self->count = 0;
    p.w = 1.0f;
    sView_25C0* it = self->head;
    while (it != 0) {
        sView_25C0* v = it;
        it = it->next;
        sBox_25C0 box;
        box.min.x = v->minx;
        box.min.y = v->miny;
        box.min.z = v->minz;
        box.min.w = 1.0f;
        box.max.x = v->maxx;
        box.max.y = v->maxy;
        box.max.z = v->maxz;
        box.max.w = 1.0f;
        int ov = bb->minx <= box.max.x && box.min.x <= bb->maxx
              && bb->miny <= box.max.y && box.min.y <= bb->maxy
              && bb->minz <= box.max.z && box.min.z <= bb->maxz;
        if (ov) {
            sCam_25C0* c2 = D_004A289C;
            bool vis = !((tCamCull_25C0)c2->vt[0x5D].fn)((char*)c2 + c2->vt[0x5D].delta, &box.min, &box.max, &mtx);
            if (vis) {
                if (!(0.0f < vu0Dot_25C0(p, v->normal))) {
                    float d = vu0DistSq_25C0(p, v->pos);
                    self->ents[self->count].view = v;
                    self->ents[self->count].dist = d;
                    self->count++;
                }
            }
        }
    }
    if (self->count == 0)
        return;
    func_00418EF8(self->ents, self->count, 8, func_00242978);
    int n = self->count;
    if (n > 2)
        n = 2;
    self->nvis = n;
    for (int i = 0; i < self->nvis; i++) {
        self->mask |= 1 << i;
        func_002429B0(self, &p, self->ents[i].view);
        func_00229F88(i, &self->ents[i].view->normal, (char*)self->ents[i].view + 0x60);
    }
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_00242978);
#ifdef SKIP_ASM
// qsort-style comparator: orders by the float at +0x4, ascending.
extern "C" int func_00242978(const void* a, const void* b)
{
    float fa = *(float*)((char*)a + 0x4);
    float fb = *(float*)((char*)b + 0x4);
    if (fa < fb) {
        return -1;
    }
    if (fb < fa) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("movie/movieplayer", func_002429B0);
#ifdef SKIP_ASM
struct sVec4_29B0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sPlane_29B0 {
    float x, y, z, d;
};

struct sFrustum_29B0 {
    sVec4_29B0 pad0;
    sVec4_29B0 corner[4];   // 0x10
    sVec4_29B0 pad50;
    sPlane_29B0 plane[4];   // 0x60
};

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec4_29B0 vu0Sub_29B0(const sVec4_29B0& a, const sVec4_29B0& b)
{
    sVec4_29B0 r;
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

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sVec4_29B0 vu0Cross_29B0(const sVec4_29B0& a, const sVec4_29B0& b)
{
    sVec4_29B0 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4_29B0 vu0Normalize_29B0(const sVec4_29B0& v)
{
    sVec4_29B0 r;
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_29B0(const sVec4_29B0& a, const sVec4_29B0& b)
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

static inline void makePlane_29B0(sFrustum_29B0* f, int i, const sVec4_29B0& eye, const sVec4_29B0& c0, const sVec4_29B0& c1)
{
    sVec4_29B0 a;
    sVec4_29B0 b;
    sVec4_29B0 n;
    a = vu0Sub_29B0(c1, eye);
    b = vu0Sub_29B0(c0, eye);
    n = vu0Normalize_29B0(vu0Cross_29B0(a, b));
    n.w = -vu0Dot_29B0(eye, n);
    f->plane[i].x = n.x;
    f->plane[i].y = n.y;
    f->plane[i].z = n.z;
    f->plane[i].d = n.w;
}

extern "C" void func_002429B0(void* self, const void* eyep, void* fp)
{
    const sVec4_29B0& eye = *(const sVec4_29B0*)eyep;
    sFrustum_29B0* f = (sFrustum_29B0*)fp;
    makePlane_29B0(f, 0, eye, f->corner[0], f->corner[1]);
    makePlane_29B0(f, 1, eye, f->corner[1], f->corner[2]);
    makePlane_29B0(f, 2, eye, f->corner[2], f->corner[3]);
    makePlane_29B0(f, 3, eye, f->corner[3], f->corner[0]);
}
#endif

