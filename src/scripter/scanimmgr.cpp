#include "common.h"

//100%
INCLUDE_ASM("scripter/scanimmgr", cScriptAnimBankManager_cScriptAnimBankManager);
#ifdef SKIP_ASM
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_004825D8[];
extern const char D_00481A80[];

struct sScAnimBank53B8 {
    int id;         // 0x0
    int index;      // 0x4
    int a;          // 0x8
    int b;          // 0xC
    int c;          // 0x10
};

struct cScriptAnimBankManager53B8 {
    int flags;                  // 0x0
    int count;                  // 0x4
    sScAnimBank53B8* banks;     // 0x8
    void* vtable;               // 0xC
};

extern "C" cScriptAnimBankManager53B8* cScriptAnimBankManager_cScriptAnimBankManager(
    cScriptAnimBankManager53B8* self, int flags, int count, int base)
{
    //S
    self->vtable = D_004825D8;
    self->flags = flags;
    self->count = count;
    //E
    self->banks = (sScAnimBank53B8*)operator_new__FUi(count * sizeof(sScAnimBank53B8), D_00481A80, flags, 0);
    int idx = base;
    for (int i = 0; i < self->count; i++) {
        self->banks[i].id = -1;
        self->banks[i].index = idx++;
        self->banks[i].a = 0;
        self->banks[i].b = 0;
        self->banks[i].c = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/scanimmgr", func_00275498);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_00275698(void* self);
extern char D_004825D8[];

extern "C" void func_00275498(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_004825D8;
    func_00275698(self);
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
INCLUDE_ASM("scripter/scanimmgr", cScriptAnimBankManager_LinkBank);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00311220(void* mem, void* data);
extern const char D_00481A98[];
extern const char D_00481AA8[];
extern void** D_004A3DF8;

struct sScLinkEntry {
    int id;             // 0x0
    int slot;           // 0x4, low byte = bank table index
    void* data;         // 0x8
    int used;           // 0xC
    int* map;           // 0x10
};

struct sScLinkList {
    int flags;              // 0x0
    int count;              // 0x4
    sScLinkEntry* entries;  // 0x8
};

struct sScBankHdr {
    short field_0x0;
    short count;            // 0x2
};

struct sScBankItem {
    void* ptr;              // 0x0
    char pad_0x4[0x10];
};

struct sScBank {
    int field_0x0;
    sScBankHdr* hdr;        // 0x4
    sScBankItem* items;     // 0x8
};

struct sAnimList;
extern "C" void* func_00275718(sAnimList* self, int id);
extern "C" void* func_002757F0_v(void* self) __asm__("func_002757F0");

extern "C" int cScriptAnimBankManager_LinkBank(sScLinkList* self, int id, void* data)
{
    sScLinkEntry* e = (sScLinkEntry*)func_00275718((sAnimList*)self, id);
    if (e == 0) {
        e = (sScLinkEntry*)func_002757F0_v(self);
        e->id = id;
        e->data = data;
        sScBank* bank = (sScBank*)func_00311220(cMemMan_alloc(0x18, D_00481A98, self->flags, 0), e->data);
        int n = bank->hdr->count;
        e->used = 0;
        for (int i = 0; i < n; i++) {
            if (bank->items[i].ptr != 0) {
                e->used++;
            }
        }
        if (e->used != 0) {
            e->map = (int*)operator_new__FUi(e->used * 4, D_00481AA8, self->flags, 0);
            int k = 0;
            for (int i = 0; i < n; i++) {
                if (bank->items[i].ptr != 0) {
                    e->map[k++] = i;
                }
            }
        }
        void** tbl = D_004A3DF8;
        void** slot = &tbl[*(unsigned char*)&e->slot];
        *slot = bank;
    }
    return e->slot;
}
#endif

//100%
INCLUDE_ASM("scripter/scanimmgr", func_00275650);
#ifdef SKIP_ASM
struct sScAnimVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sAnimList;
extern "C" void* func_00275718(sAnimList* self, int id);

extern "C" void func_00275650(sAnimList* self, int id)
{
    void* p = func_00275718(self, id);
    if (p != 0) {
        sScAnimVEntry* vt = *(sScAnimVEntry**)((char*)self + 0xC);
        vt[2].fn((char*)self + vt[2].delta, p);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/scanimmgr", func_00275698);
#ifdef SKIP_ASM
struct sDmEntry275698 {
    char pad_0x00[0x8];
    int used;
    char pad_0x0C[0x8];
};

struct sDmVEntry275698 {
    short delta;
    short index;
    void (*fn)(void*, sDmEntry275698*);
};

struct sDmTable275698 {
    int unk_0x0;
    int count;
    sDmEntry275698* entries;
    sDmVEntry275698* vt;
};

extern "C" void func_00275698(void* self_)
{
    sDmTable275698* self = (sDmTable275698*)self_;
    int i;
    for (i = 0; i < self->count; i++) {
        if (self->entries[i].used != 0) {
            self->vt[2].fn((char*)self + self->vt[2].delta, &self->entries[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/scanimmgr", func_00275718);
#ifdef SKIP_ASM
struct sAnimEntry {
    int id;
    int unk4;
    void* data;
    int unkC;
    int unk10;
};

struct sAnimList {
    int unk0;
    int count;
    sAnimEntry* entries;
};

extern "C" void* func_00275718(sAnimList* self, int id)
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
INCLUDE_ASM("scripter/scanimmgr", func_00275760);
#ifdef SKIP_ASM
extern "C" void func_00311110(void** tbl);
extern "C" void func_003112C8(void* self, int flags);
void cMemMan_free(void*);
extern void** D_004A3DF8;

extern "C" void func_00275760(void* self, sAnimEntry* e)
{
    void** tbl = D_004A3DF8;
    void** slot = &tbl[*(unsigned char*)&e->unk4];
    void* obj = *slot;
    *slot = 0;
    func_00311110(tbl);
    if (obj != 0) {
        func_003112C8(obj, 3);
    }
    if (e->unkC != 0 && e->unk10 != 0) {
        cMemMan_free((void*)e->unk10);
    }
    //PSTART
    e->id = -1;
    e->unkC = 0;
    e->data = 0;
    e->unk10 = 0;
    //PEND
}
#endif

//100%
INCLUDE_ASM("scripter/scanimmgr", func_002757F0);
#ifdef SKIP_ASM
extern "C" sAnimEntry* func_002757F0(sAnimList* self)
{
    for (int i = 0; i < self->count; i++) {
        if (self->entries[i].data == 0) {
            return &self->entries[i];
        }
    }
    return 0;
}
#endif

