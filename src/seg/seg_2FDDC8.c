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

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF00);

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

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD150);

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

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD660);

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

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD758);
