#include "common.h"

INCLUDE_ASM("main/debugmenu", cRenderTogglesMenu_cRenderTogglesMenu);

//100%
INCLUDE_ASM("main/debugmenu", cVisualEffectsTestMenu_cVisualEffectsTestMenu);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047FC88[];
extern char D_0047E038[];
extern char D_0047E058[];
extern char D_0047E070[];
extern char D_0047E088[];
extern char D_0047E098[];
extern char D_0047E0B0[];
extern char D_0047E0C0[];
extern char D_0047E0D0[];
extern char D_0047E0E0[];
extern char D_0047E100[];
extern char D_004A2CF0[];
extern char D_004A2CF8[];
extern char D_004A2D00[];
extern char D_004A2D08[];
extern char D_004A2D10[];
extern char D_004A2D18[];
extern char D_004A2D20[];
extern char D_004A2D28[];
extern int D_004A4478;
extern int D_004A447C;
extern int D_004A4480;
extern int D_004A4484;
extern int D_004A4488;
extern int D_004A448C;
extern int D_004A4490;
extern int D_004A4494;
extern int D_004A4498;
extern int D_004A449C;
extern int D_004A44A0;
extern int D_004A44A4;
extern int D_004A44A8;
extern int D_004A44AC;
extern int D_004A44B0;
extern int D_004A44B4;
extern int D_004A44B8;

extern "C" void* cVisualEffectsTestMenu_cVisualEffectsTestMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047FC88;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E038);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A4478, 0, 1, D_0047E058);
    cIntMenuItem_cIntMenuItem((char*)self + 0x194, 1, &D_004A447C, 0, 1, D_0047E070);
    cIntMenuItem_cIntMenuItem((char*)self + 0x1C4, 2, &D_004A4480, 0, 1, D_0047E088);
    cIntMenuItem_cIntMenuItem((char*)self + 0x1F4, 3, &D_004A4484, 0, 0x3e8, D_0047E098);
    cIntMenuItem_cIntMenuItem((char*)self + 0x224, 4, &D_004A4488, -640, 0x280, D_0047E0B0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x254, 5, &D_004A448C, -480, 0x1e0, D_0047E0C0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x284, 6, &D_004A4490, -640, 0x280, D_004A2CF0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x2B4, 7, &D_004A4494, -640, 0x280, D_004A2CF8);
    cIntMenuItem_cIntMenuItem((char*)self + 0x2E4, 8, &D_004A4498, -1, 0x3e8, D_004A2D00);
    cIntMenuItem_cIntMenuItem((char*)self + 0x314, 9, &D_004A449C, -1, 0x3e8, D_004A2D08);
    cIntMenuItem_cIntMenuItem((char*)self + 0x344, 0xa, &D_004A44A0, -255, 0xff, D_004A2D10);
    cIntMenuItem_cIntMenuItem((char*)self + 0x374, 0xb, &D_004A44A4, -255, 0xff, D_004A2D18);
    cIntMenuItem_cIntMenuItem((char*)self + 0x3A4, 0xc, &D_004A44A8, -255, 0xff, D_004A2D20);
    cIntMenuItem_cIntMenuItem((char*)self + 0x3D4, 0xd, &D_004A44AC, -255, 0xff, D_004A2D28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x404, 0xe, &D_004A44B0, -16, 0x10, D_0047E0D0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x434, 0xf, &D_004A44B4, 0, 1, D_0047E0E0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x464, 0x10, &D_004A44B8, 0, 0x64, D_0047E100);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C4, -1);
    cMenu_addItem(self, (char*)self + 0x1F4, -1);
    cMenu_addItem(self, (char*)self + 0x224, -1);
    cMenu_addItem(self, (char*)self + 0x254, -1);
    cMenu_addItem(self, (char*)self + 0x284, -1);
    cMenu_addItem(self, (char*)self + 0x2B4, -1);
    cMenu_addItem(self, (char*)self + 0x2E4, -1);
    cMenu_addItem(self, (char*)self + 0x314, -1);
    cMenu_addItem(self, (char*)self + 0x344, -1);
    cMenu_addItem(self, (char*)self + 0x374, -1);
    cMenu_addItem(self, (char*)self + 0x3A4, -1);
    cMenu_addItem(self, (char*)self + 0x3D4, -1);
    cMenu_addItem(self, (char*)self + 0x404, -1);
    cMenu_addItem(self, (char*)self + 0x434, -1);
    cMenu_addItem(self, (char*)self + 0x464, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cPlantsMenu_cPlantsMenu);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047FC30[];
extern char D_0047E118[];
extern char D_0047E128[];
extern char D_0047E138[];
extern char D_0047E148[];
extern char D_0047E160[];
extern char D_0047E178[];
extern char D_0047E188[];
extern char D_0047E1A8[];
extern char D_0047E1C0[];
extern char D_0047E1E0[];
extern char D_0047E200[];
extern char D_0047E210[];
extern char D_004A2D30[];
extern int D_004A4444;
extern float D_004A4448;
extern float D_004A444C;
extern float D_004A4450;
extern float D_004A4454;
extern float D_004A4458;
extern int D_004A445C;
extern float D_004A4460;
extern float D_004A4464;
extern float D_004A4468;
extern float D_004A446C;
extern float D_004A4470;

extern "C" void* cPlantsMenu_cPlantsMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047FC30;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E118);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A4444, 0, 2, D_004A2D30);
    cFloatMenuItem_ctor((char*)self + 0x194, 1, &D_004A4448, 0.0f, 2.0f, D_0047E128);
    cFloatMenuItem_ctor((char*)self + 0x1C8, 2, &D_004A444C, -5.0f, 5.0f, D_0047E138);
    cFloatMenuItem_ctor((char*)self + 0x1FC, 3, &D_004A4450, 0.0f, 2.0f, D_0047E148);
    cFloatMenuItem_ctor((char*)self + 0x230, 4, &D_004A4454, 0.0f, 2.0f, D_0047E160);
    cFloatMenuItem_ctor((char*)self + 0x264, 5, &D_004A4458, 0.0f, 1000.0f, D_0047E178);
    cIntMenuItem_cIntMenuItem((char*)self + 0x298, 6, &D_004A445C, 0, 0x1770, D_0047E188);
    cFloatMenuItem_ctor((char*)self + 0x2C8, 7, &D_004A4460, 0.0f, 6000.0f, D_0047E1A8);
    cFloatMenuItem_ctor((char*)self + 0x2FC, 8, &D_004A4464, 0.0f, 6000.0f, D_0047E1C0);
    cFloatMenuItem_ctor((char*)self + 0x330, 9, &D_004A4468, 0.0f, 6000.0f, D_0047E1E0);
    cFloatMenuItem_ctor((char*)self + 0x364, 0xa, &D_004A446C, 0.0f, 360.0f, D_0047E200);
    cFloatMenuItem_ctor((char*)self + 0x398, 0xb, &D_004A4470, 0.0f, 360.0f, D_0047E210);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C8, -1);
    cMenu_addItem(self, (char*)self + 0x1FC, -1);
    cMenu_addItem(self, (char*)self + 0x230, -1);
    cMenu_addItem(self, (char*)self + 0x264, -1);
    cMenu_addItem(self, (char*)self + 0x298, -1);
    cMenu_addItem(self, (char*)self + 0x2C8, -1);
    cMenu_addItem(self, (char*)self + 0x2FC, -1);
    cMenu_addItem(self, (char*)self + 0x330, -1);
    cMenu_addItem(self, (char*)self + 0x364, -1);
    cMenu_addItem(self, (char*)self + 0x398, -1);
    return self;
}
#endif

INCLUDE_ASM("main/debugmenu", cLightGlowMenu_cLightGlowMenu);

