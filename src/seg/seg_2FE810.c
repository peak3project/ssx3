#include "common.h"

INCLUDE_ASM("seg/seg_2FE810", func_003FD810);

void func_003FD908(void) {
}

INCLUDE_ASM("seg/seg_2FE810", func_003FD910);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDAA0);
#ifdef SKIP_ASM
extern char D_00451550[];
void *func_003FDAA0(void) {
    return D_00451550;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FDAB0);

INCLUDE_ASM("seg/seg_2FE810", sceGsSyncPath);

INCLUDE_ASM("seg/seg_2FE810", func_003FDE30);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDEA0);
#ifdef SKIP_ASM
extern char D_004977D8[];
extern void func_003FDEA0_log(char *) __asm__("func_00425C60");
extern void func_003FE5C8();
void func_003FDEA0(int *p, unsigned lim, int tmo) {
    int t = 0x1000000;
    if (tmo)
        t = tmo;
    while (*(volatile int *)(p + 4) < lim) {
        if (--t < 0) {
            func_003FDEA0_log(D_004977D8);
            func_003FE5C8(p);
        }
        }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDF28);
#ifdef SKIP_ASM
unsigned func_003FDF28(unsigned a) {
    if ((a >> 28) == 7) {
        a &= 0xFFFFFFF;
        a |= 0x80000000;
    }
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDF50);
#ifdef SKIP_ASM
void func_003FDF50(char *p, int n) {
    while (n--)
        *p++ = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDF88);
#ifdef SKIP_ASM
extern int D_00451590[];
int func_003FDF88(unsigned n) {
    return n < 10 ? D_00451590[n] : 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FDFB0);

INCLUDE_ASM("seg/seg_2FE810", func_003FE090);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE268);
#ifdef SKIP_ASM
struct S003FE268 { int c[5]; };
extern struct S003FE268 D_005261D0[];
struct S003FE268 *func_003FE268(struct S003FE268 *d) {
    *d = D_005261D0[0];
    return d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE2A0);
#ifdef SKIP_ASM
int func_003FE2A0(int v) {
    int *r = (int *)0x1000E060;
    int o = *r;
    *r = v;
    return o;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE2B8);
#ifdef SKIP_ASM
extern unsigned func_003FDF28(unsigned);
extern void func_003FDE30();
void func_003FE2B8(int *p, unsigned a) {
    unsigned v = func_003FDF28(a);
    func_003FDE30(p);
    if (p[12] != 0xFFFFFFFF)
        p[12] = v;
    p[8] = 0;
    p[0] = (p[0] & ~0xC) | 0x105;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE320);
#ifdef SKIP_ASM
void func_003FE320(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    p[0] = (p[0] & ~0xC) | 0x101;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE398);
#ifdef SKIP_ASM
void func_003FE398(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    p[0] = (p[0] & ~0xC) | 0x109;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE410);
#ifdef SKIP_ASM
extern void func_003FDE30();
void func_003FE410(int *p) {
    func_003FDE30(p);
    p[8] = 0;
    p[0] = ((p[0] & ~0xC | 0x4) & ~1) | 0x100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE458);
#ifdef SKIP_ASM
void func_003FE458(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    int t;
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    t = p[0] & ~0xC;
    p[0] = (t & ~1) | 0x100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE4D8);
#ifdef SKIP_ASM
void func_003FE4D8(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    int t;
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    t = (p[0] & ~0xC) | 8;
    p[0] = (t & ~1) | 0x100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE558);
#ifdef SKIP_ASM
extern void func_003FDE30(int *, int);
int func_003FE558(unsigned *p, int m) {
    if (m == 1)
        return (*p >> 8) & 1;
    func_003FDE30((int *)p, m);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE590);
#ifdef SKIP_ASM
extern void func_003FDEA0(int *, unsigned, int);
int func_003FE590(int *p, unsigned n, int m, int x) {
    if (m == 1)
        return (unsigned)p[4] < n;
    func_003FDEA0(p, n, x);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FE5C8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE660);
#ifdef SKIP_ASM
unsigned func_003FE660(unsigned *p, unsigned v) {
    unsigned o = *p;
    *p = v;
    return (o >> 8) & 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FE678);

INCLUDE_ASM("seg/seg_2FE810", func_003FE690);

INCLUDE_ASM("seg/seg_2FE810", func_003FE6A8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE708);
#ifdef SKIP_ASM
extern int func_003FE7D8(void);
extern int func_003FE828(void);
extern void func_003FE818(int);
int func_003FE708(void) {
    int r = 0;
    int n = func_003FE7D8();
    if (n < 4) {
        if (n > 0) {
            func_003FE818(func_003FE828());
            r = 1;
        }
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FE758);

INCLUDE_ASM("seg/seg_2FE810", func_003FE788);

INCLUDE_ASM("seg/seg_2FE810", func_003FE7B8);

INCLUDE_ASM("seg/seg_2FE810", func_003FE7C8);

INCLUDE_ASM("seg/seg_2FE810", func_003FE7D8);

INCLUDE_ASM("seg/seg_2FE810", func_003FE818);

INCLUDE_ASM("seg/seg_2FE810", func_003FE828);

INCLUDE_ASM("seg/seg_2FE810", func_003FE838);

INCLUDE_ASM("seg/seg_2FE810", func_003FE998);

INCLUDE_ASM("seg/seg_2FE810", func_003FEB08);

INCLUDE_ASM("seg/seg_2FE810", func_003FEB38);

INCLUDE_ASM("seg/seg_2FE810", func_003FEB78);

INCLUDE_ASM("seg/seg_2FE810", func_003FEBC0);

INCLUDE_ASM("seg/seg_2FE810", func_003FEBD8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FEC38);
#ifdef SKIP_ASM
extern int func_003FED08(void);
extern unsigned short func_003FED60(void);
extern void func_003FED50(int);
int func_003FEC38(void) {
    int r = 0;
    int n = func_003FED08();
    if (n < 4) {
        if (n > 0) {
            func_003FED50(func_003FED60());
            r = 1;
        }
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FEC88);

INCLUDE_ASM("seg/seg_2FE810", func_003FECB8);

INCLUDE_ASM("seg/seg_2FE810", func_003FECE8);

INCLUDE_ASM("seg/seg_2FE810", func_003FECF8);

INCLUDE_ASM("seg/seg_2FE810", func_003FED08);

INCLUDE_ASM("seg/seg_2FE810", func_003FED50);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FED60);
#ifdef SKIP_ASM
extern void func_003FEB78(void *, int);
unsigned short func_003FED60(void) {
    unsigned short v;
    func_003FEB78(&v, 0x43A);
    return v;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FED88);

INCLUDE_ASM("seg/seg_2FE810", func_003FEF18);

INCLUDE_ASM("seg/seg_2FE810", func_003FF060);

INCLUDE_ASM("seg/seg_2FE810", func_003FF088);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF0F0);
#ifdef SKIP_ASM
extern int func_003FF160(void);
int func_003FF0F0(void) {
    if (func_003FF160() != 1)
        return 0;
    *(volatile int *)0x10003810 = 8;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF130);
#ifdef SKIP_ASM
void func_003FF130(unsigned a, unsigned b, unsigned c) {
    *(unsigned *)0x10003820 = a | (b << 1) | (c << 2);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF150);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF160);
