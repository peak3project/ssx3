#include "common.h"

// PORT: PS2-only COP0 (read the Count register).
#define MFC0_COUNT_2F41(v) __asm__ volatile("mfc0 %0, $9" : "=r"(v))
#define MFC0_COUNT_STMT_2F41(v) do { __asm__ volatile("mfc0 %0, $9" : "=r"(v)); } while (0)
// PORT: PS2-only COP0 (enable interrupts) and memory barrier.
#define EI_2F41() __asm__ volatile("ei")
#define SYNC_2F41() __asm__ volatile("sync")

extern unsigned int strlen(const char *);

/* D_0051F0C0: the SIF request queue (layout from every user in this unit). Requests a[] are sent, results b[] come
   back with the same key; c[] holds the completion callback (fn 0 = none, 1 = store f14 and wake th). */
struct sSifReq { int f0; int f4; int pad8[5]; int key; };
struct sSifRes { int pad0[2]; int f8; int fC; int f10; int f14; int pad18; int key; };
struct sSifCb { int (*fn)(int, int, int, int, int, int, int, int, int *); int *out; int arg; int th; };
struct sSifEnt { int idx; int k1; int k2; int v; };
struct sSifQueue {
    char buf[0x4D88];                   /* byte 0: done flag (func_003F4F40) */
    struct sSifEnt *beg;                /* 0x4D88 */
    struct sSifEnt *end;
    int pad4D90;
    struct sSifReq *a;                  /* 0x4D94 */
    int pad4D98[2];
    struct sSifRes *b;                  /* 0x4DA0 */
    int pad4DA4[2];
    int base2;                          /* 0x4DAC */
    int pad4DB0;
    int base1;                          /* 0x4DB4 */
    int pad4DB8[3];
    struct sSifCb *c;                   /* 0x4DC4 */
    int pad4DC8[2];
    int head;                           /* 0x4DD0 */
    int tail;
    int cnt;
    int pad4DDC;
    int pos;                            /* 0x4DE0 */
    int pad4DE4;
    int h4DE8;
    int h4DEC;
    int h4DF0;
    int h4DF4;
    volatile unsigned last;             /* 0x4DF8: Count at the last update */
    int pad4DFC;
    volatile unsigned long total;       /* 0x4E00 */
    int sema;                           /* 0x4E08 */
};
extern struct sSifQueue D_0051F0C0;

/* D_00525F80: the USB keyboard state. D_00525F88 (+8) is the sceUsbKbGetInfo block and D_00526010 (+0x90) the
   max-connect word handed to func_0040C028; ents[] are 0x8C-byte read buffers with a ready flag at +0x88. */
struct sKb {
    int fd[2];                          /* 0x00 */
    int info[2];                        /* 0x08 */
    unsigned char v[128];               /* 0x10: connected */
    int cnt;                            /* 0x90 */
    unsigned char prev[8];              /* 0x94 */
    unsigned st;                        /* 0x9C */
    unsigned char flag;                 /* 0xA0 */
    int cur;                            /* 0xA4 */
    unsigned char *ents;                /* 0xA8 */
    int a;                              /* 0xAC */
    int b;
    int tick;                           /* 0xB4 */
    int period;
    void (*cb1)(int, int);              /* 0xBC */
    int (*cb2)(int);                    /* 0xC0 */
};
extern struct sKb D_00525F80;

/* D_004A5B20: the memory-card session (0xAC bytes, allocated by func_003FC0E8). params is the caller's 0x64-byte
   block; f9C points to f94 entries; f6C / f70 are the two driver interfaces. Field names are offsets. */
struct sMcEnt { int key; int a; int b; int c; };
struct sMcParams { int w[25]; };
struct sMcKey { char b[4]; };
struct sMcIfA { int (*f00)(int); int (*f04)(void); int pad08; int (*f0C)(char *, int); int (*f10)(int, int); int (*f14)(int, int); int (*f18)(void); };
struct sMcIfB { int (*f00)(int); int (*f04)(void); int pad08; int (*f0C)(int, int, int); int (*f10)(int, int); int (*f14)(int); };
struct sMcState {
    struct sMcParams params;            /* 0x00 */
    char *f64;
    int f68;
    struct sMcIfA *f6C;
    struct sMcIfB *f70;
    int f74;
    int f78;                            /* current step */
    int f7C;
    int f80;
    int f84;
    struct sMcKey f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    struct sMcEnt *f9C;
    int fA0;
    int fA4;
    char fA8;
};
extern struct sMcState *D_004A5B20;

/* D_004A4BD8: the pending memory-card request (0x74 bytes). body is a copy of the caller's parameter block. */
struct sMcReqBody { int port; int slot; int pad08[16]; char name[0x18]; };
struct sMcReq {
    int op;                             /* 0x00: request kind, 0 = none */
    int st;                             /* 0x04: state */
    int f08;
    struct sMcReqBody body;             /* 0x0C */
    int f6C;
    int f70;
};
extern struct sMcReq *D_004A4BD8;

/* D_004A4BDC: the memory-card driver (0x42C bytes): callbacks and per-op / per-state handler tables. */
struct sMcDrv {
    unsigned short ports;               /* 0x00: bit per usable slot */
    short pad02;
    int f04;
    int f08;
    int f0C;
    void (*f10)(int);                   /* 0x10 */
    void (*f14)(int);
    int f18;
    void (*f1C)(int);
    int f20;
    int f24;
    int f28;
    void (*f2C)(int, int, int);         /* 0x2C */
    void (*f30)(int, int, int);
    void (*f34)(int, int, int);
    void (*f38)(int);
    int f3C;
    int (*f40)(int *, int *);           /* 0x40 */
    int f44;
    int (**f48)(int, int *, int *);     /* 0x48: by op */
    int (**f4C)(int, int, int);         /* 0x4C: by state */
    char f50[0x3D0];
    int f420;
    int f424;
    int h;                              /* 0x428: heap */
};
extern struct sMcDrv *D_004A4BDC;

/* D_004A4BC4: the network account session (0x14C bytes, func_003F6C70). cur / saved are the current and the saved
   phase (mode + handler slots); handler slots hold untyped code addresses (callers cast them). */
struct sNetHdr { int w[17]; };
struct sNetPhase {
    unsigned mode;                      /* +0x00 */
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    int fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    void *fFC;
    void *f100;
};
struct sNetAcct {
    struct sNetHdr hdr;                 /* 0x00 */
    struct sMcParams params;            /* 0x44 */
    char name[0x11];                    /* 0xA8 */
    char pass[0x11];                    /* 0xB9 */
    char *out;                          /* 0xCC */
    unsigned st;                        /* 0xD0 */
    void *fD4;
    struct sNetPhase cur;               /* 0xD8 */
    unsigned f104;
    int f108;
    struct sNetPhase saved;             /* 0x10C */
    int f138;
    int f13C;
    int heap;                           /* 0x140 */
    char *f144;
    int f148;
};
extern struct sNetAcct *D_004A4BC4;

/* D_00451518: the CRC-32 state (func_003FB3A0 allocates the 0x400-byte table). */
struct sCrc { unsigned *table; int f04; int *f08; unsigned crc; int heap; };
extern struct sCrc D_00451518;

/* XOR key window (func_003FB650): D_004A4BE4 .. D_004A4BE8 is the key, D_004A4BEC the next key byte, D_004A4BF0
   the cipher state (4 = idle). */
extern unsigned char *D_004A4BE4;
extern unsigned char *D_004A4BE8;
extern unsigned char *D_004A4BEC;
extern int D_004A4BF0;

/* D_0051F030: the periodic callbacks run by func_003F42A0 (fn 0 = free slot). */
struct sTick { void (*fn)(int, int); int arg; };
extern struct sTick D_0051F030[16];

/* SIF RPC client (func_003F6A40 binds it): D_004A5B14 = bound, D_00526100 the client data, D_00526080 the
   send buffer. */
