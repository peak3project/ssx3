#include "common.h"

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6498);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_6498 { unsigned char *p; unsigned int x; };
extern struct E_6498 D_0044FFB8_6498[] __asm__("D_0044FFB8");
void func_003DA3A8(void *arg0, int *arg1, int *arg2);

static __inline__ void clear_6498(unsigned long key) {
    int i, j;
    for (i = 0; i < 8; i++) {
        unsigned char *p = D_0044FFB8_6498[i].p;
        if (p != 0 && D_0044FFB8_6498[i].x == key) {
            unsigned char *q = p + (((*(unsigned short *)(p + 0x10) * 2 + 3) & 0xFFFFFFFC) + 0x18);
            for (j = 0; j < D_0044FFB8_6498[i].p[0x12]; j++) {
                q[j] = 0xFF;
            }
        }
    }
}

int func_003D6498_6498(unsigned short *arg0, unsigned int arg1) __asm__("func_003D6498");
int func_003D6498_6498(unsigned short *arg0, unsigned int arg1) {
    int a, b;
    int i;
    int ok = 0;
    if (*arg0 == 0xC03) {
        func_003DA3A8(arg0, &a, &b);
        for (i = 0; i < 8; i++) {
            unsigned char *p = D_0044FFB8_6498[i].p;
            if (p != 0 && p[9] == b && p[8] == a) {
                goto out;
            }
        }
        for (i = 0; i < 8; i++) {
            if (D_0044FFB8_6498[i].p == 0) {
                D_0044FFB8_6498[i].p = (unsigned char *)arg0;
                D_0044FFB8_6498[i].x = arg1;
                ok = 1;
                break;
            }
        }
        clear_6498(arg1);
    }
out:
    return ok;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6618);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_6618 { unsigned char *p; unsigned int x; };
extern struct E_6618 D_0044FFB8_6618[] __asm__("D_0044FFB8");