#ifdef SKIP_ASM
int func_003FF160(void) {
    int v = *(volatile int *)0x10003800;
    if (!(v & 3)) {
        return 0;
    }
    if (v & 0x700) {
        return 1;
    }
    if (v & 0xC) {
        return 2;
    }
    return (v & 0x3000) ? 3 : 4;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF1B0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF330);
#ifdef SKIP_ASM
typedef int i128 __attribute__((mode(TI)));
int func_003FF330(i128 *src, int n) {
    int c = 0;
    while (n--) {
        if (*(volatile unsigned *)0x10003800 & 0x10000000)
            return c;
        *(i128 *)0x10004000 = *src++;
        c++;
    }
    return c;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF390);

INCLUDE_ASM("seg/seg_2FE810", func_003FF4A8);

INCLUDE_ASM("seg/seg_2FE810", func_003FF5E8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF688);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int D_004515C8[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_003FF688(void) {
    int v;
    D_00526440[0] = 15;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    v = D_00526440[3];
    if (v == 1)
        D_004515C8[0] = 0;
    return v;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF708);

INCLUDE_ASM("seg/seg_2FE810", func_003FF8F0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF9A8);
#ifdef SKIP_ASM
struct E_526250 { int pad[4]; int f10; int pad2[2]; };
struct R_526250 { struct E_526250 e[4]; };
extern struct R_526250 D_00526250[];
extern void func_00424698(int *, int *);
int *func_003FF9A8(int a, int b) {
    int *p, c;
    p = (int *)D_00526250[a].e[b].pad[0];
    func_00424698(p, (int *)((char *)p + 0xFF));
    c = (p[22] < p[54]) << 7;
    return (int *)((char *)p + c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFA08);
#ifdef SKIP_ASM
extern int * func_003FF9A8(int, int);
int func_003FFA08(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_003FF9A8(a, b)[22];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FFA58);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFBC0);
#ifdef SKIP_ASM
int func_003FFBC0(int a, int b) {
    unsigned char *p;
    if (!D_00526250[a].e[b].f10)
        return 99;
    p = (unsigned char *)func_003FF9A8(a, b);
    if (p[0x70] == 6 && p[0x71] == 2)
        return 5;
    return p[0x70];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFC38);
#ifdef SKIP_ASM
extern char *D_004515D0[];
extern char D_004979A8[];
extern char *strcpy(char *, const char *);
void func_003FFC38(unsigned i, char *dst) {
    if (i < 8) {
        strcpy(dst, D_004515D0[i]);
        return;
    }
    *dst = D_004979A8[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFC70);
#ifdef SKIP_ASM
int func_003FFC70(int a, int b, int c) {
    if (!D_00526250[a].e[b].f10)
        return 0;
    ((char *)func_003FF9A8(a, b))[0x71] = c;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFCD8);
#ifdef SKIP_ASM
int func_003FFCD8(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return ((unsigned char *)func_003FF9A8(a, b))[0x71];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFD28);
#ifdef SKIP_ASM
extern char *D_004515F0[];
extern char D_004979A8[];
extern char *strcpy(char *, const char *);
void func_003FFD28(unsigned i, char *dst) {
    if (i < 4) {
        strcpy(dst, D_004515F0[i]);
        return;
    }
    *dst = D_004979A8[0];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FFD60);

INCLUDE_ASM("seg/seg_2FE810", func_003FFE80);

INCLUDE_ASM("seg/seg_2FE810", func_003FFFA0);

INCLUDE_ASM("seg/seg_2FE810", func_004000D8);

INCLUDE_ASM("seg/seg_2FE810", func_00400190);

INCLUDE_ASM("seg/seg_2FE810", func_00400250);

INCLUDE_ASM("seg/seg_2FE810", func_00400328);

INCLUDE_ASM("seg/seg_2FE810", func_004003E0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400490);
#ifdef SKIP_ASM
extern int func_00400328(int, int);
int func_00400490(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_00400328(a, b) == 0x3FFFF;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004004F0);
#ifdef SKIP_ASM
extern int func_004003E0(int, int, int);
int func_004004F0(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_004003E0(a, b, 0xFFF);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400548);
#ifdef SKIP_ASM
extern int func_004003E0(int, int, int);
int func_00400548(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_004003E0(a, b, 0);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004005A0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400670);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_00400670(void) {
    D_00526440[0] = 12;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004006D8);
#ifdef SKIP_ASM
int func_004006D8(int a) {
    D_00526440[1] = a;
    D_00526440[0] = 13;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400740);
#ifdef SKIP_ASM
int func_00400740(void) {
    D_00526440[0] = 18;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004007A8);
#ifdef SKIP_ASM
int func_004007A8(int a) {
    D_00526440[1] = a;
    D_00526440[0] = 20;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[2];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00400810);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400838);
#ifdef SKIP_ASM
extern int func_00423DA0(int *);
extern void func_00400810(int, int, int);
void func_00400838(unsigned short a) {
    int s[6];
    int h;
    s[1] = 1;
    s[2] = 0;
    s[5] = 0;
    h = func_00423DA0(s);
    func_00423B20(a, func_00400810, h);
    func_00423DE0(h);
    func_00423DB0(h);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004008A0);

INCLUDE_ASM("seg/seg_2FE810", func_00400908);

INCLUDE_ASM("seg/seg_2FE810", func_004009A8);

INCLUDE_ASM("seg/seg_2FE810", func_00400A78);

INCLUDE_ASM("seg/seg_2FE810", func_00400B48);

INCLUDE_ASM("seg/seg_2FE810", func_00400C00);

INCLUDE_ASM("seg/seg_2FE810", func_00400CB8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400D58);
#ifdef SKIP_ASM
extern int D_00451640[];
extern int func_0042C078();
extern void func_0042C0C0(void);
extern int func_00400E30(void);
extern void (*D_005264C8[])(int);
extern int D_005264CC[];
extern int D_005264D0[];
void (*func_00400D58(void (*a)(int), int b))(int) {
    int s;
    void (*old)(int);
    if (D_00451640[0] < 0)
        func_00400E30();
    s = func_0042C078();
    old = D_005264C8[0];
    D_005264D0[0] = b;
    D_005264C8[0] = a;
    __asm__ volatile("sw $28,%0" : "=m"(D_005264CC[0]));
    if (s)
        func_0042C0C0();
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400DD8);
#ifdef SKIP_ASM
extern void (*D_005264C8[])(int);
extern int D_005264CC[];
extern int D_005264D0[];
extern int D_00451624[];
void func_00400DD8(void) {
    void (*fn)(int) = D_005264C8[0];
    if (fn) {
        if (D_00451624[0] == 0) {
            int saved;
            __asm__ volatile("move %0,$28\n\tlw $28,%1" : "=r"(saved) : "m"(D_005264CC[0]));
            fn(D_005264D0[0]);
            __asm__ volatile("move $28,%0" : : "r"(saved));
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400E30);
#ifdef SKIP_ASM
extern int D_00451640[];
extern int func_0042C078();
extern void func_0042C0C0(void);
extern void func_00400DD8(void);
extern void func_00426020(int, void (*)(void), int);
int func_00400E30(void) {
    int s;
    D_00451624[0] = 1;
    s = func_0042C078();
    func_00426020(0x80000012, func_00400DD8, 0);
    if (s)
        func_0042C0C0();
    D_00451624[0] = 0;
    D_00451640[0] = 1;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00400EA8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004011C0);
#ifdef SKIP_ASM
extern int func_00400EA8(int, int, int);
int func_004011C0(int a, int b) {
    return func_00400EA8(a, b, 0);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004011E0);

INCLUDE_ASM("seg/seg_2FE810", func_00401350);

INCLUDE_ASM("seg/seg_2FE810", func_004013E8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00401488);
#ifdef SKIP_ASM
extern int D_00451610[];
extern char D_00453180[];
extern char D_00497AC8[];
extern void func_00425C60();
extern int func_00426F08(char *);
int func_00401488(int a) {
    if (a == 0) {
        if (D_00451610[0] > 0)
            func_00425C60(D_00497AC8);
        while (func_00426F08(D_00453180))
            func_00400838(60);
        return 0;
    }
    return func_00426F08(D_00453180);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004014F8);

INCLUDE_ASM("seg/seg_2FE810", func_00401668);

INCLUDE_ASM("seg/seg_2FE810", func_00401718);

INCLUDE_ASM("seg/seg_2FE810", func_004019F8);

INCLUDE_ASM("seg/seg_2FE810", func_00401BF0);

INCLUDE_ASM("seg/seg_2FE810", func_00401DF8);

INCLUDE_ASM("seg/seg_2FE810", func_00401FD8);

INCLUDE_ASM("seg/seg_2FE810", func_00402268);

INCLUDE_ASM("seg/seg_2FE810", func_00402300);

INCLUDE_ASM("seg/seg_2FE810", func_00402398);

INCLUDE_ASM("seg/seg_2FE810", func_00402450);

INCLUDE_ASM("seg/seg_2FE810", func_00402520);

INCLUDE_ASM("seg/seg_2FE810", func_00402618);

INCLUDE_ASM("seg/seg_2FE810", func_00402708);

INCLUDE_ASM("seg/seg_2FE810", func_004027B8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004029C8);
#ifdef SKIP_ASM
int func_004029C8(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004029D0);
#ifdef SKIP_ASM
extern int func_00403500(int, int, int);
int func_004029D0(int *p, int b, int n) {
    func_00403500(p[16], b, (n + 19) / 16 * 16);
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00402A10);

INCLUDE_ASM("seg/seg_2FE810", func_00402A58);

INCLUDE_ASM("seg/seg_2FE810", func_00402AA0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402AF0);
#ifdef SKIP_ASM
void func_00402AF0(int *p) {
    int *q = (int *)p[16];
    q[0x428] = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B00);
#ifdef SKIP_ASM
void func_00402B00(int *p, int a, int b, int c) {
    int *q = (int *)p[16];
    q[37] = a;
    q[38] = b;
    q[39] = c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B18);
#ifdef SKIP_ASM
void func_00402B18(int *p, int *a, int *b, int *c) {
    int *q = (int *)p[16];
    *a = q[37];
    *b = q[38];
    *c = q[39];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B38);
#ifdef SKIP_ASM
int func_00402B38(int *p) {
    int *q = (int *)p[16];
    return q[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B48);
#ifdef SKIP_ASM
int func_00402B48(int *p) {
    int *q = (int *)p[16];
    return q[1] == 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B58);
#ifdef SKIP_ASM
extern void func_00403398(int *);
int func_00402B58(int *a) {
    int *p = (int *)a[16];
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    a[2] = 0;
    p[43] = 0;
    p[32] = -1;
    func_00403398(p);
    p[70] = 0;
    func_004032A8(p);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402BB0);
#ifdef SKIP_ASM
int func_00402BB0(int *p) {
    char *q = (char *)p[16];
    int *t;
    if ((t = *(int **)(q + 0x1B8))) t[10] = 0;
    if ((t = *(int **)(q + 0x1C8))) t[10] = 0;
    if ((t = *(int **)(q + 0x1D8))) t[10] = 0;
    if ((t = *(int **)(q + 0x1BC))) t[10] = 0;
    if ((t = *(int **)(q + 0x1CC))) t[10] = 0;
    if ((t = *(int **)(q + 0x1DC))) t[10] = 0;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00402C08);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402C30);
#ifdef SKIP_ASM
struct FA_402C30 { int (*fn)(int *, int *, int); int arg; };
struct T_402C30 { char pad[12]; struct FA_402C30 e[1]; };
int func_00402C30(int *p, int *v) {
    int r = 0;
    if (p) {
        struct T_402C30 *q = (struct T_402C30 *)p[16];
        if (q) {
            if (q->e[*v].fn) {
                r = q->e[*v].fn(p, v, q->e[*v].arg);
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402C80);
#ifdef SKIP_ASM
extern int func_00402C30(int *, int *);
int func_00402C80(int *p) {
    int v[8];
    v[0] = 1;
    func_00402C30(p, v);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CA8);
#ifdef SKIP_ASM
int func_00402CA8(int *p, long v) {
    int *q = (int *)p[16];
    q[28] = 1;
    *(long *)&q[30] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CC0);
#ifdef SKIP_ASM
int func_00402CC0(int *p) {
    int *q = (int *)p[16];
    q[28] = 0;
    *(long *)&q[30] = 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CD8);
#ifdef SKIP_ASM
int func_00402CD8(int *p, int v) {
    int *q = (int *)p[16];
    q[54] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CE8);
#ifdef SKIP_ASM
int func_00402CE8(int *p) {
    int *q = (int *)p[16];
    return q[51];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CF8);
#ifdef SKIP_ASM
int func_00402CF8(int *p) {
    int *q = (int *)p[16];
    return q[52];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D08);
#ifdef SKIP_ASM
char *func_00402D08(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D18);
#ifdef SKIP_ASM
char *func_00402D18(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D28);
#ifdef SKIP_ASM
int func_00402D28(int *p, int v) {
    int *q = (int *)p[16];
    int old = q[58];
    q[58] = v;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D38);
#ifdef SKIP_ASM
int func_00402D38(int *p, long v) {
    int *q = (int *)p[16];
    *(long *)&q[60] = v;
    q[62] = 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D50);
#ifdef SKIP_ASM
void func_00402D50(int *p, int a, int b) {
    p[0] = a;
    p[1] = b;
    p[2] = a;
    p[3] = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D68);
#ifdef SKIP_ASM
int func_00402D68(int *p) {
    return p[3] = p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D78);
#ifdef SKIP_ASM
int func_00402D78(int *p) {
    return p[2] = p[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D88);
#ifdef SKIP_ASM
extern char D_00497C48[];
extern void func_004034A8(int *, int);
unsigned func_00402D88(int *a, unsigned *p, unsigned size, unsigned align) {
    unsigned s = (p[2] + align - 1) / align * align;
    unsigned e = s + size;
    if (p[0] + p[1] >= e) {
        p[2] = e;
        return s;
    }
    func_004034A8(a, (int)D_00497C48);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402DF8);
#ifdef SKIP_ASM
int func_00402DF8(int *p) {
    return p[0] + p[1] - p[2];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00402E10);

INCLUDE_ASM("seg/seg_2FE810", func_00402F80);

INCLUDE_ASM("seg/seg_2FE810", func_00403098);

INCLUDE_ASM("seg/seg_2FE810", func_004030E0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403240);
#ifdef SKIP_ASM
extern void func_004032B8(int *);
int func_00403240(int *a) {
    int *s = (int *)a[16];
    int r = 0;
    if (s[1] != 0 && s[2] != 0) {
        func_004032B8(s);
        a[2] = s[70] - s[43];
        s[1] = 0;
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004032A8);
#ifdef SKIP_ASM
extern void func_00405B48(unsigned);
void func_004032A8(int *p) {
    p[530] = 0;
    func_00405B48(1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004032B8);
#ifdef SKIP_ASM
extern void func_004034A8(int *, int);
extern char D_00497CC8[];
extern void func_004086C0(int *, int, int);
extern void func_004087D0(int *, int, int, int);
void func_004032B8(int *p) {
    int n = p[0x118 / 4];
    if (p[0x120 / 4] != 0) {
        func_004034A8(p, (int)D_00497CC8);
    } else if (p[0x174 / 4] == 3) {
        func_004086C0(p, p[0x1BC / 4], n - 1);
    } else {
        func_004087D0(p, p[0x1CC / 4], p[0x1DC / 4], n - 1);
    }
    p[0x120 / 4] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403338);
#ifdef SKIP_ASM
extern void func_00405B48(unsigned);
void func_00403338(int *p) {
    int v = 0x70000000;
    func_00405B48(1);
    p[356] = v;
    p[357] = 0x70001800;
    p[436] = 0x70001B00;
    p[437] = 0x70003300;
    p[516] = 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00403398);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403460);
#ifdef SKIP_ASM
extern char D_00497CE8[];
extern void func_00425C60(char *, int);
void func_00403460(int a) {
    func_00425C60(D_00497CE8, a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403470);
#ifdef SKIP_ASM
extern int sprintf(char *, const char *, ...);
extern void func_004034A8(int *, int);
void func_00403470(int *a, char *fmt) {
    char buf[256];
    sprintf(buf, fmt);
    func_004034A8(a, (int)buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004034A8);
#ifdef SKIP_ASM
extern int func_00402C30(int *, int *);
extern void func_00403460(int);
void func_004034A8(int *p, int b) {
    int v[2];
    int *q = (int *)p[534];
    if (q && p && p[3]) {
        v[0] = 0;
        v[1] = b;
        func_00402C30(q, v);
        return;
    }
    func_00403460(b);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00403500);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403600);
#ifdef SKIP_ASM
int func_00403600(int *p, int a, int b) {
    p[1] = a;
    p[2] = b;
    p[3] = a >> 4;
    p[4] = b >> 4;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00403620);

INCLUDE_ASM("seg/seg_2FE810", func_00403748);

INCLUDE_ASM("seg/seg_2FE810", func_004039F0);

INCLUDE_ASM("seg/seg_2FE810", func_00403AD0);

INCLUDE_ASM("seg/seg_2FE810", func_00403BB0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403CE0);
#ifdef SKIP_ASM
extern int func_004072E8(int, int);
void func_00403CE0(int *p) {
    func_004072E8((int)p, 3);
    if (func_004072E8((int)p, 1)) {
        func_004072E8((int)p, 8);
        func_004072E8((int)p, 8);
        p[0x144 / 4] = func_004072E8((int)p, 8);
    }
    p[0x148 / 4] = func_004072E8((int)p, 0xE);
    func_004072E8((int)p, 1);
    p[0x14C / 4] = func_004072E8((int)p, 0xE);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", _sequenceScalableExtension);
#ifdef SKIP_ASM
extern char D_00497D58[];
extern void func_004034A8(int *, int);
void _sequenceScalableExtension(int *p) {
    func_004034A8(p, (int)D_00497D58);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403D80);
#ifdef SKIP_ASM
extern char D_00497D88[];
extern void func_004034A8(int *, int);
void func_00403D80(int *p) {
    func_004034A8(p, (int)D_00497D88);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403D90);
#ifdef SKIP_ASM
extern char D_00497DA0[];
extern void func_004034A8(int *, int);
void func_00403D90(int *p) {
    func_004034A8(p, (int)D_00497DA0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403DA0);
#ifdef SKIP_ASM
extern char D_00497DD8[];
extern void func_004034A8(int *, int);
void func_00403DA0(int *p) {
    func_004034A8(p, (int)D_00497DD8);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403DB0);
#ifdef SKIP_ASM
extern void func_00409400(void *);
int func_00403DB0(int *p) {
    func_00409400((char *)p[16] + 0x4C);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403DD8);
#ifdef SKIP_ASM
extern void func_004094E8(void *);
int func_00403DD8(int *p) {
    func_004094E8((char *)p[16] + 0x4C);
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00403E00);

INCLUDE_ASM("seg/seg_2FE810", func_00404050);

INCLUDE_ASM("seg/seg_2FE810", func_00404758);

INCLUDE_ASM("seg/seg_2FE810", func_00404B78);

INCLUDE_ASM("seg/seg_2FE810", func_00404D98);

INCLUDE_ASM("seg/seg_2FE810", func_00404E10);

INCLUDE_ASM("seg/seg_2FE810", func_00404EA8);

INCLUDE_ASM("seg/seg_2FE810", func_00404F60);

INCLUDE_ASM("seg/seg_2FE810", func_00405030);

INCLUDE_ASM("seg/seg_2FE810", func_004050E0);

INCLUDE_ASM("seg/seg_2FE810", func_00405198);

INCLUDE_ASM("seg/seg_2FE810", func_00405290);

INCLUDE_ASM("seg/seg_2FE810", func_00405390);

INCLUDE_ASM("seg/seg_2FE810", func_00405430);

INCLUDE_ASM("seg/seg_2FE810", func_004054E0);

INCLUDE_ASM("seg/seg_2FE810", func_004055C0);

INCLUDE_ASM("seg/seg_2FE810", func_004056A8);

INCLUDE_ASM("seg/seg_2FE810", func_00405780);

INCLUDE_ASM("seg/seg_2FE810", func_00405850);

INCLUDE_ASM("seg/seg_2FE810", func_00405970);

INCLUDE_ASM("seg/seg_2FE810", func_00405A88);

INCLUDE_ASM("seg/seg_2FE810", func_00405AE8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405B48);
#ifdef SKIP_ASM
void func_00405B48(unsigned a) {
    unsigned *r = (unsigned *)0x10002010;
    *r = (*r & 0xFF7FFFFF) | (a << 23);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00405B70);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405E10);
#ifdef SKIP_ASM
extern int func_00406F78(int, int);
int func_00405E10(int a) {
    return func_00406F78(a, 3);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00405E30);

INCLUDE_ASM("seg/seg_2FE810", func_00405FB8);

INCLUDE_ASM("seg/seg_2FE810", func_004060C8);

INCLUDE_ASM("seg/seg_2FE810", _sliceA0);

INCLUDE_ASM("seg/seg_2FE810", func_00406318);

INCLUDE_ASM("seg/seg_2FE810", func_00406510);

INCLUDE_ASM("seg/seg_2FE810", func_004065D0);

INCLUDE_ASM("seg/seg_2FE810", func_00406A78);

INCLUDE_ASM("seg/seg_2FE810", func_00406B00);

INCLUDE_ASM("seg/seg_2FE810", func_00406CA0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406DF0);
#ifdef SKIP_ASM
extern int D_004532C0[];
void func_00406DF0(int *p, unsigned a) {
    volatile int *r = (volatile int *)0x10002000;
    *r = a;
    p[518] = D_004532C0[a >> 28];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00406E20);

INCLUDE_ASM("seg/seg_2FE810", func_00406EC8);

INCLUDE_ASM("seg/seg_2FE810", func_00406F78);

INCLUDE_ASM("seg/seg_2FE810", func_004070F0);

INCLUDE_ASM("seg/seg_2FE810", func_004071F8);

INCLUDE_ASM("seg/seg_2FE810", func_004072E8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407438);
#ifdef SKIP_ASM
extern void func_004071F8(int, int);
extern int func_004070F0(int, int);
extern void func_00406E20(int);
void func_00407438(int p) {
    int n;
    func_00406E20(p);
    n = -(*(volatile int *)0x10002020 & 7) & 7;
    if (n)
        func_004071F8(p, n);
    while (func_004070F0(p, 0x18) != 1)
        func_004071F8(p, 8);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004074B8);
#ifdef SKIP_ASM
extern void func_004071F8(int, int);
extern int func_004072E8(int, int);
extern void func_00407A10(int);
int func_004074B8(int *p) {
    p[109] = func_004072E8((int)p, 5);
    if (func_004072E8((int)p, 1)) {
        func_004072E8((int)p, 1);
        func_004071F8((int)p, 7);
        func_00407A10((int)p);
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00407520);

INCLUDE_ASM("seg/seg_2FE810", func_00407630);

INCLUDE_ASM("seg/seg_2FE810", func_004076F8);

INCLUDE_ASM("seg/seg_2FE810", func_00407820);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407A10);
#ifdef SKIP_ASM
extern void func_004071F8(int, int);
extern int func_004072E8(int, int);
void func_00407A10(int p) {
    while (func_004072E8(p, 1))
        func_004071F8(p, 8);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00407A58);

INCLUDE_ASM("seg/seg_2FE810", func_00407AD0);

INCLUDE_ASM("seg/seg_2FE810", func_00407B70);

INCLUDE_ASM("seg/seg_2FE810", func_00407C38);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407D30);
#ifdef SKIP_ASM
extern int func_004072E8(int, int);
void func_00407D30(int p) {
    func_004072E8(p, 1);
    func_004072E8(p, 8);
    func_004072E8(p, 1);
    func_004072E8(p, 7);
    func_004072E8(p, 1);
    func_004072E8(p, 0x14);
    func_004072E8(p, 1);
    func_004072E8(p, 0x16);
    func_004072E8(p, 1);
    func_004072E8(p, 0x16);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00407DC0);

INCLUDE_ASM("seg/seg_2FE810", func_00407E90);

INCLUDE_ASM("seg/seg_2FE810", func_00407F20);

INCLUDE_ASM("seg/seg_2FE810", func_004081D8);

INCLUDE_ASM("seg/seg_2FE810", func_00408278);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00408508);
#ifdef SKIP_ASM
void func_00408508(int *p) {
    if (p[2] != 2) {
        p[2] = 2;
        p[43] = p[70];
    }
    p[520] = 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00408530);

INCLUDE_ASM("seg/seg_2FE810", func_004086C0);

INCLUDE_ASM("seg/seg_2FE810", func_004087D0);

INCLUDE_ASM("seg/seg_2FE810", func_00408988);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00408AF8);
#ifdef SKIP_ASM
extern int func_0042C078();
extern void func_0042C0C0(void);
void func_00408AF8(unsigned a, int b) {
    int s = func_0042C078();
    *(volatile unsigned *)0x1000B010 = (a & 0xFFFFFFF) | 0x80000000;
    *(volatile int *)0x1000B020 = b >> 4;
    *(volatile int *)0x1000B000 = 0x100;
    if (s)
        func_0042C0C0();
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00408B80);

INCLUDE_ASM("seg/seg_2FE810", func_00408CA8);

INCLUDE_ASM("seg/seg_2FE810", func_00408DF0);

INCLUDE_ASM("seg/seg_2FE810", func_00408FB0);

INCLUDE_ASM("seg/seg_2FE810", func_00409088);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409310);
#ifdef SKIP_ASM
extern int func_0042C078();
extern void func_0042C0C0(void);
void func_00409310(int a) {
    int s = func_0042C078();
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B000 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    if (s)
        func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409388);
#ifdef SKIP_ASM
extern int func_0042C078();
extern void func_0042C0C0(void);
void func_00409388(int a) {
    int s = func_0042C078();
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B400 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    if (s)
        func_0042C0C0();
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00409400);

INCLUDE_ASM("seg/seg_2FE810", func_004094E8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409638);
#ifdef SKIP_ASM
int func_00409638(int a) {
    int r = 0;
    int v;
    switch (a) {
    case 0:
        do {
            v = *(volatile int *)0x10002010;
            __asm__ volatile("nop");
        } while (v < 0);
        r = 0;
        break;
    case 1:
        r = *(volatile unsigned *)0x10002010 >> 31;
        break;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004096A0);
#ifdef SKIP_ASM
extern int func_0042C078(int);
extern void func_0042C0C0(void);
void func_004096A0(int a) {
    func_0042C078(a);
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B400 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    func_0042C0C0();
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00409708);

INCLUDE_ASM("seg/seg_2FE810", func_00409940);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409B10);
#ifdef SKIP_ASM
extern int D_004533C4[];
extern int D_004533C8[];
extern int func_00423DB0(int);
int func_00409B10(void) {
    if (D_004533C4[0] >= 0) {
        func_00423DB0(D_004533C4[0]);
        D_004533C4[0] = -1;
        func_00423DB0(D_004533C8[0]);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409B60);
#ifdef SKIP_ASM
extern int D_00528780[];
extern int D_004533C0[];
extern int D_004533C4[];
extern int D_005271C0[];
int *func_00409B60(int *a, int *b) {
    *a = (int)D_00528780;
    *b = (int)D_004533C0;
    D_00528780[15] = D_004533C4[0];
    return D_005271C0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00409B90);

INCLUDE_ASM("seg/seg_2FE810", func_00409C48);

INCLUDE_ASM("seg/seg_2FE810", func_00409D10);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409E38);
#ifdef SKIP_ASM
extern int func_00409D10(int, int, int, int);
extern int D_004533C0[];
int func_00409E38(int a, int b, int c) {
    int r = func_00409D10(a, b, c, 0x40);
    if (r == 0) {
        D_004533C0[0] = 0xB;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00409E70);

INCLUDE_ASM("seg/seg_2FE810", func_00409F28);

INCLUDE_ASM("seg/seg_2FE810", func_0040A000);

INCLUDE_ASM("seg/seg_2FE810", func_0040A090);

INCLUDE_ASM("seg/seg_2FE810", func_0040A1A8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A320);
#ifdef SKIP_ASM
extern void func_00423DD0(int);
void func_0040A320(int a, int b, int c) {
    func_00423DD0(c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A328);
#ifdef SKIP_ASM
extern int D_004533C8[];
extern void func_0040A320(int, int, int);
extern void func_00423B20(int, void (*)(int, int, int), int);
extern void func_00423DE0(int);
void func_0040A328(unsigned short a) {
    func_00423B20(a, func_0040A320, D_004533C8[0]);
    func_00423DE0(D_004533C8[0]);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040A360);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A440);
#ifdef SKIP_ASM
extern int *D_005271E8[];
extern int *D_005271EC[];
extern int *D_005271F0[];
void func_0040A440(unsigned a) {
    int *p = (int *)(a | 0x20000000);
    if (D_005271E8[0])
        *D_005271E8[0] = p[0];
    if (D_005271EC[0])
        *D_005271EC[0] = p[1];
    if (D_005271F0[0])
        *D_005271F0[0] = p[36];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040A498);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A618);
#ifdef SKIP_ASM
extern int D_00528780[];
extern void func_0040A618_log(char *) __asm__("func_00425C60");
extern int D_00527240[];
extern char D_00498158[];
int func_0040A618(void) {
    if (func_00426D18(D_005271C0, 53, 0, D_00527240, 48, D_00528780, 4, 0, 0)) {
        func_0040A618_log(D_00498158);
        return -1;
    }
    return D_00528780[0];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040A688);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A7D0);
#ifdef SKIP_ASM
extern char D_00527780[];
extern unsigned strlen(char *);
extern int func_0041605C(int, int, int);
void func_0040A7D0(char *dst) {
    char *src;
    int n;
    if (dst) {
        src = (char *)((unsigned)D_00527780 | 0x20000000);
        if (strlen(src) < 0x400)
            n = strlen(src);
        else
            n = 0x3FF;
        func_0041605C((int)dst, (unsigned)D_00527780 | 0x20000000, n);
        dst[n] = 0;
    }
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040A858);

INCLUDE_ASM("seg/seg_2FE810", func_0040A998);

INCLUDE_ASM("seg/seg_2FE810", func_0040AA68);

INCLUDE_ASM("seg/seg_2FE810", func_0040AB80);

INCLUDE_ASM("seg/seg_2FE810", func_0040AC38);

INCLUDE_ASM("seg/seg_2FE810", func_0040AE00);

INCLUDE_ASM("seg/seg_2FE810", func_0040AF58);

INCLUDE_ASM("seg/seg_2FE810", func_0040B028);

INCLUDE_ASM("seg/seg_2FE810", func_0040B130);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B1F8);
#ifdef SKIP_ASM
extern int D_004533E0[];
void func_0040B1F8(void) {
    D_004533E0[0] = 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040B208);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B2B0);
#ifdef SKIP_ASM
void func_0040B2B0(unsigned *p) {
    p[6] = 0;
    p[4] &= 0xFFFFFFFE;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040B2D0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B3D8);
#ifdef SKIP_ASM
extern int func_0040B400(int, int, int, int, int, int);
int func_0040B3D8(int a, int b, int c) {
    return func_0040B400(a, b, c, 0x800, 0x2000, 0x20);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040B400);

INCLUDE_ASM("seg/seg_2FE810", func_0040B5B0);

INCLUDE_ASM("seg/seg_2FE810", func_0040B6D0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B938);
#ifdef SKIP_ASM
extern char D_00453400[];
extern int func_00427D60(char *, int);
extern void func_004283A0(int, char *, int);
extern void func_00427FE8(int);
extern char D_00498220[];
int func_0040B938(void) {
    int h;
    if (D_00453400[0] == 0) {
        h = func_00427D60(D_00498220, 1);
        if (h >= 0) {
            func_004283A0(h, D_00453400, 14);
            func_00427FE8(h);
        }
    }
    return (int)D_00453400;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B9A8);
#ifdef SKIP_ASM
extern char D_00453400[];
extern int func_0040B938(void);
int func_0040B9A8(void) {
    if (D_00453400[0] == 0)
        func_0040B938();
    return D_00453400[4] == 0x54;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040B9E8);

INCLUDE_ASM("seg/seg_2FE810", func_0040BA48);
#ifdef SKIP_ASM
typedef struct { int a; int b; } U64;
extern U64 D_004533F8[];
void func_0040BA48(U64 *p) {
    D_004533F8[0] = *p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BA68);
#ifdef SKIP_ASM
extern unsigned char D_004533FA[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
int func_0040BA68(void) {
    unsigned buf[1];
    if (func_0040B9A8())
        return D_004533FA[0];
    func_00423E50(buf);
    return (buf[0] >> 1) & 3;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BAA8);
#ifdef SKIP_ASM
extern unsigned char D_004533FD[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
int func_0040BAA8(void) {
    unsigned buf[1];
    if (func_0040B9A8())
        return D_004533FD[0];
    func_00423E50(buf);
    return buf[0] & 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040BAE8);

INCLUDE_ASM("seg/seg_2FE810", func_0040BB38);

INCLUDE_ASM("seg/seg_2FE810", func_0040BBA0);

INCLUDE_ASM("seg/seg_2FE810", func_0040BC08);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BC70);
#ifdef SKIP_ASM
unsigned char func_0040BC70(unsigned char a) {
    return a + (a / 10) * 6;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040BCA0);
#ifdef SKIP_ASM
unsigned char func_0040BCA0(unsigned char x) {
    return x - (x / 16) * 6;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BCC0);
#ifdef SKIP_ASM
void func_0040BCC0(unsigned char *p) {
    p[7] = func_0040BCA0(p[7]);
    p[6] = func_0040BCA0(p[6]);
    p[5] = func_0040BCA0(p[5]);
    p[3] = func_0040BCA0(p[3]);
    p[2] = func_0040BCA0(p[2]);
    p[1] = func_0040BCA0(p[1]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BD28);
#ifdef SKIP_ASM
void func_0040BD28(unsigned char *p) {
    p[7] = func_0040BC70(p[7]);
    p[6] = func_0040BC70(p[6]);
    p[5] = func_0040BC70(p[5]);
    p[3] = func_0040BC70(p[3]);
    p[2] = func_0040BC70(p[2]);
    p[1] = func_0040BC70(p[1]);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040BD90);

INCLUDE_ASM("seg/seg_2FE810", func_0040BE48);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BEF0);
#ifdef SKIP_ASM
extern void func_0040BD90(unsigned char *);
void func_0040BEF0(unsigned char *p) {
    p[3]++;
    if (p[3] == 24) {
        p[3] = 0;
        func_0040BD90(p);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BF20);
#ifdef SKIP_ASM
extern void func_0040BE48(unsigned char *);
void func_0040BF20(unsigned char *p) {
    if (p[3] == 0) {
        p[3] = 23;
        func_0040BE48(p);
    } else {
        p[3]--;
    }
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040BF48);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BFD8);
#ifdef SKIP_ASM
extern void func_0040BF48(int, int);
void func_0040BFD8(int a) {
    func_0040BF48(a, -540);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BFE0);
#ifdef SKIP_ASM
extern int func_0040BAE8(void);
extern int func_0040BBA0(void);
extern void func_0040BF48(int, int);
void func_0040BFE0(int a) {
    int t = func_0040BAE8();
    func_0040BF48(a, t - 540 + func_0040BBA0() * 60);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040C028);

INCLUDE_ASM("seg/seg_2FE810", func_0040C220);

INCLUDE_ASM("seg/seg_2FE810", sceUsbKbGetInfo);

INCLUDE_ASM("seg/seg_2FE810", sceUsbKbRead);

INCLUDE_ASM("seg/seg_2FE810", sceUsbKbGetLocation);

INCLUDE_ASM("seg/seg_2FE810", sceUsbKbSetLEDStatus);

INCLUDE_ASM("seg/seg_2FE810", sceUsbKbSetLEDMode);

INCLUDE_ASM("seg/seg_2FE810", func_0040C728);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C770);
#ifdef SKIP_ASM
struct E_529000 { int f0; int f4; int f8; char pad[0x2C]; };
struct T_529000 { int n; struct E_529000 *e; };
extern struct T_529000 D_00529000[];
int func_0040C770(int a, unsigned b) {
    if (a >= D_00529000[0].n)
        return -11;
    if (b >= 2)
        return -12;
    D_00529000[0].e[a].f4 = b;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C7C0);
#ifdef SKIP_ASM
int func_0040C7C0(int a, unsigned b) {
    if (a >= D_00529000[0].n)
        return -11;
    if (b >= 3)
        return -12;
    D_00529000[0].e[a].f8 = b;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040C810);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C8B0);
#ifdef SKIP_ASM
extern int D_00453438[];
extern void func_00423DD0(int);
void func_0040C8B0(void) {
    func_00423DD0(D_00453438[0]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C8C0);
#ifdef SKIP_ASM
struct S_C8C0 { char pad[0x90]; int f90; int pad2; int f98; };
extern struct S_C8C0 G_C8C0[] __asm__("D_00529000");
extern int (*D_00453420[])(void);
int func_0040C8C0(void) {
    int r = 0;
    unsigned s = G_C8C0[0].f90;
    if (s - 1 < 5)
        r = D_00453420[s]();
    G_C8C0[0].f90 = 0;
    G_C8C0[0].f98 = 0;
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040C928);

INCLUDE_ASM("seg/seg_2FE810", func_0040C980);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040CEF8);
#ifdef SKIP_ASM
extern unsigned char *D_00529098[];
extern unsigned char D_00529140[];
int func_0040CEF8(void) {
    unsigned char *s = D_00529140;
    unsigned char *d = D_00529098[0];
    int i;
    if (s[6])
        return -1;
    i = 6;
    do {
        *d = *s; i--; s++; d++;
    } while (i >= 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040CF48);
#ifdef SKIP_ASM
extern unsigned char D_00529141[];
extern unsigned char D_00529101[];
int func_0040CF48(void) {
    return D_00529141[0] == D_00529101[0] ? 0 : -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040CF68);
#ifdef SKIP_ASM
int func_0040CF68(void) {
    return D_00529141[0] == D_00529101[0] ? 0 : -1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040CF88);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D010);
#ifdef SKIP_ASM
extern char *D_00529004[];
int func_0040D010(int i) {
    int *p = (int *)(D_00529004[0] + i * 0x38 + 0x10);
    p[9] = 0;
    p[7] = 0;
    p[8] = 0;
    p[1] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D040);
#ifdef SKIP_ASM
struct E_D040 { char pad[0x22]; unsigned short buf[5]; int idx; };
int func_0040D040(int a, unsigned short b) {
    struct E_D040 *e = (struct E_D040 *)(D_00529004[0] + a * 0x38);
    int *q = (int *)((char *)e + 0x10);
    if (q[9] >= 4)
        return -1;
    e->buf[e->idx++] = b;
    if (q[7] >= 4)
        q[7] = 0;
    q[9]++;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D0B0);
#ifdef SKIP_ASM
struct E_D0B0 { char pad[0x22]; unsigned short buf[7]; int idx; };
int func_0040D0B0(int a, unsigned short *out) {
    struct E_D0B0 *e = (struct E_D0B0 *)(D_00529004[0] + a * 0x38);
    int *q = (int *)((char *)e + 0x10);
    if (q[9] <= 0)
        return -1;
    *out = e->buf[e->idx++];
    if (q[8] >= 4)
        q[8] = 0;
    q[9]--;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040D118);

INCLUDE_ASM("seg/seg_2FE810", func_0040D268);

INCLUDE_ASM("seg/seg_2FE810", func_0040D3C0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D430);
#ifdef SKIP_ASM
int func_0040D430(int a, unsigned b) {
    char *e;
    if (a >= D_00529000[0].n)
        return -11;
    if (b >= 2)
        return -12;
    e = (char *)(a * 0x38) + (int)D_00529000[0].e;
    if (b != *(unsigned *)(e + 0xC)) {
        *(int *)(e + 0x14) = 0;
        *(int *)(e + 0x2C) = 0;
        *(int *)(e + 0x30) = 0;
        *(int *)((char *)D_00529000 + 0x10) = 0;
        *(short *)(e + 0x20) = 0;
    }
    *(unsigned *)(e + 0xC) = b;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040D4A0);

INCLUDE_ASM("seg/seg_2FE810", func_0040D588);

INCLUDE_ASM("seg/seg_2FE810", func_0040D610);

INCLUDE_ASM("seg/seg_2FE810", func_0040D758);

INCLUDE_ASM("seg/seg_2FE810", func_0040D8D0);

INCLUDE_ASM("seg/seg_2FE810", func_0040DA10);

INCLUDE_ASM("seg/seg_2FE810", func_0040DB58);

INCLUDE_ASM("seg/seg_2FE810", func_0040E048);

INCLUDE_ASM("seg/seg_2FE810", func_0040E300);

INCLUDE_ASM("seg/seg_2FE810", func_0040E550);

INCLUDE_ASM("seg/seg_2FE810", func_0040E878);

INCLUDE_ASM("seg/seg_2FE810", func_0040EC58);

INCLUDE_ASM("seg/seg_2FE810", func_0040F5A8);

INCLUDE_ASM("seg/seg_2FE810", func_0040F840);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040F878);
#ifdef SKIP_ASM
extern void func_00412500(long, long);
int func_0040F878(long *p) {
    long v = p[1];
    func_00412500(v, v);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040F8A0);

INCLUDE_ASM("seg/seg_2FE810", func_0040F8C0);

INCLUDE_ASM("seg/seg_2FE810", func_0040F8E8);

INCLUDE_ASM("seg/seg_2FE810", func_0040F9D0);

INCLUDE_ASM("seg/seg_2FE810", func_0040F9F8);

INCLUDE_ASM("seg/seg_2FE810", func_0040FB58);

INCLUDE_ASM("seg/seg_2FE810", func_0040FB88);

INCLUDE_ASM("seg/seg_2FE810", func_0040FBE0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040FC90);
#ifdef SKIP_ASM
extern int D_0052AD98[];
extern void func_0040FBE0(void);
void func_0040FC90(void) {
    if (D_0052AD98[0] == 0) {
        D_0052AD98[0] = 1;
        func_0040FBE0();
    }
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040FCB0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004103A0);
#ifdef SKIP_ASM
extern int func_00418790(void) __attribute__((noreturn));
int func_004103A0(void) {
    return func_00418790();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004103B0);
#ifdef SKIP_ASM
extern void (*D_00453440[])(void);
void func_004103B0(void) {
    D_00453440[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004103D8);
#ifdef SKIP_ASM
extern int func_004165A8(int, int);
int func_004103D8(int a, int b, int c) {
    if (func_004165A8(a, b)) {
        c = 0;
    }
    return c;
}
#endif

void func_00410408(void) {
}

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00410410);
#ifdef SKIP_ASM
extern int *func_00410410_alloc(int) __asm__("func_004188C0");
extern void func_004103B0(void);
extern void func_00416210(int *, int, int);
int *func_00410410(void) {
    int *p = func_00410410_alloc(0x18);
    if (!p)
        func_004103B0();
    func_00416210(p, 0, 0x18);
    p[1] = (int)(p + 4);
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00410468);
#ifdef SKIP_ASM
extern int (*D_00453444[])(void);
void func_00410468(void) {
    D_00453444[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00410490);
#ifdef SKIP_ASM
int *func_00410490(void) {
    return (int *)D_00453444[0]() + 2;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004104B8);
#ifdef SKIP_ASM
extern int func_004104E0(void);
void func_004104B8(void) {
    int (*fp)(void) = func_004104E0;
    D_00453444[0] = fp;
    fp();
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004104E0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00410548);
#ifdef SKIP_ASM
int *func_00410548(void) {
    return (int *)D_00453444[0]() + 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00410570);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00410848);
#ifdef SKIP_ASM
int func_00410848(short *p) {
    return p[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00410850);
#ifdef SKIP_ASM
int func_00410850(short *p) {
    return p[2];
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00410858);

INCLUDE_ASM("seg/seg_2FE810", func_00410930);

INCLUDE_ASM("seg/seg_2FE810", func_00410A78);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00410B00);
#ifdef SKIP_ASM
extern int func_00410A78();
extern int func_0041605C(int, int, int);
int func_00410B00(int a, int b, int c) {
    int x = func_00410A78(a, b, 0);
    int y = func_00410A78(a, c, 0);
    int k;
    k = a < 31 ? 16 : (a <= 63 ? 4 : 8);
    return func_0041605C(y, x, k);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00410B80);

void func_00410C10(void) {
}

INCLUDE_ASM("seg/seg_2FE810", func_00410C18);

INCLUDE_ASM("seg/seg_2FE810", func_00410F48);

INCLUDE_ASM("seg/seg_2FE810", func_00411128);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00411310);
#ifdef SKIP_ASM
extern void func_0040FB88(int);
extern void func_00416FE0(void);
extern void func_001001C8(int);
void func_00411310(int a) {
    func_0040FB88(a);
    func_00416FE0();
    func_001001C8(a);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00411340);