//100%
INCLUDE_ASM("main/debugmenu", cDepthFogMenu_cDepthFogMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
// PORT: the unit declares cFloatMenuItem_ctor(self, id, var, lo, hi, text); the real parameter order is
// (self, id, var, lo, hi, text) like cIntMenuItem (it decides the arg-move order and FP register allocation here).
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047FB80[];
extern char D_0047E460[];
extern char D_004A2D30[];
extern char D_0047E238[];
extern char D_0047E470[];
extern char D_0047E480[];
extern char D_0047E490[];
extern char D_004A2D48[];
extern char D_0047E4A0[];
extern char D_004A2D50[];
extern char D_00504720[];
extern int D_004A4324;
extern int D_004A4328;
extern float D_004A432C;
extern float D_004A4330;
extern int D_004A4334;
extern float D_004A4338;
extern float D_004A433C;

extern "C" void* cDepthFogMenu_cDepthFogMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047FB80;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E460);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A4324, 0, 1, D_004A2D30);
    cIntMenuItem_cIntMenuItem((char*)self + 0x194, 1, &D_004A4328, 0, 1, D_0047E238);
    cFloatMenuItem_ctor((char*)self + 0x1C4, 2, &D_004A432C, 1.0f, 100000.0f, D_0047E470);
    cFloatMenuItem_ctor((char*)self + 0x1F8, 3, &D_004A4330, 1.0f, 100000.0f, D_0047E480);
    cIntMenuItem_cIntMenuItem((char*)self + 0x22C, 4, &D_004A4334, 0, 2, D_0047E490);
    cFloatMenuItem_ctor((char*)self + 0x25C, 5, &D_004A4338, 0.0f, 100.0f, D_004A2D48);
    cFloatMenuItem_ctor((char*)self + 0x290, 6, &D_004A433C, 0.0f, 1.0f, D_0047E4A0);
    cARGBMenuItem_cARGBMenuItem((char*)self + 0x2C4, 7, D_004A2D50, D_00504720);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C4, -1);
    cMenu_addItem(self, (char*)self + 0x1F8, -1);
    cMenu_addItem(self, (char*)self + 0x22C, -1);
    cMenu_addItem(self, (char*)self + 0x25C, -1);
    cMenu_addItem(self, (char*)self + 0x290, -1);
    cMenu_addItem(self, (char*)self + 0x2C4, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cHeightFogMenu_cHeightFogMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
extern "C" void* cFloatMenuItem_cFloatMenuItem(void* self, int a1, void* var, void* text, float lo, float hi);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047FB28[];
extern char D_0047E4C0[];
extern char D_004A2D30[];
extern char D_0047E4D0[];
extern char D_0047E4E0[];
extern int D_004A43B4;
extern float D_004A43B8;
extern float D_004A43BC;

extern "C" void* cHeightFogMenu_cHeightFogMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047FB28;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E4C0);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A43B4, 0, 1, D_004A2D30);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x194, 1, &D_004A43B8, D_0047E4D0, -100000.0f, 100000.0f);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x1C8, 2, &D_004A43BC, D_0047E4E0, 9.999999747378752e-05f, 10000.0f);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C8, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cDetailSystemMenu_cDetailSystemMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
// PORT: the unit declares cFloatMenuItem_ctor(self, id, var, lo, hi, text); the real parameter order is
// (self, id, var, lo, hi, text) like cIntMenuItem (it decides the arg-move order and FP register allocation here).
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047FAD0[];
extern char D_0047E4F0[];
extern char D_0047E508[];
extern char D_0047E520[];
extern char D_0047E538[];
extern char D_0047E550[];
extern char D_0047E570[];
extern char D_0047E590[];
extern char D_0047E5A8[];
extern char D_0047E5C0[];
extern char D_0047E5D8[];
extern char D_004A2D30[];
extern int D_004A4340;
extern float D_004A4344;
extern float D_004A4348;
extern float D_004A434C;
extern float D_004A4350;
extern float D_004A4354;
extern float D_004A4358;
extern float D_004A435C;
extern float D_004A4360;
extern float D_004A4364;

extern "C" void* cDetailSystemMenu_cDetailSystemMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047FAD0;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E4F0);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A4340, 0, 1, D_004A2D30);
    cFloatMenuItem_ctor((char*)self + 0x194, 1, &D_004A4344, -1.0f, 1.0f, D_0047E508);
    cFloatMenuItem_ctor((char*)self + 0x1C8, 2, &D_004A4348, 0.0f, 20.0f, D_0047E520);
    cFloatMenuItem_ctor((char*)self + 0x1FC, 3, &D_004A434C, 0.0f, 500.0f, D_0047E538);
    cFloatMenuItem_ctor((char*)self + 0x230, 4, &D_004A4350, 0.0f, 100.0f, D_0047E550);
    cFloatMenuItem_ctor((char*)self + 0x264, 5, &D_004A4354, 0.0f, 100.0f, D_0047E570);
    cFloatMenuItem_ctor((char*)self + 0x298, 6, &D_004A4358, 1.0f, 300.0f, D_0047E590);
    cFloatMenuItem_ctor((char*)self + 0x2CC, 7, &D_004A435C, 0.0f, 500.0f, D_0047E5A8);
    cFloatMenuItem_ctor((char*)self + 0x300, 8, &D_004A4360, 0.0f, 100.0f, D_0047E5C0);
    cFloatMenuItem_ctor((char*)self + 0x334, 9, &D_004A4364, 0.0f, 100.0f, D_0047E5D8);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C8, -1);
    cMenu_addItem(self, (char*)self + 0x1FC, -1);
    cMenu_addItem(self, (char*)self + 0x230, -1);
    cMenu_addItem(self, (char*)self + 0x264, -1);
    cMenu_addItem(self, (char*)self + 0x298, -1);
    cMenu_addItem(self, (char*)self + 0x2CC, -1);
    cMenu_addItem(self, (char*)self + 0x300, -1);
    cMenu_addItem(self, (char*)self + 0x334, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cShellRendererMenu_cShellRendererMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
// PORT: the unit declares cFloatMenuItem_ctor(self, id, var, lo, hi, text); the real parameter order is
// (self, id, var, lo, hi, text) like cIntMenuItem (it decides the arg-move order and FP register allocation here).
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047FA78[];
extern char D_0047E470[];
extern char D_0047E480[];
extern char D_0047E5F0[];
extern char D_0047E608[];
extern char D_0047E620[];
extern char D_0047E638[];
extern char D_0047E648[];
extern char D_0047E658[];
extern char D_0047E670[];
extern char D_004A2D30[];
extern int D_004A46B8;
extern int D_004A46BC;
extern int D_004A46C0;
extern int D_004A46C4;
extern int D_004A46C8;
extern int D_004A46CC;
extern float D_004A46D0;
extern float D_004A46D4;
extern int D_004A46D8;

extern "C" void* cShellRendererMenu_cShellRendererMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047FA78;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E5F0);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A46B8, 0, 1, D_004A2D30);
    cIntMenuItem_cIntMenuItem((char*)self + 0x194, 1, &D_004A46BC, 0, 0xc8, D_0047E608);
    cIntMenuItem_cIntMenuItem((char*)self + 0x1C4, 2, &D_004A46C0, 0, 0xc8, D_0047E620);
    cIntMenuItem_cIntMenuItem((char*)self + 0x1F4, 3, &D_004A46C4, 1, 0x2710, D_0047E470);
    cIntMenuItem_cIntMenuItem((char*)self + 0x224, 4, &D_004A46C8, 1, 0x2710, D_0047E480);
    cIntMenuItem_cIntMenuItem((char*)self + 0x254, 5, &D_004A46CC, 1, 0x186a0, D_0047E638);
    cFloatMenuItem_ctor((char*)self + 0x284, 6, &D_004A46D0, 1e-05f, 2.0f, D_0047E648);
    cFloatMenuItem_ctor((char*)self + 0x2B8, 7, &D_004A46D4, 0.0f, 1.0f, D_0047E658);
    cIntMenuItem_cIntMenuItem((char*)self + 0x2EC, 8, &D_004A46D8, 1, 0x40, D_0047E670);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C4, -1);
    cMenu_addItem(self, (char*)self + 0x1F4, -1);
    cMenu_addItem(self, (char*)self + 0x224, -1);
    cMenu_addItem(self, (char*)self + 0x254, -1);
    cMenu_addItem(self, (char*)self + 0x284, -1);
    cMenu_addItem(self, (char*)self + 0x2B8, -1);
    cMenu_addItem(self, (char*)self + 0x2EC, -1);
    return self;
}
#endif

INCLUDE_ASM("main/debugmenu", cScreenTintMenu_cScreenTintMenu);

