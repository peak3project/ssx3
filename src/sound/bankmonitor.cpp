#include "common.h"

class cController;
class cBankMonitorInstance;
// Sound callback: a g++ 2.95 pointer to member function (8 bytes), as cSndPlayOpts::OPTS_Callback takes it
// (same type as sound/soundsys).
typedef void (cController::*sSndCallback)(cController*, cBankMonitorInstance*, float);

// OPTS_Callback handlers passed to func_002ADCA0 / func_002ADDE0: 8-byte pointer-to-member constants.
extern const sSndCallback D_004A37D8[];
extern const sSndCallback D_004A37E0[];
extern const sSndCallback D_004A3838[];
extern const sSndCallback D_004A3840[];
extern const sSndCallback D_004A3848[];
extern const sSndCallback D_004A3850[];

// g++ 2.95 vtable entry with an untyped function slot (vtables copied / patched as data), as in sound/soundsys.
struct sSndVtSlot {
    short delta;
    short index;
    void* fn;
};

// 4-entry vtable image (the hand-expanded virtual-base ctors / dtors copy one to the stack and patch a delta).
struct sSndVtbl4 {
    sSndVtSlot e[4];
} __attribute__((aligned(8)));

// 7-entry vtable image (same use as sSndVtbl4).
struct sSndVtbl7 {
    sSndVtSlot e[7];
} __attribute__((aligned(8)));

// Virtual-base vtable images patched by the ctors / dtors below.
extern const sSndVtbl4 D_00483B88;
extern const sSndVtbl4 D_00483BC0;
extern const sSndVtbl4 D_004838A0;
extern const sSndVtbl7 D_004838C0;
extern const sSndVtbl4 D_00483928;
extern const sSndVtbl7 D_00483948;
// Primary vtables.
extern void* D_00483B48[];
extern void* D_00483BA8[];
extern void* D_00483870[];
extern void* D_004838F8[];
extern char D_00483C00[];
extern char D_00483980[];

struct sBmQuad {
    int w[4];
} __attribute__((aligned(16)));

// One entry of cSndPlayOpts' option stack (mCurrent[], 0x18 bytes); byte 0 seeds mBaseVol.
struct sSndOptsRec {
    signed char vol;
    char pad1[3];
    int f4[5];
};

// One cSndPlayOpts mDelay[] entry (reset to 100 / 0 / 90 / 50 on every push).
struct sSndOptsDelay {
    int f0;
    int f4;
    int f8;
    int fC;
};

// cSndPlayOpts (prototype class, as in sound/soundsys): the play-option stack; push = cur++ and copy def into
// ch[cur]. Field names follow sound/soundsys (ch = mCurrent, vals = mBaseVol, p70 = mDelay, ...).
struct cSndPlayOpts {
    char* vbase;                // 0x00 virtual-base pointer
    sSndOptsRec def;            // 0x04
    volatile int cur;           // 0x1C
    sSndOptsRec* ch;            // 0x20
    sBmQuad* tgt[4];            // 0x24
    int* p34;                   // 0x34
    int* vals;                  // 0x38
    int* p3C;                   // 0x3C
    sSndCallback callbacks[4];  // 0x40
    int* p60;                   // 0x60
    int* p64;                   // 0x64
    float* p68;                 // 0x68
    float* p6C;                 // 0x6C
    sSndOptsDelay* p70;         // 0x70
    int* p74;                   // 0x74
    int* p78;                   // 0x78
    int* p7C;                   // 0x7C
    int* p80;                   // 0x80
    int* p84;                   // 0x84
};

// One of a sound player's 48 monitored-sound slots (0x2C bytes).
struct sBmSlot {
    char pad00[0xC];
    sSndCallback callback;      // 0x0C
    char pad14[0x18 - 0x14];
    int f18;                    // 0x18
    int f1C;                    // 0x1C
    int f20;                    // 0x20
    int f24;                    // 0x24
    int f28;                    // 0x28
};

// Sound player: a cSndPlayOpts (0x88 bytes) plus 48 monitored-sound slots; virtual base at 0x8DC.
struct sSndPlayer : public cSndPlayOpts {
    int f88;                    // 0x88
    int f8C;                    // 0x8C
    volatile int busy;          // 0x90
    char pad_0x94[0x4];
    sBmSlot slots[48];          // 0x98
    void** vtbl;                // 0x8D8
    char vb[0x4];               // 0x8DC
};

// cBankManager as this unit sees it (as in sound/soundsys): only its sound player at 0x1D8 is used here.
struct cBankManager {
    char pad0[0x1D8];
    sSndPlayer sub;             // 0x1D8
};

extern "C" void* func_002AB9E0(void* self);

// One of a bank monitor's 64 voices (0xC0 bytes).
struct sBmVoice {
    int kind;                   // 0x00 (1 / 2: which sound system plays it)
    int id;                     // 0x04
    int valid;                  // 0x08
    int handle;                 // 0x0C
    char pad10[0x58 - 0x10];
    int f58;                    // 0x58
    float value;                // 0x5C
    int f60;                    // 0x60
    int vol;                    // 0x64
    sBmQuad* tgt;               // 0x68
    int f6C;                    // 0x6C
    sBmQuad tgtCopy;            // 0x70
    int f80;                    // 0x80
    int f84;                    // 0x84
    float f88;                  // 0x88
    float f8C;                  // 0x8C
    float f90;                  // 0x90
    int f94;                    // 0x94
    int f98;                    // 0x98
    int f9C;                    // 0x9C
    int fA0;                    // 0xA0
    int fA4;                    // 0xA4
    sSndCallback callback;      // 0xA8
    char padB0[0xC0 - 0xB0];
    sBmVoice() { func_002AB9E0(this); }
    void operator delete[](void* p, unsigned int size);
};

// cBankMonitor: a sound player (cSndPlayOpts part at 0x0, player part up to 0x8DC) plus 64 voices;
// virtual base at 0x8F0.
struct cBankMonitor : public cSndPlayOpts {
    char pad88[0x8D8 - 0x88];
    void** vtbl;                // 0x8D8
    volatile int busy;          // 0x8DC
    int f8E0;                   // 0x8E0
    int f8E4;                   // 0x8E4
    int f8E8;                   // 0x8E8
    sBmVoice* voices;           // 0x8EC
    char vb[0x4];               // 0x8F0
};

// One of the 24 bank-slot records D_004D3EF8 (0x28 bytes): sound id, handle and bank index (-1 = free).
struct sBankMonSlot28 {
    int id;         // 0x00
    int handle;     // 0x04
    int bank;       // 0x08
    int fC;         // 0x0C
    int f10;        // 0x10
    int f14;        // 0x14
    int f18;        // 0x18
    int f1C;        // 0x1C
    int f20;        // 0x20
    int f24;        // 0x24
};
extern sBankMonSlot28 D_004D3EF8[];

// One of the 24 bank records D_004D3E98 points at (0x70 bytes) and its per-sound sub-entries (12 bytes).
struct sMonSub {
    int size;   // 0x0
    int id;     // 0x4
    int pos;    // 0x8
};

struct sMonSlot {
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
    sMonSub* subs;      // 0x6C
};

extern void* D_004D3E98[];

// A loaded sound stream object (func_002AF960, 0x4C bytes); 0x40 is passed on as its short name.
struct sBmObj {
    char pad[0x40];
    int f40;                    // 0x40
};

struct sBmVoicePair {
    void* handle;               // 0x0
    int active;                 // 0x4
};

struct sBmHandlePair {
    void* p[2];
};

// A bank list (func_002AFA68 ctor / func_002AFB38 dtor): its voices and up to 500 loaded streams.
struct sBankList {
    int f0;                     // 0x0
    int id;                     // 0x4
    int f8;                     // 0x8
    char fC;                    // 0xC
    char pad_0xD[0xCC - 0xD];
    sBmVoicePair voices[4];     // 0xCC
    int voiceCount;             // 0xEC
    int count;                  // 0xF0
    sBmObj* streams[(0x8C4 - 0xF4) / 4];  // 0xF4
    int f8C4;                   // 0x8C4
    int f8C8;                   // 0x8C8
    int f8CC;                   // 0x8CC
    int f8D0;                   // 0x8D0
    sBmHandlePair pairs[4];     // 0x8D4
    float f8F4;                 // 0x8F4
    int f8F8;                   // 0x8F8
    int f8FC;                   // 0x8FC
    int f900;                   // 0x900
};

