#include "common.h"

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003ADDC0);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADDC0(void* self, int a1, int a2, int a3, int a4)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, 0, a2, 0, 0, 0, a3, a4);
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003ADE08);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADE08(void* self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, 0, a2, a3, 0, a4, a5, a6);
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003ADE58);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADE58(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, a2, a3, a4, a5, a6, a7, a8);
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003ADE90);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADE90(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, a2, a3, a4, a5, a6, 2, a7);
    return self;
}
#endif

// Memory allocator interface (alloc/free callbacks and the default allocation flags).
struct sAllocator {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void* (*free)(void* p);
    int flags;
    void* f0C;
};
extern sAllocator D_00509430;

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003ADEC8);
#ifdef SKIP_ASM
extern char D_00495218[];
extern char D_00495230[];
extern "C" signed char func_003B5440();
extern "C" void func_003E62B0();
extern "C" void func_003E6448(void* dst, int value, int size);
extern "C" void func_003E0AD8(int h, int a, int b);
extern "C" int func_003E0D80(int h, int a, int b, int c);
extern "C" int func_003DF690(int a, int flags);
extern "C" int func_003E06D8(int a, int b, int c, void* buf, int size);
extern "C" void func_003E0948(int h, int a, int b, int c, int d);
extern "C" int func_003E0BF8(int h, int a);
extern "C" int func_003E0C88(int h, int a, int b, int c);

static inline bool wsCanAlloc(sAllocator* a)
{
    return a->alloc != 0 && a->free != 0;
}

extern "C" void func_003ADEC8(void* selfp, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    char* self = (char*)selfp;
    if (func_003B5440() == 0) {
        a8 = 1;
    }
    func_003E6448(self, 0, 0x78);
    *(int*)(self + 0x18) = a7;
    *(int*)(self + 0x1C) = a8;
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 0x28) = 0;
    *(int*)(self + 0x24) = 0;
    *(int*)(self + 0x2C) = 0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x5C) = 0;
    *(int*)(self + 0x64) = 0;
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x70) = 0;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0xC) = a1;
    *(int*)(self + 0x10) = a4;
    if (!wsCanAlloc(&D_00509430)) {
        func_003E62B0();
        return;
    }
    if (a4 != 0) {
        *(int*)(self + 0x14) = 1;
        *(void**)(self + 0x4) = D_00509430.alloc(D_00495218, a3, 0, 0, D_00509430.flags);
        *(void**)(self + 0x8) = D_00509430.alloc(D_00495230, a6, 0, 0, D_00509430.flags);
        *(int*)(self + 0x30) = func_003E06D8(2, 2, 1, *(void**)(self + 0x4), a3);
        *(int*)(self + 0x34) = func_003E06D8(2, 2, 1, *(void**)(self + 0x8), a6);
        func_003E0AD8(*(int*)(self + 0x34), 0x98, 0x34);
        func_003E0AD8(*(int*)(self + 0x30), 0x98, 0x34);
        func_003E0948(*(int*)(self + 0x30), 1, 0xFF, 0x4D, 1);
        func_003E0948(*(int*)(self + 0x30), 2, 0, 0, -2);
        if (*(int*)(self + 0x1C) == 0) {
            func_003E0948(*(int*)(self + 0x34), 1, 0xFFFF, 0x4353, 1);
        } else {
            func_003E0948(*(int*)(self + 0x34), 1, 0xFFFF, 0x4353, -1);
        }
        func_003E0948(*(int*)(self + 0x34), 2, 0, 0, -2);
        int type = *(int*)(self + 0x18);
        if (type == 1) {
            *(int*)(self + 0x2C) = func_003DF690(a4, D_00509430.flags);
            *(int*)(self + 0x24) = func_003DF690(a1, D_00509430.flags);
        } else if (type == 0) {
            *(int*)(self + 0x3C) = func_003E0C88(*(int*)(self + 0x34), a4, 0, 0);
            *(int*)(self + 0x38) = func_003E0C88(*(int*)(self + 0x30), a1, 0, 0);
        } else if (type == 2) {
            *(int*)(self + 0x38) = func_003E0D80(*(int*)(self + 0x30), *(int*)(self + 0xC), a2, 0);
            *(int*)(self + 0x3C) = func_003E0D80(*(int*)(self + 0x34), *(int*)(self + 0x10), a5, 0);
        }
    } else {
        *(int*)(self + 0x14) = 0;
        *(void**)(self + 0x4) = D_00509430.alloc(D_00495218, a3, 0, 0, D_00509430.flags);
        *(void**)(self + 0x8) = 0;
        *(int*)(self + 0x30) = func_003E06D8(2, 3, 2, *(void**)(self + 0x4), a3);
        *(int*)(self + 0x34) = func_003E0BF8(*(int*)(self + 0x30), 2);
        func_003E0AD8(*(int*)(self + 0x34), 0x98, 0x34);
        func_003E0AD8(*(int*)(self + 0x30), 0x98, 0x34);
        func_003E0948(*(int*)(self + 0x30), 1, 0xFF, 0x4D, 1);
        func_003E0948(*(int*)(self + 0x30), 3, 0, 0, -2);
        if (*(int*)(self + 0x1C) == 0) {
            func_003E0948(*(int*)(self + 0x30), 2, 0xFFFF, 0x4353, 2);
        } else {
            func_003E0948(*(int*)(self + 0x30), 2, 0xFFFF, 0x4353, -1);
        }
        int type = *(int*)(self + 0x18);
        if (type == 1) {
            *(int*)(self + 0x24) = func_003DF690(a1, D_00509430.flags);
        } else if (type == 0) {
            *(int*)(self + 0x38) = func_003E0C88(*(int*)(self + 0x30), a1, 0, 0);
        } else if (type == 2) {
            *(int*)(self + 0x38) = func_003E0D80(*(int*)(self + 0x30), *(int*)(self + 0xC), a2, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE2F8);
#ifdef SKIP_ASM
extern "C" void func_003AE2F8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x70))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE300);
#ifdef SKIP_ASM
struct sWSVtE300 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// Memory interface record filled by func_003DE928 (size field first).
struct sWSMemIfE300 {
    int size;                   // 0x0
    int f4;                     // 0x4
    void* (*release)(void*);    // 0x8
    int pad[5];
};

extern "C" void func_003AEE30(void* self, int flags);
extern "C" int func_003DE928(sWSMemIfE300* mi);
extern "C" void func_003E0A28(void* p);

extern "C" void func_003AE300(char* self, int flags)
{
    char* o = *(char**)(self + 0x64);
    if (o != 0) {
        sWSVtE300* vt = *(sWSVtE300**)(o + 0x18);
        vt[1].fn(o + vt[1].delta, 3);
        *(void**)(self + 0x64) = 0;
    }
    if (*(void**)(self + 0x0) != 0) {
        func_003AEE30(*(void**)(self + 0x0), 3);
        *(void**)(self + 0x0) = 0;
    }
    if (*(void**)(self + 0x5C) != 0) {
        D_00509430.free(*(void**)(self + 0x5C));
        *(void**)(self + 0x5C) = 0;
    }
    func_003E0A28(*(void**)(self + 0x30));
    *(void**)(self + 0x30) = 0;
    if (*(int*)(self + 0x14) != 0) {
        func_003E0A28(*(void**)(self + 0x34));
        *(void**)(self + 0x34) = 0;
    }
    {
        void* p = *(void**)(self + 0x20);
        if (p != 0) {
            sWSMemIfE300 mi;
            mi.size = 0x20;
            func_003DE928(&mi);
            mi.release(p);
            *(void**)(self + 0x20) = 0;
        }
    }
    {
        void* p = *(void**)(self + 0x28);
        if (p != 0) {
            sWSMemIfE300 mi;
            mi.size = 0x20;
            func_003DE928(&mi);
            mi.release(p);
            *(void**)(self + 0x28) = 0;
        }
    }
    if (*(void**)(self + 0x4) != 0) {
        D_00509430.free(*(void**)(self + 0x4));
        *(void**)(self + 0x4) = 0;
    }
    if (*(void**)(self + 0x8) != 0) {
        D_00509430.free(*(void**)(self + 0x8));
        *(void**)(self + 0x8) = 0;
    }
    if (flags & 1) {
        D_00509430.free(self);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE450);
#ifdef SKIP_ASM
extern char D_00495210[];

struct sTimer_AE450 {
    unsigned int start;     // 0x0
    int pad4;
    long ticks;             // 0x8
    int period;             // 0x10
    int pad14;
};

struct func_003B0430_sObj;
struct func_003B0430_sKey;
extern "C" func_003B0430_sObj* func_003B0430(func_003B0430_sObj* self, func_003B0430_sKey* key);
// PORT: the unit declares func_003B0758 with int params; it stores pointers.
extern "C" void* func_003B0758_AE450(void* self, void* a1, void* a2, void* a3, int a4) __asm__("func_003B0758");
void* func_003AECB8(void* self, void* a1);
void* func_003AED20(void* self, void* a1, int a2);
extern "C" void* func_003AED40(void* self, int a1, int a2);
extern "C" int func_003AEEF8(void* self);
extern "C" void func_003E0AD8(int h, int a, int b);
extern "C" int func_003E0D80(int h, int a, int b, int c);
extern "C" void ASYNCFILE_release(int h, void* data, int* size);
extern "C" int func_003B0600(void* p, int a1);
extern "C" unsigned int func_003E4E98();
extern "C" int func_003E5008();
extern "C" void func_0042E508(void* timer);
extern "C" void* func_003AE888(void*, int);

static inline void* wsAlloc(sAllocator* a, int size)
{
    return a->alloc(D_00495210, size, 0, 0, a->flags);
}

// PORT: 64-bit long tick counter
extern "C" int func_003AE450(char* self, int a1, int a2)
{
    func_003E0AD8(*(int*)(self + 0x34), 0x97, 0x33);
    func_003E0AD8(*(int*)(self + 0x30), 0x97, 0x33);
    if (*(int*)(self + 0x24) != 0) {
        int size;
        ASYNCFILE_release(*(int*)(self + 0x24), self + 0x20, &size);
        *(int*)(self + 0x38) = func_003E0D80(*(int*)(self + 0x30), *(int*)(self + 0x20), size, 0);
    }
    if (*(int*)(self + 0x2C) != 0) {
        int size;
        ASYNCFILE_release(*(int*)(self + 0x2C), self + 0x28, &size);
        *(int*)(self + 0x3C) = func_003E0D80(*(int*)(self + 0x34), *(int*)(self + 0x28), size, 0);
    }
    if (*(int*)(self + 0x14) == 0) {
        *(int*)(self + 0x3C) = *(int*)(self + 0x38);
    }
    if (*(int*)(self + 0x1C) == 0) {
        char* s = (char*)func_003AED40(wsAlloc(&D_00509430, 0x14), *(int*)(self + 0x34), *(int*)(self + 0x3C));
        *(char**)(self + 0x0) = s;
        *(unsigned int*)(self + 0x54) = *(int*)(s + 0xC) >= 0;
    } else {
        *(unsigned int*)(self + 0x54) = 0;
    }
    *(void**)(self + 0x64) = 0;
    if (wsCanAlloc(&D_00509430)) {
        char key[0x10];
        *(char**)(self + 0x60) = self;
        func_003B0758_AE450(key, self + 0x60, (void*)func_003AECB8, (void*)func_003AED20, a1);
        *(func_003B0430_sObj**)(self + 0x64) = func_003B0430((func_003B0430_sObj*)wsAlloc(&D_00509430, 0x1C), (func_003B0430_sKey*)key);
    }
    *(int*)(self + 0x74) = func_003B0600(*(void**)(self + 0x64), 0);
    sTimer_AE450* t = (sTimer_AE450*)wsAlloc(&D_00509430, 0x18);
    t->ticks = 0;
    t->start = func_003E4E98();
    t->period = 0x1000;
    *(sTimer_AE450**)(self + 0x5C) = t;
    func_0042E508(t);
    unsigned int ms = (unsigned int)(t->ticks * 1000) / func_003E5008();
    *(int*)(self + 0x40) = a2;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x58) = 0;
    *(unsigned int*)(self + 0x4C) = ms;
    if (*(void**)(self + 0x0) != 0) {
        func_003AEEF8(*(void**)(self + 0x0));
    }
    func_003AE888(self, 0x1000);
    return *(int*)(self + 0x74);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE6C8);
