#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

struct sColorK18EB40 {
    float r, g, b, a;
    sColorK18EB40(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

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
    virtual void setEnabled(int on);
    virtual void setFocus(int on);
    virtual void setStatic(int);
    virtual void setVisible(int on);
    virtual void v10();
    virtual void v11(const sColorK18EB40& c);
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
    virtual void v25(int);
};

// Declarations shared by the functions of this unit.
struct cAppMan;
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0039F400(void* self, void* state);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern int D_004A15E8;
extern "C" void* func_00227F80(void* app);
extern void* D_004A28A8;
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_004A15E0[];
extern char D_004A15D0[];
extern char D_004A15D8[];
extern char D_004A1458[];
extern char D_004A1460[];
extern "C" void func_0018F2B8(void* self);
extern "C" void func_0018F9D8(void* self);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_0045E260[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern char D_0045E318[];
extern char D_0045E330[];
extern char D_0045E348[];
extern char D_0045E358[];

//100%
INCLUDE_ASM("fe/festateprofile", cFEStateProfileSelect_onCreateScreen);
#ifdef SKIP_ASM
extern char D_0045E240[];

extern "C" void cFEStateProfileSelect_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045E240), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018EB40);
#ifdef SKIP_ASM
extern "C" void func_0018EB40(void* self, char* menu, unsigned int msg)
{
    if (menu == 0)
        return;
    switch (msg) {
    case 5: {
        ((cUIThing*)menu)->v11(sColorK18EB40(1.0f, 1.0f, 0.0f, 0.0f));
        char* g = **(char***)((char*)self + 0x10);
        sVEntry<void*(void*, void*, int)>* vt = *(sVEntry<void*(void*, void*, int)>**)(g + 4);
        void* r = vt[4].fn(g + vt[4].delta, self, *(int*)(menu + 0x18));
        if (r != 0)
            func_0039F400(*(char**)((char*)self + 0x10) + 0x18, r);
        break;
    }
    case 6: {
        char* g = **(char***)((char*)self + 0x10);
        sVEntry<void*(void*, void*, int)>* vt = *(sVEntry<void*(void*, void*, int)>**)(g + 4);
        void* r = vt[5].fn(g + vt[5].delta, self, *(int*)(menu + 0x18));
        if (r != 0)
            func_0039F400(*(char**)((char*)self + 0x10) + 0x18, r);
        break;
    }
    case 1: {
        ((cUIThing*)menu)->v11(sColorK18EB40(1.0f, 0.0f, 1.0f, 0.0f));
        break;
    }
    case 2: {
        ((cUIThing*)menu)->v11(sColorK18EB40(1.0f, 1.0f, 1.0f, 1.0f));
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018ECA0);
#ifdef SKIP_ASM
extern "C" int func_00147318(void* self, int a1);
extern "C" void* func_001D53B0(void* self, int a1, int a2);
extern void* D_0046BFD0[];
extern char D_00535BC8[];

extern "C" void* func_0018ECA0(void* self, int a1, int a2, unsigned char flags)
{
    func_001D53B0(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x23;
    *(void***)((char*)self + 0x8) = D_0046BFD0;
    D_004A15E8 = a2;
    *(int*)((char*)self + 0x1CC) = 0;
    *(int*)((char*)self + 0x230) = 0;
    *(int*)((char*)self + 0x234) = 0;
    *(int*)((char*)self + 0x27C) = 0;
    *(unsigned char*)((char*)self + 0x15) = flags;
    *(int*)((char*)self + 0x22C) = 0;
    for (int i = 0; i < 3; i++) {
        if (flags & 1) {
            break;
        }
        flags >>= 1;
        *(int*)((char*)self + 0x22C) += 1;
    }
    void* pi = cBE_getInterface_Fv(cBE_getBE(), 1);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    signed char* g = (signed char*)D_00535BC8;
    int n = 1;
    if (g[0x49] == 2) {
        n = 2;
    }
    for (int j = 0; j < n; j++) {
        if (func_00147318(pi, j) == *(int*)((char*)self + 0x22C)) {
            *(int*)((char*)self + 0x1CC) = j;
            break;
        }
    }
    int idx = *(signed char*)((char*)self + 0x1CC);
    *(signed char*)((char*)self + 0x44) = idx;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", cFEStateProfileLoad_onCreateScreen);
#ifdef SKIP_ASM
extern char D_0045E250[];
extern "C" void func_001902C0(void* self);
extern "C" void cFEStateProfileLoad_initCreateScreen(void* self);
extern "C" void func_00190670(void* self);
extern "C" void func_00190768(void* self);

extern "C" void cFEStateProfileLoad_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045E250), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_001902C0(self);
    switch (D_004A15E8) {
    case 1:
        cFEStateProfileLoad_initCreateScreen(self);
        break;
    case 2:
        func_00190670(self);
        break;
    case 3:
        func_00190768(self);
        break;
    }
}
#endif

extern "C" void func_0039E6B8(void* self);

//100%
INCLUDE_ASM("fe/festateprofile", func_0018EE98__FPv);
#ifdef SKIP_ASM
void func_0018EE98(void* self)
{
    func_0039E6B8(self);
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018EEB8);
#ifdef SKIP_ASM
struct cList0018EEB8 {
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual int v54(int a);
};

extern "C" int func_0018EEB8(void* self, void* widget, unsigned int msg)
{
    char* app = (char*)func_00227F80(D_004A28A8);
    switch (msg) {
    case 6:
        if ((*(cList0018EEB8**)(app + 0x434))->v54(*(int*)(app + 0x428)) == 0) {
            return 0x100;
        }
        break;
    case 8:
        if (D_004A15E8 == 2 || *(int*)((char*)self + 0x220) == 0) {
            return 0x100;
        }
        break;
    case 9:
        return 0x100;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018EF70);
#ifdef SKIP_ASM
extern "C" void func_0018EF70(void* self, int on)
{
    if (*(int*)((char*)self + 0x234) == on)
        return;
    int off = on ^ 1;
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15E0)))->setVisible(off);
    if (D_004A15E8 != 2) {
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D0)))->setVisible(off);
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1458)))->setVisible(off);
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1460)))->setVisible(off);
    } else {
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D8)))->setVisible(off);
    }
    *(int*)((char*)self + 0x234) = on;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018F0B8);
