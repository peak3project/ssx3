#include "common.h"

extern "C" {

int func_00414B98(int *a, int *b);

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414B68);
#ifdef SKIP_ASM
extern int D_00499A48[];
extern int operator_delete__FPi(int *);
int func_00414B68(int *p, int flag) {
    p[1] = (int)D_00499A48;
    if (flag & 1) return operator_delete__FPi(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414B98);
#ifdef SKIP_ASM
extern int func_004165A8(int, int);
int func_00414B98(int *a, int *b) {
    int r = 0;
    if (b == a || func_004165A8(*a, *b) == 0)
        r = 1;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414BD8);
#ifdef SKIP_ASM
extern int D_004999D0[];
void func_00414BD8(int *p, int a, int b, int c) {
    if (p != 0) {
        p[3] = c;
        p[0] = a;
        p[2] = b;
        p[1] = (int)D_004999D0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414C00);
#ifdef SKIP_ASM
extern int D_004999E8[];
void func_00414C00(int *p, int a, int b) {
    if (p != 0) {
        p[2] = b;
        p[0] = a;
        p[1] = (int)D_004999E8;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414C20);
#ifdef SKIP_ASM
extern int D_00499A00[];
void func_00414C20(int *p, int a) {
    if (p != 0) {
        p[0] = a;
        p[1] = (int)D_00499A00;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414C40);
#ifdef SKIP_ASM
int func_00414C40(int *a, int *b, int c, int d) {
    if (func_00414B98(a, b) == 0) d = 0;
    return d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414C70);
#ifdef SKIP_ASM
int func_00414C70(int *p, int a, int b, int c, int d, int e) {
    int *o;
    short *vt;
    if (func_00414B98(p, (int *)a) != 0)
        return c;
    o = (int *)p[2];
    vt = (short *)o[1];
    return ((int (*)(int *, int, int, int, int, int))((int *)vt)[5])((int *)((char *)o + vt[8]), a, b, c, d, e);
}
#endif

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414D08);

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414EE0);
#ifdef SKIP_ASM
extern int D_004999D0[];
int *func_00414EE0(int *p, int a, int b, int c) {
    p[0] = a;
    p[1] = (int)D_004999D0;
    p[2] = b;
    p[3] = c;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414F00);
#ifdef SKIP_ASM
extern int D_0053EA60[];
extern int D_00499A58[];
extern int D_0053EA40[];
extern int *func_00415018(void);
extern void func_00414C00(int *, int, int);
int *func_00414F00(void) {
    if (D_0053EA60[0] == 0) {
        func_00415018();
        func_00414C00(D_0053EA60, (int)D_00499A58, (int)D_0053EA40);
    }
    return D_0053EA60;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414F50);
#ifdef SKIP_ASM
void func_00414F50(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414F70);
#ifdef SKIP_ASM
extern int D_004999E8[];
int *func_00414F70(int *p, int a, int b) {
    p[0] = a;
    p[1] = (int)D_004999E8;
    p[2] = b;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414F90);
#ifdef SKIP_ASM
extern int D_0053EA50[];
extern int D_00499A70[];
extern int D_0053EA40[];
extern int *func_00415018(void);
extern void func_00414C00(int *, int, int);
int *func_00414F90(void) {
    if (D_0053EA50[0] == 0) {
        func_00415018();
        func_00414C00(D_0053EA50, (int)D_00499A70, (int)D_0053EA40);
    }
    return D_0053EA50;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00414FE0);
#ifdef SKIP_ASM
void func_00414FE0(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415000);
#ifdef SKIP_ASM
extern int D_00499A00[];
int *func_00415000(int *p, int a) {
    p[0] = a;
    p[1] = (int)D_00499A00;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415018);
#ifdef SKIP_ASM
extern int D_0053EA40[];
extern int D_00499A88[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415018(void) {
    if (D_0053EA40[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EA40, (int)D_00499A88, (int)D_004A5BB0);
    }
    return D_0053EA40;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415068);
#ifdef SKIP_ASM
void func_00415068(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415088);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern int operator_delete__FPi(int *);
int func_00415088(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) return operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004150B8);
#ifdef SKIP_ASM
extern int D_00499A18[];
int *func_004150B8(int **p) {
    *p = D_00499A18;
    return (int*)p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004150D0);
#ifdef SKIP_ASM
extern int D_0053EA20[];
extern int D_00499AA0[];
extern int D_004A5BA8[];
extern int *func_00412F18(void);
extern void func_00414C00(int *, int, int);
int *func_004150D0(void) {
    if (D_0053EA20[0] == 0) {
        func_00412F18();
        func_00414C00(D_0053EA20, (int)D_00499AA0, (int)D_004A5BA8);
    }
    return D_0053EA20;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415120);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern int operator_delete__FPi(int *);
int func_00415120(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) return operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415150);
#ifdef SKIP_ASM
extern int D_00499A30[];
int *func_00415150(int **p) {
    *p = D_00499A30;
    return (int*)p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415168);
#ifdef SKIP_ASM
extern int D_0053EA30[];
extern int D_00499AB0[];
extern int D_004A5BA8[];
extern int *func_00412F18(void);
extern void func_00414C00(int *, int, int);
int *func_00415168(void) {
    if (D_0053EA30[0] == 0) {
        func_00412F18();
        func_00414C00(D_0053EA30, (int)D_00499AB0, (int)D_004A5BA8);
    }
    return D_0053EA30;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004151B8);
#ifdef SKIP_ASM
int func_004151B8(int *a, int *b) {
    return func_00414B98(a, b) ^ 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004151D8);
#ifdef SKIP_ASM
int func_004151D8(int *p) {
    return *p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004151E0);
#ifdef SKIP_ASM
extern int D_00499A48[];
int *func_004151E0(int *p, int a) {
    p[0] = a;
    p[1] = (int)D_00499A48;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004151F8);
#ifdef SKIP_ASM
extern int D_00499AC0[];
extern int D_004A5BB0[];
extern void func_00414C20(int *, int);
int *func_004151F8(void) {
    if (D_004A5BB0[0] == 0)
        func_00414C20(D_004A5BB0, (int)D_00499AC0);
    return D_004A5BB0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415238);
#ifdef SKIP_ASM
extern int func_004165A8(int, int);
int func_00415238(int *a, int *b) {
    return (unsigned)func_004165A8(*a, *b) >> 31;
}
#endif

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415260);

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415728);
#ifdef SKIP_ASM
extern int *func_004151F8(void);
extern int *func_00415F48(void);
extern int func_00415840(int, char *, int, char *, char *, void *);
int func_00415728(int *p) {
    int r = 0;
    if (p) {
        short *vt = (short *)p[1];
        r = func_00415840(((int *)vt)[1], (char *)func_00415F48, 1, (char *)p + vt[0], (char *)func_004151F8, p);
    }
    return r != 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415778);
