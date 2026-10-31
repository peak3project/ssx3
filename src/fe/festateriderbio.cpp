#include "common.h"

//100%
INCLUDE_ASM("fe/festateriderbio", cFEStateRiderDetail_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_00182DB8(void* self);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" void func_001A0570(void* self, int a1, int a2);
extern "C" void func_001A0508(void* self, int idx, int a2, int a3);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* self, int a1);
extern "C" int func_001577A0(void* self, int a1, int a2);
extern void* D_004A28A8;
extern char D_0045D870[];

struct sVE_32A8 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void cFEStateRiderDetail_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045D870), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_00182DB8(self);
    void* pi = cBE_getInterface_Fv(cBE_getBE(), 1);
    int charID = cBENewPlayerInterface_getPlayerCharID(pi, *(signed char*)((char*)self + 0x44));
    sVE_32A8* vt = *(sVE_32A8**)((char*)pi + 0xC);
    vt[2].fn((char*)pi + vt[2].delta);
    func_001A0570(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44), 0);
    func_001A0508(*(char**)((char*)D_004A28A8 + 0x7C) + 0xB0, *(signed char*)((char*)self + 0x44), charID, 0);
    func_0028F140(func_0028B180(), 1);
    *(int*)((char*)self + 0x50) = 1;
    if (func_001577A0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(signed char*)((char*)self + 0x44), charID) == 0) {
        *(int*)((char*)self + 0x50) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_001833D0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_00186518(void* self, int a1);
extern char D_0045D888[];
extern char D_0045D898[];
extern char D_0045D8A8[];
extern char D_0045D8B8[];
extern char D_0045D8C8[];

struct sVtEnt_001833D0 { short delta; short index; void (*fn)(void*, int); };

static inline void showObj_001833D0(void* self, char* name, int id)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    if (obj != 0) {
        sVtEnt_001833D0* vt = *(sVtEnt_001833D0**)((char*)obj + 8);
        vt[9].fn((char*)obj + vt[9].delta, 1);
        *(int*)((char*)obj + 0x18) = id;
    }
}

extern "C" void func_001833D0(void* self, int a1)
{
    showObj_001833D0(self, D_0045D888, 5);
    showObj_001833D0(self, D_0045D898, 6);
    showObj_001833D0(self, D_0045D8A8, 7);
    showObj_001833D0(self, D_0045D8B8, 8);
    showObj_001833D0(self, D_0045D8C8, 9);
    func_00186518(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_00183550);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_00194498(void* obj);
extern char D_0045D898[];

extern "C" void func_00183550(void* self)
{
    if (*(int*)((char*)self + 0x50) == 0) {
        void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D898));
        if (obj != 0) {
            func_00194498(obj);
        }
    }
}
#endif

extern "C" void func_0039E6B8(void* self);

