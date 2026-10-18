#include "common.h"

INCLUDE_ASM("seg/seg_313E80", func_00412E80);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00412ED0);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern void operator_delete__FPi(int *);
void func_00412ED0(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00412F00);
#ifdef SKIP_ASM
extern int D_004998B8[];
int *func_00412F00(int **p) {
    *p = D_004998B8;
    return (int*)p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00412F18);

INCLUDE_ASM("seg/seg_313E80", func_00412F58);

INCLUDE_ASM("seg/seg_313E80", func_00413068);

INCLUDE_ASM("seg/seg_313E80", func_004130F8);

INCLUDE_ASM("seg/seg_313E80", func_00413330);

INCLUDE_ASM("seg/seg_313E80", func_00413388);

INCLUDE_ASM("seg/seg_313E80", func_004133F0);

INCLUDE_ASM("seg/seg_313E80", func_004135E8);

INCLUDE_ASM("seg/seg_313E80", func_00413748);

INCLUDE_ASM("seg/seg_313E80", func_00413860);

INCLUDE_ASM("seg/seg_313E80", func_004138B0);

INCLUDE_ASM("seg/seg_313E80", func_00413968);

INCLUDE_ASM("seg/seg_313E80", func_004139F8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413A90);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern void func_00412F58(int *);
void func_00413A90(float x) {
    int obj[2];
    float f = x;
    func_00413068(&f, obj);
    obj[1] = obj[1] == 0;
    func_00412F58(obj);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413AC8);
#ifdef SKIP_ASM
void func_00413AC8(int a, int b, int c, int d) {
    int v[4];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    func_00412F58(v);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00413AF8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413B38);
#ifdef SKIP_ASM
unsigned char *func_00413B38(unsigned char *p, unsigned *out) {
    unsigned b = *p++;
    unsigned r = b & 0x7F;
    int shift = 0;
    if (b & 0x80) {
        do {
            b = *p++;
            shift += 7;
            r |= (b & 0x7F) << shift;
        } while (b & 0x80);
    }
    *out = r;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00413B80);
#ifdef SKIP_ASM
unsigned char *func_00413B80(unsigned char *p, int *out) {
    unsigned shift = 0;
    int r = 0;
    unsigned b;
    do {
        b = *p++;
        r |= (b & 0x7F) << shift;
        shift += 7;
    } while (b & 0x80);
    if (shift < 32 && (b & 0x40))
        r |= -1 << shift;
    *out = r;
    return p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00413BD0);

INCLUDE_ASM("seg/seg_313E80", func_00413CD0);

INCLUDE_ASM("seg/seg_313E80", func_00413F38);

INCLUDE_ASM("seg/seg_313E80", func_00413F80);

INCLUDE_ASM("seg/seg_313E80", func_00414008);

INCLUDE_ASM("seg/seg_313E80", func_00414148);

INCLUDE_ASM("seg/seg_313E80", func_00414230);

INCLUDE_ASM("seg/seg_313E80", func_00414338);

INCLUDE_ASM("seg/seg_313E80", func_004146D0);

INCLUDE_ASM("seg/seg_313E80", func_004146F8);

INCLUDE_ASM("seg/seg_313E80", func_00414728);

INCLUDE_ASM("seg/seg_313E80", func_00414750);

INCLUDE_ASM("seg/seg_313E80", func_00414780);

INCLUDE_ASM("seg/seg_313E80", func_004147F8);

INCLUDE_ASM("seg/seg_313E80", func_00414818);

INCLUDE_ASM("seg/seg_313E80", func_004149F0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414B68);
#ifdef SKIP_ASM
extern int D_00499A48[];
extern void operator_delete__FPi(int *);
void func_00414B68(int *p, int flag) {
    p[1] = (int)D_00499A48;
    if (flag & 1) operator_delete__FPi(p);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00414B98);

INCLUDE_ASM("seg/seg_313E80", func_00414BD8);

INCLUDE_ASM("seg/seg_313E80", func_00414C00);

INCLUDE_ASM("seg/seg_313E80", func_00414C20);

INCLUDE_ASM("seg/seg_313E80", func_00414C40);

INCLUDE_ASM("seg/seg_313E80", func_00414C70);

INCLUDE_ASM("seg/seg_313E80", func_00414D08);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414EE0);
#ifdef SKIP_ASM
extern int D_004999D0[];
int *func_00414EE0(int *p, int a, int b, int c) {
    p[0] = a;
    p[1] = (int)D_004999D0;
    p[2] = b;
    p[3] = c;
    return p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00414F00);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414F50);
