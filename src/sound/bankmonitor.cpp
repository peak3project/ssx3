#include "common.h"

//100%
INCLUDE_ASM("sound/bankmonitor", cBankMonitor_cBankMonitor);
#ifdef SKIP_ASM
struct sSndPlayerD9C8;
extern "C" sSndPlayerD9C8* func_002AD9C8(sSndPlayerD9C8* self, int inchrg, int heap);
extern "C" void* func_002ADE88(void* self, int a);
extern "C" void* func_002AB9E0(void* self);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_00483238[];
extern void* D_00483B48[];

struct sBmVEntryCD08 {
    short delta;
    short index;
    void* fn;
};
struct sBmVtblCD08 {
    sBmVEntryCD08 e[4];
} __attribute__((aligned(8)));
extern const sBmVtblCD08 D_00483B88;

struct sBmVoiceCD08 {
    char pad_0x0[0xC0];
    sBmVoiceCD08() { func_002AB9E0(this); }
    void operator delete[](void* p, unsigned int size);
};

struct sBankMonitorCD08 {
    char* vbase;                // 0x0
    char pad_0x4[0x8D8 - 0x4];
    void** vtbl;                // 0x8D8
    int f8DC;                   // 0x8DC
    int f8E0;                   // 0x8E0
    int f8E4;                   // 0x8E4
    int f8E8;                   // 0x8E8
    sBmVoiceCD08* voices;       // 0x8EC
    char vb[0x4];               // 0x8F0
};

extern "C" sBankMonitorCD08* cBankMonitor_cBankMonitor(sBankMonitorCD08* self, int inchrg, int heap)
{
    if (inchrg) {
        self->vbase = self->vb;
        func_002ADE88(self->vb, heap);
    }
    func_002AD9C8((sSndPlayerD9C8*)self, 0, heap);
    *(const sBmVtblCD08**)(self->vbase + 4) = &D_00483B88;
    if (!inchrg) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sBmVtblCD08 vt = D_00483B88;
        *(sBmVtblCD08**)(self->vbase + 4) = &vt;
        char* base = self->vbase - 0x8F0;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483B88.e[1].delta + d;
    }
    self->vtbl = D_00483B48;
    self->f8DC = 0;
    self->f8E0 = 1;
    self->f8E4 = 1;
    sBmVoiceCD08** slot = &self->voices;
    *slot = new (D_00483238, 0, 0) sBmVoiceCD08[64];
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ACE40);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_002ABA18(void* self, int flags);
struct sSndPlayerDAC8;
extern "C" void func_002ADAC8(sSndPlayerDAC8* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern void* D_00483B48[];

struct sBmVEntryE40 {
    short delta;
    short index;
    void* fn;
};
struct sBmVtblE40 {
    sBmVEntryE40 e[4];
} __attribute__((aligned(8)));
extern const sBmVtblE40 D_00483B88_E40 __asm__("D_00483B88");

struct sBmVoiceE40 {
    char pad_0x0[0xC0];
};

struct sBankMonitorE40 {
    char* vbase;                // 0x0
    char pad_0x4[0x8D8 - 0x4];
    void** vtbl;                // 0x8D8
    char pad_0x8DC[0x8EC - 0x8DC];
    sBmVoiceE40* voices;        // 0x8EC
};

extern "C" void func_002ACE40(sBankMonitorE40* self, int flags)
{
    self->vtbl = D_00483B48;
    *(const sBmVtblE40**)(self->vbase + 4) = &D_00483B88_E40;
    if (flags == 0) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sBmVtblE40 vt = D_00483B88_E40;
        *(sBmVtblE40**)(self->vbase + 4) = &vt;
        char* base = self->vbase - 0x8F0;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483B88_E40.e[1].delta + d;
    }
    if (self->voices != 0) {
        sBmVoiceE40* q = self->voices + ((int*)self->voices)[-4];
        while (self->voices != q) {
            q--;
            func_002ABA18(q, 0);
        }
        cMemMan_free((char*)self->voices - 0x10);
    }
    func_002ADAC8((sSndPlayerDAC8*)self, 0);
    if (flags & 2) {
        func_002ADEE8(self->vbase, 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ACF60);
#ifdef SKIP_ASM
extern "C" int func_002ABB80(void*);

extern "C" int func_002ACF60(void* self, int n)
{
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) != 0) {
            if (--n == 0) {
                return i;
            }
        }
    }
    return -1;
}
#endif

INCLUDE_ASM("sound/bankmonitor", cBankMonitor_BANKMONITOR_Create);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD2A8);
#ifdef SKIP_ASM
extern "C" void func_002ACAC8(void*);

