#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A848[];
extern void* D_0045ADF8[16];
extern void* D_004A1238;

// Per-profile character stat levels / flag tables (as in be/beintplayer and be/belibrary).
struct sBEFlagEntryPC {
    short id;
    unsigned short flags;
};

struct sBEProfilePair {
    int a;
    int b;
};

struct sPlayerStat7 {
    signed char v[7];
};

// One collectable record per peak-mission slot (12 bytes).
struct sBEMissionRec {
    signed char collected;              // 0x0: number of bits set in bits[]
    char pad_0x1[3];
    unsigned int bits[2];               // 0x4: 64 collected flags
};

// One character's record inside a profile: D_004A6CA8 is [profile][character] of these
// (0x9B50 = 10 * 0xF88); same type as be/belibrary's sBEProfileChar.
struct sBEProfileChar {
    int field_0x000;                    // 0x000
    sBEMissionRec missions[23];         // 0x004
    unsigned int missionFlags[88];      // 0x118: one flag word per mission (D_0043EE10 order)
    // PORT: 64-bit `long` bitfield (8 bytes on EE); use uint64_t off-PS2.
    unsigned long b0 : 1;               // 0x278: bits 0-5 kind 0-2 flags, 6-11 more kind flags,
    unsigned long b1 : 1;               //        12/13 peak 1/2 locked, 14-19 kinds 6-11
    unsigned long b2 : 1;
    unsigned long b3 : 1;
    unsigned long b4 : 1;
    unsigned long b5 : 1;
    unsigned long b6 : 1;
    unsigned long b7 : 1;
    unsigned long b8 : 1;
    unsigned long b9 : 1;
    unsigned long b10 : 1;
    unsigned long b11 : 1;
    unsigned long b12 : 1;
    unsigned long b13 : 1;
    unsigned long b14 : 1;
    unsigned long b15 : 1;
    unsigned long b16 : 1;
    unsigned long b17 : 1;
    unsigned long b18 : 1;
    unsigned long b19 : 1;
    int field_0x27C;                    // 0x27C
    short level0;                       // 0x280
    short progress0;                    // 0x282
    short level1;                       // 0x284
    short progress1;                    // 0x286
    short* index;                       // 0x288
    int count;                          // 0x28C
    sBEFlagEntryPC entries[0x20D];      // 0x290
    char pad_0xAC4[0xBA0 - 0xAC4];
    sBEProfilePair pairs[7];            // 0xBA0
    char pad_0xBD8[0xBDF - 0xBD8];
    sPlayerStat7 stats;                 // 0xBDF
    char pad_0xBE6[0xF88 - 0xBE6];
};
extern sBEProfileChar D_004A6CA8[][10];

// Mission definition table D_0043EE10 (88 entries of 0x24 bytes).
struct sMissionDef {
    int id;             // 0x00
    int field_0x04;     // 0x04: text id (name)
    int field_0x08;     // 0x08: text id
    int field_0x0C;     // 0x0C: text id
    int group;          // 0x10: peak-mission slot (index into D_0043D950)
    int field_0x14;     // 0x14
    short field_0x18;   // 0x18
    char pad_0x1A[0x2];
    int field_0x1C;     // 0x1C
    char pad_0x20[0x2];
    short value;        // 0x22
};
extern sMissionDef D_0043EE10[];

// Event table D_0043D950 (0x64-byte entries); 0x54 is the peak the event belongs to.
struct sEventEntry {
    char pad_0x0[0x54];
    int peak;               // 0x54
    char pad_0x58[0xC];
};
extern sEventEntry D_0043D950[];

// Race settings (as in be/beintplayer): two rider -> player slot maps, the event and the race mode.
struct sRaceSettings {
    int playerID[6];            // 0x00
    int playerID2[6];           // 0x18
    char pad_0x30[0x40 - 0x30];
    int event;                  // 0x40 (index into D_0043D950)
    char pad_0x44[4];
    signed char mode;           // 0x48
    char pad_0x49[0x4C - 0x49];
};
extern sRaceSettings D_005305B0;

// vtable entry: this-adjust delta, slot index, function.
struct sSerVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// The text database at *(D_004A28A8 + 0x8C); slot 4 looks up a text id.
class cMissionObj
{
public:
    char pad_0x00[0x4];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int a);
};

struct cBEMissionInterface {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

//100%
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
INCLUDE_ASM("be/beintmission", func_001532F0);
#ifdef SKIP_ASM
extern signed char D_0043FA70[];

extern "C" int func_001532F0(void* self, int start)
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
    {
        sum += D_0043FA70[start + i];
    }
    return sum;
}
#endif
//100%
INCLUDE_ASM("be/beintmission", func_00153330);
#ifdef SKIP_ASM
extern signed char D_0043FA70[];
extern int D_005305F0[];

