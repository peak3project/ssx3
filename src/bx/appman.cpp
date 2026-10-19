#include "common.h"

//100%
INCLUDE_ASM("bx/appman", cAppMan_cAppMan);
#ifdef SKIP_ASM
extern void* D_0048DBE8[16];
extern void* D_004A5B64;

extern "C" void* cAppMan_cAppMan(void* self)
{
    *(void**)((char*)self + 0x5C) = D_0048DBE8;
    *(int*)((char*)self + 0x20) = 0xC;
    *(float*)((char*)self + 0x24) = 1.0f;
    *(float*)((char*)self + 0x30) = 0.8999999761581421f;
    *(int*)((char*)self + 0x34) = 0;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0xC) = 0;
    D_004A5B64 = self;
    return self;
}
#endif

extern void* D_0048DBE8[16];
extern void* D_004A5B64;
void operator_delete(int* ptr);

//99.92%
INCLUDE_ASM("bx/appman", cAppMan__cAppMan__FPvi);
#ifdef SKIP_ASM
void cAppMan__cAppMan(void* self, int flags)
{
    *(void**)((char*)self + 0x5C) = D_0048DBE8;
    D_004A5B64 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("bx/appman", cAppMan_run);
#ifdef SKIP_ASM
extern "C" void SYNCTASK_run(int a);
extern "C" void cAppMan_mainLoop(void* self);
struct cAppMan;
int cAppMan_checkHalt(cAppMan* self);

struct sVt0_6D60 { short delta; short index; int (*fn)(void*); };
struct sVt1_6D60 { short delta; short index; void (*fn)(void*, int); };
struct sVt2_6D60 { short delta; short index; void (*fn)(void*, int, int); };

static inline int call0_6D60(char* o, int vtoff, int slot)
{
    sVt0_6D60* vt = *(sVt0_6D60**)(o + vtoff);
    return vt[slot].fn(o + vt[slot].delta);
}

struct sVtV_6D60 { short delta; short index; void (*fn)(void*); };

static inline void callv_6D60(char* o, int vtoff, int slot)
{
    sVtV_6D60* vt = *(sVtV_6D60**)(o + vtoff);
    vt[slot].fn(o + vt[slot].delta);
}

static inline void call1_6D60(char* o, int vtoff, int slot, int a)
{
    sVt1_6D60* vt = *(sVt1_6D60**)(o + vtoff);
    vt[slot].fn(o + vt[slot].delta, a);
}

extern "C" int cAppMan_run(char* self, char* exec, int a2, int a3)
{
    *(float*)(self + 0x14) = 0.01666666753590107f;
    *(char**)(self + 0x8) = exec;
    *(int*)(self + 0x10) = 60;
    call1_6D60(exec, 8, 2, 60);
    sVt2_6D60* vt = *(sVt2_6D60**)(self + 0x5C);
    vt[3].fn(self + vt[3].delta, a2, a3);
    call1_6D60(*(char**)(self + 0x8), 8, 9, *(int*)(self + 0x4));
    while (call0_6D60(*(char**)(self + 0x8), 8, 10) == 0) {
        callv_6D60(*(char**)(self + 0x8), 8, 11);
        SYNCTASK_run(0);
        callv_6D60(*(char**)(self + 0x8), 8, 12);
        callv_6D60(*(char**)(self + 0x8), 8, 4);
        cAppMan_checkHalt((cAppMan*)self);
    }
    char* next = *(char**)(self + 0x4);
    *(int*)(self + 0x4) = 0;
    *(char**)(self + 0x0) = next;
    callv_6D60(next, 0, 5);
    *(int*)(self + 0x58) = 0;
    cAppMan_mainLoop(self);
    callv_6D60(self, 0x5C, 4);
    callv_6D60(*(char**)(self + 0x8), 8, 3);
    char* e = *(char**)(self + 0x8);
    if (e)
        call1_6D60(e, 8, 1, 3);
    return 0;
}
#endif

struct cAppMan {
    char pad_0x00[0x4];
    unsigned int mNextModule; // offset 0x4
    void* mExecutionMan; // offset 0x8
};

//100%
INCLUDE_ASM("bx/appman", cAppMan_setNextModule__FP7cAppManUi);
#ifdef SKIP_ASM
void cAppMan_setNextModule(cAppMan* self, unsigned int module)
{
    self->mNextModule = module;
}
#endif

//100%
INCLUDE_ASM("bx/appman", cAppMan_mainLoop);
#ifdef SKIP_ASM
// PORT: cAppMan_checkHalt returns int; the main loop ignores it (void call here).
void cAppMan_checkHalt_v(cAppMan* self) __asm__("cAppMan_checkHalt__FP7cAppMan");
void func_00317530(void* self, float arg);
void func_003175A0(void* self);
void func_00317600(void* self);
// PORT: func_00319D10 takes no arguments at this call site.
void func_00319D10_0() __asm__("func_00319D10__FPv");
int func_00319D18(void* self);
// PORT: func_00319D18 is called with (1, 1) here.
int func_00319D18_2(int a, int b) __asm__("func_00319D18__FPv");

struct sVtI_6F00 { short delta; short index; int (*fn)(void*); };
struct sVtV1_6F00 { short delta; short index; void (*fn)(void*, int); };

static inline int calli_6F00(char* o, int vtoff, int slot)
{
    sVtI_6F00* vt = *(sVtI_6F00**)(o + vtoff);
    return vt[slot].fn(o + vt[slot].delta);
}

static inline void call1_6F00(char* o, int vtoff, int slot, int a)
{
    sVtV1_6F00* vt = *(sVtV1_6F00**)(o + vtoff);
    vt[slot].fn(o + vt[slot].delta, a);
}

extern "C" void cAppMan_mainLoop(void* p)
{
    char* self = (char*)p;
    int count = 0;
    calli_6F00(self, 0x5C, 5);
    for (;;) {
        callv_6D60(*(char**)(self + 0x8), 8, 11);
        SYNCTASK_run(0);
        callv_6D60(*(char**)(self + 0x8), 8, 12);
        switch (*(volatile int*)(self + 0x58)) {
        case 1:
            if (calli_6F00(*(char**)(self + 0x8), 8, 10)) {
                *(volatile int*)(self + 0x58) = 2;
                func_00317600(self + 0x38);
            } else {
                func_003175A0(self + 0x38);
            }
            break;
        case 2:
            if (calli_6F00(*(char**)(self + 0x0), 0, 4)) {
                cAppMan_checkHalt_v((cAppMan*)self);
                callv_6D60(*(char**)(self + 0x0), 0, 3);
                cAppMan_checkHalt_v((cAppMan*)self);
                char* cur = *(char**)(self + 0x0);
                if (cur)
                    call1_6F00(cur, 0, 1, 3);
                func_00319D18_2(1, 1);
                func_00319D10_0();
                count = 0;
                char* next = *(char**)(self + 0x4);
                *(int*)(self + 0x4) = 0;
                *(char**)(self + 0x0) = next;
                callv_6D60(next, 0, 5);
                cAppMan_checkHalt_v((cAppMan*)self);
                calli_6F00(self, 0x5C, 5);
                *(int*)(self + 0x2C) = 0;
                *(volatile int*)(self + 0x58) = 0;
            }
            break;
        case 3:
            if (calli_6F00(*(char**)(self + 0x0), 0, 4)) {
                cAppMan_checkHalt_v((cAppMan*)self);
                callv_6D60(*(char**)(self + 0x0), 0, 3);
                cAppMan_checkHalt_v((cAppMan*)self);
                char* cur = *(char**)(self + 0x0);
                if (cur)
                    call1_6F00(cur, 0, 1, 3);
                *(int*)(self + 0x0) = 0;
                return;
            }
            break;
        case 0:
            if (*(int*)(self + 0x4)) {
                func_00317530(self + 0x38, 10.0f);
                call1_6F00(*(char**)(self + 0x8), 8, 9, *(int*)(self + 0x4));
                *(volatile int*)(self + 0x58) = 1;
            }
            break;
        }
        while (calli_6F00(self, 0x5C, 6)) {
            cAppMan_checkHalt_v((cAppMan*)self);
            count++;
            if (*(int*)(self + 0x20) < count) {
                count += calli_6F00(self, 0x5C, 5);
                break;
            }
            (*(int*)(self + 0x1C))++;
            callv_6D60(*(char**)(self + 0x0), 0, 6);
            cAppMan_checkHalt_v((cAppMan*)self);
        }
        if ((*(int*)(self + 0x34) == 1 && count > 1 && calli_6F00(*(char**)(self + 0x0), 0, 7))
            || (*(int*)(self + 0x34) == 0 && count != 0 && calli_6F00(*(char**)(self + 0x0), 0, 7))) {
            cAppMan_checkHalt_v((cAppMan*)self);
            if (0.0f < *(float*)(self + 0x2C)) {
                float k = *(float*)(self + 0x30);
                *(float*)(self + 0x2C) = (1.0f - k) * *(float*)(self + 0x24) * (float)*(int*)(self + 0x10) / (float)count + k * *(float*)(self + 0x2C);
            } else {
                *(float*)(self + 0x2C) = *(float*)(self + 0x24) * (float)*(int*)(self + 0x10) / (float)count;
            }
            count = 0;
        } else {
            callv_6D60(*(char**)(self + 0x8), 8, 4);
            cAppMan_checkHalt_v((cAppMan*)self);
        }
    }
}
#endif

INCLUDE_ASM("bx/appman", func_00317308);

int cExecutionMan_checkHalt(void* self, int flag);

//100%
INCLUDE_ASM("bx/appman", cAppMan_checkHalt__FP7cAppMan);
#ifdef SKIP_ASM
int cAppMan_checkHalt(cAppMan* self)
{
    return cExecutionMan_checkHalt(self->mExecutionMan, 1);
}
#endif

//100%
INCLUDE_ASM("bx/appman", func_00317348__FPv);
#ifdef SKIP_ASM
class cAppSubK2 {
public:
    char pad_0x00[8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

class cAppTickK2 {
public:
    char pad_0x00[8];
    cAppSubK2* sub; // 0x8
    char pad_0x0C[0xC];
    int ticks; // 0x18
    char pad_0x1C[8];
    float step; // 0x24
    float accum; // 0x28
    char pad_0x2C[0x5C - 0x2C];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
};

int func_00317348(void* p)
{
    cAppTickK2* self = (cAppTickK2*)p;
    float f28 = self->accum;
    float f24 = self->step;
    int i28 = (int)f28;
    self->ticks++;
    float sum = f28 + f24;
    int n = (int)sum - i28;
    self->accum = sum - (float)n;
    while (n--) {
        self->v07();
    }
    self->sub->v05();
}
#endif

//100%
INCLUDE_ASM("bx/appman", cAppMan_loadexecpurge);
#ifdef SKIP_ASM
struct sVEntry00317400 {
    short delta;
    short index;
    void* fn;
};

struct sAppObj00317400 {
    char pad[8];
    sVEntry00317400* vt;
};

extern "C" void cAppMan_loadexecpurge(void* self)
{
    sAppObj00317400* o = *(sAppObj00317400**)((char*)self + 8);
    ((void (*)(void*))o->vt[3].fn)((char*)o + o->vt[3].delta);
    sAppObj00317400* d = *(sAppObj00317400**)((char*)self + 8);
    if (d != 0)
    {
        ((void (*)(void*, int))d->vt[1].fn)((char*)d + d->vt[1].delta, 3);
    }
}
#endif

struct cExecutionMan {
    int field_0x0;
    int field_0x4;
    void* field_0x8;
};

extern void* D_0048DC30[16];

//100%
INCLUDE_ASM("bx/appman", cExecutionMan_halt__FP13cExecutionMan);
#ifdef SKIP_ASM
cExecutionMan* cExecutionMan_halt(cExecutionMan* self)
{
    self->field_0x0 = 0;
    self->field_0x8 = D_0048DC30;
    self->field_0x4 = 0;
    return self;
}
#endif

INCLUDE_ASM("bx/appman", func_00317478);

//100%
INCLUDE_ASM("bx/appman", cExecutionMan_checkHalt__FPvi);
#ifdef SKIP_ASM
int cExecutionMan_checkHalt(void* self, int flag)
{
    void (*fn)(void*) = *(void (**)(void*))self;
    if (fn != 0) {
        fn(*(void**)((char*)self + 0x4));
        if (flag != 0) {
            void* vt = *(void**)((char*)self + 0x8);
            short off = *(short*)((char*)vt + 0x70);
            void (*fn2)(void*) = *(void (**)(void*))((char*)vt + 0x74);
            fn2((char*)self + off);
        }
    }
}
#endif

//99.25%
INCLUDE_ASM("bx/appman", func_00317500__Fv);
#ifdef SKIP_ASM
int func_00317500(void)
{
    return func_00317348(D_004A5B64);
}
#endif

//99.67%
INCLUDE_ASM("bx/appman", func_00317520__Fv);
#ifdef SKIP_ASM
int func_00317520(void)
{
    return *(int*)((char*)D_004A5B64 + 0x8);
}
#endif

//100%
INCLUDE_ASM("bx/appman", func_00317530__FPvf);
#ifdef SKIP_ASM
void func_00317530(void* self, float arg)
{
    *(float*)((char*)self + 0xC) = arg;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1C) = 0;
}
#endif


//99.9%
INCLUDE_ASM("bx/appman", func_00317550__FPvf);
#ifdef SKIP_ASM
void func_00317550(void* self, float arg)
{
    float old8 = *(float*)((char*)self + 0x8);
    float raw = *(float*)((char*)self + 0xC);
    float diff = arg - old8;
    float x0 = *(float*)((char*)self + 0x0);
    float rate = raw * diff;
    int v1 = *(int*)((char*)D_004A5B64 + 0x1C);
    x0 = x0 - arg;
    rate = rate * 0.01f;
    *(float*)((char*)self + 0x4) = old8;
    *(float*)((char*)self + 0x18) = x0;
    *(int*)((char*)self + 0x10) = v1;
    float result = -1.5f / rate;
    *(float*)((char*)self + 0x14) = arg;
    *(float*)((char*)self + 0x8) = arg;
    *(float*)((char*)self + 0x1C) = result;
}
#endif

extern "C" float func_0040D758(float);

//99.96%
INCLUDE_ASM("bx/appman", func_003175A0__FPv);
#ifdef SKIP_ASM
void func_003175A0(void* self)
{
    int delta = *(int*)((char*)D_004A5B64 + 0x1C) - *(int*)((char*)self + 0x10);
    float ret = func_0040D758((float)delta * *(float*)((char*)D_004A5B64 + 0x14) * *(float*)((char*)self + 0x1C));
    *(float*)((char*)self + 0x0) = *(float*)((char*)self + 0x14) + *(float*)((char*)self + 0x18) * ret;
}
#endif

//100%
INCLUDE_ASM("bx/appman", func_00317600__FPv);
#ifdef SKIP_ASM
void func_00317600(void* self)
{
    *(float*)((char*)self + 0x14) = 100.0f;
    *(int*)((char*)self + 0x18) = 0;
    *(float*)((char*)self + 0x0) = 100.0f;
}
#endif