struct sBankEntry64 {
    char data[0x64];
};

// The speech-bank monitor (func_002B3398 dtor): up to 64 named banks, the selection mask and per-kind counts.
// PORT: 64-bit `long` mask (8 bytes on EE, 4 on Windows); use uint64_t off-PS2.
struct sSpeechMon {
    cBankManager** pp;          // 0x000
    int arr[64];                // 0x004
    char obj[0x20];             // 0x104
    char names[64][11];         // 0x124
    int count;                  // 0x3E4 (number of names)
    int selected;               // 0x3E8
    int f3EC;                   // 0x3EC
    int current;                // 0x3F0
    int pad3F4;
    ulong mask;                 // 0x3F8
    char pad400[0x40C - 0x400];
    int res;                    // 0x40C
    char pad410[0x420 - 0x410];
    int grid[64][5];            // 0x420
    int totals[5];              // 0x920
    sBankEntry64 a[64];         // 0x934
    sBankEntry64 b[64];         // 0x2234
    sBankEntry64 c[64];         // 0x3B34
};
extern "C" void func_003B58D8(void);
extern "C" void func_003B58A0(void);
extern char* D_004A37B4;
extern "C" int sprintf(char* buf, const char* fmt, ...);
void operator_delete(int* ptr);
extern "C" void func_002AEFA8(int a0);
extern "C" int func_002B2488(void* self);
extern void*** D_004A37EC;
extern char D_004A36E0[];
extern "C" void func_002ABB38(void*);
void cMemMan_free(void*);
extern "C" void func_002ADEE8(void* self, int flags);
extern "C" int func_002ABB80(void*);
extern void* D_004A377C;
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_002AD940(void*);
extern "C" int func_003B7FB8(int h, int v);
extern "C" int func_002AE230(int a, int b);
void func_002AD970(void* self, int a1);
extern void* (*D_004A3794)(void*);
extern void* (*D_004A378C)(void*, int, int);
extern void (*D_004A3798)();
extern int D_004A37BC;
extern int D_004A37B8;
extern int D_004A379C;
extern char D_004A3590[];
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_003D7EC8(void* p);
extern "C" void* func_002ADE88(void* self, int a);
extern "C" void* func_002AD550(void* self, int idx, int a2);
extern "C" void* func_00252FA0(void* a0, int a1, int a2);
extern "C" void* func_002523A8(void* self);
extern "C" void func_003D1038(int cmd, int v);
extern "C" void func_003B5948(int id);
extern "C" void func_002B21E0(void*, int);
extern "C" void func_002B20C8(void* mon, int a1, int a2);
extern "C" void func_002B1F78(void* self, int flags);
extern "C" void func_002ACB80(void* voice, int a, int b, float v);
extern "C" void func_002AA648(void* self, int flags);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_0028A728(void* self, int i);
extern "C" void bxLogPrint(const char* fmt, ...);
extern "C" unsigned int strlen(const char* s);
extern "C" int func_003E4E98();
extern "C" int func_003B7E70(int h, int v);
// PORT: declared as (int, int); the second argument is an out-pointer
extern "C" int func_003B7C40(int h, int v);
extern "C" int func_003B7B48(int h, void* out);
extern "C" int func_003B65D0(int);
extern "C" int func_002B9F88(void*, int);
extern "C" int func_002B0290(void* p);
extern "C" int func_002AF8A8(int a);
extern "C" int func_002AB150(void* self, int i);
extern "C" int func_002AB028(void* self, int i);
extern "C" int func_002AAE08(void* self, int i);
extern "C" float func_002AAE78(void* self, int i);

//100%
INCLUDE_ASM("sound/bankmonitor", cBankMonitor_cBankMonitor);
#ifdef SKIP_ASM
extern "C" sSndPlayer* func_002AD9C8(sSndPlayer* self, int inchrg, int heap);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_00483238[];

extern "C" cBankMonitor* cBankMonitor_cBankMonitor(cBankMonitor* self, int inchrg, int heap)
{
    if (inchrg) {
        self->vbase = self->vb;
        func_002ADE88(self->vb, heap);
    }
    func_002AD9C8((sSndPlayer*)self, 0, heap);
    *(const sSndVtbl4**)(self->vbase + 4) = &D_00483B88;
    if (!inchrg) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sSndVtbl4 vt = D_00483B88;
        *(sSndVtbl4**)(self->vbase + 4) = &vt;
        char* base = self->vbase - 0x8F0;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483B88.e[1].delta + d;
    }
    self->vtbl = D_00483B48;
    self->busy = 0;
    self->f8E0 = 1;
    self->f8E4 = 1;
    sBmVoice** slot = &self->voices;
    *slot = new (D_00483238, 0, 0) sBmVoice[64];
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ACE40);
#ifdef SKIP_ASM
extern "C" void func_002ABA18(void* self, int flags);
extern "C" void func_002ADAC8(sSndPlayer* self, int flags);

extern "C" void func_002ACE40(cBankMonitor* self, int flags)
{
    self->vtbl = D_00483B48;
    *(const sSndVtbl4**)(self->vbase + 4) = &D_00483B88;
    if (flags == 0) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sSndVtbl4 vt = D_00483B88;
        *(sSndVtbl4**)(self->vbase + 4) = &vt;
        char* base = self->vbase - 0x8F0;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483B88.e[1].delta + d;
    }
    if (self->voices != 0) {
        sBmVoice* q = self->voices + ((int*)self->voices)[-4];
        while (self->voices != q) {
            q--;
            func_002ABA18(q, 0);
        }
        cMemMan_free((char*)self->voices - 0x10);
    }
    func_002ADAC8((sSndPlayer*)self, 0);
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

//100%
INCLUDE_ASM("sound/bankmonitor", cBankMonitor_BANKMONITOR_Create);
#ifdef SKIP_ASM
extern "C" int func_002ACF60(void* self, int n);
extern "C" void func_002ABD48(void* voice, void* mon);
extern "C" void func_003B89E0(int h);
extern "C" int func_003B9920(int h);
extern char D_00483250[];

// cSndPlayOpts::OPTS_GetCallback (prototype name; out-of-line copy in bx is func_002B91C8)
static inline sSndCallback OPTS_GetCallback_Create(cBankMonitor* s)
{
    return s->callbacks[s->cur];
}

static inline void setCallback_Create(sBmVoice* v, sSndCallback k)
{
    v->callback = k;
}

extern "C" sBmVoice* cBankMonitor_BANKMONITOR_Create(cBankMonitor* self, int id, int vol, int kind)
{
    sBmVoice* v = 0;
    self->busy++;
    int idx = func_002ACF60(self, self->busy);
    if (idx >= 0) {
        v = &self->voices[idx];
        func_002ABB38(v);
        v->kind = kind;
        v->id = id;
        v->f60 = self->p3C[self->cur];
        v->vol = vol;
        v->tgt = self->tgt[self->cur];
        setCallback_Create(v, OPTS_GetCallback_Create(self));
        v->f80 = self->p60[self->cur];
        v->f84 = self->p64[self->cur];
        if (self->p34[self->cur] != 0) {
            v->tgtCopy = *v->tgt;
            v->tgt = &v->tgtCopy;
        }
        v->f88 = self->p68[self->cur];
        v->f8C = self->p6C[self->cur];
        v->f94 = self->p74[self->cur];
        v->f98 = self->p78[self->cur];
        int f9C = self->p7C[self->cur];
        if (v->f58 == 0)
            v->f9C = f9C;
        v->f90 = -1.0f;
        v->fA0 = self->p80[self->cur];
        v->fA4 = self->p84[self->cur];
        if (self->tgt[self->cur] != 0)
            func_002ABD48(v, self);
        v->valid = id >= 0;
    } else {
        bxLogPrint(D_00483250);
        switch (kind) {
        case 1:
            func_003B89E0(id);
            break;
        case 2:
            func_003B9920(id);
            break;
        }
    }
    self->busy--;
    return v;
}
#endif

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
static inline int func_002AD410_match(sBmVoice* v, sSndCallback k)
{
    return k == v->callback;
}