//100%
INCLUDE_ASM("main/debugmenu", cShadowMenu_cShadowMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
// PORT: the unit declares cFloatMenuItem_ctor(self, id, var, lo, hi, text); the real parameter order is
// (self, id, var, lo, hi, text) like cIntMenuItem (it decides the arg-move order and FP register allocation here).
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F9C8[];
extern char D_0047E948[];
extern char D_0047E958[];
extern char D_0047E970[];
extern char D_0047E980[];
extern char D_0047E990[];
extern char D_0047E9A0[];
extern char D_0047E9B0[];
extern char D_004A2D30[];
extern char D_004A2D60[];
extern char D_004A2D68[];
extern int D_004A41B0;
extern int D_004A41B4;
extern float D_004A41B8;
extern float D_004A41BC;
extern float D_004A41C0;
extern float D_004A41C4;
extern float D_004A41C8;
extern float D_004A41CC;
extern float D_004A41D0;

extern "C" void* cShadowMenu_cShadowMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F9C8;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E948);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A41B0, 0, 1, D_004A2D30);
    cIntMenuItem_cIntMenuItem((char*)self + 0x194, 1, &D_004A41B4, 0, 1, D_0047E958);
    cFloatMenuItem_ctor((char*)self + 0x1C4, 2, &D_004A41B8, -1.0f, 1.0f, D_0047E970);
    cFloatMenuItem_ctor((char*)self + 0x1F8, 3, &D_004A41BC, -1.0f, 1.0f, D_0047E980);
    cFloatMenuItem_ctor((char*)self + 0x22C, 4, &D_004A41C0, -1.0f, 1.0f, D_0047E990);
    cFloatMenuItem_ctor((char*)self + 0x260, 5, &D_004A41C4, 0.1f, 100000.0f, D_004A2D60);
    cFloatMenuItem_ctor((char*)self + 0x294, 6, &D_004A41C8, 0.0f, 1.0f, D_0047E9A0);
    cFloatMenuItem_ctor((char*)self + 0x2C8, 7, &D_004A41CC, -64.0f, 64.0f, D_0047E9B0);
    cFloatMenuItem_ctor((char*)self + 0x2FC, 8, &D_004A41D0, -64.0f, 64.0f, D_004A2D68);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C4, -1);
    cMenu_addItem(self, (char*)self + 0x1F8, -1);
    cMenu_addItem(self, (char*)self + 0x22C, -1);
    cMenu_addItem(self, (char*)self + 0x260, -1);
    cMenu_addItem(self, (char*)self + 0x294, -1);
    cMenu_addItem(self, (char*)self + 0x2C8, -1);
    cMenu_addItem(self, (char*)self + 0x2FC, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cSnowSurfaceMenu_cSnowSurfaceMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
extern "C" void* cFloatMenuItem_cFloatMenuItem(void* self, int a1, void* var, void* text, float lo, float hi);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F970[];
extern char D_0047E9C0[];
extern char D_004A2D30[];
extern char D_0047E9D8[];
extern char D_004A2D70[];
extern char D_004A2D78[];
extern char D_004A2D80[];
extern char D_0047E9F0[];
extern char D_0047EA00[];
extern int D_004A46DC;
extern int D_004A46E0;
extern float D_004A46E4;
extern float D_004A46E8;
extern float D_004A46EC;
extern float D_004A46F0;
extern float D_004A46F4;

extern "C" void* cSnowSurfaceMenu_cSnowSurfaceMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F970;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047E9C0);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A46DC, 0, 1, D_004A2D30);
    cIntMenuItem_cIntMenuItem((char*)self + 0x194, 1, &D_004A46E0, 0, 1, D_0047E9D8);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x1C4, 2, &D_004A46E4, D_004A2D70, 0.0f, 32.0f);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x1F8, 3, &D_004A46E8, D_004A2D78, 0.0f, 32.0f);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x22C, 4, &D_004A46EC, D_004A2D80, 0.0f, 32.0f);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x260, 5, &D_004A46F0, D_0047E9F0, 0.0f, 3.0f);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x294, 6, &D_004A46F4, D_0047EA00, 0.0f, 3.0f);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C4, -1);
    cMenu_addItem(self, (char*)self + 0x1F8, -1);
    cMenu_addItem(self, (char*)self + 0x22C, -1);
    cMenu_addItem(self, (char*)self + 0x260, -1);
    cMenu_addItem(self, (char*)self + 0x294, -1);
    return self;
}
#endif

INCLUDE_ASM("main/debugmenu", cBoardTrailMenu_cBoardTrailMenu);

//100%
INCLUDE_ASM("main/debugmenu", cFlagsMenu_cFlagsMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F8C0[];
extern char D_0047EBB8[];
extern char D_0047EBC8[];
extern char D_0047EBD8[];
extern int D_004A4240;
extern int D_004A4244;

extern "C" void* cFlagsMenu_cFlagsMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F8C0;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047EBB8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A4240, 0, 1, D_0047EBC8);
    cIntMenuItem_cIntMenuItem((char*)self + 0x194, 1, &D_004A4244, 0, 1, D_0047EBD8);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cPowerUpFXTogglesMenu_cPowerUpFXTogglesMenu);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F868[];
extern char D_0047EBE8[];
extern char D_0047EC00[];
extern char D_0047EC20[];
extern char D_0047EC40[];
extern char D_0047EC58[];
extern char D_0047EC78[];
extern char D_0047EC98[];
extern char D_0047ECC0[];
extern char D_0047ECE8[];
extern char D_0047ED08[];
extern char D_0047ED20[];
extern char D_0047ED38[];
extern char D_0047ED48[];
extern char D_0047ED60[];
extern char D_0047ED78[];
extern char D_0047ED88[];
extern int D_004A4700;
extern int D_004A4704;
extern float D_004A4708;
extern float D_004A470C;
extern float D_004A4710;
extern float D_004A4714;
extern float D_004A4718;
extern int D_004A471C;
extern int D_004A4720;
extern int D_004A4724;
extern int D_004A4728;
extern int D_004A472C;
extern int D_004A4730;
extern int D_004A4734;
extern int D_004A4738;

extern "C" void* cPowerUpFXTogglesMenu_cPowerUpFXTogglesMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F868;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047EBE8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A4700, 0, 1, D_0047EC00);
    cIntMenuItem_cIntMenuItem((char*)self + 0x194, 1, &D_004A4704, 0, 1, D_0047EC20);
    cFloatMenuItem_ctor((char*)self + 0x1C4, 2, &D_004A4708, 0.0f, 1.0f, D_0047EC40);
    cFloatMenuItem_ctor((char*)self + 0x1F8, 3, &D_004A470C, 0.0f, 60.0f, D_0047EC58);
    cFloatMenuItem_ctor((char*)self + 0x22C, 4, &D_004A4710, 0.0f, 60.0f, D_0047EC78);
    cFloatMenuItem_ctor((char*)self + 0x260, 5, &D_004A4714, 0.0f, 120.0f, D_0047EC98);
    cFloatMenuItem_ctor((char*)self + 0x294, 6, &D_004A4718, 0.0f, 120.0f, D_0047ECC0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x2C8, 7, &D_004A471C, 0, 0x64, D_0047ECE8);
    cIntMenuItem_cIntMenuItem((char*)self + 0x2F8, 8, &D_004A4720, 0, 1, D_0047ED08);
    cIntMenuItem_cIntMenuItem((char*)self + 0x328, 9, &D_004A4724, 0, 1, D_0047ED20);
    cIntMenuItem_cIntMenuItem((char*)self + 0x358, 0xa, &D_004A4728, 0, 1, D_0047ED38);
    cIntMenuItem_cIntMenuItem((char*)self + 0x388, 0xb, &D_004A472C, 0, 1, D_0047ED48);
    cIntMenuItem_cIntMenuItem((char*)self + 0x3B8, 0xc, &D_004A4730, 0, 1, D_0047ED60);
    cIntMenuItem_cIntMenuItem((char*)self + 0x3E8, 0xd, &D_004A4734, 0, 1, D_0047ED78);
    cIntMenuItem_cIntMenuItem((char*)self + 0x418, 0xe, &D_004A4738, 0, 1, D_0047ED88);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C4, -1);
    cMenu_addItem(self, (char*)self + 0x1F8, -1);
    cMenu_addItem(self, (char*)self + 0x22C, -1);
    cMenu_addItem(self, (char*)self + 0x260, -1);
    cMenu_addItem(self, (char*)self + 0x294, -1);
    cMenu_addItem(self, (char*)self + 0x2C8, -1);
    cMenu_addItem(self, (char*)self + 0x2F8, -1);
    cMenu_addItem(self, (char*)self + 0x328, -1);
    cMenu_addItem(self, (char*)self + 0x358, -1);
    cMenu_addItem(self, (char*)self + 0x388, -1);
    cMenu_addItem(self, (char*)self + 0x3B8, -1);
    cMenu_addItem(self, (char*)self + 0x3E8, -1);
    cMenu_addItem(self, (char*)self + 0x418, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cSnowfallTogglesMenu_cSnowfallTogglesMenu);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F810[];
extern char D_0047EDA0[];
extern char D_0047EDB8[];
extern char D_0047EDD0[];
extern char D_0047EDE8[];
extern char D_0047EE00[];
extern char D_0047EE18[];
extern char D_0047EE30[];
extern char D_0047EE48[];
extern char D_0047EE60[];
extern char D_0047EE78[];
extern char D_0047EE98[];
extern char D_0047EEB0[];
extern char D_0047EEC8[];
extern char D_005059B8[];
extern char D_005059C8[];
extern int D_004A473C;
extern float D_004A4740;
extern float D_004A4744;
extern float D_004A4748;
extern float D_004A474C;
extern float D_004A4750;
extern float D_004A4754;
extern float D_004A4758;
extern float D_004A475C;
extern int D_004A4760;

