#include "common.h"

INCLUDE_ASM("seg/seg_2F41F8", func_003F31F8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F33B0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F3530);

INCLUDE_ASM("seg/seg_2F41F8", func_003F35D0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F3748);

INCLUDE_ASM("seg/seg_2F41F8", func_003F3860);

INCLUDE_ASM("seg/seg_2F41F8", func_003F3940);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F3B18);

INCLUDE_ASM("seg/seg_2F41F8", func_003F3BC8);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F4118);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F42A0);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4330);
#ifdef SKIP_ASM
extern int func_003F4DE8(void);
int func_003F4330(void) { return func_003F4DE8(); }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F4350);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F43D0);
#ifdef SKIP_ASM
int func_003F43D0(int a, ...) { return 1; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F4410);

INCLUDE_ASM("seg/seg_2F41F8", func_003F4448);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F4D68);

INCLUDE_ASM("seg/seg_2F41F8", func_003F4DE8);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F4E80);
#ifdef SKIP_ASM
extern int func_00424698(int, int);
int func_003F4E80(int a0, int a1) { return func_00424698(a0, a0 + a1); }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F4EA0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F55B8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5638);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5738);

INCLUDE_ASM("seg/seg_2F41F8", func_003F57C8);

void func_003F5908(void) {
}

INCLUDE_ASM("seg/seg_2F41F8", func_003F5910);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5A50);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5A70);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5C38);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F5D88);
#ifdef SKIP_ASM
extern int func_003F4DE8(void);
int func_003F5D88(void) { return func_003F4DE8(); }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F5DA8);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F5F08);

INCLUDE_ASM("seg/seg_2F41F8", func_003F5F88);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F60B8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F6138);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F6358);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F63E0);
#ifdef SKIP_ASM
extern int D_00526038[];
void func_003F63E0(int a0) { D_00526038[0] = a0; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F63F0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F6670);

INCLUDE_ASM("seg/seg_2F41F8", func_003F6700);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F6838);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F6960);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F6DC8);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F6EE0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F6F68);

INCLUDE_ASM("seg/seg_2F41F8", func_003F71B8);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003F71F8);
#ifdef SKIP_ASM
extern int func_003F7BD0(void);
int func_003F71F8(void) { return func_003F7BD0(); }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003F7218);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F7478);

INCLUDE_ASM("seg/seg_2F41F8", func_003F7528);

INCLUDE_ASM("seg/seg_2F41F8", func_003F75D8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F7658);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F7708);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F7990);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F7DE0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F7F48);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F80E0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F8178);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F87B0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003F95E8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9698);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9818);

INCLUDE_ASM("seg/seg_2F41F8", func_003F99B8);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9B38);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9C48);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9DC0);

INCLUDE_ASM("seg/seg_2F41F8", func_003F9F00);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FA240);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FA708);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FA818);

INCLUDE_ASM("seg/seg_2F41F8", func_003FA8F8);

INCLUDE_ASM("seg/seg_2F41F8", func_003FAE50);

//100%
INCLUDE_ASM("seg/seg_2F41F8", func_003FB278);
#ifdef SKIP_ASM
int func_003FB278(void) { return 1; }
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FB280);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FB3A0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FB4C0);

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
    D_004A4BEC = a;
    D_004A4BE8 = a + b - 1;
    D_004A4BE4 = a;
    D_004A4BF0 = 5;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2F41F8", func_003FB6A0);

INCLUDE_ASM("seg/seg_2F41F8", func_003FB730);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FBB50);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FBC40);

INCLUDE_ASM("seg/seg_2F41F8", func_003FBCD8);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FBE40);

INCLUDE_ASM("seg/seg_2F41F8", func_003FBED0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FBFE0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FC3F0);

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

INCLUDE_ASM("seg/seg_2F41F8", func_003FC708);

INCLUDE_ASM("seg/seg_2F41F8", func_003FC850);

INCLUDE_ASM("seg/seg_2F41F8", func_003FC8F8);

INCLUDE_ASM("seg/seg_2F41F8", func_003FC990);

INCLUDE_ASM("seg/seg_2F41F8", func_003FCA40);
