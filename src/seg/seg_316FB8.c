#include "common.h"

// PORT: PS2 kernel syscall stub: the syscall number goes in $3. Defined under a second C name with an
// asm label because this file declares these symbols with their argument lists elsewhere.
#define SYSCALL_STUB(name, n) \
    void name##_syscall(void) __asm__(#name); \
    void name##_syscall(void) { register int v __asm__("$3") = (n); __asm__ volatile("syscall" : : "r"(v)); }

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00415FB8);
#ifdef SKIP_ASM
extern int D_00454944;
int func_00415FB8(void) {
    return D_00454944;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_00415FC8);

INCLUDE_ASM("seg/seg_316FB8", func_0041605C);

INCLUDE_ASM("seg/seg_316FB8", func_0041610C);

INCLUDE_ASM("seg/seg_316FB8", func_00416210);

INCLUDE_ASM("seg/seg_316FB8", func_004162D0);

INCLUDE_ASM("seg/seg_316FB8", strchr);

INCLUDE_ASM("seg/seg_316FB8", func_004165A8);

INCLUDE_ASM("seg/seg_316FB8", strcpy);

INCLUDE_ASM("seg/seg_316FB8", strlen);

INCLUDE_ASM("seg/seg_316FB8", func_00416958);

INCLUDE_ASM("seg/seg_316FB8", func_00416B18);

INCLUDE_ASM("seg/seg_316FB8", strncpy);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416EB0);
#ifdef SKIP_ASM
extern int func_00420180(int, char *, int *);
extern char *func_00420010(int);
extern int func_0041FCB0(int *, int, int, int);
extern long func_00417948(), func_004179B0(), func_00417A30();
extern void func_00417A98();
extern long func_00417008(char *, int, int);
char *func_00416EB0_(int ptr, char *file, char *mode) __asm__("func_00416EB0");
char *func_00416EB0_(int ptr, char *file, char *mode) {
    char *fp;
    int f, flags, oflags;
    if ((flags = func_00420180(ptr, mode, &oflags)) == 0)
        return 0;
    if ((fp = func_00420010(ptr)) == 0)
        return 0;
    if ((f = func_0041FCB0(*(int **)(fp + 0x54), (int)file, oflags, 0x1B6)) < 0) {
        *(short *)(fp + 0xC) = 0;
        return 0;
    }
    *(short *)(fp + 0xE) = f;
    *(short *)(fp + 0xC) = flags;
    *(char **)(fp + 0x1C) = fp;
    *(void **)(fp + 0x20) = func_00417948;
    *(void **)(fp + 0x24) = func_004179B0;
    *(void **)(fp + 0x28) = func_00417A30;
    *(void **)(fp + 0x2C) = func_00417A98;
    if (flags & 0x100)
        func_00417008(fp, 0, 2);
    return fp;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416F90);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416EB0(int, int, int);