#ifdef SKIP_ASM
extern int D_00499BC8[];
void func_00415778(int *p, int a, int b) {
    if (p != 0) {
        p[2] = b;
        p[0] = a;
        p[1] = (int)D_00499BC8;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415798);
#ifdef SKIP_ASM
extern int D_00499BB8[];
void func_00415798(int *p, int a, int b, int c) {
    if (p != 0) {
        p[3] = b;
        p[0] = a;
        p[2] = c;
        p[1] = (int)D_00499BB8;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004157C0);
#ifdef SKIP_ASM
extern int D_00499B98[];
void func_004157C0(int *p, int a) {
    if (p != 0) {
        p[0] = a;
        p[1] = (int)D_00499B98;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_004157E0);
#ifdef SKIP_ASM
extern int D_00499B88[];
void func_004157E0(int *p, int a) {
    if (p != 0) {
        p[0] = a;
        p[1] = (int)D_00499B88;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415800);
#ifdef SKIP_ASM
extern int D_00499B78[];
void func_00415800(int *p, int a) {
    if (p != 0) {
        p[0] = a;
        p[1] = (int)D_00499B78;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415820);
#ifdef SKIP_ASM
extern int D_00499B68[];
void func_00415820(int *p, int a) {
    if (p != 0) {
        p[0] = a;
        p[1] = (int)D_00499B68;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415840);
#ifdef SKIP_ASM
int func_00415840(int f0, char *f1, int a, char *b, char *f4, void *c) {
    char *o = ((char *(*)(void))f0)();
    int *vt = *(int **)(o + 4);
    char *th = o + *(short *)((char *)vt + 0x10);
    int r1;
    int r4;
    vt = (int *)((char *)vt + 0x10);
    r1 = ((int (*)(void))f1)();
    r4 = ((int (*)(void))f4)();
    return ((int (*)(char *, int, int, char *, int, void *))vt[1])(th, r1, a, b, r4, c);
}
#endif

}  // extern "C"

// libstdc++-v2 tinfo2.cc, BUILTIN(m): __tf<m>() lazily placement-constructs the builtin type_info __ti<m> (its name
// is the mangled type letter, its vtable is __builtin_type_info's) and returns it. The objects, name strings and
// the vtable are retail data (D_*): only their addresses are referenced here.
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) throw() { return p; }

extern "C" {
extern const int D_00499BA8[];
extern unsigned char D_00454158[8];
extern unsigned char D_00454160[8];
extern unsigned char D_00454168[8];
extern unsigned char D_00454170[8];
extern unsigned char D_00454178[8];
extern unsigned char D_00454180[8];
extern unsigned char D_00454188[8];
extern unsigned char D_00454190[8];
extern unsigned char D_00454198[8];
extern unsigned char D_004541A0[8];
extern unsigned char D_004541A8[8];
extern unsigned char D_004541B0[8];
extern unsigned char D_004541B8[8];
extern unsigned char D_004541C0[8];
extern unsigned char D_004541C8[8];
extern unsigned char D_004541D0[8];
extern unsigned char D_004541D8[8];
extern const char D_00499AE0[];
extern const char D_00499AE8[];
extern const char D_00499AF0[];
extern const char D_00499AF8[];
extern const char D_00499B00[];
extern const char D_00499B08[];
extern const char D_00499B10[];
extern const char D_00499B18[];
extern const char D_00499B20[];
extern const char D_00499B28[];
extern const char D_00499B30[];
extern const char D_00499B38[];
extern const char D_00499B40[];
extern const char D_00499B48[];
extern const char D_00499B50[];
extern const char D_00499B58[];
extern const char D_00499B60[];
}

class __builtin_ti {
    const char* _name;
    const void* vtbl_;
public:
    __builtin_ti(const char* n) : _name(n), vtbl_(D_00499BA8) {}
};

// (a non-polymorphic stand-in class that stores the retail vtable's address: a real polymorphic class would emit its
// own vtable, and the retail one is data we reference rather than regenerate)
#define BUILTIN(fn, ti, name)                  \
    extern "C" const __builtin_ti& fn(void) {  \
        if (*(void**)ti == 0)                  \
            new (ti) __builtin_ti(name);       \
        return *(const __builtin_ti*)ti;       \
    }

INCLUDE_ASM("seg/seg_315B68_tinfo", func_004158F0);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415928);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415960);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415998);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_004159D0);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415A08);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415A40);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415A78);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415AB0);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415AE8);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415B20);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415B58);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415B90);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415BC8);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415C00);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415C38);

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415C70);

