#include "common.h"

INCLUDE_ASM("seg/seg_32F020", func_0042E020);

void func_0042E0B0(void) {
}

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E0B8);
#ifdef SKIP_ASM
long func_0042E0B8(int a0, long a1) {
    return a1;
}
#endif

void func_0042E0C0(void) {
}

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E0C8);
#ifdef SKIP_ASM
long func_0042E0C8(int a0, long a1) {
    return a1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E0D0);
#ifdef SKIP_ASM
extern int (*D_00509434[])(void);
int func_0042E0D0(void) {
    return D_00509434[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E0F8);
#ifdef SKIP_ASM
extern int (*D_00509434[])(void);
int func_0042E0F8(void) {
    return D_00509434[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E120);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
void func_0042E120(int a0, int a1, int a2, int a3, int a4) {
    D_00509430(a1, a0, a2, a3, a4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E150);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
void func_0042E150(int a0, int a1, int a2, int a3, int a4) {
    D_00509430(a1, a0, a2, a3, a4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E180);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
extern char D_004953E8[];
void func_0042E180(int a0) {
    D_00509430((int)D_004953E8, a0, 0, 0, ((int *)&D_00509430)[2]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E1C0);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
extern char D_004953E8[];
void func_0042E1C0(int a0) {
    D_00509430((int)D_004953E8, a0, 0, 0, ((int *)&D_00509430)[2]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E200);
#ifdef SKIP_ASM
extern int D_0053EA00;
extern int D_004A5BA0;
extern char D_00495410[];
extern char D_00495420[];
extern void func_00414C20(void *a0, void *a1);
extern void func_00414C00(void *a0, void *a1, void *a2);
int *func_0042E200(void) {
    if (D_0053EA00 == 0) {
        if (D_004A5BA0 == 0) {
            func_00414C20(&D_004A5BA0, D_00495410);
        }
        func_00414C00(&D_0053EA00, D_00495420, &D_004A5BA0);
    }
    return &D_0053EA00;
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E278);
#ifdef SKIP_ASM
extern int D_00456810[];
extern int (*D_00509434[])(void);
void func_0042E278(int *a0, int a1) {
    *a0 = (int)D_00456810;
    if (a1 & 1) {
        D_00509434[0]();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E2B0);
#ifdef SKIP_ASM
extern int D_004A5BA0;
extern char D_00495410[];
extern void func_00414C20(void *a0, void *a1);
int *func_0042E2B0(void) {
    if (D_004A5BA0 == 0) {
        func_00414C20(&D_004A5BA0, D_00495410);
    }
    return &D_004A5BA0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E2F0);
#ifdef SKIP_ASM
int func_0042E2F0(int a0) {
    return a0 + 4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E2F8);
#ifdef SKIP_ASM
int func_0042E2F8(int *a0) {
    return a0[5] != 0;
}
#endif

void func_0042E308(void) {
}

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E310);
#ifdef SKIP_ASM
long func_0042E310(int a0, long a1) {
    return a1;
}
#endif

void func_0042E318(void) {
}

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E320);
#ifdef SKIP_ASM
long func_0042E320(int a0, long a1) {
    return a1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E328);
#ifdef SKIP_ASM
extern int (*D_00509434[])(void);
int func_0042E328(void) {
    return D_00509434[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E350);
#ifdef SKIP_ASM
extern int (*D_00509434[])(void);
int func_0042E350(void) {
    return D_00509434[0]();
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E378);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
void func_0042E378(int a0, int a1, int a2, int a3, int a4) {
    D_00509430(a1, a0, a2, a3, a4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E3A8);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
void func_0042E3A8(int a0, int a1, int a2, int a3, int a4) {
    D_00509430(a1, a0, a2, a3, a4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E3D8);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
extern char D_004953B8[];
void func_0042E3D8(int a0) {
    D_00509430((int)D_004953B8, a0, 0, 0, ((int *)&D_00509430)[2]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E418);
#ifdef SKIP_ASM
extern int (*D_00509430)(int a0, int a1, int a2, int a3, int a4);
extern char D_004953B8[];
void func_0042E418(int a0) {
    D_00509430((int)D_004953B8, a0, 0, 0, ((int *)&D_00509430)[2]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E458);
#ifdef SKIP_ASM
extern int D_004A5B90;
extern char D_004953D8[];
extern void func_00414C20(void *a0, void *a1);
int *func_0042E458(void) {
    if (D_004A5B90 == 0) {
        func_00414C20(&D_004A5B90, D_004953D8);
    }
    return &D_004A5B90;
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E498);
#ifdef SKIP_ASM
extern int D_00456890[];
extern void operator_delete__FPi(int *a0);
void func_0042E498(int *a0, int a1) {
    a0[3] = (int)D_00456890;
    if (a1 & 1) {
        operator_delete__FPi(a0);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E4C8);
#ifdef SKIP_ASM
extern int D_004A5B98;
extern char D_004953C0[];
extern void func_00414C20(void *a0, void *a1);
int *func_0042E4C8(void) {
    if (D_004A5B98 == 0) {
        func_00414C20(&D_004A5B98, D_004953C0);
    }
    return &D_004A5B98;
}
#endif

//100%
INCLUDE_ASM("seg/seg_32F020", func_0042E508);
#ifdef SKIP_ASM
typedef struct { unsigned last; unsigned pad; unsigned long acc; unsigned rate; } sClk;
extern unsigned func_003E4E98(void);
void func_0042E508(sClk *c) {
    unsigned now = func_003E4E98();
    if (c->rate == 0x1000) {
        c->acc += now - c->last;
    } else {
        c->acc += ((unsigned long)c->rate * (unsigned long)(now - c->last)) >> 12;
    }
    c->last = now;
}
#endif
