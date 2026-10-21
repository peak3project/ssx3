#include "common.h"

extern "C" {

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412800);
#ifdef SKIP_ASM
// __terminate_func / __unexpected_func (retail data D_00453440 / D_00453A38); never return
typedef void (*sVfpNoRet)(void) __attribute__((__noreturn__));
extern sVfpNoRet D_00453440_f __asm__("D_00453440");
// terminate()
void terminate_800(void) __asm__("func_00412800") __attribute__((__noreturn__));
void terminate_800(void)
{
    D_00453440_f();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412818);
#ifdef SKIP_ASM
// __default_unexpected(): unexpected() falls back to terminate()
void unexpected_dflt_818(void) __asm__("func_00412818") __attribute__((__noreturn__));
void unexpected_dflt_818(void)
{
    terminate_800();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412828);
#ifdef SKIP_ASM
// set_terminate(): install a new terminate handler, return the old one
extern void* D_00453440_p __asm__("D_00453440");
void* set_terminate_828(void* f) __asm__("func_00412828");
void* set_terminate_828(void* f)
{
    void* old = D_00453440_p;
    D_00453440_p = f;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412838);
#ifdef SKIP_ASM
extern int D_00453A38[];
int func_00412838(int v) {
    int o = D_00453A38[0];
    D_00453A38[0] = v;
    return o;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412848);
#ifdef SKIP_ASM
// __terminate_func / __unexpected_func (retail data D_00453440 / D_00453A38); never return
extern sVfpNoRet D_00453A38_f __asm__("D_00453A38");
// unexpected()
void unexpected_848(void) __asm__("func_00412848") __attribute__((__noreturn__));
void unexpected_848(void)
{
    D_00453A38_f();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412860);
#ifdef SKIP_ASM
// __cp_exception_info(): address of the current exception's value in its cp_eh_info
extern void* func_00410490_v(void) __asm__("func_00410490");
void* cp_exception_info_860(void) __asm__("func_00412860");
void* cp_exception_info_860(void)
{
    return (char*)*(void**)func_00410490_v() + 8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412888);
#ifdef SKIP_ASM
extern int *func_00410490(void);
int func_00412888(void) {
    return *func_00410490();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_004128A8);
#ifdef SKIP_ASM
extern int *func_00410490(void);
int *func_004128A8(void) {
    int *p = (int *)*func_00410490();
    p[5] = 1;
    *(long *)(p + 8) += 1;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_004128E0);
#ifdef SKIP_ASM
extern int func_004188C0(void);
extern int func_00412800(void) __attribute__((noreturn));
int func_004128E0(void) {
    if (func_004188C0() == 0)
        return func_00412800();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412908);
#ifdef SKIP_ASM
extern int func_00418910(void);
int func_00412908(void) {
    return func_00418910();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412928);
#ifdef SKIP_ASM
extern int func_00415260(int, int, int);
int func_00412928(int *a, int (*fn)(void), short *c) {
    int r;
    if (c != 0 && c[2] != 4)
        return 0;
    if (fn == (int (*)(void))-1)
        return a[2];
    r = func_00415260(fn(), a[3], a[10]);
    if (r)
        a[2] = r;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412998);
#ifdef SKIP_ASM
extern int *func_004128E0_a(int) __asm__("func_004128E0");
extern int *func_00410490_l(void) __asm__("func_00410490");
void func_00412998(int a, int b, int c) {
    int *p = func_004128E0_a(0x30);
    int *l;
    p[3] = b;
    p[4] = c;
    p[2] = a;
    p[10] = a;
    *(long long *)(p + 8) = 0;
    p[5] = 0;
    p[0] = (int)func_00412928;
    ((short *)p)[2] = 4;
    ((short *)p)[3] = 1;
    l = func_00410490_l();
    p[6] = *l;
    *l = (int)p;
}
#endif

INCLUDE_ASM("seg/seg_313800_exception", func_00412A28);

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412AF0);
#ifdef SKIP_ASM
extern int *func_00410490(void);
extern int func_00412800(void) __attribute__((noreturn));
void func_00412AF0(void) {
    int *p = (int *)*func_00410490();
    if (p == 0) {
        func_00412800();
    }
    p[5] = 0;
}
#endif

INCLUDE_ASM("seg/seg_313800_exception", func_00412B20);

INCLUDE_ASM("seg/seg_313800_exception", func_00412CD8);

INCLUDE_ASM("seg/seg_313800_exception", func_00412D58);

INCLUDE_ASM("seg/seg_313800_exception", func_00412DD8);

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412E10);
#ifdef SKIP_ASM
int func_00412E10(int *p) {
    int *(**vt)(int *) = *(int *(***)(int *))p;
    return *vt[1](p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412E38);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern int operator_delete__FPi(int *);
int func_00412E38(int **p, int f) {
    *p = D_004998B8;
    if (f & 1) return operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412E68);
#ifdef SKIP_ASM
extern char D_004998A0[];
void *func_00412E68(void **p) {
    *p = D_004998A0;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412E80);
#ifdef SKIP_ASM
extern int D_0053EA10[];
extern int D_004998D0[];
extern int D_004A5BA8[];
extern int *func_00412F18(void);
extern void func_00414C00(int *, int, int);
int *func_00412E80(void) {
    if (D_0053EA10[0] == 0) {
        func_00412F18();
        func_00414C00(D_0053EA10, (int)D_004998D0, (int)D_004A5BA8);
    }
    return D_0053EA10;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412ED0);
#ifdef SKIP_ASM
extern int D_004998B8[];
extern int operator_delete__FPi(int *);
int func_00412ED0(int **p, int flag) {
    *p = D_004998B8;
    if (flag & 1) return operator_delete__FPi((int *)p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412F00);
#ifdef SKIP_ASM
extern int D_004998B8[];
int *func_00412F00(int **p) {
    *p = D_004998B8;
    return (int*)p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412F18);
#ifdef SKIP_ASM
extern int D_004998E0[];
extern int D_004A5BA8[];
extern void func_00414C20(int *, int);
int *func_00412F18(void) {
    if (D_004A5BA8[0] == 0)
        func_00414C20(D_004A5BA8, (int)D_004998E0);
    return D_004A5BA8;
}
#endif

}
