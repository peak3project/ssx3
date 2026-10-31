#include "common.h"

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCDC8);
#ifdef SKIP_ASM
extern int func_003FC0D8(void);
extern int func_003FA240(int);
extern int func_003FB810(int);
int func_003FCDC8(int a) {
    int r;
    if (func_003FC0D8()) {
        r = func_003FB810(func_003FA240(a));
    } else {
        r = 2;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCE10);
#ifdef SKIP_ASM
extern void func_003FB858(int, int*, int*);
extern int func_003FB898(int, int);
extern char* func_00266728(int, int, int);
extern void func_00416210(char*, int, int);
extern char D_00497550[];
int func_003FCE10(char** out, int a, int b, int c) {
    int v[2];
    int n;
    v[0] = 4;
    v[1] = 1;
    func_003FB858(c, v, &v[1]);
    n = func_003FB898(b, c);
    if (out == 0) {
        return 4;
    }
    *out = func_00266728(a, n, v[0]);
    if (*out != 0) {
        func_00416210(*out, 0, n);
        __builtin_memcpy(*out, D_00497550, 12);
        *out += 12;
        return 0;
    }
    return 6;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF00);
#ifdef SKIP_ASM
extern void func_003FB858(int, int*, int*);
extern int func_003FB898(int, int);
extern void func_00266760(int, int, int, int);
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

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FCFD8);
#ifdef SKIP_ASM
extern char D_00497598[];
extern char D_004975A8[];
extern char D_004975C0[];
extern char D_004975D8[];
extern int D_0045152C_i[] __asm__("D_0045152C");
extern int D_00451530_i[] __asm__("D_00451530");
extern int D_00451534_i[] __asm__("D_00451534");
extern char func_003FD810[];
extern char func_003FD908[];
extern int func_003FD558(int*, int, int);
extern void func_003FD660(int, int);
extern int func_003FD758(int*, char*);
extern void func_00424020(int);
int func_003FCFD8(int a, int b) {
    int obj[12];
    int hdr[3];
    int r;
    int* p;
    if (func_003FD558(obj, a, b) == 0) {
        return -1;
    }
    r = func_003FD758(obj, D_00497598);
    if (r == 0) {
        return -2;
    }
    hdr[0] = func_003FD908 - func_003FD810;
    hdr[1] = r;
    hdr[2] = (int)func_003FD810;
    func_003FD660((int)obj, (int)hdr);
    p = D_0045152C_i;
    *p = func_003FD758(obj, D_004975A8);
    if (*p == 0) {
        return -3;
    }
    p = D_00451530_i;
    *p = func_003FD758(obj, D_004975C0);
    if (*p == 0) {
        return -4;
    }
    p = D_00451534_i;
    *p = func_003FD758(obj, D_004975D8);
    if (*p == 0) {
        return -5;
    }
    func_00424020(0);
    func_00424020(2);
    return 0;
}
#endif

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
int func_003FD100(void) {
    return D_00451530[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD128);
#ifdef SKIP_ASM
extern int (*D_00451534[])(void);
int func_003FD128(void) {
    return D_00451534[0]();
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

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD210);
#ifdef SKIP_ASM
extern int func_004165A8(const char*, const char*);
struct sShdr { int name; int type; int flags; int addr; int offset; int size; int link; int info; int align; int entsize; };
struct sEhdr { char pad[0x20]; int shoff; char pad2[0xC]; unsigned short shnum; unsigned short shstrndx; };
struct sShdr* func_003FD210(int* p, char* name) {
    struct sEhdr* h = (struct sEhdr*)p[0];
    struct sShdr* sh = (struct sShdr*)((char*)h + h->shoff);
    int strtab = sh[h->shstrndx].offset;
    unsigned int i = 0;
    while (i < h->shnum) {
        if (func_004165A8((char*)h + (strtab + sh->name), name) == 0) {
            return sh;
        }
        i++;
        sh++;
    }
    return 0;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD558);
#ifdef SKIP_ASM
extern char D_004975F0[];
extern char D_004975F8[];
extern char D_00497600[];
extern int func_003FD1D8(int*);
int func_003FD558(int* o, int imgi, int x) {
    int* img = (int*)imgi;
    int ok = 0;
    struct sShdr* s1;
    struct sShdr* s2;
    struct sShdr* s3;
    if (func_003FD1D8(img)) {
        if (img[4] == 0x80001) {
            o[1] = x;
            o[0] = (int)img;
            ok = 1;
            s1 = func_003FD210(o, D_004975F0);
            s2 = func_003FD210(o, D_004975F8);
            s3 = func_003FD210(o, D_00497600);
            if (s1) {
                o[2] = (int)img + s1->offset;
                o[3] = s1->size;
            }
            if (s3) {
                o[8] = (int)img + s3->offset;
            }
            if (s2) {
                o[5] = (unsigned int)s2->size >> 4;
                o[4] = (int)img + s2->offset;
            }
        }
    }
    return ok;
}
#endif

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