extern "C" int func_00153330(void* self, int start)
{
    return D_0043FA70[start + D_005305F0[0]];
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
extern signed char D_0043FA70[];

extern "C" int func_00153390(void* self, int owner)
{
    int sum = 0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].peak == owner)
            {
                sum += D_0043FA70[i + j];
            }
        }
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_001533F8);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern "C" int func_001533F8(void* self, int rider, int idx)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int sum = 0;
    int off = idx * 12 + c * 0xF88 + profile * 0x9B50;
    char* p = (char*)D_004A6CA8 + off;
    for (int i = 0; i < 17; i++)
    {
        sum += *(signed char*)(p + 4);
        p += 12;
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153498);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern int D_005305F0[];

extern "C" int func_00153498(void* self, int rider, int idx)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int off = (idx + D_005305F0[0]) * 12 + c * 0xF88 + profile * 0x9B50;
    char* p = (char*)D_004A6CA8 + off;
    return *(signed char*)(p + 4);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153520);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

extern "C" int func_00153520(void* self, int rider, int idx)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int sum = 0;
    int off = idx * 12 + c * 0xF88 + profile * 0x9B50;
    char* p = (char*)D_004A6CA8 + off;
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
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);


extern "C" int cBEMissionInterface_getCurrentCollectForPeak(void* self, int rider, int owner)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int character = cBELibrary_getCharacterID(rider);
    int sum = 0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].peak == owner)
            {
                sum += D_004A6CA8[profile][character].missions[i + j].collected;
            }
        }
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153688);
#ifdef SKIP_ASM

extern "C" int func_00153688(void* self, int profile, int character, int owner)
{
    int sum = 0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].peak == owner)
            {
                sum += D_004A6CA8[profile][character].missions[i + j].collected;
            }
        }
    }
    return sum;
}
#endif

INCLUDE_ASM("be/beintmission", func_00153708);

//100%
INCLUDE_ASM("be/beintmission", func_00153858);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);
extern int D_005305F0[];

extern "C" char* func_00153858(void* self, int rider, int idx)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    char* b = (char*)D_004A6CA8 + c * 0xF88;
    // PORT: pointer held as int (index-first addu)
    char* p = (char*)(profile * 0x9B50 + (int)b);
    char* q = p + (D_005305F0[0] * 12 + 4);
    return q + idx * 12 + 4;
}
#endif

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

//100%
INCLUDE_ASM("be/beintmission", func_001539A8);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int);
int cBELibrary_getCharacterID(int);

// D_004A6CB0 = D_004A6CA8 + 8 (the first mission record's bit words) is its own symbol in the target:
// one slot per mission, indexed as missions[block].m[i].
struct sMissionBits_9A8 {
    unsigned int w[2];
};
struct sBitsSlot_9A8 {
    sMissionBits_9A8 bits;
    char next[4];
};
struct sBitsBlock_9A8 {
    sBitsSlot_9A8 m[1];
};
struct sBitsProfile_9A8 {
    sBitsBlock_9A8 missions[(0xF88 - 4) / 12];
    char pad[4];
};

struct sMask8_9A8 { char b[8]; };

extern sBitsProfile_9A8 D_004A6CB0_bits[][10] __asm__("D_004A6CB0");

extern "C" void func_001539A8(void* self, int rider, int idx, sMask8_9A8* mask)
{
    int profile = cBELibrary_getProfileIndex(rider);
    int c = cBELibrary_getCharacterID(rider);
    int off = profile * 0x9B50 + c * 0xF88 + D_005305B0.event * 12;
    int count = 0;
    *(sMask8_9A8*)((char*)D_004A6CB0_bits + (idx * 12 + off)) = *mask;
    for (int k = 0; k < 64; k++) {
        if (D_004A6CB0_bits[profile][c].missions[D_005305B0.event].m[idx].bits.w[k / 32] & (1 << k))
            count++;
    }
    D_004A6CA8[profile][c].missions[idx + D_005305B0.event].collected = count;
}
#endif

INCLUDE_ASM("be/beintmission", func_00153B00);

//100%
INCLUDE_ASM("be/beintmission", func_00153C88);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_00154240(void* self, int id);

