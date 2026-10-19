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

INCLUDE_ASM("be/bedbreward", func_0015AEC0);

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

INCLUDE_ASM("be/bedbreward", func_0015AFE8);

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

INCLUDE_ASM("be/bedbreward", func_0015BB20);

INCLUDE_ASM("be/bedbreward", func_0015BB48);

INCLUDE_ASM("be/bedbreward", func_0015BB58);

INCLUDE_ASM("be/bedbreward", func_0015BB68);

INCLUDE_ASM("be/bedbreward", func_0015BB78);

INCLUDE_ASM("be/bedbreward", func_0015BB88);

INCLUDE_ASM("be/bedbreward", func_0015BB98);

INCLUDE_ASM("be/bedbreward", func_0015BBA8);

INCLUDE_ASM("be/bedbreward", func_0015BBB8);

INCLUDE_ASM("be/bedbreward", func_0015BBC8);

INCLUDE_ASM("be/bedbreward", func_0015BBD8);

INCLUDE_ASM("be/bedbreward", func_0015BBF0);

INCLUDE_ASM("be/bedbreward", func_0015BBF8);

INCLUDE_ASM("be/bedbreward", func_0015BC00);

INCLUDE_ASM("be/bedbreward", func_0015BC08);

INCLUDE_ASM("be/bedbreward", func_0015BC10);

INCLUDE_ASM("be/bedbreward", func_0015BC30);

INCLUDE_ASM("be/bedbreward", func_0015BC60);

INCLUDE_ASM("be/bedbreward", func_0015BC70);

INCLUDE_ASM("be/bedbreward", func_0015BC88);

INCLUDE_ASM("be/bedbreward", func_0015BCB0);

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

INCLUDE_ASM("be/bedbreward", func_0015BCD0);

INCLUDE_ASM("be/bedbreward", func_0015BCF8);

INCLUDE_ASM("be/bedbreward", func_0015BD00);

INCLUDE_ASM("be/bedbreward", func_0015BD08);

INCLUDE_ASM("be/bedbreward", func_0015BD18);

INCLUDE_ASM("be/bedbreward", func_0015BD30);

INCLUDE_ASM("be/bedbreward", func_0015BD58);

INCLUDE_ASM("be/bedbreward", func_0015BE10);

INCLUDE_ASM("be/bedbreward", func_0015BEC0);

INCLUDE_ASM("be/bedbreward", func_0015BEE8);

INCLUDE_ASM("be/bedbreward", func_0015BF10);

INCLUDE_ASM("be/bedbreward", func_0015BF38);

INCLUDE_ASM("be/bedbreward", func_0015BF60);

INCLUDE_ASM("be/bedbreward", func_0015BF88);

INCLUDE_ASM("be/bedbreward", func_0015BF90);

INCLUDE_ASM("be/bedbreward", func_0015BFA8);

INCLUDE_ASM("be/bedbreward", func_0015BFD0);

INCLUDE_ASM("be/bedbreward", func_0015BFF8);

INCLUDE_ASM("be/bedbreward", func_0015C018);

INCLUDE_ASM("be/bedbreward", func_0015C040);

INCLUDE_ASM("be/bedbreward", func_0015C068);

INCLUDE_ASM("be/bedbreward", func_0015C090);

INCLUDE_ASM("be/bedbreward", func_0015C0B8);

INCLUDE_ASM("be/bedbreward", func_0015C0E0);

INCLUDE_ASM("be/bedbreward", func_0015C0F8);

INCLUDE_ASM("be/bedbreward", func_0015C110);

INCLUDE_ASM("be/bedbreward", func_0015C120);

INCLUDE_ASM("be/bedbreward", func_0015C130);

INCLUDE_ASM("be/bedbreward", func_0015C148);

INCLUDE_ASM("be/bedbreward", func_0015C158);

INCLUDE_ASM("be/bedbreward", func_0015C170);

INCLUDE_ASM("be/bedbreward", func_0015C188);

INCLUDE_ASM("be/bedbreward", func_0015C1B8);

