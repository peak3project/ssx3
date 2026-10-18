#include "common.h"

INCLUDE_ASM("seg/seg_313E80", func_00412E80);

INCLUDE_ASM("seg/seg_313E80", func_00412ED0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00412F00);
#ifdef SKIP_ASM
extern int D_004998B8[];
int *func_00412F00(int **p) {
    *p = D_004998B8;
    return (int*)p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00412F18);

INCLUDE_ASM("seg/seg_313E80", func_00412F58);

INCLUDE_ASM("seg/seg_313E80", func_00413068);

INCLUDE_ASM("seg/seg_313E80", func_004130F8);

INCLUDE_ASM("seg/seg_313E80", func_00413330);

INCLUDE_ASM("seg/seg_313E80", func_00413388);

INCLUDE_ASM("seg/seg_313E80", func_004133F0);

INCLUDE_ASM("seg/seg_313E80", func_004135E8);

INCLUDE_ASM("seg/seg_313E80", func_00413748);

INCLUDE_ASM("seg/seg_313E80", func_00413860);

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

INCLUDE_ASM("seg/seg_313E80", func_004139F8);

INCLUDE_ASM("seg/seg_313E80", func_00413A90);

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

INCLUDE_ASM("seg/seg_313E80", func_00413AF8);

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

INCLUDE_ASM("seg/seg_313E80", func_00413F38);

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

INCLUDE_ASM("seg/seg_313E80", func_00414008);

INCLUDE_ASM("seg/seg_313E80", func_00414148);

INCLUDE_ASM("seg/seg_313E80", func_00414230);

INCLUDE_ASM("seg/seg_313E80", func_00414338);

INCLUDE_ASM("seg/seg_313E80", func_004146D0);

INCLUDE_ASM("seg/seg_313E80", func_004146F8);

INCLUDE_ASM("seg/seg_313E80", func_00414728);

INCLUDE_ASM("seg/seg_313E80", func_00414750);

INCLUDE_ASM("seg/seg_313E80", func_00414780);

INCLUDE_ASM("seg/seg_313E80", func_004147F8);

INCLUDE_ASM("seg/seg_313E80", func_00414818);

INCLUDE_ASM("seg/seg_313E80", func_004149F0);

INCLUDE_ASM("seg/seg_313E80", func_00414B68);

INCLUDE_ASM("seg/seg_313E80", func_00414B98);

INCLUDE_ASM("seg/seg_313E80", func_00414BD8);

INCLUDE_ASM("seg/seg_313E80", func_00414C00);

INCLUDE_ASM("seg/seg_313E80", func_00414C20);

INCLUDE_ASM("seg/seg_313E80", func_00414C40);

INCLUDE_ASM("seg/seg_313E80", func_00414C70);

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

INCLUDE_ASM("seg/seg_313E80", func_00414F00);

INCLUDE_ASM("seg/seg_313E80", func_00414F50);

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

INCLUDE_ASM("seg/seg_313E80", func_00414F90);

INCLUDE_ASM("seg/seg_313E80", func_00414FE0);

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

INCLUDE_ASM("seg/seg_313E80", func_00415018);

INCLUDE_ASM("seg/seg_313E80", func_00415068);

INCLUDE_ASM("seg/seg_313E80", func_00415088);

//100%
INCLUDE_ASM("seg/seg_313E80", func_004150B8);
#ifdef SKIP_ASM
extern int D_00499A18[];
int *func_004150B8(int **p) {
    *p = D_00499A18;
    return (int*)p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004150D0);

INCLUDE_ASM("seg/seg_313E80", func_00415120);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415150);
#ifdef SKIP_ASM
extern int D_00499A30[];
int *func_00415150(int **p) {
    *p = D_00499A30;
    return (int*)p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415168);

//100%
INCLUDE_ASM("seg/seg_313E80", func_004151B8);
#ifdef SKIP_ASM
extern int func_00414B98(void);
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

INCLUDE_ASM("seg/seg_313E80", func_004151F8);

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
extern char func_00415F48[];
extern char func_004151F8[];
extern int func_00415840(int, char *, int, char *, char *, void *);
int func_00415728(int *p) {
    int r = 0;
    if (p) {
        short *vt = (short *)p[1];
        r = func_00415840(((int *)vt)[1], func_00415F48, 1, (char *)p + vt[0], func_004151F8, p);
    }
    return r != 0;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415778);

INCLUDE_ASM("seg/seg_313E80", func_00415798);

INCLUDE_ASM("seg/seg_313E80", func_004157C0);

INCLUDE_ASM("seg/seg_313E80", func_004157E0);

INCLUDE_ASM("seg/seg_313E80", func_00415800);

INCLUDE_ASM("seg/seg_313E80", func_00415820);

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

INCLUDE_ASM("seg/seg_313E80", func_00415CA8);

INCLUDE_ASM("seg/seg_313E80", func_00415CF8);

INCLUDE_ASM("seg/seg_313E80", func_00415D18);

INCLUDE_ASM("seg/seg_313E80", func_00415D68);

INCLUDE_ASM("seg/seg_313E80", func_00415D88);

INCLUDE_ASM("seg/seg_313E80", func_00415DD8);

INCLUDE_ASM("seg/seg_313E80", func_00415DF8);

INCLUDE_ASM("seg/seg_313E80", func_00415E48);

INCLUDE_ASM("seg/seg_313E80", func_00415E68);

INCLUDE_ASM("seg/seg_313E80", func_00415EB8);

INCLUDE_ASM("seg/seg_313E80", func_00415ED8);

INCLUDE_ASM("seg/seg_313E80", func_00415F28);

INCLUDE_ASM("seg/seg_313E80", func_00415F48);
