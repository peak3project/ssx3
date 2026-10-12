#include "common.h"

//100%
INCLUDE_ASM("fe/ovstates", cFEStateTitle_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* self, int a1);
extern char D_004A17C8[];

extern "C" void cFEStateTitle_onCreateScreen(void* self)
{
    void* engine;
    void* screen;
    *(int*)((char*)self + 0x48) = 0;
    engine = *(void**)((char*)self + 0x10);
    screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A17C8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0028F140(func_0028B180(), 0);
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_001947F8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0045DB90[];
extern char D_004A17D0[];
extern int D_004A17C0;

class cUIObj_1947F8 {
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

extern "C" int func_001947F8(void* self)
{
    if (D_004A17C0 == 0 || --D_004A17C0 == 0) {
        cUIObj_1947F8* o = (cUIObj_1947F8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DB90));
        if (o != 0) {
            o->v07(1);
        }
        o = (cUIObj_1947F8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A17D0));
        if (o != 0) {
            o->setVisible(1);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_001948A8);
#ifdef SKIP_ASM
extern "C" void func_0039E510(void* self);
extern void* D_004A28A8;
extern int D_004A19CC;

struct sItem_1948A8 {
    char pad[0xC];
    int active;
    char pad2[0xC];
};
struct sList_1948A8 {
    int count;
    sItem_1948A8 items[1];
};

struct sApp_1948A8 {
    char pad[0xB0];
    sList_1948A8** lists[2];
};
struct sSelf_1948A8 {
    char pad[0x48];
    int timer;
};

static inline int isActive_1948A8(sList_1948A8* l, int j)
{
    if (j < l->count) {
        return l->items[j].active;
    }
    return 0;
}

extern "C" void func_001948A8(sSelf_1948A8* self)
{
    func_0039E510(self);
    self->timer += 1;
    if (self->timer > 0x708) {
        self->timer = 0;
        D_004A19CC |= 4;
        return;
    }
    int found = 0;
    int i;
    for (i = 0; i < 2; i++) {
        sList_1948A8* l = *((sApp_1948A8*)D_004A28A8)->lists[i];
        int n = l->count;
        if (n != 0) {
            int j;
            for (j = 0; j < n; j++) {
                if (isActive_1948A8(l, j)) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                self->timer = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00194980__FPv);
#ifdef SKIP_ASM
void func_00194980(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00194988);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_003A0330(void* self, int a1, int a2);
extern char D_004A17D0[];

extern "C" void func_00194988(void* self, void* item)
{
    int id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_004A17D0)) {
        *(int*)((char*)item + 0x18) = 0;
        func_003A0330(item, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_001949E0);
#ifdef SKIP_ASM
struct sVEntry_func_001949E0 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};
extern "C" void func_0039F400(void* list, void* item);

extern "C" void func_001949E0(void* self, void* msg, int type)
{
    if (type == 5) {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry_func_001949E0* vt = *(sVEntry_func_001949E0**)((char*)obj + 0x4);
        void* r = vt[4].fn((char*)obj + vt[4].delta, self, *(int*)((char*)msg + 0x18));
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00194A48);
#ifdef SKIP_ASM
extern "C" int func_00194A48(void* self, int a1, int a2)
{
    return a2 != 6 ? 0x100 : 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00194A60);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void*);
extern void* D_0046B9E8[];

extern "C" void* func_00194A60(void* self)
{
    func_0039E2A0(self);
    *(int*)((char*)self + 0xC) = 2;
    *(void***)((char*)self + 0x8) = D_0046B9E8;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", cFEStateMainMenu_onCreateScreen);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_003E6448(void* p, int v, int n);
extern "C" void func_00266CD8();
extern "C" void func_00261008();
extern "C" void func_0025B688();
extern "C" void func_00256C50();
extern "C" void func_00255898();
extern char D_00460030[];
extern char D_005308B8[];
extern int D_00534B30[];

struct sVEnt0_00194AA8 { short delta; short index; void (*fn)(void*); };
struct sVEnt1_00194AA8 { short delta; short index; void (*fn)(void*, unsigned char); };
struct sVEnt2_00194AA8 { short delta; short index; int (*fn)(void*); };

extern "C" void cFEStateMainMenu_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00460030), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_003E6448(D_005308B8, 0, 0x20);
    *(int*)((char*)self + 0x48) = 0;
    *(char*)((char*)self + 0x54) = 0;
    func_00266CD8();
    func_00261008();
    func_0025B688();
    func_00256C50();
    func_00255898();
    void* iface = cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    D_00534B30[0] = 0;
    sVEnt0_00194AA8* vt0 = *(sVEnt0_00194AA8**)((char*)iface + 0xC);
    vt0[1].fn((char*)iface + vt0[1].delta);
    func_0028F140(func_0028B180(), 1);
    char* obj = *(char**)(*(char**)((char*)self + 0x10) + 0xC);
    *(unsigned char*)((char*)self + 0x55) = 0;
    for (int i = 0; i < 2; i++) {
        sVEnt1_00194AA8* vt1 = *(sVEnt1_00194AA8**)(obj + 8);
        vt1[44].fn(obj + vt1[44].delta, i);
        sVEnt2_00194AA8* vt2 = *(sVEnt2_00194AA8**)(obj + 8);
        if (vt2[45].fn(obj + vt2[45].delta) != 0) {
            (*(unsigned char*)((char*)self + 0x55))++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00194BF0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_00194498(void* obj);
extern int D_004A29EC;
extern char D_00460040[];
extern char D_004A17D8[];

struct sColor_194BF0 {
    float r, g, b, a;
};

class cUIObj_194BF0 {
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
    virtual void v10();
    virtual void setColor(const sColor_194BF0& c);
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
    virtual void setSelected(int v);
};

extern "C" void func_00194BF0(void* self)
{
    cUIObj_194BF0* obj = (cUIObj_194BF0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00460040));
    if (obj != 0) {
        if (*(signed char*)((char*)self + 0x55) < 2) {
            func_00194498(obj);
        } else if ((*(unsigned char*)((char*)self + 0x1D) & 0x3F) == 5) {
            obj->setSelected(0);
            obj->setEnabled(0);
            sColor_194BF0 c = *(sColor_194BF0*)((char*)obj + 0x1C);
            c.r = 1.0f;
            obj->setColor(c);
        }
    }
    if (D_004A29EC == 0) {
        void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A17D8));
        if (o != 0) {
            func_00194498(o);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", cFEStateMainMenu_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00460050[];
extern char D_00460060[];
extern char D_00460040[];
extern char D_00460070[];
extern char D_004A17D8[];

extern "C" void cFEStateMainMenu_onWidgetCreate(void* self, void* item)
{
    int id;
    id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_00460050)) {
        *(int*)((char*)item + 0x18) = 0xB;
        return;
    }
    id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_00460060)) {
        *(int*)((char*)item + 0x18) = 9;
        return;
    }
    id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_00460040)) {
        *(int*)((char*)item + 0x18) = 0x16;
        return;
    }
    id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_00460070)) {
        *(int*)((char*)item + 0x18) = 5;
        return;
    }
    id = *(int*)((char*)item + 0x38);
    if (id == GetHashValue32(D_004A17D8)) {
        *(int*)((char*)item + 0x18) = 0x31;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00194DD0);
