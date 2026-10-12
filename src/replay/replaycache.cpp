#include "common.h"

//100%
INCLUDE_ASM("replay/replaycache", cReplay_addCache);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0026D0A0(void* self);
extern const char D_004817B0[];

extern "C" void* cReplay_addCache(void* self)
{
    void** slot = (void**)((char*)self + 0x48C);
    for (int i = 0; i < 2; i++, slot++) {
        if (*slot == 0) {
            return *slot = func_0026D0A0(cMemMan_alloc(0x10, D_004817B0, 0, 0));
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002700D8);
#ifdef SKIP_ASM
extern "C" void func_0026D0E8(void* p, int mode);

extern "C" void func_002700D8(void* self, void* p)
{
    if (p != 0) {
        void** slot = (void**)((char*)self + 0x48C);
        for (int i = 0; i < 2; i++, slot++) {
            if (*slot == p) {
                if (*slot != 0) {
                    func_0026D0E8(*slot, 3);
                }
                *slot = 0;
                return;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270130);
#ifdef SKIP_ASM
extern "C" void func_002701A0(void* self);
extern "C" void* func_0026E670(void* list);

struct sFrameDesc270130 {
    short type;
    char a;
    char b;
};

extern "C" void* func_00270130(void* self)
{
    void* list = (char*)self + 0x3BC;
    if (*(int*)((char*)self + 0x3C4) <= 0) {
        func_002701A0(self);
    }
    void* node = func_0026E670(list);
    sFrameDesc270130 desc;
    desc.type = 0;
    desc.a = 0;
    desc.b = 0;
    *(sFrameDesc270130*)((char*)node + 0x1C) = desc;
    *(int*)((char*)node + 0x20) = -1;
    *(int*)((char*)node + 0x24) = -1;
    *(int*)((char*)node + 0x34) = -1;
    *(int*)((char*)node + 0x30) = 0;
    return node;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002701A0);
#ifdef SKIP_ASM
extern "C" void func_00270238(void* self, void* node);

struct sRcNode1A0 {
    char pad_0x00[0x14];
    sRcNode1A0* next;       // 0x14
    char pad_0x18[0x6];
    unsigned char locked;   // 0x1E
    unsigned char used;     // 0x1F
};

struct sRcCursor1A0 {
    char pad_0x000[0x3AC];
    sRcNode1A0* cursor;     // 0x3AC
    sRcNode1A0* head;       // 0x3B0
};

extern "C" void func_002701A0(void* self)
{
    sRcCursor1A0* c = (sRcCursor1A0*)self;
    int i;
    for (i = 0; i < 2; i++) {
        while (c->cursor != 0 && c->cursor->next != 0 && c->cursor->next->next != 0) {
            sRcNode1A0* n = c->cursor->next;
            if (n->used == 0) {
                if (n->locked == 0) {
                    c->cursor = n->next;
                    func_00270238(self, n);
                    return;
                }
            }
            c->cursor = c->cursor->next;
        }
        c->cursor = c->head;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270238);
#ifdef SKIP_ASM
extern "C" void func_0026E608(void* list, void* node);
extern "C" void func_0026D628(void* node);
extern "C" void func_0026E5D0(void* list, void* node);

extern "C" void func_00270238(void* self, void* node)
{
    func_0026E608((char*)self + 0x3B0, node);
    func_0026D628(node);
    func_0026E5D0((char*)self + 0x3BC, node);
}
#endif

INCLUDE_ASM("replay/replaycache", func_00270280);

//100%
INCLUDE_ASM("replay/replaycache", func_002702F8);
#ifdef SKIP_ASM
extern "C" int func_0026D4D8(void* stream, unsigned int pos);

struct sReplay002702F8 {
    char pad_0x000[0x3B0];
    void* head;
    char pad_0x3B4[0x484 - 0x3B4];
    int pos;
    void* frame;
    void* streams[2];
    char pad_0x494[0x604 - 0x494];
    int unk_0x604;
};

extern "C" void func_002702F8(sReplay002702F8* self, void* frame)
{
    int i;
    self->unk_0x604 = 0;
    if (frame != 0) {
        self->frame = frame;
    } else {
        self->frame = self->head;
    }
    self->pos = *(int*)((char*)self->frame + 0x30);
    for (i = 0; i < 2; i++) {
        if (self->streams[i] != 0) {
            func_0026D4D8(self->streams[i], self->pos);
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270378);
#ifdef SKIP_ASM
extern "C" int func_0026D4D8(void* stream, unsigned int pos);
// PORT: func_0026E448 is declared elsewhere with one parameter, but this caller
// passes (self, pos); bind the 2-arg form to the symbol.
void* func_0026E448_2(void* self, int pos) __asm__("func_0026E448__FPv");

struct sReplay00270378 {
    char pad_0x000[0x484];
    int pos;
    void* frame;
    void* streams[2];
    char pad_0x494[0x604 - 0x494];
    int unk_0x604;
};

extern "C" void func_00270378(sReplay00270378* self)
{
    int i;
    self->unk_0x604 = 0;
    void* p = func_0026E448_2(self, 100000000);
    self->frame = p;
    self->pos = *(int*)((char*)p + 0x30);
    for (i = 0; i < 2; i++) {
        if (self->streams[i] != 0) {
            func_0026D4D8(self->streams[i], self->pos);
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002703F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0026DB88(void* self, void* frame);
extern "C" void func_001620D0(void* self);
extern "C" void cGameViewMan_updateAll(void* list);
void* func_0026E448_2(void* self, int pos) __asm__("func_0026E448__FPv");
extern char* D_004A28A8;
void func_0026F4A0(void* self, int arg);

struct sRcVEntry03F0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sReplay002703F0 {
    char pad_0x000[0x3CC];
    int end;                // 0x3CC
    void* tail;             // 0x3D0
    char pad_0x3D4[0x484 - 0x3D4];
    int pos;                // 0x484
    void* frame;            // 0x488
    void* streams[2];       // 0x48C
    char pad_0x494[0x61C - 0x494];
    int loop;               // 0x61C
};

extern "C" void func_002703F0(sReplay002703F0* self, int reset)
{
    int i;
    if (reset) {
        self->frame = func_0026E448_2(self, self->pos);
    }
    void* f = self->frame;
    if (f != 0 && f == self->tail) {
        self->frame = *(void**)((char*)f + 0x18);
    }
    if (reset) {
        self->pos = *(int*)((char*)self->frame + 0x30);
        for (i = 0; i < 2; i++) {
            if (self->streams[i] != 0) {
                func_0026D4D8(self->streams[i], self->pos);
            }
        }
        func_0026DB88(self, self->frame);
        return;
    }
    if (self->pos >= self->end) {
        if (self->loop != 0) {
            func_002702F8((sReplay002702F8*)self, 0);
            func_002703F0(self, 1);
            void* list = *(void**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
            char* obj = *(char**)(*(char**)((char*)list + 0x4) + 0xA8);
            func_001620D0(obj);
            sRcVEntry03F0* vt = *(sRcVEntry03F0**)(obj + 0x14);
            vt[4].fn(obj + vt[4].delta);
            cGameViewMan_updateAll(list);
        } else {
            self->pos = self->end;
            func_0026F4A0(self, 3);
        }
    } else {
        self->pos++;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270538);
#ifdef SKIP_ASM
struct sReplayNode270538 {
    char pad_0x00[0x14];
    sReplayNode270538* next;
    char pad_0x18[0x4];
    unsigned short type;
    unsigned char a;
    unsigned char b;
};

extern "C" void func_00270538(void* self)
{
    sReplayNode270538* node = *(sReplayNode270538**)((char*)self + 0x3B0);
    while (node != 0) {
        sReplayNode270538* next = node->next;
        if (node->type != 0) {
        } else if (node->b != 0) {
        } else if (node->a != 0) {
        } else {
            func_00270238(self, node);
        }
        node = next;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002705A8__FPv);
#ifdef SKIP_ASM
void func_002705A8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002705B0);
#ifdef SKIP_ASM
extern "C" void func_00270658(void* self);

// PORT: the unit declares the object argument as int.
extern "C" void func_002705B0(void* self, int obj, int alt)
{
    char* s = (char*)self;
    char* o = (char*)obj;
    if (*(int*)(s + 0x3D4) == 0) {
        return;
    }
    if (*(int*)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0x7C) != 1) {
        return;
    }
    int now;
    int start;
    if (alt != 0) {
        now = *(int*)(o + 0x9C);
        start = *(int*)(s + 0x474);
    } else {
        now = *(int*)(o + 0xA4);
        start = *(int*)(s + 0x47C);
    }
    now -= start;
    if (now >= 1000) {
        func_00270658(self);
    } else {
        *(int*)(s + 0x3D4) = 0;
    }
}
#endif

INCLUDE_ASM("replay/replaycache", func_00270628);

//100%
INCLUDE_ASM("replay/replaycache", func_00270658);
#ifdef SKIP_ASM
extern "C" void func_00270658(void* self)
{
    if (*(int*)((char*)self + 0x620) == 0) {
        *(int*)((char*)self + 0x624) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270670);
#ifdef SKIP_ASM
extern "C" void func_0026F980(void* self);
extern "C" void func_001173B8(void* p);
extern char* D_004A28A8;

extern "C" void func_00270670(void* self)
{
    if (*(int*)((char*)self + 0x620) != 0) {
        func_0026F980(self);
        func_001173B8(*(void**)(*(char**)(*(char**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0x40) + 0x18) + 0x790));
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002706B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_0026F4A0_cpp(void* self, int arg) __asm__("func_0026F4A0__FPvi");

extern "C" void func_002706B8(void* self)
{
    if (*(int*)((char*)self + 0x61C) == 0 && *(int*)self != 9) {
        func_0026F4A0_cpp(self, 9);
    }
}
#endif

extern "C" void func_0026F980(void* self);
void func_0026F4A0(void* self, int arg);

//100%
INCLUDE_ASM("replay/replaycache", cReplay_stopAutoReplay__FPv);
#ifdef SKIP_ASM
void cReplay_stopAutoReplay(void* self)
{
    if (*(int*)((char*)self + 0x61C) != 0) {
        func_0026F980(self);
    }
    func_0026F4A0(self, 0xD);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270730);
#ifdef SKIP_ASM
extern char* D_004A28A8;

class cRcIdObj_0730 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
};

struct sRcRider_0730 {
    char pad_0x0[0x18];
    char* obj;                      // 0x18
};

struct sRcWorld_0730 {
    char pad_0x0[0x40];
    sRcRider_0730* riders[15];      // 0x40
    int numRiders;                  // 0x7C
};

static inline sRcWorld_0730* world_0730()
{
    return *(sRcWorld_0730**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
}

extern "C" int func_00270730(int id)
{
    int i;
    for (i = 0; i < world_0730()->numRiders; i++) {
        if (((cRcIdObj_0730*)(world_0730()->riders[i]->obj + 0x6C0))->v07() == id) {
            return i;
        }
    }
    return -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002707E0);
#ifdef SKIP_ASM
extern "C" int func_00270730(int id);
extern "C" void func_00270B88(void* self, int slot, int id);
// PORT: the unit defines func_002705A8(void*) (an empty stub), but this caller
// passes (self, id); bind the 2-arg call by asm label.
void func_002705A8_2(void* self, int id) __asm__("func_002705A8__FPv");

extern "C" void func_002707E0(void* self, int key, int id)
{
    if (*(int*)((char*)self + 0x61C) == 0 && *(int*)((char*)self + 0x620) == 0 &&
        *(int*)((char*)self + 0x610) == 0 && *(int*)((char*)self + 0x60C) == 0 &&
        *(int*)((char*)self + 0x0) == 0) {
        int slot = func_00270730(key);
        if (slot >= 0) {
            func_00270B88(self, slot, id);
            func_002705A8_2(self, id);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00270870);
#ifdef SKIP_ASM
extern "C" int func_00270730(int id);
extern "C" void func_00270CE8(void* self, int slot, int id, int flag);
extern "C" void func_002705B0(void* self, int id, int flag);

extern "C" void func_00270870(void* self, int key, int id)
{
    if (*(int*)((char*)self + 0x61C) == 0 && *(int*)((char*)self + 0x620) == 0 &&
        *(int*)((char*)self + 0x0) == 0) {
        int slot = func_00270730(key);
        if (slot >= 0) {
            func_00270CE8(self, slot, id, 1);
            func_002705B0(self, id, 1);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002708F0);
#ifdef SKIP_ASM
extern "C" int func_00270730(int id);
extern "C" void func_00270CE8(void* self, int slot, int id, int flag);
extern "C" void func_002705B0(void* self, int id, int flag);

extern "C" void func_002708F0(void* self, int key, int id)
{
    if (*(int*)((char*)self + 0x61C) == 0 && *(int*)((char*)self + 0x620) == 0 &&
        *(int*)((char*)self + 0x0) == 0) {
        int slot = func_00270730(key);
        if (slot >= 0) {
            func_00270CE8(self, slot, id, 0);
            func_002705B0(self, id, 0);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00270970);
#ifdef SKIP_ASM
extern "C" int func_00270730(int id);
struct sRcSlots;
extern "C" void func_00270DE0(sRcSlots* self, int i);
extern "C" void func_00270628(void* self);

extern "C" void func_00270970(void* self, int key)
{
    if (*(int*)((char*)self + 0x61C) == 0 && *(int*)((char*)self + 0x620) == 0 &&
        *(int*)((char*)self + 0x0) == 0) {
        int slot = func_00270730(key);
        if (slot >= 0) {
            func_00270DE0((sRcSlots*)self, slot);
            func_00270628(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002709D8);
#ifdef SKIP_ASM
extern "C" int func_00270730(int id);
extern "C" void func_00270B88(void* self, int slot, int id);
// PORT: the unit defines func_002705A8(void*) (an empty stub), but this caller
// passes (self, id); bind the 2-arg call by asm label.
void func_002705A8_2(void* self, int id) __asm__("func_002705A8__FPv");
extern char* D_004A28A8;

extern "C" void func_002709D8(void* self, int key, int mode)
{
    if (*(int*)((char*)self + 0x61C) == 0 && *(int*)((char*)self + 0x620) == 0 &&
        *(int*)((char*)self + 0x610) == 0 && *(int*)((char*)self + 0x60C) == 0 &&
        *(int*)((char*)self + 0x0) == 0) {
        int slot = func_00270730(key);
        if (slot >= 0) {
            char* world = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
            char* rider = *(char**)(world + (key << 2) + 0x28);
            switch (mode) {
            case 0:
                func_002705A8_2(self, *(int*)(rider + 0x790) + 0xFC);
                break;
            case 1:
                func_00270B88(self, slot, *(int*)(rider + 0x790) + 0xFC);
                break;
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00270AB0);
#ifdef SKIP_ASM
static inline int func_00270AB0_isClear(int v, int bit)
{
    return !((v >> bit) & 1);
}

extern "C" void func_00270AB0(void* self, int key, int bit)
{
    if (*(int*)((char*)self + 0x61C) == 0 && *(int*)((char*)self + 0x620) == 0 &&
        *(int*)((char*)self + 0x610) == 0 && *(int*)((char*)self + 0x60C) == 0 &&
        *(int*)((char*)self + 0x0) == 0) {
        int slot = func_00270730(key);
        if (slot >= 0 && bit >= 0 && bit < *(int*)((char*)self + 0x10)) {
            int off = slot << 2;
            char* base = (char*)self + 0x5FC;
            int* p = (int*)(base + off);
            if (func_00270AB0_isClear(*p, bit)) {
                unsigned char* q = *(unsigned char**)((char*)self + 0x3B4);
                q[0x1F] |= 1 << slot;
                *p |= 1 << bit;
            }
        }
    }
}
#endif

INCLUDE_ASM("replay/replaycache", func_00270B88);

//100%
INCLUDE_ASM("replay/replaycache", func_00270BD8);
#ifdef SKIP_ASM
struct sReplayCacheNode {
    char pad[0x14];
    sReplayCacheNode* next;
    char pad2[0x1E - 0x18];
    unsigned char mask;
    char pad3;
    int values[1];
};

extern "C" int func_00270BD8(void* self, int i, int positive)
{
    int count = 0;
    sReplayCacheNode* n = *(sReplayCacheNode**)((char*)self + 0x3B0);
    while (n != 0) {
        if ((n->mask >> i) & 1) {
            if (positive) {
                if (n->values[i] > 0) count++;
            } else if (n->values[i] < 0) {
                count++;
            }
        }
        n = n->next;
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270C40);
#ifdef SKIP_ASM
extern "C" int func_00270C40(void* self, int a1)
{
    if (a1 != 0) {
        return *(int*)((char*)self + 0xc);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270C58);
#ifdef SKIP_ASM
struct sReplayCacheNode2 {
    char pad[0x14];
    sReplayCacheNode2* next;
    char pad2[0x1E - 0x18];
    unsigned char mask;
    unsigned char busy;
    int values[1];
};

extern "C" sReplayCacheNode2* func_00270C58(void* self, int i, sReplayCacheNode2* best, int positive)
{
    sReplayCacheNode2* result = best;
    sReplayCacheNode2* n = *(sReplayCacheNode2**)((char*)self + 0x3B0);
    while (n != 0) {
        if (((n->mask >> i) & 1) && n->busy == 0) {
            if (positive) {
                if (n->values[i] > 0 && !(best->values[i] < n->values[i])) {
                    best = result = n;
                }
            } else {
                if (n->values[i] < 0 && !(n->values[i] < best->values[i])) {
                    best = result = n;
                }
            }
        }
        n = n->next;
    }
    return result;
}
#endif

INCLUDE_ASM("replay/replaycache", func_00270CE8);

//100%
INCLUDE_ASM("replay/replaycache", func_00270DE0);
#ifdef SKIP_ASM
extern "C" void func_0026E800(void* p);

struct sRcSlot {
    char data[0xB4];
};

struct sRcSlots {
    int state;
    char pad[0x494 - 4];
    sRcSlot slots[1];
};

extern "C" void func_00270DE0(sRcSlots* self, int i)
{
    if (self->state == 0) {
        func_0026E800(&self->slots[i]);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270E18);
#ifdef SKIP_ASM
extern "C" void func_00270E18(sRcSlots* self)
{
    if (self->state == 0) {
        for (int i = 0; i < 2; i++) {
            func_0026E800(&self->slots[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270E68);
#ifdef SKIP_ASM
extern "C" void func_00270F20(void* self);

extern "C" void func_00270E68(void* self)
{
    func_00270F20(self);
    *(int*)((char*)self + 0x638) = 0;
    *(int*)((char*)self + 0x644) = 0;
    *(int*)((char*)self + 0x648) = 0;
    *(int*)((char*)self + 0x64C) = 0;
    *(int*)((char*)self + 0x650) = 0;
    *(int*)((char*)self + 0x654) = 0;
    *(int*)((char*)self + 0x658) = 0;
    *(int*)((char*)self + 0x65C) = 0;
    *(int*)((char*)self + 0x660) = 0;
    *(int*)((char*)self + 0x664) = 0;
    *(int*)((char*)self + 0x66C) = 0;
    *(int*)((char*)self + 0x674) = 0;
    *(int*)((char*)self + 0x678) = 0;
    *(int*)((char*)self + 0x67C) = 0;
    *(int*)((char*)self + 0x680) = 0;
    *(unsigned int*)((char*)self + 0x684) = 0xDEADBEEF;
}
#endif

extern "C" void* func_00270F78(void* self);

//100%
INCLUDE_ASM("replay/replaycache", func_00270ED8__FPv);
#ifdef SKIP_ASM
void* func_00270ED8(void* self)
{
    return func_00270F78(self);
}
#endif

extern "C" void* func_0026F228(void* self);

//100%
INCLUDE_ASM("replay/replaycache", func_00270EF8__FPv);
#ifdef SKIP_ASM
void* func_00270EF8(void* self)
{
    return func_0026F228(self);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270F18__FPv);
#ifdef SKIP_ASM
void func_00270F18(void* self)
{
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270F20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_00481800[];
extern const char D_00481810[];

extern "C" void func_00270F20(void* self)
{
    *(void**)((char*)self + 0x63C) = cMemMan_alloc(0x4000, D_00481800, 0x20000000, 0);
    *(void**)((char*)self + 0x640) = operator_new_tag(0xC800, D_00481810, 0x20000000, 0);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270F78);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void operator_delete(int* p);

// The unit declares this as returning void* (line ~198, used by the tail-call
// wrapper func_00270ED8); nothing meaningful is returned.
extern "C" void* func_00270F78(void* self)
{
    operator_delete(*(int**)((char*)self + 0x63C));
    void* p = *(void**)((char*)self + 0x640);
    if (p != 0) {
        cMemMan_free(p);
    }
    *(void**)((char*)self + 0x63C) = 0;
    *(void**)((char*)self + 0x640) = 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00270FC0);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int size);

struct sRcStream0FC0 {
    char pad_0x000[0x644];
    char* src;      // 0x644
    int left;       // 0x648
    int used;       // 0x64C
    char* dst;      // 0x650
};

extern "C" void func_00270FC0(sRcStream0FC0* self)
{
    if (self->src != 0) {
        if (self->left > 0) {
            int space = 0x4000 - self->used;
            int n = space < self->left ? space : self->left;
            if (n > 0) {
                func_003E6574(self->dst, self->src, n);
                self->dst += n;
                self->src += n;
                self->left -= n;
                self->used += n;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00271058);
#ifdef SKIP_ASM
extern "C" void func_00271058(void* self, signed char* data, int size)
{
    *(int*)((char*)self + 0x680) += size;
    for (int i = 0; i < size; i++) {
        *(int*)((char*)self + 0x684) += data[i];
    }
    *(signed char**)((char*)self + 0x644) = data;
    *(int*)((char*)self + 0x648) = size;
    *(int*)((char*)self + 0x678) += size;
}
#endif

INCLUDE_ASM("replay/replaycache", func_002710A8);

//100%
INCLUDE_ASM("replay/replaycache", func_00271228);
#ifdef SKIP_ASM
struct sReplayCache;
extern "C" int func_002712F8(sReplayCache* self);
extern "C" void func_0012BAF0(void* self, int* dst);
extern char* D_004A28A8;

struct sReplayHdr_1228 {
    int magic;   // 0x0
    int count;   // 0x4
    int a;       // 0x8
    int b;       // 0xC
    int c;       // 0x10
    int d;       // 0x14
    int mode;    // 0x18
    int pad;     // 0x1C
    int data[2]; // 0x20
};

extern "C" void func_00271228(void* self)
{
    sReplayHdr_1228* hdr = *(sReplayHdr_1228**)((char*)self + 0x640);
    hdr->count = func_002712F8((sReplayCache*)self);
    char* g = D_004A28A8;
    hdr->a = *(int*)((char*)self + 0x18);
    hdr->b = *(int*)((char*)self + 0x610);
    hdr->c = *(int*)((char*)self + 0x3C8);
    hdr->d = *(int*)((char*)self + 0x3CC);
    int mode = *(int*)(*(char**)(*(char**)(g + 0x84) + 0xC) + 0x7C);
    hdr->magic = 0xABCD0002;
    hdr->mode = mode;
    func_0012BAF0(*(void**)(*(char**)(g + 0x84) + 0xC), hdr->data);
    *(int*)((char*)self + 0x644) = 0;
    *(int*)((char*)self + 0x648) = 0;
    *(int*)((char*)self + 0x638) = *(int*)((char*)self + 0x638) + 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002712C0);
#ifdef SKIP_ASM
extern "C" void func_002712C0(void* self)
{
    func_00271058(self, *(signed char**)((char*)self + 0x640), 0x28);
    *(int*)((char*)self + 0x638) += 1;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002712F8);
#ifdef SKIP_ASM
struct sCacheNode {
    char pad[0x14];
    sCacheNode* next;
};

struct sReplayCache {
    char pad[0x3b0];
    sCacheNode* head;
    char pad2[0x3d0 - 0x3b4];
    sCacheNode* skip;
    char pad3[0x65c - 0x3d4];
    sCacheNode* iter;
};

extern "C" int func_002712F8(sReplayCache* self)
{
    int count = 0;
    self->iter = self->head;
    while (self->iter) {
        if (self->iter == self->skip) {
            self->iter = self->iter->next;
        } else {
            count++;
        }
        if (self->iter) {
            self->iter = self->iter->next;
        }
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00271348);
#ifdef SKIP_ASM
extern "C" void func_00271348(void* self)
{
    void* p = *(void**)((char*)self + 0x3b0);
    *(void**)((char*)self + 0x65c) = p;
    if (p == *(void**)((char*)self + 0x3d0)) {
        *(void**)((char*)self + 0x65c) = *(void**)((char*)p + 0x14);
    }
    *(int*)((char*)self + 0x660) = 0;
    *(int*)((char*)self + 0x638) += 1;
    *(int*)((char*)self + 0x644) = 0;
    *(int*)((char*)self + 0x648) = 0;
    *(int*)((char*)self + 0x668) = 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00271380);
#ifdef SKIP_ASM
extern "C" int HUFF_encode(void* src, int size, void* dst, int* state);
extern "C" void func_00271058(void* self, signed char* data, int size);
// PORT: cReplayFramePtr_getFrameBlock is mangled with no parameters (__Fv) but is
// called with (frame, n); bind the 2-arg form to the symbol.
void cReplayFramePtr_getFrameBlock_2(void* frame, int n) __asm__("cReplayFramePtr_getFrameBlock__Fv");

struct sRcFrame1380 {
    char pad_0x0[0x4];
    void* data;             // 0x4
    char pad_0x8[0x8];
    int size;               // 0x10
    sRcFrame1380* next;     // 0x14
    char pad_0x18[0x8];
    int f20;                // 0x20
    int f24;                // 0x24
    int f28;                // 0x28
    int f2C;                // 0x2C
    int f30;                // 0x30
    int f34;                // 0x34
};

struct sReplayCache1380 {
    char pad_0x0[0x3D0];
    sRcFrame1380* tail;     // 0x3D0
    char pad_0x3D4[0x638 - 0x3D4];
    int field_0x638;        // 0x638
    char pad_0x63C[0x4];
    int* out;               // 0x640
    int field_0x644;        // 0x644
    int field_0x648;        // 0x648
    char pad_0x64C[0x10];
    sRcFrame1380* frame;    // 0x65C
    void* pending;          // 0x660
    int pendingSize;        // 0x664
    int frames;             // 0x668
};

extern "C" void func_00271380(sReplayCache1380* self)
{
    if (self->pending != 0) {
        int state = 0;
        int n = HUFF_encode(self->pending, self->pendingSize, self->out + 1, &state);
        *self->out = n;
        func_00271058(self, (signed char*)self->out, n + 4);
        self->pending = 0;
        return;
    }
    if (self->frame != 0) {
        self->frames++;
        cReplayFramePtr_getFrameBlock_2(self->frame, 1);
        int* hdr = self->out;
        hdr[0] = 0x11111113;
        hdr[2] = self->frame->f30;
        hdr[3] = self->frame->f34;
        hdr[1] = self->frame->size;
        hdr[9] = 0x11111111;
        hdr[5] = self->frame->f20;
        hdr[6] = self->frame->f24;
        hdr[7] = self->frame->f28;
        hdr[8] = self->frame->f2C;
        hdr[7] = self->frame->f28;
        hdr[8] = self->frame->f2C;
        func_00271058(self, (signed char*)hdr, 0x28);
        sRcFrame1380* f = self->frame;
        self->pending = f->data;
        self->pendingSize = f->size;
        sRcFrame1380* next = f->next;
        self->frame = next;
        if (next != 0 && next == self->tail) {
            self->frame = next->next;
        }
        return;
    }
    self->field_0x644 = 0;
    self->field_0x648 = 0;
    self->field_0x638++;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002714E0);
#ifdef SKIP_ASM
extern "C" void func_002714E0(void* self)
{
    *(int*)((char*)self + 0x658) = 2;
    *(int*)((char*)self + 0x638) += 1;
    *(int*)((char*)self + 0x674) = 0;
    *(int*)((char*)self + 0x66c) = 0;
    *(int*)((char*)self + 0x670) = 0;
    *(int*)((char*)self + 0x644) = 0;
    *(int*)((char*)self + 0x648) = 0;
    *(int*)((char*)self + 0x654) = 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00271510);
#ifdef SKIP_ASM
extern "C" int HUFF_encode(void* src, int size, void* dst, int* state);

struct sRcEntry1510 {
    int field_0x0;          // 0x0
    char pad_0x4[0x8];
    void* data;             // 0xC
};

struct sReplayCache1510 {
    char pad_0x0[0x48C];
    sRcEntry1510* entries[(0x638 - 0x48C) / 4];   // 0x48C
    int field_0x638;        // 0x638
    char pad_0x63C[0x4];
    int* out;               // 0x640
    int field_0x644;        // 0x644
    int field_0x648;        // 0x648
    char pad_0x64C[0x8];
    int cur;                // 0x654
    int count;              // 0x658
    char pad_0x65C[0x10];
    void* pending;          // 0x66C
    int pendingSize;        // 0x670
    int* header;            // 0x674
};

extern "C" void func_00271510(sReplayCache1510* self)
{
    if (self->header != 0) {
        func_00271058(self, (signed char*)self->header, 8);
        self->header = 0;
        return;
    }
    if (self->pending != 0) {
        int state = 0;
        int n = HUFF_encode(self->pending, self->pendingSize, self->out + 1, &state);
        *self->out = n;
        func_00271058(self, (signed char*)self->out, n + 4);
        self->pending = 0;
        return;
    }
    int cur = self->cur;
    if (cur < self->count) {
        self->pending = 0;
        self->header = 0;
        self->pendingSize = 0;
        sRcEntry1510* e = self->entries[cur];
        if (e != 0) {
            self->pending = e->data;
            self->header = self->out;
            self->pendingSize = 0x8000;
            *self->out = 0x11111112;
            self->header[1] = e->field_0x0;
            self->cur++;
        } else {
            self->cur = cur + 1;
            self->field_0x648 = 0;
            self->field_0x644 = 0;
        }
    } else {
        self->field_0x638++;
        self->field_0x648 = 0;
        self->field_0x644 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00271620);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);
extern "C" void* cBE_getBE();
extern "C" int func_0014E048(void* be);

extern "C" void func_00271620(void* self)
{
    func_003E6448(*(void**)((char*)self + 0x640), 0, 0xC800);
    int used = func_0014E048(cBE_getBE()) + *(int*)((char*)self + 0x678);
    *(int*)((char*)self + 0x67C) = 0x7FFF8 - used;
    *(int*)((char*)self + 0x638) += 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00271688);
#ifdef SKIP_ASM
extern "C" void func_00271688(void* self)
{
    int left = *(int*)((char*)self + 0x67C);
    if (left > 0) {
        int n = (left < 0x4001) ? left : 0x4000;
        func_00271058(self, *(signed char**)((char*)self + 0x640), n);
        *(int*)((char*)self + 0x67C) -= n;
    } else {
        *(int*)((char*)self + 0x638) += 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002716F0__FPv);
#ifdef SKIP_ASM
void* func_002716F0(void* self)
{
    int t0 = 0;
    void* t1 = (char*)*(void**)((char*)self + 0x638) + 0x1;
    *(int*)((char*)self + 0x644) = t0;
    *(int*)((char*)self + 0x648) = t0;
    *(int*)((char*)self + 0x638) = (int)t1;
    return t1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00271708);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int size);
extern "C" void func_00271058(void* self, signed char* data, int size);

extern "C" void func_00271708(void* self)
{
    func_003E6574(*(void**)((char*)self + 0x640), (char*)self + 0x680, 8);
    func_00271058(self, *(signed char**)((char*)self + 0x640), 8);
    *(int*)((char*)self + 0x638) += 1;
}
#endif

INCLUDE_ASM("replay/replaycache", func_00271758);

INCLUDE_ASM("replay/replaycache", func_002718E8);

//100%
INCLUDE_ASM("replay/replaycache", func_002721D0);
#ifdef SKIP_ASM
void operator_delete(int* p);

extern void* D_00481898[];

extern "C" void func_002721D0(int* self, int flags)
{
    *(void**)self = D_00481898;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272258);
#ifdef SKIP_ASM
void operator_delete(int* p);

extern void* D_00481898[];

extern "C" void func_00272258(int* self, int flags)
{
    *(void**)self = D_00481898;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272288);
#ifdef SKIP_ASM
extern "C" void func_00272288(int* self)
{
    self[0] = -1;
    self[0xB0 / 4] = 0;
    func_003E6448(self + 1, 0, 0xAC);
}
#endif

extern "C" void* func_002718E8(int, int);

//99.38%
INCLUDE_ASM("replay/replaycache", func_002722C0__FPv);
#ifdef SKIP_ASM
void* func_002722C0(void* self)
{
    return func_002718E8(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002722E0__FPvN20);
#ifdef SKIP_ASM
void* func_002722E0(void* self, void* a1, void* a2)
{
    *(int*)((char*)self + 0x8) = (int)a1;
    *(int*)self = (int)a1;
    *(int*)((char*)self + 0x4) = (int)a2;
    *(int*)((char*)a1 + 0x4) = 0;
    *(int*)*(void**)((char*)self + 0x8) = (int)((char*)a2 - 0x8);
    return self;
}
#endif

INCLUDE_ASM("replay/replaycache", func_00272308);

//100%
INCLUDE_ASM("replay/replaycache", func_002723A8);
#ifdef SKIP_ASM
struct sRcBlock {
    int size;
    sRcBlock* next;
};

struct sRcHeap {
    int field_0x0;
    int field_0x4;
    sRcBlock* freeList;
};

extern "C" void func_002723A8(sRcHeap* h, void* p)
{
    if (p) {
        sRcBlock* b = (sRcBlock*)((char*)p - 8);
        if (!h->freeList) {
            h->freeList = b;
            return;
        }
        sRcBlock* prev = 0;
        sRcBlock* cur = h->freeList;
        do {
            if (b < cur) {
                int size = b->size + 8;
                if ((sRcBlock*)((char*)b + size) == cur) {
                    b->next = cur->next;
                    b->size = size + cur->size;
                    if (!prev)
                        h->freeList = b;
                    else
                        prev->next = b;
                    return;
                }
                if (!prev) {
                    b->next = h->freeList;
                    h->freeList = b;
                } else {
                    b->next = prev->next;
                    prev->next = b;
                }
                return;
            }
            int size = cur->size + 8;
            if ((sRcBlock*)((char*)cur + size) == b) {
                cur->size = size + b->size;
                b = cur;
                cur = b->next;
                b->next = 0;
                if (!prev)
                    h->freeList = cur;
                else
                    prev->next = cur;
            } else {
                prev = cur;
                cur = cur->next;
            }
        } while (cur);
        if (!prev) {
            b->next = h->freeList;
            h->freeList = b;
        } else {
            b->next = prev->next;
            prev->next = b;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00272488);
#ifdef SKIP_ASM
extern "C" void* func_00272308(void* heap, int size);
extern int D_004A3488;

// PORT: real arity is (size, heap); the unit declares func_00272488(void*) for its callers.
extern "C" void* func_00272488_impl(int size, void* heap) __asm__("func_00272488");
extern "C" void* func_00272488_impl(int size, void* heap)
{
    void** p = (void**)func_00272308(heap, size + D_004A3488);
    *p = heap;
    return (char*)p + D_004A3488;
}
#endif

extern "C" void* func_00272488(void* self);

//99.29%
INCLUDE_ASM("replay/replaycache", func_002724C8__FPv);
#ifdef SKIP_ASM
void* func_002724C8(void* self)
{
    return func_00272488(self);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002724E8);
#ifdef SKIP_ASM
extern int D_004A3488;

// PORT: returns void; the unit declares func_002724E8 as returning void*.
extern "C" void func_002724E8_impl(void* p) __asm__("func_002724E8");
extern "C" void func_002724E8_impl(void* p)
{
    char* h = (char*)p - D_004A3488;
    func_002723A8(*(sRcHeap**)h, h);
}
#endif

extern "C" void* func_002724E8(void* self);

//99.29%
INCLUDE_ASM("replay/replaycache", func_00272510__FPv);
#ifdef SKIP_ASM
void* func_00272510(void* self)
{
    return func_002724E8(self);
}
#endif

INCLUDE_ASM("replay/replaycache", func_00272570);

//100%
INCLUDE_ASM("replay/replaycache", func_002725B8);
#ifdef SKIP_ASM
extern void* D_00481A10[];

extern "C" void* func_002725B8(void* self)
{
    *(void***)((char*)self + 0x4) = D_00481A10;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1c) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002725F0);
#ifdef SKIP_ASM
extern "C" float func_00272570(float* coef, float t);

struct sRcTrack25F0 {
    char pad_0x00[0x8];
    unsigned int* data;     // 0x8
    int key;                // 0xC
    unsigned int* cur;      // 0x10
    char* body;             // 0x14
    int field_0x18;         // 0x18
    float value;            // 0x1C
    char* extra;            // 0x20
    char* next;             // 0x24
};

extern "C" int func_002725F0(sRcTrack25F0* self, unsigned int* data, int key)
{
    char* body = (char*)data + 4;
    self->data = data;
    self->key = key;
    self->cur = data;
    self->body = body;
    self->field_0x18 = 0;
    if (data[0] >= 2) {
        self->next = body + *(unsigned short*)((char*)data + 4);
    } else {
        self->next = 0;
    }
    self->value = func_00272570((float*)(self->body + 4), 0.0f);
    char* b = self->body;
    if (*(unsigned short*)b >= 0x15) {
        self->extra = b + 0x14;
    } else {
        self->extra = 0;
    }
    return self->next != 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272680__FPv);
#ifdef SKIP_ASM
void func_00272680(void* self)
{
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1c) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002726A8);
#ifdef SKIP_ASM
extern "C" int func_002726A8(sRcTrack25F0* self, float t)
{
    char* n = self->next;
    if (n == 0) return 0;
    if ((float)*(unsigned short*)(n + 2) <= t) {
        self->body = n;
        self->extra = 0;
        self->field_0x18++;
        if (*(unsigned short*)n >= 0x15) self->extra = n + 0x14;
        if (self->field_0x18 == self->cur[0] - 1) {
            self->next = 0;
            self->value = func_00272570((float*)(self->body + 4), 0.0f);
            return 0;
        }
        self->next = self->body + *(unsigned short*)self->body;
    }
    char* b = self->body;
    self->value = func_00272570((float*)(b + 4), t - (float)*(unsigned short*)(b + 2));
    return 1;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272788);
#ifdef SKIP_ASM
extern "C" void* func_00274518(void* self);
// PORT: array new[] with a heap argument; same symbol as the unit's func_002724C8(void*).
void* operator new[](unsigned int size, void* heap) __asm__("func_002724C8__FPv");

struct sRcItem2788 {
    int field_0x0;              // 0x0
    unsigned int index;         // 0x4
    char body[0x48];            // 0x8
    sRcItem2788* next;          // 0x50
    sRcItem2788* prev;          // 0x54
    sRcItem2788() { func_00274518(body); }
    void operator delete[](void* p, unsigned int size);
};

struct sRcPool2788 {
    int tag;                    // 0x0
    unsigned int count;         // 0x4
    char heap[0xC];             // 0x8
    sRcItem2788* items;         // 0x14
    sRcItem2788* free;          // 0x18
    int used;                   // 0x1C
};

extern "C" sRcPool2788* func_00272788(sRcPool2788* self, void* a1, void* a2, unsigned int count, int tag)
{
    func_002722E0(self->heap, a1, a2);
    self->tag = tag;
    self->count = count;
    self->items = 0;
    self->free = 0;
    sRcItem2788** slot = &self->items;
    *slot = new (self->heap) sRcItem2788[count];
    for (unsigned int i = 0; i < self->count; i++) {
        self->items[i].index = i;
        self->items[i].next = &self->items[i + 1];
        self->items[i].prev = &self->items[i - 1];
    }
    self->items[0].prev = 0;
    self->items[self->count - 1].next = 0;
    self->used = 0;
    self->free = self->items;
    return self;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002728D0);
#ifdef SKIP_ASM
void operator_delete(int* p);

// Deleting-destructor tail: free self when bit 0 of the g++ 2.95 in-charge flag is set.
extern "C" void func_002728D0(int* self, int flags)
{
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002728F8);
#ifdef SKIP_ASM
extern "C" void func_00274A30(void* p);

extern "C" void func_002728F8(void* self)
{
    char* n = *(char**)((char*)self + 0x1C);
    while (n != 0) {
        func_00274A30(n + 8);
        n = *(char**)(n + 0x50);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272938);
#ifdef SKIP_ASM
extern "C" void* func_002745C0(void* data, void* src, void* owner, int id);

struct sRcNode272938 {
    int unk_0x0;
    int id;
    char data[0x48];
    sRcNode272938* next;
    sRcNode272938* prev;
};

struct sRcList272938 {
    char pad_0x00[0x18];
    sRcNode272938* freeHead;
    sRcNode272938* usedHead;
};

extern "C" int func_00272938(sRcList272938* self, void* src)
{
    sRcNode272938* n = self->freeHead;
    self->freeHead = n->next;
    n->next = 0;
    if (self->freeHead != 0) {
        self->freeHead->prev = 0;
    }
    func_002745C0(n->data, src, self, n->id);
    n->next = self->usedHead;
    if (self->usedHead != 0) {
        self->usedHead->prev = n;
    }
    self->usedHead = n;
    return n->id;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002729A8);
#ifdef SKIP_ASM
extern "C" void func_00272B58(void* self, int a1);
extern "C" void func_002746F8(void* p);

extern "C" void func_002729A8(sRcList272938* self, int i)
{
    func_00272B58(self, i);
    char* base = *(char**)((char*)self + 0x14);
    sRcNode272938* n = (sRcNode272938*)(base + i * 0x58);
    func_002746F8(n->data);
    if (n->prev == 0) {
        self->usedHead = n->next;
        n->next = 0;
        if (self->usedHead != 0) {
            self->usedHead->prev = 0;
        }
    } else {
        n->prev->next = n->next;
        if (n->next != 0) {
            n->next->prev = n->prev;
        }
        n->next = 0;
        n->prev = 0;
    }
    n->next = self->freeHead;
    if (self->freeHead != 0) {
        self->freeHead->prev = n;
    }
    self->freeHead = n;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272AD0);
#ifdef SKIP_ASM
extern "C" void* func_00274830(void*, int);
extern "C" void* func_00272CC0(void* self, int a1);

extern "C" void* func_00272AD0(void* self, int a1, int a2)
{
    return func_00274830(func_00272CC0(self, a1), a2);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272B58);
#ifdef SKIP_ASM
extern "C" void* func_00272CC0(void* self, int a1);
extern "C" void func_00274918(void* p);

extern "C" void func_00272B58(void* self, int a1)
{
    func_00274918(func_00272CC0(self, a1));
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272CC0);
#ifdef SKIP_ASM
extern "C" void* func_00272CC0(void* self, int a1)
{
    char* base = *(char**)((char*)self + 0x14);
    char* p = base + a1 * 0x58;
    return *(int*)(p + 0xc) != 0 ? p + 0x8 : 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00272D68);
#ifdef SKIP_ASM
extern void* D_004819B0[];

extern "C" void* func_00272D68(void* self)
{
    *(void***)((char*)self + 0x4) = D_004819B0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    *(int*)((char*)self + 0x28) = 0;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00272DA0);
#ifdef SKIP_ASM
extern "C" void func_00272EC0(void* self);
extern "C" void* func_002724E8(void* self);
extern void* D_004819B0[];

extern "C" void func_00272DA0(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004819B0;
    func_00272EC0(self);
    if (flags & 1) {
        func_002724E8(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00272DF0);
#ifdef SKIP_ASM
struct sCacheRecord;
struct sCacheEntry;
extern "C" void* func_00272308(void* heap, int size);
extern "C" sCacheEntry* func_002730C0(void* self, sCacheRecord* rec);
extern "C" void func_00273140(void* self);

extern "C" int func_00272DF0(void* self, unsigned short* data, void* owner, int* flags)
{
    *(unsigned short**)((char*)self + 0x8) = data;
    *(void**)((char*)self + 0xC) = owner;
    *(unsigned short**)((char*)self + 0x10) = data;
    if (data[0] != 0) {
        char* heap = *(char**)(*(char**)((char*)owner + 0x8) + 0x8);
        *(void**)((char*)self + 0x20) = func_00272308(heap + 8, data[1] * 0x1C);
        *(int*)((char*)self + 0x18) = 0;
        char* base = *(char**)((char*)self + 0x10);
        *(char**)((char*)self + 0x14) = base + 4;
        if (base + 4 != 0 && *(unsigned short*)(base + 8) == 0) do {
            *flags |= 4;
            func_002730C0(self, *(sCacheRecord**)((char*)self + 0x14));
            func_00273140(self);
        } while (*(char**)((char*)self + 0x14) != 0 &&
               *(unsigned short*)(*(char**)((char*)self + 0x14) + 4) == 0);
    }
    return **(unsigned short**)((char*)self + 0x10) != 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00272EC0);
#ifdef SKIP_ASM
extern "C" void func_00272EC0(void* self)
{
    char* owner = *(char**)((char*)self + 0xC);
    if (owner != 0) {
        void* p = *(void**)((char*)self + 0x20);
        if (p != 0) {
            func_002723A8((sRcHeap*)(*(char**)(*(char**)(owner + 0x8) + 0x8) + 0x8), p);
        }
        *(int*)((char*)self + 0x8) = 0;
        *(int*)((char*)self + 0xC) = 0;
        *(int*)((char*)self + 0x10) = 0;
        *(int*)((char*)self + 0x14) = 0;
        *(int*)((char*)self + 0x18) = 0;
        *(int*)((char*)self + 0x20) = 0;
        *(int*)((char*)self + 0x24) = 0;
        *(int*)((char*)self + 0x28) = 0;
    }
}
#endif

INCLUDE_ASM("replay/replaycache", func_00272F28);

//100%
INCLUDE_ASM("replay/replaycache", func_00273040);
#ifdef SKIP_ASM
struct sCacheTimeNode {
    char pad[0xC];
    int time;
    char pad2[0x18 - 0x10];
    sCacheTimeNode* next;
};

extern "C" int func_00273040(void* self)
{
    if (*(int*)((char*)self + 0x8) == 0) {
        return -1;
    }
    if (**(unsigned short**)((char*)self + 0x10) == 0) {
        return -1;
    }
    int best = -1;
    sCacheTimeNode* n = *(sCacheTimeNode**)((char*)self + 0x24);
    unsigned short* cur = *(unsigned short**)((char*)self + 0x14);
    for (; n != 0; n = n->next) {
        int t = n->time;
        if (best < 0 || t < best) {
            best = t;
        }
    }
    if (cur != 0) {
        int t = cur[2];
        if (best < 0 || t < best) {
            best = t;
        }
    }
    return best;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002730C0);
#ifdef SKIP_ASM
struct sCacheRecord {
    unsigned short size;
    unsigned short id;
    unsigned short a;
    unsigned short b;
    int x;
    int y;
};

struct sCacheEntry {
    int x;
    int id;
    int a;
    int b;
    int y;
    sCacheRecord* data;
    sCacheEntry* next;
};

extern "C" sCacheEntry* func_002730C0(void* self, sCacheRecord* rec)
{
    sCacheEntry* e = (sCacheEntry*)(*(char**)((char*)self + 0x20) + rec->id * 0x1C);
    e->x = rec->x;
    e->id = rec->id;
    e->y = rec->y;
    e->a = rec->a;
    e->b = rec->b;
    e->data = 0;
    if (rec->size > 0x10) {
        e->data = rec + 1;
    }
    e->next = *(sCacheEntry**)((char*)self + 0x24);
    *(sCacheEntry**)((char*)self + 0x24) = e;
    (*(int*)((char*)self + 0x28))++;
    return e;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273140);
#ifdef SKIP_ASM
extern "C" void func_00273140(void* self)
{
    int idx = *(int*)((char*)self + 0x18);
    if (idx == **(unsigned short**)((char*)self + 0x10) - 1) {
        *(char**)((char*)self + 0x14) = 0;
    } else {
        char* cur = *(char**)((char*)self + 0x14);
        *(char**)((char*)self + 0x14) = cur + *(unsigned short*)cur;
        *(int*)((char*)self + 0x18) = idx + 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273180);
#ifdef SKIP_ASM
extern void* D_00481950[];

extern "C" void* func_00273180(void* self)
{
    *(void***)((char*)self + 0x4) = D_00481950;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1c) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002731B8);
#ifdef SKIP_ASM
extern "C" void func_002732C8(void* self);
extern "C" void* func_002724E8(void* self);
extern void* D_00481950[];

extern "C" void func_002731B8(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00481950;
    func_002732C8(self);
    if (flags & 1) {
        func_002724E8(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00273208);
#ifdef SKIP_ASM
struct sCacheRec;
struct sCacheRef;
extern "C" void* func_00272308(void* heap, int size);
extern "C" sCacheRef* func_00273418(void* self, sCacheRec* rec);
extern "C" void func_00273468(void* self);

extern "C" int func_00273208(void* self, unsigned short* data, void* owner, int* flags)
{
    *(unsigned short**)((char*)self + 0x8) = data;
    *(void**)((char*)self + 0xC) = owner;
    *(unsigned short**)((char*)self + 0x10) = data;
    if (data[0] != 0) {
        char* heap = *(char**)(*(char**)((char*)owner + 0x8) + 0x8);
        *(void**)((char*)self + 0x1C) = func_00272308(heap + 8, data[1] * 8);
        *(int*)((char*)self + 0x18) = 0;
        char* base = *(char**)((char*)self + 0x10);
        *(char**)((char*)self + 0x14) = base + 4;
        if (base + 4 != 0 && *(unsigned short*)(base + 6) == 0) do {
            *flags |= 0x10;
            func_00273418(self, *(sCacheRec**)((char*)self + 0x14));
            func_00273468(self);
            *(int*)((char*)self + 0x24) = 0;
        } while (*(char**)((char*)self + 0x14) != 0 &&
               *(unsigned short*)(*(char**)((char*)self + 0x14) + 2) == 0);
    }
    return *(char**)((char*)self + 0x14) != 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002732C8);
#ifdef SKIP_ASM
extern "C" void func_002732C8(void* self)
{
    char* owner = *(char**)((char*)self + 0xC);
    if (owner != 0) {
        void* p = *(void**)((char*)self + 0x1C);
        if (p != 0) {
            func_002723A8((sRcHeap*)(*(char**)(*(char**)(owner + 0x8) + 0x8) + 0x8), p);
        }
        *(int*)((char*)self + 0x8) = 0;
        *(int*)((char*)self + 0xC) = 0;
        *(int*)((char*)self + 0x10) = 0;
        *(int*)((char*)self + 0x14) = 0;
        *(int*)((char*)self + 0x18) = 0;
        *(int*)((char*)self + 0x1C) = 0;
        *(int*)((char*)self + 0x20) = 0;
        *(int*)((char*)self + 0x24) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273330);
#ifdef SKIP_ASM
struct sCacheRec;
struct sCacheRef;
extern "C" sCacheRef* func_00273418(void* self, sCacheRec* rec);
extern "C" void func_00273468(void* self);

extern "C" int func_00273330(void* self, int* flags, float t)
{
    if (*(float*)((char*)self + 0x24) != t) {
        *(int*)((char*)self + 0x20) = 0;
    }
    while (*(char**)((char*)self + 0x14) != 0) {
        float v = (float)*(unsigned short*)(*(char**)((char*)self + 0x14) + 2);
        if (t < v) break;
        *flags |= 0x10;
        func_00273418(self, *(sCacheRec**)((char*)self + 0x14));
        *(float*)((char*)self + 0x24) = v;
        func_00273468(self);
    }
    return *(char**)((char*)self + 0x14) != 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002733E0);
#ifdef SKIP_ASM
extern "C" int func_002733E0(void* self)
{
    if (*(int*)((char*)self + 0x8) == 0) {
        return -1;
    }
    if (**(unsigned short**)((char*)self + 0x10) == 0) {
        return -1;
    }
    unsigned short* cur = *(unsigned short**)((char*)self + 0x14);
    int r = -1;
    if (cur) {
        r = cur[1];
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273418);
#ifdef SKIP_ASM
struct sCacheRef {
    int key;
    void* data;
};

struct sCacheRec {
    unsigned short size;
    unsigned short pad;
    int key;
};

extern "C" sCacheRef* func_00273418(void* self, sCacheRec* rec)
{
    sCacheRef* e = &(*(sCacheRef**)((char*)self + 0x1c))[*(int*)((char*)self + 0x20)];
    e->key = rec->key;
    e->data = 0;
    if (rec->size > 8) {
        e->data = (char*)rec + 8;
    }
    *(int*)((char*)self + 0x20) += 1;
    return e;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273468);
#ifdef SKIP_ASM
extern "C" void func_00273468(void* self)
{
    int idx = *(int*)((char*)self + 0x18);
    if (idx == **(unsigned short**)((char*)self + 0x10) - 1) {
        *(char**)((char*)self + 0x14) = 0;
    } else {
        char* cur = *(char**)((char*)self + 0x14);
        *(char**)((char*)self + 0x14) = cur + *(unsigned short*)cur;
        *(int*)((char*)self + 0x18) = idx + 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002734A8);
#ifdef SKIP_ASM
extern void* D_004818F0[];

extern "C" void* func_002734A8(void* self)
{
    *(void***)((char*)self + 0x4) = D_004818F0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1c) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002734E0);
#ifdef SKIP_ASM
extern "C" void func_00273630(void* self);
extern "C" void* func_002724E8(void* self);
extern void* D_004818F0[];

extern "C" void func_002734E0(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004818F0;
    func_00273630(self);
    if (flags & 1) {
        func_002724E8(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00273530);
#ifdef SKIP_ASM
extern "C" void* func_00272308(void* heap, int size);
struct sCacheRecord2;
struct sCacheEntry2;
extern "C" sCacheEntry2* func_00273860(void* self, sCacheRecord2* rec);
extern "C" void func_002738F8(void* self);

extern "C" int func_00273530(void* self, unsigned short* data, void* owner, int* flags)
{
    *(unsigned short**)((char*)self + 0x8) = data;
    *(void**)((char*)self + 0xC) = owner;
    *(unsigned short**)((char*)self + 0x10) = data;
    if (data[0] != 0) {
        char* heap = *(char**)(*(char**)((char*)owner + 0x8) + 0x8);
        *(void**)((char*)self + 0x1C) = func_00272308(heap + 8, data[1] * 0x24);
        for (int i = 0; i < (*(unsigned short**)((char*)self + 0x10))[1]; i++) {
        }
        *(int*)((char*)self + 0x18) = 0;
        char* base = *(char**)((char*)self + 0x10);
        *(char**)((char*)self + 0x14) = base + 4;
        if (base + 4 != 0 && *(unsigned short*)(base + 8) == 0) do {
            *flags |= 1;
            func_00273860(self, *(sCacheRecord2**)((char*)self + 0x14));
            func_002738F8(self);
        } while (*(char**)((char*)self + 0x14) != 0 &&
               *(unsigned short*)(*(char**)((char*)self + 0x14) + 4) == 0);
    }
    return **(unsigned short**)((char*)self + 0x10) != 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00273630);
#ifdef SKIP_ASM
extern "C" void func_00273630(void* self)
{
    char* owner = *(char**)((char*)self + 0xC);
    if (owner != 0) {
        void* p = *(void**)((char*)self + 0x1C);
        if (p != 0) {
            func_002723A8((sRcHeap*)(*(char**)(*(char**)(owner + 0x8) + 0x8) + 0x8), p);
        }
        *(int*)((char*)self + 0x8) = 0;
        *(int*)((char*)self + 0xC) = 0;
        *(int*)((char*)self + 0x10) = 0;
        *(int*)((char*)self + 0x14) = 0;
        *(int*)((char*)self + 0x18) = 0;
        *(int*)((char*)self + 0x1C) = 0;
        *(int*)((char*)self + 0x20) = 0;
        *(int*)((char*)self + 0x24) = 0;
    }
}
#endif

INCLUDE_ASM("replay/replaycache", func_00273698);

//100%
INCLUDE_ASM("replay/replaycache", func_002737E0);
#ifdef SKIP_ASM
struct sCacheTimeNode2 {
    char pad[0x8];
    int time;
    char pad2[0x20 - 0xC];
    sCacheTimeNode2* next;
};

extern "C" int func_002737E0(void* self)
{
    if (*(int*)((char*)self + 0x8) == 0) {
        return -1;
    }
    if (**(unsigned short**)((char*)self + 0x10) == 0) {
        return -1;
    }
    int best = -1;
    sCacheTimeNode2* n = *(sCacheTimeNode2**)((char*)self + 0x20);
    unsigned short* cur = *(unsigned short**)((char*)self + 0x14);
    for (; n != 0; n = n->next) {
        int t = n->time;
        if (best < 0 || t < best) {
            best = t;
        }
    }
    if (cur != 0) {
        int t = cur[2];
        if (best < 0 || t < best) {
            best = t;
        }
    }
    return best;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273860);
#ifdef SKIP_ASM
struct sCacheRecord2 {
    unsigned short size;
    unsigned short id;
    unsigned short a;
    unsigned short b;
    int x;
    int ix;
    float f;
    int y;
};

struct sCacheEntry2 {
    int x;
    int a;
    int b;
    int id;
    float fx;
    float f;
    int y;
    sCacheRecord2* data;
    sCacheEntry2* next;
};

extern "C" sCacheEntry2* func_00273860(void* self, sCacheRecord2* rec)
{
    sCacheEntry2* e = (sCacheEntry2*)(*(char**)((char*)self + 0x1C) + rec->id * 0x24);
    e->x = rec->x;
    e->y = rec->y;
    e->fx = rec->ix;
    e->f = rec->f;
    e->id = rec->id;
    e->a = rec->a;
    e->b = rec->b;
    e->data = 0;
    if (rec->size > 0x18) {
        e->data = rec + 1;
    }
    e->next = *(sCacheEntry2**)((char*)self + 0x20);
    *(sCacheEntry2**)((char*)self + 0x20) = e;
    (*(int*)((char*)self + 0x24))++;
    return e;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002738F8);
#ifdef SKIP_ASM
extern "C" void func_002738F8(void* self)
{
    int idx = *(int*)((char*)self + 0x18);
    if (idx == **(unsigned short**)((char*)self + 0x10) - 1) {
        *(char**)((char*)self + 0x14) = 0;
    } else {
        char* cur = *(char**)((char*)self + 0x14);
        *(char**)((char*)self + 0x14) = cur + *(unsigned short*)cur;
        *(int*)((char*)self + 0x18) = idx + 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273938);
#ifdef SKIP_ASM
extern "C" void* func_00273938(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1c) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x2c) = 0;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00273970);
#ifdef SKIP_ASM
extern "C" void func_00273A00(void* self);

extern "C" void func_00273970(void* self, int flags)
{
    func_00273A00(self);
    if (flags & 1) {
        func_002724E8(self);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002739B8);
#ifdef SKIP_ASM
extern "C" int func_002739B8(void* self, char* data, int size)
{
    *(char**)((char*)self + 0x4) = data;
    *(char**)((char*)self + 0x10) = data;
    *(int*)((char*)self + 0x8) = size;
    *(char**)((char*)self + 0x14) = data + 8;
    *(int*)((char*)self + 0x18) = 0;
    char* rec = data + *(int*)(data + 8);
    *(char**)((char*)self + 0x1c) = rec;
    if (*(unsigned short*)rec > 8) {
        *(char**)((char*)self + 0x20) = rec + 8;
    } else {
        *(char**)((char*)self + 0x20) = 0;
    }
    return **(int**)((char*)self + 0x10);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273A00);
#ifdef SKIP_ASM
extern "C" void func_00273DC0(void* self);

extern "C" void func_00273A00(void* self)
{
    if (*(int*)((char*)self + 0x4) != 0) {
        func_00273DC0(self);
        *(int*)((char*)self + 0x4) = 0;
        *(int*)((char*)self + 0x8) = 0;
        *(int*)((char*)self + 0xC) = 0;
        *(int*)((char*)self + 0x10) = 0;
        *(int*)((char*)self + 0x14) = 0;
        *(int*)((char*)self + 0x18) = 0;
        *(int*)((char*)self + 0x1C) = 0;
        *(int*)((char*)self + 0x20) = 0;
        *(int*)((char*)self + 0x30) = 0;
        *(int*)((char*)self + 0x34) = 0;
        *(int*)((char*)self + 0x38) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273A60);
#ifdef SKIP_ASM
extern "C" void func_00273A60(void* self, int idx)
{
    *(int*)((char*)self + 0x18) = idx;
    char* rec = *(char**)((char*)self + 0x4) + (*(int**)((char*)self + 0x14))[idx];
    *(char**)((char*)self + 0x1c) = rec;
    if (*(unsigned short*)rec > 8) {
        *(char**)((char*)self + 0x20) = rec + 8;
    } else {
        *(char**)((char*)self + 0x20) = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00273AA8);
#ifdef SKIP_ASM
extern "C" void* func_00272308(void* heap, int size);
// PORT: real arity is (size, heap); the unit declares func_00272488(void*) for its callers.
extern "C" void* func_00272488_impl(int size, void* heap) __asm__("func_00272488");
extern "C" void* func_002725B8(void* self);
extern "C" void* func_00272D68(void* self);
extern "C" void* func_00273180(void* self);
extern "C" void* func_002734A8(void* self);
extern "C" int func_00274D70(void* self);

struct sRcVE_273AA8 {
    short delta;
    short index;
    int (*fn)(void*, void*, void*, int*);
};

struct sRcVE2_273AA8 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};

struct sRcVE3_273AA8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sRcHdr_273AA8 {
    unsigned short first;   // 0x0
    unsigned char count;    // 0x2
    unsigned char kind;     // 0x3
};

struct sRcRec_273AA8 {
    unsigned short type;    // 0x0
    unsigned short size;    // 0x2
};

struct sRcObj_273AA8 {
    int f0;
    sRcVE_273AA8* vt;       // 0x4
};

struct sRcCache_273AA8 {
    char pad0[0x8];
    char* owner;            // 0x8
    char padC[0x1C - 0xC];
    sRcHdr_273AA8* hdr;     // 0x1C
    char pad20[0x24 - 0x20];
    sRcObj_273AA8** objs;   // 0x24
    int ready;              // 0x28
    char* player;           // 0x2C
    int done;               // 0x30
    int flags;              // 0x34
    int started;            // 0x38
};

extern "C" int func_00273AA8(sRcCache_273AA8* self)
{
    self->done = 0;
    self->flags = 0;
    if (self->hdr->count) {
        void* heap = *(char**)(self->owner + 8) + 8;
        self->objs = (sRcObj_273AA8**)func_00272308(heap, self->hdr->count * 4);
        char* p = (char*)self->hdr + self->hdr->first;
        for (int i = 0; i < self->hdr->count; i++) {
            sRcRec_273AA8* e = (sRcRec_273AA8*)p;
            p += 4;
            switch (e->type) {
            case 0: {
                sRcObj_273AA8** slot = (sRcObj_273AA8**)((i << 2) + (int)self->objs);
                *slot = (sRcObj_273AA8*)func_002725B8(func_00272488_impl(0x28, heap));
                break;
            }
            case 1: {
                sRcObj_273AA8** slot = (sRcObj_273AA8**)((i << 2) + (int)self->objs);
                *slot = (sRcObj_273AA8*)func_002734A8(func_00272488_impl(0x28, heap));
                break;
            }
            case 2: {
                sRcObj_273AA8** slot = (sRcObj_273AA8**)((i << 2) + (int)self->objs);
                *slot = (sRcObj_273AA8*)func_00272D68(func_00272488_impl(0x2C, heap));
                break;
            }
            case 3: {
                sRcObj_273AA8** slot = (sRcObj_273AA8**)((i << 2) + (int)self->objs);
                *slot = (sRcObj_273AA8*)func_00273180(func_00272488_impl(0x28, heap));
                break;
            }
            }
            int flag = 0;
            int* pd = &self->done;
            int r = 0;
            sRcObj_273AA8* o = self->objs[i];
            if (o->vt[1].fn((char*)o + o->vt[1].delta, p, self, &flag) || self->done)
                r = 1;
            *pd = r;
            self->flags |= flag;
            p += e->size;
        }
    }
    self->ready = 1;
    char* x = (char*)func_00274D70(self->owner);
    if (x) {
        sRcVE2_273AA8* vt = *(sRcVE2_273AA8**)x;
        self->player = (char*)vt[6].fn(x + vt[6].delta, self, self->hdr->kind);
    }
    if (self->player) {
        char* pl = self->player;
        sRcVE3_273AA8* vt = *(sRcVE3_273AA8**)pl;
        vt[1].fn(pl + vt[1].delta, self, self->hdr->kind);
    }
    self->started = 1;
    return self->ready;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273D20);
#ifdef SKIP_ASM
class cRcListener3D20 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03(void* src, int id, int h, float t);
    virtual void v04(void* src, int id, int h, float t0, float t1);
};

extern "C" int func_00273D20(void* self)
{
    cRcListener3D20* obj = *(cRcListener3D20**)((char*)self + 0x2C);
    int ret = *(int*)((char*)self + 0x30);
    if (obj != 0) {
        int h = *(int*)((char*)self + 0x34);
        if (h != 0) {
            obj->v03(self, *(unsigned char*)(*(char**)((char*)self + 0x1C) + 3), h, 0.0f);
        }
        (*(cRcListener3D20**)((char*)self + 0x2C))->v04(self,
            *(unsigned char*)(*(char**)((char*)self + 0x1C) + 3),
            *(int*)((char*)self + 0x34), 0.0f, 0.0f);
    }
    *(int*)((char*)self + 0x30) = 0;
    *(int*)((char*)self + 0x34) = 0;
    *(int*)((char*)self + 0x38) = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273DC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_002724E8_impl(void* p) __asm__("func_002724E8");
extern "C" void func_002723A8(sRcHeap* h, void* p);

class cRcObj_3DC0 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
    virtual void v08();
    virtual void v09();
    virtual void v10(int);
};

class cRcListener_3DC0 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* src, int id);
    virtual void v02(void* src, int id);
};

extern "C" void func_00273DC0(void* self)
{
    if (*(int*)((char*)self + 0x28) == 0)
        return;
    cRcListener_3DC0* l = *(cRcListener_3DC0**)((char*)self + 0x2C);
    if (l != 0)
        l->v02(self, *(unsigned char*)(*(char**)((char*)self + 0x1C) + 3));
    *(void**)((char*)self + 0x2C) = 0;
    if (*(unsigned char*)(*(char**)((char*)self + 0x1C) + 2) != 0)
    {
        for (int i = 0; i < *(unsigned char*)(*(char**)((char*)self + 0x1C) + 2); i++)
        {
            cRcObj_3DC0** objs = *(cRcObj_3DC0***)((char*)self + 0x24);
            objs[i]->v02();
            switch ((*(cRcObj_3DC0***)((char*)self + 0x24))[i]->v07())
            {
            case 0:
                func_002724E8_impl((*(cRcObj_3DC0***)((char*)self + 0x24))[i]);
                break;
            case 1:
            {
                cRcObj_3DC0* o = (*(cRcObj_3DC0***)((char*)self + 0x24))[i];
                if (o)
                    o->v10(3);
                break;
            }
            case 2:
            {
                cRcObj_3DC0* o = (*(cRcObj_3DC0***)((char*)self + 0x24))[i];
                if (o)
                    o->v10(3);
                break;
            }
            case 3:
            {
                cRcObj_3DC0* o = (*(cRcObj_3DC0***)((char*)self + 0x24))[i];
                if (o)
                    o->v10(3);
                break;
            }
            }
        }
        func_002723A8((sRcHeap*)(*(char**)(*(char**)((char*)self + 0x8) + 0x8) + 8), *(void**)((char*)self + 0x24));
        *(void**)((char*)self + 0x24) = 0;
    }
    *(int*)((char*)self + 0x28) = 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00273F68);
#ifdef SKIP_ASM
class cRcObj_3F68 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual int v01(void* data, void* cache, int* mask);
    virtual void v02();
};

extern "C" int func_00273F68(void* self)
{
    if (*(int*)((char*)self + 0x28) == 0)
        return 0;
    unsigned char* hdr = *(unsigned char**)((char*)self + 0x1C);
    int mask = 0;
    int i = 0;
    int changed = 0;
    unsigned char* p = hdr + *(unsigned short*)hdr;
    if (hdr[2] != 0)
    {
        do
        {
            unsigned char* rec = p;
            int ch = 0;
            p += 4;
            (*(cRcObj_3F68***)((char*)self + 0x24))[i]->v02();
            int m = 0;
            if ((*(cRcObj_3F68***)((char*)self + 0x24))[i]->v01(p, self, &m) != 0 || changed)
                ch = 1;
            i++;
            p += *(unsigned short*)(rec + 2);
            changed = ch;
            mask |= m;
        } while (i < (*(unsigned char**)((char*)self + 0x1C))[2]);
    }
    cRcListener3D20* l = *(cRcListener3D20**)((char*)self + 0x2C);
    if (l == 0)
        return changed;
    if (mask)
        l->v03(self, *(unsigned char*)(*(char**)((char*)self + 0x1C) + 3), mask, 0.0f);
    (*(cRcListener3D20**)((char*)self + 0x2C))->v04(self, *(unsigned char*)(*(char**)((char*)self + 0x1C) + 3), mask, 0.0f, 0.0f);
    return changed;
}
#endif

INCLUDE_ASM("replay/replaycache", func_00274100);

//100%
INCLUDE_ASM("replay/replaycache", func_00274240);
#ifdef SKIP_ASM
class cRcListener4240 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* src, int id);
    virtual void v02(void* src, int id);
};

extern "C" cRcListener4240* func_00274240(void* self, cRcListener4240* l)
{
    cRcListener4240* old = *(cRcListener4240**)((char*)self + 0x2C);
    if (old != 0) {
        old->v02(self, *(unsigned char*)(*(char**)((char*)self + 0x1C) + 3));
    }
    *(cRcListener4240**)((char*)self + 0x2C) = l;
    if (l != 0) {
        l->v01(self, *(unsigned char*)(*(char**)((char*)self + 0x1C) + 3));
    }
    return old;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002742C8__FPvi);
#ifdef SKIP_ASM
int func_002742C8(void* self, int a1)
{
    return *(int*)((char*)*(void**)((char*)self + 0x24) + a1 * 4);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002742E0);
#ifdef SKIP_ASM
extern "C" void* func_002742E0(void* self, int i)
{
    int* table = *(int**)((char*)self + 0x14);
    char* p = *(char**)((char*)self + 0x4) + table[i];
    if (*(unsigned short*)p > 8) {
        return p + 8;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274348__FPv);
#ifdef SKIP_ASM
int func_00274348(void* self)
{
    return *(int*)((char*)*(void**)((char*)self + 0x1c) + 0x4);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274388__FPv);
#ifdef SKIP_ASM
int func_00274388(void* self)
{
    return *(int*)((char*)*(void**)((char*)self + 0x10) + 0x4);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002743C8__FPv);
#ifdef SKIP_ASM
unsigned char func_002743C8(void* self)
{
    return *(unsigned char*)((char*)*(void**)((char*)self + 0x1c) + 0x3);
}
#endif

INCLUDE_ASM("replay/replaycache", func_002743E8);

//100%
INCLUDE_ASM("replay/replaycache", func_00274518);
#ifdef SKIP_ASM
extern "C" void* func_00274518(void* self)
{
    *(int*)((char*)self + 0x0) = -1;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(float*)((char*)self + 0x24) = 1.0f;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x30) = -1;
    *(int*)((char*)self + 0x34) = -1;
    *(int*)((char*)self + 0x38) = 0;
    *(int*)((char*)self + 0x3C) = 0;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002745C0);
#ifdef SKIP_ASM
// PORT: array new[] with a heap argument; same symbol as the unit's func_002724C8(void*).
void* operator new[](unsigned int size, void* heap) __asm__("func_002724C8__FPv");

struct sRcElem45C0 {
    char pad_0x0[0x3C];
    sRcElem45C0() { func_00273938(this); }
    void operator delete[](void* p, unsigned int size);
};

struct sRcHdr45C0 {
    unsigned char field_0x0;
    unsigned char count;    // 0x1
    unsigned short size;    // 0x2
    int field_0x4;
    int result;             // 0x8
};

struct sRcStream45C0 {
    int field_0x0;          // 0x0
    sRcHdr45C0* data;       // 0x4
    char* owner;            // 0x8
    char pad_0xC[0x4];
    sRcHdr45C0* hdr;        // 0x10
    char* ext;              // 0x14
    sRcElem45C0* elems;     // 0x18
    int field_0x1C;         // 0x1C
    char pad_0x20[0x14];
    int field_0x34;         // 0x34
    int field_0x38;         // 0x38
};

// PORT: func_002739B8's third argument receives the owning stream pointer as an int.
// PORT: the unit declares func_002745C0 as returning void*; it returns the header word.
extern "C" int func_002745C0_impl(sRcStream45C0* self, sRcHdr45C0* data, char* owner, int a3) __asm__("func_002745C0");
extern "C" int func_002745C0_impl(sRcStream45C0* self, sRcHdr45C0* data, char* owner, int a3)
{
    self->field_0x0 = a3;
    self->owner = owner;
    self->data = data;
    self->hdr = data;
    self->field_0x34 = -1;
    self->field_0x38 = 0;
    self->field_0x1C = 0;
    if (data->size >= 0xD) {
        self->ext = (char*)data + 0xC;
    }
    char* p = (char*)data + self->hdr->size;
    if (self->hdr->count != 0) {
        sRcElem45C0** slot = &self->elems;
        *slot = new (owner + 8) sRcElem45C0[self->hdr->count];
        for (int i = 0; i < self->hdr->count; i++) {
            p += func_002739B8(&self->elems[i], p, (int)self);
        }
    }
    return self->hdr->result;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002746F8);
#ifdef SKIP_ASM
extern "C" void func_00273970(void* self, int flags);
void* func_00272510(void* self);

struct sRcElem46F8 {
    char pad_0x0[0x3C];
};

struct sRcHdr46F8 {
    unsigned char field_0x0;
    unsigned char count;    // 0x1
};

struct sRcStream46F8 {
    int field_0x0;          // 0x0
    void* data;             // 0x4
    void* owner;            // 0x8
    int field_0xC;          // 0xC
    sRcHdr46F8* hdr;        // 0x10
    char* ext;              // 0x14
    sRcElem46F8* elems;     // 0x18
    int field_0x1C;         // 0x1C
    int field_0x20;         // 0x20
    float field_0x24;       // 0x24
    int field_0x28;         // 0x28
    int field_0x2C;         // 0x2C
    int field_0x30;         // 0x30
    int field_0x34;         // 0x34
    int field_0x38;         // 0x38
};

extern "C" void func_002746F8(void* p)
{
    sRcStream46F8* self = (sRcStream46F8*)p;
    if (self->data == 0) {
        return;
    }
    func_00274918(self);
    for (int i = 0; i < self->hdr->count; i++) {
        func_00273A00(&self->elems[i]);
    }
    // delete[] self->elems (element count in the 16-byte array cookie)
    sRcElem46F8* e = self->elems;
    if (e != 0) {
        sRcElem46F8* q = e + *(int*)((char*)e - 0x10);
        while (self->elems != q) {
            q--;
            func_00273970(q, 0);
        }
        func_00272510((char*)self->elems - 0x10);
    }
    self->field_0x38 = 0;
    self->field_0x0 = -1;
    self->data = 0;
    self->owner = 0;
    self->field_0xC = 0;
    self->hdr = 0;
    self->ext = 0;
    self->elems = 0;
    self->field_0x1C = 0;
    self->field_0x20 = 0;
    self->field_0x28 = 0;
    self->field_0x2C = 0;
    self->field_0x30 = -1;
    self->field_0x24 = 1.0f;
    self->field_0x34 = -1;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274808__FPvf);
#ifdef SKIP_ASM
void func_00274808(void* self, float val)
{
    *(float*)((char*)self + 0x24) = val;
}
#endif

extern "C" void* func_00274830(void*, int);

//100%
INCLUDE_ASM("replay/replaycache", func_00274810__FPv);
#ifdef SKIP_ASM
void* func_00274810(void* self)
{
    return func_00274830(self, *(int*)((char*)self + 0x1c));
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274830);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// the unit declares this as returning void*; the body returns nothing,
// so bind a void body to the symbol
void func_00274830_impl(void* self, int a1) __asm__("func_00274830");

void func_00274830_impl(void* self, int a1)
{
    if (*(int*)((char*)self + 0x20) != 0) {
        if (*(int*)((char*)self + 0x3c) != 0) {
            *(int*)((char*)self + 0x40) = 0;
        }
    } else {
        *(int*)((char*)self + 0x1c) = a1;
        *(int*)((char*)self + 0x20) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274918);
#ifdef SKIP_ASM
extern "C" void func_00273DC0(void* self);
extern "C" int func_00274D70(void* self);

class cRcListener4918 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(void* src);
};

extern "C" void func_00274918(void* self)
{
    if (*(int*)((char*)self + 0x20) == 0) return;
    if (*(int*)((char*)self + 0x3C) != 0) {
        *(int*)((char*)self + 0x40) = 1;
        return;
    }
    for (int i = 0; i < *(unsigned char*)(*(char**)((char*)self + 0x10) + 1); i++) {
        func_00273DC0(*(char**)((char*)self + 0x18) + i * 0x3C);
    }
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x38) = 0;
    *(int*)((char*)self + 0x30) = -1;
    *(int*)((char*)self + 0x34) = -1;
    cRcListener4918* l = (cRcListener4918*)func_00274D70(self);
    if (l != 0) {
        l->v04(self);
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002749E8);
#ifdef SKIP_ASM
extern "C" void func_002749E8(void* self)
{
    if (*(int*)((char*)self + 0x20) != 0) {
        *(int*)((char*)self + 0x2c) += 1;
    }
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274A08);
#ifdef SKIP_ASM
extern "C" void func_00274A08(void* self)
{
    if (*(int*)((char*)self + 0x20) != 0) {
        int v = *(int*)((char*)self + 0x2c) - 1;
        *(int*)((char*)self + 0x2c) = v;
        if (v < 0) {
            *(int*)((char*)self + 0x2c) = 0;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00274A30);
#ifdef SKIP_ASM
extern "C" int func_00274C70(void* self);
extern "C" void func_00274918(void* p);
void* func_00274810(void* self);
extern "C" void func_00274DE0(void* self);
extern "C" void func_002749E8(void* self);

struct sRcPlay_4A30 {
    char pad0[0x1C];
    int loop;       // 0x1C
    int playing;    // 0x20
    float speed;    // 0x24
    float pos;      // 0x28
    int f2C;        // 0x2C
    char pad30[4];
    int seekTo;     // 0x34
    int steps;      // 0x38
};

extern "C" void func_00274A30(void* p)
{
    sRcPlay_4A30* self = (sRcPlay_4A30*)p;
    int need = 1;
    if (self->seekTo >= 0)
    {
        int target = self->seekTo;
        self->seekTo = -1;
        int len = func_00274C70(self);
        int saved = self->f2C;
        self->f2C = 0;
        if (self->loop != 0)
            target = target % len;
        float ft = (float)target;
        if (self->playing == 1)
            func_00274DE0(self);
        if (ft != self->pos)
        {
            if (ft < self->pos)
            {
                func_00274918(self);
                func_00274810(self);
                func_00274DE0(self);
            }
            float one = 1.0f;
            float pos = self->pos;
            float frac = (float)((int)pos + 1) - pos;
            float speed = self->speed;
            if (frac < one)
            {
                self->speed = frac;
                func_00274DE0(self);
            }
            self->speed = one;
            while (self->playing != 0 && self->pos < ft)
                func_00274DE0(self);
            self->speed = speed;
        }
        if (self->playing != 0)
            self->f2C = saved;
        need = 0;
    }
    if (self->steps != 0)
    {
        int steps = self->steps;
        int saved2 = self->f2C;
        self->steps = 0;
        self->f2C = 0;
        if (self->playing != 0)
        {
            do
            {
                func_00274DE0(self);
                steps--;
                if (self->playing == 0)
                    goto skip;
            } while (steps != 0);
            self->f2C = saved2;
        }
    skip:
        if (self->f2C <= 0)
            func_002749E8(self);
        need = 0;
    }
    if (need)
        func_00274DE0(self);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274C10__FPvi);
#ifdef SKIP_ASM
int func_00274C10(void* self, int a1)
{
    int old = *(int*)((char*)self + 0xc);
    *(int*)((char*)self + 0xc) = a1;
    return old;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274C20);
#ifdef SKIP_ASM
extern "C" void* func_00274C20(void* self, int a1)
{
    return *(char**)((char*)self + 0x18) + a1 * 0x3c;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274C38);
#ifdef SKIP_ASM
extern "C" void* func_00274C38(void* self)
{
    if (*(unsigned short*)((char*)self + 0x2) >= 0xd) {
        return (char*)self + 0xc;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_00274C70);
#ifdef SKIP_ASM
struct sRcTrack4C70 {
    char pad[0x3C];
};

extern "C" int func_00274C70(void* self)
{
    int r = *(int*)((char*)self + 0x30);
    if (r < 0) {
        int best = 0;
        int i;
        for (i = 0; i < *(unsigned char*)(*(char**)((char*)self + 0x10) + 1); i++) {
            int v = func_00274348(&(*(sRcTrack4C70**)((char*)self + 0x18))[i]);
            if (best < v) {
                best = v;
            }
        }
        if (*(int*)((char*)self + 0x20) != 0) {
            *(int*)((char*)self + 0x30) = best;
        }
        r = best;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274D08);
#ifdef SKIP_ASM
extern "C" int func_00274C70(void* self);

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ftrunc_00274D08(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    return t;
}

extern "C" int func_00274D08(void* self)
{
    float x = ((float)func_00274C70(self) - *(float*)((char*)self + 0x28)) / *(float*)((char*)self + 0x24);
    float c = ftrunc_00274D08(x);
    if (c < x) {
        c += 1.0f;
    }
    return (int)c;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00274D70);
#ifdef SKIP_ASM
extern "C" int func_00274D70(void* self)
{
    int v = *(int*)((char*)self + 0x44);
    if (v != 0) {
        return v;
    }
    return **(int**)((char*)self + 0x8);
}
#endif

INCLUDE_ASM("replay/replaycache", func_00274DE0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("replay/replaycache", func_002751A0);
#ifdef SKIP_ASM
extern "C" int func_00274100(void* track, float prev, float time, float speed, int jump);
extern "C" int func_00274D70(void* self);

class cRcListener51A0 {
public:
    virtual void v01();
    virtual void v02(void* src, float time, float speed);
};

struct sRcAnim51A0 {
    char pad_0x0[0x10];
    unsigned char* hdr;     // 0x10, hdr[1] = track count
    char pad_0x14[0x4];
    char* tracks;           // 0x18, 0x3C bytes each
    char pad_0x1C[0xC];
    float time;             // 0x28
};

extern "C" int func_002751A0(sRcAnim51A0* self, float time, float prev, float speed)
{
    int changed = 0;
    int jump = 0;
    self->time = time;
    if (speed > 1.0f) {
        jump = 1;
    } else {
        int ti = (int)time;
        int pi = (int)prev;
        if ((float)ti != time) {
            jump = pi != ti;
        }
    }
    for (int i = 0; i < self->hdr[1]; i++) {
        int c = 0;
        if (func_00274100(self->tracks + i * 0x3C, prev, self->time, speed, jump) != 0 || changed != 0) {
            c = 1;
        }
        changed = c;
    }
    cRcListener51A0* l = (cRcListener51A0*)func_00274D70(self);
    if (l != 0) {
        l->v02(self, self->time, speed);
    }
    return changed;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002752F0__FPv);
#ifdef SKIP_ASM
void* func_002752F0(void* self)
{
    return (char*)self + 0x1C;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002752F8__FPv);
#ifdef SKIP_ASM
int func_002752F8(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275300__FPv);
#ifdef SKIP_ASM
int func_00275300(void* self)
{
    return -0x1;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275308__FPv);
#ifdef SKIP_ASM
int func_00275308(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275310__FPv);
#ifdef SKIP_ASM
int func_00275310(void* self)
{
    return *(int*)((char*)self + 0xC);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275318__FPv);
#ifdef SKIP_ASM
int func_00275318(void* self)
{
    return (*(int*)((char*)self + 0x8) != 0);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275328__FPv);
#ifdef SKIP_ASM
void* func_00275328(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275330__FPv);
#ifdef SKIP_ASM
int func_00275330(void* self)
{
    return *(int*)((char*)self + 0x24);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275338__FPv);
#ifdef SKIP_ASM
int func_00275338(void* self)
{
    return 0x2;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275340__FPv);
#ifdef SKIP_ASM
int func_00275340(void* self)
{
    return *(int*)((char*)self + 0xC);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275348__FPv);
#ifdef SKIP_ASM
int func_00275348(void* self)
{
    return (*(int*)((char*)self + 0x8) != 0);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275358__FPv);
#ifdef SKIP_ASM
void* func_00275358(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275360__FPv);
#ifdef SKIP_ASM
int func_00275360(void* self)
{
    return *(int*)((char*)self + 0x1C);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275368__FPv);
#ifdef SKIP_ASM
int func_00275368(void* self)
{
    return 0x3;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275370__FPv);
#ifdef SKIP_ASM
int func_00275370(void* self)
{
    return *(int*)((char*)self + 0xC);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275378__FPv);
#ifdef SKIP_ASM
int func_00275378(void* self)
{
    return (*(int*)((char*)self + 0x8) != 0);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275388__FPv);
#ifdef SKIP_ASM
void* func_00275388(void* self)
{
    return (char*)self + 0x24;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275390__FPv);
#ifdef SKIP_ASM
int func_00275390(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_00275398__FPv);
#ifdef SKIP_ASM
int func_00275398(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002753A0__FPv);
#ifdef SKIP_ASM
int func_002753A0(void* self)
{
    return *(int*)((char*)self + 0xC);
}
#endif

//100%
INCLUDE_ASM("replay/replaycache", func_002753A8__FPv);
#ifdef SKIP_ASM
int func_002753A8(void* self)
{
    return (*(int*)((char*)self + 0x8) != 0);
}
#endif

