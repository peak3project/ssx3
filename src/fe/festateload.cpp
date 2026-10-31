#include "common.h"

//100%
INCLUDE_ASM("fe/festateload", cFEStateEventSelect_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A14B0[];
extern char D_0045DC50[];
extern unsigned int D_004A2594;
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void cUITemplate_MAP_onCreateScreen(void* tmpl, void* screen, void* owner);

extern "C" void cFEStateEventSelect_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A14B0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    engine = *(void**)((char*)self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DC50), 0);
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    void* main = *(void**)((char*)self + 0x40);
    D_004A2594 = 0;
    cUITemplate_MAP_onCreateScreen((char*)self + 0x48, main, self);
}
#endif

extern "C" void* func_002009D0(void*);

//100%
INCLUDE_ASM("fe/festateload", func_00186708__FPv);
#ifdef SKIP_ASM
void* func_00186708(void* self)
{
    return func_002009D0((char*)self + 0x48);
}
#endif

extern "C" void* func_00200A70(void*);

//100%
INCLUDE_ASM("fe/festateload", func_00186728__FPv);
#ifdef SKIP_ASM
void* func_00186728(void* self)
{
    return func_00200A70((char*)self + 0x48);
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_00186748);
#ifdef SKIP_ASM
extern "C" void func_0039E4C0(void* self, int a1);
extern "C" void func_00200AC0(void* tmpl);

extern "C" void func_00186748(void* self, int a1)
{
    func_0039E4C0(self, a1);
    func_00200AC0((char*)self + 0x48);
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_00186778);
#ifdef SKIP_ASM
void func_0039E4A0(void* self);
extern "C" void func_00200AF0(void* tmpl);

extern "C" void func_00186778(void* self)
{
    func_0039E4A0(self);
    func_00200AF0((char*)self + 0x48);
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_001867A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* self, int hash);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" int func_002018A8(void* tmpl, void* obj, int msg);
extern "C" void* func_0039F190(void* list, int a1);
extern "C" void func_0039F400(void* list, void* item);
extern int D_004A1A70;

static inline int IsQuick1867A8() { return D_004A1A70 == 1; }
extern char D_0045DC60[];

class cMgr1867A8 {
public:
    int f0;
    // vptr at 0x4
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* v04(void* owner, int id);
    virtual void* v05(void* owner, int id);
};

class cFEVObj_1867A8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual int v24(int a, int b);
};

static inline void PlayIntro1867A8(void* self)
{
    int f = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_0045DC60));
    if (f != 0xFFFF) {
        cUIScreen_playFrame(*(void**)((char*)self + 0x40), f, 1);
    }
}

static inline void Opened1867A8(void* self, void* item)
{
    if (item != 0) {
        cFEVObj_1867A8* c = *(cFEVObj_1867A8**)(**(char***)((char*)self + 0x10) + 0x10);
        if (c != 0) {
            c->v24(1, 0);
        }
        PlayIntro1867A8(self);
        func_0039F400(*(char**)((char*)self + 0x10) + 0x18, item);
    }
}

