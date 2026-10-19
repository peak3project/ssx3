#include "common.h"

//100%
INCLUDE_ASM("seg/seg_325220", func_00424220);
#ifdef SKIP_ASM
extern int D_00455168;
void func_00424220(void) {
    D_00455168 = 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424230);

INCLUDE_ASM("seg/seg_325220", func_004242C0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424368);
#ifdef SKIP_ASM
extern int D_00455168;
extern int func_00425260(void);
extern int func_00425040(int, int);
int func_00424368(int a0, int a1, int a2) {
    if (a0 == 1 || a0 == 2) {
        if (D_00455168 == 0) {
            if (func_00425260() == 0) {
                return -1;
            }
            D_00455168 = 1;
        }
        return func_00425040(a1, a2);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004243E8);
#ifdef SKIP_ASM
extern int D_00455168;
extern int func_00425260(void);
extern int func_00425190(int, int);
int func_004243E8(int a0, int a1, int a2) {
    if (a0 == 0) {
        if (D_00455168 == 0) {
            if (func_00425260() == 0) {
                return -1;
            }
            D_00455168 = 1;
        }
        return func_00425190(a1, a2);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424460);
#ifdef SKIP_ASM
extern int *func_00415FB8(void);
int func_00424460(void) {
    *func_00415FB8() = 5;
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424488);
#ifdef SKIP_ASM
int func_00424488(void) {
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424490);
#ifdef SKIP_ASM
int func_00424490(void) {
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424498);
#ifdef SKIP_ASM
int func_00424498(void) {
    return -1;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004244A0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424550);
#ifdef SKIP_ASM
int func_00424550(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424558);
#ifdef SKIP_ASM
long func_00424558(int a0, char *a1) {
    *(int *)(a1 + 4) = 0x2000;
    *(long *)(a1 + 0x48) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424570);
#ifdef SKIP_ASM
int func_00424570(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424578);
#ifdef SKIP_ASM
extern void func_0042C6E8(int a0);
int func_00424578(int a0, int a1) {
    if (a0 == 1) {
        func_0042C6E8(a1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004245A0);
#ifdef SKIP_ASM
extern int *func_00415FB8(void);
int func_004245A0(void) {
    *func_00415FB8() = 5;
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004245C8);
#ifdef SKIP_ASM
extern int *func_00415FB8(void);
int func_004245C8(void) {
    *func_00415FB8() = 5;
    return -1;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004245F0);

INCLUDE_ASM("seg/seg_325220", func_00424698);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424718);
#ifdef SKIP_ASM
extern void func_004245F0(unsigned, unsigned);
void func_00424718(unsigned a, unsigned b) {
    func_004245F0(a & ~63, b & ~63);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424730);

INCLUDE_ASM("seg/seg_325220", func_004247D8);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424858);
#ifdef SKIP_ASM
extern void func_00424730(unsigned, unsigned);
void func_00424858(unsigned a, unsigned b) {
    func_00424730(a & ~63, b & ~63);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424870);

INCLUDE_ASM("seg/seg_325220", func_00424880);

INCLUDE_ASM("seg/seg_325220", func_004248E8);

INCLUDE_ASM("seg/seg_325220", func_00424950);

INCLUDE_ASM("seg/seg_325220", func_004249B8);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424A20);
#ifdef SKIP_ASM
extern void func_00423B40(void);
void func_00424A20(void) {
    func_00423B40();
    __asm__ volatile("sync");
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424A40);
#ifdef SKIP_ASM
extern void func_00423B50(void);
void func_00424A40(void) {
    func_00423B50();
    __asm__ volatile("sync");
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424A60);
#ifdef SKIP_ASM
extern void func_00423B60(void);
void func_00424A60(void) {
    func_00423B60();
    __asm__ volatile("sync");
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424A80);
#ifdef SKIP_ASM
extern void func_00423B70(void);
void func_00424A80(void) {
    func_00423B70();
    __asm__ volatile("sync");
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424AA0);
#ifdef SKIP_ASM
extern int D_0052B3A0;
extern char D_0049AAE0[];
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
extern void func_00423C50(int);
extern void func_00423CD0(int);
extern void func_00423D10(int);
void func_00424AA0(unsigned *p) {
    unsigned i;
    unsigned j;
    unsigned char *t = (unsigned char *)p + 8;
    unsigned char *v = (unsigned char *)p + 9;
    for (;;) {
        func_00423DE0_i(D_0052B3A0);
        i = *p & 0x1FF;
        j = i << 1;
        *p = i + 1;
        switch (*(t + j)) {
        case 0:
            func_00423CD0(*(v + j));
            break;
        case 1:
            func_00423C50(*(v + j));
            break;
        case 2:
            func_00423D10(*(v + j));
            break;
        default:
            func_00425C28((int)D_0049AAE0);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424B78);
#ifdef SKIP_ASM
extern int D_00455170;
extern int D_0052B3A0;
extern char D_0052AFA0[];
extern char D_004A30F0[];
extern int D_0052B3A8_a[] __asm__("D_0052B3A8");
extern int func_00423DA0(int *p);
extern int func_00423BA0(int *);
extern void func_00423BC0(int, int *);
extern int func_00423C90(void);
extern void func_00423C30(int, int);
extern void func_00423DB0(int);
extern void func_00424AA0(unsigned *);
int func_00424B78_i(void) __asm__("func_00424B78");
int func_00424B78_i(void) {
    int cfg[12];
    int buf[8];
    if (D_00455170 > 0) {
        return -1;
    }
    buf[2] = 0;
    buf[1] = 0xFF;
    D_0052B3A0 = func_00423DA0(buf);
    if (D_0052B3A0 < 0) {
        return -1;
    }
    cfg[1] = (int)func_00424AA0;
    cfg[2] = (int)D_0052AFA0;
    cfg[3] = 0x400;
    cfg[4] = (int)D_004A30F0;
    cfg[5] = 0;
    D_00455170 = func_00423BA0(cfg);
    if (D_00455170 < 0) {
        func_00423DB0(D_0052B3A0);
        return -1;
    }
    D_0052B3A8_a[0] = 0;
    D_0052B3A8_a[1] = 0;
    func_00423BC0(D_00455170, D_0052B3A8_a);
    func_00423C30(func_00423C90(), 1);
    return D_00455170;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424C50);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424CE8);
#ifdef SKIP_ASM
struct S_0052B3A8 {
    int pad0;
    unsigned idx;
    struct { char a; char b; } e[512];
};
extern int D_00455170;
extern int D_0052B3A0;
extern struct S_0052B3A8 D_0052B3A8;
extern void func_00423DD0(int);
int func_00424CE8(unsigned a0) {
    unsigned i;
    if (a0 >= 0x80 || D_00455170 == 0) {
        return -1;
    }
    i = D_0052B3A8.idx & 0x1FF;
    D_0052B3A8.idx = i + 1;
    D_0052B3A8.e[i].a = 1;
    D_0052B3A8.e[i].b = a0;
    func_00423DD0(D_0052B3A0);
    return a0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424D68);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424E00);
#ifdef SKIP_ASM
extern int D_0052B7C0[];
int *func_00424E00(int a0) {
    D_0052B7C0[0] = a0;
    D_0052B7C0[1] = 0;
    D_0052B7C0[3] = (int)&D_0052B7C0[4];
    D_0052B7C0[2] = (int)&D_0052B7C0[4];
    return D_0052B7C0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424E28);
#ifdef SKIP_ASM
struct Ring4E28 { int size; int count; char *rd; char *wr; char data[1]; };
void func_00424E28(struct Ring4E28 *r) {
    r->count++;
    r->wr++;
    if (r->wr == (char *)r + (r->size + 16)) {
        r->wr = r->data;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424E68);
#ifdef SKIP_ASM
struct Ring4E68 { int size; int count; char *rd; char *wr; char data[1]; };
void func_00424E68(struct Ring4E68 *r) {
    r->count--;
    r->rd++;
    if (r->rd == (char *)r + (r->size + 16)) {
        r->rd = r->data;
    }
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424EA8);

INCLUDE_ASM("seg/seg_325220", func_00425040);

//100%
INCLUDE_ASM("seg/seg_325220", func_00425190);
#ifdef SKIP_ASM
struct S8D0 { int f0; int f4; int f8; int fC; int f10; int f14; struct Ring4E68 *f18; };
extern struct S8D0 D_0052B8D0;
extern struct Ring4E68 *D_0052B8E8;
int func_00425190(int a0, int n) {
    char *buf = (char *)a0;
    int i;
    int j;
    char *p;
    for (i = 0; i < n; i = j) {
        p = buf + i;
        j = i + 1;
        while (*(volatile int *)&D_0052B8E8->count == 0) {
        }
        *p = *D_0052B8D0.f18->rd;
        func_00424E68(D_0052B8D0.f18);
        if (*p == '\n' || *p == '\r') {
            return j;
        }
    }
    return i;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00425260);

INCLUDE_ASM("seg/seg_325220", func_00425320);

//100%
INCLUDE_ASM("seg/seg_325220", func_00425358);
#ifdef SKIP_ASM
extern int D_00455174;
extern char D_0052BB80[];
extern void func_0042CA58_v(char *) __asm__("func_0042CA58");
void func_00425358(int c) {
    int idx;
    if (D_00455174 >= 0x7E) {
        D_00455174 = 0;
        D_0052BB80[0x7F] = 0;
        func_0042CA58_v(D_0052BB80);
    }
    idx = D_00455174;
    if (c == 10) {
        D_00455174 = 0;
        D_0052BB80[idx] = c;
        D_0052BB80[idx + 1] = 0;
        func_0042CA58_v(D_0052BB80);
    } else {
        D_00455174 = idx + 1;
        D_0052BB80[idx] = c;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425408);
#ifdef SKIP_ASM
extern void func_00425320(int c);
void func_00425408(int c) {
    if (c == 10) {
        func_00425320(13);
        func_00425320(10);
    } else {
        func_00425320(c);
    }
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00425440);

INCLUDE_ASM("seg/seg_325220", func_004254D0);

INCLUDE_ASM("seg/seg_325220", func_00425638);

//100%
INCLUDE_ASM("seg/seg_325220", func_00425C28);
#ifdef SKIP_ASM
// not matched: varargs wrapper (a0 passes through, $5 = &spill at sp+0x58 passed as ap). hand-rolled va_start gives right sd $5..$11
// but also emits swc1 $f12..$f18 saves (target has none) -> size mismatch (18 vs 14 insns).
extern void func_00425638(int a0, char *ap);
void func_00425C28(int a0, ...) {
    char *ap;
    ap = (char *)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_00425638(a0, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425C60);
#ifdef SKIP_ASM
extern void (*D_00455178)(int);
extern void func_00425358(int c);
extern void func_00425638(int a0, char *ap);
void func_00425C60(int a0, ...) {
    char *ap;
    void (*old)(int) = D_00455178;
    D_00455178 = func_00425358;
    ap = (char *)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_00425638(a0, ap);
    D_00455178 = old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425CC0);
#ifdef SKIP_ASM
void func_00425CC0(int *a0, int *a1) {
    ((int *)a1[7])[a0[4]] = a0[5];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425CE0);
#ifdef SKIP_ASM
void func_00425CE0(int *a0, int *a1) {
    a1[2] = a0[4];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425CF0);
#ifdef SKIP_ASM
extern int D_0052BE00[];
int func_00425CF0(int a0) {
    return D_0052BE00[a0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425D08);
#ifdef SKIP_ASM
extern int D_0052BE00[];
int func_00425D08(int a0, int a1) {
    D_0052BE00[a0] = a1;
    return a1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425D28);
#ifdef SKIP_ASM
extern int D_0052BCD8[];
int *func_00425D28(void) {
    return D_0052BCD8;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00425D38);

//100%
INCLUDE_ASM("seg/seg_325220", func_00425FB8);
#ifdef SKIP_ASM
extern int func_00424950(int a0);
extern int func_00423AD0(int a0, int a1);
extern int D_0045517C;
extern int D_0052BCD4;
void func_00425FB8(void) {
    func_00424950(5);
    func_00423AD0(5, D_0052BCD4);
    D_0045517C = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425FF0);
#ifdef SKIP_ASM
extern int D_0052BCD8[];
int func_00425FF0(int a0, int a1) {
    int old = D_0052BCD8[5];
    D_0052BCD8[5] = a0;
    D_0052BCD8[6] = a1;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426008);
#ifdef SKIP_ASM
extern int D_0052BCD8[];
int func_00426008(int a0, int a1) {
    int old = D_0052BCD8[3];
    D_0052BCD8[3] = a0;
    D_0052BCD8[4] = a1;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426020);
#ifdef SKIP_ASM
extern int *D_0052BCE4;
extern int *D_0052BCEC;
void func_00426020(int a0, int a1, int a2) {
    int off = a0 << 3;
    if (a0 < 0) {
        a0 = (int)D_0052BCE4;
    } else {
        a0 = (int)D_0052BCEC;
    }
    off += a0;
    ((int *)off)[0] = a1;
    ((int *)off)[1] = a2;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426050);
#ifdef SKIP_ASM
extern int *D_0052BCE4;
extern int *D_0052BCEC;
void func_00426050(int a0) {
    int off = a0 << 3;
    if (a0 < 0) {
        a0 = (int)D_0052BCE4;
    } else {
        a0 = (int)D_0052BCEC;
    }
    off += a0;
    *(int *)off = 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426078);

//100%
INCLUDE_ASM("seg/seg_325220", func_004261B0);
#ifdef SKIP_ASM
extern int func_00426078(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
int func_004261B0(int a0, int a1, int a2, int a3, int a4, int a5) {
    return func_00426078(a0, 0, a1, a2, a3, a4, a5);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004261F0);
#ifdef SKIP_ASM
extern int func_00426078(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
int func_004261F0(int a0, int a1, int a2, int a3, int a4, int a5) {
    return func_00426078(a0, 1, a1, a2, a3, a4, a5);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426230);

INCLUDE_ASM("seg/seg_325220", func_00426358);

INCLUDE_ASM("seg/seg_325220", func_00426404);

INCLUDE_ASM("seg/seg_325220", func_00426408);

//100%
INCLUDE_ASM("seg/seg_325220", func_004265A8);
#ifdef SKIP_ASM
extern void func_00425FB8(void);
extern int D_00455180;
void func_004265A8(void) {
    func_00425FB8();
    D_00455180 = 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004265D0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00426678);
#ifdef SKIP_ASM
void func_00426678(unsigned int *a0) {
    a0[6] = 0;
    a0[4] &= 0xFFFFFFFE;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426698);

//100%
INCLUDE_ASM("seg/seg_325220", func_004266C8);
#ifdef SKIP_ASM
extern int func_00426698(int *a0);
int func_004266C8(int *a0, int a1) {
    if (a1 < 0 || a1 >= a0[8]) {
        return func_00426698(a0);
    }
    return a0[7] + (a1 << 6);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426708);

//100%
INCLUDE_ASM("seg/seg_325220", func_004267C0);
#ifdef SKIP_ASM
extern int func_004261F0(int a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00423B80(int a0, int (*a1)(int, int, int *), int *a2);
int func_004267C0(int a0, int a1, int *p) {
    if (func_004261F0(0x80000008, (int)p, 0x40, p[9], p[10], p[11]) == 0) {
        func_00423B80(10, func_004267C0, p);
    }
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426820);

INCLUDE_ASM("seg/seg_325220", func_004268F0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00426A48);
#ifdef SKIP_ASM
struct N426A48 { int key; char pad[0x34]; struct N426A48 *next; };
struct O426A48 { char pad[8]; struct N426A48 *head; char pad2[8]; struct O426A48 *next; };
struct P426A48 { char pad[0x28]; struct O426A48 *list; };
struct N426A48 *func_00426A48(int a0, struct P426A48 *a1) {
    struct O426A48 *o;
    struct N426A48 *n;
    for (o = a1->list; o != 0; o = o->next) {
        for (n = o->head; n != 0; n = n->next) {
            if (n->key == a0) {
                return n;
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426A98);
#ifdef SKIP_ASM
extern int func_00426698(int *a0);
extern int *func_00426A48_p(int, int *) __asm__("func_00426A48");
extern void func_004261F0_v(int, int *, int, int, int, int) __asm__("func_004261F0");
void func_00426A98(int *a0, int *a1) {
    int *q = (int *)func_00426698(a1);
    int *n;
    int t1 = a0[5];
    int t2 = a0[7];
    q[7] = t2;
    q[5] = t1;
    q[8] = 0x80000009;
    n = func_00426A48_p(a0[8], a1);
    if (n == 0) {
        q[9] = 0;
        q[10] = 0;
        q[11] = 0;
    } else {
        q[9] = (int)n;
        q[10] = n[2];
        q[11] = n[5];
    }
    func_004261F0_v(0x80000008, q, 0x40, 0, 0, 0);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426B48);

//100%
INCLUDE_ASM("seg/seg_325220", func_00426C88);
#ifdef SKIP_ASM
struct B26C88 {
    int f0;
    int f4;
    int pad8;
    int head;
    int tail;
};
struct E26C88 {
    int pad0[3];
    int fC;
    int pad10[3];
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int pad38;
    int next;
    struct B26C88 *owner;
};
struct A26C88 {
    int pad0[4];
    int f10;
    int f14;
    int pad18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    struct E26C88 *e;
};
extern void func_00424C50(int);
void func_00426C88(struct A26C88 *a) {
    struct E26C88 *e = a->e;
    struct B26C88 *b = e->owner;
    if (b->head == 0) {
        b->head = (int)e;
    } else {
        ((struct E26C88 *)b->tail)->next = (int)e;
    }
    b->tail = (int)e;
    {
        int t1 = a->f14;
        int t2 = a->f1C;
        e->f20 = t1;
        e->f1C = t2;
    }
    e->f24 = a->f20;
    e->fC = a->f24;
    e->f28 = a->f28;
    e->f2C = a->f2C;
    e->f30 = a->f30;
    e->f34 = a->f10;
    if (b->f0 >= 0 && b->f4 == 0) {
        func_00424C50(b->f0);
    }
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426D18);

//100%
INCLUDE_ASM("seg/seg_325220", func_00426F08);
#ifdef SKIP_ASM
int func_00426F08(int *a0) {
    int *p = (int *)a0[0];
    if (p == 0 || a0[1] != p[6] || !(p[4] & 1)) {
        return 0;
    }
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426F48);

INCLUDE_ASM("seg/seg_325220", func_00426FE0);

INCLUDE_ASM("seg/seg_325220", func_004270B0);

INCLUDE_ASM("seg/seg_325220", func_00427148);

//100%
INCLUDE_ASM("seg/seg_325220", func_004271D8);
#ifdef SKIP_ASM
struct N4271D8 { char pad[0x3C]; int next; };
struct S4271D8 { char pad[4]; int f4; char pad2[4]; struct N4271D8 *head; };
extern void func_0042C078(void);
extern void func_0042C0C0(void);
int func_004271D8(int arg) {
    struct S4271D8 *a0 = (struct S4271D8 *)arg;
    struct N4271D8 *n;
    func_0042C078();
    n = a0->head;
    if (n == 0) {
        a0->f4 = 0;
    } else {
        struct N4271D8 *t = (struct N4271D8 *)n->next;
        a0->f4 = 1;
        a0->head = t;
    }
    func_0042C0C0();
    return (int)n;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00427230);

//100%
INCLUDE_ASM("seg/seg_325220", func_004273F8);
#ifdef SKIP_ASM
extern int func_004271D8(int a0);
extern void func_00427230(int a0);
extern void func_00423CC0(void);
int func_004273F8(int a0) {
    int r;
    while (1) {
        while ((r = func_004271D8(a0)) != 0) {
            func_00427230(r);
        }
        func_00423CC0();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00427438);
#ifdef SKIP_ASM
extern int D_00455218;
extern int D_0045521C;
extern int func_00423DA0(int *p);
void func_00427438(void) {
    int buf[8];
    if (D_00455218 == -1) {
        buf[5] = 0;
        buf[2] = 1;
        buf[1] = 1;
        D_00455218 = func_00423DA0(buf);
        D_0045521C = func_00423DA0(buf);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00427498);
#ifdef SKIP_ASM
struct E427498 { int f0; int f4; int f8; int fC; };
extern int D_00455218;
extern char D_0052EC00[];
extern void func_00427438(void);
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
extern void func_00423DC0(int);
struct E427498 *func_00427498(void) {
    struct E427498 *p;
    struct E427498 *end;
    func_00427438();
    func_00423DE0_i(D_00455218);
    p = (struct E427498 *)D_0052EC00;
    end = p + 32;
    while (p < end) {
        if (p->f4 == 0) {
            p->f4 = 0x10000000;
            func_00423DC0(D_00455218);
            return p;
        }
        p++;
    }
    func_00423DC0(D_00455218);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00427520);
#ifdef SKIP_ASM
extern int D_00455218;
extern char D_0052EC00[];
extern void func_00427438(void);
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
extern void func_00423DC0(int);
char *func_00427520(unsigned a0) {
    char *p;
    func_00427438();
    func_00423DE0_i(D_00455218);
    if (a0 >= 0x20) {
        func_00423DC0(D_00455218);
        return 0;
    }
    p = D_0052EC00 + a0 * 16;
    func_00423DC0(D_00455218);
    return p;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00427590);

//100%
INCLUDE_ASM("seg/seg_325220", func_00427938);
#ifdef SKIP_ASM
extern int D_00455214;
extern int func_00423DA0(int *p);
void func_00427938(void) {
    int buf[8];
    if (D_00455214 == -1) {
        buf[5] = 0;
        buf[2] = 1;
        buf[1] = 1;
        D_00455214 = func_00423DA0(buf);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00427988);
#ifdef SKIP_ASM
extern void func_00427938(void);
extern void func_00423DE0(int a0);
extern int D_00455214;
int func_00427988(void) {
    func_00427938();
    func_00423DE0(D_00455214);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004279B8);
#ifdef SKIP_ASM
extern int D_00455214;
extern void func_00423DC0(int);
void func_004279B8(void) {
    func_00423DC0(D_00455214);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004279C8);
#ifdef SKIP_ASM
extern int D_0045520C;
extern int D_0052EE80;
extern void func_00427988_a(int) __asm__("func_00427988");
extern void func_00427A90(void);
extern int func_0042C078_i(void) __asm__("func_0042C078");
extern void func_0042C0C0(void);
extern void func_004279B8(void);
int func_004279C8(int a0, int a1) {
    int r;
    int old;
    int *p = &D_0052EE80;
    func_00427988_a(0x1B);
    if (D_0045520C == 0) {
        func_00427A90();
    }
    r = func_0042C078_i();
    old = D_0052EE80;
    p[1] = a1;
    D_0052EE80 = a0;
    if (r != 0) {
        func_0042C0C0();
    }
    func_004279B8();
    return old;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00427A60);

INCLUDE_ASM("seg/seg_325220", func_00427A90);

//100%
INCLUDE_ASM("seg/seg_325220", func_00427C98);
#ifdef SKIP_ASM
extern char D_00455164[];
extern char D_0052EE28[];
extern char *D_00455220;
extern int func_00415FC8(char *, char *, int);
int func_00427C98(void) {
    char *a = D_00455164;
    char *b = D_0052EE28;
    int r = 0;
    if (func_00415FC8(b, a, 4) != 0 &&
        func_00415FC8(b, D_00455220, 4) != 0) {
        r = func_00415FC8(a, D_00455220, 4) != 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00427D28);
#ifdef SKIP_ASM
extern void func_00416210(void *a0, int a1, int a2);
extern int D_0045520C;
extern char D_0052EE28[];
int func_00427D28(void) {
    D_0045520C = 0;
    func_00416210(D_0052EE28, 0, 4);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00427D60);

INCLUDE_ASM("seg/seg_325220", func_00427FE8);

INCLUDE_ASM("seg/seg_325220", func_00428168);

INCLUDE_ASM("seg/seg_325220", func_004283A0);

INCLUDE_ASM("seg/seg_325220", func_00428600);

INCLUDE_ASM("seg/seg_325220", func_004288C0);

INCLUDE_ASM("seg/seg_325220", func_00428C38);

INCLUDE_ASM("seg/seg_325220", func_00428E18);

//100%
INCLUDE_ASM("seg/seg_325220", func_00428FC0);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00428FC0(int a0) {
    return func_00428E18(a0, 6);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00428FE0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00429190);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00429190(int a0) {
    return func_00428E18(a0, 8);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004291B0);

INCLUDE_ASM("seg/seg_325220", func_00429420);

//100%
INCLUDE_ASM("seg/seg_325220", func_00429540);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00429540(int a0) {
    return func_00428E18(a0, 0x10);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00429560);

INCLUDE_ASM("seg/seg_325220", func_00429628);

INCLUDE_ASM("seg/seg_325220", func_00429790);

INCLUDE_ASM("seg/seg_325220", func_004298E8);

INCLUDE_ASM("seg/seg_325220", func_00429A88);

INCLUDE_ASM("seg/seg_325220", func_00429CC8);

//100%
INCLUDE_ASM("seg/seg_325220", func_00429EB8);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00429EB8(int a0) {
    return func_00428E18(a0, 0x12);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00429ED8);

INCLUDE_ASM("seg/seg_325220", func_0042A070);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042A2E0);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_0042A2E0(int a0) {
    return func_00428E18(a0, 0x15);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042A300);

INCLUDE_ASM("seg/seg_325220", func_0042A538);

INCLUDE_ASM("seg/seg_325220", func_0042A770);

INCLUDE_ASM("seg/seg_325220", func_0042A950);

INCLUDE_ASM("seg/seg_325220", func_0042AB18);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042ABA0);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int D_0052EF40;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
int func_0042ABA0(int a0) {
    if (D_00455224 >= 0) {
        D_0052EF40 = a0;
        if (func_00426D18(D_0052EEC0, 1, 0, (int)&D_0052EF40, 4, &D_0052EF00, 4, 0, 0) >= 0) {
            return D_0052EF00;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AC10);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int D_0052EF40;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
int func_0042AC10(int a0, int a1, int a2) {
    int *p;
    if (D_00455224 < 0) {
        return 0;
    }
    p = &D_0052EF40;
    p[0] = a1;
    p[1] = a0;
    p[2] = a2;
    if (func_00426D18(D_0052EEC0, 4, 0, (int)p, 0xC, &D_0052EF00, 4, 0, 0) >= 0) {
        return D_0052EF00;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AC90);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int D_0052EF40;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
int func_0042AC90_impl(int a0) __asm__("func_0042AC90");
int func_0042AC90_impl(int a0) {
    if (D_00455224 < 0) {
        return 0;
    }
    D_0052EF40 = a0;
    if (func_00426D18(D_0052EEC0, 2, 0, (int)&D_0052EF40, 4, &D_0052EF00, 4, 0, 0) < 0) {
        return -1;
    }
    return D_0052EF00;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AD08);
#ifdef SKIP_ASM
extern int func_0042AC90(void);
int func_0042AD08(void) {
    return func_0042AC90();
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042AD28);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AE18);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
unsigned int func_0042AE18(void) {
    if (D_00455224 < 0) {
        return 0;
    }
    if (func_00426D18(D_0052EEC0, 5, 0, 0, 0, &D_0052EF00, 4, 0, 0) < 0) {
        return 0xFFFFFFFF;
    }
    return D_0052EF00;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AE88);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
unsigned int func_0042AE88(void) {
    if (D_00455224 < 0) {
        return 0;
    }
    if (func_00426D18(D_0052EEC0, 6, 0, 0, 0, &D_0052EF00, 4, 0, 0) < 0) {
        return 0xFFFFFFFF;
    }
    return D_0052EF00;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AEF8);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
unsigned int func_0042AEF8(void) {
    if (D_00455224 < 0) {
        return 0;
    }
    if (func_00426D18(D_0052EEC0, 7, 0, 0, 0, &D_0052EF00, 4, 0, 0) < 0) {
        return 0xFFFFFFFF;
    }
    return D_0052EF00;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AF68);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int D_0052EF40;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
unsigned int func_0042AF68(int a0) {
    if (D_00455224 < 0) {
        return 0;
    }
    D_0052EF40 = a0;
    if (func_00426D18(D_0052EEC0, 8, 0, (int)&D_0052EF40, 4, &D_0052EF00, 4, 0, 0) < 0) {
        return 0xFFFFFFFF;
    }
    return D_0052EF00;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AFE8);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern int D_0052EF40;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
unsigned int func_0042AFE8(int a0) {
    if (D_00455224 < 0) {
        return 0;
    }
    D_0052EF40 = a0;
    if (func_00426D18(D_0052EEC0, 9, 0, (int)&D_0052EF40, 4, &D_0052EF00, 4, 0, 0) < 0) {
        return 0xFFFFFFFF;
    }
    return D_0052EF00;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042B068);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B168);
#ifdef SKIP_ASM
extern char D_00455164[];
extern char D_0052F2A8[];
extern char *D_0045522C;
extern int func_00415FC8(char *, char *, int);
int func_0042B168(void) {
    char *a = D_00455164;
    char *b = D_0052F2A8;
    int r = 0;
    if (func_00415FC8(b, a, 4) != 0 &&
        func_00415FC8(b, D_0045522C, 4) != 0) {
        r = func_00415FC8(a, D_0045522C, 4) != 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B1F8);
#ifdef SKIP_ASM
extern void func_00416210(void *a0, int a1, int a2);
extern int D_00455228;
extern char D_0052F2A8[];
int func_0042B1F8(void) {
    D_00455228 = -1;
    func_00416210(D_0052F2A8, 0, 4);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042B230);

INCLUDE_ASM("seg/seg_325220", func_0042B438);

INCLUDE_ASM("seg/seg_325220", func_0042B640);

INCLUDE_ASM("seg/seg_325220", func_0042B6D0);

INCLUDE_ASM("seg/seg_325220", func_0042B770);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B800);
#ifdef SKIP_ASM
extern int func_0042B230(int a0, int a1, int a2, int *a3);
int func_0042B800(int a0, int a1, int a2) {
    int sp;
    return func_0042B230(a0, a1, a2, &sp);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B820);
#ifdef SKIP_ASM
extern int func_0042B230(int a0, int a1, int a2, int *a3);
int func_0042B820(int a0, int a1, int a2, int *a3) {
    return func_0042B230(a0, a1, a2, a3);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042B840);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BA68);
#ifdef SKIP_ASM
extern int func_0042B840(int a0, int a1, int a2, int *a3, int a4);
int func_0042BA68(int a0, int a1, int a2) {
    int sp;
    return func_0042B840(a0, a1, a2, &sp, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BA88);
#ifdef SKIP_ASM
extern int func_0042B840(int a0, int a1, int a2, int *a3, int a4);
int func_0042BA88(int a0, int a1, int a2, int *a3) {
    return func_0042B840(a0, a1, a2, a3, 0);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042BAA8);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BBB0);
#ifdef SKIP_ASM
extern int func_0042BAA8(int a0, char *a1, int a2, int a3);
int func_0042BBB0(int a0, char *a1, int a2) {
    return func_0042BAA8(a0, a1, a2, 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BBD0);
#ifdef SKIP_ASM
extern char D_0049AD58[];
extern int func_0042BAA8(int a0, char *a1, int a2, int a3);
int func_0042BBD0(int a0, int a1) {
    return func_0042BAA8(a0, D_0049AD58, a1, 1);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042BBF8);

INCLUDE_ASM("seg/seg_325220", func_0042BCE8);

INCLUDE_ASM("seg/seg_325220", func_0042BDC8);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BF08);
#ifdef SKIP_ASM
extern int func_004241B0(int a0);
int func_0042BF08(void) { int r = func_004241B0(4) & 0x10000; return r != 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BF30);
#ifdef SKIP_ASM
extern int func_004241B0(int a0);
extern void func_00424220(void);
int func_0042BF30(void) {
    if (func_004241B0(4) & 0x40000) {
        func_00424220();
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042BF68);

INCLUDE_ASM("seg/seg_325220", func_0042C078);

INCLUDE_ASM("seg/seg_325220", func_0042C0C0);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C0D8);
#ifdef SKIP_ASM
extern int D_00455248;
extern int D_0045524C;
extern int func_00423DA0(int *a0);
void func_0042C0D8(void) {
    int a[8];
    int b[8];
    a[1] = 1;
    a[2] = 1;
    b[1] = 1;
    b[2] = 1;
    D_00455248 = func_00423DA0(a);
    D_0045524C = func_00423DA0(b);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C120);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C130);
#ifdef SKIP_ASM
// 88.57% (identical shape/score for func_0042C360, func_0042C780, func_0042CB78 -- same asm)
// target: bnez delay slot is an unfilled nop with `addiu $4,$4,4` placed BEFORE bnez; ours fills the slot with the addiu.
// do{}while(0) in body made it worse (85.71). byte version func_0042C4D0 same issue (86.67), see drafts/w2/func_0042C4D0.c
int func_0042C130(int *a0, int *a1, unsigned int a2) {
    unsigned int n = a2 >> 2;
    unsigned int i;
    for (i = 0; i < n; i++) {
        *a0++ = *a1++;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C168);
#ifdef SKIP_ASM
int *func_0042C168(int *a0, int *a1, int a2) {
    while (*a0 != a2 && a0 < a1) a0++;
    return a0 < a1 ? a0 : 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C1A8);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C1B8);
#ifdef SKIP_ASM
extern void func_0042C120(void *a0, int a1, int a2);
extern int D_00455230;
int func_0042C1B8(int a0) {
    int v;
    func_0042C120(&v, D_00455230 + a0 * 4, 4);
    return v;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C1F0);

INCLUDE_ASM("seg/seg_325220", func_0042C2F0);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C300);
#ifdef SKIP_ASM
extern void func_0042C0D8(void);
extern void func_0042C1F0(void);
extern void func_0042C7C8(void);
extern void func_00424B78(void);
extern void func_0042C410(void);
extern void func_0042CBD0(void);
void func_0042C300(void) {
    func_0042C0D8();
    func_0042C1F0();
    func_0042C7C8();
    func_00424B78();
    func_0042C410();
    func_0042CBD0();
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C340);

INCLUDE_ASM("seg/seg_325220", func_0042C350);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C360);
#ifdef SKIP_ASM
// 88.57% (identical shape/score for func_0042C360, func_0042C780, func_0042CB78 -- same asm)
// target: bnez delay slot is an unfilled nop with `addiu $4,$4,4` placed BEFORE bnez; ours fills the slot with the addiu.
// do{}while(0) in body made it worse (85.71). byte version func_0042C4D0 same issue (86.67), see drafts/w2/func_0042C4D0.c
int func_0042C360(int *a0, int *a1, unsigned int a2) {
    unsigned int n = a2 >> 2;
    unsigned int i;
    for (i = 0; i < n; i++) {
        *a0++ = *a1++;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C398);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C3A8);
#ifdef SKIP_ASM
extern void func_00423E50(unsigned *p);
extern void func_00423E40(unsigned *p);
int func_0042C3A8(void) {
    unsigned a[2];
    func_00423E50(&a[0]);
    a[1] = (a[0] & 0xFFFF1FFF) | 0x2000;
    func_00423E40(&a[1]);
    func_00423E50(&a[1]);
    func_00423E40(&a[0]);
    return ((a[1] >> 13) & 7) == 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C410);
#ifdef SKIP_ASM
struct P42C410 { int a; int b; };
extern struct P42C410 D_004559F8[];
extern char D_00455250[];
extern int func_0042C3A8(void);
extern void func_0042C340(int, int);
extern void func_0042C350(int, char *, int);
extern void func_00424020(int);
extern int func_0042C398(int);
void func_0042C410(void) {
    unsigned i;
    if (func_0042C3A8() != 0) {
        func_0042C340(D_004559F8[0].a, D_004559F8[0].b);
        func_0042C350(0x80074000, D_00455250, 0x7A8);
        func_00424020(0);
        func_00424020(2);
        func_0042C340(D_004559F8[1].a, D_004559F8[1].b);
        for (i = 2; i < 3; i++) {
            func_0042C340(D_004559F8[i].a, func_0042C398(D_004559F8[i].a));
        }
    }
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C4C0);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C4D0);
#ifdef SKIP_ASM
// 86.67%: target has addiu $4 before bnez with unfilled nop delay slot; ours fills slot
int func_0042C4D0(unsigned char *a0, unsigned char *a1, unsigned int a2) {
    unsigned int i;
    for (i = 0; i < a2; i++) {
        *a0++ = *a1++;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C500);

INCLUDE_ASM("seg/seg_325220", func_0042C510);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C628);
#ifdef SKIP_ASM
extern void func_0042CD58_v(void) __asm__("func_0042CD58");
void func_0042C628(void) {
    func_0042CD58_v();
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C630);
#ifdef SKIP_ASM
extern char D_0049AD90[];
extern int D_00456538;
extern void func_0042C510_v(char *, int, int) __asm__("func_0042C510");
extern void func_0042C628(void);
extern int func_004239F0(int, int, int, int);
int func_0042C630(int a0, int a1, int a2, int a3) {
    func_0042C510_v(D_0049AD90, a2, a3);
    func_0042C628();
    return func_004239F0(a0, a1, a2, D_00456538 + 4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C6A0);
#ifdef SKIP_ASM
extern int D_00456538;
extern int func_0042C510(int a0, int a1);
extern void func_004239E0(int a0, int a1, int a2);
void func_0042C6A0(int a0, int a1) {
    int r = func_0042C510(a0, a1);
    func_0042C628();
    func_004239E0(r, a1, D_00456538 + 4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C6E8);
#ifdef SKIP_ASM
extern void func_004239C0(int);
void func_0042C6E8(int a) {
    func_0042C628();
    func_004239C0(a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C710);
#ifdef SKIP_ASM
extern int D_00456538;
extern char D_0049AD90[];
extern int func_0042C510_3(char *a0, int a1, int a2) __asm__("func_0042C510");
extern void func_004241C0(int a0, int a1);
void func_0042C710(int a0, int a1) {
    func_0042C510_3(D_0049AD90, a0, a1);
    func_0042C628();
    func_004241C0(a0, D_00456538 + 4);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C760);

INCLUDE_ASM("seg/seg_325220", func_0042C770);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C780);
#ifdef SKIP_ASM
// 88.57% (identical shape/score for func_0042C360, func_0042C780, func_0042CB78 -- same asm)
// target: bnez delay slot is an unfilled nop with `addiu $4,$4,4` placed BEFORE bnez; ours fills the slot with the addiu.
// do{}while(0) in body made it worse (85.71). byte version func_0042C4D0 same issue (86.67), see drafts/w2/func_0042C4D0.c
int func_0042C780(int *a0, int *a1, unsigned int a2) {
    unsigned int n = a2 >> 2;
    unsigned int i;
    for (i = 0; i < n; i++) {
        *a0++ = *a1++;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C7B8);

INCLUDE_ASM("seg/seg_325220", func_0042C7C8);

INCLUDE_ASM("seg/seg_325220", func_0042C8A0);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C8E8);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042C8E8(int a0) {
    return func_004241D0(2, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C910);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C910(int a0, char a1) {
    int buf[2];
    buf[0] = a0;
    buf[1] = a1;
    func_004241D0(3, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C940);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042C940(int a0) {
    return func_004241D0(4, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C968);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C968(int a0, int a1, unsigned short a2) {
    int buf[3];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    func_004241D0(-5, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C9A0);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C9A0(int a0, int a1, unsigned short a2) {
    int buf[3];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    func_004241D0(-6, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C9D8);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C9D8(int a0, char a1) {
    int buf[2];
    buf[0] = a0;
    buf[1] = a1;
    func_004241D0(-7, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CA08);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042CA08(int a0) {
    return func_004241D0(-8, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CA30);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042CA30(int a0) {
    return func_004241D0(-9, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CA58);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042CA58(int a0) {
    return func_004241D0(0x10, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CA80);
#ifdef SKIP_ASM
extern int D_004564F0;
extern void func_0042CFC0(void);
extern void func_00423A50(int, void (*)(void));
int func_0042CA80(int a0) {
    D_004564F0 = a0;
    func_00423A50(1, func_0042CFC0);
    func_00423A50(2, func_0042CFC0);
    func_00423A50(3, func_0042CFC0);
    return a0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CAE0);
#ifdef SKIP_ASM
extern int D_004564F8[];
extern char D_0042D200[];
extern void func_00423A50(int, void (*)(void));
extern void func_00423A60(int, void *);
unsigned func_0042CAE0(int a0, int a1) {
    int old;
    if (a0 - 1 >= 13U) {
        return 0xFFFFFFFF;
    }
    old = D_004564F8[a0];
    D_004564F8[a0] = a1;
    if (a0 - 1 < 3U) {
        func_00423A50(a0, (void (*)(void))D_0042D200);
    } else {
        func_00423A60(a0, (void (*)(void))D_0042D200);
    }
    return old;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042CB68);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CB78);
#ifdef SKIP_ASM
// 88.57% (identical shape/score for func_0042C360, func_0042C780, func_0042CB78 -- same asm)
// target: bnez delay slot is an unfilled nop with `addiu $4,$4,4` placed BEFORE bnez; ours fills the slot with the addiu.
// do{}while(0) in body made it worse (85.71). byte version func_0042C4D0 same issue (86.67), see drafts/w2/func_0042C4D0.c
int func_0042CB78(int *a0, int *a1, unsigned int a2) {
    unsigned int n = a2 >> 2;
    unsigned int i;
    for (i = 0; i < n; i++) {
        *a0++ = *a1++;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042CBB0);

INCLUDE_ASM("seg/seg_325220", func_0042CBC0);

INCLUDE_ASM("seg/seg_325220", func_0042CBD0);

INCLUDE_ASM("seg/seg_325220", func_0042CC98);

INCLUDE_ASM("seg/seg_325220", func_0042CCA8);

INCLUDE_ASM("seg/seg_325220", func_0042CCB8);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CCC8);
#ifdef SKIP_ASM
extern int func_0042CCB8(int a0);
int func_0042CCC8(int a0) {
    if ((unsigned int)(a0 - 13) >= 0x23)
        return -1;
    return func_0042CCB8(a0);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042CCF8);

INCLUDE_ASM("seg/seg_325220", func_0042CD08);

INCLUDE_ASM("seg/seg_325220", func_0042CD18);

INCLUDE_ASM("seg/seg_325220", func_0042CD28);

INCLUDE_ASM("seg/seg_325220", func_0042CD38);

INCLUDE_ASM("seg/seg_325220", func_0042CD48);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CD58);
#ifdef SKIP_ASM
extern int func_00424200(void);
extern int func_0042CD98(void);
extern int func_00424210(void);
int func_0042CD58(void) {
    if (func_00424200() == 0x2000000) {
        return func_0042CD98();
    }
    return func_00424210();
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042CD98);

INCLUDE_ASM("seg/seg_325220", func_0042CFC0);

INCLUDE_ASM("seg/seg_325220", func_0042D320);

INCLUDE_ASM("seg/seg_325220", func_0042D380);

INCLUDE_ASM("seg/seg_325220", func_0042D470);

INCLUDE_ASM("seg/seg_325220", func_0042DAD8);
