#include "common.h"

//100%
INCLUDE_ASM("replay/replay", cReplay_restoreFrame);
#ifdef SKIP_ASM
class cStreamRF {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};
class cStreamRB;
class cStreamRDB;
struct cReplayFramePtr;
extern "C" void func_00354C98(void* mgr, void* bucket);
extern "C" void cBucketMan_purgeBucket(void* mgr, int bucket);
extern "C" void cWorld_resetMap(void* world);
void cReplayFramePtr_readRewind(cReplayFramePtr* p);
void func_00317908(void* buf);
// PORT: cWorldPainterMan_reset__FPv is called without loading $a0 here.
void cWorldPainterMan_reset_0() __asm__("cWorldPainterMan_reset__FPv");
extern "C" void* cBE_getBE();
extern "C" void cBE_readFromReplayFrame(void* be, void* stream);
extern "C" void cAvalanche_readFromReplayFrame(char* stream);
extern "C" void func_0030BD20(void* self, void* stream);
extern "C" void func_00229E58(void* self, void* stream);
extern "C" void func_00344240(void* self, void* stream);
extern "C" void func_00357D28(void* self, void* stream);
extern "C" void cReplay_restoreBucket(void* self, void* bucket, cStreamRB* stream);
extern "C" void cReplay_restoreDeadBucket(void* self, cStreamRDB* stream);
extern "C" void func_00103578(void* self, void* stream);
extern "C" void func_0026DE58(void* self, int a);
extern "C" void func_0012B788(void* self);
extern "C" void cGameViewMan_updateAll(void* self);
extern char D_004A5988;
extern void* D_004A47B8_DBF0 __asm__("D_004A47B8");
extern void* D_004A28A8;
extern void* D_004A3DD8;
extern void* D_004A2A00;
extern void* D_004A3FF0;
extern void* D_004A4028;
extern int D_004A5B78;
extern int D_004A5B7C;

struct sVtS_DBF0 { short delta; short index; void (*fn)(void*, void*); };

extern "C" void cReplay_restoreFrame(void* self, cStreamRF* stream)
{
    void* bm = &D_004A5988;
    func_00354C98(bm, (void*)1);
    cBucketMan_purgeBucket(bm, 1);
    cBucketMan_purgeBucket(bm, 8);
    cWorld_resetMap(D_004A47B8_DBF0);
    cReplayFramePtr_readRewind((cReplayFramePtr*)stream);
    char buf[0x18];
    stream->v02(buf, 0x18);
    func_00317908(buf);
    int v;
    stream->v02(&v, 4);
    D_004A5B78 = v;
    stream->v02(&v, 4);
    D_004A5B7C = v;
    cWorldPainterMan_reset_0();
    cBE_readFromReplayFrame(cBE_getBE(), stream);
    char* o = *(char**)((char*)D_004A28A8 + 0x84);
    sVtS_DBF0* vt = *(sVtS_DBF0**)o;
    vt[9].fn(o + vt[9].delta, stream);
    char* o2 = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC);
    sVtS_DBF0* vt2 = *(sVtS_DBF0**)(o2 + 0xCC);
    vt2[8].fn(o2 + vt2[8].delta, stream);
    cAvalanche_readFromReplayFrame((char*)stream);
    func_0030BD20(D_004A3DD8, stream);
    func_00229E58(D_004A2A00, stream);
    func_00344240(D_004A3FF0, stream);
    func_00357D28(D_004A4028, stream);
    cReplay_restoreBucket(self, (void*)1, (cStreamRB*)stream);
    cReplay_restoreDeadBucket(self, (cStreamRDB*)stream);
    func_00103578(*(void**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0xA4), stream);
    func_0026DE58(self, 1);
    func_0012B788(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC));
    cGameViewMan_updateAll(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84));
}
#endif

