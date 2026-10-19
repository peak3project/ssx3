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

INCLUDE_ASM("seg/seg_313E80", func_00413388);

INCLUDE_ASM("seg/seg_313E80", func_004133F0);

INCLUDE_ASM("seg/seg_313E80", func_004135E8);

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

INCLUDE_ASM("seg/seg_313E80", func_004138B0);

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

INCLUDE_ASM("seg/seg_313E80", func_00413BD0);

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

INCLUDE_ASM("seg/seg_313E80", func_00414818);

INCLUDE_ASM("seg/seg_313E80", func_004149F0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414B68);
#ifdef SKIP_ASM
extern int D_00499A48[];
extern int operator_delete__FPi(int *);
int func_00414B68(int *p, int flag) {
    p[1] = (int)D_00499A48;
    if (flag & 1) return operator_delete__FPi(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414B98);
#ifdef SKIP_ASM
extern int func_004165A8(int, int);
int func_00414B98(a, b)
    int *a;
    int *b;
{
    int r = 0;
    if (b == a || func_004165A8(*a, *b) == 0)
        r = 1;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414BD8);
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
INCLUDE_ASM("seg/seg_313E80", func_00414C00);
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
INCLUDE_ASM("seg/seg_313E80", func_00414C20);
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
INCLUDE_ASM("seg/seg_313E80", func_00414C40);
#ifdef SKIP_ASM
extern int func_00414B98();
int func_00414C40(int a, int b, int c, int d) {
    if (func_00414B98(a, b) == 0) d = 0;
    return d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414C70);
#ifdef SKIP_ASM
extern int func_00414B98();
int func_00414C70(int *p, int a, int b, int c, int d, int e) {
    int *o;
    short *vt;
    if (func_00414B98(p, a) != 0)
        return c;
    o = (int *)p[2];
    vt = (short *)o[1];
    return ((int (*)(int *, int, int, int, int, int))((int *)vt)[5])((int *)((char *)o + vt[8]), a, b, c, d, e);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00414D08);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414EE0);
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
INCLUDE_ASM("seg/seg_313E80", func_00414F00);
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
INCLUDE_ASM("seg/seg_313E80", func_00414F50);
#ifdef SKIP_ASM
void func_00414F50(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414F70);
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
INCLUDE_ASM("seg/seg_313E80", func_00414F90);
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
INCLUDE_ASM("seg/seg_313E80", func_00414FE0);
#ifdef SKIP_ASM
void func_00414FE0(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415000);
#ifdef SKIP_ASM
extern int D_00499A00[];
int *func_00415000(int *p, int a) {
    p[0] = a;
    p[1] = (int)D_00499A00;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415018);
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
INCLUDE_ASM("seg/seg_313E80", func_00415068);
#ifdef SKIP_ASM
void func_00415068(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415088);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern int operator_delete__FPi(int *);
int func_00415088(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) return operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004150B8);
#ifdef SKIP_ASM
extern int D_00499A18[];
int *func_004150B8(int **p) {
    *p = D_00499A18;
    return (int*)p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004150D0);
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
INCLUDE_ASM("seg/seg_313E80", func_00415120);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern int operator_delete__FPi(int *);
int func_00415120(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) return operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415150);
#ifdef SKIP_ASM
extern int D_00499A30[];
int *func_00415150(int **p) {
    *p = D_00499A30;
    return (int*)p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415168);
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
INCLUDE_ASM("seg/seg_313E80", func_004151B8);
#ifdef SKIP_ASM
extern int func_00414B98();
int func_004151B8(void) {
    return func_00414B98() ^ 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004151D8);
#ifdef SKIP_ASM
int func_004151D8(int *p) {
    return *p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004151E0);
#ifdef SKIP_ASM
extern int D_00499A48[];
int *func_004151E0(int *p, int a) {
    p[0] = a;
    p[1] = (int)D_00499A48;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004151F8);
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
INCLUDE_ASM("seg/seg_313E80", func_00415238);
#ifdef SKIP_ASM
extern int func_004165A8(int, int);
int func_00415238(int *a, int *b) {
    return (unsigned)func_004165A8(*a, *b) >> 31;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415260);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415728);
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
INCLUDE_ASM("seg/seg_313E80", func_00415778);
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
INCLUDE_ASM("seg/seg_313E80", func_00415798);
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
INCLUDE_ASM("seg/seg_313E80", func_004157C0);
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
INCLUDE_ASM("seg/seg_313E80", func_004157E0);
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
INCLUDE_ASM("seg/seg_313E80", func_00415800);
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
INCLUDE_ASM("seg/seg_313E80", func_00415820);
#ifdef SKIP_ASM
extern int D_00499B68[];
void func_00415820(int *p, int a) {
    if (p != 0) {
        p[0] = a;
        p[1] = (int)D_00499B68;
    }
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415840);

INCLUDE_ASM("seg/seg_313E80", func_004158F0);

INCLUDE_ASM("seg/seg_313E80", func_00415928);

INCLUDE_ASM("seg/seg_313E80", func_00415960);

INCLUDE_ASM("seg/seg_313E80", func_00415998);

INCLUDE_ASM("seg/seg_313E80", func_004159D0);

INCLUDE_ASM("seg/seg_313E80", func_00415A08);

INCLUDE_ASM("seg/seg_313E80", func_00415A40);

INCLUDE_ASM("seg/seg_313E80", func_00415A78);

INCLUDE_ASM("seg/seg_313E80", func_00415AB0);

INCLUDE_ASM("seg/seg_313E80", func_00415AE8);

INCLUDE_ASM("seg/seg_313E80", func_00415B20);

INCLUDE_ASM("seg/seg_313E80", func_00415B58);

INCLUDE_ASM("seg/seg_313E80", func_00415B90);

INCLUDE_ASM("seg/seg_313E80", func_00415BC8);

INCLUDE_ASM("seg/seg_313E80", func_00415C00);

INCLUDE_ASM("seg/seg_313E80", func_00415C38);

INCLUDE_ASM("seg/seg_313E80", func_00415C70);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415CA8);
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
INCLUDE_ASM("seg/seg_313E80", func_00415CF8);
#ifdef SKIP_ASM
void func_00415CF8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415D18);
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
INCLUDE_ASM("seg/seg_313E80", func_00415D68);
#ifdef SKIP_ASM
void func_00415D68(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415D88);
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
INCLUDE_ASM("seg/seg_313E80", func_00415DD8);
#ifdef SKIP_ASM
void func_00415DD8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415DF8);
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
INCLUDE_ASM("seg/seg_313E80", func_00415E48);
#ifdef SKIP_ASM
void func_00415E48(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415E68);
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
INCLUDE_ASM("seg/seg_313E80", func_00415EB8);
#ifdef SKIP_ASM
void func_00415EB8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415ED8);
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
INCLUDE_ASM("seg/seg_313E80", func_00415F28);
#ifdef SKIP_ASM
void func_00415F28(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415F48);
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
