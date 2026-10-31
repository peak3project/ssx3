#include "common.h"

//100%
INCLUDE_ASM("scripter/scsndmgr", cScriptSoundBankManager_cScriptSoundBankManager);
#ifdef SKIP_ASM
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_00482240[];
extern const char D_00481FB0[];

struct sScSndBank3450 {
    int id;         // 0x0
    int index;      // 0x4
    int a;          // 0x8
};

struct cScriptSoundBankManager3450 {
    int flags;                  // 0x0
    int count;                  // 0x4
    sScSndBank3450* banks;      // 0x8
    void* vtable;               // 0xC
};

extern "C" cScriptSoundBankManager3450* cScriptSoundBankManager_cScriptSoundBankManager(
    cScriptSoundBankManager3450* self, int flags, int count, int base)
{
    self->vtable = D_00482240;
    self->flags = flags;
    self->count = count;
    self->banks = (sScSndBank3450*)operator_new__FUi(count * sizeof(sScSndBank3450), D_00481FB0, flags, 0);
    int idx = base;
    for (int i = 0; i < self->count; i++) {
        self->banks[i].id = -1;
        self->banks[i].index = idx++;
        self->banks[i].a = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283518);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_00283658(void* self);
extern char D_00482240[];

extern "C" void func_00283518(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_00482240;
    func_00283658(self);
    void* p = *(void**)((char*)self + 0x8);
    if (p != 0) {
        cMemMan_free(p);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283580);
#ifdef SKIP_ASM
struct sSndEntry;
struct sSndList;
extern "C" sSndEntry* func_002836D8(sSndList* self, int id);
extern "C" sSndEntry* func_00283760(sSndList* self);
extern "C" void* func_0028B180();
extern "C" void func_0028BE60(void* bank, int handle, void* data, int b);

extern "C" int func_00283580(sSndList* self, int id, void* data, int b)
{
    char* e = (char*)func_002836D8(self, id);
    if (e == 0) {
        e = (char*)func_00283760(self);
        *(int*)(e + 0x0) = id;
        *(void**)(e + 0x8) = data;
        func_0028BE60(**(void***)((char*)func_0028B180() + 0x118), *(int*)(e + 0x4), data, b);
    }
    return *(int*)(e + 0x4);
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283610);
#ifdef SKIP_ASM
struct sScSndVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sSndEntry;
struct sSndList;
extern "C" sSndEntry* func_002836D8(sSndList* self, int id);

extern "C" void func_00283610(sSndList* self, int id)
{
    sSndEntry* p = func_002836D8(self, id);
    if (p != 0) {
        sScSndVEntry* vt = *(sScSndVEntry**)((char*)self + 0xC);
        vt[2].fn((char*)self + vt[2].delta, p);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283658);
#ifdef SKIP_ASM
struct sDmEntry283658 {
    char pad_0x00[0x8];
    int used;
    
};

struct sDmVEntry283658 {
    short delta;
    short index;
    void (*fn)(void*, sDmEntry283658*);
};

struct sDmTable283658 {
    int unk_0x0;
    int count;
    sDmEntry283658* entries;
    sDmVEntry283658* vt;
};

extern "C" void func_00283658(void* self_)
{
    sDmTable283658* self = (sDmTable283658*)self_;
    int i;
    for (i = 0; i < self->count; i++) {
        if (self->entries[i].used != 0) {
            self->vt[2].fn((char*)self + self->vt[2].delta, &self->entries[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_002836D8);
#ifdef SKIP_ASM
struct sSndEntry {
    int id;
    int unk4;
    void* data;
};

struct sSndList {
    int unk0;
    int count;
    sSndEntry* entries;
};

extern "C" sSndEntry* func_002836D8(sSndList* self, int id)
{
    for (int i = 0; i < self->count; i++) {
        if (self->entries[i].data != 0 && self->entries[i].id == id) {
            return &self->entries[i];
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283720);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_0028BE90(void* bank, int handle);

extern "C" void func_00283720(sSndList* self, sSndEntry* e)
{
    func_0028BE90(**(void***)((char*)func_0028B180() + 0x118), e->unk4);
    e->id = -1;
    e->data = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283760);
#ifdef SKIP_ASM
extern "C" sSndEntry* func_00283760(sSndList* self)
{
    for (int i = 0; i < self->count; i++) {
        if (self->entries[i].data == 0) {
            return &self->entries[i];
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283798);
#ifdef SKIP_ASM
extern char D_00482228[];

extern "C" void* func_00283798(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(void**)((char*)self + 0x18) = D_00482228;
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_002837C8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_00283818(void* self);
extern char D_00482228[];

extern "C" void func_002837C8(void* self, int flags)
{
    *(void**)((char*)self + 0x18) = D_00482228;
    func_00283818(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/scsndmgr", func_00283818);
#ifdef SKIP_ASM
extern "C" void func_00253418(void* p, int flags);
extern "C" void* func_0028B180();
extern "C" void func_0029CE70(void* p);
extern "C" void func_002EA860(void* p);
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_004428F0[];
extern char* D_004A28A8;

class cWorld_3818 {
public:
    char pad_0x0[0x10D8];
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
    virtual void v40(int a);
};

extern cWorld_3818* D_004A289C;

extern "C" void func_00283818(void* self)
{
    char* s = (char*)self;
    if (*(void**)(s + 0x0) != 0) {
        func_00253418(*(void**)(s + 0x0), 3);
        if (*(int*)(s + 0x4) != 0) {
            D_004A2A50 = D_004428F0[D_005366E8[--D_004A2A54]];
            func_0029CE70(func_0028B180());
            D_004A289C->v40(*(int*)(s + 0x10));
            if (*(int*)(s + 0x14) != 0) {
                *(int*)(s + 0x14) = 0;
                func_002EA860(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x64));
            }
        }
    }
    *(int*)(s + 0x0) = 0;
    *(int*)(s + 0x4) = 0;
    *(int*)(s + 0x8) = 0;
    *(int*)(s + 0xC) = 0;
}
#endif

