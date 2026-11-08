#include "common.h"

// Declarations shared by the functions of this unit.
struct cUIScreen;
int GetHashValue32(char* str);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

//100%
INCLUDE_ASM("fe/festatelegal", cFEStateLegal_onCreateScreen);
#ifdef SKIP_ASM
extern char D_0045DD10[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);

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
extern char D_0045DC60[];
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
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

//100%
INCLUDE_ASM("fe/festatelegal", func_00187D38);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void func_002C2868(char* s);
extern "C" int func_00158618(void* self, int a1, int a2, int bit, int give);
extern "C" int func_00150B88(void* self, int a, int b, int peak, int unlocked);
extern "C" int func_00158558(void* self, int a1, int a2, int bit, int give);
extern "C" void func_00158848(void* self, int a1, int a2, long value);
int func_00157350(void* self);
int func_001572B0(void* self);
int func_001572D0(void* self);
int func_001572F0(void* self);
int func_00157310(void* self);
int func_00157330(void* self);
extern "C" int func_00157FD0(void* self, int a1, int a2, int bit, int give);
extern "C" int func_001580F8(void* self, int a1, int a2, int bit, int give);
extern "C" int func_00158220(void* self, int a1, int a2, int bit, int give);
extern "C" int func_00158348(void* self, int a1, int a2, int bit, int give);
extern "C" int func_00158470(void* self, int a1, int a2, int bit, int give);

struct sLibEntry_7D38 {
    char pad0[2];
    signed char type;   // 0x2
    char pad3;
    short id;           // 0x4
    char pad6[0x38 - 6];

    int getType() { return type; }
};

// PORT: func_0014BDB8 is declared (void*) but never reads its argument; called here with none
void* func_0014BDB8_n() __asm__("func_0014BDB8__FPv");
extern "C" sLibEntry_7D38* func_0014D998(void* self, int i);
int func_0014D988(void* self, int i);
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" int func_0014D908(void* self, sLibEntry_7D38* e, int key);
extern "C" void func_00151C48(void* prof, int idx, int on);
extern int D_004A11E0;

extern "C" int func_00187D38(const char* code)
{
    void* reward = cBE_getInterface_Fv(cBE_getBE(), 0xB);
    void* career = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    void* lib = cBE_getInterface_Fv(cBE_getBE(), 9);
    char buf[128];
    strcpy(buf, code);
    func_002C2868(buf);
    if (GetHashValue32(buf) == 0x7E68D) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0xB, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x699649F) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0xD, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x80C4F45) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0xF, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xFA26044) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x11, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x539AB42) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0xA, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x61C8197) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x12, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x64694E5) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x13, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x3F22E2B) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x14, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xCD28689) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x15, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xB582D1C) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x16, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x1CB90E5) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x17, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x715E0E4) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x18, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xF3223E) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x19, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xEAFC69E) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x1B, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xDD36D88) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x1C, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xDE3475) {
        for (int i = 0; i < 10; i++) {
            func_00158618(career, 0, i, 0x1A, 0);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x82DE683) {
        for (int i = 0; i < 10; i++) {
            func_00150B88(reward, 0, i, 1, 1);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x4B1FF67) {
        for (int i = 0; i < 10; i++) {
            func_00150B88(reward, 0, i, 1, 1);
            func_00150B88(reward, 0, i, 2, 1);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x61F9F02) {
        int n = func_00157350(career);
        for (int r = 0; r < 10; r++) {
            long mask = 0;
            for (int b = 0; b < n; b++) {
                func_00158558(career, 0, r, b, 0);
                mask |= 1L << b;
            }
            func_00158848(career, 0, r, mask);
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x5B65653) {
        int n = func_001572B0(career);
        for (int r = 0; r < n; r++) {
            for (int i = 0; i < 10; i++) {
                func_00157FD0(career, 0, i, r, 0);
            }
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xA0CF7C4) {
        int n = func_001572D0(career);
        for (int r = 0; r < n; r++) {
            for (int i = 0; i < 10; i++) {
                func_001580F8(career, 0, i, r, 0);
            }
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xB5D8914) {
        int n = func_001572F0(career);
        for (int r = 0; r < n; r++) {
            for (int i = 0; i < 10; i++) {
                func_00158220(career, 0, i, r, 0);
            }
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x717257D) {
        int n = func_00157330(career);
        for (int r = 0; r < n; r++) {
            for (int i = 0; i < 10; i++) {
                func_00158470(career, 0, i, r, 0);
            }
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x74F6CF4) {
        int n = func_00157310(career);
        for (int r = 0; r < n; r++) {
            for (int i = 0; i < 10; i++) {
                func_00158348(career, 0, i, r, 0);
            }
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0xBCF3974) {
        for (int g = 0; g < 3; g++) {
            for (int k = 0; k < 10; k++) {
                void* tbl = func_0014BDB8_n();
                sLibEntry_7D38* e = func_0014D998(tbl, k);
                int cnt = func_0014D988(tbl, k);
                void* prof = func_0014AD28(lib, g, k);
                for (int j = 0; j < cnt; j++, e++) {
                    if (e->getType() == 1 || e->getType() == 2 || e->getType() == 3) {
                        if (func_0014D908(tbl, e, D_004A11E0)) {
                            func_00151C48(prof, e->id, 1);
                        }
                    }
                }
            }
        }
        return 1;
    }
    if (GetHashValue32(buf) == 0x70694D5) {
        for (int g = 0; g < 3; g++) {
            for (int k = 0; k < 10; k++) {
                sLibEntry_7D38* e = func_0014D998(func_0014BDB8_n(), k);
                int cnt = func_0014D988(func_0014BDB8_n(), k);
                void* prof = func_0014AD28(lib, g, k);
                for (int j = 0; j < cnt; j++, e++) {
                    if (e->getType() == 1) {
                        func_00151C48(prof, e->id, 1);
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}
#endif

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

