#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A6D8[];

struct sVTableBAGT {
    char pad_0x00[0x10];
    short field_0x10;
    char pad_0x12[2];
    void (*fn)(void*);
};
extern sVTableBAGT D_0045ACD8;

struct cBEBAGTInterface {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};
extern void* D_004A1210;

//100%
INCLUDE_ASM("be/beintbagt", cBEBAGTInterface_getThis__Fv);
#ifdef SKIP_ASM
void* cBEBAGTInterface_getThis()
{
    if (D_004A1210 == 0) {
        cBEBAGTInterface* mem = (cBEBAGTInterface*)cMemMan_alloc(0x10, D_0045A6D8, 0, 0);
        D_004A1210 = mem;
        sVTableBAGT* vt = &D_0045ACD8;
        short d = vt->field_0x10;
        void (*fn)(void*) = vt->fn;
        mem->vtable = vt;
        fn((char*)mem + d);
        ((cBEBAGTInterface*)D_004A1210)->field_0x8 = 0;
    }
    return D_004A1210;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014F960);
#ifdef SKIP_ASM
struct sBagtRec {
    short data[0xFF];
};

struct sBagtSlot {
    sBagtRec rec;
    char pad[0xF88 - 0x1FE];
};

extern sBagtSlot D_004A788E[3][10];
extern sBagtRec D_00530EC0[3][10];

extern "C" void func_0014F960(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            D_004A788E[i][j].rec = D_00530EC0[i][j];
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014FAD0);
#ifdef SKIP_ASM
extern sBagtSlot D_004A788E[3][10];
extern sBagtRec D_00530EC0[3][10];

extern "C" void func_0014FAD0(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            D_00530EC0[i][j] = D_004A788E[i][j].rec;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014FC40);
#ifdef SKIP_ASM
extern sBagtSlot D_004A788E[3][10];
extern sBagtRec D_00530EC0[3][10];

