#include "common.h"

//100%
INCLUDE_ASM("sound/bankmanager", cBankInstance_AllocMem);
#ifdef SKIP_ASM
extern char* D_004A3614;
extern char D_00482998[];
extern "C" void* func_00252FA0(void* a0, int a1, int a2);

class cSndStream_B588 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int alloc(int size);
};

// PORT: the unit declares this void* (a caller forwards its $v0), but no value is returned.
extern "C" void* cBankInstance_AllocMem(void* self, int size, int extra, int tag)
{
    if (size != 0 || extra != 0) {
        *(int*)((char*)self + 0x8) = 1;
        if (extra != 0) {
            int id = (**(cSndStream_B588***)(D_004A3614 + 0x1D8))->alloc(extra);
            if (id >= 0) {
                *(int*)((char*)self + 0xC) = id;
                *(int*)((char*)self + 0x8) = 2;
            } else if (id == -3) {
                size += extra;
            }
        }
        *(int*)((char*)self + 0x14) = size;
        *(void**)((char*)self + 0x10) = func_00252FA0(D_00482998, size, tag);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B650);
#ifdef SKIP_ASM
extern "C" void func_0028B528(void*);
extern "C" void* func_002523A8(void* self);
extern char* D_004A3614;

class cSndStream_B650 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void stop(int id);
};

