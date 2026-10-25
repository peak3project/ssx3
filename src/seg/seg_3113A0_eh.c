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

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410570);
#ifdef SKIP_ASM
extern int (*D_00453444[])(void);
extern void func_004103B0(void);
struct N570 { int *next; int cleanup; void *jb[3]; char pad[0x62C]; };
void sjthrow_410570(void) __asm__("func_00410570");
void sjthrow_410570(void) {
    struct N570 node;
    int *eh;
    int **pchain;
    int *q;
    int **pcl;
    struct N570 *h;
    eh = (int *)D_00453444[0]();
    pchain = (int **)&eh[1];
    q = (int *)eh[1];
    pcl = (int **)&q[1];
    if (q[1] != 0) {
        node.next = q;
        node.cleanup = 0;
        h = &node;
        if (__builtin_setjmp(node.jb) == 0) {
            *pchain = (int *)h;
                        {
                int *n;
                while (*pcl != 0) {
                    n = *pcl;
                    *pcl = (int *)n[0];
                    ((void (*)(int, int))n[1])(n[2], 2);
                }
            }
            *pchain = h->next;
        } else {
            func_004103B0();
        }
    }
    if (eh[2] == 0 || ((int *)*pchain)[0] == 0)
        func_004103B0();
    {
        int *r = *pchain;
        *pchain = (int *)r[0];
        __builtin_longjmp((void **)&r[2], 1);
    }
}
__asm__(".globl D_00410628\n\t.type D_00410628,@function\n\tD_00410628 = func_00410570 + 0xB8\n");
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_004106E8);
#ifdef SKIP_ASM
extern int (*D_00453444[])(void);
extern int func_00410570(void) __attribute__((noreturn));
struct N6E8 { int *next; int cleanup; void *jb[3]; char pad[0x62C]; };
int func_004106E8(void) {
    struct N6E8 node;
    int *eh;
    int *q;
    int **pchain;
    int **pcl;
    struct N6E8 *h;
    eh = (int *)D_00453444[0]();
    pchain = (int **)&eh[1];
    q = (int *)eh[1];
    pcl = (int **)&q[1];
    if (q[1] != 0) {
        node.next = q;
        node.cleanup = 0;
        h = &node;
        __builtin_setjmp(node.jb);
        *pchain = (int *)h;
                {
            int *n;
            while (*pcl != 0) {
                n = *pcl;
                *pcl = (int *)n[0];
                ((void (*)(int, int))n[1])(n[2], 2);
            }
        }
        *pchain = h->next;
    }
    *pchain = (int *)(*pchain)[0];
    return func_00410570();
}
__asm__(".globl D_00410790\n\t.type D_00410790,@function\n\tD_00410790 = func_004106E8 + 0xA8\n");
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410800);
#ifdef SKIP_ASM
int func_00410800(int a) {
    int *o = *(int **)func_00410490();
    int (*fn)(int *, int, int) = (int (*)(int *, int, int))o[0];
    if (fn == 0)
        return 0;
    return fn(o, a, 0) != 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410C18);
