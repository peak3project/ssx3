#include "common.h"

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCDC8);
#ifdef SKIP_ASM
extern int func_003FC0D8(int);
extern int func_003FA240(int);
extern int func_003FB810(int);
int func_003FCDC8(int a) {
    int r;
    if (func_003FC0D8(a)) {
        r = func_003FB810(func_003FA240(a));
    } else {
        r = 2;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCE10);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF00);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF98);
#ifdef SKIP_ASM
extern int func_003FB898(int, int);
int func_003FCF98(int a, int *out) {
    int r;
    if (out) {
        *out = func_003FB898(a, 2);
        r = 0;
    } else {
        r = 4;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCFD8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD0D8);
#ifdef SKIP_ASM
extern void (*D_0045152C[])(int, int);
void func_003FD0D8(int a) {
    D_0045152C[0](a, 0x1020000);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD100);
#ifdef SKIP_ASM
extern int (*D_00451530[])(void);
void func_003FD100(void) {
    D_00451530[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD128);
#ifdef SKIP_ASM
extern int (*D_00451534[])(void);
void func_003FD128(void) {
    D_00451534[0]();
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD150);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD1D8);
#ifdef SKIP_ASM
int func_003FD1D8(int *p) {
    return *p == 0x464C457F;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD1F0);
#ifdef SKIP_ASM
int func_003FD1F0(int *p, int n) {
    int base = *p;
    return base + *(int *)(base + 0x20) + n * 40;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD210);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD2B8);
#ifdef SKIP_ASM
unsigned func_003FD2B8(int *p, unsigned n) {
    unsigned r;
    if (n <= 0xFEFF) {
        r = ((unsigned *)func_003FD1F0(p, n))[4];
    } else {
        r = n == 0xFFF1 ? 0xFFF00000 : 0;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD2F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD558);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD660);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD6E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD758);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD810);

void func_003FD908(void) {
}

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD910);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FDAA0);
#ifdef SKIP_ASM
extern char D_00451550[];
void *func_003FDAA0(void) {
    return D_00451550;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDAB0);

INCLUDE_ASM("seg/seg_2FDDC8", sceGsSyncPath);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDE30);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDEA0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FDF28);
#ifdef SKIP_ASM
unsigned func_003FDF28(unsigned a) {
    if ((a >> 28) == 7) {
        a &= 0xFFFFFFF;
        a |= 0x80000000;
    }
    return a;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDF50);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FDF88);
#ifdef SKIP_ASM
extern int D_00451590[];
int func_003FDF88(unsigned n) {
    return n < 10 ? D_00451590[n] : 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDFB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE090);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FE268);
#ifdef SKIP_ASM
struct S003FE268 { int c[5]; };
extern struct S003FE268 D_005261D0[];
struct S003FE268 *func_003FE268(struct S003FE268 *d) {
    *d = D_005261D0[0];
    return d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FE2A0);
#ifdef SKIP_ASM
int func_003FE2A0(int v) {
    int *r = (int *)0x1000E060;
    int o = *r;
    *r = v;
    return o;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE2B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE320);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE398);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE410);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE458);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE4D8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FE558);
#ifdef SKIP_ASM
extern void func_003FDE30(int *, int);
int func_003FE558(unsigned *p, int m) {
    if (m != 1) {
        func_003FDE30((int *)p, m);
        return 0;
    }
    return (*p >> 8) & 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FE590);
#ifdef SKIP_ASM
extern void func_003FDEA0(int *, unsigned, int);
int func_003FE590(int *p, unsigned n, int m, int x) {
    if (m != 1) {
        func_003FDEA0(p, n, x);
        return 0;
    }
    return (unsigned)p[4] < n;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE5C8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FE660);
