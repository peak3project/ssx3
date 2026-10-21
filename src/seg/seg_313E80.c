#include "common.h"

//100%
INCLUDE_ASM("seg/seg_313E80", func_00412E80);
#ifdef SKIP_ASM
extern int D_0053EA10[];
extern int D_004998D0[];
extern int D_004A5BA8[];
extern int *func_00412F18(void);
extern void func_00414C00(int *, int, int);
int *func_00412E80(void) {
    if (D_0053EA10[0] == 0) {
        func_00412F18();
        func_00414C00(D_0053EA10, (int)D_004998D0, (int)D_004A5BA8);
    }
    return D_0053EA10;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00412ED0);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern int operator_delete__FPi(int *);
int func_00412ED0(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) return operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00412F00);
#ifdef SKIP_ASM
extern int D_004998B8[];
int *func_00412F00(int **p) {
    *p = D_004998B8;
    return (int*)p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00412F18);
#ifdef SKIP_ASM
extern int D_004998E0[];
extern int D_004A5BA8[];
extern void func_00414C20(int *, int);
int *func_00412F18(void) {
    if (D_004A5BA8[0] == 0)
        func_00414C20(D_004A5BA8, (int)D_004998E0);
    return D_004A5BA8;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00412F58);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413068);
#ifdef SKIP_ASM
struct FB {
    unsigned m : 23;
    unsigned e : 8;
    unsigned s : 1;
};
void func_00413068(float *f, int *o) {
    struct FB *b = (struct FB *)f;
    unsigned m = b->m;
    int e = b->e;
    o[1] = b->s;
    if (e == 0) {
        o[0] = 2;
        return;
    }
    if (e == 0xFF) {
        if (m == 0) {
            o[0] = 4;
            return;
        }
        if (m & 0x100000)
            o[0] = 1;
        else
            o[0] = 0;
        o[3] = m;
        return;
    }
    o[2] = e - 0x7F;
    o[0] = 3;
    o[3] = (m << 7) | 0x40000000;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004130F8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413330);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int *func_004130F8(int *, int *, int *);
extern int func_00412F58(int *);

int func_00413330(float x, float y) {
    int a[4];
    int b[4];
    int c[4];
    float fx = x;
    float fy = y;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    return func_00412F58(func_004130F8(a, b, c));
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413388);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int *func_004130F8(int *, int *, int *);
extern int func_00412F58(int *);

int func_00413388(float x, float y) {
    int a[4];
    int b[4];
    int c[4];
    float fx = x;
    float fy = y;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    b[1] ^= 1;
    return func_00412F58(func_004130F8(a, b, c));
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004133F0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_004135E8);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern float func_00412F58_f(int *) __asm__("func_00412F58");
extern int D_0052ADD8[];

float func_004135E8(float x, float y) {
    int a[4];
    int b[4];
    float fx = x;
    float fy = y;
    int *r;
    unsigned n, d, q, bit;
    int *p;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    p = a;
    if ((unsigned)a[0] < 2) {
        r = a;
    } else if ((unsigned)b[0] < 2) {
        r = b;
    } else {
        a[1] ^= b[1];
        if ((a[0] ^ 4) == 0 || (a[0] ^ 2) == 0) {
            r = a;
            if (a[0] == b[0])
                r = D_0052ADD8;
        } else if ((b[0] ^ 4) == 0) {
            a[3] = 0;
            a[2] = 0;
            r = a;
        } else if ((b[0] ^ 2) == 0) {
            a[0] = 4;
            r = a;
        } else {
            a[2] = a[2] - b[2];
            n = a[3];
            d = b[3];
            if (n < d) {
                a[2]--;
                n <<= 1;
            }
            bit = 0x40000000;
            q = 0;
            for (; bit != 0; bit >>= 1) {
                if (n >= d) {
                    q |= bit;
                    n -= d;
                }
                n <<= 1;
            }
            if ((q & 0x7F) == 0x40) {
                if (q & 0x80)
                    q += 0x40;
                else if (n != 0)
                    q += 0x40;
            }
            p[3] = q;
            r = p;
        }
    }
    return func_00412F58_f(r);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00413748);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413860);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int func_00413748(int *, int *);

