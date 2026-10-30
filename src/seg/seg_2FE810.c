#include "common.h"

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FD810);
#ifdef SKIP_ASM
// Not code: a table read by the loader in seg_2FDDC8 (func_003FD908): the addresses of 59 functions/data objects,
// an end word and a 0. Written as plain words because splat emits the retail table without relocations, so a
// pointer initialiser cannot match yet; the comment on each entry names its symbol (for a port, or a later splat fix).
const unsigned int func_003FD810[] __attribute__((section(".text"), aligned(8))) = {
    0x00425C28, /* func_00425C28 */
    0x00425C60, /* func_00425C60 */
    0x0040B6D0, /* func_0040B6D0 */
    0x0040B400, /* func_0040B400 */
    0x0040B5B0, /* func_0040B5B0 */
    0x00401718, /* func_00401718 */
    0x00402268, /* func_00402268 */
    0x00402520, /* func_00402520 */
    0x00402450, /* func_00402450 */
    0x00401350, /* func_00401350 */
    0x00401BF0, /* func_00401BF0 */
    0x004014F8, /* func_004014F8 */
    0x00451680, /* D_00451680 */
    0x00451628, /* D_00451628 */
    0x004527D0, /* D_004527D0 */
    0x004011E0, /* func_004011E0 */
    0x00452800, /* D_00452800 */
    0x00453180, /* D_00453180 */
    0x0045162C, /* D_0045162C */
    0x00423BA0, /* func_00423BA0 */
    0x00423BC0, /* func_00423BC0 */
    0x00423BB0, /* func_00423BB0 */
    0x00423C30, /* func_00423C30 */
    0x00423CA0, /* func_00423CA0 */
    0x00423BF0, /* func_00423BF0 */
    0x00423C90, /* func_00423C90 */
    0x00423DA0, /* func_00423DA0 */
    0x00423DE0, /* func_00423DE0 */
    0x00423DB0, /* func_00423DB0 */
    0x00423DC0, /* func_00423DC0 */
    0x00423DF0, /* func_00423DF0 */
    0x00424020, /* func_00424020 */
    0x00426D18, /* func_00426D18 */
    0x00427D60, /* func_00427D60 */
    0x00427FE8, /* func_00427FE8 */
    0x004283A0, /* func_004283A0 */
    0x00428600, /* func_00428600 */
    0x00428168, /* func_00428168 */
    0x00424570, /* func_00424570 */
    0x004245A0, /* func_004245A0 */
    0x00426B48, /* func_00426B48 */
    0x00423DD0, /* func_00423DD0 */
    0x00423B80, /* func_00423B80 */
    0x00423B20, /* func_00423B20 */
    0x00423B30, /* func_00423B30 */
    0x00424880, /* func_00424880 */
    0x00423AA0, /* func_00423AA0 */
    0x004240E0, /* func_004240E0 */
    0x004239A0, /* func_004239A0 */
    0x00424558, /* func_00424558 */
    0x00424550, /* func_00424550 */
    0x00424460, /* func_00424460 */
    0x00424368, /* func_00424368 */
    0x00424488, /* func_00424488 */
    0x00424498, /* func_00424498 */
    0x004243E8, /* func_004243E8 */
    0x00423A80, /* func_00423A80 */
    0x004248E8, /* func_004248E8 */
    0x00455248, /* D_00455248 */
    0x03E00008, /* end word */
    0x00000000, /* terminator */
};
#endif

void func_003FD908(void) {
}

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FD910);
#ifdef SKIP_ASM
struct S3FD910 { short a; short b; short c; unsigned short d; int e; int f; };
extern int func_00423AA0(int, int);
extern void func_00424880(int);
extern void func_004239A0(int, int, int);
extern int func_004240E0(int);
void func_003FD910(short a, short b, short c, short d) {
    struct S3FD910 *p;
    int e;
    switch (a) {
    case 0:
        p = func_003FDAA0();
        *(volatile long *)0x12001000 = 0x200;
        p->a = b;
        p->b = c;
        p->d = (*(volatile unsigned long *)0x12001000 >> 16) & 0xFF;
        func_004240E0(0xFF00);
        p->c = !!d;
        if (p->e) {
            func_00424880(2);
            func_00423AA0(2, p->f);
            p->e = 0;
            p->f = 0;
        }
        func_004239A0(b & 1, c & 0xFF, d & 1);
        break;
    case 1:
        *(volatile long *)0x12001000 = 0x100;
        break;
    case 5:
        p = func_003FDAA0();
        p->c = d != 0;
        p->a = b;
        p->b = c;
        p->d = (*(volatile unsigned long *)0x12001000 >> 16) & 0xFF;
        func_004239A0(b & 1, c & 0xFF, d & 1);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDAA0);
#ifdef SKIP_ASM
extern char D_00451550[];
void *func_003FDAA0(void) {
    return D_00451550;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FDAB0);

INCLUDE_ASM("seg/seg_2FE810", sceGsSyncPath);

INCLUDE_ASM("seg/seg_2FE810", func_003FDE30);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDEA0);
#ifdef SKIP_ASM
extern char D_004977D8[];
extern void func_003FDEA0_log(char *) __asm__("func_00425C60");
extern int func_003FE5C8();
void func_003FDEA0(int *p, unsigned lim, int tmo) {
    int t = 0x1000000;
    if (tmo)
        t = tmo;
    while (*(volatile int *)(p + 4) < lim) {
        if (--t < 0) {
            func_003FDEA0_log(D_004977D8);
            func_003FE5C8(p);
        }
        }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDF28);
#ifdef SKIP_ASM
unsigned func_003FDF28(unsigned a) {
    if ((a >> 28) == 7) {
        a &= 0xFFFFFFF;
        a |= 0x80000000;
    }
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDF50);
#ifdef SKIP_ASM
void func_003FDF50(char *p, int n) {
    while (n--)
        *p++ = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDF88);
#ifdef SKIP_ASM
extern int D_00451590[];
int func_003FDF88(unsigned n) {
    return n < 10 ? D_00451590[n] : 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FDFB0);
#ifdef SKIP_ASM
extern int D_00451590[];
extern int D_004977F0[];
extern void func_003FDF50(char *, int);
extern int func_003FE090_i(char *) __asm__("func_003FE090");
int func_003FDFB0(int a) {
    char buf[20];
    int i;
    int saved = *(volatile int *)0x1000E000 & 1;
    for (i = 0; i < 10; i++) {
        if (D_004977F0[i] != 0) {
            int *t = (int *)D_00451590[i];
            t[0] = 0;
            t[0x30 / 4] = 0;
            t[0x10 / 4] = 0;
            t[0x50 / 4] = 0;
            t[0x40 / 4] = 0;
            t[0x80 / 4] = 0;
        }
    }
    *(volatile int *)0x1000E010 = 0xFF1F;
    *(int *)0x1000E010 &= 0xFF1F0000;
    func_003FDF50(buf, 20);
    func_003FE090_i(buf);
    if (a == 1)
        *(volatile int *)0x1000E000 |= 1;
    return saved;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FE090);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE268);
#ifdef SKIP_ASM
struct S003FE268 { int c[5]; };
extern struct S003FE268 D_005261D0[];
struct S003FE268 *func_003FE268(struct S003FE268 *d) {
    *d = D_005261D0[0];
    return d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE2A0);
#ifdef SKIP_ASM
int func_003FE2A0(int v) {
    int *r = (int *)0x1000E060;
    int o = *r;
    *r = v;
    return o;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE2B8);
#ifdef SKIP_ASM
extern unsigned func_003FDF28(unsigned);
extern void func_003FDE30();
void func_003FE2B8(int *p, unsigned a) {
    unsigned v = func_003FDF28(a);
    func_003FDE30(p);
    if (p[12] != 0xFFFFFFFF)
        p[12] = v;
    p[8] = 0;
    p[0] = (p[0] & ~0xC) | 0x105;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE320);
#ifdef SKIP_ASM
void func_003FE320(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    p[0] = (p[0] & ~0xC) | 0x101;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE398);
#ifdef SKIP_ASM
void func_003FE398(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    p[0] = (p[0] & ~0xC) | 0x109;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE410);
#ifdef SKIP_ASM
extern void func_003FDE30();
void func_003FE410(int *p) {
    func_003FDE30(p);
    p[8] = 0;
    p[0] = ((p[0] & ~0xC | 0x4) & ~1) | 0x100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE458);
#ifdef SKIP_ASM
void func_003FE458(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    int t;
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    t = p[0] & ~0xC;
    p[0] = (t & ~1) | 0x100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE4D8);
#ifdef SKIP_ASM
void func_003FE4D8(int *p, unsigned a, int c) {
    unsigned v = func_003FDF28(a);
    int t;
    func_003FDE30(p);
    if (p[4] != 0xFFFFFFFF)
        p[4] = v;
    p[8] = c;
    t = (p[0] & ~0xC) | 8;
    p[0] = (t & ~1) | 0x100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE558);
#ifdef SKIP_ASM
extern void func_003FDE30(int *, int);
int func_003FE558(unsigned *p, int m) {
    if (m == 1)
        return (*p >> 8) & 1;
    func_003FDE30((int *)p, m);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE590);
#ifdef SKIP_ASM
extern void func_003FDEA0(int *, unsigned, int);
int func_003FE590(int *p, unsigned n, int m, int x) {
    if (m == 1)
        return (unsigned)p[4] < n;
    func_003FDEA0(p, n, x);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE5C8);
#ifdef SKIP_ASM
extern int func_0042C078();
extern void func_0042C0C0(void);
int func_003FE5C8(volatile unsigned *p) {
    int x, r, s;
    unsigned v;
    s = func_0042C078();
    r = *(volatile int *)0x1000F520;
    if ((r & 0x10000) == 0)
        *(volatile int *)0x1000F590 = r | 0x10000;
    x = *(volatile int *)0x1000E000;
    v = *p;
    *p = v & 0xFFFFFEFF;
    *(volatile int *)0x1000F590 = r;
    if (s)
        func_0042C0C0();
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE660);
#ifdef SKIP_ASM
unsigned func_003FE660(unsigned *p, unsigned v) {
    unsigned o = *p;
    *p = v;
    return (o >> 8) & 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE678);
#ifdef SKIP_ASM
// VU0 status read: (status >> 0) & 1 from $vi29.
// PORT: PS2-only VU0 control-register read. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_678(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi29
	.set reorder" : "=r"(v));
    return v;
}
int func_003FE678(void) {
    return (vu0_cfc2_678() & 0xF) == 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE690);