INCLUDE_ASM("be/bedbreward", func_0015C1E0);

INCLUDE_ASM("be/bedbreward", func_0015C1F0);

INCLUDE_ASM("be/bedbreward", func_0015C200);

INCLUDE_ASM("be/bedbreward", func_0015C210);

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

INCLUDE_ASM("be/bedbreward", func_0015C250);

INCLUDE_ASM("be/bedbreward", func_0015C278);

INCLUDE_ASM("be/bedbreward", func_0015C288);

INCLUDE_ASM("be/bedbreward", func_0015C298);

INCLUDE_ASM("be/bedbreward", func_0015C2A8);

INCLUDE_ASM("be/bedbreward", func_0015C2B8);

INCLUDE_ASM("be/bedbreward", func_0015C2C8);

INCLUDE_ASM("be/bedbreward", func_0015C2D8);

INCLUDE_ASM("be/bedbreward", func_0015C2E8);

INCLUDE_ASM("be/bedbreward", func_0015C2F8);

INCLUDE_ASM("be/bedbreward", func_0015C308);

INCLUDE_ASM("be/bedbreward", func_0015C318);

INCLUDE_ASM("be/bedbreward", func_0015C328);

INCLUDE_ASM("be/bedbreward", func_0015C338);

INCLUDE_ASM("be/bedbreward", func_0015C358);

INCLUDE_ASM("be/bedbreward", func_0015C368);

INCLUDE_ASM("be/bedbreward", func_0015C388);

INCLUDE_ASM("be/bedbreward", func_0015C398);

INCLUDE_ASM("be/bedbreward", func_0015C3B8);

INCLUDE_ASM("be/bedbreward", func_0015C3C8);

INCLUDE_ASM("be/bedbreward", func_0015C3D8);

INCLUDE_ASM("be/bedbreward", func_0015C3E8);

INCLUDE_ASM("be/bedbreward", func_0015C3F8);

INCLUDE_ASM("be/bedbreward", func_0015C408);

INCLUDE_ASM("be/bedbreward", func_0015C418);

INCLUDE_ASM("be/bedbreward", func_0015C4D0);

INCLUDE_ASM("be/bedbreward", func_0015C4E0);

INCLUDE_ASM("be/bedbreward", func_0015C598);

INCLUDE_ASM("be/bedbreward", func_0015C5A8);

INCLUDE_ASM("be/bedbreward", func_0015C5B8);

INCLUDE_ASM("be/bedbreward", func_0015C5C8);

INCLUDE_ASM("be/bedbreward", func_0015C600);

INCLUDE_ASM("be/bedbreward", func_0015C610);

INCLUDE_ASM("be/bedbreward", func_0015C618);

INCLUDE_ASM("be/bedbreward", func_0015C660);

INCLUDE_ASM("be/bedbreward", func_0015C678);

INCLUDE_ASM("be/bedbreward", func_0015C6A0);

INCLUDE_ASM("be/bedbreward", func_0015C6B0);

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

INCLUDE_ASM("be/bedbreward", func_0015C6E8);

INCLUDE_ASM("be/bedbreward", func_0015C710);

INCLUDE_ASM("be/bedbreward", func_0015C720);

INCLUDE_ASM("be/bedbreward", func_0015C738);

INCLUDE_ASM("be/bedbreward", func_0015C760);

INCLUDE_ASM("be/bedbreward", func_0015C788);

INCLUDE_ASM("be/bedbreward", func_0015C7B0);

INCLUDE_ASM("be/bedbreward", func_0015C7C0);

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

INCLUDE_ASM("be/bedbreward", func_0015C7E0);

INCLUDE_ASM("be/bedbreward", func_0015C808);

INCLUDE_ASM("be/bedbreward", func_0015C818);

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

INCLUDE_ASM("be/bedbreward", func_0015C858);

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

INCLUDE_ASM("be/bedbreward", func_0015C898);

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

INCLUDE_ASM("be/bedbreward", func_0015C8D8);

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

