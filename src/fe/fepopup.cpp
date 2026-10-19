#include "common.h"

//100%
INCLUDE_ASM("fe/fepopup", cScreenPopup_cScreenPopup);
#ifdef SKIP_ASM
extern "C" void* func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_001C55F8(void* self);
extern "C" void func_00416210(void* dst, int c, int n);
extern void* D_0046CBD8[];
extern int D_004A3E90;
struct sVec3_58E8 {
    float x, y, z;
    sVec3_58E8(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct sQuad_58E8 { int v[4]; };
extern sQuad_58E8 D_004C6788;
extern sQuad_58E8 D_004C6798;

extern "C" void* cScreenPopup_cScreenPopup(void* self, void* engine, void* owner)
{
    func_0039E318(self, engine, owner);
    *(void***)((char*)self + 0x8) = D_0046CBD8;
    func_001C55F8((char*)self + 0xBC);
    int d = D_004A3E90;
    *(int*)((char*)self + 0x2B0) = d;
    *(int*)((char*)self + 0x2B4) = d;
    *(int*)((char*)self + 0x2C4) = -1;
    *(int*)((char*)self + 0x2A8) = 0;
    *(int*)((char*)self + 0x2B8) = 0;
    *(int*)((char*)self + 0x2BC) = 0;
    *(int*)((char*)self + 0x30C) = 0;
    *(int*)((char*)self + 0x2C0) = 0;
    *(int*)((char*)self + 0x314) = 0;
    for (int j = 0; j < 5; j++)
        func_00416210((char*)self + 0x2D0 + j * 12, 0, 12);
    *(int*)((char*)self + 0x310) = 1;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x6C) = 0;
    *(int*)((char*)self + 0x70) = 0;
    *(int*)((char*)self + 0x74) = 0;
    *(int*)((char*)self + 0x78) = 0;
    *(int*)((char*)self + 0x7C) = 0;
    *(int*)((char*)self + 0x80) = 0;
    *(int*)((char*)self + 0x88) = 0;
    *(int*)((char*)self + 0x84) = 0;
    *(int*)((char*)self + 0x8C) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x58) = 0;
    *(int*)((char*)self + 0x5C) = 0;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x68) = 0;
    for (int i = 0; i < 5; i++)
        ((int*)((char*)self + 0x90))[i] = 0;
    *(int*)((char*)self + 0x31C) = 0;
    *(sVec3_58E8*)((char*)self + 0x278) = sVec3_58E8(1.0f, 1.0f, 1.0f);
    *(int*)((char*)self + 0x2C8) = 0;
    *(int*)((char*)self + 0x2CC) = 0;
    *(sQuad_58E8*)((char*)self + 0x32C) = D_004C6788;
    *(sQuad_58E8*)((char*)self + 0x33C) = D_004C6798;
    *(int*)((char*)self + 0x328) = 0x3F;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C5A90);
#ifdef SKIP_ASM
extern void* D_0046CBD8[];
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void func_001C5750(void* self, int flags);
extern "C" void func_0039E390(void* self, int flags);

extern "C" void func_001C5A90(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046CBD8;
    cBXString__cBXString((char*)self + 0x2B4, 2);
    cBXString__cBXString((char*)self + 0x2B0, 2);
    func_001C5750((char*)self + 0xBC, 2);
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cScreenPopup_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A1C40[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cScreenPopup_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A1C40), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        *(int*)((char*)self + 0x2B8) = 1;
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

void* func_0039E4A0(void*);

//100%
INCLUDE_ASM("fe/fepopup", func_001C5B68__FPv);
#ifdef SKIP_ASM
void* func_001C5B68(void* self)
{
    *(int*)((char*)self + 0x2b8) = 0;
    return func_0039E4A0(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C5B88);
#ifdef SKIP_ASM
struct sVE5B88 {
    short delta;
    short index;
    void* fn;
};
extern "C" void func_001C5F20(void* self, float t);
extern "C" void func_001C75C8(void* self, void* menu, int idx, int max);

extern "C" void func_001C5B88(void* self)
{
    if (*(void**)((char*)self + 0x6C) != 0) {
        func_001C5F20(self, 1.0f);
        {
            char* o = *(char**)((char*)self + 0x6C);
            sVE5B88* vt = *(sVE5B88**)(o + 8);
            ((void (*)(void*, int))vt[8].fn)(o + vt[8].delta, 0);
        }
        func_001C75C8(self, *(void**)((char*)self + 0x6C), *(int*)((char*)self + 0x2C4), *(int*)((char*)self + 0x30C));
        {
            char* o = *(char**)((char*)self + 0x6C);
            sVE5B88* vt = *(sVE5B88**)(o + 8);
            ((void (*)(void*, int))vt[7].fn)(o + vt[7].delta, 1);
        }
        {
            sVE5B88* vt = *(sVE5B88**)((char*)self + 8);
            ((int (*)(void*, void*, int, int))vt[20].fn)((char*)self + vt[20].delta, *(void**)((char*)self + 0x6C), 5, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cScreenPopup_onGainTransition);
#ifdef SKIP_ASM
struct cUIScreen;
struct sColor_7738;
struct sColF_5C30 { float r, g, b; };
struct sVec3_5C30 { float x, y, z; };
int GetHashValue32(char* str);
int cUIScreen_getFrameByLabel(cUIScreen* screen, int hash);
extern "C" void func_001C5F20(void* self, float t);
extern "C" void func_001C6B08(void* self, void* p);
extern "C" void func_001C7738(void* self, sColor_7738* color);
extern char D_004A1C48[];

extern "C" int cScreenPopup_onGainTransition(void* self, int first)
{
    if (first) {
        sColF_5C30 c;
        c.r = 0.2f;
        c.g = 0.2f;
        c.b = 1.0f;
        *(int*)((char*)self + 0x2BC) = 1;
        func_001C6B08(self, (char*)self + 0xBC);
        func_001C7738(self, (sColor_7738*)&c);
        if (*(int*)((char*)self + 0x31C) == 1)
            func_001C5F20(self, 0.0f);
        int f = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_004A1C48));
        if (f != 0xFFFF)
            *(int*)((char*)self + 0xA8) = f;
        else
            *(int*)((char*)self + 0xA8) = 25;
        if (*(int*)((char*)self + 0xA8) == 1)
            *(int*)((char*)self + 0xA8) = 2;
        *(int*)((char*)self + 0xA4) = 1;
        *(float*)((char*)self + 0xAC) = (*(float*)((char*)self + 0x278) - 0.2f) / (float)(*(int*)((char*)self + 0xA8) - 1);
        *(float*)((char*)self + 0xB0) = (*(float*)((char*)self + 0x27C) - 0.2f) / (float)(*(int*)((char*)self + 0xA8) - 1);
    }
    if (*(int*)((char*)self + 0x31C) == 1) {
        float t = (float)*(int*)((char*)self + 0xA4);
        sVec3_5C30 pos = *(sVec3_5C30*)(*(char**)((char*)self + 0x58) + 0x44);
        sColF_5C30 c;
        c.r = t * *(float*)((char*)self + 0xAC) + 0.2f;
        c.g = t * *(float*)((char*)self + 0xB0) + 0.2f;
        func_001C7738(self, (sColor_7738*)&c);
        if (*(int*)((char*)self + 0xA4) < *(int*)((char*)self + 0xA8)) {
            *(int*)((char*)self + 0xA4) += 1;
            return 0;
        }
    } else {
        sColF_5C30 c = *(sColF_5C30*)((char*)self + 0x278);
        func_001C7738(self, (sColor_7738*)&c);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C5DD0__FPv);
#ifdef SKIP_ASM
int func_001C5DD0(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C5DD8);
#ifdef SKIP_ASM
struct sColor_7738;
struct sColor5DD8 { int r, g, b; };
struct sVEntry001C5DD8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
extern "C" void func_001C8A38(void* self);
extern "C" void func_001C6B08(void* self, void* p);
extern "C" void func_001C7738(void* self, sColor_7738* color);

extern "C" void func_001C5DD8(void* self)
{
    if (*(int*)((char*)self + 0x2BC) != 0) {
        func_001C8A38(self);
        func_001C6B08(self, (char*)self + 0xBC);
        sColor5DD8 c = *(sColor5DD8*)((char*)self + 0x278);
        func_001C7738(self, (sColor_7738*)&c);
        sVEntry001C5DD8* vt = *(sVEntry001C5DD8**)((char*)self + 8);
        vt[6].fn((char*)self + vt[6].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C5E58);
#ifdef SKIP_ASM
struct sVEntry_5E58 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void Call9_5E58(char* o, int a)
{
    if (o != 0) {
        sVEntry_5E58* vt = *(sVEntry_5E58**)(o + 8);
        vt[9].fn(o + vt[9].delta, a);
    }
}

extern "C" void func_001C5E58(void* self, int a)
{
    char* s = (char*)self;
    Call9_5E58(*(char**)(s + 0x70), a);
    Call9_5E58(*(char**)(s + 0x74), a);
    Call9_5E58(*(char**)(s + 0x78), a);
    Call9_5E58(*(char**)(s + 0x7C), a);
    Call9_5E58(*(char**)(s + 0x88), a);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C5F20);
#ifdef SKIP_ASM
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct sColor_5F20 { float a, r, g, b; };
struct sVEntry_5F20 {
    short delta;
    short index;
    void (*fn)(void*, sColor_5F20*);
};
extern char D_004A1C50[];
extern char D_004A1C58[];
extern char D_004A15E0[];

static inline void SetAlpha_5F20(char* o, float t)
{
    if (o != 0) {
        sColor_5F20 c = *(sColor_5F20*)(o + 0x1C);
        c.a = t;
        sVEntry_5F20* vt = *(sVEntry_5F20**)(o + 8);
        vt[11].fn(o + vt[11].delta, &c);
    }
}

extern "C" void func_001C5F20(void* self, float t)
{
    char* s = (char*)self;
    SetAlpha_5F20(*(char**)(s + 0x70), t);
    SetAlpha_5F20(*(char**)(s + 0x74), t);
    SetAlpha_5F20(*(char**)(s + 0x78), t);
    SetAlpha_5F20(*(char**)(s + 0x7C), t);
    SetAlpha_5F20(*(char**)(s + 0x88), t);
    SetAlpha_5F20((char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004A1C50)), t);
    SetAlpha_5F20((char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004A1C58)), t);
    SetAlpha_5F20((char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004A15E0)), t);
    for (int i = 0; i < 5; i++) {
        SetAlpha_5F20(((char**)(s + 0x90))[i], t);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cScreenPopup_FillObjectPointers);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_0045DB90[];
extern char D_00465FA8[];
extern char D_00465FB8[];
extern char D_00465FC8[];
extern char D_00465FD8[];
extern char D_00465FE8[];
extern char D_00465FF8[];
extern char D_00466008[];
extern char D_00466018[];
extern char D_00466028[];
extern char D_00466038[];
extern char D_00466048[];
extern char D_00466058[];
extern char D_00466070[];
extern char D_004A1C60[];
extern char D_004A1C68[];
extern char D_004A1C70[];
extern char D_004A1C78[];
extern char D_00466080[];

struct sV3_6260 {
    float x, y, z;
};

struct sVE_6260 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sObj_6260 {
    char pad0[0x8];
    sVE_6260* vt;                   // 0x8
    char padC[0x44 - 0xC];
    sV3_6260 pos;                   // 0x44
    void GetRect(void* out) { vt[20].fn((char*)this + vt[20].delta, out); }
};

static inline sObj_6260* find_6260(void* self, char* name)
{
    return (sObj_6260*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

#define POS_6260(o) (*(sV3_6260*)((char*)self + (o)))
#define OBJ_6260(o) (*(sObj_6260**)((char*)self + (o)))

// Looks up the popup's widgets by name and caches them (and their positions) in the screen object.
extern "C" void cScreenPopup_FillObjectPointers(void* self)
{
    if (sObj_6260* o = find_6260(self, D_004A1C60)) {
        POS_6260(0x188) = o->pos;
        o->GetRect((char*)self + 0x1F4);
        OBJ_6260(0x48) = o;
    }
    if (sObj_6260* o = find_6260(self, D_004A1C68)) {
        POS_6260(0x194) = o->pos;
        OBJ_6260(0x4C) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00465FA8))
        OBJ_6260(0x64) = o;
    if (sObj_6260* o = find_6260(self, D_00465FB8)) {
        POS_6260(0x230) = o->pos;
        OBJ_6260(0x54) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00465FC8)) {
        POS_6260(0x224) = o->pos;
        OBJ_6260(0x50) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00465FD8)) {
        POS_6260(0x248) = o->pos;
        OBJ_6260(0x5C) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00465FE8)) {
        POS_6260(0x23C) = o->pos;
        o->GetRect((char*)self + 0x218);
        OBJ_6260(0x58) = o;
    }
    if (sObj_6260* o = find_6260(self, D_004A1C70)) {
        POS_6260(0x254) = o->pos;
        OBJ_6260(0x60) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00465FF8))
        OBJ_6260(0x68) = o;
    if (sObj_6260* o = find_6260(self, D_0045DB90)) {
        POS_6260(0x1A0) = o->pos;
        OBJ_6260(0x6C) = o;
    }
    if (sObj_6260* o = find_6260(self, D_004A1C78)) {
        POS_6260(0x1AC) = o->pos;
        OBJ_6260(0x70) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00466008)) {
        POS_6260(0x1C4) = o->pos;
        OBJ_6260(0x74) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00466018)) {
        POS_6260(0x1B8) = o->pos;
        OBJ_6260(0x7C) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00466028)) {
        POS_6260(0x1D0) = o->pos;
        OBJ_6260(0x78) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00466038)) {
        POS_6260(0x1DC) = o->pos;
        OBJ_6260(0x80) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00466048)) {
        POS_6260(0x1E8) = o->pos;
        OBJ_6260(0x88) = o;
    }
    if (sObj_6260* o = find_6260(self, D_00466058))
        OBJ_6260(0x84) = o;
    if (sObj_6260* o = find_6260(self, D_00466070)) {
        POS_6260(0x200) = o->pos;
        o->GetRect((char*)self + 0x20C);
        OBJ_6260(0x8C) = o;
    }
    for (int i = 0; i < 5; i++) {
        char name[32];
        sprintf(name, D_00466080, i);
        sObj_6260* o = find_6260(self, name);
        if (o != 0)
            ((sObj_6260**)((char*)self + 0x90))[i] = o;
    }
}
#undef POS_6260
#undef OBJ_6260
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C66E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001CA488(void* self, void* obj);
extern "C" void func_001CA4C0(void* self, void* obj);
extern sQuad_58E8 D_004C67A8;

struct sVEp_C66E8 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

static inline void SetColor_C66E8(char* o, sQuad_58E8* c)
{
    if (o != 0) {
        sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
        vt[11].fn(o + vt[11].delta, c);
    }
}

extern "C" void func_001C66E8_impl(char* self) __asm__("func_001C66E8");
extern "C" void func_001C66E8_impl(char* self)
{
    switch (*(int*)(self + 0x31C)) {
    case 0:
        func_001CA4C0(self, *(void**)(self + 0x64));
        func_001CA4C0(self, *(void**)(self + 0x48));
        func_001CA4C0(self, *(void**)(self + 0x4C));
        func_001CA488(self, *(void**)(self + 0x50));
        func_001CA488(self, *(void**)(self + 0x54));
        func_001CA488(self, *(void**)(self + 0x58));
        func_001CA488(self, *(void**)(self + 0x5C));
        func_001CA488(self, *(void**)(self + 0x60));
        func_001CA488(self, *(void**)(self + 0x68));
        {
            char* o = *(char**)(self + 0x74);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        {
            char* o = *(char**)(self + 0x78);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        {
            char* o = *(char**)(self + 0x7C);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        {
            char* o = *(char**)(self + 0x80);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        *(sQuad_58E8*)(self + 0x32C) = D_004C6788;
        *(sQuad_58E8*)(self + 0x33C) = D_004C6798;
        break;
    case 1:
        func_001CA4C0(self, *(void**)(self + 0x64));
        func_001CA4C0(self, *(void**)(self + 0x50));
        func_001CA4C0(self, *(void**)(self + 0x54));
        func_001CA4C0(self, *(void**)(self + 0x58));
        func_001CA4C0(self, *(void**)(self + 0x5C));
        func_001CA4C0(self, *(void**)(self + 0x60));
        func_001CA488(self, *(void**)(self + 0x48));
        func_001CA488(self, *(void**)(self + 0x4C));
        func_001CA488(self, *(void**)(self + 0x68));
        {
            char* o = *(char**)(self + 0x74);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        {
            char* o = *(char**)(self + 0x78);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        {
            char* o = *(char**)(self + 0x7C);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        {
            char* o = *(char**)(self + 0x80);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6798);
            }
        }
        *(sQuad_58E8*)(self + 0x32C) = D_004C6788;
        *(sQuad_58E8*)(self + 0x33C) = D_004C6798;
        break;
    case 2:
        func_001CA488(self, *(void**)(self + 0x48));
        func_001CA488(self, *(void**)(self + 0x4C));
        func_001CA488(self, *(void**)(self + 0x50));
        func_001CA488(self, *(void**)(self + 0x54));
        func_001CA488(self, *(void**)(self + 0x58));
        func_001CA488(self, *(void**)(self + 0x5C));
        func_001CA488(self, *(void**)(self + 0x60));
        func_001CA488(self, *(void**)(self + 0x64));
        func_001CA4C0(self, *(void**)(self + 0x68));
        {
            char* o = *(char**)(self + 0x74);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6788);
            }
        }
        {
            char* o = *(char**)(self + 0x78);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6788);
            }
        }
        {
            char* o = *(char**)(self + 0x7C);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6788);
            }
        }
        {
            char* o = *(char**)(self + 0x80);
            if (o != 0) {
                sVEp_C66E8* vt = *(sVEp_C66E8**)(o + 8);
                vt[11].fn(o + vt[11].delta, &D_004C6788);
            }
        }
        *(sQuad_58E8*)(self + 0x32C) = D_004C67A8;
        *(sQuad_58E8*)(self + 0x33C) = D_004C6788;
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001C6B08);
#ifdef SKIP_ASM
struct cUIText;
struct sVec3_6B08 {
    float x, y, z;
    sVec3_6B08() {}
    sVec3_6B08(float a, float b, float c) : x(a), y(b), z(c) {}
};
extern "C" void cScreenPopup_FillObjectPointers(void* self);
extern "C" sVec3_6B08* func_001C58D0(void* info, int i);
extern "C" void func_001C8678(void* self, void* a1);
extern "C" void func_001C7258(void* self, void* a1);
extern "C" void func_001C7388(void* self, void* a1);
extern "C" void func_001C8758(void* self);
extern "C" void func_001C88C8(void* self);
extern "C" void func_001C7040(void* self, void* a1);
extern "C" void func_001C9CD0(void* self, int v);
extern "C" void func_001C66E8(void* self, int v);
extern "C" void func_001C7C20(void* self);
extern "C" void func_001C7EB0(void* self);
extern "C" void cScreenPopup_checkAndFixTextEntry(void* self, cUIText* text, const char* str);

