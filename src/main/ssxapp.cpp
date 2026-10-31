#include "common.h"

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_cSSXApp);
#ifdef SKIP_ASM
extern "C" void* cAppMan_cAppMan(void* self);
extern "C" void* func_003E6448(void* dst, int c, int n);
extern int D_004A3E90;
extern void* D_0047D9C8[];

struct cSSXApp00226830 {
    char base[0x5C];
    void** vt;
    int f60;
    int f64;
    int f68;
    int f6C;
    int f70;
    int f74;
    char pad78[0xA8 - 0x78];
    char fA8[8];
    char fB0[8];
    char fB8[8];
    int fC0;
    int fC4;
    int fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    int fDC;
    int fE0;
    int fE4;
    int fE8;
    int arr[11];
    int f118;
};

extern "C" cSSXApp00226830* cSSXApp_cSSXApp(cSSXApp00226830* self)
{
    cAppMan_cAppMan(self);
    self->vt = D_0047D9C8;
    self->fC4 = D_004A3E90;
    self->fC8 = D_004A3E90;
    self->fCC = D_004A3E90;
    self->fD4 = 0;
    self->fD8 = 0;
    self->fDC = 0;
    self->fE0 = 0;
    self->fE4 = 0;
    self->fE8 = 0;
    int i;
    for (i = 0; i < 11; i++) {
        self->arr[i] = 0;
    }
    self->f118 = 0;
    self->f74 = 0;
    self->f68 = 0;
    self->f6C = 0;
    self->f70 = 0;
    self->f60 = 1;
    self->f64 = 1;
    func_003E6448(self->fA8, 0, 8);
    func_003E6448(self->fB8, 0, 8);
    func_003E6448(self->fB0, 0, 8);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_init);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is the game's tagged operator new(size, tag, flags, d); bound by asm label.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

class cPlayerMgr_6900;
extern "C" void func_00326A28(cPlayerMgr_6900* self);

struct sApp_6900 {
    char pad_0x0[0xA0];
    void* shape;    // 0xA0
};

struct sVE_6900 {
    short delta;
    short index;
    void* fn;
};

struct sGfx_6900 {
    char pad_0x0[0x10D8];
    sVE_6900* vt;   // 0x10D8
};

struct sColor_6900 {
    float r, g, b, a;
    sColor_6900() {}
    sColor_6900(const float& ar, const float& ag, const float& ab, const float& aa) : r(ar), g(ag), b(ab), a(aa) {}
};

struct sTint_6900 {
    int a;
    int b;
    int c;
    sColor_6900 col;
    sTint_6900() : a(0), b(0), c(0) { col = sColor_6900(1.0f, 1.0f, 1.0f, 1.0f); }
};

extern void* D_004A28A0;
extern void* D_004A28A8;
extern void* D_004A289C;
extern void* D_004A28AC;
extern char D_00479A40[];
extern char D_00479A50[];
extern char D_00479A60[];
extern char D_00479A70[];
extern char D_00479A80[];
extern char D_00479A90[];
extern char D_00479AA0[];
extern char D_0047AB40[];
extern char D_004A28B0[];
extern "C" void* func_002C7440();
extern "C" void* func_00375A08();
void cLightMan_construct();
void cBezierMan_construct();
extern "C" void cSSXApp_parseCommandLine(char* self, int argc, char** argv);
extern "C" void* SHAPE_locate(const char* name, void* list);
extern "C" void func_00369FF8(void* gfx);
void* func_00232328(void* p);
extern "C" void* func_001A3590(void* p);
extern "C" void func_001A3648(void* p);
extern "C" void* cGameModeMan_getGM();
struct cAppMan;
void cAppMan_setNextModule(cAppMan* self, unsigned int module);

typedef void (*V0Fn_6900)(char*);
typedef void (*V1Fn_6900)(char*, int);
typedef void* (*LoadFn_6900)(char*, void*, const char*, int, int, int);

extern "C" void cSSXApp_init(char* self, int argc, char** argv)
{
    D_004A28A8 = self;
    *(void**)(self + 0x9C) = func_002C7440();
    cPlayerMgr_6900* volatile pm = (cPlayerMgr_6900*)cMemMan_alloc(0x2EFC, D_00479A40, 0, 0);
    func_00326A28(pm);
    D_004A28A0 = pm;
    char* g = (char*)func_00375A08();
    D_004A289C = g;
    sVE_6900* vt = ((sGfx_6900*)g)->vt;
    ((V0Fn_6900)vt[2].fn)(g + vt[2].delta);
    cLightMan_construct();
    cBezierMan_construct();
    D_004A28AC = cMemMan_alloc(1, D_00479A50, 0, 0);
    int i;
    for (i = 0; i < 2; i++) {
        int* p = (int*)cMemMan_alloc(0x2A4, D_00479A60, 0, 0);
        ((int**)(self + 0xA8))[i] = p;
        *p = 0;
    }
    *(int*)(self + 0x84) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x7C) = 0;
    cSSXApp_parseCommandLine(self, argc, argv);
    char* g2 = (char*)D_004A289C;
    sVE_6900* vt2 = ((sGfx_6900*)g2)->vt;
    ((V1Fn_6900)vt2[44].fn)(g2 + vt2[44].delta, 0x100);
    char* g3 = (char*)D_004A289C;
    sVE_6900* vt3 = ((sGfx_6900*)g3)->vt;
    char* o = g3 + vt3[46].delta;
    void* r = SHAPE_locate(D_0047AB40, D_004A28B0);
    ((sApp_6900*)D_004A28A8)->shape = ((LoadFn_6900)vt3[46].fn)(o, r, D_00479A70, 0, 1, -1);
    func_00369FF8(D_004A289C);
    *(sTint_6900**)(self + 0xA4) = new (D_00479A80, 0, 0) sTint_6900;
    cAppMan_setNextModule((cAppMan*)self, (unsigned int)func_00232328(cMemMan_alloc(0xC, D_00479A90, 0x100, 0)));
    *(void**)(self + 0xC0) = cGameModeMan_getGM();
    void* m = func_001A3590(cMemMan_alloc(0x590, D_00479AA0, 0, 0));
    *(void**)(self + 0x11C) = m;
    func_001A3648(m);
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_loadInputMap);
#ifdef SKIP_ASM
struct sParseBuf_5F48 {
    int size;
    int cap;
    char* data;
};
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void cMemMan_free(void* p);
extern "C" void* func_00325F48(sParseBuf_5F48* self, char* path, int* outSize);
extern "C" void cInputMap_init(void* self, int count);
extern "C" void cInputMap_loadMapFile(void* self, void* a1, int a2);
extern "C" void cInputMap_compileMap(void* self, int idx, const char* src);
extern "C" void cInputMap_purgeMapFile(void* self);
extern char D_00479AB0[];
extern char D_00479AC0[];
extern char D_00479AD0[];
extern char D_00479AE0[];
extern char D_00479AF0[];
extern char D_00479B00[];
extern char D_00479B10[];
extern char D_00479B20[];
extern char D_00479B30[];
extern char D_00479B40[];
extern char D_00479B50[];
extern char D_00479B60[];
extern char D_00479B70[];
extern char D_00479B80[];
extern char D_00479B90[];
extern char D_004A28B8[];
extern char D_004A28C0[];
extern char D_00479BA0[];
extern char D_00479BB0[];
extern char D_00479BC0[];
extern char D_00479BD0[];
extern char D_00479BE0[];
extern char D_004A28C8[];
extern char D_00479BF0[];
extern char D_00479C00[];
extern char D_00479C10[];
extern char D_00479C28[];
extern char D_00479C38[];
extern char D_00479C48[];
extern char D_00479C58[];
extern char D_00479C68[];
extern char D_00479C78[];
extern char D_004A28D0[];
extern char D_004A28D8[];
extern char D_004A28E0[];
extern char D_004A28E8[];
extern char D_004A28F0[];
extern char D_004A28F8[];
extern char D_004A2900[];
extern char D_004A2908[];
extern char D_004A2910[];
extern char D_004A2918[];
extern char D_004A2920[];
extern char D_004A2928[];
extern char D_004A2930[];
extern char D_004A2938[];
extern char D_004A2940[];
extern char D_00479C88[];
extern char D_00479C98[];
extern char D_00479CA8[];
extern char D_00479CB8[];
extern char D_00479CC8[];
extern char D_00479CD8[];
extern char D_00479CE8[];
extern char D_00479CF8[];
extern char D_00479D10[];
extern char D_00479D28[];
extern char D_00479D40[];
extern char D_00479D58[];
extern char D_00479D70[];
extern char D_00479D88[];
extern char D_00479DA0[];
extern char D_004A2948[];
extern char D_00479DB0[];
extern char D_00479DC0[];
extern char D_004A2950[];
extern char D_00479DD0[];
extern char D_00479DE0[];
extern char D_00479DF0[];
extern char D_00479E00[];
extern char D_00479E10[];
extern char D_00479E28[];
extern char D_00479E40[];
extern char D_00479E58[];
extern char D_00479E68[];
extern char D_00479E80[];
extern char D_00479E98[];
extern char D_00479EA8[];
extern char D_00479EB8[];
extern char D_00479ED0[];
extern char D_00479EE0[];
extern char D_00479EF0[];
extern char D_00479F08[];
extern char D_00479F18[];
extern char D_00479F28[];
extern char D_00479F38[];
extern char D_00479F48[];
extern char D_00479F60[];
extern char D_00479F70[];
extern char D_00479F80[];
extern char D_00479F90[];
extern char D_00479FA0[];
extern char D_00479FB8[];
extern char D_00479FD0[];
extern char D_00479FE0[];
extern char D_00479FF0[];
extern char D_0047A008[];
extern char D_0047A020[];
extern char D_0047A038[];
extern char D_0047A050[];
extern char D_0047A068[];
extern char D_0047A080[];
extern char D_0047A098[];
extern char D_0047A0A8[];
extern char D_0047A0B8[];
extern char D_0047A0C8[];
extern char D_0047A0D8[];
extern char D_0047A0E8[];
extern char D_0047A100[];
extern char D_0047A110[];
extern char D_0047A128[];
extern char D_0047A138[];
extern char D_004A2958[];
extern char D_004A2960[];
extern char D_0047A148[];
extern char D_004A2968[];
extern char D_004A2970[];
extern char D_004A2978[];
extern char D_004A2980[];
extern char D_004A2988[];
extern char D_004A2990[];
extern char D_004A2998[];
extern char D_0047A158[];
extern char D_004A29A0[];
extern char D_0047A168[];
extern char D_0047A178[];
extern char D_004A29A8[];
extern char D_0047A188[];
extern char D_0047A198[];
extern char D_0047A1A8[];
extern char D_0047A1B8[];
extern char D_0047A1C8[];
extern char D_0047A1D8[];
extern char D_0047A1E8[];
extern char D_0047A1F8[];
extern char D_0047A208[];
extern char D_0047A218[];
extern char D_0047A228[];
extern char D_0047A238[];
extern char D_0047A248[];
extern char D_0047A258[];
extern char D_0047A268[];
extern char D_0047A278[];
extern char D_0047A288[];
extern char D_0047A298[];
extern char D_0047A2A8[];
extern char D_0047A2B8[];
extern char D_0047A2C8[];
extern char D_0047A2D8[];
extern char D_0047A2E8[];
extern char D_0047A2F8[];
extern char D_0047A308[];
extern char D_0047A318[];
extern char D_0047A328[];
extern char D_0047A338[];
extern char D_0047A348[];
extern char D_0047A358[];
extern char D_0047A368[];
extern char D_0047A380[];
extern char D_0047A398[];
extern char D_0047A3A8[];
extern char D_0047A3B8[];
extern char D_0047A3C8[];
extern char D_0047A3E0[];
extern char D_0047A3F8[];
extern char D_0047A410[];
extern char D_0047A428[];
extern char D_0047A440[];
extern char D_0047A460[];
extern char D_0047A480[];
extern char D_0047A4A0[];
extern char D_0047A4B8[];
extern char D_0047A4D8[];
extern char D_0047A4F8[];
extern char D_0047A510[];
extern char D_0047A530[];
extern char D_0047A550[];
extern char D_0047A578[];
extern char D_0047A598[];
extern char D_0047A5B8[];
extern char D_0047A5D8[];
extern char D_0047A5F8[];
extern char D_0047A608[];
extern char D_0047A618[];
extern char D_0047A630[];
extern char D_0047A640[];
extern char D_0047A650[];
extern char D_0047A660[];
extern char D_0047A670[];
extern char D_0047A680[];
extern char D_0047A690[];
extern char D_0047A6A0[];
extern char D_0047A6B8[];
extern char D_0047A6D0[];
extern char D_0047A6E8[];
extern char D_0047A700[];
extern char D_0047A718[];
extern char D_0047A728[];
extern char D_0047A740[];
extern char D_0047A758[];
extern char D_0047A770[];
extern char D_0047A788[];
extern char D_0047A798[];
extern char D_0047A7A8[];
extern char D_0047A7B8[];
extern char D_0047A7C8[];

