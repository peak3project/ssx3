#include "common.h"

// A UI widget as cUIScreen_getObjectByHashName returns it: vptr at 0x8. Slot names from the prototype's
// _vt$8cUIThing (as in fe/feasyncfile); the other slots are known only by position.
class cUIThing {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void setEnabled(int v);
    virtual void setFocus(int v);
    virtual void setStatic(int v);
    virtual void setVisible(int v);
};

// Declarations shared by the functions of this unit.
struct cUIText;
int GetHashValue32(char* str);
extern void* D_004A28A8;
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);

//100%
INCLUDE_ASM("fe/ovstatereplay", cOVState_REPLAY_onWidgetCreate);
#ifdef SKIP_ASM
extern char D_00471BF0[];
extern char D_00471C08[];
extern char D_00471C20[];

extern "C" void cOVState_REPLAY_onWidgetCreate(void* self, cUIThing* w)
{
    int id = *(int*)((char*)w + 0x38);
    if (id == GetHashValue32(D_00471BF0)) {
        *(int*)((char*)w + 0x18) = 0;
        if (*(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28) + 0x608) != 0) {
            w->setEnabled(0);
            w->setStatic(1);
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

//100%
INCLUDE_ASM("fe/ovstatereplay", func_0020DF38);
#ifdef SKIP_ASM
// g++ 2.95 vtable slot: this-pointer adjustment, index, function.
template <class F> struct sVEntry_DF38 {
    short delta;
    short index;
    F* fn;
};

struct sSnd_DF38 {
    sVEntry_DF38<void(void*, int)>* vt;
};

struct sPadEvent_DF38 {
    char pad_0x0[0x4];
    unsigned char port;                     // 0x4
    char pad_0x5[0x3];
    sVEntry_DF38<int(void*)>* vt;           // 0x8
};

struct sOwner_DF38 {
    char pad_0x0[0x14];
    sSnd_DF38* snd;                         // 0x14
    char list[1];                           // 0x18
};

struct sReplay_DF38 {
    char pad_0x0[0x10];
    sOwner_DF38* owner;                     // 0x10
    char pad_0x14[0x2C];
    void* screen;                           // 0x40
    char pad_0x44[0x58];
    int paused;                             // 0x9C
    int field_0xA0;                                // 0xA0
    int pos;                                // 0xA4
    int speed;                              // 0xA8
    int start;                              // 0xAC
    int end;                                // 0xB0
    int field_0xB4;                             // 0xB4
};

struct cUIScreen;
int func_00320C48(void* pad, int button);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void func_0039F190(void* list, int a1);
extern "C" void func_0026F980(void* replay);
extern "C" void func_002706B8(void* replay);
extern "C" void cGame_exit(void* game, int a);
extern "C" void func_0020AB50(int state);
extern "C" int func_0026FB88(void* replay, int a1);
extern sSnd_DF38 D_004A5A58;
extern int D_004A2A50;
extern int D_004A2A54;
extern int D_005366E8[];
extern int D_004428F0[];
extern int D_004428F8[];
extern char D_00471BE0[];
extern char D_0046E050[];
extern char D_004A2720[];
extern char D_00471BC0[];
extern char D_00471BD0[];

static inline char* game_DF38()
{
    return *(char**)((char*)D_004A28A8 + 0x84);
}

static inline char* replay_DF38()
{
    return *(char**)(game_DF38() + 0x28);
}

struct sApp_DF38 {
    char pad_0x0[0x84];
    char* game;                             // 0x84
    char pad_0x88[0x28];
    void* pads[1];                          // 0xB0
};

static inline void* pad_DF38(int port)
{
    return ((sApp_DF38*)D_004A28A8)->pads[port];
}

static inline void play_DF38(sSnd_DF38* snd, int id)
{
    snd->vt[2].fn((char*)snd + snd->vt[2].delta, id);
}

extern "C" int func_0020DF38(sReplay_DF38* self, sPadEvent_DF38* ev)
{
    sSnd_DF38* snd = &D_004A5A58;
    if (self->owner->snd != 0)
        snd = self->owner->snd;
    if (ev->port != *(unsigned int*)(replay_DF38() + 0x28))
        return 1;
    if (self->paused == 0 && func_00320C48(pad_DF38(ev->port), 0xCA)) {
        if (self->pos == self->end || self->speed == 4)
            play_DF38(snd, 2);
        self->speed = -4;
        return 1;
    } else if (self->paused == 0 && func_00320C48(pad_DF38(ev->port), 0xCB)) {
        if (self->pos == self->start || self->speed == -4)
            play_DF38(snd, 2);
        self->speed = 4;
        return 1;
    } else if (ev->vt[3].fn((char*)ev + ev->vt[3].delta) && self->paused == 0) {
        play_DF38(snd, 6);
        D_005366E8[++D_004A2A54] = 2;
        D_004A2A50 = D_004428F8[0];
        self->paused = 1;
        char* obj = (char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471BE0));
        *(int*)(obj + 0x90) &= ~8;
        return 1;
    } else if (self->paused != 0 && ev->vt[5].fn((char*)ev + ev->vt[5].delta)) {
        play_DF38(snd, 6);
        char* obj = (char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471BE0));
        switch (*(int*)(*(char**)(obj + 0xA0) + 0x18)) {
        case 0:
            func_0026F980(replay_DF38());
            func_0020AB50(0x12);
            D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
            break;
        case 1: {
            func_0039F190(self->owner->list, 1);
            unsigned short frame = cUIScreen_getFrameByLabel((cUIScreen*)self->screen, GetHashValue32(D_0046E050));
            if (frame != 0xFFFF)
                cUIScreen_playFrame(self->screen, frame, 1);
            func_0026F980(replay_DF38());
            if (self->field_0xB4 == 0)
                func_002706B8(replay_DF38());
            if (*(int*)(replay_DF38() + 0x608) != 0)
                cGame_exit(game_DF38(), 0);
            D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
            break;
        }
        case 2:
            self->paused = 0;
            D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
            break;
        }
        return 1;
    } else if (self->paused != 0 && ev->vt[6].fn((char*)ev + ev->vt[6].delta)) {
        play_DF38(snd, 3);
        D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
        self->paused = 0;
        char* obj = (char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471BE0));
        *(int*)(obj + 0x90) |= 8;
        return 1;
    } else if (self->paused == 0 && func_00320C48(pad_DF38(ev->port), 0xCC)) {
        play_DF38(snd, 6);
        self->field_0xA0 ^= 1;
        if (self->field_0xA0 != 0) {
            cUIState_hideObjSafe(self, D_004A2720);
            cUIState_hideObjSafe(self, D_00471BC0);
            cUIState_showObjSafe(self, D_00471BD0);
        } else {
            cUIState_showObjSafe(self, D_004A2720);
            cUIState_showObjSafe(self, D_00471BC0);
            cUIState_hideObjSafe(self, D_00471BD0);
        }
        return 1;
    } else if (ev->vt[17].fn((char*)ev + ev->vt[17].delta)) {
        char* obj = (char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471BE0));
        if (obj != 0 && self->field_0xB4 != 0 && *(unsigned char*)(obj + 0x95) == 1)
            return 1;
    } else if (ev->vt[18].fn((char*)ev + ev->vt[18].delta)) {
        char* obj = (char*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00471BE0));
        if (obj != 0 && self->field_0xB4 != 0 && *(unsigned char*)(obj + 0x95) == 2)
            return 1;
    }
    if (self->paused != 0)
        return 0;
    return func_0026FB88(replay_DF38(), 0);
}
#endif

//100%
INCLUDE_ASM("fe/ovstatereplay", cOVState_REPLAY_onUpdate);
#ifdef SKIP_ASM
extern "C" void cUIState_showObjSafe(void* self, char* name);
extern "C" void cUIState_hideObjSafe(void* self, char* name);
extern "C" void func_0020E900(void* self);
extern "C" void func_0026FA78(void* p);
extern "C" void cOVState_REPLAY_setupCameraName(void* self);
extern "C" void cOVState_REPLAY_setupTicker(void* self);
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
extern "C" void* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);
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
extern char D_00471CC8[];
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
extern "C" int func_00231840(void* game, int a);
extern "C" void func_0039E510(void* self);

extern "C" void func_0020E900(void* self)
{
    func_00231840(*(void**)((char*)D_004A28A8 + 0x84), 1);
    func_0039E510(self);
}
#endif

