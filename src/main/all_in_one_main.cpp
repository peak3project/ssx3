#include "common.h"

//100%
INCLUDE_ASM("main/all_in_one_main", __sti__all_in_one_main_cpp);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;

void func_002CAA58(void*);
extern "C" void cMenu_addItem(void *, char*, int);
extern "C" void func_002CCF98(char*, int, int *, int);
void cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* label);
void cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* height);

extern char D_0046D3D0[];
extern char D_00467DA8[];
extern char D_00467DC0[];
extern char D_00467DC8[];
extern int D_00467DD0[];
extern int D_00467DD8[];

extern "C" char* __sti__all_in_one_main_cpp(char* self, int* a, int* b)
{
    char* item0 = self + 0x138;
    char* item1 = self + 0x154;
    char* item2 = self + 0x170;
    char* item3 = self + 0x18C;
    char* item4 = self + 0x1A4;
    char* item5 = self + 0x1C8;
    func_002CAA58(self);
    *(char**)(self + 0x12C) = D_0046D3D0;
    *(int*)(self + 0x130) = *a;
    *(int*)(self + 0x134) = *b;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)item0, D_00467DA8);
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)item1, D_00467DC0);
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)item2, D_00467DC8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)item3, (void*)0xE);
    func_002CCF98(item4, 0, D_00467DD0, 0);
    func_002CCF98(item5, 1, D_00467DD8, 0);
    cMenu_addItem(self, item0, -1);
    cMenu_addItem(self, item1, -1);
    cMenu_addItem(self, item2, -1);
    cMenu_addItem(self, item3, -1);
    cMenu_addItem(self, item4, -1);
    cMenu_addItem(self, item5, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DB2B0);
#ifdef SKIP_ASM
void func_002CAA58(void*);
extern "C" void func_002CCF98(char*, int, int *, int);
extern "C" void cMenu_addItem(void *, char*, int);
extern int D_00467DE0[];
extern int D_0046D378[];

extern "C" void *func_001DB2B0(char *arg0, int *arg1) {
    func_002CAA58(arg0);
    char *p = arg0 + 0x134;
    *(int **)(arg0 + 0x12C) = D_0046D378;
    *(int *)(arg0 + 0x130) = *arg1;
    func_002CCF98(p, 0, D_00467DE0, 0);
    cMenu_addItem(arg0, p, -1);
    return arg0;
}
#endif

INCLUDE_ASM("main/all_in_one_main", func_001DB330);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/all_in_one_main", func_001DB418);
#ifdef SKIP_ASM
struct MenuItem_B418 {
    char pad0[8];
    int index;          // 0x08
    char padC[8];
    int data;           // 0x14
    char pad18[0xC];
};

struct Menu_B418 {
    char pad0[0x2E8];
    char sub2E8[0x518 - 0x2E8];     // 0x2E8
    MenuItem_B418 items[4];         // 0x518
    char item5A8[0x1C];             // 0x5A8
    char item5C4[0x1C];             // 0x5C4
};

struct Src_B418 {
    char pad0[0x6C];
    int count;          // 0x6C
    int ids[4];         // 0x70
};

extern "C" void func_002CA388(void* item, int enable);
extern "C" void func_001DB330(void* sub, Src_B418* src);

extern "C" void func_001DB418(Menu_B418* self, Src_B418* src)
{
    int i = 0;
    for (; i < src->count; i++) {
        int id = src->ids[i];
        MenuItem_B418* it = &self->items[i];
        it->data = id;
        func_002CA388(it, 1);
        it->index = i;
    }
    for (; i < 4; i++) {
        func_002CA388(&self->items[i], 0);
    }
    func_001DB330(self->sub2E8, src);
    func_002CA388(self->item5C4, src->count >= 2);
    func_002CA388(self->item5A8, src->count < 4);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DB528);
#ifdef SKIP_ASM
struct MenuItem_B528 {
    char pad0[8];
    int index;          // 0x08
    char padC[8];
    void* data;         // 0x14
    char pad18[0xC];
};

struct Menu_B528 {
    char pad0[0x168];
    MenuItem_B528 items[12];    // 0x168
};

extern "C" int func_0025F120(void* src);
extern "C" void* func_0025F150(void* src, int i);
extern "C" void func_002CA388(void* item, int enable);
extern char D_00467DE8[];