INCLUDE_ASM("seg/seg_2FE810", func_00411438);

INCLUDE_ASM("seg/seg_2FE810", func_004114D0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00411530);
#ifdef SKIP_ASM
extern void func_004103B0(void);
void func_00411530(void) {
    func_004103B0();
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00411538);

INCLUDE_ASM("seg/seg_2FE810", func_00411B08);

INCLUDE_ASM("seg/seg_2FE810", func_00411C38);

INCLUDE_ASM("seg/seg_2FE810", func_00411CD8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00411F18);
#ifdef SKIP_ASM
struct S412778;
extern void func_00411C38(long *, int *);
extern struct S412778 *func_00411CD8(int *, int *, int *);
extern void func_00411B08(struct S412778 *);
void func_00411F18(long a, long b) {
    int x[8];
    int y[8];
    int z[8];
    func_00411C38(&a, x);
    func_00411C38(&b, y);
    func_00411B08(func_00411CD8(x, y, z));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00411F70);
#ifdef SKIP_ASM
struct S412778;
extern void func_00411C38(long *, int *);
extern struct S412778 *func_00411CD8(int *, int *, int *);
extern void func_00411B08(struct S412778 *);
void func_00411F70(long a, long b) {
    int x[8];
    int y[8];
    int z[8];
    func_00411C38(&a, x);
    func_00411C38(&b, y);
    y[1] ^= 1;
    func_00411B08(func_00411CD8(x, y, z));
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00411FD8);