#ifdef SKIP_ASM
extern "C" int func_004139F8(float f);
extern "C" int func_003B0600(void* p, int a1);
extern "C" int func_003B0580(void* self);

extern "C" int func_003AE6C8(void* self, float f)
{
    *(float*)((char*)self + 0x48) = f;
    *(int*)((char*)self + 0x74) = func_003B0600(*(void**)((char*)self + 0x64), func_004139F8(f));
    *(int*)((char*)self + 0x44) = func_003B0580(*(void**)((char*)self + 0x64));
    return *(int*)((char*)self + 0x74);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE718);
#ifdef SKIP_ASM
extern "C" int func_003AF258(int, int);

extern "C" int func_003AE718(void *self) {
    if (*(int *)((char *)self + 0x70) != 0) {
        if (*(int *)((char *)self + 0x74) != 0) {
            return func_003AF258(*(int *)((char *)self + 0x70), *(int *)((char *)self + 0x44));
        }
        return func_003AF258(*(int *)((char *)self + 0x70), func_004139F8(*(float *)((char *)self + 0x48)));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE780);
#ifdef SKIP_ASM
extern "C" unsigned int func_003AE9A0_E780(void* self) __asm__("func_003AE9A0");
extern "C" float func_003B05C0(void*);

extern "C" int func_003AE780(char* self)
{
    unsigned int t = func_003AE9A0_E780(self);
    float s = func_003B05C0(*(void**)(self + 0x64));
    *(float*)(self + 0x48) = (float)(t + *(unsigned int*)(self + 0x40)) * 0.001f * s;
    if (*(float*)(self + 0x48) < (float)*(unsigned int*)(self + 0x44) + 1.0f)
        return 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE860);
#ifdef SKIP_ASM
extern "C" int func_003AEFA8(void* p);

extern "C" int func_003AE860(void** self)
{
    void* p = *self;
    int r = 1;
    if (p != 0) {
        r = func_003AEFA8(p);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE888);
#ifdef SKIP_ASM
struct func_003AE888_sTimer {
    unsigned int last;
    int pad4;
    ulong accum;
    unsigned int rate;
};

extern "C" int func_003AEE98(void* self, int v);
extern "C" unsigned int func_003E4E98();

// PORT: accum is a 64-bit ulong
extern "C" void* func_003AE888(void* self, int speed)
{
    if ((unsigned int)speed > 0x4000) {
        speed = 0x4000;
    }
    int s = speed;
    if (*(void**)self != 0) {
        func_003AEE98(*(void**)self, s);
    }
    func_003AE888_sTimer* t = *(func_003AE888_sTimer**)((char*)self + 0x5C);
    unsigned int now = func_003E4E98();
    if (t->rate == 0x1000) {
        t->accum += (ulong)(now - t->last);
    } else {
        t->accum += ((ulong)t->rate * (ulong)(now - t->last)) >> 12;
    }
    t->rate = s;
    t->last = now;
    return 0;
}
#endif

extern "C" void* func_003AE888(void*, int);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE938__FPv);
#ifdef SKIP_ASM
void* func_003AE938(void* self)
{
    return func_003AE888(self, 0);
}
#endif

extern "C" void* func_003AE888(void*, int);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE958__FPv);
#ifdef SKIP_ASM
void* func_003AE958(void* self)
{
    return func_003AE888(self, 0x1000);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE978);
#ifdef SKIP_ASM
extern "C" int func_003AEF48(int);

extern "C" int func_003AE978(int *arg0) {
    int temp_4;
    int var_2;

    temp_4 = *arg0;
    var_2 = 0;
    if (temp_4 != 0) {
        var_2 = func_003AEF48(temp_4);
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AE9A0);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B5F60();
extern "C" int func_003B7B48(int id, void* out);
extern "C" int func_003B7C40(int id, void* out);
extern "C" int func_003E5008();
extern "C" void func_0042E508(void* timer);

// PORT: accum is a 64-bit ulong
struct func_003AE9A0_sTimer {
    unsigned int last;
    int pad4;
    ulong accum;
    unsigned int rate;
};

struct func_003AE9A0_sInfo {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xC;
};

struct func_003AE9A0_sOwner {
    char pad[0xC];
    int id;
};

struct func_003AE9A0_sSync {
    func_003AE9A0_sOwner* owner;
    char pad04[0x48];
    int offset;
    int last;
    int enabled;
    int drift;
    func_003AE9A0_sTimer* timer;
};

extern "C" int func_003AE9A0(func_003AE9A0_sSync* self)
{
    func_003AE9A0_sInfo b;
    func_003AE9A0_sInfo a;
    func_003AE9A0_sTimer* t = self->timer;
    func_0042E508(t);
    unsigned int ms = (unsigned int)(t->accum * 1000) / func_003E5008();
    int res = ms - self->offset;
    if (self->enabled != 0) {
        func_003B58A0();
        func_003B7B48(self->owner->id, &a);
        func_003B7C40(a.field_0x4, &b);
        func_003B58D8();
        int d = b.field_0x4 - func_003B5F60();
        if (self->last < d) {
            self->last = d;
            self->drift = self->drift - self->drift / 8 + (d - res);
            int av = -self->drift;
            if (av < self->drift) av = self->drift;
            if (av > 0x108) {
                self->offset -= self->drift / 8;
                self->drift = 0;
                res = ms - self->offset;
            }
        }
    }
    return res;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AEAD0);
#ifdef SKIP_ASM
extern char D_00495210[];

extern "C" unsigned char* func_003E12E0(void* q);
extern "C" int SYNCTASK_run(int a);
extern "C" int func_003B11F0(int v);
void* func_003B0720(void* self);
extern "C" void* func_003B11A0();
// PORT: func_003B04F8 returns its vcall's int result; the unit defines it void.
extern "C" int func_003B04F8_i(void* self, void* obj, void* item) __asm__("func_003B04F8");
extern "C" void func_003B0538(void* self);
extern "C" void* func_003E13E8(void* p, int a1);
extern "C" int func_003E1530(void* q);

struct sChunk_AEAD0 {
    unsigned char* data;    // 0x0
    unsigned char* body;    // 0x4
    unsigned int size;      // 0x8
};

static inline unsigned int le32_AEAD0(unsigned char* p)
{
    return (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
}

// PORT: chunk pointers passed through int parameters of some callees. The unit declares
// func_003AEAD0(int, void*) for its caller; the real body takes (self, ctx, out), bound by asm label.
extern "C" void func_003AEAD0_impl(char* self, char* ctx, sChunk_AEAD0** out) __asm__("func_003AEAD0");
extern "C" void func_003AEAD0_impl(char* self, char* ctx, sChunk_AEAD0** out)
{
    int kind = 0;
    void* q = *(void**)(self + 0x30);
    *out = 0;
    for (;;) {
        unsigned char* p = func_003E12E0(q);
        SYNCTASK_run(0);
        if (p != 0) {
            unsigned int tag = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
            if (func_003B11F0(tag))
                kind = 3;
            if (kind != 0) {
                sChunk_AEAD0* c = (sChunk_AEAD0*)func_003B0720(D_00509430.alloc(D_00495210, 0xC, 0, 0, D_00509430.flags));
                *out = c;
                c->data = p;
                if (kind == 2) {
                    unsigned int size = le32_AEAD0(p + 4);
                    c->body = p;
                    c->size = size;
                } else {
                    unsigned int size = le32_AEAD0(p + 4);
                    c->body = p + 8;
                    c->size = size;
                }
                if (*(int*)(ctx + 0x14) != 0)
                    return;
                if (kind != 3)
                    return;
                if (func_003B04F8_i(ctx, func_003B11A0(), c) != 2)
                    func_003B0538(ctx);
                return;
            }
            char name[8];
            *(unsigned int*)name = tag;
            name[4] = 0;
            func_003E13E8(q, (int)p);
        }
        if (func_003E1530(q))
            return;
    }
}
#endif

extern "C" void* func_003AEAD0(char*, void*);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AECB8__FPvT0);
#ifdef SKIP_ASM
void* func_003AECB8(void* self, void* a1)
{
    return func_003AEAD0(*(char**)a1, self);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AECE0);
#ifdef SKIP_ASM
extern "C" void* func_003E13E8(void* p, int a1);

extern "C" void* func_003AECE0(int self, int a1)
{
    int* obj = (int*)a1;
    void* r = func_003E13E8(*(void**)(self + 0x30), *obj);
    if (obj != 0) {
        r = D_00509430.free(obj);
    }
    return r;
}
#endif

extern "C" void* func_003AECE0(int, int);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AED20__FPvT0i);
#ifdef SKIP_ASM
void* func_003AED20(void* self, void* a1, int a2)
{
    return func_003AECE0(*(int*)a1, a2);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AED40);
#ifdef SKIP_ASM
extern char D_00495250[];

extern "C" signed char func_003B5440();
extern "C" void func_003E62B0();
extern "C" int func_003BA020(void* desc);
extern "C" int func_003B7AC8(int a, int b);
extern "C" int func_003B7E38(int a, void* desc, int b, int c, void* mem, int size);
extern "C" int func_003B7DE8(int h, int a, int b);

