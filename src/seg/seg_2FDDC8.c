#include "common.h"

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCDC8);
#ifdef SKIP_ASM
extern int func_003FC0D8(int);
extern int func_003FA240(int);
extern int func_003FB810(int);
int func_003FCDC8(int a) {
    int r;
    if (func_003FC0D8(a)) {
        r = func_003FB810(func_003FA240(a));
    } else {
        r = 2;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCE10);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF00);
#ifdef SKIP_ASM
extern int func_003FB858(int, int*, int*);
extern int func_003FB898(int, int);
extern int func_00266760(int, int, int, int);
int func_003FCF00(int a, int b, int c, int d) {
    int v[2];
    int r;
    v[0] = 4;
    v[1] = 1;
    func_003FB858(d, v, &v[1]);
    r = func_003FB898(c, d);
    if (a) {
        func_00266760(b, a - 0xC, r, v[0]);
        r = 0;
    } else {
        r = 4;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF98);
#ifdef SKIP_ASM
extern int func_003FB898(int, int);
int func_003FCF98(int a, int *out) {
    int r;
    if (out) {
        *out = func_003FB898(a, 2);
        r = 0;
    } else {
        r = 4;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCFD8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD0D8);
#ifdef SKIP_ASM
extern void (*D_0045152C[])(int, int);
void func_003FD0D8(int a) {
    D_0045152C[0](a, 0x1020000);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD100);
#ifdef SKIP_ASM
extern int (*D_00451530[])(void);
void func_003FD100(void) {
    D_00451530[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD128);
#ifdef SKIP_ASM
extern int (*D_00451534[])(void);
void func_003FD128(void) {
    D_00451534[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD150);
#ifdef SKIP_ASM
extern void (*D_0045152C[])(int, int);
extern int (*D_00451530_a[])(int) __asm__("D_00451530");
extern int (*D_00451534_a[])(int) __asm__("D_00451534");
void func_003FD150(int a, int b, int (*fn)(int), int arg) {
    int none;
    D_0045152C[0](a, 0x1020000);
    none = 0;
    do {
    } while (D_00451530_a[0](fn(arg) == none) == 1);
    D_00451534_a[0](b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD1D8);
#ifdef SKIP_ASM
int func_003FD1D8(int *p) {
    return *p == 0x464C457F;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD1F0);
#ifdef SKIP_ASM
int func_003FD1F0(int *p, int n) {
    int base = *p;
    return base + *(int *)(base + 0x20) + n * 40;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD210);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD2B8);
#ifdef SKIP_ASM
unsigned func_003FD2B8(int *p, unsigned n) {
    unsigned r;
    if (n <= 0xFEFF) {
        r = ((unsigned *)func_003FD1F0(p, n))[4];
    } else {
        r = n == 0xFFF1 ? 0xFFF00000 : 0;
    }
    return r;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD2F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD558);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD660);
#ifdef SKIP_ASM
extern char D_004975F0[];
extern char D_00497608[];
extern char D_00497618[];
extern char D_00497620[];
extern char D_00497630[];
extern char D_00497638[];
extern void func_003FD2F8(int, char*, char*, int);
void func_003FD660(int a, int b) {
    func_003FD2F8(a, D_004975F0, D_00497608, b);
    func_003FD2F8(a, D_00497618, D_00497620, b);
    func_003FD2F8(a, D_00497630, D_00497638, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD6E0);
#ifdef SKIP_ASM
extern char* strcpy(char* d, const char* s);
extern unsigned func_003FD2B8(int* p, unsigned n);
struct sSym { int name; int val; int size; unsigned char info; unsigned char other; unsigned short shndx; };
int func_003FD6E0(int* p, int idx, char* dst) {
    int r = 0;
    int symtab = p[4];
    if (symtab) {
        int strtab = p[8];
        if (strtab) {
            struct sSym* sym = (struct sSym*)(idx * 16 + symtab);
            strcpy(dst, (char*)(strtab + sym->name));
            r = p[0] + func_003FD2B8(p, sym->shndx) + sym->val;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD758);
#ifdef SKIP_ASM
extern int func_004165A8(const char*, const char*);
extern unsigned func_003FD2B8(int* p, unsigned n);
int func_003FD758(int* p, char* name) {
    int r = 0;
    char* symtab = (char*)p[4];
    if (symtab) {
        if (p[8]) {
            struct sSym* sym = (struct sSym*)symtab;
            unsigned int i;
            for (i = 0; i < (unsigned int)p[5]; i++) {
                if (func_004165A8((char*)(p[8] + sym->name), name) == 0) {
                    r = p[0] + func_003FD2B8(p, sym->shndx) + sym->val;
                    break;
                }
                sym++;
            }
        }
    }
    return r;
}
#endif