extern "C" void func_0028B650(void* self)
{
    func_0028B528(self);
    int state = *(int*)((char*)self + 0x8);
    if (state != 0) {
        if (state == 2) {
            (**(cSndStream_B650***)(D_004A3614 + 0x1D8))->stop(*(int*)((char*)self + 0xC));
            *(int*)((char*)self + 0xC) = -1;
        }
        func_002523A8(*(void**)((char*)self + 0x10));
        *(int*)((char*)self + 0x10) = 0;
        *(int*)((char*)self + 0x14) = 0;
        *(int*)((char*)self + 0x8) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B6C8);
#ifdef SKIP_ASM
extern "C" void func_0028B6C8(void *dst, void *src) {
    int flag;

    if (*(void **)((char*)src + 0x18) != 0) {
        *(void **)((char*)dst + 0x18) = src;
        *(void **)((char*)dst + 0x1C) = *(void **)((char*)src + 0x1C);
        *(void **)((char*)src + 0x1C) = dst;
        *(void **)((char*)*(void **)((char*)dst + 0x1C) + 0x18) = dst;
    } else {
        *(void **)((char*)src + 0x18) = dst;
        *(void **)((char*)src + 0x1C) = dst;
        *(void **)((char*)dst + 0x18) = src;
        *(void **)((char*)dst + 0x1C) = src;
    }
    flag = *(int *)((char*)src + 8);
    if (flag != 0) {
        *(int *)((char*)dst + 8) = flag;
        *(int *)((char*)dst + 0x10) = *(int *)((char*)src + 0x10);
        *(int *)((char*)dst + 0x14) = *(int *)((char*)src + 0x14);
        *(int *)((char*)dst + 0xC) = *(int *)((char*)src + 0xC);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B730);
#ifdef SKIP_ASM
struct sBankNode {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    sBankNode* next;
    sBankNode* prev;
};

extern "C" void func_0028B730(sBankNode* self)
{
    if (self->next != 0) {
        self->unkC = -1;
        self->unk10 = 0;
        self->unk14 = 0;
        self->unk8 = 0;
        if (self->next == self->prev) {
            self->next->next = 0;
            self->next->prev = 0;
        } else {
            self->next->prev = self->prev;
            self->prev->next = self->next;
        }
        self->prev = 0;
        self->next = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B788);
#ifdef SKIP_ASM
extern "C" void func_0028B7E0(void*);
extern "C" int func_003B6098(void* sema, int a1);

extern "C" void func_0028B788(void* self, int a1, int a2)
{
    func_0028B7E0(self);
    *(int*)((char*)self + 0x10) = a1;
    *(int*)((char*)self + 0x14) = a2;
    func_003B6098((char*)self + 0x4, a1);
    *(int*)self = 1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B7E0);
#ifdef SKIP_ASM
extern "C" int func_003B6300(int id);

extern "C" void func_0028B7E0(void* self)
{
    *(int*)self = 0;
    if (*(int*)((char*)self + 0x4) != -1) {
        func_003B6300(*(int*)((char*)self + 0x4));
        *(int*)((char*)self + 0x4) = -1;
    }
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B830);
#ifdef SKIP_ASM
extern "C" int func_004165A8(void*, void*);

extern "C" int func_0028B830(void* self, void* name)
{
    int s = *(int*)self;
    if (s != 1) {
        return 0;
    }
    if (func_004165A8(name, (char*)self + 0x20) != 0) {
        s = 0;
    }
    return s;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B878);
#ifdef SKIP_ASM
extern "C" void func_0028B528(void*);
extern "C" void func_0028B2D0(void* self);
extern char* D_004A3614;

class cSndStream_B878 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int id);
    virtual void v6(int id);
};

extern "C" void func_0028B878(void* self)
{
    func_0028B528(self);
    func_0028B2D0(self);
    *(int*)self = 2;
    if (*(int*)((char*)self + 0x8) == 2) {
        (**(cSndStream_B878***)(D_004A3614 + 0x1D8))->v6(*(int*)((char*)self + 0xC));
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", cBankInstance_OnAsyncMainMemAlloc);
#ifdef SKIP_ASM
extern "C" void* func_00252FA0(void* a0, int a1, int a2);
extern char D_004829A8[];

// PORT: real body returns the buffer; a later caller in this unit declares it void(void*, int, int)
void* cBankInstance_OnAsyncMainMemAlloc_impl(void* self, int size, int flags) __asm__("cBankInstance_OnAsyncMainMemAlloc");

void* cBankInstance_OnAsyncMainMemAlloc_impl(void* self, int size, int flags)
{
    if (*(int*)((char*)self + 0x8) == 0) {
        *(void**)((char*)self + 0x10) = func_00252FA0(D_004829A8, size, flags);
        *(int*)((char*)self + 0x14) = size;
    }
    return *(void**)((char*)self + 0x10);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B928__FPv);
#ifdef SKIP_ASM
int func_0028B928(void* self)
{
    return *(int*)((char*)self + 0x14);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028B930);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern char* D_004A3614;

class cSndStream_B930 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int id);
    virtual void v6(int id);
    virtual void v7();
};

// PORT: name is passed as int (matches the unit's 6-int caller declaration); d, e unused.
extern "C" void func_0028B930(void* self, int id, int flag, int name, int d, int e)
{
    (**(cSndStream_B930***)(D_004A3614 + 0x1D8))->v7();
    *(int*)((char*)self + 0x4) = id;
    if (flag == 0) {
        *(int*)self = 1;
    } else {
        *(int*)self = 0;
    }
    strcpy((char*)self + 0x20, (const char*)name);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", cBankManager_cBankManager);
#ifdef SKIP_ASM
extern "C" void* cBankMonitor_cBankMonitor(void* self, int a1, int heap);
extern "C" void* func_0028A058(void* self);
extern "C" void* func_0028B248(void* self);
extern "C" void* func_002ADE88(void* self, int heap);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char* D_004A3614;
extern const char D_004829B8[];
extern void* D_00483B48[];
extern void* D_00483AD8[];

struct sBmVEntry {
    short delta;
    short index;
    void* fn;
};
struct sBmVtbl {
    sBmVEntry e[4];
} __attribute__((aligned(8)));
extern const sBmVtbl D_00483AB8;

struct sBmBank {
    char pad_0x0[0x60];
    sBmBank() { func_0028B248(this); }
    void operator delete[](void* p, unsigned int size);
};

struct sBankManager {
    char pad_0x0[0x1D4];
    void** vtbl;                // 0x1D4
    char* monitor;              // 0x1D8
    char pad_0x1DC[0xAB0 - 0x1DC];
    void** vtbl2;               // 0xAB0
    char pad_0xAB4[0xAC8 - 0xAB4];
    int count;                  // 0xAC8
    sBmBank* banks;             // 0xACC
    char embedded[0x4];         // 0xAD0
};

extern "C" sBankManager* cBankManager_cBankManager(sBankManager* self, int embedded, int count, int heap)
{
    if (embedded) {
        self->monitor = self->embedded;
        func_002ADE88(self->embedded, heap);
    }
    func_0028A058(self);
    cBankMonitor_cBankMonitor(&self->monitor, 0, heap);
    *(const sBmVtbl**)(self->monitor + 4) = &D_00483AB8;
    if (!embedded) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sBmVtbl vt = D_00483AB8;
        *(sBmVtbl**)(self->monitor + 4) = &vt;
        char* base = self->monitor - 0xAD0;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483AB8.e[1].delta + d;
    }
    self->count = count;
    self->vtbl2 = D_00483B48;
    self->vtbl = D_00483AD8;
    sBmBank** slot = &self->banks;
    *slot = new (D_004829B8, 0, 0) sBmBank[count];
    D_004A3614 = (char*)self;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028BB10);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_0028A148(void* self, int flags);
extern "C" void func_0028B278(void* self, int flags);
extern "C" void func_002ACE40(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern char* D_004A3614;
extern void* D_00483B48[];
extern void* D_00483AD8[];

struct sBmVEntryBB10 {
    short delta;
    short index;
    void* fn;
};
struct sBmVtblBB10 {
    sBmVEntryBB10 e[4];
} __attribute__((aligned(8)));
extern const sBmVtblBB10 D_00483AB8_BB10 __asm__("D_00483AB8");

struct sBmBankBB10 {
    char pad_0x0[0x60];
};

struct sBankManagerBB10 {
    char pad_0x0[0x1D4];
    void** vtbl;                // 0x1D4
    char* monitor;              // 0x1D8
    char pad_0x1DC[0xAB0 - 0x1DC];
    void** vtbl2;               // 0xAB0
    char pad_0xAB4[0xAC8 - 0xAB4];
    int count;                  // 0xAC8
    sBmBankBB10* banks;         // 0xACC
};

extern "C" void func_0028BB10(sBankManagerBB10* self, int flags)
{
    self->vtbl2 = D_00483B48;
    self->vtbl = D_00483AD8;
    *(const sBmVtblBB10**)(self->monitor + 4) = &D_00483AB8_BB10;
    if (flags == 0) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sBmVtblBB10 vt = D_00483AB8_BB10;
        *(sBmVtblBB10**)(self->monitor + 4) = &vt;
        char* base = self->monitor - 0xAD0;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483AB8_BB10.e[1].delta + d;
    }
    D_004A3614 = 0;
    if (self->banks != 0) {
        sBmBankBB10* q = self->banks + ((int*)self->banks)[-4];
        while (self->banks != q) {
            q--;
            func_0028B278(q, 0);
        }
        cMemMan_free((char*)self->banks - 0x10);
    }
    func_002ACE40(&self->monitor, 0);
    func_0028A148(self, 0);
    if (flags & 2) {
        func_002ADEE8(self->monitor, 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BC58);
#ifdef SKIP_ASM
extern "C" void func_0028A728(void* self, int i);
extern "C" void func_0028B320(void* bank, void* id, int a3);

extern "C" void func_0028BC58(void* self, int i, void* id, int a3)
{
    int off = i * 0x60;
    if (func_0028B830((char*)*(void**)((char*)self + 0xACC) + off, id) == 0) {
        func_0028A728(self, i);
        func_0028B320((char*)*(void**)((char*)self + 0xACC) + off, id, a3);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028BCE8);
#ifdef SKIP_ASM
extern "C" void func_0028B528(void*);

extern "C" void func_0028BCE8(void* self, int i)
{
    func_0028B528((char*)*(void**)((char*)self + 0xACC) + i * 0x60);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BD10);
#ifdef SKIP_ASM
extern "C" void func_0028A728(void* self, int i);
extern "C" void func_0028A558(void* self, int i, void* id, int a3, int a4);

struct sBankInst60 { char pad0[8]; int f8; char pad1[0x60 - 0xC]; };

extern "C" void func_0028BD10(void* self, int i, void* id, int a3)
{
    if (func_0028B830((char*)*(void**)((char*)self + 0xACC) + i * 0x60, id) == 0) {
        func_0028A728(self, i);
        func_0028A558(self, i, id, (*(sBankInst60**)((char*)self + 0xACC))[i].f8, a3);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BDA8);
#ifdef SKIP_ASM
extern "C" void* cBankInstance_AllocMem(void* inst, int a, int b, int c);

extern "C" void* func_0028BDA8(void* self, int i, int a, int b, int c)
{
    return cBankInstance_AllocMem((char*)*(void**)((char*)self + 0xACC) + i * 0x60, a, b, c);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BDE0);
#ifdef SKIP_ASM
extern "C" void func_0028B650(void*);

extern "C" void func_0028BDE0(void* self, int i)
{
    func_0028B650((char*)*(void**)((char*)self + 0xACC) + i * 0x60);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028BE08);
#ifdef SKIP_ASM
extern "C" void func_0028B6C8(void *dst, void *src);

extern "C" void func_0028BE08(void* self, int i, int j)
{
    char* base = *(char**)((char*)self + 0xACC);
    func_0028B6C8(base + i * 0x60, base + j * 0x60);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028BE38);
#ifdef SKIP_ASM
extern "C" void func_0028B730(sBankNode* self);

extern "C" void func_0028BE38(void* self, int i)
{
    func_0028B730((sBankNode*)((char*)*(void**)((char*)self + 0xACC) + i * 0x60));
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BE60);
#ifdef SKIP_ASM
extern "C" void func_0028B788(void* inst, int a, int b);

extern "C" void func_0028BE60(void* self, int i, int a, int b)
{
    func_0028B788((char*)*(void**)((char*)self + 0xACC) + i * 0x60, a, b);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028BE90);
#ifdef SKIP_ASM
extern "C" void func_0028B7E0(void*);

extern "C" void func_0028BE90(void* self, int i)
{
    func_0028B7E0((char*)*(void**)((char*)self + 0xACC) + i * 0x60);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BEB8);
#ifdef SKIP_ASM
extern "C" void func_0028B878(void*);

extern "C" void func_0028BEB8(void* self, int i)
{
    func_0028B878((char*)*(void**)((char*)self + 0xACC) + i * 0x60);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BEE0);
#ifdef SKIP_ASM
extern "C" void cBankInstance_OnAsyncMainMemAlloc(void* inst, int a, int b);

extern "C" void func_0028BEE0(void* self, int i, int a, int b)
{
    cBankInstance_OnAsyncMainMemAlloc((char*)*(void**)((char*)self + 0xACC) + i * 0x60, a, b);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BF10);
#ifdef SKIP_ASM
int func_0028B928(void*);

extern "C" void func_0028BF10(void* self, int i)
{
    func_0028B928((char*)*(void**)((char*)self + 0xACC) + i * 0x60);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028BF38);
#ifdef SKIP_ASM
extern "C" void func_0028B930(void* inst, int a, int b, int c, int d, int e);

extern "C" void func_0028BF38(void* self, int i, int a, int b, int c, int d, int e)
{
    func_0028B930((char*)*(void**)((char*)self + 0xACC) + i * 0x60, a, b, c, d, e);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028BF78);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_0028B1B0(void);
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_0028D488(void* self);
extern "C" int func_002B49E0(void* monitor);
extern "C" int func_002B4AF0(void* monitor);
extern "C" void func_00287558(void* self, int on);
// PORT: func_002B4070 takes the 64-bit bank mask as a second argument (64-bit `long`).
extern "C" void func_002B4070_BF78(void* monitor, long mask) __asm__("func_002B4070");

struct sCfg_BF78 {
    int flags;
    int v[(0x288 - 4) / 4];
};
extern sCfg_BF78 D_00535610_BF78 __asm__("D_00535610");

extern "C" void func_0028BF78(char* self, int state)
{
    if (*(int*)(self + 0x608C) == state)
        return;
    *(int*)(self + 0x608C) = state;
    switch (state) {
    case 0: {
        func_002B4070_BF78(self + 0x118, *(long*)(self + 0x518));
        cBE_getInterface_Fv(cBE_getBE(), 4);
        sCfg_BF78 cfg = D_00535610_BF78;
        func_00287558(self, (cfg.flags >> 17) & 1);
        if (func_0028B1B0() == 0)
            return;
        if (*(int*)(self + 0x530) == 0)
            return;
        if ((unsigned int)(func_002B49E0(self + 0x118) - 101) >= 3)
            return;
        func_0028D488(self);
        func_0028CF98(self, 0, 0, -1, 0);
        break;
    }
    case 1:
    case 3: {
        func_002B4070_BF78(self + 0x118, *(long*)(self + 0x6098));
        cBE_getInterface_Fv(cBE_getBE(), 4);
        sCfg_BF78 cfg = D_00535610_BF78;
        func_00287558(self, (cfg.flags >> 17) & 1);
        if (*(long*)(self + 0x6098) == 0)
            return;
        if (func_0028B1B0() == 0)
            return;
        if (*(int*)(self + 0x530) == 0)
            return;
        int st = func_002B49E0(self + 0x118);
        if ((unsigned int)(st - 1) < 3)
            return;
        if (func_002B4AF0(self + 0x118) != 0 && st != 0x12D)
            return;
        func_0028D488(self);
        func_0028CF98(self, 0, 0, -1, 0);
        break;
    }
    case 2:
        func_00287558(self, 0);
        if (func_0028B1B0() == 0)
            return;
        if ((unsigned int)(func_002B49E0(self + 0x118) - 101) < 3)
            return;
        func_0028CF98(self, 0, 0, -1, 0);
        *(int*)(self + 0x5FD4) = 0;
        *(int*)(self + 0x5FD0) = 0;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028C2D0);
#ifdef SKIP_ASM
extern "C" int func_0028B1B0(void);
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_0028D488(void* self);
extern "C" void func_002B4070(void* monitor);
extern "C" int func_002B49E0(void* monitor);
extern "C" int func_002B4AF0(void* monitor);

static inline void bmRestartC2D0(char* self)
{
    if (func_0028B1B0() == 0) {
        return;
    }
    if (*(int*)(self + 0x530) == 0) {
        return;
    }
    char* mon = self + 0x118;
    int st = func_002B49E0(mon);
    if ((unsigned int)(st - 1) < 3) {
        return;
    }
    if (func_002B4AF0(mon) != 0 && st != 0x12D) {
        return;
    }
    func_0028D488(self);
    func_0028CF98(self, 0, 0, -1, 0);
}

// PORT: 64-bit `long` key.
extern "C" void func_0028C2D0(char* self, long key)
{
    if (*(long*)(self + 0x6098) != key) {
        *(long*)(self + 0x6098) = key;
        int state = *(int*)(self + 0x608C);
        if (state == 1 || state == 3) {
            func_002B4070(self + 0x118);
            bmRestartC2D0(self);
        }
    } else {
        int state = *(int*)(self + 0x608C);
        if (state == 1 || state == 3) {
            bmRestartC2D0(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028C430);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" int func_002906B8(void* self);
extern "C" void func_002B2850(void* a, void* mon);

struct sEntry_C430 {
    signed char kind;
    char pad[0x17];
};
struct sQuad_C430 {
    int a;
    int b;
    int c;
    int d;
};
struct sStack_C430 {
    int field_0x0;                  // 0x1D8
    sEntry_C430 cur;                // 0x1DC
    volatile int depth;             // 0x1F4
    sEntry_C430* entries;           // 0x1F8
    int flags[4];                   // 0x1FC
    int* a34;
    int* a38;
    int* a3C;
    char a40[4][8];
    int* a60;
    int* a64;
    int* a68;
    int* a6C;
    sQuad_C430* a70;
    int* a74;
    int* a78;
    int* a7C;
    int* a80;
    int* a84;
};
struct sMgr_C430 {
    char pad_0x0[0x1D8];
    sStack_C430 st;                 // 0x1D8
};

struct sDesc_C430 {
    char pad0[0x70];
    int count;          // 0x70
    char pad74[0x8C - 0x74];
    int volume;         // 0x8C
};
struct sObj_C430 {
    sDesc_C430* desc;   // 0x00
    char pad4[0x34 - 4];
    int kind;           // 0x34
};
struct sCue_C430 {
    char pad0[4];
    int f4;             // 0x04
    char pad8[0x18 - 8];
    sObj_C430* obj;     // 0x18
    char* data;         // 0x1C
    int idx;            // 0x20
    int f24;            // 0x24
};

static inline void bmPush_C430(sMgr_C430** self, int kind, int data)
{
    sMgr_C430* m = *self;
    sStack_C430* st = &m->st;
    m->st.depth++;
    st->entries[m->st.depth] = m->st.cur;
    m->st.flags[m->st.depth] = 0;
    st->a34[m->st.depth] = 0;
    st->a38[m->st.depth] = st->entries[m->st.depth].kind;
    st->a3C[m->st.depth] = 0;
    func_00416210((char*)st + m->st.depth * 8 + 0x40, 0, 8);
    st->a60[m->st.depth] = 0;
    st->a64[m->st.depth] = 0;
    st->a68[m->st.depth] = 0;
    st->a6C[m->st.depth] = 0;
    st->a70[m->st.depth].b = 0;
    st->a70[m->st.depth].a = 100;
    st->a70[m->st.depth].c = 90;
    st->a70[m->st.depth].d = 50;
    st->a74[m->st.depth] = 0;
    st->a80[m->st.depth] = 0;
    st->a84[m->st.depth] = 0;
    st->a78[m->st.depth] = 127;
    st->a7C[m->st.depth] = 1;
    (*(int**)((char*)self + 4))[(*self)->st.depth] = kind;
    (*(int**)((char*)self + 8))[(*self)->st.depth] = data;
}

#define BM_MIN_C430(a, b) ((a) < (b) ? (a) : (b))
#define BM_MAX_C430(a, b) ((a) >= (b) ? (a) : (b))

extern "C" int func_0028C430(void* p, sCue_C430* cue)
{
    sMgr_C430** self = (sMgr_C430**)p;
    int* pidx = &cue->idx;
    char* data = cue->data;
    int saved = cue->f24;
    sObj_C430* obj = cue->obj;
    sDesc_C430* desc = obj->desc;
    int kind = obj->kind;
    int ivol = desc->volume;
    int count = desc->count;
    if (cue->idx >= count) {
        cue->idx = 0;
        if (count <= 0)
            goto end;
    }
    {
        float vol = (float)ivol;
        int idx = cue->idx;
        while (idx < 0)
            idx += count;
        bmPush_C430(self, kind, (int)(data + idx));
        sMgr_C430** pp = *(sMgr_C430***)((char*)self + 0x118);
        (*pp)->st.a3C[(*pp)->st.depth] = (int)((char*)self + 0x60A0);
        sMgr_C430* m2 = **(sMgr_C430***)((char*)self + 0x118);
        sStack_C430* st2 = &m2->st;
        st2->a38[m2->st.depth] = (int)BM_MAX_C430(BM_MIN_C430(st2->a38[st2->depth] * (vol * 0.009999999776482582f), 127.0f), 0.0f);
        st2->entries[st2->depth].kind = BM_MAX_C430(BM_MIN_C430(st2->a38[st2->depth], 127), 0);
        func_002B2850(*(void**)((char*)self + 0x520), (char*)self + 0x118);
        func_002906B8(self);
        (*pidx)++;
        cue->f4 = saved;
    }
end:
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028C8C0__FPvi);
#ifdef SKIP_ASM
void func_0028C8C0(void* self, int val)
{
    *(int*)((char*)self + 0x6250) = val;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028C8C8);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_00285D98 returns a rider pointer here (the unit declares it int).
struct sRiderC8C8;
extern "C" sRiderC8C8* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
int func_0011FE98(void* rider);
int func_0028D898(void* self);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_00288AE0(void* self);
extern "C" int func_0028D960(void* self);
extern "C" void func_002910E0(void* self);
extern "C" void func_002913D8(void* self);
extern "C" int func_002A4168(void* self);
extern "C" int func_002A41D8(void* self);
extern "C" void func_002B3C98(void* mon, char v);
extern "C" void func_002B3D10(void* mon, char v);
extern "C" int func_002B4620(void* mon);
extern "C" int func_002B46E8(void* mon);
extern "C" void func_002B4708(void* mon);
extern "C" int func_002B4878(void* mon);
extern int D_004A361C;
extern int D_004A3620;

struct sBmVtC8C8 { short delta; short index; void (*fn)(void*, int); };

struct sApC8C8 {
    char pad0[0x98];
    float f98;          // 0x98
    float f9C;          // 0x9C
    float fA0;          // 0xA0
    char padA4[0xAC - 0xA4];
    int state;          // 0xAC
};

struct sRiderC8C8 {
    char pad0[0x788];
    sApC8C8* ap;        // 0x788
};

struct sBmC8C8 {
    char pad0[0x118];
    char mon[0x5558 - 0x118];   // 0x118
    sBmVtC8C8* monVt;           // 0x5558
    char pad555C[0x5830 - 0x555C];
    float f5830;                // 0x5830
    char pad5834[0x60A0 - 0x5834];
    float f60A0;                // 0x60A0
    char pad60A4[0x6244 - 0x60A4];
    float f6244;                // 0x6244
    float f6248;                // 0x6248
    float f624C;                // 0x624C
    int f6250;                  // 0x6250
};

static inline float bmSpeed_C8C8(sBmC8C8* self, sRiderC8C8* rider)
{
    int s = rider->ap->state;
    int air = 0;
    if (s == 1 || s == 3)
        air = 1;
    if (air) {
        if (D_004A361C == 1)
            return self->f6244;
        float v = rider->ap->f98;
        self->f6248 = 0.0f;
        self->f6244 = v;
        return v;
    }
    if (D_004A361C == 1)
        return self->f6244;
    return 0.0f;
}

extern "C" void func_0028C8C8(sBmC8C8* self)
{
    if (self->f6250 > 0)
        self->f6250--;
    sRiderC8C8* rider = func_00285D98_p(self, -1);
    float spd;
    if (func_0011FE98(rider) == 1) {
        int s = rider->ap->state;
        int air = 0;
        if (s == 1 || s == 3)
            air = 1;
        if (air) {
            if (D_004A361C == 1) {
                spd = self->f6244;
            } else {
                spd = rider->ap->f98;
                self->f6248 = 0.0f;
                self->f6244 = spd;
            }
            goto have;
        }
        if (D_004A361C == 1) {
            spd = self->f6244;
            goto have;
        }
    }
    spd = 0.0f;
have:
    int play = 0;
    self->f60A0 = *(float*)func_00287968(self, 1, 0);
    D_004A3620 = D_004A361C;
    D_004A361C = 0;
    if (3.9994986057281494f < spd) {
        int r = func_002B4878(self->mon);
        if (r == 1 && !func_002A4168(self) && !func_002A41D8(self)) {
            if (!func_0028D898(self))
                play = r;
        }
    }
    if (func_00288AE0(self) == 0) {
        if (2.0f < spd) {
            D_004A361C = 1;
            float lo = rider->ap->fA0;
            if (lo < self->f6248)
                lo = self->f6248;
            self->f6248 = lo;
            float hi;
            if (D_004A3620 == 0) {
                hi = (rider->ap->f9C - rider->ap->fA0) * 0.5f;
                if (hi < 0.5f)
                    hi = 0.5f;
                hi = hi + lo;
                self->f624C = hi;
            } else {
                hi = self->f624C;
            }
            float vmax = 127.0f;
            float inv = 0.007874015718698502f;
            float vol = ((1.0f - spd * 0.8425197005271912f * 0.5f) * vmax <? vmax) >? 20.0f;
            if (lo < hi) {
                float ratio = lo / hi;
                int full = 127;
                float t = vmax - ratio * 107.0f;
                char v = (int)((t <? vmax) >? 20.0f);
                if (play) {
                    float k = *(float*)func_00287968(self, 1, 0);
                    int d = v - 20;
                    float f = (float)(full - d) * (k * inv);
                    self->f60A0 = f;
                    func_002B3D10(self->mon, (int)(f * 100.0f));
                }
                t = vmax - (vmax - vol) * ratio;
                v = (int)((t <? vmax) >? vol);
                self->f5830 = (float)(full - v) * inv;
                if (play)
                    func_002B3C98(self->mon, v);
            } else {
                self->f5830 = (vmax - vol) * inv;
                if (play) {
                    func_002B3C98(self->mon, (int)vol);
                    float k = *(float*)func_00287968(self, 1, 0);
                    self->f60A0 = k;
                    func_002B3D10(self->mon, (int)(k * 100.0f));
                }
            }
            self->f5830 = self->f5830 * *(float*)func_00287968(self, 5, 0);
            if (D_004A3620 == 0) {
                func_002910E0(self);
                if (play) {
                    char* mon = self->mon;
                    if (func_002B4620(mon) && func_0028D960(self))
                        self->monVt[3].fn(mon + self->monVt[3].delta, 7);
                }
            }
            return;
        }
    }
    char* mon = self->mon;
    if (D_004A3620 == 1) {
        func_002913D8(self);
        if (func_002B46E8(mon)) {
            if (func_0028D960(self))
                self->monVt[3].fn(mon + self->monVt[3].delta, 8);
            func_002B4708(mon);
        }
    }
    func_002B3C98(mon, 0x7F);
    func_002B3D10(mon, (int)(self->f60A0 * 100.0f));
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028CD48);
#ifdef SKIP_ASM
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" void func_002B49C0(void* self, int a1);
extern "C" void func_002B3C28(void* self, int a1);
extern char D_004A3628[];

struct sBmVtCD48 {
    short delta;
    short index;
    void* fn;
};

typedef void (*tBmLoadCD48)(void*, void*, int, void*, int);
typedef int (*tBmSetCD48)(void*, int);

extern "C" void func_0028CD48(void* self)
{
    char* mon = (char*)self + 0x118;
    sBmVtCD48* vt = *(sBmVtCD48**)((char*)self + 0x5558);
    ((tBmLoadCD48)vt[2].fn)(mon + vt[2].delta, D_004A3628, 0xC, func_00287968(self, 1, 0), 1);
    func_002B49C0(mon, 0x191);
    sBmVtCD48* vt2 = *(sBmVtCD48**)((char*)self + 0x5558);
    ((tBmSetCD48)vt2[4].fn)(mon + vt2[4].delta, 1);
    func_002B3C28(mon, 0x7F);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028CDF8);
#ifdef SKIP_ASM
extern "C" void func_002B4A08(void* self, int a1);
extern char* D_004A28A8;
extern int D_00536730[];
extern int D_00536708[];
extern char D_00482A00[];

struct sRace_28CDF8 {
    int mode;
    char pad4[0x14];
    int tracks[8];
};

extern "C" void func_0028CDF8(char* self)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    if (*(int*)(self + 0x608C) == 2) {
        return;
    }
    sRace_28CDF8* race = *(sRace_28CDF8**)(D_004A28A8 + 0xC0);
    if (race->mode != 3) {
        return;
    }
    if (D_00536730[0] >= 3) {
        return;
    }
    int track = -1;
    switch (race->tracks[D_00536708[0]]) {
    case 0: track = 10; break;
    case 1: track = 2; break;
    case 2: track = 8; break;
    case 3: track = 1; break;
    case 4: track = 5; break;
    case 5: track = 9; break;
    case 6: track = 3; break;
    case 7: track = 7; break;
    case 8: track = 4; break;
    case 9: track = 6; break;
    }
    if (track < 0) {
        return;
    }
    char* mon = self + 0x118;
    *(int*)(self + 0x62AC) = *(int*)(self + 0x508);
    sBmVtCD48* vt = *(sBmVtCD48**)(self + 0x5558);
    ((tBmLoadCD48)vt[2].fn)(mon + vt[2].delta, D_00482A00, 0xC, func_00287968(self, 1, 0), 0);
    func_002B49C0(mon, 0xC9);
    sBmVtCD48* vt2 = *(sBmVtCD48**)(self + 0x5558);
    ((tBmSetCD48)vt2[4].fn)(mon + vt2[4].delta, track);
    func_002B4A08(mon, 1);
    func_002B3C28(mon, 0x7F);
}
#endif

INCLUDE_ASM("sound/bankmanager", func_0028CF98);

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D488);
#ifdef SKIP_ASM
extern "C" unsigned int func_002ADF60(void* rng);
extern "C" int func_0028D8A0(void* self);
extern "C" void func_002B42B8(void* q, int a, int b);

extern "C" void func_0028D488(void* vself)
{
    char* self = (char*)vself;
    unsigned int count = *(unsigned int*)(self + 0x504);
    int prev = *(int*)(self + 0x62A4);
    *(unsigned int*)(self + 0x508) = ((func_002ADF60(*(void**)(**(char***)(self + 0x118) + 0x1D8)) & 0x7FFF) * count) / 0x7FFF;
    int n = ((func_002ADF60(*(void**)(**(char***)(self + 0x118) + 0x1D8)) & 0x7FFF) * 10) / 0x7FFF + 1;
    int i;
    for (i = 0; i < n; i++)
        func_002B42B8(self + 0x118, 1, func_0028D8A0(self));
    char* q = self + 0x118;
    if (prev == *(int*)(self + 0x508)) {
        func_002B42B8(q, 1, func_0028D8A0(self));
        if (prev == *(int*)(self + 0x508))
            func_002B42B8(q, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D5A0);
#ifdef SKIP_ASM
extern "C" int func_002B49E0(void* monitor);
extern "C" int func_002A1E20(void* self, int id);
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);

extern "C" void func_0028D5A0(void* self, int id)
{
    int cur;
    int type;
    int want;
    if (*(int*)((char*)self + 0x6284) == 0x17) {
        return;
    }
    cur = func_002B49E0((char*)self + 0x118);
    type = func_002A1E20(self, id);
    if (type == 1) {
        want = 0x65;
    } else if (type == 2) {
        want = 0x66;
    } else {
        want = 0x67;
    }
    if (want != cur) {
        func_0028CF98(self, 0, 0, type, 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D630);
#ifdef SKIP_ASM
extern "C" int func_00285D98(void* self, int which);

struct sBmVt630 { short delta; short index; int (*fn)(void*); };
struct sBmVt630b { short delta; short index; int (*fn)(void*, int); };

extern "C" void func_0028D630(void* self, int id, void* obj)
{
    int ok;
    if (*(int*)((char*)self + 0x5FD4) != 0) return;
    if (*(int*)((char*)self + 0x5FD8) != 0) return;
    if (*(int*)((char*)self + 0x623C) == id) return;
    ok = 0;
    if (*(int*)((char*)self + 0x62A0) == -1) {
        // PORT: func_00285D98 returns an object pointer as int
        if ((int)obj == func_00285D98(self, -1)) {
            char* o = (char*)obj + 0x6C0;
            sBmVt630* e = &(*(sBmVt630**)o)[7];
            ok = 1;
            *(int*)((char*)self + 0x62A0) = e->fn(o + e->delta);
        }
    } else {
        char* o = (char*)obj + 0x6C0;
        sBmVt630* e = &(*(sBmVt630**)o)[7];
        ok = e->fn(o + e->delta) == *(int*)((char*)self + 0x62A0);
    }
    if (ok) {
        int n = *(int*)((char*)self + 0x623C);
        char* mon = (char*)self + 0x118;
        if (n != 0) {
            sBmVt630b* vt = *(sBmVt630b**)((char*)self + 0x5558);
            vt[4].fn(mon + vt[4].delta, n + 1);
        }
        *(int*)((char*)self + 0x623C) = id;
        *(int*)((char*)self + 0x6240) = 0;
        {
            sBmVt630b* vt = *(sBmVt630b**)((char*)self + 0x5558);
            vt[4].fn(mon + vt[4].delta, id);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D740);
#ifdef SKIP_ASM
extern "C" void func_0028D7D8(void* self, void* a1);

struct sVtEnt { short delta; short index; int (*fn)(void*); };

extern "C" void func_0028D740(void* self, int id, void* obj)
{
    int ok;
    if (*(int*)((char*)self + 0x6240) == id) {
        return;
    }
    ok = 0;
    if (*(int*)((char*)self + 0x62A0) != -1) {
        char* o = (char*)obj + 0x6C0;
        sVtEnt* e = &(*(sVtEnt**)o)[7];
        ok = e->fn(o + e->delta) == *(int*)((char*)self + 0x62A0);
    }
    if (ok) {
        if (*(int*)((char*)self + 0x623C) == id) {
            *(int*)((char*)self + 0x6240) = id;
            return;
        }
        func_0028D7D8(self, obj);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D7D8);
#ifdef SKIP_ASM
struct sBmVtD7D8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

// PORT: the unit declares func_0028D7D8 as returning void; it really returns 0/1.
int func_0028D7D8_impl(void* self, void* obj) __asm__("func_0028D7D8");

int func_0028D7D8_impl(void* self, void* obj)
{
    int ok = 0;
    if (obj == 0) {
        ok = 1;
        *(int*)((char*)self + 0x62A0) = -1;
    } else {
        int none = -1;
        if (*(int*)((char*)self + 0x62A0) != none) {
            char* o = (char*)obj + 0x6C0;
            sVtEnt* e = &(*(sVtEnt**)o)[7];
            if (e->fn(o + e->delta) == *(int*)((char*)self + 0x62A0)) {
                *(int*)((char*)self + 0x62A0) = none;
                ok = 1;
            }
        }
    }
    if (ok) {
        int n = *(int*)((char*)self + 0x623C);
        if (n != 0) {
            char* mon = (char*)self + 0x118;
            sBmVtD7D8* vt = *(sBmVtD7D8**)((char*)self + 0x5558);
            vt[4].fn(mon + vt[4].delta, n + 1);
            *(int*)((char*)self + 0x623C) = 0;
            *(int*)((char*)self + 0x6240) = 0;
        }
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D898__FPv);
#ifdef SKIP_ASM
int func_0028D898(void* self)
{
    return *(int*)((char*)self + 0x623C);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D8A0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A4318(void* self);
extern "C" int func_002A4368(void* self);
extern "C" int func_002A40E0(void* self, int id);
extern "C" int func_002A4158(void* self, int id);
extern "C" int func_002A41C8(void* self, int id);
extern "C" int func_002A4238(void* self, int id);

extern "C" int func_0028D8A0(void* self)
{
    int id = *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0));
    int r;
    if (func_002A4318(self)) {
        r = 0;
    } else if (func_002A4368(self)) {
        r = 1;
    } else if (func_002A40E0(self, id)) {
        r = 0;
    } else if (func_002A4158(self, id)) {
        r = 1;
    } else if (func_002A41C8(self, id)) {
        r = 2;
    } else if (func_002A4238(self, id)) {
        r = 3;
    } else {
        r = 4;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028D960);
#ifdef SKIP_ASM
extern "C" int func_0028D960(void* self)
{
    unsigned int s = *(unsigned int*)((char*)self + 0x608c);
    if (s < 2 || s == 3) {
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("sound/bankmanager", func_0028D988);

//100%
INCLUDE_ASM("sound/bankmanager", func_0028DEF0);
#ifdef SKIP_ASM
extern "C" int func_0028DEF0(void* self, int a1)
{
    int old = *(int*)((char*)self + 0x629c);
    *(int*)((char*)self + 0x629c) = a1;
    return old != a1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028DF08__FPv);
#ifdef SKIP_ASM
void func_0028DF08(void* self)
{
    *(int*)((char*)self + 0x629C) = -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028DF18);
#ifdef SKIP_ASM
struct sSndKey8_DF18 {
    long v;
} __attribute__((packed));
extern sSndKey8_DF18 D_004A3648_DF18[] __asm__("D_004A3648");
extern sSndKey8_DF18 D_004A3650_DF18[] __asm__("D_004A3650");
extern sSndKey8_DF18 D_004A3658_DF18[] __asm__("D_004A3658");
// PORT: func_002ADCA0 returns int; the unit declares it void elsewhere.
extern "C" int func_002ADCA0_DF18(void*, int, long, int, int, int, int, int) __asm__("func_002ADCA0");
extern "C" int func_002A10C0(void* self, int id);
extern "C" void func_002B3D48(void* self, float v);
int func_002B4908(void* self);

struct sBmVtDF18 {
    short delta;
    short index;
    void* fn;
};

typedef int (*tBmSetDF18)(void*, int);

// PORT: 64-bit long sound key
extern "C" int func_0028DF18(void* self, int quiet)
{
    int ok = 0;
    if (func_002A10C0(self, 0xA) == 0) {
        char* mon = (char*)self + 0x118;
        if (*(int*)((char*)self + 0x62B8) == 0) {
            func_002B3D48(mon, 2.0f);
        }
        sBmVtDF18* vt = *(sBmVtDF18**)((char*)self + 0x5558);
        ok = 1;
        ((tBmSetDF18)vt[4].fn)(mon + vt[4].delta, 0x12);
        func_0028D488(self);
        func_002ADCA0_DF18(**(char***)((char*)self + 0x118) + 0x1D8, 0x7D0, D_004A3648_DF18->v, 0, 1, 1, 0, 0);
        char* p = **(char***)((char*)self + 0x118) + 0x1D8;
        sSndKey8_DF18* key = D_004A3650_DF18;
        int r = func_002B4908(mon);
        func_002ADCA0_DF18(p, 0x5DC, key->v, 0, 3, r, 0, 0);
    } else if (quiet == 0) {
        func_002ADCA0_DF18(**(char***)((char*)self + 0x118) + 0x1D8, 0x64, D_004A3658_DF18->v, 0, 0, 0, 0, 0);
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028E068);
#ifdef SKIP_ASM
extern "C" int func_0028DF18(void* self, int quiet);

extern "C" int func_0028E068(void* self)
{
    return func_0028DF18(self, 1) != 0;
}
#endif
//100%
INCLUDE_ASM("sound/bankmanager", func_0028E088);
#ifdef SKIP_ASM
extern "C" int func_002B2550(int);

extern "C" int func_0028E088(char *self, char *arg) {
    int obj;
    int t;

    obj = *(int *)(self + 0x520);
    if (obj == 0 || func_002B2550(obj) == -1) {
        *(int *)(self + 0x6274) = 1;
        *(int *)(self + 0x6278) = *(int *)(arg + 0x1C);
        return 1;
    }
    t = *(int *)(arg + 0x20);
    if (t == 1) {
        *(int *)(self + 0x6274) = t;
        *(int *)(self + 0x6278) = *(int *)(arg + 0x1C);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028E100);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" void* func_0028B1E8();
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_0028D488(void* self);
extern "C" int func_0028D960(void* self);
extern "C" int func_002A1E20(void* self, int id);
extern "C" int func_002A4030(void* self);
extern "C" void func_002B3C28(void* self, int a1);
extern "C" void func_002B49C0(void* self, int a1);
extern char D_004A3630[];
extern char D_004A3638[];
extern char D_004A3640[];

struct sBmVtE100 {
    short delta;
    short index;
    void* fn;
};

typedef void (*tBmLoadE100)(void*, void*, int, void*, int);
typedef int (*tBmSetE100)(void*, int);

static inline void bmLoad_E100(char* self, char* bank, int n)
{
    char* mon = self + 0x118;
    sBmVtE100* vt = *(sBmVtE100**)(self + 0x5558);
    ((tBmLoadE100)vt[2].fn)(mon + vt[2].delta, bank, 0xC, func_00287968(self, 1, 0), 0);
    func_002B49C0(mon, n);
}

static inline void bmLoadBank_E100(char* self, int t)
{
    if (t == 1) {
        bmLoad_E100(self, D_004A3630, 1);
    } else if (t == 2) {
        bmLoad_E100(self, D_004A3638, 2);
    } else {
        bmLoad_E100(self, D_004A3640, 3);
    }
    char* mon = self + 0x118;
    sBmVtE100* vt2 = *(sBmVtE100**)(self + 0x5558);
    ((tBmSetE100)vt2[4].fn)(mon + vt2[4].delta, 0xC);
    func_002B3C28(mon, 0x7F);
}

extern "C" void func_0028E100(char* self)
{
    if (*(int*)(self + 0x6274) == 0)
        return;
    int st = *(int*)(self + 0x6278);
    int id;
    if (st == 0) {
        if (func_0028D960(self)) {
            int t;
            id = *(int*)(self + 0x6284);
            if (id == 0x17) {
                t = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            } else {
                t = func_002A1E20(self, id);
                *(int*)(self + 0x6284) = 0x17;
            }
            bmLoadBank_E100(self, t);
        }
    } else if (st == 2) {
        if (func_0028D960(self)) {
            id = *(int*)(self + 0x6284);
            if (id != 0x17) {
                if (func_002A4030(self)) {
                    func_0028D488(self);
                    func_0028CF98(self, 0x24, 1, -1, 0);
                } else {
                    id = *(int*)(self + 0x6284);
                    bmLoadBank_E100(self, func_002A1E20(self, id));
                }
                *(int*)(self + 0x6284) = 0x17;
            }
        }
    } else if (st == 4) {
        func_0028CF98(self, 0, 0, -1, 0);
    } else {
        if (func_0028D960(self)) {
            if (*(int*)(self + 0x6278) == 3)
                func_0028CF98(self, 0x24, 0, -1, 0);
            else
                func_0028CF98(self, 0, 0, -1, 0);
        }
    }
    *(int*)(self + 0x6274) = 0;
}
#endif

INCLUDE_ASM("sound/bankmanager", func_0028E510);

INCLUDE_ASM("sound/bankmanager", func_0028E548);
//100%
INCLUDE_ASM("sound/bankmanager", func_0028E888);
#ifdef SKIP_ASM
extern "C" void func_0028E8C0(void* self, int id, int a2);

extern "C" void func_0028E888(void* self)
{
    if (*(int*)((char*)self + 0x6254) != 0) {
        func_0028E8C0(self, 0x13, 1);
        *(int*)((char*)self + 0x6254) = 0;
    }
}
#endif

INCLUDE_ASM("sound/bankmanager", func_0028E8C0);

//100%
INCLUDE_ASM("sound/bankmanager", func_0028EF90);
#ifdef SKIP_ASM
struct sSndKey8_EF90 {
    long v;
} __attribute__((packed));
extern sSndKey8_EF90 D_004A3648[];
extern "C" void func_002ADCA0(void*, int, long, int, int, int, int, int);

// PORT: 64-bit long sound key
extern "C" void func_0028EF90(void* self)
{
    *(int*)((char*)self + 0x6258) = 0;
    *(int*)((char*)self + 0x577C) = 0;
    func_0028DF08(self);
    *(int*)((char*)self + 0x578C) = 0;
    func_0028D488(self);
    func_002ADCA0(**(char***)((char*)self + 0x118) + 0x1D8, 0xA, D_004A3648->v, 0, 2, 1, 0, 0);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F000);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
extern "C" int func_00285D98(void* self, int which);
extern "C" int func_00289C18(void* self, int rider);

extern "C" void func_0028F000(void* self)
{
    char* mon = (char*)self + 0x118;
    int st = func_002B49E0(mon);
    if (st >= 1 && st <= 3) {
        func_002B3C28(mon, 0x7F);
        return;
    }
    if (*(int*)((char*)self + 0x6288) != 2) {
        *(int*)((char*)self + 0x6288) = 2;
        *(int*)((char*)self + 0x628C) = 0;
    }
    int max = 800;
    int r = func_00289C18(self, func_00285D98(self, -1));
    if (r == 1) {
        max = 1000;
    } else if (r == 2) {
        max = 1200;
    }
    int cur = *(int*)((char*)self + 0x628C);
    float t = (float)cur / (float)max;
    if (cur < max) {
        *(int*)((char*)self + 0x628C) = cur + 1;
    } else {
        *(int*)((char*)self + 0x628C) = max;
    }
    t = t <? 1.0f;
    t = t >? 0.0f;
    func_002B3C28((char*)self + 0x118, (int)(t * 127.0f));
}
#endif

INCLUDE_ASM("sound/bankmanager", func_0028F108);

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F140);
#ifdef SKIP_ASM
struct sBmVtF140 {
    short delta;
    short index;
    void* fn;
};
typedef int (*tBmSetF140)(void*, int);

// Switches the bank monitor to the sound bank for a new mode (0..9).
extern "C" void func_0028F140(void* self, int mode)
{
    int bank;
    if (mode == *(int*)((char*)self + 0x6290)) {
        return;
    }
    *(int*)((char*)self + 0x6290) = mode;
    switch (mode) {
    case 0:
        bank = (*(int*)((char*)self + 0x534) == -1) ? 0 : 9;
        break;
    case 1: bank = 1; break;
    case 3: bank = 3; break;
    case 4: bank = 4; break;
    case 5: bank = 5; break;
    case 6: bank = 6; break;
    case 7: bank = 7; break;
    case 8: bank = 8; break;
    case 2:
    case 9: bank = 2; break;
    default: bank = -1; break;
    }
    if (bank >= 0) {
        char* mon = (char*)self + 0x118;
        sBmVtF140* vt = *(sBmVtF140**)((char*)self + 0x5558);
        ((tBmSetF140)vt[4].fn)(mon + vt[4].delta, bank);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F200);
#ifdef SKIP_ASM
extern "C" int func_002B49E0(void* stream);
extern "C" int func_0028D960(void* self);

// PORT: 64-bit long sound key
extern "C" void func_0028F200(void* self)
{
    char* s = (char*)self;
    void* mon = s + 0x118;
    *(int*)(s + 0x6294) = 0;
    *(int*)(s + 0x6298) = 0;
    if (*(int*)(s + 0x530) == 0 || func_002B49E0(mon) == 0xC9) {
        if (func_0028D960(self) != 0) {
            if (func_002B49E0(mon) == 0xC9) {
                *(int*)(s + 0x508) = *(int*)(s + 0x62AC);
            }
            func_002ADCA0(**(char***)(s + 0x118) + 0x1D8, 0xA, D_004A3648->v, 0, 3, 1, 0, 0);
        }
        *(int*)(s + 0x6294) = 1;
    } else {
        *(int*)(s + 0x6298) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F2C0);
#ifdef SKIP_ASM
extern "C" void* func_002B3AC0(void*);

struct sBankMgrVEntry {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0028F2C0(void* self)
{
    if (*(int*)((char*)self + 0x6294) != 0) {
        func_002B3AC0((char*)self + 0x118);
    } else if (*(int*)((char*)self + 0x6298) != 0) {
        char* obj = (char*)self + 0x118;
        sBankMgrVEntry* vt = *(sBankMgrVEntry**)((char*)self + 0x5558);
        vt[4].fn(obj + vt[4].delta, 0x24);
    }
    *(int*)((char*)self + 0x6294) = 0;
    *(int*)((char*)self + 0x6298) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F328);
#ifdef SKIP_ASM
extern "C" void func_002B3B88(void* self, int a1);
extern "C" int func_002B49E0(void* monitor);
extern int D_004A3620;

class cBankMonitor_F328 {
public:
    char data[0x5440];
    virtual void v1();
    virtual void v2();
    virtual void v3(int a1);
};

extern "C" void func_0028F328(void* self, int code)
{
    void* monitor = (char*)self + 0x118;
    func_002B3B88(monitor, code);
    if (func_002B49E0(monitor) == -1) {
        if ((unsigned)(code - 10) < 2 || code == 0x12) {
            if (D_004A3620 == 1) {
                ((cBankMonitor_F328*)((char*)self + 0x118))->v3(8);
            }
            *(int*)((char*)self + 0x530) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F3C8);
#ifdef SKIP_ASM
extern "C" int func_002B3BC0(void* self, int v);

extern "C" int func_0028F3C8(void* self, int code)
{
    void* monitor = (char*)self + 0x118;
    int r = func_002B3BC0(monitor, code);
    if (func_002B49E0(monitor) == -1) {
        if ((unsigned)(code - 10) < 2 || code == 0x12) {
            if (D_004A3620 == 1) {
                ((cBankMonitor_F328*)((char*)self + 0x118))->v3(8);
            }
            *(int*)((char*)self + 0x530) = 0;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F478);
#ifdef SKIP_ASM
class cUiObj_F478 {
public:
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
    virtual int v24(int a, int b);
};

int GetHashValue32(char*);
extern char D_004A3660[];
extern char* D_004A28A8;
extern "C" void func_002B35A0(void* monitor);
extern "C" float func_00287930(void* self, int a, int b);
extern "C" cUiObj_F478* func_0039F9D8(void* list, int hash);

extern "C" void func_0028F478(void* self)
{
    func_002B35A0((char*)self + 0x118);
    if (func_00287930(self, 1, 0) > 0.0f) {
        char* game = *(char**)(D_004A28A8 + 0x84);
        if (game != 0) {
            char* owner = *(char**)(game + 0x48);
            if (owner != 0) {
                void* list = owner + 0x18;
                if (list != 0) {
                    cUiObj_F478* obj = func_0039F9D8(list, GetHashValue32(D_004A3660));
                    if (obj != 0) {
                        obj->v24(5, 0);
                    }
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F520);
#ifdef SKIP_ASM
extern "C" int func_0028D960(void* self);
extern "C" void* func_002B3AC0(void*);

extern "C" void func_0028F520(void* self)
{
    if (func_0028D960(self) != 0) {
        func_002B3AC0((char*)self + 0x118);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028F558);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" void func_0028EF90(void* self);

extern "C" void func_0028F558(void* self, int id)
{
    *(int*)((char*)self + 0x6284) = id;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    if (iface != 0) {
        if (*func_00144BC0(iface) == *(int*)((char*)self + 0x6284)) {
            func_0028EF90(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F5B8);
#ifdef SKIP_ASM
extern "C" int func_0028B1B0(void);
extern "C" void func_0029CE28(void* self);
extern "C" void func_00294F78(void* self, int a1);
extern "C" void func_002B3D48(void* self, float v);
extern "C" void func_0028F768(void* self);
extern "C" void func_002B3C28(void* self, int a1);

struct sBmVtF5B8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

extern "C" void func_0028F5B8(void* self)
{
    *(int*)((char*)self + 0x6088) = 0;
    if (*(int*)((char*)self + 0x5FB4) != 0) return;
    if (func_0028B1B0() == 0) return;
    if (*(int*)((char*)self + 0x5818) == 0) {
        func_0029CE28(self);
        *(int*)((char*)self + 0x6088) = 1;
    }
    func_00294F78(self, 9);
    if (*(int*)((char*)self + 0x608C) != 2) {
        char* mon = (char*)self + 0x118;
        func_002B3D48(mon, 1.0f);
        func_0028F768(self);
        sBmVtF5B8* vt = *(sBmVtF5B8**)((char*)self + 0x5558);
        vt[4].fn(mon + vt[4].delta, 0);
        func_002B3C28(mon, 0x7F);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F678);
#ifdef SKIP_ASM
extern "C" void func_0029CE70(void* self);
extern "C" int func_002A3F90(void* self);
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_0028FA98(void* self, float v);

extern "C" void func_0028F678(void* self, int a1)
{
    if (*(int*)((char*)self + 0x6088) != 0) {
        func_0029CE70(self);
        *(int*)((char*)self + 0x6088) = 0;
    }
    if (*(int*)((char*)self + 0x62A8) >= 0) {
        func_0028FA98(self, 1.0f);
        if (a1 != 0 && func_002A3F90(self) != 0) {
            func_0028CF98(self, 0, 0, -1, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F700);
#ifdef SKIP_ASM
extern "C" void func_0028BC58(void* self, int i, void* id, int a3);
extern void* D_004A3624;

extern "C" void func_0028F700(void* self)
{
    func_0028BC58(**(void***)((char*)self + 0x118), 0xD, D_004A3624, 0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmanager", func_0028F730);
#ifdef SKIP_ASM
extern "C" void func_0028FA98(void* self, float v);
extern "C" void func_0028BCE8(void* self, int i);

extern "C" void func_0028F730(void* self)
{
    func_0028FA98(self, 0.0f);
    func_0028BCE8(**(void***)((char*)self + 0x118), 0);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028F768);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sEntry_F768 {
    signed char kind;
    char pad[0x17];
};
struct sQuad_F768 {
    int a;
    int b;
    int c;
    int d;
};
struct sStack_F768 {
    int field_0x0;                  // 0x1D8
    sEntry_F768 cur;                // 0x1DC
    volatile int depth;             // 0x1F4
    sEntry_F768* entries;           // 0x1F8
    int flags[4];                   // 0x1FC
    int* a34;
    int* a38;
    int* a3C;
    char a40[4][8];
    int* a60;
    int* a64;
    int* a68;
    int* a6C;
    sQuad_F768* a70;
    int* a74;
    int* a78;
    int* a7C;
    int* a80;
    int* a84;
};
struct sMgr_F768 {
    char pad_0x0[0x1D8];
    sStack_F768 st;                 // 0x1D8
};

static inline void bmPush_F768(sMgr_F768** self, int kind)
{
    sMgr_F768* m = *self;
    sStack_F768* st = &m->st;
    m->st.depth++;
    st->entries[m->st.depth] = m->st.cur;
    m->st.flags[m->st.depth] = 0;
    st->a34[m->st.depth] = 0;
    st->a38[m->st.depth] = st->entries[m->st.depth].kind;
    st->a3C[m->st.depth] = 0;
    func_00416210((char*)st + m->st.depth * 8 + 0x40, 0, 8);
    st->a60[m->st.depth] = 0;
    st->a64[m->st.depth] = 0;
    st->a68[m->st.depth] = 0;
    st->a6C[m->st.depth] = 0;
    st->a70[m->st.depth].b = 0;
    st->a70[m->st.depth].a = 100;
    st->a70[m->st.depth].c = 90;
    st->a70[m->st.depth].d = 50;
    st->a74[m->st.depth] = 0;
    st->a80[m->st.depth] = 0;
    st->a84[m->st.depth] = 0;
    st->a78[m->st.depth] = 127;
    st->a7C[m->st.depth] = 1;
    (*(int**)((char*)self + 4))[(*self)->st.depth] = kind;
    (*(int**)((char*)self + 8))[(*self)->st.depth] = 0;
}

#define BM_MIN_F768(a, b) ((a) < (b) ? (a) : (b))
#define BM_MAX_F768(a, b) ((a) >= (b) ? (a) : (b))

extern "C" void func_0028F768(void* p)
{
    sMgr_F768** self = (sMgr_F768**)p;
    bmPush_F768(self, 13);
    sMgr_F768* m2 = **(sMgr_F768***)((char*)self + 0x118);
    sStack_F768* st2 = &m2->st;
    st2->a38[m2->st.depth] = 127;
    st2->entries[m2->st.depth].kind = BM_MAX_F768(BM_MIN_F768(st2->a38[st2->depth], 127), 0);
    sMgr_F768** pp = *(sMgr_F768***)((char*)self + 0x118);
    (*pp)->st.a3C[(*pp)->st.depth] = (int)func_00287968(self, 1, 0);
    *(int*)((char*)self + 0x62A8) = func_002906B8(self);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028FA98);
#ifdef SKIP_ASM
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_0028FA98(void* self, float v)
{
    int idx = *(int*)((char*)self + 0x62A8);
    if (idx >= 0) {
        func_002AD5F0((char*)**(void***)((char*)self + 0x118) + 0x1D8, idx, 1, v);
        *(int*)((char*)self + 0x62A8) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028FAE0);
#ifdef SKIP_ASM
struct sSndKey8_FAE0 {
    long v;
} __attribute__((packed));
extern sSndKey8_FAE0 D_004A3648_FAE0[] __asm__("D_004A3648");
extern sSndKey8_FAE0 D_004A3650_FAE0[] __asm__("D_004A3650");
extern sSndKey8_FAE0 D_004A3658_FAE0[] __asm__("D_004A3658");
extern "C" void func_002ADDE0(void* bank, long id);
extern "C" void func_002ADCA0(void*, int, long, int, int, int, int, int);
extern "C" int func_0028DEF0(void* self, int a1);
extern "C" void* func_002B3AC0(void* monitor);

// PORT: 64-bit long sound keys
// Stops the three menu loops, and unless a bank load is pending, switches to the front-end bank and starts its music.
extern "C" void func_0028FAE0(char* self)
{
    if (func_0028D960(self) == 0) {
        return;
    }
    func_002ADDE0(**(char***)(self + 0x118) + 0x1D8, D_004A3648_FAE0->v);
    func_002ADDE0(**(char***)(self + 0x118) + 0x1D8, D_004A3650_FAE0->v);
    func_002ADDE0(**(char***)(self + 0x118) + 0x1D8, D_004A3658_FAE0->v);
    int st = func_002B49E0(self + 0x118);
    if ((unsigned int)(st - 1) >= 3 && st != 0x191) {
        if (*(int*)(self + 0x530) != 0) {
            return;
        }
    }
    func_0028DEF0(self, 0x12);
    *(int*)(self + 0x5828) = 1;
    func_002B3AC0(self + 0x118);
    func_0028D488(self);
    func_0028CF98(self, 0, 0, -1, 0);
    char* p = **(char***)(self + 0x118) + 0x1D8;
    sSndKey8_FAE0* key = D_004A3650_FAE0;
    int r = func_002B4908(self + 0x118);
    func_002ADCA0(p, 3000, key->v, 0, 4, r, 0, 0);
}
#endif

extern "C" void* func_002B3AC0(void*);

//100%
INCLUDE_ASM("sound/bankmanager", func_0028FC38__FPv);
#ifdef SKIP_ASM
void* func_0028FC38(void* self)
{
    return func_002B3AC0((char*)self + 0x118);
}
#endif

//100%
INCLUDE_ASM("sound/bankmanager", func_0028FC58);
#ifdef SKIP_ASM
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" void func_002B49C0(void* self, int a1);
extern char D_004A3598[];

struct sBmVtFC58 {
    short delta;
    short index;
    void* fn;
};

typedef void (*tBmLoadFC58)(void*, void*, int, void*, int);
typedef int (*tBmSetFC58)(void*, int);

extern "C" void func_0028FC58(void* self)
{
    char* mon = (char*)self + 0x118;
    sBmVtFC58* vt = *(sBmVtFC58**)((char*)self + 0x5558);
    ((tBmLoadFC58)vt[2].fn)(mon + vt[2].delta, D_004A3598, 0xC, func_00287968(self, 1, 0), 1);
    func_002B49C0(mon, 0x12D);
    sBmVtFC58* vt2 = *(sBmVtFC58**)((char*)self + 0x5558);
    ((tBmSetFC58)vt2[4].fn)(mon + vt2[4].delta, *(int*)((char*)self + 0x6290));
}
#endif