#ifdef SKIP_ASM
void func_00414F50(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414F70);
#ifdef SKIP_ASM
extern int D_004999E8[];
int *func_00414F70(int *p, int a, int b) {
    p[0] = a;
    p[1] = (int)D_004999E8;
    p[2] = b;
    return p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00414F90);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00414FE0);
#ifdef SKIP_ASM
void func_00414FE0(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415000);
#ifdef SKIP_ASM
extern int D_00499A00[];
int *func_00415000(int *p, int a) {
    p[0] = a;
    p[1] = (int)D_00499A00;
    return p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415018);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415068);
#ifdef SKIP_ASM
void func_00415068(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415088);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern void operator_delete__FPi(int *);
void func_00415088(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004150B8);
#ifdef SKIP_ASM
extern int D_00499A18[];
int *func_004150B8(int **p) {
    *p = D_00499A18;
    return (int*)p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004150D0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415120);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern void operator_delete__FPi(int *);
void func_00415120(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415150);
#ifdef SKIP_ASM
extern int D_00499A30[];
int *func_00415150(int **p) {
    *p = D_00499A30;
    return (int*)p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415168);

//100%
INCLUDE_ASM("seg/seg_313E80", func_004151B8);
#ifdef SKIP_ASM
extern int func_00414B98(void);
int func_004151B8(void) {
    return func_00414B98() ^ 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004151D8);
#ifdef SKIP_ASM
int func_004151D8(int *p) {
    return *p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004151E0);
#ifdef SKIP_ASM
extern int D_00499A48[];
int *func_004151E0(int *p, int a) {
    p[0] = a;
    p[1] = (int)D_00499A48;
    return p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004151F8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415238);
#ifdef SKIP_ASM
extern int func_004165A8(int, int);
int func_00415238(int *a, int *b) {
    return (unsigned)func_004165A8(*a, *b) >> 31;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415260);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415728);
#ifdef SKIP_ASM
extern char func_00415F48[];
extern char func_004151F8[];
extern int func_00415840(int, char *, int, char *, char *, void *);
int func_00415728(int *p) {
    int r = 0;
    if (p) {
        short *vt = (short *)p[1];
        r = func_00415840(((int *)vt)[1], func_00415F48, 1, (char *)p + vt[0], func_004151F8, p);
    }
    return r != 0;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415778);

INCLUDE_ASM("seg/seg_313E80", func_00415798);

INCLUDE_ASM("seg/seg_313E80", func_004157C0);

INCLUDE_ASM("seg/seg_313E80", func_004157E0);

INCLUDE_ASM("seg/seg_313E80", func_00415800);

INCLUDE_ASM("seg/seg_313E80", func_00415820);

INCLUDE_ASM("seg/seg_313E80", func_00415840);

INCLUDE_ASM("seg/seg_313E80", func_004158F0);

INCLUDE_ASM("seg/seg_313E80", func_00415928);

INCLUDE_ASM("seg/seg_313E80", func_00415960);

INCLUDE_ASM("seg/seg_313E80", func_00415998);

INCLUDE_ASM("seg/seg_313E80", func_004159D0);

INCLUDE_ASM("seg/seg_313E80", func_00415A08);

INCLUDE_ASM("seg/seg_313E80", func_00415A40);

INCLUDE_ASM("seg/seg_313E80", func_00415A78);

INCLUDE_ASM("seg/seg_313E80", func_00415AB0);

INCLUDE_ASM("seg/seg_313E80", func_00415AE8);

INCLUDE_ASM("seg/seg_313E80", func_00415B20);

INCLUDE_ASM("seg/seg_313E80", func_00415B58);

INCLUDE_ASM("seg/seg_313E80", func_00415B90);

INCLUDE_ASM("seg/seg_313E80", func_00415BC8);

INCLUDE_ASM("seg/seg_313E80", func_00415C00);

INCLUDE_ASM("seg/seg_313E80", func_00415C38);

INCLUDE_ASM("seg/seg_313E80", func_00415C70);

