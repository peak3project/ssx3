#include "common.h"

// defined in seg_313E80 (moved there with the ee-gcc 2.9 split)
extern int func_00414B68(int *p, int flag);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00415F98);
#ifdef SKIP_ASM
void func_00415F98(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00415FB8);
#ifdef SKIP_ASM
extern int D_00454944;
int func_00415FB8(void) {
    return D_00454944;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00415FC8);

INCLUDE_ASM("seg/seg_316F98", func_0041605C);

INCLUDE_ASM("seg/seg_316F98", func_0041610C);

INCLUDE_ASM("seg/seg_316F98", func_00416210);

INCLUDE_ASM("seg/seg_316F98", func_004162D0);

INCLUDE_ASM("seg/seg_316F98", strchr);

INCLUDE_ASM("seg/seg_316F98", func_004165A8);

INCLUDE_ASM("seg/seg_316F98", strcpy);

INCLUDE_ASM("seg/seg_316F98", strlen);

INCLUDE_ASM("seg/seg_316F98", func_00416958);

INCLUDE_ASM("seg/seg_316F98", func_00416B18);

INCLUDE_ASM("seg/seg_316F98", strncpy);

INCLUDE_ASM("seg/seg_316F98", func_00416EB0);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00416F90);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416EB0(int, int, int);
void func_00416F90(int a, int b) {
    func_00416EB0(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00416FC0);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
extern int func_00417418(int, void (*)(void));
void func_00416FC0(int a) {
    func_00417418(a, func_0041FE30);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00416FE0);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416FC0(int);
void func_00416FE0(void) {
    func_00416FC0(D_00454944);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00417008);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00417418);
#ifdef SKIP_ASM
struct G17418 {
    struct G17418 *next;
    int n;
    char *files;
};
int func_00417418(int r_, void (*fn_)(void)) {
    char *r = (char *)r_;
    int (*fn)(char *) = (int (*)(char *))fn_;
    struct G17418 *g;
    char *fp;
    int n;
    int ret = 0;
    for (g = (struct G17418 *)(r + 0x1D8); g; g = g->next) {
        fp = g->files;
        for (n = g->n; --n >= 0; fp += 0x58)
            if (*(short *)(fp + 0xC))
                ret |= fn(fp);
    }
    return ret;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_004174B0);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00417578);
