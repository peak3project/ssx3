#include "common.h"
#include "seg/seg_313800_exception.h"

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

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412A28);
#ifdef SKIP_ASM
struct sCpEh { int (*match)(void); short lang, ver; int value; int type; void (*cleanup)(int, int); int caught; sCpEh *next; long handlers; int orig; };
extern sCpEh **eh_get_a28(void) __asm__("func_00410490");
extern int ptr_type_a28(int) __asm__("func_00415728");
extern void eh_free_a28(void *) __asm__("func_00412908");
extern int term_a28(void) __asm__("func_00412800") __attribute__((noreturn));
void func_00412A28(sCpEh *p) {
    sCpEh **q = eh_get_a28();
    if (--p->handlers != 0)
        return;
    if (p == *q && !p->caught)
        return;
    for (; *q && *q != p; q = &(*q)->next)
        ;
    if (!*q)
        term_a28();
    *q = p->next;
    if (p->cleanup)
        p->cleanup(p->value, 2);
    if (!ptr_type_a28(p->type))
        eh_free_a28((void *)p->orig);
    eh_free_a28(p);
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412B20);
#ifdef SKIP_ASM
// NOTE: 100.00 (relocs agree) in the w2 tree ONLY with this class appended to include/seg/seg_313800_exception.h
// (same style as bad_cast; defining it in the .cpp loses the vptr-reset landing pad, 95.55):
//   class bad_exception : public exception {
//   public:
//       bad_exception() {}
//       virtual ~bad_exception() {}
//   };
// Uses __exception_info (g++ 2.9's hidden catch(...) variable = __start_cp_handler result).
struct sCpEhB20 { void* match; short lang, ver; void* value; const void* type; };
extern sCpEhB20** eh_get_b20(void) __asm__("func_00410490");
extern void* match_b20(const void*, const void*, void*) __asm__("func_00415260");
extern void unexpected_b20(void) __asm__("func_00412848") __attribute__((noreturn));
extern void terminate_b20(void) __asm__("func_00412800") __attribute__((noreturn));
extern const void* tf_bad_exception_b20(void) __asm__("func_00412E80");
__asm__("_vt$13bad_exception = D_004998A0\n"
        "_$_13bad_exception = func_00412E38\n"
        "__uncatch_exception = func_00412AF0
"
        "__start_cp_handler = func_004128A8
"
        "__cp_pop_exception = func_00412A28
"
        "terminate__Fv = func_00412800");
// __check_eh_spec(): an exception escaped a function whose exception specification does not allow it
void check_eh_spec_b20(int n, const void** spec) __asm__("func_00412B20");
void check_eh_spec_b20(int n, const void** spec)
{
    sCpEhB20* p = *eh_get_b20();
    int i;
    for (i = 0; i < n; ++i)
        if (match_b20(spec[i], p->type, p->value))
            throw;
    try {
        unexpected_b20();
    } catch (...) {
        sCpEhB20* q = (sCpEhB20*)__exception_info;
        if (p != q) {
            p = q;
            for (i = 0; i < n; ++i)
                if (match_b20(spec[i], p->type, p->value))
                    throw;
        }
        const void* bt = tf_bad_exception_b20();
        for (i = 0; i < n; ++i)
            if (match_b20(spec[i], bt, p->value))
                throw bad_exception();
        terminate_b20();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412CD8);
#ifdef SKIP_ASM
// g++ emits the throw machinery under fixed names; bind them to the retail functions and data (assembler
// assignments, so the relocations name the retail symbols): __eh_alloc, __cp_push_exception and __throw are libgcc /
// exception.cc functions, _vt$<class> and _$_<class> are the vtables and out-of-line destructors from tinfo.cc.
__asm__("__eh_alloc = func_004128E0\n"
        "__cp_push_exception = func_00412998\n"
        "__throw = func_00410F48\n"
        "_vt$9exception = D_004998B8\n"
        "_vt$8bad_cast = D_00499A30\n"
        "_$_8bad_cast = func_00415120");

// __throw_bad_cast()
void throw_bad_cast_cd8(void) __asm__("func_00412CD8");
void throw_bad_cast_cd8(void)
{
    throw bad_cast();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412D58);
#ifdef SKIP_ASM
__asm__("_vt$10bad_typeid = D_00499A18\n"
        "_$_10bad_typeid = func_00415088");

// __throw_bad_typeid()
void throw_bad_typeid_d58(void) __asm__("func_00412D58");
void throw_bad_typeid_d58(void)
{
    throw bad_typeid();
}
#endif

//100%
INCLUDE_ASM("seg/seg_313800_exception", func_00412DD8);
#ifdef SKIP_ASM
struct sCpEhInfoDD8 { int pad[5]; int caught; };
extern sCpEhInfoDD8** func_00410490_dd8(void) __asm__("func_00410490");
// uncaught_exception(): an exception is being thrown and no handler has caught it yet
bool uncaught_exception_dd8(void) __asm__("func_00412DD8");
bool uncaught_exception_dd8(void)
{
    sCpEhInfoDD8* p = *func_00410490_dd8();
    return p && !p->caught;
}
#endif

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