extern "C" void* func_003AED40(void* self, int a1, int a2)
{
    char desc[0x18];
    if (func_003B5440() == 0) {
        func_003E62B0();
    } else {
        *(void**)((char*)self + 0x4) = 0;
        *(int*)((char*)self + 0x10) = -1;
        *(int*)((char*)self + 0xC) = -1;
        func_003BA020(desc);
        int size = func_003B7AC8(1, 0x1E);
        void* mem = D_00509430.alloc(D_00495250, size, 0, 0, D_00509430.flags);
        *(void**)((char*)self + 0x4) = mem;
        int h = func_003B7E38(a1, desc, 1, 0x1E, mem, size);
        *(int*)((char*)self + 0xC) = h;
        *(int*)((char*)self + 0x10) = func_003B7DE8(h, -1, a2);
        *(float*)self = 1.0f;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AEE30);
#ifdef SKIP_ASM
extern "C" int func_003B7838(void* a);

extern "C" void func_003AEE30(void* self, int flags)
{
    if (*(void**)((char*)self + 0x4) != 0) {
        func_003B7838(*(void**)((char*)self + 0xC));
        D_00509430.free(*(void**)((char*)self + 0x4));
        *(void**)((char*)self + 0x4) = 0;
    }
    if (flags & 1) {
        D_00509430.free(self);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AEE98);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7FB8(int h, int v);

extern "C" int func_003AEE98(void* self, int v)
{
    int r;
    if (*(int*)((char*)self + 0xC) != -1) {
        func_003B58A0();
        r = func_003B7FB8(*(int*)((char*)self + 0xC), v);
        func_003B58D8();
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AEEF8);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7D80(int h, int a1);

extern "C" int func_003AEEF8(void* self)
{
    int r;
    if (*(int*)((char*)self + 0x10) != -1) {
        func_003B58A0();
        r = func_003B7D80(*(int*)((char*)self + 0x10), 0);
        func_003B58D8();
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AEF48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003B7E70(int, int);
int func_003AEF48_impl(void *self, int arg) __asm__("func_003AEF48");

int func_003AEF48_impl(void *self, int arg) {
    int r;

    if (*(int *)((char *)self + 0xC) != -1) {
        func_003B58A0();
        r = func_003B7E70(*(int *)((char *)self + 0xC), arg);
        func_003B58D8();
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AEFA8);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7B48(int id, void* out);
extern "C" int func_003B7C40(int id, void* out);

struct func_003AEFA8_sInfo {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xC;
};

extern "C" int func_003AEFA8(void* self)
{
    func_003AEFA8_sInfo b;
    func_003AEFA8_sInfo a;
    func_003B58A0();
    if (func_003B7B48(*(int*)((char*)self + 0xC), &a) >= 0 && func_003B7C40(a.field_0x4, &b) >= 0) {
        func_003B58D8();
        return b.field_0x8 == 0;
    }
    func_003B58D8();
    return 0;
}
#endif

extern void* D_00456890[];

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF010);
#ifdef SKIP_ASM
extern "C" void *func_003AF010(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF020);
#ifdef SKIP_ASM

struct sElem_F020 {
    char pad[0x34];
    ~sElem_F020() {}
    static void operator delete[](void* p) { D_00509430.free(p); }
};
struct sSelf_F020 { sElem_F020* arr; unsigned int count; };

extern "C" void func_003AF020(sSelf_F020* self, int flags)
{
    if (self->arr != 0) {
        delete[] self->arr;
        self->arr = 0;
    }
    self->count = 0;
    if (flags & 1) {
        D_00509430.free(self);
    }
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF0C8);
#ifdef SKIP_ASM
extern "C" void* func_003B0340(void*);
extern "C" void f03A8_F0C8(void*, int) __asm__("func_003B03A8");
extern "C" void func_003B03B0(void*, int);
extern "C" void func_003B03B8(void*, int);
extern "C" void func_003B03C0(void*, int);
extern "C" void f03C8_F0C8(void*, unsigned int) __asm__("func_003B03C8");
extern "C" void func_003B03D0(void*, int);
extern char D_00495260[];

struct sElem_F0C8 { char pad[0x34]; };
struct sSelf_F0C8 { sElem_F0C8* arr; unsigned int count; };

extern "C" void func_003AF0C8(void* vself, unsigned int count, int a2, int a3, int a4, int a5)
{
    sSelf_F0C8* self = (sSelf_F0C8*)vself;
    unsigned int* raw;
    char* arr;
    char* p;
    int i;
    unsigned int k;

    i = count - 1;
    raw = (unsigned int*)D_00509430.alloc(D_00495260, count * 0x34 + 0x10, 0, 0, D_00509430.flags);
    arr = (char*)raw + 0x10;
    *raw = count;
    p = arr;
    if (count != 0) {
        do {
            i--;
            func_003B0340(p);
            p += 0x34;
        } while (i != -1);
    }
    self->arr = (sElem_F0C8*)arr;
    self->count = count;
    if (count != 0) {
        func_003B03D0(arr, 0);
    }
    for (k = 0; k < self->count; k++) {
        f03A8_F0C8(&self->arr[k], a2);
        func_003B03B0(&self->arr[k], a3);
        func_003B03B8(&self->arr[k], a4);
        func_003B03C0(&self->arr[k], a5);
        f03C8_F0C8(&self->arr[k], k);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF230);
#ifdef SKIP_ASM
struct func_003AF230_sArr {
    char* items;
    unsigned int count;
};

extern "C" void* func_003AF230(func_003AF230_sArr* self, unsigned int idx)
{
    if (self->count < idx) {
        return 0;
    }
    return self->items + idx * 0x34;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF258);
#ifdef SKIP_ASM
struct sElem_F258 { char pad[0x14]; unsigned int key; char pad18[0x1C]; };
struct sSelf_F258 { sElem_F258* arr; int count; };

static inline int clamp_F258(int i, int n)
{
    if (i < 0) {
        i = 0;
    }
    return i < n - 1 ? i : n - 1;
}

extern "C" sElem_F258* func_003AF258_impl(sSelf_F258* self, unsigned int key) __asm__("func_003AF258");
extern "C" sElem_F258* func_003AF258_impl(sSelf_F258* self, unsigned int key)
{
    if (self->count == 0) {
        return 0;
    }
    int lo = -1;
    int hi = self->count;
    sElem_F258* arr = self->arr;
    while (hi - lo >= 2) {
        int mid = (hi + lo) / 2;
        if (arr[mid].key >= key) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return &arr[clamp_F258(hi - 1, self->count)];
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF2F8);
#ifdef SKIP_ASM
extern "C" int func_003AF2F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF300);
#ifdef SKIP_ASM
extern unsigned char D_00499C81[];
static inline unsigned char ctype_3AF300(char c) { return D_00499C81[c]; }
extern "C" void func_003AF300(char** pp, unsigned int* plen)
{
    unsigned int n;
    char* p = *pp;
    for (n = 0; n < *plen && (ctype_3AF300(p[n]) & 8); n++) {
    }
    *pp = p + n;
    *plen = *plen - n;
}

#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF378);
#ifdef SKIP_ASM
extern unsigned char D_00499C81[];
static inline int to_lower_AF378(int c) { if (D_00499C81[c] & 1) return c + 0x20; return c; }

extern "C" int func_003AF378(const char* a, const char* b)
{
    int i;
    int d = 0;
    i = 0;
    while (a[i] != 0 && b[i] != 0) {
        d += to_lower_AF378(a[i]) - to_lower_AF378(b[i]);
        if (d != 0) {
            return d;
        }
        i++;
    }
    return a[i] - b[i];
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF428);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sNames_F428 { const char* e[5]; };
struct sVals_F428 { unsigned int e[5]; };
extern const sNames_F428 D_00495290;
extern const sVals_F428 D_004952A8;
extern "C" int func_003AF378(const char*, const char*);

extern "C" unsigned int func_003AF428(char* s, unsigned int len)
{
    unsigned int i;
    char ch = 9;
    unsigned int r;
    unsigned int j;

    for (i = 0; i < len; i++) {
        char c = s[i];
        if (c == 9 || c == 13) {
            s[i] = 0;
            ch = c;
            break;
        }
    }
    sNames_F428 names = D_00495290;
    sVals_F428 vals = D_004952A8;
    r = 0xFFFFFFFF;
    for (j = 0; j < 5; j++) {
        if (func_003AF378(names.e[j], s) == 0) {
            r = vals.e[j];
            break;
        }
    }
    if (i != len) {
        s[i] = ch;
    }
    return r;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF560);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long func_0041E9E0(unsigned char *s, unsigned char **end, int base);

extern "C" int func_003AF560(unsigned char **pp, unsigned int *plen, int *out) {
    unsigned int i;
    int ch = 9;
    unsigned char *end;
    long r;

    for (i = 0; i < *plen; i++) {
        unsigned char c = (*pp)[i];
        if ((unsigned int)(c - 9) < 2U) {
            ch = (signed char)c;
            (*pp)[i] = 0;
            break;
        }
    }
    r = func_0041E9E0(*pp, &end, 10);
    *plen = *plen - (end - *pp);
    if (i != *plen) {
        (*pp)[i] = (unsigned char)ch;
    }
    if (end == *pp) {
        return 0;
    }
    *out = (int)r;
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF670);
#ifdef SKIP_ASM
extern "C" void func_003AF300(char** pp, unsigned int* plen);

extern "C" void func_003AF670(char** pp, unsigned int* plen, char** keys, unsigned int* keyLens,
                              unsigned int nkeys, unsigned int* index)
{
    char* s = *pp;
    unsigned int i;
    unsigned int k;
    unsigned int j;

    if (s == 0) {
        *pp = 0;
        *plen = 0;
        *index = 0xFFFFFFFF;
        return;
    }
    func_003AF300(&s, plen);
    for (i = 0; i < *plen; i++) {
        for (k = 0; k < nkeys; k++) {
            for (j = 0; j < keyLens[k] && i + j < *plen && keys[k][j] == s[i + j]; j++) {
            }
            if (j == keyLens[k]) {
                *pp = s + (i + j);
                *plen = *plen - (i + j);
                *index = k;
                return;
            }
        }
    }
    *pp = 0;
    *plen = 0;
    *index = 0xFFFFFFFF;
}
#endif

INCLUDE_ASM("ealib/seg_2AEDC0", func_003AF7F0);
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0340);
#ifdef SKIP_ASM
extern "C" void *func_003B0340(void *self) {
    *(int *)((char *)self + 0x00) = 0x20;
    *(int *)((char *)self + 0x04) = 0x15E;
    *(int *)((char *)self + 0x08) = 0x258;
    *(int *)((char *)self + 0x0C) = 0x32;
    *(unsigned *)((char *)self + 0x10) = 0xFFFFFFFFu;
    *(unsigned char *)((char *)self + 0x24) = 0xFF;
    *(unsigned char *)((char *)self + 0x25) = 0xFF;
    *(unsigned char *)((char *)self + 0x26) = 0xFF;
    *(int *)((char *)self + 0x18) = 2;
    *(unsigned *)((char *)self + 0x14) = 0xFFFFFFFFu;
    *(unsigned char *)((char *)self + 0x27) = 0xFF;
    *(int *)((char *)self + 0x1C) = 2;
    *(int *)((char *)self + 0x20) = 0;
    *(int *)((char *)self + 0x28) = 0;
    *(int *)((char *)self + 0x2C) = 0;
    *(int *)((char *)self + 0x30) = 0;
    return self;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03A8);
#ifdef SKIP_ASM
extern "C" void func_003B03A8(int *arg0, int arg1) {
    *arg0 = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03B0);
#ifdef SKIP_ASM
extern "C" void func_003B03B0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (4))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03B8);
#ifdef SKIP_ASM
extern "C" void func_003B03B8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03C0);
#ifdef SKIP_ASM
extern "C" void func_003B03C0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03C8);
#ifdef SKIP_ASM
extern "C" void func_003B03C8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03D0);
#ifdef SKIP_ASM
extern "C" void func_003B03D0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03D8);
#ifdef SKIP_ASM
extern "C" void func_003B03D8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03E0);
#ifdef SKIP_ASM
extern "C" void func_003B03E0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03E8);
#ifdef SKIP_ASM
extern "C" void func_003B03E8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03F0);
#ifdef SKIP_ASM
extern "C" void func_003B03F0(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x24))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B03F8);
#ifdef SKIP_ASM
extern "C" void func_003B03F8(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x25))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0400);
#ifdef SKIP_ASM
extern "C" void func_003B0400(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x26))) = arg1;
}
#endif
//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0408);
#ifdef SKIP_ASM
extern "C" void func_003B0408(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x27))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0410__FPv);
#ifdef SKIP_ASM
void* func_003B0410(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 0xc) = (int)(void*)D_00456890;
    *(int*)((char*)self + 0x4) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0430);