#ifdef SKIP_ASM
unsigned func_003FE660(unsigned *p, unsigned v) {
    unsigned o = *p;
    *p = v;
    return (o >> 8) & 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE678);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE690);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE6A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE708);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE758);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE788);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE7B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE7C8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE7D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE818);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE828);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE838);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE998);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEB08);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEB38);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEB78);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEBC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEBD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEC38);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEC88);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FECB8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FECE8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FECF8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FED08);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FED50);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FED60);
#ifdef SKIP_ASM
extern void func_003FEB78(void *, int);
unsigned short func_003FED60(void) {
    unsigned short v;
    func_003FEB78(&v, 0x43A);
    return v;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FED88);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEF18);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF060);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF088);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FF0F0);
#ifdef SKIP_ASM
extern int func_003FF160(void);
int func_003FF0F0(void) {
    if (func_003FF160() == 1) {
        volatile int *reg = (volatile int *)0x10003810;
        *reg = 8;
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF130);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF150);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FF160);
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

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF1B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF330);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF390);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF4A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF5E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF688);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF708);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF8F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF9A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFA08);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFA58);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFBC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFC38);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFC70);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFCD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFD28);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFD60);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFE80);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFFA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004000D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400190);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400250);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400328);

INCLUDE_ASM("seg/seg_2FDDC8", func_004003E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400490);

INCLUDE_ASM("seg/seg_2FDDC8", func_004004F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400548);

INCLUDE_ASM("seg/seg_2FDDC8", func_004005A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400670);

INCLUDE_ASM("seg/seg_2FDDC8", func_004006D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400740);

INCLUDE_ASM("seg/seg_2FDDC8", func_004007A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400810);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400838);

INCLUDE_ASM("seg/seg_2FDDC8", func_004008A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400908);

INCLUDE_ASM("seg/seg_2FDDC8", func_004009A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400A78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400B48);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400C00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400CB8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400D58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400DD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400E30);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400EA8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_004011C0);
#ifdef SKIP_ASM
extern void func_00400EA8(int, int, int);
void func_004011C0(int a, int b) {
    func_00400EA8(a, b, 0);
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_004011E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401350);

INCLUDE_ASM("seg/seg_2FDDC8", func_004013E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401488);

INCLUDE_ASM("seg/seg_2FDDC8", func_004014F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401668);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401718);

INCLUDE_ASM("seg/seg_2FDDC8", func_004019F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401BF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401DF8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401FD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402268);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402300);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402398);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402450);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402520);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402618);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402708);

INCLUDE_ASM("seg/seg_2FDDC8", func_004027B8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_004029C8);
#ifdef SKIP_ASM
int func_004029C8(void) {
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_004029D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402A10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402A58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402AA0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402AF0);
#ifdef SKIP_ASM
void func_00402AF0(int *p) {
    int *q = (int *)p[16];
    q[0x428] = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402B00);
#ifdef SKIP_ASM
void func_00402B00(int *p, int a, int b, int c) {
    int *q = (int *)p[16];
    q[37] = a;
    q[38] = b;
    q[39] = c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402B18);
#ifdef SKIP_ASM
void func_00402B18(int *p, int *a, int *b, int *c) {
    int *q = (int *)p[16];
    *a = q[37];
    *b = q[38];
    *c = q[39];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402B38);
#ifdef SKIP_ASM
int func_00402B38(int *p) {
    int *q = (int *)p[16];
    return q[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402B48);
#ifdef SKIP_ASM
int func_00402B48(int *p) {
    int *q = (int *)p[16];
    return q[1] == 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00402B58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402BB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402C08);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402C30);
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
INCLUDE_ASM("seg/seg_2FDDC8", func_00402C80);
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
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CA8);
#ifdef SKIP_ASM
int func_00402CA8(int *p, long v) {
    int *q = (int *)p[16];
    q[28] = 1;
    *(long *)&q[30] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CC0);
#ifdef SKIP_ASM
int func_00402CC0(int *p) {
    int *q = (int *)p[16];
    q[28] = 0;
    *(long *)&q[30] = 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CD8);