extern unsigned char D_004A5B14;
extern int D_00526100[];

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F31F8);
#ifdef SKIP_ASM
extern char *D_004A4B98;
extern void f2220(void *) __asm__("func_003F2220");
typedef struct { unsigned count; unsigned st[4]; unsigned char buf[64]; } sMd5;
void func_003F31F8(sMd5 *ctx, unsigned char *out, int n) {
    unsigned char c = 0x80;
    unsigned w = 0;
    int i;
    i = ctx->count & 0x3F;
    do {
        ctx->buf[i] = c;
        i++;
        c = 0;
        if (i == 0x40) {
            f2220(ctx);
            i = 0;
        }
    } while (i != 0x38);
    ctx->buf[0x3D] = 0;
    ctx->buf[0x38] = (unsigned char)ctx->count << 3;
    ctx->buf[0x3E] = 0;
    ctx->buf[0x3F] = 0;
    ctx->buf[0x39] = ctx->count >> 5;
    ctx->buf[0x3A] = ctx->count >> 13;
    ctx->buf[0x3B] = ctx->count >> 21;
    ctx->buf[0x3C] = ctx->count >> 29;
    f2220(ctx);
    for (i = 0; i < 16; i++) {
        if ((i & 3) == 0) w = ctx->st[i >> 2];
        if (n == 16) {
            *out = w;
            out++;
        } else if (n > 32) {
            *out = D_004A4B98[(w >> 4) & 0xF];
            out++;
            *out = D_004A4B98[w & 0xF];
            out++;
        }
        w >>= 8;
    }
    if (n > 32) {
        *out = 0;
    } else if (n != 16) {
        while (n > 0) {
            *out = 0;
            out++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F33B0);
#ifdef SKIP_ASM
extern int D_004A4B9C;
extern unsigned D_00496C08[];
extern char D_00497008[];
extern char D_0051EEF8[];
void func_003F33B0(unsigned char *s, unsigned char *key, int klen, int rounds) {
    int i;
    int lim;
    unsigned crc;

    if (D_004A4B9C == 0) {
        D_004A4B9C = 1;
        func_003F33B0((unsigned char *)D_0051EEF8, (unsigned char *)D_00497008, -1, 10);
    }
    i = 0xFF;
    if (rounds < 0) {
        rounds = -rounds;
    } else {
        unsigned char *p = s + 0xFF;
        for (; i >= 0; i--) *p-- = i;
        s[0x100] = 0;
        *(int *)(s + 0x104) = 0;
    }
    if (klen < 0) {
        klen = 0;
        while (key[klen] != 0) klen++;
    }
    if (klen > 0) {
        crc = 0;
        i = 0;
        lim = rounds << 8;
        if (lim > 0) {
            do {
                unsigned char *p;
                unsigned char *q;
                unsigned char t;
                int r = i % klen;
                p = s + (i & 0xFF);
                t = *p;
                i++;
                crc = (crc >> 8) ^ D_00496C08[(crc & 0xFF) ^ key[r]];
                crc = (crc >> 8) ^ D_00496C08[(crc & 0xFF) ^ t];
                q = s + (crc & 0xFF);
                *p = *q;
                *q = t;
            } while (i < lim);
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3530);
#ifdef SKIP_ASM
extern unsigned D_00496C08[];
void func_003F3530(unsigned char *s, unsigned char *buf, int n) {
    unsigned char i = s[0x100];
    unsigned j = *(unsigned *)(s + 0x104);
    for (; n > 0; n--) {
        unsigned char a, b;
        j = (j >> 8) ^ D_00496C08[(j & 0xFF) ^ s[i++]];
        a = s[i];
        b = s[j & 0xFF];
        s[i] = b;
        s[j & 0xFF] = a;
        *buf++ ^= s[(unsigned char)(a - b)];
    }
    s[0x100] = i;
    *(unsigned *)(s + 0x104) = j;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F35D0);
#ifdef SKIP_ASM
extern void f33B0w(void *, int, int, int) __asm__("func_003F33B0");
extern void f3530w(void *, unsigned char *, int) __asm__("func_003F3530");
extern char D_0051EEF8[];
extern char D_00497018[];
int func_003F35D0(char *out, int n, unsigned char *in, int a, int b, int c) {
    unsigned char ctx[0x110];
    unsigned char ch;
    unsigned char k;
    k = 0;
    f33B0w(ctx, a, b, c);
    f33B0w(D_0051EEF8, a, b, -c);
    f33B0w(D_0051EEF8, (int)D_00497018, -1, -1);
    for (; n > 1; n--) {
        if (in == 0) {
            f3530w(D_0051EEF8, &ch, 1);
            ch = (ch & 0x3F) + 0x20;
        } else {
            ch = *in;
            in++;
            if (ch == 0) in = 0;
        }
        if ((unsigned)(ch - 0x20) > 0x5E) ch = 0x7F;
        f3530w(ctx, &k, 1);
        *out = (ch + 0x40 + (int)(k % 0x60U)) % 0x60 + 0x20;
        out++;
    }
    if (n > 0) *out = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3748);
#ifdef SKIP_ASM
extern void f33B0(void *, int, int, int) __asm__("func_003F33B0");
extern void f3530(void *, unsigned char *, int) __asm__("func_003F3530");
int func_003F3748(char *out, int n, unsigned char *in, int a, int b, int c) {
    unsigned char ctx[0x110];
    unsigned char k;
    int i;
    int ch;
    int cur;
    unsigned t;
    k = 0;
    f33B0(ctx, a, b, c);
    i = 0;
    while (i < n - 1) {
        cur = in[i];
        i++;
        if (cur == 0) break;
        f3530(ctx, &k, 1);
        t = k % 96U - 0x40;
        ch = (int)(cur - t) % 96 + 0x20;
        *out = ch;
        if ((char)ch == 0x7F) break;
        out++;
    }
    if (i < n) *out = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3860);
#ifdef SKIP_ASM
extern char D_0051F000[];
extern int func_003F4C98(char *, int, int);
extern int f4C68g(char *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
int func_003F3860(int *self) {
    int id = self[0x58 / 4];
    func_003F4C98(D_0051F000, 'name', 'done');
    f4C68g(D_0051F000, 1, id, 0, 0, 0, 0, 0, 1, self);
    if (self[0] > 0) {
        func_003F4C98(D_0051F000, 'name', 'addr');
        f4C68g(D_0051F000, 1, id, 0, 0, 0, 0, 0, 1, self + 1);
    }
    return self[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3940);
#ifdef SKIP_ASM
extern char D_0051F010[];
extern int func_003F4C98(char *, int, int);
extern void func_00256BD8(int *);
void func_003F3940(int *self) {
    int v = self[0x58 / 4];
    func_003F4C98(D_0051F010, 'name', 'free');
    func_003F4C68(D_0051F010, 1, v, 0, 0, 0, 0, 0, 0, 0);
    func_00256BD8(self);
}

#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F39C8);
#ifdef SKIP_ASM
extern char D_0051F020[];
extern int *RpcAlloc(int);
extern void f6210k(int *, int, int) __asm__("func_00416210");
extern int func_003F4C98(char *, int, int);
extern int f4C68k(char *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern int func_003F3860(int *);
extern void func_003F3940(int *);
int *f39C8impl(int a, int b) __asm__("func_003F39C8");
int *f39C8impl(int a, int b) {
    int f;
    int *p = RpcAlloc(0x5C);
    if (p) {
        f6210k(p, 0, 0x5C);
        f = (int)func_003F3860;
        p[3] = (int)func_003F3940;
        p[2] = f;
        func_003F4C98(D_0051F020, 'name', 'look');
        f = 1;
        f4C68k(D_0051F020, f, 0, b, a, -f, 0, 0, f, p + 0x58 / 4);
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3A98);
#ifdef SKIP_ASM
extern int func_003F39C8(void);
int func_003F3A98(void* p, int a) { return func_003F39C8(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3AB8);
#ifdef SKIP_ASM
extern int func_003F39C8(void);
int func_003F3AB8(void) {
    int *p;
    int r = 0;
    p = (int *)func_003F39C8();
    if (p) {
        while (((int (*)(int *))p[2])(p) == 0)
            ;
        r = p[1];
        ((void (*)(int *))p[3])(p);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3B18);
#ifdef SKIP_ASM
extern int D_004A4BA0;
extern int D_004A4BA4;
extern int func_003F5470(void);
extern void f5000(int) __asm__("func_003F5000");
extern int func_003F4D68(void);
extern int func_003F4C98(char *, int, int);
extern int f4C68e(char *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
int func_003F3B18(int a) {
    char buf[16];
    if (D_004A4BA0 != 0) return -1;
    if (func_003F5470() <= 0) {
        f5000(0);
        func_003F4D68();
    }
    func_003F4C98(buf, 'netw', 'crea');
    f4C68e(buf, 1, 0, '1731', a, -1, 0, 0, 1, &D_004A4BA4);
    D_004A4BA0 = 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3BC8);
#ifdef SKIP_ASM
extern int D_004A4BA4;
extern int func_003F4C98(char *, int, int);
extern int func_003F4C68b(char *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
int func_003F3BC8(int self, int a, int b) {
    char buf[16];
    int out;
    func_003F4C98(buf, 'netw', 'list');
    func_003F4C68b(buf, 5, D_004A4BA4, 0, self, -1, a, b << 8, 1, &out);
    return out;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F3C50);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3CC0);
#ifdef SKIP_ASM
extern int D_004A4BA0;
extern int D_004A4BA4;
extern int func_003F4C98(char *, int, int);
extern int f4C68m(char *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
int func_003F3CC0(int tag, int a, int b) {
    char buf[16];
    int o20;
    int o24;
    if (tag == 'open') {
        return D_004A4BA0;
    }
    if (tag == 'onln') {
        func_003F4C98(buf, 'netw', 'stat');
        f4C68m(buf, 1, D_004A4BA4, 'host', 0, 0, 0, 0, 1, &o20);
        return o20 != 0;
    }
    if (tag == 'conn') {
        func_003F4C98(buf, 'netw', 'stat');
        f4C68m(buf, 5, D_004A4BA4, 'conn', 0, 0, a, b, 1, &o20);
        return o20;
    }
    if (tag == 'host') {
        func_003F4C98(buf, 'netw', 'stat');
        f4C68m(buf, 1, D_004A4BA4, 'host', 0, 0, 0, 0, 1, &o24);
        return o24;
    }
    if (tag == 'addr') {
        func_003F4C98(buf, 'netw', 'stat');
        f4C68m(buf, 1, D_004A4BA4, 'addr', 0, 0, 0, 0, 1, &o24);
        return o24;
    }
    if (tag == 'macx') {
        func_003F4C98(buf, 'netw', 'stat');
        func_003F4C68(buf, 5, D_004A4BA4, 'macx', 0, 0, a, b, 1, 0);
        return 0;
    }
    if (tag == 'bbnd' || tag == 'type') {
        func_003F4C98(buf, 'netw', 'stat');
        f4C68m(buf, 1, D_004A4BA4, 'type', 0, 0, a, b, 1, &o20);
        if (tag == 'bbnd') {
            o20 = (o20 >> 2) & 1;
        }
        return o20;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3F78);
#ifdef SKIP_ASM
extern char D_004512E8[];
extern const char D_00497028[];
extern void f3CC0(int, unsigned char *, int) __asm__("func_003F3CC0");
char *func_003F3F78(void) {
    unsigned char b[16];
    if (D_004512E8[0] == 0) {
        f3CC0(0x6d616378, b, 0x10);
        D_004512E8[1] = D_00497028[b[0] >> 4];
        D_004512E8[2] = D_00497028[b[0] & 0xF];
        D_004512E8[3] = D_00497028[b[1] >> 4];
        D_004512E8[4] = D_00497028[b[1] & 0xF];
        D_004512E8[5] = D_00497028[b[2] >> 4];
        D_004512E8[6] = D_00497028[b[2] & 0xF];
        D_004512E8[7] = D_00497028[b[3] >> 4];
        D_004512E8[8] = D_00497028[b[3] & 0xF];
        D_004512E8[9] = D_00497028[b[4] >> 4];
        D_004512E8[10] = D_00497028[b[4] & 0xF];
        D_004512E8[11] = D_00497028[b[5] >> 4];
        D_004512E8[12] = D_00497028[b[5] & 0xF];
        D_004512E8[0] = '$';
        D_004512E8[13] = 0;
    }
    return D_004512E8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F40B8);
#ifdef SKIP_ASM
extern int D_004A4BA4;
extern int func_003F4C98(char *, int, int);
extern int func_003F4C68(char *, int, int, int, int, int, int, int, int, int);
int func_003F40B8(void) {
    char buf[16];
    func_003F4C98(buf, 'netw', 'shut');
    func_003F4C68(buf, 1, D_004A4BA4, 0, 0, 0, 0, 0, 1, 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4118);
#ifdef SKIP_ASM
extern int D_004A4BA0;
extern int D_004A4BA4;
extern int func_003F40B8(void);
extern int func_003F4C98(char *, int, int);
extern int func_003F4C68(char *, int, int, int, int, int, int, int, int, int);
int func_003F4118(void) {
    char buf[16];
    if (D_004A4BA0 == 0) return -1;
    func_003F40B8();
    func_003F4C98(buf, 'netw', 'dest');
    func_003F4C68(buf, 1, D_004A4BA4, 0, 0, 0, 0, 0, 1, 0);
    D_004A4BA0 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4198);
#ifdef SKIP_ASM
extern int func_003F4DE8(void);
int func_003F4198(void) { return func_003F4DE8(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F41B8);
#ifdef SKIP_ASM
extern unsigned int func_003F4DE8u(void) __asm__("func_003F4DE8");
void func_003F41B8(int n) {
    if (n == 0) n = 5;
    if (n > 0) {
        unsigned int end = func_003F4DE8u() + n;
        while (func_003F4DE8u() < end) func_003F4DE8u();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4210);
#ifdef SKIP_ASM
int func_003F4210(void (*fn)(int, int), int arg) {
    int i;
    struct sTick *p = D_0051F030;
    for (i = 0; i < 16; i++) {
        if (p->fn == 0) {
            p->fn = fn;
            p->arg = arg;
            return 0;
        }
        p++;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4250);
#ifdef SKIP_ASM
int func_003F4250(void (*fn)(int, int), int arg) {
    int i;
    struct sTick *p = D_0051F030;
    for (i = 0; i < 16; i++) {
        if (p->fn == fn && p->arg == arg) {
            p->fn = 0;
            p->arg = 0;
            return 0;
        }
        p++;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F42A0);
#ifdef SKIP_ASM
extern int D_004A4BA0;
extern unsigned D_004A4BAC;
extern int func_003F4A78(void);
void func_003F42A0(void) {
    int i;
    struct sTick *p;
    if (D_004A4BA0 != 0) {
        if (func_003F4DE8() < D_004A4BAC) return;
        D_004A4BAC = func_003F4DE8() + 5;
    }
    func_003F4A78();
    p = D_0051F030;
    for (i = 0xF; i >= 0; i--) {
        if (p->fn) p->fn(p->arg, func_003F4DE8());
        p++;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4330);
#ifdef SKIP_ASM
extern int func_003F4DE8(void);
int func_003F4330(void) { return func_003F4DE8(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4350);
#ifdef SKIP_ASM
int func_003F4350(unsigned char *a, unsigned char *b, int n) {
    int d;
    if (n < 0) {
        while (*a) {
            if (*a != *b)
                return *a - *b;
            a++;
            b++;
        }
        return 0;
    }
    while (n > 0) { d = *a++ - *b; if (d) return d; n--; b++; }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F43D0);
#ifdef SKIP_ASM
int func_003F43D0(int a, ...) { return 1; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4410);
#ifdef SKIP_ASM
int func_003F4410(int a0, struct sSifQueue *d) {
    unsigned c;
    unsigned last = d->last;
    unsigned long total;
    MFC0_COUNT_STMT_2F41(c);
    total = d->total;
    d->total = total + (unsigned)(c - last);
    d->last = c;
    SYNC_2F41();
    EI_2F41();
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4448);
#ifdef SKIP_ASM
extern int f4C50(int) __asm__("func_00424C50");
extern int f3B80(int, void *, void *) __asm__("func_00423B80");
void func_003F4448(int a, int b, struct sSifQueue *s);
void func_003F4448(int a, int b, struct sSifQueue *s) {
    if (a == s->h4DEC) s->h4DEC = -1;
    if (a == s->h4DF0) s->h4DF0 = -1;
    if (s->tail != s->head) {
        if (s->b[s->tail].key == s->a[s->tail].key) f4C50(s->h4DE8);
        if (s->h4DEC < 0 && s->h4DF0 < 0) s->h4DF0 = f3B80(0x10, (void *)func_003F4448, s);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F44F8);
#ifdef SKIP_ASM
extern int func_003F4A78(void);
extern int func_00423CC0(void);
extern volatile int D_004A5B04;
void func_003F44F8(void) {
    while (1) {
        func_003F4A78();
        D_004A5B04 = 1;
        func_00423CC0();
        D_004A5B04 = 0;
    }
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F4528);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4A78);
#ifdef SKIP_ASM
extern volatile int D_004A5B00;
extern int func_00423DE0(int);
extern int func_00423DC0(int);
extern int func_00423CD0(int);
int func_003F4A78(void) {
    struct sSifQueue *g = &D_0051F0C0;
    int n = 0;
    while (g->tail != g->head && g->b[g->tail].key == g->a[g->tail].key) {
        int th, key, kind, arg, p10, p14, addr, len, p8, pC;
        D_004A5B00 = 1;
        func_00423DE0(g->sema);
        D_004A5B00 = 0;
        key = g->b[g->tail].key;
        if (key != g->a[g->tail].key) {
            func_00423DC0(g->sema);
            return n;
        }
        th = 0;
        addr = g->base2 + (g->a[g->tail].f0 - g->base1);
        p8 = g->b[g->tail].f8;
        pC = g->b[g->tail].fC;
        p10 = g->b[g->tail].f10;
        p14 = g->b[g->tail].f14;
        kind = (int)g->c[g->tail].fn;
        arg = g->c[g->tail].arg;
        len = g->a[g->tail].f4;
        if (kind != 0) {
            if (kind == 1) {
                if (g->c[g->tail].out != 0) *g->c[g->tail].out = p14;
                th = g->c[g->tail].th;
            } else {
                g->c[g->tail].fn(key, arg, p10, p14, addr, len, p8, pC, g->c[g->tail].out);
                SYNC_2F41();
            }
        }
        if (g->a[g->tail].f4 > 0) {
            g->pos = g->a[g->tail].f0 - g->base1;
            g->pos += (g->a[g->tail].f4 + 0x3F) & ~0x3F;
        }
        g->tail = (g->tail + 1) % g->cnt;
        func_00423DC0(g->sema);
        if (th != 0) func_00423CD0(th);
        n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4C68);
#ifdef SKIP_ASM
extern int func_003F4528(int, int, int, int, int, int, int, int, int, int, int);
int func_003F4C68_impl(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) __asm__("func_003F4C68");
int func_003F4C68_impl(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    int unused[12];
    return func_003F4528(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4C98);
#ifdef SKIP_ASM
int f4C98impl(struct sSifEnt *c, int k1, int k2) __asm__("func_003F4C98");
int f4C98impl(struct sSifEnt *c, int k1, int k2) {
    struct sSifQueue *g = &D_0051F0C0;
    struct sSifEnt *e;
    if (k1 == c->k1 && k2 == c->k2) {
        int i = c->idx;
        if (i >= 0) {
            if (i < 0x81) {
                struct sSifEnt *ent = (struct sSifEnt *)(i * 16 + (int)g->beg);
                if (ent->v == c->v && ent->k1 == k1) return 0;
            }
        }
    }
    c->k2 = k2;
    c->k1 = k1;
    for (e = g->beg; e != g->end; e++) {
        if (e->k1 == c->k1 && e->k2 == c->k2) {
            c->idx = e->idx;
            c->v = e->v;
            return 1;
        }
    }
    c->idx = 0;
    c->v = 0;
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4D68);
#ifdef SKIP_ASM
extern int func_003F4C68d(int *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_003F4A78(void);
int func_003F4D68(void) {
    int t[4];
    t[3] = 1;
    func_003F4C68d(t, 1, 0, 0, 0, 0, (int)D_0051F0C0.beg, (char *)D_0051F0C0.end - (char *)D_0051F0C0.beg, 1, 0);
    while (D_0051F0C0.head != D_0051F0C0.tail) func_003F4A78();
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4DE8);
#ifdef SKIP_ASM
extern long func_00411538_4DE8(long, long) __asm__("func_00411538");
int func_003F4DE8(void) {
    volatile unsigned cnt;
    volatile unsigned last;
    volatile unsigned long total;
    volatile unsigned long sum;
    unsigned c, t;
    do {
        last = D_0051F0C0.last;
        total = D_0051F0C0.total;
        MFC0_COUNT_2F41(c);
        cnt = c;
        t = cnt;
        t = last;
    } while (t != D_0051F0C0.last || total != D_0051F0C0.total);
    sum = total + (unsigned)(cnt - last);
    return (int)func_00411538_4DE8(sum, 0x48000);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4E80);
#ifdef SKIP_ASM
extern int func_00424698(int, int);
int func_003F4E80(int a0, int a1) { return func_00424698(a0, a0 + a1); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4EA0);
#ifdef SKIP_ASM
int func_003F4EA0(unsigned a, int *out) {
    unsigned *p = (unsigned *)((a & 0xFFFFFFF) | 0x20000000);
    unsigned x = p[0];
    int sz;
    int n;
    unsigned *q;
    unsigned h;
    if (x == 0 || (sz = p[3]) < 0 || sz > 0x8000) return -1;
    n = ((sz + 0xF) & 0x7FFFFFF0) + 0x10;
    q = (unsigned *)((x & 0xFFFFFFF) | 0x20000000);
    h = p[2];
    if (q != (unsigned *)((char *)p + n)) return -2;
    if ((((q[0]) & 0xFFFFFFF) | 0x20000000) != (unsigned)p) return -2;
    if (h != q[2]) return -3;
    if (out) *out = sz;
    return h;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4F40);
#ifdef SKIP_ASM
extern struct { unsigned char b; char pad[11]; int w; } D_00451340;
extern void func_00424020(int);
extern void func_004261B0(int, void *, int, int, int, int);
int func_003F4F40(void) {
    int r;
    unsigned start;
    unsigned c;
    char *flag = D_0051F0C0.buf;
    unsigned limit = 0x2FAF080;
    *flag = 0;
    D_00451340.w = (int)flag + 1;
    func_00424020(0);
    func_004261B0(1, &D_00451340, D_00451340.b, 0, 0, 0);
    r = 1;
    MFC0_COUNT_2F41(start);
    while (*flag == 0) {
        MFC0_COUNT_2F41(c);
        if (c - start > limit) {
            r = 0;
            break;
        }
        func_00424020(0);
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F5000);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F53F8);
#ifdef SKIP_ASM
extern int D_004A4BB0;
extern void func_00423B30(int);
extern void func_00423AA0(int, int);
extern void func_00423BF0(int);
extern void func_00423BB0(int);
extern void func_00423DB0(int);
int func_003F53F8(void) {
    struct sSifQueue *q = &D_0051F0C0;
    if (q->h4DEC >= 0) func_00423B30(q->h4DEC);
    if (q->h4DF0 >= 0) func_00423B30(q->h4DF0);
    func_00423AA0(2, q->h4DF4);
    func_00423BF0(q->h4DE8);
    func_00423BB0(q->h4DE8);
    func_00423DB0(q->sema);
    D_004A4BB0 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5470);
#ifdef SKIP_ASM
extern int D_004A4BB0;
int func_003F5470(void) {
    return D_004A4BB0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5478);
#ifdef SKIP_ASM
extern char D_00525F00[];
extern int *RpcAlloc(int);
extern void *f6210h(void *, int, int) __asm__("func_00416210");
extern int func_00424698(int, int);
extern void func_00424020(int);
extern void func_00256BD8(int *);
extern int func_003F4C98(char *, int, int);
extern int func_003F4C68(char *, int, int, int, int, int, int, int, int, int);
int *func_003F5478(int size) {
    int *p;

    if (size < 0x1000) size = 0x1000;
    if (size > 0x2000) size = 0x2000;

    p = RpcAlloc(size + 0x9C);
    if (p == 0) return 0;
    f6210h(p, 0, 0x9C);
    p[1] = ((int)p + 0x5B) & ~0x3F;
    p[5] = size;
    p[6] = p[1] + 0x40;
    f6210h((void *)p[1], 0, 0x20);
    f6210h((void *)p[6], 0, p[5]);
    func_00424698(p[1], p[1] + 0x20);
    func_00424698(p[6], p[6] + p[5]);
    func_00424020(0);
    func_003F4C98(D_00525F00, 'sess', 'crea');
    func_003F4C68(D_00525F00, 1, 0, size, 0, 0, 0, 0, 1, (int)p);
    if (p[0] == 0) {
        func_00256BD8(p);
        p = 0;
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F55B8);
#ifdef SKIP_ASM
extern char D_00525F10[];
extern int func_003F4C98(char *, int, int);
extern void func_00256BD8(int *);
void func_003F55B8(int *p) {
    func_003F4C98(D_00525F10, 'sess', 'dest');
    func_003F4C68(D_00525F10, 1, *p, 0, 0, 0, 0, 0, 1, 0);
    func_00256BD8(p);
}

#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5638);
#ifdef SKIP_ASM
extern char D_00525F20[];
extern int func_003F4C98(char *, int, int);
extern int func_003F4C68(char *, int, int, int, int, int, int, int, int, int);
extern int func_00424698(int, int);
typedef struct { unsigned short family; unsigned short port; int addr; int z8; int zC; } SA5638;
int func_003F5638(int *self, unsigned addr, int port) {
    unsigned v;
    if (((SA5638 *)self[1])->family != 0) return -1;
    ((SA5638 *)self[1])->family = 2;
    ((SA5638 *)self[1])->port = 0;
    ((SA5638 *)self[1])->addr = 0;
    ((SA5638 *)self[1])->z8 = 0;
    ((SA5638 *)self[1])->zC = 0;
    ((unsigned char *)self[1])[2] = port >> 8;
    ((unsigned char *)self[1])[3] = port;
    v = addr;
    ((unsigned char *)self[1])[7] = v;
    v >>= 8;
    ((unsigned char *)self[1])[6] = v;
    v >>= 8;
    ((unsigned char *)self[1])[5] = v;
    v >>= 8;
    ((unsigned char *)self[1])[4] = v;
    func_00424698(self[1], self[1] + 0x20);
    func_003F4C98(D_00525F20, 'sess', 'conn');
    func_003F4C68(D_00525F20, 0, self[0], 0, self[1], 0x10, 0, 0, 0, 0);
    self[4] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5738);
#ifdef SKIP_ASM
extern char D_00525F30[];
extern int func_003F4C98(char *, int, int);
extern void func_00416210b(int, int, int) __asm__("func_00416210");
int func_003F5738(int *self) {
    func_003F4C98(D_00525F30, 'sess', 'disc');
    func_003F4C68(D_00525F30, 0, self[0], 0, 0, 0, 0, 0, 0, 0);
    func_00416210b(self[1], 0, 0x20);
    self[4] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F57C8);
#ifdef SKIP_ASM
typedef struct { unsigned char b[0x18]; } B57C8;
typedef struct { int f0; B57C8 *f4; int f8; int fC; int f10; } S57C8;
extern char D_00525F40[];
extern int func_003F4C98(char *, int, int);
extern int c57_4C68(char *, int, int, int, int, int, B57C8 *, int, int, int) __asm__("func_003F4C68");
int func_003F57C8_impl(S57C8 *self, int key) __asm__("func_003F57C8");
int func_003F57C8_impl(S57C8 *self, int key) {
    func_003F4C98(D_00525F40, 'sess', 'stat');
    c57_4C68(D_00525F40, 0, self->f0, 0, 0, 0, self->f4, 0x20, 1, 0);
    if (key == 'port') {
        return (self->f4->b[2] << 8) | self->f4->b[3];
    }
    if (key == 'addr') {
        return (((self->f4->b[4] << 8 | self->f4->b[5]) << 8 | self->f4->b[6]) << 8) | self->f4->b[7];
    }
    if (key == 'ladr') {
        return (((self->f4->b[0x14] << 8 | self->f4->b[0x15]) << 8 | self->f4->b[0x16]) << 8) | self->f4->b[0x17];
    }
    if (key == 'lprt') {
        return (self->f4->b[0x12] << 8) | self->f4->b[0x13];
    }
    if (key == 'ibuf') {
        return self->f10;
    }
    return 0;
}
#endif

void func_003F5908(void) {
}

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5910);
#ifdef SKIP_ASM
typedef struct { int n0; unsigned char *p; int n; char *s; int z; } IO5910;
extern char D_00525F50[];
extern int func_003F4C98(char *, int, int);
extern int c59_4C68(char *, int, int, int, IO5910 *, int, int, int, int, int) __asm__("func_003F4C68");
extern void c59_5908(int *) __asm__("func_003F5908");
int func_003F5910(int *self, int a, int b, char *str, int len) {
    unsigned char hdr[12];
    IO5910 io;
    c59_5908(self);
    if (len < 0) {
        len = strlen(str) + 1;
    }
    len += 0xC;
    hdr[8] = len >> 24;
    hdr[9] = len >> 16;
    hdr[10] = len >> 8;
    hdr[11] = len;
    hdr[0] = a >> 24;
    hdr[1] = a >> 16;
    hdr[2] = a >> 8;
    hdr[3] = a;
    hdr[4] = b >> 24;
    hdr[5] = b >> 16;
    hdr[6] = b >> 8;
    hdr[7] = b;
    io.n0 = 0xC;
    io.p = hdr;
    io.n = len - 0xC;
    io.s = str;
    io.z = 0;
    func_003F4C98(D_00525F50, 'sess', 'send');
    c59_4C68(D_00525F50, 2, self[0], 0, &io, 0, 0, 0, 0, 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5A50);
#ifdef SKIP_ASM
typedef struct { int f0; int f4; volatile int f8; volatile int fC; volatile int f10; int f14; char *f18; } S5A50;
int func_003F5A50_cb(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int len, S5A50 *self) __asm__("func_003F5A50");
int func_003F5A50_cb(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int len, S5A50 *self) {
    self->f10 = len;
    self->fC = 0;
    self->f8 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5A70);
#ifdef SKIP_ASM
typedef struct { int f0; int f4; volatile int f8; volatile int fC; volatile int f10; int f14; unsigned char *f18; } S5A70;
extern char D_00525F60[];
extern char D_004A4BB8[];
extern int func_003F4C98(char *, int, int);
extern void a70_47D8(unsigned char *, unsigned char *) __asm__("func_004247D8");
extern int a70_4C68(char *, int, int, int, int, int, unsigned char *, int, int, int) __asm__("func_003F4C68");
extern int func_003F5A50(void);
int func_003F5A70(S5A70 *self, unsigned *o1, unsigned *o2, char **o3) {
    int n;
    if (self->fC >= self->f10) {
        if (self->f8 == 0 && self->fC >= self->f10) {
            self->f8 = 1;
            if (self->f10 > 0) {
                a70_47D8(self->f18, self->f18 + self->f14 - 1);
                self->f10 = 0;
                self->fC = self->f10;
            }
            func_003F4C98(D_00525F60, 'sess', 'recv');
            a70_4C68(D_00525F60, 0, self->f0, 0, 0, 0, self->f18, self->f14, (int)func_003F5A50, (int)self);
        }
        return -1;
    } else {
        unsigned char *e = self->f18 + self->fC;
        char *u = (char *)(self->f18 + self->fC) + 0xC;
        n = e[8] << 24 | e[9] << 16 | e[10] << 8 | e[11];
        n -= 0xC;
        if (n < 1) u = D_004A4BB8;
        else u[n - 1] = 0;
        if (o1) *o1 = e[0] << 24 | e[1] << 16 | e[2] << 8 | e[3];
        if (o2) *o2 = e[4] << 24 | e[5] << 16 | e[6] << 8 | e[7];
        if (o3) *o3 = u;
        return n;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5C38);
#ifdef SKIP_ASM
typedef struct { int f0; int f4; volatile int f8; volatile int fC; volatile int f10; int f14; char *f18; } S5C38;
extern char D_00525F70[];
extern int c38_5A70(S5C38 *, int, int, int) __asm__("func_003F5A70");
extern void c38_605C(char *, char *, int) __asm__("func_0041605C");
extern void c38_47D8(char *, char *) __asm__("func_004247D8");
extern int func_003F4C98(char *, int, int);
extern int c38_4C68(char *, int, int, int, int, int, char *, int, int, int) __asm__("func_003F4C68");
extern int func_003F5A50(void);
int func_003F5C38_impl(S5C38 *self, int a, int b, char *buf, int max) __asm__("func_003F5C38");
int func_003F5C38_impl(S5C38 *self, int a, int b, char *buf, int max) {
    int t;
    int n = c38_5A70(self, a, b, 0);
    if (n >= 0) {
        if (n < max) max = n;
        if (buf) c38_605C(buf, self->f18 + self->fC + 0xC, max);
        t = self->fC + 0xC;
        self->fC = t + n;
        if (self->fC >= self->f10 && self->f8 == 0 && self->fC >= self->f10) {
            self->f8 = 1;
            if (self->f10 > 0) {
                c38_47D8(self->f18, self->f18 + self->f14 - 1);
                self->f10 = 0;
                self->fC = self->f10;
            }
            func_003F4C98(D_00525F70, 'sess', 'recv');
            c38_4C68(D_00525F70, 0, self->f0, 0, 0, 0, self->f18, self->f14, (int)func_003F5A50, (int)self);
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5D88);
#ifdef SKIP_ASM
extern int func_003F4DE8(void);
int func_003F5D88(void) { return func_003F4DE8(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5DA8);
#ifdef SKIP_ASM
extern char *strcpy(char *, const char *);
extern char* func_004162D0(char *, const char *);
extern int fBA68(char *, int, const char *) __asm__("func_0042BA68");
extern char D_00497038[], D_00497048[];
int func_003F5DA8(char *name, char *str) {
    char path[0x100];
    if (name == 0) {
        D_00525F80.fd[0] = -1;
        D_00525F80.fd[1] = -1;
        return 0;
    }
    if (str == 0) goto fail;
    strcpy(path, name);
    func_004162D0(path, D_00497038);
    D_00525F80.fd[0] = fBA68(path, 0, 0);
    if (D_00525F80.fd[0] < 0) goto fail;
    strcpy(path, name);
    func_004162D0(path, D_00497048);
    D_00525F80.fd[1] = fBA68(path, strlen(str) + 1, str); if (D_00525F80.fd[1] < 0) return -1; return 0;
fail:
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5E90);
#ifdef SKIP_ASM
extern int func_0042B438(int, int, int, int *);
extern int func_0042B640(int);
int func_003F5E90(int a, int b) {
    int buf[4];
    int r = 0;
    if (a >= 0) {
        if (func_0042B438(a, 0, 0, buf) < 0) r = b;
        if (func_0042B640(a) < 0) r = b;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5F08);
#ifdef SKIP_ASM
extern char D_00525F88[];
extern int sceUsbKbGetInfo(char *);
void func_003F5F08(void) {
    int i;
    char *p;
    for (i = 0; i < D_00525F80.cnt; i++) D_00525F80.prev[i] = D_00525F80.v[i];
    if (sceUsbKbGetInfo(D_00525F88) == 0) {
        p = D_00525F88 - 8;
        *(int *)(p + 0x9C) = 1;
        p[0xA0] = 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5F88);
#ifdef SKIP_ASM
extern int f810(int, int *) __asm__("func_0040C810");
int func_003F5F88(void) {
    int tmp;
    int r;
    int i;
    r = f810(1, &tmp);
    if (r != 0) return r;
    for (i = 0; i < D_00525F80.cnt; i++) {
        if (D_00525F80.prev[i] != D_00525F80.v[i]) D_00525F80.cb1(i, D_00525F80.v[i]);
    }
    D_00525F80.flag = 0;
    D_00525F80.st = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6040);
#ifdef SKIP_ASM
int func_003F6040(int i) {
    int c;
    for (c = 0; c < D_00525F80.cnt; c++) {
        if (i >= D_00525F80.cnt) i = 0;
        if (D_00525F80.v[i] != 0) {
            if (*(unsigned char *)(D_00525F80.ents + i * 0x8C + 0x88) == 0) return i;
        }
        i++;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F60B8);
#ifdef SKIP_ASM
extern int func_003F6040(int);
extern int sceUsbKbRead(int, int *);
void func_003F60B8(void) {
    int id = func_003F6040(D_00525F80.cur + 1);
    int *e;
    if (id != -1) {
        D_00525F80.cur = id;
        e = (int *)(D_00525F80.ents + id * 0x8C);
        D_00525F80.a = e[0];
        D_00525F80.b = e[1];
        if (sceUsbKbRead(id, e) == 0) {
            D_00525F80.st = 2;
            D_00525F80.flag = 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6138);
#ifdef SKIP_ASM
extern int f810(int, int *) __asm__("func_0040C810");
int func_003F6138(void) {
    int tmp;
    int r;
    r = f810(0, &tmp);
    if (r != 0) return r;
    {
        int *e = (int *)(D_00525F80.ents + D_00525F80.cur * 0x8C);
        if (e[2] > 0 || e[1] != D_00525F80.b || e[0] != D_00525F80.a) ((unsigned char *)e)[0x88] = 1;
    }
    D_00525F80.flag = 0;
    D_00525F80.st = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F61C8);
#ifdef SKIP_ASM
int func_003F61C8(void) { return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F61D0);
#ifdef SKIP_ASM
extern int D_00526010[];
extern int func_003F5DA8(char *, char *);
extern int f0C028(int *) __asm__("func_0040C028");
extern void f5F08(void) __asm__("func_003F5F08");
extern int f5F88(void) __asm__("func_003F5F88");
extern void f6358(int, int) __asm__("func_003F6358");
extern int f61C8(int) __asm__("func_003F61C8");
// The keyboard state block sits 0x90 bytes below the max-connect word passed to func_0040C028.
static inline struct sKb *ctl(void) { return (struct sKb *)((char *)D_00526010 - 0x90); }
int func_003F61D0(char *name, char *str, unsigned char *ents, void (*cb1)(int, int), int (*cb2)(int)) {
    int i;
    if (func_003F5DA8(name, str) < 0) return -1;
    if (f0C028(D_00526010) == -1) return -1;
    if (ctl()->cnt > 8) ctl()->cnt = 8;
    ctl()->ents = ents;
    for (i = 0; i < ctl()->cnt; i++) {
        ctl()->v[i] = 0;
        ctl()->prev[i] = 0;
        ents[i * 0x8C + 0x88] = 0;
    }
    D_00525F80.cur = 0;
    D_00525F80.period = 0x3C;
    D_00525F80.tick = 0x3C;
    D_00525F80.flag = 0;
    D_00525F80.cb1 = cb1 ? cb1 : f6358;
    D_00525F80.cb2 = cb2 ? cb2 : f61C8;
    f5F08();
    while (f5F88()) ;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F62F8);
#ifdef SKIP_ASM
extern int func_0040C220(void);
extern int func_003F5E90(int, int);
int func_003F62F8(void) {
    int r;
    func_0040C220();
    r = func_003F5E90(D_00525F80.fd[1], 1);
    return r | func_003F5E90(D_00525F80.fd[0], 2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6348);
#ifdef SKIP_ASM
extern int D_00526010[];
int func_003F6348(void) { return D_00526010[0]; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6358);
#ifdef SKIP_ASM
extern int sceUsbKbSetLEDStatus(int, int);
extern int sceUsbKbSetLEDMode(int, int);
extern void func_0040C810(int, int *);
extern void func_0040D4A0(int);
extern void func_0040C728(int, int, int);
extern void func_0040C770(int, int);
void func_003F6358(int h, int on) {
    int res;
    if (on) {
        res = sceUsbKbSetLEDStatus(h, 1);
        if (res == 0) func_0040C810(0, &res);
        res = sceUsbKbSetLEDMode(h, 1);
        if (res == 0) func_0040C810(0, &res);
        func_0040D4A0(h);
        func_0040C728(h, 0x1E, 2);
        func_0040C770(h, 0);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F63E0);
#ifdef SKIP_ASM
extern int D_00526038[];
void func_003F63E0(int a0) { D_00526038[0] = a0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F63F0);
#ifdef SKIP_ASM
extern int func_003F5F88(void);
extern int func_003F6138(void);
extern void func_003F5F08(void);
extern void func_003F60B8(void);
void func_003F63F0(void);
void func_003F63F0(void) {
    switch (D_00525F80.st) {
    case 1: func_003F5F88(); break;
    case 0: break;
    case 2: func_003F6138(); break;
    case 3: if (D_00525F80.cb2(1) != 0) D_00525F80.st = 0; break;
    }
    if (D_00525F80.st == 0) {
        if (D_00525F80.cb2(0) != 0) D_00525F80.st = 3;
        if (D_00525F80.st == 0) {
            D_00525F80.tick = D_00525F80.tick + 1;
            if (D_00525F80.period < D_00525F80.tick) { D_00525F80.tick = 0; func_003F5F08(); } else { func_003F60B8(); }
        }
    }
}

#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F64E0);
#ifdef SKIP_ASM
unsigned char *func_003F64E0(int n) {
    int off = n * 0x8C;
    if (D_00525F80.ents[off + 0x88] == 1) {
        D_00525F80.ents[off + 0x88] = 0;
        return D_00525F80.ents + off;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6520);
#ifdef SKIP_ASM
int func_003F6520(int a0) { return D_00525F80.v[a0] != 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6538);
#ifdef SKIP_ASM
extern void func_003F63F0(void);
extern int func_003F6520(int);
extern int func_003F6348(void);
int func_003F6538(void) {
    int i;
    func_003F63F0();
    for (i = 0; i < func_003F6348(); i++) {
        if (func_003F6520(i) == 1) return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F65A0);
#ifdef SKIP_ASM
extern short D_004513DC[], D_0045133A[], D_00451350[];
short *func_003F65A0(unsigned int c) {
    if (c - 0x2E < 8) return &D_004513DC[c];
    if (c - 0x87 >= 5) return &D_00451350[c];
    return &D_0045133A[c];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F65F8);
#ifdef SKIP_ASM
extern short D_00451420[], D_00451350[];
extern short *func_003F65A0(unsigned int);
void func_003F65F8(char *out, char *flags, int mode, int c) {
    unsigned char *p;
    unsigned int t;
    if ((*(int *)flags & 1) && (t = c - 0x59, t < 0xB)) {
        p = (unsigned char *)&D_00451420[t];
    } else if (mode == 0) {
        p = (unsigned char *)&D_00451350[c];
    } else {
        p = (unsigned char *)func_003F65A0(c);
    }
    *out = p[1];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6670);
#ifdef SKIP_ASM
extern unsigned char D_00451458[];
extern int f268(int, int, int, int) __asm__("func_0040D268");
void func_003F6670_impl(unsigned char *self, int *fl, int kb, unsigned code) __asm__("func_003F6670");
void func_003F6670_impl(unsigned char *self, int *fl, int kb, unsigned code) {
    unsigned t = code - 0x54;
    if (t < 0x10) {
        if (code < 0x59 || (fl[0] & 1)) self[1] = D_00451458[t];
        else self[1] = 0;
    } else {
        int r = f268(kb, fl[1], fl[0], code & 0xFFFF);
        if (r < 0x100) self[1] = r;
        else self[1] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6700);
#ifdef SKIP_ASM
int func_003F6700_impl(unsigned flags, unsigned key, unsigned *out) __asm__("func_003F6700");
int func_003F6700_impl(unsigned flags, unsigned key, unsigned *out) {
    int ok = 1;
    unsigned v = 0;
    switch (key) {
    case 0x5B: v = flags & 0x8; break;
    case 0xA3: v = flags & 0x10; break;
    case 0xA1: v = flags & 0x20; break;
    case 0xA0:
    case 0x10: v = flags & 0x2; break;
    case 0x12:
    case 0xA4: v = flags & 0x4; break;
    case 0x11: v = flags & 0x11; break;
    case 0x5C: v = flags & 0x80; break;
    case 0xA2: v = flags & 0x1; break;
    case 0xA5: v = flags & 0x40; break;
    default: ok = 0; break;
    }
    if (ok) *out = v;
    return ok;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F67E0);
#ifdef SKIP_ASM
int func_003F67E0(int a, unsigned int mode, int *out) {
    int r = 1;
    int v = 0;
    switch (mode) {
    case 0x90: v = a & 1; break;
    case 0x14: v = a & 2; break;
    case 0x91: v = a & 4; break;
    default: r = 0; break;
    }
    if (r) *out = v;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6838);
#ifdef SKIP_ASM
typedef struct { int a; int b; int pad; unsigned short t[1]; } S6838;
extern int f6700(int, int, int *) __asm__("func_003F6700");
extern int f67E0(int, int, int *) __asm__("func_003F67E0");
extern void f65F8(char *, S6838 *, int, int) __asm__("func_003F65F8");
int func_003F6838(S6838 *s, int b, int idx, int d) {
    int res = 0;
    char buf[8];
    int key = s->t[idx];
    if (f6700(s->b, d, &res) == 0) {
        if (f67E0(s->a, d, &res) == 0) {
            f65F8(buf, s, b, key);
            if ((unsigned char)buf[0] == d) res = 1;
        }
    }
    return res;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F68F0);
#ifdef SKIP_ASM
extern char D_004A5B10;
extern void func_003F65F8(char *, char *, int, int);
extern void func_003F6670(char *, char *, int, int);
char *func_003F68F0(char *a, int b, int c) {
    unsigned int v = *(unsigned short *)(a + (c << 1) + 12);
    func_003F65F8(&D_004A5B10, a, b, v);
    func_003F6670(&D_004A5B10, a, b, v);
    return &D_004A5B10;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6960);
#ifdef SKIP_ASM
typedef struct { int a; int b; } R6960;
extern R6960 D_526080s[] __asm__("D_00526080");
extern int f6F08(int *) __asm__("func_00426F08");
extern int f6D18(int *, int, int, R6960 *, int, int, int, int, int) __asm__("func_00426D18");
void func_003F6960_impl(int a, int b, int c, int d, int e) __asm__("func_003F6960");
void func_003F6960_impl(int a, int b, int c, int d, int e) {
    R6960 *r = D_526080s;
    if (D_004A5B14) {
        while (f6F08(D_00526100) > 0) ;
        r->a = b;
        r->b = c;
        do {
            if (f6D18(D_00526100, a, 0, D_526080s, 0x80, d, e, 0, 0) >= 0) break;
        } while (1);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6A40);
#ifdef SKIP_ASM
extern int *D_004A5B18;
extern int D_005261C0[], D_00526140[];
extern int func_00426B48(int *, int, int);
extern void func_003F6960b(int, int, int, int *, int) __asm__("func_003F6960");
void func_003F6A40(void) {
    int *p;
    D_004A5B14 = 1;
    func_00426B48(D_00526100, 0x237, 0);
    p = (int *)(((int)D_005261C0 & 0xFFFFFFF) | 0x20000000);
    D_004A5B18 = p;
    func_003F6960b(0, (int)p, 0, D_00526140, 0x80);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6AB0);
#ifdef SKIP_ASM
void func_003F6AB0(void) { D_004A5B14 = 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6AB8);
#ifdef SKIP_ASM
extern int D_00526140[];
extern int func_003F6960(int, int, int, int *, int);
int func_003F6AB8(int a, unsigned short b, int c) { return func_003F6960(2, a, b | (c << 16), D_00526140, 0x80); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6AF0);
#ifdef SKIP_ASM
extern int D_00526140[];
extern int func_003F6960(int, int, int, int *, int);
int func_003F6AF0(void) { return func_003F6960(3, 0, 0, D_00526140, 0x80); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6B20);
#ifdef SKIP_ASM
extern int D_00526140[];
extern int func_003F6960(int, int, int, int *, int);
void func_003F6B20() { func_003F6960(4, 0, 0, D_00526140, 0x80); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6B50);
#ifdef SKIP_ASM
extern int D_00526140[];
extern int func_003F6960(int, int, int, int *, int);
int func_003F6B50(void) { return func_003F6960(5, 0, 0, D_00526140, 0x80); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6B80);
#ifdef SKIP_ASM
extern int func_003F6C40(void);
int func_003F6B80(void) { return func_003F6C40() & 1; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6BA0);
#ifdef SKIP_ASM
extern int D_00526140[];
extern void func_003F6960b(int, int, int, int *, int) __asm__("func_003F6960");
void func_003F6BA0(int *a, int *b) {
    func_003F6960b(7, 0, 0, D_00526140, 0x80);
    *a = D_00526140[0];
    *b = D_00526140[1];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6C10);
#ifdef SKIP_ASM
extern int D_00526140[];
extern int func_003F6960(int, int, int, int *, int);
void func_003F6C10(int a, int b) { func_003F6960(6, a, b, D_00526140, 0x80); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6C40);
#ifdef SKIP_ASM
extern int *D_004A5B18;
int func_003F6C40(void) { return *D_004A5B18; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6C50);
#ifdef SKIP_ASM
extern char D_004A4BC0;
int func_003F6C50(void) { D_004A4BC0 = 1; return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6C60);
#ifdef SKIP_ASM
extern char D_004A4BC0;
int func_003F6C60(void) { D_004A4BC0 = 0; return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6C70);
#ifdef SKIP_ASM
extern struct sNetAcct *f6728(int, int, int) __asm__("func_00266728");
extern unsigned f6210x(struct sNetAcct *, int, int) __asm__("func_00416210");
int func_003F6C70_impl(int *arg) __asm__("func_003F6C70");
int func_003F6C70_impl(int *arg) {
    struct sNetAcct *d;
    struct sNetAcct *e;
    D_004A4BC4 = f6728(arg[1], 0x14C, 4);
    f6210x(D_004A4BC4, 0, 0x14C);
    d = D_004A4BC4;
    d->heap = arg[1];
    d->hdr = *(struct sNetHdr *)arg[0];
    e = D_004A4BC4;
    e->st = 4;
    e->f104 = 4;
    e->f148 = 0;
    e->f138 = 0;
    e->cur.mode = 0xA;
    e->cur.fEC = 5;
    e->f13C = -1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6D98);
#ifdef SKIP_ASM
extern int func_00266760(int, char *, int, int);
int func_003F6D98(void) {
    func_00266760(D_004A4BC4->heap, (char *)D_004A4BC4, 0x14C, 4);
    D_004A4BC4 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6DC8);
#ifdef SKIP_ASM
typedef struct { char b[0x1A]; } K6DC8;
extern K6DC8 D_00497060;
extern int fB800(void) __asm__("func_003FB800");
extern int fC0E8(void *) __asm__("func_003FC0E8");
extern int func_003F8178(int);
typedef struct { int a; int *p; struct sNetAcct *d; K6DC8 *buf; int len; int r; int v; } R6DC8;
int func_003F6DC8(void) {
    K6DC8 buf;
    R6DC8 req;
    struct sNetAcct *d = D_004A4BC4;
    buf = D_00497060;
    req.a = 2;
    req.p = &d->f138;
    req.d = d;
    req.len = 0x1A;
    req.buf = &buf;
    req.r = fB800();
    req.v = D_004A4BC4->heap;
    return func_003F8178(fC0E8(&req));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6E70);
#ifdef SKIP_ASM
extern int func_003FC260(void);
extern int func_003F8178(int);
int func_003F6E70(void) { return func_003F8178(func_003FC260()); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6E98);
#ifdef SKIP_ASM
extern int func_003F7990(int);
int func_003F6E98(int a) {
    int r = 0;
    if (D_004A4BC4->st == 4) {
        func_003F7990(a);
    } else {
        r = 0x16;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6EE0);
#ifdef SKIP_ASM
int func_003F6EE0(int *out) {
    int err = 0; struct sNetAcct *d;
    *out = 0;
    if (out == 0) err = 7;
    d = D_004A4BC4;
    if (d->st >= 4) err = 0xF;
    if (err == 0) {
        if (D_004A4BC4->cur.mode < 9) err = ((int (*)(int *, struct sNetAcct *))d->cur.fDC)(out, d);
        else ((void (*)(int *, int *))D_004A4BC4->cur.fE8)(out, &err);
    }
    return err;
}

#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F6F68);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F71B8);
#ifdef SKIP_ASM
extern int f7A60c(int, int) __asm__("func_003F7A60");
int func_003F71B8(int *a, int *b) {
    *a = 1;
    D_004A4BC4->f148 = *b;
    *b = 0;
    return f7A60c(7, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F71F8);
#ifdef SKIP_ASM
extern int func_003F7BD0(void);
int func_003F71F8(void) { return func_003F7BD0(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7218);
#ifdef SKIP_ASM
extern int f7A60c(int, int) __asm__("func_003F7A60");
int func_003F7218_impl(int *a, int *b) __asm__("func_003F7218");
int func_003F7218_impl(int *a, int *b) {
    int x; int err = 0xC;
    *a = 1;
    switch (D_004A4BC4->cur.mode) {
    case 0: x = 1; break;
    case 1: { unsigned sel = D_004A4BC4->st;
        if (sel >= 2) { if (sel != 2) goto fail; x = 4; } else x = 2; break; }
    case 2: x = 3; break;
    case 4: x = 5; break;
    case 3: case 5: x = 6; break;
    default: goto fail;
    }
    return f7A60c(x, 1);
fail:
    *b = err; *a = 0; return err;
}

#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F72C8);
#ifdef SKIP_ASM
extern int func_003F7BD0(void);
void func_003F72C8(int *a) { func_003F7BD0(); *a = 2; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F72F8);
#ifdef SKIP_ASM
extern int func_003F7BD0(void);
int func_003F72F8(int a, int *b) {
    *b = D_004A4BC4->f148;
    D_004A4BC4->f148 = 0;
    return func_003F7BD0();
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F7328);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F73A8);
#ifdef SKIP_ASM
extern char D_004A4BC8[];
extern int func_003F77F8(void);
extern int func_003FC390(char *, int, int);
extern int func_003F8178(int);
int func_003F73A8(void) {
    struct sNetAcct *p = D_004A4BC4;
    p->cur.fFC = func_003F77F8;
    p->cur.f100 = 0;
    return func_003F8178(func_003FC390(D_004A4BC8, -1, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F73F0);
#ifdef SKIP_ASM
extern char D_004A4BC8[];
extern int func_003F7820(void);
extern int func_003FC4C8(int, int, int);
extern int func_003F8178(int);
int func_003F73F0(void) {
    struct sNetAcct *p = D_004A4BC4;
    p->cur.fFC = func_003F7820;
    p->cur.f100 = 0;
    return func_003F8178(func_003FC4C8((int)D_004A4BC8, -1, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7438);
#ifdef SKIP_ASM
extern char D_004A4BC8[];
extern int func_003FC3C0(char *, int, int);
extern int func_003F8178(int);
int func_003F7438(void) {
    struct sNetAcct *p = D_004A4BC4;
    p->cur.fFC = 0;
    p->cur.f100 = 0;
    return func_003F8178(func_003FC3C0(D_004A4BC8, -1, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7478);
#ifdef SKIP_ASM
extern char fn7920[] __asm__("func_003F7920");
extern char fn78E0[] __asm__("func_003F78E0");
extern int func_003FCE10(char *, int, int, int);
extern int fC548(struct sMcParams *, int, int, int, int) __asm__("func_003FC548");
extern int func_003F8178(int);
typedef struct { char b[17]; } K17;
int func_003F7478(void) {
    int r;
    struct sNetAcct *d = D_004A4BC4;
    d->cur.fFC = fn78E0;
    d->cur.f100 = fn7920;
    r = func_003F8178(func_003FCE10((char *)&d->f144, d->heap, 0x11, 0));
    if (r == 0) {
        struct sNetAcct *e = D_004A4BC4;
        K17 *dst = (K17 *)e->f144;
        *dst = *(K17 *)e->name;
        r = func_003F8178(fC548(&D_004A4BC4->params, 0x41434354, 0, (int)D_004A4BC4->f144, 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7528);
#ifdef SKIP_ASM
extern char fn7958[] __asm__("func_003F7958");
extern char fn7900[] __asm__("func_003F7900");
extern int func_003FCE10(char *, int, int, int);
extern int fC548(struct sMcParams *, int, int, int, int) __asm__("func_003FC548");
extern int func_003F8178(int);
typedef struct { char b[17]; } K17b;
int func_003F7528(void) {
    int r;
    struct sNetAcct *d = D_004A4BC4;
    d->cur.fFC = fn7900;
    d->cur.f100 = fn7958;
    r = func_003F8178(func_003FCE10((char *)&d->f144, d->heap, 0x11, 0));
    if (r == 0) {
        struct sNetAcct *e = D_004A4BC4;
        K17b *dst = (K17b *)e->f144;
        *dst = *(K17b *)e->pass;
        r = func_003F8178(fC548(&D_004A4BC4->params, 0x50415353, 0, (int)D_004A4BC4->f144, 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F75D8);
#ifdef SKIP_ASM
extern char fn7920[] __asm__("func_003F7920");
extern char fn7840[] __asm__("func_003F7840");
extern int func_003FCE10(char *, int, int, int);
extern int func_003FC708(struct sMcParams *, int, int, int, int);
extern int func_003F8178(int);
int func_003F75D8(void) {
    int r;
    struct sNetAcct *d = D_004A4BC4;
    d->cur.fFC = fn7840;
    d->cur.f100 = fn7920;
    r = func_003F8178(func_003FCE10((char *)&d->f144, d->heap, 0x11, 0));
    if (r == 0) {
        struct sNetAcct *e = D_004A4BC4;
        r = func_003F8178(func_003FC708(&e->params, 0x41434354, 0, (int)e->f144, 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7658);
#ifdef SKIP_ASM
extern char fn7958[] __asm__("func_003F7958");
extern char fn7890[] __asm__("func_003F7890");
extern int func_003FCE10(char *, int, int, int);
extern int func_003FC708(struct sMcParams *, int, int, int, int);
extern int func_003F8178(int);
int func_003F7658(void) {
    int r;
    struct sNetAcct *d = D_004A4BC4;
    d->cur.fFC = fn7890;
    d->cur.f100 = fn7958;
    r = func_003F8178(func_003FCE10((char *)&d->f144, d->heap, 0x11, 0));
    if (r == 0) {
        struct sNetAcct *e = D_004A4BC4;
        r = func_003F8178(func_003FC708(&e->params, 0x50415353, 0, (int)e->f144, 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F76D8);
#ifdef SKIP_ASM
extern int func_003FC4E8(char *);
extern int func_003F8178(int);
int func_003F76D8(void) {
    struct sNetAcct *p = D_004A4BC4;
    p->cur.fFC = 0;
    p->cur.f100 = 0;
    return func_003F8178(func_003FC4E8((char *)&p->params));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7708);
#ifdef SKIP_ASM
extern int func_003FCA40(int *, int *);
extern int func_003F8178(int);
int func_003F7708(int *out) {
    int st[2];
    int err;
    unsigned s;
    st[0] = 0;
    err = out ? 0 : 7;
    if (err == 0)
        err = func_003F8178(func_003FCA40(st, st + 1));
    if (err == 0) {
        s = st[0];
        *out = 0;
        switch (s) {
        case 0:
            err = 0x17;
            break;
        case 2:
            if (D_004A4BC4->cur.fFC) {
                err = ((int (*)(void))D_004A4BC4->cur.fFC)();
                D_004A4BC4->cur.fFC = 0;
            }
            if (err != 0)
                break;
        case 1:
            *out = s;
            break;
        default:
            err = 0x12;
            break;
        }
    } else {
        if (D_004A4BC4->cur.f100) {
            err = ((int (*)(void))D_004A4BC4->cur.f100)();
            D_004A4BC4->cur.f100 = 0;
        }
    }
    return err;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F77F0);
#ifdef SKIP_ASM
int func_003F77F0(void) { return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F77F8);
#ifdef SKIP_ASM
extern int func_003FC990(struct sMcParams *);
extern int func_003F8178(int);
int func_003F77F8(void) { return func_003F8178(func_003FC990(&D_004A4BC4->params)); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7820);
#ifdef SKIP_ASM
extern int func_003F77F8(void);
int func_003F7820(void) { return func_003F77F8(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7840);
#ifdef SKIP_ASM
typedef struct { char c[17]; } S17b;
extern int func_003F7920(int);
void func_003F7840(void) {
    S17b *dst = (S17b *)D_004A4BC4->out;
    *dst = *(S17b *)D_004A4BC4->f144;
    func_003F7920(0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7890);
#ifdef SKIP_ASM
extern int func_003F7958(int);
typedef struct { char c[17]; } S17;
void func_003F7890(void) {
    S17 *dst = (S17 *)(D_004A4BC4->out + 0x11);
    *dst = *(S17 *)D_004A4BC4->f144;
    func_003F7958(0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F78E0);
#ifdef SKIP_ASM
extern int func_003F7920(int);
int func_003F78E0(void) { return func_003F7920(0); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7900);
#ifdef SKIP_ASM
extern int func_003F7958(int);
int func_003F7900(void) { return func_003F7958(0); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7920);
#ifdef SKIP_ASM
extern int func_003FCF00(int, int, int, int);
extern int func_003F8178(int);
int func_003F7920(int unused) { return func_003F8178(func_003FCF00((int)D_004A4BC4->f144, D_004A4BC4->heap, 0x11, 0)); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7958);
#ifdef SKIP_ASM
extern int func_003FCF00(int, int, int, int);
extern int func_003F8178(int);
int func_003F7958(int unused) { return func_003F8178(func_003FCF00((int)D_004A4BC4->f144, D_004A4BC4->heap, 0x11, 0)); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7990);
#ifdef SKIP_ASM
extern char fn6EE0[] __asm__("func_003F6EE0");
extern char fn7328[] __asm__("func_003F7328");
int f7990(unsigned a) __asm__("func_003F7990");
int f7990(unsigned a) {
    int r = 0;
    unsigned i;
    D_004A4BC4->st = a;
    D_004A4BC4->f104 = a;
    if (a < 4) {
        D_004A4BC4->fD4 = fn6EE0;
    } else {
        r = 0xF;
    }
    D_004A4BC4->cur.mode = 9;
    D_004A4BC4->cur.fEC = 4;
    D_004A4BC4->cur.fE8 = fn7328;
    D_004A4BC4->cur.fE0 = 0;
    D_004A4BC4->cur.fE4 = 0;
    D_004A4BC4->cur.fDC = 0;
    for (i = 0; i < 3; i++)
        ;
    D_004A4BC4->cur.fF0 = 0;
    D_004A4BC4->cur.fF4 = 0;
    D_004A4BC4->cur.fF8 = 0;
    D_004A4BC4->cur.fFC = 0;
    D_004A4BC4->cur.f100 = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7A30);
#ifdef SKIP_ASM
extern int func_003F7BD0(void);
int func_003F7A30(void) {
    struct sNetAcct *p = D_004A4BC4;
    p->st = 4;
    p->fD4 = 0;
    p->cur.fE8 = 0;
    return func_003F7BD0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7A60);
#ifdef SKIP_ASM
extern int func_003F6F68();
extern int func_003F7218();
extern int func_003F7C00(void);
int func_003F7A60(int mode, unsigned char copy) {
    int err = 0;
    D_004A4BC4->cur.mode = mode;
    if (copy)
        D_004A4BC4->saved = D_004A4BC4->cur;
    if (D_004A4BC4->cur.mode < 9)
        D_004A4BC4->cur.fDC = (void *)func_003F6F68;
    else
        err = 0xD;
    if (err == 0) {
        switch (D_004A4BC4->cur.mode) {
        case 0: case 1: case 2: case 3: case 4: case 5:
            D_004A4BC4->cur.fE0 = (void *)func_003F7218;
            break;
        case 6: case 8:
            D_004A4BC4->cur.fE0 = (void *)func_003F72C8;
            break;
        case 7:
            D_004A4BC4->cur.fE0 = (void *)func_003F72F8;
            break;
        default:
            err = 0xD;
            break;
        }
    }
    if (err == 0) {
        switch (D_004A4BC4->cur.mode) {
        case 0: case 1: case 2: case 3: case 4: case 5:
            D_004A4BC4->cur.fE4 = (void *)func_003F71B8;
            break;
        case 6: case 8:
            D_004A4BC4->cur.fE4 = (void *)func_003F71F8;
            break;
        case 7:
            D_004A4BC4->cur.fE4 = (void *)func_003F72F8;
            break;
        }
    }
    return func_003F7C00();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7BD0);
#ifdef SKIP_ASM
extern int func_003F7D98(void);
int func_003F7BD0(void) {
    struct sNetAcct *p = D_004A4BC4;
    p->cur.mode = 10;
    p->cur.fDC = 0;
    p->cur.fE0 = 0;
    p->cur.fE4 = 0;
    return func_003F7D98();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7C00);
#ifdef SKIP_ASM
typedef struct { unsigned char b[0x18]; } B7C00;
int func_003F7C00(void) {
    int r;
    unsigned i;
    i = r = 0;
    D_004A4BC4->cur.fEC = 4;
    *(B7C00 *)&D_004A4BC4->saved.fEC = *(B7C00 *)&D_004A4BC4->cur.fEC;
    for (i = 0; i < 3; i++) ;
    switch (D_004A4BC4->cur.mode) {
    case 0: D_004A4BC4->cur.fF0 = (void *)func_003F73A8; break;
    case 1: D_004A4BC4->cur.fF0 = (void *)func_003F73F0; break;
    case 2: D_004A4BC4->cur.fF0 = (void *)func_003F7478; break;
    case 3: D_004A4BC4->cur.fF0 = (void *)func_003F7528; break;
    case 4: D_004A4BC4->cur.fF0 = (void *)func_003F75D8; break;
    case 5: D_004A4BC4->cur.fF0 = (void *)func_003F7658; break;
    case 6:
    case 7: D_004A4BC4->cur.fF0 = (void *)func_003F76D8; break;
    case 8: D_004A4BC4->cur.fF0 = (void *)func_003F7438; break;
    default: r = 0xD;
    }
    if (r == 0) {
        if (D_004A4BC4->cur.mode < 9) D_004A4BC4->cur.fF4 = (void *)func_003F7708;
        else r = 0xD;
        if (r == 0) {
            if (D_004A4BC4->cur.mode < 9) D_004A4BC4->cur.fF8 = (void *)func_003F77F0;
            else r = 0xD;
        }
    }
    D_004A4BC4->cur.fFC = 0;
    D_004A4BC4->cur.f100 = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7D98);
#ifdef SKIP_ASM
int func_003F7D98(void) {
    unsigned int i;
    int *p;
    struct sNetAcct *g = D_004A4BC4;
    struct sNetAcct *h;
    g->cur.fEC = 5;
    p = (int *)&g->cur.fF0;
    for (i = 0; i < 3; i++) {
        *p++ = 0;
    }
    h = D_004A4BC4;
    h->cur.fFC = 0;
    h->cur.f100 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7DE0);
#ifdef SKIP_ASM
typedef struct { int **p; } W7DE0;
typedef struct { char pad[0xC]; int (*f0)(void); int (*f1)(int, int); int (*f2)(W7DE0 **); } V7DE0;
extern V7DE0 *fB5E8(void) __asm__("func_003FB5E8");
int func_003F7DE0(int a) {
    int err = 0;
    V7DE0 *o = fB5E8();
    int r;
    W7DE0 *w;
    r = o->f0();
    if (r == 0) {
        r = o->f1(a, 0x296E);
        if (r == 0) {
            r = o->f2(&w);
            if (r == 0) {
                err = 0x15;
                if (**(unsigned **)((char *)w + 4) == 0x836C71D) err = 0;
            }
        }
    }
    if (r != 0) return 0x18;
    return err;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7E90);
#ifdef SKIP_ASM
char *func_003F7E90(char *dst, char *src, int n) {
    char *d;
    unsigned char *s = (unsigned char*)src;
    if (s && dst && n && s != (unsigned char*)dst) {
        d = dst;
        do {
            if (--n == 0) { *d = 0; break; }
        } while ((*d++ = *s++) != 0);
    }
    return dst;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7EE0);
#ifdef SKIP_ASM
extern int func_003F6C50(void);
extern int func_003F6C70(int);
extern int func_003F6DC8(void);
void func_003F7EE0(int a) {
    func_003F6C50();
    func_003F6C70(a);
    func_003F6DC8();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7F18);
#ifdef SKIP_ASM
extern int func_003F6E70(void);
extern int func_003F6D98(void);
extern int func_003F6C60(void);
int func_003F7F18(void) {
    func_003F6E70();
    func_003F6D98();
    return func_003F6C60();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7F48);
#ifdef SKIP_ASM
extern char* f7E90(char *, int, int) __asm__("func_003F7E90");
extern int func_003F7DE0(int);
extern int f8258(int) __asm__("func_003F8258");
int func_003F7F48(int a, int b) {
    int err = 0;
    if (a == 0 && b == 0) {
        err = 7;
    } else {
        f7E90(D_004A4BC4->name, b, 0x11);
        f7E90(D_004A4BC4->pass, b + 0x11, 0x11);
    }
    if (err == 0) {
        err = func_003F7DE0(a);
        if (err == 0) {
            err = f8258(a);
            if (err == 0) err = func_003F6E98(0);
        }
    }
    return err;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8000);
#ifdef SKIP_ASM
extern int func_003F6E98(int);
int func_003F8000(char *a) {
    int r = 0;
    if (a == 0) {
        r = 7;
    } else {
        D_004A4BC4->out = a;
    }
    if (r == 0) {
        r = func_003F6E98(2);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8048);
#ifdef SKIP_ASM
extern char *func_003F7E90(char *, char *, int);
extern int func_003F6E98(int);
int func_003F8048(char *name) {
    int r = 0;
    if (name == 0) {
        r = 7;
    } else {
        func_003F7E90(D_004A4BC4->name, name, 0x11);
        func_003F7E90(D_004A4BC4->pass, name + 0x11, 0x11);
    }
    if (r == 0) r = func_003F6E98(1);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F80C0);
#ifdef SKIP_ASM
extern int func_003F6E98(int);
int func_003F80C0(void) { return func_003F6E98(3); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F80E0);
#ifdef SKIP_ASM
extern int func_003F7A30(void);
int func_003F80E0(int *out) {
    int err = 0;
    int v;
    if (out == 0) {
        err = 7;
    } else {
        *out = 0;
        if (D_004A4BC4->st != 4) {
            err = ((int (*)(int *))D_004A4BC4->fD4)(out);
            if (err == 0) {
                v = *out;
                if (v == 2) {
                    func_003F7A30();
                    *out = v;
                }
            } else {
                func_003F7A30();
            }
        }
    }
    return err;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8178);
#ifdef SKIP_ASM
int func_003F8178(int a);
int func_003F8178(int a) {
    switch (a) {
    case 0: return 0;
    case 104: return 1;
    case 103: return 2;
    case 114: return 3;
    case 108: return 4;
    case 3:
    case 7:
    case 110: return 5;
    case 9: return 6;
    case 1: return 0x13;
    case 2: return 0x14;
    case 4: return 7;
    case 6:
    case 107: return 0xB;
    }
    return 0x18;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8200);
#ifdef SKIP_ASM
int func_003F8200(int *a0) { *a0 = D_004A4BC4->f104; return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8218);
#ifdef SKIP_ASM
int func_003F8218(int *a0) { *a0 = D_004A4BC4->saved.mode; return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8230);
#ifdef SKIP_ASM
extern int func_003FCF98(int, int);
int func_003F8230(int a) { func_003FCF98(0x22, a); return 0; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F8258);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8550);
#ifdef SKIP_ASM
int func_003F8550(unsigned v) {
    int i = 0;
    v &= 0xFFFF;
    if (!(v & 1)) {
        do {
            i++;
        } while (i < 8 && !(v & (1 << i)));
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8588);
#ifdef SKIP_ASM
int func_003F8588(unsigned v) {
    int i = 7;
    v &= 0xFFFF;
    if (!(v & 0x80)) {
        do {
            i--;
        } while (i >= 0 && !(v & (1 << i)));
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F85C0);
#ifdef SKIP_ASM
int func_003F85C0(unsigned short v, int dir) {
    short i = D_004A4BD8->body.slot;
    int r;
    if (dir == 0) {
        i++;
        while (i < 8 && !((v >> i) & 1)) i++;
        if (i >= 8) r = -1; else r = i;
    } else if (dir == 1) {
        i--;
        while (i >= 0 && !((v >> i) & 1)) i--;
        if (i < 0) r = -1; else r = i;
    } else {
        return 0x12;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F86B8);
#ifdef SKIP_ASM
int func_003F86B8(unsigned short v) {
    int r = 0; int i = 0;
    for (i = 0; i < 8; i++) { int bit = 1 << i; if (v & bit) r++; }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F86F0);
#ifdef SKIP_ASM
void func_003F86F0_impl(int a) __asm__("func_003F86F0");
void func_003F86F0_impl(int a) {
    struct sMcReq *p = D_004A4BD8;
    if ((unsigned)(p->op - 11) >= 3) p->f08 = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8710);
#ifdef SKIP_ASM
int func_003F8710(void) { return D_004A4BD8->f08; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8720);
#ifdef SKIP_ASM
int func_003F8720(int a, int *out) {
    struct sMcReq *d;
    struct sMcDrv *e;
    *out = 1;
    d = D_004A4BD8;
    e = D_004A4BDC;
    d->op = 0xB;
    d->st = 0x18;
    e->f38(d->body.port);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8768);
#ifdef SKIP_ASM
int func_003F8768(int a, int *out) {
    struct sMcReq *d;
    struct sMcDrv *e;
    *out = 1;
    d = D_004A4BD8;
    e = D_004A4BDC;
    d->op = 0xC;
    d->st = 0x19;
    e->f1C(d->body.port);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F87B0);
#ifdef SKIP_ASM
int func_003F87B0(int a, int *out) {
    struct sMcReq *d;
    struct sMcDrv *e;
    *out = 1;
    d = D_004A4BD8;
    e = D_004A4BDC;
    d->op = 0xD;
    d->st = 0x1A;
    e->f14(a);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F87F8);
#ifdef SKIP_ASM
int func_003F87F8(int a0) { return a0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8800);
#ifdef SKIP_ASM
int func_003F8800(int a) {
    if (D_004A4BD8->st != 1) return 0x12;
    if (a != 0 && a != 3 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8838);
#ifdef SKIP_ASM
int func_003F8838(int a) {
    if (D_004A4BD8->st != 2) return 0x12;
    if (a != 0 && a != 4 && a != 3 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8880);
#ifdef SKIP_ASM
int func_003F8880(int a) {
    int m = D_004A4BD8->st;
    if (m != 0x1B && m != 0x1D && m != 0x1C && m != 7 && m != 0xB && m != 0x18) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xE && a != 0xD && a != 0x11 && a != 0xA) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8908);
#ifdef SKIP_ASM
int func_003F8908(int a) {
    int m = D_004A4BD8->st;
    if (m != 0x18 && m != 8 && m != 0xC && m != 0x10) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8968);
#ifdef SKIP_ASM
int func_003F8968(int a) {
    int m = D_004A4BD8->st;
    if (m != 0x19 && m != 9 && m != 0xD && m != 0x11) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F89C8);
#ifdef SKIP_ASM
int func_003F89C8(int a) {
    if (D_004A4BD8->st != 0x1A) return 0x12;
    if (a != 0 && a != 3 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8A08);
#ifdef SKIP_ASM
int func_003F8A08(int a) {
    if (D_004A4BD8->st != 5) return 0x12;
    if (a != 0 && a != 3 && a != 9 && a != 0xE && a != 8 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8A58);
#ifdef SKIP_ASM
int func_003F8A58(int a) {
    int m = D_004A4BD8->st;
    if (m != 0x16 && m != 6 && m != 0xE && m != 0xA) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xD && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8AC0);
#ifdef SKIP_ASM
int func_003F8AC0(int a) {
    if ((unsigned)(D_004A4BD8->st - 0x13) >= 3) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xD && a != 6 && a != 5 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8B28);
#ifdef SKIP_ASM
int func_003F8B28(int a) {
    if (D_004A4BD8->st != 0x12) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xD && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8B78);
#ifdef SKIP_ASM
int func_003F8B78(int a) {
    int m = D_004A4BD8->st;
    if (m != 3) return 0x12;
    if (a != 0 && a != m && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8BB0);
#ifdef SKIP_ASM
int func_003F8BB0(int a) {
    if (D_004A4BD8->st != 4) return 0x12;
    if (a != 0 && a != 3 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8BE8);
#ifdef SKIP_ASM
int func_003F8BE8(int a) {
    if (D_004A4BD8->st != 0x17) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8C30);
#ifdef SKIP_ASM
int func_003F8C30(int a0) { return a0; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F8C38);

INCLUDE_ASM("seg/seg_2F41F8", func_003F8EF8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F8FF0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9130);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9208);
#ifdef SKIP_ASM
int func_003F9208(void) { return D_004A4BDC != 0; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F9218);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9530);
#ifdef SKIP_ASM
extern int func_003F9208(void);
extern int func_00266760(int, char *, int, int);
int func_003F9530(void) {
    struct sMcDrv *e;
    struct sMcReq *s;
    if (func_003F9208() == 0) return 2;
    e = D_004A4BDC;
    s = D_004A4BD8;
    if (e == 0 || s == 0) return 2;
    e->f04 = 0;
    e->f08 = 0;
    e->f0C = 0;
    e->f10 = 0;
    e->f14 = 0;
    e->f18 = 0;
    e->f1C = 0;
    e->f20 = 0;
    e->f24 = 0;
    e->f28 = 0;
    e->f2C = 0;
    e->f30 = 0;
    e->f34 = 0;
    e->f38 = 0;
    e->f3C = 0;
    e->f40 = 0;
    e->f44 = 0;
    s->op = 0;
    s->st = 0;
    func_00266760(e->h, (char *)s, 0x74, 4);
    D_004A4BD8 = 0;
    func_00266760(D_004A4BDC->h, (char *)D_004A4BDC, 0x42C, 4);
    D_004A4BDC = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F95E8);
#ifdef SKIP_ASM
int func_003F95E8(char *dst) {
    if (dst == 0) return 0xC;
    __builtin_memcpy(dst, &D_004A4BD8->body, 0x60);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9698);
#ifdef SKIP_ASM
extern int c9698_86B8(int) __asm__("func_003F86B8");
extern int c9698_8550(int) __asm__("func_003F8550");
extern int c9698_8588(int) __asm__("func_003F8588");
extern void c9698_86F0(int) __asm__("func_003F86F0");
extern void c9698_B2F8(int) __asm__("func_003FB2F8");
extern unsigned c9698_6210(void *, int, int) __asm__("func_00416210");
extern char *strcpy(char *, const char *);
int func_003F9698(char *str, int a, int b);
int func_003F9698(char *str, int a, int b) {
    int v;
    int t;
    struct sMcReq *s;
    struct sMcReq *s2;
    unsigned m;
    if (func_003F9208() == 0) return 2;
    if (str == 0) return 0xC;
    if ((unsigned)(a + 1) >= 9) return 9;
    if (a != -1) {
        m = 1 << a;
        if (!(D_004A4BDC->ports & m)) return 0xB;
    }
    if (D_004A4BD8->op != 0) return 0xD;
    c9698_6210(&D_004A4BD8->body, 0, 0x60);
    if (a == -1) {
        if (c9698_86B8(D_004A4BDC->ports) == 1) {
            v = c9698_8550(D_004A4BDC->ports);
            s = D_004A4BD8;
            s->body.slot = v;
            s->op = 5;
        } else if (b == 0) {
            v = c9698_8550(D_004A4BDC->ports);
            s = D_004A4BD8;
            s->body.slot = v;
            s->op = 2;
        } else if (b == 1) {
            v = c9698_8588(D_004A4BDC->ports);
            s = D_004A4BD8;
            s->body.slot = v;
            s->op = 2;
        } else {
            return 0xC;
        }
    } else {
        s2 = D_004A4BD8;
        s2->body.slot = a;
        s2->op = 5;
    }
    c9698_86F0(0);
    strcpy(D_004A4BD8->body.name, str);
    D_004A4BD8->f6C = b;
    c9698_B2F8(1);
    D_004A4BDC->f10(D_004A4BD8->body.slot);
    D_004A4BD8->st = 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9818);
#ifdef SKIP_ASM
extern int c9818_86B8(int) __asm__("func_003F86B8");
extern int c9818_8550(int) __asm__("func_003F8550");
extern int c9818_8588(int) __asm__("func_003F8588");
extern void c9818_86F0(int) __asm__("func_003F86F0");
extern void c9818_B2F8(int) __asm__("func_003FB2F8");
extern unsigned c9818_6210(void *, int, int) __asm__("func_00416210");
extern char *strcpy(char *, const char *);
int func_003F9818(char *str, int a, int b);
int func_003F9818(char *str, int a, int b) {
    int v;
    int t;
    struct sMcReq *s;
    struct sMcReq *s2;
    unsigned m;
    if (func_003F9208() == 0) return 2;
    if (str == 0) return 0xC;
    if (strlen(str) >= 0x18) return 0xC;
    if ((unsigned)(a + 1) >= 9) return 9;
    if (a != -1) {
        m = 1 << a;
        if (!(D_004A4BDC->ports & m)) return 0xB;
    }
    if (D_004A4BD8->op != 0) return 0xD;
    c9818_6210(&D_004A4BD8->body, 0, 0x60);
    if (a == -1) {
        if (c9818_86B8(D_004A4BDC->ports) == 1) {
            v = c9818_8550(D_004A4BDC->ports);
            s = D_004A4BD8;
            s->body.slot = v;
            s->op = 4;
        } else if (b == 0) {
            v = c9818_8550(D_004A4BDC->ports);
            s2 = D_004A4BD8;
            s2->body.slot = v;
            s2->op = 1;
        } else if (b == 1) {
            v = c9818_8588(D_004A4BDC->ports);
            s2 = D_004A4BD8;
            s2->body.slot = v;
            s2->op = b;
        } else {
            return 0xC;
        }
    } else {
        s2 = D_004A4BD8;
        s2->body.slot = a;
        s2->op = 4;
    }
    c9818_86F0(0);
    strcpy(D_004A4BD8->body.name, str);
    D_004A4BD8->f6C = b;
    c9818_B2F8(1);
    D_004A4BDC->f10(D_004A4BD8->body.slot);
    D_004A4BD8->st = 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F99B8);
#ifdef SKIP_ASM
extern int c99b8_86B8(int) __asm__("func_003F86B8");
extern int c99b8_8550(int) __asm__("func_003F8550");
extern int c99b8_8588(int) __asm__("func_003F8588");
extern void c99b8_86F0(int) __asm__("func_003F86F0");
extern void c99b8_B2F8(int) __asm__("func_003FB2F8");
extern unsigned c99b8_6210(void *, int, int) __asm__("func_00416210");
extern char *strcpy(char *, const char *);
int func_003F99B8_impl(char *str, int a, int b) __asm__("func_003F99B8");
int func_003F99B8_impl(char *str, int a, int b) {
    int v;
    int t;
    struct sMcReq *s;
    struct sMcReq *s2;
    unsigned m;
    if (func_003F9208() == 0) return 2;
    if (str == 0) return 0xC;
    if ((unsigned)(a + 1) >= 9) return 9;
    if (a != -1) {
        m = 1 << a;
        if (!(D_004A4BDC->ports & m)) return 0xB;
    }
    if (D_004A4BD8->op != 0) return 0xD;
    c99b8_6210(&D_004A4BD8->body, 0, 0x60);
    if (a == -1) {
        if (c99b8_86B8(D_004A4BDC->ports) == 1) {
            v = c99b8_8550(D_004A4BDC->ports);
            s = D_004A4BD8;
            s->body.slot = v;
            s->op = 6;
        } else if (b == 0) {
            v = c99b8_8550(D_004A4BDC->ports);
            s = D_004A4BD8;
            s->body.slot = v;
            s->op = 3;
        } else if (b == 1) {
            v = c99b8_8588(D_004A4BDC->ports);
            s = D_004A4BD8;
            s->body.slot = v;
            s->op = 3;
        } else {
            return 0xC;
        }
    } else {
        s2 = D_004A4BD8;
        s2->body.slot = a;
        s2->op = 6;
    }
    c99b8_86F0(0);
    strcpy(D_004A4BD8->body.name, str);
    D_004A4BD8->f6C = b;
    c99b8_B2F8(1);
    D_004A4BDC->f10(D_004A4BD8->body.slot);
    D_004A4BD8->st = 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9B38);
#ifdef SKIP_ASM
extern int f9208(void) __asm__("func_003F9208");
int func_003F9B38_impl(int *src) __asm__("func_003F9B38");
int func_003F9B38_impl(int *src) {
    if (f9208() == 0) return 2;
    if (src == 0) return 0xC;
    if (D_004A4BD8->op != 0) return 0xD;
    __builtin_memcpy(&D_004A4BD8->body, src, 0x60);
    D_004A4BD8->op = 7;
    D_004A4BD8->st = 0x18;
    D_004A4BDC->f38(src[0]);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9C48);
#ifdef SKIP_ASM
extern void c9c48_86F0(int) __asm__("func_003F86F0");
extern int func_003FA6E8(void);
int func_003F9C48_impl(int *src, int a, int b) __asm__("func_003F9C48");
int func_003F9C48_impl(int *src, int a, int b) {
    struct sMcReq *s;
    struct sMcReq *t;
    int v;
    struct sMcDrv *e;
    if (func_003F9208() == 0) return 2;
    if (src == 0) return 0xC;
    s = D_004A4BD8;
    if (s->op != 0) return 0xD;
    s->op = 8;
    s->st = 0x1B;
    c9c48_86F0(0);
    __builtin_memcpy(&D_004A4BD8->body, (char *)src, 0x60);
    if (b == 0) {
        v = a + func_003FA6E8();
        t = D_004A4BD8;
        e = D_004A4BDC;
        t->f70 = v;
        e->f34(t->body.port, a + func_003FA6E8(), 0);
    } else {
        struct sMcReq *d = D_004A4BD8;
        struct sMcDrv *e2 = D_004A4BDC;
        d->f70 = a;
        e2->f34(d->body.port, a, b);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9DC0);
#ifdef SKIP_ASM
extern void f86F0(int) __asm__("func_003F86F0");
int func_003F9DC0_impl(int *src, int a, int b) __asm__("func_003F9DC0");
int func_003F9DC0_impl(int *src, int a, int b) {
    struct sMcReq *s;
    struct sMcReq *t;
    struct sMcDrv *e;
    if (func_003F9208() == 0) return 2;
    if (src == 0) return 0xC;
    s = D_004A4BD8;
    if (s->op != 0) return 0xD;
    s->op = 0xA;
    s->st = 0x1D;
    f86F0(0);
    __builtin_memcpy(&D_004A4BD8->body, (char *)src, 0x60);
    t = D_004A4BD8;
    e = D_004A4BDC;
    t->f70 = b;
    e->f2C(src[0], a, b);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9F00);
#ifdef SKIP_ASM
extern int func_003F9208(void);
extern void f86F0(int) __asm__("func_003F86F0");
int func_003F9F00_impl(int *src, int a, int b) __asm__("func_003F9F00");
int func_003F9F00_impl(int *src, int a, int b) {
    struct sMcReq *s;
    struct sMcReq *t;
    struct sMcDrv *e;
    if (func_003F9208() == 0) return 2;
    if (src == 0) return 0xC;
    s = D_004A4BD8;
    if (s->op != 0) return 0xD;
    s->op = 9;
    s->st = 0x1C;
    f86F0(0);
    __builtin_memcpy(&D_004A4BD8->body, (char *)src, 0x60);
    t = D_004A4BD8;
    e = D_004A4BDC;
    t->f70 = b;
    e->f30(src[0], a, b);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA040);
#ifdef SKIP_ASM
extern void fB2F8w(int) __asm__("func_003FB2F8");
int func_003FA040(int *p, int *q) {
    int r;
    if (func_003F9208() == 0) return 2;
    if (D_004A4BDC->f40 == 0) return 0xD;
    if (p == 0) return 0xC;
    if (q == 0) return 0xC;
    r = D_004A4BDC->f40(p, q);
    if (p[0] == 0) {
        if (D_004A4BD8->op != 0) return 0xF;
    }
    if (p[0] != 2) return r;
    r = D_004A4BDC->f4C[D_004A4BD8->st](r, 2, q[0]);
    if (r == 10) {
        struct sMcReq *g = D_004A4BD8;
        g->op = 0;
        g->st = 0;
        return 10;
    }
    if (r == 0x10) return 0x10;
    r = D_004A4BDC->f48[D_004A4BD8->op](r, p, q);
    if (p[0] == 2) {
        int s = D_004A4BD8->op;
        struct sMcReq *g;
        if (s == 5 || s == 2 || s == 7 || s == 0xB || s == 0xC || s == 0xD) fB2F8w(0);
        g = D_004A4BD8;
        g->op = 0;
        g->st = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA1D0);
#ifdef SKIP_ASM
extern int func_003F9208(void);
extern int func_003FA708(unsigned int, int);
int func_003FA1D0(unsigned int a, int b) {
    if (b == 0) return 12;
    if (func_003F9208() == 0) return 2;
    if (a >= 8) return 9;
    func_003FA708(a, b);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA240);
#ifdef SKIP_ASM
extern int func_003F9208(void);
extern void fA6A8(char *, int *, int *) __asm__("func_003FA6A8");
extern int fB308(char *) __asm__("func_003FB308");
int func_003FA240_impl(char *src) __asm__("func_003FA240");
int func_003FA240_impl(char *src) {
    if (src == 0) return 0xC;
    if (func_003F9208() == 0) return 2;
    __builtin_memcpy(D_004A4BDC->f50, src, 0x3D0);
    fA6A8(src, &D_004A4BDC->f420, &D_004A4BDC->f424);
    return fB308(src);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA360);
#ifdef SKIP_ASM
extern int func_3FB278(void);
int func_003FA360(char* name) { return func_003FB278(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA380);
#ifdef SKIP_ASM
typedef struct { unsigned char b[33]; } T_A380;
extern T_A380 D_004973B0;
void func_003FA380(char *src, unsigned short *dst) {
    T_A380 tbl = D_004973B0;
    unsigned char i = 0;
    unsigned short c = *src++;
    while (c != 0) {
        if ((unsigned short)(c - 0x81) < 0x18) {
            c = (c << 8) + *src++;
        } else if (c >= 0x7B) {
            c = tbl.b[c - 0x5E] + 0x8100;
        } else if (c >= 0x61) {
            c = c + 0x8220;
        } else if (c >= 0x5B) {
            c = tbl.b[c - 0x44] + 0x8100;
        } else if (c >= 0x41) {
            c = c + 0x821F;
        } else if (c >= 0x3A) {
            c = tbl.b[c - 0x2A] + 0x8100;
        } else if (c >= 0x30) {
            c = c + 0x821F;
        } else {
            c = tbl.b[c - 0x20] + 0x8100;
        }
        c = (c >> 8) | ((c & 0xFF) << 8);
        dst[i++] = c;
        c = *src++;
    }
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FA4F0);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA6A8);
#ifdef SKIP_ASM
extern int func_3FB280(void);
int func_003FA6A8(void) { return func_003FB280(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA6C8);
#ifdef SKIP_ASM
extern int func_3FB2C8(void);
int func_003FA6C8(void) { return func_003FB2C8(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA6E8);
#ifdef SKIP_ASM
extern int func_3FB300(void);
int func_003FA6E8(void) { return func_003FB300(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA708);
#ifdef SKIP_ASM
void func_003FA708_impl(unsigned a, unsigned char *p) __asm__("func_003FA708");
void func_003FA708_impl(unsigned a, unsigned char *p) {
    switch (a) {
    case 0: p[0] = 0; p[1] = 0; break;
    case 1: p[0] = 0; p[1] = 1; break;
    case 2: p[0] = 0; p[1] = 2; break;
    case 3: p[0] = 0; p[1] = 3; break;
    case 4: p[0] = 1; p[1] = 0; break;
    case 5: p[0] = 1; p[1] = 1; break;
    case 6: p[0] = 1; p[1] = 2; break;
    case 7: p[0] = 1; p[1] = 3; break;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA7A0);
#ifdef SKIP_ASM
extern unsigned char D_004A4BE0[];
extern void func_00416210(char *, int, int);
extern void func_0041605C(char *, char *, int);
char *func_003FA7A0(char *dst, int unused, char *src) {
    char *p = dst + 1;
    func_00416210(dst, 0, 0x20);
    *dst = D_004A4BE0[0];
    func_0041605C(p, src, strlen(src));
    return p + strlen(src);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA818);
#ifdef SKIP_ASM
typedef struct { char b[9]; } K9;
extern K9 D_00497400;
extern void f6210(char *, int, int) __asm__("func_00416210");
extern void f605C(char *, char *, int) __asm__("func_0041605C");
void func_003FA818_impl(char *a, char *b, int unused, char *str) __asm__("func_003FA818");
void func_003FA818_impl(char *a, char *b, int unused, char *str) {
    char *p;
    f6210(a, 0, 0x20);
    *(K9 *)a = D_00497400;
    p = a + 9;
    f605C(p, str, strlen(str));
    p = b + 9;
    strlen(str);
    f6210(b, 0, 0x20);
    *(K9 *)b = D_00497400;
    f605C(p, str, strlen(str));
    strlen(str);
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FA8F8);

INCLUDE_ASM("seg/seg_2F41F8", func_003FAE50);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB278);
#ifdef SKIP_ASM
int func_003FB278(void) { return 1; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB280);
#ifdef SKIP_ASM
static inline unsigned roundup_kb(unsigned v) { if (v & 0x3FF) return ((v >> 10) + 1) << 10; return (v >> 10) << 10; }
void func_003FB280(char *p, int *out, int *kind) {
    unsigned a = roundup_kb(*(unsigned *)(p + 0x3CC));
    unsigned b = roundup_kb(*(unsigned *)(p + 4));
    *out = a + b + 0x1400;
    *kind = 3;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB2C8);
#ifdef SKIP_ASM
extern char *func_003FB5E8(void);
void func_003FB2C8(char **a) {
    char *r = func_003FB5E8();
    if (a) *a = r;
}
#endif

void func_003FB2F8(void) {
}

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB300);
#ifdef SKIP_ASM
int func_003FB300(void) { return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB308);
#ifdef SKIP_ASM
int func_003FB308(int a0) { return a0 ? 0 : 12; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB318);
#ifdef SKIP_ASM
unsigned int func_003FB318(unsigned int c) {
    unsigned char i = 8;
    do {
        if (c & 1) {
            c = (c >> 1) ^ 0xEDB88320;
        } else {
            c >>= 1;
        }
    } while (--i != 0);
    return c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB358);
#ifdef SKIP_ASM
extern unsigned int func_003FB318(unsigned int);
void func_003FB358(unsigned int *t) {
    unsigned int i;
    for (i = 0; i < 256; i++) {
        *t++ = func_003FB318(i);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB3A0);
#ifdef SKIP_ASM
extern int func_00266728(int, int, int);
extern void func_003FB358b(int) __asm__("func_003FB358");
int func_003FB3A0(unsigned a) {
    int r;
    if (D_00451518.table != 0) return 5;
    r = func_00266728(a, 0x400, 4);
    D_00451518.table = (unsigned *)r;
    if (r == 0) return 1;
    D_00451518.heap = a;
    func_003FB358b(r);
    D_00451518.f04 = 4;
    D_00451518.crc = 0xFFFFFFFF;
    D_00451518.f08 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB430);
#ifdef SKIP_ASM
extern int func_00266760(int, char *, int, int);
int func_003FB430(void) {
    struct sCrc *p = &D_00451518;
    if (D_00451518.table == 0) return 6;
    func_00266760(p->heap, (char *)p->table, 0x400, 4);
    D_00451518.table = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB480);
#ifdef SKIP_ASM
int func_003FB480(void) { return D_00451518.table != 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB490);
#ifdef SKIP_ASM
int func_003FB490(void) {
    unsigned long long v = 0xFFFFFFFF;
    if (D_00451518.table == 0) return 6;
    D_00451518.crc = v;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB4C0);
#ifdef SKIP_ASM
int func_003FB4C0(unsigned char *buf, unsigned n) {
    unsigned crc = D_00451518.crc;
    unsigned i;
    if (D_00451518.table == 0) return 6;
    if (buf == 0) return 2;
    for (i = 0; i < n; i++)
        crc = ((crc >> 8) & 0xFFFFFF) ^ D_00451518.table[(crc ^ buf[i]) & 0xFF];
    D_00451518.crc = crc;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB558);
#ifdef SKIP_ASM
extern int D_004A5B1C;
int func_003FB558(int **out) {
    struct sCrc *p = &D_00451518;
    if (D_00451518.table == 0) return 6;
    if (out == 0) return 2;
    p->f08 = &D_004A5B1C;
    p->f04 = 4;
    D_004A5B1C = ~p->crc;
    *out = &p->f04;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB5B0);
#ifdef SKIP_ASM
int func_003FB5B0(int *out) {
    if (D_00451518.table == 0) return 6;
    if (out == 0) return 2;
    *out = 4;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB5E8);
#ifdef SKIP_ASM
extern char D_00497508[];
char *func_003FB5E8(void) { return D_00497508; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB5F8);
#ifdef SKIP_ASM
int func_003FB5F8(void) {
    if (D_004A4BF0 != 4) return 3;
    D_004A4BF0 = 6;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB620);
#ifdef SKIP_ASM
int func_003FB620(void) {
    D_004A4BE4 = 0;
    D_004A4BE8 = 0;
    D_004A4BEC = 0;
    D_004A4BF0 = 4;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB640);
#ifdef SKIP_ASM
int func_003FB640(void) { return D_004A4BF0 != 4; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB650);
#ifdef SKIP_ASM
int func_003FB650(unsigned char *a, int b) {
    if (a == 0 || b == 0) return 2;
    if (D_004A4BF0 == 4) return 4;
    D_004A4BE4 = a;
    D_004A4BE8 = a + b - 1;
    D_004A4BEC = a;
    D_004A4BF0 = 5;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB6A0);
#ifdef SKIP_ASM
int func_003FB6A0(unsigned char *buf, unsigned n) {
    unsigned i;
    if (buf == 0 || n == 0) return 2;
    if (D_004A4BF0 != 5 && D_004A4BF0 != 7) return D_004A4BF0;
    for (i = 0; i < n; i++) {
        buf[i] ^= *D_004A4BEC;
        if (D_004A4BEC == D_004A4BE8) D_004A4BEC = D_004A4BE4;
        else D_004A4BEC = D_004A4BEC + 1;
    }
    D_004A4BF0 = 7;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB730);
#ifdef SKIP_ASM
int func_003FB730(unsigned char *buf, unsigned n) {
    unsigned i;
    if (buf == 0 || n == 0) return 2;
    if (D_004A4BF0 != 5 && D_004A4BF0 != 8) return D_004A4BF0;
    for (i = 0; i < n; i++) {
        buf[i] ^= *D_004A4BEC;
        if (D_004A4BEC == D_004A4BE8) D_004A4BEC = D_004A4BE4;
        else D_004A4BEC = D_004A4BEC + 1;
    }
    D_004A4BF0 = 8;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB7C0);
#ifdef SKIP_ASM
int func_003FB7C0(void) {
    if (D_004A4BF0 == 5 || D_004A4BF0 == 7 || D_004A4BF0 == 8) {
        D_004A4BF0 = 5;
        D_004A4BEC = D_004A4BE4;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB800);
#ifdef SKIP_ASM
extern char D_00497528[];
char *func_003FB800(void) { return D_00497528; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB810);
#ifdef SKIP_ASM
char *func_003FB810_impl(char *p) __asm__("func_003FB810");
char *func_003FB810_impl(char *p) {
    if (p == 0) return 0;
    return p + 100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB828);
#ifdef SKIP_ASM
char *func_003FB828_impl(char *p) __asm__("func_003FB828");
char *func_003FB828_impl(char *p) {
    if (p == 0) return 0;
    return p + 200;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB840);
#ifdef SKIP_ASM
char *func_003FB840_impl(char *p) __asm__("func_003FB840");
char *func_003FB840_impl(char *p) {
    if (p == 0) return 0;
    return p + 300;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB858);
#ifdef SKIP_ASM
void func_003FB858(unsigned a, int *x, int *y) {
    int sx = 4, sy = 1;
    switch (a) {
    case 0: sx = 4; sy = 1; break;
    case 1: sx = 4; sy = 1; break;
    case 2: sx = 4; sy = 1; break;
    case 3: sx = 4; sy = 1; break;
    case 4: sx = 4; sy = 1; break;
    }
    *x = sx;
    *y = sy;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB898);
#ifdef SKIP_ASM
extern void func_003FB858b(int, int *, int *) __asm__("func_003FB858");
int func_003FB898(int a, int b);
int func_003FB898(int a, int b) {
    int x = 4;
    unsigned y = 1;
    unsigned r;
    unsigned pad;
    func_003FB858b(b, &x, (int *)&y);
    r = a + 0xC;
    if (r < y) return y;
    pad = (y - r % y) % y;
    return a + 0xC + pad;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB910);
#ifdef SKIP_ASM
extern int func_00415FC8(int, char *, int);
extern char D_00497550[];
int func_003FB910(int a, int b) {
    int r = a - 0xC;
    if (b & 0xFF) {
        if (func_00415FC8(r, D_00497550, 0xC) != 0) r = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB958);
#ifdef SKIP_ASM
typedef struct { char b[4]; } W3FB958;
typedef struct { W3FB958 x, y; } V3FB958;
void func_003FB958(W3FB958 *dst, int a, int b, W3FB958 *c) {
    V3FB958 t;
    *(int *)&t.x = a;
    *(int *)&t.y = b;
    dst[0] = t.x;
    dst[1] = t.y;
    dst[2] = *c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB9A0);
#ifdef SKIP_ASM
extern char D_00497550[];
void func_003FB9A0(char *dst) {
    __builtin_memcpy(dst, D_00497550, 12);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB9D0);
#ifdef SKIP_ASM
void func_003FB9D0(char *src, char *d1, char *d2, char *d3) {
    if (d1) __builtin_memcpy(d1, src, 4);
    if (d2) __builtin_memcpy(d2, src + 4, 4);
    if (d3) __builtin_memcpy(d3, src + 8, 4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBA20);
#ifdef SKIP_ASM
struct sMcEnt *func_003FBA20(int key, int n) {
    struct sMcState *s = D_004A5B20;
    struct sMcEnt *end = s->f9C + s->f94;
    struct sMcEnt *e = s->f9C;
    int cnt = 0;
    for (; e < end; e++) {
        if (key == e->key) {
            if (n == cnt) return e;
            cnt++;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBA78);
#ifdef SKIP_ASM
void func_003FBA78(int key, int n, int *val) {
    struct sMcState *s = D_004A5B20;
    struct sMcEnt *end = s->f9C + s->f94;
    struct sMcEnt *e = s->f9C;
    int cnt = 0;
    for (; e < end; e++) {
        if (key == e->key) {
            if (n == cnt) e->c = *val;
            cnt++;
        }
    }
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FBAD0);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBB50);
#ifdef SKIP_ASM
extern int func_003FB840c(int) __asm__("func_003FB840");
int func_003FBB50_impl(int a, int b, int c) __asm__("func_003FBB50");
int func_003FBB50_impl(int a, int b, int c) {
    struct sMcIfB *vt = D_004A5B20->f70;
    int r = vt->f0C(a, b, c);
    if (r == 0) {
        r = vt->f10(a, b);
        if (r == 0) {
            r = vt->f14(c);
            if (r == 0) return 0;
        }
    }
    return func_003FB840c(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBBE0);
#ifdef SKIP_ASM
extern int func_003FBB50(void *, int, int **);
void func_003FBBE0(struct sMcKey *out) {
    struct sMcState *s = D_004A5B20;
    int *r;
    int sz = s->f94 << 4;
    if (sz == 0) {
        *(int *)out = 0;
    } else {
        func_003FBB50(s->f9C, sz, &r);
        *out = *(struct sMcKey *)r[1];
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBC40);
#ifdef SKIP_ASM
extern int fB828b(int) __asm__("func_003FB828");
int func_003FBC40_impl(int x, int y) __asm__("func_003FBC40");
int func_003FBC40_impl(int x, int y) {
    int r;
    if (D_004A5B20->f6C == 0) return 0;
    r = D_004A5B20->f6C->f0C(D_004A5B20->f64, D_004A5B20->f68);
    if (r == 0) {
        r = D_004A5B20->f6C->f10(x, y);
        if (r == 0) {
            r = D_004A5B20->f6C->f18();
            if (r == 0) return 0;
        }
    }
    return fB828b(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBCD8);
#ifdef SKIP_ASM
extern int fB828(int) __asm__("func_003FB828");
int func_003FBCD8_impl(int x, int y) __asm__("func_003FBCD8");
int func_003FBCD8_impl(int x, int y) {
    int r;
    if (D_004A5B20->f6C == 0) return 0;
    r = D_004A5B20->f6C->f0C(D_004A5B20->f64, D_004A5B20->f68);
    if (r == 0) {
        r = D_004A5B20->f6C->f14(x, y);
        if (r == 0) {
            r = D_004A5B20->f6C->f18();
            if (r == 0) return 0;
        }
    }
    return fB828(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBD70);
#ifdef SKIP_ASM
extern int func_003F99B8(int, int, int);
int func_003FBD70(int a, int b, int c, int d) {
    int r = func_003F99B8(a, b, c);
    struct sMcState *p = D_004A5B20;
    p->f74 = d;
    p->f78 = 4;
    p->f94 = 0;
    p->f98 = 0;
    return func_003FB810(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBDB8);
#ifdef SKIP_ASM
extern int func_003F9C48(struct sMcState *, int, int);
extern int func_003FB810(int);
int func_003FBDB8(void) {
    struct sMcState *p = D_004A5B20;
    p->f78 = 9;
    return func_003FB810(func_003F9C48(p, 0, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBDF0);
#ifdef SKIP_ASM
extern int func_003FB898(int, int);
extern int func_003F9DC0(struct sMcState *, int, int);
extern int func_003FB810(int);
int func_003FBDF0(void) {
    struct sMcState *p = D_004A5B20;
    p->f78 = 7;
    return func_003FB810(func_003F9DC0(D_004A5B20, p->f80, func_003FB898(0, 1)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBE40);
#ifdef SKIP_ASM
extern int fBCD8(int, int) __asm__("func_003FBCD8");
extern void fB9D0(int, int *, int *, char *) __asm__("func_003FB9D0");
extern int fBAD0(int, int, char *) __asm__("func_003FBAD0");
extern int f9C48(struct sMcState *, int, int) __asm__("func_003F9C48");
int func_003FBE40(void) {
    int x[2];
    int r;
    int p, q;
    x[1] = 0;
    D_004A5B20->f78 = 0xB;
    r = fBCD8(D_004A5B20->f80, 0xC);
    if (r != 0) return r;
    fB9D0(D_004A5B20->f80, &x[0], &x[1], D_004A5B20->f88.b);
    q = x[1];
    p = x[0];
    r = fBAD0(p, q, D_004A5B20->f88.b);
    if (D_004A5B20->f98 == r) return 5;
    return func_003FB810(f9C48(D_004A5B20, D_004A5B20->f98, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBED0);
#ifdef SKIP_ASM
extern int func_003FB910(int, int);
extern void fB958(int, int, int, char *) __asm__("func_003FB958");
extern int fBC40(int, int) __asm__("func_003FBC40");
extern int f9F00(struct sMcState *, int, int) __asm__("func_003F9F00");
int func_003FBED0(void) {
    int h;
    int r;
    D_004A5B20->f78 = 6;
    h = func_003FB910(D_004A5B20->f7C, 1);
    if (h == 0) return 4;
    fB958(h, D_004A5B20->f8C, D_004A5B20->f84, D_004A5B20->f88.b);
    r = fBC40(h, 0xC);
    if (r != 0) return r;
    r = fBC40(D_004A5B20->f7C, D_004A5B20->f84);
    if (r != 0) return r;
    r = func_003FB898(D_004A5B20->f84, 2);
    return func_003FB810(f9F00(D_004A5B20, h, r));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBF80);
#ifdef SKIP_ASM
extern int func_003FB898(int, int);
extern int func_003F9DC0(struct sMcState *, int, int);
extern int func_003FB810(int);
int func_003FBF80(void) {
    struct sMcState *p = D_004A5B20;
    int r;
    p->f78 = 10;
    r = func_003FB910(p->f7C, 0);
    return func_003FB810(func_003F9DC0(D_004A5B20, r, func_003FB898(D_004A5B20->f84, 1)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBFE0);
#ifdef SKIP_ASM
typedef struct { int tag; int p; } P3FBFE0;
typedef struct { int a; int b; P3FBFE0 *p; } L3FBFE0;
extern int func_003FB910(int, int);
extern int fBCD8(int, int) __asm__("func_003FBCD8");
extern void fB9D0(int, int *, int *, char *) __asm__("func_003FB9D0");
extern int fBB50(int, int, P3FBFE0 **) __asm__("func_003FBB50");
extern int f5FC8(int, char *, int) __asm__("func_00415FC8");
int func_003FBFE0(void) {
    L3FBFE0 x; int h; int r; int err = 0xA; int hh;
    x.p = 0; hh = D_004A5B20->f7C; x.b = 0;
    D_004A5B20->f78 = err;
    h = func_003FB910(hh, 0);
    r = fBCD8(h, 0xC);
    if (r != 0) return r;
    fB9D0(h, &x.a, &x.b, D_004A5B20->f88.b);
    if (x.a != D_004A5B20->f8C) return 0xB;
    if (x.b != D_004A5B20->f84) return 0x6E;
    r = fBCD8(D_004A5B20->f7C, x.b);
    if (r != 0) return r;
    r = fBB50(D_004A5B20->f7C, D_004A5B20->f84, &x.p);
    if (r != 0) return r;
    if (x.p->tag != 4) return 0xB;
    if (f5FC8(x.p->p, D_004A5B20->f88.b, 4) == 0) err = 0;
    return err;
}

#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC0D8);
#ifdef SKIP_ASM
int func_003FC0D8(void) { return D_004A5B20 != 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC0E8);
#ifdef SKIP_ASM
typedef struct { int f0; int f4; int f8; char *fC; int f10; struct sMcIfA *f14; int f18; } P0E8;
extern int func_003FC0D8(void);
extern int func_003F9218(int, int, int);
extern int func_003FB810(int);
extern int func_003FB840c(int) __asm__("func_003FB840");
extern int fB828(int) __asm__("func_003FB828");
extern void *c0e8_6728(int, int, int) __asm__("func_00266728");
extern void c0e8_A6C8(struct sMcIfB **) __asm__("func_003FA6C8");
extern int func_003FCE10(char *, int, int, int);
extern void func_0041605C(char *, char *, int);
int func_003FC0E8(P0E8 *p) {
    int r;
    struct sMcIfA *cb;
    if (func_003FC0D8() != 0) return 1;
    r = func_003F9218(p->f4, p->f8, p->f18);
    if (r != 0) return func_003FB810(r);
    D_004A5B20 = c0e8_6728(p->f18, 0xAC, 4);
    if (D_004A5B20 == 0) return 6;
    c0e8_A6C8(&D_004A5B20->f70);
    r = D_004A5B20->f70->f00(p->f18);
    if (r != 0) return func_003FB840c(r);
    D_004A5B20->f6C = cb = p->f14;
    if (cb != 0) {
        int n;
        r = cb->f00(p->f18);
        if (r != 0) return fB828(r);
        n = p->f10;
        D_004A5B20->f68 = n;
        D_004A5B20->f64 = c0e8_6728(p->f18, n, 4);
        if (D_004A5B20->f64 == 0) return 6;
        func_0041605C(D_004A5B20->f64, p->fC, D_004A5B20->f68);
    }
    D_004A5B20->f90 = p->f0;
    D_004A5B20->f94 = 0;
    D_004A5B20->f98 = 0;
    D_004A5B20->f9C = c0e8_6728(p->f18, p->f0 << 4, 4);
    if (D_004A5B20->f9C == 0) return 6;
    r = func_003FCE10((char *)&D_004A5B20->f80, D_004A5B20->fA0, 0, 1);
    if (r != 0) return r;
    D_004A5B20->f80 -= 0xC;
    D_004A5B20->fA0 = p->f18;
    D_004A5B20->fA8 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC260);
#ifdef SKIP_ASM
// 99.47: only $2/$3 swap between D ptr and q (f6C) in blocks 3,7 (target D in $2). tried decl order sweep, q vs int v, permuter 4min nothing. Names prefixed c260_ in file to avoid clashes
extern int func_003FC0D8(void);
extern void c260_B9A0(int) __asm__("func_003FB9A0");
extern void c260_6760(int, void *, int, int) __asm__("func_00266760");
extern int c260_B828(int) __asm__("func_003FB828");
extern int c260_B840(int) __asm__("func_003FB840");
extern int c260_B810(int, struct sMcState *) __asm__("func_003FB810");
extern int c260_9530(void) __asm__("func_003F9530");
int func_003FC260(void) {
    int r;
    int v;
    struct sMcIfA *q;
    if (func_003FC0D8() == 0) return 2;
    c260_B9A0(D_004A5B20->f80);
    v = D_004A5B20->f80 + 0xC;
    D_004A5B20->f80 = v;
    r = func_003FCF00(v, D_004A5B20->fA0, 0, 1);
    if (r != 0) return r;
    c260_6760(D_004A5B20->fA0, D_004A5B20->f9C, D_004A5B20->f90 * 16, 4);
    q = D_004A5B20->f6C;
    D_004A5B20->f9C = 0;
    if (q != 0) {
        r = q->f04();
        if (r != 0) return c260_B828(r);
        c260_6760(D_004A5B20->fA0, D_004A5B20->f64, D_004A5B20->f68, 4);
        D_004A5B20->f64 = 0;
    }
    D_004A5B20->f6C = 0;
    r = D_004A5B20->f70->f04();
    if (r != 0) return c260_B840(r);
    D_004A5B20->f70 = 0;
    r = c260_9530();
    if (r != 0) return c260_B810(r, D_004A5B20);
    c260_6760(D_004A5B20->fA0, D_004A5B20, 0xAC, 4);
    D_004A5B20 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC390);
#ifdef SKIP_ASM
extern int func_003F9818(char *str, int a, int b);
extern int func_003FB810(int);
int func_003FC390(char *str, int a, int b) {
    struct sMcState *p = D_004A5B20;
    p->f74 = 1;
    p->f78 = 1;
    return func_003FB810(func_003F9818(str, a, b));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC3C0);
#ifdef SKIP_ASM
extern int func_003F9698(char *str, int a, int b);
extern int func_003FB810(int);
int func_003FC3C0(char *str, int a, int b) {
    struct sMcState *p = D_004A5B20;
    p->f74 = 2;
    p->f78 = 2;
    return func_003FB810(func_003F9698(str, a, b));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC3F0);
#ifdef SKIP_ASM
extern int fBD70(char *, int, int, int) __asm__("func_003FBD70");
int func_003FC3F0_impl(struct sMcParams *a) __asm__("func_003FC3F0");
int func_003FC3F0_impl(struct sMcParams *a) {
    D_004A5B20->params = *a;
    return fBD70((char *)a + 0x48, a->w[1], -1, 5);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC4C8);
#ifdef SKIP_ASM
extern int func_003FBD70(int, int, int, int);
int func_003FC4C8(int a, int b, int c) { return func_003FBD70(a, b, c, 4); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC4E8);
#ifdef SKIP_ASM
extern int func_003F9B38(char *);
extern int func_003FB810(int);
extern void func_003FBBE0b(char *) __asm__("func_003FBBE0");
int func_003FC4E8(char *x) {
    struct sMcState *p;
    func_003FBBE0b(x + 0x60);
    /* stored through a pointer, not params.w[24]: the target reloads D_004A5B20 after this store */
    *(D_004A5B20->params.w + 24) = *(int *)(x + 0x60);
    p = D_004A5B20;
    p->f74 = 3;
    p->f78 = 3;
    p->f98 = 0;
    p->f94 = 0;
    return func_003FB810(func_003F9B38(x));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC548);
#ifdef SKIP_ASM
typedef struct { int w[25]; } __attribute__((aligned(8))) S64C548;
extern int fBB50w(int, int, int *) __asm__("func_003FBB50");
extern int fBAD0w(int, int, void *) __asm__("func_003FBAD0");
extern void fBA78w(int, int, void *) __asm__("func_003FBA78");
extern void fBBE0w(void *) __asm__("func_003FBBE0");
extern int f9C48w(void *, int, int) __asm__("func_003F9C48");
int func_003FC548(S64C548 *p, int a, int b, int c, int d) {
    int *r[4];
    int v;
    void* k;
    r[0] = 0;
    D_004A5B20->f74 = 6;
    D_004A5B20->f78 = 5;
    __builtin_memcpy(D_004A5B20, p, 0x64);
    D_004A5B20->f84 = d;
    D_004A5B20->f7C = c;
    D_004A5B20->f8C = a;
    k = func_003FBA20(a, b);
    if (fBB50w(D_004A5B20->f7C, D_004A5B20->f84, (int *)r) == 0) {
        D_004A5B20->f88 = *(struct sMcKey *)((int *)r[0])[1];
        if (k == 0) {
            v = D_004A5B20->f98;
            fBAD0w(a, D_004A5B20->f84, &D_004A5B20->f88);
        } else {
            v = ((int *)k)[1];
            fBA78w(a, b, &D_004A5B20->f88);
        }
        fBBE0w((char *)p + 0x60);
        return func_003FB810(f9C48w(p, v, 0));
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC708);
#ifdef SKIP_ASM
extern int c708_9C48(void *, int, int) __asm__("func_003F9C48");
int func_003FC708_impl(struct sMcParams *src, int a, int b, int c, int d) __asm__("func_003FC708");
int func_003FC708_impl(struct sMcParams *src, int a, int b, int c, int d) {
    struct sMcState *s = D_004A5B20;
    struct sMcEnt *r;
    int v;
    s->f74 = 8;
    s->f78 = 5;
    s->params = *src;
    D_004A5B20->f7C = c;
    D_004A5B20->f8C = a;
    D_004A5B20->f84 = d;
    r = func_003FBA20(a, b);
    if (r == 0) return 7;
    if (d != r->b) return 0x6E;
    v = r->a;
    D_004A5B20->fA4 = v;
    return func_003FB810(c708_9C48(src, v, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC850);
#ifdef SKIP_ASM
extern int func_003FC0D8(void);
int func_003FC850_impl(int a, int key, int *out) __asm__("func_003FC850");
int func_003FC850_impl(int a, int key, int *out) {
    struct sMcState *s;
    struct sMcEnt *e, *end;
    if (!func_003FC0D8()) return 2;
    if (a == 0) return 4;
    if (out == 0) return 4;
    *out = 0;
    s = D_004A5B20;
    end = s->f9C + s->f94;
    e = s->f9C;
    for (; e < end; e++) {
        if (key == e->key) *out = *out + 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC8F8);
#ifdef SKIP_ASM
extern int func_003FC0D8(void);
int func_003FC8F8_impl(int a, int b, int c, int *out) __asm__("func_003FC8F8");
int func_003FC8F8_impl(int a, int b, int c, int *out) {
    int err = 0;
    struct sMcEnt *e;
    if (!func_003FC0D8()) return 2;
    if (a == 0) return 4;
    if (out == 0) return 4;
    *out = 0;
    e = func_003FBA20(b, c);
    if (e) *out = e->b;
    else err = 7;
    return err;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC990);
#ifdef SKIP_ASM
int func_003FC990_impl(struct sMcParams *dst) __asm__("func_003FC990");
int func_003FC990_impl(struct sMcParams *dst) {
    if (dst == 0) return 4;
    *dst = D_004A5B20->params;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FCA40);