#ifdef SKIP_ASM
void* func_003B0738(void* self);
extern void* D_004568A8[];

struct func_003B0430_sKey {
    int v[4];
};

struct func_003B0430_sObj {
    int field_0x0;
    func_003B0430_sKey key;   // 0x4
    int field_0x14;
    void** vtable;            // 0x18
};

extern "C" func_003B0430_sObj* func_003B0430(func_003B0430_sObj* self, func_003B0430_sKey* key)
{
    self->vtable = D_004568A8;
    func_003B0738(&self->key);
    self->key = *key;
    self->field_0x14 = 0;
    self->field_0x0 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B04A0);
#ifdef SKIP_ASM
extern "C" void func_003B0538(void* self);
extern void* D_004568A8[];

extern "C" void func_003B04A0(void* self, int flags)
{
    *(void***)((char*)self + 0x18) = D_004568A8;
    func_003B0538(self);
    if (flags & 1) {
        D_00509430.free(self);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B04F8);
#ifdef SKIP_ASM
class func_003B04F8_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(void* a, int b);
    virtual void v03();
    virtual int v04();
    virtual float v05();
};

extern "C" int func_003B04F8(void* self, func_003B04F8_cObj* obj, int a2)
{
    *(func_003B04F8_cObj**)((char*)self + 0x14) = obj;
    *(int*)self = a2;
    return obj->v02(self, a2);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0538);
#ifdef SKIP_ASM
struct sVEntry003B0538 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_003B0538(void* self)
{
    void* obj = *(void**)((char*)self + 0x14);
    if (obj != 0) {
        sVEntry003B0538* vt = *(sVEntry003B0538**)obj;
        vt[1].fn((char*)obj + vt[1].delta, 3);
        *(void**)((char*)self + 0x14) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0580);
#ifdef SKIP_ASM
extern "C" int func_003B0580(void* self)
{
    func_003B04F8_cObj* obj = *(func_003B04F8_cObj**)((char*)self + 0x14);
    if (obj == 0) {
        return 0;
    }
    return obj->v04();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B05C0);
#ifdef SKIP_ASM
extern "C" float func_003B05C0(void* self)
{
    func_003B04F8_cObj* obj = *(func_003B04F8_cObj**)((char*)self + 0x14);
    if (obj == 0) {
        return 0.0f;
    }
    return obj->v05();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0600);
#ifdef SKIP_ASM
class func_003B0600_cVirt {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual int v03(int);
};

struct func_003B0600_sObj {
    int loaded;                                    // 0x0
    void* arg;                                     // 0x4
    void (*load)(func_003B0600_sObj*, void*, func_003B0600_sObj*); // 0x8
    char pad_0xC[0x8];
    func_003B0600_cVirt* obj;                      // 0x14
};

extern "C" int func_003B0600(void* p, int a1)
{
    func_003B0600_sObj* self = (func_003B0600_sObj*)p;
    if (self->obj == 0) {
        if (self->loaded == 0) {
            self->load(self, self->arg, self);
        }
    }
    int r;
    if (self->obj != 0) {
        r = self->obj->v03(a1);
    } else {
        r = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0680);
#ifdef SKIP_ASM
class func_003B0680_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int a);
};

extern "C" void func_003B0680(void* self, int a)
{
    (*(func_003B0680_cObj**)((char*)self + 0x14))->v06(a);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B06B0);
#ifdef SKIP_ASM
struct func_003B06B0_sReq {
    int pending;
    int arg;
    void (*fn)(func_003B06B0_sReq* self, int arg, int* out);
};

extern "C" int func_003B06B0(func_003B06B0_sReq* self)
{
    int r;
    int v = self->pending;
    if (v != 0) {
        self->pending = 0;
        r = v;
        return v;
    }
    self->fn(self, self->arg, &r);
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B06F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sWSCb06F8 {
    int pad0;
    void* ctx;
    int pad8;
    void (*fn)(sWSCb06F8* self, void* ctx, int arg);
};

// The unit later declares func_003B06F8(void*, void*) for its caller; bind this definition by asm label.
void func_003B06F8_impl(sWSCb06F8* self, int arg) __asm__("func_003B06F8");
void func_003B06F8_impl(sWSCb06F8* self, int arg)
{
    self->fn(self, self->ctx, arg);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0720__FPv);
#ifdef SKIP_ASM
void* func_003B0720(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)self = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0738__FPv);
#ifdef SKIP_ASM
void* func_003B0738(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 0xc) = 2;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0758);
#ifdef SKIP_ASM
extern "C" void* func_003B0758(void* self, int a1, int a2, int a3, int a4)
{
    *(int*)((char*)self + 0xc) = a4;
    *(int*)self = a1;
    *(int*)((char*)self + 0x4) = a2;
    *(int*)((char*)self + 0x8) = a3;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0770);
#ifdef SKIP_ASM
extern "C" void* func_003B0770(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init != 0) {
            func_003B0410(&D_00509430);
        } else {
            D_00509430.f0C = D_00456890;
        }
    }
}
#endif

extern "C" void* func_003B0770(int, int);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B07B8__FPv);
#ifdef SKIP_ASM
void* func_003B07B8(void* self)
{
    return func_003B0770(1, 0xffff);
}
#endif

