#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A648[];
extern void* D_0045AD98[16];
extern void* D_004A1204;

struct cBENetworkInterface {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

//100%
INCLUDE_ASM("be/beintnetwork", cBENetworkInterface_getThis__Fv);
#ifdef SKIP_ASM
void* cBENetworkInterface_getThis()
{
    if (D_004A1204 == 0) {
        cBENetworkInterface* mem = (cBENetworkInterface*)cMemMan_alloc(0x10, D_0045A648, 0, 0);
        mem->field_0x8 = 0;
        mem->vtable = D_0045AD98;
        D_004A1204 = mem;
    }
    return D_004A1204;
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014E130);
#ifdef SKIP_ASM
struct sNetState_0014E130
{
    int data[0x4B0 / 4];
};

extern sNetState_0014E130 D_00534B30;
extern sNetState_0014E130 D_00535088;

extern "C" void func_0014E130(void)
{
    D_00535088 = D_00534B30;
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014E1F8);
#ifdef SKIP_ASM
extern sNetState_0014E130 D_00534B30;
extern sNetState_0014E130 D_00535088;

extern "C" void func_0014E1F8(void)
{
    D_00534B30 = D_00535088;
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014E2C0__FPv);
#ifdef SKIP_ASM
int func_0014E2C0(void* self)
{
    return 0xC44;
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014E2C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sNetHdr_E2C8 {
    int w[0x4C / 4];
};

struct sNetPair_E2C8 {
    int w[2];
};

struct sNetTrip_E2C8 {
    int w[3];
};

struct sNetHW_E2C8 {
    short h[2];
};

struct sNetDW_E2C8 {
    int w[2];
};

struct sNetTag_E2C8 {
    char c[7];
};

struct sNetKey_E2C8 {
    short h[3];
};

struct sCharE_E2C8 {
    char pad_0x00[0x11];
    signed char charID;     // 0x11
    char pad_0x12[0x2];
    int w[2];
};

struct sNetState_E2C8 {
    sNetHdr_E2C8 hdr;                   // 0x000
    sCharE_E2C8 me;             // 0x04C
    sCharE_E2C8 chars[6];       // 0x068
    signed char charID;                 // 0x110
    sNetTag_E2C8 tag;                   // 0x111
    sNetKey_E2C8 keys[0x55];            // 0x118
    sNetHW_E2C8 blob[0x20D];            // 0x316
    char pad_0xB4A[2];
    sNetDW_E2C8 moves[0x1A];            // 0xB4C
    sNetTrip_E2C8 t0;                   // 0xC1C
    sNetTrip_E2C8 t1;                   // 0xC28
    sNetPair_E2C8 pair;                 // 0xC34
    int a;                              // 0xC3C
    int b;                              // 0xC40
};

extern sCharE_E2C8 D_00535B20_E2C8[] __asm__("D_00535B20");
extern int D_004A11B8;
extern int D_004A11BC;
extern sNetHdr_E2C8 D_005305B0;
extern char D_005308D0[];
extern char D_004A6F38[];
extern char D_004A7778[];
extern char D_004A7887[];

extern "C" void func_0014E2C8(void* self, int p, sNetState_E2C8* out)
{
    out->a = D_004A11B8;
    out->b = D_004A11BC;
    out->hdr = D_005305B0;
    for (int i = 0; i < 6; i++) {
        out->chars[i] = D_00535B20_E2C8[i];
    }
    out->me = D_00535B20_E2C8[p];
    signed char c = D_00535B20_E2C8[p].charID;
    out->charID = c;
    out->pair = *(sNetPair_E2C8*)D_005308D0;
    out->t0 = *(sNetTrip_E2C8*)(D_005308D0 - 0x18);
    out->t1 = *(sNetTrip_E2C8*)(D_005308D0 - 0xC);
    for (int k = 0; k < 0x20D; k++) {
        out->blob[k] = ((sNetHW_E2C8*)(D_004A6F38 + (c * 0xF88 + p * 0x9B50)))[k];
    }
    for (int k = 0; k < 0x1A; k++) {
        out->moves[k] = ((sNetDW_E2C8*)(D_004A7778 + (c * 0xF88 + p * 0x9B50)))[k];
    }
    out->tag = *(sNetTag_E2C8*)(D_004A7887 + (c * 0xF88 + p * 0x9B50));
    for (int k = 0; k < 0x55; k++) {
        out->keys[k] = ((sNetKey_E2C8*)(D_004A7887 + 7 + (c * 0xF88 + p * 0x9B50)))[k];
    }
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014E5C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00151600(void* p, int i, int arg);
extern "C" void func_00156810(void* self);
extern sNetTrip_E2C8 D_005308B8_E5C8[] __asm__("D_005308B8");

struct sProfChar_E5C8 {
    char d[0xF88];
};

extern sProfChar_E5C8 D_004A6CA8_E5C8[][10] __asm__("D_004A6CA8");

class cBEIface_E5C8 {
public:
    int pad[3];
    virtual void v01();
    virtual void v02();
};

extern "C" void func_0014E5C8(void* self, int p, sNetState_E2C8* in)
{
    D_004A11B8 = in->a;
    D_004A11BC = in->b;
    D_005305B0 = in->hdr;
    ((cBEIface_E5C8*)cBE_getInterface_Fv(cBE_getBE(), 0))->v02();
    if (D_00534B30.data[2] == 0)
    {
        for (int i = 2; i < 6; i++)
            D_00535B20_E2C8[i] = in->chars[i];
    }
    D_00535B20_E2C8[p] = in->me;
    ((cBEIface_E5C8*)cBE_getInterface_Fv(cBE_getBE(), 1))->v02();
    signed char c = in->charID;
    if (D_00534B30.data[2] == 0)
        *(sNetPair_E2C8*)D_005308D0 = in->pair;
    D_005308B8_E5C8[p] = (&in->t0)[p];
    func_00151600(&D_004A6CA8_E5C8[p][c], c, 1);
    func_00156810(D_004A6CA8_E5C8[p]);
    for (int k = 0; k < 0x20D; k++)
        ((sNetHW_E2C8*)((char*)D_004A6CA8_E5C8 + 0x290 + (c * 0xF88 + p * 0x9B50)))[k] = in->blob[k];
    for (int k = 0; k < 0x1A; k++)
        ((sNetDW_E2C8*)(D_004A7778 + (c * 0xF88 + p * 0x9B50)))[k] = in->moves[k];
    *(sNetTag_E2C8*)(D_004A7887 + (c * 0xF88 + p * 0x9B50)) = in->tag;
    for (int k = 0; k < 0x55; k++)
        ((sNetKey_E2C8*)(D_004A7887 + 7 + (c * 0xF88 + p * 0x9B50)))[k] = in->keys[k];
    ((cBEIface_E5C8*)cBE_getInterface_Fv(cBE_getBE(), 6))->v02();
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014E9C0);
#ifdef SKIP_ASM
struct sBEPlayerData {
    char data[0x9B50];
};
extern sBEPlayerData D_004A6CA8[];

extern "C" void func_00156858(sBEPlayerData* dst, sBEPlayerData* src);

extern "C" void func_0014E9C0(void* self, int a1, int a2)
{
    sBEPlayerData* src = &D_004A6CA8[a1];
    func_00156858(&D_004A6CA8[a2], src);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/beintnetwork", func_0014E9F8);
#ifdef SKIP_ASM
extern "C" void func_001567B8(void* self, int arg);
// PORT: func_0014EB08 is defined (void) in this unit but called with self here.
void func_0014EB08_self(void* self) __asm__("func_0014EB08");

struct sRiderEntry_0014E9F8 {
    int w[7];
};

extern char D_004BA348[];
extern int D_00534B38[];
extern sRiderEntry_0014E9F8 D_00535B3C;

extern "C" void func_0014E9F8(void* self)
{
    func_001567B8(D_004BA348, 0);
    if (D_00534B38[0] == 0)
    {
        sRiderEntry_0014E9F8* e = &D_00535B3C;
        e[0] = e[-1];
        func_0014E9C0(self, 0, 1);
    }
    func_0014EB08_self(self);
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EA90);
#ifdef SKIP_ASM
struct sVEntry0014EA90 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sBEIface0014EA90 {
    char pad_0x00[0xC];
    sVEntry0014EA90* vtable; // 0xC
};

extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_0014EB08 is defined (void) in this unit but called with self here.
void func_0014EB08_self(void* self) __asm__("func_0014EB08");

extern "C" void func_0014EA90(void* self)
{
    sBEIface0014EA90* a = (sBEIface0014EA90*)cBE_getInterface_Fv(cBE_getBE(), 3);
    a->vtable[2].fn((char*)a + a->vtable[2].delta);
    sBEIface0014EA90* b = (sBEIface0014EA90*)cBE_getInterface_Fv(cBE_getBE(), 0xC);
    b->vtable[2].fn((char*)b + b->vtable[2].delta);
    func_0014EB08_self(self);
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EB08);
#ifdef SKIP_ASM
struct sNetSlot_0014EB08
{
    unsigned int a : 1;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 28;
    int x;
    int y;
};

extern sNetSlot_0014EB08 D_005308B8[];

extern "C" void func_0014EB08(void)
{
    sNetSlot_0014EB08 tmp = D_005308B8[0];
    D_005308B8[0].y = D_005308B8[1].y;
    D_005308B8[0].c = D_005308B8[1].c;
    D_005308B8[0].a = D_005308B8[1].a;
    D_005308B8[0].x = D_005308B8[1].x;
    D_005308B8[1].y = tmp.y;
    D_005308B8[1].c = tmp.c;
    D_005308B8[1].a = tmp.a;
    D_005308B8[1].x = tmp.x;
}
#endif

extern "C" char* strcpy(char*, const char*);
extern char D_00534FC8[16];

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EBB8);
#ifdef SKIP_ASM
extern "C" void func_0014EBB8(void* self, const char* src)
{
    strcpy(D_00534FC8, src);
}
#endif

extern char D_00534FB8[16];

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EBD8);
#ifdef SKIP_ASM
extern "C" void func_0014EBD8(void* self, const char* src)
{
    strcpy(D_00534FB8, src);
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EBF8);
#ifdef SKIP_ASM
struct sCharEntry_0014EBF8
{
    char pad_0x00[0x11];
    signed char charID; // 0x11
    char pad_0x12[0x2];
    int w[2];
};

extern sCharEntry_0014EBF8 D_00535B20[];
extern sCharEntry_0014EBF8 D_00534A88[];
extern "C" void func_00156950(sBEPlayerData* data, int charID);

extern "C" void func_0014EBF8(void* self, int idx)
{
    func_00156950(&D_004A6CA8[idx], D_00535B20[idx].charID);
    for (int i = 0; i < 6; i++)
    {
        D_00534A88[i] = D_00535B20[i];
    }
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014ECA0);
#ifdef SKIP_ASM
extern "C" void func_00156988(sBEPlayerData* data);

extern "C" void func_0014ECA0(void* self, int idx)
{
    func_00156988(&D_004A6CA8[idx]);
    if (D_00534B38[0] == 0)
    {
        D_00535B20[0] = D_00535B20[1];
    }
    for (int i = 1; i < 6; i++)
    {
        D_00535B20[i] = D_00534A88[i];
    }
    sBEIface0014EA90* a = (sBEIface0014EA90*)cBE_getInterface_Fv(cBE_getBE(), 1);
    a->vtable[2].fn((char*)a + a->vtable[2].delta);
    sBEIface0014EA90* b = (sBEIface0014EA90*)cBE_getInterface_Fv(cBE_getBE(), 6);
    b->vtable[2].fn((char*)b + b->vtable[2].delta);
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EDD8);
#ifdef SKIP_ASM
extern const char D_0045A280[];
extern void* D_0045AD38[16];
extern void* D_004A1208;

extern "C" void* func_0014EDD8(void)
{
    if (D_004A1208 == 0) {
        cBENetworkInterface* mem = (cBENetworkInterface*)cMemMan_alloc(0x10, D_0045A280, 0, 0);
        mem->field_0x8 = 0;
        mem->vtable = D_0045AD38;
        D_004A1208 = mem;
    }
    return D_004A1208;
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EE28);
#ifdef SKIP_ASM
signed char cBELibrary_getCharacterID(int index);

struct sNetChar_0014EE28
{
    char data[0x88];
};

extern sNetChar_0014EE28 D_00530970[];

extern "C" void* func_0014EE28(void* self, int rider)
{
    return &D_00530970[cBELibrary_getCharacterID(rider)];
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EE58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
signed char cBELibrary_getCharacterID(int index);
extern "C" signed char func_0014A0B0(int index);

struct sNetEntry8_0014EE58
{
    char data[8];
};

struct sNetEntry88_0014EE58
{
    char data[0x88];
};

extern sNetEntry8_0014EE58 D_0043FA38_0014EE58[] __asm__("D_0043FA38");
extern sNetEntry88_0014EE58 D_00530990_0014EE58[] __asm__("D_00530990");

extern "C" void* func_0014EE58(void* self, int rider)
{
    int c = cBELibrary_getCharacterID(rider);
    int index = func_0014A0B0(rider);
    if (index >= 10 && index < 30) {
        return &D_0043FA38_0014EE58[index];
    }
    return &D_00530990_0014EE58[c];
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EEC8);
#ifdef SKIP_ASM
struct sNetEntry8_0043FA38
{
    char data[8];
};

struct sNetEntry88_00530990
{
    char data[0x88];
};

extern sNetEntry8_0043FA38 D_0043FA38[];
extern sNetEntry88_00530990 D_00530990[];

extern "C" void* func_0014EEC8(void* self, int player, int index)
{
    if (index >= 10 && index < 30) {
        return &D_0043FA38[index];
    }
    return &D_00530990[player];
}
#endif

//100%
INCLUDE_ASM("be/beintnetwork", func_0014EF00);
#ifdef SKIP_ASM
signed char cBELibrary_getCharacterID(int index);

struct sNetChar_0014EF00
{
    char pad_0x00[0x30];
    char field_0x30[0x88 - 0x30];
};

extern sNetChar_0014EF00 D_00530970_EF00[] __asm__("D_00530970");

extern "C" void* func_0014EF00(void* self, int rider)
{
    return D_00530970_EF00[cBELibrary_getCharacterID(rider)].field_0x30;
}
#endif

