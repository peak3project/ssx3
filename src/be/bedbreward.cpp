#include "common.h"

INCLUDE_ASM("be/bedbreward", cBERewardDB_init);

//100%
INCLUDE_ASM("be/bedbreward", func_0015AE00);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void func_0019DC20(void* self, int bank, int i);
extern "C" void func_0019D4B8(void* self, int bank, int i);
void cMemMan_free(void* p);

struct sBEDB_0015AE00
{
    int handle;
    void* data;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
};

extern "C" void func_0015AE00(sBEDB_0015AE00* self)
{
    if (self->handle >= 0)
    {
        char* snd = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
        func_0019DC20(snd, 0, self->handle);
        func_0019D4B8(snd, 0, self->handle);
    }
    if (self->data != 0)
    {
        cMemMan_free(self->data);
    }
    self->handle = -1;
    self->data = 0;
    self->f8 = 0;
    self->fC = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f1C = 0;
    self->f20 = 0;
    self->f24 = 0;
    self->f2C = 0;
    self->f30 = 0;
    self->f34 = 0;
    self->f38 = 0;
    self->f3C = 0;
    self->f40 = 0;
    self->f44 = 0;
    self->f48 = 0;
    self->f4C = 0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015AF40);
#ifdef SKIP_ASM
struct sRec12_AF40 { int id; int f4; int f8; };
struct sRec8_AF40 { int id; int f4; };
struct sRec16_AF40 { int id; int f4; int f8; int fC; };

struct sRewardDB_AF40 {
    int f0;
    int f4;
    sRec12_AF40* t0;    // 0x8
    sRec12_AF40* t1;    // 0xC
    sRec8_AF40* t2;     // 0x10
    sRec16_AF40* t3;    // 0x14
    sRec16_AF40* t4;    // 0x18
    sRec16_AF40* t5;    // 0x1C
    sRec16_AF40* t7;    // 0x20
    sRec16_AF40* t6;    // 0x24
    sRec16_AF40* t8;    // 0x28
};

// Returns the id of entry idx in the reward table of the given type.
extern "C" int func_0015AF40(sRewardDB_AF40* self, int type, int idx)
{
    switch (type) {
    case 0: { int off = idx * 12; return *(int*)((char*)self->t0 + off); }
    case 1: { int off = idx * 12; return *(int*)((char*)self->t1 + off); }
    case 2: { int off = idx * 8; return *(int*)((char*)self->t2 + off); }
    case 3: { int off = idx * 16; return *(int*)((char*)self->t3 + off); }
    case 4: { int off = idx * 16; return *(int*)((char*)self->t4 + off); }
    case 5: { int off = idx * 16; return *(int*)((char*)self->t5 + off); }
    case 6: { int off = idx * 16; return *(int*)((char*)self->t6 + off); }
    case 7: { int off = idx * 16; return *(int*)((char*)self->t7 + off); }
    case 8: { int off = idx * 16; return *(int*)((char*)self->t8 + off); }
    case 9: break;
    }
    return 0;
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015B028);

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB00__FPv);
#ifdef SKIP_ASM
void func_0015BB00(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB08__FPv);
#ifdef SKIP_ASM
void func_0015BB08(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB10__FPv);
#ifdef SKIP_ASM
void func_0015BB10(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB18__FPv);
#ifdef SKIP_ASM
void func_0015BB18(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BCC0__FPv);
#ifdef SKIP_ASM
void func_0015BCC0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BCC8__FPv);
#ifdef SKIP_ASM
void func_0015BCC8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C228);
#ifdef SKIP_ASM
// func_003E6448 looks like memset(dst, value, size).
extern "C" void* func_003E6448(void* dst, int value, int size);
extern char D_005308B8[];

extern "C" void func_0015C228()
{
    func_003E6448(D_005308B8, 0, 0x20);
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C6C8__FPv);
#ifdef SKIP_ASM
void func_0015C6C8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C6D0__FPv);
#ifdef SKIP_ASM
void func_0015C6D0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C6D8__FPv);
#ifdef SKIP_ASM
void func_0015C6D8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C6E0__FPv);
#ifdef SKIP_ASM
void func_0015C6E0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C7D0__FPv);
#ifdef SKIP_ASM
void func_0015C7D0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C7D8__FPv);
#ifdef SKIP_ASM
void func_0015C7D8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C830);
#ifdef SKIP_ASM
extern int* D_004A1258;
void operator_delete(int* ptr);

extern "C" void func_0015C830(void)
{
    operator_delete(D_004A1258);
    D_004A1258 = 0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C870);
#ifdef SKIP_ASM
extern int* D_004A122C;
void operator_delete(int* ptr);

extern "C" void func_0015C870(void)
{
    operator_delete(D_004A122C);
    D_004A122C = 0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C8B0);
#ifdef SKIP_ASM
extern int* D_004A1254;
void operator_delete(int* ptr);

extern "C" void func_0015C8B0(void)
{
    operator_delete(D_004A1254);
    D_004A1254 = 0;
}
#endif

extern "C" void* func_0015B028(int, int);

//99.38%
INCLUDE_ASM("be/bedbreward", func_0015C8F0__FPv);
#ifdef SKIP_ASM
void* func_0015C8F0(void* self)
{
    return func_0015B028(1, 0xffff);
}
#endif

extern "C" void* func_0015B028(int, int);

//99.38%
INCLUDE_ASM("be/bedbreward", func_0015C910__FPv);
#ifdef SKIP_ASM
void* func_0015C910(void* self)
{
    return func_0015B028(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C930__FPv);
#ifdef SKIP_ASM
void* func_0015C930(void* self)
{
    int t0 = 0;
    *(int*)self = t0;
    *(int*)((char*)self + 0x4) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C940);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_0015CB08(void* self);

extern "C" void func_0015C940(int* self, int flags)
{
    func_0015CB08(self);
    if (flags & 1)
    {
        operator_delete(self);
    }
}
#endif

