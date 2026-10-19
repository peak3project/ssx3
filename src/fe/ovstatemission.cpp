#include "common.h"

//100%
INCLUDE_ASM("fe/ovstatemission", cFEStateMPCircuit_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIScreen_playFrame(void* self, unsigned short frame, int flag);
// PORT: func_001A34A0__FPv is called with (self, obj) here; bind the 2-arg form to that symbol.
void func_001A34A0_2(void* self, void* obj) __asm__("func_001A34A0__FPv");
extern char D_004613C8[];
extern char D_004A19E8[];

extern "C" void cFEStateMPCircuit_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004613C8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A19E8));
    if (obj != 0) {
        *(int*)((char*)obj + 0x14) = (*(int*)((char*)obj + 0x14) & ~1) | 0x80;
        func_001A34A0_2(self, obj);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A3300__FPv);
#ifdef SKIP_ASM
void func_001A3300(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A3308);
#ifdef SKIP_ASM
struct cUIScreen;
int GetHashValue32(char* str);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" char* func_0039A708(void* self);
extern "C" void func_0039E4C0(void* self, int a1);
void func_001A34A8(void* self);
extern char D_004A19E8[];

extern "C" void func_001A3308(void* self, int a1)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A19E8));
    if (obj != 0) {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(func_0039A708(obj)));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
    }
    func_001A34A8(self);
    func_0039E4C0(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A33A0);
#ifdef SKIP_ASM
struct cUIScreen;
int GetHashValue32(char* str);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" char* func_0039A708(void* self);
extern "C" void func_0039F400(void* list, void* item);
void func_001A34A8(void* self);

struct sVEntry_33A0 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

extern "C" void func_001A33A0(void* self, void* item, unsigned int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry_33A0* vt = *(sVEntry_33A0**)((char*)obj + 4);
        void* r = vt[4].fn((char*)obj + vt[4].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    case 6: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry_33A0* vt = *(sVEntry_33A0**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    case 9: {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(func_0039A708(item)));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
        func_001A34A8(self);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A34A0__FPv);
#ifdef SKIP_ASM
void func_001A34A0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A34A8__FPv);
#ifdef SKIP_ASM
void func_001A34A8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A34B0);
#ifdef SKIP_ASM
extern "C" int func_001A34B0(void) {
    return -1;
}
#endif
//100%
INCLUDE_ASM("fe/ovstatemission", func_001A34B8);
#ifdef SKIP_ASM
extern "C" int cBENewPlayerInterface_isPeakLocked1(void*, int, int);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146E98(void*, int);

extern "C" unsigned int func_001A34B8(void)
{
    signed char i;
    unsigned char best = 0;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    for (i = 0; i < 2; i++) {
        int h = func_00146E98(iface, i != 0);
        unsigned char cnt = 0;
        signed char j;
        for (j = 1; j < 3; j++) {
            cnt += cBENewPlayerInterface_isPeakLocked1(iface, h, j);
        }
        if (best < cnt) {
            best = cnt;
        }
    }
    return best;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A3590);
#ifdef SKIP_ASM
extern "C" int BXFILE_exists(char* name);
extern "C" void func_003DED50(char* name, int a1, int a2, void* out);
extern char D_00461418[];

extern "C" void* func_001A3590(void* self)
{
    if (BXFILE_exists(D_00461418) != 0) {
        func_003DED50(D_00461418, 0, 0x64, (char*)self + 0x58C);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A35E8);
#ifdef SKIP_ASM
extern "C" int BXFILE_exists(char* name);
extern "C" void func_003DEDC0(void* handle, int arg);
void operator_delete(int* p);
extern char D_00461418[];

extern "C" void func_001A35E8(void* self, int flags)
{
    if (BXFILE_exists(D_00461418) != 0) {
        func_003DEDC0(*(void**)((char*)self + 0x58C), 0x64);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstatemission", func_001A3648);
#ifdef SKIP_ASM
struct sMissionSlot {
    char name[0x100];
    int f100;
    int f104;
    int f108;
    int f10C;
    int f110;
    int f114;
    int f118;
};

extern unsigned char D_004A1408[];

extern "C" void func_001A3648(sMissionSlot* self)
{
    int i;
    for (i = 0; i < 5; i++) {
        unsigned char c = D_004A1408[0];
        self[i].f100 = 0;
        self[i].name[0] = c;
        self[i].f104 = -1;
        self[i].f108 = 1;
        self[i].f10C = 0;
        self[i].f110 = -1;
        self[i].f114 = 0;
        self[i].f118 = -1;
    }
}
#endif

INCLUDE_ASM("fe/ovstatemission", func_001A3698);

