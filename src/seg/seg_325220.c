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

//100%
INCLUDE_ASM("seg/seg_325220", func_00426078);
#ifdef SKIP_ASM
struct E6078 { int a; int b; int c; int d; };
extern int D_0052BCE0;
extern void func_00426358(int, int);
extern int func_00424160(struct E6078 *, int);
extern int func_00424170(struct E6078 *, int);
int func_00426078_d(int, int, int *, unsigned, int, int, int) __asm__("func_00426078");
int func_00426078_d(int a0, int a1, int *a2, unsigned a3, int a4, int a5, int a6) {
    struct E6078 ent[2];
    int n;
    if (a3 - 0x10 > 0x60) {
        return 0;
    }
    n = 0;
    if (a6 > 0) {
        ent[0].a = a4;
        n = 1;
        ent[0].b = a5;
        a2[1] = a5;
        a2[0] = *(unsigned char *)a2 | (a6 << 8);
        ent[0].c = a6;
        ent[0].d = 0;
        if (a1 & 4) {
            func_00426358(a4, a6);
        }
    } else {
        a2[1] = 0;
        a2[0] = *(unsigned char *)a2;
    }
    ent[n].a = (int)a2;
    ent[n].b = D_0052BCE0;
    ent[n].c = a3;
    a2[2] = a0;
    *(unsigned char *)a2 = a3;
    ent[n].d = 0x44;
    func_00426358((int)a2, a3);
    n++;
    if (a1 & 1) {
        return func_00424170(ent, n);
    }
    return func_00424160(ent, n);
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_004265D0);
#ifdef SKIP_ASM
struct E65D0 { char pad[0x10]; int f10; int f14; int f18; char pad2[0x24]; };
struct S65D0 { int f0; struct E65D0 *tab; int n; };
extern int func_0042C078_rq(void) __asm__("func_0042C078");
extern void func_0042C0C0(void);
struct E65D0 *f65D0(struct S65D0 *s) __asm__("func_004265D0");
struct E65D0 *f65D0(struct S65D0 *s) {
    struct E65D0 *e;
    int i;
    int n;
    int c;
    int id;
    int seq;
    func_0042C078_rq();
    n = s->n;
    i = 0;
    e = s->tab;
    while (i < n) {
        if (!(e->f10 & 1)) {
            e->f10 = (i << 16) | 5;
            c = s->f0;
            id = c + 1;
            s->f0 = id;
            if (id == 1) {
                s->f0 = c + 2;
                seq = 1;
            } else {
                seq = id;
            }
            id = seq;
            e->f14 = (int)e;
            e->f18 = id;
            func_0042C0C0();
            return e;
        }
        i++;
        e++;
    }
    func_0042C0C0();
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426678);
#ifdef SKIP_ASM
void func_00426678(unsigned int *a0) {
    a0[6] = 0;
    a0[4] &= 0xFFFFFFFE;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426698);
#ifdef SKIP_ASM
struct S6698 { int p0[5]; char *base; int cnt; int p1[2]; int idx; };
char *f6698(struct S6698 *a0) __asm__("func_00426698");
char *f6698(struct S6698 *a0) {
    int r = a0->idx % a0->cnt;
    char *p = a0->base + r * 64;
    a0->idx = r + 1;
    return p;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_00426708);
#ifdef SKIP_ASM
struct Q6708 { int f0; int pad4; int f8; char padC[0x10]; int f1C; int f20; int f24; };
struct A6708 { char pad[0x1C]; struct Q6708 *q; unsigned f20; int f24; int f28; int f2C; };
extern void func_00423DD0(int);
extern void func_00426678_k(int) __asm__("func_00426678");
void f6708(struct A6708 *a) __asm__("func_00426708");
void f6708(struct A6708 *a) {
    struct Q6708 *q;
    switch (a->f20) {
    case 0x8000000A:
        q = a->q;
        if (q->f1C != 0) {
            ((void (*)(int))q->f1C)(q->f20);
        }
        break;
    case 0x80000009:
        q = a->q;
        q->f24 = a->f24;
        ((int *)q)[5] = a->f28;
        ((int *)q)[6] = a->f2C;
        break;
    case 0x8000000B:
        break;
    }
    q = a->q;
    if (q->f8 >= 0) {
        func_00423DD0(q->f8);
    }
    func_00426678_k(q->f0);
    q->f0 = 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_00426820);