extern "C" void* cSnowfallTogglesMenu_cSnowfallTogglesMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F810;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047EDA0);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A473C, 0, 1, D_0047EDB8);
    cFloatMenuItem_ctor((char*)self + 0x194, 1, &D_004A4740, 0.0f, 4.0f, D_0047EDD0);
    cFloatMenuItem_ctor((char*)self + 0x1C8, 2, &D_004A4744, 0.0f, 100.0f, D_0047EDE8);
    cFloatMenuItem_ctor((char*)self + 0x1FC, 3, &D_004A4748, 0.1f, 10.0f, D_0047EE00);
    cFloatMenuItem_ctor((char*)self + 0x230, 4, &D_004A474C, 0.0f, 360.0f, D_0047EE18);
    cFloatMenuItem_ctor((char*)self + 0x264, 5, &D_004A4750, 0.0f, 1.0f, D_0047EE30);
    cFloatMenuItem_ctor((char*)self + 0x298, 6, &D_004A4754, -2.0f, 5.0f, D_0047EE48);
    cFloatMenuItem_ctor((char*)self + 0x2CC, 7, &D_004A4758, 0.0f, 1.0f, D_0047EE60);
    cFloatMenuItem_ctor((char*)self + 0x300, 8, &D_004A475C, 0.0f, 100.0f, D_0047EE78);
    cARGBMenuItem_cARGBMenuItem((char*)self + 0x334, 9, D_0047EE98, D_005059B8);
    cARGBMenuItem_cARGBMenuItem((char*)self + 0x990, 0xa, D_0047EEB0, D_005059C8);
    cIntMenuItem_cIntMenuItem((char*)self + 0xFEC, 0xb, &D_004A4760, 0, 1, D_0047EEC8);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C8, -1);
    cMenu_addItem(self, (char*)self + 0x1FC, -1);
    cMenu_addItem(self, (char*)self + 0x230, -1);
    cMenu_addItem(self, (char*)self + 0x264, -1);
    cMenu_addItem(self, (char*)self + 0x298, -1);
    cMenu_addItem(self, (char*)self + 0x2CC, -1);
    cMenu_addItem(self, (char*)self + 0x300, -1);
    cMenu_addItem(self, (char*)self + 0x334, -1);
    cMenu_addItem(self, (char*)self + 0x990, -1);
    cMenu_addItem(self, (char*)self + 0xFEC, -1);
    return self;
}
#endif

INCLUDE_ASM("main/debugmenu", cSplashTogglesMenu_cSplashTogglesMenu);

//100%
INCLUDE_ASM("main/debugmenu", cTubeMenu_cTubeMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
extern "C" void* cFloatMenuItem_cFloatMenuItem(void* self, int a1, void* var, void* text, float lo, float hi);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F760[];
extern char D_0047F4A8[];
extern char D_004A2D30[];
extern char D_0047F4B8[];
extern char D_0047F4C8[];
extern char D_004A2DA8[];
extern char D_004A2DB0[];
extern char D_004A2DB8[];
extern int D_004A41D4;
extern float D_004A41D8;
extern float D_004A41DC;
extern int D_004A41E0;
extern int D_004A41E4;
extern int D_004A41E8;

extern "C" void* cTubeMenu_cTubeMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F760;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047F4A8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A41D4, 0, 1, D_004A2D30);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x194, 1, &D_004A41D8, D_0047F4B8, 0.0f, 1000.0f);
    cFloatMenuItem_cFloatMenuItem((char*)self + 0x1C8, 2, &D_004A41DC, D_0047F4C8, 0.0f, 1000.0f);
    cIntMenuItem_cIntMenuItem((char*)self + 0x1FC, 3, &D_004A41E0, 0, 0xFF, D_004A2DA8);
    cIntMenuItem_cIntMenuItem((char*)self + 0x22C, 4, &D_004A41E4, 0, 0xFF, D_004A2DB0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x25C, 5, &D_004A41E8, 0, 0xFF, D_004A2DB8);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C8, -1);
    cMenu_addItem(self, (char*)self + 0x1FC, -1);
    cMenu_addItem(self, (char*)self + 0x22C, -1);
    cMenu_addItem(self, (char*)self + 0x25C, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cPathArrowMenu_cPathArrowMenu);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F708[];
extern char D_0047F4D8[];
extern char D_0047F4E8[];
extern char D_0047F4F8[];
extern char D_0047F508[];
extern char D_0047F518[];
extern char D_0047F528[];
extern char D_0047F538[];
extern char D_0047F548[];
extern char D_0047F558[];
extern char D_0047F568[];
extern char D_004A2D30[];
extern char D_004A2DA8[];
extern char D_004A2DB0[];
extern char D_004A2DB8[];
extern char D_004A2DC0[];
extern char D_004A2DC8[];
extern char D_004A2DD0[];
extern int D_004A41EC;
extern float D_004A41F0;
extern float D_004A41F4;
extern float D_004A41F8;
extern float D_004A41FC;
extern float D_004A4200;
extern float D_004A4204;
extern int D_004A4208;
extern int D_004A420C;
extern int D_004A4210;
extern int D_004A4214;
extern float D_004A4218;
extern float D_004A421C;
extern float D_004A4220;
extern int D_004A4224;
extern int D_004A4228;