int func_00413860(float x, float y) {
    int a[4];
    int b[4];
    float fx = x;
    float fy = y;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    return func_00413748(a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004138B0);
#ifdef SKIP_ASM
extern float func_00412F58_f(int *) __asm__("func_00412F58");

float func_004138B0(int x) {
    int o[4];
    unsigned m, t;
    int e;
    o[0] = 3;
    o[1] = (unsigned)x >> 31;
    if (x == 0) {
        o[0] = 2;
    } else {
        o[2] = 0x1E;
        if (o[1]) {
            if (x == 0x80000000)
                return -2147483648.0f;
            o[3] = -x;
        } else {
            o[3] = x;
        }
        m = o[3];
        if (m <= 0x3FFFFFFF) {
            e = o[2];
            do {
                t = m << 1;
                e--;
                m = t;
            } while (t <= 0x3FFFFFFF);
            o[2] = e;
            o[3] = t;
        }
    }
    return func_00412F58_f(o);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413968);
#ifdef SKIP_ASM
int func_00413968(float x) {
    int o[4];
    float f = x;
    unsigned c;
    unsigned r;
    func_00413068(&f, o);
    c = o[0];
    if ((c ^ 2) == 0)
        return 0;
    if (c < 2)
        return 0;
    if ((c ^ 4) == 0)
        goto sat;
    if (o[2] < 0)
        return 0;
    if (o[2] >= 0x1F) {
sat:
        return o[1] ? 0x80000000 : 0x7FFFFFFF;
    }
    r = (unsigned)o[3] >> (0x1E - o[2]);
    return o[1] ? -r : r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004139F8);
#ifdef SKIP_ASM
unsigned func_004139F8(float x) {
    int o[4];
    float f = x;
    unsigned c;
    func_00413068(&f, o);
    c = o[0];
    if ((c ^ 2) == 0)
        return 0;
    if (c < 2)
        return 0;
    if (o[1])
        return 0;
    if ((c ^ 4) == 0)
        goto sat;
    if (o[2] < 0)
        return 0;
    if (o[2] >= 0x20) {
sat:
        return 0xFFFFFFFF;
    }
    if (o[2] >= 0x1F)
        return (unsigned)o[3] << (o[2] - 0x1E);
    return (unsigned)o[3] >> (0x1E - o[2]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413A90);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int func_00412F58(int *);
int func_00413A90(float x) {
    int obj[2];
    float f = x;
    func_00413068(&f, obj);
    obj[1] = obj[1] == 0;
    return func_00412F58(obj);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413AC8);
#ifdef SKIP_ASM
void func_00413AC8(int a, int b, int c, int d) {
    int v[4];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    func_00412F58(v);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413AF8);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int func_00412778(int, int, int, unsigned long long);
int func_00413AF8(float x) {
    int o[4];
    float f = x;
    func_00413068(&f, o);
    return func_00412778(o[0], o[1], o[2], ((unsigned long long)(long long)o[3] << 32) >> 2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413B38);
#ifdef SKIP_ASM
unsigned char *func_00413B38(unsigned char *p, unsigned *out) {
    unsigned b = *p++;
    unsigned r = b & 0x7F;
    int shift = 0;
    if (b & 0x80) {
        do {
            b = *p++;
            shift += 7;
            r |= (b & 0x7F) << shift;
        } while (b & 0x80);
    }
    *out = r;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413B80);
#ifdef SKIP_ASM
unsigned char *func_00413B80(unsigned char *p, int *out) {
    unsigned shift = 0;
    int r = 0;
    unsigned b;
    do {
        b = *p++;
        r |= (b & 0x7F) << shift;
        shift += 7;
    } while (b & 0x80);
    if (shift < 32 && (b & 0x40))
        r |= -1 << shift;
    *out = r;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413BD0);
#ifdef SKIP_ASM
struct K13BD0 { int f0; int f4; int key; };
struct L13BD0 { struct K13BD0 **items; unsigned n; };
void func_00413BD0(struct L13BD0 *a, struct L13BD0 *b) {
    unsigned m = b->n;
    unsigned n;
    unsigned j;
    j = m;
    if (m != 0) {
        n = a->n;
        do {
            struct K13BD0 *x;
            j--;
            x = b->items[j];
            if (n != 0 && a->items[n - 1]->key - x->key > 0) {
                do {
                    a->items[n + j] = a->items[n - 1];
                    n--;
                } while (n != 0 && a->items[n - 1]->key - x->key > 0);
            }
            a->items[n + j] = x;
        } while (j != 0);
        a->n = a->n + m;
    }
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00413CD0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413F38);
#ifdef SKIP_ASM
struct N13F38 {
    int off;
    int a;
    int b;
};
int func_00413F38(struct N13F38 *n) {
    int cnt = 0;
    if (n->off != 0) {
        do {
            if (n->a != 0 && n->b != 0)
                cnt++;
            n = (struct N13F38 *)((char *)n + n->off + 4);
        } while (n->off);
    }
    return cnt;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413F80);
#ifdef SKIP_ASM
struct N13F80 {
    int off;
    int a;
    unsigned addr;
    int size;
};
struct L13F80 {
    struct N13F80 **arr;
    int cnt;
};
void func_00413F80(struct N13F80 *n, struct L13F80 *l, unsigned *lo, unsigned *hi) {
    unsigned mn = *lo;
    unsigned mx = *hi;
    if (n->off != 0) {
        do {
            if (n->a != 0 && n->addr != 0) {
                l->arr[l->cnt++] = n;
                if (n->addr < mn)
                    mn = n->addr;
                if (mx < n->addr + n->size)
                    mx = n->addr + n->size;
            }
            n = (struct N13F80 *)((char *)n + n->off + 4);
        } while (n->off);
    }
    *lo = mn;
    *hi = mx;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414008);
#ifdef SKIP_ASM
struct N14008 {
    unsigned lo;
    unsigned hi;
    struct N13F80 *root;
    struct N13F80 **roots;
    int cnt;
};
struct LL14008 {
    int *a;
    int na;
    int *b;
    int nb;
};
extern int *func_004188C0(int);
extern struct N13F80 **func_00413CD0(struct LL14008 *, int);
void func_00414008(struct N14008 *n) {
    struct N13F80 **pp;
    int cnt, bytes;
    struct LL14008 l;
    unsigned lo, hi;
    if (n->roots != 0) {
        pp = n->roots;
        cnt = 0;
        while (*pp != 0) {
            cnt += func_00413F38((struct N13F38 *)*pp);
            pp++;
        }
    } else {
        cnt = func_00413F38((struct N13F38 *)n->root);
    }
    bytes = cnt * 4;
    n->cnt = cnt;
    l.a = func_004188C0(bytes);
    l.b = func_004188C0(bytes);
    l.na = 0;
    l.nb = 0;
    lo = 0xFFFFFFFF;
    hi = 0;
    if (n->roots != 0) {
        pp = n->roots;
        while (*pp != 0) {
            func_00413F80(*pp, (struct L13F80 *)&l, &lo, &hi);
            pp++;
        }
    } else {
        func_00413F80(n->root, (struct L13F80 *)&l, &lo, &hi);
    }
    n->roots = func_00413CD0(&l, cnt);
    n->lo = lo;
    n->hi = hi;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00414148);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414230);
#ifdef SKIP_ASM
extern int D_004998F0[];
extern int D_004998F8[];
extern int func_004165A8(int, int);
struct C14230 {
    char *aug;
    int f4;
    unsigned f8;
    int fC;
    int f10;
};
struct U14230 {
    int v;
} __attribute__((packed));
extern int strlen(char *);
unsigned char *func_00414230(int *cie, struct C14230 *o) {
    char *s;
    unsigned char *p;
    unsigned tmp;
    o->aug = (char *)cie - cie[1] + 13;
    if (func_004165A8((int)o->aug, (int)D_004998F0) == 0 || func_004165A8((int)o->aug, (int)D_004998F8) == 0 || *o->aug == 'z') {
        s = o->aug + strlen(o->aug);
        p = (unsigned char *)s + 1;
        if (func_004165A8((int)o->aug, (int)D_004998F8) == 0) {
            o->f4 = ((struct U14230 *)p)->v;
            p += 4;
        } else {
            o->f4 = 0;
        }
        p = func_00413B38(p, &o->f8);
        p = func_00413B80(p, &o->fC);
        o->f10 = *p++;
        if (*o->aug == 'z')
            p = func_00413B38(p, &tmp) + tmp;
        return p;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00414338);

//100%
INCLUDE_ASM("seg/seg_313E80", func_004146D0);
#ifdef SKIP_ASM
extern int *D_0052ADE8;
void func_004146D0(int a, int *p) {
    p[2] = a;
    p[5] = (int)D_0052ADE8;
    D_0052ADE8 = p;
    p[0] = 0;
    p[3] = 0;
    p[4] = 0;
    p[1] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004146F8);
#ifdef SKIP_ASM
extern void func_004146D0(int, int *);
extern int *func_004188C0(int);
void func_004146F8(int a) {
    func_004146D0(a, func_004188C0(0x18));
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414728);
#ifdef SKIP_ASM
extern int *D_0052ADE8;
void func_00414728(int a, int *p) {
    p[2] = a;
    p[5] = (int)D_0052ADE8;
    D_0052ADE8 = p;
    p[1] = 0;
    p[0] = 0;
    p[4] = 0;
    p[3] = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414750);
#ifdef SKIP_ASM
extern void func_00414728(int, int *);
extern int *func_004188C0(int);
void func_00414750(int a) {
    func_00414728(a, func_004188C0(0x18));
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414780);
#ifdef SKIP_ASM
extern int *D_0052ADE8;
extern void func_00418910(int);
extern void func_00418790();
int func_00414780(key)
    int key;
{
    int **pp = &D_0052ADE8;
    int *n;
    if (D_0052ADE8 != 0) {
        do {
            n = *pp;
            if (n[2] == key) {
                *pp = (int *)n[5];
                if (n[0] != 0)
                    func_00418910(n[3]);
                return (int)n;
            }
            pp = (int **)&n[5];
        } while (n[5] != 0);
    }
    func_00418790(key, pp);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004147F8);
#ifdef SKIP_ASM
extern int func_00414780();
extern void func_00418910(int);
void func_004147F8(void) {
    func_00418910(func_00414780());
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414818);
#ifdef SKIP_ASM
// 96.79 (reg numbering: target &st=$20,start=$19,copyend=$21,pc=$22; ours &st=19,start=20,pc=21,copyend=22) - struct copy needs aligned(8)
struct Ctx14818 {
    char *aug;
    int f4;
    int f8;
    int fC;
    unsigned short f10;
};
struct St14818 {
    char pad0[4];
    unsigned f4;
    char pad8[0x29A - 8];
    unsigned short ra;
    char rest[0x2F0 - 0x29C];
} __attribute__((aligned(8)));
struct SI14818 {
    struct St14818 s;
    int extra[2];
};
extern int *f14818_find(unsigned) __asm__("func_00414148");
extern unsigned char *f14818_cie(int *, struct Ctx14818 *) __asm__("func_00414230");
extern unsigned char *f14818_exec(unsigned char *, struct SI14818 *, struct Ctx14818 *, unsigned *) __asm__("func_00414338");
extern unsigned char *f14818_leb(unsigned char *, int *) __asm__("func_00413B38");
extern void f14818_memset(void *, int, int) __asm__("func_00416210");
struct St14818 *func_00414818(unsigned pc, struct St14818 *out) {
    struct Ctx14818 ctx;
    struct SI14818 st;
    int *fde;
    int *cie;
    unsigned char *insn;
    unsigned char *end;
    unsigned char *start;
    int len;
    unsigned fpc;
    fde = f14818_find(pc);
    if (fde == 0) return 0;
    insn = f14818_cie(fde, &ctx);
    if (insn == 0) return 0;
    f14818_memset(&st, 0, sizeof(st));
    st.s.ra = ctx.f10;
    cie = (int *)((char *)fde - (fde[1] - 4));
    end = (unsigned char *)cie + *cie + 4;
    st.s.f4 = ctx.f4;
    do {
    if (insn < end) {
        start = (unsigned char *)(fde + 4);
        do {
            insn = f14818_exec(insn, &st, &ctx, 0);
        } while (insn < end);
    } else {
        start = (unsigned char *)(fde + 4);
    }
    } while (0);
    insn = start;
    if (*ctx.aug == 'z') {
        insn = f14818_leb(insn, &len) + len;
    }
    end = (unsigned char *)fde + *fde + 4;
    fpc = fde[2];
    if (insn < end && pc >= fpc) {
        do {
            insn = f14818_exec(insn, &st, &ctx, &fpc);
        } while (insn < end && pc >= fpc);
    }
    *out = st.s;
    return out;}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004149F0);
#ifdef SKIP_ASM
struct K { int f0; int f4; int key; };
struct L { struct K **items; unsigned n; };
struct M { struct K **arr; int n; };
void func_004149F0(struct L *a, struct M *out) {
    unsigned n = a->n;
    unsigned link[n];
    unsigned top = -1;
    unsigned i;
    unsigned p;
    for (i = 0; i < n; i++) {
        p = top;
        if (p != -1 && a->items[i]->key - a->items[p]->key < 0) {
            do {
                out->arr[out->n++] = a->items[p];
                a->items[p] = 0;
                p = link[p];
                if (p == -1) break;
            } while (a->items[i]->key - a->items[p]->key < 0);
        }
        top = i;
        link[i] = p;
    }
    p = 0;
    for (i = 0; i < n; i++) {
        struct K *k = a->items[i];
        if (k) a->items[p++] = k;
    }
    a->n = p;
}
#endif