extern "C" void func_001DB528(Menu_B528* self, void* src)
{
    int i = 0;
    int n = func_0025F120(src);
    for (; i < n; i++) {
        MenuItem_B528* it = &self->items[i];
        it->data = func_0025F150(src, i);
        func_002CA388(it, 1);
        it->index = i;
    }
    if (i == 0) {
        self->items[0].data = D_00467DE8;
        i = 1;
        func_002CA388(&self->items[0], 1);
        self->items[0].index = -1;
    }
    for (; i < 12; i++) {
        func_002CA388(&self->items[i], 0);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DB620);
#ifdef SKIP_ASM
struct MenuItem_B620 {
    char pad0[8];
    int index;          // 0x08
    char padC[8];
    void* data;         // 0x14
    char pad18[0xC];
};

struct Menu_B620 {
    char pad0[0x16C];
    MenuItem_B620 items[24];    // 0x16C
};

extern "C" int func_0025F1B0(void* src);
extern "C" void* func_0025F1E0(void* src, int i, int flags);
extern "C" void func_002CA388(void* item, int enable);
extern char D_00467E00[];

extern "C" void func_001DB620(Menu_B620* self, void* src)
{
    int i = 0;
    int n = func_0025F1B0(src);
    for (; i < n; i++) {
        MenuItem_B620* it = &self->items[i];
        it->data = func_0025F1E0(src, i, 0);
        func_002CA388(it, 1);
        it->index = i;
    }
    if (i == 0) {
        self->items[0].data = D_00467E00;
        i = 1;
        func_002CA388(&self->items[0], 1);
        self->items[0].index = -1;
    }
    for (; i < 24; i++) {
        func_002CA388(&self->items[i], 0);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DB718);
#ifdef SKIP_ASM
void operator_delete(int*);
struct N_B718 { N_B718 *next; N_B718 *prev; };
struct L_B718 { int pad; N_B718 *head; };

extern "C" void func_001DB718(L_B718 *self) {
    N_B718 *p = self->head->next;
    while (p != self->head) {
        N_B718 *n = p;
        p = p->next;
        operator_delete((int *)n);
    }
    self->head->next = self->head;
    self->head->prev = self->head;
}
#endif

INCLUDE_ASM("main/all_in_one_main", func_001DB778);

INCLUDE_ASM("main/all_in_one_main", func_001DB918);

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBAB8);
#ifdef SKIP_ASM
extern "C" void func_0017E558(int);

extern "C" int func_001DBAB8(void *arg0) {
    func_0017E558((*(int *)((char*)(arg0) + (0x130))));
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBAD8);
#ifdef SKIP_ASM
extern "C" void func_0017E490(int);
extern "C" void func_0017E4F0(int);

extern "C" int func_001DBAD8(void *arg0, void *arg1) {
    int temp_3;

    temp_3 = (*(int *)((char*)(arg1) + (8)));
    if (temp_3 == 0) {
        func_0017E490((*(int *)((char*)(arg0) + (0x130))));
    } else if (temp_3 == 1) {
        func_0017E4F0((*(int *)((char*)(arg0) + (0x134))));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBB20);
#ifdef SKIP_ASM
extern "C" void func_0017E418(int, int);

extern "C" int func_001DBB20(void *arg0, void *arg1) {
    func_0017E418((*(int *)((char*)(arg0) + (0x130))), (*(int *)((char*)(arg1) + (0x14))));
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBB48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0017E368_BB48(int, int) __asm__("func_0017E368");
extern "C" void func_0017E3B8_BB48(int) __asm__("func_0017E3B8");

extern "C" int func_001DBB48(void *arg0, void *arg1) {
    int t = *(int *)((char *)arg1 + 8);
    if (t == -2) {
        func_0017E3B8_BB48(*(int *)((char *)arg0 + 0x134));
    } else if (t != -1) {
        func_0017E368_BB48(*(int *)((char *)arg0 + 0x130), t);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBB90);
#ifdef SKIP_ASM
extern "C" void func_0017E2F8(int, int);

extern "C" int func_001DBB90(void *arg0, void *arg1) {
    int temp_5;

    temp_5 = (*(int *)((char*)(arg1) + (8)));
    if (temp_5 >= 0) {
        func_0017E2F8((*(int *)((char*)(arg0) + (0x130))), temp_5);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBBC0);
#ifdef SKIP_ASM
extern "C" void func_0017E290(int, int);

extern "C" int func_001DBBC0(void *arg0, void *arg1) {
    func_0017E290((*(int *)((char*)(arg0) + (0x4E0))), (*(int *)((char*)(arg1) + (8))));
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBBE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0017E1C0_BBE8(int, void *) __asm__("func_0017E1C0");

extern "C" int func_001DBBE8(char *arg0) {
    func_0017E1C0_BBE8(*(int *)(arg0 + 0x130), arg0 + 0x180);
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBC10);
#ifdef SKIP_ASM
extern "C" void func_0017E228(int, int);

extern "C" int func_001DBC10(void *arg0, void *arg1) {
    func_0017E228((*(int *)((char*)(arg0) + (0x130))), (*(int *)((char*)(arg1) + (8))));
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBC38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0017E030_BC38(int, char*, char*) __asm__("func_0017E030");

extern "C" int func_001DBC38(char *self) {
    func_0017E030_BC38(*(int*)(self + 0x130), self + 0x180, self + 0x1AC);
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DBC68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0017E118_BC68(int, char*, char*) __asm__("func_0017E118");

extern "C" int func_001DBC68(char *self) {
    func_0017E118_BC68(*(int*)(self + 0x130), self + 0x180, self + 0x1AC);
    return 0;
}
#endif

INCLUDE_ASM("main/all_in_one_main", func_001DBC98);

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DC900);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_0046D970[];

extern "C" void func_001DC900(void *self, int flags) {
    *(void***)((char*)self + 0) = D_0046D970;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void func_001DC930(void) {
}

extern "C" void func_001DC938(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DC940);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_0046D948[];

extern "C" void func_001DC940(void *self, int flags) {
    *(void***)((char*)self + 0) = D_0046D948;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DC970);
#ifdef SKIP_ASM
extern "C" int func_001DC970(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DC978);
#ifdef SKIP_ASM
extern "C" int func_001DC978(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DC980);
#ifdef SKIP_ASM
extern "C" void func_001DC980(void *arg0) {
    (*(int *)((char*)(arg0) + (0x14))) = (int) (*(int *)((char*)(arg0) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DC990);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
typedef char* func_001DC990_va_list;
#define func_001DC990_va_start(ap)                                                \
    (ap = (char*)__builtin_next_arg()                                    \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

extern "C" void func_00391C48_C990(int, int, char*) __asm__("func_00391C48");

extern "C" void func_001DC990(float x, float y, int c, int d, ...)
{
    func_001DC990_va_list ap;
    func_001DC990_va_start(ap);
    func_00391C48_C990(c, d, ap);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DC9D0);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
#define func_001DC9D0_va_start(ap)                                       \
    (ap = (char*)__builtin_next_arg()                                    \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

extern "C" void func_00391C48_C9D0(void *, int, char *) __asm__("func_00391C48");

struct V2_C9D0 { float x, y; };

extern "C" void func_001DC9D0(void *self, int d, float p0, float p1, float sx, float sy, ...)
{
    char *ap;
    func_001DC9D0_va_start(ap);
    *(float *)((char *)self + 0x38) = *(float *)((char *)self + 0x30) * sx;
    *(float *)((char *)self + 0x3C) = *(float *)((char *)self + 0x34) * sy;
    func_00391C48_C9D0(self, d, ap);
    *(V2_C9D0 *)((char *)self + 0x38) = *(V2_C9D0 *)((char *)self + 0x30);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCA40);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
typedef char* func_001DCA40_va_list;
#define func_001DCA40_va_start(ap)                                                \
    (ap = (char*)__builtin_next_arg()                                    \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

extern "C" void func_003929F8_CA40(int, int, char*) __asm__("func_003929F8");

extern "C" void func_001DCA40(float x, float y, int c, int d, ...)
{
    func_001DCA40_va_list ap;
    func_001DCA40_va_start(ap);
    func_003929F8_CA40(c, d, ap);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCA80);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
typedef char* func_001DCA80_va_list;
#define func_001DCA80_va_start(ap)                                                \
    (ap = (char*)__builtin_next_arg()                                    \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

extern "C" void func_00392B40_CA80(int, int, char*) __asm__("func_00392B40");

extern "C" void func_001DCA80(float x, float y, int c, int d, ...)
{
    func_001DCA80_va_list ap;
    func_001DCA80_va_start(ap);
    func_00392B40_CA80(c, d, ap);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCAC0);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_0045B8B0[];

extern "C" void func_001DCAC0(void *self, int flags) {
    *(void***)((char*)self + 0x90) = D_0045B8B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCAF0);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void *, int);
extern int D_0046D8C0[];

extern "C" void func_001DCAF0(char *arg0, int arg1) {
    *(int **)(arg0 + 0xC) = D_0046D8C0;
    cBXString__cBXString(arg0 + 8, 2);
    cBXString__cBXString(arg0 + 4, 2);
    cBXString__cBXString(arg0, 2);
    if (arg1 & 1) {
        operator_delete((int*)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCB60);
#ifdef SKIP_ASM
extern "C" int func_001DCB60(int arg0) {
    return arg0 + 0x10;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCB68);
#ifdef SKIP_ASM
extern "C" int func_001DCB68(int arg0) {
    return arg0 + 0x10;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCB70);
#ifdef SKIP_ASM
extern "C" void func_001A0538(int);

extern "C" void func_001DCB70(int arg0) {
    func_001A0538(arg0 + 0xB0);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCB90);
#ifdef SKIP_ASM
extern "C" void func_001A0548(int);

extern "C" void func_001DCB90(int arg0) {
    func_001A0548(arg0 + 0xB0);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCBB0);
#ifdef SKIP_ASM
extern "C" int func_001DCBB0(int arg0) {
    return arg0 + 0xB0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCBB8);
#ifdef SKIP_ASM
extern "C" int func_001DCBB8(int arg0) {
    return arg0 + 0xB0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCBC0);
#ifdef SKIP_ASM
extern "C" int func_001DCBC0(int arg0) {
    return arg0 + 0x1A70;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCBC8);
#ifdef SKIP_ASM
extern "C" int func_001DCBC8(int arg0) {
    return arg0 + 0x1A70;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCBD0);
#ifdef SKIP_ASM
extern "C" int func_001DCBD0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCBD8);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_0046D848[];

extern "C" void func_001DCBD8(void *self, int flags) {
    *(void***)((char*)self + 4) = D_0046D848;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCC08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001E1090_CC08(void*, int) __asm__("func_001E1090");

extern "C" void func_001DCC08(signed char *self, signed char v) {
    *self = v;
    func_001E1090_CC08(self, v == 2);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCC38);
#ifdef SKIP_ASM
extern "C" void func_001DCC38(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (1))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCC40);
#ifdef SKIP_ASM
extern "C" unsigned char *func_001DCC40(unsigned char *arg0) {
    *arg0 &= 0xE0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCC58);
#ifdef SKIP_ASM
extern "C" int func_001DCC58(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCC60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_0046D810_CC60[] __asm__("D_0046D810");

extern "C" void *func_001DCC60(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(void ***)((char*)(arg0) + (4))) = D_0046D810_CC60;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCC78);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_0046DD28[];

extern "C" void func_001DCC78(void *self, int flags) {
    *(void***)((char*)self + 4) = D_0046DD28;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void func_001DCCA8(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCCB0);
#ifdef SKIP_ASM
extern "C" void func_001DCCB0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCCB8);
#ifdef SKIP_ASM
extern int D_004A19C4;

extern "C" void func_001DCCB8(int arg0) {
    D_004A19C4 = arg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCCC0);
#ifdef SKIP_ASM
extern int D_004A19C4;

extern "C" int func_001DCCC0(void) {
    return D_004A19C4;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCCC8);
#ifdef SKIP_ASM
extern int D_004A19CC;

extern "C" void func_001DCCC8(void) {
    D_004A19CC |= 4;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCCD8);
#ifdef SKIP_ASM
extern "C" int func_001DCCD8(int arg0) {
    return arg0 + 0xB5AB0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCCE8);
#ifdef SKIP_ASM
extern "C" int func_001DCCE8(int arg0) {
    return arg0 + 0xB5ABC;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCCF8);
#ifdef SKIP_ASM
extern "C" void func_001DCCF8(int *arg0, int arg1) {
    *arg0 = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCD00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0017ABE0_CD00(void *, int) __asm__("func_0017ABE0");
void operator_delete(int*);
extern void* D_0046D948[];


extern "C" void func_001DCD00(void *self, int flags) {
    func_0017ABE0_CD00((char *)self + 0x8C10, 2);
    *(void ***)self = D_0046D948;
    if (flags & 1) {
        operator_delete((int *)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCD58);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_001DCD58(int arg0, int arg1) {
    func_002CA280(arg0 + 0x130, 2);
    func_002CAA80(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCDA0);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_001DCDA0(int arg0, int arg1) {
    func_002CA280(arg0 + 0x1E4, 2);
    func_002CA280(arg0 + 0x1C0, 2);
    func_002CA280(arg0 + 0x194, 2);
    func_002CA280(arg0 + 0x168, 2);
    func_002CA280(arg0 + 0x150, 2);
    func_002CA280(arg0 + 0x134, 2);
    func_002CAA80(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCE20);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_001DCE20(int arg0, int arg1) {
    func_002CA280(arg0 + 0x1E4, 2);
    func_002CA280(arg0 + 0x1C0, 2);
    func_002CA280(arg0 + 0x194, 2);
    func_002CA280(arg0 + 0x168, 2);
    func_002CA280(arg0 + 0x150, 2);
    func_002CA280(arg0 + 0x134, 2);
    func_002CAA80(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCEA0);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

// PORT: pointers passed as int (unit declares the callees with int parameters)
static inline void SubMenuB_CEA0(int m)
{
    func_002CA280(m + 0x24C, 2);
    func_002CA280(m + 0x230, 2);
    func_002CA280(m + 0x218, 2);
    func_002CA280(m + 0x1FC, 2);
    func_002CA280(m + 0x1E4, 2);
    func_002CA280(m + 0x1C0, 2);
    func_002CA280(m + 0x194, 2);
    func_002CA280(m + 0x168, 2);
    func_002CA280(m + 0x150, 2);
    func_002CA280(m + 0x134, 2);
    func_002CAA80(m, 2);
}

static inline void SubMenuA_CEA0(int m)
{
    SubMenuB_CEA0(m + 0x1FC);
    func_002CA280(m + 0x1E4, 2);
    func_002CA280(m + 0x1C0, 2);
    func_002CA280(m + 0x194, 2);
    func_002CA280(m + 0x168, 2);
    func_002CA280(m + 0x150, 2);
    func_002CA280(m + 0x134, 2);
    func_002CAA80(m, 2);
}

extern "C" void func_001DCEA0(int self, int arg)
{
    SubMenuA_CEA0(self + 0x130);
    func_002CAA80(self, arg);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DCFC8);
#ifdef SKIP_ASM
struct VEnt { short delta; short idx; void (*fn)(void*, int); };
struct VTab { int a; int b; VEnt dtor; };
struct Elem { char pad[0x10]; VTab *vt; char pad2[0x24 - 0x14]; };
struct Obj { char pad[0x168]; Elem elems[4]; };
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_001DCFC8(Obj *self, int flags) {
    if (self->elems != 0) {
        Elem *end = self->elems + 4;
        Elem *p = end;
        while (self->elems != p) {
            p--;
            p->vt->dtor.fn((char*)p + p->vt->dtor.delta, 0);
        }
    }
    func_002CA280((int)self + 0x150, 2);
    func_002CA280((int)self + 0x134, 2);
    func_002CAA80((int)self, flags);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD060);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_001DD060(int arg0, int arg1) {
    func_002CA280(arg0 + 0x194, 2);
    func_002CA280(arg0 + 0x168, 2);
    func_002CA280(arg0 + 0x150, 2);
    func_002CA280(arg0 + 0x134, 2);
    func_002CAA80(arg0, arg1);
}
#endif

INCLUDE_ASM("main/all_in_one_main", func_001DD0C8);

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD258);
#ifdef SKIP_ASM
struct VEnt_D258 { short delta; short idx; void (*fn)(void*, int); };
struct VTab_D258 { int a; int b; VEnt_D258 dtor; };
struct Elem_D258 { char pad[0x10]; VTab_D258 *vt; char pad2[0x24 - 0x14]; };
struct Obj_D258 { char pad[0x168]; Elem_D258 elems[12]; };

extern "C" void func_001DD258(Obj_D258 *self, int flags) {
    if (self->elems != 0) {
        Elem_D258 *end = self->elems + 12;
        Elem_D258 *p = end;
        while (self->elems != p) {
            p--;
            p->vt->dtor.fn((char*)p + p->vt->dtor.delta, 0);
        }
    }
    func_002CA280((int)self + 0x150, 2);
    func_002CA280((int)self + 0x134, 2);
    func_002CAA80((int)self, flags);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD2F0);
#ifdef SKIP_ASM
struct VEnt_D2F0 { short delta; short idx; void (*fn)(void*, int); };
struct VTab_D2F0 { int a; int b; VEnt_D2F0 dtor; };
struct Elem_D2F0 { char pad[0x10]; VTab_D2F0 *vt; char pad2[0x24 - 0x14]; };
struct Obj_D2F0 { char pad[0x16C]; Elem_D2F0 elems[24]; };

extern "C" void func_001DD2F0(Obj_D2F0 *self, int flags) {
    func_002CA280((int)self + 0x4CC, 2);
    if (self->elems != 0) {
        Elem_D2F0 *p = self->elems + 24;
        while (self->elems != p) {
            p--;
            p->vt->dtor.fn((char*)p + p->vt->dtor.delta, 0);
        }
    }
    func_002CA280((int)self + 0x154, 2);
    func_002CA280((int)self + 0x138, 2);
    func_002CAA80((int)self, flags);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD398);
#ifdef SKIP_ASM
struct VEnt_D398 { short delta; short idx; void (*fn)(void*, int); };
struct VTab_D398 { int a; int b; VEnt_D398 dtor; };
struct Elem_D398 { char pad[0x10]; VTab_D398 *vt; char pad2[0x24 - 0x14]; };
struct Obj_D398 { char pad[0x194]; Elem_D398 elems[14]; };

extern "C" void func_001DD398(Obj_D398 *self, int flags) {
    if (self->elems != 0) {
        Elem_D398 *p = self->elems + 14;
        while (self->elems != p) {
            p--;
            p->vt->dtor.fn((char*)p + p->vt->dtor.delta, 0);
        }
    }
    func_002CA280((int)self + 0x168, 2);
    func_002CA280((int)self + 0x150, 2);
    func_002CA280((int)self + 0x134, 2);
    func_002CAA80((int)self, flags);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD440);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_001DD440(int arg0, int arg1) {
    func_002CA280(arg0 + 0x1C8, 2);
    func_002CA280(arg0 + 0x1A4, 2);
    func_002CA280(arg0 + 0x18C, 2);
    func_002CA280(arg0 + 0x170, 2);
    func_002CA280(arg0 + 0x154, 2);
    func_002CA280(arg0 + 0x138, 2);
    func_002CAA80(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD4C0);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_001DD4C0(int arg0, int arg1) {
    func_002CA280(arg0 + 0x134, 2);
    func_002CAA80(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD508);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_0046D1D0_D508[] __asm__("D_0046D1D0");

extern "C" void *func_001DD508(void *arg0) {
    (*(signed char *)((char*)(arg0) + (4))) = 0;
    (*(void ***)((char*)(arg0) + (8))) = D_0046D1D0_D508;
    (*(int *)((char*)(arg0) + (0x18))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD530);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_0046DBA8[];

extern "C" void func_001DD530(void *self, int flags) {
    *(void***)((char*)self + 8) = D_0046DBA8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD560);
#ifdef SKIP_ASM
extern "C" int func_001DD560(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD568);
#ifdef SKIP_ASM
extern "C" int func_001DD568(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD570);
#ifdef SKIP_ASM
extern "C" int func_001DD570(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD578);
#ifdef SKIP_ASM
extern "C" int func_001DD578(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD580);
#ifdef SKIP_ASM
extern "C" unsigned short *func_001DD580(unsigned short *arg0) {
    *arg0 = (*arg0 | 1) & 0xFFFD;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD598);
#ifdef SKIP_ASM
extern "C" void func_0039C558();

extern "C" void func_001DD598(void) {
    func_0039C558();
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD5B8);
#ifdef SKIP_ASM
extern "C" void func_003977E8(void *);
extern "C" int func_0039FB30(void *, int, int);
extern int D_0046D1A0[];
extern int D_00494670[];
extern int D_004949E8[];

extern "C" void *func_001DD5B8(char *self) {
    *(char **)(self + 4) = self;
    *(char **)(self + 0) = self;
    *(int *)(self + 0xC) = 0;
    *(int *)(self + 0x10) = 0;
    *(int **)(self + 8) = D_00494670;
    func_001DD580((unsigned short*)(self + 0x14));
    func_003977E8(self + 0x18);
    *(int *)(self + 0x34) = 0;
    *(int *)(self + 0x38) = 0;
    *(int *)(self + 0x3C) = 0;
    func_0039FB30(self + 0x40, 0, 0);
    *(int **)(self + 0x48) = D_004949E8;
    func_003977E8(self + 0xB4);
    *(int *)(self + 0xD0) = 0;
    *(int **)(self + 8) = D_0046D1A0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD648);
#ifdef SKIP_ASM
extern "C" int func_001DD648(int arg0) {
    return arg0 + 0xEC;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD650);
#ifdef SKIP_ASM
extern "C" int func_001DD650(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x170)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD658);
#ifdef SKIP_ASM
extern "C" void func_001DD658(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xD8))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD660);
#ifdef SKIP_ASM
extern "C" void func_001DD660(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xDC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD668);
#ifdef SKIP_ASM
extern "C" void func_001DD668(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xE0))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD670);
#ifdef SKIP_ASM
extern "C" void func_001DD670(void *arg0) {
    int temp_3;

    temp_3 = (*(int *)((char*)(arg0) + (0x16C))) + 1;
    if (temp_3 < (*(int *)((char*)(arg0) + (0xD4)))) {
        (*(int *)((char*)(arg0) + (0x16C))) = temp_3;
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD690);
#ifdef SKIP_ASM
extern "C" void func_001DD690(void *arg0) {
    int temp_2;

    temp_2 = (*(int *)((char*)(arg0) + (0x16C)));
    if (temp_2 > 0) {
        (*(int *)((char*)(arg0) + (0x16C))) = (int) (temp_2 - 1);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD6A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_D6A8(void*, int) __asm__("func_0039E2A0");
extern void* D_0046D0D0[];

extern "C" void* func_001DD6A8(void *self) {
    func_0039E2A0_D6A8(self, 0);
    *(void***)((char*)self + 8) = D_0046D0D0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD6E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_D6E0(void*) __asm__("func_0039E2A0");
extern void* D_0046D0D0[];

extern "C" void* func_001DD6E0(void *self) {
    func_0039E2A0_D6E0(self);
    *(void***)((char*)self + 8) = D_0046D0D0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD718);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E318_D718(void*) __asm__("func_0039E318");
extern void* D_0046D0D0[];

extern "C" void* func_001DD718(void *self) {
    func_0039E318_D718(self);
    *(void***)((char*)self + 8) = D_0046D0D0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD750);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DD750(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DD750(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DD750(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD778);
#ifdef SKIP_ASM
extern "C" int func_001A1CD0(int, signed char);

extern "C" void func_001DD778(char *self, signed char n) {
    int i = 0;
    int mask = 0xFF;
    int h = **(int **)(self + 0x10);
    if (n > 0) {
        do {
            mask &= ~func_001A1CD0(h, i);
            i++;
        } while (i < n);
    }
    *(char *)(self + 0x15) = mask;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD800);
#ifdef SKIP_ASM
extern "C" void func_001A1CB8(int, signed char, int);

extern "C" void func_001DD800(void *arg0, signed char arg1, signed char arg2) {
    func_001A1CB8(*(*(int **)((char*)(arg0) + (0x10))), arg1, (1 << arg2) & 0xFF);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD840);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DD840(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DD840(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DD840(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD868);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DD868(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DD868(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DD868(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD890);
#ifdef SKIP_ASM
extern "C" int func_001DD890(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x74)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD898);
#ifdef SKIP_ASM
extern "C" int func_001DD898(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x70)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD8A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DD8A0(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DD8A0(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DD8A0(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD8C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DD8C8(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DD8C8(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DD8C8(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD8F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DD8F0(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DD8F0(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DD8F0(self);
}
#endif

extern "C" void func_001DD918(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD920);
#ifdef SKIP_ASM
extern "C" void func_001DD920(int *arg0, int arg1) {
    *arg0 = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD928);
#ifdef SKIP_ASM
extern "C" int func_001DD928(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD930);
#ifdef SKIP_ASM
extern "C" void func_001DD930(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x94))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD938);
#ifdef SKIP_ASM
extern "C" int func_001DD938(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x94)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD940);
#ifdef SKIP_ASM
extern "C" void func_001DD940(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x98))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD948);
#ifdef SKIP_ASM
extern "C" int func_001DD948(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x98)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD950);
#ifdef SKIP_ASM
struct V3_D950 { float x, y, z; };
extern "C" void func_001DD950(void *self, V3_D950 v) {
    *(V3_D950 *)((char *)self + 0x9C) = v;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD990);
#ifdef SKIP_ASM
struct V12_D990 { int a; int b; int c; };
extern "C" V12_D990* func_001DD990(V12_D990* dst, char* src) {
    *dst = *(V12_D990*)(src + 0x9C);
    return dst;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9B0);
#ifdef SKIP_ASM
extern "C" void func_001DD9B0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xAC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9B8);
#ifdef SKIP_ASM
extern "C" int func_001DD9B8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xAC)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9C0);
#ifdef SKIP_ASM
extern "C" void func_001DD9C0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xA8))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9C8);
#ifdef SKIP_ASM
extern "C" int func_001DD9C8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA8)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9D0);
#ifdef SKIP_ASM
extern "C" void func_001DD9D0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x90))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9D8);
#ifdef SKIP_ASM
extern "C" int func_001DD9D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x90)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9E0);
#ifdef SKIP_ASM
extern "C" void func_001DD9E0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC0))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9E8);
#ifdef SKIP_ASM
extern "C" int func_001DD9E8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC0)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9F0);
#ifdef SKIP_ASM
extern "C" void func_001DD9F0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DD9F8);
#ifdef SKIP_ASM
extern "C" int func_001DD9F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC4)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA00);
#ifdef SKIP_ASM
extern "C" void func_001DDA00(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0xB0))) = fparg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA08);
#ifdef SKIP_ASM
extern "C" float func_001DDA08(void *arg0) {
    return (*(float *)((char*)(arg0) + (0xB0)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA10);
#ifdef SKIP_ASM
extern "C" void func_001DDA10(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xB8))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA18);
#ifdef SKIP_ASM
extern "C" int func_001DDA18(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB8)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA20);
#ifdef SKIP_ASM
extern "C" void func_001DDA20(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xBC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA28);
#ifdef SKIP_ASM
extern "C" int func_001DDA28(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xBC)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA30);
#ifdef SKIP_ASM
extern "C" void func_001DDA30(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
    (*(int *)((char*)(arg0) + (4))) = 2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA40);
#ifdef SKIP_ASM
extern "C" void func_001DDA40(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
    (*(int *)((char*)(arg0) + (4))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA50);
#ifdef SKIP_ASM
extern "C" void func_001DDA50(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
    (*(int *)((char*)(arg0) + (4))) = 3;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA60);
#ifdef SKIP_ASM
struct V8_DA60 { int a; int b; };
extern "C" void func_001DDA60(V8_DA60* dst, V8_DA60* src) {
    *(V8_DA60*)((char*)dst + 4) = *src;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA78);
#ifdef SKIP_ASM
extern "C" int func_001DDA78(int arg0) {
    return arg0 + 4;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA80);
#ifdef SKIP_ASM
extern "C" void func_001DDA80(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
    (*(int *)((char*)(arg0) + (0xC))) = 2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDA90);
#ifdef SKIP_ASM
extern "C" void func_001DDA90(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
    (*(int *)((char*)(arg0) + (0xC))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDAA0);
#ifdef SKIP_ASM
extern "C" void func_001DDAA0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
    (*(int *)((char*)(arg0) + (0xC))) = 3;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDAB0);
#ifdef SKIP_ASM
struct V8_DDAB0 { int a; int b; };
extern "C" void func_001DDAB0(V8_DDAB0* dst, V8_DDAB0* src) {
    *(V8_DDAB0*)((char*)dst + 0xC) = *src;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDAC8);
#ifdef SKIP_ASM
extern "C" int func_001DDAC8(int arg0) {
    return arg0 + 0xC;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDAD0);
#ifdef SKIP_ASM
extern "C" void func_001DDAD0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
    (*(int *)((char*)(arg0) + (0x14))) = 2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDAE0);
#ifdef SKIP_ASM
extern "C" void func_001DDAE0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
    (*(int *)((char*)(arg0) + (0x14))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDAF0);
#ifdef SKIP_ASM
extern "C" void func_001DDAF0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
    (*(int *)((char*)(arg0) + (0x14))) = 3;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB00);