#ifdef SKIP_ASM
struct S410C18 { char b[0x2F0]; } __attribute__((aligned(8)));
struct F410C18 { int f0; unsigned *p; char pad0[0x292]; unsigned short idx; signed char kind[0x50]; } __attribute__((aligned(8)));
extern void func_004103B0(void);
extern void func_00410C10(void);
extern struct F410C18 *f_b80_410C18(int, struct F410C18 *, struct S410C18 *) __asm__("func_00410B80");
extern long long *f_a78_410C18(int, struct F410C18 *, struct S410C18 *) __asm__("func_00410A78");
extern void f_b00_410C18(int, struct F410C18 *, struct S410C18 *) __asm__("func_00410B00");
extern int f_930_410C18(int, int, int, int, int *) __asm__("func_00410930");
extern int f_858_410C18(int, int) __asm__("func_00410858");
static inline void nop_410C18(void) {}
int unwind_410C18(int *info, int pc, struct S410C18 *buf, struct F410C18 **pout) __asm__("func_00410C18");
int unwind_410C18(int *info, int pc, struct S410C18 *buf, struct F410C18 **pout) {
    struct S410C18 first;
    struct S410C18 save;
    struct F410C18 *cur;
    struct F410C18 *t;
    struct S410C18 *prev;
    int flag;
    int pc0, sres, spc, have2, have;
    int result = 0;
    int regs = info[2];
    int fl3 = info[3] != 0;
    have2 = 0;
    have = 0;
    pc0 = pc;
    flag = 0;
    cur = *pout;
    prev = &first;
    for (;;) {
        t = cur;
        cur = f_b80_410C18(pc, t, prev);
        prev = (struct S410C18 *)t;
        if (cur == 0)
            break;
        {
            int m;
            if (cur->p == 0)
                m = 0;
            else
                m = *cur->p == 0xFFFFFFFE;
            if (fl3) {
                fl3 = 0;
                result = f_930_410C18(info[3], (int)cur->p, regs, 1, &flag);
                info[3] = 0;
            } else if (m) {
                result = f_930_410C18(pc, (int)cur->p, regs, 0, &flag);
            } else {
                result = f_858_410C18(pc, (int)cur->p);
            }
        }
        if (result != 0) {
            if (flag != 0) {
                if (have == 0) {
                    save = *(struct S410C18 *)cur;
                    spc = pc;
                    sres = result;
                    have = 1;
                    have2 = 1;
                }
            } else {
                have2 = 0;
                break;
            }
        }
        {
            long long v = *f_a78_410C18(cur->idx, cur, (struct S410C18 *)t);
            pc = (int)v - 1;
        }
    }
    if (have) {
        cur = (struct F410C18 *)&save;
        result = sres;
        pc = spc;
        if (have2)
            func_00410C10();
    }
    if (result == 0)
        func_004103B0();
    *info = result;
    {
        int end = pc;
        if (end == pc0) {
            cur = (struct F410C18 *)buf;
        } else {
            int i;
            int stop = end;
            pc = pc0;
            *cur = *(struct F410C18 *)buf;
            while (pc != stop) {
                t = cur;
                cur = f_b80_410C18(pc, t, (struct S410C18 *)prev);
                prev = (struct S410C18 *)t;
                for (i = 0; i < 0x4F; i++) {
                    if (i != cur->idx && cur->kind[i] != 0)
                        f_b00_410C18(i, cur, buf);
                }
                {
                    long long v = *f_a78_410C18(cur->idx, cur, (struct S410C18 *)t);
                    pc = (int)v - 1;
                }
            }
            if (cur->kind[cur->idx] == 2)
                nop_410C18();
        }
        *pout = cur;
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("seg/seg_3113A0_eh", func_00410F48);
#ifdef SKIP_ASM
struct S410F48 { char b[0x2F0]; } __attribute__((aligned(8)));
extern void func_004103B0(void);
extern struct S410F48 *get_410F48(void *, void *) __asm__("func_00414818");
extern void *func_00410C18(void *, int, void *, void *);
void func_00410F48(void) {
    struct S410F48 ctx0;
    struct S410F48 buf;
    struct S410F48 *a;
    int *info;
    struct S410F48 *pb;
    void **pa;
    void *pc;
    __builtin_unwind_init();
    info = (int *)D_00453444[0]();
    pb = &buf;
    a = &ctx0;
    if (info[2] == 0) {
        func_004103B0();
        pa = (void **)&a;
    } else {
        pa = (void **)&a;
    }
lbl:
    pc = (void *)&&lbl;
    a = get_410F48(pc, (void *)a);
    if (a == 0)
        func_004103B0();
    *(void **)a = __builtin_dwarf_cfa();
    buf = *a;
    {
        void *h = func_00410C18(info, (int)__builtin_return_address(0) - 1, pb, pa);
        __builtin_eh_return(info, *(int *)a - *(int *)pb, h);
    }
}
__asm__(".globl D_004110B8\n\t.type D_004110B8,@function\n\tD_004110B8 = func_00410F48 + 0x170\n");
#endif

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