extern "C" void* cPathArrowMenu_cPathArrowMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F708;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047F4D8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cIntMenuItem_cIntMenuItem((char*)self + 0x164, 0, &D_004A41EC, 0, 1, D_004A2D30);
    cFloatMenuItem_ctor((char*)self + 0x194, 1, &D_004A41F0, 0.0f, 1000.0f, D_0047F4E8);
    cFloatMenuItem_ctor((char*)self + 0x1C8, 2, &D_004A41F4, 0.0f, 1000.0f, D_0047F4F8);
    cFloatMenuItem_ctor((char*)self + 0x1FC, 3, &D_004A41F8, 0.0f, 1000.0f, D_0047F508);
    cFloatMenuItem_ctor((char*)self + 0x230, 4, &D_004A41FC, 0.0f, 1000.0f, D_0047F518);
    cFloatMenuItem_ctor((char*)self + 0x264, 5, &D_004A4200, 0.0f, 1000.0f, D_0047F528);
    cFloatMenuItem_ctor((char*)self + 0x298, 6, &D_004A4204, 0.0f, 1000.0f, D_004A2DC0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x2CC, 7, &D_004A4208, 0, 0xff, D_004A2DA8);
    cIntMenuItem_cIntMenuItem((char*)self + 0x2FC, 8, &D_004A420C, 0, 0xff, D_004A2DB0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x32C, 9, &D_004A4210, 0, 0xff, D_004A2DB8);
    cIntMenuItem_cIntMenuItem((char*)self + 0x35C, 0xa, &D_004A4214, 0, 0xff, D_004A2DC8);
    cFloatMenuItem_ctor((char*)self + 0x38C, 0xb, &D_004A4218, 0.0f, 1000.0f, D_0047F538);
    cFloatMenuItem_ctor((char*)self + 0x3C0, 0xc, &D_004A421C, 0.0f, 1000.0f, D_0047F548);
    cFloatMenuItem_ctor((char*)self + 0x3F4, 0xd, &D_004A4220, 50.0f, 1000.0f, D_0047F558);
    cIntMenuItem_cIntMenuItem((char*)self + 0x428, 0xe, &D_004A4224, 0, 0x3e8, D_004A2DD0);
    cIntMenuItem_cIntMenuItem((char*)self + 0x458, 0xf, &D_004A4228, 1, 0x4650, D_0047F568);
    cMenu_addItem(self, (char*)self + 0x130, -1);
    cMenu_addItem(self, (char*)self + 0x14C, -1);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C8, -1);
    cMenu_addItem(self, (char*)self + 0x1FC, -1);
    cMenu_addItem(self, (char*)self + 0x230, -1);
    cMenu_addItem(self, (char*)self + 0x264, -1);
    cMenu_addItem(self, (char*)self + 0x298, -1);
    cMenu_addItem(self, (char*)self + 0x2CC, -1);
    cMenu_addItem(self, (char*)self + 0x2FC, -1);
    cMenu_addItem(self, (char*)self + 0x32C, -1);
    cMenu_addItem(self, (char*)self + 0x35C, -1);
    cMenu_addItem(self, (char*)self + 0x38C, -1);
    cMenu_addItem(self, (char*)self + 0x3C0, -1);
    cMenu_addItem(self, (char*)self + 0x3F4, -1);
    cMenu_addItem(self, (char*)self + 0x428, -1);
    cMenu_addItem(self, (char*)self + 0x458, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", cVisualEffectsMainMenu_cVisualEffectsMainMenu);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cIntMenuItem_cIntMenuItem(void* self, int a1, void* var, int a3, int a4, void* text);
void* cFloatMenuItem_ctor(void* self, int a1, void* var, float lo, float hi, void* text) __asm__("cFloatMenuItem_cFloatMenuItem");
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void* cARGBMenuItem_cARGBMenuItem(void* self, int a1, void* text, void* color);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047F6B0[];
extern char D_0047F578[];
extern char D_0047F598[];
extern char D_0047F5A8[];
extern char D_0047F5C0[];
extern char D_0047F5D0[];
extern char D_0047F5E0[];
extern char D_0047F5F0[];
extern char D_0047F600[];
extern char D_0047F610[];
extern char D_0047F620[];
extern char D_0047F630[];
extern char D_0047F650[];
extern char D_0047F668[];
extern char D_0047F688[];
extern char D_0047F698[];
extern char D_004A2DD8[];
extern char D_004A2DE0[];
extern char D_004A2DE8[];
extern char D_004C98E0[];
extern char D_004CA328[];
extern char D_004CA7C0[];
extern char D_004CAEF8[];
extern char D_004CB2C8[];
extern char D_004CBBE8[];
extern char D_004CBDE8[];
extern char D_004CC150[];
extern char D_004CCAB0[];
extern char D_004CCDE0[];
extern char D_004CD0A8[];
extern char D_004CD678[];
extern char D_004CD840[];
extern char D_004CDC88[];
extern char D_004CECA8[];
extern char D_004D11F0[];
extern char D_004D1480[];

extern "C" void* cVisualEffectsMainMenu_cVisualEffectsMainMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047F6B0;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047F578);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cSubMenuItem_cSubMenuItem((char*)self + 0x164, D_004C98E0, D_0047F598);
    cSubMenuItem_cSubMenuItem((char*)self + 0x180, D_004CA328, D_0047F5A8);
    cSubMenuItem_cSubMenuItem((char*)self + 0x19C, D_004CA7C0, D_0047F5C0);
    cSubMenuItem_cSubMenuItem((char*)self + 0x1B8, D_004CAEF8, D_004A2DD8);
    cSubMenuItem_cSubMenuItem((char*)self + 0x1D4, D_004CB2C8, D_0047F5D0);
    cSubMenuItem_cSubMenuItem((char*)self + 0x1F0, D_004CBBE8, D_0047F5E0);
    cSubMenuItem_cSubMenuItem((char*)self + 0x20C, D_004CBDE8, D_0047F5F0);
    cSubMenuItem_cSubMenuItem((char*)self + 0x228, D_004CC150, D_0047F600);
    cSubMenuItem_cSubMenuItem((char*)self + 0x244, D_004CCAB0, D_004A2DE0);
    cSubMenuItem_cSubMenuItem((char*)self + 0x260, D_004CCDE0, D_0047F610);
    cSubMenuItem_cSubMenuItem((char*)self + 0x27C, D_004CD0A8, D_0047F620);
    cSubMenuItem_cSubMenuItem((char*)self + 0x298, D_004CD678, D_004A2DE8);
    cSubMenuItem_cSubMenuItem((char*)self + 0x2B4, D_004CD840, D_0047F630);
    cSubMenuItem_cSubMenuItem((char*)self + 0x2D0, D_004CDC88, D_0047F650);
    cSubMenuItem_cSubMenuItem((char*)self + 0x2EC, D_004CECA8, D_0047F668);
    cSubMenuItem_cSubMenuItem((char*)self + 0x308, D_004D11F0, D_0047F688);
    cSubMenuItem_cSubMenuItem((char*)self + 0x324, D_004D1480, D_0047F698);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    cMenu_addItem(self, (char*)self + 0x180, -1);
    cMenu_addItem(self, (char*)self + 0x19C, -1);
    cMenu_addItem(self, (char*)self + 0x1B8, -1);
    cMenu_addItem(self, (char*)self + 0x1D4, -1);
    cMenu_addItem(self, (char*)self + 0x1F0, -1);
    cMenu_addItem(self, (char*)self + 0x20C, -1);
    cMenu_addItem(self, (char*)self + 0x228, -1);
    cMenu_addItem(self, (char*)self + 0x244, -1);
    cMenu_addItem(self, (char*)self + 0x260, -1);
    cMenu_addItem(self, (char*)self + 0x27C, -1);
    cMenu_addItem(self, (char*)self + 0x298, -1);
    cMenu_addItem(self, (char*)self + 0x2B4, -1);
    cMenu_addItem(self, (char*)self + 0x2D0, -1);
    cMenu_addItem(self, (char*)self + 0x2EC, -1);
    cMenu_addItem(self, (char*)self + 0x308, -1);
    cMenu_addItem(self, (char*)self + 0x324, -1);
    return self;
}
#endif

extern "C" void* func_002CBF60(void* self);

//100%
INCLUDE_ASM("main/debugmenu", func_0024D690__FPv);
#ifdef SKIP_ASM
void* func_0024D690(void* self)
{
    return func_002CBF60(self);
}
#endif

extern "C" void* func_002CBFD0(void* self);