#ifdef SKIP_ASM
struct V8_DDB00 { int a; int b; };
extern "C" void func_001DDB00(V8_DDB00* dst, V8_DDB00* src) {
    *(V8_DDB00*)((char*)dst + 0x14) = *src;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB18);
#ifdef SKIP_ASM
extern "C" int func_001DDB18(int arg0) {
    return arg0 + 0x14;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB20);
#ifdef SKIP_ASM
extern "C" void func_001DDB20(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
    (*(int *)((char*)(arg0) + (0x1C))) = 2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB30);
#ifdef SKIP_ASM
extern "C" void func_001DDB30(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
    (*(int *)((char*)(arg0) + (0x1C))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB40);
#ifdef SKIP_ASM
extern "C" void func_001DDB40(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
    (*(int *)((char*)(arg0) + (0x1C))) = 3;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB50);
#ifdef SKIP_ASM
struct V8_DDB50 { int a; int b; };
extern "C" void func_001DDB50(V8_DDB50* dst, V8_DDB50* src) {
    *(V8_DDB50*)((char*)dst + 0x1C) = *src;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB68);
#ifdef SKIP_ASM
extern "C" int func_001DDB68(int arg0) {
    return arg0 + 0x1C;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB70);
#ifdef SKIP_ASM
extern "C" void func_001DDB70(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x50))) = arg1;
    (*(int *)((char*)(arg0) + (0x4C))) = 2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB80);
