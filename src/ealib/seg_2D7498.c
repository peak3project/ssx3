#include "common.h"

/* Library state in .bss (each word is its own symbol). */
extern int D_004A4820;                  /* 0x01789A34 while initialised (func_003D6840) */
extern unsigned char **D_004A4824;      /* shape table, D_004A4828 entries */
extern int D_004A4828;
extern void (*D_004A482C)(int, int, ...);
extern int D_004A4830;
extern unsigned int D_004A4834;
extern int D_004A4838;
extern int D_004A483C;
extern int D_004A4840;
extern short D_004A4844;
extern int D_004A484C;                  /* re-entrancy lock */
extern int D_004A4858;                  /* func_003DB5C0 history head */

/* D_0044FF90: the client callbacks (field names are offsets). f0C and f10 are also reached through their own
   symbols D_0044FF9C / D_0044FFA0; D_0044FFA8 follows (its f08 is also D_0044FFB0). */
struct sKey4 { unsigned char b[4]; };
struct sFF90Msg { int id; int start; int len; struct sKey4 k; int f10; int f14; int f18; };
struct sFF90 {
    int (*f00)(struct sFF90Msg *);                  /* func_003D9830 */
    int (*f04)(unsigned char *, int, int, int);     /* func_003DB208 */
    void (*f08)(void *, int, int, int);             /* func_003DAE48, func_003DB040 */
    int (*f0C)(struct sKey4 *);                     /* func_003D7EC8 */
    int (*f10)(int, void *);                        /* func_003DA418 */
    int f14;
};
struct sFFA8 { int f00; int f04; int (*f08)(); int f0C; };
extern struct sFF90 D_0044FF90;
extern int (*D_0044FF9C[])(struct sKey4 *);
extern int (*D_0044FFA0[])(int, void *);
extern struct sFFA8 D_0044FFA8;
extern int (*D_0044FFB0[])();

/* D_0044FFB8: the registered banks (func_003D6498); p is the bank header, x its key. */
struct sBank { unsigned char *p; unsigned int x; };
extern struct sBank D_0044FFB8[8];

/* D_0044FFF8: the event players. z[] counts the busy players per bucket; a[] / b[] hold player indices per
   bucket (-1 = none). D_0045006C is r[0].arr (func_003DA418). */
struct sEvtHdr { unsigned short h0; unsigned short h2; unsigned short h4; char pad6[3]; signed char b9; unsigned char bA; };
struct sPlayer {                    /* 0x60 */
    unsigned int f0;                /* start time */
    unsigned short h;
    unsigned char c;                /* in use */
    unsigned char d;                /* bucket */
    short s8;
    short next;                     /* chained player, -1 = end */
    struct sEvtHdr *p;
    int arr[20];
};
struct sFFF8 { int z[8]; int a[8]; int b[8]; int n; struct sPlayer r[16]; };
extern struct sFFF8 D_0044FFF8;

/* D_00450660: one entry per bucket (func_003D69A8 resets h to 0xFFFF). */
struct s0660 { unsigned short h; int w; };
extern struct s0660 D_00450660[8];
extern int D_004506A0[];                /* one word per bucket (a mask table follows at +0x20) */
extern unsigned int D_004506E0[8];      /* weight scale by the top 3 bits of a weight byte */

/* Random generator (func_003DB790 seeds, func_003DB4D0 steps): D_00450B70 is the 192-bit state, D_00450B88 the
   history of the last 32 results per key (head D_004A4858). */
struct sRandHist { unsigned short a; unsigned short b; };
extern unsigned int D_00450B70[6];
extern struct sRandHist D_00450B88[32];

/* D_00450700: the queued play requests (func_003D9AC8 adds, func_003D9A40 clears). f0 = owner id (-1 = free),
   f4 = request count, f8 = used q entries. D_0045070C is q[] and D_00450710 is q[0].y (own splat symbols). */
struct s0700Q { short x; short idx; unsigned short y; short d; };
struct s0700Req { int f0; unsigned char *f4; unsigned char b8; unsigned char b9; unsigned char ba; unsigned char bb; int data[20]; };
struct s0700 { int f0; int f4; int f8; struct s0700Q q[0x30]; struct s0700Req r[8]; };
struct s0710 { unsigned short y; short pad[3]; };
extern struct s0700 D_00450700;
extern struct s0700Q D_0045070C[];
extern struct s0710 D_00450710[];

/* What func_003DB838 reports for one shape entry. */
struct sShapeInfo { int len; int start; int n; unsigned char col[4]; };
int func_003DB838(unsigned char *shp, int idx, struct sShapeInfo *out);

/* A selection set: one entry per layer (x = shape, tbl[start .. start + len) its candidates, cur the chosen one). */
struct sSel { short x; short y; unsigned char start; unsigned char len; unsigned char cur; unsigned char flag; };
struct sSelSet { struct sSel ent[12]; unsigned char n; unsigned char ntbl; unsigned char tbl[200]; };
struct sTblEnt { unsigned short a; unsigned short b; };

/* A layer condition: a[i] = 0xFE sets, 0xFF tests the flag word b[i] & 0x7F (when b[i] & 0x80). */
/* The block that follows a shape's header and tables (bit map, then history). */
static __inline__ unsigned char *shapeTail(unsigned char *s) {
    int n = s[4] & 0xF;
    return s + ((s[5] * (n + 2) + 0xF) & 0x3FFC) + n * 4;
}

/* Sequence data header: n entry offsets (in words) at ids[], then (f7 & 0xF) 3-byte events. */
struct sSeqHdr { char pad[6]; unsigned char n; unsigned char f7; char pad8[4]; unsigned short ids[1]; };
/* A layer header: cnt >> 2 conditions (low 2 bits: mode), each at word offset list[i]. */
struct sLayer { char pad[4]; unsigned char cnt; unsigned char n5; unsigned char n6; char pad7; unsigned char list[1]; };
struct sCond { unsigned short id; unsigned char idx; unsigned char mode; signed char n; char pad5[3]; unsigned char a[8]; unsigned char b[4]; unsigned int m[4]; };

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6498);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003DA3A8(void *arg0, int *arg1, int *arg2);