void func_00416F90(int a, int b) {
    func_00416EB0(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416FC0);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
extern int func_00417418(int, void (*)(void));
void func_00416FC0(int a) {
    func_00417418(a, func_0041FE30);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416FE0);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416FC0(int);
void func_00416FE0(void) {
    func_00416FC0(D_00454944);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417008);
#ifdef SKIP_ASM
struct R17008 {
    int err;
    char pad[0x38 - 4];
    int didinit;
};
struct F17008 {
    unsigned char *p;
    int r;
    int w;
    unsigned short flags;
    short file;
    unsigned char *base;
    int size;
    int lbfsize;
    int cookie;
    int pad20[2];
    long (*seek)(int, long, int);
    int pad2C;
    unsigned char *ubbase;
    int ubsize;
    unsigned char *up;
    int ur;
    char pad40[0x4C - 0x40];
    int blksize;
    int offset;
    struct R17008 *data;
};
extern struct R17008 *g17008_impure __asm__("D_00454944");
extern void g17008_init(struct R17008 *) __asm__("func_004200F0");
extern int g17008_fflush(struct F17008 *) __asm__("func_0041FE30");
extern int g17008_fstat(struct R17008 *, int, int *) __asm__("func_0041FBF0");
extern long g17008_sseek(int, long, int) __asm__("func_00417A30");
extern void g17008_smakebuf(struct F17008 *) __asm__("func_004174B0");
extern int g17008_srefill(struct F17008 *) __asm__("func_00417648");
int func_00417008_(struct F17008 *fp, long offset, int whence) __asm__("func_00417008");
int func_00417008_(struct F17008 *fp, long offset, int whence) {
    long (*seekfn)(int, long, int);
    long target, curoff;
    unsigned n;
    int st[0x68 / 4];
    int havepos;
    struct R17008 *ptr;
    if (fp->data == 0)
        fp->data = g17008_impure;
    if (fp->data->didinit == 0)
        g17008_init(fp->data);
    ptr = fp->data;
    if ((*(int *)&fp->flags & 0x108) == 0x108)
        g17008_fflush(fp);
    if ((seekfn = fp->seek) == 0) {
        ptr->err = 0x1D;
        return -1;
    }
    switch (whence) {
    case 1:
        g17008_fflush(fp);
        if (fp->flags & 0x1000)
            curoff = fp->offset;
        else {
            curoff = (*seekfn)(fp->cookie, 0, 1);
            if (curoff == -1)
                return -1;
        }
        if (fp->flags & 4) {
            curoff -= fp->r;
            if (fp->ubbase)
                curoff -= fp->ur;
        } else if (fp->flags & 8 && fp->p != 0)
            curoff += fp->p - fp->base;
        offset += curoff;
        whence = 0;
        havepos = 1;
        break;
    case 0:
    case 2:
        havepos = 0;
        break;
    default:
        ptr->err = 0x16;
        return -1;
    }
    if (fp->base == 0)
        g17008_smakebuf(fp);
    if (fp->flags & 0x81A)
        goto dumb;
    if ((fp->flags & 0x400) == 0) {
        if (seekfn != g17008_sseek || fp->file < 0 || g17008_fstat(ptr, fp->file, st) ||
            (st[1] & 0xF000) != 0x8000) {
            fp->flags |= 0x800;
            goto dumb;
        }
        fp->blksize = 0x400;
        fp->flags |= 0x400;
    }
    if (whence == 0)
        target = offset;
    else {
        if (g17008_fstat(ptr, fp->file, st))
            goto dumb;
        target = *(long *)&st[4] + offset;
    }
    if (!havepos) {
        if (fp->flags & 0x1000)
            curoff = fp->offset;
        else {
            curoff = (*seekfn)(fp->cookie, 0, 1);
            if (curoff == -1)
                goto dumb;
        }
        curoff -= fp->r;
        if (fp->ubbase)
            curoff -= fp->ur;
    }
    if (fp->ubbase) {
        curoff += fp->r;
        n = fp->up - fp->base;
        curoff -= n;
        n += fp->ur;
    } else {
        n = fp->p - fp->base;
        curoff -= n;
        n += fp->r;
    }
    if ((fp->flags & 0x2000) == 0 && target >= curoff && target < curoff + n) {
        int o = target - curoff;
        fp->p = fp->base + o;
        fp->r = n - o;
        fp->flags &= ~0x20;
        return 0;
    }
    curoff = target & -fp->blksize;
    if ((*seekfn)(fp->cookie, curoff, 0) == -1)
        goto dumb;
    fp->r = 0;
    fp->flags &= ~0x20;
    n = target - curoff;
    if (n) {
        if (g17008_srefill(fp) || fp->r < n)
            goto dumb;
        fp->p += n;
        fp->r -= n;
    }
    return 0;
dumb:
    if (g17008_fflush(fp) || (*seekfn)(fp->cookie, offset, whence) == -1)
        return -1;
    fp->p = fp->base;
    fp->r = 0;
    fp->flags &= ~0x20;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417418);
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

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004174B0);
#ifdef SKIP_ASM
struct F174B0 {
    char *p;
    int r;
    int w;
    unsigned short flags;
    short file;
    char *base;
    int size;
    char pad1[0x28 - 0x18];
    void *seek;
    char pad2[0x43 - 0x2C];
    char nbuf[9];
    int blksize;
    int offset;
    int data;
};
extern long func_00417A30();
extern int func_0041FBF0(int *, int, int);
void func_004174B0(struct F174B0 *f) {
    int st[0x68 / 4];
    if (f->flags & 2) {
        f->p = f->nbuf;
        f->base = f->nbuf;
        f->size = 1;
        return;
    }
    if (f->file < 0 || func_0041FBF0((int *)f->data, f->file, (int)st) < 0) {
        f->flags |= 0x800;
    } else if ((st[1] & 0xF000) == 0x8000 && f->seek == (void *)func_00417A30) {
        f->blksize = 0x400;
        f->flags |= 0x400;
    } else {
        f->flags |= 0x800;
    }
    f->flags |= 2;
    f->size = 1;
    f->p = f->nbuf;
    f->base = f->nbuf;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417578);
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
INCLUDE_ASM("seg/seg_316FB8", func_004175C8);
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
INCLUDE_ASM("seg/seg_316FB8", func_00417628);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
void func_00417628(void) {
    func_0041FE30();
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417648);
#ifdef SKIP_ASM
struct R7648 {
    int err;
    char pad[0x38 - 4];
    int didinit;
};
struct F7648 {
    unsigned char *p;
    int r;
    int w;
    unsigned short flags;
    short file;
    unsigned char *base;
    int size;
    int lbfsize;
    int cookie;
    int (*rd)(int, unsigned char *, int);
    int pad24;
    int pad28;
    int pad2C;
    unsigned char *ubbase;
    int ubsize;
    unsigned char *up;
    int ur;
    char pad40[0x54 - 0x40];
    struct R7648 *data;
};
extern struct R7648 *g7648_impure __asm__("D_00454944");
extern void g7648_init(struct R7648 *) __asm__("func_004200F0");
extern int g7648_fflush(struct F7648 *) __asm__("func_0041FE30");
extern void g7648_smakebuf(struct F7648 *) __asm__("func_004174B0");
extern int g7648_fwalk(struct R7648 *, void *) __asm__("func_00417418");
extern void g7648_lflush(void) __asm__("func_00417628");
int func_00417648_impl(struct F7648 *fp) __asm__("func_00417648");
int func_00417648_impl(struct F7648 *fp) {
    int n;
    do {
        if (fp->data == 0)
            fp->data = g7648_impure;
        if (fp->data->didinit == 0)
            g7648_init(fp->data);
    } while (0);
    fp->r = 0;
    if (fp->flags & 0x20)
        return -1;
    if ((fp->flags & 4) == 0) {
        if ((fp->flags & 0x10) == 0)
            return -1;
        if (fp->flags & 8) {
            if (g7648_fflush(fp))
                return -1;
            fp->flags &= ~8;
            fp->w = 0;
            fp->lbfsize = 0;
        }
        fp->flags |= 4;
    } else if (fp->ubbase != 0) {
        if ((fp->r = fp->ur) != 0) {
            fp->p = fp->up;
            return 0;
        }
    }
    if (fp->base == 0)
        g7648_smakebuf(fp);
    if (fp->flags & 3)
        g7648_fwalk(fp->data, g7648_lflush);
    fp->p = fp->base;
    n = fp->rd(fp->cookie, fp->base, fp->size);
    fp->r = n;
    fp->flags &= ~0x2000;
    if (n <= 0) {
        if (n == 0) {
            fp->flags |= 0x20;
        } else {
            fp->r = 0;
            fp->flags |= 0x40;
        }
        return -1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004177B0);
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
INCLUDE_ASM("seg/seg_316FB8", sprintf);
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
INCLUDE_ASM("seg/seg_316FB8", func_004178A8);
#ifdef SKIP_ASM
int func_004178A8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004178B0);
#ifdef SKIP_ASM
#define func_004178B0_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
struct F178B0 {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int lbfsize;
    int cookie;
    int (*read)(void);
    int pad1[3];
    int ubbase;
    int pad2[0x44 / 4 - 0x34 / 4];
    int lbbase;
    int pad3[0x54 / 4 - 0x48 / 4];
    int ent;
};
extern int strlen(char *);
extern int D_00454944;
extern int func_00417AB8(struct F178B0 *, int, char *);
int func_004178B0(char *str, int fmt, ...) {
    char *ap;
    struct F178B0 f;
    f.flags = 4;
    f.p = str;
    f.base = str;
    f.size = f.r = strlen(str);
    f.read = func_004178A8;
    f.ubbase = 0;
    f.lbbase = 0;
    f.ent = D_00454944;
    func_004178B0_va_start(ap);
    return func_00417AB8(&f, fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417948);
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

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004179B0);
#ifdef SKIP_ASM
extern long func_0041FDD0(int *, int, int, int);
int func_004179B0_(int *f, int a, int b) __asm__("func_004179B0");
int func_004179B0_(int *f, int a, int b) {
    if (((unsigned short *)f)[6] & 0x100)
        func_0041FC50((int *)f[0x54 / 4], ((short *)f)[7], 0, 2);
    ((unsigned short *)f)[6] &= 0xEFFF;
    return func_0041FDD0((int *)f[0x54 / 4], ((short *)f)[7], a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417A30);
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
INCLUDE_ASM("seg/seg_316FB8", func_00417A98);
#ifdef SKIP_ASM
extern int func_0041FB98(int, int);
void func_00417A98(int *p) {
    func_0041FB98(p[0x54 / 4], ((short *)p)[7]);
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_00417AB8);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004185D0);
#ifdef SKIP_ASM
char *func_004185D0(char *tab, char *fmt) {
    int c, n, v;
    c = *fmt++;
    if (c == '^') {
        v = 1;
        c = *fmt++;
    } else
        v = 0;
    for (n = 0; n < 256; n++)
        tab[n] = v;
    if (c == 0)
        return fmt - 1;
    v = 1 - v;
    for (;;) {
        tab[c] = v;
    doswitch:
        n = *fmt++;
        switch (n) {
        case 0:
            return fmt - 1;
        case '-':
            n = *fmt;
            if (n == ']' || n < c) {
                c = '-';
                break;
            }
            fmt++;
            do {
                tab[++c] = v;
            } while (c < n);
            goto doswitch;
            break;
        case ']':
            return fmt;
        default:
            c = n;
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004186C8);
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
INCLUDE_ASM("seg/seg_316FB8", func_00418720);
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
INCLUDE_ASM("seg/seg_316FB8", func_00418790);
#ifdef SKIP_ASM
void func_001001C8(int) __attribute__((noreturn));
void func_00418790(void) {
    func_001001C8(1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004187A0);
#ifdef SKIP_ASM
extern void func_0041A7E8(int, int);
void func_004187A0(int a) {
    func_0041A7E8(a, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004187C0);
#ifdef SKIP_ASM
extern long func_0041E9E0(int, int, int);
int func_004187C0(int a) {
    return func_0041E9E0(a, 0, 10);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004187E8);
#ifdef SKIP_ASM
void *func_004187E8(void *key, char *base, unsigned nmemb, unsigned size, int (*compar)(void *, void *)) {
    unsigned lo = 0, hi = nmemb, mid;
    char *p;
    int c;
    if (nmemb == 0 || size == 0)
        return 0;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        p = base + mid * size;
        c = compar(key, p);
        if (c < 0)
            hi = mid;
        else if (c > 0)
            lo = mid + 1;
        else
            return p;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004188C0);
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
INCLUDE_ASM("seg/seg_316FB8", func_00418910);
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

INCLUDE_ASM("seg/seg_316FB8", func_00418958);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418CA8);
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
INCLUDE_ASM("seg/seg_316FB8", func_00418D08);
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
INCLUDE_ASM("seg/seg_316FB8", func_00418D48);
#ifdef SKIP_ASM
extern void func_004218D8(int, int, int, int, int);
void func_00418D48(int a, int b, int c, int d) {
    func_004218D8(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418D68);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418D48(int, int, int, int);
void func_00418D68(int a, int b, int c) {
    func_00418D48(func_00413AF8(), a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418DB8);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern int func_00418E68(int, int, int);
void func_00418DB8(int a, int b) {
    func_00418E68(func_00413AF8(), a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418DF8);
#ifdef SKIP_ASM
extern void func_00421A50(int, int, int, int, int);
void func_00418DF8(int a, int b, int c, int d) {
    func_00421A50(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418E18);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418DF8(int, int, int, int);
void func_00418E18(int a, int b, int c) {
    func_00418DF8(func_00413AF8(), a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418E68);
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

INCLUDE_ASM("seg/seg_316FB8", func_00418EF8);

INCLUDE_ASM("seg/seg_316FB8", func_004198D8);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041A7E8);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_004198D8(int, int, int);
void func_0041A7E8(int a, int b) {
    func_004198D8(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041A818);
#ifdef SKIP_ASM
extern void func_004127A8(int);
void func_0041A818(void) {
    func_004127A8(((int (*)(void))func_0041A7E8)());
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041A840);
#ifdef SKIP_ASM
extern char D_00499C81[];
extern long func_00411538_div(long, long) __asm__("func_00411538");
extern long func_004114D0_mul(long, long) __asm__("func_004114D0");
extern long func_0042DAD8_mod(long, long) __asm__("func_0042DAD8");
#define XCT(c) (D_00499C81[(int)(c)])
unsigned long func_0041A840_(int *ptr, char *nptr, char **endptr, int base) __asm__("func_0041A840");
unsigned long func_0041A840_(int *ptr, char *nptr, char **endptr, int base) {
    char *s = nptr;
    unsigned long acc, cutoff;
    int c, neg = 0, any, cutlim;
    do {
        c = *s++;
    } while (XCT(c) & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = func_00411538_div(-1, base);
    cutlim = func_0042DAD8_mod(-1, base);
    for (acc = 0, any = 0;; c = *s++) {
        if (XCT(c) & 4)
            c -= '0';
        else if (XCT(c) & 3)
            c -= (XCT(c) & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc = func_004114D0_mul(acc, base);
            acc += c;
        }
    }
    if (any < 0) {
        acc = -1;
        *ptr = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = any ? s - 1 : nptr;
    return acc;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AA50);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041A840(int, int, int, int);
void func_0041AA50(int a, int b, int c) {
    func_0041A840(D_00454944, a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AA88);
#ifdef SKIP_ASM
int func_0041AA88(char *a, char *b) {
    while (*a && func_0041EA18(*a) == func_0041EA18(*b)) {
        a++;
        b++;
    }
    return func_0041EA18((unsigned char)*a) - func_0041EA18((unsigned char)*b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AB08);
#ifdef SKIP_ASM
int func_0041AB08(char *s1, char *s2) {
    char *s = s1;
    char *c;
    while (*s1) {
        for (c = s2; *c; c++)
            if (*s1 == *c)
                break;
        if (*c)
            break;
        s1++;
    }
    return s1 - s;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AB78);
#ifdef SKIP_ASM
extern int func_0041EA18(int);
int func_0041AB78(char *s1, char *s2, unsigned n) {
    if (n == 0)
        return 0;
    while (n-- != 0 && func_0041EA18(*s1) == func_0041EA18(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
    }
    return func_0041EA18(*(unsigned char *)s1) - func_0041EA18(*(unsigned char *)s2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AC40);
#ifdef SKIP_ASM
char *func_0041AC40(char *s, char *accept) {
    char *p;
    if (*s == 0)
        return 0;
    for (; *s; s++) {
        for (p = accept; *p && *s != *p; p++)
            ;
        if (*p)
            break;
    }
    return *p ? s : 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041ACC0);
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

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AD10);
#ifdef SKIP_ASM
int func_0041AD10(char *s1, char *s2) {
    char *s = s1;
    char *c;
    while (*s1) {
        for (c = s2; *c; c++)
            if (*s1 == *c)
                break;
        if (*c == 0)
            break;
        s1++;
    }
    return s1 - s;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_0041AD80);

INCLUDE_ASM("seg/seg_316FB8", func_0041AE00);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AE70);
#ifdef SKIP_ASM
char *func_0041AE70(char *s) {
    int i, j;
    char t;
    j = 0;
    while (s[j])
        j++;
    j--;
    for (i = 0; i < j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    return s;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_0041AEE8);

INCLUDE_ASM("seg/seg_316FB8", func_0041AF88);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041B528);
#ifdef SKIP_ASM
extern void func_0041B550(int, int, int, int);
void func_0041B528(short *p) {
    func_0041B550(p[7], 0, 0, 2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041B550);
#ifdef SKIP_ASM
extern char *D_00454CDC;
extern int D_00454CD8;
extern char D_0052AE98[];
extern int func_00424368(int, int, int);
int func_0041B550_(int fd, char *buf, unsigned n, int mode) __asm__("func_0041B550");
int func_0041B550_(int fd, char *buf, unsigned n, int mode) {
    unsigned i;
    int r;
    if (mode == 1) {
        r = func_00424368(fd, (int)D_0052AE98, D_00454CD8);
        D_00454CD8 = 0;
        D_00454CDC = D_0052AE98;
        return r;
    }
    for (i = 0; i < n; i++) {
        *D_00454CDC = buf[i];
        D_00454CDC++;
        D_00454CD8++;
        if (D_00454CD8 >= 128) {
            r = func_00424368(fd, (int)D_0052AE98, D_00454CD8);
            D_00454CDC = D_0052AE98;
            D_00454CD8 = 0;
            if (r == 0)
                return 0;
        }
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041B658);
#ifdef SKIP_ASM
extern int func_0041B728_f(int, int, char *, char *) __asm__("func_0041B728");
extern int func_0041CA70_i(int, int, char *, char *) __asm__("func_0041CA70");
int func_0041B658(int fp, int fmt, char *ap) {
    char *p = (char *)fmt;
    while (*p) {
        if (*p == '%' && p[1]) {
            p++;
            while (*p < 'A' && p[1])
                p++;
            switch (*p) {
            case 'E':
            case 'G':
            case 'L':
            case 'e':
            case 'f':
            case 'g':
                return func_0041B728_f(*(int *)(fp + 0x54), fp, (char *)fmt, ap);
            }
        }
        p++;
    }
    return func_0041CA70_i(*(int *)(fp + 0x54), fp, (char *)fmt, ap);
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_0041B728);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041C788);
#ifdef SKIP_ASM
extern void *g_c788_memcpy(void *, const void *, unsigned) __asm__("func_0041605C");
char *func_0041C788_impl(char *dest, char *start, char *end, int *outlen) __asm__("func_0041C788");
char *func_0041C788_impl(char *dest, char *start, char *end, int *outlen) {
    int len = end - start + 10;
    char *buf = __builtin_alloca(len);
    char *w = buf + len - 1;
    int cnt = 0;
    int st[2];
    char *p;
    if (dest == 0 || start == 0 || end == 0) return 0;
    st[0] = 0;
    st[1] = (int)end;
    p = start;
    if (!(end < p)) {
        do {
            switch (*p) {
            case '.':
                st[1] = (int)p;
                if (st[0] == 0) st[0] = 1;
                break;
            case 'E':
            case 'e':
                st[0] = 2;
                break;
            }
            p++;
        } while (!(end < p) && st[0] != 2);
    }
    if (st[0] == 2) return start;
    p = end;
    if (start < p) {
        do {
            *w = *p;
            w--;
            if (!((char *)st[1] < p)) {
                if (cnt % 3 == 0 && cnt != 0) {
                    *w = ',';
                    len++;
                    w--;
                }
                cnt++;
            }
            p--;
        } while (start < p);
    }
    *w = *p;
    len -= 10;
    g_c788_memcpy(dest, w, len);
    *outlen = len;
    return dest;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041C938);
#ifdef SKIP_ASM
extern char *D_00454CE4;
extern int D_00454CE0;
extern char D_0052AF18[];
int func_0041C938_(int fd, char *buf, unsigned n, int mode) __asm__("func_0041C938");
int func_0041C938_(int fd, char *buf, unsigned n, int mode) {
    unsigned i;
    int r;
    if (mode == 1) {
        r = func_00424368(fd, (int)D_0052AF18, D_00454CE0);
        D_00454CE0 = 0;
        D_00454CE4 = D_0052AF18;
        return r;
    }
    for (i = 0; i < n; i++) {
        *D_00454CE4 = buf[i];
        D_00454CE4++;
        D_00454CE0++;
        if (D_00454CE0 >= 128) {
            r = func_00424368(fd, (int)D_0052AF18, D_00454CE0);
            D_00454CE4 = D_0052AF18;
            D_00454CE0 = 0;
            if (r == 0)
                return 0;
        }
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041CA40);
#ifdef SKIP_ASM
extern void func_0041CA70(int, int *, int, int);
void func_0041CA40(int *p, int b, int c) {
    func_0041CA70(p[21], p, b, c);
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_0041CA70);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041D990);
#ifdef SKIP_ASM
struct mchunk {
    unsigned prev_size, size;
    struct mchunk *fd, *bk;
};
typedef struct mchunk *mchunkptr;
extern unsigned D_00454CE8[];
extern unsigned long D_004550F0;
extern unsigned long D_004550F8;
extern unsigned D_00454CF0[];
#define bin_at(i) ((mchunkptr)((char *)&D_00454CE8[2 * (i) + 2] - 8))
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define lr2 ((mchunkptr)D_00454CF0)
#define binblocks (bin_at(0)->size)
#define chunk_at_offset(p, s) ((mchunkptr)((char *)(p) + (s)))
#define chunksize(p) ((p)->size & ~3u)
#define inuse_bit_at_offset(p, s) (chunk_at_offset(p, s)->size & 1)
#define unlink(P, BK, FD) \
    { \
        BK = (P)->bk; \
        FD = (P)->fd; \
        FD->bk = BK; \
        BK->fd = FD; \
    }
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (chunk_at_offset(p, s)->prev_size = (s))
#define idx2binblock(ix) ((unsigned long)1 << ((ix) / 4))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define smallbin_index(sz) (((unsigned)(sz)) >> 3)
#define bin_index(sz) \
    ((((unsigned)(sz)) >> 9 == 0) ? (((unsigned)(sz)) >> 3) \
    : (((unsigned)(sz)) >> 9 <= 4) ? 56 + (((unsigned)(sz)) >> 6) \
    : (((unsigned)(sz)) >> 9 <= 20) ? 91 + (((unsigned)(sz)) >> 9) \
    : (((unsigned)(sz)) >> 9 <= 84) ? 110 + (((unsigned)(sz)) >> 12) \
    : (((unsigned)(sz)) >> 9 <= 340) ? 119 + (((unsigned)(sz)) >> 15) \
    : (((unsigned)(sz)) >> 9 <= 1364) ? 124 + (((unsigned)(sz)) >> 18) \
    : 126)
#define frontlink(P, S, IDX, BK, FD) \
    { \
        if (S < 512) { \
            IDX = smallbin_index(S); \
            mark_binblock(IDX); \
            BK = bin_at(IDX); \
            FD = BK->fd; \
            P->bk = BK; \
            P->fd = FD; \
            FD->bk = BK->fd = P; \
        } else { \
            IDX = bin_index(S); \
            BK = bin_at(IDX); \
            FD = BK->fd; \
            if (FD == BK) { \
                mark_binblock(IDX); \
            } else { \
                while (FD != BK && S < chunksize(FD)) \
                    FD = FD->fd; \
                BK = FD->bk; \
            } \
            P->bk = BK; \
            P->fd = FD; \
            FD->bk = BK->fd = P; \
        } \
    }
#define link_last_remainder(P) \
    { \
        lr->fd = lr->bk = P; \
        P->fd = P->bk = lr; \
    }

#define set_head_size(p, s) ((p)->size = (((p)->size & 1) | (s)))
extern char *D_00455100;
extern int D_00455118;
extern unsigned long D_00455108;
extern unsigned long D_00455110;
extern char *func_0041FD70_sbrk(int, int) __asm__("func_0041FD70");
extern void func_0041E340_free(int, void *) __asm__("func_0041E340");
void func_0041D990_(int ptr, unsigned nb) __asm__("func_0041D990");
void func_0041D990_(int ptr, unsigned nb) {
    char *brk;
    unsigned front_misalign;
    unsigned correction;
    char *new_brk;
    unsigned top_size;
    mchunkptr old_top = top;
    unsigned old_top_size = chunksize(old_top);
    char *old_end = (char *)chunk_at_offset(old_top, old_top_size);
    unsigned sbrk_size = nb + D_004550F8 + 16;
    unsigned long pagesz = 0x1000;
    if (D_00455100 != (char *)-1)
        sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);
    brk = func_0041FD70_sbrk(ptr, sbrk_size);
    if (brk == (char *)-1 || (brk < old_end && old_top != (mchunkptr)D_00454CE8))
        return;
    D_00455118 += sbrk_size;
    if (brk == old_end) {
        top_size = sbrk_size + old_top_size;
        set_head(top, top_size | 1);
    } else {
        if (D_00455100 == (char *)-1)
            D_00455100 = brk;
        else
            D_00455118 += brk - old_end;
        front_misalign = (unsigned long)(brk + 8) & 15;
        if (front_misalign > 0) {
            correction = 16 - front_misalign;
            brk += correction;
        } else
            correction = 0;
        correction += pagesz - ((unsigned long)(brk + sbrk_size) & (pagesz - 1));
        new_brk = func_0041FD70_sbrk(ptr, correction);
        if (new_brk == (char *)-1)
            return;
        D_00455118 += correction;
        top = (mchunkptr)brk;
        top_size = new_brk - brk + correction;
        set_head(top, top_size | 1);
        if (old_top != (mchunkptr)D_00454CE8) {
            if (old_top_size < 16) {
                set_head(top, 1);
                return;
            }
            old_top_size = (old_top_size - 12) & ~15u;
            set_head_size(old_top, old_top_size);
            chunk_at_offset(old_top, old_top_size)->size = 5;
            chunk_at_offset(old_top, old_top_size + 4)->size = 5;
            if (old_top_size >= 16)
                func_0041E340_free(ptr, (char *)old_top + 8);
        }
    }
    if ((unsigned long)D_00455118 > D_00455108)
        D_00455108 = D_00455118;
    if ((unsigned long)D_00455118 > D_00455110)
        D_00455110 = D_00455118;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_0041DBF8);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041E340);
#ifdef SKIP_ASM
extern void func_00418CA8_lock(int) __asm__("func_00418CA8");
extern void func_00418D08_unlock(int) __asm__("func_00418D08");
extern int func_0041E638_trim(int, unsigned) __asm__("func_0041E638");
void func_0041E340_(int ptr, void *mem) __asm__("func_0041E340");
void func_0041E340_(int ptr, void *mem) {
    mchunkptr p;
    unsigned hd, sz;
    int idx;
    mchunkptr next;
    unsigned nextsz, prevsz;
    mchunkptr bck, fwd;
    int islr;
    mchunkptr lr;
    if (mem == 0)
        return;
    func_00418CA8_lock(ptr);
    p = (mchunkptr)((char *)mem - 8);
    hd = p->size;
    sz = hd & ~1u;
    next = chunk_at_offset(p, sz);
    nextsz = chunksize(next);
    if (next == top) {
        sz += nextsz;
        if (!(hd & 1)) {
            prevsz = p->prev_size;
            p = chunk_at_offset(p, -(int)prevsz);
            sz += prevsz;
            unlink(p, bck, fwd);
        }
        set_head(p, sz | 1);
        top = p;
        if ((unsigned long)sz >= D_004550F0)
            func_0041E638_trim(ptr, D_004550F8);
        func_00418D08_unlock(ptr);
        return;
    }
    set_head(next, nextsz);
    islr = 0;
    if (!(hd & 1)) {
        prevsz = p->prev_size;
        p = chunk_at_offset(p, -(int)prevsz);
        sz += prevsz;
        if (p->fd == last_remainder)
            islr = 1;
        else
            unlink(p, bck, fwd);
    }
    if (!inuse_bit_at_offset(next, nextsz)) {
        sz += nextsz;
        if (!islr && next->fd == (lr = lr2)) {
            islr = 1;
            link_last_remainder(p);
        } else
            unlink(next, bck, fwd);
    }
    set_head(p, sz | 1);
    set_foot(p, sz);
    if (!islr)
        frontlink(p, sz, idx, bck, fwd);
    func_00418D08_unlock(ptr);
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_0041E638);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041E7A8);
#ifdef SKIP_ASM
long func_0041E7A8_(int *ptr, char *nptr, char **endptr, int base) __asm__("func_0041E7A8");
long func_0041E7A8_(int *ptr, char *nptr, char **endptr, int base) {
    char *s = nptr;
    unsigned long acc, cutoff;
    int c, neg = 0, any, cutlim;
    do {
        c = *s++;
    } while (XCT(c) & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = neg ? -(unsigned long)0x8000000000000000L : 0x7FFFFFFFFFFFFFFFL;
    cutlim = func_0042DAD8_mod(cutoff, base);
    cutoff = func_00411538_div(cutoff, base);
    for (acc = 0, any = 0;; c = *s++) {
        if (XCT(c) & 4)
            c -= '0';
        else if (XCT(c) & 3)
            c -= (XCT(c) & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc = func_004114D0_mul(acc, base);
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? 0x8000000000000000L : 0x7FFFFFFFFFFFFFFFL;
        *ptr = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = any ? s - 1 : nptr;
    return acc;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041E9E0);
#ifdef SKIP_ASM
extern int D_00454944;
extern long func_0041E7A8(int, int, int, int);
long func_0041E9E0(int s, int end, int base) {
    return func_0041E7A8(D_00454944, s, end, base);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EA18);
#ifdef SKIP_ASM
extern char D_00499C81[];
int func_0041EA18(int a) {
    return (D_00499C81[a] & 1) ? a + 0x20 : a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EA38);
#ifdef SKIP_ASM
extern char D_0049A7D0b[] __asm__("D_0049A7D0");
extern char D_0049A7C0[], D_0049A7D0[], D_0049A7D8[], D_0049A7E0[], D_0049A7E8[];
extern char D_00455140[], D_00455148[], D_00455150[];
extern int func_004165A8_cmp(char *, char *) __asm__("func_004165A8");
extern char *strcpy_(char *, char *) __asm__("strcpy");
extern unsigned strlen_(char *) __asm__("strlen");
char *func_0041EA38_(int *p, int category, char *locale) __asm__("func_0041EA38");
char *func_0041EA38_(int *p, int category, char *locale) {
    if (locale) {
        if (category != 2) {
            if (func_004165A8_cmp(locale, D_0049A7D0) && func_004165A8_cmp(locale, D_0049A7C0))
                return 0;
            if (category == 0) {
                strcpy_(D_00455150, D_00455148);
                strcpy_(D_00455148, locale);
                *(int *)D_00455140 = 1;
            }
        } else {
            if (func_004165A8_cmp(locale, D_0049A7D0) && func_004165A8_cmp(locale, D_0049A7C0) && func_004165A8_cmp(locale, D_0049A7D0) &&
                func_004165A8_cmp(locale, D_0049A7D8) && func_004165A8_cmp(locale, D_0049A7E0) &&
                func_004165A8_cmp(locale, D_0049A7E8))
                return 0;
            strcpy_(D_00455150, D_00455148);
            strcpy_(D_00455148, locale);
            if (func_004165A8_cmp(locale, D_0049A7D8) == 0)
                *(int *)D_00455140 = 8;
            else if (strlen_(locale) >= 2)
                *(int *)D_00455140 = 2;
            else
                *(int *)D_00455140 = 1;
        }
        p[0xD] = (int)locale;
        p[0xC] = category;
        return category == 2 ? D_00455150 : D_0049A7D0b;
    }
    return category == 2 ? D_00455148 : D_0049A7D0b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EC08);
#ifdef SKIP_ASM
extern char D_0049A790[];
char *func_0041EC08(void) {
    return D_0049A790;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EC18);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041EA38(int, int, int);
void func_0041EC18(int a, int b) {
    func_0041EA38(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EC48);
#ifdef SKIP_ASM
extern int D_00454944;
void func_0041EC48(void) {
    ((char *(*)(int))func_0041EC08)(D_00454944);
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_0041EC70);

INCLUDE_ASM("seg/seg_316FB8", func_0041ED60);

INCLUDE_ASM("seg/seg_316FB8", func_0041EF50);

INCLUDE_ASM("seg/seg_316FB8", func_0041F3A8);

INCLUDE_ASM("seg/seg_316FB8", func_0041F9D8);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FB98);
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
INCLUDE_ASM("seg/seg_316FB8", func_0041FBF0);
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
INCLUDE_ASM("seg/seg_316FB8", func_0041FC50);
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
INCLUDE_ASM("seg/seg_316FB8", func_0041FCB0);
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
INCLUDE_ASM("seg/seg_316FB8", func_0041FD10);
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
INCLUDE_ASM("seg/seg_316FB8", func_0041FD70);
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
INCLUDE_ASM("seg/seg_316FB8", func_0041FDD0);
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

INCLUDE_ASM("seg/seg_316FB8", func_0041FE30);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FF40);
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
INCLUDE_ASM("seg/seg_316FB8", func_0041FF98);
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

INCLUDE_ASM("seg/seg_316FB8", func_00420010);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004200F0);
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

INCLUDE_ASM("seg/seg_316FB8", func_00420180);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420228);
#ifdef SKIP_ASM
void func_00420228(char *d, char *s, unsigned n) {
    while (n--)
        *d++ = *s++;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420260);
#ifdef SKIP_ASM
extern void func_00420228(char *, char *, unsigned);
extern int func_00417648(int *);
unsigned func_00420260(char *buf, unsigned size, unsigned count, int *fp) {
    unsigned resid, total, r;
    char *p;
    if ((resid = count * size) == 0)
        return 0;
    if (fp[1] < 0)
        fp[1] = 0;
    total = resid;
    p = buf;
    while (resid > (r = fp[1])) {
        func_00420228(p, (char *)fp[0], r);
        p += r;
        fp[0] = fp[0] + r;
        resid -= r;
        if (func_00417648(fp))
            return (total - resid) / size;
    }
    func_00420228(p, (char *)fp[0], resid);
    fp[1] -= resid;
    fp[0] += resid;
    return count;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", ungetc);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420510);
#ifdef SKIP_ASM
extern int *func_004224A0(int *, int, int);
int *func_00420510(int ep_, int k) {
    int *ep = (int *)ep_;
    int x;
    int *rv;
    if (ep[0x4C / 4] == 0) {
        ep[0x4C / 4] = (int)func_004224A0(ep, 4, 16);
        if (ep[0x4C / 4] == 0)
            return 0;
    }
    rv = ((int **)ep[0x4C / 4])[k];
    if (rv) {
        ((int **)ep[0x4C / 4])[k] = (int *)*rv;
    } else {
        x = 1 << k;
        rv = func_004224A0(ep, 1, 0x18 + (x - 1) * 4);
        if (rv == 0)
            return 0;
        rv[1] = k;
        rv[2] = x;
    }
    rv[3] = rv[4] = 0;
    return rv;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004205B8);
#ifdef SKIP_ASM
void func_004205B8(int *self, int *p) {
    if (p) {
        int i = p[1];
        p[0] = ((int *)self[0x4C / 4])[i];
        ((int **)self[0x4C / 4])[i] = p;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004205F0);
#ifdef SKIP_ASM
struct Bigint {
    struct Bigint *next;
    int k, maxwds, sign, wds;
    unsigned x[1];
};
extern int *func_00420510(int, int);
extern void func_004205B8(int *, int *);
extern void *func_0041605C(void *, void *, int);
struct Bigint *func_004205F0(int ptr, struct Bigint *b, int m, int a) {
    int i, wds;
    unsigned *x, y, xi, z, carry;
    struct Bigint *b1;
    wds = b->wds;
    x = b->x;
    i = 0;
    carry = a;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + carry;
        z = (xi >> 16) * m + (y >> 16);
        carry = z >> 16;
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (carry) {
        if (wds >= b->maxwds) {
            b1 = (struct Bigint *)func_00420510(ptr, b->k + 1);
            func_0041605C(&b1->sign, &b->sign, b->wds * 4 + 8);
            func_004205B8((int *)ptr, (int *)b);
            b = b1;
        }
        b->x[wds++] = carry;
        b->wds = wds;
    }
    return b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004206F8);
#ifdef SKIP_ASM
extern struct Bigint *func_004205F0(int, struct Bigint *, int, int);
struct Bigint *func_004206F8(int ptr, char *s, int nd0, int nd, int y9) {
    struct Bigint *b;
    int i, k;
    int x, y;
    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++)
        ;
    b = (struct Bigint *)func_00420510(ptr, k);
    b->x[0] = y9;
    b->wds = 1;
    i = 9;
    if (9 < nd0) {
        s += 9;
        do
            b = func_004205F0(ptr, b, 10, *s++ - '0');
        while (++i < nd0);
        s++;
    } else
        s += 10;
    for (; i < nd; i++)
        b = func_004205F0(ptr, b, 10, *s++ - '0');
    return b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420830);
#ifdef SKIP_ASM
int func_00420830(unsigned x) {
    int k = 0;
    if (!(x & 0xffff0000)) {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xff000000)) {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xf0000000)) {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xc0000000)) {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000))
            return 32;
    }
    return k;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004208B8);
#ifdef SKIP_ASM
int func_004208B8(unsigned *y) {
    int k;
    unsigned x = *y;
    if (x & 7) {
        if (x & 1)
            return 0;
        if (x & 2) {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xffff)) {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xff)) {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xf)) {
        k += 4;
        x >>= 4;
    }
    if (!(x & 3)) {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1)) {
        k++;
        x >>= 1;
        if (!x)
            return 32;
    }
    *y = x;
    return k;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420978);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
int *func_00420978(int a, int b) {
    int *p = func_00420510(a, 1);
    p[5] = b;
    p[4] = 1;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004209B0);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
struct Bigint *func_004209B0(int ptr, struct Bigint *a, struct Bigint *b) {
    struct Bigint *c;
    int i, k, wa, wb, wc;
    unsigned *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
    unsigned y, carry, z, z2;
    if (a->wds < b->wds) {
        c = a;
        a = b;
        b = c;
    }
    k = a->k;
    wa = a->wds;
    wb = b->wds;
    wc = wa + wb;
    if (wc > a->maxwds)
        k++;
    c = (struct Bigint *)func_00420510(ptr, k);
    for (x = c->x, xa = x + wc; x < xa; x++)
        *x = 0;
    xa = a->x;
    xae = xa + wa;
    xb = b->x;
    xbe = xb + wb;
    xc0 = c->x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xffff)) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                ((unsigned short *)xc)[1] = z2;
                ((unsigned short *)xc)[0] = z;
                xc++;
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16)) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                ((unsigned short *)xc)[1] = z;
                ((unsigned short *)xc)[0] = z2;
                xc++;
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc)
        ;
    c->wds = wc;
    return c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420BC8);
