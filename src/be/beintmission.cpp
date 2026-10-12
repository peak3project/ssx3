#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A848[];
extern void* D_0045ADF8[16];
extern void* D_004A1238;

struct cBEMissionInterface {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

//99.58%
INCLUDE_ASM("be/beintmission", cBEMissionInterface_getThis__Fv);
#ifdef SKIP_ASM
void* cBEMissionInterface_getThis()
{
    if (D_004A1238 == 0) {
        cBEMissionInterface* mem = (cBEMissionInterface*)cMemMan_alloc(0x14, D_0045A848, 0, 0);
        mem->field_0x8 = 0;
        mem->vtable = D_0045ADF8;
        D_004A1238 = mem;
    }
    return D_004A1238;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153350);
#ifdef SKIP_ASM
extern signed char D_0043FA70[];

extern "C" int func_00153350(void* self, int start)
{
    int sum = 0;
    for (int i = 0; i < 1; i++)
    {
        sum += D_0043FA70[start + i];
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153390);
#ifdef SKIP_ASM
struct sMissionEntry_0043D950
{
    char pad_0x00[0x54];
    int owner;          // 0x54
    char pad_0x58[0xC];
};

extern sMissionEntry_0043D950 D_0043D950[];
extern signed char D_0043FA70[];

extern "C" int func_00153390(void* self, int owner)
{
    int sum = 0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].owner == owner)
            {
                sum += D_0043FA70[i + j];
            }
        }
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern int D_005305F0[];
// Byte view of the profile table; the unit declares D_004A6CA8 later with a struct type.
extern char D_004A6CA8_raw[] __asm__("D_004A6CA8");

extern "C" int func_00153498(void* self, int rider, int idx)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int off = (idx + D_005305F0[0]) * 12 + c * 0xF88 + profile * 0x9B50;
    char* p = D_004A6CA8_raw + off;
    return *(signed char*)(p + 4);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153520);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
// Byte view of the profile table; the unit declares D_004A6CA8 later with a struct type.
extern char D_004A6CA8_raw[] __asm__("D_004A6CA8");

extern "C" int func_00153520(void* self, int rider, int idx)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int sum = 0;
    int off = idx * 12 + c * 0xF88 + profile * 0x9B50;
    char* p = D_004A6CA8_raw + off;
    for (int i = 0; i < 1; i++)
    {
        sum += *(signed char*)(p + i * 12 + 4);
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", cBEMissionInterface_getCurrentCollectForPeak);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

struct sEconRecord_001535C0
{
    int id;
    signed char count; // 0x4
    char pad_0x05[0x7];
};

// One character's economy block (0xF88 bytes); 10 per profile (0x9B50).
struct sEconChar_001535C0
{
    sEconRecord_001535C0 records[22];
    char pad[0xF88 - 22 * 12];
};

extern sMissionEntry_0043D950 D_0043D950[];
extern sEconChar_001535C0 D_004A6CA8_econ[][10] __asm__("D_004A6CA8");

extern "C" int cBEMissionInterface_getCurrentCollectForPeak(void* self, int rider, int owner)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int character = cBELibrary_getCharacterID(rider);
    int sum = 0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].owner == owner)
            {
                sum += D_004A6CA8_econ[profile][character].records[i + j].count;
            }
        }
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153688);
#ifdef SKIP_ASM
struct sEconRecord_00153688
{
    int id;
    signed char count; // 0x4
    char pad_0x05[0x7];
};

// One character's economy block (0xF88 bytes); 10 per profile (0x9B50).
struct sEconChar_00153688
{
    sEconRecord_00153688 records[22];
    char pad[0xF88 - 22 * 12];
};

extern sMissionEntry_0043D950 D_0043D950[];
extern sEconChar_00153688 D_004A6CA8[][10];

extern "C" int func_00153688(void* self, int profile, int character, int owner)
{
    int sum = 0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].owner == owner)
            {
                sum += D_004A6CA8[profile][character].records[i + j].count;
            }
        }
    }
    return sum;
}
#endif

INCLUDE_ASM("be/beintmission", func_00153708);

//100%
INCLUDE_ASM("be/beintmission", func_001538E8);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern int D_005305F0[];
extern char D_004A6CAC[];