extern "C" {

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415CA8);
#ifdef SKIP_ASM
extern int D_0053EAA0[];
extern int D_00499BD8[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415CA8(void) {
    if (D_0053EAA0[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EAA0, (int)D_00499BD8, (int)D_004A5BB0);
    }
    return D_0053EAA0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415CF8);
#ifdef SKIP_ASM
void func_00415CF8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415D18);
#ifdef SKIP_ASM
extern int D_0053EAC0[];
extern int D_00499BF0[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415D18(void) {
    if (D_0053EAC0[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EAC0, (int)D_00499BF0, (int)D_004A5BB0);
    }
    return D_0053EAC0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415D68);
#ifdef SKIP_ASM
void func_00415D68(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415D88);
#ifdef SKIP_ASM
extern int D_0053EA90[];
extern int D_00499C08[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415D88(void) {
    if (D_0053EA90[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EA90, (int)D_00499C08, (int)D_004A5BB0);
    }
    return D_0053EA90;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415DD8);
#ifdef SKIP_ASM
void func_00415DD8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415DF8);
#ifdef SKIP_ASM
extern int D_0053EA70[];
extern int D_00499C20[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415DF8(void) {
    if (D_0053EA70[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EA70, (int)D_00499C20, (int)D_004A5BB0);
    }
    return D_0053EA70;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415E48);
#ifdef SKIP_ASM
void func_00415E48(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415E68);
#ifdef SKIP_ASM
extern int D_0053EAD0[];
extern int D_00499C38[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415E68(void) {
    if (D_0053EAD0[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EAD0, (int)D_00499C38, (int)D_004A5BB0);
    }
    return D_0053EAD0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415EB8);
#ifdef SKIP_ASM
void func_00415EB8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415ED8);
#ifdef SKIP_ASM
extern int D_0053EA80[];
extern int D_00499C50[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415ED8(void) {
    if (D_0053EA80[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EA80, (int)D_00499C50, (int)D_004A5BB0);
    }
    return D_0053EA80;
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415F28);
#ifdef SKIP_ASM
void func_00415F28(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415F48);
#ifdef SKIP_ASM
extern int D_0053EAB0[];
extern int D_00499C68[];
extern int D_004A5BB0[];
extern int *func_004151F8(void);
extern void func_00414C00(int *, int, int);
int *func_00415F48(void) {
    if (D_0053EAB0[0] == 0) {
        func_004151F8();
        func_00414C00(D_0053EAB0, (int)D_00499C68, (int)D_004A5BB0);
    }
    return D_0053EAB0;
}
#endif

INCLUDE_ASM("seg/seg_315B68_tinfo", func_00415F98);

}  // extern "C"
