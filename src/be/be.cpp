#include "common.h"

//100%
INCLUDE_ASM("be/be", cBE_getBE);
#ifdef SKIP_ASM
struct sBEInterface;
extern sBEInterface* D_005308A8[];
extern int D_004A11F4;
extern void* D_004A11F8;
extern int* D_004A11EC;
extern int D_004A11F0;
extern int* D_004A1250;
extern char D_004A1200[];
extern char D_0045A638[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00149860(void* mem);
void* cBEPreRaceState_getState(void* self);
void* cBERaceState_getState(void* self);
void* cBEPostRaceState_getState(void* self);

class cBEStateV_getBE
{
public:
    char pad_0x00[0x4];
    virtual void v1();
    virtual void v2();
    virtual void leave();
    virtual void enter();
};

extern "C" void* cBE_getBE()
{
    if (D_004A11EC == 0)
    {
        D_004A11EC = (int*)cMemMan_alloc(4, D_004A1200, 0, 0);
        D_004A11F8 = func_00149860(cMemMan_alloc(1, D_0045A638, 0, 0));
        D_005308A8[0] = (sBEInterface*)cBEPreRaceState_getState((void*)0);
        D_005308A8[1] = (sBEInterface*)cBERaceState_getState((void*)1);
        D_005308A8[2] = (sBEInterface*)cBEPostRaceState_getState((void*)2);
        D_004A11F4 = 0;
        ((cBEStateV_getBE*)D_005308A8[0])->enter();
        D_004A11F0 = 1;
        D_004A1250 = D_004A11EC;
    }
    return D_004A11EC;
}
#endif

INCLUDE_ASM("be/be", func_0014DD48);

struct sBEInterfaceVTable {
    char pad_0x00[0x8];
    short field_0x8;
    char pad_0xA[2];
    void* (*fn)(void*);
};

struct sBEInterface {
    char pad_0x00[0x4];
    sBEInterfaceVTable* vtable;
};

extern sBEInterface* D_005308A8[];
extern int D_004A11F4;

//100%
INCLUDE_ASM("be/be", cBE_getInterface__Fv);
#ifdef SKIP_ASM
class cBEInterfaceV_getInterface
{
public:
    char pad_0x00[0x4];
    virtual void* getInterface(int kind);
};

// PORT: callers pass (be, kind); the mangled name __Fv is a guess. The kind is forwarded
// to the current state's virtual getInterface.
void* cBE_getInterface_impl(void* be, int kind) __asm__("cBE_getInterface__Fv");

void* cBE_getInterface_impl(void* be, int kind)
{
    return ((cBEInterfaceV_getInterface*)D_005308A8[D_004A11F4])->getInterface(kind);
}
#endif

//100%
INCLUDE_ASM("be/be", func_0014DD98);
#ifdef SKIP_ASM
class cBEStateV_0014DD98
{
public:
    char pad_0x00[0x4];
    virtual void v1();
    virtual void shutdown();
};
extern void* D_004A11F8;
extern int* D_004A11EC;
extern int D_004A11F0;
extern "C" void func_001499A8(void* p, int a);
void operator_delete(int* ptr);

extern "C" void func_0014DD98(void)
{
    if (D_004A11F8)
        func_001499A8(D_004A11F8, 3);
    ((cBEStateV_0014DD98*)D_005308A8[0])->shutdown();
    ((cBEStateV_0014DD98*)D_005308A8[1])->shutdown();
    ((cBEStateV_0014DD98*)D_005308A8[2])->shutdown();
    operator_delete(D_004A11EC);
    D_004A11EC = 0;
    D_004A11F0 = 0;
}
#endif

//100%
INCLUDE_ASM("be/be", func_0014DE28);
#ifdef SKIP_ASM
extern void* D_004A11F8;
extern "C" void func_00149A88(void* p, char c);
extern "C" void func_0014FC40(char c);

extern "C" void func_0014DE28(void* self, char c)
{
    if (D_004A11F8)
        func_00149A88(D_004A11F8, c);
    func_0014FC40(c);
}
#endif

//100%
INCLUDE_ASM("be/be", cBE_setState);
#ifdef SKIP_ASM
class cBEStateV_setState
{
public:
    char pad_0x00[0x4];
    virtual void v1();
    virtual void v2();
    virtual void leave();
    virtual void enter();
};

extern "C" void cBE_setState(int state)
{
    if (D_004A11F4 != state)
    {
        ((cBEStateV_setState*)D_005308A8[D_004A11F4])->leave();
        D_004A11F4 = state;
        ((cBEStateV_setState*)D_005308A8[state])->enter();
    }
}
#endif

INCLUDE_ASM("be/be", func_0014DEE8);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/be", func_0014DF08);
#ifdef SKIP_ASM
class cBEReplayStream {
public:
    virtual void write(void* data, int size);
    virtual void read(void* data, int size);
};

class cBEReplayIface {
public:
    char pad_0x00[0xC];
    virtual void v1();
    virtual void v2();
    virtual void writeToReplayFrame(cBEReplayStream* s);
    virtual void readFromReplayFrame(cBEReplayStream* s);
};

// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
cBEReplayIface* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");

extern "C" void func_0014DF08(void* self, cBEReplayStream* s)
{
    s->write(&D_004A11F4, 4);
    for (int i = 0; i < 14; i++)
    {
        if (cBE_getInterface_Fv(self, i))
            cBE_getInterface_Fv(self, i)->writeToReplayFrame(s);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/be", cBE_readFromReplayFrame);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
cBEReplayIface* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");

extern "C" void cBE_readFromReplayFrame(void* self, cBEReplayStream* s)
{
    s->read(&D_004A11F4, 4);
    for (int i = 0; i < 14; i++)
    {
        if (cBE_getInterface_Fv(self, i))
            cBE_getInterface_Fv(self, i)->readFromReplayFrame(s);
    }
}
#endif

//100%
INCLUDE_ASM("be/be", func_0014E048);
#ifdef SKIP_ASM
extern "C" int func_0014E048()
{
    return 0xBB78;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("be/be", func_0014E050);
#ifdef SKIP_ASM
extern "C" void func_0014A188(void* buf);
// PORT: func_0014E048 is declared () in this unit but called with the BE object here.
int func_0014E048_self(void* be) __asm__("func_0014E048");
extern "C" int func_003E62D0(void* buf, int size, int seed);
extern "C" void* memcpy(void*, const void*, unsigned int);

extern "C" void func_0014E050(void* self, char* buf)
{
    func_0014A188(buf);
    int crc = func_003E62D0(buf, func_0014E048_self(self) - 4, 0xFBEA);
    char* p = buf + (func_0014E048_self(self) - 4);
    memcpy(p, &crc, 4);
}
#endif

extern "C" void* func_0014A5E0(int);

//100%
INCLUDE_ASM("be/be", func_0014E0C0__FPvi);
#ifdef SKIP_ASM
void* func_0014E0C0(void* self, int a1)
{
    return func_0014A5E0(a1);
}
#endif