#ifdef SKIP_ASM
extern int func_00426698(int *a0);
extern int func_004266C8(int *a0, int a1);
extern int func_004261F0(int a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00423B80(int a0, int (*a1)(int, int, int *), int *a2);
extern int func_004267C0(int a0, int a1, int *p);
extern int func_004266C8_u(int *, unsigned) __asm__("func_004266C8");
void func_00426820(int *a0, int *a1) {
    int *p;
    unsigned fl = a0[4];
    int t1;
    int t2;
    if (fl & 4) {
        p = (int *)func_004266C8_u(a1, fl >> 16);
    } else {
        p = (int *)func_00426698(a1);
    }
    t1 = a0[5];
    t2 = a0[7];
    p[5] = t1;
    p[7] = t2;
    p[8] = 0x8000000C;
    p[9] = a0[8];
    p[10] = a0[9];
    p[11] = a0[10];
    if (func_004261F0(0x80000008, (int)p, 0x40, a0[8], a0[9], a0[10]) == 0) {
        func_00423B80(10, func_004267C0, p);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004268F0);
#ifdef SKIP_ASM
struct S68F0 { struct S68F0 *f0; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; int f20; int f24; int f28; };
extern char D_0052D680[];
extern struct S68F0 *func_004265D0_p(char *) __asm__("func_004265D0");
extern void func_00426678_j(struct S68F0 *) __asm__("func_00426678");
extern int func_00423DA0_j(int *) __asm__("func_00423DA0");
extern void func_00423DB0_j(int) __asm__("func_00423DB0");
extern int func_00423DE0_j(int) __asm__("func_00423DE0");
extern int func_004261B0_j(int, int, int, int, int, int) __asm__("func_004261B0");
int func_004268F0_d(struct S68F0 *, int, int, int, int) __asm__("func_004268F0");
int func_004268F0_d(struct S68F0 *a0, int a1, int a2, int a3, int a4) {
    int buf[8];
    struct S68F0 *t;
    t = func_004265D0_p(D_0052D680);
    if (t == 0) {
        return -1;
    }
    a0->f0 = t;
    a0->f4 = t->f18;
    t->f20 = a1;
    t->f24 = a2;
    t->f28 = a3;
    t->f14 = (int)t;
    t->f1C = (int)a0;
    if (!(a4 & 1)) {
        buf[1] = 1;
        buf[2] = 0;
        a0->f8 = func_00423DA0_j(buf);
        if (a0->f8 < 0) {
            func_00426678_j(t);
            return -3;
        }
        if (func_004261B0_j(0x8000000C, (int)t, 0x40, 0, 0, 0) == 0) {
            func_00426678_j(t);
            func_00423DB0_j(a0->f8);
            return -2;
        }
        func_00423DE0_j(a0->f8);
        func_00423DB0_j(a0->f8);
        return 0;
    }
    a0->f8 = -1;
    if (func_004261B0_j(0x8000000C, (int)t, 0x40, 0, 0, 0) == 0) {
        func_00426678_j(t);
        return -2;
    }
    return 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_00426B48);
#ifdef SKIP_ASM
struct S6B48 { struct S6B48 *f0; int f4; int f8; int fC; int f10; int f14; int f18; int f1C; int f20; int f24; };
extern char D_0052D680[];
extern struct S6B48 *func_004265D0(char *);
extern void func_00426678_i(struct S6B48 *) __asm__("func_00426678");
extern int func_00423DA0(int *);
extern void func_00423DB0(int);
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
int func_00426B48_d(struct S6B48 *, int, int) __asm__("func_00426B48");
int func_00426B48_d(struct S6B48 *a0, int a1, int a2) {
    int buf[8];
    struct S6B48 *t;
    a0->f10 = 0;
    a0->f24 = 0;
    t = func_004265D0(D_0052D680);
    if (t == 0) {
        return -1;
    }
    a0->f0 = t;
    a0->f4 = t->f18;
    t->f20 = a1;
    t->f14 = (int)t;
    t->f1C = (int)a0;
    if (!(a2 & 1)) {
        buf[1] = 1;
        buf[2] = 0;
        a0->f8 = func_00423DA0(buf);
        if (a0->f8 < 0) {
            func_00426678_i(t);
            return -3;
        }
        if (func_004261B0(0x80000009, (int)t, 0x40, 0, 0, 0) == 0) {
            func_00426678_i(t);
            func_00423DB0(a0->f8);
            return -2;
        }
        func_00423DE0_i(a0->f8);
        func_00423DB0(a0->f8);
        return 0;
    }
    a0->f8 = -1;
    if (func_004261B0(0x80000009, (int)t, 0x40, 0, 0, 0) == 0) {
        func_00426678_i(t);
        return -2;
    }
    return 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_00426F48);
#ifdef SKIP_ASM
struct N6F48 { int f0; int f4; int f8; int fC; int f10; struct N6F48 *next; };
struct D6F48 { char pad[0x28]; struct N6F48 *head; };
extern struct D6F48 D_6F48 __asm__("D_0052D680");
extern int func_0042C078_r(void) __asm__("func_0042C078");
extern void func_0042C0C0(void);
void func_00426F48(struct N6F48 *n, int a1) {
    struct N6F48 *p;
    struct N6F48 *h;
    func_0042C078_r();
    n->f0 = a1;
    n->f4 = 0;
    n->f8 = 0;
    n->fC = 0;
    n->f10 = 0;
    h = D_6F48.head;
    n->next = 0;
    if (h == 0) {
        D_6F48.head = n;
    } else {
        p = h;
        for (; p->next != 0; p = p->next)
            ;
        p->next = n;
    }
    func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426FE0);
#ifdef SKIP_ASM
struct N6FE0 { int f0; int f4; int f8; int fC; int f10; int f14; char pad[0x20]; struct N6FE0 *next; struct N6FE0 *f3C; struct S6FE0 *f40; };
struct S6FE0 { int f0; int f4; struct N6FE0 *head; };
extern int func_0042C078_r(void) __asm__("func_0042C078");
extern void func_0042C0C0(void);
void func_00426FE0(struct N6FE0 *n, int a1, int a2, int a3, int a4, int a5, struct S6FE0 *a6) {
    struct N6FE0 *p;
    struct N6FE0 *h;
    func_0042C078_r();
    n->f3C = 0;
    n->next = 0;
    n->f0 = a1;
    h = a6->head;
    n->f4 = a2;
    n->f8 = a3;
    n->f10 = a4;
    n->f14 = a5;
    n->f40 = a6;
    if (h == 0) {
        a6->head = n;
    } else {
        p = h;
        for (; p->next != 0; p = p->next)
            ;
        p->next = n;
    }
    func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004270B0);
#ifdef SKIP_ASM
struct N70B0 { char pad[0x38]; struct N70B0 *next; };
struct S70B0 { int f0; int f4; struct N70B0 *head; };
extern int func_0042C078_r(void) __asm__("func_0042C078");
extern void func_0042C0C0(void);
struct N70B0 *func_004270B0(struct N70B0 *x, struct S70B0 *s) {
    struct N70B0 *p;
    func_0042C078_r();
    p = s->head;
    if (p == x) {
        s->head = p->next;
    } else {
        while (p != 0) {
            if (p->next == x) {
                p->next = x->next;
                break;
            }
            p = p->next;
        }
    }
    func_0042C0C0();
    return p;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_00429420);
#ifdef SKIP_ASM
struct S9420 { int f0; int f4; int f8; int fC; };
extern int D_0045520C;
extern struct S9420 D_0052D700;
extern char D_0052E340[];
extern char D_0052EE00[];
extern int func_00427988_b(int) __asm__("func_00427988");
extern void func_00427A90(void);
extern void func_004279B8(void);
extern int func_00423DA0(int *p);
extern void func_00423DB0(int);
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_00429420(int a0) {
    int buf[12];
    int sem;
    int v;
    struct S9420 *p = &D_0052D700;
    func_00427988_b(0xF);
    if (D_0045520C == 0) {
        func_00427A90();
    }
    p->fC = a0;
    buf[1] = 1;
    buf[2] = 0;
    buf[5] = 0;
    sem = func_00423DA0(&buf[0]);
    D_0052D700.f0 = sem;
    p->f4 = (int)&buf[8];
    p->f8 = 4;
    if (func_00426D18_v(D_0052EE00, 0xF, 0, &D_0052D700, 0x10, D_0052E340, 4, 0, 0) < 0) {
        func_00423DB0(sem);
        func_004279B8();
        return -1;
    }
    v = *(int *)((int)D_0052E340 | 0x20000000);
    func_004279B8();
    if (v == 0) {
        func_00423DB0(sem);
        return -1;
    }
    func_00423DE0_i(sem);
    func_00423DB0(sem);
    return buf[8];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00429540);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00429540(int a0) {
    return func_00428E18(a0, 0x10);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00429560);
#ifdef SKIP_ASM
struct E429560 { int f0; int f4; int f8; int fC; };
extern int D_00455218;
extern int D_0045520C;
extern char D_0052EC00[];
extern int func_00427988_b(int) __asm__("func_00427988");
extern void func_004279B8(void);
extern void func_00427A90(void);
extern struct E429560 *func_00427498_p(void) __asm__("func_00427498");
extern int func_00428E18(int a0, int a1);
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
extern void func_00423DC0(int);
int func_00429560(int a0) {
    int r;
    struct E429560 *p;
    func_00427988_b(9);
    if (D_0045520C == 0) {
        func_00427A90();
    }
    func_004279B8();
    p = func_00427498_p();
    if (p == 0) {
        return -0x13;
    }
    r = func_00428E18(a0, 9);
    if (r < 0) {
        func_00423DE0_i(D_00455218);
        p->f4 = 0;
        func_00423DC0(D_00455218);
        return r;
    } else {
        func_00423DE0_i(D_00455218);
        p->f0 = r;
        r = ((char *)p - D_0052EC00) >> 4;
        func_00423DC0(D_00455218);
        return r;
    }
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00429628);

//100%
INCLUDE_ASM("seg/seg_325220", func_00429790);
#ifdef SKIP_ASM
struct S9790 { int f0; int f4; int f8; int fC; int f10; };
extern int D_0045520C;
extern struct S9790 D_Y __asm__("D_0052D700");
extern char D_0052E340[];
extern char D_0052EE00[];
extern int *func_00427520_p(int) __asm__("func_00427520");
extern int func_00427988_b(int);
extern void func_004279B8(void);
extern int func_00423DA0(int *p);
extern void func_00423DB0(int);
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_00429790_d(int, int) __asm__("func_00429790");
int func_00429790_d(int a0, int a1) {
    int buf[12];
    int sem;
    int v;
    int *t;
    struct S9790 *p = &D_Y;
    t = func_00427520_p(a0);
    func_00427988_b(0xB);
    if (D_0045520C == 0) {
        func_004279B8();
        return -1;
    }
    if (t == 0 || t[1] == 0) {
        func_004279B8();
        return -9;
    }
    p->fC = t[0];
    p->f10 = a1;
    buf[1] = 1;
    buf[2] = 0;
    buf[5] = 0;
    sem = func_00423DA0(&buf[0]);
    p->f0 = sem;
    p->f4 = (int)&buf[8];
    p->f8 = 4;
    if (func_00426D18_v(D_0052EE00, 0xB, 0, p, 0x20, D_0052E340, 4, 0, 0) < 0) {
        func_00423DE0_i(sem);
        func_004279B8();
        return -0xB;
    }
    v = *(int *)((int)D_0052E340 | 0x20000000);
    func_004279B8();
    if (v == 0) {
        func_00423DB0(sem);
        return -0xB;
    }
    func_00423DE0_i(sem);
    func_00423DB0(sem);
    return buf[8];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004298E8);
#ifdef SKIP_ASM
struct S98E8 { int f0; int f4; int f8; int fC; char s[0x400]; };
extern int D_0045520C;
extern struct S98E8 D_G98 __asm__("D_0052D700");
extern char D_0052E340[];
extern char D_0052EE00[];
extern int func_00427988_b(int) __asm__("func_00427988");
extern void func_00427A90(void);
extern void func_004279B8(void);
extern int func_00423DA0(int *p);
extern void func_00423DB0(int);
extern int func_00423DE0_i(int) __asm__("func_00423DE0");
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_004298E8(char *a0, int a1) {
    int buf[12];
    int sem;
    int v;
    int i;
    unsigned char c;
    struct S98E8 *p = &D_G98;
    func_00427988_b(0xC);
    if (D_0045520C == 0) {
        func_00427A90();
    }
    c = (p->s[0] = a0[0]);
    i = 0;
    if (c != 0) {
        while (++i < 0x400) {
            c = (p->s[i] = a0[i]);
            if (c == 0) {
                break;
            }
        }
    }
    if (i == 0x400) {
        p->s[0x3FF] = 0;
        i = 0x3FF;
    }
    p->fC = a1;
    buf[1] = 1;
    buf[2] = 0;
    buf[5] = 0;
    sem = func_00423DA0(&buf[0]);
    p->f4 = (int)&buf[8];
    p->f0 = sem;
    p->f8 = 4;
    if (func_00426D18_v(D_0052EE00, 0xC, 0, &D_G98, i + 0x11, D_0052E340, 4, 0, 0) < 0) {
        func_00423DB0(sem);
        func_004279B8();
        return -0xB;
    }
    v = *(int *)((int)D_0052E340 | 0x20000000);
    func_004279B8();
    if (v == 0) {
        func_00423DB0(sem);
        return -0xB;
    }
    func_00423DE0_i(sem);
    func_00423DB0(sem);
    return buf[8];
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AB18);
#ifdef SKIP_ASM
extern int D_00455224;
extern char D_0052EEC0[];
extern int func_00426B48_v(void *, int, int) __asm__("func_00426B48");
int func_0042AB18(void) {
    int i;
    for (;;) {
        i = func_00426B48_v(D_0052EEC0, 0x80000003, 0);
        if (i < 0) {
            return -1;
        }
        if (((int *)D_0052EEC0)[9] != 0) {
            D_00455224 = 0;
            break;
        }
        i = 0x100000;
        do {
            i--;
        } while (i != -1);
    }
    return 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AD28);
#ifdef SKIP_ASM
struct S2AD28 { int cmd; char name[0xFC]; };
extern int D_00455224;
extern char D_0052EEC0[];
extern int D_0052EF00;
extern struct S2AD28 D_0052EF80;
extern int func_00426D18(void *a0, int a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8);
int func_0042AD28(char *a0, int a1) {
    int i;
    if (D_00455224 < 0) {
        return 0;
    }
    i = 0;
    if ((D_0052EF80.name[0] = a0[0]) != 0) {
        do {
            i++;
            if (i >= 0xFC) {
                break;
            }
        } while ((D_0052EF80.name[i] = a0[i]) != 0);
    }
    if (i == 0xFC) {
        D_0052EF80.name[0xFB] = 0;
        i = 0xFB;
    }
    D_0052EF80.cmd = a1;
    D_0052EF80.name[0xFB] = 0;
    if (func_00426D18(D_0052EEC0, 3, 0, (int)&D_0052EF80, i + 5, &D_0052EF00, 4, 0, 0) < 0) {
        return -1;
    }
    return D_0052EF00;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B068);
#ifdef SKIP_ASM
typedef struct { char b[4]; } K4;
extern int D_00455228;
extern char D_0052F280[];
extern K4 D_Gm __asm__("D_0052F2A8");
extern K4 D_G68 __asm__("D_0052F080");
extern int func_00426B48_v(void *, int, int) __asm__("func_00426B48");
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042B068(void) {
    int i;
    if (D_00455228 < 0) {
        for (;;) {
            if (func_00426B48_v(D_0052F280, 0x80000006, 0) < 0) {
                return -1;
            }
            if (((int *)D_0052F280)[9] != 0) {
                D_00455228 = 0;
                if (func_00426D18_v(D_0052F280, 0xFF, 0, 0, 0, &D_G68, 4, 0, 0) < 0) {
                    return 0xFFFEFFFF;
                }
                D_Gm = D_G68;
                return 0;
            }
            i = 0x100000;
            do {
                i--;
            } while (i != -1);
        }
    }
    return 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B230);
#ifdef SKIP_ASM
typedef struct { char b[0xFC]; } K2B230;
struct B230 { int f0; int f4; char pad0[0xFC]; char pad[0xFC]; };
extern struct B230 D_G30 __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_0042B168(void);
extern void *func_0041605C(void *, void *, int);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042B230_i(int a0, int a1, K2B230 *a2, int *a3) __asm__("func_0042B230");
int func_0042B230_i(int a0, int a1, K2B230 *a2, int *a3) {
    int r;
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (func_0042B168() != 0) {
        return 0xFFFEFFFC;
    }
    D_G30.f0 = a0;
    if (a2 != 0) {
        if (a1 >= 0xFD) {
            *(K2B230 *)D_G30.pad = *a2;
            D_G30.f4 = 0xFC;
        } else {
            func_0041605C(D_G30.pad, a2, a1);
            D_G30.f4 = a1;
        }
    } else {
        D_G30.f4 = 0;
    }
    if (func_00426D18_v(D_0052F280, 6, 0, &D_G30, 0x200, &D_G30, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    r = D_G30.f0;
    *a3 = D_G30.f4;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B438);
#ifdef SKIP_ASM
typedef struct { char b[0xFC]; } K2B438;
struct B438 { int f0; int f4; char pad0[0xFC]; char pad[0xFC]; };
extern struct B438 D_G38 __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_0042B168(void);
extern void *func_0041605C(void *, void *, int);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042B438_i(int a0, int a1, K2B438 *a2, int *a3) __asm__("func_0042B438");
int func_0042B438_i(int a0, int a1, K2B438 *a2, int *a3) {
    int r;
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (func_0042B168() != 0) {
        return 0xFFFEFFFC;
    }
    D_G38.f0 = a0;
    if (a2 != 0) {
        if (a1 >= 0xFD) {
            *(K2B438 *)D_G38.pad = *a2;
            D_G38.f4 = 0xFC;
        } else {
            func_0041605C(D_G38.pad, a2, a1);
            D_G38.f4 = a1;
        }
    } else {
        D_G38.f4 = 0;
    }
    if (func_00426D18_v(D_0052F280, 7, 0, &D_G38, 0x200, &D_G38, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    r = D_G38.f0;
    *a3 = D_G38.f4;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B640);
#ifdef SKIP_ASM
struct B640 { int f0; };
extern struct B640 D_G6 __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_0042B168(void);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042B640(int a0) {
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (func_0042B168() != 0) {
        return 0xFFFEFFFC;
    }
    D_G6.f0 = a0;
    if (func_00426D18_v(D_0052F280, 8, 0, &D_G6, 4, &D_G6, 4, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return D_G6.f0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B6D0);
#ifdef SKIP_ASM
struct B6D0 { int f0; int f4; char n1[0xFC]; };
extern struct B6D0 D_G6D __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_0042B168(void);
extern char *strncpy(char *, const char *, int);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042B6D0(char *a0) {
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (func_0042B168() != 0) {
        return 0xFFFEFFFC;
    }
    strncpy(D_G6D.n1, a0, 0xFC);
    D_G6D.n1[0xFB] = 0;
    if (func_00426D18_v(D_0052F280, 9, 0, &D_G6D, 0x200, &D_G6D, 4, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return D_G6D.f0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B770);
#ifdef SKIP_ASM
struct B770 { int f0; };
extern struct B770 D_G7a __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_0042B168(void);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042B770(int a0) {
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (func_0042B168() != 0) {
        return 0xFFFEFFFC;
    }
    D_G7a.f0 = a0;
    if (func_00426D18_v(D_0052F280, 0xA, 0, &D_G7a, 4, &D_G7a, 4, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return D_G7a.f0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B840);
#ifdef SKIP_ASM
typedef struct { char b[0xFC]; } K2B840;
struct B840 { int f0; int f4; char n1[0xFC]; char n2[0xFC]; };
extern struct B840 D_G40 __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_0042B168(void);
extern char *strncpy(char *, const char *, int);
extern void *func_0041605C(void *, void *, int);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042B840_i(char *a0, int a1, K2B840 *a2, int *a3, int a4) __asm__("func_0042B840");
int func_0042B840_i(char *a0, int a1, K2B840 *a2, int *a3, int a4) {
    int r;
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (func_0042B168() != 0) {
        return 0xFFFEFFFC;
    }
    strncpy(D_G40.n1, a0, 0xFC);
    D_G40.n1[0xFB] = 0;
    if (a2 != 0) {
        if (a1 >= 0xFD) {
            *(K2B840 *)D_G40.n2 = *a2;
            D_G40.f0 = 0xFC;
        } else {
            func_0041605C(D_G40.n2, a2, a1);
            D_G40.f0 = a1;
        }
    } else {
        D_G40.n2[0] = 0;
        D_G40.f0 = 0;
    }
    if (func_00426D18_v(D_0052F280, a4, 0, &D_G40, 0x200, &D_G40, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    r = D_G40.f0;
    *a3 = D_G40.f4;
    return r;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BAA8);
#ifdef SKIP_ASM
struct B2F080 { int f0; int f4; char n1[0xFC]; char n2[0xFC]; };
extern struct B2F080 D_X __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_0042B168(void);
extern char *strncpy(char *, const char *, int);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042BAA8_i(char *, char *, int *, int) __asm__("func_0042BAA8");
int func_0042BAA8_i(char *a0, char *a1, int *a2, int a3) {
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (func_0042B168() != 0) {
        return 0xFFFEFFFC;
    }
    strncpy(D_X.n1, a0, 0xFC);
    D_X.n1[0xFB] = 0;
    strncpy(D_X.n2, a1, 0xFC);
    D_X.n2[0xFB] = 0;
    if (func_00426D18_v(D_0052F280, a3, 0, &D_X, 0x200, &D_X, 0x10, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    if (D_X.f0 == 0) {
        return 0xFFFEFFFD;
    }
    a2[0] = D_X.f0;
    a2[1] = D_X.f4;
    return 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BBF8);
#ifdef SKIP_ASM
struct B80 { union { unsigned char b; unsigned short h; int w; } f0; int f4; };
extern struct B80 D_0052F080;
extern char D_0052F280[];
extern int func_0042B068(void);
extern int func_00426D18_v(void *a0, int a1, int a2, void *a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042BBF8(int a0, void *a1, unsigned a2) {
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    if (a2 > 2) {
        return 0xFFFEFFFE;
    }
    *(int *)&D_0052F080 = a0;
    D_0052F080.f4 = a2;
    if (func_00426D18_v(D_0052F280, 3, 0, &D_0052F080, 0x20, &D_0052F080, 0x20, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    if (a2 == 0) {
        *(unsigned char *)a1 = D_0052F080.f0.b;
    } else if (a2 == 1) {
        *(unsigned short *)a1 = D_0052F080.f0.h;
    } else if (a2 == 2) {
        *(int *)a1 = D_0052F080.f0.w;
    } else {
        return 0xFFFEFFFE;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BCE8);
#ifdef SKIP_ASM
struct S7080 { int f0; int f4; union { unsigned char b; unsigned short h; unsigned w; } f8; };
extern struct S7080 D_F080 __asm__("D_0052F080");
extern char D_0052F280[];
extern int func_0042B068(void);
extern int f6D18_b(void *a0, int a1, int a2, int a3, int a4, void *a5, int a6, int a7, int a8) __asm__("func_00426D18");
int func_0042BCE8(int a0, void *a1, int a2) {
    if (func_0042B068() < 0) {
        return 0xFFFF0000;
    }
    D_F080.f0 = a0;
    D_F080.f4 = a2;
    if (a2 == 0) {
        D_F080.f8.b = *(unsigned char *)a1;
    } else if (a2 == 1) {
        D_F080.f8.h = *(unsigned short *)a1;
    } else if (a2 == 2) {
        D_F080.f8.w = *(unsigned *)a1;
    } else {
        return 0xFFFEFFFE;
    }
    if (f6D18_b(D_0052F280, 2, 0, (int)&D_F080, 0x20, &D_F080, 0x10, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C1F0);
#ifdef SKIP_ASM
extern int D_00455230;
extern int D_00455238[];
extern int func_0042C1A8(int, int, void *);
extern void func_0042C2F0(int, int);
void func_0042C1F0(void) {
    int a;
    int b;
    unsigned x;
    unsigned y;
    func_0042C2F0(D_00455238[0], D_00455238[1]);
    func_0042C2F0(D_00455238[2], D_00455238[3]);
    a = func_0042C1A8(0x80000000, 0x80080000, (void *)func_0042C168);
    x = a - 0x20C;
    b = func_0042C1A8(0x80000000, 0x80080000, (void *)func_0042C130);
    y = b - 0x168;
    while (x != y) {
        if (x < y) {
            a = func_0042C1A8(a + 4, 0x80080000, (void *)func_0042C168);
            x = a - 0x20C;
        } else {
            b = func_0042C1A8(b + 4, 0x80080000, (void *)func_0042C130);
            y = b - 0x168;
        }
    }
    D_00455230 = x;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C510);
#ifdef SKIP_ASM
extern int D_00456538;
extern int D_00455A10[];
extern int strlen(char *);
extern int func_0042C4C0(int, void *, int);
extern void func_0042C500(int, int);
int func_0042C510_d(char *, int, char **) __asm__("func_0042C510");
int func_0042C510_d(char *a0, int argc, char **argv) {
    int pos;
    int p = D_00456538;
    int ret;
    int len;
    char **q;
    pos = p + 0x40;
    ret = pos;
    func_0042C500(D_00455A10[0], D_00455A10[1]);
    if (argc >= 0x10) {
        argc = 0xF;
    }
    func_0042C4C0(p, &pos, 4);
    p += 4;
    len = strlen(a0) + 1;
    func_0042C4C0(pos, a0, len);
    pos += len;
    if (argc > 0) {
        q = argv;
        do {
            func_0042C4C0(p, &pos, 4);
            p += 4;
            argc--;
            len = strlen(*q) + 1;
            func_0042C4C0(pos, *q, len);
            q++;
            pos += len;
        } while (argc != 0);
    }
    return ret;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C7C8);
#ifdef SKIP_ASM
extern int D_00456180[];
extern char D_00455A18[];
extern char D_00456158[];
extern void func_00424020(int);
extern int func_0042C7B8(int);
extern void func_0042C760(int, int);
extern void func_0042C770(int, char *, int);
void func_0042C7C8(void) {
    unsigned i;
    int *p;
    if (!(*(volatile int *)0x10001810 & 0x100)) {
        func_0042C760(D_00456180[0], D_00456180[1]);
        func_0042C770(0x80076000, D_00455A18, 0x740);
        func_0042C770(0x82000, D_00456158, 0x28);
        func_00424020(0);
        func_00424020(2);
        func_0042C760(D_00456180[2], D_00456180[3]);
        p = &D_00456180[4];
        for (i = 2; i < 8; i++) {
            func_0042C760(p[0], func_0042C7B8(p[0]));
            p += 2;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C8A0);
#ifdef SKIP_ASM
extern char D_0052F328[];
extern int func_004241D0(int a0, int *a1);
int f8A0(unsigned short a0, int a1, int a2) __asm__("func_0042C8A0");
int f8A0(unsigned short a0, int a1, int a2) {
    int buf[4];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    buf[3] = (int)D_0052F328 | 0x20000000;
    return func_004241D0(1, buf);
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CBD0);
#ifdef SKIP_ASM
extern int D_00456538;
extern int D_00456540[];
extern char D_004561C0[];
extern void func_00424020(int);
extern int func_0042CBB0(int);
extern void func_0042CBC0(int, int);
extern void func_0042CB68(int, char *, int);
void func_0042CBD0(void) {
    unsigned i;
    int *p;
    func_0042CBC0(D_00456540[0], D_00456540[1]);
    func_0042CB68(0x80075000, D_004561C0, 0x330);
    func_00424020(0);
    func_00424020(2);
    func_0042CBC0(D_00456540[2], D_00456540[3]);
    func_0042CBC0(D_00456540[4], D_00456540[5]);
    p = &D_00456540[6];
    for (i = 3; i < 8; i++) {
        func_0042CBC0(p[0], func_0042CBB0(p[0]));
        p += 2;
    }
    D_00456538 = func_0042CBB0(3);
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_325220", func_0042D320);
#ifdef SKIP_ASM
extern long func_00412500(double, double);
extern double func_00411F70(double, double);
extern long func_0042D380(double);
long func_0042D320(double a0) {
    if (func_00412500(a0, 0.0) < 0)
        return -func_0042D380(func_00411F70(0.0, a0));
    return func_0042D380(a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042D380);
#ifdef SKIP_ASM
long func_0042D380(double a) {
    unsigned long hi;
    if (a < 0.0) {
        return 0;
    }
    hi = (unsigned long)(unsigned)(a * 2.3283064365386963e-10) << 32;
    a = a - (double)hi;
    if (a < 0.0) {
        hi -= (unsigned)(0.0 - a);
    } else {
        hi += (unsigned)a;
    }
    return hi;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042D470);

INCLUDE_ASM("seg/seg_325220", func_0042DAD8);