#ifdef SKIP_ASM
extern "C" void func_0039E510(void* self);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, int index);
extern char D_004A1398[];

class cProfileMan_194DD0 {
public:
    int pad[2];
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
    virtual void select(unsigned char i);
    virtual int isValid();
};

extern "C" void func_00194DD0(void* self)
{
    int i = 0;
    func_0039E510(self);
    cProfileMan_194DD0* pm = *(cProfileMan_194DD0**)((char*)*(void**)((char*)self + 0x10) + 0xC);
    *(signed char*)((char*)self + 0x55) = 0;
    for (; i < 2; i++) {
        pm->select(i);
        if (pm->isValid()) {
            (*(signed char*)((char*)self + 0x55))++;
        }
    }
    void* menu = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1398));
    if (menu != 0) {
        if (*(unsigned char*)((char*)menu + 0x95) == 2) {
            if (*(signed char*)((char*)self + 0x55) < 2) {
                cUIMenu_setSelectedByIndex(menu, 1);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", cFEStateMainMenu_onWidgetEvent);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
extern "C" void func_001A86E8(int a);
extern "C" void func_00145108(void* iface, int mode);
extern "C" void cCommSystem_construct();
extern "C" void func_0025B650();
extern "C" void func_00260F80();
extern "C" void func_00266CA0();
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0039E318(void* self, void* engine, void* owner);
extern "C" void func_0039F290(void* stack, void* state);
extern "C" void* func_001887A0(void* mem, void* engine, int a2);
extern "C" void cUIStateStack_pushSpecial(void* stack, void* state, int a2, int a3);
extern void* D_00469518[];
extern char D_00460080[];
extern char D_0045D698[];
extern char D_004A17E8[];
extern char D_00460040[];
extern char D_00460060[];
extern char D_004600A0[];
extern char D_004A1458[];
extern char D_004A1460[];
extern char D_004A17E0[];

struct sVE_194EB0 {
    short delta;
    short index;
    void* fn;
};

struct sObj_194EB0 {
    int pad0;
    sVE_194EB0* vt;
};

static inline void setWidgetHidden_194EB0(char* self, char* name)
{
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(name));
    if (o != 0) {
        sVE_194EB0* vt = *(sVE_194EB0**)(o + 0x8);
        ((void (*)(void*, int))vt[9].fn)(o + vt[9].delta, 0);
    }
}

static inline void setWidgetVisible_194EB0(char* self, char* name)
{
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(name));
    if (o != 0) {
        sVE_194EB0* vt = *(sVE_194EB0**)(o + 0x8);
        ((void (*)(void*, int))vt[8].fn)(o + vt[8].delta, 0);
    }
}

extern "C" void cFEStateMainMenu_onWidgetEvent(void* self_, void* item_, unsigned int type)
{
    char* self = (char*)self_;
    char* item = (char*)item_;
    if (item == 0)
        return;
    switch (type) {
    case 5: {
        func_001A86E8(0);
        char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
        switch (*(int*)(item + 0x18)) {
        case 11:
            func_00145108(iface, 0);
            *(int*)(self + 0x48) = 1;
            break;
        case 9:
            func_00145108(iface, 1);
            *(int*)(self + 0x48) = 1;
            // both arms set the flag; the leftover compare on the cheat counter is in the target too
            if (*(signed char*)(self + 0x54) >= 7)
                *(int*)(self + 0x48) = 1;
            break;
        case 22:
            func_00145108(iface, 2);
            *(int*)(self + 0x48) = 1;
            break;
        case 49:
            func_00145108(iface, 2);
            cCommSystem_construct();
            func_0025B650();
            func_00260F80();
            func_00266CA0();
        case 5:
            *(int*)(self + 0x48) = 1;
            break;
        }
        sVE_194EB0* ivt = *(sVE_194EB0**)(iface + 0xC);
        ((void (*)(void*))ivt[1].fn)(iface + ivt[1].delta);
        if (*(int*)(item + 0x18) == 0x16 && *(int*)(self + 0x48) == 0) {
            *(int*)(self + 0x50) = *(signed char*)(self + 0x14);
            char* popup = (char*)operator new(0x4C, D_00460080, 0, 0);
            func_0039E318(popup, *(void**)(self + 0x10), self);
            *(void***)(popup + 0x8) = D_00469518;
            int bit = 1;
            bit <<= *(int*)(self + 0x50);
            *(char*)(popup + 0x15) = bit;
            *(char*)(popup + 0x48) = 0;
            func_0039F290(*(char**)(self + 0x10) + 0x18, popup);
            *(char**)(self + 0x4C) = item;
            setWidgetHidden_194EB0(self, D_004A17E0);
            setWidgetHidden_194EB0(self, D_004600A0);
            setWidgetHidden_194EB0(self, D_004A1458);
            setWidgetHidden_194EB0(self, D_004A1460);
            return;
        }
        sObj_194EB0* obj = **(sObj_194EB0***)(self + 0x10);
        void* r = ((void* (*)(void*, void*, int))obj->vt[4].fn)((char*)obj + obj->vt[4].delta, self, *(int*)(item + 0x18));
        if (r != 0)
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        break;
    }
    case 6: {
        sObj_194EB0* obj = **(sObj_194EB0***)(self + 0x10);
        void* r = ((void* (*)(void*, void*, int))obj->vt[5].fn)((char*)obj + obj->vt[5].delta, self, *(int*)(item + 0x18));
        if (r != 0)
            func_0039F400(*(char**)(self + 0x10) + 0x18, r);
        break;
    }
    case 7: {
        char* o = (char*)func_001887A0(cMemMan_alloc(0x54, D_0045D698, 0x100, 0), *(void**)(self + 0x10), 1);
        *(int*)(o + 0x1C) = (*(int*)(o + 0x1C) & ~0x3F00) | 0x100;
        cUIStateStack_pushSpecial(*(char**)(self + 0x10) + 0x18, o, 0, 0);
        break;
    }
    case 8:
        if (++*(signed char*)(self + 0x54) >= 7) {
            setWidgetVisible_194EB0(self, D_00460060);
            setWidgetVisible_194EB0(self, D_00460040);
            setWidgetVisible_194EB0(self, D_004A17E8);
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_001952E8);
#ifdef SKIP_ASM
extern "C" int func_001952E8(void* self, int a1, int a2)
{
    switch (a2) {
    case 6:
        return *(int*)((char*)self + 0x48) == 0 ? 1 : 0x101;
    case 9:
        return 0x100;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00195328);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" int func_0039FFA0(void* self, int x);
extern char D_004A17E0[];
extern char D_004600A0[];
extern char D_004A1458[];
extern char D_004A1460[];

struct sVEi_195328 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sVEv_195328 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

static inline void Show195328(void* self, char* name)
{
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    if (o != 0) {
        sVEv_195328* vt = *(sVEv_195328**)(o + 8);
        vt[9].fn(o + vt[9].delta, 1);
    }
}

// On confirm (msg 0x16) commits the selected entry, then re-shows the four main-menu buttons.
extern "C" void func_00195328(void* self, char* obj, int msg)
{
    if (msg == 0x15) {
        return;
    }
    if (msg != 0x16) {
        return;
    }
    sVEi_195328* ovt = *(sVEi_195328**)(obj + 8);
    if (ovt[23].fn(obj + ovt[23].delta, 0) != 0) {
        *(int*)((char*)self + 0x48) = 1;
        int v = *(signed char*)((char*)self + 0x50);
        *(char*)((char*)self + 0x14) = v;
        func_0039FFA0(*(void**)((char*)self + 0x4C), 2);
        sVEv_195328* svt = *(sVEv_195328**)((char*)self + 8);
        svt[19].fn((char*)self + svt[19].delta, *(void**)((char*)self + 0x4C), 5);
    }
    Show195328(self, D_004A17E0);
    Show195328(self, D_004600A0);
    Show195328(self, D_004A1458);
    Show195328(self, D_004A1460);
}
#endif

//100%
INCLUDE_ASM("fe/ovstates", func_00195498);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void*);
extern char D_0046B918[];

extern "C" void* func_00195498(void* self)
{
    func_0039E2A0(self);
    *(void**)((char*)self + 0x8) = D_0046B918;
    *(int*)((char*)self + 0xC) = 5;
    return self;
}
#endif