#ifdef SKIP_ASM
extern "C" void func_001DDB80(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x50))) = arg1;
    (*(int *)((char*)(arg0) + (0x4C))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDB90);
#ifdef SKIP_ASM
extern "C" void func_001DDB90(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x50))) = arg1;
    (*(int *)((char*)(arg0) + (0x4C))) = 3;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDBA0);
#ifdef SKIP_ASM
struct V8_DDBA0 { int a; int b; };
extern "C" void func_001DDBA0(V8_DDBA0* dst, V8_DDBA0* src) {
    *(V8_DDBA0*)((char*)dst + 0x4C) = *src;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDBB8);
#ifdef SKIP_ASM
extern "C" int func_001DDBB8(int arg0) {
    return arg0 + 0x4C;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDBC0);
#ifdef SKIP_ASM
extern "C" void func_001DDBC0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xB4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDBC8);
#ifdef SKIP_ASM
extern "C" int func_001DDBC8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xB4)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDBD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E318_DBD0(void *, int, int) __asm__("func_0039E318");
extern "C" void func_001C55F8_DBD0(void *) __asm__("func_001C55F8");
extern int D_0046CBD8[];
extern int D_004A3E90;

struct S_DBD0 {
    int pad0[2];
    int *vt;
    char pad1[0x2A4];
    int v2B0;
    int v2B4;
};
extern "C" S_DBD0 *func_001DDBD0(S_DBD0 *self) {
    func_0039E318_DBD0(self, 0, 0);
    self->vt = D_0046CBD8;
    func_001C55F8_DBD0((char *)self + 0xBC);
    self->v2B0 = D_004A3E90;
    self->v2B4 = D_004A3E90;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDC20);