extern "C" void func_001867A8(void* self, void* obj, int msg)
{
    if (msg == 5) {
        if (func_002018A8((char*)self + 0x48, obj, 5) == 1) {
            if (IsQuick1867A8()) {
                PlayIntro1867A8(self);
                func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
            } else {
                cMgr1867A8* m = **(cMgr1867A8***)((char*)self + 0x10);
                Opened1867A8(self, m->v04(self, *(int*)((char*)obj + 0x18)));
            }
        }
    } else if (msg == 6) {
        if (func_002018A8((char*)self + 0x48, obj, 6) == 1) {
            if (IsQuick1867A8()) {
                PlayIntro1867A8(self);
                func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
            } else {
                cMgr1867A8* m = **(cMgr1867A8***)((char*)self + 0x10);
                Opened1867A8(self, m->v05(self, *(int*)((char*)obj + 0x18)));
            }
        }
    } else {
        func_002018A8((char*)self + 0x48, obj, msg);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_00186950);
#ifdef SKIP_ASM
extern "C" int func_00202738(void* self, int a1, int a2);

extern "C" int func_00186950(void* self, int a1, int a2)
{
    if (func_00202738((char*)self + 0x48, a1, a2) != 0) {
        return 0x101;
    }
    return 0;
}
#endif

int func_00202768(void*);

//100%
INCLUDE_ASM("fe/festateload", func_00186978);
#ifdef SKIP_ASM
extern "C" void func_00186978(void* self)
{
    func_00202768((char*)self + 0x48);
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_00186998);
#ifdef SKIP_ASM
extern "C" void func_00202770(void* self, int a1);
// PORT: func_0039E508__FPv is called with (self, a1) here; bind the 2-arg form to that symbol.
void func_0039E508_2(void* self, int a1) __asm__("func_0039E508__FPv");

extern "C" void func_00186998(void* self, int a1)
{
    func_00202770((char*)self + 0x48, a1);
    func_0039E508_2(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_001869D8);
#ifdef SKIP_ASM
extern "C" void func_0039E510(void* self);
extern "C" void cUITemplate_MAP_onUpdate(void* tmpl);

extern "C" void func_001869D8(void* self)
{
    func_0039E510(self);
    cUITemplate_MAP_onUpdate((char*)self + 0x48);
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_00186A08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001D53B0(void* self, void* a1, int a2);
extern "C" void* func_00227F80(void* p);
extern void* D_004A28A8;
extern void* D_0046B570[];
// D_004A14B8 holds the active load state (the unit declares it as int elsewhere).
extern void* D_004A14B8_K186A08 __asm__("D_004A14B8");
extern int D_004A14B4;
extern int D_004A14BC;
extern "C" void func_00186F90();
extern "C" void func_00187148();
extern "C" void func_00187180();
extern "C" void func_00187230();
extern "C" void func_001871A8();
extern "C" void func_00186C98();
extern "C" void func_00186D60();
extern "C" bool func_00186F40();
extern "C" void func_00187360();

struct sFEStateLoadK186A08 {
    char pad_0x0[0x8];
    void** vtbl;        // 0x8
    int fC;             // 0xC
    char pad_0x10[0x19C - 0x10];
    int f19C;           // 0x19C
    char pad_0x1A0[0x204 - 0x1A0];
    int f204;           // 0x204
    char pad_0x208[0x22C - 0x208];
    int f22C;           // 0x22C
    int f230;           // 0x230
    int f234;           // 0x234
    int f238;           // 0x238
    int f23C;           // 0x23C
    int f240;           // 0x240
    int f244;           // 0x244
};

struct sMemCardK186A08 {
    char pad_0x0[0x38];
    void* cb38;         // 0x38
    void* cb3C;         // 0x3C
    char pad_0x40[0x8];
    void* cb48;         // 0x48
    char pad_0x4C[0x10];
    void* cb5C;         // 0x5C
    char pad_0x60[0x30];
    void* cb90;         // 0x90
    void* cb94;         // 0x94
    char pad_0x98[0xC];
    void* cbA4;         // 0xA4
    char pad_0xA8[0x4];
    void* cbAC;         // 0xAC
    void* cbB0;         // 0xB0
    char pad_0xB4[0x11C - 0xB4];
    int f11C;           // 0x11C
    int f120;           // 0x120
    int f124;           // 0x124
    int f128;           // 0x128
    int f12C;           // 0x12C
};

extern "C" sFEStateLoadK186A08* func_00186A08(sFEStateLoadK186A08* self, void* engine)
{
    func_001D53B0(self, engine, 2);
    int one = 1;
    self->vtbl = D_0046B570;
    D_004A14B8_K186A08 = self;
    D_004A14B4 = 0;
    D_004A14BC = 0;
    self->f204 = one;
    self->fC = one;
    self->f23C = one;
    self->f230 = 0;
    self->f234 = 0;
    self->f240 = 0;
    self->f244 = 0;
    self->f19C = 0x1A;
    self->f22C = -1;
    self->f238 = -1;
    sMemCardK186A08* mc = (sMemCardK186A08*)func_00227F80(D_004A28A8);
    mc->f12C = one;
    mc->f124 = one;
    mc->f120 = one;
    mc->cbA4 = (void*)func_00186F90;
    mc->cb38 = (void*)func_00187148;
    mc->cb94 = (void*)func_00187180;
    mc->cbAC = (void*)func_00187230;
    mc->cb90 = (void*)func_001871A8;
    mc->cb48 = (void*)func_00186C98;
    mc->cb3C = (void*)func_00186D60;
    mc->cbB0 = (void*)func_00186F40;
    mc->cb5C = (void*)func_00187360;
    mc->f128 = 0;
    mc->f11C = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_00186B18);
#ifdef SKIP_ASM
extern void* D_0046B570[];
extern int D_004A14B8;
extern "C" void func_001D5428(void* self, int flags);

extern "C" void func_00186B18(void* self, int flags)
{
    *(void***)((char*)self + 8) = D_0046B570;
    D_004A14B8 = 0;
    func_001D5428(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/festateload", func_00186B48__FPv);
#ifdef SKIP_ASM
int func_00186B48(void* self)
{
    return 0x100;
}
#endif

