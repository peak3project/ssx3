#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

struct sColor_200288 {
    float r, g, b, a;
    sColor_200288(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
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
    virtual void setStatic(int v);
    virtual void setVisible(int v);
    virtual void v10();
    virtual int v11(const sColor_200288& c);
};

//100%
INCLUDE_ASM("fe/ovstaterewardslist", cOVStateRewardsList_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void func_0020A380(void* self);
extern char D_004704B8[];

extern "C" void cOVStateRewardsList_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004704B8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_0020A380(self);
}
#endif

//100%
INCLUDE_ASM("fe/ovstaterewardslist", func_00200288);
#ifdef SKIP_ASM
extern "C" void func_0039F400(void* list, void* item);

extern "C" void func_00200288(void* self, cUIThing* item, int msg)
{
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        item->v11(sColor_200288(1.0f, 1.0f, 0.0f, 0.0f));
        void* r = 0;
        if (*(int*)((char*)item + 0x18) == 1) {
            void* obj = **(void***)((char*)self + 0x10);
            sVEntry<void*(void*, void*, int)>* vt = *(sVEntry<void*(void*, void*, int)>**)((char*)obj + 4);
            r = vt[4].fn((char*)obj + vt[4].delta, self, 1);
        }
        func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        break;
    }
    case 6: {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry<void*(void*, void*, int)>* vt = *(sVEntry<void*(void*, void*, int)>**)((char*)obj + 4);
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
INCLUDE_ASM("fe/ovstaterewardslist", func_00200388);
#ifdef SKIP_ASM
struct sRewardDesc_0388 {
    int w[0x6C / 4];
};
extern sRewardDesc_0388 D_004781D0[][4];
extern sRewardDesc_0388 D_004786E0[][5];
extern sRewardDesc_0388 D_00478D38[][8];

extern "C" sRewardDesc_0388 func_00200388(int a, int b, int kind)
{
    if (kind == 0) {
        return D_004781D0[a][b];
    } else if (kind == 1) {
        return D_004786E0[a][b];
    } else if (kind == 2) {
        return D_00478D38[a][b];
    }
    return D_004781D0[0][0];
}
#endif

//100%
INCLUDE_ASM("fe/ovstaterewardslist", func_002006B8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00144BC0(void* iface);
extern unsigned int D_004A2594;
extern int D_004A25A4;

extern "C" void func_002006B8(void* self)
{
    if (D_004A2594 >= 2) {
        D_004A25A4 = *(int*)((char*)func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0)) + 0x54);
    }
}
#endif