//100%
INCLUDE_ASM("main/debugmenu", func_0024D6B0__FPv);
#ifdef SKIP_ASM
void* func_0024D6B0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024D6D0);
#ifdef SKIP_ASM
extern "C" void* func_0024D6D0(void* fmt, ...)
{
    return fmt;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024D710);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024D710(void* self, int flags)
{
    func_002CA280((char*)self + 0xA18, 2);
    func_002CA280((char*)self + 0x9E8, 2);
    func_002CA280((char*)self + 0x9B8, 2);
    func_002CA280((char*)self + 0x988, 2);
    func_002CA280((char*)self + 0x958, 2);
    func_002CA280((char*)self + 0x924, 2);
    func_002CA280((char*)self + 0x8F0, 2);
    func_002CA280((char*)self + 0x8BC, 2);
    func_002CA280((char*)self + 0x888, 2);
    func_002CA280((char*)self + 0x858, 2);
    func_002CA280((char*)self + 0x828, 2);
    func_002CA280((char*)self + 0x7F8, 2);
    func_002CA280((char*)self + 0x7C4, 2);
    func_002CA280((char*)self + 0x794, 2);
    func_002CA280((char*)self + 0x764, 2);
    func_002CA280((char*)self + 0x734, 2);
    func_002CA280((char*)self + 0x704, 2);
    func_002CA280((char*)self + 0x6D4, 2);
    func_002CA280((char*)self + 0x6A4, 2);
    func_002CA280((char*)self + 0x674, 2);
    func_002CA280((char*)self + 0x644, 2);
    func_002CA280((char*)self + 0x614, 2);
    func_002CA280((char*)self + 0x5E4, 2);
    func_002CA280((char*)self + 0x5B4, 2);
    func_002CA280((char*)self + 0x584, 2);
    func_002CA280((char*)self + 0x554, 2);
    func_002CA280((char*)self + 0x524, 2);
    func_002CA280((char*)self + 0x4F4, 2);
    func_002CA280((char*)self + 0x4C4, 2);
    func_002CA280((char*)self + 0x494, 2);
    func_002CA280((char*)self + 0x464, 2);
    func_002CA280((char*)self + 0x434, 2);
    func_002CA280((char*)self + 0x404, 2);
    func_002CA280((char*)self + 0x3D4, 2);
    func_002CA280((char*)self + 0x3A4, 2);
    func_002CA280((char*)self + 0x374, 2);
    func_002CA280((char*)self + 0x344, 2);
    func_002CA280((char*)self + 0x314, 2);
    func_002CA280((char*)self + 0x2E4, 2);
    func_002CA280((char*)self + 0x2B4, 2);
    func_002CA280((char*)self + 0x284, 2);
    func_002CA280((char*)self + 0x254, 2);
    func_002CA280((char*)self + 0x224, 2);
    func_002CA280((char*)self + 0x1F4, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024D998);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024D998(void* self, int flags)
{
    func_002CA280((char*)self + 0x464, 2);
    func_002CA280((char*)self + 0x434, 2);
    func_002CA280((char*)self + 0x404, 2);
    func_002CA280((char*)self + 0x3D4, 2);
    func_002CA280((char*)self + 0x3A4, 2);
    func_002CA280((char*)self + 0x374, 2);
    func_002CA280((char*)self + 0x344, 2);
    func_002CA280((char*)self + 0x314, 2);
    func_002CA280((char*)self + 0x2E4, 2);
    func_002CA280((char*)self + 0x2B4, 2);
    func_002CA280((char*)self + 0x284, 2);
    func_002CA280((char*)self + 0x254, 2);
    func_002CA280((char*)self + 0x224, 2);
    func_002CA280((char*)self + 0x1F4, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024DAB8);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024DAB8(void* self, int flags)
{
    func_002CA280((char*)self + 0x700, 2);
    func_002CA280((char*)self + 0x6CC, 2);
    func_002CA280((char*)self + 0x698, 2);
    func_002CA280((char*)self + 0x664, 2);
    func_002CA280((char*)self + 0x630, 2);
    func_002CA280((char*)self + 0x600, 2);
    func_002CA280((char*)self + 0x5CC, 2);
    func_002CA280((char*)self + 0x598, 2);
    func_002CA280((char*)self + 0x564, 2);
    func_002CA280((char*)self + 0x530, 2);
    func_002CA280((char*)self + 0x4FC, 2);
    func_002CA280((char*)self + 0x4C8, 2);
    func_002CA280((char*)self + 0x494, 2);
    func_002CA280((char*)self + 0x460, 2);
    func_002CA280((char*)self + 0x42C, 2);
    func_002CA280((char*)self + 0x3FC, 2);
    func_002CA280((char*)self + 0x3C8, 2);
    func_002CA280((char*)self + 0x394, 2);
    func_002CA280((char*)self + 0x360, 2);
    func_002CA280((char*)self + 0x32C, 2);
    func_002CA280((char*)self + 0x2F8, 2);
    func_002CA280((char*)self + 0x2C4, 2);
    func_002CA280((char*)self + 0x290, 2);
    func_002CA280((char*)self + 0x25C, 2);
    func_002CA280((char*)self + 0x228, 2);
    func_002CA280((char*)self + 0x1F4, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024DC68);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

static inline void dtorSubMenuItem_24DC68(void* p)
{
    func_002CAA80((char*)p + 0x18, 2);
    func_002CA280(p, 2);
}

extern "C" void func_0024DC68(void* self, int flags)
{
    func_002CA280((char*)self + 0x904, 2);
    func_002CA280((char*)self + 0x8E0, 2);
    func_002CA280((char*)self + 0x8BC, 2);
    func_002CA280((char*)self + 0x898, 2);
    func_002CA280((char*)self + 0x874, 2);
    dtorSubMenuItem_24DC68((char*)self + 0x2C4);
    func_002CA280((char*)self + 0x290, 2);
    func_002CA280((char*)self + 0x25C, 2);
    func_002CA280((char*)self + 0x22C, 2);
    func_002CA280((char*)self + 0x1F8, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024DD70);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024DD70(void* self, int flags)
{
    func_002CA280((char*)self + 0x928, 2);
    func_002CA280((char*)self + 0x8F4, 2);
    func_002CA280((char*)self + 0x8C0, 2);
    func_002CA280((char*)self + 0x88C, 2);
    func_002CA280((char*)self + 0x858, 2);
    func_002CA280((char*)self + 0x824, 2);
    func_002CA280((char*)self + 0x7F0, 2);
    func_002CA280((char*)self + 0x7C0, 2);
    func_002CA280((char*)self + 0x78C, 2);
    func_002CA280((char*)self + 0x758, 2);
    func_002CA280((char*)self + 0x724, 2);
    func_002CA280((char*)self + 0x6F0, 2);
    func_002CA280((char*)self + 0x6BC, 2);
    func_002CA280((char*)self + 0x688, 2);
    func_002CA280((char*)self + 0x654, 2);
    func_002CA280((char*)self + 0x620, 2);
    func_002CA280((char*)self + 0x5EC, 2);
    func_002CA280((char*)self + 0x5B8, 2);
    func_002CA280((char*)self + 0x584, 2);
    func_002CA280((char*)self + 0x550, 2);
    func_002CA280((char*)self + 0x520, 2);
    func_002CA280((char*)self + 0x4F0, 2);
    func_002CA280((char*)self + 0x4C0, 2);
    func_002CA280((char*)self + 0x490, 2);
    func_002CA280((char*)self + 0x45C, 2);
    func_002CA280((char*)self + 0x42C, 2);
    func_002CA280((char*)self + 0x3FC, 2);
    func_002CA280((char*)self + 0x3C8, 2);
    func_002CA280((char*)self + 0x394, 2);
    func_002CA280((char*)self + 0x360, 2);
    func_002CA280((char*)self + 0x32C, 2);
    func_002CA280((char*)self + 0x2F8, 2);
    func_002CA280((char*)self + 0x2C4, 2);
    func_002CA280((char*)self + 0x290, 2);
    func_002CA280((char*)self + 0x25C, 2);
    func_002CA280((char*)self + 0x228, 2);
    func_002CA280((char*)self + 0x1F4, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024DFA0);
#ifdef SKIP_ASM
extern "C" void func_0024DFA0(void* self, int flags)
{
    func_002CA280((char*)self + 0x59C, 2);
    func_002CA280((char*)self + 0x56C, 2);
    func_002CA280((char*)self + 0x53C, 2);
    func_002CA280((char*)self + 0x508, 2);
    func_002CA280((char*)self + 0x4D4, 2);
    func_002CA280((char*)self + 0x4A0, 2);
    func_002CA280((char*)self + 0x46C, 2);
    func_002CA280((char*)self + 0x438, 2);
    func_002CA280((char*)self + 0x404, 2);
    func_002CA280((char*)self + 0x3D0, 2);
    func_002CA280((char*)self + 0x39C, 2);
    func_002CA280((char*)self + 0x368, 2);
    func_002CA280((char*)self + 0x334, 2);
    func_002CA280((char*)self + 0x300, 2);
    func_002CA280((char*)self + 0x2CC, 2);
    func_002CA280((char*)self + 0x298, 2);
    func_002CA280((char*)self + 0x264, 2);
    func_002CA280((char*)self + 0x230, 2);
    func_002CA280((char*)self + 0x1FC, 2);
    func_002CA280((char*)self + 0x1C8, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024E0F8);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024E0F8(void* self, int flags)
{
    func_002CA280((char*)self + 0x418, 2);
    func_002CA280((char*)self + 0x3E8, 2);
    func_002CA280((char*)self + 0x3B8, 2);
    func_002CA280((char*)self + 0x388, 2);
    func_002CA280((char*)self + 0x358, 2);
    func_002CA280((char*)self + 0x328, 2);
    func_002CA280((char*)self + 0x2F8, 2);
    func_002CA280((char*)self + 0x2C8, 2);
    func_002CA280((char*)self + 0x294, 2);
    func_002CA280((char*)self + 0x260, 2);
    func_002CA280((char*)self + 0x22C, 2);
    func_002CA280((char*)self + 0x1F8, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024E200);
#ifdef SKIP_ASM
static inline void dtorSubMenuItem_24E200(void* p)
{
    func_002CAA80((char*)p + 0x18, 2);
    func_002CA280(p, 2);
}

extern "C" void func_0024E200(void* self, int flags)
{
    func_002CA280((char*)self + 0xFEC, 2);
    func_002CA280((char*)self + 0xFD0, 2);
    func_002CA280((char*)self + 0xFAC, 2);
    func_002CA280((char*)self + 0xF88, 2);
    func_002CA280((char*)self + 0xF64, 2);
    func_002CA280((char*)self + 0xF40, 2);
    dtorSubMenuItem_24E200((char*)self + 0x990);
    func_002CA280((char*)self + 0x974, 2);
    func_002CA280((char*)self + 0x950, 2);
    func_002CA280((char*)self + 0x92C, 2);
    func_002CA280((char*)self + 0x908, 2);
    func_002CA280((char*)self + 0x8E4, 2);
    dtorSubMenuItem_24E200((char*)self + 0x334);
    func_002CA280((char*)self + 0x300, 2);
    func_002CA280((char*)self + 0x2CC, 2);
    func_002CA280((char*)self + 0x298, 2);
    func_002CA280((char*)self + 0x264, 2);
    func_002CA280((char*)self + 0x230, 2);
    func_002CA280((char*)self + 0x1FC, 2);
    func_002CA280((char*)self + 0x1C8, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024E388);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

static inline void dtorSubMenuItem_24E388(void* p)
{
    func_002CAA80((char*)p + 0x18, 2);
    func_002CA280(p, 2);
}

extern "C" void func_0024E388(void* self, int flags)
{
    func_002CA280((char*)self + 0x252C, 2);
    func_002CA280((char*)self + 0x2508, 2);
    func_002CA280((char*)self + 0x24E4, 2);
    func_002CA280((char*)self + 0x24C0, 2);
    func_002CA280((char*)self + 0x249C, 2);
    dtorSubMenuItem_24E388((char*)self + 0x1EEC);
    func_002CA280((char*)self + 0x1ED0, 2);
    func_002CA280((char*)self + 0x1EAC, 2);
    func_002CA280((char*)self + 0x1E88, 2);
    func_002CA280((char*)self + 0x1E64, 2);
    func_002CA280((char*)self + 0x1E40, 2);
    dtorSubMenuItem_24E388((char*)self + 0x1890);
    func_002CA280((char*)self + 0x185C, 2);
    func_002CA280((char*)self + 0x1828, 2);
    func_002CA280((char*)self + 0x17F4, 2);
    func_002CA280((char*)self + 0x17C0, 2);
    func_002CA280((char*)self + 0x178C, 2);
    func_002CA280((char*)self + 0x1758, 2);
    func_002CA280((char*)self + 0x1724, 2);
    func_002CA280((char*)self + 0x16F0, 2);
    func_002CA280((char*)self + 0x16BC, 2);
    func_002CA280((char*)self + 0x1688, 2);
    func_002CA280((char*)self + 0x1654, 2);
    func_002CA280((char*)self + 0x1620, 2);
    func_002CA280((char*)self + 0x15EC, 2);
    func_002CA280((char*)self + 0x15B8, 2);
    func_002CA280((char*)self + 0x1584, 2);
    func_002CA280((char*)self + 0x1550, 2);
    func_002CA280((char*)self + 0x151C, 2);
    func_002CA280((char*)self + 0x14E8, 2);
    func_002CA280((char*)self + 0x14B4, 2);
    func_002CA280((char*)self + 0x1498, 2);
    func_002CA280((char*)self + 0x1474, 2);
    func_002CA280((char*)self + 0x1450, 2);
    func_002CA280((char*)self + 0x142C, 2);
    func_002CA280((char*)self + 0x1408, 2);
    dtorSubMenuItem_24E388((char*)self + 0xE58);
    func_002CA280((char*)self + 0xE3C, 2);
    func_002CA280((char*)self + 0xE18, 2);
    func_002CA280((char*)self + 0xDF4, 2);
    func_002CA280((char*)self + 0xDD0, 2);
    func_002CA280((char*)self + 0xDAC, 2);
    dtorSubMenuItem_24E388((char*)self + 0x7FC);
    func_002CA280((char*)self + 0x7C8, 2);
    func_002CA280((char*)self + 0x794, 2);
    func_002CA280((char*)self + 0x760, 2);
    func_002CA280((char*)self + 0x72C, 2);
    func_002CA280((char*)self + 0x6F8, 2);
    func_002CA280((char*)self + 0x6C4, 2);
    func_002CA280((char*)self + 0x690, 2);
    func_002CA280((char*)self + 0x65C, 2);
    func_002CA280((char*)self + 0x628, 2);
    func_002CA280((char*)self + 0x5F4, 2);
    func_002CA280((char*)self + 0x5C0, 2);
    func_002CA280((char*)self + 0x58C, 2);
    func_002CA280((char*)self + 0x558, 2);
    func_002CA280((char*)self + 0x524, 2);
    func_002CA280((char*)self + 0x4F0, 2);
    func_002CA280((char*)self + 0x4BC, 2);
    func_002CA280((char*)self + 0x488, 2);
    func_002CA280((char*)self + 0x454, 2);
    func_002CA280((char*)self + 0x420, 2);
    func_002CA280((char*)self + 0x3EC, 2);
    func_002CA280((char*)self + 0x3B8, 2);
    func_002CA280((char*)self + 0x384, 2);
    func_002CA280((char*)self + 0x350, 2);
    func_002CA280((char*)self + 0x31C, 2);
    func_002CA280((char*)self + 0x2EC, 2);
    func_002CA280((char*)self + 0x2BC, 2);
    func_002CA280((char*)self + 0x28C, 2);
    func_002CA280((char*)self + 0x258, 2);
    func_002CA280((char*)self + 0x224, 2);
    func_002CA280((char*)self + 0x1F4, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024E7C8);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024E7C8(void* self, int flags)
{
    func_002CA280((char*)self + 0x458, 2);
    func_002CA280((char*)self + 0x428, 2);
    func_002CA280((char*)self + 0x3F4, 2);
    func_002CA280((char*)self + 0x3C0, 2);
    func_002CA280((char*)self + 0x38C, 2);
    func_002CA280((char*)self + 0x35C, 2);
    func_002CA280((char*)self + 0x32C, 2);
    func_002CA280((char*)self + 0x2FC, 2);
    func_002CA280((char*)self + 0x2CC, 2);
    func_002CA280((char*)self + 0x298, 2);
    func_002CA280((char*)self + 0x264, 2);
    func_002CA280((char*)self + 0x230, 2);
    func_002CA280((char*)self + 0x1FC, 2);
    func_002CA280((char*)self + 0x1C8, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

INCLUDE_ASM("main/debugmenu", func_0024E8D8);

//100%
INCLUDE_ASM("main/debugmenu", func_0024F6C0);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024F6C0(void* self, int flags)
{
    func_002CA280((char*)self + 0x324, 2);
    func_002CA280((char*)self + 0x308, 2);
    func_002CA280((char*)self + 0x2EC, 2);
    func_002CA280((char*)self + 0x2D0, 2);
    func_002CA280((char*)self + 0x2B4, 2);
    func_002CA280((char*)self + 0x298, 2);
    func_002CA280((char*)self + 0x27C, 2);
    func_002CA280((char*)self + 0x260, 2);
    func_002CA280((char*)self + 0x244, 2);
    func_002CA280((char*)self + 0x228, 2);
    func_002CA280((char*)self + 0x20C, 2);
    func_002CA280((char*)self + 0x1F0, 2);
    func_002CA280((char*)self + 0x1D4, 2);
    func_002CA280((char*)self + 0x1B8, 2);
    func_002CA280((char*)self + 0x19C, 2);
    func_002CA280((char*)self + 0x180, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F7E0__FPv);
#ifdef SKIP_ASM
void* func_0024F7E0(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F800__FPv);
#ifdef SKIP_ASM
void* func_0024F800(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F820__FPv);
#ifdef SKIP_ASM
void* func_0024F820(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F840__FPv);
#ifdef SKIP_ASM
void* func_0024F840(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F860);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024F860(void* self, int flags)
{
    func_002CA280((char*)self + 0x398, 2);
    func_002CA280((char*)self + 0x364, 2);
    func_002CA280((char*)self + 0x330, 2);
    func_002CA280((char*)self + 0x2FC, 2);
    func_002CA280((char*)self + 0x2C8, 2);
    func_002CA280((char*)self + 0x298, 2);
    func_002CA280((char*)self + 0x264, 2);
    func_002CA280((char*)self + 0x230, 2);
    func_002CA280((char*)self + 0x1FC, 2);
    func_002CA280((char*)self + 0x1C8, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F940__FPv);
#ifdef SKIP_ASM
void* func_0024F940(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F960__FPv);
#ifdef SKIP_ASM
void* func_0024F960(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F980__FPv);
#ifdef SKIP_ASM
void* func_0024F980(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F9A0__FPv);
#ifdef SKIP_ASM
void* func_0024F9A0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F9C0__FPv);
#ifdef SKIP_ASM
void* func_0024F9C0(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024F9E0__FPv);
#ifdef SKIP_ASM
void* func_0024F9E0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FA00);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024FA00(void* self, int flags)
{
    func_002CA280((char*)self + 0x1C8, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FA78__FPv);
#ifdef SKIP_ASM
void* func_0024FA78(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FA98__FPv);
#ifdef SKIP_ASM
void* func_0024FA98(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FAB8);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024FAB8(void* self, int flags)
{
    func_002CA280((char*)self + 0x334, 2);
    func_002CA280((char*)self + 0x300, 2);
    func_002CA280((char*)self + 0x2CC, 2);
    func_002CA280((char*)self + 0x298, 2);
    func_002CA280((char*)self + 0x264, 2);
    func_002CA280((char*)self + 0x230, 2);
    func_002CA280((char*)self + 0x1FC, 2);
    func_002CA280((char*)self + 0x1C8, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FB80__FPv);
#ifdef SKIP_ASM
void* func_0024FB80(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FBA0__FPv);
#ifdef SKIP_ASM
void* func_0024FBA0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FBC0);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024FBC0(void* self, int flags)
{
    func_002CA280((char*)self + 0x2EC, 2);
    func_002CA280((char*)self + 0x2B8, 2);
    func_002CA280((char*)self + 0x284, 2);
    func_002CA280((char*)self + 0x254, 2);
    func_002CA280((char*)self + 0x224, 2);
    func_002CA280((char*)self + 0x1F4, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FC80__FPv);
#ifdef SKIP_ASM
void* func_0024FC80(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FCA0__FPv);
#ifdef SKIP_ASM
void* func_0024FCA0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FCC0__FPv);
#ifdef SKIP_ASM
void* func_0024FCC0(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FCE0__FPv);
#ifdef SKIP_ASM
void* func_0024FCE0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FD00);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024FD00(void* self, int flags)
{
    func_002CA280((char*)self + 0x2FC, 2);
    func_002CA280((char*)self + 0x2C8, 2);
    func_002CA280((char*)self + 0x294, 2);
    func_002CA280((char*)self + 0x260, 2);
    func_002CA280((char*)self + 0x22C, 2);
    func_002CA280((char*)self + 0x1F8, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FDC0__FPv);
#ifdef SKIP_ASM
void* func_0024FDC0(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FDE0__FPv);
#ifdef SKIP_ASM
void* func_0024FDE0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FE00);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024FE00(void* self, int flags)
{
    func_002CA280((char*)self + 0x294, 2);
    func_002CA280((char*)self + 0x260, 2);
    func_002CA280((char*)self + 0x22C, 2);
    func_002CA280((char*)self + 0x1F8, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FEA8__FPv);
#ifdef SKIP_ASM
void* func_0024FEA8(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FEC8__FPv);
#ifdef SKIP_ASM
void* func_0024FEC8(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FEE8__FPv);
#ifdef SKIP_ASM
void* func_0024FEE8(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FF08__FPv);
#ifdef SKIP_ASM
void* func_0024FF08(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FF28);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_0024FF28(void* self, int flags)
{
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FF90__FPv);
#ifdef SKIP_ASM
void* func_0024FF90(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FFB0__FPv);
#ifdef SKIP_ASM
void* func_0024FFB0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FFD0__FPv);
#ifdef SKIP_ASM
void* func_0024FFD0(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_0024FFF0__FPv);
#ifdef SKIP_ASM
void* func_0024FFF0(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250010__FPv);
#ifdef SKIP_ASM
void* func_00250010(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250030__FPv);
#ifdef SKIP_ASM
void* func_00250030(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250050__FPv);
#ifdef SKIP_ASM
void* func_00250050(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250070__FPv);
#ifdef SKIP_ASM
void* func_00250070(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250090);
#ifdef SKIP_ASM
extern "C" void func_00250090(void* self, int flags)
{
    func_002CA280((char*)self + 0x25C, 2);
    func_002CA280((char*)self + 0x22C, 2);
    func_002CA280((char*)self + 0x1FC, 2);
    func_002CA280((char*)self + 0x1C8, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250128__FPv);
#ifdef SKIP_ASM
void* func_00250128(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250148__FPv);
#ifdef SKIP_ASM
void* func_00250148(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250168__FPv);
#ifdef SKIP_ASM
void* func_00250168(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250188__FPv);
#ifdef SKIP_ASM
void* func_00250188(void* self)
{
    return func_002CBFD0(self);
}
#endif

extern "C" void* func_0024E8D8(int, int);

//99.38%
INCLUDE_ASM("main/debugmenu", func_002501A8__FPv);
#ifdef SKIP_ASM
void* func_002501A8(void* self)
{
    return func_0024E8D8(1, 0xffff);
}
#endif

extern "C" void* func_0024E8D8(int, int);

//99.38%
INCLUDE_ASM("main/debugmenu", func_002501C8__FPv);
#ifdef SKIP_ASM
void* func_002501C8(void* self)
{
    return func_0024E8D8(0, 0xffff);
}
#endif

INCLUDE_ASM("main/debugmenu", cAvalancheMenu_cAvalancheMenu);

//100%
INCLUDE_ASM("main/debugmenu", cAIVisualEffectsMainMenu_cAIVisualEffectsMainMenu);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0047FFE8[];
extern char D_0047FFB0[];
extern char D_004D1C88[];
extern char D_0047FFD0[];

extern "C" void* cAIVisualEffectsMainMenu_cAIVisualEffectsMainMenu(void* self)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0047FFE8;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x130), D_0047FFB0);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x14C), (void*)0x28);
    cSubMenuItem_cSubMenuItem((char*)self + 0x164, D_004D1C88, D_0047FFD0);
    cMenu_addItem(self, (char*)self + 0x164, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250A60__FPv);
#ifdef SKIP_ASM
void* func_00250A60(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00250A80__FPv);
#ifdef SKIP_ASM
void* func_00250A80(void* self)
{
    return func_002CBFD0(self);
}
#endif

INCLUDE_ASM("main/debugmenu", func_00250AA0);

//100%
INCLUDE_ASM("main/debugmenu", func_00250AE0);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_00250AE0(void* self, int flags)
{
    func_002CA280((char*)self + 0x77C, 2);
    func_002CA280((char*)self + 0x748, 2);
    func_002CA280((char*)self + 0x714, 2);
    func_002CA280((char*)self + 0x6E0, 2);
    func_002CA280((char*)self + 0x6B0, 2);
    func_002CA280((char*)self + 0x67C, 2);
    func_002CA280((char*)self + 0x648, 2);
    func_002CA280((char*)self + 0x614, 2);
    func_002CA280((char*)self + 0x5E0, 2);
    func_002CA280((char*)self + 0x5AC, 2);
    func_002CA280((char*)self + 0x578, 2);
    func_002CA280((char*)self + 0x544, 2);
    func_002CA280((char*)self + 0x514, 2);
    func_002CA280((char*)self + 0x4E0, 2);
    func_002CA280((char*)self + 0x4AC, 2);
    func_002CA280((char*)self + 0x478, 2);
    func_002CA280((char*)self + 0x444, 2);
    func_002CA280((char*)self + 0x410, 2);
    func_002CA280((char*)self + 0x3DC, 2);
    func_002CA280((char*)self + 0x3AC, 2);
    func_002CA280((char*)self + 0x37C, 2);
    func_002CA280((char*)self + 0x34C, 2);
    func_002CA280((char*)self + 0x31C, 2);
    func_002CA280((char*)self + 0x2E8, 2);
    func_002CA280((char*)self + 0x2B8, 2);
    func_002CA280((char*)self + 0x288, 2);
    func_002CA280((char*)self + 0x258, 2);
    func_002CA280((char*)self + 0x228, 2);
    func_002CA280((char*)self + 0x1F8, 2);
    func_002CA280((char*)self + 0x1C4, 2);
    func_002CA280((char*)self + 0x194, 2);
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

INCLUDE_ASM("main/debugmenu", func_00250CB0);

//100%
INCLUDE_ASM("main/debugmenu", func_002515F0__FPv);
#ifdef SKIP_ASM
void* func_002515F0(void* self)
{
    return func_002CBF60(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00251610__FPv);
#ifdef SKIP_ASM
void* func_00251610(void* self)
{
    return func_002CBFD0(self);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", func_00251630);
#ifdef SKIP_ASM
extern "C" void func_002CA280(void* p, int flags);
extern "C" void func_002CAA80(void* self, int flags);

extern "C" void func_00251630(void* self, int flags)
{
    func_002CA280((char*)self + 0x164, 2);
    func_002CA280((char*)self + 0x14C, 2);
    func_002CA280((char*)self + 0x130, 2);
    func_002CAA80(self, flags);
}
#endif

extern "C" void* func_00250CB0(int, int);

//99.38%
INCLUDE_ASM("main/debugmenu", func_00251690__FPv);
#ifdef SKIP_ASM
void* func_00251690(void* self)
{
    return func_00250CB0(1, 0xffff);
}
#endif

extern "C" void* func_00250CB0(int, int);

//99.38%
INCLUDE_ASM("main/debugmenu", func_002516B0__FPv);
#ifdef SKIP_ASM
void* func_002516B0(void* self)
{
    return func_00250CB0(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("main/debugmenu", MEM_initblock);
#ifdef SKIP_ASM
extern "C" void* MEM_initblock(void* self, int p1, void* p2, int p3, short p4, int p5, int p6)
{
    *(short*)self = 0x424d;
    *(short*)((char*)self + 0x2) = p4;
    *(int*)((char*)self + 0x4) = (int)p2;
    *(int*)((char*)self + 0x8) = p6;
    *(int*)((char*)self + 0xc) = p5;
    return (char*)p2 + 0x10;
}
#endif

INCLUDE_ASM("main/debugmenu", func_002516F0);

