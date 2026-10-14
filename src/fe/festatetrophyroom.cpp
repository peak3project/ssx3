#include "common.h"

//100%
INCLUDE_ASM("fe/festatetrophyroom", cFEStateTrophyRoom_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern char D_004676C8[];

extern "C" void cFEStateTrophyRoom_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004676C8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

extern "C" void* func_0039E4C0(void* self);

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D43D0__FPv);
#ifdef SKIP_ASM
void* func_001D43D0(void* self)
{
    return func_0039E4C0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", cFEStateTrophyRoom_onWidgetCreate);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
int GetHashValue32(char* str);
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" char* func_00156A90(void* self, int a1, int a2);
extern "C" int func_001CE6F0(int a, int b);
extern "C" void func_001D47A0(void* self, int index);
extern "C" void setChallengeName(void* text, int a1, int a2, int idx);
extern char D_004A1FE8[];
extern char D_004A1FF0[];
extern char D_00466E60[];
extern char D_004676D8[];
extern char D_004676F0[];
extern char D_00467708[];
extern char D_00467720[];
extern char* D_00441600[];
extern char* D_00441618[];

struct sVEntry_43F0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sTrophy_43F0 {
    char pad0[0x48];
    void* f48;          // 0x48
    void* f4C;          // 0x4C
    char pad50[4];
    int f54;            // 0x54
    int f58;            // 0x58
    char pad5C[0x40];
    int f9C;            // 0x9C
};

static inline void vcall_43F0(void* o, int slot, int arg)
{
    sVEntry_43F0* vt = *(sVEntry_43F0**)((char*)o + 8);
    vt[slot].fn((char*)o + vt[slot].delta, arg);
}

extern "C" void cFEStateTrophyRoom_onWidgetCreate(sTrophy_43F0* self, void* w)
{
    int h = *(int*)((char*)w + 0x38);
    if (h == GetHashValue32(D_004A1FE8)) {
        self->f48 = w;
        func_001D47A0(self, self->f9C);
        return;
    }
    if (h == GetHashValue32(D_004A1FF0)) {
        self->f4C = w;
        vcall_43F0(w, 9, 0);
        return;
    }
    if (h == GetHashValue32(D_00466E60)) {
        int id = 0;
        switch (self->f58) {
        case 3:
            id = GetHashValue32(D_004676D8);
            break;
        case 2:
            id = GetHashValue32(D_004676F0);
            break;
        case 0:
            id = GetHashValue32(D_00467708);
            break;
        case 1:
            id = GetHashValue32(D_00467720);
            break;
        }
        cUIText_setUnicodeStringByID((cUIText*)w, id);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (h == GetHashValue32(D_00441600[i])) {
            int n = func_001CE6F0(self->f54, self->f58);
            *(int*)((char*)w + 0x18) = i;
            if (n < i) {
                vcall_43F0(w, 9, 0);
                vcall_43F0(w, 8, 1);
            } else if (i == 0) {
                cUIText_setAsciiString((cUIText*)w, *(char**)func_00156A90(cBE_getInterface_Fv(cBE_getBE(), 0xD), self->f54, self->f58));
            } else {
                setChallengeName(w, self->f54, self->f58, i - 1);
            }
        } else if (h == GetHashValue32(D_00441618[i])) {
            if (func_001CE6F0(self->f54, self->f58) < i) {
                vcall_43F0(w, 9, 0);
                vcall_43F0(w, 8, 1);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4660);
#ifdef SKIP_ASM
extern "C" int func_001D4660(void* self, int a1, unsigned int a2)
{
    switch (a2) {
    case 6:
    case 8:
    case 9:
        return 0x100;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4698);
#ifdef SKIP_ASM
struct sVEntry001D4698 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};
extern "C" void func_0039F400(void* list, void* item);
extern "C" void func_001D47A0(void* self, int index);
extern "C" void func_001D4890(void* self, int index);

class cTrophyWidget_4698 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

extern "C" void func_001D4698(void* self, void* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 6: {
        cTrophyWidget_4698* w = *(cTrophyWidget_4698**)((char*)self + 0x48);
        if (w != 0) {
            w->show(0);
        }
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry001D4698* vt = *(sVEntry001D4698**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, *(int*)((char*)self + 0x54));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    case 1:
        *(int*)((char*)self + 0x9C) = *(int*)((char*)item + 0x18);
        func_001D47A0(self, *(int*)((char*)item + 0x18));
        func_001D4890(self, *(int*)((char*)item + 0x18));
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4760);
#ifdef SKIP_ASM
extern "C" void func_001D4A20(void* self);
extern "C" void* func_0039E510(void* self);

extern "C" void func_001D4760(void* self)
{
    if (*(int*)((char*)self + 0x5C) > 0) {
        func_001D4A20(self);
    }
    func_0039E510(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D47A0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00157BF0(void* self, int rider, int a, int b, int c);
extern "C" int func_001CED90(int rider, int a, int b, int c, int index);

class cTrophyWidget_47A0 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

extern "C" void func_001D47A0(void* self, int index)
{
    int v;
    if (index < 0) {
        goto hide;
    }
    v = -1;
    {
        if (index == 0) {
            if (func_00157BF0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(signed char*)((char*)self + 0x44),
                              *(int*)((char*)self + 0x50), *(int*)((char*)self + 0x54),
                              *(int*)((char*)self + 0x58)) != 0) {
                v = *(int*)((char*)self + 0x60);
            }
        } else {
            int r = func_001CED90(*(signed char*)((char*)self + 0x44),
                                  *(int*)((char*)self + 0x50), *(int*)((char*)self + 0x54),
                                  *(int*)((char*)self + 0x58), index - 1);
            if (r != -1) {
                v = *(int*)((char*)self + ((r + 1) << 2) + 0x60);
            }
        }
    }
    if (v < 0) {
    hide:
        (*(cTrophyWidget_47A0**)((char*)self + 0x48))->show(0);
    } else {
        (*(cTrophyWidget_47A0**)((char*)self + 0x48))->show(1);
        char* w = *(char**)((char*)self + 0x48);
        *(int*)(w + 0x78) = v;
        *(int*)(w + 0x7C) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4890);
#ifdef SKIP_ASM
extern "C" void setChallengeStats(void* widget, signed char rider, int a2, int a3, int a4, int index);

// Real virtual class so g++ emits the vcall itself (vptr at +8, after 8 bytes of data).
class cTrophyWidget_4890 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

extern "C" void func_001D4890(void* self, int index)
{
    cTrophyWidget_4890* widget = *(cTrophyWidget_4890**)((char*)self + 0x4C);
    if (widget != 0) {
        if (index == 0) {
            widget->show(0);
        } else {
            widget->show(1);
            setChallengeStats(*(void**)((char*)self + 0x4C), *(signed char*)((char*)self + 0x44),
                              *(int*)((char*)self + 0x50), *(int*)((char*)self + 0x54),
                              *(int*)((char*)self + 0x58), index - 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4918);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" char* func_00156A90(void* self, int a1, int a2);
extern "C" char* func_00156AE0(void* self, int a1, int a2);
extern "C" int func_0019DA10(void* self, int bank, int id, int a3, int a4, int a5);
extern void* D_004A28A8;

struct sTrophyRoom_4918 {
    char pad[0x50];
    int bank;
    int f54;
    int f58;
    int count;
    char pad60[0x14];
    int ids[5];
};

extern "C" void func_001D4918(sTrophyRoom_4918* self)
{
    void* pi = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    void* snd = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    self->ids[0] = func_0019DA10(snd, self->bank, *(int*)(func_00156A90(pi, self->f54, self->f58) + 4), 0xA, 1, 0);
    self->count = 1;
    for (int i = 0; i < 4; i++) {
        int id = *(int*)(func_00156AE0(pi, self->f58, i) + 4);
        if (id != 0) {
            self->ids[i + 1] = func_0019DA10(snd, self->bank, id, 0xA, 1, 0);
            self->count++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4A20);
#ifdef SKIP_ASM
extern "C" int func_0019E238(void* self, int bank, int i);
extern "C" char* func_0019E2B0(void* self, int bank, int i);
extern "C" void func_0019DC20(void* self, int bank, int i);
extern "C" void func_001D47A0(void* self, int index);
extern void* D_004A289C;
extern void* D_004A28A8;
extern char D_004A1FF8[];

struct cGame_4A20 {
    char pad[0x10D8];
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual int playSound(void* data, char* name, int a3, int a4, int a5);
};

struct sSelf_4A20 {
    char pad[0x50];
    int bank;
    char pad54[0x8];
    int count;
    int snd[5];
    int tex[5];
    char pad88[0x14];
    int f9C;
};

extern "C" void func_001D4A20(void* p)
{
    sSelf_4A20* self = (sSelf_4A20*)p;
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    int i;
    for (i = 0; i < 5; i++) {
        if (self->tex[i] >= 0 && func_0019E238(mgr, self->bank, self->tex[i]) != 0) {
            char* d = func_0019E2B0(mgr, self->bank, self->tex[i]);
            self->snd[i] = ((cGame_4A20*)D_004A289C)->playSound(d + *(int*)(d + 0x14), D_004A1FF8, 0, 1, -1);
            func_0019DC20(mgr, self->bank, self->tex[i]);
            self->tex[i] = -1;
            self->count--;
            func_001D47A0(self, self->f9C);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4B20);
#ifdef SKIP_ASM
struct cGame001D4B20 {
    char pad[0x10D8];
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50(int id);
};

extern void* D_004A289C;
extern void* D_004A28A8;
extern "C" void func_0019DC20(void* self, int bank, int i);
struct sSelf001D4B20 {
    char pad[0x50];
    int bank;
    char pad54[0xC];
    int snd[5];
    int tex[5];
};

extern "C" void func_001D4B20(sSelf001D4B20* self)
{
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    int i;
    for (i = 0; i < 5; i++) {
        if (self->snd[i] >= 0) {
            ((cGame001D4B20*)D_004A289C)->v50(self->snd[i]);
        }
        self->snd[i] = -1;
        if (self->tex[i] >= 0) {
            func_0019DC20(mgr, self->bank, self->tex[i]);
        }
        self->tex[i] = -1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4BC8);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern "C" unsigned char func_001A1CD0(void* self, signed char a1);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern void* D_004695E8[];

extern "C" void* func_001D4BC8(void* self, int a1, signed char idx, int a3)
{
    func_0039E2A0(self);
    *(int*)((char*)self + 0xC) = 0x2E;
    *(void***)((char*)self + 0x8) = D_004695E8;
    *(signed char*)((char*)self + 0x44) = idx;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), idx);
    *(int*)((char*)self + 0x4C) = a3;
    *(int*)((char*)self + 0x48) = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)((char*)self + 0x44));
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", cFEStateRewardsRoom_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* self, int a1);
extern char D_00467738[];

extern "C" void cFEStateRewardsRoom_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00467738), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0028F140(func_0028B180(), 6);
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", cFEStateRewardsRoom_onWidgetCreate);
#ifdef SKIP_ASM
struct cUIText;
extern "C" void func_001D4F90(void* self, int index, cUIText* text);
extern char D_004A2000[];
extern char D_004A2008[];
extern char D_004A2010[];
extern char D_004A2018[];
extern char D_00467748[];
extern char D_00467758[];
extern char D_004674A8[];
extern char D_004674B8[];
extern char D_004674C8[];
extern char D_004674D8[];
extern char D_004674E8[];
extern char D_00467768[];

extern "C" void cFEStateRewardsRoom_onWidgetCreate(void* self, void* w)
{
    int id = *(int*)((char*)w + 0x38);
    if (id == GetHashValue32(D_004A2000)) {
        *(int*)((char*)w + 0x18) = 5;
    } else if (id == GetHashValue32(D_004A2008)) {
        *(int*)((char*)w + 0x18) = 6;
    } else if (id == GetHashValue32(D_004A2010)) {
        *(int*)((char*)w + 0x18) = 3;
    } else if (id == GetHashValue32(D_004A2018)) {
        *(int*)((char*)w + 0x18) = 7;
    } else if (id == GetHashValue32(D_00467748)) {
        *(int*)((char*)w + 0x18) = 4;
    } else if (id == GetHashValue32(D_00467758)) {
        *(int*)((char*)w + 0x18) = 8;
    } else if (id == GetHashValue32(D_004674A8)) {
        func_001D4F90(self, 5, (cUIText*)w);
    } else if (id == GetHashValue32(D_004674B8)) {
        func_001D4F90(self, 3, (cUIText*)w);
    } else if (id == GetHashValue32(D_004674C8)) {
        func_001D4F90(self, 7, (cUIText*)w);
    } else if (id == GetHashValue32(D_004674D8)) {
        func_001D4F90(self, 4, (cUIText*)w);
    } else if (id == GetHashValue32(D_004674E8)) {
        func_001D4F90(self, 8, (cUIText*)w);
    } else if (id == GetHashValue32(D_00467768)) {
        func_001D4F90(self, 6, (cUIText*)w);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4EA8);
#ifdef SKIP_ASM
struct sVEntry001D4EA8 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};
extern "C" void func_0039F400(void* list, void* item);

extern "C" void func_001D4EA8(void* self, void* item, unsigned int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 0:
        break;
    case 5: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry001D4EA8* vt = *(sVEntry001D4EA8**)((char*)obj + 4);
        void* r = vt[4].fn((char*)obj + vt[4].delta, self, *(int*)((char*)item + 0x18));
        func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        break;
    }
    case 6: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry001D4EA8* vt = *(sVEntry001D4EA8**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, *(int*)((char*)item + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4F68);
#ifdef SKIP_ASM
// Key filter: keys 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001D4F68(void* self, int a1, unsigned int key)
{
    int r = 0x101;
    if (key < 10) {
        if (key < 8) {
            r = 0x101;
        } else {
            return 0x100;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D4F90);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_00157210(void* iface, int index);
extern "C" int func_00157518(void* iface, int rider, int a, int index);
extern char D_004A2020[];

extern "C" void func_001D4F90(void* self, int index, cUIText* text)
{
    char buf[256];
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0xD);
    int total = func_00157210(iface, index);
    int got = func_00157518(iface, *(signed char*)((char*)self + 0x44), *(int*)((char*)self + 0x48), index);
    sprintf(buf, D_004A2020, got, total);
    cUIText_setAsciiString(text, buf);
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5038);
#ifdef SKIP_ASM
extern "C" void* func_001BEE30(void* self);
extern void* D_00468050[];

extern "C" void* func_001D5038(void* self)
{
    func_001BEE30(self);
    *(void***)((char*)self + 0x8) = D_00468050;
    *(int*)((char*)self + 0xC) = 0x34;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5078);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern char D_00467778[];

extern "C" void func_001D5078(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00467778), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D50E0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_00467790[];
extern char D_00461CC0[];

extern "C" void func_001D50E0(void* self, cUIText* item)
{
    int id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_00467790)) {
        cUIText_setUnicodeStringByID(item, GetHashValue32(D_00461CC0));
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5138);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" int func_001BF228(void* self, int msg);
extern "C" void* func_001BFBB8(void* mem, int a1);
extern "C" void func_0025C610(void* mgr);
extern "C" void* func_0025CD50(void*, int);
extern "C" void func_0025FD50(void* mgr, int a1, int a2, int a3, char* a4, char* a5);
extern void* D_004A28A8;
extern void* D_004A3028;
extern char D_0045FF28[];
extern char D_00534B30[];

extern "C" int func_001D5138(void* self, int msg)
{
    switch (msg) {
    case 0xC9:
        func_0025C610(D_004A3028);
        break;
    case 0xD4:
        func_0025CD50(D_004A3028, *(int*)((char*)D_004A3028 + 0x80));
        break;
    case 0x101:
        func_001A8A40(self, func_001BFBB8(cMemMan_alloc(0x6D0, D_0045FF28, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    case 0x111: {
        cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
        char* g = D_00534B30;
        func_0025FD50(D_004A3028, *(int*)(g + 4), *(int*)(g + 8) == 0, *(int*)(g + 8) != 0, g + 0x330, g + 0x3DC);
        break;
    }
    default:
        return func_001BF228(self, msg);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5240);
#ifdef SKIP_ASM
extern "C" int func_001A9668(void* self, void* a1, int a2);
extern "C" int func_001BF6C0(void* self, void* a1, int a2);

extern "C" int func_001D5240(void* self, void* a1, int a2)
{
    int r;
    if (*(int*)((char*)a1 + 0x18) == 0x102) {
        r = func_001A9668(self, a1, a2);
    } else {
        r = func_001BF6C0(self, a1, a2);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5280);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" int func_0039F698(void* p);
extern "C" void* cUIStateStack_getCurrentState(void* self);
extern "C" void* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B3F78(void* mem, void* owner);
extern "C" void func_001A8A40(void* self, void* obj);
extern char D_00460BF0[];

extern "C" void func_001D5280(void* self, void* item, int msg)
{
    if (msg == 0xF || msg == 0x14) {
        func_001A97B8(self, item, msg);
        func_0039F698((char*)*(void**)((char*)self + 0x10) + 0x18);
        void* state = cUIStateStack_getCurrentState((char*)*(void**)((char*)self + 0x10) + 0x18);
        *(int*)((char*)state + 0x1C) |= 0x80;
        func_002636F0(func_002591B8(), 0);
        func_001A8A40(self, func_001B3F78(cMemMan_alloc(0x91C, D_00460BF0, 0, 0), *(void**)((char*)self + 0x10)));
    } else {
        func_001A97B8(self, item, msg);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5330);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern "C" void func_001D5488(void* self, int a1);
extern void* D_00474E08[];
extern void* D_0046C980[];
extern unsigned short D_004A1390[];

extern "C" void* func_001D5330(void* self, int a1, int a2, int a3)
{
    func_0039E2A0(self);
    *(int*)((char*)self + 0x98) = a3;
    *(void***)((char*)self + 0x8) = D_00474E08;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(unsigned short*)((char*)self + 0x58) = D_004A1390[0];
    *(void***)((char*)self + 0x8) = D_0046C980;
    func_001D5488(self, a2);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D53B0);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self);
extern "C" void func_001D5488(void* self, int a1);
extern void* D_00474E08[];
extern void* D_0046C980[];
extern unsigned short D_004A1390[];

extern "C" void* func_001D53B0(void* self, int a1, int a2)
{
    func_0039E2A0(self);
    *(int*)((char*)self + 0x98) = 0;
    *(void***)((char*)self + 0x8) = D_00474E08;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(unsigned short*)((char*)self + 0x58) = D_004A1390[0];
    *(void***)((char*)self + 0x8) = D_0046C980;
    func_001D5488(self, a2);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5428);
#ifdef SKIP_ASM
extern void* D_0046C980[];
extern void* D_00474E08[];
extern void* D_004A2028;
extern "C" void func_0039E390(void* self, int flags);

extern "C" void func_001D5428(void* self, int flags)
{
    *(void***)((char*)self + 8) = D_0046C980;
    D_004A2028 = 0;
    *(void***)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5460);
#ifdef SKIP_ASM
// Key filter: keys 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001D5460(void* self, int a1, unsigned int key)
{
    int r = 0x101;
    if (key < 10) {
        if (key < 8) {
            r = 0x101;
        } else {
            return 0x100;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5488);
#ifdef SKIP_ASM
extern "C" void* func_00227F80(void* app);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_00152948__FPv ignores its argument; this caller passes none.
int func_00152948_r() __asm__("func_00152948__FPv");
extern "C" int func_00152BA8();
// PORT: func_0023CC58__FPv really takes a second argument.
void func_0023CC58_2(void* app, int n) __asm__("func_0023CC58__FPv");
extern "C" void func_0023CAA0(void* app, int n);
extern "C" void func_0023C8F0(void* app, int mode);
extern "C" void func_0023D5A8(void* app);
extern "C" void func_00241D40(void* app, int a, char* buf, int n);
extern "C" void func_00241AA0(char* buf, int n);
extern "C" void func_002C2540(char* buf, char* s);
extern "C" void func_002C26D0(void* dst, char* a, char* b, char* c);
extern void* D_004A28A8;
extern void* D_004A2028;
extern char D_004A14C8[];
// PORT: callback function addresses taken through asm-label views (their real prototypes vary).
extern char func_001D59A0_a5488[] __asm__("func_001D59A0");
extern char func_001D5D78_a5488[] __asm__("func_001D5D78");
extern char func_001D5F38_a5488[] __asm__("func_001D5F38__FPv");
extern char cFEMemCard_callbackSaveSuccess_a5488[] __asm__("cFEMemCard_callbackSaveSuccess");
extern char func_001D6C28_a5488[] __asm__("func_001D6C28");
extern char func_001D5DF0_a5488[] __asm__("func_001D5DF0");
extern char func_001D5C28_a5488[] __asm__("func_001D5C28");
extern char func_001D5F40_a5488[] __asm__("func_001D5F40");
extern char func_001D6AD0_a5488[] __asm__("func_001D6AD0");
extern char cFEMemCard_callbackReadSuccess_a5488[] __asm__("cFEMemCard_callbackReadSuccess");
extern char cFEMemCard_callbackDeleteDone_a5488[] __asm__("cFEMemCard_callbackDeleteDone");
extern char func_001D8020_a5488[] __asm__("func_001D8020");
extern char func_001D72A8_a5488[] __asm__("func_001D72A8");
extern char func_001D6D88_a5488[] __asm__("func_001D6D88");
extern char func_001D7010_a5488[] __asm__("func_001D7010");
extern char func_001D68E8_a5488[] __asm__("func_001D68E8");
extern char func_001D7318_a5488[] __asm__("func_001D7318");
extern char func_001D7548_a5488[] __asm__("func_001D7548");
extern char cFEMemCard_callbackConfirmFormatDone_a5488[] __asm__("cFEMemCard_callbackConfirmFormatDone");
extern char cFEMemCard_callbackConfirmDelete_a5488[] __asm__("cFEMemCard_callbackConfirmDelete");
extern char func_001D77E8_a5488[] __asm__("func_001D77E8");
extern char func_001D7B18_a5488[] __asm__("func_001D7B18");
extern char func_001D7998_a5488[] __asm__("func_001D7998");
extern char func_001DDD28_a5488[] __asm__("func_001DDD28");
extern char func_001DDD48_a5488[] __asm__("func_001DDD48");
extern char func_001DDD58_a5488[] __asm__("func_001DDD58");
extern char func_001DDD68_a5488[] __asm__("func_001DDD68");
extern char func_001DDD78_a5488[] __asm__("func_001DDD78");
extern char func_001DDD38_a5488[] __asm__("func_001DDD38");
extern char func_001DDD88_a5488[] __asm__("func_001DDD88");
extern char func_001DDD98_a5488[] __asm__("func_001DDD98");
extern char func_001DDDB8_a5488[] __asm__("func_001DDDB8");
extern char func_001DDDA8_a5488[] __asm__("func_001DDDA8");
extern char func_001D7190_a5488[] __asm__("func_001D7190");
extern char func_001D8160_a5488[] __asm__("func_001D8160");
extern char func_001D83A8_a5488[] __asm__("func_001D83A8");
extern char func_001D8358_a5488[] __asm__("func_001D8358");
extern char func_001D8240_a5488[] __asm__("func_001D8240");
extern char cFEMemCard_callbackFileExists_a5488[] __asm__("cFEMemCard_callbackFileExists");
extern char func_001D7D70_a5488[] __asm__("func_001D7D70");

extern "C" void func_001D5488(void* self_, int mode)
{
    char* self = (char*)self_;
    void* gapp = D_004A28A8;
    D_004A2028 = self;
    *(int*)(self + 0x1C0) = 0;
    *(int*)(self + 0x214) = 0;
    char* app = (char*)func_00227F80(gapp);
    *(void**)(app + 0x0) = func_001D59A0_a5488;
    *(void**)(app + 0x18) = func_001D5DF0_a5488;
    *(void**)(app + 0x8) = func_001D5F38_a5488;
    *(void**)(app + 0x20) = func_001D5F40_a5488;
    *(void**)(app + 0x6C) = func_001DDD58_a5488;
    *(void**)(app + 0x68) = func_001DDD48_a5488;
    *(void**)(app + 0x64) = func_001DDD28_a5488;
    *(void**)(app + 0x70) = func_001DDD68_a5488;
    *(void**)(app + 0x74) = func_001DDD78_a5488;
    *(void**)(app + 0x78) = func_001DDD38_a5488;
    *(void**)(app + 0x7C) = func_001DDD88_a5488;
    *(void**)(app + 0x80) = func_001DDD98_a5488;
    *(void**)(app + 0x84) = func_001DDDB8_a5488;
    *(void**)(app + 0x4) = func_001D5D78_a5488;
    *(void**)(app + 0x44) = func_001D68E8_a5488;
    *(void**)(app + 0x40) = func_001D7010_a5488;
    *(void**)(app + 0x1C) = func_001D5C28_a5488;
    *(void**)(app + 0x88) = func_001DDDA8_a5488;
    *(void**)(app + 0x48) = func_001D7318_a5488;
    *(void**)(app + 0x50) = cFEMemCard_callbackConfirmFormatDone_a5488;
    *(void**)(app + 0x4C) = func_001D7548_a5488;
    *(void**)(app + 0x54) = cFEMemCard_callbackConfirmDelete_a5488;
    *(void**)(app + 0x38) = func_001D72A8_a5488;
    *(void**)(app + 0x28) = cFEMemCard_callbackReadSuccess_a5488;
    *(void**)(app + 0x24) = func_001D6AD0_a5488;
    *(void**)(app + 0x3C) = func_001D6D88_a5488;
    *(void**)(app + 0x58) = func_001D77E8_a5488;
    *(void**)(app + 0x10) = func_001D6C28_a5488;
    *(void**)(app + 0xC) = cFEMemCard_callbackSaveSuccess_a5488;
    *(void**)(app + 0x60) = func_001D7998_a5488;
    *(void**)(app + 0x30) = cFEMemCard_callbackDeleteDone_a5488;
    *(void**)(app + 0x34) = func_001D8020_a5488;
    *(void**)(app + 0x8C) = func_001D7190_a5488;
    *(void**)(app + 0x90) = func_001D8160_a5488;
    *(void**)(app + 0x94) = func_001D83A8_a5488;
    *(void**)(app + 0x98) = func_001D8358_a5488;
    *(void**)(app + 0x9C) = func_001D8240_a5488;
    *(void**)(app + 0x5C) = func_001D7B18_a5488;
    *(void**)(app + 0xA0) = cFEMemCard_callbackFileExists_a5488;
    *(void**)(app + 0xA8) = func_001D7D70_a5488;
    *(int*)(self + 0x19C) = 0x19;
    *(int*)(self + 0x1BC) = mode;
    *(int*)(self + 0x1A8) = 0;
    *(int*)(self + 0x1AC) = 0;
    *(int*)(self + 0x1B0) = 0;
    *(int*)(self + 0x1B4) = 0;
    *(int*)(self + 0x1B8) = 0;
    *(int*)(self + 0x1C4) = 0;
    *(int*)(self + 0x1CC) = 0;
    *(int*)(self + 0x1D8) = 0;
    *(int*)(self + 0x1DC) = 0;
    *(int*)(self + 0x1E0) = 0;
    *(int*)(self + 0x1E4) = 0;
    *(int*)(self + 0x1E8) = 0;
    *(int*)(self + 0x1EC) = 0;
    *(int*)(self + 0x1F0) = 0;
    *(int*)(self + 0x1F4) = 0;
    *(int*)(self + 0x1F8) = 0;
    *(int*)(self + 0x1FC) = 0;
    *(int*)(self + 0x200) = 0;
    *(int*)(self + 0x204) = 0;
    *(int*)(self + 0x208) = 0;
    *(int*)(self + 0x20C) = 0;
    *(int*)(self + 0x210) = 0;
    *(int*)(self + 0x218) = 0;
    *(int*)(self + 0x21C) = 0;
    *(int*)(self + 0x1A0) = 0;
    *(int*)(self + 0x1A4) = 0;
    *(int*)(self + 0x220) = 0;
    *(int*)(self + 0x224) = 0;
    *(int*)(self + 0x228) = 0;
    *(int*)(self + 0x1D4) = 0;
    *(int*)(self + 0x1D0) = 0;
    *(int*)(self + 0x1C8) = 0;
    *(short*)(self + 0x9C) = 0;
    func_0023D5A8(app);
    cBE_getInterface_Fv(cBE_getBE(), 5);
    if (*(int*)(self + 0x1BC) == 2)
    {
        int n = func_00152948_r();
        func_0023CC58_2(app, n);
        func_0023CAA0(app, n);
        func_0023C8F0(app, 2);
    }
    else if (*(int*)(self + 0x1BC) == 1)
    {
        func_0023CC58_2(app, 0x80000);
        func_0023CAA0(app, 0x80000);
        func_0023C8F0(app, 0);
    }
    else
    {
        int n = func_00152BA8();
        func_0023CC58_2(app, n);
        func_0023CAA0(app, n);
        func_0023C8F0(app, 1);
    }
    char b0[0x200];
    char b1[0x200];
    char b2[0x200];
    func_00241D40(app, *(int*)(app + 0xB4), b0, 0x100);
    func_002C2540(b2, D_004A14C8);
    func_00241AA0(b1, 0x100);
    func_002C26D0(self + 0x11C, b2, b1, b0);
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D58B8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
void cMemMan_free(void* p);
extern "C" void func_00152700(void* iface);
extern "C" void func_00152728(void* iface);
extern "C" void func_0020A430(void* self);
extern "C" void* func_00227F80(void* app);
extern "C" void func_0023C860(void* self);
extern "C" void func_0023D5E8(void* self);
extern "C" void func_002410A0(void* self);

extern "C" void func_001D58B8(void* self)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 5);
    if (*(int*)((char*)self + 0x1BC) == 1 && *(int*)((char*)self + 0x228) == 2 && *(int*)((char*)self + 0x1B4) == 0) {
        func_00152728(iface);
        *(int*)((char*)self + 0x1D4) = 0;
        *(int*)((char*)self + 0x1D0) = 0;
        *(int*)((char*)self + 0x228) = 0;
    }
    func_00152700(iface);
    char* app = (char*)func_00227F80(D_004A28A8);
    if (*(int*)(app + 0x434) != 0) {
        func_002410A0(app);
        func_0023D5E8(app);
        func_0023C860(app);
    }
    if (*(int*)((char*)self + 0x228) == 1) {
        *(int*)((char*)self + 0x228) = 0;
        if (*(void**)((char*)self + 0x1D4) != 0) {
            cMemMan_free(*(void**)((char*)self + 0x1D4));
        }
        *(int*)((char*)self + 0x1D4) = 0;
        *(int*)((char*)self + 0x1D0) = 0;
    }
    func_0020A430(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D59A0);
#ifdef SKIP_ASM
extern "C" void* func_00227F80(void* app);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_002412A0(void* app);
extern "C" void func_00270E68(void* p);
extern "C" int func_0014E048(void* be);
extern "C" void cFEMemCard_createReadBuffer_59A0(void* self, int size) __asm__("cFEMemCard_createReadBuffer");
extern "C" void func_0014E050(void* be, int a);
extern "C" int func_00152950(void* iface, int a);
extern "C" int func_00152BA8();
extern "C" void func_00241D40(void* app, int a, char* buf, int n);
extern "C" void func_00241AA0(char* buf, int n);
// PORT: the unit declares func_002C2540 as void; it returns dst (bound by asm label so the call is a call_value).
extern "C" unsigned short* func_002C2540_59A0(char* buf, const char* s) __asm__("func_002C2540");
extern "C" void func_002C26D0_59A0(char* dst, char* fmt, char* a, char* b, int n) __asm__("func_002C26D0");
extern "C" void func_00241000(void* app, char* name, int a, int b);
extern "C" void func_00241E18(void* app, char* buf, int n);
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void cMemMan_free(void* p);
extern void* D_004A28A8;
extern void* D_004A2028;
extern char D_004677A8[];
extern char D_0045E2A0[];

struct sVE_59A0 {
    short delta;
    short index;
    void (*fn)(void*, char*, int, int, int, int, int);
};

// Memory-card "save" step: builds the save-file title for the current mode and starts the save; on first entry shows the saving dialog.
extern "C" void func_001D59A0(void)
{
    char name[0x90];
    char title[0x90];
    char slot[0x200];
    char fmt1[0x200];
    char fmt2[0x200];
    char* app = (char*)func_00227F80(D_004A28A8);
    int mode = *(int*)((char*)D_004A2028 + 0x1BC);
    if (mode == 2) {
        func_002412A0(app);
    } else if (mode == 1) {
        void* replay = *(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
        *(int*)((char*)D_004A2028 + 0x1C8) = mode;
        func_00270E68(replay);
        int size = func_0014E048(cBE_getBE());
        cFEMemCard_createReadBuffer_59A0(D_004A2028, size);
        func_0014E050(cBE_getBE(), *(int*)((char*)D_004A2028 + 0x1D4));
        func_00241D40(app, 0, name, 0x41);
        func_002C2540_59A0(fmt1, D_004677A8);
        func_00241AA0(slot, 0x100);
        func_002C26D0_59A0(title, fmt1, slot, name, *(int*)(app + 0xF8) + 1);
        func_00241000(app, title, *(int*)((char*)D_004A2028 + 0x1D4), size);
    } else {
        char* app2 = (char*)func_00227F80(D_004A28A8);
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 5);
        int a = func_00152950(iface, *(int*)((char*)D_004A2028 + 0x1CC));
        int b = func_00152BA8();
        func_00241D40(app2, 1, name, 0x41);
        func_002C2540_59A0(fmt2, D_004677A8);
        func_00241AA0(slot, 0x100);
        func_002C26D0_59A0(title, fmt2, slot, name, *(int*)(app2 + 0xF8) + 1);
        func_00241000(app2, title, a, b);
    }
    char* fe = (char*)D_004A2028;
    if (*(int*)(fe + 0x210) == 0 && *(int*)(fe + 0x208) == 0) {
        *(int*)(fe + 0x19C) = 0x16;
        char* buf = (char*)operator_new_tag(0x640, D_0045E2A0, 0x100, 0);
        func_00241E18(app, buf, 0x320);
        sVE_59A0* vt = *(sVE_59A0**)((char*)D_004A2028 + 8);
        vt[36].fn((char*)D_004A2028 + vt[36].delta, buf, 1, 1, 0, 0, 1);
        *(int*)((char*)D_004A2028 + 0x210) = 1;
        if (buf != 0) {
            cMemMan_free(buf);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5C28);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern int D_004A19B8;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00152728(void* iface);
extern "C" void* func_00227F80(void* app);
extern "C" int func_0014E048(void* be);
void* func_0014E0C0(void* self, int a1);
extern "C" void func_00241200(void* self, char* a, int n);
extern "C" int func_003E62D0(void* buf, int size, int seed);
extern "C" void* memcpy(void*, const void*, unsigned int);

struct sTrophyRoom_001D5C28 {
    char pad0[0x1BC];
    int mode;           // 0x1BC
    char pad1C0[0x10];
    char* cur;          // 0x1D0
    void* buf;          // 0x1D4
    char pad1D8[0x28];
    int pending;        // 0x200
    char pad204[0x24];
    int state;          // 0x228
};
// PORT: D_004A2028 holds the trophy room state pointer.
extern sTrophyRoom_001D5C28* D_004A2028_tr __asm__("D_004A2028");

extern "C" int func_001D5C28(int size)
{
    sTrophyRoom_001D5C28* g = D_004A2028_tr;
    int mode = g->mode;
    if (mode != 1) {
        return 1;
    }
    if (g->pending != 0) {
        g->pending = 0;
        char* base = g->cur;
        int crc = func_003E62D0(g->cur, func_0014E048(cBE_getBE()) - 4, 0xFBEA);
        D_004A2028_tr->cur += func_0014E048(cBE_getBE()) - 4;
        int stored = 0;
        memcpy(&stored, D_004A2028_tr->cur, 4);
        D_004A2028_tr->cur += 4;
        if (crc != stored) {
            func_00152728(cBE_getInterface_Fv(cBE_getBE(), 5));
            D_004A2028_tr->buf = 0;
            D_004A2028_tr->cur = 0;
            D_004A2028_tr->state = 0;
            return 0;
        }
        D_004A19B8 = mode;
        func_0014E0C0(cBE_getBE(), (int)base);
    }
    if (size > 0) {
        if (size > 0x4000) {
            size = 0x4000;
        }
        func_00241200(func_00227F80(D_004A28A8), D_004A2028_tr->cur, size);
        D_004A2028_tr->cur += size;
    }
    return 1;
}
#endif

INCLUDE_ASM("fe/festatetrophyroom", func_001D5D78);

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5DF0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00227F80(void* app);
extern "C" int func_0014E048(void* be);
// PORT: func_00152948__FPv ignores its argument; this caller passes none.
int func_00152948_r() __asm__("func_00152948__FPv");
extern "C" int func_00152BA8();
extern "C" void func_0023CA28(void* self, int a, int b, int c);

struct sMoviePlayer_001D5DF0 {
    char pad0[0xF8];
    int fF8;            // 0xF8
};

struct sTrophyRoom_001D5DF0 {
    char pad0[0x1B0];
    int f1B0;           // 0x1B0
    int f1B4;           // 0x1B4
    char pad1B8[0x4];
    int mode;           // 0x1BC
    char pad1C0[0x4];
    int size;           // 0x1C4
    char pad1C8[0x8];
    int cur;            // 0x1D0
    int buf;            // 0x1D4
    char pad1D8[0x28];
    int pending;        // 0x200
    char pad204[0x24];
    int state;          // 0x228
};
// PORT: D_004A2028 holds the trophy room state pointer.
extern sTrophyRoom_001D5DF0* D_004A2028_tr5 __asm__("D_004A2028");
extern "C" int func_00152688(void* iface);
extern "C" void cFEMemCard_createReadBuffer(sTrophyRoom_001D5DF0* self, int size);

extern "C" void func_001D5DF0()
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 5);
    sMoviePlayer_001D5DF0* app = (sMoviePlayer_001D5DF0*)func_00227F80(D_004A28A8);
    sTrophyRoom_001D5DF0* g = D_004A2028_tr5;
    g->f1B0 = 1;
    g->f1B4 = 0;
    app->fF8 = g->size;
    int mode = g->mode;
    switch (mode) {
    case 2: {
        int n = func_00152948_r();
        cFEMemCard_createReadBuffer(D_004A2028_tr5, n);
        func_0023CA28(app, D_004A2028_tr5->size, D_004A2028_tr5->cur, n);
        break;
    }
    case 1: {
        D_004A2028_tr5->state = 2;
        int b = func_00152688(iface);
        sTrophyRoom_001D5DF0* t = D_004A2028_tr5;
        t->buf = t->cur = b;
        func_0023CA28(app, t->size, t->cur, func_0014E048(cBE_getBE()));
        D_004A2028_tr5->pending = mode;
        break;
    }
    case 0: {
        int n = func_00152BA8();
        cFEMemCard_createReadBuffer(D_004A2028_tr5, n);
        func_0023CA28(app, D_004A2028_tr5->size, D_004A2028_tr5->cur, n);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5F38__FPv);
#ifdef SKIP_ASM
void func_001D5F38(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D5F40);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" int func_00152BB0(void* self, char* buf);
extern "C" int func_00152DE0(void* self, char* buf, int idx);
extern "C" void func_001D64C0(unsigned int mode);
extern "C" void func_00287410(void* opt, int v);
extern "C" void func_00287488(void* opt, int v);
extern "C" void func_00287520(void* opt, int v);
extern "C" void func_00287558(void* opt, int v);
extern "C" void func_002875D0(void* opt, int v);
void cMemMan_free(void*);
extern void* D_004A2028;

struct sSndCfg_1D5F40 {
    unsigned int sfxVol : 4;        // bits 0-3
    unsigned int musicVol : 4;      // bits 4-7
    unsigned int speechVol : 4;     // bits 8-11
    unsigned int output : 2;        // bits 12-13
    unsigned int pad14 : 2;
    int f16 : 1;                    // bit 16
    int f17 : 1;                    // bit 17
    int pad18 : 14;
    char rest[0x288 - 4];
};
// PORT: D_00535610 is viewed with different types across the program; view bound by asm label
extern sSndCfg_1D5F40 D_00535610_1D5F40 __asm__("D_00535610");

static inline sSndCfg_1D5F40 Cfg_1D5F40()
{
    return D_00535610_1D5F40;
}

struct sMemCard_1D5F40 {
    char pad0[0x1BC];
    int op;                         // 0x1BC
    char pad1C0[0x1CC - 0x1C0];
    int slot;                       // 0x1CC
    char* buf;                      // 0x1D0
    char* data;                     // 0x1D4
    char pad1D8[0x228 - 0x1D8];
    int busy;                       // 0x228
};

// Memory-card load/save step: applies the loaded sound options, then frees the transfer buffer.
extern "C" int func_001D5F40()
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 5);
    switch (((sMemCard_1D5F40*)D_004A2028)->op) {
    case 2:
        if (!func_00152BB0(iface, ((sMemCard_1D5F40*)D_004A2028)->buf))
            return 0;
        if (func_0028B180() != 0) {
            cBE_getInterface_Fv(cBE_getBE(), 4);
            func_001D64C0(Cfg_1D5F40().output);
            func_00287410(func_0028B180(), Cfg_1D5F40().sfxVol);
            func_00287488(func_0028B180(), Cfg_1D5F40().speechVol);
            func_00287520(func_0028B180(), Cfg_1D5F40().musicVol);
            func_00287558(func_0028B180(), Cfg_1D5F40().f17 != 0);
            func_002875D0(func_0028B180(), Cfg_1D5F40().f16 != 0);
        }
        break;
    case 0:
        if (!func_00152DE0(iface, ((sMemCard_1D5F40*)D_004A2028)->buf, ((sMemCard_1D5F40*)D_004A2028)->slot))
            return 0;
        break;
    case 1:
        break;
    }
    if (((sMemCard_1D5F40*)D_004A2028)->busy == 1) {
        if (((sMemCard_1D5F40*)D_004A2028)->data != 0)
            cMemMan_free(((sMemCard_1D5F40*)D_004A2028)->data);
        ((sMemCard_1D5F40*)D_004A2028)->buf = 0;
        ((sMemCard_1D5F40*)D_004A2028)->data = 0;
        ((sMemCard_1D5F40*)D_004A2028)->busy = 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/festatetrophyroom", func_001D64C0);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" int func_00287670(void* opt);
extern "C" int func_002876A0(void* opt);
extern "C" int func_002876D0(void* opt);
extern "C" void func_00286200(void* opt);
extern "C" void func_00284C28();
extern "C" void SSXAUDIO_Init(int lang);
extern "C" void func_00287410(void* opt, int v);
extern "C" void func_00287488(void* opt, int v);
extern "C" void func_00287520(void* opt, int v);
extern "C" void func_00287558(void* opt, int v);
extern "C" void func_002875D0(void* opt, int v);
extern "C" void func_00285FB0(void* opt);

struct sLang_001D64C0 {
    int f0;
    virtual void v01();
    virtual int v02(int lang);
};
struct sLangHolder_001D64C0 {
    char pad0[0x1D8];
    sLang_001D64C0* lang;   // 0x1D8
};
struct sOptSub_001D64C0 {
    sLangHolder_001D64C0** holder;  // 0x0
    char pad4[0x543C];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(int v);
};
struct sOptBase_001D64C0 {
    char pad0[0x118];
};
struct sOpt_001D64C0 : sOptBase_001D64C0, sOptSub_001D64C0 {
};

extern "C" void func_001D64C0(unsigned int mode)
{
    int lang;
    switch (mode) {
    case 1:
        lang = 2;
        break;
    case 2:
        lang = 0;
        break;
    case 3:
        lang = 3;
        break;
    case 0:
    default:
        lang = 1;
        break;
    }
    if ((*((sOpt_001D64C0*)func_0028B180())->holder)->lang->v02(lang) == 1) {
        float a = func_00287670(func_0028B180());
        float b = func_002876A0(func_0028B180());
        float c = func_002876D0(func_0028B180());
        int x = *(int*)((char*)func_0028B180() + 0x62B8);
        int y = *(int*)((char*)func_0028B180() + 0x62B4);
        int z = *(int*)((char*)func_0028B180() + 0x534);
        func_00286200(func_0028B180());
        func_00284C28();
        SSXAUDIO_Init(lang);
        func_00287410(func_0028B180(), (int)a);
        func_00287488(func_0028B180(), (int)b);
        func_00287520(func_0028B180(), (int)c);
        func_00287558(func_0028B180(), x);
        func_002875D0(func_0028B180(), y);
        func_00285FB0(func_0028B180());
        sOpt_001D64C0* o = (sOpt_001D64C0*)func_0028B180();
        o->v04(z);
    }
}
#endif

