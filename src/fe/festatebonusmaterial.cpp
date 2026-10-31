#include "common.h"

//100%
INCLUDE_ASM("fe/festatebonusmaterial", cFEStateBonusMaterial_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00460168[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cFEStateBonusMaterial_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00460168), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebonusmaterial", func_00195540);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A14F8[];
extern char D_004A1500[];
extern char D_004A1508[];

extern "C" void func_00195540(void* self, void* menu)
{
    int h = *(int*)((char*)menu + 0x38);
    if (h == GetHashValue32(D_004A14F8)) {
        *(int*)((char*)menu + 0x18) = 0;
    }
    h = *(int*)((char*)menu + 0x38);
    if (h == GetHashValue32(D_004A1500)) {
        *(int*)((char*)menu + 0x18) = 1;
    }
    h = *(int*)((char*)menu + 0x38);
    if (h == GetHashValue32(D_004A1508)) {
        *(int*)((char*)menu + 0x18) = 2;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatebonusmaterial", func_001955B8);
#ifdef SKIP_ASM
// Key filter: keys 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001955B8(void* self, int a1, unsigned int key)
{
    int r = 0x101;
    if (key < 10) {
        if (key < 8) {
            r = 0x101;
        } else {
            return 0x100;
        }
    }
    return r;
}
#endif

extern "C" void func_0039E4C0(void* self);

//100%
INCLUDE_ASM("fe/festatebonusmaterial", func_001955E0__FPv);
#ifdef SKIP_ASM
void func_001955E0(void* self)
{
    func_0039E4C0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatebonusmaterial", func_00195600);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001D22F0(void* self, void* engine, void* owner, signed char idx);
extern "C" void func_001D2598(void* self, const char* a, const char* b);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern char D_004601D8[];
extern const char* D_00441128[];

struct sVEntryK195600 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

extern "C" void func_00195600(void* self, void* item, unsigned int event)
{
    if (item == 0)
        return;
    switch (event) {
    case 4:
        break;
    case 5: {
        void* p = func_001D22F0(cMemMan_alloc(0x280, D_004601D8, 0, 0), *(void**)((char*)self + 0x10), self,
                                *(signed char*)((char*)self + 0x44));
        func_001D2598(p, D_00441128[*(int*)((char*)item + 0x18)], 0);
        func_0039F290(*(char**)((char*)self + 0x10) + 0x18, p);
        break;
    }
    case 6: {
        char* o = **(char***)((char*)self + 0x10);
        sVEntryK195600* vt = *(sVEntryK195600**)(o + 4);
        void* r = vt[5].fn(o + vt[5].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0)
            func_0039F400(*(char**)((char*)self + 0x10) + 0x18, r);
        break;
    }
    }
}
#endif

