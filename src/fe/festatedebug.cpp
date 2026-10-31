#include "common.h"

//100%
INCLUDE_ASM("fe/festatedebug", cScreenKeyboard_initScreenKeyboard);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* s);
extern "C" void func_001805D8(void* self, char* s);
extern "C" void func_001809B0(void* self, int id, char* buf);
extern "C" void func_00180A90(void* self, int id, char* buf);
extern char D_0045D570[];
extern char D_0045D588[];
extern char D_0045D5A0[];
extern char D_0045D5B0[];
extern char D_0045D5C0[];
extern char D_0045D5D0[];
extern char D_0045D5E0[];
extern char D_0045D5F0[];
extern char D_004A1370[];
extern char D_004A1378[];
extern char D_004A1380[];
extern char D_004A1388[];

class cUIObjK180B60 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int on);
};

extern "C" void cScreenKeyboard_initScreenKeyboard(char* self, void* screen)
{
    cUIObjK180B60* t;
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D570));
    if (t != 0)
    {
        t->setVisible(1);
        cUIText_setAsciiString((cUIText*)t, D_004A1370);
    }
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D588));
    if (t != 0)
    {
        t->setVisible(1);
        cUIText_setAsciiString((cUIText*)t, D_004A1378);
    }
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D5A0));
    if (t != 0)
    {
        t->setVisible(1);
        cUIText_setAsciiString((cUIText*)t, D_004A1380);
    }
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D5B0));
    if (t != 0)
        t->setVisible(0);
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D5C0));
    if (t != 0)
        t->setVisible(0);
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D5D0));
    if (t != 0)
        t->setVisible(0);
    char name[0x20];
    char ch[2];
    ch[1] = 0;
    ch[0] = 'A';
    for (int i = 0; i < 26; i++)
    {
        func_001809B0(self, i + 10, name);
        t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(name));
        if (t != 0)
            cUIText_setAsciiString((cUIText*)t, ch);
        func_00180A90(self, i + 10, name);
        t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(name));
        if (t != 0)
            t->setVisible(0);
        ch[0]++;
    }
    ch[0] = '0';
    for (int j = 0; j < 10; j++)
    {
        func_001809B0(self, j, name);
        t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(name));
        if (t != 0)
            cUIText_setAsciiString((cUIText*)t, ch);
        func_00180A90(self, j, name);
        t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(name));
        if (t != 0)
            t->setVisible(0);
        ch[0]++;
    }
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D5E0));
    if (t != 0)
        t->setVisible(1);
    func_001805D8(self, D_004A1388);
    t = (cUIObjK180B60*)cUIScreen_getObjectByHashName(screen, GetHashValue32(D_0045D5F0));
    if (t != 0)
        cUIText_setAsciiString((cUIText*)t, self + 0xEC);
}
#endif

//100%
INCLUDE_ASM("fe/festatedebug", func_00180EF0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_00180A90(void* self, int id, char* buf);
extern "C" void func_00180618(void* self);
extern "C" void func_00180678(void* self);
extern "C" void func_001806D8(void* self);
extern "C" void func_00180768(void* self);
extern "C" void func_00180840(void* self);
extern "C" int func_001807C8(void* self);

struct sDbgObj_180EF0 {
    char pad0[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};
struct sDbgInput_180EF0 {
    char pad0[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
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
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual int v26();
};
struct sDbgState_180EF0 {
    char pad0[0x170];
    int sel;    // 0x170
};

extern "C" int func_00180EF0(sDbgState_180EF0* self, sDbgInput_180EF0* in)
{
    char buf[0x20];
    func_00180A90(self, self->sel, buf);
    sDbgObj_180EF0* o = (sDbgObj_180EF0*)cUIScreen_getObjectByHashName(self, GetHashValue32(buf));
    if (o) {
        o->v09(0);
    }
    if (in->v19()) {
        func_00180618(self);
    } else if (in->v20()) {
        func_00180678(self);
    } else if (in->v17()) {
        func_001806D8(self);
    } else if (in->v18()) {
        func_00180768(self);
    } else if (in->v05()) {
        func_00180840(self);
    } else if (in->v26()) {
        func_001807C8(self);
    }
    func_00180A90(self, self->sel, buf);
    o = (sDbgObj_180EF0*)cUIScreen_getObjectByHashName(self, GetHashValue32(buf));
    if (o) {
        o->v09(1);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/festatedebug", func_00181090);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void* self, void* owner);
extern "C" unsigned char func_001A1CD0(void* self, signed char a1);
extern void* D_0046D000[];

extern "C" void* func_00181090(void* self, void* owner, int count)
{
    signed char n = count;
    int i = 0;
    unsigned char mask = 0xFF;
    func_0039E2A0(self, owner);
    *(void***)((char*)self + 0x8) = D_0046D000;
    *(int*)((char*)self + 0xC) = 9;
    *(int*)((char*)self + 0x54) = 1;
    *(signed char*)((char*)self + 0x44) = n;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    void* mgr = **(void***)((char*)self + 0x10);
    for (; i < n; i++) {
        mask &= ~func_001A1CD0(mgr, i);
    }
    *(unsigned char*)((char*)self + 0x15) = mask;
    return self;
}
#endif

