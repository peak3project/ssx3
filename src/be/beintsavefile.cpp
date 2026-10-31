#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A7E0[];
extern void* D_0045AD08[16];
extern void* D_004A121C;
extern int D_004A1228;

struct cBESaveInterface {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

//100%
INCLUDE_ASM("be/beintsavefile", cBESaveInterface_getThis__Fv);
#ifdef SKIP_ASM
void* cBESaveInterface_getThis()
{
    if (D_004A121C == 0) {
        cBESaveInterface* mem = (cBESaveInterface*)cMemMan_alloc(0x10, D_0045A7E0, 0, 0);
        mem->field_0x8 = 0;
        mem->vtable = D_0045AD08;
        D_004A121C = mem;
        D_004A1228 = 0;
    }
    return D_004A121C;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00152688);
#ifdef SKIP_ASM
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern const char D_0045A7F0[];
extern char* D_004A1224;

extern "C" char* func_00152688(void* iface)
{
    D_004A1228 = 1;
    if (D_004A1224 == 0)
        D_004A1224 = (char*)operator_new__FUi(0x80000, D_0045A7F0, 0x100, 0);
    return D_004A1224;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_001526D0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
extern "C" int func_0014E048(void* be);
extern char* D_004A1224;

extern "C" char* func_001526D0(void)
{
    return D_004A1224 + func_0014E048(cBE_getBE());
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00152700);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern void* D_004A1220;

extern "C" void func_00152700(void* self)
{
    if (D_004A1220)
        cMemMan_free(D_004A1220);
    D_004A1220 = 0;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00152728);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern char* D_004A1224;

extern "C" void func_00152728(void)
{
    if (D_004A1224)
        cMemMan_free(D_004A1224);
    D_004A1224 = 0;
    D_004A1228 = 0;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00152758);
#ifdef SKIP_ASM
int func_00152948(void* self);
// PORT: the unit defines func_00152700(void); this caller passes self in $a0.
void func_00152700(void* self);
extern "C" void* func_0041605C(void* dst, const void* src, int n);
extern "C" int func_003E62D0(void* buf, int n, int seed);
extern void* D_004A1220;
struct sSaveHdr_2758 { int w[0x288 / 4]; };
extern sSaveHdr_2758 D_00535898;
extern char D_00535C18[];
struct sCharTbl_2758 { char pad[0x10]; unsigned b0 : 1; unsigned b1 : 1; unsigned b2 : 22; unsigned char f13; char pad14[8]; };
extern sCharTbl_2758 D_00535B20[];
struct sSaveBits_2758 { unsigned a : 1; unsigned b : 8; unsigned rest : 23; };
struct sSaveBits6_2758 { sSaveBits_2758 e[6]; };

extern "C" void* func_00152758(void* self)
{
    int size = func_00152948(self);
    func_00152700(self);
    D_004A1220 = operator_new__FUi(size, D_0045A7F0, 0x100, 0);
    char* p = (char*)D_004A1220;
    *(sSaveHdr_2758*)p = D_00535898;
    p += sizeof(sSaveHdr_2758);
    func_0041605C(p, D_00535C18, 0xA28);
    p += 0xA28;
    sSaveBits6_2758 bits;
    for (int i = 0; i < 6; i++) {
        bits.e[i].a = D_00535B20[i].b1;
        bits.e[i].b = D_00535B20[i].f13;
    }
    *(sSaveBits6_2758*)p = bits;
    p += sizeof(sSaveBits6_2758);
    int crc = func_003E62D0(D_004A1220, size - 4, 0xFBEA);
    __builtin_memcpy(p, &crc, 4);
    return D_004A1220;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00152948__FPv);
#ifdef SKIP_ASM
int func_00152948(void* self)
{
    return 0xCCC;
}
#endif

INCLUDE_ASM("be/beintsavefile", func_00152950);

//100%
INCLUDE_ASM("be/beintsavefile", func_00152BA8);
#ifdef SKIP_ASM
extern "C" int func_00152BA8()
{
    return 0x9B61;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00152BB0);
#ifdef SKIP_ASM
class cBEIface_2BB0 {
public:
    char pad[0xC];
    virtual void v1();
    virtual void onLoad();
};
cBEIface_2BB0* cBEOptionInterface_getThis();
cBEIface_2BB0* cBEScoreInterface_getThis();
cBEIface_2BB0* cBENewPlayerInterface_getThis();
extern "C" void cSSXApp_initLocale(void* app);
extern "C" void func_00228C08(void* app);
extern void* D_004A28A8;

// Restores the save block written by func_00152758 after checking its CRC; returns 0 when the CRC is wrong.
extern "C" int func_00152BB0(void* self, char* buf)
{
    int size = func_00152948(self) - 4;
    int crc = func_003E62D0(buf, size, 0xFBEA);
    int stored = 0;
    __builtin_memcpy(&stored, buf + size, 4);
    if (crc != stored) {
        return 0;
    }
    char* p = buf;
    cBEIface_2BB0* o;
    D_00535898 = *(sSaveHdr_2758*)p;
    o = cBEOptionInterface_getThis();
    p += sizeof(sSaveHdr_2758);
    o->onLoad();
    func_0041605C(D_00535C18, p, 0xA28);
    p += 0xA28;
    o = cBEScoreInterface_getThis();
    o->onLoad();
    sSaveBits6_2758 bits = *(sSaveBits6_2758*)p;
    for (int i = 0; i < 6; i++) {
        D_00535B20[i].b1 = bits.e[i].a;
        D_00535B20[i].f13 = bits.e[i].b;
    }
    o = cBENewPlayerInterface_getThis();
    o->onLoad();
    cSSXApp_initLocale(D_004A28A8);
    func_00228C08(D_004A28A8);
    return 1;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00152DE0);
#ifdef SKIP_ASM
cBEIface_2BB0* func_00147F78_2DE0() __asm__("func_00147F78");
cBEIface_2BB0* cBEBAGTInterface_getThis_2DE0() __asm__("cBEBAGTInterface_getThis__Fv");
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);
extern "C" void func_001515B8(void* p);
struct sProfSub_2DE0 { char pad[0x288]; int keep; char pad28C[0xF88 - 0x28C]; };
struct sProfile_2DE0 { sProfSub_2DE0 sub[10]; };
extern sProfile_2DE0 D_004A6CA8_2DE0[] __asm__("D_004A6CA8");
struct sCharFlag_2DE0 { unsigned char f; char pad[0x1B]; };
extern sCharFlag_2DE0 D_00535B31[];

// Loads rider profile 'idx' from a save block after checking its CRC; the per-sub-profile 'keep' values survive the load.
extern "C" int func_00152DE0(void* self, char* buf, int idx)
{
    int size = func_00152BA8() - 4;
    int crc = func_003E62D0(buf, size, 0xFBEA);
    int stored = 0;
    __builtin_memcpy(&stored, buf + size, 4);
    if (crc != stored) {
        return 0;
    }
    int keep[10];
    for (int i = 0; i < 10; i++) {
        keep[i] = D_004A6CA8_2DE0[idx].sub[i].keep;
    }
    char* p = buf;
    strncpy((char*)&D_00535B20[idx], p, 0xC);
    p += 0xC;
    D_004A6CA8_2DE0[idx] = *(sProfile_2DE0*)p;
    p += sizeof(sProfile_2DE0);
    D_00535B31[idx].f = *p;
    cBENewPlayerInterface_getThis()->onLoad();
    func_00147F78_2DE0()->onLoad();
    cBEBAGTInterface_getThis_2DE0()->onLoad();
    for (int i = 0; i < 10; i++) {
        D_004A6CA8_2DE0[idx].sub[i].keep = keep[i];
        func_001515B8(&D_004A6CA8_2DE0[idx].sub[i]);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("be/beintsavefile", func_00153050);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
void cMemMan_free(void*);
extern void* D_004A1220;

extern "C" void func_00153050(void)
{
    operator_delete((int*)D_004A121C);
    D_004A121C = 0;
    if (D_004A1220)
        cMemMan_free(D_004A1220);
    D_004A1220 = 0;
}
#endif