extern "C" int func_001538E8(void* self, int rider, int bit, int idx)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int off = profile * 0x9B50 + c * 0xF88 + D_005305F0[0] * 12;
    char* p = D_004A6CAC + (idx * 12 + off);
    p = p + (bit / 32) * 4;
    int mask = 1 << bit;
    return (*(unsigned int*)(p + 4) & mask) != 0;
}
#endif

INCLUDE_ASM("be/beintmission", func_00153B00);

//100%
INCLUDE_ASM("be/beintmission", func_00153C88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sMissionDefView_00153C88
{
    int id;
    int f4;
    char pad_0x08[0x1C];
};
extern sMissionDefView_00153C88 D_0043EE10_v00153C88[] __asm__("D_0043EE10");
extern void* D_004A28A8;
extern "C" int func_00154240(void* self, int id);

class cMissionObj_00153C88
{
public:
    char pad_0x00[0x4];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a);
};

extern "C" void func_00153C88(void* self, int id)
{
    int i = func_00154240(self, id);
    ((cMissionObj_00153C88*)*(void**)((char*)D_004A28A8 + 0x8C))->v4(D_0043EE10_v00153C88[i].f4);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153D28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sMissionDefView_00153D28
{
    int id;
    int f4;
    int f8;
    int fC;
    char pad_0x10[0x14];
};
extern sMissionDefView_00153D28 D_0043EE10_v00153D28[] __asm__("D_0043EE10");
extern void* D_004A28A8;
extern "C" int func_00154240(void* self, int id);

class cMissionObj_00153D28
{
public:
    char pad_0x00[0x4];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a);
};

extern "C" void func_00153D28(void* self, int id)
{
    int i = func_00154240(self, id);
    ((cMissionObj_00153D28*)*(void**)((char*)D_004A28A8 + 0x8C))->v4(D_0043EE10_v00153D28[i].fC);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153D78);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153D78(void* self, int id)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    return (*(unsigned int*)(p + 0x118) >> 3) & 1;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153DD0);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153DD0(void* self, int id)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    return (*(unsigned int*)(p + 0x118) >> 1) & 1;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153E28);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153E28(void* self, int id)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    return (*(unsigned int*)(p + 0x118)) & 1;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153E80);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153E80(void* self, int id)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    return (*(unsigned int*)(p + 0x118) >> 2) & 1;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153ED8);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153ED8(void* self, int id)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    return (*(unsigned int*)(p + 0x118) >> 4) & 1;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153FA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// The unit's sMissionDef_0043EE10 is defined later (with func_00154240) and lacks
// the fields at 0x18/0x1C; this local view of the same table binds to D_0043EE10.
struct sMissionDefView_0043EE10
{
    int id;             // 0x00
    char pad_0x04[0xC];
    int group;          // 0x10
    char pad_0x14[0x4];
    short field_0x18;   // 0x18
    char pad_0x1A[0x2];
    int field_0x1C;     // 0x1C
    char pad_0x20[0x2];
    short value;        // 0x22
};
extern sMissionDefView_0043EE10 D_0043EE10_view[] __asm__("D_0043EE10");

extern "C" int func_00154240(void* self, int id);

extern "C" short func_00153FA0(void* self, int id)
{
    int i = func_00154240(self, id);
    return D_0043EE10_view[i].field_0x18;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153FD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// The unit's sMissionDef_0043EE10 is defined later (with func_00154240) and lacks
// the fields at 0x18/0x1C; this local view of the same table binds to D_0043EE10.
extern sMissionDefView_0043EE10 D_0043EE10_view[] __asm__("D_0043EE10");

extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153FD8(void* self, int id)
{
    int i = func_00154240(self, id);
    return D_0043EE10_view[i].field_0x1C;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154010);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" void func_00154010(void* self, int id, int value)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    *(int*)(p + 0x118) = (*(int*)(p + 0x118) & ~1) | (value & 1);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154080);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" void func_00154080(void* self, int id, int value)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    *(int*)(p + 0x118) = (*(int*)(p + 0x118) & ~(1 << 1)) | ((value & 1) << 1);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001540F0);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" void func_001540F0(void* self, int id, int value)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    *(int*)(p + 0x118) = (*(int*)(p + 0x118) & ~(1 << 2)) | ((value & 1) << 2);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154160);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" void func_00154160(void* self, int id, int value)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    *(int*)(p + 0x118) = (*(int*)(p + 0x118) & ~(1 << 3)) | ((value & 1) << 3);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001541D0);