INCLUDE_ASM("seg/seg_2FE810", func_00412280);

INCLUDE_ASM("seg/seg_2FE810", func_004123E8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412500);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
extern void func_004123E8(int *, int *);
void func_00412500(long a, long b) {
    int x[8];
    int y[8];
    func_00411C38(&a, x);
    func_00411C38(&b, y);
    func_004123E8(x, y);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00412550);

INCLUDE_ASM("seg/seg_2FE810", func_00412608);

INCLUDE_ASM("seg/seg_2FE810", func_004126A0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412740);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
void func_00412740(long a) {
    int buf[8];
    func_00411C38(&a, buf);
    buf[1] = buf[1] == 0;
    func_00411B08((struct S412778 *)buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412778);
#ifdef SKIP_ASM
struct S412778 { int a, b, c; long d; };
extern void func_00411B08(struct S412778 *);
void func_00412778(int a, int b, int c, long d) {
    struct S412778 s;
    s.a = a;
    s.b = b;
    s.c = c;
    s.d = d;
    func_00411B08(&s);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004127A8);

INCLUDE_ASM("seg/seg_2FE810", func_00412800);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412838);
#ifdef SKIP_ASM
extern int D_00453A38[];
int func_00412838(int v) {
    int o = D_00453A38[0];
    D_00453A38[0] = v;
    return o;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00412848);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412888);