#ifdef SKIP_ASM
extern struct Bigint *func_004205F0(int, struct Bigint *, int, int);
extern struct Bigint *func_004209B0(int, struct Bigint *, struct Bigint *);
extern int *func_00420978(int, int);
extern void func_004205B8(int *, int *);
extern int D_0049A8E8[];
struct Bigint *func_00420BC8(int ptr, struct Bigint *b, int k) {
    struct Bigint *b1, *p5, *p51;
    int i;
    if ((i = k & 3))
        b = func_004205F0(ptr, b, D_0049A8E8[i - 1], 0);
    if (!(k >>= 2))
        return b;
    if (!(p5 = ((struct Bigint **)ptr)[0x48 / 4])) {
        p5 = ((struct Bigint **)ptr)[0x48 / 4] = (struct Bigint *)func_00420978(ptr, 625);
        p5->next = 0;
    }
    for (;;) {
        if (k & 1) {
            b1 = func_004209B0(ptr, b, p5);
            func_004205B8((int *)ptr, (int *)b);
            b = b1;
        }
        if (!(k >>= 1))
            break;
        if (!(p51 = p5->next)) {
            p51 = p5->next = func_004209B0(ptr, p5, p5);
            p51->next = 0;
        }
        p5 = p51;
    }
    return b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420CC8);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