extern "C" void* func_00153C88(void* self, int id)
{
    int i = func_00154240(self, id);
    return ((cMissionObj*)*(void**)((char*)D_004A28A8 + 0x8C))->v4(D_0043EE10[i].field_0x04);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153CD8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_00154240(void* self, int id);

extern "C" void func_00153CD8(void* self, int id)
{
    int i = func_00154240(self, id);
    ((cMissionObj*)*(void**)((char*)D_004A28A8 + 0x8C))->v4(D_0043EE10[i].field_0x08);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153D28);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_00154240(void* self, int id);

extern "C" void* func_00153D28(void* self, int id)
{
    int i = func_00154240(self, id);
    return ((cMissionObj*)*(void**)((char*)D_004A28A8 + 0x8C))->v4(D_0043EE10[i].field_0x0C);
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
INCLUDE_ASM("be/beintmission", func_00153F30);
#ifdef SKIP_ASM
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153F30(void* self, int id)
{
    int i = func_00154240(self, id);
    return D_0043EE10[i].group;
}
#endif
//100%
INCLUDE_ASM("be/beintmission", func_00153F68);
#ifdef SKIP_ASM
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153F68(void* self, int id)
{
    int i = func_00154240(self, id);
    return D_0043EE10[i].field_0x14;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153FA0);
#ifdef SKIP_ASM
extern "C" int func_00154240(void* self, int id);

extern "C" short func_00153FA0(void* self, int id)
{
    int i = func_00154240(self, id);
    return D_0043EE10[i].field_0x18;
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00153FD8);
#ifdef SKIP_ASM
extern "C" int func_00154240(void* self, int id);

extern "C" int func_00153FD8(void* self, int id)
{
    int i = func_00154240(self, id);
    return D_0043EE10[i].field_0x1C;
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
// sMissionDef entry, addressed through its own symbol.
struct sMissionGroup_0043EE20
{
    int group;          // 0x00 (0x10 in sMissionDef)
    char pad_0x04[0x20];
};

extern sMissionGroup_0043EE20 D_0043EE20[];

extern "C" int func_00154368(void* self, int owner)
{
    int n = 0;
    for (int i = 0; i < 88; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (D_0043D950[j].peak == owner)
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
extern "C" int func_00153D78(void* self, int id);

// Counts the completed missions whose slot belongs to the given owner.
extern "C" int func_001543E0(void* self, int owner)
{
    int count = 0;
    for (int i = 0; i < 88; i++) {
        for (int j = 0; j < 22; j++) {
            if (D_0043EE10[i].group == j && D_0043D950[j].peak == owner) {
                if (func_00153D78(self, D_0043EE10[i].id)) {
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

// View of D_0043D950[].peak (offset 0x54); splat labels that address D_0043D9A4.
struct sMissionOwnerView_001544D0
{
    int peak;
    char pad_0x04[0x60];
};
extern sMissionOwnerView_001544D0 D_0043D9A4[];


extern "C" int func_001544D0(void* self, int profile, int character, int owner)
{
    if (*(void**)((char*)D_004A28A8 + 0x84) != 0)
    {
        return func_001543E0(self, owner);
    }
    int n = 0;
    for (int i = 0; i < 88; i++)
    {
        if (D_0043D9A4[D_0043EE10[i].group].peak == owner)
        {
            n += (D_004A6CA8[profile][character].missionFlags[i] >> 3) & 1;
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
extern char D_004A6CAC[];

extern "C" void func_001547E8(void* self, void* stream)
{
    int c = cBELibrary_getCharacterID(0);
    char* base = D_004A6CAC;
    int off = c * 0xF88;
    sSerVEntry* e = &(*(sSerVEntry**)stream)[1];
    e->fn((char*)stream + e->delta, base + off, 0x114);
    e = &(*(sSerVEntry**)stream)[1];
    char* base2 = base + 0x114;
    e->fn((char*)stream + e->delta, base2 + off, 0x160);
    e = &(*(sSerVEntry**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 8, 4);
}
#endif

//100%
INCLUDE_ASM("be/beintmission", func_00154898);
#ifdef SKIP_ASM
extern char D_004A6CAC[];

extern "C" void func_00154898(void* self, void* stream)
{
    int c = cBELibrary_getCharacterID(0);
    char* base = D_004A6CAC;
    int off = c * 0xF88;
    sSerVEntry* e = &(*(sSerVEntry**)stream)[2];
    e->fn((char*)stream + e->delta, base + off, 0x114);
    e = &(*(sSerVEntry**)stream)[2];
    char* base2 = base + 0x114;
    e->fn((char*)stream + e->delta, base2 + off, 0x160);
    e = &(*(sSerVEntry**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 8, 4);
}
#endif