INCLUDE_ASM("seg/seg_313E80", func_00415CA8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415CF8);
#ifdef SKIP_ASM
void func_00415CF8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415D18);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415D68);
#ifdef SKIP_ASM
void func_00415D68(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415D88);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415DD8);
#ifdef SKIP_ASM
void func_00415DD8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415DF8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415E48);
#ifdef SKIP_ASM
void func_00415E48(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415E68);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415EB8);
#ifdef SKIP_ASM
void func_00415EB8(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415ED8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415F28);
#ifdef SKIP_ASM
void func_00415F28(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415F48);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415F98);
#ifdef SKIP_ASM
void func_00415F98(void) {
    ((void (*)(void))func_00414B68)();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00415FB8);
#ifdef SKIP_ASM
extern int D_00454944;
int func_00415FB8(void) {
    return D_00454944;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00415FC8);

INCLUDE_ASM("seg/seg_313E80", func_0041605C);

INCLUDE_ASM("seg/seg_313E80", func_0041610C);

INCLUDE_ASM("seg/seg_313E80", func_00416210);

INCLUDE_ASM("seg/seg_313E80", func_004162D0);

INCLUDE_ASM("seg/seg_313E80", strchr);

INCLUDE_ASM("seg/seg_313E80", func_004165A8);

INCLUDE_ASM("seg/seg_313E80", strcpy);

INCLUDE_ASM("seg/seg_313E80", strlen);

INCLUDE_ASM("seg/seg_313E80", func_00416958);

INCLUDE_ASM("seg/seg_313E80", func_00416B18);

INCLUDE_ASM("seg/seg_313E80", strncpy);

INCLUDE_ASM("seg/seg_313E80", func_00416EB0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00416F90);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416EB0(int, int, int);
void func_00416F90(int a, int b) {
    func_00416EB0(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00416FC0);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
extern void func_00417418(int, void (*)(void));
void func_00416FC0(int a) {
    func_00417418(a, func_0041FE30);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00416FE0);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416FC0(int);
void func_00416FE0(void) {
    func_00416FC0(D_00454944);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00417008);

INCLUDE_ASM("seg/seg_313E80", func_00417418);

INCLUDE_ASM("seg/seg_313E80", func_004174B0);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00417578);
#ifdef SKIP_ASM
#define func_00417578_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern void func_0041B728(int *, int, int, char *);
void func_00417578(int *p, int fmt, ...) {
    char *ap;
    func_00417578_va_start(ap);
    func_0041B728(p, p[2], fmt, ap);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004175C8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00417628);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
void func_00417628(void) {
    func_0041FE30();
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00417648);

INCLUDE_ASM("seg/seg_313E80", func_004177B0);

INCLUDE_ASM("seg/seg_313E80", sprintf);

//100%
INCLUDE_ASM("seg/seg_313E80", func_004178A8);
#ifdef SKIP_ASM
int func_004178A8(void) {
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004178B0);

INCLUDE_ASM("seg/seg_313E80", func_00417948);

INCLUDE_ASM("seg/seg_313E80", func_004179B0);

INCLUDE_ASM("seg/seg_313E80", func_00417A30);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00417A98);
#ifdef SKIP_ASM
extern int func_0041FB98(int, int);
void func_00417A98(int *p) {
    func_0041FB98(p[0x54 / 4], ((short *)p)[7]);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00417AB8);

INCLUDE_ASM("seg/seg_313E80", func_004185D0);

INCLUDE_ASM("seg/seg_313E80", func_004186C8);