extern void func_004205B8(int *, int *);
struct Bigint *func_00420CC8(int ptr, struct Bigint *b, int k) {
    int i, k1, n, n1;
    struct Bigint *b1;
    unsigned *x, *x1, *xe, z;
    n = k >> 5;
    k1 = b->k;
    n1 = n + b->wds + 1;
    for (i = b->maxwds; n1 > i; i <<= 1)
        k1++;
    b1 = (struct Bigint *)func_00420510(ptr, k1);
    x1 = b1->x;
    for (i = 0; i < n; i++)
        *x1++ = 0;
    x = b->x;
    xe = x + b->wds;
    if (k &= 0x1f) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z))
            ++n1;
    } else
        do
            *x1++ = *x++;
        while (x < xe);
    b1->wds = n1 - 1;
    func_004205B8((int *)ptr, (int *)b);
    return b1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420E28);
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

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420E90);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
struct Bigint *func_00420E90(int ptr, struct Bigint *a, struct Bigint *b) {
    struct Bigint *c;
    int i, wa, wb;
    int borrow, y, z;
    unsigned *xa, *xae, *xb, *xbe, *xc;
    i = func_00420E28((struct Bigint28 *)a, (struct Bigint28 *)b);
    if (!i) {
        c = (struct Bigint *)func_00420510(ptr, 0);
        c->wds = 1;
        c->x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else
        i = 0;
    c = (struct Bigint *)func_00420510(ptr, a->k);
    c->sign = i;
    wa = a->wds;
    xa = a->x;
    xae = xa + wa;
    wb = b->wds;
    xb = b->x;
    xbe = xb + wb;
    xc = c->x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        ((unsigned short *)xc)[1] = z;
        ((unsigned short *)xc)[0] = y;
        xc++;
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        ((unsigned short *)xc)[1] = z;
        ((unsigned short *)xc)[0] = y;
        xc++;
    }
    while (!*--xc)
        wa--;
    c->wds = wa;
    return c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421020);