#ifdef SKIP_ASM
// VU0 control: set bit 0x2 in $vi28 (read-modify-write).
// PORT: PS2-only VU0 control-register access. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_vi28_690(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi28
	.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_vi28_690(unsigned int v)
{
    __asm__ volatile(".set noreorder
	ctc2.ni %0, $vi28
	.set reorder" : : "r"(v));
}
void func_003FE690(void) {
    vu0_ctc2_vi28_690(vu0_cfc2_vi28_690() | 0x2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE6A8);
#ifdef SKIP_ASM
// Act on the VU0 status decode: case 4 sets bit 0x1 in $vi28; returns 1 for cases 0, 3 and 4.
// PORT: PS2-only VU0 control-register access. The EE interlocks COP2 moves, so no hazard nop follows.
extern int func_003FE7D8_6A8(void) __asm__("func_003FE7D8");
static inline unsigned int vu0_cfc2_vi28_6A8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi28
	.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_vi28_6A8(unsigned int v)
{
    __asm__ volatile(".set noreorder
	ctc2.ni %0, $vi28
	.set reorder" : : "r"(v));
}
int func_003FE6A8(void) {
    int r = 0;
    switch (func_003FE7D8_6A8()) {
    case 4:
        vu0_ctc2_vi28_6A8(vu0_cfc2_vi28_6A8() | 0x1);
    case 0:
    case 3:
        r = 1;
        break;
    case 1:
    case 2:
        break;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE708);
#ifdef SKIP_ASM
extern int func_003FE7D8(void);
extern int func_003FE828(void);
extern void func_003FE818(int);
int func_003FE708(void) {
    int r = 0;
    int n = func_003FE7D8();
    if (n < 4) {
        if (n > 0) {
            func_003FE818(func_003FE828());
            r = 1;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE758);
#ifdef SKIP_ASM
// VU0 status flag set/clear: bit 2 of the VU0 status register ($vi28).
// PORT: PS2-only VU0 control-register access.
static inline unsigned int vu0_cfc2_758(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi28\n\t.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_758(unsigned int v)
{
    __asm__ volatile(".set noreorder\n\tctc2.ni %0, $vi28\n\t.set reorder" : : "r"(v));
}
void func_003FE758(int a) {
    unsigned int s = vu0_cfc2_758();
    if (a == 1)
        s |= 0x4;
    else
        s &= ~0x4;
    vu0_ctc2_758(s);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE788);
#ifdef SKIP_ASM
// VU0 status flag set/clear: bit 3 of the VU0 status register ($vi28).
// PORT: PS2-only VU0 control-register access.
static inline unsigned int vu0_cfc2_788(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi28\n\t.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_788(unsigned int v)
{
    __asm__ volatile(".set noreorder\n\tctc2.ni %0, $vi28\n\t.set reorder" : : "r"(v));
}
void func_003FE788(int a) {
    unsigned int s = vu0_cfc2_788();
    if (a == 1)
        s |= 0x8;
    else
        s &= ~0x8;
    vu0_ctc2_788(s);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE7B8);
#ifdef SKIP_ASM
// VU0 status flag read: bit 2 of the VU0 status register ($vi28).
// PORT: PS2-only VU0 control-register read. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_vi28_7B8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi28\n\t.set reorder" : "=r"(v));
    return v;
}
int func_003FE7B8(void) {
    return (vu0_cfc2_vi28_7B8() >> 2) & 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE7C8);
#ifdef SKIP_ASM
// VU0 status read: (status >> 3) & 1 from $vi28.
// PORT: PS2-only VU0 control-register read. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_7C8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi28
	.set reorder" : "=r"(v));
    return v;
}
int func_003FE7C8(void) {
    return (vu0_cfc2_7C8() >> 3) & 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE7D8);
#ifdef SKIP_ASM
// VU0 status decode from $vi29.
// PORT: PS2-only VU0 control-register read. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_vi29_7D8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi29
	.set reorder" : "=r"(v));
    return v;
}
int func_003FE7D8(void) {
    unsigned int s = vu0_cfc2_vi29_7D8();
    if (s & 2)
        return 1;
    if (s & 4)
        return 2;
    if (s & 8)
        return 3;
    return (s & 1) << 2;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FE818);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FE828);
#ifdef SKIP_ASM
// VU0 status read: (status >> 0) & 1 from $vi26.
// PORT: PS2-only VU0 control-register read. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_828(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi26
	.set reorder" : "=r"(v));
    return v;
}
int func_003FE828(void) {
    return vu0_cfc2_828() & 0xFFFF;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FE838);

INCLUDE_ASM("seg/seg_2FE810", func_003FE998);

INCLUDE_ASM("seg/seg_2FE810", func_003FEB08);

INCLUDE_ASM("seg/seg_2FE810", func_003FEB38);

INCLUDE_ASM("seg/seg_2FE810", func_003FEB78);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FEBC0);
#ifdef SKIP_ASM
// VU0 control: set bit 0x200 in $vi28 (read-modify-write).
// PORT: PS2-only VU0 control-register access. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_vi28_BC0(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi28
	.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_vi28_BC0(unsigned int v)
{
    __asm__ volatile(".set noreorder
	ctc2.ni %0, $vi28
	.set reorder" : : "r"(v));
}
void func_003FEBC0(void) {
    vu0_ctc2_vi28_BC0(vu0_cfc2_vi28_BC0() | 0x200);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FEBD8);
#ifdef SKIP_ASM
// Act on the VU0 status decode: case 4 sets bit 0x100 in $vi28; returns 1 for cases 0, 3 and 4.
// PORT: PS2-only VU0 control-register access. The EE interlocks COP2 moves, so no hazard nop follows.
extern int func_003FED08_BD8(void) __asm__("func_003FED08");
static inline unsigned int vu0_cfc2_vi28_BD8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi28
	.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_vi28_BD8(unsigned int v)
{
    __asm__ volatile(".set noreorder
	ctc2.ni %0, $vi28
	.set reorder" : : "r"(v));
}
int func_003FEBD8(void) {
    int r = 0;
    switch (func_003FED08_BD8()) {
    case 4:
        vu0_ctc2_vi28_BD8(vu0_cfc2_vi28_BD8() | 0x100);
    case 0:
    case 3:
        r = 1;
        break;
    case 1:
    case 2:
        break;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FEC38);
#ifdef SKIP_ASM
extern int func_003FED08(void);
extern unsigned short func_003FED60(void);
extern void func_003FED50(int);
int func_003FEC38(void) {
    int r = 0;
    int n = func_003FED08();
    if (n < 4) {
        if (n > 0) {
            func_003FED50(func_003FED60());
            r = 1;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FEC88);
#ifdef SKIP_ASM
// VU0 status flag set/clear: bit 10 of the VU0 status register ($vi28).
// PORT: PS2-only VU0 control-register access.
static inline unsigned int vu0_cfc2_C88(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi28\n\t.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_C88(unsigned int v)
{
    __asm__ volatile(".set noreorder\n\tctc2.ni %0, $vi28\n\t.set reorder" : : "r"(v));
}
void func_003FEC88(int a) {
    unsigned int s = vu0_cfc2_C88();
    if (a == 1)
        s |= 0x400;
    else
        s &= ~0x400;
    vu0_ctc2_C88(s);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FECB8);
#ifdef SKIP_ASM
// VU0 status flag set/clear: bit 11 of the VU0 status register ($vi28).
// PORT: PS2-only VU0 control-register access.
static inline unsigned int vu0_cfc2_CB8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi28\n\t.set reorder" : "=r"(v));
    return v;
}
static inline void vu0_ctc2_CB8(unsigned int v)
{
    __asm__ volatile(".set noreorder\n\tctc2.ni %0, $vi28\n\t.set reorder" : : "r"(v));
}
void func_003FECB8(int a) {
    unsigned int s = vu0_cfc2_CB8();
    if (a == 1)
        s |= 0x800;
    else
        s &= ~0x800;
    vu0_ctc2_CB8(s);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FECE8);
#ifdef SKIP_ASM
// VU0 status read: (status >> 10) & 1 from $vi28.
// PORT: PS2-only VU0 control-register read. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_CE8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi28
	.set reorder" : "=r"(v));
    return v;
}
int func_003FECE8(void) {
    return (vu0_cfc2_CE8() >> 10) & 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FECF8);
#ifdef SKIP_ASM
// VU0 status read: (status >> 11) & 1 from $vi28.
// PORT: PS2-only VU0 control-register read. The EE interlocks COP2 moves, so no hazard nop follows.
static inline unsigned int vu0_cfc2_CF8(void)
{
    unsigned int v;
    __asm__ volatile(".set noreorder
	cfc2.ni %0, $vi28
	.set reorder" : "=r"(v));
    return v;
}
int func_003FECF8(void) {
    return (vu0_cfc2_CF8() >> 11) & 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FED08);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FED50);
#ifdef SKIP_ASM
// Write the VU0 control register $vi31 (low 16 bits).
// PORT: PS2-only VU0 control-register write.
static inline void vu0_ctc2_D50(unsigned int v)
{
    __asm__ volatile(".set noreorder\n\tctc2.ni %0, $vi31\n\t.set reorder" : : "r"(v));
}
void func_003FED50(int v) {
    vu0_ctc2_D50(v & 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FED60);
#ifdef SKIP_ASM
extern void func_003FEB78(void *, int);
unsigned short func_003FED60(void) {
    unsigned short v;
    func_003FEB78(&v, 0x43A);
    return v;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FED88);

INCLUDE_ASM("seg/seg_2FE810", func_003FEF18);

INCLUDE_ASM("seg/seg_2FE810", func_003FF060);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF088);
#ifdef SKIP_ASM
extern int func_003FF160(void);
int func_003FF088(int a) {
    int r = func_003FF160();
    if (r == 0) return 0;
    if (r == 1) return 0;
    if (a == 0) {
        *(volatile int *)0x10003810 = 2;
    } else if (a == 1) {
        *(volatile int *)0x10003810 = 4;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF0F0);
#ifdef SKIP_ASM
extern int func_003FF160(void);
int func_003FF0F0(void) {
    if (func_003FF160() != 1)
        return 0;
    *(volatile int *)0x10003810 = 8;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF130);

INCLUDE_ASM("seg/seg_2FE810", func_003FF150);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF160);
#ifdef SKIP_ASM
int func_003FF160(void) {
    int v = *(volatile int *)0x10003800;
    if (!(v & 3)) {
        return 0;
    }
    if (v & 0x700) {
        return 1;
    }
    if (v & 0xC) {
        return 2;
    }
    return (v & 0x3000) ? 3 : 4;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF1B0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF330);
#ifdef SKIP_ASM
typedef int i128 __attribute__((mode(TI)));
int func_003FF330(i128 *src, int n) {
    int c = 0;
    while (n--) {
        if (*(volatile unsigned *)0x10003800 & 0x10000000)
            return c;
        *(i128 *)0x10004000 = *src++;
        c++;
    }
    return c;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF390);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF4A8);
#ifdef SKIP_ASM
extern int D_004515C8[];
extern int D_004515CC[];
struct Q526200 { int pad[9]; int f24; };
extern struct Q526200 Q_526200[] __asm__("D_00526200");
extern char D_004978D0[];
extern char D_004978F8[];
extern int Q_6B48a(struct Q526200 *, unsigned, int) __asm__("func_00426B48");
extern int func_00400740(void);
extern void func_00425C60();
extern int func_003FF5E8_a(int) __asm__("func_003FF5E8");
int func_003FF4A8(int a) {
    int i;
    int v;
    int h;
    D_004515C8[0] = 1;
    for (;;) {
        Q_6B48a(&Q_526200[0], 0x80000100, 0);
        if (Q_526200[0].f24 != 0)
            break;
        i = 0x10000;
        do {
            i--;
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
        } while (i != -1);
    }
    for (;;) {
        Q_6B48a(&Q_526200[1], 0x80000101, 0);
        if (Q_526200[1].f24 != 0)
            break;
        i = 0x10000;
        do {
            i--;
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
        } while (i != -1);
    }
    v = func_00400740();
    h = v >> 8;
    if (h != 4) {
        if (D_004515CC[0] != 0) {
            func_00425C60(D_004978D0);
            func_00425C60(D_004978F8, 4, 0, h, v & 0xFF);
        }
        return 0;
    }
    return func_003FF5E8_a(a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF5E8);
#ifdef SKIP_ASM
struct E_526250 { int pad[4]; int f10; int pad2[2]; };
struct R_526250 { struct E_526250 e[4]; };
extern struct R_526250 D_00526250[];
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_003FF5E8(void) {
    int i;
    for (i = 0; i < 4; i++) {
        D_00526250[0].e[i].f10 = 0;
        D_00526250[0].e[i].pad2[1] = 0;
        D_00526250[0].e[i].pad2[0] = 0;
        D_00526250[1].e[i].f10 = 0;
        D_00526250[1].e[i].pad2[1] = 0;
        D_00526250[1].e[i].pad2[0] = 0;
    }
    D_00526440[0] = 16;
    D_00526440[4] = 0;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF688);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int D_004515C8[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_003FF688(void) {
    int v;
    D_00526440[0] = 15;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    v = D_00526440[3];
    if (v == 1)
        D_004515C8[0] = 0;
    return v;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_003FF708);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF8F0);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_003FF8F0(int a, int b) {
    if (!D_00526250[a].e[b].f10)
        return 0;
    D_00526440[0] = 14;
    D_00526440[1] = a;
    D_00526440[2] = b;
    D_00526440[4] = 1;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    D_00526250[a].e[b].f10 = 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FF9A8);
#ifdef SKIP_ASM
extern void func_00424698(int *, int *);
int *func_003FF9A8(int a, int b) {
    int *p, c;
    p = (int *)D_00526250[a].e[b].pad[0];
    func_00424698(p, (int *)((char *)p + 0xFF));
    c = (p[22] < p[54]) << 7;
    return (int *)((char *)p + c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFA08);
#ifdef SKIP_ASM
extern int * func_003FF9A8(int, int);
int func_003FFA08(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_003FF9A8(a, b)[22];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFA58);
#ifdef SKIP_ASM
struct B128 { char b[128]; };
extern unsigned char *func_003FF9A8_c(int, int) __asm__("func_003FF9A8");
extern int func_0042C078();
extern void func_0042C0C0();
extern int func_0041605C_k() __asm__("func_0041605C");
int func_003FFA58(int a, int b, int c) {
    struct B128 s;
    int *q;
    int r;
    if (!D_00526250[a].e[b].f10)
        return 0;
    r = func_0042C078();
    q = (int *)&s;
    s = *(struct B128 *)func_003FF9A8_c(a, b);
    func_0041605C_k(c, q, q[0x60 / 4]);
    if (r == 1)
        func_0042C0C0();
    return q[0x60 / 4];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFBC0);
#ifdef SKIP_ASM
int func_003FFBC0(int a, int b) {
    unsigned char *p;
    if (!D_00526250[a].e[b].f10)
        return 99;
    p = (unsigned char *)func_003FF9A8(a, b);
    if (p[0x70] == 6 && p[0x71] == 2)
        return 5;
    return p[0x70];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFC38);
#ifdef SKIP_ASM
extern char *D_004515D0[];
extern char D_004979A8[];
extern char *strcpy(char *, const char *);
void func_003FFC38(unsigned i, char *dst) {
    if (i < 8) {
        strcpy(dst, D_004515D0[i]);
        return;
    }
    *dst = D_004979A8[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFC70);
#ifdef SKIP_ASM
int func_003FFC70(int a, int b, int c) {
    if (!D_00526250[a].e[b].f10)
        return 0;
    ((char *)func_003FF9A8(a, b))[0x71] = c;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFCD8);
#ifdef SKIP_ASM
int func_003FFCD8(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return ((unsigned char *)func_003FF9A8(a, b))[0x71];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFD28);
#ifdef SKIP_ASM
extern char *D_004515F0[];
extern char D_004979A8[];
extern char *strcpy(char *, const char *);
void func_003FFD28(unsigned i, char *dst) {
    if (i < 4) {
        strcpy(dst, D_004515F0[i]);
        return;
    }
    *dst = D_004979A8[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFD60);
#ifdef SKIP_ASM
struct Z_FD60 { unsigned char pad[0x30]; struct { unsigned char a, b, c, d; } e[8]; unsigned char pad2[0x14]; unsigned char f64; unsigned char pad3[5]; unsigned char f6A; unsigned char pad4[7]; unsigned char f72; };
int func_003FFD60(int a, int b, int c, int d) {
    struct Z_FD60 *p;
    if (!D_00526250[a].e[b].f10) return 0;
    p = (struct Z_FD60 *)func_003FF9A8(a, b);
    if (p->f72 != 1) return 0;
    if (p->f64 < 2) return 0;
    if (c >= p->f6A) return 0;
    if (c == -1) return p->f6A;
    switch (d) {
    case 1:
        return p->e[c].a;
    case 2:
        return p->e[c].b;
    case 3:
        return p->e[c].c;
    case 4:
        return p->e[c].d;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFE80);
#ifdef SKIP_ASM
struct Z_FE80 { unsigned char pad[0x40]; struct { unsigned char a, b, c, d; } e[8]; unsigned char pad2[4]; unsigned char f64; unsigned char pad3[6]; unsigned char f6B; unsigned char pad4[6]; unsigned char f72; };
int func_003FFE80(int a, int b, int c, int d) {
    struct Z_FE80 *p;
    if (!D_00526250[a].e[b].f10) return 0;
    p = (struct Z_FE80 *)func_003FF9A8(a, b);
    if (p->f72 != 1) return 0;
    if (p->f64 < 2) return 0;
    if (c == -1) return p->f6B;
    if (c >= p->f6B) return 0;
    switch (d) {
    case -1:
        return p->e[c].a;
    case 0:
        return p->e[c].b;
    case 1:
        return p->e[c].c;
    case 2:
        return p->e[c].d;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_003FFFA0);
#ifdef SKIP_ASM
// scePadInfoMode(port, slot, term, offs)
struct Z_FFA0 { unsigned char pad[0x50]; unsigned short t[8]; unsigned char pad2[4]; unsigned char f64; unsigned char f65; unsigned char pad3[2]; unsigned char f68; unsigned char f69; unsigned char pad4[7]; unsigned char f71; unsigned char f72; };
int func_003FFFA0(int port, int slot, int term, int offs) {
    struct Z_FFA0 *p;
    int t;
    if (!D_00526250[port].e[slot].f10) return 0;
    p = (struct Z_FFA0 *)func_003FF9A8(port, slot);
    if (p->f72 != 1) return 0;
    if (p->f71 == 2) return 0;
    switch (term) {
    case 1:
        t = p->f65;
        if (t == 0xF3) return 0;
        return t >> 4;
    case 2:
        if (p->f64 == 1) return 0;
        return p->t[p->f69];
    case 3:
        if (p->f64 == 1) return 0;
        return p->f69;
    case 4:
        if (p->f64 == 1) return 0;
        if (offs == -1) return p->f68;
        if (offs < p->f68) return p->t[offs];
        return 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004000D8);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern int func_003FFC70(int, int, int);
int func_004000D8(int a, int b, int c, int d) {
    int v;
    D_00526440[3] = c;
    D_00526440[4] = d;
    D_00526440[0] = 6;
    D_00526440[1] = a;
    D_00526440[2] = b;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    v = D_00526440[5];
    if (v == 1)
        func_003FFC70(a, b, 2);
    return D_00526440[5];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400190);
#ifdef SKIP_ASM
extern int *func_003FF9A8(int, int);
extern int s0_F390(int, int) __asm__("func_003FF390");
int func_00400190(int a, int b, unsigned char *src) {
    int i;
    int ok;
    int *q;
    char *d;
    if (((unsigned char *)func_003FF9A8(a, b))[0x72] != 1)
        return 0;
    q = (int *)D_00526250[a].e[b].pad[1];
    d = (char *)q + 0xC;
    for (i = 0; i < 6; i++)
        d[i] = src[i];
    ok = 1;
    q[1] = ok;
    q[2] = 6;
    if (s0_F390(a, b) != 1)
        ok = 0;
    return ok;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400250);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern int func_003FFC70(int, int, int);
int func_00400250(int port, int slot, unsigned char *data) {
    int i;
    unsigned char *d;
    int *p = D_00526440;
    p[0] = 8;
    p[1] = port;
    p[2] = slot;
    d = (unsigned char *)&p[3];
    for (i = 0; i < 6; i++)
        d[i] = data[i];
    if (func_00426D18(D_00526200, 1, 0, p, 128, p, 128, 0, 0) < 0)
        return 0;
    if (p[5] == 1)
        func_003FFC70(port, slot, 2);
    return p[5];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400328);
#ifdef SKIP_ASM
extern unsigned char *func_003FF9A8_c(int, int) __asm__("func_003FF9A8");
int func_00400328(int a, int b) {
    unsigned char *p;
    if (!D_00526250[a].e[b].f10)
        return 0;
    p = func_003FF9A8_c(a, b);
    if (p[0x72] != 1)
        return 0;
    if (p[0x64] < 2)
        return 0;
    if (p[0x66] < 2)
        return 0;
    return p[0x79] + ((long)p[0x7A] << 8) + ((long)p[0x7B] << 16) + ((long)p[0x7C] << 24);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004003E0);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern int func_003FFC70(int, int, int);
int func_004003E0(int a, int b, int c) {
    int v;
    D_00526440[3] = c;
    D_00526440[0] = 10;
    D_00526440[1] = a;
    D_00526440[2] = b;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    v = D_00526440[4];
    if (v == 1)
        func_003FFC70(a, b, 2);
    return D_00526440[4];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400490);
#ifdef SKIP_ASM
extern int func_00400328(int, int);
int func_00400490(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_00400328(a, b) == 0x3FFFF;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004004F0);
#ifdef SKIP_ASM
extern int func_004003E0(int, int, int);
int func_004004F0(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_004003E0(a, b, 0xFFF);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400548);
#ifdef SKIP_ASM
extern int func_004003E0(int, int, int);
int func_00400548(int a, int b) {
    if (!D_00526250[a].e[b].f10) return 0;
    return func_004003E0(a, b, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004005A0);
#ifdef SKIP_ASM
struct P12 { char b[12]; } __attribute__((packed));
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern int func_003FFC70(int, int, int);
int func_004005A0(int a, int b, struct P12 *c) {
    D_00526440[1] = a;
    D_00526440[0] = 11;
    D_00526440[2] = b;
    *(struct P12 *)&D_00526440[3] = *c;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    if (D_00526440[7] == 1)
        func_003FFC70(a, b, 2);
    return D_00526440[7];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400670);
#ifdef SKIP_ASM
extern char D_00526200[];
extern int D_00526440[];
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_00400670(void) {
    D_00526440[0] = 12;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004006D8);
#ifdef SKIP_ASM
int func_004006D8(int a) {
    D_00526440[1] = a;
    D_00526440[0] = 13;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400740);
#ifdef SKIP_ASM
int func_00400740(void) {
    D_00526440[0] = 18;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004007A8);
#ifdef SKIP_ASM
int func_004007A8(int a) {
    D_00526440[1] = a;
    D_00526440[0] = 20;
    if (func_00426D18(D_00526200, 1, 0, D_00526440, 128, D_00526440, 128, 0, 0) < 0)
        return 0;
    return D_00526440[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400810);
#ifdef SKIP_ASM
// PORT: PS2-only COP0 (enable interrupts) and memory barrier.
#define SYNC_0810() __asm__ volatile("sync")
#define EI_0810() __asm__ volatile("ei")
extern void func_00423DD0(int);
void func_00400810(int a, int b, int c) {
    func_00423DD0(c);
    SYNC_0810();
    EI_0810();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400838);
#ifdef SKIP_ASM
extern int func_00423DA0(int *);
extern void func_00400810(int, int, int);
void func_00400838(unsigned short a) {
    int s[6];
    int h;
    s[1] = 1;
    s[2] = 0;
    s[5] = 0;
    h = func_00423DA0(s);
    func_00423B20(a, func_00400810, h);
    func_00423DE0(h);
    func_00423DB0(h);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004008A0);
#ifdef SKIP_ASM
extern int D_005264C0[];
extern int D_005264C4[];
extern int func_004013E8(int);
extern int func_0042C078();
extern void func_0042C0C0(void);
int func_004008A0(int cb) {
    int old;
    int s;
    register int gp __asm__("$28");
    if (func_004013E8(1) != 0)
        return 0;
    s = func_0042C078();
    old = D_005264C0[0];
    D_005264C0[0] = cb;
    *(volatile int *)D_005264C4 = gp;
    if (s != 0)
        func_0042C0C0();
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400908);
#ifdef SKIP_ASM
extern int D_00451614[];
extern int D_00451620[];
extern int D_00451628[];
extern int D_00451634[];
extern char D_00451658[];
extern int D_0045165C[];
extern int D_005264C0[];
extern int func_00423DD0_i(int) __asm__("func_00423DD0");
void func_00400908(char *p) {
    *(volatile int *)D_00451658 = *(int *)p;
    *(volatile int *)D_0045165C = *(volatile int *)D_00451658;
    if (*(volatile int *)D_00451658 == 11) {
        *(volatile int *)D_00451658 = 0;
        *(volatile int *)D_00451634 = 0;
        return;
    }
    func_00423DD0_i(*(volatile int *)D_00451628);
    if (D_00451614[0] != 0 && D_005264C0[0] != 0)
        func_00423DD0_i(*(volatile int *)D_00451620);
    else
        *(volatile int *)D_00451634 = 0;
    *(volatile int *)D_00451658 = 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004009A8);

INCLUDE_ASM("seg/seg_2FE810", func_00400A78);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400B48);
#ifdef SKIP_ASM
struct S0B48 { int n0; int n1; unsigned char *d0; unsigned char *d1; unsigned char b0[0x40]; unsigned char b1[0x40]; };
extern char D_00451658[];
extern void func_00400908(char *);
void func_00400B48(unsigned a) {
    struct S0B48 *s = (struct S0B48 *)(a | 0x20000000);
    unsigned char *e;
    int i;
    unsigned char *d;
    if (s->n0 > 0) {
        e = (unsigned char *)((unsigned)s->d0 | 0x20000000);
        d = s->d0;
        for (i = 0; i < s->n0; i++) {
            unsigned char c = s->b0[i];
            e[i] = c;
            d[i] = c;
        }
    }
    if (s->n1 > 0) {
        e = (unsigned char *)((unsigned)s->d1 | 0x20000000);
        d = s->d1;
        for (i = 0; i < s->n1; i++) {
            unsigned char c = s->b1[i];
            e[i] = c;
            d[i] = c;
        }
    }
    func_00400908(D_00451658);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00400C00);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400CB8);
#ifdef SKIP_ASM
extern int D_00451614[];
extern int D_00451620[];
extern int D_00451628[];
extern int D_0045162C[];
extern int D_00451630[];
extern char D_00451658[];
extern int cb_DB0(int) __asm__("func_00423DB0");
extern void cb_DC0(int) __asm__("func_00423DC0");
extern void func_00426050(int);
extern int cb_078() __asm__("func_0042C078");
extern void func_0042C0C0(void);
void func_00400CB8(void) {
    int s;
    if (D_00451614[0] != 0) {
        *(int *)D_00451658 = -1;
        do { } while (0);
        cb_DC0(D_00451620[0]);
    }
    cb_DB0(D_00451628[0]);
    cb_DB0(D_0045162C[0]);
    cb_DB0(D_00451630[0]);
    cb_DB0(D_00451620[0]);
    s = cb_078();
    func_00426050(0x80000012);
    if (s)
        func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400D58);
#ifdef SKIP_ASM
extern int D_00451640[];
extern int func_0042C078();
extern void func_0042C0C0(void);
extern int func_00400E30(void);
extern void (*D_005264C8[])(int);
extern int D_005264CC[];
extern int D_005264D0[];
void (*func_00400D58(void (*a)(int), int b))(int) {
    int s;
    void (*old)(int);
    if (D_00451640[0] < 0)
        func_00400E30();
    s = func_0042C078();
    old = D_005264C8[0];
    D_005264D0[0] = b;
    D_005264C8[0] = a;
    __asm__ volatile("sw $28,%0" : "=m"(D_005264CC[0]));
    if (s)
        func_0042C0C0();
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400DD8);
#ifdef SKIP_ASM
extern void (*D_005264C8[])(int);
extern int D_005264CC[];
extern int D_005264D0[];
extern int D_00451624[];
void func_00400DD8(void) {
    void (*fn)(int) = D_005264C8[0];
    if (fn) {
        if (D_00451624[0] == 0) {
            int saved;
            __asm__ volatile("move %0,$28\n\tlw $28,%1" : "=r"(saved) : "m"(D_005264CC[0]));
            fn(D_005264D0[0]);
            __asm__ volatile("move $28,%0" : : "r"(saved));
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00400E30);
#ifdef SKIP_ASM
extern int D_00451640[];
extern int func_0042C078();
extern void func_0042C0C0(void);
extern void func_00400DD8(void);
extern void func_00426020(int, void (*)(void), int);
int func_00400E30(void) {
    int s;
    D_00451624[0] = 1;
    s = func_0042C078();
    func_00426020(0x80000012, func_00400DD8, 0);
    if (s)
        func_0042C0C0();
    D_00451624[0] = 0;
    D_00451640[0] = 1;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00400EA8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004011C0);
#ifdef SKIP_ASM
extern int func_00400EA8(int, int, int);
int func_004011C0(int a, int b) {
    return func_00400EA8(a, b, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004011E0);
#ifdef SKIP_ASM
extern int D_00451610[];
extern int D_00451628[];
extern int D_0045161C[];
extern int D_0045163C[];
extern int D_005264D8[];
extern int D_005264E0[];
extern char D_004527D0[];
extern char D_00497A78[];
extern char D_00497AA0[];
extern void func_00400C00();
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern void func_00423CA0(int, int *);
extern void func_00425C60();
extern int func_004013E8(int);
extern void func_00426408(int);
extern int func_00426B48(char *, unsigned, int);
int func_004011E0(int a) {
    int i;
    func_00400C00();
    if (D_00451628[0] != func_00423DF0(*(volatile int *)D_00451628)) {
        if (D_00451610[0] > 0)
            func_00425C60(D_00497A78, a, D_0045161C[0]);
        return 0;
    }
    D_0045161C[0] = a;
    func_00423CA0(D_005264D8[0], D_005264E0);
    if (func_004013E8(1) != 0) {
        func_00423DC0(*(volatile int *)D_00451628);
        return 0;
    }
    func_00426408(0);
    if (D_0045163C[0] >= 0)
        return 1;
    for (;;) {
        if (func_00426B48(D_004527D0, 0x80000595, 0) < 0) {
            if (D_00451610[0] > 0)
                func_00425C60(D_00497AA0);
            i = 0x100000;
            do {
                i--;
                __asm__ volatile("nop");
                __asm__ volatile("nop");
                __asm__ volatile("nop");
                __asm__ volatile("nop");
            } while (i != -1);
            continue;
        }
        if (*(int *)(D_004527D0 + 0x24) != 0)
            break;
        i = 0x100000;
        do {
            i--;
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
        } while (i != -1);
    }
    D_0045163C[0] = 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00401350);
#ifdef SKIP_ASM
extern char D_004527D0[];
extern int D_00451628[];
extern int D_00451680[];
extern int func_004011E0();
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern void func_00423DC0(int);
int func_00401350(void) {
    int v;
    if (func_004011E0(2) == 0)
        return 0;
    if (func_00426D18(D_004527D0, 14, 0, 0, 0, D_00451680, 4, 0, 0) < 0) {
        func_00423DC0(D_00451628[0]);
        return 0;
    }
    v = *(int *)((unsigned)D_00451680 | 0x20000000);
    func_00423DC0(D_00451628[0]);
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004013E8);
#ifdef SKIP_ASM
extern int D_00451610[];
extern int D_00451634[];
extern char D_004527D0[];
extern char D_00497AB8[];
extern void func_00425C60();
extern int func_00426F08(char *);
int func_004013E8(int a) {
    if (a == 0) {
        if (D_00451610[0] > 0)
            func_00425C60(D_00497AB8);
        while (D_00451634[0] || func_00426F08(D_004527D0))
            func_00400838(60);
        return 0;
    }
    if (D_00451634[0] || func_00426F08(D_004527D0))
        return 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00401488);
#ifdef SKIP_ASM
extern int D_00451610[];
extern char D_00453180[];
extern char D_00497AC8[];
extern void func_00425C60();
extern int func_00426F08(char *);
int func_00401488(int a) {
    if (a == 0) {
        if (D_00451610[0] > 0)
            func_00425C60(D_00497AC8);
        while (func_00426F08(D_00453180))
            func_00400838(60);
        return 0;
    }
    return func_00426F08(D_00453180);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004014F8);
#ifdef SKIP_ASM
extern int D_00451610[];
extern int D_0045162C[];
extern int D_00451618[];
extern int D_0045164C[];
extern int D_005264D8[];
extern int D_005264E0[];
extern char D_00453180[];
extern char D_00497AD8[];
extern char D_00497B00[];
extern void func_00400C00();
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern void func_00423CA0(int, int *);
extern void func_00425C60();
extern int func_00401488(int);
extern void func_00426408(int);
extern int func_00426B48(char *, unsigned, int);
int func_004014F8(int a) {
    int i;
    func_00400C00();
    if (D_0045162C[0] != func_00423DF0(*(volatile int *)D_0045162C)) {
        if (D_00451610[0] > 0)
            func_00425C60(D_00497AD8, a, D_00451618[0]);
        return 0;
    }
    D_00451618[0] = a;
    func_00423CA0(D_005264D8[0], D_005264E0);
    if (func_00401488(1) != 0) {
        func_00423DC0(*(volatile int *)D_0045162C);
        return 0;
    }
    func_00426408(0);
    if (D_0045164C[0] >= 0)
        return 1;
    for (;;) {
        if (func_00426B48(D_00453180, 0x80000593, 0) < 0) {
            if (D_00451610[0] > 0)
                func_00425C60(D_00497B00);
            i = 0x100000;
            do {
                i--;
                __asm__ volatile("nop");
                __asm__ volatile("nop");
                __asm__ volatile("nop");
                __asm__ volatile("nop");
            } while (i != -1);
            continue;
        }
        if (*(int *)(D_00453180 + 0x24) != 0)
            break;
        i = 0x100000;
        do {
            i--;
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
        } while (i != -1);
    }
    D_0045164C[0] = 0;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00401668);

INCLUDE_ASM("seg/seg_2FE810", func_00401718);

INCLUDE_ASM("seg/seg_2FE810", func_004019F8);

INCLUDE_ASM("seg/seg_2FE810", func_00401BF0);

INCLUDE_ASM("seg/seg_2FE810", func_00401DF8);

INCLUDE_ASM("seg/seg_2FE810", func_00401FD8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402268);
#ifdef SKIP_ASM
extern char D_00453180[];
extern int D_0045162C[];
extern int D_00452800[];
extern int func_004014F8();
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern void func_00423DC0(int);
int func_00402268(void) {
    int v;
    if (func_004014F8(1) == 0)
        return 0;
    if (func_00426D18(D_00453180, 3, 0, 0, 0, D_00452800, 4, 0, 0) < 0) {
        func_00423DC0(D_0045162C[0]);
        return 0;
    }
    v = *(int *)((unsigned)D_00452800 | 0x20000000);
    func_00423DC0(D_0045162C[0]);
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402300);
#ifdef SKIP_ASM
extern char D_00453180[];
extern int D_0045162C[];
extern int D_00452800[];
extern int func_004014F8();
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern void func_00423DC0(int);
int func_00402300(void) {
    int v;
    if (func_004014F8(3) == 0)
        return -1;
    if (func_00426D18(D_00453180, 4, 0, 0, 0, D_00452800, 4, 0, 0) < 0) {
        func_00423DC0(D_0045162C[0]);
        return -1;
    }
    v = *(int *)((unsigned)D_00452800 | 0x20000000);
    func_00423DC0(D_0045162C[0]);
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402398);
#ifdef SKIP_ASM
extern char D_00453180[];
extern int D_0045162C[];
extern int D_00452800[];
extern int func_004014F8();
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern void func_00423DC0(int);
int func_00402398(int *out) {
    int v;
    if (func_004014F8(0x21) == 0)
        return 0;
    if (func_00426D18(D_00453180, 0x21, 0, 0, 0, D_00452800, 8, 0, 0) < 0) {
        func_00423DC0(D_0045162C[0]);
        return 0;
    }
    *out = *(int *)((unsigned)(D_00452800 + 1) | 0x20000000);
    v = *(int *)((unsigned)D_00452800 | 0x20000000);
    func_00423DC0(D_0045162C[0]);
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402450);
#ifdef SKIP_ASM
extern char D_00453180[];
extern int D_0045162C[];
extern int D_00452800[];
extern int D_00452C40[];
extern int D_004531A8[];
extern int D_004531AC[];
extern int D_004531B0[];
extern int func_004014F8();
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern void func_00423DC0(int);
extern void func_00426358_p(int *, int) __asm__("func_00426358");
int func_00402450(int a) {
    int v;
    int *p = D_00452C40;
    if (func_004014F8(34) == 0)
        return 0;
    D_00452C40[0] = a;
    func_00426358_p(p, 4);
    if (func_00426D18(D_00453180, D_004531A8[0], 0, p, D_004531AC[0], D_00452800, D_004531B0[0], 0, 0) < 0) {
        func_00423DC0(D_0045162C[0]);
        return 0;
    }
    v = *(int *)((unsigned)D_00452800 | 0x20000000);
    func_00423DC0(D_0045162C[0]);
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402520);
#ifdef SKIP_ASM
struct P8 { char b[8]; } __attribute__((packed));
extern char D_00453180[];
extern int D_0045162C[];
extern int D_00451610[];
extern int D_00452800[];
extern char D_00497BD8[];
extern char D_00497BF8[];
extern int func_004014F8();
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern void func_00423DC0(int);
extern void func_00425C60();
int func_00402520(struct P8 *a) {
    int v;
    if (func_004014F8(15) == 0)
        return 0;
    if (D_00451610[0] > 0)
        func_00425C60(D_00497BD8);
    if (func_00426D18(D_00453180, 1, 0, 0, 0, D_00452800, 16, 0, 0) < 0) {
        func_00423DC0(D_0045162C[0]);
        return 0;
    }
    *a = *(struct P8 *)((unsigned)&D_00452800[1] | 0x20000000);
    if (D_00451610[0] > 0)
        func_00425C60(D_00497BF8);
    v = *(int *)((unsigned)D_00452800 | 0x20000000);
    func_00423DC0(D_0045162C[0]);
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402618);
#ifdef SKIP_ASM
extern char D_00453180[];
extern int D_0045162C[];
extern int D_00452800[];
extern int D_00452C40[];
extern int func_004014F8();
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
extern void func_00423DC0(int);
extern void func_00426358_p(int *, int) __asm__("func_00426358");
int func_00402618(int a, int *out) {
    int v;
    int *p = D_00452C40;
    if (func_004014F8(26) == 0)
        return -1;
    D_00452C40[0] = a;
    func_00426358_p(p, 4);
    if (func_00426D18(D_00453180, 5, 0, p, 4, D_00452800, 8, 0, 0) < 0) {
        func_00423DC0(*(volatile int *)D_0045162C);
        return -1;
    }
    if (out)
        *out = *(int *)((unsigned)&D_00452800[1] | 0x20000000);
    v = *(int *)((unsigned)D_00452800 | 0x20000000);
    func_00423DC0(D_0045162C[0]);
    return v;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00402708);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004027B8);
#ifdef SKIP_ASM
extern char D_00497C20[];
extern int i7B8_memset(int, int, int) __asm__("func_00416210");
extern void i7B8_34A8(int *, char *) __asm__("func_004034A8");
extern void i7B8_2D50(int *, int, int) __asm__("func_00402D50");
extern unsigned i7B8_2D88(int *, int *, unsigned, unsigned) __asm__("func_00402D88");
extern void i7B8_3338(int *) __asm__("func_00403338");
extern int i7B8_2B58(int *) __asm__("func_00402B58");
extern int i7B8_2BB0(int *) __asm__("func_00402BB0");
extern void i7B8_2D68(int *) __asm__("func_00402D68");
extern int i7B8_3DB0(int *) __asm__("func_00403DB0");
extern int i7B8_3DD8(int *) __asm__("func_00403DD8");
// sceMpegCreate(mp, buff, size)
int func_004027B8(int *a, int buf, int size) {
    int *p;
    int *q;
    int v;
    int rem;
    i7B8_memset(buf, 0, size);
    p = (int *)(((unsigned)(buf + 3) >> 2) << 2);
    rem = size - ((int)p - buf);
    if ((unsigned)rem < 0x10C0) {
        i7B8_34A8(p, D_00497C20);
        return 0;
    }
    q = p + 0x108 / 4;
    a[16] = (int)p;
    i7B8_2D50(q, (int)p + 0x10C0, rem - 0x10C0);
    v = -1;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    *(long *)&a[4] = -1;
    *(long *)&a[6] = -1;
    *(long *)&a[8] = 0;
    *(long *)&a[10] = -1;
    *(long *)&a[12] = -1;
    *(long *)&a[14] = 0;
    p[45] = 0;
    p[46] = 0;
    p[47] = 0;
    p[48] = 0;
    p[49] = 0;
    p[50] = 0;
    p[51] = 0;
    p[52] = 0;
    p[53] = 0;
    p[54] = 0;
    p[55] = 0;
    p[56] = 0;
    p[57] = 0;
    p[58] = 0;
    p[62] = 0;
    p[3] = 0;
    p[5] = 0;
    p[11] = 0;
    p[13] = 0;
    p[15] = 0;
    *(long *)&p[60] = -1;
    p[7] = (int)i7B8_3DB0;
    p[9] = (int)i7B8_3DD8;
    p[17] = i7B8_2D88(p, q, 0x600, 8);
    p[18] = 0;
    p[63] = 0;
    p[64] = 0;
    p[65] = 0;
    p[28] = 0;
    *(long *)&p[30] = 0;
    p[32] = v;
    *(long *)&p[34] = 0;
    p[36] = 0;
    p[43] = 0;
    p[37] = v;
    p[38] = v;
    p[39] = v;
    p[534] = (int)a;
    p[44] = 1;
    i7B8_3338(p);
    i7B8_2B58(a);
    i7B8_2BB0(a);
    p[110] = (int)p + 0x1E8;
    p[111] = (int)p + 0x250;
    p[113] = (int)p + 0x2B8;
    p[114] = (int)p + 0x320;
    p[115] = (int)p + 0x388;
    p[117] = (int)p + 0x3F0;
    p[118] = (int)p + 0x458;
    p[119] = (int)p + 0x4C0;
    p[121] = (int)p + 0x528;
    i7B8_2D68(q);
    p[532] = v;
    p[533] = 0;
    p[531] = 0;
    p[519] = 0x70003600;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004029C8);
#ifdef SKIP_ASM
int func_004029C8(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004029D0);
#ifdef SKIP_ASM
extern int func_00403500(int, int, int);
int func_004029D0(int *p, int b, int n) {
    func_00403500(p[16], b, (n + 19) / 16 * 16);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402A10);
#ifdef SKIP_ASM
extern int func_00402E10(int *);
int func_00402A10(int *a, unsigned b, int c) {
    int *p = (int *)a[16];
    b = (b & 0xFFFFFFF) | 0x20000000;
    p[44] = 1;
    p[54] = b;
    p[57] = c;
    p[56] = 0;
    p[55] = 0;
    return func_00402E10(a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402A58);
#ifdef SKIP_ASM
extern int func_00402E10(int *);
int func_00402A58(int *a, unsigned b, int c) {
    int *p = (int *)a[16];
    b = (b & 0xFFFFFFF) | 0x20000000;
    p[57] = c;
    p[54] = b;
    p[44] = 0;
    p[56] = 0;
    p[55] = 0;
    return func_00402E10(a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402AA0);
#ifdef SKIP_ASM
extern int func_00402E10(int *);
int func_00402AA0(int *a, unsigned b, int c, int d) {
    int *p = (int *)a[16];
    b = (b & 0xFFFFFFF) | 0x20000000;
    p[56] = d * 16;
    p[54] = b;
    p[57] = c * d;
    p[55] = c * 16;
    p[44] = 0;
    return func_00402E10(a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402AF0);
#ifdef SKIP_ASM
void func_00402AF0(int *p) {
    int *q = (int *)p[16];
    q[0x428] = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B00);
#ifdef SKIP_ASM
void func_00402B00(int *p, int a, int b, int c) {
    int *q = (int *)p[16];
    q[37] = a;
    q[38] = b;
    q[39] = c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B18);
#ifdef SKIP_ASM
void func_00402B18(int *p, int *a, int *b, int *c) {
    int *q = (int *)p[16];
    *a = q[37];
    *b = q[38];
    *c = q[39];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B38);
#ifdef SKIP_ASM
int func_00402B38(int *p) {
    int *q = (int *)p[16];
    return q[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B48);
#ifdef SKIP_ASM
int func_00402B48(int *p) {
    int *q = (int *)p[16];
    return q[1] == 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402B58);
#ifdef SKIP_ASM
extern void func_00403398(int *);
int func_00402B58(int *a) {
    int *p = (int *)a[16];
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    a[2] = 0;
    p[43] = 0;
    p[32] = -1;
    func_00403398(p);
    p[70] = 0;
    func_004032A8(p);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402BB0);
#ifdef SKIP_ASM
int func_00402BB0(int *p) {
    char *q = (char *)p[16];
    int *t;
    if ((t = *(int **)(q + 0x1B8))) t[10] = 0;
    if ((t = *(int **)(q + 0x1C8))) t[10] = 0;
    if ((t = *(int **)(q + 0x1D8))) t[10] = 0;
    if ((t = *(int **)(q + 0x1BC))) t[10] = 0;
    if ((t = *(int **)(q + 0x1CC))) t[10] = 0;
    if ((t = *(int **)(q + 0x1DC))) t[10] = 0;
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00402C08);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402C30);
#ifdef SKIP_ASM
struct FA_402C30 { int (*fn)(int *, int *, int); int arg; };
struct T_402C30 { char pad[12]; struct FA_402C30 e[1]; };
int func_00402C30(int *p, int *v) {
    int r = 0;
    if (p) {
        struct T_402C30 *q = (struct T_402C30 *)p[16];
        if (q) {
            if (q->e[*v].fn) {
                r = q->e[*v].fn(p, v, q->e[*v].arg);
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402C80);
#ifdef SKIP_ASM
extern int func_00402C30(int *, int *);
int func_00402C80(int *p) {
    int v[8];
    v[0] = 1;
    func_00402C30(p, v);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CA8);
#ifdef SKIP_ASM
int func_00402CA8(int *p, long v) {
    int *q = (int *)p[16];
    q[28] = 1;
    *(long *)&q[30] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CC0);
#ifdef SKIP_ASM
int func_00402CC0(int *p) {
    int *q = (int *)p[16];
    q[28] = 0;
    *(long *)&q[30] = 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CD8);
#ifdef SKIP_ASM
int func_00402CD8(int *p, int v) {
    int *q = (int *)p[16];
    q[54] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CE8);
#ifdef SKIP_ASM
int func_00402CE8(int *p) {
    int *q = (int *)p[16];
    return q[51];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402CF8);
#ifdef SKIP_ASM
int func_00402CF8(int *p) {
    int *q = (int *)p[16];
    return q[52];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D08);
#ifdef SKIP_ASM
char *func_00402D08(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D18);
#ifdef SKIP_ASM
char *func_00402D18(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D28);
#ifdef SKIP_ASM
int func_00402D28(int *p, int v) {
    int *q = (int *)p[16];
    int old = q[58];
    q[58] = v;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D38);
#ifdef SKIP_ASM
int func_00402D38(int *p, long v) {
    int *q = (int *)p[16];
    *(long *)&q[60] = v;
    q[62] = 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D50);
#ifdef SKIP_ASM
void func_00402D50(int *p, int a, int b) {
    p[0] = a;
    p[1] = b;
    p[2] = a;
    p[3] = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D68);
#ifdef SKIP_ASM
int func_00402D68(int *p) {
    return p[3] = p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D78);
#ifdef SKIP_ASM
int func_00402D78(int *p) {
    return p[2] = p[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402D88);
#ifdef SKIP_ASM
extern char D_00497C48[];
extern void func_004034A8(int *, int);
unsigned func_00402D88(int *a, unsigned *p, unsigned size, unsigned align) {
    unsigned s = (p[2] + align - 1) / align * align;
    unsigned e = s + size;
    if (p[0] + p[1] >= e) {
        p[2] = e;
        return s;
    }
    func_004034A8(a, (int)D_00497C48);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402DF8);
#ifdef SKIP_ASM
int func_00402DF8(int *p) {
    return p[0] + p[1] - p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402E10);
#ifdef SKIP_ASM
extern char D_00497C68[];
extern void func_00403470_k() __asm__("func_00403470");
extern int func_00403240();
extern int func_00403098();
extern int func_00407520();
int func_00402E10(int *a) {
    int *p = (int *)a[16];
    int r = 0;
    int s = 1;
    p[0] = 0;
    if ((p[54] & 0x3F) != 0) {
        func_00403470_k(p, D_00497C68, p[54]);
        return -1;
    }
    p[520] = 0;
    for (;;) {
        if (r != -1) {
            do {
                s = func_00407520(p);
                if (s == 0)
                    break;
                if (p[93] == p[53])
                    break;
            } while (p[530] != 0);
        }
        switch (s) {
        case 0:
            func_00403240(a);
            p[0] = 1;
            break;
        case 1:
            p[42] = 0;
            p[41] = 0;
            p[40] = 0;
            r = func_00403098(a, 0, p[37]);
            p[40]++;
            break;
        case 2:
            r = func_00403098(a, p[41], p[38]);
            p[41]++;
            break;
        case 3:
        case 4:
            r = func_00403098(a, p[42], p[39]);
            p[42]++;
            break;
        }
        if (p[520] != 0)
            return 1;
        if (p[0] != 0)
            return 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00402F80);
#ifdef SKIP_ASM
struct P_2F80 { char pad[4]; int f4; int f8; char padC[0xA0]; int fAC; char pad2[0x68]; int f118; char pad3[4]; int f120; char pad4[0x50]; int f174; };
struct A_2F80 { char pad[8]; int f8; char pad2[0x34]; struct P_2F80 *f40; };
extern int s2_7F20(struct P_2F80 *, int) __asm__("func_00407F20");
extern int s2_7DC0(struct P_2F80 *) __asm__("func_00407DC0");
extern void s2_2C80(struct A_2F80 *) __asm__("func_00402C80");
extern void s2_7E90(struct P_2F80 *, int, int) __asm__("func_00407E90");
int func_00402F80(struct A_2F80 *a, int b, int c) {
    struct P_2F80 *p = a->f40;
    int t, ret;
    int flag = 0;
    if (c == -1 || b < c) {
        if (p->f8 == 0) {
            a->f8 = 0;
            p->f8 = 1;
        }
        t = s2_7F20(p, 0) ? s2_7DC0(p) != 0 : 0;
        ret = t;
    } else {
        ret = s2_7F20(p, 0);
        flag = 1;
        s2_2C80(a);
    }
    s2_7E90(p, p->f118, p->f4);
    if ((t = p->f174) != 3 && flag == 0)
        p->f120 = p->f120 == 0;
    a->f8 = p->f118 - p->fAC;
    if (p->f120 == 0) {
        p->f118++;
        p->f4++;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403098);
#ifdef SKIP_ASM
struct P_3098 { char pad[0x174]; int f174; };
struct A_3098 { char pad[0x40]; struct P_3098 *f40; };
extern int s98_30E0(struct A_3098 *, int, int) __asm__("func_004030E0");
extern int s98_2F80(struct A_3098 *, int, int) __asm__("func_00402F80");
int func_00403098(struct A_3098 *a, int b, int c) {
    if (a->f40->f174 != 3) return s98_30E0(a, b, c);
    return s98_2F80(a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004030E0);
#ifdef SKIP_ASM
struct P_30E0 { int f0; int f4; int f8; char padC[0xA0]; int fAC; char pad2[0x24]; int fD4; char pad3[0x40]; int f118; char pad4[4]; int f120; char pad5[0x50]; int f174; };
struct A_30E0 { char pad[8]; int f8; char pad2[0x34]; struct P_30E0 *f40; };
extern int s3_7F20(struct P_30E0 *, int) __asm__("func_00407F20");
extern int s3_7DC0(struct P_30E0 *) __asm__("func_00407DC0");
extern void s3_2C80(struct A_30E0 *) __asm__("func_00402C80");
extern void s3_7E90(struct P_30E0 *, int, int) __asm__("func_00407E90");
extern int s3_7520(struct P_30E0 *) __asm__("func_00407520");
extern void s3_3240(struct A_30E0 *) __asm__("func_00403240");
int func_004030E0(struct A_30E0 *a, int b, int c) {
    struct P_30E0 *p = a->f40;
    int flag = 0;
    int ret, k, t;
    p->f120 = 0;
    if (c == -1 || b < c)
        flag = 1;
    if (p->f8 == 0) {
        a->f8 = 0;
        p->f8 = 1;
    }
    if (s3_7F20(p, 0)) {
        if (flag)
            s3_7DC0(p);
    }
    p->f120 = 1;
    if (s3_7520(p) == 0) {
        s3_3240(a);
        p->f0 = 1;
        return 0;
    }
    k = 2;
    if (p->fD4 != 1)
        k = 1;
    if (p->f174 != k)
        return -1;
    ret = 0;
    t = 0;
    if (s3_7F20(p, 1))
        t = 1;
    if (t && flag) {
        if (s3_7DC0(p))
            ret = 1;
    }
    s3_7E90(p, p->f118, p->f4);
    p->f120 = 0;
    a->f8 = p->f118 - p->fAC;
    p->f118++;
    p->f4++;
    if (!flag)
        s3_2C80(a);
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403240);
#ifdef SKIP_ASM
extern void func_004032B8(int *);
int func_00403240(int *a) {
    int *s = (int *)a[16];
    int r = 0;
    if (s[1] != 0 && s[2] != 0) {
        func_004032B8(s);
        a[2] = s[70] - s[43];
        s[1] = 0;
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004032A8);
#ifdef SKIP_ASM
extern void func_00405B48(unsigned);
void func_004032A8(int *p) {
    p[530] = 0;
    func_00405B48(1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004032B8);
#ifdef SKIP_ASM
extern void func_004034A8(int *, int);
extern char D_00497CC8[];
extern void func_004086C0(int *, int, int);
extern void func_004087D0(int *, int, int, int);
void func_004032B8(int *p) {
    int n = p[0x118 / 4];
    if (p[0x120 / 4] != 0) {
        func_004034A8(p, (int)D_00497CC8);
    } else if (p[0x174 / 4] == 3) {
        func_004086C0(p, p[0x1BC / 4], n - 1);
    } else {
        func_004087D0(p, p[0x1CC / 4], p[0x1DC / 4], n - 1);
    }
    p[0x120 / 4] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403338);
#ifdef SKIP_ASM
extern void func_00405B48(unsigned);
void func_00403338(int *p) {
    int v = 0x70000000;
    func_00405B48(1);
    p[356] = v;
    p[357] = 0x70001800;
    p[436] = 0x70001B00;
    p[437] = 0x70003300;
    p[516] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403398);
#ifdef SKIP_ASM
extern int func_0042C078_0() __asm__("func_0042C078");
extern void func_0042C0C0(void);
extern void func_00409638_2(int, int) __asm__("func_00409638");
void func_00403398(int *p) {
    int s;
    p[0x818 / 4] = 1;
    p[0x1B0 / 4] = 0;
    s = func_0042C078_0();
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B000 = 0;
    *(volatile int *)0x1000B400 = 0;
    *(volatile int *)0x1000D400 = 0;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    if (s)
        func_0042C0C0();
    *(volatile int *)0x1000B020 = 0;
    *(volatile int *)0x1000B420 = 0;
    *(volatile int *)0x1000D420 = 0;
    *(volatile int *)0x10002010 = 0x40000000;
    func_00409638_2(0, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403460);
#ifdef SKIP_ASM
extern char D_00497CE8[];
extern void func_00425C60(char *, int);
void func_00403460(int a) {
    func_00425C60(D_00497CE8, a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403470);
#ifdef SKIP_ASM
extern int sprintf(char *, const char *, ...);
extern void func_004034A8(int *, int);
void func_00403470(int *a, char *fmt) {
    char buf[256];
    sprintf(buf, fmt);
    func_004034A8(a, (int)buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004034A8);
#ifdef SKIP_ASM
extern int func_00402C30(int *, int *);
extern void func_00403460(int);
void func_004034A8(int *p, int b) {
    int v[2];
    int *q = (int *)p[534];
    if (q && p && p[3]) {
        v[0] = 0;
        v[1] = b;
        func_00402C30(q, v);
        return;
    }
    func_00403460(b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403500);
#ifdef SKIP_ASM
extern void func_00424020(int) __asm__("func_00424020");
extern int func_0042C078();
extern void func_0042C0C0(void);
void q3500(int base, unsigned addr, int n) __asm__("func_00403500");
void q3500(int base, unsigned addr, int n) {
    unsigned t = ((unsigned)(base + 0x88F) >> 4) << 4;
    long *tag = (long *)t;
    int ret;
    while (n > 0) {
        int chunk = n > 0xFFF40 ? 0xFFF40 : n;
        int id = 0;
        long hi = addr & 0xFFFFFFF;
        n -= chunk;
        if (n != 0) id = 3;
        *tag = (hi << 32) | ((long)id << 28) | (unsigned long)(unsigned)((chunk + 0xF) / 16);
        __asm__ volatile("sync");
        addr += chunk;
        tag += 2;
    }
    func_00424020(0);
    ret = func_0042C078();
    *(volatile int *)0x1000B430 = t & 0xFFFFFFF;
    *(volatile int *)0x1000B420 = 0;
    *(volatile int *)0x1000B400 = 0x105;
    if (ret)
        func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403600);
#ifdef SKIP_ASM
int func_00403600(int *p, int a, int b) {
    p[1] = a;
    p[2] = b;
    p[3] = a >> 4;
    p[4] = b >> 4;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403620);
#ifdef SKIP_ASM
extern char D_00453200[];
extern char D_00453240[];
extern char D_00497CF8[];
extern int func_004072E8();
extern void func_00403AD0();
extern void func_00403748();
extern void func_004076F8();
void func_00403620(int *p) {
    unsigned v;
    int w;
    int b;
    p[0xD4 / 4] = 0;
    v = func_004072E8(p, 32);
    w = (v >> 8) & 0xFFF;
    p[0x124 / 4] = v >> 20;
    p[0x128 / 4] = w;
    if (w >= 0xAF1)
        func_004034A8(p, (int)D_00497CF8);
    v = func_004072E8(p, 30);
    p[0x134 / 4] = v >> 12;
    p[0x138 / 4] = (v >> 1) & 0x3FF;
    b = func_004072E8(p, 1);
    p[0x840 / 4] = b;
    if (b != 0) {
        func_00406E20((int)p);
        func_00406DF0(p, 0x50000000);
        func_00406E20((int)p);
    } else {
        func_00403AD0(p, 0x50000000, D_00453200);
    }
    b = func_004072E8(p, 1);
    p[0x844 / 4] = b;
    if (b != 0) {
        func_00406E20((int)p);
        func_00406DF0(p, 0x58000000);
        func_00406E20((int)p);
    } else {
        func_00403AD0(p, 0x58000000, D_00453240);
    }
    func_004076F8(p);
    func_00403748(p[0x858 / 4]);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00403748);

INCLUDE_ASM("seg/seg_2FE810", func_004039F0);

INCLUDE_ASM("seg/seg_2FE810", func_00403AD0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403BB0);
#ifdef SKIP_ASM
extern char D_00497D10[];
extern char D_00497D38[];
extern void func_00405B48(unsigned);
void func_00403BB0(int *p) {
    unsigned v;
    unsigned h;
    unsigned w;
    int t;
    unsigned x;
    unsigned y;
    unsigned z;
    p[0x848 / 4] = 1;
    func_00405B48(0);
    v = func_004072E8(p, 28);
    x = (v >> 1) & 0xFFF;
    t = (v >> 17) & 3;
    y = (v >> 13) & 3;
    z = (v >> 15) & 3;
    p[0x140 / 4] = t;
    if (t != 1)
        func_004034A8(p, (int)D_00497D10);
    p[0x13C / 4] = (v >> 19) & 1;
    h = v >> 20;
    w = (unsigned)func_004072E8(p, 16) >> 8;
    if (h != 0x48 && h != 0x58 && h != 0x44)
        func_004034A8(p, (int)D_00497D38);
    p[0x124 / 4] = (z << 12) | (p[0x124 / 4] & 0xFFF);
    p[0x128 / 4] = (y << 12) | (p[0x128 / 4] & 0xFFF);
    p[0x134 / 4] = p[0x134 / 4] + (x << 18);
    p[0x138 / 4] = p[0x138 / 4] + (w << 10);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403CE0);
#ifdef SKIP_ASM
extern int func_004072E8(int, int);
void func_00403CE0(int *p) {
    func_004072E8((int)p, 3);
    if (func_004072E8((int)p, 1)) {
        func_004072E8((int)p, 8);
        func_004072E8((int)p, 8);
        p[0x144 / 4] = func_004072E8((int)p, 8);
    }
    p[0x148 / 4] = func_004072E8((int)p, 0xE);
    func_004072E8((int)p, 1);
    p[0x14C / 4] = func_004072E8((int)p, 0xE);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", _sequenceScalableExtension);
#ifdef SKIP_ASM
extern char D_00497D58[];
extern void func_004034A8(int *, int);
void _sequenceScalableExtension(int *p) {
    func_004034A8(p, (int)D_00497D58);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403D80);
#ifdef SKIP_ASM
extern char D_00497D88[];
extern void func_004034A8(int *, int);
void func_00403D80(int *p) {
    func_004034A8(p, (int)D_00497D88);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403D90);
#ifdef SKIP_ASM
extern char D_00497DA0[];
extern void func_004034A8(int *, int);
void func_00403D90(int *p) {
    func_004034A8(p, (int)D_00497DA0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403DA0);
#ifdef SKIP_ASM
extern char D_00497DD8[];
extern void func_004034A8(int *, int);
void func_00403DA0(int *p) {
    func_004034A8(p, (int)D_00497DD8);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403DB0);
#ifdef SKIP_ASM
extern void func_00409400(void *);
int func_00403DB0(int *p) {
    func_00409400((char *)p[16] + 0x4C);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00403DD8);
#ifdef SKIP_ASM
extern void func_004094E8(void *);
int func_00403DD8(int *p) {
    func_004094E8((char *)p[16] + 0x4C);
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00403E00);

INCLUDE_ASM("seg/seg_2FE810", func_00404050);

INCLUDE_ASM("seg/seg_2FE810", func_00404758);

INCLUDE_ASM("seg/seg_2FE810", func_00404B78);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00404D98);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00404D98(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "sll $11, $12, 1\n"
        "addiu $15, $0, -0x1\n"
        "mtsab $13, 0x0\n"
        "1:\n"
        "lq $8, 0x0($5)\n"
        "addi $7, $7, -0x1\n"
        "lq $9, 0x0($6)\n"
        "addu $5, $5, $12\n"
        "qfsrv $10, $9, $8\n"
        "pextlb $8, $0, $10\n"
        "pextub $9, $0, $10\n"
        "sq $8, 0x0($14)\n"
        "addu $6, $6, $12\n"
        "sq $9, 0x10($14)\n"
        "bgtz $7, 1b\n"
        "addu $14, $14, $11\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $10, $15, $7\n"
        "bnez $10, 1b\n"
        "daddu $15, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00404E10);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00404E10(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "sll $11, $12, 1\n"
        "mtsab $13, 0x0\n"
        "addiu $24, $0, -0x1\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "addiu $15, $0, -0x1\n"
        "2:\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "qfsrv $9, $8, $8\n"
        "pextlb $8, $0, $9\n"
        "sq $8, 0x0($14)\n"
        "addi $7, $7, -0x1\n"
        "addu $5, $5, $12\n"
        "addu $14, $14, $11\n"
        "bgtz $7, 2b\n"
        "addu $6, $6, $12\n"
        "addiu $5, $5, 0x140\n"
        "addiu $6, $6, 0x140\n"
        "lw $7, 0xC($4)\n"
        "and $10, $15, $7\n"
        "bnez $10, 2b\n"
        "daddu $15, $0, $0\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "bnez $24, 1b\n"
        "daddu $24, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00404EA8);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00404EA8(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $24, 0x10($4)\n"
        "lq $8, 0x0($5)\n"
        "sll $12, $24, 1\n"
        "lq $9, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $10, $9, $8\n"
        "pextlb $8, $0, $10\n"
        "addiu $11, $0, -0x1\n"
        "beqz $7, 2f\n"
        "pextub $9, $0, $10\n"
        "1:\n"
        "addu $5, $5, $24\n"
        "addu $6, $6, $24\n"
        "lq $10, 0x0($5)\n"
        "lq $15, 0x0($6)\n"
        "qfsrv $2, $15, $10\n"
        "pextlb $10, $0, $2\n"
        "addi $7, $7, -0x1\n"
        "pextub $15, $0, $2\n"
        "paddh $2, $8, $10\n"
        "paddh $3, $9, $15\n"
        "por $8, $10, $0\n"
        "por $9, $15, $0\n"
        "paddh $2, $2, $25\n"
        "paddh $3, $3, $25\n"
        "psrlh $2, $2, 1\n"
        "psrlh $3, $3, 1\n"
        "sq $2, 0x0($14)\n"
        "sq $3, 0x10($14)\n"
        "bgtz $7, 1b\n"
        "addu $14, $14, $12\n"
        "2:\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $10, $11, $7\n"
        "bnez $10, 1b\n"
        "daddu $11, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00404F60);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00404F60(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "addiu $11, $0, 0x1\n"
        "sll $24, $12, 1\n"
        "mtsab $13, 0x0\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "qfsrv $8, $8, $8\n"
        "ori $11, $11, 0x8000\n"
        "beqz $7, 3f\n"
        "pextlb $15, $0, $8\n"
        "2:\n"
        "addu $5, $5, $12\n"
        "addu $6, $6, $12\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $10, $0, $8\n"
        "addi $7, $7, -0x1\n"
        "paddh $9, $10, $15\n"
        "por $15, $10, $0\n"
        "paddh $10, $9, $25\n"
        "psrlh $10, $10, 1\n"
        "sq $10, 0x0($14)\n"
        "bgtz $7, 2b\n"
        "addu $14, $14, $24\n"
        "3:\n"
        "psrah $10, $11, 15\n"
        "addiu $5, $5, 0x140\n"
        "lw $7, 0xC($4)\n"
        "addiu $6, $6, 0x140\n"
        "and $10, $10, $7\n"
        "bnez $10, 2b\n"
        "andi $11, $11, 0x7FFF\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "andi $10, $11, 0x1\n"
        "bnez $10, 1b\n"
        "andi $11, $11, 0xFFFE\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405030);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405030(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "addiu $24, $0, 0x1\n"
        "lw $9, 0x10($4)\n"
        "sll $8, $9, 1\n"
        "addiu $11, $0, -0x1\n"
        "1:\n"
        "lq $10, 0x0($5)\n"
        "lq $15, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $2, $15, $10\n"
        "qfsrv $3, $10, $15\n"
        "pextlb $10, $0, $2\n"
        "addi $7, $7, -0x1\n"
        "pextub $15, $0, $2\n"
        "mtsab $24, 0x0\n"
        "qfsrv $3, $3, $2\n"
        "pextlb $2, $0, $3\n"
        "pextub $3, $0, $3\n"
        "paddh $10, $10, $2\n"
        "paddh $15, $15, $3\n"
        "paddh $2, $10, $25\n"
        "paddh $3, $15, $25\n"
        "psrlh $2, $2, 1\n"
        "psrlh $3, $3, 1\n"
        "sq $2, 0x0($14)\n"
        "sq $3, 0x10($14)\n"
        "addu $5, $5, $9\n"
        "addu $6, $6, $9\n"
        "bgtz $7, 1b\n"
        "addu $14, $14, $8\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $12, $11, $7\n"
        "bnez $12, 1b\n"
        "daddu $11, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004050E0);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_004050E0(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "addiu $24, $0, 0x1\n"
        "addiu $12, $0, -0x1\n"
        "lw $3, 0x10($4)\n"
        "sll $2, $3, 1\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "addiu $11, $0, -0x1\n"
        "2:\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "mtsab $13, 0x0\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $9, $0, $8\n"
        "addi $7, $7, -0x1\n"
        "addu $5, $5, $3\n"
        "addu $6, $6, $3\n"
        "mtsab $24, 0x0\n"
        "qfsrv $10, $0, $8\n"
        "pextlb $8, $0, $10\n"
        "paddh $10, $9, $8\n"
        "paddh $10, $10, $25\n"
        "psrlh $10, $10, 1\n"
        "sq $10, 0x0($14)\n"
        "bgtz $7, 2b\n"
        "addu $14, $14, $2\n"
        "addiu $5, $5, 0x140\n"
        "addiu $6, $6, 0x140\n"
        "lw $7, 0xC($4)\n"
        "and $10, $11, $7\n"
        "bnez $10, 2b\n"
        "daddu $11, $0, $0\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "bnez $12, 1b\n"
        "daddu $12, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405198);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405198(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "psllh $25, $25, 1\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "addiu $24, $0, 0x1\n"
        "lq $8, 0x0($5)\n"
        "lq $9, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $10, $9, $8\n"
        "qfsrv $15, $8, $9\n"
        "pextlb $8, $0, $10\n"
        "pextub $9, $0, $10\n"
        "addiu $11, $0, -0x1\n"
        "mtsab $24, 0x0\n"
        "qfsrv $15, $15, $10\n"
        "pextlb $10, $0, $15\n"
        "pextub $15, $0, $15\n"
        "paddh $8, $8, $10\n"
        "beqz $7, 2f\n"
        "paddh $9, $9, $15\n"
        "1:\n"
        "addu $5, $5, $12\n"
        "addu $6, $6, $12\n"
        "lq $10, 0x0($5)\n"
        "lq $15, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $2, $15, $10\n"
        "qfsrv $3, $10, $15\n"
        "pextlb $10, $0, $2\n"
        "addi $7, $7, -0x1\n"
        "pextub $15, $0, $2\n"
        "mtsab $24, 0x0\n"
        "qfsrv $3, $3, $2\n"
        "pextlb $2, $0, $3\n"
        "pextub $3, $0, $3\n"
        "paddh $10, $10, $2\n"
        "paddh $15, $15, $3\n"
        "paddh $2, $8, $10\n"
        "paddh $3, $9, $15\n"
        "por $8, $10, $0\n"
        "por $9, $15, $0\n"
        "paddh $2, $2, $25\n"
        "paddh $3, $3, $25\n"
        "psrlh $2, $2, 2\n"
        "psrlh $3, $3, 2\n"
        "sq $2, 0x0($14)\n"
        "sll $10, $12, 1\n"
        "sq $3, 0x10($14)\n"
        "bgtz $7, 1b\n"
        "addu $14, $14, $10\n"
        "2:\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $10, $11, $7\n"
        "bnez $10, 1b\n"
        "daddu $11, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405290);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405290(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "psllh $25, $25, 1\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "addiu $24, $0, 0x1\n"
        "addiu $11, $0, 0x1\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "mtsab $13, 0x0\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $9, $0, $8\n"
        "addu $5, $5, $12\n"
        "ori $11, $11, 0x8000\n"
        "mtsab $24, 0x0\n"
        "qfsrv $10, $0, $8\n"
        "pextlb $8, $0, $10\n"
        "beqz $7, 3f\n"
        "paddh $15, $9, $8\n"
        "2:\n"
        "addu $6, $6, $12\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "mtsab $13, 0x0\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $9, $0, $8\n"
        "addi $7, $7, -0x1\n"
        "addu $5, $5, $12\n"
        "mtsab $24, 0x0\n"
        "qfsrv $10, $0, $8\n"
        "pextlb $8, $0, $10\n"
        "paddh $10, $9, $8\n"
        "paddh $9, $10, $15\n"
        "por $15, $10, $0\n"
        "paddh $10, $9, $25\n"
        "sll $8, $12, 1\n"
        "psrlh $10, $10, 2\n"
        "sq $10, 0x0($14)\n"
        "bgtz $7, 2b\n"
        "addu $14, $14, $8\n"
        "3:\n"
        "psrah $10, $11, 15\n"
        "addiu $5, $5, 0x140\n"
        "lw $7, 0xC($4)\n"
        "addiu $6, $6, 0x140\n"
        "and $10, $10, $7\n"
        "bnez $10, 2b\n"
        "andi $11, $11, 0x7FFF\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "andi $10, $11, 0x1\n"
        "bnez $10, 1b\n"
        "andi $11, $11, 0xFFFE\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405390);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405390(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $9, 0x10($4)\n"
        "sll $8, $9, 1\n"
        "addiu $11, $0, -0x1\n"
        "mtsab $13, 0x0\n"
        "1:\n"
        "lq $10, 0x0($5)\n"
        "lq $15, 0x0($6)\n"
        "qfsrv $2, $15, $10\n"
        "pextlb $10, $0, $2\n"
        "pextub $15, $0, $2\n"
        "lq $2, 0x0($14)\n"
        "lq $3, 0x10($14)\n"
        "paddh $2, $2, $10\n"
        "paddh $3, $3, $15\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "paddh $10, $2, $25\n"
        "psrlh $2, $10, 1\n"
        "paddh $10, $3, $25\n"
        "psrlh $3, $10, 1\n"
        "sq $2, 0x0($14)\n"
        "sq $3, 0x10($14)\n"
        "addi $7, $7, -0x1\n"
        "addu $5, $5, $9\n"
        "addu $14, $14, $8\n"
        "bgtz $7, 1b\n"
        "addu $6, $6, $9\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $12, $11, $7\n"
        "bnez $12, 1b\n"
        "daddu $11, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405430);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405430(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "addiu $12, $0, -0x1\n"
        "lw $3, 0x10($4)\n"
        "sll $2, $3, 1\n"
        "mtsab $13, 0x0\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "addiu $11, $0, -0x1\n"
        "2:\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $9, $0, $8\n"
        "addi $7, $7, -0x1\n"
        "addu $5, $5, $3\n"
        "addu $6, $6, $3\n"
        "lq $8, 0x0($14)\n"
        "paddh $10, $9, $8\n"
        "pcgth $9, $10, $0\n"
        "psrlh $9, $9, 15\n"
        "paddh $10, $10, $9\n"
        "psrlh $10, $10, 1\n"
        "sq $10, 0x0($14)\n"
        "bgtz $7, 2b\n"
        "addu $14, $14, $2\n"
        "addiu $5, $5, 0x140\n"
        "addiu $6, $6, 0x140\n"
        "lw $7, 0xC($4)\n"
        "and $10, $11, $7\n"
        "bnez $10, 2b\n"
        "daddu $11, $0, $0\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "bnez $12, 1b\n"
        "daddu $12, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004054E0);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_004054E0(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "lq $8, 0x0($5)\n"
        "lq $9, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $10, $9, $8\n"
        "sll $24, $12, 1\n"
        "pextlb $8, $0, $10\n"
        "addiu $11, $0, -0x1\n"
        "beqz $7, 2f\n"
        "pextub $9, $0, $10\n"
        "1:\n"
        "addu $5, $5, $12\n"
        "addu $6, $6, $12\n"
        "lq $10, 0x0($5)\n"
        "lq $15, 0x0($6)\n"
        "qfsrv $2, $15, $10\n"
        "pextlb $10, $0, $2\n"
        "addi $7, $7, -0x1\n"
        "pextub $15, $0, $2\n"
        "paddh $2, $8, $10\n"
        "paddh $3, $9, $15\n"
        "por $8, $10, $0\n"
        "por $9, $15, $0\n"
        "paddh $2, $2, $25\n"
        "paddh $3, $3, $25\n"
        "psrlh $2, $2, 1\n"
        "psrlh $3, $3, 1\n"
        "lq $10, 0x0($14)\n"
        "lq $15, 0x10($14)\n"
        "paddh $2, $2, $10\n"
        "paddh $3, $3, $15\n"
        "paddh $10, $2, $25\n"
        "psrlh $2, $10, 1\n"
        "pcgth $10, $3, $0\n"
        "psrlh $10, $10, 15\n"
        "paddh $10, $3, $10\n"
        "psrlh $3, $10, 1\n"
        "sq $2, 0x0($14)\n"
        "sq $3, 0x10($14)\n"
        "bgtz $7, 1b\n"
        "addu $14, $14, $24\n"
        "2:\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $10, $11, $7\n"
        "bnez $10, 1b\n"
        "daddu $11, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004055C0);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_004055C0(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "addiu $11, $0, 0x1\n"
        "sll $24, $12, 1\n"
        "mtsab $13, 0x0\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "qfsrv $8, $8, $8\n"
        "ori $11, $11, 0x8000\n"
        "beqz $7, 3f\n"
        "pextlb $15, $0, $8\n"
        "2:\n"
        "addu $5, $5, $12\n"
        "addu $6, $6, $12\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $10, $0, $8\n"
        "addi $7, $7, -0x1\n"
        "paddh $9, $10, $15\n"
        "por $15, $10, $0\n"
        "paddh $10, $9, $25\n"
        "psrlh $10, $10, 1\n"
        "lq $8, 0x0($14)\n"
        "paddh $10, $10, $8\n"
        "pcgth $9, $10, $0\n"
        "psrlh $9, $9, 15\n"
        "paddh $10, $10, $9\n"
        "psrlh $10, $10, 1\n"
        "sq $10, 0x0($14)\n"
        "bgtz $7, 2b\n"
        "addu $14, $14, $24\n"
        "3:\n"
        "psrah $10, $11, 15\n"
        "addiu $5, $5, 0x140\n"
        "lw $7, 0xC($4)\n"
        "addiu $6, $6, 0x140\n"
        "and $10, $10, $7\n"
        "bnez $10, 2b\n"
        "andi $11, $11, 0x7FFF\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "andi $10, $11, 0x1\n"
        "bnez $10, 1b\n"
        "andi $11, $11, 0xFFFE\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004056A8);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_004056A8(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "addiu $24, $0, 0x1\n"
        "lw $9, 0x10($4)\n"
        "sll $8, $9, 1\n"
        "addiu $11, $0, -0x1\n"
        "1:\n"
        "lq $10, 0x0($5)\n"
        "lq $15, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $2, $15, $10\n"
        "qfsrv $3, $10, $15\n"
        "pextlb $10, $0, $2\n"
        "addi $7, $7, -0x1\n"
        "pextub $15, $0, $2\n"
        "mtsab $24, 0x0\n"
        "qfsrv $3, $3, $2\n"
        "pextlb $2, $0, $3\n"
        "pextub $3, $0, $3\n"
        "paddh $10, $10, $2\n"
        "paddh $15, $15, $3\n"
        "paddh $2, $10, $25\n"
        "paddh $3, $15, $25\n"
        "psrlh $2, $2, 1\n"
        "psrlh $3, $3, 1\n"
        "lq $10, 0x0($14)\n"
        "lq $15, 0x10($14)\n"
        "paddh $2, $2, $10\n"
        "paddh $3, $3, $15\n"
        "paddh $10, $2, $25\n"
        "psrlh $2, $10, 1\n"
        "pcgth $10, $3, $0\n"
        "psrlh $10, $10, 15\n"
        "paddh $10, $3, $10\n"
        "psrlh $3, $10, 1\n"
        "sq $2, 0x0($14)\n"
        "sq $3, 0x10($14)\n"
        "addu $5, $5, $9\n"
        "addu $6, $6, $9\n"
        "bgtz $7, 1b\n"
        "addu $14, $14, $8\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $12, $11, $7\n"
        "bnez $12, 1b\n"
        "daddu $11, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405780);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405780(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "addiu $24, $0, 0x1\n"
        "addiu $12, $0, -0x1\n"
        "lw $3, 0x10($4)\n"
        "sll $2, $3, 1\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "addiu $11, $0, -0x1\n"
        "2:\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "mtsab $13, 0x0\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $9, $0, $8\n"
        "addi $7, $7, -0x1\n"
        "addu $5, $5, $3\n"
        "addu $6, $6, $3\n"
        "mtsab $24, 0x0\n"
        "qfsrv $10, $0, $8\n"
        "pextlb $8, $0, $10\n"
        "paddh $10, $9, $8\n"
        "paddh $10, $10, $25\n"
        "psrlh $10, $10, 1\n"
        "lq $8, 0x0($14)\n"
        "paddh $10, $10, $8\n"
        "pcgth $9, $10, $0\n"
        "psrlh $9, $9, 15\n"
        "paddh $10, $10, $9\n"
        "psrlh $10, $10, 1\n"
        "sq $10, 0x0($14)\n"
        "bgtz $7, 2b\n"
        "addu $14, $14, $2\n"
        "addiu $5, $5, 0x140\n"
        "addiu $6, $6, 0x140\n"
        "lw $7, 0xC($4)\n"
        "and $10, $11, $7\n"
        "bnez $10, 2b\n"
        "daddu $11, $0, $0\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "bnez $12, 1b\n"
        "daddu $12, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405850);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405850(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "psllh $25, $25, 1\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $7, 0x8($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $24, 0x10($4)\n"
        "addiu $12, $0, 0x1\n"
        "lq $8, 0x0($5)\n"
        "lq $9, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $10, $9, $8\n"
        "qfsrv $15, $8, $9\n"
        "pextlb $8, $0, $10\n"
        "pextub $9, $0, $10\n"
        "addiu $11, $0, -0x1\n"
        "mtsab $12, 0x0\n"
        "qfsrv $15, $15, $10\n"
        "pextlb $10, $0, $15\n"
        "pextub $15, $0, $15\n"
        "paddh $8, $8, $10\n"
        "beqz $7, 2f\n"
        "paddh $9, $9, $15\n"
        "1:\n"
        "addu $5, $5, $24\n"
        "addu $6, $6, $24\n"
        "lq $10, 0x0($5)\n"
        "lq $15, 0x0($6)\n"
        "mtsab $13, 0x0\n"
        "qfsrv $2, $15, $10\n"
        "qfsrv $3, $10, $15\n"
        "pextlb $10, $0, $2\n"
        "addi $7, $7, -0x1\n"
        "pextub $15, $0, $2\n"
        "mtsab $12, 0x0\n"
        "qfsrv $3, $3, $2\n"
        "pextlb $2, $0, $3\n"
        "pextub $3, $0, $3\n"
        "paddh $10, $10, $2\n"
        "paddh $15, $15, $3\n"
        "paddh $2, $8, $10\n"
        "paddh $3, $9, $15\n"
        "por $8, $10, $0\n"
        "por $9, $15, $0\n"
        "paddh $2, $2, $25\n"
        "paddh $3, $3, $25\n"
        "psrlh $2, $2, 2\n"
        "psrlh $3, $3, 2\n"
        "lq $10, 0x0($14)\n"
        "lq $15, 0x10($14)\n"
        "paddh $2, $2, $10\n"
        "paddh $3, $3, $15\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "paddh $10, $2, $25\n"
        "psrlh $2, $10, 1\n"
        "paddh $10, $3, $25\n"
        "psrlh $3, $10, 1\n"
        "sq $2, 0x0($14)\n"
        "sll $10, $24, 1\n"
        "sq $3, 0x10($14)\n"
        "bgtz $7, 1b\n"
        "addu $14, $14, $10\n"
        "2:\n"
        "addiu $5, $5, 0x80\n"
        "addiu $6, $6, 0x80\n"
        "lw $7, 0xC($4)\n"
        "and $10, $11, $7\n"
        "bnez $10, 1b\n"
        "daddu $11, $0, $0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405970);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405970(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "pnor $25, $0, $0\n"
        "psrlh $25, $25, 15\n"
        "psllh $25, $25, 1\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "lw $13, 0x4($4)\n"
        "lw $12, 0x10($4)\n"
        "addiu $24, $0, 0x1\n"
        "addiu $11, $0, 0x1\n"
        "1:\n"
        "lw $7, 0x8($4)\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "mtsab $13, 0x0\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $9, $0, $8\n"
        "addu $5, $5, $12\n"
        "ori $11, $11, 0x8000\n"
        "mtsab $24, 0x0\n"
        "qfsrv $10, $0, $8\n"
        "pextlb $8, $0, $10\n"
        "beqz $7, 3f\n"
        "paddh $15, $9, $8\n"
        "2:\n"
        "addu $6, $6, $12\n"
        "ld $8, 0x0($5)\n"
        "ld $9, 0x0($6)\n"
        "pcpyld $8, $9, $8\n"
        "mtsab $13, 0x0\n"
        "qfsrv $8, $8, $8\n"
        "pextlb $9, $0, $8\n"
        "addi $7, $7, -0x1\n"
        "addu $5, $5, $12\n"
        "mtsab $24, 0x0\n"
        "qfsrv $10, $0, $8\n"
        "pextlb $8, $0, $10\n"
        "paddh $10, $9, $8\n"
        "paddh $9, $10, $15\n"
        "por $15, $10, $0\n"
        "paddh $10, $9, $25\n"
        "psrlh $10, $10, 2\n"
        "lq $8, 0x0($14)\n"
        "paddh $10, $10, $8\n"
        "pcgth $9, $10, $0\n"
        "psrlh $9, $9, 15\n"
        "paddh $10, $10, $9\n"
        "sll $8, $12, 1\n"
        "psrlh $10, $10, 1\n"
        "sq $10, 0x0($14)\n"
        "bgtz $7, 2b\n"
        "addu $14, $14, $8\n"
        "3:\n"
        "psrah $10, $11, 15\n"
        "addiu $5, $5, 0x140\n"
        "lw $7, 0xC($4)\n"
        "addiu $6, $6, 0x140\n"
        "and $10, $10, $7\n"
        "bnez $10, 2b\n"
        "andi $11, $11, 0x7FFF\n"
        "lw $5, 0x14($4)\n"
        "lw $6, 0x18($4)\n"
        "lw $14, 0x0($4)\n"
        "addiu $5, $5, 0x40\n"
        "addiu $6, $6, 0x40\n"
        "addiu $14, $14, 0x80\n"
        "andi $10, $11, 0x1\n"
        "bnez $10, 1b\n"
        "andi $11, $11, 0xFFFE\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405A88);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405A88(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "addiu $12, $0, 0x18\n"
        "lui $10, %%hi(D_00405B30)\n"
        "addiu $10, $10, %%lo(D_00405B30)\n"
        "lq $11, 0x0($10)\n"
        "1:\n"
        "lq $8, 0x0($5)\n"
        "addi $12, $12, -0x1\n"
        "lq $13, 0x0($6)\n"
        "addiu $4, $4, 0x10\n"
        "lq $9, 0x10($5)\n"
        "paddh $8, $8, $13\n"
        "lq $2, 0x10($6)\n"
        "pminh $8, $8, $11\n"
        "paddh $9, $9, $2\n"
        "pmaxh $8, $8, $0\n"
        "pminh $9, $9, $11\n"
        "addiu $5, $5, 0x20\n"
        "pmaxh $9, $9, $0\n"
        "addiu $6, $6, 0x20\n"
        "ppacb $10, $9, $8\n"
        "bnez $12, 1b\n"
        "sq $10, -0x10($4)\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405AE8);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (no compiler emits its addi/mtsab/fixed-register code); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function body.
void func_00405AE8(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "addiu $12, $0, 0x18\n"
        "lui $10, %%hi(D_00405B30)\n"
        "addiu $10, $10, %%lo(D_00405B30)\n"
        "lq $11, 0x0($10)\n"
        "1:\n"
        "lq $8, 0x0($5)\n"
        "addi $12, $12, -0x1\n"
        "pminh $8, $8, $11\n"
        "lq $9, 0x10($5)\n"
        "pmaxh $8, $8, $0\n"
        "pminh $9, $9, $11\n"
        "addiu $5, $5, 0x20\n"
        "pmaxh $9, $9, $0\n"
        "addiu $4, $4, 0x10\n"
        "ppacb $10, $9, $8\n"
        "bnez $12, 1b\n"
        "sq $10, -0x10($4)\n"
        "nop\n"
        "nop\n"
        ".globl D_00405B30\n"
        "D_00405B30:\n"
        ".word 0x00FF00FF\n"
        ".word 0x00FF00FF\n"
        ".word 0x00FF00FF\n"
        ".word 0x00FF00FF\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405B48);
#ifdef SKIP_ASM
void func_00405B48(unsigned a) {
    unsigned *r = (unsigned *)0x10002010;
    *r = (*r & 0xFF7FFFFF) | (a << 23);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00405B70);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405E10);
#ifdef SKIP_ASM
extern int func_00406F78(int, int);
int func_00405E10(int a) {
    return func_00406F78(a, 3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405E30);
#ifdef SKIP_ASM
#define H1(x) (((x) + ((x) > 0)) >> 1)
#define H3(x) ((3 * (x) + ((x) > 0)) >> 1)
void func_00405E30(int *p, int *o, int *in, int a, int b) {
    if (p[93] == 3) {
        if (p[94] != 0) {
            o[0] = H1(a) + in[0];
            o[1] = H1(b) + in[1] - 1;
            o[2] = H3(a) + in[0];
            o[3] = H3(b) + in[1] + 1;
        } else {
            o[0] = H3(a) + in[0];
            o[1] = H3(b) + in[1] - 1;
            o[2] = H1(a) + in[0];
            o[3] = H1(b) + in[1] + 1;
        }
    } else {
        o[0] = H1(a) + in[0];
        o[1] = H1(b) + in[1];
        if (p[93] == 1)
            o[1] = o[1] - 1;
        else
            o[1] = o[1] + 1;
    }
}
#undef H1
#undef H3
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00405FB8);
#ifdef SKIP_ASM
extern char D_00497ED0[];
extern int lx5_6F78(int *, int) __asm__("func_00406F78");
extern int lx5_70F0(int *, int) __asm__("func_004070F0");
extern void lx5_71F8(int *, int) __asm__("func_004071F8");
extern void lx5_3470(int *, char *, int) __asm__("func_00403470");
int func_00405FB8(int *p) {
    int sum = 0;
    int c;
    int t;
    int again;
    do {
        c = lx5_6F78(p, 0);
        switch ((unsigned)c) {
        case 0x23:
            again = 1;
            sum += 0x21;
            break;
        case 0x22:
            again = 1;
            break;
        case 0:
            t = lx5_70F0(p, 11);
            if (p[0x848 / 4] != 0 && t == 15) {
                lx5_71F8(p, 11);
                again = 1;
                break;
            }
            lx5_3470(p, D_00497ED0, c);
            p[0x11C / 4] = 1;
            return 1;
        default:
            sum += c;
            again = 0;
            break;
        }
    } while (again);
    return sum;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004060C8);
#ifdef SKIP_ASM
extern char D_00497F08[];
extern int func_00406318(int *, int);
extern void func_00406E20(int);
extern int func_00405B70(int *);
extern void func_00404B78(int *, int);
extern void func_004034A8(int *, int);
int func_004060C8(int *p) {
    int n;
    int r;
    p[0x810 / 4] = 0;
    n = p[0x12C / 4] * p[0x130 / 4];
    p[0x814 / 4] = 0;
    if (p[0x174 / 4] != 3)
        n >>= 1;
    do {
        r = func_00406318(p, n);
    } while (r == 1 || r == 3);
    func_00406E20((int)p);
    if (func_00405B70(p) == 0) {
        r = 4;
        if (p[0x10A0 / 4] != 0)
            p[0x10A0 / 4] = 0;
        else
            r = 2;
    }
    while ((*(volatile unsigned *)0x1000D400 >> 8) & 1)
        ;
    if (r == 0)
        func_00404B78(p, p[0x810 / 4] == 0);
    if ((unsigned)(r - 1) < 2)
        func_004034A8(p, (int)D_00497F08);
    return r == 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", _sliceA0);
#ifdef SKIP_ASM
extern char D_00497F28[];
extern char D_00497F50[];
extern void func_00403470_k() __asm__("func_00403470");
extern int func_004070F0(int, int);
extern void func_004071F8(int, int);
extern void func_00407438();
extern int func_00405FB8(int *);
int _sliceA0(int *p, int unused, int *o1, int *o2, int *s) {
    int v;
    int a;
    int b;
    p[0x11C / 4] = 0;
    func_00407438();
    v = func_004070F0((int)p, 32);
    if ((unsigned)(v - 0x101) >= 0xAF) {
        func_00403470_k(p, D_00497F28, v);
        return 2;
    }
    func_004071F8((int)p, 32);
    a = func_004074B8(p);
    b = func_00405FB8(p);
    *o2 = b;
    if (p[0x11C / 4] != 0) {
        func_004034A8(p, (int)D_00497F50);
        return 1;
    }
    *o1 = ((((a << 7) + (v & 0xFF)) - 1) * p[0x12C / 4] + b) - 1;
    *o2 = 1;
    p[0x1B0 / 4] = 1;
    s[5] = 0;
    s[4] = 0;
    s[1] = 0;
    s[0] = 0;
    s[7] = 0;
    s[6] = 0;
    s[3] = 0;
    s[2] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406318);
#ifdef SKIP_ASM
extern char D_00497F70[];
extern int _sliceA0(int *, int, int *, int *, int *);
extern int func_00405B70(int *);
extern int func_004070F0(int, int);
extern int func_00405FB8(int *);
extern void func_004034A8(int *, int);
extern int func_004065D0(int *, int *, int *, int *, int *, int *, int *);
extern int func_00406510(int *, int *, int *, int *, int *);
extern int func_00403E00_k() __asm__("func_00403E00");
extern void func_00404B78(int *, int);
int func_00406318(int *p, int n) {
    int a;
    int b;
    int c;
    int d;
    int e;
    int s[8];
    int q[4];
    int r[4];
    int v;
    a = 0;
    b = 0;
    v = _sliceA0(p, n, &a, &b, s);
    if (v != 0)
        return v;
    p[0x11C / 4] = 0;
    for (;;) {
        if (a >= n)
            return 0;
        p[(0x6CC + p[0x810 / 4] * 0x140) / 4] = 0;
        if (func_00405B70(p) == 0) {
            if (p[0x10A0 / 4] != 0) {
                p[0x10A0 / 4] = 0;
                return 4;
            }
            return 2;
        }
        if (b == 0) {
            if (func_004070F0((int)p, 0x17) == 0) {
                p[0x11C / 4] = 0;
                return 3;
            }
            if (p[0x11C / 4] != 0) {
                p[0x11C / 4] = 0;
                return 3;
            }
            b = func_00405FB8(p);
            if (p[0x11C / 4] != 0) {
                p[0x11C / 4] = 0;
                return 1;
            }
        }
        if (a >= n) {
            func_004034A8(p, (int)D_00497F70);
            return 2;
        }
        if (b == 1) {
            if (func_004065D0(p, &c, &d, &e, s, q, r) == 0) {
                p[0x11C / 4] = 0;
                return 1;
            }
        } else {
            if (func_00406510(p, s, &d, q, &c) == 0) {
                p[0x11C / 4] = 0;
                return 2;
            }
        }
        if (func_00403E00_k(p, a, b, c, d, s, q, r) == 0) {
            p[0x11C / 4] = 0;
            return 2;
        }
        if (a != 0)
            func_00404B78(p, p[0x810 / 4] ^ 1);
        a++;
        p[0x810 / 4] ^= 1;
        b--;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406510);
#ifdef SKIP_ASM
extern char D_00497F90[];
extern void func_004034A8(int *, int);
int func_00406510(int *p, int *q, int *r, int *s, int *t) {
    int ok = 1;
    int v;
    p[p[0x810 / 4] * 0x140 / 4 + 0x6CC / 4] = 1;
    p[0x1B0 / 4] = 1;
    if (p[0x150 / 4] == 2) {
        q[5] = 0;
        q[4] = 0;
        q[1] = 0;
        q[0] = 0;
    }
    if (p[0x174 / 4] == 3) {
        *r = 2;
    } else {
        *r = 1;
        v = p[0x174 / 4] == 2;
        s[1] = v;
        s[0] = v;
    }
    if (p[0x150 / 4] == 1) {
        func_004034A8(p, (int)D_00497F90);
        ok = 0;
    }
    *t &= ~1;
    return ok;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004065D0);

INCLUDE_ASM("seg/seg_2FE810", func_00406A78);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406B00);
#ifdef SKIP_ASM
extern int Q_72E8(int, int) __asm__("func_004072E8");
extern void Q_6CA0(int, int *, int *, int, int, int, int, int) __asm__("func_00406CA0");
void func_00406B00(int p, int *x, int *out, int *t, int idx, int m, int k, int n0, int n1, int f1, int f2) {
    int v;
    int *q;
    if (m == 1) {
        if (k == 0 && f1 == 0) {
            v = Q_72E8(p, 1);
            t[idx] = v;
            t[idx + 2] = v;
        }
        q = &x[idx * 2];
        Q_6CA0(p, q, out, n0, n1, f1, f2, 0);
        q[4] = q[0];
        q[5] = q[1];
    } else {
        t[idx] = Q_72E8(p, 1);
        Q_6CA0(p, &x[idx * 2], out, n0, n1, f1, f2, 0);
        t[idx + 2] = Q_72E8(p, 1);
        Q_6CA0(p, &x[idx * 2 + 4], out, n0, n1, f1, f2, 0);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406CA0);
#ifdef SKIP_ASM
extern int func_00406F78();
extern int func_004072E8();
extern int func_00405E10();
extern void func_00406A78();
void func_00406CA0(int p, int *x, int *out, int n0, int n1, int f1, int f2, int z) {
    int h;
    int v;
    h = func_00406F78(p, 2);
    if (n0 != 0 && h != 0)
        v = func_004072E8(p, n0);
    else
        v = 0;
    func_00406A78(x, n0, h, v, z);
    if (f1 != 0)
        out[0] = func_00405E10(p);
    h = func_00406F78(p, 2);
    if (n1 != 0 && h != 0)
        v = func_004072E8(p, n1);
    else
        v = 0;
    if (f2 != 0)
        x[1] = x[1] >> 1;
    func_00406A78(x + 1, n1, h, v, z);
    if (f2 != 0)
        x[1] = x[1] * 2;
    if (f1 != 0)
        out[1] = func_00405E10(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406DF0);
#ifdef SKIP_ASM
extern int D_004532C0[];
void func_00406DF0(int *p, unsigned a) {
    volatile int *r = (volatile int *)0x10002000;
    *r = a;
    p[518] = D_004532C0[a >> 28];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406E20);
#ifdef SKIP_ASM
extern int func_00402C80(int *);
void func_00406E20(int p) {
    int n = 0;
    if ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000) {
        do {
            if (n++ >= 0x1389) {
                func_00402C80(*(int **)(p + 0x858));
                n = 0;
            }
        } while ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406EC8);
#ifdef SKIP_ASM
extern int func_00402C80(int *);
long func_00406EC8(int p) {
    int n = 0;
    long v = *(volatile long *)0x10002000;
    if (v < 0 && !(*(volatile unsigned *)0x10002010 & 0x4000)) {
        do {
            if (n++ >= 0x1389) {
                func_00402C80(*(int **)(p + 0x858));
                n = 0;
            }
            v = *(volatile long *)0x10002000;
        } while (v < 0 && !(*(volatile unsigned *)0x10002010 & 0x4000));
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00406F78);
#ifdef SKIP_ASM
extern int D_004532C0[];
extern int func_00402C80(int *);
int func_00406F78(int p, int cmd) {
    int m = 0;
    int n = 0;
    int w;
    long v;
    long b;
    int s;
    if ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000) {
        do {
            if (n++ >= 0x1389) {
                func_00402C80(*(int **)(p + 0x858));
                n = 0;
            }
        } while ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000);
    }
    w = (cmd << 26) | 0x30000000;
    *(volatile int *)0x10002000 = w;
    *(int *)(p + 0x818) = D_004532C0[w >> 28];
    v = *(volatile long *)0x10002000;
    if (v < 0) {
        do {
            if (m++ >= 0x1389) {
                func_00402C80(*(int **)(p + 0x858));
                m = 0;
            }
            v = *(volatile long *)0x10002000;
        } while (v < 0);
    }
    s = *(volatile int *)0x10002020;
    b = *(long *)0x10002030;
    *(int *)(p + 0x838) = (int)b;
    if (b < 0)
        *(int *)(p + 0x83C) = -(s & 0x1F) & 0x1F;
    else
        *(int *)(p + 0x83C) = 32;
    *(int *)(p + 0x11C) = (int)v == 0;
    return (short)v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004070F0);
#ifdef SKIP_ASM
extern int D_004532C0[];
extern int func_00402C80(int *);
extern long func_00406EC8_k() __asm__("func_00406EC8");
int func_004070F0(int p, int n) {
    int c;
    int x;
    int *e;
    if (*(int *)(p + 0x818) || *(int *)(p + 0x83C) < n) {
        c = 0;
        if ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000) {
            do {
                if (c++ >= 0x1389) {
                    func_00402C80(*(int **)(p + 0x858));
                    c = 0;
                }
            } while ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000);
        }
        *(volatile int *)0x10002000 = 0x40000000;
        *(int *)(p + 0x818) = D_004532C0[4];
        x = (int)func_00406EC8_k(p);
        *(int *)(p + 0x838) = x;
        *(int *)(p + 0x83C) = 32;
    }
    return (unsigned)*(int *)(p + 0x838) >> (32 - n);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004071F8);
#ifdef SKIP_ASM
extern int D_004532C0[];
extern int func_00402C80(int *);
extern long func_00406EC8_k() __asm__("func_00406EC8");
void func_004071F8(int p, int v) {
    int n = 0;
    int w;
    int x;
    int *e;
    if ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000) {
        do {
            if (n++ >= 0x1389) {
                func_00402C80(*(int **)(p + 0x858));
                n = 0;
            }
        } while ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000);
    }
    w = v | 0x40000000;
    *(volatile int *)0x10002000 = w;
    e = &D_004532C0[(unsigned)w >> 28];
    *(int *)(p + 0x818) = *e;
    x = (int)func_00406EC8_k(p, e);
    *(int *)(p + 0x838) = x;
    *(int *)(p + 0x83C) = 32;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004072E8);
#ifdef SKIP_ASM
extern int D_004532C0[];
extern int func_00402C80(int *);
extern long func_00406EC8_k() __asm__("func_00406EC8");
int func_004072E8(int p, int n) {
    int c = 0;
    int w;
    unsigned r;
    int x;
    int *e;
    if ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000) {
        do {
            if (c++ >= 0x1389) {
                func_00402C80(*(int **)(p + 0x858));
                c = 0;
            }
        } while ((*(volatile int *)0x10002010 & 0x80004000) == 0x80000000);
    }
    if (*(int *)(p + 0x818) || *(int *)(p + 0x83C) < n) {
        *(volatile int *)0x10002000 = 0x40000000;
        *(int *)(p + 0x818) = D_004532C0[4];
        x = (int)func_00406EC8_k(p);
        *(int *)(p + 0x838) = x;
    }
    r = (unsigned)*(int *)(p + 0x838) >> (32 - n);
    *(int *)(p + 0x83C) = 32;
    w = n | 0x40000000;
    *(volatile int *)0x10002000 = w;
    e = &D_004532C0[(unsigned)w >> 28];
    *(int *)(p + 0x818) = *e;
    x = (int)func_00406EC8_k(p);
    *(int *)(p + 0x838) = x;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407438);
#ifdef SKIP_ASM
extern void func_004071F8(int, int);
extern int func_004070F0(int, int);
extern void func_00406E20(int);
void func_00407438(int p) {
    int n;
    func_00406E20(p);
    n = -(*(volatile int *)0x10002020 & 7) & 7;
    if (n)
        func_004071F8(p, n);
    while (func_004070F0(p, 0x18) != 1)
        func_004071F8(p, 8);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004074B8);
#ifdef SKIP_ASM
extern void func_004071F8(int, int);
extern int func_004072E8(int, int);
extern void func_00407A10(int);
int func_004074B8(int *p) {
    p[109] = func_004072E8((int)p, 5);
    if (func_004072E8((int)p, 1)) {
        func_004072E8((int)p, 1);
        func_004071F8((int)p, 7);
        func_00407A10((int)p);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407520);
#ifdef SKIP_ASM
struct B7520 { int op; long l1; long l2; };
struct S_7520 { char pad[0x150]; int f150; char pad2[0x6D4]; long f828; long f830; char pad3[0x20]; int f858; };
extern void s7_7438(struct S_7520 *) __asm__("func_00407438");
extern int s7_72E8(struct S_7520 *, int) __asm__("func_004072E8");
extern void s7_3620(struct S_7520 *) __asm__("func_00403620");
extern void s7_7AD0(struct S_7520 *) __asm__("func_00407AD0");
extern void s7_7630(struct S_7520 *) __asm__("func_00407630");
extern void s7_2C30(int, struct B7520 *) __asm__("func_00402C30");
int func_00407520(struct S_7520 *a) {
    struct B7520 b;
    for (;;) {
        s7_7438(a);
        switch ((unsigned)s7_72E8(a, 0x20)) {
        case 0x1B3:
            s7_3620(a);
            break;
        case 0x1B8:
            s7_7AD0(a);
            break;
        case 0x1B7:
            return 0;
        case 0x100:
            s7_7630(a);
            b.op = 5;
            b.l1 = -1;
            b.l2 = -1;
            s7_2C30(a->f858, &b);
            a->f830 = b.l2;
            a->f828 = b.l1;
            return a->f150;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407630);
#ifdef SKIP_ASM
extern int func_004072E8(int, int);
extern void func_00407A10(int);
extern void func_004076F8(int);
extern void func_00407A58(int, int);
void func_00407630(int *p) {
    int v = func_004072E8((int)p, 10);
    p[0x150 / 4] = func_004072E8((int)p, 3);
    func_004072E8((int)p, 16);
    if ((unsigned)(p[0x150 / 4] - 2) < 2) {
        p[0x154 / 4] = func_004072E8((int)p, 1);
        p[0x158 / 4] = func_004072E8((int)p, 3);
    }
    if (p[0x150 / 4] == 3) {
        p[0x15C / 4] = func_004072E8((int)p, 1);
        p[0x160 / 4] = func_004072E8((int)p, 3);
    }
    func_00407A10((int)p);
    func_004076F8((int)p);
    func_00407A58((int)p, v);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004076F8);
#ifdef SKIP_ASM
struct PT44 { int v[11]; };
extern char D_00497FE0[];
extern int func_004070F0(int, int);
extern void func_004071F8(int, int);
extern int func_004072E8();
void func_004076F8(int p) {
    struct PT44 t = *(struct PT44 *)D_00497FE0;
    unsigned i;
    int r;
    func_00407438(p);
    while ((r = func_004070F0(p, 32)) == 0x1B5 || r == 0x1B2) {
        if (r == 0x1B5) {
            func_004071F8(p, 32);
            i = func_004072E8(p, 4);
            i = i > 10 ? 0 : i;
            ((void (*)(int))t.v[i])(p);
            func_00407438(p);
        } else {
            func_004071F8(p, 32);
            func_00407438(p);
        }
    }
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00407820);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407A10);
#ifdef SKIP_ASM
extern void func_004071F8(int, int);
extern int func_004072E8(int, int);
void func_00407A10(int p) {
    while (func_004072E8(p, 1))
        func_004071F8(p, 8);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407A58);
#ifdef SKIP_ASM
struct S407A58 { char p0[0x150]; int f150; char p1[0x58]; int f1AC; char p2[0x69C]; int f84C; int f850; int f854; };
int f_407A58(struct S407A58 *p, int n) __asm__("func_00407A58");
int f_407A58(struct S407A58 *p, int n) {
    int t = 0;
    int m = 0;
    int x;
    if (p->f150 != 3) {
        if (n != 0) {
            if (n < 0)
                t = p->f854 == 0;
            p->f854 = 0;
            m = n;
        }
    }
    p->f1AC = p->f84C + n;
    if (t && m >= n)
        p->f1AC += 0x400;
    x = p->f850;
    if (x < p->f1AC)
        x = p->f1AC;
    p->f850 = x;
    return x;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407AD0);
#ifdef SKIP_ASM
extern int func_004072E8(int, int);
extern void func_004076F8();
void func_00407AD0(int *p) {
    p[0xE8 / 4] = 0;
    p[0x84C / 4] = p[0x850 / 4] + 1;
    p[0x854 / 4] = 1;
    func_004072E8((int)p, 1);
    func_004072E8((int)p, 5);
    func_004072E8((int)p, 6);
    func_004072E8((int)p, 1);
    func_004072E8((int)p, 6);
    func_004072E8((int)p, 6);
    p[0x1A4 / 4] = func_004072E8((int)p, 1);
    p[0x1A8 / 4] = func_004072E8((int)p, 1);
    func_004076F8(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407B70);
#ifdef SKIP_ASM
extern int func_004072E8(int, int);
extern void func_00406E20(int);
extern void func_004034A8(int *, int);
extern char D_00498010[];
extern char D_00498038[];
void func_00407B70(int *p) {
    if ((p[0x840 / 4] = func_004072E8((int)p, 1)) != 0) {
        func_00406E20((int)p);
        func_00406DF0(p, 0x50000000);
        func_00406E20((int)p);
    }
    if ((p[0x844 / 4] = func_004072E8((int)p, 1)) != 0) {
        func_00406E20((int)p);
        func_00406DF0(p, 0x58000000);
        func_00406E20((int)p);
    }
    if (func_004072E8((int)p, 1) != 0)
        func_004034A8(p, (int)D_00498010);
    if (func_004072E8((int)p, 1) != 0)
        func_004034A8(p, (int)D_00498038);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407C38);
#ifdef SKIP_ASM
struct S_7C38 { char pad[0x13C]; int f13C; char pad2[0x34]; int f174; int f178; char pad3[8]; int f184; int pad188; int f18C[3]; int f198[3]; };
extern int sc_72E8(struct S_7C38 *, int) __asm__("func_004072E8");
void func_00407C38(struct S_7C38 *a) {
    int n;
    int i;
    if (a->f13C) {
        if (a->f184 == 0) n = 1;
        else n = a->f178 ? 3 : 2;
    } else {
        if (a->f174 != 3) n = 1;
        else n = a->f184 ? 3 : 2;
    }
    for (i = 0; i < n; i++) {
        a->f18C[i] = sc_72E8(a, 16);
        sc_72E8(a, 1);
        a->f198[i] = sc_72E8(a, 16);
        sc_72E8(a, 1);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407D30);
#ifdef SKIP_ASM
extern int func_004072E8(int, int);
void func_00407D30(int p) {
    func_004072E8(p, 1);
    func_004072E8(p, 8);
    func_004072E8(p, 1);
    func_004072E8(p, 7);
    func_004072E8(p, 1);
    func_004072E8(p, 0x14);
    func_004072E8(p, 1);
    func_004072E8(p, 0x16);
    func_004072E8(p, 1);
    func_004072E8(p, 0x16);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407DC0);
#ifdef SKIP_ASM
extern char D_00498068[];
extern char D_00498088[];
extern void func_004034A8();
extern int func_004060C8(int *);
int func_00407DC0(int *p) {
    int *q;
    int r;
    if (p[0x174 / 4] == 3 && p[0x120 / 4] != 0) {
        func_004034A8(p, D_00498068);
        p[0x120 / 4] = 0;
    }
    switch (p[0x174 / 4]) {
    case 3:
        q = (int *)p[0x1C0 / 4];
        break;
    case 1:
        q = (int *)p[0x1D0 / 4];
        break;
    case 2:
        q = (int *)p[0x1E0 / 4];
        break;
    default:
        q = (int *)p[0x1C0 / 4];
        func_004034A8(p, D_00498088);
        break;
    }
    r = func_004060C8(p);
    if (r != 0)
        q[0x28 / 4] = 1;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00407E90);
#ifdef SKIP_ASM
extern void func_004086C0(int *, int, int);
extern void func_004087D0(int *, int, int, int);
void func_00407E90(int *p, int n, int flag) {
    int a, b;
    if (flag) {
        if (p[0x174 / 4] == 3) {
            if (p[0x150 / 4] == 3)
                a = p[0x1C4 / 4];
            else
                a = p[0x1B8 / 4];
            func_004086C0(p, a, n - 1);
        } else {
            if (p[0x150 / 4] == 3) {
                a = p[0x1D4 / 4];
                b = p[0x1E4 / 4];
            } else {
                a = p[0x1C8 / 4];
                b = p[0x1D8 / 4];
            }
            func_004087D0(p, a, b, n - 1);
        }
    }
    if (p[0xF8 / 4] == 1)
        p[0xF8 / 4] = 2;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00407F20);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004081D8);
#ifdef SKIP_ASM
extern int sprintf(char *, const char *, ...);
extern void func_004034A8(int *, int);
extern char D_004980A8[];
int func_004081D8(int *p, int *q) {
    char buf[256];
    int r;
    int n = p[0xE0 / 4];
    if (n != 0)
        r = p[0xDC / 4] >= q[1] && n >= q[2];
    else
        r = p[0xE4 / 4] >= q[3] * q[4];
    if (r == 0) {
        sprintf(buf, D_004980A8, q[1], q[2]);
        func_004034A8(p, (int)buf);
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00408278);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00408508);
#ifdef SKIP_ASM
void func_00408508(int *p) {
    if (p[2] != 2) {
        p[2] = 2;
        p[43] = p[70];
    }
    p[520] = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00408530);
#ifdef SKIP_ASM
// func_00408530 97.98 (sweep: schedule). IPU/MPEG picture-timestamp routine: a=decoder state, b=picture header, o1/o2/o3 -> r->f10/f18/f20 in caller func_004086C0. func_004114D0=__muldi3 (long*long). Only diff: 'move $4,$18' (4th muldi3 arg) placed before dsra32 in ours, after it in target. Tried named locals, bitfield union, w/z temps, sweep 716 variants, permuter 4min. Chain order f34|f38|f3c|f40|f30|f2c found by permutation search.
struct S85 { char pad0[0x70]; int f70; int pad74; long f78; int f80; int pad84; long f88; int f90; char pad94[0x5C]; long fF0; int fF8; };
struct B85 { char pad0[0x18]; long f18; long f20; int pad28; int f2c; int f30; int f34; int f38; int f3c; int f40; };
extern long mul85(long, long) __asm__("func_004114D0");
long func_00408530(struct S85 *a, struct B85 *b, long *o1, long *o2, long *o3) {
    long r;
    long v;
    int x;
    int e;
    int s;
    if (a->f70 != 0) {
        v = b->f18;
        if (v >= 0) {
            *o1 = v;
        } else {
            s = a->f80;
            if (s < 0) {
                *o1 = v;
            } else {
                long t;
                int y;
                x = a->f88;

                t = mul85(x & 1, a->f78 & 1);
                e = a->f90;
                y = mul85(t, e & 1);
                *o1 = s + ((int)(mul85(a->f78, x) >> 1) + y);
                if (mul85(x & 1, a->f78 & 1))
                    a->f90 = e + 1;
            }
        }
    } else {
        *o1 = b->f18;
    }
    if (a->fF8 == 2 && a->fF0 >= 0) {
        *o1 = a->fF0;
        a->fF8 = 0;
        a->fF0 = -1;
    }
    *o2 = b->f20;
    r = (long)b->f34 << 8 | (long)b->f38 << 7 | (long)b->f3c << 6 | (long)b->f40 << 5 | (long)b->f30 << 3 | (long)b->f2c;
    *o3 = r;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004086C0);
#ifdef SKIP_ASM
struct S86C0 { char pad0[0x80]; int f80; int pad84; unsigned long f88; char pad90[0x20]; int fB0; int fB4; int fB8; int fBC; int fC0; int fC4; int fC8; int fCC; int fD0; char padD4[0x784]; int f858; };
struct B86C0 { char pad0[0x28]; int f28; char pad2C[0x18]; int f44; int f48; int f4C; int f50; int f54; int f58; int f5C; int f60; };
struct R86C0 { char pad[0x10]; int f10; int f14; int f18; int f1C; long f20; };
extern unsigned D_004532E8[];
extern void q86_8530(struct S86C0 *, struct B86C0 *, void *, void *, void *) __asm__("func_00408530");
extern int q86_81D8(struct S86C0 *, struct B86C0 *) __asm__("func_004081D8");
extern int q86_9088(struct S86C0 *, struct B86C0 *) __asm__("func_00409088");
extern int q86_8278(struct S86C0 *, struct B86C0 *) __asm__("func_00408278");
extern void q86_8508(struct S86C0 *) __asm__("func_00408508");
void d86C0(struct S86C0 *a, struct B86C0 *b, int c) __asm__("func_004086C0");
void d86C0(struct S86C0 *a, struct B86C0 *b, int c) {
    struct R86C0 *r = (struct R86C0 *)a->f858;
    int m;
    q86_8530(a, b, &r->f10, &r->f18, &r->f20);
    r = (struct R86C0 *)a->f858;
    a->f80 = r->f10;
    m = r->f20 >> 5;
    a->f88 = D_004532E8[m & 0xF];
    a->fCC = b->f5C;
    a->fD0 = b->f60;
    a->fB4 = b->f44;
    a->fB8 = b->f48;
    a->fBC = b->f4C;
    a->fC0 = b->f50;
    a->fC4 = b->f54;
    a->fC8 = b->f58;
    if (q86_81D8(a, b) && b->f28 == 1) {
        if (a->fB0 != 0) q86_9088(a, b);
        else q86_8278(a, b);
        q86_8508(a);
    }
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_004087D0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00408988);
#ifdef SKIP_ASM
struct Ent_8988 { int f0; int f4; unsigned a[4]; unsigned b[69]; int cnt; int pad[4]; };
struct P_8988 { char pad[0x590]; struct Ent_8988 e[2]; int idx; };
extern char q8988_D[] __asm__("D_00526FC0");
extern int q8988_C078() __asm__("func_0042C078");
extern void q8988_C0C0(void) __asm__("func_0042C0C0");
void q8988(struct P_8988 *p) __asm__("func_00408988");
void q8988(struct P_8988 *p) {
    int i = 0;
    unsigned long long *t = (unsigned long long *)(((unsigned)q8988_D & 0x0FFFFFFF) | 0x20000000);
    int n = p->e[p->idx].cnt;
    int s;
    if (n > 0) {
        do {
            unsigned a = p->e[p->idx].a[i] & 0x0FFFFFFF;
            unsigned b = p->e[p->idx].b[i] & 0x0FFFFFFF;
            int last = (i == n - 1) ? 0 : 3;
            i++;
            t[0] = ((unsigned long long)a << 32) | 0x30000030;
            t[2] = ((unsigned long long)b << 32) | ((unsigned long long)last << 28) | 0x30;
            t += 4;
        } while (i < n);
    }
    s = q8988_C078();
    __asm__ volatile("sync");
    *(volatile int *)0x1000D480 = p->e[p->idx].f0;
    *(volatile int *)0x1000D430 = (int)q8988_D;
    *(volatile int *)0x1000D420 = 0;
    *(volatile int *)0x1000D400 = 0x105;
    if (s)
        q8988_C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00408AF8);
#ifdef SKIP_ASM
extern int func_0042C078();
extern void func_0042C0C0(void);
void func_00408AF8(unsigned a, int b) {
    int s = func_0042C078();
    *(volatile unsigned *)0x1000B010 = (a & 0xFFFFFFF) | 0x80000000;
    *(volatile int *)0x1000B020 = b >> 4;
    *(volatile int *)0x1000B000 = 0x100;
    if (s)
        func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00408B80);
#ifdef SKIP_ASM
extern int q8B80_C078() __asm__("func_0042C078");
extern void q8B80_C0C0(void) __asm__("func_0042C0C0");
extern void q8B80_6DF0(int *, int) __asm__("func_00406DF0");
extern int q8B80_2C30(int *, int *) __asm__("func_00402C30");
void q8B80(int *p, unsigned addr, int n) __asm__("func_00408B80");
void q8B80(int *p, unsigned addr, int n) {
    int s;
    int sp[8];
    while (*(volatile int *)0x10002010 < 0)
        ;
    s = q8B80_C078();
    *(volatile int *)0x1000B010 = addr & 0x0FFFFFFF;
    *(volatile int *)0x1000B020 = n << 6;
    *(volatile int *)0x1000B000 = 0x100;
    if (s)
        q8B80_C0C0();
    q8B80_6DF0(p, n | 0x70000000);
    sp[0] = 4;
    q8B80_2C30(*(int **)((char *)p + 0x858), sp);
    while (((*(volatile unsigned *)0x1000B000 >> 8) & 1))
        ;
    while (*(volatile int *)0x10002010 < 0)
        ;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_00408CA8);

INCLUDE_ASM("seg/seg_2FE810", func_00408DF0);

INCLUDE_ASM("seg/seg_2FE810", func_00408FB0);

INCLUDE_ASM("seg/seg_2FE810", func_00409088);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409310);
#ifdef SKIP_ASM
extern int func_0042C078();
extern void func_0042C0C0(void);
void func_00409310(int a) {
    int s = func_0042C078();
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B000 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    if (s)
        func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409388);
#ifdef SKIP_ASM
extern int func_0042C078();
extern void func_0042C0C0(void);
void func_00409388(int a) {
    int s = func_0042C078();
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B400 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    if (s)
        func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409400);
#ifdef SKIP_ASM
extern void q9400_9388(int) __asm__("func_00409388");
extern void q9400_9310(int) __asm__("func_00409310");
void q9400(int *p) __asm__("func_00409400");
void q9400(int *p) {
    q9400_9388(1);
    p[0] = *(volatile int *)0x1000B410;
    p[1] = *(volatile int *)0x1000B430;
    p[2] = *(volatile int *)0x1000B420;
    p[3] = *(volatile int *)0x1000B400;
    while (*(volatile int *)0x10002010 & 0xF0)
        ;
    q9400_9310(0);
    p[4] = *(volatile int *)0x1000B010;
    p[5] = *(volatile int *)0x1000B020;
    p[6] = *(volatile int *)0x1000B000;
    p[7] = *(volatile int *)0x10002020;
    p[8] = *(volatile int *)0x10002010;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004094E8);
#ifdef SKIP_ASM
extern void q94E8_9388(int) __asm__("func_00409388");
extern void q94E8_9310(int) __asm__("func_00409310");
void q94E8(int *p) __asm__("func_004094E8");
void q94E8(int *p) {
    unsigned v = p[7];
    int e = v & 0x7F;
    int n = ((v >> 16) & 3) + ((v >> 8) & 0xF);
    int r = p[0] - (n << 4);
    int q = p[2] + n;
    if (p[4] != 0 && p[5] != 0) {
        *(volatile int *)0x1000B010 = p[4];
        *(volatile int *)0x1000B020 = p[5];
        q94E8_9310(p[6] | 0x100);
    }
    while (*(volatile int *)0x10002010 < 0)
        ;
    *(volatile int *)0x10002000 = e;
    while (*(volatile int *)0x10002010 < 0)
        ;
    if (r != 0 && q != 0) {
        *(volatile int *)0x1000B410 = r;
        *(volatile int *)0x1000B430 = p[1];
        *(volatile int *)0x1000B420 = q;
        q94E8_9388(p[3] | 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409638);
#ifdef SKIP_ASM
int func_00409638(int a) {
    int r = 0;
    int v;
    switch (a) {
    case 0:
        do {
            v = *(volatile int *)0x10002010;
            __asm__ volatile("nop");
        } while (v < 0);
        r = 0;
        break;
    case 1:
        r = *(volatile unsigned *)0x10002010 >> 31;
        break;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_004096A0);
#ifdef SKIP_ASM
extern int func_0042C078(int);
extern void func_0042C0C0(void);
void func_004096A0(int a) {
    func_0042C078(a);
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B400 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    func_0042C0C0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409708);
#ifdef SKIP_ASM
typedef int i128_9708 __attribute__((mode(TI)));
extern volatile i128_9708 D_00453340[];
extern i128_9708 D_00453390[];
extern void func_004096A0(int);
#define WAIT_9708() while (*(volatile int *)0x10002010 < 0)
void func_00409708(void) {
    func_004096A0(1);
    *(volatile int *)0x10002010 = 0x40000000;
    WAIT_9708();
    *(volatile int *)0x10002000 = 0;
    WAIT_9708();
    *(volatile i128_9708 *)0x10007010 = D_00453340[0];
    *(volatile i128_9708 *)0x10007010 = D_00453340[1];
    *(volatile i128_9708 *)0x10007010 = D_00453340[2];
    *(volatile i128_9708 *)0x10007010 = D_00453340[3];
    *(volatile i128_9708 *)0x10007010 = D_00453340[4];
    *(volatile i128_9708 *)0x10007010 = D_00453340[4];
    *(volatile i128_9708 *)0x10007010 = D_00453340[4];
    *(volatile i128_9708 *)0x10007010 = D_00453340[4];
    *(volatile int *)0x10002000 = 0x50000000;
    WAIT_9708();
    *(volatile int *)0x10002000 = 0x58000000;
    WAIT_9708();
    *(volatile i128_9708 *)0x10007010 = D_00453390[0];
    *(volatile i128_9708 *)0x10007010 = D_00453390[1];
    *(volatile int *)0x10002000 = 0x60000000;
    WAIT_9708();
    *(volatile int *)0x10002000 = 0x90000000;
    WAIT_9708();
    *(volatile int *)0x10002010 = 0x40000000;
    WAIT_9708();
    *(volatile int *)0x10002000 = 0;
    WAIT_9708();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409940);
#ifdef SKIP_ASM
extern int Q_5271C0[] __asm__("D_005271C0");
extern int Q_527240[] __asm__("D_00527240");
extern int Q_528780[] __asm__("D_00528780");
extern int Q_4533C4[] __asm__("D_004533C4");
extern int Q_4533C8[] __asm__("D_004533C8");
extern char Q_4980F0[] __asm__("D_004980F0");
extern char Q_498108[] __asm__("D_00498108");
extern char Q_498130[] __asm__("D_00498130");
extern int Q_sema(int *) __asm__("func_00423DA0");
extern void Q_wait(int) __asm__("func_00423DE0");
extern void Q_sig(int) __asm__("func_00423DC0");
extern void Q_log(char *) __asm__("func_00425C60");
extern int Q_A360(int, int, int) __asm__("func_0040A360");
extern void Q_6408(int) __asm__("func_00426408");
extern int Q_6B48(int *, unsigned, int) __asm__("func_00426B48");
extern int Q_6D18(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
int func_00409940(void) {
    int s[6];
    int r;
    int i;
    if (Q_4533C4[0] < 0) {
        s[5] = 0;
        s[2] = 1;
        s[1] = 1;
        Q_4533C4[0] = Q_sema(s);
        s[1] = 1;
        s[2] = 0;
        s[5] = 0;
        Q_4533C8[0] = Q_sema(s);
    }
    Q_A360(0, 0, 0);
    Q_wait(Q_4533C4[0]);
    Q_6408(0);
    for (;;) {
        if (Q_6B48(Q_5271C0, 0x80000400, 0) < 0) {
            Q_log(Q_4980F0);
            for (;;)
                __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
        }
        if (Q_5271C0[9] != 0)
            break;
        i = 0x100000;
        do {
            i--;
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
            __asm__ volatile("nop");
        } while (i != 0);
    }
    r = Q_6D18(Q_5271C0, 0xFE, 0, Q_527240, 48, Q_528780, 12, 0, 0);
    Q_sig(Q_4533C4[0]);
    if (r < 0) {
        Q_5271C0[9] = 0;
        return r - 100;
    }
    if (Q_528780[1] < 0x20A) {
        Q_log(Q_498108);
        Q_5271C0[9] = 0;
        return -120;
    }
    if (Q_528780[2] < 0x20E) {
        Q_log(Q_498130);
        Q_5271C0[9] = 0;
        return -121;
    }
    return Q_528780[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409B10);
#ifdef SKIP_ASM
extern int D_004533C4[];
extern int D_004533C8[];
extern int func_00423DB0(int);
int func_00409B10(void) {
    if (D_004533C4[0] >= 0) {
        func_00423DB0(D_004533C4[0]);
        D_004533C4[0] = -1;
        func_00423DB0(D_004533C8[0]);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409B60);
#ifdef SKIP_ASM
extern int D_00528780[];
extern int D_004533C0[];
extern int D_004533C4[];
extern int D_005271C0[];
int *func_00409B60(int *a, int *b) {
    *a = (int)D_00528780;
    *b = (int)D_004533C0;
    D_00528780[15] = D_004533C4[0];
    return D_005271C0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409B90);
#ifdef SKIP_ASM
extern int D_005271C0[];
extern int D_00527240[];
extern int D_00528780[];
extern int D_004533C0[];
extern int D_004533C4[];
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_00409B90(int a) {
    int r;
    if (D_005271C0[9] == 0)
        return -100;
    if (func_00423DF0(D_004533C4[0]) < 0)
        return -200;
    D_00527240[5] = a;
    r = func_00426D18((char *)D_005271C0, 20, 1, D_00527240, 48, D_00528780, 4, 0, 0);
    if (r == 0)
        D_004533C0[0] = 20;
    else
        func_00423DC0(D_004533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409C48);
#ifdef SKIP_ASM
extern int D_005271C0[];
extern int D_00527240[];
extern int D_00528780[];
extern int D_004533C4[];
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_00409C48(int a) {
    int r;
    if (D_005271C0[9] == 0)
        return -100;
    if (func_00423DF0(D_004533C4[0]) < 0)
        return -200;
    D_00527240[1] = a;
    r = func_00426D18((char *)D_005271C0, 21, 0, D_00527240, 48, D_00528780, 4, 0, 0);
    if (r != 0) {
        func_00423DC0(D_004533C4[0]);
        return r;
    }
    func_00423DC0(D_004533C4[0]);
    return D_00528780[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409D10);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527270[] __asm__("D_00527270");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern char *strncpy(char *, const char *, int);
int func_00409D10(int a, int b, int s_, int c) {
    char *s = (char *)s_;
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    if (s == 0 || s[0] == 0) {
        func_00423DC0(A_4533C4[0]);
        return -210;
    }
    strncpy((char *)(A_527270 + 5), s, 0x3FF);
    A_527270[0] = a;
    A_527270[2] = c;
    A_527270[1] = b;
    ((char *)A_527270)[0x413] = 0;
    r = func_KbOpenA(A_5271C0, 2, 1, A_527270, 0x414, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 2;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409E38);
#ifdef SKIP_ASM
extern int func_00409D10(int, int, int, int);
extern int D_004533C0[];
int func_00409E38(int a, int b, int c) {
    int r = func_00409D10(a, b, c, 0x40);
    if (r == 0) {
        D_004533C0[0] = 0xB;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409E70);
#ifdef SKIP_ASM
extern int D_005271C0[];
extern int D_00527240[];
extern int D_00528780[];
extern int D_004533C0[];
extern int D_004533C4[];
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_00409E70(int a) {
    int r;
    if (D_005271C0[9] == 0)
        return -100;
    if (func_00423DF0(D_004533C4[0]) < 0)
        return -200;
    D_00527240[0] = a;
    r = func_00426D18((char *)D_005271C0, 3, 1, D_00527240, 48, D_00528780, 4, 0, 0);
    if (r == 0)
        D_004533C0[0] = 3;
    else
        func_00423DC0(D_004533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_00409F28);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527240[] __asm__("D_00527240");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
int func_00409F28(int a, int b, int c) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    A_527240[0] = a;
    A_527240[4] = b;
    A_527240[5] = c;
    r = func_KbOpenA(A_5271C0, 4, 1, A_527240, 48, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 4;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A000);
#ifdef SKIP_ASM
struct S0A000 { int n0; int n1; char *d0; char *d1; char b0[0x40]; char b1[0x40]; };
void func_0040A000(unsigned a) {
    struct S0A000 *s = (struct S0A000 *)(a | 0x20000000);
    char *d;
    int i;
    if (s->n0 != 0) {
        d = s->d0;
        for (i = 0; i < s->n0; i++)
            *d++ = s->b0[i];
    }
    if (s->n1 != 0) {
        d = s->d1;
        for (i = 0; i < s->n1; i++)
            *d++ = s->b1[i];
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A090);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527240[] __asm__("D_00527240");
extern int A_5276C0[] __asm__("D_005276C0");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenC(int *, int, int, int *, int, int *, int, void (*)(void), int *) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern void func_00426358(int, int);
extern void cb_A000(void) __asm__("func_0040A000");
int func_0040A090(int a, int b, int c) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    A_527240[0] = a;
    A_527240[7] = (int)A_5276C0;
    A_527240[6] = b;
    A_527240[3] = c;
    func_00426358(b, c);
    func_00426358((int)A_5276C0, 0xC0);
    r = func_KbOpenC(A_5271C0, 5, 1, A_527240, 48, A_528780, 4, cb_A000, A_5276C0);
    if (r == 0)
        A_4533C0[0] = 5;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040A1A8);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A320);
#ifdef SKIP_ASM
extern void func_00423DD0(int);
void func_0040A320(int a, int b, int c) {
    func_00423DD0(c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A328);
#ifdef SKIP_ASM
extern int D_004533C8[];
extern void func_0040A320(int, int, int);
extern void func_00423B20(int, void (*)(int, int, int), int);
extern void func_00423DE0(int);
void func_0040A328(unsigned short a) {
    func_00423B20(a, func_0040A320, D_004533C8[0]);
    func_00423DE0(D_004533C8[0]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A360);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int poll_F08(int *) __asm__("func_00426F08");
extern void func_00423DC0(int);
extern void sleep_A328(int) __asm__("func_0040A328");
int func_0040A360(int a, int *p, int *q) {
    int r;
    if (A_4533C0[0] == 0)
        return -1;
    r = poll_F08(A_5271C0);
    if (a == 0 && r != 0) {
        while (poll_F08(A_5271C0) != 0)
            sleep_A328(60);
        r = 0;
    }
    r = r == 0;
    if (p)
        *p = A_4533C0[0];
    if (r) {
        A_4533C0[0] = 0;
        if (q)
            *q = A_528780[0];
        func_00423DC0(A_4533C4[0]);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A440);
#ifdef SKIP_ASM
extern int *D_005271E8[];
extern int *D_005271EC[];
extern int *D_005271F0[];
void func_0040A440(unsigned a) {
    int *p = (int *)(a | 0x20000000);
    if (D_005271E8[0])
        *D_005271E8[0] = p[0];
    if (D_005271EC[0])
        *D_005271EC[0] = p[1];
    if (D_005271F0[0])
        *D_005271F0[0] = p[36];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A498);
#ifdef SKIP_ASM
extern int P498_5271C0[] __asm__("D_005271C0");
extern int P498_5271E8[] __asm__("D_005271E8");
extern int P498_5271EC[] __asm__("D_005271EC");
extern int P498_5271F0[] __asm__("D_005271F0");
extern int P498_527240[] __asm__("D_00527240");
extern int P498_5276C0[] __asm__("D_005276C0");
extern int P498_528780[] __asm__("D_00528780");
extern int P498_4533C0[] __asm__("D_004533C0");
extern int P498_4533C4[] __asm__("D_004533C4");
extern int func_KbOpen498(int *, int, int, int *, int, int *, int, void (*)(void), int *) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern void func_00426358(int, int);
extern void cb_498(void) __asm__("func_0040A440");
int func_0040A498(int a, int b, int c, int d, int e) {
    int r;
    if (P498_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(P498_4533C4[0]) < 0)
        return -200;
    P498_527240[1] = a;
    P498_527240[2] = b;
    P498_527240[7] = (int)P498_5276C0;
    if (c != 0)
        P498_527240[5] = 1;
    else
        P498_527240[5] = 0;
    if (d != 0)
        P498_527240[4] = 1;
    else
        P498_527240[4] = 0;
    if (e != 0)
        P498_527240[3] = 1;
    else
        P498_527240[3] = 0;
    P498_5271E8[0] = c;
    P498_5271EC[0] = d;
    P498_5271F0[0] = e;
    func_00426358((int)P498_5276C0, 0xC0);
    r = func_KbOpen498(P498_5271C0, 1, 1, P498_527240, 48, P498_528780, 4, cb_498, P498_5276C0);
    if (r == 0)
        P498_4533C0[0] = 1;
    else
        func_00423DC0(P498_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A618);
#ifdef SKIP_ASM
extern int D_00528780[];
extern void func_0040A618_log(char *) __asm__("func_00425C60");
extern int D_00527240[];
extern char D_00498158[];
int func_0040A618(void) {
    if (func_00426D18(D_005271C0, 53, 0, D_00527240, 48, D_00528780, 4, 0, 0)) {
        func_0040A618_log(D_00498158);
        return -1;
    }
    return D_00528780[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A688);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527270[] __asm__("D_00527270");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern char *strncpy(char *, const char *, int);
extern void func_00426358(int, int);
int func_0040A688(int a, int b, char *s, int c, int d, int e) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    if (s == 0 || s[0] == 0) {
        func_00423DC0(A_4533C4[0]);
        return -210;
    }
    A_527270[0] = a;
    A_527270[1] = b;
    A_527270[2] = c;
    A_527270[3] = d;
    A_527270[4] = e;
    strncpy((char *)(A_527270 + 5), s, 0x3FF);
    ((char *)A_527270)[0x413] = 0;
    if (d >= 0)
        func_00426358(e, d << 6);
    r = func_KbOpenA(A_5271C0, 13, 1, A_527270, 0x414, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 13;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A7D0);
#ifdef SKIP_ASM
extern char D_00527780[];
extern unsigned strlen(char *);
extern int func_0041605C(int, int, int);
void func_0040A7D0(char *dst) {
    char *src;
    int n;
    if (dst) {
        src = (char *)((unsigned)D_00527780 | 0x20000000);
        if (strlen(src) < 0x400)
            n = strlen(src);
        else
            n = 0x3FF;
        func_0041605C((int)dst, (unsigned)D_00527780 | 0x20000000, n);
        dst[n] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A858);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527270[] __asm__("D_00527270");
extern int A_527780[] __asm__("D_00527780");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenB(int *, int, int, int *, int, int *, int, void (*)(void), int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern char *strncpy(char *, const char *, int);
extern void func_00426358(int, int);
extern void cb_A7D0(void) __asm__("func_0040A7D0");
int func_0040A858(int a, int b, char *s, int u) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    if (s == 0 || s[0] == 0) {
        func_00423DC0(A_4533C4[0]);
        return -210;
    }
    A_527270[0] = a;
    A_527270[4] = (int)A_527780;
    A_527270[1] = b;
    strncpy((char *)(A_527270 + 5), s, 0x3FF);
    ((char *)A_527270)[0x413] = 0;
    func_00426358((int)A_527780, 0x400);
    r = func_KbOpenB(A_5271C0, 12, 1, A_527270, 0x414, A_528780, 4, cb_A7D0, u);
    if (r == 0)
        A_4533C0[0] = 12;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040A998);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527240[] __asm__("D_00527240");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
int func_0040A998(int a, int b) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    A_527240[1] = a;
    A_527240[2] = b;
    r = func_KbOpenA(A_5271C0, 16, 1, A_527240, 48, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 16;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040AA68);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527270[] __asm__("D_00527270");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern char *strncpy(char *, const char *, int);
int func_0040AA68(int a, int b, char *s) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    if (s == 0 || s[0] == 0) {
        func_00423DC0(A_4533C4[0]);
        return -210;
    }
    strncpy((char *)(A_527270 + 5), s, 0x3FF);
    A_527270[0] = a;
    A_527270[1] = b;
    ((char *)A_527270)[0x413] = 0;
    A_527270[2] = 0;
    r = func_KbOpenA(A_5271C0, 15, 1, A_527270, 0x414, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 15;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040AB80);
#ifdef SKIP_ASM
extern int D_005271C0[];
extern int D_00527240[];
extern int D_00528780[];
extern int D_004533C0[];
extern int D_004533C4[];
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern int func_00426D18(char *, int, int, int *, int, int *, int, int, int);
int func_0040AB80(int a) {
    int r;
    if (D_005271C0[9] == 0)
        return -100;
    if (func_00423DF0(D_004533C4[0]) < 0)
        return -200;
    D_00527240[0] = a;
    r = func_00426D18((char *)D_005271C0, 10, 1, D_00527240, 48, D_00528780, 4, 0, 0);
    if (r == 0)
        D_004533C0[0] = 10;
    else
        func_00423DC0(D_004533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040AC38);
#ifdef SKIP_ASM
struct S40_AC38 { char b[0x40]; };
extern int R_5271C0[] __asm__("D_005271C0");
extern int R_527270[] __asm__("D_00527270");
extern struct S40_AC38 R_527200 __asm__("D_00527200");
extern int R_528780[] __asm__("D_00528780");
extern int R_4533C0[] __asm__("D_004533C0");
extern int R_4533C4[] __asm__("D_004533C4");
extern int R_open(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int R_3DF0(int) __asm__("func_00423DF0");
extern void R_3DC0(int) __asm__("func_00423DC0");
extern void R_4020(int) __asm__("func_00424020");
extern char *strncpy(char *, const char *, int);
int func_0040AC38(int a, int b, char *s, struct S40_AC38 *c, int e) {
    int r;
    int *h = R_5271C0;
    if (h[9] == 0)
        return -100;
    if (R_3DF0(R_4533C4[0]) < 0)
        return -200;
    if (s == 0 || s[0] == 0) {
        R_3DC0(R_4533C4[0]);
        return -210;
    }
    e &= 7;
    R_527270[0] = a;
    R_527270[1] = b;
    R_527270[2] = e;
    R_527200 = *c;
    R_527270[4] = (int)&R_527200;
    strncpy((char *)(R_527270 + 5), s, 0x3FF);
    ((char *)R_527270)[0x413] = 0;
    R_4020(0);
    r = R_open(h, 14, 1, R_527270, 0x414, R_528780, 4, 0, 0);
    if (r == 0)
        R_4533C0[0] = 14;
    else
        R_3DC0(R_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040AE00);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527270[] __asm__("D_00527270");
extern char A_527220[] __asm__("D_00527220");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern char *strncpy(char *, const char *, int);
extern void func_00424020(int);
int func_0040AE00(int a, int b, char *s, char *t) {
    int r;
    char *p;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    if (s == 0 || s[0] == 0 || t == 0) {
        func_00423DC0(A_4533C4[0]);
        return -210;
    }
    A_527270[0] = a;
    A_527270[1] = b;
    A_527270[2] = 16;
    strncpy((char *)(A_527270 + 5), s, 0x3FF);
    ((char *)A_527270)[0x413] = 0;
    strncpy(A_527220, t, 0x20);
    p = A_527220 - 0x20;
    p[0x3F] = 0;
    A_527270[4] = (int)p;
    func_00424020(0);
    r = func_KbOpenA(A_5271C0, 14, 1, A_527270, 0x414, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 19;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040AF58);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527240[] __asm__("D_00527240");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
int func_0040AF58(int a, int b) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    A_527240[1] = a;
    A_527240[2] = b;
    r = func_KbOpenA(A_5271C0, 17, 1, A_527240, 48, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 17;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B028);
#ifdef SKIP_ASM
extern int A_5271C0[] __asm__("D_005271C0");
extern int A_527270[] __asm__("D_00527270");
extern int A_528780[] __asm__("D_00528780");
extern int A_4533C0[] __asm__("D_004533C0");
extern int A_4533C4[] __asm__("D_004533C4");
extern int func_KbOpenA(int *, int, int, int *, int, int *, int, int, int) __asm__("func_00426D18");
extern int func_00423DF0(int);
extern void func_00423DC0(int);
extern char *strncpy(char *, const char *, int);
int func_0040B028(int a, int b, char *s) {
    int r;
    if (A_5271C0[9] == 0)
        return -100;
    if (func_00423DF0(A_4533C4[0]) < 0)
        return -200;
    if (s == 0 || s[0] == 0) {
        func_00423DC0(A_4533C4[0]);
        return -210;
    }
    A_527270[0] = a;
    A_527270[1] = b;
    strncpy((char *)(A_527270 + 5), s, 0x3FF);
    ((char *)A_527270)[0x413] = 0;
    r = func_KbOpenA(A_5271C0, 18, 1, A_527270, 0x414, A_528780, 4, 0, 0);
    if (r == 0)
        A_4533C0[0] = 18;
    else
        func_00423DC0(A_4533C4[0]);
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040B130);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B1F8);
#ifdef SKIP_ASM
extern int D_004533E0[];
void func_0040B1F8(void) {
    D_004533E0[0] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B208);
#ifdef SKIP_ASM
struct E0B208 { char pad[0x10]; int f10; int f14; int f18; char pad2[0x24]; };
struct S0B208 { int f0; struct E0B208 *tab; int n; };
extern int func_0042C078_rq(void) __asm__("func_0042C078");
extern void func_0042C0C0(void);
struct E0B208 *f0B208(struct S0B208 *s) __asm__("func_0040B208");
struct E0B208 *f0B208(struct S0B208 *s) {
    struct E0B208 *e;
    int i;
    int n;
    int c;
    int id;
    int seq;
    func_0042C078_rq();
    n = s->n;
    i = 0;
    e = s->tab;
    while (i < n) {
        if (!(e->f10 & 1)) {
            e->f10 = (i << 16) | 5;
            c = s->f0;
            id = c + 1;
            s->f0 = id;
            if (id == 1) {
                s->f0 = c + 2;
                seq = 1;
            } else {
                seq = id;
            }
            id = seq;
            e->f14 = (int)e;
            e->f18 = id;
            func_0042C0C0();
            return e;
        }
        i++;
        e++;
    }
    func_0042C0C0();
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B2B0);
#ifdef SKIP_ASM
void func_0040B2B0(unsigned *p) {
    p[6] = 0;
    p[4] &= 0xFFFFFFFE;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B2D0);
#ifdef SKIP_ASM
struct C_B2D0 { unsigned *f0; int pad4; int f8; int pad[2]; int f14; int f18; void (*f1C)(int); int f20; int f24; int f28; int f2C; };
struct E_B2D0 { char pad[0x1C]; struct C_B2D0 *ctx; unsigned code; int f24; int f28; int f2C; };
extern void func_00423DD0(int);
extern void func_0040B2B0(unsigned *);
void func_0040B2D0(struct E_B2D0 *e) {
    struct C_B2D0 *c;
    switch (e->code) {
    case 0x8000001A:
        c = e->ctx;
        if (c->f1C)
            c->f1C(c->f20);
        func_00423DD0(c->f28);
        break;
    case 0x80000019:
        c = e->ctx;
        c->f24 = e->f24;
        c->f14 = e->f28;
        c->f18 = e->f2C;
        func_00423DD0(c->f28);
        break;
    case 0x8000001C:
        break;
    case 0x8000001D:
        c = e->ctx;
        c->f2C = e->f24;
        func_00423DD0(c->f28);
        break;
    }
    c = e->ctx;
    if (c->f8 >= 0)
        func_00423DD0(c->f8);
    func_0040B2B0(c->f0);
    c->f0 = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B3D8);
#ifdef SKIP_ASM
extern int func_0040B400(int, int, int, int, int, int);
int func_0040B3D8(int a, int b, int c) {
    return func_0040B400(a, b, c, 0x800, 0x2000, 0x20);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B400);
#ifdef SKIP_ASM
struct N_B400 { char pad0[0x14]; struct N_B400 *f14; int f18; struct C_B400 *f1C; int f20; int f24; int f28; int f2C; };
struct C_B400 { struct N_B400 *f0; int f4; int f8; int padC; int f10; char pad14[0x10]; int f24; int f28; int pad2C; int f30; int f34; int f38; };
extern int func_00423DA0(int *);
extern int fr_B400(int) __asm__("func_00423DB0");
extern void func_00423DE0(int);
extern void lg_B400(char *) __asm__("func_00425C60");
extern struct N_B400 *func_0040B208(char *);
extern void rl_B400(struct N_B400 *) __asm__("func_0040B2B0");
extern int func_004261B0(unsigned, struct N_B400 *, int, int, int, int);
extern char D_00498178[];
extern char D_00528FC0[];
int func_0040B400(int cc, int a, int flag, int d, int e, int f) {
    struct C_B400 *c = (struct C_B400 *)cc;
    int s[6];
    int h;
    struct N_B400 *n;
    if (flag != 0) {
        lg_B400(D_00498178);
        return -1;
    }
    s[5] = 0;
    s[2] = 1;
    s[1] = 1;
    c->f28 = func_00423DA0(s);
    if (c->f28 < 0)
        return -3;
    func_00423DE0(c->f28);
    c->f10 = a;
    c->f24 = 0;
    c->f30 = d;
    c->f34 = e;
    c->f38 = f;
    n = func_0040B208(D_00528FC0);
    if (n == 0) {
        fr_B400(c->f28);
        return -1;
    }
    c->f0 = n;
    c->f4 = n->f18;
    n->f20 = a;
    n->f24 = d;
    n->f28 = e;
    n->f2C = f;
    n->f14 = n;
    n->f1C = c;
    s[1] = 1;
    s[2] = 0;
    s[5] = 0;
    h = func_00423DA0(s);
    c->f8 = h;
    if (h < 0) {
        rl_B400(n);
        fr_B400(c->f28);
        return -3;
    }
    if (func_004261B0(0x80000019, n, 0x40, 0, 0, 0) == 0) {
        rl_B400(n);
        fr_B400(h);
        fr_B400(c->f28);
        return -2;
    }
    func_00423DE0(h);
    fr_B400(h);
    if (c->f24 == 0)
        fr_B400(c->f28);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040B5B0);

INCLUDE_ASM("seg/seg_2FE810", func_0040B6D0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B938);
#ifdef SKIP_ASM
extern char D_00453400[];
extern int func_00427D60(char *, int);
extern void func_004283A0(int, char *, int);
extern void func_00427FE8(int);
extern char D_00498220[];
int func_0040B938(void) {
    int h;
    if (D_00453400[0] == 0) {
        h = func_00427D60(D_00498220, 1);
        if (h >= 0) {
            func_004283A0(h, D_00453400, 14);
            func_00427FE8(h);
        }
    }
    return (int)D_00453400;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B9A8);
#ifdef SKIP_ASM
extern char D_00453400[];
extern int func_0040B938(void);
int func_0040B9A8(void) {
    if (D_00453400[0] == 0)
        func_0040B938();
    return D_00453400[4] == 0x54;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040B9E8);
#ifdef SKIP_ASM
extern unsigned char D_004533FC[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
int func_0040B9E8(void) {
    unsigned buf[1];
    int r;
    func_00423E50(buf);
    if (func_0040B9A8()) {
        r = D_004533FC[0];
    } else {
        func_00423E50(buf);
        if (((buf[0] >> 13) & 7) == 0)
            r = (buf[0] >> 4) & 1;
        else
            r = (buf[0] >> 16) & 0x1F;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040BA48);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BA68);
#ifdef SKIP_ASM
extern unsigned char D_004533FA[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
int func_0040BA68(void) {
    unsigned buf[1];
    if (func_0040B9A8())
        return D_004533FA[0];
    func_00423E50(buf);
    return (buf[0] >> 1) & 3;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BAA8);
#ifdef SKIP_ASM
extern unsigned char D_004533FD[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
int func_0040BAA8(void) {
    unsigned buf[1];
    if (func_0040B9A8())
        return D_004533FD[0];
    func_00423E50(buf);
    return buf[0] & 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BAE8);
#ifdef SKIP_ASM
extern short D_004533F8_s[] __asm__("D_004533F8");
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
int func_0040BAE8(void) {
    unsigned buf[1];
    int r;
    if (func_0040B9A8()) {
        r = D_004533F8_s[0];
    } else {
        func_00423E50(buf);
        if (((buf[0] >> 13) & 7) == 0) r = 0x21C; else r = (int)buf[0] >> 21;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BB38);
#ifdef SKIP_ASM
extern unsigned char D_004533FB[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
extern int func_004240B0(unsigned *, int, int);
int func_0040BB38(void) {
    unsigned buf[2];
    unsigned char v;
    int r;
    if (func_0040B9A8()) {
        r = D_004533FB[0];
    } else {
        func_00423E50(buf);
        if (((buf[0] >> 13) & 7) == 0) {
            r = 0;
        } else {
            func_004240B0(&buf[1], 1, 1);
            v = ((unsigned char *)buf)[4];
            r = v >> 6;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BBA0);
#ifdef SKIP_ASM
extern unsigned char D_004533FE[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
extern int func_004240B0(unsigned *, int, int);
int func_0040BBA0(void) {
    unsigned buf[2];
    unsigned char v;
    int r;
    if (func_0040B9A8()) {
        r = D_004533FE[0];
    } else {
        func_00423E50(buf);
        if (((buf[0] >> 13) & 7) == 0) {
            r = 0;
        } else {
            func_004240B0(&buf[1], 1, 1);
            v = ((unsigned char *)buf)[4];
            r = (v >> 4) & 1;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BC08);
#ifdef SKIP_ASM
extern unsigned char D_004533FF[];
extern int func_0040B9A8(void);
extern void func_00423E50(unsigned *);
extern int func_004240B0(unsigned *, int, int);
int func_0040BC08(void) {
    unsigned buf[2];
    unsigned char v;
    int r;
    if (func_0040B9A8()) {
        r = D_004533FF[0];
    } else {
        func_00423E50(buf);
        if (((buf[0] >> 13) & 7) == 0) {
            r = 0;
        } else {
            func_004240B0(&buf[1], 1, 1);
            v = ((unsigned char *)buf)[4];
            r = (v >> 5) & 1;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BC70);
#ifdef SKIP_ASM
unsigned char func_0040BC70(unsigned char a) {
    return a + (a / 10) * 6;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040BCA0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BCC0);
#ifdef SKIP_ASM
void func_0040BCC0(unsigned char *p) {
    p[7] = func_0040BCA0(p[7]);
    p[6] = func_0040BCA0(p[6]);
    p[5] = func_0040BCA0(p[5]);
    p[3] = func_0040BCA0(p[3]);
    p[2] = func_0040BCA0(p[2]);
    p[1] = func_0040BCA0(p[1]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BD28);
#ifdef SKIP_ASM
void func_0040BD28(unsigned char *p) {
    p[7] = func_0040BC70(p[7]);
    p[6] = func_0040BC70(p[6]);
    p[5] = func_0040BC70(p[5]);
    p[3] = func_0040BC70(p[3]);
    p[2] = func_0040BC70(p[2]);
    p[1] = func_0040BC70(p[1]);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040BD90);

INCLUDE_ASM("seg/seg_2FE810", func_0040BE48);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BEF0);
#ifdef SKIP_ASM
extern void func_0040BD90(unsigned char *);
void func_0040BEF0(unsigned char *p) {
    p[3]++;
    if (p[3] == 24) {
        p[3] = 0;
        func_0040BD90(p);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BF20);
#ifdef SKIP_ASM
extern void func_0040BE48(unsigned char *);
void func_0040BF20(unsigned char *p) {
    if (p[3] == 0) {
        p[3] = 23;
        func_0040BE48(p);
    } else {
        p[3]--;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BF48);
#ifdef SKIP_ASM
extern void func_0040BCC0(unsigned char *);
extern void func_0040BEF0(unsigned char *);
extern void func_0040BF20(unsigned char *);
extern void func_0040BD28(unsigned char *);
void func_0040BF48(int a, int d0) {
    int d;
    unsigned char *p = (unsigned char *)a;
    func_0040BCC0(p);
    d = p[2] + d0;
    if (d >= 0) {
        if (d > 60) {
            do {
                d -= 60;
                func_0040BEF0(p);
            } while (d > 60);
        }
        p[2] = d;
    } else {
        while (d < 0) {
            d += 60;
            func_0040BF20(p);
        }
        p[2] = d;
    }
    func_0040BD28(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BFD8);
#ifdef SKIP_ASM
extern void func_0040BF48(int, int);
void func_0040BFD8(int a) {
    func_0040BF48(a, -540);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040BFE0);
#ifdef SKIP_ASM
extern int func_0040BAE8(void);
extern int func_0040BBA0(void);
extern void func_0040BF48(int, int);
void func_0040BFE0(int a) {
    int t = func_0040BAE8();
    func_0040BF48(a, t - 540 + func_0040BBA0() * 60);
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040C028);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C220);
#ifdef SKIP_ASM
extern int func_0042C078_0() __asm__("func_0042C078");
extern void func_0042C0C0(void);
extern int func_00423AA0(int, int);
extern void func_00424880(int);
extern int func_00423DB0(int);
extern int D_0052909C[];
extern int D_00453438[];
extern char D_00498278[];
extern char D_004982A8[];
int func_0040C220(void) {
    int n = 0;
    int s, r;
    s = func_0042C078_0();
    r = func_00423AA0(3, D_0052909C[0]);
    if (r == 0)
        func_00424880(3);
    if (s)
        func_0042C0C0();
    if (r < 0) {
        n = 1;
        func_0040A618_log(D_00498278);
    }
    if (D_00453438[0] != -1) {
        if (func_00423DB0(D_00453438[0]) < 0) {
            n++;
            func_0040A618_log(D_004982A8);
        } else {
            D_00453438[0] = -1;
        }
    }
    return n == 0 ? 0 : -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", sceUsbKbGetInfo);
#ifdef SKIP_ASM
struct S_KbInfo { char pad[0x90]; int f90; int pad2; int f98; };
extern struct S_KbInfo G_KbInfo[] __asm__("D_00529000");
extern int D_00453438[];
extern char D_005290A0[];
extern int D_00529100[];
extern int G_KbBuf[] __asm__("D_00529140");
extern char D_004982D0[];
extern void func_0040C8B0(void);
extern void func_00423DE0(int);
extern int func_KbOpen(char *, int, int, int *, int, int *, int, void (*)(void), int) __asm__("func_00426D18");
extern void func_00425C60(char *, int);
int sceUsbKbGetInfo(int a) {
    int r;
    if (D_00453438[0] == -1)
        return -1;
    func_00423DE0(D_00453438[0]);
    r = func_KbOpen(D_005290A0, 1, 1, D_00529100, 16, G_KbBuf, 0x90, func_0040C8B0, 0);
    if (r != 0) {
        func_00425C60(D_004982D0, r);
        return -2;
    }
    G_KbInfo[0].f90 = 1;
    G_KbInfo[0].f98 = a;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", sceUsbKbRead);
#ifdef SKIP_ASM
struct S_KbInfo2 { int cnt; char pad[0x8C]; int f90; int f94; int f98; };
extern struct S_KbInfo2 G_KbInfo2[] __asm__("D_00529000");
extern int G_KbRdy[] __asm__("D_00453438");
extern char G_KbName[] __asm__("D_005290A0");
extern char G_KbArg[] __asm__("D_00529100");
extern int G_KbBuf[] __asm__("D_00529140");
extern char D_004982F8[];
extern void func_0040C8B0(void);
extern void func_00423DE0(int);
extern int func_KbOpenR(char *, int, int, char *, int, int *, int, void (*)(void), int) __asm__("func_00426D18");
extern void func_00425C60(char *, int);
int sceUsbKbRead(unsigned a, int b) {
    if (G_KbRdy[0] == -1)
        return -1;
    if (a >= G_KbInfo2[0].cnt)
        return -11;
    G_KbArg[0] = a;
    func_00423DE0(G_KbRdy[0]);
    {
        int r = func_KbOpenR(G_KbName, 2, 1, G_KbArg, 16, G_KbBuf, 0x50, func_0040C8B0, 0);
        if (r != 0) {
            func_00425C60(D_004982F8, r);
            return -2;
        }
    }
    G_KbInfo2[0].f90 = 2;
    G_KbInfo2[0].f94 = a;
    G_KbInfo2[0].f98 = b;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", sceUsbKbGetLocation);
#ifdef SKIP_ASM
struct S_KbInfo3 { int cnt; char pad[0x8C]; int f90; int f94; int f98; };
extern struct S_KbInfo3 G_KbInfo3[] __asm__("D_00529000");
extern int G_KbRdy3[] __asm__("D_00453438");
extern char G_KbName3[] __asm__("D_005290A0");
extern char G_KbArg3[] __asm__("D_00529100");
extern int G_KbBuf3[] __asm__("D_00529140");
extern char D_00498320[];
extern void func_0040C8B0(void);
extern void func_00423DE0(int);
extern int func_KbOpen3(char *, int, int, char *, int, int *, int, void (*)(void), int) __asm__("func_00426D18");
extern void func_00425C60(char *, int);
int sceUsbKbGetLocation(int a, int b) {
    if (G_KbRdy3[0] == -1)
        return -1;
    if (a >= G_KbInfo3[0].cnt)
        return -11;
    G_KbArg3[0] = a;
    func_00423DE0(G_KbRdy3[0]);
    {
        int r = func_KbOpen3(G_KbName3, 3, 1, G_KbArg3, 16, G_KbBuf3, 0x10, func_0040C8B0, 0);
        if (r != 0) {
            func_00425C60(D_00498320, r);
            return -2;
        }
    }
    G_KbInfo3[0].f90 = 3;
    G_KbInfo3[0].f94 = a;
    G_KbInfo3[0].f98 = b;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", sceUsbKbSetLEDStatus);
#ifdef SKIP_ASM
struct S_KbInfo4 { int cnt; char pad[0x8C]; int f90; int f94; int f98; };
extern struct S_KbInfo4 G_KbInfo4[] __asm__("D_00529000");
extern int G_KbRdy4[] __asm__("D_00453438");
extern char G_KbName4[] __asm__("D_005290A0");
extern char G_KbArg4[] __asm__("D_00529100");
extern int G_KbBuf4[] __asm__("D_00529140");
extern char D_00498350[];
extern void func_0040C8B0(void);
extern void func_00423DE0(int);
extern int func_KbOpen4(char *, int, int, char *, int, int *, int, void (*)(void), int) __asm__("func_00426D18");
extern void func_00425C60(char *, int);
int sceUsbKbSetLEDStatus(int a, unsigned char b) {
    if (G_KbRdy4[0] == -1)
        return -1;
    if (a >= G_KbInfo4[0].cnt)
        return -11;
    G_KbArg4[0] = a;
    G_KbArg4[1] = b;
    func_00423DE0(G_KbRdy4[0]);
    {
        int r = func_KbOpen4(G_KbName4, 4, 1, G_KbArg4, 16, G_KbBuf4, 0x10, func_0040C8B0, 0);
        if (r != 0) {
            func_00425C60(D_00498350, r);
            return -2;
        }
    }
    G_KbInfo4[0].f90 = 4;
    G_KbInfo4[0].f98 = 0;
    G_KbInfo4[0].f94 = a;
    return 0;
}

#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", sceUsbKbSetLEDMode);
#ifdef SKIP_ASM
struct S_Ent5 { int mode; char pad[0x34]; };
struct S_KbInfo5 { int cnt; struct S_Ent5 *ents; char pad[0x88]; int f90; int f94; int f98; };
extern struct S_KbInfo5 G_KbInfo5[] __asm__("D_00529000");
extern int G_KbRdy5[] __asm__("D_00453438");
extern char G_KbName5[] __asm__("D_005290A0");
extern char G_KbArg5[] __asm__("D_00529100");
extern int G_KbBuf5[] __asm__("D_00529140");
extern char D_00498380[];
extern void func_0040C8B0(void);
extern void func_00423DE0(int);
extern int func_KbOpen5(char *, int, int, char *, int, int *, int, void (*)(void), int) __asm__("func_00426D18");
extern void func_00425C60(char *, int);
int sceUsbKbSetLEDMode(int a, unsigned b) {
    int h = G_KbRdy5[0];
    if (h == -1)
        return -1;
    if (a >= G_KbInfo5[0].cnt)
        return -11;
    if (b > 2)
        return -12;
    G_KbInfo5[0].ents[a].mode = b;
    G_KbArg5[0] = a;
    G_KbArg5[1] = b;
    func_00423DE0(h);
    {
        int r = func_KbOpen5(G_KbName5, 5, 1, G_KbArg5, 16, G_KbBuf5, 0x10, func_0040C8B0, 0);
        if (r != 0) {
            func_00425C60(D_00498380, r);
            return -2;
        }
    }
    G_KbInfo5[0].f90 = 5;
    G_KbInfo5[0].f98 = 0;
    G_KbInfo5[0].f94 = a;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040C728);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C770);
#ifdef SKIP_ASM
struct E_529000 { int f0; int f4; int f8; char pad[0x2C]; };
struct T_529000 { int n; struct E_529000 *e; };
extern struct T_529000 D_00529000[];
int func_0040C770(int a, unsigned b) {
    if (a >= D_00529000[0].n)
        return -11;
    if (b >= 2)
        return -12;
    D_00529000[0].e[a].f4 = b;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C7C0);
#ifdef SKIP_ASM
int func_0040C7C0(int a, unsigned b) {
    if (a >= D_00529000[0].n)
        return -11;
    if (b >= 3)
        return -12;
    D_00529000[0].e[a].f8 = b;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040C810);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C8B0);
#ifdef SKIP_ASM
extern int D_00453438[];
extern void func_00423DD0(int);
void func_0040C8B0(void) {
    func_00423DD0(D_00453438[0]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C8C0);
#ifdef SKIP_ASM
struct S_C8C0 { char pad[0x90]; int f90; int pad2; int f98; };
extern struct S_C8C0 G_C8C0[] __asm__("D_00529000");
extern int (*D_00453420[])(void);
int func_0040C8C0(void) {
    int r = 0;
    unsigned s = G_C8C0[0].f90;
    if (s - 1 < 5)
        r = D_00453420[s]();
    G_C8C0[0].f90 = 0;
    G_C8C0[0].f98 = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040C928);
#ifdef SKIP_ASM
struct S40C928 { int n; int m; unsigned char d[1]; };
extern unsigned char *D_00529098[];
extern unsigned char D_00529140[];
int func_0040C928(void) {
    struct S40C928 *p = (struct S40C928 *)D_00529098[0];
    unsigned char *s = D_00529140;
    int i = 0;
    int n = s[0];
    p->n = n;
    p->m = s[1];
    if (n != 0) {
        do {
            p->d[i] = s[2 + i];
            i++;
        } while (i < p->n);
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040C980);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040CEF8);
#ifdef SKIP_ASM
extern unsigned char *D_00529098[];
extern unsigned char D_00529140[];
int func_0040CEF8(void) {
    unsigned char *s = D_00529140;
    unsigned char *d = D_00529098[0];
    int i;
    if (s[6])
        return -1;
    i = 6;
    do {
        *d = *s; i--; s++; d++;
    } while (i >= 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040CF48);
#ifdef SKIP_ASM
extern unsigned char D_00529141[];
extern unsigned char D_00529101[];
int func_0040CF48(void) {
    return D_00529141[0] == D_00529101[0] ? 0 : -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040CF68);
#ifdef SKIP_ASM
int func_0040CF68(void) {
    return D_00529141[0] == D_00529101[0] ? 0 : -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040CF88);
#ifdef SKIP_ASM
struct S40CF88V { int f0; int f4; int f8; int fC; };
struct S40CF88 { int n; char *e; };
extern struct S40CF88 G_40CF88[] __asm__("D_00529000");
int func_0040CF88(void) {
    int i;

    for (i = 0; i < G_40CF88[0].n; i++) {
        struct S40CF88V *v = (struct S40CF88V *)(G_40CF88[0].e + i * 0x38 + 0x10);
        if (v->f8 > 0 && v->fC > 0 && v->f0 != 0 && v->f0 >= 0 && v->f0 < 3)
            v->f4++;
    }
    SYNC_0810();
    EI_0810();
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D010);
#ifdef SKIP_ASM
extern char *D_00529004[];
int func_0040D010(int i) {
    int *p = (int *)(D_00529004[0] + i * 0x38 + 0x10);
    p[9] = 0;
    p[7] = 0;
    p[8] = 0;
    p[1] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D040);
#ifdef SKIP_ASM
struct E_D040 { char pad[0x22]; unsigned short buf[5]; int idx; };
int func_0040D040(int a, unsigned short b) {
    struct E_D040 *e = (struct E_D040 *)(D_00529004[0] + a * 0x38);
    int *q = (int *)((char *)e + 0x10);
    if (q[9] >= 4)
        return -1;
    e->buf[e->idx++] = b;
    if (q[7] >= 4)
        q[7] = 0;
    q[9]++;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D0B0);
#ifdef SKIP_ASM
struct E_D0B0 { char pad[0x22]; unsigned short buf[7]; int idx; };
int func_0040D0B0(int a, unsigned short *out) {
    struct E_D0B0 *e = (struct E_D0B0 *)(D_00529004[0] + a * 0x38);
    int *q = (int *)((char *)e + 0x10);
    if (q[9] <= 0)
        return -1;
    *out = e->buf[e->idx++];
    if (q[8] >= 4)
        q[8] = 0;
    q[9]--;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D118);
#ifdef SKIP_ASM
struct En_D118 { int f0; int mode; int f8; char pad[0x2C]; };
extern struct En_D118 *K_529004[] __asm__("D_00529004");
extern short q_0040D268(int, int, int, unsigned short) __asm__("func_0040D268");
int func_0040D118(int idx, unsigned char b, unsigned char c, int n, unsigned short *src, unsigned short *dst) {
    struct En_D118 *e = &K_529004[0][idx];
    int i;
    int r = 0;
    switch (e->mode) {
    case 0:
        i = 0;
        if (n > 0 && src[0] != 0) {
            do {
                dst[i] = src[i];
                i++;
            } while (i < n && src[i] != 0);
        }
        r = i;
        break;
    case 1:
        i = 0;
        if (n > 0 && src[0] != 0) {
            do {
                dst[i] = q_0040D268(e->f8, b, c, src[i]);
                i++;
            } while (i < n && src[i] != 0);
        }
        r = i;
        break;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D268);
#ifdef SKIP_ASM
extern char T_4983B0[] __asm__("D_004983B0");
extern char T_4983C8[] __asm__("D_004983C8");
extern char T_4987C8[] __asm__("D_004987C8");
extern char T_498BC8[] __asm__("D_00498BC8");
extern void u268_00425C60(char *) __asm__("func_00425C60");
extern unsigned short u268_0040D3C0(int, int) __asm__("func_0040D3C0");
unsigned short func_0040D268(int mode, int a, int b, unsigned short ch) {
    unsigned short *tbl = 0;
    unsigned short v;
    int up = (a & 0x22) != 0;
    switch (mode) {
    case 0:
        tbl = (unsigned short *)(T_4983C8 + (up << 9));
        break;
    case 1:
        tbl = (unsigned short *)(T_4987C8 + (up << 9));
        break;
    case 2:
        tbl = (unsigned short *)(T_498BC8 + (up << 9));
        break;
    default:
        u268_00425C60(T_4983B0);
        break;
    }
    if (ch == 0)
        return 0;
    if (ch >= 0x100)
        return ch;
    v = tbl[ch];
    if (v == 0x4000)
        v = u268_0040D3C0(b & 0xFF, ch & 0xFF);
    if (v == 0x8000)
        v = ch | 0x8000;
    if ((unsigned short)(v - 0x61) < 0x1A && (b & 2))
        v -= 0x20;
    if ((unsigned short)(v - 0x41) < 0x1A) {
        if (b & 2) {
            if (up)
                v += 0x20;
        }
    }
    return v;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040D3C0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D430);
#ifdef SKIP_ASM
int func_0040D430(int a, unsigned b) {
    char *e;
    if (a >= D_00529000[0].n)
        return -11;
    if (b >= 2)
        return -12;
    e = (char *)(a * 0x38) + (int)D_00529000[0].e;
    if (b != *(unsigned *)(e + 0xC)) {
        *(int *)(e + 0x14) = 0;
        *(int *)(e + 0x2C) = 0;
        *(int *)(e + 0x30) = 0;
        *(int *)((char *)D_00529000 + 0x10) = 0;
        *(short *)(e + 0x20) = 0;
    }
    *(unsigned *)(e + 0xC) = b;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D4A0);
#ifdef SKIP_ASM
struct En_D4A0 { char pad[0x10]; int f10; int f14; char pad2[8]; short f20; char pad3[10]; int f2C; int f30; int f34; };
struct Ki_D4A0 { unsigned cnt; struct En_D4A0 *ents; };
extern struct Ki_D4A0 K_529000[] __asm__("D_00529000");
extern int K_453438[] __asm__("D_00453438");
extern char K_5290A0[] __asm__("D_005290A0");
extern char K_529100[] __asm__("D_00529100");
extern int K_529140[] __asm__("D_00529140");
extern char K_4982F8[] __asm__("D_004982F8");
extern void cb_C8B0(void) __asm__("func_0040C8B0");
extern void q_00423DE0(int) __asm__("func_00423DE0");
extern int q_00426D18(char *, int, int, char *, int, int *, int, void (*)(void), int) __asm__("func_00426D18");
extern void q_00425C60(char *, int) __asm__("func_00425C60");
int func_0040D4A0(unsigned a) {
    int r;
    struct En_D4A0 *e;
    if (K_453438[0] == -1)
        return -1;
    if (a >= K_529000[0].cnt)
        return -11;
    K_529100[0] = a;
    q_00423DE0(K_453438[0]);
    r = q_00426D18(K_5290A0, 6, 1, K_529100, 16, K_529140, 0, cb_C8B0, 0);
    if (r != 0) {
        q_00425C60(K_4982F8, r);
        return -2;
    }
    e = &K_529000[0].ents[a];
    e->f10 = 0;
    e->f14 = 0;
    e->f20 = 0;
    e->f2C = 0;
    e->f30 = 0;
    e->f34 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D588);
#ifdef SKIP_ASM
extern int func_0040E878(float x, float *y);
extern float func_0040F5A8(float x, float y, int iy);
typedef union { float f; int bits; } FloatBits_D588;
#define FLOAT_TO_BITS_D588(i, d) do { FloatBits_D588 fb_; fb_.f = (d); (i) = fb_.bits; } while (0)
float func_0040D588(float x) {
    float y[2];
    int hx, ix;
    FLOAT_TO_BITS_D588(hx, x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3f490fda) {
        return func_0040F5A8(x, 0.0f, 1);
    } else if (ix > 0x7f7fffff) {
        return x - x;
    } else {
        int n = func_0040E878(x, y);
        return func_0040F5A8(y[0], y[1], 1 - ((n & 1) << 1));
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D610);
#ifdef SKIP_ASM
struct E40D610 { int type; char *name; double arg1; double arg2; double retval; int err; };
extern int D_00499688[];
extern char D_00499070[];
extern double D_00499680[];
extern double core_40D610(double) __asm__("func_0040DB58");
extern int isn_40D610(double) __asm__("func_0040F840");
extern int cmp_40D610(double, double) __asm__("func_00412500");
extern double sub_40D610(double, double) __asm__("func_00411F70");
extern int matherr_40D610(struct E40D610 *) __asm__("func_0040F878");
extern int *errno_40D610(void) __asm__("func_00415FB8");
double func_0040D610(double x) {
    struct E40D610 e;
    double zero;
    double z = core_40D610(x);
    int ver = D_00499688[0];
    if (ver == -1 || isn_40D610(x) || (zero = 0.0, cmp_40D610(x, zero) > 0))
        return z;
    e.err = 0;
    e.name = D_00499070;
    e.arg2 = e.arg1 = x;
    if (ver == 0)
        e.retval = -3.4028234663852886e+38;
    else
        e.retval = sub_40D610(zero, D_00499680[0]);
    if (cmp_40D610(x, 0.0) == 0) {
        e.type = 2;
        if (D_00499688[0] == 2)
            *errno_40D610() = 34;
        else if (!matherr_40D610(&e))
            *errno_40D610() = 33;
    } else {
        e.type = 1;
        if (D_00499688[0] == 2)
            *errno_40D610() = 33;
        else if (!matherr_40D610(&e))
            *errno_40D610() = 33;
    }
    if (e.err != 0)
        *errno_40D610() = e.err;
    return e.retval;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D758);
#ifdef SKIP_ASM
// PORT: PS2-only newlib libm library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0040D758\n.type func_0040D758, @function\nfunc_0040D758:\n"
    "addiu $29, $29, -0x70\n"
    "swc1 $f20, 0x60($29)\n"
    "mov.s $f20, $f12\n"
    "sd $17, 0x40($29)\n"
    "sd $16, 0x30($29)\n"
    "swc1 $f21, 0x68($29)\n"
    "sd $31, 0x50($29)\n"
    "jal func_0040E048\n"
    "lui $17, %hi(D_00499688)\n"
    "lw $16, %lo(D_00499688)($17)\n"
    "addiu $2, $0, -0x1\n"
    "beq $16, $2, .L0040D8B0\n"
    "mov.s $f21, $f0\n"
    "jal func_0040F8C0\n"
    "mov.s $f12, $f20\n"
    "beqz $2, .L0040D8B0\n"
    "mov.s $f0, $f21\n"
    "lui $1, (0x42B17180 >> 16)\n"
    "ori $1, $1, (0x42B17180 & 0xFFFF)\n"
    "mtc1 $1, $f0\n"
    "c.lt.s $f0, $f20\n"
    "nop\n"
    "bc1f .L0040D814\n"
    "lui $2, %hi(D_00499088)\n"
    "addiu $3, $0, 0x3\n"
    "addiu $2, $2, %lo(D_00499088)\n"
    "sw $3, 0x0($29)\n"
    "sw $2, 0x4($29)\n"
    "mov.s $f12, $f20\n"
    "jal func_00413AF8\n"
    "sw $0, 0x20($29)\n"
    "sd $2, 0x8($29)\n"
    "bnez $16, .L0040D7F0\n"
    "sd $2, 0x10($29)\n"
    "lui $1, %hi(D_00499090)\n"
    "ld $2, %lo(D_00499090)($1)\n"
    "b .L0040D7FC\n"
    "sd $2, 0x18($29)\n"
    ".L0040D7F0:\n"
    "lui $2, %hi(D_00499680)\n"
    "ld $3, %lo(D_00499680)($2)\n"
    "sd $3, 0x18($29)\n"
    ".L0040D7FC:\n"
    "lw $3, %lo(D_00499688)($17)\n"
    "addiu $2, $0, 0x2\n"
    "beq $3, $2, .L0040D870\n"
    "nop\n"
    "b .L0040D860\n"
    "nop\n"
    ".L0040D814:\n"
    "lui $1, (0xC2CFF1B5 >> 16)\n"
    "ori $1, $1, (0xC2CFF1B5 & 0xFFFF)\n"
    "mtc1 $1, $f0\n"
    "c.lt.s $f20, $f0\n"
    "nop\n"
    "bc1f .L0040D8AC\n"
    "addiu $3, $0, 0x4\n"
    "addiu $2, $2, %lo(D_00499088)\n"
    "sw $3, 0x0($29)\n"
    "sw $2, 0x4($29)\n"
    "mov.s $f12, $f20\n"
    "jal func_00413AF8\n"
    "sw $0, 0x20($29)\n"
    "daddu $3, $0, $0\n"
    "sd $2, 0x8($29)\n"
    "sd $3, 0x18($29)\n"
    "addiu $3, $0, 0x2\n"
    "beq $16, $3, .L0040D870\n"
    "sd $2, 0x10($29)\n"
    ".L0040D860:\n"
    "jal func_0040F878\n"
    "daddu $4, $29, $0\n"
    "bnez $2, .L0040D884\n"
    "lw $2, 0x20($29)\n"
    ".L0040D870:\n"
    "jal func_00415FB8\n"
    "nop\n"
    "addiu $3, $0, 0x22\n"
    "sw $3, 0x0($2)\n"
    "lw $2, 0x20($29)\n"
    ".L0040D884:\n"
    "beqz $2, .L0040D89C\n"
    "nop\n"
    "jal func_00415FB8\n"
    "nop\n"
    "lw $3, 0x20($29)\n"
    "sw $3, 0x0($2)\n"
    ".L0040D89C:\n"
    "jal func_004127A8\n"
    "ld $4, 0x18($29)\n"
    "b .L0040D8B4\n"
    "ld $31, 0x50($29)\n"
    ".L0040D8AC:\n"
    "mov.s $f0, $f21\n"
    ".L0040D8B0:\n"
    "ld $31, 0x50($29)\n"
    ".L0040D8B4:\n"
    "ld $17, 0x40($29)\n"
    "ld $16, 0x30($29)\n"
    "lwc1 $f21, 0x68($29)\n"
    "lwc1 $f20, 0x60($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x70\n"
    ".size func_0040D758, . - func_0040D758\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040D8D0);
#ifdef SKIP_ASM
// PORT: PS2-only newlib libm library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0040D8D0\n.type func_0040D8D0, @function\nfunc_0040D8D0:\n"
    "addiu $29, $29, -0x80\n"
    "swc1 $f21, 0x68($29)\n"
    "swc1 $f20, 0x60($29)\n"
    "mov.s $f21, $f12\n"
    "mov.s $f20, $f13\n"
    "sd $17, 0x40($29)\n"
    "sd $16, 0x30($29)\n"
    "swc1 $f22, 0x70($29)\n"
    "sd $31, 0x50($29)\n"
    "jal func_0040E300\n"
    "lui $17, %hi(D_00499688)\n"
    "lw $16, %lo(D_00499688)($17)\n"
    "addiu $2, $0, -0x1\n"
    "beq $16, $2, .L0040D9E8\n"
    "mov.s $f22, $f0\n"
    "jal func_0040F9D0\n"
    "mov.s $f12, $f20\n"
    "bnez $2, .L0040D9EC\n"
    "mov.s $f0, $f22\n"
    "jal func_0040F9D0\n"
    "mov.s $f12, $f21\n"
    "bnez $2, .L0040D9EC\n"
    "mov.s $f0, $f22\n"
    "mtc1 $0, $f0\n"
    "c.eq.s $f20, $f0\n"
    "nop\n"
    "bc1f .L0040D9E8\n"
    "lui $2, %hi(D_00499098)\n"
    "addiu $3, $0, 0x1\n"
    "addiu $2, $2, %lo(D_00499098)\n"
    "sw $3, 0x0($29)\n"
    "sw $2, 0x4($29)\n"
    "mov.s $f12, $f21\n"
    "jal func_00413AF8\n"
    "sw $0, 0x20($29)\n"
    "mov.s $f12, $f20\n"
    "jal func_00413AF8\n"
    "sd $2, 0x8($29)\n"
    "bnez $16, .L0040D980\n"
    "sd $2, 0x10($29)\n"
    "jal func_00413AF8\n"
    "mov.s $f12, $f21\n"
    "b .L0040D98C\n"
    "sd $2, 0x18($29)\n"
    ".L0040D980:\n"
    "lui $2, %hi(D_004990A0)\n"
    "ld $3, %lo(D_004990A0)($2)\n"
    "sd $3, 0x18($29)\n"
    ".L0040D98C:\n"
    "lw $3, %lo(D_00499688)($17)\n"
    "addiu $2, $0, 0x2\n"
    "beq $3, $2, .L0040D9AC\n"
    "nop\n"
    "jal func_0040F878\n"
    "daddu $4, $29, $0\n"
    "bnez $2, .L0040D9C0\n"
    "lw $2, 0x20($29)\n"
    ".L0040D9AC:\n"
    "jal func_00415FB8\n"
    "nop\n"
    "addiu $3, $0, 0x21\n"
    "sw $3, 0x0($2)\n"
    "lw $2, 0x20($29)\n"
    ".L0040D9C0:\n"
    "beqz $2, .L0040D9D8\n"
    "nop\n"
    "jal func_00415FB8\n"
    "nop\n"
    "lw $3, 0x20($29)\n"
    "sw $3, 0x0($2)\n"
    ".L0040D9D8:\n"
    "jal func_004127A8\n"
    "ld $4, 0x18($29)\n"
    "b .L0040D9F0\n"
    "ld $31, 0x50($29)\n"
    ".L0040D9E8:\n"
    "mov.s $f0, $f22\n"
    ".L0040D9EC:\n"
    "ld $31, 0x50($29)\n"
    ".L0040D9F0:\n"
    "ld $17, 0x40($29)\n"
    "ld $16, 0x30($29)\n"
    "lwc1 $f22, 0x70($29)\n"
    "lwc1 $f21, 0x68($29)\n"
    "lwc1 $f20, 0x60($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x80\n"
    ".size func_0040D8D0, . - func_0040D8D0\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040DA10);
#ifdef SKIP_ASM
// PORT: PS2-only newlib libm library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0040DA10\n.type func_0040DA10, @function\nfunc_0040DA10:\n"
    "addiu $29, $29, -0x70\n"
    "swc1 $f20, 0x60($29)\n"
    "mov.s $f20, $f12\n"
    "sd $17, 0x40($29)\n"
    "sd $16, 0x30($29)\n"
    "swc1 $f21, 0x68($29)\n"
    "sd $31, 0x50($29)\n"
    "jal func_0040E550\n"
    "lui $17, %hi(D_00499688)\n"
    "lw $16, %lo(D_00499688)($17)\n"
    "addiu $2, $0, -0x1\n"
    "beq $16, $2, .L0040DA68\n"
    "mov.s $f21, $f0\n"
    "jal func_0040F9D0\n"
    "mov.s $f12, $f20\n"
    "bnez $2, .L0040DB3C\n"
    "mov.s $f0, $f21\n"
    "mtc1 $0, $f0\n"
    "c.lt.s $f0, $f20\n"
    "nop\n"
    "bc1f .L0040DA70\n"
    "lui $2, %hi(D_004990A8)\n"
    ".L0040DA68:\n"
    "b .L0040DB3C\n"
    "mov.s $f0, $f21\n"
    ".L0040DA70:\n"
    "sw $0, 0x20($29)\n"
    "addiu $2, $2, %lo(D_004990A8)\n"
    "mov.s $f12, $f20\n"
    "jal func_00413AF8\n"
    "sw $2, 0x4($29)\n"
    "sd $2, 0x8($29)\n"
    "bnez $16, .L0040DAA0\n"
    "sd $2, 0x10($29)\n"
    "lui $1, %hi(D_004990B0)\n"
    "ld $2, %lo(D_004990B0)($1)\n"
    "b .L0040DAB4\n"
    "sd $2, 0x18($29)\n"
    ".L0040DAA0:\n"
    "lui $2, %hi(D_00499680)\n"
    "daddu $4, $0, $0\n"
    "jal func_00411F70\n"
    "ld $5, %lo(D_00499680)($2)\n"
    "sd $2, 0x18($29)\n"
    ".L0040DAB4:\n"
    "mtc1 $0, $f0\n"
    "c.eq.s $f20, $f0\n"
    "nop\n"
    "bc1f .L0040DAE4\n"
    "addiu $2, $0, 0x2\n"
    "lw $3, %lo(D_00499688)($17)\n"
    "bne $3, $2, .L0040DAF8\n"
    "sw $2, 0x0($29)\n"
    "jal func_00415FB8\n"
    "nop\n"
    "b .L0040DB14\n"
    "addiu $3, $0, 0x22\n"
    ".L0040DAE4:\n"
    "addiu $3, $0, 0x1\n"
    "lw $2, %lo(D_00499688)($17)\n"
    "addiu $4, $0, 0x2\n"
    "beq $2, $4, .L0040DB08\n"
    "sw $3, 0x0($29)\n"
    ".L0040DAF8:\n"
    "jal func_0040F878\n"
    "daddu $4, $29, $0\n"
    "bnez $2, .L0040DB1C\n"
    "lw $2, 0x20($29)\n"
    ".L0040DB08:\n"
    "jal func_00415FB8\n"
    "nop\n"
    "addiu $3, $0, 0x21\n"
    ".L0040DB14:\n"
    "sw $3, 0x0($2)\n"
    "lw $2, 0x20($29)\n"
    ".L0040DB1C:\n"
    "beqz $2, .L0040DB34\n"
    "nop\n"
    "jal func_00415FB8\n"
    "nop\n"
    "lw $3, 0x20($29)\n"
    "sw $3, 0x0($2)\n"
    ".L0040DB34:\n"
    "jal func_004127A8\n"
    "ld $4, 0x18($29)\n"
    ".L0040DB3C:\n"
    "ld $31, 0x50($29)\n"
    "ld $17, 0x40($29)\n"
    "ld $16, 0x30($29)\n"
    "lwc1 $f21, 0x68($29)\n"
    "lwc1 $f20, 0x60($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x70\n"
    ".size func_0040DA10, . - func_0040DA10\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040DB58);
#ifdef SKIP_ASM
// PORT: PS2-only newlib libm library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0040DB58\n.type func_0040DB58, @function\nfunc_0040DB58:\n"
    "addiu $29, $29, -0xA0\n"
    "daddu $6, $4, $0\n"
    "sd $31, 0x90($29)\n"
    "sd $30, 0x80($29)\n"
    "sd $23, 0x70($29)\n"
    "sd $22, 0x60($29)\n"
    "sd $21, 0x50($29)\n"
    "sd $20, 0x40($29)\n"
    "sd $19, 0x30($29)\n"
    "sd $18, 0x20($29)\n"
    "sd $17, 0x10($29)\n"
    "sd $16, 0x0($29)\n"
    "daddu $2, $6, $0\n"
    "dsra32 $19, $2, 0\n"
    "dsll32 $3, $2, 0\n"
    "dsra32 $3, $3, 0\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "slt $2, $2, $19\n"
    "bnez $2, .L0040DC10\n"
    "daddu $30, $0, $0\n"
    "lui $2, (0x7FFFFFFF >> 16)\n"
    "ori $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
    "and $2, $19, $2\n"
    "or $2, $2, $3\n"
    "bnez $2, .L0040DBD0\n"
    "lui $3, %hi(D_00499110)\n"
    "b .L0040E014\n"
    "ld $2, %lo(D_00499110)($3)\n"
    "nop\n"
    ".L0040DBD0:\n"
    "bgez $19, .L0040DBF4\n"
    "daddu $4, $6, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $4, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412280\n"
    "daddu $5, $0, $0\n"
    "b .L0040E018\n"
    "ld $31, 0x90($29)\n"
    ".L0040DBF4:\n"
    "ori $5, $0, 0x86A0\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411FD8\n"
    "addiu $30, $0, -0x36\n"
    "daddu $6, $2, $0\n"
    "dsra32 $19, $2, 0\n"
    "nop\n"
    ".L0040DC10:\n"
    "lui $2, (0x7FEFFFFF >> 16)\n"
    "ori $2, $2, (0x7FEFFFFF & 0xFFFF)\n"
    "slt $2, $2, $19\n"
    "beqz $2, .L0040DC38\n"
    "lui $16, (0xFFFFF >> 16)\n"
    "daddu $4, $6, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $4, $0\n"
    "b .L0040E018\n"
    "ld $31, 0x90($29)\n"
    ".L0040DC38:\n"
    "sra $4, $19, 20\n"
    "ori $16, $16, (0xFFFFF & 0xFFFF)\n"
    "lui $2, (0x95F64 >> 16)\n"
    "ori $2, $2, (0x95F64 & 0xFFFF)\n"
    "and $19, $19, $16\n"
    "addu $2, $19, $2\n"
    "addiu $3, $30, -0x3FF\n"
    "lui $5, (0x100000 >> 16)\n"
    "addu $30, $3, $4\n"
    "and $20, $2, $5\n"
    "daddu $4, $6, $0\n"
    "lui $2, (0x3FF00000 >> 16)\n"
    "lui $3, (0xFFFF0000 >> 16)\n"
    "dsrl32 $3, $3, 0\n"
    "xor $2, $20, $2\n"
    "and $4, $4, $3\n"
    "or $2, $2, $19\n"
    "dsll32 $2, $2, 0\n"
    "or $6, $4, $2\n"
    "sra $3, $20, 20\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "addu $30, $30, $3\n"
    "jal func_00411F70\n"
    "daddu $4, $6, $0\n"
    "daddu $21, $2, $0\n"
    "addiu $2, $19, 0x2\n"
    "and $2, $2, $16\n"
    "slti $2, $2, 0x3\n"
    "beqz $2, .L0040DDB4\n"
    "daddu $16, $0, $0\n"
    "daddu $4, $21, $0\n"
    "jal func_00412500\n"
    "daddu $5, $16, $0\n"
    "bnez $2, .L0040DD18\n"
    "daddu $4, $21, $0\n"
    "beqz $30, .L0040E014\n"
    "daddu $2, $16, $0\n"
    "jal func_00412550\n"
    "daddu $4, $30, $0\n"
    "daddu $22, $2, $0\n"
    "lui $1, %hi(D_00499118)\n"
    "ld $5, %lo(D_00499118)($1)\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "lui $1, %hi(D_00499120)\n"
    "ld $5, %lo(D_00499120)($1)\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $2, $0\n"
    "b .L0040E018\n"
    "ld $31, 0x90($29)\n"
    "nop\n"
    ".L0040DD18:\n"
    "jal func_00411FD8\n"
    "daddu $5, $21, $0\n"
    "lui $1, %hi(D_00499128)\n"
    "ld $5, %lo(D_00499128)($1)\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $21, $0\n"
    "ori $4, $0, 0xFF80\n"
    "dsll32 $4, $4, 14\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "bnez $30, .L0040DD64\n"
    "daddu $18, $2, $0\n"
    "daddu $4, $21, $0\n"
    "b .L0040E00C\n"
    "daddu $5, $18, $0\n"
    ".L0040DD64:\n"
    "jal func_00412550\n"
    "daddu $4, $30, $0\n"
    "daddu $22, $2, $0\n"
    "lui $1, %hi(D_00499130)\n"
    "ld $5, %lo(D_00499130)($1)\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "lui $1, %hi(D_00499138)\n"
    "ld $5, %lo(D_00499138)($1)\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $21, $0\n"
    "b .L0040E008\n"
    "daddu $4, $16, $0\n"
    ".L0040DDB4:\n"
    "ori $5, $0, 0x8000\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411F18\n"
    "daddu $4, $21, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00412280\n"
    "daddu $4, $21, $0\n"
    "daddu $23, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $30, $0\n"
    "daddu $22, $2, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $23, $0\n"
    "lui $3, (0xFFF9EB86 >> 16)\n"
    "daddu $18, $2, $0\n"
    "ori $3, $3, (0xFFF9EB86 & 0xFFFF)\n"
    "daddu $4, $18, $0\n"
    "addu $20, $19, $3\n"
    "jal func_00411FD8\n"
    "daddu $5, $18, $0\n"
    "lui $16, (0x6B851 >> 16)\n"
    "daddu $17, $2, $0\n"
    "ori $16, $16, (0x6B851 & 0xFFFF)\n"
    "lui $1, %hi(D_00499140)\n"
    "ld $5, %lo(D_00499140)($1)\n"
    "subu $16, $16, $19\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "or $20, $20, $16\n"
    "lui $1, %hi(D_00499148)\n"
    "ld $5, %lo(D_00499148)($1)\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "lui $1, %hi(D_00499150)\n"
    "ld $5, %lo(D_00499150)($1)\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "lui $1, %hi(D_00499158)\n"
    "ld $5, %lo(D_00499158)($1)\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "lui $1, %hi(D_00499160)\n"
    "ld $5, %lo(D_00499160)($1)\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "lui $1, %hi(D_00499168)\n"
    "ld $5, %lo(D_00499168)($1)\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $4, $17, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "lui $1, %hi(D_00499170)\n"
    "ld $5, %lo(D_00499170)($1)\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $16, $0\n"
    "blez $20, .L0040DF84\n"
    "daddu $18, $2, $0\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $21, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $21, $0\n"
    "bnez $30, .L0040DF30\n"
    "daddu $19, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $19, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $19, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "b .L0040E008\n"
    "daddu $4, $21, $0\n"
    ".L0040DF30:\n"
    "lui $1, %hi(D_00499178)\n"
    "ld $5, %lo(D_00499178)($1)\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $17, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $19, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "lui $1, %hi(D_00499180)\n"
    "ld $5, %lo(D_00499180)($1)\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $2, $0\n"
    "b .L0040DFF0\n"
    "daddu $4, $19, $0\n"
    ".L0040DF84:\n"
    "bnez $30, .L0040DFAC\n"
    "nop\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $21, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "b .L0040E008\n"
    "daddu $4, $21, $0\n"
    ".L0040DFAC:\n"
    "lui $1, %hi(D_00499188)\n"
    "ld $5, %lo(D_00499188)($1)\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $17, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $21, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "lui $1, %hi(D_00499190)\n"
    "ld $5, %lo(D_00499190)($1)\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $16, $0\n"
    ".L0040DFF0:\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $21, $0\n"
    "daddu $4, $17, $0\n"
    ".L0040E008:\n"
    "daddu $5, $2, $0\n"
    ".L0040E00C:\n"
    "jal func_00411F70\n"
    "nop\n"
    ".L0040E014:\n"
    "ld $31, 0x90($29)\n"
    ".L0040E018:\n"
    "ld $30, 0x80($29)\n"
    "ld $23, 0x70($29)\n"
    "ld $22, 0x60($29)\n"
    "ld $21, 0x50($29)\n"
    "ld $20, 0x40($29)\n"
    "ld $19, 0x30($29)\n"
    "ld $18, 0x20($29)\n"
    "ld $17, 0x10($29)\n"
    "ld $16, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xA0\n"
    ".size func_0040DB58, . - func_0040DB58\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040E048);
#ifdef SKIP_ASM
// PORT: PS2-only newlib libm library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0040E048\n.type func_0040E048, @function\nfunc_0040E048:\n"
    "mfc1 $2, $f12\n"
    "daddu $4, $2, $0\n"
    "srl $7, $4, 31\n"
    "lui $3, (0x7FFFFFFF >> 16)\n"
    "lui $2, (0x42B17217 >> 16)\n"
    "ori $3, $3, (0x7FFFFFFF & 0xFFFF)\n"
    "ori $2, $2, (0x42B17217 & 0xFFFF)\n"
    "and $4, $4, $3\n"
    "sltu $2, $2, $4\n"
    "beqz $2, .L0040E0F0\n"
    "lui $3, (0x7F800000 >> 16)\n"
    "sltu $2, $3, $4\n"
    "beqz $2, .L0040E088\n"
    "nop\n"
    "jr $31\n"
    "add.s $f0, $f12, $f12\n"
    ".L0040E088:\n"
    "bne $4, $3, .L0040E0A4\n"
    "nop\n"
    "mtc1 $0, $f0\n"
    "beql $7, $0, .L0040E09C\n"
    "mov.s $f0, $f12\n"
    ".L0040E09C:\n"
    "jr $31\n"
    "nop\n"
    ".L0040E0A4:\n"
    "lui $1, (0x42B17180 >> 16)\n"
    "ori $1, $1, (0x42B17180 & 0xFFFF)\n"
    "mtc1 $1, $f0\n"
    "c.lt.s $f0, $f12\n"
    "nop\n"
    "bc1f .L0040E0C8\n"
    "lui $2, %hi(D_004991E0)\n"
    "jr $31\n"
    "lwc1 $f0, %lo(D_004991E0)($2)\n"
    ".L0040E0C8:\n"
    "lui $1, (0xC2CFF1B5 >> 16)\n"
    "ori $1, $1, (0xC2CFF1B5 & 0xFFFF)\n"
    "mtc1 $1, $f0\n"
    "c.lt.s $f12, $f0\n"
    "nop\n"
    "bc1f .L0040E0F4\n"
    "lui $2, (0x3EB17218 >> 16)\n"
    "mtc1 $0, $f0\n"
    "jr $31\n"
    "nop\n"
    ".L0040E0F0:\n"
    "lui $2, (0x3EB17218 >> 16)\n"
    ".L0040E0F4:\n"
    "ori $2, $2, (0x3EB17218 & 0xFFFF)\n"
    "sltu $2, $2, $4\n"
    "beqz $2, .L0040E1A4\n"
    "lui $2, (0x3F851591 >> 16)\n"
    "ori $2, $2, (0x3F851591 & 0xFFFF)\n"
    "sltu $2, $2, $4\n"
    "bnez $2, .L0040E14C\n"
    "lui $2, %hi(D_004991A0)\n"
    "lui $2, %hi(D_004991B8)\n"
    "sll $5, $7, 2\n"
    "addiu $2, $2, %lo(D_004991B8)\n"
    "lui $4, %hi(D_004991C0)\n"
    "addu $2, $5, $2\n"
    "addiu $4, $4, %lo(D_004991C0)\n"
    "lwc1 $f0, 0x0($2)\n"
    "addiu $3, $0, 0x1\n"
    "addu $5, $5, $4\n"
    "subu $3, $3, $7\n"
    "sub.s $f7, $f12, $f0\n"
    "subu $6, $3, $7\n"
    "b .L0040E19C\n"
    "lwc1 $f6, 0x0($5)\n"
    ".L0040E14C:\n"
    "lui $1, (0x3FB8AA3B >> 16)\n"
    "ori $1, $1, (0x3FB8AA3B & 0xFFFF)\n"
    "mtc1 $1, $f0\n"
    "addiu $2, $2, %lo(D_004991A0)\n"
    "sll $3, $7, 2\n"
    "addu $3, $3, $2\n"
    "mul.s $f0, $f12, $f0\n"
    "lwc1 $f2, 0x0($3)\n"
    "lui $2, %hi(D_004991B8)\n"
    "lwc1 $f1, %lo(D_004991B8)($2)\n"
    "lui $3, %hi(D_004991C0)\n"
    "add.s $f0, $f0, $f2\n"
    "lwc1 $f3, %lo(D_004991C0)($3)\n"
    ".word 0x460000A4\n"
    "mfc1 $6, $f2\n"
    "mtc1 $6, $f5\n"
    "cvt.s.w $f5, $f5\n"
    "mul.s $f1, $f5, $f1\n"
    "mul.s $f6, $f5, $f3\n"
    "sub.s $f7, $f12, $f1\n"
    ".L0040E19C:\n"
    "b .L0040E1E8\n"
    "sub.s $f12, $f7, $f6\n"
    ".L0040E1A4:\n"
    "lui $2, (0x317FFFFF >> 16)\n"
    "ori $2, $2, (0x317FFFFF & 0xFFFF)\n"
    "sltu $2, $2, $4\n"
    "bnel $2, $0, .L0040E1E8\n"
    "daddu $6, $0, $0\n"
    "lui $1, (0x7149F2CA >> 16)\n"
    "ori $1, $1, (0x7149F2CA & 0xFFFF)\n"
    "mtc1 $1, $f0\n"
    "lui $1, (0x3F800000 >> 16)\n"
    "mtc1 $1, $f1\n"
    "add.s $f0, $f12, $f0\n"
    "c.lt.s $f1, $f0\n"
    "nop\n"
    "bc1fl .L0040E1EC\n"
    "mul.s $f5, $f12, $f12\n"
    "jr $31\n"
    "add.s $f0, $f12, $f1\n"
    ".L0040E1E8:\n"
    "mul.s $f5, $f12, $f12\n"
    ".L0040E1EC:\n"
    "lui $1, (0x3331BB4C >> 16)\n"
    "ori $1, $1, (0x3331BB4C & 0xFFFF)\n"
    "mtc1 $1, $f0\n"
    "lui $1, (0xB5DDEA0E >> 16)\n"
    "ori $1, $1, (0xB5DDEA0E & 0xFFFF)\n"
    "mtc1 $1, $f1\n"
    "lui $1, (0x388AB355 >> 16)\n"
    "ori $1, $1, (0x388AB355 & 0xFFFF)\n"
    "mtc1 $1, $f2\n"
    "mul.s $f0, $f5, $f0\n"
    "lui $1, (0xBB360B61 >> 16)\n"
    "ori $1, $1, (0xBB360B61 & 0xFFFF)\n"
    "mtc1 $1, $f3\n"
    "lui $1, (0x3E2AAAAB >> 16)\n"
    "ori $1, $1, (0x3E2AAAAB & 0xFFFF)\n"
    "mtc1 $1, $f4\n"
    "add.s $f0, $f0, $f1\n"
    "mul.s $f0, $f5, $f0\n"
    "add.s $f0, $f0, $f2\n"
    "mul.s $f0, $f5, $f0\n"
    "add.s $f0, $f0, $f3\n"
    "mul.s $f0, $f5, $f0\n"
    "add.s $f0, $f0, $f4\n"
    "mul.s $f0, $f5, $f0\n"
    "bnez $6, .L0040E284\n"
    "sub.s $f3, $f12, $f0\n"
    "lui $1, (0x40000000 >> 16)\n"
    "mtc1 $1, $f1\n"
    "mul.s $f0, $f12, $f3\n"
    "lui $1, (0x3F800000 >> 16)\n"
    "mtc1 $1, $f2\n"
    "sub.s $f1, $f3, $f1\n"
    "nop\n"
    "nop\n"
    "div.s $f0, $f0, $f1\n"
    "sub.s $f0, $f0, $f12\n"
    "jr $31\n"
    "sub.s $f0, $f2, $f0\n"
    ".L0040E284:\n"
    "lui $1, (0x40000000 >> 16)\n"
    "mtc1 $1, $f1\n"
    "mul.s $f0, $f12, $f3\n"
    "lui $1, (0x3F800000 >> 16)\n"
    "mtc1 $1, $f2\n"
    "slti $2, $6, -0x7D\n"
    "sub.s $f1, $f1, $f3\n"
    "nop\n"
    "nop\n"
    "div.s $f0, $f0, $f1\n"
    "sub.s $f0, $f6, $f0\n"
    "sub.s $f0, $f0, $f7\n"
    "sub.s $f2, $f2, $f0\n"
    "mfc1 $3, $f2\n"
    "bnez $2, .L0040E2D8\n"
    "daddu $2, $3, $0\n"
    "sll $2, $6, 23\n"
    "addu $3, $3, $2\n"
    "mtc1 $3, $f0\n"
    "jr $31\n"
    "nop\n"
    ".L0040E2D8:\n"
    "addiu $3, $6, 0x64\n"
    "sll $3, $3, 23\n"
    "addu $3, $2, $3\n"
    "lui $1, (0xD800000 >> 16)\n"
    "mtc1 $1, $f0\n"
    "mtc1 $3, $f1\n"
    "mul.s $f0, $f1, $f0\n"
    "jr $31\n"
    "nop\n"
    ".size func_0040E048, . - func_0040E048\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040E300);

INCLUDE_ASM("seg/seg_2FE810", func_0040E550);

INCLUDE_ASM("seg/seg_2FE810", func_0040E878);

INCLUDE_ASM("seg/seg_2FE810", func_0040EC58);

INCLUDE_ASM("seg/seg_2FE810", func_0040F5A8);

INCLUDE_ASM("seg/seg_2FE810", func_0040F840);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040F878);
#ifdef SKIP_ASM
extern void func_00412500(long, long);
int func_0040F878(long *p) {
    long v = p[1];
    func_00412500(v, v);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040F8A0);
#ifdef SKIP_ASM
typedef union { float f; int bits; } FloatBits_F8A0;
#define FLOAT_TO_BITS_F8A0(i, d) do { FloatBits_F8A0 fb_; fb_.f = (d); (i) = fb_.bits; } while (0)
#define BITS_TO_FLOAT_F8A0(d, i) do { FloatBits_F8A0 fb_; fb_.bits = (i); (d) = fb_.f; } while (0)
float func_0040F8A0(float x) {
    int ix;
    FLOAT_TO_BITS_F8A0(ix, x);
    BITS_TO_FLOAT_F8A0(x, ix & 0x7fffffff);
    return x;
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040F8C0);

INCLUDE_ASM("seg/seg_2FE810", func_0040F8E8);

INCLUDE_ASM("seg/seg_2FE810", func_0040F9D0);

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040F9F8);
#ifdef SKIP_ASM
extern float copysignf_F9F8(float, float) __asm__("func_0040FB58");
typedef union { float f; int bits; } FloatBits_F9F8;
#define FLOAT_TO_BITS_F9F8(i, d) do { FloatBits_F9F8 fb_; fb_.f = (d); (i) = fb_.bits; } while (0)
#define BITS_TO_FLOAT_F9F8(d, i) do { FloatBits_F9F8 fb_; fb_.bits = (i); (d) = fb_.f; } while (0)
static const float k_2pow25_F9F8 = 3.3554432e+07f, k_2powm25_F9F8 = 2.9802322e-08f, k_big_F9F8 = 1.0e+30f, k_small_F9F8 = 1.0e-30f;
float func_0040F9F8(float x, int n) {
    int k, ix;
    FLOAT_TO_BITS_F9F8(ix, x);
    k = (ix & 0x7f800000) >> 23;
    if (k == 0) {
        if ((ix & 0x7fffffff) == 0)
            return x;
        x *= k_2pow25_F9F8;
        FLOAT_TO_BITS_F9F8(ix, x);
        k = ((ix & 0x7f800000) >> 23) - 25;
        if (n < -50000)
            return k_small_F9F8 * x;
    }
    if (k == 0xff)
        return x + x;
    k = k + n;
    if (k > 0xfe)
        return k_big_F9F8 * copysignf_F9F8(k_big_F9F8, x);
    if (k > 0) {
        BITS_TO_FLOAT_F9F8(x, (ix & 0x807fffff) | (k << 23));
        return x;
    }
    if (k <= -25) {
        if (n > 50000)
            return k_big_F9F8 * copysignf_F9F8(k_big_F9F8, x);
        else
            return k_small_F9F8 * copysignf_F9F8(k_small_F9F8, x);
    }
    k += 25;
    BITS_TO_FLOAT_F9F8(x, (ix & 0x807fffff) | (k << 23));
    return x * k_2powm25_F9F8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040FB58);
#ifdef SKIP_ASM
typedef union { float f; int bits; } FloatBits_FB58;
#define FLOAT_TO_BITS_FB58(i, d) do { FloatBits_FB58 fb_; fb_.f = (d); (i) = fb_.bits; } while (0)
#define BITS_TO_FLOAT_FB58(d, i) do { FloatBits_FB58 fb_; fb_.bits = (i); (d) = fb_.f; } while (0)
float func_0040FB58(float x, float y) {
    int ix, iy;
    FLOAT_TO_BITS_FB58(ix, x);
    FLOAT_TO_BITS_FB58(iy, y);
    BITS_TO_FLOAT_FB58(x, (ix & 0x7fffffff) | (iy & 0x80000000));
    return x;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040FB88);
#ifdef SKIP_ASM
extern void (**D_0045343C[])(void);
void func_0040FB88(int a) {
    void (**p)(void);
    while (*D_0045343C[0]) {
        p = D_0045343C[0];
        p++;
        D_0045343C[0] = p;
        p[-1]();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040FBE0);
#ifdef SKIP_ASM
// 98.52%: crt __do_global_ctors; only s0/s1 swapped in the final call loop (counter should be $17, ptr $16)
typedef void (*func_ptr)(void);
extern func_ptr D_0043CE38[0];



void func_0040FBE0(void)
{
  unsigned long nptrs = (unsigned long) D_0043CE38[0];
  unsigned i;
  if (nptrs == (-1))
  {
    for (nptrs = 0; D_0043CE38[nptrs + 1] != 0; nptrs++)
    {
      ;
    }

  }
 do { for (i = nptrs; i >= 1; i--) { D_0043CE38[i](); } } while (0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FE810", func_0040FC90);
#ifdef SKIP_ASM
extern int D_0052AD98[];
extern void func_0040FBE0(void);
void func_0040FC90(void) {
    if (D_0052AD98[0] == 0) {
        D_0052AD98[0] = 1;
        func_0040FBE0();
    }
}
#endif

INCLUDE_ASM("seg/seg_2FE810", func_0040FCB0);