//100%
INCLUDE_ASM("fe/festateriderbio", func_001835A8__FPv);
#ifdef SKIP_ASM
void func_001835A8(void* self)
{
    func_0039E6B8(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_001835C8);
#ifdef SKIP_ASM
extern "C" void func_0039E510(void*);
extern "C" void func_00182EC0(void*);

extern "C" void func_001835C8(void* self)
{
    func_0039E510(self);
    func_00182EC0(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_001835F8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00147138(void* self, int a1, const char* name);
extern "C" void func_001474A8(void* self, int a1, int a2);
extern "C" void func_001831D0(void* self, int a1);
extern "C" unsigned int strlen(const char* s);
extern char D_0045D780[];

struct sVE_35F8 {
    short delta;
    short index;
    void (*fn)(void*);
};

static inline int Is_001835F8(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void func_001835F8(void* self, void* item, int msg)
{
    void* pi = cBE_getInterface_Fv(cBE_getBE(), 1);
    if (msg == 0x16) {
        if (Is_001835F8(*(int*)((char*)item + 0xC), D_0045D780)) {
            int v = *(int*)((char*)item + 0x70);
            if (*(int*)((char*)item + 0x74) != 0) {
                void* pi2 = cBE_getInterface_Fv(cBE_getBE(), 1);
                func_001474A8(pi2, *(signed char*)((char*)self + 0x44), v);
                sVE_35F8* vt = *(sVE_35F8**)((char*)pi2 + 0xC);
                vt[1].fn((char*)pi2 + vt[1].delta);
            }
        } else if (*(int*)((char*)item + 0xC) == 0) {
            char* name = (char*)item + 0x74;
            if (*(int*)((char*)item + 0x5C) != 0 && strlen(name) != 0) {
                func_00147138(pi, *(signed char*)((char*)self + 0x44), name);
                sVE_35F8* vt = *(sVE_35F8**)((char*)pi + 0xC);
                vt[1].fn((char*)pi + vt[1].delta);
            }
        }
        func_001831D0(self, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_00183710);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void cUIStateStack_pushSpecial(void* stack, void* state, int a2, int a3);
extern "C" char* func_00147170(void* iface, int rider);
extern "C" int func_001577A0(void* self, int a1, int a2);
extern "C" void* func_00182220(void* mem, void* engine, void* owner, int rider, int cid);
extern "C" void func_001831D0(void* self, int a1);
extern "C" void* func_001887A0(void* mem, void* engine, int a2);
extern "C" unsigned char func_001A1CD0(void* self, int a1);
extern "C" void* func_001CB030(void* self, void* engine, void* owner, int a3, unsigned char a4);
extern "C" void func_001CB418(void* self, const char* str);
extern "C" void func_001CD088(void* self, int v);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_001CE408(void* self, int v);
extern "C" void func_0039F290(void* stack, void* state);
extern "C" void func_0039F400(void* stack, void* state);
extern const char D_0045D8D8[];
extern const char D_0045D8E8[];
extern const char D_0045D698[];

struct sVE_3710 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};
struct sBits_3710 {
    unsigned lo : 8;
    unsigned mode : 6;
    unsigned hi : 18;
};

extern "C" void func_00183710(char* self, char* item, unsigned int msg)
{
    if (item == 0) return;
    switch (msg) {
    case 5: {
        int sub = *(int*)(item + 0x18);
        if (sub == 8) {
            char* w = (char*)func_001CB030(cMemMan_alloc(0x444, D_0045D8D8, 0x100, 0), *(void**)(self + 0x10), self, 0, 0xF);
            *(int*)(w + 0x140) = 0x37;
            func_001CD088(w, 8);
            func_001CE3C8(w, 0x4B, 1, 2);
            *(int*)(w + 0x58) = 1;
            func_001CE408(w, 1);
            func_001CE3C8(w, 0xE, 0, 2);
            func_001CE3C8(w, 0x27, 0, 2);
            func_001CE3C8(w, 0x28, 0, 2);
            func_001CE3C8(w, 0x34, 0, 2);
            func_001CE3C8(w, 0x1A, 0, 2);
            func_001CE3C8(w, 0x19, 0, 2);
            func_001CE3C8(w, 0x35, 0, 2);
            func_001CE3C8(w, 0x40, 0, 2);
            func_001CE3C8(w, 0x41, 0, 2);
            func_001CE3C8(w, 0x42, 0, 2);
            func_0039F290(*(char**)(self + 0x10) + 0x18, w);
            func_001CB418(w, func_00147170(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)(self + 0x44)));
            func_001831D0(self, 0);
        } else if (sub == 6) {
            int cid = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(cBE_getBE(), 1), *(signed char*)(self + 0x44));
            if (func_001577A0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(signed char*)(self + 0x44), cid) > 0) {
                char* w = (char*)func_00182220(cMemMan_alloc(0x1E4, D_0045D8E8, 0, 0), *(void**)(self + 0x10), self, *(signed char*)(self + 0x44), cid);
                *(unsigned char*)(w + 0x15) = func_001A1CD0(**(void***)(self + 0x10), *(signed char*)(self + 0x44));
                func_0039F290(*(char**)(self + 0x10) + 0x18, w);
                func_001831D0(self, 0);
            }
        } else {
            char* obj = **(char***)(self + 0x10);
            sVE_3710* vt = *(sVE_3710**)(obj + 4);
            void* r = vt[4].fn(obj + vt[4].delta, self, sub);
            if (r != 0) {
                func_0039F400(*(char**)(self + 0x10) + 0x18, r);
            }
        }
        func_001831D0(self, 0);
        break;
    }
    case 6: {
        char* obj = **(char***)(self + 0x10);
        sVE_3710* vt = *(sVE_3710**)(obj + 4);
        void* r = vt[5].fn(obj + vt[5].delta, self, *(int*)(item + 0x18));
        if (r != 0) {
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
            func_001831D0(self, 0);
        }
        break;
    }
    case 7: {
        char* w = (char*)func_001887A0(cMemMan_alloc(0x54, D_0045D698, 0x100, 0), *(void**)(self + 0x10), 1);
        ((sBits_3710*)(w + 0x1C))->mode = 1;
        cUIStateStack_pushSpecial(*(char**)(self + 0x10) + 0x18, w, 0, 0);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_00183A98);
#ifdef SKIP_ASM
extern void* D_0046CCC0[];
extern "C" void* func_0039E2A0(void *, int);
extern "C" unsigned char func_001A1CD0(void* self, int a1);

extern "C" void* func_00183A98(void* self, int a1, int a2)
{
    signed char idx = a2;
    func_0039E2A0(self, a1);
    *(void***)((char*)self + 0x8) = D_0046CCC0;
    *(int*)((char*)self + 0xC) = 0x12;
    *(signed char*)((char*)self + 0x44) = idx;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), idx);
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x48) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_00183B08);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0045D900[];
extern char D_0045D910[];
extern char D_0045D920[];
extern char D_0045D930[];

class cUIObj_183B08 {
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

extern "C" void func_00183B08(void* self)
{
    cUIObj_183B08* a = (cUIObj_183B08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D900));
    if (a != 0) {
        a->setVisible(0);
    }
    cUIObj_183B08* b = (cUIObj_183B08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D910));
    if (b != 0) {
        b->setVisible(1);
    }
    cUIObj_183B08* c = (cUIObj_183B08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D920));
    if (c != 0) {
        c->setVisible(1);
    }
    cUIObj_183B08* d = (cUIObj_183B08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D930));
    if (d != 0) {
        d->setVisible(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_00183C08);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0045D900[];
extern char D_0045D910[];
extern char D_0045D920[];
extern char D_0045D930[];

class cUIObj_183C08 {
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

extern "C" void func_00183C08(void* self)
{
    cUIObj_183C08* a = (cUIObj_183C08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D900));
    if (a != 0) {
        a->setVisible(1);
    }
    cUIObj_183C08* b = (cUIObj_183C08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D910));
    if (b != 0) {
        b->setVisible(0);
    }
    cUIObj_183C08* c = (cUIObj_183C08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D920));
    if (c != 0) {
        c->setVisible(0);
    }
    cUIObj_183C08* d = (cUIObj_183C08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045D930));
    if (d != 0) {
        d->setVisible(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateriderbio", func_00183D08);
#ifdef SKIP_ASM
struct sVec2_00183D08 { float x, y; };

class cWidget_00183D08 {
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
    virtual void v09(int a);
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
    virtual void v20(sVec2_00183D08* p);
    virtual void v21(sVec2_00183D08* p);
};

extern "C" void func_00183D08(cWidget_00183D08* self, void* rect, float scale)
{
    if (rect) {
        sVec2_00183D08 pos;
        self->v20(&pos);
        float k = scale * 256.0f;
        pos.x = (*(float*)((char*)rect + 0x14) - *(float*)((char*)rect + 0x10)) * k;
        pos.y = (*(float*)((char*)rect + 0x18) - *(float*)((char*)rect + 0xC)) * k;
        self->v21(&pos);
        self->v09(1);
    } else {
        self->v09(0);
    }
}
#endif