#ifdef SKIP_ASM
union double_union {
    double d;
    struct {
        unsigned long lo : 32;
        unsigned long hi : 32;
    } w;
    long l;
};
#define word0(x) x.w.hi
#define word1(x) x.w.lo
double func_00421020(double _x) {
    union double_union x, a;
    int L;
    x.d = _x;
    L = (word0(x) & 0x7ff00000) - 52 * 0x100000;
    if (L > 0) {
        word0(a) = L;
        word1(a) = 0;
    } else {
        L = -L >> 20;
        if (L < 20) {
            word0(a) = 0x80000 >> L;
            word1(a) = 0;
        } else {
            word0(a) = 0;
            L -= 20;
            word1(a) = L >= 31 ? 1 : 1 << (31 - L);
        }
    }
    return a.d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004210E8);
#ifdef SKIP_ASM
extern int func_00420830(unsigned);
double func_004210E8(struct Bigint *a, int *e) {
    unsigned *xa, *xa0, w, y, z;
    int k;
    union double_union d;
    xa0 = a->x;
    xa = xa0 + a->wds;
    y = *--xa;
    k = func_00420830(y);
    *e = 32 - k;
    if (k < 11) {
        d.w.hi = 0x3ff00000 | y >> (11 - k);
        w = xa > xa0 ? *--xa : 0;
        d.w.lo = y << (21 + k) | w >> (11 - k);
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    if (k -= 11) {
        d.w.hi = 0x3ff00000 | y << k | z >> (32 - k);
        y = xa > xa0 ? *--xa : 0;
        d.w.lo = z << k | y >> (32 - k);
    } else {
        d.w.hi = 0x3ff00000 | y;
        d.w.lo = z;
    }
ret_d:
    return d.d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421280);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
extern int func_004208B8(unsigned *);
extern int func_00420830(unsigned);
struct Bigint *func_00421280(int ptr, double _d, int *e, int *bits) {
    struct Bigint *b;
    int de, i, k;
    unsigned *x, y, z;
    union double_union d;
    d.d = _d;
    b = (struct Bigint *)func_00420510(ptr, 1);
    x = b->x;
    z = d.w.hi & 0xfffff;
    d.w.hi &= 0x7fffffff;
    if ((de = (int)(d.w.hi >> 20)))
        z |= 0x100000;
    if ((y = d.w.lo)) {
        if ((k = func_004208B8(&y))) {
            x[0] = y | z << (32 - k);
            z >>= k;
        } else
            x[0] = y;
        i = b->wds = (x[1] = z) ? 2 : 1;
    } else {
        k = func_004208B8(&z);
        x[0] = z;
        i = b->wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - 1023 - 52 + k;
        *bits = 53 - k;
    } else {
        *e = de - 1023 - 52 + 1 + k;
        *bits = 32 * i - func_00420830(x[i - 1]);
    }
    return b;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_00421400);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004214C0);
