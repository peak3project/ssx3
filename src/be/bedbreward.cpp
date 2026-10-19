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
INCLUDE_ASM("be/bedbreward", func_0015AEC0);
#ifdef SKIP_ASM
extern "C" int func_0019E238(void* self, int bank, int i);
extern "C" int func_0019E330(void* self, int bank, int i);
extern "C" void func_0015A818(int* self, int v);

extern "C" void func_0015AEC0(int* self)
{
    if (*self >= 0) {
        char* snd = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
        if (func_0019E238(snd, 0, *self) != 0) {
            func_0015A818(self, func_0019E330(snd, 0, *self));
            func_0019DC20(snd, 0, *self);
            *self = -1;
        }
    }
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

//100%
INCLUDE_ASM("be/bedbreward", func_0015AFE8);
#ifdef SKIP_ASM
extern "C" void* func_0015AFE8(void* self, ...)
{
    return self;
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
INCLUDE_ASM("be/bedbreward", func_0015BB20);
#ifdef SKIP_ASM
extern void* D_004A11B4;
void operator_delete(int* ptr);

extern "C" void func_0015BB20(void)
{
    operator_delete((int*)D_004A11B4);
    D_004A11B4 = 0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB48);
#ifdef SKIP_ASM
extern int D_00535BF8[];

extern "C" int func_0015BB48(void)
{
    return D_00535BF8[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB58);
#ifdef SKIP_ASM
extern int D_00535BFC[];

extern "C" int func_0015BB58(void)
{
    return D_00535BFC[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB68);
#ifdef SKIP_ASM
extern int D_00535C04[];

extern "C" int func_0015BB68(void)
{
    return D_00535C04[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB78);
#ifdef SKIP_ASM
extern int D_00535C00[];

extern "C" int func_0015BB78(void)
{
    return D_00535C00[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB88);
#ifdef SKIP_ASM
extern int D_00535C0C[];

extern "C" void func_0015BB88(void* self, int v)
{
    D_00535C0C[0] = v;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BB98);
#ifdef SKIP_ASM
extern int D_00535C0C[];

extern "C" int func_0015BB98(void)
{
    return D_00535C0C[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BBA8);
#ifdef SKIP_ASM
extern signed char D_00535C10[];

extern "C" signed char func_0015BBA8(void)
{
    return D_00535C10[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BBB8);
#ifdef SKIP_ASM
extern signed char D_00535C12[];

extern "C" signed char func_0015BBB8(void)
{
    return D_00535C12[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BBC8);
#ifdef SKIP_ASM
extern signed char D_00535C11[];

extern "C" signed char func_0015BBC8(void)
{
    return D_00535C11[0];
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015BBD8);

//100%
INCLUDE_ASM("be/bedbreward", func_0015BBF0);
#ifdef SKIP_ASM
extern int D_004A11BC;

extern "C" void func_0015BBF0(void* self, int v)
{
    D_004A11BC = v;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BBF8);
#ifdef SKIP_ASM
extern int D_004A11BC;

extern "C" int func_0015BBF8(void) {
    return D_004A11BC;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BC00);
#ifdef SKIP_ASM
extern int D_004A11B8;

extern "C" int func_0015BC00(void) {
    return D_004A11B8;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BC08);
#ifdef SKIP_ASM
extern int D_004A11B8;

extern "C" void func_0015BC08(void) {
    D_004A11B8 = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BC10);
#ifdef SKIP_ASM
extern "C" void cBXString_cBXString4(int *);
extern int D_004A4CB8;

extern "C" void func_0015BC10(void) {
    cBXString_cBXString4(&D_004A4CB8);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BC30);
#ifdef SKIP_ASM
extern "C" void cBXString_cBXString1(void*, int*);

extern "C" void* func_0015BC30(void* self)
{
    cBXString_cBXString1(self, &D_004A4CB8);
    return self;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BC60);
#ifdef SKIP_ASM
extern void *D_004A11B4;

extern "C" void func_0015BC60(int arg0) {
    (*(int *)((char*)(D_004A11B4) + (8))) = arg0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BC70);
#ifdef SKIP_ASM
extern char D_0045AE58[];

extern "C" void* func_0015BC70(void* self)
{
    *(void**)((char*)self + 0xC) = D_0045AE58;
    return self;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BC88);
#ifdef SKIP_ASM
extern void* D_004A11C0;
void operator_delete(int* ptr);

extern "C" void func_0015BC88(void)
{
    operator_delete((int*)D_004A11C0);
    D_004A11C0 = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BCB0);
#ifdef SKIP_ASM
extern void *D_004A11C0;

extern "C" void func_0015BCB0(int arg0) {
    (*(int *)((char*)(D_004A11C0) + (8))) = arg0;
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
INCLUDE_ASM("be/bedbreward", func_0015BCD0);
#ifdef SKIP_ASM
extern void* D_004A1238;
void operator_delete(int* ptr);

extern "C" void func_0015BCD0(void)
{
    operator_delete((int*)D_004A1238);
    D_004A1238 = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BCF8);
#ifdef SKIP_ASM
extern "C" int func_0015BCF8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BD00);
#ifdef SKIP_ASM
extern "C" void func_0015BD00(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BD08);
#ifdef SKIP_ASM
extern void *D_004A1238;

extern "C" void func_0015BD08(int arg0) {
    (*(int *)((char*)(D_004A1238) + (8))) = arg0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BD18);
#ifdef SKIP_ASM
extern char D_0045ADF8[];

extern "C" void* func_0015BD18(void* self)
{
    *(void**)((char*)self + 0xC) = D_0045ADF8;
    return self;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BD30);
#ifdef SKIP_ASM
extern void* D_004A120C;
void operator_delete(int* ptr);

extern "C" void func_0015BD30(void)
{
    operator_delete((int*)D_004A120C);
    D_004A120C = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BD58);
#ifdef SKIP_ASM
struct sBEOpt_BE10 { int v[0xA2]; };
extern sBEOpt_BE10 D_00535610;

extern "C" sBEOpt_BE10* func_0015BD58(sBEOpt_BE10* dst)
{
    *dst = D_00535610;
    return dst;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BE10);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BE10(void* self, sBEOpt_BE10* src)
{
    D_00535610 = *src;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BEC0);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BEC0(void* self, int arg1)
{
    int b = arg1 != 0;
    D_00535610.v[0] = (D_00535610.v[0] & ~0x80000) | (b << 19);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BEE8);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BEE8(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0x300000) | ((arg1 & 3) << 20);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BF10);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BF10(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0x1C00000) | ((arg1 & 7) << 22);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BF38);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BF38(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0x1E000000) | ((arg1 & 0xF) << 25);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BF60);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BF60(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0x20000000) | ((arg1 & 1) << 29);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BF88);
#ifdef SKIP_ASM
extern "C" int func_0015BF88(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015BF90);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" int func_0015BF90(void)
{
    return ((unsigned int)D_00535610.v[0] >> 22) & 7;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BFA8);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BFA8(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0x3000) | ((arg1 & 3) << 12);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BFD0);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BFD0(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0xC000) | ((arg1 & 3) << 14);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015BFF8);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015BFF8(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0xF) | (arg1 & 0xF);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C018);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015C018(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0xF0) | ((arg1 & 0xF) << 4);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C040);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015C040(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & ~0xF00) | ((arg1 & 0xF) << 8);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C068);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015C068(void* self, int arg1)
{
    int b = arg1 != 0;
    D_00535610.v[0] = (D_00535610.v[0] & ~0x10000) | (b << 16);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C090);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015C090(void* self, int arg1)
{
    int b = arg1 != 0;
    D_00535610.v[0] = (D_00535610.v[0] & ~0x20000) | (b << 17);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C0B8);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015C0B8(void* self, int arg1)
{
    int b = arg1 != 0;
    D_00535610.v[0] = (D_00535610.v[0] & ~0x40000) | (b << 18);
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C0E0);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" int func_0015C0E0(void)
{
    return ((unsigned int)D_00535610.v[0] >> 12) & 3;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C0F8);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" int func_0015C0F8(void)
{
    return ((unsigned int)D_00535610.v[0] >> 14) & 3;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C110);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" int func_0015C110(void)
{
    return D_00535610.v[0] & 0xF;
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C120);

