#include "common.h"

extern int D_005305B0[];

struct sCharEntry {
    char pad_0x00[0x11];
    signed char mCharID; // 0x11
    char pad_0x12[0x1C - 0x11 - 1];
};
extern sCharEntry D_00535B20[];

//100%
INCLUDE_ASM("be/belibrary", cBELibrary_getCharacterID__Fi);
#ifdef SKIP_ASM
signed char cBELibrary_getCharacterID(int index)
{
    int charID = D_005305B0[index];
    sCharEntry* entry = &D_00535B20[charID];
    return entry->mCharID;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014A0B0);
#ifdef SKIP_ASM
extern "C" signed char func_0014A0B0(int index)
{
    int charID = D_005305B0[index];
    signed char* entry = (signed char*)((char*)D_00535B20 + charID * 0x1C);
    return entry[0x12];
}
#endif

struct sCharEntry2 {
    char pad_0x00[0xC];
    int field_0xC;
    int field_0x10;
};

//100%
INCLUDE_ASM("be/belibrary", cBELibrary_getProfileIndex__Fi);
#ifdef SKIP_ASM
int cBELibrary_getProfileIndex(int index)
{
    int charID = D_005305B0[index];
    sCharEntry2* entry = (sCharEntry2*)((char*)D_00535B20 + charID * 0x1C);
    if (entry->field_0xC == -1) {
        return 2;
    }
    return entry->field_0x10 & 1;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", cBELibrary_getRiderIndex__Fi);
#ifdef SKIP_ASM
int cBELibrary_getRiderIndex(int flag)
{
    int* base = D_005305B0;
    int count = 0;
    while (1) {
        int charID = *base;
        sCharEntry2* entry = (sCharEntry2*)((char*)D_00535B20 + charID * 0x1C);
        int bit = entry->field_0x10 & 1;
        if (bit == flag) {
            return count;
        }
        count++;
        if (count < 6) {
            base++;
            continue;
        }
        return -1;
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014A180);
#ifdef SKIP_ASM
extern "C" void func_0014A180(void) {

}
#endif

INCLUDE_ASM("be/belibrary", func_0014A188);

INCLUDE_ASM("be/belibrary", func_0014A5E0);

//100%
INCLUDE_ASM("be/belibrary", func_0014AB20);
#ifdef SKIP_ASM
struct sScoreTable_0014AB20 {
    char data[0x64];
};
extern sScoreTable_0014AB20 D_00535C18[];
extern "C" int cBELibrary_getScoreType(int a, int b);

extern "C" void* func_0014AB20(int a, int b)
{
    int type = cBELibrary_getScoreType(a, b);
    if (type == 26) {
        return 0;
    }
    return &D_00535C18[type];
}
#endif

//100%
INCLUDE_ASM("be/belibrary", cBELibrary_getScoreType);
#ifdef SKIP_ASM
struct sScoreTypeMap {
    int key;
    int type;
};
extern sScoreTypeMap D_0045A2F8[][2];

extern "C" int cBELibrary_getScoreType(int a, int b)
{
    int i;
    if (a > 16) {
        return 26;
    }
    if ((unsigned)(b - 6) < 3) {
        return b - 6;
    }
    if ((unsigned)(b - 9) < 3) {
        return b - 6;
    }
    sScoreTypeMap* row = D_0045A2F8[a];
    for (i = 0; i < 2; i++) {
        if (row[i].key == b) {
            return row[i].type;
        }
    }
    return 26;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014ABE0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0045A408[];
extern void* D_0045AE88[16];
extern void* D_004A11C8;

struct cBELibraryInterface_0014ABE0 {
    char pad_0x00[8];
    int field_0x8;
    void* vtable;
};

extern "C" void* func_0014ABE0(void)
{
    if (D_004A11C8 == 0) {
        cBELibraryInterface_0014ABE0* mem = (cBELibraryInterface_0014ABE0*)cMemMan_alloc(0x10, D_0045A408, 0, 0);
        mem->field_0x8 = 0;
        mem->vtable = D_0045AE88;
        D_004A11C8 = mem;
    }
    return D_004A11C8;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014AC30);
#ifdef SKIP_ASM
extern "C" signed char func_0014AC30(int a0)
{
    return cBELibrary_getCharacterID(a0);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014AC50);
#ifdef SKIP_ASM
extern "C" int func_0014AC50(int a0)
{
    return cBELibrary_getProfileIndex(a0);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014AC70);
#ifdef SKIP_ASM
extern "C" int func_0014AC70(void* self, int rider, int* outChar)
{
    *outChar = cBELibrary_getCharacterID(rider);
    return cBELibrary_getProfileIndex(rider);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014ACB0);
#ifdef SKIP_ASM
extern int D_004A6CA8[];
extern "C" void* func_003E6574(void* dst, void* src, int n);

extern "C" void func_0014ACB0(void* self, int a1, int a2, void* src)
{
    char* p = (char*)D_004A6CA8 + a1 * 0x9b50 + a2 * 0xf88;
    func_003E6574(p + 0x290, src, 0x834);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014ACF8);
#ifdef SKIP_ASM
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" void func_00151A88(void*, int);

extern "C" void func_0014ACF8(void* self, int a1, int a2)
{
    func_00151A88(func_0014AD28(self, a1, a2), a2);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014AD28);
#ifdef SKIP_ASM
extern int D_004A6CA8[];

extern "C" void* func_0014AD28(void* self, int a1, int a2)
{
    return (char*)D_004A6CA8 + a1 * 0x9b50 + a2 * 0xf88;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/belibrary", func_0014AD50);
#ifdef SKIP_ASM
extern "C" void* func_0014AD50(void* self, int rider)
{
    int profile = func_0014AC50(rider);
    return func_0014AD28(self, profile, func_0014AC30(rider));
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014ADA8);
#ifdef SKIP_ASM
extern "C" void* func_0014ADA8(void* self, int a1, int a2, int a3)
{
    int off = a1 * 0x9b50 + a2 * 0xf88;
    char* p = (char*)D_004A6CA8 + off;
    return p + (a3 * 4 + 0x290);
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014ADD8);
#ifdef SKIP_ASM
extern "C" int func_0014AC70(void* self, int rider, int* outChar);
extern "C" void* func_0014ADA8(void* self, int a1, int a2, int a3);

extern "C" void* func_0014ADD8(void* self, int rider, int a2)
{
    int ch = 0;
    int profile = func_0014AC70(self, rider, &ch);
    return func_0014ADA8(self, profile, ch, a2);
}
#endif

INCLUDE_ASM("be/belibrary", func_0014AE28);
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/belibrary", func_0014AE60);
#ifdef SKIP_ASM
extern "C" int func_0014AC70(void* self, int rider, int* outChar);
extern "C" void* func_0014AE28(void* self, int a1, int a2, int* out);

extern "C" void* func_0014AE60(void* self, int rider, int* out)
{
    int ch;
    int profile = func_0014AC70(self, rider, &ch);
    return func_0014AE28(self, profile, ch, out);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014AEA8);
#ifdef SKIP_ASM
extern int D_004A6CA8[];

struct sBEFlagEntry {
    unsigned short field_0x0;
    short flags;
};

extern "C" void func_0014AEA8(void* self, int a1, int a2)
{
    char* p = (char*)D_004A6CA8 + a1 * 0x9b50 + a2 * 0xf88;
    int count = *(int*)(p + 0x28C);
    sBEFlagEntry* e = (sBEFlagEntry*)(p + 0x290);
    int i;
    for (i = 0; i < count; i++, e++) {
        if (e->flags & 0x10) {
            e->flags |= 4;
        } else {
            e->flags &= ~4;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014AF10);
#ifdef SKIP_ASM
extern int D_004A6CA8[];

extern "C" void func_0014AF10(void)
{
    int a;
    int b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 10; b++) {
            char* p = (char*)D_004A6CA8 + a * 0x9b50 + b * 0xf88;
            int count = *(int*)(p + 0x28C);
            sBEFlagEntry* e = (sBEFlagEntry*)(p + 0x290);
            int i;
            for (i = 0; i < count; i++, e++) {
                if (e->flags & 4) {
                    e->flags |= 0x10;
                } else {
                    e->flags &= ~0x10;
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014AFB0);
#ifdef SKIP_ASM
extern int D_004A6CA8[];
extern "C" int func_00151C90(void* prof, int idx, int on);
extern "C" int func_001521F0(void* prof);
extern "C" int func_001520E8(void* prof, int* out);

struct sFlagEntry_14AFB0
{
    short id;
    unsigned short flags;
    sFlagEntry_14AFB0() : id(-1), flags(0) {}
};

struct sProfile_14AFB0
{
    char pad[0x288];
    short* index;
    int count;
    sFlagEntry_14AFB0 entries[0x20D];
};

static inline sFlagEntry_14AFB0* getEntry_14AFB0(sProfile_14AFB0* p, int idx)
{
    short k = p->index[idx];
    if (k >= 0)
        return &p->entries[k];
    return 0;
}

extern "C" int func_0014AFB0(void* self, int a, int b, int idx, int on)
{
    sProfile_14AFB0* p = (sProfile_14AFB0*)((char*)D_004A6CA8 + a * 0x9b50 + b * 0xf88);
    sFlagEntry_14AFB0 save[0x20D];

    func_003E6574(save, p->entries, 0x834);
    if (func_00151C90(p, idx, on)) {
        sFlagEntry_14AFB0* e = getEntry_14AFB0(p, idx);
        if (on)
            e->flags |= 0x10;
        else
            e->flags &= ~0x10;
        if (func_001521F0(p)) {
            int n = 0;
            if (func_001520E8(p, &n)) {
                if (n == 0 || func_001521F0(p))
                    return 1;
            }
        }
    }
    func_003E6574(p->entries, save, 0x834);
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014B0F0);
#ifdef SKIP_ASM
extern "C" void func_0014B0F0(void* self, int a, int b, int idx)
{
    sProfile_14AFB0* p = (sProfile_14AFB0*)((char*)D_004A6CA8 + a * 0x9b50 + b * 0xf88);
    sFlagEntry_14AFB0* e = getEntry_14AFB0(p, idx);
    int on = 1;
    if (e->flags & 0x10) on = 0;
    func_0014AFB0(self, a, b, idx, on);
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014B170);
#ifdef SKIP_ASM
extern "C" void func_00152368(void*, int, int);

extern "C" void func_0014B170(void* self, int a1, int a2, int a3, int a4)
{
    func_00152368((char*)D_004A6CA8 + a1 * 0x9b50 + a2 * 0xf88, a3, a4);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/belibrary", func_0014B1B0);
#ifdef SKIP_ASM
extern "C" int func_0014AC70(void* self, int rider, int* outChar);
extern "C" void func_00152368(void*, int, int);

extern "C" void func_0014B1B0(void* self, int rider, int b, int c)
{
    int ch = 0;
    int profile = func_0014AC70(self, rider, &ch);
    func_00152368((char*)D_004A6CA8 + profile * 0x9b50 + ch * 0xf88, b, c);
}
#endif

INCLUDE_ASM("be/belibrary", func_0014B218);

INCLUDE_ASM("be/belibrary", func_0014B290);
//100%
INCLUDE_ASM("be/belibrary", func_0014B2F8);
#ifdef SKIP_ASM
extern void* D_004A6750[];
struct sBELibTables;
int func_0014D988(void* self, int i);
extern "C" void* func_0014D998(sBELibTables* self, int i);

struct sBEEntry38_B2F8 {
    char pad_0x00;
    signed char used; // 0x1
    char pad_0x02[0x36];
};

extern "C" int func_0014B2F8(void* self, int a)
{
    int count = func_0014D988(D_004A6750, a);
    sBEEntry38_B2F8* e = (sBEEntry38_B2F8*)func_0014D998((sBELibTables*)D_004A6750, a);
    int n = 0;
    int i;
    for (i = 0; i < count; i++, e++) {
        if (e->used == 0)
            n++;
    }
    return n;
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014B378);
#ifdef SKIP_ASM
extern void* D_004A6750[];
struct sBELibTables;
int func_0014D988(void* self, int i);
extern "C" void* func_0014D998(sBELibTables* self, int i);

struct sBEEntry38_B378 {
    char pad_0x00;
    signed char used; // 0x1
    char pad_0x02[0x36];
};

extern "C" int func_0014B378(void* self, int a, sBEEntry38_B378* out)
{
    int count = func_0014D988(D_004A6750, a);
    sBEEntry38_B378* e = (sBEEntry38_B378*)func_0014D998((sBELibTables*)D_004A6750, a);
    int n = 0;
    int i;
    for (i = 0; i < count; i++, e++) {
        if (e->used == 0) {
            *out++ = *e;
            n++;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014B478);
#ifdef SKIP_ASM
extern int D_004A6CA8[];
extern void* D_004A6750[];
struct sBELibTables;
int func_0014D988(void* self, int i);
extern "C" void* func_0014D998(sBELibTables* self, int i);

struct sBEFlagEntryB {
    unsigned short field_0x0;
    unsigned short flags;
};

struct sBEEntry38B {
    signed char group; // 0x0
    char pad_0x01[3];
    short field_0x4;
    short field_0x6;
    char pad_0x08[4];
    short field_0xC;
    char pad_0x0E[0x2A];
};

extern "C" int func_0014B478(void* self, int a1, int a2)
{
    char* p = (char*)D_004A6CA8 + a1 * 0x9b50 + a2 * 0xf88;
    int sum = 0;
    int count = func_0014D988(D_004A6750, a2);
    sBEEntry38B* e = (sBEEntry38B*)func_0014D998((sBELibTables*)D_004A6750, a2);
    int i;
    for (i = 0; i < count; i++, e++) {
        short s = (*(short**)(p + 0x288))[e->field_0x4];
        sBEFlagEntryB* f;
        if (s >= 0)
            f = (sBEFlagEntryB*)(p + 0x290) + s;
        else
            f = 0;
        if (f->flags & 0x10)
            sum += e->field_0xC;
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014B560);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_0014BDB8__FPv ignores its argument; callers pass none.
void* func_0014BDB8_0() __asm__("func_0014BDB8__FPv");
struct sBEGroupTable;
extern "C" int func_0014D448(sBEGroupTable* self, int g, int key);
extern "C" void func_00151C48(void* prof, int idx, int on);
extern "C" void func_00150B48(void* iface, int a, int b, int v);
extern "C" void func_00150928(void* iface, int a, int b);

struct sBEEntry38_14B560 {
    signed char group;  // 0x0
    char pad_0x01[3];
    short field_0x4;
    short field_0x6;
    char pad_0x08[6];
    short field_0xE;
    char pad_0x10[0x28];
};
struct sBETbl_14B560 {
    char pad_0x00[4];
    sBEEntry38_14B560* entries;   // 0x4
};

static inline sBEEntry38_14B560* entry_14B560(sBETbl_14B560* t, int i)
{
    if (i < 0)
        return 0;
    return &t->entries[i];
}

static inline int scale10_14B560(int v)
{
    if (v > 0) v *= 10;
    return v;
}

extern "C" void func_0014B560(void* self, int a1, int a2, int key, int flag)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0xB);
    char* p = (char*)D_004A6CA8 + a1 * 0x9b50 + a2 * 0xf88;
    func_00151C48(p, key, 1);
    sBEEntry38_14B560* e = (sBEEntry38_14B560*)func_0014D998((sBELibTables*)func_0014BDB8_0(), a2);
    int n = func_0014D988(func_0014BDB8_0(), a2);
    for (int j = 0; j < n; j++, e++) {
        if (scale10_14B560(e->field_0xE) == -key) {
            func_00151C48(p, e->field_0x4, 1);
        }
    }
    sBETbl_14B560* tbl = (sBETbl_14B560*)func_0014BDB8_0();
    e = entry_14B560(tbl, func_0014D448((sBEGroupTable*)tbl, a2, key));
    if (flag) {
        func_00150B48(iface, a1, a2, scale10_14B560(e->field_0xE));
    } else {
        func_00150928(iface, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014B700);
#ifdef SKIP_ASM
extern char D_0045A418[];
extern char D_0045A440[];
extern char D_0045A468[];
extern char D_0045A498[];
extern char D_0045A4C0[];
extern char D_0045A4E8[];
extern char D_0045A518[];
extern char D_0045A540[];
extern char D_0045A568[];
extern char D_0045A590[];
extern "C" char* func_0014B700(void* self, unsigned int x)
{
    switch (x) {
    case 0: return D_0045A418;
    case 1: return D_0045A440;
    case 2: return D_0045A468;
    case 3: return D_0045A498;
    case 4: return D_0045A4C0;
    case 5: return D_0045A4E8;
    case 6: return D_0045A518;
    case 7: return D_0045A540;
    case 8: return D_0045A568;
    case 9: return D_0045A590;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014B7A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0014B988_B7A8(void* self, int profile, int ch, void* e, void* out) __asm__("func_0014B988");
extern "C" int func_004165A8(void* a, void* b);

struct sBEEntry38_B7A8 {
    char pad_0x00[4];
    short slot;         // 0x4
    char pad_0x06[0x26];
    int active;         // 0x2C
    char pad_0x30[8];
};

extern "C" int func_0014B7A8(void* self, int profile, int ch, char* out)
{
    int cnt = 0;
    void* tables = func_0014BDB8_0();
    sProfile_14AFB0* prof = (sProfile_14AFB0*)func_0014AD28(self, profile, ch);
    sBEEntry38_B7A8* e = (sBEEntry38_B7A8*)func_0014D998((sBELibTables*)tables, ch);
    int n = func_0014D988(tables, ch);
    int i;
    for (i = 0; i < n; i++, e++) {
        if (e->active != 0) {
            sFlagEntry_14AFB0* f = getEntry_14AFB0(prof, e->slot);
            if (f->flags & 0x10) {
                char* dst = out + (cnt << 8);
                if (func_0014B988_B7A8(self, profile, ch, e, dst)) {
                    int prev = cnt - 1;
                    int k;
                    for (k = prev; k >= 0; k--) {
                        if (func_004165A8(dst, out + (k << 8)) == 0) {
                            cnt = prev;
                            break;
                        }
                    }
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014B920);
#ifdef SKIP_ASM
extern "C" int func_0014B7A8(void* self, int profile, int ch, char* out);

extern "C" int func_0014B920(void* self, int rider, char* out)
{
    int profile = func_0014AC50(rider);
    return func_0014B7A8(self, profile, func_0014AC30(rider), out);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014B988);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" char* strcpy(char* dst, const char* src);
extern "C" char* strchr(const char* s, int c);

struct sBEEntry38_14B988 {
    char pad_0x00[3];
    signed char group;  // 0x3
    short key;          // 0x4
    char pad_0x06[0x26];
    char* name;         // 0x2C
    char pad_0x30[8];
};

extern "C" int func_0014B988(void* self, int a, int b, sBEEntry38_14B988* e0, char* out)
{
    signed char grp = e0->group;
    if (grp == -1 || e0->name == 0) {
        *out = 0;
        return 0;
    }
    sBELibTables* tbl = (sBELibTables*)D_004A6750;
    sProfile_14AFB0* prof = (sProfile_14AFB0*)func_0014AD28(cBE_getInterface_Fv(cBE_getBE(), 9), a, b);
    strcpy(out, e0->name);
    char* d = strchr(out, '$');
    if (d == 0) return 1;
    int n = func_0014D988(tbl, b);
    sBEEntry38_14B988* e = (sBEEntry38_14B988*)func_0014D998(tbl, b);
    for (int i = 0; i < n; i++, e++) {
        if (e->group != grp) continue;
        char* s = e->name;
        if (s == 0) continue;
        if (e->key == e0->key) continue;
        if (!(getEntry_14AFB0(prof, e->key)->flags & 0x10)) continue;
        char* p = d;
        int k = d - out;
        while (*p != 0 && *p != '.') {
            if (s[k] != '$' && *p == '$') *p = s[k];
            p++;
            k++;
        }
        while (*d != 0 && *d != '$' && *d != '.') d++;
        if (*d != '$') return 1;
    }
    return 1;
}
#endif

extern void* D_004A6750[];
extern "C" void* func_0014C6A0(void*);

//100%
INCLUDE_ASM("be/belibrary", func_0014BBA0);
#ifdef SKIP_ASM
extern "C" int func_0014BBA0(void* self, int rider, sBEEntry38_14B988* e, char* out)
{
    int profile = func_0014AC50(rider);
    return func_0014B988(self, profile, func_0014AC30(rider), e, out);
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014BC18);
#ifdef SKIP_ASM
extern "C" int func_004165A8(void* a, void* b);
extern "C" char* strcpy(char* dst, const char* src);

struct sBEEntry38_BC18 {
    char pad_0x00[4];
    short slot;         // 0x4
    char pad_0x06[0x22];
    char* name;         // 0x28
    char pad_0x2C[0xC];
};

extern "C" int func_0014BC18(void* self, int profile, int ch, char* out)
{
    int cnt = 0;
    void* tables = func_0014BDB8_0();
    sProfile_14AFB0* prof = (sProfile_14AFB0*)func_0014AD28(self, profile, ch);
    int n = func_0014D988(tables, ch);
    sBEEntry38_BC18* e = (sBEEntry38_BC18*)func_0014D998((sBELibTables*)tables, ch);
    int i;
    for (i = 0; i < n; i++, e++) {
        char* name = e->name;
        if (name != 0) {
            sFlagEntry_14AFB0* f = getEntry_14AFB0(prof, e->slot);
            if (f->flags & 0x10) {
                int k;
                for (k = cnt - 1; k >= 0; k--) {
                    if (func_004165A8(name, out + (k << 8)) == 0)
                        break;
                }
                if (k < 0) {
                    strcpy(out + (cnt << 8), name);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014BD78__FPv);
#ifdef SKIP_ASM
void* func_0014BD78(void* self)
{
    return func_0014C6A0((void*)D_004A6750);
}
#endif

extern "C" void* func_0014D068(void*);

//100%
INCLUDE_ASM("be/belibrary", func_0014BD98__FPv);
#ifdef SKIP_ASM
void* func_0014BD98(void* self)
{
    return func_0014D068((void*)D_004A6750);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014BDB8__FPv);
#ifdef SKIP_ASM
void* func_0014BDB8(void* self)
{
    return (void*)D_004A6750;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014BDC8);
#ifdef SKIP_ASM
extern "C" void func_0014C548(void **, int, int, int);

extern "C" void func_0014BDC8(int arg0, int arg1, int arg2) {
    func_0014C548(D_004A6750, arg0, arg1, arg2);
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014BE00);
#ifdef SKIP_ASM
extern "C" void func_0014C590(void **, int, int, int);

extern "C" void func_0014BE00(int arg0, int arg1, int arg2) {
    func_0014C590(D_004A6750, arg0, arg1, arg2);
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014BE38);
#ifdef SKIP_ASM
extern "C" void func_0014C5D8(void **, int, int, int);

extern "C" void func_0014BE38(int arg0, int arg1, int arg2) {
    func_0014C5D8(D_004A6750, arg0, arg1, arg2);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014BE70);
#ifdef SKIP_ASM
extern "C" int func_00317F60(const char* name);
extern "C" int func_003E1BB8(const char* name, void* buf, int size);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char* D_004A11CC;
extern int D_004A11E8;
extern const char D_0045A600[];

struct sBEEnt_14BE70 {
    char pad0[0x14];
    char* name;         // 0x14
    char* sub[4];       // 0x18
    char* f28;          // 0x28
    char* f2C;          // 0x2C
    char* f30;          // 0x30
    int f34;
};
struct sBELib_14BE70 {
    char* buf;                  // 0x0
    sBEEnt_14BE70* entries;     // 0x4
    char* t8;                   // 0x8
    char* tC;                   // 0xC
    char* t10;                  // 0x10
    char* strings;              // 0x14
    int f18;
    int n0;                     // 0x1C
    int n1;                     // 0x20
    int n2;                     // 0x24
    int n3;                     // 0x28
};


extern "C" void func_0014BE70(void* vself)
{
    sBELib_14BE70* self = (sBELib_14BE70*)vself;
    int size = func_00317F60(D_004A11CC);
    char* buf = new (D_0045A600, 0, 0) char[size];
    self->buf = buf;
    func_003E1BB8(D_004A11CC, buf, size);
    char* d = self->buf;
    D_004A11E8 = *(int*)d;
    int n0 = *(int*)(d + 4);
    self->entries = (sBEEnt_14BE70*)(d + 8);
    self->n0 = n0;
    int off = 8 + n0 * 0x38;
    int n1 = *(int*)(d + off);
    off += 4;
    self->t8 = d + off;
    self->n1 = n1;
    off += n1 * 0xC;
    int n2 = *(int*)(d + off);
    off += 4;
    self->tC = d + off;
    self->n2 = n2;
    off += n2 * 8;
    int n3 = *(int*)(d + off);
    off += 4;
    self->t10 = d + off;
    self->n3 = n3;
    off += n3 * 8;
    off += 4;
    self->strings = d + off;
    if (D_004A11E8 & 1) D_004A11E8++;
    for (int i = 0; i < self->n0; i++) {
        if (self->entries[i].name) self->entries[i].name = self->strings + ((int)self->entries[i].name - 1);
        if (self->entries[i].f28) self->entries[i].f28 = self->strings + ((int)self->entries[i].f28 - 1);
        if (self->entries[i].f2C) self->entries[i].f2C = self->strings + ((int)self->entries[i].f2C - 1);
        if (self->entries[i].f30) self->entries[i].f30 = self->strings + ((int)self->entries[i].f30 - 1);
        for (int j = 0; j < 4; j++) {
            if (self->entries[i].sub[j]) self->entries[i].sub[j] = self->strings + ((int)self->entries[i].sub[j] - 1);
        }
    }
}
#endif

INCLUDE_ASM("be/belibrary", func_0014C068);

//100%
INCLUDE_ASM("be/belibrary", func_0014C2B0);
#ifdef SKIP_ASM
struct sBEEntry38 {
    signed char group; // 0x0
    char pad_0x01[3];
    short field_0x4;
    short field_0x6;
    char pad_0x08[0x30];
};

struct sBEGroupTable {
    char pad_0x00[4];
    sBEEntry38* entries; // 0x4
    char pad_0x08[0x14];
    int count; // 0x1C
    char pad_0x20[0xC];
    int groupCount[30]; // 0x2C
    int groupFirst[30]; // 0xA4
    short* lookup_0x11C[30]; // 0x11C
    char pad_0x194[0x4DC - 0x194];
    short* lookup_0x4DC[30]; // 0x4DC
};

extern "C" void func_0014C2B0(sBEGroupTable* self)
{
    int last = -1;
    int i;
    for (i = 0; i < self->count; i++) {
        int g = self->entries[i].group;
        self->groupCount[g]++;
        if (last != g) {
            last = g;
            self->groupFirst[g] = i;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014C320);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

struct sBEEntryC_G {
    signed char group; // 0x0
    char pad_0x01[0xB];
};

struct sBEKeyTableG {
    char pad_0x00[8];
    sBEEntryC_G* entries; // 0x8
    char pad_0x0C[0x14];
    int count; // 0x20
    char pad_0x24[0x20C - 0x24];
    int groupCount[30]; // 0x20C
    int groupFirst[30]; // 0x284
};

extern "C" void func_0014C320(sBEKeyTableG* self)
{
    int last = 30;
    int i;
    func_003E6448(self->groupCount, 0, sizeof(self->groupCount));
    for (i = 0; i < self->count; i++) {
        int g = self->entries[i].group;
        self->groupCount[g]++;
        if (last != g) {
            last = g;
            self->groupFirst[g] = i;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014C3C8);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

struct sBEEntry8G {
    signed char group; // 0x0
    char pad_0x01[7];
};

struct sBEKeyTableG1 {
    char pad_0x00[0xC];
    sBEEntry8G* entries; // 0xC
    char pad_0x10[0x14];
    int count; // 0x24
    char pad_0x28[0x2FC - 0x28];
    int groupCount[30]; // 0x2FC
    int groupFirst[30]; // 0x374
};

extern "C" void func_0014C3C8(sBEKeyTableG1* self)
{
    int last = -1;
    int i;
    func_003E6448(self->groupCount, 0, sizeof(self->groupCount));
    func_003E6448(self->groupFirst, 0, sizeof(self->groupFirst));
    for (i = 0; i < self->count; i++) {
        int g = self->entries[i].group;
        self->groupCount[g]++;
        if (last != g) {
            last = g;
            self->groupFirst[g] = i;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014C488);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

struct sBEEntry8G2 {
    signed char group; // 0x0
    char pad_0x01[7];
};

struct sBEKeyTableG2 {
    char pad_0x00[0x10];
    sBEEntry8G2* entries; // 0x10
    char pad_0x14[0x14];
    int count; // 0x28
    char pad_0x2C[0x3EC - 0x2C];
    int groupCount[30]; // 0x3EC
    int groupFirst[30]; // 0x464
};

extern "C" void func_0014C488(sBEKeyTableG2* self)
{
    int last = -1;
    int i;
    func_003E6448(self->groupCount, 0, sizeof(self->groupCount));
    func_003E6448(self->groupFirst, 0, sizeof(self->groupFirst));
    for (i = 0; i < self->count; i++) {
        int g = self->entries[i].group;
        self->groupCount[g]++;
        if (last != g) {
            last = g;
            self->groupFirst[g] = i;
        }
    }
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014C548);
#ifdef SKIP_ASM
extern "C" void func_0014C548(void** vself, int g, int key, int v)
{
    sBEGroupTable* self = (sBEGroupTable*)vself;
    *(char*)((char*)&self->entries[func_0014D448(self, g, key)] + 0x10) = v;
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014C590);
#ifdef SKIP_ASM
extern "C" void func_0014C590(void** vself, int g, int key, int v)
{
    sBEGroupTable* self = (sBEGroupTable*)vself;
    *(char*)((char*)&self->entries[func_0014D448(self, g, key)] + 0x1) = v;
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014C5D8);
#ifdef SKIP_ASM
extern "C" void func_0014C5D8(void** vself, int g, int key, int v)
{
    sBEGroupTable* self = (sBEGroupTable*)vself;
    *(short*)((char*)&self->entries[func_0014D448(self, g, key)] + 0xC) = v;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014C620);
#ifdef SKIP_ASM
extern "C" void* func_0014C620(void* self)
{
    int* p = (int*)self;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014C658);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_0014D240(void* self);

extern "C" void func_0014C658(int* self, int flags)
{
    func_0014D240(self);
    if (flags & 1)
    {
        operator_delete(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/belibrary", func_0014C6A0);
#ifdef SKIP_ASM
extern "C" void func_0014BE70(void* self);

extern "C" void* func_0014C6A0(void* self)
{
    if (*(int*)((char*)self + 0x10) == 0) {
        int none = *(int*)((char*)self + 4) == 0;
        func_0014D240(self);
        func_0014BE70(self);
        func_0014C2B0((sBEGroupTable*)self);
        func_0014C320((sBEKeyTableG*)self);
        func_0014C3C8((sBEKeyTableG1*)self);
        func_0014C488((sBEKeyTableG2*)self);
        if (!none) {
            int a;
            int b;
            for (a = 0; a < 3; a++) {
                for (b = 0; b < 10; b++) {
                    char* p = (char*)D_004A6CA8 + a * 0x9b50 + b * 0xf88;
                    int count = *(int*)(p + 0x28C);
                    sBEFlagEntry* e = (sBEFlagEntry*)(p + 0x290);
                    int i;
                    for (i = 0; i < count; i++, e++) {
                        if (e->flags & 4) {
                            e->flags |= 0x10;
                        } else {
                            e->flags &= ~0x10;
                        }
                    }
                }
            }
        }
    }
}
#endif

INCLUDE_ASM("be/belibrary", func_0014C7A0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/belibrary", func_0014D068);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0014C7A0(void* self);
int func_0014DC00(void* self, int i);
extern "C" void* func_0014DC10(sBELibTables* self, int i);

struct sBEReq_14D068 {
    char pad_0x0[4];
    short a;    // 0x4
    short b;    // 0x6
};

// The unit declares func_0014D068 as returning void*; the body returns nothing.
extern "C" void func_0014D068_impl(void* self) __asm__("func_0014D068");

extern "C" void func_0014D068_impl(void* self)
{
    int a;
    int b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 10; b++) {
            sBEReq_14D068* r = (sBEReq_14D068*)func_0014DC10((sBELibTables*)self, b);
            int n = func_0014DC00(self, b);
            sProfile_14AFB0* p = (sProfile_14AFB0*)((char*)D_004A6CA8 + a * 0x9b50 + b * 0xf88);
            int i;
            int count = p->count;
            sFlagEntry_14AFB0* e = p->entries;
            for (i = 0; i < count; i++, e++) {
                if (e->flags & 4)
                    e->flags |= 0x10;
            }
            for (i = 0; i < n; i++, r++) {
                e = getEntry_14AFB0(p, r->a);
                if (e->flags & 4) {
                    if (r->b >= 0)
                        getEntry_14AFB0(p, r->b)->flags |= 0x10;
                }
            }
            e = getEntry_14AFB0(p, 4);
            e->flags |= 0x10;
        }
    }
    func_0014C7A0(self);
    func_0014C2B0((sBEGroupTable*)self);
    func_0014C320((sBEKeyTableG*)self);
    func_0014C3C8((sBEKeyTableG1*)self);
    func_0014C488((sBEKeyTableG2*)self);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D240);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

struct sBELibData_14D240
{
    void* buf;          // 0x0
    int f4;             // 0x4
    int f8;             // 0x8
    int fC;             // 0xC
    int f10;            // 0x10
    int f14;            // 0x14
    void* buf2;         // 0x18
    int f1C;            // 0x1C
    int f20;            // 0x20
    int f24;            // 0x24
    int f28;            // 0x28
    int tab[11][30];    // 0x2C
};

extern "C" void func_0014D240(void* self)
{
    sBELibData_14D240* p = (sBELibData_14D240*)self;
    if (p->buf)
        cMemMan_free(p->buf);
    p->buf = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->fC = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
    p->f28 = 0;
    func_003E6448(p->tab[0], 0, sizeof(p->tab[0]));
    func_003E6448(p->tab[1], 0, sizeof(p->tab[1]));
    func_003E6448(p->tab[2], 0, sizeof(p->tab[2]));
    func_003E6448(p->tab[3], 0, sizeof(p->tab[3]));
    func_003E6448(p->tab[4], 0, sizeof(p->tab[4]));
    func_003E6448(p->tab[5], 0, sizeof(p->tab[5]));
    func_003E6448(p->tab[6], 0, sizeof(p->tab[6]));
    func_003E6448(p->tab[7], 0, sizeof(p->tab[7]));
    func_003E6448(p->tab[8], 0, sizeof(p->tab[8]));
    func_003E6448(p->tab[9], 0, sizeof(p->tab[9]));
    func_003E6448(p->tab[10], 0, sizeof(p->tab[10]));
    if (p->buf2)
        cMemMan_free(p->buf2);
    p->buf2 = 0;
}
#endif

INCLUDE_ASM("be/belibrary", func_0014D368);

//100%
INCLUDE_ASM("be/belibrary", func_0014D448);
#ifdef SKIP_ASM
extern "C" int func_0014D448(sBEGroupTable* self, int g, int key)
{
    short* lookup = self->lookup_0x4DC[g];
    if (lookup == 0) {
        int i = self->groupFirst[g];
        int end = i + self->groupCount[g];
        sBEEntry38* e = &self->entries[i];
        for (; i < end; i++, e++) {
            if (e->field_0x4 == key) {
                return i;
            }
        }
        return -1;
    }
    return lookup[key];
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D4C8);
#ifdef SKIP_ASM
extern "C" int func_0014D4C8(sBEGroupTable* self, int g, int key)
{
    short* lookup = self->lookup_0x11C[g];
    if (lookup == 0) {
        int n = 0;
        int i = self->groupFirst[g];
        int end = i + self->groupCount[g];
        sBEEntry38* e = &self->entries[i];
        for (; i < end; e++, i++) {
            if (e->field_0x6 == key) {
                n++;
            } else if (e->field_0x6 > key) {
                break;
            }
        }
        return n;
    }
    return lookup[key];
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D558);
#ifdef SKIP_ASM
extern "C" sBEEntry38* func_0014D558(sBEGroupTable* self, int g, int key)
{
    short* lookup;
    if (key == -1 || (lookup = *(short**)((char*)self + (g << 2) + 0x194)) == 0) {
        int i = self->groupFirst[g];
        int end = i + self->groupCount[g];
        sBEEntry38* e = &self->entries[i];
        for (; i < end; i++, e++) {
            if (e->field_0x6 == key) {
                return e;
            }
        }
        return 0;
    }
    if (self->lookup_0x11C[g][key] <= 0) {
        return 0;
    }
    return &self->entries[lookup[key]];
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D608);
#ifdef SKIP_ASM
extern "C" int func_0014D608(sBEGroupTable* self, int g, int key, sBEEntry38** out, int depth, int all)
{
    int count = 0;
    if (key == -1 || self->lookup_0x11C[g] == 0) {
        int i = self->groupFirst[g];
        int end = i + self->groupCount[g];
        sBEEntry38* e = &self->entries[i];
        for (; i < end; i++, e++) {
            if (e->field_0x6 == key) {
                *out++ = e;
                count++;
                if (depth != 0) {
                    if (!(*(int*)((char*)e + 0x34) & 0x20) || all) {
                        int r = func_0014D608(self, g, e->field_0x4, out, depth - 1, all);
                        count += r;
                        out += r;
                    }
                }
            } else if (key < e->field_0x6) {
                return count;
            }
        }
    } else {
        sBEEntry38* e = func_0014D558(self, g, key);
        int n = self->lookup_0x11C[g][key];
        for (int j = 0; j < n; j++, e++) {
            *out++ = e;
            count++;
            if (depth != 0) {
                if (!(*(int*)((char*)e + 0x34) & 0x20) || all) {
                    int r = func_0014D608(self, g, e->field_0x4, out, depth - 1, all);
                    count += r;
                    out += r;
                }
            }
        }
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D7E8);
#ifdef SKIP_ASM
struct sBENode_14D7E8
{
    signed char group;  // 0x0
    char pad_0x01[3];
    short child;        // 0x4
    short field_0x6;
    short parent;       // 0x8
    char pad_0x0A[0x2A];
    int flags;          // 0x34
};

struct sBENodeTable_14D7E8
{
    char pad_0x00[4];
    sBENode_14D7E8* entries; // 0x4
    char pad_0x08[0x24];
    int groupCount[30]; // 0x2C
    int groupFirst[30]; // 0xA4
};

extern "C" int func_0014D7E8(sBENodeTable_14D7E8* self, int g, int key, sBENode_14D7E8** out, int depth, int all)
{
    int n = 0;
    int i = self->groupFirst[g];
    int end = i + self->groupCount[g];
    sBENode_14D7E8* e = &self->entries[i];
    for (; i < end; i++, e++) {
        if (e->parent == key) {
            *out++ = e;
            n++;
            if (depth != 0 && (!(e->flags & 0x20) || all)) {
                int k = func_0014D7E8(self, g, e->child, out, depth - 1, all);
                n += k;
                out += k;
            }
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D908);
#ifdef SKIP_ASM
extern "C" int func_0014D908(sBEGroupTable* self, sBEEntry38* e, int key)
{
    if (e == 0)
        return 0;
    if (e->field_0x6 == key)
        return 1;
    if (e->field_0x6 == -1)
        return 0;
    int i = func_0014D448(self, e->group, e->field_0x6);
    sBEEntry38* parent;
    if (i < 0)
        parent = 0;
    else
        parent = &self->entries[i];
    return func_0014D908(self, parent, key);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D988__FPvi);
#ifdef SKIP_ASM
int func_0014D988(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0x2C);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D998);
#ifdef SKIP_ASM
struct sBELibTables {
    char pad_0x00[4];
    char* field_0x4;
    char pad_0x8[4];
    char* field_0xC;
    char* field_0x10;
    char pad_0x14[0x2C - 0x14];
    int count0[30]; // 0x2C
    int index0[30]; // 0xA4
    char pad_0x11C[0x2FC - 0x11C];
    int count1[30]; // 0x2FC
    int index1[30]; // 0x374
    int count2[30]; // 0x3EC
    int index2[30]; // 0x464
};

extern "C" void* func_0014D998(sBELibTables* self, int i)
{
    if (self->count0[i] <= 0) {
        return 0;
    }
    return self->field_0x4 + self->index0[i] * 0x38;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014D9D0);
#ifdef SKIP_ASM
extern "C" void* func_0014D9D0(sBELibTables* self, int i)
{
    if (self->count0[i] <= 0) {
        return 0;
    }
    return self->field_0x4 + self->index0[i] * 0x38;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014DA08);
#ifdef SKIP_ASM
extern "C" int func_0014DA08(int arg0, int arg1) {
    return (*(int *)(((char*)(arg0) + (arg1 << 2)) + (0xA4)));
}
#endif
//100%
INCLUDE_ASM("be/belibrary", func_0014DA18);
#ifdef SKIP_ASM
extern "C" int func_0014DA18(int arg0, int arg1) {
    return (*(int *)(((char*)(arg0) + (arg1 << 2)) + (0x20C)));
}
#endif

INCLUDE_ASM("be/belibrary", func_0014DA28);
//100%
INCLUDE_ASM("be/belibrary", func_0014DAA0);
#ifdef SKIP_ASM
extern "C" void* func_0014DAC0(void*, int, int, int*);

extern "C" void* func_0014DAA0(void* self, int a1, int a2)
{
    int count;
    return func_0014DAC0(self, a1, a2, &count);
}
#endif

INCLUDE_ASM("be/belibrary", func_0014DAC0);
//100%
INCLUDE_ASM("be/belibrary", func_0014DB40);
#ifdef SKIP_ASM
struct sBEEntryC {
    char field_0x0;
    signed char flag; // 0x1
    short key; // 0x2
    char pad_0x4[8];
};

struct sBEKeyTable {
    char pad_0x00[8];
    sBEEntryC* entries; // 0x8
    char pad_0x0C[0x20C - 0xC];
    int count[30]; // 0x20C
    int first[30]; // 0x284
};

extern "C" sBEEntryC* func_0014DB40(sBEKeyTable* self, int g, int key, int want, int* out)
{
    sBEEntryC* result;
    int i;
    *out = 0;
    if (self->count[g] <= 0) {
        return 0;
    }
    result = 0;
    for (i = self->first[g]; i < self->first[g] + self->count[g]; i++) {
        if (self->entries[i].key == key) {
            if ((self->entries[i].flag != 0) == want) {
                if (result == 0) {
                    result = &self->entries[i];
                }
                (*out)++;
            } else if (result != 0) {
                break;
            }
        } else if (key < self->entries[i].key) {
            break;
        }
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014DC00__FPvi);
#ifdef SKIP_ASM
int func_0014DC00(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0x2FC);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014DC10);
#ifdef SKIP_ASM
extern "C" void* func_0014DC10(sBELibTables* self, int i)
{
    if (self->count1[i] > 0) {
        return self->field_0xC + self->index1[i] * 8;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014DC40__FPvi);
#ifdef SKIP_ASM
int func_0014DC40(void* self, int i)
{
    return *(int*)((char*)self + (i << 2) + 0x3EC);
}
#endif

//100%
INCLUDE_ASM("be/belibrary", func_0014DC50);
#ifdef SKIP_ASM
extern "C" void* func_0014DC50(sBELibTables* self, int i)
{
    if (self->count2[i] > 0) {
        return self->field_0x10 + self->index2[i] * 8;
    }
    return 0;
}
#endif