#ifdef SKIP_ASM
extern double D_0049A8F8[];
extern double func_00411FD8(double, double);
double func_004214C0(int n) {
    double r = 1.0;
    if (n < 24)
        return D_0049A8F8[n];
    if (n > 0) {
        do {
            r = func_00411FD8(r, 10.0);
        } while (--n > 0);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421530);
#ifdef SKIP_ASM
struct R21530;
extern char *g21530_dtoa(struct R21530 *, double, int, int, int *, int *, char **) __asm__("func_00422780");
extern char *g21530_strcpy(char *, char *) __asm__("strcpy");
void func_00421530_(struct R21530 *ptr, char *buf, double invalue, int ndigit, int type, int dot, int mode) __asm__("func_00421530");
void func_00421530_(struct R21530 *ptr, char *buf, double invalue, int ndigit, int type, int dot, int mode) {
    int decpt;
    int sign;
    char *p, *start, *end;
    start = p = g21530_dtoa(ptr, invalue, mode, ndigit, &decpt, &sign, &end);
    if (decpt == 9999) {
        g21530_strcpy(buf, p);
        return;
    }
    while (*p != '\0' && decpt > 0) {
        *buf++ = *p++;
        decpt--;
    }
    while (decpt > 0) {
        *buf++ = '0';
        decpt--;
    }
    if (dot == 0 && *p == '\0') {
        *buf = '\0';
        return;
    }
    if (p == start)
        *buf++ = '0';
    *buf++ = '.';
    while (decpt < 0 && ndigit > 0) {
        *buf++ = '0';
        decpt++;
        ndigit--;
    }
    while (*p && ndigit > 0) {
        *buf++ = *p++;
        ndigit--;
    }
    while (ndigit > 0) {
        *buf++ = '0';
        ndigit--;
    }
    *buf = '\0';
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004216E8);
#ifdef SKIP_ASM
struct R216E8;
extern char *g216E8_dtoa(struct R216E8 *, double, int, int, int *, int *, char **) __asm__("func_00422780");
extern char *g216E8_strcpy(char *, char *) __asm__("strcpy");
void func_004216E8_(struct R216E8 *ptr, char *buf, double invalue, int ndigit, char type, int dot) __asm__("func_004216E8");
void func_004216E8_(struct R216E8 *ptr, char *buf, double invalue, int ndigit, char type, int dot) {
    int decpt;
    int i = ndigit;
    int sign;
    char *p, *end;
    p = g216E8_dtoa(ptr, invalue, 2, i + 1, &decpt, &sign, &end);
    if (decpt == 9999) {
        g216E8_strcpy(buf, p);
        return;
    }
    *buf++ = *p++;
    if (dot || i != 0)
        *buf++ = '.';
    while (*p && i > 0) {
        *buf++ = *p++;
        i--;
    }
    if (type == 'g')
        type = 'e';
    else if (type == 'G')
        type = 'E';
    else {
        while (i > 0) {
            *buf++ = '0';
            i--;
        }
    }
    *buf++ = type;
    decpt--;
    if (decpt < 0) {
        *buf++ = '-';
        decpt = -decpt;
    } else
        *buf++ = '+';
    if (decpt >= 100) {
        int dig = decpt / 100;
        *buf++ = dig + '0';
        decpt -= dig * 100;
    }
    {
        int dig = decpt / 10;
        *buf++ = dig + '0';
        decpt -= dig * 10;
    }
    *buf++ = decpt + '0';
    *buf = '\0';
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004218D8);
#ifdef SKIP_ASM
struct R218D8 {
    int pad0[0x50 / 4];
    int cvtlen;
    char *cvtbuf;
};
extern struct R218D8 *g218D8_impure __asm__("D_00454944");
#define REENT218D8 g218D8_impure
extern char *g218D8_realloc(struct R218D8 *, char *, int) __asm__("func_00421F20");
extern char *g218D8_dtoa(struct R218D8 *, double, int, int, int *, int *, char **) __asm__("func_00422780");
char *func_004218D8_(double invalue, int ndigit, int *decpt, int *sign, char *buf) __asm__("func_004218D8");
char *func_004218D8_(double invalue, int ndigit, int *decpt, int *sign, char *buf) {
    char *save, *p, *end;
    int done = 0;
    int newlen;
    if (buf == 0) {
        if (ndigit >= REENT218D8->cvtlen) {
            newlen = ndigit + 1;
            buf = g218D8_realloc(REENT218D8, REENT218D8->cvtbuf, newlen);
            if (buf == 0)
                return 0;
            REENT218D8->cvtlen = newlen;
            REENT218D8->cvtbuf = buf;
        }
        buf = REENT218D8->cvtbuf;
    }
    save = buf;
    if (invalue < 1.0 && invalue > -1.0)
        p = g218D8_dtoa(REENT218D8, invalue, 2, ndigit, decpt, sign, &end);
    else
        p = g218D8_dtoa(REENT218D8, invalue, 3, ndigit, decpt, sign, &end);
    while (p < end) {
        *buf++ = *p++;
        done++;
    }
    if (done < ndigit) {
        done = ndigit - done;
        do {
            *buf++ = '0';
        } while (--done);
    }
    *buf = 0;
    return save;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421A50);
#ifdef SKIP_ASM
struct Reent51 {
    int pad0[0x50 / 4];
    int cvtlen;
    char *cvtbuf;
};
extern int D_00454944;
#define REENT ((struct Reent51 *)D_00454944)
extern char *func_00421F20(struct Reent51 *, char *, int);
extern char *func_00422780(struct Reent51 *, double, int, int, int *, int *, char **);
char *func_00421A50_(double value, int ndigit, int *decpt, int *sign, char *buf) __asm__("func_00421A50");
char *func_00421A50_(double value, int ndigit, int *decpt, int *sign, char *buf) {
    char *save, *p, *end;
    int i = 0;
    int newlen;
    if (buf == 0) {
        if (ndigit >= REENT->cvtlen) {
            newlen = ndigit + 1;
            buf = func_00421F20(REENT, REENT->cvtbuf, newlen);
            if (buf == 0)
                return 0;
            REENT->cvtlen = newlen;
            REENT->cvtbuf = buf;
        }
        buf = REENT->cvtbuf;
    }
    save = buf;
    p = func_00422780(REENT, value, 2, ndigit, decpt, sign, &end);
    while (p < end) {
        *buf++ = *p++;
        i++;
    }
    if (i < ndigit) {
        i = ndigit - i;
        do {
            *buf++ = '0';
        } while (--i);
    }
    *buf = 0;
    return save;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_00421B98);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421E60);