//100%
INCLUDE_ASM("be/bedbreward", func_0015C130);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" int func_0015C130(void)
{
    return ((unsigned int)D_00535610.v[0] >> 8) & 0xF;
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C148);

//100%
INCLUDE_ASM("be/bedbreward", func_0015C158);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" int func_0015C158(void)
{
    return (D_00535610.v[0] >> 17) & 1;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C170);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" int func_0015C170(void)
{
    return (D_00535610.v[0] >> 18) & 1;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C188);
#ifdef SKIP_ASM
extern "C" char* strcpy(char*, const char*);
extern char D_00535617[];

extern "C" void func_0015C188(void* self, int idx, const char* name)
{
    strcpy(D_00535617 + (idx << 6), name);
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C1B8);
#ifdef SKIP_ASM
extern sBEOpt_BE10 D_00535610;

extern "C" void func_0015C1B8(void* self, int arg1)
{
    D_00535610.v[0] = (D_00535610.v[0] & 0x3FFFFFFF) | (arg1 << 30);
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C1E0);

INCLUDE_ASM("be/bedbreward", func_0015C1F0);
//100%
INCLUDE_ASM("be/bedbreward", func_0015C200);
#ifdef SKIP_ASM
extern void *D_004A120C;

extern "C" void func_0015C200(int arg0) {
    (*(int *)((char*)(D_004A120C) + (8))) = arg0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C210);
