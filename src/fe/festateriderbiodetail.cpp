#include "common.h"

//100%
INCLUDE_ASM("fe/festateriderbiodetail", cFEStateRiderBio_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" unsigned char cUIListBox_addEntryByStringID(void* box, int id, int a2);
extern "C" void func_00190A08(void* self);
extern "C" void func_00190CD8(void* self);
extern char D_0045E398[];
extern char D_0045E3A8[];
extern char D_0045E3B8[];
extern char D_0045E3C8[];
extern char D_0045E3D8[];
extern char D_0045E3E8[];

struct sVEnt_001908C0 { short delta; short index; void (*fn)(void*); };

extern "C" void cFEStateRiderBio_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045E398), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    void* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E3A8));
    if (box != 0) {
        cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045E3B8), 0);
        cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045E3C8), 0);
        cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045E3D8), 0);
        cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045E3E8), 0);
    }
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 1);
    *(int*)((char*)self + 0x48) = cBENewPlayerInterface_getPlayerCharID(iface, *(signed char*)((char*)self + 0x44));
    sVEnt_001908C0* vt = *(sVEnt_001908C0**)((char*)iface + 0xC);
    vt[2].fn((char*)iface + vt[2].delta);
    *(int*)((char*)self + 0x4C) = 0;
    func_00190A08(self);
    func_00190CD8(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", func_00190A08);
#ifdef SKIP_ASM
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void cFEStateRiderBio_fillDNAInfo(void* self);
extern "C" void cFEStateRiderBio_fillFavesInfo(void* self);
extern "C" void cFEStateRiderBio_fillQnAInfo(void* self);
extern "C" void cFEStateRiderBio_fillBioInfo(void* self);
extern char D_0045E3F8[];
extern char D_004A1610[];
extern char D_0045E408[];
extern char D_0045E418[];
extern char D_0045E428[];
extern char D_004A1618[];
extern char D_0045E438[];
extern char D_0045E450[];
extern char D_0045E460[];

extern "C" void func_00190A08(void* self)
{
    switch (*(int*)((char*)self + 0x4C)) {
    case 0:
        cUIState_showObjSafe(self, D_0045E3F8);
        cUIState_showObjSafe(self, D_004A1610);
        cUIState_hideObjSafe(self, D_0045E408);
        cUIState_hideObjSafe(self, D_0045E418);
        cUIState_hideObjSafe(self, D_0045E428);
        cUIState_hideObjSafe(self, D_004A1618);
        cUIState_hideObjSafe(self, D_0045E438);
        cUIState_showObjSafe(self, D_0045E450);
        cUIState_showObjSafe(self, D_0045E460);
        cFEStateRiderBio_fillDNAInfo(self);
        break;
    case 1:
        cUIState_hideObjSafe(self, D_0045E3F8);
        cUIState_hideObjSafe(self, D_004A1610);
        cUIState_showObjSafe(self, D_0045E408);
        cUIState_showObjSafe(self, D_0045E418);
        cUIState_hideObjSafe(self, D_0045E428);
        cUIState_hideObjSafe(self, D_004A1618);
        cUIState_hideObjSafe(self, D_0045E438);
        cUIState_showObjSafe(self, D_0045E450);
        cUIState_showObjSafe(self, D_0045E460);
        cFEStateRiderBio_fillFavesInfo(self);
        break;
    case 2:
        cUIState_hideObjSafe(self, D_0045E3F8);
        cUIState_hideObjSafe(self, D_004A1610);
        cUIState_hideObjSafe(self, D_0045E408);
        cUIState_hideObjSafe(self, D_0045E418);
        cUIState_showObjSafe(self, D_0045E428);
        cUIState_showObjSafe(self, D_004A1618);
        cUIState_hideObjSafe(self, D_0045E438);
        cUIState_hideObjSafe(self, D_0045E450);
        cUIState_hideObjSafe(self, D_0045E460);
        cFEStateRiderBio_fillQnAInfo(self);
        break;
    case 3:
        cUIState_hideObjSafe(self, D_0045E3F8);
        cUIState_hideObjSafe(self, D_004A1610);
        cUIState_hideObjSafe(self, D_0045E408);
        cUIState_hideObjSafe(self, D_0045E418);
        cUIState_hideObjSafe(self, D_0045E428);
        cUIState_hideObjSafe(self, D_004A1618);
        cUIState_showObjSafe(self, D_0045E438);
        cUIState_hideObjSafe(self, D_0045E450);
        cUIState_hideObjSafe(self, D_0045E460);
        cFEStateRiderBio_fillBioInfo(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", func_00190CD8);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);

struct sNames_0CD8 {
    char* name[10];
};
extern sNames_0CD8 D_0045E470;
extern char D_004A1670[];

extern "C" void func_00190CD8(void* self)
{
    sNames_0CD8 names = D_0045E470;
    char buf[32];
    for (int i = 0; i < 10; i++) {
        sprintf(buf, D_004A1670, names.name[i]);
        if (i == *(int*)((char*)self + 0x48)) {
            cUIState_showObjSafe(self, names.name[i]);
            cUIState_showObjSafe(self, buf);
        } else {
            cUIState_hideObjSafe(self, names.name[i]);
            cUIState_hideObjSafe(self, buf);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", cFEStateRiderBio_fillDNAInfo);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);

struct sDNANames {
    char* name[10][8];
};
extern sDNANames D_0045E998;
extern char D_004A1678[];

extern "C" void cFEStateRiderBio_fillDNAInfo(void* self)
{
    sDNANames names = D_0045E998;
    char buf[16];
    for (int i = 0; i < 8; i++) {
        sprintf(buf, D_004A1678, i + 1);
        cUIText* obj = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        if (obj != 0) {
            cUIText_setUnicodeStringByID(obj, GetHashValue32(names.name[*(int*)((char*)self + 0x48)][i]));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", cFEStateRiderBio_fillFavesInfo);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);

struct sFavesNames {
    char* name[10][12];
};
extern sFavesNames D_0045F2D0;
extern char D_004A1680[];

extern "C" void cFEStateRiderBio_fillFavesInfo(void* self)
{
    sFavesNames names = D_0045F2D0;
    char buf[16];
    for (int i = 0; i < 12; i++) {
        sprintf(buf, D_004A1680, i + 1);
        cUIText* obj = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        if (obj != 0) {
            cUIText_setUnicodeStringByID(obj, GetHashValue32(names.name[*(int*)((char*)self + 0x48)][i]));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", cFEStateRiderBio_fillQnAInfo);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);

struct sQnANames {
    char* name[10][4];
};
extern sQnANames D_0045F730;
extern char D_004A1688[];

extern "C" void cFEStateRiderBio_fillQnAInfo(void* self)
{
    sQnANames names = D_0045F730;
    char buf[16];
    for (int i = 0; i < 4; i++) {
        sprintf(buf, D_004A1688, i + 1);
        cUIText* obj = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        if (obj != 0) {
            cUIText_setUnicodeStringByID(obj, GetHashValue32(names.name[*(int*)((char*)self + 0x48)][i]));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", cFEStateRiderBio_fillBioInfo);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* func_0014EEC8(void* self, int player, int index);
extern "C" void func_003A18C0(void* self);
extern "C" void func_003A1F18(void* self, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_0045E438[];
extern char D_0045F7D0[];

extern "C" void cFEStateRiderBio_fillBioInfo(void* self)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E438));
    if (obj) {
        char buf[64];
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 2);
        sprintf(buf, D_0045F7D0, func_0014EEC8(iface, *(int*)((char*)self + 0x48), 0));
        func_003A18C0(obj);
        func_003A1F18(obj, GetHashValue32(buf));
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", func_001912D0);
#ifdef SKIP_ASM
struct sVEntry001912D0 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};
extern "C" void func_0039F400(void* list, void* item);
extern "C" void func_00190A08(void* self);

extern "C" void func_001912D0(void* self, void* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 6: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry001912D0* vt = *(sVEntry001912D0**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    case 9:
        *(int*)((char*)self + 0x4C) = *(unsigned char*)((char*)item + 0x319);
        func_00190A08(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbiodetail", func_00191360);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void *, int);
extern "C" unsigned char func_001A1CD0(void* p, int a);
extern void* D_0046B090[];

extern "C" void* func_00191360(void* self, int a1)
{
    func_0039E2A0(self, a1);
    *(void***)((char*)self + 0x8) = D_0046B090;
    *(int*)((char*)self + 0x48) = 0;
    *(char*)((char*)self + 0x44) = 0;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), 0);
    *(int*)((char*)self + 0xC) = 0x14;
    return self;
}
#endif

