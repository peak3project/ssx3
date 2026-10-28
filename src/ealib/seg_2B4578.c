#include "common.h"

// PORT: PS2-only COP0 (disable / enable interrupts, pipeline sync, read the Status register).
#define DI_2B45() __asm__ volatile("di")
#define EI_2B45() __asm__ volatile("ei")
#define SYNCP_2B45() __asm__ volatile("sync.p")
#define MFC0_STATUS_2B45(v) __asm__ volatile("mfc0 %0, $12" : "=r"(v))

INCLUDE_ASM("ealib/seg_2B4578", SHAPE_unpack);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B38B8);
#ifdef SKIP_ASM
int func_003B38B8(int arg0) {
    int var_5;

    var_5 = 0;
    switch (arg0) {
    case 15:
    case 16:
        var_5 = 0x20;
        break;
    case 18:
    case 24:
        var_5 = 0;
        break;
    case 32:
        var_5 = 0x21;
        break;
    }
    return var_5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3900);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *f_3A10_3900(char *) __asm__("func_003B3A10");
extern void f_3D00_3900(char *, int, void *) __asm__("func_003B3D00");
extern int f_65A8_3900(void *, int) __asm__("func_004165A8");
struct B_3900 { int pad; char c; };
struct H_3900 { char pad[8]; int n; char pad2[8]; struct { int off; int x; } t[1]; };

char *func_003B3900_3900(struct H_3900 *, int) __asm__("func_003B3900");
char *func_003B3900_3900(struct H_3900 *arg0, int arg1) {
    int i;
    int n = arg0->n;
    struct B_3900 buf;
    char *p;
    for (i = 0; i < n; i++) {
        p = f_3A10_3900((char *)arg0 + arg0->t[i].off);
        if (p == 0) {
            buf.c = 0;
            f_3D00_3900((char *)arg0, i, &buf);
            p = (char *)&buf;
        }
        if (f_65A8_3900(p, arg1) == 0)
            return (char *)arg0 + arg0->t[i].off;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", SHAPE_locate);
#ifdef SKIP_ASM
extern void func_003B3900();

void SHAPE_locate(void) {
    func_003B3900();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B39D8);
#ifdef SKIP_ASM
extern unsigned char D_0044C3D0[];

unsigned char func_003B39D8(unsigned char *arg0) {
    return D_0044C3D0[*arg0 & 0x7F];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B39F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044C3D0_39F8[128] __asm__("D_0044C3D0");

unsigned char func_003B39F8(int arg0) {
    return D_0044C3D0_39F8[arg0 & 0x7F];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3A10);
#ifdef SKIP_ASM
unsigned char *func_003B3A10(unsigned char *p) {
    while (p) {
        int off;
        unsigned char *n;
        if (*p == 0x70) {
            return p + 4;
        }
        off = *(int *)p >> 8;
        n = p + off;
        p = off ? n : 0;
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B3A50);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B3BB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B3A50_3BB0(unsigned char, short, short, unsigned int, int) __asm__("func_003B3A50");
extern int func_003B4D00_3BB0(char *, int *) __asm__("func_003B4D00");
extern int strlen_3BB0(char *) __asm__("strlen");

int func_003B3BB0(char *p) {
    int sp0;
    int r = 0;
    int w;
    unsigned int u;
    char *q;
    unsigned int t = *(unsigned char *)p;
    switch (t) {
    case 0x70:
        return strlen_3BB0(p + 4) + 5;
    case 0x6F:
        return *(int *)(p + 4) + 8;
    case 0x7C:
        return (*(int *)(p + 4) << 3) + 8;
    case 0x69:
        if (*(unsigned short *)(p + 6) & 0x10) {
            u = *(unsigned short *)(p + 4);
            if (u == 0) u = 0xF0;
            return u + 0x10;
        }
        return 0x10;
    default:
        if (*(unsigned char *)p & 0x80) {
            sp0 = 0;
            if (*(int *)(p + 0xC) & 0x1000) {
                q = p + *(int *)(p + 0x10);
            } else {
                q = p + 0x10;
            }
            if (func_003B4D00_3BB0(q, &sp0) != 0) {
                r = sp0 + 0x10;
            }
        } else {
            w = *(int *)(p + 0xC);
            r = func_003B3A50_3BB0(*(unsigned char *)p, *(short *)(p + 4), *(short *)(p + 6), (unsigned int)w >> 28, (w >> 13) & 1);
        }
        return r;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B3CCC);

INCLUDE_ASM("ealib/seg_2B4578", func_003B3CD8);

INCLUDE_ASM("ealib/seg_2B4578", func_003B3D00);

INCLUDE_ASM("ealib/seg_2B4578", func_003B3D40);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3DA8);
#ifdef SKIP_ASM
int func_003B3DA8(int arg0) {
    int r = 0;
    switch (arg0) {
    case 4: r = 1; break;
    case 8: r = 2; break;
    case 0xF: case 0x10: case 0x22B: case 0x613: r = 3; break;
    case 0x20: case 0x22B8: r = 5; break;
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B3E40);

INCLUDE_ASM("ealib/seg_2B4578", func_003B4010);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4218);
#ifdef SKIP_ASM
extern int func_003B42B0(int, int, int);
extern int func_003B4338(int, int, int);
extern int func_003B43C0(int, int, int);
extern int func_003B4448(int, int, int);

int func_003B4218(int a0, int a1, int a2, int a3, int kind) {
    int result = 0;
    switch (kind) {
    case 4:
        result = func_003B42B0(a0, a1, a2);
        break;
    case 8:
        result = func_003B4338(a0, a1, a2);
        break;
    case 15:
        result = func_003B43C0(a0, a1, a2);
        break;
    case 16:
        result = func_003B43C0(a0, a1, a2);
        break;
    case 32:
        result = func_003B4448(a0, a1, a2);
        break;
    }
    return result;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B42B0);

INCLUDE_ASM("ealib/seg_2B4578", func_003B4338);

INCLUDE_ASM("ealib/seg_2B4578", func_003B43C0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4448);
#ifdef SKIP_ASM
int func_003B4448(int arg0, int arg1, int arg2) {
    return ((arg1 * arg2) + arg0) << 5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4458);
#ifdef SKIP_ASM
extern int D_0044C450[];
extern int D_0044C454[];
extern int D_0044C458[];

void func_003B4458(int arg0, int arg1, int arg2) {
    D_0044C450[0] = arg0;
    D_0044C454[0] = arg1;
    D_0044C458[0] = arg2;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B4478);

//100%
INCLUDE_ASM("ealib/seg_2B4578", SHAPE_cloneat);
#ifdef SKIP_ASM
extern int f_3BB0_CA(char *) __asm__("func_003B3BB0");
extern int f_4708_CA(int) __asm__("func_003B4708");
extern void f_6188_CA(char *, char *, int) __asm__("func_003E6188");
extern int sprintf(char *, const char *, ...);
extern char D_004957B8_CA[] __asm__("D_004957B8");

void SHAPE_cloneat(char *dst, char *src) {
    int off = 0;
    char *prev;
    char *cur = 0;
    char *nx;
    int n;
    int r;
    int pad = (((int)src + 15) & -16) - (int)src;
    int padm;
    int al;
    if (src) {
        al = -16;
        padm = pad - 16;
        do {
            n = f_3BB0_CA(src);
            if (off != 0) {
                r = f_4708_CA(*(unsigned char *)src);
                if (r) {
                    off = (((off - pad) + 0x1F) & al) + padm;
                } else {
                    off = (((off - pad) + 0xF) & al) + pad;
                }
            }
            prev = cur;
            cur = dst + off;
            if (prev) {
                *(unsigned int *)prev = *(unsigned char *)prev | ((cur - prev) << 8);
            }
            *(unsigned int *)cur = *(unsigned char *)cur;
            if (n) {
                f_6188_CA(cur, src, n);
                if (*(unsigned char *)cur == 0x69 && n > 0x14) {
                    sprintf(cur + 0x10, D_004957B8_CA, *(short *)(cur + 4));
                }
            }
            r = *(int *)src >> 8;
            nx = 0;
            if (r) nx = src + r;
            src = nx;
            off += n;
        } while (src);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4690);
#ifdef SKIP_ASM
extern int func_003B4478_4690(int) __asm__("func_003B4478");
extern void *func_003B3A10_4690(int) __asm__("func_003B3A10");
extern void SHAPE_cloneat_4690(void *, int) __asm__("SHAPE_cloneat");
extern void *(*D_0044C454_4690)(void *, int, int, int, int) __asm__("D_0044C454");

void *func_003B4690(int arg0) {
    int sz = func_003B4478_4690(arg0);
    void *r = D_0044C454_4690(func_003B3A10_4690(arg0), sz, 0, 0x10, 0x400);
    SHAPE_cloneat_4690(r, arg0);
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4708);
#ifdef SKIP_ASM
int func_003B4708(int arg0) {
    int var_5;

    var_5 = 0;
    switch (arg0) {
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x24:
    case 0x29:
    case 0x2A:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x38:
        var_5 = 1;
        break;
    }
    return var_5;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B4740);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B47F8);
#ifdef SKIP_ASM
extern void func_003B4740();

void func_003B47F8(void) {
    func_003B4740();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4818);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int f_4818(unsigned char *p) __asm__("func_003B4818");
static __inline__ int get24_4818(unsigned char *q) { return (q[0] << 16) | (q[1] << 8) | q[2]; }
static __inline__ int get32_4818(unsigned char *q) { return (q[0] << 24) | (q[1] << 16) | (q[2] << 8) | q[3]; }
int f_4818(unsigned char *p) {
    int v = 0;
    if (p[1] == 0xFB) {
        switch (p[0] & 0xFE) {
        case 0x10: case 0x18: case 0x1A: case 0x1E:
        case 0x30: case 0x32: case 0x34: case 0x46:
            v = get24_4818(p + 2);
            break;
        case 0x90: case 0x98: case 0x9A: case 0x9E:
        case 0xB0: case 0xB2: case 0xB4: case 0xC6:
            v = get32_4818(p + 2);
            break;
        case 0xC0:
            break;
        }
    }
    return v;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B49B0);
#ifdef SKIP_ASM
extern void func_003B4818();

void func_003B49B0(void) {
    func_003B4818();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B49D0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4D00);
#ifdef SKIP_ASM
int func_003B4D00(unsigned char *p, int *out) {
    int r = 0;
    unsigned char *q;
    unsigned int c;
    unsigned int n;
    if (p) {
        q = (((*p << 8) & 0x100) ? p + 5 : p + 2);
        r = *q++;
        r = (r << 8) + *q++;
        r = (r << 8) + *q++;
        if (out) {
            for (;;) {
                c = *q++;
                if ((c & 0x80) == 0) {
                    q++;
                    q += c & 3;
                } else if ((c & 0x40) == 0) {
                    n = *q >> 6;
                    q += 2;
                    q += n;
                } else if ((c & 0x20) == 0) {
                    q += 3;
                    q += c & 3;
                } else {
                    n = ((c & 0x1F) << 2) + 4;
                    if (n <= 0x70) {
                        q += n;
                    } else {
                        q += c & 3;
                        n = q - p;
                        *out = n;
                        break;
                    }
                }
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4DD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Sub_4DD8 {
    char pad00[0x8];
    short f08;
    char pad0A[0x14 - 0xA];
    float f14;
    char pad18[0x1C - 0x18];
    char f1C;
    char pad1D[0x2B - 0x1D];
    char f2B;
    char pad2C[0xA0 - 0x2C];
};
struct Cfg_4DD8 {
    char pad00[0x20];
    struct Sub_4DD8 sub;
    char padC0[0xD4 - 0xC0];
};
struct G_4DD8 {
    struct Cfg_4DD8 cfg;
    struct Sub_4DD8 saved;
};
extern struct G_4DD8 D_0050A8E8_4DD8 __asm__("D_0050A8E8");
extern int D_0044C45C;
extern int D_0044C460;
extern int func_003C0C90_4DD8() __asm__("func_003C0C90");

int func_003B4DD8_4DD8(struct Cfg_4DD8 *out) __asm__("func_003B4DD8");

int func_003B4DD8_4DD8(struct Cfg_4DD8 *out) {
    if (D_0044C45C == 0) {
        D_0044C460 = func_003C0C90_4DD8();
        D_0044C45C = 1;
        D_0050A8E8_4DD8.cfg.sub.f08 = 0x10;
        D_0050A8E8_4DD8.cfg.sub.f2B = 0x5A;
        D_0050A8E8_4DD8.cfg.sub.f1C = 1;
        D_0050A8E8_4DD8.cfg.sub.f14 = -1.0f;
        D_0050A8E8_4DD8.saved = D_0050A8E8_4DD8.cfg.sub;
    }
    *out = D_0050A8E8_4DD8.cfg;
    return D_0044C460;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4FC0);
#ifdef SKIP_ASM
typedef struct { int w[5]; } W14_4FC0;
extern char D_0050A908[];
extern W14_4FC0 D_0050A9A8;
extern void f0E28(void) __asm__("func_003C0E28");
int func_003B4FC0_impl(char *p) __asm__("func_003B4FC0");
int func_003B4FC0_impl(char *p) {
    __builtin_memcpy(D_0050A908, p + 0x20, 0xA0);
    D_0050A9A8 = *(W14_4FC0 *)(p + 0xC0);
    f0E28();
    __builtin_memcpy((char *)&D_0050A9A8 + 0x14, (char *)&D_0050A9A8 - 0xA0, 0xA0);
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B5158);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5320);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B5440_5320() __asm__("func_003B5440");
extern int func_003B82B8_5320(int, int, int, int, int) __asm__("func_003B82B8");
extern void func_003BC530_5320() __asm__("func_003BC530");
extern void func_003B8A38_5320() __asm__("func_003B8A38");
extern void func_003C2268_5320() __asm__("func_003C2268");
extern void func_003B58A0_5320() __asm__("func_003B58A0");
extern void func_003B5E98_5320(int) __asm__("func_003B5E98");
extern void func_003B58D8_5320() __asm__("func_003B58D8");
extern int func_003B5C40_5320() __asm__("func_003B5C40");
extern void func_003C3358_5320() __asm__("func_003C3358");
struct G_5320 {
    char pad0[0x174]; char f174; char pad1[0x1D8 - 0x175];
    void (*f1D8)(void); void (*f1DC)(void); void (*f1E0)(void); void (*f1E4)(int);
    void (*f1E8)(void); void (*f1EC)(void); int f1F0; int f1F4;
};
extern struct G_5320 D_0050A8E8_5320 __asm__("D_0050A8E8");

int func_003B5320(void) {
    int r;
    if (func_003B5440_5320() == 0) return -14;
    func_003B82B8_5320(0, 0, 0, -1, -1);
    if (D_0050A8E8_5320.f1D8) D_0050A8E8_5320.f1D8();
    if (D_0050A8E8_5320.f1DC) D_0050A8E8_5320.f1DC();
    if (D_0050A8E8_5320.f1E0) D_0050A8E8_5320.f1E0();
    if (D_0050A8E8_5320.f1EC) D_0050A8E8_5320.f1EC();
    if (D_0050A8E8_5320.f1E8) D_0050A8E8_5320.f1E8();
    func_003BC530_5320();
    func_003B8A38_5320();
    if (D_0050A8E8_5320.f1E4) D_0050A8E8_5320.f1E4(-1);
    func_003C2268_5320();
    func_003B58A0_5320();
    func_003B5E98_5320(D_0050A8E8_5320.f1F0);
    func_003B5E98_5320(D_0050A8E8_5320.f1F4);
    func_003B58D8_5320();
    r = func_003B5C40_5320();
    D_0050A8E8_5320.f174 = 0;
    func_003C3358_5320();
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5440);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern signed char D_0050AA5C_5440[16] __asm__("D_0050AA5C");

signed char func_003B5440(void) {
    return D_0050AA5C_5440[0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5450);
#ifdef SKIP_ASM
extern void func_003C60E0();

int func_003B5450(void) {
    func_003C60E0();
    return 0;
}
#endif

void func_003B5470(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5478);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003BC910(void);
extern void SYNCTASK_add_5478(void *, int, int) __asm__("SYNCTASK_add");
extern void func_003E4A30_5478(void *) __asm__("func_003E4A30");
extern int D_0044C464_C464[] __asm__("D_0044C464");
extern void (*D_0050A9B0_A9B0[])() __asm__("D_0050A9B0");

int func_003B5478(void) {
    D_0050A9B0_A9B0[0] = func_003B5470;
    if (D_0044C464_C464[0] == 0) {
        SYNCTASK_add_5478(func_003B5450, 0, 1);
        D_0044C464_C464[0] = 1;
    }
    func_003E4A30_5478(func_003BC910);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B54E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct N_54E0 { struct N_54E0 *next; int pad; void (*fn)(int); int arg; } N_54E0;
typedef struct { char pad[0x1B4]; N_54E0 *list; int pad2[2]; int cnt; } G_54E0;
extern int D_0050A8E8_A8E8_54E0[] __asm__("D_0050A8E8");
extern int D_0044C468_C468[] __asm__("D_0044C468");

void func_003B54E0(void) {
    N_54E0 *n;
    G_54E0 *g = (G_54E0 *)D_0050A8E8_A8E8_54E0;

    if (g->cnt != D_0044C468_C468[0]) {
        n = g->list;
        D_0044C468_C468[0] = g->cnt;
        if (n != 0) {
            do {
                n->fn(n->arg);
                n = n->next;
            } while (n != 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5540);
#ifdef SKIP_ASM
struct G_5540 { char pad[0x174]; signed char f174; char pad1[0x180 - 0x175]; unsigned f180; char pad2[0x330 - 0x184]; volatile unsigned f330; volatile unsigned short f334; };
extern struct G_5540 D_0050A8E8_5540 __asm__("D_0050A8E8");
extern void func_003B55F0_5540(void) __asm__("func_003B55F0");

void func_003B5540(unsigned arg0) {
    unsigned lim;
    if (D_0050A8E8_5540.f174 != 0) {
        if ((int)arg0 != (short)D_0050A8E8_5540.f334) {
            D_0050A8E8_5540.f334 = arg0;
            D_0050A8E8_5540.f180 = 0;
            D_0050A8E8_5540.f330 = 0;
        }
        D_0050A8E8_5540.f330++;
        lim = D_0050A8E8_5540.f330 * 100 / arg0;
        while (lim >= D_0050A8E8_5540.f180) {
            func_003B55F0_5540();
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B55F0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5860);
#ifdef SKIP_ASM
extern void func_003C3380();

void func_003B5860(void) {
    func_003C3380();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5880);
#ifdef SKIP_ASM
extern void func_003C33E0();

void func_003B5880(void) {
    func_003C33E0();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B58A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void (*D_0044C46C[])(void);
extern char D_0050A8E8_58A0[] __asm__("D_0050A8E8");

void func_003B58A0(void) {
    D_0044C46C[0]();
    D_0050A8E8_58A0[0x176]++;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B58D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct G_58D8 { char pad[0x176]; volatile unsigned char depth; };
extern struct G_58D8 D_0050A8E8_58D8[] __asm__("D_0050A8E8");
extern void (*D_0044C470_58D8[])(void) __asm__("D_0044C470");

void func_003B58D8(void) {
    D_0050A8E8_58D8[0].depth--;
    D_0044C470_58D8[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5910);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_5910 {
    char pad0[0x174];
    signed char f174;
    char pad1[2];
    signed char f177;
    char pad2[0xC];
    int q[1];
};
extern struct S_5910 D_0050A8E8_5910 __asm__("D_0050A8E8");

void func_003B5910(int arg0) {
    if (D_0050A8E8_5910.f174 != 0) {
        D_0050A8E8_5910.q[D_0050A8E8_5910.f177] = arg0;
        D_0050A8E8_5910.f177++;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5948);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_5948 { char pad[0x174]; char on; char p1; char p2; signed char n; char pad2[12]; int arr[8]; };
extern struct S_5948 D_a8e8_5948 __asm__("D_0050A8E8");
extern void func_003B58A0();
extern void func_003B58D8();

void func_003B5948(int a) {
    int i;
    if (D_a8e8_5948.on) {
        func_003B58A0();
        for (i = 0; i < D_a8e8_5948.n; i++) {
            if (D_a8e8_5948.arr[i] == a) {
                D_a8e8_5948.n--;
                for (; i < D_a8e8_5948.n; i++) D_a8e8_5948.arr[i] = D_a8e8_5948.arr[i + 1];
                break;
            }
        }
        func_003B58D8();
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5A28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_5A28 {
    char pad0[0x174];
    signed char f174;
    char pad1[4];
    signed char f179;
    char pad2[0x4E];
    int q[1];
};
extern struct S_5A28 D_0050A8E8_5A28 __asm__("D_0050A8E8");

void func_003B5A28(int arg0) {
    if (D_0050A8E8_5A28.f174 != 0) {
        D_0050A8E8_5A28.q[D_0050A8E8_5A28.f179] = arg0;
        D_0050A8E8_5A28.f179++;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5A60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct G_5A60 { char pad[0x179]; signed char cnt; char pad2[0x4E]; int list[1]; };
extern struct G_5A60 D_0050A8E8_5A60[] __asm__("D_0050A8E8");

void func_003B5A60(int arg) {
    int i;
    func_003B58A0();
    for (i = 0; i < D_0050A8E8_5A60[0].cnt; i++) {
        if (D_0050A8E8_5A60[0].list[i] == arg) {
            D_0050A8E8_5A60[0].cnt--;
            if (i < D_0050A8E8_5A60[0].cnt) {
                do {
                    D_0050A8E8_5A60[0].list[i] = D_0050A8E8_5A60[0].list[i + 1];
                    i++;
                } while (i < D_0050A8E8_5A60[0].cnt);
            }
            break;
        }
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5B20);
#ifdef SKIP_ASM
extern void func_003B58A0();
extern void func_003B58D8();
extern int func_003C4E50(int, int);

int func_003B5B20(int arg0, int arg1) {
    int temp_16;

    func_003B58A0();
    temp_16 = func_003C4E50(arg0, arg1);
    func_003B58D8();
    return temp_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5B68);
#ifdef SKIP_ASM
extern void func_003B58A0();
extern void func_003B58D8();
extern int func_003C4EC8(int);

int func_003B5B68(int arg0) {
    int temp_16;

    func_003B58A0();
    temp_16 = func_003C4EC8(arg0);
    func_003B58D8();
    return temp_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5BA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct G_5BA0 { char pad[0xC]; unsigned int lim; };
extern struct G_5BA0 *D_0050AB1C_5BA0[] __asm__("D_0050AB1C");
void func_003B5BA0(int *a, int *b) {
    int x = *a;
    unsigned int lim = D_0050AB1C_5BA0[0]->lim;
    if (lim < (unsigned int)(x + *b))
        *b = lim - x;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5BD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct H_5BD0 { int f0; int f4; int f8; int fC; int f10; };
struct G_5BD0 { char pad[0x234]; struct H_5BD0 *cur; };
extern struct G_5BD0 D_0050A8E8_5BD0 __asm__("D_0050A8E8");

void func_003B5BD0(struct H_5BD0 *a0, int a1) {
    D_0050A8E8_5BD0.cur = a0;
    a0->f8 = a1;
    D_0050A8E8_5BD0.cur->f4 = (int)a0 + a1 - 8;
    a1 -= 0xF;
    D_0050A8E8_5BD0.cur->f0 = (int)a0 + 0x18;
    D_0050A8E8_5BD0.cur->f0 += 0xF;
    D_0050A8E8_5BD0.cur->f0 &= 0xFFFFFFF0;
    D_0050A8E8_5BD0.cur->fC = a1 - 0x20;
    D_0050A8E8_5BD0.cur->f10 = a1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5C40);
#ifdef SKIP_ASM
extern void func_003C6240();

void func_003B5C40(void) {
    func_003C6240();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B5C60);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5E98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B5E98_5E98(int) __asm__("func_003B5E98");
struct E_5E98 { int key; int val; };
struct S_5E98 { int base; struct E_5E98 *arr; int p2; int x; int p4; int cnt; };
struct G_5E98 { char pad[0x234]; struct S_5E98 *s; };
extern struct G_5E98 D_0050A8E8_5E98[] __asm__("D_0050A8E8");

void func_003B5E98_5E98(int a) {
    int i = 0;
    int d = a - D_0050A8E8_5E98[0].s->base;
    if (D_0050A8E8_5E98[0].s->cnt >= 0) return;
    while (1) {
        struct S_5E98 *s = D_0050A8E8_5E98[0].s;
        if (((struct E_5E98 *)((char *)s->arr + (i << 3)))->key == d) {
            s->cnt++;
            D_0050A8E8_5E98[0].s->x += 8;
            if (!(D_0050A8E8_5E98[0].s->cnt < i)) return;
            do {
                D_0050A8E8_5E98[0].s->arr[i] = D_0050A8E8_5E98[0].s->arr[i - 1];
                i--;
            } while (D_0050A8E8_5E98[0].s->cnt < i);
            return;
        }
        i--;
        if (!(s->cnt < i)) return;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5F60);
#ifdef SKIP_ASM
int func_003C51E0(void);
extern char D_0050AA5C[];

int func_003B5F60(void) {
    int r;
    if (D_0050AA5C[0] != 0) {
        r = func_003C51E0();
    } else {
        r = 0;
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B5F98);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6098);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Hdr_6098 { int pad0; short pad4; unsigned short n; int off; int size2; int size1; int tbl[1]; };
struct Ent_6098 { struct Hdr_6098 *hdr; char *buf1; char *buf2; char busy; };
struct G_6098 { char pad[0x1E4]; void (*cb)(); char pad2[0x1F4 - 0x1E8]; struct Ent_6098 *ents; };
extern struct G_6098 D_0050A8E8_6098 __asm__("D_0050A8E8");
extern void func_003B6300_6098() __asm__("func_003B6300");
extern int f_6500_6098(void) __asm__("func_003C6500");
extern char *f_4B70_6098(int, int) __asm__("func_003C4B70");
extern int f_42D8_6098(int, char *, char *, int) __asm__("func_003C42D8");
extern int f_42F8_6098(int) __asm__("func_003C42F8");
extern int f_6788_6098(int, char *, char *, int *) __asm__("func_003B6788");

int func_003B6098(int *out, struct Hdr_6098 *hdr) {
    struct Ent_6098 *ent;
    int i, n, h;
    int tmp;

    D_0050A8E8_6098.cb = func_003B6300_6098;
    *out = f_6500_6098();
    ent = &D_0050A8E8_6098.ents[*out];
    ent->busy = 1;
    ent->hdr = hdr;
    ent->buf1 = 0;
    if (hdr->size1 != 0) {
        ent->buf1 = f_4B70_6098(0x100, hdr->size1 + 0x40);
        if (ent->buf1 == 0) {
            goto fail;
        }
        for (i = 0; i < hdr->size1; i += 0x1000) {
            n = hdr->size1 - i;
            h = f_42D8_6098(0x100, (char *)hdr + hdr->off + i, ent->buf1 + i, n < 0x1001 ? n : 0x1000);
            while (f_42F8_6098(h) == 0) {
            }
        }
        tmp = 0;
        for (i = 0; i < hdr->n; i++) {
            if (hdr->tbl[i] != 0) {
                f_6788_6098(0x100, (char *)&hdr->tbl[i] + hdr->tbl[i], ent->buf1, &tmp);
            }
        }
    }
    ent->buf2 = 0;
    if (hdr->size2 != 0) {
        ent->buf2 = f_4B70_6098(8, hdr->size2 + 0x30);
        if (ent->buf2 == 0) {
fail:
            ent->hdr = 0;
            ent->busy = 0;
            return -6;
        }
        for (i = 0; i < hdr->size2; i += 0x1000) {
            n = hdr->size2 - i;
            h = f_42D8_6098(8, (char *)hdr + hdr->off + hdr->size1 + i, ent->buf2 + i, n < 0x1001 ? n : 0x1000);
            while (f_42F8_6098(h) == 0) {
            }
        }
        tmp = 0;
        for (i = 0; i < hdr->n; i++) {
            if (hdr->tbl[i] != 0) {
                f_6788_6098(8, (char *)&hdr->tbl[i] + hdr->tbl[i], ent->buf2, &tmp);
            }
        }
    }
    ent->busy = 0;
    if (hdr->size2 != 0 || hdr->size1 != 0) {
        return 7;
    }
    return 8;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B6300);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_6300 {
    void *p;
    char pad04[0xE];
    short f12;
    char pad14[0x8C - 0x14];
};
struct R_6300 {
    void *p0;
    int p4;
    int p8;
    char fC;
};
struct G_6300 {
    char pad000[0x28];
    unsigned short f28;
    char pad02A[0x17E - 0x2A];
    short f17E;
    char pad180[0x1F0 - 0x180];
    struct E_6300 *f1F0;
    struct R_6300 *f1F4;
};
extern struct G_6300 D_0050A8E8_6300 __asm__("D_0050A8E8");
extern void func_003B58A0_6300() __asm__("func_003B58A0");
extern void func_003B58D8_6300() __asm__("func_003B58D8");
extern void func_003B5F98_6300(void *buf, int n) __asm__("func_003B5F98");
extern int func_003B64D8_6300(int i) __asm__("func_003B64D8");
extern void func_003B89E0_6300(void *p) __asm__("func_003B89E0");
extern int func_003BAAC0_6300(char **pp, void *buf) __asm__("func_003BAAC0");
extern void func_003C4D78_6300(int a, int p) __asm__("func_003C4D78");
extern char *func_003C6540_6300(void *p, int i) __asm__("func_003C6540");

int func_003B6300(int arg0) {
    char buf[0xD0];
    char *q;
    void *obj;
    int i;
    int r;

    if (arg0 == -1) {
        for (i = 0; i < D_0050A8E8_6300.f28; i++) {
            func_003B6300(i);
        }
        return 0;
    }
    if (func_003B64D8_6300(arg0) != 0) {
        return -8;
    }
    func_003B58A0_6300();
    obj = D_0050A8E8_6300.f1F4[arg0].p0;
    for (i = 0; i < D_0050A8E8_6300.f17E; i++) {
        struct E_6300 *e = &D_0050A8E8_6300.f1F0[i];
        if (e->f12 == arg0) {
            func_003B89E0_6300(e->p);
        }
    }
    for (i = 0; i < *(unsigned short *)((char *)obj + 6); i++) {
        q = func_003C6540_6300(obj, i);
        if (q != 0) {
            q += 4;
            do {
                r = func_003BAAC0_6300(&q, buf);
                func_003B5F98_6300(buf, 2);
            } while (r != 0);
        }
    }
    if (D_0050A8E8_6300.f1F4[arg0].p4 != 0) {
        func_003C4D78_6300(0x100, D_0050A8E8_6300.f1F4[arg0].p4);
    }
    if (D_0050A8E8_6300.f1F4[arg0].p8 != 0) {
        func_003C4D78_6300(8, D_0050A8E8_6300.f1F4[arg0].p8);
    }
    D_0050A8E8_6300.f1F4[arg0].p0 = 0;
    D_0050A8E8_6300.f1F4[arg0].fC = 0;
    func_003B58D8_6300();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B64D8);
#ifdef SKIP_ASM
struct R_64D8 {
    void *p0;
    int p4;
    int p8;
    signed char fC;
};
struct G_64D8 {
    char pad000[0x28];
    unsigned short f28;
    char pad02A[0x1F4 - 0x2A];
    int f1F4;
};
extern struct G_64D8 D_0050A8E8_64D8 __asm__("D_0050A8E8");

int func_003B64D8(int arg0) {
    struct R_64D8 *r;
    if (arg0 < 0 || arg0 >= D_0050A8E8_64D8.f28) {
        return -8;
    }
    r = (struct R_64D8 *)(arg0 * 16 + D_0050A8E8_64D8.f1F4);
    if (r->p0 != 0) {
        return r->fC ? -0x12 : 0;
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6528);
#ifdef SKIP_ASM
typedef struct { int a; int b; int c; } B6528_inner;
typedef struct { B6528_inner *p; int pad[3]; } B6528_ent;
extern B6528_ent *D_0050AADC[];

int func_003B6528(int arg0) {
    return D_0050AADC[0][arg0].p->c;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6548);
#ifdef SKIP_ASM
extern void *func_0041610C_6548(void *, void *, int) __asm__("func_0041610C");
struct R_6548 { void *ptr; int pad[3]; };
struct G_6548 { char pad[0x1F4]; struct R_6548 *recs; };
extern struct G_6548 D_0050A8E8_6548 __asm__("D_0050A8E8");

int func_003B6548(void *dst, int idx) {
    int ret = 0;
    int n = func_003B6528(idx);
    if (n < 0) {
        ret = n;
    } else {
        func_0041610C_6548(dst, D_0050A8E8_6548.recs[idx].ptr, n);
        D_0050A8E8_6548.recs[idx].ptr = dst;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B65D0);
#ifdef SKIP_ASM
struct E_65D0 { int f0; char pad[0xE]; short f12; char pad2[0x8C - 0x14]; };
struct G_65D0 { char pad[0x17E]; short cnt; char pad2[0x1F0 - 0x180]; struct E_65D0 *tab; };
extern struct G_65D0 D_0050A8E8_65D0 __asm__("D_0050A8E8");
extern int f_64D8_65D0(int) __asm__("func_003B64D8");
extern int f_8AB8_65D0(int) __asm__("func_003B8AB8");

int func_003B65D0(int a) {
    int ok = 0;
    int i;
    if (f_64D8_65D0(a) != 0) return -8;
    func_003B58A0();
    for (i = 0; i < D_0050A8E8_65D0.cnt; i++) {
        struct E_65D0 *e = &D_0050A8E8_65D0.tab[i];
        if (e->f12 == a && f_8AB8_65D0(e->f0) == 0) {
            ok = 1;
            break;
        }
    }
    func_003B58D8();
    return ok;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6670);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B64D8_6670() __asm__("func_003B64D8");
extern void func_003BB820_6670(int, int, char *, int, int, int) __asm__("func_003BB820");
extern int func_003C6540_6670(int, int) __asm__("func_003C6540");
struct G_6670 { char pad[0x1F4]; int f1F4; };
extern struct G_6670 D_0050A8E8_6670 __asm__("D_0050A8E8");

int func_003B6670(int a0, int a1, char *a2, int a3, int a4) {
    int off, o, i;
    int *p;
    if (func_003B64D8_6670() < 0) return -8;
    off = a0 * 0x10;
    o = func_003C6540_6670(*(int *)(off + D_0050A8E8_6670.f1F4), a1);
    if (o == 0) return -8;
    i = 0;
    func_003B58A0();
    func_003BB820_6670(*(int *)(off + D_0050A8E8_6670.f1F4), o, a2, a3, a4, 0);
    if (*(unsigned char *)(a2 + 2) != 0) {
        p = (int *)(a3 + 0x18);
        do {
            if (*p != 0) {
                func_003B5E98(*p);
                *p = 0;
                p[6] = 0;
            }
            i++;
            p++;
        } while (i < *(unsigned char *)(a2 + 2));
    }
    func_003B58D8();
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B6788);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B5F98_6788(void *, int) __asm__("func_003B5F98");
extern int func_003BAAC0_6788(char **, void *) __asm__("func_003BAAC0");
extern void func_003C3EA8_6788(void *, int, int) __asm__("func_003C3EA8");

int func_003B6788(int arg0, char *arg1, int arg2, int arg3) {
    char sp[0xD0];
    char *spD0;
    int temp_16;

    spD0 = arg1 + 4;
    do {
        temp_16 = func_003BAAC0_6788(&spD0, sp);
        if (*(unsigned short *)(sp + 0x18) & arg0) {
            func_003C3EA8_6788(sp, arg2, arg3);
            func_003B5F98_6788(sp, 0);
        }
    } while (temp_16 != 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6820);
#ifdef SKIP_ASM
typedef struct { void *p; int pad[3]; } B6820_ent;
extern B6820_ent *D_0050AADC_6820[] __asm__("D_0050AADC");
extern int f_64D8_6820(int) __asm__("func_003B64D8");
extern void *f_6540_6820(void *, int) __asm__("func_003C6540");
extern int f_B588_6820(void *, void *, int, int, int) __asm__("func_003BB588");

int func_003B6820(int a, int b, int c) {
    char *obj;
    if (f_64D8_6820(a) < 0) return -8;
    obj = D_0050AADC_6820[0][a].p;
    if (b < 0 || b >= *(unsigned short *)(obj + 6)) return -8;
    return f_B588_6820(obj, f_6540_6820(obj, b), a, b, c);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B68B8);
#ifdef SKIP_ASM
extern int func_003B8CC8(int, int);
extern int func_003C6760(int, int, int, int);

void func_003B68B8(char *p) {
    int i = 0;
    char *q = p + 0x104;
    int *f = (int*)(p + 0x114);
    *(int *)(p + 4) = func_003C6760(*(int *)(p + 8), (int)(p + 0x14), (int)(p + 0x1C), (int)(p + 0xEC));
    do {
        if (*f != 0) {
            func_003B8CC8(*(int *)(p + 4), (int)q);
        }
        q += 0x18;
        i++;
        f += 6;
    } while (i == 0);
    *(char *)(p + 0x10) = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6948);
#ifdef SKIP_ASM
int func_003B6948(unsigned char *p) {
    int v = 0;
    int w = *(unsigned short *)p;
    int h = p[2];
    int t = p[3];
    w = w * h;
    if (t == 5) v = 0x92;
    else if (t == 10) v = 0x88;
    else if (t == 4) v = 0x33;
    else if (t == 22) v = 0x66;
    else if (t == 8) v = 0x200;
    else if (t == 16) return h << 3;
    else if (t == 23) return h << 3;
    return (w * v) >> 8;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B69D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad[0x46]; unsigned char cnt; } G_69D8;
extern void func_003B7838(int);
extern G_69D8 D_0050A8E8_A8E8_69D8 __asm__("D_0050A8E8");

int func_003B69D8(void) {
    int i;

    i = 0;
    if (D_0050A8E8_A8E8_69D8.cnt != 0) {
        do {
            func_003B7838(i);
            i += 1;
        } while (i < (int)D_0050A8E8_A8E8_69D8.cnt);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6A38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0050A0A0[];
extern unsigned char D_0050A92E_6A38[] __asm__("D_0050A92E");

int func_003B6A38(int arg0) {
    if (arg0 >= D_0050A92E_6A38[0] || arg0 < 0) {
        return 0;
    }
    return D_0050A0A0[arg0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6A70);
#ifdef SKIP_ASM
extern char *D_0050A0A0_6A70[] __asm__("D_0050A0A0");
extern void *func_003B7A70_6A70(int) __asm__("func_003B7A70");
extern void func_003C6320_6A70(void *, void *) __asm__("func_003C6320");
extern void func_003C6288_6A70(void *, void *) __asm__("func_003C6288");

void func_003B6A70(int arg0) {
    char *s = D_0050A0A0_6A70[arg0 & 0xFF];
    void *r = func_003B7A70_6A70(arg0);
    func_003C6320_6A70(s + 0x11C, r);
    func_003C6288_6A70(s + 0x128, r);
    if (*(void **)(s + 0x134) == r) {
        *(int *)(s + 0x134) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6AD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E13E8_6AD8(int, unsigned char *) __asm__("func_003E13E8");
extern int *D_0050A0A0_6AD8[] __asm__("D_0050A0A0");

void func_003B6AD8(void *arg0) {
    unsigned char *t = ((unsigned char **)arg0)[-1];
    func_003E13E8_6AD8(*D_0050A0A0_6AD8[*t], t);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6B10);
#ifdef SKIP_ASM
struct N_6B10 { char pad[0xC]; volatile int f0C; char pad2[4]; volatile unsigned f14; volatile unsigned f18; volatile unsigned f1C; };
struct S_6B10 { char pad[0x11C]; struct N_6B10 *node; };

void func_003B6B10(struct N_6B10 *node, unsigned n, struct S_6B10 *s) {
    unsigned left = 0;
    int i = 0;
    for (;;) {
        i++;
        node = s->node;
        if (i >= 0xC9) {
            func_003B6A70(node->f0C);
            return;
        }
        if (node->f1C < n) {
            left = n - node->f1C;
            n -= left;
        }
        node->f14 += n;
        node->f1C -= n;
        if (node->f14 >= node->f18) {
            func_003B6A70(node->f0C);
        }
        if (left == 0) return;
        n = left;
        left = 0;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B6BD0);

INCLUDE_ASM("ealib/seg_2B4578", func_003B6EA8);

INCLUDE_ASM("ealib/seg_2B4578", func_003B7080);
#ifdef SKIP_ASM
extern int *D_0050A0A0_7080[] __asm__("D_0050A0A0");
extern void func_003B6EA8_7080(int *) __asm__("func_003B6EA8");
extern void func_003B6BD0_7080(int) __asm__("func_003B6BD0");
extern void func_003E13E8_7080(int) __asm__("func_003E13E8");

int func_003B7080(int arg0, int *arg1) {
    int *o = D_0050A0A0_7080[arg0];
    int tag = *arg1;
    if (tag == 0x6C444353) {
        func_003B6EA8_7080(o);
        return 1;
    }
    if (*arg1 != 0x6C484353) {
        func_003E13E8_7080(*o);
        return 1;
    }
    func_003B6BD0_7080(arg0);
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B70F8);

INCLUDE_ASM("ealib/seg_2B4578", func_003B71D8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7410);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0050A0A0_7410[] __asm__("D_0050A0A0");
extern unsigned char D_0050A92E_7410[] __asm__("D_0050A92E");

int func_003B7410(void) {
    int n = 0;
    int i;

    for (i = 0; i < D_0050A92E_7410[0]; i++) {
        if (D_0050A0A0_7410[i] != 0) {
            n++;
        }
    }
    return n;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B7450);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B76E8);
#ifdef SKIP_ASM
struct O_76E8 { int f0; char pad4[8]; volatile int fC; char pad10[0x10C]; int f11C; char pad120[8]; int f128; int f12C; int f130; };
struct S_76E8 { char pad0[8]; int f8; volatile int fC; char pad10[0x10]; volatile int f20; char pad24[4]; };
extern struct O_76E8 *f_6A38_76E8(int) __asm__("func_003B6A38");
extern int f_0C88_76E8(int, int, int, int) __asm__("func_003E0C88");
extern int f_0D80_76E8(int, int, int, int) __asm__("func_003E0D80");
extern struct S_76E8 *f_62E8_76E8(void *) __asm__("func_003C62E8");
extern void f_6210_76E8(void *, int, int) __asm__("func_00416210");
extern void f_62B8_76E8(void *, void *) __asm__("func_003C62B8");

int func_003B76E8_impl(int, int, int, int, int) __asm__("func_003B76E8");
int func_003B76E8_impl(int a0, int a1, int a2, int a3, int a4) {
    struct O_76E8 *o = f_6A38_76E8(a0);
    struct S_76E8 *s;
    int r;
    if (o == 0) return -8;
    if (o->f130 == 0) return -13;
    if (a4 == 0) {
        r = f_0C88_76E8(o->f0, a2, a3, 0x6C454353);
    } else if (a4 == 1) {
        r = f_0D80_76E8(o->f0, a2, 0, 0x6C454353);
    } else {
        r = a3;
    }
    if (r == 0) return -1;
    func_003B58A0();
    a4 = (int)f_62E8_76E8((char *)o + 0x128);
    s = (struct S_76E8 *)a4;
    f_6210_76E8(s, 0, 0x28);
    f_62B8_76E8((char *)o + 0x11C, s);
    s->f8 = r;
    o->fC += 0x100;
    if (o->fC < 0) o->fC = 0;
    s->fC = o->fC | a0;
    s->f20 = a1;
    o = (struct O_76E8 *)s->fC;
    func_003B58D8();
    return (int)o;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7818);
#ifdef SKIP_ASM
void func_003B7818(int a, int b, int c, int d, int e) {
    func_003B7450(a, b, c, d, e, 0, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7838);
#ifdef SKIP_ASM
char *func_003B6A38_7838(int) __asm__("func_003B6A38");
extern int func_003B71D8_7838[] __asm__("func_003B71D8");
extern int func_003B7410_7838(void) __asm__("func_003B7410");
extern void func_003B78F8_7838(int) __asm__("func_003B78F8");
extern void func_003C6040_7838(int *) __asm__("func_003C6040");
extern int func_003C6DA0_7838(int) __asm__("func_003C6DA0");
extern void func_003E0A28_7838(int) __asm__("func_003E0A28");
extern int D_0050AAD4_7838 __asm__("D_0050AAD4");
extern int D_0050A0A0_7838[] __asm__("D_0050A0A0");

int func_003B7838_impl(int) __asm__("func_003B7838");
int func_003B7838_impl(int h) {
    char *o = func_003B6A38_7838(h);
    int w;
    signed char c;
    if (o == 0) return -8;
    func_003B78F8_7838(h);
    if (func_003B7410_7838() == 1) {
        func_003C6040_7838(func_003B71D8_7838);
        D_0050AAD4_7838 = 0;
    }
    func_003C6DA0_7838(*(volatile int *)(o + 8));
    w = *(int *)o;
    c = *(volatile unsigned char *)(o + 0x11);
    D_0050A0A0_7838[h] = 0;
    if (c == 0)
        func_003E0A28_7838(w);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B78D8);
#ifdef SKIP_ASM
extern void func_003B76E8(int, int, int, int, int);

void func_003B78D8(int a, int b, int c, int d) {
    func_003B76E8(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B78F8);
#ifdef SKIP_ASM
struct O_78F8 { int f0; volatile int f4; volatile int f8; char pad0C[4]; char f10; volatile unsigned char f11; char pad12[8]; unsigned char f1A; char pad1B[0x81]; int f9C[1]; };
extern struct O_78F8 *f_6A38_78F8(int) __asm__("func_003B6A38");
extern void f_6CE8_78F8(int) __asm__("func_003C6CE8");
extern void f_1110_78F8(int) __asm__("func_003E1110");
extern void f_5E98_78F8(int) __asm__("func_003B5E98");
extern void *f_62E8_78F8(void *) __asm__("func_003C62E8");
extern void f_6288_78F8(void *, void *) __asm__("func_003C6288");
extern void f_6210_78F8(void *, int, int) __asm__("func_00416210");

int func_003B78F8(int arg0) {
    struct O_78F8 *o;
    void *s;
    int i;
    func_003B58A0();
    o = f_6A38_78F8(arg0);
    if (o == 0) {
        func_003B58D8();
        return -8;
    }
    if (o->f4 >= 0) {
        f_6CE8_78F8(o->f8);
    }
    o->f4 = -1;
    if (o->f11 == 0) {
        f_1110_78F8(o->f0);
    }
    if (o->f9C[0] != 0) {
        i = 0;
        if (o->f1A != 0) {
            int *p = &o->f9C[0];
            do {
                i++;
                f_5E98_78F8(*p++);
            } while (i < o->f1A);
        }
    }
    do {
        s = f_62E8_78F8((char *)o + 0x11C);
        if (s == 0) break;
        f_6288_78F8((char *)o + 0x128, s);
    } while (1);
    *(int *)((char *)o + 0x134) = 0;
    o->f10 = 0;
    f_6210_78F8((char *)o + 0x14, 0, 4);
    f_6210_78F8((char *)o + 0x18, 0, 4);
    f_6210_78F8((char *)o + 0x1C, 0, 0x68);
    f_6210_78F8((char *)o + 0x84, 0, 0x68);
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7A70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
char *func_003B6A38_7A70(int) __asm__("func_003B6A38");

char *func_003B7A70(int arg0) {
    char *t;
    char *v;
    if (arg0 < 0) return 0;
    t = func_003B6A38_7A70(arg0 & 0xFF);
    if (t == 0) return 0;
    for (v = *(char **)(t + 0x11C); v != 0; v = *(char **)v) {
        if (*(int *)(v + 0xC) == arg0) break;
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7AC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C65F0(int);
int func_003B7AC8_7AC8(int arg0, int arg1) __asm__("func_003B7AC8");

int func_003B7AC8_7AC8(int arg0, int arg1) {
    int t = arg0 * 0x28 + 0x138;
    return t + func_003C65F0(arg1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7B00);
#ifdef SKIP_ASM
extern int func_003B7AC8();
extern int func_003E06B0(int, int, int);

int func_003B7B00(int arg0) {
    int temp_17;

    temp_17 = func_003B7AC8();
    return temp_17 + func_003E06B0(arg0 + 2, 1, 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7B48);
#ifdef SKIP_ASM
struct N_7B48 { char pad[0xC]; int fC; int f10; };
struct P_7B48 { char pad[0x10]; int f10; };
struct S_7B48 { int f0; char pad4[4]; int f8; char padC[8]; unsigned short f14; char pad16[0x106]; struct N_7B48 *f11C; char pad120[4]; int f124; };
extern struct S_7B48 *f_6A38_7B48(int) __asm__("func_003B6A38");
extern struct P_7B48 *f_7A70_7B48(int) __asm__("func_003B7A70");
extern unsigned int f_6C98_7B48(int) __asm__("func_003C6C98");
extern unsigned int f_14C8_7B48(int) __asm__("func_003E14C8");

int func_003B7B48_impl(int, int *) __asm__("func_003B7B48");
int func_003B7B48_impl(int arg0, int *out) {
    struct S_7B48 *s;
    struct N_7B48 *n;
    unsigned int t;
    int v;
    
    out[2] = 0;
    out[1] = 0;
    out[0] = 0;
    s = f_6A38_7B48(arg0);
    if (s == 0) return -8;
    v = s->f124;
    out[0] = v;
    if (v != 0) {
        n = s->f11C;
        out[1] = n->fC;
        if (s->f14 == 0) return 0;
        do {
            out[2] = f_6C98_7B48(s->f8) * 1000 / s->f14;
            if (out[2] != 0) return 0;
            n = (struct N_7B48 *)f_7A70_7B48(out[1]);
            if (n->f10 == 0) return 0;
        } while (0);
        t = f_14C8_7B48(s->f0);
        out[2] = (t > 0x3D0900 ? 0x3D0900 : t) * 1000 / n->f10;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7C40);
#ifdef SKIP_ASM
typedef struct { unsigned int lo, hi; } L64_7C40;
extern char *f6A38_7C40(int) __asm__("func_003B6A38");
extern char *f7A70_7C40(int) __asm__("func_003B7A70");
extern L64_7C40 f6380_7C40(int, int) __asm__("func_003C6380");
extern int f64A8_7C40(L64_7C40, int) __asm__("func_003C64A8");

int func_003B7C40(int h, int *out) {
    char *a;
    char *b;
    unsigned int d;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    if (h < 0 || (a = f6A38_7C40(h & 0xFF)) == 0) {
        return -8;
    }
    b = f7A70_7C40(h);
    if (b != 0) {
        if (*(unsigned char *)(b + 0x24) == 0) {
            out[0] = 0;
        } else {
            if (*(char **)(a + 0x11C) == b) {
                out[0] = 2;
                d = *(unsigned short *)(a + 0x14);
            } else {
                out[0] = 1;
                d = *(unsigned short *)(a + 0x18);
            }
            out[1] = f64A8_7C40(f6380_7C40(*(int *)(b + 0x14), 1000), d);
            out[2] = f64A8_7C40(f6380_7C40(*(int *)(b + 0x18) - *(int *)(b + 0x14), 1000), d);
            out[3] = (unsigned int)(*(int *)(b + 0x1C) * 1000) / d;
        }
    } else {
        out[0] = 3;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7D80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_003B7A70_7D80(int) __asm__("func_003B7A70");

int func_003B7D80(int arg0, int arg1) {
    int var_18;
    char *temp_2;

    var_18 = -8;
    func_003B58A0();
    temp_2 = func_003B7A70_7D80(arg0);
    if (temp_2 != 0) {
        var_18 = 0;
        *(int *)(temp_2 + 0x20) = (short)arg1;
    }
    func_003B58D8();
    return var_18;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7DE8);
#ifdef SKIP_ASM
extern void func_003B76E8(int, int, int, int, int);

void func_003B7DE8(int a, int b, int c) {
    func_003B76E8(a, b, 0, c, 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7E10);
#ifdef SKIP_ASM
extern void func_003B76E8(int, int, int, int, int);

void func_003B7E10(int a, int b, int c, int d) {
    func_003B76E8(a, b, c + d, 0, 1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7E38);
#ifdef SKIP_ASM
extern void func_003B7450(int, int, int, int, int, int, int);

void func_003B7E38(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    func_003B7450(arg1, arg2, arg3, arg4, arg5, arg0, 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7E70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B7E70(void) __asm__("func_003B6A38");
void func_003B85F0_func_003B7E70(int, int) __asm__("func_003B85F0");

int func_003B7E70(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B7E70();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(char *)((char *)p + 0xEC) = arg1;
    func_003B85F0_func_003B7E70(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7EB0);
#ifdef SKIP_ASM
int *func_003B6A38_7EB0(void) __asm__("func_003B6A38");
int func_003B8530_7EB0(int, int, int) __asm__("func_003B8530");

int func_003B7EB0(int arg0, int arg1, int arg2) {
    int *p;

    p = func_003B6A38_7EB0();
    if (p == 0) {
        return -8;
    }
    *(char *)((char *)p + 0xEC) = arg2;
    func_003B8530_7EB0(p[1], arg1 / 10, arg2);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7F18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_7F18(void) __asm__("func_003B6A38");
int func_003B86C0_7F18(int) __asm__("func_003B86C0");

int func_003B7F18(void) {
    int *p;
    int r;

    p = func_003B6A38_7F18();
    if (p == 0) {
        return -8;
    }
    r = func_003B86C0_7F18(*(volatile int *)(p + 1));
    if (r < 0) {
        r = *(signed char *)((char *)p + 0xEC);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7F60);
#ifdef SKIP_ASM
int *func_003B6A38_7F60(void) __asm__("func_003B6A38");
int func_003B8C00_7F60(int, int, int) __asm__("func_003B8C00");

int func_003B7F60(int arg0, int arg1, int arg2) {
    int *p;

    p = func_003B6A38_7F60();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(short *)((char *)p + 0xF4) = arg1;
    *(short *)((char *)p + 0xF6) = arg2;
    func_003B8C00_7F60(p[1], arg1, arg2);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7FB8);
#ifdef SKIP_ASM
int *func_003B6A38_7FB8(void) __asm__("func_003B6A38");
int func_003B8790_7FB8(int, int) __asm__("func_003B8790");

static inline int body_7FB8(int *p, int arg1) {
    if (arg1 > 0x4000) {
        arg1 = 0x4000;
    }
    *(short *)((char *)p + 0xF8) = arg1;
    func_003B8790_7FB8(p[1], arg1);
    return 0;
}

int func_003B7FB8(int arg0, int arg1) {
    int *p;
    p = func_003B6A38_7FB8();
    if (p == 0) {
        return -8;
    }
    if (arg1 > 0x4000) {
        arg1 = 0x4000;
    }
    *(short *)((char *)p + 0xF8) = arg1;
    func_003B8790_7FB8(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8010);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B8010(void) __asm__("func_003B6A38");
void func_003B8700_func_003B8010(int, int) __asm__("func_003B8700");

int func_003B8010(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B8010();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(char *)((char *)p + 0xF0) = arg1;
    func_003B8700_func_003B8010(p[1], arg1);
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B8050);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B80A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B80A0(void) __asm__("func_003B6A38");
void func_003B8978_func_003B80A0(int, int) __asm__("func_003B8978");

int func_003B80A0(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B80A0();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(short *)((char *)p + 0x100) = arg1;
    func_003B8978_func_003B80A0(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B80E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B80E0(void) __asm__("func_003B6A38");
void func_003B8838_func_003B80E0(int, int) __asm__("func_003B8838");

int func_003B80E0(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B80E0();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(short *)((char *)p + 0xFA) = arg1;
    func_003B8838_func_003B80E0(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_8120(void) __asm__("func_003B6A38");
void func_003E0B28_8120(int, int) __asm__("func_003E0B28");

int func_003B8120(int arg0, int arg1) {
    int *temp_2;

    temp_2 = func_003B6A38_8120();
    if (temp_2 == 0) {
        return -8;
    }
    func_003E0B28_8120(*temp_2, arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8160);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_A7B0_8160(int) __asm__("func_003BA7B0");
extern void f_2A50_8160(int) __asm__("func_003C2A50");
struct T_8160 { int w0; char pad[0x65]; char c69; char pad2[0x22]; };
struct G_8160 { char pad[0x175]; char c; char pad2[8]; short n; char pad3[0x6F]; struct T_8160 *tab; };
extern struct G_8160 D_0050A8E8_8160[] __asm__("D_0050A8E8");

int func_003B8160(int arg0) {
    int i;
    struct T_8160 *e;
    func_003B58A0();
    D_0050A8E8_8160[0].c = arg0;
    for (i = 0; i < D_0050A8E8_8160[0].n; i++) {
        e = (struct T_8160 *)((char *)D_0050A8E8_8160[0].tab + i * 0x8C);
        if (e->c69 == 1 && e->w0 >= 0) {
            f_A7B0_8160(i);
            f_2A50_8160(i);
        }
    }
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8218);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050AAE0_8218[] __asm__("D_0050AAE0");
extern char D_0050AAF4_8218[] __asm__("D_0050AAF4");
extern char D_0050AB08_8218[] __asm__("D_0050AB08");

void *func_003B8218(int arg0, int arg1) {
    switch (arg1 & 0x71C) {
    case 8:
        return (arg0 * 0x14) + D_0050AB08_8218;
    case 4:
        return (arg0 * 0x14) + D_0050AAE0_8218;
    case 0x100:
        return (arg0 * 0x14) + D_0050AAF4_8218;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8290);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
int func_003B8290(unsigned long a) {
    int t = (a & 0x40) >> 3;
    if (a & 0x10) t |= 4;
    if (a & 0x20) t |= 0x100;
    return t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B82B8);
#ifdef SKIP_ASM
struct Q_82B8 { short c; short pad2; int d; int e; };
extern int f8290_82B8(int) __asm__("func_003B8290");
extern struct Q_82B8 *f8218_82B8(int, int) __asm__("func_003B8218");
extern int f36A8_82B8(int, int) __asm__("func_003C36A8");
extern int f83A0_82B8(int, int) __asm__("func_003B83A0");

int func_003B82B8(int a, int b, int c, int d, int e) {
    int m;
    int bit = 4;
    int id;
    if ((a & 0x1F8) == 0) a |= 0x1F8;
    m = f8290_82B8(a);
    id = a & ~0x1F8;
    while (m != 0) {
        if (bit & m) {
            struct Q_82B8 *q = f8218_82B8(id, bit);
            q->c = c;
            q->d = d;
            q->e = e;
            f36A8_82B8(id, bit);
            m &= ~bit;
        }
        bit <<= 1;
    }
    f83A0_82B8(a, c ? b : 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B83A0);
#ifdef SKIP_ASM
/* func_003B83A0: 100.00 in the diff build (12/12 blocks, 80 insns, relocs agree) but NOT committable: with this function in place the unit build fails (SIZE MISMATCH, .org backwards -12) because func_003D4C40 (matched, unrelated) gets 2 extra short-loop pad nops + 1 trailing nop (SN as pads the copy loop according to a sticky provisional address). Workaround that makes score work (not committable): a dummy C function with 1-3 nops placed after INCLUDE_ASM(func_003D4B00) (scratch/w4/padins.py). Tricks: integer-add struct views (struct W{char pad[0x1FA]; char b;} *)(id*0x14 + (int)&G) for idx-first addu, (struct Wd*)((int)e + id) for base-first, arg0 |= 0x1F8 in place, callee 88C8 declared int (sweep). */
struct V_83Ab { float a; float b; };
struct E_83Ab { int f0; char pad4[0x5D]; signed char b61; char pad62[0x8C - 0x62]; };
struct Q_83Ab { char b; char pad[0x13]; };
struct G_83Ab { char pad[0x17E]; short cnt; char pad180[0x1F0 - 0x180]; struct E_83Ab *tab; char pad1F4[6]; struct Q_83Ab qa[1]; struct Q_83Ab qb[1]; struct Q_83Ab qc[1]; };
struct Wa_83Ab { char pad[0x1FA]; char b; };
struct Wb_83Ab { char pad[0x20E]; char b; };
struct Wc_83Ab { char pad[0x222]; char b; };
struct Wd_83Ab { char pad[0x61]; signed char b; };
extern struct G_83Ab D_0050A8E8_83Ab __asm__("D_0050A8E8");
extern void f58A0_83Ab(void) __asm__("func_003B58A0");
extern void f58D8_83Ab(void) __asm__("func_003B58D8");
extern void f84E0_83Ab(int, int, int, struct V_83Ab *) __asm__("func_003B84E0");
extern int f88C8_83Ab(int, int, int) __asm__("func_003B88C8");

int func_003B83A0(int arg0, int arg1) {
    int id = arg0 & ~0x1F8;
    int i;
    int f40;
    if ((arg0 & 0x1F8) == 0) {
        arg0 |= 0x1F8;
    }
    if (arg0 & 0x10) {
        ((struct Wa_83Ab *)(id * 0x14 + (int)&D_0050A8E8_83Ab))->b = arg1;
    }
    if (arg0 & 0x20) {
        ((struct Wb_83Ab *)(id * 0x14 + (int)&D_0050A8E8_83Ab))->b = arg1;
    }
    f40 = arg0 & 0x40;
    if (f40) {
        ((struct Wc_83Ab *)(id * 0x14 + (int)&D_0050A8E8_83Ab))->b = arg1;
    }
    f58A0_83Ab();
    if (f40) {
        struct V_83Ab v;
        v.b = v.a = (float)arg1 * 0.007874016f;
        f84E0_83Ab(id, 8, 0, &v);
    }
    for (i = 0; i < D_0050A8E8_83Ab.cnt; i++) {
        struct E_83Ab *e = &D_0050A8E8_83Ab.tab[i];
        f88C8_83Ab(e->f0, id, ((struct Wd_83Ab *)((int)e + id))->b);
    }
    f58D8_83Ab();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B84E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V_84E0 { int a; int b; };
struct E_84E0 { struct V_84E0 v; char pad[0xC]; };
extern struct E_84E0 D_0050AB14_84E0[] __asm__("D_0050AB14");
extern void func_003C36C8_84E0(int, int, int, struct V_84E0 *) __asm__("func_003C36C8");

int func_003B84E0(int arg0, int flags, int arg2, struct V_84E0 *v) {
    if (flags & 8) {
        D_0050AB14_84E0[arg0].v = *v;
    }
    func_003C36C8_84E0(arg0, flags, arg2, v);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8530);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BAA00_8530(int, int *) __asm__("func_003BAA00");
extern int func_003BA6E8_8530(void) __asm__("func_003BA6E8");
struct G_8530 { char pad[0x1F0]; char *tab; };
extern struct G_8530 D_0050A8E8_8530[] __asm__("D_0050A8E8");

int func_003B8530(int a, int n, int v) {
    int h = func_003BA6E8_8530();
    int sp0;
    if (h >= 0) {
        if (n <= 0) n = 1;
        sp0 = -1;
        v <<= 16;
        while (func_003BAA00_8530(h, &sp0)) {
            char *e = D_0050A8E8_8530[0].tab + sp0 * 0x8C;
            *(int *)(e + 0x34) = v;
            *(int *)(e + 0x30) = (v - *(int *)(e + 0x38)) / n;
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B85F0);
#ifdef SKIP_ASM
extern int func_003BAA00_85F0(int, int *) __asm__("func_003BAA00");
extern int func_003BA6E8_85F0(void) __asm__("func_003BA6E8");
extern void f_A7B0_85F0(int) __asm__("func_003BA7B0");
extern void f_2A50_85F0(int) __asm__("func_003C2A50");
extern void f_27E0_85F0(int, int) __asm__("func_003C27E0");
struct E_85F0 { short f0; short f2; short f4; char pad6[0x2A]; int f30; int f34; int f38; char pad3C[0x26]; short f62; };
struct G_85F0 { char pad[0x1F0]; struct E_85F0 *tab; };
extern struct G_85F0 D_0050A8E8_85F0[] __asm__("D_0050A8E8");

int func_003B85F0_impl(int, int) __asm__("func_003B85F0");
int func_003B85F0_impl(int arg0, int arg1) {
    int h = func_003BA6E8_85F0();
    int sp0;
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00_85F0(h, &sp0) != 0) {
            struct E_85F0 *e = (struct E_85F0 *)((char *)D_0050A8E8_85F0[0].tab + sp0 * 0x8C);
            int v = arg1 << 16;
            e->f30 = 0;
            if (e->f38 == v) return 0;
            e->f38 = v;
            f_A7B0_85F0(sp0);
            f_2A50_85F0(sp0);
            if (e->f62 > 0) f_27E0_85F0(e->f4, 0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B86C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_0050AAD8_86C0[] __asm__("D_0050AAD8");

short func_003B86C0(void) {
    int i = (int)func_003BA6E8();
    if (i < 0) {
        return -8;
    }
    return *(short *)(D_0050AAD8_86C0[0] + i * 0x8C + 0x3A);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8700);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BAA00_8700(int, int *) __asm__("func_003BAA00");
extern void func_003C2EC8_8700(int) __asm__("func_003C2EC8");
struct G_8700 { char pad[0x1F0]; char *tbl; };
extern struct G_8700 D_0050A8E8_8700 __asm__("D_0050A8E8");

int func_003B8700(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8();
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00_8700(h, &sp0) != 0) {
            
            *(char *)(D_0050A8E8_8700.tbl + sp0 * 0x8C + 0x5F) = arg1;
            func_003C2EC8_8700(sp0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8790);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BA6E8_8790(void) __asm__("func_003BA6E8");
extern void func_003BA938_8790(int, int) __asm__("func_003BA938");
extern int func_003BAA00_8790(int, int *) __asm__("func_003BAA00");
extern void func_003C25E0_8790(int) __asm__("func_003C25E0");
extern char D_0050A8E8_8790[] __asm__("D_0050A8E8");
int func_003B8790_8790(int a0, int arg1) __asm__("func_003B8790");

int func_003B8790_8790(int a0, int arg1) {
    int sp0;
    int h;
    char *e;
    char *g;
    int i;
    h = func_003BA6E8_8790();
    if (h >= 0) {
        sp0 = -1;
        g = D_0050A8E8_8790;
        while (func_003BAA00_8790(h, &sp0) != 0) {
            i = sp0;
            e = *(char **)(g + 0x1F0) + i * 0x8C;
            if (*(unsigned short *)(e + 0x88) == arg1) {
                return 0;
            }
            *(unsigned short *)(e + 0x88) = arg1;
            func_003BA938_8790(i, i);
            func_003C25E0_8790(sp0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8838);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BAA00_8838(int, int *) __asm__("func_003BAA00");
extern void func_003C3010_8838(int, int) __asm__("func_003C3010");
struct G_8838 { char pad[0x1F0]; char *tbl; };
extern struct G_8838 D_0050A8E8_8838 __asm__("D_0050A8E8");

int func_003B8838(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8();
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00_8838(h, &sp0) != 0) {
            int i = sp0;
            *(short *)(D_0050A8E8_8838.tbl + i * 0x8C + 0x6A) = arg1;
            func_003C3010_8838(i, arg1);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B88C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BA6E8_88C8() __asm__("func_003BA6E8");
extern void func_003BA740_88C8(int, int) __asm__("func_003BA740");
extern int func_003BAA00_88C8(int, int *) __asm__("func_003BAA00");
extern void func_003C27E0_88C8(int, int) __asm__("func_003C27E0");
extern char D_0050A8E8_88C8[] __asm__("D_0050A8E8");

int func_003B88C8(int arg0, int arg1, int arg2) {
    int sp0;
    int t;
    char *b;
    t = func_003BA6E8_88C8();
    if (t >= 0) {
        sp0 = -1;
        b = D_0050A8E8_88C8;
        while (func_003BAA00_88C8(t, &sp0) != 0) {
            *(char *)(sp0 * 0x8C + *(int *)(b + 0x1F0) + arg1 + 0x61) = arg2;
            func_003BA740_88C8(arg1, sp0);
            func_003C27E0_88C8(sp0, arg1);
        }
    }
    return t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8978);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BAA00_8978(int, int *) __asm__("func_003BAA00");
extern void func_003C3178_8978(int, int) __asm__("func_003C3178");

int func_003B8978(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8();
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00_8978(h, &sp0) != 0) {
            func_003C3178_8978(sp0, arg1);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B89E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003BA6E8_89E0(void) __asm__("func_003BA6E8");
int func_003BAA00_89E0(int, int *) __asm__("func_003BAA00");
void func_003C2440_89E0(int) __asm__("func_003C2440");

int func_003B89E0(void) {
    int sp0;
    int temp_2;

    temp_2 = func_003BA6E8_89E0();
    if (temp_2 >= 0) {
        sp0 = -1;
        while (func_003BAA00_89E0(temp_2, &sp0) != 0) {
            func_003C2440_89E0(sp0);
        }
    }
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8A38);
#ifdef SKIP_ASM
struct E_8A38 { int f0; char pad[0x8C - 4]; };
struct G_8A38 { char pad[0x17E]; short cnt; char pad2[0x1F0 - 0x180]; struct E_8A38 *tab; };
extern struct G_8A38 D_0050A8E8_8A38 __asm__("D_0050A8E8");
extern int f_89E0_8A38(int) __asm__("func_003B89E0");

void func_003B8A38(void) {
    int i = 0;
    func_003B58A0();
    for (i = 0; i < D_0050A8E8_8A38.cnt; i++) {
        f_89E0_8A38(D_0050A8E8_8A38.tab[i].f0);
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8AB8);
#ifdef SKIP_ASM
extern unsigned int func_003BA6E8();

unsigned int func_003B8AB8(void) {
    return func_003BA6E8() >> 0x1F;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B8AD8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8C00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_8C00 { char p0[0x1C]; unsigned short s1c; unsigned short s1e; char p1[0x2C]; unsigned short s4c; char p2[0x8C - 0x4E]; };
struct G_8C00 { char pad[0x1F0]; struct E_8C00 *tab; };
extern struct G_8C00 D_0050A8E8_8C00[] __asm__("D_0050A8E8");

int func_003B8C00(int a, int b, int c) {
    int h;
    int sp0;
    if (c >= 0x4000) {
        c = 0x3FFF;
    } else if (c < -0x4000) {
        c = -0x4000;
    }
    h = func_003BA6E8();
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0)) {
            struct E_8C00 *e = &D_0050A8E8_8C00[0].tab[sp0];
            e->s1c = e->s4c + b;
            e->s1e = c;
            func_003C38E0(sp0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8CC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BAA00_8CC8(int, int *) __asm__("func_003BAA00");
extern void func_003C5068_8CC8(int, int) __asm__("func_003C5068");

int func_003B8CC8(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8();
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00_8CC8(h, &sp0) != 0) {
            func_003C5068_8CC8(sp0, arg1);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8D30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BAA00_8D30(int, int *) __asm__("func_003BAA00");
extern void func_003C5128_8D30(int, int) __asm__("func_003C5128");

int func_003B8D30(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8();
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00_8D30(h, &sp0) != 0) {
            func_003C5128_8D30(sp0, arg1);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8D98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad[0x10]; int key; char pad2[0x5C]; } E_8D98;
extern E_8D98 D_0050A120_8D98[] __asm__("D_0050A120");

int func_003B8D98(int arg0) {
    int idx;
    int v = arg0;
    if (v < 0)
        return -8;
    idx = v & 0x1F;
    if (idx < 0x10)
        return (D_0050A120_8D98[idx].key ^ v) == 0 ? idx : -8;
    return -8;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8DE8);
#ifdef SKIP_ASM
struct E_8DE8 { char pad0[0x10]; int f10; int f14; int f18; int f1C; char pad20[0x50]; };
struct V_8DE8 { int id; signed char owner; signed char slot; char pad[2]; };
extern struct E_8DE8 D_0050A120_8DE8[] __asm__("D_0050A120");
extern struct V_8DE8 D_0050A820_8DE8[] __asm__("D_0050A820");
extern void f_9920_8DE8(int) __asm__("func_003B9920");
extern int f_85F0_8DE8(int, int) __asm__("func_003B85F0");

int func_003B8DE8_impl(int) __asm__("func_003B8DE8");
int func_003B8DE8_impl(int id) {
    struct E_8DE8 *e = &D_0050A120_8DE8[id];
    struct V_8DE8 *v;
    int i;
    e->f14 = e->f14 + e->f18;
    if (e->f18 < 0) {
        if (!(e->f1C < e->f14)) {
            e->f14 = e->f1C;
            e->f18 = 0;
        }
    } else {
        if (!(e->f14 < e->f1C)) {
            e->f14 = e->f1C;
            e->f18 = 0;
        }
    }
    if (e->f14 < 0) {
        f_9920_8DE8(e->f10);
        return 1;
    }
    i = 0x17;
    v = D_0050A820_8DE8;
    do {
        if (v->owner == id && v->id >= 0) {
            f_85F0_8DE8(v->id, ((*(unsigned int *)((char *)e + (v->slot << 2) + 0x30) >> 10 & 0x7F) * *(short *)((char *)e + 0x16)) >> 7);
        }
        i--;
        v++;
    } while (i >= 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8EE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_8EE8 { int id; signed char owner; char pad[3]; };
extern struct E_8EE8 D_0050A820_8EE8[] __asm__("D_0050A820");
extern int func_003BA6E8_8EE8(int) __asm__("func_003BA6E8");

int func_003B8EE8(int arg0) {
    int i;
    int r = 1;
    for (i = 0; i < 0x18; i++) {
        if (D_0050A820_8EE8[i].owner == arg0 && D_0050A820_8EE8[i].id >= 0 && func_003BA6E8_8EE8(D_0050A820_8EE8[i].id) >= 0) {
            r = 0;
            break;
        }
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B8F78);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9140);
#ifdef SKIP_ASM
extern void f7138_9140(int) __asm__("func_003C7138");
struct T_9140 { char pad[8]; int cnt; char pad2[0x64]; };
extern struct T_9140 D_0050A120_9140[] __asm__("D_0050A120");
typedef struct { int a; signed char b, c, d, e; } E_9140;

void func_003B9140(int arg0, int arg1, int arg2) {
    struct T_9140 *t = D_0050A120_9140;
    E_9140 *p;
    int i = 0;
    t[arg0].cnt++;
    p = (E_9140 *)((char *)t + 0x700);
    do {
        if (p->b == arg0 && p->c == arg1 && p->d == arg2 && p->e >= 0) {
            f7138_9140(p->a);
            p->e = -1;
            break;
        }
        i++;
        p++;
    } while (i < 0x18);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B91E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Ch_91E0 {
    char pad00[0x8];
    unsigned char *p8;
    unsigned char *pC;
    char pad10[0x16 - 0x10];
    short f16;
    char pad18[0x20 - 0x18];
    unsigned short f20;
    char pad22[0x26 - 0x22];
    unsigned char f26;
    char pad27[0x70 - 0x27];
};
struct V_91E0 {
    int h;
    signed char ch;
    signed char x;
    char pad[2];
};
struct G_91E0 {
    struct Ch_91E0 ch[16];
    struct V_91E0 v[24];
};
struct Bits_91E0 {
    unsigned int a : 10;
    unsigned int b : 7;
};
extern struct G_91E0 D_0050A120_91E0 __asm__("D_0050A120");
extern void func_003B85F0(int, unsigned int);
extern int func_003BC570_91E0(int v) __asm__("func_003BC570");

void func_003B91E0(int h, struct Bits_91E0 *bits, int x, int cmd) {
    struct V_91E0 *p = (struct V_91E0 *)&D_0050A120_91E0;
    struct Ch_91E0 *e = (struct Ch_91E0 *)((char *)p + h * 0x70);
    unsigned char *s;
    int i;

    if (cmd == 20) {
        unsigned char *t = e->p8 + 1;
        e->p8 = t;
        e->pC = t;
        return;
    } else if (cmd == 30) {
        if (e->f26 >= 0x7F) {
            e->f26 = *e->p8;
        }
        if (e->f26 != 0) {
            e->f26--;
            e->p8 = e->pC;
            return;
        }
    } else if (cmd == 7) {
        s = e->p8;
        p = (struct V_91E0 *)((char *)p + 0x700);
        i = 0x17;
        bits->b = *s;
        e->p8 = s + 1;
        do {
            if (p->ch == h && p->x == x) {
                func_003B85F0(p->h, (unsigned int)(bits->b * e->f16) >> 7);
            }
            i--;
            p++;
        } while (i >= 0);
        return;
    } else if (cmd == 10) {
        p = (struct V_91E0 *)((char *)p + 0x700);
        i = 0x17;
        bits->a = func_003BC570_91E0(*e->p8++) >> 6;
        do {
            if (p->ch == h && p->x == x) {
                int v = ((*(unsigned int *)bits & 0x3FF) << 6) + e->f20;
                func_003B8C00(p->h, (unsigned short)v, 0);
            }
            i--;
            p++;
        } while (i >= 0);
        return;
    }
    e->p8++;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B93C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct B_93C8 { unsigned int lo : 17; unsigned int f : 7; unsigned int hi : 8; };
struct E_93C8 { int id; signed char owner; signed char sub; short pad; };
struct R_93C8 { char pad0[8]; unsigned char *cur; char pad1[0x70 - 12]; };
struct G_93C8 { struct R_93C8 r[16]; struct E_93C8 e[24]; };
extern struct G_93C8 D_a120_93C8 __asm__("D_0050A120");
extern void fC6B8_93C8(int, int) __asm__("func_003BC6B8");

void func_003B93C8(int a0, struct B_93C8 *a1, int a2, int a3) {
    struct R_93C8 *r = &D_a120_93C8.r[a0];
    int t, i;
    struct E_93C8 *e = &D_a120_93C8.e[0];
    i = 0x17;
    t = (*r->cur++ << 7) + a3;
    a1->f = t / 128;
    do {
        i -= 1;
        if (e->owner == a0 && e->sub == a2) {
            fC6B8_93C8(e->id, a1->f);
        }
        e += 1;
    } while (i >= 0);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B94B0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B96B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B8DE8_96B8(int) __asm__("func_003B8DE8");
extern void func_003B94B0_96B8(int) __asm__("func_003B94B0");
struct E_96B8 { int f0; unsigned int f4; char pad[0x18 - 8]; int f18; char pad2[0x24 - 0x1C]; unsigned short u24; char pad4[2]; signed char st; char pad3[0x70 - 0x29]; };
extern struct E_96B8 D_0050A120_96B8[] __asm__("D_0050A120");

void func_003B96B8(void) {
    int i;
    struct E_96B8 *e;
    signed char st;
    unsigned int lim;
    int t;
    for (i = 0; i < 16; i++) {
        e = &D_0050A120_96B8[i];
        st = e->st;
        if (st == 3 && (e->f18 == 0 || func_003B8DE8_96B8(i) == 0)) {
            t = e->f0;
            lim = (unsigned int)(t * e->u24) / 100u;
            e->f0 = t + 1;
            if (lim >= e->f4 && e->st == st) {
                do {
                    func_003B94B0_96B8(i);
                    e->f4++;
                } while (lim >= e->f4 && e->st == 3);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B97D8);
#ifdef SKIP_ASM
struct A_97D8 { int a; char pad; signed char b; signed char c; signed char d; };
struct B_97D8 { char pad[0x10]; int v; char pad2[0x14]; signed char w; char pad3[0x47]; };
struct G_97D8 { char pad[0x1E8]; void (*f1E8)(void); };
extern struct A_97D8 D_0050A820_97D8[] __asm__("D_0050A820");
extern struct B_97D8 D_0050A120_97D8[] __asm__("D_0050A120");
extern struct G_97D8 D_0050A8E8_97D8 __asm__("D_0050A8E8");
extern void func_003B58A0();
extern void func_003B58D8();
extern void f_5910_97D8(void (*)(void)) __asm__("func_003B5910");
extern void f_96B8_97D8(void) __asm__("func_003B96B8");
extern void f_9880_97D8(void) __asm__("func_003B9880");

int func_003B97D8(void) {
    int i;
    struct A_97D8 *a;
    struct B_97D8 *b;
    int end;
    func_003B58A0();
    for (i = 0; i < 24; i++) {
        D_0050A820_97D8[i].b = -1;
        D_0050A820_97D8[i].c = 0;
        D_0050A820_97D8[i].d = 0;
        D_0050A820_97D8[i].a = -1;
    }
    b = D_0050A120_97D8;
    end = (int)(b + 16);
    do {
        b->v = -1;
        b->w = 0;
        b++;
    } while ((int)b < end);
    f_5910_97D8(f_96B8_97D8);
    D_0050A8E8_97D8.f1E8 = f_9880_97D8;
    func_003B58D8();
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B9880);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B5948_9880(void (*)(void)) __asm__("func_003B5948");
extern void func_003B96B8_9880(void) __asm__("func_003B96B8");
extern void func_003B98C0_9880(void) __asm__("func_003B98C0");
extern int D_0050AAD0_9880[] __asm__("D_0050AAD0");

int func_003B9880(void) {
    func_003B58A0();
    func_003B98C0_9880();
    func_003B5948_9880(func_003B96B8_9880);
    D_0050AAD0_9880[0] = 0;
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B98C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a[4]; int v; int pad[0x17]; } E_98C0;
extern void func_003B58A0();
extern void func_003B58D8();
extern void func_003B9920(int);
extern E_98C0 D_0050A120_A120_98C0[] __asm__("D_0050A120");

int func_003B98C0(void) {
    E_98C0 *tbl;
    int *p;
    int i;

    i = 0xF;
    func_003B58A0();
    tbl = D_0050A120_A120_98C0;
    p = &tbl->v;
    do {
        i -= 1;
        func_003B9920(*p);
        p += 0x1C;
    } while (i >= 0);
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9920);
#ifdef SKIP_ASM
struct E_9920 { char pad0[0x10]; int f10; char pad14[0x14]; signed char f28; char pad29[0x47]; };
struct V_9920 { int id; signed char owner; signed char s5; signed char s6; signed char s7; };
extern struct E_9920 D_0050A120_9920[] __asm__("D_0050A120");
extern struct V_9920 D_0050A820_9920[] __asm__("D_0050A820");
extern int f_8D98_9920(int) __asm__("func_003B8D98");
extern void f_89E0_9920(int) __asm__("func_003B89E0");

int func_003B9920_9920(int) __asm__("func_003B9920");
int func_003B9920_9920(int arg0) {
    int idx = f_8D98_9920(arg0);
    struct E_9920 *e;
    struct V_9920 *vt;
    int i;
    if (idx < 0) return idx;
    e = &D_0050A120_9920[idx];
    if (e->f28 != 0) {
        vt = (struct V_9920 *)&D_0050A120_9920[16];
        for (i = 0; i < 24; i++) {
            if (vt[i].owner == idx) {
                if (vt[i].id >= 0) f_89E0_9920(vt[i].id);
                vt[i].s5 = -1;
                vt[i].s6 = 0;
                vt[i].s7 = 0;
                vt[i].id = -1;
            }
        }
        e->f10 = -1;
        e->f28 = 2;
        return 0;
    }
    return -1;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B9A00);

INCLUDE_ASM("ealib/seg_2B4578", func_003B9B68);

INCLUDE_ASM("ealib/seg_2B4578", func_003B9C20);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9D00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B89E0_9D00(int) __asm__("func_003B89E0");
extern int D_0050A120_9D00[] __asm__("D_0050A120");
typedef struct { int a; signed char b; char pad[3]; } E_9D00;

int func_003B9D00(int arg0) {
    int r, h, i;

    E_9D00 *p;
    char *t;

    func_003B58A0();
    h = func_003B8D98(arg0);
    if (h < 0) {
        func_003B58D8();
        return h;
    }
    t = (char*)D_0050A120_9D00 + h * 0x70;
    if (*(signed char*)(t + 0x28) == 3) {
        p = (E_9D00*)(((char*)D_0050A120_9D00) + 0x700);
        *(signed char*)(t + 0x28) = 5;
        i = 0x17;
        do {
            i--;
            if (p->b == h) {
                if (p->a >= 0) func_003B89E0_9D00(p->a);
            }
            p++;
        } while (i >= 0);
    }
    r = func_003B9FC8(arg0);
    func_003B58D8();
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9DC8);
#ifdef SKIP_ASM
extern char D_0050A120_9DC8[] __asm__("D_0050A120");

int func_003B9DC8(int arg0) {
    int r, h;
    char *t;

    func_003B58A0();
    h = func_003B8D98(arg0);
    if (h < 0) {
        func_003B58D8();
        return h;
    }
    t = D_0050A120_9DC8 + h * 0x70;
    if (*(signed char *)(t + 0x28) == 5)
        *(signed char *)(t + 0x28) = 3;
    r = func_003B9FC8(arg0);
    func_003B58D8();
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9E48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A120_9E48[] __asm__("D_0050A120");
extern int func_003B8D98_9E48() __asm__("func_003B8D98");
extern void func_003B85F0(int, unsigned int);

int func_003B9E48(int a0, int vol) {
    int ret = 0;
    int idx = func_003B8D98_9E48();
    if (idx < 0) {
        return idx;
    }
    {
        int key = vol << 16;
        char *e = D_0050A120_9E48 + idx * 0x70;
        *(int *)(e + 0x18) = 0;
        if (*(int *)(e + 0x14) != key) {
            if (*(signed char *)(e + 0x28) == 3) {
                char *p;
                int i;
                *(int *)(e + 0x14) = key;
                p = D_0050A120_9E48 + 0x700;
                i = 0x17;
                do {
                    if (*(signed char *)(p + 4) == idx) {
                        int v = *(int *)p;
                        if (v >= 0) {
                            unsigned x = *(unsigned *)(e + (*(signed char *)(p + 5) << 2) + 0x30);
                            func_003B85F0(v, ((x >> 10 & 0x7F) * vol) >> 7);
                        }
                    }
                    i -= 1;
                    p += 8;
                } while (i >= 0);
            } else {
                ret = -1;
            }
        }
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9F38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A120_9F38[] __asm__("D_0050A120");

int func_003B9F38(int arg0, int arg1, int arg2) {
    int r;
    char *e;
    int t;
    r = func_003B8D98(arg0);
    if (r < 0) return r;
    e = D_0050A120_9F38 + r * 0x70;
    if (*(signed char *)(e + 0x28) == 3) {
        if (arg1 <= 0) arg1 = 1;
        t = arg2 << 16;
        *(int *)(e + 0x1C) = t;
        *(int *)(e + 0x18) = (t - *(int *)(e + 0x14)) / arg1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9FC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
signed char func_003B8D98_9FC8(void) __asm__("func_003B8D98");
extern char D_0050A120_A120[] __asm__("D_0050A120");

signed char func_003B9FC8(void) {
    signed char var_5;
    char *temp_2;

    var_5 = func_003B8D98_9FC8();
    if (var_5 >= 0) {
        temp_2 = D_0050A120_A120 + var_5 * 0x70;
        var_5 = *(signed char *)(temp_2 + 0x28);
        if (var_5 == 3) {
            var_5 = (*(int *)(temp_2 + 0x18) != 0) ? 6 : var_5;
        }
    }
    return var_5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA020);
#ifdef SKIP_ASM
struct S_A020 {
    unsigned char b0, b1, b2, b3, b4, b5;
    short pad6;
    unsigned short h8, hA, hC, hE, h10, h12, h14, h16;
};

int func_003BA020(struct S_A020 *s) {
    s->hC = 0x1000;
    s->b2 = 0x3C;
    s->hE = 0x1000;
    s->h10 = 0x1000;
    s->h12 = 0;
    s->h14 = 0xFFFF;
    s->h16 = 0;
    s->b1 = 0x40;
    s->b3 = 0x7F;
    s->b0 = 0x7F;
    s->b4 = 0x7F;
    s->b5 = 0x7F;
    s->h8 = 0;
    s->hA = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA078);
#ifdef SKIP_ASM
extern short D_0050AC20[];

int func_003BA078(int arg0, int arg1) {
    int i;
    for (i = 0; i < arg1; i++) {
        if (D_0050AC20[i] == arg0) {
            return 1;
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BA0B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA550);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_A550 { int f0; char pad[0x22]; unsigned char f26; unsigned char f27; char pad2[4]; int f2C; char pad3[0x69 - 0x30]; signed char f69; char pad4[0x8C - 0x6A]; };
struct G_A550 { char pad[0x17E]; short cnt; int f180; char pad2[0x1F0 - 0x184]; struct E_A550 *tab; };
extern struct G_A550 D_0050A8E8_A550 __asm__("D_0050A8E8");
void func_003BA550(int i, unsigned char u) {
    struct E_A550 *e = &D_0050A8E8_A550.tab[i];
    unsigned char k = e->f26;
    int n = 0;
    int sel = -1;
    int j;
    if (k != 0) {
        for (j = 0; j < D_0050A8E8_A550.cnt; j++) {
            struct E_A550 *q = &D_0050A8E8_A550.tab[j];
            if (q->f26 == k && q->f0 >= 0 && q->f69 != 0) {
                n++;
                if (q->f27) sel = j;
            }
        }
        e = &D_0050A8E8_A550.tab[i];
        if (n == 1) {
            e->f69 = 0;
            e->f26 = 0;
            e->f27 = 0;
            e->f2C = D_0050A8E8_A550.f180;
            return;
        }
        if (D_0050A8E8_A550.tab[sel].f69 == 2 && i != sel && n == 2) {
            e->f69 = 0;
            e->f26 = 0;
            e->f27 = 0;
            e->f2C = D_0050A8E8_A550.f180;
            D_0050A8E8_A550.tab[sel].f69 = 0;
            D_0050A8E8_A550.tab[sel].f26 = 0;
            D_0050A8E8_A550.tab[sel].f27 = 0;
            D_0050A8E8_A550.tab[sel].f2C = D_0050A8E8_A550.f180;
            return;
        }
        if (D_0050A8E8_A550.tab[sel].f69 == 1 && i == sel) {
            D_0050A8E8_A550.tab[sel].f69 = 2;
            return;
        }
        e->f69 = 0;
        e->f26 = 0;
        e->f27 = 0;
        e->f2C = D_0050A8E8_A550.f180;
        return;
    }
    e->f69 = 0;
    e->f26 = 0;
    e->f27 = 0;
    e->f2C = D_0050A8E8_A550.f180;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA6E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A8E8_A8E8[] __asm__("D_0050A8E8");

int func_003BA6E8_A6E8(int arg0) __asm__("func_003BA6E8");
int func_003BA6E8_A6E8(int arg0) {
    int var_5;
    char *temp_2;
    char *g;

    if ((arg0 < 0) || (g = D_0050A8E8_A8E8, var_5 = arg0 & 0xFF, (var_5 < *(short *)(g + 0x17E)) == 0)) {
        return -8;
    }
    temp_2 = *(char **)(g + 0x1F0) + (var_5 * 0x8C);
    if ((*(signed char *)(temp_2 + 0x69) == 0) || (*(int *)temp_2 != arg0)) {
        var_5 = -8;
    }
    return var_5;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BA740);

INCLUDE_ASM("ealib/seg_2B4578", func_003BA7B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA888);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044C480_A888[] __asm__("D_0044C480");

int func_003BA888(int x) {
    int scale = 0x1000;
    int t;
    while (x >= 0x4B0) {
        x -= 0x4B0;
        scale <<= 1;
    }
    while (x < -0x4AF) {
        x += 0x4B0;
        scale >>= 1;
    }
    t = (x * 0x369D) >> 16;
    if (t <= -0x100)
        t = -0xFF;
    if (t < 0)
        scale = (scale * (D_0044C480_A888[t + 0x100] + 0x100)) >> 9;
    else
        scale = (scale * (D_0044C480_A888[t] + 0x100)) >> 8;
    return scale;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BA938);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BAA00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_AA00 { int w; char p0[0x22]; unsigned char type; char p1[0x42]; signed char b; char p2[0x22]; };
struct G_AA00 { char pad[0x17E]; short cnt; char pad2[0x70]; struct E_AA00 *tab; };
extern struct G_AA00 D_0050A8E8_AA00[] __asm__("D_0050A8E8");

int func_003BAA00(int h, int *pos) {
    struct E_AA00 *e = &D_0050A8E8_AA00[0].tab[h];
    unsigned char t = e->type;
    if (t != 0) {
        (*pos)++;
        while (*pos < D_0050A8E8_AA00[0].cnt) {
            e = &D_0050A8E8_AA00[0].tab[*pos];
            if (e->type == t && e->b == 1 && e->w >= 0) return 1;
            (*pos)++;
        }
    } else if (*pos < 0) {
        *pos = h;
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BAAC0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BB0C8);
#ifdef SKIP_ASM
struct E_B0C8 {
    char pad00[0x26];
    unsigned char f26;
    char pad27[0x69 - 0x27];
    signed char f69;
    char pad6A[0x8C - 0x6A];
};
struct G_B0C8 {
    char pad[0x17E];
    short f17E;
    char pad180[0x1F0 - 0x180];
    struct E_B0C8 *f1F0;
};
extern struct G_B0C8 D_0050A8E8_B0C8 __asm__("D_0050A8E8");
extern unsigned char D_0044C588_B0C8[] __asm__("D_0044C588");

unsigned char func_003BB0C8(void) {
    int i;
again:
    D_0044C588_B0C8[0] = D_0044C588_B0C8[0] + 1;
    if (D_0044C588_B0C8[0] == 0) {
        D_0044C588_B0C8[0] = D_0044C588_B0C8[0] + 1;
    }
    for (i = 0; i < D_0050A8E8_B0C8.f17E; i++) {
        struct E_B0C8 *e = &D_0050A8E8_B0C8.f1F0[i];
        if (e->f69 != 0 && e->f26 == D_0044C588_B0C8[0]) {
            goto again;
        }
    }
    return D_0044C588_B0C8[0];
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BB140);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003BB588);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Rec_B588 {
    short id;
    char pad2[6];
    unsigned char x0;
    unsigned char x1;
    unsigned char y0;
    unsigned char y1;
    char padC[0xD0 - 0xC];
};
struct G_B588 { char pad[0x1F0]; char *ents; };
extern struct G_B588 D_0050A8E8_B588 __asm__("D_0050A8E8");
extern char *D_0050AAD8_B588 __asm__("D_0050AAD8");
extern int f_B0C8_B588(void) __asm__("func_003BB0C8");
extern int f_AAC0_B588(int **, struct Rec_B588 *) __asm__("func_003BAAC0");
extern int f_72A0_B588(int) __asm__("func_003C72A0");
extern int f_B140_B588(int, int, int *, signed char *, struct Rec_B588 *, int, int, int) __asm__("func_003BB140");
extern void f_5F98_B588(struct Rec_B588 *, int) __asm__("func_003B5F98");
extern int f_8AB8_B588(int) __asm__("func_003B8AB8");
extern int f_A6E8_B588(int) __asm__("func_003BA6E8");
extern void f_89E0_B588(int) __asm__("func_003B89E0");

int func_003BB588_impl(int *self, int *cur, int a2, int a3, signed char *pos) __asm__("func_003BB588");
int func_003BB588_impl(int *self, int *cur, int a2, int a3, signed char *pos) {
    struct Rec_B588 rec;
    int ids[12];
    int n;
    int m;
    int i;
    int k;
    char *e;
    int ret;
    int first;
    int h;
    int x;
    int y;
    int tag;
    int more;

    n = 0;
    e = 0;
    ret = -9;
    first = 0;
    h = 0;
    if (cur == 0) {
        return -8;
    }
    if (self == 0) {
        self = cur;
    }
    cur++;
    y = pos[2];
    x = pos[3];
    tag = f_B0C8_B588();
    do {
        more = f_AAC0_B588(&cur, &rec);
        if (!first) {
            if (rec.id) {
                h = f_72A0_B588(rec.id);
            }
            first = 1;
        }
        if (x >= (signed char)rec.x0 && x <= (signed char)rec.x1 && y >= (signed char)rec.y0 && y <= (signed char)rec.y1) {
            ret = f_B140_B588(a2, a3, self, pos, &rec, y, x, h);
            if (ret < 0) {
                goto fail;
            }
            ids[n++] = ret;
            f_5F98_B588(&rec, 1);
        }
    } while (more);

    m = n;
    n = 0;
    for (i = 0; i < m; i++) {
        if (f_8AB8_B588(ids[i]) == 0) {
            ids[n++] = ids[i];
        }
    }
    if (n == 0) {
        goto fail;
    }
    if (n == 1) {
        k = f_A6E8_B588(ids[0]);
        if (k >= 0) {
            e = D_0050AAD8_B588 + k * 0x8C;
            e[0x26] = 0;
            e[0x27] = 0;
        }
    } else {
        for (i = 0; i < n; i++) {
            k = f_A6E8_B588(ids[i]);
            if (k >= 0) {
                e = D_0050A8E8_B588.ents + k * 0x8C;
                e[0x26] = tag;
                e[0x27] = 0;
            }
        }
        e[0x27] = 1;
    }
    return ret;
fail:
    for (i = 0; i < n; i++) {
        f_89E0_B588(ids[i]);
    }
    return ret;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BB820);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BBDA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct O_BDA0 { char pad[0x48]; int a[4]; int b[4]; };
struct Rec_BDA0 { int p; int id; int v1; int v2; int v3; };
extern void f_6210_BDA0(void *, int, int) __asm__("func_00416210");
extern void f_7218_BDA0(char *) __asm__("func_003C7218");
extern int f_7388_BDA0(struct Rec_BDA0 *) __asm__("func_003C7388");
extern unsigned short D_0050ABC8_BDA0[][6] __asm__("D_0050ABC8");

void func_003BBDA0(int unused, int src, unsigned char *hdr, char *out, int *extra) {
    int a[43];
    int c[43];
    int d[46];
    int b[46];
    struct Rec_BDA0 rec;
    int i;
    int k;

    k = 0;
    f_6210_BDA0(hdr, 0, 4);
    f_6210_BDA0(out, 0, 0x68);
    f_6210_BDA0(extra, 0, 0x1C);
    f_7218_BDA0(out);
    rec.p = src + 8;
    for (i = 42; i >= 0; i--) {
        c[i] = 0;
    }
    for (i = 45; i >= 0; i--) {
        b[i] = 0;
    }
    d[2] = 1;
    d[4] = 48000;
    d[0x20] = 10;
    d[5] = 0;
    while (f_7388_BDA0(&rec) != 0) {
        if (rec.id < 0x2B) {
            a[rec.id] = rec.v1;
            c[rec.id] = rec.v2;
            if (rec.id == 0x14) {
                ((struct O_BDA0 *)out)->a[k] = rec.v2;
                ((struct O_BDA0 *)out)->b[k] = rec.v3;
                k++;
            }
        } else if ((unsigned int)(rec.id - 0x80) >= 0x2E) {
            if (rec.id != 0xFE) {
                continue;
            }
            break;
        } else {
            d[rec.id - 0x80] = rec.v1;
            b[rec.id - 0x80] = rec.v2;
        }
    }
    hdr[2] = d[2];
    hdr[3] = d[0x20];
    *(unsigned short *)hdr = d[4];
    *extra = d[5];
    *(short *)(out + 8) = 4;
    out[7] = 3;
    for (i = 0; i < hdr[2]; i++) {
        ((unsigned short *)(out + 0xC))[i] = D_0050ABC8_BDA0[hdr[2] - 1][i];
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC000);
#ifdef SKIP_ASM
extern float func_003BC770(float);
extern float func_003BC840(float);

void func_003BC000(float *out, int arg1, int arg2, int arg3) {
    float a = 2.0f * ((float)arg1 / 65535.0f) * 3.1415927f;
    float b = 2.0f * ((float)arg2 / 65535.0f) * 3.1415927f;
    float c = 2.0f * ((float)arg3 / 65535.0f) * 3.1415927f;
    float t = (c - b) / (a - b) * 1.5707964f;
    out[0] = func_003BC770(t);
    out[1] = func_003BC840(t);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BC0B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC4C0);
#ifdef SKIP_ASM
extern char D_0050A8E8_4C0[] __asm__("D_0050A8E8");
extern unsigned char* D_0050AC38[];
void func_003BC4C0(int a, float* out)
{
    int idx = (a & 0xFFFF) >> 8;
    int i;
    for (i = 0; i < (unsigned char)D_0050A8E8_4C0[0x47]; i++) {
        out[i] = (float)D_0050AC38[i][idx] / 255.0f;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC530);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B5E98_C530(int) __asm__("func_003B5E98");
extern int D_0050AC30_C530[] __asm__("D_0050AC30");
extern char D_0050AC38_C530[] __asm__("D_0050AC38");

void func_003BC530(void) {
    func_003B58A0();
    if (D_0050AC38_C530 != 0) {
        func_003B5E98_C530(D_0050AC30_C530[0]);
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC570);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned short D_0044C590_C570[128] __asm__("D_0044C590");

unsigned short func_003BC570(int arg0) {
    return D_0044C590_C570[arg0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC588);
#ifdef SKIP_ASM
extern int D_0044C690[];
extern int D_0050AC50[];

void func_003BC588(int arg0) {
    int i;
    for (i = 0; i < 6; i++) {
        D_0050AC50[i] = D_0044C690[i] + arg0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC5C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned int D_0050AC50_C5C8[6] __asm__("D_0050AC50");

unsigned int func_003BC5C8(void) {
    unsigned int s, c, n;

    s = D_0050AC50_C5C8[5] + D_0050AC50_C5C8[4];
    c = 0;
    if (s < D_0050AC50_C5C8[5] || s < D_0050AC50_C5C8[4]) {
        c = 1;
    }
    D_0050AC50_C5C8[4] = s;
    s = s + D_0050AC50_C5C8[3] + c;
    c = s < D_0050AC50_C5C8[3];
    D_0050AC50_C5C8[3] = s;
    s = s + D_0050AC50_C5C8[2] + c;
    c = s < D_0050AC50_C5C8[2];
    D_0050AC50_C5C8[2] = s;
    n = ++D_0050AC50_C5C8[5];
    s = s + D_0050AC50_C5C8[1] + c;
    c = s < D_0050AC50_C5C8[1];
    D_0050AC50_C5C8[1] = s;
    s = s + D_0050AC50_C5C8[0] + c;
    D_0050AC50_C5C8[0] = s;
    if (n == 0) {
        if (++D_0050AC50_C5C8[4] == 0) {
            if (++D_0050AC50_C5C8[3] == 0) {
                if (++D_0050AC50_C5C8[2] == 0) {
                    if (++D_0050AC50_C5C8[1] == 0) {
                        s = ++D_0050AC50_C5C8[0];
                    }
                }
            }
        }
    }
    return s;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC6B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int f_A6E8_C6B8() __asm__("func_003BA6E8");
extern void f_A938_C6B8(int) __asm__("func_003BA938");
extern int f_AA00_C6B8(int, int *) __asm__("func_003BAA00");
extern void f_25E0_C6B8(int) __asm__("func_003C25E0");
struct G_C6B8 { char pad[0x1F0]; char *tab; };
extern struct G_C6B8 D_0050A8E8_C6B8[] __asm__("D_0050A8E8");

int func_003BC6B8(int arg0, int arg1) {
    int sp0;
    int r = f_A6E8_C6B8();
    char *e;
    if (r >= 0) {
        sp0 = -1;
        while (f_AA00_C6B8(r, &sp0) != 0) {
            e = D_0050A8E8_C6B8[0].tab + sp0 * 0x8C;
            if (*(char *)(e + 0x64) == arg1)
                return 0;
            if (*(short *)(e + 0x82) != 0) {
                *(short *)(e + 0x86) = 0;
                *(char *)(e + 0x64) = arg1;
                f_A938_C6B8(sp0);
                f_25E0_C6B8(sp0);
            } else
                return 0;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC770);
#ifdef SKIP_ASM
float func_003BC770(float x) {
    float x2, x3, x5, x7, x9, x11, x13;
    while (x > 6.2831855f) {
        x -= 6.2831855f;
    }
    x2 = x * x;
    x3 = x2 * x;
    x5 = x2 * x3;
    x7 = x2 * x5;
    x9 = x2 * x7;
    x11 = x2 * x9;
    x13 = x2 * x11;
    return x - x3 * 0.16666667f + x5 * 0.00833333f - x7 * 0.00019841270f + x9 * 2.7557319e-6f - x11 * 2.5052108e-8f + x13 * 1.6059e-10f;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC840);
#ifdef SKIP_ASM
float func_003BC840(float x) {
    float x2, x4, x6, x8, x10, x12;
    while (x > 6.2831855f) {
        x -= 6.2831855f;
    }
    x2 = x * x;
    x4 = x2 * x2;
    x6 = x2 * x4;
    x8 = x4 * x4;
    x10 = x2 * x8;
    x12 = x6 * x6;
    return 1.0f - x2 * 0.5f + x4 * 0.041666668f - x6 * 0.0013888889f + x8 * 2.4801588e-5f - x10 * 2.755732e-7f + x12 * 2.0876758e-9f;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC910);
#ifdef SKIP_ASM
extern void func_003C5E08();

void func_003BC910(void) {
    func_003C5E08();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC930);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003BECA0_C930(void) __asm__("func_003BECA0");
extern void func_003BED30_C930(void) __asm__("func_003BED30");
extern void func_003BF0F0_C930(void) __asm__("func_003BF0F0");
extern void *D_0050C840[];
extern void *D_0050C844[];
extern void *D_0050C848[];

void func_003BC930(void) {
    D_0050C840[0] = func_003BECA0_C930;
    D_0050C844[0] = func_003BED30_C930;
    D_0050C848[0] = func_003BF0F0_C930;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC968);
#ifdef SKIP_ASM
void func_003BC968(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D400 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
    *(volatile int *)0x1000D410 = arg0;
    *(volatile int *)0x1000D480 = arg1;
    *(volatile int *)0x1000D420 = arg2;
    *(volatile int *)0x1000D400 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D400 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BCA28);
#ifdef SKIP_ASM
void func_003BCA28(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D000 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
    *(volatile int *)0x1000D010 = arg1;
    *(volatile int *)0x1000D080 = arg0;
    *(volatile int *)0x1000D020 = arg2;
    *(volatile int *)0x1000D000 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D000 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BCAE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char p0[6]; unsigned short pos; unsigned char *buf; } BW_CAE8;
extern BW_CAE8 *D_0050AC68_CAE8[] __asm__("D_0050AC68");

void func_003BCAE8(int arg0, int n) {
    unsigned int v = arg0 << (0x20 - n);
    int byte;
    int room;
    int take;
    int rem;
    v = v >> (0x20 - n);
    while (n > 0) {
        byte = D_0050AC68_CAE8[0]->pos >> 3;
        if (byte & 1)
            byte = byte - 1;
        else
            byte = byte + 1;
        room = 8 - (D_0050AC68_CAE8[0]->pos & 7);
        if (room == 8)
            D_0050AC68_CAE8[0]->buf[byte] = 0;
        take = (room >= n) ? n : room;
        rem = n - take;
        D_0050AC68_CAE8[0]->buf[byte] |= (v >> rem) << (room - take);
        n = rem;
        D_0050AC68_CAE8[0]->pos += take;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BCBA0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD078);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C06B0_D078(int a0, float *buf, void *p, signed char *tbl) __asm__("func_003C06B0");
extern signed char D_0044DD00_D078[] __asm__("D_0044DD00");
extern int D_0044C760_D078[] __asm__("D_0044C760");
extern signed char D_0044DD38_D078[] __asm__("D_0044DD38");
extern void *D_0050AC68;

void func_003BD078(int a0, signed char *out, signed char *out8) {
    float buf[8];
    float max;
    float min;
    float scale;
    int i;
    int n;
    int idx;

    max = 0.0f;
    min = 0.0f;
    func_003C06B0_D078(a0, buf, (char *)D_0050AC68 + 0x6C, D_0044DD00_D078);
    for (i = 0; i < 8; i++) {
        if (max < buf[i]) {
            max = buf[i];
        } else if (buf[i] < min) {
            min = buf[i];
        }
    }
    min = -min;
    if (max < min) {
        max = min;
    }
    if (max < 4.0f) {
        idx = D_0044DD38_D078[(int)max];
    } else {
        n = (int)((float)*(int *)&max * 6.524646209982166e-07f) - 0x2B8;
        idx = n + 1;
        if (max < (float)D_0044C760_D078[n]) {
            idx = n;
        }
    }
    *out = idx;
    scale = 1.0f / (float)D_0044C760_D078[idx] * 28.571428298950195f;
    for (i = 0; i < 8; i++) {
        out8[i] = (int)(buf[i] * scale);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD220);
#ifdef SKIP_ASM
struct S_D220 { char pad[4]; unsigned short w4; };
struct C_D220 { char pad0[0x600]; char b600[0x200]; char b800[0x220]; int *pA20; int *pA24; int *pA28; int *pA2C; int *pA30; int *pA34; int *pA38; unsigned char padA3C; };
extern struct S_D220 *D_0050AC68_D220 __asm__("D_0050AC68");
extern struct C_D220 *D_0050AC6C_D220 __asm__("D_0050AC6C");
extern void fC968_D220(int, int, int, int) __asm__("func_003BC968");
extern void fCA28_D220(int, int, int, int) __asm__("func_003BCA28");
extern void fF3E0_D220(int, int, int) __asm__("func_003BF3E0");
extern void fF440_D220(int, int, int) __asm__("func_003BF440");
extern void fF4C0_D220(int, int, void *) __asm__("func_003BF4C0");
extern void fF5A0_D220(int, int, void *) __asm__("func_003BF5A0");
extern void fF6B0_D220(int, int, void *) __asm__("func_003BF6B0");
extern void fF800_D220(void *) __asm__("func_003BF800");
extern void fF8D0_D220(void *, void *) __asm__("func_003BF8D0");
extern void fF960_D220(void *, void *) __asm__("func_003BF960");
extern void fFAC0_D220(void *, void *) __asm__("func_003BFAC0");
extern void fFB90_D220(void *, void *) __asm__("func_003BFB90");
extern void fFC50_D220(void *, int) __asm__("func_003BFC50");
extern void fFD60_D220(void *, int, void *) __asm__("func_003BFD60");
extern void fFE80_D220(void *, int, void *) __asm__("func_003BFE80");
extern void fFFA0_D220(void *, int, void *) __asm__("func_003BFFA0");
extern void f01A0_D220(void *, int, int, int) __asm__("func_003C01A0");
void func_003BD220(unsigned int a0, int a1, unsigned int a2) {
    short b;
    int i;
    if (!(D_0050AC6C_D220->padA3C == 0)) {
        b = 0;
        if ((a0 & 0x70000000) != 0x70000000) {
            b = (a2 & 0x70000000) != 0x70000000;
        }
    } else {
        b = 0;
    }
    if (b) {
        fC968_D220(a2, (int)D_0050AC6C_D220->pA20, D_0050AC68_D220->w4 >> 2, 0);
        fF440_D220(a0, (int)D_0050AC6C_D220->pA20 + D_0050AC68_D220->w4 * 4, 0x200);
        if (*(volatile int *)0x1000D400 & 0x100) {
            do {
            } while (*(volatile int *)0x1000D400 & 0x100);
        }
    } else {
        fF3E0_D220(a2, (int)D_0050AC6C_D220->pA20, D_0050AC68_D220->w4);
    }
    i = 0;
    do {
        if (b) {
            if (D_0050AC68_D220->w4 == 0xE0) {
                fF4C0_D220((int)D_0050AC6C_D220->pA20 + i * 0x200, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else if (D_0050AC68_D220->w4 == 0x160) {
                fF5A0_D220((int)D_0050AC6C_D220->pA20 + i * 0x200, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else {
                fF6B0_D220((int)D_0050AC6C_D220->pA20 + i * 0x200, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            }
        } else {
            fF440_D220(a0, (int)D_0050AC6C_D220->pA20 + D_0050AC68_D220->w4 * 4, 0x80);
            if (D_0050AC68_D220->w4 == 0xE0) {
                fF4C0_D220((int)D_0050AC6C_D220->pA20, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else if (D_0050AC68_D220->w4 == 0x160) {
                fF5A0_D220((int)D_0050AC6C_D220->pA20, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else {
                fF6B0_D220((int)D_0050AC6C_D220->pA20, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            }
            fF3E0_D220((int)D_0050AC6C_D220->pA20 + 0x200, (int)D_0050AC6C_D220->pA20, D_0050AC68_D220->w4);
        }
        i++;
        a0 += 0x100;
        fF800_D220(D_0050AC6C_D220->b600);
        fF8D0_D220(D_0050AC6C_D220->b600, D_0050AC6C_D220->b800);
        fF960_D220(D_0050AC6C_D220->b800, D_0050AC6C_D220->b600);
        fFAC0_D220(D_0050AC6C_D220->b600, D_0050AC6C_D220->b800);
        fFB90_D220(D_0050AC6C_D220->b800, D_0050AC6C_D220->b600);
        fFC50_D220(D_0050AC6C_D220->b600, (int)D_0050AC6C_D220->pA28);
        fFD60_D220(D_0050AC6C_D220->b600, (int)D_0050AC6C_D220->pA2C, D_0050AC6C_D220->b800);
        fFE80_D220(D_0050AC6C_D220->b800, (int)D_0050AC6C_D220->pA30, D_0050AC6C_D220->b600);
        fFFA0_D220(D_0050AC6C_D220->b600, (int)D_0050AC6C_D220->pA34, D_0050AC6C_D220->b800);
        f01A0_D220(D_0050AC6C_D220->b800, (int)D_0050AC6C_D220->pA38, a1, 0x40);
        a1 += 0x10;
    } while (i < 4);
    if (b) {
        fCA28_D220((int)D_0050AC6C_D220->pA20 + 0x800, a2, D_0050AC68_D220->w4 >> 2, 0x10000);
    } else {
        fF3E0_D220((int)D_0050AC6C_D220->pA20, a2, D_0050AC68_D220->w4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD5B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Blk_D5B8 {
    int *data;
    unsigned char sf[24];
};
struct S_D5B8 {
    unsigned char mode;
    unsigned char n;
    char pad2[6];
    unsigned char *out;
    float fC[24];
    int a6C[6];
    struct Blk_D5B8 *ptrs[5];
};
struct C_D5B8 {
    char pad0[0xA00];
    unsigned short q[16];
    char padA20[0xA20 - 0xA20];
    float *pA20;
};
extern struct S_D5B8 *D_0050AC68_D5B8 __asm__("D_0050AC68");
extern struct C_D5B8 *D_0050AC6C_D5B8 __asm__("D_0050AC6C");
extern int D_0044C760_D5B8[] __asm__("D_0044C760");
extern signed char D_0044DD38_D5B8[] __asm__("D_0044DD38");
extern void f03E0_D5B8(struct C_D5B8 *, float *) __asm__("func_003C03E0");
extern void f0564_D5B8(void *, void *, float) __asm__("func_003C0564");
extern void f05E0_D5B8(void *, void *, float) __asm__("func_003C05E0");

void func_003BD5B8(int ch) {
    struct Blk_D5B8 *blk;
    unsigned char *sf;
    unsigned char *out;
    unsigned short *q;
    unsigned char *b;
    float x;
    int i;
    int n;
    int idx;

    blk = D_0050AC68_D5B8->ptrs[ch];
    f03E0_D5B8(D_0050AC6C_D5B8, D_0050AC6C_D5B8->pA20);
    sf = blk->sf;
    for (i = 0; i < 24; i++) {
        x = D_0050AC6C_D5B8->pA20[i] * D_0050AC68_D5B8->fC[i];
        if (x < 4.0f) {
            idx = D_0044DD38_D5B8[(int)x];
        } else {
            n = (int)((float)*(int *)&x * 6.5246462099821656e-07f) - 0x2B8;
            idx = n + 1;
            if (x < (float)D_0044C760_D5B8[n]) {
                idx = n;
            }
        }
        blk->sf[i] = idx;
    }
    out = D_0050AC68_D5B8->out + (ch * 0xDC + 0xEA);
    q = D_0050AC6C_D5B8->q;
    for (i = 0; i < 14; i++) {
        f0564_D5B8((char *)D_0050AC6C_D5B8 + i * 0x40, q, 1.0f / (float)D_0044C760_D5B8[sf[i]]);
        out[1] = q[0] >> 2;
        out[0] = (q[0] << 6) | (q[1] >> 4);
        out[3] = (q[1] << 4) | (q[2] >> 6);
        out[2] = (q[2] << 2) | (q[3] >> 8);
        out[5] = q[3];
        out[4] = q[4] >> 2;
        out[7] = (q[4] << 6) | (q[5] >> 4);
        out[6] = (q[5] << 4) | (q[6] >> 6);
        out[9] = (q[6] << 2) | (q[7] >> 8);
        out[8] = q[7];
        out[0x371] = q[8] >> 2;
        out[0x370] = (q[8] << 6) | (q[9] >> 4);
        out[0x373] = (q[9] << 4) | (q[10] >> 6);
        out[0x372] = (q[10] << 2) | (q[11] >> 8);
        out[0x375] = q[11];
        out[0x374] = q[12] >> 2;
        out[0x377] = (q[12] << 6) | (q[13] >> 4);
        out[0x376] = (q[13] << 4) | (q[14] >> 6);
        out[0x379] = (q[14] << 2) | (q[15] >> 8);
        out[0x378] = q[15];
        out += 10;
    }
    for (; i < 24; i++) {
        f05E0_D5B8((char *)D_0050AC6C_D5B8 + i * 0x40, q, 1.0f / (float)D_0044C760_D5B8[sf[i]]);
        b = (unsigned char *)q;
        out[1] = b[0];
        out[0] = b[1];
        out[3] = b[2];
        out[2] = b[3];
        out[5] = b[4];
        out[4] = b[5];
        out[7] = b[6];
        out[6] = b[7];
        out[0x371] = b[8];
        out[0x370] = b[9];
        out[0x373] = b[10];
        out[0x372] = b[11];
        out[0x375] = b[12];
        out[0x374] = b[13];
        out[0x377] = b[14];
        out[0x376] = b[15];
        out += 8;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD9C0);
#ifdef SKIP_ASM
extern void *D_0050AC68;

void func_003BD9C0(void) {
    int temp_3;
    int var_7;
    int var_8;
    void *temp_4;
    void *temp_4_2;
    void *temp_5;
    void *temp_5_2;
    void *var_6;

    var_7 = 0;
    var_6 = (*(int *)((char*)(D_0050AC68) + (8))) + 0x8D;
    if ((*(unsigned char *)((char*)(D_0050AC68) + (1))) != 0) {
        var_8 = 4;
        do {
            temp_3 = var_7 * 4;
            var_7 += 2;
            temp_4 = (*(void **)((char*)((D_0050AC68 + temp_3)) + (0x84)));
            temp_5 = temp_4 + 4;
            (*(signed char *)((char*)(var_6) + (-1))) = (signed char) (((*(unsigned char *)((char*)(temp_4) + (4))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (1))) >> 6));
            (*(signed char *)((char*)(var_6) + (2))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (1))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (2))) >> 5));
            (*(signed char *)((char*)(var_6) + (1))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (2))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (3))) >> 4));
            (*(signed char *)((char*)(var_6) + (4))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (3))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (4))) >> 3));
            (*(signed char *)((char*)(var_6) + (3))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (4))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (5))) >> 2));
            (*(signed char *)((char*)(var_6) + (6))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (5))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (6))) >> 1));
            (*(signed char *)((char*)(var_6) + (5))) = (signed char) ((*(unsigned char *)((char*)(temp_5) + (7))) | ((*(unsigned char *)((char*)(temp_5) + (6))) << 7));
            (*(signed char *)((char*)(var_6) + (8))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (8))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (9))) >> 6));
            (*(signed char *)((char*)(var_6) + (7))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (9))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xA))) >> 5));
            (*(signed char *)((char*)(var_6) + (0xA))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xA))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xB))) >> 4));
            (*(signed char *)((char*)(var_6) + (9))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xB))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xC))) >> 3));
            (*(signed char *)((char*)(var_6) + (0xC))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xC))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xD))) >> 2));
            (*(signed char *)((char*)(var_6) + (0xB))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xD))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xE))) >> 1));
            (*(signed char *)((char*)(var_6) + (0xE))) = (signed char) ((*(unsigned char *)((char*)(temp_5) + (0xF))) | ((*(unsigned char *)((char*)(temp_5) + (0xE))) << 7));
            (*(signed char *)((char*)(var_6) + (0xD))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x10))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x11))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x10))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x11))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x12))) >> 5));
            (*(signed char *)((char*)(var_6) + (0xF))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x12))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x13))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x12))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x13))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x14))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x11))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x14))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x15))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x14))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x15))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x16))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x13))) = (signed char) ((*(unsigned char *)((char*)(temp_5) + (0x17))) | ((*(unsigned char *)((char*)(temp_5) + (0x16))) << 7));
            temp_4_2 = (*(void **)((char*)((D_0050AC68 + var_8)) + (0x84)));
            var_8 += 8;
            temp_5_2 = temp_4_2 + 4;
            (*(signed char *)((char*)(var_6) + (0x16))) = (signed char) (((*(unsigned char *)((char*)(temp_4_2) + (4))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (1))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x15))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (1))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (2))) >> 5));
            (*(signed char *)((char*)(var_6) + (0x18))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (2))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (3))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x17))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (3))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (4))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x1A))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (4))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (5))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x19))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (5))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (6))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x1C))) = (signed char) ((*(unsigned char *)((char*)(temp_5_2) + (7))) | ((*(unsigned char *)((char*)(temp_5_2) + (6))) << 7));
            (*(signed char *)((char*)(var_6) + (0x1B))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (8))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (9))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x1E))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (9))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xA))) >> 5));
            (*(signed char *)((char*)(var_6) + (0x1D))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xA))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xB))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x20))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xB))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xC))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x1F))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xC))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xD))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x22))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xD))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xE))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x21))) = (signed char) ((*(unsigned char *)((char*)(temp_5_2) + (0xF))) | ((*(unsigned char *)((char*)(temp_5_2) + (0xE))) << 7));
            (*(signed char *)((char*)(var_6) + (0x24))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x10))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x11))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x23))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x11))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x12))) >> 5));
            (*(signed char *)((char*)(var_6) + (0x26))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x12))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x13))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x25))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x13))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x14))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x28))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x14))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x15))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x27))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x15))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x16))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x2A))) = (signed char) ((*(unsigned char *)((char*)(temp_5_2) + (0x17))) | ((*(unsigned char *)((char*)(temp_5_2) + (0x16))) << 7));
            var_6 += 0x2A;
        } while (var_7 < (int) (*(unsigned char *)((char*)(D_0050AC68) + (1))));
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BDE08);

INCLUDE_ASM("ealib/seg_2B4578", func_003BE6E0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BECA0);
#ifdef SKIP_ASM
int func_003BECA0(int a, int b, int *o1, int *o2) {
    int w, m;
    if (b < 0) return -2;
    if (b < 0x22) w = 0xE0;
    else if (b < 0x43) w = 0x160;
    else if (b < 0x65) w = 0x1E0;
    else return -2;
    if (a == 1) m = 4;
    else if (a == 2) m = 5;
    else return -1;
    *o1 = (w * 4 + 0x3C) * m + 0xA8;
    *o2 = (w + (w + 0x200)) * 4 + 0xC00;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BED30);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003BF0F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct C_F0F0 {
    char pad0[0xA20];
    char *pA20;
    char *pA24;
    char *pA28;
    char *pA2C;
    char *pA30;
    char *pA34;
    char *pA38;
    unsigned char flagA3C;
};
struct S_F0F0 {
    unsigned char mode;
    unsigned char n;
    char pad2[2];
    unsigned short n4;
    short h6;
    int key;
    char padC[0x84 - 0xC];
    int *ptrs[1];
};
extern struct S_F0F0 *D_0050AC68_F0F0 __asm__("D_0050AC68");
extern struct C_F0F0 *D_0050AC6C_F0F0 __asm__("D_0050AC6C");
extern char D_0044C980_F0F0[] __asm__("D_0044C980");
extern char D_0044C990_F0F0[] __asm__("D_0044C990");
extern char D_0044C9B0_F0F0[] __asm__("D_0044C9B0");
extern char D_0044C9E0_F0F0[] __asm__("D_0044C9E0");
extern char D_0044CA40_F0F0[] __asm__("D_0044CA40");
extern char D_0044CB00_F0F0[] __asm__("D_0044CB00");
extern char D_0044CF00_F0F0[] __asm__("D_0044CF00");
extern char D_0044D500_F0F0[] __asm__("D_0044D500");
extern void f_C968_F0F0(char *, char *, int, int) __asm__("func_003BC968");
extern void f_CBA0_F0F0(void) __asm__("func_003BCBA0");
extern void f_D220_F0F0(int, struct C_F0F0 *, int) __asm__("func_003BD220");
extern void f_D5B8_F0F0(int) __asm__("func_003BD5B8");
extern void f_DE08_F0F0(int) __asm__("func_003BDE08");
extern void f_D9C0_F0F0(void) __asm__("func_003BD9C0");
extern void f_E6E0_F0F0(int *) __asm__("func_003BE6E0");

int func_003BF0F0(int *data, int key, char *buf) {
    int i;

    if (key & 1) {
        return -3;
    }
    buf = (char *)((((int)buf - 1) | 0xF) + 1);
    D_0050AC6C_F0F0 = (struct C_F0F0 *)buf;
    D_0050AC6C_F0F0->flagA3C = ((int)buf & 0x70000000) == 0x70000000;
    if (D_0050AC6C_F0F0->flagA3C) {
        buf += 0xA40;
        D_0050AC6C_F0F0->pA24 = buf;
        if (D_0050AC68_F0F0->n4 == 0xE0) {
            f_C968_F0F0(D_0044CB00_F0F0, buf, 0x40, 0);
            buf += 0x400;
        } else if (D_0050AC68_F0F0->n4 == 0x160) {
            f_C968_F0F0(D_0044CF00_F0F0, buf, 0x60, 0);
            buf += 0x600;
        } else {
            f_C968_F0F0(D_0044D500_F0F0, buf, 0x80, 0);
            buf += 0x800;
        }
        D_0050AC6C_F0F0->pA20 = buf;
        buf += (D_0050AC68_F0F0->n4 + 0x200) * 4;
        D_0050AC6C_F0F0->pA28 = buf;
        D_0050AC6C_F0F0->pA2C = buf + 0x10;
        D_0050AC6C_F0F0->pA30 = buf + 0x30;
        D_0050AC6C_F0F0->pA34 = buf + 0x60;
        D_0050AC6C_F0F0->pA38 = buf + 0xC0;
        f_C968_F0F0(D_0044C980_F0F0, buf, 0x12, 0x10000);
    } else {
        D_0050AC6C_F0F0->pA20 = buf + 0xA40;
        if (D_0050AC68_F0F0->n4 == 0xE0) {
            D_0050AC6C_F0F0->pA24 = D_0044CB00_F0F0;
        } else if (D_0050AC68_F0F0->n4 == 0x160) {
            D_0050AC6C_F0F0->pA24 = D_0044CF00_F0F0;
        } else if (D_0050AC68_F0F0->n4 == 0x1E0) {
            D_0050AC6C_F0F0->pA24 = D_0044D500_F0F0;
        }
        D_0050AC6C_F0F0->pA28 = D_0044C980_F0F0;
        D_0050AC6C_F0F0->pA2C = D_0044C990_F0F0;
        D_0050AC6C_F0F0->pA30 = D_0044C9B0_F0F0;
        D_0050AC6C_F0F0->pA34 = D_0044C9E0_F0F0;
        D_0050AC6C_F0F0->pA38 = D_0044CA40_F0F0;
    }
    if (D_0050AC68_F0F0->key != key) {
        D_0050AC68_F0F0->key = key;
        D_0050AC68_F0F0->h6 = 0;
        f_CBA0_F0F0();
    }
    for (i = 0; i < D_0050AC68_F0F0->n; i++) {
        if (data[i] & 0xF) {
            return -3;
        }
        f_D220_F0F0(data[i], D_0050AC6C_F0F0, *D_0050AC68_F0F0->ptrs[i]);
        if (D_0050AC68_F0F0->mode == 1) {
            f_D5B8_F0F0(i);
        } else {
            f_DE08_F0F0(i);
        }
    }
    if (D_0050AC68_F0F0->mode == 1) {
        f_D9C0_F0F0();
    } else {
        f_E6E0_F0F0(data);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF3E0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF3E0(char *src, char *dst, unsigned bytes) {
    __asm__ volatile(
        ".set noreorder\n"
        "srl $2, $6, 5\n"
        "1:\n"
        "lqc2 $vf1, 0x0($4)\n"
        "lqc2 $vf2, 0x10($4)\n"
        "lqc2 $vf3, 0x20($4)\n"
        "lqc2 $vf4, 0x30($4)\n"
        "lqc2 $vf5, 0x40($4)\n"
        "lqc2 $vf6, 0x50($4)\n"
        "lqc2 $vf7, 0x60($4)\n"
        "lqc2 $vf8, 0x70($4)\n"
        "sqc2 $vf1, 0x0($5)\n"
        "sqc2 $vf2, 0x10($5)\n"
        "sqc2 $vf3, 0x20($5)\n"
        "sqc2 $vf4, 0x30($5)\n"
        "sqc2 $vf5, 0x40($5)\n"
        "sqc2 $vf6, 0x50($5)\n"
        "addiu $2, $2, -0x1\n"
        "sqc2 $vf7, 0x60($5)\n"
        "addiu $4, $4, 0x80\n"
        "sqc2 $vf8, 0x70($5)\n"
        "bnez $2, 1b\n"
        "addiu $5, $5, 0x80\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF440);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF440(char *src, char *dst, unsigned bytes) {
    __asm__ volatile(
        ".set noreorder\n"
        "srl $2, $6, 4\n"
        "1:\n"
        "ld $7, 0x0($4)\n"
        "ld $8, 0x8($4)\n"
        "ld $9, 0x10($4)\n"
        "ld $10, 0x18($4)\n"
        "pextlh $7, $7, $0\n"
        "pextlh $8, $8, $0\n"
        "pextlh $9, $9, $0\n"
        "pextlh $10, $10, $0\n"
        "psraw $7, $7, 8\n"
        "psraw $8, $8, 8\n"
        "psraw $9, $9, 8\n"
        "psraw $10, $10, 8\n"
        "qmtc2.ni $7, $vf1\n"
        "qmtc2.ni $8, $vf2\n"
        "qmtc2.ni $9, $vf3\n"
        "qmtc2.ni $10, $vf4\n"
        "vitof0.xyzw $vf1, $vf1\n"
        "vitof0.xyzw $vf2, $vf2\n"
        "vitof0.xyzw $vf3, $vf3\n"
        "vitof0.xyzw $vf4, $vf4\n"
        "sqc2 $vf1, 0x0($5)\n"
        "sqc2 $vf2, 0x10($5)\n"
        "addiu $2, $2, -0x1\n"
        "sqc2 $vf3, 0x20($5)\n"
        "addiu $4, $4, 0x20\n"
        "sqc2 $vf4, 0x30($5)\n"
        "bnez $2, 1b\n"
        "addiu $5, $5, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF4C0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF4C0(char *a, char *b, char *out) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x10\n"
        "1:\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x100($5)\n"
        "lqc2 $vf3, 0x200($5)\n"
        "lqc2 $vf4, 0x300($5)\n"
        "lqc2 $vf5, 0x0($4)\n"
        "lqc2 $vf6, 0x80($4)\n"
        "lqc2 $vf7, 0x100($4)\n"
        "lqc2 $vf8, 0x180($4)\n"
        "lqc2 $vf9, 0x200($4)\n"
        "lqc2 $vf10, 0x280($4)\n"
        "lqc2 $vf11, 0x300($4)\n"
        "lqc2 $vf12, 0x380($4)\n"
        "lqc2 $vf13, 0x400($4)\n"
        "lqc2 $vf14, 0x480($4)\n"
        "vmula.xyzw ACC, $vf1, $vf5\n"
        "vmadda.xyzw ACC, $vf2, $vf7\n"
        "vmadda.xyzw ACC, $vf3, $vf9\n"
        "vmadd.xyzw $vf5, $vf4, $vf11\n"
        "vmula.xyzw ACC, $vf1, $vf6\n"
        "vmadda.xyzw ACC, $vf2, $vf8\n"
        "vmadda.xyzw ACC, $vf3, $vf10\n"
        "vmadd.xyzw $vf6, $vf4, $vf12\n"
        "vmula.xyzw ACC, $vf1, $vf7\n"
        "vmadda.xyzw ACC, $vf2, $vf9\n"
        "vmadda.xyzw ACC, $vf3, $vf11\n"
        "vmadd.xyzw $vf7, $vf4, $vf13\n"
        "vmula.xyzw ACC, $vf1, $vf8\n"
        "vmadda.xyzw ACC, $vf2, $vf10\n"
        "vmadda.xyzw ACC, $vf3, $vf12\n"
        "vmadd.xyzw $vf8, $vf4, $vf14\n"
        "qmfc2.ni $7, $vf5\n"
        "qmfc2.ni $8, $vf6\n"
        "qmfc2.ni $9, $vf7\n"
        "qmfc2.ni $10, $vf8\n"
        "pextlw $11, $8, $7\n"
        "pextuw $8, $8, $7\n"
        "pextlw $12, $10, $9\n"
        "pextuw $10, $10, $9\n"
        "pcpyld $7, $12, $11\n"
        "pcpyud $9, $11, $12\n"
        "pcpyld $11, $10, $8\n"
        "pcpyud $12, $8, $10\n"
        "sq $7, 0x0($6)\n"
        "addiu $2, $2, -0x1\n"
        "sq $9, 0x10($6)\n"
        "addiu $4, $4, 0x10\n"
        "sq $11, 0x20($6)\n"
        "addiu $5, $5, 0x10\n"
        "sq $12, 0x30($6)\n"
        "bnez $2, 1b\n"
        "addiu $6, $6, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF5A0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF5A0(char *a, char *b, char *out) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x10\n"
        "1:\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x100($5)\n"
        "lqc2 $vf3, 0x200($5)\n"
        "lqc2 $vf4, 0x300($5)\n"
        "lqc2 $vf5, 0x400($5)\n"
        "lqc2 $vf6, 0x500($5)\n"
        "lqc2 $vf7, 0x0($4)\n"
        "lqc2 $vf8, 0x80($4)\n"
        "lqc2 $vf9, 0x100($4)\n"
        "lqc2 $vf10, 0x180($4)\n"
        "lqc2 $vf11, 0x200($4)\n"
        "lqc2 $vf12, 0x280($4)\n"
        "lqc2 $vf13, 0x300($4)\n"
        "lqc2 $vf14, 0x380($4)\n"
        "lqc2 $vf15, 0x400($4)\n"
        "lqc2 $vf16, 0x480($4)\n"
        "lqc2 $vf17, 0x500($4)\n"
        "lqc2 $vf18, 0x580($4)\n"
        "lqc2 $vf19, 0x600($4)\n"
        "lqc2 $vf20, 0x680($4)\n"
        "vmula.xyzw ACC, $vf1, $vf7\n"
        "vmadda.xyzw ACC, $vf2, $vf9\n"
        "vmadda.xyzw ACC, $vf3, $vf11\n"
        "vmadda.xyzw ACC, $vf4, $vf13\n"
        "vmadda.xyzw ACC, $vf5, $vf15\n"
        "vmadd.xyzw $vf7, $vf6, $vf17\n"
        "vmula.xyzw ACC, $vf1, $vf8\n"
        "vmadda.xyzw ACC, $vf2, $vf10\n"
        "vmadda.xyzw ACC, $vf3, $vf12\n"
        "vmadda.xyzw ACC, $vf4, $vf14\n"
        "vmadda.xyzw ACC, $vf5, $vf16\n"
        "vmadd.xyzw $vf8, $vf6, $vf18\n"
        "vmula.xyzw ACC, $vf1, $vf9\n"
        "vmadda.xyzw ACC, $vf2, $vf11\n"
        "vmadda.xyzw ACC, $vf3, $vf13\n"
        "vmadda.xyzw ACC, $vf4, $vf15\n"
        "vmadda.xyzw ACC, $vf5, $vf17\n"
        "vmadd.xyzw $vf9, $vf6, $vf19\n"
        "vmula.xyzw ACC, $vf1, $vf10\n"
        "vmadda.xyzw ACC, $vf2, $vf12\n"
        "vmadda.xyzw ACC, $vf3, $vf14\n"
        "vmadda.xyzw ACC, $vf4, $vf16\n"
        "vmadda.xyzw ACC, $vf5, $vf18\n"
        "vmadd.xyzw $vf10, $vf6, $vf20\n"
        "qmfc2.ni $7, $vf7\n"
        "qmfc2.ni $8, $vf8\n"
        "qmfc2.ni $9, $vf9\n"
        "qmfc2.ni $10, $vf10\n"
        "pextlw $11, $8, $7\n"
        "pextuw $8, $8, $7\n"
        "pextlw $12, $10, $9\n"
        "pextuw $10, $10, $9\n"
        "pcpyld $7, $12, $11\n"
        "pcpyud $9, $11, $12\n"
        "pcpyld $11, $10, $8\n"
        "pcpyud $12, $8, $10\n"
        "sq $7, 0x0($6)\n"
        "addiu $2, $2, -0x1\n"
        "sq $9, 0x10($6)\n"
        "addiu $4, $4, 0x10\n"
        "sq $11, 0x20($6)\n"
        "addiu $5, $5, 0x10\n"
        "sq $12, 0x30($6)\n"
        "bnez $2, 1b\n"
        "addiu $6, $6, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF6B0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF6B0(char *a, char *b, char *out) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x10\n"
        "1:\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x100($5)\n"
        "lqc2 $vf3, 0x200($5)\n"
        "lqc2 $vf4, 0x300($5)\n"
        "lqc2 $vf5, 0x400($5)\n"
        "lqc2 $vf6, 0x500($5)\n"
        "lqc2 $vf7, 0x600($5)\n"
        "lqc2 $vf8, 0x700($5)\n"
        "lqc2 $vf9, 0x0($4)\n"
        "lqc2 $vf10, 0x80($4)\n"
        "lqc2 $vf11, 0x100($4)\n"
        "lqc2 $vf12, 0x180($4)\n"
        "lqc2 $vf13, 0x200($4)\n"
        "lqc2 $vf14, 0x280($4)\n"
        "lqc2 $vf15, 0x300($4)\n"
        "lqc2 $vf16, 0x380($4)\n"
        "lqc2 $vf17, 0x400($4)\n"
        "lqc2 $vf18, 0x480($4)\n"
        "lqc2 $vf19, 0x500($4)\n"
        "lqc2 $vf20, 0x580($4)\n"
        "lqc2 $vf21, 0x600($4)\n"
        "lqc2 $vf22, 0x680($4)\n"
        "lqc2 $vf23, 0x700($4)\n"
        "lqc2 $vf24, 0x780($4)\n"
        "lqc2 $vf25, 0x800($4)\n"
        "lqc2 $vf26, 0x880($4)\n"
        "vmula.xyzw ACC, $vf1, $vf9\n"
        "vmadda.xyzw ACC, $vf2, $vf11\n"
        "vmadda.xyzw ACC, $vf3, $vf13\n"
        "vmadda.xyzw ACC, $vf4, $vf15\n"
        "vmadda.xyzw ACC, $vf5, $vf17\n"
        "vmadda.xyzw ACC, $vf6, $vf19\n"
        "vmadda.xyzw ACC, $vf7, $vf21\n"
        "vmadd.xyzw $vf9, $vf8, $vf23\n"
        "vmula.xyzw ACC, $vf1, $vf10\n"
        "vmadda.xyzw ACC, $vf2, $vf12\n"
        "vmadda.xyzw ACC, $vf3, $vf14\n"
        "vmadda.xyzw ACC, $vf4, $vf16\n"
        "vmadda.xyzw ACC, $vf5, $vf18\n"
        "vmadda.xyzw ACC, $vf6, $vf20\n"
        "vmadda.xyzw ACC, $vf7, $vf22\n"
        "vmadd.xyzw $vf10, $vf8, $vf24\n"
        "vmula.xyzw ACC, $vf1, $vf11\n"
        "vmadda.xyzw ACC, $vf2, $vf13\n"
        "vmadda.xyzw ACC, $vf3, $vf15\n"
        "vmadda.xyzw ACC, $vf4, $vf17\n"
        "vmadda.xyzw ACC, $vf5, $vf19\n"
        "vmadda.xyzw ACC, $vf6, $vf21\n"
        "vmadda.xyzw ACC, $vf7, $vf23\n"
        "vmadd.xyzw $vf11, $vf8, $vf25\n"
        "vmula.xyzw ACC, $vf1, $vf12\n"
        "vmadda.xyzw ACC, $vf2, $vf14\n"
        "vmadda.xyzw ACC, $vf3, $vf16\n"
        "vmadda.xyzw ACC, $vf4, $vf18\n"
        "vmadda.xyzw ACC, $vf5, $vf20\n"
        "vmadda.xyzw ACC, $vf6, $vf22\n"
        "vmadda.xyzw ACC, $vf7, $vf24\n"
        "vmadd.xyzw $vf12, $vf8, $vf26\n"
        "qmfc2.ni $7, $vf9\n"
        "qmfc2.ni $8, $vf10\n"
        "qmfc2.ni $9, $vf11\n"
        "qmfc2.ni $10, $vf12\n"
        "pextlw $11, $8, $7\n"
        "pextuw $8, $8, $7\n"
        "pextlw $12, $10, $9\n"
        "pextuw $10, $10, $9\n"
        "pcpyld $7, $12, $11\n"
        "pcpyud $9, $11, $12\n"
        "pcpyld $11, $10, $8\n"
        "pcpyud $12, $8, $10\n"
        "sq $7, 0x0($6)\n"
        "addiu $2, $2, -0x1\n"
        "sq $9, 0x10($6)\n"
        "addiu $4, $4, 0x10\n"
        "sq $11, 0x20($6)\n"
        "addiu $5, $5, 0x10\n"
        "sq $12, 0x30($6)\n"
        "bnez $2, 1b\n"
        "addiu $6, $6, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF800);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF800(char *p) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x4\n"
        "addiu $5, $4, 0x1F0\n"
        "1:\n"
        "lqc2 $vf9, 0x200($4)\n"
        "lqc2 $vf10, 0x210($4)\n"
        "lqc2 $vf11, 0x220($4)\n"
        "lqc2 $vf12, 0x230($4)\n"
        "lqc2 $vf13, 0x1D0($5)\n"
        "lqc2 $vf14, 0x1E0($5)\n"
        "lqc2 $vf15, 0x1F0($5)\n"
        "lqc2 $vf16, 0x200($5)\n"
        "lqc2 $vf1, 0x0($4)\n"
        "lqc2 $vf2, 0x10($4)\n"
        "lqc2 $vf3, 0x20($4)\n"
        "lqc2 $vf4, 0x30($4)\n"
        "lqc2 $vf5, -0x30($5)\n"
        "lqc2 $vf6, -0x20($5)\n"
        "lqc2 $vf7, -0x10($5)\n"
        "lqc2 $vf8, 0x0($5)\n"
        "vadd.xyzw $vf16, $vf9, $vf16\n"
        "vadd.xyzw $vf15, $vf10, $vf15\n"
        "vadd.xyzw $vf14, $vf11, $vf14\n"
        "vadd.xyzw $vf13, $vf12, $vf13\n"
        "vsub.xyzw $vf9, $vf1, $vf8\n"
        "vsub.xyzw $vf10, $vf2, $vf7\n"
        "vsub.xyzw $vf11, $vf3, $vf6\n"
        "vsub.xyzw $vf12, $vf4, $vf5\n"
        "vsub.xyzw $vf8, $vf8, $vf1\n"
        "vsub.xyzw $vf7, $vf7, $vf2\n"
        "vsub.xyzw $vf6, $vf6, $vf3\n"
        "vsub.xyzw $vf5, $vf5, $vf4\n"
        "vsub.xyzw $vf1, $vf9, $vf16\n"
        "vsub.xyzw $vf2, $vf10, $vf15\n"
        "vsub.xyzw $vf3, $vf11, $vf14\n"
        "vsub.xyzw $vf4, $vf12, $vf13\n"
        "vsub.xyzw $vf8, $vf8, $vf16\n"
        "vsub.xyzw $vf7, $vf7, $vf15\n"
        "vsub.xyzw $vf6, $vf6, $vf14\n"
        "vsub.xyzw $vf5, $vf5, $vf13\n"
        "sqc2 $vf1, 0x0($4)\n"
        "sqc2 $vf2, 0x10($4)\n"
        "sqc2 $vf3, 0x20($4)\n"
        "sqc2 $vf4, 0x30($4)\n"
        "sqc2 $vf5, -0x30($5)\n"
        "sqc2 $vf6, -0x20($5)\n"
        "addiu $2, $2, -0x1\n"
        "sqc2 $vf7, -0x10($5)\n"
        "addiu $4, $4, 0x40\n"
        "sqc2 $vf8, 0x0($5)\n"
        "bnez $2, 1b\n"
        "addiu $5, $5, -0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

/* Types and VU0 helpers shared by the func_003BF8D0 .. func_003C01A0 family (EA audio engine transform
   routines). Kept in one unguarded block so that no function's block depends on another's (types and unused
   static inline helpers emit no code when the functions are built from asm). */
/* --- used by func_003BF8D0 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_F8D0;

// PORT: PS2-only VU0 inline asm (clear running-sum register vf1).
static inline void vu0ClearSum(void) {
    __asm__ volatile("vsub.xyzw  $vf1, $vf0, $vf0\n");
}

// PORT: PS2-only VU0 inline asm (load eight vec4 rows into vf2..vf9).
static inline void vu0LoadRows2to9(const V4_F8D0 *p) {
    __asm__ volatile(
        "lqc2       $vf2, 0x0(%0)\n"
        "lqc2       $vf3, 0x10(%0)\n"
        "lqc2       $vf4, 0x20(%0)\n"
        "lqc2       $vf5, 0x30(%0)\n"
        "lqc2       $vf6, 0x40(%0)\n"
        "lqc2       $vf7, 0x50(%0)\n"
        "lqc2       $vf8, 0x60(%0)\n"
        "lqc2       $vf9, 0x70(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (add each row to its successor: vf1..vf8 += vf2..vf9).
static inline void vu0AddNext1to8(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf1, $vf1, $vf2\n"
        "vadd.xyzw  $vf2, $vf2, $vf3\n"
        "vadd.xyzw  $vf3, $vf3, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf5\n"
        "vadd.xyzw  $vf5, $vf5, $vf6\n"
        "vadd.xyzw  $vf6, $vf6, $vf7\n"
        "vadd.xyzw  $vf7, $vf7, $vf8\n"
        "vadd.xyzw  $vf8, $vf8, $vf9\n");
}

// PORT: PS2-only VU0 inline asm (store first six sums).
static inline void vu0StoreSums(V4_F8D0 *d) {
    __asm__ volatile(
        "sqc2       $vf2, 0x0(%0)\n"
        "sqc2       $vf4, 0x10(%0)\n"
        "sqc2       $vf6, 0x20(%0)\n"
        "sqc2       $vf8, 0x30(%0)\n"
        "sqc2       $vf1, 0x100(%0)\n"
        "sqc2       $vf3, 0x110(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store sum vf5).
static inline void vu0StoreSum5(V4_F8D0 *d) {
    __asm__ volatile("sqc2       $vf5, 0x120(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store sum vf7, carry last row vf9 into vf1).
static inline void vu0StoreSum7Carry(V4_F8D0 *d) {
    __asm__ volatile("sqc2       $vf7, 0x130(%0)\n" "vmove.xyzw $vf1, $vf9\n" : : "r"(d) : "memory");
}

/* --- used by func_003BF960 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_F960;

// PORT: PS2-only VU0 inline asm (load sixteen consecutive vec4 rows into vf1..vf16).
static inline void vu0LoadRows16(const V4_F960 *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x40(%0)\n"
        "lqc2       $vf6, 0x50(%0)\n"
        "lqc2       $vf7, 0x60(%0)\n"
        "lqc2       $vf8, 0x70(%0)\n"
        "lqc2       $vf9, 0x80(%0)\n"
        "lqc2       $vf10, 0x90(%0)\n"
        "lqc2       $vf11, 0xA0(%0)\n"
        "lqc2       $vf12, 0xB0(%0)\n"
        "lqc2       $vf13, 0xC0(%0)\n"
        "lqc2       $vf14, 0xD0(%0)\n"
        "lqc2       $vf15, 0xE0(%0)\n"
        "lqc2       $vf16, 0xF0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store the first row unchanged to the middle of the output).
static inline void vu0StoreFirstRow(V4_F960 *d) {
    __asm__ volatile("sqc2       $vf1, 0x80(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (add each row to its successor: vf1..vf15 += vf2..vf16).
static inline void vu0AddNext1to15(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf1, $vf1, $vf2\n"
        "vadd.xyzw  $vf2, $vf2, $vf3\n"
        "vadd.xyzw  $vf3, $vf3, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf5\n"
        "vadd.xyzw  $vf5, $vf5, $vf6\n"
        "vadd.xyzw  $vf6, $vf6, $vf7\n"
        "vadd.xyzw  $vf7, $vf7, $vf8\n"
        "vadd.xyzw  $vf8, $vf8, $vf9\n"
        "vadd.xyzw  $vf9, $vf9, $vf10\n"
        "vadd.xyzw  $vf10, $vf10, $vf11\n"
        "vadd.xyzw  $vf11, $vf11, $vf12\n"
        "vadd.xyzw  $vf12, $vf12, $vf13\n"
        "vadd.xyzw  $vf13, $vf13, $vf14\n"
        "vadd.xyzw  $vf14, $vf14, $vf15\n"
        "vadd.xyzw  $vf15, $vf15, $vf16\n");
}

// PORT: PS2-only VU0 inline asm (store the odd-numbered sums to the low half of the output).
static inline void vu0StoreOddSums(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf5, 0x20(%0)\n"
        "sqc2       $vf7, 0x30(%0)\n"
        "sqc2       $vf9, 0x40(%0)\n"
        "sqc2       $vf11, 0x50(%0)\n"
        "sqc2       $vf13, 0x60(%0)\n"
        "sqc2       $vf15, 0x70(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store the even-numbered sums to the upper half of the output).
static inline void vu0StoreEvenSums(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf2, 0x90(%0)\n"
        "sqc2       $vf4, 0xA0(%0)\n"
        "sqc2       $vf6, 0xB0(%0)\n"
        "sqc2       $vf8, 0xC0(%0)\n"
        "sqc2       $vf10, 0xD0(%0)\n"
        "sqc2       $vf12, 0xE0(%0)\n"
        "sqc2       $vf14, 0xF0(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (load every other row of the second block, vf1..vf8).
static inline void vu0LoadEvenRows(const V4_F960 *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x100(%0)\n"
        "lqc2       $vf2, 0x120(%0)\n"
        "lqc2       $vf3, 0x140(%0)\n"
        "lqc2       $vf4, 0x160(%0)\n"
        "lqc2       $vf5, 0x180(%0)\n"
        "lqc2       $vf6, 0x1A0(%0)\n"
        "lqc2       $vf7, 0x1C0(%0)\n"
        "lqc2       $vf8, 0x1E0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (copy vf1..vf8 to eight consecutive output rows).
static inline void vu0StoreCopy8(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x100(%0)\n"
        "sqc2       $vf2, 0x110(%0)\n"
        "sqc2       $vf3, 0x120(%0)\n"
        "sqc2       $vf4, 0x130(%0)\n"
        "sqc2       $vf5, 0x140(%0)\n"
        "sqc2       $vf6, 0x150(%0)\n"
        "sqc2       $vf7, 0x160(%0)\n"
        "sqc2       $vf8, 0x170(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (load the other interleaved rows of the second block, vf1..vf8).
static inline void vu0LoadOddRows(const V4_F960 *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x110(%0)\n"
        "lqc2       $vf2, 0x130(%0)\n"
        "lqc2       $vf3, 0x150(%0)\n"
        "lqc2       $vf4, 0x170(%0)\n"
        "lqc2       $vf5, 0x190(%0)\n"
        "lqc2       $vf6, 0x1B0(%0)\n"
        "lqc2       $vf7, 0x1D0(%0)\n"
        "lqc2       $vf8, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store the first row unchanged).
static inline void vu0StoreFirstRow2(V4_F960 *d) {
    __asm__ volatile("sqc2       $vf1, 0x180(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (add each row to its successor: vf1..vf7 += vf2..vf8).
static inline void vu0AddNext1to7(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf1, $vf1, $vf2\n"
        "vadd.xyzw  $vf2, $vf2, $vf3\n"
        "vadd.xyzw  $vf3, $vf3, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf5\n"
        "vadd.xyzw  $vf5, $vf5, $vf6\n"
        "vadd.xyzw  $vf6, $vf6, $vf7\n"
        "vadd.xyzw  $vf7, $vf7, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store sums vf1..vf7; trailing label keeps gas from filling a delay slot).
static inline void vu0StoreSums7(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x190(%0)\n"
        "sqc2       $vf2, 0x1A0(%0)\n"
        "sqc2       $vf3, 0x1B0(%0)\n"
        "sqc2       $vf4, 0x1C0(%0)\n"
        "sqc2       $vf5, 0x1D0(%0)\n"
        "sqc2       $vf6, 0x1E0(%0)\n"
        "sqc2       $vf7, 0x1F0(%0)\n"
        "1:\n"
        : : "r"(d) : "memory");
}

/* --- used by func_003BFAC0 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FAC0;

// PORT: PS2-only VU0 inline asm (load eight vec4 rows into vf1..vf8).
static inline void vu0LoadRows1to8(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x40(%0)\n"
        "lqc2       $vf6, 0x50(%0)\n"
        "lqc2       $vf7, 0x60(%0)\n"
        "lqc2       $vf8, 0x70(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store row vf1 unchanged).
static inline void vu0StoreRow1At40(V4_FAC0 *d) {
    __asm__ volatile("sqc2       $vf1, 0x40(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store sums vf1, vf3, vf5, vf7 and vf2).
static inline void vu0StoreHeadSums(V4_FAC0 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf5, 0x20(%0)\n"
        "sqc2       $vf7, 0x30(%0)\n"
        "sqc2       $vf2, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf4 to row 6).
static inline void vu0StoreV4At60(void *d) {
    __asm__ volatile("sqc2       $vf4, 0x60(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf6 to row 7).
static inline void vu0StoreV6At70(void *d) {
    __asm__ volatile("sqc2       $vf6, 0x70(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf1, vf3, vf5, vf7 to rows 0..3).
static inline void vu0StoreOddRows(V4_FAC0 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf5, 0x20(%0)\n"
        "sqc2       $vf7, 0x30(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (pairwise sums of even rows: vf3 = vf2+vf4, vf4 = vf4+vf6, vf5 = vf6+vf8).
static inline void vu0AddEvenPairs(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf3, $vf2, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf6\n"
        "vadd.xyzw  $vf5, $vf6, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store vf2 and vf3 to rows 4 and 5).
static inline void vu0StoreV2V3(V4_FAC0 *d) {
    __asm__ volatile(
        "sqc2       $vf2, 0x40(%0)\n"
        "sqc2       $vf3, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf5 to row 7).
static inline void vu0StoreV5At70(V4_FAC0 *d) {
    __asm__ volatile("sqc2       $vf5, 0x70(%0)\n" : : "r"(d) : "memory");
}

/* --- used by func_003BFB90 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FB90;

// PORT: PS2-only VU0 inline asm (first-block sums: vf9 = vf1+vf2, vf10 = vf3+vf4, vf11 = vf2+vf3, vf12 = vf6+vf8).
static inline void vu0AddHeadSums(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf2\n"
        "vadd.xyzw  $vf10, $vf3, $vf4\n"
        "vadd.xyzw  $vf11, $vf2, $vf3\n"
        "vadd.xyzw  $vf12, $vf6, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store first-block results to rows 0..5).
static inline void vu0StoreHeadRows(V4_FB90 *d) {
    __asm__ volatile(
        "sqc2       $vf9, 0x0(%0)\n"
        "sqc2       $vf10, 0x10(%0)\n"
        "sqc2       $vf1, 0x20(%0)\n"
        "sqc2       $vf11, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf7, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf6 to row 6).
static inline void vu0StoreV6At60(V4_FB90 *d) {
    __asm__ volatile("sqc2       $vf6, 0x60(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf12 to row 7).
static inline void vu0StoreV12At70(V4_FB90 *d) {
    __asm__ volatile("sqc2       $vf12, 0x70(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (loop sums: vf9 = vf2+vf4, vf10 = vf6+vf8).
static inline void vu0AddLoopSums(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf2, $vf4\n"
        "vadd.xyzw  $vf10, $vf6, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store loop results to rows 0..5).
static inline void vu0StoreLoopRows(V4_FB90 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf2, 0x20(%0)\n"
        "sqc2       $vf9, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf7, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf10 to row 7).
static inline void vu0StoreV10At70(V4_FB90 *d) {
    __asm__ volatile("sqc2       $vf10, 0x70(%0)\n" : : "r"(d) : "memory");
}

/* --- used by func_003BFC50 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FC50;

// PORT: PS2-only VU0 inline asm (load the twiddle vector into vf16).
static inline void vu0LoadTwiddle(const V4_FC50 *p) {
    __asm__ volatile("lqc2       $vf16, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (head: vf9 = (vf1+vf2)*w.x, vf10/vf11/vf12 = vf4/vf6/vf8 * w.x).
static inline void vu0ScaleHead(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf2\n"
        "vmulx.xyzw $vf10, $vf4, $vf16x\n"
        "vmulx.xyzw $vf11, $vf6, $vf16x\n"
        "vmulx.xyzw $vf12, $vf8, $vf16x\n"
        "vmulx.xyzw $vf9, $vf9, $vf16x\n");
}

// PORT: PS2-only VU0 inline asm (head butterfly: sub/add of rows against the scaled terms).
static inline void vu0ButterflyHead(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf4, $vf3, $vf10\n"
        "vadd.xyzw  $vf3, $vf3, $vf10\n"
        "vsub.xyzw  $vf6, $vf5, $vf11\n"
        "vadd.xyzw  $vf5, $vf5, $vf11\n"
        "vsub.xyzw  $vf2, $vf1, $vf9\n"
        "vadd.xyzw  $vf1, $vf1, $vf9\n"
        "vsub.xyzw  $vf8, $vf7, $vf12\n"
        "vadd.xyzw  $vf7, $vf7, $vf12\n");
}

// PORT: PS2-only VU0 inline asm (scale vf2 by w.y and vf1 by w.z).
static inline void vu0ScaleY2Z1(void) {
    __asm__ volatile(
        "vmuly.xyzw $vf2, $vf2, $vf16y\n"
        "vmulz.xyzw $vf1, $vf1, $vf16z\n");
}

// PORT: PS2-only VU0 inline asm (store head results in place, vf3..vf8 then vf1).
static inline void vu0StoreHeadInPlace(void *p) {
    __asm__ volatile(
        "sqc2       $vf3, 0x20(%0)\n"
        "sqc2       $vf4, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf6, 0x50(%0)\n"
        "sqc2       $vf7, 0x60(%0)\n"
        "sqc2       $vf8, 0x70(%0)\n"
        "sqc2       $vf1, 0x0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf2 to row 1).
static inline void vu0StoreV2At10(void *p) {
    __asm__ volatile("sqc2       $vf2, 0x10(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (scale even rows vf2/vf4/vf6/vf8 by w.x).
static inline void vu0ScaleEvenRows(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf2, $vf16x\n"
        "vmulx.xyzw $vf10, $vf4, $vf16x\n"
        "vmulx.xyzw $vf11, $vf6, $vf16x\n"
        "vmulx.xyzw $vf12, $vf8, $vf16x\n");
}

// PORT: PS2-only VU0 inline asm (butterfly of row pairs against the scaled terms).
static inline void vu0ButterflyPairs(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf2, $vf1, $vf9\n"
        "vadd.xyzw  $vf1, $vf1, $vf9\n"
        "vsub.xyzw  $vf4, $vf3, $vf10\n"
        "vadd.xyzw  $vf3, $vf3, $vf10\n"
        "vsub.xyzw  $vf6, $vf5, $vf11\n"
        "vadd.xyzw  $vf5, $vf5, $vf11\n"
        "vsub.xyzw  $vf8, $vf7, $vf12\n"
        "vadd.xyzw  $vf7, $vf7, $vf12\n");
}

// PORT: PS2-only VU0 inline asm (store butterfly rows vf1..vf7 in place).
static inline void vu0StoreRows1to7(void *p) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf2, 0x10(%0)\n"
        "sqc2       $vf3, 0x20(%0)\n"
        "sqc2       $vf4, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf6, 0x50(%0)\n"
        "sqc2       $vf7, 0x60(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf8 to row 7).
static inline void vu0StoreV8At70(void *p) {
    __asm__ volatile("sqc2       $vf8, 0x70(%0)\n" : : "r"(p) : "memory");
}

/* --- used by func_003BFD60 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FD60;

// PORT: PS2-only VU0 inline asm (load two twiddle vectors into vf15 and vf16).
static inline void vu0LoadTwiddles15and16(const V4_FD60 *p) {
    __asm__ volatile(
        "lqc2       $vf15, 0x0(%0)\n"
        "lqc2       $vf16, 0x10(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (head sums and differences of rows 1..4).
static inline void vu0AddSubRows1to4Head(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf3\n"
        "vadd.xyzw  $vf10, $vf2, $vf4\n"
        "vsub.xyzw  $vf11, $vf4, $vf2\n"
        "vsub.xyzw  $vf12, $vf3, $vf1\n");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf15 and vf7/vf8 by vf16.x/y).
static inline void vu0ScaleHeadLanes(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf15x\n"
        "vmuly.xyzw $vf10, $vf10, $vf15y\n"
        "vmulz.xyzw $vf11, $vf11, $vf15z\n"
        "vmulw.xyzw $vf12, $vf12, $vf15w\n"
        "vmulx.xyzw $vf7, $vf7, $vf16x\n"
        "vmuly.xyzw $vf8, $vf8, $vf16y\n");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 0..3).
static inline void vu0StoreResults4(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x0(%0)\n"
        "sqc2       $vf10, 0x10(%0)\n"
        "sqc2       $vf11, 0x20(%0)\n"
        "sqc2       $vf12, 0x30(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (sums and differences of rows 5..8).
static inline void vu0AddSubRows5to8(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf5, $vf7\n"
        "vadd.xyzw  $vf10, $vf6, $vf8\n"
        "vsub.xyzw  $vf11, $vf6, $vf8\n"
        "vsub.xyzw  $vf12, $vf5, $vf7\n");
}

// PORT: PS2-only VU0 inline asm (store vf9 and vf10 to rows 4 and 5).
static inline void vu0StoreResults5and6(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x40(%0)\n"
        "sqc2       $vf10, 0x50(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf11 to row 6).
static inline void vu0StoreV11At60(void *p) {
    __asm__ volatile("sqc2       $vf11, 0x60(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf12 to row 7).
static inline void vu0StoreV12At70Of(void *p) {
    __asm__ volatile("sqc2       $vf12, 0x70(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (loop: scale rows 3, 4, 7, 8 by vf16.x/y).
static inline void vu0ScaleLoopRows(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf3, $vf3, $vf16x\n"
        "vmuly.xyzw $vf4, $vf4, $vf16y\n"
        "vmulx.xyzw $vf7, $vf7, $vf16x\n"
        "vmuly.xyzw $vf8, $vf8, $vf16y\n");
}

// PORT: PS2-only VU0 inline asm (loop sums and differences of rows 1..4).
static inline void vu0AddSubRows1to4Loop(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf3\n"
        "vadd.xyzw  $vf10, $vf2, $vf4\n"
        "vsub.xyzw  $vf11, $vf2, $vf4\n"
        "vsub.xyzw  $vf12, $vf1, $vf3\n");
}

/* --- used by func_003BFE80 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FE80;

// PORT: PS2-only VU0 inline asm (add the upper four rows to the lower four: vf9..vf12 = vf1..vf4 + vf5..vf8).
static inline void vu0AddRowHalves(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf5\n"
        "vadd.xyzw  $vf10, $vf2, $vf6\n"
        "vadd.xyzw  $vf11, $vf3, $vf7\n"
        "vadd.xyzw  $vf12, $vf4, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf15).
static inline void vu0ScaleResultsBy15(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf15x\n"
        "vmuly.xyzw $vf10, $vf10, $vf15y\n"
        "vmulz.xyzw $vf11, $vf11, $vf15z\n"
        "vmulw.xyzw $vf12, $vf12, $vf15w\n");
}

// PORT: PS2-only VU0 inline asm (subtract lower four rows from the upper four, reversed order).
static inline void vu0SubRowHalvesRev(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf9, $vf8, $vf4\n"
        "vsub.xyzw  $vf10, $vf7, $vf3\n"
        "vsub.xyzw  $vf11, $vf6, $vf2\n"
        "vsub.xyzw  $vf12, $vf5, $vf1\n");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf16).
static inline void vu0ScaleResultsBy16(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf16x\n"
        "vmuly.xyzw $vf10, $vf10, $vf16y\n"
        "vmulz.xyzw $vf11, $vf11, $vf16z\n"
        "vmulw.xyzw $vf12, $vf12, $vf16w\n");
}

// PORT: PS2-only VU0 inline asm (load the third twiddle vector into vf16).
static inline void vu0LoadTwiddle16At20(const V4_FE80 *p) {
    __asm__ volatile("lqc2       $vf16, 0x20(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (loop: scale rows 5..8 per lane by vf16).
static inline void vu0ScaleRows5to8By16(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf5, $vf5, $vf16x\n"
        "vmuly.xyzw $vf6, $vf6, $vf16y\n"
        "vmulz.xyzw $vf7, $vf7, $vf16z\n"
        "vmulw.xyzw $vf8, $vf8, $vf16w\n");
}

// PORT: PS2-only VU0 inline asm (loop: subtract scaled upper rows from lower rows).
static inline void vu0SubRowHalves(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf9, $vf4, $vf8\n"
        "vsub.xyzw  $vf10, $vf3, $vf7\n"
        "vsub.xyzw  $vf11, $vf2, $vf6\n"
        "vsub.xyzw  $vf12, $vf1, $vf5\n");
}

/* --- used by func_003BFFA0 and later family members --- */
// PORT: PS2-only VU0 inline asm (load scale vectors 0 and 3 into vf15 and vf16).
static inline void vu0LoadScale0and3(const void *s) {
    __asm__ volatile(
        "lqc2       $vf15, 0x0(%0)\n"
        "lqc2       $vf16, 0x30(%0)\n"
        : : "r"(s) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 0..3 into vf1..vf4 and rows 8..11 into vf5..vf8).
static inline void vu0LoadRowsLo0Hi8(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x80(%0)\n"
        "lqc2       $vf6, 0x90(%0)\n"
        "lqc2       $vf7, 0xA0(%0)\n"
        "lqc2       $vf8, 0xB0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 12..15).
static inline void vu0StoreResultsC0(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0xC0(%0)\n"
        "sqc2       $vf10, 0xD0(%0)\n"
        "sqc2       $vf11, 0xE0(%0)\n"
        "sqc2       $vf12, 0xF0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load scale vectors 1 and 2 into vf15 and vf16).
static inline void vu0LoadScale1and2(const void *s) {
    __asm__ volatile(
        "lqc2       $vf15, 0x10(%0)\n"
        "lqc2       $vf16, 0x20(%0)\n"
        : : "r"(s) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 4..7 into vf1..vf4 and rows 12..15 into vf5..vf8).
static inline void vu0LoadRowsLo4Hi12(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x40(%0)\n"
        "lqc2       $vf2, 0x50(%0)\n"
        "lqc2       $vf3, 0x60(%0)\n"
        "lqc2       $vf4, 0x70(%0)\n"
        "lqc2       $vf5, 0xC0(%0)\n"
        "lqc2       $vf6, 0xD0(%0)\n"
        "lqc2       $vf7, 0xE0(%0)\n"
        "lqc2       $vf8, 0xF0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 4..7).
static inline void vu0StoreResults40(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x40(%0)\n"
        "sqc2       $vf10, 0x50(%0)\n"
        "sqc2       $vf11, 0x60(%0)\n"
        "sqc2       $vf12, 0x70(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 8..11).
static inline void vu0StoreResults80(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x80(%0)\n"
        "sqc2       $vf10, 0x90(%0)\n"
        "sqc2       $vf11, 0xA0(%0)\n"
        "sqc2       $vf12, 0xB0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load scale vectors 4 and 5 into vf1 and vf2).
static inline void vu0LoadScale4and5(const void *s) {
    __asm__ volatile(
        "lqc2       $vf1, 0x40(%0)\n"
        "lqc2       $vf2, 0x50(%0)\n"
        : : "r"(s) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 24..31 into vf9..vf16).
static inline void vu0LoadRows24to31(const void *p) {
    __asm__ volatile(
        "lqc2       $vf9, 0x180(%0)\n"
        "lqc2       $vf10, 0x190(%0)\n"
        "lqc2       $vf11, 0x1A0(%0)\n"
        "lqc2       $vf12, 0x1B0(%0)\n"
        "lqc2       $vf13, 0x1C0(%0)\n"
        "lqc2       $vf14, 0x1D0(%0)\n"
        "lqc2       $vf15, 0x1E0(%0)\n"
        "lqc2       $vf16, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf1, vf13..vf16 per lane by vf2).
static inline void vu0ScaleRows9to16(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf1x\n"
        "vmuly.xyzw $vf10, $vf10, $vf1y\n"
        "vmulz.xyzw $vf11, $vf11, $vf1z\n"
        "vmulw.xyzw $vf12, $vf12, $vf1w\n"
        "vmulx.xyzw $vf13, $vf13, $vf2x\n"
        "vmuly.xyzw $vf14, $vf14, $vf2y\n"
        "vmulz.xyzw $vf15, $vf15, $vf2z\n"
        "vmulw.xyzw $vf16, $vf16, $vf2w\n");
}

// PORT: PS2-only VU0 inline asm (load rows 19..16 reversed into vf4..vf1).
static inline void vu0LoadRowsRev100(const void *p) {
    __asm__ volatile(
        "lqc2       $vf4, 0x130(%0)\n"
        "lqc2       $vf3, 0x120(%0)\n"
        "lqc2       $vf2, 0x110(%0)\n"
        "lqc2       $vf1, 0x100(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (butterfly of vf1..vf4 against vf9..vf12: vf5..vf8 = diff, vf1..vf4 = sum).
static inline void vu0Butterfly1to4With9to12(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf5, $vf4, $vf12\n"
        "vsub.xyzw  $vf6, $vf3, $vf11\n"
        "vsub.xyzw  $vf7, $vf2, $vf10\n"
        "vsub.xyzw  $vf8, $vf1, $vf9\n"
        "vadd.xyzw  $vf1, $vf1, $vf9\n"
        "vadd.xyzw  $vf2, $vf2, $vf10\n"
        "vadd.xyzw  $vf3, $vf3, $vf11\n"
        "vadd.xyzw  $vf4, $vf4, $vf12\n");
}

// PORT: PS2-only VU0 inline asm (store butterfly sums to rows 16..19 and differences to rows 28..31).
static inline void vu0StoreButterfly100(void *p) {
    __asm__ volatile(
        "sqc2       $vf1, 0x100(%0)\n"
        "sqc2       $vf2, 0x110(%0)\n"
        "sqc2       $vf3, 0x120(%0)\n"
        "sqc2       $vf4, 0x130(%0)\n"
        "sqc2       $vf5, 0x1C0(%0)\n"
        "sqc2       $vf6, 0x1D0(%0)\n"
        "sqc2       $vf7, 0x1E0(%0)\n"
        "sqc2       $vf8, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 23..20 reversed into vf4..vf1).
static inline void vu0LoadRowsRev140(const void *p) {
    __asm__ volatile(
        "lqc2       $vf4, 0x170(%0)\n"
        "lqc2       $vf3, 0x160(%0)\n"
        "lqc2       $vf2, 0x150(%0)\n"
        "lqc2       $vf1, 0x140(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (butterfly of vf1..vf4 against vf13..vf16: vf5..vf8 = diff, vf1..vf4 = sum).
static inline void vu0Butterfly1to4With13to16(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf5, $vf4, $vf16\n"
        "vsub.xyzw  $vf6, $vf3, $vf15\n"
        "vsub.xyzw  $vf7, $vf2, $vf14\n"
        "vsub.xyzw  $vf8, $vf1, $vf13\n"
        "vadd.xyzw  $vf1, $vf1, $vf13\n"
        "vadd.xyzw  $vf2, $vf2, $vf14\n"
        "vadd.xyzw  $vf3, $vf3, $vf15\n"
        "vadd.xyzw  $vf4, $vf4, $vf16\n");
}

// PORT: PS2-only VU0 inline asm (store butterfly sums to rows 20..23 and differences to rows 24..27; trailing label keeps gas from filling the return delay slot).
static inline void vu0StoreButterfly140(void *p) {
    __asm__ volatile(
        "sqc2       $vf1, 0x140(%0)\n"
        "sqc2       $vf2, 0x150(%0)\n"
        "sqc2       $vf3, 0x160(%0)\n"
        "sqc2       $vf4, 0x170(%0)\n"
        "sqc2       $vf5, 0x180(%0)\n"
        "sqc2       $vf6, 0x190(%0)\n"
        "sqc2       $vf7, 0x1A0(%0)\n"
        "sqc2       $vf8, 0x1B0(%0)\n"
        "1:\n"
        : : "r"(p) : "memory");
}

/* --- used by func_003C01A0 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_01A0;

// PORT: PS2-only VU0 inline asm (load one scale vector into vf16).
static inline void vu0LoadScaleVec16(const V4_01A0 *v) {
    __asm__ volatile("lqc2       $vf16, %0\n" : : "m"(*v));
}

// PORT: PS2-only VU0 inline asm (load rows 0..3 into vf1..vf4 and rows 16..19 into vf5..vf8).
static inline void vu0LoadRowsG0(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x100(%0)\n"
        "lqc2       $vf6, 0x110(%0)\n"
        "lqc2       $vf7, 0x120(%0)\n"
        "lqc2       $vf8, 0x130(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 4..7 into vf1..vf4 and rows 20..23 into vf5..vf8).
static inline void vu0LoadRowsG1(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x40(%0)\n"
        "lqc2       $vf2, 0x50(%0)\n"
        "lqc2       $vf3, 0x60(%0)\n"
        "lqc2       $vf4, 0x70(%0)\n"
        "lqc2       $vf5, 0x140(%0)\n"
        "lqc2       $vf6, 0x150(%0)\n"
        "lqc2       $vf7, 0x160(%0)\n"
        "lqc2       $vf8, 0x170(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 8..11 into vf1..vf4 and rows 24..27 into vf5..vf8).
static inline void vu0LoadRowsG2(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x80(%0)\n"
        "lqc2       $vf2, 0x90(%0)\n"
        "lqc2       $vf3, 0xA0(%0)\n"
        "lqc2       $vf4, 0xB0(%0)\n"
        "lqc2       $vf5, 0x180(%0)\n"
        "lqc2       $vf6, 0x190(%0)\n"
        "lqc2       $vf7, 0x1A0(%0)\n"
        "lqc2       $vf8, 0x1B0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 12..15 into vf1..vf4 and rows 28..31 into vf5..vf8).
static inline void vu0LoadRowsG3(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0xC0(%0)\n"
        "lqc2       $vf2, 0xD0(%0)\n"
        "lqc2       $vf3, 0xE0(%0)\n"
        "lqc2       $vf4, 0xF0(%0)\n"
        "lqc2       $vf5, 0x1C0(%0)\n"
        "lqc2       $vf6, 0x1D0(%0)\n"
        "lqc2       $vf7, 0x1E0(%0)\n"
        "lqc2       $vf8, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 27..24 and 11..8 reversed into vf8..vf1).
static inline void vu0LoadRowsRevG2(const void *p) {
    __asm__ volatile(
        "lqc2       $vf8, 0x1B0(%0)\n"
        "lqc2       $vf7, 0x1A0(%0)\n"
        "lqc2       $vf6, 0x190(%0)\n"
        "lqc2       $vf5, 0x180(%0)\n"
        "lqc2       $vf4, 0xB0(%0)\n"
        "lqc2       $vf3, 0xA0(%0)\n"
        "lqc2       $vf2, 0x90(%0)\n"
        "lqc2       $vf1, 0x80(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9).
static inline void vu0StoreVf9(void *p) {
    __asm__ volatile("sqc2       $vf9, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf10).
static inline void vu0StoreVf10(void *p) {
    __asm__ volatile("sqc2       $vf10, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf11).
static inline void vu0StoreVf11(void *p) {
    __asm__ volatile("sqc2       $vf11, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf12).
static inline void vu0StoreVf12(void *p) {
    __asm__ volatile("sqc2       $vf12, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (final store of vf12; trailing label keeps gas from filling the return delay slot).
static inline void vu0StoreVf12Last(void *p) {
    __asm__ volatile("sqc2       $vf12, 0x0(%0)\n" "1:\n" : : "r"(p) : "memory");
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF8D0);
#ifdef SKIP_ASM
void func_003BF8D0(V4_F8D0 *src, V4_F8D0 *dst) {
    int i = 4;
    vu0ClearSum();
    do {
        vu0LoadRows2to9(src);
        vu0AddNext1to8();
        vu0StoreSums(dst);
        i--;
        vu0StoreSum5(dst);
        src += 8;
        vu0StoreSum7Carry(dst);
        dst += 4;
    } while (i != 0);
}
/* retail: two padding nops end this function's slot (the next VU0 routine starts after them) */
__asm__("nop\n\tnop");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF960);
#ifdef SKIP_ASM
void func_003BF960(V4_F960 *src, V4_F960 *dst) {
    vu0LoadRows16(src);
    vu0StoreFirstRow(dst);
    vu0AddNext1to15();
    vu0StoreOddSums(dst);
    vu0StoreEvenSums(dst);
    vu0LoadEvenRows(src);
    vu0StoreCopy8(dst);
    vu0LoadOddRows(src);
    vu0StoreFirstRow2(dst);
    vu0AddNext1to7();
    vu0StoreSums7(dst);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFAC0);
#ifdef SKIP_ASM
void func_003BFAC0(V4_FAC0 *src, V4_FAC0 *dst) {
    int i;
    vu0LoadRows1to8(src);
    vu0StoreRow1At40(dst);
    vu0AddNext1to7();
    vu0StoreHeadSums(dst);
    i = 3;
    vu0StoreV4At60(dst);
    src += 8;
    vu0StoreV6At70(dst);
    dst += 8;
    do {
        vu0LoadRows1to8(src);
        vu0StoreOddRows(dst);
        vu0AddEvenPairs();
        vu0StoreV2V3(dst);
        i--;
        vu0StoreV4At60(dst);
        src += 8;
        vu0StoreV5At70(dst);
        dst += 8;
    } while (i != 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFB90);
#ifdef SKIP_ASM
void func_003BFB90(V4_FB90 *src, V4_FB90 *dst) {
    int i;
    vu0LoadRows1to8(src);
    vu0AddHeadSums();
    vu0StoreHeadRows(dst);
    i = 3;
    vu0StoreV6At60(dst);
    src += 8;
    vu0StoreV12At70(dst);
    dst += 8;
top:
    vu0LoadRows1to8(src);
    vu0AddLoopSums();
    vu0StoreLoopRows(dst);
    i--;
    vu0StoreV6At60(dst);
    src += 8;
    vu0StoreV10At70(dst);
    dst += 8;
    if (i != 0) goto top;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFC50);
#ifdef SKIP_ASM
void func_003BFC50(V4_FC50 *src, V4_FC50 *dst) {
    int i;
    vu0LoadTwiddle(dst);
    vu0LoadRows1to8(src);
    vu0ScaleHead();
    vu0ButterflyHead();
    vu0ScaleY2Z1();
    vu0StoreHeadInPlace(src);
    i = 3;
    vu0StoreV2At10(src);
    src += 8;
top:
    vu0LoadRows1to8(src);
    vu0ScaleEvenRows();
    vu0ButterflyPairs();
    vu0StoreRows1to7(src);
    i--;
    vu0StoreV8At70(src);
    src += 8;
    if (i != 0) goto top;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFD60);
#ifdef SKIP_ASM
void func_003BFD60(V4_FD60 *src, V4_FD60 *dst, V4_FD60 *p6) {
    int i;
    vu0LoadTwiddles15and16(dst);
    vu0LoadRows1to8(src);
    vu0AddSubRows1to4Head();
    vu0ScaleHeadLanes();
    vu0StoreResults4(p6);
    vu0AddSubRows5to8();
    vu0StoreResults5and6(p6);
    i = 3;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
top:
    vu0LoadRows1to8(src);
    vu0ScaleLoopRows();
    vu0AddSubRows1to4Loop();
    vu0StoreResults4(p6);
    vu0AddSubRows5to8();
    vu0StoreResults5and6(p6);
    i--;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
    if (i != 0) goto top;
}
/* retail: two padding nops end this function's slot (the next VU0 routine starts after them) */
__asm__("nop\n\tnop");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFE80);
#ifdef SKIP_ASM
void func_003BFE80(V4_FE80 *src, V4_FE80 *dst, V4_FE80 *p6) {
    int i;
    vu0LoadTwiddles15and16(dst);
    vu0LoadRows1to8(src);
    vu0AddRowHalves();
    vu0ScaleResultsBy15();
    vu0StoreResults4(p6);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreResults5and6(p6);
    i = 3;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
    vu0LoadTwiddle16At20(dst);
top:
    vu0LoadRows1to8(src);
    vu0ScaleRows5to8By16();
    vu0AddRowHalves();
    vu0StoreResults4(p6);
    vu0SubRowHalves();
    vu0StoreResults5and6(p6);
    i--;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
    if (i != 0) goto top;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFFA0);
#ifdef SKIP_ASM
void func_003BFFA0(void *in, void *scale, void *out) {
    vu0LoadScale0and3(scale);
    vu0LoadRowsLo0Hi8(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy15();
    vu0StoreResults4(out);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreResultsC0(out);
    vu0LoadScale1and2(scale);
    vu0LoadRowsLo4Hi12(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy15();
    vu0StoreResults40(out);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreResults80(out);
    vu0LoadScale4and5(scale);
    vu0LoadRows24to31(in);
    vu0ScaleRows9to16();
    vu0LoadRowsRev100(in);
    vu0Butterfly1to4With9to12();
    vu0StoreButterfly100(out);
    vu0LoadRowsRev140(in);
    vu0Butterfly1to4With13to16();
    vu0StoreButterfly140(out);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C01A0);
#ifdef SKIP_ASM
void func_003C01A0(void *in, void *scale, void *out, int stride) {
    const V4_01A0 *s = (const V4_01A0 *)scale;
    vu0LoadScaleVec16(&s[0]);
    vu0LoadRowsG0(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[1]);
    vu0LoadRowsG1(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[2]);
    vu0LoadRowsG2(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[3]);
    vu0LoadRowsG3(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[4]);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[5]);
    vu0LoadRowsRevG2(in);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12Last(out);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C03E0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C04F0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed halfwords).
void func_003C04F0(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "addiu     $10, $0, 0xFFF\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "pcpyh     $10, $10\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "pcpyld    $10, $10, $10\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "pand      $6, $6, $10\n"
        "pand      $8, $8, $10\n"
        "sq        $6, 0x0(%1)\n"
        "sq        $8, 0x10(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "$10", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0564);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed halfwords).
void func_003C0564(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "addiu     $10, $0, 0x3FF\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "pcpyh     $10, $10\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "pcpyld    $10, $10, $10\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "pand      $6, $6, $10\n"
        "pand      $8, $8, $10\n"
        "sq        $6, 0x0(%1)\n"
        "sq        $8, 0x10(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "$10", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C05E0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed bytes).
void func_003C05E0(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "ppacb     $6, $8, $6\n"
        "sq        $6, 0x0(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0640);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed bytes).
void func_003C0640(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "addiu     $10, $0, 0x1F1F\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "pcpyh     $10, $10\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "pcpyld    $10, $10, $10\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "ppacb     $6, $8, $6\n"
        "pand      $6, $6, $10\n"
        "sq        $6, 0x0(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "$10", "memory");
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C06B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C07A8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 FPU-flag probe: builds two float4s from flag bits and multiplies them on VU0.
void func_003C07A8_impl(int flags) __asm__("func_003C07A8");
void func_003C07A8_impl(int flags)
{
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    int i;
    for (i = 0; i < 4; i++) {
        float f;
        if ((flags & 0x8800) == 0) {
            f = 0.0f;
            if (!(flags & 8))
                f = 1.0f;
        } else {
            f = 1.0000000031710769e-30f;
            if (!(flags & 8))
                f = 1.0000000150474662e+30f;
        }
        a[i] = f;
        if (flags & 0x80)
            f = -f;
        b[i] = f;
        flags <<= 1;
    }
    __asm__ __volatile__(
        "qmfc2.ni   $8, $vf1\n"
        "qmfc2.ni   $9, $vf2\n"
        "lqc2       $vf1, %0\n"
        "lqc2       $vf2, %1\n"
        "vmul.xyzw  $vf1, $vf1, $vf2\n"
        "qmtc2.ni   $8, $vf1\n"
        "qmtc2.ni   $9, $vf2\n"
        "vnop\n"
        :
        : "m"(a[0]), "m"(b[0])
        : "$8", "$9");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0858);
#ifdef SKIP_ASM
/* PORT: PS2-only VU0 state save; func_0031A308 without the $vi22/$vi18
   saves, and with ctc2 (not cfc2) on $vi16 as in the shipped code. */
void func_003C0858(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "cfc2.i     $9, $vi17\n"
        "sqc2       $vf1, 0x0($8)\n"
        "sqc2       $vf2, 0x10($8)\n"
        "sw         $9, 0x200($8)\n"
        "sqc2       $vf3, 0x20($8)\n"
        "sqc2       $vf4, 0x30($8)\n"
        "ctc2.ni    $9, $vi16\n"
        "sqc2       $vf5, 0x40($8)\n"
        "sqc2       $vf6, 0x50($8)\n"
        "sw         $9, 0x204($8)\n"
        "sqc2       $vf7, 0x60($8)\n"
        "sqc2       $vf8, 0x70($8)\n"
        "vmaddx.xyzw $vf1, $vf0, $vf0x\n"
        "sqc2       $vf9, 0x80($8)\n"
        "sqc2       $vf10, 0x90($8)\n"
        "sqc2       $vf11, 0xA0($8)\n"
        "sqc2       $vf12, 0xB0($8)\n"
        "sqc2       $vf13, 0xC0($8)\n"
        "sqc2       $vf14, 0xD0($8)\n"
        "sqc2       $vf15, 0xE0($8)\n"
        "sqc2       $vf16, 0xF0($8)\n"
        "sqc2       $vf17, 0x100($8)\n"
        "sqc2       $vf18, 0x110($8)\n"
        "sqc2       $vf19, 0x120($8)\n"
        "sqc2       $vf20, 0x130($8)\n"
        "sqc2       $vf21, 0x140($8)\n"
        "sqc2       $vf22, 0x150($8)\n"
        "sqc2       $vf23, 0x160($8)\n"
        "sqc2       $vf24, 0x170($8)\n"
        "sqc2       $vf25, 0x180($8)\n"
        "sqc2       $vf26, 0x190($8)\n"
        "sqc2       $vf27, 0x1A0($8)\n"
        "sqc2       $vf28, 0x1B0($8)\n"
        "sqc2       $vf29, 0x1C0($8)\n"
        "sqc2       $vf30, 0x1D0($8)\n"
        "sqc2       $vf31, 0x1E0($8)\n"
        "sqc2       $vf1, 0x1F0($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C08F8);
#ifdef SKIP_ASM
void func_003C07A8(int status);

/* PORT: PS2-only VU0 state restore; same as func_0031A3C0 without the
   $vi22/$vi18 restore. */
void func_003C08F8(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "lqc2       $vf1, 0x1F0($8)\n"
        "vaddax.xyzw ACC, $vf1, $vf0x\n"
        "lqc2       $vf1, 0x0($8)\n"
        "lqc2       $vf2, 0x10($8)\n"
        "lqc2       $vf3, 0x20($8)\n"
        "lqc2       $vf4, 0x30($8)\n"
        "lqc2       $vf5, 0x40($8)\n"
        "lqc2       $vf6, 0x50($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
    func_003C07A8(*(int*)((char*)buf + 0x200));
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "lqc2       $vf7, 0x60($8)\n"
        "lqc2       $vf8, 0x70($8)\n"
        "lqc2       $vf9, 0x80($8)\n"
        "lqc2       $vf10, 0x90($8)\n"
        "lqc2       $vf11, 0xA0($8)\n"
        "lqc2       $vf12, 0xB0($8)\n"
        "lw         $9, 0x204($8)\n"
        "lqc2       $vf13, 0xC0($8)\n"
        "lqc2       $vf14, 0xD0($8)\n"
        "ctc2.ni    $9, $vi16\n"
        "lqc2       $vf15, 0xE0($8)\n"
        "lqc2       $vf16, 0xF0($8)\n"
        "lqc2       $vf17, 0x100($8)\n"
        "lqc2       $vf18, 0x110($8)\n"
        "lqc2       $vf19, 0x120($8)\n"
        "lqc2       $vf20, 0x130($8)\n"
        "lqc2       $vf21, 0x140($8)\n"
        "lqc2       $vf22, 0x150($8)\n"
        "lqc2       $vf23, 0x160($8)\n"
        "lqc2       $vf24, 0x170($8)\n"
        "lqc2       $vf25, 0x180($8)\n"
        "lqc2       $vf26, 0x190($8)\n"
        "lqc2       $vf27, 0x1A0($8)\n"
        "lqc2       $vf28, 0x1B0($8)\n"
        "lqc2       $vf29, 0x1C0($8)\n"
        "lqc2       $vf30, 0x1D0($8)\n"
        "lqc2       $vf31, 0x1E0($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C09B8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0A60);
#ifdef SKIP_ASM
struct D_0A60 { char pad[0x1AAE]; unsigned short s1AAE; char pad2[0x1B1C - 0x1AB0]; int r[7]; int f1B38; };
extern struct D_0A60 D_0050AD00_0A60 __asm__("D_0050AD00");
extern int D_0050A94C_0A60 __asm__("D_0050A94C");
extern void func_003C4978_0A60(int, int, int, int) __asm__("func_003C4978");

void func_003C0A60(void) {
    func_003C4978_0A60(D_0050AD00_0A60.f1B38, D_0050A94C_0A60, D_0050AD00_0A60.s1AAE >> 4, 0x10000);
    *(volatile int *)0x1000D010 = D_0050AD00_0A60.r[0];
    *(volatile int *)0x1000D080 = D_0050AD00_0A60.r[1];
    *(volatile int *)0x1000D020 = D_0050AD00_0A60.r[2];
    *(volatile int *)0x1000D410 = D_0050AD00_0A60.r[3];
    *(volatile int *)0x1000D430 = D_0050AD00_0A60.r[4];
    *(volatile int *)0x1000D480 = D_0050AD00_0A60.r[5];
    *(volatile int *)0x1000D420 = D_0050AD00_0A60.r[6];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0B10);
#ifdef SKIP_ASM
struct S_0B10 { char pad[0xC80]; char buf[1]; };
extern struct S_0B10 D_0050AD00_0B10 __asm__("D_0050AD00");
extern void func_003C51E8(void *, void *, int);
extern int func_00426F08(void *);
extern void func_00426D18(void *, int, int, void *, int, int, int, int, int);

void func_003C0B10(int a0, void *a1, int a2) {
    volatile int i;
    int two = a0 == 2;
    if (a2) {
        func_003C51E8(&D_0050AD00_0B10, a1, a2);
    }
    while (func_00426F08(D_0050AD00_0B10.buf)) {
        for (i = 0; i < 10000; i++) {
        }
    }
    func_00426D18(D_0050AD00_0B10.buf, a0, two, &D_0050AD00_0B10, a2, 0, 0, 0, 0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C0BE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003BA550(int, unsigned char);
struct S_0BE8 { char pad[0x2F]; unsigned char a; unsigned char b; };
extern struct S_0BE8 D_0050A8E8_0BE8 __asm__("D_0050A8E8");

void func_003C0BE8(int arg0) {
    func_003BA550(arg0 + D_0050A8E8_0BE8.b + D_0050A8E8_0BE8.a, D_0050A8E8_0BE8.a);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0C18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A8E8_0C18[] __asm__("D_0050A8E8");
extern unsigned char D_0050A918_0C18[] __asm__("D_0050A918");

void func_003C0C18(int arg0, int *arg1, int *arg2) {
    if (arg0 & 8) {
        *arg1 = 0;
        *arg2 = D_0050A918_0C18[0];
        return;
    }
    if (arg0 & 0x100) {
        char *b = D_0050A8E8_0C18;
        *arg1 = *(unsigned char *)(b + 0x30);
        *arg2 = *(unsigned char *)(b + 0x30) + *(unsigned char *)(b + 0x2F);
        return;
    }
    if (arg0 & 4) {
        char *b = D_0050A8E8_0C18;
        *arg1 = *(unsigned char *)(b + 0x30) + *(unsigned char *)(b + 0x2F);
        *arg2 = *(short *)(b + 0x17E);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C0C90);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0E28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Sub_0E28 {
    char pad00[0xA];
    unsigned short hA;
    unsigned short hC;
    unsigned char bE;
    unsigned char bF;
    unsigned char b10;
    char pad11[0x20 - 0x11];
    unsigned char b20;
    unsigned char b21;
    char pad22[0x26 - 0x22];
    unsigned char b26;
    unsigned char b27;
    unsigned char b28;
    unsigned char b29;
    unsigned char b2A;
    char pad2B[0x44 - 0x2B];
    unsigned int w44;
    int w48;
    char pad4C[0xA0 - 0x4C];
};
struct Ch_0E28 {
    char pad0[0x28];
    short h28;
    char pad2A[0x69 - 0x2A];
    signed char b69;
    char pad6A[0x8C - 0x6A];
};
struct G_0E28 {
    char pad0[4];
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    char pad9[0x20 - 9];
    struct Sub_0E28 sub;
    char padC0[0xD4 - 0xC0];
    struct Sub_0E28 saved;
    char pad174[0x174 - 0x174];
    signed char f174;
    char pad175[0x17E - 0x175];
    short h17E;
    char pad180[0x1F0 - 0x180];
    struct Ch_0E28 *chans;
};
struct O_0E28 { char pad[0x13]; unsigned char b13; };
extern struct G_0E28 D_0050A8E8_0E28 __asm__("D_0050A8E8");
extern struct Sub_0E28 D_0050A908_0E28 __asm__("D_0050A908");
extern struct O_0E28 *D_0050B9B0_0E28 __asm__("D_0050B9B0");
extern void f8148_0E28(int) __asm__("func_003C8148");
extern void f38E0_0E28(int) __asm__("func_003C38E0");

int func_003C0E28(void) {
    struct Sub_0E28 s;
    int i;

    s = D_0050A908_0E28;
    if (D_0050A8E8_0E28.f174) {
        D_0050A8E8_0E28.sub = D_0050A8E8_0E28.saved;
        if (D_0050A8E8_0E28.saved.b29 != s.b29) {
            return 0;
        }
    }
    if (s.hA <= 24000) {
        s.hA = 24000;
    } else if (s.hA <= 36000) {
        s.hA = 36000;
    } else {
        s.hA = 48000;
    }
    if (s.hC <= 24000) {
        s.hC = 24000;
    } else if (s.hC <= 36000) {
        s.hC = 36000;
    } else {
        s.hC = 48000;
    }
    if (s.b29 & 2) {
        s.b10 = 0x18;
        if (s.b27 < 4) {
            s.b27 = 4;
        }
    }
    if (s.b29 & 1) {
        if (s.b27 > 2) {
            s.b27 = 2;
        }
        s.b28 = 0;
    }
    if (s.b2A > 100) {
        s.b2A = 100;
    }
    if (s.b27 < D_0050A8E8_0E28.b4) {
        s.b27 = D_0050A8E8_0E28.b4;
    } else if (s.b27 > D_0050A8E8_0E28.b5) {
        s.b27 = D_0050A8E8_0E28.b5;
    }
    if (s.b27 == 5) {
        s.b28 = 1;
    } else {
        s.b28 = 0;
    }
    if (s.bE > D_0050A8E8_0E28.b6) {
        s.bE = D_0050A8E8_0E28.b6;
    }
    if (s.bF > D_0050A8E8_0E28.b7) {
        s.bF = D_0050A8E8_0E28.b7;
    }
    if (s.b10 > D_0050A8E8_0E28.b8) {
        s.b10 = D_0050A8E8_0E28.b8;
    }
    if (s.b26 > 0x20) {
        s.b26 = 0x20;
    }
    f8148_0E28(s.b20);
    if (D_0050A8E8_0E28.sub.w44 != 0 && (s.w44 & 0xF)) {
        s.w44 = ((s.w44 + 0xF) >> 4) << 4;
        s.w48 -= 0x10;
    }
    if (D_0050A8E8_0E28.f174) {
        D_0050A8E8_0E28.sub.b20 = s.b20;
        D_0050A8E8_0E28.sub.b21 = s.b21;
        D_0050B9B0_0E28->b13 = s.b21;
        if (D_0050A8E8_0E28.saved.b27 != s.b27) {
            D_0050A8E8_0E28.sub.b27 = s.b27;
            for (i = 0; i < D_0050A8E8_0E28.h17E; i++) {
                if (D_0050A8E8_0E28.chans[i].b69 == 1 && D_0050A8E8_0E28.chans[i].h28 < 0) {
                    f38E0_0E28(i);
                }
            }
        }
        return 0;
    }
    D_0050A8E8_0E28.h17E = s.bE + s.bF + s.b10;
    D_0050A8E8_0E28.sub = s;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C1298);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct KV_1298 { int key; int val; };
struct T_1298 {
    char pad0[0x20];
    struct KV_1298 e[(0x1A0 - 0x20) / 8];
    struct { int a; int b; int c; int d; } f[1];
};
struct H_1298 {
    char pad0[0x83C];
    struct KV_1298 k[(0x9BC - 0x83C) / 8];
    struct KV_1298 k2[(0xCAC - 0x9BC) / 8];
    int padCAC;
    struct T_1298 *tbl;
};
struct Ent_1298 {
    char pad0[4];
    short list[15];
    char pad22;
    unsigned char n;
    char pad24[4];
    short f28;
    char pad2A[0x8C - 0x2A];
};
struct G_1298 {
    char pad0[0x2F];
    unsigned char cnt2;
    unsigned char cnt1;
    char pad31[0x49 - 0x31];
    unsigned char mode;
    char pad4A[0x1F0 - 0x4A];
    struct Ent_1298 *ents;
};
extern struct G_1298 D_0050A8E8_1298 __asm__("D_0050A8E8");
extern struct H_1298 D_0050AD00_1298 __asm__("D_0050AD00");
extern void f_A550_1298(int) __asm__("func_003BA550");

void func_003C1298(void) {
    int i;
    int j;
    int h;

    for (i = 0; i < D_0050A8E8_1298.cnt1; i++) {
        if (D_0050AD00_1298.tbl->e[i].key != 0 && D_0050A8E8_1298.ents[i].f28 == -1) {
            if (D_0050AD00_1298.k[i].key != D_0050AD00_1298.tbl->e[i].key) {
                D_0050AD00_1298.k[i].val = D_0050AD00_1298.tbl->e[i].key & 0x7FFFFF;
            }
            if (D_0050AD00_1298.k[i].val == 0) {
                for (j = 0; j < D_0050A8E8_1298.ents[i].n; j++) {
                    h = D_0050A8E8_1298.ents[i].list[j];
                    D_0050AD00_1298.tbl->e[h].key = 0;
                    f_A550_1298(h);
                    if (D_0050A8E8_1298.mode == 2) {
                        D_0050AD00_1298.tbl->e[h + 0x18].key = 0;
                    }
                }
            }
        }
    }
    for (i = 0; i < D_0050A8E8_1298.cnt2; i++) {
        if (D_0050AD00_1298.tbl->f[i].a != 0 && D_0050A8E8_1298.ents[i + D_0050A8E8_1298.cnt1].f28 == -1) {
            if (D_0050AD00_1298.k2[i].key != D_0050AD00_1298.tbl->f[i].a) {
                D_0050AD00_1298.k2[i].val = 0;
            }
            if (D_0050AD00_1298.k2[i].val == -1) {
                for (j = 0; j < D_0050A8E8_1298.ents[i + D_0050A8E8_1298.cnt1].n; j++) {
                    h = D_0050A8E8_1298.ents[i + D_0050A8E8_1298.cnt1].list[j];
                    D_0050AD00_1298.tbl->f[h - D_0050A8E8_1298.cnt1].a = 0;
                    f_A550_1298(h);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C1578);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad[0xC]; int v; int mode; } A_1578;
typedef struct { char pad[0x1AA4]; int a; char pad2[0x5C]; int b; } G_1578;
extern void func_003C4918_1578(int) __asm__("func_003C4918");
extern void func_00423DD0(int);
extern G_1578 D_0050AD00_AD00 __asm__("D_0050AD00");

void func_003C1578(A_1578 *arg0) {
    switch (arg0->mode) {
    case 2:
        func_003C4918_1578(arg0->v);
        return;
    case 3:
        break;
    case 0:
        D_0050AD00_AD00.b = arg0->v;
        func_00423DD0(D_0050AD00_AD00.a);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C15D8);
#ifdef SKIP_ASM
void func_003C15D8(char *dst, char *src) {
    while (*dst) dst++;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C1638);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C1980);
#ifdef SKIP_ASM
struct S_1980 { char pad[0x1C0]; int cnt; };
extern struct S_1980 D_0050A8E8_1980 __asm__("D_0050A8E8");
int func_003C1980(void) {
    D_0050A8E8_1980.cnt = D_0050A8E8_1980.cnt + 1;
    // PORT: MIPS sync + EE ei (no C equivalent)
    __asm__ volatile("sync\n\tei");
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C19A8);

INCLUDE_ASM("ealib/seg_2B4578", func_003C1B80);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C2268);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct {
    char pad0[0x176];
    unsigned char f176;
    char pad177[0x180 - 0x177];
    unsigned int f180;
} G_2268;
typedef struct { int h; int pad[3]; } V_2268;
typedef struct {
    char pad0[0xE8C];
    V_2268 v[1];
    char padE9C[0x1AA0 - 0xE9C];
    int f1AA0;
    int f1AA4;
    int f1AA8;
    char pad1AAC;
    unsigned char f1AAD;
    char pad1AAE[0x1AD4 - 0x1AAE];
    int f1AD4;
    int f1AD8;
    char pad1ADC[0x1AF8 - 0x1ADC];
    int f1AF8;
    char pad1AFC[0x1B38 - 0x1AFC];
    int f1B38;
} H_2268;
extern volatile G_2268 D_0050A8E8_2268 __asm__("D_0050A8E8");
extern H_2268 D_0050AD00_2268 __asm__("D_0050AD00");
extern int D_00512B20_2268[] __asm__("D_00512B20");
extern void func_003B58D8_2268(void) __asm__("func_003B58D8");
extern void func_003B58A0_2268(void) __asm__("func_003B58A0");
extern void func_003B5E98_2268(int) __asm__("func_003B5E98");
extern void func_003C0B10_2268(int, int, int) __asm__("func_003C0B10");
extern void func_003C60E0_2268(void) __asm__("func_003C60E0");
extern void func_003C8018_2268(void) __asm__("func_003C8018");
extern void func_003CBC00_2268(int) __asm__("func_003CBC00");
extern int func_00423AA0_2268(int, int) __asm__("func_00423AA0");
extern void func_00423BB0_2268(int) __asm__("func_00423BB0");
extern void func_00423BF0_2268(int) __asm__("func_00423BF0");
extern void func_00423CA0_2268(int, void *) __asm__("func_00423CA0");
extern void func_00423DB0_2268(int) __asm__("func_00423DB0");
extern void func_00424880_2268(int) __asm__("func_00424880");
extern void func_004248E8_2268(int) __asm__("func_004248E8");
extern void func_0042AD08_2268(int) __asm__("func_0042AD08");

int func_003C2268(void) {
    int st[12];
    unsigned int t;
    int i;

    while (D_0050A8E8_2268.f176 != 0) {
        func_003B58D8_2268();
    }
    t = D_0050A8E8_2268.f180 + 10;
    while (D_0050A8E8_2268.f180 < t) {
        func_003C60E0_2268();
    }
    if (D_0050AD00_2268.f1AA8 >= 0) {
        func_00424880_2268(2);
        if (func_00423AA0_2268(2, D_0050AD00_2268.f1AA8) > 0) {
            func_004248E8_2268(2);
        }
    }
    func_003C0B10_2268(1, 0, 0);
    func_00423CA0_2268(D_00512B20_2268[0], st);
    if (st[0] == 0x10) {
        func_00423BB0_2268(D_00512B20_2268[0]);
    } else {
        func_00423BF0_2268(D_00512B20_2268[0]);
        func_00423BB0_2268(D_00512B20_2268[0]);
    }
    func_00423DB0_2268(D_0050AD00_2268.f1AA4);
    for (i = 0; i < 1; i++) {
        func_0042AD08_2268(D_0050AD00_2268.v[i].h);
    }
    func_003CBC00_2268(0);
    D_0050AD00_2268.f1AAD = 0;
    func_003B58A0_2268();
    if (D_0050AD00_2268.f1AD4 != 0) {
        func_003B5E98_2268(D_0050AD00_2268.f1AD4);
        D_0050AD00_2268.f1AD4 = 0;
        D_0050AD00_2268.f1AD8 = 0;
    }
    if (D_0050AD00_2268.f1AF8 != 0) {
        func_003B5E98_2268(D_0050AD00_2268.f1AF8);
        D_0050AD00_2268.f1AF8 = 0;
    }
    if (D_0050AD00_2268.f1B38 != 0) {
        func_003B5E98_2268(D_0050AD00_2268.f1B38);
        D_0050AD00_2268.f1B38 = 0;
    }
    func_003C8018_2268();
    func_003B5E98_2268(D_0050AD00_2268.f1AA0);
    func_003B58D8_2268();
    return 0;
}
#endif

void func_003C2438(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C2440);
#ifdef SKIP_ASM
struct E_2440 { char pad0[4]; short ids[15]; char pad22; unsigned char cnt; unsigned short flags; char pad26[0x8C - 0x26]; };
struct G_2440 { char pad0[0x2F]; unsigned char f2F; unsigned char f30; char pad31[0x49 - 0x31]; unsigned char f49; char pad4A[0x1F0 - 0x4A]; struct E_2440 *tab; };
struct H_2440 { char pad0[0xCB0]; char *tbl; };
extern struct G_2440 D_0050A8E8_2440 __asm__("D_0050A8E8");
extern struct H_2440 D_0050AD00_2440 __asm__("D_0050AD00");
extern void f_A550_2440(int) __asm__("func_003BA550");
extern void f_8468_2440(int) __asm__("func_003C8468");

int func_003C2440(int arg0) {
    struct E_2440 *e = &D_0050A8E8_2440.tab[arg0];
    int i, k;
    unsigned fl = e->flags;
    if (fl & 8) {
        for (i = 0; i < e->cnt; i++) {
            *(int *)(D_0050AD00_2440.tbl + (e->ids[i] << 3) + 0x20) = 0;
            f_A550_2440(e->ids[i]);
            if (D_0050A8E8_2440.f49 == 2) {
                k = e->ids[i] + 0x18;
                *(int *)(D_0050AD00_2440.tbl + (k << 3) + 0x20) = 0;
            }
        }
    } else if (fl & 0x100) {
        for (i = 0; i < e->cnt; i++) {
            *(int *)(D_0050AD00_2440.tbl + ((e->ids[i] - D_0050A8E8_2440.f30) << 4) + 0x1A0) = 0;
            f_A550_2440(e->ids[i]);
        }
    } else {
        for (i = 0; i < e->cnt; i++) {
            f_8468_2440(e->ids[i] - (D_0050A8E8_2440.f30 + D_0050A8E8_2440.f2F));
            f_A550_2440(e->ids[i]);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C25E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_25E0 {
    char pad00[0x4];
    short h[14];
    unsigned short f20;
    char pad22;
    unsigned char n;
    unsigned short flags;
    char pad26[0x8A - 0x26];
    unsigned short f8A;
};
struct G_25E0 {
    char pad000[0x2A];
    unsigned short f2A;
    unsigned short f2C;
    char pad02E;
    unsigned char f2F;
    unsigned char f30;
    char pad031[0x49 - 0x31];
    unsigned char f49;
    char pad04A[0x1F0 - 0x4A];
    struct E_25E0 *f1F0;
};
struct A8_25E0 {
    int a;
    short v;
    short b;
};
struct B16_25E0 {
    int a;
    short v;
    char pad[10];
};
struct T_25E0 {
    char pad[0x20];
    struct A8_25E0 a[48];
    struct B16_25E0 b[1];
};
struct H_25E0 {
    char pad[0xCB0];
    struct T_25E0 *tbl;
};
extern struct G_25E0 D_0050A8E8_25E0 __asm__("D_0050A8E8");
extern struct H_25E0 D_0050AD00_25E0 __asm__("D_0050AD00");
extern void func_003C8A88_25E0(int a, unsigned int v) __asm__("func_003C8A88");

int func_003C25E0(int idx) {
    struct E_25E0 *e = &D_0050A8E8_25E0.f1F0[idx];
    unsigned int v;
    int i;

    if (e->flags & 8) {
        v = (unsigned int)((e->f20 << 12) / 48000 * e->f8A) >> 12;
        if (v >= 0x4000) {
            v = 0x3FFF;
        }
        for (i = 0; i < e->n; i++) {
            D_0050AD00_25E0.tbl->a[e->h[i]].v = v;
            if (D_0050A8E8_25E0.f49 == 2) {
                D_0050AD00_25E0.tbl->a[e->h[i] + 0x18].v = v;
            }
        }
    } else if (e->flags & 0x100) {
        v = (unsigned int)((e->f20 << 12) / D_0050A8E8_25E0.f2C * e->f8A) >> 12;
        for (i = 0; i < e->n; i++) {
            D_0050AD00_25E0.tbl->b[e->h[i] - D_0050A8E8_25E0.f30].v = v;
        }
    } else {
        v = (unsigned int)((e->f20 << 12) / D_0050A8E8_25E0.f2A * e->f8A) >> 8;
        for (i = 0; i < e->n; i++) {
            func_003C8A88_25E0(e->h[i] - (D_0050A8E8_25E0.f30 + D_0050A8E8_25E0.f2F), v);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C27E0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Ch_27E0 {
    int pad0;
    short ids[15];
    char pad22;
    unsigned char n;
    unsigned short flags;
    char pad26[0x48 - 0x26];
    float vol;
    char pad4C[0x62 - 0x4C];
    short vals[1];
};
struct V_27E0 { char pad[0x1AC]; char v[1][16]; };
struct G_27E0 { char pad[0x2F]; unsigned char base2; unsigned char base; char pad31[0x49 - 0x31]; unsigned char mode; char pad4A[0x1F0 - 0x4A]; struct Ch_27E0 *chans; };
struct A_27E0 { char pad[0xCB0]; long *mask; };
extern struct G_27E0 D_0050A8E8_27E0 __asm__("D_0050A8E8");
extern struct A_27E0 D_0050AD00_27E0 __asm__("D_0050AD00");
extern void f_8598_27E0(int, int, float) __asm__("func_003C8598");

int func_003C27E0(int id, int k) {
    struct Ch_27E0 *ch;
    int i, v;
    float f;

    ch = (struct Ch_27E0 *)((char *)D_0050A8E8_27E0.chans + id * 0x8C);
    if (ch->flags & 8) {
        for (i = 0; i < ch->n; i++) {
            if (ch->vals[0] != 0) {
                *D_0050AD00_27E0.mask |= 1L << ch->ids[i];
            } else {
                *D_0050AD00_27E0.mask &= ~(1L << ch->ids[i]);
            }
            if (D_0050A8E8_27E0.mode == 2) {
                if (ch->vals[0] != 0) {
                    *D_0050AD00_27E0.mask |= 1L << (ch->ids[i] + 0x18);
                } else {
                    *D_0050AD00_27E0.mask &= ~(1L << (ch->ids[i] + 0x18));
                }
            }
        }
    } else if (ch->flags & 0x100) {
        v = ch->vol * ch->vals[k] * 0.003875850699841976f;
        for (i = 0; i < ch->n; i++) {
            ((struct V_27E0 *)D_0050AD00_27E0.mask)->v[ch->ids[i] - D_0050A8E8_27E0.base][k] = v;
        }
    } else {
        f = ch->vol * ch->vals[k] / 32767.0f;
        for (i = 0; i < ch->n; i++) {
            f_8598_27E0(ch->ids[i] - (D_0050A8E8_27E0.base + D_0050A8E8_27E0.base2), k, f);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C2A50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Ch_2A50 {
    int pad0;
    short ids[15];
    char pad22;
    unsigned char n;
    unsigned short flags;
    char pad26[0x48 - 0x26];
    float vol;
    char pad4C[0x5F - 0x4C];
    signed char b5F;
    char pad60[0x8C - 0x60];
};
struct G_2A50 {
    char pad0[0x2F];
    unsigned char base2;
    unsigned char base;
    char pad31[0x47 - 0x31];
    unsigned char b47;
    unsigned char b48;
    unsigned char mode;
    char pad4A[0x1F0 - 0x4A];
    struct Ch_2A50 *chans;
};
struct W8_2A50 { char pad[6]; signed char l; signed char r; };
struct W16_2A50 { char pad[6]; signed char c[10]; };
struct T_2A50 {
    char pad0[0x20];
    struct W8_2A50 a[48];
    struct W16_2A50 b[1];
};
struct Spk_2A50 { float p[5]; char pad14[0x20 - 0x14]; };
struct A_2A50 {
    char pad0[0xCB0];
    struct T_2A50 *tbl;
    char padCB4[0xE98 - 0xCB4];
    struct Spk_2A50 spk[1];
};
extern struct G_2A50 D_0050A8E8_2A50 __asm__("D_0050A8E8");
extern struct A_2A50 D_0050AD00_2A50 __asm__("D_0050AD00");
extern struct Spk_2A50 D_0050BB98_2A50[] __asm__("D_0050BB98");
extern void f8560_2A50(int, int, float) __asm__("func_003C8560");

void func_003C2A50(int id) {
    struct Ch_2A50 *ch;
    float sc;
    int i;
    int j;
    int m;

    ch = (struct Ch_2A50 *)((char *)D_0050A8E8_2A50.chans + id * 0x8C);
    if (ch->flags & 8) {
        for (i = 0; i < ch->n; i++) {
            if (D_0050A8E8_2A50.mode != 2) {
                D_0050AD00_2A50.tbl->a[ch->ids[i]].l = D_0050AD00_2A50.spk[ch->ids[i]].p[1] * ch->vol * 127.0f;
                D_0050AD00_2A50.tbl->a[ch->ids[i]].r = D_0050AD00_2A50.spk[ch->ids[i]].p[0] * ch->vol * 127.0f;
            } else {
                if (D_0050A8E8_2A50.b47 == 4) {
                    D_0050AD00_2A50.tbl->a[ch->ids[i]].l = D_0050AD00_2A50.spk[ch->ids[i]].p[3] * ch->vol * 127.0f;
                    D_0050AD00_2A50.tbl->a[ch->ids[i]].r = D_0050AD00_2A50.spk[ch->ids[i]].p[0] * ch->vol * 127.0f;
                    D_0050AD00_2A50.tbl->a[ch->ids[i] + 0x18].l = D_0050AD00_2A50.spk[ch->ids[i]].p[2] * ch->vol * 127.0f;
                    D_0050AD00_2A50.tbl->a[ch->ids[i] + 0x18].r = D_0050AD00_2A50.spk[ch->ids[i]].p[1] * ch->vol * 127.0f;
                } else {
                    D_0050AD00_2A50.tbl->a[ch->ids[i]].l = D_0050AD00_2A50.spk[ch->ids[i]].p[4] * ch->vol * 127.0f;
                    D_0050AD00_2A50.tbl->a[ch->ids[i]].r = D_0050AD00_2A50.spk[ch->ids[i]].p[1] * ch->vol * 127.0f;
                    D_0050AD00_2A50.tbl->a[ch->ids[i] + 0x18].l = D_0050AD00_2A50.spk[ch->ids[i]].p[3] * ch->vol * 127.0f;
                    D_0050AD00_2A50.tbl->a[ch->ids[i] + 0x18].r = D_0050AD00_2A50.spk[ch->ids[i]].p[2] * ch->vol * 127.0f;
                }
            }
        }
    } else if (ch->flags & 0x100) {
        m = D_0050A8E8_2A50.b47 + D_0050A8E8_2A50.b48;
        sc = ch->vol * (float)ch->b5F * 0.0078740157186985016f;
        for (i = 0; i < ch->n; i++) {
            for (j = 0; j < m; j++) {
                D_0050AD00_2A50.tbl->b[ch->ids[i] - D_0050A8E8_2A50.base].c[j] = sc * D_0050AD00_2A50.spk[ch->ids[i]].p[j] * 127.0f;
            }
        }
    } else {
        m = D_0050A8E8_2A50.b47 + D_0050A8E8_2A50.b48;
        sc = ch->vol * (float)ch->b5F * 0.0078740157186985016f;
        for (i = 0; i < ch->n; i++) {
            for (j = 0; j < m; j++) {
                f8560_2A50(ch->ids[i] - (D_0050A8E8_2A50.base + D_0050A8E8_2A50.base2), j, sc * D_0050BB98_2A50[ch->ids[i]].p[j]);
            }
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C2EC8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3010);
#ifdef SKIP_ASM
extern void func_003C8B40(int, int);
struct G_3010 { char pad[0x2F]; unsigned char a; unsigned char b; char pad2[0x1BF]; char *tab; };
struct E_3010 { char pad[4]; short v[15]; char padb; unsigned char cnt; unsigned short flags; };
extern struct G_3010 D_0050A8E8_3010[] __asm__("D_0050A8E8");

int func_003C3010(int arg0, int arg1) {
    struct E_3010 *e;
    int i;
    e = (struct E_3010 *)(D_0050A8E8_3010[0].tab + arg0 * 0x8C);
    if (e->flags & 4) {
        for (i = 0; i < e->cnt; i++)
            func_003C8B40(e->v[i] - (D_0050A8E8_3010[0].b + D_0050A8E8_3010[0].a), arg1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C30C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8B80(int, int);
struct G_30C8 { char pad[0x2F]; unsigned char a; unsigned char b; char pad2[0x1BF]; char *tab; };
struct E_30C8 { char pad[4]; short v[15]; char padb; unsigned char cnt; unsigned short flags; };
extern struct G_30C8 D_0050A8E8_30C8[] __asm__("D_0050A8E8");

void func_003C30C8(int arg0, int arg1) {
    struct E_30C8 *e;
    int i;
    e = (struct E_30C8 *)(D_0050A8E8_30C8[0].tab + arg0 * 0x8C);
    if (e->flags & 4) {
        for (i = 0; i < e->cnt; i++)
            func_003C8B80(e->v[i] - (D_0050A8E8_30C8[0].b + D_0050A8E8_30C8[0].a), arg1);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C3178);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3250);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8C30(int, int);
struct G_3250 { char pad[0x2F]; unsigned char a; unsigned char b; char pad2[0x1BF]; char *tab; };
struct E_3250 { char pad[4]; short v[15]; char padb; unsigned char cnt; unsigned short flags; };
extern struct G_3250 D_0050A8E8_3250[] __asm__("D_0050A8E8");

void func_003C3250(int arg0, int arg1) {
    struct E_3250 *e;
    int i;
    e = (struct E_3250 *)(D_0050A8E8_3250[0].tab + arg0 * 0x8C);
    if (e->flags & 4) {
        for (i = 0; i < e->cnt; i++)
            func_003C8C30(e->v[i] - (D_0050A8E8_3250[0].b + D_0050A8E8_3250[0].a), arg1);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3300);
#ifdef SKIP_ASM
struct G_3300 {
    char pad[0x1B10];
    volatile int f1B10;
    volatile int f1B14;
    volatile int f1B18;
};
struct H_3300 { int f0; int f4; int f8; };
extern struct G_3300 D_0050AD00_3300 __asm__("D_0050AD00");
extern int D_0050ACE0_3300[] __asm__("D_0050ACE0");
extern int func_00423DA0_3300(int *) __asm__("func_00423DA0");

void func_003C3300(void) {
    D_0050ACE0_3300[1] = 0x14;
    D_0050AD00_3300.f1B14 = -1;
    D_0050ACE0_3300[2] = 1;
    D_0050AD00_3300.f1B18 = 0;
    D_0050AD00_3300.f1B10 = func_00423DA0_3300(D_0050ACE0_3300);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3358);
#ifdef SKIP_ASM
extern void func_00423DB0_3358(int) __asm__("func_00423DB0");
extern int D_0050AD00_3358[] __asm__("D_0050AD00");
void func_003C3358(void) {
    int *p = D_0050AD00_3358;
    func_00423DB0_3358(((volatile int *)p)[0x6C4]);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C3380);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C33E0);
#ifdef SKIP_ASM
struct G_33E0 {
    char pad[0x1B10];
    volatile int f1B10;
    volatile int f1B14;
    volatile int f1B18;
};
extern struct G_33E0 D_0050AD00_33E0 __asm__("D_0050AD00");
extern int func_00423C90_33E0(void) __asm__("func_00423C90");
extern void func_00423DC0_33E0(int) __asm__("func_00423DC0");

void func_003C33E0(void) {
    int r = func_00423C90_33E0();
    if (D_0050AD00_33E0.f1B14 == r) {
        D_0050AD00_33E0.f1B18--;
        if (D_0050AD00_33E0.f1B18 == 0) {
            D_0050AD00_33E0.f1B14 = -1;
        }
    }
    if (D_0050AD00_33E0.f1B18 <= 0) {
        func_00423DC0_33E0(D_0050AD00_33E0.f1B10);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C3450);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_0B10_3450(int, void *, int) __asm__("func_003C0B10");
extern int f_72F8_3450(void *, int) __asm__("func_003C72F8");
extern char D_0050AAF4_3450[] __asm__("D_0050AAF4");
struct G_3450 { char pad[0xF]; char c; void *fn; };
extern struct G_3450 D_00515B40_3450[] __asm__("D_00515B40");
extern char D_00515B4F_3450[] __asm__("D_00515B4F");
extern char D_0044DD70_3450[] __asm__("D_0044DD70");
extern char f_C878_3450[] __asm__("func_003CC878");

void func_003C3450(int arg0) {
    char *b = D_0050AAF4_3450;
    char *t = b - 0x20C;
    char *q;
    if (*(unsigned char *)(t + 0x42) != 0) {
        D_00515B40_3450[0].fn = f_C878_3450;
        D_00515B40_3450[0].c = 1;
    }
    if (arg0 != 1) {
        f_0B10_3450(2, D_0044DD70_3450, 4);
        if (*(unsigned char *)(t + 0x42) != 0)
            D_00515B4F_3450[0] = 0;
    } else {
        q = *(char **)(b + 4);
        if (*(unsigned char *)(t + 0x42) != 0)
            D_00515B4F_3450[0] = arg0;
        f_0B10_3450(2, q, f_72F8_3450(q + 4, 4));
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3500);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044DD48_3500[] __asm__("D_0044DD48");
struct A_3500 {
    char pad0[0xCB0];
    char *p;
    char pad1[0x1A9E - 0xCB4];
    short s;
};
struct B_3500 {
    char pad0[0x224];
    unsigned char a;
    char pad1[3];
    unsigned char b;
};
extern struct A_3500 D_0050AD00_3500 __asm__("D_0050AD00");
extern struct B_3500 D_0050A8E8_3500 __asm__("D_0050A8E8");

void func_003C3500(unsigned a) {
    unsigned v = a;
    if (a < 2) {
        v = 0;
    } else if (a == 5) {
        v = 1;
    } else if (a == 10) {
        v = 2;
    } else if (a == 20) {
        v = 3;
    } else if (a == 30) {
        v = 4;
    } else if (a == 40) {
        v = 5;
    } else if (a == 50) {
        v = 6;
    } else if (a == 100) {
        v = 9;
    } else if (a == 110) {
        v = 8;
    } else if (a == 120) {
        v = 7;
    }
    D_0050AD00_3500.s = (0x200000 - D_0044DD48_3500[v]) >> 6;
    D_0050AD00_3500.p[0x10] = v;
    D_0050AD00_3500.p[0x11] = D_0050A8E8_3500.a;
    D_0050AD00_3500.p[0x12] = D_0050A8E8_3500.b;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C35F8);
#ifdef SKIP_ASM
struct G_35F8 { char pad[0x2A]; unsigned short u2A; char pad2[0x42 - 0x2C]; unsigned char c42; char pad3[0x1F8 - 0x43]; short s1F8; char pad4[2]; int f1FC; };
extern struct G_35F8 D_0050A8E8_35F8 __asm__("D_0050A8E8");
extern short D_0050AB08_35F8 __asm__("D_0050AB08");
extern short D_0050AAF4_35F8 __asm__("D_0050AAF4");
extern int D_00515B50_35F8 __asm__("D_00515B50");
extern void func_003CC848_35F8(void) __asm__("func_003CC848");
extern void func_003CC630_35F8(int, int) __asm__("func_003CC630");

void func_003C35F8(int arg0) {
    func_003B58A0();
    if (arg0 == 8) {
        func_003C3500(D_0050AB08_35F8);
    } else if (arg0 == 0x100) {
        func_003C3450(D_0050AAF4_35F8);
    } else if (arg0 == 4) {
        if (D_0050A8E8_35F8.s1F8 != 1 || D_0050A8E8_35F8.c42 != 0) {
            if (D_0050A8E8_35F8.c42 == 0) {
                D_00515B50_35F8 = 0;
            }
            func_003CC848_35F8();
        } else {
            func_003CC630_35F8(D_0050A8E8_35F8.u2A, D_0050A8E8_35F8.f1FC);
        }
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C36A8);
#ifdef SKIP_ASM
extern void func_003C35F8(int);

int func_003C36A8(int a, int b) {
    func_003C35F8(b);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C36C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct O_36C8 { char pad[0x14]; short x; short y; };
struct G_36C8 { char pad[0xCB0]; struct O_36C8 *o; };
extern struct G_36C8 D_0050AD00_36C8[] __asm__("D_0050AD00");
extern float D_0050AB08_36C8[] __asm__("D_0050AB08");

void func_003C36C8(int arg0, int flags) {
    struct G_36C8 *g = &D_0050AD00_36C8[0];
    if (g->o != 0 && (flags & 8)) {
        g->o->x = (int)(D_0050AB08_36C8[3] * 32767.0f);
        g->o->y = (int)(D_0050AB08_36C8[4] * 32767.0f);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3728);
#ifdef SKIP_ASM
extern short D_0044DD78[];
void func_003C3728(unsigned x, float* out)
{
    short* p = D_0044DD78;
    int i;
    p = (short*)((char*)p + ((x >> 6) & 0x3FC));
    for (i = 0; i < 2; i++)
        out[i] = p[i] / 32767.0f;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C3780);

INCLUDE_ASM("ealib/seg_2B4578", func_003C38E0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3EA8);
#ifdef SKIP_ASM
int func_003C3EA8(void *arg0, int arg1, int *arg2) {
    if (*arg2 == 0) {
        *arg2 = (*(int *)((char*)(arg0) + (0x68)));
    }
    *(*(int **)((char*)(arg0) + (0x64))) = arg1 + ((*(int *)((char*)(arg0) + (0x68))) - *arg2);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3EE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V_3EE0 {
    char pad0[2];
    signed char b2;
    char pad3[0x13 - 3];
    unsigned char b13;
    char pad14[0x5C - 0x14];
    int x5C;
    int x60;
    int *p64;
    int a68[6];
    int a80[6];
    int a98[6];
};
struct Ch_3EE0 {
    int pad0;
    short ids[15];
    char pad22;
    unsigned char n;
    unsigned short flags;
    char pad26[0x8C - 0x26];
};
struct G_3EE0 {
    char pad0[0x2F];
    unsigned char base2;
    unsigned char base;
    char pad31[0x49 - 0x31];
    unsigned char mode;
    char pad4A[0x1F0 - 0x4A];
    struct Ch_3EE0 *chans;
};
struct W8_3EE0 { int w; int pad; };
struct W16_3EE0 { int w; char pad[12]; };
struct T_3EE0 {
    char pad0[0x20];
    struct W8_3EE0 a[48];
    struct W16_3EE0 b[1];
};
struct E32_3EE0 { int w; char pad[28]; };
struct A_3EE0 {
    char pad0[0x840];
    struct W8_3EE0 x840[48];
    struct W8_3EE0 x9C0[(0xCB0 - 0x9C0) / 8];
    struct T_3EE0 *tbl;
    char padCB4[0xEB0 - 0xCB4];
    struct E32_3EE0 e[96];
    char pad1AB0[0x1AB8 - 0x1AB0];
    int x1AB8;
};
extern struct G_3EE0 D_0050A8E8_3EE0 __asm__("D_0050A8E8");
extern struct A_3EE0 D_0050AD00_3EE0 __asm__("D_0050AD00");
extern void f2EC8_3EE0(int) __asm__("func_003C2EC8");
extern void f38E0_3EE0(int) __asm__("func_003C38E0");
extern void f3178_3EE0(int, int) __asm__("func_003C3178");
extern void f83A0_3EE0(int) __asm__("func_003C83A0");
extern void f8158_3EE0(int, int, int, int, int, int, int, int, int, int, int, int, int, int) __asm__("func_003C8158");

int func_003C3EE0(struct V_3EE0 *v, int base, int id, int p3, int p4, int p5, int p6) {
    struct Ch_3EE0 *ch;
    int i;

    ch = (struct Ch_3EE0 *)((char *)D_0050A8E8_3EE0.chans + id * 0x8C);
    if (ch->flags & 8) {
        func_003C25E0(id);
        f38E0_3EE0(id);
        f2EC8_3EE0(id);
        func_003C27E0(id, 0);
        for (i = 0; i < ch->n; i++) {
            D_0050AD00_3EE0.e[ch->ids[i]].w = *v->p64 + (v->a68[i] - v->a68[0]);
            D_0050AD00_3EE0.x1AB8 += 0x800000;
            D_0050AD00_3EE0.tbl->a[ch->ids[i]].w = D_0050AD00_3EE0.e[ch->ids[i]].w | D_0050AD00_3EE0.x1AB8;
            D_0050AD00_3EE0.x840[ch->ids[i]].w = D_0050AD00_3EE0.e[ch->ids[i]].w;
            if (D_0050A8E8_3EE0.mode == 2) {
                D_0050AD00_3EE0.tbl->a[ch->ids[i] + 0x18].w = D_0050AD00_3EE0.e[ch->ids[i]].w | D_0050AD00_3EE0.x1AB8;
                D_0050AD00_3EE0.x840[ch->ids[i] + 0x18].w = D_0050AD00_3EE0.e[ch->ids[i]].w;
            }
        }
    } else if (ch->flags & 0x100) {
        func_003C25E0(id);
        f38E0_3EE0(id);
        func_003C27E0(id, 0);
        for (i = 0; i < ch->n; i++) {
            D_0050AD00_3EE0.e[ch->ids[i]].w = *v->p64 + (v->a68[i] - v->a68[0]);
            D_0050AD00_3EE0.x1AB8 += 0x800000;
            D_0050AD00_3EE0.tbl->b[ch->ids[i] - D_0050A8E8_3EE0.base].w = D_0050AD00_3EE0.e[ch->ids[i]].w | D_0050AD00_3EE0.x1AB8;
            D_0050AD00_3EE0.x9C0[ch->ids[i] - D_0050A8E8_3EE0.base].w = 0;
        }
    } else {
        for (i = 0; i < ch->n; i++) {
            f8158_3EE0(ch->ids[i] - (D_0050A8E8_3EE0.base + D_0050A8E8_3EE0.base2), v->b13, 1,
                       base + v->a68[i], base + v->a68[0] + v->a80[i], v->a98[i], ch->n, *(int *)((char *)ch + 0x14),
                       v->x5C, v->x60, 0, 0, v->b2, i);
        }
        func_003C25E0(ch->ids[0]);
        f38E0_3EE0(ch->ids[0]);
        func_003C27E0(ch->ids[0], 0);
        func_003C3010(ch->ids[0], p3);
        func_003C30C8(ch->ids[0], p4);
        f3178_3EE0(ch->ids[0], p5);
        func_003C3250(ch->ids[0], p6);
        for (i = 0; i < ch->n; i++) {
            f83A0_3EE0(ch->ids[i] - (D_0050A8E8_3EE0.base + D_0050A8E8_3EE0.base2));
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C42D8);
#ifdef SKIP_ASM
extern void func_003C4788(int, int, int, int, int);

void func_003C42D8(int a, int b, int c, int d) {
    func_003C4788(a, b, c, d, 10);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C42F8);
#ifdef SKIP_ASM
extern void func_003C4898();

void func_003C42F8(void) {
    func_003C4898();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C4318);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C43C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_43C0 { int a, b, c, d; };
extern void func_00424020(int);
extern void func_00424050(int);
extern int func_00424140(int);
extern int func_00424150(int);
extern int func_00424160(void *, int);
extern int func_00424170(void *, int);
extern int D_0044E178_43C0[] __asm__("D_0044E178");

void func_003C43C0(int arg0, int arg1, int arg2, int arg3) {
    struct S_43C0 s;
    s.a = arg0;
    s.c = arg2;
    s.b = arg1;
    s.d = 0;
    if (arg3 != 0) {
        func_00424050(0);
        while (func_00424150(D_0044E178_43C0[0]) >= 0) {}
        D_0044E178_43C0[0] = func_00424170(&s, 1);
    } else {
        func_00424020(0);
        while (func_00424140(D_0044E178_43C0[0]) >= 0) {}
        D_0044E178_43C0[0] = func_00424160(&s, 1);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4450);
#ifdef SKIP_ASM
struct Ent_4450 { unsigned key; int f4; int f8; unsigned short hC; unsigned char bE; char pF; };
struct Hd_4450 { char pad0[0xCC0]; volatile unsigned char cnt; volatile unsigned char sel; char f1CC2; char pad1CC3; int f1CC4; char pad1CC8[0xE8C - 0xCC8]; int fE8C; };
struct Dst_4450 { char b0; char pad1[0xF]; int f10; int f14; int f18; int f1C; unsigned short h20; short h22; };
extern struct Ent_4450 D_0050B9C8_4450[] __asm__("D_0050B9C8");
extern struct Hd_4450 D_0050AD00_4450 __asm__("D_0050AD00");
extern struct { char pad[0x180]; int f180; } D_0050A8E8_4450 __asm__("D_0050A8E8");
extern struct Dst_4450 D_00515780_4450 __asm__("D_00515780");
extern void f43C0_4450(int, int, int, int) __asm__("func_003C43C0");
extern void f61B0_4450(int, void *, int, int, int, int) __asm__("func_004261B0");
extern void f61F0_4450(int, void *, int, int, int, int) __asm__("func_004261F0");

void func_003C4450(int arg0) {
    struct Ent_4450 *t0 = D_0050B9C8_4450;
    struct Hd_4450 *h = (struct Hd_4450 *)((char *)t0 - 0xCC8);
    struct Ent_4450 *e = t0;
    int cnt = 0;
    unsigned best = 0xFFFFFFFF;
    unsigned char pri = 0;
    int i;
    struct Ent_4450 *p;
    signed char c;
    i = 0;
    do {
        if (e->key != 0) {
            cnt++;
            if (pri < e->bE) {
                h->sel = i;
                best = e->key;
                pri = e->bE;
            } else if (e->bE == pri && e->key < best) {
                h->sel = i;
                best = e->key;
            }
            c = h->cnt;
            if (cnt >= c) break;
        }
        i++;
        e++;
    } while (i < 0x1C);
    D_0050AD00_4450.f1CC4 = D_0050A8E8_4450.f180;
    p = &((struct Ent_4450 *)((char *)&D_0050AD00_4450 + 0xCC8))[(signed char)D_0050AD00_4450.sel];
    f43C0_4450(p->f4, D_0050AD00_4450.fE8C, p->hC, arg0);
    D_0050AD00_4450.f1CC2 = 1;
    D_00515780_4450.b0 = 0x30;
    D_00515780_4450.f10 = 1;
    D_00515780_4450.f14 = p->key;
    D_00515780_4450.f18 = D_0050AD00_4450.fE8C;
    D_00515780_4450.f1C = p->f8;
    D_00515780_4450.h20 = p->hC;
    D_00515780_4450.h22 = p->bE;
    if (arg0 != 0) {
        f61F0_4450(0, &D_00515780_4450, 0x30, 0, 0, 0);
        return;
    }
    f61B0_4450(0, &D_00515780_4450, 0x30, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C45E8);
#ifdef SKIP_ASM
extern volatile unsigned char D_0050AD00_45E8[] __asm__("D_0050AD00");
extern void func_003C4450_45E8(int) __asm__("func_003C4450");
void func_003C45E8(int arg0) {
    int s;
    if (arg0 == 0) {
        do {
            DI_2B45();
            SYNCP_2B45();
            MFC0_STATUS_2B45(s);
        } while (s & 0x10000);
    }
    if (D_0050AD00_45E8[0xCC2] == 0 && (D_0050AD00_45E8[0xCC0] << 24) > 0) {
        func_003C4450_45E8(arg0);
    }
    if (arg0 == 0) {
        EI_2B45();
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C4668);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C4788);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C45E8_4788(int) __asm__("func_003C45E8");
extern int func_003C4668_4788(int, int, int, int, int) __asm__("func_003C4668");
extern volatile unsigned char D_0050AD00_4788[] __asm__("D_0050AD00");
int func_003C4788_4788(int, int, int, int, int) __asm__("func_003C4788");

int func_003C4788_4788(int a0, int a1, int a2, int a3, int a4) {
    int r = 0;
    int t;
    int c;
    while (a3 > 0) {
        t = 0x1000;
        if (!(a3 > 0xFFF)) t = a3;
        c = D_0050AD00_4788[0xCC0];
        while (0x1C - (signed char)c < 5) {
            func_003C45E8_4788(0);
            c = D_0050AD00_4788[0xCC0];
        }
        r = func_003C4668_4788(a0, a1, a2, t, a4);
        a1 += t;
        a2 += t;
        a3 -= t;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4898);
#ifdef SKIP_ASM
struct Ent_4898 { int key; int val; int pad[2]; };
struct D_4898 { char pad[0xCC0]; volatile unsigned char count; char pad2[3]; int f4; struct Ent_4898 e[28]; };
extern struct D_4898 D_0050AD00_4898 __asm__("D_0050AD00");
extern struct { char pad[0x180]; unsigned int f180; } D_0050A8E8_4898 __asm__("D_0050A8E8");
extern void func_003C4450(int);

int func_003C4898_4898(int) __asm__("func_003C4898");
int func_003C4898_4898(int key) {
    int i;
    if ((signed char)D_0050AD00_4898.count <= 0) return 1;
    for (i = 0; i < 28; i++) {
        if (D_0050AD00_4898.e[i].key == key) {
            if (D_0050AD00_4898.f4 + 500 < D_0050A8E8_4898.f180) {
                func_003C4450(0);
            }
            return 0;
        }
    }
    return 1;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C4918);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4978);
#ifdef SKIP_ASM
void func_003C4978(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D400 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
    *(volatile int *)0x1000D410 = arg0;
    *(volatile int *)0x1000D480 = arg1;
    *(volatile int *)0x1000D420 = arg2;
    *(volatile int *)0x1000D400 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D400 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4A38);
#ifdef SKIP_ASM
void func_003C4A38(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D000 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
    *(volatile int *)0x1000D010 = arg1;
    *(volatile int *)0x1000D080 = arg0;
    *(volatile int *)0x1000D020 = arg2;
    *(volatile int *)0x1000D000 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D000 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4AF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050AD00_4AF8[] __asm__("D_0050AD00");

void func_003C4AF8(int *arg0, int *arg1) {
    char *b = D_0050AD00_4AF8;
    int temp_4;
    int temp_6;
    int lo = *(unsigned short *)(b + 0x1A9A);

    temp_6 = *arg0;
    if (temp_6 < lo) {
        *arg0 = lo;
        *arg1 -= lo - temp_6;
    }
    if ((int)*(unsigned short *)(b + 0x1A9C) < *arg0 + *arg1) {
        *arg1 = *(unsigned short *)(b + 0x1A9C) - *arg0;
    }
    temp_4 = *arg0;
    if ((int)*(unsigned short *)(b + 0x1A9E) < temp_4 + *arg1) {
        *arg1 = *(unsigned short *)(b + 0x1A9E) - temp_4;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C4B70);

INCLUDE_ASM("ealib/seg_2B4578", func_003C4D78);

INCLUDE_ASM("ealib/seg_2B4578", func_003C4E50);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4EC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_4EC8 { unsigned short a; unsigned short b; };
struct G_4EC8 { char pad[0x1A98]; unsigned short n; unsigned short lo; unsigned short hi; unsigned short max; struct S_4EC8 *segs; };
extern struct G_4EC8 D_0050AD00_4EC8 __asm__("D_0050AD00");
int f_4EC8(int *out) __asm__("func_003C4EC8");
int f_4EC8(int *out) {
    int start;
    int len;
    int best = 0;
    int i;
    struct S_4EC8 *seg;
    struct S_4EC8 *prev;

    if (D_0050AD00_4EC8.n == 0) {
        start = D_0050AD00_4EC8.lo;
        len = D_0050AD00_4EC8.hi - D_0050AD00_4EC8.lo;
        func_003C4AF8(&start, &len);
        best = len;
        *out = start;
    } else {
        for (i = 0; i < D_0050AD00_4EC8.n; i++) {
            seg = &D_0050AD00_4EC8.segs[i];
            if (i == 0) {
                start = seg->a;
                len = seg->a - 0x141;
                func_003C4AF8(&start, &len);
                if (best < len) {
                    best = len;
                    *out = start;
                }
            } else {
                prev = &D_0050AD00_4EC8.segs[i - 1];
                start = prev->a + prev->b;
                len = seg->a - start;
                func_003C4AF8(&start, &len);
                if (best < len) {
                    best = len;
                    *out = start;
                }
            }
        }
        prev = &D_0050AD00_4EC8.segs[i - 1];
        start = prev->a + prev->b;
        len = D_0050AD00_4EC8.max - start;
        func_003C4AF8(&start, &len);
        if (best < len) {
            best = len;
            *out = start;
        }
    }
    *out <<= 6;
    return best << 6;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5068);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8E28_5068(int, int, int) __asm__("func_003C8E28");
struct G_5068 { char pad[0x2F]; unsigned char a; unsigned char b; char pad2[0x1BF]; char *tab; };
struct E_5068 { char pad[4]; short v[15]; char padb; unsigned char cnt; unsigned short flags; };
extern struct G_5068 D_0050A8E8_5068[] __asm__("D_0050A8E8");

int func_003C5068(int arg0, int arg1) {
    struct E_5068 *e;
    int i;
    e = (struct E_5068 *)(D_0050A8E8_5068[0].tab + arg0 * 0x8C);
    if (e->flags & 4) {
        for (i = 0; i < e->cnt; i++)
            func_003C8E28_5068(e->v[i] - (D_0050A8E8_5068[0].b + D_0050A8E8_5068[0].a), i, arg1);
        return 0;
    }
    return -7;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5128);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8EC0(int, int);
struct G_5128 { char pad[0x2F]; unsigned char a; unsigned char b; char pad2[0x1BF]; char *tab; };
struct E_5128 { char pad[4]; short v[15]; char padb; unsigned char cnt; unsigned short flags; };
extern struct G_5128 D_0050A8E8_5128[] __asm__("D_0050A8E8");

int func_003C5128(int arg0, int arg1) {
    struct E_5128 *e;
    int i;
    e = (struct E_5128 *)(D_0050A8E8_5128[0].tab + arg0 * 0x8C);
    if (e->flags & 4) {
        for (i = 0; i < e->cnt; i++)
            func_003C8EC0(e->v[i] - (D_0050A8E8_5128[0].b + D_0050A8E8_5128[0].a), arg1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C51E0);
#ifdef SKIP_ASM
int func_003C51E0(void) {
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C51E8);

INCLUDE_ASM("ealib/seg_2B4578", func_003C52C8);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C52F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_52F8(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_52F8(void *) __asm__("func_003B4FC0");

int func_003C52F8(int arg0) {
    char sp[0xE0];
    func_003B4DD8_52F8(sp);
    *(short *)(sp + 0x28) = arg0;
    func_003B4FC0_52F8(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5330);
#ifdef SKIP_ASM
extern void func_003B4DD8(void *);

int func_003C5330(int *arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *arg0 = *(unsigned short *)(sp + 0x28);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5368);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_5368(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5368(void *) __asm__("func_003B4FC0");

int func_003C5368(int arg0) {
    char sp[0xE0];
    func_003B4DD8_5368(sp);
    *(signed char *)(sp + 0x46) = arg0;
    func_003B4FC0_5368(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C53A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_53A0(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_53A0(void *) __asm__("func_003B4FC0");

int func_003C53A0(int arg0) {
    char sp[0xE0];
    func_003B4DD8_53A0(sp);
    *(signed char *)(sp + 0x3C) = arg0;
    func_003B4FC0_53A0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C53D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_53D8(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_53D8(void *) __asm__("func_003B4FC0");

int func_003C53D8(int arg0) {
    char sp[0xE0];
    func_003B4DD8_53D8(sp);
    *(int *)(sp + 0x24) = arg0;
    func_003B4FC0_53D8(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5410);
#ifdef SKIP_ASM
extern void func_003B4FC0(void *);

int func_003C5410(float f) {
    char buf[0xE0];

    if (f >= 0.0f) {
        f = 1000.0f / f;
    }
    func_003B4DD8(buf);
    *(float *)(buf + 0x34) = f;
    func_003B4FC0(buf);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5468);
#ifdef SKIP_ASM
int func_003C5468(float *a0) {
    char buf[0xE0];
    float f;

    func_003B4DD8(buf);
    f = *(float *)(buf + 0x34);
    *a0 = f;
    if (f >= 0.0f) {
        *a0 = 1000.0f / f;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C54C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003B4DD8_i(void *) __asm__("func_003B4DD8");
int func_003C54C0(unsigned int kind, int *out) {
    unsigned char info[0xE0];
    *out = 0;
    func_003B4DD8_i(info);
    switch (kind) {
    case 1:
        if (info[5] >= 2U) {
            *out = 1;
        }
        break;
    case 0:
    case 4:
    case 5:
    case 8:
        *out = 1;
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5538);
#ifdef SKIP_ASM
extern char D_004958C8[];
extern char D_004958D0[];
extern char D_004958D8[];
extern char D_004958E0[];
extern char D_004958E8[];
extern char D_004958F0[];
extern char D_004958F8[];
extern char D_00495910[];
extern char D_00495920[];

int func_003C5538(unsigned int kind, char **out) {
    switch (kind) {
    case 0:
        *out = D_004958C8;
        break;
    case 1:
        *out = D_004958D0;
        break;
    case 2:
        *out = D_004958D8;
        break;
    case 3:
        *out = D_004958E0;
        break;
    case 4:
        *out = D_004958E8;
        break;
    case 5:
        *out = D_004958F0;
        break;
    case 6:
        *out = D_004958F8;
        break;
    case 7:
        *out = D_00495910;
        break;
    case 8:
        *out = D_00495920;
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5600);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C4_5600[] __asm__("D_0044E1C4");
int func_003C54C0_5600(int, int *) __asm__("func_003C54C0");

int func_003C5600(int arg0) {
    int buf[4];
    func_003C54C0_5600(arg0, buf);
    if (buf[0] == 0) {
        return -5;
    }
    D_0044E1C4_5600[0] = arg0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5648);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C4_5648[4] __asm__("D_0044E1C4");

int func_003C5648(int *arg0) {
    *arg0 = D_0044E1C4_5648[0];
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5660);
#ifdef SKIP_ASM
extern int func_003B4DD8_5660(void *) __asm__("func_003B4DD8");

int func_003C5660(int mode, int rate, int *out) {
    char sp[0xE0];
    func_003B4DD8_5660(sp);
    switch (mode) {
    case 0:
        if (rate <= 24000) {
            *out = 24000;
        } else if (rate <= 36000) {
            *out = 36000;
        } else {
            *out = 48000;
        }
        break;
    case 1:
        if (rate <= 24000) {
            *out = 24000;
        } else if (rate <= 36000) {
            *out = 36000;
        } else {
            *out = 48000;
        }
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5710);
#ifdef SKIP_ASM
extern int func_003B4DD8_5710(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5710(void *) __asm__("func_003B4FC0");


int func_003C5710(int arg0, int arg1) {
    char buf[0xE0];
    func_003B4DD8_5710(buf);
    { int lim = 0xFFFF; arg1 = arg1 > lim ? lim : arg1; }
    *(short *)(buf + 0x2A) = arg1 & 0xFF;
    switch (arg0) {
    case 0:
        *(short *)(buf + 0x2A) = arg1;
        break;
    case 1:
        *(short *)(buf + 0x2C) = arg1;
        break;
    default:
        return -5;
    }
    func_003B4FC0_5710(buf);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5788);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct Buf_5788 { char pad[0x2A]; unsigned short a; unsigned short b; char rest[0xE0 - 0x2E]; } Buf_5788;
extern void func_003B4DD8_5788(Buf_5788 *) __asm__("func_003B4DD8");

int func_003C5788(int arg0, int *arg1) {
    Buf_5788 sp;

    *arg1 = 0;
    func_003B4DD8_5788(&sp);
    switch (arg0) {
    case 0:
        *arg1 = sp.a;
        break;
    case 1:
        *arg1 = sp.b;
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C57F0);
#ifdef SKIP_ASM
extern int func_003B4DD8_57F0(void *) __asm__("func_003B4DD8");

int func_003C57F0(int which, int *out) {
    char sp[0xE0];
    *out = 0;
    func_003B4DD8_57F0(sp);
    switch (which) {
    case 0:
        *out = *(unsigned char *)(sp + 6);
        break;
    case 1:
        *out = *(unsigned char *)(sp + 7);
        break;
    case 2:
        *out = *(unsigned char *)(sp + 8);
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5880);
#ifdef SKIP_ASM
extern int func_003B4DD8_5880(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5880(void *) __asm__("func_003B4FC0");

int func_003C5880(int which, int val) {
    char sp[0xE0];
    func_003B4DD8_5880(sp);
    switch (which) {
    case 0:
        sp[0x2E] = val;
        break;
    case 1:
        sp[0x2F] = val;
        break;
    case 2:
        sp[0x30] = val;
        break;
    default:
        return -5;
    }
    func_003B4FC0_5880(sp);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5908);
#ifdef SKIP_ASM
extern int func_003B4DD8_5908(void *) __asm__("func_003B4DD8");

int func_003C5908(int which, int *out) {
    char sp[0xE0];
    func_003B4DD8_5908(sp);
    switch (which) {
    case 0:
        *out = *(unsigned char *)(sp + 0x2E);
        break;
    case 1:
        *out = *(unsigned char *)(sp + 0x2F);
        break;
    case 2:
        *out = *(unsigned char *)(sp + 0x30);
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5998);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_5998(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5998(void *) __asm__("func_003B4FC0");

int func_003C5998(int arg0, float f) {
    char sp[0xE0];
    func_003B4DD8_5998(sp);
    switch (arg0) {
    case 0:
        *(signed char *)(sp + 0x40) = (int)(f * 100.0f);
        break;
    case 1:
        *(signed char *)(sp + 0x41) = (int)(f * 100.0f);
        break;
    default:
        return -5;
    }
    func_003B4FC0_5998(sp);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5A28);
#ifdef SKIP_ASM
extern void func_003B4DD8_5A28(void *) __asm__("func_003B4DD8");

int func_003C5A28(int arg0, float *out) {
    char sp[0xE0];
    func_003B4DD8_5A28(sp);
    switch (arg0) {
    case 0:
        *out = *(unsigned char *)(sp + 0x40) * 0.01f;
        break;
    case 1:
        *out = *(unsigned char *)(sp + 0x41) * 0.01f;
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AA0);
#ifdef SKIP_ASM
int func_003C5AA0(void) {
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AA8);
#ifdef SKIP_ASM
int func_003C5AA8(void) {
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AB0);
#ifdef SKIP_ASM
int func_003C5AB0(void) {
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AB8);
#ifdef SKIP_ASM
int func_003C5AB8(void) {
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_5AC0(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5AC0(void *) __asm__("func_003B4FC0");

int func_003C5AC0(int arg0) {
    char sp[0xE0];
    func_003B4DD8_5AC0(sp);
    *(signed char *)(sp + 0x3F) = arg0;
    func_003B4FC0_5AC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_5AF8(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5AF8(void *) __asm__("func_003B4FC0");

int func_003C5AF8(int arg0) {
    char sp[0xE0];
    func_003B4DD8_5AF8(sp);
    *(int *)(sp + 0x6C) = arg0;
    func_003B4FC0_5AF8(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5B30);
#ifdef SKIP_ASM
typedef struct { char pad[0x4A]; signed char v; char pad2[0xE0 - 0x4B]; } S_5B30;
extern void func_003B4FC0(void *);

int func_003C5B30(float f) {
    S_5B30 s;
    func_003B4DD8(&s);
    s.v = (int)(f * 100.0f);
    func_003B4FC0(&s);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5B80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_5B80(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5B80(void *) __asm__("func_003B4FC0");

int func_003C5B80(int arg0) {
    char sp[0xE0];
    func_003B4DD8_5B80(sp);
    *(signed char *)(sp + 0x42) = arg0;
    func_003B4FC0_5B80(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5BB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_5BB8(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5BB8(void *) __asm__("func_003B4FC0");

int func_003C5BB8(int arg0) {
    char sp[0xE0];
    func_003B4DD8_5BB8(sp);
    *(signed char *)(sp + 0x43) = arg0;
    func_003B4FC0_5BB8(sp);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5BF0);
#ifdef SKIP_ASM
int func_003C5BF0(void) {
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5BF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B4DD8_5BF8(void *) __asm__("func_003B4DD8");
extern void func_003B4FC0_5BF8(void *) __asm__("func_003B4FC0");

int func_003C5BF8(int arg0) {
    char sp[0xE0];
    func_003B4DD8_5BF8(sp);
    *(int *)(sp + 0xC8) = arg0;
    func_003B4FC0_5BF8(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5C30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003B4FC0_i(void *) __asm__("func_003B4FC0");
extern int func_003B5158(int, int, int);
extern int D_0044E1C0;
extern unsigned int D_0044E1C4;
extern int D_005157B0;

struct sInfo_5C30 {
    char pad0[0x2A];
    unsigned short w2A;
    unsigned short w2C;
    char pad2E;
    unsigned char b2F;
    char pad30[0x47 - 0x30];
    signed char f47;
    signed char f48;
    signed char f49;
    char pad4A[2];
    unsigned char n;
    char pad4D;
    short list[8];
    char tail[0xE0 - 0x5E];
};

int func_003C5C30(int arg0) {
    struct sInfo_5C30 info;
    int t;
    int ia;

    func_003B4DD8(&info);
    info.n = 0;
    if (D_0044E1C4 == 8) {
        info.list[0] = 0x44;
        info.n = 1;
    }
    info.list[info.n] = 0x24;
    info.n += 1;
    if (info.b2F != 0) {
        if (D_0044E1C4 == 8) {
            info.list[info.n] = 0x140;
            info.n += 1;
        }
        info.list[info.n] = 0x120;
        info.n += 1;
    }
    if (D_0044E1C4 == 8) {
        info.list[info.n] = 0x48;
        info.n += 1;
    }
    info.list[info.n] = 0x28;
    info.f49 = 1;
    info.f48 = 0;
    info.n += 1;
    switch (D_0044E1C4) {
    case 0:
        info.f47 = 1;
        break;
    case 4:
        info.f47 = 4;
        info.f49 = 2;
        break;
    case 5:
        info.f47 = 5;
        info.f49 = 2;
        break;
    case 1:
    case 8:
        info.f47 = 2;
        break;
    }
    ia = info.w2A;
    t = ia & 0xFFFF;
    if (t != info.w2C && (t != 0x8CA0 || info.w2C != 0x5DC0)) {
        info.w2C = ia;
    }
    func_003B4FC0_i(&info);
    func_003B5158(D_0044E1C0, D_005157B0, arg0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5DF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern signed char D_0050AA5C_5DF0[16] __asm__("D_0050AA5C");

int func_003C5DF0(void) {
    return D_0050AA5C_5DF0[0] == 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5E08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C0_5E08[] __asm__("D_0044E1C0");
void func_003B5320_5E08(void) __asm__("func_003B5320");
int func_003C5E08_5E08(void) __asm__("func_003C5E08");
int func_003C5E08_5E08(void) {
    func_003B5320_5E08();
    D_0044E1C0_5E08[0] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5E30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C0_5E30[] __asm__("D_0044E1C0");
extern int D_005157B0_5E30[] __asm__("D_005157B0");
int func_003C5E30(int a, int b, int c) {
    if (a == 0) {
        D_0044E1C0_5E30[0] = b;
        D_005157B0_5E30[0] = c;
        return 0;
    }
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5E58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C5DF0();
extern int D_0044E1C0_5E58[] __asm__("D_0044E1C0");
extern int D_005157B0_5E58[] __asm__("D_005157B0");

int func_003C5E58(int arg0, int *arg1, int *arg2) {
    *arg1 = 0;
    *arg2 = 0;
    if (arg0 == 0) {
        if (func_003C5DF0() == 0) {
            return -4;
        }
        *arg1 = D_0044E1C0_5E58[0];
        *arg2 = D_005157B0_5E58[0];
    } else {
        return -5;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5ED0);
#ifdef SKIP_ASM
typedef struct { char pad0[0x64]; int a; int b; char pad1[0xE0 - 0x6C]; } S_5ED0;
extern void func_003B4FC0(void *);

int func_003C5ED0(int arg0, int arg1) {
    S_5ED0 s;
    func_003B4DD8(&s);
    s.a = arg0;
    s.b = arg1;
    func_003B4FC0(&s);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5F18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B4FC0_5F18(char *) __asm__("func_003B4FC0");

int func_003C5F18(int arg0, float f) {
    char buf[0xE0];
    if (arg0 == 0) {
        func_003B4DD8(buf);
        buf[0x4B] = (int)(f * 100.0f);
        func_003B4FC0_5F18(buf);
        return 0;
    }
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5F70);
#ifdef SKIP_ASM
extern void func_003B4DD8(void *);

int func_003C5F70(int arg0, float *arg1) {
    unsigned char buf[0xE0];

    *arg1 = 0.0f;
    if (arg0 == 0) {
        func_003B4DD8(buf);
        *arg1 = (float)buf[0x4B] * 0.01f;
        return 0;
    }
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5FD0);
#ifdef SKIP_ASM
typedef struct { char pad0[0xCC]; int a; int b; char pad1[0xE0 - 0xD4]; } S_5FD0;
extern void func_003B4FC0(void *);

int func_003C5FD0(int arg0, int arg1) {
    S_5FD0 s;
    func_003B4DD8(&s);
    s.a = arg0;
    s.b = arg1;
    func_003B4FC0(&s);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_6018 { char pad[0x178]; signed char n; char pad2[0x23]; int v[1]; };
extern struct S_6018 D_0050A8E8_6018 __asm__("D_0050A8E8");
void func_003C6018(int a) {
    D_0050A8E8_6018.v[D_0050A8E8_6018.n] = a;
    D_0050A8E8_6018.n = D_0050A8E8_6018.n + 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6040);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad[0x178]; signed char n; char pad2[0x23]; int arr[1]; } S_6040;
extern S_6040 D_0050A8E8_6040 __asm__("D_0050A8E8");

void func_003C6040(int arg0) {
    int i;

    for (i = 0; i < D_0050A8E8_6040.n; i++) {
        if (D_0050A8E8_6040.arr[i] == arg0) {
            D_0050A8E8_6040.n--;
            while (i < D_0050A8E8_6040.n) {
                D_0050A8E8_6040.arr[i] = D_0050A8E8_6040.arr[i + 1];
                i++;
            }
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C60E0);
#ifdef SKIP_ASM
struct G_60E0 {
    char pad[0x174];
    signed char f174;
    char pad175[3];
    signed char f178;
    char pad179[0x19C - 0x179];
    void (*fn[8])(void);
};
extern struct G_60E0 D_0050A8E8_60E0 __asm__("D_0050A8E8");

void func_003C60E0(void) {
    int i;
    if (D_0050A8E8_60E0.f174 != 0) {
        for (i = 0; i < D_0050A8E8_60E0.f178; i++) {
            D_0050A8E8_60E0.fn[i]();
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C6158);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6240);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_0050AB1C_6240[] __asm__("D_0050AB1C");
int func_003C6240_6240(void) __asm__("func_003C6240");

int func_003C6240_6240(void) {
    int temp_3;

    temp_3 = (*(int *)((char*)(D_0050AB1C_6240[0]) + (8)));
    return (int) ((temp_3 - (*(int *)((char*)(D_0050AB1C_6240[0]) + (0x10)))) * 0x64) / temp_3;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6278);
#ifdef SKIP_ASM
void func_003C6278(void *arg0) {
    *(int *)((char *)arg0 + 0) = 0;
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 8) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6288);
#ifdef SKIP_ASM
void func_003C6288(void *arg0, void *arg1) {
    void *temp_2;

    (*(void **)((char*)(arg1) + (0))) = (void *) (*(void **)((char*)(arg0) + (0)));
    (*(int *)((char*)(arg1) + (4))) = 0;
    temp_2 = (*(void **)((char*)(arg0) + (0)));
    if (temp_2 != 0) {
        (*(void **)((char*)(temp_2) + (4))) = arg1;
    } else {
        (*(void **)((char*)(arg0) + (4))) = arg1;
    }
    (*(void **)((char*)(arg0) + (0))) = arg1;
    (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) + 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C62B8);
#ifdef SKIP_ASM
void func_003C62B8(void *arg0, int *arg1) {
    int *temp_2;

    (*(int **)((char*)(arg1) + (0))) = 0;
    (*(int **)((char*)(arg1) + (4))) = (int *) (*(int **)((char*)(arg0) + (4)));
    temp_2 = (*(int **)((char*)(arg0) + (4)));
    if (temp_2 != 0) {
        *temp_2 = (int)arg1;
    } else {
        (*(int **)((char*)(arg0) + (0))) = arg1;
    }
    (*(int **)((char*)(arg0) + (4))) = arg1;
    (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) + 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C62E8);
#ifdef SKIP_ASM
int *func_003C62E8(void *arg0) {
    int *temp_2;
    int *temp_3;

    temp_3 = (*(int **)((char*)(arg0) + (0)));
    if (temp_3 != 0) {
        temp_2 = *temp_3;
        (*(int **)((char*)(arg0) + (0))) = temp_2;
        if (temp_2 == 0) {
            (*(int *)((char*)(arg0) + (4))) = 0;
        } else {
            (*(int *)((char*)(temp_2) + (4))) = 0;
        }
        (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) - 1);
    }
    return temp_3;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6320);
#ifdef SKIP_ASM
void func_003C6320(void *arg0, void *arg1) {
    void **temp_3;
    void *temp_3_2;

    if (arg1 == (*(void **)((char*)(arg0) + (0)))) {
        (*(void **)((char*)(arg0) + (0))) = (void *) (*(void **)((char*)(arg1) + (0)));
    }
    if (arg1 == (*(void ***)((char*)(arg0) + (4)))) {
        (*(void ***)((char*)(arg0) + (4))) = (void **) (*(void ***)((char*)(arg1) + (4)));
    }
    temp_3 = (*(void ***)((char*)(arg1) + (4)));
    if (temp_3 != 0) {
        *temp_3 = (*(void **)((char*)(arg1) + (0)));
    }
    temp_3_2 = (*(void **)((char*)(arg1) + (0)));
    if (temp_3_2 != 0) {
        (*(void ***)((char*)(temp_3_2) + (4))) = (void **) (*(void ***)((char*)(arg1) + (4)));
    }
    (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) - 1);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C6380);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C64A8);
#ifdef SKIP_ASM
struct U64_64A8 { unsigned int lo, hi; };
unsigned int func_003C64A8(struct U64_64A8 n, unsigned int d) {
    unsigned int q = 0;
    unsigned int lo = n.lo;
    unsigned int r = n.hi;
    int i;
    for (i = 31; i >= 0; i--) {
        unsigned int c = lo >> 31;
        r <<= 1;
        r += c;
        q <<= 1;
        lo <<= 1;
        if (r >= d) {
            r -= d;
            q++;
        }
    }
    return q;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6500);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_6500 { int used; int pad[3]; };
struct G_6500 { char pad[0x28]; unsigned short count; char pad2[0x1F4 - 0x2A]; struct S_6500 *slots; };
extern struct G_6500 D_0050A8E8_6500[] __asm__("D_0050A8E8");

int func_003C6500(void) {
    int i;
    for (i = 0; i < D_0050A8E8_6500[0].count; i++) {
        if (D_0050A8E8_6500[0].slots[i].used == 0) {
            return i;
        }
    }
    return -9;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6540);
#ifdef SKIP_ASM
void *func_003C6540(char *arg0, int arg1) {
    int temp_3;

    if (arg1 >= *(unsigned short *)(arg0 + 6)) {
        return 0;
    }
    temp_3 = *(int *)(arg0 + (arg1 << 2) + 0x14);
    if (temp_3 == 0) {
        return 0;
    }
    return arg0 + ((arg1 << 2) + 0x14) + temp_3;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6580);
#ifdef SKIP_ASM
struct E_6580 { short h[0x46]; };
struct T_6580 { int pad; struct E_6580 e[1]; };
extern struct T_6580 *D_0050AAD8_6580 __asm__("D_0050AAD8");

int func_003C6580(int arg0, int arg1) {
    int i;
    int best = -1;
    int bi = -1;
    for (i = 0; i < arg1; i++) {
        if (best < D_0050AAD8_6580->e[arg0].h[i]) {
            best = D_0050AAD8_6580->e[arg0].h[i];
            bi = i;
        }
    }
    return bi;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C65E0);
#ifdef SKIP_ASM
int func_003C65E0(int arg0) {
    return (arg0 << 5) + 0x9C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C65F0);
#ifdef SKIP_ASM
int func_003CE198(void);
int func_003C65F0(int arg0) {
    int t = func_003C65E0(arg0);
    return t + func_003CE198();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C6620);

INCLUDE_ASM("ealib/seg_2B4578", func_003C6760);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6AB8);
#ifdef SKIP_ASM
/* 97.69: only missing "move $5,$2" copy of lbu result before loop (n vs r pseudo); volatile f48/f46/f4/f40/a[] needed */
struct A_6AB8 { char pad0[4]; unsigned int sz : 31; unsigned int flag : 1; char pad8[4]; int w[6]; };
struct R_6AB8 { int id; unsigned int sz : 31; unsigned int flag : 1; int w[6]; };
struct S_6AB8 {
    char pad0[4];
    volatile int f4;
    char pad8[0x2C];
    volatile unsigned short a[6];
    volatile unsigned short f40;
    char pad42[4];
    volatile unsigned short f46;
    volatile int f48;
    char pad4C[0x16];
    unsigned char f62;
    char pad63[0x19];
    struct R_6AB8 recs[1];
};
struct G_6AB8 { char pad[0x304]; struct S_6AB8 *p[1]; };
extern struct G_6AB8 D_005157B8_6AB8 __asm__("D_005157B8");






int func_003C6AB8(int arg0, struct A_6AB8 *arg1)
{
  struct S_6AB8 *s = D_005157B8_6AB8.p[arg0];
  struct R_6AB8 *e;
  int i;
  int r;
  for (i = 0; i < s->f62; i++)
  {
    if (((short) s->a[i]) >= (((short) s->f40) - 1))
    {
      r = -13;
      goto done;
    }
  }

  e = (struct R_6AB8 *) ((((char *) s) + 0x7C) + (((short) s->f46) << 5));
  e->sz = arg1->sz;
  e->flag = arg1->flag;
  e->id = s->f4;
  for (i = 0; i < s->f62; i++)
  {
    e->w[i] = arg1->w[i];
    s->a[i] += 1;
  }

  s->f48 += arg1->sz;
  r = s->f4;
  s->f4 = s->f4 + 1;
  s->f46 = s->f46 + 1;
  if (((short) s->f46) >= ((short) s->f40))
  {
    s->f46 = 0;
  }
  done:
  return r;

}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C6C28);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6C98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Inner_6C98 { char pad[0x48]; int a; int b; };
struct S_6C98 { char pad[0x304]; struct Inner_6C98 *p[1]; };
extern struct S_6C98 D_005157B8_6C98 __asm__("D_005157B8");
int func_003C6C98(int i) {
    struct Inner_6C98 *q = (&D_005157B8_6C98)[0].p[i];
    int b = q->b; int a = q->a; return a + b;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6CC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Inner_6CC0 { char pad[0x48]; int a; volatile int b; };
struct S_6CC0 { char pad[0x304]; struct Inner_6CC0 *p[1]; };
extern struct S_6CC0 D_005157B8_6CC0 __asm__("D_005157B8");
int func_003C6CC0(int i) {
    return (&D_005157B8_6CC0)[0].p[i]->b;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6CE0);
#ifdef SKIP_ASM
int func_003C6CE0(void) {
    return -0xF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6CE8);
#ifdef SKIP_ASM
struct E_6CE8 { int f0; char pad4[0x5E]; unsigned char n; char pad63; int arr[1]; };
struct G_6CE8 { char pad[0x304]; struct E_6CE8 *p[1]; };
extern struct G_6CE8 D_005157B8_6CE8 __asm__("D_005157B8");
extern void f_89E0_6CE8(int) __asm__("func_003B89E0");
extern void f_7080_6CE8(void) __asm__("func_003C7080");
extern int f_6CE0_6CE8(int, int, int) __asm__("func_003C6CE0");
extern void f_5E98_6CE8(int) __asm__("func_003B5E98");

int func_003C6CE8(int arg0) {
    struct E_6CE8 *e = D_005157B8_6CE8.p[arg0];
    int i = 0;

    f_89E0_6CE8(*(volatile int *)&e->f0);
    f_7080_6CE8();
    f_6CE0_6CE8(arg0, 0, 0x7FFFFFFF);
    *(volatile int *)&e->f0 = -1;

    for (; i < e->n; i++) {
        if (e->arr[i]) f_5E98_6CE8(e->arr[i]);

    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6DA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CE1A8_6DA0(void) __asm__("func_003CE1A8");
typedef struct { char pad[0x304]; int arr[100]; } W_6DA0;
extern W_6DA0 D_005157B8_6DA0 __asm__("D_005157B8");

int func_003C6DA0(int arg0) {
    func_003CE1A8_6DA0();
    D_005157B8_6DA0.arr[arg0] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6DE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_6DE0 { int pad; int len:31; int flag:1; unsigned int val[6]; };
struct Q_6DE0 {
    int pad0[2];
    volatile unsigned int wr;
    volatile unsigned int rd;
    volatile unsigned int pos[6];
    volatile short ridx[6];
    volatile short cnt[6];
    volatile short size;
    short pad42;
    volatile short widx;
    short pad46;
    volatile int a;
    volatile int b;
    int pad50;
    int flag;
    char pad58[10];
    unsigned char n;
    char pad63[0x19];
    struct E_6DE0 e[1];
};
struct Ev_6DE0 { short type; short id; int val; };
struct G_6DE0 { int count; struct Ev_6DE0 ev[0x60]; struct Q_6DE0 *q[1]; };
extern struct G_6DE0 D_005157B8_6DE0 __asm__("D_005157B8");

unsigned int func_003C6DE0(int id, int r, int *len, int *flag) {
    struct Q_6DE0 *q;
    struct E_6DE0 *e;
    struct Ev_6DE0 *ev;
    int ok, ok2, i;
    unsigned int v;

    ok = 1;
    q = D_005157B8_6DE0.q[id];
    ok2 = 1;
    for (i = 0; i < q->n; i++) {
        if (q->pos[i] <= q->wr) {
            ok = 0;
        }
    }
    if (ok) {
        struct E_6DE0 *w = &q->e[q->widx];
        if (q->flag) {
            ev = &D_005157B8_6DE0.ev[D_005157B8_6DE0.count];
            ev->type = 1;
            ev->id = id;
            ev->val = w->val[0];
            D_005157B8_6DE0.count++;
        }
        q->widx++;
        q->wr++;
        if (q->widx >= q->size) {
            q->widx = 0;
        }
    }
    if (q->cnt[r] == 0) {
        return 0;
    }
    e = &q->e[q->ridx[r]];
    *len = e->len;
    *flag = e->flag;
    q->ridx[r]++;
    q->pos[r]++;
    i = 0;
    do {
        if (q->pos[i] <= q->rd) {
            ok2 = 0;
        }
        i++;
    } while (ok2 == 1 && i < q->n);
    if (ok2) {
        q->rd++;
        q->a -= e->len;
        q->b += e->len;
    }
    if (q->ridx[r] >= q->size) {
        q->ridx[r] = 0;
    }
    q->cnt[r]--;
    v = e->val[r];
    return v ? v : 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7010);
#ifdef SKIP_ASM
struct Ent_7010 { short z; short id; int v; };
struct Obj_7010 { char p0[0x42]; volatile unsigned char f42; char p1[9]; volatile int f4C; char p2[8]; int f58; };
struct G_7010 { int count; struct Ent_7010 list[1]; char pad[0x2F8]; struct Obj_7010* tbl[1]; };
extern struct G_7010 D_005157B8_7010 __asm__("D_005157B8");
void func_003C7010(int id, int b, int c)
{
    struct Obj_7010* o = D_005157B8_7010.tbl[id];
    if (b == (signed char)o->f42) {

        o->f4C -= c;
        if (o->f58) {
            struct Ent_7010* e = &D_005157B8_7010.list[D_005157B8_7010.count];
            e->v = c;
            e->id = id;
            e->z = 0;
            D_005157B8_7010.count++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7080);
#ifdef SKIP_ASM
struct O_7080 { char pad[0x54]; void (*f54)(int, int); void (*f58)(int, int, int); int f5C; };
struct N_7080 { unsigned short a; unsigned short b; int arg; };
struct G_7080 { int count; struct N_7080 ent[96]; struct O_7080 *tab[1]; };
extern struct G_7080 D_005157B8_7080 __asm__("D_005157B8");

void func_003C7080(void) {
    int i;
    for (i = 0; i < D_005157B8_7080.count; i++) {
        struct N_7080 *n = &D_005157B8_7080.ent[i];
        struct O_7080 *o = D_005157B8_7080.tab[n->b];
        if (n->a == 0) {
            o->f58(n->b, n->arg, o->f5C);
        } else {
            o->f54(n->arg, o->f5C);
        }
    }
    D_005157B8_7080.count = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int fA6E8_7138(void) __asm__("func_003BA6E8");
extern int fAA00_7138(int, int *) __asm__("func_003BAA00");
extern void f2440_7138(int) __asm__("func_003C2440");
extern char D_A8E8_7138[] __asm__("D_0050A8E8");

int func_003C7138(void) {
    int sp0;
    int r = fA6E8_7138();
    if (r >= 0) {
        char *g;
        sp0 = -1;
        g = D_A8E8_7138;
        while (fAA00_7138(r, &sp0) != 0) {
            char *e = *(char **)(g + 0x1F0) + sp0 * 0x8C;
            signed char t = *(signed char *)(e + 0x5E);
            if (t < 0) {
                f2440_7138(sp0);
            } else if (*(signed char *)(e + 0x5D) < t) {
                char *q;
                int d;
                *(signed char *)(e + 0x5D) = (unsigned char)*(signed char *)(e + 0x5E);
                q = (char *)(t * 8 + *(int *)(e + 0x6C));
                d = *(int *)q;
                *(int *)(e + 0x44) = d;
                *(int *)(e + 0x3C) = ((*(int *)(q + 4) << 16) - *(int *)(e + 0x40)) / d;
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7218);
#ifdef SKIP_ASM
struct S7218 { short s0; char b2, b3, b4, b5, b6, b7; short s8; short sA; short sC[6]; int i18[6]; char pad[0x48 - 0x30]; int a48[4]; int a58[4]; };

int func_003C7218(struct S7218 *p) {
    int i;
    p->b3 = 0x7F;
    p->b4 = 0x40;
    p->s8 = 8;
    p->b2 = 0;
    p->s0 = 0;
    p->b5 = 0;
    p->b6 = 0;
    p->b7 = 0;
    for (i = 0; i < 4; i++) {
        p->a48[i] = 0;
        p->a58[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        p->sC[i] = 0;
        p->i18[i] = 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C72A0);
#ifdef SKIP_ASM
int func_003C72A0(int arg0) {
    if (arg0 > 0x10000) {
        arg0 = 0x10000;
    } else {
        arg0 = (arg0 <= -1) ? 0 : arg0;
    }
    return (int)(((func_003BC5C8() & 0x7FFF) - 0x4000) * arg0) >> 0xE;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C72F8);
#ifdef SKIP_ASM
int f_72F8_72F8(unsigned char *, int) __asm__("func_003C72F8");
int f_72F8_72F8(unsigned char *p, int n) {
    int v = 0;
    int i = n;
    int ext;
    while (i--) {
        v = (v << 8) + *p++;
    }
    if (n == 1 && v >= 0x80) {
        v -= 0x100;
    } else {
        if (n == 2 && v > 0x7FFF) {
            ext = 0xFFFF0000;
            v += ext;
        } else if (n == 3 && v > 0x7FFFFF) {
            ext = 0xFF000000;
            v += ext;
        }
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7388);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_7388 {
    unsigned char *p;
    unsigned cur;
    int r8;
    unsigned char *c;
    unsigned len;
};
extern unsigned func_003C72F8_7388(unsigned char *, unsigned) __asm__("func_003C72F8");

int func_003C7388(struct S_7388 *s) {
    unsigned char *p = s->p;
    unsigned char *q, *r;
    unsigned cur, len;
    if (*p == 0xFC) {
        do {
            q = p;
            s->p = q + 1;
            p = q + 1;
        } while (q[1] == 0xFC);
    }
    r = s->p;
    cur = *r;
    s->cur = cur;
    if (cur == 0xFF) {
        return 0;
    }
    s->p = r + 1;
    if (cur == 0xFD) {
        return 1;
    }
    if (cur == 0xFE) {
        return 1;
    }
    len = r[1];
    s->len = len;
    if (len == 0xFF) {
        s->len = func_003C72F8_7388(r + 2, 4);
        s->p = s->p + 4;
    }
    s->p = s->p + 1;
    s->c = s->p;
    if (s->len < 5) {
        s->r8 = func_003C72F8_7388(s->p, s->len);
    }
    s->p = s->p + s->len;
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7480);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S24_7480 { int w[6]; };
struct S16_7480 { int w[4]; };
struct T_7480 { struct S24_7480 a, b, c, d, e; struct S16_7480 f; int pad[2]; struct S16_7480 g; };
extern struct T_7480 D_0050AB20_7480 __asm__("D_0050AB20");
extern struct S24_7480 D_0044E1C8_7480 __asm__("D_0044E1C8");
extern struct S24_7480 D_0044E1E0_7480 __asm__("D_0044E1E0");
extern struct S24_7480 D_0044E1F8_7480 __asm__("D_0044E1F8");
extern struct S24_7480 D_0044E210_7480 __asm__("D_0044E210");
extern struct S24_7480 D_0044E228_7480 __asm__("D_0044E228");
extern struct S16_7480 D_0044E240_7480 __asm__("D_0044E240");
extern struct S16_7480 D_0044E250_7480 __asm__("D_0044E250");

void func_003C7480(void) {
    D_0050AB20_7480.a = D_0044E1C8_7480;
    D_0050AB20_7480.b = D_0044E1E0_7480;
    D_0050AB20_7480.c = D_0044E1F8_7480;
    D_0050AB20_7480.d = D_0044E210_7480;
    D_0050AB20_7480.e = D_0044E228_7480;
    D_0050AB20_7480.f = D_0044E240_7480;
    D_0050AB20_7480.g = D_0044E250_7480;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7600);
#ifdef SKIP_ASM
void func_003C7600(float *arg0, void *arg1) {
    (*(float *)((char*)(arg1) + (0))) = (float) ((*(float *)((char*)(arg1) + (0))) + (*arg0 * 0.9411765f));
    (*(float *)((char*)(arg1) + (4))) = (float) ((*(float *)((char*)(arg1) + (4))) + (*arg0 * 0.88235295f));
    (*(float *)((char*)(arg1) + (8))) = (float) ((*(float *)((char*)(arg1) + (8))) + (*arg0 * 0.8235294f));
    (*(float *)((char*)(arg1) + (0xC))) = (float) ((*(float *)((char*)(arg1) + (0xC))) + (*arg0 * 0.7647059f));
    (*(float *)((char*)(arg1) + (0x10))) = (float) ((*(float *)((char*)(arg1) + (0x10))) + (*arg0 * 0.7058824f));
    (*(float *)((char*)(arg1) + (0x14))) = (float) ((*(float *)((char*)(arg1) + (0x14))) + (*arg0 * 0.64705884f));
    (*(float *)((char*)(arg1) + (0x18))) = (float) ((*(float *)((char*)(arg1) + (0x18))) + (*arg0 * 0.5882353f));
    (*(float *)((char*)(arg1) + (0x1C))) = (float) ((*(float *)((char*)(arg1) + (0x1C))) + (*arg0 * 0.5294118f));
    (*(float *)((char*)(arg1) + (0x20))) = (float) ((*(float *)((char*)(arg1) + (0x20))) + (*arg0 * 0.47058824f));
    (*(float *)((char*)(arg1) + (0x24))) = (float) ((*(float *)((char*)(arg1) + (0x24))) + (*arg0 * 0.4117647f));
    (*(float *)((char*)(arg1) + (0x28))) = (float) ((*(float *)((char*)(arg1) + (0x28))) + (*arg0 * 0.3529412f));
    (*(float *)((char*)(arg1) + (0x2C))) = (float) ((*(float *)((char*)(arg1) + (0x2C))) + (*arg0 * 0.29411766f));
    (*(float *)((char*)(arg1) + (0x30))) = (float) ((*(float *)((char*)(arg1) + (0x30))) + (*arg0 * 0.23529412f));
    (*(float *)((char*)(arg1) + (0x34))) = (float) ((*(float *)((char*)(arg1) + (0x34))) + (*arg0 * 0.1764706f));
    (*(float *)((char*)(arg1) + (0x38))) = (float) ((*(float *)((char*)(arg1) + (0x38))) + (*arg0 * 0.11764706f));
    (*(float *)((char*)(arg1) + (0x3C))) = (float) ((*(float *)((char*)(arg1) + (0x3C))) + (*arg0 * 0.05882353f));
    *arg0 = 0.0f;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7828);
#ifdef SKIP_ASM
void func_003C7828(void *arg0, void *arg1, float fparg0, float fparg1) {
    float temp_f13;

    temp_f13 = (fparg1 - fparg0) * 0.05882353f;
    (*(float *)((char*)(arg1) + (0))) = (float) ((*(float *)((char*)(arg1) + (0))) + ((*(float *)((char*)(arg0) + (0))) * (fparg0 + temp_f13)));
    (*(float *)((char*)(arg1) + (4))) = (float) ((*(float *)((char*)(arg1) + (4))) + ((*(float *)((char*)(arg0) + (4))) * (fparg0 + (2.0f * temp_f13))));
    (*(float *)((char*)(arg1) + (8))) = (float) ((*(float *)((char*)(arg1) + (8))) + ((*(float *)((char*)(arg0) + (8))) * (fparg0 + (temp_f13 * 3.0f))));
    (*(float *)((char*)(arg1) + (0xC))) = (float) ((*(float *)((char*)(arg1) + (0xC))) + ((*(float *)((char*)(arg0) + (0xC))) * (fparg0 + (temp_f13 * 4.0f))));
    (*(float *)((char*)(arg1) + (0x10))) = (float) ((*(float *)((char*)(arg1) + (0x10))) + ((*(float *)((char*)(arg0) + (0x10))) * (fparg0 + (temp_f13 * 5.0f))));
    (*(float *)((char*)(arg1) + (0x14))) = (float) ((*(float *)((char*)(arg1) + (0x14))) + ((*(float *)((char*)(arg0) + (0x14))) * (fparg0 + (temp_f13 * 6.0f))));
    (*(float *)((char*)(arg1) + (0x18))) = (float) ((*(float *)((char*)(arg1) + (0x18))) + ((*(float *)((char*)(arg0) + (0x18))) * (fparg0 + (temp_f13 * 7.0f))));
    (*(float *)((char*)(arg1) + (0x1C))) = (float) ((*(float *)((char*)(arg1) + (0x1C))) + ((*(float *)((char*)(arg0) + (0x1C))) * (fparg0 + (temp_f13 * 8.0f))));
    (*(float *)((char*)(arg1) + (0x20))) = (float) ((*(float *)((char*)(arg1) + (0x20))) + ((*(float *)((char*)(arg0) + (0x20))) * (fparg0 + (temp_f13 * 9.0f))));
    (*(float *)((char*)(arg1) + (0x24))) = (float) ((*(float *)((char*)(arg1) + (0x24))) + ((*(float *)((char*)(arg0) + (0x24))) * (fparg0 + (temp_f13 * 10.0f))));
    (*(float *)((char*)(arg1) + (0x28))) = (float) ((*(float *)((char*)(arg1) + (0x28))) + ((*(float *)((char*)(arg0) + (0x28))) * (fparg0 + (temp_f13 * 11.0f))));
    (*(float *)((char*)(arg1) + (0x2C))) = (float) ((*(float *)((char*)(arg1) + (0x2C))) + ((*(float *)((char*)(arg0) + (0x2C))) * (fparg0 + (temp_f13 * 12.0f))));
    (*(float *)((char*)(arg1) + (0x30))) = (float) ((*(float *)((char*)(arg1) + (0x30))) + ((*(float *)((char*)(arg0) + (0x30))) * (fparg0 + (temp_f13 * 13.0f))));
    (*(float *)((char*)(arg1) + (0x34))) = (float) ((*(float *)((char*)(arg1) + (0x34))) + ((*(float *)((char*)(arg0) + (0x34))) * (fparg0 + (temp_f13 * 14.0f))));
    (*(float *)((char*)(arg1) + (0x38))) = (float) ((*(float *)((char*)(arg1) + (0x38))) + ((*(float *)((char*)(arg0) + (0x38))) * (fparg0 + (temp_f13 * 15.0f))));
    (*(float *)((char*)(arg1) + (0x3C))) = (float) ((*(float *)((char*)(arg1) + (0x3C))) + ((*(float *)((char*)(arg0) + (0x3C))) * (fparg0 + (temp_f13 * 16.0f))));
}
#endif

void func_003C7AA8(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7AB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Obj_7AB0 {
    int (*fn)(struct Obj_7AB0 *self, int a, int b, void *c, int d);
};
struct Snd_7AB0 {
    char pad00[0x3C];
    float f3C;
};
struct G_7AB0 {
    char pad000[0x5];
    unsigned char n;
    char pad006[0xF - 0x6];
    signed char on[1];
    char pad010[0xB0 - 0x10];
    int fB0;
    struct Snd_7AB0 *snd;
    char pad0B8[0xD0 - 0xB8];
    void *names[(0x1E0 - 0xD0) / 4];
    void (*set)(int a, struct Snd_7AB0 *snd, void *name, float v);
};
struct S_7AB0 {
    char pad00[0x4];
    float cur[6];
    float want[6];
    float a[1];
    float b[1];
    float f3C;
    struct Obj_7AB0 *obj;
};
extern struct G_7AB0 D_00515B40_7AB0 __asm__("D_00515B40");
extern char D_00515D80_7AB0[] __asm__("D_00515D80");
extern void func_003C7828_7AB0(struct Snd_7AB0 *snd, void *name, float from, float to) __asm__("func_003C7828");

int func_003C7AB0(struct S_7AB0 *s) {
    int i;

    if (s->obj->fn(s->obj, 0x10, D_00515B40_7AB0.fB0, D_00515B40_7AB0.snd, 0) <= 0) {
        for (i = 0; i < 1; i++) {
            s->a[i] = s->b[i];
        }
        for (i = 0; i < D_00515B40_7AB0.n; i++) {
            s->cur[i] = s->want[i];
        }
        return 0;
    }
    s->f3C = D_00515B40_7AB0.snd->f3C;
    for (i = 0; i < 1; i++) {
        if (D_00515B40_7AB0.on[i] != 0) {
            if (s->a[i] != s->b[i]) {
                func_003C7828_7AB0(D_00515B40_7AB0.snd, D_00515D80_7AB0, s->a[i], s->b[i]);
                s->a[i] = s->b[i];
            } else if (s->b[i] != 0.0f) {
                D_00515B40_7AB0.set(0x10, D_00515B40_7AB0.snd, D_00515D80_7AB0, s->b[i]);
            }
        }
    }
    for (i = 0; i < D_00515B40_7AB0.n; i++) {
        if (s->cur[i] != s->want[i]) {
            func_003C7828_7AB0(D_00515B40_7AB0.snd, D_00515B40_7AB0.names[i], s->cur[i], s->want[i]);
            s->cur[i] = s->want[i];
        } else if (s->want[i] != 0.0f) {
            D_00515B40_7AB0.set(0x10, D_00515B40_7AB0.snd, D_00515B40_7AB0.names[i], s->want[i]);
        }
    }
    return 0x10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7CC0);
#ifdef SKIP_ASM
extern void func_003B5C60();

void func_003C7CC0(void) {
    func_003B5C60();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7CE0);
#ifdef SKIP_ASM
extern void func_003B5E98();

void func_003C7CE0(void) {
    func_003B5E98();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C7D00);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct G_8018 { char p0[5]; unsigned char f5; char p6[0xA8-6]; int fA8[4]; int fB8[8]; char pc[0x1DC-0xD8]; int f1DC; };
extern struct G_8018 D_00515B40_8018 __asm__("D_00515B40");
extern void f_58A0_8018(void) __asm__("func_003B58A0");
extern void f_58D8_8018(void) __asm__("func_003B58D8");
extern void f_5E98_8018(int) __asm__("func_003B5E98");
extern void f_7AA8_8018(float) __asm__("func_003C7AA8");
void func_003C8018(void) {
    int i;
    int v;
    f_58A0_8018();
    if (D_00515B40_8018.f1DC) {
        f_5E98_8018(D_00515B40_8018.f1DC);
        D_00515B40_8018.f1DC = 0;
    }
    for (i = 0; i < 2; i++) {
        v = D_00515B40_8018.fA8[i];
        if ((v & 0x70000000) == 0x70000000) {
            D_00515B40_8018.fA8[i] = 0;
        } else if (v != 0) {
            f_5E98_8018(v);
            D_00515B40_8018.fA8[i] = 0;
        }
    }
    for (i = 0; i < D_00515B40_8018.f5; i++) {
        v = D_00515B40_8018.fB8[i];
        if ((v & 0x70000000) == 0x70000000) {
            D_00515B40_8018.fB8[i] = 0;
        } else if (v != 0) {
            f_5E98_8018(v);
            D_00515B40_8018.fB8[i] = 0;
        }
    }
    f_7AA8_8018(2.0f);
    f_58D8_8018();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8128);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad0[0xC]; short s; char pad1[0x1E0 - 0xE]; void (*f)(void); } C8128_S;
extern C8128_S D_00515B40;
extern void func_003CBB78_8128(void) __asm__("func_003CBB78");

void func_003C8128(void) {
    D_00515B40.f = func_003CBB78_8128;
    D_00515B40.s = 0x400;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8148);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern signed char D_00515B4E_8148[16] __asm__("D_00515B4E");

void func_003C8148(signed char arg0) {
    D_00515B4E_8148[0] = arg0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C8158);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C83A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct G_83A0 { char p0[5]; unsigned char cnt; char pad[0x1D6]; char *tbl; };
extern struct G_83A0 D_00515B40_83A0 __asm__("D_00515B40");

void func_003C83A0(int arg0) {
    int i;
    int j;
    char *e;
    float *a;
    float *b;
    i = 0;
    e = D_00515B40_83A0.tbl + arg0 * 0x60;
    *(int *)(e + 0x3C) = 0;
    a = (float *)(e + 0x34);
    e[1] = 0;
    do {
        i -= 1;
        a[0] = a[1];
        a++;
    } while (i >= 0);
    j = 0;
    if (D_00515B40_83A0.cnt != 0) {
        b = (float *)(e + 4);
        do {
            j += 1;
            b[0] = b[6];
            b++;
        } while (j < D_00515B40_83A0.cnt);
    }
    e[0] = 2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8430);
#ifdef SKIP_ASM
extern void func_003C8468();
extern int (*D_00515B48[])(int);

void func_003C8430(int arg0) {
    func_003C8468();
    D_00515B48[0](arg0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8468);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Node_8468 {
    int pad0;
    void (*fn)(struct Node_8468 *);
    struct Node_8468 *next;
};
struct Ent_8468 {
    char c0;
    char pad1[3];
    float a[12];
    float b[2];
    float scale;
    struct Node_8468 *node;
};
struct G_8468 {
    char pad0[5];
    unsigned char n;
    char pad1[0xE8 - 6];
    float f[6];
    float g[1];
    char pad2[0x1DC - 0x104];
    char *tab;
};
extern struct G_8468 D_00515B40_8468 __asm__("D_00515B40");
extern void func_003B5E98_8468(struct Node_8468 *) __asm__("func_003B5E98");

void func_003C8468(int idx) {
    struct Ent_8468 *e = (struct Ent_8468 *)(D_00515B40_8468.tab + idx * 0x60);
    int i;
    struct Node_8468 *nd;
    struct Node_8468 *next;
    for (i = 0; i < 1; i++) {
        D_00515B40_8468.g[i] += e->b[i] * e->scale;
    }
    for (i = 0; i < D_00515B40_8468.n; i++) {
        D_00515B40_8468.f[i] += e->a[i] * e->scale;
    }
    do {
        if (e->node->fn != 0) {
            e->node->fn(e->node);
        }
        nd = e->node;
        next = nd->next;
        func_003B5E98_8468(nd);
        e->node = next;
    } while (next != 0);
    e->c0 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8560);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_8560 {
    char pad0[1];
    char flag;
    char pad1[0x1A];
    float v[1];
    char pad2[0x40];
};
struct G_8560 {
    char pad[0x1DC];
    struct E_8560 *tab;
};
extern struct G_8560 D_00515B40_8560 __asm__("D_00515B40");

void func_003C8560(int idx, int k, float f) {
    D_00515B40_8560.tab[idx].v[k] = f;
    D_00515B40_8560.tab[idx].flag = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8598);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_8598 {
    char pad0[1];
    char flag;
    char pad1[0x36];
    float v[1];
    char pad2[0x24];
};
struct G_8598 {
    char pad[0x1DC];
    struct E_8598 *tab;
};
extern struct G_8598 D_00515B40_8598 __asm__("D_00515B40");

void func_003C8598(int idx, int k, float f) {
    D_00515B40_8598.tab[idx].v[k] = f;
    D_00515B40_8598.tab[idx].flag = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C85D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Obj_85D0 {
    int (*fn)(struct Obj_85D0 *self, int n, int b, float *snd, int d);
};
struct Ent_85D0 {
    signed char state;
    signed char dirty;
    char pad2[2];
    float cur[6];
    float want[6];
    float a[1];
    float b[1];
    float f3C;
    struct Obj_85D0 *obj;
    char pad44[0x60 - 0x44];
};
struct G_85D0 {
    char pad000[0x4];
    unsigned char cnt;
    unsigned char n;
    char pad006[0xF - 0x6];
    signed char on[1];
    void (*fn10)(int);
    char pad014[0xB0 - 0x14];
    int fB0;
    float *snd;
    char pad0B8[0xD0 - 0xB8];
    float *names[6];
    float f[6];
    float g[1];
    struct Obj_85D0 *objB[6];
    struct Obj_85D0 *objA[6];
    char pad134[0x1DC - 0x134];
    struct Ent_85D0 *tab;
    void (*set)(int a, float *snd, float *name, float v);
};
extern struct G_85D0 D_00515B40_85D0 __asm__("D_00515B40");
extern float D_00515D80_85D0[] __asm__("D_00515D80");
extern void f6210_85D0(void *, int, int) __asm__("func_00416210");
extern int f7AB0_85D0(struct Ent_85D0 *) __asm__("func_003C7AB0");
extern void f8430_85D0(int) __asm__("func_003C8430");

void func_003C85D0(int *outs, int n) {
    struct Ent_85D0 *e;
    int i;
    int j;
    int k;
    int m;
    int r;

    for (i = 0; i < 1; i++) {
        if (D_00515B40_85D0.on[i] != 0 && D_00515B40_85D0.g[i] != 0.0f) {
            func_003C7600(&D_00515B40_85D0.g[i], D_00515D80_85D0);
        }
    }
    for (i = 0; i < D_00515B40_85D0.n; i++) {
        f6210_85D0(D_00515B40_85D0.names[i], 0, n * 4);
        if (D_00515B40_85D0.f[i] != 0.0f) {
            func_003C7600(&D_00515B40_85D0.f[i], D_00515B40_85D0.names[i]);
        }
    }
    for (j = 0; j < D_00515B40_85D0.cnt; j++) {
        e = &D_00515B40_85D0.tab[j];
        if (e->state == 2) {
            if (e->dirty != 0) {
                k = f7AB0_85D0(e);
                e->dirty = 0;
                m = n - k;
            } else {
                k = 0;
                m = n;
            }
            if (m != 0) {
                r = e->obj->fn(e->obj, m, D_00515B40_85D0.fB0, D_00515B40_85D0.snd, 0);
                if (r < 0) {
                    f8430_85D0(j);
                } else if (r != 0) {
                    e->f3C = D_00515B40_85D0.snd[r - 1];
                    for (i = 0; i < D_00515B40_85D0.n; i++) {
                        if (e->want[i] != 0.0f) {
                            D_00515B40_85D0.set(r, D_00515B40_85D0.snd, D_00515B40_85D0.names[i] + k, e->want[i]);
                        }
                    }
                    for (i = 0; i < 1; i++) {
                        if (D_00515B40_85D0.on[i] != 0 && e->b[i] != 0.0f) {
                            D_00515B40_85D0.set(r, D_00515B40_85D0.snd, D_00515D80_85D0 + k, e->b[i]);
                            *(int *)((char *)D_00515D80_85D0 + 0x1800) = 0;
                        }
                    }
                }
            }
        }
    }
    if (D_00515B40_85D0.fn10 != 0) {
        D_00515B40_85D0.fn10(n);
    }
    for (i = 0; i < D_00515B40_85D0.n; i++) {
        if (D_00515B40_85D0.objA[i] != 0) {
            D_00515B40_85D0.objA[i]->fn(D_00515B40_85D0.objA[i], n, (int)D_00515B40_85D0.names[i], (float *)D_00515B40_85D0.fB0, 0);
            D_00515B40_85D0.objB[i]->fn(D_00515B40_85D0.objB[i], n, D_00515B40_85D0.fB0, (float *)outs[i], 0);
        } else {
            D_00515B40_85D0.objB[i]->fn(D_00515B40_85D0.objB[i], n, (int)D_00515B40_85D0.names[i], (float *)outs[i], 0);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C8968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad[5]; unsigned char cnt; char pad2[6]; unsigned short add; } H_8968;
extern H_8968 D_00515B40_8968[] __asm__("D_00515B40");
extern unsigned char D_00515B45_8968[] __asm__("D_00515B45");
extern void func_003C85D0_8968(int *, int) __asm__("func_003C85D0");

void func_003C8968(int *src, int len) {
    int buf[8];
    int i, n;

    for (i = 0; i < D_00515B45_8968[0]; i++) {
        buf[i] = src[i];
    }
    while (len > 0) {
        func_003C85D0_8968(buf, len < 0x201 ? len : 0x200);
        for (i = 0; i < D_00515B40_8968[0].cnt; i++) {
            buf[i] += D_00515B40_8968[0].add;
        }
        len -= 0x200;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8A40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_00515D1C_8A40[] __asm__("D_00515D1C");

int func_003C8A40(int idx) {
    char *e = D_00515D1C_8A40[0] + idx * 0x60;
    int (*fn)(int) = *(int (**)(int))(e + 0x44);
    if (fn != 0) {
        return fn(*(int *)(e + 0x48));
    }
    return -1;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C8A88);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8B40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad[0x4C]; int f; char pad2[0x10]; } E_8B40;
typedef struct { E_8B40 arr[100]; } W_8B40;
extern W_8B40 *D_00515D1C_8B40[] __asm__("D_00515D1C");
void func_003CB110_8B40(int, int) __asm__("func_003CB110");

void func_003C8B40(int arg0, int arg1) {
    int temp_4;

    temp_4 = D_00515D1C_8B40[0]->arr[arg0].f;
    if (temp_4 != 0) {
        func_003CB110_8B40(temp_4, arg1);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8B80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *f_5C60_8B80(int) __asm__("func_003B5C60");
extern void f_5E98_8B80(void *) __asm__("func_003B5E98");
extern void f_8F48_8B80(void *, void *) __asm__("func_003C8F48");
extern void f_8FB0_8B80(void *, void *) __asm__("func_003C8FB0");
extern void f_B4A8_8B80(void *, int) __asm__("func_003CB4A8");
extern void f_B528_8B80(void *) __asm__("func_003CB528");
struct Q_8B80 { int w0; int w4; char pad[0x10]; short h18; };
struct E_8B80 { char pad[0x40]; char sub[0x14]; struct Q_8B80 *q; char pad2[8]; };
extern struct E_8B80 *D_00515D1C_8B80[] __asm__("D_00515D1C");

void func_003C8B80(int arg0, int arg1) {
    struct E_8B80 *p = D_00515D1C_8B80[0] + arg0;
    if (arg1 > 0) {
        if (p->q == 0) {
            struct Q_8B80 *n = (struct Q_8B80 *)f_5C60_8B80(0x50);
            p->q = n;
            n->w4 = 0;
            p->q->h18 = 0x78;
            f_B528_8B80(p->q);
            f_8F48_8B80(p->sub, p->q);
        }
        f_B4A8_8B80(p->q, arg1);
        return;
    }
    if (p->q != 0) {
        f_8FB0_8B80(p->sub, p->q);
        f_5E98_8B80(p->q);
        p->q = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8C30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_00515D1C_8C30[] __asm__("D_00515D1C");
extern unsigned short D_0050A912_8C30[] __asm__("D_0050A912");
extern void *func_003B5C60_8C30(int) __asm__("func_003B5C60");
extern void func_003B5E98_8C30(void *) __asm__("func_003B5E98");
extern void func_003CA990_8C30(void *) __asm__("func_003CA990");
extern void func_003C8F48_8C30(void *, void *) __asm__("func_003C8F48");
extern void func_003C8FB0_8C30(void *, void *) __asm__("func_003C8FB0");
extern void func_003CA9D8_8C30(void *, int *) __asm__("func_003CA9D8");

void func_003C8C30(int arg0, int arg1) {
    int sp[2];
    char *e;
    char *buf;

    e = D_00515D1C_8C30[0] + arg0 * 0x60;
    if (arg1 > 0) {
        if (*(char**)(e + 0x5C) == 0) {
            char *t2 = func_003B5C60_8C30(0x120);
            *(char**)(e + 0x5C) = t2;
            *(int*)(t2 + 4) = 0;
            *(short*)(*(char**)(e + 0x5C) + 0x18) = 0x50;
            *(signed char*)(*(char**)(e + 0x5C) + 0x1A) = 0;
            func_003CA990_8C30(*(char**)(e + 0x5C));
            func_003C8F48_8C30(e + 0x40, *(char**)(e + 0x5C));
        }
        sp[0] = arg1 << 8;
        sp[1] = D_0050A912_8C30[0] << 8;
        func_003CA9D8_8C30(*(char**)(e + 0x5C), sp);
        return;
    }
    buf = *(char**)(e + 0x5C);
    if (buf != 0) {
        func_003C8FB0_8C30(e + 0x40, buf);
        func_003B5E98_8C30(*(char**)(e + 0x5C));
        *(char**)(e + 0x5C) = 0;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C8D00);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8E28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_003B5C60_8E28(int) __asm__("func_003B5C60");
extern void func_003C8F48_8E28(int, void *) __asm__("func_003C8F48");
extern int D_00515D1C_8E28[] __asm__("D_00515D1C");

void func_003C8E28(int arg0, int arg1, void *arg2) {
    int temp_18;
    int temp_7;
    void *temp_2;

    temp_7 = arg0 * 0x60;
    temp_18 = D_00515D1C_8E28[0] + temp_7;
    temp_2 = func_003B5C60_8E28((*(int *)((char*)(arg2) + (4))));
    (*(int (**)(void *, int, int))((char*)(arg2) + (0xC)))(temp_2, (*(int *)((char*)(arg2) + (0))), arg1);
    (*(unsigned short *)((char*)(temp_2) + (0x18))) = (unsigned short) (*(unsigned short *)((char*)(arg2) + (8)));
    (*(int *)((char*)(temp_2) + (0))) = (int) (*(int *)((char*)(arg2) + (0x10)));
    (*(int *)((char*)(temp_2) + (4))) = (int) (*(int *)((char*)(arg2) + (0x14)));
    (*(signed char *)((char*)(temp_2) + (0x1A))) = 0;
    func_003C8F48_8E28(temp_18 + 0x40, temp_2);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8EC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_00515D1C_8EC0[] __asm__("D_00515D1C");
extern void func_003C8FB0_8EC0(char *, char *) __asm__("func_003C8FB0");
extern void func_003B5E98_8EC0(char *) __asm__("func_003B5E98");

void func_003C8EC0(int arg0, int arg1) {
    char *rec = D_00515D1C_8EC0[0] + arg0 * 0x60;
    char *node = *(char **)(rec + 0x40);
    void (*fn)(char *);
    do {
        if (*(unsigned short *)(node + 0x18) == arg1) {
            fn = *(void (**)(char *))(node + 4);
            if (fn != 0) {
                fn(node);
            }
            func_003C8FB0_8EC0(rec + 0x40, node);
            func_003B5E98_8EC0(node);
            return;
        }
        node = *(char **)(node + 8);
    } while (node != 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8F48);
#ifdef SKIP_ASM
void func_003C8F48(char **arg0, char *arg1) {
    char *cur;
    char *prev;

    cur = *arg0;
    prev = 0;
    while (cur != 0 && *(unsigned short *)(cur + 0x18) < *(unsigned short *)(arg1 + 0x18)) {
        prev = cur;
        cur = *(char **)(cur + 8);
    }
    *(char **)(arg1 + 8) = cur;
    if (cur != 0) {
        *(char **)(cur + 0x10) = arg1;
    }
    if (prev == 0) {
        *arg0 = arg1;
    } else {
        *(char **)(prev + 8) = arg1;
        *(char **)(arg1 + 0x10) = prev;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8FB0);
#ifdef SKIP_ASM
typedef struct N_8FB0 { char pad0[8]; struct N_8FB0 *next; int pad1; struct N_8FB0 *prev; } N_8FB0;

void func_003C8FB0(N_8FB0 **arg0, N_8FB0 *arg1) {
    N_8FB0 *temp_5;
    N_8FB0 *var_2;
    N_8FB0 *var_6;

    var_6 = *arg0;
    var_2 = var_6->next;
    if (arg1 == var_6) {
        *arg0 = var_2;
        return;
    }
    while (var_2 != 0 && var_2 != arg1) {
        var_6 = var_2;
        var_2 = var_6->next;
    }
    if ((var_2 != 0) && (var_2 == arg1)) {
        temp_5 = arg1->next;
        if (temp_5 != 0) {
            temp_5->prev = var_6;
        }
        var_6->next = var_6->next->next;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9010);
#ifdef SKIP_ASM
int func_003C9010(void *arg0) {
    int (*temp_2)();

    temp_2 = (*(int (**)())((char*)(arg0) + (4)));
    if (temp_2 != 0) {
        temp_2();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9040);
#ifdef SKIP_ASM
void func_003C9040(void *arg0) {
    int (*temp_2)(void *);
    void *temp_4;
    void *temp_4_2;

    temp_4 = (*(void **)((char*)(arg0) + (8)));
    if ((temp_4 != 0) && ((*(unsigned char *)((char*)(temp_4) + (0x1B))) == 0)) {
        func_003C9040(temp_4);
    }
    temp_4_2 = (*(void **)((char*)(arg0) + (0xC)));
    if ((temp_4_2 != 0) && ((*(unsigned char *)((char*)(temp_4_2) + (0x1B))) == 0)) {
        func_003C9040(temp_4_2);
    }
    temp_2 = (*(int (**)(void *))((char*)(arg0) + (4)));
    if (temp_2 != 0) {
        temp_2(arg0);
    }
    (*(signed char *)((char*)(arg0) + (0x1B))) = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C90C0);
#ifdef SKIP_ASM
int func_003C90C0(char *a, char *b, int s, int t) {
    if (s == 1 && t == 1 && *(int*)(b + 8) == 0) {
        *(int*)(a + 0x10) = (int)b;
        *(int*)(b + 8) = (int)a;
        *(char*)(b + 0x1A) = t;
        return 0;
    }
    if (s == 1 && t == 2 && *(int*)(b + 0xC) == 0) {
        *(int*)(a + 0x10) = (int)b;
        *(int*)(b + 0xC) = (int)a;
        *(char*)(b + 0x1A) = s;
        return 0;
    }
    if (s == 2 && t == 1 && *(int*)(b + 8) == 0) {
        *(int*)(a + 0x14) = (int)b;
        *(int*)(b + 8) = (int)a;
        *(char*)(b + 0x1A) = s;
        return 0;
    }
    if (s == 2 && t == 2 && *(int*)(b + 0xC) == 0) {
        *(int*)(a + 0x14) = (int)b;
        *(int*)(b + 0xC) = (int)a;
        *(char*)(b + 0x1A) = t;
        return 0;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9188);
#ifdef SKIP_ASM
int func_003C9188(int *a, int *b, int x, int y) {
    if (x == 1 && y == 1 && a[4] == (int)b && b[2] == (int)a) {
        a[4] = 0;
        b[2] = 0;
        return 0;
    }
    if (x == 1 && y == 2 && a[4] == (int)b && b[3] == (int)a) {
        a[4] = 0;
        b[3] = 0;
        return 0;
    }
    if (x == 2 && y == 1 && a[5] == (int)b && b[2] == (int)a) {
        a[5] = 0;
        b[2] = 0;
        return 0;
    }
    if (x == 2 && y == 2 && a[5] == (int)b && b[3] == (int)a) {
        a[5] = 0;
        b[3] = 0;
        return 0;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9268);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct {
    char pad0[0x18];
    void *p18, *p1c, *p20;
    char pad1[0x60 - 0x24];
    int i60, i64, i68;
} G_9268;
extern G_9268 D_00515B40_9268 __asm__("D_00515B40");
extern void f_9268_a(void) __asm__("func_003C9AC8");
extern void f_9268_b(void) __asm__("func_003C9BC8");
extern void f_9268_c(void) __asm__("func_003C9D28");

void func_003C9268(void) {
D_00515B40_9268.p18 = f_9268_a;
    D_00515B40_9268.i60 = 0x2C;
    D_00515B40_9268.p1c = f_9268_b;
    D_00515B40_9268.i64 = 0x30;
    D_00515B40_9268.p20 = f_9268_c;
    D_00515B40_9268.i68 = 0x34;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C92B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct {
    char pad0[0x24];
    void *p24, *p28, *p2c;
    char pad1[0x6C - 0x30];
    int i6c, i70, i74;
} G_92B0;
extern G_92B0 D_00515B40_92B0 __asm__("D_00515B40");
extern void f_92B0_a(void) __asm__("func_003CA028");
extern void f_92B0_b(void) __asm__("func_003CA388");
extern void f_92B0_c(void) __asm__("func_003CA610");

void func_003C92B0(void) {
D_00515B40_92B0.p24 = f_92B0_a;
    D_00515B40_92B0.i6c = 0x2C;
    D_00515B40_92B0.i70 = 0x54;
    D_00515B40_92B0.p28 = f_92B0_b;
    D_00515B40_92B0.p2c = f_92B0_c;
    D_00515B40_92B0.i74 = 0x3C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C92F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct {
    char pad[0x30];
    void *f30, *f34, *f38, *f3C, *f40, *f44;
    char pad2[0x30];
    int i78, i7C, i80, i84, i88, i8C;
} G_92F8;
extern void func_003C9420_9420(void) __asm__("func_003C9420");
extern void func_003C9618_9618(void) __asm__("func_003C9618");
extern void func_003C9960_9960(void) __asm__("func_003C9960");
extern G_92F8 D_00515B40_5B40 __asm__("D_00515B40");

void func_003C92F8(void) {
    D_00515B40_5B40.f30 = func_003C9420_9420;
    D_00515B40_5B40.i78 = 0x2C;
    D_00515B40_5B40.f38 = func_003C9960_9960;
    D_00515B40_5B40.i80 = 0x3C;
    D_00515B40_5B40.f34 = func_003C9618_9618;
    D_00515B40_5B40.i7C = 0x30;
D_00515B40_5B40.f3C = func_003C9420_9420;
    D_00515B40_5B40.i84 = 0x2C;
    D_00515B40_5B40.f44 = func_003C9960_9960;
    D_00515B40_5B40.i8C = 0x3C;
    D_00515B40_5B40.f40 = func_003C9618_9618;
    D_00515B40_5B40.i88 = 0x30;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9358);
#ifdef SKIP_ASM
int func_003C9358(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9360);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CDE68_9360(int, int **, int) __asm__("func_003CDE68");
extern void func_00416210_9360(int *, int, int) __asm__("func_00416210");

int func_003C9360(void *arg0, int arg1, int arg2, int *arg3) {
    int *sp0;
    int temp_2;

    sp0 = arg3;
    if ((unsigned int) (*(unsigned int *)((char*)(arg0) + (0x20))) >= (unsigned int) (*(unsigned int *)((char*)(arg0) + (0x1C)))) {
        return -1;
    }
    temp_2 = func_003CDE68_9360((*(int *)((char*)(arg0) + (0x28))), &sp0, arg1);
    (*(unsigned int *)((char*)(arg0) + (0x20))) = (unsigned int) ((*(unsigned int *)((char*)(arg0) + (0x20))) + temp_2);
    sp0 = sp0 + temp_2;
    if (temp_2 < arg1) {
        func_00416210_9360(sp0, 0, (arg1 -= temp_2) * 4);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C93F8);
#ifdef SKIP_ASM
extern void func_003CD1D0(int);

void func_003C93F8(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x28)));
    if (temp_4 != 0) {
        func_003CD1D0(temp_4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9420);
#ifdef SKIP_ASM
typedef struct { int a, b, c; } Q_9420;
extern int f_9360_9420[] __asm__("func_003C9360");
extern int f_93F8_9420[] __asm__("func_003C93F8");
extern int f_9358_9420[] __asm__("func_003C9358");
extern int f_D1A8_9420(int) __asm__("func_003CD1A8");
extern void *f_DDB8_9420(int) __asm__("func_003CDDB8");
extern Q_9420 f_E078_9420(int) __asm__("func_003CE078");
extern void f_E0B8_9420(int, Q_9420 *, int) __asm__("func_003CE0B8");
extern void f_E0D8_9420(int, int) __asm__("func_003CE0D8");
extern void f_DDE8_9420(int, int, int, int) __asm__("func_003CDDE8");

void func_003C9420_impl(char *, char *) __asm__("func_003C9420");
void func_003C9420_impl(char *self, char *src) {
    Q_9420 q;
    Q_9420 t;
    int n;
    *(int **)(self + 0) = f_9360_9420;
    *(int *)(self + 0x1C) = *(int *)(src + 0xC);
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = *(int *)(src + 0x24);
    *(int **)(src + 0x28) = f_9358_9420;
    *(int **)(self + 4) = f_93F8_9420;
    *(void **)(self + 0x28) = f_DDB8_9420(f_D1A8_9420(0xD68));
    t = f_E078_9420(*(int *)(self + 0x28));
    q = t;
    q.c = 1;
    f_E0B8_9420(*(int *)(self + 0x28), &q, 0);
    if (*(int *)(self + 0x24) < 3) {
        f_E0D8_9420(*(int *)(self + 0x28), 0);
    } else {
        f_E0D8_9420(*(int *)(self + 0x28), 1);
    }
    n = *(int *)(self + 0x1C);
    f_DDE8_9420(*(int *)(self + 0x28), *(int *)(src + 0), n * 4, n);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9518);
#ifdef SKIP_ASM
int func_003C9518(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9520);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a, b, c; } Q_9520;
extern int func_003CDE68_9520(int, int *, int) __asm__("func_003CDE68");
extern void func_003CE0B8_9520(int, void *, int) __asm__("func_003CE0B8");
extern void func_003CDDE8_9520(int, int, int, int) __asm__("func_003CDDE8");

int func_003C9520(char *arg0, int arg1, int arg2, int arg3) {
    Q_9520 q;
    int sp10;
    int n, t;

    sp10 = arg3;
    if (arg1 > 0) {
        do {
            n = func_003CDE68_9520(*(int*)(arg0 + 0x1C), &sp10, arg1);
            arg1 -= n;
            sp10 += n * 4;
            *(int*)(arg0 + 0x20) = *(int*)(arg0 + 0x20) + n;
            if (n < arg1) {
                *(int*)(arg0 + 0x20) = *(int*)(arg0 + 0x24);
                q.b = 0;
                q.a = 0;
                q.c = 1;
                func_003CE0B8_9520(*(int*)(arg0 + 0x1C), &q, 0);
                t = (*(int*)(arg0 + 0x28) - *(int*)(arg0 + 0x24)) + 1;
                func_003CDDE8_9520(*(int*)(arg0 + 0x1C), *(int*)(arg0 + 0x2C), t * 4, t);
            }
        } while (arg1 > 0);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C95F0);
#ifdef SKIP_ASM
extern void func_003CD1D0(int);

void func_003C95F0(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CD1D0(temp_4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9618);
#ifdef SKIP_ASM
typedef struct { int a, b, c; } Q_9618;
extern int f_9520_9618[] __asm__("func_003C9520");
extern int f_95F0_9618[] __asm__("func_003C95F0");
extern int f_9518_9618[] __asm__("func_003C9518");
extern int f_D1A8_9618(int) __asm__("func_003CD1A8");
extern void *f_DDB8_9618(int) __asm__("func_003CDDB8");
extern Q_9618 f_E078_9618(int) __asm__("func_003CE078");
extern void f_E0B8_9618(int, Q_9618 *, int) __asm__("func_003CE0B8");
extern int f_DDE8_9618(int, int, int, int) __asm__("func_003CDDE8");

void func_003C9618_impl(char *, char *) __asm__("func_003C9618");
void func_003C9618_impl(char *self, char *src) {
    Q_9618 q;
    Q_9618 t;
    int n;
    *(int **)(self + 0) = f_9520_9618;
    *(int **)(self + 4) = f_95F0_9618;
    *(int *)(self + 0x2C) = *(int *)(src + 4);
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = *(int *)(src + 0x10);
    *(int *)(self + 0x28) = *(int *)(src + 0x14);
    *(void **)(self + 0x1C) = f_DDB8_9618(f_D1A8_9618(0xD68));
    t = f_E078_9618(*(int *)(self + 0x1C));
    q = t;
    q.c = 1;
    f_E0B8_9618(*(int *)(self + 0x1C), &q, 0);
    n = *(int *)(self + 0x24);
    f_DDE8_9618(*(int *)(self + 0x1C), *(int *)(src + 0), n * 4, n);
    *(int **)(src + 0x28) = f_9518_9618;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C96F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a, b, c; } Q_96F0;
extern void f_7010_96F0(int, int, int) __asm__("func_003C7010");
extern int f_6DE0_96F0(int, int, char *, int *) __asm__("func_003C6DE0");
extern int f_DE68_96F0(int, int *, int) __asm__("func_003CDE68");
extern Q_96F0 f_E078_96F0(int) __asm__("func_003CE078");
extern void f_E0B8_96F0(int, Q_96F0 *, int) __asm__("func_003CE0B8");
extern void f_E0D8_96F0(int, int) __asm__("func_003CE0D8");
extern void f_DDE8_96F0(int, int, int, int) __asm__("func_003CDDE8");
extern void f_6210_96F0(int, int, int) __asm__("func_00416210");

int func_003C96F0(char *self, int n, int unused, int buf) {
    Q_96F0 q;
    Q_96F0 t;
    int last;
    int total;
    int got;

    total = 0;
    if (*(int *)(self + 0x28) != 0) {
        f_7010_96F0(*(int *)(self + 0x24), *(unsigned char *)(self + 0x38), *(int *)(self + 0x28));
        *(int *)(self + 0x28) = 0;
    }
    while (n > 0) {
        got = f_DE68_96F0(*(int *)(self + 0x34), &buf, n);
        *(unsigned short *)(self + 0x2C) += got;
        total += got;
        buf += got * 4;
        *(int *)(self + 0x28) += got;
        if (got < n) {
            n -= got;
            *(int *)(self + 0x1C) = f_6DE0_96F0(*(int *)(self + 0x24), *(unsigned char *)(self + 0x38), self + 0x20, &last);
            if (*(int *)(self + 0x1C) != 0) {
                *(unsigned short *)(self + 0x2C) = 0;
                if (*(int *)(self + 0x30) < 3) {
                    if (last == 0) {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.c = 1;
                        f_E0B8_96F0(*(int *)(self + 0x34), &q, 0);
                    } else {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.c = 0;
                        f_E0B8_96F0(*(int *)(self + 0x34), &q, 0);
                    }
                    f_E0D8_96F0(*(int *)(self + 0x34), 0);
                } else {
                    if (last == 0) {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.b = 0;
                        q.c = 1;
                    } else {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.c = 0;
                    }
                    f_E0B8_96F0(*(int *)(self + 0x34), &q, 0);
                    f_E0D8_96F0(*(int *)(self + 0x34), 1);
                }
                f_DDE8_96F0(*(int *)(self + 0x34), *(int *)(self + 0x1C) + 1, *(int *)(self + 0x20) * 4, *(int *)(self + 0x20));
            } else {
                if (n > 0 && *(int *)(self + 0x28) != 0) {
                    f_6210_96F0(buf, 0, n * 4);
                }
                *(int *)(self + 0x20) = 0;
                n = 0;
            }
        } else {
            n -= got;
        }
    }
    return total;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9938);
#ifdef SKIP_ASM
extern void func_003CD1D0(int);

void func_003C9938(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x34)));
    if (temp_4 != 0) {
        func_003CD1D0(temp_4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9960);
#ifdef SKIP_ASM
extern int func_003CD1A8_9960(int) __asm__("func_003CD1A8");
extern void *func_003CDDB8_9960(int) __asm__("func_003CDDB8");
extern int func_003CE0E0_9960(int) __asm__("func_003CE0E0");
extern signed char func_003CE118_9960(int) __asm__("func_003CE118");
extern int func_003CE378_9960(int) __asm__("func_003CE378");
extern int func_003C96F0_9960[] __asm__("func_003C96F0");
extern int func_003C9938_9960[] __asm__("func_003C9938");

void func_003C9960(void *arg0, void *arg1) {
    (*(int **)((char *)(arg0) + 0)) = func_003C96F0_9960;
    (*(int *)((char *)(arg0) + 0x24)) = func_003CE378_9960(func_003CE0E0_9960((*(int *)((char *)(arg1) + 0x1C))));
    (*(signed char *)((char *)(arg0) + 0x38)) = func_003CE118_9960((*(int *)((char *)(arg1) + 0x1C)));
    (*(int *)((char *)(arg0) + 0x1C)) = 0;
    (*(short *)((char *)(arg0) + 0x2C)) = 0;
    (*(int *)((char *)(arg0) + 0x30)) = (int)(*(int *)((char *)(arg1) + 0x24));
    (*(int *)((char *)(arg0) + 0x20)) = (int)(*(int *)((char *)(arg1) + 0xC));
    (*(int **)((char *)(arg0) + 4)) = func_003C9938_9960;
    (*(void **)((char *)(arg0) + 0x34)) = func_003CDDB8_9960(func_003CD1A8_9960(0xD68));
    (*(int *)((char *)(arg0) + 0x28)) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C99F8);
#ifdef SKIP_ASM
int func_003C99F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9A00);
#ifdef SKIP_ASM
struct R_9A00 { char pad[0x1C]; short *data; unsigned int pos; unsigned int cap; int flag; };

int func_003C9A00(struct R_9A00 *r, unsigned int n, int arg2, int *buf) {
    unsigned int pos = r->pos;
    unsigned int cap = r->cap;
    if (pos >= cap) return -1;
    r->pos = pos + n;
    if (pos + n < cap) {
        if (r->flag) {
            func_003C9E50(n, r->data + pos, buf);
        }
    } else {
        unsigned int first = cap - pos;
        if (r->flag) {
            func_003C9E50(first, r->data + pos, buf);
        }
        func_00416210(buf + first, 0, (n - first) * 4);
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9AC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C99F8_9AC8(void) __asm__("func_003C99F8");
void func_003C9A00_9AC8(void) __asm__("func_003C9A00");

void func_003C9AC8(char *arg0, char *arg1) {
    int t;
    *(void (**)(void))(arg0 + 0) = func_003C9A00_9AC8;
    t = *(int *)(arg1 + 0);
    *(int *)(arg0 + 0x20) = 0;
    *(int *)(arg0 + 0x1C) = t;
    *(int *)(arg0 + 0x24) = *(int *)(arg1 + 0xC);
    *(int *)(arg0 + 0x28) = *(int *)(arg1 + 0x18);
    *(void (**)(void))(arg1 + 0x28) = func_003C99F8_9AC8;
    *(int *)(arg0 + 4) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9B08);
#ifdef SKIP_ASM
int func_003C9B08(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9B10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_9E50_9B10(int, void *, void *) __asm__("func_003C9E50");
struct R_9B10 { char pad[0x1C]; short *buf; unsigned cur; unsigned start; unsigned end; int en; };

int func_003C9B10(struct R_9B10 *self, int n, int unused, int *src) {
    int m;
    while (n > 0) {
        m = self->end - self->cur + 1;
        if (n < m)
            m = n;
        if (self->en != 0)
            f_9E50_9B10(m, self->buf + self->cur, src);
        src += m;
        self->cur = self->cur + m;
        n -= m;
        if (self->end < self->cur)
            self->cur = self->start;
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9BC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C9B10_9BC8(void) __asm__("func_003C9B10");
void func_003C9B08_9BC8(void) __asm__("func_003C9B08");

void func_003C9BC8(int *a, int *b) {
    a[0] = (int)func_003C9B10_9BC8;
    a[7] = b[0];
    a[8] = 0;
    a[9] = b[4];
    a[10] = b[5];
    a[11] = b[6];
    b[10] = (int)func_003C9B08_9BC8;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9C08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C6DE0_9C08(int, unsigned char, int *, int *) __asm__("func_003C6DE0");
extern void func_003C7010_9C08(int, unsigned char, int) __asm__("func_003C7010");
extern void func_003C9E50_9C08(int, int, int *) __asm__("func_003C9E50");
extern void func_00416210_9C08(int *, int, int) __asm__("func_00416210");

int func_003C9C08_9C08(char *o, int n, int unused, int *buf) __asm__("func_003C9C08");
int func_003C9C08_9C08(char *o, int n, int unused, int *buf) {
    int sp0, sp4;
    int t;
    if (*(int *)(o + 0x2C) != 0) {
        func_003C7010_9C08(*(int *)(o + 0x28), *(unsigned char *)(o + 0x31), *(int *)(o + 0x2C));
        *(int *)(o + 0x2C) = 0;
    }
    while (n > 0) {
        if (*(int *)(o + 0x24) >= *(int *)(o + 0x20)) {
            *(int *)(o + 0x1C) = func_003C6DE0_9C08(*(int *)(o + 0x28), *(unsigned char *)(o + 0x31), &sp0, &sp4);
            if (*(int *)(o + 0x1C) == 0) {
                if (*(int *)(o + 0x2C) != 0) {
                    func_00416210_9C08(buf, 0, n * 4);
                }
                return *(int *)(o + 0x2C);
            }
            *(int *)(o + 0x24) = 0;
            *(int *)(o + 0x20) = sp0;
        }
        t = *(int *)(o + 0x20) - *(int *)(o + 0x24);
        if (n < t) t = n;
        if (*(unsigned char *)(o + 0x30) != 0) {
            func_003C9E50_9C08(t, *(int *)(o + 0x1C) + *(int *)(o + 0x24) * 2, buf);
        }
        buf += t;
        n -= t;
        *(int *)(o + 0x24) += t;
        *(int *)(o + 0x2C) += t;
    }
    return *(int *)(o + 0x2C);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9D28);
#ifdef SKIP_ASM
extern int func_003CE0E0(int);
extern signed char func_003CE118(int);
extern int func_003CE378(int);
extern void func_003C9C08(void);

void func_003C9D28(void *arg0, void *arg1) {
    (*(int **)((char*)(arg0) + (0))) = (int*)&func_003C9C08;
    (*(int *)((char*)(arg0) + (0x28))) = func_003CE378(func_003CE0E0((*(int *)((char*)(arg1) + (0x1C)))));
    (*(signed char *)((char*)(arg0) + (0x31))) = func_003CE118((*(int *)((char*)(arg1) + (0x1C))));
    (*(int *)((char*)(arg0) + (0x20))) = -1;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    (*(int *)((char*)(arg0) + (0x24))) = 0;
    (*(unsigned char *)((char*)(arg0) + (0x30))) = (*(unsigned char *)((char*)(arg1) + (0x18)));
    (*(int *)((char*)(arg0) + (0x2C))) = 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C9DA0);

INCLUDE_ASM("ealib/seg_2B4578", func_003C9E50);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9F58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CCF90_9F58(int, char **, int) __asm__("func_003CCF90");
extern void func_00416210_9F58(char *, int, int) __asm__("func_00416210");

int func_003C9F58(void *arg0, int arg1, int arg2, int arg3) {
    char *p;
    char *q;
    int n;
    p = (char *)arg3;
    if (*(int *)((char *)arg0 + 0x28) >= *(int *)((char *)arg0 + 0x24)) {
        return -1;
    }
    n = func_003CCF90_9F58(*(int *)((char *)arg0 + 0x1C), &p, arg1);
    *(int *)((char *)arg0 + 0x28) += n;
    p += n * 4;
    q = p;
    if (n < arg1) {
        arg1 = arg1 - n;
        n += arg1;
        func_00416210_9F58(q, 0, arg1 * 4);
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9FF8);
#ifdef SKIP_ASM
int func_003C9FF8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x28)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA000);
#ifdef SKIP_ASM
extern void func_003CCF18(int);

void func_003CA000(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CCF18(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA028);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char func_003C9F58_A028[] __asm__("func_003C9F58");
extern char func_003C9FF8_A028[] __asm__("func_003C9FF8");
extern char func_003CA000_A028[] __asm__("func_003CA000");
extern int func_003CCEF0_A028(int) __asm__("func_003CCEF0");
extern int func_003CCF40_A028(int) __asm__("func_003CCF40");
extern void func_003CCF60_A028(int, int, int, int) __asm__("func_003CCF60");

void func_003CA028(char *arg0, char *arg1) {
    int n;
    *(char **)(arg0 + 0) = func_003C9F58_A028;
    *(char **)(arg0 + 4) = func_003CA000_A028;
    *(int *)(arg0 + 0x20) = *(int *)(arg1 + 0);
    *(int *)(arg0 + 0x24) = *(int *)(arg1 + 0xC);
    *(int *)(arg0 + 0x28) = 0;
    *(int *)(arg0 + 0x1C) = func_003CCF40_A028(func_003CCEF0_A028(0xA8));
    *(char **)(arg1 + 0x28) = func_003C9FF8_A028;
    n = *(int *)(arg0 + 0x24);
    func_003CCF60_A028(*(int *)(arg0 + 0x1C), *(int *)(arg0 + 0x20), n * 4, n);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CA0B8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA358);
#ifdef SKIP_ASM
int func_003CA358(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA360);
#ifdef SKIP_ASM
extern void func_003CCF18(int);

void func_003CA360(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CCF18(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA388);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char func_003CA0B8_A388[] __asm__("func_003CA0B8");
extern char func_003CA358_A388[] __asm__("func_003CA358");
extern char func_003CA360_A388[] __asm__("func_003CA360");
extern int func_003CCEF0_A388(int) __asm__("func_003CCEF0");
extern int func_003CCF40_A388(int) __asm__("func_003CCF40");
extern void func_003CCF60_A388(int, int, int, int) __asm__("func_003CCF60");

void func_003CA388(int *self, int *arg1) {
    int n;

    self[0] = (int)func_003CA0B8_A388;
    self[1] = (int)func_003CA360_A388;
    self[11] = arg1[1];
    self[8] = 0;
    self[12] = arg1[9];
    self[9] = arg1[4];
    self[10] = arg1[5];
    self[7] = func_003CCF40_A388(func_003CCEF0_A388(0xA8));
    arg1[10] = (int)func_003CA358_A388;
    if (self[12] < 3) {
        self[13] = arg1[0];
        self[14] = arg1[3];
        self[15] = 0;
        self[16] = 0;
        self[17] = arg1[4];
        self[18] = arg1[5];
    } else {
        n = self[9];
        func_003CCF60_A388(self[7], arg1[0], n * 4, n);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA460);
#ifdef SKIP_ASM
extern int func_003CCF90_A460(int, int **, int) __asm__("func_003CCF90");
extern void func_003C7010_A460(int, unsigned char, int) __asm__("func_003C7010");
extern short *func_003C6DE0_A460(int, unsigned char, int *, int *) __asm__("func_003C6DE0");
extern void func_00416210_A460(int *, int, int) __asm__("func_00416210");
extern void func_003CD190_A460(int, float *) __asm__("func_003CD190");
extern void func_003CCF60_A460(int, short *, int, int) __asm__("func_003CCF60");

int func_003CA460(char *o, int n, int unused, int *buf) {
    float f[2];
    int *dst;
    int sp14;
    int used = 0;
    int got;
    int flag = 0;

    dst = buf;

    if (*(int *)(o + 0x34) != 0) {
        func_003C7010_A460(*(int *)(o + 0x30), *(unsigned char *)(o + 0x38), *(int *)(o + 0x34));
        *(int *)(o + 0x34) = 0;
    }
    while (n > 0) {
        got = func_003CCF90_A460(*(int *)(o + 0x1C), &dst, n);
        used += got;
        *(int *)(o + 0x28) += got;
        dst += got;
        *(int *)(o + 0x34) += got;
        if (got < n) {
            short *p;
            n -= got;
            p = func_003C6DE0_A460(*(int *)(o + 0x30), *(unsigned char *)(o + 0x38), (int *)(o + 0x24), &sp14);
            *(short **)(o + 0x20) = p;
            if (p != 0) {
                if (*(int *)(o + 0x2C) < 3) flag = 1;
                if (flag) {
                    f[0] = (float)p[0];
                    f[1] = (float)p[1];
                    func_003CD190_A460(*(int *)(o + 0x1C), f);
                    *(short **)(o + 0x20) += 2;
                }
                *(int *)(o + 0x28) = 0;
                func_003CCF60_A460(*(int *)(o + 0x1C), *(short **)(o + 0x20), *(int *)(o + 0x24) * 4, *(int *)(o + 0x24));
            } else {
                if (n > 0 && *(int *)(o + 0x34) != 0) {
                    func_00416210_A460(dst, 0, n * 4);
                }
                n = 0;
            }
        } else {
            n -= got;
        }
    }
    return used;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA5E8);
#ifdef SKIP_ASM
extern void func_003CCF18(int);

void func_003CA5E8(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CCF18(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA610);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CCEF0_A610(int) __asm__("func_003CCEF0");
extern int func_003CCF40_A610(int) __asm__("func_003CCF40");
extern int func_003CE0E0_A610(int) __asm__("func_003CE0E0");
extern signed char func_003CE118_A610(int) __asm__("func_003CE118");
extern int func_003CE378_A610(int) __asm__("func_003CE378");
extern int func_003CA460_A610[] __asm__("func_003CA460");
extern int func_003CA5E8_A610[] __asm__("func_003CA5E8");

void func_003CA610(void *arg0, void *arg1) {
    (*(int **)((char*)(arg0) + (0))) = func_003CA460_A610;
    (*(int **)((char*)(arg0) + (4))) = func_003CA5E8_A610;
    (*(int *)((char*)(arg0) + (0x30))) = func_003CE378_A610(func_003CE0E0_A610((*(int *)((char*)(arg1) + (0x1C)))));
    (*(signed char *)((char*)(arg0) + (0x38))) = func_003CE118_A610((*(int *)((char*)(arg1) + (0x1C))));
    (*(int *)((char*)(arg0) + (0x2C))) = (int) (*(int *)((char*)(arg1) + (0x24)));
    (*(int *)((char*)(arg0) + (0x20))) = 0;
    (*(int *)((char*)(arg0) + (0x24))) = (int) (*(int *)((char*)(arg1) + (0xC)));
    (*(int *)((char*)(arg0) + (0x28))) = 0;
    (*(int *)((char*)(arg0) + (0x34))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = func_003CCF40_A610(func_003CCEF0_A610(0xA8));
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CA6A8);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA7A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CA6A8_A7A0(void) __asm__("func_003CA6A8");

void func_003CA7A0(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(void (**)(void))((char *)arg0 + 0) = func_003CA6A8_A7A0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA7B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef int (*vfn_A7B8)(void *, int, float *, float *, unsigned char);
int func_003CA7B8_A7B8(char *, int, float *, float *) __asm__("func_003CA7B8");
int func_003CA7B8_A7B8(char *self, int n, float *in, float *out) {
    void **o = *(void ***)(self + 8);
    int r;
    float *st;
    int i;
    if (o == 0 || (r = ((vfn_A7B8)(*(void **)o))(o, n, out, in, *(unsigned char *)(self + 0x1A))) > 0) {
        st = (float *)(self + 0x1C);
        for (i = 0; i < n; i++) {
            st[0] = st[0] * st[1] + st[2] * in[i];
            out[i] = st[0];
        }
        r = n;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA870);
#ifdef SKIP_ASM
extern void func_003CA7B8();

int func_003CA870(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(void (**)())((char*)(arg0) + (0))) = func_003CA7B8;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(signed char *)((char*)(arg0) + (0x1B))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA8A0);
#ifdef SKIP_ASM
void func_003CA8A0(void *arg0, void *arg1) {
    float temp_f1;
    float temp_f2;

    temp_f1 = (2.0f * (float) (*(int *)((char*)(arg1) + (0)))) / (float) (*(int *)((char*)(arg1) + (4)));
    temp_f2 = 1.0f - temp_f1;
    (*(float *)((char*)(arg0) + (0x24))) = temp_f1;
    (*(float *)((char*)(arg0) + (0x20))) = temp_f2;
    (*(float *)((char*)(arg0) + (0x24))) = (float) (temp_f1 * ((float) (*(int *)((char*)(arg1) + (8))) * 0.00390625f));
    (*(float *)((char*)(arg0) + (0x20))) = (float) (temp_f2 * ((float) (*(int *)((char*)(arg1) + (8))) * 0.00390625f));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA900);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003CEBE8_A900(void *, int, int, int) __asm__("func_003CEBE8");

int func_003CA900(char *p, int arg1, int arg2, int arg3) {
    int (**obj)(void *, int, int, int, int);
    int n;
    obj = *(int (***)(void *, int, int, int, int))(p + 8);
    if (obj != 0) {
        n = (*obj)(obj, arg1, arg3, arg2, *(unsigned char *)(p + 0x1A));
        if (n <= 0) {
            return n;
        }
    } else {
        n = arg1;
    }
    func_003CEBE8_A900(p + 0x20, n, arg2, arg3);
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA990);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; int f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int pad1c; char sub[1]; } S_A990;
extern void func_003CEB90(void *);
extern void func_003CA900_x(void) __asm__("func_003CA900");

int func_003CA990(S_A990 *self) {
    self->vt = func_003CA900_x;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f4 = 0;
    func_003CEB90(&self->sub);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA9D8);
#ifdef SKIP_ASM
extern void func_003CE7C0_A9D8(char *, int) __asm__("func_003CE7C0");

void func_003CA9D8(char *arg0, int *arg1) {
    *(float *)(arg0 + 0x114) = (float)(arg1[0] >> 7) / (float)(arg1[1] >> 8);
    func_003CE7C0_A9D8(arg0 + 0x20, 3);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CAA28);

INCLUDE_ASM("ealib/seg_2B4578", func_003CAB28);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CAC88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C51E8_AC88(void *, void *, int) __asm__("func_003C51E8");
extern void func_003CAA28_AC88(void *, void *, void *, int, int) __asm__("func_003CAA28");

void func_003CAC88(char *arg0, char **arg1, int arg2) {
    char *v18;
    char *v20;
    if (*(int *)(arg0 + 0x34) > 0) {
        v18 = arg0 + 0x40;
        v20 = *arg1;
    } else {
        v18 = *arg1;
        v20 = v18 + *(int *)(arg0 + 0x2C) * 4;
    }
    if (arg2 == 0) {
        func_003C51E8_AC88(arg0 + 0x838, v18, *(int *)(arg0 + 0x2C) * 4);
        *(int *)(arg0 + 0x30) = *(int *)(arg0 + 0x30) - *(int *)(arg0 + 0x2C);
        *(int *)(arg0 + 0x38) = *(int *)(arg0 + 0x2C);
        *arg1 = v20;
    } else {
        if (arg2 > 0) {
            int t = arg2 * 4;
            func_003C51E8_AC88(arg0 + 0x838, v18, t);
            func_003CAA28_AC88(v18, v20, arg0 + (t + 0x838), *(int *)(arg0 + 0x2C), arg2);
            *(int *)(arg0 + 0x30) = *(int *)(arg0 + 0x30) - *(int *)(arg0 + 0x2C);
            *(int *)(arg0 + 0x38) = *(int *)(arg0 + 0x2C) + arg2;
            *arg1 = v20;
        } else {
            int m, d, n;
            func_003CAA28_AC88(v18, v20, arg0 + 0x838, *(int *)(arg0 + 0x2C), arg2);
            m = *(int *)(arg0 + 0x2C);
            func_003C51E8_AC88(arg0 + ((m * 4) + 0x838), v20 - arg2 * 4, (m + arg2) * 4);
            n = *(int *)(arg0 + 0x2C);
            d = n * 2;
            *(int *)(arg0 + 0x30) = *(int *)(arg0 + 0x30) - d;
            *(int *)(arg0 + 0x38) = d + arg2;
            *arg1 = v20 + n * 4;
        }
    }
    *(int *)(arg0 + 0x34) = 0;
    *(int *)(arg0 + 0x3C) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CADF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C51E8_ADF0(int, void *, int) __asm__("func_003C51E8");

int func_003CADF0(void *arg0, int *arg1, int *arg2) {
    int temp_16;
    int temp_16_2;
    int temp_20;
    int temp_3;

    temp_16_2 = (*(int *)((char*)(arg0) + (0x38)));
    temp_3 = *arg1;
    temp_16 = temp_16_2;
    if (temp_16_2 >= temp_3) temp_16 = temp_3;
    temp_20 = temp_16 * 4;
    func_003C51E8_ADF0(*arg2, arg0 + (((*(int *)((char*)(arg0) + (0x3C))) * 4) + 0x838), temp_20);
    (*(int *)((char*)(arg0) + (0x3C))) = (int) ((*(int *)((char*)(arg0) + (0x3C))) + temp_16);
    (*(int *)((char*)(arg0) + (0x38))) = (int) ((*(int *)((char*)(arg0) + (0x38))) - temp_16);
    *arg1 -= temp_16;
    *arg2 += temp_20;
    return temp_16;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CAEA0);

INCLUDE_ASM("ealib/seg_2B4578", func_003CAFD0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB110);
#ifdef SKIP_ASM
struct S_B110 { char pad[0x24]; float f24; };

void func_003CB110(struct S_B110 *p, int v) {
    p->f24 = (float)v * 0.000244140625f;
    if ((double)p->f24 < 0.5) {
        p->f24 = 0.5f;
    } else if ((double)p->f24 > 2.0) {
        p->f24 = 2.0f;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB1A8);
#ifdef SKIP_ASM
struct O_B1A8 { int (*fn)(struct O_B1A8 *, int, int *, int, int); };
struct S_B1A8 { char pad0[8]; struct O_B1A8 *f8; char padC[0xE]; unsigned char f1A; char pad1B[5]; int f20; };
extern int f_AEA0_B1A8(struct S_B1A8 *, int) __asm__("func_003CAEA0");
extern int f_AFD0_B1A8(struct S_B1A8 *, int, int, int *) __asm__("func_003CAFD0");
extern int f_6C98_B1A8(int) __asm__("func_003C6C98");
extern void f_6210_B1A8(int *, int, int) __asm__("func_00416210");

int func_003CB1A8_impl(struct S_B1A8 *, int, int, int *) __asm__("func_003CB1A8");
int func_003CB1A8_impl(struct S_B1A8 *s, int n, int a2, int *buf) {
    int w = f_AEA0_B1A8(s, n);
    int r;
    if (s->f20 >= 0) {
        if (f_6C98_B1A8(s->f20) < w) return 0;
    }
    if (w > 0) {
        r = s->f8->fn(s->f8, w, buf, a2, s->f1A);
        if (r <= 0) return r;
    }
    r = f_AFD0_B1A8(s, n, a2, buf);
    if (r < n) {
        f_6210_B1A8(buf + r, 0, (n - r) * 4);
    }
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CB280);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C72F8(int, int);
extern int func_003CE0E0(int);
extern int func_003CE378(int);
extern char func_003CB1A8_B280[] __asm__("func_003CB1A8");

int func_003CB280(void *arg0, void *arg1, int arg2) {
    (*(char **)((char*)(arg0) + (0))) = func_003CB1A8_B280;
    (*(int *)((char*)(arg0) + (4))) = 0;
    if (arg2 >= 0) {
        (*(int *)((char*)(arg0) + (0x20))) = func_003CE378(func_003CE0E0(arg2));
    } else {
        (*(int *)((char*)(arg0) + (0x20))) = -1;
    }
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (arg1 + 6);
    (*(float *)((char*)(arg0) + (0x24))) = 1.0f;
    (*(int *)((char*)(arg0) + (0x28))) = 0;
    (*(int *)((char*)(arg0) + (0x2C))) = (int) ((*(unsigned char *)((char*)(arg1) + (1))) * 2);
    (*(int *)((char*)(arg0) + (0x30))) = func_003C72F8(arg1 + 2, 4);
    (*(int *)((char*)(arg0) + (0x34))) = 0;
    (*(int *)((char*)(arg0) + (0x38))) = 0;
    (*(int *)((char*)(arg0) + (0x3C))) = 0;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CB328);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB4A8);
#ifdef SKIP_ASM
struct P { char pad[0x20]; short A[8]; short B[8]; short C[8]; };
void func_003CB4A8(struct P* p, int x)
{
    int t = (x * 0x7D00) >> 15;
    int b = 0x7FFF - t;
    int i;
    p->A[0] = t - 0x8000;
    p->B[0] = b;
    p->C[0] = 0x3FDE00 / (short)b;
    for (i = 1; i < 8; i++) {
        p->A[i] = p->A[0];
        p->B[i] = p->B[0];
        p->C[i] = p->C[0];
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CB528);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CB328_B528(void) __asm__("func_003CB328");

void func_003CB528(void (**arg0)(void)) {
    *arg0 = func_003CB328_B528;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB538);
#ifdef SKIP_ASM
void func_003CB538(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CB540);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CBB28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_BB28_vt(void) __asm__("func_003CB540");

void func_003CBB28(int *self) {
    int i;
    self[1] = 0;
    self[8] = 0;
    self[0] = (int)f_BB28_vt;
    ((short *)self)[0x24 / 2] = 0;
    ((short *)self)[0x26 / 2] = 0;
    for (i = 3; i >= 0; i--)
        self[0xA + i] = 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CBB78);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CBC00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00515B54_BC00[4] __asm__("D_00515B54");

void func_003CBC00(int arg0) {
    D_00515B54_BC00[0] = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CBC10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00515D80_BC10[4] __asm__("D_00515D80");

int *func_003CBC10(void) {
    return D_00515D80_BC10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CBC20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044E770_BC20[][6][6] __asm__("D_0044E770");

unsigned char func_003CBC20(int arg0, int arg1, int arg2) {
    return D_0044E770_BC20[arg0 - 1][arg1 - 1][arg2 - 1];
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CBC58);

INCLUDE_ASM("ealib/seg_2B4578", func_003CBEC8);

INCLUDE_ASM("ealib/seg_2B4578", func_003CC070);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CC630);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Hdr_C630 {
    int f0;
    int f4;
    int cnt[6];
    int len[6];
};
struct G_C630 {
    char pad00[0x5];
    unsigned char n;
    char pad06[0xF - 0x6];
    signed char fF;
    void *f10;
};
extern struct Hdr_C630 D_005175C0_C630 __asm__("D_005175C0");
extern int D_005175C8_C630[] __asm__("D_005175C8");
extern struct G_C630 D_00515B40_C630 __asm__("D_00515B40");
extern int D_0044E870_C630[] __asm__("D_0044E870");
extern int D_0044E898;
extern int D_00515D54;
extern int D_00515D58;
extern unsigned char *D_005175F8;
extern unsigned char *D_005175FC;
extern void func_003CBC58();
extern void func_003CC848_C630(void) __asm__("func_003CC848");
extern void func_003C51E8_C630(void *dst, void *src, int size) __asm__("func_003C51E8");
extern int func_003C72F8_C630(void *p, int size) __asm__("func_003C72F8");
extern void func_003CC070_C630(int a, unsigned char *data) __asm__("func_003CC070");

void func_003CC630(int a0, unsigned char *data) {
    unsigned char *p = data + 0x38;
    int n;
    int i;
    int j;
    int k;

    func_003CC848_C630();
    D_0044E898 = 1;
    func_003C51E8_C630(&D_005175C0_C630, data, 0x38);
    n = D_00515B40_C630.n - 1;
    if (func_003C72F8_C630(&D_005175C0_C630.cnt[n], 4) != 0) {
        D_00515D58 = D_00515B40_C630.n;
    } else {
        while (func_003C72F8_C630(&D_005175C8_C630[n], 4) == 0) {
            n--;
        }
        D_00515D58 = n + 1;
    }
    D_00515D54 = D_00515D58;
    for (i = 0; i < n; i++) {
        k = func_003C72F8_C630(&D_005175C8_C630[i], 4);
        for (j = 0; j < k; j++) {
            p += D_0044E870_C630[*p];
        }
        p += func_003C72F8_C630(&D_005175C8_C630[i + 6], 4) * 12;
    }
    D_005175F8 = p;
    k = func_003C72F8_C630(&D_005175C8_C630[n], 4);
    for (j = 0; j < k; j++) {
        p += D_0044E870_C630[*p];
    }
    D_005175FC = p;
    func_003CC070_C630(a0, data);
    D_00515B40_C630.f10 = func_003CBC58;
    D_00515B40_C630.fF = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CC848);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003CBEC8();
struct S_C848 { char pad[0xF]; char a; int b; };
extern struct S_C848 D_00515B40_C848 __asm__("D_00515B40");

void func_003CC848(void) {
    D_00515B40_C848.b = 0;
    func_003CBEC8();
    D_00515B40_C848.a = 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CC878);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC918);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00517604_C918[4] __asm__("D_00517604");

void func_003CC918(int arg0) {
    D_00517604_C918[0] = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC928);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00517608_C928[4] __asm__("D_00517608");

void func_003CC928(int arg0) {
    D_00517608_C928[0] = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC938);
#ifdef SKIP_ASM
typedef struct { int pad0; float x; float y; unsigned char *src; float *dst; } S_C938;
typedef union { short s; unsigned char c[2]; } U_C938;

void func_003CC938(S_C938 *s) {
    unsigned char b[2];
    unsigned int i;

    if (*s->src == 0xEE) {
        s->src++;
        b[0] = s->src[1];
        b[1] = s->src[0];
        s->src += 2;
        s->x = (float)*(short*)b;
        b[0] = s->src[1];
        b[1] = s->src[0];
        s->src += 2;
        s->y = (float)*(short*)b;
        for (i = 0; i < 0x1C; i++) {
            b[0] = s->src[1];
            b[1] = s->src[0];
            *s->dst = (float)*(short*)b;
            s->dst++;
            s->src += 2;
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CCA08);

INCLUDE_ASM("ealib/seg_2B4578", func_003CCA38);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCEF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517604_CEF0[])(void) __asm__("D_00517604");
int func_003CCEF0(void) {
    return D_00517604_CEF0[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517608_CF18[])(void) __asm__("D_00517608");
int func_003CCF18_CF18(int) __asm__("func_003CCF18");
int func_003CCF18_CF18(int a) {
    return D_00517608_CF18[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF40);
#ifdef SKIP_ASM
void *func_003CCF40(void *arg0) {
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x9C))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF60);
#ifdef SKIP_ASM
int func_003CCF60(void *arg0, int arg1, int arg2, int arg3) {
    if (arg1 == 0) {
        return -1;
    }
    if ((*(int *)((char*)(arg0) + (8))) != 0) {
        return -1;
    }
    (*(int *)((char*)(arg0) + (8))) = arg3;
    (*(int *)((char*)(arg0) + (0xC))) = arg2;
    (*(int *)((char*)(arg0) + (0xA0))) = arg1;
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_CF90 { int f0; int pending; int remaining; int fC; float *rd; char pad[0x10]; float buf[28]; int n; int pad2[3]; float *out; };
extern void func_003CCA08_CF90(int *) __asm__("func_003CCA08");

int func_003CCF90(struct S_CF90 *s, float **pout, int n) {
    int done = 0;
    int m;
    int k;
    int i;
    int rem;
    float *dst;

    s->out = *pout;
    if (s->remaining == 0) {
        return 0;
    }
    m = s->remaining;
    if (n < m) {
        m = n;
    }
    if (s->pending != 0) {
        if (m < s->pending) {
            k = m;
        } else {
            k = s->pending;
        }
        for (i = 0; i < k; i++) {
            *s->out = *s->rd;
            s->out++;
            s->rd++;
        }
        m -= k;
        s->remaining -= k;
        s->pending -= k;
        done = k;
    }
    i = m / 28 * 28;
    rem = m - i;
    s->n = i;
    if (i > 0) {
        done += i;
        func_003CCA08_CF90(&s->n);
        s->remaining -= i;
    }
    if (rem > 0) {
        dst = s->out;
        s->n = rem;
        s->out = s->buf;
        func_003CCA08_CF90(&s->n);
        s->remaining -= rem;
        s->rd = s->out + s->n;
        s->pending = -s->n;
        s->out -= 28;
        for (i = 0; i < rem; i++) {
            dst[i] = s->out[i];
        }
        done += rem;
    }
    if (s->remaining <= 0) {
        s->pending = 0;
    }
    return done;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { float x; float y; } V2_D138;
V2_D138 func_003CD138_D138(char *p) __asm__("func_003CD138");

V2_D138 func_003CD138_D138(char *p) {
    V2_D138 v;
    V2_D138 w;
    v.x = *(float *)(p + 0x98);
    v.y = *(float *)(p + 0x9C);
    w = v;
    return w;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD190);
#ifdef SKIP_ASM
void func_003CD190(void *arg0, void *arg1) {
    (*(float *)((char*)(arg0) + (0x98))) = (float) (*(float *)((char*)(arg1) + (0)));
    (*(float *)((char*)(arg0) + (0x9C))) = (float) (*(float *)((char*)(arg1) + (4)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD1A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517604_D1A8[])(void) __asm__("D_00517604");
int func_003CD1A8_D1A8(int) __asm__("func_003CD1A8");
int func_003CD1A8_D1A8(int a) {
    return D_00517604_D1A8[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD1D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517608_D1D0[])(void) __asm__("D_00517608");
int func_003CD1D0_D1D0(int) __asm__("func_003CD1D0");
int func_003CD1D0_D1D0(int a) {
    return D_00517608_D1D0[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD1F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct BS_D1F8 { unsigned char *ptr; unsigned int bits; int cnt; } BS_D1F8;
extern unsigned int D_0044E8C0_E8C0[] __asm__("D_0044E8C0");

int func_003CD1F8(BS_D1F8 *p, int n) {
    unsigned int v = p->bits;
    int ret = v & D_0044E8C0_E8C0[n];
    p->bits >>= n;
    p->cnt -= n;
    if (p->cnt < 8) {
        p->bits |= *p->ptr++ << p->cnt;
        p->cnt += 8;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD260);
#ifdef SKIP_ASM
typedef struct { unsigned char *p; unsigned int bits; int n; } B_D260;

void func_003CD260(B_D260 *b, int k) {
    unsigned int t = b->bits >> k;
    int n = b->n - k;
    b->bits = t;
    b->n = n;
    if (n < 8) {
        unsigned char *q = b->p;
        unsigned int c = *q;
        b->n = n + 8;
        b->p = q + 1;
        b->bits = t | (c << n);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CD2B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD518);
#ifdef SKIP_ASM
void func_003CD518(void *arg0) {
    int var_2;
    void *var_4;

    var_4 = arg0;
    var_2 = 0x6A;
    do {
        var_2 -= 2;
        (*(float *)((char*)(var_4) + (0))) = (float) ((((*(float *)((char*)(var_4) + (-4))) + (*(float *)((char*)(var_4) + (4)))) * 0.59738594f) + (((*(float *)((char*)(var_4) + (-0xC))) + (*(float *)((char*)(var_4) + (0xC)))) * -0.11459156f) + (((*(float *)((char*)(var_4) + (-0x14))) + (*(float *)((char*)(var_4) + (0x14)))) * 0.01803268f));
        var_4 += 8;
    } while (var_2 >= 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD590);
#ifdef SKIP_ASM
void func_003CD590(char *a_, void *out_) {
    float *a = (float *)a_;
    float *out = (float *)out_;
    float tmp[12];
    float y[12];
    int i, j;
    float s;
    for (j = 10; j >= 0; j--)
        tmp[j + 1] = a[j];
    tmp[0] = 1.0f;
    for (i = 0; i < 12; i++) {
        s = -a[11] * tmp[11];
        for (j = 10; j >= 0; j--) {
            s -= a[j] * tmp[j];
            tmp[j + 1] = a[j] * s + tmp[j];
        }
        tmp[0] = s;
        y[i] = s;
        { int k; for (k = 0; k < i; k++) s -= out[k] * y[i - k - 1]; }
        out[i] = s;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CD690);
#ifdef SKIP_ASM
extern void func_003CD590(char *, void *);
extern void func_003CE410(int, void *, char *, char *);

void func_003CD690(char *arg0, int arg1, int arg2) {
    char buf[0x30];

    func_003CD590(arg0 + 0x114, buf);
    func_003CE410(arg2, buf, arg0 + 0x144, arg0 + (arg1 * 4 + 0x684));
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CD6F0);

INCLUDE_ASM("ealib/seg_2B4578", func_003CD878);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CDDB8);
#ifdef SKIP_ASM
void *func_003CDDB8(void *arg0) {
    (*(int *)((char*)(arg0) + (0xD44))) = 0;
    (*(int *)((char*)(arg0) + (0xD64))) = 1;
    (*(int *)((char*)(arg0) + (0xD54))) = 0;
    (*(int *)((char*)(arg0) + (0xD58))) = 0;
    (*(short *)((char*)(arg0) + (0xD50))) = 0;
    (*(short *)((char*)(arg0) + (0xD52))) = 0;
    (*(int *)((char*)(arg0) + (0xD5C))) = 0;
    (*(int *)((char*)(arg0) + (0xD60))) = 0;
    return arg0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CDDE8);
#ifdef SKIP_ASM
extern void func_003CD6F0(char *, unsigned char *, char *, int);

int func_003CDDE8(char *arg0, unsigned char *arg1, int arg2, int arg3) {
    int temp_8;

    if (arg1 == 0) return -1;
    if (*(int *)(arg0 + 0xD54) != 0) return -1;
    temp_8 = *(int *)(arg0 + 0xD64);
    *(int *)(arg0 + 0xD54) = arg3;
    *(int *)(arg0 + 0xD58) = arg2;
    *(int *)(arg0 + 0xD44) = 0;
    *(unsigned char **)(arg0 + 0xD48) = arg1;
    if (temp_8 == 1) {
        if (*arg1 == 0xEE) {
            *(int *)(arg0 + 0xD60) = temp_8;
        } else {
            *(int *)(arg0 + 0xD60) = 0;
        }
        func_003CD6F0(arg0, arg1 + 1, arg0, *(int *)(arg0 + 0xD5C));
    } else {
        func_003CD6F0(arg0, arg1, arg0, *(int *)(arg0 + 0xD5C));
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CDE68);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE078);
#ifdef SKIP_ASM
struct V3_E078 { int a; int b; int c; };

struct V3_E078 func_003CE078(char *self) {
    struct V3_E078 t;
    t.a = *(int *)(self + 4);
    t.c = *(int *)(self + 0xD5C);
    t.b = *(int *)(self + 0xD44);
    return t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE0B8);
#ifdef SKIP_ASM
void func_003CE0B8(void *arg0, void *arg1) {
    (*(int *)((char*)(arg0) + (4))) = (int) (*(int *)((char*)(arg1) + (0)));
    (*(int *)((char*)(arg0) + (0xD5C))) = (int) (*(int *)((char*)(arg1) + (8)));
    (*(int *)((char*)(arg0) + (0xD44))) = (int) (*(int *)((char*)(arg1) + (4)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE0D8);
#ifdef SKIP_ASM
void func_003CE0D8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xD64))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE0E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A8E8_E0E0[] __asm__("D_0050A8E8");
typedef struct { char pad[0x28]; short f; char pad2[0x62]; } R_E0E0;
typedef struct { R_E0E0 arr[100]; } W_E0E0;

int func_003CE0E0(int arg0) {
    char *p = D_0050A8E8_E0E0;
    int temp_2;
    int temp_4;

    temp_4 = arg0 + *(unsigned char *)(p + 0x30) + *(unsigned char *)(p + 0x2F);
    temp_2 = (*(W_E0E0 **)(p + 0x1F0))->arr[temp_4].f;
    return (temp_2 == -1) ? temp_4 : temp_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE118);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A8E8_E118[] __asm__("D_0050A8E8");

struct E_E118 { char pad[0x28]; short f28; char pad2[0x8C - 0x2A]; };
struct R_E118 { struct E_E118 e[1]; };

int func_003CE118_impl(int arg0) __asm__("func_003CE118");
int func_003CE118_impl(int arg0) {
    short *var_3;
    int temp_2;
    int temp_4;
    int var_5;
    char *b = D_0050A8E8_E118;

    temp_4 = arg0 + *(unsigned char *)(b + 0x30) + *(unsigned char *)(b + 0x2F);
    temp_2 = ((struct R_E118 *)*(char **)(b + 0x1F0))->e[temp_4].f28;
    if (temp_2 == -1) {
        return 0;
    }
    var_3 = (short *)(temp_2 * 0x8C + *(int *)(b + 0x1F0) + 6);
    for (var_5 = 1; var_5 < 6; var_5++, var_3++) {
        if (*var_3 == temp_4) {
            return var_5;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE198);
#ifdef SKIP_ASM
int func_003CE198(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE1A0);
#ifdef SKIP_ASM
int func_003CE1A0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE1A8);
#ifdef SKIP_ASM
int func_003CE1A8(void) {
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CE1B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct {
    char pad0[4];
    short h[8];
    int f14;
    char pad18[0x23 - 0x18];
    unsigned char f23;
    unsigned short f24;
    char pad26[0x8C - 0x26];
} E_E1B0;
typedef struct {
    char pad0[0x2F];
    unsigned char f2F;
    unsigned char f30;
    char pad31[0x1F0 - 0x31];
    E_E1B0 *ents;
} G_E1B0;
typedef struct { char pad0[3]; unsigned char b3; } A6_E1B0;
typedef struct { char pad0[7]; unsigned char b7; char pad8[0x18 - 8]; int arr[8]; } A7_E1B0;
extern G_E1B0 D_0050A8E8_E1B0 __asm__("D_0050A8E8");
extern void func_003C8158_E1B0(int, int, int, int, unsigned int, int, int, int, int, int, int, int, int, int) __asm__("func_003C8158");
extern void func_003C25E0_E1B0(int) __asm__("func_003C25E0");
extern void func_003C38E0_E1B0(int) __asm__("func_003C38E0");
extern void func_003C27E0_E1B0(int, int) __asm__("func_003C27E0");
extern void func_003C3010_E1B0(int, int) __asm__("func_003C3010");
extern void func_003C30C8_E1B0(int, int) __asm__("func_003C30C8");
extern void func_003C3178_E1B0(int, int) __asm__("func_003C3178");
extern void func_003C3250_E1B0(int, int) __asm__("func_003C3250");
extern void func_003C83A0_E1B0(int) __asm__("func_003C83A0");

int func_003CE1B0(int arg0, int idx, int arg2, int arg3, int arg4, int arg5, A6_E1B0 *arg6, A7_E1B0 *arg7) {
    E_E1B0 *e;
    int i;

    e = &D_0050A8E8_E1B0.ents[idx];
    if (!(e->f24 & 8)) {
    if (e->f24 & 4) {
    for (i = 0; i < e->f23; i++) {
        func_003C8158_E1B0(e->h[i] - (D_0050A8E8_E1B0.f30 + D_0050A8E8_E1B0.f2F), arg6->b3, 0, 0, 0xFFFFFFFF,
                           arg7->arr[i], e->f23, e->f14, -1, -1, 0, 0, arg7->b7, i);
    }
    func_003C25E0_E1B0(e->h[0]);
    func_003C38E0_E1B0(e->h[0]);
    func_003C27E0_E1B0(e->h[0], 0);
    func_003C3010_E1B0(e->h[0], arg2);
    func_003C30C8_E1B0(e->h[0], arg3);
    func_003C3178_E1B0(e->h[0], arg4);
    func_003C3250_E1B0(e->h[0], arg5);
    for (i = 0; i < e->f23; i++) {
        func_003C83A0_E1B0(e->h[i] - (D_0050A8E8_E1B0.f30 + D_0050A8E8_E1B0.f2F));
    }
    }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE378);
#ifdef SKIP_ASM
struct S_E378 { char pad[0x304]; int *p[1]; };
extern struct S_E378 D_005157B8_E378 __asm__("D_005157B8");
extern struct { char pad[0x46]; unsigned char cnt; } D_0050A8E8_E378 __asm__("D_0050A8E8");
extern int func_003BA6E8_E378(int) __asm__("func_003BA6E8");

int func_003CE378_E378(int) __asm__("func_003CE378");
int func_003CE378_E378(int key) {
    int i;
    for (i = 0; i < D_0050A8E8_E378.cnt; i++) {
        int *q = D_005157B8_E378.p[i];
        if (q != 0 && func_003BA6E8_E378(*(volatile int *)q) == key) return i;
    }
    return -1;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CE410);

INCLUDE_ASM("ealib/seg_2B4578", func_003CE7C0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEB90);
#ifdef SKIP_ASM
void func_003CEB90(void *arg0) {
    (*(int *)((char*)(arg0) + (0xC0))) = 0;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    (*(int *)((char*)(arg0) + (0xC8))) = 0;
    (*(int *)((char*)(arg0) + (0xCC))) = 0;
    (*(int *)((char*)(arg0) + (0xD0))) = 0;
    (*(int *)((char*)(arg0) + (0xD4))) = 0;
    (*(int *)((char*)(arg0) + (0xD8))) = 0;
    (*(int *)((char*)(arg0) + (0xDC))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x18))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    (*(int *)((char*)(arg0) + (0x2C))) = 0;
    (*(int *)((char*)(arg0) + (0x90))) = 0;
    (*(int *)((char*)(arg0) + (0xA0))) = 0;
    (*(int *)((char*)(arg0) + (0xA4))) = 0;
    (*(int *)((char*)(arg0) + (0xB0))) = 0;
    (*(int *)((char*)(arg0) + (0xB4))) = 0;
    (*(int *)((char*)(arg0) + (0xB8))) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEBE8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (FIR filter over 4-float blocks: 12x4 banded matrix times sliding window).
void func_003CEBE8(char *p, int n, int src, int dst) {
    if (*(signed char *)(p + 0xFC) != 0) {
        float *m = (float *)p;
        float a = m[0xE0 / 4];
        float b = m[0xE4 / 4];
        float c = m[0xE8 / 4];
        float d = m[0xEC / 4];
        float e = m[0xF0 / 4];
        m[0] = a;
        m[5] = a;
        m[10] = a;
        m[15] = a;
        m[4] = b;
        m[9] = b;
        m[14] = b;
        m[19] = b;
        m[8] = c;
        m[13] = c;
        m[18] = c;
        m[23] = c;
        m[12] = d;
        m[17] = d;
        m[22] = d;
        m[27] = d;
        m[16] = e;
        m[21] = e;
        m[26] = e;
        m[31] = e;
        m[20] = d;
        m[25] = d;
        m[30] = d;
        m[35] = d;
        m[24] = c;
        m[29] = c;
        m[34] = c;
        m[39] = c;
        m[28] = b;
        m[33] = b;
        m[38] = b;
        m[43] = b;
        m[32] = a;
        m[37] = a;
        m[42] = a;
        m[47] = a;
        *(signed char *)(p + 0xFC) = 0;
    }
    __asm__ volatile(
        ".set push\n"
        ".set noreorder\n"
        "move         $6, %1\n"
        "move         $4, %0\n"
        "move         $5, %2\n"
        "sll          $6, $6, 2\n"
        "move         $7, %3\n"
        "move         $8, %4\n"
        "add          $6, $6, $7\n"
        "lqc2         $vf1, 0x0($4)\n"
        "lqc2         $vf2, 0x10($4)\n"
        "lqc2         $vf3, 0x20($4)\n"
        "lqc2         $vf4, 0x30($4)\n"
        "lqc2         $vf5, 0x40($4)\n"
        "lqc2         $vf6, 0x50($4)\n"
        "lqc2         $vf7, 0x60($4)\n"
        "lqc2         $vf8, 0x70($4)\n"
        "lqc2         $vf9, 0x80($4)\n"
        "lqc2         $vf10, 0x90($4)\n"
        "lqc2         $vf11, 0xA0($4)\n"
        "lqc2         $vf12, 0xB0($4)\n"
        "lqc2         $vf20, 0x0($5)\n"
        "lqc2         $vf21, 0x10($5)\n"
        "1:\n"
        "lqc2         $vf22, 0x0($7)\n"
        "lqc2         $vf23, 0x10($7)\n"
        "lqc2         $vf24, 0x20($7)\n"
        "lqc2         $vf25, 0x30($7)\n"
        "vmulax.xyzw  ACC, $vf1, $vf20x\n"
        "vmadday.xyzw ACC, $vf2, $vf20y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf20z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf20w\n"
        "vmaddax.xyzw ACC, $vf5, $vf21x\n"
        "vmadday.xyzw ACC, $vf6, $vf21y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf21z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf21w\n"
        "vmaddax.xyzw ACC, $vf9, $vf22x\n"
        "vmadday.xyzw ACC, $vf10, $vf22y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf22z\n"
        "vmaddw.xyzw  $vf28, $vf12, $vf22w\n"
        "vmulax.xyzw  ACC, $vf1, $vf21x\n"
        "vmadday.xyzw ACC, $vf2, $vf21y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf21z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf21w\n"
        "vmaddax.xyzw ACC, $vf5, $vf22x\n"
        "vmadday.xyzw ACC, $vf6, $vf22y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf22z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf22w\n"
        "vmaddax.xyzw ACC, $vf9, $vf23x\n"
        "vmadday.xyzw ACC, $vf10, $vf23y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf23z\n"
        "vmaddw.xyzw  $vf29, $vf12, $vf23w\n"
        "vmulax.xyzw  ACC, $vf1, $vf22x\n"
        "vmadday.xyzw ACC, $vf2, $vf22y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf22z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf22w\n"
        "vmaddax.xyzw ACC, $vf5, $vf23x\n"
        "vmadday.xyzw ACC, $vf6, $vf23y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf23z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf23w\n"
        "vmaddax.xyzw ACC, $vf9, $vf24x\n"
        "vmadday.xyzw ACC, $vf10, $vf24y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf24z\n"
        "vmaddw.xyzw  $vf30, $vf12, $vf24w\n"
        "vmulax.xyzw  ACC, $vf1, $vf23x\n"
        "vmadday.xyzw ACC, $vf2, $vf23y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf23z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf23w\n"
        "vmaddax.xyzw ACC, $vf5, $vf24x\n"
        "vmadday.xyzw ACC, $vf6, $vf24y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf24z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf24w\n"
        "vmaddax.xyzw ACC, $vf9, $vf25x\n"
        "vmadday.xyzw ACC, $vf10, $vf25y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf25z\n"
        "vmaddw.xyzw  $vf31, $vf12, $vf25w\n"
        "addi         $7, $7, 0x40\n"
        "sqc2         $vf28, 0x0($8)\n"
        "sqc2         $vf29, 0x10($8)\n"
        "sqc2         $vf30, 0x20($8)\n"
        "sqc2         $vf31, 0x30($8)\n"
        "vmove.xyzw   $vf20, $vf24\n"
        "vmove.xyzw   $vf21, $vf25\n"
        "bne          $6, $7, 1b\n"
        "addi         $8, $8, 0x40\n"
        "sqc2         $vf20, 0x0($5)\n"
        "sqc2         $vf21, 0x10($5)\n"
        ".set pop\n"
        :
        : "r"(p), "r"(n), "r"(p + 0xC0), "r"(src), "r"(dst)
        : "$4", "$5", "$6", "$7", "$8", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEE08);
#ifdef SKIP_ASM
extern void func_003CEBE8(char *, int, int, int);
int func_003CEE08(char *arg0, int arg1, int arg2, int arg3) {
    int **obj = *(int ***)(arg0 + 8);
    int r;
    if (obj == 0 || (r = ((int (*)(int **, int, int, int, unsigned char))(*obj))(obj, arg1, arg3, arg2, *(unsigned char *)(arg0 + 0x1A)), r > 0)) {
        func_003CEBE8(arg0 + 0x20, arg1, arg2, arg3);
        r = arg1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CEE88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; int f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int pad1c; char sub[1]; } S_EE88;
extern void func_003CEB90(void *);
extern void func_003CEE08_x(void) __asm__("func_003CEE08");

int func_003CEE88(S_EE88 *self) {
    self->vt = func_003CEE08_x;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f4 = 0;
    func_003CEB90(&self->sub);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEED0);
#ifdef SKIP_ASM
extern void func_003CE7C0_EED0(char *, int) __asm__("func_003CE7C0");

void func_003CEED0(char *arg0, int *arg1) {
    float a = (float)(arg1[0] >> 8);
    *(float *)(arg0 + 0x118) = (a + a) / (float)(arg1[1] >> 8);
    func_003CE7C0_EED0(arg0 + 0x20, 2);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEF20);
#ifdef SKIP_ASM
// Identical copy of func_003CA900.
extern void func_003CEBE8_EF20(void *, int, int, int) __asm__("func_003CEBE8");

int func_003CEF20(char *p, int arg1, int arg2, int arg3) {
    int (**obj)(void *, int, int, int, int);
    int n;
    obj = *(int (***)(void *, int, int, int, int))(p + 8);
    if (obj != 0) {
        n = (*obj)(obj, arg1, arg3, arg2, *(unsigned char *)(p + 0x1A));
        if (n <= 0) {
            return n;
        }
    } else {
        n = arg1;
    }
    func_003CEBE8_EF20(p + 0x20, n, arg2, arg3);
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CEFB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; int f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int pad1c; char sub[1]; } S_EFB0;
extern void func_003CEB90(void *);
extern void func_003CEF20_x(void) __asm__("func_003CEF20");

int func_003CEFB0(S_EFB0 *self) {
    self->vt = func_003CEF20_x;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f4 = 0;
    func_003CEB90(&self->sub);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEFF8);
#ifdef SKIP_ASM
extern void func_003CE7C0_EFF8(char *, int) __asm__("func_003CE7C0");

void func_003CEFF8(char *arg0, int *arg1) {
    float x = (float)(arg1[0] >> 7);
    float y = (float)(arg1[1] >> 7);
    float d = (float)(arg1[2] >> 8);
    *(float *)(arg0 + 0x114) = x / d;
    *(float *)(arg0 + 0x118) = y / d;
    func_003CE7C0_EFF8(arg0 + 0x20, 4);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CF060);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF128);
#ifdef SKIP_ASM
extern void func_003CF060();

int func_003CF128(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(void (**)())((char*)(arg0) + (0))) = func_003CF060;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(signed char *)((char*)(arg0) + (0x1B))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF158);
#ifdef SKIP_ASM
void func_003CF158(void *arg0, int *arg1) {
    (*(float *)((char*)(arg0) + (0x1C))) = (float) ((float) *arg1 * 0.00390625f);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CF178);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF298);
#ifdef SKIP_ASM
extern void func_003B5E98(int);

void func_003CF298(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003B5E98(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF2C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF178_F2C0(void) __asm__("func_003CF178");
void func_003CF298_F2C0(void) __asm__("func_003CF298");

int func_003CF2C0(char *arg0) {
    *(void (**)(void))(arg0 + 4) = func_003CF298_F2C0;
    *(void (**)(void))(arg0 + 0) = func_003CF178_F2C0;
    *(int *)(arg0 + 8) = 0;
    *(int *)(arg0 + 0xC) = 0;
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
    *(signed char *)(arg0 + 0x1B) = 0;
    *(int *)(arg0 + 0x1C) = 0;
    *(int *)(arg0 + 0x20) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF300);
#ifdef SKIP_ASM
struct S_F300 { char p0[0x1C]; int f1C; float f20; float f24; float f28; float f2C; float f30; char p34[4]; float f38; float f3C; };
void func_003CF300(void *sv, int n, int in_, int out_) {
    struct S_F300 *s = (struct S_F300 *)sv;
    float *in = (float *)in_;
    float *out = (float *)out_;
    int h = s->f1C;
    float t, a, b, v;
    if (s->f24 < (2.0f * (float)h) / 3.1415927f && (t = s->f20, t > 0.0f) && t < (float)(h >> 1)) {
        if (n > 0) {
            do {
                a = s->f28;
                n -= 1;
                b = s->f30 * (*in + 1e-20f);
                in += 1;
                *out = (b + (2.0f * a * s->f2C * s->f38)) - (a * a * s->f3C);
                s->f3C = s->f38;
                t = *out;
                out += 1;
                s->f38 = t;
            } while (n != 0);
        }
    } else if (n > 0) {
        do {
            v = *in;
            n -= 1;
            in += 1;
            *out = v;
            out += 1;
        } while (n != 0);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF408);
#ifdef SKIP_ASM
extern void func_003CF300(void *, int, int, int);

int func_003CF408(char *p, int arg1, int arg2, int arg3) {
    int (**obj)(void *, int, int, int, int);
    int n;
    obj = *(int (***)(void *, int, int, int, int))(p + 8);
    if (obj != 0) {
        n = (*obj)(obj, arg1, arg3, arg2, *(unsigned char *)(p + 0x1A));
        if (n <= 0) {
            return n;
        }
    } else {
        n = arg1;
    }
    func_003CF300(p, n, arg2, arg3);
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF408_F498(void) __asm__("func_003CF408");

int func_003CF498(char *arg0) {
    *(int *)(arg0 + 8) = 0;
    *(void (**)(void))(arg0 + 0) = func_003CF408_F498;
    *(int *)(arg0 + 0xC) = 0;
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
    *(signed char *)(arg0 + 0x1B) = 0;
    *(int *)(arg0 + 4) = 0;
    *(int *)(arg0 + 0x34) = 0;
    *(int *)(arg0 + 0x38) = 0;
    *(int *)(arg0 + 0x3C) = 0;
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF4D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern float f_C840_F4D0(float) __asm__("func_003BC840");
extern float f_FA98_F4D0(float) __asm__("func_003CFA98");
void func_003CF4D0(void *arg0, void *arg1) {
    float fa, fb, fc, fd, f21, f0, r;
    int ia = (*(int *)((char*)arg1 + 0)) >> 8;
    int ib = (*(int *)((char*)arg1 + 4)) >> 8;
    int ic = (*(int *)((char*)arg1 + 8)) >> 8;
    fa = (float)ia;
    fd = (float)(*(int *)((char*)arg1 + 0xC));
    fc = (float)ic;
    fb = (float)ib;
    *(int *)((char*)arg0 + 0x1C) = ib;
    *(float *)((char*)arg0 + 0x20) = fa;
    fd = fd * 0.00390625f;
    *(float *)((char*)arg0 + 0x24) = fc;
    f0 = 1.0f - (fc * 3.1415927f) / fb;
    *(float *)((char*)arg0 + 0x28) = f0;
    f21 = f0 * f0;
    r = (2.0f * *(float *)((char*)arg0 + 0x28)) / (f21 + 1.0f) * f_C840_F4D0((fa * 6.2831855f) / fb);
    *(float *)((char*)arg0 + 0x2C) = r;
    *(float *)((char*)arg0 + 0x30) = (1.0f - f21) * fd * f_FA98_F4D0(-r * r);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF5D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B5C60_F5D0(int) __asm__("func_003B5C60");
extern void func_003B5E98_F5D0(int) __asm__("func_003B5E98");
extern void func_003C51E8_F5D0(char *, char *, int) __asm__("func_003C51E8");

int func_003CF5D0(char *self, int n, char *a2, char *a3) {
    int bytes, p, r;
    int *obj;
    if (*(short *)(self + 0x24) != 0) {
        *(short *)(self + 0x24) = 0;
        *(short *)(self + 0x26) = 1;
    }
    bytes = n * 4;
    if (*(int *)(self + 0x20) < n) {
        p = *(int *)(self + 0x1C);
        if (p != 0) {
            func_003B5E98_F5D0(p);
        }
        *(int *)(self + 0x1C) = func_003B5C60_F5D0(bytes);
        *(int *)(self + 0x20) = n;
    }
    if (*(short *)(self + 0x26) != 0) {
        int (**vt)(void *, int, char *, char *, int) = *(int (***)(void *, int, char *, char *, int))(self + 8);
        r = (*vt)(vt, n, a3, a2, 1);
        if (r <= 0) {
            return r;
        }
        func_003C51E8_F5D0(a3, a2, bytes);
        func_003C51E8_F5D0(*(char **)(self + 0x1C), a2, bytes);
        *(short *)(self + 0x26) = 0;
    } else {
        func_003C51E8_F5D0(a3, *(char **)(self + 0x1C), bytes);
        *(short *)(self + 0x24) = 1;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF6D0);
#ifdef SKIP_ASM
extern void func_003B5E98(int);

void func_003CF6D0(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003B5E98(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF6F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; void *f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int f1c; int f20; short f24; short f26; } S_F6F8;
extern void f_F6F8_a(void) __asm__("func_003CF5D0");
extern void f_F6F8_b(void) __asm__("func_003CF6D0");

int func_003CF6F8(S_F6F8 *self) {
self->f26 = 1;
    self->f4 = f_F6F8_b;
    self->vt = f_F6F8_a;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f20 = 0;
    self->f1c = 0;
    self->f24 = 0;
    self->f8 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF740);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C51E8_F740(void *, void *, int) __asm__("func_003C51E8");

int func_003CF740(char *self, int n, int arg2, void *dst) {
    func_003C51E8_F740(dst, *(char **)(self + 0x1C), n * 4);
    *(char **)(self + 0x1C) += n * 4;
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF798);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF740_F798(void) __asm__("func_003CF740");

void func_003CF798(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x1C) = arg1;
    *(int *)((char *)arg0 + 4) = 0;
    *(void (**)(void))((char *)arg0 + 0) = func_003CF740_F798;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF7B0);
#ifdef SKIP_ASM
int func_003CF7B0(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(signed char *)((char*)(arg0) + (0x1B))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CF7D0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF958);
#ifdef SKIP_ASM
void func_003B5E98(int);

void func_003CF958(char *arg0) {
    int temp_4;

    temp_4 = *(int *)(arg0 + 0x20);
    if (temp_4 != 0) {
        func_003B5E98(temp_4);
        *(int *)(arg0 + 0x20) = 0;
        *(int *)(arg0 + 0x1C) = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF998);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF7D0_F998(void) __asm__("func_003CF7D0");
void func_003CF958_F998(void) __asm__("func_003CF958");

int func_003CF998(char *arg0) {
    *(void (**)(void))(arg0 + 4) = func_003CF958_F998;
    *(void (**)(void))(arg0 + 0) = func_003CF7D0_F998;
    *(int *)(arg0 + 8) = 0;
    *(int *)(arg0 + 0xC) = 0;
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
    *(signed char *)(arg0 + 0x1B) = 0;
    *(int *)(arg0 + 0x20) = 0;
    *(int *)(arg0 + 0x1C) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF9D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_F958_F9D8(void) __asm__("func_003CF958");
extern int f_FB38_F9D8(int, int) __asm__("func_003CFB38");
extern char *f_5C60_F9D8(int) __asm__("func_003B5C60");
extern void f_6210_F9D8(char *, int, int) __asm__("func_00416210");
void func_003CF9D8(void *arg0, void *arg1) {
    float temp_f0;
    int temp_16;
    int temp_16_2;
    int temp_17;
    int temp_18;
    int temp_2;
    char *temp_2_2;
    int temp_3;

    temp_16 = (*(int *)((char*)(arg1) + (0))) >> 1;
    temp_17 = (*(int *)((char*)(arg1) + (4))) >> 8;
    temp_18 = (*(int *)((char*)(arg1) + (8))) >> 8;
    f_F958_F9D8();
    temp_f0 = (float) temp_16 * 0.007874016f;
    (*(float *)((char*)(arg0) + (0x30))) = temp_f0;
    (*(float *)((char*)(arg0) + (0x34))) = -temp_f0;
    temp_2 = f_FB38_F9D8(temp_17, temp_18);
    temp_16_2 = temp_2 * 4;
    (*(int *)((char*)(arg0) + (0x28))) = temp_2;
    temp_2_2 = f_5C60_F9D8(temp_16_2 + 0x10);
    (*(char **)((char*)(arg0) + (0x20))) = temp_2_2;
    temp_3 = ((unsigned int) ((int)temp_2_2 + 0xF) >> 4) * 0x10;
    (*(int *)((char*)(arg0) + (0x1C))) = temp_3;
    f_6210_F9D8((char*)temp_3, 0, temp_16_2);
    (*(int *)((char*)(arg0) + (0x24))) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFA98);
#ifdef SKIP_ASM
float func_003CFA98(float fparg0) {
    float temp_f0;
    float temp_f1;
    float temp_f2;
    float temp_f4;
    float temp_f5;
    float temp_f6;

    temp_f0 = fparg0 * 0.5f;
    temp_f1 = temp_f0 * -0.25f * fparg0;
    temp_f2 = temp_f1 * -0.5f * fparg0;
    temp_f4 = temp_f2 * -0.625f * fparg0;
    temp_f5 = temp_f4 * -0.7f * fparg0;
    temp_f6 = temp_f5 * -0.75f * fparg0;
    return temp_f0 + 1.0f + temp_f1 + temp_f2 + temp_f4 + temp_f5 + temp_f6 + (temp_f6 * -0.7857f * fparg0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFB38);
#ifdef SKIP_ASM
extern int func_003CFB98(int, int);

int func_003CFB38(int arg0, int arg1) {
    return func_003CFB98(arg0, arg1 / 16) * 16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFB68);
#ifdef SKIP_ASM
int func_003CFB68(int n) {
    int i = 0, sq;
    for (;;) {
        sq = i * i;
        i++;
        if (sq != n) {
            if (n < sq) return i - 2;
        } else
            return i - 1;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFB98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CFB68_FB98(int) __asm__("func_003CFB68");

int func_003CFB98(int arg0, int arg1) {
    int lim;
    int t;
    int n;
    int d;

    t = (int) (arg1 * arg0) / 1000;
    n = (t <= 2) ? 3 : t;
    for (;;) {
        lim = func_003CFB68_FB98(n) + 1;
        for (d = 2; lim >= d; d++) {
            if ((n % d) == 0) {
                n += 1;
                break;
            }
            if (d == lim) {
                return n;
            }
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CFC30);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0B18);
#ifdef SKIP_ASM
typedef struct { int a, b, c, d; } E_0B18;
typedef struct { int p0, p1, p2; unsigned lo : 16; unsigned idx : 6; unsigned hi : 10; E_0B18 e[1]; } Q_0B18;

void func_003D0B18(Q_0B18 *q, E_0B18 *src) {
    E_0B18 *arr = q->e;
    unsigned i = q->idx;
    q->idx = i + 1;
    arr[i] = *src;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0B78);
#ifdef SKIP_ASM
void func_003D0B78_impl(char *base, int n, char *lim) __asm__("func_003D0B78");
void func_003D0B78_impl(char *base, int n, char *lim) {
    int depth = 0;
    char *e = base + 0x10;
    while (e <= lim && n >= 0) {
        if (((unsigned char *)e)[9] == 1) {
            unsigned m = *(unsigned *)(e + 8) & 0x300000;
            if (m == 0x100000) {
                depth++;
            } else if (m == 0x300000) {
                if (depth-- < 1) {
                    n--;
                }
            } else if (m == 0x200000) {
                if (depth-- < 1) {
                    n--;
                }
            }
        }
        if (n < 1) {
            *(unsigned *)(e + 8) |= 0x4000000;
        }
        e += 0x10;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0C20);
#ifdef SKIP_ASM
void func_003D0C20(unsigned char *a0, unsigned char *a1) {
    unsigned char *p = a0 + 0x10;

    while (a1 >= p && p[9] != 1) {
        *(unsigned int *)(p + 8) |= 0x04000000;
        p += 0x10;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0C78);
#ifdef SKIP_ASM
void func_003D0C78(int arg0, unsigned int arg1) {
    unsigned int temp_4;

    temp_4 = arg0 + 0x10;
    if (arg1 >= temp_4) {
        (*(int *)((char*)(temp_4) + (8))) = (int) ((*(int *)((char*)(temp_4) + (8))) | 0x04000000);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0CA0);
#ifdef SKIP_ASM
extern void func_003D0CC8(int);
extern int func_003D5290();

void func_003D0CA0(void) {
    func_003D0CC8(func_003D5290());
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0CC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D32B8_0CC8(char *, int *) __asm__("func_003D32B8");
extern int D_0044F438_0CC8[] __asm__("D_0044F438");
extern char *D_0044F420_0CC8[] __asm__("D_0044F420");
int func_003D0CC8_0CC8(char *arg0) __asm__("func_003D0CC8");

int func_003D0CC8_0CC8(char *arg0) {
    int buf[8];
    unsigned int t;
    int r;
    if (arg0 == 0) {
        return 1;
    }
    {
        t = *(unsigned int *)(arg0 + 0x4C);
        *(int *)(arg0 + 0x100) = 2;
        if (t != 0) {
            if ((unsigned int)D_0044F438_0CC8[0] >= t) {
                *(int *)(arg0 + 0x100) = 4;
            } else {
                *(int *)(arg0 + 0x100) = 3;
            }
            goto done;
        }
        if (*(short *)(arg0 + 0x36) >= 0) {
            *(int *)(arg0 + 0x100) = 7;
            if (func_003D32B8_0CC8(arg0, buf) >= 0
                && (unsigned int)(*(int *)(arg0 + 0x24) + *(int *)(D_0044F420_0CC8[0] + 0xC)) >= (unsigned int)buf[6]) {
                *(int *)(arg0 + 0x100) = 5;
            }
        }
done:
        r = *(int *)(arg0 + 0x100);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0D70);
#ifdef SKIP_ASM
extern int func_003D5450_0D70(int) __asm__("func_003D5450");
extern int D_0044F420_0D70[] __asm__("D_0044F420");
struct P_0D70 { char pad[0x58]; unsigned char *a[24]; };
extern unsigned char D_0044F42C_0D70[] __asm__("D_0044F42C");
extern int D_0044F430_0D70[] __asm__("D_0044F430");
extern char D_00517644_0D70[] __asm__("D_00517644");

int func_003D0D70(unsigned int mask, unsigned int val) {
    int i, j;
    unsigned int fl, t, u;
    if (D_0044F42C_0D70[0] == 0) {
        return -18;
    }
    if (D_0044F430_0D70[0] != 0) {
        return -18;
    }
    if (func_003D5450_0D70(-1) == 0) {
        return -18;
    }
    if (val < 0x80) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(D_00517644_0D70 + i * 0x928) != 0) {
                fl = *(unsigned int *)(D_00517644_0D70 + i * 0x928 - 4);
                t = fl & 0xF0000000;
                if ((t & mask) != 0 && (u = fl & 0x0F000000, (u & mask) != 0)) {
                    if (func_003D5450_0D70(i & 0xFF) != 0) {
                        for (j = 0; j < 24; j++) {
                            unsigned char *e = ((struct P_0D70 *)D_0044F420_0D70[0])->a[j];
                            if (e != 0) {
                                unsigned char t2 = e[1];
                                e[1] = val;
                                e[2] = t2;
                            }
                        }
                    }
                }
            }
        }
    }
    D_0044F430_0D70[0] = 0;
    D_0044F420_0D70[0] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0ED0);
#ifdef SKIP_ASM
struct Ev_0ED0 { int w0; char pad4[4]; signed char b8; unsigned char b9; short hA; short hC; signed char bE; char pF; };
struct Q_0ED0 { int p[4]; };
struct P_0ED0 { unsigned int x30; int x34; char pad2[0x928 - 8]; };
extern unsigned char D_0044F42C_0ED0 __asm__("D_0044F42C");
extern int D_0044F430_0ED0 __asm__("D_0044F430");
extern int D_0044F420_0ED0 __asm__("D_0044F420");
extern struct P_0ED0 D_00517610_0ED0[4] __asm__("D_00517610");
extern int f5450_0ED0(int) __asm__("func_003D5450");
extern void f6210_0ED0(void *, int, int) __asm__("func_00416210");
extern void f0B18_0ED0(void *, void *) __asm__("func_003D0B18");
extern char *fcopy_0ED0(void *) __asm__("PATHI_copyevent");
extern int f1F80_0ED0(unsigned int, char *) __asm__("func_003D1F80");

int func_003D0ED0(unsigned int arg0, int arg1) {
    struct Ev_0ED0 ev;
    struct Q_0ED0 q;
    unsigned int i;
    unsigned int fl, t, u;
    char *base;
    struct P_0ED0 *p;
    if (D_0044F42C_0ED0 == 0 || D_0044F430_0ED0 != 0 || f5450_0ED0(-1) == 0) {
        return -18;
    }
    f6210_0ED0(&q, 0, 0x10);
    i = 0;
    f6210_0ED0(&ev, 0, 0x10);
    ev.w0 = arg0;
    ev.b9 = 4;
    ev.bE = ev.b8 = -1;
    ev.hC = arg1;
    f0B18_0ED0(&q, &ev);
    base = (char *)D_00517610_0ED0;
    p = (struct P_0ED0 *)(base + 0x30);
    do {
        if (p->x34 != 0) {
            fl = p->x30;
            t = fl & 0xF0000000;
            if ((t & arg0) != 0 && (u = fl & 0x0F000000, (u & arg0) != 0)) {
                if (f5450_0ED0(i & 0xFF) != 0) {
                    f1F80_0ED0(arg0, fcopy_0ED0(&q));
                }
            }
        }
        i++;
        p++;
    } while (i < 4);
    D_0044F430_0ED0 = 0;
    D_0044F420_0ED0 = 0;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D1038);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D11B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Info_11B8 {
    int a;
    int b;
    int c;
    unsigned int total;
    unsigned int f10;
    unsigned int f14;
    unsigned int len;
    unsigned int f1C;
    unsigned int f20;
    int f24;
    int f28;
};
struct Ent_11B8 { int a; int b; int c; int key; };
struct Fmt_11B8 {
    unsigned int pad0 : 20;
    unsigned int ch : 4;
    unsigned int mul : 4;
    unsigned int pad1 : 4;
};
struct Rec_11B8 { int w0; unsigned int w; };
struct S_11B8 {
    char pad0[0x20];
    unsigned int pad20a : 14;
    unsigned int n : 5;
    unsigned int pad20b : 13;
    char pad24[0x36 - 0x24];
    short f36;
    char pad38[0x54 - 0x38];
    int f54;
    char pad58[0xDC - 0x58];
    char name[0xFC - 0xDC];
    struct Ent_11B8 *tbl;
};
struct G_11B8 {
    char pad0[0x34];
    char *hdr;
    short *a;
};
extern unsigned char D_0044F42C_11B8 __asm__("D_0044F42C");
extern int D_0044F430_11B8 __asm__("D_0044F430");
extern int D_0044F43C_11B8 __asm__("D_0044F43C");
extern struct G_11B8 *D_0044F420_11B8 __asm__("D_0044F420");
extern char D_00495B10_11B8[] __asm__("D_00495B10");
extern int f_5450_11B8(int) __asm__("func_003D5450");
extern struct S_11B8 *f_5290_11B8(unsigned int) __asm__("func_003D5290");
extern int f_4BB0_11B8(unsigned int) __asm__("func_003D4BB0");
extern int f_F2F0_11B8(int, int *, int *, int) __asm__("func_002AF2F0");
extern void f_1658_11B8(char *, char *, int) __asm__("func_003D1658");

int func_003D11B8_impl(unsigned int id, struct Info_11B8 *info) __asm__("func_003D11B8");
int func_003D11B8_impl(unsigned int id, struct Info_11B8 *info) {
    int ret;
    struct S_11B8 *s;
    struct G_11B8 *g;
    struct Rec_11B8 *r;
    unsigned int i;
    unsigned int total;
    unsigned int q;
    int off;
    int len;

    ret = -8;
    if (D_0044F42C_11B8 == 0 || D_0044F430_11B8 != 0 || f_5450_11B8(-1) == 0) {
        return -18;
    }
    info->a = -1;
    info->b = -1;
    info->c = -1;
    info->total = 0;
    info->f10 = 0;
    info->f14 = 0;
    info->len = 0;
    info->f20 = 0;
    info->f1C = 0;
    info->f24 = -1;
    info->f28 = -1;
    s = f_5290_11B8(id);
    if (s == 0) {
        goto done;
    }
    if (f_4BB0_11B8(id & 0xFF000000) != 0) {
        ret = f_F2F0_11B8(s->f54, &off, &len, 0);
        if (ret >= 0) {
            info->len = len;
            info->total = off + len;
            info->f24 = s->f36;
            for (i = 0; i < s->n; i++) {
                if (s->tbl[i].key == ret) {
                    g = D_0044F420_11B8;
                    info->a = s->tbl[i].a;
                    total = info->total;
                    info->c = s->tbl[i].c;
                    r = (struct Rec_11B8 *)(g->hdr + g->a[info->a] * 4);
                    q = total;
                    if (r->w & 0xF00000) {
                        info->f10 = total / ((r->w >> 20) & 0xF);
                        q = total / ((r->w >> 20) & 0xF);
                        if (r->w & 0xF000000) {
                            info->f14 = total / (((r->w >> 24) & 0xF) * ((r->w >> 20) & 0xF));
                            total = total / (((r->w >> 24) & 0xF) * ((r->w >> 20) & 0xF));
                        }
                    }
                    if (q != 0) {
                        info->f1C = info->len % q;
                    } else {
                        info->f1C = 0;
                    }
                    if (total != 0) {
                        info->f20 = info->len % total;
                    } else {
                        info->f20 = 0;
                    }
                    goto done;
                }
            }
            if (D_0044F43C_11B8 & 0x100) {
                f_1658_11B8(D_00495B10_11B8, s->name, ret);
            }
        }
    }
done:
    D_0044F430_11B8 = 0;
    D_0044F420_11B8 = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1470);
#ifdef SKIP_ASM
extern int func_003D5450_1470(int) __asm__("func_003D5450");
extern void func_002AF838_1470(int) __asm__("func_002AF838");
struct E_1470 { char pad0[0x36]; short h36; char pad38[0x1C]; int f54; };
struct P_1470 { char pad0[0x58]; struct E_1470 *a[24]; };
extern struct P_1470 *D_0044F420_1470 __asm__("D_0044F420");
extern unsigned char D_0044F42C_1470 __asm__("D_0044F42C");
extern int D_0044F430_1470 __asm__("D_0044F430");
extern char D_00517640_1470[] __asm__("D_00517640");
extern char D_00517644_1470[] __asm__("D_00517644");

void func_003D1470_impl(unsigned int mask) __asm__("func_003D1470");
void func_003D1470_impl(unsigned int mask) {
    int i;
    int j;
    int next;
    unsigned int fl, t, u;
    struct P_1470 *g;
    int off;
    char *np;
    char *b4;
    unsigned int nv;
    struct E_1470 *e;
    if (D_0044F42C_1470 == 0) return;
    if (D_0044F430_1470 != 0) return;
    if (func_003D5450_1470(-1) == 0) return;
    i = 0;
    do { b4 = D_00517644_1470; } while (0);
    do {
        off = (u = 0x928);
        off = i * off;
        np = D_00517640_1470;
        next = i + 1;
        if (*(int *)(off + (int)b4) != 0) {
            fl = *(unsigned int *)(np + off);
            nv = fl & 0xF0000000;
            do { t = nv; } while (0);
            if ((t & mask) != 0 && (u = fl & 0x0F000000, (u & mask) != 0)) {
                if (func_003D5450_1470(i) != 0) {
                    for (j = 0; j < 24; j++) {
                        g = D_0044F420_1470;
                        e = g->a[j];
                        if (e != 0) {
                            func_002AF838_1470(e->f54);
                            e->h36 = -1;
                        }
                    }
                }
            }
        }
        i = next;
    } while (i < 4);
    D_0044F420_1470 = 0;
    D_0044F430_1470 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D15C8);
#ifdef SKIP_ASM
int func_003D15C8(int arg0, int arg1) {
    char *t = (char *)func_003D5290();
    if (t == 0) {
        return -8;
    }
    *(int *)(t + 0x24) = arg1 & 0xFFFF;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1608);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned int D_0044F430_1608[] __asm__("D_0044F430");
extern void func_00411310_1608(int, ...) __asm__("func_00411310") __attribute__((noreturn));

void func_003D1608(int a, ...) {
    D_0044F430_1608[0] = 0xFFFFFFFF;
    func_00411310_1608(0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1658);
#ifdef SKIP_ASM
void func_003D1658(int a, ...) {
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1690);
#ifdef SKIP_ASM
void func_003D1690(int a, ...) {
}
#endif

void func_003D16C8(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D16D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044F43C_16D0[4] __asm__("D_0044F43C");

int func_003D16D0_16D0(void) __asm__("func_003D16D0");
int func_003D16D0_16D0(void) {
    return D_0044F43C_16D0[0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D16E0);
#ifdef SKIP_ASM
int func_003D16E0(int arg0) {
    return arg0;
}
#endif

void func_003D16E8(void) {
}

INCLUDE_ASM("ealib/seg_2B4578", func_003D16F0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1940);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003D1BA8_1940(int, int) __asm__("func_003D1BA8");
extern int func_003D5450_1940(int) __asm__("func_003D5450");
extern int D_0044F420_1940[] __asm__("D_0044F420");
extern unsigned char D_0044F42C_1940[] __asm__("D_0044F42C");
extern int D_0044F430_1940[] __asm__("D_0044F430");
extern char D_00517644_1940[] __asm__("D_00517644");

struct P_1940 { char pad[0xDC]; int a[16]; };

void func_003D1940(unsigned int mask) {
    int i, j;
    unsigned int fl, t, u;
    if (D_0044F42C_1940[0] != 0) {
        if (D_0044F430_1940[0] == 0) {
            if (func_003D5450_1940(-1) != 0) {
                for (i = 0; i < 4; i++) {
                    if (*(int *)(D_00517644_1940 + i * 0x928) != 0) {
                        fl = *(unsigned int *)(D_00517644_1940 + i * 0x928 - 4);
                        t = fl & 0xF0000000;
                        if ((t & mask) != 0 && (u = fl & 0x0F000000, (u & mask) != 0)) {
                            if (func_003D5450_1940(i & 0xFF) != 0) {
                                for (j = 0; j < 0x10; j++) {
                                    if (((struct P_1940 *)D_0044F420_1940[0])->a[j] != 0) {
                                        func_003D1BA8_1940(j, 2);
                                    }
                                }
                            }
                        }
                    }
                }
                D_0044F420_1940[0] = 0;
                D_0044F430_1940[0] = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1A88);
#ifdef SKIP_ASM
extern int func_003D5450_1A88(int) __asm__("func_003D5450");
struct P_1A88 { char pad[0x30]; unsigned m_a; int m_b; char pad2[0x928 - 0x38]; };
struct G_1A88 { char pad[0xDC]; int a[16]; };
extern struct P_1A88 D_7610_1A88[4] __asm__("D_00517610");
extern struct G_1A88 *D_0044F420_1A88 __asm__("D_0044F420");
extern unsigned char D_0044F42C_1A88 __asm__("D_0044F42C");
extern int D_0044F430_1A88 __asm__("D_0044F430");

int func_003D1A88_impl(unsigned int mask) __asm__("func_003D1A88");
int func_003D1A88_impl(unsigned int mask) {
    int n = 0;
    int i;
    int j;
    if (D_0044F42C_1A88 == 0 || D_0044F430_1A88 != 0 || func_003D5450_1A88(-1) == 0) {
        return -0x12;
    }
    mask &= 0x0F000000;
    for (i = 0; i < 4; i++) {
        if (D_7610_1A88[i].m_b != 0 && (D_7610_1A88[i].m_a & mask) != 0 && func_003D5450_1A88(i & 0xFF) != 0) {
            for (j = 0; j < 16; j++) {
                if (D_0044F420_1A88->a[j] != 0) {
                    n++;
                }
            }
            break;
        }
    }
    D_0044F430_1A88 = 0;
    D_0044F420_1A88 = 0;
    return n;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D1BA8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1D28);
#ifdef SKIP_ASM
struct H_1D28 {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int pad : 16;
    unsigned int end : 6;
    unsigned int start : 6;
    unsigned int rest : 4;
};
struct E_1D28 {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
};
struct G_1D28 { char pad[0xDC]; struct H_1D28 *h[1]; };
extern struct G_1D28 *D_0044F420_1D28 __asm__("D_0044F420");
extern unsigned int D_0044F438_1D28 __asm__("D_0044F438");
extern int func_003CFC30_1D28(struct H_1D28 *, struct E_1D28 *) __asm__("func_003CFC30");

int func_003D1D28_impl(int idx) __asm__("func_003D1D28");
int func_003D1D28_impl(int idx) {
    struct H_1D28 *h = D_0044F420_1D28->h[idx];
    unsigned int i = h->start;
    int n = 0;
    if (i < h->end) {
        struct E_1D28 *e = (struct E_1D28 *)(i * 16 + ((int)h + 16));
        do {
            if (e->f4 != 0) {
                if (e->f4 < h->f0) {
                    e->f4 += D_0044F438_1D28;
                }
                if (e->f4 < D_0044F438_1D28) {
                    e->f8 |= 0x04000000;
                }
            }
            if (!(e->f8 & 0x04000000) && func_003CFC30_1D28(h, e) == 0) {
                break;
            }
            i++;
            n++;
            e++;
            h->f8 = D_0044F438_1D28;
            h->start++;
        } while (i < h->end);
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1E80);
#ifdef SKIP_ASM
extern void f_1BA8_1E80(int, int) __asm__("func_003D1BA8");
extern int f_1D28_1E80(int) __asm__("func_003D1D28");
struct O_1E80 { unsigned int f0; unsigned int f4; char pad8[4]; unsigned int fC; };
struct T_1E80 { char pad[0xDC]; struct O_1E80 *a[16]; char pad11C[0x91C - 0x11C]; int n; };
extern struct T_1E80 *D_0044F420_1E80 __asm__("D_0044F420");
extern unsigned int D_0044F438_1E80 __asm__("D_0044F438");

int func_003D1E80_impl(void) __asm__("func_003D1E80");
int func_003D1E80_impl(void) {
    int i;
    int sum = 0;
    struct O_1E80 *o;
    int st;
    unsigned int v;
    for (i = 0; i < 16; i++) {
        if (i >= D_0044F420_1E80->n) {
            D_0044F420_1E80->a[i] = 0;
            continue;
        }
        o = D_0044F420_1E80->a[i];
        if (o == 0) break;
        v = o->fC;
        st = ((v >> 22) & 0x3F) < ((v >> 16) & 0x3F) ? 0 : 3;
        if (o->f4 != 0) {
            if (o->f0 + o->f4 < D_0044F438_1E80) st = 1;
        }
        if (st != 0) {
            f_1BA8_1E80(i, st);
            i--;
        } else {
            sum += f_1D28_1E80(i);
        }
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1F80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_1F80 { char pad[0x30]; unsigned int m_a; int m_b; char pad2[0xDC - 0x38]; char *ptrs[16]; char pad3[0x91C - 0x11C]; int count; char pad4[0x928 - 0x920]; };
extern int f2AF370_1F80(void) __asm__("func_002AF370");
extern struct P_1F80 D_7610_1F80[4] __asm__("D_00517610");

int func_003D1F80(unsigned int a0, char *a1) {
    unsigned int m = a0 & 0xFF000000;
    int i, ret = -8;
    for (i = 0; i < 4; i++) {
        if (D_7610_1F80[i].m_b != 0 && (D_7610_1F80[i].m_a & m) == m) {
            int c = D_7610_1F80[i].count;
            if (c >= 0x10) return -0xD;
            ret = 0;
            {
                int t = f2AF370_1F80();
                *(int *)(a1 + 8) = t;
                *(int *)a1 = t;
            }
            D_7610_1F80[i].ptrs[c] = a1;
            c++;
            D_7610_1F80[i].count = c;
        }
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", PATHI_copyevent);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044F420_2068[] __asm__("D_0044F420");
extern int D_0044F43C_2068[] __asm__("D_0044F43C");
extern char D_00495B48_2068[] __asm__("D_00495B48");
extern void func_0041605C_2068(unsigned int, void *, int) __asm__("func_0041605C");

unsigned int PATHI_copyevent(void *arg0) {
    int temp_9;
    unsigned int *p;
    unsigned int temp_3;
    unsigned int temp_6;
    unsigned int cur;
    unsigned int i;

    temp_6 = D_0044F420_2068[0] + 0x91C;
    cur = D_0044F420_2068[0] + 0x11C;
    p = (unsigned int*)(D_0044F420_2068[0] + 0xDC);
    temp_9 = (((*(unsigned short*)((char*)arg0 + 0xE)) & 0x3F) * 0x10) + 0x10;
    for (i = 0; i < 0x10; i++, p++) {
        temp_3 = *p;
        if (temp_3 >= cur) {
            if (temp_3 < temp_6) {
                int sz = (((*(unsigned short*)((char*)temp_3 + 0xE)) & 0x3F) * 0x10) + 0x10;
                cur += sz;
            }
        }
    }
    if (cur + temp_9 < temp_6) {
        func_0041605C_2068(cur, arg0, temp_9);
        return cur;
    }
    if (D_0044F43C_2068[0] & 0x120) {
        func_003D1658(D_00495B48_2068, temp_9, temp_6 - cur);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct I2138 { int w0; int w4; unsigned int w8; int wC; };
struct E2138 { char pad[0xC]; unsigned char b; char padd; unsigned short h; struct I2138 items[1]; };
extern struct E2138 **D_0044F420_2138[] __asm__("D_0044F420");

int func_003D2138(char *arg0, int arg1) {
    int i;
    unsigned int j;
    struct E2138 *e;
    struct I2138 *it;
    for (i = 0; i < 16; i++) {
        e = *(struct E2138 **)((char *)D_0044F420_2138[0] + 0xDC + i * 4);
        if (e != 0 && e->b == *(unsigned char *)(arg0 + 0xC)) {
            for (j = 0; j < (e->h & 0x3F); j++) {
                it = &e->items[j];
                if (((unsigned char *)it)[9] == arg1) {
                    return (it->w8 >> 26) & 1;
                }
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D21C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_0044F420_f420[] __asm__("D_0044F420");

void func_003D21C0(char *arg0, int arg1) {
    char *g = D_0044F420_f420[0];
    char *p = *(char **)(g + 0x34) + (*(short *)(*(char **)(g + 0x40) + *(unsigned char *)(arg0 + 0xC) * 2) * 4);
    if (p != 0) {
        *(unsigned *)(p + 0xC) = (*(unsigned *)(p + 0xC) & 0xDFFFFFFF) | ((arg1 & 1) << 29);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D2218);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2290);
#ifdef SKIP_ASM
struct P_2290 { char pad[0x34]; int valid; char pad2[0x58 - 0x38]; int arr[24]; char pad3[0x924 - 0xB8]; int tail; };
extern struct P_2290 D_00517610_2290[4] __asm__("D_00517610");
extern unsigned int D_0044F430_2290 __asm__("D_0044F430");
extern unsigned char D_0044F42C_2290 __asm__("D_0044F42C");
extern unsigned char D_0044F42D_2290 __asm__("D_0044F42D");
extern int D_0044F43C_2290 __asm__("D_0044F43C");
extern int D_0044F420_2290 __asm__("D_0044F420");

int func_003D2290(void) {
    int i, j, n;
    if (D_0044F430_2290 != 0) return -0x12;
    i = 0;
    do {
        n = i + 1;
        D_00517610_2290[i].valid = 0;
        D_00517610_2290[i].tail = 0;
        for (j = 23; j >= 0; j--) {
            D_00517610_2290[i].arr[j] = 0;
        }
        i = n;
    } while (i < 4);
    D_0044F42C_2290 = 1;
    D_0044F43C_2290 = 0x100;
    D_0044F420_2290 = 0;
    D_0044F42D_2290 = 0;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D2350);

INCLUDE_ASM("ealib/seg_2B4578", func_003D25F0);

INCLUDE_ASM("ealib/seg_2B4578", func_003D2A68);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2C20);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D5450_2C20(int) __asm__("func_003D5450");
extern int func_003D4BB0_2C20(int) __asm__("func_003D4BB0");
extern double func_00413AF8_2C20(float) __asm__("func_00413AF8");
extern double func_00411F18_2C20(double, double) __asm__("func_00411F18");
extern int func_004126A0_2C20(double) __asm__("func_004126A0");
extern char *D_0044F420_2C20[] __asm__("D_0044F420");
extern unsigned char D_0044F42C_2C20[] __asm__("D_0044F42C");
extern int D_0044F430_2C20[] __asm__("D_0044F430");

static inline int bitclear_2C20(int x) {
    return !(x & 1);
}

int func_003D2C20(int m, int arg1) {
    float ratio, max;
    unsigned int i;
    char *g;
    int *base;
    int *tab;
    int *e;
    int r;

    ratio = 0.0f;
    max = 0.0f;
    if (D_0044F42C_2C20[0] == 0 || D_0044F430_2C20[0] != 0 || func_003D5450_2C20(-1) == 0) {
        return -0x12;
    }
    if (func_003D4BB0_2C20(m & 0xFF000000) == 0) {
        return 0;
    }
    i = 0;
    while (i < 24 && bitclear_2C20((long)m >> i)) {
        i++;
    }
    g = D_0044F420_2C20[0];
    base = *(int **)(g + 0x34);
    if (*((unsigned char *)base + 0xD) < i) {
        return 0;
    }
    tab = *(int **)(g + 0x4C);
    for (e = base + tab[i]; e < base + tab[i + 1] - 2; e += 2) {
        ratio = (float)((unsigned int)(e[2] - e[0]) << 7) / (float)(unsigned int)e[1];
        if (max < ratio) {
            max = ratio;
        }
    }
    r = func_004126A0_2C20(func_00411F18_2C20(func_00413AF8_2C20(ratio * arg1), 0.5));
    D_0044F430_2C20[0] = 0;
    D_0044F420_2C20[0] = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2DF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_2DF8 { unsigned int f0; unsigned int f4; unsigned int f8; };
struct R_2DF8 { unsigned short n; unsigned short type; unsigned int f4; unsigned int f8; };
struct T_2DF8 { char pad[0x54]; int f54; char pad2[4]; char f5C[0x104 - 0x5C]; unsigned int f104; unsigned int f108; };
extern struct T_2DF8 *func_003D5290_2DF8(int) __asm__("func_003D5290");
extern int func_003D5450_2DF8(int) __asm__("func_003D5450");
extern struct R_2DF8 *func_003D4A50_2DF8(int) __asm__("func_003D4A50");
extern int func_003D3140_2DF8(int, int) __asm__("func_003D3140");
extern int func_002AE3A8_2DF8(int) __asm__("func_002AE3A8");
extern int func_002AE298_2DF8(int, char *, int, int) __asm__("func_002AE298");
extern int D_0044F420_2DF8[] __asm__("D_0044F420");
extern unsigned char D_0044F42C_2DF8[] __asm__("D_0044F42C");
extern int D_0044F430_2DF8[] __asm__("D_0044F430");

int func_003D2DF8(int h, int idx, int arg2) {
    int ret = 0;
    struct T_2DF8 *t;
    struct R_2DF8 *r;
    struct E_2DF8 *e;

    if (D_0044F42C_2DF8[0] != 0) {
        if (D_0044F430_2DF8[0] != 0) {
            return -0x12;
        }
        if (func_003D5450_2DF8(-1) != 0) {
            goto ok;
        }
    }
    return -0x12;
ok:
    t = func_003D5290_2DF8(h);
    if (t != 0) {
        r = func_003D4A50_2DF8(h);
        e = (struct E_2DF8 *)(r + 1);
        e += idx;
        if (r != 0 && r->type != 2) {
            if (r->f4 < t->f104 + e->f4 || r->f8 < t->f108 + e->f8) {
                if (r->type == 1) {
                    unsigned int min = 0x7FFFFFFF;
                    int sel = -1;
                    int i;
                    e = (struct E_2DF8 *)(r + 1);
                    for (i = 0; i < r->n; i++, e++) {
                        if (e->f0 <= min) {
                            min = e->f0;
                            sel = i;
                        }
                    }
                    if (sel == idx) {
                        return 0;
                    }
                    func_003D3140_2DF8(h, sel);
                } else if (r->type == 0) {
                    func_002AE3A8_2DF8(h);
                }
            }
        }
        ret = func_002AE298_2DF8(t->f54, t->f5C, idx, arg2);
    }
    D_0044F430_2DF8[0] = 0;
    D_0044F420_2DF8[0] = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2FA0);
#ifdef SKIP_ASM
void func_003D2FA0(void) {
    func_003D16C8();
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D2FC0);
#ifdef SKIP_ASM
extern void func_003D16D0();

void func_003D2FC0(void) {
    func_003D16D0();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2FE0);
#ifdef SKIP_ASM
extern unsigned char D_0044F42C_2FE0 __asm__("D_0044F42C");
extern int D_0044F430_2FE0 __asm__("D_0044F430");
int func_003D2A68(int);
int func_003D2FE0(void) {
    func_003D2A68(-1);
    D_0044F42C_2FE0 = 0;
    D_0044F430_2FE0 = 0;
    return 0;
}
#endif

void func_003D3010(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044F424_3018[4] __asm__("D_0044F424");
extern int D_0044F428_3018[4] __asm__("D_0044F428");

void func_003D3018(int arg0, int arg1) {
    D_0044F424_3018[0] = arg0;
    D_0044F428_3018[0] = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3030);
#ifdef SKIP_ASM
int func_003D3030(void) {
    char *temp_2;

    temp_2 = (char *)func_003D5290();
    if (temp_2 == 0) {
        return -8;
    }
    return *(int *)(temp_2 + 0x54);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3058);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002AE478_3058() __asm__("func_002AE478");

int func_003D3058(int n) {
    int t = func_002AE478_3058() + 0x110;
    t += n * 0x10;
    return (t / 16) * 16 + 0x10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D30A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002AE768_30A8(int, int, int) __asm__("func_002AE768");
extern void *func_003D5290_30A8(int) __asm__("func_003D5290");
extern int func_003D5450_30A8(int) __asm__("func_003D5450");
extern int D_0044F420_30A8[] __asm__("D_0044F420");
extern unsigned char D_0044F42C_30A8[] __asm__("D_0044F42C");
extern int D_0044F430_30A8[] __asm__("D_0044F430");

void func_003D30A8(int arg0, int arg1, int arg2) {
    int var_4;
    void *temp_2;

    if ((D_0044F42C_30A8[0] != 0) && (D_0044F430_30A8[0] == 0) && (func_003D5450_30A8(-1) != 0)) {
        temp_2 = func_003D5290_30A8(arg0);
        var_4 = -8;
        if (temp_2 != 0) {
            var_4 = (*(int *)((char*)(temp_2) + (0x54)));
        }
        func_002AE768_30A8(var_4, arg1, arg2);
        D_0044F430_30A8[0] = 0;
        D_0044F420_30A8[0] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3140);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002AE328_3140(int, int) __asm__("func_002AE328");
extern char *func_003D5290_3140(int) __asm__("func_003D5290");
extern int func_003D5450_3140(int) __asm__("func_003D5450");
extern int D_0044F420_3140[] __asm__("D_0044F420");
extern unsigned char D_0044F42C_3140[] __asm__("D_0044F42C");
extern int D_0044F430_3140[] __asm__("D_0044F430");
int func_003D3140_3140(int arg0, int arg1) __asm__("func_003D3140");

int func_003D3140_3140(int arg0, int arg1) {
    int r;
    char *t;
    r = 0;
    if (D_0044F42C_3140[0] != 0) {
        if (D_0044F430_3140[0] != 0) {
            return -0x12;
        }
        if (func_003D5450_3140(-1) != 0) {
            goto ok;
        }
    }
    return -0x12;
ok:
    t = func_003D5290_3140(arg0);
    if (t != 0) {
        r = func_002AE328_3140(*(int *)(t + 0x54), arg1);
    }
    D_0044F430_3140[0] = 0;
    D_0044F420_3140[0] = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D31E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_31E8 { char p0[0xC]; int f0c; int f10; char p1[0x1C]; unsigned int f30; int f34; char p2[0x928 - 0x38]; };
extern struct S_31E8 D_00517610_31E8[] __asm__("D_00517610");
extern unsigned char D_0044F42C_31E8[] __asm__("D_0044F42C");
extern int D_0044F430_31E8[] __asm__("D_0044F430");
extern int D_0044F420_31E8[] __asm__("D_0044F420");

void func_003D31E8(unsigned int a, int b, int c) {
    int i;
    if (D_0044F42C_31E8[0] != 0 && D_0044F430_31E8[0] == 0) {
        if (func_003D5450(-1)) {
            a &= 0x0F000000;
            for (i = 0; i < 4; i++) {
                if (D_00517610_31E8[i].f34 != 0 && (D_00517610_31E8[i].f30 & a) != 0) {
                    D_00517610_31E8[i].f0c = b;
                    D_00517610_31E8[i].f10 = c;
                }
            }
            D_0044F430_31E8[0] = 0;
            D_0044F420_31E8[0] = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D32A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044ED48_32A8[4] __asm__("D_0044ED48");

int *func_003D32A8(void) {
    return D_0044ED48_32A8;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D32B8);

INCLUDE_ASM("ealib/seg_2B4578", func_003D3658);

INCLUDE_ASM("ealib/seg_2B4578", func_003D37A0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D3900);
#ifdef SKIP_ASM
// PORT: 64-bit `long` bitfields (8 bytes on EE); use uint64_t off-PS2.
struct E_3900 {
    short type;
    unsigned short h2;
    unsigned int w4;
    unsigned int w8;
    unsigned int wC;
};
struct V_3900 {
    char pad0[0x20];
    unsigned int lo : 4;
    int ch : 5;
    unsigned int hi : 23;
    char pad24[0x2C - 0x24];
    short h2C;
    char pad2E[2];
    struct E_3900 *cur;
};
struct G_3900 {
    char pad0[0x30];
    unsigned int x30;
    char *hdr;
    short *a;
    char pad3C[4];
    short *b;
    char pad44[0x54 - 0x44];
    unsigned int *tab54;
    struct V_3900 *voices[32];
};
struct Ev_3900 {
    int w0;
    int w4;
    signed char b8;
    unsigned char b9;
    short pad;
    unsigned char bC;
    unsigned long f7 : 7;
    unsigned long f1 : 1;
    unsigned short hE;
};
struct Q_3900 {
    int p0;
    int p1;
    int p2;
    unsigned long lo : 12;
    unsigned long b : 4;
    unsigned long idx : 6;
    unsigned long hi : 10;
};
struct P_3900 { char pad[0x30]; unsigned int x30; char pad2[0x928 - 0x34]; };
extern struct G_3900 *D_0044F420_3900 __asm__("D_0044F420");
extern void (*D_0044F424_3900)(int, int) __asm__("D_0044F424");
extern int D_0044F430_3900 __asm__("D_0044F430");
extern unsigned int D_0044F438_3900 __asm__("D_0044F438");
extern struct P_3900 D_00517610_3900[4] __asm__("D_00517610");
extern int f3C90_3900(int, int) __asm__("func_003D3C90");
extern int f37A0_3900(int, int) __asm__("func_003D37A0");
extern void f6210_3900(void *, int, int) __asm__("func_00416210");
extern void f0B18_3900(void *, void *) __asm__("func_003D0B18");
extern char *fcopy_3900(void *) __asm__("PATHI_copyevent");
extern int f1F80_3900(unsigned int, char *) __asm__("func_003D1F80");

int func_003D3900(int id, int start, int vel) {
    struct Ev_3900 ev;
    struct Q_3900 q;
    struct E_3900 *e;
    struct V_3900 *v;
    unsigned int t;
    unsigned int w;
    short k;
    short type;
    int save;

    save = vel;
    k = f3C90_3900(id, start);
    e = (struct E_3900 *)(D_0044F420_3900->hdr + D_0044F420_3900->a[k] * 4);
    v = D_0044F420_3900->voices[e->h2 & 0x1F];
    while (e->type <= 0) {
        type = e->type;
        if (type == 0) {
            v->cur = e;
            if (e->w8 & 0x7C00) {
                f6210_3900(&q, 0, 0x10);
                f6210_3900(&ev, 0, 0x10);
                t = D_0044F420_3900->tab54[((e->w8 >> 10) & 0x1F) - 1];
                if (t & 0x80) {
                    ev.bC = 100;
                } else {
                    ev.bC = 0;
                }
                ev.f1 = (t >> 7) & 1;
                ev.b9 = 6;
                ev.hE = 0x25A0;
                ev.f7 = ((e->w8 >> 10) & 0x1F) - 1;
                ev.b8 = -1;
                q.p1 = ev.hE;
                ev.w4 = D_0044F438_3900 + ev.hE;
                ev.w0 = 0x1F000001;
                q.b = 0;
                f0B18_3900(&q, &ev);
                f1F80_3900(D_00517610_3900[0].x30, fcopy_3900(&q));
            }
            if ((e->w4 & 0xE0000) == 0x20000) {
                vel = (D_0044F438_3900 / 23) & 0x7F;
            }
            if (D_0044F424_3900 != 0) {
                D_0044F424_3900(D_0044F430_3900, k);
            }
        } else if (type == -1) {
            w = *(unsigned int *)e;
            if (w & 0xF0000000) {
                if (k != v->h2C) {
                    v->h2C = k;
                    v->lo = w >> 28;
                }
            }
        } else if (type == -2) {
            vel = (D_0044F438_3900 / 23) & 0x7F;
        } else if (type == -3) {
            f1F80_3900(D_0044F420_3900->x30, (D_0044F420_3900->hdr + D_0044F420_3900->b[(e->wC >> 2) & 0xFFF] * 4));
        }
        t = f37A0_3900(k, vel);
        vel = save;
        k = f3C90_3900(id, t);
        e = (struct E_3900 *)(D_0044F420_3900->hdr + D_0044F420_3900->a[k] * 4);
    }
    return (short)f3C90_3900(id, k);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3C90);
#ifdef SKIP_ASM
struct G_3C90 { char pad[0x34]; unsigned int *t34; short *t38; char pad2[0xC]; int *t48; };
extern struct G_3C90 *D_0044F420_3C90 __asm__("D_0044F420");

int func_003D3C90(int idx, int def) {
    int ret = def;
    struct G_3C90 *g;
    unsigned int *base;
    int k;
    if (idx < 0) return ret;
    g = D_0044F420_3C90;
    base = g->t34;
    k = ((unsigned char *)base)[g->t38[idx] * 4 + 4];
    if (k == 0) return ret;
    {
        int lo = g->t48[k - 1];
        int n = g->t48[k] - lo;
        unsigned int *start = base + lo;
        int i;
        for (i = 0; i < n; i++) {
            unsigned int w = start[i];
            if (ret == (int)w >> 16) ret = w & 0xFFFF;
        }
    }
    return ret;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D3D20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V_3D20 {
    char pad0;
    unsigned char b1;
    char pad2[0x20 - 2];
    unsigned int lo : 4;
    int ch : 5;
    unsigned int hi : 23;
    char pad24[0x2F - 0x24];
    unsigned char b2F;
    char pad30[6];
    short h36;
    char pad38[0x110 - 0x38];
};
struct E_3D20 { unsigned short h0; unsigned short h2; unsigned int w4; int w8; int wC; };
struct G_3D20 {
    char pad0[0x34];
    char *hdr;
    short *a;
    char pad3C[0x58 - 0x3C];
    struct V_3D20 *voices[32];
    char padD8[0x91C - 0xD8];
    int x91C;
};
extern struct G_3D20 *D_0044F420_3D20 __asm__("D_0044F420");
extern int f_37A0_3D20(int, int) __asm__("func_003D37A0");
extern int f_3900_3D20(int, int, int) __asm__("func_003D3900");
extern void f_4050_3D20(int) __asm__("func_003D4050");
extern int f_41A8_3D20(struct V_3D20 *) __asm__("func_003D41A8");

void func_003D3D20(int idx) {
    struct V_3D20 save;
    struct V_3D20 *v;
    struct V_3D20 *w;
    struct E_3D20 *e;
    int old;
    int ch;
    int sel;
    int n;
    int k;
    int r;

    sel = -1;
    old = D_0044F420_3D20->x91C;
    v = D_0044F420_3D20->voices[idx];
    save = *v;
    ch = -1;
    k = v->h36;
    e = (struct E_3D20 *)(D_0044F420_3D20->hdr + D_0044F420_3D20->a[k] * 4);
    n = v->ch;
    if (v->b2F) {
        ch = 1;
    }
    if (n > 0 && (e->wC & 2) && (int)(((e->w4 >> 24) & 0xF) * ((e->w4 >> 20) & 0xF)) >= n) {
        sel = k;
        ch = n;
    } else if (v->h36 >= 0) {
        sel = f_37A0_3D20(v->h36, v->b1);
    }
    if (sel >= 0) {
        sel = f_3900_3D20(v->h36, sel, v->b1);
    }
    e = (struct E_3D20 *)(D_0044F420_3D20->hdr + D_0044F420_3D20->a[sel] * 4);
    w = D_0044F420_3D20->voices[e->h2 & 0x1F];
    if (w != 0 && w != v) {
        v->h36 = -1;
        v->ch = ch;
        f_4050_3D20(sel);
        return;
    }
    v->h36 = sel;
    v->ch = ch;
    r = f_41A8_3D20(v);
    if (r >= 0 || r == -9999) {
        return;
    }
    D_0044F420_3D20->x91C = old;
    *v = save;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4050);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003D0B18_4050(void *, void *) __asm__("func_003D0B18");
extern void func_003D1F80_4050(int, int) __asm__("func_003D1F80");
extern int PATHI_copyevent_4050(void *) __asm__("PATHI_copyevent");
extern void func_003D32B8_4050(int, void *) __asm__("func_003D32B8");
extern void *func_00416210_4050(void *, int, int) __asm__("func_00416210");
extern char *D_0044F420_4050[] __asm__("D_0044F420");
struct M_4050 {
    int w0;
    int w4;
    unsigned char b8;
    unsigned char b9;
    unsigned char ba, bb;
    short sc;
    char be;
    char bf;
};
struct G_4050 { char pad[0x58]; int a[1]; };
struct B_4050 { char pad[0x18]; int w18; char rest[4]; };

int func_003D4050(int idx) {
    struct M_4050 m;
    struct M_4050 a;
    struct B_4050 buf;
    char *g = D_0044F420_4050[0];
    char *e = *(char **)(g + 0x34) + *(short *)(*(char **)(g + 0x38) + idx * 2) * 4;
    int r = 0;
    int k, h;
    if (e != 0) {
        k = *(unsigned short *)(e + 2) & 0x1F;
        if (((struct G_4050 *)g)->a[k] != 0) {
            h = (int)((1L << k) | 0x11000000);
            func_00416210_4050(&a, 0, 0x10);
            func_00416210_4050(&m, 0, 0x10);
            if (*(int *)D_0044F420_4050[0] >= 0) {
                func_003D32B8_4050(((struct G_4050 *)D_0044F420_4050[0])->a[*(int *)D_0044F420_4050[0]], &buf);
                m.b9 = 2;
                m.w0 = h;
                *(int *)&m.sc = buf.w18 - 0xA;
                func_003D0B18_4050(&a, &m);
            }
            m.b9 = 4;
            m.w0 = h;
            m.b8 = (*(unsigned int *)e >> 21) & 0x3F;
            m.sc = idx;
            m.be = -1;
            func_003D0B18_4050(&a, &m);
            r = PATHI_copyevent_4050(&a);
            func_003D1F80_4050(h, r);
        }
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D41A8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4898);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct E_4898 { short v; short w; } E_4898;
typedef struct B_4898 { E_4898 ent[0x40]; } B_4898;
typedef struct A_4898 { char pad0[0x34]; B_4898 *b; short *idx; char pad1[0x50 - 0x3C]; char *arr; } A_4898;
extern A_4898 *D_0044F420_F420[] __asm__("D_0044F420");

static inline int get_4898(char *arr, int i) {
    return *(int *)(arr + i * 8);
}

int func_003D4898(int arg0) {
    int var_7;
    A_4898 *a;
    B_4898 *b;
    short t;

    var_7 = 0;
    if (arg0 < 0) return 0;
    a = D_0044F420_F420[0];
    b = a->b;
    if (arg0 >= *(unsigned short *)((char *)b + 0x12)) return 0;
    t = b->ent[a->idx[arg0]].v;
    if (t > 0) {
        var_7 = get_4898(a->arr, t - 1);
    }
    return var_7;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4900);
#ifdef SKIP_ASM
struct S_4900 {
    int a0;
    int a4;
    int a8;
    int ac;
    unsigned int a10;
    int a14;
    int a18;
    int a1c;
};
extern int func_003D32B8(int, struct S_4900 *);

int func_003D4900(int a0, int *a1) {
    struct S_4900 s;

    if (func_003D32B8(a0, &s) < 0) {
        s.a4 = 0;
        s.a10 = 0xFFFFFFFF;
    }
    if (a1 != 0) {
        *a1 = s.a4;
    }
    return s.a10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4950);
#ifdef SKIP_ASM
extern int func_002AEAA8(int, unsigned int);

int func_003D4950(char *arg0) {
    int temp_2;
    int var_16 = 0;
    unsigned int i;

    for (i = 0; i < ((*(unsigned int *)(arg0 + 0x20) >> 0xE) & 0x1F); i++) {
        temp_2 = func_002AEAA8(*(int *)(arg0 + 0x54), i);
        if (temp_2 >= 0) {
            var_16 += temp_2;
        }
    }
    return var_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D49D0);
#ifdef SKIP_ASM
struct C_49D0 { signed char a; signed char b; unsigned short v; };

int func_003D49D0(int n, int key, struct C_49D0 *tbl) {
    struct C_49D0 *best = tbl;
    int bd;
    int i;
    if (n <= 0) return -1;
    bd = 0x7F;
    for (i = 0; i < n; i++) {
        int da = tbl[i].a - key;
        int db = tbl[i].b - key;
        int d;
        if (da < 0) da = -da;
        if (db < 0) db = -db;
        d = da < db ? da : db;
        if (d < bd) {
            bd = d;
            best = &tbl[i];
        }
    }
    return best->v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4A50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_4A50 { char pad[0x30]; unsigned mask; int w34; char pad2[0x8EC]; int *tab; };
extern struct E_4A50 D_00517610_4A50[] __asm__("D_00517610");

int func_003D4A50(unsigned arg0) {
    unsigned i, b;
    unsigned hi = arg0 & 0xF0000000;
    unsigned mid = arg0 & 0x0F000000;
    unsigned m = arg0 & 0xFFFFFF;
    for (i = 0; i < 4; i++) {
        unsigned mk = D_00517610_4A50[i].mask;
        if (D_00517610_4A50[i].tab != 0 && D_00517610_4A50[i].w34 != 0 &&
            (mk & hi) && (mk & mid)) {
            for (b = 0; b < 0x18; b++) {
                if ((m >> b) & 1)
                    return D_00517610_4A50[i].tab[b];
            }
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D4B00);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4BB0);
#ifdef SKIP_ASM
struct P_4BB0 { char pad[0x30]; int m_a; int m_b; char pad2[0x928 - 0x38]; };
extern struct P_4BB0 D_7610_4BB0[4] __asm__("D_00517610");
extern struct P_4BB0 *D_0044F420_4BB0 __asm__("D_0044F420");
extern unsigned int D_0044F430_4BB0 __asm__("D_0044F430");

static inline int sel_4BB0(unsigned int idx) {
    if (D_0044F430_4BB0 == 0)
        D_0044F430_4BB0 = 0xFFFFFFFF;
    if (idx < 4 && D_7610_4BB0[idx].m_b != 0) {
        int v = D_7610_4BB0[idx].m_a;
        D_0044F420_4BB0 = &D_7610_4BB0[idx];
        D_0044F430_4BB0 = v;
        return v;
    }
    if ((int)idx != -1)
        D_0044F430_4BB0 = 0;
    return D_0044F430_4BB0;
}

int func_003D4BB0(int key) {
    int i;
    for (i = 0; i < 4; i++) {
        if (D_7610_4BB0[i].m_b != 0 && D_7610_4BB0[i].m_a == key)
            return sel_4BB0(i);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4C40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_4C40 {
    char pad0[0x30];
    unsigned int mask;
    void *hdr;
    char pad38[0x928 - 0x38];
};
extern struct E_4C40 D_00517610_4C40[4] __asm__("D_00517610");
extern char D_00517644_4C40[] __asm__("D_00517644");

void func_003D4C40(void) {
    struct E_4C40 tmp;
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        if (*(void **)(D_00517644_4C40 + i * 0x928) != 0) {
            for (j = i + 1; j < 4; j++) {
                if (D_00517610_4C40[j].hdr != 0 && D_00517610_4C40[j].mask < D_00517610_4C40[i].mask) {
                    tmp = D_00517610_4C40[i];
                    D_00517610_4C40[i] = D_00517610_4C40[j];
                    D_00517610_4C40[j] = tmp;
                }
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D4F10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Str_4F10 {
    char pad00[0x3];
    unsigned char f3;
    char pad04[0xD - 0x4];
    signed char fD;
    signed char fE;
    char pad0F[0x15 - 0xF];
    signed char f15;
    char pad16[0x1D - 0x16];
    signed char f1D;
    char pad1E[0x24 - 0x1E];
    int f24;
    char pad28[0x2F - 0x28];
    unsigned char f2F;
    int f30;
    char pad34[0x36 - 0x34];
    short f36;
    char pad38[0x48 - 0x38];
    unsigned int f48;
    unsigned int f4C;
    char pad50[0x54 - 0x50];
    int f54;
};
struct Mgr_4F10 {
    char pad00[0xC];
    unsigned int fC;
    unsigned int f10;
    char pad14[0x58 - 0x14];
    struct Str_4F10 *slot[24];
};
extern struct Mgr_4F10 *D_0044F420_4F10 __asm__("D_0044F420");
extern unsigned char D_0044F434_4F10 __asm__("D_0044F434");
extern unsigned int D_0044F438_4F10 __asm__("D_0044F438");
extern void func_002AE9F8_4F10(int h, int a) __asm__("func_002AE9F8");
extern int func_002AEBD0_4F10(int h) __asm__("func_002AEBD0");
extern int func_002AF428_4F10(int h) __asm__("func_002AF428");
extern int func_003D1E80_4F10(void) __asm__("func_003D1E80");
extern void func_003D3D20_4F10(unsigned int i) __asm__("func_003D3D20");
extern int func_003D4950_4F10(struct Str_4F10 *s) __asm__("func_003D4950");
extern void func_003D5A98_4F10(struct Str_4F10 *s) __asm__("func_003D5A98");
extern void func_003D5CC0_4F10(struct Str_4F10 *s) __asm__("func_003D5CC0");
extern void func_003D5EE8_4F10(struct Str_4F10 *s) __asm__("func_003D5EE8");

void func_003D4F10(void) {
    int isB = D_0044F434_4F10 == 'B';
    unsigned int step;
    unsigned int i;
    struct Str_4F10 *s;
    unsigned int end;
    int ok;
    int r;
    int skip;

    if (isB) {
        step = D_0044F420_4F10->f10;
    } else {
        step = D_0044F420_4F10->fC;
    }
    if (!isB) {
        func_003D1E80_4F10();
    }
    for (i = 0; i < 24; i++) {
        s = D_0044F420_4F10->slot[i];
        if (s == 0 || s->f3 != 0) {
            continue;
        }
        ok = 0;
        end = D_0044F438_4F10 + s->f24;
        if (s->f36 >= 0) {
            ok = s->f30 != 0;
        }
        if (ok) {
            if (s->fD >= 0) {
                func_003D5A98_4F10(s);
            }
            if (s->f15 >= 0) {
                func_003D5CC0_4F10(s);
            }
            if (s->f1D >= 0) {
                func_003D5EE8_4F10(s);
            }
        }
        if ((s->f2F != 0) != isB || !ok) {
            continue;
        }
        if (s->f4C != 0) {
            if (D_0044F438_4F10 + (step >> 1) >= s->f4C) {
                func_002AE9F8_4F10(s->f54, 0);
                s->f4C = 0;
            }
        } else if (func_002AEBD0_4F10(s->f54) != 0) {
            r = func_003D4950_4F10(s);
            if (s->f48 != 0) {
                end += step;
                skip = end < s->f48;
            } else {
                skip = s->f24 < r;
            }
            if (!skip) {
                if (s->fE == 0 && func_002AF428_4F10(s->f54) == 0) {
                    s->fE = -1;
                }
                func_003D3D20_4F10(i);
            }
        }
    }
    while (!isB && func_003D1E80_4F10() != 0) {
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D5128);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5290);
#ifdef SKIP_ASM
struct E_5290 { char pad[0x30]; unsigned mask; int w34; char pad2[0x20]; int tab[24]; char pad3[0x928 - 0xB8]; };
extern struct E_5290 D_00517610_5290[] __asm__("D_00517610");

int func_003D5290(unsigned arg0) {
    unsigned i, b;
    unsigned hi = arg0 & 0xF0000000;
    unsigned mid = arg0 & 0x0F000000;
    unsigned m = arg0 & 0xFFFFFF;
    for (i = 0; i < 4; i++) {
        unsigned mk = D_00517610_5290[i].mask;
        if (D_00517610_5290[i].w34 != 0 &&
            (mk & hi) && (mk & mid)) {
            for (b = 0; b < 0x18; b++) {
                if ((m >> b) & 1)
                    return D_00517610_5290[i].tab[b];
            }
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D5330);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D53B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D11B8_53B8(int, int *) __asm__("func_003D11B8");
extern int func_003D3030_53B8(int) __asm__("func_003D3030");

int func_003D53B8(int arg0, int arg1) {
    int sp0[12];
    int i;
    int t;

    for (i = 1; i >= 0; i--) {
        t = ((0x10000000 << i) | (0x01000000 << arg0)) + (1 << arg1);
        if (func_003D3030_53B8(t) >= 0) {
            func_003D11B8_53B8(t, sp0);
            if (sp0[0] >= 0) return t;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5450);
#ifdef SKIP_ASM
struct P_5450 { char pad[0x30]; int m_a; int m_b; char pad2[0x928 - 0x38]; };
extern struct P_5450 D_7610_5450[4] __asm__("D_00517610");
extern struct P_5450 *D_0044F420_5450 __asm__("D_0044F420");
extern unsigned int D_0044F430_5450 __asm__("D_0044F430");

int func_003D5450(unsigned int idx) {
    if (D_0044F430_5450 == 0)
        D_0044F430_5450 = 0xFFFFFFFF;
    if (idx < 4 && D_7610_5450[idx].m_b != 0) {
        int v = D_7610_5450[idx].m_a;
        D_0044F420_5450 = &D_7610_5450[idx];
        D_0044F430_5450 = v;
        return v;
    }
    if ((int)idx != -1)
        D_0044F430_5450 = 0;
    return D_0044F430_5450;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D54C8);
#ifdef SKIP_ASM
extern void func_003D5128(int);

void func_003D54C8(void) {
    func_003D5128(0x20);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D54E8);
#ifdef SKIP_ASM
extern void func_003D5128(int);

void func_003D54E8(void) {
    func_003D5128(0x42);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D5508);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5698);
#ifdef SKIP_ASM
/* 99.39: remaining only callee-saved reg numbering (base644 $22, masks $30/$23) and const reg $2; twin 3D5800 (callee 3D6360), sibling 3D1038/3D5508 */
extern int func_003D5450_5698(int) __asm__("func_003D5450");
extern void func_003D6318_5698(int, int, int, int) __asm__("func_003D6318");
struct P_5698 { char pad0[0x18]; int f18; char pad1C[0x3C]; int a[24]; };
extern struct P_5698 *D_0044F420_5698 __asm__("D_0044F420");
extern unsigned char D_0044F42C_5698 __asm__("D_0044F42C");
extern int D_0044F430_5698 __asm__("D_0044F430");
extern char D_00517640_5698[] __asm__("D_00517640");
extern char D_00517644_5698[] __asm__("D_00517644");

void func_003D5698(unsigned int mask, int a1, int a2) {
    int i;
    int j;
    int next;
    unsigned int fl, t, u;
    struct P_5698 *g;
    int off;
    char *np;
    char *b4;
    unsigned int nv;
    if (D_0044F42C_5698 == 0) return;
    if (D_0044F430_5698 != 0) return;
    if (func_003D5450_5698(-1) == 0) return;
    do {
    b4 = D_00517644_5698;
    i = 0;
    } while (0);
    do {
        off = (u = 0x928);
        off = i * off;
        np = D_00517640_5698;
        next = i + 1;
        if (*(int *)(off + (int)b4) != 0) {
            fl = *(unsigned int *)(np + off);
            nv = fl & 0xF0000000;
            do { t = nv; } while (0);
            if ((t & mask) != 0 && (u = fl & 0x0F000000, (u & mask) != 0)) {
                if (func_003D5450_5698(i) != 0) {
                    for (j = 0; j < 24; j++) {
                        g = D_0044F420_5698;
                        if (g->a[j] != 0 && (((mask >> j) ^ 1) & 1) == 0) {
                            func_003D6318_5698(g->a[j], a1, a2, g->f18);
                        }
                    }
                }
            }
        }
        i = next;
    } while (i < 4);
    D_0044F420_5698 = 0;
    D_0044F430_5698 = 0;}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5800);
#ifdef SKIP_ASM
extern int func_003D5450_5800(int) __asm__("func_003D5450");
extern void func_003D6360_5800(int, int, int, int) __asm__("func_003D6360");
struct P_5800 { char pad0[0x18]; int f18; char pad1C[0x3C]; int a[24]; };
extern struct P_5800 *D_0044F420_5800 __asm__("D_0044F420");
extern unsigned char D_0044F42C_5800 __asm__("D_0044F42C");
extern int D_0044F430_5800 __asm__("D_0044F430");
extern char D_00517640_5800[] __asm__("D_00517640");
extern char D_00517644_5800[] __asm__("D_00517644");

void func_003D5800(unsigned int mask, int a1, int a2) {
    int i;
    int j;
    int next;
    unsigned int fl, t, u;
    struct P_5800 *g;
    int off;
    char *np;
    char *b4;
    unsigned int nv;
    if (D_0044F42C_5800 == 0) return;
    if (D_0044F430_5800 != 0) return;
    if (func_003D5450_5800(-1) == 0) return;
    do {
    b4 = D_00517644_5800;
    i = 0;
    } while (0);
    do {
        off = (u = 0x928);
        off = i * off;
        np = D_00517640_5800;
        next = i + 1;
        if (*(int *)(off + (int)b4) != 0) {
            fl = *(unsigned int *)(np + off);
            nv = fl & 0xF0000000;
            do { t = nv; } while (0);
            if ((t & mask) != 0 && (u = fl & 0x0F000000, (u & mask) != 0)) {
                if (func_003D5450_5800(i) != 0) {
                    for (j = 0; j < 24; j++) {
                        g = D_0044F420_5800;
                        if (g->a[j] != 0 && (((mask >> j) ^ 1) & 1) == 0) {
                            func_003D6360_5800(g->a[j], a1, a2, g->f18);
                        }
                    }
                }
            }
        }
        i = next;
    } while (i < 4);
    D_0044F420_5800 = 0;
    D_0044F430_5800 = 0;}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002AF428_5968(int) __asm__("func_002AF428");
extern void func_002AF6C0_5968(int, int) __asm__("func_002AF6C0");
extern void func_002AF838_5968(int) __asm__("func_002AF838");
extern int D_0044F420_5968[] __asm__("D_0044F420");

void func_003D5968(unsigned int mask) {
    int i;
    for (i = 0; i < 0x18; i++) {
        char *o = *(char **)((char *)D_0044F420_5968[0] + (i << 2) + 0x58);
        if (o != 0 && !(((mask >> i) ^ 1) & 1) && *(short *)(o + 0x36) >= 0) {
            int t18 = *(signed char *)(o + 0x34) * *(signed char *)(o + 4) / 100;
            signed char b = *(signed char *)(o + 0xE);
            if (b >= 0) {
                int t16 = b * *(signed char *)(o + 4) / 100;
                if (t16 == func_002AF428_5968(*(int *)(o + 0x54))) {
                    if (*(signed char *)(o + 0xE) == 0) {
                        func_002AF838_5968(*(int *)(o + 0x54));
                        *(short *)(o + 0x36) = -1;
                    } else {
                        goto b8;
                    }
                    goto b10;
                }
            } else {
b8:
                if (t18 >= 0) {
                    func_002AF6C0_5968(*(int *)(o + 0x54), t18);
                }
b10:
                *(signed char *)(o + 0xE) = -1;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5A98);
#ifdef SKIP_ASM
struct V_5A98 { char pad0[8]; int f8; char fC; char fD; char fE; char padF[0x34 - 0xF]; char f34; char pad35[0x54 - 0x35]; int f54; };
struct G_5A98 { char pad0[0x14]; unsigned short h14; char pad16[2]; unsigned f18; };
extern struct G_5A98 *D_0044F420_5A98 __asm__("D_0044F420");
extern int D_0044F438_5A98 __asm__("D_0044F438");
extern void func_002AF6C0_5A98(int, int) __asm__("func_002AF6C0");

void func_003D5A98_impl(struct V_5A98 *v) __asm__("func_003D5A98");
void func_003D5A98_impl(struct V_5A98 *v) {
    struct {
        unsigned mode : 7;
        int neg : 1;
        unsigned mid : 8;
        unsigned dur : 16;
    } l;
    float r = -1.0f;
    float diff;
    float t;
    float m;
    int pos;
    int none;
    unsigned sel;
    diff = (float)v->fE - (float)v->fC;
    l.dur = D_0044F420_5A98->h14;
    l.mode = D_0044F420_5A98->f18;
    pos = 1;
    if (diff < 0.0f) {
        pos = 0;
    }
    l.neg = pos;
    t = (float)(unsigned)(D_0044F438_5A98 - v->f8) / (float)l.dur;
    if (t >= 1.0f) {
        func_002AF6C0_5A98(v->f54, v->f34);
        none = -1;
        v->fC = none;
        sel = none;
        v->fD = v->fE = sel;
        v->f8 = 0;
        v->f34 = sel;
        return;
    }
    if (l.neg) {
        t = 1.0f - t;
    }
    sel = l.mode;
    switch (sel) {
    case 1:
        r = 1.0f - t;
        break;
    case 2:
        r = 1.0f - t * t;
        break;
    case 3:
        r = 1.0f / t / 25.0f;
        break;
    }
    m = v->fC;
    if (v->fE < v->fC) {
        m = v->fE;
    }
    if (diff < 0.0f) {
        diff = -diff;
    }
    if (r >= 0.0f && r <= 1.0f) {
        r = m + diff * r;
        func_002AF6C0_5A98(v->f54, (int)r);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5CC0);
#ifdef SKIP_ASM
struct V_5CC0 { char pad0[0x10]; int f10; char f14; char f15; char f16; char pad17[0x54 - 0x17]; int f54; };
struct G_5CC0 { char pad0[0x1C]; unsigned short h1C; char pad1E[2]; unsigned f20; };
extern struct G_5CC0 *D_0044F420_5CC0 __asm__("D_0044F420");
extern int D_0044F438_5CC0 __asm__("D_0044F438");
extern void func_002AF4E0_5CC0(int, int, int) __asm__("func_002AF4E0");

void func_003D5CC0_impl(struct V_5CC0 *v) __asm__("func_003D5CC0");
void func_003D5CC0_impl(struct V_5CC0 *v) {
    struct {
        unsigned mode : 7;
        int neg : 1;
        unsigned mid : 8;
        unsigned dur : 16;
    } l;
    float r = -1.0f;
    float diff;
    float t;
    float m;
    int pos;
    int none;
    unsigned sel;
    diff = (float)v->f16 - (float)v->f14;
    l.dur = D_0044F420_5CC0->h1C;
    l.mode = D_0044F420_5CC0->f20;
    pos = 1;
    if (diff < 0.0f) {
        pos = 0;
    }
    l.neg = pos;
    t = (float)(unsigned)(D_0044F438_5CC0 - v->f10) / (float)l.dur;
    if (t >= 1.0f) {
        func_002AF4E0_5CC0(v->f54, 0, v->f16);
        none = -1;
        v->f14 = none;
        v->f15 = v->f16 = none;
        v->f10 = 0;
        return;
    }
    if (l.neg) {
        t = 1.0f - t;
    }
    sel = l.mode;
    switch (sel) {
    case 1:
        r = 1.0f - t;
        break;
    case 2:
        r = 1.0f - t * t;
        break;
    case 3:
        r = 1.0f / t / 25.0f;
        break;
    }
    m = v->f14;
    if (v->f16 < v->f14) {
        m = v->f16;
    }
    if (diff < 0.0f) {
        diff = -diff;
    }
    if (r >= 0.0f && r <= 1.0f) {
        r = m + diff * r;
        func_002AF4E0_5CC0(v->f54, 0, (int)r);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5EE8);
#ifdef SKIP_ASM
struct V_5EE8 { char pad0[0x18]; int f18; char f1C; char f1D; char f1E; char pad1F[0x54 - 0x1F]; int f54; };
struct G_5EE8 { char pad0[0x24]; unsigned short h24; char pad26[2]; unsigned f28; };
extern struct G_5EE8 *D_0044F420_5EE8 __asm__("D_0044F420");
extern int D_0044F438_5EE8 __asm__("D_0044F438");
extern void func_002AF580_5EE8(int, int) __asm__("func_002AF580");

void func_003D5EE8_impl(struct V_5EE8 *v) __asm__("func_003D5EE8");
void func_003D5EE8_impl(struct V_5EE8 *v) {
    struct {
        unsigned mode : 7;
        int neg : 1;
        unsigned mid : 8;
        unsigned dur : 16;
    } l;
    float r = -1.0f;
    float diff;
    float t;
    float m;
    int pos;
    int none;
    unsigned sel;
    diff = (float)v->f1E - (float)v->f1C;
    l.dur = D_0044F420_5EE8->h24;
    l.mode = D_0044F420_5EE8->f28;
    pos = 1;
    if (diff < 0.0f) {
        pos = 0;
    }
    l.neg = pos;
    t = (float)(unsigned)(D_0044F438_5EE8 - v->f18) / (float)l.dur;
    if (t >= 1.0f) {
        func_002AF580_5EE8(v->f54, v->f1E);
        none = -1;
        v->f1C = none;
        v->f1D = v->f1E = none;
        v->f18 = 0;
        return;
    }
    if (l.neg) {
        t = 1.0f - t;
    }
    sel = l.mode;
    switch (sel) {
    case 1:
        r = 1.0f - t;
        break;
    case 2:
        r = 1.0f - t * t;
        break;
    case 3:
        r = 1.0f / t / 25.0f;
        break;
    }
    m = v->f1C;
    if (v->f1E < v->f1C) {
        m = v->f1E;
    }
    if (diff < 0.0f) {
        diff = -diff;
    }
    if (r >= 0.0f && r <= 1.0f) {
        r = m + diff * r;
        func_002AF580_5EE8(v->f54, (int)r);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6108);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_6108 { char pad[0x30]; int m_a; int m_b; char pad2[0x928 - 0x38]; };
extern int f5450_6108(int) __asm__("func_003D5450");
extern int D_f420_6108[] __asm__("D_0044F420");
extern unsigned char D_f42C_6108[] __asm__("D_0044F42C");
extern int D_f430_6108[] __asm__("D_0044F430");
extern struct P_6108 D_7610_6108[4] __asm__("D_00517610");

void func_003D6108(int a0, int a1) {
    int i;
    if (D_f42C_6108[0] != 0 && D_f430_6108[0] == 0 && f5450_6108(-1) != 0) {
        a0 &= 0x0F000000;
        for (i = 0; i < 4; i++) {
            if (D_7610_6108[i].m_b != 0 && (D_7610_6108[i].m_a & a0) && f5450_6108(i & 0xFF) != 0) {
                *(int *)(D_f420_6108[0] + 0x14) = a1;
            }
        }
        D_f430_6108[0] = 0;
        D_f420_6108[0] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D61E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_61E8 { char pad[0x30]; int m_a; int m_b; char pad2[0x928 - 0x38]; };
extern int f5450_61E8(int) __asm__("func_003D5450");
extern int D_f420_61E8[] __asm__("D_0044F420");
extern unsigned char D_f42C_61E8[] __asm__("D_0044F42C");
extern int D_f430_61E8[] __asm__("D_0044F430");
extern struct P_61E8 D_7610_61E8[4] __asm__("D_00517610");

void func_003D61E8(int a0, int a1) {
    int i;
    if (D_f42C_61E8[0] != 0 && D_f430_61E8[0] == 0 && f5450_61E8(-1) != 0) {
        a0 &= 0x0F000000;
        for (i = 0; i < 4; i++) {
            if (D_7610_61E8[i].m_b != 0 && (D_7610_61E8[i].m_a & a0) && f5450_61E8(i & 0xFF) != 0) {
                *(int *)(D_f420_61E8[0] + 0x18) = a1;
            }
        }
        D_f430_61E8[0] = 0;
        D_f420_61E8[0] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D62C8);
#ifdef SKIP_ASM
extern void func_002AF6C0(int, int);

void func_003D62C8(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (4))) = arg1;
    if ((*(signed char *)((char*)(arg0) + (0xE))) < 0) {
        func_002AF6C0((*(int *)((char*)(arg0) + (0x54))), (int) ((*(signed char *)((char*)(arg0) + (0x34))) * arg1) / 100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6318);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D6318_cb(int, int, int, char) __asm__("func_002AF608");

void func_003D6318(char *self, int v, int w) {
    int x;
    self[0xE] = v;
    x = (v * self[4]) / 100;
    self[0xD] = 0;
    func_003D6318_cb(*(int *)(self + 0x54), x, w, 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6360);
#ifdef SKIP_ASM
void func_003D6360(void *arg0, int arg1, int arg2, int arg3) {
    *(signed char *)((char *)arg0 + 0x16) = arg1;
    if (arg3 >= 0) {
        *(signed char *)((char *)arg0 + 0x15) = arg3;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6378);
#ifdef SKIP_ASM
extern int D_0044F438_6378[] __asm__("D_0044F438");
extern int f_6378_cb(int) __asm__("func_002AF428");

void func_003D6378(char *self, int a, int b) {
    int t;
    int q, d;
    *(int *)(self + 8) = D_0044F438_6378[0];
    self[0xD] = b;
    t = f_6378_cb(*(int *)(self + 0x54));
    self[0xC] = (int)(float)t;
    self[0xE] = a;
    self[0x34] = (int)(float)a;
    d = 0x7F;
    q = a / d;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D63F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044F438_63F8[] __asm__("D_0044F438");
extern signed char f_63F8_cb(int) __asm__("func_002AF4B0");

void func_003D63F8(char *self, int a, int b) {
    signed char t;
    *(int *)(self + 0x10) = D_0044F438_63F8[0];
    self[0x15] = b;
    t = f_63F8_cb(*(int *)(self + 0x54));
    self[0x16] = a;
    self[0x14] = t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6448);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044F438_6448[] __asm__("D_0044F438");
extern signed char f_6448_cb(int) __asm__("func_002AF480");

void func_003D6448(char *self, int a, int b) {
    signed char t;
    *(int *)(self + 0x18) = D_0044F438_6448[0];
    self[0x1D] = b;
    t = f_6448_cb(*(int *)(self + 0x54));
    self[0x1E] = a;
    self[0x1C] = t;
}
#endif