#ifdef SKIP_ASM
extern void func_00421530_f(int, char *, long, int, int, int, int) __asm__("func_00421530");
extern void func_00421B98_g(int, long, int, char *, int, int) __asm__("func_00421B98");
extern void func_004216E8_e(int, char *, long, int, int, int) __asm__("func_004216E8");
char *func_00421E60(int ep, char *buf, long val, int nd, int unused, char fmt, int pad) {
    switch (fmt) {
    case 'f':
    case 'F':
        func_00421530_f(ep, buf, val, nd, fmt, nd ? 1 : pad, 3);
        break;
    case 'g':
    case 'G':
        func_00421B98_g(ep, val, nd ? nd : 1, buf, fmt, pad);
        break;
    case 'e':
    case 'E':
        func_004216E8_e(ep, buf, val, nd, fmt, pad);
        break;
    }
    return buf;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421F20);
#ifdef SKIP_ASM
extern void func_00418CA8_lock(int) __asm__("func_00418CA8");
extern void func_00418D08_unlock(int) __asm__("func_00418D08");
extern void *func_0041DBF8_malloc(int, int) __asm__("func_0041DBF8");
extern void func_0041E340_free(int, void *) __asm__("func_0041E340");
extern void *func_0041605C_memcpy(void *, void *, unsigned) __asm__("func_0041605C");
#define MALLOC_COPY(dest, src, nbytes)     do {         unsigned mcn = (nbytes);         if (mcn < 37) {             unsigned *mcsrc = (unsigned *)(src);             unsigned *mcdst = (unsigned *)(dest);             if (mcn >= 20) {                 *mcdst++ = *mcsrc++;                 *mcdst++ = *mcsrc++;                 if (mcn >= 28) {                     *mcdst++ = *mcsrc++;                     *mcdst++ = *mcsrc++;                     if (mcn >= 36) {                         *mcdst++ = *mcsrc++;                         *mcdst++ = *mcsrc++;                     }                 }             }             *mcdst++ = *mcsrc++;             *mcdst++ = *mcsrc++;             *mcdst = *mcsrc;         } else             func_0041605C_memcpy(dest, src, mcn);     } while (0)
#define inuse(p) (chunk_at_offset(p, (p)->size & ~1u)->size & 1)
void *func_00421F20_(int ptr, void *oldmem, unsigned bytes) __asm__("func_00421F20");
void *func_00421F20_(int ptr, void *oldmem, unsigned bytes) {
    unsigned nb, oldsize, newsize, nextsize, prevsize, remainder_size;
    mchunkptr oldp, newp, next, prev, remainder, bck, fwd;
    void *newmem;
    if (oldmem == 0)
        return func_0041DBF8_malloc(ptr, bytes);
    func_00418CA8_lock(ptr);
    newp = oldp = (mchunkptr)((char *)oldmem - 8);
    newsize = oldsize = chunksize(oldp);
    nb = (bytes + 19 < 31) ? 16 : ((bytes + 19) & ~15u);
    if (oldsize < nb) {
        next = chunk_at_offset(oldp, oldsize);
        if (next == top || !inuse(next)) {
            nextsize = chunksize(next);
            if (next == top) {
                if (nextsize + newsize >= nb + 16) {
                    newsize += nextsize;
                    top = chunk_at_offset(oldp, nb);
                    set_head(top, (newsize - nb) | 1);
                    set_head_size(oldp, nb);
                    func_00418D08_unlock(ptr);
                    return (char *)oldp + 8;
                }
            } else if (nextsize + newsize >= nb) {
                unlink(next, bck, fwd);
                newsize += nextsize;
                goto split;
            }
        } else {
            next = 0;
            nextsize = 0;
        }
        if (!(oldp->size & 1)) {
            prev = chunk_at_offset(oldp, -(int)oldp->prev_size);
            prevsize = chunksize(prev);
            if (next != 0) {
                if (next == top) {
                    if (nextsize + prevsize + newsize >= nb + 16) {
                        unlink(prev, bck, fwd);
                        newp = prev;
                        newsize += prevsize + nextsize;
                        newmem = (char *)newp + 8;
                        MALLOC_COPY((char *)newp + 8, oldmem, oldsize - 4);
                        top = chunk_at_offset(newp, nb);
                        set_head(top, (newsize - nb) | 1);
                        set_head_size(newp, nb);
                        func_00418D08_unlock(ptr);
                        return newmem;
                    }
                } else if (nextsize + prevsize + newsize >= nb) {
                    unlink(next, bck, fwd);
                    unlink(prev, bck, fwd);
                    newp = prev;
                    newsize += nextsize + prevsize;
                    newmem = (char *)newp + 8;
                    MALLOC_COPY((char *)newp + 8, oldmem, oldsize - 4);
                    goto split;
                }
            }
            if (prev != 0 && prevsize + newsize >= nb) {
                unlink(prev, bck, fwd);
                newp = prev;
                newsize += prevsize;
                newmem = (char *)newp + 8;
                MALLOC_COPY((char *)newp + 8, oldmem, oldsize - 4);
                goto split;
            }
        }
        newmem = func_0041DBF8_malloc(ptr, bytes);
        if (newmem == 0) {
            func_00418D08_unlock(ptr);
            return 0;
        }
        if ((newp = (mchunkptr)((char *)newmem - 8)) == chunk_at_offset(oldp, oldp->size & ~1u)) {
            newsize += chunksize(newp);
            newp = oldp;
            goto split;
        }
        MALLOC_COPY(newmem, oldmem, oldsize - 4);
        func_0041E340_free(ptr, oldmem);
        func_00418D08_unlock(ptr);
        return newmem;
    }
split:
    if (newsize - nb >= 16) {
        remainder = chunk_at_offset(newp, nb);
        remainder_size = newsize - nb;
        set_head_size(newp, nb);
        set_head(remainder, remainder_size | 1);
        chunk_at_offset(remainder, remainder_size)->size |= 1;
        func_0041E340_free(ptr, (char *)remainder + 8);
    } else {
        set_head_size(newp, newsize);
        chunk_at_offset(newp, newsize)->size |= 1;
    }
    func_00418D08_unlock(ptr);
    return (char *)newp + 8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004224A0);
