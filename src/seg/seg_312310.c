#include "common.h"

//100%
INCLUDE_ASM("seg/seg_312310", func_00411310);
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

INCLUDE_ASM("seg/seg_312310", func_00411340);

//100%
INCLUDE_ASM("seg/seg_312310", func_00411438);
#ifdef SKIP_ASM
extern double itod_411438(int) __asm__("func_00412550");
extern double dmul_411438(double, double) __asm__("func_00411FD8");
extern double dadd_411438(double, double) __asm__("func_00411F18");
double func_00411438(long a) {
    double hi = itod_411438((int)(a >> 32));
    double lo;
    hi = dmul_411438(hi, 65536.0);
    hi = dmul_411438(hi, 65536.0);
    lo = itod_411438((int)(a & 0xFFFFFFFF));
    if ((int)(a & 0xFFFFFFFF) < 0)
        lo = dadd_411438(lo, 4294967296.0);
    return dadd_411438(hi, lo);
}
#endif

INCLUDE_ASM("seg/seg_312310", func_004114D0);

//100%
INCLUDE_ASM("seg/seg_312310", func_00411530);
#ifdef SKIP_ASM
extern void func_004103B0(void);
void func_00411530(void) {
    func_004103B0();
}
#endif

INCLUDE_ASM("seg/seg_312310", func_00411538);

INCLUDE_ASM("seg/seg_312310", func_00411B08);

INCLUDE_ASM("seg/seg_312310", func_00411C38);

INCLUDE_ASM("seg/seg_312310", func_00411CD8);

//100%
INCLUDE_ASM("seg/seg_312310", func_00411F18);
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
INCLUDE_ASM("seg/seg_312310", func_00411F70);
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

INCLUDE_ASM("seg/seg_312310", func_00411FD8);

//100%
INCLUDE_ASM("seg/seg_312310", func_00412280);
#ifdef SKIP_ASM
struct S412280 { unsigned cls; int sign; int exp; int pad; unsigned long frac; long pad2; };
extern void unp_80(long *, struct S412280 *) __asm__("func_00411C38");
extern void pk_80(struct S412280 *) __asm__("func_00411B08");
extern struct S412280 D_0052ADC0;
void func_00412280(long x, long y) {
    struct S412280 a;
    struct S412280 b;
    struct S412280 *r;
    struct S412280 *p;
    unsigned long n, d, q, bit;
    unp_80(&x, &a);
    unp_80(&y, &b);
    p = &a;
    if (a.cls < 2) {
        r = &a;
    } else if (b.cls < 2) {
        r = &b;
    } else {
        a.sign ^= b.sign;
        if ((a.cls ^ 4) == 0 || (a.cls ^ 2) == 0) {
            r = &a;
            if (a.cls == b.cls)
                r = &D_0052ADC0;
        } else if ((b.cls ^ 4) == 0) {
            a.frac = 0;
            a.exp = 0;
            r = &a;
        } else if ((b.cls ^ 2) == 0) {
            a.cls = 4;
            r = &a;
        } else {
            a.exp = a.exp - b.exp;
            n = a.frac;
            d = b.frac;
            if (n < d) {
                a.exp--;
                n <<= 1;
            }
            q = 0;
            for (bit = 0x1000000000000000UL; bit != 0; bit >>= 1) {
                if (n >= d) {
                    q |= bit;
                    n -= d;
                }
                n <<= 1;
            }
            if ((q & 0xFF) == 0x80) {
                if (q & 0x100)
                    q += 0x80;
                else if (n != 0)
                    q += 0x80;
            }
            p->frac = q;
            r = p;
        }
    }
    pk_80(r);
}
#endif

INCLUDE_ASM("seg/seg_312310", func_004123E8);

//100%
INCLUDE_ASM("seg/seg_312310", func_00412500);
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

//100%
INCLUDE_ASM("seg/seg_312310", func_00412550);
#ifdef SKIP_ASM
struct S412550 { unsigned cls; int sign; int exp; int pad; unsigned long frac; };
extern void pk_412550(struct S412550 *) __asm__("func_00411B08");
double func_00412550(int x) {
    struct S412550 s;
    s.cls = 3;
    s.sign = (unsigned)x >> 31;
    if (x == 0) {
        s.cls = 2;
    } else {
        s.exp = 60;
        if (s.sign) {
            if (x == (-2147483647 - 1))
                return -2147483648.0;
            s.frac = -x;
        } else {
            s.frac = x;
        }
        while (s.frac <= (~0UL >> 4)) {
            s.frac <<= 1;
            s.exp--;
        }
    }
    pk_412550(&s);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00412608);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
struct S412608 { unsigned cls; int sign; int exp; int pad; unsigned long frac; };
int func_00412608(long a) {
    struct S412608 s;
    int r;
    func_00411C38(&a, (int *)&s);
    if ((s.cls ^ 2) == 0)
        return 0;
    if (s.cls < 2)
        return 0;
    if ((s.cls ^ 4) == 0)
        goto sat;
    if (s.exp < 0)
        return 0;
    if (s.exp >= 31) {
sat:
        return s.sign ? 0x80000000 : 0x7FFFFFFF;
    }
    r = (int)(s.frac >> (60 - s.exp));
    return s.sign ? -r : r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_004126A0);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
struct S4126A0 { unsigned cls; int sign; int exp; int pad; unsigned long frac; };
unsigned func_004126A0(long a) {
    struct S4126A0 s;
    func_00411C38(&a, (int *)&s);
    if ((s.cls ^ 2) == 0)
        return 0;
    if (s.cls < 2)
        return 0;
    if (s.sign != 0)
        return 0;
    if ((s.cls ^ 4) == 0)
        goto sat;
    if (s.exp < 0)
        return 0;
    if (s.exp >= 32) {
sat:
        return 0xFFFFFFFF;
    }
    if (s.exp >= 61)
        return s.frac << (s.exp - 60);
    else
        return s.frac >> (60 - s.exp);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00412740);
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
INCLUDE_ASM("seg/seg_312310", func_00412778);
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

INCLUDE_ASM("seg/seg_312310", func_004127A8);