#ifdef SKIP_ASM
extern "C" void func_0018F0B8(void* self, bool on)
{
    if (D_004A15E8 != 2) {
        int off = !on;
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1458)))->setVisible(off);
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1460)))->setVisible(off);
    }
    *(int*)((char*)self + 0x220) = !on;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018F168);
#ifdef SKIP_ASM
extern "C" void func_0018F168(void* self, bool a, bool b)
{
    cUIThing* o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15E0));
    if (D_004A15E8 != 2) {
        int v = !b;
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D0)))->setVisible(v);
        *(int*)((char*)self + 0x224) = v;
        o->setVisible(v);
    } else {
        int v = !a;
        ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D8)))->setVisible(v);
        *(int*)((char*)self + 0x224) = v;
        o->setVisible(v);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018F278);
#ifdef SKIP_ASM
extern "C" void func_0018F278(void* self)
{
    if (*(int*)((char*)self + 0x214) == 3) {
        func_0018F2B8(self);
    } else {
        func_0018F9D8(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018F2B8);
#ifdef SKIP_ASM
extern "C" void func_001D8240();
extern "C" int func_001D97E0(void* self, void* mp, int dev, int a3);
extern "C" void cMCOverlayManager_GetDeviceDisplayString(void* mp, int dev, unsigned short* buf, int len);
extern "C" void func_003A0D00(void* obj, unsigned short* s);
extern "C" void func_003A0E90(void* obj, unsigned short* s);
extern char D_0045E1D8[];
extern char D_0045E1E8[];
extern char D_0045E270[];
extern char D_0045E280[];
extern char D_004A15F0[];
extern char D_004A15F8[];

struct sColor_F2B8 {
    int c[4];
};
extern sColor_F2B8 D_004C66C8;

class cMCSub_F2B8 {
public:
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual void v14(int, void*);
    virtual void v15(int, void*);
    virtual void v16(int, void*);
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54(int);
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66(int);
    virtual int v67(int);
};
class cState_F2B8 {
public:
    int pad[2];
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual void v35(int);
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual void v43();
};

static inline cUIThing* getObj_F2B8(cState_F2B8* self, char* name)
{
    return (cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

extern "C" void func_0018F2B8_s(cState_F2B8* self) __asm__("func_0018F2B8");

extern "C" void func_0018F2B8_s(cState_F2B8* self)
{
    unsigned short buf[0x320];
    char name[0x40];
    char* mp = (char*)func_00227F80(D_004A28A8);
    if (self->v42()) {
        if (!(*(cMCSub_F2B8**)(mp + 0x434))->v53()) {
            func_001D8240();
            func_0018F9D8(self);
            return;
        }
        if (*(int*)((char*)self + 0x214) != 3) {
            self->v35(3);
        }
    }
    if (self->v42()) {
        cMCOverlayManager_GetDeviceDisplayString(mp, *(int*)(mp + 0x428), buf, 0x320);
        int sel = 0;
        func_003A0D00(getObj_F2B8(self, D_0045E1E8), buf);
        *(int*)((char*)self + 0x21C) = *(int*)(mp + 0x428);
        self->v43();
        cUIThing* o = getObj_F2B8(self, D_0045E1D8);
        o->setVisible(0);
        for (int i = 1; i < 7; i++) {
            sprintf(name, D_0045E260, i);
            o = getObj_F2B8(self, name);
            *(sColor_F2B8*)((char*)o + 0x88) = D_004C66C8;
            if (!(*(cMCSub_F2B8**)(mp + 0x434))->v67(i - 1) && !(*(cMCSub_F2B8**)(mp + 0x434))->v66(i - 1)
                && (*(cMCSub_F2B8**)(mp + 0x434))->v55()) {
                (*(cMCSub_F2B8**)(mp + 0x434))->v14(i - 1, (char*)self + 0x238);
                func_003A0E90(o, (unsigned short*)((char*)self + 0x238));
                if (D_004A15E8 != 2 && sel == 0) {
                    sel = 1;
                    o->setStatic(0);
                    o->v25(0);
                } else {
                    o->v25(1);
                    o->setStatic(1);
                }
                sprintf(name, D_004A15F0, i);
                o = getObj_F2B8(self, name);
                o->setVisible(0);
                sprintf(name, D_004A15F8, i);
                o = getObj_F2B8(self, name);
                o->setVisible(0);
            } else if ((*(cMCSub_F2B8**)(mp + 0x434))->v54(*(int*)(mp + 0x428))) {
                (*(cMCSub_F2B8**)(mp + 0x434))->v14(i - 1, (char*)self + 0x238);
                func_003A0E90(o, (unsigned short*)((char*)self + 0x238));
                if ((*(cMCSub_F2B8**)(mp + 0x434))->v66(i - 1)) {
                    o->setStatic(1);
                    o->v25(1);
                } else {
                    o->setStatic(0);
                    o->v25(0);
                }
                sprintf(name, D_004A15F0, i);
                o = getObj_F2B8(self, name);
                (*(cMCSub_F2B8**)(mp + 0x434))->v15(i - 1, buf);
                func_003A0E90(o, buf);
                o->setVisible(1);
                sprintf(name, D_004A15F8, i);
                o = getObj_F2B8(self, name);
                (*(cMCSub_F2B8**)(mp + 0x434))->v16(i - 1, buf);
                func_003A0E90(o, buf);
                o->setVisible(1);
            } else {
                (*(cMCSub_F2B8**)(mp + 0x434))->v14(i - 1, (char*)self + 0x238);
                func_003A0E90(o, (unsigned short*)((char*)self + 0x238));
                o->v25(1);
                o->setStatic(1);
                sprintf(name, D_004A15F0, i);
                o = getObj_F2B8(self, name);
                o->setVisible(0);
                sprintf(name, D_004A15F8, i);
                o = getObj_F2B8(self, name);
                o->setVisible(0);
            }
        }
        if (func_001D97E0(self, mp, *(int*)(mp + 0x428), 1) == -1)
            getObj_F2B8(self, D_0045E270)->setVisible(0);
        else
            getObj_F2B8(self, D_0045E270)->setVisible(1);
        if (func_001D97E0(self, mp, *(int*)(mp + 0x428), 0) == -1)
            getObj_F2B8(self, D_0045E280)->setVisible(0);
        else
            getObj_F2B8(self, D_0045E280)->setVisible(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018F9D8);
#ifdef SKIP_ASM
struct cSelf_F9D8 {
    int f0;
    int f4;
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
    virtual void setState(int s);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual int isReady();
};
struct cCard_F9D8 {
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual int isPresent();
};

extern "C" void func_0018F9D8(void* p)
{
    cSelf_F9D8* self = (cSelf_F9D8*)p;
    void* app = func_00227F80(D_004A28A8);
    if (self->isReady() != 0) {
        if ((*(cCard_F9D8**)((char*)app + 0x434))->isPresent() != 0) {
            self->setState(3);
            func_0018F2B8(self);
            return;
        }
    }
    for (int i = 1; i < 7; i++) {
        char buf[64];
        sprintf(buf, D_0045E260, i);
        cUIThing* o = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        o->v25(0);
        o->setStatic(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018FAF0);
#ifdef SKIP_ASM
extern "C" int cBENewRaceInterface_setGameMode(void* iface, int mode);
extern "C" int cBENewRaceInterface_setGameEvent(void* iface, int ev);
extern "C" int func_00146D98(void* iface, int a1);
void* func_00232720(void* self);
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
extern "C" void* func_00194738(void* self, void* engine);
extern "C" void func_0039F4C0(void* self, void* state);
extern int D_004A11B8;
extern int D_004A19D8;
extern int D_00535C08[];
extern char D_0045CE60[];
extern char D_0045E290[];

extern "C" void func_0018FAF0(void* self)
{
    if (*(int*)((char*)self + 0x1AC) == 0) {
        int sel = *(int*)((char*)self + 0x27C);
        if (sel == 0) {
            char* g = **(char***)((char*)self + 0x10);
            sVEntry<void*(void*, void*, int)>* vt = *(sVEntry<void*(void*, void*, int)>**)(g + 4);
            void* r = vt[5].fn(g + vt[5].delta, self, *(int*)((char*)self + 0x1BC));
            if (r != 0)
                func_0039F4C0(*(char**)((char*)self + 0x10) + 0x18, r);
        } else if (sel == 1) {
            char* race = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
            void* pl = cBE_getInterface_Fv(cBE_getBE(), 1);
            cBENewRaceInterface_setGameMode(race, 4);
            cBENewRaceInterface_setGameEvent(race, 0xC);
            int x = func_00146D98(pl, 0);
            D_004A11B8 = 1;
            D_00535C08[0] = x;
            sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)(race + 0xC);
            vt[1].fn(race + vt[1].delta);
            cAppMan_setNextModule((cAppMan*)D_004A28A8, (unsigned int)func_00232720(cMemMan_alloc(8, D_0045CE60, 0x100, 0)));
        } else if (sel == 2) {
            D_004A19D8 = 0;
            void* st = func_00194738(cMemMan_alloc(0x4C, D_0045E290, 0, 0), *(void**)((char*)self + 0x10));
            func_0039F400(*(char**)((char*)self + 0x10) + 0x18, st);
        }
    }
    *(int*)((char*)self + 0x1AC) = 1;
}
#endif

extern "C" void func_001D58B8(void*);

//100%
INCLUDE_ASM("fe/festateprofile", func_0018FC70__FPv);
#ifdef SKIP_ASM
void func_0018FC70(void* self)
{
    func_001D58B8(self);
    *(int*)((char*)self + 0x1a4) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018FC98);
#ifdef SKIP_ASM
extern "C" void func_0023CAE8(void* app, int a1, int a2);
extern "C" void func_00241E18(void*, unsigned short*, int);
void cMemMan_free(void* p);
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_0045E2A0[];

struct cSelf_FC98 {
    int f0;
    int f4;
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
    virtual void showMessage(unsigned short* text, int a2, int a3, int a4, int a5, int a6);
};

extern "C" void func_0018FC98(void* p)
{
    cSelf_FC98* self = (cSelf_FC98*)p;
    if (*(int*)((char*)self + 0x224) != 0) {
        func_0023CAE8(func_00227F80(D_004A28A8), 1, *(int*)((char*)self + 0x1CC));
        *(int*)((char*)self + 0x1C0) = 3;
        *(int*)((char*)self + 0x1A8) = 1;
        *(int*)((char*)self + 0x1DC) = 1;
        if (*(int*)((char*)self + 0x210) == 0 && *(int*)((char*)self + 0x204) == 0) {
            *(int*)((char*)self + 0x19C) = 0x16;
            unsigned short* buf = (unsigned short*)operator_new__FUi(0x640, D_0045E2A0, 0x100, 0);
            func_00241E18(func_00227F80(D_004A28A8), buf, 0x320);
            self->showMessage(buf, 1, 1, 0, 0, 1);
            *(int*)((char*)self + 0x210) = 1;
            if (buf != 0) {
                cMemMan_free(buf);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_0018FD90);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);
extern "C" void func_00147138(void* player, int idx, char* name);
extern "C" void* func_00147170(void* player, int idx);
extern "C" void func_0018FC98(void* p);
extern "C" void* func_001CB030(void* mem, void* engine, void* owner, int a3, int a4);
extern "C" void func_001CB418(void* kb, void* name);
extern "C" void func_001CD088(void* kb, int a1);
extern "C" void func_001CD0B0(void* kb, int a1);
extern "C" void func_001CE3C8(void* kb, int key, int a2, int a3);
extern "C" void func_001CE408(void* kb, int a1);
extern "C" void cKeyboardPopup_setStatic(void* kb, void* text);
extern "C" void func_0023C8F0(void* mp, int a1);
extern "C" void func_0023D570(void* mp, int a1);
extern "C" unsigned short* func_002C2540(void* dst, char* src);
extern "C" char* func_002C2580(char* dst, void* src);
extern "C" void func_0039F290(void* list, void* item);
extern char D_0045E2B0[];
extern char D_0045E2C8[];
extern char D_0045E2D8[];

#define VCALLV_K18FD90(obj, off, idx) (*(sVEntry<void(void*, ...)>**)((char*)(obj) + (off)))[idx].fn((char*)(obj) + (*(sVEntry<void(void*, ...)>**)((char*)(obj) + (off)))[idx].delta

#define VCALL_K18FD90(obj, off, idx) (*(sVEntry<void*(void*, ...)>**)((char*)(obj) + (off)))[idx].fn((char*)(obj) + (*(sVEntry<void*(void*, ...)>**)((char*)(obj) + (off)))[idx].delta

struct sProfileK18FD90 {
    int f0;                  // 0x0
    int f4;                  // 0x4
    void* vtbl;              // 0x8
    int fC;                  // 0xC
    void* engine;            // 0x10
    unsigned char f14;       // 0x14
    unsigned char f15;       // 0x15
    char pad16[0x40 - 0x16];
    char* screen;            // 0x40
    char pad44[0x19C - 0x44];
    int f19C;                // 0x19C
    int f1A0;                // 0x1A0
    char* keyboard;          // 0x1A4
    int f1A8;                // 0x1A8
    char pad1AC[0x1C0 - 0x1AC];
    int state;               // 0x1C0
    int f1C4;                // 0x1C4
    int f1C8;                // 0x1C8
    int slot;                // 0x1CC
    char pad1D0[0x1E4 - 0x1D0];
    int f1E4;                // 0x1E4
    char pad1E8[0x214 - 0x1E8];
    int f214;                // 0x214
    char pad218[0x220 - 0x218];
    int f220;                // 0x220
    int f224;                // 0x224
};

struct sMgrK18FD90 {
    char pad0[0xF8];
    int fF8;                 // 0xF8
};

static inline void* GetText_K18FD90(char* key)
{
    char* db = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry<void*(void*, ...)>* vt = *(sVEntry<void*(void*, ...)>**)(db + 4);
    return vt[4].fn(db + vt[4].delta, GetHashValue32(key));
}

// Profile screen: handles menu events (5 = name picked, 6 = back, 7 = slot chosen, 13 = name entered).
extern "C" void func_0018FD90(void* vself, char* item, int event)
{
    sProfileK18FD90* self = (sProfileK18FD90*)vself;
    switch (event) {
    case 13: {
        char buf[0x70];
        char fmt[0x70];
        char* name = self->keyboard + 0x74;
        char* mp = (char*)func_00227F80(D_004A28A8);
        char* player = (char*)cBE_getInterface_Fv(cBE_getBE(), 1);
        if (strlen(name) != 0) {
            func_00147138(player, self->slot, name);
            func_002C2540(mp + 0x276, name);
        } else {
            func_002C2580(fmt, GetText_K18FD90(D_0045E2B0));
            sprintf(buf, fmt, self->slot + 1);
            func_00147138(player, self->slot, buf);
            func_002C2540(mp + 0x276, buf);
        }
        VCALLV_K18FD90(player, 0xC, 1));
        func_0018FC98(vself);
        break;
    }
    case 5: {
        if (item == 0) break;
        if (self->f1A8 != 0) break;
        char* mp = (char*)func_00227F80(D_004A28A8);
        if (self->f214 != 3) break;
        ((sMgrK18FD90*)mp)->fF8 = self->f1C4 = *(int*)(item + 0x18);
        switch (D_004A15E8) {
        case 1:
        case 3:
            if (self->state == 1 && self->f224 != 0) {
                if (self->keyboard == 0) {
                    char* kb = (char*)func_001CB030(cMemMan_alloc(0x444, D_0045E2C8, 0x100, 0), self->engine, vself, 0, self->f15);
                    self->keyboard = kb;
                    *(int*)(kb + 0x140) = 0x37;
                    func_001CD088(self->keyboard, 8);
                    func_001CE3C8(self->keyboard, 0x4B, 1, 2);
                    *(int*)(self->keyboard + 0x58) = 1;
                    func_001CE408(self->keyboard, 1);
                    func_001CE3C8(self->keyboard, 0xE, 0, 2);
                    func_001CE3C8(self->keyboard, 0x27, 0, 2);
                    func_001CE3C8(self->keyboard, 0x28, 0, 2);
                    func_001CE3C8(self->keyboard, 0x34, 0, 2);
                    func_001CE3C8(self->keyboard, 0x1A, 0, 2);
                    func_001CE3C8(self->keyboard, 0x19, 0, 2);
                    func_001CE3C8(self->keyboard, 0x35, 0, 2);
                    func_001CE3C8(self->keyboard, 0x40, 0, 2);
                    func_001CE3C8(self->keyboard, 0x41, 0, 2);
                    func_001CE3C8(self->keyboard, 0x42, 0, 2);
                    func_001CD0B0(self->keyboard, 1);
                }
                cKeyboardPopup_setStatic(self->keyboard, GetText_K18FD90(D_0045E2D8));
                *(int*)(self->keyboard + 0x54) = 1;
                func_001CB418(self->keyboard, func_00147170(cBE_getInterface_Fv(cBE_getBE(), 1), self->slot));
                func_0039F290(*(char**)(*(char**)(self->screen + 0xD0) + 0x10) + 0x18, self->keyboard);
                self->f1A0 = 1;
                self->f19C = 0;
            }
            break;
        case 2:
            if (self->f224 != 0) {
                func_0023C8F0(mp, 1);
                VCALLV_K18FD90(self, 8, 44));
            }
            break;
        }
        break;
    }
    case 6: {
        char* mp = (char*)func_00227F80(D_004A28A8);
        if (self->f1A8 != 1) {
            int st = self->state;
            if (st != 6) {
                self->f1E4 = 1;
                if (st == 0 || st == 2 || st == 1) {
                    VCALLV_K18FD90(mp, 0x748, 1), 0);
                }
                self->state = 6;
            }
        }
        break;
    }
    case 7:
        if (self->f1A8 != 1 && self->state != 6 && D_004A15E8 != 2 && self->f220 != 0) {
            char* mp = (char*)func_00227F80(D_004A28A8);
            if (VCALL_K18FD90(*(char**)(mp + 0x434), 0, 54), *(int*)(mp + 0x428)) != 0) {
                ((sMgrK18FD90*)mp)->fF8 = self->f1C4 = *(int*)(item + 0x18);
                if (self->state == 1) {
                    if (VCALL_K18FD90(*(char**)(mp + 0x434), 0, 67), self->f1C4) != 0) {
                        self->f1A8 = 1;
                        self->state = 4;
                        func_0023D570(mp, 0);
                        VCALLV_K18FD90(mp, 0x748, 1), 0x18);
                    }
                }
            }
        }
        break;
    case 14:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_001902C0);
#ifdef SKIP_ASM
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_004A12C0[];
extern char D_004A1600[];
extern char D_004A1608[];

static inline cUIThing* getObj_02C0(char* self, char* name)
{
    return (cUIThing*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(name));
}

// Hides the profile panels, numbers the six slot rows and enables the confirm buttons.
extern "C" void func_001902C0(void* selfp)
{
    char* self = (char*)selfp;
    cUIThing* o;
    o = getObj_02C0(self, D_0045E318);
    o->setVisible(0);
    o = getObj_02C0(self, D_0045E330);
    o->setVisible(0);
    o = getObj_02C0(self, D_0045E348);
    o->setVisible(0);
    o = getObj_02C0(self, D_0045E358);
    o->setVisible(0);
    o = getObj_02C0(self, D_004A15D0);
    o->setVisible(0);
    o = getObj_02C0(self, D_004A15D8);
    o->setVisible(0);
    o = getObj_02C0(self, D_004A1458);
    o->setVisible(0);
    char buf[0x10];
    for (int i = 1; i < 7; i++) {
        sprintf(buf, D_004A12C0, i);
        o = getObj_02C0(self, buf);
        cUIText_setAsciiString((cUIText*)o, buf);
        sprintf(buf, D_0045E260, i);
        o = getObj_02C0(self, buf);
        *(int*)((char*)o + 0x18) = i - 1;
    }
    getObj_02C0(self, D_004A1600)->setFocus(0);
    getObj_02C0(self, D_004A1608)->setFocus(1);
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", cFEStateProfileLoad_initCreateScreen);
#ifdef SKIP_ASM
void cUIText_setUnicodeStringByID(cUIText* t, int id);
extern char D_0045E368[];
extern char D_0045E378[];

extern "C" void cFEStateProfileLoad_initCreateScreen(void* self)
{
    cUIThing* t = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E318));
    t->setVisible(1);
    cUIText_setUnicodeStringByID((cUIText*)t, GetHashValue32(D_0045E368));
    cUIThing* u = (cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E348));
    u->setVisible(1);
    cUIText_setUnicodeStringByID((cUIText*)u, GetHashValue32(D_0045E378));
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D0)))->setVisible(1);
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1458)))->setVisible(1);
    *(int*)((char*)self + 0x220) = 1;
    *(int*)((char*)self + 0x224) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_00190670);