#ifdef SKIP_ASM
extern void *func_0041DBF8_malloc(int, int) __asm__("func_0041DBF8");
extern void *func_00416210_memset(void *, int, unsigned) __asm__("func_00416210");
#define MALLOC_ZERO(charp, nbytes)     do {         unsigned mctmp = (nbytes);         if (mctmp < 37) {             unsigned *mzp = (unsigned *)(charp);             if (mctmp >= 20) {                 *mzp++ = 0;                 *mzp++ = 0;                 if (mctmp >= 28) {                     *mzp++ = 0;                     *mzp++ = 0;                     if (mctmp >= 36) {                         *mzp++ = 0;                         *mzp++ = 0;                     }                 }             }             *mzp++ = 0;             *mzp++ = 0;             *mzp = 0;         } else             func_00416210_memset(charp, 0, mctmp);     } while (0)
void *func_004224A0_(int ptr, int n, int elem_size) __asm__("func_004224A0");
void *func_004224A0_(int ptr, int n, int elem_size) {
    mchunkptr p;
    unsigned csz;
    unsigned sz = n * elem_size;
    void *mem;
    mem = func_0041DBF8_malloc(ptr, sz);
    if (mem == 0)
        return 0;
    p = (mchunkptr)((char *)mem - 8);
    csz = chunksize(p);
    MALLOC_ZERO(mem, csz - 4);
    return mem;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00422560);
#ifdef SKIP_ASM
extern int func_00420E28_cmp(struct Bigint *, struct Bigint *) __asm__("func_00420E28");
int func_00422560(struct Bigint *b, struct Bigint *S) {
    int n;
    int borrow, y;
    unsigned carry, q, ys;
    unsigned *bx, *bxe, *sx, *sxe;
    int z;
    unsigned si, zs;
    n = S->wds;
    if (b->wds < n)
        return 0;
    sx = S->x;
    sxe = sx + --n;
    bx = b->x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            ((unsigned short *)bx)[1] = (unsigned short)z;
            ((unsigned short *)bx)[0] = (unsigned short)y;
            bx++;
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->x;
            while (--bxe > bx && !*bxe)
                --n;
            b->wds = n;
        }
    }
    if (func_00420E28_cmp(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->x;
        sx = S->x;
        do {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            ((unsigned short *)bx)[1] = (unsigned short)z;
            ((unsigned short *)bx)[0] = (unsigned short)y;
            bx++;
        } while (sx <= sxe);
        bx = b->x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe)
                --n;
            b->wds = n;
        }
    }
    return q;
}
#endif

INCLUDE_ASM("seg/seg_316FB8", func_00422780);

INCLUDE_ASM("seg/seg_316FB8", func_00423980);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00423990);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423990, 0x1)
#endif