#ifdef SKIP_ASM
#define func_00417578_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern void func_0041B728(int *, int, int, char *);
void func_00417578(int *p, int fmt, ...) {
    char *ap;
    func_00417578_va_start(ap);
    func_0041B728(p, p[2], fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_004175C8);
#ifdef SKIP_ASM
#define func_004175C8_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern int D_00454944;
extern int func_0041B658(int, int, char *);
void func_004175C8(int fmt, ...) {
    char *ap;
    int *g;
    func_004175C8_va_start(ap);
    g = (int *)D_00454944;
    ((int *)g[2])[0x54 / 4] = (int)g;
    func_0041B658(g[2], fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00417628);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
void func_00417628(void) {
    func_0041FE30();
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00417648);

//100%
INCLUDE_ASM("seg/seg_316F98", func_004177B0);
#ifdef SKIP_ASM
#define func_004177B0_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
struct F177B0 {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int pad[0x54 / 4 - 6];
    int ent;
};
void func_004177B0(int reent, char *buf, int fmt, ...) {
    char *ap;
    struct F177B0 f;
    func_004177B0_va_start(ap);
    f.p = buf;
    f.w = 0x7FFFFFFF;
    f.flags = 0x208;
    f.base = buf;
    f.size = 0x7FFFFFFF;
    f.ent = reent;
    func_0041B658((int)&f, fmt, ap);
    *f.p = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", sprintf);
#ifdef SKIP_ASM
#define sprintf_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
struct Fsprintf {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int pad[0x54 / 4 - 6];
    int ent;
};
extern int D_00454944;
void sprintf(char *buf, int fmt, ...) {
    char *ap;
    struct Fsprintf f;
    sprintf_va_start(ap);
    f.p = buf;
    f.w = 0x7FFFFFFF;
    f.flags = 0x208;
    f.base = buf;
    f.size = 0x7FFFFFFF;
    f.ent = D_00454944;
    func_0041B658((int)&f, fmt, ap);
    *f.p = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_004178A8);
#ifdef SKIP_ASM
int func_004178A8(void) {
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_004178B0);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00417948);
#ifdef SKIP_ASM
extern long func_0041FD10(int *, int, int, int);
long func_00417948(int *f, int a, int b) {
    int r = func_0041FD10((int *)f[0x54 / 4], ((short *)f)[7], a, b);
    if (r >= 0) {
        f[0x50 / 4] += r;
    } else {
        ((unsigned short *)f)[6] &= 0xEFFF;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_004179B0);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00417A30);
#ifdef SKIP_ASM
extern long func_0041FC50(int *, int, int, int);
long func_00417A30(int *f, int a, int b) {
    long r = func_0041FC50((int *)f[0x54 / 4], ((short *)f)[7], a, b);
    unsigned short *p = (unsigned short *)f + 6;
    if (r == -1) {
        *p &= 0xEFFF;
    } else {
        f[0x50 / 4] = r;
        *p |= 0x1000;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00417A98);
#ifdef SKIP_ASM
extern int func_0041FB98(int, int);
void func_00417A98(int *p) {
    func_0041FB98(p[0x54 / 4], ((short *)p)[7]);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00417AB8);

INCLUDE_ASM("seg/seg_316F98", func_004185D0);

//100%
INCLUDE_ASM("seg/seg_316F98", func_004186C8);
#ifdef SKIP_ASM
struct Fvsprintf {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int pad[0x54 / 4 - 6];
    int ent;
};
extern int D_00454944;
extern int func_0041B658(int, int, char *);
void func_004186C8(char *buf, int fmt, char *ap) {
    struct Fvsprintf f;
    f.p = buf;
    f.w = 0x7FFFFFFF;
    f.flags = 0x208;
    f.base = buf;
    f.size = 0x7FFFFFFF;
    f.ent = D_00454944;
    func_0041B658((int)&f, fmt, ap);
    *f.p = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418720);
#ifdef SKIP_ASM
struct F18720 {
    char *p;
    int r;
    unsigned w;
    short flags, file;
    char *base;
    unsigned size;
    int pad[0x54 / 4 - 6];
    int ent;
};
extern int D_00454944;
int func_00418720(char *buf, unsigned n, int fmt, char *ap) {
    struct F18720 f;
    int r;
    f.p = buf;
    f.w = n;
    f.flags = 0x208;
    f.base = buf;
    f.size = n;
    f.ent = D_00454944;
    r = func_0041B658((int)&f, fmt, ap);
    if (n < (unsigned)r) r = -1;
    *f.p = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418790);
#ifdef SKIP_ASM
void func_001001C8(int) __attribute__((noreturn));
void func_00418790(void) {
    func_001001C8(1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_004187A0);
#ifdef SKIP_ASM
extern void func_0041A7E8(int, int);
void func_004187A0(int a) {
    func_0041A7E8(a, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_004187C0);
#ifdef SKIP_ASM
extern long func_0041E9E0(int, int, int);
int func_004187C0(int a) {
    return func_0041E9E0(a, 0, 10);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_004187E8);

//100%
INCLUDE_ASM("seg/seg_316F98", func_004188C0);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00418CA8(int);
extern void func_00418D08(int);
extern int func_0041DBF8(int, int);
int func_004188C0(int a) {
    int r;
    func_00418CA8(D_00454944);
    r = func_0041DBF8(D_00454944, a);
    func_00418D08(D_00454944);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418910);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00418CA8(int);
extern void func_00418D08(int);
extern void func_0041E340(int, int);
void func_00418910(int a) {
    func_00418CA8(D_00454944);
    func_0041E340(D_00454944, a);
    func_00418D08(D_00454944);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00418958);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418CA8);
#ifdef SKIP_ASM
extern int func_00423C90(void);
extern void func_00423DE0(int);
extern int D_00454CA8;
extern int D_00454CAC;
extern int D_00455248;
void func_00418CA8(int unused) {
    int id = func_00423C90();
    if (D_00454CA8 == id) {
        D_00454CAC++;
    } else {
        func_00423DE0(D_00455248);
        D_00454CA8 = id;
        D_00454CAC++;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418D08);
#ifdef SKIP_ASM
extern void func_00423DC0(int);
extern int D_00454CA8;
extern int D_00454CAC;
extern int D_00455248;
void func_00418D08(int unused) {
    if (--D_00454CAC == 0) {
        D_00454CA8 = -1;
        func_00423DC0(D_00455248);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418D48);
#ifdef SKIP_ASM
extern void func_004218D8(int, int, int, int, int);
void func_00418D48(int a, int b, int c, int d) {
    func_004218D8(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418D68);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418D48(int, int, int, int);
void func_00418D68(int a, int b, int c) {
    func_00418D48(func_00413AF8(), a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418DB8);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern int func_00418E68(int, int, int);
void func_00418DB8(int a, int b) {
    func_00418E68(func_00413AF8(), a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418DF8);
#ifdef SKIP_ASM
extern void func_00421A50(int, int, int, int, int);
void func_00418DF8(int a, int b, int c, int d) {
    func_00421A50(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418E18);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418DF8(int, int, int, int);
void func_00418E18(int a, int b, int c) {
    func_00418DF8(func_00413AF8(), a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_00418E68);
#ifdef SKIP_ASM
extern int D_00454944;
extern int func_00412500(int, int);
extern int func_00421B98(int, int, int, char *, int, int);
int func_00418E68(int a, int prec, int buf_) {
    char *buf = (char *)buf_;
    char *p = buf;
    if (func_00412500(a, 0) < 0) {
        *p++ = '-';
        prec--;
    }
    return func_00421B98(D_00454944, a, prec, p, 'g', 0) ? (int)buf : 0;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00418EF8);

INCLUDE_ASM("seg/seg_316F98", func_004198D8);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041A7E8);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_004198D8(int, int, int);
void func_0041A7E8(int a, int b) {
    func_004198D8(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041A818);
#ifdef SKIP_ASM
extern void func_004127A8(int);
void func_0041A818(void) {
    func_004127A8(((int (*)(void))func_0041A7E8)());
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041A840);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041AA50);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041A840(int, int, int, int);
void func_0041AA50(int a, int b, int c) {
    func_0041A840(D_00454944, a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041AA88);
#ifdef SKIP_ASM
int func_0041AA88(char *a, char *b) {
    while (*a && func_0041EA18(*a) == func_0041EA18(*b)) {
        a++;
        b++;
    }
    return func_0041EA18((unsigned char)*a) - func_0041EA18((unsigned char)*b);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041AB08);

INCLUDE_ASM("seg/seg_316F98", func_0041AB78);

INCLUDE_ASM("seg/seg_316F98", func_0041AC40);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041ACC0);
#ifdef SKIP_ASM
char *func_0041ACC0(char *s, char c) {
    char *r = 0;
    while (*s) {
        if (*s == c) r = s;
        s++;
    }
    return *s == c ? s : r;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041AD10);

INCLUDE_ASM("seg/seg_316F98", func_0041AD80);

INCLUDE_ASM("seg/seg_316F98", func_0041AE00);

INCLUDE_ASM("seg/seg_316F98", func_0041AE70);

INCLUDE_ASM("seg/seg_316F98", func_0041AEE8);

INCLUDE_ASM("seg/seg_316F98", func_0041AF88);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041B528);
#ifdef SKIP_ASM
extern void func_0041B550(int, int, int, int);
void func_0041B528(short *p) {
    func_0041B550(p[7], 0, 0, 2);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041B550);

INCLUDE_ASM("seg/seg_316F98", func_0041B658);

INCLUDE_ASM("seg/seg_316F98", func_0041B728);

INCLUDE_ASM("seg/seg_316F98", func_0041C788);

INCLUDE_ASM("seg/seg_316F98", func_0041C938);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041CA40);
#ifdef SKIP_ASM
extern void func_0041CA70(int, int *, int, int);
void func_0041CA40(int *p, int b, int c) {
    func_0041CA70(p[21], p, b, c);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041CA70);

INCLUDE_ASM("seg/seg_316F98", func_0041D990);

INCLUDE_ASM("seg/seg_316F98", func_0041DBF8);

INCLUDE_ASM("seg/seg_316F98", func_0041E340);

INCLUDE_ASM("seg/seg_316F98", func_0041E638);

INCLUDE_ASM("seg/seg_316F98", func_0041E7A8);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041E9E0);
#ifdef SKIP_ASM
extern int D_00454944;
extern long func_0041E7A8(int, int, int, int);
long func_0041E9E0(int s, int end, int base) {
    return func_0041E7A8(D_00454944, s, end, base);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041EA18);
#ifdef SKIP_ASM
extern char D_00499C81[];
int func_0041EA18(int a) {
    return (D_00499C81[a] & 1) ? a + 0x20 : a;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041EA38);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041EC08);
#ifdef SKIP_ASM
extern char D_0049A790[];
char *func_0041EC08(void) {
    return D_0049A790;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041EC18);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041EA38(int, int, int);
void func_0041EC18(int a, int b) {
    func_0041EA38(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041EC48);
#ifdef SKIP_ASM
extern int D_00454944;
void func_0041EC48(void) {
    ((char *(*)(int))func_0041EC08)(D_00454944);
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041EC70);

INCLUDE_ASM("seg/seg_316F98", func_0041ED60);

INCLUDE_ASM("seg/seg_316F98", func_0041EF50);

INCLUDE_ASM("seg/seg_316F98", func_0041F3A8);

INCLUDE_ASM("seg/seg_316F98", func_0041F9D8);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FB98);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424488(int);
int func_0041FB98(int err, int a) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424488(a);
    if (r == -1 && D_004A5BB8)
        *(int *)err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FBF0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424558(int, int);
int func_0041FBF0(int *err, int a, int b) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424558(a, b);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FC50);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424498(int, int, int);
long func_0041FC50(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424498(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FCB0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424460(int, int, int);
int func_0041FCB0(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424460(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FD10);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_004243E8(int, int, int);
long func_0041FD10(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_004243E8(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FD70);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern unsigned func_004244A0(int);
unsigned func_0041FD70(int *err, int a) {
    unsigned r;
    D_004A5BB8 = 0;
    r = func_004244A0(a);
    if (r == 0xFFFFFFFF && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FDD0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424368(int, int, int);
long func_0041FDD0(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424368(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_0041FE30);

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FF40);
#ifdef SKIP_ASM
struct F41FF40 {
    int p, r, w;
    short flags, file;
    int base, size_, lbf;
    int cookie;
    void *rd, *wr, *sk, *cl;
    int pad[0x54 / 4 - 12];
    int ent;
};
extern long func_00417948(), func_004179B0(), func_00417A30();
void func_0041FF40(struct F41FF40 *f, short flags, short file, int ent) {
    f->p = 0;
    f->r = 0;
    f->w = 0;
    f->flags = flags;
    f->file = file;
    f->base = 0;
    f->lbf = 0;
    f->cookie = (int)f;
    f->rd = func_00417948;
    f->wr = func_004179B0;
    f->sk = func_00417A30;
    f->cl = (void *)func_00417A98;
    f->ent = ent;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316F98", func_0041FF98);
#ifdef SKIP_ASM
extern void *func_00416210(void *, int, int);
int *func_0041FF98(int a, int cnt) {
    int sz = cnt * 0x58;
    int *p = (int *)func_0041DBF8(a, sz + 0xC);
    if (!p)
        return 0;
    p[1] = cnt;
    p[0] = 0;
    p[2] = (int)(p + 3);
    func_00416210(p + 3, 0, sz);
    return p;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00420010);

//100%
INCLUDE_ASM("seg/seg_316F98", func_004200F0);
#ifdef SKIP_ASM
void func_004200F0(char *r) {
    char *f0 = r + 0x1E4;
    *(void **)(r + 0x3C) = (void *)func_00416FC0;
    *(int *)(r + 0x38) = 1;
    func_0041FF40((void *)f0, 4, 0, (int)r);
    func_0041FF40((void *)(r + 0x23C), 9, 1, (int)r);
    func_0041FF40((void *)(r + 0x294), 0xA, 2, (int)r);
    *(char **)(r + 0x1E0) = f0;
    *(int *)(r + 0x1DC) = 3;
    *(int *)(r + 0x1D8) = 0;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00420180);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00420228);
#ifdef SKIP_ASM
void func_00420228(char *d, char *s, unsigned n) {
    while (n--)
        *d++ = *s++;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00420260);

INCLUDE_ASM("seg/seg_316F98", ungetc);

INCLUDE_ASM("seg/seg_316F98", func_00420510);

//100%
INCLUDE_ASM("seg/seg_316F98", func_004205B8);
#ifdef SKIP_ASM
void func_004205B8(int *self, int *p) {
    if (p) {
        int i = p[1];
        p[0] = ((int *)self[0x4C / 4])[i];
        ((int **)self[0x4C / 4])[i] = p;
    }
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_004205F0);

INCLUDE_ASM("seg/seg_316F98", func_004206F8);

INCLUDE_ASM("seg/seg_316F98", func_00420830);

INCLUDE_ASM("seg/seg_316F98", func_004208B8);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00420978);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
int *func_00420978(int a, int b) {
    int *p = func_00420510(a, 1);
    p[5] = b;
    p[4] = 1;
    return p;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_004209B0);

INCLUDE_ASM("seg/seg_316F98", func_00420BC8);

INCLUDE_ASM("seg/seg_316F98", func_00420CC8);

//100%
INCLUDE_ASM("seg/seg_316F98", func_00420E28);
#ifdef SKIP_ASM
struct Bigint28 {
    struct Bigint28 *next;
    int k, maxwds, sign, wds;
    unsigned x[1];
};
int func_00420E28(struct Bigint28 *a, struct Bigint28 *b) {
    unsigned *xa, *xa0, *xb, *xb0;
    int i, j;
    i = a->wds;
    j = b->wds;
    if (i -= j)
        return i;
    xa0 = a->x;
    xa = xa0 + j;
    xb0 = b->x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb)
            return *xa < *xb ? -1 : 1;
        if (xa <= xa0)
            break;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_316F98", func_00420E90);

INCLUDE_ASM("seg/seg_316F98", func_00421020);

INCLUDE_ASM("seg/seg_316F98", func_004210E8);

INCLUDE_ASM("seg/seg_316F98", func_00421280);

INCLUDE_ASM("seg/seg_316F98", func_00421400);

INCLUDE_ASM("seg/seg_316F98", func_004214C0);

INCLUDE_ASM("seg/seg_316F98", func_00421530);

INCLUDE_ASM("seg/seg_316F98", func_004216E8);

INCLUDE_ASM("seg/seg_316F98", func_004218D8);

INCLUDE_ASM("seg/seg_316F98", func_00421A50);

INCLUDE_ASM("seg/seg_316F98", func_00421B98);

INCLUDE_ASM("seg/seg_316F98", func_00421E60);

INCLUDE_ASM("seg/seg_316F98", func_00421F20);

INCLUDE_ASM("seg/seg_316F98", func_004224A0);

INCLUDE_ASM("seg/seg_316F98", func_00422560);

INCLUDE_ASM("seg/seg_316F98", func_00422780);

INCLUDE_ASM("seg/seg_316F98", func_00423980);

INCLUDE_ASM("seg/seg_316F98", func_00423990);