#ifdef SKIP_ASM
extern int *func_00410490(void);
int func_00412888(void) {
    return *func_00410490();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004128A8);
#ifdef SKIP_ASM
extern int *func_00410490(void);
int *func_004128A8(void) {
    int *p = (int *)*func_00410490();
    p[5] = 1;
    *(long *)(p + 8) += 1;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004128E0);
#ifdef SKIP_ASM
extern int func_004188C0(void);
extern int func_00412800(void) __attribute__((noreturn));
int func_004128E0(void) {
    if (func_004188C0() == 0)
        return func_00412800();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412908);
#ifdef SKIP_ASM
extern int func_00418910(void);
int func_00412908(void) {
    return func_00418910();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412928);
#ifdef SKIP_ASM
extern int func_00415260(int, int, int);
int func_00412928(int *a, int (*fn)(void), short *c) {
    int r;
    if (c != 0 && c[2] != 4)
        return 0;
    if (fn == (int (*)(void))-1)
        return a[2];
    r = func_00415260(fn(), a[3], a[10]);
    if (r)
        a[2] = r;
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00412998);

INCLUDE_ASM("seg/seg_2FE810", func_00412A28);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412AF0);
#ifdef SKIP_ASM
extern int *func_00410490(void);
extern int func_00412800(void) __attribute__((noreturn));
void func_00412AF0(void) {
    int *p = (int *)*func_00410490();
    if (p == 0) {
        func_00412800();
    }
    p[5] = 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00412B20);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00412E10);
#ifdef SKIP_ASM
int func_00412E10(int *p) {
    int *(**vt)(int *) = *(int *(***)(int *))p;
    return *vt[1](p);
}
#endif