extern "C" void func_001C6B08(void* self, void* info)
{
    cScreenPopup_FillObjectPointers(self);
    *(int*)((char*)self + 0x18) = *(int*)((char*)info + 0x94);
    *(int*)((char*)self + 0x2C0) = *(int*)((char*)info + 0x98);
    *(int*)((char*)self + 0x310) = *(int*)((char*)info + 0xA8);
    *(int*)((char*)self + 0x30C) = *(int*)((char*)info + 0x0);
    *(int*)((char*)self + 0x2C8) = *(int*)((char*)info + 0xB8);
    *(int*)((char*)self + 0x2CC) = *(int*)((char*)info + 0xBC);
    float t = *(float*)((char*)info + 0xB0);
    *(float*)((char*)self + 0x318) = t;
    if (t != 0.0f)
        *(sVec3_6B08*)((char*)self + 0x260) = sVec3_6B08(t, 0.0f, 0.0f);
    else if (*(int*)((char*)self + 0x2CC) == 0)
        *(sVec3_6B08*)((char*)self + 0x260) = sVec3_6B08(472.0f, 0.0f, 0.0f);
    else
        *(sVec3_6B08*)((char*)self + 0x260) = sVec3_6B08(300.0f, 0.0f, 0.0f);
    for (int i = 0; i < 5; i++)
        ((sVec3_6B08*)((char*)self + 0x2D0))[i] = *func_001C58D0(info, i);
    sVec3_6B08 c = *(sVec3_6B08*)((char*)info + 0x9C);
    *(sVec3_6B08*)((char*)self + 0x26C) = c;
    func_001C8678(self, info);
    func_001C7258(self, info);
    func_001C7388(self, info);
    func_001C8758(self);
    func_001C88C8(self);
    func_001C7040(self, info);
    int v = *(int*)((char*)info + 0x90);
    *(int*)((char*)self + 0x314) = v;
    if (v != 0)
        func_001C9CD0(self, v);
    int m = *(int*)((char*)info + 0xC0);
    *(int*)((char*)self + 0x31C) = m;
    func_001C66E8(self, m);
    *(int*)((char*)self + 0x2C4) = *(int*)((char*)info + 0xAC);
    *(int*)((char*)self + 0x328) = *(int*)((char*)info + 0xC4);
    func_001C7C20(self);
    if (*(int*)((char*)info + 0x0) == -1) {
        func_001C7EB0(self);
        cScreenPopup_checkAndFixTextEntry(self, *(cUIText**)((char*)self + 0x80), *(const char**)((char*)self + 0x2B0));
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C6D30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cUIText;
struct sVec3_6D30 { float x, y, z; };
class cUIObj_6D30 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};
struct sPopup_6D30 {
    char pad[0x80];
    cUIObj_6D30* o80;
    cUIObj_6D30* o84;
    cUIObj_6D30* o88;
    cUIObj_6D30* o8C;
};
extern sVec3_6D30 D_004FF0D8_6D30 __asm__("D_004FF0D8");
extern "C" void func_001C80E8(void* self, void* dst, int* info);
extern "C" void func_001C8050(void* self, cUIText* text, int* info);
extern "C" void func_001C8628(void* self, void* obj, void* out);
extern "C" void func_001C8320(void* self, cUIText* text, int* info, float* out);
extern "C" void func_001C9B68(void* self, float* size, float* item);

extern "C" int func_001C6D30(void* self, void* infop)
{
    int* info = (int*)infop;
    sPopup_6D30* p = (sPopup_6D30*)self;
    float size[4];
    if (info[0] == -1) {
        sVec3_6D30 pos = D_004FF0D8_6D30;
        float w = 0.0f;
        if (p->o84 != 0) {
            float item[4];
            int* it = info + 5;
            func_001C8050(self, (cUIText*)p->o84, it);
            func_001C8628(self, p->o84, size);
            func_001C8320(self, (cUIText*)p->o84, it, item);
            w = item[2];
            pos = *(sVec3_6D30*)((char*)p->o84 + 0x44);
            p->o84->setEnabled(0);
            p->o84->setVisible(1);
        }
        if (p->o80 != 0) {
            func_001C80E8(self, (char*)self + 0x2B0, info + 7);
            sVec3_6D30 v = pos;
            v.x = v.x + w + 10.0f;
            *(sVec3_6D30*)((char*)p->o80 + 0x44) = v;
            func_001C9B68(self, (float*)((char*)self + 0x260), size);
            p->o80->setEnabled(0);
            p->o80->setVisible(1);
        }
        if (p->o88 != 0) {
            p->o88->setEnabled(0);
            p->o88->setVisible(1);
        }
        if (p->o8C != 0) {
            p->o8C->setVisible(1);
        }
        info[0] = 1;
        return 1;
    }
    if (p->o88 != 0) {
        p->o88->setEnabled(1);
        p->o88->setVisible(0);
    }
    if (p->o84 != 0) {
        p->o84->setEnabled(1);
        p->o84->setVisible(0);
    }
    if (p->o80 != 0) {
        p->o80->setEnabled(1);
        p->o80->setVisible(0);
    }
    if (p->o8C != 0) {
        p->o8C->setVisible(0);
    }
    func_001C8628(self, p->o80, size);
    func_001C9B68(self, (float*)((char*)self + 0x260), size);
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C7040);
#ifdef SKIP_ASM
struct sVec3_7040 { float x, y, z; };
extern "C" void func_001C97E0(void* self, void* a, void* b, int which, float t);
extern "C" void func_001C8930(void* self, void* obj, unsigned char state, float t);

extern "C" void func_001C7040(void* self, void* a1)
{
    char* o = *(char**)((char*)self + 0x78);
    if (o != 0) {
        if (*(int*)((char*)a1 + 0x4C) != 0) {
            sVec3_7040 v = *(sVec3_7040*)((char*)self + 0x1B8);
            v.y += *(float*)((char*)self + 0x264);
            *(sVec3_7040*)(o + 0x44) = v;
            func_001C97E0(self, (char*)a1 + 0x4C, (char*)self + 0x260, 0, 10.0f);
            if (*(int*)((char*)self + 0x2CC) != 0) {
                func_001C8930(self, *(void**)((char*)self + 0x78), 0x11, 0.0f);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C70F0);
#ifdef SKIP_ASM
struct cW_70F0 {
    int f0, f4;
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
    virtual void get(void* out);
    virtual void set(void* in);
};
struct sVec3_70F0 { float x, y, z; };
struct sVec3_7258;

extern "C" void func_001C70F0(void* self, sVec3_7258* vp)
{
    sVec3_70F0* v = (sVec3_70F0*)vp;
    cW_70F0* o = *(cW_70F0**)((char*)self + 0x74);
    if (o != 0) {
        sVec3_70F0 t;
        o->get(&t);
        if (v->x != 0.0f) t.x = v->x;
        if (v->y != 0.0f) t.y = v->y;
        (*(cW_70F0**)((char*)self + 0x74))->set(v);
    }
    o = *(cW_70F0**)((char*)self + 0x78);
    if (o != 0) {
        sVec3_70F0 t;
        o->get(&t);
        if (v->x != 0.0f) t.x = v->x;
        if (v->y != 0.0f) t.y = v->y;
        (*(cW_70F0**)((char*)self + 0x78))->set(&t);
    }
    o = *(cW_70F0**)((char*)self + 0x7C);
    if (o != 0) {
        sVec3_70F0 t;
        o->get(&t);
        if (v->x != 0.0f) t.x = v->x;
        if (v->y != 0.0f) t.y = v->y;
        (*(cW_70F0**)((char*)self + 0x7C))->set(v);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001C7258);
#ifdef SKIP_ASM
struct sVec3_7258 { float x, y, z; };
extern sVec3_7258 D_004FF0D8;
extern "C" void func_001C70F0(void* self, sVec3_7258* v);
extern "C" void func_001C93B0(void* self, int* msg, void* out);
extern "C" void func_001C97E0(void* self, void* a, void* b, int which, float t);
extern "C" void func_001C8930(void* self, void* obj, unsigned char state, float t);

extern "C" void func_001C7258(void* self, void* a1)
{
    char* o = *(char**)((char*)self + 0x74);
    if (o != 0) {
        sVec3_7258 v = *(sVec3_7258*)((char*)self + 0x1B8);
        v.y += *(float*)((char*)self + 0x264);
        *(sVec3_7258*)(o + 0x44) = v;
        char* p = (char*)a1 + 4;
        if (*(int*)((char*)self + 0x2CC) != 0) {
            sVec3_7258 t = D_004FF0D8;
            func_001C93B0(self, (int*)p, &t);
            if (t.x > *(float*)((char*)self + 0x260))
                func_001C70F0(self, &t);
        }
        func_001C97E0(self, p, (char*)self + 0x260, 1, 10.0f);
        if (*(int*)((char*)self + 0x2CC) != 0)
            func_001C8930(self, *(void**)((char*)self + 0x74), 0x11, 0.0f);
    }
    *(sVec3_7258*)((char*)self + 0x284) = *(sVec3_7258*)((char*)self + 0x260);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001C7388);
#ifdef SKIP_ASM
struct cUIText;
class cUIObj_7388 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};
struct sPopup_7388 {
    char pad[0x90];
    cUIObj_7388* items[5];
};
extern "C" int func_001C6D30(void* self, void* info);
extern "C" int* func_001C5800(void* info, int i);
extern "C" void func_001C8050(void* self, cUIText* text, int* info);
extern "C" void func_001C8628(void* self, void* obj, void* out);
extern "C" void func_001C8320(void* self, cUIText* text, int* info, float* out);
extern "C" void func_001C9B68(void* self, float* size, float* item);

extern "C" void func_001C7388(void* self, void* infop)
{
    int* info = (int*)infop;
    switch (info[0]) {
    case 0:
        *(int*)(*(char**)((char*)self + 0x6C) + 0x90) |= 8;
        break;
    case 1:
        *(int*)(*(char**)((char*)self + 0x6C) + 0x90) |= 8;
        break;
    default:
        *(int*)(*(char**)((char*)self + 0x6C) + 0x90) &= ~8;
        break;
    }
    *(int*)((char*)self + 0x290) = 0;
    *(int*)((char*)self + 0x29C) = 0;
    int r = func_001C6D30(self, info);
    if (info[0] == 0)
        (*(cUIObj_7388**)((char*)self + 0x70))->setVisible(0);
    else
        (*(cUIObj_7388**)((char*)self + 0x70))->setVisible(1);
    for (int i = info[0]; i < 5; i++) {
        if (((sPopup_7388*)self)->items[i] != 0) {
            ((sPopup_7388*)self)->items[i]->setEnabled(1);
            ((sPopup_7388*)self)->items[i]->setVisible(0);
        }
    }
    for (int j = 0; j < info[0]; j++) {
        cUIObj_7388* t = ((sPopup_7388*)self)->items[j];
        if (t != 0) {
            float size[4];
            float item[4];
            int* it = func_001C5800(info, j);
            func_001C8050(self, (cUIText*)t, it);
            func_001C8628(self, t, size);
            func_001C8320(self, (cUIText*)t, it, item);
            if (*(float*)((char*)self + 0x29C) < item[2])
                *(float*)((char*)self + 0x29C) = item[2];
            func_001C9B68(self, (float*)((char*)self + 0x260), size);
            t->setEnabled(0);
            t->setVisible(1);
        }
    }
    *(float*)((char*)self + 0x264) += 10.0f;
    if (r != 0)
        info[0] = -1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C75C8);
#ifdef SKIP_ASM
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);

extern "C" void func_001C75C8(void* self, void* menu, int idx, int max)
{
    int lo;
    idx = idx + 1;
    if (max == -1) {
        lo = 0;
        max = 1;
    } else {
        lo = 1;
    }
    if (idx < lo) {
        idx = lo;
    } else if (idx > max) {
        idx = max;
    }
    cUIMenu_setSelectedByIndex(menu, idx);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C7620);
#ifdef SKIP_ASM
struct sVec3_7620 { float x, y, z; };
// PORT: SN soft-float helpers called by name (fptodp / dpmul / dptofp); on PC: (float)((double)(...) * 1.05)
extern "C" double func_00413AF8(float f);
extern "C" double func_00411FD8(double a, double b);
extern "C" float func_004127A8(double d);

// Converts a screen position into the popup's normalised scroll position for the current layout.
extern "C" void func_001C7620(void* self, sVec3_7620 pos)
{
    char* s = (char*)self;
    switch (*(int*)(s + 0x31C)) {
    case 0:
        *(float*)(s + 0x278) = (pos.x + 15.0f) / *(float*)(s + 0x1F4);
        *(float*)(s + 0x27C) = (pos.y + 10.0f) / *(float*)(s + 0x1F8);
        break;
    case 1:
        *(float*)(s + 0x278) = func_004127A8(func_00411FD8(func_00413AF8((pos.x + 20.0f) / *(float*)(s + 0x218)), 1.05));
        *(float*)(s + 0x27C) = (pos.y + 15.0f) / *(float*)(s + 0x21C);
        break;
    case 2:
        *(float*)(s + 0x278) = 1.0f;
        *(float*)(s + 0x27C) = 1.0f;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C7738);
#ifdef SKIP_ASM
struct sColor_7738 { int r, g, b; };

extern "C" void func_001C7738(void* self, sColor_7738* color)
{
    sColor_7738 c = *color;
    switch (*(int*)((char*)self + 0x31C)) {
    case 0:
        {
            void* p = *(void**)((char*)self + 0x48);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        {
            void* p = *(void**)((char*)self + 0x4C);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        break;
    case 1:
        {
            void* p = *(void**)((char*)self + 0x58);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        {
            void* p = *(void**)((char*)self + 0x5C);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        {
            void* p = *(void**)((char*)self + 0x50);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        {
            void* p = *(void**)((char*)self + 0x54);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        {
            void* p = *(void**)((char*)self + 0x60);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        break;
    case 2:
        {
            void* p = *(void**)((char*)self + 0x68);
            if (p != 0) {
                *(sColor_7738*)((char*)p + 0x50) = c;
            }
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C78C0);
#ifdef SKIP_ASM
struct sVec3_78C0 { float x, y, z; };
// PORT: SN soft-float helpers called by name (fptodp / dpsub / dptofp); on PC: y = (float)((double)(...) - 7.5)
extern "C" double func_00413AF8(float f);
extern "C" double func_00411F70(double a, double b);
extern "C" float func_004127A8(double d);

extern "C" void func_001C78C0(void* self, sVec3_78C0 v, float a, float b)
{
    char* s = (char*)self;
    float y = 0.0f;
    switch (*(int*)(s + 0x31C)) {
    case 0:
        if (*(char**)(s + 0x48) != 0) {
            sVec3_78C0 p = *(sVec3_78C0*)(s + 0x188);
            y = *(float*)(s + 0x1BC) + b + v.y * 0.5f - 5.0f;
            p.x += a;
            p.y = y;
            *(sVec3_78C0*)(*(char**)(s + 0x48) + 0x44) = p;
        }
        if (*(char**)(s + 0x4C) != 0) {
            sVec3_78C0 p = *(sVec3_78C0*)(s + 0x194);
            p.y = y;
            p.x += a;
            *(sVec3_78C0*)(*(char**)(s + 0x4C) + 0x44) = p;
        }
        break;
    case 1:
        if (*(char**)(s + 0x58) != 0) {
            sVec3_78C0 p = *(sVec3_78C0*)(s + 0x23C);
            y = func_004127A8(func_00411F70(func_00413AF8(*(float*)(s + 0x1BC) + b + v.y * 0.5f), 7.5));
            p.x += a;
            p.y = y;
            *(sVec3_78C0*)(*(char**)(s + 0x58) + 0x44) = p;
        }
        if (*(char**)(s + 0x5C) != 0) {
            sVec3_78C0 p = *(sVec3_78C0*)(s + 0x248);
            p.y = y;
            p.x += a;
            *(sVec3_78C0*)(*(char**)(s + 0x5C) + 0x44) = p;
        }
        if (*(char**)(s + 0x50) != 0) {
            sVec3_78C0 p = *(sVec3_78C0*)(s + 0x224);
            p.y = y;
            p.x += a;
            *(sVec3_78C0*)(*(char**)(s + 0x50) + 0x44) = p;
        }
        if (*(char**)(s + 0x54) != 0) {
            sVec3_78C0 p = *(sVec3_78C0*)(s + 0x230);
            p.y = y;
            p.x += a;
            *(sVec3_78C0*)(*(char**)(s + 0x54) + 0x44) = p;
        }
        if (*(char**)(s + 0x60) != 0) {
            sVec3_78C0 p = *(sVec3_78C0*)(s + 0x254);
            p.y = y;
            p.x += a;
            *(sVec3_78C0*)(*(char**)(s + 0x60) + 0x44) = p;
        }
        break;
    case 2:
        *(float*)(s + 0x27C) = *(float*)(s + 0x278) = 1.0f;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C7BE0);
#ifdef SKIP_ASM
extern "C" float func_001C7BE0(void* self)
{
    if (*(int*)((char*)self + 0x2CC) != 0) {
        return 0.0f;
    }
    return (640.0f - *(float*)((char*)self + 0x260)) * 0.5f - *(float*)((char*)self + 0x1B8);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001C7C20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sVec3_7C20 { float x, y, z; };
extern "C" float func_001C7BE0(void* self);
void func_001C7620_7C20(void* self, sVec3_7C20 v) __asm__("func_001C7620");
void func_001C78C0_7C20(void* self, sVec3_7C20 v, float a, float b) __asm__("func_001C78C0");

extern "C" void func_001C7C20(void* self)
{
    char* s = (char*)self;
    float x = func_001C7BE0(self) + *(float*)(s + 0x26C);
    float y = *(float*)(s + 0x270);
    func_001C7620_7C20(self, *(sVec3_7C20*)(s + 0x260));
    func_001C78C0_7C20(self, *(sVec3_7C20*)(s + 0x260), *(float*)(s + 0x26C), y);
    char* p = *(char**)(s + 0x6C);
    if (p != 0) {
        sVec3_7C20 v = *(sVec3_7C20*)(p + 0x44);
        v.x += *(float*)(s + 0x26C);
        v.y += y;
        *(sVec3_7C20*)(p + 0x44) = v;
    }
    p = *(char**)(s + 0x70);
    if (p != 0) {
        sVec3_7C20 v = *(sVec3_7C20*)(p + 0x44);
        v.x += *(float*)(s + 0x26C);
        v.y += y;
        *(sVec3_7C20*)(p + 0x44) = v;
    }
    if (*(char**)(s + 0x74) != 0) {
        sVec3_7C20 v = *(sVec3_7C20*)(*(char**)(s + 0x74) + 0x44);
        if (*(int*)(s + 0x2CC) != 0) {
            v.x = x + 320.0f;
        } else {
            v.x += x;
        }
        v.y += y;
        *(sVec3_7C20*)(*(char**)(s + 0x74) + 0x44) = v;
    }
    if (*(char**)(s + 0x7C) != 0) {
        sVec3_7C20 v = *(sVec3_7C20*)(*(char**)(s + 0x7C) + 0x44);
        if (*(int*)(s + 0x2CC) != 0) {
            v.x = x + 320.0f;
        } else {
            v.x += x;
        }
        v.y += y;
        *(sVec3_7C20*)(*(char**)(s + 0x7C) + 0x44) = v;
    }
    if (*(char**)(s + 0x78) != 0) {
        sVec3_7C20 v = *(sVec3_7C20*)(*(char**)(s + 0x78) + 0x44);
        if (*(int*)(s + 0x2CC) != 0) {
            v.x = x + 320.0f;
        } else {
            v.x += x;
        }
        v.y += y;
        *(sVec3_7C20*)(*(char**)(s + 0x78) + 0x44) = v;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C7EB0);
#ifdef SKIP_ASM
struct sVec3_7EB0 { float x, y, z; };
struct sVec2_7EB0 { float x, y; };
struct sVE_7EB0 {
    short delta;
    short index;
    void (*fn)(void*, sVec2_7EB0*);
};

extern "C" void func_001C7EB0(void* self)
{
    char* o80 = *(char**)((char*)self + 0x80);
    sVec3_7EB0 a = *(sVec3_7EB0*)(o80 + 0x44);
    sVec3_7EB0 c;
    sVec3_7EB0 b = *(sVec3_7EB0*)(*(char**)((char*)self + 0x6C) + 0x44);
    c = *(sVec3_7EB0*)(*(char**)((char*)self + 0x84) + 0x44);
    sVec2_7EB0 size;
    {
        sVE_7EB0* vt = *(sVE_7EB0**)(o80 + 8);
        vt[20].fn(o80 + vt[20].delta, &size);
    }
    size.x = *(float*)((char*)self + 0x260) - (a.x - c.x) - 10.0f;
    {
        char* o = *(char**)((char*)self + 0x80);
        sVE_7EB0* vt = *(sVE_7EB0**)(o + 8);
        vt[21].fn(o + vt[21].delta, &size);
    }
    sVec3_7EB0 scale;
    scale.x = (size.x + 6.0f) / *(float*)((char*)self + 0x20C);
    scale.y = 1.0f;
    scale.z = 1.0f;
    char* p = *(char**)((char*)self + 0x8C);
    if (p != 0) {
        sVec3_7EB0 d = a;
        d.y = d.y + *(float*)((char*)self + 0x210) * 0.5f + b.y - 3.0f;
        d.x = d.x + (size.x + 6.0f) * 0.5f;
        *(sVec3_7EB0*)(p + 0x44) = d;
        *(sVec3_7EB0*)(*(char**)((char*)self + 0x8C) + 0x50) = scale;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C8050);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void func_003A0E90(cUIText* text, void* p);
extern char D_004A1408[];

extern "C" void func_001C8050(void* self, cUIText* text, int* info)
{
    switch (info[0]) {
    case 1:
        func_003A0E90(text, (void*)info[1]);
        break;
    case 2:
        cUIText_setAsciiString(text, (const char*)info[1]);
        break;
    case 3:
        cUIText_setUnicodeStringByID(text, info[1]);
        break;
    case 0:
        cUIText_setAsciiString(text, D_004A1408);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C80E8);
#ifdef SKIP_ASM
extern "C" int USTR_length(unsigned short* s);
extern "C" char* func_002C2580(char* dst, unsigned short* src);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
void cMemMan_free(void* ptr);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern char D_00466098[];
extern char D_004660A8[];
extern char D_004A1408[];

struct sVEntry_80E8 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern "C" void func_001C80E8(void* self, void* dst, int* info)
{
    switch (info[0]) {
    case 1: {
        unsigned short* u = (unsigned short*)info[1];
        char* buf = (char*)operator_new_tag(USTR_length(u) + 1, D_00466098, 0x100, 0);
        func_002C2580(buf, (unsigned short*)info[1]);
        cBXString_cBXString4(dst, buf);
        if (buf != 0) {
            cMemMan_free(buf);
        }
        break;
    }
    case 2:
        cBXString_cBXString4(dst, (const char*)info[1]);
        break;
    case 3: {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry_80E8* vt = *(sVEntry_80E8**)(o + 4);
        unsigned short* str = vt[4].fn(o + vt[4].delta, info[1]);
        if (str) {
            char* buf = (char*)operator_new_tag(USTR_length(str) + 1, D_00466098, 0x100, 0);
            func_002C2580(buf, str);
            cBXString_cBXString4(dst, buf);
            if (buf != 0) {
                cMemMan_free(buf);
            }
        } else {
            char tmp[0x40];
            sprintf(tmp, D_004660A8, info[1]);
            cBXString_cBXString4(dst, tmp);
        }
        break;
    }
    case 0:
        cBXString_cBXString4(dst, D_004A1408);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cScreenPopup_setTextString);
#ifdef SKIP_ASM
struct cUIText;
extern "C" char* func_003A0C00(cUIText* text);
extern "C" unsigned short* func_003A0C28(cUIText* text);
extern "C" int USTR_length(unsigned short* s);
extern "C" char* func_002C2580(char* dst, unsigned short* src);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
void cMemMan_free(void* ptr);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_004660B8[];
extern char D_004A1408[];

extern "C" void cScreenPopup_setTextString(void* self, void* dst, cUIText* text)
{
    char* s = func_003A0C00(text);
    if (s != 0) {
        cBXString_cBXString4(dst, s);
        return;
    }
    unsigned short* u = func_003A0C28(text);
    if (u != 0) {
        char* buf = (char*)operator_new_tag(USTR_length(u) + 1, D_004660B8, 0x100, 0);
        func_002C2580(buf, u);
        cBXString_cBXString4(dst, buf);
        if (buf != 0) {
            cMemMan_free(buf);
        }
    } else {
        cBXString_cBXString4(dst, D_004A1408);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C8320);
#ifdef SKIP_ASM
struct cUIText;
struct sVec3_8320 { float x, y, z; };
extern "C" void* func_003A04F0(void* self);
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);
extern "C" float func_003921F0(void* self, const char* str, void* out, int n, float sx, float sy);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern char D_004660A8[];

struct sVEntry_8320 {
    short delta;
    short index;
    char* (*fn)(void*, int);
};

extern "C" void func_001C8320(void* self, cUIText* text, int* info, float* out)
{
    sVec3_8320 v = *(sVec3_8320*)((char*)text + 0x50);
    char* g = (char*)func_003A04F0(text);
    float sx = *(float*)(g + 0x30) * v.x;
    float sy = *(float*)(g + 0x34) * v.y;
    *(float*)(g + 0x38) = sx;
    *(float*)(g + 0x3C) = sy;
    char* f;
    switch (info[0]) {
    case 1:
        f = (char*)func_003A04F0(text);
        func_003921F0(f, (const char*)info[1], out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
        break;
    case 2:
        f = (char*)func_003A04F0(text);
        func_00391FB0(f, (const char*)info[1], out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
        break;
    case 3: {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry_8320* vt = *(sVEntry_8320**)(o + 4);
        char* str = vt[4].fn(o + vt[4].delta, info[1]);
        if (str) {
            f = (char*)func_003A04F0(text);
            func_003921F0(f, str, out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
        } else {
            char buf[0x40];
            sprintf(buf, D_004660A8, info[1]);
            f = (char*)func_003A04F0(text);
            func_00391FB0(f, buf, out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
        }
        break;
    }
    case 0:
        out[2] = 0.0f;
        out[3] = 0.0f;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C84A8);
#ifdef SKIP_ASM
struct sVec3_84A8 { float x, y, z; };
extern "C" void* func_003A04F0(void* self);
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);

extern "C" void func_001C84A8(void* self, void* text, const char* str, void* out)
{
    sVec3_84A8 v = *(sVec3_84A8*)((char*)text + 0x50);
    char* f = (char*)func_003A04F0(text);
    float sx = *(float*)(f + 0x30) * v.x;
    float sy = *(float*)(f + 0x34) * v.y;
    *(float*)(f + 0x38) = sx;
    *(float*)(f + 0x3C) = sy;
    f = (char*)func_003A04F0(text);
    func_00391FB0(f, str, out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
    f = (char*)func_003A04F0(text);
    *(float*)((char*)out + 0xC) = v.y * ((float)*(int*)(f + 0x14) * *(float*)(f + 0x34));
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C8568);
#ifdef SKIP_ASM
struct sVec3_8568 { float x, y, z; };
extern "C" void* func_003A04F0(void* self);
extern "C" float func_003921F0(void* self, const char* str, void* out, int n, float sx, float sy);

extern "C" void func_001C8568(void* self, void* text, const char* str, void* out)
{
    sVec3_8568 v = *(sVec3_8568*)((char*)text + 0x50);
    char* f = (char*)func_003A04F0(text);
    float sx = *(float*)(f + 0x30) * v.x;
    float sy = *(float*)(f + 0x34) * v.y;
    *(float*)(f + 0x38) = sx;
    *(float*)(f + 0x3C) = sy;
    f = (char*)func_003A04F0(text);
    func_003921F0(f, str, out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
    f = (char*)func_003A04F0(text);
    *(float*)((char*)out + 0xC) = v.y * ((float)*(int*)(f + 0x14) * *(float*)(f + 0x34));
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C8628);
#ifdef SKIP_ASM
struct sVec2_8628 { float x, y; };

struct sVEntry001C8628 {
    short delta;
    short index;
    void (*fn)(void*, sVec2_8628*);
};

extern "C" void func_001C8628(void* self, void* obj, void* out)
{
    sVec2_8628 v;
    sVEntry001C8628* vt = *(sVEntry001C8628**)((char*)obj + 8);
    vt[20].fn((char*)obj + vt[20].delta, &v);
    *(float*)((char*)out + 0x8) = v.x;
    *(float*)((char*)out + 0xC) = v.y;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C8678);
#ifdef SKIP_ASM
struct cUIText;
struct sVE8678 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
extern "C" void func_001C8050(void* self, cUIText* text, int* info);
extern "C" void func_001C8320(void* self, cUIText* text, int* info, float* out);
extern "C" void func_001C9B68(void* self, float* size, float* item);
extern "C" void func_001C8930(void* self, void* obj, unsigned char state, float t);

extern "C" void func_001C8678(void* self, void* a1)
{
    cUIText* text = *(cUIText**)((char*)self + 0x7C);
    if (text != 0) {
        int* info = (int*)((char*)a1 + 0xC);
        if (*(int*)((char*)a1 + 0xC) != 0) {
            float item[4];
            func_001C8050(self, text, info);
            {
                char* o = *(char**)((char*)self + 0x7C);
                sVE8678* vt = *(sVE8678**)(o + 8);
                vt[9].fn(o + vt[9].delta, 1);
            }
            func_001C8320(self, *(cUIText**)((char*)self + 0x7C), info, item);
            func_001C9B68(self, (float*)((char*)self + 0x260), item);
            *(float*)((char*)self + 0x264) += 5.0f;
            if (*(int*)((char*)self + 0x2CC) != 0) {
                func_001C8930(self, *(void**)((char*)self + 0x7C), 0x11, 0.0f);
            }
        } else {
            sVE8678* vt = *(sVE8678**)((char*)text + 8);
            vt[9].fn((char*)text + vt[9].delta, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C8758);
#ifdef SKIP_ASM
struct sVec3_8758 { float x, y, z; };
extern "C" void func_001C8930(void* self, void* obj, unsigned char state, float t);

extern "C" void func_001C8758(void* self)
{
    char* p = *(char**)((char*)self + 0x6C);
    if (p != 0) {
        sVec3_8758 a = *(sVec3_8758*)(*(char**)((char*)self + 0x90) + 0x44);
        float x = (640.0f - *(float*)((char*)self + 0x29C)) * 0.5f - a.x;
        sVec3_8758 b = *(sVec3_8758*)((char*)self + 0x1A0);
        b.y += *(float*)((char*)self + 0x288);
        b.x += x;
        *(sVec3_8758*)(p + 0x44) = b;
        char* q = *(char**)((char*)self + 0x88);
        sVec3_8758 c = *(sVec3_8758*)(q + 0x44);
        c.x = c.x - x + 5.0f;
        *(sVec3_8758*)(q + 0x44) = c;
        if (*(int*)((char*)self + 0x2C8) != 0) {
            int i;
            for (i = 0; i < 5; i++) {
                void* o = *(void**)((char*)self + 0x90 + i * 4);
                if (o != 0)
                    func_001C8930(self, o, 0x12, *(float*)((char*)self + 0x29C) * 0.5f);
            }
        }
        *(float*)((char*)self + 0x290) = x;
        *(float*)((char*)self + 0x294) = *(float*)((char*)self + 0x288);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C88C8);
#ifdef SKIP_ASM
struct sVec3_88C8 { float x, y, z; };

extern "C" void func_001C88C8(void* self)
{
    void* p = *(void**)((char*)self + 0x70);
    if (p != 0) {
        sVec3_88C8 v = *(sVec3_88C8*)((char*)self + 0x1AC);
        v.y += *(float*)((char*)self + 0x294);
        v.x += *(float*)((char*)self + 0x290);
        *(sVec3_88C8*)((char*)p + 0x44) = v;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C8930);
#ifdef SKIP_ASM
struct sObjBitsK8930 {
    unsigned lo : 13;
    unsigned state : 6;
    unsigned hi : 13;
};
struct sVec2K8930 { float x, y; };
struct sVec3K8930 { float x, y, z; };

struct sVEntryK8930 {
    short delta;
    short index;
    void (*fn)(void*, sVec2K8930*);
};

extern "C" void func_001C8930(void* self, void* obj, unsigned char state, float t)
{
    sObjBitsK8930* b = (sObjBitsK8930*)((char*)obj + 0x14);
    if (b->state == state)
        return;
    sVec2K8930 size;
    sVEntryK8930* vt = *(sVEntryK8930**)((char*)obj + 8);
    vt[20].fn((char*)obj + vt[20].delta, &size);
    sVec3K8930 pos = *(sVec3K8930*)((char*)obj + 0x44);
    b->state = state;
    if (t == 0.0f)
        t = size.x * 0.5f;
    switch (state) {
    case 17:
    case 18:
        pos.x += t;
        break;
    case 9:
    case 10:
        pos.x -= t;
        break;
    }
    *(sVec3K8930*)((char*)obj + 0x44) = pos;
}
#endif

INCLUDE_ASM("fe/fepopup", func_001C8A38);

//100%
INCLUDE_ASM("fe/fepopup", func_001C8EF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_001C9038(void* self, void* text, unsigned short* str, float* size);
extern "C" void func_001C9210_s(void* self, void* text, const char* str, float* size) __asm__("func_001C9210");
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern char D_004660A8[];

struct sVEntry_8EF0 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern "C" void func_001C8EF0(void* vself, int* item, float* size, int flag, float extra)
{
    char* self = (char*)vself;
    void* text;
    if (flag != 0)
        text = *(void**)(self + 0x74);
    else
        text = *(void**)(self + 0x78);
    if (text == 0)
        return;
    switch (item[0]) {
    case 0:
        break;
    case 2:
        func_001C9210_s(self, text, (const char*)item[1], size);
        goto add;
    case 1:
        func_001C9038(self, text, (unsigned short*)item[1], size);
        goto add;
    case 3: {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry_8EF0* vt = *(sVEntry_8EF0**)(o + 4);
        unsigned short* str = vt[4].fn(o + vt[4].delta, item[1]);
        if (str) {
            func_001C9038(self, text, str, size);
            goto add;
        } else {
            char buf[0x40];
            sprintf(buf, D_004660A8, item[1]);
            func_001C9210_s(self, text, buf, size);
        }
        break;
    }
    default:
    add:
        size[1] += extra;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C9038);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int USTR_length(unsigned short* s);
void cMemMan_free(void* ptr);
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_001C8568(void* self, void* text, const char* str, void* out);
extern "C" void func_001C9B68(void* self, float* size, float* item);
extern char D_004660D8[];
extern char D_004A1C38;

extern "C" void func_001C9038(void* self, void* text, unsigned short* str, float* size)
{
    int j = 0;
    int i = 0;
    float item[4];
    unsigned short* buf = new (D_004660D8, 0x100, 0) unsigned short[USTR_length(str) + 1];
    buf[0] = 0;
    int n = USTR_length(str);
    while (i < n) {
        unsigned short c = str[i];
        unsigned short next = str[i + 1];
        if (c == D_004A1C38 && next == D_004A1C38) {
            buf[j] = 0;
            func_001C8568(self, text, (const char*)buf, item);
            i += 2;
            j = 0;
            func_001C9B68(self, size, item);
            size[1] += 3.0f;
        } else if (c == '\r') {
            buf[j] = 0;
            func_001C8568(self, text, (const char*)buf, item);
            i += 1;
            j = 0;
            func_001C9B68(self, size, item);
            size[1] += 3.0f;
        } else {
            buf[j] = c;
            i++;
            j++;
        }
    }
    if (j != 0) {
        buf[j] = 0;
        func_001C8568(self, text, (const char*)buf, item);
        func_001C9B68(self, size, item);
        size[1] += 3.0f;
    }
    if (buf != 0)
        cMemMan_free(buf);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C9210);
#ifdef SKIP_ASM
struct cUIText;
extern "C" int strlen(const char* s);
void cMemMan_free(void* ptr);
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_001C84A8(void* self, void* text, const char* str, void* out);
extern "C" void func_001C9B68(void* self, float* size, float* item);
extern char D_004660D8[];

// PORT: a3 is the float* size out pointer (the unit declares it int)
extern "C" void func_001C9210(void* self, cUIText* text, const char* str, int a3)
{
    float* size = (float*)a3;
    int j = 0;
    int i = 0;
    float item[4];
    char* buf = new (D_004660D8, 0x100, 0) char[strlen(str) + 1];
    buf[0] = 0;
    int n = strlen(str);
    while (i < n) {
        char c = str[i];
        char next = str[i + 1];
        if (c == '\\' && next == '\\') {
            buf[j] = 0;
            func_001C84A8(self, text, buf, item);
            i += 2;
            func_001C9B68(self, size, item);
            j = 0;
            size[1] += 3.0f;
        } else if (c == '\r') {
            buf[j] = 0;
            func_001C84A8(self, text, buf, item);
            i += 1;
            func_001C9B68(self, size, item);
            j = 0;
            size[1] += 3.0f;
        } else {
            buf[j] = c;
            i++;
            j++;
        }
    }
    if (j != 0) {
        buf[j] = 0;
        func_001C84A8(self, text, buf, item);
        func_001C9B68(self, size, item);
    }
    if (buf != 0)
        cMemMan_free(buf);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C93B0);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void cScreenPopup_getMessageLineWrapSize(void* self, void* text, const char* str, void* out);
extern "C" void func_001C94B0(void* self, void* text, void* str, void* out);
extern void* D_004A28A8;
extern char D_004660A8[];

struct sVEntryK93B0 {
    short delta;
    short index;
    void* (*fn)(void*, int);
};

extern "C" void func_001C93B0(void* self, int* msg, void* out)
{
    if (*(void**)((char*)self + 0x74) == 0)
        return;
    switch (msg[0]) {
    case 0:
        break;
    case 2:
        cScreenPopup_getMessageLineWrapSize(self, *(void**)((char*)self + 0x74), (const char*)msg[1], out);
        break;
    case 1:
        func_001C94B0(self, *(void**)((char*)self + 0x74), (void*)msg[1], out);
        break;
    case 3: {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntryK93B0* vt = *(sVEntryK93B0**)(o + 4);
        void* str = vt[4].fn(o + vt[4].delta, msg[1]);
        if (str) {
            func_001C94B0(self, *(void**)((char*)self + 0x74), str, out);
        } else {
            char buf[0x40];
            sprintf(buf, D_004660A8, msg[1]);
            cScreenPopup_getMessageLineWrapSize(self, *(void**)((char*)self + 0x74), buf, out);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C94B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sVec3_94B0 { float x, y, z; };
struct sVec2_94B0 { float x, y; };
struct sVEntry_94B0 {
    short delta;
    short index;
    void (*fn)(void*, sVec2_94B0*);
};
extern "C" void* func_003A04F0(void* self);
extern "C" float func_00392C60(void* font, int c);
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
void cMemMan_free(void* ptr);
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_004660E8[];
extern char D_004A1C38;

extern "C" void func_001C94B0(void* self, void* text, void* strp, void* outp)
{
    unsigned short* str = (unsigned short*)strp;
    float* out = (float*)outp;
    *(int*)((char*)text + 0x14) |= 0x80;
    void* font = func_003A04F0(text);
    if (font == 0)
        return;
    int i = 0;
    int n = USTR_length(str);
    float w = 0.0f;
    int done = 0;
    unsigned short* buf = new (D_004660E8, 0x100, 0) unsigned short[n + 1];
    USTR_copy(buf, str);
    sVec3_94B0 v;
    sVec2_94B0 size;
    sVEntry_94B0* vt = *(sVEntry_94B0**)((char*)text + 8);
    vt[20].fn((char*)text + vt[20].delta, &size);
    v = *(sVec3_94B0*)((char*)text + 0x50);
    while (i < n) {
        if (buf[i] == D_004A1C38 && buf[i + 1] == D_004A1C38) {
            w = 0.0f;
            i += 2;
        } else {
            float cw = func_00392C60(font, buf[i]) * v.x;
            w += cw;
            if (size.x < w) {
                done = 1;
                *out = w - cw;
                break;
            }
            i += 1;
        }
    }
    if (!done)
        *out = w;
    if (buf != 0)
        cMemMan_free(buf);
}
#endif

INCLUDE_ASM("fe/fepopup", cScreenPopup_getMessageLineWrapSize);

//100%
INCLUDE_ASM("fe/fepopup", func_001C97E0);
#ifdef SKIP_ASM
struct cUIText;
extern "C" void func_001C8050(void* self, cUIText* text, int* info);
extern "C" void func_001C9938(void* self, cUIText* text, void* str, float* out);
// PORT: func_001C9B28's 4th parameter is the out pointer (declared int in the unit)
extern "C" void func_001C9B28(void* self, cUIText* text, const char* str, int a3);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* D_004A28A8;
extern char D_004660A8[];

struct sVEntry_97E0 {
    short delta;
    short index;
    void* (*fn)(void*, int);
};

extern "C" void func_001C97E0(void* self, void* a, void* b, int which, float t)
{
    int* info = (int*)a;
    float* out = (float*)b;
    cUIText* text;
    if (which != 0)
        text = *(cUIText**)((char*)self + 0x74);
    else
        text = *(cUIText**)((char*)self + 0x78);
    if (text == 0)
        return;
    switch (info[0]) {
    case 2:
        func_001C9B28(self, text, (const char*)info[1], (int)out);
        break;
    case 1:
        func_001C9938(self, text, (void*)info[1], out);
        break;
    case 3: {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry_97E0* vt = *(sVEntry_97E0**)(o + 4);
        void* str = vt[4].fn(o + vt[4].delta, info[1]);
        if (str) {
            func_001C9938(self, text, str, out);
        } else {
            char buf[0x40];
            sprintf(buf, D_004660A8, info[1]);
            func_001C9B28(self, text, buf, (int)out);
            return;
        }
        break;
    }
    case 0:
        func_001C8050(self, text, info);
        return;
    }
    out[1] += t;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C9938);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cUIText;
struct sVec3_9938 { float x, y, z; };
struct sVec2_9938 { float x, y; };
struct sVEntry_9938 {
    short delta;
    short index;
    void (*fn)(void*, sVec2_9938*);
};
extern "C" void* func_003A04F0(void* self);
extern "C" float func_00392C60(void* font, int c);
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
extern "C" void func_003A0E90(cUIText* text, void* p);
extern "C" void func_001C9038(void* self, void* text, unsigned short* str, float* size);
void cMemMan_free(void* ptr);
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_004660E8[];
extern char D_004A1C38;

extern "C" void func_001C9938(void* self, cUIText* text, void* strp, float* out)
{
    unsigned short* str = (unsigned short*)strp;
    *(int*)((char*)text + 0x14) |= 0x80;
    void* font = func_003A04F0(text);
    if (font == 0)
        return;
    int last = -1;
    int n = USTR_length(str);
    float w = 0.0f;
    int i = 0;
    unsigned short* buf = new (D_004660E8, 0x100, 0) unsigned short[n + 1];
    USTR_copy(buf, str);
    sVec3_9938 v;
    sVec2_9938 size;
    sVEntry_9938* vt = *(sVEntry_9938**)((char*)text + 8);
    vt[20].fn((char*)text + vt[20].delta, &size);
    v = *(sVec3_9938*)((char*)text + 0x50);
    while (i < n) {
        if (buf[i] == D_004A1C38 && buf[i + 1] == D_004A1C38) {
            last = -1;
            w = 0.0f;
            i += 2;
        } else {
            if (buf[i] == '\r') {
                w = 0.0f;
                last = -1;
            } else {
                float cw = func_00392C60(font, buf[i]) * v.x;
                if (buf[i] == ' ')
                    last = i;
                w += cw;
                if (size.x < w && last >= 0) {
                    buf[last] = '\r';
                    i = last;
                    w = 0.0f;
                    last = -1;
                }
            }
            i++;
        }
    }
    func_001C9038(self, text, buf, out);
    func_003A0E90(text, buf);
    if (buf != 0)
        cMemMan_free(buf);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001C9B28);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void func_001C9210(void* self, cUIText* text, const char* str, int a3);

extern "C" void func_001C9B28(void* self, cUIText* text, const char* str, int a3)
{
    func_001C9210(self, text, str, a3);
    cUIText_setAsciiString(text, str);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001C9B68);
#ifdef SKIP_ASM
extern "C" void func_001C9B68(void* self, float* size, float* item)
{
    float w = item[2];
    if (size[0] < w) {
        size[0] = w;
    }
    size[1] += item[3];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", cScreenPopup_createConfirmationPopup);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cScreenPopup_cScreenPopup(void* mem, void* engine, void* owner);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00466110[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

struct sVec3K1C9B98 {
    float x, y, z;
    sVec3K1C9B98(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct sPairK1C9B98 { int a, b; };
struct sEntryK1C9B98 { sPairK1C9B98 p; int c; };
struct sSelfK1C9B98 { char pad[0x2D0]; sEntryK1C9B98 entries[4]; };

extern "C" void cScreenPopup_createConfirmationPopup(void* self, int idx)
{
    char* popup = (char*)cScreenPopup_cScreenPopup(cMemMan_alloc(0x360, D_00466110, 0x100, 0), *(void**)((char*)self + 0x10), self);
    *(void**)((char*)self + 0x2AC) = popup;
    char* slots = popup + 0xBC;
    *(int*)(popup + 0xBC) = 2;
    func_001C57C0(slots, 0, GetHashValue32(D_0045DCC8));
    func_001C57C0(slots, 1, GetHashValue32(D_0045FCD8));
    sVec3K1C9B98 v(30.0f, 40.0f, 0.0f);
    *(sVec3K1C9B98*)(popup + 0x158) = v;
    *(int*)(popup + 0x14C) = *(int*)((char*)self + 0x314) + 3;
    *(int*)(popup + 0x168) = ((sSelfK1C9B98*)self)->entries[idx].c;
    *(sPairK1C9B98*)(popup + 0xC0) = ((sSelfK1C9B98*)self)->entries[idx].p;
    *(int*)((char*)self + 0x324) = idx;
    func_0039F290((char*)*(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18,
                  *(void**)((char*)self + 0x2AC));
}
#endif

INCLUDE_ASM("fe/fepopup", func_001C9CD0);

//100%
INCLUDE_ASM("fe/fepopup", func_001CA0F0);
#ifdef SKIP_ASM
struct sVEntry_A0F0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001CA0F0(void* self, int idx, int a)
{
    char* o = *(char**)((char*)self + (idx << 2) + 0x90);
    if (o != 0) {
        sVEntry_A0F0* vt = *(sVEntry_A0F0**)(o + 8);
        vt[8].fn(o + vt[8].delta, a);
        sVEntry_A0F0* vt2 = *(sVEntry_A0F0**)(o + 8);
        vt2[25].fn(o + vt2[25].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA150);
#ifdef SKIP_ASM
extern "C" int func_001CA150(void* self)
{
    void* p = *(void**)((char*)self + 0x6C);
    if (p == 0) {
        return *(int*)((char*)self + 0x168);
    }
    int n = *(unsigned char*)((char*)p + 0x95);
    if (*(int*)((char*)self + 0x30C) == -1) {
        return n;
    }
    return n - 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA180);
#ifdef SKIP_ASM
extern "C" char* func_00397870(void* list, int idx);

struct sVE1CA180 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

static inline void SetColour1CA180(char* obj, void* colour)
{
    sVE1CA180* vt = *(sVE1CA180**)(obj + 8);
    vt[11].fn(obj + vt[11].delta, colour);
}

// Popup menu event handler: on draw (5) colours the selected entry; 0x101 = not handled.
extern "C" int func_001CA180(char* self, char* menu, int msg)
{
    switch (msg) {
    case 5: {
        int sel = *(unsigned char*)(menu + 0x95);
        for (int i = 0; i < *(unsigned char*)(menu + 0x96); i++) {
            char* obj = func_00397870(menu + 0x74, i);
            if (obj == *(char**)(self + 0x88)) {
                obj = *(char**)(self + 0x84);
            }
            if (i == sel) {
                SetColour1CA180(obj, self + 0x32C);
            } else {
                SetColour1CA180(obj, self + 0x33C);
            }
        }
        break;
    }
    case 8: case 9:
        return 0;
    case 7:
        return *(int*)(self + 0x310) ? 0x101 : 0;
    case 6:
        return *(int*)(self + 0xB8) ? 0 : 0x101;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA298);
#ifdef SKIP_ASM
extern "C" void cScreenPopup_createConfirmationPopup(void* self, int idx);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001CB030(void* self, void* engine, void* owner, int a3, unsigned char a4);
extern "C" void func_001CD088(void* popup, int a1);
extern "C" void func_0039F290(void* stack, void* item);
extern char D_0045D8D8[];

struct sPopupVE_1CA298 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sPopupOwner_1CA298 {
    char pad0[8];
    sPopupVE_1CA298* vt;   // 0x8
};

struct sBtn_1CA298 {
    int confirm;
    int b;
    int c;
};

static inline void Notify_1CA298(sPopupOwner_1CA298* o, int vi, void* self, int v)
{
    o->vt[vi].fn((char*)o + o->vt[vi].delta, self, v);
}

extern "C" void func_001CA298(char* self, int id, int ev)
{
    switch (ev) {
    case 5:
        if (*(int*)(self + 0x30C) != 0) {
            int handled = 0;
            int i;
            *(int*)(self + 0xB8) = 0;
            for (i = 0; i < 5; i++) {
                if (id == ((int*)(self + 0x90))[i]) {
                    if (((sBtn_1CA298*)(self + 0x2D0))[i].confirm != 0) {
                        cScreenPopup_createConfirmationPopup(self, i);
                    } else {
                        Notify_1CA298(*(sPopupOwner_1CA298**)(self + 0x20), 17, self, i + 15);
                    }
                    handled = 1;
                    break;
                }
            }
            if (handled) {
                break;
            }
            if (id != *(int*)(self + 0x88)) {
                break;
            }
            void* p = cMemMan_alloc(0x444, D_0045D8D8, 0x100, 0);
            *(void**)(self + 0x2A8) = func_001CB030(p, *(void**)(self + 0x10), self, 0, 0xF);
            func_001CD088(*(void**)(self + 0x2A8), *(int*)(self + 0x328));
            func_0039F290(*(char**)(*(char**)(*(char**)(self + 0x40) + 0xD0) + 0x10) + 0x18, *(void**)(self + 0x2A8));
            if (*(cUIText**)(self + 0x84) != 0) {
                cScreenPopup_setTextString(self, self + 0x2B4, *(cUIText**)(self + 0x84));
            }
        } else {
            *(int*)(self + 0xB8) = 1;
        }
        break;
    case 6:
        if (*(int*)(self + 0x310) != 0) {
            Notify_1CA298(*(sPopupOwner_1CA298**)(self + 0x20), 17, self, 0x14);
        }
        break;
    case 7:
    case 8:
        break;
    case 13:
        cBXString_cBXString4(self + 0x2B0, *(char**)(self + 0x2A8) + 0x74);
        if (*(cUIText**)(self + 0x80) != 0 && *(int*)(*(char**)(self + 0x2B0) - 8) != 0) {
            cScreenPopup_checkAndFixTextEntry(self, *(cUIText**)(self + 0x80), *(const char**)(self + 0x2B0));
        }
        break;
    default:
        {
            sPopupOwner_1CA298* o = *(sPopupOwner_1CA298**)(self + 0x20);
            ((void (*)(void*, int, int))o->vt[19].fn)((char*)o + o->vt[19].delta, id, ev);
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA488);
#ifdef SKIP_ASM
struct sVEntry_func_001CA488 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001CA488(void* self, void* obj)
{
    if (obj != 0) {
        sVEntry_func_001CA488* vt = *(sVEntry_func_001CA488**)((char*)obj + 0x8);
        vt[9].fn((char*)obj + vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA4C0);
#ifdef SKIP_ASM
struct sVEntry_func_001CA4C0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001CA4C0(void* self, void* obj)
{
    if (obj != 0) {
        sVEntry_func_001CA4C0* vt = *(sVEntry_func_001CA4C0**)((char*)obj + 0x8);
        vt[9].fn((char*)obj + vt[9].delta, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA4F8);
#ifdef SKIP_ASM
class func_001CA4F8_cObj {
public:
    char pad[0x8];
    virtual int v01(int, int);
    virtual int v02(int, int);
    virtual int v03(int, int);
    virtual int v04(int, int);
    virtual int v05(int, int);
    virtual int v06(int, int);
    virtual int v07(int, int);
    virtual int v08(int, int);
    virtual int v09(int, int);
    virtual int v10(int, int);
    virtual int v11(int, int);
    virtual int v12(int, int);
    virtual int v13(int, int);
    virtual int v14(int, int);
    virtual int v15(int, int);
    virtual int v16(int, int);
    virtual int v17(int, int);
    virtual int v18(int, int);
    virtual int v19(int, int);
    virtual int v20(int, int);
    virtual int v21(int, int);
    virtual int v22(int, int);
    virtual int v23(int, int);
    virtual int v24(int, int);
};

extern "C" int func_001CA4F8(void* self, int a1, int a2)
{
    return (*(func_001CA4F8_cObj**)((char*)self + 0x20))->v24(a1, a2);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA528);
#ifdef SKIP_ASM
struct sVEntry001CA528 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0039E510(void*);

extern "C" void func_001CA528(void* self)
{
    if (*(int*)((char*)self + 0x2C0) != 0) {
        void* obj = *(void**)((char*)self + 0x20);
        sVEntry001CA528* vt = *(sVEntry001CA528**)((char*)obj + 8);
        vt[12].fn((char*)obj + vt[12].delta);
    }
    func_0039E510(self);
}
#endif

extern "C" void* func_0039E6B8(void* self);

//100%
INCLUDE_ASM("fe/fepopup", func_001CA578__FPv);
#ifdef SKIP_ASM
void* func_001CA578(void* self)
{
    return func_0039E6B8(self);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA598);
#ifdef SKIP_ASM
extern "C" void func_001CB418(void* popup, const char* a1);
extern "C" void func_001CCF00(void* popup, const char* a1);
// PORT: the unit declares func_0039F190 as void; it returns a value this caller ignores.
extern "C" int func_0039F190_i(void* self, int a1) __asm__("func_0039F190");

struct sVE1CA598 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// Child-popup message handler: forwards results, plays sounds and closes the popup when done.
extern "C" void func_001CA598(char* self, void* child, int msg)
{
    switch (msg) {
    case 0x15:
        if (child == *(void**)(self + 0x2A8)) {
            func_001CB418(child, *(const char**)(self + 0x2B0));
            func_001CCF00(*(void**)(self + 0x2A8), *(const char**)(self + 0x2B4));
        }
        break;
    case 0xF:
        func_0039F190_i(*(char**)(self + 0x10) + 0x18, 1);
        *(int*)(self + 0x320) = *(int*)(self + 0x324) + 0xF;
        break;
    case 0x10: case 0x14:
        *(int*)(self + 0x320) = -1;
        func_0039F190_i(*(char**)(self + 0x10) + 0x18, 1);
        break;
    case 0x11: case 0x12: case 0x13:
        func_0039F190_i(*(char**)(self + 0x10) + 0x18, 1);
        break;
    case 0x16:
        if (child == *(void**)(self + 0x2A8)) {
            *(void**)(self + 0x2A8) = 0;
        }
        if (child == *(void**)(self + 0x2AC)) {
            *(void**)(self + 0x2AC) = 0;
            if (*(int*)(self + 0x320) != -1) {
                char* obj = *(char**)(self + 0x20);
                sVE1CA598* vt = *(sVE1CA598**)(obj + 8);
                vt[17].fn(obj + vt[17].delta, self, *(int*)(self + 0x320));
            }
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cScreenPopup_checkAndFixTextEntry);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct cUIText;
struct sVec3_A6A0 { float x, y, z; };
struct sVec2_A6A0 { float x, y; };
struct sVEntry_A6A0 {
    short delta;
    short index;
    void (*fn)(void*, sVec2_A6A0*);
};
extern "C" void* func_003A04F0(void* self);
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);
extern "C" char* func_004162D0(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern "C" char* strcpy(char* dst, const char* src);
void cUIText_setAsciiString(cUIText* self, const char* str);
void cMemMan_free(void* ptr);
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_004661A0[];
extern char D_004A1BD0[];

static inline void measure_A6A0(cUIText* text, const char* s, float* out)
{
    char* f = (char*)func_003A04F0(text);
    func_00391FB0(f, s, out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
}

extern "C" void cScreenPopup_checkAndFixTextEntry(void* self, cUIText* text, const char* str)
{
    int fixed = 0;
    sVec3_A6A0 scale = *(sVec3_A6A0*)((char*)text + 0x50);
    sVec2_A6A0 size;
    float ext[4];
    float dots[4];
    sVEntry_A6A0* vt = *(sVEntry_A6A0**)((char*)text + 8);
    vt[20].fn((char*)text + vt[20].delta, &size);
    char* f = (char*)func_003A04F0(text);
    float sx = *(float*)(f + 0x30) * scale.x;
    float sy = *(float*)(f + 0x34) * scale.y;
    *(float*)(f + 0x38) = sx;
    *(float*)(f + 0x3C) = sy;
    char* buf = new (D_004661A0, 0x100, 0) char[*(int*)((char*)self + 0x328) + 4];
    int len = strlen(str) - 1;
    strcpy(buf, str);
    const char* dotstr = D_004A1BD0;
    measure_A6A0(text, dotstr, dots);
    measure_A6A0(text, buf, ext);
    while (size.x - dots[2] - 1.0f < ext[2]) {
        fixed = 1;
        buf[len] = 0;
        len--;
        measure_A6A0(text, buf, ext);
    }
    if (fixed) {
        func_004162D0(buf, dotstr);
        cUIText_setAsciiString(text, buf);
    } else {
        cUIText_setAsciiString(text, str);
    }
    if (buf != 0)
        cMemMan_free(buf);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CA8A0);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);

extern "C" void func_001CA8A0(void* self)
{
    func_003E6448((char*)self + 0x14, 0, 8);
    func_003E6448((char*)self + 0xC, 0, 8);
    func_003E6448((char*)self + 0x1C, 0, 8);
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cBuyPopupInfo_initBuySongByCredit);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004661B8[];
extern char D_004661C8[];

extern "C" void cBuyPopupInfo_initBuySongByCredit(void* self, int song, int credit)
{
    int three = 3;
    int h = GetHashValue32(D_004661B8);
    *(int*)((char*)self + 0x10) = song;
    *(int*)((char*)self + 0x14) = three;
    *(int*)((char*)self + 0xC) = 2;
    *(int*)((char*)self + 0x18) = h;
    h = GetHashValue32(D_004661C8);
    *(int*)((char*)self + 0x8) = credit;
    *(int*)((char*)self + 0x1C) = three;
    *(int*)((char*)self + 0x20) = h;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cBuyPopupInfo_initBuySong);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004661B8[];
extern char D_004661E0[];

extern "C" void cBuyPopupInfo_initBuySong(int* self, int a1, int a2, int a3)
{
    int three = 3;
    int h = GetHashValue32(D_004661B8);
    self[4] = a1;
    self[5] = three;
    self[3] = 2;
    self[6] = h;
    h = GetHashValue32(D_004661E0);
    self[1] = a3;
    self[7] = three;
    self[0] = a2;
    self[2] = -1;
    self[8] = h;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CAA18);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004661F8[];
extern char D_00466210[];
extern char D_00466228[];
extern char D_00466240[];
extern char D_00466258[];
extern char D_00466270[];
extern char D_00466288[];

// Fills in a popup description: title, OK button and the message text for the given kind.
extern "C" void func_001CAA18(int* desc, int kind, int a2, int a3, int a4)
{
    desc[4] = a2;
    desc[3] = 2;
    desc[8] = GetHashValue32(D_004661F8);
    desc[7] = 3;
    desc[2] = -1;
    desc[0] = a3;
    desc[1] = a4;
    switch (kind) {
    case 3:
        desc[6] = GetHashValue32(D_00466210);
        desc[5] = 3;
        break;
    case 4:
        desc[6] = GetHashValue32(D_00466228);
        desc[5] = 3;
        break;
    case 5:
        desc[6] = GetHashValue32(D_00466240);
        desc[5] = 3;
        break;
    case 6:
        desc[6] = GetHashValue32(D_00466258);
        desc[5] = 3;
        break;
    case 7:
        desc[6] = GetHashValue32(D_00466270);
        desc[5] = 3;
        break;
    case 8:
        desc[6] = GetHashValue32(D_00466288);
        desc[5] = 3;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cBuyPopupInfo_initBuyBolt);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004662B8[];
extern char D_004661F8[];

extern "C" void cBuyPopupInfo_initBuyBolt(int* self, int a1, int a2, int a3)
{
    int three = 3;
    int h = GetHashValue32(D_004662B8);
    self[4] = a1;
    self[5] = three;
    self[3] = 2;
    self[6] = h;
    h = GetHashValue32(D_004661F8);
    self[1] = a3;
    self[7] = three;
    self[0] = a2;
    self[2] = -1;
    self[8] = h;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001CABA8);
#ifdef SKIP_ASM
extern "C" void* func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_001CA8A0(void* self);
extern "C" unsigned char func_001A1CD0(void* self, signed char a1);
extern void* D_0046CB08[];

extern "C" void* func_001CABA8(void* self, void* engine, void* owner, signed char idx)
{
    func_0039E318(self, engine, owner);
    *(void***)((char*)self + 0x8) = D_0046CB08;
    func_001CA8A0((char*)self + 0x48);
    *(signed char*)((char*)self + 0x44) = idx;
    *(int*)((char*)self + 0xC) = 7;
    void* p = **(void***)((char*)self + 0x10);
    if (p != 0) {
        *(char*)((char*)self + 0x15) = func_001A1CD0(p, idx);
    }
    func_001CA8A0((char*)self + 0x48);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CAC30);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004662C8[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void func_001CAC30(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004662C8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cUIStateBuyPopup_onWidgetCreate);
#ifdef SKIP_ASM
struct cUIText;
class cUIObj_AC98 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void setEnabled(int v);
    virtual void setVisible(int v);
};
int GetHashValue32(char* str);
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void func_003A0E90(cUIText* text, void* p);
extern "C" char* func_00198AF0(void* p);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004662D8[];
extern char D_004662E8[];
extern char D_004662F8[];
extern char D_004605F0[];
extern char D_00460610[];
extern char D_00466308[];
extern char D_00466318[];
extern char D_00466328[];
extern char D_004A12C0[];

extern "C" void cUIStateBuyPopup_onWidgetCreate(void* self, void* widget)
{
    cUIText* text = (cUIText*)widget;
    int id = *(int*)((char*)widget + 0x38);
    if (id == GetHashValue32(D_004662D8)) {
        int type = *(int*)((char*)self + 0x5C);
        if (type == 2)
            cUIText_setAsciiString(text, *(const char**)((char*)self + 0x60));
        else if (type == 1)
            func_003A0E90(text, *(void**)((char*)self + 0x60));
        else if (type == 3)
            cUIText_setUnicodeStringByID(text, *(int*)((char*)self + 0x60));
    } else if (id == GetHashValue32(D_004662E8)) {
        int type = *(int*)((char*)self + 0x54);
        if (type == 2)
            cUIText_setAsciiString(text, *(const char**)((char*)self + 0x58));
        else if (type == 1)
            func_003A0E90(text, *(void**)((char*)self + 0x58));
        else if (type == 3)
            cUIText_setUnicodeStringByID(text, *(int*)((char*)self + 0x58));
    } else if (id == GetHashValue32(D_004662F8)) {
        int type = *(int*)((char*)self + 0x64);
        if (type == 2)
            cUIText_setAsciiString(text, *(const char**)((char*)self + 0x68));
        else if (type == 1)
            func_003A0E90(text, *(void**)((char*)self + 0x68));
        else if (type == 3)
            cUIText_setUnicodeStringByID(text, *(int*)((char*)self + 0x68));
    } else if (id == GetHashValue32(D_004605F0)) {
        if (*(int*)((char*)self + 0x50) <= 0)
            cUIText_setAsciiString(text, func_00198AF0(*(void**)((char*)self + 0x48)));
    } else if (id == GetHashValue32(D_00460610)) {
        if (*(int*)((char*)self + 0x50) <= 0)
            cUIText_setAsciiString(text, func_00198AF0(*(void**)((char*)self + 0x4C)));
    } else if (id == GetHashValue32(D_00466308)) {
        int n = *(int*)((char*)self + 0x50);
        if (n > 0) {
            char buf[16];
            sprintf(buf, D_004A12C0, n);
            cUIText_setAsciiString(text, buf);
        }
    } else if (id == GetHashValue32(D_00466318)) {
        if (*(int*)((char*)self + 0x50) <= 0)
            ((cUIObj_AC98*)widget)->setVisible(0);
    } else if (id == GetHashValue32(D_00466328)) {
        if (*(int*)((char*)self + 0x50) > 0)
            ((cUIObj_AC98*)widget)->setVisible(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CAED8);
#ifdef SKIP_ASM
// Key filter: keys 7, 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001CAED8(void* self, int a1, unsigned int key)
{
    int r = 0x101;
    if (key < 10) {
        if (key < 7) {
            r = 0x101;
        } else {
            return 0x100;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CAF00);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A14E8[];

extern "C" void func_001CAF00(void* self, void* item, int event)
{
    if (item != 0) {
        if (event == 5) {
            int h = *(int*)((char*)item + 0x38);
            if (h == GetHashValue32(D_004A14E8)) {
                *(int*)((char*)self + 0x6C) = 1;
            } else {
                *(int*)((char*)self + 0x6C) = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cUIStateBuyPopup_initBuyTrick);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00466338[];
extern char D_00466350[];

extern "C" void cUIStateBuyPopup_initBuyTrick(void* self, int trick, int a2, int a3)
{
    int three = 3;
    *(int*)((char*)self + 0x48) = a2;
    *(int*)((char*)self + 0x4C) = a3;
    *(int*)((char*)self + 0x58) = trick;
    *(int*)((char*)self + 0x54) = 2;
    int h = GetHashValue32(D_00466338);
    *(int*)((char*)self + 0x5C) = three;
    *(int*)((char*)self + 0x60) = h;
    h = GetHashValue32(D_00466350);
    *(int*)((char*)self + 0x64) = three;
    *(int*)((char*)self + 0x68) = h;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CAFC0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00466368[];
extern char D_004A1408[];

extern "C" void func_001CAFC0(void* self, int a1, int a2, int a3)
{
    char* s = D_004A1408;
    int two = 2;
    *(char**)((char*)self + 0x58) = s;
    *(int*)((char*)self + 0x54) = two;
    *(int*)((char*)self + 0x48) = a2;
    *(int*)((char*)self + 0x4C) = a3;
    int h = GetHashValue32(D_00466368);
    *(int*)((char*)self + 0x64) = two;
    *(char**)((char*)self + 0x68) = s;
    *(int*)((char*)self + 0x5C) = 3;
    *(int*)((char*)self + 0x60) = h;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB030);
#ifdef SKIP_ASM
extern "C" void* func_0039E318(void* self, void* engine, void* owner);
extern "C" void cBXString_Reset(void* self);
extern "C" void func_001CE2A8(void* self);
extern int D_004A3E90;
extern void* D_004A33F0;
extern void* D_0046BEC8[];

extern "C" void* func_001CB030(void* self, void* engine, void* owner, int a3, unsigned char a4)
{
    func_0039E318(self, engine, owner);
    int d = D_004A3E90;
    *(unsigned char*)((char*)self + 0x15) = a4;
    *(int*)((char*)self + 0x70) = a3;
    *(int*)((char*)self + 0x418) = 0;
    *(int*)((char*)self + 0x41C) = 0;
    *(int*)((char*)self + 0x420) = 1;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x6C) = 0;
    *(int*)((char*)self + 0x68) = 1;
    *(char*)((char*)self + 0x74) = 0;
    *(int*)((char*)self + 0x134) = 0;
    *(int*)((char*)self + 0x138) = 0;
    *(int*)((char*)self + 0x13C) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x58) = 0;
    *(void***)((char*)self + 0x8) = D_0046BEC8;
    *(int*)((char*)self + 0x140) = 0x1D;
    *(int*)((char*)self + 0x424) = d;
    *(int*)((char*)self + 0x60) = 0x3F;
    cBXString_Reset((char*)self + 0x424);
    void* bx = D_004A33F0;
    *(int*)((char*)self + 0x144) = 2;
    *(int*)((char*)self + 0x434) = 0x2B;
    *(int*)((char*)self + 0x43C) = 1;
    *(int*)((char*)self + 0x428) = 0;
    *(int*)((char*)self + 0x42C) = 0;
    *(int*)((char*)self + 0x430) = 0;
    *(int*)((char*)self + 0x438) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0;
    if (bx != 0)
        *(int*)((char*)self + 0x68) = (*(unsigned int*)((char*)bx + 0x88) >> 1) & 1;
    func_001CE2A8(self);
    *(int*)((char*)self + 0x440) = 0;
    *(int*)((char*)self + 0x5C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB138);
#ifdef SKIP_ASM
extern void* D_0046BEC8[];
void cMemMan_free(void* ptr);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void func_0039E390(void* self, int flags);

extern "C" void func_001CB138(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046BEC8;
    void* p = *(void**)((char*)self + 0x428);
    if (p != 0) {
        cMemMan_free(p);
        *(void**)((char*)self + 0x428) = 0;
    }
    cBXString__cBXString((char*)self + 0x424, 2);
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cKeyboardPopup_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00466388[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cKeyboardPopup_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00466388), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB208);
#ifdef SKIP_ASM
struct sVEntry001CB208 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern void* D_004A2EEC;
extern void* D_004A28A8;
extern "C" void func_0039E510(void*);
extern "C" void func_0039F190(void* self, int a1);

extern "C" void func_001CB208(void* self)
{
    func_0039E510(self);
    if (D_004A2EEC != 0 && *(int*)((char*)D_004A2EEC + 0x64) == 0 && *(int*)((char*)D_004A28A8 + 0x84) != 0) {
        func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
    }
    if (*(int*)((char*)self + 0x440) != 0) {
        void* obj = *(void**)((char*)self + 0x20);
        if (obj != 0) {
            sVEntry001CB208* vt = *(sVEntry001CB208**)((char*)obj + 8);
            vt[12].fn((char*)obj + vt[12].delta);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB290);
#ifdef SKIP_ASM
extern "C" void func_0039F190(void* self, int a1);

extern "C" void func_001CB290(void* self, void* a1, unsigned int a2)
{
    switch (a2) {
    case 5:
    case 6:
        func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cKeyboardPopup_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern int D_004A1A70;
extern void* D_004A28A8;
extern char D_00466398[];
extern char D_004663A8[];
extern char D_004663B8[];
extern char D_004663C8[];

struct sVEntryK1CB2C8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline int isOnK1CB2C8()
{
    return D_004A1A70 == 1;
}

static inline int IsK1CB2C8(int id, char* s)
{
    return id == GetHashValue32(s);
}

extern "C" void cKeyboardPopup_onWidgetCreate(void* self, void* widget)
{
    if (IsK1CB2C8(*(int*)((char*)widget + 0x38), D_00466398)) {
        sVEntryK1CB2C8* vt = *(sVEntryK1CB2C8**)((char*)widget + 8);
        vt[9].fn((char*)widget + vt[9].delta, 0);
        if (isOnK1CB2C8()) {
            sVEntryK1CB2C8* vt2 = *(sVEntryK1CB2C8**)((char*)widget + 8);
            vt2[9].fn((char*)widget + vt2[9].delta, 1);
        }
        if (*(int*)((char*)D_004A28A8 + 0x84) != 0) {
            sVEntryK1CB2C8* vt3 = *(sVEntryK1CB2C8**)((char*)widget + 8);
            vt3[9].fn((char*)widget + vt3[9].delta, 0);
        }
    } else if (IsK1CB2C8(*(int*)((char*)widget + 0x38), D_004663A8)) {
        *(void**)((char*)self + 0x48) = widget;
    } else if (IsK1CB2C8(*(int*)((char*)widget + 0x38), D_004663B8)) {
        *(void**)((char*)self + 0x50) = widget;
    } else if (IsK1CB2C8(*(int*)((char*)widget + 0x38), D_004663C8)) {
        *(void**)((char*)self + 0x4C) = widget;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB3D0);
#ifdef SKIP_ASM
struct sVEntry001CB3D0 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" int func_001CB3D0(void* self, int a1, int a2)
{
    if (*(int*)((char*)self + 0x438) != 0) {
        void* obj = *(void**)((char*)self + 0x20);
        if (obj != 0) {
            sVEntry001CB3D0* vt = *(sVEntry001CB3D0**)((char*)obj + 8);
            return vt[24].fn((char*)obj + vt[24].delta, a1, a2);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB418);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void cKeyboardPopup_redrawScreen(void* self);
extern "C" void func_001CC848(void* self, int a1);

extern "C" void func_001CB418(void* self, const char* str)
{
    int one = 1;
    char* buf = (char*)self + 0x74;
    *(int*)((char*)self + 0x418) = one;
    strcpy(buf, str);
    *(int*)((char*)self + 0x134) = strlen(buf);
    *(int*)((char*)self + 0x138) = 0;
    *(int*)((char*)self + 0x13C) = strlen(buf);
    if (*(int*)((char*)self + 0x58) != 0) {
        func_001CE3C8(self, 0x4B, strlen(buf) ? one : 0, 2);
    }
    if (strlen(buf) < *(int*)((char*)self + 0x64)) {
        func_001CE3C8(self, 0x37, 0, 2);
    } else {
        func_001CE3C8(self, 0x37, 1, 2);
    }
    cKeyboardPopup_redrawScreen(self);
    if (*(int*)((char*)self + 0x41C) != 0) {
        func_001CC848(self, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB500);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern signed char D_00441390[];

extern "C" void func_001CB500(void* self, int a1)
{
    bool b = *(int*)((char*)self + 0x68) != 0;
    int flag;
    if (*(int*)((char*)self + 0x6C)) {
        flag = b;
        flag = !flag;
    } else {
        flag = b != 0;
    }
    int idx = *(int*)((char*)self + 0x140);
    int old = *(int*)((char*)self + 0x434);
    if (idx >= 15 && idx <= 26) {
        // PORT: reads the int field at 0x6C as a bool (bool is 4 bytes in SN gcc 2.95); use `*(int*)... == 0` off-PS2.
        flag = !*(bool*)((char*)self + 0x6C);
    }
    int st = *(int*)((char*)self + 0x430);
    if (a1) {
        *(int*)((char*)self + 0x434) = idx;
        *(int*)((char*)self + 0x430) = 2;
        if (st == 3) {
            *(int*)((char*)self + 0x140) = old;
            return;
        }
    }
    int s = *(int*)((char*)self + 0x140);
    if (s == 0 || s == 14 || s == 28 || s == 42 || s == 56 || s == 70)
        *(int*)((char*)self + 0x140) += 13;
    else
        *(int*)((char*)self + 0x140) = s - 1;
    while (D_00441390[*(int*)((char*)self + 0x140)] == 0x2A)
        *(int*)((char*)self + 0x140) -= 1;
    int val;
    if (func_001CE560_out(self, *(int*)((char*)self + 0x140), &val)) {
        *(int*)((char*)self + 0x144) = 2;
    } else {
        func_001CB500(self, 0);
        if (val)
            *(int*)((char*)self + 0x144) = flag == 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB650);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern signed char D_00441390[];

extern "C" void func_001CB650(void* self, int a1)
{
    bool b = *(int*)((char*)self + 0x68) != 0;
    int flag;
    if (*(int*)((char*)self + 0x6C)) {
        flag = b;
        flag = !flag;
    } else {
        flag = b != 0;
    }
    int idx = *(int*)((char*)self + 0x140);
    int old = *(int*)((char*)self + 0x434);
    if (idx >= 15 && idx <= 26) {
        // PORT: reads the int field at 0x6C as a bool (bool is 4 bytes in SN gcc 2.95); use `*(int*)... == 0` off-PS2.
        flag = !*(bool*)((char*)self + 0x6C);
    }
    int st = *(int*)((char*)self + 0x430);
    if (a1) {
        *(int*)((char*)self + 0x434) = idx;
        *(int*)((char*)self + 0x430) = 3;
        if (st == 2) {
            int v = *(int*)((char*)self + 0x144);
            if (v == 2 || (flag && v == 0) || (!flag && v == 0)) {
                if (func_001CE560_out(self, old, 0)) {
                    // the do/while(0) wrapper (a compiled-out macro block) is needed to match register allocation
                    do {
                        *(int*)((char*)self + 0x140) = old;
                        return;
                    } while (0);
                }
            }
        }
    }
    int s = *(int*)((char*)self + 0x140);
    if (s == 13 || s == 27 || s == 41 || s == 55 || s == 69 || s == 83)
        *(int*)((char*)self + 0x140) -= 13;
    else
        *(int*)((char*)self + 0x140) = s + 1;
    while (D_00441390[*(int*)((char*)self + 0x140)] == 0x2A)
        *(int*)((char*)self + 0x140) += 1;
    int val;
    if (func_001CE560_out(self, *(int*)((char*)self + 0x140), &val)) {
        *(int*)((char*)self + 0x144) = 2;
    } else {
        func_001CB650(self, 0);
        if (val)
            *(int*)((char*)self + 0x144) = flag == 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB7F0);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern signed char D_00441390[];
extern "C" int func_001CBB70(void* self, int a1);
extern "C" int func_001CBDB0(void* self, int a1);
extern "C" int func_001CBF20(void* self, int a1);

extern "C" void func_001CB7F0(void* self, int a1)
{
    bool b = *(int*)((char*)self + 0x68) != 0;
    int flag;
    if (*(int*)((char*)self + 0x6C)) {
        flag = b;
        flag = !flag;
    } else {
        flag = b != 0;
    }
    int idx = *(int*)((char*)self + 0x140);
    int old = *(int*)((char*)self + 0x434);
    if (idx >= 15 && idx <= 26) {
        // PORT: reads the int field at 0x6C as a bool (bool is 4 bytes in SN gcc 2.95); use `*(int*)... == 0` off-PS2.
        flag = !*(bool*)((char*)self + 0x6C);
    }
    int st = *(int*)((char*)self + 0x430);
    if (a1) {
        *(int*)((char*)self + 0x434) = idx;
        *(int*)((char*)self + 0x430) = 0;
        if (st == 1) {
            int v = *(int*)((char*)self + 0x144);
            if (v == 2 || (flag && v == 0) || (!flag && v == 0)) {
                if (func_001CE560_out(self, old, 0)) {
                    *(int*)((char*)self + 0x140) = old;
                    return;
                }
            }
        }
    }
    unsigned int s = *(unsigned int*)((char*)self + 0x140);
    if (s >= 70 && s <= 83) {
        if (func_001CBF20(self, flag))
            return;
        s = *(unsigned int*)((char*)self + 0x140);
    } else if (s >= 14 && s <= 27) {
        if (func_001CBDB0(self, flag))
            return;
        s = *(unsigned int*)((char*)self + 0x140);
    } else if (s < 14) {
        if (func_001CBB70(self, flag))
            return;
        s = *(unsigned int*)((char*)self + 0x140);
    }
    if (s < 14)
        *(int*)((char*)self + 0x140) = s + 70;
    else
        *(int*)((char*)self + 0x140) -= 14;
    while (D_00441390[*(int*)((char*)self + 0x140)] == 0x2A)
        *(int*)((char*)self + 0x140) -= 1;
    int val;
    if (func_001CE560_out(self, *(int*)((char*)self + 0x140), &val)) {
        *(int*)((char*)self + 0x144) = 2;
    } else {
        func_001CB7F0(self, 0);
        if (val)
            *(int*)((char*)self + 0x144) = flag == 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CB9B0);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern signed char D_00441390[];
extern "C" int func_001CBC48(void* self, int a1);
extern "C" int func_001CBCE8(void* self, int a1);
extern "C" int func_001CBFC0(void* self, int a1);

extern "C" void func_001CB9B0(void* self, int a1)
{
    bool b = *(int*)((char*)self + 0x68) != 0;
    int flag;
    if (*(int*)((char*)self + 0x6C)) {
        flag = b;
        flag = !flag;
    } else {
        flag = b != 0;
    }
    int idx = *(int*)((char*)self + 0x140);
    int old = *(int*)((char*)self + 0x434);
    if (idx >= 15 && idx <= 26) {
        // PORT: reads the int field at 0x6C as a bool (bool is 4 bytes in SN gcc 2.95); use `*(int*)... == 0` off-PS2.
        flag = !*(bool*)((char*)self + 0x6C);
    }
    int st = *(int*)((char*)self + 0x430);
    if (a1) {
        *(int*)((char*)self + 0x434) = idx;
        *(int*)((char*)self + 0x430) = 1;
        if (st == 0) {
            int v = *(int*)((char*)self + 0x144);
            if (v == 2 || (flag && v == 0) || (!flag && v == 0)) {
                if (func_001CE560_out(self, old, 0)) {
                    *(int*)((char*)self + 0x140) = old;
                    return;
                }
            }
        }
    }
    unsigned int s = *(unsigned int*)((char*)self + 0x140);
    if (s >= 56 && s <= 69) {
        if (func_001CBFC0(self, flag))
            return;
    } else if (s >= 70 && s <= 83) {
        if (func_001CBCE8(self, flag))
            return;
    } else if (s < 14) {
        if (func_001CBC48(self, flag))
            return;
    }
    unsigned int s2 = *(unsigned int*)((char*)self + 0x140);
    if (s2 >= 70 && s2 <= 83)
        *(int*)((char*)self + 0x140) = s2 - 70;
    else
        *(int*)((char*)self + 0x140) = s2 + 14;
    while (D_00441390[*(int*)((char*)self + 0x140)] == 0x2A)
        *(int*)((char*)self + 0x140) += 1;
    int val;
    if (func_001CE560_out(self, *(int*)((char*)self + 0x140), &val)) {
        *(int*)((char*)self + 0x144) = 2;
    } else {
        func_001CB9B0(self, 0);
        if (val)
            *(int*)((char*)self + 0x144) = flag == 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CBB70);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern "C" void func_001CC0E0(void* self, int a1);

extern "C" int func_001CBB70(void* self, int a1)
{
    int val;
    int state = *(int*)((char*)self + 0x140);
    if (state >= 5 && state <= 8) {
        if (func_001CE560_out(self, 0x4B, &val)) {
            *(int*)((char*)self + 0x140) = 0x4B;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC0E0(self, -1);
        }
        return 1;
    } else if (state >= 9 && state <= 10) {
        if (func_001CE560_out(self, 0x4C, &val)) {
            *(int*)((char*)self + 0x140) = 0x4C;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC0E0(self, -1);
        }
        return 1;
    } else if (state >= 11 && state <= 12) {
        if (func_001CE560_out(self, 0x4F, &val)) {
            *(int*)((char*)self + 0x140) = 0x4F;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC0E0(self, -1);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CBC48);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern "C" void func_001CC190(void* self);

extern "C" int func_001CBC48(void* self, int a1)
{
    int val;
    int state = *(int*)((char*)self + 0x140);
    if (state == 4) {
        if (func_001CE560_out(self, 0x10, &val)) {
            *(int*)((char*)self + 0x140) = 0x10;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC190(self);
        }
        return 1;
    } else if (state == 5) {
        if (func_001CE560_out(self, 0x12, &val)) {
            *(int*)((char*)self + 0x140) = 0x12;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC190(self);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CBCE8);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern "C" void func_001CC090(void* self);

extern "C" int func_001CBCE8(void* self, int a1)
{
    int val;
    int val2;
    int state = *(int*)((char*)self + 0x140);
    if (state == 0x4C) {
        if (func_001CE560_out(self, 0, &val)) {
            *(int*)((char*)self + 0x140) = 9;
        } else if (func_001CE560_out(self, 0x17, &val)) {
            *(int*)((char*)self + 0x140) = 0x17;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC090(self);
        }
        return 1;
    } else if (state == 0x4B) {
        if (func_001CE560_out(self, 0x13, &val2)) {
            *(int*)((char*)self + 0x140) = 0x13;
        } else {
            if (val2) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC090(self);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CBDB0);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern "C" void func_001CC0E0(void* self, int a1);

extern "C" int func_001CBDB0(void* self, int a1)
{
    int val;
    int r = func_001CE560_out(self, 0, 0);
    int state = *(int*)((char*)self + 0x140);
    if (r) {
        if (state >= 16 && state <= 17) {
            *(int*)((char*)self + 0x140) = 4;
            return 1;
        } else if (state == 18) {
            *(int*)((char*)self + 0x140) = 5;
            return 1;
        }
        return 0;
    }
    if (state >= 15 && state <= 22) {
        if (func_001CE560_out(self, 0x4B, &val)) {
            *(int*)((char*)self + 0x140) = 0x4B;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            if (*(int*)((char*)self + 0x140) == 0x14) {
                func_001CC0E0(self, 0x3E);
            } else {
                func_001CC0E0(self, -1);
            }
        }
        return 1;
    } else if (state == 23) {
        if (func_001CE560_out(self, 0x4C, &val)) {
            *(int*)((char*)self + 0x140) = 0x4C;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC0E0(self, -1);
        }
        return 1;
    } else if (state == 26) {
        if (func_001CE560_out(self, 0x53, &val)) {
            *(int*)((char*)self + 0x140) = 0x53;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC0E0(self, -1);
        }
        return 1;
    } else if (state >= 24 && state <= 25) {
        if (func_001CE560_out(self, 0x4F, &val)) {
            *(int*)((char*)self + 0x140) = 0x4F;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC0E0(self, -1);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CBF20);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern "C" void func_001CC140(void* self);

extern "C" int func_001CBF20(void* self, int a1)
{
    int val;
    int state = *(int*)((char*)self + 0x140);
    if (state == 0x4C) {
        if (func_001CE560_out(self, 0x42, &val)) {
            *(int*)((char*)self + 0x140) = 0x42;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC140(self);
        }
        return 1;
    } else if (state == 0x4F) {
        if (func_001CE560_out(self, 0x42, &val)) {
            *(int*)((char*)self + 0x140) = 0x42;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC140(self);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CBFC0);
#ifdef SKIP_ASM
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
extern "C" void func_001CC090(void* self);

extern "C" int func_001CBFC0(void* self, int a1)
{
    int val;
    int state = *(int*)((char*)self + 0x140);
    if (state == 0x39) {
        if (func_001CE560_out(self, 0x4B, &val)) {
            *(int*)((char*)self + 0x140) = 0x4B;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC090(self);
        }
        return 1;
    } else if (state >= 0x3A && state <= 0x41) {
        if (func_001CE560_out(self, 0x4B, &val)) {
            *(int*)((char*)self + 0x140) = 0x4B;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC090(self);
        }
        return 1;
    } else if (state == 0x42) {
        if (func_001CE560_out(self, 0x4C, &val)) {
            *(int*)((char*)self + 0x140) = 0x4C;
        } else {
            if (val) {
                *(int*)((char*)self + 0x144) = a1 == 0;
            }
            func_001CC090(self);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC090);
#ifdef SKIP_ASM
extern "C" int func_001CE560(void*, int, int);

extern "C" void func_001CC090(void* self)
{
    int i = *(int*)((char*)self + 0x140) - 0x38;
    while (!func_001CE560(self, i, 0)) {
        i += 0xE;
    }
    *(int*)((char*)self + 0x140) = i;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC0E0);
#ifdef SKIP_ASM
extern "C" int func_001CE560(void*, int, int);

extern "C" void func_001CC0E0(void* self, int start)
{
    int i;
    if (start == -1) {
        i = *(int*)((char*)self + 0x140) + 0x38;
    } else {
        i = start;
    }
    while (!func_001CE560(self, i, 0)) {
        i -= 0xE;
    }
    *(int*)((char*)self + 0x140) = i;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC140);
#ifdef SKIP_ASM
extern "C" int func_001CE560(void*, int, int);

extern "C" void func_001CC140(void* self)
{
    int i = *(int*)((char*)self + 0x140) - 0xE;
    while (!func_001CE560(self, i, 0)) {
        i -= 0xE;
    }
    *(int*)((char*)self + 0x140) = i;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC190);
#ifdef SKIP_ASM
extern "C" int func_001CE560(void*, int, int);

extern "C" void func_001CC190(void* self)
{
    int i = *(int*)((char*)self + 0x140) + 0xE;
    while (!func_001CE560(self, i, 0)) {
        i += 0xE;
    }
    *(int*)((char*)self + 0x140) = i;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC1E0);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern "C" void func_00416210(void* dst, int c, int n);
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void cKeyboardPopup_redrawScreen(void* self);
extern "C" int cKeyboardPopup_getObjName(void* self, int key, char* out, int a3);
extern "C" void func_001CC848(void* self, int a1);
extern "C" void func_001CC7C8(void* self);
extern "C" void func_001CE5E0(void* self, int digit);
extern "C" void func_001CC1E0(void* self, int a1);
// PORT: func_001CE560's third parameter is an int* out-param; the unit declares it (void*, int, int).
int func_001CE560_out(void* self, int idx, int* out) __asm__("func_001CE560");
// func_0039F190 returns its last list node in $v0; the unit declares it void.
void* func_0039F190_r(void* self, int a1) __asm__("func_0039F190");

struct sVE_C1E0 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

struct sUIObj_C1E0 {
    char pad_0x0[0x8];
    sVE_C1E0* vt;                   // 0x8
};

struct sColor_C1E0 {
    float r, g, b, a;
    sColor_C1E0(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};


struct sKeyboard_C1E0 {
    char pad_0x0[0x10];
    char* owner;                    // 0x10
    char pad_0x14[0xC];
    sUIObj_C1E0* parent;            // 0x20
    char pad_0x24[0x1C];
    void* screen;                   // 0x40
    char pad_0x44[0x10];
    int pendingAccept;              // 0x54
    int needText;                   // 0x58
    int done;                       // 0x5C
    int maxLen;                     // 0x60
    int minLen;                     // 0x64
    int caps;                       // 0x68
    int shift;                      // 0x6C
    char pad_0x70[0x4];
    char text[0xC0];                // 0x74
    int cursor;                     // 0x134
    int mark;                       // 0x138
    int end;                        // 0x13C
    int key;                        // 0x140
    char pad_0x144[0x2DC];
    int closeOnAccept;              // 0x420
};

// Handles the currently selected key of the on-screen keyboard.
extern "C" void func_001CC1E0(void* self_, int flag)
{
    sKeyboard_C1E0* self = (sKeyboard_C1E0*)self_;
    int redo = 0;
    int moved;
    if (self->pendingAccept != 0) {
        int key = self->key;
        if (key != 0x37 && key != 0x46) {
            self->pendingAccept = 0;
            self->key = 0x46;
            func_001CC1E0(self, 0);
            redo = 1;
            self->key = key;
        }
    }
    moved = 0;
    if (flag == 0 && func_001CE560_out(self, self->key, 0) != 0) {
        switch (self->key) {
        case 27: {
            int len = strlen(self->text);
            if (self->cursor != len) {
                if (self->cursor == 0)
                    break;
                if (self->cursor > 0)
                    self->cursor--;
                strcpy(&self->text[self->cursor], &self->text[self->cursor + 1]);
                if (self->mark == self->cursor + 1) {
                    self->mark = self->cursor;
                    moved = 1;
                }
                if ((unsigned int)strlen(self->text) < (unsigned int)self->end)
                    self->end = strlen(self->text);
            } else if (self->mark == self->cursor) {
                self->mark = 0;
            } else {
                if (self->cursor > 0)
                    self->cursor--;
                self->text[self->cursor] = 0;
                self->end = self->cursor;
            }
            break;
        }
        case 28:
        case 69:
        case 79:
            break;
        case 42:
            self->caps ^= 1;
            cKeyboardPopup_redrawScreen(self);
            break;
        case 56:
            self->shift ^= 1;
            cKeyboardPopup_redrawScreen(self);
            break;
        case 70:
            func_00416210(self->text, 0, 0x40);
            self->text[0] = 0;
            self->cursor = 0;
            self->end = 0;
            self->mark = 0;
            break;
        case 76:
            if (self->cursor == self->mark) {
                if (self->cursor != 0)
                    self->mark = self->cursor - 1;
                moved = 1;
            }
            if (self->cursor > 0)
                self->cursor--;
            break;
        case 83: {
            int len = strlen(self->text);
            if (self->cursor != len) {
                if (self->cursor < self->maxLen - 1)
                    self->cursor++;
                if (self->end == self->cursor)
                    self->end++;
            }
            break;
        }
        case 55:
            if (self->closeOnAccept != 0)
                func_0039F190_r(self->owner + 0x18, 1);
            self->done = 1;
            self->parent->vt[19].fn((char*)self->parent + self->parent->vt[19].delta, 0, 0xD);
            break;
        case 75:
            if (func_001CE560_out(self, 0x4B, 0) != 0)
                func_001CC7C8(self);
            break;
        case 0:
            func_0039F190_r(self->owner + 0x18, 1);
            self->parent->vt[19].fn((char*)self->parent + self->parent->vt[19].delta, 0, 0xE);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            func_001CE5E0(self, self->key - 4);
            break;
        default:
            func_001CC7C8(self);
            break;
        }
    }
    if (self->key != 0x38 && self->shift != 0) {
        self->shift ^= 1;
        cKeyboardPopup_redrawScreen(self);
    }
    func_001CC848(self, moved);
    if (self->needText != 0)
        func_001CE3C8(self, 0x4B, strlen(self->text) != 0, 2);
    if (strlen(self->text) < self->minLen)
        func_001CE3C8(self, 0x37, 0, 2);
    else
        func_001CE3C8(self, 0x37, 1, 2);
    cKeyboardPopup_redrawScreen(self);
    if (redo) {
        char name[32];
        cKeyboardPopup_getObjName(self, 0x46, name, 1);
        sUIObj_C1E0* o = (sUIObj_C1E0*)cUIScreen_getObjectByHashName(self->screen, GetHashValue32(name));
        if (o != 0) {
            // PORT: takes the address of a temporary (accepted by g++ 2.95); use a named local elsewhere.
            o->vt[11].fn((char*)o + o->vt[11].delta, &sColor_C1E0(0.3f, 0, 0, 0));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC620);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

extern "C" void func_001CC620(void* self, int value)
{
    char c = value;
    char* buf = (char*)self + 0x74;
    int len = strlen(buf);
    int cur = *(int*)((char*)self + 0x134);
    buf[cur] = c;
    if (cur == len) {
        if (*(int*)((char*)self + 0x134) == *(int*)((char*)self + 0x60) - 1) {
            buf[*(int*)((char*)self + 0x60)] = 0;
            *(int*)((char*)self + 0x13C) = *(int*)((char*)self + 0x134) + 1;
        } else {
            if (*(int*)((char*)self + 0x134) < *(int*)((char*)self + 0x60) - 1) {
                *(int*)((char*)self + 0x134) += 1;
            }
            buf[*(int*)((char*)self + 0x134)] = 0;
            *(int*)((char*)self + 0x13C) += 1;
        }
    } else {
        if (*(int*)((char*)self + 0x134) < *(int*)((char*)self + 0x60) - 1) {
            *(int*)((char*)self + 0x134) += 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC6E8);
#ifdef SKIP_ASM
extern "C" int func_001CE560(void*, int, int);
extern signed char D_00441390[];
extern signed char D_004413E8[];

extern "C" int func_001CC6E8(void* self, int value)
{
    char c = value;
    int i;
    if (c == 0x60) {
        *(int*)((char*)self + 0x140) = 0xE;
        return 1;
    }
    for (i = 0; i < 0x54; i++) {
        if ((D_00441390[i] == c || D_004413E8[i] == c) && D_00441390[i] != '*'
            && (D_00441390[i] != '@' || D_004413E8[i] != D_00441390[i])) {
            if (func_001CE560(self, i, 0)) {
                *(int*)((char*)self + 0x140) = i;
                return 1;
            }
            return 0;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001CC7C8);
#ifdef SKIP_ASM
extern "C" void func_001CC620(void* self, int value);
extern signed char D_00441390[];
extern signed char D_004413E8[];

extern "C" void func_001CC7C8(void* self)
{
    bool b = *(int*)((char*)self + 0x68) != 0;
    int flag = *(int*)((char*)self + 0x6C);
    if (flag) {
        flag = !b;
    } else {
        flag = b != 0;
    }
    int idx = *(int*)((char*)self + 0x140);
    if (idx >= 15 && idx <= 26) {
        // PORT: reads the int field at 0x6C as a bool (bool is 4 bytes in SN gcc 2.95); use `*(int*)... == 0` off-PS2.
        flag = !*(bool*)((char*)self + 0x6C);
    }
    if (flag) {
        func_001CC620(self, D_00441390[idx]);
    } else {
        func_001CC620(self, D_004413E8[idx]);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CC848);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
struct sPwd_CCE98;
extern "C" void func_001CCE98(sPwd_CCE98* self, char* str);
extern "C" void func_001CC8D8(void* self, int a1);
extern "C" void func_001CCC30(void* self);
extern char D_00466530[];

extern "C" void func_001CC848(void* self, int a1)
{
    func_001CC8D8(self, a1);
    cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00466530));
    if (text != 0) {
        if (*(int*)((char*)self + 0x70) != 0) {
            func_001CCE98((sPwd_CCE98*)self, (char*)self + 0xB4);
            cUIText_setAsciiString(text, (char*)self + 0xF4);
        } else {
            cUIText_setAsciiString(text, (char*)self + 0xB4);
        }
    }
    func_001CCC30(self);
}
#endif

INCLUDE_ASM("fe/fepopup", func_001CC8D8);

//100%
INCLUDE_ASM("fe/fepopup", func_001CCC30);
#ifdef SKIP_ASM
struct sVec3_CC30 { float x, y, z; };
struct sRect_CC30 {
    float x, y, w, h;
    void Measure(char* f, const char* str, int flag)
    {
        func_00391FB0(f, str, this, flag, *(float*)(f + 0x38), *(float*)(f + 0x3C));
    }
};
struct sVEntry_CC30 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};
extern "C" void func_001CE4C8(void* self, void* obj);
extern "C" char* strncpy(char* dst, const char* src, int n);
extern char D_00466570[];

extern "C" void func_001CCC30(void* self)
{
    sVec3_CC30 pos;
    char* s = (char*)self;

    void* text = cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466530));
    char* t = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466530));
    if (t != 0) {
        sVEntry_CC30* vt = *(sVEntry_CC30**)(t + 8);
        vt[20].fn(t + vt[20].delta, s + 0x3F4);
        *(sVec3_CC30*)(s + 0x3E8) = *(sVec3_CC30*)(t + 0x44);
    }
    *(float*)(s + 0x410) = *(float*)(s + 0x3F8) + *(float*)(s + 0x3EC) - *(float*)(s + 0x404) - 2.0f;
    unsigned char c = *(s + *(int*)(s + 0x134) + 0x74);
    char tc = *(s + *(int*)(s + 0x134) + 0x74);
    pos = *(sVec3_CC30*)(s + 0x400);
    if (tc != 0) {
        sRect_CC30 size;
        char ch[2];
        ch[1] = 0;
        if (*(int*)(s + 0x70) != 0) {
            ch[0] = '*';
        } else {
            ch[0] = c;
        }
        func_001CE4C8(self, text);
        char* f = (char*)func_003A04F0(text);
        size.Measure(f, ch, ch[0] == ' ');
        pos.x = size.w;
    }
    t = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466570));
    sVEntry_CC30* vt = *(sVEntry_CC30**)(t + 8);
    vt[21].fn(t + vt[21].delta, &pos);
    char buf[0x40];
    if (*(int*)(s + 0x70) != 0) {
        func_001CCE98((sPwd_CCE98*)self, s + 0xB4);
        strncpy(buf, s + 0xF4, *(int*)(s + 0x134) - *(int*)(s + 0x138));
    } else {
        strncpy(buf, s + 0xB4, *(int*)(s + 0x134) - *(int*)(s + 0x138));
    }
    buf[*(int*)(s + 0x134) - *(int*)(s + 0x138)] = 0;
    func_001CE4C8(self, text);
    char* f = (char*)func_003A04F0(text);
    sRect_CC30 size;
    size.Measure(f, buf, 1);
    sVec3_CC30 p = *(sVec3_CC30*)(s + 0x40C);
    p.x = size.w + *(float*)(s + 0x3E8);
    *(sVec3_CC30*)(t + 0x44) = p;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CCE98);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

struct sPwd_CCE98 {
    char pad[0xF4];
    char buf[1];
};

extern "C" void func_001CCE98(sPwd_CCE98* self, char* str)
{
    int n = strlen(str);
    int i;
    for (i = 0; i < n; i++) {
        self->buf[i] = '*';
    }
    self->buf[n] = 0;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CCF00);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00466580[];
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cBXString_cBXString4(void* self, const char* str);

extern "C" void func_001CCF00(void* self, const char* str)
{
    if (*(void**)((char*)self + 0x40) == 0) {
        cBXString_cBXString4((char*)self + 0x424, str);
        return;
    }
    cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00466580));
    if (text != 0) {
        cUIText_setAsciiString(text, str);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cKeyboardPopup_setStatic);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_003A0E90(cUIText* text, void* p);
void cMemMan_free(void* ptr);
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00466580[];
extern char D_00466590[];

extern "C" void cKeyboardPopup_setStatic(void* self, unsigned short* str)
{
    if (*(void**)((char*)self + 0x40) == 0) {
        void* p = *(void**)((char*)self + 0x428);
        if (p != 0) {
            cMemMan_free(p);
            *(void**)((char*)self + 0x428) = 0;
        }
        unsigned short* copy = (unsigned short*)operator_new_tag((USTR_length(str) + 1) * 2, D_00466590, 0x100, 0);
        *(unsigned short**)((char*)self + 0x428) = copy;
        USTR_copy(copy, str);
    } else {
        cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00466580));
        if (text != 0) {
            func_003A0E90(text, str);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CD020);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_00466580[];

extern "C" void func_001CD020(void* self, int id)
{
    if (*(void**)((char*)self + 0x40) == 0) {
        *(int*)((char*)self + 0x42C) = id;
    } else {
        cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00466580));
        if (text != 0) {
            cUIText_setUnicodeStringByID(text, id);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CD088);
#ifdef SKIP_ASM
extern "C" void func_001CD088(void* self, int v)
{
    if (v < 0) {
        *(int*)((char*)self + 0x60) = 0;
        return;
    }
    if (v >= 0x40) {
        *(int*)((char*)self + 0x60) = 0x3f;
        return;
    }
    *(int*)((char*)self + 0x60) = v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CD0B0);
#ifdef SKIP_ASM
extern "C" void func_001CD0B0(void* self, int v)
{
    if (v < 0) {
        *(int*)((char*)self + 0x64) = 0;
        return;
    }
    if (v >= 0x40) {
        *(int*)((char*)self + 0x64) = 0x3f;
        return;
    }
    *(int*)((char*)self + 0x64) = v;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cKeyboardPopup_getObjName);
#ifdef SKIP_ASM
struct sName8_1CD0E8 { char s[8]; };
struct sName10_1CD0E8 { char s[10]; };
extern char D_004A1368[];
extern sName10_1CD0E8 D_0045D550_1CD0E8 __asm__("D_0045D550");
extern char D_004A12A8[];
extern char D_004A1C80[];
extern char D_004A1C88[];
extern char D_004A1C90[];
extern char D_004A1350[];
extern char D_0045D560[];
extern char D_004A1C98[];
extern char D_004A1CA0[];
extern char D_004A1CA8[];
extern char D_004A1CB0[];
extern char D_004A1CB8[];
extern char D_004A1CC0[];
extern char D_004A1CC8[];

extern "C" int cKeyboardPopup_getObjName(void* self, int key, char* out, int shifted)
{
    char num[16];
    char ch[2];
    if (shifted != 0) {
        *(sName8_1CD0E8*)out = *(sName8_1CD0E8*)D_004A1368;
    } else {
        *(sName10_1CD0E8*)out = D_0045D550_1CD0E8;
    }
    switch (key) {
    case 27: func_004162D0(out, D_004A12A8); break;
    case 42: func_004162D0(out, D_004A1C80); break;
    case 56: func_004162D0(out, D_004A1C88); break;
    case 70: func_004162D0(out, D_004A1C90); break;
    case 76: func_004162D0(out, D_004A1350); break;
    case 83: func_004162D0(out, D_0045D560); break;
    case 28: func_004162D0(out, D_004A1C98); break;
    case 55: func_004162D0(out, D_004A1CA0); break;
    case 69: func_004162D0(out, D_004A1CA8); break;
    case 79: func_004162D0(out, D_004A1CB0); break;
    case 75: func_004162D0(out, D_004A1CB8); break;
    case 0: func_004162D0(out, D_004A1CC0); break;
    case 4: case 5: case 6: case 7: case 8:
    case 9: case 10: case 11: case 12: case 13:
        sprintf(num, D_004A1CC8, key - 3);
        func_004162D0(out, num);
        break;
    default:
        if (D_00441390[key] == '*') {
            return 0;
        }
        ch[0] = D_00441390[key];
        ch[1] = 0;
        func_004162D0(out, ch);
        break;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CD2F0);
#ifdef SKIP_ASM
extern "C" void func_001CCC30(void* self);
extern "C" void func_0039E4C0(void* self, int a1);

extern "C" void func_001CD2F0(void* self, int a1)
{
    if (*(int*)((char*)self + 0x134) == *(int*)((char*)self + 0x60)) {
        *(int*)((char*)self + 0x134) = *(int*)((char*)self + 0x134) - 1;
    }
    func_001CCC30(self);
    func_0039E4C0(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cKeyboardPopup_onGainTransition);
#ifdef SKIP_ASM
struct cUIScreen;
int GetHashValue32(char* str);
int cUIScreen_getFrameByLabel(cUIScreen* screen, int hash);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void cKeyboardPopup_redrawScreen(void* self);
extern "C" void cKeyboardPopup_setStatic(void* self, unsigned short* str);
extern "C" void func_001CB418(void* self, const char* str);
extern "C" void func_001CCF00(void* self, const char* str);
extern "C" void func_001CD020(void* self, int a1);
extern "C" void func_001CCC30(void* self);
extern "C" void cBXString_Reset(void* self);
extern "C" int sprintf(char* buf, const char* fmt, ...);
void cMemMan_free(void* ptr);
extern void* D_004A33F0;
extern char D_004A1CD0[];
extern char D_004A1CD8[];
extern char D_00466700[];
extern char D_00466570[];
extern char D_00466530[];
extern char D_00466710[];
extern char D_00466540[];
extern char D_00466558[];
extern char D_004A1408[];

struct sVec3_D348 { float x, y, z; };

struct sVEi_D348 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sVEp_D348 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sKbd_D348 {
    char pad_0x0[0x68];
    int f68;            // 0x68
    char pad_0x6C[0x41C - 0x6C];
    int f41C;           // 0x41C
};

static inline void SetVis_D348(char* o, int on)
{
    sVEi_D348* vt = *(sVEi_D348**)(o + 8);
    vt[9].fn(o + vt[9].delta, on);
}

extern "C" int cKeyboardPopup_onGainTransition(char* s, int first)
{
    if (first) {
        char buf[16];
        ((sKbd_D348*)s)->f41C = 1;
        ((sKbd_D348*)s)->f68 = 1;
        if (D_004A33F0 != 0) {
            ((sKbd_D348*)s)->f68 = (*(unsigned int*)((char*)D_004A33F0 + 0x88) >> 1) & 1;
        }
        *(int*)(s + 0x6C) = 0;
        if (*(int*)(s + 0x418) == 0) {
            s[0x74] = 0;
        }
        *(int*)(s + 0x138) = 0;
        *(int*)(s + 0x13C) = 0;
        *(int*)(s + 0x134) = 0;
        int a = 0;
        int c = 0;
        int b = 0;
        cKeyboardPopup_redrawScreen(s);
        switch (*(int*)(s + 0x43C)) {
        case 0:
            c = 1;
            sprintf(buf, D_004A1CD0);
            break;
        case 2:
            b = 1;
            sprintf(buf, D_00466700);
            break;
        case 1:
        default:
            a = 1;
            sprintf(buf, D_004A1CD8);
            break;
        }
        char* oa = *(char**)(s + 0x48);
        if (oa != 0) {
            SetVis_D348(oa, a);
        }
        char* ob = *(char**)(s + 0x50);
        if (ob != 0) {
            SetVis_D348(ob, b);
        }
        char* oc = *(char**)(s + 0x4C);
        if (oc != 0) {
            SetVis_D348(oc, c);
        }
        int f = cUIScreen_getFrameByLabel(*(cUIScreen**)(s + 0x40), GetHashValue32(buf));
        if (f != 0xFFFF) {
            cUIScreen_playFrame(*(void**)(s + 0x40), f, 1);
        }
        char* o1 = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466570));
        if (o1 != 0) {
            sVEp_D348* vt = *(sVEp_D348**)(o1 + 8);
            vt[20].fn(o1 + vt[20].delta, s + 0x400);
            *(sVec3_D348*)(s + 0x40C) = *(sVec3_D348*)(o1 + 0x44);
        }
        char* o2 = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466530));
        if (o2 != 0) {
            sVEp_D348* vt = *(sVEp_D348**)(o2 + 8);
            vt[20].fn(o2 + vt[20].delta, s + 0x3F4);
            *(sVec3_D348*)(s + 0x3E8) = *(sVec3_D348*)(o2 + 0x44);
            *(float*)(s + 0x410) = *(float*)(s + 0x3F8) + *(float*)(s + 0x3EC);
        }
        char* o3 = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466710));
        if (o3 != 0) {
            sVec3_D348 p = *(sVec3_D348*)(o3 + 0x44);
            *(float*)(s + 0x3E8) += p.x;
            *(float*)(s + 0x3EC) += p.y;
            *(float*)(s + 0x3F0) += p.z;
        }
        char* o4 = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466540));
        if (o4 != 0) {
            SetVis_D348(o4, 0);
        }
        char* o5 = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00466558));
        if (o5 != 0) {
            SetVis_D348(o5, 0);
        }
        if (*(int*)(s + 0x418) != 0) {
            func_001CB418(s, s + 0x74);
        }
        if (*(int*)(s + 0x42C) != 0) {
            func_001CD020(s, *(int*)(s + 0x42C));
            *(int*)(s + 0x42C) = 0;
        } else if (*(int*)(s + 0x428) != 0) {
            cKeyboardPopup_setStatic(s, *(unsigned short**)(s + 0x428));
            if (*(void**)(s + 0x428) != 0) {
                cMemMan_free(*(void**)(s + 0x428));
            }
            *(void**)(s + 0x428) = 0;
        } else {
            char** str = (char**)(s + 0x424);
            if (*(int*)(*str - 8) != 0) {
                func_001CCF00(s, *str);
                cBXString_Reset(str);
            } else {
                func_001CCF00(s, D_004A1408);
            }
        }
        func_001CCC30(s);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cKeyboardPopup_redrawScreen);
#ifdef SKIP_ASM
static inline bool Neg_D708(bool b) { return !b; }
static inline bool Shift_D708(char* s) { return *(bool*)(s + 0x6C); }
struct cUIText;
struct sVEntry_D708 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};
extern "C" int cKeyboardPopup_getObjName(void* self, int i, char* out, int mode);
extern "C" void cKeyboardPopup_SetNameForKey(void* self, cUIText* text, int i);
extern "C" void func_001CE520(void* self);
extern signed char D_00441390[];
extern signed char D_004413E8[];
extern char D_004C67B8[];
extern char D_004C67C8[];
extern char D_004C67E8[];
extern char D_004C67F8[];

extern "C" void cKeyboardPopup_redrawScreen(void* self)
{
    char* s = (char*)self;
    char name[0x20];
    char ch[2];
    if (*(void**)(s + 0x40) == 0) {
        return;
    }
    ch[1] = 0;
    for (int i = 0; i < 0x54; i++) {
        if (cKeyboardPopup_getObjName(self, i, name, 0) == 0) {
            continue;
        }
        cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(name));
        if (D_00441390[i] == '@' || D_00441390[i] == ' ') {
            cKeyboardPopup_SetNameForKey(self, text, i);
        } else {
            int caps = *(int*)(s + 0x68) != 0;
            bool upper;
            if (Shift_D708(s)) {
                upper = Neg_D708(caps);
            } else {
                upper = caps;
            }
            if (i >= 0xF && i < 0x1B) {
                upper = !Shift_D708(s);
            }
            func_001CE520(self);
            if (upper) {
                ch[0] = D_00441390[i];
            } else {
                ch[0] = D_004413E8[i];
            }
            if (text != 0) {
                cUIText_setAsciiString(text, ch);
                if (func_001CE560(self, i, 0) == 0) {
                    sVEntry_D708* vt = *(sVEntry_D708**)((char*)text + 8);
                    vt[11].fn((char*)text + vt[11].delta, D_004C67B8);
                } else {
                    sVEntry_D708* vt = *(sVEntry_D708**)((char*)text + 8);
                    vt[11].fn((char*)text + vt[11].delta, D_004C67C8);
                }
            }
        }
        cKeyboardPopup_getObjName(self, i, name, 1);
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(name));
        if (o != 0) {
            if (*(int*)(s + 0x43C) == 1) {
                if (i >= 0 && i < 0xE) {
                    sVEntry_D708* vt = *(sVEntry_D708**)(o + 8);
                    vt[9].fn(o + vt[9].delta, (void*)0);
                } else {
                    sVEntry_D708* vt = *(sVEntry_D708**)(o + 8);
                    vt[9].fn(o + vt[9].delta, (void*)1);
                }
            } else {
                {
                    sVEntry_D708* vt = *(sVEntry_D708**)(o + 8);
                    vt[11].fn(o + vt[11].delta, D_004C67F8);
                }
                {
                    sVEntry_D708* vt = *(sVEntry_D708**)(o + 8);
                    vt[9].fn(o + vt[9].delta, (void*)1);
                }
            }
        }
    }
    cKeyboardPopup_getObjName(self, *(int*)(s + 0x140), name, 1);
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(name));
    if (o != 0) {
        sVEntry_D708* vt = *(sVEntry_D708**)(o + 8);
        vt[11].fn(o + vt[11].delta, D_004C67E8);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", cKeyboardPopup_SetNameForKey);
#ifdef SKIP_ASM
extern "C" int func_001CE560(void* self, int key, int a2);
extern char D_004C67B8[];
extern char D_004C67C8[];
extern char D_004A1CC8[];
extern char D_00466720[];
extern char D_00466740[];
extern char D_00466760[];
extern char D_00466778[];
extern char D_00466790[];
extern char D_004667A8[];
extern char D_004667C0[];
extern char D_004667D8[];

struct sTextVE_1CD9B8 {
    short delta;
    short index;
    void* fn;
};

static inline void SetColor_1CD9B8(cUIText* text, void* col)
{
    sTextVE_1CD9B8* vt = *(sTextVE_1CD9B8**)((char*)text + 8);
    ((int (*)(void*, void*))vt[11].fn)((char*)text + vt[11].delta, col);
}

static inline void SetVisible_1CD9B8(cUIText* text, int on)
{
    sTextVE_1CD9B8* vt = *(sTextVE_1CD9B8**)((char*)text + 8);
    ((void (*)(void*, int))vt[9].fn)((char*)text + vt[9].delta, on);
}

extern "C" void cKeyboardPopup_SetNameForKey(void* vself, cUIText* text, int key)
{
    char* self = (char*)vself;
    char buf[16];
    if (text == 0) {
        return;
    }
    if (func_001CE560(self, key, 0) == 0) {
        SetColor_1CD9B8(text, D_004C67B8);
    } else {
        SetColor_1CD9B8(text, D_004C67C8);
    }
    switch (key) {
    case 27:
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466720));
        break;
    case 42:
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466740));
        SetColor_1CD9B8(text, D_004C67C8);
        break;
    case 56:
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466760));
        SetColor_1CD9B8(text, D_004C67C8);
        break;
    case 70:
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466778));
        break;
    case 28:
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00466790));
        break;
    case 55:
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_004667A8));
        break;
    case 75:
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_004667C0));
        break;
    case 0:
        if (*(int*)(self + 0x43C) == 1) {
            SetVisible_1CD9B8(text, 0);
        } else {
            SetVisible_1CD9B8(text, 1);
        }
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_004667D8));
        break;
    case 4: case 5: case 6: case 7: case 8:
    case 9: case 10: case 11: case 12: case 13:
        if (*(int*)(self + 0x43C) == 1) {
            SetVisible_1CD9B8(text, 0);
        } else {
            SetVisible_1CD9B8(text, 1);
        }
        sprintf(buf, D_004A1CC8, key - 3);
        cUIText_setAsciiString(text, buf);
        break;
    case 83:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CDB98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
extern "C" int cKeyboardPopup_getObjName(void* self, int key, char* out, int a3);
extern "C" void cKeyboardPopup_redrawScreen(void* self);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_001CB500(void* self, int a1);
extern "C" void func_001CB650(void* self, int a1);
extern "C" void func_001CB7F0(void* self, int a1);
extern "C" void func_001CB9B0(void* self, int a1);
extern "C" void func_001CC1E0(void* self, int a1);
extern "C" void func_001CC620(void* self, int value);
extern "C" bool func_001CC6E8_b(void* self, int value) __asm__("func_001CC6E8");
extern "C" int func_001CE560(void*, int, int);
extern "C" void* func_001D9D48(void* mem, void* engine, void* owner);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern "C" void func_0039F190(void* self, int a1);
extern "C" void func_0039F290(void* list, void* item);
extern int D_004A1A70;
extern void* D_004A28A8;
extern char D_00461A70[];
extern char D_00466940[];
extern char D_00466950[];
extern char D_00466968[];
extern char D_00466988[];
extern char D_004669A0[];
extern char D_004669B8[];
extern char D_004669D8[];

struct sVEntryK1CDB98 {
    short delta;
    short index;
    void* fn;
};
struct sColorK1CDB98 {
    float a, r, g, b;
    sColorK1CDB98(float a_, float r_, float g_, float b_) : a(a_), r(r_), g(g_), b(b_) {}
};
class cUIObjK1CDB98 {
public:
    char pad[0x8];
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
    virtual void SetColor(const sColorK1CDB98& c);
};
struct sSndK1CDB98 {
    sVEntryK1CDB98* vt;
};
extern sSndK1CDB98 D_004A5A58;

typedef int (*FnIK1CDB98)(void*);

static inline int InputK1CDB98(char* ev, int slot)
{
    sVEntryK1CDB98* vt = *(sVEntryK1CDB98**)(ev + 8);
    return ((FnIK1CDB98)vt[slot].fn)(ev + vt[slot].delta);
}

static inline int isOnK1CDB98()
{
    return D_004A1A70 == 1;
}

extern "C" int func_001CDB98(void* self, char* ev)
{
    if (InputK1CDB98(ev, 8) != 0)
        return 1;
    {
        char name[32];
        int changed = 0;
        int sound = 1;
        cKeyboardPopup_getObjName(self, *(int*)((char*)self + 0x140), name, 1);
        {
            cUIObjK1CDB98* o = (cUIObjK1CDB98*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
            if (o != 0) {
                o->SetColor(sColorK1CDB98(0.3f, 0.0f, 0.0f, 0.0f));
            }
        }
        if (InputK1CDB98(ev, 19)) {
            changed = 1;
            func_001CB500(self, 1);
        } else if (InputK1CDB98(ev, 20)) {
            changed = 1;
            func_001CB650(self, 1);
        } else if (InputK1CDB98(ev, 17)) {
            changed = 1;
            func_001CB7F0(self, 1);
        } else if (InputK1CDB98(ev, 18)) {
            changed = 1;
            func_001CB9B0(self, 1);
        } else if (InputK1CDB98(ev, 5)) {
            changed = 1;
            func_001CC1E0(self, 0);
        } else if (InputK1CDB98(ev, 7)) {
            if (isOnK1CDB98()) {
                if (*(int*)((char*)D_004A28A8 + 0x84) == 0) {
                    changed = 1;
                    void* p = func_001D9D48(cMemMan_alloc(0x140, D_00461A70, 0x100, 0), *(void**)((char*)self + 0x10), self);
                    func_001DA528(p, 6);
                    *(int*)((char*)p + 0x54) = GetHashValue32(D_00466940);
                    func_001DA530(p, 0, GetHashValue32(D_00466950));
                    func_001DA510(p, 0, GetHashValue32(D_00466968), 4);
                    func_001DA510(p, 1, GetHashValue32(D_00466968), 3);
                    func_001DA510(p, 2, GetHashValue32(D_00466988), 5);
                    func_001DA510(p, 3, GetHashValue32(D_004669A0), 6);
                    func_001DA510(p, 4, GetHashValue32(D_004669B8), 0);
                    func_001DA510(p, 5, GetHashValue32(D_004669D8), 1);
                    func_0039F290(*(char**)((char*)self + 0x10) + 0x18, p);
                }
                sound = 5;
            }
        } else if (InputK1CDB98(ev, 6)) {
            changed = 1;
            sound = 6;
            func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
            char* o = *(char**)((char*)self + 0x20);
            sVEntryK1CDB98* vt = *(sVEntryK1CDB98**)(o + 8);
            ((void (*)(void*, int, int))vt[19].fn)(o + vt[19].delta, 0, 0xE);
        } else if (InputK1CDB98(ev, 25)) {
            changed = 1;
            *(int*)((char*)self + 0x68) ^= 1;
            cKeyboardPopup_redrawScreen(self);
        } else if (InputK1CDB98(ev, 27)) {
            changed = 1;
            *(int*)((char*)self + 0x6C) ^= 1;
            cKeyboardPopup_redrawScreen(self);
        } else {
            int fail = 0;
            if (InputK1CDB98(ev, 41)) {
                int typed = 0;
                switch (InputK1CDB98(ev, 42)) {
                case 8:
                    if (func_001CE560(self, 0x1B, 0)) *(int*)((char*)self + 0x140) = 0x1B;
                    else fail = 1;
                    break;
                case 0xD:
                    *(int*)((char*)self + 0x140) = 0x37;
                    break;
                case 0x10:
                    if (func_001CE560(self, 0x38, 0)) *(int*)((char*)self + 0x140) = 0x38;
                    else fail = 1;
                    break;
                case 0x14:
                    if (func_001CE560(self, 0x2A, 0)) *(int*)((char*)self + 0x140) = 0x2A;
                    else fail = 1;
                    break;
                case 0x1B:
                    if (func_001CE560(self, 0, 0)) *(int*)((char*)self + 0x140) = 0;
                    else fail = 1;
                    break;
                case 0x25:
                    if (func_001CE560(self, 0x4C, 0)) *(int*)((char*)self + 0x140) = 0x4C;
                    else fail = 1;
                    break;
                case 0x27:
                    if (func_001CE560(self, 0x53, 0)) *(int*)((char*)self + 0x140) = 0x53;
                    else fail = 1;
                    break;
                case 0x26:
                    if (func_001CE560(self, 0x45, 0)) *(int*)((char*)self + 0x140) = 0x45;
                    else fail = 1;
                    break;
                case 0x28:
                    if (func_001CE560(self, 0x4F, 0)) *(int*)((char*)self + 0x140) = 0x4F;
                    else fail = 1;
                    break;
                case 9:
                    if (func_001CE560(self, 0x1C, 0)) *(int*)((char*)self + 0x140) = 0x1C;
                    else fail = 1;
                    break;
                case 0x70: case 0x71: case 0x72: case 0x73: case 0x74:
                case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: {
                    int key = InputK1CDB98(ev, 42) - 0x6C;
                    if (func_001CE560(self, key, 0)) *(int*)((char*)self + 0x140) = key;
                    else fail = 1;
                    break;
                }
                default:
                    if (InputK1CDB98(ev, 43) >= 0x20) {
                        char c = InputK1CDB98(ev, 43);
                        fail = !func_001CC6E8_b(self, c);
                        if (!fail) {
                            if (func_001CE560(self, *(int*)((char*)self + 0x140), 0)) {
                                if (c == 0x60) func_001CC620(self, 0x7E);
                                else func_001CC620(self, c);
                            } else {
                                fail = 1;
                            }
                        }
                    }
                    typed = 1;
                    break;
                }
                if (!fail) {
                    changed = 1;
                    func_001CC1E0(self, typed);
                }
            }
        }
        cKeyboardPopup_getObjName(self, *(int*)((char*)self + 0x140), name, 1);
        {
            cUIObjK1CDB98* o = (cUIObjK1CDB98*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
            if (o != 0) {
                o->SetColor(sColorK1CDB98(1.0f, 0.0f, 0.0f, 0.0f));
            }
        }
        sSndK1CDB98* snd = *(sSndK1CDB98**)(*(char**)((char*)self + 0x10) + 0x14);
        if (snd == 0)
            snd = &D_004A5A58;
        if (changed && snd != 0)
            ((void (*)(void*, int))snd->vt[2].fn)((char*)snd + snd->vt[2].delta, sound);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CE2A8);
#ifdef SKIP_ASM
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_001CE468(void* self, int a1);
extern "C" int strlen(const char* s);
extern signed char D_00441390[];

extern "C" void func_001CE2A8(void* self)
{
    int i;
    for (i = 0; i < 0x54; i++) {
        if (D_00441390[i] == '*' || i == 0x1C) {
            func_001CE3C8(self, i, 0, 2);
        } else if (i == 0x45 || i == 0x4F || i == 0x29) {
            func_001CE3C8(self, i, 0, 2);
        } else if (i == 0x4B) {
            if (strlen((char*)self + 0x74) != 0 && *(int*)((char*)self + 0x58) != 0)
                func_001CE3C8(self, i, 1, 2);
            else
                func_001CE3C8(self, i, 0, 2);
        } else {
            func_001CE3C8(self, i, 1, 2);
        }
    }
    func_001CE468(self, 0);
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CE3C8);
#ifdef SKIP_ASM
extern "C" void func_001CE3C8(void* self, int i, int v, int mode)
{
    if (mode == 0 || mode == 2) {
        *(int*)((char*)self + (i << 2) + 0x148) = v;
    }
    if (mode == 1 || mode == 2) {
        *(int*)((char*)self + (i << 2) + 0x298) = v;
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CE408);
#ifdef SKIP_ASM
extern "C" void func_001CE408(void* self, bool on)
{
    int i;
    for (i = 0xF; i < 0x19; i++) {
        func_001CE3C8(self, i, !on, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CE468);
#ifdef SKIP_ASM
extern "C" void func_001CE468(void* self, int v)
{
    int i;
    for (i = 0; i < 0xE; i++) {
        func_001CE3C8(self, i, v, 2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CE4C8);
#ifdef SKIP_ASM
struct sVec3_CE4C8 { float x, y, z; };

extern "C" void* func_003A04F0(void* self);

extern "C" void func_001CE4C8(void* self, void* obj)
{
    sVec3_CE4C8 v = *(sVec3_CE4C8*)((char*)obj + 0x50);
    char* p = (char*)func_003A04F0(obj);
    float x = *(float*)(p + 0x30) * v.x;
    float y = *(float*)(p + 0x34) * v.y;
    *(float*)(p + 0x38) = x;
    *(float*)(p + 0x3C) = y;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/fepopup", func_001CE520);
#ifdef SKIP_ASM
extern "C" int func_001CE560(void*, int, int);
extern "C" void func_001CB9B0(void*, int);

extern "C" void func_001CE520(void* self)
{
    if (func_001CE560(self, *(int*)((char*)self + 0x140), 0) == 0) {
        func_001CB9B0(self, 0);
    }
}
#endif

INCLUDE_ASM("fe/fepopup", func_001CE560);

//100%
INCLUDE_ASM("fe/fepopup", func_001CE5E0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" char* func_0014F6A8(void* self, int i);
int cBEOptionInterface_getDefaultQuickKeyMessageHashValue(void* self, int value);
extern "C" void func_003DCB20(char* dst, void* src);
extern "C" char* func_004162D0(char* dst, const char* src);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern void* D_004A28A8;

struct sVEntryK1CE5E0 {
    short delta;
    short index;
    void* (*fn)(void*, int);
};

extern "C" void func_001CE5E0(void* self, int key)
{
    char buf[0x40];
    int room = *(int*)((char*)self + 0x60) - strlen((char*)self + 0x74);
    void* opt = cBE_getInterface_Fv(cBE_getBE(), 4);
    char* msg = func_0014F6A8(opt, key);
    if (msg == 0) {
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntryK1CE5E0* vt = *(sVEntryK1CE5E0**)(o + 4);
        void* str = vt[4].fn(o + vt[4].delta, cBEOptionInterface_getDefaultQuickKeyMessageHashValue(opt, key));
        if (str)
            func_003DCB20(buf, str);
        else
            buf[0] = 0;
    } else {
        strcpy(buf, msg);
    }
    buf[room] = 0;
    func_004162D0((char*)self + 0x74, buf);
    int len = strlen((char*)self + 0x74);
    int n = len - 1;
    *(int*)((char*)self + 0x134) = n;
    if (n < *(int*)((char*)self + 0x60) - 1)
        *(int*)((char*)self + 0x134) = len;
}
#endif

//100%
INCLUDE_ASM("fe/fepopup", func_001CE6F0);
#ifdef SKIP_ASM
struct sPopupSlot_E6F0 {
    signed char id;
    signed char pad;
};

extern sPopupSlot_E6F0 D_0045AAD8[][4][5];

extern "C" int func_001CE6F0(int a, int b)
{
    int n = 0;
    for (int i = 0; i < 5; i++) {
        if (D_0045AAD8[a][b][i].id >= 0) {
            n++;
        } else {
            break;
        }
    }
    return n;
}
#endif

