#include "common.h"

//100%
INCLUDE_ASM("replay/frameptr", cReplayFramePtr_initBlock);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_00481730[];

// same body as func_0026E950 (setBlock), inlined here
static inline void cReplayFramePtr_setBlockInl(void* self, char* buf, int size)
{
    *(char**)((char*)self + 0x4) = buf;
    *(char**)((char*)self + 0x8) = buf + size;
    *(char**)((char*)self + 0xc) = buf;
    *(int*)((char*)self + 0x10) = size;
}

extern "C" void cReplayFramePtr_initBlock(void* self, unsigned int size)
{
    cReplayFramePtr_setBlockInl(self, (char*)operator_new_tag(size, D_00481730, 0, 0), 0);
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026E950);
#ifdef SKIP_ASM
extern "C" void func_0026E950(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x4) = a1;
    *(int*)((char*)self + 0x8) = a1 + a2;
    *(int*)((char*)self + 0xc) = a1;
    *(int*)((char*)self + 0x10) = a2;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026E968);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

extern "C" void func_0026E968(void* self)
{
    void* p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        cMemMan_free(p);
    }
    cReplayFramePtr_setBlockInl(self, 0, 0);
}
#endif

struct cReplayFramePtr {
    char pad_0x00[0x4];
    int field_0x4;
    char pad_0x08[0x4];
    int field_0xC;
};

//100%
INCLUDE_ASM("replay/frameptr", cReplayFramePtr_readRewind__FP15cReplayFramePtr);
#ifdef SKIP_ASM
void cReplayFramePtr_readRewind(cReplayFramePtr* self)
{
    self->field_0xC = self->field_0x4;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026E9C0__FPv);
#ifdef SKIP_ASM
int func_0026E9C0(void* self)
{
    int t0 = *(int*)((char*)self + 0x4);
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x8) = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026E9D0);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int size);

extern "C" void func_0026E9D0(void* self, void* src, int n)
{
    func_003E6574(*(char**)((char*)self + 0x8), src, n);
    *(char**)((char*)self + 0x8) += n;
    *(int*)((char*)self + 0x10) += n;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EA20);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int size);

extern "C" void func_0026EA20(void* self, void* dst, int n)
{
    func_003E6574(dst, *(char**)((char*)self + 0xC), n);
    *(char**)((char*)self + 0xC) += n;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EA68);
#ifdef SKIP_ASM
class cStream26EA68 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

// Peek the next frame header's id without consuming it.
extern "C" short func_0026EA68(cStream26EA68* self)
{
    struct {
        short id;
        short size;
    } hdr;
    int pos = *(int*)((char*)self + 0xC);
    self->v02(&hdr, 4);
    *(int*)((char*)self + 0xC) = pos;
    return hdr.id;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EAB8);
#ifdef SKIP_ASM
extern "C" int func_002C85A0(void* src, int a, int dst);

extern "C" int func_0026EAB8(cReplayFramePtr* self, char** pp, void* src)
{
    struct {
        int tag;
        int size;
    } hdr;
    func_003E6574(&hdr.tag, src, 4);
    func_003E6574(&hdr.size, *pp, 4);
    *pp += 4;
    int n = func_002C85A0(*pp, 0, self->field_0x4);
    *pp += hdr.size;
    *(int*)((char*)self + 0x8) = self->field_0x4 + n;
    cReplayFramePtr_readRewind(self);
    return 1;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EB48);
#ifdef SKIP_ASM
extern char* D_004A28A8;

struct sRefSet_EB48 {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};

struct sRefWorld_EB48 {
    char pad_0x0[0x8];
    sRefSet_EB48** sets;    // 0x8
};

extern sRefWorld_EB48** D_004A47B8;

extern "C" void* func_003512C0(void* table, unsigned int id);

class cStream_EB48 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

static inline void* refToPtr_EB48(unsigned int p)
{
    return (void*)(p << 2);
}

static inline void* lookup_EB48(unsigned int id)
{
    sRefSet_EB48* set = (*D_004A47B8)->sets[id & 0xFF];
    if (set == 0) {
        return 0;
    }
    unsigned int p = set->refs[id >> 8] >> 8;
    if (p == 0) {
        return 0;
    }
    return refToPtr_EB48(p);
}