extern "C" void* func_003B0770(int, int);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B07D8__FPv);
#ifdef SKIP_ASM
void* func_003B07D8(void* self)
{
    return func_003B0770(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B07F8);
#ifdef SKIP_ASM
extern "C" void* func_003B2A68(unsigned int w, int h, int bpp, int a3, int a4, int flags, int a6, int a7);
extern "C" void* func_003B3D40(void* img);
extern "C" void func_003E6448(void* dst, int value, int size);
extern int D_00509438;

static inline char* func_003B07F8_data(char* p)
{
    if (*(int*)(p + 0xC) & 0x1000) {
        return p + *(int*)(p + 0x10);
    }
    return p + 0x10;
}

extern "C" void* func_003B07F8(void* self, unsigned int w, int h)
{
    *(int*)((char*)self + 0x0) = 2;
    *(int*)((char*)self + 0x8) = 3;
    *(int*)((char*)self + 0xC) = 3;
    *(int*)((char*)self + 0x10) = 0;
    char* img = (char*)func_003B2A68(w, h, 0x20, 0, 0, D_00509438, 0, 0xF0);
    *(char**)((char*)self + 0x4) = img;
    char* hdr = (char*)func_003B3D40(img);
    hdr[4] = 0x32;
    hdr[5] = 0x34;
    hdr[6] = 0x30;
    unsigned int size = ((w >> 4) * h >> 4) << 10;
    func_003E6448(func_003B07F8_data(*(char**)((char*)self + 0x4)), 0, size);
    **(char**)((char*)self + 0x4) = 5;
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B08E0);
#ifdef SKIP_ASM
extern "C" void func_003B2B68(char* buf);

extern "C" void func_003B08E0(void* self, int flags)
{
    if (*(void**)((char*)self + 0x4) != 0) {
        func_003B2B68(*(char**)((char*)self + 0x4));
        *(void**)((char*)self + 0x4) = 0;
    }
    *(int*)((char*)self + 0x8) = 7;
    *(int*)((char*)self + 0xC) = 7;
    if (flags & 1) {
        D_00509430.free(self);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0948);
#ifdef SKIP_ASM
extern void* D_00456850[];

struct sWSNode2 {
    sWSNode2* next;
    sWSNode2* prev;
};

static inline void wsListInit(sWSNode2* h)
{
    h->next = (sWSNode2*)3;
    h->prev = (sWSNode2*)3;
    h->next = h;
    h->prev = h;
    h->next = h;
    h->prev = h;
}

extern "C" void* func_003B0948(void* self)
{
    *(void***)self = D_00456850;
    wsListInit((sWSNode2*)((char*)self + 0x18));
    wsListInit((sWSNode2*)((char*)self + 0x20));
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x78) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B09A0);
#ifdef SKIP_ASM
extern void* D_00456810[];
extern "C" void func_003B08E0(void* self, int flags);
struct sB09A0 {
    void** vt;          // 0x0
    char pad04[0x14];
    sWSNode2 l18;       // 0x18
    sWSNode2 l20;       // 0x20
    char pad28[0x4];
    void* p2C;          // 0x2C
    char pad30[0x48];
    void* p78;          // 0x78
};
static inline void wsListDone(sWSNode2* h)
{
    h->next = (sWSNode2*)7;
    h->prev = (sWSNode2*)7;
}
static inline int wsEmpty(sWSNode2* h) { return h->next == h; }
static inline void* wsItem(sWSNode2* n) { return n ? (char*)n - 8 : 0; }
static inline void wsUnlink(sWSNode2* n)
{
    sWSNode2* next = n->next;
    sWSNode2* prev = n->prev;
    prev->next = next;
    next->prev = prev;
    n->prev = (sWSNode2*)0xB;
    n->next = (sWSNode2*)0xB;
}
extern "C" void func_003B09A0(sB09A0* self, int flags)
{
    self->vt = D_00456850;
    if (self->p2C != 0) {
        D_00509430.free(self->p2C);
        self->p2C = 0;
    }
    if (self->p78 != 0) {
        D_00509430.free(self->p78);
        self->p78 = 0;
    }
    while (!wsEmpty(&self->l18)) {
        sWSNode2* n = self->l18.next;
        void* e = wsItem(n);
        wsUnlink(n);
        if (e != 0)
            func_003B08E0(e, 3);
    }
    while (!wsEmpty(&self->l20)) {
        sWSNode2* n = self->l20.next;
        void* e = wsItem(n);
        wsUnlink(n);
        if (e != 0)
            func_003B08E0(e, 3);
    }
    wsListDone(&self->l20);
    wsListDone(&self->l18);
    self->vt = D_00456810;
    if (flags & 1) {
        D_00509430.free(self);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0B10);
#ifdef SKIP_ASM
extern "C" void func_003B0B40(void* a, void* b, void* c);

extern "C" int func_003B0B10(void* self, void* a1, void* a2)
{
    func_003B0B40(a2, self, a1);
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0B40);
#ifdef SKIP_ASM
extern "C" void func_003B06F8(void* req, void* blk);
extern "C" void func_003E6574(void* dst, void* src, int size);
extern "C" void func_004029D0(void* dst, void* src, int size);

struct func_003B0B40_sBlock {
    int f0;
    void* data;
    int size;
};

struct func_003B0B40_sScript {
    char pad00[0x14];
    int count;
    char pad18[0x10];
    func_003B06B0_sReq* req;
    char pad2C[0x4C];
    void* hdr;
    char* buf;
};

// PORT: func_003B06B0 returns the block pointer as int.
extern "C" void func_003B0B40(void* a, void* b, void* c)
{
    func_003B0B40_sScript* self = (func_003B0B40_sScript*)a;
    void* data = 0;
    func_003B0B40_sBlock* blk = (func_003B0B40_sBlock*)func_003B06B0(self->req);
    if (blk != 0) {
        data = blk->data;
    }
    int total;
    int i;
    if (data != 0) {
        i = blk->size;
        total = (i + 7) & ~0xF;
        i -= 8;
        func_003E6574(self->buf, data, i);
        for (; i < total + 0x10; i += 4) {
            *(int*)(self->buf + i) = 0;
        }
    } else {
        total = 0x10;
        for (i = 0; i < 0x10; i += 4) {
            *(int*)(self->buf + i) = 0xB7010000;
        }
    }
    if (blk != 0) {
        func_003B06F8(self->req, blk);
    }
    self->count++;
    func_004029D0(b, self->hdr, total);
}
#endif

// MPEG decoder layer state: bit reader at the start; D_0050A088 points at the active layer.
struct sMpegLayer {
    unsigned char* p;           // 0x000
    unsigned int bits;          // 0x004
    int count;                  // 0x008
    int f00C;
    int a010[64];               // 0x010
    int a110[64];               // 0x110
    int a210[64];               // 0x210
    int a310[64];               // 0x310
    int f410;
    int f414;
    int f418;
    int f41C;
    int f420;
    int f424;
    int f428;
    int f42C;
    int f430;
    int f434;
    int f438;
    int f43C;
};
extern sMpegLayer* D_0050A088;
extern sMpegLayer D_00509648;

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0C58);
#ifdef SKIP_ASM
extern int D_005094F4;
extern int D_005094F8;
extern int D_005094FC;
extern int D_00509500;
extern int D_00509524;
extern int D_00509548;
extern int D_00509584;
extern int D_0050958C;
extern int D_005095A0;
extern int D_005094D4;
extern int D_005094D8;
extern int D_005094DC;
extern int D_005094E0;
extern char D_004953E8[];
extern char D_004953F0[];
extern char D_00495400[];
extern "C" void func_003B1228(void* data);
extern "C" int func_003B13D8(void);
extern "C" void* func_003B07F8(void* self, unsigned int w, int h);
extern "C" void func_00402708(void);
extern "C" void func_004027B8(void* a, void* b, int size);
extern "C" void* func_00402C08(void* a, int n, void* fn, void* arg);
extern "C" int func_003B0B10(void* self, void* a1, void* a2);

struct sWSNode_B0C58 {
    sWSNode_B0C58* next;
    sWSNode_B0C58* prev;
};

struct sScript_B0C58 {
    char pad00[0x10];
    int count;
};

struct sData_B0C58 {
    int f0;
    void* data;
};

struct sPlayer_B0C58 {
    int f0;
    int state;              // 0x4
    int w;                  // 0x8
    int h;                  // 0xC
    int f10;                // 0x10
    int f14;                // 0x14
    sWSNode_B0C58 list18;   // 0x18
    sWSNode_B0C58 frames;   // 0x20
    sScript_B0C58* script;  // 0x28
    void* work;             // 0x2C
    char mpeg[0x48];        // 0x30
    void* ipuBuf;           // 0x78
    void* ipuBufUc;         // 0x7C
};

extern "C" int func_003B0C58(sPlayer_B0C58* self, sScript_B0C58* script, sData_B0C58* d)
{
    self->script = script;
    self->f10 = 0;
    self->f14 = 0;
    if (self->work != 0) {
        D_00509430.free(self->work);
        self->work = 0;
    }
    if (self->ipuBuf != 0) {
        D_00509430.free(self->ipuBuf);
        self->ipuBuf = 0;
    }
    self->state = 1;
    void* data = d->data;
    D_0050A088 = &D_00509648;
    func_003B1228(data);
    func_003B13D8();
    int mode = D_00509648.f420;
    if (mode == 0) {
        D_00509524 = 1;
        D_005095A0 = 1;
        D_00509584 = 3;
        D_0050958C = 1;
        D_00509548 = 5;
    }
    D_005094FC = (D_005094F4 + 15) / 16;
    D_00509500 = (mode != 0 && D_00509524 == 0) ? (D_005094F8 + 31) / 32 * 2 : (D_005094F8 + 15) / 16;
    int w = D_005094FC * 16;
    D_005094D4 = w;
    self->w = w;
    int h = D_00509500 * 16;
    D_005094D8 = h;
    self->h = h;
    D_005094DC = w >> 1;
    D_005094E0 = h >> 1;
    int n = self->script->count;
    for (int i = 0; i < n; i++) {
        int cw = self->w;
        int ch = self->h;
        char* r = (char*)func_003B07F8(D_00509430.alloc(D_004953E8, 0x14, 0, 0, D_00509430.flags), cw, ch);
        sWSNode_B0C58* node = r ? (sWSNode_B0C58*)(r + 8) : 0;
        sWSNode_B0C58* head = &self->frames;
        sWSNode_B0C58* old = head->next;
        head->next = node;
        old->prev = node;
        node->next = old;
        node->prev = head;
    }
    self->work = D_00509430.alloc(D_004953F0, self->w * self->h * 9 / 2 + 0x176C, 0, 0, D_00509430.flags | 0x400);
    self->ipuBuf = D_00509430.alloc(D_00495400, 0x32000, 0, 0, D_00509430.flags | 0x400);
    self->ipuBufUc = (void*)(((unsigned int)self->ipuBuf & 0x0FFFFFFF) | 0x30000000);
    func_00402708();
    func_004027B8(self->mpeg, self->work, self->w * self->h * 9 / 2 + 0x176C);
    func_00402C08(self->mpeg, 1, (void*)func_003B0B10, self);
    return 2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0FA0__FPv);
#ifdef SKIP_ASM
int func_003B0FA0(void* self)
{
    return *(int*)((char*)self + 0x10);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0FA8);
#ifdef SKIP_ASM
extern float D_00509508;

extern "C" float func_003B0FA8()
{
    return D_00509508;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B0FB8);
#ifdef SKIP_ASM
struct sWSPool;
struct sWSItem;
extern "C" sWSItem* func_003B10D0(sWSPool* self);
extern "C" void func_00402A10(void* dma, void* data, int qwc);

extern "C" void* func_003B0FB8(void* self)
{
    sWSItem* item = func_003B10D0((sWSPool*)self);
    char* hdr = *(char**)((char*)item + 0x4);
    char* data;
    if (*(int*)(hdr + 0xC) & 0x1000) {
        data = hdr + *(int*)(hdr + 0x10);
    } else {
        data = hdr + 0x10;
    }
    func_00402A10((char*)self + 0x30, data, *(int*)((char*)self + 0x8) / 16 * *(int*)((char*)self + 0xC) / 16);
    *(int*)((char*)self + 0x10) += 1;
    return item;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1050);
#ifdef SKIP_ASM
extern "C" void* func_003B0FB8(void* self);
extern "C" int func_00402B38(void* sema);

class func_003B1050_cCache {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(void*);
};

extern "C" void* func_003B1050(func_003B1050_cCache* self, unsigned int limit)
{
    void* item = 0;
    do {
        if (item != 0) {
            self->v06(item);
        }
        if (func_00402B38((char*)self + 0x30) != 0) {
            return 0;
        }
        item = func_003B0FB8(self);
    } while (*(unsigned int*)((char*)self + 0x10) < limit);
    return item;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B10D0);
#ifdef SKIP_ASM
struct sWSNode {
    sWSNode* next;
    sWSNode* prev;

    void unlink()
    {
        sWSNode* n = next;
        sWSNode* p = prev;
        p->next = n;
        n->prev = p;
        prev = next = (sWSNode*)0xB;
    }
};

struct sWSList {
    sWSNode head;

    void addTail(sWSNode* n)
    {
        sWSNode* tail = head.prev;
        tail->next = n;
        head.prev = n;
        n->prev = tail;
        n->next = &head;
    }
};

struct sWSItemBase {
    int a;
    int b;
};

struct sWSItem : sWSItemBase, sWSNode {
    int refs; // 0x10
};

struct sWSPool {
    char pad00[0x18];
    sWSList used; // 0x18
    sWSList free; // 0x20
};

extern "C" sWSItem* func_003B10D0(sWSPool* self)
{
    sWSNode* n = self->free.head.next;
    if (n != &self->free.head) {
        sWSItem* item;
        n->unlink();
        item = static_cast<sWSItem*>(n);
        self->used.addTail(item);
        item->refs = 1;
        return item;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1140);
#ifdef SKIP_ASM
extern "C" void func_003B1140(sWSPool* self, sWSItem* item)
{
    if (--item->refs > 0) {
        return;
    }
    item->unlink();
    self->free.addTail(item);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B11A0);
#ifdef SKIP_ASM
extern "C" void* func_003B11A0(void)
{
    return func_003B0948(D_00509430.alloc(D_004953E8, 0x80, 0, 0, D_00509430.flags));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B11E8__FPv);
#ifdef SKIP_ASM
void func_003B11E8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B11F0);
#ifdef SKIP_ASM
extern int D_00495448[];

extern "C" int func_003B11F0(int v)
{
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (D_00495448[i] == v) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1228);
#ifdef SKIP_ASM
extern "C" void func_003B1290(int n);

extern "C" void func_003B1228(void* data)
{
    sMpegLayer* r = D_0050A088;
    r->p = (unsigned char*)data;
    r->count = 0;
    r->bits = 0;
    func_003B1290(0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1258);
#ifdef SKIP_ASM
extern "C" unsigned int func_003B1258(int a0)
{
    return D_0050A088->bits >> (unsigned int)(-a0);
}
#endif

extern "C" int func_003B1300(int);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1270__FPv);
#ifdef SKIP_ASM
int func_003B1270(void* self)
{
    return func_003B1300(1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1290);
#ifdef SKIP_ASM
// Reads the next byte into the bit buffer; taking the reader by reference matches the target's register copy.
static inline void FillByte(sMpegLayer*& r, int c)
{
    r->bits |= *r->p++ << (24 - c);
}

// Drops n bits from the bit buffer and refills it a byte at a time.
extern "C" void func_003B1290(int n)
{
    sMpegLayer* r = D_0050A088;
    r->bits <<= n;
    int c = r->count - n;
    while (c < 25) {
        FillByte(r, c);
        c += 8;
    }
    D_0050A088->count = c;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1300);
#ifdef SKIP_ASM
extern "C" void func_003B1290(int n);

extern "C" int func_003B1300(int n)
{
    unsigned int v = func_003B1258(n);
    func_003B1290(n);
    return v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1340);
#ifdef SKIP_ASM
// Drops the whole 32-bit buffer and refills it a byte at a time.
extern "C" void func_003B1340(void)
{
    sMpegLayer* r = D_0050A088;
    r->bits = 0;
    int c = r->count - 32;
    while (c < 25) {
        FillByte(r, c);
        c += 8;
    }
    D_0050A088->count = c;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B13A8);
#ifdef SKIP_ASM
extern "C" void func_003B1340(void);

extern "C" unsigned int func_003B13A8(void)
{
    unsigned int v = func_003B1258(0x20);
    func_003B1340();
    return v;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B13D8);
#ifdef SKIP_ASM
// PORT: func_003B1498 takes no arguments (the unit declares it void*(void*)); bound by asm label
extern "C" void func_003B1498_noarg(void) __asm__("func_003B1498");
extern "C" void func_003B14F0(void);
extern "C" void group_of_pictures_header(void);
extern "C" void func_003B17A8(void);

extern "C" int func_003B13D8(void)
{
    for (;;) {
        func_003B1498_noarg();
        switch ((int)func_003B13A8()) {
        case 0x1B3:
            func_003B14F0();
            break;
        case 0x1B8:
            group_of_pictures_header();
            break;
        case 0x1B7:
            return 0;
        case 0x100:
            func_003B17A8();
            return 1;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1498);
#ifdef SKIP_ASM
extern "C" void func_003B1290(int n);

// PORT: no return value here; the unit declares it void* and callers forward $v0.
void func_003B1498_impl(void* self) __asm__("func_003B1498");

void func_003B1498_impl(void* self)
{
    func_003B1290(D_0050A088->count & 7);
    while (func_003B1258(0x18) != 1) {
        func_003B1290(8);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2AEDC0", func_003B14F0);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", group_of_pictures_header);
#ifdef SKIP_ASM
extern int D_0044C378;
extern int D_0044C37C;
extern int D_0044C380;
extern int D_00509628;
extern int D_0050962C;
extern int D_00509630;
extern int D_00509634;
extern int D_00509638;
extern int D_0050963C;
extern int D_00509640;
extern char D_00495468[];
int func_003B2360(void* self);
extern "C" void func_003B1988(void);

extern "C" void group_of_pictures_header(void)
{
    if (D_0050A088 == &D_00509648) {
        D_0044C378 = D_0044C37C + 1;
        D_0044C380 = 1;
    }
    D_00509628 = func_003B1300(1);
    D_0050962C = func_003B1300(5);
    D_00509630 = func_003B1300(6);
    func_003B2360(D_00495468);
    D_00509634 = func_003B1300(6);
    D_00509638 = func_003B1300(6);
    D_0050963C = func_003B1300(1);
    D_00509640 = func_003B1300(1);
    func_003B1988();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B17A8);
#ifdef SKIP_ASM
extern int D_00509554;
extern int D_00509558;
extern int D_0050955C;
extern int D_00509560;
extern int D_00509564;
extern int D_00509568;
extern int D_0050956C;
extern "C" void func_003B1988(void);
extern "C" int func_003B2318(void);
extern "C" void func_003B2440(void);

extern "C" void func_003B17A8(void)
{
    D_0050A088->f430 = 0;
    D_00509554 = func_003B1300(0xA);
    D_00509558 = func_003B1300(3);
    D_0050955C = func_003B1300(0x10);
    if (D_00509558 == 2 || D_00509558 == 3) {
        D_00509560 = func_003B1300(1);
        D_00509564 = func_003B1300(3);
    }
    if (D_00509558 == 3) {
        D_00509568 = func_003B1300(1);
        D_0050956C = func_003B1300(3);
    }
    func_003B2318();
    func_003B1988();
    func_003B2440();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1878);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044C2D8[];
extern int D_005094F8;

extern "C" int func_003B1878(void)
{
    int r;
    int v;
    int t;

    if (D_0050A088->f420 != 0) {
        r = 0;
        if (D_005094F8 >= 0xAF1) {
            r = func_003B1300(3);
        }
    } else {
        r = 0;
    }
    if (D_0050A088->f424 == 1) {
        D_0050A088->f434 = func_003B1300(7);
    }
    t = func_003B1300(5);
    {
        sMpegLayer* p = D_0050A088;
        p->f438 = p->f420 != 0
            ? (p->f428 != 0 ? (int)D_0044C2D8[t] : t * 2)
            : t;
    }
    if (func_003B1300(1) != 0) {
        D_0050A088->f43C = func_003B1300(1);
        func_003B1300(1);
        func_003B1300(6);
        func_003B2318();
    } else {
        D_0050A088->f43C = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1988);
#ifdef SKIP_ASM
extern "C" unsigned int func_003B1258(int a0);
extern "C" void func_003B1340(void);
extern "C" void func_003B1498_v(void) __asm__("func_003B1498");
extern "C" void func_003B2380_v(void) __asm__("func_003B2380__FPv");
extern "C" void func_003B1AB0(void);
extern "C" void func_003B1CC0(void);
extern "C" void func_003B1D58(void);
extern "C" void sequence_scalable_extension(void);
extern "C" void func_003B1FC8(void);
extern "C" void func_003B20B8(void);
extern "C" void picture_spatial_scalable_extension(void);
extern "C" void func_003B22F8(void);
extern "C" void copyright_extension(void);

// Parses a script block: runs one command per 0x1B5 token, skips 0x1B2 sections.
extern "C" void func_003B1988(void)
{
    unsigned int tok;
    func_003B1498_v();
    while ((tok = func_003B1258(0x20)) == 0x1B5 || tok == 0x1B2) {
        if (tok == 0x1B5) {
            func_003B1340();
            switch (func_003B1300(4)) {
            case 1: func_003B1AB0(); break;
            case 2: func_003B1CC0(); break;
            case 3: func_003B1D58(); break;
            case 5: sequence_scalable_extension(); break;
            case 7: func_003B1FC8(); break;
            case 8: func_003B20B8(); break;
            case 9: picture_spatial_scalable_extension(); break;
            case 10: func_003B22F8(); break;
            case 4: copyright_extension(); break;
            case 6: break;
            }
            func_003B1498_v();
        } else {
            func_003B1340();
            func_003B2380_v();
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1AB0);
#ifdef SKIP_ASM
extern int D_005095DC;
extern int D_00509520;
extern int D_00509524;
extern int D_00509528;
extern int D_0050952C;
extern int D_00509530;
extern int D_00509534;
extern int D_00509510;
extern int D_00509514;
extern int D_00509518;
extern int D_005094EC;
extern int D_005094F0;
extern int D_005094F4;
extern int D_005094F8;
extern float D_00509504;
extern float D_00509508;
extern float D_0044C388[];
extern char D_004954B8[];
int func_003B2360(void* self);

// Parse an MPEG-2 sequence extension.
extern "C" void func_003B1AB0(void)
{
    sMpegLayer* g = D_0050A088;
    g->f420 = 1;
    g->f424 = 0;
    D_005095DC = 0;
    D_00509520 = func_003B1300(8);
    D_00509524 = func_003B1300(1);
    D_00509528 = func_003B1300(2);
    int hext = func_003B1300(2);
    int vext = func_003B1300(2);
    int brext = func_003B1300(0xC);
    func_003B2360(D_004954B8);
    int vbvext = func_003B1300(8);
    D_0050952C = func_003B1300(1);
    D_00509530 = func_003B1300(2);
    D_00509534 = func_003B1300(5);
    D_00509508 = D_0044C388[D_00509510] * ((float)(D_00509530 + 1) / (float)(D_00509534 + 1));
    if ((D_00509520 >> 7) & 1) {
        if ((D_00509520 & 0xF) == 5) {
            D_005094EC = 0x85;
            D_005094F0 = 8;
        }
    } else {
        D_005094EC = D_00509520 >> 4;
        D_005094F0 = D_00509520 & 0xF;
    }
    D_005094F4 = (hext << 12) | (D_005094F4 & 0xFFF);
    D_005094F8 = (vext << 12) | (D_005094F8 & 0xFFF);
    D_00509514 = D_00509514 + (brext << 18);
    D_00509504 = D_00509514 * 400.0f;
    D_00509518 = D_00509518 + (vbvext << 10);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1CC0);
#ifdef SKIP_ASM
extern int D_00509538;
extern int D_0050953C;
extern int D_00509540;
extern int D_00509544;
extern int D_00509548;
extern int D_0050954C;
extern int D_00509550;
extern char D_004954D0[];
int func_003B2360(void* self);

extern "C" void func_003B1CC0(void)
{
    D_00509538 = func_003B1300(3);
    D_0050953C = func_003B1300(1);
    if (D_0050953C != 0) {
        D_00509540 = func_003B1300(8);
        D_00509544 = func_003B1300(8);
        D_00509548 = func_003B1300(8);
    }
    D_0050954C = func_003B1300(0xE);
    func_003B2360(D_004954D0);
    D_00509550 = func_003B1300(0xE);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1D58);
#ifdef SKIP_ASM
extern unsigned char D_0044C218[];

extern "C" void func_003B1D58(void)
{
    sMpegLayer** cur = &D_0050A088;
    {
        int p = func_003B1300(1);
        (*cur)->f410 = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                int q = func_003B1300(8);
                int k = D_0044C218[i];
                D_0050A088->a010[k] = q;
                D_0050A088->a210[k] = q;
            }
        }
    }
    {
        int p = func_003B1300(1);
        D_0050A088->f414 = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                int q = func_003B1300(8);
                int k = D_0044C218[i];
                D_0050A088->a110[k] = q;
                D_0050A088->a310[k] = q;
            }
        }
    }
    {
        int p = func_003B1300(1);
        D_0050A088->f418 = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                int q = func_003B1300(8);
                int k = D_0044C218[i];
                D_0050A088->a210[k] = q;
            }
        }
    }
    {
        int p = func_003B1300(1);
        D_0050A088->f41C = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                int q = func_003B1300(8);
                int k = D_0044C218[i];
                D_0050A088->a310[k] = q;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", sequence_scalable_extension);
#ifdef SKIP_ASM
extern int D_005095DC;
extern int D_005095E0;
extern int D_005095E4;
extern int D_005095E8;
extern int D_005095EC;
extern int D_005095F0;
extern int D_005095F4;
extern char D_004954F0[];
extern char D_00495510[];
int func_003B2360(void* self);
void func_003B11E8(void* self);

extern "C" void sequence_scalable_extension(void)
{
    D_0050A088->f424 = func_003B1300(2) + 1;
    D_005095DC = func_003B1300(4);
    if (D_0050A088->f424 == 2) {
        D_005095E0 = func_003B1300(0xE);
        func_003B2360(D_004954F0);
        D_005095E4 = func_003B1300(0xE);
        D_005095E8 = func_003B1300(5);
        D_005095EC = func_003B1300(5);
        D_005095F0 = func_003B1300(5);
        D_005095F4 = func_003B1300(5);
    }
    if (D_0050A088->f424 == 4) {
        func_003B11E8(D_00495510);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B1FC8);
#ifdef SKIP_ASM
extern int D_00509524;
extern int D_00509584;
extern int D_00509588;
extern int D_00509598;
extern int D_005095C0[];
extern int D_005095D0[];
extern char D_00495538[];
extern char D_00495568[];
int func_003B2360(void* self);

extern "C" void func_003B1FC8(void)
{
    int n;
    int i;
    if (D_00509524 != 0) {
        if (D_00509598 == 0) {
            n = 1;
        } else {
            n = D_00509588 != 0 ? 3 : 2;
        }
    } else if (D_00509584 != 3) {
        n = 1;
    } else {
        n = D_00509598 != 0 ? 3 : 2;
    }
    for (i = 0; i < n; i++) {
        D_005095C0[i] = func_003B1300(0x10);
        func_003B2360(D_00495538);
        D_005095D0[i] = func_003B1300(0x10);
        func_003B2360(D_00495568);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B20B8);
#ifdef SKIP_ASM
extern int D_00509570[];
extern int D_00509580;
extern int D_00509584;
extern int D_00509588;
extern int D_0050958C;
extern int D_00509590;
extern int D_00509594;
extern int D_00509598;
extern int D_0050959C;
extern int D_005095A0;
extern int D_005095A4;
extern int D_005095A8;
extern int D_005095AC;
extern int D_005095B0;
extern int D_005095B4;
extern int D_005095B8;

extern "C" void func_003B20B8(void)
{
    D_00509570[0] = func_003B1300(4);
    D_00509570[1] = func_003B1300(4);
    D_00509570[2] = func_003B1300(4);
    D_00509570[3] = func_003B1300(4);
    D_00509580 = func_003B1300(2);
    D_00509584 = func_003B1300(2);
    D_00509588 = func_003B1300(1);
    D_0050958C = func_003B1300(1);
    D_00509590 = func_003B1300(1);
    D_0050A088->f428 = func_003B1300(1);
    D_00509594 = func_003B1300(1);
    D_0050A088->f42C = func_003B1300(1);
    D_00509598 = func_003B1300(1);
    D_0050959C = func_003B1300(1);
    D_005095A0 = func_003B1300(1);
    D_005095A4 = func_003B1300(1);
    if (D_005095A4 != 0) {
        D_005095A8 = func_003B1300(1);
        D_005095AC = func_003B1300(3);
        D_005095B0 = func_003B1300(1);
        D_005095B4 = func_003B1300(7);
        D_005095B8 = func_003B1300(8);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", picture_spatial_scalable_extension);
#ifdef SKIP_ASM
extern int D_005095F8;
extern int D_005095FC;
extern int D_00509600;
extern int D_00509604;
extern int D_00509608;
extern int D_0050960C;
extern char D_00495598[];
extern char D_004955D0[];
int func_003B2360(void* self);

extern "C" void picture_spatial_scalable_extension(void)
{
    D_0050A088->f430 = 1;
    D_005095F8 = func_003B1300(0xA);
    func_003B2360(D_00495598);
    D_005095FC = func_003B1300(0xF);
    if (D_005095FC >= 0x4000) {
        D_005095FC -= 0x8000;
    }
    func_003B2360(D_004955D0);
    D_00509600 = func_003B1300(0xF);
    if (D_00509600 >= 0x4000) {
        D_00509600 -= 0x8000;
    }
    D_00509604 = func_003B1300(2);
    D_00509608 = func_003B1300(1);
    D_0050960C = func_003B1300(1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B22F8);
#ifdef SKIP_ASM
extern int D_00495608[];

extern "C" void func_003B22F8(void)
{
    func_003B11E8(D_00495608);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2318);
#ifdef SKIP_ASM
// PORT: func_003B1270 takes a void* it never reads; this caller passes nothing, so it binds
// a no-argument declaration to the mangled symbol.
int func_003B1270_noarg() __asm__("func_003B1270__FPv");

extern "C" int func_003B2318(void)
{
    int n = 0;
    while (func_003B1270_noarg() != 0) {
        func_003B1290(8);
        n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2360__FPv);
#ifdef SKIP_ASM
int func_003B2360(void* self)
{
    return func_003B1300(1);
}
#endif

extern "C" void* func_003B1498(void* self);

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2380__FPv);
#ifdef SKIP_ASM
void* func_003B2380(void* self)
{
    return func_003B1498(self);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", copyright_extension);
#ifdef SKIP_ASM
extern int D_00509610;
extern int D_00509614;
extern int D_00509618;
extern int D_0050961C;
extern int D_00509620;
extern int D_00509624;
extern char D_00495630[];
extern char D_00495658[];
extern char D_00495688[];
int func_003B2360(void* self);

extern "C" void copyright_extension(void)
{
    D_00509610 = func_003B1300(1);
    D_00509614 = func_003B1300(8);
    D_00509618 = func_003B1300(1);
    func_003B1300(7);
    func_003B2360(D_00495630);
    D_0050961C = func_003B1300(0x14);
    func_003B2360(D_00495658);
    D_00509620 = func_003B1300(0x16);
    func_003B2360(D_00495688);
    D_00509624 = func_003B1300(0x16);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2440);
#ifdef SKIP_ASM
extern int D_00509554;
extern int D_00509558;
extern int D_0044C378;
extern int D_0044C37C;
extern int D_0044C380;
extern int D_0044C3C8;
extern int D_0044C3CC;
extern int D_0050A098;

extern "C" void func_003B2440(void)
{
    if (D_0050A088 != &D_00509648) {

        return;
    }
    int last;
    if (D_00509558 != 3 && D_00509554 != (last = D_0044C3CC)) {
        if (D_0044C3C8 != 0) {
            D_0044C3C8 = 0;
            D_0044C378 += 0x400;
        }
        if (D_00509554 < last && D_0044C380 == 0) {
            D_0044C3C8 = 1;
        }
        D_0044C380 = 0;
        D_0044C3CC = D_00509554;
    }
    D_0050A098 = D_0044C378 + D_00509554;
    if (D_0044C3C8 != 0 && D_0044C3CC >= D_00509554) {
        D_0050A098 += 0x400;
    }
    D_0044C37C = (D_0044C37C < D_0050A098) ? D_0050A098 : D_0044C37C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2528);
#ifdef SKIP_ASM
struct func_003B2528_sKey {
    char c;
};

extern "C" char func_003B3DA8(int key);
extern "C" unsigned char func_003B39D8(func_003B2528_sKey* k);

extern "C" int func_003B2528(int key)
{
    func_003B2528_sKey k;
    if (key == 0) {
        key = 0x20;
    }
    k.c = func_003B3DA8(key);
    return func_003B39D8(&k);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2558);
#ifdef SKIP_ASM
extern "C" int func_003B2528(int fmt);

extern "C" int func_003B2558(int w, int h, int fmt, int maxLevel)
{
    int total = 0;
    int c = func_003B2528(fmt);
    int bpp = 0x10;
    if (c != 0xF) bpp = c;
    if (w < 1 || w > 0x10000 || h < 1) return 0;
    if (h > 0x10000) return 0;
    if (w * h > 1000000000) return 0;
    if (func_003B3DA8(c) == 0) return 0;
    int i;
    for (i = 0; i <= maxLevel; i++) {
        int lw = w >> i;
        int lh = h >> i;
        if (lw <= 0) lw = 1;
        if (lh <= 0) lh = 1;
        if (total != 0) total = (total + 0xF) & ~0xF;
        total += ((lw * bpp + 7) / 8) * lh;
        if (lw == 1 && lh == 1) break;
    }
    return total;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2688);
#ifdef SKIP_ASM
extern "C" int func_003B2688(int v)
{
    switch (v) {
    case 8:
        return 0x100;
    case 4:
        return 0x10;
    default:
        return 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B26B8);
#ifdef SKIP_ASM
extern "C" int func_003B2528(int fmt);
extern "C" int func_003B2558(int w, int h, int fmt, int maxLevel);

extern "C" int func_003B26B8(int w, int h, int fmt, int clut, int maxLevel, int extra1, int extra2)
{
    int c = func_003B2528(fmt);
    int size = func_003B2558(w, h, fmt, maxLevel);
    size += 0x10;
    if (c < 9 && clut != 0) {
        if (clut == 0xF) clut = 0x10;
        if (size != 0) size = (size + 0xF) & ~0xF;
        int n = func_003B2688(c) * clut / 8 + 0x10;
        size = ((size + 0xF) & ~0xF) + n;
    }
    if (extra1 != 0) {
        int t = size + 8;
        size = t + extra1;
    }
    if (extra2 != 0) {
        int t = size + 0x10;
        size = t + extra2;
    }
    return size;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B27C8);
#ifdef SKIP_ASM
extern "C" char func_003B3DA8(int key);
extern "C" void func_003E6448(void* dst, int value, int size);
// PORT: memset-like fill called with an unsigned all-ones value here
extern "C" void func_003E6448_u(void* dst, unsigned int value, int size) __asm__("func_003E6448");
extern "C" int func_003B2558(int w, int h, int fmt, int maxLevel);
extern "C" int func_003B2688(int v);
extern "C" unsigned char func_003B38B8(int clut);

struct sTexHdr_27C8 {
    unsigned type : 8;          // 0x0
    unsigned next : 24;
    short w;                    // 0x4
    short h;                    // 0x6
    int f8;                     // 0x8
    unsigned flags : 28;        // 0xC
    unsigned levels : 4;
    int dataOff;                // 0x10
};

struct sRGBA_27C8 {
    unsigned char r, g, b, a;
};

static inline unsigned char* texData_27C8(sTexHdr_27C8* t)
{
    if (*(int*)((char*)t + 0xC) & 0x1000) {
        return (unsigned char*)t + t->dataOff;
    }
    return (unsigned char*)t + 0x10;
}

extern "C" void func_003B27C8(void* tex, int w, int h, int fmt, int clut, int levels, int extra1, int extra2)
{
    sTexHdr_27C8* t = (sTexHdr_27C8*)tex;
    int bpp = 0x20;
    if (fmt != 0) bpp = fmt;
    char c = func_003B3DA8(bpp);
    func_003E6448(t, 0, 0x10);
    t->type = c;
    t->w = w;
    t->h = h;
    t->levels = levels;
    sTexHdr_27C8* hdr = t;
    unsigned char* p = (unsigned char*)hdr + (func_003B2558(w, h, bpp, levels) + 0x10);
    if (bpp < 9 && clut != 0) {
        int n = func_003B2688(bpp);
        unsigned char cfmt = func_003B38B8(clut);
        int off = ((p - (unsigned char*)hdr) + 0xF) & ~0xF;
        p = (unsigned char*)hdr + off;
        int cbits = 0x10;
        if (clut != 0xF) cbits = clut;
        hdr->next = off;
        func_003E6448(p, 0, 0x10);
        ((sTexHdr_27C8*)p)->type = cfmt;
        ((sTexHdr_27C8*)p)->h = 1;
        ((sTexHdr_27C8*)p)->w = n;
        if (clut >= 0x20) {
            sRGBA_27C8* pal = (sRGBA_27C8*)texData_27C8((sTexHdr_27C8*)p);
            for (int i = 0; i < n; i++) {
                pal[i].b = i;
                pal[i].g = i;
                pal[i].r = i;
                pal[i].a = 0xFF;
            }
        } else {
            func_003E6448_u(texData_27C8((sTexHdr_27C8*)p), 0xFFFFFFFF, n * cbits / 8);
        }
        hdr = (sTexHdr_27C8*)p;
        p += n * cbits / 8 + 0x10;
    }
    if (extra1 != 0) {
        hdr->next = p - (unsigned char*)hdr;
        hdr = (sTexHdr_27C8*)p;
        func_003E6448(p, 0, extra1 + 8);
        *(int*)(p + 4) = extra1;
        p[0] = 0x6F;
        p += extra1 + 8;
    }
    if (extra2 != 0) {
        hdr->next = p - (unsigned char*)hdr;
        func_003E6448(p, 0, extra2 + 0x10);
        p[0] = 0x69;
        *(short*)(p + 6) = 0x10;
        *(int*)(p + 0x10) = 0x455355;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2A68);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_003B26B8(int w, int h, int fmt, int clut, int maxLevel, int extra1, int extra2);
extern "C" void func_003B27C8(void* tex, int w, int h, int fmt, int clut, int maxLevel, int extra1, int extra2);
extern void* (*D_0044C454)(char* name, int size, int a2, int align, int heap);
extern char D_004956B0[];

extern "C" void* func_003B2A68(unsigned int w, int h, int fmt, int clut, int maxLevel, int heap, int extra1, int extra2)
{
    char name[16];
    void* tex = 0;
    int size = func_003B26B8(w, h, fmt, clut, maxLevel, extra1, extra2);
    if (size != 0) {
        sprintf(name, D_004956B0, w, h, fmt);
        tex = D_0044C454(name, size, 0, 0x10, heap);
        if (tex != 0) {
            func_003B27C8(tex, w, h, fmt, clut, maxLevel, extra1, extra2);
        }
    }
    return tex;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2B68);
#ifdef SKIP_ASM
extern void (*D_0044C458)(char* buf);

extern "C" void func_003B2B68(char* buf)
{
    buf[0] = 0;
    D_0044C458(buf);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2B90);
#ifdef SKIP_ASM
// Decodes one 4x4 alpha block into the alpha bytes of dst: mode 3 is DXT3 (explicit 4-bit alpha),
// anything else is DXT5 (two endpoints + 3-bit indices).
// NOTE: the DXT3 path steps through dst as `unsigned long` (64-bit on the EE), not as 32-bit pixels.
// PORT: callers declare func_003B2B90 with char* parameters; defined under an asm label.
extern "C" void func_003B2B90_impl(unsigned long* dst, int stride, unsigned char* src, int mode) __asm__("func_003B2B90");
extern "C" void func_003B2B90_impl(unsigned long* dst, int stride, unsigned char* src, int mode)
{
    if (mode == 3) {
        for (unsigned int y = 0; y < 4; y++) {
            for (unsigned int x = 0; x < 2; x++) {
                unsigned char b = *src++;
                unsigned int lo = b & 0xF;
                *dst = (*dst & 0xFFFFFF) | (int)((lo | (lo << 4)) << 24);
                dst++;
                unsigned int hi = b & 0xF0;
                *dst = (*dst & 0xFFFFFF) | (int)((hi | (hi >> 4)) << 24);
                dst++;
            }
            dst = (unsigned long*)((char*)dst + stride - 0x20);
        }
        return;
    }
    unsigned char* s = src;
    unsigned char* d = (unsigned char*)dst + 3;
    unsigned char a0 = *s++;
    unsigned char a1 = *s++;
    unsigned char a2, a3, a4, a5, a6, a7;
    if (a0 > a1) {
        a2 = (6 * a0 + a1 + 3) / 7;
        a3 = (5 * a0 + 2 * a1 + 3) / 7;
        a4 = (4 * a0 + 3 * a1 + 3) / 7;
        a5 = (3 * a0 + 4 * a1 + 3) / 7;
        a6 = (2 * a0 + 5 * a1 + 3) / 7;
        a7 = (a0 + 6 * a1 + 3) / 7;
    } else {
        a2 = (4 * a0 + a1 + 2) / 5;
        a3 = (3 * a0 + 2 * a1 + 2) / 5;
        a4 = (2 * a0 + 3 * a1 + 2) / 5;
        a5 = (a0 + 4 * a1 + 2) / 5;
        a6 = 0;
        a7 = 0xFF;
    }
    for (int i = 0; i < 2; i++) {
        unsigned long bits = *(unsigned long*)s;
        s += 3;
        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < 4; x++) {
                unsigned char idx = bits & 7;
                bits >>= 3;
                switch (idx) {
                case 0: *d = a0; break;
                case 1: *d = a1; break;
                case 2: *d = a2; break;
                case 3: *d = a3; break;
                case 4: *d = a4; break;
                case 5: *d = a5; break;
                case 6: *d = a6; break;
                case 7: *d = a7; break;
                }
                d += 4;
            }
            d += stride - 0x10;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B2E78);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` palette entries (`long` is 8 bytes on this compiler).
static inline unsigned short dxtTo1555_2E78(unsigned short c)
{
    if (c != 0) {
        // the alpha bit is a sign-extended short constant (forces the final 16-bit mask)
        int g = ((c >> 1) & 0x3E0) | (short)0x8000;
        c = ((c & 0x1F) << 10) | g | (c >> 11);
    }
    return c;
}

// Decode one DXT1 block into 4 rows of 4 64-bit texels.
extern "C" void func_003B2E78(char* src, int pitch, char* dst)
{
    ulong pal[4];
    ulong c = *(ulong*)dst;
    ulong c0 = ((c & 0x1F) << 3) | ((c & 0x7E0) << 5) | ((c & 0xF800) << 8);
    ulong c1 = ((c >> 13) & 0xF8) | ((c >> 11) & 0xFC00) | ((c & 0xF8000000) >> 8);
    pal[0] = c0 | 0x40204;
    pal[1] = c1 | 0x40204;
    if (c0 >= c1) {
        int b0 = c0 & 0xFF0000;
        int b1 = c1 & 0xFF0000;
        int g0 = c0 & 0xFF00;
        int g1 = c1 & 0xFF00;
        int r0 = c0 & 0xFF;
        int r1 = c1 & 0xFF;
        pal[2] = ((((b0 * 5 + b1 * 3) >> 3) & 0xFF0000) | (((g0 * 5 + g1 * 3) >> 3) & 0xFF00)) | (((r0 * 5 + r1 * 3) >> 3) & 0xFF);
        pal[3] = (((((b0 * 3 + b1 * 5) >> 3) & 0xFF0000) | (((g0 * 3 + g1 * 5) >> 3) & 0xFF00)) | (((r0 * 3 + r1 * 5) >> 3) & 0xFF)) | 0xFF000000UL;
    } else {
        int b0 = c0 & 0xFF0000;
        int b1 = c1 & 0xFF0000;
        int g0 = c0 & 0xFF00;
        int g1 = c1 & 0xFF00;
        int r0 = c0 & 0xFF;
        int r1 = c1 & 0xFF;
        pal[2] = ((ulong)((r0 + r1) | ((g0 + g1) | (b0 + b1))) >> 1) | 0xFF000000UL;
        pal[3] = 0;
    }
    pal[0] |= 0xFF000000;
    pal[1] |= 0xFF000000;
    pal[2] |= 0xFF000000;
    pal[0] = dxtTo1555_2E78(pal[0]);
    pal[1] = dxtTo1555_2E78(pal[1]);
    pal[2] = dxtTo1555_2E78(pal[2]);
    pal[3] = dxtTo1555_2E78(pal[3]);
    unsigned int b;
    b = ((unsigned char*)dst)[4];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
    src += pitch;
    b = ((unsigned char*)dst)[5];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
    src += pitch;
    b = ((unsigned char*)dst)[6];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
    src += pitch;
    b = ((unsigned char*)dst)[7];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B3308);
#ifdef SKIP_ASM
// PORT: 64-bit `long` compares (ld); `long` is 8 bytes on this compiler.
extern "C" int func_003B3308(void* buf, int size, int type)
{
    if (type == 3) {
        unsigned long* p = (unsigned long*)buf;
        int n = size / 16;
        int i;
        for (i = 0; i < n; i++) {
            unsigned long v = *p++;
            if (v != 0xFFFFFFFF) {
                return 1;
            }
            if (*p != v) {
                return 1;
            }
            p += 3;
        }
    } else {
        unsigned short* q = (unsigned short*)buf;
        int n = size / 16;
        int i;
        for (i = 0; i < n; i++) {
            if (*q != 0xFFFF) {
                return 1;
            }
            q += 16;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2AEDC0", func_003B33B0);
#ifdef SKIP_ASM
extern "C" int func_003B3308(void* buf, int size, int type);
extern "C" void func_003B2E78(char* src, int pitch, char* dst);
extern "C" void func_003B2B90(char* src, int pitch, char* dst, int fmt);

// Compress a w x h image into 4x4 blocks.
extern "C" void func_003B33B0(void* out, char* src, int w, int h, int fmt)
{
    char* dst = (char*)out;
    int x, y;
    int n = w * h;
    if (fmt == 3 || fmt == 5) {
        if (func_003B3308(dst, n, fmt)) {
            for (y = 0; y < h; y += 4) {
                for (x = 0; x < w; x += 4) {
                    func_003B2E78(src, w * 8, dst + 8);
                    func_003B2B90(src, w * 8, dst, fmt);
                    src += 0x20;
                    dst += 0x10;
                }
                src += w * 0x18;
            }
        } else {
            for (y = 0; y < h; y += 4) {
                for (x = 0; x < w; x += 4) {
                    func_003B2E78(src, w * 8, dst + 8);
                    src += 0x20;
                    dst += 0x10;
                }
                src += w * 0x18;
            }
        }
    } else {
        for (y = 0; y < h; y += 4) {
            for (x = 0; x < w; x += 4) {
                func_003B2E78(src, w * 4, dst);
                src += 0x20;
                dst += 8;
            }
            src += w * 0x18;
        }
    }
}
#endif