static __inline__ void clear_6498(unsigned long key) {
    int i, j;
    for (i = 0; i < 8; i++) {
        unsigned char *p = D_0044FFB8[i].p;
        if (p != 0 && D_0044FFB8[i].x == key) {
            unsigned char *q = p + (((*(unsigned short *)(p + 0x10) * 2 + 3) & 0xFFFFFFFC) + 0x18);
            for (j = 0; j < D_0044FFB8[i].p[0x12]; j++) {
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
            unsigned char *p = D_0044FFB8[i].p;
            if (p != 0 && p[9] == b && p[8] == a) {
                goto out;
            }
        }
        for (i = 0; i < 8; i++) {
            if (D_0044FFB8[i].p == 0) {
                D_0044FFB8[i].p = (unsigned char *)arg0;
                D_0044FFB8[i].x = arg1;
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

void func_003D6618(unsigned long key) {
    int i, j;
    for (i = 0; i < 8; i++) {
        unsigned char *p = D_0044FFB8[i].p;
        if (p != 0 && D_0044FFB8[i].x == key) {
            unsigned char *q = p + (((*(unsigned short *)(p + 0x10) * 2 + 3) & 0xFFFFFFFC) + 0x18);
            for (j = 0; j < D_0044FFB8[i].p[0x12]; j++) {
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

int func_003D66F0(unsigned char *arg0, unsigned int arg1) {
    int i;
    if (arg0 == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (D_0044FFB8[i].p == arg0 && D_0044FFB8[i].x == arg1) {
            D_0044FFB8[i].p = 0;
            return 1;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D6748);
#ifdef SKIP_ASM
extern int func_003D6498(int, int);

void func_003D6748(int a) {
    func_003D6498(a, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6768);
#ifdef SKIP_ASM

struct sFFA8 *func_003D6768(void) {
    return &D_0044FFA8;
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
void func_003D6D30(void);
void func_003D8278(void);

void func_003D67F8(void) {
    if (D_004A4820 == 0x01789A34) {
        D_004A4820 = 0;
        D_0044FF90.f00 = 0;
        D_0044FF90.f04 = 0;
        D_0044FF90.f08 = 0;
        func_003D6D30();
        func_003D8278();
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6840);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
void func_003D76F0(int, int, ...);
void func_003DB790(int);
void func_003D9A40(void);
void func_003DA3C0(int);
void func_003D8278(void);
void func_003D6D40(void);
void func_003D71D8(void);

int func_003D6840(int (*arg0)(struct sFF90Msg *), int arg1, int arg2) {
    int i;
    long j;
    D_0044FF90.f00 = arg0;
    D_0044FF90.f04 = 0;
    D_0044FF90.f08 = 0;
    D_0044FFA8.f00 = 0;
    D_0044FFA8.f04 = 0;
    D_0044FFA8.f08 = 0;
    D_004A482C = func_003D76F0;
    D_004A4834 = arg1;
    D_004A4838 = arg2;
    func_003DB790(arg1);
    func_003D9A40();
    func_003DA3C0(0);
    for (i = 7; i >= 0; i--) {
        D_004506A0[i] = 0;
    }
    func_003D8278();
    for (j = 0; j < 8; j++) {
        D_00450660[(int)j].h = 0xFFFF;
        D_00450660[(int)j].w = 0;
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
void func_003D6940(int (*x)(unsigned char *, int, int, int), void (*y)(void *, int, int, int)) {
    if (D_004A4820 == 0x01789A34) {
        D_0044FF90.f04 = x;
        D_0044FF90.f08 = y;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6968);
#ifdef SKIP_ASM

void func_003D6968(int (*arg0)(int, void *)) {
    if (D_004A4820 == 0x01789A34) {
        D_0044FFA0[0] = arg0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6988);
#ifdef SKIP_ASM

void func_003D6988(int (*arg0)(struct sKey4 *)) {
    if (D_004A4820 == 0x01789A34) {
        D_0044FF9C[0] = arg0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D69A8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.

void func_003D69A8(void) {
    long i;
    for (i = 0; i < 8; i++) {
        D_00450660[(int)i].h = 0xFFFF;
        D_00450660[(int)i].w = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D69F0);
#ifdef SKIP_ASM

static inline int findfree_69F0(void) {
    int i, idx;

    idx = -1;
    for (i = 0; i < D_004A4828; i++) {
        if (D_004A4824[i] == 0) {
            idx = i;
            break;
        }
    }
    return idx;
}

int func_003D69F0(unsigned char *shp) {
    int ret;
    int i, j, w, extra, c, cnt, bit;
    unsigned char *p, *t;
    unsigned int r, start, end, byte;

    ret = -1;
    if (D_004A4824 != 0) {
        if (shp[6] != 0) {
            extra = 0;
            p = shapeTail(shp);
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
                t = shapeTail(shp);
                w = shp[5];
                c = *t;
                if (c > 0) {
                    r = D_004A4834 % c;
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
            D_004A4824[ret] = shp;
        }
    }
out:
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6BC0);
#ifdef SKIP_ASM
void func_003D7038(unsigned char *p);
void func_003D6F80(unsigned char *p);

void func_003D6BC0(int arg0) {
    int i;
    unsigned char *p;
    if (D_004A4820 != 0) {
        D_004A4834 = arg0;
        if (D_004A4824 != 0) {
            for (i = 0; i < D_004A4828; i++) {
                p = D_004A4824[i];
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

void func_003D6C60(int arg0, unsigned char **arg1) {
    int i;

    D_004A4828 = arg0;
    D_004A4824 = arg1;
    if (arg1 != 0) {
        for (i = 0; i < D_004A4828; i++) {
            D_004A4824[i] = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6CA0);
#ifdef SKIP_ASM

void func_003D6CA0(int arg0) {
    if (D_004A4824 != 0) {
        D_004A4824[arg0] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6CC0);
#ifdef SKIP_ASM

int func_003D6CC0(int arg0) {
    int r = 0;
    if (D_004A4820 == 0x01789A34 && D_004A4824 != 0) {
        r = (int)D_004A4824[arg0];
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6CF8);
#ifdef SKIP_ASM

int func_003D6CF8(int arg0, unsigned int arg1) {
    int r = 0;
    unsigned short *p;

    if (D_004A4824 != 0 && arg0 >= 0) {
        p = (unsigned short *)(D_004A4824[arg0] + 0xA);
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

void func_003D6D30(void) {
    D_004A4824 = 0;
    D_004A4828 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6D40);
#ifdef SKIP_ASM

void func_003D6D40(void) {
    D_004A4824 = 0;
    D_004A4828 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D6D50);
#ifdef SKIP_ASM

int func_003D6D50(unsigned short arg0) {
    unsigned char **p;
    short i;

    p = D_004A4824;
    if (p != 0) {
        for (i = 0; i < D_004A4828; i++) {
            if (*p != 0 && *(unsigned short *)*p == arg0) {
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

int func_003D6DB8(unsigned short arg0, unsigned short arg1) {
    short i;
    unsigned short *p;

    if (D_004A4824 != 0) {
        for (i = 0; i < D_004A4828; i++) {
            p = (unsigned short *)D_004A4824[i];
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

void func_003D6F80(unsigned char *shp) {
    int j, w, c, cnt, bit;
    unsigned char *t;
    unsigned int r, start, end, byte;
    int n = shp[4] & 0xF;

    t = shp + ((shp[5] * (n + 2) + 0xF) & 0x3FFC) + n * 4;
    w = shp[5];
    c = *t;
    if (c > 0) {
        r = D_004A4834 % c;
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

int func_003D70B0(void) {
    int i;
    int r = -1;

    for (i = 0; i < D_004A4828; i++) {
        if (D_004A4824[i] == 0) {
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
    struct sBank *res;
    struct sBank *e = D_0044FFB8;
    unsigned short *ret = 0;
    struct sBank **pres = &res;
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

void func_003D71D8(void) {
    int i, j;
    for (i = 0; i < 8; i++) {
        D_0044FFF8.z[i] = 0;
        D_0044FFF8.a[i] = -1;
        D_0044FFF8.b[i] = -1;
    }
    D_0044FFF8.n = 0;
    for (i = 0; i < 16; i++) {
        D_0044FFF8.r[i].c = 0;
        D_0044FFF8.r[i].h = 0;
        D_0044FFF8.r[i].f0 = 0;
        D_0044FFF8.r[i].p = 0;
        D_0044FFF8.r[i].d = 0xFF;
        for (j = 19; j >= 0; j--) {
            D_0044FFF8.r[i].arr[j] = 0;
        }
    }
    D_004A4840 = 0;
    D_004A4844 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D72A0);
#ifdef SKIP_ASM
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
        if (D_0044FFF8.r[i].c == 0) {
            ret = i;
            goto out;
        }
    }
    if (arg2 != 0) {
        skip = D_0044FFF8.b[arg1];
    }
    i = 0;
    t = func_003DB9A0();
    for (; i < 16; i++) {
        if (D_0044FFF8.r[i].s8 == 0 && (h = D_0044FFF8.r[i].p->h2) != 0 &&
            h < t - D_0044FFF8.r[i].f0 && skip != i) {
            func_003D7C38(i);
            ret = i;
            goto out;
        }
    }
    for (i = 0; i < 16; i++) {
        if (D_0044FFF8.r[i].s8 == 0) {
            d = D_0044FFF8.r[i].d;
            if (arg0 >= D_0044FFF8.r[i].p->h4 && d == arg1 && i != skip) {
                D_0044FFF8.r[i].c = 0;
                D_0044FFF8.z[d]--;
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

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7760);
#ifdef SKIP_ASM
struct L_7760 { int n; unsigned short *ids; };

static __inline__ int has_7760(struct L_7760 *l, unsigned int id) {
    int i;
    int found = 0;
    for (i = 0; i < l->n; i++) {
        if (l->ids[i] == id) {
            found = 1;
            break;
        }
    }
    return found;
}

static __inline__ int find_7760(unsigned char *k, struct sBank **pres) {
    int found = 0;
    int i = 0;
    do {
        unsigned char *q = D_0044FFB8[i].p;
        if (q != 0 && q[9] == k[2] && q[8] == k[3]) {
            *pres = &D_0044FFB8[i];
            found = 1;
            break;
        }
        i++;
    } while (i < 8);
    return found;
}

static __inline__ int busy_7760(struct sEvtHdr *p, int *arr) {
    struct sKey4 key;
    struct sBank *res;
    int r = 0;

    key = *(struct sKey4 *)arr;
    if (find_7760(key.b, &res) && p->h4 < *(unsigned short *)(res->p + 0x16)) {
        r = 1;
    }
    return r;
}

int func_003D7760(struct L_7760 *list, int idx) {
    unsigned int bestval;
    int best;
    unsigned int bestdiff;
    int bestp;
    unsigned int now;
    int i;
    struct sEvtHdr *p;
    int inlist;
    int expired;
    int blocked;
    unsigned int diff;
    int h4;

    now = func_003DB9A0() + D_004A483C;
    best = -1;
    bestdiff = -1;
    bestp = 0;
    bestval = 0;
    for (i = 0; i < 16; i++) {
        if (D_0044FFF8.r[i].c == 0) continue;
        if (D_0044FFF8.r[i].d != idx) continue;
        if (D_0044FFF8.r[i].s8 != 0) continue;
        p = D_0044FFF8.r[i].p;
        expired = 0;
        blocked = 0;
        inlist = 1;
        if (list != 0) {
            inlist = has_7760(list, p->h0);
        }
        diff = now - D_0044FFF8.r[i].f0;
        if (p->h2 != 0 && p->h2 < diff) {
            expired = 1;
        }
        if (D_004506A0[idx] == 1 && (p->bA & 1)) {
            blocked = busy_7760(p, D_0044FFF8.r[i].arr);
        }
        if (expired) {
            func_003D7C38(i);
            continue;
        }
        if (inlist == 0) continue;
        if (blocked != 0) continue;
        h4 = p->h4;
        if (bestp < h4) {
            best = i;
            bestdiff = diff;
            bestp = h4;
            bestval = D_0044FFF8.r[best].h;
        } else if (h4 == bestp) {
            if (diff < bestdiff || (diff == bestdiff && bestval < D_0044FFF8.r[i].h)) {
                best = i;
                bestdiff = diff;
                bestval = D_0044FFF8.r[best].h;
            }
        }
    }
    return best;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D7A50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
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
    if (D_00450660[idx].h != 0xFFFF) {
        q = (struct B_7A50 *)func_003D7110((unsigned char *)&D_00450660[idx]);
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
void func_003D69A8(void);

void func_003D7B98(void) {
    int i;
    for (i = 0; i < 16; i++) {
        if (D_0044FFF8.r[i].c != 0) {
            D_0044FFF8.r[i].c = 0;
            D_0044FFF8.z[D_0044FFF8.r[i].d]--;
        }
    }
    for (i = 0; i < 8; i++) {
        D_0044FFF8.b[i] = -1;
        D_0044FFF8.a[i] = -1;
        if (D_0044FFF8.z[i] != 0) {
            D_0044FFF8.z[i] = 0;
        }
    }
    func_003D69A8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7C38);
#ifdef SKIP_ASM
void func_003D7C38(unsigned int n) {
    int nx = -1;
    if (n < 16) {
        if (D_0044FFF8.r[n].s8 == 0) {
            int b;
            D_0044FFF8.r[n].c = 0;
            b = D_0044FFF8.r[n].d;
            if (n == D_0044FFF8.b[b]) {
                D_0044FFF8.b[b] = -1;
            }
            if (n == D_0044FFF8.a[b]) {
                D_0044FFF8.a[b] = -1;
            }
            nx = D_0044FFF8.r[n].next;
            while (nx != -1) {
                if ((unsigned int)nx >= 16) {
                    break;
                }
                if (D_0044FFF8.r[nx].s8 != 0 && D_0044FFF8.r[nx].c != 0) {
                    if (nx == D_0044FFF8.a[b]) {
                        D_0044FFF8.a[b] = -1;
                    }
                    D_0044FFF8.r[nx].c = 0;
                    nx = D_0044FFF8.r[nx].next;
                } else {
                    nx = -1;
                }
            }
            if (D_0044FFF8.r[n].s8 == 0) {
                D_0044FFF8.z[b]--;
            }
            if (D_0044FFF8.z[b] < 0) {
                D_0044FFF8.z[b] = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D7D58);
#ifdef SKIP_ASM
void func_003D7C38(unsigned int);

void func_003D7D58(int a) {
    int i;
    unsigned int f0, f;
    unsigned int h, hi;
    int d;

    f0 = D_0044FFF8.r[a].f0;
    d = D_0044FFF8.r[a].d;
    h = D_0044FFF8.r[a].h;
    D_0044FFF8.n = 0;
    for (i = 0; i < 16; i++) {
        if (i == a) continue;
        if (D_0044FFF8.r[i].c == 0) continue;
        if (D_0044FFF8.r[i].d != d) continue;
        if (D_0044FFF8.r[i].s8 != 0) continue;
        f = D_0044FFF8.r[i].f0;
        hi = D_0044FFF8.r[i].h;
        if (f < f0 || (f == f0 && hi < h)) {
            if ((D_0044FFF8.r[i].p->bA >> 2) & 1) continue;
            func_003D7C38(i);
        } else if (D_0044FFF8.r[i].p->b9 == 100) {
            if (D_0044FFF8.r[i].d == d) {
                D_0044FFF8.n = 1;
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D7EC8);
#ifdef SKIP_ASM
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
    struct sKey4 k;
    if (D_0044FFF8.z[a] != 0) {
        do {
            idx = func_003D7A50(a);
            if (idx < 0) goto out;
            k = *(struct sKey4 *)D_0044FFF8.r[idx].arr;
            t = 1;
            if (D_0044FF90.f0C != 0) {
                t = D_0044FF90.f0C(&k);
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
            s = D_0044FFF8.r[s].next;
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

void* func_003D8008(int arg0, int arg1, int arg2) {
    D8008_S u;
    u.c = arg0;
    u.b = arg1;
    u.a = arg2;
    return *(void**)&u;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8028);
#ifdef SKIP_ASM

int func_003D8028(int arg0) {
    return D_0044FFF8.z[arg0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8040);
#ifdef SKIP_ASM
int func_003DA3F0(int x);
int func_003D7EC8(int);
void* func_003D9BD8(int);

void* func_003D8040(int arg0) {
    void* r = 0;
    if (D_004A484C == 0) {
        D_004A484C = 1;
        if (func_003DA3F0(arg0) != 0 || func_003D7EC8(arg0) != 0) {
            r = func_003D9BD8(arg0);
        }
    }
    D_004A484C = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D80B0);
#ifdef SKIP_ASM
void func_003D9A40(void);
int func_003DA418(int);
void func_003D7C38(unsigned int);
void* func_003D9BD8(int);

void func_003D80B0(int x) {
    if (D_004A484C == 0) {
        unsigned int a = D_0044FFF8.a[x];
        unsigned int b = D_0044FFF8.b[x];
        int ok;
        D_004A484C = 1;
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
    D_004A484C = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D8158);
#ifdef SKIP_ASM

void func_003D8158(int arg0, int arg1) {
    D_004506A0[arg1] = arg0;
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
extern int func_003D7EC8(int);
extern void* func_003D9BD8(int);
extern int func_003DA3F0(int);

void func_003D8190(void) {
    if (D_004A484C == 0) {
        D_004A484C = 1;
        if (func_003DA3F0(0) != 0) {
            func_003D9BD8(0);
        } else if (func_003D7EC8(0) != 0) {
            func_003D9BD8(0);
        }
    }
    D_004A484C = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D81F0);
#ifdef SKIP_ASM

int func_003D81F0(unsigned char *arg0, int *arg1) {
    struct sBank *res;
    struct sBank *e = D_0044FFB8;
    int ret = 0;
    struct sBank **pres = &res;
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

void func_003D8278(void) {
    int i;
    for (i = 0; i < 8; i++) {
        D_0044FFB8[i].p = 0;
        D_0044FFB8[i].x = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D82B0);
#ifdef SKIP_ASM

unsigned short func_003D82B0(unsigned char *arg0) {
    struct sBank *res;
    struct sBank *e = D_0044FFB8;
    unsigned short ret = 0;
    struct sBank **pres = &res;
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

int func_003D8330(unsigned char *arg0, int *arg1) {
    struct sBank *res;
    struct sBank *e = D_0044FFB8;
    int ret = 0;
    struct sBank **pres = &res;
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

int func_003D83B8(unsigned char *arg0, unsigned char **arg1) {
    struct sBank *res;
    struct sBank *e = D_0044FFB8;
    int ret = 0;
    struct sBank **pres = &res;
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

int func_003D84A0(unsigned char *arg0, struct sBank **pres) {
    struct sBank *e = D_0044FFB8;
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
int func_003D8500(int i) {
    int r = (unsigned int)D_0044FFF8.a[i] < 0x10;
    if ((unsigned int)D_0044FFF8.b[i] >= 0x10) r = 0;
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
                t = shapeTail(shp);
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
            r = bit_8780(shapeTail(shp) + 1, x);
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

#define WEIGHT_8CB0(p) ((*(p) & 0x1F) * D_004506E0[*(p) >> 5])

void func_003D8CB0(struct sSeqHdr *h, unsigned char *out) {
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

int func_003D8E58(struct sSelSet *h, struct sLayer *l) {
    struct sShapeInfo o;
    int ok = 1;
    int i;
    int i0;
    int j;
    int cnt;
    int redo;
    int n;
    int *tab;
    unsigned char *lp;
    struct sCond *c;
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
                    c = (struct sCond *)((int *)l + lp[i]);
                    n = c->n;
                    if (!func_003DB838(D_004A4824[h->ent[i].x], h->tbl[h->ent[i].cur], &o)) {
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

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9088);
#ifdef SKIP_ASM
extern int func_003DB3B8(unsigned char a, unsigned char b, unsigned char *p);
extern int func_003D6D50(unsigned short arg0);
extern int func_003D6DB8(unsigned short arg0, unsigned short arg1);
extern int func_003D6CF8(int arg0, unsigned int arg1);
extern int func_003D88C8(struct sSelSet *, unsigned char *, struct sSel *, struct sCond *, struct sTblEnt *);


static __inline__ int modeOk_9088(void *arg0, int arg1) {
    int temp_3;

    temp_3 = (*(unsigned char *)((char*)(arg0) + (4))) & 3;
    if (((temp_3 == 1) && (arg1 == 2)) || ((temp_3 == 2) && (arg1 != temp_3))) {
        return 1;
    }
    return temp_3 == 0;
}

static __inline__ void clear_9088(unsigned char *arg0) {
    int *q;
    int i;
    q = (int *)(arg0 + ((((arg0[4] >> 2) + 3) & 0x7C) + 8) + (arg0[6] * 4));
    for (i = 0; i < arg0[5]; i++) {
        q[i] = 0;
    }
}

static __inline__ int check_9088(unsigned char *h, struct sCond *s) {
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

static __inline__ int resolve_9088(struct sCond *p, struct sTblEnt *tbl, struct sSel *out) {
    unsigned short v = p->id;
    unsigned int mode = p->mode;
    unsigned int idx = p->idx;
    int r;
    out->y = -1;
    out->x = -1;
    switch (mode) {
    case 0:
        out->x = func_003D6D50(v);
        break;
    case 1:
        if (idx >= 20) {
            out->x = -1;
        } else {
            out->x = func_003D6DB8(v, tbl[idx].a);
        }
        break;
    case 2: {
        struct sTblEnt *e;
        int t = func_003D6D50(v);
        e = (struct sTblEnt *)(idx * 4 + (int)tbl);
        if (func_003D6CF8(t, *(int *)e) != 0) {
            out->y = e->a;
        } else {
            t = -1;
        }
        out->x = t;
        break;
    }
    }
    r = out->x;
    if (r <= -1)
        return 0;
    return 1;
}

int func_003D9088(struct sSelSet *self, unsigned char *hdr, struct sTblEnt *tbl, int a, int b, int mode) {
    int ret = 1;
    int all;
    int tries = 200;
    int n = hdr[4] >> 2;
    unsigned char *lp;
    int i;

    if (n >= 13 || !modeOk_9088(hdr, mode) || !func_003DB3B8(a, b, hdr)) {
        ret = 0;
    } else {
        clear_9088(hdr);
        self->n = n;
        do {
            all = 1;
            tries--;
            i = 0;
            if (n != 0) {
                lp = hdr + 8;
                do {
                    struct sSel *slot = &self->ent[i];
                    struct sCond *e = (struct sCond *)(hdr + lp[i] * 4);
                    if (!check_9088(hdr, e)) {
                        all = 0;
                    } else if (slot->flag == 0) {
                        int r;
                        slot->start = self->ntbl;
                        if (!resolve_9088(e, tbl, slot)) {
                            ret = 0;
                            goto out;
                        }
                        r = func_003D88C8(self, hdr, slot, e, tbl);
                        if (r == 0) {
                            ret = 0;
                            goto out;
                        }
                        slot->len = r;
                        slot->flag = 1;
                    }
                    i++;
                } while (i < n);
            }
        } while (!all && tries > 0);
        if (tries == 0) {
            ret = 0;
        }
    }
out:
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D93C0);
#ifdef SKIP_ASM
/* Combination search: reset every entry, then advance the odometer until the usage
   percentage fits under `thr` and the constraints (func_003D8E58) hold, or the odometer
   wraps. The helpers are the inline bodies of func_003DA910 (usage percent) and
   func_003DAC20 (next combination); the retail TU keeps their out-of-line copies at the
   end of the file. */

/* same body as func_003DA910 */
static inline int usage_93C0(unsigned char *a0, struct sSelSet *h) {
    struct sShapeInfo o;
    int total = 0;
    int i;
    int r;
    int cnt = a0[4] >> 2;

    for (i = 0; i < cnt; i++) {
        if (func_003DB838(D_004A4824[h->ent[i].x], h->tbl[h->ent[i].cur], &o)) {
            total += o.len;
        }
    }
    r = 0;
    if (D_004A4838 != 0) {
        r = total * 100 / D_004A4838;
    }
    return r;
}

/* same body as func_003DAC20 */
static inline int next_93C0(unsigned char *h, struct sSel *e) {
    int wrap = 0;
    int done = 0;
    int i = (h[4] >> 2) - 1;
    struct sSel *p = &e[i];
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

int func_003D93C0(struct sLayer *l, struct sSelSet *h, int thr) {
    int ok = 0;
    int of = 0;
    int i;
    int n;
    int pct;

    n = l->cnt >> 2;
    for (i = 0; i < n; i++) {
        h->ent[i].cur = h->ent[i].start;
    }
    do {
        ok = 1;
        pct = 0;
        if (thr != 0) {
            pct = usage_93C0((unsigned char *)l, h);
            if (thr < pct) ok = 0;
        }
        if (ok) {
            if (l->n5 != 0) {
                if (func_003D8E58(h, l) == 0) ok = 0;
            }
        }
        if (!ok) {
            of = next_93C0((unsigned char *)l, h->ent);
        }
    } while (!of && !ok);
    return ok;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003D95B8);
#ifdef SKIP_ASM
extern int func_003DB5C0(int, int);

static __inline__ void shuffle_95B8(struct sLayer *l, struct sSelSet *h) {
    int i = 0;
    int j;
    int n = l->cnt >> 2;
    struct sSel *e;
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

static __inline__ void apply_95B8(void *a0, struct sSelSet *h, struct sLayer *l) {
    struct sShapeInfo o;
    unsigned char *out;
    int n;
    int i;
    int j;
    struct sCond *c;

    if (func_003D83B8(a0, &out) != 0) {
        i = 0;
        n = l->cnt >> 2;
        for (; i < n; i++) {
            c = (struct sCond *)((int *)l + l->list[i]);
            for (j = 0; j < c->n; j++) {
                if (c->a[j] == 0xFE && !(c->b[j] & 0x80)) {
                    if (func_003DB838(D_004A4824[h->ent[i].x], h->tbl[h->ent[i].cur], &o)) {
                        out[c->b[j]] = o.col[j];
                    }
                }
            }
        }
    }
}

int func_003D95B8(void *a0, struct sSelSet *h, struct sLayer *l, int mode, int thr) {
    int ok;
    int i;
    int n;

    if (mode == 1 || l->n5 != 0) {
        shuffle_95B8(l, h);
        ok = func_003D93C0(l, h, mode != 2 ? thr : 0);
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

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9830);
#ifdef SKIP_ASM

static __inline__ void clearBit_9830(unsigned char *s, int bit) {
    int n = s[4] & 0xF;
    int q = bit / 8;
    unsigned char *p = s + ((s[5] * (n + 2) + 0xF) & 0x3FFC) + n * 4 + (q + 1);
    *p &= ~(1 << (bit - q * 8));
}

int func_003D9830(unsigned char *h, struct sKey4 *k, int a2) {
    struct sShapeInfo o;
    struct sFF90Msg m;
    int w30;
    int w34;
    int sum;
    int cnt;
    int n;
    int r;
    int st;
    int t;
    int x;
    int y;
    struct s0700Q *e;
    unsigned char *s;

    sum = 0;
    r = 0;
    w34 = 0;
    if (D_0044FF90.f00 != 0) {
        func_003D8330(k->b, &w30);
        func_003D81F0(k->b, &w34);
        n = h[4] >> 2;
        if (n != 0) {
            cnt = n;
            e = D_0045070C + a2;
            do {
                x = e->x;
                s = D_004A4824[x];
                y = e->y;
                if ((s[4] & 0x80) && D_004A4830 != 0) {
                    clearBit_9830(s, y);
                }
                if (func_003DB838(s, y, &o)) {
                    t = *(unsigned short *)(s + 8) * ((s[7] + 1) << 8);
                    st = o.start;
                    if (e->idx != -1) {
                        st = e->idx * t + st;
                    }
                    m.start = st;
                    m.id = x;
                    sum += o.len;
                    m.len = o.len;
                    m.k = *k;
                    m.f18 = w30;
                    m.f10 = w34;
                    m.f14 = *(unsigned short *)(s + 2);
                    D_0044FF90.f00(&m);
                    func_003D6EE8(s, y);
                }
                cnt--;
                e++;
            } while (cnt != 0);
        }
        r = 0;
        if (D_004A4838 != 0) {
            r = sum * 100 / D_004A4838;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9A40);
#ifdef SKIP_ASM

void func_003D9A40(void) {
    int i;
    D_00450700.f0 = -1;
    D_00450700.f4 = 0;
    D_00450700.f8 = 0;
    for (i = 0; i < 8; i++) {
        D_00450700.r[i].f0 = 0;
        D_00450700.r[i].f4 = 0;
        D_00450700.r[i].b8 = 0;
        D_00450700.r[i].b9 = 0;
        D_00450700.r[i].bb = 0;
    }
    for (i = 0; i < 0x30; i++) {
        D_00450700.q[i].x = -1;
        D_00450700.q[i].idx = -1;
        D_00450700.q[i].y = 0;
        D_00450700.q[i].d = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9AC8);
#ifdef SKIP_ASM

void func_003D9AC8(struct sSelSet *h, int id, int a2, unsigned char *a3, int a4, int *a5) {
    int n;
    int i;
    int cnt;
    int j;

    if (D_00450700.f0 < 0 || D_00450700.f0 == id) {
        n = D_00450700.f4++;
        if (n < 8) {
            D_00450700.f0 = id;
            D_00450700.r[n].f0 = a2;
            D_00450700.r[n].f4 = a3;
            D_00450700.r[n].b8 = a4;
            for (i = 0; i < 20; i++) {
                D_00450700.r[n].data[i] = a5[i];
            }
            D_00450700.r[n].b9 = 1;
            cnt = a3[4] >> 2;
            j = D_00450700.f8;
            for (i = 0; i < cnt; i++) {
                D_00450700.q[j + i].x = h->ent[i].x;
                D_00450700.q[j + i].idx = h->ent[i].y;
                D_00450700.q[j + i].y = h->tbl[h->ent[i].cur];
            }
            D_00450700.f8 += cnt;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9BD8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern void func_003DB040_9BD8(struct sKey4 *, int, int, int *) __asm__("func_003DB040");
extern int func_003DB3E0_9BD8(int, int) __asm__("func_003DB3E0");

/* The body of func_003DAE48, inlined. */
static __inline__ void layerHits_9BD8(void *a0, int a1, struct sLayer *l, int a3) {
    struct sShapeInfo o;
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

    if (D_0044FF90.f08 != 0) {
        func_003D8330(a0, &out);
        cnt = l->cnt >> 2;
        for (i = 0; i < cnt; i++) {
            tbl = (unsigned char *)l + l->list[i] * 4 + 0xC;
            for (j = 0; j < 4; j++) {
                if ((b = tbl[j]) != 0xFF) {
                    h = func_003DB3E0_9BD8(a1, b);
                    yy = D_00450710[i + a3].y;
                    shp = D_004A4824[D_0045070C[i + a3].x];
                    if (func_003DB838(shp, yy, &o)) {
                        m = 1 << o.col[j];
                        D_0044FF90.f08(a0, h, (int)m, out);
                    }
                }
            }
        }
    }
}

/* func_003DA3F0, inlined. */
static __inline__ int reqOwned_9BD8(int x) {
    int r = 0;
    if (D_00450700.f0 == x)
        r = D_00450700.f4 > 0;
    return r;
}

int func_003D9BD8_impl(int id) __asm__("func_003D9BD8");
int func_003D9BD8_impl(int id) {
    struct sKey4 key;
    int ret = 0;
    int n;
    int k;

    if (reqOwned_9BD8(id)) {
        n = D_00450700.f4;
        for (k = 0; k < n; k++) {
            key = *(struct sKey4 *)D_00450700.r[k].data;
            func_003DB040_9BD8(&key, D_00450700.r[k].f0, D_00450700.r[k].b8, D_00450700.r[k].data);
            layerHits_9BD8(&key, D_00450700.r[k].f0, (struct sLayer *)D_00450700.r[k].f4, ret);
            func_003D9830(D_00450700.r[k].f4, &key, ret);
            ret += D_00450700.r[k].f4[4] >> 2;
            if (k == 0) {
                if (*(unsigned short *)&key == D_00450660[id].h) {
                    D_00450660[id].w++;
                } else {
                    *(struct sKey4 *)&D_00450660[id] = key;
                    D_00450660[id].w = 1;
                }
            }
        }
    }
    func_003D9A40();
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003D9ED0);
#ifdef SKIP_ASM
struct R_9ED0 { int x, y, z; };
struct E_9ED0 { unsigned char x, y, z; };
int func_003D9ED0(struct sSeqHdr *a, struct sLayer *b, unsigned *tbl) {
    struct R_9ED0 rec;
    int n = (signed char)a->f7 >> 4;
    int ok = 1;
    if (n != 0) {
        unsigned *m = (unsigned *)((unsigned char *)b + ((((b->cnt >> 2) + 3) & 0xFFFFFFFC) + 8));
        struct E_9ED0 *e = (struct E_9ED0 *)((unsigned char *)a + (((a->n * 2 + 3) & 0xFFFFFFFC) + 0xC) + (((a->f7 & 0xF) * 3 + 3) & ~3));
        int i;
        for (i = 0; i < n; i++) {
            rec.x = e[i].x;
            rec.y = e[i].y;
            rec.z = e[i].z;
            if (m[i] != 0 && (m[i] & tbl[rec.y]) == 0) {
                ok = 0;
                break;
            }
        }
    }
    return ok;
}
#endif

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

void func_003DA3C0(int arg0) {
    D_004A483C = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA3C8);
#ifdef SKIP_ASM
unsigned int func_003DA3C8(unsigned int a) {
    a &= 0xFF;
    return (a & 0x1F) * D_004506E0[a >> 5];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA3F0);
#ifdef SKIP_ASM
int func_003DA3F0(int x) {
    int r = 0;
    if (D_00450700.f0 == x)
        r = D_00450700.f4 > 0;
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2D7498", func_003DA418);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_A418 { char data[0x60]; };
extern struct E_A418 D_0045006C_A418[] __asm__("D_0045006C");
extern int func_003D9FB0_A418(struct E_A418 *) __asm__("func_003D9FB0");

int func_003DA418(int idx) {
    struct E_A418 *e = &D_0045006C_A418[idx];
    int r;
    int i;
    int k;

    r = func_003D9FB0_A418(e);
    if (r == 0 && D_0044FF90.f10 != 0) {
        i = 0;
        do {
            k = D_0044FF90.f10(i, e);
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
int func_003DA578(struct sCond *p) {
    int i;
    int r = 0;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (p->a[i] == 0xFE) {
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
static __inline__ int gt_A5C8(int a, int b) { return a > b; }

int func_003DA5C8(struct sCond *p, struct sTblEnt *tbl, struct sSel *out) {
    unsigned int idx = p->idx;
    unsigned int mode = p->mode;
    unsigned short v = p->id;
    int r;
    out->y = -1;
    out->x = -1;
    switch (mode) {
    case 0:
        out->x = func_003D6D50(v);
        break;
    case 1:
        if (idx >= 20) {
            out->x = -1;
        } else {
            out->x = func_003D6DB8(v, tbl[idx].a);
        }
        break;
    case 2: {
        struct sTblEnt *e;
        int t = func_003D6D50(v);
        e = (struct sTblEnt *)(idx * 4 + (int)tbl);
        if (func_003D6CF8(t, *(int *)e) != 0) {
            out->y = e->a;
        } else {
            t = -1;
        }
        out->x = t;
        break;
    }
    }
    r = out->x;
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
int func_003DA810(struct sSelSet *s, int c) {
    int r = 0;
    if (s->ntbl < 0xC8U) {
        r = 1;
        s->tbl[s->ntbl] = c;
        s->ntbl++;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DA848);
#ifdef SKIP_ASM
int func_003DA848(struct sCond *arg0, unsigned char *arg1, int *arg2) {
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
            c = arg0->a[i];
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

int func_003DA910(unsigned char *a0, struct sSelSet *h) {
    struct sShapeInfo o;
    int total = 0;
    int i;
    int r;
    int cnt = a0[4] >> 2;

    for (i = 0; i < cnt; i++) {
        if (func_003DB838(D_004A4824[h->ent[i].x], h->tbl[h->ent[i].cur], &o)) {
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

int func_003DA9C8(char *p, int idx) {
    int r = 1;
    if (*(unsigned short *)p == D_00450660[idx].h) {
        int v = p[8];
        if (v > 0) {
            if (!(D_00450660[idx].w < v)) {
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
int func_003DAAB0(unsigned char *h, struct sCond *s) {
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
extern int func_003DB5C0(int, int);

void func_003DAB58(unsigned char *a0, struct sSelSet *h) {
    int i = 0;
    int j;
    int n = a0[4] >> 2;
    struct sSel *e;
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
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DAC20);
#ifdef SKIP_ASM
int func_003DAC20(unsigned char *h, struct sSel *e) {
    int wrap = 0;
    int done = 0;
    int i = (h[4] >> 2) - 1;
    struct sSel *p = &e[i];
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

void func_003DACE8(void *a0, struct sSelSet *h, struct sLayer *l) {
    struct sShapeInfo o;
    unsigned char *out;
    int n;
    int i;
    int j;
    struct sCond *c;

    if (func_003D83B8(a0, &out) != 0) {
        i = 0;
        n = l->cnt >> 2;
        for (; i < n; i++) {
            c = (struct sCond *)((int *)l + l->list[i]);
            for (j = 0; j < c->n; j++) {
                if (c->a[j] == 0xFE && !(c->b[j] & 0x80)) {
                    if (func_003DB838(D_004A4824[h->ent[i].x], h->tbl[h->ent[i].cur], &o)) {
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
extern int func_003DB3E0_AE48(int, int) __asm__("func_003DB3E0");

void func_003DAE48(void *a0, int a1, struct sLayer *l, int a3) {
    struct sShapeInfo o;
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

    if (D_0044FF90.f08 != 0) {
        func_003D8330(a0, &out);
        cnt = l->cnt >> 2;
        for (i = 0; i < cnt; i++) {
            tbl = (unsigned char *)l + l->list[i] * 4 + 0xC;
            for (j = 0; j < 4; j++) {
                b = tbl[j];
                if (b != 0xFF) {
                    h = func_003DB3E0_AE48(a1, b);
                    yy = D_00450710[i + a3].y;
                    shp = D_004A4824[D_0045070C[i + a3].x];
                    if (func_003DB838(shp, yy, &o)) {
                        m = 1 << o.col[j];
                        D_0044FF90.f08(a0, h, (int)m, out);
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
void func_003DAFD0(struct sSelSet *s) {
    int i;

    s->ntbl = 0;
    s->n = 0;
    for (i = 11; i >= 0; i--) {
        s->ent[i].flag = 0;
    }
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


/* A 3-byte sequence event, widened. */
struct sEvent {
    int a;
    int b;
    int type;
};

void func_003DB040(unsigned char *ctx, unsigned char *data, int idx, int *tbl) {
    struct sEvent ev;
    int time;
    int count;
    int i;
    unsigned char *track;
    unsigned char *events;
    if (D_0044FF90.f08 != 0) {
        func_003D8330(ctx, &time);
        count = data[7] & 0xF;
        track = data + ((struct sSeqHdr *)data)->ids[idx] * 4;
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
                    D_0044FF90.f08(ctx, a, tbl[b], time);
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
struct B_B208 { unsigned char a, b, c; };

int func_003DB208(unsigned char *a0, struct sSeqHdr *h, int *vals, unsigned char *negmask) {
    struct sEvent t;
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
    n = h->f7 & 0xF;
    tbl = (struct B_B208 *)((unsigned char *)h + (((h->n * 2 + 3) & 0x3FC) + 0xC));
    for (; k < 21; k++) {
        for (j = 0; j < n; j++) {
            bit = 0;
            t.a = tbl[j].a;
            t.b = tbl[j].b;
            t.type = tbl[j].c;
            if (k == 20) {
                if (t.b != 0) continue;
                v = 0;
            } else {
                if (t.b != k) continue;
                v = vals[k];
            }
            mask = 1 << (7 - j);
            a = t.a;
            if (D_0044FF90.f04 != 0) {
                r = D_0044FF90.f04(a0, a, v, out);
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
int func_003DB3E0(struct sSeqHdr *h, unsigned int idx) {
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

unsigned int func_003DB4D0(void) {
    unsigned int s, c, n;

    s = D_00450B70[5] + D_00450B70[4];
    c = 0;
    if (s < D_00450B70[5] || s < D_00450B70[4]) {
        c = 1;
    }
    D_00450B70[4] = s;
    s = s + D_00450B70[3] + c;
    c = s < D_00450B70[3];
    D_00450B70[3] = s;
    s = s + D_00450B70[2] + c;
    c = s < D_00450B70[2];
    D_00450B70[2] = s;
    n = ++D_00450B70[5];
    s = s + D_00450B70[1] + c;
    c = s < D_00450B70[1];
    D_00450B70[1] = s;
    s = s + D_00450B70[0] + c;
    D_00450B70[0] = s;
    if (n == 0) {
        if (++D_00450B70[4] == 0) {
            if (++D_00450B70[3] == 0) {
                if (++D_00450B70[2] == 0) {
                    if (++D_00450B70[1] == 0) {
                        s = ++D_00450B70[0];
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
                if (D_00450B88[head].b == k16) {
                    j++;
                    if (D_00450B88[head].a == cand) {
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
    D_00450B88[D_004A4858].a = res;
    D_00450B88[D_004A4858].b = k16;
    return cand;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2D7498", func_003DB790);
#ifdef SKIP_ASM

void func_003DB790(int seed) {
    int i;
    unsigned int v;

    for (i = 0; i < 32; i++) {
        D_00450B88[i].a = 0xFFFF;
        D_00450B88[i].b = 0xFFFF;
    }
    seed += seed << 16;
    v = seed + 0xF22D0E56;
    D_00450B70[0] = v;
    v += 0x96041893;
    D_00450B70[1] = v;
    v += 0x3DF3B646;
    D_00450B70[2] = v;
    v += 0x40DDE76D;
    D_00450B70[3] = v;
    v += 0x97327AE1;
    D_00450B70[4] = v;
    v += 0xD1A9FBE7;
    D_004A4858 = 0;
    D_00450B70[5] = v;
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