#ifdef SKIP_ASM
int func_00402CD8(int *p, int v) {
    int *q = (int *)p[16];
    q[54] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CE8);
#ifdef SKIP_ASM
int func_00402CE8(int *p) {
    int *q = (int *)p[16];
    return q[51];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CF8);
#ifdef SKIP_ASM
int func_00402CF8(int *p) {
    int *q = (int *)p[16];
    return q[52];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D08);
#ifdef SKIP_ASM
char *func_00402D08(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D18);
#ifdef SKIP_ASM
char *func_00402D18(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D28);
#ifdef SKIP_ASM
int func_00402D28(int *p, int v) {
    int *q = (int *)p[16];
    int old = q[58];
    q[58] = v;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D38);
#ifdef SKIP_ASM
int func_00402D38(int *p, long v) {
    int *q = (int *)p[16];
    *(long *)&q[60] = v;
    q[62] = 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D50);
#ifdef SKIP_ASM
void func_00402D50(int *p, int a, int b) {
    p[0] = a;
    p[1] = b;
    p[2] = a;
    p[3] = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D68);
#ifdef SKIP_ASM
int func_00402D68(int *p) {
    return p[3] = p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D78);
#ifdef SKIP_ASM
int func_00402D78(int *p) {
    return p[2] = p[3];
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00402D88);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402DF8);
#ifdef SKIP_ASM
int func_00402DF8(int *p) {
    return p[0] + p[1] - p[2];
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00402E10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402F80);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403098);

INCLUDE_ASM("seg/seg_2FDDC8", func_004030E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403240);

INCLUDE_ASM("seg/seg_2FDDC8", func_004032A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004032B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403338);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403398);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403460);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403470);

INCLUDE_ASM("seg/seg_2FDDC8", func_004034A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403500);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00403600);
#ifdef SKIP_ASM
int func_00403600(int *p, int a, int b) {
    p[1] = a;
    p[2] = b;
    p[3] = a >> 4;
    p[4] = b >> 4;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00403620);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403748);

INCLUDE_ASM("seg/seg_2FDDC8", func_004039F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403AD0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403BB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403CE0);

INCLUDE_ASM("seg/seg_2FDDC8", _sequenceScalableExtension);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403D80);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403D90);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403DA0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00403DB0);
#ifdef SKIP_ASM
extern void func_00409400(void *);
int func_00403DB0(int *p) {
    func_00409400((char *)p[16] + 0x4C);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00403DD8);
#ifdef SKIP_ASM
extern void func_004094E8(void *);
int func_00403DD8(int *p) {
    func_004094E8((char *)p[16] + 0x4C);
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00403E00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404050);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404758);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404B78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404D98);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404E10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404EA8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404F60);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405030);

INCLUDE_ASM("seg/seg_2FDDC8", func_004050E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405198);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405290);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405390);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405430);

INCLUDE_ASM("seg/seg_2FDDC8", func_004054E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004055C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004056A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405780);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405850);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405970);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405A88);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405AE8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00405B48);
#ifdef SKIP_ASM
void func_00405B48(unsigned a) {
    unsigned *r = (unsigned *)0x10002010;
    *r = (*r & 0xFF7FFFFF) | (a << 23);
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00405B70);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00405E10);
#ifdef SKIP_ASM
extern void func_00406F78(int, int);
void func_00405E10(int a) {
    func_00406F78(a, 3);
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00405E30);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405FB8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004060C8);

INCLUDE_ASM("seg/seg_2FDDC8", _sliceA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406318);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406510);

INCLUDE_ASM("seg/seg_2FDDC8", func_004065D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406A78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406B00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406CA0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00406DF0);
#ifdef SKIP_ASM
extern int D_004532C0[];
void func_00406DF0(int *p, unsigned a) {
    volatile int *r = (volatile int *)0x10002000;
    *r = a;
    p[518] = D_004532C0[a >> 28];
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00406E20);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406EC8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406F78);