#ifdef SKIP_ASM
extern char D_0045ADC8[];

extern "C" void* func_0015C210(void* self)
{
    *(void**)((char*)self + 0xC) = D_0045ADC8;
    return self;
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
INCLUDE_ASM("be/bedbreward", func_0015C250);
#ifdef SKIP_ASM
extern void* D_004A1204;
void operator_delete(int* ptr);

extern "C" void func_0015C250(void)
{
    operator_delete((int*)D_004A1204);
    D_004A1204 = 0;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C278);
#ifdef SKIP_ASM
extern int D_00534B30[];

extern "C" void func_0015C278(void* self, int v)
{
    D_00534B30[0] = v;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C288);
#ifdef SKIP_ASM
extern int D_00534B30[];

extern "C" int func_0015C288(void)
{
    return D_00534B30[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C298);
#ifdef SKIP_ASM
extern int D_00534B34[];

extern "C" void func_0015C298(void* self, int v)
{
    D_00534B34[0] = v;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C2A8);
#ifdef SKIP_ASM
extern int D_00534B34[];

extern "C" int func_0015C2A8(void)
{
    return D_00534B34[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C2B8);
#ifdef SKIP_ASM
extern int D_00534B38[];

extern "C" void func_0015C2B8(void* self, int v)
{
    D_00534B38[0] = v;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C2C8);
#ifdef SKIP_ASM
extern int D_00534B38[];

extern "C" int func_0015C2C8(void)
{
    return D_00534B38[0];
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C2D8);
#ifdef SKIP_ASM
extern int D_00534B3C[];

extern "C" void func_0015C2D8(void* self, int v)
{
    D_00534B3C[0] = v;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C2E8);
#ifdef SKIP_ASM
extern int D_00534B3C[];

extern "C" int func_0015C2E8(void)
{
    return D_00534B3C[0];
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C2F8);

//100%
INCLUDE_ASM("be/bedbreward", func_0015C308);
#ifdef SKIP_ASM
extern float D_00534B40[];

extern "C" float func_0015C308(void)
{
    return D_00534B40[0];
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C318);

//100%
INCLUDE_ASM("be/bedbreward", func_0015C328);
#ifdef SKIP_ASM
extern int D_00534D44[];

extern "C" int func_0015C328(void)
{
    return D_00534D44[0];
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C338);
#ifdef SKIP_ASM
extern "C" char* strcpy(char*, const char*);
extern char D_00534D48[];

// Copies the caller's name string (a1) into a static buffer; the receiver (a0) is unused.
extern "C" void func_0015C338(void* self, const char* name)
{
    strcpy(D_00534D48, name);
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C358);
#ifdef SKIP_ASM
extern char D_00534D48[];

extern "C" char* func_0015C358(void)
{
    return D_00534D48;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C368);
#ifdef SKIP_ASM
extern "C" char* strcpy(char*, const char*);
extern char D_00534DC0[];

// Copies the caller's name string (a1) into a static buffer; the receiver (a0) is unused.
extern "C" void func_0015C368(void* self, const char* name)
{
    strcpy(D_00534DC0, name);
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C388);
#ifdef SKIP_ASM
extern char D_00534DC0[];

extern "C" char* func_0015C388(void)
{
    return D_00534DC0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C398);
#ifdef SKIP_ASM
extern "C" char* strcpy(char*, const char*);
extern char D_00534E38[];

// Copies the caller's name string (a1) into a static buffer; the receiver (a0) is unused.
extern "C" void func_0015C398(void* self, const char* name)
{
    strcpy(D_00534E38, name);
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C3B8);
#ifdef SKIP_ASM
extern char D_00534E38[];

extern "C" char* func_0015C3B8(void)
{
    return D_00534E38;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C3C8);
#ifdef SKIP_ASM
extern void *D_004A1204;

extern "C" void func_0015C3C8(int arg0) {
    (*(int *)((char*)(D_004A1204) + (8))) = arg0;
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C3D8);

//100%
INCLUDE_ASM("be/bedbreward", func_0015C3E8);
#ifdef SKIP_ASM
extern int D_00534E58[];

extern "C" int func_0015C3E8(void)
{
    return D_00534E58[0];
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C3F8);

//100%
INCLUDE_ASM("be/bedbreward", func_0015C408);
#ifdef SKIP_ASM
extern int D_00534E5C[];

extern "C" int func_0015C408(void)
{
    return D_00534E5C[0];
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C418);
#ifdef SKIP_ASM
struct sBEBlk_C418 { int v[0x2B]; };
extern sBEBlk_C418 D_00534E60;

extern "C" void func_0015C418(void* self, sBEBlk_C418* src)
{
    D_00534E60 = *src;
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C4D0);
//100%
INCLUDE_ASM("be/bedbreward", func_0015C4E0);
#ifdef SKIP_ASM
extern sBEBlk_C418 D_00534F0C;

extern "C" void func_0015C4E0(void* self, sBEBlk_C418* src)
{
    D_00534F0C = *src;
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C598);

//100%
INCLUDE_ASM("be/bedbreward", func_0015C5A8);
#ifdef SKIP_ASM
extern char D_00534FC8[];

extern "C" char* func_0015C5A8(void)
{
    return D_00534FC8;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C5B8);
#ifdef SKIP_ASM
extern char D_00534FB8[];

extern "C" char* func_0015C5B8(void)
{
    return D_00534FB8;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C5C8);
#ifdef SKIP_ASM
struct sBEBlk7_C5C8 { char c[7]; };
extern unsigned char D_00534FD8[];

extern "C" void func_0015C5C8(void* self, sBEBlk7_C5C8* src)
{
    *(sBEBlk7_C5C8*)D_00534FD8 = *src;
}
#endif

INCLUDE_ASM("be/bedbreward", func_0015C600);
//100%
INCLUDE_ASM("be/bedbreward", func_0015C610);
#ifdef SKIP_ASM
extern "C" int func_0015C610(void) {
    return 8;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C618);
#ifdef SKIP_ASM
extern unsigned char D_00534FD8[];

extern "C" int func_0015C618(void)
{
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += D_00534FD8[i];
    }
    return sum / 35;
}
#endif

//100%
INCLUDE_ASM("be/bedbreward", func_0015C660);
#ifdef SKIP_ASM
extern char D_0045AD98[];

extern "C" void* func_0015C660(void* self)
{
    *(void**)((char*)self + 0xC) = D_0045AD98;
    return self;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C678);
#ifdef SKIP_ASM
extern void* D_004A11C4;
void operator_delete(int* ptr);

extern "C" void func_0015C678(void)
{
    operator_delete((int*)D_004A11C4);
    D_004A11C4 = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C6A0);
#ifdef SKIP_ASM
extern void *D_004A11C4;

extern "C" void func_0015C6A0(int arg0) {
    (*(int *)((char*)(D_004A11C4) + (8))) = arg0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C6B0);
#ifdef SKIP_ASM
extern char D_0045AD68[];

extern "C" void* func_0015C6B0(void* self)
{
    *(char**)((char*)self + 0xC) = D_0045AD68;
    return self;
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
INCLUDE_ASM("be/bedbreward", func_0015C6E8);
#ifdef SKIP_ASM
extern void* D_004A1210;
void operator_delete(int* ptr);

extern "C" void func_0015C6E8(void)
{
    operator_delete((int*)D_004A1210);
    D_004A1210 = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C710);
#ifdef SKIP_ASM
extern void *D_004A1210;

extern "C" void func_0015C710(int arg0) {
    (*(int *)((char*)(D_004A1210) + (8))) = arg0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C720);
#ifdef SKIP_ASM
extern char D_0045ACD8[];

extern "C" void* func_0015C720(void* self)
{
    *(char**)((char*)self + 0xC) = D_0045ACD8;
    return self;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C738);
#ifdef SKIP_ASM
extern void* D_004A1248;
void operator_delete(int* ptr);

extern "C" void func_0015C738(void)
{
    operator_delete((int*)D_004A1248);
    D_004A1248 = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C760);
#ifdef SKIP_ASM
extern "C" int func_0015C760(void *arg0) {
    int var_3;

    var_3 = 0;
    if (((*(int *)((char*)(arg0) + (0x10))) != 0) || ((*(int *)((char*)(arg0) + (0x14))) != 0)) {
        var_3 = 1;
    }
    return var_3;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C788);
#ifdef SKIP_ASM
extern "C" int func_0015C788(void *arg0) {
    int var_3;

    var_3 = 0;
    if (((*(int *)((char*)(arg0) + (0x18))) >= 0) || ((*(int *)((char*)(arg0) + (0x1C))) >= 0)) {
        var_3 = 1;
    }
    return var_3;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C7B0);
#ifdef SKIP_ASM
extern "C" int func_0015C7B0(int arg0, int arg1) {
    return (*(int *)(((char*)(arg0) + (arg1 << 2)) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C7C0);
#ifdef SKIP_ASM
extern void *D_004A1248;

extern "C" void func_0015C7C0(int arg0) {
    (*(int *)((char*)(D_004A1248) + (8))) = arg0;
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
INCLUDE_ASM("be/bedbreward", func_0015C7E0);
#ifdef SKIP_ASM
extern void* D_004A124C;
void operator_delete(int* ptr);

extern "C" void func_0015C7E0(void)
{
    operator_delete((int*)D_004A124C);
    D_004A124C = 0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C808);
#ifdef SKIP_ASM
extern void *D_004A124C;

extern "C" void func_0015C808(int arg0) {
    (*(int *)((char*)(D_004A124C) + (8))) = arg0;
}
#endif
//100%
INCLUDE_ASM("be/bedbreward", func_0015C818);
#ifdef SKIP_ASM
extern char D_0045AC48[];

extern "C" void* func_0015C818(void* self)
{
    *(char**)((char*)self + 0xC) = D_0045AC48;
    return self;
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
INCLUDE_ASM("be/bedbreward", func_0015C858);
#ifdef SKIP_ASM
extern char D_0045AC18[];

extern "C" void* func_0015C858(void* self)
{
    *(char**)((char*)self + 4) = D_0045AC18;
    return self;
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
INCLUDE_ASM("be/bedbreward", func_0015C898);
#ifdef SKIP_ASM
extern char D_0045ABE8[];

extern "C" void* func_0015C898(void* self)
{
    *(char**)((char*)self + 4) = D_0045ABE8;
    return self;
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

//100%
INCLUDE_ASM("be/bedbreward", func_0015C8D8);
#ifdef SKIP_ASM
extern char D_0045ABB8[];

extern "C" void* func_0015C8D8(void* self)
{
    *(char**)((char*)self + 4) = D_0045ABB8;
    return self;
}
#endif

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