extern "C" void func_0014FC40(int i)
{
    for (int j = 0; j < 10; j++) {
        D_00530EC0[i][j] = D_004A788E[i][j].rec;
    }
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014FD80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern char D_00530EC0_raw[] __asm__("D_00530EC0");

extern "C" int func_0014FD80(void* self, int rider, int idx, int value)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int off = idx * 6 + c * 0x1FE + profile * 0x13EC;
    char* p = D_00530EC0_raw + off;
    p[1] = value;
    return 1;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014FE08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

struct sBagtEntry {
    unsigned char b0;
    unsigned char b1;
    unsigned short flags;  // 0x2
    unsigned short flags2; // 0x4
};

struct sBagtEntries {
    sBagtEntry e[85];
};

extern sBagtEntries D_00530EC0_e[3][10] __asm__("D_00530EC0");

extern "C" int func_0014FE08(void* self, int rider, int idx, int bit)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    D_00530EC0_e[profile][c].e[idx].flags &= ~(1 << bit);
    return 1;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014FEA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern char D_00530EC0_raw[] __asm__("D_00530EC0");
struct sPad20;
extern sPad20 D_0045AEB8;

extern "C" int func_0014FEA8(void* self, int rider, int idx, int second)
{
    char* t = (char*)&D_0045AEB8 + idx * 0x14;
    if (*(unsigned short*)(t + 0xC) == 0)
        return -1;
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int r;
    if (second)
    {
        char* p = D_00530EC0_raw + (idx * 6 + c * 0x1FE + profile * 0x13EC);
        r = (unsigned char)p[1];
    }
    else
    {
        char* p = D_00530EC0_raw + (idx * 6 + c * 0x1FE + profile * 0x13EC);
        r = (unsigned char)p[0];
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014FF90);
#ifdef SKIP_ASM
struct sBagInfo_FF90 {
    char pad[0xC];
    unsigned short count;  // 0xC
    short pad2;
    int value;             // 0x10
};
extern sBagInfo_FF90 D_0045AEB8_FF90[] __asm__("D_0045AEB8");

// Release-build assert: expands to an empty do { } while (0); its loop notes keep the target's register choice.
#define ASSERT_FF90(cond) do { } while (0)

extern "C" int func_0014FF90(void* self, int rider, int idx, int* count)
{
    int r = D_0045AEB8_FF90[idx].value;
    unsigned short c;
    c = D_0045AEB8_FF90[idx].count;
    *count = c;
    ASSERT_FF90(count != 0);
    return r;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_0014FFB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sBagtEntries D_00530EC0_e[3][10] __asm__("D_00530EC0");

extern "C" int func_0014FFB8(void* self, int rider, int idx, int bit)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return (D_00530EC0_e[profile][c].e[idx].flags >> bit) & 1;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_00150048);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern sBagtEntries D_00530EC0_e[3][10] __asm__("D_00530EC0");

extern "C" int func_00150048(void* self, int rider, int idx, int bit)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    return (D_00530EC0_e[profile][c].e[idx].flags2 >> bit) & 1;
}
#endif

struct sPad20 { char x; int pad[4]; };
extern sPad20 D_0045AEB8;

//100%
INCLUDE_ASM("be/beintbagt", func_001500D8);
#ifdef SKIP_ASM
extern "C" unsigned short func_001500D8(void* self, int a1, int a2)
{
    return *(unsigned short*)((char*)&D_0045AEB8 + a2 * 0x14);
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_001500F8);
#ifdef SKIP_ASM
extern "C" unsigned short func_001500F8(void* self, int a1, int a2)
{
    char* p = (char*)&D_0045AEB8 + a2 * 0x14;
    return *(unsigned short*)(p + 0x2);
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_00150118);
#ifdef SKIP_ASM
extern "C" unsigned short func_00150118(void* self, int a1, int a2)
{
    char* p = (char*)&D_0045AEB8 + a2 * 0x14;
    return *(unsigned short*)(p + 0x4);
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_00150138);
#ifdef SKIP_ASM
extern "C" unsigned short func_00150138(void* self, int a1, int a2)
{
    char* p = (char*)&D_0045AEB8 + a2 * 0x14;
    return *(unsigned short*)(p + 0x6);
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_00150158);
#ifdef SKIP_ASM
extern "C" unsigned short func_00150158(void* self, int a1, int a2)
{
    char* p = (char*)&D_0045AEB8 + a2 * 0x14;
    return *(unsigned short*)(p + 0x8);
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_00150178);
#ifdef SKIP_ASM
extern "C" unsigned short func_00150178(void* self, int a1, int a2)
{
    char* p = (char*)&D_0045AEB8 + a2 * 0x14;
    return *(unsigned short*)(p + 0xa);
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_00150198);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPad20;
extern sPad20 D_0045AEB8;
extern "C" int func_0014A0B0(int rider);
extern "C" int func_0014FEA8(void* self, int rider, int idx, int second);

struct sBagtAnim_150198
{
    unsigned short anim;
    unsigned short anim2;
    unsigned short anim3;
    unsigned short pad;
};

struct sBagtCat_150198
{
    char pad0[0x10];
    sBagtAnim_150198* anims;    // 0x10
};
// Typed view of D_0045AEB8 (declared as sPad20 in this unit).
extern sBagtCat_150198 D_0045AEB8_150198[] __asm__("D_0045AEB8");

extern "C" int func_00150198(void* self, int rider, int idx, int second)
{
    int ch = func_0014A0B0(rider);
    if (ch != 0)
    switch (ch)
    {
    case 0x14:
        if (idx == 4) return 0xA0;
        break;
    case 0x18:
        if (idx == 4) return 0x9F;
        break;
    case 0x19:
        if (idx == 9) return 0xA2;
        break;
    case 0x1C:
        if (idx == 4) return 0xA1;
        break;
    }
    int k = func_0014FEA8(self, rider, idx, second);
    if (k < 0) return 0x1B6;
    return D_0045AEB8_150198[idx].anims[k].anim;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_001502C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPad20;
extern sPad20 D_0045AEB8;
extern "C" int func_0014A0B0(int rider);
extern "C" int func_0014FEA8(void* self, int rider, int idx, int second);

struct sBagtAnim_1502C8
{
    unsigned short anim;
    unsigned short anim2;
    unsigned short anim3;
    unsigned short pad;
};

struct sBagtCat_1502C8
{
    char pad0[0x10];
    sBagtAnim_1502C8* anims;    // 0x10
};
// Typed view of D_0045AEB8 (declared as sPad20 in this unit).
extern sBagtCat_1502C8 D_0045AEB8_1502C8[] __asm__("D_0045AEB8");

extern "C" int func_001502C8(void* self, int rider, int idx, int second)
{
    int ch = func_0014A0B0(rider);
    if (ch != 0)
    switch (ch)
    {
    case 0x14:
        if (idx == 4) return 0xD2;
        break;
    case 0x18:
        if (idx == 4) return 0xD1;
        break;
    case 0x19:
        if (idx == 9) return 0xD4;
        break;
    case 0x1C:
        if (idx == 4) return 0xD3;
        break;
    }
    int k = func_0014FEA8(self, rider, idx, second);
    if (k < 0) return 0x1B6;
    return D_0045AEB8_1502C8[idx].anims[k].anim2;
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_001503F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPad20;
extern sPad20 D_0045AEB8;
extern "C" int func_0014A0B0(int rider);
extern "C" int func_0014FEA8(void* self, int rider, int idx, int second);

struct sBagtAnim_1503F8
{
    unsigned short anim;
    unsigned short anim2;
    unsigned short anim3;
    unsigned short pad;
};

struct sBagtCat_1503F8
{
    char pad0[0x10];
    sBagtAnim_1503F8* anims;    // 0x10
};
// Typed view of D_0045AEB8 (declared as sPad20 in this unit).
extern sBagtCat_1503F8 D_0045AEB8_1503F8[] __asm__("D_0045AEB8");

extern "C" int func_001503F8(void* self, int rider, int idx, int second)
{
    int ch = func_0014A0B0(rider);
    if (ch != 0)
    switch (ch)
    {
    case 0x14:
        if (idx == 4) return 0x52;
        break;
    case 0x18:
        if (idx == 4) return 0x51;
        break;
    case 0x19:
        if (idx == 9) return 0x54;
        break;
    case 0x1C:
        if (idx == 4) return 0x53;
        break;
    }
    int k = func_0014FEA8(self, rider, idx, second);
    if (k < 0) return 0;
    return D_0045AEB8_1503F8[idx].anims[k].anim3;
}
#endif

extern void* D_00530600[];

//100%
INCLUDE_ASM("be/beintbagt", func_00150528__FPvi);
#ifdef SKIP_ASM
int func_00150528(void* self, int a1)
{
    return *(int*)((char*)(void*)D_00530600 + a1 * 8);
}
#endif

//100%
INCLUDE_ASM("be/beintbagt", func_00150540__FPvi);
#ifdef SKIP_ASM
struct sBAGTEntry {
    int key;
    int value;
};

struct sBAGTTable {
    sBAGTEntry entries[1];
};

int func_00150540(void* self, int a1)
{
    return ((sBAGTTable*)D_00530600)->entries[a1].value;
}
#endif

INCLUDE_ASM("be/beintbagt", func_00150558);

