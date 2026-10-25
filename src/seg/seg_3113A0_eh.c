#include "common.h"

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_004103A0);
#ifdef SKIP_ASM
extern int func_00418790(void) __attribute__((noreturn));
int func_004103A0(void) {
    return func_00418790();
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_004103B0);
#ifdef SKIP_ASM
extern void (*D_00453440[])(void);
void func_004103B0(void) {
    D_00453440[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_004103D8);
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
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410410);
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
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410468);
#ifdef SKIP_ASM
extern int (*D_00453444[])(void);
void func_00410468(void) {
    D_00453444[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410490);
#ifdef SKIP_ASM
int *func_00410490(void) {
    return (int *)D_00453444[0]() + 2;
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_004104B8);
#ifdef SKIP_ASM
extern int func_004104E0(void);
void func_004104B8(void) {
    int (*fp)(void) = func_004104E0;
    D_00453444[0] = fp;
    fp();
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_004104E0);
#ifdef SKIP_ASM
extern int D_0052ADA0[];
extern char D_0052ADB8[];
extern int D_0052ADB0[];
extern void *memset_4104E0(void *, int, int) __asm__("func_00416210");
int func_004104E0(void) {
    if (D_0052ADB0[0] == 0) {
        D_0052ADB0[0] = 1;
        memset_4104E0(D_0052ADA0, 0, 16);
        *(char **)(D_0052ADA0 + 1) = D_0052ADB8;
    }
    return (int)D_0052ADA0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410548);
#ifdef SKIP_ASM
int *func_00410548(void) {
    return (int *)D_00453444[0]() + 1;
}
#endif

INCLUDE_ASM("seg/seg_3113A0_eh", func_00410570);

INCLUDE_ASM("seg/seg_3113A0_eh", func_004106E8);

INCLUDE_ASM("seg/seg_3113A0_eh", func_00410800);

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410848);
#ifdef SKIP_ASM
int func_00410848(short *p) {
    return p[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410850);
#ifdef SKIP_ASM
int func_00410850(short *p) {
    return p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410858);
#ifdef SKIP_ASM
struct E410858 { unsigned start; unsigned end; int data; };
int func_00410858(unsigned pc, struct E410858 *tab) {
    int best, i;
    if (tab) {
        best = -1;
        for (i = 0; tab[i].start != 0xFFFFFFFF; i++) {
            if (pc >= tab[i].start && pc < tab[i].end) {
                if (best == -1 || (tab[best].end >= tab[i].end && tab[best].start <= tab[i].start))
                    best = i;
            } else if (best >= 0 && pc < tab[i].start)
                break;
        }
        if (best != -1)
            return tab[best].data;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410930);
#ifdef SKIP_ASM
struct E410930 { unsigned start; unsigned end; int val; int cb; };
struct C410930 { int (*match)(struct C410930 *, int, int); };
int func_00410930(unsigned pc, int obj, struct C410930 *ctx, int flag, int *out) {
    int r = 0;
    *out = 1;
    if (obj != 0) {
        int idx = 0;
        struct E410930 *tbl = (struct E410930 *)(obj + 8);
        if (flag) {
            idx = ((int)pc - (int)tbl) >> 4;
            pc = ((unsigned *)pc)[1] - 1;
            if (tbl[idx].start != 0xFFFFFFFF)
                idx++;
        } else {
            pc = pc - 1;
        }
        for (; tbl[idx].start != 0xFFFFFFFF; idx++) {
            if (pc >= tbl[idx].start && pc < tbl[idx].end) {
                if (tbl[idx].cb) {
                    if (ctx->match) {
                        if (ctx->match(ctx, tbl[idx].cb, obj)) {
                            if (r == 0)
                                r = tbl[idx].val;
                            *out = 0;
                            break;
                        }
                    }
                } else if (r == 0) {
                    r = tbl[idx].val;
                }
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410A78);
#ifdef SKIP_ASM
struct S410A78 { int base; char pad[0x14]; long e[0x50]; unsigned short n; short pad2; signed char kind[1]; };
extern int nr_410A78(void) __asm__("func_00418790");
int func_00410A78(int idx, struct S410A78 *s, int z) {
    if (s->kind[idx] == 2) {
        do {
            idx = (int)s->e[idx];
        } while (s->kind[idx] == 2);
    }
    if (s->kind[idx] == 1)
        return s->base + (int)s->e[idx];
    return nr_410A78();
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410B00);
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

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410B80);
#ifdef SKIP_ASM
extern int *func_00414818();
extern long long *func_00410B80_idx() __asm__("func_00410A78");
int *func_00410B80(int a, int *b, int c) {
    int *q = func_00414818(a, c);
    unsigned short i;
    if (q == 0)
        return 0;
    i = *(unsigned short *)((char *)q + 0x298);
    if (*((char *)b + i + 0x29C) != 0)
        {
            long long v = *func_00410B80_idx(i, b, 0);
            q[0] = (int)v;
        }
    else
        q[0] = b[0];
    q[0] = q[0] + q[2];
    return q;
}
#endif

void func_00410C10(void) {
}

INCLUDE_ASM("seg/seg_3113A0_eh", func_00410C18);

INCLUDE_ASM("seg/seg_3113A0_eh", func_00410F48);

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00411128);
#ifdef SKIP_ASM
struct S411128 { char b[0x2F0]; } __attribute__((aligned(8)));
extern void func_004103B0(void);
extern struct S411128 *get_411128(void *, void *) __asm__("func_00414818");
extern void *func_00410C18(void *, int, void *, void *);
void func_00411128(int val) {
    struct S411128 ctx0;
    struct S411128 buf;
    struct S411128 *a;
    int *info;
    struct S411128 *pb;
    void **pa;
    void *pc;
    __builtin_unwind_init();
    info = (int *)D_00453444[0]();
    pb = &buf;
    a = &ctx0;
    if (info[2] == 0)
        func_004103B0();
    info[3] = val;
    pa = (void **)&a;
lbl:
    __asm__ volatile(".globl D_004111D4\n\t.type D_004111D4,@function\nD_004111D4:");
    pc = (void *)&&lbl;
    a = get_411128(pc, (void *)a);
    if (a == 0)
        func_004103B0();
    *(void **)a = __builtin_dwarf_cfa();
    buf = *a;
    {
        void *h = func_00410C18(info, (int)__builtin_return_address(0) - 1, pb, pa);
        __builtin_eh_return(info, *(int *)a - *(int *)pb, h);
    }
}
__asm__(".globl D_004112A0\n\t.type D_004112A0,@function\n\tD_004112A0 = func_00411128 + 0x178\n");
#endif