extern "C" void func_002AD2A8(void* self)
{
    *(int*)((char*)self + 0x8E8) = 1;
    for (int i = 0; i < 64; i++) {
        func_002ACAC8((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD300);
#ifdef SKIP_ASM
extern "C" void func_002ACB30(void*);

extern "C" void func_002AD300(void* self)
{
    for (int i = 0; i < 64; i++) {
        func_002ACB30((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0);
    }
    *(int*)((char*)self + 0x8E8) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD358);
#ifdef SKIP_ASM
extern "C" void* func_002AD550(void* self, int idx, int a2);
extern "C" void func_002ACB80(void* voice, int a, int b, float v);

extern "C" void func_002AD358(void* self, int idx, int key, float v)
{
    void* voice = func_002AD550(self, idx, key);
    if (voice != 0) {
        func_002ACB80(voice, -1, 0, v);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD398);
#ifdef SKIP_ASM
extern "C" void func_002ABB38(void*);

extern "C" void func_002AD398(void* self, int i)
{
    func_002ABB38((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AD3C0);
#ifdef SKIP_ASM
extern "C" void func_002AD398(void* self, int i);

extern "C" void func_002AD3C0(void* self)
{
    int i;
    for (i = 0; i < 64; i++) {
        func_002AD398(self, i);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD410);
#ifdef SKIP_ASM
extern "C" void func_002ABB38(void*);

struct sBmKeyD410 {
    short a;
    short id;
    union {
        int v;
        short s;
    };
};

static inline int func_002AD410_match(char* e, sBmKeyD410 k)
{
    int r = 0;
    if (k.id == *(short*)(e + 0xAA)) {
        if ((k.id != -1 && k.s == *(short*)(e + 0xAC)) || k.v == *(int*)(e + 0xAC)) {
            r = 1;
        }
    }
    return r;
}

extern "C" void func_002AD410(void* self, sBmKeyD410 key)
{
    for (int i = 0; i < 64; i++) {
        if (func_002AD410_match((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0, key)) {
            func_002ABB38((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD4D8);
#ifdef SKIP_ASM
extern "C" void func_002AD4D8(void* self, int id)
{
    for (int i = 0; i < 64; i++) {
        if (*(int*)((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0 + 0x80) == id) {
            func_002ABB38((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD550);
#ifdef SKIP_ASM
struct sVoiceC0 { int key; int idx; char pad[0xC0 - 8]; };

extern "C" void* func_002AD550(void* self, int idx, int key)
{
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) == 0
            && (*(sVoiceC0**)((char*)self + 0x8EC))[i].key == key
            && (*(sVoiceC0**)((char*)self + 0x8EC))[i].idx == idx) {
            return &(*(sVoiceC0**)((char*)self + 0x8EC))[i];
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AD5F0);
#ifdef SKIP_ASM
extern "C" void* func_002AD550(void* self, int idx, int a2);
extern "C" void func_002ABB38(void*);
extern "C" void func_002ACB80(void* voice, int a, int b, float v);

extern "C" void func_002AD5F0(void* self, int idx, int a2, float v)
{
    void* voice = func_002AD550(self, idx, a2);
    if (voice != 0) {
        if (v != 0.0f) {
            func_002ACB80(voice, -1, 1, v);
        } else {
            func_002ABB38(voice);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD650);
#ifdef SKIP_ASM
extern "C" int func_002ABB80(void*);
extern "C" void func_002ABB38(void*);
// PORT: same ABI as the unit's func_002ACB80(void*, int, int, float); the float is
// the 2nd parameter in the original, which orders the argument moves.
void func_002ACB80_f(void* voice, float v, int a, int b) __asm__("func_002ACB80");

struct sVoiceD650 {
    int state;      // 0x0
    int pad_4[2];
    int id;         // 0xC
    char pad[0xC0 - 0x10];
};

extern "C" void func_002AD650(void* self, int id, float v)
{
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) == 0) {
            // PORT: pointer arithmetic through int
            sVoiceD650* e = (sVoiceD650*)(i * 0xC0 + *(int*)((char*)self + 0x8EC));
            if (e->state == 1 && e->id == id) {
                if (v != 0.0f) {
                    func_002ACB80_f(e, v, -1, 1);
                } else {
                    func_002ABB38(e);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD730);
#ifdef SKIP_ASM
extern "C" int func_002ABB80(void*);

struct sVoiceAD730 {
    int pad_0[2];
    int active;     // 0x8
    char pad[0xC0 - 0xC];
};

extern "C" int func_002AD730(void* self)
{
    int count = 0;
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) == 0) {
            // PORT: pointer arithmetic through int
            sVoiceAD730* e = (sVoiceAD730*)(i * 0xC0 + *(int*)((char*)self + 0x8EC));
            if (e->active != 0) {
                count++;
            }
        }
    }
    return count;
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD7A8);
#ifdef SKIP_ASM
extern "C" int func_002ABB80(void*);

extern "C" int func_002AD7A8(void* self)
{
    int count = 0;
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) == 0) {
            count++;
        }
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD810);
#ifdef SKIP_ASM
struct sBankVoice {
    char pad[0x5c];
    float value;
    char pad2[0xc0 - 0x60];
};

extern "C" void func_002AD810(void* self)
{
    for (int i = 0; i < 64; i++) {
        (*(sBankVoice**)((char*)self + 0x8ec))[i].value = -1.0f;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD848__FPv);
#ifdef SKIP_ASM
void* func_002AD848(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 0x4) = -1;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD860);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_002AD860(int* self, int flags)
{
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD888);
#ifdef SKIP_ASM
extern "C" void func_002AD940(void*);
void func_002AD970(void* self, int a1);
void func_002AD980(void* self);

struct sBmKeyD888 {
    short a;
    short id;
    int v;
};

// PORT: 64-bit long sound key
extern "C" void func_002AD888(void* self, int a1, long key, int b, int c, int d, int e, int f)
{
    func_002AD940(self);
    func_002AD970(self, a1);
    // PORT: the 8-byte key is copied through its in-memory layout
    *(sBmKeyD888*)((char*)self + 0xC) = *(sBmKeyD888*)&key;
    *(int*)((char*)self + 0x18) = b;
    *(int*)((char*)self + 0x1C) = c;
    *(int*)((char*)self + 0x20) = d;
    *(int*)((char*)self + 0x24) = e;
    *(int*)((char*)self + 0x28) = f;
    func_002AD980(self);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD930);
#ifdef SKIP_ASM
extern "C" int func_002AD930(void* self)
{
    return *(int*)((char*)self + 0x4) == -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD940);
#ifdef SKIP_ASM
void func_002AD990(void* self);
void func_002AD970(void* self, int a1);

extern "C" void func_002AD940(void* self)
{
    func_002AD990(self);
    func_002AD970(self, -1);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD970__FPvi);
#ifdef SKIP_ASM
void func_002AD970(void* self, int a1)
{
    *(int*)((char*)self + 0x4) = a1;
    *(int*)((char*)self + 0x8) = a1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD980__FPv);
#ifdef SKIP_ASM
void func_002AD980(void* self)
{
    *(int*)self = 1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD990__FPv);
#ifdef SKIP_ASM
void func_002AD990(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD998);
#ifdef SKIP_ASM
class func_002AD998_cObj {
public:
    char data[0x8D8];
    virtual void v01();
};

extern func_002AD998_cObj* D_004A3778;

extern "C" void func_002AD998()
{
    D_004A3778->v01();
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002AD9C8);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADAC8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_003B5948(int id);
extern "C" void func_002A97C0(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern void* D_00483BA8[];

struct sBmVEntryDAC8 {
    short delta;
    short index;
    void* fn;
};
struct sBmVtblDAC8 {
    sBmVEntryDAC8 e[4];
} __attribute__((aligned(8)));
extern const sBmVtblDAC8 D_00483BC0_DAC8 __asm__("D_00483BC0");

struct sBmSlotDAC8 {
    char pad_0x0[0x2C];
};

struct sSndPlayerDAC8 {
    char* vbase;                // 0x0
    char pad_0x4[0x98 - 0x4];
    sBmSlotDAC8 slots[48];      // 0x98
    void** vtbl;                // 0x8D8
};

extern "C" void func_002ADAC8(sSndPlayerDAC8* self, int flags)
{
    sBmSlotDAC8* end = self->slots + 48;
    self->vtbl = D_00483BA8;
    *(const sBmVtblDAC8**)(self->vbase + 4) = &D_00483BC0_DAC8;
    if (flags == 0) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sBmVtblDAC8 vt = D_00483BC0_DAC8;
        *(sBmVtblDAC8**)(self->vbase + 4) = &vt;
        char* base = self->vbase - 0x8DC;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483BC0_DAC8.e[1].delta + d;
    }
    // PORT: function pointer passed as int
    func_003B5948((int)func_002AD998);
    D_004A3778 = 0;
    if (self->slots != 0) {
        sBmSlotDAC8* p = end;
        while (self->slots != p) {
            p--;
            func_002AD860((int*)p, 0);
        }
    }
    func_002A97C0(self, 0);
    if (flags & 2) {
        func_002ADEE8(self->vbase, 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void func_002AD998();
extern "C" void* func_003B5910(void*);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADBF0__FPv);
#ifdef SKIP_ASM
void* func_002ADBF0(void* self)
{
    return func_003B5910((void*)func_002AD998);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADC10);
#ifdef SKIP_ASM
extern "C" void func_002ADC10(void* self)
{
    if (*(int*)((char*)self + 0x94) == 0) {
        *(int*)((char*)self + 0x88) += 1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002ADC30);
#ifdef SKIP_ASM
extern "C" int func_002ADC30(void* self, int n)
{
    for (int i = 0; i < 48; i++) {
        if (func_002AD930((char*)self + 0x98 + i * 0x2C) != 0) {
            if (--n == 0) {
                return i;
            }
        }
    }
    return -1;
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002ADCA0);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADD78);
#ifdef SKIP_ASM
extern "C" void func_002ADD78(char* self, int idx)
{
    int off = idx * 0x2C + 0x98;
    func_002AD940(self + off);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADDA0);
#ifdef SKIP_ASM
extern "C" void func_002AD940(void*);

extern "C" void func_002ADDA0(void* self)
{
    char* p = (char*)self + 0x98;
    int i;
    for (i = 47; i >= 0; i--) {
        func_002AD940(p);
        p += 0x2C;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADDE0);
#ifdef SKIP_ASM
extern "C" void func_002AD940(void*);

struct sBmKeyDDE0 {
    short a;
    short id;
    union {
        int v;
        short s;
    };
};

static inline int func_002ADDE0_match(char* e, sBmKeyDDE0 k)
{
    int r = 0;
    if (k.id == *(short*)(e + 0xE)) {
        if ((k.id != -1 && k.s == *(short*)(e + 0x10)) || k.v == *(int*)(e + 0x10)) {
            r = 1;
        }
    }
    return r;
}

// Release-build assert: expands to an empty do { } while (0). Its loop notes keep GCC from reversing the
// slot loop into a count-down, as in the target.
#define ASSERT_DDE0(cond) do { } while (0)

// PORT: callers in this unit declare func_002ADDE0(void*, long); the key is the same 8 bytes viewed as a struct.
void func_002ADDE0_impl(void* self, sBmKeyDDE0 key) __asm__("func_002ADDE0");

// Stops every one of the 48 monitored sounds that matches the key.
void func_002ADDE0_impl(void* self, sBmKeyDDE0 key)
{
    for (int i = 0; i < 48; i++) {
        if (func_002ADDE0_match((char*)self + 0x98 + i * 0x2C, key)) {
            func_002AD940((char*)self + 0x98 + i * 0x2C);
        }
        ASSERT_DDE0(i < 48);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADE88);
#ifdef SKIP_ASM
class func_002ADE88_cObj {
public:
    virtual void v01(int a);
};

extern "C" func_002ADE88_cObj* func_002A8FA0();
extern char D_00483C00[];
extern void* D_004A377C;

extern "C" void* func_002ADE88(void* self, int a)
{
    *(void**)((char*)self + 0x4) = D_00483C00;
    D_004A377C = self;
    func_002ADE88_cObj* obj = func_002A8FA0();
    *(func_002ADE88_cObj**)self = obj;
    obj->v01(a);
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADEE8);
#ifdef SKIP_ASM
class func_002ADEE8_cObj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03(int a);
};

void operator_delete(int* ptr);
extern char D_00483C00[];
extern void* D_004A377C;

extern "C" void func_002ADEE8(void* self, int flags)
{
    *(void**)((char*)self + 0x4) = D_00483C00;
    (*(func_002ADEE8_cObj**)self)->v03(flags);
    operator_delete(*(int**)self);
    D_004A377C = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADF58);
#ifdef SKIP_ASM
extern "C" void func_002ADF58(void) {

}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADF60);
#ifdef SKIP_ASM
int BXrand();

extern "C" int func_002ADF60()
{
    return BXrand();
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADF80);
#ifdef SKIP_ASM
class func_002ADF80_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(int a);
};

struct func_002ADF80_sHolder {
    func_002ADF80_cObj* obj;
};

extern "C" int func_002ADF80(func_002ADF80_sHolder* self, int a)
{
    return self->obj->v02(a);
}
#endif

extern void* D_004D3E98[];

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADFB0__Fi);
#ifdef SKIP_ASM
int func_002ADFB0(int self)
{
    return *(int*)((char*)(void*)D_004D3E98 + self * 4);
}
#endif

extern "C" void* func_002523A8(void* self);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADFC8);
#ifdef SKIP_ASM
extern void* (*D_004A378C)(void*, int, int);
extern char D_00483288[];

extern "C" void* func_002ADFC8(int a)
{
    void* r = 0;
    if (D_004A378C != 0) {
        r = D_004A378C(D_00483288, a, 0);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE000__FPv);
#ifdef SKIP_ASM
void* func_002AE000(void* self)
{
    return func_002523A8(self);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE020);
#ifdef SKIP_ASM
extern void (*D_004A3798)();

extern "C" int func_002AE020()
{
    if (D_004A3798 != 0) {
        D_004A3798();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE048);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void REAL_abortmessage();
extern "C" void func_004175C8();
extern "C" void* func_00252FA0(void* a0, int a1, int a2);
extern "C" void* func_002526B8(void* block, int size);
extern "C" void SYNCTASK_add(int (*fn)(), int a, int b);
extern int D_004A379C;
extern void (*D_004A3780)();
extern void (*D_004A3784)();
extern void* (*D_004A378C)(void*, int, int);
extern void* (*D_004A3790)(void*, int);
extern void* (*D_004A3794)(void*);

struct sBankMonSlot28_E048 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
};
// D_004D3EF8's own type is defined later in the unit; bind a same-layout view.
extern sBankMonSlot28_E048 D_004D3EF8_E048[] __asm__("D_004D3EF8");

extern "C" void func_002AE048(void (*cb)(), int id)
{
    for (int i = 0; i < 24; i++) {
        D_004D3E98[i] = 0;
        D_004D3EF8_E048[i].f8 = -1;
        D_004D3EF8_E048[i].f4 = -1;
        D_004D3EF8_E048[i].f0 = -1;
        D_004D3EF8_E048[i].f18 = 0;
    }
    D_004A3798 = cb;
    D_004A379C = id;
    func_003B5910((void*)id);
    SYNCTASK_add(func_002AE020, 5, 100);
    D_004A3780 = REAL_abortmessage;
    D_004A3784 = func_004175C8;
    D_004A378C = func_00252FA0;
    D_004A3790 = func_002526B8;
    D_004A3794 = func_002AE000;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE100);
#ifdef SKIP_ASM
extern "C" int func_002AE020();
extern "C" void SYNCTASK_del(int (*fn)());
extern "C" void func_003B5948(int id);
extern void (*D_004A3798)();
extern int D_004A379C;

extern "C" void func_002AE100()
{
    if (D_004A3798 != 0) {
        func_003B5948(D_004A379C);
        SYNCTASK_del(func_002AE020);
        D_004A3798 = 0;
        D_004A379C = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE138);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);

extern "C" void func_002AE138(void* self)
{
    func_00416210(self, 0, 0x70);
    *(int*)((char*)self + 0x0) = -1;
    *(int*)((char*)self + 0x4) = -1;
    *(char*)((char*)self + 0x66) = -1;
    *(int*)((char*)self + 0x5C) = -1;
    *(int*)((char*)self + 0x8) = -1;
    *(char*)((char*)self + 0x65) = 1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE188);
#ifdef SKIP_ASM
extern "C" void func_002AE188(void* p)
{
    for (int i = 0; i < 24; i++) {
        if (D_004D3E98[i] == p) {
            D_004D3E98[i] = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE1B8);
#ifdef SKIP_ASM
extern "C" int func_002AE1B8(void)
{
    for (int i = 0; i < 24; i++) {
        if (D_004D3E98[i] == 0) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE1F0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);

extern "C" void func_002AE1F0(int* self)
{
    func_00416210(self, 0, 0x28);
    self[2] = -1;
    self[1] = -1;
    self[0] = -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE230);
#ifdef SKIP_ASM
struct sBankSlot_2AE230 {
    int id;         // 0x0
    int pad4;
    int bank;       // 0x8
    char pad[0x28 - 0xC];
};
// D_004D3EF8's own type is defined later in the unit; bind a same-layout view.
extern sBankSlot_2AE230 D_004D3EF8_2AE230[24] __asm__("D_004D3EF8");

// Finds a slot: bank < 0 asks for a free slot, otherwise the slot holding bank (and id, unless id < 0).
extern "C" int func_002AE230(int bank, int id)
{
    sBankSlot_2AE230* s = D_004D3EF8_2AE230;
    for (int i = 0; i < 24; i++, s++) {
        if (bank < 0) {
            if (s->bank < 0) {
                // the do/while(0) wrapper (a compiled-out macro block) is needed to match register allocation
                do {
                    return i;
                } while (0);
            }
        } else if (s->bank == bank) {
            if (id < 0 || s->id == id)
                return i;
        }
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE290);
#ifdef SKIP_ASM
extern "C" int func_002AE290(void) {
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AE298);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sBankMonSlot28v {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
};
// sBankMonSlot28 / D_004D3EF8 are defined later in the unit; bind a same-layout view.
extern sBankMonSlot28v D_004D3EF8_v[] __asm__("D_004D3EF8");
extern "C" int func_002AE230(int a, int b);

extern "C" int func_002AE298(int a, int unused, int b, int c)
{
    int i = func_002AE230(a, b);
    if (i >= 0 || (i = func_002AE230(-1, -1)) >= 0) {
        sBankMonSlot28v* e = &D_004D3EF8_v[i];
        e->f1C = 1;
        e->f8 = a;
        e->f0 = b;
        e->f4 = c;
        return c;
    }
    return -13;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AE328);
#ifdef SKIP_ASM
struct sBankMonSlot28 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
};
extern sBankMonSlot28 D_004D3EF8[];
extern "C" int func_002AE230(int a, int b);
extern "C" int func_003B6300(int id);

extern "C" int func_002AE328(int a, int b)
{
    int none = -1;
    int i = func_002AE230(a, b);
    if (i < 0) {
        return -1;
    }
    sBankMonSlot28* e = &D_004D3EF8[i];
    if (e->f4 >= 0) {
        func_003B6300(-1);
        e->f14 = 0;
        e->f4 = none;
        e->f8 = none;
        e->f0 = none;
        e->f1C = 0;
        e->f24 = none;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AE3A8);
#ifdef SKIP_ASM
extern sBankMonSlot28 D_004D3EF8[];
extern "C" int func_002AE230(int a, int b);
extern "C" int func_002AE328(int a, int b);

extern "C" int func_002AE3A8(int a)
{
    int best = 0x7FFFFFF;
    int bestIdx = -1;
    int i = 0;
    sBankMonSlot28* tbl = D_004D3EF8;
    int id;
    while (i < 24 && (id = func_002AE230(a, i)) >= 0) {
        int t = tbl[id].f24;
        if (t >= 0 && t < best) {
            best = t;
            bestIdx = i;
        }
        i++;
    }
    if (bestIdx == -1) {
        return 0;
    }
    return func_002AE328(a, bestIdx);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE478);
#ifdef SKIP_ASM
extern "C" int func_003B7B00(int n, int m);

extern "C" int func_002AE478(int n, int m)
{
    int size = n * 0xC + 0x70;
    if (m > 0) {
        size += func_003B7B00(n, m);
    }
    return size + (0x10 - (size & 0xF));
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE4C0);
#ifdef SKIP_ASM
struct sBankDesc_2AE4C0 { char c[24]; };
struct sBankEnt_2AE4C0 { int f0; int f4; int f8; };
extern "C" int func_002AE1B8(void);
extern "C" void func_002AE138(void* self);
extern "C" int func_003B7818(void* desc, int n, int m, void* mem, int size);
extern "C" int func_003BA020(void* desc);
extern char D_004A37A8[];
extern "C" int sprintf(char* buf, const char* fmt, ...);

extern "C" int func_002AE4C0(char* name, sBankDesc_2AE4C0* desc, int count, int m, char* mem, int size)
{
    int slot = func_002AE1B8();
    if (slot < 0)
        return -13;
    D_004D3E98[slot] = mem;
    mem += 0x70;
    func_002AE138(D_004D3E98[slot]);
    char* b = (char*)D_004D3E98[slot];
    *(char**)(b + 0x6C) = mem;
    mem = count * 12 + mem;
    int off = mem - b;
    mem = mem + (0x10 - off % 16);
    size -= mem - b;
    int i;
    for (i = 0; i < count; i++)
        (*(sBankEnt_2AE4C0**)(b + 0x6C))[i].f4 = -1;
    if (desc)
        *(sBankDesc_2AE4C0*)(b + 0x30) = *desc;
    else
        func_003BA020(b + 0x30);
    *(char*)(b + 0x35) = 0;
    sprintf(b + 0x1C, D_004A37A8, 11, name);
    if (m > 0)
        *(int*)(b + 0x0) = func_003B7818(b + 0x30, count, m, mem, size);
    else
        *(char*)(b + 0x64) = 1;
    if (*(int*)(b + 0x0) < 0 && *(signed char*)(b + 0x64) == 0)
        return *(int*)(b + 0x0);
    *(char*)(b + 0x66) = count;
    *(int*)(b + 0x14) = 0x7F;
    *(int*)(b + 0x10) = 0;
    return slot;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AE690);
#ifdef SKIP_ASM
extern void* (*D_004A3794)(void*);
extern "C" void func_003B7838(int id);

extern "C" void func_002AE690(int idx)
{
    void* m = D_004D3E98[idx];
    if (*(signed char*)((char*)m + 0x64) != 0) {
        int id = func_002AE230(idx, -1);
        while (id >= 0) {
            sBankMonSlot28* e = &D_004D3EF8[id];
            if (D_004A3794 != 0 && e->f14 != 0) {
                D_004A3794((void*)e->f14);
            }
            func_002AE1F0((int*)e);
            id = func_002AE230(idx, -1);
        }
    } else {
        func_003B7838(*(int*)m);
    }
    func_002AE188(m);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE768);
#ifdef SKIP_ASM
extern "C" void func_002AE768(unsigned int idx, int a1, int a2)
{
    if (idx < 24) {
        void* m = D_004D3E98[idx];
        if (m != 0 && *(signed char*)((char*)m + 0x64) == 0) {
            *(int*)((char*)m + 0x28) = a1;
            *(int*)((char*)m + 0x2c) = a2;
        }
    }
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002AE7A8);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AE9F8);
#ifdef SKIP_ASM
extern "C" void func_003B7D80(void*);

extern "C" void func_002AE9F8(int i)
{
    void* p = D_004D3E98[i];
    if (*(signed char*)((char*)p + 0x64) == 0) {
        func_003B7D80(*(void**)((char*)*(void**)((char*)p + 0x6C) + 0x4));
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEA38);
#ifdef SKIP_ASM
extern "C" void func_002AEFA8(int a0);

extern "C" int func_002AEA38(int idx)
{
    void* p = D_004D3E98[idx];
    if (p != 0) {
        if (*(char*)((char*)p + 0x65) != 0) {
            func_002AEFA8(0);
        }
    }
    return *(int*)((char*)D_004D3E98[idx] + 0x50);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEAA8);
#ifdef SKIP_ASM
extern "C" void func_002AEFA8(int a0);

struct sMonEntC { int f0; int f4; int f8; };

extern "C" int func_002AEAA8(int idx, int sub)
{
    void* m = D_004D3E98[idx];
    if (m != 0 && *(signed char*)((char*)m + 0x65) != 0) {
        func_002AEFA8(0);
    }
    if (sub < 0) {
        return *(int*)((char*)m + 0x54);
    }
    if (sub < *(signed char*)((char*)m + 0x66)) {
        if ((*(sMonEntC**)((char*)m + 0x6C))[sub].f4 >= 0) {
            return (*(sMonEntC**)((char*)m + 0x6C))[sub].f8;
        }
        return -8;
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEB40);
#ifdef SKIP_ASM
extern "C" void func_002AEFA8(int a0);

struct sEntryEB40 { int pad0; int key; int value; };

extern "C" int func_002AEB40(int idx, int key)
{
    void* ch = D_004D3E98[idx];
    if (ch != 0 && *(char*)((char*)ch + 0x65) != 0) {
        func_002AEFA8(0);
    }
    for (int i = 0; i < *(signed char*)((char*)ch + 0x66); i++) {
        sEntryEB40* e = &(*(sEntryEB40**)((char*)ch + 0x6C))[i];
        if (e->key == key) {
            return e->value;
        }
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEBD0);
#ifdef SKIP_ASM
extern "C" void func_002AEFA8(int a0);

extern "C" int func_002AEBD0(int idx)
{
    if (D_004D3E98[idx] != 0) {
        if (*(signed char*)((char*)D_004D3E98[idx] + 0x65) != 0) {
            func_002AEFA8(0);
        }
        return *(int*)((char*)D_004D3E98[idx] + 0x58);
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEC28);
#ifdef SKIP_ASM
extern "C" int func_002AEC28(int idx)
{
    void* m = D_004D3E98[idx];
    if (m == 0) {
        return -8;
    }
    *(char*)((char*)m + 0x65) = 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEC58);
#ifdef SKIP_ASM
extern void* D_004D3E98[];
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" int func_003B6670(int h, int sub, void* hdr, void* buf, unsigned int* pos);
extern "C" int func_003B8AD8(int h);
extern "C" int func_003B86C0(int h);
extern "C" int func_003B7B48(int h, void* out);
// PORT: the unit declares func_003B7C40(int, int); the second argument is an out-pointer
extern "C" void func_003B7C40(int h, int v);
extern "C" int func_003B7F18(int h);

struct sMonSub_EC58 {
    int size;   // 0x0
    int id;     // 0x4
    int pos;    // 0x8
};

struct sMonSlot_EC58 {
    int h;              // 0x0
    int sub;            // 0x4
    char pad08[0x4];
    int status;         // 0xC
    char pad10[0x38];
    int f48;            // 0x48
    int f4C;            // 0x4C
    int f50;            // 0x50
    int f54;            // 0x54
    int busy;           // 0x58
    int f5C;            // 0x5C
    int f60;            // 0x60
    signed char isMem;  // 0x64
    signed char dirty;  // 0x65
    signed char count;  // 0x66
    char pad67[0x5];
    sMonSub_EC58* subs; // 0x6C
};

struct sStrmInfo_EC58 {
    int count;
    int pad[3];
};

struct sStrmState_EC58 {
    int state;  // 0x0
    int a;      // 0x4
    int b;      // 0x8
    int c;      // 0xC
};

struct sStrmPos_EC58 {
    unsigned int samples;   // 0x0
    int pad[7];
};

struct sStrmHdr_EC58 {
    unsigned short rate;
    char pad[0xE];
};

// PORT: the end of this function stores the out-pointers themselves into the slot (as in the original)
extern "C" int func_002AEC58(int idx, int* outA, int* outB)
{
    sMonSlot_EC58* m = (sMonSlot_EC58*)D_004D3E98[idx];
    *outA = 0;
    *outB = 0;
    if (m == 0) {
        return -1;
    }
    int f60 = -8;
    m->busy = 1;
    if (m->h < 0) {
        return -2;
    }
    m->dirty = 1;
    func_003B58A0();
    sStrmInfo_EC58 info;
    sStrmState_EC58 st;
    sStrmHdr_EC58 hdr;
    char buf[0x70];
    sStrmPos_EC58 pos;
    if (m->isMem != 0) {
        if (m->sub >= 0 && m->subs->id >= 0) {
            f60 = func_003B6670(m->h, m->sub, &hdr, buf, &pos.samples);
            if (f60 >= 0) {
                *outB = func_003B8AD8(m->subs->id);
                if (*outB < 0) {
                    *outB = 0;
                    m->subs->id = -1;
                    goto done;
                }
                *outB *= 10;
                *outA = (int)((float)pos.samples / (float)hdr.rate * 1000.0f) - *outB;
            }
            m->subs->pos = *outB;
            m->f50 = m->subs->size;
            m->status = func_003B86C0(m->subs->id);
            m->f5C = m->subs->id;
        }
    } else {
        f60 = func_003B7B48(m->h, &info);
        m->f50 = 0;
        if (info.count >= m->count) {
            m->busy = 0;
        }
        for (int j = 0; j < m->count; j++) {
            m->subs[j].pos = 0;
            if (m->subs[j].id < 0) {
                continue;
            }
            func_003B7C40(m->subs[j].id, (int)&st);
            switch (st.state) {
            case 1:
                m->subs[j].pos = m->subs[j].size;
                m->f54 += m->subs[j].size;
                m->f50 += st.c;
                m->busy = 0;
                m->f5C = m->subs[j].id;
                break;
            case 0:
            case 2:
                *outA = st.a;
                *outB = st.b;
                if (outA == 0 && outB == 0) {
                    *outA = 0;
                    *outB = m->subs[j].size;
                }
                m->subs[j].pos = *outB;
                m->f54 += *outB;
                m->f50 += st.c;
                if (st.c < st.b) {
                    m->busy = 0;
                }
                m->f5C = m->subs[j].id;
                break;
            default:
                m->subs[j].id = -1;
                break;
            }
        }
        m->status = func_003B7F18(m->h);
    }
done:
    m->f48 = (int)outA;
    m->f4C = (int)outB;
    m->f60 = f60;
    m->dirty = 0;
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEFA8);
#ifdef SKIP_ASM
extern void* D_004D3E98[];
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" int func_003B6670(int h, int sub, void* hdr, void* buf, unsigned int* pos);
extern "C" int func_003B8AD8(int h);
extern "C" int func_003B86C0(int h);
extern "C" int func_003B7B48(int h, void* out);
// PORT: the unit declares func_003B7C40(int, int); the second argument is an out-pointer
extern "C" void func_003B7C40(int h, int v);
extern "C" int func_003B7F18(int h);

struct sMonSub_EFA8 {
    int size;   // 0x0
    int id;     // 0x4
    int pos;    // 0x8
};

struct sMonSlot_EFA8 {
    int h;              // 0x0
    int sub;            // 0x4
    char pad08[0x4];
    int status;         // 0xC
    char pad10[0x38];
    int f48;            // 0x48
    int f4C;            // 0x4C
    int f50;            // 0x50
    int f54;            // 0x54
    int busy;           // 0x58
    int f5C;            // 0x5C
    int f60;            // 0x60
    signed char isMem;  // 0x64
    signed char dirty;  // 0x65
    signed char count;  // 0x66
    char pad67[0x5];
    sMonSub_EFA8* subs; // 0x6C
};

struct sStrmInfo_EFA8 {
    int count;
    int pad[3];
};

struct sStrmState_EFA8 {
    int state;  // 0x0
    int a;      // 0x4
    int b;      // 0x8
    int c;      // 0xC
};

struct sStrmPos_EFA8 {
    unsigned int samples;   // 0x0
    int pad[7];
};

struct sStrmHdr_EFA8 {
    unsigned short rate;
    char pad[0xE];
};

extern "C" void func_002AEFA8(int reset)
{
    func_003B58A0();
    for (int i = 0; i < 24; i++) {
        sMonSlot_EFA8* m = (sMonSlot_EFA8*)D_004D3E98[i];
        if (m == 0) {
            continue;
        }
        if (reset != 0) {
            m->f60 = 0;
            m->dirty = 1;
            continue;
        }
        int f60 = -8;
        int f48 = 0;
        int f4C = 0;
        m->busy = 1;
        if (m->h >= 0) {
            sStrmInfo_EFA8 info;
            sStrmState_EFA8 st;
            sStrmHdr_EFA8 hdr;
            char buf[0x70];
            sStrmPos_EFA8 pos;
            if (m->isMem != 0) {
                if (m->sub >= 0 && m->subs->id >= 0) {
                    f60 = func_003B6670(m->h, m->sub, &hdr, buf, &pos.samples);
                    if (f60 >= 0) {
                        f4C = func_003B8AD8(m->subs->id);
                        if (f4C < 0) {
                            f4C = 0;
                            m->subs->id = -1;
                            goto done;
                        }
                        f4C *= 10;
                        f48 = (int)((float)pos.samples / (float)hdr.rate * 1000.0f) - f4C;
                    }
                    m->subs->pos = f4C;
                    m->f50 = m->subs->size;
                    m->status = func_003B86C0(m->subs->id);
                    m->f5C = m->subs->id;
                }
            } else {
                f60 = func_003B7B48(m->h, &info);
                m->f50 = 0;
                if (info.count >= m->count) {
                    m->busy = 0;
                }
                for (int j = 0; j < m->count; j++) {
                    m->subs[j].pos = 0;
                    if (m->subs[j].id < 0) {
                        continue;
                    }
                    func_003B7C40(m->subs[j].id, (int)&st);
                    switch (st.state) {
                    case 1:
                        m->subs[j].pos = m->subs[j].size;
                        m->f54 += m->subs[j].size;
                        m->f50 += st.c;
                        m->busy = 0;
                        m->f5C = m->subs[j].id;
                        break;
                    case 0:
                    case 2:
                        f48 = st.a;
                        f4C = st.b;
                        if (f48 == 0 && f4C == 0) {
                            f48 = f4C;
                            f4C = m->subs[j].size;
                        }
                        m->subs[j].pos = f4C;
                        m->f54 += f4C;
                        m->f50 += st.c;
                        if (st.c < st.b) {
                            m->busy = 0;
                        }
                        m->f5C = m->subs[j].id;
                        break;
                    default:
                        m->subs[j].id = -1;
                        break;
                    }
                }
                m->status = func_003B7F18(m->h);
            }
        }
    done:
        m->f48 = f48;
        m->f4C = f4C;
        m->f60 = f60;
        m->dirty = 0;
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF2F0);
#ifdef SKIP_ASM
extern "C" void func_002AEFA8(int a0);

extern "C" int func_002AF2F0(int idx, int* a, int* b)
{
    void* m = D_004D3E98[idx];
    if (m == 0) {
        return -8;
    }
    if (*(signed char*)((char*)m + 0x65) != 0) {
        func_002AEFA8(0);
    }
    *a = *(int*)((char*)m + 0x48);
    *b = *(int*)((char*)m + 0x4C);
    if (*(int*)((char*)m + 0x60) != 0) {
        return *(int*)((char*)m + 0x60);
    }
    return *(int*)((char*)m + 0x5C);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF370);
#ifdef SKIP_ASM
extern "C" int func_003E4E98();
extern "C" void func_004139F8(float);
extern int D_00450DC8[];

extern "C" void func_002AF370(void)
{
    func_004139F8((float)func_003E4E98() / (float)D_00450DC8[0] * 1000.0f);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF3B8);
#ifdef SKIP_ASM
extern "C" int func_002AF3B8(int arg0) {
    void *temp_4;

    temp_4 = D_004D3E98[arg0];
    if ((temp_4 != 0) && ((*(signed char *)((char*)(temp_4) + (0x64))) != 0)) {
        return (*(int *)((char*)(temp_4) + (0)));
    }
    return -1;
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF3F0);
#ifdef SKIP_ASM
extern "C" int func_002AF3F0(int arg0) {
    void *temp_4;

    temp_4 = D_004D3E98[arg0];
    if ((temp_4 != 0) && ((*(signed char *)((char*)(temp_4) + (0x64))) == 0)) {
        return (*(int *)((char*)(temp_4) + (0)));
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF428);
#ifdef SKIP_ASM
extern "C" void func_002AEFA8(int a0);

extern "C" int func_002AF428(int idx)
{
    if (D_004D3E98[idx] != 0) {
        if (*(signed char*)((char*)D_004D3E98[idx] + 0x65) != 0) {
            func_002AEFA8(0);
        }
        return *(int*)((char*)D_004D3E98[idx] + 0xC);
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF480);
#ifdef SKIP_ASM
extern "C" int func_002AF480(int idx)
{
    void* m = D_004D3E98[idx];
    if (m != 0) {
        return *(int*)((char*)m + 0x14);
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF4B0);
#ifdef SKIP_ASM
extern "C" int func_002AF4B0(int idx)
{
    void* m = D_004D3E98[idx];
    if (m != 0) {
        return *(int*)((char*)m + 0x10);
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF4E0);
#ifdef SKIP_ASM
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" int func_003B8050(void* h, int a, int b);
extern "C" int func_003B88C8(void* h, int a, int b);

extern "C" int func_002AF4E0(int idx, int a, int b)
{
    void* m = D_004D3E98[idx];
    int r = -8;
    if (m != 0) {
        func_003B58A0();
        if (*(signed char*)((char*)m + 0x64) != 0) {
            r = func_003B88C8(*(void**)m, a, b);
        } else {
            r = func_003B8050(*(void**)m, a, b);
        }
        func_003B58D8();
        *(int*)((char*)m + 0x10) = b;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF580);
#ifdef SKIP_ASM
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" int func_003B8010(void* h, int a);
extern "C" int func_003B8700(void* h, int a);

extern "C" int func_002AF580(int idx, int a)
{
    void* m = D_004D3E98[idx];
    int r = -8;
    if (m != 0) {
        func_003B58A0();
        if (*(signed char*)((char*)m + 0x64) != 0) {
            r = func_003B8700(*(void**)m, a);
        } else {
            r = func_003B8010(*(void**)m, a);
        }
        func_003B58D8();
        *(int*)((char*)m + 0x14) = a;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF608);
#ifdef SKIP_ASM
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" int func_003B8530(int h, int v, int c);
// PORT: the unit declares func_003B7EB0 as void; this caller uses its result.
int func_003B7EB0_r(int h, int v, int c) __asm__("func_003B7EB0");

extern "C" int func_002AF608(int idx, int c, int v, char busy)
{
    void* m = D_004D3E98[idx];
    int r = 0;
    if (busy == 0) {
        func_003B58A0();
        *(int*)((char*)m + 0x8) = c;
        if (*(signed char*)((char*)m + 0x64) != 0) {
            r = func_003B8530(*(int*)((char*)*(void**)((char*)m + 0x6C) + 0x4), v / 10, c);
        } else {
            r = func_003B7EB0_r(*(int*)m, v, c);
        }
        func_003B58D8();
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF6C0);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_002AEFA8(int a0);
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B85F0(int h, int v);
extern "C" void func_003B7E70(int h, int v);

extern "C" int func_002AF6C0(int idx, int v)
{
    void* m = D_004D3E98[idx];
    int r = 0;
    if (*(int*)((char*)func_0028B180() + 0x6280) == 0) return 0;
    if (*(signed char*)((char*)m + 0x65) != 0) {
        func_002AEFA8(0);
    }
    int cur = *(int*)((char*)m + 0xC);
    if (*(int*)((char*)m + 0x8) < 0 || *(int*)((char*)m + 0x8) == cur) {
        *(int*)((char*)m + 0x8) = -1;
        if (cur != v && v >= 0 && cur >= 0) {
            func_003B58A0();
            if (*(signed char*)((char*)m + 0x64) != 0) {
                func_003B85F0(*(int*)((char*)*(void**)((char*)m + 0x6C) + 0x4), v);
            } else {
                func_003B7E70(*(int*)m, v);
            }
            func_003B58D8();
            *(int*)((char*)m + 0xC) = v;
        }
    } else {
        r = -8;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF7A0);
#ifdef SKIP_ASM
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B7FB8(int h, int v);
extern "C" void func_003B8790(int h, int v);

extern "C" int func_002AF7A0(int idx, int reset)
{
    void* m = D_004D3E98[idx];
    unsigned short v;
    if (reset != 0) {
        v = 0;
        *(int*)((char*)m + 0x18) = *(unsigned short*)((char*)m + 0x3C);
    } else {
        v = *(int*)((char*)m + 0x18);
    }
    func_003B58A0();
    if (*(signed char*)((char*)m + 0x64) != 0) {
        func_003B8790(*(int*)((char*)*(void**)((char*)m + 0x6C) + 4), v);
    } else {
        func_003B7FB8(*(int*)m, v);
    }
    func_003B58D8();
    *(char*)((char*)m + 0x65) = 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF838);
#ifdef SKIP_ASM
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B78F8(int);
extern "C" void func_003B89E0(int);

extern "C" int func_002AF838(int idx)
{
    void* m = D_004D3E98[idx];
    func_003B58A0();
    if (*(signed char*)((char*)m + 0x64) != 0) {
        func_003B89E0(*(int*)((char*)*(void**)((char*)m + 0x6C) + 0x4));
    } else {
        func_003B78F8(*(int*)((char*)m + 0x0));
    }
    func_003B58D8();
    *(char*)((char*)m + 0x65) = 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF8A8);
#ifdef SKIP_ASM
extern "C" int func_002B0F48(void* self, int a1);
extern char* D_004A37B4;
extern int D_004A37BC;

// PORT: real signature is int(int); the unit later declares func_002AF8A8 as void() for its callback use.
extern "C" int func_002AF8A8_impl(int a) __asm__("func_002AF8A8");
extern "C" int func_002AF8A8_impl(int a)
{
    if (D_004A37BC != 0) {
        return -1;
    }
    return func_002B0F48(D_004A37B4, a);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF8E0__FPv);
#ifdef SKIP_ASM
void* func_002AF8E0(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x48) = t0;
    *(int*)self = -1;
    *(int*)((char*)self + 0x44) = t0;
    *(signed char*)((char*)self + 0x4) = (signed char)t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF900);
#ifdef SKIP_ASM
extern "C" void func_003D6CA0(void* a0);

extern "C" void func_002AF900(int* self, int flags)
{
    func_003D6CA0(*(void**)self);
    if (*(int*)((char*)self + 0x48) != 0) {
        func_002523A8(*(void**)((char*)self + 0x44));
    }
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AF960);
#ifdef SKIP_ASM
extern "C" int BXFILE_exists(const char* name);
extern "C" void* FILE_load(const char* name, int a1);
extern "C" int func_003D69F0(void* data);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" char* func_0041ACC0(const char* s, int c);
void* func_002AF8E0(void* self);
extern char D_004A37C0[];
extern char D_004832B0[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" int sprintf(char* buf, const char* fmt, ...);

// PORT: callers declare func_002AF960 as int(int, int, int); the body is (name, unused, data) returning an object pointer.
void* func_002AF960_impl(const char* name, int unused, void* data) __asm__("func_002AF960");

void* func_002AF960_impl(const char* name, int unused, void* data)
{
    char buf[0x50];
    int owned = data == 0;
    sprintf(buf, D_004A37C0, name);
    if (data == 0) {
        if (BXFILE_exists(buf) == 0) {
            return 0;
        }
        data = FILE_load(buf, 0);
    }
    char* obj = (char*)func_002AF8E0(cMemMan_alloc(0x4C, D_004832B0, 0, 0));
    *(int*)(obj + 0x48) = owned;
    *(void**)(obj + 0x44) = data;
    *(int*)obj = func_003D69F0(data);
    strcpy(obj + 4, name);
    char* p = func_0041ACC0(obj + 4, '\\');
    if (p == 0) {
        *(char**)(obj + 0x40) = obj + 4;
    } else {
        *(char**)(obj + 0x40) = p + 1;
    }
    return obj;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AFA58);
#ifdef SKIP_ASM
extern "C" int func_002AFA58(void* self, int a1)
{
    return a1 == *(int*)self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AFA68);
#ifdef SKIP_ASM
extern char* D_004A37B4;
extern "C" void func_002AA910(void* sys, int id, int a, int b, int c);
extern "C" void func_002B0088(void* self, int a, int b, int c);

struct sBmPair_FA68 {
    int a;
    int b;
};

struct sBmStream_FA68 {
    int f0;                     // 0x0
    int f4;                     // 0x4
    int f8;                     // 0x8
    char fC;                    // 0xC
    char pad_0xD[0xCC - 0xD];
    sBmPair_FA68 pairs[4];      // 0xCC
    int fEC;                    // 0xEC
    int fF0;                    // 0xF0
    char pad_0xF4[0x8C4 - 0xF4];
    int f8C4;                   // 0x8C4
    int f8C8;                   // 0x8C8
    int f8CC;                   // 0x8CC
    int f8D0;                   // 0x8D0
    char pad_0x8D4[0x8F4 - 0x8D4];
    int f8F4;                   // 0x8F4
    char pad_0x8F8[0x900 - 0x8F8];
    int f900;                   // 0x900
};

extern "C" void* func_002AFA68(void* mem, int a1, int a2, int a3, int a4, int a5, int a6)
{
    sBmStream_FA68* self = (sBmStream_FA68*)mem;
    self->f0 = a1;
    self->f4 = a2;
    self->f900 = 1;
    self->f8 = a6;
    self->fEC = 0;
    self->fF0 = 0;
    self->f8C4 = 0;
    self->f8C8 = 0;
    self->f8CC = 0;
    self->f8D0 = 0;
    self->f8F4 = 0;
    self->fC = 0;
    for (int i = 0; i < 4; i++) {
        self->pairs[i].a = 0;
        self->pairs[i].b = 0;
    }
    func_002AA910(*(void**)D_004A37B4, self->f4, a4, 0, 0x20000);
    func_002B0088(self, a1, a3, a5);
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AFB38);
#ifdef SKIP_ASM
extern "C" void func_002AABD0(void* self, int i);
extern "C" void func_002AF900(int* self, int flags);
extern char* D_004A37B4;
extern int D_004A37B8;

struct sBmVoiceFB38 {
    void* handle;           // 0x0
    int active;             // 0x4
};

struct sBmPairFB38 {
    void* p[2];
};

struct sBankMonFB38 {
    int field_0x0;
    int id;                         // 0x4
    char pad_0x8[0xC4];
    sBmVoiceFB38 voices[(0xEC - 0xCC) / 8];   // 0xCC
    int voiceCount;                 // 0xEC
    int streamCount;                // 0xF0
    int* streams[(0x8D4 - 0xF4) / 4];         // 0xF4
    sBmPairFB38 pairs[1];           // 0x8D4
};

extern "C" void func_002AFB38(void* selfp, int flags)
{
    sBankMonFB38* self = (sBankMonFB38*)selfp;
    int i;
    for (i = 0; i < self->streamCount; i++) {
        if (self->streams[i] != 0) {
            func_002AF900(self->streams[i], 3);
        }
    }
    D_004A37B8 -= self->streamCount;
    for (i = 0; i < self->voiceCount; i++) {
        for (int j = 0; j < 2; j++) {
            if (self->pairs[i].p[j] != 0) {
                func_002523A8(self->pairs[i].p[j]);
            }
        }
        if (self->voices[i].active != 0) {
            func_002523A8(self->voices[i].handle);
            self->voices[i].active = 0;
            self->voices[i].handle = 0;
        }
    }
    func_002AABD0(*(void**)D_004A37B4, self->id);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AFC88);
#ifdef SKIP_ASM
extern "C" int func_002B0290(void* p);
extern "C" void* func_003D7EC8(void* p);
extern "C" void* func_003D8040(void* p);
extern char* D_004A37B4;

class func_002AFC88_cObj {
public:
    char data[0x1BC];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
};

// PORT: i is passed through as a pointer-sized handle
extern "C" void func_002AFC88(void* self, int i)
{
    if (func_002B0290(self) != 0) {
        if (*(int*)((char*)self + 0x900) != 0) {
            ((func_002AFC88_cObj*)D_004A37B4)->v04();
            if (func_003D7EC8((void*)i) != 0) {
                *(int*)((char*)self + 0x900) = 0;
            }
        } else {
            func_003D8040((void*)i);
            *(int*)((char*)self + 0x900) = 1;
        }
    } else {
        *(int*)((char*)self + 0x900) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AFD10);
#ifdef SKIP_ASM
extern "C" void* func_003D7EC8(void* p);

// PORT: real arity is (self, p); the unit later declares func_002AFD10(int)
void* func_002AFD10_impl(void* self, void* p) __asm__("func_002AFD10");

void* func_002AFD10_impl(void* self, void* p)
{
    void* r = func_003D7EC8(p);
    if (r != 0) {
        *(int*)((char*)self + 0x900) = 0;
    }
    return r;
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002AFD40);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0088);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_002A77F8(void* parser, void* src, int n);
extern "C" void func_002A7890(void* parser, int flags);
extern "C" void func_002A7A20(void* parser);
extern "C" int func_002A7C68(void* parser, int file);
extern "C" char* func_002A7DA0(void* parser);
extern "C" int func_002A7F90(void* parser);
extern "C" int func_002A7FF8(void* parser, const char* key, char* out);
void func_002AAB98_2B0088(void* self, int i, char* val) __asm__("func_002AAB98");
extern "C" int func_002AFD40(void* self, int a, char* name, int b, int c);
extern "C" int func_0041AA88(const char* a, const char* b);
extern void* D_004A37B0;
extern char* D_004A37B4;
extern char D_004A37C8[];
extern char D_004828C0[];
extern char D_004A37D0[];
extern char D_004832D8[];
extern char D_004832E8[];
extern char D_004A36E0[];
struct sBankList_0348;
extern "C" void func_002B0348(sBankList_0348* self, int a, int b, int c);

extern "C" void func_002B0088(void* p, int a1, int a2, int a3)
{
    char* self = (char*)p;
    char parser[0x810];
    char value[0x100];
    char v40[0x40];
    char path[0x80];
    char name[0x60];
    func_002A77F8(parser, D_004A37B0, 0x100);
    if (func_002A7C68(parser, a2) != 0)
    {
        func_002A7A20(parser);
        while (func_002A7F90(parser) == 0)
        {
            char* key = func_002A7DA0(parser);
            if (func_0041AA88(D_004A37C8, key) == 0)
            {
                func_002A7FF8(parser, D_004A37C8, v40);
                func_002AAB98_2B0088(*(void**)D_004A37B4, *(int*)(self + 4), v40);
            }
            if (func_0041AA88(D_004828C0, key) == 0)
            {
                func_002A7FF8(parser, D_004828C0, self + 0x6C);
                sprintf(value, D_004832D8, self + 0x6C);
                if (func_002AFD40(self, 1, value, a1, a2) == 0)
                    break;
                if (a3)
                {
                    sprintf(value, D_004832E8, self + 0x6C);
                    func_002AFD40(self, 0, value, a1, a2);
                }
                *(int*)(self + 0xEC) += 1;
            }
            if (func_0041AA88(D_004A37D0, key) == 0)
            {
                func_002A7FF8(parser, D_004A37D0, value);
                sprintf(path, D_004A36E0, self + 0x6C, name);
                func_002B0348((sBankList_0348*)self, (int)path, (int)name, 0);
            }
        }
    }
    func_002A7890(parser, 2);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B0290);
#ifdef SKIP_ASM
extern "C" int func_002AAE08(void* self, int i);
extern "C" float func_002AAE78(void* self, int i);
extern "C" int func_002AB028(void* self, int i);
extern char* D_004A37B4;

extern "C" int func_002B0290(void* p)
{
    int state = func_002AAE08(*(void**)D_004A37B4, *(int*)((char*)p + 0x4));
    if (state == 0) {
        return 1;
    }
    if (state != 1) {
        return 0;
    }
    if (func_002AB028(*(void**)D_004A37B4, *(int*)((char*)p + 0x4)) == 0) {
        return 0;
    }
    int ok = (int)func_002AAE78(*(void**)D_004A37B4, *(int*)((char*)p + 0x4)) < 500;
    int r = 0;
    if (ok) {
        r = state;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B0320);
#ifdef SKIP_ASM
extern "C" void func_002AAE40(void* self, int i);
extern char* D_004A37B4;

extern "C" void func_002B0320(void* p)
{
    func_002AAE40(*(void**)D_004A37B4, *(int*)((char*)p + 0x4));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0348);
#ifdef SKIP_ASM
extern "C" int func_002AF960(int a, int b, int c);
extern int D_004A37B8;

struct sBankList_0348 {
    char pad[0xF0];
    int count;     // 0xF0
    int ids[1];    // 0xF4
};

extern "C" void func_002B0348(sBankList_0348* self, int a, int b, int c)
{
    self->ids[self->count] = func_002AF960(a, b, c);
    if (self->ids[self->count] != 0) {
        self->count++;
        D_004A37B8++;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B03B8);
#ifdef SKIP_ASM
extern "C" unsigned int strlen(const char* s);

extern "C" int func_002B03B8(const char* name)
{
    int lang = 0;
    int len = strlen(name);
    if (name[len - 4] == '_') {
        if (name[len - 3] == 'e' && name[len - 2] == 'n' && name[len - 1] == 'g') {
            lang = 1;
        } else if (name[len - 3] == 'f' && name[len - 2] == 'r' && name[len - 1] == 'n') {
            lang = 2;
        } else if (name[len - 3] == 'g' && name[len - 2] == 'r' && name[len - 1] == 'm') {
            lang = 3;
        } else if (name[len - 3] == 's' && name[len - 2] == 'p' && name[len - 1] == 'n') {
            lang = 4;
        }
    }
    return lang;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B04D8);
#ifdef SKIP_ASM
struct sSndKey8_04D8 {
    long v;
} __attribute__((packed));
extern sSndKey8_04D8 D_004A37D8[];
extern sSndKey8_04D8 D_004A37E0[];
extern char* D_004A37B4;
extern char D_004832F8[];
extern char D_004A3590[];
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_002AFA58(void* self, int a1);
extern "C" int func_002B1520(void* sys, int a, int b);
extern "C" int func_002B03B8(const char* name);
extern "C" int func_002AAE08(void* self, int i);
extern "C" float func_002AAE78(void* self, int i);
extern "C" int func_002AB028(void* self, int i);
extern "C" void func_002AB0D0(void* self, int i, int w);
// PORT: func_002ADCA0 takes a 64-bit sound key by value and returns int.
extern "C" int func_002ADCA0_04D8(void*, int, long, void*, int, int, int, int) __asm__("func_002ADCA0");

typedef int (*Fn1_04D8)(void*, int, char*, int, int, int, int, float, int, int);

struct sBmVE_04D8 {
    short delta;
    short index;
    void* fn;
};

struct sBmObj_04D8 {
    char pad[0x40];
    int f40;
};

struct sBmList_04D8 {
    int f0;                     // 0x0
    int f4;                     // 0x4
    char pad8[0xE8];
    int count;                  // 0xF0
    sBmObj_04D8* ids[1];        // 0xF4
};

struct sBmArgs_04D8 {
    int f0;
    int f4;
    char pad8[4];
    unsigned short fC;
};

static inline sBmObj_04D8** at_04D8(sBmObj_04D8** base, int i)
{
    return base + i;
}

extern "C" int func_002B04D8_impl(sBmList_04D8* self, sBmArgs_04D8* a) __asm__("func_002B04D8");

extern "C" int func_002B04D8_impl(sBmList_04D8* self, sBmArgs_04D8* a)
{
    int idx = -1;
    int i;
    if (func_002AFA58(self->ids[a->f0], a->f0)) {
        idx = a->f0;
    } else {
        for (i = 0; i < self->count; i++) {
            if (func_002AFA58(self->ids[i], a->f0)) {
                idx = i;
            }
        }
    }
    if (idx >= 0 && func_002B1520(D_004A37B4, self->f0, a->fC)) {
        sBmObj_04D8** slot = at_04D8(self->ids, idx);
        int lang = func_002B03B8((char*)*slot + 4);
        char buf[0x100];
        sprintf(buf, D_004832F8, D_004A3590, D_004A37B4 + 0x158 + lang * 0x14, (char*)*slot + 4);
        char* d0 = D_004A37B4;
        sBmVE_04D8* vt0 = *(sBmVE_04D8**)(d0 + 0x1BC);
        int h = ((int (*)(void*, int, int))vt0[2].fn)(d0 + vt0[2].delta, self->f0, (*slot)->f40);
        char* d; sBmVE_04D8* vt;
        int t = (int)func_002AAE78(*(void**)D_004A37B4, self->f4);
        int r;
        if (func_002AAE08(*(void**)D_004A37B4, self->f4) != 0) {
            if (func_002AB028(*(void**)D_004A37B4, self->f4) != 0) {
                d = D_004A37B4;
                vt = *(sBmVE_04D8**)(d + 0x1BC);
                r = ((Fn1_04D8)vt[1].fn)(d + vt[1].delta, self->f4, buf, a->f4, *(int*)((char*)self + 0x8CC), -1, *(int*)((char*)self + 0x8D0), *(float*)((char*)self + 0x8F4), *(int*)((char*)self + 0x8F8), *(int*)((char*)self + 0x8FC));
                if (r >= 0) {
                    func_002ADCA0_04D8(**(char***)D_004A37B4 + 0x1D8, t, D_004A37D8[0].v, self, r, h, 0, 0);
                }
                return r;
            }
            d = D_004A37B4;
            vt = *(sBmVE_04D8**)(d + 0x1BC);
            r = ((Fn1_04D8)vt[1].fn)(d + vt[1].delta, self->f4, buf, a->f4, *(int*)((char*)self + 0x8CC), -1, *(int*)((char*)self + 0x8D0), *(float*)((char*)self + 0x8F4), *(int*)((char*)self + 0x8F8), *(int*)((char*)self + 0x8FC));
            if (r >= 0) {
                func_002ADCA0_04D8(**(char***)D_004A37B4 + 0x1D8, 0xC8, D_004A37E0[0].v, self, r, h, 0, 0);
            }
            return r;
        }
        d = D_004A37B4;
        vt = *(sBmVE_04D8**)(d + 0x1BC);
        int w = ((int (*)(void*, int, int, int))vt[3].fn)(d + vt[3].delta, self->f0, h, *(int*)((char*)self + 0x8D0));
        if (w != 0) {
            func_002AB0D0(*(void**)D_004A37B4, self->f4, w);
        }
        char* d2 = D_004A37B4;
        sBmVE_04D8* vt2 = *(sBmVE_04D8**)(d2 + 0x1BC);
        return ((Fn1_04D8)vt2[1].fn)(d2 + vt2[1].delta, self->f4, buf, a->f4, *(int*)((char*)self + 0x8CC), *(int*)((char*)self + 0x8C8), *(int*)((char*)self + 0x8D0), *(float*)((char*)self + 0x8F4), *(int*)((char*)self + 0x8F8), *(int*)((char*)self + 0x8FC));
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B07C0);
#ifdef SKIP_ASM
extern "C" void func_002B07C0(void* self)
{
    func_002AB028(*(void**)D_004A37B4, *(int*)((char*)self + 4));
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B07E8);
#ifdef SKIP_ASM
extern "C" void func_002B07E8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x8C4))) = arg1;
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B07F0);
#ifdef SKIP_ASM
extern "C" void func_002B07F0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x8C8))) = arg1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B07F8);
#ifdef SKIP_ASM
extern "C" void* cBankManager_cBankManager(void* self, int embedded, int count, int heap);
extern "C" void* cStreamSys_cStreamSys(void* self, int inchrg, int banks, int count, int heap);
struct sBankSlots;
extern "C" void func_002B1428(sBankSlots* self);
extern char* D_004A37B4;
extern void* D_00483870[];
extern void* D_00483B48[];
extern const char D_00483308[];

struct sName17_07F8 { char s[17]; };
struct sName18_07F8 { char s[18]; } __attribute__((aligned(2)));
extern const sName17_07F8 D_00483318;
extern const sName18_07F8 D_00483330;
extern const sName17_07F8 D_00483348;
extern const sName17_07F8 D_00483360;
extern const sName18_07F8 D_00483378;

struct sBmonVEntry07F8 {
    short delta;
    short index;
    void* fn;
};
struct sBmonVtblA07F8 {
    sBmonVEntry07F8 e[4];
} __attribute__((aligned(8)));
struct sBmonVtblB07F8 {
    sBmonVEntry07F8 e[7];
} __attribute__((aligned(8)));
// The unit declares these vtables later with its own types; bind views by asm label.
extern const sBmonVtblA07F8 D_004838A0_07F8 __asm__("D_004838A0");
extern const sBmonVtblB07F8 D_004838C0_07F8 __asm__("D_004838C0");

// PORT: g++ 2.95 constructor of a class with virtual bases (stack vtable this-adjust fix-ups written out by hand).
extern "C" char* func_002B07F8(char* self, int inchrg, int a2, int a3, int heap)
{
    if (inchrg) {
        char* vb = self + 0x1C0;
        char* vb2 = self + 0xC98;
        *(char**)(self + 0xC98) = self + 0x1C8;
        *(char**)self = vb2;
        *(char**)(self + 0x3A0) = vb;
        func_002ADE88(vb, heap);
        cBankManager_cBankManager(*(void**)(self + 0xC98), 0, a2, heap);
        cStreamSys_cStreamSys(*(void**)self, 0, a2, a3, heap);
    }
    *(const sBmonVtblA07F8**)(*(char**)(**(char***)self + 0x1D8) + 4) = &D_004838A0_07F8;
    *(void***)(**(char***)self + 0xAB0) = D_00483B48;
    *(const sBmonVtblB07F8**)(**(char***)self + 0x1D4) = &D_004838C0_07F8;
    if (inchrg == 0) {
        sBmonVtblA07F8 t1 = D_004838A0_07F8;
        *(sBmonVtblA07F8**)(*(char**)(**(char***)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)self + 0x1D8) - 0x1C0;
        int d1 = self - base1;
        t1.e[1].delta = D_004838A0_07F8.e[1].delta + d1;
        sBmonVtblB07F8 t2 = D_004838C0_07F8;
        *(sBmonVtblB07F8**)(**(char***)self + 0x1D4) = &t2;
        char* base2 = **(char***)self - 0x1C8;
        int d2 = self - base2;
        t2.e[1].delta = D_004838C0_07F8.e[1].delta + d2;
    }
    *(void***)(self + 0x1BC) = D_00483870;
    *(int*)(self + 0x10) = -1;
    *(int*)(self + 0x8) = 0;
    *(int*)(self + 0xC) = 0;
    D_004A37B4 = self;
    *(void***)(self + 0x4) = new (D_00483308, 0, 0) void*[2];
    for (int i = 0; i < 2; i++)
        (*(void***)(self + 0x4))[i] = 0;
    func_002B1428((sBankSlots*)self);
    *(sName17_07F8*)(self + 0x158) = D_00483318;
    *(sName18_07F8*)(self + 0x16C) = D_00483330;
    *(sName17_07F8*)(self + 0x180) = D_00483348;
    *(sName17_07F8*)(self + 0x194) = D_00483360;
    *(sName18_07F8*)(self + 0x1A8) = D_00483378;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B0AE8);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002AA648(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern char* D_004A37B4;
extern void* D_00483870[];
extern void* D_00483B48[];

struct sBmonVEntry0AE8 {
    short delta;
    short index;
    void* fn;
};
struct sBmonVtblA0AE8 {
    sBmonVEntry0AE8 e[4];
} __attribute__((aligned(8)));
struct sBmonVtblB0AE8 {
    sBmonVEntry0AE8 e[7];
} __attribute__((aligned(8)));
extern const sBmonVtblA0AE8 D_004838A0;
extern const sBmonVtblB0AE8 D_004838C0;

// PORT: g++ 2.95 virtual-base destruction with stack vtable this-adjust fix-ups, written out by hand.
extern "C" void func_002B0AE8(char* self, int flags)
{
    *(void***)(self + 0x1BC) = D_00483870;
    *(const sBmonVtblA0AE8**)(*(char**)(**(char***)self + 0x1D8) + 4) = &D_004838A0;
    *(void***)(**(char***)self + 0xAB0) = D_00483B48;
    *(const sBmonVtblB0AE8**)(**(char***)self + 0x1D4) = &D_004838C0;
    if (flags == 0) {
        sBmonVtblA0AE8 t1 = D_004838A0;
        *(sBmonVtblA0AE8**)(*(char**)(**(char***)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)self + 0x1D8) - 0x1C0;
        int d1 = self - base1;
        t1.e[1].delta = D_004838A0.e[1].delta + d1;
        sBmonVtblB0AE8 t2 = D_004838C0;
        *(sBmonVtblB0AE8**)(**(char***)self + 0x1D4) = &t2;
        char* base2 = **(char***)self - 0x1C8;
        int d2 = self - base2;
        t2.e[1].delta = D_004838C0.e[1].delta + d2;
    }
    if (*(void**)(self + 4) != 0) {
        cMemMan_free(*(void**)(self + 4));
    }
    D_004A37B4 = 0;
    if (flags & 2) {
        func_002AA648(*(void**)self, 0);
        func_0028BB10(**(void***)self, 0);
        func_002ADEE8(*(void**)(**(char***)self + 0x1D8), 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0C78);
#ifdef SKIP_ASM
struct sBankSlots;
extern "C" void func_002AFC88(void*, int);
extern "C" void func_002B1720(sBankSlots*);

extern "C" void func_002B0C78(void* self)
{
    for (int i = 0; i < 2; i++) {
        void* p = (*(void***)((char*)self + 0x4))[i];
        if (p != 0) {
            func_002AFC88(p, i);
        }
    }
    func_002B1720((sBankSlots*)self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", SPCH_Init);
#ifdef SKIP_ASM
extern "C" int func_003D6778(int a, int b, int c);
// PORT: the unit defines func_002ADF60() with no args; this caller passes one.
int func_002ADF60_a(int seed) __asm__("func_002ADF60");
extern "C" void bxLogPrint(const char* fmt, ...);
extern "C" void func_003D6840(void* fn, int seed, int buf);
extern "C" int func_003D6C58(int n);
extern "C" void* func_00252FA0(void* a0, int a1, int a2);
extern "C" void func_003D6C60(int n, void* p);
extern "C" void* func_003D6768();
extern "C" void func_002AF8A8();
extern "C" int func_003E4E98();
extern char D_00483390[];
extern char D_004833A8[];

extern "C" void SPCH_Init(void* self)
{
    int buf = func_003D6778(0x5622, 0x10, 1);
    int seed = func_002ADF60_a(*(int*)(**(char***)self + 0x1D8));
    bxLogPrint(D_00483390, seed);
    func_003D6840((void*)func_002AF8A8, seed, buf);
    int n = func_003D6C58(500);
    void* p = func_00252FA0(D_004833A8, n, 0);
    *(void**)((char*)self + 0x8) = p;
    func_003D6C60(500, p);
    *(void**)((char*)func_003D6768() + 0x8) = (void*)func_003E4E98;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0DA0);
#ifdef SKIP_ASM
extern "C" void func_002AFB38(void* p, int mode);
extern "C" void func_003D67F8(void);

extern "C" void func_002B0DA0(void* self)
{
    for (int i = 0; i < 2; i++) {
        void* p = (*(void***)((char*)self + 0x4))[i];
        if (p != 0) {
            func_002AFB38(p, 3);
        }
        (*(void***)((char*)self + 0x4))[i] = 0;
    }
    func_003D67F8();
    func_002523A8(*(void**)((char*)self + 0x8));
    *(void**)((char*)self + 0x8) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B0E28);
#ifdef SKIP_ASM
extern "C" int func_002B0290(void* p);

extern "C" int func_002B0E28(void* self, int i)
{
    void* p = (*(void***)((char*)self + 0x4))[i];
    if (p != 0) {
        return func_002B0290(p);
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0E60);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002AFA68(void* mem, int i, int a, int b, int c, int d, int e);
extern const char D_004833B8[];

extern "C" void func_002B0E60(void* self, int i, int a, int b, int c, int d, int e)
{
    // PORT: pointer arithmetic through int
    void** slot = (void**)(i * 4 + *(int*)((char*)self + 0x4));
    *slot = func_002AFA68(cMemMan_alloc(0x904, D_004833B8, 0, 0), i, a, b, c, d, e);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B0F10);
#ifdef SKIP_ASM
extern "C" void func_002B0F10(void* self, int i, int a)
{
    void* p = (*(void***)((char*)self + 0x4))[i];
    if (p != 0) {
        func_002B0088(p, i, a, 0);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0F48);
#ifdef SKIP_ASM
extern "C" int func_002B04D8(void* p, int a1);

extern "C" int func_002B0F48(void* self, int a1)
{
    for (int i = 0; i < 2; i++) {
        void* p = (*(void***)((char*)self + 0x4))[i];
        if (p != 0) {
            int r = func_002B04D8(p, a1);
            if (r >= 0) {
                if (*(int*)((char*)self + 0x10) == i) {
                    (*(void (**)(int))((char*)self + 0xC))(r);
                }
                return r;
            }
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B0FE8);
#ifdef SKIP_ASM
extern "C" void func_002B07E8(void* p, int a);

extern "C" void func_002B0FE8(void* self, int i, int a)
{
    void* p = (*(void***)((char*)self + 0x4))[i];
    if (p != 0) {
        func_002B07E8(p, a);
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1020);
#ifdef SKIP_ASM
extern "C" void func_002B07F0(void* p, int a);

extern "C" void func_002B1020(void* self, int i, int a)
{
    void* p = (*(void***)((char*)self + 0x4))[i];
    if (p != 0) {
        func_002B07F0(p, a);
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1058);
#ifdef SKIP_ASM
extern "C" void func_002B1058(void* self, int idx, int a2, int a3, int a4, float v)
{
    int** chans = *(int***)((char*)self + 4);
    if (chans[idx] != 0) {
        *(int*)((char*)chans[idx] + 0x8CC) = a2;
        if (v > 0.0f) {
            *(float*)((char*)(*(int***)((char*)self + 4))[idx] + 0x8F4) = v;
        }
        *(int*)((char*)(*(int***)((char*)self + 4))[idx] + 0x8D0) = a4;
        if (a3 != 0) {
            *(int*)((char*)self + 0xC) = a3;
            *(int*)((char*)self + 0x10) = idx;
        }
        func_003D8040((void*)idx);
        *(int*)((char*)self + 0x10) = -1;
        *(int*)((char*)self + 0xC) = 0;
        *(float*)((char*)(*(int***)((char*)self + 4))[idx] + 0x8F4) = 0.0f;
        *(int*)((char*)(*(int***)((char*)self + 4))[idx] + 0x8CC) = 0;
        *(int*)((char*)(*(int***)((char*)self + 4))[idx] + 0x8D0) = 0;
    }
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B1128);
#ifdef SKIP_ASM
extern "C" void func_002B1058(void* self, int idx, int a2, int a3, int a4, float v);
extern int D_004A37BC;

extern "C" void func_002B1128(void* self, int idx)
{
    if ((*(int**)((char*)self + 4))[idx] != 0) {
        int i = 3;
        D_004A37BC = 1;
        do {
            func_002B1058(self, idx, 0, 0, 0, 0.0f);
            i--;
        } while (i >= 0);
        D_004A37BC = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B11B0);
#ifdef SKIP_ASM
extern "C" void func_002B0320(void* p);

extern "C" void func_002B11B0(void* self, int i)
{
    void* p = (*(void***)((char*)self + 0x4))[i];
    if (p != 0) {
        func_002B0320(p);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B11E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002B07C0_11E8(void* self) __asm__("func_002B07C0");

extern "C" int func_002B11E8(void* self, int i)
{
    void* p = (*(void***)((char*)self + 0x4))[i];
    if (p != 0) {
        return func_002B07C0_11E8(p);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1220);
#ifdef SKIP_ASM
extern "C" int func_002B1220(void* self, int i)
{
    void* e = (*(void***)((char*)self + 0x4))[i];
    if (e != 0) {
        return *(int*)((char*)e + 0x4);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1248);
#ifdef SKIP_ASM
extern "C" void func_002AB1A0(int);

extern "C" void func_002B1248(int *arg0) {
    func_002AB1A0(*arg0);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B1268);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPacked8_1268 { long v; } __attribute__((packed));
extern const sPacked8_1268 D_004A37E0_2B1268[] __asm__("D_004A37E0");
extern "C" int func_002AB150(void* self, int i);
extern "C" void func_002AB0D0(void* self, int i, int val);
extern "C" void func_002ADCA0(int a, int b, long t, void* c, int d, int e, int f, int g);
extern "C" int func_002B1248_pp(void* self, void* msg) __asm__("func_002B1248");
struct sVE1268 { short delta; short index; int (*fn)(void*, int, int, int); };

extern "C" int func_002B1268(void* self, void* msg)
{
    char* ent = *(char**)((char*)msg + 0x18);
    if (func_002AB150(*(void**)self, func_002B1220(D_004A37B4, *(int*)ent)) != *(int*)((char*)msg + 0x1C)) {
        func_002ADCA0(**(int**)D_004A37B4 + 0x1D8, 0xC8, D_004A37E0_2B1268[0].v, *(void**)((char*)msg + 0x18), *(int*)((char*)msg + 0x1C), *(int*)((char*)msg + 0x20), 0, 0);
        return 1;
    }
    int slot = *(int*)((char*)msg + 0x20);
    if (slot != -1) {
        sVE1268* vt = *(sVE1268**)((char*)self + 0x1BC);
        int r = vt[3].fn((char*)self + vt[3].delta, *(int*)ent, slot, *(int*)(ent + 0x8D0));
        if (r != 0) {
            func_002AB0D0(*(void**)self, *(int*)(ent + 4), r);
        }
    }
    return func_002B1248_pp(self, msg);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B1348);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPacked8_1348 { long v; } __attribute__((packed));
extern const sPacked8_1348 D_004A37D8_2B1348[] __asm__("D_004A37D8");
extern "C" int func_002AB150(void* self, int i);
extern "C" void func_002ADCA0(int a, int b, long t, void* c, int d, int e, int f, int g);
extern "C" int func_002B1268(void* self, void* msg);

extern "C" int func_002B1348(void* self, void* msg)
{
    char* ent = *(char**)((char*)msg + 0x18);
    if (func_002AAE08(*(void**)self, *(int*)(ent + 4)) - 1 > 0) {
        if (func_002AB028(*(void**)self, *(int*)(ent + 4)) != 0) {
            float f = func_002AAE78(*(void**)self, *(int*)(ent + 4));
            func_002ADCA0(**(int**)D_004A37B4 + 0x1D8, (int)f, D_004A37D8_2B1348[0].v, ent, *(int*)((char*)msg + 0x1C), *(int*)((char*)msg + 0x20), 0, 0);
            return 1;
        }
        if (func_002AB150(*(void**)self, func_002B1220(D_004A37B4, *(int*)ent)) != *(int*)((char*)msg + 0x1C)) {
            return 0;
        }
        return func_002B1268(self, msg);
    }
    return func_002B1268(self, msg);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1428);
#ifdef SKIP_ASM
struct sBankSlot0018 {
    int value;
    int timer;
    char pad[0x18];
};

struct sBankSlots {
    char pad[0x18];
    sBankSlot0018 slots[10];
};

extern "C" void func_002B1428(sBankSlots* self)
{
    for (int i = 9; i >= 0; i--) {
        self->slots[i].value = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1458);
#ifdef SKIP_ASM
struct sBankEntry20 {
    int used;
    int timer;
    int a;
    int b;
    int c;
    int d;
    float f;
    int e;
};

struct sBankEntries {
    char pad[0x18];
    sBankEntry20 entries[10];
};

extern "C" int func_002B1458(sBankEntries* self, int a, int b, int c, int d, int e, int refresh, float f)
{
    int freeIdx = -1;
    int i;
    for (i = 0; i < 10; i++) {
        if (self->entries[i].used != 0) {
            if (self->entries[i].a == a && self->entries[i].b == b) {
                if (refresh == 0) {
                    return 0;
                }
                self->entries[i].timer = 180;
                return 1;
            }
        } else {
            if (freeIdx == -1) {
                freeIdx = i;
            }
        }
    }
    if (freeIdx == -1) {
        return 0;
    }
    self->entries[freeIdx].used = 1;
    self->entries[freeIdx].timer = 180;
    self->entries[freeIdx].a = a;
    self->entries[freeIdx].b = b;
    self->entries[freeIdx].c = c;
    self->entries[freeIdx].d = d;
    self->entries[freeIdx].f = f;
    self->entries[freeIdx].e = e;
    return 1;
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002B1520);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B16A0);
#ifdef SKIP_ASM
struct sSlot16A0 {
    int active;     // 0x0
    int pad4;
    int idx;        // 0x8
    int key;        // 0xC
    char pad[0x10];
};

extern "C" void func_002B16A0(void* self, int idx, int key)
{
    sSlot16A0* slots = (sSlot16A0*)((char*)self + 0x18);
    for (int i = 0; i < 10; i++) {
        if (slots[i].active != 0 && slots[i].idx == idx && slots[i].key == key) {
            *(int*)((char*)self + 0xC) = 0;
            *(int*)((char*)self + 0x10) = -1;
            *(int*)((char*)(*(int**)((char*)self + 4))[idx] + 0x8F4) = 0;
            *(int*)((char*)(*(int**)((char*)self + 4))[idx] + 0x8CC) = 0;
            *(int*)((char*)(*(int**)((char*)self + 4))[idx] + 0x8D0) = 0;
            slots[i].active = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1720);
#ifdef SKIP_ASM
extern "C" void func_002B1720(sBankSlots* self)
{
    for (int i = 0; i < 10; i++) {
        if (self->slots[i].value != 0) {
            if (--self->slots[i].timer <= 0) {
                self->slots[i].value = 0;
            }
        }
    }
}
#endif

extern "C" void* func_002AFD10(int);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1758__FPvi);
#ifdef SKIP_ASM
void* func_002B1758(void* self, int a1)
{
    // a1 also stays in $5 as func_002AFD10's second argument
    return func_002AFD10_impl((void*)(*(int**)((char*)self + 0x4))[a1], (void*)a1);
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002B1780);
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1A70);
#ifdef SKIP_ASM
extern void*** D_004A37EC;

extern "C" void func_002B1A70(void) {
    func_002AAE40(*D_004A37EC, 2);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1A98);
#ifdef SKIP_ASM
extern char D_00483980[];
extern unsigned char D_004A35A8[];

struct func_002B1A98_sElem20 {
    unsigned char b;
    char pad[0x1F];
};

extern "C" void* func_002B1A98(void* self)
{
    *(void**)((char*)self + 0xA8) = D_00483980;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x64) = 4;
    *(int*)((char*)self + 0x68) = 2;
    *(int*)((char*)self + 0x6C) = 4;
    *(int*)((char*)self + 0x70) = 8;
    *(int*)((char*)self + 0x74) = 0x10;
    *(int*)((char*)self + 0x78) = 0;
    *(int*)((char*)self + 0x7C) = 0x5A;
    *(int*)((char*)self + 0x80) = 100;
    *(int*)((char*)self + 0x84) = 0x32;
    *(int*)((char*)self + 0x88) = 100;
    *(int*)((char*)self + 0x8C) = 100;
    *(float*)((char*)self + 0x90) = 120.0f;
    *(int*)((char*)self + 0x94) = 1;
    *(int*)((char*)self + 0x98) = -1;
    *(int*)((char*)self + 0x9C) = 0xFFFF;
    *(int*)((char*)self + 0xA0) = -1;
    *(int*)((char*)self + 0xA4) = 1;
    *(unsigned char*)((char*)self + 0x0) = D_004A35A8[0];
    *(unsigned char*)((char*)self + 0x20) = D_004A35A8[0];
    func_002B1A98_sElem20* p = (func_002B1A98_sElem20*)((char*)self + 0x44);
    for (int i = 0; i >= 0; i--, p++) {
        p->b = D_004A35A8[0];
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1B68);
#ifdef SKIP_ASM
extern char D_00483980[];

extern "C" void func_002B1B68(int* self, int flags)
{
    *(void**)((char*)self + 0xA8) = D_00483980;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1B98);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002B1C50(void* mem, int a0, int a1, int a2, int a3, char a4, int a5, int a6, int a7);
extern const char D_004833E0[];

extern "C" void* func_002B1B98(int a0, int a1, int a2, int a3, char a4, int a5, int a6, int a7)
{
    return func_002B1C50(cMemMan_alloc(0xC4, D_004833E0, 0, 0), a0, a1, a2, a3, a4, a5, a6, a7);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1C50);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* bmNew_1C50(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int func_003D3058(int a, int b);
extern "C" void func_002B4A20(void* self, void* name, int sync);
extern "C" void func_002B21E0(void*, int);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004833F0[];
extern char D_00483408[];
extern char D_00483420[];
extern char D_00483430[];
extern char D_004A3588[];
extern char D_004A3590[];
extern char D_004A36E0[];
extern void*** D_004A37EC;

struct sBankEntry_1C50 {
    unsigned char vol;      // 0x0
    char pad1[0x13];
    unsigned short f14;     // 0x14
    short pad16;
};

struct sBankDef_1C50 {
    char pad00[0x1C];
    volatile int cur;           // 0x1C
    sBankEntry_1C50* entries;   // 0x20
    char pad24[0x14];
    int* vols;                  // 0x38
};

struct sBankMon_1C50 {
    char* snd;                  // 0x0
    sBankEntry_1C50 entry;      // 0x4
    int f1C;                    // 0x1C
    int f20;
    void* buf24;                // 0x24
    void* buf28;                // 0x28
    int f2C;                    // 0x2C
    int f30;                    // 0x30
    int f34;                    // 0x34
    int f38;                    // 0x38
    int f3C;                    // 0x3C
    char f40;                   // 0x40
    int f44;                    // 0x44
    int f48;                    // 0x48
    int f4C;                    // 0x4C
    int f50;                    // 0x50
    int f54;                    // 0x54
    int f58;                    // 0x58
    int f5C;                    // 0x5C
    char name[0x40];            // 0x60
};

#define BM_MIN_1C50(a, b) ((a) < (b) ? (a) : (b))
#define BM_MAX_1C50(a, b) ((a) >= (b) ? (a) : (b))

static inline sBankEntry_1C50* bankCur_1C50(sBankDef_1C50* d)
{
    return &d->entries[d->cur];
}

// PORT: callers declare the first parameter as void*; the body takes the typed object (bound by asm label)
extern "C" void* func_002B1C50_body(sBankMon_1C50* self, int a0, int a1, int a2, int a3, char a4, int a5, int a6, int a7) __asm__("func_002B1C50");

extern "C" void* func_002B1C50_body(sBankMon_1C50* self, int a0, int a1, int a2, int a3, char a4, int a5, int a6, int a7)
{
    char* snd = (char*)a2;
    sBankDef_1C50* def = (sBankDef_1C50*)a3;
    self->f1C = -1;
    self->buf24 = 0;
    self->buf28 = 0;
    self->f2C = 0;
    self->f30 = -1;
    self->f38 = 0;
    self->f34 = a6;
    self->f3C = a5;
    self->f40 = a4;
    self->f48 = 0;
    self->f4C = 0;
    self->f50 = 0;
    self->f54 = 1;
    self->f58 = -1;
    self->f5C = 0;
    self->f44 = bankCur_1C50(def)->f14;
    self->buf24 = bmNew_1C50(0x37000, D_004833F0, 0, 0);
    self->buf28 = bmNew_1C50(func_003D3058(1, 0), D_00483408, 0, 0);
    float scale = (float)*(int*)(snd + 0x88) * 0.01f;
    def->vols[def->cur] = (int)BM_MAX_1C50(BM_MIN_1C50((float)def->vols[def->cur] * scale, 127.0f), 0.0f);
    def->entries[def->cur].vol = BM_MAX_1C50(BM_MIN_1C50(def->vols[def->cur], 127), 0);
    if (*(int*)(snd + 0xA4) == 1) {
        sprintf(self->name, D_004A3588, D_004A3590, D_00483420, a0);
    } else {
        sprintf(self->name, D_004A3588, D_004A3590, D_00483430, a0);
    }
    self->snd = snd;
    self->entry = *bankCur_1C50(def);
    char buf[0x100];
    sprintf(buf, D_004A36E0, self->name, snd);
    func_002B4A20(D_004A37EC, buf, a7);
    if (a7 != 0) {
        func_002B21E0(self, 1);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1F78);
#ifdef SKIP_ASM
extern "C" void func_0028A728(void* self, int i);
extern "C" int func_003D2A68(int id);
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern void*** D_004A37EC;

extern "C" void func_002B1F78(void* self, int flags)
{
    func_0028A728(**D_004A37EC, *(int*)((char*)self + 0x34));
    func_003D2A68(0x11000001);
    if (*(int*)(*(char**)self + 0x40) > 0) {
        func_003D2A68(0x11000002);
    }
    if (*(void**)((char*)self + 0x24) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x24));
    }
    if (*(void**)((char*)self + 0x28) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x28));
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2018);
#ifdef SKIP_ASM
extern "C" int func_002B2488(void* self);
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B7FB8(int h, int v);
extern "C" void func_003D1038(int cmd, int v);

extern "C" void func_002B2018(void* self)
{
    func_003B58A0();
    int h = func_002B2488(self);
    if (h >= 0) {
        func_003B7FB8(h, 0);
    }
    func_003B58D8();
    func_003D1038(0x11000002, 1);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2070);
#ifdef SKIP_ASM
extern "C" int func_002B2488(void* self);
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B7FB8(int h, int v);
extern "C" void func_003D1038(int cmd, int v);

extern "C" void func_002B2070(void* self)
{
    func_003B58A0();
    int h = func_002B2488(self);
    if (h >= 0) {
        func_003B7FB8(h, 0x1000);
    }
    func_003B58D8();
    func_003D1038(0x11000002, 0);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B20C8);
#ifdef SKIP_ASM
extern "C" void func_003D16F0(int id, short v);

extern "C" void func_002B20C8(void* self, int v, int force)
{
    if (*(int*)((char*)self + 0x5C) != 0 && force == 0) {
        return;
    }
    if (*(int*)((char*)self + 0x2C) != 0) {
        func_003D16F0(-1, v);
    } else if (*(int*)((char*)self + 0x30) == -1) {
        *(int*)((char*)self + 0x30) = v;
    }
}
#endif

extern "C" void func_003D0D70(unsigned int);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2120);
#ifdef SKIP_ASM
extern "C" void func_002B2120()
{
    func_003D0D70(0x11000001U);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2140);
#ifdef SKIP_ASM
extern "C" void func_003D15C8(int);

extern "C" void func_002B2140(void) {
    func_003D15C8(0x11000001);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2160);
#ifdef SKIP_ASM
extern "C" int func_002B2488(void* self);
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B80A0(int h, int v);

extern "C" void func_002B2160(void* self, int v)
{
    if (v > 0xFFFF) {
        v = 0xFFFF;
    }
    if (v < 0) {
        v = 0;
    }
    if (v != *(int*)((char*)self + 0x44)) {
        func_003B58A0();
        int h = func_002B2488(self);
        if (h >= 0) {
            *(int*)((char*)self + 0x44) = v;
            func_003B80A0(h, v);
        }
        func_003B58D8();
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B21E0);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_002B20C8(void* mon, int a1, int a2);
extern "C" void func_002B2160(void* self, int v);
extern "C" int func_002B2488(void* self);
extern "C" int func_002B4AA0(void* self, int force);
int func_002B4AE8(void* self);
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B7E70(int h, int v);
extern "C" void func_003D2350(int a);
extern "C" int func_003D25F0(int id, char* name, int a2, void* a3, int a4, int a5, void* buf, int size);
extern void*** D_004A37EC;
extern char D_004A36E0[];
extern float D_004A3508;

struct sBmStrm_2B21E0 { char pad[0x2C]; int f2C; };

// PORT: g++ `<?` / `>?` (min/max) operators.
extern "C" void func_002B21E0(void* mon, int force)
{
    char* self = (char*)mon;
    if (*(int*)(self + 0x2C) == 0)
    {
        if (func_002B4AA0(D_004A37EC, force) == 0)
            return;
        ((sBmStrm_2B21E0*)self)->f2C = 1;
        func_003D2350(func_002B4AE8(D_004A37EC));
        char buf[256];
        sprintf(buf, D_004A36E0, self + 0x60, *(char**)self + 0x20);
        *(int*)(self + 0x1C) = func_003D25F0(0x11000001, buf, 500, self + 4, 2, 150, *(void**)(self + 0x24), 0x37000);
        if (*(int*)(*(char**)self + 0x40) > 0)
        {
            sprintf(buf, D_004A36E0, self + 0x60, *(char**)self + 0x44);
            *(int*)(self + 0x20) = func_003D25F0(0x11000002, buf, 10, self + 4, 1, 0, *(void**)(self + 0x28), 0x6A400);
        }
        if (*(int*)(self + 0x30) != -1)
        {
            func_002B20C8(self, *(int*)(self + 0x30), 1);
            *(int*)(self + 0x30) = -1;
        }
        return;
    }
    func_002B2160(self, *(int*)(*(char**)self + 0x9C));
    if (*(int*)(self + 0x48) != 0)
        return;
    if (*(int*)(self + 0x54) == 0)
        return;
    float v;
    float* p = *(float**)(self + 0x3C);
    if (p)
        v = (float)*(signed char*)(self + 0x40) * 0.009999999776482582f * (float)*(int*)(*(char**)self + 0x88) * *p;
    else
        v = (float)*(signed char*)(self + 0x40) * 0.009999999776482582f * (float)*(int*)(*(char**)self + 0x88);
    v *= D_004A3508;
    func_003B58A0();
    int h = func_002B2488(self);
    if (h >= 0)
    {
        signed char vol = (int)((v <? 127.0f) >? 0.0f);
        func_003B7E70(h, vol);
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B23E8);
#ifdef SKIP_ASM
extern "C" void func_003D5508(int cmd, int v);

extern "C" void func_002B23E8(void* self, signed char v)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        func_003D5508(0x11000002, v);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2418);
#ifdef SKIP_ASM
extern "C" int func_002B2488(void* self);
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" void func_003B7EB0(int h, int v, int c);

extern "C" void func_002B2418(void* self, float t)
{
    func_003B58A0();
    int h = func_002B2488(self);
    if (h >= 0) {
        func_003B7EB0(h, (int)(t * 1000.0f), 0);
    }
    func_003B58D8();
    *(int*)((char*)self + 0x48) = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B2488);
#ifdef SKIP_ASM
extern "C" int func_003D3030(int id);

extern "C" int func_002B2488(void* self)
{
    int idx = func_003D3030(0x11000001);
    if (idx < 0) {
        return -1;
    }
    // PORT: func_002ADFB0 returns a pointer held in int
    return *(int*)func_002ADFB0(idx);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B24C0);
#ifdef SKIP_ASM
// PORT: func_002ADF60 is defined () but this caller passes the monitor.
unsigned int func_002ADF60_p(void* p) __asm__("func_002ADF60");
extern void* D_004A377C;

extern "C" int func_002B24C0(void* p)
{
    return func_002ADF60_p(D_004A377C) % *(unsigned int*)(*(char**)p + 0x40);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2500);
#ifdef SKIP_ASM
extern "C" int func_002B2500(void* self)
{
    char* p;
    unsigned int r = func_002ADF60_p(D_004A377C);
    p = *(char**)self;
    return (r % (unsigned int)(*(int*)(p + 0x6C) - 1)) * *(int*)(p + 0x74);
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2550);
#ifdef SKIP_ASM
extern "C" void func_003D11B8(int, void*);

extern "C" int func_002B2550(void)
{
    int buf[10];
    func_003D11B8(0x11000001, buf);
    return buf[9];
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2578);
#ifdef SKIP_ASM
extern "C" int func_002B2488(void* self);
extern "C" int func_003B7B48(int h, void* out);

// PORT: returns int; a later caller in this unit declares it void(void*, void*)
int func_002B2578_impl(void* self, void* out) __asm__("func_002B2578");

int func_002B2578_impl(void* self, void* out)
{
    return func_002B2488(self) < 0 ? -1 : func_003B7B48(func_002B2488(self), out);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B25C8);
#ifdef SKIP_ASM
extern "C" void func_002B2578(void* self, void* out);
extern "C" void func_003B7C40(int h, int v);

struct sBmInfo {
    int a;
    int handle;
    int c;
    int d;
};

extern "C" void func_002B25C8(void* self, int v)
{
    sBmInfo info;
    func_002B2578(self, &info);
    func_003B7C40(info.handle, v);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B2600);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// The unit declares func_002B25C8(void*, int); its second arg is really an out pointer.
void func_002B25C8_out(void* self, void* out) __asm__("func_002B25C8");

struct func_002B2600_sInfo {
    int type;
    int value;
    int c;
    int d;
};

extern "C" float func_002B2600(void* self)
{
    func_002B2600_sInfo info;
    func_002B25C8_out(self, &info);
    if (info.type == 2) {
        return (float)info.value;
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2640);
#ifdef SKIP_ASM
struct func_002B2640_sInfo {
    int type;
    int value;
    int c;
    int d;
};

extern "C" float func_002B26B8(void* self);

// PORT: the unit later declares func_002B2640() as void() for a caller; real signature is float(void*).
float func_002B2640_impl(void* self) __asm__("func_002B2640");
float func_002B2640_impl(void* self)
{
    func_002B2640_sInfo info;
    func_002B25C8_out(self, &info);
    if (info.type == 2) {
        return (float)info.c;
    }
    return func_002B26B8(self);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2690);
#ifdef SKIP_ASM
extern "C" float func_002B2690(void* self)
{
    void* p = *(void**)self;
    return (60.0f / *(float*)((char*)p + 0x90)) * 1000.0f;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B26B8);
#ifdef SKIP_ASM
extern "C" float func_002B26B8(void* self)
{
    float a = func_002B2690(self);
    char* p = *(char**)self;
    return a * (float)*(int*)(p + 0x64) * (float)*(int*)(p + 0x68);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B26F8);
#ifdef SKIP_ASM
extern "C" void func_002B2640();

extern "C" void func_002B26F8(void) {
    func_002B2640();
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B2718);
#ifdef SKIP_ASM
extern "C" float func_002B2600(void* self);
extern "C" float func_0040D8D0(float x, float y);

extern "C" float func_002B2718(void* self)
{
    float a = func_002B2690(self);
    float b = func_002B2600(self);
    return a - func_0040D8D0(b, func_002B2690(self));
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2778);
#ifdef SKIP_ASM
extern "C" int func_002B2778(void* self)
{
    return (int)(func_002B2600(self) / func_002B2690(self));
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B27C0);
#ifdef SKIP_ASM
extern "C" int func_002B9F88(void*, int);
extern "C" int func_003B65D0(int);

extern "C" int func_002B27C0(void* self, void* other)
{
    if (*(int*)((char*)self + 0x4C) == 0) {
        int slot = *(int*)((char*)self + 0x34);
        int ok = 0;
        func_003B58A0();
        bool notReady = *(int*)(slot * 0x60 + *(int*)((char*)other + 0xACC)) != 1;
        if (!notReady) {
            ok = func_003B65D0(func_002B9F88(other, slot)) == 1;
        }
        func_003B58D8();
        if (ok == 0) {
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2850);
#ifdef SKIP_ASM
struct sBMVec16 {
    int x;
    int y;
    int z;
    int w;
};

struct sBMTrack {
    char pad0[0x1F4];
    int cur;
    char pad1F8[0x248 - 0x1F8];
    sBMVec16* vecs;
};

struct sBMSrc {
    char pad0[0x78];
    int a;
    int b;
    int c;
};

extern "C" void func_002B2850(sBMSrc** src, sBMTrack*** dst)
{
    (**dst)->vecs[(**dst)->cur].y = (*src)->a;
    (**dst)->vecs[(**dst)->cur].z = (*src)->b;
    (**dst)->vecs[(**dst)->cur].x = (*src)->c;
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002B28C0);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3398);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002AA648(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern "C" void func_002B1F78(void* self, int flags);
extern void*** D_004A37EC;
extern void* D_004838F8[];
extern void* D_00483B48[];

struct sBmonVEntry3398 {
    short delta;
    short index;
    void* fn;
};
struct sBmonVtblA3398 {
    sBmonVEntry3398 e[4];
} __attribute__((aligned(8)));
struct sBmonVtblB3398 {
    sBmonVEntry3398 e[7];
} __attribute__((aligned(8)));
extern const sBmonVtblA3398 D_00483928;
extern const sBmonVtblB3398 D_00483948;

struct sBmonVcall3398 { short delta; short index; void (*fn)(void*, int); };

// PORT: g++ 2.95 virtual-base destruction with stack vtable this-adjust fix-ups, written out by hand.
extern "C" void func_002B3398(char* self, int flags)
{
    *(void***)(self + 0x5440) = D_004838F8;
    *(const sBmonVtblA3398**)(*(char**)(**(char***)self + 0x1D8) + 4) = &D_00483928;
    *(void***)(**(char***)self + 0xAB0) = D_00483B48;
    *(const sBmonVtblB3398**)(**(char***)self + 0x1D4) = &D_00483948;
    if (flags == 0) {
        sBmonVtblA3398 t1 = D_00483928;
        *(sBmonVtblA3398**)(*(char**)(**(char***)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)self + 0x1D8) - 0x5448;
        int d1 = self - base1;
        t1.e[1].delta = D_00483928.e[1].delta + d1;
        sBmonVtblB3398 t2 = D_00483948;
        *(sBmonVtblB3398**)(**(char***)self + 0x1D4) = &t2;
        char* base2 = **(char***)self - 0x5450;
        int d2 = self - base2;
        t2.e[1].delta = D_00483948.e[1].delta + d2;
    }
    for (int i = 0; i < *(int*)(self + 0x3E4); i++) {
        char* o = ((char**)(self + 4))[i];
        if (o != 0) {
            sBmonVcall3398* e = &(*(sBmonVcall3398**)(o + 0xA8))[1];
            e->fn(o + e->delta, 3);
        }
    }
    if (*(void**)(self + 0x5434) != 0) {
        cMemMan_free(*(void**)(self + 0x5434));
    }
    if (*(void**)(self + 0x408) != 0) {
        func_002B1F78(*(void**)(self + 0x408), 3);
    }
    D_004A37EC = 0;
    if (flags & 2) {
        func_002AA648(*(void**)self, 0);
        func_0028BB10(**(void***)self, 0);
        func_002ADEE8(*(void**)(**(char***)self + 0x1D8), 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B35A0);
#ifdef SKIP_ASM
extern "C" void func_002B3838(void* self, int a1, int a2, int a3);

struct sBmEnt35A0 {
    signed char b0;
    char pad1[3];
    int f4[5];
};

struct sBmPair35A0 {
    int a;
    int b;
};

struct sBmV16_35A0 {
    int f0;
    int f4;
    int f8;
    int fC;
};

struct sBmSub35A0 {
    int f0;
    sBmEnt35A0 cfg;         // 0x04
    volatile int cur;       // 0x1C (target re-reads it after every store and twice back-to-back: volatile)
    sBmEnt35A0* ents;       // 0x20
    int arr24[4];           // 0x24
    int* p34;               // 0x34
    int* p38;               // 0x38
    int* p3C;               // 0x3C
    sBmPair35A0 arr40[4];   // 0x40
    int* p60;               // 0x60
    int* p64;               // 0x64
    int* p68;               // 0x68
    int* p6C;               // 0x6C
    sBmV16_35A0* p70;       // 0x70
    int* p74;               // 0x74
    int* p78;               // 0x78
    int* p7C;               // 0x7C
    int* p80;               // 0x80
    int* p84;               // 0x84
};

struct sBmTrack35A0 {
    char pad0[0x1D8];
    sBmSub35A0 sub;         // 0x1D8
};

extern "C" void func_002B35A0(sBmTrack35A0*** self, int a1, int a2, int a3, int a4)
{
    sBmTrack35A0* t = **self;
    sBmSub35A0* s = &t->sub;
    t->sub.cur++;
    s->ents[t->sub.cur] = s->cfg;
    t->sub.arr24[t->sub.cur] = 0;
    s->p34[t->sub.cur] = 0;
    s->p38[t->sub.cur] = s->ents[t->sub.cur].b0;
    s->p3C[t->sub.cur] = 0;
    func_00416210((char*)s + t->sub.cur * 8 + 0x40, 0, 8);
    s->p60[t->sub.cur] = 0;
    s->p64[t->sub.cur] = 0;
    s->p68[t->sub.cur] = 0;
    s->p6C[t->sub.cur] = 0;
    s->p70[t->sub.cur].f4 = 0;
    s->p70[t->sub.cur].f0 = 100;
    s->p70[t->sub.cur].f8 = 90;
    s->p70[t->sub.cur].fC = 50;
    s->p74[t->sub.cur] = 0;
    s->p80[t->sub.cur] = 0;
    s->p84[t->sub.cur] = 0;
    s->p78[t->sub.cur] = 0x7F;
    s->p7C[t->sub.cur] = 1;
    sBmTrack35A0* t2 = **self;
    t2->sub.p3C[t2->sub.cur] = a3;
    func_002B3838(self, a1, a2, a4);
    sBmTrack35A0* t3 = **self;
    t3->sub.cur--;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3838);
#ifdef SKIP_ASM
extern "C" int func_004165A8(void*, void*);
extern "C" void func_002B3AC0(void* self);
extern "C" void func_002B43D8(void* self);
extern "C" void* func_002B1B98(int a0, int a1, int a2, int a3, char a4, int a5, int a6, int a7);

struct sBMon3838 {
    sBmTrack35A0** pp;          // 0x000
    int arr[64];                // 0x004
    char obj[0x20];             // 0x104
    char names[64][11];         // 0x124
    int count;                  // 0x3E4
    int pad3E8[2];
    int cur;                    // 0x3F0
    int pad3F4[6];
    int res;                    // 0x40C - see below
};

// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
static inline float bmMin3838(float a, float b)
{
    return a <? b;
}
static inline float bmMax3838(float a, float b)
{
    return a >? b;
}

extern "C" void func_002B3838(void* self_, int a1, int a2, int a3)
{
    sBMon3838* self = (sBMon3838*)self_;
    sBmTrack35A0* t;
    sBmSub35A0* sub;
    float* pf;
    char c;
    int arg;
    int name;
    int base;
    func_002B3AC0(self);
    t = *self->pp;
    sub = &t->sub;
    c = sub->p38[sub->cur];
    pf = (float*)sub->p3C[sub->cur];
    if (pf != 0) {
        float f = (float)c * *pf;
        f = bmMax3838(bmMin3838(f, 127.0f), 0.0f);
        sub->p38[t->sub.cur] = (char)(int)f;
        {
            signed char* d = &((sBmEnt35A0*)(t->sub.cur * 24 + (int)sub->ents))->b0;
            unsigned char r;
            if (sub->p38[sub->cur] > 0x7E || sub->p38[sub->cur] >= 0) {
                r = sub->p38[sub->cur] < 0x7F ? (unsigned char)sub->p38[sub->cur] : 0x7F;
            } else {
                r = 0;
            }
            *d = r;
        }
    }
    if (a1 != 0) {
        int idx = self->count - 1;
        while (idx >= 0) {
            if (func_004165A8(self->names[idx], (void*)a1) == 0) {
                break;
            }
            idx--;
        }
        self->cur = idx;
        name = a1;
        base = (int)&(*self->pp)->sub;
        *(int*)((char*)self + 0x408) = (int)func_002B1B98((int)self->obj, name, self->arr[idx], base, c, (int)pf, a2, a3);
    } else {
        int k = self->cur;
        name = (int)self->names[k];
        arg = self->arr[k];
        base = (int)&(*self->pp)->sub;
        *(int*)((char*)self + 0x408) = (int)func_002B1B98((int)self->obj, name, arg, base, c, (int)pf, a2, a3);
    }
    func_002B43D8(self);
    *(int*)((char*)self + 0x41C) = -1;
    *(int*)((char*)self + 0x418) = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B3A70);
#ifdef SKIP_ASM
extern "C" void func_002B2018(void*);

extern "C" void func_002B3A70(void* self)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        func_002B2018(p);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B3A98);
#ifdef SKIP_ASM
extern "C" void func_002B2070(void*);

extern "C" void func_002B3A98(void* self)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        func_002B2070(p);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3AC0);
#ifdef SKIP_ASM
struct sSndKey8_3AC0 {
    long v;
} __attribute__((packed));
extern sSndKey8_3AC0 D_004A3838[];
extern sSndKey8_3AC0 D_004A3840[];
extern sSndKey8_3AC0 D_004A3848[];
extern "C" void func_002ADDE0(void* bank, long key);
extern "C" void func_0028A728(void* self, int i);
extern "C" void func_0028BCE8(void* self, int i);
extern "C" void func_002B3A98(void* self);
extern "C" void func_002B1F78(void* self, int flags);

// PORT: 64-bit long sound keys
extern "C" void func_002B3AC0(void* self)
{
    char* s = (char*)self;
    func_002ADDE0(**(char***)s + 0x1D8, D_004A3838[0].v);
    func_002ADDE0(**(char***)s + 0x1D8, D_004A3840[0].v);
    func_002ADDE0(**(char***)s + 0x1D8, D_004A3848[0].v);
    if (*(void**)(s + 0x408) != 0) {
        func_0028A728(**(void***)s, *(int*)(*(char**)(s + 0x408) + 0x34));
        func_0028BCE8(**(void***)s, *(int*)(*(char**)(s + 0x408) + 0x34));
    }
    func_002B3A98(self);
    *(int*)(s + 0x418) = 0;
    if (*(void**)(s + 0x408) != 0) {
        func_002B1F78(*(void**)(s + 0x408), 3);
    }
    *(void**)(s + 0x408) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B3B88);
#ifdef SKIP_ASM
extern "C" void func_002B20C8(void* mon, int a1, int a2);

extern "C" void func_002B3B88(void* self, int a1)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* m = *(void**)((char*)self + 0x408);
        if (m != 0) {
            func_002B20C8(m, a1, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3BC0);
#ifdef SKIP_ASM
struct sBankMonVEntry {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" int func_002B3BC0(void* self, int v)
{
    int r = 0;
    if (*(int*)((char*)self + 0x418) != 0 && v != *(int*)((char*)self + 0x41C)) {
        sBankMonVEntry* vt = *(sBankMonVEntry**)((char*)self + 0x5440);
        vt[3].fn((char*)self + vt[3].delta);
        *(int*)((char*)self + 0x41C) = v;
        r = 1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B3C28);
#ifdef SKIP_ASM
// PORT: called with the monitor as `this`; the unit declares func_002B2120() with no args
void func_002B2120_m(void* mon) __asm__("func_002B2120");

extern "C" void func_002B3C28(void* self)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* m = *(void**)((char*)self + 0x408);
        if (m != 0) {
            func_002B2120_m(m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3C60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002B2140_3C60(int) __asm__("func_002B2140");

extern "C" void func_002B3C60(void *arg0) {
    int temp_4;

    if ((*(int *)((char*)(arg0) + (0x418))) != 0) {
        temp_4 = (*(int *)((char*)(arg0) + (0x408)));
        if (temp_4 != 0) {
            func_002B2140_3C60(temp_4);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3C98);
#ifdef SKIP_ASM
extern "C" void func_002B3C98(void* self, signed char a1)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* p = *(void**)((char*)self + 0x408);
        if (p != 0) {
            *(signed char*)((char*)p + 0x40) = a1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3CC0);
#ifdef SKIP_ASM
extern "C" void func_002B3CC0(void* self, int a1)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        *(int*)((char*)p + 0x54) = a1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3CD8);
#ifdef SKIP_ASM
extern "C" void func_002B3CD8(void* self, int v)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* p = *(void**)((char*)self + 0x408);
        if (p != 0) {
            func_002B2160(p, v);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B3D10);
#ifdef SKIP_ASM
extern "C" void func_002B23E8(void* self, signed char v);

extern "C" void func_002B3D10(void* self, signed char v)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* m = *(void**)((char*)self + 0x408);
        if (m != 0) {
            func_002B23E8(m, v);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B3D48);
#ifdef SKIP_ASM
extern "C" void func_002B2418(void* mon, float v);

extern "C" void func_002B3D48(void* self, float v)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* m = *(void**)((char*)self + 0x408);
        if (m != 0) {
            func_002B2418(m, v);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B3D80);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPacked8_3D80 { long v; } __attribute__((packed));
extern const sPacked8_3D80 D_004A3850_3D80[] __asm__("D_004A3850");
extern void func_002ADCA0_3D80(int a, int b, long t, int c, int d, int e, int f, int g) __asm__("func_002ADCA0");

extern "C" void func_002B3D80(void* self, signed char target, float duration)
{
    signed char cur;
    void* voice = *(void**)((char*)self + 0x408);
    if (voice != 0 && target != (cur = *(signed char*)((char*)voice + 0x40))) {
        int steps = (target - cur) / 25;
        *(int*)((char*)self + 0x414) = target;
        *(float*)((char*)self + 0x410) = (float)cur;
        *(float*)((char*)self + 0x40C) = (float)steps / duration;
        func_002ADCA0_3D80(**(int**)self + 0x1D8, 0x28, D_004A3850_3D80[0].v, 0, 0, 0, 0, 0);
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3E20);
#ifdef SKIP_ASM
extern "C" int func_002B3E20(void* self)
{
    float step = *(float*)((char*)self + 0x40C);
    float cur = *(float*)((char*)self + 0x410) + step;
    *(float*)((char*)self + 0x410) = cur;
    if ((step > 0.0f && cur < (float)*(int*)((char*)self + 0x414))
        || (step < 0.0f && cur > (float)*(int*)((char*)self + 0x414))) {
        *(signed char*)((char*)*(void**)((char*)self + 0x408) + 0x40) = (signed char)(int)*(float*)((char*)self + 0x410);
        return 0;
    }
    signed char t = *(int*)((char*)self + 0x414);
    *(signed char*)((char*)*(void**)((char*)self + 0x408) + 0x40) = t;
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3EB0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_002B3EB0(void* self)
{
    *(ulong*)((char*)self + 0x3f8) = 0;
    *(int*)((char*)self + 0x3e8) = 0;
    for (int i = 4; i >= 0; i--) {
        ((int*)((char*)self + 0x920))[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3EE8);
#ifdef SKIP_ASM
extern "C" int func_0041AD80(const char* a, const char* b);

// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sBankMonFind {
    char pad0[0x124];
    char names[64][11];         // 0x124
    int nnames;                 // 0x3E4
    int count;                  // 0x3E8
    char pad3EC[0x3F8 - 0x3EC];
    ulong mask;                 // 0x3F8
    char pad400[0x420 - 0x400];
    int grid[64][5];            // 0x420
    int totals[5];              // 0x920
};

extern "C" void func_002B3EE8(sBankMonFind* self, const char* name)
{
    if (self->count < 64) {
        for (int i = 0; i < self->nnames; i++) {
            if (func_0041AD80(self->names[i], name) != 0) {
                self->mask |= (ulong)1 << i;
                self->count++;
                for (int j = 0; j < 5; j++) {
                    if (self->grid[i][j] != 0) {
                        self->totals[j]++;
                    }
                }
                return;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3FE8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sBankMonUse {
    char pad0[0x3E8];
    int count;                  // 0x3E8
    char pad3EC[0x3F8 - 0x3EC];
    ulong mask;                 // 0x3F8
    char pad400[0x420 - 0x400];
    int grid[64][5];            // 0x420
    int totals[5];              // 0x920
};

extern "C" void func_002B3FE8(sBankMonUse* self, int idx)
{
    if (self->count < 64) {
        self->count++;
        self->mask |= (ulong)1 << idx;
        for (int i = 0; i < 5; i++) {
            if (self->grid[idx][i] != 0) {
                self->totals[i]++;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4060__FPv);
#ifdef SKIP_ASM
void func_002B4060(void* self)
{
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4068);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long func_002B4068(void *arg0) {
    return (*(long *)((char*)(arg0) + (0x3F8)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B4070);
#ifdef SKIP_ASM
// PORT: 64-bit `long` mask (8 bytes on EE); use uint64_t off-PS2.
struct sBankMonUse;
extern "C" void func_002B3EB0(void* self);
extern "C" void func_002B3FE8(sBankMonUse* self, int idx);
void func_002B4060(void* self);

extern "C" void func_002B4070(void* self, ulong mask)
{
    func_002B3EB0(self);
    for (int i = 0; i < *(int*)((char*)self + 0x3EC); i++) {
        int bit = (mask >> i) & 1;
        if (bit) {
            func_002B3FE8((sBankMonUse*)self, i);
        }
    }
    func_002B4060(self);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B40F0);
#ifdef SKIP_ASM
struct sBankEntry64 {
    char data[0x64];
};

struct sBankMonitor934 {
    char pad[0x3f0];
    int current;                // 0x3F0
    char pad2[0x934 - 0x3f4];
    sBankEntry64 a[64];         // 0x934
    sBankEntry64 b[64];         // 0x2234
    sBankEntry64 c[64];         // 0x3B34
};

extern "C" sBankEntry64* func_002B40F0(sBankMonitor934* self, int i)
{
    if (i < 0) {
        i = self->current;
        if (i < 0) {
            return 0;
        }
    }
    return &self->a[i];
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4120);
#ifdef SKIP_ASM
extern "C" sBankEntry64* func_002B4120(sBankMonitor934* self, int i)
{
    if (i < 0) {
        i = self->current;
        if (i < 0) {
            return 0;
        }
    }
    return &self->b[i];
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4150);
#ifdef SKIP_ASM
extern "C" sBankEntry64* func_002B4150(sBankMonitor934* self, int i)
{
    if (i < 0) {
        i = self->current;
        if (i < 0) {
            return 0;
        }
    }
    return &self->c[i];
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4180);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_002B42B8_vii(void* self, int filter, int kind) __asm__("func_002B42B8");

extern "C" void func_002B4180(void* self, int n)
{
    *(int*)((char*)self + 0x3F0) = -1;
    func_002B42B8_vii(self, 0, 0);
    for (int i = 0; i < n; i++) {
        func_002B42B8_vii(self, 0, 0);
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B41E8);
#ifdef SKIP_ASM
struct sMon41E8 {
    char pad[0x3E4];
    int count;              // 0x3E4
    char pad3E8[0x3F0 - 0x3E8];
    int current;            // 0x3F0
    char pad3F4[0x3F8 - 0x3F4];
    unsigned long mask;     // 0x3F8 (PORT: 64-bit long)
    char pad400[0x420 - 0x400];
    int table[64][5];       // 0x420
    int counts[5];          // 0x920
};

extern "C" void func_002B41E8(sMon41E8* self, int filter, int kind)
{
    if (filter == 0 || self->counts[kind] == 0) {
        do {
            if (--self->current < 0) {
                self->current = self->count - 1;
            }
        } while (!((self->mask >> self->current) & 1));
    } else {
        do {
            if (--self->current < 0) {
                self->current = self->count - 1;
            }
        } while (!((self->mask >> self->current) & 1) || self->table[self->current][kind] == 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B42B8);
#ifdef SKIP_ASM
struct func_002B42B8_sMon {
    char pad[0x3E4];
    int count;              // 0x3E4
    char pad3E8[0x3F0 - 0x3E8];
    int current;            // 0x3F0
    char pad3F4[0x3F8 - 0x3F4];
    unsigned long mask;     // 0x3F8 (PORT: 64-bit long)
    char pad400[0x420 - 0x400];
    int table[64][5];       // 0x420
    int counts[5];          // 0x920
};

extern "C" void func_002B42B8(func_002B42B8_sMon* self, int filter, int kind)
{
    if (filter == 0 || self->counts[kind] == 0) {
        do {
            if (++self->current >= self->count) {
                self->current = 0;
            }
        } while (!((self->mask >> self->current) & 1));
    } else {
        do {
            if (++self->current >= self->count) {
                self->current = 0;
            }
        } while (!((self->mask >> self->current) & 1) || self->table[self->current][kind] == 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4388);
#ifdef SKIP_ASM
extern "C" void func_002B21E0(void*, int);
extern "C" void func_002B4620(void*);

extern "C" void func_002B4388(void* self)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        func_002B21E0(p, 0);
        if (*(int*)((char*)*(void**)((char*)self + 0x408) + 0x50) != 0) {
            func_002B4620(self);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B43D8);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_002B24C0(void* p);
extern "C" void func_0028BD10(void* self, int i, void* id, int a3);
extern char D_004A36E0[];

struct sBankMonHdr { char pad[0x40]; int f40; char names[1][0x20]; };

extern "C" void func_002B43D8(void* self)
{
    char buf[256];
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        int bank = *(int*)((char*)p + 0x34);
        if ((*(sBankMonHdr**)p)->f40 != 0) {
            int n = func_002B24C0(p);
            void* q = *(void**)((char*)self + 0x408);
            sprintf(buf, D_004A36E0, (char*)q + 0x60, (*(sBankMonHdr**)q)->names[n]);
            func_0028BD10(**(void***)self, bank, buf, 0x100);
            *(int*)((char*)*(void**)((char*)self + 0x408) + 0x38) = 1;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B4470);
#ifdef SKIP_ASM
struct sPacked8_4470 { long v; } __attribute__((packed));
extern const sPacked8_4470 D_004A3838_4470[] __asm__("D_004A3838");
extern void func_002ADCA0_4470(int a, int b, long t, int c, int d, int e, int f, int g) __asm__("func_002ADCA0");

// PORT: 64-bit long sound key, read unaligned from a const table
extern "C" void func_002B4470(void* self)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0 && *(int*)((char*)p + 0x4C) == 0) {
        *(int*)((char*)p + 0x4C) = 1;
        func_002ADCA0_4470(*(int*)(*(int*)self) + 0x1D8, 0, D_004A3838_4470[0].v, 0, 0, 0, 0, 0);
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B44D8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sPacked8 { long v; } __attribute__((packed));
extern const sPacked8 D_004A3838_2B44D8[] __asm__("D_004A3838");
extern const sPacked8 D_004A3840_2B44D8[] __asm__("D_004A3840");
extern "C" void func_002ADDE0_m4481(int a, long t) __asm__("func_002ADDE0");
extern "C" void func_002B4708(void* self);

extern "C" void func_002B44D8(void* self)
{
    if (*(void**)((char*)self + 0x408) != 0) {
        func_002ADDE0_m4481(*(int*)(*(int*)self) + 0x1D8, D_004A3838_2B44D8[0].v);
        func_002ADDE0_m4481(*(int*)(*(int*)self) + 0x1D8, D_004A3840_2B44D8[0].v);
        func_002B4708(self);
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4540);
#ifdef SKIP_ASM
class func_002B4540_cObj {
public:
    int unk0;
    void* entries[(0x5440 - 4) / 4];
    // vptr at 0x5440; slot N at vtable offset N*8
    virtual int v01(int a);
};

extern "C" void func_002B4540(func_002B4540_cObj* self, int a)
{
    self->v01(a);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B4568);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern const sPacked8 D_004A3840_2B4568[] __asm__("D_004A3840");
extern "C" int func_002B2778(void* ent);
extern "C" int func_002B2500(void* ent);
extern "C" void func_002ADCA0(int a, int b, long t, void* c, int d, int e, int f, int g);

extern "C" void func_002B4568(void* self, void* ent)
{
    if (*(void**)((char*)self + 0x408) != 0) {
        float a = func_002B2690(ent);
        float b = func_002B2718(ent);
        int c = func_002B2778(ent) + 1;
        int d = func_002B2500(ent);
        func_002ADCA0(**(int**)self + 0x1D8, (int)b, D_004A3840_2B4568[0].v, *(void**)((char*)self + 0x408), d, c, (int)a, 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4620);
#ifdef SKIP_ASM
extern "C" void func_003D2DF8(int cmd, int a, int b);

struct sBmStream4620 {
    int state;      // 0x0
    int handle;     // 0x4
    char pad[0x60 - 8];
};

static inline int func_002B4620_ready(sBmStream4620* e)
{
    return e->state == 1;
}

// PORT: the unit declares func_002B4620 as void; it really returns 0/1.
int func_002B4620_impl(void* self) __asm__("func_002B4620");

int func_002B4620_impl(void* self)
{
    int one = 1;
    if (*(char**)((char*)self + 0x408) == 0) return 0;
    *(int*)(*(char**)((char*)self + 0x408) + 0x4C) = one;
    int r = 0;
    char* m = *(char**)((char*)self + 0x408);
    int st = *(int*)(m + 0x38);
    if (st == one) {
        // PORT: pointer arithmetic through int
        sBmStream4620* e = (sBmStream4620*)(*(int*)(m + 0x34) * 0x60 + *(int*)(**(char***)self + 0xACC));
        if (func_002B4620_ready(e)) {
            func_003D2DF8(0x11000002, 0, e->handle);
            *(int*)(*(char**)((char*)self + 0x408) + 0x38) = 2;
            r = 1;
        }
    } else if (st == 2) {
        r = one;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B46D0);
#ifdef SKIP_ASM
extern "C" void func_002B46D0(void* self)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        *(int*)((char*)p + 0x50) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B46E8);
#ifdef SKIP_ASM
extern "C" void* func_002B46E8(void* self)
{
    void* inner = *(void**)((char*)self + 0x408);
    if (inner == 0) {
        return 0;
    }
    return *(void**)((char*)inner + 0x4C);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4708);
#ifdef SKIP_ASM
extern "C" void func_002B4708(void* self)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        *(int*)((char*)p + 0x4c) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4720);
#ifdef SKIP_ASM
extern "C" int func_002B4720(void* self)
{
    char* p = *(char**)((char*)self + 0x408);
    if (p == 0) {
        return 0;
    }
    return *(signed char*)(p + 0x40);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B4740);
#ifdef SKIP_ASM
extern "C" void func_002B4568(void* self, void* ent);

extern "C" int func_002B4740(void* self)
{
    void* ent = *(void**)((char*)self + 0x408);
    char* table = *(char**)((char*)**(void***)self + 0xACC);
    int state = *(int*)(table + *(int*)((char*)ent + 0x34) * 0x60);
    switch (state) {
    case 0:
        return 1;
    case 1:
        func_002B4568(self, ent);
        return 1;
    case 2:
        return 0;
    default:
        return 1;
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B47C0);
#ifdef SKIP_ASM
extern "C" int func_002B9F88(void*, int);
extern "C" int func_003B65D0(int);

extern "C" int func_002B47C0(void* self)
{
    int ok = 0;
    int slot = *(int*)((char*)*(void**)((char*)self + 0x408) + 0x34);
    void* other = **(void***)self;
    func_003B58A0();
    bool notReady = *(int*)(slot * 0x60 + *(int*)((char*)other + 0xACC)) != 1;
    if (!notReady) {
        ok = func_003B65D0(func_002B9F88(other, slot)) == 1;
    }
    func_003B58D8();
    if (ok == 0) {
        *(int*)((char*)*(void**)((char*)self + 0x408) + 0x4C) = 0;
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4868__FPv);
#ifdef SKIP_ASM
int func_002B4868(void* self)
{
    return *(int*)((char*)*(void**)self + 0x94);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B4878);
#ifdef SKIP_ASM
extern "C" int func_002B4878(void* self)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* m = *(void**)((char*)self + 0x408);
        if (m != 0) {
            return func_002B4868(m);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B48B8);
#ifdef SKIP_ASM
extern "C" int func_002B48B8(void **arg0) {
    return (*(int *)((char*)(*arg0) + (0x98)));
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B48C8);
#ifdef SKIP_ASM
extern "C" int func_002B48C8(void* self)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void** p = *(void***)((char*)self + 0x408);
        if (p != 0) {
            return func_002B48B8(p);
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4908__FPv);
#ifdef SKIP_ASM
int func_002B4908(void* self)
{
    void* p = *(void**)((char*)self + (*(int*)((char*)self + 0x3f0) << 2) + 0x4);
    return *(int*)((char*)p + 0x98);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B4920);
#ifdef SKIP_ASM
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" float func_002B2718(void* self);

extern "C" float func_002B4920(void* self)
{
    if (*(int*)((char*)self + 0x418) == 0) {
        return 0.0f;
    }
    func_003B58A0();
    float r = func_002B2718(*(void**)((char*)self + 0x408));
    func_003B58D8();
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4978);
#ifdef SKIP_ASM
class func_002B4978_cObj {
public:
    int unk0;
    void* entries[(0x5440 - 4) / 4];
    // vptr at 0x5440; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03(int a);
};

extern "C" void func_002B4978(func_002B4978_cObj* self, int i)
{
    int v = *(int*)((char*)self->entries[i] + 0xA0);
    if (v >= 0) {
        self->v03(v);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B49C0);
#ifdef SKIP_ASM
extern "C" void func_002B49C0(void* self, int a1)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* p = *(void**)((char*)self + 0x408);
        if (p != 0) {
            *(int*)((char*)p + 0x58) = a1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B49E0);
#ifdef SKIP_ASM
extern "C" int func_002B49E0(void* self)
{
    if (*(int*)((char*)self + 0x418) != 0) {
        void* p = *(void**)((char*)self + 0x408);
        if (p != 0) {
            return *(int*)((char*)p + 0x58);
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4A08);
#ifdef SKIP_ASM
extern "C" void func_002B4A08(void* self, int a1)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0) {
        *(int*)((char*)p + 0x5c) = a1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4A20);
#ifdef SKIP_ASM
extern "C" void func_003DFAF0(void* f);
extern "C" void ASYNCFILE_release(void* f, int a, int b);
extern "C" void* func_003DF748(void* name, void* buf, int size);
extern "C" void func_003E1B68(void* name, void* buf, int size);

extern "C" void func_002B4A20(void* self, void* name, int sync)
{
    if (*(void**)((char*)self + 0x5438) != 0) {
        func_003DFAF0(*(void**)((char*)self + 0x5438));
        ASYNCFILE_release(*(void**)((char*)self + 0x5438), 0, 0);
    }
    if (sync == 0) {
        *(void**)((char*)self + 0x5438) = func_003DF748(name, *(void**)((char*)self + 0x5434), 0x6400);
    } else {
        func_003E1B68(name, *(void**)((char*)self + 0x5434), 0x6400);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4AA0);
#ifdef SKIP_ASM
extern "C" int func_003DF980(void*);

extern "C" int func_002B4AA0(void* self, int force)
{
    void* p;
    if (force != 0) {
        return 1;
    }
    p = *(void**)((char*)self + 0x5438);
    if (p != 0 && func_003DF980(p) == 1) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4AE8__FPv);
#ifdef SKIP_ASM
int func_002B4AE8(void* self)
{
    return *(int*)((char*)self + 0x5434);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4AF0);
#ifdef SKIP_ASM
// PORT: needs a 64-bit return (ulong); use uint64_t off-PS2.
extern "C" ulong func_002B4AF0(void* self)
{
    return (*(ulong*)((char*)self + 0x3f8) >> *(int*)((char*)self + 0x3f0)) & 1;
}
#endif

