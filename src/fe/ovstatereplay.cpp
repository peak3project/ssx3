#include "common.h"

//100%
INCLUDE_ASM("fe/ovstatereplay", cOVState_REPLAY_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00471BF0[];
extern char D_00471C08[];
extern char D_00471C20[];
extern void* D_004A28A8;

class cUIObj_20DE30 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int v);
    virtual void v07(int v);
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};

extern "C" void cOVState_REPLAY_onWidgetCreate(void* self, cUIObj_20DE30* w)
{
    int id = *(int*)((char*)w + 0x38);
    if (id == GetHashValue32(D_00471BF0)) {
        *(int*)((char*)w + 0x18) = 0;
        if (*(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28) + 0x608) != 0) {
            w->v06(0);
            w->setEnabled(1);
            w->setVisible(0);
        }
    } else {
        int id2 = *(int*)((char*)w + 0x38);
        if (id2 == GetHashValue32(D_00471C08)) {
            *(int*)((char*)w + 0x18) = 1;
        } else {
            int id3 = *(int*)((char*)w + 0x38);
            if (id3 == GetHashValue32(D_00471C20)) {
                *(int*)((char*)w + 0x18) = 2;
            }
        }
    }
}
#endif

INCLUDE_ASM("fe/ovstatereplay", func_0020DF10);

INCLUDE_ASM("fe/ovstatereplay", func_0020DF38);

//100%
INCLUDE_ASM("fe/ovstatereplay", cOVState_REPLAY_onUpdate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void func_0020E900(void* self);
extern "C" void func_0026FA78(void* p);
extern "C" void cOVState_REPLAY_setupCameraName(void* self);
extern "C" void cOVState_REPLAY_setupTicker(void* self);
extern void* D_004A28A8;
extern char D_00471C30[];
extern char D_00471BB0[];
extern char D_00471BA0[];
extern char D_004A2728[];

struct sVec3_0020E530 {
    float x, y, z;
};

struct sReplay_0020E530 {
    char pad_0x0[0x40];
    void* screen;       // 0x40
    char pad_0x44[0x58];
    int paused;         // 0x9C
    char pad_0xA0[0x4];
    int pos;            // 0xA4
    int speed;          // 0xA8
    int start;          // 0xAC
    int end;            // 0xB0
};

extern "C" void cOVState_REPLAY_onUpdate(void* p)
{
    sReplay_0020E530* self = (sReplay_0020E530*)p;
    func_0020E900(self);
    self->pos += self->speed;
    if (self->pos <= self->start) {
        self->pos = self->start;
        self->speed = 0;
    } else if (self->pos >= self->end) {
        self->pos = self->end;
        self->speed = 0;
    }
    if (self->pos == self->start) {
        cUIState_showObjSafe(self, D_00471C30);
        cUIState_hideObjSafe(self, D_00471BB0);
    } else if (self->pos == self->end) {
        cUIState_hideObjSafe(self, D_00471C30);
        cUIState_showObjSafe(self, D_00471BB0);
    } else {
        cUIState_hideObjSafe(self, D_00471C30);
        cUIState_hideObjSafe(self, D_00471BB0);
    }
    char* obj = (char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_004A2728));
    sVec3_0020E530 v = *(sVec3_0020E530*)(obj + 0x44);
    v.y = (float)self->pos;
    *(sVec3_0020E530*)(obj + 0x44) = v;
    if (self->paused != 0) {
        cUIState_showObjSafe(self, D_00471BA0);
    } else {
        cUIState_hideObjSafe(self, D_00471BA0);
    }
    if (self->paused == 0) {
        func_0026FA78(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28));
    }
    cOVState_REPLAY_setupCameraName(self);
    cOVState_REPLAY_setupTicker(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatereplay", cOVState_REPLAY_setupCameraName);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);
extern void* D_004A28A8;
extern char D_004A2730[];
extern char D_004A2138[];

// Shows the name of the active replay camera.
extern "C" void cOVState_REPLAY_setupCameraName(void* self)
{
    char buf[16];
    cUIText* t = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2730));
    if (t == 0) {
        return;
    }
    unsigned int cam = *(unsigned int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28) + 0x630);
    switch (cam) {
    case 0: strcpy(buf, "-  Web-cam"); break;
    case 1: strcpy(buf, "-  Manual-cam"); break;
    case 2: strcpy(buf, "-  Near-cam"); break;
    case 3: strcpy(buf, "-  Mid-cam"); break;
    case 4: strcpy(buf, "-  Far-cam"); break;
    case 5: strcpy(buf, "-  2:00"); break;
    case 6: strcpy(buf, "-  10:00"); break;
    case 7: strcpy(buf, "-  4:00"); break;
    case 8: strcpy(buf, "-  8:00"); break;
    default: sprintf(buf, D_004A2138, cam + 1); break;
    }
    cUIText_setAsciiString(t, buf);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatereplay", cOVState_REPLAY_setupTicker);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_00471CC8[];
extern void* D_004A28A8;
struct sVec3_20E818 {
    float x, y, z;
};

extern "C" void cOVState_REPLAY_setupTicker(void* self)
{
    char* obj = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00471CC8));
    if (obj != 0) {
        sVec3_20E818 pos = *(sVec3_20E818*)(obj + 0x44);
        char* replay = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
        int total = *(int*)(replay + 0x3CC);
        float frac;
        if (total > 0) {
            frac = (float)*(int*)(replay + 0x484) / (float)total;
        } else {
            frac = 0.0f;
        }
        pos.x = frac * 315.0f + 170.0f;
        *(sVec3_20E818*)(obj + 0x44) = pos;
    }
}
#endif

extern "C" void func_0039E6B8(void* self);

//100%
INCLUDE_ASM("fe/ovstatereplay", func_0020E8E0__FPv);
#ifdef SKIP_ASM
void func_0020E8E0(void* self)
{
    func_0039E6B8(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatereplay", func_0020E900);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" int func_00231840(void* game, int a);
extern "C" void func_0039E510(void* self);

extern "C" void func_0020E900(void* self)
{
    func_00231840(*(void**)((char*)D_004A28A8 + 0x84), 1);
    func_0039E510(self);
}
#endif