void func_003D6618(unsigned long key) {
    int i, j;
    for (i = 0; i < 8; i++) {
        unsigned char *p = D_0044FFB8_6618[i].p;
        if (p != 0 && D_0044FFB8_6618[i].x == key) {
            unsigned char *q = p + (((*(unsigned short *)(p + 0x10) * 2 + 3) & 0xFFFFFFFC) + 0x18);
            for (j = 0; j < D_0044FFB8_6618[i].p[0x12]; j++) {
                q[j] = 0xFF;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D66C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003D6498_66C0(void *arg0, unsigned int arg1) __asm__("func_003D6498");

int func_003D66C0(void *arg0, unsigned int arg1) {
    int r = 0;
    if (arg1 < 8) {
        r = func_003D6498_66C0(arg0, arg1);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D66F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044FFB8_FFB8[] __asm__("D_0044FFB8");

int func_003D66F0(int arg0, int arg1) {
    int i;
    if (arg0 == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (D_0044FFB8_FFB8[i * 2] == arg0 && D_0044FFB8_FFB8[i * 2 + 1] == arg1) {
            D_0044FFB8_FFB8[i * 2] = 0;
            return 1;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D6748);
#ifdef SKIP_ASM
extern void func_003D6498(int, int);

void func_003D6748(int a) {
    func_003D6498(a, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6768);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044FFA8_6768[4] __asm__("D_0044FFA8");

int *func_003D6768(void) {
    return D_0044FFA8_6768;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6778);
#ifdef SKIP_ASM
int func_003D6778(int arg0, int arg1, unsigned int arg2) {
    int v = arg0 * arg1 / 8;
    switch (arg2) {
    case 0:
        break;
    case 1:
        v = v / 10;
        break;
    case 2:
        v = v * 2 / 7;
        break;
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D67F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_67F8 { int a; int b; int c; };
extern struct S_67F8 D_0044FF90_67F8 __asm__("D_0044FF90");
extern int D_004A4820;
void func_003D6D30(void);
void func_003D8278(void);

void func_003D67F8(void) {
    if (D_004A4820 == 0x01789A34) {
        D_004A4820 = 0;
        D_0044FF90_67F8.a = 0;
        D_0044FF90_67F8.b = 0;
        D_0044FF90_67F8.c = 0;
        func_003D6D30();
        func_003D8278();
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6840);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_6840 { int a; int b; int c; };
struct E_6840 { unsigned short h; int w; };
extern struct S_6840 D_0044FF90_6840 __asm__("D_0044FF90");
extern struct S_6840 D_0044FFA8_6840 __asm__("D_0044FFA8");
extern struct E_6840 D_00450660_6840[] __asm__("D_00450660");
extern int D_004506A0_6840[] __asm__("D_004506A0");
extern int D_004A4820;
extern void *D_004A482C_6840 __asm__("D_004A482C");
extern int D_004A4834_6840 __asm__("D_004A4834");
extern int D_004A4838_6840 __asm__("D_004A4838");
void func_003D76F0(int, int, ...);
void func_003DB790(int);
void func_003D9A40(void);
void func_003DA3C0(int);
void func_003D8278(void);
void func_003D6D40(void);
void func_003D71D8(void);

int func_003D6840(int arg0, int arg1, int arg2) {
    int i;
    long j;
    D_0044FF90_6840.a = arg0;
    D_0044FF90_6840.b = 0;
    D_0044FF90_6840.c = 0;
    D_0044FFA8_6840.a = 0;
    D_0044FFA8_6840.b = 0;
    D_0044FFA8_6840.c = 0;
    D_004A482C_6840 = (void *)func_003D76F0;
    D_004A4834_6840 = arg1;
    D_004A4838_6840 = arg2;
    func_003DB790(arg1);
    func_003D9A40();
    func_003DA3C0(0);
    for (i = 7; i >= 0; i--) {
        D_004506A0_6840[i] = 0;
    }
    func_003D8278();
    for (j = 0; j < 8; j++) {
        D_00450660_6840[(int)j].h = 0xFFFF;
        D_00450660_6840[(int)j].w = 0;
    }
    func_003D6D40();
    func_003D71D8();
    D_004A4820 = 0x01789A34;
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6940);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_6940 { int pad0; int a; int b; };
extern struct S_6940 D_0044FF90_6940 __asm__("D_0044FF90");
extern int D_004A4820;
void func_003D6940(int x, int y) {
    if (D_004A4820 == 0x01789A34) {
        D_0044FF90_6940.a = x;
        D_0044FF90_6940.b = y;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6968);
#ifdef SKIP_ASM
extern int D_0044FFA0[];
extern int D_004A4820;

void func_003D6968(int arg0) {
    if (D_004A4820 == 0x01789A34) {
        D_0044FFA0[0] = arg0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6988);
#ifdef SKIP_ASM
extern int D_0044FF9C[];
extern int D_004A4820;

void func_003D6988(int arg0) {
    if (D_004A4820 == 0x01789A34) {
        D_0044FF9C[0] = arg0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D69A8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_69A8 { unsigned short h; int w; };
extern struct E_69A8 D_00450660_69A8[] __asm__("D_00450660");

void func_003D69A8(void) {
    long i;
    for (i = 0; i < 8; i++) {
        D_00450660_69A8[(int)i].h = 0xFFFF;
        D_00450660_69A8[(int)i].w = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D69F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char **D_004A4824_69F0 __asm__("D_004A4824");
extern int D_004A4828_69F0 __asm__("D_004A4828");
extern unsigned int D_004A4834_69F0 __asm__("D_004A4834");

static inline int findfree_69F0(void) {
    int i, idx;

    idx = -1;
    for (i = 0; i < D_004A4828_69F0; i++) {
        if (D_004A4824_69F0[i] == 0) {
            idx = i;
            break;
        }
    }
    return idx;
}

static inline unsigned char *tail_69F0(unsigned char *s) {
    int n = s[4] & 0xF;
    return s + ((s[5] * (n + 2) + 0xF) & 0x3FFC) + n * 4;
}

int func_003D69F0(unsigned char *shp) {
    int ret;
    int i, j, w, extra, c, cnt, bit;
    unsigned char *p, *t;
    unsigned int r, start, end, byte;

    ret = -1;
    if (D_004A4824_69F0 != 0) {
        if (shp[6] != 0) {
            extra = 0;
            p = tail_69F0(shp);
            if (shp[4] & 0x80) {
                extra = (shp[5] + 7) / 8 + 1;
            }
            p += extra;
            if (*p != 0) {
                goto out;
            }
            for (i = 0; i < shp[6]; i++) {
                if (p[i + 1] != 0xFF) {
                    goto out;
                }
            }
        }
        ret = findfree_69F0();
        if (ret >= 0) {
            if (shp[4] & 0x80) {
                t = tail_69F0(shp);
                w = shp[5];
                c = *t;
                if (c > 0) {
                    r = D_004A4834_69F0 % c;
                    start = r * w / c;
                    end = (r + 1) * w / c;
                    bit = start & 7;
                    byte = (start >> 3) + 1;
                    cnt = end - start;
                    for (j = 0; j < cnt; j++) {
                        t[byte] |= 1 << bit;
                        bit++;
                        if (bit == 8) {
                            bit = 0;
                            byte++;
                        }
                    }
                }
            }
            D_004A4824_69F0[ret] = shp;
        }
    }
out:
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6BC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A4820;
extern unsigned char **D_004A4824_6BC0 __asm__("D_004A4824");
extern int D_004A4828_6BC0 __asm__("D_004A4828");
extern int D_004A4834_6BC0 __asm__("D_004A4834");
void func_003D7038(unsigned char *p);
void func_003D6F80(unsigned char *p);

void func_003D6BC0(int arg0) {
    int i;
    unsigned char *p;
    if (D_004A4820 != 0) {
        D_004A4834_6BC0 = arg0;
        if (D_004A4824_6BC0 != 0) {
            for (i = 0; i < D_004A4828_6BC0; i++) {
                p = D_004A4824_6BC0[i];
                if (p != 0 && (p[4] & 0x80)) {
                    func_003D7038(p);
                    func_003D6F80(p);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6C58);
#ifdef SKIP_ASM
int func_003D6C58(int arg0) {
    return arg0 * 4;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6C60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int *D_004A4824_6C60 __asm__("D_004A4824");
extern int D_004A4828_6C60 __asm__("D_004A4828");

void func_003D6C60(int arg0, int *arg1) {
    int i;

    D_004A4828_6C60 = arg0;
    D_004A4824_6C60 = arg1;
    if (arg1 != 0) {
        for (i = 0; i < D_004A4828_6C60; i++) {
            D_004A4824_6C60[i] = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6CA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int *D_004A4824_6CA0 __asm__("D_004A4824");

void func_003D6CA0(int arg0) {
    if (D_004A4824_6CA0 != 0) {
        D_004A4824_6CA0[arg0] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6CC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A4820;
extern int *D_004A4824_6CC0 __asm__("D_004A4824");

int func_003D6CC0(int arg0) {
    int r = 0;
    if (D_004A4820 == 0x01789A34 && D_004A4824_6CC0 != 0) {
        r = D_004A4824_6CC0[arg0];
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6CF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char **D_004A4824_6CF8 __asm__("D_004A4824");

int func_003D6CF8(int arg0, unsigned int arg1) {
    int r = 0;
    unsigned short *p;

    if (D_004A4824_6CF8 != 0 && arg0 >= 0) {
        p = (unsigned short *)(D_004A4824_6CF8[arg0] + 0xA);
        if (*p != 0xFFFF) {
            r = arg1 < *p;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6D30);
#ifdef SKIP_ASM
extern int D_004A4824;
extern int D_004A4828;

void func_003D6D30(void) {
    D_004A4824 = 0;
    D_004A4828 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6D40);
#ifdef SKIP_ASM
extern int D_004A4824;
extern int D_004A4828;

void func_003D6D40(void) {
    D_004A4824 = 0;
    D_004A4828 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6D50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned short **D_004A4824_6D50 __asm__("D_004A4824");
extern int D_004A4828_6D50 __asm__("D_004A4828");

int func_003D6D50(unsigned short arg0) {
    unsigned short **p;
    short i;

    p = D_004A4824_6D50;
    if (p != 0) {
        for (i = 0; i < D_004A4828_6D50; i++) {
            if (*p != 0 && **p == arg0) {
                return i;
            }
            p++;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6DB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned short **D_004A4824_6DB8 __asm__("D_004A4824");
extern int D_004A4828_6DB8 __asm__("D_004A4828");

int func_003D6DB8(unsigned short arg0, unsigned short arg1) {
    short i;
    unsigned short *p;

    if (D_004A4824_6DB8 != 0) {
        for (i = 0; i < D_004A4828_6DB8; i++) {
            p = D_004A4824_6DB8[i];
            if (p != 0 && p[0] == arg0 && p[1] == arg1) {
                return i;
            }
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6E30);
#ifdef SKIP_ASM
int func_003D6E30(unsigned char *p, int key) {
    int cnt = p[6];
    int r = 0;
    if (cnt > 0) {
        unsigned char f = p[4];
        int off = 0;
        unsigned char w = p[5];
        int t = f & 0xF;
        unsigned char *q, *s;
        int i, j;
        q = p + ((w * (t + 2) + 0xF) & 0x3FFC) + t * 4;
        if (f & 0x80)
            off = (w + 7) / 8 + 1;
        s = q + off;
        i = 0;
        j = *s;
        s++;
        j -= 1;
        do {
            if (j <= -1)
                j = cnt - 1;
            if (s[j] == key) {
                r = i + 1;
                break;
            }
            i += 1;
            j -= 1;
        } while (i < cnt);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6EE8);
#ifdef SKIP_ASM
void func_003D6EE8(unsigned char *arg0, int arg1) {
    int t3;
    int var_10;
    unsigned char *q;
    unsigned char *p;
    unsigned char t4;
    unsigned char t6;
    unsigned char t9;
    unsigned char b;

    t9 = arg0[6];
    var_10 = 0;
    if (t9 != 0) {
        t4 = arg0[4];
        t6 = arg0[5];
        t3 = t4 & 0xF;
        q = arg0 + (((t6 * (t3 + 2)) + 0xF) & 0x3FFC) + t3 * 4;
        if (t4 & 0x80) {
            var_10 = (t6 + 7) / 8 + 1;
        }
        p = q + var_10;
        b = *p;
        if (b < t9) {
            p[b + 1] = arg1;
        }
        b++;
        if (b >= arg0[6]) b = 0;
        *p = b;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6F80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned int D_004A4834_6F80 __asm__("D_004A4834");

void func_003D6F80(unsigned char *shp) {
    int j, w, c, cnt, bit;
    unsigned char *t;
    unsigned int r, start, end, byte;
    int n = shp[4] & 0xF;

    t = shp + ((shp[5] * (n + 2) + 0xF) & 0x3FFC) + n * 4;
    w = shp[5];
    c = *t;
    if (c > 0) {
        r = D_004A4834_6F80 % c;
        start = r * w / c;
        end = (r + 1) * w / c;
        bit = start & 7;
        byte = (start >> 3) + 1;
        cnt = end - start;
        for (j = 0; j < cnt; j++) {
            t[byte] |= 1 << bit;
            bit++;
            if (bit == 8) {
                bit = 0;
                byte++;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7038);
#ifdef SKIP_ASM
void func_003D7038(unsigned char *p) {
    int n = p[4] & 0xF;
    int m = p[5];
    unsigned char *r = p + ((m * (n + 2) + 0xF) & 0x3FFC) + n * 4;
    if (*r != 0) {
        int cnt = (m + 7) / 8;
        if (cnt != 0) {
            int i = 1;
            do {
                r[i] = 0;
                i++;
            } while (i <= cnt);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D70B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int *D_004A4824_4824 __asm__("D_004A4824");
extern int D_004A4828_4828 __asm__("D_004A4828");

int func_003D70B0(void) {
    int i;
    int r = -1;

    for (i = 0; i < D_004A4828_4828; i++) {
        if (D_004A4824_4824[i] == 0) {
            r = i;
            break;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7110);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_7110 { unsigned char *p; int x; };
extern struct E_7110 D_0044FFB8_7110[] __asm__("D_0044FFB8");

static __inline__ unsigned short *lookup_7110(unsigned char *base, unsigned short id) {
    unsigned short n = *(unsigned short *)(base + 0x10);
    int j;
    for (j = 0; j < n; j++) {
        unsigned short *r = (unsigned short *)(base + ((unsigned short *)(base + 0x18))[j] * 4);
        if (*r == id) {
            return r;
        }
    }
    return 0;
}

unsigned short *func_003D7110(unsigned char *arg0) {
    struct E_7110 *res;
    struct E_7110 *e = D_0044FFB8_7110;
    unsigned short *ret = 0;
    struct E_7110 **pres = &res;
    int found = 0;
    int i = 0;
    do {
        unsigned char *q = e->p;
        if (q != 0 && q[9] == arg0[2] && q[8] == arg0[3]) {
            *pres = e;
            found = 1;
            goto done;
        }
        i++;
        e++;
    } while (i < 8);
done:
    if (found) {
        ret = lookup_7110(res->p, *(unsigned short *)arg0);
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D71D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct R_71D8 { int f0; short h; char c; unsigned char d; int pad8; int fc; int arr[20]; };
struct G_71D8 { int z[8]; int a[8]; int b[8]; int n; struct R_71D8 r[16]; };
extern struct G_71D8 D_0044FFF8_71D8 __asm__("D_0044FFF8");
extern int D_004A4840;
extern short D_004A4844;

void func_003D71D8(void) {
    int i, j;
    for (i = 0; i < 8; i++) {
        D_0044FFF8_71D8.z[i] = 0;
        D_0044FFF8_71D8.a[i] = -1;
        D_0044FFF8_71D8.b[i] = -1;
    }
    D_0044FFF8_71D8.n = 0;
    for (i = 0; i < 16; i++) {
        D_0044FFF8_71D8.r[i].c = 0;
        D_0044FFF8_71D8.r[i].h = 0;
        D_0044FFF8_71D8.r[i].f0 = 0;
        D_0044FFF8_71D8.r[i].fc = 0;
        D_0044FFF8_71D8.r[i].d = 0xFF;
        for (j = 19; j >= 0; j--) {
            D_0044FFF8_71D8.r[i].arr[j] = 0;
        }
    }
    D_004A4840 = 0;
    D_004A4844 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D72A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct H_72A0 { unsigned short h0; unsigned short h2; unsigned short h4; };
struct R_72A0 { unsigned int f0; short h; unsigned char c; unsigned char d; short s8; struct H_72A0 *p; int arr[20]; };
struct G_72A0 { int z[8]; int a[8]; int b[8]; int n; struct R_72A0 r[16]; };
extern struct G_72A0 D_0044FFF8_72A0 __asm__("D_0044FFF8");
int func_003DB9A0(void);
void func_003D7C38(unsigned int);

int func_003D72A0(unsigned int arg0, int arg1, int arg2) {
    int i;
    int ret = -1;
    int skip = -1;
    unsigned int t;
    int d;
    unsigned int h;

    for (i = 0; i < 16; i++) {
        if (D_0044FFF8_72A0.r[i].c == 0) {
            ret = i;
            goto out;
        }
    }
    if (arg2 != 0) {
        skip = D_0044FFF8_72A0.b[arg1];
    }
    i = 0;
    t = func_003DB9A0();
    for (; i < 16; i++) {
        if (D_0044FFF8_72A0.r[i].s8 == 0 && (h = D_0044FFF8_72A0.r[i].p->h2) != 0 &&
            h < t - D_0044FFF8_72A0.r[i].f0 && skip != i) {
            func_003D7C38(i);
            ret = i;
            goto out;
        }
    }
    for (i = 0; i < 16; i++) {
        if (D_0044FFF8_72A0.r[i].s8 == 0) {
            d = D_0044FFF8_72A0.r[i].d;
            if (arg0 >= D_0044FFF8_72A0.r[i].p->h4 && d == arg1 && i != skip) {
                D_0044FFF8_72A0.r[i].c = 0;
                D_0044FFF8_72A0.z[d]--;
                ret = i;
                break;
            }
        }
    }
out:
    return ret;
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003D7418);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D76F0);
#ifdef SKIP_ASM
int func_003D7418(unsigned char *arg0);

// PORT: SN-specific va_start (gcc 2.95 EE EABI form); use <stdarg.h> off-PS2.
void func_003D76F0(int a0, int n, ...) {
    int buf[20];
    int *p;
    char *ap;
    ap = (char *)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    buf[0] = a0;
    if (n > 0) {
        p = &buf[1];
        do {
            ap += 8;
            *p++ = *(int *)(ap - 8);
        } while (--n != 0);
    }
    func_003D7418((unsigned char *)buf);
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003D7760);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D7A50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_7A50 { unsigned short h; int w; };
extern struct E_7A50 D_00450660_7A50[] __asm__("D_00450660");
struct L_7A50 { int n; unsigned short *ids; };
struct B_7A50 { unsigned char pad[6]; unsigned char b6; unsigned char lo : 4; signed char hi : 4; unsigned char pad8[2];
    unsigned char f0 : 1; unsigned char f1 : 1; unsigned char f2 : 1; unsigned char f3 : 1; unsigned char f4 : 1; };
unsigned short *func_003D7110(unsigned char *arg0);
int func_003D7760_7A50(struct L_7A50 *list, int arg1) __asm__("func_003D7760");

int func_003D7A50(int idx) {
    struct L_7A50 list;
    int ok = 0;
    struct B_7A50 *q;
    unsigned char *p;
    int r;

    list.n = 0;
    list.ids = 0;
    if (D_00450660_7A50[idx].h != 0xFFFF) {
        q = (struct B_7A50 *)func_003D7110((unsigned char *)&D_00450660_7A50[idx]);
        if (q != 0) {
            int f = 0;
            if (((unsigned char *)q)[0xA] >> 4 & 1) {
                p = (unsigned char *)q + (((q->b6 * 2 + 3) & 0xFFFFFFFC) + 0xC) + ((q->lo * 3 + 3) & ~3) + ((q->hi * 3 + 3) & ~3);
                f = 1;
                if (((unsigned char *)q)[0xA] >> 3 & 1) {
                    p += (q->b6 * 2 + 7) & 0xFFFFFFFC;
                }
                list.n = *p;
                list.ids = (unsigned short *)(p + 2);
            }
            ok = f;
        }
    }
    if (ok) {
        r = func_003D7760_7A50(&list, idx);
    } else {
        r = func_003D7760_7A50(0, idx);
    }
    if (ok && r < 0) {
        r = func_003D7760_7A50(0, idx);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7B98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct R_7B98 { unsigned int f0; unsigned short h; unsigned char c; unsigned char d; short s8; short next; void *p; int arr[20]; };
struct G_7B98 { int z[8]; int a[8]; int b[8]; int n; struct R_7B98 r[16]; };
extern struct G_7B98 D_0044FFF8_7B98 __asm__("D_0044FFF8");
void func_003D69A8(void);

void func_003D7B98(void) {
    int i;
    for (i = 0; i < 16; i++) {
        if (D_0044FFF8_7B98.r[i].c != 0) {
            D_0044FFF8_7B98.r[i].c = 0;
            D_0044FFF8_7B98.z[D_0044FFF8_7B98.r[i].d]--;
        }
    }
    for (i = 0; i < 8; i++) {
        D_0044FFF8_7B98.b[i] = -1;
        D_0044FFF8_7B98.a[i] = -1;
        if (D_0044FFF8_7B98.z[i] != 0) {
            D_0044FFF8_7B98.z[i] = 0;
        }
    }
    func_003D69A8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7C38);
#ifdef SKIP_ASM
struct E_7C38 {
    char pad0[0x6A];
    unsigned char flag;     // 0x6A
    unsigned char bucket;   // 0x6B
    short busy;             // 0x6C
    short next;             // 0x6E
};
struct T_7C38 {
    int a[8];
    int b[8];
    int c[8];
};
extern struct T_7C38 D_0044FFF8_7C38 __asm__("D_0044FFF8");
#define T D_0044FFF8_7C38
#define ENT(i) ((struct E_7C38 *)((char *)&T + (i) * 0x60))

void func_003D7C38(unsigned int n) {
    int nx = -1;
    if (n < 16) {
        struct E_7C38 *e = ENT(n);
        if (e->busy == 0) {
            int b;
            e->flag = 0;
            b = e->bucket;
            if (n == T.c[b]) {
                T.c[b] = -1;
            }
            if (n == T.b[b]) {
                T.b[b] = -1;
            }
            nx = e->next;
            while (nx != -1) {
                struct E_7C38 *q;
                if ((unsigned int)nx >= 16) {
                    break;
                }
                q = ENT(nx);
                if (q->busy != 0 && q->flag != 0) {
                    if (nx == T.b[b]) {
                        T.b[b] = -1;
                    }
                    q->flag = 0;
                    nx = q->next;
                } else {
                    nx = -1;
                }
            }
            if (ENT(n)->busy == 0) {
                T.a[b]--;
            }
            if (T.a[b] < 0) {
                T.a[b] = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7D58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_7D58 { char pad[9]; signed char b9; unsigned char bA; };
struct R_7D58 { unsigned int f0; unsigned short h; unsigned char c; unsigned char d; short s8; short next; struct P_7D58 *p; int arr[20]; };
struct G_7D58 { int z[8]; int a[8]; int b[8]; int n; struct R_7D58 r[16]; };
extern struct G_7D58 D_0044FFF8_7D58 __asm__("D_0044FFF8");
void func_003D7C38(unsigned int);

void func_003D7D58(int a) {
    int i;
    unsigned int f0, f;
    unsigned int h, hi;
    int d;

    f0 = D_0044FFF8_7D58.r[a].f0;
    d = D_0044FFF8_7D58.r[a].d;
    h = D_0044FFF8_7D58.r[a].h;
    D_0044FFF8_7D58.n = 0;
    for (i = 0; i < 16; i++) {
        if (i == a) continue;
        if (D_0044FFF8_7D58.r[i].c == 0) continue;
        if (D_0044FFF8_7D58.r[i].d != d) continue;
        if (D_0044FFF8_7D58.r[i].s8 != 0) continue;
        f = D_0044FFF8_7D58.r[i].f0;
        hi = D_0044FFF8_7D58.r[i].h;
        if (f < f0 || (f == f0 && hi < h)) {
            if ((D_0044FFF8_7D58.r[i].p->bA >> 2) & 1) continue;
            func_003D7C38(i);
        } else if (D_0044FFF8_7D58.r[i].p->b9 == 100) {
            if (D_0044FFF8_7D58.r[i].d == d) {
                D_0044FFF8_7D58.n = 1;
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D7EC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct K_7EC8 { unsigned char b[4]; };
struct R_7EC8 { unsigned int f0; unsigned short h; unsigned char c; unsigned char d; short s8; short next; void *p; int arr[20]; };
struct G_7EC8 { int z[8]; int a[8]; int b[8]; int n; struct R_7EC8 r[16]; };
extern struct G_7EC8 D_0044FFF8_7EC8 __asm__("D_0044FFF8");
struct S_7EC8 { int a; int b; int c; int (*fn)(struct K_7EC8 *); };
extern struct S_7EC8 D_0044FF90_7EC8 __asm__("D_0044FF90");
int func_003D7A50(int idx);
void func_003D7C38(unsigned int);
void func_003D7D58(int idx);
void func_003D9A40(void);
int func_003DA418(int);

int func_003D7EC8(int a);
int func_003D7EC8(int a) {
    int r = 0;
    int done = 0;
    int idx, t, s;
    struct K_7EC8 k;
    if (D_0044FFF8_7EC8.z[a] != 0) {
        do {
            idx = func_003D7A50(a);
            if (idx < 0) goto out;
            k = *(struct K_7EC8 *)D_0044FFF8_7EC8.r[idx].arr;
            t = 1;
            if (D_0044FF90_7EC8.fn != 0) {
                t = D_0044FF90_7EC8.fn(&k);
            }
            if (t == 1) {
                done = 1;
            } else {
                func_003D7C38(idx);
            }
        } while (done == 0);
        func_003D7D58(idx);
        s = idx;
        func_003D9A40();
        do {
            r = func_003DA418(s);
            s = D_0044FFF8_7EC8.r[s].next;
        } while (s != -1 && r != 0);
        func_003D7C38(idx);
    }
out:
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8008);
#ifdef SKIP_ASM
typedef struct { short a; signed char b; signed char c; } D8008_S;

int func_003D8008(int arg0, int arg1, int arg2) {
    D8008_S u;
    u.c = arg0;
    u.b = arg1;
    u.a = arg2;
    return *(int *)&u;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8028);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044FFF8_8028[128] __asm__("D_0044FFF8");

int func_003D8028(int arg0) {
    return D_0044FFF8_8028[arg0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8040);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A484C_8040 __asm__("D_004A484C");
int func_003DA3F0(int x);
int func_003D7EC8(int);
int func_003D9BD8(int);

int func_003D8040(int arg0) {
    int r = 0;
    if (D_004A484C_8040 == 0) {
        D_004A484C_8040 = 1;
        if (func_003DA3F0(arg0) != 0 || func_003D7EC8(arg0) != 0) {
            r = func_003D9BD8(arg0);
        }
    }
    D_004A484C_8040 = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D80B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct G_80B0 { int z[8]; unsigned int a[8]; unsigned int b[8]; };
extern struct G_80B0 D_0044FFF8_80B0 __asm__("D_0044FFF8");
extern int D_004A484C_80B0 __asm__("D_004A484C");
void func_003D9A40(void);
int func_003DA418(int);
void func_003D7C38(unsigned int);
int func_003D9BD8(int);

void func_003D80B0(int x) {
    if (D_004A484C_80B0 == 0) {
        unsigned int a = D_0044FFF8_80B0.a[x];
        unsigned int b = D_0044FFF8_80B0.b[x];
        int ok;
        D_004A484C_80B0 = 1;
        ok = 1;
        if (a >= 16) ok = 0;
        if (b >= 16) ok = 0;
        if (ok) {
            int r;
            func_003D9A40();
            r = func_003DA418(b);
            func_003D7C38(b);
            if (r != 0) {
                func_003D9BD8(x);
            }
        }
    }
    D_004A484C_80B0 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8158);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004506A0_8158[128] __asm__("D_004506A0");

void func_003D8158(int arg0, int arg1) {
    D_004506A0_8158[arg1] = arg0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D8170);
#ifdef SKIP_ASM
extern int func_003D7EC8(int);

void func_003D8170(void) {
    func_003D7EC8(0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D8190);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D7EC8(int);
extern int func_003D9BD8(int);
extern int func_003DA3F0(int);
extern int D_004A484C_484C __asm__("D_004A484C");

void func_003D8190(void) {
    if (D_004A484C_484C == 0) {
        D_004A484C_484C = 1;
        if (func_003DA3F0(0) != 0) {
            func_003D9BD8(0);
        } else if (func_003D7EC8(0) != 0) {
            func_003D9BD8(0);
        }
    }
    D_004A484C_484C = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D81F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E82B0 { unsigned char *p; int x; };
extern struct E82B0 D_0044FFB8_82B0[] __asm__("D_0044FFB8");

int func_003D81F0(unsigned char *arg0, int *arg1) {
    struct E82B0 *res;
    struct E82B0 *e = D_0044FFB8_82B0;
    int ret = 0;
    struct E82B0 **pres = &res;
    int found = 0;
    int i = 0;
    do {
        unsigned char *q = e->p;
        if (q != 0 && q[9] == arg0[2] && q[8] == arg0[3]) {
            *pres = e;
            found = 1;
            goto done;
        }
        i++;
        e++;
    } while (i < 8);
done:
    if (found) {
        ret = 1;
        *arg1 = res->x;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8278);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044FFB8_8278[] __asm__("D_0044FFB8");

void func_003D8278(void) {
    int *var_2;
    int var_3;

    var_3 = 7;
    var_2 = D_0044FFB8_8278;
    do {
        var_2[0] = 0;
        var_3 -= 1;
        var_2[1] = 0;
        var_2 += 2;
    } while (var_3 >= 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D82B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern struct E82B0 D_0044FFB8_82B0[] __asm__("D_0044FFB8");

unsigned short func_003D82B0(unsigned char *arg0) {
    struct E82B0 *res;
    struct E82B0 *e = D_0044FFB8_82B0;
    unsigned short ret = 0;
    struct E82B0 **pres = &res;
    int found = 0;
    int i = 0;
    do {
        unsigned char *q = e->p;
        if (q != 0 && q[9] == arg0[2] && q[8] == arg0[3]) {
            *pres = e;
            found = 1;
            goto done;
        }
        i++;
        e++;
    } while (i < 8);
done:
    if (found) {
        ret = *(unsigned short *)(res->p + 0x14);
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8330);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern struct E82B0 D_0044FFB8_82B0[] __asm__("D_0044FFB8");

int func_003D8330(unsigned char *arg0, int *arg1) {
    struct E82B0 *res;
    struct E82B0 *e = D_0044FFB8_82B0;
    int ret = 0;
    struct E82B0 **pres = &res;
    int found = 0;
    int i = 0;
    do {
        unsigned char *q = e->p;
        if (q != 0 && q[9] == arg0[2] && q[8] == arg0[3]) {
            *pres = e;
            found = 1;
            goto done;
        }
        i++;
        e++;
    } while (i < 8);
done:
    if (found) {
        ret = 1;
        *arg1 = res->p[9];
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D83B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_83B8 { unsigned char *p; int x; };
extern struct E_83B8 D_0044FFB8_83B8[] __asm__("D_0044FFB8");

int func_003D83B8(unsigned char *arg0, unsigned char **arg1) {
    struct E_83B8 *res;
    struct E_83B8 *e = D_0044FFB8_83B8;
    int ret = 0;
    struct E_83B8 **pres = &res;
    int found = 0;
    int i = 0;
    do {
        unsigned char *q = e->p;
        if (q != 0 && q[9] == arg0[2] && q[8] == arg0[3]) {
            *pres = e;
            found = 1;
            goto done;
        }
        i++;
        e++;
    } while (i < 8);
done:
    if (found) {
        unsigned char *p = res->p;
        ret = 1;
        *arg1 = p + (((*(unsigned short *)(p + 0x10) * 2 + 3) & 0xFFFFFFFC) + 0x18);
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8460);
#ifdef SKIP_ASM
unsigned short *func_003D8460(void *arg0, int arg1) {
    int var_7;
    unsigned short *var_2;
    unsigned short *var_6;
    unsigned short temp_8;

    temp_8 = (*(unsigned short *)((char*)(arg0) + (0x10)));
    var_7 = 0;
    if (temp_8 != 0) {
        var_6 = arg0 + 0x18;
loop_2:
        var_2 = arg0 + (*var_6 * 4);
        var_7 += 1;
        if (*var_2 != arg1) {
            var_6 += 1;
            if (var_7 >= (int) temp_8) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        var_2 = 0;
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D84A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_84A0 { unsigned char *p; int x; };
extern struct E_84A0 D_0044FFB8_84A0[] __asm__("D_0044FFB8");

int func_003D84A0(unsigned char *arg0, struct E_84A0 **pres) {
    struct E_84A0 *e = D_0044FFB8_84A0;
    int found = 0;
    int i = 0;
    do {
        unsigned char *q = e->p;
        if (q != 0 && q[9] == arg0[2] && q[8] == arg0[3]) {
            *pres = e;
            found = 1;
            goto done;
        }
        i++;
        e++;
    } while (i < 8);
done:
    return found;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8500);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_8500 { unsigned int z[8]; unsigned int a[8]; unsigned int b[8]; };
extern struct S_8500 D_0044FFF8_8500 __asm__("D_0044FFF8");
int func_003D8500(int i) {
    int r = D_0044FFF8_8500.a[i] < 0x10;
    if (D_0044FFF8_8500.b[i] >= 0x10) r = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8530);
#ifdef SKIP_ASM
void func_003D8530(void *arg0) {
    *(int *)((char *)arg0 + 0) = 0;
    *(int *)((char *)arg0 + 4) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8540);
#ifdef SKIP_ASM
int func_003D8540(int arg0, int *arg1) {
    unsigned key = arg0 & 0xFFFF;
    int i;
    int found = 0;
    for (i = 0; i < arg1[0]; i++) {
        if ((*(unsigned short **)(arg1 + 1))[i] == key) {
            found = 1;
            break;
        }
    }
    return found;
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003D8598);

INCLUDE_ASM("ealib/seg_2D7498", func_003D85C8);

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8780);
#ifdef SKIP_ASM
static __inline__ unsigned char *tail_8780(unsigned char *s) {
    int n = s[4] & 0xF;
    return s + ((s[5] * (n + 2) + 0xF) & 0x3FFC) + n * 4;
}

static __inline__ int bit_8780(unsigned char *b, int i) {
    unsigned char m = 1 << (i % 8);
    return b[i / 8] & m;
}

int func_003D8780(short *p, unsigned char *shp, int x) {
    int r = 1;
    int h, bit;
    int idx;
    unsigned char *q, *t;
    int extra;

    if (shp[5] < x) {
        r = 0;
    } else {
        h = p[1];
        if (h != -1) {
            bit = 0;
            if (h < *(unsigned short *)(shp + 0xA)) {
                idx = shp[5] * h + x;
                extra = 0;
                t = tail_8780(shp);
                if (shp[4] & 0x80) {
                    extra = (shp[5] + 7) / 8 + 1;
                }
                q = t + extra;
                if (shp[6]) {
                    q += shp[6] + 1;
                }
                bit = bit_8780(q, idx);
            }
            r = bit;
            if (r == 0) {
                goto out;
            }
        }
        if (shp[4] & 0x80) {
            r = bit_8780(tail_8780(shp) + 1, x);
        }
    }
out:
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003D88C8);

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8CB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct H_8CB0 { char pad[6]; unsigned char n; char pad2[5]; unsigned short ids[1]; };
extern unsigned int D_004506E0_8CB0[] __asm__("D_004506E0");

#define WEIGHT_8CB0(p) ((*(p) & 0x1F) * D_004506E0_8CB0[*(p) >> 5])

void func_003D8CB0(struct H_8CB0 *h, unsigned char *out) {
    int w[100];
    int n = h->n;
    int total = 0;
    int k;
    int i;
    int r;
    unsigned char *e;

    for (i = 0; i < n; i++) {
        e = (unsigned char *)h + h->ids[i] * 4;
        w[i] = WEIGHT_8CB0(e);
        total += WEIGHT_8CB0(e);
    }
    k = 0;
    while (total > 0) {
        r = func_003DB5C0(total, -1);
        for (i = 0; i < n; i++) {
            r -= w[i];
            if (r < 0) break;
        }
        out[k++] = i;
        total -= w[i];
        w[i] = 0;
    }
    for (i = 0; i < n; i++) {
        e = (unsigned char *)h + h->ids[i] * 4;
        if (WEIGHT_8CB0(e) == 0) {
            out[k++] = i;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8E58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_8E58 { short x; char pad[2]; unsigned char start; unsigned char len; unsigned char cur; unsigned char flag; };
struct H_8E58 { struct E_8E58 ent[12]; char pad[2]; unsigned char tbl[1]; };
struct O_8E58 { int len; int start; int n; unsigned char col[4]; };
struct L_8E58 { char pad[4]; unsigned char cnt; unsigned char n5; unsigned char n6; char pad2; unsigned char list[1]; };
struct C_8E58 { char pad[4]; signed char n; char pad2[3]; unsigned char a[8]; unsigned char b[8]; };
extern int func_003DB838_8E58(unsigned char *, int, struct O_8E58 *) __asm__("func_003DB838");
extern unsigned char **D_004A4824_8E58 __asm__("D_004A4824");

int func_003D8E58_impl(struct H_8E58 *h, struct L_8E58 *l) __asm__("func_003D8E58");
int func_003D8E58_impl(struct H_8E58 *h, struct L_8E58 *l) {
    struct O_8E58 o;
    int ok = 1;
    int i;
    int i0;
    int j;
    int cnt;
    int redo;
    int n;
    int *tab;
    unsigned char *lp;
    struct C_8E58 *c;
    int bv;
    int v;

    tab = (int *)((unsigned char *)l + ((((l->cnt >> 2) + 3) & 0x7C) + 8) + l->n6 * 4);
    for (i0 = 0; i0 < l->n5; i0++) {
        tab[i0] = 0;
    }
    for (i = 11; i >= 0; i--) {
        h->ent[i].flag = 0;
    }
    cnt = l->cnt >> 2;
    do {
        redo = 1;
        i = 0;
        if (cnt != 0) {
            lp = (unsigned char *)l + 8;
            do {
                if (h->ent[i].flag == 0) {
                    h->ent[i].flag = 1;
                    c = (struct C_8E58 *)((int *)l + lp[i]);
                    n = c->n;
                    if (!func_003DB838_8E58(D_004A4824_8E58[h->ent[i].x], h->tbl[h->ent[i].cur], &o)) {
                        ok = 0;
                        goto out;
                    }
                    for (j = 0; j < n; j++) {
                        bv = c->b[j];
                        if (bv == 0xFF) continue;
                        if (!(bv & 0x80)) continue;
                        bv &= 0x7F;
                        if (c->a[j] == 0xFF) {
                            v = tab[bv];
                            if (v == 0) {
                                h->ent[i].flag = 0;
                                redo = 0;
                                continue;
                            }
                            if (!((v >> o.col[j]) & 1)) {
                                ok = 0;
                                goto out;
                            }
                        } else if (c->a[j] == 0xFE) {
                            tab[bv] = 1 << o.col[j];
                        }
                    }
                }
                i++;
            } while (i < cnt);
        }
    } while (!redo);
out:
    return ok;
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003D9088);

INCLUDE_ASM("ealib/seg_2D7498", func_003D93C0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D95B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_95B8 { short x; char pad[2]; unsigned char start; unsigned char len; unsigned char cur; unsigned char flag; };
struct H_95B8 { struct E_95B8 ent[12]; char pad[2]; unsigned char tbl[1]; };
struct O_95B8 { int len; int start; int n; unsigned char col[4]; };
struct L_95B8 { char pad[4]; unsigned char cnt; unsigned char n5; char pad2[2]; unsigned char list[1]; };
struct C_95B8 { char pad[4]; signed char n; char pad2[3]; unsigned char a[8]; unsigned char b[8]; };
extern int func_003D83B8_95B8(void *, unsigned char **) __asm__("func_003D83B8");
extern int func_003DB838_95B8(unsigned char *, int, struct O_95B8 *) __asm__("func_003DB838");
extern int func_003D93C0_95B8(struct L_95B8 *, struct H_95B8 *, int) __asm__("func_003D93C0");
extern unsigned char **D_004A4824_95B8 __asm__("D_004A4824");
extern int func_003DB5C0(int, int);

static __inline__ void shuffle_95B8(struct L_95B8 *l, struct H_95B8 *h) {
    int i = 0;
    int j;
    int n = l->cnt >> 2;
    struct E_95B8 *e;
    unsigned char *p;
    unsigned char *q;
    unsigned char t;

    for (; i < n; i++) {
        e = &h->ent[i];
        p = &h->tbl[e->start];
        for (j = e->len; j >= 2; j--) {
            q = &p[func_003DB5C0(j, -1)];
            t = p[j - 1];
            p[j - 1] = *q;
            *q = t;
        }
    }
}

static __inline__ void apply_95B8(void *a0, struct H_95B8 *h, struct L_95B8 *l) {
    struct O_95B8 o;
    unsigned char *out;
    int n;
    int i;
    int j;
    struct C_95B8 *c;

    if (func_003D83B8_95B8(a0, &out) != 0) {
        i = 0;
        n = l->cnt >> 2;
        for (; i < n; i++) {
            c = (struct C_95B8 *)((int *)l + l->list[i]);
            for (j = 0; j < c->n; j++) {
                if (c->a[j] == 0xFE && !(c->b[j] & 0x80)) {
                    if (func_003DB838_95B8(D_004A4824_95B8[h->ent[i].x], h->tbl[h->ent[i].cur], &o)) {
                        out[c->b[j]] = o.col[j];
                    }
                }
            }
        }
    }
}

int func_003D95B8(void *a0, struct H_95B8 *h, struct L_95B8 *l, int mode, int thr) {
    int ok;
    int i;
    int n;

    if (mode == 1 || l->n5 != 0) {
        shuffle_95B8(l, h);
        ok = func_003D93C0_95B8(l, h, mode != 2 ? thr : 0);
    } else {
        ok = 1;
        n = l->cnt >> 2;
        for (i = 0; i < n; i++) {
            if (h->ent[i].len == 0) {
                ok = 0;
                goto end;
            }
            h->ent[i].cur = h->ent[i].start + func_003DB5C0(h->ent[i].len, h->ent[i].x);
        }
    }
    apply_95B8(a0, h, l);
end:
    return ok;
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003D9830);

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9A40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Q9A40 { short a, b, c, d; };
struct R9A40 { int f0; int f4; unsigned char b8; unsigned char b9; unsigned char ba; unsigned char bb; char pad[0x5C - 12]; };
struct G9A40 { int f0, f4, f8; struct Q9A40 q[0x30]; struct R9A40 r[8]; };
extern struct G9A40 D_00450700_9A40 __asm__("D_00450700");

void func_003D9A40(void) {
    int i;
    D_00450700_9A40.f0 = -1;
    D_00450700_9A40.f4 = 0;
    D_00450700_9A40.f8 = 0;
    for (i = 0; i < 8; i++) {
        D_00450700_9A40.r[i].f0 = 0;
        D_00450700_9A40.r[i].f4 = 0;
        D_00450700_9A40.r[i].b8 = 0;
        D_00450700_9A40.r[i].b9 = 0;
        D_00450700_9A40.r[i].bb = 0;
    }
    for (i = 0; i < 0x30; i++) {
        D_00450700_9A40.q[i].a = -1;
        D_00450700_9A40.q[i].b = -1;
        D_00450700_9A40.q[i].c = 0;
        D_00450700_9A40.q[i].d = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9AC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Q_9AC8 { short a, b, c, d; };
struct R_9AC8 { int f0; unsigned char *f4; char b8; unsigned char b9; unsigned char ba; unsigned char bb; int data[20]; };
struct G_9AC8 { int f0, f4, f8; struct Q_9AC8 q[0x30]; struct R_9AC8 r[8]; };
struct E_9AC8 { unsigned short x; unsigned short y; unsigned short z; unsigned char idx; unsigned char pad; };
struct H_9AC8 { struct E_9AC8 ent[12]; char pad[2]; unsigned char tbl[1]; };
extern struct G_9AC8 D_00450700_9AC8 __asm__("D_00450700");

void func_003D9AC8(struct H_9AC8 *h, int id, int a2, unsigned char *a3, int a4, int *a5) {
    int n;
    int i;
    int cnt;
    int j;

    if (D_00450700_9AC8.f0 < 0 || D_00450700_9AC8.f0 == id) {
        n = D_00450700_9AC8.f4++;
        if (n < 8) {
            D_00450700_9AC8.f0 = id;
            D_00450700_9AC8.r[n].f0 = a2;
            D_00450700_9AC8.r[n].f4 = a3;
            D_00450700_9AC8.r[n].b8 = a4;
            for (i = 0; i < 20; i++) {
                D_00450700_9AC8.r[n].data[i] = a5[i];
            }
            D_00450700_9AC8.r[n].b9 = 1;
            cnt = a3[4] >> 2;
            j = D_00450700_9AC8.f8;
            for (i = 0; i < cnt; i++) {
                D_00450700_9AC8.q[j + i].a = h->ent[i].x;
                D_00450700_9AC8.q[j + i].b = h->ent[i].y;
                D_00450700_9AC8.q[j + i].c = h->tbl[h->ent[i].idx];
            }
            D_00450700_9AC8.f8 += cnt;
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003D9BD8);

INCLUDE_ASM("ealib/seg_2D7498", func_003D9ED0);

INCLUDE_ASM("ealib/seg_2D7498", func_003D9FB0);

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA3A8);
#ifdef SKIP_ASM
void func_003DA3A8(void *arg0, int *arg1, int *arg2) {
    *arg1 = (int) (*(unsigned char *)((char*)(arg0) + (8)));
    *arg2 = (int) (*(unsigned char *)((char*)(arg0) + (9)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA3C0);
#ifdef SKIP_ASM
extern int D_004A483C;

void func_003DA3C0(int arg0) {
    D_004A483C = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA3C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned int D_004506E0_A3C8[] __asm__("D_004506E0");
unsigned int func_003DA3C8(unsigned int a) {
    a &= 0xFF;
    return (a & 0x1F) * D_004506E0_A3C8[a >> 5];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA3F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_A3F0 { int a; int b; int c; };
extern struct S_A3F0 D_00450700_A3F0 __asm__("D_00450700");
int func_003DA3F0(int x) {
    int r = 0;
    if (D_00450700_A3F0.a == x)
        r = D_00450700_A3F0.b > 0;
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003DA418);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct G_A418 { int pad[4]; int (*cb)(int, void *); };
struct E_A418 { char data[0x60]; };
extern struct G_A418 D_0044FF90_A418 __asm__("D_0044FF90");
extern struct E_A418 D_0045006C_A418[] __asm__("D_0045006C");
extern int func_003D9FB0_A418(struct E_A418 *) __asm__("func_003D9FB0");

int func_003DA418(int idx) {
    struct E_A418 *e = &D_0045006C_A418[idx];
    int r;
    int i;
    int k;

    r = func_003D9FB0_A418(e);
    if (r == 0 && D_0044FF90_A418.cb != 0) {
        i = 0;
        do {
            k = D_0044FF90_A418.cb(i, e);
            if (k >= 0) {
                r = func_003D9FB0_A418(e);
            }
            i++;
        } while (r == 0 && k > 0);
    }
    if (r > -1) {
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA4E0);
#ifdef SKIP_ASM
void func_003DA4E0(unsigned char *a, unsigned char *b, unsigned char *c) {
    int i;
    signed char n;
    unsigned char t;
    unsigned char *base;
    int *w;
    i = 0;
    n = b[4];
    base = a + ((((a[4] >> 2) + 3) & 0x7C) + 8) + a[6] * 4;
    if (n > 0) {
        unsigned char *q = b + 0x10;
        do {
            if (q[-8] == 0xFE) {
                t = q[0];
                if (t & 0x80) {
                    w = (int *)((t & 0x7F) * 4 + (int)base);
                    *w |= 1 << c[i];
                }
            }
            i++;
            q++;
        } while (i < n);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA578);
#ifdef SKIP_ASM
struct S_A578 {
    char pad[4];
    signed char n;
    char pad2[3];
    unsigned char arr[1];
};
int func_003DA578(struct S_A578 *p) {
    int i;
    int r = 0;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (p->arr[i] == 0xFE) {
            r = 1;
            break;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA5C8);
#ifdef SKIP_ASM
struct R_A5C8 { short a; short b; };
struct T_A5C8 { unsigned short a; unsigned short b; };
static __inline__ int gt_A5C8(int a, int b) { return a > b; }

int func_003DA5C8(unsigned char *p, struct T_A5C8 *tbl, struct R_A5C8 *out) {
    unsigned int idx = p[2];
    unsigned int mode = p[3];
    unsigned short v = *(unsigned short *)p;
    int r;
    out->b = -1;
    out->a = -1;
    switch (mode) {
    case 0:
        out->a = func_003D6D50(v);
        break;
    case 1:
        if (idx >= 20) {
            out->a = -1;
        } else {
            out->a = func_003D6DB8(v, tbl[idx].a);
        }
        break;
    case 2: {
        struct T_A5C8 *e;
        int t = func_003D6D50(v);
        e = (struct T_A5C8 *)(idx * 4 + (int)tbl);
        if (func_003D6CF8(t, *(int *)e) != 0) {
            out->b = e->a;
        } else {
            t = -1;
        }
        out->a = t;
        break;
    }
    }
    r = out->a;
    return gt_A5C8(r, -1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA6B0);
#ifdef SKIP_ASM
void func_003DA6B0(char *arg0, int arg1) {
    int temp_8;
    int temp_3;
    unsigned char *temp_4;

    temp_8 = *(unsigned char *)(arg0 + 4) & 0xF;
    temp_3 = arg1 / 8;
    temp_4 = (unsigned char *)(arg0 + ((*(unsigned char *)(arg0 + 5) * (temp_8 + 2) + 0xF) & 0x3FFC) + temp_8 * 4 + (temp_3 + 1));
    *temp_4 &= ~(1 << (arg1 - temp_3 * 8));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA718);
#ifdef SKIP_ASM
int func_003DA718(unsigned char *arg0, int arg1) {
    int temp_3 = arg1 / 8;
    unsigned char m = 1 << (arg1 - temp_3 * 8);
    return arg0[temp_3] & m;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA750);
#ifdef SKIP_ASM
int func_003DA750(char *h, unsigned char *p, int bit) {
    int a = *(short *)(h + 2);
    int res = 0;
    if (a < *(unsigned short *)(p + 0xA)) {
        int k = 0;
        unsigned char *r, *q;
        unsigned char mask;
        int idx;
        bit += p[5] * a;
        q = p + ((p[5] * ((p[4] & 0xF) + 2) + 0xF) & 0x3FFC) + (p[4] & 0xF) * 4;
        if (p[4] & 0x80) {
            k = (p[5] + 7) / 8 + 1;
        }
        r = q + k;
        if (p[6]) {
            r += p[6] + 1;
        }
        idx = bit / 8;
        mask = 1 << (bit - idx * 8);
        res = r[idx] & mask;
    }
    return res;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA810);
#ifdef SKIP_ASM
struct S_A810 {
    char pad[0x61];
    unsigned char n;
    signed char buf[1];
};

int func_003DA810(struct S_A810 *s, int c) {
    int r = 0;
    if (s->n < 0xC8U) {
        r = 1;
        s->buf[s->n] = c;
        s->n++;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA848);
#ifdef SKIP_ASM
struct S_A848 {
    char pad[8];
    unsigned char arr[1];
};
int func_003DA848(struct S_A848 *arg0, unsigned char *arg1, int *arg2) {
    int *q;
    int n;
    int ok;
    int i;
    unsigned char c;

    ok = 1;
    n = arg1[4] & 0xF;
    i = 0;
    q = (int *)(arg1 + ((arg1[5] * (n + 2) + 0xF) & 0x3FFC));
    if (n != 0) {
        do {
            c = arg0->arr[i];
            if (c != 0 && c != 0xFF && c != 0xFE) {
                if (!(q[i] & arg2[c])) {
                    ok = 0;
                    break;
                }
            }
            i++;
        } while (i < n);
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA8E0);
#ifdef SKIP_ASM
extern int D_004A4838;

int func_003DA8E0(int arg0) {
    int var_2;

    var_2 = 0;
    if (D_004A4838 != 0) {
        var_2 = (int) (arg0 * 0x64) / (int) D_004A4838;
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA910);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_A910 { short x; unsigned short y; unsigned short z; unsigned char idx; unsigned char pad; };
struct H_A910 { struct E_A910 ent[12]; char pad[2]; unsigned char tbl[1]; };
struct O_A910 { int len; int start; int n; unsigned char col[4]; };
extern int func_003DB838_A910(unsigned char *, int, struct O_A910 *) __asm__("func_003DB838");
extern unsigned char **D_004A4824_A910 __asm__("D_004A4824");
extern int D_004A4838;

int func_003DA910(unsigned char *a0, struct H_A910 *h) {
    struct O_A910 o;
    int total = 0;
    int i;
    int r;
    int cnt = a0[4] >> 2;

    for (i = 0; i < cnt; i++) {
        if (func_003DB838_A910(D_004A4824_A910[h->ent[i].x], h->tbl[h->ent[i].idx], &o)) {
            total += o.len;
        }
    }
    r = 0;
    if (D_004A4838 != 0) {
        r = total * 100 / D_004A4838;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA9C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_A9C8 { unsigned short h; int w; };
extern struct E_A9C8 D_00450660_A9C8[] __asm__("D_00450660");

int func_003DA9C8(char *p, int idx) {
    int r = 1;
    if (*(unsigned short *)p == D_00450660_A9C8[idx].h) {
        int v = p[8];
        if (v > 0) {
            if (!(D_00450660_A9C8[idx].w < v)) {
                r = 0;
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAA10);
#ifdef SKIP_ASM
int func_003DAA10(void *arg0, int arg1) {
    int temp_3;

    temp_3 = (*(unsigned char *)((char*)(arg0) + (4))) & 3;
    if (((temp_3 == 1) && (arg1 == 2)) || ((temp_3 == 2) && (arg1 != temp_3))) {
        return 1;
    }
    return temp_3 == 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAA50);
#ifdef SKIP_ASM
void func_003DAA50(unsigned char *arg0) {
    int *q;
    int i;
    q = (int *)(arg0 + ((((arg0[4] >> 2) + 3) & 0x7C) + 8) + (arg0[6] * 4));
    for (i = 0; i < arg0[5]; i++) {
        q[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAAB0);
#ifdef SKIP_ASM
struct S_AAB0 {
    char pad[4];
    signed char n;
    char pad2[3];
    unsigned char a[8];
    unsigned char b[8];
};
int func_003DAAB0(unsigned char *h, struct S_AAB0 *s) {
    int ok = 1;
    int i;
    int *tab;
    int n = s->n;
    int b;
    for (i = 0; i < n; i++) {
        if (s->a[i] == 0xFF) {
            b = s->b[i];
            if (b != 0xFF && (b & 0x80)) {
                tab = (int *)(h + ((((h[4] >> 2) + 3) & 0xFFFFFFFC) + 8) + ((h[6] * 4 + 3) & 0xFFFFFFFC));
                if (tab != 0) {
                    b &= 0x7F;
                    if (tab[b] == 0) {
                        ok = 0;
                        break;
                    }
                }
            }
        }
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAB58);
#ifdef SKIP_ASM
struct E_AB58 { char pad[4]; unsigned char off; unsigned char cnt; char pad2[2]; };
struct H_AB58 { struct E_AB58 ent[12]; char pad[2]; unsigned char tbl[1]; };
extern int func_003DB5C0(int, int);

void func_003DAB58(unsigned char *a0, struct H_AB58 *h) {
    int i = 0;
    int j;
    int n = a0[4] >> 2;
    struct E_AB58 *e;
    unsigned char *p;
    unsigned char *q;
    unsigned char t;

    for (; i < n; i++) {
        e = &h->ent[i];
        p = &h->tbl[e->off];
        for (j = e->cnt; j >= 2; j--) {
            q = &p[func_003DB5C0(j, -1)];
            t = p[j - 1];
            p[j - 1] = *q;
            *q = t;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAC20);
#ifdef SKIP_ASM
struct E_AC20 {
    int pad;
    unsigned char start;
    unsigned char len;
    unsigned char cur;
    unsigned char pad2;
};
int func_003DAC20(unsigned char *h, struct E_AC20 *e) {
    int wrap = 0;
    int done = 0;
    int i = (h[4] >> 2) - 1;
    struct E_AC20 *p = &e[i];
    int t = p->len;
    int limit = p->start + t;
    do {
        if (++p->cur < limit) {
            done = 1;
        } else {
            p->cur = p->start;
            if (--i < 0) {
                done = 1;
                wrap = 1;
            }
            p = &e[i];
            t = p->len;
            limit = p->start + t;
        }
    } while (!done);
    return wrap;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DACA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003DB5C0_ACA8(unsigned char, short) __asm__("func_003DB5C0");

int func_003DACA8(void *arg0) {
    (*(signed char *)((char*)(arg0) + (6))) = (signed char) ((*(unsigned char *)((char*)(arg0) + (4))) + func_003DB5C0_ACA8((*(unsigned char *)((char*)(arg0) + (5))), (*(short *)((char*)(arg0) + (0)))));
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DACE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_ACE8 { short x; unsigned short y; unsigned short z; unsigned char idx; unsigned char pad; };
struct H_ACE8 { struct E_ACE8 ent[12]; char pad[2]; unsigned char tbl[1]; };
struct O_ACE8 { int len; int start; int n; unsigned char col[4]; };
struct L_ACE8 { char pad[4]; unsigned char cnt; char pad2[3]; unsigned char list[1]; };
struct C_ACE8 { char pad[4]; signed char n; char pad2[3]; unsigned char a[8]; unsigned char b[8]; };
extern int func_003D83B8_ACE8(void *, unsigned char **) __asm__("func_003D83B8");
extern int func_003DB838_ACE8(unsigned char *, int, struct O_ACE8 *) __asm__("func_003DB838");
extern unsigned char **D_004A4824_ACE8 __asm__("D_004A4824");

void func_003DACE8(void *a0, struct H_ACE8 *h, struct L_ACE8 *l) {
    struct O_ACE8 o;
    unsigned char *out;
    int n;
    int i;
    int j;
    struct C_ACE8 *c;

    if (func_003D83B8_ACE8(a0, &out) != 0) {
        i = 0;
        n = l->cnt >> 2;
        for (; i < n; i++) {
            c = (struct C_ACE8 *)((int *)l + l->list[i]);
            for (j = 0; j < c->n; j++) {
                if (c->a[j] == 0xFE && !(c->b[j] & 0x80)) {
                    if (func_003DB838_ACE8(D_004A4824_ACE8[h->ent[i].x], h->tbl[h->ent[i].idx], &o)) {
                        out[c->b[j]] = o.col[j];
                    }
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAE48);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct O_AE48 { int len; int start; int n; unsigned char col[4]; };
struct L_AE48 { char pad[4]; unsigned char cnt; char pad2[3]; unsigned char list[1]; };
struct S_AE48 { int pad[2]; void (*cb)(void *, int, int, int); };
struct X_AE48 { short x; short pad[3]; };
struct Y_AE48 { unsigned short y; short pad[3]; };
extern int func_003D8330_AE48(void *, int *) __asm__("func_003D8330");
extern int func_003DB838_AE48(unsigned char *, int, struct O_AE48 *) __asm__("func_003DB838");
extern int func_003DB3E0_AE48(int, int) __asm__("func_003DB3E0");
extern unsigned char **D_004A4824_AE48 __asm__("D_004A4824");
extern struct S_AE48 D_0044FF90_AE48 __asm__("D_0044FF90");
extern struct X_AE48 D_0045070C_AE48[] __asm__("D_0045070C");
extern struct Y_AE48 D_00450710_AE48[] __asm__("D_00450710");

void func_003DAE48(void *a0, int a1, struct L_AE48 *l, int a3) {
    struct O_AE48 o;
    int out;
    int i;
    int j;
    int cnt;
    unsigned char *tbl;
    unsigned char *shp;
    unsigned char b;
    int h;
    unsigned yy;
    long m;

    if (D_0044FF90_AE48.cb != 0) {
        func_003D8330_AE48(a0, &out);
        cnt = l->cnt >> 2;
        for (i = 0; i < cnt; i++) {
            tbl = (unsigned char *)l + l->list[i] * 4 + 0xC;
            for (j = 0; j < 4; j++) {
                b = tbl[j];
                if (b != 0xFF) {
                    h = func_003DB3E0_AE48(a1, b);
                    yy = D_00450710_AE48[i + a3].y;
                    shp = D_004A4824_AE48[D_0045070C_AE48[i + a3].x];
                    if (func_003DB838_AE48(shp, yy, &o)) {
                        m = 1 << o.col[j];
                        D_0044FF90_AE48.cb(a0, h, (int)m, out);
                    }
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAFD0);
#ifdef SKIP_ASM
void func_003DAFD0(void *arg0) {
    int var_3;
    signed char *var_2;

    (*(signed char *)((char*)(arg0) + (0x61))) = 0;
    var_3 = 0xB;
    (*(signed char *)((char*)(arg0) + (0x60))) = 0;
    var_2 = arg0 + 0x5F;
    do {
        *var_2 = 0;
        var_3 -= 1;
        var_2 -= 8;
    } while (var_3 >= 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB008);
#ifdef SKIP_ASM
extern int func_003DB5C0(int, int);

int func_003DB008(unsigned char *arg0) {
    return func_003DB5C0(0x64, -1) < (int) arg0[1];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB040);
#ifdef SKIP_ASM
struct S_B040 {
    int a;
    int b;
    void (*cb)(unsigned char *, int, int, int);
};
extern struct S_B040 D_0044FF90_B040 __asm__("D_0044FF90");

/* Sequence data header: +6 entry count, +7 low nibble = event count, +0xC entry offsets (in words). */
struct Hdr_B040 {
    unsigned char pad0[0xC];
    unsigned short offs[1];
};

struct Ev_B040 {
    int a;
    int b;
    int type;
};

void func_003DB040(unsigned char *ctx, unsigned char *data, int idx, int *tbl) {
    struct Ev_B040 ev;
    int time;
    int count;
    int i;
    unsigned char *track;
    unsigned char *events;
    if (D_0044FF90_B040.cb != 0) {
        func_003D8330(ctx, &time);
        count = data[7] & 0xF;
        track = data + ((struct Hdr_B040 *)data)->offs[idx] * 4;
        events = data + (((data[6] * 2 + 3) & 0x3FC) + 0xC);
        for (i = 0; i < count; i++) {
            /* PORT: pointer arithmetic through int (index-first addu); use uintptr_t off-PS2. */
            unsigned char *e = (unsigned char *)(i * 3 + (int)events);
            int type;
            int a;
            int b;
            ev.a = e[0];
            ev.b = e[1];
            ev.type = e[2];
            type = ev.type;
            a = ev.a;
            b = ev.b;
            switch (type) {
            case 0:
            case 3: {
                int n = track[4] >> 2;
                int found = 0;
                int k;
                for (k = 0; k < n; k++) {
                    unsigned char *ent = track + (track + k)[8] * 4;
                    int m;
                    if (ent[2] == b) {
                        found = 1;
                        break;
                    }
                    for (m = 0; m < 4; m++) {
                        if ((ent + m)[8] == b) {
                            found = 1;
                            break;
                        }
                    }
                }
                if (found)
                    D_0044FF90_B040.cb(ctx, a, tbl[b], time);
                break;
            }
            case 1:
            case 2:
            case 4:
            case 5:
                break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB208);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct H_B208 {
    char pad[6];
    unsigned char n6;
    unsigned char lo : 4;
    unsigned char hi : 4;
};
struct B_B208 { unsigned char a, b, c; };
struct T_B208 { int a, b, c; };
struct F_B208 { int pad; int (*cb)(unsigned char *, int, int, int); int pad2[3]; };
extern struct F_B208 D_0044FF90_B208 __asm__("D_0044FF90");

int func_003DB208(unsigned char *a0, struct H_B208 *h, int *vals, unsigned char *negmask) {
    struct T_B208 t;
    int out;
    int res = 0;
    unsigned char neg = 0;
    int k = 1;
    int n;
    int j;
    int v;
    int r;
    int bit;
    int a;
    unsigned char mask;
    struct B_B208 *tbl;

    func_003D8330(a0, &out);
    n = h->lo;
    tbl = (struct B_B208 *)((unsigned char *)h + (((h->n6 * 2 + 3) & 0x3FC) + 0xC));
    for (; k < 21; k++) {
        for (j = 0; j < n; j++) {
            bit = 0;
            t.a = tbl[j].a;
            t.b = tbl[j].b;
            t.c = tbl[j].c;
            if (k == 20) {
                if (t.b != 0) continue;
                v = 0;
            } else {
                if (t.b != k) continue;
                v = vals[k];
            }
            mask = 1 << (7 - j);
            a = t.a;
            if (D_0044FF90_B208.cb != 0) {
                r = D_0044FF90_B208.cb(a0, a, v, out);
            } else {
                r = -1;
            }
            if (r == 0) {
                bit = 0;
            } else if (r > 0) {
                bit = mask;
            } else {
                neg |= mask;
            }
            res |= bit;
        }
    }
    *negmask = neg;
    return res;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB3B8);
#ifdef SKIP_ASM
int func_003DB3B8(unsigned char a, unsigned char b, unsigned char *p) {
    int m = p[2] & ~b;
    return ((p[3] ^ a) & m) == 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB3E0);
#ifdef SKIP_ASM
typedef struct { char pad[6]; unsigned char n; } H_B3E0;
int func_003DB3E0(H_B3E0 *h, unsigned int idx) {
    int c[3];
    int r = -1;
    unsigned char *tbl = (unsigned char *)h + (((h->n * 2 + 3) & 0x3FC) + 0xC);

    if (idx < 8) {
        unsigned char *e = (unsigned char *)(idx * 3 + (unsigned)tbl); // PORT: ptr in int
        c[0] = e[0];
        c[1] = e[1];
        c[2] = e[2];
        r = c[0];
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB440);
#ifdef SKIP_ASM
int func_003DB440(unsigned char *arg0, int arg1) {
    int i, j;
    int found = 0;
    int n = arg0[4] >> 2;
    unsigned char *e;
    for (i = 0; i < n; i++) {
        e = arg0 + *(arg0 + i + 8) * 4;
        if (e[2] == arg1) {
            found = 1;
            break;
        }
        for (j = 0; j < 4; j++) {
            if (*(e + j + 8) == arg1) {
                found = 1;
                break;
            }
        }
    }
    return found;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB4D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned int D_00450B70_B4D0[6] __asm__("D_00450B70");

unsigned int func_003DB4D0(void) {
    unsigned int s, c, n;

    s = D_00450B70_B4D0[5] + D_00450B70_B4D0[4];
    c = 0;
    if (s < D_00450B70_B4D0[5] || s < D_00450B70_B4D0[4]) {
        c = 1;
    }
    D_00450B70_B4D0[4] = s;
    s = s + D_00450B70_B4D0[3] + c;
    c = s < D_00450B70_B4D0[3];
    D_00450B70_B4D0[3] = s;
    s = s + D_00450B70_B4D0[2] + c;
    c = s < D_00450B70_B4D0[2];
    D_00450B70_B4D0[2] = s;
    n = ++D_00450B70_B4D0[5];
    s = s + D_00450B70_B4D0[1] + c;
    c = s < D_00450B70_B4D0[1];
    D_00450B70_B4D0[1] = s;
    s = s + D_00450B70_B4D0[0] + c;
    D_00450B70_B4D0[0] = s;
    if (n == 0) {
        if (++D_00450B70_B4D0[4] == 0) {
            if (++D_00450B70_B4D0[3] == 0) {
                if (++D_00450B70_B4D0[2] == 0) {
                    if (++D_00450B70_B4D0[1] == 0) {
                        s = ++D_00450B70_B4D0[0];
                    }
                }
            }
        }
    }
    return s;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB5C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_B5C0 { unsigned short a; unsigned short b; };
extern struct P_B5C0 D_00450B88_B5C0[32] __asm__("D_00450B88");
extern int D_004A4858;
extern unsigned int func_003DB4D0(void);

int func_003DB5C0(int range, int key) {
    int hist = range / 2;
    int count = 0;
    int done = 0;
    int best = -1;
    unsigned int res;
    unsigned int cand;
    int lim, head, j, found, k, flag;
    unsigned short k16;

    hist = hist < 11 ? hist : 10;
    res = ((func_003DB4D0() >> 16) * range) >> 16;
    if (key == -1) {
        return res;
    }
    k16 = key;
    do {
        cand = ((func_003DB4D0() >> 16) * range) >> 16;
        lim = hist;
        lim = lim < 33 ? lim : 32;
        head = D_004A4858;
        found = -1;
        j = 0;
        k = 0;
        flag = 0;
        do {
            if (j < lim) {
                if (D_00450B88_B5C0[head].b == k16) {
                    j++;
                    if (D_00450B88_B5C0[head].a == cand) {
                        flag = 1;
                        found = j - 1;
                    }
                }
            } else {
                flag = 1;
            }
            head--;
            k++;
            if (head < 0) head += 32;
            if (k >= 33) flag = 1;
        } while (!flag);
        if (found == -1) {
            res = cand;
            done = 1;
        } else if (best < found) {
            best = found;
            res = cand;
        }
        count = count + 1;
        if (count >= 32) done = 1;
    } while (!done);
    D_004A4858++;
    if (D_004A4858 >= 32) D_004A4858 = 0;
    D_00450B88_B5C0[D_004A4858].a = res;
    D_00450B88_B5C0[D_004A4858].b = k16;
    return cand;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB790);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_B790 {
    unsigned short a;
    unsigned short b;
};
extern struct P_B790 D_00450B88_B790[32] __asm__("D_00450B88");
extern unsigned int D_00450B70_B790[6] __asm__("D_00450B70");
extern int D_004A4858;

void func_003DB790(int seed) {
    int i;
    unsigned int v;

    for (i = 0; i < 32; i++) {
        D_00450B88_B790[i].a = 0xFFFF;
        D_00450B88_B790[i].b = 0xFFFF;
    }
    seed += seed << 16;
    v = seed + 0xF22D0E56;
    D_00450B70_B790[0] = v;
    v += 0x96041893;
    D_00450B70_B790[1] = v;
    v += 0x3DF3B646;
    D_00450B70_B790[2] = v;
    v += 0x40DDE76D;
    D_00450B70_B790[3] = v;
    v += 0x97327AE1;
    D_00450B70_B790[4] = v;
    v += 0xD1A9FBE7;
    D_004A4858 = 0;
    D_00450B70_B790[5] = v;
}
#endif

INCLUDE_ASM("ealib/seg_2D7498", func_003DB838);

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB978);
#ifdef SKIP_ASM
struct S_B978 { int a; int b; int c; unsigned char r, g, bl, al; };
void func_003DB978(struct S_B978 *s) {
    s->b = -1; s->a = 0; s->c = 0; s->r = 0xFF; s->g = 0xFF; s->bl = 0xFF; s->al = 0xFF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB9A0);
#ifdef SKIP_ASM
extern int (*D_0044FFB0[])();

int func_003DB9A0(void) {
    int r = 0;
    if (D_0044FFB0[0] != 0) {
        r = D_0044FFB0[0]();
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB9D8);
#ifdef SKIP_ASM
static __inline__ int get32_B9D8(unsigned char *q) {
    return (q[3] << 24) | (q[2] << 16) | (q[1] << 8) | q[0];
}
int func_003DB9D8(unsigned char *p, int sel) {
    unsigned char *r;

    switch (sel) {
    case 0:
        return (p[0xF] << 8) | p[0xE];
    case 1:
        return (p[0xD] << 8) | p[0xC];
    case 2:
        r = p + get32_B9D8(p + *(unsigned short *)(p + 0xE) * 4 + 0x10);
        return get32_B9D8(r + 0xC);
    case 3:
        return p[8] & 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DBAA8);
#ifdef SKIP_ASM
void func_003DBAA8(void *arg0, int arg1, unsigned int arg2) {
    if (arg1 == 0) {
        *(unsigned short *)((char *)arg0 + 0xE) = arg2;
        *(unsigned char *)((char *)arg0 + 0xE) = arg2;
        *(unsigned char *)((char *)arg0 + 0xF) = arg2 >> 8;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DBAC8);
#ifdef SKIP_ASM
int func_003DBAC8(unsigned short *arg0, void *arg1) {
    return *arg0 - (((*(unsigned char *)((char*)(arg1) + (1))) << 8) | (*(unsigned char *)((char*)(arg1) + (0))));
}
#endif
