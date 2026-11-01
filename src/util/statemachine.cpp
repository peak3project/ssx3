#include "common.h"

//100%
INCLUDE_ASM("util/statemachine", cConsoleConfig_setTimeString);
#ifdef SKIP_ASM
extern "C" int func_002C27C0(char* buf, const char* fmt, ...);
extern "C" unsigned short* func_002C25B8(char* dst, const char* src, int size);
extern char D_00486500[];
extern char D_00486510[];
extern char D_00486528[];

extern "C" void cConsoleConfig_setTimeString(void* self, char* dst, int size, int hour, int min, int sec, int mode)
{
    char buf[0x40];
    switch (mode) {
    case 0:
        func_002C27C0(buf, D_00486500, hour, min, sec);
        break;
    case 1:
        if (hour < 12) {
            func_002C27C0(buf, D_00486510, hour, min, sec);
        } else {
            func_002C27C0(buf, D_00486528, hour % 13 - 12, min, sec);
        }
        break;
    }
    func_002C25B8(dst, buf, size);
}
#endif

//100%
INCLUDE_ASM("util/statemachine", func_002C7038);
#ifdef SKIP_ASM
extern char D_00486540[];
extern char D_00486550[];

extern "C" void func_002C7038(void* self, char* dst, int size, int a, int b, int c, int mode)
{
    char buf[0x40];
    switch (mode) {
    case 0:
        func_002C27C0(buf, D_00486540, c, b, a);
        break;
    case 1:
        func_002C27C0(buf, D_00486550, b, a, c);
        break;
    case 2:
        func_002C27C0(buf, D_00486550, a, b, c);
        break;
    }
    func_002C25B8(dst, buf, size);
}
#endif
//100%
INCLUDE_ASM("util/statemachine", func_002C7100);
#ifdef SKIP_ASM
extern "C" void func_002C73C0(void*);

