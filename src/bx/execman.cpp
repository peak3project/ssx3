#include "common.h"

struct cExecutionMan {
    int field_0x0;
    int field_0x4;
    void* field_0x8;
};

extern void* D_0048DC30[16];
void operator_delete(int* ptr);

//100%
INCLUDE_ASM("bx/execman", cExecutionMan__cExecutionMan__FP13cExecutionMani);
#ifdef SKIP_ASM
void cExecutionMan__cExecutionMan(cExecutionMan* self, int flags)
{
    self->field_0x8 = D_0048DC30;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("bx/execman", cExecutionMan_prepause__Fv);
#ifdef SKIP_ASM
void cExecutionMan_prepause()
{
}
#endif

//100%
INCLUDE_ASM("bx/execman", cExecutionMan_postpause__Fv);
#ifdef SKIP_ASM
void cExecutionMan_postpause()
{
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320960);
#ifdef SKIP_ASM
extern "C" int func_00320960(void *arg0) {
    return (*(int *)((char*)(arg0) + (4))) != 0;
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320970);
#ifdef SKIP_ASM
extern "C" void func_00320970(void *arg0, float fparg0) {
    (*(float *)((char*)(arg0) + (0x24))) = fparg0;
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320978);
#ifdef SKIP_ASM
extern "C" int func_00320978(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320980);
#ifdef SKIP_ASM
extern "C" float func_00320980(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x14)));
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320988);
#ifdef SKIP_ASM
extern "C" float func_00320988(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x24)));
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320990);
#ifdef SKIP_ASM
extern "C" float func_00320990(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x2C)));
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320998);
#ifdef SKIP_ASM
extern "C" int func_00320998(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C)));
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_003209A0);
#ifdef SKIP_ASM
extern "C" int func_003209A0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_003209A8);
#ifdef SKIP_ASM
extern "C" int func_003209A8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_003209B0);
#ifdef SKIP_ASM
extern "C" void func_003209B0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_003209B8);
#ifdef SKIP_ASM
extern "C" int func_003209B8(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_003209C0);
#ifdef SKIP_ASM
class cExecIf_9C0 {
public:
    int pad[2];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct cExecHolder_9C0 {
    int pad[2];
    cExecIf_9C0* obj;
};

extern "C" void func_003209C0(cExecHolder_9C0* self)
{
    self->obj->v5();
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_003209F0);
#ifdef SKIP_ASM
class cExecIf_9F0 {
public:
    int pad[2];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct cExecHolder_9F0 {
    int pad[2];
    cExecIf_9F0* obj;
};

extern "C" void func_003209F0(cExecHolder_9F0* self)
{
    self->obj->v4();
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320A20);
#ifdef SKIP_ASM
class cExecIf_A20 {
public:
    int pad[2];
    virtual unsigned int v1();
    virtual unsigned int v2();
    virtual unsigned int v3();
    virtual unsigned int v4();
    virtual unsigned int v5();
    virtual unsigned int v6();
};
struct cExecHolder_A20 {
    int pad[2];
    cExecIf_A20* obj;
};

extern "C" unsigned int func_00320A20(cExecHolder_A20* self)
{
    if (self->obj != 0) {
        return self->obj->v6();
    }
    return 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320A60);
#ifdef SKIP_ASM
class cExecIf_A60 {
public:
    int pad[2];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
};
struct cExecHolder_A60 {
    int pad[2];
    cExecIf_A60* obj;
};

extern "C" void func_00320A60(cExecHolder_A60* self)
{
    self->obj->v11();
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320A90);
#ifdef SKIP_ASM
class cExecIf_A90 {
public:
    int pad[2];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};
struct cExecHolder_A90 {
    int pad[2];
    cExecIf_A90* obj;
};

extern "C" void func_00320A90(cExecHolder_A90* self)
{
    self->obj->v12();
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320AC0);
#ifdef SKIP_ASM
extern "C" int func_00320AC0(int arg0) {
    return arg0 + 0x38;
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320AC8);
#ifdef SKIP_ASM
extern int D_004A5B64;

extern "C" int func_00320AC8(void) {
    return D_004A5B64;
}
#endif
//100%
INCLUDE_ASM("bx/execman", func_00320AD0);
#ifdef SKIP_ASM
extern "C" void func_00320AD0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x34))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320AD8);
#ifdef SKIP_ASM
// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00320AD8(cExecutionMan* self, int flags)
{
    self->field_0x8 = D_0048DC30;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_00423C90(void* self);

//100%
INCLUDE_ASM("bx/execman", func_00320B08__FPv);
#ifdef SKIP_ASM
void* func_00320B08(void* self)
{
    return func_00423C90(self);
}
#endif

extern "C" void func_00320550(int, int);

//100%
INCLUDE_ASM("bx/execman", func_00320B28__FPv);
#ifdef SKIP_ASM
void func_00320B28(void* self)
{
    func_00320550(1, 0xffff);
}
#endif

extern "C" void func_00320550(int, int);

//100%
INCLUDE_ASM("bx/execman", func_00320B48__FPv);
#ifdef SKIP_ASM
void func_00320B48(void* self)
{
    func_00320550(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320B68);
#ifdef SKIP_ASM
// Branchless ceil(log2(x)): count leading zeros by halving the search
// window (16/8/4/2 bits), then subtract one more if x isn't a power of two.
extern "C" int func_00320B68(int x)
{
    int n, m, y;
    n = ((x - 0x10000) >> 31) & 16;
    y = x << n;
    m = ((y - 0x1000000) >> 31) & 8;
    y <<= m;
    n += m;
    m = ((y - 0x10000000) >> 31) & 4;
    y <<= m;
    n += m;
    m = ((y - 0x40000000) >> 31) & 2;
    y <<= m;
    n += m;
    n += 1 + (y >> 31);
    n += -(x & (x - 1)) >> 31;
    return n ^ 31;
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320BF0);
#ifdef SKIP_ASM
extern "C" void* func_00320FA8(int, int, int);

extern "C" void* func_00320BF0(void* self, int a1)
{
    return func_00320FA8(*(int*)((char*)self + 0x4), *(int*)self, a1);
}
#endif

extern "C" void* func_00321108(int, int, int);

//100%
INCLUDE_ASM("bx/execman", func_00320C18);
#ifdef SKIP_ASM
extern "C" void func_00321010(int, int, int, int);

extern "C" void func_00320C18(void *arg0, int arg1, int arg2) {
    func_00321010((*(int *)((char*)(arg0) + (4))), (*(int *)((char*)(arg0) + (0))), arg1, arg2);
}
#endif

//100%
INCLUDE_ASM("bx/execman", func_00320C48__FPvi);
#ifdef SKIP_ASM
void* func_00320C48(void* self, int a1)
{
    return func_00321108(*(int*)((char*)self + 0x4), *(int*)self, a1);
}
#endif


//100%
INCLUDE_ASM("bx/execman", func_00320C70);
#ifdef SKIP_ASM
extern "C" int func_00321188(int, int, int, int);

extern "C" void func_00320C70(void *arg0, int arg1, int arg2) {
    func_00321188((*(int *)((char*)(arg0) + (4))), (*(int *)((char*)(arg0) + (0))), arg1, arg2);
}
#endif
