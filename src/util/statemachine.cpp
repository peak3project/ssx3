#include "common.h"

//100%
INCLUDE_ASM("util/statemachine", cConsoleConfig_setTimeString);
#ifdef SKIP_ASM
extern "C" int func_002C27C0(char* buf, const char* fmt, ...);
extern "C" void func_002C25B8(char* dst, const char* src, int size);
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
    int one = 1;
    if (month != 2) {
        if (m >= 8) m++;
        return (m & one) ? 31 : 30;
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
extern "C" int func_002C7328_v(void*, int*, int*, int*, int) __asm__("func_002C7328");
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
        rem = func_002C7328_v(self, (int*)((char*)self + 0x10), (int*)((char*)self + 0xC), (int*)((char*)self + 8), ticks);
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

INCLUDE_ASM("util/statemachine", func_002C7478);

INCLUDE_ASM("util/statemachine", func_002C76C0);