extern "C" void func_002C7100(void *self, int *a, int *b, int *c) {
    func_002C73C0(self);
    *a = (*(int *)((char*)(self) + (8)));
    *b = (*(int *)((char*)(self) + (0xC)));
    *c = (*(int *)((char*)(self) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("util/statemachine", func_002C7160);
#ifdef SKIP_ASM
extern "C" void func_002C73C0(void*);

extern "C" void func_002C7160(void *self, int *a, int *b, int *c) {
    func_002C73C0(self);
    *a = (*(int *)((char*)(self) + (0x1C)));
    *b = (*(int *)((char*)(self) + (0x18)));
    *c = (*(int *)((char*)(self) + (0x14)));
}
#endif
//100%
INCLUDE_ASM("util/statemachine", func_002C71C0);
#ifdef SKIP_ASM
extern "C" int func_002C71C0(void* self, int year) {
    int leap;

    leap = 0;
    if (!(year & 3)) {
        leap = 1;
        if ((year % 100) == 0) {
            leap = (year % 400) == 0;
        }
    }
    return leap;
}
#endif

//100%
INCLUDE_ASM("util/statemachine", func_002C7208);
#ifdef SKIP_ASM
extern "C" int func_002C71C0(void* self, int a1);

extern "C" int func_002C7208(int self, int month, int year)
{
    int m = month;
    if (month != 2) {
        if (m >= 8) m++;
        return (m & 1) ? 31 : 30;
    }
    m = func_002C71C0((void*)self, year);
    return m == 0 ? 28 : 29;
}

#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/statemachine", func_002C7260);
#ifdef SKIP_ASM
extern "C" int func_002C7208(int, int, int);

extern "C" void func_002C7260(int self, int *day, int *month, int *year, int count) {
    int dim;
    int newMonth;
    int cur;
    int rest;

    if (count > 0) {
        do {
            dim = func_002C7208(self, *month, *year);
            cur = *day;
            if (dim < cur + count) {
                rest = count - 1;
                *day = 1;
                count = rest - (dim - cur);
                newMonth = *month + 1;
                *month = newMonth;
                if (newMonth >= 0xD) {
                    *month = 1;
                    *year += 1;
                }
            } else {
                *day = cur + count;
                count = 0;
            }
        } while (count > 0);
    }
}
#endif
//100%
INCLUDE_ASM("util/statemachine", func_002C7328);
#ifdef SKIP_ASM
extern "C" int func_002C7328(void* self, int* sec, int* min, int* hour, int add) {
    int total;
    int rem;
    int q;

    total = *hour * 0xE10 + *min * 0x3C + *sec + add;
    q = total / 86400;
    rem = total % 86400;
    *hour = (rem / 3600) % 24;
    *min = (rem / 60) % 60;
    *sec = rem % 60;
    return q;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("util/statemachine", func_002C73C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_002C7328(void*, int*, int*, int*, int);
extern "C" void func_002C7260_v(void*, int*, int*, int*, int) __asm__("func_002C7260");
extern char* D_004A28A8;

extern "C" void func_002C73C0(void* self) {
    int rem;
    int now;
    int ticks;

    now = *(int*)(D_004A28A8 + 0x18);
    ticks = (now - *(int*)((char*)self + 0x20)) / *(int*)(D_004A28A8 + 0x10);
    if (ticks != 0) {
        *(int*)((char*)self + 0x20) = now;
        rem = func_002C7328(self, (int*)((char*)self + 0x10), (int*)((char*)self + 0xC), (int*)((char*)self + 8), ticks);
        if (rem != 0) {
            func_002C7260_v(self, (int*)((char*)self + 0x1C), (int*)((char*)self + 0x18), (int*)((char*)self + 0x14), rem);
        }
    }
}
#endif

//100%
INCLUDE_ASM("util/statemachine", func_002C7440);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002C7478(void* self);
extern char D_00486560[];

extern "C" void* func_002C7440(void)
{
    return func_002C7478(cMemMan_alloc(0x38, D_00486560, 0, 0));
}
#endif

//100%
INCLUDE_ASM("util/statemachine", func_002C7478);
#ifdef SKIP_ASM
struct sClockK7478 { unsigned char b[8]; };
extern "C" int func_0040BAA8(void);
extern "C" int func_0040B9E8(void);
extern "C" int func_0040BB38(void);
extern "C" int func_0040BC08(void);
extern "C" int func_00402520_clk(sClockK7478* c) __asm__("func_00402520");
extern "C" void func_0040BFE0_clk(sClockK7478* c) __asm__("func_0040BFE0");
extern void* D_00486798[];
extern char* D_004A28A8;

static inline int bcdK7478(unsigned char v)
{
    return (v & 0xF) + (v >> 4) * 10;
}

extern "C" void* func_002C7478(void* self)
{
    int* s = (int*)self;
    s[13] = (int)D_00486798;
    s[9] = 0;
    switch (func_0040BAA8()) {
    case 0:
        s[10] = 1;
        break;
    case 1:
        s[10] = 0;
        break;
    default:
        s[10] = 0;
        break;
    }
    s[11] = 1;
    switch (func_0040B9E8()) {
    case 0: s[12] = 0; break;
    case 1: s[12] = 1; break;
    case 2: s[12] = 2; break;
    case 3: s[12] = 3; break;
    case 4: s[12] = 4; break;
    case 5: s[12] = 5; break;
    case 6: s[12] = 6; break;
    case 7: s[12] = 7; break;
    default: s[12] = 1; break;
    }
    int m = func_0040BB38();
    switch (m) {
    case 0:
        s[0] = 0;
        break;
    case 1:
        s[0] = 1;
        break;
    case 2:
        s[0] = 2;
        break;
    default:
        s[0] = 0;
        break;
    }
    int h = func_0040BC08();
    switch (h) {
    case 0:
        s[1] = 0;
        break;
    case 1:
        s[1] = 1;
        break;
    default:
        s[1] = 0;
        break;
    }
    sClockK7478 c;
    if (func_00402520_clk(&c)) {
        func_0040BFE0_clk(&c);
        s[2] = bcdK7478(c.b[3]);
        s[3] = bcdK7478(c.b[2]);
        s[4] = bcdK7478(c.b[1]);
        s[5] = bcdK7478(c.b[7]) + 2000;
        s[6] = bcdK7478(c.b[6]);
        s[7] = bcdK7478(c.b[5]);
    } else {
        s[5] = 0x7D3;
        s[6] = 10;
        s[7] = 14;
        s[2] = 0;
        s[3] = 0;
        s[4] = 0;
    }
    s[8] = *(int*)(D_004A28A8 + 0x18);
    return self;
}
#endif

INCLUDE_ASM("util/statemachine", func_002C76C0);