extern "C" void* cSSXApp_loadInputMap(void* self, char* path)
{
    sParseBuf_5F48 buf;
    int size;
    void* data = func_00325F48(&buf, path, &size);
    void* map = cMemMan_alloc(0x18, D_00479AB0, 0, 0);
    cInputMap_init(map, 0xCD);
    cInputMap_loadMapFile(map, data, size);
    if (data != 0) {
        cMemMan_free(data);
    }
    cInputMap_compileMap(map, 0, D_00479AC0);
    cInputMap_compileMap(map, 1, D_00479AD0);
    cInputMap_compileMap(map, 2, D_00479AE0);
    cInputMap_compileMap(map, 3, D_00479AF0);
    cInputMap_compileMap(map, 4, D_00479B00);
    cInputMap_compileMap(map, 5, D_00479B10);
    cInputMap_compileMap(map, 6, D_00479B20);
    cInputMap_compileMap(map, 7, D_00479B30);
    cInputMap_compileMap(map, 8, D_00479B40);
    cInputMap_compileMap(map, 9, D_00479B50);
    cInputMap_compileMap(map, 10, D_00479B60);
    cInputMap_compileMap(map, 11, D_00479B70);
    cInputMap_compileMap(map, 12, D_00479B80);
    cInputMap_compileMap(map, 13, D_00479B90);
    cInputMap_compileMap(map, 14, D_004A28B8);
    cInputMap_compileMap(map, 15, D_004A28C0);
    cInputMap_compileMap(map, 16, D_00479BA0);
    cInputMap_compileMap(map, 17, D_00479BB0);
    cInputMap_compileMap(map, 18, D_00479BC0);
    cInputMap_compileMap(map, 19, D_00479BD0);
    cInputMap_compileMap(map, 20, D_00479BE0);
    cInputMap_compileMap(map, 21, D_004A28C8);
    cInputMap_compileMap(map, 22, D_00479BF0);
    cInputMap_compileMap(map, 23, D_00479C00);
    cInputMap_compileMap(map, 24, D_00479C10);
    cInputMap_compileMap(map, 25, D_00479C28);
    cInputMap_compileMap(map, 26, D_00479C38);
    cInputMap_compileMap(map, 27, D_00479C48);
    cInputMap_compileMap(map, 28, D_00479C58);
    cInputMap_compileMap(map, 29, D_00479C68);
    cInputMap_compileMap(map, 30, D_00479C78);
    cInputMap_compileMap(map, 31, D_004A28D0);
    cInputMap_compileMap(map, 32, D_004A28D8);
    cInputMap_compileMap(map, 33, D_004A28E0);
    cInputMap_compileMap(map, 34, D_004A28E8);
    cInputMap_compileMap(map, 35, D_004A28F0);
    cInputMap_compileMap(map, 36, D_004A28F8);
    cInputMap_compileMap(map, 37, D_004A2900);
    cInputMap_compileMap(map, 38, D_004A2908);
    cInputMap_compileMap(map, 39, D_004A2910);
    cInputMap_compileMap(map, 40, D_004A2918);
    cInputMap_compileMap(map, 41, D_004A2920);
    cInputMap_compileMap(map, 42, D_004A2928);
    cInputMap_compileMap(map, 43, D_004A2930);
    cInputMap_compileMap(map, 44, D_004A2938);
    cInputMap_compileMap(map, 45, D_004A2940);
    cInputMap_compileMap(map, 46, D_00479C88);
    cInputMap_compileMap(map, 47, D_00479C98);
    cInputMap_compileMap(map, 48, D_00479CA8);
    cInputMap_compileMap(map, 49, D_00479CB8);
    cInputMap_compileMap(map, 50, D_00479CC8);
    cInputMap_compileMap(map, 51, D_00479CD8);
    cInputMap_compileMap(map, 52, D_00479CE8);
    cInputMap_compileMap(map, 53, D_00479CF8);
    cInputMap_compileMap(map, 54, D_00479D10);
    cInputMap_compileMap(map, 55, D_00479D28);
    cInputMap_compileMap(map, 56, D_00479D40);
    cInputMap_compileMap(map, 57, D_00479D58);
    cInputMap_compileMap(map, 58, D_00479D70);
    cInputMap_compileMap(map, 59, D_00479D88);
    cInputMap_compileMap(map, 60, D_00479DA0);
    cInputMap_compileMap(map, 61, D_004A2948);
    cInputMap_compileMap(map, 62, D_00479DB0);
    cInputMap_compileMap(map, 63, D_00479DC0);
    cInputMap_compileMap(map, 64, D_004A2950);
    cInputMap_compileMap(map, 65, D_00479DD0);
    cInputMap_compileMap(map, 66, D_00479DE0);
    cInputMap_compileMap(map, 67, D_00479DF0);
    cInputMap_compileMap(map, 68, D_00479E00);
    cInputMap_compileMap(map, 69, D_00479E10);
    cInputMap_compileMap(map, 70, D_00479E28);
    cInputMap_compileMap(map, 71, D_00479E40);
    cInputMap_compileMap(map, 72, D_00479E58);
    cInputMap_compileMap(map, 73, D_00479E68);
    cInputMap_compileMap(map, 74, D_00479E80);
    cInputMap_compileMap(map, 75, D_00479E98);
    cInputMap_compileMap(map, 76, D_00479EA8);
    cInputMap_compileMap(map, 77, D_00479EB8);
    cInputMap_compileMap(map, 78, D_00479ED0);
    cInputMap_compileMap(map, 79, D_00479EE0);
    cInputMap_compileMap(map, 80, D_00479EF0);
    cInputMap_compileMap(map, 81, D_00479F08);
    cInputMap_compileMap(map, 82, D_00479F18);
    cInputMap_compileMap(map, 83, D_00479F28);
    cInputMap_compileMap(map, 84, D_00479F38);
    cInputMap_compileMap(map, 85, D_00479F48);
    cInputMap_compileMap(map, 86, D_00479F60);
    cInputMap_compileMap(map, 87, D_00479F70);
    cInputMap_compileMap(map, 88, D_00479F80);
    cInputMap_compileMap(map, 89, D_00479F90);
    cInputMap_compileMap(map, 90, D_00479FA0);
    cInputMap_compileMap(map, 91, D_00479FB8);
    cInputMap_compileMap(map, 92, D_00479FD0);
    cInputMap_compileMap(map, 93, D_00479FE0);
    cInputMap_compileMap(map, 94, D_00479FF0);
    cInputMap_compileMap(map, 95, D_0047A008);
    cInputMap_compileMap(map, 96, D_0047A020);
    cInputMap_compileMap(map, 97, D_0047A038);
    cInputMap_compileMap(map, 98, D_0047A050);
    cInputMap_compileMap(map, 99, D_0047A068);
    cInputMap_compileMap(map, 100, D_0047A080);
    cInputMap_compileMap(map, 101, D_0047A098);
    cInputMap_compileMap(map, 102, D_0047A0A8);
    cInputMap_compileMap(map, 103, D_0047A0B8);
    cInputMap_compileMap(map, 104, D_0047A0C8);
    cInputMap_compileMap(map, 105, D_0047A0D8);
    cInputMap_compileMap(map, 106, D_0047A0E8);
    cInputMap_compileMap(map, 107, D_0047A100);
    cInputMap_compileMap(map, 108, D_0047A110);
    cInputMap_compileMap(map, 109, D_0047A128);
    cInputMap_compileMap(map, 110, D_0047A138);
    cInputMap_compileMap(map, 111, D_004A2958);
    cInputMap_compileMap(map, 112, D_004A2960);
    cInputMap_compileMap(map, 113, D_0047A148);
    cInputMap_compileMap(map, 114, D_004A2968);
    cInputMap_compileMap(map, 115, D_004A2970);
    cInputMap_compileMap(map, 116, D_004A2978);
    cInputMap_compileMap(map, 117, D_004A2980);
    cInputMap_compileMap(map, 118, D_004A2988);
    cInputMap_compileMap(map, 119, D_004A2990);
    cInputMap_compileMap(map, 120, D_004A2998);
    cInputMap_compileMap(map, 121, D_0047A158);
    cInputMap_compileMap(map, 122, D_004A29A0);
    cInputMap_compileMap(map, 123, D_0047A168);
    cInputMap_compileMap(map, 124, D_0047A178);
    cInputMap_compileMap(map, 125, D_004A29A8);
    cInputMap_compileMap(map, 126, D_0047A188);
    cInputMap_compileMap(map, 127, D_0047A198);
    cInputMap_compileMap(map, 128, D_0047A1A8);
    cInputMap_compileMap(map, 129, D_0047A1B8);
    cInputMap_compileMap(map, 130, D_0047A1C8);
    cInputMap_compileMap(map, 131, D_0047A1D8);
    cInputMap_compileMap(map, 132, D_0047A1E8);
    cInputMap_compileMap(map, 133, D_0047A1F8);
    cInputMap_compileMap(map, 134, D_0047A208);
    cInputMap_compileMap(map, 135, D_0047A218);
    cInputMap_compileMap(map, 136, D_0047A228);
    cInputMap_compileMap(map, 137, D_0047A238);
    cInputMap_compileMap(map, 138, D_0047A248);
    cInputMap_compileMap(map, 139, D_0047A258);
    cInputMap_compileMap(map, 140, D_0047A268);
    cInputMap_compileMap(map, 141, D_0047A278);
    cInputMap_compileMap(map, 142, D_0047A288);
    cInputMap_compileMap(map, 143, D_0047A298);
    cInputMap_compileMap(map, 144, D_0047A2A8);
    cInputMap_compileMap(map, 145, D_0047A2B8);
    cInputMap_compileMap(map, 146, D_0047A2C8);
    cInputMap_compileMap(map, 147, D_0047A2D8);
    cInputMap_compileMap(map, 148, D_0047A2E8);
    cInputMap_compileMap(map, 149, D_0047A2F8);
    cInputMap_compileMap(map, 150, D_0047A308);
    cInputMap_compileMap(map, 151, D_0047A318);
    cInputMap_compileMap(map, 152, D_0047A328);
    cInputMap_compileMap(map, 153, D_0047A338);
    cInputMap_compileMap(map, 154, D_0047A348);
    cInputMap_compileMap(map, 155, D_0047A358);
    cInputMap_compileMap(map, 156, D_0047A368);
    cInputMap_compileMap(map, 157, D_0047A380);
    cInputMap_compileMap(map, 158, D_0047A398);
    cInputMap_compileMap(map, 159, D_0047A3A8);
    cInputMap_compileMap(map, 160, D_0047A3B8);
    cInputMap_compileMap(map, 161, D_0047A3C8);
    cInputMap_compileMap(map, 162, D_0047A3E0);
    cInputMap_compileMap(map, 163, D_0047A3F8);
    cInputMap_compileMap(map, 164, D_0047A410);
    cInputMap_compileMap(map, 165, D_0047A428);
    cInputMap_compileMap(map, 166, D_0047A440);
    cInputMap_compileMap(map, 167, D_0047A460);
    cInputMap_compileMap(map, 168, D_0047A480);
    cInputMap_compileMap(map, 169, D_0047A4A0);
    cInputMap_compileMap(map, 170, D_0047A4B8);
    cInputMap_compileMap(map, 171, D_0047A4D8);
    cInputMap_compileMap(map, 172, D_0047A4F8);
    cInputMap_compileMap(map, 173, D_0047A510);
    cInputMap_compileMap(map, 174, D_0047A530);
    cInputMap_compileMap(map, 175, D_0047A550);
    cInputMap_compileMap(map, 176, D_0047A578);
    cInputMap_compileMap(map, 177, D_0047A598);
    cInputMap_compileMap(map, 178, D_0047A5B8);
    cInputMap_compileMap(map, 179, D_0047A5D8);
    cInputMap_compileMap(map, 180, D_0047A5F8);
    cInputMap_compileMap(map, 181, D_0047A608);
    cInputMap_compileMap(map, 182, D_0047A618);
    cInputMap_compileMap(map, 183, D_0047A630);
    cInputMap_compileMap(map, 184, D_0047A640);
    cInputMap_compileMap(map, 185, D_0047A650);
    cInputMap_compileMap(map, 186, D_0047A660);
    cInputMap_compileMap(map, 187, D_0047A670);
    cInputMap_compileMap(map, 188, D_0047A680);
    cInputMap_compileMap(map, 189, D_0047A690);
    cInputMap_compileMap(map, 190, D_0047A6A0);
    cInputMap_compileMap(map, 191, D_0047A6B8);
    cInputMap_compileMap(map, 192, D_0047A6D0);
    cInputMap_compileMap(map, 193, D_0047A6E8);
    cInputMap_compileMap(map, 194, D_0047A700);
    cInputMap_compileMap(map, 195, D_0047A718);
    cInputMap_compileMap(map, 196, D_0047A728);
    cInputMap_compileMap(map, 197, D_0047A740);
    cInputMap_compileMap(map, 198, D_0047A758);
    cInputMap_compileMap(map, 199, D_0047A770);
    cInputMap_compileMap(map, 200, D_0047A788);
    cInputMap_compileMap(map, 201, D_0047A798);
    cInputMap_compileMap(map, 202, D_0047A7A8);
    cInputMap_compileMap(map, 203, D_0047A7B8);
    cInputMap_compileMap(map, 204, D_0047A7C8);
    cInputMap_purgeMapFile(map);
    return map;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_parseCommandLine);
