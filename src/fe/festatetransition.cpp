#include "common.h"

//100%
INCLUDE_ASM("fe/festatetransition", cFEStateBackground_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern char D_0045FFD8[];

extern "C" void cFEStateBackground_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045FFD8), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetransition", cFEStateTransition_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern char D_0045FFE8[];
extern char D_0045FFF8[];

extern "C" void cFEStateTransition_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* engine2;
    *(void**)((char*)self + 0x48) = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045FFE8), 0);
    engine2 = *(void**)((char*)self + 0x10);
    *(void**)((char*)self + 0x4C) = cUIEngine_addScreenByHashName(engine2, self, GetHashValue32(D_0045FFF8), 0);
}
#endif

//100%
INCLUDE_ASM("fe/festatetransition", cFEStateTransition_onScreenEvent);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A1360[];
extern char D_004A17B8[];

extern "C" int cFEStateTransition_onScreenEvent(void* self, void* screen, int id)
{
    int h1 = GetHashValue32(D_004A1360);
    int h2 = GetHashValue32(D_004A17B8);
    if (id == h1) {
        *(int*)((char*)self + 0x1C) &= ~8;
        *(int*)((char*)screen + 0x54) &= ~0x40;
    } else if (id == h2) {
        *(int*)((char*)self + 0x1C) |= 8;
        *(int*)((char*)screen + 0x54) |= 0x40;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatetransition", func_001946A8);
#ifdef SKIP_ASM
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* func_0028B180();
extern "C" void func_00294F78(void*, int);

extern "C" int func_001946A8(void* self, int which)
{
    if (which == 0) {
        void* screen = *(void**)((char*)self + 0x48);
        if (screen != 0) {
            *(int*)((char*)screen + 0x54) |= 0x40;
            cUIScreen_playFrame(*(void**)((char*)self + 0x48), 0, 0);
            func_00294F78(func_0028B180(), 0xF);
        }
    } else if (which == 1) {
        void* screen = *(void**)((char*)self + 0x4C);
        if (screen != 0) {
            *(int*)((char*)screen + 0x54) |= 0x40;
            cUIScreen_playFrame(*(void**)((char*)self + 0x4C), 0, 0);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatetransition", func_00194738);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void *, int);
extern void* D_0046BAB8[];

extern "C" void* func_00194738(void* self, int a1)
{
    func_0039E2A0(self, a1);
    *(void***)((char*)self + 0x8) = D_0046BAB8;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0xC) = 0;
    return self;
}
#endif

