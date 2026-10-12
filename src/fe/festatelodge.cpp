#include "common.h"

//100%
INCLUDE_ASM("fe/festatelodge", cFEStateLodge_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A2318[];
extern int D_00441B14[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_001474C8(void* iface, int player);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* self, int a1);

extern "C" void cFEStateLodge_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A2318), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    *(int*)((char*)self + 0x48) = func_001474C8(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)((char*)self + 0x44));
    D_00441B14[0] = 0;
    func_0028F140(func_0028B180(), 1);
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0x12;
    *(int*)((char*)self + 0x54) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", cFEStateLodge_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00146D98(void* iface, int a1);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_0046EDC0[];
extern char D_0046EDD0[];
extern char D_0046EDE0[];
extern char D_0046EDF0[];
extern char D_0046EE00[];
extern char D_0046EE10[];
extern char D_0046EE20[];
extern char D_0046EE30[];
extern char D_0046EE40[];
extern char D_0046EE50[];
extern char D_0046EE60[];
extern char D_0046EE78[];
extern char D_0046EE90[];

struct sWVt_3840 { short delta; short index; void (*fn)(void*, int); };

extern "C" void cFEStateLodge_onWidgetCreate(void* self, void* w)
{
    int h = *(int*)((char*)w + 0x38);
    if (h == GetHashValue32(D_0046EDC0)) {
        *(int*)((char*)w + 0x18) = 0;
    } else if (h == GetHashValue32(D_0046EDD0)) {
        *(int*)((char*)w + 0x18) = 1;
    } else if (h == GetHashValue32(D_0046EDE0)) {
        *(int*)((char*)w + 0x18) = 2;
    } else if (h == GetHashValue32(D_0046EDF0)) {
        *(int*)((char*)w + 0x18) = 3;
    } else if (h == GetHashValue32(D_0046EE00)) {
        *(int*)((char*)w + 0x18) = 4;
    } else if (h == GetHashValue32(D_0046EE10)) {
        *(int*)((char*)w + 0x18) = 5;
    } else if (h == GetHashValue32(D_0046EE20)) {
        *(int*)((char*)w + 0x18) = 8;
    } else if (h == GetHashValue32(D_0046EE30)) {
        *(int*)((char*)w + 0x18) = 6;
    } else if (h == GetHashValue32(D_0046EE40)) {
        *(int*)((char*)w + 0x18) = 7;
        sWVt_3840* vt = *(sWVt_3840**)((char*)w + 8);
        vt[8].fn((char*)w + vt[8].delta, 1);
        vt = *(sWVt_3840**)((char*)w + 8);
        vt[9].fn((char*)w + vt[9].delta, 0);
    } else if (h == GetHashValue32(D_0046EE50)) {
        int lvl = func_00146D98(cBE_getInterface_Fv(cBE_getBE(), 1), 0);
        if (lvl >= 17) {
            if (lvl < 19) {
                cUIText_setUnicodeStringByID((cUIText*)w, GetHashValue32(D_0046EE60));
                return;
            }
            if (lvl < 21) {
                cUIText_setUnicodeStringByID((cUIText*)w, GetHashValue32(D_0046EE78));
                return;
            }
        }
        cUIText_setUnicodeStringByID((cUIText*)w, GetHashValue32(D_0046EE90));
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", func_001F3A38);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001D99C8(void* self, void* engine, void* owner, unsigned short* text, int a4, int a5, int a6, int a7, int a8);
extern "C" void* func_0018ECA0(void* self, void* engine, int a2, unsigned char mask);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* screen, int hash);
extern void* D_004A28A8;
extern int D_00441AF8[];
extern char D_0046EEA8[];
extern char D_0046EEC0[];
extern char D_0046EED0[];
extern char D_0046EEF0[];
extern char D_0046E050[];

struct sVE_1F3A38s {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

struct sVE_1F3A38p {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

extern "C" void func_001F3A38(char* self, char* w, int event)
{
    if (w == 0) {
        return;
    }
    if (event != 5) {
        return;
    }
    if (D_00441AF8[*(int*)(w + 0x18)] == 0) {
        return;
    }
    cBE_getInterface_Fv(cBE_getBE(), 4);
    if (*(int*)(w + 0x18) == 0 && *(int*)(self + 0x4C) == 0) {
        char* mgr = *(char**)((char*)D_004A28A8 + 0x8C);
        sVE_1F3A38s* vt = *(sVE_1F3A38s**)(mgr + 4);
        unsigned short* text = vt[4].fn(mgr + vt[4].delta, GetHashValue32(D_0046EEA8));
        void* p = cMemMan_alloc(0xBFC, D_0046EEC0, 0x100, 0);
        void* o = func_001D99C8(p, *(void**)(self + 0x10), self, text, 0, 0, 0, 0, 0);
        *(int*)(self + 0x50) = 0x10;
        func_0039F290(*(char**)(self + 0x10) + 0x18, o);
        return;
    }
    int k = *(int*)(w + 0x18);
    if (k == 6 && *(int*)(self + 0x4C) == 0) {
        char* mgr = *(char**)((char*)D_004A28A8 + 0x8C);
        sVE_1F3A38s* vt = *(sVE_1F3A38s**)(mgr + 4);
        unsigned short* text = vt[4].fn(mgr + vt[4].delta, GetHashValue32(D_0046EED0));
        void* p = cMemMan_alloc(0xBFC, D_0046EEC0, 0x100, 0);
        void* o = func_001D99C8(p, *(void**)(self + 0x10), self, text, 0, 0, 0, 0, 0);
        *(int*)(self + 0x50) = k;
        func_0039F290(*(char**)(self + 0x10) + 0x18, o);
        return;
    }
    if (k == 8) {
        *(int*)(**(char***)(self + 0x10) + 0xC) = 0x27;
        void* p = cMemMan_alloc(0x280, D_0046EEF0, 0, 0);
        void* o = func_0018ECA0(p, *(void**)(self + 0x10), 3, 1 << *(signed char*)(self + 0x14));
        func_0039F400(*(char**)(self + 0x10) + 0x18, o);
        return;
    }
    cUIScreen_playFrame(*(void**)(self + 0x40), cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_0046E050)), 1);
    char* obj = **(char***)(self + 0x10);
    sVE_1F3A38p* vt = *(sVE_1F3A38p**)(obj + 4);
    void* r = vt[4].fn(obj + vt[4].delta, self, *(int*)(w + 0x18));
    if (r != 0) {
        func_0039F400(*(char**)(self + 0x10) + 0x18, r);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", func_001F3CC8);
#ifdef SKIP_ASM
// Key filter: keys 7, 8 and 9 return 0x100, every other key 0x101.
extern "C" int func_001F3CC8(void* self, int a1, unsigned int key)
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
INCLUDE_ASM("fe/festatelodge", func_001F3CF0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001D99C8(void* self, void* engine, void* owner, unsigned short* text, int a4, int a5, int a6, int a7, int a8);
extern "C" void* func_0018ECA0(void* self, void* engine, int a2, unsigned char mask);
extern "C" void func_0039F190(void* list, int a1);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F4C0(void* list, void* item);
extern "C" void cUIStateStack_pushSpecial(void* list, void* item, int a2, int a3);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* screen, int hash);
extern void* D_004A28A8;
extern char D_0046EDC0[];
extern char D_0046E050[];
extern char D_0046EEC0[];
extern char D_0046EEF0[];
extern char D_0046EF08[];

struct sVE_1F3CF0s {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

struct sVE_1F3CF0p {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sVE_1F3CF0o {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001F3CF0(char* self, char* msg, unsigned int id)
{
    switch (id) {
    case 0xF:
        *(int*)(self + 0x54) = 1;
        if (*(int*)(self + 0x50) == 6 || *(int*)(self + 0x50) == 0x10 || *(int*)(self + 0x50) == 0x11) {
            func_0039F190(*(char**)(self + 0x10) + 0x18, 1);
        }
        break;
    case 0x10:
        *(int*)(self + 0x54) = 0;
        func_0039F190(*(char**)(self + 0x10) + 0x18, 1);
        switch (*(int*)(self + 0x50)) {
        case 0x10: {
            *(int*)(self + 0x4C) = 1;
            sVE_1F3CF0o* vt = *(sVE_1F3CF0o**)(self + 8);
            vt[19].fn(self + vt[19].delta, cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_0046EDC0)), 5);
            break;
        }
        case 0x11: {
            *(int*)(self + 0x4C) = 1;
            cUIScreen_playFrame(*(void**)(self + 0x40), cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_0046E050)), 1);
            char* obj = **(char***)(self + 0x10);
            sVE_1F3CF0p* vt = *(sVE_1F3CF0p**)(obj + 4);
            void* r = vt[4].fn(obj + vt[4].delta, self, 6);
            if (r != 0) {
                func_0039F4C0(*(char**)(self + 0x10) + 0x18, r);
            }
            break;
        }
        }
        break;
    case 0x15:
        break;
    case 0x16:
        if (*(int*)(msg + 0xC) != 0) {
            break;
        }
        if (*(int*)(self + 0x54) == 0) {
            break;
        }
        switch (*(int*)(self + 0x50)) {
        case 0x10: {
            void* p = cMemMan_alloc(0x280, D_0046EEF0, 0x100, 0);
            char* o = (char*)func_0018ECA0(p, *(void**)(self + 0x10), 3, *(unsigned char*)(self + 0x15));
            *(int*)(o + 0x27C) = 1;
            *(int*)(o + 0x1C) = (*(int*)(o + 0x1C) & ~0x3F00) | 0x100;
            cUIStateStack_pushSpecial(*(char**)(self + 0x10) + 0x18, o, 0, 1);
            break;
        }
        case 0x11: {
            void* p = cMemMan_alloc(0x280, D_0046EEF0, 0x100, 0);
            char* o = (char*)func_0018ECA0(p, *(void**)(self + 0x10), 3, *(unsigned char*)(self + 0x15));
            *(int*)(o + 0x27C) = 2;
            *(int*)(o + 0x1C) = (*(int*)(o + 0x1C) & ~0x3F00) | 0x100;
            cUIStateStack_pushSpecial(*(char**)(self + 0x10) + 0x18, o, 0, 1);
            break;
        }
        case 6: {
            char* mgr = *(char**)((char*)D_004A28A8 + 0x8C);
            sVE_1F3CF0s* vt = *(sVE_1F3CF0s**)(mgr + 4);
            unsigned short* text = vt[4].fn(mgr + vt[4].delta, GetHashValue32(D_0046EF08));
            void* p = cMemMan_alloc(0xBFC, D_0046EEC0, 0x100, 0);
            void* o = func_001D99C8(p, *(void**)(self + 0x10), self, text, 0, 0, 0, 0, 0);
            *(int*)(self + 0x50) = 0x11;
            func_0039F290(*(char**)(self + 0x10) + 0x18, o);
            break;
        }
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", func_001F3FF8);
#ifdef SKIP_ASM
extern void* D_004739D8[];
extern "C" void* func_0039E2A0(void* self);
extern "C" unsigned char func_001A1CD0(void* self, int a1);

extern "C" void* func_001F3FF8(void* self)
{
    func_0039E2A0(self);
    *(void***)((char*)self + 0x8) = D_004739D8;
    *(int*)((char*)self + 0xC) = 0x28;
    *(char*)((char*)self + 0x44) = 0;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), 0);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", cFEStateLodgeRiderDetail_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_0046EF20[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int player);
extern "C" int func_001577A0(void* self, int a1, int a2);

extern "C" void cFEStateLodgeRiderDetail_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0046EF20), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    *(int*)((char*)self + 0x48) = 1;
    int charID = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)((char*)self + 0x44));
    if (func_001577A0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(signed char*)((char*)self + 0x44), charID) == 0) {
        *(int*)((char*)self + 0x48) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", func_001F4108);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00147138(void* self, int a1, const char* name);
extern "C" void func_001474A8(void* self, int a1, int a2);
extern "C" int strlen(const char* s);
extern char D_0046EF40[];

struct sVEntryK1F4108 {
    short delta;
    short index;
    void (*fn)(void*);
};

static inline int IsK1F4108(int id, char* s)
{
    return id == GetHashValue32(s);
}

static inline void commitK1F4108(void* np)
{
    sVEntryK1F4108* vt = *(sVEntryK1F4108**)((char*)np + 0xC);
    vt[1].fn((char*)np + vt[1].delta);
}

extern "C" void func_001F4108(void* self, char* popup, int event)
{
    void* np = cBE_getInterface_Fv(cBE_getBE(), 1);
    if (event != 0x16)
        return;
    if (IsK1F4108(*(int*)(popup + 0xC), D_0046EF40)) {
        int v = *(int*)(popup + 0x70);
        if (*(int*)(popup + 0x74) != 0) {
            void* np2 = cBE_getInterface_Fv(cBE_getBE(), 1);
            func_001474A8(np2, *(signed char*)((char*)self + 0x44), v);
            commitK1F4108(np2);
        }
    } else if (*(int*)(popup + 0xC) == 0) {
        if (*(int*)(popup + 0x5C) != 0) {
            char* name = popup + 0x74;
            if (strlen(name) != 0) {
                func_00147138(np, *(signed char*)((char*)self + 0x44), name);
                commitK1F4108(np);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", cFEStateLodgeRiderDetail_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getRiderCharID(void* self, int riderIndex);
extern "C" int func_00146E98(void* iface, int a1);
extern "C" void* func_0014EEC8(void* self, int player, int index);
struct cUIText;
void cUIText_setAsciiString(cUIText* text, const char* str);
extern char D_0046EF50[];
extern char D_0046EF60[];
extern char D_0046EF70[];
extern char D_0046EF80[];
extern char D_0046EF90[];
extern char D_0046EFA0[];
extern char D_0046EFB0[];
extern char D_0046EFC0[];

extern "C" void cFEStateLodgeRiderDetail_onWidgetCreate(void* self, void* w)
{
    int h = *(int*)((char*)w + 0x38);
    if (h == GetHashValue32(D_0046EF50)) {
        *(int*)((char*)w + 0x18) = 9;
    }     else if (h == GetHashValue32(D_0046EF60)) {
        *(int*)((char*)w + 0x18) = 10;
    }     else if (h == GetHashValue32(D_0046EF70)) {
        *(int*)((char*)w + 0x18) = 11;
    }     else if (h == GetHashValue32(D_0046EF80)) {
        *(int*)((char*)w + 0x18) = 12;
    }     else if (h == GetHashValue32(D_0046EF90)) {
        *(int*)((char*)w + 0x18) = 13;
    }     else if (h == GetHashValue32(D_0046EFA0)) {
        *(int*)((char*)w + 0x18) = 14;
    }     else if (h == GetHashValue32(D_0046EFB0)) {
        *(int*)((char*)w + 0x18) = 15;
    } else if (h == GetHashValue32(D_0046EFC0)) {
        void* np = cBE_getInterface_Fv(cBE_getBE(), 1);
        signed char cid = cBENewPlayerInterface_getRiderCharID(np, func_00146E98(np, 0));
        cUIText_setAsciiString((cUIText*)w, (const char*)func_0014EEC8(cBE_getInterface_Fv(cBE_getBE(), 2), cid, 0));
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatelodge", func_001F4380);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_00194498(void* obj);
extern char D_0046EF70[];

extern "C" void func_001F4380(void* self)
{
    if (*(int*)((char*)self + 0x48) == 0) {
        void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0046EF70));
        if (obj != 0) {
            func_00194498(obj);
        }
    }
}
#endif

INCLUDE_ASM("fe/festatelodge", func_001F43D8);

//100%
INCLUDE_ASM("fe/festatelodge", func_001F4400);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001CB030(void* self, void* engine, void* owner, int a3, unsigned char a4);
extern "C" void func_001CD088(void* self, int a1);
extern "C" void func_001CE3C8(void* self, int key, int a2, int a3);
extern "C" void func_001CE408(void* self, int a1);
extern "C" void func_001CB418(void* self, const char* str);
extern "C" const char* func_00147170(void* iface, int player);
extern "C" void* func_00182220(void* self, void* engine, void* owner, int player, int charID);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_0039F400(void* list, void* item);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" int func_001577A0(void* self, int a1, int a2);
int cBENewPlayerInterface_getPlayerCharID(void* self, int player);
struct cUIScreen;
int cUIScreen_getFrameByLabel(cUIScreen* screen, int hash);
extern int D_00441AF8[];
extern char D_0046EFD0[];
extern char D_0046EFE0[];
extern char D_0046E050[];

struct sVE_1F4400 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

extern "C" void func_001F4400(char* self, char* w, int event)
{
    if (w == 0) {
        return;
    }
    switch (event) {
    case 5: {
        int k = *(int*)(w + 0x18);
        if (D_00441AF8[k] == 0) {
            return;
        }
        if (k == 14) {
            void* p = cMemMan_alloc(0x444, D_0046EFD0, 0x100, 0);
            char* o = (char*)func_001CB030(p, *(void**)(self + 0x10), self, 0, *(unsigned char*)(self + 0x15));
            *(char*)(o + 0x44) = 0;
            *(int*)(o + 0x140) = 0x37;
            func_001CD088(o, 8);
            func_001CE3C8(o, 0x4B, 1, 2);
            *(int*)(o + 0x58) = 1;
            func_001CE408(o, 1);
            func_001CE3C8(o, 0xE, 0, 2);
            func_001CE3C8(o, 0x27, 0, 2);
            func_001CE3C8(o, 0x28, 0, 2);
            func_001CE3C8(o, 0x34, 0, 2);
            func_001CE3C8(o, 0x1A, 0, 2);
            func_001CE3C8(o, 0x19, 0, 2);
            func_001CE3C8(o, 0x35, 0, 2);
            func_001CE3C8(o, 0x40, 0, 2);
            func_001CE3C8(o, 0x41, 0, 2);
            func_001CE3C8(o, 0x42, 0, 2);
            func_0039F290(*(char**)(self + 0x10) + 0x18, o);
            func_001CB418(o, func_00147170(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)(self + 0x44)));
            return;
        }
        if (k == 11) {
            int id = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)(self + 0x44));
            if (func_001577A0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(signed char*)(self + 0x44), id) > 0) {
                void* p = cMemMan_alloc(0x1E4, D_0046EFE0, 0, 0);
                void* o = func_00182220(p, *(void**)(self + 0x10), self, *(signed char*)(self + 0x44), id);
                func_0039F290(*(char**)(self + 0x10) + 0x18, o);
            }
            return;
        }
        cUIScreen_playFrame(*(void**)(self + 0x40), cUIScreen_getFrameByLabel(*(cUIScreen**)(self + 0x40), GetHashValue32(D_0046E050)), 1);
        char* obj = **(char***)(self + 0x10);
        sVE_1F4400* vt = *(sVE_1F4400**)(obj + 4);
        void* r = vt[4].fn(obj + vt[4].delta, self, *(int*)(w + 0x18));
        if (r != 0) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        }
        break;
    }
    case 6: {
        char* obj = **(char***)(self + 0x10);
        sVE_1F4400* vt = *(sVE_1F4400**)(obj + 4);
        void* r = vt[5].fn(obj + vt[5].delta, self, 0);
        if (r != 0) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        }
        break;
    }
    }
}
#endif

INCLUDE_ASM("fe/festatelodge", func_001F4728);