#ifdef SKIP_ASM
struct cBXString {
    char* str;
    cBXString() {}
    cBXString(const cBXString& o);
};

extern "C" void* cBXString_cBXString2(cBXString* self, const char* str);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" cBXString* cBXString_cBXString5(cBXString* self, cBXString* other, int n);
extern "C" cBXString* func_00319028(cBXString* self, cBXString* other, int n);
extern "C" void* cBXString_operatorE(void* self, void* other);
extern "C" void cBXString__cBXString(void* self, int flags);
int cBXString_FindFirstOf(cBXString* self, char ch);
int cBXString_FindLastOf(cBXString* self, char ch, int len);
extern "C" int func_0041AA88(const char* a, const char* b);
extern int D_004A4540;
extern char D_004A29B0[];
extern char D_004A29B8[];
extern char D_004A29C0[];
extern char D_0047A7D8[];
extern char D_0047A7E8[];
extern char D_0047A7F8[];

#define MAX_7BF0(x, y) ((x) > (y) ? (x) : (y))

// PORT: cBXString keeps its length in a header 8 bytes before the text (pointer held in int).
extern "C" void cSSXApp_parseCommandLine(char* self, int argc, char** argv)
{
    int i = 1;
    while (i < argc) {
        if (argv[i][0] == '-') {
            char* opt = argv[i] + 1;
            if (func_0041AA88(opt, D_004A29B0) == 0) {
                i++;
                if (i >= argc) {
                    break;
                }
                cBXString s;
                cBXString_cBXString2(&s, argv[i]);
                int a = cBXString_FindFirstOf(&s, '/');
                int b = cBXString_FindFirstOf(&s, '\\');
                int c = cBXString_FindFirstOf(&s, ':');
                int p = MAX_7BF0(a, MAX_7BF0(b, c));
                if (p >= 0) {
                    cBXString t;
                    func_00319028(&t, &s, *(int*)((int)s.str - 8) - p - 1);
                    cBXString_operatorE(&s, &t);
                    cBXString__cBXString(&t, 2);
                }
                int dot = cBXString_FindLastOf(&s, '.', 0);
                if (dot >= 0) {
                    cBXString t;
                    cBXString_cBXString5(&t, &s, dot);
                    cBXString_operatorE(&s, &t);
                    cBXString__cBXString(&t, 2);
                }
                cBXString_operatorE(self + 0xCC, &s);
                cBXString__cBXString(&s, 2);
            } else if (func_0041AA88(opt, D_0047A7D8) == 0) {
                i++;
                if (i >= argc) {
                    break;
                }
                cBXString_cBXString4(self + 0xC4, argv[i]);
            } else if (func_0041AA88(opt, D_0047A7E8) == 0) {
                i++;
                if (i >= argc) {
                    break;
                }
                cBXString_cBXString4(self + 0xC8, argv[i]);
            } else if (func_0041AA88(opt, D_004A29B8) == 0) {
                *(int*)(self + 0x60) = 1;
            } else if (func_0041AA88(opt, D_004A29C0) == 0) {
                *(int*)(self + 0x64) = 0;
            } else if (func_0041AA88(opt, D_0047A7F8) == 0) {
                *(int*)(self + 0x74) = 1;
            }
        }
        i++;
    }
    D_004A4540 = *(int*)(self + 0x64) == 0;
}
#endif

extern "C" int func_00326C60(void* mgr);
extern void* D_004A28A0;

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_flush__Fv);
#ifdef SKIP_ASM
int cSSXApp_flush()
{
    if (D_004A28A0 != 0) {
        return func_00326C60(D_004A28A0);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_preUpdate);
#ifdef SKIP_ASM
extern "C" int func_00326B48(void* pad);
extern "C" void func_00255A20(void* p);
extern "C" void func_002668E8(void* p);
extern "C" int func_00326CA0(void* self, int i);
extern "C" void* func_00326CC8(void* self, int i);
extern "C" void func_00321298(void* target, int a, void* data);
extern void* D_004A28A0;
extern void* D_004A2EB8;
extern void* D_004A33F0;

extern "C" int cSSXApp_preUpdate(void* self)
{
    if (D_004A28A0 != 0 && func_00326B48(D_004A28A0) != 0) {
        if (D_004A2EB8 != 0) {
            func_00255A20(D_004A2EB8);
        }
        if (D_004A33F0 != 0) {
            func_002668E8(D_004A33F0);
        }
        int i;
        for (i = 0; i < 2; i++) {
            int a = func_00326CA0(D_004A28A0, i);
            void* d = func_00326CC8(D_004A28A0, i);
            func_00321298(((void**)((char*)self + 0xA8))[i], a, d);
        }
        return 1;
    }
    return 0;
}
#endif

extern "C" void func_00326B88(void* mgr);

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_timerCallback__Fv);
#ifdef SKIP_ASM
void cSSXApp_timerCallback()
{
    if (D_004A28A0 != 0) {
        func_00326B88(D_004A28A0);
    }
}
#endif

void* cMCOverlayManager_getManager();

//100%
INCLUDE_ASM("main/ssxapp", func_00227F80);
#ifdef SKIP_ASM
extern "C" void* func_00227F80(void* app)
{
    return cMCOverlayManager_getManager();
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00227FA0);
#ifdef SKIP_ASM
extern "C" int func_0023C850();

extern "C" void func_00227FA0(void) {
    func_0023C850();
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_purge);
#ifdef SKIP_ASM
void operator_delete(int* p);
extern "C" void func_00398438(void* p);
extern "C" void func_00326A68(void* p);
extern "C" void func_00278308(void* p);
extern "C" int func_003DEDC0(void* handle, int arg);
// PORT: func_002B4B48 is declared (void*) but never reads it; this caller passes nothing.
extern "C" void func_002B4B48_noarg() __asm__("func_002B4B48");
extern "C" void func_00284C28();
extern "C" void func_0014DD98(void* p);
extern "C" void func_002380E8(void* p);
extern "C" void func_001A35E8(void* p, int flags);
extern void* D_004A28A0;
extern void* D_004A28A4;
extern void* D_004A28A8;
extern void* D_004A289C;

