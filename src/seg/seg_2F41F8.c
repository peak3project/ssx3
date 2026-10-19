#include "common.h"

INCLUDE_ASM("seg/seg_2F41F8", func_003F31F8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F33B0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F3530);

INCLUDE_ASM("seg/seg_2F41F8", func_003F35D0);

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
extern int f4C68h(char *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_00256BD8(int *);
void func_003F3940(int *self) {
    int v = self[0x58 / 4];
    func_003F4C98(D_0051F010, 'name', 'free');
    f4C68h(D_0051F010, 1, v, 0, 0, 0, 0, 0, 0, 0);
    func_00256BD8(self);
}

#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F39C8);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F3A98);
#ifdef SKIP_ASM
extern int func_003F39C8(void);
int func_003F3A98(void) { return func_003F39C8(); }
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
extern int f5470(void) __asm__("func_003F5470");
extern void f5000(int) __asm__("func_003F5000");
extern void f4D68(void) __asm__("func_003F4D68");
extern int func_003F4C98(char *, int, int);
extern int f4C68e(char *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
int func_003F3B18(int a) {
    char buf[16];
    if (D_004A4BA0 != 0) return -1;
    if (f5470() <= 0) {
        f5000(0);
        f4D68();
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

INCLUDE_ASM("seg/seg_2F41F8", func_003F3CC0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F3F78);

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
extern int D_0051F030[];
int func_003F4210(int a, int b) {
    int i;
    int *p = D_0051F030;
    for (i = 0; i < 16; i++) {
        if (p[0] == 0) {
            p[0] = a;
            p[1] = b;
            return 0;
        }
        p += 2;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4250);
#ifdef SKIP_ASM
extern int D_0051F030[];
int func_003F4250(int a, int b) {
    int i;
    int *p = D_0051F030;
    for (i = 0; i < 16; i++) {
        if (p[0] == a && p[1] == b) {
            p[0] = 0;
            p[1] = 0;
            return 0;
        }
        p += 2;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F42A0);
#ifdef SKIP_ASM
extern int D_004A4BA0;
extern unsigned D_004A4BAC;
extern int f4DE8(void) __asm__("func_003F4DE8");
extern void f4A78(void) __asm__("func_003F4A78");
typedef struct { void (*fn)(int, int); int arg; } T42A0;
extern T42A0 D_42A0t[] __asm__("D_0051F030");
void func_003F42A0(void) {
    int i;
    T42A0 *p;
    if (D_004A4BA0 != 0) {
        if (f4DE8() < D_004A4BAC) return;
        D_004A4BAC = f4DE8() + 5;
    }
    f4A78();
    p = D_42A0t;
    for (i = 0xF; i >= 0; i--) {
        if (p->fn) p->fn(p->arg, f4DE8());
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

INCLUDE_ASM("seg/seg_2F41F8", func_003F4410);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4448);
#ifdef SKIP_ASM
typedef struct { int pad[7]; int v; } E4448;
typedef struct { char pad[0x4D94]; E4448 *p94; char pad2[8]; E4448 *pA0; char pad3[0x2C]; int c0; int c4; char pad4[0x10]; int e8; int ec; int f0; } S4448;
extern int f4C50(int) __asm__("func_00424C50");
extern int f3B80(int, void *, void *) __asm__("func_00423B80");
void func_003F4448(int a, int b, S4448 *s);
void func_003F4448(int a, int b, S4448 *s) {
    if (a == s->ec) s->ec = -1;
    if (a == s->f0) s->f0 = -1;
    if (s->c4 != s->c0) {
        if (s->pA0[s->c4].v == s->p94[s->c4].v) f4C50(s->e8);
        if (s->ec < 0 && s->f0 < 0) s->f0 = f3B80(0x10, (void *)func_003F4448, s);
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

INCLUDE_ASM("seg/seg_2F41F8", func_003F4A78);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F4C98);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4D68);
#ifdef SKIP_ASM
typedef struct { char pad[0x4D88]; int a; int b; char pad2[0x40]; int c; int d; } S4D68;
extern S4D68 D_4d68 __asm__("D_0051F0C0");
extern int func_003F4C68d(int *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern void func_003F4A78v(void) __asm__("func_003F4A78");
int func_003F4D68(void) {
    int t[4];
    t[3] = 1;
    func_003F4C68d(t, 1, 0, 0, 0, 0, D_4d68.a, D_4d68.b - D_4d68.a, 1, 0);
    while (D_4d68.c != D_4d68.d) func_003F4A78v();
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F4DE8);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F4F40);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5000);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F53F8);
#ifdef SKIP_ASM
extern char D_0051F0C0[];
extern int D_004A4BB0;
extern void func_00423B30(int);
extern void func_00423AA0(int, int);
extern void func_00423BF0(int);
extern void func_00423BB0(int);
extern void func_00423DB0(int);
int func_003F53F8(void) {
    char *p = D_0051F0C0;
    if (*(int *)(p + 0x4DEC) >= 0) func_00423B30(*(int *)(p + 0x4DEC));
    if (*(int *)(p + 0x4DF0) >= 0) func_00423B30(*(int *)(p + 0x4DF0));
    func_00423AA0(2, *(int *)(p + 0x4DF4));
    func_00423BF0(*(int *)(p + 0x4DE8));
    func_00423BB0(*(int *)(p + 0x4DE8));
    func_00423DB0(*(int *)(p + 0x4E08));
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

INCLUDE_ASM("seg/seg_2F41F8", func_003F5478);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F55B8);
#ifdef SKIP_ASM
extern char D_00525F10[];
extern int func_003F4C98(char *, int, int);
extern int f4C68c(char *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_00256BD8(int *);
void func_003F55B8(int *p) {
    func_003F4C98(D_00525F10, 'sess', 'dest');
    f4C68c(D_00525F10, 1, *p, 0, 0, 0, 0, 0, 1, 0);
    func_00256BD8(p);
}

#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F5638);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5738);
#ifdef SKIP_ASM
extern char D_00525F30[];
extern int func_003F4C98(char *, int, int);
extern int func_003F4C68c(char *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern void func_00416210b(int, int, int) __asm__("func_00416210");
int func_003F5738(int *self) {
    func_003F4C98(D_00525F30, 'sess', 'disc');
    func_003F4C68c(D_00525F30, 0, self[0], 0, 0, 0, 0, 0, 0, 0);
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

INCLUDE_ASM("seg/seg_2F41F8", func_003F5910);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5A50);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5A70);

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
extern int D_5DA8[] __asm__("D_00525F80");
extern char *strcpy(char *, const char *);
extern int strlen5(const char *) __asm__("strlen");
extern void f62D0(char *, const char *) __asm__("func_004162D0");
extern int fBA68(char *, int, const char *) __asm__("func_0042BA68");
extern char D_00497038[], D_00497048[];
int func_003F5DA8(char *name, char *str) {
    char path[0x100];
    if (name == 0) {
        D_5DA8[0] = -1;
        D_5DA8[1] = -1;
        return 0;
    }
    if (str == 0) goto fail;
    strcpy(path, name);
    f62D0(path, D_00497038);
    D_5DA8[0] = fBA68(path, 0, 0);
    if (D_5DA8[0] < 0) goto fail;
    strcpy(path, name);
    f62D0(path, D_00497048);
    D_5DA8[1] = fBA68(path, strlen5(str) + 1, str); if (D_5DA8[1] < 0) return -1; return 0;
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
typedef struct { char pad0[16]; unsigned char v[128]; int cnt; unsigned char prev[128]; } Q5F08;
extern Q5F08 D_5F80q __asm__("D_00525F80");
extern char D_00525F88[];
extern int sceUsbKbGetInfo(char *);
void func_003F5F08(void) {
    int i;
    char *p;
    for (i = 0; i < D_5F80q.cnt; i++) D_5F80q.prev[i] = D_5F80q.v[i];
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
typedef struct { char pad0[16]; unsigned char v[128]; int cnt; unsigned char prev[8]; int st; unsigned char flag; char pad3[0x1B]; void (*cb)(int, int); } Q5F88;
extern Q5F88 D_5F88q __asm__("D_00525F80");
extern int f810(int, int *) __asm__("func_0040C810");
int func_003F5F88(void) {
    int tmp;
    int r;
    int i;
    r = f810(1, &tmp);
    if (r != 0) return r;
    for (i = 0; i < D_5F88q.cnt; i++) {
        if (((unsigned char *)&D_5F88q)[0x94 + i] != D_5F88q.v[i]) D_5F88q.cb(i, D_5F88q.v[i]);
    }
    D_5F88q.flag = 0;
    D_5F88q.st = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6040);
#ifdef SKIP_ASM
typedef struct { char pad0[16]; unsigned char v[128]; int cnt; char pad2[0x14]; char *ents; } Q;
extern Q D_00525F80q __asm__("D_00525F80");
int func_003F6040(int i) {
    int c;
    for (c = 0; c < D_00525F80q.cnt; c++) {
        if (i >= D_00525F80q.cnt) i = 0;
        if (D_00525F80q.v[i] != 0) {
            if (*(unsigned char *)(D_00525F80q.ents + i * 0x8C + 0x88) == 0) return i;
        }
        i++;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F60B8);
#ifdef SKIP_ASM
typedef struct { char pad0[0x9C]; int state; unsigned char flag; char pad1[3]; int cur; int *ents; int a; int b; } Q60B8;
extern Q60B8 D_60B8q __asm__("D_00525F80");
extern int func_003F6040(int);
extern int sceUsbKbRead(int, int *);
void func_003F60B8(void) {
    int id = func_003F6040(D_60B8q.cur + 1);
    int *e;
    if (id != -1) {
        D_60B8q.cur = id;
        e = (int *)((char *)D_60B8q.ents + id * 0x8C);
        D_60B8q.a = e[0];
        D_60B8q.b = e[1];
        if (sceUsbKbRead(id, e) == 0) {
            D_60B8q.state = 2;
            D_60B8q.flag = 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6138);
#ifdef SKIP_ASM
typedef struct { char pad0[0x9C]; int st; unsigned char flag; char p1[3]; int cur; char *ents; int a; int b; } Q6138;
extern Q6138 D_6138q __asm__("D_00525F80");
extern int f810(int, int *) __asm__("func_0040C810");
int func_003F6138(void) {
    int tmp;
    int r;
    r = f810(0, &tmp);
    if (r != 0) return r;
    {
        int *e = (int *)(D_6138q.ents + D_6138q.cur * 0x8C);
        if (e[2] > 0 || e[1] != D_6138q.b || e[0] != D_6138q.a) ((unsigned char *)e)[0x88] = 1;
    }
    D_6138q.flag = 0;
    D_6138q.st = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F61C8);
#ifdef SKIP_ASM
int func_003F61C8(void) { return 0; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F61D0);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F62F8);
#ifdef SKIP_ASM
extern int func_0040C220(void);
extern int func_003F5E90(int, int);
extern int D_00525F80a[] __asm__("D_00525F80");
int func_003F62F8(void) {
    int r;
    func_0040C220();
    r = func_003F5E90(D_00525F80a[1], 1);
    return r | func_003F5E90(D_00525F80a[0], 2);
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
typedef struct { char pad[0x9C]; unsigned st; char pad2[0x14]; int cnt; int max; int pad3; int (*cb)(int); } Q63F0;
extern Q63F0 D_63F0q __asm__("D_00525F80");
extern void f5F88(void) __asm__("func_003F5F88");
extern void f6138(void) __asm__("func_003F6138");
extern void f5F08(void) __asm__("func_003F5F08");
extern void f60B8(void) __asm__("func_003F60B8");
void func_003F63F0_impl(void) __asm__("func_003F63F0");
void func_003F63F0_impl(void) {
    switch (D_63F0q.st) {
    case 1: f5F88(); break;
    case 0: break;
    case 2: f6138(); break;
    case 3: if (D_63F0q.cb(1) != 0) D_63F0q.st = 0; break;
    }
    if (D_63F0q.st == 0) {
        if (D_63F0q.cb(0) != 0) D_63F0q.st = 3;
        if (D_63F0q.st == 0) {
            D_63F0q.cnt = D_63F0q.cnt + 1;
            if (D_63F0q.max < D_63F0q.cnt) { D_63F0q.cnt = 0; f5F08(); } else { f60B8(); }
        }
    }
}

#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F64E0);
#ifdef SKIP_ASM
unsigned char *func_003F64E0(int n) {
    int off = n * 0x8C;
    if (((unsigned char*)D_00525F80q.ents)[off + 0x88] == 1) {
        ((unsigned char*)D_00525F80q.ents)[off + 0x88] = 0;
        return (unsigned char*)D_00525F80q.ents + off;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6520);
#ifdef SKIP_ASM
extern struct { char pad[16]; unsigned char v[1]; } D_00525F80;
int func_003F6520(int a0) { return D_00525F80.v[a0] != 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6538);
#ifdef SKIP_ASM
extern int func_003F63F0(void);
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
extern unsigned char D_004A5B14b __asm__("D_004A5B14");
extern int D_6100[] __asm__("D_00526100");
typedef struct { int a; int b; } R6960;
extern R6960 D_526080s[] __asm__("D_00526080");
extern int f6F08(int *) __asm__("func_00426F08");
extern int f6D18(int *, int, int, R6960 *, int, int, int, int, int) __asm__("func_00426D18");
void func_003F6960_impl(int a, int b, int c, int d, int e) __asm__("func_003F6960");
void func_003F6960_impl(int a, int b, int c, int d, int e) {
    R6960 *r = D_526080s;
    if (D_004A5B14b) {
        while (f6F08(D_6100) > 0) ;
        r->a = b;
        r->b = c;
        do {
            if (f6D18(D_6100, a, 0, D_526080s, 0x80, d, e, 0, 0) >= 0) break;
        } while (1);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6A40);
#ifdef SKIP_ASM
extern char D_004A5B14;
extern int *D_004A5B18;
extern int D_00526100[], D_005261C0[], D_00526140[];
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
extern char D_004A5B14;
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
int func_003F6B20(void) { return func_003F6960(4, 0, 0, D_00526140, 0x80); }
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
int func_003F6C10(int a, int b) { return func_003F6960(6, a, b, D_00526140, 0x80); }
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

INCLUDE_ASM("seg/seg_2F41F8", func_003F6C70);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6D98);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern int func_00266760(int, char *, int, int);
int func_003F6D98(void) {
    func_00266760(*(int *)(D_004A4BC4 + 0x140), D_004A4BC4, 0x14C, 4);
    D_004A4BC4 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F6DC8);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
typedef struct { char b[0x1A]; } K6DC8;
extern K6DC8 D_00497060;
extern int fB800(void) __asm__("func_003FB800");
extern int fC0E8(void *) __asm__("func_003FC0E8");
extern int func_003F8178(int);
typedef struct { int a; char *p; char *d; K6DC8 *buf; int len; int r; int v; } R6DC8;
int func_003F6DC8(void) {
    K6DC8 buf;
    R6DC8 req;
    char *d = D_004A4BC4;
    buf = D_00497060;
    req.a = 2;
    req.p = d + 0x138;
    req.d = d;
    req.len = 0x1A;
    req.buf = &buf;
    req.r = fB800();
    req.v = *(int *)(D_004A4BC4 + 0x140);
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
extern char *D_004A4BC4;
extern int func_003F7990(int);
int func_003F6E98(int a) {
    int r = 0;
    if (*(int *)(D_004A4BC4 + 0xD0) == 4) {
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
extern char *D_004A4BC4;
int func_003F6EE0(int *out) {
    int err = 0; char *d;
    *out = 0;
    if (out == 0) err = 7;
    d = D_004A4BC4;
    if (*(unsigned *)(d + 0xD0) >= 4) err = 0xF;
    if (err == 0) {
        if (*(unsigned *)(D_004A4BC4 + 0xD8) < 9) err = ((int (*)(int *, char *))*(int *)(d + 0xDC))(out, d);
        else ((void (*)(int *, int *))*(int *)(D_004A4BC4 + 0xE8))(out, &err);
    }
    return err;
}

#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F6F68);

INCLUDE_ASM("seg/seg_2F41F8", func_003F71B8);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F71F8);
#ifdef SKIP_ASM
extern int func_003F7BD0(void);
int func_003F71F8(void) { return func_003F7BD0(); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7218);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern int f7A60c(int, int) __asm__("func_003F7A60");
int func_003F7218_impl(int *a, int *b) __asm__("func_003F7218");
int func_003F7218_impl(int *a, int *b) {
    int x; int err = 0xC;
    *a = 1;
    switch (*(unsigned *)(D_004A4BC4 + 0xD8)) {
    case 0: x = 1; break;
    case 1: { unsigned sel = *(unsigned *)(D_004A4BC4 + 0xD0);
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
extern char *D_004A4BC4;
extern int func_003F7BD0(void);
int func_003F72F8(int a, int *b) {
    *b = *(int *)(D_004A4BC4 + 0x148);
    *(int *)(D_004A4BC4 + 0x148) = 0;
    return func_003F7BD0();
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F7328);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F73A8);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern char D_004A4BC8[];
extern int func_003F77F8(void);
extern int func_003FC390_call(char *, int, int) __asm__("func_003FC390");
extern int func_003F8178(int);
int func_003F73A8(void) {
    char *p = D_004A4BC4;
    *(int (**)(void))(p + 0xFC) = func_003F77F8;
    *(int *)(p + 0x100) = 0;
    return func_003F8178(func_003FC390_call(D_004A4BC8, -1, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F73F0);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern char D_004A4BC8[];
extern int func_003F7820(void);
extern int func_003FC4C8(int, int, int);
extern int func_003F8178(int);
int func_003F73F0(void) {
    char *p = D_004A4BC4;
    *(int (**)(void))(p + 0xFC) = func_003F7820;
    *(int *)(p + 0x100) = 0;
    return func_003F8178(func_003FC4C8((int)D_004A4BC8, -1, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7438);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern char D_004A4BC8[];
extern int func_003FC3C0_call(char *, int, int) __asm__("func_003FC3C0");
extern int func_003F8178(int);
int func_003F7438(void) {
    char *p = D_004A4BC4;
    *(int *)(p + 0xFC) = 0;
    *(int *)(p + 0x100) = 0;
    return func_003F8178(func_003FC3C0_call(D_004A4BC8, -1, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7478);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern char fn7920[] __asm__("func_003F7920");
extern char fn78E0[] __asm__("func_003F78E0");
extern int func_003FCE10(char *, int, int, int);
extern int fC548(char *, int, int, int, int) __asm__("func_003FC548");
extern int func_003F8178(int);
typedef struct { char b[17]; } K17;
int func_003F7478(void) {
    int r;
    char *d = D_004A4BC4;
    *(char **)(d + 0xFC) = fn78E0;
    *(char **)(d + 0x100) = fn7920;
    r = func_003F8178(func_003FCE10(d + 0x144, *(int *)(d + 0x140), 0x11, 0));
    if (r == 0) {
        char *e = D_004A4BC4;
        K17 *dst = *(K17 **)(e + 0x144);
        *dst = *(K17 *)(e + 0xA8);
        r = func_003F8178(fC548(D_004A4BC4 + 0x44, 0x41434354, 0, *(int *)(D_004A4BC4 + 0x144), 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7528);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern char fn7958[] __asm__("func_003F7958");
extern char fn7900[] __asm__("func_003F7900");
extern int func_003FCE10(char *, int, int, int);
extern int fC548(char *, int, int, int, int) __asm__("func_003FC548");
extern int func_003F8178(int);
typedef struct { char b[17]; } K17b;
int func_003F7528(void) {
    int r;
    char *d = D_004A4BC4;
    *(char **)(d + 0xFC) = fn7900;
    *(char **)(d + 0x100) = fn7958;
    r = func_003F8178(func_003FCE10(d + 0x144, *(int *)(d + 0x140), 0x11, 0));
    if (r == 0) {
        char *e = D_004A4BC4;
        K17b *dst = *(K17b **)(e + 0x144);
        *dst = *(K17b *)(e + 0xB9);
        r = func_003F8178(fC548(D_004A4BC4 + 0x44, 0x50415353, 0, *(int *)(D_004A4BC4 + 0x144), 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F75D8);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern char fn7920[] __asm__("func_003F7920");
extern char fn7840[] __asm__("func_003F7840");
extern int func_003FCE10(char *, int, int, int);
extern int func_003FC708(char *, int, int, int, int);
extern int func_003F8178(int);
int func_003F75D8(void) {
    int r;
    char *d = D_004A4BC4;
    *(char **)(d + 0xFC) = fn7840;
    *(char **)(d + 0x100) = fn7920;
    r = func_003F8178(func_003FCE10(d + 0x144, *(int *)(d + 0x140), 0x11, 0));
    if (r == 0) {
        char *e = D_004A4BC4;
        r = func_003F8178(func_003FC708(e + 0x44, 0x41434354, 0, *(int *)(e + 0x144), 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7658);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern char fn7958[] __asm__("func_003F7958");
extern char fn7890[] __asm__("func_003F7890");
extern int func_003FCE10(char *, int, int, int);
extern int func_003FC708(char *, int, int, int, int);
extern int func_003F8178(int);
int func_003F7658(void) {
    int r;
    char *d = D_004A4BC4;
    *(char **)(d + 0xFC) = fn7890;
    *(char **)(d + 0x100) = fn7958;
    r = func_003F8178(func_003FCE10(d + 0x144, *(int *)(d + 0x140), 0x11, 0));
    if (r == 0) {
        char *e = D_004A4BC4;
        r = func_003F8178(func_003FC708(e + 0x44, 0x50415353, 0, *(int *)(e + 0x144), 0x11));
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F76D8);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern int func_003FC4E8(char *);
extern int func_003F8178(int);
int func_003F76D8(void) {
    char *p = D_004A4BC4;
    *(int *)(p + 0xFC) = 0;
    *(int *)(p + 0x100) = 0;
    return func_003F8178(func_003FC4E8(p + 0x44));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7708);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
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
            if (*(int *)(D_004A4BC4 + 0xFC)) {
                err = ((int (*)(void))*(int *)(D_004A4BC4 + 0xFC))();
                *(int *)(D_004A4BC4 + 0xFC) = 0;
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
        if (*(int *)(D_004A4BC4 + 0x100)) {
            err = ((int (*)(void))*(int *)(D_004A4BC4 + 0x100))();
            *(int *)(D_004A4BC4 + 0x100) = 0;
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
extern char *D_004A4BC4;
extern int func_003FC990(char *);
extern int func_003F8178(int);
int func_003F77F8(void) { return func_003F8178(func_003FC990(D_004A4BC4 + 0x44)); }
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
extern char *D_004A4BC4;
extern void func_003F7920b(int) __asm__("func_003F7920");
void func_003F7840(void) {
    S17b *dst = *(S17b **)(D_004A4BC4 + 0xCC);
    *dst = **(S17b **)(D_004A4BC4 + 0x144);
    func_003F7920b(0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7890);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern void func_003F7958b(int) __asm__("func_003F7958");
typedef struct { char c[17]; } S17;
void func_003F7890(void) {
    S17 *dst = (S17 *)(*(char **)(D_004A4BC4 + 0xCC) + 0x11);
    *dst = **(S17 **)(D_004A4BC4 + 0x144);
    func_003F7958b(0);
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
extern char *D_004A4BC4;
extern int func_003FCF00(int, int, int, int);
extern int func_003F8178(int);
int func_003F7920(int unused) { return func_003F8178(func_003FCF00(*(int *)(D_004A4BC4 + 0x144), *(int *)(D_004A4BC4 + 0x140), 0x11, 0)); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7958);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern int func_003FCF00(int, int, int, int);
extern int func_003F8178(int);
int func_003F7958(int unused) { return func_003F8178(func_003FCF00(*(int *)(D_004A4BC4 + 0x144), *(int *)(D_004A4BC4 + 0x140), 0x11, 0)); }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7990);
#ifdef SKIP_ASM
typedef struct { char pad0[0xD0]; unsigned f0D0; void *f0D4; int f0D8, f0DC, f0E0, f0E4; void *f0E8; int f0EC, f0F0, f0F4, f0F8, f0FC, f100; unsigned f104; } S7990;
extern S7990 *D_7990 __asm__("D_004A4BC4");
extern char fn6EE0[] __asm__("func_003F6EE0");
extern char fn7328[] __asm__("func_003F7328");
int f7990(unsigned a) __asm__("func_003F7990");
int f7990(unsigned a) {
    int r = 0;
    unsigned i;
    D_7990->f0D0 = a;
    D_7990->f104 = a;
    if (a < 4) {
        D_7990->f0D4 = fn6EE0;
    } else {
        r = 0xF;
    }
    D_7990->f0D8 = 9;
    D_7990->f0EC = 4;
    D_7990->f0E8 = fn7328;
    D_7990->f0E0 = 0;
    D_7990->f0E4 = 0;
    D_7990->f0DC = 0;
    for (i = 0; i < 3; i++)
        ;
    D_7990->f0F0 = 0;
    D_7990->f0F4 = 0;
    D_7990->f0F8 = 0;
    D_7990->f0FC = 0;
    D_7990->f100 = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7A30);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern int func_003F7BD0(void);
int func_003F7A30(void) {
    char *p = D_004A4BC4;
    *(int *)(p + 0xD0) = 4;
    *(int *)(p + 0xD4) = 0;
    *(int *)(p + 0xE8) = 0;
    return func_003F7BD0();
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F7A60);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7BD0);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern int func_003F7D98(void);
int func_003F7BD0(void) {
    char *p = D_004A4BC4;
    *(int *)(p + 0xD8) = 10;
    *(int *)(p + 0xDC) = 0;
    *(int *)(p + 0xE0) = 0;
    *(int *)(p + 0xE4) = 0;
    return func_003F7D98();
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F7C00);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F7D98);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
int func_003F7D98(void) {
    unsigned int i;
    int *p;
    char *g = D_004A4BC4;
    char *h;
    *(int *)(g + 0xEC) = 5;
    p = (int *)(g + 0xF0);
    for (i = 0; i < 3; i++) {
        *p++ = 0;
    }
    h = D_004A4BC4;
    *(int *)(h + 0xFC) = 0;
    *(int *)(h + 0x100) = 0;
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
extern char *D_004A4BC4;
extern void f7E90(char *, int, int) __asm__("func_003F7E90");
extern int f7DE0(int) __asm__("func_003F7DE0");
extern int f8258(int) __asm__("func_003F8258");
extern int f6E98(int) __asm__("func_003F6E98");
int func_003F7F48(int a, int b) {
    int err = 0;
    if (a == 0 && b == 0) {
        err = 7;
    } else {
        f7E90(D_004A4BC4 + 0xA8, b, 0x11);
        f7E90(D_004A4BC4 + 0xB9, b + 0x11, 0x11);
    }
    if (err == 0) {
        err = f7DE0(a);
        if (err == 0) {
            err = f8258(a);
            if (err == 0) err = f6E98(0);
        }
    }
    return err;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8000);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
extern int func_003F6E98(int);
int func_003F8000(int a) {
    int r = 0;
    if (a == 0) {
        r = 7;
    } else {
        *(int *)(D_004A4BC4 + 0xCC) = a;
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
extern char *D_004A4BC4;
extern char *func_003F7E90(char *, char *, int);
extern int func_003F6E98(int);
int func_003F8048(char *name) {
    int r = 0;
    if (name == 0) {
        r = 7;
    } else {
        func_003F7E90(D_004A4BC4 + 0xA8, name, 0x11);
        func_003F7E90(D_004A4BC4 + 0xB9, name + 0x11, 0x11);
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
extern char *D_80E0 __asm__("D_004A4BC4");
extern void f7A30(void) __asm__("func_003F7A30");
int func_003F80E0(int *out) {
    int err = 0;
    int v;
    if (out == 0) {
        err = 7;
    } else {
        *out = 0;
        if (*(int *)(D_80E0 + 0xD0) != 4) {
            err = ((int (*)(int *))*(int *)(D_80E0 + 0xD4))(out);
            if (err == 0) {
                v = *out;
                if (v == 2) {
                    f7A30();
                    *out = v;
                }
            } else {
                f7A30();
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
extern char *D_004A4BC4;
int func_003F8200(int *a0) { *a0 = *(int *)(D_004A4BC4 + 0x104); return 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8218);
#ifdef SKIP_ASM
extern char *D_004A4BC4;
int func_003F8218(int *a0) { *a0 = *(int *)(D_004A4BC4 + 0x10C); return 0; }
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

INCLUDE_ASM("seg/seg_2F41F8", func_003F85C0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F86B8);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F86F0);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
void func_003F86F0_impl(int a) __asm__("func_003F86F0");
void func_003F86F0_impl(int a) {
    int *p = D_004A4BD8;
    if ((unsigned)(p[0] - 11) >= 3) p[2] = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8710);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8710(void) { return D_004A4BD8[2]; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8720);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
extern int **D_004A4BDC_p __asm__("D_004A4BDC");
int func_003F8720(int a, int *out) {
    int *d;
    int **e;
    *out = 1;
    d = D_004A4BD8;
    e = D_004A4BDC_p;
    d[0] = 0xB;
    d[1] = 0x18;
    ((void (*)(int))e[0x38 / 4])(d[3]);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8768);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
extern int **D_004A4BDC_p __asm__("D_004A4BDC");
int func_003F8768(int a, int *out) {
    int *d;
    int **e;
    *out = 1;
    d = D_004A4BD8;
    e = D_004A4BDC_p;
    d[0] = 0xC;
    d[1] = 0x19;
    ((void (*)(int))e[0x1C / 4])(d[3]);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F87B0);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
extern int **D_004A4BDC_p __asm__("D_004A4BDC");
int func_003F87B0(int a, int *out) {
    int *d;
    int **e;
    *out = 1;
    d = D_004A4BD8;
    e = D_004A4BDC_p;
    d[0] = 0xD;
    d[1] = 0x1A;
    ((void (*)(int))e[0x14 / 4])(a);
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
extern int *D_004A4BD8;
int func_003F8800(int a) {
    if (D_004A4BD8[1] != 1) return 0x12;
    if (a != 0 && a != 3 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8838);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8838(int a) {
    if (D_004A4BD8[1] != 2) return 0x12;
    if (a != 0 && a != 4 && a != 3 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8880);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8880(int a) {
    int m = D_004A4BD8[1];
    if (m != 0x1B && m != 0x1D && m != 0x1C && m != 7 && m != 0xB && m != 0x18) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xE && a != 0xD && a != 0x11 && a != 0xA) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8908);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8908(int a) {
    int m = D_004A4BD8[1];
    if (m != 0x18 && m != 8 && m != 0xC && m != 0x10) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8968);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8968(int a) {
    int m = D_004A4BD8[1];
    if (m != 0x19 && m != 9 && m != 0xD && m != 0x11) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F89C8);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F89C8(int a) {
    if (D_004A4BD8[1] != 0x1A) return 0x12;
    if (a != 0 && a != 3 && a != 9 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8A08);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8A08(int a) {
    if (D_004A4BD8[1] != 5) return 0x12;
    if (a != 0 && a != 3 && a != 9 && a != 0xE && a != 8 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8A58);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8A58(int a) {
    int m = D_004A4BD8[1];
    if (m != 0x16 && m != 6 && m != 0xE && m != 0xA) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xD && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8AC0);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8AC0(int a) {
    if ((unsigned)(D_004A4BD8[1] - 0x13) >= 3) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xD && a != 6 && a != 5 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8B28);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8B28(int a) {
    if (D_004A4BD8[1] != 0x12) return 0x12;
    if (a != 0 && a != 3 && a != 4 && a != 9 && a != 0xD && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8B78);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8B78(int a) {
    int m = D_004A4BD8[1];
    if (m != 3) return 0x12;
    if (a != 0 && a != m && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8BB0);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8BB0(int a) {
    if (D_004A4BD8[1] != 4) return 0x12;
    if (a != 0 && a != 3 && a != 0x11) return 0x10;
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F8BE8);
#ifdef SKIP_ASM
extern int *D_004A4BD8;
int func_003F8BE8(int a) {
    if (D_004A4BD8[1] != 0x17) return 0x12;
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
extern int D_004A4BDC;
int func_003F9208(void) { return D_004A4BDC != 0; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F9218);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9530);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F95E8);
#ifdef SKIP_ASM
extern char *D_95E8 __asm__("D_004A4BD8");
int func_003F95E8(char *dst) {
    if (dst == 0) return 0xC;
    __builtin_memcpy(dst, D_95E8 + 0xC, 0x60);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F9698);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9818);

INCLUDE_ASM("seg/seg_2F41F8", func_003F99B8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9B38);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9C48);
#ifdef SKIP_ASM
extern int c9c48_9208(void) __asm__("func_003F9208");
extern void c9c48_86F0(int) __asm__("func_003F86F0");
extern int c9c48_A6E8(void) __asm__("func_003FA6E8");
extern int *D_9C48s __asm__("D_004A4BD8");
typedef struct { char pad[0x34]; void (*f34)(int, int, int); } E9C48;
extern E9C48 *D_9C48e __asm__("D_004A4BDC");
int func_003F9C48_impl(int *src, int a, int b) __asm__("func_003F9C48");
int func_003F9C48_impl(int *src, int a, int b) {
    int *s;
    int *t;
    int v;
    E9C48 *e;
    if (c9c48_9208() == 0) return 2;
    if (src == 0) return 0xC;
    s = D_9C48s;
    if (s[0] != 0) return 0xD;
    s[0] = 8;
    s[1] = 0x1B;
    c9c48_86F0(0);
    __builtin_memcpy((char *)D_9C48s + 0xC, (char *)src, 0x60);
    if (b == 0) {
        v = a + c9c48_A6E8();
        t = D_9C48s;
        e = D_9C48e;
        t[0x70 / 4] = v;
        e->f34(t[3], a + c9c48_A6E8(), 0);
    } else {
        int *d = D_9C48s;
        E9C48 *e2 = D_9C48e;
        d[0x70 / 4] = a;
        e2->f34(d[3], a, b);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9DC0);
#ifdef SKIP_ASM
extern int f9208(void) __asm__("func_003F9208");
extern void f86F0(int) __asm__("func_003F86F0");
extern int *D_9DC0s __asm__("D_004A4BD8");
typedef struct { char pad[0x2C]; void (*f2C)(int, int, int); } E9DC0;
extern E9DC0 *D_9DC0e __asm__("D_004A4BDC");
int func_003F9DC0_impl(int *src, int a, int b) __asm__("func_003F9DC0");
int func_003F9DC0_impl(int *src, int a, int b) {
    int *s;
    int *t;
    E9DC0 *e;
    if (f9208() == 0) return 2;
    if (src == 0) return 0xC;
    s = D_9DC0s;
    if (s[0] != 0) return 0xD;
    s[0] = 0xA;
    s[1] = 0x1D;
    f86F0(0);
    __builtin_memcpy((char *)D_9DC0s + 0xC, (char *)src, 0x60);
    t = D_9DC0s;
    e = D_9DC0e;
    t[0x70 / 4] = b;
    e->f2C(src[0], a, b);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F9F00);
#ifdef SKIP_ASM
extern int f9208(void) __asm__("func_003F9208");
extern void f86F0(int) __asm__("func_003F86F0");
extern int *D_9F00s __asm__("D_004A4BD8");
typedef struct { char pad[0x30]; void (*f30)(int, int, int); } E9F00;
extern E9F00 *D_9F00e __asm__("D_004A4BDC");
int func_003F9F00_impl(int *src, int a, int b) __asm__("func_003F9F00");
int func_003F9F00_impl(int *src, int a, int b) {
    int *s;
    int *t;
    E9F00 *e;
    if (f9208() == 0) return 2;
    if (src == 0) return 0xC;
    s = D_9F00s;
    if (s[0] != 0) return 0xD;
    s[0] = 9;
    s[1] = 0x1C;
    f86F0(0);
    __builtin_memcpy((char *)D_9F00s + 0xC, (char *)src, 0x60);
    t = D_9F00s;
    e = D_9F00e;
    t[0x70 / 4] = b;
    e->f30(src[0], a, b);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FA040);

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
extern int f9208(void) __asm__("func_003F9208");
extern char *D_A240 __asm__("D_004A4BDC");
extern void fA6A8(char *, char *, char *) __asm__("func_003FA6A8");
extern int fB308(char *) __asm__("func_003FB308");
int func_003FA240_impl(char *src) __asm__("func_003FA240");
int func_003FA240_impl(char *src) {
    if (src == 0) return 0xC;
    if (f9208() == 0) return 2;
    __builtin_memcpy(D_A240 + 0x50, src, 0x3D0);
    fA6A8(src, D_A240 + 0x420, D_A240 + 0x424);
    return fB308(src);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FA360);
#ifdef SKIP_ASM
extern int func_3FB278(void);
int func_003FA360(void) { return func_003FB278(); }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FA380);

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
extern int strlen(const char *);
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
extern int strlen(const char *);
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
extern unsigned D_3A0[] __asm__("D_00451518");
extern int func_00266728(int, int, int);
extern void func_003FB358b(int) __asm__("func_003FB358");
int func_003FB3A0(unsigned a) {
    int r;
    if (D_3A0[0] != 0) return 5;
    r = func_00266728(a, 0x400, 4);
    D_3A0[0] = r;
    if (r == 0) return 1;
    D_3A0[4] = a;
    func_003FB358b(r);
    D_3A0[1] = 4;
    D_3A0[3] = 0xFFFFFFFF;
    D_3A0[2] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB430);
#ifdef SKIP_ASM
extern int D_00451518[];
extern int func_00266760(int, char *, int, int);
int func_003FB430(void) {
    int *p = D_00451518;
    if (D_00451518[0] == 0) return 6;
    func_00266760(p[4], (char *)p[0], 0x400, 4);
    D_00451518[0] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB480);
#ifdef SKIP_ASM
extern int D_00451518[];
int func_003FB480(void) { return D_00451518[0] != 0; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB490);
#ifdef SKIP_ASM
extern int D_00451518[];
int func_003FB490(void) {
    unsigned long long v = 0xFFFFFFFF;
    if (D_00451518[0] == 0) return 6;
    D_00451518[3] = v;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB4C0);
#ifdef SKIP_ASM
extern unsigned D_4C0[] __asm__("D_00451518");
int func_003FB4C0(unsigned char *buf, unsigned n) {
    unsigned crc = D_4C0[3];
    unsigned i;
    if (D_4C0[0] == 0) return 6;
    if (buf == 0) return 2;
    for (i = 0; i < n; i++)
        crc = ((crc >> 8) & 0xFFFFFF) ^ ((unsigned *)D_4C0[0])[(crc ^ buf[i]) & 0xFF];
    D_4C0[3] = crc;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB558);
#ifdef SKIP_ASM
extern int D_00451518[];
extern int D_004A5B1C;
int func_003FB558(int **out) {
    int *p = D_00451518;
    if (D_00451518[0] == 0) return 6;
    if (out == 0) return 2;
    p[2] = (int)&D_004A5B1C;
    p[1] = 4;
    D_004A5B1C = ~p[3];
    *out = &p[1];
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB5B0);
#ifdef SKIP_ASM
extern int D_00451518[];
int func_003FB5B0(int *out) {
    if (D_00451518[0] == 0) return 6;
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
extern int D_004A4BF0;
int func_003FB5F8(void) {
    if (D_004A4BF0 != 4) return 3;
    D_004A4BF0 = 6;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB620);
#ifdef SKIP_ASM
extern int D_004A4BE4, D_004A4BE8, D_004A4BEC, D_004A4BF0;
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
extern int D_004A4BF0;
int func_003FB640(void) { return D_004A4BF0 != 4; }
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB650);
#ifdef SKIP_ASM
extern int D_004A4BE4, D_004A4BE8, D_004A4BEC, D_004A4BF0;
int func_003FB650(int a, int b) {
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
extern int D_004A4BF0;
extern unsigned char *pEC __asm__("D_004A4BEC");
extern unsigned char *pE8 __asm__("D_004A4BE8");
extern unsigned char *pE4 __asm__("D_004A4BE4");
int func_003FB6A0(unsigned char *buf, unsigned n) {
    unsigned i;
    if (buf == 0 || n == 0) return 2;
    if (D_004A4BF0 != 5 && D_004A4BF0 != 7) return D_004A4BF0;
    for (i = 0; i < n; i++) {
        buf[i] ^= *pEC;
        if (pEC == pE8) pEC = pE4;
        else pEC = pEC + 1;
    }
    D_004A4BF0 = 7;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB730);
#ifdef SKIP_ASM
extern int D_004A4BF0;
extern unsigned char *pEC __asm__("D_004A4BEC");
extern unsigned char *pE8 __asm__("D_004A4BE8");
extern unsigned char *pE4 __asm__("D_004A4BE4");
int func_003FB730(unsigned char *buf, unsigned n) {
    unsigned i;
    if (buf == 0 || n == 0) return 2;
    if (D_004A4BF0 != 5 && D_004A4BF0 != 8) return D_004A4BF0;
    for (i = 0; i < n; i++) {
        buf[i] ^= *pEC;
        if (pEC == pE8) pEC = pE4;
        else pEC = pEC + 1;
    }
    D_004A4BF0 = 8;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB7C0);
#ifdef SKIP_ASM
extern int D_004A4BE4, D_004A4BEC, D_004A4BF0;
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
typedef struct { int key; int a, b, c; } E3FBA20;
typedef struct { char pad[0x94]; int count; int pad2; E3FBA20 *arr; } S3FBA20;
extern S3FBA20 *D_5B20 __asm__("D_004A5B20");
E3FBA20 *func_003FBA20(int key, int n) {
    S3FBA20 *s = D_5B20;
    E3FBA20 *end = s->arr + s->count;
    E3FBA20 *e = s->arr;
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
typedef struct { int key; int a, b, c; } E3FBA78;
typedef struct { char pad[0x94]; int count; int pad2; E3FBA78 *arr; } S3FBA78;
extern S3FBA78 *D_5B20b __asm__("D_004A5B20");
void func_003FBA78(int key, int n, int *val) {
    S3FBA78 *s = D_5B20b;
    E3FBA78 *end = s->arr + s->count;
    E3FBA78 *e = s->arr;
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
typedef struct { char pad[0xC]; int (*f0)(int, int, int); int (*f1)(int, int); int (*f2)(int); } V3FBB50;
typedef struct { char pad[0x70]; V3FBB50 *vt; } S3FBB50;
extern S3FBB50 *D_BB50 __asm__("D_004A5B20");
extern int func_003FB840c(int) __asm__("func_003FB840");
int func_003FBB50_impl(int a, int b, int c) __asm__("func_003FBB50");
int func_003FBB50_impl(int a, int b, int c) {
    V3FBB50 *vt = D_BB50->vt;
    int r = vt->f0(a, b, c);
    if (r == 0) {
        r = vt->f1(a, b);
        if (r == 0) {
            r = vt->f2(c);
            if (r == 0) return 0;
        }
    }
    return func_003FB840c(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBBE0);
#ifdef SKIP_ASM
typedef struct { char c[4]; } S4;
extern int D_004A5B20;
extern int func_003FBB50(int, int, int **);
void func_003FBBE0(S4 *out) {
    char *s = (char *)D_004A5B20;
    int *r;
    int sz = *(int *)(s + 0x94) << 4;
    if (sz == 0) {
        *(int *)out = 0;
    } else {
        func_003FBB50(*(int *)(s + 0x9C), sz, &r);
        *out = *(S4 *)r[1];
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBC40);
#ifdef SKIP_ASM
typedef struct { char pad[0xC]; int (*f0)(int, int); int (*f1)(int, int); int (*f2)(int, int); int (*f3)(void); } V3FBC40;
typedef struct { char pad[0x64]; int a; int b; V3FBC40 *vt; } S3FBC40;
extern S3FBC40 *D_BC40 __asm__("D_004A5B20");
extern int fB828b(int) __asm__("func_003FB828");
int func_003FBC40_impl(int x, int y) __asm__("func_003FBC40");
int func_003FBC40_impl(int x, int y) {
    int r;
    if (D_BC40->vt == 0) return 0;
    r = D_BC40->vt->f0(D_BC40->a, D_BC40->b);
    if (r == 0) {
        r = D_BC40->vt->f1(x, y);
        if (r == 0) {
            r = D_BC40->vt->f3();
            if (r == 0) return 0;
        }
    }
    return fB828b(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBCD8);
#ifdef SKIP_ASM
typedef struct { char pad[0xC]; int (*f0)(int, int); int (*f1)(int, int); int (*f2)(int, int); int (*f3)(void); } V3FBCD8;
typedef struct { char pad[0x64]; int a; int b; V3FBCD8 *vt; } S3FBCD8;
extern S3FBCD8 *D_BCD8 __asm__("D_004A5B20");
extern int fB828(int) __asm__("func_003FB828");
int func_003FBCD8_impl(int x, int y) __asm__("func_003FBCD8");
int func_003FBCD8_impl(int x, int y) {
    int r;
    if (D_BCD8->vt == 0) return 0;
    r = D_BCD8->vt->f0(D_BCD8->a, D_BCD8->b);
    if (r == 0) {
        r = D_BCD8->vt->f2(x, y);
        if (r == 0) {
            r = D_BCD8->vt->f3();
            if (r == 0) return 0;
        }
    }
    return fB828(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBD70);
#ifdef SKIP_ASM
extern int D_004A5B20;
extern int func_003F99B8(int, int, int);
extern int func_003FB810b(int) __asm__("func_003FB810");
int func_003FBD70(int a, int b, int c, int d) {
    int r = func_003F99B8(a, b, c);
    char *p = (char *)D_004A5B20;
    *(int *)(p + 0x74) = d;
    *(int *)(p + 0x78) = 4;
    *(int *)(p + 0x94) = 0;
    *(int *)(p + 0x98) = 0;
    return func_003FB810b(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBDB8);
#ifdef SKIP_ASM
extern int D_004A5B20;
extern int func_003F9C48(int, int, int);
extern int func_003FB810b(int) __asm__("func_003FB810");
int func_003FBDB8(void) {
    int p = D_004A5B20;
    *(int *)(p + 0x78) = 9;
    return func_003FB810b(func_003F9C48(p, 0, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBDF0);
#ifdef SKIP_ASM
extern int D_004A5B20;
extern int func_003FB898(int, int);
extern int func_003F9DC0(int, int, int);
extern int func_003FB810b(int) __asm__("func_003FB810");
int func_003FBDF0(void) {
    char *p = (char *)D_004A5B20;
    *(int *)(p + 0x78) = 7;
    return func_003FB810b(func_003F9DC0(D_004A5B20, *(int *)(p + 0x80), func_003FB898(0, 1)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBE40);
#ifdef SKIP_ASM
typedef struct { char pad[0x78]; int st; int pad2; int h; int pad3; char buf[0x10]; int cnt; } S3FBE40;
extern S3FBE40 *D_BE40 __asm__("D_004A5B20");
extern int fBCD8(int, int) __asm__("func_003FBCD8");
extern void fB9D0(int, int *, int *, char *) __asm__("func_003FB9D0");
extern int fBAD0(int, int, char *) __asm__("func_003FBAD0");
extern int f9C48(S3FBE40 *, int, int) __asm__("func_003F9C48");
extern int fB810x(int) __asm__("func_003FB810");
int func_003FBE40(void) {
    int x[2];
    int r;
    int p, q;
    x[1] = 0;
    D_BE40->st = 0xB;
    r = fBCD8(D_BE40->h, 0xC);
    if (r != 0) return r;
    fB9D0(D_BE40->h, &x[0], &x[1], D_BE40->buf);
    q = x[1];
    p = x[0];
    r = fBAD0(p, q, D_BE40->buf);
    if (D_BE40->cnt == r) return 5;
    return fB810x(f9C48(D_BE40, D_BE40->cnt, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBED0);
#ifdef SKIP_ASM
typedef struct { char pad[0x78]; int st; int h; int pad2; int a; char buf[4]; int c; } S3FBED0;
extern S3FBED0 *D_BED0 __asm__("D_004A5B20");
extern int fB910(int, int) __asm__("func_003FB910");
extern void fB958(int, int, int, char *) __asm__("func_003FB958");
extern int fBC40(int, int) __asm__("func_003FBC40");
extern int fB898(int, int) __asm__("func_003FB898");
extern int f9F00(S3FBED0 *, int, int) __asm__("func_003F9F00");
extern int fB810(int) __asm__("func_003FB810");
int func_003FBED0(void) {
    int h;
    int r;
    D_BED0->st = 6;
    h = fB910(D_BED0->h, 1);
    if (h == 0) return 4;
    fB958(h, D_BED0->c, D_BED0->a, D_BED0->buf);
    r = fBC40(h, 0xC);
    if (r != 0) return r;
    r = fBC40(D_BED0->h, D_BED0->a);
    if (r != 0) return r;
    r = fB898(D_BED0->a, 2);
    return fB810(f9F00(D_BED0, h, r));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBF80);
#ifdef SKIP_ASM
extern int D_004A5B20;
extern int func_003FB898(int, int);
extern int func_003F9DC0(int, int, int);
extern int func_003FB810b(int) __asm__("func_003FB810");
int func_003FBF80(void) {
    char *p = (char *)D_004A5B20;
    int r;
    *(int *)(p + 0x78) = 10;
    r = func_003FB910(*(int *)(p + 0x7C), 0);
    return func_003FB810b(func_003F9DC0(D_004A5B20, r, func_003FB898(*(int *)((char *)D_004A5B20 + 0x84), 1)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FBFE0);
#ifdef SKIP_ASM
typedef struct { char pad[0x78]; int st; int h; int pad2; int a; char buf[4]; int c; } S3FBFE0;
typedef struct { int tag; int p; } P3FBFE0;
typedef struct { int a; int b; P3FBFE0 *p; } L3FBFE0;
extern S3FBFE0 *D_BFE0 __asm__("D_004A5B20");
extern int fB910(int, int) __asm__("func_003FB910");
extern int fBCD8(int, int) __asm__("func_003FBCD8");
extern void fB9D0(int, int *, int *, char *) __asm__("func_003FB9D0");
extern int fBB50(int, int, P3FBFE0 **) __asm__("func_003FBB50");
extern int f5FC8(int, char *, int) __asm__("func_00415FC8");
int func_003FBFE0(void) {
    L3FBFE0 x; int h; int r; int err = 0xA; int hh;
    x.p = 0; hh = D_BFE0->h; x.b = 0;
    D_BFE0->st = err;
    h = fB910(hh, 0);
    r = fBCD8(h, 0xC);
    if (r != 0) return r;
    fB9D0(h, &x.a, &x.b, D_BFE0->buf);
    if (x.a != D_BFE0->c) return 0xB;
    if (x.b != D_BFE0->a) return 0x6E;
    r = fBCD8(D_BFE0->h, x.b);
    if (r != 0) return r;
    r = fBB50(D_BFE0->h, D_BFE0->a, &x.p);
    if (r != 0) return r;
    if (x.p->tag != 4) return 0xB;
    if (f5FC8(x.p->p, D_BFE0->buf, 4) == 0) err = 0;
    return err;
}

#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC0D8);
#ifdef SKIP_ASM
extern int D_004A5B20;
int func_003FC0D8(void) { return D_004A5B20 != 0; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FC0E8);

INCLUDE_ASM("seg/seg_2F41F8", func_003FC260);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC390);
#ifdef SKIP_ASM
extern int D_004A5B20;
extern int func_003F9818(void);
extern void func_003FB810(int);
void func_003FC390(void) {
    char *p = (char *)D_004A5B20;
    *(int *)(p + 0x74) = 1;
    *(int *)(p + 0x78) = 1;
    func_003FB810(func_003F9818());
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC3C0);
#ifdef SKIP_ASM
extern int D_004A5B20;
extern int func_003F9698(void);
extern void func_003FB810(int);
void func_003FC3C0(void) {
    char *p = (char *)D_004A5B20;
    *(int *)(p + 0x74) = 2;
    *(int *)(p + 0x78) = 2;
    func_003FB810(func_003F9698());
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC3F0);
#ifdef SKIP_ASM
typedef struct { int w[25]; } K100b;
extern K100b *D_C3F0 __asm__("D_004A5B20");
extern int fBD70(char *, int, int, int) __asm__("func_003FBD70");
int func_003FC3F0_impl(K100b *a) __asm__("func_003FC3F0");
int func_003FC3F0_impl(K100b *a) {
    *D_C3F0 = *a;
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
extern int D_004A5B20;
extern int func_003F9B38(char *);
extern int func_003FB810b(int) __asm__("func_003FB810");
extern void func_003FBBE0b(char *) __asm__("func_003FBBE0");
int func_003FC4E8(char *x) {
    char *p;
    func_003FBBE0b(x + 0x60);
    *(int *)((char *)D_004A5B20 + 0x60) = *(int *)(x + 0x60);
    p = (char *)D_004A5B20;
    *(int *)(p + 0x74) = 3;
    *(int *)(p + 0x78) = 3;
    *(int *)(p + 0x98) = 0;
    *(int *)(p + 0x94) = 0;
    return func_003FB810b(func_003F9B38(x));
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FC548);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC708);
#ifdef SKIP_ASM
typedef struct { int w[25]; } B3FC708;
typedef struct { B3FC708 b; char pad[0x74 - 0x64]; int f74; int f78; int f7C; int f80; int f84; int f88; int f8C; char pad2[0x14]; int fA4; } S3FC708;
typedef struct { int f0; int f4; int f8; } R3FC708;
extern S3FC708 *D_C708 __asm__("D_004A5B20");
extern R3FC708 *c708_BA20(int, int) __asm__("func_003FBA20");
extern int c708_9C48(void *, int, int) __asm__("func_003F9C48");
extern int c708_B810(int) __asm__("func_003FB810");
int func_003FC708_impl(B3FC708 *src, int a, int b, int c, int d) __asm__("func_003FC708");
int func_003FC708_impl(B3FC708 *src, int a, int b, int c, int d) {
    S3FC708 *s = D_C708;
    R3FC708 *r;
    int v;
    s->f74 = 8;
    s->f78 = 5;
    s->b = *src;
    D_C708->f7C = c;
    D_C708->f8C = a;
    D_C708->f84 = d;
    r = c708_BA20(a, b);
    if (r == 0) return 7;
    if (d != r->f8) return 0x6E;
    v = r->f4;
    D_C708->fA4 = v;
    return c708_B810(c708_9C48(src, v, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC850);
#ifdef SKIP_ASM
typedef struct { int key; int a, b, c; } E3FC850;
typedef struct { char pad[0x94]; int count; int pad2; E3FC850 *arr; } S3FC850;
extern S3FC850 *D_C850 __asm__("D_004A5B20");
extern int fC0D8(void) __asm__("func_003FC0D8");
int func_003FC850_impl(int a, int key, int *out) __asm__("func_003FC850");
int func_003FC850_impl(int a, int key, int *out) {
    S3FC850 *s;
    E3FC850 *e, *end;
    if (!fC0D8()) return 2;
    if (a == 0) return 4;
    if (out == 0) return 4;
    *out = 0;
    s = D_C850;
    end = s->arr + s->count;
    e = s->arr;
    for (; e < end; e++) {
        if (key == e->key) *out = *out + 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC8F8);
#ifdef SKIP_ASM
extern int fC0D8(void) __asm__("func_003FC0D8");
extern int *fBA20(int, int) __asm__("func_003FBA20");
int func_003FC8F8_impl(int a, int b, int c, int *out) __asm__("func_003FC8F8");
int func_003FC8F8_impl(int a, int b, int c, int *out) {
    int err = 0;
    int *e;
    if (!fC0D8()) return 2;
    if (a == 0) return 4;
    if (out == 0) return 4;
    *out = 0;
    e = fBA20(b, c);
    if (e) *out = e[2];
    else err = 7;
    return err;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FC990);
#ifdef SKIP_ASM
typedef struct { int w[25]; } K100;
extern K100 *D_C990 __asm__("D_004A5B20");
int func_003FC990_impl(K100 *dst) __asm__("func_003FC990");
int func_003FC990_impl(K100 *dst) {
    if (dst == 0) return 4;
    *dst = *D_C990;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FCA40);