INCLUDE_ASM("seg/seg_313E80", func_00418720);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418790);
#ifdef SKIP_ASM
void func_001001C8(int) __attribute__((noreturn));
void func_00418790(void) {
    func_001001C8(1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004187A0);
#ifdef SKIP_ASM
extern void func_0041A7E8(int, int);
void func_004187A0(int a) {
    func_0041A7E8(a, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_004187C0);
#ifdef SKIP_ASM
extern long func_0041E9E0(int, int, int);
int func_004187C0(int a) {
    return func_0041E9E0(a, 0, 10);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004187E8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_004188C0);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00418CA8(int);
extern void func_00418D08(int);
extern int func_0041DBF8(int, int);
int func_004188C0(int a) {
    int r;
    func_00418CA8(D_00454944);
    r = func_0041DBF8(D_00454944, a);
    func_00418D08(D_00454944);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418910);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00418CA8(int);
extern void func_00418D08(int);
extern void func_0041E340(int, int);
void func_00418910(int a) {
    func_00418CA8(D_00454944);
    func_0041E340(D_00454944, a);
    func_00418D08(D_00454944);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00418958);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418CA8);
#ifdef SKIP_ASM
extern int func_00423C90(void);
extern void func_00423DE0(int);
extern int D_00454CA8;
extern int D_00454CAC;
extern int D_00455248;
void func_00418CA8(int unused) {
    int id = func_00423C90();
    if (D_00454CA8 == id) {
        D_00454CAC++;
    } else {
        func_00423DE0(D_00455248);
        D_00454CA8 = id;
        D_00454CAC++;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418D08);
#ifdef SKIP_ASM
extern void func_00423DC0(int);
extern int D_00454CA8;
extern int D_00454CAC;
extern int D_00455248;
void func_00418D08(int unused) {
    if (--D_00454CAC == 0) {
        D_00454CA8 = -1;
        func_00423DC0(D_00455248);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418D48);
#ifdef SKIP_ASM
extern void func_004218D8(int, int, int, int, int);
void func_00418D48(int a, int b, int c, int d) {
    func_004218D8(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418D68);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418D48(int, int, int, int);
void func_00418D68(int a, int b, int c) {
    func_00418D48(func_00413AF8(), a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418DB8);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418E68(int, int, int);
void func_00418DB8(int a, int b) {
    func_00418E68(func_00413AF8(), a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418DF8);
#ifdef SKIP_ASM
extern void func_00421A50(int, int, int, int, int);
void func_00418DF8(int a, int b, int c, int d) {
    func_00421A50(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_00418E18);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418DF8(int, int, int, int);
void func_00418E18(int a, int b, int c) {
    func_00418DF8(func_00413AF8(), a, b, c);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_00418E68);

INCLUDE_ASM("seg/seg_313E80", func_00418EF8);

INCLUDE_ASM("seg/seg_313E80", func_004198D8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041A7E8);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_004198D8(int, int, int);
void func_0041A7E8(int a, int b) {
    func_004198D8(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041A818);
#ifdef SKIP_ASM
extern void func_004127A8(int);
void func_0041A818(void) {
    func_004127A8(((int (*)(void))func_0041A7E8)());
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041A840);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041AA50);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041A840(int, int, int, int);
void func_0041AA50(int a, int b, int c) {
    func_0041A840(D_00454944, a, b, c);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041AA88);

INCLUDE_ASM("seg/seg_313E80", func_0041AB08);

INCLUDE_ASM("seg/seg_313E80", func_0041AB78);

INCLUDE_ASM("seg/seg_313E80", func_0041AC40);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041ACC0);
#ifdef SKIP_ASM
char *func_0041ACC0(char *s, char c) {
    char *r = 0;
    while (*s) {
        if (*s == c) r = s;
        s++;
    }
    return *s == c ? s : r;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041AD10);

INCLUDE_ASM("seg/seg_313E80", func_0041AD80);

INCLUDE_ASM("seg/seg_313E80", func_0041AE00);

INCLUDE_ASM("seg/seg_313E80", func_0041AE70);

INCLUDE_ASM("seg/seg_313E80", func_0041AEE8);

INCLUDE_ASM("seg/seg_313E80", func_0041AF88);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041B528);
#ifdef SKIP_ASM
extern void func_0041B550(int, int, int, int);
void func_0041B528(short *p) {
    func_0041B550(p[7], 0, 0, 2);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041B550);

INCLUDE_ASM("seg/seg_313E80", func_0041B658);

INCLUDE_ASM("seg/seg_313E80", func_0041B728);

INCLUDE_ASM("seg/seg_313E80", func_0041C788);

INCLUDE_ASM("seg/seg_313E80", func_0041C938);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041CA40);
#ifdef SKIP_ASM
extern void func_0041CA70(int, int *, int, int);
void func_0041CA40(int *p, int b, int c) {
    func_0041CA70(p[21], p, b, c);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041CA70);

INCLUDE_ASM("seg/seg_313E80", func_0041D990);

INCLUDE_ASM("seg/seg_313E80", func_0041DBF8);

INCLUDE_ASM("seg/seg_313E80", func_0041E340);

INCLUDE_ASM("seg/seg_313E80", func_0041E638);

INCLUDE_ASM("seg/seg_313E80", func_0041E7A8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041E9E0);
#ifdef SKIP_ASM
extern int D_00454944;
extern long func_0041E7A8(int, int, int, int);
long func_0041E9E0(int s, int end, int base) {
    return func_0041E7A8(D_00454944, s, end, base);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041EA18);
#ifdef SKIP_ASM
extern char D_00499C81[];
int func_0041EA18(int a) {
    return (D_00499C81[a] & 1) ? a + 0x20 : a;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041EA38);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041EC08);
#ifdef SKIP_ASM
extern char D_0049A790[];
char *func_0041EC08(void) {
    return D_0049A790;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041EC18);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041EA38(int, int, int);
void func_0041EC18(int a, int b) {
    func_0041EA38(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041EC48);
#ifdef SKIP_ASM
extern int D_00454944;
void func_0041EC48(void) {
    ((char *(*)(int))func_0041EC08)(D_00454944);
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041EC70);

INCLUDE_ASM("seg/seg_313E80", func_0041ED60);

INCLUDE_ASM("seg/seg_313E80", func_0041EF50);

INCLUDE_ASM("seg/seg_313E80", func_0041F3A8);

INCLUDE_ASM("seg/seg_313E80", func_0041F9D8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041FB98);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424488(int);
int func_0041FB98(int err, int a) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424488(a);
    if (r == -1 && D_004A5BB8)
        *(int *)err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041FBF0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424558(int, int);
int func_0041FBF0(int *err, int a, int b) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424558(a, b);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041FC50);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424498(int, int, int);
int func_0041FC50(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424498(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313E80", func_0041FCB0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424460(int, int, int);
int func_0041FCB0(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424460(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_0041FD10);

INCLUDE_ASM("seg/seg_313E80", func_0041FD70);

INCLUDE_ASM("seg/seg_313E80", func_0041FDD0);

INCLUDE_ASM("seg/seg_313E80", func_0041FE30);

INCLUDE_ASM("seg/seg_313E80", func_0041FF40);

INCLUDE_ASM("seg/seg_313E80", func_0041FF98);

INCLUDE_ASM("seg/seg_313E80", func_00420010);

INCLUDE_ASM("seg/seg_313E80", func_004200F0);

INCLUDE_ASM("seg/seg_313E80", func_00420180);

INCLUDE_ASM("seg/seg_313E80", func_00420228);

INCLUDE_ASM("seg/seg_313E80", func_00420260);

INCLUDE_ASM("seg/seg_313E80", ungetc);

INCLUDE_ASM("seg/seg_313E80", func_00420510);

INCLUDE_ASM("seg/seg_313E80", func_004205B8);

INCLUDE_ASM("seg/seg_313E80", func_004205F0);

INCLUDE_ASM("seg/seg_313E80", func_004206F8);

INCLUDE_ASM("seg/seg_313E80", func_00420830);

INCLUDE_ASM("seg/seg_313E80", func_004208B8);

//100%
INCLUDE_ASM("seg/seg_313E80", func_00420978);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
int *func_00420978(int a, int b) {
    int *p = func_00420510(a, 1);
    p[5] = b;
    p[4] = 1;
    return p;
}
#endif

INCLUDE_ASM("seg/seg_313E80", func_004209B0);

INCLUDE_ASM("seg/seg_313E80", func_00420BC8);

INCLUDE_ASM("seg/seg_313E80", func_00420CC8);

INCLUDE_ASM("seg/seg_313E80", func_00420E28);

INCLUDE_ASM("seg/seg_313E80", func_00420E90);

INCLUDE_ASM("seg/seg_313E80", func_00421020);

INCLUDE_ASM("seg/seg_313E80", func_004210E8);

INCLUDE_ASM("seg/seg_313E80", func_00421280);

INCLUDE_ASM("seg/seg_313E80", func_00421400);

INCLUDE_ASM("seg/seg_313E80", func_004214C0);

INCLUDE_ASM("seg/seg_313E80", func_00421530);

INCLUDE_ASM("seg/seg_313E80", func_004216E8);

INCLUDE_ASM("seg/seg_313E80", func_004218D8);

INCLUDE_ASM("seg/seg_313E80", func_00421A50);

INCLUDE_ASM("seg/seg_313E80", func_00421B98);

INCLUDE_ASM("seg/seg_313E80", func_00421E60);

INCLUDE_ASM("seg/seg_313E80", func_00421F20);

INCLUDE_ASM("seg/seg_313E80", func_004224A0);

INCLUDE_ASM("seg/seg_313E80", func_00422560);

INCLUDE_ASM("seg/seg_313E80", func_00422780);

INCLUDE_ASM("seg/seg_313E80", func_00423980);

INCLUDE_ASM("seg/seg_313E80", func_00423990);