struct sVEPurge0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVEPurge {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sSSXAppPurge {
    char pad_0x00[0x78];
    void* f78;          // 0x78
    char pad_0x7C[0xC];
    int* f88;           // 0x88
    char pad_0x8C[0x10];
    char* f9C;          // 0x9C
    char pad_0xA0[0x18];
    int* fB8[2];        // 0xB8
    void* fC0;          // 0xC0
    char pad_0xC4[0x10];
    void* fD4;          // 0xD4
    void* fD8;          // 0xD8
    void* fDC;          // 0xDC
    void* fE0;          // 0xE0
    void* fE4;          // 0xE4
    void* fE8;          // 0xE8
    void* fEC[11];      // 0xEC
    void* f118;         // 0x118
    void* f11C;         // 0x11C
};

extern "C" void cSSXApp_purge(sSSXAppPurge* self)
{
    int i;
    for (i = 0; i < 2; i++) {
        if (self->fB8[i]) {
            operator_delete(self->fB8[i]);
        }
    }
    int* q = self->f88;
    if (q) {
        func_00398438(q);
        operator_delete(q);
    }
    int* mgr = (int*)D_004A28A0;
    self->f88 = 0;
    D_004A28A0 = 0;
    func_00326A68(mgr);
    operator_delete(mgr);
    if (D_004A28A4) {
        func_00278308(D_004A28A4);
        char* o = (char*)D_004A28A4;
        if (o) {
            sVEPurge* vt = *(sVEPurge**)(o + 0x2A8);
            vt[1].fn(o + vt[1].delta, 3);
        }
        D_004A28A4 = 0;
    }
    {
        char* g = (char*)D_004A289C;
        sVEPurge0* vt = *(sVEPurge0**)(g + 0x10D8);
        vt[3].fn(g + vt[3].delta);
    }
    {
        char* g = (char*)D_004A289C;
        if (g) {
            sVEPurge* vt = *(sVEPurge**)(g + 0x10D8);
            vt[1].fn(g + vt[1].delta, 3);
        }
    }
    D_004A289C = 0;
    if (self->fE4) func_003DEDC0(self->fE4, 100);
    if (self->fE8) func_003DEDC0(self->fE8, 100);
    for (i = 0; i < 11; i++) {
        if (self->fEC[i]) {
            func_003DEDC0(self->fEC[i], 100);
        }
    }
    if (self->f118) func_003DEDC0(self->f118, 100);
    func_002B4B48_noarg();
    func_00284C28();
    if (self->fD4) func_003DEDC0(self->fD4, 100);
    if (self->fD8) func_003DEDC0(self->fD8, 100);
    if (self->fDC) func_003DEDC0(self->fDC, 100);
    if (self->fE0) func_003DEDC0(self->fE0, 100);
    if (self->f78) func_0014DD98(self->f78);
    func_002380E8(self->fC0);
    if (self->f11C) func_001A35E8(self->f11C, 3);
    {
        char* m = self->f9C;
        if (m) {
            sVEPurge* vt = *(sVEPurge**)(m + 0x34);
            vt[1].fn(m + vt[1].delta, 3);
        }
    }
    D_004A28A8 = 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_startGameLoad);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0022E968(void* self);
struct cAppMan;
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
extern "C" void* cGameModeMan_getGM();
extern char D_0047A808[];

extern "C" void cSSXApp_startGameLoad(void* self)
{
    void* m = func_0022E968(cMemMan_alloc(0x22C, D_0047A808, 0, 0));
    *(void**)((char*)self + 0x84) = m;
    cAppMan_setNextModule((cAppMan*)self, (unsigned int)m);
    *(void**)((char*)self + 0xC0) = cGameModeMan_getGM();
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00228238);
#ifdef SKIP_ASM
extern int D_004A203C;
extern char D_0047A818[];
extern "C" void* func_001A1CE8(void* p);
extern "C" void* func_0017F7B8(void* p);

extern "C" void func_00228238(void* self)
{
    D_004A203C = 0;
    if (*(int*)((char*)self + 0x60) != 0) {
        void* m = func_001A1CE8(cMemMan_alloc(0xB5AE0, D_0047A818, 0, 0));
        *(void**)((char*)self + 0x7C) = m;
        cAppMan_setNextModule((cAppMan*)self, (unsigned int)m);
    } else {
        void* m = func_0017F7B8(cMemMan_alloc(0x238, D_0047A818, 0, 0));
        *(void**)((char*)self + 0x80) = m;
        cAppMan_setNextModule((cAppMan*)self, (unsigned int)m);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_initload);
#ifdef SKIP_ASM
extern "C" void initOnline();
extern "C" int BXFILE_exists(const char* name);
extern "C" int func_003DED50(const char* name, int a, int b, void* dst);
extern "C" void func_00256188();
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00277F20(void* p);
extern "C" void func_00278210(void* p);
void func_00244400(void* p, int v);
void func_00244408(void* p, int v);
int GetHashValue32(char* s);
extern "C" void func_003984B0(void* a, int idx, const char* s, int hash);
extern "C" void cUIFontInterface_loadFonts(void* p);
extern "C" void* cBE_getBE();
void* cBE_getInterface(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00228C08(void* self);
extern "C" void cSSXApp_initLocale(void* self);
extern "C" void func_00311870();
extern "C" void* func_00314D98(void* p);
extern "C" void func_00314DD8(void* p);
extern "C" void* func_00311048(void* p);
extern "C" void* func_0028B180();
extern "C" void* func_00289D08(void* a, int b);
extern "C" void SSXAUDIO_Init(void* p);
extern "C" void func_0031A6B8();
extern "C" void func_00287410(void* a, int b);
extern "C" void func_00287488(void* a, int b);
extern "C" void func_00287520(void* a, int b);
extern "C" void func_00287558(void* a, int b);
extern "C" void func_002875D0(void* a, int b);
void WORLDTRIGGERMANAGER_Init();
extern "C" int func_004165A8(int a, const char* s);

extern char D_0047A828[];
extern char D_0047A840[];
extern char D_0047A858[];
extern char D_0047A870[];
extern char D_0047A888[];
extern char D_0047A8D0[];
extern char D_0047A8E0[];
extern char D_0047A8F8[];
extern char D_0047A910[];
extern char D_0047A928[];
extern char D_0047A940[];
extern char D_0047A958[];
extern char D_0047A968[];
extern char D_004A29D0[];
extern char D_004A29D8[];
extern char D_004A29E0[];
extern char D_004A29E8[];
extern char* D_00442100[];
extern char* D_004A29C8;
extern char* D_004A29CC;
extern void* D_004A28A4;
extern int D_004A4CB8;

struct sOpt_initload {
    unsigned int f0 : 4;
    unsigned char f4 : 4;
    unsigned int f8 : 4;
    unsigned int f12 : 2;
    unsigned int f14 : 2;
    unsigned int pad : 16;
    int data[0x284 / 4];
};
extern sOpt_initload D_00535610_il __asm__("D_00535610");

static inline int optA_il(sOpt_initload o) { return o.f0; }
static inline int optB_il(sOpt_initload o) { return o.f8; }
static inline int optC_il(sOpt_initload o) { return o.f4; }
static inline int optD_il(sOpt_initload o) { return (((int*)&o)[0] >> 17) & 1; }
static inline int optE_il(sOpt_initload o) { return ((short)(((int*)&o)[0] >> 16)) & 1; }

struct sE_initload {
    int a, b, c;
    sE_initload() { a = 0; b = 0; c = 0; }
};
struct sTbl_initload {
    int f0;
    sE_initload e[4];
    char f34;
    int f38, f3C, f40;
    sTbl_initload() : f0(0) { f34 = 0; f38 = 0; f3C = 0; f40 = 0; }
};

struct sSSXApp_initload {
    char pad0[0x78];
    void* f78;
    char pad7C[0x88 - 0x7C];
    sTbl_initload* f88;
    void* f8C;
    void* f90;
    void* f94;
    char pad98[0xA8 - 0x98];
    int fA8[2];
    void* fB0[2];
    int fB8[2];
    char padC0[0xCC - 0xC0];
    int fCC;
    char padD0[0xD4 - 0xD0];
    int fD4, fD8, fDC, fE0, fE4, fE8;
    int fEC[11];
    int f118;
};

extern "C" void cSSXApp_initload(sSSXApp_initload* self)
{
    initOnline();
    if (BXFILE_exists(D_0047A828)) func_003DED50(D_0047A828, 0, 100, &self->fD8);
    if (BXFILE_exists(D_0047A840)) func_003DED50(D_0047A840, 0, 100, &self->fDC);
    if (BXFILE_exists(D_0047A858)) func_003DED50(D_0047A858, 0, 100, &self->fD4);
    if (BXFILE_exists(D_0047A870)) func_003DED50(D_0047A870, 0, 100, &self->fE0);
    func_00256188();
    func_003DED50(D_0047A888, 0, 100, &self->fE4);
    func_003DED50(D_004A29C8, 0, 100, &self->fE8);
    for (int i = 0; i < 11; i++) {
        func_003DED50(D_00442100[i], 0, 100, &self->fEC[i]);
    }
    func_003DED50(D_004A29CC, 0, 100, &self->f118);
    D_004A28A4 = func_00277F20(cMemMan_alloc(0xA50, D_0047A8D0, 0, 0));
    func_00278210(D_004A28A4);
    self->fB8[0] = (int)cSSXApp_loadInputMap(self, D_0047A8E0);
    self->fB8[1] = (int)cSSXApp_loadInputMap(self, D_0047A8F8);
    void** pb = self->fB0;
    int* pa = self->fA8;
    for (int j = 0; j < 2; j++) {
        void* p = cMemMan_alloc(8, D_004A29D0, 0, 0);
        int m = self->fB8[0];
        func_00244400(p, pa[j]);
        func_00244408(p, m);
        pb[j] = p;
    }
    sTbl_initload** pp = &self->f88;
    *pp = new (D_0047A910, 0, 0) sTbl_initload;
    func_003984B0(self->f88, 0, D_0047A928, GetHashValue32(D_004A29D8));
    func_003984B0(self->f88, 1, D_0047A940, GetHashValue32(D_004A29E0));
    cUIFontInterface_loadFonts(self->f88);
    self->f78 = cBE_getBE();
    func_00228C08(self);
    cSSXApp_initLocale(self);
    func_00311870();
    self->f94 = func_00314D98(cMemMan_alloc(0x1848, D_0047A958, 0, 0));
    func_00314DD8(self->f94);
    self->f90 = func_00311048(cMemMan_alloc(0x3FC, D_0047A968, 0, 0));
    cBE_getInterface(cBE_getBE(), 4);
    SSXAUDIO_Init(func_00289D08(func_0028B180(), D_00535610_il.f12));
    func_0031A6B8();
    func_00287410(func_0028B180(), optA_il(D_00535610_il));
    func_00287488(func_0028B180(), optB_il(D_00535610_il));
    func_00287520(func_0028B180(), optC_il(D_00535610_il));
    func_00287558(func_0028B180(), optD_il(D_00535610_il));
    func_002875D0(func_0028B180(), optE_il(D_00535610_il));
    WORLDTRIGGERMANAGER_Init();
    if (func_004165A8(self->fCC, D_004A29E8)) {
        cBE_getInterface(cBE_getBE(), 0);
        cBXString_cBXString4(&D_004A4CB8, (const char*)self->fCC);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_initLocale);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00195880(void* self);
extern "C" void func_00195B70(void* self);
extern char D_0047A978[];

struct sOptions_228A78 {
    unsigned int pad0 : 22;
    unsigned int language : 3;
    unsigned int pad25 : 7;
    int data[0x284 / 4];
};
extern sOptions_228A78 D_00535610_228A78 __asm__("D_00535610");

struct sVEntry_228A78 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline int optLanguage_228A78(sOptions_228A78 o)
{
    return o.language;
}

extern "C" void cSSXApp_initLocale(void* self)
{
    if (*(void**)((char*)self + 0x8C) == 0) {
        *(void**)((char*)self + 0x8C) = func_00195880(cMemMan_alloc(0xC0, D_0047A978, 0, 0));
    }
    cBE_getInterface_Fv(cBE_getBE(), 4);
    char* loc = *(char**)((char*)self + 0x8C);
    sVEntry_228A78* vt = *(sVEntry_228A78**)(loc + 4);
    char* thisp = loc + vt[3].delta;
    void (**pfn)(void*, int) = &vt[3].fn;
    (*pfn)(thisp, optLanguage_228A78(D_00535610_228A78));
    func_00195B70(*(void**)((char*)self + 0x8C));
}
#endif

extern "C" void func_002B4B48(void* self);
extern "C" void func_00284C28();
extern "C" void cAppMan_loadexecpurge(void* self);

struct sExecPurgeVTable {
    char pad_0x00[0x3B8];
    short field_0x3B8;
    char pad_0x3BA[2];
    void (*fn)(void*);
};

struct sExecPurgeMgr {
    char pad_0x00[0x10D8];
    sExecPurgeVTable* vtable;
};

extern sExecPurgeMgr* D_004A5B80;

//100%
INCLUDE_ASM("main/ssxapp", cSSXApp_loadexecpurge__FPv);
#ifdef SKIP_ASM
void cSSXApp_loadexecpurge(void* self)
{
    func_002B4B48(self);
    func_00284C28();
    cAppMan_loadexecpurge(self);
    sExecPurgeVTable* vt = D_004A5B80->vtable;
    vt->fn((char*)D_004A5B80 + vt->field_0x3B8);
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00228C08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sOptions_228C08 {
    unsigned int pad0 : 20;
    unsigned int mode : 2;          // bits 20..21
    unsigned int pad22 : 10;
    int pad_4 : 8;
    int b5 : 8;
    int b6 : 8;
    int pad_7 : 8;
    int data[(0x288 - 8) / 4];
};
extern sOptions_228C08 D_00535610_228C08 __asm__("D_00535610");

static inline sOptions_228C08 GetOptions_228C08()
{
    return D_00535610_228C08;
}

class cGfx_228C08 {
public:
    char pad_0x0[0x10D8];
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
    virtual void v12(int a, int b);
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40(int mode);
};

struct sVE_228C08 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern cGfx_228C08* D_004A5B80_228C08 __asm__("D_004A5B80");

extern "C" void func_00228C08(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 4);
    switch (GetOptions_228C08().mode) {
    case 0:
        D_004A5B80_228C08->v40(0);
        break;
    case 1:
        D_004A5B80_228C08->v40(1);
        break;
    case 2:
        D_004A5B80_228C08->v40(2);
        break;
    default:
        D_004A5B80_228C08->v40(0);
        break;
    }
    cGfx_228C08* g = D_004A5B80_228C08;
    sVE_228C08* vt = *(sVE_228C08**)((char*)g + 0x10D8);
    char* thisp = (char*)g + vt[12].delta;
    void (**pfn)(void*, int, int) = &vt[12].fn;
    (*pfn)(thisp, GetOptions_228C08().b6, GetOptions_228C08().b5);
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", initOnline);
#ifdef SKIP_ASM
extern int D_004A3E94;
extern int D_004A29EC;
extern char D_00479918[];
extern char D_004A29F0[];
extern char D_004A29F8[];
extern char D_0047A988[];
extern char D_0047A998[];
extern char D_0047A9C8[];
extern char D_0047A9D8[];
extern char D_0047A9E8[];
extern char D_0047A9F8[];
extern char D_0047AA08[];
extern char D_0047AA20[];
extern char D_0047AA58[];
extern char D_0047AA68[];
extern char D_0047AA78[];
extern char D_0047AA90[];
extern char D_0047AAA0[];
extern char D_0047AAC8[];
extern char D_0047AAD8[];
extern char D_0047AAE8[];
extern char D_0047AAF8[];
extern char D_0047AB08[];
extern char D_0047AB18[];
extern char D_0047AB30[];
extern "C" int func_00319718(int loader, const char* name, int flags, int argLen, const char* args);
extern "C" void func_00319930(int loader);
extern "C" void func_003197D0(int loader);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void THREAD_yieldticks(int ticks);
extern "C" void func_0040B130(int a);
extern "C" void func_003F6A40();
extern "C" void func_003F6AB0();
extern "C" void func_00266788();

extern "C" void initOnline()
{
    char buf[0x100];
    func_00319718(D_004A3E94, D_0047A988, 0, 0x2B, D_0047A998);
    int ok = 0;
    func_00319718(D_004A3E94, D_0047A9C8, 0, 0x10, D_0047A9D8);
    func_00319718(D_004A3E94, D_0047A9E8, 0, 0, 0);
    func_00319930(D_004A3E94);
    func_00319718(D_004A3E94, D_0047A9F8, 1, 0x12, D_0047AA08);
    int n = sprintf(buf, D_0047AA20, D_00479918, D_004A29F0, 0, D_00479918, D_004A29F0);
    func_00319718(D_004A3E94, D_0047AA58, 1, n + 1, buf);
    func_00319718(D_004A3E94, D_0047AA68, 1, 0x14, D_0047AA78);
    D_004A29EC = 0;
    if (func_00319718(D_004A3E94, D_0047AA90, 0, 0, 0) >= 0) {
        D_004A29EC = 1;
        ok = 1;
    }
    func_00319718(D_004A3E94, D_004A29F8, 1, 0, 0);
    n = sprintf(buf, D_0047AAA0, D_00479918, D_004A29F0, 0);
    if (func_00319718(D_004A3E94, D_0047AAC8, 0, n + 1, buf) >= 0) {
        D_004A29EC = 1;
    }
    if (D_004A29EC && ok) {
        func_00319718(D_004A3E94, D_0047AAD8, 1, 0, 0);
    }
    THREAD_yieldticks(10);
    if (D_004A29EC) {
        func_003197D0(D_004A3E94);
        func_00319718(D_004A3E94, D_0047AAE8, 1, 0, 0);
        func_0040B130(0);
        func_00319718(D_004A3E94, D_0047AAF8, 1, 0, 0);
        func_00319718(D_004A3E94, D_0047AB08, 0, 0x12, D_0047AB18);
        if (func_00319718(D_004A3E94, D_0047AB30, 0, 0, 0) >= 0) {
            func_003F6A40();
        } else {
            func_003F6AB0();
        }
    }
    func_00266788();
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229180);
#ifdef SKIP_ASM
extern "C" void func_002292E0(void* self);
// PORT: the ctor's mangled name says int; it receives the allocated block (pointer in int)
void* cCrowdRender2D_cCrowdRender2D(int mem);
void* cCrowdRender2D_constructCrowdAnim2D(void* r);
extern char D_0047B320[];
extern int D_004A2A00;

inline void* operator new[](unsigned int, void* p) { return p; }

struct sCrowdCfg_229180 {
    short f0;
    short f2;
    short f4;
    short f6;
    int f8;
    int fC;
    int f10;
};
extern sCrowdCfg_229180 D_00536690_229180[] __asm__("D_00536690");

struct sCrowdId_229180 {
    unsigned int id;
    sCrowdId_229180() : id(0xFFFFFFFF) {}
};

struct sCrowdSlot_229180 {
    char data[0x40];
    sCrowdSlot_229180() {}
};

struct sCrowdRest_229180 {
    char data[0x20];
    sCrowdRest_229180() {}
};

static inline int AnimCount_229180(char* anim)
{
    return *(int*)(anim + 0x10);
}

struct sCrowd_229180 {
    void* render;
    char* anim;
};

extern "C" void* func_00229180(sCrowd_229180* self)
{
    new ((char*)self + 0x8) sCrowdId_229180[128];
    new ((char*)self + 0x210) sCrowdSlot_229180[128];
    new ((char*)self + 0x2220) sCrowdRest_229180[40];
    // PORT: the singleton pointer is held in an int global
    D_004A2A00 = (int)self;
    self->render = cCrowdRender2D_cCrowdRender2D((int)cMemMan_alloc(0x10, D_0047B320, 0x20000000, 0));
    char* anim = (char*)cCrowdRender2D_constructCrowdAnim2D(self->render);
    self->anim = anim;
    D_00536690_229180[0].f0 = AnimCount_229180(anim);
    D_00536690_229180[0].fC = 0x20000;
    D_00536690_229180[0].f10 = 0;
    D_00536690_229180[0].f2 = -1;
    D_00536690_229180[0].f4 = -1;
    D_00536690_229180[0].f8 = 0;
    D_00536690_229180[0].f6 = -1;
    func_002292E0(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229278);
#ifdef SKIP_ASM
extern "C" void func_00229398(void* self);
extern int D_004A2A00;
void operator_delete(int* p);
void cCrowdRender2D__cCrowdRender2D(int* self, int flags);

extern "C" void func_00229278(void* self, int flags)
{
    func_00229398(self);
    int* p = *(int**)((char*)self + 4);
    D_004A2A00 = 0;
    operator_delete(p);
    int* r = *(int**)self;
    if (r != 0) {
        cCrowdRender2D__cCrowdRender2D(r, 3);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_002292E0);
#ifdef SKIP_ASM
extern "C" void* func_003E6448(void* dst, int c, int n);
unsigned int BXrand();

struct sCrowdSlot_2292E0 {
    char pad_0x00[0x30];
    int delay;              // 0x30
    char pad_0x34[0xC];
};

struct sCrowd_2292E0 {
    int pad0;
    int pad4;
    unsigned int ids[128];          // 0x8
    char pad_0x208[0x8];
    sCrowdSlot_2292E0 slots[128];   // 0x210
    int count;                      // 0x2210
    int count2;                     // 0x2214
    char pad_0x2218[0x8];
    char rest[0x500];               // 0x2220
};

extern "C" void func_002292E0(void* self)
{
    sCrowd_2292E0* c = (sCrowd_2292E0*)self;
    int i;
    c->count = 0;
    func_003E6448(c->slots, 0, 0x2000);
    for (i = 0; i < 128; i++) {
        c->ids[i] = 0xFFFFFFFF;
        c->slots[i].delay = BXrand() % 300 + 300;
    }
    c->count2 = 0;
    func_003E6448(c->rest, 0, 0x500);
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229398);
#ifdef SKIP_ASM
extern "C" void func_00229B90(void* self, int a1);

extern "C" void func_00229398(void* self)
{
    int i;
    for (i = 0; i < 0x80; i++) {
        unsigned* e = (unsigned*)((char*)self + 0x8) + i;
        if (*e != 0xFFFFFFFF) {
            func_00229B90(self, i);
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229408);
#ifdef SKIP_ASM
extern "C" void func_00229B90(void* self, int a1);

extern "C" void func_00229408(void* self, int id)
{
    int i;
    for (i = 0; i < 0x80; i++) {
        unsigned* e = (unsigned*)((char*)self + 0x8) + i;
        if (*e != 0xFFFFFFFF && *(unsigned char*)e == id) {
            func_00229B90(self, i);
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229498);
#ifdef SKIP_ASM
extern "C" void func_00229398(void* self);
extern "C" void func_002292E0(void* self);

extern "C" void func_00229498(void* self)
{
    func_00229398(self);
    func_002292E0(self);
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_002294C8);
#ifdef SKIP_ASM
extern "C" void cCrowdAnim2D_update(void* p);
extern "C" void func_00229530(void* self);
extern short D_00536690[];

extern "C" void func_002294C8(void* self)
{
    int i;
    char* p;
    int t;
    cCrowdAnim2D_update(*(void**)((char*)self + 0x4));
    t = *(int*)((char*)*(void**)((char*)self + 0x4) + 0x10);
    D_00536690[0] = t;
    p = (char*)self;
    for (i = 0x27; i >= 0; i--) {
        if (*(int*)(p + 0x2230) > 0) {
            *(int*)(p + 0x2230) = *(int*)(p + 0x2230) - 1;
        }
        p += 0x20;
    }
    func_00229530(self);
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229530);
#ifdef SKIP_ASM
unsigned int BXrand();
extern "C" int func_002A77C8(void* self, int a1);
extern void* D_004A3500;
struct sRingOwner;
struct sQuad229;
extern "C" void func_00229738(sRingOwner* self, sQuad229* q, int value);

struct sVec4_229530 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCrowdSlot_229530 {
    sVec4_229530 pos;       // 0x00
    sVec4_229530 dx;        // 0x10
    sVec4_229530 dy;        // 0x20
    int delay;              // 0x30
    char pad_0x34[0xC];
};

struct sCrowd_229530 {
    int pad0;
    int* anim;                          // 0x4
    unsigned int ids[128];              // 0x8
    char pad_0x208[0x8];
    sCrowdSlot_229530 slots[128];       // 0x210
    int count;                          // 0x2210
};

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_229530 Add_229530(const sVec4_229530& a, const sVec4_229530& b)
{
    sVec4_229530 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_229530 Scale_229530(const sVec4_229530& v, float s)
{
    sVec4_229530 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline float randf_229530()
{
    union { int i; float f; } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

static inline float rands_229530(float lo, float hi)
{
    return randf_229530() * (hi - lo) + lo;
}

extern "C" void func_00229530(void* selfp)
{
    sCrowd_229530* self = (sCrowd_229530*)selfp;
    int n = func_002A77C8(D_004A3500, 0);
    n = n > -1 ? n : -n;
    if (n != self->count) {
        int c = n > 0 ? n : 1;
        self->count = n;
        *self->anim = c;
    }
    int dec = self->count * 10 + 4;
    for (int i = 0; i < 128; i++) {
        if (self->ids[i] != 0xFFFFFFFF) {
            self->slots[i].delay -= dec;
            if (self->slots[i].delay <= 0) {
                float r1 = rands_229530(-1.0f, 1.0f);
                float r2 = rands_229530(-1.0f, 1.0f);
                sVec4_229530 p = Add_229530(Add_229530(self->slots[i].pos, Scale_229530(self->slots[i].dx, r1)),
                                            Scale_229530(self->slots[i].dy, r2));
                func_00229738((sRingOwner*)self, (sQuad229*)&p, 3);
                self->slots[i].delay = BXrand() % 300 + 300;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229738);
#ifdef SKIP_ASM
struct sQuad229 {
    int v[4];
} __attribute__((aligned(16)));

struct sRingEntry {
    sQuad229 q;     // 0x0
    int value;      // 0x10
    int pad[3];
};

struct sRingOwner {
    char pad_0x0[0x2214];
    int index;              // 0x2214
    int pad_0x2218[2];
    sRingEntry entries[40]; // 0x2220
};

extern "C" void func_00229738(sRingOwner* self, sQuad229* q, int value)
{
    self->entries[self->index].q = *q;
    self->entries[self->index].value = value;
    self->index++;
    self->index %= 40;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229788);
#ifdef SKIP_ASM
extern "C" void func_00229910(void* self, int slot, int a1);

extern "C" void func_00229788(void* self, int a1)
{
    int i;
    for (i = 0; i < 0x40; i++) {
        if (((unsigned int*)((char*)self + 0x8))[i] == 0xFFFFFFFF) {
            func_00229910(self, i, a1);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_002297D8);
#ifdef SKIP_ASM
extern "C" void func_00229B90(void* self, int a1);

extern "C" void func_002297D8(void* self, int val)
{
    int i;
    for (i = 0; i < 0x40; i++) {
        if (((int*)self)[i + 2] == val) {
            func_00229B90(self, i);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229820);
#ifdef SKIP_ASM
struct sHTable_229820 {
    char pad[0x1C];
    unsigned int* entries;      // 0x1C
};

struct sHMgr_229820 {
    char pad[0x8];
    sHTable_229820** tables;    // 0x8
};

extern "C" sHMgr_229820** func_002D1BD8(void);

struct sPart_229820 {
    char pad[0x1C];
    int count;                  // 0x1C
    short** bones;              // 0x20
};

struct sPartRef_229820 {
    int f0;
    sPart_229820* part;         // 0x4
    int f8, fC;
};

struct sSkel_229820 {
    int f0;
    int count;                  // 0x4
    sPartRef_229820* parts;     // 0x8
};

struct sModel_229820 {
    char pad[0x80];
    sSkel_229820* skel;         // 0x80
    char pad84[0x94 - 0x84];
    struct {
        int f0;
        void* bones[1];
    }* pose;                    // 0x94
};

extern char D_00536690_229820[] __asm__("D_00536690");

static inline sModel_229820* refToPtr_229820(unsigned int p)
{
    return (sModel_229820*)(p << 2);
}

static inline sModel_229820* lookup_229820(sHTable_229820* t, unsigned int idx)
{
    unsigned int p = t->entries[idx] >> 8;
    if (p == 0) {
        return 0;
    }
    return refToPtr_229820(p);
}

static inline sModel_229820* HandleToModel_229820(unsigned int h)
{
    sHTable_229820* t = (*func_002D1BD8())->tables[h & 0xFF];
    if (t == 0) {
        return 0;
    }
    return lookup_229820(t, h >> 8);
}

// Points bone b of part a of the model behind handle at the shared crowd pose.
extern "C" void func_00229820(void* self, unsigned int handle, int a, int b)
{
    sModel_229820* m = HandleToModel_229820(handle);
    if (m != 0) {
        sSkel_229820* s = m->skel;
        void** dst = m->pose->bones;
        sPartRef_229820* parts = s->parts;
        if (a < s->count) {
            sPart_229820* p = parts[a].part;
            if (b < p->count)
                dst[*p->bones[b]] = D_00536690_229820;
        }
    }
}
#endif

INCLUDE_ASM("main/ssxapp", func_00229910);

//100%
INCLUDE_ASM("main/ssxapp", func_00229B90);
#ifdef SKIP_ASM
extern "C" void func_00229B90(void* self, int a1)
{
    ((unsigned int*)self)[a1 + 2] = 0xFFFFFFFFU;
}
#endif

INCLUDE_ASM("main/ssxapp", func_00229BA8);

//100%
INCLUDE_ASM("main/ssxapp", func_00229E20);
#ifdef SKIP_ASM
// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
class cSSXAppStream {
public:
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

extern "C" void func_00229E20(void* self, cSSXAppStream* s)
{
    s->v01((char*)self + 0x8, 0x200);
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229E58);
#ifdef SKIP_ASM
extern "C" void func_00229398(void* self);
extern "C" void func_002292E0(void* self);
extern "C" void func_00229910(void* self, int slot, int a1);

// Serialisation stream: v01 = read(buf, size), v02 = write(buf, size).
class cSSXAppStream_229E58 {
public:
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

struct sCrowdId_229E58 {
    unsigned int id;
    sCrowdId_229E58() : id(0xFFFFFFFF) {}
};

extern "C" void func_00229E58(void* self, cSSXAppStream_229E58* s)
{
    func_00229398(self);
    func_002292E0(self);
    sCrowdId_229E58 ids[128];
    s->v02(ids, 0x200);
    int i;
    for (i = 0; i < 128; i++) {
        if (ids[i].id != 0xFFFFFFFF) {
            func_00229910(self, i, ids[i].id);
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229F30);
#ifdef SKIP_ASM
// Upload two 4x4 matrices (a, b) to VU0 data memory starting at qword 4 (address 0x40).
// PORT: PS2-only VU0 inline asm (ctc2/lqc2/vsqi); the PC port needs its own matrix store.
extern "C" void func_00229F30(void* a, void* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "ctc2.ni   %0, $vi1\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "vsqi.xyzw $vf1, ($vi1++)\n"
        "vsqi.xyzw $vf2, ($vi1++)\n"
        "vsqi.xyzw $vf3, ($vi1++)\n"
        "vsqi.xyzw $vf4, ($vi1++)\n"
        "lqc2      $vf1, 0x0(%2)\n"
        "lqc2      $vf2, 0x10(%2)\n"
        "lqc2      $vf3, 0x20(%2)\n"
        "lqc2      $vf4, 0x30(%2)\n"
        "vsqi.xyzw $vf1, ($vi1++)\n"
        "vsqi.xyzw $vf2, ($vi1++)\n"
        "vsqi.xyzw $vf3, ($vi1++)\n"
        "vsqi.xyzw $vf4, ($vi1++)\n"
        ".set reorder\n"
        :
        : "r"(0x40), "r"(a), "r"(b)
        : "memory");
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229F80__FPv);
#ifdef SKIP_ASM
void func_00229F80(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229F88);
#ifdef SKIP_ASM
// Upload a vector plus a 4x4 matrix (5 qwords) to VU0 data memory slot `index`,
// starting at qword 0x50 + index * 5.
// PORT: PS2-only VU0 inline asm (ctc2/lqc2/vsqi); the PC port needs its own store.
extern "C" void func_00229F88(int index, void* v, void* m)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "ctc2.ni   %0, $vi1\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x0(%2)\n"
        "lqc2      $vf3, 0x10(%2)\n"
        "lqc2      $vf4, 0x20(%2)\n"
        "lqc2      $vf5, 0x30(%2)\n"
        "vsqi.xyzw $vf1, ($vi1++)\n"
        "vsqi.xyzw $vf2, ($vi1++)\n"
        "vsqi.xyzw $vf3, ($vi1++)\n"
        "vsqi.xyzw $vf4, ($vi1++)\n"
        "vsqi.xyzw $vf5, ($vi1++)\n"
        ".set reorder\n"
        :
        : "r"(index * 5 + 0x50), "r"(v), "r"(m)
        : "memory");
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_00229FC8);
#ifdef SKIP_ASM
struct sVisEnt_9FC8 {
    int a;
    int f4;
};
struct sVisRec_9FC8 {
    int f0;
    int pad[5];
};
struct sVisTbl_9FC8 {
    char pad0[0x20];
    sVisEnt_9FC8 ent[0x7A];
    sVisRec_9FC8 rec[1];
};

struct sVisOwner_9FC8 {
    char pad0[0x90];
    char **tblp;                  // 0x90
    char pad94[0x209C - 0x94];
    int countA;                   // 0x209C
    void *nodesA[0x800];          // 0x20A0
    int countB;                   // 0x40A0
    void *nodesB[0x400];          // 0x40A4
    void *last;                   // 0x50A4
};

static inline int visOk_9FC8(sVisOwner_9FC8 *self, char *node)
{
    if ((*(int *)(node + 8) & 3) != 3) {
        return 0;
    }
    sVisTbl_9FC8 *tbl = (sVisTbl_9FC8 *)*self->tblp;
    if (*(unsigned char *)(node + 0x7D) == 0xFF) {
        return 1;
    }
    if ((tbl->ent[*(unsigned char *)(node + 0x7D)].f4 ^ 6) == 0) {
        return tbl->rec[*(short *)(node + 0x7E)].f0 == 3;
    }
    return 0;
}

// PORT: PS2-only VU0 microprogram call (lqc2/ctc2/vcallms/cfc2); the PC port needs a C
// version of the microprogram at 0xDB8 (box vs frustum test).
extern "C" void func_00229FC8_impl(sVisOwner_9FC8 *self, void *vnode, int frustum) __asm__("func_00229FC8");
extern "C" void func_00229FC8_impl(sVisOwner_9FC8 *self, void *vnode, int frustum)
{
    char *node = (char *)vnode;
    unsigned int r;

    if (node != 0) {
        if (!visOk_9FC8(self, node)) {
            return;
        }
        {
            float lo[4] __attribute__((aligned(16)));
            float hi[4] __attribute__((aligned(16)));
            lo[0] = *(float *)(node + 0x60);
            lo[1] = *(float *)(node + 0x64);
            lo[2] = *(float *)(node + 0x68);
            hi[0] = *(float *)(node + 0x6C);
            hi[1] = *(float *)(node + 0x70);
            hi[2] = *(float *)(node + 0x74);
            lo[3] = 1.0f;
            hi[3] = 1.0f;
            __asm__ __volatile__("cfc2.i    %0, $vi1\n" : "=r"(r));
            __asm__ __volatile__(
                "lqc2      $vf20, 0x0(%0)\n"
                "lqc2      $vf21, 0x0(%1)\n"
                "lqc2      $vf22, 0x0(%2)\n"
                "ctc2.ni   %3, $vi14\n"
                "vcallms   0xDB8\n"
                :
                : "r"(lo), "r"(hi), "r"(node + 0x50), "r"(frustum));
        }
    } else {
        __asm__ __volatile__("cfc2.i    %0, $vi1\n" : "=r"(r));
    }
    switch (r) {
    case 0:
    case 3:
        if (self->last != 0) {
            self->nodesA[self->countA++] = self->last;
        }
        break;
    case 1:
    case 2:
        break;
    case 4:
        if (self->last != 0) {
            self->nodesB[self->countB++] = self->last;
        }
        break;
    }
    self->last = node;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_0022A128);
#ifdef SKIP_ASM
struct sVisEnt_A128 {
    int a;
    int f4;
};
struct sVisRec_A128 {
    int f0;
    int pad[5];
};
struct sVisTbl_A128 {
    char pad0[0x20];
    sVisEnt_A128 ent[0x7A];
    sVisRec_A128 rec[1];
};

struct sVisOwner_A128 {
    char pad0[0x90];
    char **tblp;                  // 0x90
    char pad94[0x50A8 - 0x94];
    int countA;                   // 0x50A8
    void *nodesA[0x800];          // 0x50AC
    int countB;                   // 0x70AC
    void *nodesB[0x200];          // 0x70B0
    void *last;                   // 0x78B0
};

static inline int visOk_A128(sVisOwner_A128 *self, char *node)
{
    int idx = *(short *)(node + 0x156);
    sVisTbl_A128 *tbl = (sVisTbl_A128 *)*self->tblp;
    if (idx < 0) {
        return 0;
    }
    if ((tbl->ent[*(unsigned char *)(node + 0x155)].f4 ^ 6) == 0) {
        return tbl->rec[idx].f0 == 3;
    }
    return 0;
}

// PORT: PS2-only VU0 microprogram call (lqc2/ctc2/vcallms/cfc2); the PC port needs a C
// version of the microprogram at 0xDB8 (box vs frustum test).
extern "C" void func_0022A128_impl(sVisOwner_A128 *self, void *vnode, int frustum) __asm__("func_0022A128");
extern "C" void func_0022A128_impl(sVisOwner_A128 *self, void *vnode, int frustum)
{
    char *node = (char *)vnode;
    unsigned int r;

    if (node != 0) {
        if (!visOk_A128(self, node)) {
            return;
        }
        {
            float lo[4] __attribute__((aligned(16)));
            float hi[4] __attribute__((aligned(16)));
            lo[0] = *(float *)(node + 0x158);
            lo[1] = *(float *)(node + 0x15C);
            lo[2] = *(float *)(node + 0x160);
            hi[0] = *(float *)(node + 0x164);
            hi[1] = *(float *)(node + 0x168);
            hi[2] = *(float *)(node + 0x16C);
            lo[3] = 1.0f;
            hi[3] = 1.0f;
            __asm__ __volatile__("cfc2.i    %0, $vi1\n" : "=r"(r));
            __asm__ __volatile__(
                "lqc2      $vf20, 0x0(%0)\n"
                "lqc2      $vf21, 0x0(%1)\n"
                "lqc2      $vf22, 0x0(%2)\n"
                "ctc2.ni   %3, $vi14\n"
                "vcallms   0xDB8\n"
                :
                : "r"(lo), "r"(hi), "r"(node + 0x140), "r"(frustum));
        }
    } else {
        __asm__ __volatile__("cfc2.i    %0, $vi1\n" : "=r"(r));
    }
    switch (r) {
    case 0:
    case 3:
        if (self->last != 0) {
            self->nodesA[self->countA++] = self->last;
        }
        break;
    case 1:
    case 2:
        break;
    case 4:
        if (self->last != 0) {
            self->nodesB[self->countB++] = self->last;
        }
        break;
    }
    self->last = node;
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_0022A270);
#ifdef SKIP_ASM
struct sVisObj_A270 {
    char pad0[0x50];
    float sphere[4];  // 0x50
    char pad60[8];
    float boxMin[3];  // 0x68
    float boxMax[3];  // 0x74
};

struct sVisOwner_A270 {
    char pad0[0x78B4];
    int countA;                  // 0x78B4
    sVisObj_A270* nodesA[0x80];  // 0x78B8
    sVisObj_A270* last;          // 0x7AB8
    int countB;                  // 0x7ABC
    sVisObj_A270* nodesB[1];     // 0x7AC0
};

// PORT: callers declare func_0022A270 with other pointer types; defined under an asm label.
extern "C" void func_0022A270_impl(sVisOwner_A270* self, sVisObj_A270* obj, int frustum) __asm__("func_0022A270");

// PORT: PS2-only VU0 microprogram call (lqc2/ctc2/vcallms/cfc2); the PC port needs a C
// version of the microprogram at 0xDB8 (box vs frustum test).
// Files the previous object by the result of its test, then starts the test for this one.
extern "C" void func_0022A270_impl(sVisOwner_A270* self, sVisObj_A270* obj, int frustum)
{
    unsigned int r;
    if (obj != 0) {
        float lo[4] __attribute__((aligned(16)));
        float hi[4] __attribute__((aligned(16)));
        lo[0] = obj->boxMin[0];
        lo[1] = obj->boxMin[1];
        lo[2] = obj->boxMin[2];
        hi[0] = obj->boxMax[0];
        hi[1] = obj->boxMax[1];
        hi[2] = obj->boxMax[2];
        lo[3] = 1.0f;
        hi[3] = 1.0f;
        __asm__ __volatile__("cfc2.i    %0, $vi1
" : "=r"(r));
        __asm__ __volatile__(
            "lqc2      $vf20, 0x0(%0)\n"
            "lqc2      $vf21, 0x0(%1)\n"
            "lqc2      $vf22, 0x0(%2)\n"
            "ctc2.ni   %3, $vi14\n"
            "vcallms   0xDB8\n"
            :
            : "r"(lo), "r"(hi), "r"(obj->sphere), "r"(frustum));
    } else {
        __asm__ __volatile__("cfc2.i    %0, $vi1
" : "=r"(r));
    }
    switch (r) {
    case 0:
    case 3:
        if (self->last != 0) {
            self->nodesA[self->countA++] = self->last;
        }
        break;
    case 1:
    case 2:
        break;
    case 4:
        if (self->last != 0) {
            self->nodesB[self->countB++] = self->last;
        }
        break;
    }
    self->last = obj;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/ssxapp", func_0022A368);
#ifdef SKIP_ASM
extern "C" void func_00229FC8(void* self, void* node, int frustum);

struct sNode_A368 {
    sNode_A368* next;
};

struct sSrc_A368 {
    char pad_0x0[0x20];
    sNode_A368* head;   // 0x20
};

struct sList_A368 {
    sSrc_A368* src;
    int vuFrustum;
};

extern "C" void func_0022A368(void* self, sList_A368* list, int count)
{
    for (; count > 0; count--, list++) {
        sNode_A368* n = list->src->head;
        while (n != 0) {
            func_00229FC8(self, n, list->vuFrustum);
            n = n->next;
        }
    }
    if (*(int*)((char*)self + 0x50A4) != 0) {
        func_00229FC8(self, 0, 0);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/ssxapp", func_0022A408);
#ifdef SKIP_ASM
extern "C" void func_0022A128(void* self, void* node, int frustum);

struct sNode_A408 {
    sNode_A408* next;
};

struct sSrc_A408 {
    char pad_0x0[0x24];
    sNode_A408* head;   // 0x24
};

struct sList_A408 {
    sSrc_A408* src;
    int vuFrustum;
};

extern "C" void func_0022A408(void* self, sList_A408* list, int count)
{
    for (; count > 0; count--, list++) {
        sNode_A408* n = list->src->head;
        while (n != 0) {
            func_0022A128(self, n, list->vuFrustum);
            n = n->next;
        }
    }
    if (*(int*)((char*)self + 0x78B0) != 0) {
        func_0022A128(self, 0, 0);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/ssxapp", func_0022A4A8);
#ifdef SKIP_ASM
struct sNode_22A4A8 {
    sNode_22A4A8* next;
    int f4;
    int type;
};

struct sItem_22A4A8 {
    char* list;
    int arg;
};

extern "C" void func_0022A270(void* self, sNode_22A4A8* node, int arg);

struct sWorld_22A4A8 {
    char pad[0x7AB8];
    int f7AB8;
    char pad7ABC[0x7BC0 - 0x7ABC];
    int count;
    sNode_22A4A8* nodes[1];
};

extern "C" void func_0022A4A8(sWorld_22A4A8* self, sItem_22A4A8* items, int n)
{
    for (; n > 0; n--, items++) {
        for (sNode_22A4A8* p = *(sNode_22A4A8**)(items->list + 0x28); p != 0; p = p->next) {
            if (p->type == 7) {
                func_0022A270(self, p, items->arg);
            } else if (p->type == 8) {
                self->nodes[self->count++] = p;
            }
        }
    }
    if (self->f7AB8 != 0) {
        func_0022A270(self, 0, 0);
    }
}
#endif

INCLUDE_ASM("main/ssxapp", func_0022A5A0);

//100%
INCLUDE_ASM("main/ssxapp", func_0022A698);
#ifdef SKIP_ASM
struct sVisNode_A698 {
    sVisNode_A698* next;    // 0x000
    char pad_0x4[0x13C];
    int sphere[4];          // 0x140
    char pad_0x150[0x5];
    unsigned char slot;     // 0x155
    short path;             // 0x156
};

struct sVisSrc_A698 {
    char pad_0x0[0x24];
    sVisNode_A698* head;    // 0x24
};

struct sVisList_A698 {
    sVisSrc_A698* src;
    int vuFrustum;
};

struct sVisSlot_A698 {
    int f0;
    int type;
};

struct sVisCam_A698 {
    char pad_0x0[0x20];
    sVisSlot_A698 slots[(0x3F0 - 0x20) / 8];  // 0x20
    struct {
        int kind;
        char pad[0x14];
    } paths[1];                     // 0x3F0
};

struct sVisOwner_A698 {
    char pad_0x0[0x90];
    sVisCam_A698** cam;             // 0x90
    char pad_0x94[0x50A8 - 0x94];
    int count;                      // 0x50A8
    sVisNode_A698* nodes[1];        // 0x50AC
};

// PORT: PS2-only VU0 microprogram call (lqc2/ctc2/vcallms/cfc2); the PC port needs a C
// version of the microprogram at 0xEF0 (sphere vs frustum test; 2 = outside).
static inline int visSphereTest_A698(int* sphere, int frustum)
{
    int r;
    __asm__ __volatile__(
        "lqc2      $vf22, 0x0(%1)\n"
        "ctc2.ni   %2, $vi14\n"
        "vcallms   0xEF0\n"
        "cfc2.i    %0, $vi1\n"
        : "=&r"(r)
        : "r"(sphere), "r"(frustum));
    return r;
}

static inline bool IsT6_A698(sVisCam_A698* c, int i)
{
    return c->slots[i].type == 6;
}

static inline int visOnPath_A698(sVisCam_A698* cam, sVisNode_A698* n)
{
    if (n->path < 0)
        return 0;
    if (IsT6_A698(cam, n->slot))
        return cam->paths[n->path].kind == 3;
    return 0;
}

// Collects the visible path-bound nodes of each source list (sphere-vs-frustum tested on VU0).
extern "C" void func_0022A698(void* self_, void* list_, int count)
{
    sVisOwner_A698* self = (sVisOwner_A698*)self_;
    sVisList_A698* list = (sVisList_A698*)list_;
    for (; count > 0; count--, list++) {
        sVisNode_A698* n = list->src->head;
        while (n != 0) {
            // A do/while(0) block around the body (as a macro would) reproduces the target's register choice.
            do {
                int frustum = list->vuFrustum;
                if (visOnPath_A698(*self->cam, n)) {
                    if (frustum == 0 || visSphereTest_A698(n->sphere, frustum) != 2) {
                        self->nodes[self->count++] = n;
                    }
                }
                n = n->next;
            } while (0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxapp", func_0022A770);
#ifdef SKIP_ASM
struct sVisNode_A770 {
    sVisNode_A770* next;    // 0x00
    int pad_0x4;
    int type;               // 0x08
    char pad_0xC[0x44];
    int sphere[4];          // 0x50
};

struct sVisSrc_A770 {
    char pad_0x0[0x28];
    sVisNode_A770* head;    // 0x28
};

struct sVisList_A770 {
    sVisSrc_A770* src;
    int vuFrustum;
};

struct sVisOwner_A770 {
    char pad_0x0[0x78B4];
    int countA;                 // 0x78B4
    sVisNode_A770* nodesA[192]; // 0x78B8
    int pad_0x7BB8[2];
    int countB;                 // 0x7BC0
    sVisNode_A770* nodesB[1];   // 0x7BC4
};

// PORT: PS2-only VU0 microprogram call (lqc2/ctc2/vcallms/cfc2); the PC port needs a C
// version of the microprogram at 0xEF0 (sphere vs frustum test; 2 = outside).
static inline int visSphereTest_A770(int* sphere, int frustum)
{
    int r;
    __asm__ __volatile__(
        "lqc2      $vf22, 0x0(%1)\n"
        "ctc2.ni   %0, $vi14\n"
        "vcallms   0xEF0\n"
        "cfc2.i    %0, $vi1\n"
        : "=r"(r)
        : "r"(sphere), "0"(frustum));
    return r;
}

extern "C" void func_0022A770(sVisOwner_A770* self, sVisList_A770* list, int count)
{
    for (; count > 0; count--, list++) {
        sVisNode_A770* n = list->src->head;
        while (n != 0) {
            if (n->type == 7) {
                int frustum = list->vuFrustum;
                if (frustum == 0 || visSphereTest_A770(n->sphere, frustum) != 2) {
                    self->nodesA[self->countA++] = n;
                }
            } else if (n->type == 8) {
                self->nodesB[self->countB++] = n;
            }
            n = n->next;
        }
    }
}
#endif

INCLUDE_ASM("main/ssxapp", func_0022A830);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/ssxapp", func_0022ADD8);
#ifdef SKIP_ASM
extern void* D_004A289C;
extern "C" void func_002425C0(void* a, void* b);
extern "C" void func_00229F30(void* a, void* b);
void func_00229F80(void* p);
extern "C" void func_0022A830(void* ctx, void* data, void* cfg);
extern "C" void func_0022A698(void* self, void* list, int n);
extern "C" void func_0022A5A0(void* self, void* list, int n);

struct sMat_22ADD8 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sVEMat_22ADD8 {
    short delta;
    short index;
    sMat_22ADD8 (*fn)(void*);
};

struct sCfg_22ADD8 {
    char pad_0x00[0x10];
    void* data;         // 0x10
};

struct sCtx_22ADD8 {
    void* owner;        // 0x0
    void* f4;           // 0x4
    void* f8;           // 0x8
    int fC;             // 0xC
};

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through vf1..vf4).
static inline void MatCopy_22ADD8(sMat_22ADD8* dst, const sMat_22ADD8* src)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

struct sWorldInit_22ADD8 {
    void* f0;               // 0x0
    void* f4;               // 0x4
    char pad_0x8[0x88];
    int f90;                // 0x90
    int f94;                // 0x94
    char pad_0x98[0x1098 - 0x98];
    int f1098;              // 0x1098
    char pad_0x109C[0x209C - 0x109C];
    int f209C;              // 0x209C
    char pad_0x20A0[0x40A0 - 0x20A0];
    int f40A0;              // 0x40A0
    char pad_0x40A4[0x50A4 - 0x40A4];
    int f50A4;              // 0x50A4
    int f50A8;              // 0x50A8
    char pad_0x50AC[0x70AC - 0x50AC];
    int f70AC;              // 0x70AC
    char pad_0x70B0[0x78B0 - 0x70B0];
    int f78B0;              // 0x78B0
    int f78B4;              // 0x78B4
    char pad_0x78B8[0x7AB8 - 0x78B8];
    int f7AB8;              // 0x7AB8
    int f7ABC;              // 0x7ABC
    char pad_0x7AC0[0x7BC0 - 0x7AC0];
    int f7BC0;              // 0x7BC0
    char pad_0x7BC4[0x7FC4 - 0x7BC4];
    int f7FC4;              // 0x7FC4
};

static inline void Load_22ADD8(sCtx_22ADD8* ctx, void* data, sCfg_22ADD8* c)
{
    if (data) {
        func_0022A830(ctx, data, c);
    }
}

extern "C" char* func_0022ADD8(char* self, sCfg_22ADD8* cfg, void* a2, void* a3, int a4)
{
    sWorldInit_22ADD8* w = (sWorldInit_22ADD8*)self;
    w->f0 = a2;
    w->f4 = a3;
    w->f90 = a4;
    w->f94 = 0;
    w->f1098 = 0;
    w->f209C = 0;
    w->f40A0 = 0;
    w->f50A8 = 0;
    w->f70AC = 0;
    w->f78B4 = 0;
    w->f7ABC = 0;
    w->f7BC0 = 0;
    w->f7FC4 = 0;
    w->f50A4 = 0;
    w->f78B0 = 0;
    w->f7AB8 = 0;
    {
        char* g = (char*)D_004A289C;
        sVEMat_22ADD8* vt = *(sVEMat_22ADD8**)(g + 0x10D8);
        sMat_22ADD8 m = vt[43].fn(g + vt[43].delta);
        MatCopy_22ADD8((sMat_22ADD8*)(self + 0x10), &m);
    }
    MatCopy_22ADD8((sMat_22ADD8*)(self + 0x50), (sMat_22ADD8*)((char*)D_004A289C + 0x5800));
    func_002425C0(*(void**)(self + 0x0), *(void**)(self + 0x4));
    func_00229F30(self + 0x10, self + 0x50);
    func_00229F80(*(void**)(self + 0x4));
    sCtx_22ADD8 ctx;
    char* f0 = *(char**)(self + 0x0);
    void* f8 = *(void**)(f0 + 0x110);
    ctx.owner = self;
    ctx.f4 = f0;
    ctx.f8 = f8;
    ctx.fC = 0;
    Load_22ADD8(&ctx, cfg[0].data, &cfg[0]);
    Load_22ADD8(&ctx, cfg[1].data, &cfg[1]);
    Load_22ADD8(&ctx, cfg[2].data, &cfg[2]);
    Load_22ADD8(&ctx, cfg[3].data, &cfg[3]);
    Load_22ADD8(&ctx, cfg[4].data, &cfg[4]);
    Load_22ADD8(&ctx, cfg[5].data, &cfg[5]);
    Load_22ADD8(&ctx, cfg[6].data, &cfg[6]);
    Load_22ADD8(&ctx, cfg[7].data, &cfg[7]);
    func_0022A698(self, self + 0x98, *(int*)(self + 0x94));
    func_0022A5A0(self, self + 0x98, *(int*)(self + 0x94));
    func_0022A770((sVisOwner_A770*)self, (sVisList_A770*)(self + 0x98), *(int*)(self + 0x94));
    func_0022A408(self, (sList_A408*)(self + 0x109C), *(int*)(self + 0x1098));
    func_0022A368(self, (sList_A368*)(self + 0x109C), *(int*)(self + 0x1098));
    func_0022A4A8((sWorld_22A4A8*)self, (sItem_22A4A8*)(self + 0x109C), *(int*)(self + 0x1098));
    return self;
}
#endif

INCLUDE_ASM("main/ssxapp", func_0022B008);