// Stops every voice playing with the given callback.
extern "C" void func_002AD410(void* self, sSndCallback key)
{
    for (int i = 0; i < 64; i++) {
        if (func_002AD410_match((sBmVoice*)((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0), key)) {
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
extern "C" void* func_002AD550(void* self, int idx, int key)
{
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) == 0
            && (*(sBmVoice**)((char*)self + 0x8EC))[i].kind == key
            && (*(sBmVoice**)((char*)self + 0x8EC))[i].id == idx) {
            return &(*(sBmVoice**)((char*)self + 0x8EC))[i];
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AD5F0);
#ifdef SKIP_ASM
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
// PORT: same ABI as the unit's func_002ACB80(void*, int, int, float); the float is
// the 2nd parameter in the original, which orders the argument moves.
void func_002ACB80_f(void* voice, float v, int a, int b) __asm__("func_002ACB80");

extern "C" void func_002AD650(void* self, int id, float v)
{
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) == 0) {
            // PORT: pointer arithmetic through int
            sBmVoice* e = (sBmVoice*)(i * 0xC0 + *(int*)((char*)self + 0x8EC));
            if (e->kind == 1 && e->handle == id) {
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
extern "C" int func_002AD730(void* self)
{
    int count = 0;
    for (int i = 0; i < 64; i++) {
        if (func_002ABB80((char*)*(void**)((char*)self + 0x8EC) + i * 0xC0) == 0) {
            // PORT: pointer arithmetic through int
            sBmVoice* e = (sBmVoice*)(i * 0xC0 + *(int*)((char*)self + 0x8EC));
            if (e->valid != 0) {
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
extern "C" void func_002AD810(void* self)
{
    for (int i = 0; i < 64; i++) {
        (*(sBmVoice**)((char*)self + 0x8ec))[i].value = -1.0f;
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
void func_002AD980(void* self);

extern "C" void func_002AD888(sBmSlot* self, int a1, sSndCallback key, int b, int c, int d, int e, int f)
{
    func_002AD940(self);
    func_002AD970(self, a1);
    self->callback = key;
    self->f18 = b;
    self->f1C = c;
    self->f20 = d;
    self->f24 = e;
    self->f28 = f;
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

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AD9C8);
#ifdef SKIP_ASM
// w1 round 2: all 120 permutations of {f88,f8C,vtbl,f90,p=slots} statement order scored 96.83-96.88, none 100.
// 96.88%: player base ctor (vbase at 0x8DC, vtable fix-up like cBankMonitor ctor). Only diff: target schedules `lui $2,%hi(D_00483BA8)` AFTER the first `sw $0,0x88`, ours before it. Store order permutations and a 5-min permuter run did not change it.
extern "C" void* cSndPlayOpts_cSndPlayOpts(void* self, int inchrg, int heap);
void* func_002AD848(void* self);

// Release-build assert: compiles to an empty do { } while (0) (its loop notes still shape the code)
#define ASSERT_D9C8(cond) do { } while (0)
extern "C" sSndPlayer* func_002AD9C8(sSndPlayer* self, int inchrg, int heap)
{
    if (inchrg) {
        self->vbase = self->vb;
        func_002ADE88(self->vb, heap);
    }
    cSndPlayOpts_cSndPlayOpts(self, 0, heap);
    *(const sSndVtbl4**)(self->vbase + 4) = &D_00483BC0;
    if (!inchrg) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sSndVtbl4 vt = D_00483BC0;
        *(sSndVtbl4**)(self->vbase + 4) = &vt;
        char* base = self->vbase - 0x8DC;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483BC0.e[1].delta + d;
    }
    self->f88 = 0;
    ASSERT_D9C8(self != 0);
    self->vtbl = D_00483BA8;
    self->f8C = 0;
    sBmSlot* p = self->slots;
    self->busy = 0;
    int i = 47;
    do {
        func_002AD848(p);
        i--;
        p++;
    } while (i != -1);
    D_004A3778 = (func_002AD998_cObj*)self;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADAC8);
#ifdef SKIP_ASM
extern "C" void func_002A97C0(void* self, int flags);

extern "C" void func_002ADAC8(sSndPlayer* self, int flags)
{
    sBmSlot* end = self->slots + 48;
    self->vtbl = D_00483BA8;
    *(const sSndVtbl4**)(self->vbase + 4) = &D_00483BC0;
    if (flags == 0) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-up (copied vtable on the stack), written out by hand.
        sSndVtbl4 vt = D_00483BC0;
        *(sSndVtbl4**)(self->vbase + 4) = &vt;
        char* base = self->vbase - 0x8DC;
        int d = (char*)self - base;
        vt.e[1].delta = D_00483BC0.e[1].delta + d;
    }
    // PORT: function pointer passed as int
    func_003B5948((int)func_002AD998);
    D_004A3778 = 0;
    if (self->slots != 0) {
        sBmSlot* p = end;
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
extern "C" void func_003B5910(void*);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADBF0__FPv);
#ifdef SKIP_ASM
void func_002ADBF0(void* self)
{
    func_003B5910((void*)func_002AD998);
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

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADCA0);
#ifdef SKIP_ASM
extern "C" int func_002ADC30(void* self, int n);

void func_002AD888_cb(void* self, int a1, sSndCallback cb, int b, int c, int d, int e, int f) __asm__("func_002AD888");

extern "C" int func_002ADCA0(sSndPlayer* self, int a1, sSndCallback cb, int b, int c, int d, int e, int f)
{
    self->busy = self->busy + 1;
    int idx = func_002ADC30(self, self->busy);
    if (idx >= 0) {
        func_002AD888_cb((char*)self + 0x98 + idx * 0x2C, a1, cb, b, c, d, e, f);
    }
    self->busy = self->busy - 1;
    return idx;
}
#endif

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
static inline int func_002ADDE0_match(sBmSlot* e, sSndCallback k)
{
    return k == e->callback;
}

// Stops every one of the 48 monitored sounds that plays with the given callback.
extern "C" void func_002ADDE0(void* self, sSndCallback key)
{
    for (int i = 0; i < 48; i++) {
        if (func_002ADDE0_match((sBmSlot*)((char*)self + 0x98 + i * 0x2C), key)) {
            func_002AD940((char*)self + 0x98 + i * 0x2C);
        }
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

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADFB0__Fi);
#ifdef SKIP_ASM
int func_002ADFB0(int self)
{
    return *(int*)((char*)(void*)D_004D3E98 + self * 4);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002ADFC8);
#ifdef SKIP_ASM
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
extern "C" void REAL_abortmessage();
extern "C" void func_004175C8();
extern "C" void* func_002526B8(void* block, int size);
extern "C" void SYNCTASK_add(int (*fn)(), int a, int b);
extern void (*D_004A3780)();
extern void (*D_004A3784)();
extern void* (*D_004A3790)(void*, int);

extern "C" void func_002AE048(void (*cb)(), int id)
{
    for (int i = 0; i < 24; i++) {
        D_004D3E98[i] = 0;
        D_004D3EF8[i].bank = -1;
        D_004D3EF8[i].handle = -1;
        D_004D3EF8[i].id = -1;
        D_004D3EF8[i].f18 = 0;
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
// Finds a slot: bank < 0 asks for a free slot, otherwise the slot holding bank (and id, unless id < 0).
extern "C" int func_002AE230(int bank, int id)
{
    sBankMonSlot28* s = D_004D3EF8;
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
extern "C" int func_002AE298(int a, int unused, int b, int c)
{
    int i = func_002AE230(a, b);
    if (i >= 0 || (i = func_002AE230(-1, -1)) >= 0) {
        sBankMonSlot28* e = &D_004D3EF8[i];
        e->f1C = 1;
        e->bank = a;
        e->id = b;
        e->handle = c;
        return c;
    }
    return -13;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AE328);
#ifdef SKIP_ASM
extern "C" int func_003B6300(int id);

extern "C" int func_002AE328(int a, int b)
{
    int none = -1;
    int i = func_002AE230(a, b);
    if (i < 0) {
        return -1;
    }
    sBankMonSlot28* e = &D_004D3EF8[i];
    if (e->handle >= 0) {
        func_003B6300(-1);
        e->f14 = 0;
        e->handle = none;
        e->bank = none;
        e->id = none;
        e->f1C = 0;
        e->f24 = none;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002AE3A8);
#ifdef SKIP_ASM
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
extern "C" int func_002AE1B8(void);
extern "C" void func_002AE138(void* self);
extern "C" int func_003B7818(void* desc, int n, int m, void* mem, int size);
extern "C" int func_003BA020(void* desc);
extern char D_004A37A8[];

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
        (*(sMonSub**)(b + 0x6C))[i].id = -1;
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
extern "C" int func_003B7838(int id);

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
extern "C" int func_003B7D80(void*, int);

extern "C" void func_002AE9F8(int i, int arg1)
{
    void* p = D_004D3E98[i];
    if (*(signed char*)((char*)p + 0x64) == 0) {
        func_003B7D80(*(void**)((char*)*(void**)((char*)p + 0x6C) + 0x4), arg1);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEA38);
#ifdef SKIP_ASM
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
        if ((*(sMonSub**)((char*)m + 0x6C))[sub].id >= 0) {
            return (*(sMonSub**)((char*)m + 0x6C))[sub].pos;
        }
        return -8;
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEB40);
#ifdef SKIP_ASM
extern "C" int func_002AEB40(int idx, int key)
{
    void* ch = D_004D3E98[idx];
    if (ch != 0 && *(char*)((char*)ch + 0x65) != 0) {
        func_002AEFA8(0);
    }
    for (int i = 0; i < *(signed char*)((char*)ch + 0x66); i++) {
        sMonSub* e = &(*(sMonSub**)((char*)ch + 0x6C))[i];
        if (e->id == key) {
            return e->pos;
        }
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AEBD0);
#ifdef SKIP_ASM
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
extern "C" int func_003B6670(int h, int sub, void* hdr, void* buf, unsigned int* pos);
extern "C" int func_003B8AD8(int h);
extern "C" int func_003B86C0(int h);
extern "C" int func_003B7F18(int h);

struct sStrmInfo {
    int count;
    int pad[3];
};

struct sStrmState {
    int state;  // 0x0
    int a;      // 0x4
    int b;      // 0x8
    int c;      // 0xC
};

struct sStrmPos {
    unsigned int samples;   // 0x0
    int pad[7];
};

struct sStrmHdr {
    unsigned short rate;
    char pad[0xE];
};

// PORT: the end of this function stores the out-pointers themselves into the slot (as in the original)
extern "C" int func_002AEC58(int idx, int* outA, int* outB)
{
    sMonSlot* m = (sMonSlot*)D_004D3E98[idx];
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
    sStrmInfo info;
    sStrmState st;
    sStrmHdr hdr;
    char buf[0x70];
    sStrmPos pos;
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
extern "C" void func_002AEFA8(int reset)
{
    func_003B58A0();
    for (int i = 0; i < 24; i++) {
        sMonSlot* m = (sMonSlot*)D_004D3E98[i];
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
            sStrmInfo info;
            sStrmState st;
            sStrmHdr hdr;
            char buf[0x70];
            sStrmPos pos;
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
extern "C" int func_004139F8(float);
extern int D_00450DC8[];

extern "C" int func_002AF370(void)
{
    return func_004139F8((float)func_003E4E98() / (float)D_00450DC8[0] * 1000.0f);
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
extern "C" int func_003B85F0(int h, int v);

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
extern "C" int func_003B8790(int h, int v);

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
extern "C" int func_003B78F8(int);
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

extern "C" int func_002AF8A8(int a)
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
    *(int*)((char*)self + 0x48) = 0;
    *(int*)self = -1;
    *(int*)((char*)self + 0x44) = 0;
    *(signed char*)((char*)self + 0x4) = (signed char)0;
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
extern "C" void func_002AA910(void* sys, int id, int a, int b, int c);
extern "C" void func_002B0088(void* self, int a, int b, int c);

extern "C" void* func_002AFA68(void* mem, int a1, int a2, int a3, int a4, int a5, int a6)
{
    sBankList* self = (sBankList*)mem;
    self->f0 = a1;
    self->id = a2;
    self->f900 = 1;
    self->f8 = a6;
    self->voiceCount = 0;
    self->count = 0;
    self->f8C4 = 0;
    self->f8C8 = 0;
    self->f8CC = 0;
    self->f8D0 = 0;
    self->f8F4 = 0;
    self->fC = 0;
    for (int i = 0; i < 4; i++) {
        self->voices[i].handle = 0;
        self->voices[i].active = 0;
    }
    func_002AA910(*(void**)D_004A37B4, self->id, a4, 0, 0x20000);
    func_002B0088(self, a1, a3, a5);
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AFB38);
#ifdef SKIP_ASM
extern "C" void func_002AABD0(void* self, int i);
extern "C" void func_002AF900(int* self, int flags);

extern "C" void func_002AFB38(void* selfp, int flags)
{
    sBankList* self = (sBankList*)selfp;
    int i;
    for (i = 0; i < self->count; i++) {
        if (self->streams[i] != 0) {
            func_002AF900((int*)self->streams[i], 3);
        }
    }
    D_004A37B8 -= self->count;
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
extern "C" void* func_003D8040(void* p);

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

//100%
INCLUDE_ASM("sound/bankmonitor", func_002AFD40);
#ifdef SKIP_ASM
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);
extern "C" void* func_003E1908(const char* name, int flags);
extern "C" void* func_003E2DF0(void* big, char* name);
extern "C" int func_003E2EE0(void* big);
extern "C" void func_003D66C0(void* h, int a);
char* BIG_locateentryz_2AFD40(void* big, char* name, int index, int* offset, int* size) __asm__("BIG_locateentryz");
extern char D_004832C0[];
extern "C" void func_002B0348(sBankList* self, int a, int b, int c);

extern "C" int func_002AFD40(void* selfp, int a, char* name, int b, int c)
{
    sBankList* self = (sBankList*)selfp;
    char buf[0x60];
    char path[0x60];
    int off;
    int sel = 0;
    if (!a)
        sel++;
    self->pairs[self->voiceCount].p[sel] = func_003E1908(name, 0);
    if (self->pairs[self->voiceCount].p[sel] != 0) {
        buf[0] = 0;
        if (a != 0) {
            sprintf(name, D_004832C0, (char*)self + 0x6C);
            char* p = name;
            int len = strlen(name);
            int i;
            for (i = 0; i < len; i++) {
                if (name[i] == 0x7C) {
                    int n = i + 1;
                    p = name + n;
                    strncpy(buf, name, n);
                    buf[n] = 0;
                    break;
                }
            }
            self->voices[self->voiceCount].handle = func_003E2DF0(self->pairs[self->voiceCount].p[sel], p);
            self->voices[self->voiceCount].active = 0;
            if (self->voices[self->voiceCount].handle == 0) {
                func_002523A8(self->pairs[self->voiceCount].p[sel]);
                self->pairs[self->voiceCount].p[sel] = 0;
                return 0;
            }
            func_003D66C0(self->voices[self->voiceCount].handle, b);
        } else {
            buf[1] = 0;
            buf[0] = 0x7C;
        }
        int n = func_003E2EE0(self->pairs[self->voiceCount].p[sel]);
        for (int i = 0; i < n; i++) {
            char* nm = BIG_locateentryz_2AFD40(self->pairs[self->voiceCount].p[sel], 0, i, &off, 0);
            char* e = (char*)self->pairs[self->voiceCount].p[sel] + off;
            if (e != self->voices[self->voiceCount].handle) {
                sprintf(path, D_004A36E0, buf, nm);
                int len = strlen(path);
                path[len - 4] = 0;
                int j = len - 4;
                while (path[j] != 0x5C && j >= 0)
                    j--;
                func_002B0348((sBankList*)self, (int)path, (int)(path + j + 1), (int)e);
            }
        }
    } else {
        sprintf(name, D_004832C0, (char*)self + 0x6C);
        self->voices[self->voiceCount].handle = func_003E1908(name, 0);
        if (self->voices[self->voiceCount].handle == 0)
            return 0;
        self->voices[self->voiceCount].active = 1;
        func_003D66C0(self->voices[self->voiceCount].handle, b);
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0088);
#ifdef SKIP_ASM
extern "C" void* func_002A77F8(void* parser, void* src, int n);
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
extern char D_004A37C8[];
extern char D_004828C0[];
extern char D_004A37D0[];
extern char D_004832D8[];
extern char D_004832E8[];
extern "C" void func_002B0348(sBankList* self, int a, int b, int c);

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
                func_002B0348((sBankList*)self, (int)path, (int)name, 0);
            }
        }
    }
    func_002A7890(parser, 2);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B0290);
#ifdef SKIP_ASM
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

extern "C" void func_002B0320(void* p)
{
    func_002AAE40(*(void**)D_004A37B4, *(int*)((char*)p + 0x4));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B0348);
#ifdef SKIP_ASM
extern "C" int func_002AF960(int a, int b, int c);

extern "C" void func_002B0348(sBankList* self, int a, int b, int c)
{
    self->streams[self->count] = (sBmObj*)func_002AF960(a, b, c);
    if (self->streams[self->count] != 0) {
        self->count++;
        D_004A37B8++;
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B03B8);
#ifdef SKIP_ASM
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
extern char D_004832F8[];
extern "C" int func_002AFA58(void* self, int a1);
extern "C" int func_002B1520(void* sys, int a, int b);
extern "C" int func_002B03B8(const char* name);
extern "C" void func_002AB0D0(void* self, int i, int w);

typedef int (*Fn1_04D8)(void*, int, char*, int, int, int, int, float, int, int);

struct sBmArgs_04D8 {
    int f0;
    int f4;
    char pad8[4];
    unsigned short fC;
};

static inline sBmObj** at_04D8(sBmObj** base, int i)
{
    return base + i;
}

extern "C" int func_002B04D8_impl(sBankList* self, sBmArgs_04D8* a) __asm__("func_002B04D8");

extern "C" int func_002B04D8_impl(sBankList* self, sBmArgs_04D8* a)
{
    int idx = -1;
    int i;
    if (func_002AFA58(self->streams[a->f0], a->f0)) {
        idx = a->f0;
    } else {
        for (i = 0; i < self->count; i++) {
            if (func_002AFA58(self->streams[i], a->f0)) {
                idx = i;
            }
        }
    }
    if (idx >= 0 && func_002B1520(D_004A37B4, self->f0, a->fC)) {
        sBmObj** slot = at_04D8(self->streams, idx);
        int lang = func_002B03B8((char*)*slot + 4);
        char buf[0x100];
        sprintf(buf, D_004832F8, D_004A3590, D_004A37B4 + 0x158 + lang * 0x14, (char*)*slot + 4);
        char* d0 = D_004A37B4;
        sSndVtSlot* vt0 = *(sSndVtSlot**)(d0 + 0x1BC);
        int h = ((int (*)(void*, int, int))vt0[2].fn)(d0 + vt0[2].delta, self->f0, (*slot)->f40);
        char* d; sSndVtSlot* vt;
        int t = (int)func_002AAE78(*(void**)D_004A37B4, self->id);
        int r;
        if (func_002AAE08(*(void**)D_004A37B4, self->id) != 0) {
            if (func_002AB028(*(void**)D_004A37B4, self->id) != 0) {
                d = D_004A37B4;
                vt = *(sSndVtSlot**)(d + 0x1BC);
                r = ((Fn1_04D8)vt[1].fn)(d + vt[1].delta, self->id, buf, a->f4, *(int*)((char*)self + 0x8CC), -1, *(int*)((char*)self + 0x8D0), *(float*)((char*)self + 0x8F4), *(int*)((char*)self + 0x8F8), *(int*)((char*)self + 0x8FC));
                if (r >= 0) {
                    func_002ADCA0(&(**(cBankManager***)D_004A37B4)->sub, t, D_004A37D8[0], (int)self, r, h, 0, 0);
                }
                return r;
            }
            d = D_004A37B4;
            vt = *(sSndVtSlot**)(d + 0x1BC);
            r = ((Fn1_04D8)vt[1].fn)(d + vt[1].delta, self->id, buf, a->f4, *(int*)((char*)self + 0x8CC), -1, *(int*)((char*)self + 0x8D0), *(float*)((char*)self + 0x8F4), *(int*)((char*)self + 0x8F8), *(int*)((char*)self + 0x8FC));
            if (r >= 0) {
                func_002ADCA0(&(**(cBankManager***)D_004A37B4)->sub, 0xC8, D_004A37E0[0], (int)self, r, h, 0, 0);
            }
            return r;
        }
        d = D_004A37B4;
        vt = *(sSndVtSlot**)(d + 0x1BC);
        int w = ((int (*)(void*, int, int, int))vt[3].fn)(d + vt[3].delta, self->f0, h, *(int*)((char*)self + 0x8D0));
        if (w != 0) {
            func_002AB0D0(*(void**)D_004A37B4, self->id, w);
        }
        char* d2 = D_004A37B4;
        sSndVtSlot* vt2 = *(sSndVtSlot**)(d2 + 0x1BC);
        return ((Fn1_04D8)vt2[1].fn)(d2 + vt2[1].delta, self->id, buf, a->f4, *(int*)((char*)self + 0x8CC), *(int*)((char*)self + 0x8C8), *(int*)((char*)self + 0x8D0), *(float*)((char*)self + 0x8F4), *(int*)((char*)self + 0x8F8), *(int*)((char*)self + 0x8FC));
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B07C0);
#ifdef SKIP_ASM
extern "C" int func_002B07C0(void* self)
{
    return func_002AB028(*(void**)D_004A37B4, *(int*)((char*)self + 4));
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
extern const char D_00483308[];

struct sName17_07F8 { char s[17]; };
struct sName18_07F8 { char s[18]; } __attribute__((aligned(2)));
extern const sName17_07F8 D_00483318;
extern const sName18_07F8 D_00483330;
extern const sName17_07F8 D_00483348;
extern const sName17_07F8 D_00483360;
extern const sName18_07F8 D_00483378;

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
    *(const sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &D_004838A0;
    *(void***)(**(char***)self + 0xAB0) = D_00483B48;
    *(const sSndVtbl7**)(**(char***)self + 0x1D4) = &D_004838C0;
    if (inchrg == 0) {
        sSndVtbl4 t1 = D_004838A0;
        *(sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)self + 0x1D8) - 0x1C0;
        int d1 = self - base1;
        t1.e[1].delta = D_004838A0.e[1].delta + d1;
        sSndVtbl7 t2 = D_004838C0;
        *(sSndVtbl7**)(**(char***)self + 0x1D4) = &t2;
        char* base2 = **(char***)self - 0x1C8;
        int d2 = self - base2;
        t2.e[1].delta = D_004838C0.e[1].delta + d2;
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

// PORT: g++ 2.95 virtual-base destruction with stack vtable this-adjust fix-ups, written out by hand.
extern "C" void func_002B0AE8(char* self, int flags)
{
    *(void***)(self + 0x1BC) = D_00483870;
    *(const sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &D_004838A0;
    *(void***)(**(char***)self + 0xAB0) = D_00483B48;
    *(const sSndVtbl7**)(**(char***)self + 0x1D4) = &D_004838C0;
    if (flags == 0) {
        sSndVtbl4 t1 = D_004838A0;
        *(sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)self + 0x1D8) - 0x1C0;
        int d1 = self - base1;
        t1.e[1].delta = D_004838A0.e[1].delta + d1;
        sSndVtbl7 t2 = D_004838C0;
        *(sSndVtbl7**)(**(char***)self + 0x1D4) = &t2;
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
int func_002ADF60_a(void* seed) __asm__("func_002ADF60");
extern "C" int func_003D6840(void* fn, int seed, int buf);
extern "C" int func_003D6C58(int n);
extern "C" void func_003D6C60(int n, void* p);
extern "C" void* func_003D6768();
extern char D_00483390[];
extern char D_004833A8[];

extern "C" void SPCH_Init(void* self)
{
    int buf = func_003D6778(0x5622, 0x10, 1);
    int seed = func_002ADF60_a(*(void**)(**(char***)self + 0x1D8));
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
extern "C" int func_002AB1A0(int, void*);

extern "C" int func_002B1248(int *arg0, void* arg1) {
    return func_002AB1A0(*arg0, arg1);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/bankmonitor", func_002B1268);
#ifdef SKIP_ASM
extern "C" void func_002AB0D0(void* self, int i, int val);
extern "C" int func_002B1248_pp(void* self, void* msg) __asm__("func_002B1248");
struct sVE1268 { short delta; short index; int (*fn)(void*, int, int, int); };

extern "C" int func_002B1268(void* self, void* msg)
{
    char* ent = *(char**)((char*)msg + 0x18);
    if (func_002AB150(*(void**)self, func_002B1220(D_004A37B4, *(int*)ent)) != *(int*)((char*)msg + 0x1C)) {
        func_002ADCA0(&(**(cBankManager***)D_004A37B4)->sub, 0xC8, D_004A37E0[0], *(int*)((char*)msg + 0x18), *(int*)((char*)msg + 0x1C), *(int*)((char*)msg + 0x20), 0, 0);
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
extern "C" int func_002B1268(void* self, void* msg);

extern "C" int func_002B1348(void* self, void* msg)
{
    char* ent = *(char**)((char*)msg + 0x18);
    if (func_002AAE08(*(void**)self, *(int*)(ent + 4)) - 1 > 0) {
        if (func_002AB028(*(void**)self, *(int*)(ent + 4)) != 0) {
            float f = func_002AAE78(*(void**)self, *(int*)(ent + 4));
            func_002ADCA0(&(**(cBankManager***)D_004A37B4)->sub, (int)f, D_004A37D8[0], (int)ent, *(int*)((char*)msg + 0x1C), *(int*)((char*)msg + 0x20), 0, 0);
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

extern "C" void* func_002AFD10(void*);

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1758__FPvi);
#ifdef SKIP_ASM
void func_002B1758(void* self, int a1)
{
    // a1 also stays in $5 as func_002AFD10's second argument
    func_002AFD10_impl((void*)(*(int**)((char*)self + 0x4))[a1], (void*)a1);
}
#endif

INCLUDE_ASM("sound/bankmonitor", func_002B1780);
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1A70);
#ifdef SKIP_ASM
extern "C" void func_002B1A70(void) {
    func_002AAE40(*D_004A37EC, 2);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B1A98);
#ifdef SKIP_ASM
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
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern "C" int func_003D3058(int a, int b);
extern "C" void func_002B4A20(void* self, void* name, int sync);
extern char D_004833F0[];
extern char D_00483408[];
extern char D_00483420[];
extern char D_00483430[];
extern char D_004A3588[];

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
    self->buf24 = operator_new__FUi(0x37000, D_004833F0, 0, 0);
    self->buf28 = operator_new__FUi(func_003D3058(1, 0), D_00483408, 0, 0);
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
extern "C" int func_003D2A68(int id);

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

extern "C" void func_002B2140(int a0) {
    func_003D15C8(0x11000001);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2160);
#ifdef SKIP_ASM
extern "C" int func_003B80A0(int h, int v);

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
extern "C" void func_002B2160(void* self, int v);
extern "C" int func_002B4AA0(void* self, int force);
int func_002B4AE8(void* self);
extern "C" void func_003D2350(int a);
extern "C" int func_003D25F0(int id, char* name, int a2, void* a3, int a4, int a5, void* buf, int size);
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
extern "C" int func_003D11B8(int, void*);

extern "C" int func_002B2550(int a0)
{
    int buf[10];
    func_003D11B8(0x11000001, buf);
    return buf[9];
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B2578);
#ifdef SKIP_ASM
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
extern "C" int func_002B2578(void* self, void* out);

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
// The unit declares func_002B25C8(void*, int); its second arg is really an out pointer.
void func_002B25C8_out(void* self, void* out) __asm__("func_002B25C8");

// Stream info filled through func_002B25C8 (func_003B7C40's out record).
struct sBmStrmInfo {
    int type;
    int value;
    int c;
    int d;
};

extern "C" float func_002B2600(void* self)
{
    sBmStrmInfo info;
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
extern "C" float func_002B26B8(void* self);

// PORT: the unit later declares func_002B2640() as void() for a caller; real signature is float(void*).
float func_002B2640_impl(void* self) __asm__("func_002B2640");
float func_002B2640_impl(void* self)
{
    sBmStrmInfo info;
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
struct sBMSrc {
    char pad0[0x78];
    int a;
    int b;
    int c;
};

extern "C" void func_002B2850(sBMSrc** src, cBankManager*** dst)
{
    (**dst)->sub.p70[(**dst)->sub.cur].f4 = (*src)->a;
    (**dst)->sub.p70[(**dst)->sub.cur].f8 = (*src)->b;
    (**dst)->sub.p70[(**dst)->sub.cur].f0 = (*src)->c;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B28C0);
#ifdef SKIP_ASM
extern void* D_004A37E8;
extern char D_004A3570[];
extern char D_004A37F0[];
extern char D_004A37F8[];
extern char D_004A3800[];
extern char D_004A3808[];
extern char D_00483470[];
extern char D_00483480[];
extern char D_004A3810[];
extern char D_00483490[];
extern char D_004834A0[];
extern char D_004834B0[];
extern char D_004834C0[];
extern char D_004834D0[];
extern char D_004834E0[];
extern char D_004834F0[];
extern char D_00483500[];
extern char D_00483510[];
extern char D_00483520[];
extern char D_00483530[];
extern char D_00483540[];
extern char D_004A3818[];
extern char D_00483550[];
extern char D_004A3820[];
extern char D_00483560[];
extern char D_004A3828[];
extern char D_004A3830[];
extern const char D_00483448[];
extern const char D_00483458[];
extern "C" int func_002A7BF8(void* parser, const char* name);
extern "C" char* func_002A7B08(void* parser);
extern "C" int func_002A80D8(void* parser, const char* key, int* out);
extern "C" int func_002A8070(void* parser, const char* key, float* out);

// One song's configuration (func_002B1A98 ctor, 0xAC bytes).
struct sSongCfg28C0 {
    char name[0x20];            // 0x00
    char file[0x20];            // 0x20
    int numBankData;            // 0x40
    char bankData[1][0x20];     // 0x44
};
struct sBank28C0 {
    int p0;
    char* ents[0x40];
};

struct sLoc28C0 {
    char parser[0x810];
    char buf[0x20];
    int iA;
    int iB;
    int iC;
    float fD;
};

// One row of the per-song grid (sSpeechMon::grid).
static inline int* Row_28C0(int (*g)[5], int i)
{
    return g[i];
}

// The music system's constructor (sound/musicsys.cpp in the July 2003 prototype): reads the song list.
// PORT: g++ 2.95 constructor of a class with virtual bases (stack vtable this-adjust fix-ups written out by hand).
extern "C" char* func_002B28C0(char* self, int inchrg, int a2, int a3, int heap)
{
    if (inchrg) {
        char* vb = self + 0x5448;
        char* vb2 = self + 0x5F20;
        *(char**)(self + 0x5F20) = self + 0x5450;
        *(char**)self = vb2;
        *(char**)(self + 0x5628) = vb;
        func_002ADE88(vb, heap);
        cBankManager_cBankManager(*(void**)(self + 0x5F20), 0, a2, heap);
        cStreamSys_cStreamSys(*(void**)self, 0, a2, a3, heap);
    }
    *(const sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &D_00483928;
    *(void***)(**(char***)self + 0xAB0) = D_00483B48;
    *(const sSndVtbl7**)(**(char***)self + 0x1D4) = &D_00483948;
    if (inchrg == 0) {
        sSndVtbl4 t1 = D_00483928;
        *(sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)self + 0x1D8) - 0x5448;
        int d1 = self - base1;
        t1.e[1].delta = D_00483928.e[1].delta + d1;
        sSndVtbl7 t2 = D_00483948;
        *(sSndVtbl7**)(**(char***)self + 0x1D4) = &t2;
        char* base2 = **(char***)self - 0x5450;
        int d2 = self - base2;
        t2.e[1].delta = D_00483948.e[1].delta + d2;
    }
    *(int*)(self + 0x3E4) = 0;
    *(int*)(self + 0x3E8) = 0;
    *(void***)(self + 0x5440) = D_004838F8;
    *(int*)(self + 0x3EC) = 0;
    *(int*)(self + 0x3F0) = 0;
    *(long*)(self + 0x3F8) = 0;
    *(int*)(self + 0x408) = 0;
    *(int*)(self + 0x418) = 0;
    *(int*)(self + 0x5438) = 0;
    *(int*)(self + 0x543C) = 0;
    D_004A37EC = (void***)self;
    *(char**)(self + 0x5434) = new (D_00483448, 0, 0) char[0x6400];
    sBank28C0* sv = (sBank28C0*)self;
    int i = 0;
    do {
        int* e = Row_28C0(((sSpeechMon*)self)->grid, i);
        for (int j = 4; j >= 0; j--)
            e[j] = 0;
        i++;
    } while (i < 0x40);
    {
        int* e = (int*)(self + 0x920);
        for (int j = 4; j >= 0; j--)
            e[j] = 0;
    }
    for (int p = 0; p < 0x1900; p += 0x64) {
        self[p + 0x934] = D_004A35A8[0];
        self[p + 0x2234] = D_004A35A8[0];
        self[p + 0x3B34] = D_004A35A8[0];
    }
    sLoc28C0 L;
    func_002A77F8(L.parser, D_004A37E8, 0x100);
    *(int*)(L.parser + 8) = *(int*)(L.parser + 4);
    if (func_002A7BF8(L.parser, D_004A3570) != 0) {
        while (func_002A7F90(L.parser) == 0) {
            func_002A7DA0(L.parser);
            func_002A7FF8(L.parser, D_004828C0, self + 0x104);
        }
    }
    *(int*)(L.parser + 8) = *(int*)(L.parser + 4);
    *(int*)(self + 0x3E4) = 0;
    *(int*)(self + 0x3EC) = 0;
    while (*(int*)(self + 0x3E4) < 0x40) {
        char* tok = func_002A7B08(L.parser);
        if (tok == 0)
            break;
        if (func_0041AA88(tok, D_004A3570) == 0)
            continue;
        // The song's bit is built in a variable: the target keeps its li 1 in the loop while the
        // other constants (100) are hoisted.
        long bit = 1;
        bit <<= *(int*)(self + 0x3E4);
        *(long*)(self + 0x3F8) |= bit;
        strcpy(self + (*(int*)(self + 0x3E4) * 0xB + 0x124), tok);
        sv->ents[*(int*)(self + 0x3E4)] = (char*)func_002B1A98(cMemMan_alloc(0xAC, D_00483458, 0, 0));
        while (func_002A7F90(L.parser) == 0) {
            char* key = func_002A7DA0(L.parser);
            if (func_0041AA88(key, D_004A37F0) == 0) {
                func_002A7FF8(L.parser, D_004A37F0, self + (*(int*)(self + 0x3E4) * 100 + 0x934));
            } else if (func_0041AA88(key, D_004A37F8) == 0) {
                func_002A7FF8(L.parser, D_004A37F8, self + (*(int*)(self + 0x3E4) * 100 + 0x2234));
            } else if (func_0041AA88(key, D_004A3800) == 0) {
                func_002A7FF8(L.parser, D_004A3800, self + (*(int*)(self + 0x3E4) * 100 + 0x3B34));
            } else if (func_0041AA88(key, D_004A3808) == 0) {
                func_002A80D8(L.parser, D_004A3808, &L.iA);
                if (L.iA == 1)
                    *(int*)(self + 0x3EC) += 1;
            } else if (func_0041AA88(key, D_00483470) == 0) {
                func_002A80D8(L.parser, D_00483470, &L.iB);
                if (L.iB < 5)
                    ((sSpeechMon*)self)->grid[((sSpeechMon*)self)->count][L.iB] = 1;
            } else if (func_0041AA88(key, D_00483480) == 0) {
                func_002A7FF8(L.parser, D_00483480, L.buf);
                strcpy(sv->ents[*(int*)(self + 0x3E4)], L.buf);
            } else if (func_0041AA88(key, D_004A3810) == 0) {
                func_002A7FF8(L.parser, D_004A3810, L.buf);
                strcpy(sv->ents[*(int*)(self + 0x3E4)] + 0x20, L.buf);
            } else if (func_0041AA88(key, D_00483490) == 0) {
                func_002A7FF8(L.parser, D_00483490, L.buf);
                strcpy(((sSongCfg28C0*)sv->ents[*(int*)(self + 0x3E4)])->bankData[((sSongCfg28C0*)sv->ents[*(int*)(self + 0x3E4)])->numBankData], L.buf);
                ((sSongCfg28C0*)sv->ents[*(int*)(self + 0x3E4)])->numBankData++;
            } else if (func_0041AA88(key, D_004834A0) == 0) {
                func_002A80D8(L.parser, D_004834A0, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x64) = L.iC;
            } else if (func_0041AA88(key, D_004834B0) == 0) {
                func_002A80D8(L.parser, D_004834B0, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x68) = L.iC;
            } else if (func_0041AA88(key, D_004834C0) == 0) {
                func_002A80D8(L.parser, D_004834C0, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x6C) = L.iC;
            } else if (func_0041AA88(key, D_004834D0) == 0) {
                func_002A80D8(L.parser, D_004834D0, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x70) = L.iC;
            } else if (func_0041AA88(key, D_004834E0) == 0) {
                func_002A80D8(L.parser, D_004834E0, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x74) = L.iC;
            } else if (func_0041AA88(key, D_004834F0) == 0) {
                func_002A80D8(L.parser, D_004834F0, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x78) = L.iC;
            } else if (func_0041AA88(key, D_00483500) == 0) {
                func_002A80D8(L.parser, D_00483500, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x7C) = L.iC;
            } else if (func_0041AA88(key, D_00483510) == 0) {
                func_002A80D8(L.parser, D_00483510, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x80) = L.iC;
            } else if (func_0041AA88(key, D_00483520) == 0) {
                func_002A80D8(L.parser, D_00483520, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x84) = L.iC;
            } else if (func_0041AA88(key, D_00483530) == 0) {
                func_002A80D8(L.parser, D_00483530, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x88) = L.iC;
            } else if (func_0041AA88(key, D_00483540) == 0) {
                func_002A80D8(L.parser, D_00483540, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x8C) = L.iC;
            } else if (func_0041AA88(key, D_004A3818) == 0) {
                func_002A8070(L.parser, D_004A3818, &L.fD);
                *(float*)(sv->ents[*(int*)(self + 0x3E4)] + 0x90) = L.fD;
            } else if (func_0041AA88(key, D_00483550) == 0) {
                func_002A80D8(L.parser, D_00483550, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x98) = L.iC;
            } else if (func_0041AA88(key, D_004A3820) == 0) {
                func_002A80D8(L.parser, D_004A3820, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x9C) = L.iC;
            } else if (func_0041AA88(key, D_00483560) == 0) {
                func_002A80D8(L.parser, D_00483560, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0x94) = L.iC;
            } else if (func_0041AA88(key, D_004A3828) == 0) {
                func_002A80D8(L.parser, D_004A3828, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0xA0) = L.iC;
            } else if (func_0041AA88(key, D_004A3830) == 0) {
                func_002A80D8(L.parser, D_004A3830, &L.iC);
                *(int*)(sv->ents[*(int*)(self + 0x3E4)] + 0xA4) = L.iC;
            }
        }
        *(int*)(self + 0x3E4) += 1;
    }
    func_002A7890(L.parser, 2);
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B3398);
#ifdef SKIP_ASM

struct sBmonVcall3398 { short delta; short index; void (*fn)(void*, int); };

// PORT: g++ 2.95 virtual-base destruction with stack vtable this-adjust fix-ups, written out by hand.
extern "C" void func_002B3398(char* self, int flags)
{
    *(void***)(self + 0x5440) = D_004838F8;
    *(const sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &D_00483928;
    *(void***)(**(char***)self + 0xAB0) = D_00483B48;
    *(const sSndVtbl7**)(**(char***)self + 0x1D4) = &D_00483948;
    if (flags == 0) {
        sSndVtbl4 t1 = D_00483928;
        *(sSndVtbl4**)(*(char**)(**(char***)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)self + 0x1D8) - 0x5448;
        int d1 = self - base1;
        t1.e[1].delta = D_00483928.e[1].delta + d1;
        sSndVtbl7 t2 = D_00483948;
        *(sSndVtbl7**)(**(char***)self + 0x1D4) = &t2;
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

extern "C" void func_002B35A0(cBankManager*** self, int a1, int a2, int a3, int a4)
{
    cBankManager* t = **self;
    sSndPlayer* s = &t->sub;
    t->sub.cur++;
    s->ch[t->sub.cur] = s->def;
    t->sub.tgt[t->sub.cur] = 0;
    s->p34[t->sub.cur] = 0;
    s->vals[t->sub.cur] = s->ch[t->sub.cur].vol;
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
    cBankManager* t2 = **self;
    t2->sub.p3C[t2->sub.cur] = a3;
    func_002B3838(self, a1, a2, a4);
    cBankManager* t3 = **self;
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
    sSpeechMon* self = (sSpeechMon*)self_;
    cBankManager* t;
    sSndPlayer* sub;
    float* pf;
    char c;
    int arg;
    int name;
    int base;
    func_002B3AC0(self);
    t = *self->pp;
    sub = &t->sub;
    c = sub->vals[sub->cur];
    pf = (float*)sub->p3C[sub->cur];
    if (pf != 0) {
        float f = (float)c * *pf;
        f = bmMax3838(bmMin3838(f, 127.0f), 0.0f);
        sub->vals[t->sub.cur] = (char)(int)f;
        {
            signed char* d = &((sSndOptsRec*)(t->sub.cur * 24 + (int)sub->ch))->vol;
            unsigned char r;
            if (sub->vals[sub->cur] > 0x7E || sub->vals[sub->cur] >= 0) {
                r = sub->vals[sub->cur] < 0x7F ? (unsigned char)sub->vals[sub->cur] : 0x7F;
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
        self->current = idx;
        name = a1;
        base = (int)&(*self->pp)->sub;
        *(int*)((char*)self + 0x408) = (int)func_002B1B98((int)self->obj, name, self->arr[idx], base, c, (int)pf, a2, a3);
    } else {
        int k = self->current;
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
extern "C" void func_0028BCE8(void* self, int i);
extern "C" void func_002B3A98(void* self);

extern "C" void func_002B3AC0(void* self)
{
    char* s = (char*)self;
    func_002ADDE0(&(**(cBankManager***)s)->sub, D_004A3838[0]);
    func_002ADDE0(&(**(cBankManager***)s)->sub, D_004A3840[0]);
    func_002ADDE0(&(**(cBankManager***)s)->sub, D_004A3848[0]);
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

extern "C" void func_002B3C28(void* self, int a1)
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
extern void func_002B2140(int);

extern "C" void func_002B3C60(void *arg0) {
    int temp_4;

    if ((*(int *)((char*)(arg0) + (0x418))) != 0) {
        temp_4 = (*(int *)((char*)(arg0) + (0x408)));
        if (temp_4 != 0) {
            func_002B2140(temp_4);
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
extern "C" void func_002B3D80(void* self, signed char target, float duration)
{
    signed char cur;
    void* voice = *(void**)((char*)self + 0x408);
    if (voice != 0 && target != (cur = *(signed char*)((char*)voice + 0x40))) {
        int steps = (target - cur) / 25;
        *(int*)((char*)self + 0x414) = target;
        *(float*)((char*)self + 0x410) = (float)cur;
        *(float*)((char*)self + 0x40C) = (float)steps / duration;
        func_002ADCA0(&(**(cBankManager***)self)->sub, 0x28, D_004A3850[0], 0, 0, 0, 0, 0);
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
extern "C" char* func_0041AD80(const char* a, const char* b);

extern "C" void func_002B3EE8(sSpeechMon* self, const char* name)
{
    if (self->selected < 64) {
        for (int i = 0; i < self->count; i++) {
            if (func_0041AD80(self->names[i], name) != 0) {
                self->mask |= (ulong)1 << i;
                self->selected++;
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
extern "C" void func_002B3FE8(sSpeechMon* self, int idx)
{
    if (self->selected < 64) {
        self->selected++;
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
extern "C" void func_002B3EB0(void* self);
extern "C" void func_002B3FE8(sSpeechMon* self, int idx);
void func_002B4060(void* self);

extern "C" void func_002B4070(void* self, ulong mask)
{
    func_002B3EB0(self);
    for (int i = 0; i < *(int*)((char*)self + 0x3EC); i++) {
        int bit = (mask >> i) & 1;
        if (bit) {
            func_002B3FE8((sSpeechMon*)self, i);
        }
    }
    func_002B4060(self);
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B40F0);
#ifdef SKIP_ASM
extern "C" sBankEntry64* func_002B40F0(sSpeechMon* self, int i)
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
extern "C" sBankEntry64* func_002B4120(sSpeechMon* self, int i)
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
extern "C" sBankEntry64* func_002B4150(sSpeechMon* self, int i)
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
extern "C" void func_002B41E8(sSpeechMon* self, int filter, int kind)
{
    if (filter == 0 || self->totals[kind] == 0) {
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
        } while (!((self->mask >> self->current) & 1) || self->grid[self->current][kind] == 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B42B8);
#ifdef SKIP_ASM
extern "C" void func_002B42B8(sSpeechMon* self, int filter, int kind)
{
    if (filter == 0 || self->totals[kind] == 0) {
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
        } while (!((self->mask >> self->current) & 1) || self->grid[self->current][kind] == 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4388);
#ifdef SKIP_ASM
extern "C" int func_002B4620(void*);

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
extern "C" int func_002B24C0(void* p);
extern "C" void func_0028BD10(void* self, int i, void* id, int a3);

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
extern "C" void func_002B4470(void* self)
{
    void* p = *(void**)((char*)self + 0x408);
    if (p != 0 && *(int*)((char*)p + 0x4C) == 0) {
        *(int*)((char*)p + 0x4C) = 1;
        func_002ADCA0(&(**(cBankManager***)self)->sub, 0, D_004A3838[0], 0, 0, 0, 0, 0);
    }
}
#endif
//100%
INCLUDE_ASM("sound/bankmonitor", func_002B44D8);
#ifdef SKIP_ASM
extern "C" void func_002B4708(void* self);

extern "C" void func_002B44D8(void* self)
{
    if (*(void**)((char*)self + 0x408) != 0) {
        func_002ADDE0(&(**(cBankManager***)self)->sub, D_004A3838[0]);
        func_002ADDE0(&(**(cBankManager***)self)->sub, D_004A3840[0]);
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
extern "C" int func_002B2778(void* ent);
extern "C" int func_002B2500(void* ent);

extern "C" void func_002B4568(void* self, void* ent)
{
    if (*(void**)((char*)self + 0x408) != 0) {
        float a = func_002B2690(ent);
        float b = func_002B2718(ent);
        int c = func_002B2778(ent) + 1;
        int d = func_002B2500(ent);
        func_002ADCA0(&(**(cBankManager***)self)->sub, (int)b, D_004A3840[0], *(int*)((char*)self + 0x408), d, c, (int)a, 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/bankmonitor", func_002B4620);
#ifdef SKIP_ASM
extern "C" int func_003D2DF8(int cmd, int a, int b);

struct sBmStream4620 {
    int state;      // 0x0
    int handle;     // 0x4
    char pad[0x60 - 8];
};

static inline int func_002B4620_ready(sBmStream4620* e)
{
    return e->state == 1;
}

int func_002B4620(void* self);

int func_002B4620(void* self)
{
    if (*(char**)((char*)self + 0x408) == 0) return 0;
    *(int*)(*(char**)((char*)self + 0x408) + 0x4C) = 1;
    int r = 0;
    char* m = *(char**)((char*)self + 0x408);
    int st = *(int*)(m + 0x38);
    if (st == 1) {
        // PORT: pointer arithmetic through int
        sBmStream4620* e = (sBmStream4620*)(*(int*)(m + 0x34) * 0x60 + *(int*)(**(char***)self + 0xACC));
        if (func_002B4620_ready(e)) {
            func_003D2DF8(0x11000002, 0, e->handle);
            *(int*)(*(char**)((char*)self + 0x408) + 0x38) = 2;
            r = 1;
        }
    } else if (st == 2) {
        r = 1;
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
extern "C" int func_003DFAF0(void* f);
extern "C" int ASYNCFILE_release(void* f, int a, int b);
extern "C" void* func_003DF748(void* name, void* buf, int size);
extern "C" int func_003E1B68(void* name, void* buf, int size);

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