INCLUDE_ASM("seg/seg_2FDDC8", func_004070F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004071F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004072E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407438);

INCLUDE_ASM("seg/seg_2FDDC8", func_004074B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407520);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407630);

INCLUDE_ASM("seg/seg_2FDDC8", func_004076F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407820);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407A10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407A58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407AD0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407B70);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407C38);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407D30);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407DC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407E90);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407F20);

INCLUDE_ASM("seg/seg_2FDDC8", func_004081D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408278);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00408508);
#ifdef SKIP_ASM
void func_00408508(int *p) {
    if (p[2] != 2) {
        p[2] = 2;
        p[43] = p[70];
    }
    p[520] = 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00408530);

INCLUDE_ASM("seg/seg_2FDDC8", func_004086C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004087D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408988);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408AF8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408B80);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408CA8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408DF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408FB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409088);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409310);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409388);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409400);

INCLUDE_ASM("seg/seg_2FDDC8", func_004094E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409638);

INCLUDE_ASM("seg/seg_2FDDC8", func_004096A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409708);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409940);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409B10);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00409B60);
#ifdef SKIP_ASM
extern int D_00528780[];
extern int D_004533C0[];
extern int D_004533C4[];
extern int D_005271C0[];
int *func_00409B60(int **a, int **b) {
    *a = D_00528780;
    *b = D_004533C0;
    D_00528780[15] = D_004533C4[0];
    return D_005271C0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00409B90);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409C48);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409D10);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00409E38);
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

INCLUDE_ASM("seg/seg_2FDDC8", func_00409E70);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409F28);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A000);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A090);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A1A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A320);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A328);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A360);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A440);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A498);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A618);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A688);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A7D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A858);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A998);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AA68);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AB80);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AC38);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AE00);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AF58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B028);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B130);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040B1F8);
#ifdef SKIP_ASM
extern int D_004533E0[];
void func_0040B1F8(void) {
    D_004533E0[0] = 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B208);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040B2B0);
#ifdef SKIP_ASM
void func_0040B2B0(unsigned *p) {
    p[6] = 0;
    p[4] &= 0xFFFFFFFE;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B2D0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040B3D8);
#ifdef SKIP_ASM
extern int func_0040B400(int, int, int, int, int, int);
int func_0040B3D8(int a, int b, int c) {
    return func_0040B400(a, b, c, 0x800, 0x2000, 0x20);
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B400);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B5B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B6D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B938);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B9A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B9E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BA48);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BA68);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BAA8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BAE8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BB38);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BBA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BC08);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040BC70);
#ifdef SKIP_ASM
unsigned char func_0040BC70(unsigned char a) {
    return a + (a / 10) * 6;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BCA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BCC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BD28);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BD90);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BE48);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BEF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BF20);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BF48);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BFD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BFE0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C028);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C220);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbGetInfo);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbRead);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbGetLocation);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbSetLEDStatus);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbSetLEDMode);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C728);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C770);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C7C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C810);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C8B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C8C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C928);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C980);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040CEF8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040CF48);
#ifdef SKIP_ASM
extern unsigned char D_00529141[];
extern unsigned char D_00529101[];
int func_0040CF48(void) {
    return D_00529141[0] == D_00529101[0] ? 0 : -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040CF68);
#ifdef SKIP_ASM
int func_0040CF68(void) {
    return D_00529141[0] == D_00529101[0] ? 0 : -1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_0040CF88);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040D010);
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

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D040);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D0B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D118);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D268);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D3C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D430);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D4A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D588);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D610);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D758);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D8D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040DA10);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040DB58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E048);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E300);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E550);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E878);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040EC58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F5A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F840);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040F878);
#ifdef SKIP_ASM
extern void func_00412500(long, long);
int func_0040F878(long *p) {
    long v = p[1];
    func_00412500(v, v);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F8A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F8C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F8E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F9D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F9F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FB58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FB88);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FBE0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FC90);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FCB0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_004103A0);