struct sRefH_EB48 {
    unsigned int id;
    sRefH_EB48() : id(0xFFFFFFFF) {}
};

extern "C" void* func_0026EB48(cStream_EB48* stream)
{
    void* r = 0;
    sRefH_EB48 h;
    stream->v02(&h, 4);
    if (~h.id != 0) {
        r = func_003512C0(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x88), h.id);
        if (r == 0) {
            void* t = lookup_EB48(h.id);
            r = t;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EC08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sRefSet_EC08 {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};

struct sRefWorld_EC08 {
    char pad_0x0[0x8];
    sRefSet_EC08** sets;    // 0x8
};

// asm-label view: func_0026EB48 declares D_004A47B8 with its own struct type in this unit
extern sRefWorld_EC08** D_004A47B8_EC08 __asm__("D_004A47B8");

class cStream_EC08 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

struct sRec_EC08 {
    unsigned int id;
    unsigned short type;
    sRec_EC08() : id(0xFFFFFFFF) {}
};

struct sNode_EC08 {
    char pad_0x0[0x8];
    unsigned int flags;     // 0x8
    void* owner;            // 0xC
};

static inline void* refToPtr_EC08(unsigned int p)
{
    return (void*)(p << 2);
}

static inline void* lookup_EC08(unsigned int id)
{
    sRefSet_EC08* set = (*D_004A47B8_EC08)->sets[id & 0xFF];
    if (set == 0) {
        return 0;
    }
    unsigned int p = set->refs[id >> 8] >> 8;
    if (p == 0) {
        return 0;
    }
    return refToPtr_EC08(p);
}

extern "C" void* func_0026EC08(cStream_EC08* stream, void* owner)
{
    sNode_EC08* r = 0;
    sRec_EC08 rec;
    stream->v02(&rec, 8);
    if (~rec.id != 0) {
        void* t = lookup_EC08(rec.id);
        r = (sNode_EC08*)t;
        r->owner = owner;
        r->flags = (r->flags & 0xFFFF0300) | (rec.type & 0xFCFF);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026ECD8);
#ifdef SKIP_ASM
struct sFpSerVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sFpSerObj {
    sFpSerVEntry* vt;
};

extern "C" void func_0026ECD8(sFpSerObj* out, void* obj)
{
    unsigned int id = 0xFFFFFFFF;
    if (obj != 0) {
        id = *(unsigned int*)((char*)obj + 0x78);
    }
    out->vt[1].fn((char*)out + out->vt[1].delta, &id, 4);
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026ED28);
#ifdef SKIP_ASM
extern "C" void func_0026ED28(sFpSerObj* out, void* obj)
{
    struct {
        unsigned int id;
        unsigned short type;
    } rec;
    rec.id = 0xFFFFFFFF;
    void* p = *(void**)((char*)obj + 0x18);
    if (p != 0) {
        rec.id = *(unsigned int*)((char*)p + 0x78);
        rec.type = *(unsigned short*)((char*)p + 0x8);
    } else {
        rec.type = 0;
    }
    out->vt[1].fn((char*)out + out->vt[1].delta, &rec, 8);
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026ED88__FPv);
#ifdef SKIP_ASM
void func_0026ED88(void* self)
{
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", cReplayFramePtr_getFrameBlock__Fv);
#ifdef SKIP_ASM
void cReplayFramePtr_getFrameBlock()
{
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026ED98);
#ifdef SKIP_ASM
extern "C" void func_0026EDD8(void* self);

extern "C" void func_0026ED98(void* self)
{
    *(int*)((char*)self + 0x630) = (*(int*)((char*)self + 0x630) + 1) % 9;
    func_0026EDD8(self);
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EDD8);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern int D_00445438[];
extern "C" void func_00161FA0(void* self, int mode);

struct sRiderList_EDD8 {
    int count;
    char* riders[1];
};

extern "C" void func_0026EDD8(void* self)
{
    sRiderList_EDD8* list = *(sRiderList_EDD8**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
    int n = list->count;
    int i;
    for (i = 0; i < n; i++) {
        func_00161FA0(*(void**)(list->riders[i] + 0xA8), D_00445438[*(int*)((char*)self + 0x630)]);
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EE68);
#ifdef SKIP_ASM
void* func_0016D1D8(void* p);
extern void* D_004C5830[];
extern "C" void func_0026EDD8(void* self);

extern "C" void func_0026EE68(void* self)
{
    func_0016D1D8(D_004C5830);
    func_0026EDD8(self);
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EEA0);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern void* D_004C5830[];
void cCameraTriggerMan_setInGameTriggers(void* self);
extern "C" void func_0015DFD8(void* self, int mode);
extern "C" void func_00161F50(void* cam);

struct sRiderList_EEA0 {
    int count;
    char* riders[1];
};

extern "C" void func_0026EEA0(void* self)
{
    cCameraTriggerMan_setInGameTriggers(D_004C5830);
    sRiderList_EEA0* list = *(sRiderList_EEA0**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
    int n = list->count;
    int i;
    for (i = 0; i < n; i++) {
        char* r = list->riders[i];
        void* cam = *(void**)(r + 0xA8);
        func_0015DFD8(r, 2);
        func_00161F50(cam);
    }
    *(int*)((char*)self + 0x630) = 0;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EF30);
#ifdef SKIP_ASM
extern "C" void func_0026EF30(void* self)
{
    func_0016D1D8(D_004C5830);
    *(int*)((char*)self + 0x634) = (*(int*)((char*)self + 0x634) + 1) % 9;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EF80);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern void* D_004C5830[];
void cCameraTriggerMan_setInGameTriggers(void* self);
extern "C" void func_0015DFD8(void* self, int mode);

extern "C" void func_0026EF80()
{
    cCameraTriggerMan_setInGameTriggers(D_004C5830);
    func_0015DFD8(*(void**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0x84) + 0x4), 2);
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026EFB8);
#ifdef SKIP_ASM
extern "C" void* func_0026D5E8(void* self);
void* func_0026E5A8(void* self);
extern "C" void* func_00272288(void* self);
void func_0026F4A0(void* self, int state);

extern "C" void* func_0026EFB8(void* self)
{
    char* p = (char*)self + 0x2C;
    for (int i = 15; i != -1; i--, p += 0x38) {
        func_0026D5E8(p);
    }
    char* q = (char*)self + 0x494;
    func_0026E5A8((char*)self + 0x3B0);
    func_0026E5A8((char*)self + 0x3BC);
    for (int i = 1; i != -1; i--, q += 0xB4) {
        func_00272288(q);
    }
    func_0026F4A0(self, 15);
    for (int i = 1; i >= 0; i--) {
        int* a = (int*)(0x48C + (char*)self);
        a[i] = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F088);
#ifdef SKIP_ASM
struct sFpOwner26F428;
struct cReplayFramePtr_F980;
extern "C" void func_0026F428(sFpOwner26F428* self);
extern "C" void func_0026F980(cReplayFramePtr_F980* self);
void func_0026F498(void* self);
void operator_delete(int* ptr);

struct sFpVEntryF088 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sFpNodeF088 {
    sFpVEntryF088* vtable;  // 0x0
    char pad_0x4[0x34];
};

struct sFpKeyF088 {
    char pad_0x0[0xB4];
    ~sFpKeyF088() {}
};

extern "C" void func_0026F088(int* self, int flags)
{
    char* s = (char*)self;
    int ok = 0;
    int v = *self;
    if (v != 0) {
        ok = v;
        ok = ok < 10;
    }
    if (ok) {
        func_0026F980((cReplayFramePtr_F980*)self);
    }
    func_0026F498(self);
    func_0026F428((sFpOwner26F428*)self);
    if (s + 0x494 != 0) {
        char* p = s + 0x494 + 0x168;
        while (s + 0x494 != p) {
            p -= 0xB4;
            ((sFpKeyF088*)p)->~sFpKeyF088();
        }
    }
    if (s + 0x2C != 0) {
        char* p = s + 0x2C + 0x380;
        while (s + 0x2C != p) {
            p -= 0x38;
            sFpVEntryF088* vt = ((sFpNodeF088*)p)->vtable;
            vt[7].fn(p + vt[7].delta, 0);
        }
    }
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F180);
#ifdef SKIP_ASM
struct sReplayBlock_F180 {
    char data[0x38];
};

struct cReplayFramePtr_F180 {
    char pad_0x0[0x8];
    int numBlocks;          // 0x8
    char pad_0xc[0x8];
    int blockSize;          // 0x14
    int field_0x18;         // 0x18
    char pad_0x1c[0x10];
    sReplayBlock_F180 blocks[1];    // 0x2C
};

extern "C" void cReplayFramePtr_initBlock(void* self, unsigned int size);
extern "C" void func_0026F228(void* self);
void func_0026F4A0(void* self, int state);

extern "C" void func_0026F180(cReplayFramePtr_F180* self)
{
    self->blockSize = 0x14000;
    self->numBlocks = 0xC9800 / self->blockSize;
    self->field_0x18 = 0;
    int i = 0;
    do {
        cReplayFramePtr_initBlock(&self->blocks[i], self->blockSize);
        i++;
    } while (i < self->numBlocks);
    func_0026F4A0(self, 10);
    func_0026F228(self);
}
#endif

INCLUDE_ASM("replay/frameptr", func_0026F228);

//100%
INCLUDE_ASM("replay/frameptr", func_0026F428);
#ifdef SKIP_ASM
void func_0026E5C0(void* self);

struct sFpEntry26F428 {
    char pad[0x38];
};

struct sFpOwner26F428 {
    char pad_0x00[0x8];
    int count;
    char pad_0x0C[0x20];
    sFpEntry26F428 entries[1];
};

extern "C" void func_0026F428(sFpOwner26F428* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        func_0026E968(&self->entries[i]);
    }
    func_0026E5C0((char*)self + 0x3B0);
    func_0026E5C0((char*)self + 0x3BC);
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F498__FPv);
#ifdef SKIP_ASM
void func_0026F498(void* self)
{
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F4A0__FPvi);
#ifdef SKIP_ASM
void func_0026F4A0(void* self, int val)
{
    *(int*)((char*)self + 0x0) = val;
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F4A8);
#ifdef SKIP_ASM
void func_0026F4A0(void* self, int state);
struct sFrameDesc_F4A8 {
    short type;
    char a;
    char b;
};
// PORT: local views of callees declared with other parameter types later in the unit
extern "C" void* func_0026D760_F4A8(void* self, sFrameDesc_F4A8* desc) __asm__("func_0026D760");
// PORT: func_0026D740 is mangled with one parameter (__FPv) but is called here
// with (self, block); bind the 2-arg form to the symbol.
void func_0026D740_F4A8(void* self, void* block) __asm__("func_0026D740__FPv");
extern "C" void func_0026F8A0_F4A8(void* self, int a1, int a2, int a3) __asm__("func_0026F8A0");
extern "C" void func_0026FB88(void* self, int a1);
extern "C" void func_0026FE50(char* self);
extern "C" void func_00270538(void* self);
extern "C" void func_00270628(void* self);
extern "C" void func_00270670(void* self);
extern "C" void func_00270E18(void* self);
int func_00320C48(void* obj, int id);
extern char* D_004A28A8;
struct sApp_F4A8 {
    char pad0[0xB0];
    void* players[4];       // 0xB0
};
// PORT: typed view of the app global
extern sApp_F4A8* D_004A28A8_F4A8 __asm__("D_004A28A8");

struct sReplay_F4A8 {
    int state;              // 0x0
    char pad4[0x14];
    int keyRate;            // 0x18
    char pad1C[0x4];
    int f20;                // 0x20
    char pad24[0x4];
    int player;             // 0x28
    char pad2C[0x39C];
    int frame;              // 0x3C8
    int seconds;            // 0x3CC
    void* block;            // 0x3D0
    int f3D4;               // 0x3D4
    char pad3D8[0xAC];
    int last;               // 0x484
    char pad488[0x17C];
    int f604;               // 0x604
    int f608;               // 0x608
    int f60C;               // 0x60C
    int paused;             // 0x610
    int timer;              // 0x614
    int f618;               // 0x618
    int f61C;               // 0x61C
    int f620;               // 0x620
    int f624;               // 0x624
};

static inline void addFrame_F4A8(sReplay_F4A8* self, short type)
{
    sFrameDesc_F4A8 desc;
    desc.type = type;
    desc.a = 0;
    desc.b = 0;
    func_0026D740_F4A8(self, func_0026D760_F4A8(self, &desc));
}

// Replay recorder/player: per-frame update of the replay state machine.
extern "C" void func_0026F4A8(sReplay_F4A8* self)
{
    int s = self->state;
    bool ok = !(s == 14 || s == 15);
    if (!ok)
        return;
    if (self->timer > 0)
        self->timer--;
    self->f604 = 0;
    if (self->f618 == 7)
        func_0026F4A0(self, 3);
    if (!(self->state == 3 || self->state == 4))
        self->f20 = 0;
    switch (self->state) {
    case 11:
        func_0026F4A0(self, 12);
        return;
    case 2:
        if (self->last < self->frame - 1) {
            func_0026FB88(self, 0);
            func_0026FE50((char*)self);
            return;
        }
        func_00270670(self);
    case 0:
    case 12:
        func_0026F4A0(self, 0);
        self->block = 0;
        if (self->f60C != 0) {
            if (self->f608 != 0)
                return;
            func_00270628(self);
            func_00270E18(self);
            func_00270538(self);
            addFrame_F4A8(self, 1);
            func_0026F4A0(self, 13);
            return;
        }
        if (self->f624 != 0) {
            func_0026F8A0_F4A8(self, self->f3D4, 1, 0);
            func_0026F4A0(self, 2);
            self->f624 = 0;
            self->f620 = 1;
            return;
        }
        if (self->paused == 0 && self->frame % 60 == 0) {
            func_00270538(self);
            if (self->frame == 0 || (self->keyRate != 0 && self->frame % self->keyRate == 0))
                addFrame_F4A8(self, 1);
            else
                addFrame_F4A8(self, 0);
        }
        if (self->paused == 0)
            self->seconds++;
        self->frame++;
        return;
    case 3: {
        void* o = D_004A28A8_F4A8->players[self->player];
        if (o != 0 && func_00320C48(o, 0x6B))
            func_0026FB88(self, 0);
        func_0026FE50((char*)self);
        return;
    }
    case 9:
        func_0026F8A0_F4A8(self, 0, 0, 1);
        func_0026F4A0(self, 1);
        self->f61C = 1;
        return;
    case 8:
        func_0026F8A0_F4A8(self, 0, 0, 0);
    case 4:
    case 5:
    case 6:
    case 7:
        func_0026F4A0(self, 3);
        return;
    default:
        func_0026FE50((char*)self);
    case 10:
    case 13:
        return;
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F7B8);
#ifdef SKIP_ASM
void func_0026F4A0(void* self, int state);

extern "C" void func_0026F7B8(int* self)
{
    int s = *self;
    bool ok = !(s == 14 || s == 15);
    if (ok) {
        if (s == 10) {
            func_0026F4A0(self, 11);
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F7F8);
#ifdef SKIP_ASM
struct sFrameDesc26F7F8 {
    short type;
    char a;
    char b;
};

extern "C" void* func_0026D760(void* self, sFrameDesc26F7F8* desc);
// PORT: func_0026D740 is mangled with one parameter (__FPv) but is called here
// with (self, block); bind the 2-arg form to the symbol.
void func_0026D740_2(void* self, void* block) __asm__("func_0026D740__FPv");

extern "C" void func_0026F7F8(void* self)
{
    if (*(void**)((char*)self + 0x3D0) == 0) {
        sFrameDesc26F7F8 desc;
        desc.type = 1;
        desc.a = 0;
        desc.b = 0;
        void* block = func_0026D760(self, &desc);
        *(void**)((char*)self + 0x3D0) = block;
        func_0026D740_2(self, block);
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F850);
#ifdef SKIP_ASM
extern "C" void func_0026DB88(void* self, void* p);
extern "C" void func_00270238(void* self, void* p);

extern "C" void func_0026F850(void* self)
{
    void* p = *(void**)((char*)self + 0x3D0);
    if (p != 0) {
        func_0026DB88(self, p);
        func_00270238(self, *(void**)((char*)self + 0x3D0));
        *(void**)((char*)self + 0x3D0) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026F898__FPvi);
#ifdef SKIP_ASM
void func_0026F898(void* self, int val)
{
    *(int*)((char*)self + 0x28) = val;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/frameptr", func_0026F8A0);
#ifdef SKIP_ASM
extern "C" void func_0026EE68(void* self);
extern "C" void func_0026EF30(void* self);
extern "C" void func_0026F7F8(void* self);
void func_0026F4A0(void* self, int state);
extern "C" void func_002702F8(void* self, void* a1);
extern "C" void func_002703F0(void* self, int a1);
extern "C" void* func_0028B180();
extern "C" void func_0028F200(void* self);

struct cReplayFramePtr_F8A0 {
    int state;              // 0x0
    char pad_0x4[0x604];
    int field_0x608;        // 0x608
    char pad_0x60c[0xC];
    int field_0x618;        // 0x618
    int field_0x61c;        // 0x61C
    int field_0x620;        // 0x620
};

extern "C" void func_0026F8A0(cReplayFramePtr_F8A0* self, void* a1, int a2, int a3)
{
    int ok = !(self->state == 14 || self->state == 15);
    if (ok) {
        if (self->field_0x608 == 0) {
            func_0026F7F8(self);
        }
        func_0026F4A0(self, 7);
        self->field_0x618 = 0;
        self->field_0x61c = 0;
        self->field_0x620 = a2;
        func_002702F8(self, a1);
        func_002703F0(self, 1);
        if (a2) {
            func_0026EF30(self);
        } else {
            func_0026EE68(self);
        }
        if (a2 == 0 && a3 == 0) {
            func_0028F200(func_0028B180());
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/frameptr", func_0026F980);
#ifdef SKIP_ASM
extern "C" void func_0026EEA0(void* self);
extern "C" void func_0026EF80(void* self);
void func_0026F4A0(void* self, int state);
extern "C" void func_0026F850(void* self);
extern "C" void func_00270628(void* self);
extern "C" void* func_0028B180();
extern "C" void func_0028F2C0(void* self);

struct cReplayFramePtr_F980 {
    int state;              // 0x0
    char pad_0x4[0x604];
    int field_0x608;        // 0x608
    int field_0x60c;        // 0x60C
    char pad_0x610[0xC];
    int field_0x61c;        // 0x61C
    int field_0x620;        // 0x620
    int field_0x624;        // 0x624
};

extern "C" void func_0026F980(cReplayFramePtr_F980* self)
{
    int ok = !(self->state == 14 || self->state == 15);
    if (ok) {
        func_00270628(self);
        if (self->field_0x61c == 0 && self->field_0x620 == 0) {
            func_0028F2C0(func_0028B180());
        }
        self->field_0x61c = 0;
        self->field_0x620 = 0;
        self->field_0x624 = 0;
        if (self->field_0x608 == 0) {
            func_0026F850(self);
            if (self->field_0x620) {
                func_0026EF80(self);
            } else {
                func_0026EEA0(self);
            }
            if (self->field_0x60c) {
                func_0026F4A0(self, 13);
            } else {
                func_0026F4A0(self, 0);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026FA50);
#ifdef SKIP_ASM
extern "C" void func_0026FA50(void* self)
{
    int s = *(int*)((char*)self + 0x0);
    bool ok = !(s == 0xE || s == 0xF);
    if (ok) {
        *(int*)((char*)self + 0x60C) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/frameptr", func_0026FA78);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern int D_00445438[];
int func_00320C48(void* pad, int button);
// PORT: func_00320BF0 returns the input axis value as a float ($f0).
extern "C" float func_00320BF0(void* pad, int axis);
extern "C" void cGameViewMan_updateAll(void* list);

static inline bool isStateFA78(int* self, int s)
{
    return *self == s;
}

extern "C" void func_0026FA78(int* self)
{
    if (!isStateFA78(self, 3)) {
        return;
    }
    void* pad = *(void**)(D_004A28A8 + (self[0x28 / 4] << 2) + 0xB0);
    if (func_00320C48(pad, 0x6C) != 0) {
        cGameViewMan_updateAll(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x84));
    }
    if (D_00445438[self[0x630 / 4]] != 0xB) {
        return;
    }
    if (func_00320BF0(pad, 0x31) != 0.0f || func_00320BF0(pad, 0x30) != 0.0f ||
        func_00320BF0(pad, 0x32) != 0.0f || func_00320BF0(pad, 0x33) != 0.0f) {
        cGameViewMan_updateAll(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x84));
    }
}
#endif

INCLUDE_ASM("replay/frameptr", func_0026FB88);

//100%
INCLUDE_ASM("replay/frameptr", func_0026FE50);
#ifdef SKIP_ASM
extern "C" void cGameViewMan_updateAll(void* list);
// PORT: func_0026E448 is declared (void*) in replay.cpp but takes the frame index too
extern "C" void func_00270378(void* self);
void* func_0026E448_2(void* self, int frame) __asm__("func_0026E448__FPv");
extern "C" void func_0026E568(void* self);
extern "C" void func_0026E528(void* self);
extern "C" void func_001620D0(void* p);

struct sVE_26FE50 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0026FE50(char* self)
{
    int redraw = 0;
    switch (*(int*)(self + 0x618)) {
    case 1:
        func_002702F8(self, 0);
        redraw = 1;
        func_002703F0(self, 1);
        if (*(int*)(self + 0x484) == 0) {
            func_0026F4A0(self, 6);
        } else {
            func_0026F4A0(self, 5);
        }
        break;
    case 2:
        func_00270378(self);
        redraw = 1;
        func_002703F0(self, 1);
        if (*(int*)(self + 0x484) == 0) {
            func_0026F4A0(self, 6);
        } else {
            func_0026F4A0(self, 5);
        }
        break;
    case 3: {
        redraw = 1;
        char* f = (char*)func_0026E448_2(self, *(int*)(self + 0x484));
        *(char**)(self + 0x488) = f;
        if (*(int*)(self + 0x484) == *(int*)(f + 0x30)) {
            func_0026E568(self);
        } else {
            char* n = *(char**)(f + 0x14);
            if (n != 0 && *(int*)(n + 0x30) == *(int*)(self + 0x484)) {
                func_0026E568(self);
            }
        }
        func_002703F0(self, 1);
        if (*(int*)(self + 0x484) == 0) {
            func_0026F4A0(self, 6);
        } else {
            func_0026F4A0(self, 5);
        }
        break;
    }
    case 4:
        redraw = 1;
        if (*(int*)(*(char**)(self + 0x488) + 0x14) != 0) {
            func_0026E528(self);
            func_002703F0(self, 1);
            func_0026F4A0(self, 5);
        }
        break;
    case 5:
        func_002703F0(self, 0);
        func_0026F4A0(self, 4);
        break;
    case 6:
        if (*(int*)self == 3) {
            func_0026F4A0(self, 1);
        } else {
            func_0026F4A0(self, 3);
        }
        break;
    case 7:
        func_0026F4A0(self, 3);
        break;
    case 8:
        break;
    default:
        if (*(int*)self != 3) {
            *(int*)(self + 0x604) = 1;
            func_002703F0(self, 0);
        }
        break;
    }
    *(int*)(self + 0x618) = 0;
    if (redraw) {
        char* views = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
        char* o = *(char**)(*(char**)(views + 4) + 0xA8);
        func_001620D0(o);
        sVE_26FE50* vt = *(sVE_26FE50**)(o + 0x14);
        vt[4].fn(o + vt[4].delta);
        cGameViewMan_updateAll(views);
    }
}
#endif

