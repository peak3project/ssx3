#include "common.h"

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBAE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char *func_004187E8_BAE8(void *, void *, unsigned int, int, void *) __asm__("func_004187E8");
extern char func_003DBAC8_BAE8[] __asm__("func_003DBAC8");

int func_003DBAE8_impl(short key, unsigned char *p) __asm__("func_003DBAE8");
int func_003DBAE8_impl(short key, unsigned char *p) {
    short k = key;
    unsigned char *n = p + 8;
    unsigned char *r;
    r = func_004187E8_BAE8(&k, p + 0x10, (n[3] << 24) | (n[2] << 16) | (n[1] << 8) | n[0], 4, func_003DBAC8_BAE8);
    if (r == 0) {
        return -1;
    }
    r += 2;
    return (r[1] << 8) | r[0];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBB68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003DBAE8_BB68(int, unsigned char *) __asm__("func_003DBAE8");
typedef struct { unsigned char b[4]; } W_BB68;
static inline unsigned rd_BB68(unsigned char *p) {
    return p[3] << 24 | p[2] << 16 | p[1] << 8 | p[0];
}
unsigned char *func_003DBB68(unsigned char *a, int idx) {
    unsigned char *h;
    if (a[8] & 1) {
        idx = func_003DBAE8_BB68(idx & 0xFFFF, a + rd_BB68(a + 4));
    }
    h = a + rd_BB68((unsigned char *)((W_BB68 *)(a + 0x10) + (a[0xF] << 8 | a[0xE])));
    if (idx >= 0 && (unsigned)idx < rd_BB68(h + 0xC)) {
        h += rd_BB68((unsigned char *)((W_BB68 *)(h + 0x10) + idx));
    } else {
        h = 0;
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBC98);
#ifdef SKIP_ASM
int func_003DBC98(int arg0) {
    return arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", USTR_length);
#ifdef SKIP_ASM
int USTR_length(unsigned short *arg0) {
    int var_3;
    unsigned short *var_4;

    var_4 = arg0;
    var_3 = 0;
    if (*var_4 != 0) {
        do {
            var_4 += 1;
            var_3 += 1;
        } while (*var_4 != 0);
    }
    return var_3;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBCD8);
#ifdef SKIP_ASM
int func_003DBCD8(unsigned short *arg0, int arg1) {
    int i;
    unsigned short key = arg1;

    i = 0;
    if (*arg0 != 0) {
        do {
            if (*arg0 == key) {
                return i;
            }
            arg0++;
            i++;
        } while (*arg0 != 0);
    }
    return 0xFFFF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBD18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int USTR_length_BD18(const unsigned short *) __asm__("USTR_length");
extern int func_003DBDD0_BD18(const unsigned short *, const unsigned short *, int) __asm__("func_003DBDD0");

/* Index of sub in s (UCS-2), or 0xFFFF. */
int func_003DBD18_impl(const unsigned short *s, const unsigned short *sub) __asm__("func_003DBD18");
int func_003DBD18_impl(const unsigned short *s, const unsigned short *sub) {
    int n = USTR_length_BD18(sub);
    int i;
    for (i = 0; s[i] != 0; i++) {
        if (func_003DBDD0_BD18(&s[i], sub, n) == 0) {
            return i;
        }
    }
    return 0xFFFF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBDB0);
#ifdef SKIP_ASM
extern void func_003DBDD0(int, int, int);

void func_003DBDB0(int a, int b) {
    func_003DBDD0(a, b, 0x7FFFFFFF);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBDD0);
#ifdef SKIP_ASM
/* UCS-2 strncmp. */
int func_003DBDD0_impl(const unsigned short *a, const unsigned short *b, int n) __asm__("func_003DBDD0");
int func_003DBDD0_impl(const unsigned short *a, const unsigned short *b, int n) {
    int i;
    int d = 0;
    for (i = 0; i < n; i++, b++, a++) {
        if (d != 0) {
            break;
        }
        d = *a - *b;
        if (*a == 0) {
            break;
        }
    }
    return d;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", USTR_copy);
#ifdef SKIP_ASM
extern void USTR_ncopy(int, int, int);

void USTR_copy(int a, int b) {
    USTR_ncopy(a, b, 0x7FFFFFFF);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", USTR_ncopy);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBE90);
#ifdef SKIP_ASM
void func_003DBE90(short *arg0, signed char *arg1) {
    short *var_3;
    int var_6;
    signed char *var_5;
    unsigned char temp_2;

    var_5 = arg1;
    var_6 = 0;
    if (*var_5 != 0) {
        var_3 = arg0;
        do {
            temp_2 = *var_5;
            var_6 += 1;
            var_5 += 1;
            *var_3 = (short) temp_2;
            var_3 += 1;
        } while (*var_5 != 0);
    }
    arg0[var_6] = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBED0);
#ifdef SKIP_ASM
extern void func_003DBEF0(int, int, int, int);

void func_003DBED0(int a, int b, int c) {
    func_003DBEF0(a, b, c, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBEF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void ucopy_BEF0(unsigned short *, unsigned short *) __asm__("USTR_copy");
extern int ulen_BEF0(unsigned short *) __asm__("USTR_length");

void fBEF0_BEF0(unsigned short *d, unsigned short *s, unsigned short *a2, unsigned short *a3) __asm__("func_003DBEF0");
void fBEF0_BEF0(unsigned short *d, unsigned short *s, unsigned short *a2, unsigned short *a3) {
    unsigned short c, c2;
    unsigned short *a;
    c = *s;
    if (c != 0) {
        do {
            if (c != 0x25) {
                *d++ = *s++;
            } else {
                c2 = s[1];
                if (c2 == 0x31) {
                    ucopy_BEF0(d, a2);
                    s += 2;
                    a = a2;
                    d += ulen_BEF0(a);
                } else if (c2 == 0x32) {
                    ucopy_BEF0(d, a3);
                    s += 2;
                    a = a3;
                    d += ulen_BEF0(a);
                } else {
                    *d++ = *s++;
                }
            }
            c = *s;
        } while (c != 0);
    }
    *d = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DBFD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
unsigned short *func_003DBFD8_BFD8(unsigned short *out, unsigned int n, unsigned int base, unsigned short *digits) __asm__("func_003DBFD8");
unsigned short *func_003DBFD8_BFD8(unsigned short *out, unsigned int n, unsigned int base, unsigned short *digits) {
    if (n == 0) {
        *--out = digits[0];
    } else {
        do {
            *--out = digits[n % base];
            n /= base;
        } while (n != 0);
    }
    return out;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DC038);
#ifdef SKIP_ASM
extern void func_003DBFD8(int, int);

void func_003DC038(int arg0, int arg1) {
    if (arg1 < 0) {
        arg1 = -arg1;
    }
    func_003DBFD8(arg0, arg1);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DC068);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DC148);

INCLUDE_ASM("ealib/seg_2DCAE8", USTR_vsprintf);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DC9F8);
#ifdef SKIP_ASM
extern void USTR_vsprintf(char *, const char *, char *);

// PORT: SN-specific va_start
void func_003DC9F8(char *dst, const char *fmt, ...) {
    char *ap;
    ap = (char*)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    USTR_vsprintf(dst, fmt, ap);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCA40);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCB20);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCBD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003DCC88_CBD8(int, int, int, int) __asm__("func_003DCC88");
extern int func_003DCD98_CBD8(int, int, int) __asm__("func_003DCD98");
extern int (*D_00450C10_CBD8[])(char *, int, int) __asm__("D_00450C10");
extern char D_00495D28_CBD8[] __asm__("D_00495D28");
extern int D_00519AB0_CBD8[] __asm__("D_00519AB0");
extern int D_00519AE8_CBD8[] __asm__("D_00519AE8");

int func_003DCBD8(int arg0, int arg1, int arg2) {
    int r;
    if (D_00519AB0_CBD8[0] == 0) {
        r = D_00450C10_CBD8[1](D_00495D28_CBD8, func_003DCD98_CBD8(arg0, arg1, arg2), 0x100);
        D_00519AE8_CBD8[0] = r;
        return func_003DCC88_CBD8(arg0, arg1, arg2, r);
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCC88);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCD98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450C5C_CD98[] __asm__("D_00450C5C");

int func_003DCD98(int a, int b, int c) {
    int x = a ? a : 0x10;
    int y = b ? b : 0x3E8;
    int z = c ? c : 0x20;
    int sz = D_00450C5C_CD98[0] + 0xC;
    return z * 0x30 + x * 0x110 + y * sz + 0x40;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCDE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E44B0_CDE0(void) __asm__("func_003E44B0");
extern void func_003DECA0_CDE0(int, int) __asm__("func_003DECA0");
extern void func_003E56E0_CDE0(char *) __asm__("func_003E56E0");
extern void func_003E6220_CDE0(char *, int) __asm__("func_003E6220");
extern void (*D_00450C10_CDE0[])(int) __asm__("D_00450C10");
extern void (*D_00450C18_CDE0[])(int) __asm__("D_00450C18");
extern char D_00519AC4_CDE0[] __asm__("D_00519AC4");
extern int *D_00519AE4_CDE0[] __asm__("D_00519AE4");
extern int D_00519AE8_CDE0[] __asm__("D_00519AE8");

void func_003DCDE0(void) {
    int *n;
    func_003E44B0_CDE0();
    for (n = D_00519AE4_CDE0[0]; n != 0; n = (int *)n[5]) {
        D_00450C10_CDE0[2](n[0]);
        func_003DECA0_CDE0(*(int *)n[3], 0);
    }
    func_003E56E0_CDE0(D_00519AC4_CDE0);
    func_003E6220_CDE0(D_00519AC4_CDE0 - 0x14, 0x38);
    if (D_00519AE8_CDE0[0] != 0) {
        D_00450C18_CDE0[0](D_00519AE8_CDE0[0]);
        D_00519AE8_CDE0[0] = 0;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCE90);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCF10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519AD8_CF10[] __asm__("D_00519AD8");
typedef struct { unsigned char a, b, c, d; } T_CF10;

int func_003DCF10(T_CF10 arg0) {
    return *(int *)((char*)(D_00519AD8_CF10[0]) + arg0.d * 0x30 + 0xC);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCF40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519AD8_CF40[] __asm__("D_00519AD8");
typedef struct { unsigned char a, b, c, d; } T_CF40;

int func_003DCF40(T_CF40 arg0) {
    return *(int *)((char*)(D_00519AD8_CF40[0]) + arg0.d * 0x30 + 0x14);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCF70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef void (*Fn_CF70)(int, int, int);
struct E_CF70 { int f0; int f4; volatile int f8; int fC; int f10; int f14; char pad[0x10]; Fn_CF70 fn; int pad2; };
extern struct E_CF70 *D_00519AD8_CF70 __asm__("D_00519AD8");

void func_003DCF70_impl(int h, Fn_CF70 fn) __asm__("func_003DCF70");
void func_003DCF70_impl(int h, Fn_CF70 fn) {
    struct E_CF70 *e = &D_00519AD8_CF70[((unsigned char *)&h)[3]];
    e->fn = fn;
    if (e->f8 != 0) {
        fn(h, e->f8, e->f14);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DCFC0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD148);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct H_D148 { unsigned int v; };
extern char *D_00519AD8_D148[] __asm__("D_00519AD8");

void func_003DD148(struct H_D148 h) {
    struct H_D148 c;
    unsigned int u = h.v;
    int t;
    int ok = 0;
    c.v = u;
    if (u != 0) {
        ok = ((*(unsigned int *)(((unsigned char *)&c)[3] * 0x30 + D_00519AD8_D148[0]) ^ u) & 0xFFFFF) == 0;
    }
    if (ok != 0) {
        t = (u >> 20) & 0xF;
        if (t != 3 && t != 0xA) {
            *(int *)(((unsigned char *)&h)[3] * 0x30 + D_00519AD8_D148[0] + 4) = 1;
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD1D8);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD310);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD438);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int *f_E670_D438() __asm__("func_003DE670");
extern int f_E800_D438() __asm__("func_003DE800");
extern void f_E668_D438(int *) __asm__("func_003DE668");
extern char *f_strncpy_D438(char *, char *, int) __asm__("strncpy");
extern void f_Exec_D438(int *) __asm__("iFILESYS_ExecCommand");
struct R_D438 { unsigned flags; int pad4, pad8; int wC; int w10; int w14; int w18; int pad1C, pad20; char *w24; };

int func_003DD438(char *arg0, int arg1, int arg2) {
    struct R_D438 *r = (struct R_D438 *)f_E670_D438();
    r->w14 = arg2;
    r->w10 = arg1;
    r->flags = (r->flags & 0xFF0FFFFF) | 0x800000;
    r->w18 = 1;
    r->w24 = (char *)f_E800_D438();
    if (r->w24 == 0) {
        r->wC = 2;
        f_E668_D438((int *)r);
    }
    f_strncpy_D438(r->w24 + 0x10, arg0, 0x100);
    f_Exec_D438((int *)r);
    return r->flags;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD4E8);
#ifdef SKIP_ASM
extern int func_003DE800();
extern void func_003DE668();

int func_003DD4E8(char *arg0, int arg1, int arg2, int arg3) {
    char *p = (char *)func_003DE670();
    int r;
    *(int *)(p + 0x14) = arg3;
    *(int *)(p + 0x18) = arg1;
    *(int *)(p + 0x10) = arg2;
    *(int *)p = (*(int *)p & 0xFF0FFFFF) | 0x200000;
    r = func_003DE800();
    *(int *)(p + 0x24) = r;
    if (r == 0) {
        *(int *)(p + 0xC) = 2;
        func_003DE668(p);
    }
    strncpy(*(char **)(p + 0x24) + 0x10, arg0, 0x100);
    iFILESYS_ExecCommand(p);
    return *(int *)p;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD5A0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD648);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { unsigned int pad0 : 20; unsigned int f : 4; unsigned int pad1 : 8; int a; int b; int c; int d; int e; int f1; int g; int h; } C_D648;
extern C_D648 *func_003DE670_D648(void) __asm__("func_003DE670");
extern void func_003DE668_D648(C_D648 *) __asm__("func_003DE668");
extern void iFILESYS_ExecCommand_D648(C_D648 *) __asm__("iFILESYS_ExecCommand");

int func_003DD648_impl(int *arg0, int arg1, int arg2, int arg3, int arg4, int arg5) __asm__("func_003DD648");
int func_003DD648_impl(int *arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    C_D648 *c;
    int n;

    c = func_003DE670_D648();
    *(int*)((char*)c + 0x14) = arg5;
    *(int*)((char*)c + 0x10) = arg4;
    c->f = 4;
    if (arg0 == 0) {
        *(int*)((char*)c + 0xC) = 6;
        func_003DE668_D648(c);
    }
    *(int**)((char*)c + 0x24) = arg0;
    n = arg0[1];
    *(int*)((char*)c + 0x20) = arg2;
    if (n < arg1 + arg3) arg3 = n - arg1;
    *(int*)((char*)c + 0x18) = arg1;
    *(int*)((char*)c + 0x1C) = arg3;
    iFILESYS_ExecCommand_D648(c);
    return *(int*)c;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD720);
#ifdef SKIP_ASM
extern void func_003DE668();

int func_003DD720(int a0, int a1, int a2, int a3, int a4, int a5) {
    char *p = (char *)func_003DE670();
    *(int *)(p + 0x14) = a5;
    *(int *)p = (*(int *)p & 0xFF0FFFFF) | 0x500000;
    if (a0 == 0) {
        *(int *)(p + 0xC) = 6;
        func_003DE668(p);
    }
    *(int *)(p + 0x24) = a0;
    *(int *)(p + 0x10) = a4;
    *(int *)(p + 0x1C) = a3;
    *(int *)(p + 0x18) = a1;
    *(int *)(p + 0x20) = a2;
    iFILESYS_ExecCommand(p);
    return *(int *)p;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD7E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int *func_003DE670_D7E0() __asm__("func_003DE670");
extern void func_003DE668_D7E0(int *) __asm__("func_003DE668");

int func_003DD7E0(int *arg0, int arg1, int arg2) {
    int *temp_2;

    temp_2 = func_003DE670_D7E0();
    temp_2[5] = arg2;
    temp_2[4] = arg1;
    temp_2[0] = (temp_2[0] & 0xFF0FFFFF) | 0x600000;
    if (arg0 != 0) {
        temp_2[6] = arg0[1];
        temp_2[2] = 1;
    } else {
        temp_2[3] = 6;
        func_003DE668_D7E0(temp_2);
    }
    return temp_2[0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD878);
#ifdef SKIP_ASM
extern int *func_003DE670();
extern void iFILESYS_ExecCommand(int);

int func_003DD878(int a0, int a1, int a2) {
    int *p = func_003DE670();
    p[5] = a2;
    p[4] = a1;
    p[0] = (p[0] & 0xFF0FFFFF) | 0x700000;
    iFILESYS_ExecCommand((int)p);
    return p[0];
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DD8E8);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DDA10);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DDAC0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DDC00);
#ifdef SKIP_ASM
extern void func_003DD310();
extern void iFILESYS_ExecCommand(int);

void func_003DDC00(int arg0, int arg1, int arg2) {
    func_003DD310();
    iFILESYS_ExecCommand(arg2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DDC30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { unsigned int pad0 : 20; unsigned int f : 4; unsigned int pad1 : 8; int a; int b; int c; int d; int e; } R_DC30;
typedef struct N_DC30 { int f0; int pad4[2]; char *key; int pad10; struct N_DC30 *next; } N_DC30;
typedef struct { char *owner; int pad4; int f8; char pad[0x110 - 0xC]; } E_DC30;
typedef struct { int f0; int count; char pad8[0x2C - 8]; E_DC30 *arr; int pad30; N_DC30 *head; } G_DC30;
extern R_DC30 *func_003DE670_DC30(void) __asm__("func_003DE670");
extern int func_003DD5A0_DC30(char *, int, R_DC30 *) __asm__("func_003DD5A0");
extern void func_003DCF70_DC30(int, void *) __asm__("func_003DCF70");
extern void func_003DDC00_DC30(int, int, int) __asm__("func_003DDC00");
extern G_DC30 D_00519AB0_DC30 __asm__("D_00519AB0");
extern int (*D_00450C10_DC30[])(void *) __asm__("D_00450C10");

int func_003DDC30(char *a0, int a1, int a2) {
    N_DC30 *prev;
    N_DC30 *n;
    R_DC30 *r;
    E_DC30 *e;
    int i;

    prev = 0;
    n = D_00519AB0_DC30.head;
    r = func_003DE670_DC30();
    e = D_00519AB0_DC30.arr;
    r->e = a2;
    r->d = a1;
    r->f = 10;
    if (*(int *)(a0 + 8) != 0) {
        r->c = 7;
    }
    for (i = 0; i < D_00519AB0_DC30.count; i++, e++) {
        if (e != 0 && e->f8 != 0 && *(char **)(e->owner + 0xC) == a0) {
            r->b = -2;
            r->c = 8;
            break;
        }
    }
    while (n != 0 && n->key != a0) {
        prev = n;
        n = n->next;
    }
    if (n == 0) {
        r->c = 5;
    }
    if (prev != 0) {
        prev->next = n->next;
    } else {
        D_00519AB0_DC30.head = D_00519AB0_DC30.head->next;
    }
    D_00450C10_DC30[2]((void *)n->f0);
    D_00450C10_DC30[2](n);
    func_003DCF70_DC30(func_003DD5A0_DC30(a0, a1, r), func_003DDC00_DC30);
    return *(int *)r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", FILESYS_atomic);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void iFILESYS_ExecCommand(int);
extern int D_00519AB0_9AB0[] __asm__("D_00519AB0");

int FILESYS_atomic_DDF0(int (*arg0)(int, int), int arg1, int arg2, int arg3) __asm__("FILESYS_atomic");
int FILESYS_atomic_DDF0(int (*arg0)(int, int), int arg1, int arg2, int arg3) {
    int temp_18;
    int temp_2;

    temp_18 = D_00519AB0_9AB0[2];
    D_00519AB0_9AB0[2] = arg2;
    temp_2 = arg0(arg2, arg3);
    D_00519AB0_9AB0[2] = temp_18;
    iFILESYS_ExecCommand(0);
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DDE50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519AB8_DE50[] __asm__("D_00519AB8");
void iFILESYS_ExecCommand_DE50(int) __asm__("iFILESYS_ExecCommand");
void func_003DDE50(int a) {
    D_00519AB8_DE50[0] = a;
    iFILESYS_ExecCommand_DE50(0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DDE78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int strlen_DE78(char *) __asm__("strlen");
extern char *strcpy_DE78(char *, char *) __asm__("strcpy");
extern int func_00416B18_DE78(char *, char *, int) __asm__("func_00416B18");
extern void func_004162D0_DE78(char *, char *) __asm__("func_004162D0");
extern char *D_00450C50_DE78[] __asm__("D_00450C50");
extern char *D_00450C08_DE78[] __asm__("D_00450C08");
extern int D_00450C44_DE78[] __asm__("D_00450C44");
extern int D_00450C48_DE78[] __asm__("D_00450C48");
extern char D_00519AF0_DE78[] __asm__("D_00519AF0");
extern char D_00495D78_DE78[] __asm__("D_00495D78");

void func_003DDE78(char *a) {
    int n, len;
    n = strlen_DE78(D_00450C50_DE78[0]);
    if (func_00416B18_DE78(a, D_00450C08_DE78[0], 3) == 0) {
        if ((D_00450C48_DE78[0] & 3) == 2) return;
        D_00450C44_DE78[0] = 1;
        a += 3;
    } else if (func_00416B18_DE78(a, D_00450C50_DE78[0], n) == 0) {
        if (!(D_00450C48_DE78[0] & 2)) return;
        D_00450C44_DE78[0] = 2;
        a += n;
    }
    strcpy_DE78(D_00519AF0_DE78, a);
    if (D_00519AF0_DE78[0xFF] == 0) {
        len = strlen_DE78(D_00519AF0_DE78);
        if (len > 0 && D_00519AF0_DE78[len - 1] != 0x2F) {
            func_004162D0_DE78(D_00519AF0_DE78, D_00495D78_DE78);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DDF80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_00519AF0_DF80[] __asm__("D_00519AF0");
void strncpy_DF80(char *, char *, int) __asm__("strncpy");
void func_003DDF80(char *dst) {
    strncpy_DF80(dst, D_00519AF0_DF80, 0x100);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", iFILESYS_ExecCommand);

INCLUDE_ASM("ealib/seg_2DCAE8", iFILESYS_CommandCompleteCallback);

void func_003DE4C8(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", FILESYS_bypassqueuefileinfo);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct N_E4D0 { int f0; int pad[2]; char *fC; int pad2; struct N_E4D0 *next; };
extern struct N_E4D0 *D_00519AE4_E4D0[] __asm__("D_00519AE4");
extern char *strchr_E4D0(char *, int) __asm__("strchr");
extern int func_003E3208_E4D0(char *, int, int *) __asm__("func_003E3208");
extern int func_003E34E8_E4D0(int) __asm__("func_003E34E8");
extern int func_003E32F8_E4D0(int) __asm__("func_003E32F8");
extern int func_004165A8_E4D0(char *, char *) __asm__("func_004165A8");
extern int BIG_locateentryz_E4D0(int, char *, int, int *, int *) __asm__("BIG_locateentryz");
int FILESYS_bypassqueuefileinfo(char *name, int flags, int *out) {
    char path[256];
    char file[256];
    int h;
    int x;
    int off;
    int found = 0;
    int mode;
    struct N_E4D0 *n;

    *out = 0;
    file[0] = 0;
    if (strchr_E4D0(name, '|')) {
        if (*name == '|') {
            mode = 2;
        } else {
            int len = strchr_E4D0(name, '|') - name;
            mode = 4;
            strncpy(path, name, len);
            path[len] = 0;
        }
        strcpy(file, strchr_E4D0(name, '|') + 1);
    } else {
        mode = 1;
        if (flags & 1) {
            mode = 3;
            strcpy(file, name);
        }
    }
    if ((mode & 1) && func_003E3208_E4D0(name, flags, &h)) {
        found = 1;
        *out = func_003E34E8_E4D0(h);
        func_003E32F8_E4D0(h);
    }
    if (!found && (mode & 6)) {
        for (n = D_00519AE4_E4D0[0]; n != 0 && !found; n = n->next) {
            if ((mode & 4) && func_004165A8_E4D0(n->fC + 0x10, path)) continue;
            if (BIG_locateentryz_E4D0(n->f0, file, 0, &x, &off)) {
                found = 1;
                *out = off;
            }
        }
    }
    return found;
}
#endif

void func_003DE668(void) {
}

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DE670);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DE7B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519AC4_9AC4[] __asm__("D_00519AC4");
extern void MUTEX_unlock(int *);

void func_003DE7B0(int a0) {
    MUTEX_lock(D_00519AC4_9AC4);
    func_003E6448(a0, 0, 0x30);
    MUTEX_unlock(D_00519AC4_9AC4);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DE800);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DE8C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519AC4_9AC4[] __asm__("D_00519AC4");
extern void MUTEX_unlock(int *);

void func_003DE8C0(int a0) {
    MUTEX_lock(D_00519AC4_9AC4);
    func_003E6448(a0, 0, 0x110);
    MUTEX_unlock(D_00519AC4_9AC4);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DE910);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450C10_E910[4] __asm__("D_00450C10");

void func_003DE910(int arg0, int arg1) {
    D_00450C10_E910[1] = arg0;
    D_00450C10_E910[2] = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DE928);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct A_E928 { int p0, p4, p8, pC, f10, f14, f18, f1C; };
struct B_E928 { int f0, f4, f8, fC; };
extern struct A_E928 D_00450C10_E928 __asm__("D_00450C10");
extern struct B_E928 D_00450C58_E928 __asm__("D_00450C58");
extern int D_00450C50_E928[] __asm__("D_00450C50");
extern void func_003E6220_E928(int, int) __asm__("func_003E6220");
extern void func_003E6574_E928(int *, void *, int) __asm__("func_003E6574");

int func_003DE928(int *arg0) {
    int n = *arg0;
    if (n >= 0x25) {
        func_003E6220_E928(arg0, n);
    }
    D_00450C10_E928.f18 = D_00450C58_E928.f0;
    D_00450C10_E928.f10 = D_00450C58_E928.f4;
    D_00450C10_E928.f14 = D_00450C58_E928.fC != 0;
    D_00450C10_E928.f1C = D_00450C50_E928[0];
    func_003E6574_E928(arg0, &D_00450C10_E928, n);
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DE9B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct A_E9B8 { int p0, p4, p8, pC, f10, f14, f18, f1C; };
struct B_E9B8 { int f0, f4, f8, fC; };
extern struct A_E9B8 D_00450C10_E9B8 __asm__("D_00450C10");
extern struct B_E9B8 D_00450C58_E9B8 __asm__("D_00450C58");
extern int D_00450C50_E9B8[] __asm__("D_00450C50");
extern void func_003E6220_E9B8(void *, int) __asm__("func_003E6220");
extern void func_003E6574_E9B8(void *, int *, int) __asm__("func_003E6574");

int func_003DE9B8(int *arg0) {
    if (*arg0 < 0x24) {
        func_003E6220_E9B8(&D_00450C10_E9B8, 0x24);
    }
    func_003E6574_E9B8(&D_00450C10_E9B8, arg0, *arg0);
    D_00450C58_E9B8.f0 = D_00450C10_E9B8.f18;
    D_00450C58_E9B8.f4 = D_00450C10_E9B8.f10;
    D_00450C58_E9B8.f8 = D_00450C10_E9B8.pC;
    D_00450C58_E9B8.fC = D_00450C10_E9B8.f14;
    D_00450C50_E9B8[0] = D_00450C10_E9B8.f1C;
    return 1;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEA48);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEB50);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEBF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003DD4E8_EBF0(int, int, int, int) __asm__("func_003DD4E8");
extern void func_003DD1D8_EBF0(int) __asm__("func_003DD1D8");
extern int func_003DCE90_EBF0(int) __asm__("func_003DCE90");
extern int func_003DD310_EBF0(int) __asm__("func_003DD310");

int func_003DEBF0_impl(int a0, int a1, int a2, int *a3) __asm__("func_003DEBF0");
int func_003DEBF0_impl(int a0, int a1, int a2, int *a3) {
    int ok = 0;
    int h = func_003DD4E8_EBF0(a0, a1, a2, 0);
    if (h != 0) {
        func_003DD1D8_EBF0(h);
        ok = func_003DCE90_EBF0(h) == 1;
        *a3 = func_003DD310_EBF0(h);
    } else {
        *a3 = 0;
    }
    return ok;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEC60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003DD648_EC60(void) __asm__("func_003DD648");
extern void func_003DEB50_EC60(int, int, int, int, int, void (*)(void)) __asm__("func_003DEB50");

void func_003DEC60(int a, int b, int c, int d, int e) {
    func_003DEB50_EC60(a, b, c, d, e, func_003DD648_EC60);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEC80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003DD720_EC80(void) __asm__("func_003DD720");
extern void func_003DEB50_EC60(int, int, int, int, int, void (*)(void)) __asm__("func_003DEB50");

void func_003DEC80(int a, int b, int c, int d, int e) {
    func_003DEB50_EC60(a, b, c, d, e, func_003DD720_EC80);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DECA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003DD1D8_ECA0(int) __asm__("func_003DD1D8");
int func_003DD310_ECA0(int) __asm__("func_003DD310");
int func_003DD5A0_ECA0(int, int, int) __asm__("func_003DD5A0");

int func_003DECA0(int a, int b) {
    int temp_2;
    int var_2 = 0;

    temp_2 = func_003DD5A0_ECA0(a, b, 0);
    if (temp_2 != 0) {
        func_003DD1D8_ECA0(temp_2);
        var_2 = func_003DD310_ECA0(temp_2) != 0;
    }
    return var_2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DECF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003DD1D8_ECF8(int) __asm__("func_003DD1D8");
int func_003DD310_ECF8(int) __asm__("func_003DD310");
int func_003DD7E0_ECF8(int, int, int) __asm__("func_003DD7E0");

int func_003DECF8(int a, int b) {
    int temp_2;
    int var_2 = 0;

    temp_2 = func_003DD7E0_ECF8(a, b, 0);
    if (temp_2 != 0) {
        func_003DD1D8_ECF8(temp_2);
        var_2 = func_003DD310_ECF8(temp_2);
    }
    return var_2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DED50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003DDAC0_ED50(int, int, int, int) __asm__("func_003DDAC0");
extern void func_003DD1D8_ED50(int) __asm__("func_003DD1D8");
extern int func_003DCE90_ED50(int) __asm__("func_003DCE90");
extern int func_003DD310_ED50(int) __asm__("func_003DD310");

int func_003DED50(int a0, int a1, int a2, int *a3) {
    int ok = 0;
    int h = func_003DDAC0_ED50(a0, a1, a2, 0);
    if (h != 0) {
        func_003DD1D8_ED50(h);
        ok = func_003DCE90_ED50(h) == 1;
        *a3 = func_003DD310_ED50(h);
    } else {
        *a3 = 0;
    }
    return ok;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEDC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003DD1D8_EDC0(int) __asm__("func_003DD1D8");
int func_003DD310_EDC0(int) __asm__("func_003DD310");
int func_003DDC30_EDC0(int, int, int) __asm__("func_003DDC30");

int func_003DEDC0(int a, int b) {
    int temp_2;
    int var_2 = 0;

    temp_2 = func_003DDC30_EDC0(a, b, 0);
    if (temp_2 != 0) {
        func_003DD1D8_EDC0(temp_2);
        var_2 = func_003DD310_EDC0(temp_2) != 0;
    }
    return var_2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEE18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003DD1D8_EE18(int) __asm__("func_003DD1D8");
int func_003DD310_EE18(int) __asm__("func_003DD310");
int func_003DD438_EE18(int, int, int) __asm__("func_003DD438");

int func_003DEE18(int a, int b) {
    int temp_2;
    int var_2 = 0;

    temp_2 = func_003DD438_EE18(a, b, 0);
    if (temp_2 != 0) {
        func_003DD1D8_EE18(temp_2);
        var_2 = func_003DD310_EE18(temp_2) != 0;
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", queueadd);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void MUTEX_unlock_qa(void *) __asm__("MUTEX_unlock");
extern char D_00519C08_9C08[] __asm__("D_00519C08");

void queueadd(char *arg0, char *arg1) {
    MUTEX_lock(D_00519C08_9C08);
    if (*(char **)arg0 == 0) {
        *(char **)arg0 = arg1;
    } else {
        *(char **)(*(char **)(arg0 + 4) + 4) = arg1;
    }
    *(char **)(arg0 + 4) = arg1;
    *(int *)(arg1 + 4) = 0;
    MUTEX_unlock_qa(D_00519C08_9C08);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEED8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void MUTEX_unlock_EED8(void *) __asm__("MUTEX_unlock");
extern char D_00519C08_9C08[] __asm__("D_00519C08");

void *func_003DEED8(void **arg0) {
    void *temp_2;
    void *var_16;

    MUTEX_lock(D_00519C08_9C08);
    temp_2 = *arg0;
    var_16 = 0;
    if (temp_2 != 0) {
        var_16 = temp_2;
        *arg0 = *(void **)((char *)var_16 + 4);
    }
    MUTEX_unlock_EED8(D_00519C08_9C08);
    return var_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEF40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519C00_EF40[] __asm__("D_00519C00");

void func_003DEF40(unsigned char *arg0) {
    int temp_2;

    temp_2 = D_00519C00_EF40[0] + 0x100;
    D_00519C00_EF40[0] = temp_2;
    if (temp_2 == 0) {
        D_00519C00_EF40[0] = 0x100;
    }
    *(int *)arg0 = (int) (*arg0 | D_00519C00_EF40[0]);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DEF70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450C34_0C34[] __asm__("D_00450C34");
extern int D_00519BF0_9BF0[] __asm__("D_00519BF0");

int *func_003DEF70(int arg0) {
    int *temp_2;
    int temp_6;

    temp_6 = arg0 & 0xFF;
    if ((arg0 < 0x100) || (temp_6 >= D_00519BF0_9BF0[0])) {
        return 0;
    }
    temp_2 = (int*)((char*)D_00450C34_0C34[0] + (temp_6 * 0x30));
    return ((*temp_2 ^ arg0) != 0) ? 0 : temp_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", releaserequest);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void queueadd_rr(char *, char *) __asm__("queueadd");
extern void (*D_00450C18_0C18[])(unsigned int) __asm__("D_00450C18");
extern char D_00519BF8_9BF8[] __asm__("D_00519BF8");

void releaserequest(char *arg0) {
    unsigned int temp_4;

    if (*(int *)(arg0 + 0x10) != 0) {
        temp_4 = *(unsigned int *)(arg0 + 0x14);
        if (temp_4 >= 2U) {
            D_00450C18_0C18[0](temp_4);
        }
    }
    *(int *)(arg0 + 0x1C) = 0;
    *(int *)arg0 = *(unsigned char *)arg0;
    queueadd_rr(D_00519BF8_9BF8, arg0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF028);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_00519C08_F028[] __asm__("D_00519C08");
extern void MUTEX_lock_F028(void *) __asm__("MUTEX_lock");
extern void MUTEX_unlock_F028(void *) __asm__("MUTEX_unlock");
extern void releaserequest_F028(void *) __asm__("releaserequest");

void func_003DF028(void *arg0) {
    int (*temp_19)(int);
    int temp_16;
    int temp_18;

    MUTEX_lock_F028(D_00519C08_F028);
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    temp_16 = (*(int *)((char*)(arg0) + (0x10)));
    temp_19 = (*(int (**)(int))((char*)(arg0) + (0x18)));
    temp_18 = (*(int *)((char*)(arg0) + (0xC)));
    MUTEX_unlock_F028(D_00519C08_F028);
    if (temp_16 != 0) {
        if (temp_18 == 0) {
            releaserequest_F028(arg0);
        }
    } else if (temp_19 != 0) {
        temp_19((*(int *)((char*)(arg0) + (0))));
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF0B8);
#ifdef SKIP_ASM
extern void func_003DD310_F0B8(int) __asm__("func_003DD310");
extern void func_003DF028_F0B8(void *) __asm__("func_003DF028");

/* Callback (third argument is the stream); later code takes its address as void (*)(void *). */
void func_003DF0B8_impl(int arg0, int arg1, char *s) __asm__("func_003DF0B8");
void func_003DF0B8_impl(int arg0, int arg1, char *s) {
    func_003DD310_F0B8(*(volatile int *)(s + 0x1C));
    func_003DF028_F0B8(s);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF0F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003DCF70(int, void *);
extern int func_003DD310_F0F0(int) __asm__("func_003DD310");
extern int func_003DD5A0(int, int, void *);
extern int func_003DD648(int, int, int, int, int, void *);
extern void func_003DF0B8(void *);

void func_003DF0F0(int a0, int a1, int *s) {
    int n = func_003DD310_F0F0(*(volatile int *)&s[7]);
    s[2] += n;
    s[11] += n;
    if (n <= 0x7FFF || s[4] != 0) {
        *(volatile int *)&s[7] = func_003DD5A0(s[8], 0x63, s);
        if (*(volatile int *)&s[7] != 0) {
            func_003DCF70(*(volatile int *)&s[7], func_003DF0B8);
        }
    } else {
        int off = s[9] + n;
        int rem = s[10] - n;
        s[9] = off;
        s[10] = rem;
        *(volatile int *)&s[7] = func_003DD648(s[8], off, s[11], rem <= 0x8000 ? rem : 0x8000, 0x63, s);
        if (*(volatile int *)&s[7] != 0) {
            func_003DCF70(*(volatile int *)&s[7], func_003DF0F0);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF1E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void fCF70_F1E0(int, char *) __asm__("func_003DCF70");
extern int fD310_F1E0(int) __asm__("func_003DD310");
extern int fD5A0_F1E0(int, int, void *) __asm__("func_003DD5A0");
extern int fD648_F1E0(int, int, int, int, int, void *) __asm__("func_003DD648");
extern int (*D_0C14_F1E0[])(char *, int, int) __asm__("D_00450C14");
extern char D_5DA8_F1E0[] __asm__("D_00495DA8");
extern char fF0B8_F1E0[] __asm__("func_003DF0B8");
extern char fF0F0_F1E0[] __asm__("func_003DF0F0");

void func_003DF1E0(int a, int b, char *s) {
    int t5, v, m, old;
    t5 = fD310_F1E0(*(volatile int *)(s + 0x1C));
    if (*(int *)(s + 0x10) != 0) {
        *(volatile int *)(s + 0x1C) = fD5A0_F1E0(*(int *)(s + 0x20), 0x63, s);
        if (*(volatile int *)(s + 0x1C) != 0) fCF70_F1E0(*(volatile int *)(s + 0x1C), fF0B8_F1E0);
    } else {
        old = *(int *)(s + 0x28);
        *(int *)(s + 0x28) = t5;
        v = D_0C14_F1E0[0](D_5DA8_F1E0, t5, old);
        m = *(int *)(s + 0x28);
        *(int *)(s + 0x14) = v;
        *(int *)(s + 0x2C) = v;
        *(volatile int *)(s + 0x1C) = fD648_F1E0(*(int *)(s + 0x20), *(int *)(s + 0x24), v, m <= 0x8000 ? m : 0x8000, 0x63, s);
        if (*(volatile int *)(s + 0x1C) != 0) fCF70_F1E0(*(volatile int *)(s + 0x1C), fF0F0_F1E0);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF2C0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF3C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003DD310_F3C0(int) __asm__("func_003DD310");
struct Q_F3C0 { int w0; int p1; int f8; int pc; int f10; int p14; int p18; volatile int h; int f20; int f24; int f28; int f2c; };

void func_003DF3C0(int a, int b, struct Q_F3C0 *s) {
    int n = func_003DD310_F3C0(s->h);
    int x;
    int m;
    s->f8 += n;
    s->f2c += n;
    if (n <= 0x7FFF || s->f10 != 0) {
        func_003DF028(s);
        return;
    }
    x = s->f28 - n;
    m = x > 0x8000 ? 0x8000 : x;
    s->f24 += n;
    s->f28 = x;
    s->h = func_003DD648(s->f20, s->f24, s->f2c, m, 99, s);
    if (s->h != 0) {
        func_003DCF70(s->h, func_003DF3C0);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF488);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF570);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF690);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_00519BF8_F690[] __asm__("D_00519BF8");
extern int *f_EED8_F690(char *) __asm__("func_003DEED8");
extern void f_EF40_F690(void *) __asm__("func_003DEF40");
extern int f_D4E8_F690(int, int, int, void *) __asm__("func_003DD4E8");
extern void f_CF70_F690(int, void *) __asm__("func_003DCF70");
extern char f_F2C0_F690[] __asm__("func_003DF2C0");
struct O_F690 { int w0, w4, w8, wC, w10, w14, w18; volatile int w1C; int w20, w24, w28, w2C; };

int func_003DF690(int arg0, int arg1) {
    struct O_F690 *t = (struct O_F690 *)f_EED8_F690(D_00519BF8_F690);
    if (t != 0) {
        f_EF40_F690(t);
        t->w28 = arg1;
        t->w8 = 0;
        t->wC = 0;
        t->w10 = 0;
        t->w18 = 0;
        t->w24 = 0;
        t->w2C = 0;
        t->w14 = 1;
        t->w1C = f_D4E8_F690(arg0, 1, 0x64, t);
        if (t->w1C != 0) {
            f_CF70_F690(t->w1C, f_F2C0_F690);
            return t->w0;
        }
        return 0;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF748);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003DF2C0_F748(void) __asm__("func_003DF2C0");
extern int D_00519BF8_F748[] __asm__("D_00519BF8");
struct Q_F748 { int w0; int p1[1]; int f8; int fc; int f10; int f14; int f18; volatile int h; int p2[1]; int f24; int f28; int f2c; };

int func_003DF748(int a, int b, int c) {
    struct Q_F748 *p = (struct Q_F748 *)func_003DEED8((void **)D_00519BF8_F748);
    if (p == 0) return 0;
    func_003DEF40(p);
    p->f28 = c;
    p->f2c = b;
    p->f8 = 0;
    p->fc = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f24 = 0;
    p->h = func_003DD4E8(a, 1, 100, p);
    if (p->h == 0) return 0;
    func_003DCF70(p->h, func_003DF2C0_F748);
    return p->w0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF808);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void fCF70_F808(int, char *) __asm__("func_003DCF70");
extern int fD648_F808(int, int, int, int, int, void *) __asm__("func_003DD648");
extern char *fEED8_F808(char *) __asm__("func_003DEED8");
extern void fEF40_F808(char *) __asm__("func_003DEF40");
extern char D_9BF8_F808[] __asm__("D_00519BF8");
extern char fF3C0_F808[] __asm__("func_003DF3C0");

int func_003DF808(int a0, int a1, int a2, int a3) {
    char *t = fEED8_F808(D_9BF8_F808);
    if (t != 0) {
        fEF40_F808(t);
        *(int *)(t + 8) = 0;
        *(int *)(t + 0xC) = 0;
        *(int *)(t + 0x10) = 0;
        *(int *)(t + 0x14) = 0;
        *(int *)(t + 0x18) = 0;
        *(int *)(t + 0x20) = a0;
        *(int *)(t + 0x24) = a1;
        *(int *)(t + 0x28) = a3;
        *(int *)(t + 0x2C) = a2;
        *(volatile int *)(t + 0x1C) = fD648_F808(a0, a1, a2, a3 <= 0x8000 ? a3 : 0x8000, 0x64, t);
        if (*(volatile int *)(t + 0x1C) != 0) {
            fCF70_F808(*(volatile int *)(t + 0x1C), fF3C0_F808);
            return *(int *)t;
        }
        return 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF8E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void MUTEX_unlock_F8E8(void *) __asm__("MUTEX_unlock");
extern char D_00519C08_9C08[] __asm__("D_00519C08");
extern char *func_003DEF70_F8E8(int) __asm__("func_003DEF70");

void func_003DF8E8_impl(int h, void (*fn)(int)) __asm__("func_003DF8E8");
void func_003DF8E8_impl(int h, void (*fn)(int)) {
    char *e = func_003DEF70_F8E8(h);
    int done;
    if (e == 0 || *(int *)(e + 0x18) != 0) {
        return;
    }
    MUTEX_lock(D_00519C08_9C08);
    done = *(int *)(e + 0x1C) == 0;
    *(void (**)(int))(e + 0x18) = fn;
    MUTEX_unlock_F8E8(D_00519C08_9C08);
    if (done) {
        fn(h);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DF980);

INCLUDE_ASM("ealib/seg_2DCAE8", ASYNCFILE_release);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFAF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void mlock_FAF0(char *) __asm__("MUTEX_lock");
extern void munlock_FAF0(char *) __asm__("MUTEX_unlock");
extern void fD148_FAF0(int) __asm__("func_003DD148");
extern char *fEF70_FAF0(int) __asm__("func_003DEF70");
extern void rel_FAF0(char *) __asm__("releaserequest");
extern char D_9C08_FAF0[] __asm__("D_00519C08");

int func_003DFAF0(int a0) {
    int v18, v19, v20, r;
    char *t;
    v19 = 0;
    v20 = 0;
    mlock_FAF0(D_9C08_FAF0);
    v18 = 0;
    t = fEF70_FAF0(a0);
    if (t != 0 && ((v19 = *(int *)(t + 0x1C), v20 = *(int *)(t + 0x10), v18 = *(int *)(t + 0xC), v19 != 0) || v18 == 0)) {
        *(int *)(t + 0x10) = 1;
    }
    munlock_FAF0(D_9C08_FAF0);
    if (t != 0 && v20 == 0) {
        if (*(int *)(t + 0x10) != 0) {
            if (v19 != 0) {
                fD148_FAF0(v19);
                return 1;
            }
            if (v18 == 0) {
                rel_FAF0(t);
            }
            return 1;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFBD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003DFBD0_impl(int **arg0, int **arg1, int ***arg2) __asm__("func_003DFBD0");
int func_003DFBD0_impl(int **arg0, int **arg1, int ***arg2) {
    int *temp_7;

    if (arg0 == 0) {
        return 1;
    }
    temp_7 = *arg0;
    if (*temp_7 != 0x4D525453) {
        return 1;
    }
    *arg2 = arg0;
    *arg1 = temp_7;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFC08);
#ifdef SKIP_ASM
int func_003DFC08(unsigned int a, unsigned int b, unsigned int c) {
    int r;
    if (b >= a) {
        r = 0;
        if (c >= a) {
            if (c < b) r = 1;
        }
        return r;
    }
    r = 0;
    if (!(c < a) || c < b) {
        r = 1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFC48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void MUTEX_lock(void *);
void MUTEX_unlock_FC48(void *) __asm__("MUTEX_unlock");
void func_003DCFC0_FC48(int, int) __asm__("func_003DCFC0");

void func_003DFC48(char *arg0, int arg1) {
    char *m;
    int old, nw, lim;

    m = arg0 + 4;
    MUTEX_lock(m);
    old = *(int *)(arg0 + 0x4C);
    nw = old - arg1;
    *(int *)(arg0 + 0x4C) = nw;
    MUTEX_unlock_FC48(m);
    lim = *(int *)(arg0 + 0x44);
    if (old >= lim && nw < lim) {
        *(int *)(arg0 + 0x48) = 1;
        if (*(int *)(arg0 + 0x38) == 1) {
            func_003DCFC0_FC48(*(int *)(arg0 + 0x174), *(int *)(arg0 + 0x40));
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFCD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519C18_FCD8[] __asm__("D_00519C18");
extern void *func_003DFCD8_impl(char *arg0) __asm__("func_003DFCD8");

void *func_003DFCD8_impl(char *arg0) {
    char *r;
    int t;
    MUTEX_lock(arg0 + 4);
    r = 0;
    if (*(char **)(arg0 + 0x68) != 0) {
        r = *(char **)(arg0 + 0x68);
        t = D_00519C18_FCD8[0] + 0x100;
        *(char **)(arg0 + 0x68) = *(char **)(r + 0xC);
        D_00519C18_FCD8[0] = t;
        if (t == 0) {
            D_00519C18_FCD8[0] = 0x100;
        }
        *(int *)r = *(unsigned char *)r | D_00519C18_FCD8[0];
    }
    MUTEX_unlock((int *)(arg0 + 4));
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFD58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void MUTEX_lock_FD58(void *) __asm__("MUTEX_lock");
extern void MUTEX_unlock_FD58(void *) __asm__("MUTEX_unlock");

void func_003DFD58(char *arg0, char *arg1) {
    char *temp_2;

    (*(int *)((char*)(arg1) + (0xC))) = 0;
    (*(int *)((char*)(arg1) + (4))) = 1;
    MUTEX_lock_FD58(arg0 + 4);
    temp_2 = (*(char **)((char*)(arg0) + (0x64)));
    if (temp_2 == 0) {
        (*(char **)((char*)(arg1) + (8))) = 0;
        (*(char **)((char*)(arg0) + (0x5C))) = arg1;
        (*(char **)((char*)(arg0) + (0x60))) = arg1;
        (*(char **)((char*)(arg0) + (0x64))) = arg1;
    } else {
        (*(char **)((char*)(arg1) + (8))) = temp_2;
        (*(char **)((char*)((*(char **)((char*)(arg0) + (0x64)))) + (0xC))) = arg1;
        (*(char **)((char*)(arg0) + (0x64))) = arg1;
    }
    MUTEX_unlock_FD58(arg0 + 4);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFDD0);
#ifdef SKIP_ASM
void *func_003DFDD0(void *arg0, int arg1) {
    int temp_3;
    void *temp_2;

    temp_3 = arg1 & 0xFF;
    if (temp_3 >= (*(int *)((char*)(arg0) + (0x18)))) {
        return 0;
    }
    temp_2 = (*(int *)((char*)(arg0) + (0x14))) + (temp_3 * 0x124);
    if (arg1 == (*(int *)((char*)(temp_2) + (0)))) {
        return ((*(int *)((char*)(temp_2) + (4))) == 0) ? 0 : temp_2;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFE18);
#ifdef SKIP_ASM
void func_003DFE18(char *l, char *n) {
    if (n == *(char **)(l + 0x5C)) {
        *(int *)(l + 0x5C) = *(int *)(n + 0xC);
    } else {
        *(int *)(*(char **)(n + 8) + 0xC) = *(int *)(n + 0xC);
    }
    if (n == *(char **)(l + 0x64)) {
        *(int *)(l + 0x64) = *(int *)(n + 8);
    } else {
        *(int *)(*(char **)(n + 0xC) + 8) = *(int *)(n + 8);
    }
    if (n == *(char **)(l + 0x60)) {
        char *t = *(char **)(n + 0xC);
        if (t == 0) t = *(char **)(n + 8);
        *(char **)(l + 0x60) = t;
    }
    *(int *)(n + 4) = 0;
    *(int *)(n + 0xC) = *(int *)(l + 0x68);
    *(char **)(l + 0x68) = n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFE88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_FE88 { int mask; int value; int result; };
struct T_FE88 { char pad[0x1C]; struct E_FE88 *ents; int count; };

int func_003DFE88(struct T_FE88 *t, int *key) {
    int i;
    int k = *key;
    for (i = 0; i < t->count; i++) {
        if ((k & t->ents[i].mask) == t->ents[i].value) {
            return t->ents[i].result;
        }
    }
    return -2;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003DFED0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E00D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003DD310_00D8(int) __asm__("func_003DD310");
void func_003E03D0_00D8(void *, int) __asm__("func_003E03D0");

void func_003E00D8(int arg0, int arg1, char *arg2) {
    int temp_2;

    temp_2 = func_003DD310_00D8(*(int *)(arg2 + 0x174));
    *(int *)(arg2 + 0x16C) = temp_2;
    if (temp_2 != 0) {
        func_003E03D0_00D8(arg2, *(int *)(arg2 + 0x40));
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0118);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003DCF70_0118(int, void *) __asm__("func_003DCF70");
void func_003DD310_0118(int) __asm__("func_003DD310");
int func_003DD4E8_0118(void *, int, int, void *) __asm__("func_003DD4E8");

void func_003E0118(int a0, int a1, char *arg2) {
    int temp_2;

    func_003DD310_0118(*(int *)(arg2 + 0x174));
    temp_2 = func_003DD4E8_0118(arg2 + 0x6C, 1, *(int *)(arg2 + 0x40), arg2);
    *(int *)(arg2 + 0x174) = temp_2;
    if (temp_2 != 0) {
        func_003DCF70_0118(temp_2, (void *)func_003E00D8);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0170);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0270);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E03D0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E06B0);
#ifdef SKIP_ASM
int func_003E06B0(int a, int b, int c) {
    int t = b * 0xC + 0x180;
    return a * 0x124 + t + c * 0x10 + 0x40;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E06D8);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0948);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct T_0948 { int a, b, c; };
extern int fFBD0_0948(int, void *, void *) __asm__("func_003DFBD0");

void func_003E0948(int a0, int a1, int a2, int a3, int a4) {
    char *sp0;
    int sp4;
    if (fFBD0_0948(a0, &sp0, &sp4) == 0 && a1 > 0) {
        int t = *(int *)(sp0 + 0x20);
        if (t >= a1 && (a1 != t || (a2 | a3) == 0) && (a4 > 0 || a4 == -1 || a4 == -2)
            && *(int *)(sp0 + 0x28) >= a4 && *(int *)(sp0 + 0x38) == 0) {
            struct T_0948 *p = &(*(struct T_0948 **)(sp0 + 0x1C))[a1 - 1];
            p->a = a2;
            p->b = a3;
            p->c = a4;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0A28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int f_FBD0_0A28(int, void *, void *) __asm__("func_003DFBD0");
extern void f_1110_0A28(int) __asm__("func_003E1110");
extern int f_5440_0A28(int) __asm__("func_003E5440");
extern void f_SYNC_0A28(int) __asm__("SYNCTASK_run");
extern void f_5398_0A28(int) __asm__("func_003E5398");
extern void f_56E0_0A28(void *) __asm__("func_003E56E0");
extern void f_ECA0_0A28(int, int) __asm__("func_003DECA0");
struct S_0A28 { int w0; char pad[0x34]; int w38; char pad2[0x130]; int w16C; };

void func_003E0A28(int arg0) {
    struct S_0A28 *sp0;
    int sp4;
    if (f_FBD0_0A28(arg0, &sp0, &sp4) == 0) {
        f_1110_0A28(arg0);
        while (sp0->w38 == 1) {
            if (f_5440_0A28(0) != 0)
                f_SYNC_0A28(0);
            f_5398_0A28(0);
        }
        sp0->w0 = 0;
        f_56E0_0A28((char *)sp0 + 4);
        if (sp0->w16C != 0)
            f_ECA0_0A28(sp0->w16C, 0x64);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0AD8);
#ifdef SKIP_ASM
void func_003E0AD8(int a0, int a1, int a2) {
    int *sp0;
    int *sp4;

    if (func_003DFBD0(a0, &sp0, &sp4) == 0) {
        sp0[0x3C / 4] = a1;
        sp0[0x40 / 4] = a2;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0B28);
#ifdef SKIP_ASM
extern int func_003DFBD0(int, void *, void *);
extern void func_003E0B98(int, int);

void func_003E0B28(int a0, int a1) {
    char *p;
    int q;
    if (func_003DFBD0(a0, &p, &q) == 0) {
        int old = *(int *)(p + 0x44);
        *(int *)(p + 0x44) = a1;
        {
            int lim = *(int *)(p + 0x4C);
            if ((lim < old) != (lim < a1)) {
                func_003E0B98(a0, lim < a1);
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0B98);
#ifdef SKIP_ASM
typedef struct { char pad[0x38]; int s38; int pad3C; int f40; char pad44[4]; int f48; char pad4C[0x128]; int f174; } O_0B98;
extern void func_003DCFC0(int, int);

void func_003E0B98(int arg0, int arg1) {
    O_0B98 *o;
    int x;

    if (func_003DFBD0(arg0, &o, &x) == 0) {
        o->f48 = arg1;
        if (arg1 != 0) {
            if (o->s38 == 1) {
                func_003DCFC0(o->f174, o->f40);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0BF8);
#ifdef SKIP_ASM
extern int func_003DFBD0_0BF8(int, void *, void *) __asm__("func_003DFBD0");

struct E_0BF8 { int w[4]; };

struct E_0BF8 *func_003E0BF8(int arg0, int k) {
    char *loc[2];

    if (func_003DFBD0_0BF8(arg0, &loc[0], &loc[1]) != 0) {
        return 0;
    }
    if (k <= 0 || *(int *)(loc[0] + 0x28) < k) {
        return 0;
    }
    return &(*(struct E_0BF8 **)(loc[0] + 0x24))[k - 1];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0C58);
#ifdef SKIP_ASM
extern int func_003DFBD0(int, void *, void *);

int func_003E0C58(int arg0) {
    int loc[2];

    if (func_003DFBD0(arg0, &loc[0], &loc[1]) != 0) {
        return 0;
    }
    return *(int *)((char*)loc[1] + 4);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0C88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct L_0C88 { char *p; int q; };
extern int func_003DFBD0_0C88(int, void *, void *) __asm__("func_003DFBD0");
extern char *func_003DFCD8_0C88(char *) __asm__("func_003DFCD8");
extern void func_003DFD58_0C88(char *, char *) __asm__("func_003DFD58");
extern void func_003E0270_0C88(char *, int) __asm__("func_003E0270");
extern void MUTEX_lock_0C88(char *) __asm__("MUTEX_lock");
extern void MUTEX_unlock_0C88(char *) __asm__("MUTEX_unlock");

int func_003E0C88(int a0, char *name, int x, int y) {
    struct L_0C88 l;
    char *node;
    int old;
    if (func_003DFBD0_0C88(a0, &l.p, &l.q) != 0) {
        return 0;
    }
    node = func_003DFCD8_0C88(l.p);
    if (node == 0) {
        return 0;
    }
    *(int *)(node + 0x10) = 0;
    strncpy(node + 0x14, name, 0xFF);
    *(int *)(node + 0x118) = x;
    *(int *)(node + 0x11C) = y;
    func_003DFD58_0C88(l.p, node);
    MUTEX_lock_0C88(l.p + 4);
    old = *(int *)(l.p + 0x38);
    if (old == 0) {
        *(int *)(l.p + 0x38) = 1;
    }
    MUTEX_unlock_0C88(l.p + 4);
    if (old == 0) {
        if (*(int *)(l.p + 0x48) != 0) {
            func_003E0270_0C88(l.p, *(int *)(l.p + 0x40));
        } else {
            func_003E0270_0C88(l.p, *(int *)(l.p + 0x3C));
        }
    }
    return *(int *)node;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0D80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003DFBD0_0D80(int, char **, int *) __asm__("func_003DFBD0");
extern char *func_003DFCD8_0D80(char *) __asm__("func_003DFCD8");
extern void func_003DFD58_0D80(char *, char *) __asm__("func_003DFD58");
extern void MUTEX_lock_0D80(char *) __asm__("MUTEX_lock");
extern void MUTEX_unlock_0D80(char *) __asm__("MUTEX_unlock");
extern void func_003E0270_0D80(char *, int) __asm__("func_003E0270");

int func_003E0D80(int h, int *p, int n, int key) {
    char *a;
    int b;
    char *o;
    int *q;
    int t, f;
    if (func_003DFBD0_0D80(h, &a, &b) != 0) return 0;
    o = func_003DFCD8_0D80(a);
    if (o == 0) return 0;
    if (n == 0) {
        q = p;
        if (*q != key) {
            do {
                t = q[1];
                q = (int *)((char *)q + t);
                n += t;
            } while (*q != key);
        }
        n += q[1];
    }
    *(int *)(o + 0x118) = n;
    *(int **)(o + 0x114) = p;
    *(int *)(o + 0x11C) = key;
    *(int *)(o + 0x10) = 1;
    func_003DFD58_0D80(a, o);
    MUTEX_lock_0D80(a + 4);
    f = *(int *)(a + 0x38);
    if (f == 0) *(int *)(a + 0x38) = 1;
    MUTEX_unlock_0D80(a + 4);
    if (f == 0) func_003E0270_0D80(a, 0);
    return *(int *)o;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E0E90);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1110);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E12E0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E13E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int fFBD0_13E8(int, void *, void *) __asm__("func_003DFBD0");
extern void fFC48_13E8(char *, int) __asm__("func_003DFC48");
extern void fMLK_13E8(char *) __asm__("MUTEX_lock");
extern void fMUL_13E8(char *) __asm__("MUTEX_unlock");
extern void f03D0_13E8(char *, int) __asm__("func_003E03D0");

void func_003E13E8(int a0, unsigned int a1) {
    char *sp0;
    int sp4;
    int t;
    if (fFBD0_13E8(a0, &sp0, &sp4) == 0 && a1 >= *(unsigned int *)(sp0 + 0x30)
        && (unsigned int)(*(int *)(sp0 + 0x34) - 8) >= a1 && *(int *)a1 != -2) {
        *(int *)a1 = -2;
        fFC48_13E8(sp0, *(int *)(a1 + 4));
        fMLK_13E8(sp0 + 4);
        t = *(int *)(sp0 + 0x38);
        if (t == 2) *(int *)(sp0 + 0x38) = 1;
        fMUL_13E8(sp0 + 4);
        if (t == 2) {
            if (*(int *)(sp0 + 0x48) != 0) f03D0_13E8(sp0, *(int *)(sp0 + 0x40));
            else f03D0_13E8(sp0, *(int *)(sp0 + 0x3C));
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E14C8);
#ifdef SKIP_ASM
extern int func_003DFBD0(int, void *, void *);

int func_003E14C8(int arg0) {
    int loc[2];

    if (func_003DFBD0(arg0, &loc[0], &loc[1]) != 0) {
        return 0;
    }
    return *(int *)((char*)loc[1] + 8);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E14F8);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1530);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1580);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003DFBD0_1580(void *, void *, void *) __asm__("func_003DFBD0");

int func_003E1580(void *arg0) {
    char *sp0;
    int sp4;

    if (func_003DFBD0_1580(arg0, &sp0, &sp4) != 0) {
        return 0;
    }
    return *(int *)(sp0 + 0x34) - *(int *)(sp0 + 0x2C);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E15B8);
#ifdef SKIP_ASM
extern int func_003DFBD0(int, void *, void *);

int func_003E15B8(int arg0) {
    int loc[2];

    if (func_003DFBD0(arg0, &loc[0], &loc[1]) != 0) {
        return 0;
    }
    return *(int *)((char*)loc[0] + 0x4C);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E15E8);
#ifdef SKIP_ASM
struct G_15E8 { char p0[4]; int mtx; char p1[0x48]; int f50; char p2[8]; int *f5c; };
struct P_15E8 { int p0; int f4; char p1[0x118]; int f120; };
struct C_15E8 { int *p0; int *p1; };
struct LL_15E8 { int w0; int p1; int p2; struct P_15E8 *next; };
struct R_15E8 { struct G_15E8 *g; int *s; };
extern int func_003DFC08();

int func_003E15E8(int a) {
    struct R_15E8 r;
    struct LL_15E8 *cur;
    int n, id, q;
    struct P_15E8 *p;
    if (func_003DFBD0(a, &r.g, &r.s)) return 0;
    if (r.s[2] == 0) return 0;
    MUTEX_lock((char *)r.g + 4);
    cur = (struct LL_15E8 *)r.g->f5c;
    n = r.g->f50;
    id = r.s[3];
    while ((p = cur->next) != 0) {
        if (p->f4 == 1) break;
        q = p->f120;
        if (func_003DFC08(n, q, id)) break;
        cur = cur->next;
        n = q;
    }
    MUTEX_unlock((int *)((char *)r.g + 4));
    return cur->w0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E16B0);
#ifdef SKIP_ASM
int func_003E16B0(int a0, int a1) {
    int *sp0;
    int *sp4;
    int *t;

    if (func_003DFBD0(a0, &sp0, &sp4) != 0) {
        return 0;
    }
    t = func_003DFDD0(sp0, a1);
    if (t == 0) {
        return 0;
    }
    return t[1];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1700);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450C38_1700[] __asm__("D_00450C38");
void func_003DEE18_1700(int, int) __asm__("func_003DEE18");
void func_003E1700(int a) {
    func_003DEE18_1700(a, D_00450C38_1700[0]);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1728);
#ifdef SKIP_ASM
extern int func_003DEBF0(int, int, int, void *);

int func_003E1728(int a0, int *a1) {
    int sp0;
    int r;
    if (func_003DEBF0(*a1, 1, a0, &sp0) != 0) {
        a0 = a0 - 1;
        r = func_003DECF8(sp0, a0);
        func_003DECA0(sp0, a0);
        return r;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1798);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void FILESYS_atomic_1798(void (*)(void), int, int, void *) __asm__("FILESYS_atomic");
void func_003E1728_1798(void) __asm__("func_003E1728");
extern int D_00450C38_1798[] __asm__("D_00450C38");

void func_003E1798(int arg0) {
    int buf[8];

    buf[0] = arg0;
    buf[3] = 1;
    FILESYS_atomic_1798(func_003E1728_1798, 0, D_00450C38_1798[0], buf);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E17D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void FILESYS_atomic_17D8(void (*)(void), int, int, void *) __asm__("FILESYS_atomic");
void func_003E1728_17D8(void) __asm__("func_003E1728");
extern int D_00450C38_17D8[] __asm__("D_00450C38");

void func_003E17D8(int arg0) {
    int buf[8];

    buf[0] = arg0;
    buf[3] = 0;
    FILESYS_atomic_17D8(func_003E1728_17D8, 0, D_00450C38_17D8[0], buf);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1810);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00450C14_1810[])(int, int, int) __asm__("D_00450C14");

int func_003E1810(int a, int *b) {
    int sp0;
    int r, c;
    if (func_003DEBF0(b[0], 1, a, &sp0)) {
        int m = a - 1;
        r = func_003DECF8(sp0, m);
        c = D_00450C14_1810[0](b[0], r, b[4]);
        if (c) {
            func_003DEC60(sp0, 0, c, r, m);
            func_003DECA0(sp0, m);
            return c;
        }
        func_003DECA0(sp0, m);
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", FILE_load);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void FILESYS_atomic_1900(void (*)(void), int, int, void *) __asm__("FILESYS_atomic");
void func_003E1810_18C8(void) __asm__("func_003E1810");
extern int D_00450C38_18C8[] __asm__("D_00450C38");

void FILE_load(int arg0, int arg1) {
    int buf[8];

    buf[0] = arg0;
    buf[3] = 1;
    buf[4] = arg1;
    FILESYS_atomic_1900(func_003E1810_18C8, 0, D_00450C38_18C8[0], buf);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1908);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void FILESYS_atomic_1908(void (*)(void), int, int, void *) __asm__("FILESYS_atomic");
void func_003E1810_1908(void) __asm__("func_003E1810");
extern int D_00450C38_1908[] __asm__("D_00450C38");

void func_003E1908(int arg0, int arg1) {
    int buf[8];

    buf[0] = arg0;
    buf[3] = 0;
    buf[4] = arg1;
    FILESYS_atomic_1908(func_003E1810_1908, 0, D_00450C38_1908[0], buf);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1948);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00450C14_1948[])(int, int, int) __asm__("D_00450C14");

int func_003E1948(int a, int *b) {
    int sp0;
    int r, c;
    if (func_003DEBF0(b[0], 1, a, &sp0)) {
        int m = a - 1;
        r = func_003DECF8(sp0, m);
        c = D_00450C14_1948[0](b[0], r, b[4]);
        if (c) {
            func_003DEC60(sp0, 0, c, r, m);
            func_003DECA0(sp0, m);
            b[2] = r;
            return c;
        }
        func_003DECA0(sp0, m);
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1A10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a; int b; int sz; int c; int d; } FLS_args_1A10;
extern int FILESYS_atomic_1A10(void (*)(void), int, int, void*) __asm__("FILESYS_atomic");
extern int D_00450C38_0C38[] __asm__("D_00450C38");
extern void func_003E1948_1948(void) __asm__("func_003E1948");

int func_003E1A10(int arg0, int *arg1, int arg2) {
    FLS_args_1A10 s;
    int r;

    s.a = arg0;
    s.c = 1;
    s.d = arg2;
    r = FILESYS_atomic_1A10(func_003E1948_1948, 0, D_00450C38_0C38[0], &s);
    if (arg1 != 0) {
        *arg1 = s.sz;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", FILE_loadsizez);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a; int b; int sz; int c; int d; } FLS_args_1ACC;
extern int FILESYS_atomic_1ACC(void (*)(void), int, int, void*) __asm__("FILESYS_atomic");
extern int D_00450C38_0C38[] __asm__("D_00450C38");
extern void func_003E1948_1948(void) __asm__("func_003E1948");

int FILE_loadsizez(int arg0, int *arg1, int arg2) {
    FLS_args_1ACC s;
    int r;

    s.a = arg0;
    s.c = 0;
    s.d = arg2;
    r = FILESYS_atomic_1ACC(func_003E1948_1948, 0, D_00450C38_0C38[0], &s);
    if (arg1 != 0) {
        *arg1 = s.sz;
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1AD0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1B68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450C38_0C38[] __asm__("D_00450C38");
extern void FILESYS_atomic(int *, int, int, void *);
extern int func_003E1AD0[];

void func_003E1B68(int a0, int a1, int a2) {
    int s[5];
    s[0] = a0;
    s[1] = a1;
    s[2] = a2;
    s[3] = 1;
    s[4] = 0;
    FILESYS_atomic(func_003E1AD0, 0, D_00450C38_0C38[0], s);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1BB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a; int b; int c; int d; int e; int pad[3]; } S_1BB8;
extern int D_00450C38_1BB8[] __asm__("D_00450C38");
extern void f_1BB8_cb(void) __asm__("func_003E1AD0");
extern int FILESYS_atomic_1BB8(void (*)(void), int, int, void *) __asm__("FILESYS_atomic");

void func_003E1BB8(int a, int b, int c) {
    S_1BB8 s;
    s.a = a;
    s.b = b;
    s.c = c;
    s.d = 0;
    s.e = 0;
    FILESYS_atomic_1BB8(f_1BB8_cb, 0, D_00450C38_1BB8[0], &s);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1C00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003E1908_1C00(int, int) __asm__("func_003E1908");

int func_003E1C00(void *arg0, void *arg1) {
    int temp_16;
    int var_18;
    int var_19;

    var_18 = 0;
    var_19 = 1;
    if ((*(int *)((char*)(arg1) + (0))) > 0) {
        do {
            temp_16 = var_18 * 4;
            var_18 += 1;
            *(int *)(temp_16 + (*(int *)((char*)(arg1) + (8)))) = func_003E1908_1C00(*(int *)(temp_16 + (*(int *)((char*)(arg1) + (4)))), (*(int *)((char*)(arg1) + (0xC))));
            var_19 = (*(int *)(temp_16 + (*(int *)((char*)(arg1) + (8)))) == 0) ? 0 : var_19;
        } while (var_18 < (*(int *)((char*)(arg1) + (0))));
    }
    return var_19;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1C98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void cb_1C98(void) __asm__("func_003E1C00");
typedef struct Args_1C98 { int a0, a1, a2, a3, a4; } Args_1C98;
extern int FILESYS_atomic_1C98(void (*)(void), int, int, Args_1C98 *) __asm__("FILESYS_atomic");
extern int D_00450C38_0C38[] __asm__("D_00450C38");

int func_003E1C98(int arg0, int arg1, int arg2, int arg3) {
    Args_1C98 args;

    if (arg0 <= 0) return 0;
    {
        args.a0 = arg0;
        args.a1 = arg1;
        args.a2 = arg2;
        args.a3 = arg3;
        args.a4 = 1;
        return FILESYS_atomic_1C98(cb_1C98, 0, D_00450C38_0C38[0], &args) == 1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1D00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void cb_1D00(void) __asm__("func_003E1C00");
typedef struct Args_1D00 { int a0, a1, a2, a3, a4; } Args_1D00;
extern int FILESYS_atomic_1D00(void (*)(void), int, int, Args_1D00 *) __asm__("FILESYS_atomic");
extern int D_00450C38_0C38[] __asm__("D_00450C38");

int func_003E1D00(int arg0, int arg1, int arg2, int arg3) {
    Args_1D00 args;

    if (arg0 <= 0) return 0;
    {
        args.a0 = arg0;
        args.a1 = arg1;
        args.a2 = arg2;
        args.a3 = arg3;
        args.a4 = 0;
        return FILESYS_atomic_1D00(cb_1D00, 0, D_00450C38_0C38[0], &args) == 1;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1D68);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1EC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void FILESYS_atomic_1EC8(void (*)(void), int, int, void *) __asm__("FILESYS_atomic");
void func_003E1D68_1EC8(void) __asm__("func_003E1D68");
extern int D_00450C38_1EC8[] __asm__("D_00450C38");

void func_003E1EC8(int arg0, int arg1) {
    int buf[8];

    buf[0] = arg0;
    buf[2] = arg1;
    buf[3] = 1;
    FILESYS_atomic_1EC8(func_003E1D68_1EC8, 0, D_00450C38_1EC8[0], buf);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1F08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void FILESYS_atomic_1F08(void (*)(void), int, int, void *) __asm__("FILESYS_atomic");
void func_003E1D68_1F08(void) __asm__("func_003E1D68");
extern int D_00450C38_1F08[] __asm__("D_00450C38");

void func_003E1F08(int arg0, int arg1) {
    int buf[8];

    buf[0] = arg0;
    buf[3] = 0;
    buf[2] = arg1;
    FILESYS_atomic_1F08(func_003E1D68_1F08, 0, D_00450C38_1F08[0], buf);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E1F48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_00450C50_1F48[] __asm__("D_00450C50");
extern int func_00416B18_1F48(char *, char *, int) __asm__("func_00416B18");
extern void func_004162D0_1F48(char *, char *) __asm__("func_004162D0");
extern int func_00427D60_1F48(char *, int) __asm__("func_00427D60");
extern void func_00427FE8_1F48(int) __asm__("func_00427FE8");
extern void func_00428600_1F48(int, char *, int) __asm__("func_00428600");

unsigned int func_003E1F48(char *name, char *data, int len) {
    char buf[256];
    int fd;
    buf[0] = 0;
    if (func_00416B18_1F48(name, D_00450C50_1F48[0], strlen(D_00450C50_1F48[0])) != 0) {
        strcpy(buf, D_00450C50_1F48[0]);
    }
    func_004162D0_1F48(buf, name);
    fd = func_00427D60_1F48(buf, 0x602);
    if (fd >= 0) {
        do {
            if (len > 0x1000) {
                func_00428600_1F48(fd, data, 0x1000);
                len -= 0x1000;
                data += 0x1000;
            } else {
                func_00428600_1F48(fd, data, len);
                len = 0;
            }
        } while (len > 0);
        func_00427FE8_1F48(fd);
    }
    return (unsigned int)~fd >> 31;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2030);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_00450C50_2030[] __asm__("D_00450C50");
extern int func_00416B18_2030(char *, char *, int) __asm__("func_00416B18");
extern void func_004162D0_2030(char *, char *) __asm__("func_004162D0");
extern int func_00427D60_2030(char *, int) __asm__("func_00427D60");
extern int func_00427FE8_2030(int) __asm__("func_00427FE8");
extern int func_00428600_2030(int, char *, int) __asm__("func_00428600");

unsigned int func_003E2030(char *name, char *data, int len) {
    char buf[256];
    int fd;
    buf[0] = 0;
    if (func_00416B18_2030(name, D_00450C50_2030[0], strlen(D_00450C50_2030[0])) != 0) {
        strcpy(buf, D_00450C50_2030[0]);
    }
    func_004162D0_2030(buf, name);
    fd = func_00427D60_2030(buf, 0x602);
    if (fd >= 0) {
        do {
            if (len > 0x1000) {
                if (func_00428600_2030(fd, data, 0x1000) < 0) {
                    return 0;
                }
                len -= 0x1000;
                data += 0x1000;
            } else {
                if (func_00428600_2030(fd, data, len) < 0) {
                    return 0;
                }
                len = 0;
            }
        } while (len > 0);
        if (func_00427FE8_2030(fd) < 0) {
            return 0;
        }
    }
    return (unsigned int)~fd >> 31;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2130);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003E1BB8_2130(int, void *, int) __asm__("func_003E1BB8");
int func_003B4818_2130(void *) __asm__("func_003B4818");

int func_003E2130(int arg0) {
    char buf[0x80];
    int var_2;

    if (func_003E1BB8_2130(arg0, buf, 0x80) != 0) {
        var_2 = func_003B4818_2130(buf);
    } else {
        var_2 = 0;
    }
    return var_2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2168);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003E1BB8_2168(int, char *, int) __asm__("func_003E1BB8");
void func_003B4818_2168(char *) __asm__("func_003B4818");
void func_003E2168(int a) {
    char buf[0x80];
    func_003E1BB8_2168(a, buf, 0x80);
    func_003B4818_2168(buf);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2190);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E22F0);
#ifdef SKIP_ASM
extern void func_003E2190();

void func_003E22F0(void) {
    func_003E2190();
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", FILE_loadpackatz);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", FILE_loadpackat);
#ifdef SKIP_ASM
extern void FILE_loadpackatz();

void FILE_loadpackat(void) {
    FILE_loadpackatz();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2490);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_00499C81_2490[] __asm__("D_00499C81");
static inline int low_2490(unsigned char *t, int c) {
    int r = c;
    if (*(unsigned char *)(c + (int)t) & 1) r = c + 0x20;
    return r;
}

int func_003E2490(signed char *a, signed char *b) {
    unsigned char *t = D_00499C81_2490;
    signed char *p = a;
    signed char *q = b;
    signed char c1 = *p;
    signed char c2 = *q;
    int d;
    while ((d = low_2490(t, c1) - low_2490(t, c2)) == 0 && c1 != 0) {
        q++;
        p++;
        c1 = *p;
        c2 = *q;
    }
    return d;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", BIG_typeofheader);
#ifdef SKIP_ASM
int BIG_typeofheader(unsigned char *p) {
    int r;
    unsigned char b0 = p[0];
    unsigned char b1 = p[1];
    unsigned int v;
    if (((b0 << 8) | b1) == 0xC0FB) {
        r = 1;
    } else {
        v = (b0 << 24) | (b1 << 16) | (p[2] << 8) | p[3];
        if (v == 0x42494746) {
            r = 2;
        } else {
            r = (((v & 0xFFFFFF00) ^ 0x42494700) != 0) ? 0 : 3;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", BIG_sizeofheader);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int BIG_typeofheader_SZ(unsigned char *) __asm__("BIG_typeofheader");

int BIG_sizeofheader_impl(unsigned char *h) __asm__("BIG_sizeofheader");
int BIG_sizeofheader_impl(unsigned char *h) {
    int r = 0;
    int t = BIG_typeofheader_SZ(h);
    if (t == 1) {
        r = ((h[2] << 8) | h[3]) + 4;
    } else if (t > 0) {
        if (t < 4) {
            unsigned char *p = h + 12;
            r = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", BIG_debuginfo);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int BIG_sizeofheader_debuginfo(char *) __asm__("BIG_sizeofheader");
int BIG_debuginfo(char *base, int *num, int *tag) {
    int r = 0;
    unsigned char *p = (unsigned char *)base + BIG_sizeofheader_debuginfo(base);
    unsigned char c = p[-8];
    unsigned char *q = p - 8;
    if (((unsigned)(c - 0x41) < 0x1A || (unsigned)(c - 0x61) < 0x1A)
        && (unsigned)(q[1] - 0x30) < 10
        && (unsigned)(q[2] - 0x30) < 10
        && (unsigned)(q[3] - 0x30) < 10) {
        r = 8;
        if (num != 0) {
            *num = ((signed char)q[1] - 0x30) * 100 + ((signed char)q[2] - 0x30) * 10 + ((signed char)q[3] - 0x30);
        }
        if (tag != 0) {
            unsigned char *t = p - 4;
            *tag = (t[0] << 24) | (t[1] << 16) | (t[2] << 8) | t[3];
        }
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2740);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void BIG_debuginfo_2740(int, int *, int) __asm__("BIG_debuginfo");
int func_003E2740(int a) {
    int x = 0;
    BIG_debuginfo_2740(a, &x, 0);
    return x;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", BIG_locateentryz);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2CE0);
#ifdef SKIP_ASM
extern void BIG_locateentryz();

void func_003E2CE0(void) {
    BIG_locateentryz();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2D00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E2CE0_2D00(int, int, int, void *, int) __asm__("func_003E2CE0");

int func_003E2D00(arg0, arg1)
int arg0;
int arg1;
{
    int sp0;

    sp0 = 0;
    if (arg1 != 0) {
        func_003E2CE0_2D00(arg0, arg1, 0, &sp0, 0);
    }
    return sp0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2D30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void BIG_locateentryz_2D30(int, int, int, void *, int) __asm__("BIG_locateentryz");

int func_003E2D30(arg0, arg1)
int arg0;
int arg1;
{
    int sp0;

    sp0 = 0;
    if (arg1 != 0) {
        BIG_locateentryz_2D30(arg0, arg1, 0, &sp0, 0);
    }
    return sp0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2D60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int f_2D60_cb(int, int, int, int *, int) __asm__("func_003E2CE0");

int func_003E2D60(int base, int x) {
    int out;
    if (f_2D60_cb(base, 0, x, &out, 0) != 0)
        return base + out;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2DA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int f_2DA8_cb(int, int, int, int *, int) __asm__("BIG_locateentryz");

int func_003E2DA8(int base, int x) {
    int out;
    if (f_2DA8_cb(base, 0, x, &out, 0) != 0)
        return base + out;
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2DF0);
#ifdef SKIP_ASM
extern int func_003E2D00();

int func_003E2DF0(int arg0) {
    int temp_2;

    temp_2 = func_003E2D00();
    return (temp_2 == 0) ? 0 : (arg0 + temp_2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2E20);
#ifdef SKIP_ASM
extern int func_003E2D30();

int func_003E2E20(int arg0) {
    int temp_2;

    temp_2 = func_003E2D30();
    return (temp_2 == 0) ? 0 : (arg0 + temp_2);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2E50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003E2DF0_2E50(int, signed char *) __asm__("func_003E2DF0");
extern signed char *strchr_2E50(signed char *, int) __asm__("strchr");

void func_003E2E50(int arg0, signed char *arg1, int *arg2) {
    signed char *temp_2;
    signed char *var_17 = arg1;
    do {
        temp_2 = strchr_2E50(var_17, 0x2C);
        if (temp_2 != 0) *temp_2 = 0;
        *arg2 = func_003E2DF0_2E50(arg0, var_17);
        arg2++;
        if (temp_2 == 0) break;
        *temp_2 = 0x2C;
        temp_2++; var_17 = temp_2;
    } while (temp_2 != 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2EE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int BIG_typeofheader_2EE0(unsigned char *) __asm__("BIG_typeofheader");

int func_003E2EE0_impl(unsigned char *h) __asm__("func_003E2EE0");
int func_003E2EE0_impl(unsigned char *h) {
    int r = 0;
    int t = BIG_typeofheader_2EE0(h);
    if (t == 1) {
        r = (h[4] << 8) | h[5];
    } else if (t > 0) {
        if (t < 4) {
            unsigned char *p = h + 8;
            r = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2F70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
char *strcpy(char *, const char *);
char *func_003E2CE0_2F70(int, int, int, int, int) __asm__("func_003E2CE0");

char *func_003E2F70(int a, int b, char *dst) {
    char *p = func_003E2CE0_2F70(a, 0, b, 0, 0);
    char *r;
    if (!p) {
        *dst = 0;
        r = 0;
    } else {
        strcpy(dst, p);
        r = dst;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E2FC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
char *strcpy(char *, const char *);
char *BIG_locateentryz_2FC8(int, int, int, int, int) __asm__("BIG_locateentryz");

char *func_003E2FC8(int a, int b, char *dst) {
    char *p = BIG_locateentryz_2FC8(a, 0, b, 0, 0);
    char *r;
    if (!p) {
        *dst = 0;
        r = 0;
    } else {
        strcpy(dst, p);
        r = dst;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3020);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void SYNCTASK_add(void (*)(void), int, int);
extern void func_003E33B0(void);
extern int D_00450C44_3020[] __asm__("D_00450C44");
extern int D_00450C48_3020[] __asm__("D_00450C48");

void func_003E3020(int arg0, int arg1) {
    int temp_3;

    D_00450C48_3020[0] = 0;
    SYNCTASK_add(func_003E33B0, 0, 0);
    temp_3 = D_00450C48_3020[0];
    D_00450C48_3020[0] = temp_3 | 2;
    if (arg1 != 0) {
        D_00450C48_3020[0] = temp_3 | 3;
        D_00450C44_3020[0] = 1;
        return;
    }
    D_00450C44_3020[0] = 2;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3098);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3208);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E32F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00427FE8(int);
extern int D_00450C40_0C40[] __asm__("D_00450C40");

int func_003E32F8(int arg0) {
    int temp_16;
    int temp_5;

    temp_5 = arg0 >> 0x18;
    temp_16 = arg0 & 0xFFFFFF;
    if (temp_5 == 2) {
        func_00427FE8(temp_16);
        if (D_00450C40_0C40[0] == temp_16) {
            D_00450C40_0C40[0] = -1;
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3350);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E33B0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3478);
#ifdef SKIP_ASM
int func_003E3478(int a0, int a1, int a2, int a3) {
    int t = a0 & 0xFFFFFF;
    func_00428168(t, a2, 0);
    func_00428600(t, a1, a3);
    iFILESYS_CommandCompleteCallback(1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E34E8);
#ifdef SKIP_ASM
extern void func_003E48D8(int, int, int, int);
extern void func_00428168(int, int, int);

void func_003E34E8(int arg0) {
    int temp_4;

    temp_4 = arg0 & 0xFFFFFF;
    if ((arg0 >> 0x18) == 1) {
        func_003E48D8(temp_4, 0, 0, 0);
        return;
    }
    func_00428168(temp_4, 0, 2);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3538);
#ifdef SKIP_ASM
int func_003E3538(int a0) {
    int sp0;
    int idx = a0 & 0xFFFFFF;

    if ((a0 >> 24) == 1) {
        func_003E48D8(idx, 0, 0, &sp0);
    } else {
        sp0 = 0;
    }
    return sp0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3588);
#ifdef SKIP_ASM
void func_00423DD0_3588(int) __asm__("func_00423DD0");
void func_003E3588(int a, int b, int c) {
    func_00423DD0_3588(c);
    // PORT: MIPS sync + EE ei (no C equivalent)
    __asm__ volatile("sync\n\tei");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E35B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct Cfg_35B0 { int f0, f4, f8, fc, f10, f14; } Cfg_35B0;
extern void cb_35B0(void) __asm__("func_003E3588");
extern void func_00423B20_35B0(int, void (*)(void), int) __asm__("func_00423B20");
extern int func_00423DA0_35B0(Cfg_35B0 *) __asm__("func_00423DA0");

void func_003E35B0(unsigned short arg0) {
    Cfg_35B0 c;
    int temp_2;

    c.f4 = 1;
    c.f8 = 0;
    c.f14 = 0;
    temp_2 = func_00423DA0_35B0(&c);
    func_00423B20_35B0(arg0, cb_35B0, temp_2);
    func_00423DE0(temp_2);
    func_00423DB0(temp_2);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3618);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E36F8);
#ifdef SKIP_ASM
extern int strlen();

int func_003E36F8(unsigned int arg0, int arg1) {
    int h = arg1;
    signed char *p = (signed char *)(arg0 + strlen(arg0)) - 1;

    do {
        signed char c = *p;
        p -= 1;
        h = h * 0x21 + c;
    } while ((unsigned int)p >= arg0);
    return h;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3758);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3968);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0051ED80_3968[] __asm__("D_0051ED80");

int func_003E3968(unsigned int *a, unsigned int *b) {
    long d = (long)*a - (long)*b;
    if (d < 0) return -1;
    if (d > 0) return 1;
    D_0051ED80_3968[0]++;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E39A8);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3AD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519C4C_3AD8[] __asm__("D_00519C4C");
void func_00423DD0_3AD8(int) __asm__("func_00423DD0");
void func_003E3AD8(void) {
    func_00423DD0_3AD8(D_00519C4C_3AD8[0]);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3B00);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3BE0);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E3D78);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4000);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00519C40_4000[] __asm__("D_00519C40");
void func_003E3D78_4000(void) __asm__("func_003E3D78");

int func_003E4000(void) {
    int t = D_00519C40_4000[0];
    if ((t & 6) == 6) {
        D_00519C40_4000[0] = t & ~6;
        func_003E3D78_4000();
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4040);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E44B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void SYNCTASK_del_44B0(void (*)(void)) __asm__("SYNCTASK_del");
extern void func_004008A0(int);
extern void func_00401718(int);
extern void func_00423BB0(int);
extern void func_00423BF0(int);
extern void func_00423DB0(int);
extern int D_00519C40_9C40[] __asm__("D_00519C40");
extern void func_003E4000_4000(void) __asm__("func_003E4000");

void func_003E44B0(void) {
    SYNCTASK_del_44B0(func_003E4000_4000);
    func_004008A0(0);
    func_00423BF0(D_00519C40_9C40[2]);
    func_00423BB0(D_00519C40_9C40[2]);
    func_00423DB0(D_00519C40_9C40[3]);
    func_00401718(5);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4508);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4648);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E48D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450C5C_48D8[] __asm__("D_00450C5C");
extern char *D_00519C78_48D8[] __asm__("D_00519C78");
extern char *strncpy(char *, const char *, int);

int func_003E48D8_48D8(int, char *, int *, int *) __asm__("func_003E48D8");

int func_003E48D8_48D8(int arg0, char *arg1, int *arg2, int *arg3) {
    char *e;
    e = D_00519C78_48D8[0] + (arg0 - 1) * (D_00450C5C_48D8[0] + 0xC);
    if (arg1 != 0) {
        strncpy(arg1, e + 0xC, D_00450C5C_48D8[0]);
    }
    if (arg2 != 0) {
        *arg2 = *(int *)(e + 8);
    }
    if (arg3 != 0) {
        *arg3 = *(int *)(e + 4);
    }
    return *(int *)(e + 8);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003E4508(int, int, int *);
extern int D_00450C5C_0C5C[] __asm__("D_00450C5C");
extern int D_00519C78_9C78[] __asm__("D_00519C78");

int func_003E4968(int a0) {
    int sp0;
    int r;

    if (func_003E4508(a0, 0, &sp0) == 0) {
        r = 0;
    } else {
        r = D_00519C78_9C78[0] + (sp0 - 1) * (D_00450C5C_0C5C[0] + 0xC);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E49B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void (*D_00450C78_0C78[])(void) __asm__("D_00450C78");

void func_003E49B8(void) {
    int i;
    for (i = 0x3F; i >= 0; i--) {
        void (*fn)(void) = D_00450C78_0C78[i];
        if (fn != 0) {
            fn();
        }
        D_00450C78_0C78[i] = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4A10);
#ifdef SKIP_ASM
extern void func_003E49B8(void);

void func_003E4A10(void) {
    func_003E49B8();
    __asm__ volatile("break 0xFFFF");  // PORT: trap
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4A30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450C78_4A30[] __asm__("D_00450C78");

void func_003E4A30(int a) {
    int i;
    for (i = 0; i < 0x40; i++) {
        if (D_00450C78_4A30[i] == a) return;
    }
    i = 0;
    while (i < 0x40) {
        if (D_00450C78_4A30[i] == 0) {
            D_00450C78_4A30[i] = a;
            break;
        }
        i++;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4AA0);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4AF0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4D68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00423AA0(int, int);
extern void func_00424880(int);
extern int D_00450DDC_0DDC[] __asm__("D_00450DDC");

void func_003E4D68(void) {
    volatile int *reg;

    if (D_00450DDC_0DDC[0] != 0) {
        reg = (volatile int *)0x10000810;
        *reg = 0;
        func_00424880(0xA);
        func_00423AA0(0xA, D_00450DDC_0DDC[0]);
        D_00450DDC_0DDC[0] = 0;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4DB8);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4E98);
#ifdef SKIP_ASM
extern int D_00450DCC;

int func_003E4E98(void)
{
    return *(volatile int*)&D_00450DCC;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4EA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450DEC_4EA8[] __asm__("D_00450DEC");

int func_003E4EA8(void) {
    int old = D_00450DEC_4EA8[0];
    int now = func_003E4E98();
    D_00450DEC_4EA8[0] = now;
    return now - old;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4EE8);
#ifdef SKIP_ASM
extern int D_00450DE8_4EE8[] __asm__("D_00450DE8");
extern int D_00450DEC_4EE8[] __asm__("D_00450DEC");
extern int D_00450DCC_4EE8[] __asm__("D_00450DCC");

// Resets the timer state.
void func_003E4EE8(void) {
    int *p = D_00450DE8_4EE8;
    D_00450DEC_4EE8[0] = 0;
    D_00450DCC_4EE8[0] = 0;
    p[0] = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4F08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003E4E98_4F08(void) __asm__("func_003E4E98");
extern int D_00450DE8_4F08[] __asm__("D_00450DE8");

void func_003E4F08(int arg0) {
    int *p = D_00450DE8_4F08;
    *p = func_003E4E98_4F08() + arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4F40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003E4F80();
extern void SYNCTASK_run_4F40(int) __asm__("SYNCTASK_run");
extern void func_003E5398_4F40(int) __asm__("func_003E5398");

void func_003E4F40(void) {
    while (func_003E4F80() == 0) {
        SYNCTASK_run_4F40(0);
        func_003E5398_4F40(0);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4F80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003E4E98();
extern int D_00450DE8_4F80[] __asm__("D_00450DE8");

int func_003E4F80(void) {
    int r = func_003E4E98() - D_00450DE8_4F80[0]; if (r > -1) return 1; return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E4FB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void SYNCTASK_run_4FB0(int) __asm__("SYNCTASK_run");
void func_003E5398_4FB0(int) __asm__("func_003E5398");

void func_003E4FB0(int arg0) {
    int end = func_003E4E98() + arg0;
    while (func_003E4E98() - end < 0) {
        SYNCTASK_run_4FB0(0);
        func_003E5398_4FB0(0);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5008);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450DC8_5008[4] __asm__("D_00450DC8");

int func_003E5008(void) {
    return D_00450DC8_5008[0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_00423C90_5018(void) __asm__("func_00423C90");
extern void func_00423C30_5018(int, int) __asm__("func_00423C30");
extern void func_003E5698_5018(void *) __asm__("func_003E5698");
extern int D_00450DF8_5018[] __asm__("D_00450DF8");
extern int D_0051ED88_5018[] __asm__("D_0051ED88");

void func_003E5018(void) {
    int t = func_00423C90_5018();
    D_00450DF8_5018[0] = 0x50533254;
    D_00450DF8_5018[1] = t;
    func_00423C30_5018(t, 100);
    func_003E5698_5018(D_0051ED88_5018);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5068);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E56E0(void *);
extern void func_003E6220_5068(int *, int) __asm__("func_003E6220");
extern int D_00450DF8_5068[] __asm__("D_00450DF8");
extern int D_0051ED88_5068[] __asm__("D_0051ED88");

void func_003E5068(void) {
    func_003E56E0(D_0051ED88_5068);
    func_003E6220_5068(D_00450DF8_5068, 8);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5098);
#ifdef SKIP_ASM
extern void func_003E50C8(int, int, int, int, int, int);

void func_003E5098(int arg0, int arg1, int arg2, int arg3, int arg4) {
    func_003E50C8(arg0, arg1, 0, arg2, arg3, arg4);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E50C8);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E51A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00423C00_51A0(int) __asm__("func_00423C00");
extern int D_00450DE4_51A0[] __asm__("D_00450DE4");

void func_003E51A0_51A0(char *arg0) __asm__("func_003E51A0");
void func_003E51A0_51A0(char *arg0) {
    int h;
    int st[12];

    if (arg0 == (char*)0xFFFFFFFF) {
        h = func_00423C90();
    } else {
        h = *(int*)(arg0 + 4);
    }
    if (D_00450DE4_51A0[0] != 0) {
        func_00423CB0(h, st);
    } else {
        func_00423CA0(h, st);
    }
    if (st[0] & 0xF) {
        if (D_00450DE4_51A0[0] != 0) {
            func_00423C00_51A0(h);
        } else {
            func_00423BF0(h);
        }
        func_00423BB0(h);
        return;
    }
    if (st[0] & 0x10) {
        func_00423BB0(h);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5268);
#ifdef SKIP_ASM
extern void func_003E51A0();

void func_003E5268(void) {
    func_003E51A0();
}
#endif

void func_003E5288(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5290);
#ifdef SKIP_ASM
extern void func_00424C50(int);

void func_003E5290(int a, int b, int c) {
    func_00424C50(c);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", THREAD_yieldticks);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void abm_YT(char *) __asm__("REAL_abortmessage");
extern int f5008_YT(void) __asm__("func_003E5008");
extern int f3B20_YT(int, char *, int) __asm__("func_00423B20");
extern void f3C50_YT(int) __asm__("func_00423C50");
extern int f3C90_YT(void) __asm__("func_00423C90");
extern void f3CA0_YT(int, int *) __asm__("func_00423CA0");
extern void f3CB0_YT(int, int *) __asm__("func_00423CB0");
extern void f3CC0_YT(void) __asm__("func_00423CC0");
extern void f4CE8_YT(int) __asm__("func_00424CE8");
extern int D_0DA0_YT[] __asm__("D_00450DA0");
extern int D_0DE4_YT[] __asm__("D_00450DE4");
extern char D_5E20_YT[] __asm__("D_00495E20");
extern char fE5290_YT[] __asm__("func_003E5290");

void THREAD_yieldticks(int a0) {
    int buf[12];
    int t16;
    if (a0 > 0) {
        t16 = ((a0 * D_0DA0_YT[0]) / f5008_YT()) & 0xFFFF;
        if (f3B20_YT(t16, fE5290_YT, f3C90_YT()) < 0) {
            abm_YT(D_5E20_YT);
        }
        f3CC0_YT();
        return;
    }
    if (D_0DE4_YT[0] != 0) {
        f3CB0_YT(f3C90_YT(), buf);
        f4CE8_YT(buf[6]);
        return;
    }
    f3CA0_YT(f3C90_YT(), buf);
    f3C50_YT(buf[6]);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5398);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5440);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450DFC_0DFC[] __asm__("D_00450DFC");

int func_003E5440(char *arg0) {
    int cur = func_00423C90();
    if (arg0 == 0) {
        return cur == D_00450DFC_0DFC[0];
    }
    if (arg0 == (char *)-1) {
        return 1;
    }
    return cur == *(int *)(arg0 + 4);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_00423C90();
extern void func_00423CA0(int, void *);
extern void func_00423CB0(int, void *);
extern int D_00450DE4_5498[] __asm__("D_00450DE4");
extern int D_00450DFC_5498[] __asm__("D_00450DFC");

int func_003E5498(int *a0) {
    int sp[12];
    int t;
    if (a0 == 0) {
        t = D_00450DFC_5498[0];
    } else if (a0 == (int *)-1) {
        t = func_00423C90();
    } else {
        t = a0[1];
    }
    if (D_00450DE4_5498[0] != 0) {
        func_00423CB0(t, sp);
    } else {
        func_00423CA0(t, sp);
    }
    return sp[6];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5508);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00423C30_5508(int, int) __asm__("func_00423C30");
extern void func_00423C40_5508(int, int) __asm__("func_00423C40");
extern int func_00423C90_5508(void) __asm__("func_00423C90");
extern int D_00450DE4_5508[] __asm__("D_00450DE4");
extern int D_00450DFC_5508[] __asm__("D_00450DFC");

int func_003E5508(void *arg0, int arg1) {
    int var_4;

    if (arg0 == 0) {
        var_4 = D_00450DFC_5508[0];
    } else if (arg0 == (void *)0xFFFFFFFF) {
        var_4 = func_00423C90_5508();
    } else {
        var_4 = (*(int *)((char*)(arg0) + (4)));
    }
    if (D_00450DE4_5508[0] != 0) {
        func_00423C40_5508(var_4, arg1);
    } else {
        func_00423C30_5508(var_4, arg1);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5580);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00423CA0(int, void *);
extern void func_00423CB0(int, void *);
extern int D_00450DE4_0DE4[] __asm__("D_00450DE4");
typedef struct { int pad; int f4; } A_5580;

int func_003E5580(A_5580 *arg0) {
    struct { int v; char rest[0x2C]; } st;
    int r;

    if (D_00450DE4_0DE4[0] != 0) {
        func_00423CB0(arg0->f4, &st);
    } else {
        func_00423CA0(arg0->f4, &st);
    }
    r = 0;
    if ((st.v & 0x10) || st.v == 0) {
        r = 1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E55E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void THREAD_yieldticks_55E0(int) __asm__("THREAD_yieldticks");
extern int func_003E4E98_55E0() __asm__("func_003E4E98");
extern void func_00423CA0_55E0(int, int *) __asm__("func_00423CA0");

int func_003E55E0(int *arg0, int arg1) {
    int sp[12];
    int temp_16;
    int temp_18;

    temp_18 = func_003E4E98_55E0() + arg1;
    temp_16 = arg0[1];
    do {
        func_00423CA0_55E0(temp_16, sp);
        if ((sp[0] & 0x10) || sp[0] == 0) break;
        THREAD_yieldticks_55E0(0);
    } while (arg1 == 0 || temp_18 < func_003E4E98_55E0());
    return sp[0] == 0x10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5678);
#ifdef SKIP_ASM
extern void func_00423BE0();

void func_003E5678(void) {
    func_00423BE0();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5698);
#ifdef SKIP_ASM
typedef struct { int a; int b; int c; int d[5]; } S_5698;
extern int func_00423DA0(S_5698 *);

int func_003E5698(int *self) {
    S_5698 s;
    self[2] = 0;
    self[1] = 0;
    s.b = 1;
    s.c = 1;
    self[3] = func_00423DA0(&s);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E56E0);
#ifdef SKIP_ASM
extern void func_00423DB0(int);

void func_003E56E0(void *arg0) {
    func_00423DB0((*(int *)((char*)(arg0) + (0xC))));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", MUTEX_lock);
#ifdef SKIP_ASM
extern int func_00423C90();
extern void func_00423DE0(int);

void MUTEX_lock(void *arg0) {
    if ((*(int *)((char*)(arg0) + (4))) == func_00423C90()) {
        (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) + 1);
        return;
    }
    func_00423DE0((*(int *)((char*)(arg0) + (0xC))));
    (*(int *)((char*)(arg0) + (4))) = func_00423C90();
    (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) + 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", MUTEX_unlock);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_00423C90();
extern void func_00423DC0(int);
extern void func_00423DD0(int);
extern int D_00450DE4_5760[] __asm__("D_00450DE4");

void MUTEX_unlock_5760(void *arg0) __asm__("MUTEX_unlock");
void MUTEX_unlock_5760(void *arg0) {
    int *p = (int *)arg0;
    if (p[1] == func_00423C90()) {
        if (--p[2] != 0) return;
        p[1] = 0;
    }
    if (D_00450DE4_5760[0] != 0) {
        func_00423DD0(p[3]);
    } else {
        func_00423DC0(p[3]);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", SYNCTASK_init);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0051ED98_57D0[] __asm__("D_0051ED98");
void func_003E6448_57D0(char *, int, int) __asm__("func_003E6448");
void SYNCTASK_init(void) {
    func_003E6448_57D0(D_0051ED98_57D0, 0, 0x100);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", SYNCTASK_add);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", SYNCTASK_del);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int fn; int b; int c; int d; } STsk_5924;
extern STsk_5924 D_0051ED98_ED98[] __asm__("D_0051ED98");

void SYNCTASK_del(int arg0) {
    int i = 0;

    while (i < 16 && D_0051ED98_ED98[i].fn != arg0) i++;
    if (i < 16 && D_0051ED98_ED98[i].fn == arg0) D_0051ED98_ED98[i].fn = 0;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", SYNCTASK_run);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5A10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int SYNCTASK_run_5A10(int) __asm__("SYNCTASK_run");

int func_003E5A10(int arg0) {
    int temp_16;
    int var_17;

    var_17 = 0;
    temp_16 = func_003E4E98() + arg0;
    while (func_003E4E98() < temp_16 && var_17 == 0) {
        var_17 = SYNCTASK_run_5A10(0);
    }
    return var_17;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5A78);
#ifdef SKIP_ASM
extern char D_00451250[];

void func_003E5A78(int arg0, int arg1) {
    char *temp_4;

    temp_4 = D_00451250 + arg0 * 0xC;
    (*(int *)((char*)(temp_4) + (8))) = (int) (((*(int *)((char*)(temp_4) + (8))) & ~1) | (arg1 & 1));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5AA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_5AA8 { int a; unsigned int b0 : 1; unsigned int b1 : 1; unsigned int rest : 30; };
extern struct E_5AA8 D_00450E08_5AA8[] __asm__("D_00450E08");

void func_003E5AA8(int idx, int val) {
    int i;
    if (idx == 0) {
        for (i = 0; i < 64; i++) {
            D_00450E08_5AA8[i].b0 = (val != 0);
        }
    } else if (idx == 1) {
        for (i = 0; i < 64; i++) {
            if (D_00450E08_5AA8[i].b1) {
                D_00450E08_5AA8[i].b0 = (val != 0);
            }
        }
    } else {
        D_00450E08_5AA8[idx].b0 = (val != 0);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5B60);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5C60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00451008_5C60[4] __asm__("D_00451008");

void func_003E5C60(void) {
    if (D_00451008_5C60[0] != 0) {
        D_00451008_5C60[0] = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5C78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_5C78 { int a; unsigned int b0 : 1; unsigned int rest : 31; };
struct H_5C78 { int a; void (*fn)(int, char *); unsigned int b0 : 1; unsigned int rest : 31; };
extern int D_00451008_5C78[] __asm__("D_00451008");
extern struct E_5C78 D_00450E08_5C78[] __asm__("D_00450E08");
extern struct H_5C78 D_00451250_5C78[] __asm__("D_00451250");

void func_003E5C78_5C78(int, char *, char *) __asm__("func_003E5C78");
void func_003E5C78_5C78(int idx, char *fmt, char *ap) {
    char buf[0x2000];
    int h;
    if (D_00451008_5C78[0] == 0) {
        func_003E5B60();
    }
    if (D_00450E08_5C78[idx].b0) {
        func_004186C8(buf, fmt, ap);
        h = (int)D_00451250_5C78;
        do {
            if (((struct H_5C78 *)h)->b0) {
                if (((struct H_5C78 *)h)->fn) {
                    ((struct H_5C78 *)h)->fn(idx, buf);
                }
            }
            h += 12;
        } while (h < (int)D_00451250_5C78 + 0x60);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5D30);
#ifdef SKIP_ASM
extern void func_003E5C78(char *, const char *, char *);

// PORT: SN-specific va_start
void func_003E5D30(char *dst, const char *fmt, ...) {
    char *ap;
    ap = (char*)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_003E5C78(dst, fmt, ap);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5D78);
#ifdef SKIP_ASM
extern void func_003E5C78_5D78(int, int, char *) __asm__("func_003E5C78");

void func_003E5D78(int a0, ...) {
    char *ap;
    // PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
    ap = (char *)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_003E5C78_5D78(2, a0, ap);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5DC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_5DC8 { int a; int b; int c; };
extern void func_003E5A78(int, int);
extern void func_003E5B60(void);
extern int D_00451008_5DC8[] __asm__("D_00451008");
extern struct S_5DC8 D_00451250_5DC8[] __asm__("D_00451250");

void func_003E5DC8(int a0, int a1) {
    if (D_00451250_5DC8[a0].b != 0) {
        if (D_00451008_5DC8[0] == 0) {
            func_003E5B60();
        }
        func_003E5A78(a0, a1);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5E38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E5B60(void);
extern char D_00451250_1250[] __asm__("D_00451250");
extern int D_00451008_1008[] __asm__("D_00451008");

int func_003E5E38(int a0) {
    char *b;
    if (D_00451008_1008[0] == 0) {
        func_003E5B60();
    }
    b = D_00451250_1250 + a0 * 12;
    return *(int *)(b + 8) & 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5E88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_5E88 { int a; int b; int c; };
extern void func_003E5B60(void);
extern struct S_5E88 D_00451250_5E88[] __asm__("D_00451250");
extern int D_00451008_5E88[] __asm__("D_00451008");

void func_003E5E88(int a0, int a1, int a2) {
    if (D_00451008_5E88[0] == 0) {
        func_003E5B60();
    }
    D_00451250_5E88[a0].a = a1;
    D_00451250_5E88[a0].b = a2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5EF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E5AA8(int, int);
extern void func_003E5B60(void);
extern int D_00451008_1008[] __asm__("D_00451008");

void func_003E5EF8(int a0, int a1) {
    if (D_00451008_1008[0] == 0) {
        func_003E5B60();
    }
    func_003E5AA8(a0, a1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5F48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_5F48 { int a; int b; };
extern struct P_5F48 D_00450E08_5F48[] __asm__("D_00450E08");
extern int D_00451008_5F48[] __asm__("D_00451008");
void func_003E5B60_5F48(void) __asm__("func_003E5B60");

int func_003E5F48(int arg0) {
    if (D_00451008_5F48[0] == 0) {
        func_003E5B60_5F48();
    }
    return (D_00450E08_5F48 + arg0)->b & 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5F98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450E08_0E08[] __asm__("D_00450E08");
extern int D_00451008_1008[] __asm__("D_00451008");
void func_003E5B60_5F98(void) __asm__("func_003E5B60");

void func_003E5F98(int arg0, int arg1) {
    if (D_00451008_1008[0] == 0) {
        func_003E5B60_5F98();
    }
    D_00450E08_0E08[arg0 * 2] = arg1;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E5FF0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", REAL_abortmessage);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
#define REAL_abortmessage_va_start(ap)                                   \
    (ap = (char*)__builtin_next_arg()                                    \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern int func_004186C8(char *dst, const char *fmt, char *ap);
extern void (*D_00450DD8_6070[])(char *, char *) __asm__("D_00450DD8");
extern char D_00495EE8_6070[] __asm__("D_00495EE8");

void REAL_abortmessage(const char *fmt, ...) {
    char buf[0x200];
    if (fmt) {
        char *ap;
        REAL_abortmessage_va_start(ap);
        func_004186C8(buf, fmt, ap);
    } else {
        buf[0] = 0;
    }
    D_00450DD8_6070[0](D_00495EE8_6070, buf);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", SYSTEM_abortmessage);
#ifdef SKIP_ASM
extern void func_003E4A10(void);
extern void func_003E5D30_60E8(int, char *, ...) __asm__("func_003E5D30");
extern int func_004186C8_60E8(char *, char *, char *) __asm__("func_004186C8");
extern char D_00495EF0[];
extern char D_00495F00[];
extern char *D_0045100C_100C[] __asm__("D_0045100C");
extern int D_00451010_1010[] __asm__("D_00451010");

void SYSTEM_abortmessage(char *fmt, ...) {
    char buf[512];
    // PORT: hand-rolled EE EABI va_start
    if (fmt != 0) {
        func_004186C8_60E8(buf, fmt, (char *)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0));
    } else {
        buf[0] = 0;
    }
    func_003E5D30_60E8(2, D_00495EF0, buf);
    if (D_0045100C_100C[0] != 0) {
        func_003E5D30_60E8(2, D_00495F00, D_0045100C_100C[0], D_00451010_1010[0]);
    }
    func_003E4A10();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6188);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E6574_6188(unsigned char *, unsigned char *, int) __asm__("func_003E6574");
void func_003E6188_6188(unsigned char *dst, unsigned char *src, int n) __asm__("func_003E6188");

void func_003E6188_6188(unsigned char *dst, unsigned char *src, int n) {
    unsigned char *e;
    if (src >= dst || dst >= (e = src + n)) {
        func_003E6574_6188(dst, src, n);
    } else {
        dst += n;
        n--;
        src = e;
        while (n != -1) {
            src--;
            dst--;
            *dst = *src;
            n--;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E61F8);
#ifdef SKIP_ASM
extern void func_003E6188(int, int);

void func_003E61F8(int arg0, int arg1) {
    func_003E6188(arg1, arg0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6220);
#ifdef SKIP_ASM
extern void func_003E6448(int, int, int);

void func_003E6220(int a, int b) {
    func_003E6448(a, 0, b);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6240);
#ifdef SKIP_ASM
int func_003E6240(unsigned int a) {
    int r = 0;
    if (a - 0x100000 <= 0x7EFFFFF || a - 0x10000000 <= 0x4000000 ||
        a - 0x20100000 <= 0x7EFFFFF || a - 0x30100000 <= 0x7EFFFFF ||
        a - 0x70000000 < 0x4000) {
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E62B0);
#ifdef SKIP_ASM
extern int D_00450DA4[];

void func_003E62B0(void) {
    if (D_00450DA4[0] != 0) {
        __asm__ volatile("break 6");  // PORT: trap
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E62D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned short D_00451018_1018[] __asm__("D_00451018");

int func_003E62D0(unsigned char *arg0, int arg1, int arg2) {
    unsigned char *p;
    unsigned int crc;
    unsigned char *end;
    p = arg0;
    crc = arg2 & 0xFFFF;
    end = p + arg1;
    if (p < end) {
        do {
            unsigned char c = *p;
            p += 1;
            crc = D_00451018_1018[(c ^ crc) & 0xFF] ^ (crc >> 8);
        } while (p < end);
    }
    return crc & 0xFFFF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6328);
#ifdef SKIP_ASM
extern int D_00451218[];

/* Shell sort of keys[] (descending) carrying vals[] along, gap table D_00451218 (same as func_0032DA40). */
void func_003E6328(int n, int *keys, int *vals) {
    int k = 1;
    int gap;
    int i;
    while (D_00451218[k] < n) {
        k++;
    }
    for (;;) {
        gap = D_00451218[--k];
        for (i = gap; i < n; i++) {
            int key = keys[i];
            int val = vals[i];
            int j = i - gap;
            do {
                if (keys[j] >= key) {
                    break;
                }
                keys[j + gap] = keys[j];
                vals[j + gap] = vals[j];
                j -= gap;
            } while (j >= 0);
            keys[j + gap] = key;
            vals[j + gap] = val;
        }
        if (gap < 2) {
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6428);
#ifdef SKIP_ASM
extern void func_004175C8(int);

void func_003E6428(int a, int b) {
    func_004175C8(b);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6448);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6574);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E665C);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6690);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00450DA0_0DA0[] __asm__("D_00450DA0");

void func_003E6690(int arg0) {
    switch (arg0) {
    case 1:
        D_00450DA0_0DA0[0] = 0x3D86;
        return;
    case 2:
        D_00450DA0_0DA0[0] = 0x3D09;
        return;
    case 3:
        D_00450DA0_0DA0[0] = 0x7080;
        return;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E66F0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E67F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0051EE98_67F8[] __asm__("D_0051EE98");
extern void func_00256BD8(int *);
extern void func_003F4C68(int *, int, int, int, int, int, int, int, int, int);
extern void func_003F4C98(int *, int, int);

void func_003E67F8(int *arg0) {
    func_003F4C98(D_0051EE98_67F8, 0x676D6C6B, 0x64657374);
    func_003F4C68(D_0051EE98_67F8, 0, *arg0, 0, 0, 0, 0, 0, 1, 0);
    func_00256BD8(arg0);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6878);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6958);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6A70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char b[4]; } U4_6A70;
extern void func_0041605C_6A70(short *, int, int) __asm__("func_0041605C");

int func_003E6A70(char *arg0, short **arg1) {
    if (arg1 != 0) {
        int t = *(int *)(arg0 + 0x160);
        if (t < *(int *)(arg0 + 0x164)) {
            *(U4_6A70 *)*arg1 = *(U4_6A70 *)(((*(int *)(arg0 + 0x16C) + t) & 0x0FFFFFFF) | 0x20000000);
            func_0041605C_6A70(*arg1, ((*(int *)(arg0 + 0x16C) + *(int *)(arg0 + 0x160)) & 0x0FFFFFFF) | 0x20000000, **arg1);
        } else {
            *arg1 = 0;
        }
    }
    return *(int *)(arg0 + 0x164) - *(int *)(arg0 + 0x160);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6B10);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6C80);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6D78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003F4C68_6D78(int *, int, int, int, int *, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_6D78(int *, int, int) __asm__("func_003F4C98");
extern int D_0051EED8_6D78[] __asm__("D_0051EED8");

int func_003E6D78_impl(int *p, int b, int c) __asm__("func_003E6D78");
int func_003E6D78_impl(int *p, int b, int c) {
    int out;

    func_003F4C98_6D78(D_0051EED8_6D78, 0x676D6C6B, 0x6374726C);
    func_003F4C68_6D78(D_0051EED8_6D78, 1, *p, b, &c, 4, 0, 0, 1, &out);
    return out;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6E08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003F4C68_6E08(int *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_6E08(int *, int, int) __asm__("func_003F4C98");

int func_003E6E08(void) {
    int sp10[4];
    int sp20;

    func_003F4C98_6E08(sp10, 0x676D7574, 0x63726561);
    func_003F4C68_6E08(sp10, 1, 0, 0, 0, 0, 0, 0, 1, &sp20);
    return sp20;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6E70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003F4C68_6E70(int *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_003F4C98_6E70(int *, int, int) __asm__("func_003F4C98");

void func_003E6E70(int arg0) {
    int sp10[4];

    func_003F4C98_6E70(sp10, 0x676D7574, 0x64657374);
    func_003F4C68_6E70(sp10, 1, arg0, 0, 0, 0, 0, 0, 1, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6ED8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003F4C68_6ED8(int *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_003F4C98_6ED8(int *, int, int) __asm__("func_003F4C98");

void func_003E6ED8(int arg0) {
    int sp10[4];

    func_003F4C98_6ED8(sp10, 0x676D7574, 0x72736574);
    func_003F4C68_6ED8(sp10, 1, arg0, 0, 0, 0, 0, 0, 1, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6F40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003F4C68_6F40(int *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_6F40(int *, int, int) __asm__("func_003F4C98");

int func_003E6F40_impl(int a, int b, int c) __asm__("func_003E6F40");
int func_003E6F40_impl(int a, int b, int c) {
    int sp10[4];
    int sp20;

    func_003F4C98_6F40(sp10, 0x676D7574, 0x636F6E6E);
    func_003F4C68_6F40(sp10, 1, a, b, c, -1, 0, 0, 1, &sp20);
    return sp20;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E6FC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003F4C68_6FC8(void *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_6FC8(void *, int, int) __asm__("func_003F4C98");
struct S_6FC8 { int a[4]; int out; };

int func_003E6FC8(int arg0) {
    struct S_6FC8 s;

    func_003F4C98_6FC8(&s, 0x676D7574, 0x636F6D70);
    func_003F4C68_6FC8(&s, 1, arg0, 0, 0, 0, 0, 0, 1, &s.out);
    return s.out;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7038);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003F4C68_7038(int *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_7038(int *, int, int) __asm__("func_003F4C98");

int func_003E7038_impl(int a, int b) __asm__("func_003E7038");
int func_003E7038_impl(int a, int b) {
    int sp10[4];
    int sp20;

    func_003F4C98_7038(sp10, 0x676D7574, 0x73746174);
    func_003F4C68_7038(sp10, 1, a, b, 0, 0, 0, 0, 1, &sp20);
    return sp20;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E70B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003F4C68_70B8(int *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_003F4C98_70B8(int *, int, int) __asm__("func_003F4C98");

void func_003E70B8(int arg0) {
    int sp10[4];

    func_003F4C98_70B8(sp10, 0x676D7574, 0x73746174);
    func_003F4C68_70B8(sp10, 1, arg0, 0, 0, 0, 0, 0, 1, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003F4C68_7120(int *, int, int, int, char *, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_003F4C98_7120(int *, int, int) __asm__("func_003F4C98");
extern int sprintf_7120(char *, int *, int, int) __asm__("sprintf");
extern int D_004A4860_7120[] __asm__("D_004A4860");

void func_003E7120(int arg0, int arg1, int arg2) {
    char sp10[256];
    int sp110[4];

    sprintf_7120(sp10, D_004A4860_7120, arg1, arg2);
    func_003F4C98_7120(sp110, 0x676D7574, 0x61647674);
    func_003F4C68_7120(sp110, 1, arg0, 0, sp10, -1, 0, 0, 1, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E71B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003F4C68_71B0(int *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern int func_003F4C98_71B0(int *, int, int) __asm__("func_003F4C98");

void func_003E71B0(int arg0) {
    int sp10[4];

    func_003F4C98_71B0(sp10, 0x676D7574, 0x77697468);
    func_003F4C68_71B0(sp10, 1, arg0, 0, 0, 0, 0, 0, 1, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7218);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003F4C68_7218(int *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_7218(int *, int, int) __asm__("func_003F4C98");
extern char D_004A4868_7218[] __asm__("D_004A4868");

int func_003E7218_impl(int a, int b, char *c) __asm__("func_003E7218");
int func_003E7218_impl(int a, int b, char *c) {
    int sp10[4];
    int sp20;

    if (c == 0) {
        c = D_004A4868_7218;
    }
    func_003F4C98_7218(sp10, 0x676D7574, 0x6C6F6361);
    func_003F4C68_7218(sp10, 1, a, 0, (int)c, -1, 0, 0, 1, &sp20);
    return sp20;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E72A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003F4C68_72A0(int *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_72A0(int *, int, int) __asm__("func_003F4C98");
extern char D_004A4868_72A0[] __asm__("D_004A4868");

int func_003E72A0_impl(int a, char *b, int c, int d) __asm__("func_003E72A0");
int func_003E72A0_impl(int a, char *b, int c, int d) {
    int sp10[4];
    int sp20;

    if (b == 0) {
        b = D_004A4868_72A0;
    }
    func_003F4C98_72A0(sp10, 0x676D7574, 0x71756572);
    func_003F4C68_72A0(sp10, 5, a, 0, (int)b, -1, c, d, 1, &sp20);
    return sp20;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7340);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E73E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00256BD8_73E0(void *) __asm__("func_00256BD8");
extern int func_003F4C68_73E0(void *, int, int, int, int, int, int, int, int, int) __asm__("func_003F4C68");
extern void func_003F4C98_73E0(void *, int, int) __asm__("func_003F4C98");
struct S_73E0 { int a[4]; };

void func_003E73E0(void *arg0) {
    struct S_73E0 s;

    func_003F4C98_73E0(&s, 0x70696E67, 0x64657374);
    func_003F4C68_73E0(&s, 0, *(int *)((char*)arg0 + 0xC), 0, 0, 0, 0, 0, 1, 0);
    func_00256BD8_73E0(arg0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7450);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003F4C68_7450(int *, int, int, int, int, int, int, int, int, int *) __asm__("func_003F4C68");
extern void func_003F4C98_7450(int *, int, int) __asm__("func_003F4C98");

int func_003E7450_impl(char *o, int a, int b, int c) __asm__("func_003E7450");
int func_003E7450_impl(char *o, int a, int b, int c) {
    int sp10[4];
    int sp20;

    func_003F4C98_7450(sp10, 0x70696E67, 0x72657175);
    func_003F4C68_7450(sp10, 1, *(int *)(o + 0xC), a, b, c, 0, 0, 1, &sp20);
    return sp20;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E74E8);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7500);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E76A8);
#ifdef SKIP_ASM
extern void func_004186C8_76A8(char *, const char *, char *) __asm__("func_004186C8");

// PORT: SN-specific va_start
void func_003E76A8(char *self, const char *fmt, ...) {
    char buf[0x1000];
    char *ap;
    void (*cb)(int, char *);
    ap = (char*)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_004186C8_76A8(buf, fmt, ap);
    cb = *(void (**)(int, char *))(self + 0x548);
    if (cb != 0) {
        cb(*(int *)(self + 0x544), buf);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7718);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_002591E8_7718(int) __asm__("func_002591E8");

void *func_003E7718(char *arg0, int arg1, int arg2, int arg3) {
    char **pp;
    char *n;
    char *cur;
    char *nx;
    char *h;

    n = func_002591E8_7718(0x44);
    if (n != 0) {
        *(int*)(n + 4) = arg1;
        *(int*)(n + 0x38) = arg2;
        *(int*)(n + 0x3C) = arg3;
        pp = (char**)(arg0 + 0x53C);
        *(char**)(n + 0x40) = 0;
        *(int*)n = *(int*)(arg0 + 0x54C);
        h = *(char**)(arg0 + 0x53C);
        *(int*)(arg0 + 0x54C) = (*(int*)(arg0 + 0x54C) + 1) & 0x7FFFFFFF;
        if (h != 0 && *(int*)(h + 4) != 0x70696E67) {
            do {
                cur = *pp;
                nx = *(char**)(cur + 0x40);
                pp = (char**)(cur + 0x40);
            } while (nx != 0 && *(int*)(nx + 4) != 0x70696E67);
        }
        cur = *pp;
        *pp = n;
        *(char**)(n + 0x40) = cur;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E77F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct N_77F0 { int pad0; int key; int w[14]; struct N_77F0 *next; } N_77F0;
extern void *memset_77F0(void *, int, unsigned int) __asm__("func_00416210");
extern void func_00259210_77F0(void *) __asm__("func_00259210");
int func_003E77F0(char *self, N_77F0 *dst, int key) {
    N_77F0 *n;
    memset_77F0(dst, 0, 0x44);
    n = *(N_77F0 **)(self + 0x53C);
    if (n != 0 && (n->key == key || key == 0x44515545)) {
        *(N_77F0 **)(self + 0x53C) = n->next;
        *dst = *n;
        func_00259210_77F0(n);
    }
    return *(int *)(self + 0x53C) != 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7918);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct N_7918 { int f0; int tag; int id; int fC; int f10; int f14; char name[0x28]; struct N_7918 *next; };
struct L_7918 { char pad[0x53C]; struct N_7918 *head; int cnt; };
extern int func_004165A8_7918(char *, char *) __asm__("func_004165A8");
extern void func_00259210_7918(void *) __asm__("func_00259210");

int func_003E7918(struct L_7918 *l, struct N_7918 *out, char *name, int id, int t) {
    struct N_7918 **pp = &l->head;
    struct N_7918 *n;

    while (*pp != 0) {
        n = *pp;
        if (n->tag == 0x70696E67 &&
            ((n->id == id && func_004165A8_7918(name, n->name) == 0) || (id == -1 && n->fC < t))) {
            *pp = n->next;
            *out = *n;
            func_00259210_7918(n);
            l->cnt--;
            return 1;
        }
        pp = &(*pp)->next;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7AC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003E77F0_7AC0(int, void *, int) __asm__("func_003E77F0");

void func_003E7AC0(int arg0) {
    char buf[0x50];
    while (func_003E77F0_7AC0(arg0, buf, 0x44515545) != 0) {
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7B00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003EE3E0(int, int, void *);
extern void *func_003EE468(int, int);
extern int func_003EEEE8(int);
extern void sprintf(void *, int *, int);
extern int D_004A4870_7B00[] __asm__("D_004A4870");

void func_003E7B00(void *arg0, int arg1, int arg2) {
    int temp_2;
    int temp_4;
    void *temp_2_2;

    temp_4 = (*(int *)((char*)(arg0) + (0x310)));
    if (temp_4 != 0) {
        temp_2 = func_003EEEE8(temp_4);
        if (temp_2 != 0) {
            temp_2_2 = func_003EE468((*(int *)((char*)(arg0) + (0x314))), temp_2);
            if ((temp_2_2 != 0) && (arg2 != (*(int *)((char*)(temp_2_2) + (0x10))))) {
                (*(int *)((char*)(temp_2_2) + (0x10))) = arg2;
                sprintf(temp_2_2 + 0x14, D_004A4870_7B00, arg2);
                func_003EE3E0((*(int *)((char*)(arg0) + (0x314))), temp_2, temp_2_2);
            }
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7BA0);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7C40);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7F58);
#ifdef SKIP_ASM
void func_003E7F58(void *arg0) {
    (*(unsigned *)((char*)(arg0) + (0x20))) = 0;
    (*(unsigned *)((char*)(arg0) + (0x18))) = 0;
    (*(unsigned *)((char*)(arg0) + (0x1C))) = 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7F70);
#ifdef SKIP_ASM
void func_003E7F70(char *arg0, int arg1, int arg2) {
    int sp[4];
    int (*fn)(char *, int *, int);

    *(int *)(arg0 + 0xC) = 0x7465726D;
    *(int *)(arg0 + 8) |= arg2;
    func_003E7F58(arg0);
    fn = *(int (**)(char *, int *, int))(arg0 + 0x52C);
    if (fn != 0) {
        sp[0] = 3; sp[1] = 0x64697363; sp[2] = arg1; sp[3] = 0;
        fn(arg0, sp, *(int *)(arg0 + 0x530));
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E7FF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_004A48A8_7FF0[] __asm__("D_004A48A8");
extern void *func_002591E8_7FF0(int) __asm__("func_002591E8");
extern void func_00416210_7FF0(void *, int, int) __asm__("func_00416210");
extern char *strchr_7FF0(char *, int) __asm__("strchr");
extern void cDirtysock_tag_TagFieldDupl_7FF0(void *, int, char *) __asm__("cDirtysock_tag_TagFieldDupl");
extern void cDirtysock_tag_TagFieldSetString_7FF0(void *, int, char *, char *) __asm__("cDirtysock_tag_TagFieldSetString");
extern int func_003F5478_7FF0(int) __asm__("func_003F5478");
extern int func_003E7340_7FF0(void) __asm__("func_003E7340");
extern void func_003E80C0_7FF0(void *) __asm__("func_003E80C0");

void *func_003E7FF0(char *arg0, int arg1, int arg2) {
    char *r;
    int t;

    r = func_002591E8_7FF0(0x550);
    if (r != 0) {
        func_00416210_7FF0(r, 0, 0x550);
        if (arg0 != 0) {
            if (strchr_7FF0(arg0, 0x3D) != 0) {
                cDirtysock_tag_TagFieldDupl_7FF0(r + 0x34, 0x100, arg0);
            } else {
                cDirtysock_tag_TagFieldSetString_7FF0(r + 0x34, 0x100, D_004A48A8_7FF0, arg0);
            }
        }
        *(int*)r = func_003F5478_7FF0(0x8000);
        t = func_003E7340_7FF0();
        *(int*)(r + 0x544) = arg1;
        *(int*)(r + 0x548) = arg2;
        *(int*)(r + 4) = t;
        func_003E80C0_7FF0(r);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E80C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00259210_80C0(void *) __asm__("func_00259210");
extern void func_003E7F58_80C0(void *) __asm__("func_003E7F58");
extern void *func_003EE480_80C0(int, int) __asm__("func_003EE480");
extern int func_003EE9A0_80C0(int) __asm__("func_003EE9A0");
extern void func_003F5738_80C0(int) __asm__("func_003F5738");

struct E_80C0 { int a, b, c, d, e; };
struct S_80C0 { int f0, f4, f8, fC; char pad[0x310 - 0x10]; struct E_80C0 e[8]; char pad2[0x53C - 0x3B0]; char *f53C; int f540; char pad3[0x54C - 0x544]; int f54C; };

void func_003E80C0(struct S_80C0 *s) {
    int i, t;
    char *p;
    s->fC = 0x6F66666C;
    func_003F5738_80C0(s->f0);
    for (i = 0; i < 8; i++) {
        if (s->e[i].a != 0) {
            while ((t = func_003EE9A0_80C0(s->e[i].a)) != 0) {
                func_00259210_80C0(func_003EE480_80C0(s->e[i].b, t));
            }
        }
    }
    while (s->f53C != 0) {
        p = s->f53C;
        s->f53C = *(char **)(p + 0x40);
        func_00259210_80C0(p);
    }
    func_003E7F58_80C0(s);
    s->f540 = 0;
    s->f54C = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E81C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E80C0_81C8(void *) __asm__("func_003E80C0");
extern void func_003EE820_81C8(int) __asm__("func_003EE820");
extern void func_003EE260_81C8(int) __asm__("func_003EE260");
extern void func_003E73E0_81C8(int) __asm__("func_003E73E0");
extern void func_003F55B8_81C8(int) __asm__("func_003F55B8");
extern void func_00259210_81C8(void *) __asm__("func_00259210");

struct S_81C8 { int h; int f4; int pad[3]; };
struct O_81C8 { int f0; int f4; char pad[0x310 - 8]; struct S_81C8 s[8]; };

void func_003E81C8_impl(struct O_81C8 *self) __asm__("func_003E81C8");
void func_003E81C8_impl(struct O_81C8 *self) {
    int i;
    func_003E80C0_81C8(self);
    for (i = 0; i < 8; i++) {
        if (self->s[i].h != 0) {
            func_003EE820_81C8(self->s[i].h);
            func_003EE260_81C8(self->s[i].f4);
        }
    }
    func_003E73E0_81C8(self->f4);
    func_003F55B8_81C8(self->f0);
    func_00259210_81C8(self);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8248);
#ifdef SKIP_ASM
typedef struct { int a; int b; } E8248_pair;
typedef struct { char pad[0x514]; E8248_pair e[1]; } E8248_S;

void func_003E8248(E8248_S *s, int i, int a, int b) {
    s->e[i].a = a;
    s->e[i].b = b;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8260);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void cDirtysock_tag_TagFieldDupl_8260(void *, int, void *) __asm__("cDirtysock_tag_TagFieldDupl");
extern void func_003E76A8_8260(void *, int *, int, int) __asm__("func_003E76A8");
extern int func_003E7718_8260(void *, int, int, int) __asm__("func_003E7718");
extern void func_003E7AC0_8260() __asm__("func_003E7AC0");
extern void func_003E7F58_8260(void *) __asm__("func_003E7F58");
extern void func_003F5638_8260(int, int, int) __asm__("func_003F5638");
extern void func_003F5738_8260(int) __asm__("func_003F5738");
extern int func_003F5910_8260(int, int, int, void *, int) __asm__("func_003F5910");
extern int func_003F5D88_8260(int) __asm__("func_003F5D88");
extern int D_00495F30_8260[] __asm__("D_00495F30");

struct S_8260 { int f0, f4, f8, fC, f10, f14; char pad[0x34 - 0x18]; char f34[0x3B0 - 0x34]; int f3B0, f3B4; char f3B8; char pad2[0x50C - 0x3B9]; int f50C; };

int func_003E8260(struct S_8260 *s, int a1, int a2, int a3, int a4) {
    char buf[0x100];
    s->f3B4 = a1;
    s->f3B0 = a2;
    func_003E7AC0_8260();
    s->f50C = 0;
    func_003E7F58_8260(s);
    if (func_003E7718_8260(s, 0x736B6579, a3, a4) == 0) {
        return -1;
    }
    func_003F5738_8260(s->f0);
    func_003F5638_8260(s->f0, s->f3B4, s->f3B0);
    func_003E76A8_8260(s, D_00495F30_8260, s->f3B4, s->f3B0);
    cDirtysock_tag_TagFieldDupl_8260(buf, 0x100, s->f34);
    func_003F5910_8260(s->f0, 0x40646972, 0, buf, -1);
    s->fC = 0x72646972;
    s->f10 = func_003F5D88_8260(s->f0) + 0x1D4C0;
    s->f14 = func_003F5D88_8260(s->f0);
    s->f3B8 = 0;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8368);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E85B0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8650);
#ifdef SKIP_ASM
typedef struct { int a, b, c, d, e; } Q_8650;
typedef struct { char pad[0x314]; Q_8650 q[8]; } S_8650;

int func_003E8650(S_8650 *s, unsigned int i, int arg2, int arg3) {
    int r = 0;
    if (i < 8U) {
        s->q[i].b = arg2;
        s->q[i].c = arg3;
        r = s->q[i].a;
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8688);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8778);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8968);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8A28);
#ifdef SKIP_ASM
extern int func_003EEC88(int, int);

int func_003E8A28(int arg0, unsigned int arg1, int arg2) {
    int temp_4;

    if (arg1 < 8U) {
        temp_4 = (*(int *)((char*)(((arg1 * 0x14) + arg0)) + (0x310)));
        if (temp_4 != 0) {
            return func_003EEC88(temp_4, arg2) != 0;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8A70);
#ifdef SKIP_ASM
char *func_003E8A70(char *p, int k) {
    if (k == 0x75736572 || k == 0x61636374) return p + 0x134;
    if (k == 0x70657273) return p + 0x174;
    if (k == 0x726F6F6D) return p + 0x1C0;
    if (k == 0x706C6179) return (*(int *)(p + 0x2CC) == 0) ? 0 : p + 0x200;
    if (k == 0x646F776E) return (*(char *)(p + 0x3B8) == 0) ? 0 : p + 0x3B8;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8AF8);
#ifdef SKIP_ASM
void func_003E8AF8(void *arg0, int arg1) {
    if (arg1 == 0x706C6179) {
        (*(int *)((char*)(arg0) + (0x2CC))) = 0;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8B10);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8D70);
#ifdef SKIP_ASM
int func_003E8D70(void *arg0, int arg1) {
    int var_6;
    void **var_4;
    void *temp_2;
    void *temp_3;

    var_6 = 0;
    var_4 = arg0 + 0x53C;
    if ((*(int *)((char*)(arg0) + (0x53C))) != 0) {
        do {
            temp_3 = *var_4;
            if (((*(int *)((char*)(temp_3) + (0))) == arg1) || (arg1 == -1)) {
                (*(int *)((char*)(temp_3) + (0x38))) = 0;
                var_6 = 1;
            }
            temp_2 = *var_4;
            var_4 = temp_2 + 0x40;
        } while ((*(int *)((char*)(temp_2) + (0x40))) != 0);
    }
    return var_6;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8DC0);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8F08);
#ifdef SKIP_ASM
int func_003E8F08(char *arg0, unsigned arg1) {
    int a, b;
    if (arg1 == 0x73746174) return *(int *)(arg0 + 0xC);
    if (arg1 == 0x72666C67) return *(int *)(arg0 + 0x1BC);
    if (arg1 == 0x6578746E) return *(int *)(arg0 + 0x4FC);
    if (arg1 == 0x6C6F636C) return *(int *)(arg0 + 0x500);
    if (arg1 == 0x696E6174) {
        a = *(int *)(arg0 + 0x4FC);
        if (a != 0) {
            b = *(int *)(arg0 + 0x500);
            if (b != 0)
                return a != b;
        }
        return 0;
    }
    if (arg1 == 0x6D6F7265) return *(int *)(arg0 + 0x504);
    if (arg1 == 0x736C6F74) return *(int *)(arg0 + 0x510);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8FB8);
#ifdef SKIP_ASM
int func_003E8FB8(void *arg0) {
    int temp_2;
    int temp_3;

    temp_2 = (*(int *)((char*)(arg0) + (8)));
    temp_3 = temp_2 & (temp_2 - 1);
    (*(int *)((char*)(arg0) + (8))) = temp_3;
    return temp_2 ^ temp_3;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E8FD0);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E9160);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E9378);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E94F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int cDirtysock_tag_TagFieldFind_94F0(int, char *) __asm__("cDirtysock_tag_TagFieldFind");
extern int cDirtysock_tag_TagFieldGetNumber_94F0(int, int) __asm__("cDirtysock_tag_TagFieldGetNumber");
extern void func_003E76A8_94F0(void *, char *) __asm__("func_003E76A8");
extern int func_003F4330_94F0(void) __asm__("func_003F4330");
extern char D_00495F98_94F0[] __asm__("D_00495F98");
extern char D_004A4898_94F0[] __asm__("D_004A4898");

void func_003E94F0(void *arg0, void *arg1) {
    int n;
    if (*(int *)((char *)arg1 + 4) == 0x70696E67) {
        n = cDirtysock_tag_TagFieldGetNumber_94F0(cDirtysock_tag_TagFieldFind_94F0(*(int *)((char *)arg1 + 0xC), D_004A4898_94F0), 0);
        if (n == 0) {
            func_003E76A8_94F0(arg0, D_00495F98_94F0);
            *(int *)((char *)arg0 + 0x20) += 1;
            if (*(int *)((char *)arg0 + 0x20) == 3) {
                *(int *)((char *)arg0 + 0x20) = 0;
            } else {
                *(int *)((char *)arg0 + 0x18) = func_003F4330_94F0();
            }
        } else {
            *(int *)((char *)arg0 + 0x1C) = n;
            *(int *)((char *)arg0 + 0x18) = func_003F4330_94F0() + 0x7530;
            *(int *)((char *)arg0 + 0x20) = 0;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2DCAE8", func_003E9590);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003E8DC0_9590(void *, void *, int, int, void *, int) __asm__("func_003E8DC0");
extern char D_004A4900_9590[] __asm__("D_004A4900");
extern char func_003E94F0_9590[] __asm__("func_003E94F0");

void func_003E9590(void *arg0) {
    func_003E8DC0_9590(arg0, D_004A4900_9590, *(int *)((char *)arg0 + 0x3B4), 0xBB8, func_003E94F0_9590, 0);
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003E95C8);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003EAE68);
#ifdef SKIP_ASM
unsigned char *func_003EAE68(unsigned char *a0, int *a1) {
    unsigned int c;

    *a1 = 0;
    c = *a0;
    if (c - 0x30 < 10) {
        do {
            a0++;
            *a1 = *a1 * 10 + (c & 0xF);
            c = *a0;
        } while (c - 0x30 < 10);
    }
    return a0;
}
#endif

INCLUDE_ASM("ealib/seg_2DCAE8", func_003EAEB8);

INCLUDE_ASM("ealib/seg_2DCAE8", func_003EB090);

//100%
INCLUDE_ASM("ealib/seg_2DCAE8", func_003EB190);
#ifdef SKIP_ASM
int func_003EB190(void) {
    return 0;
}
#endif
