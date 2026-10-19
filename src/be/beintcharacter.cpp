#include "common.h"

signed char cBELibrary_getCharacterID(int index);

struct sCharWeightEntry {
    char pad_0x00[0x40];
    int mWeight;
    char pad_0x44[0x88 - 0x40 - 4];
};
extern sCharWeightEntry D_00530970[];

//100%
INCLUDE_ASM("be/beintcharacter", cBECharacterInterface_getWeight__FPvi);
#ifdef SKIP_ASM
int cBECharacterInterface_getWeight(void* self, int riderIndex)
{
    return D_00530970[cBELibrary_getCharacterID(riderIndex)].mWeight;
}
#endif

//100%
INCLUDE_ASM("be/beintcharacter", func_0014EF70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// sCharWeightEntry (declared above in the unit) has no field at 0x44 yet;
// this view of the same table binds to D_00530970.
struct sCharWeightEntryView {
    char pad_0x00[0x40];
    int mWeight;        // 0x40
    int field_0x44;     // 0x44
    char pad_0x48[0x88 - 0x48];
};
extern sCharWeightEntryView D_00530970_view[] __asm__("D_00530970");

extern "C" bool func_0014EF70(void* self, int riderIndex)
{
    int charID = cBELibrary_getCharacterID(riderIndex);
    return D_00530970_view[charID].field_0x44 != 0;
}
#endif

//100%
INCLUDE_ASM("be/beintcharacter", func_0014EFA8);
#ifdef SKIP_ASM
signed char cBELibrary_getCharacterID(int index);
extern "C" int func_0014A0B0(int riderIndex);
extern "C" void* cBE_getBE();
void* cBE_getInterface_EFA8(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_isMissionMan(int riderIndex);
extern signed char D_00535C11[];

struct sCharScaleEntry_EFA8 {
    char pad_0x00[0x48];
    int mScale;         // 0x48, percent
    char pad_0x4C[0x88 - 0x4C];
};
extern sCharScaleEntry_EFA8 D_00530970_EFA8[] __asm__("D_00530970");

// Model scale for a rider: fixed values for the cheat characters,
// 0.8 for mission men, otherwise the character table's percentage.
extern "C" float func_0014EFA8(void* self, int riderIndex)
{
    int charID = cBELibrary_getCharacterID(riderIndex);
    int cheat = func_0014A0B0(riderIndex);
    cBE_getInterface_EFA8(cBE_getBE(), 0);
    if (cheat != 0 && (D_00535C11[0] != 0 || riderIndex != 0)) {
        switch (cheat) {
        case 10:
            return 0.98f;
        case 11:
        case 14:
            return 0.85f;
        case 29:
            return 2.0f;
        case 28:
            return 0.7f;
        case 26:
            return 1.5f;
        case 20:
            return 1.2f;
        case 22:
        case 23:
            return 1.3f;
        case 15:
        case 17:
            return 0.75f;
        case 13:
        case 18:
        case 19:
        case 21:
            return 1.0f;
        default:
            return 0.9f;
        }
    }
    if (cBENewPlayerInterface_isMissionMan(riderIndex)) {
        return 0.8f;
    }
    return D_00530970_EFA8[charID].mScale * 0.01f;
}
#endif


//100%
INCLUDE_ASM("be/beintcharacter", func_0014F100);
#ifdef SKIP_ASM
extern "C" void func_0014F100(void) {

}
#endif

INCLUDE_ASM("be/beintcharacter", func_0014F108);

INCLUDE_ASM("be/beintcharacter", func_0014F138);

INCLUDE_ASM("be/beintcharacter", func_0014F170);

INCLUDE_ASM("be/beintcharacter", func_0014F1B0);

INCLUDE_ASM("be/beintcharacter", func_0014F1E0);

INCLUDE_ASM("be/beintcharacter", func_0014F210);