#ifdef SKIP_ASM
int cBELibrary_getCharacterID(int);
extern "C" int func_00154240(void* self, int id);

extern "C" void func_001541D0(void* self, int id, int value)
{
    int i = func_00154240(self, id);
    int c = cBELibrary_getCharacterID(0);
    int off = (i << 2) + c * 0xF88;
    char* p = (char*)D_004A6CA8 + off;
    *(int*)(p + 0x118) = (*(int*)(p + 0x118) & ~(1 << 4)) | ((value & 1) << 4);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154240);
#ifdef SKIP_ASM
struct sMissionDef_0043EE10
{
    int id;             // 0x00
    char pad_0x04[0xC];
    int group;          // 0x10
    char pad_0x14[0xE];
    short value;        // 0x22
};

extern sMissionDef_0043EE10 D_0043EE10[];

extern "C" int func_00154240(void* self, int id)
{
    for (int i = 0; i < 88; i++) {
        if (D_0043EE10[i].id == id) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154278);
#ifdef SKIP_ASM
extern "C" int func_001542A0(void* self, int group);
extern int D_005305F0[];

extern "C" int func_00154278(void* self)
{
    return func_001542A0(self, D_005305F0[0]);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001542A0);
#ifdef SKIP_ASM
extern sMissionDef_0043EE10 D_0043EE10[];

extern "C" int func_001542A0(void* self, int group)
{
    int n = 0;
    for (int i = 0; i < 88; i++) {
        if (D_0043EE10[i].group == group) {
            n++;
        }
    }
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/beintmission", func_001542E0);
#ifdef SKIP_ASM
extern "C" int func_00153D78(void* self, int id);

extern "C" int func_001542E0(void* self, int group)
{
    int n = 0;
    for (int i = 0; i < 88; i++)
    {
        if (D_0043EE10[i].group == group)
        {
            if (func_00153D78(self, D_0043EE10[i].id))
                n++;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154368);
#ifdef SKIP_ASM
// D_0043EE20 is D_0043EE10 + 0x10: the `group` field of each 0x24-byte
// sMissionDef_0043EE10 entry, addressed through its own symbol.
struct sMissionGroup_0043EE20
{
    int group;          // 0x00 (0x10 in sMissionDef_0043EE10)
    char pad_0x04[0x20];
};

extern sMissionEntry_0043D950 D_0043D950[];
extern sMissionGroup_0043EE20 D_0043EE20[];

extern "C" int func_00154368(void* self, int owner)
{
    int n = 0;
    for (int i = 0; i < 88; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].owner == owner)
            {
                if (D_0043EE20[i].group == j)
                {
                    n++;
                }
            }
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001543E0);
#ifdef SKIP_ASM
struct sMissionEntry_43E0 {
    char pad_0x00[0x54];
    int owner;          // 0x54
    char pad_0x58[0xC];
};

struct sMissionDef_43E0 {
    int id;             // 0x0
    char pad4[0xC];
    int slot;           // 0x10
    char pad14[0x10];
};

extern sMissionEntry_43E0 D_0043D950_43E0[] __asm__("D_0043D950");
extern sMissionDef_43E0 D_0043EE10_43E0[] __asm__("D_0043EE10");
extern "C" int func_00153D78(void* self, int id);

// Counts the completed missions whose slot belongs to the given owner.
extern "C" int func_001543E0(void* self, int owner)
{
    int count = 0;
    for (int i = 0; i < 88; i++) {
        for (int j = 0; j < 22; j++) {
            if (D_0043EE10_43E0[i].slot == j && D_0043D950_43E0[j].owner == owner) {
                if (func_00153D78(self, D_0043EE10_43E0[i].id)) {
                    count++;
                }
            }
        }
    }
    return count;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/beintmission", func_001544D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_001543E0(void* self, int owner);

// View of D_0043D950[].owner (offset 0x54); splat labels that address D_0043D9A4.
struct sMissionOwnerView_001544D0
{
    int owner;
    char pad_0x04[0x60];
};
extern sMissionOwnerView_001544D0 D_0043D9A4[];

// One character's economy block (0xF88 bytes); mission flag words start at 0x118.
struct sEconFlags_001544D0
{
    char pad_0x00[0x118];
    unsigned int flags[88];
    char pad_0x278[0xF88 - 0x118 - 88 * 4];
};
extern sEconFlags_001544D0 D_004A6CA8_flags[][10] __asm__("D_004A6CA8");

extern "C" int func_001544D0(void* self, int profile, int character, int owner)
{
    if (*(void**)((char*)D_004A28A8 + 0x84) != 0)
    {
        return func_001543E0(self, owner);
    }
    int n = 0;
    for (int i = 0; i < 88; i++)
    {
        if (D_0043D9A4[D_0043EE10[i].group].owner == owner)
        {
            n += (D_004A6CA8_flags[profile][character].flags[i] >> 3) & 1;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154588);
#ifdef SKIP_ASM
extern "C" int func_001545B0(void* self, int a, int group);
extern int D_005305F0[];

extern "C" int func_00154588(void* self, int a)
{
    return func_001545B0(self, a, D_005305F0[0]);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001545B0);
#ifdef SKIP_ASM
extern sMissionDef_0043EE10 D_0043EE10[];

extern "C" int func_001545B0(void* self, int index, int group)
{
    int n = 0;
    for (int i = 0; i < 88; i++) {
        if (D_0043EE10[i].group == group) {
            if (n == index) {
                return D_0043EE10[i].id;
            }
            n++;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001545F8);
#ifdef SKIP_ASM
struct sMissionEntry {
    int id;              // 0x00
    char pad_0x04[0x14];
    int value;           // 0x18
    char pad_0x1c[0x10];
};

extern sMissionEntry D_00440770[];

extern "C" int func_001545F8(void* self, int id)
{
    for (int i = 0; i < 22; i++) {
        if (D_00440770[i].id == id) {
            return D_00440770[i].value;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154630);
#ifdef SKIP_ASM
extern "C" int func_00154630(void* self, int value, int id)
{
    for (int i = 0; i < 22; i++) {
        if (D_00440770[i].id == id && D_00440770[i].value >= value) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154678);
#ifdef SKIP_ASM
extern "C" sMissionEntry func_00154678(void* self, int id)
{
    for (int i = 0; i < 22; i++)
    {
        if (D_00440770[i].id == id)
        {
            return D_00440770[i];
        }
    }
    return D_00440770[0];
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154760);
#ifdef SKIP_ASM
extern "C" void* func_00154760(void* self, int id)
{
    for (int i = 0; i < 22; i++) {
        if (D_00440770[i].id == id) {
            return D_00440770[i].pad_0x04;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001547A0);
#ifdef SKIP_ASM
extern sMissionDef_0043EE10 D_0043EE10[];

extern "C" int func_001547A0(void* self, int id)
{
    for (int i = 0; i < 88; i++) {
        if (D_0043EE10[i].id == id) {
            return D_0043EE10[i].value;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001547D8__FPv);
#ifdef SKIP_ASM
void func_001547D8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001547E0__FPv);
#ifdef SKIP_ASM
void func_001547E0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001547E8);
#ifdef SKIP_ASM
struct sSerVEntry_001547E8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern char D_004A6CAC[];

extern "C" void func_001547E8(void* self, void* stream)
{
    int c = cBELibrary_getCharacterID(0);
    char* base = D_004A6CAC;
    int off = c * 0xF88;
    sSerVEntry_001547E8* e = &(*(sSerVEntry_001547E8**)stream)[1];
    e->fn((char*)stream + e->delta, base + off, 0x114);
    e = &(*(sSerVEntry_001547E8**)stream)[1];
    char* base2 = base + 0x114;
    e->fn((char*)stream + e->delta, base2 + off, 0x160);
    e = &(*(sSerVEntry_001547E8**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 8, 4);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154898);
#ifdef SKIP_ASM
struct sSerVEntry_00154898 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern char D_004A6CAC[];

extern "C" void func_00154898(void* self, void* stream)
{
    int c = cBELibrary_getCharacterID(0);
    char* base = D_004A6CAC;
    int off = c * 0xF88;
    sSerVEntry_00154898* e = &(*(sSerVEntry_00154898**)stream)[2];
    e->fn((char*)stream + e->delta, base + off, 0x114);
    e = &(*(sSerVEntry_00154898**)stream)[2];
    char* base2 = base + 0x114;
    e->fn((char*)stream + e->delta, base2 + off, 0x160);
    e = &(*(sSerVEntry_00154898**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 8, 4);
}
#endif

