#include "common.h"

void* operator_new(unsigned int size);

struct cAsyncSys {
    char pad_0x00[0x1CC];
    void* field_0x1CC;
    int field_0x1D0;
};

//100%
INCLUDE_ASM("sound/asyncsys", cAsyncSys_ASYNCSYS_Init__FP9cAsyncSysUi);
#ifdef SKIP_ASM
extern const char D_00482988[];
// PORT: operator_new really takes (size, tag, flags, d); unit declares 1 arg
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);

void cAsyncSys_ASYNCSYS_Init(cAsyncSys* self, unsigned int x, int flags) __asm__("cAsyncSys_ASYNCSYS_Init__FP9cAsyncSysUi");
void cAsyncSys_ASYNCSYS_Init(cAsyncSys* self, unsigned int x, int flags)
{
    if (x != 0) {
        self->field_0x1D0 = x;
        self->field_0x1CC = operator_new__FUi(x, D_00482988, flags, 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028A230);
#ifdef SKIP_ASM
extern "C" void func_00289DF0(void* self, int a);
extern "C" void func_003E4FB0(int a);
void cMemMan_free(void* p);

extern "C" void func_0028A230(cAsyncSys* self)
{
    func_00289DF0(self, 1);
    while (*(int*)((char*)self + 4) != 0) {
        func_003E4FB0(2);
        func_00289DF0(self, 1);
    }
    if (self->field_0x1CC != 0) {
        cMemMan_free(self->field_0x1CC);
        self->field_0x1CC = 0;
        self->field_0x1D0 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028A298);
#ifdef SKIP_ASM
extern "C" int func_003DF748(char* name, int a1, int a2);
extern "C" int func_003DF690(char* name, int a1);

struct sRing_A298 {
    int size;
    int* data;
    int head;
    int tail;
};

struct sVE_A298 {
    short delta;
    short index;
    int (*fn)(void*, int, int, int);
};

class cAsync_A298 {
public:
    char data[0x1D4];
    // vptr at 0x1D4; slot N at vtable offset N*8
    virtual void v01();
    virtual void notify(int id);
};

struct sAsync_A298 {
    int result;             // 0x0
    int busy;               // 0x4
    int slot;               // 0x8
    char names[6][0x40];    // 0xC
    char pad18C[0x18C - 0xC - 6 * 0x40];
    sRing_A298 q18C;        // 0x18C
    sRing_A298 q19C;        // 0x19C
    sRing_A298 q1AC;        // 0x1AC
    sRing_A298 q1BC;        // 0x1BC
    void* buf;              // 0x1CC
    int bufSize;            // 0x1D0
    sVE_A298* vt;           // 0x1D4
};

extern "C" void func_0028A298(void* self)
{
    sAsync_A298* s = (sAsync_A298*)self;
    if (s->busy != 0) {
        return;
    }
    sRing_A298* q0 = &s->q18C;
    if (s->q18C.head == s->q18C.tail) {
        return;
    }
    s->busy = 1;
    ((cAsync_A298*)self)->notify(q0->data[q0->tail]);
    int kind;
    {
        sRing_A298* q = &s->q1AC;
        if (s->q1AC.head == s->q1AC.tail) {
            kind = -1;
        } else {
            kind = q->data[q->tail];
        }
    }
    switch (kind) {
    case 0: {
        int idx;
        sRing_A298* q = &s->q19C;
        if (s->q19C.head == s->q19C.tail) {
            idx = -1;
        } else {
            idx = q->data[q->tail];
        }
        s->result = func_003DF748(s->names[idx], (int)s->buf, s->bufSize);
        break;
    }
    case 2: {
        int idx;
        sRing_A298* q = &s->q19C;
        if (s->q19C.head == s->q19C.tail) {
            idx = -1;
        } else {
            idx = q->data[q->tail];
        }
        s->result = func_003DF748(s->names[idx], (int)s->buf, s->bufSize);
        break;
    }
    case 1: {
        int idx;
        {
            sRing_A298* q = &s->q19C;
            if (s->q19C.head == s->q19C.tail) {
                idx = -1;
            } else {
                idx = q->data[q->tail];
            }
        }
        char* name = s->names[idx];
        int a, c;
        // PORT: g++ 2.95 virtual calls (vptr at 0x1D4) written out by hand: delta + saved &pfn, args evaluated after.
        sVE_A298* vt = s->vt;
        char* thisp = (char*)s + vt[3].delta;
        int (**pf)(void*, int, int, int) = &vt[3].fn;
        if (s->q18C.head == s->q18C.tail) {
            a = -1;
        } else {
            a = q0->data[q0->tail];
        }
        sRing_A298* q3 = &s->q1BC;
        if (s->q1BC.head == s->q1BC.tail) {
            c = -1;
        } else {
            c = q3->data[q3->tail];
        }
        int r = (*pf)(thisp, a, -1, c);
        sVE_A298* vt2 = s->vt;
        char* thisp2 = (char*)s + vt2[4].delta;
        int (**pf2)(void*, int, int, int) = &vt2[4].fn;
        int b;
        if (s->q18C.head == s->q18C.tail) {
            b = -1;
        } else {
            b = q0->data[q0->tail];
        }
        int r2 = ((int (*)(void*, int))*pf2)(thisp2, b);
        if (r != 0) {
            s->result = func_003DF748(name, r, r2);
        } else {
            int d;
            if (s->q1BC.head == s->q1BC.tail) {
                d = -1;
            } else {
                d = q3->data[q3->tail];
            }
            s->result = func_003DF690(name, d);
        }
        break;
    }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/asyncsys", func_0028A558);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void func_0028A298(void* self);

struct sRing28A558 {
    int size;
    int* data;
    int head;
    int tail;
};

struct sAsync28A558 {
    char pad0[0x8];
    int slot;              // 0x8
    char names[6][0x40];   // 0xC
    char pad18C[0x18C - 0xC - 6 * 0x40];
    sRing28A558 q18C;      // 0x18C
    sRing28A558 q19C;      // 0x19C
    sRing28A558 q1AC;      // 0x1AC
    sRing28A558 q1BC;      // 0x1BC
};

extern "C" void func_0028A558(void* self, int a1, const char* name, int a3, int a4)
{
    sAsync28A558* s = (sAsync28A558*)self;
    {
        sRing28A558* q = &s->q18C;
        if ((s->q18C.head + 1) % s->q18C.size != s->q18C.tail) {
            q->data[q->head] = a1;
            if (++s->q18C.head >= s->q18C.size) {
                s->q18C.head = 0;
            }
        }
    }
    {
        sRing28A558* q = &s->q1AC;
        if ((s->q1AC.head + 1) % s->q1AC.size != s->q1AC.tail) {
            q->data[q->head] = a3;
            if (++s->q1AC.head >= s->q1AC.size) {
                s->q1AC.head = 0;
            }
        }
    }
    {
        sRing28A558* q = &s->q1BC;
        if ((s->q1BC.head + 1) % s->q1BC.size != s->q1BC.tail) {
            q->data[q->head] = a4;
            if (++s->q1BC.head >= s->q1BC.size) {
                s->q1BC.head = 0;
            }
        }
    }
    strcpy(s->names[s->slot], name);
    int slot = s->slot++;
    {
        sRing28A558* q = &s->q19C;
        if ((s->q19C.head + 1) % s->q19C.size != s->q19C.tail) {
            q->data[q->head] = slot;
            if (++s->q19C.head >= s->q19C.size) {
                s->q19C.head = 0;
            }
        }
    }
    if (s->slot >= 6) {
        s->slot = 0;
    }
    func_0028A298(self);
}
#endif

INCLUDE_ASM("sound/asyncsys", func_0028A728);

INCLUDE_ASM("sound/asyncsys", func_0028AAF8);

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B0F0);
#ifdef SKIP_ASM
struct sVE_0028B0F0 { short delta; short index; void (*fn)(void*, int, int, int); };

struct sRing_0028B0F0 {
    int pad0;
    int* data;  // 0x4
    int tail;   // 0x8
    int head;   // 0xC
    char pad10[0x20];
};

struct sAsync_0028B0F0 {
    char pad0[0x18C];
    sRing_0028B0F0 q1;       // 0x18C
    sRing_0028B0F0 q2;       // 0x1BC
    char pad1ec[0];
};

extern "C" void func_0028B0F0(sAsync_0028B0F0* self, int arg)
{
    sVE_0028B0F0* e = &(*(sVE_0028B0F0**)((char*)self + 0x1D4))[3];
    void (**pf)(void*, int, int, int) = &e->fn;
    char* thisp = (char*)self + e->delta;
    sRing_0028B0F0* q1 = &self->q1;
    int a;
    int b;
    if (self->q1.tail == self->q1.head)
        a = -1;
    else
        a = q1->data[q1->head];
    sRing_0028B0F0* q2 = &self->q2;
    if (self->q2.tail == self->q2.head)
        b = -1;
    else
        b = q2->data[q2->head];
    (*pf)(thisp, a, arg, b);
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B180);
#ifdef SKIP_ASM
extern void* D_004A3500;

extern "C" void* func_0028B180()
{
    return D_004A3500;
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B188);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" int func_0028B188(void) {
    int var_4;

    var_4 = 0;
    if (((*(int *)((char*)(D_004A28A8) + (0x7C))) != 0) || ((*(int *)((char*)(D_004A28A8) + (0x80))) != 0)) {
        var_4 = 1;
    }
    return var_4;
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B1B0);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" int func_0028B1B0()
{
    return *(void**)(D_004A28A8 + 0x84) != 0;
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B1C0);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_0028B1C0()
{
    return D_004A28A8;
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B1C8);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_0028B1C8()
{
    return *(void**)(D_004A28A8 + 0x84);
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B1D8);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_0028B1D8()
{
    return *(void**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B1E8);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_0028B1E8()
{
    return *(void**)(D_004A28A8 + 0x78);
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B1F8);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_0028B1F8()
{
    return *(void**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0x84) + 0x10);
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B210);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_0028B210(int i)
{
    char* riders = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
    return *(void**)(riders + (i << 2) + 4);
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B230);
#ifdef SKIP_ASM
extern "C" int func_0028B230(void) {
    return (*(int *)((char*)((*(void **)((char*)(D_004A28A8) + (0x84)))) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B240__FPv);
#ifdef SKIP_ASM
int func_0028B240(void* self)
{
    return 0x3C;
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B248);
#ifdef SKIP_ASM
extern "C" void* func_0028B248(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = -1;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = -1;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1c) = 0;
    *(char*)((char*)self + 0x20) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B278);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_0028B528(void* self);
extern "C" void func_0028B730(void* self);
extern "C" void func_0028B650(void* self);

extern "C" void func_0028B278(void* self, int flags)
{
    func_0028B528(self);
    func_0028B730(self);
    func_0028B650(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B2D0);
#ifdef SKIP_ASM
extern "C" void func_0028B528(void* self);

extern "C" void func_0028B2D0(void* self)
{
    if (*(void**)((char*)self + 0x18) != 0) {
        for (void* p = *(void**)((char*)self + 0x18); p != self; p = *(void**)((char*)p + 0x18)) {
            func_0028B528(p);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B320);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void* FILE_loadsizez(const char* name, int* size, int align);
extern "C" void* func_002523A8(void* self);
extern "C" void* func_00252FA0(void* a0, int a1, int a2);
extern "C" void func_0028B2D0(void* self);
extern "C" void func_0028B528(void* self);
extern "C" int func_003B6098(void* sema, int a1);
extern "C" int func_003B6528(int id);
extern "C" int func_003B6548(void* data, int id);
extern "C" int func_003E1BB8(const char* name, void* data, int size);
extern char* D_004A3614;

class cSndStream_B320 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int id);
    virtual void v7();
};

// PORT: data pointers are passed through int parameters of the semaphore/bank helpers
extern "C" void func_0028B320(void* self, const char* file, int align)
{
    void* data = 0;
    func_0028B528(self);
    func_0028B2D0(self);
    int size = 0;
    switch (*(int*)((char*)self + 0x8)) {
    case 0:
        data = FILE_loadsizez(file, &size, align);
        if (data == 0) {
            return;
        }
        break;
    case 2:
        data = FILE_loadsizez(file, &size, 0x100);
        if (data == 0) {
            return;
        }
        break;
    case 1:
        if (func_003E1BB8(file, *(void**)((char*)self + 0x10), *(int*)((char*)self + 0x14)) == 0) {
            return;
        }
        size = *(int*)((char*)self + 0x14);
        data = *(void**)((char*)self + 0x10);
        break;
    }
    if (*(int*)((char*)self + 0x8) == 2) {
        (**(cSndStream_B320***)(D_004A3614 + 0x1D8))->v6(*(int*)((char*)self + 0xC));
    }
    switch (func_003B6098((char*)self + 0x4, (int)data)) {
    case 7: {
        int h = func_003B6528(*(int*)((char*)self + 0x4));
        if (*(int*)((char*)self + 0x8) == 2) {
            func_003B6548(*(void**)((char*)self + 0x10), *(int*)((char*)self + 0x4));
        } else {
            void* m = func_00252FA0((void*)file, h, 0);
            *(void**)((char*)self + 0x10) = m;
            func_003B6548(m, *(int*)((char*)self + 0x4));
            func_002523A8(data);
            *(int*)((char*)self + 0x14) = h;
        }
        *(int*)self = 1;
        break;
    }
    case 8:
        if (*(int*)((char*)self + 0x8) == 0) {
            *(void**)((char*)self + 0x10) = data;
            *(int*)((char*)self + 0x14) = size;
        }
        *(int*)self = 1;
        break;
    default:
        if (*(int*)((char*)self + 0x8) != 1) {
            func_002523A8(data);
        }
        *(int*)self = 0;
        break;
    }
    (**(cSndStream_B320***)(D_004A3614 + 0x1D8))->v7();
    strcpy((char*)self + 0x20, file);
}
#endif

//100%
INCLUDE_ASM("sound/asyncsys", func_0028B528);
#ifdef SKIP_ASM
extern "C" int func_003B6300(int id);
extern "C" void* func_002523A8(void* self);

extern "C" void func_0028B528(void* self)
{
    if (*(int*)self == 1) {
        *(int*)self = 0;
        func_003B6300(*(int*)((char*)self + 0x4));
        *(int*)((char*)self + 0x4) = -1;
        if (*(int*)((char*)self + 0x8) == 0) {
            func_002523A8(*(void**)((char*)self + 0x10));
            *(int*)((char*)self + 0x10) = 0;
            *(int*)((char*)self + 0x14) = 0;
        }
    }
}
#endif

