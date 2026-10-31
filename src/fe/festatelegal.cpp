#include "common.h"

//100%
INCLUDE_ASM("fe/festatelegal", cFEStateLegal_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0045DD10[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cFEStateLegal_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DD10), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    *(int*)((char*)self + 0x48) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatelegal", func_00187CB8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0045DC60[];
struct cUIScreen;
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0039E510(void* self);
extern "C" void* func_0039F190(void* list, int a1);

extern "C" void func_00187CB8(void* self)
{
    func_0039E510(self);
    if (++*(int*)((char*)self + 0x48) == 0xF0) {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_0045DC60));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
        func_0039F190((char*)*(void**)((char*)self + 0x10) + 0x18, 1);
    }
}
#endif

INCLUDE_ASM("fe/festatelegal", func_00187D38);

//100%
INCLUDE_ASM("fe/festatelegal", func_001887A0);
#ifdef SKIP_ASM
struct sFlowState_887A0 {
    signed char count;
    char* states;
};
// NOTE: placeholder for the object at $gp+0x1D90 (no symbol in the target)
extern sFlowState_887A0 D_004A4E80;
extern void* D_0046C7C0[];
extern "C" void* func_0039E2A0(void *, int);
extern "C" void func_001A0708(void* self, int a1, int a2);

extern "C" void* func_001887A0(void* self, int a1, int reset)
{
    func_0039E2A0(self, a1);
    *(int*)((char*)self + 0xC) = 0x18;
    *(void***)((char*)self + 0x8) = D_0046C7C0;
    if (reset != 0) {
        func_001A0708(&D_004A4E80, 0x18, 0);
    }
    return self;
}
#endif

