#include "common.h"

//100%
INCLUDE_ASM("fe/festateselectmp", cFEStateSelectMultiplayerMode_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern char D_004613B8[];

extern "C" void cFEStateSelectMultiplayerMode_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004613B8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateselectmp", func_001A30F8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A14F8[];
extern char D_004A1500[];

extern "C" void func_001A30F8(void* self, void* item)
{
    int id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_004A14F8)) {
        *(int*)((char*)item + 0x18) = 0;
    } else {
        int id2 = *(int*)((char*)item + 0x38);
        if (id2 == GetHashValue32(D_004A1500)) {
            *(int*)((char*)item + 0x18) = 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateselectmp", func_001A3160);
#ifdef SKIP_ASM
struct sVEntry001A3160 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};
extern "C" void func_0039F400(void* list, void* item);

extern "C" void func_001A3160(void* self, void* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry001A3160* vt = *(sVEntry001A3160**)((char*)obj + 4);
        void* r = vt[4].fn((char*)obj + vt[4].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    case 6: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry001A3160* vt = *(sVEntry001A3160**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateselectmp", func_001A3218);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void *, int);
extern void* D_00469178[];

extern "C" void* func_001A3218(void* self, int a1)
{
    func_0039E2A0(self, a1);
    *(void***)((char*)self + 0x8) = D_00469178;
    *(int*)((char*)self + 0xC) = 0x17;
    return self;
}
#endif