#ifdef SKIP_ASM
extern void func_00418790(void) __attribute__((noreturn));
void func_004103A0(void) {
    func_00418790();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_004103B0);
#ifdef SKIP_ASM
extern void (*D_00453440[])(void);
void func_004103B0(void) {
    D_00453440[0]();
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_004103D8);

void func_00410408(void) {
}

INCLUDE_ASM("seg/seg_2FDDC8", func_00410410);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00410468);
#ifdef SKIP_ASM
extern int (*D_00453444[])(void);
void func_00410468(void) {
    D_00453444[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00410490);
#ifdef SKIP_ASM
int *func_00410490(void) {
    return (int *)D_00453444[0]() + 2;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_004104B8);
#ifdef SKIP_ASM
extern int func_004104E0(void);
void func_004104B8(void) {
    int (*fp)(void) = func_004104E0;
    D_00453444[0] = fp;
    fp();
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_004104E0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00410548);
#ifdef SKIP_ASM
int *func_00410548(void) {
    return (int *)D_00453444[0]() + 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00410570);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00410848);
#ifdef SKIP_ASM
int func_00410848(short *p) {
    return p[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00410850);
#ifdef SKIP_ASM
int func_00410850(short *p) {
    return p[2];
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00410858);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410930);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410A78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410B00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410B80);

void func_00410C10(void) {
}

INCLUDE_ASM("seg/seg_2FDDC8", func_00410C18);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410F48);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411128);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411310);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411340);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411438);

INCLUDE_ASM("seg/seg_2FDDC8", func_004114D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411530);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411538);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411B08);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411C38);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411CD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411F18);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411F70);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411FD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412280);

INCLUDE_ASM("seg/seg_2FDDC8", func_004123E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412500);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412550);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412608);

INCLUDE_ASM("seg/seg_2FDDC8", func_004126A0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412740);
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
INCLUDE_ASM("seg/seg_2FDDC8", func_00412778);
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

INCLUDE_ASM("seg/seg_2FDDC8", func_004127A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412800);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412838);
#ifdef SKIP_ASM
extern int D_00453A38[];
int func_00412838(int v) {
    int o = D_00453A38[0];
    D_00453A38[0] = v;
    return o;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00412848);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412888);
#ifdef SKIP_ASM
extern int *func_00410490(void);
int func_00412888(void) {
    return *func_00410490();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_004128A8);
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
INCLUDE_ASM("seg/seg_2FDDC8", func_004128E0);
#ifdef SKIP_ASM
extern int func_004188C0(void);
extern void func_00412800(void) __attribute__((noreturn));
void func_004128E0(void) {
    if (func_004188C0() == 0) {
        func_00412800();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412908);
#ifdef SKIP_ASM
extern void func_00418910(void);
void func_00412908(void) {
    func_00418910();
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00412928);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412998);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412A28);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412AF0);
#ifdef SKIP_ASM
extern int *func_00410490(void);
extern void func_00412800(void) __attribute__((noreturn));
void func_00412AF0(void) {
    int *p = (int *)*func_00410490();
    if (p == 0) {
        func_00412800();
    }
    p[5] = 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00412B20);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412E10);
#ifdef SKIP_ASM
int func_00412E10(int *p) {
    int *(**vt)(int *) = *(int *(***)(int *))p;
    return *vt[1](p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412E38);
#ifdef SKIP_ASM
extern char D_004998B8[];
extern void operator_delete__FPi(void *);
void func_00412E38(int *p, int f) {
    *p = (int)D_004998B8;
    if (f & 1) {
        operator_delete__FPi(p);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412E68);
#ifdef SKIP_ASM
extern char D_004998A0[];
void *func_00412E68(void **p) {
    *p = D_004998A0;
    return p;
}
#endif