//100%
INCLUDE_ASM("replay/replay", cReplay_restoreBucket);
#ifdef SKIP_ASM
class cStreamRB {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

extern "C" void cReplay_restoreObject(void* self, void* bucket, cStreamRB* stream);
extern "C" void func_00354C98(void* mgr, void* bucket);
extern char D_004A5988;

extern "C" void cReplay_restoreBucket(void* self, void* bucket, cStreamRB* stream)
{
    struct {
        int count;
        int pad;
    } hdr;
    int i;
    stream->v02(&hdr, 8);
    for (i = 0; i < hdr.count; i++) {
        cReplay_restoreObject(self, bucket, stream);
    }
    func_00354C98(&D_004A5988, bucket);
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026DE58);
#ifdef SKIP_ASM
struct cBucketMan;
void* cBucketMan_first(cBucketMan* self, int index);
void* cBucketMan_next(cBucketMan* self, void* node, int index);
struct sBucketVEntryDE58 {
    short delta;
    short index;
    void (*fn)(void*);
};

// Calls virtual slot 3 on every object in the given bucket of the global bucket manager.
extern "C" void func_0026DE58(void* self, int a)
{
    void* node = cBucketMan_first((cBucketMan*)&D_004A5988, a);
    cBucketMan* bm = (cBucketMan*)&D_004A5988;
    while (node != 0) {
        sBucketVEntryDE58* vt = *(sBucketVEntryDE58**)((char*)node + 0xC);
        vt[3].fn((char*)node + vt[3].delta);
        node = cBucketMan_next(bm, node, a);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replay", cReplay_restoreObject);
#ifdef SKIP_ASM
class cStreamRB;
extern "C" void* cMemMan_alloc(unsigned int size, const char* tag, int flags, int d);
extern "C" int func_0026EA68(void* stream);
extern char D_004815F0[];
extern "C" void* cDebounceNode_cDebounceNode(void* self, void* bucket, void* stream);
extern char D_00481600[];
extern "C" void* func_00341C80_RO(void* self, void* bucket, void* stream) __asm__("func_00341C80");
extern char D_00481610[];
extern "C" void* func_00359270(void* self, void* bucket, void* stream);
extern char D_00481620[];
extern "C" void* func_00358DB0(void* self, void* bucket, void* stream);
extern char D_00481630[];
extern "C" void* func_003422E8_RO(void* self, void* bucket, void* stream) __asm__("func_003422E8");
extern char D_00481640[];
extern "C" void* func_003464E0(void* self, void* bucket, void* stream);
extern char D_004A3440[];
extern "C" void* func_003437C0(void* self, void* bucket, void* stream);
extern char D_004A3448[];
extern "C" void* func_00341548(void* self, void* bucket, void* stream);
extern char D_004A3450[];
extern "C" void* func_0034CBE8(void* self, void* bucket, void* stream);
extern char D_004A3458[];
extern "C" void* func_0034AE68(void* self, void* bucket, void* stream);
extern char D_00481650[];
extern "C" void* func_00352168(void* self, void* bucket, void* stream);
extern char D_00481660[];
extern "C" void* func_00357918(void* self, void* bucket, void* stream);
extern char D_004A3460[];
extern "C" void* func_00358588_RO(void* self, void* bucket, void* stream) __asm__("func_00358588");
extern char D_004A3468[];
extern "C" void* func_00350FD8(void* self, void* bucket, void* stream);
extern char D_00481670[];
extern "C" void* func_0034ED88(void* self, void* bucket, void* stream);
extern char D_00481680[];
extern "C" void* func_003430D0(void* self, void* bucket, void* stream);
extern char D_004A3470[];
extern "C" void* func_00350F08(void* self, void* bucket, void* stream);
extern char D_004A3478[];
extern "C" void* func_00356E60(void* self, void* bucket, void* stream);
extern char D_00481690[];
extern "C" void* func_00348FA0_RO(void* self, void* bucket, void* stream) __asm__("func_00348FA0");
extern char D_004816A0[];
extern "C" void* func_00349DB0_RO(void* self, void* bucket, void* stream) __asm__("func_00349DB0");
extern char D_004816B0[];
struct sVE_RO { short delta; short index; void (*fn)(void*, int); };
struct sObj_RO { int pad[3]; sVE_RO* vt; };
extern "C" sObj_RO* func_00350B98(void* self, void* bucket, void* stream);

// Recreates a replay object of the recorded type and links it into the bucket.
extern "C" void cReplay_restoreObject(void* self, void* bucket, cStreamRB* stream)
{
    switch (func_0026EA68(stream)) {
    case 0:
        cDebounceNode_cDebounceNode(cMemMan_alloc(0x34, D_004815F0, 0x20000000, 0), bucket, stream);
        break;
    case 1:
        func_00341C80_RO(cMemMan_alloc(0x6C, D_00481600, 0x20000000, 0), bucket, stream);
        break;
    case 2:
        func_00359270(cMemMan_alloc(0x70, D_00481610, 0x20000000, 0), bucket, stream);
        break;
    case 3:
        func_00358DB0(cMemMan_alloc(0x88, D_00481620, 0x20000000, 0), bucket, stream);
        break;
    case 4:
        func_003422E8_RO(cMemMan_alloc(0x80, D_00481630, 0x20000000, 0), bucket, stream);
        break;
    case 5:
        func_003464E0(cMemMan_alloc(0xB0, D_00481640, 0x20000000, 0), bucket, stream);
        break;
    case 7:
        func_003437C0(cMemMan_alloc(0x24, D_004A3440, 0x20000000, 0), bucket, stream);
        break;
    case 8:
        func_00341548(cMemMan_alloc(0x50, D_004A3448, 0x20000000, 0), bucket, stream);
        break;
    case 9:
        func_0034CBE8(cMemMan_alloc(0x10C, D_004A3450, 0x20000000, 0), bucket, stream);
        break;
    case 10:
        func_0034AE68(cMemMan_alloc(0x1C, D_004A3458, 0x20000000, 0), bucket, stream);
        break;
    case 11:
        func_00352168(cMemMan_alloc(0x6C0, D_00481650, 0x20000000, 0), bucket, stream);
        break;
    case 13:
        func_00357918(cMemMan_alloc(0x2C, D_00481660, 0x20000000, 0), bucket, stream);
        break;
    case 18:
        func_00358588_RO(cMemMan_alloc(0x218, D_004A3460, 0x20000000, 0), bucket, stream);
        break;
    case 19:
        func_00350FD8(cMemMan_alloc(0x1C, D_004A3468, 0x20000000, 0), bucket, stream);
        break;
    case 14:
        func_0034ED88(cMemMan_alloc(0x7C, D_00481670, 0x20000000, 0), bucket, stream);
        break;
    case 15:
        func_003430D0(cMemMan_alloc(0x48, D_00481680, 0x20000000, 0), bucket, stream);
        break;
    case 16:
        func_00350F08(cMemMan_alloc(0x1C, D_004A3470, 0x20000000, 0), bucket, stream);
        break;
    case 17:
        func_00356E60(cMemMan_alloc(0x2C, D_004A3478, 0x20000000, 0), bucket, stream);
        break;
    case 20:
        func_00348FA0_RO(cMemMan_alloc(0x80, D_00481690, 0x20000000, 0), bucket, stream);
        break;
    case 21:
        func_00349DB0_RO(cMemMan_alloc(0x80, D_004816A0, 0x20000000, 0), bucket, stream);
        break;
    case 22: {
        sObj_RO* o = func_00350B98(cMemMan_alloc(0x3C, D_004816B0, 0x20000000, 0), bucket, stream);
        if (o != 0) {
            o->vt[1].fn((char*)o + o->vt[1].delta, 3);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("replay/replay", cReplay_restoreDeadBucket);
#ifdef SKIP_ASM
class cStreamRDB {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

struct sRdbModelSet {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};

struct sRdbWorld {
    char pad_0x0[0x8];
    sRdbModelSet** sets;    // 0x8
};

extern sRdbWorld** D_004A47B8;
extern char D_00481720[];
extern "C" void* cMemMan_alloc(unsigned int size, const char* tag, int flags, int d);
extern "C" void* func_003506D8(void* self, void* model);

static inline void* refToPtrRDB(unsigned int p)
{
    return (void*)(p << 2);
}

struct sRdbRef {
    unsigned int id;
    sRdbRef() : id(0xFFFFFFFF) {}

    void* get()
    {
        sRdbModelSet* set = (*D_004A47B8)->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        unsigned int p = set->refs[id >> 8] >> 8;
        if (p == 0) {
            return 0;
        }
        return refToPtrRDB(p);
    }
};

extern "C" void cReplay_restoreDeadBucket(void* self, cStreamRDB* stream)
{
    struct {
        int count;
        int pad;
    } hdr;
    sRdbRef ref;
    stream->v02(&hdr, 8);
    for (int i = 0; i < hdr.count; i++) {
        stream->v02(&ref, 4);
        void* mem = cMemMan_alloc(0x1C, D_00481720, 0x20000000, 0);
        func_003506D8(mem, ref.get());
    }
}
#endif

extern "C" void* func_0026E6A0(void*);

//100%
INCLUDE_ASM("replay/replay", func_0026E448__FPv);
#ifdef SKIP_ASM
void* func_0026E448(void* self)
{
    return func_0026E6A0((char*)self + 0x3b0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replay", func_0026E468);
#ifdef SKIP_ASM
extern "C" void* func_0026E468(void* self, int idx)
{
    void* p = func_0026E448(self);
    void* q = *(void**)((char*)p + 0x14);
    if (q != 0) {
        p = q;
    }
    return p;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replay", func_0026E490);
#ifdef SKIP_ASM
extern "C" void* func_0026E490(void* self, int idx)
{
    void* p = func_0026E448(self);
    void* q = *(void**)((char*)p + 0x18);
    if (q != 0) {
        p = q;
    }
    return p;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replay", func_0026E4B8);
#ifdef SKIP_ASM
// PORT: func_0026E448 is declared in this unit with one parameter, but this caller
// passes (self, index); bind the 2-arg form to the symbol.
void* func_0026E448_2(void* self, int idx) __asm__("func_0026E448__FPv");
extern "C" int func_0026D4D8(void* stream, unsigned int pos);

struct sReplay0026E4B8 {
    char pad_0x000[0x484];
    int pos;
    void* frame;
    void* streams[2];
};

extern "C" void func_0026E4B8(void* self_)
{
    sReplay0026E4B8* self = (sReplay0026E4B8*)self_;
    int i;
    void* p = func_0026E448_2(self, self->pos);
    self->frame = p;
    self->pos = *(int*)((char*)p + 0x30);
    for (i = 0; i < 2; i++) {
        if (self->streams[i] != 0) {
            func_0026D4D8(self->streams[i], self->pos);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replay", func_0026E528);
#ifdef SKIP_ASM
void* func_0026E468(void* self, int idx);
extern "C" void func_0026E4B8(void* self);

extern "C" void func_0026E528(void* self)
{
    void* p = func_0026E468(self, *(int*)((char*)self + 0x484));
    *(void**)((char*)self + 0x488) = p;
    *(int*)((char*)self + 0x484) = *(int*)((char*)p + 0x30);
    func_0026E4B8(self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replay", func_0026E568);
#ifdef SKIP_ASM
void* func_0026E490(void* self, int idx);
extern "C" void func_0026E4B8(void* self);

extern "C" void func_0026E568(void* self)
{
    void* p = func_0026E490(self, *(int*)((char*)self + 0x484));
    *(void**)((char*)self + 0x488) = p;
    *(int*)((char*)self + 0x484) = *(int*)((char*)p + 0x30);
    func_0026E4B8(self);
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E5A8__FPv);
#ifdef SKIP_ASM
void* func_0026E5A8(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)self = t0;
    *(int*)((char*)self + 0x8) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E5C0__FPv);
#ifdef SKIP_ASM
void func_0026E5C0(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x8) = 0;
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E5D0);
#ifdef SKIP_ASM
struct sReplayNode {
    char pad[0x14];
    sReplayNode* next;
    sReplayNode* prev;
};

struct sReplayList {
    sReplayNode* head;
    sReplayNode* tail;
    int count;
};

extern "C" void func_0026E5D0(sReplayList* list, sReplayNode* node)
{
    node->prev = list->tail;
    node->next = 0;
    if (list->tail) {
        list->tail->next = node;
    }
    list->tail = node;
    if (!list->head) {
        list->head = node;
    }
    list->count++;
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E608);
#ifdef SKIP_ASM
extern "C" void func_0026E608(sReplayList* list, sReplayNode* node)
{
    if (node == list->head) {
        list->head = node->next;
    }
    if (node == list->tail) {
        list->tail = node->prev;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    node->next = 0;
    node->prev = 0;
    list->count--;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replay", func_0026E670);
#ifdef SKIP_ASM
extern "C" sReplayNode* func_0026E670(sReplayList* list)
{
    sReplayNode* node = list->head;
    func_0026E608(list, node);
    return node;
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E6A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sReplayFrame {
    char pad[0x14];
    sReplayFrame* next;
    char pad2[0x30 - 0x18];
    int time;
};

struct sReplayFrameList {
    sReplayFrame* head;
    sReplayFrame* tail;
    int count;
};

// the unit declares this with one arg; bind the real 2-arg body to the symbol
sReplayFrame* func_0026E6A0_impl(sReplayFrameList* list, int time) __asm__("func_0026E6A0");

sReplayFrame* func_0026E6A0_impl(sReplayFrameList* list, int time)
{
    sReplayFrame* f = list->head;
    while (f->next) {
        if (f->time == time) {
            break;
        }
        if (f->time < time && time < f->next->time) {
            break;
        }
        f = f->next;
    }
    return f;
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E6E0);
#ifdef SKIP_ASM
void func_0026D730(void*, int, int);

struct sReplayDataE6E0 {
    int v[0xAC / 4];
};

struct sReplayObjE6E0 {
    int index;                  // 0x0
    sReplayDataE6E0 data;       // 0x4
    void* rider;                // 0xB0
};

extern "C" void func_0026E6E0(sReplayObjE6E0* self, char* rider, sReplayDataE6E0* src)
{
    *(unsigned char*)(rider + 0x1E) |= 1 << self->index;
    func_0026D730(rider, self->index, 0);
    self->rider = rider;
    self->data = *src;
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E7F8__FPv);
#ifdef SKIP_ASM
void func_0026E7F8(void* self)
{
    *(int*)((char*)self + 0xB0) = 0;
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E800);
#ifdef SKIP_ASM
extern "C" void func_0026E800(void* self)
{
    unsigned char* p = *(unsigned char**)((char*)self + 0xb0);
    if (p) {
        p[0x1e] &= ~(1 << *(int*)self);
        *(int*)((char*)self + 0xb0) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replay", func_0026E838);
#ifdef SKIP_ASM
void func_0026D730(void*, int, int);

extern "C" int func_0026E838(void* self, void* o, int mode)
{
    if (mode) {
        int d = *(int*)((char*)o + 0x9C) - *(int*)((char*)self + 0xA0);
        if (d == 0) return 0;
        if (d >= 1000) {
            func_0026D730(*(void**)((char*)self + 0xB0), *(int*)self, d);
            return 1;
        }
        float v = *(float*)((char*)o + 0x44);
        if (v >= 5.0f) {
            func_0026D730(*(void**)((char*)self + 0xB0), *(int*)self, (int)(v * 1000.0f));
            return 1;
        }
    }
    int e = *(int*)((char*)o + 0xA4) - *(int*)((char*)self + 0xA8);
    if (e == 0) return 0;
    func_0026D730(*(void**)((char*)self + 0xB0), *(int*)self, -e);
    return 1;
}
#endif

extern void* D_00481898[];

//100%
INCLUDE_ASM("replay/replay", func_0026E8E0__FPv);
#ifdef SKIP_ASM
void* func_0026E8E0(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)self = (int)(void*)D_00481898;
    *(int*)((char*)self + 0x8) = t0;
    *(int*)((char*)self + 0xc) = t0;
    *(int*)((char*)self + 0x10) = t0;
    return self;
}
#endif