#ifdef SKIP_ASM
struct sProfile_0670 {
    char pad[0x220];
    int f220;
    int f224;
};

extern "C" void func_00190670(void* self)
{
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E330)))->setVisible(1);
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E358)))->setVisible(1);
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D8)))->setVisible(1);
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1460)))->setVisible(0);
    ((sProfile_0670*)self)->f220 = 0;
    ((sProfile_0670*)self)->f224 = 1;
    *(int*)((char*)func_00227F80(D_004A28A8) + 0x11C) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_00190768);
#ifdef SKIP_ASM
extern "C" void func_00190768(void* self)
{
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E318)))->setVisible(1);
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045E348)))->setVisible(1);
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A15D0)))->setVisible(1);
    ((cUIThing*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1458)))->setVisible(1);
    *(int*)((char*)self + 0x220) = 1;
    *(int*)((char*)self + 0x224) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/festateprofile", func_00190858);
#ifdef SKIP_ASM
extern void* D_0046B160[];
extern "C" void* func_0039E2A0(void *, int);
extern "C" unsigned char func_001A1CD0(void* self, int a1);

extern "C" void* func_00190858(void* self, int a1, int a2)
{
    signed char idx = a2;
    func_0039E2A0(self, a1);
    *(void***)((char*)self + 0x8) = D_0046B160;
    *(int*)((char*)self + 0xC) = 0xF;
    *(signed char*)((char*)self + 0x44) = idx;
    *(char*)((char*)self + 0x15) = func_001A1CD0(**(void***)((char*)self + 0x10), idx);
    return self;
}
#endif