#ifdef SKIP_ASM
extern "C" int func_001DDC20(int arg0) {
    return arg0 + 0xBC;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDC28);
#ifdef SKIP_ASM
extern "C" void func_001DDC28(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x2C0))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDC30);
#ifdef SKIP_ASM
extern "C" int func_001DDC30(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2C0)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDC38);
#ifdef SKIP_ASM
extern "C" int func_001DDC38(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2B0)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDC40);
#ifdef SKIP_ASM
extern "C" int func_001DDC40(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2B8)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDC48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E318_DC48(void *, int, int) __asm__("func_0039E318");
extern "C" void func_001CA8A0_DC48(void *) __asm__("func_001CA8A0");
extern int D_0046CB08[];

extern "C" void *func_001DDC48(void *self) {
    func_0039E318_DC48(self, 0, 0);
    *(int **)((char *)self + 8) = D_0046CB08;
    func_001CA8A0_DC48((char *)self + 0x48);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDC90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DDC90(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DDC90(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DDC90(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDCB8);
#ifdef SKIP_ASM
extern "C" int func_001DDCB8(int arg0) {
    return arg0 + 0x48;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDCC0);
#ifdef SKIP_ASM
extern "C" int func_001DDCC0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6C)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDCC8);
#ifdef SKIP_ASM
extern "C" void cBuyPopupInfo_initBuySongByCredit(int);

extern "C" void func_001DDCC8(int arg0) {
    cBuyPopupInfo_initBuySongByCredit(arg0 + 0x48);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDCE8);
#ifdef SKIP_ASM
extern "C" void cBuyPopupInfo_initBuySong(int);

extern "C" void func_001DDCE8(int arg0) {
    cBuyPopupInfo_initBuySong(arg0 + 0x48);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD08);
#ifdef SKIP_ASM
extern "C" void func_001CAA18(int);

extern "C" void func_001DDD08(int arg0) {
    func_001CAA18(arg0 + 0x48);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD28);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD28(void) {
    return (*(int *)((char*)(D_004A2028) + (0x1DC)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD38);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD38(void) {
    return (*(int *)((char*)(D_004A2028) + (0x1F4)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD48);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD48(void) {
    return (*(int *)((char*)(D_004A2028) + (0x1E0)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD58);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD58(void) {
    int temp_2;

    temp_2 = (*(int *)((char*)(D_004A2028) + (0x1E4)));
    (*(int *)((char*)(D_004A2028) + (0x1E4))) = 0;
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD68);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD68(void) {
    return (*(int *)((char*)(D_004A2028) + (0x1F0)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD78);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD78(void) {
    return (*(int *)((char*)(D_004A2028) + (0x1A8)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD88);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD88(void) {
    int temp_2;

    temp_2 = (*(int *)((char*)(D_004A2028) + (0x1F8)));
    (*(int *)((char*)(D_004A2028) + (0x1F8))) = 0;
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDD98);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDD98(void) {
    int temp_2;

    temp_2 = (*(int *)((char*)(D_004A2028) + (0x1FC)));
    (*(int *)((char*)(D_004A2028) + (0x1FC))) = 0;
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDDA8);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDDA8(void) {
    return (*(int *)((char*)(D_004A2028) + (0x1E8)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDDB8);
#ifdef SKIP_ASM
extern void *D_004A2028;

extern "C" int func_001DDDB8(void) {
    int temp_2;

    temp_2 = (*(int *)((char*)(D_004A2028) + (0x1EC)));
    (*(int *)((char*)(D_004A2028) + (0x1EC))) = 0;
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDDC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A2028_DDC8 __asm__("D_004A2028");

extern "C" int func_001DDDC8(void) {
    return D_004A2028_DDC8 != 0;
}
#endif

extern "C" void func_001DDDD8(void) {
}

extern "C" void func_001DDDE0(void) {
}

extern "C" void func_001DDDE8(void) {
}

extern "C" void func_001DDDF0(void) {
}

extern "C" void func_001DDDF8(void) {
}

extern "C" void func_001DDE00(void) {
}

extern "C" void func_001DDE08(void) {
}

extern "C" void func_001DDE10(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDE18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_DE18(void *, int) __asm__("func_0039E2A0");
extern int D_0046C980[];
extern int D_00474E08[];
extern unsigned short D_004A1390[];

extern "C" void *func_001DDE18(void *self) {
    func_0039E2A0_DE18(self, 0);
    *(int *)((char *)self + 0x98) = 0;
    *(int *)((char *)self + 0x48) = 0;
    *(int **)((char *)self + 8) = D_00474E08;
    *(int *)((char *)self + 0x4C) = 0;
    *(int *)((char *)self + 0x54) = 0;
    unsigned short t = D_004A1390[0];
    *(int **)((char *)self + 8) = D_0046C980;
    *(unsigned short *)((char *)self + 0x58) = t;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDE78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *cScreenPopup_cScreenPopup_DE78(void *, int, int) __asm__("cScreenPopup_cScreenPopup");
extern int D_0046C890[];

extern "C" void *func_001DDE78(void *self) {
    cScreenPopup_cScreenPopup_DE78(self, 0, 0);
    *(int **)((char *)self + 8) = D_0046C890;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDEB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001C5A90_DEB8(void*) __asm__("func_001C5A90");
extern void* D_0046C890_DEB8[] __asm__("D_0046C890");

extern "C" void func_001DDEB8(void *self) {
    *(void***)((char*)self + 8) = D_0046C890_DEB8;
    func_001C5A90_DEB8(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDEE0);
#ifdef SKIP_ASM
extern int D_004A203C;

extern "C" void func_001DDEE0(int arg0) {
    D_004A203C = arg0;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDEE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_DEE8(void*, int) __asm__("func_0039E2A0");
extern void* D_0046C7C0[];

extern "C" void* func_001DDEE8(void *self) {
    func_0039E2A0_DEE8(self, 0);
    *(void***)((char*)self + 8) = D_0046C7C0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDF20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DDF20(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DDF20(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DDF20(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDF48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_DF48(void*, int) __asm__("func_0039E2A0");
extern void* D_0046C6F0[];

extern "C" void* func_001DDF48(void *self) {
    func_0039E2A0_DF48(self, 0);
    *(void***)((char*)self + 8) = D_0046C6F0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDF80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DDF80(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DDF80(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DDF80(self);
}
#endif

extern "C" void func_001DDFA8(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDFB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_DFB0(void*, int) __asm__("func_0039E2A0");
extern void* D_0046C620[];

extern "C" void* func_001DDFB0(void *self) {
    func_0039E2A0_DFB0(self, 0);
    *(void***)((char*)self + 8) = D_0046C620;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DDFE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DDFE8(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DDFE8(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DDFE8(self);
}
#endif

extern "C" void func_001DE010(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_E018(void*, int) __asm__("func_0039E2A0");
extern void* D_0046C550[];

extern "C" void* func_001DE018(void *self) {
    func_0039E2A0_E018(self, 0);
    *(void***)((char*)self + 8) = D_0046C550;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE050);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DE050(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DE050(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DE050(self);
}
#endif

extern "C" void func_001DE078(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE080);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E080(void *, int) __asm__("func_0039E2A0");
extern int D_0046C480[];

extern "C" void *func_001DE080(void *self) {
    func_0039E2A0_E080(self, 0);
    *(int **)((char *)self + 8) = D_0046C480;
    *((char *)self + 0x50) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE0C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DE0C0(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DE0C0(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DE0C0(self);
}
#endif

extern "C" void func_001DE0E8(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE0F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E0F0(void *, int) __asm__("func_0039E2A0");
extern int D_0046C3B0[];

extern "C" void *func_001DE0F0(void *self) {
    func_0039E2A0_E0F0(self, 0);
    *(int **)((char *)self + 8) = D_0046C3B0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE128);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_DE128(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void func_001DE128(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    func_0039E390_DE128(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE150);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001D5428_E150(void*) __asm__("func_001D5428");
extern void* D_0046C228[];

extern "C" void* func_001DE150(void *self) {
    *(void***)((char*)self + 8) = D_0046C228;
    return func_001D5428_E150(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE178);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_001D53B0_E178(void *, int, int) __asm__("func_001D53B0");
extern int D_0046C228_E178[] __asm__("D_0046C228");

extern "C" void *func_001DE178(void *self) {
    func_001D53B0_E178(self, 0, 0);
    *(int **)((char *)self + 8) = D_0046C228_E178;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE1B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E1B8(void *, int) __asm__("func_0039E2A0");
extern int D_0046C158[];

extern "C" void *func_001DE1B8(void *self) {
    func_0039E2A0_E1B8(self, 0);
    *(int **)((char *)self + 8) = D_0046C158;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE1F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E1F0(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void* func_001DE1F0(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    return func_0039E390_E1F0(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE218);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001D5428_E218(void*) __asm__("func_001D5428");
extern void* D_0046BFD0[];

extern "C" void* func_001DE218(void *self) {
    *(void***)((char*)self + 8) = D_0046BFD0;
    return func_001D5428_E218(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE240);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_001D53B0_E240(void *, int, int) __asm__("func_001D53B0");
extern int D_0046BFD0_E240[] __asm__("D_0046BFD0");

extern "C" void *func_001DE240(void *self) {
    func_001D53B0_E240(self, 0, 0);
    *(int **)((char *)self + 8) = D_0046BFD0_E240;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE280);
#ifdef SKIP_ASM
extern "C" void func_001DE280(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x27C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE288);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E318_E288(void *, int, int) __asm__("func_0039E318");
extern int D_0046BEC8[];
extern int D_004A3E90;

struct S_E288 {
    int pad0[2];
    int *vt;
    char pad1[0x54];
    int v60;
    char pad2[0x3C0];
    int v424;
};
extern "C" S_E288 *func_001DE288(S_E288 *self) {
    func_0039E318_E288(self, 0, 0);
    self->vt = D_0046BEC8;
    self->v60 = 0x3F;
    self->v424 = D_004A3E90;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE2D8);
#ifdef SKIP_ASM
extern "C" int func_001DE2D8(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE2E0);
#ifdef SKIP_ASM
extern "C" int func_001DE2E0(int arg0) {
    return arg0 + 0x74;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE2E8);
#ifdef SKIP_ASM
extern "C" void strlen(int);

extern "C" void func_001DE2E8(int arg0) {
    strlen(arg0 + 0x74);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE308);
#ifdef SKIP_ASM
extern "C" int func_001DE308(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x140)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE310);
#ifdef SKIP_ASM
extern "C" void func_001DE310(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x140))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE318);
#ifdef SKIP_ASM
extern "C" void func_001DE318(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x43C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE320);
#ifdef SKIP_ASM
extern "C" int func_001DE320(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x43C)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE328);
#ifdef SKIP_ASM
extern "C" int func_001DE328(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x420)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE330);
#ifdef SKIP_ASM
extern "C" void func_001DE330(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x420))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE338);
#ifdef SKIP_ASM
extern "C" void func_001DE338(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x70))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE340);
#ifdef SKIP_ASM
extern "C" void func_001DE340(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x54))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE348);
#ifdef SKIP_ASM
extern "C" void func_001DE348(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x58))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE350);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001CE3C8_DE350(int, int, int, int) __asm__("func_001CE3C8");

extern "C" void func_001DE350(int arg0, int arg1) {
    func_001CE3C8_DE350(arg0, 0x4B, arg1, 2);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE378);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001CE3C8_DE378(int, int, int, int) __asm__("func_001CE3C8");

extern "C" void func_001DE378(int arg0, int arg1) {
    func_001CE3C8_DE378(arg0, 0x1C, arg1, 2);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE3A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001CE3C8_DE3A0(int, int, int, int) __asm__("func_001CE3C8");

extern "C" void func_001DE3A0(int arg0, int arg1) {
    func_001CE3C8_DE3A0(arg0, 0x45, arg1, 2);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE3C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001CE3C8_DE3C8(int, int, int, int) __asm__("func_001CE3C8");

extern "C" void func_001DE3C8(int arg0, int arg1) {
    func_001CE3C8_DE3C8(arg0, 0x4F, arg1, 2);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE3F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001CE3C8_DE3F0(int, int, int, int) __asm__("func_001CE3C8");

extern "C" void func_001DE3F0(int arg0, int arg1) {
    func_001CE3C8_DE3F0(arg0, 0x29, arg1, 2);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE418);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001CE3C8_DE418(int, int, int, int) __asm__("func_001CE3C8");

extern "C" void func_001DE418(int arg0, int arg1) {
    func_001CE3C8_DE418(arg0, 0x42, arg1, 2);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE440);
#ifdef SKIP_ASM
extern "C" int func_001DE440(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x64)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE448);
#ifdef SKIP_ASM
extern "C" int func_001DE448(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x60)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE450);
#ifdef SKIP_ASM
extern "C" void func_001DE450(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x438))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE458);
#ifdef SKIP_ASM
extern "C" int func_001DE458(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x438)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE460);
#ifdef SKIP_ASM
extern "C" void func_001DE460(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x440))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE468);
#ifdef SKIP_ASM
extern "C" int func_001DE468(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5C)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE470);
#ifdef SKIP_ASM
extern "C" void func_001DE470(void *arg0) {
    int temp_3;

    temp_3 = (*(int *)((char*)(arg0) + (0x134)));
    if (temp_3 < ((*(int *)((char*)(arg0) + (0x60))) - 1)) {
        (*(int *)((char*)(arg0) + (0x134))) = (int) (temp_3 + 1);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE498);
#ifdef SKIP_ASM
extern "C" void func_001DE498(void *arg0) {
    int temp_2;

    temp_2 = (*(int *)((char*)(arg0) + (0x134)));
    if (temp_2 > 0) {
        (*(int *)((char*)(arg0) + (0x134))) = (int) (temp_2 - 1);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE4B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E4B0(void *, int) __asm__("func_0039E2A0");
extern int D_0046BDF8[];

extern "C" void *func_001DE4B0(void *self) {
    func_0039E2A0_E4B0(self, 0);
    *(int **)((char *)self + 8) = D_0046BDF8;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE4E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E4E8(void *, int) __asm__("func_0039E2A0");
extern "C" void func_002006B8_E4E8(void *) __asm__("func_002006B8");
extern int D_0046BD28[];

extern "C" void *func_001DE4E8(void *self) {
    func_0039E2A0_E4E8(self, 0);
    *(int **)((char *)self + 8) = D_0046BD28;
    func_002006B8_E4E8((char *)self + 0x48);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE528);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E528(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void* func_001DE528(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    return func_0039E390_E528(self);
}
#endif

extern "C" void func_001DE550(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE558);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E558(void *, int) __asm__("func_0039E2A0");
extern int D_0046BC58_E558[] __asm__("D_0046BC58");

extern "C" void *func_001DE558(void *self) {
    func_0039E2A0_E558(self, 0);
    *(int **)((char *)self + 8) = D_0046BC58_E558;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE590);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_E590(void*) __asm__("func_0039E2A0");
extern void* D_0046BC58[];

extern "C" void* func_001DE590(void *self) {
    func_0039E2A0_E590(self);
    *(void***)((char*)self + 8) = D_0046BC58;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE5C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E5C8(void*) __asm__("func_0039E390");
extern void* D_0046BC58[];

extern "C" void* func_001DE5C8(void *self) {
    *(void***)((char*)self + 8) = D_0046BC58;
    return func_0039E390_E5C8(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE5F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E5F0(void *, int) __asm__("func_0039E2A0");
extern int D_0046BB88_E5F0[] __asm__("D_0046BB88");

extern "C" void *func_001DE5F0(void *self) {
    func_0039E2A0_E5F0(self, 0);
    *(int **)((char *)self + 8) = D_0046BB88_E5F0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE628);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E628(void *) __asm__("func_0039E2A0");
extern int D_0046BB88_E628[] __asm__("D_0046BB88");

extern "C" void *func_001DE628(void *self) {
    func_0039E2A0_E628(self);
    *(int **)((char *)self + 8) = D_0046BB88_E628;
    *(int *)((char *)self + 0x48) = 0;
    *(int *)((char *)self + 0x4C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE668);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E668(void*) __asm__("func_0039E390");
extern void* D_0046BB88[];

extern "C" void* func_001DE668(void *self) {
    *(void***)((char*)self + 8) = D_0046BB88;
    return func_0039E390_E668(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE690);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E690(void *, int) __asm__("func_0039E2A0");
extern int D_0046BAB8[];

extern "C" void *func_001DE690(void *self) {
    func_0039E2A0_E690(self, 0);
    *(int **)((char *)self + 8) = D_0046BAB8;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE6C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E6C8(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void* func_001DE6C8(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    return func_0039E390_E6C8(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE6F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E6F0(void *, int) __asm__("func_0039E2A0");
extern int D_0046B9E8[];

extern "C" void *func_001DE6F0(void *self) {
    func_0039E2A0_E6F0(self, 0);
    *(int **)((char *)self + 8) = D_0046B9E8;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE728);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E728(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void* func_001DE728(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    return func_0039E390_E728(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE750);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E750(void *, int) __asm__("func_0039E2A0");
extern int D_0046B918[];

extern "C" void *func_001DE750(void *self) {
    func_0039E2A0_E750(self, 0);
    *(int **)((char *)self + 8) = D_0046B918;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE788);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E788(void*) __asm__("func_0039E390");
extern void* D_0046D0D0[];

extern "C" void* func_001DE788(void *self) {
    *(void***)((char*)self + 8) = D_0046D0D0;
    return func_0039E390_E788(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE7B0);
#ifdef SKIP_ASM
extern "C" void* func_0039E318_E7B0(void* self, int a1, int a2) __asm__("func_0039E318");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cBXString_cBXString2(void* self, const char* str);
extern void* D_0046B808[];
extern char D_004A1390_E7B0[] __asm__("D_004A1390");
extern char D_0045CDE8[];

struct sListNode_E7B0 {
    sListNode_E7B0* next;   // 0x0
    sListNode_E7B0* prev;   // 0x4
    int data;               // 0x8
};

struct sList_E7B0 {
    int count;              // 0x0
    sListNode_E7B0* head;   // 0x4
};

// Front-end state constructor: clears the state fields, sets the vtable, the name string and an empty list.
extern "C" void* func_001DE7B0(void* self)
{
    // An unused 16-byte local is needed to reproduce the 0x40-byte frame.
    int unused[4];
    char* s = (char*)self;
    func_0039E318_E7B0(self, 0, 0);
    sList_E7B0* l = (sList_E7B0*)(s + 0x6C8);
    *(int*)(s + 0x48) = 0;
    *(int*)(s + 0x58) = 0;
    *(int*)(s + 0x69C) = 0;
    *(int*)(s + 0x6A4) = 0;
    *(int*)(s + 0x6AC) = 0;
    *(int*)(s + 0x6B0) = 0;
    *(int*)(s + 0x6B8) = 0;
    *(int*)(s + 0x6BC) = 2;
    *(void***)(s + 0x8) = D_0046B808;
    cBXString_cBXString2(s + 0x6C0, D_004A1390_E7B0);
    *(sListNode_E7B0**)(s + 0x6CC) = (sListNode_E7B0*)cMemMan_alloc(0xC, D_0045CDE8, 0x20000000, 0);
    l->head->next = *(sListNode_E7B0**)(s + 0x6CC);
    l->head->prev = *(sListNode_E7B0**)(s + 0x6CC);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE860);
#ifdef SKIP_ASM
extern "C" int func_001DE860(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x58)));
}
#endif

extern "C" void func_001DE868(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE870);
#ifdef SKIP_ASM
extern "C" int func_001DE870(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE878);
#ifdef SKIP_ASM
extern int D_004A1A70;

extern "C" int func_001DE878(void) {
    return D_004A1A70;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE880);
#ifdef SKIP_ASM
extern int D_004A1A70;

extern "C" int func_001DE880(void) {
    return D_004A1A70 == 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE890);
#ifdef SKIP_ASM
extern "C" void func_001DE890(void *arg0) {
    (*(int *)((char*)(arg0) + (0x6B0))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE8A0);
#ifdef SKIP_ASM
extern "C" void func_001DE8A0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x6C4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE8A8);
#ifdef SKIP_ASM
extern "C" int func_001DE8A8(void *arg0) {
    int var_3;

    var_3 = 0;
    if ((*(int *)((char*)(arg0) + (0x40))) != 0) {
        var_3 = (*(int *)((char*)(arg0) + (0x48))) != 0;
    }
    return var_3;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE8C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_001A8500_E8C8(void *, int, int) __asm__("func_001A8500");
extern int D_0046B6F8_E8C8[] __asm__("D_0046B6F8");

extern "C" void *func_001DE8C8(void *self) {
    func_001A8500_E8C8(self, 0, 0);
    *(int **)((char *)self + 8) = D_0046B6F8_E8C8;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE908);
#ifdef SKIP_ASM
extern "C" int func_001DE908(void) {
    return 0;
}
#endif

extern "C" void func_001DE910(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE918);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001A85D0_E918(void*) __asm__("func_001A85D0");
extern void* D_0046B6F8[];

extern "C" void* func_001DE918(void *self) {
    *(void***)((char*)self + 8) = D_0046B6F8;
    return func_001A85D0_E918(self);
}
#endif

extern "C" void func_001DE940(void) {
}

extern "C" void func_001DE948(void) {
}

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE950);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_001D53B0_E950(void *, int, int) __asm__("func_001D53B0");
extern int D_0046B570[];

extern "C" void *func_001DE950(void *self) {
    func_001D53B0_E950(self, 0, 0);
    *(int **)((char *)self + 8) = D_0046B570;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE990);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0039E2A0_E990(void *, int) __asm__("func_0039E2A0");
extern int D_0046B4A0_E990[] __asm__("D_0046B4A0");

extern "C" void *func_001DE990(void *self) {
    func_0039E2A0_E990(self, 0);
    *(int **)((char *)self + 8) = D_0046B4A0_E990;
    return self;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE9C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E9C8(void*) __asm__("func_0039E390");
extern void* D_0046B4A0[];

extern "C" void* func_001DE9C8(void *self) {
    *(void***)((char*)self + 8) = D_0046B4A0;
    return func_0039E390_E9C8(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE9F0);
#ifdef SKIP_ASM
extern "C" int func_001DE9F0(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DE9F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_E9F8(void*) __asm__("func_0039E390");
extern void* D_0046B3D0[];

extern "C" void* func_001DE9F8(void *self) {
    *(void***)((char*)self + 8) = D_0046B3D0;
    return func_0039E390_E9F8(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DEA20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int GetHashValue32_EA20(char *) __asm__("GetHashValue32__FPc");
extern "C" int cUIEngine_addScreenByHashName_EA20(int, void *, int, int) __asm__("cUIEngine_addScreenByHashName");
extern "C" void cUIScreen_playFrame_EA20(int, int, int) __asm__("cUIScreen_playFrame");
extern char D_0045DD20[];

extern "C" void func_001DEA20(void *self) {
    int h = GetHashValue32_EA20(D_0045DD20);
    *(int *)((char *)self + 0xC) = h;
    int s = cUIEngine_addScreenByHashName_EA20(*(int *)((char *)self + 0x10), self, h, 0);
    *(int *)((char *)self + 0x40) = s;
    if (s != 0) {
        cUIScreen_playFrame_EA20(s, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DEA80);
#ifdef SKIP_ASM
// Key filter: keys 7, 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001DEA80(void* self, int a1, unsigned int key)
{
    int r = 0x101;
    if (key < 10) {
        if (key < 7) {
            r = 0x101;
        } else {
            return 0x100;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DEAA8);
#ifdef SKIP_ASM
int GetHashValue32(char*);
extern "C" void func_0039F190(int, int);
extern char D_004A14E8[];
extern char D_004A14F0[];

extern "C" void func_001DEAA8(char *self, char *arg1, int arg2) {
    if (arg1 != 0) {
        if (arg2 == 5) {
            int a = *(int*)(arg1 + 0x38);
            if (a == GetHashValue32(D_004A14E8)) {
                *(char*)(self + 0x48) = 1;
                func_0039F190(*(int*)(self + 0x10) + 0x18, 1);
            } else {
                int b = *(int*)(arg1 + 0x38);
                if (b == GetHashValue32(D_004A14F0)) {
                    *(char*)(self + 0x48) = 0;
                    func_0039F190(*(int*)(self + 0x10) + 0x18, 1);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DEB50);
#ifdef SKIP_ASM
extern "C" signed char func_001DEB50(void *arg0) {
    return (*(signed char *)((char*)(arg0) + (0x48)));
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DEB58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_EB58(void*) __asm__("func_0039E390");
extern void* D_0046B300[];

extern "C" void* func_001DEB58(void *self) {
    *(void***)((char*)self + 8) = D_0046B300;
    return func_0039E390_EB58(self);
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DEB80);
#ifdef SKIP_ASM
extern "C" int func_001DEB80(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/all_in_one_main", func_001DEB88);
#ifdef SKIP_ASM
extern "C" int func_001DEB88(void) {
    return 1;
}
#endif
