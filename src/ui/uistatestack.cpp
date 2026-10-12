#include "common.h"

//100%
INCLUDE_ASM("ui/uistatestack", cUIStateStack_pushExplicit);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void cList_addToEnd(cList*, cListNode*);

class cUIStateStack_pushExplicit_cState {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
};

extern "C" void cUIStateStack_pushExplicit(void* self, cUIStateStack_pushExplicit_cState* state)
{
    *(int*)((char*)state + 0x1C) |= 0x60;
    state->v04();
    cList_addToEnd((cList*)((char*)self + 0x1C), (cListNode*)state);
}
#endif

INCLUDE_ASM("ui/uistatestack", func_0039F290);

//100%
INCLUDE_ASM("ui/uistatestack", cUIStateStack_pushSpecial);
#ifdef SKIP_ASM
struct cListNode;
void cList_addToFront(cList*, cListNode*);

struct cUIStateStack_sState {
    char pad0[0x1C];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
};

static inline int cUIStateStack_stateId(cUIStateStack_sState* s) { return s->id; }

extern "C" void* cUIStateStack_getCurrentState(void* self);

extern "C" void cUIStateStack_pushSpecial(cList* self, cUIStateStack_sState* st, int a2, int a3)
{
    cUIStateStack_sState* cur = (cUIStateStack_sState*)cUIStateStack_getCurrentState(self);
    if (cur != 0) {
        if (((*(int*)((char*)cur + 0x1C) >> 5) & 1) && cUIStateStack_stateId(cur) == 5) {
            cur->id = 7;
            cur->b7 = a3;
        }
    } else {
        a2 = 1;
        st->id = 2;
    }
    cList_addToFront(self, (cListNode*)st);
    st->b5 = a2;
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F400);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList*);
struct cListNode;
void cList_addToFront(cList*, cListNode*);

struct func_0039F400_sState {
    char pad0[0x1C];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
};

static inline int func_0039F400_stateId(func_0039F400_sState* s) { return s->id; }

extern "C" void func_0039F400(cList* self, func_0039F400_sState* st)
{
    int covered = 0;
    func_0039F400_sState* top = (func_0039F400_sState*)cList_first(self);
    if (top != 0) {
        int f = *(int*)((char*)top + 0x1C);
        if (((f >> 5) & 1) && ((f >> 6) & 1) == 0 && func_0039F400_stateId(top) < 6) {
            covered = 1;
            top->id = 6;
            top->b7 = 1;
        }
    }
    if (covered) {
        st->id = 1;
        st->b5 = 0;
    } else {
        st->id = 2;
        st->b5 = 1;
    }
    cList_addToFront(self, (cListNode*)st);
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F4C0);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList*);
struct cListNode;
void cList_addToFront(cList*, cListNode*);

struct func_0039F4C0_sState {
    char pad0[0x4];
    func_0039F4C0_sState* next;     // 0x4
    char pad8[0x1C - 0x8];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
    unsigned int b14 : 1;
};

static inline void setB7_F4C0(func_0039F4C0_sState* s, int v) { s->b7 = v; }
static inline void setB14_F4C0(func_0039F4C0_sState* s, int v) { s->b14 = v; }
static inline int func_0039F4C0_stateId(func_0039F4C0_sState* s) { return s->id; }

// Release-build assert: expands to an empty do { } while (0); the leftover loop notes shape register
// allocation of the pinned-state loop the way the target has it.
#define ASSERT_F4C0(cond) do { } while (0)

// Pushes a state, first marking every pinned state on top as covered (id 7) and suspended.
extern "C" void func_0039F4C0(cList* self, func_0039F4C0_sState* st)
{
    int covered = 0;
    int skipped = 0;
    func_0039F4C0_sState* top = (func_0039F4C0_sState*)cList_first(self);
    if (top != 0) {
        while (top->b0) {
            ASSERT_F4C0(top != 0);
            if (top->id < 6) {
                top->id = 7;
                ASSERT_F4C0(top->id == 7);
                setB7_F4C0(top, 1);
            }
            setB14_F4C0(top, 1);
            top = top->next;
            skipped = 1;
        }
        int f = *(int*)((char*)top + 0x1C);
        if (skipped || ((f >> 5) & 1)) {
            if (((f >> 6) & 1) == 0 && func_0039F4C0_stateId(top) < 6) {
                covered = 1;
                top->id = 6;
                top->b7 = 1;
            }
        }
    }
    if (covered) {
        st->id = 1;
        st->b5 = 0;
    } else {
        st->id = 2;
        st->b5 = 1;
    }
    cList_addToFront(self, (cListNode*)st);
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F600);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList*);

struct func_0039F600_node {
    char pad0[0x4];
    func_0039F600_node* next; // 0x4
    char pad8[0x1C - 0x8];
    unsigned int b0 : 1;
    unsigned int b1 : 5;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
    unsigned int b14 : 1;
    unsigned int b15 : 1;
};

static inline void func_0039F600_setId(func_0039F600_node* n, int v) { n->id = v; }
static inline void func_0039F600_setB7(func_0039F600_node* n, int v) { n->b7 = v; }

extern "C" func_0039F600_node* func_0039F600(cList* list)
{
    func_0039F600_node* n = (func_0039F600_node*)cList_first(list);
    if (n != 0) {
        while (n->b0) {
            if ((*(int*)((char*)n + 0x1C) >> 15) & 1) {
                break;
            }
            if (n->id < 6) {
                func_0039F600_setId(n, 7);
                func_0039F600_setB7(n, 1);
            }
            n = n->next;
        }
        return n;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F698);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList*);

struct func_0039F698_node {
    char pad0[0x4];
    func_0039F698_node* next; // 0x4
    char pad8[0x1C - 0x8];
    unsigned int b0 : 1;
    unsigned int b1 : 5;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
};

static inline void func_0039F698_setId(func_0039F698_node* n, int v) { n->id = v; }
static inline void func_0039F698_setB7(func_0039F698_node* n, int v) { n->b7 = v; }

extern "C" func_0039F698_node* func_0039F698(cList* list)
{
    func_0039F698_node* n = (func_0039F698_node*)cList_first(list);
    if (n != 0) {
        if (n->b0) {
            do {
                if (n->id < 6) {
                    func_0039F698_setId(n, 7);
                    func_0039F698_setB7(n, 1);
                }
                n = n->next;
            } while (n->b0);
        }
        return n;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F718);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList*);

struct func_0039F718_node {
    char pad0[0x4];
    func_0039F718_node* next; // 0x4
    char pad8[0x1C - 0x8];
    unsigned int b0 : 1;
    unsigned int b1 : 5;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
};

static inline void func_0039F718_setId(func_0039F718_node* n, int v) { n->id = v; }
static inline void func_0039F718_setB7(func_0039F718_node* n, int v) { n->b7 = v; }

extern "C" func_0039F718_node* func_0039F718(cList* list)
{
    func_0039F718_node* n = (func_0039F718_node*)cList_first(list);
    if (n != 0) {
        if (n->b0) {
            do {
                if (n->id < 6) {
                    func_0039F718_setId(n, 7);
                    func_0039F718_setB7(n, 1);
                }
                n = n->next;
            } while (n->b0);
        }
        if (n->id < 6) {
            n->id = 7;
            n->b7 = 1;
        }
        return n->next;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F7B8);
#ifdef SKIP_ASM
struct sUIState39F7B8 {
    char pad0[0x4];
    sUIState39F7B8* next;       // 0x04
    char pad8[0x14];
    unsigned int b0 : 3;        // 0x1C
    unsigned int active : 1;
    unsigned int b4 : 4;
    unsigned int type : 6;
    unsigned int b14 : 18;
    int child;                  // 0x20
};

static inline void Set39F7B8(sUIState39F7B8* s, int on)
{
    if (s->type < 6) {
        s->active = on;
    }
}

// Sets the active flag on every state in a chain (and the last one if requested), skipping types >= 6.
extern "C" void func_0039F7B8(void* self, sUIState39F7B8* s, int on, int last)
{
    if (s == 0) {
        return;
    }
    sUIState39F7B8* cur = s;
    while (cur->child != 0) {
        Set39F7B8(cur, on);
        cur = cur->next;
    }
    s = cur;
    if (last != 0) {
        Set39F7B8(s, on);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F840);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct func_0039F840_node {
    char pad0[0x4];
    func_0039F840_node* next; // 0x4
    char pad8[0x1C - 0x8];
    unsigned int b0 : 1;
    unsigned int b1 : 4;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
};

static inline void func_0039F840_setId(func_0039F840_node* n, int v) { n->id = v; }
static inline void func_0039F840_setB7(func_0039F840_node* n, int v) { n->b7 = v; }
static inline void func_0039F840_setB5(func_0039F840_node* n, int v) { n->b5 = v; }

extern "C" void func_0039F840(cList* list)
{
    func_0039F840_node* n = (func_0039F840_node*)cList_first(list);
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            func_0039F840_node* next = n->next;
            func_0039F840_setId(n, 7);
            func_0039F840_setB7(n, 1);
            func_0039F840_setB5(n, 1);
            n = next;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F8C8);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct sUIStVtF8C8 { short delta; short index; void (*fn)(void*, int); };
struct sUIStVtF8C8a { short delta; short index; void (*fn)(void*); };

static inline void func_0039F8C8_purge(cList* list)
{
    char* n = (char*)cList_first(list);
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            char* next = *(char**)(n + 4);
            if (((*(int*)(n + 0x1C) >> 6) & 1) == 0) {
                sUIStVtF8C8a* vt = *(sUIStVtF8C8a**)(n + 8);
                vt[5].fn(n + vt[5].delta);
                if (n != 0) {
                    sUIStVtF8C8* vt2 = *(sUIStVtF8C8**)(n + 8);
                    vt2[1].fn(n + vt2[1].delta, 3);
                }
            }
            n = next;
        }
    }
}

extern "C" void func_0039F8C8(cList* self)
{
    func_0039F8C8_purge(self);
    func_0039F8C8_purge((cList*)((char*)self + 0x1C));
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039F9D8);
#ifdef SKIP_ASM
struct cListNode;
int cListNode_isSentinel(cListNode*);

extern "C" void* func_0039F9D8(void* self, int id)
{
    char* n = (char*)cList_first((cList*)self);
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            if (*(int*)(n + 0xC) == id) {
                return n;
            }
            n = *(char**)(n + 4);
        }
    }
    n = (char*)cList_first((cList*)((char*)self + 0x1C));
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            if (*(int*)(n + 0xC) == id) {
                return n;
            }
            n = *(char**)(n + 4);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", cUIStateStack_getCurrentState);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList*);
struct cListNode;
int cListNode_isSentinel(cListNode*);

extern "C" void* cUIStateStack_getCurrentState(void* self)
{
    void* n = cList_first((cList*)self);
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            if ((*(int*)((char*)n + 0x1C) >> 5) & 1) {
                return n;
            }
            n = *(void**)((char*)n + 4);
        }
    }
    return 0;
}
#endif

struct cList;
void* cList_first(cList*);

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FAE8);
#ifdef SKIP_ASM
extern "C" void* func_0039FAE8(void* self)
{
    return cList_first((cList*)self);
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FB30);
#ifdef SKIP_ASM
struct func_0039FB30_sVec3 {
    float x;
    float y;
    float z;
};

extern func_0039FB30_sVec3 D_004FF0D8;
extern char D_00494BD8[];

struct func_0039FB30_sFlags {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int b8 : 5;
    unsigned int align : 6;
};

struct func_0039FB30_sUIObj {
    void* prev;
    void* next;
    void* vtbl;
    int unkC;
    char unk10;
    func_0039FB30_sFlags flags;
    int unk18;
    float color[4];
    func_0039FB30_sVec3 pos;
    int unk38;
    int unk3C;
    int unk40;
    func_0039FB30_sVec3 rot;
    func_0039FB30_sVec3 scale;
    int unk5C;
    func_0039FB30_sVec3 offs;
    int unk6C;
    int unk70;
};

extern "C" func_0039FB30_sUIObj* func_0039FB30(func_0039FB30_sUIObj* self, int a1, int a2)
{
    self->vtbl = D_00494BD8;
    self->flags.b0 = 1;
    self->flags.b7 = 0;
    self->flags.b8 = 0;
    self->flags.b5 = 0;
    self->flags.b4 = 0;
    self->flags.b2 = 0;
    self->flags.b1 = 1;
    self->flags.b3 = 1;
    self->flags.b6 = 1;
    self->flags.align = 9;
    self->next = self;
    self->prev = self;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk18 = 0;
    self->color[0] = 1.0f;
    self->color[1] = 1.0f;
    self->color[2] = 1.0f;
    self->color[3] = 1.0f;
    self->pos = D_004FF0D8;
    self->unk40 = a2;
    self->unk38 = 0;
    self->unk3C = 0;
    self->rot = D_004FF0D8;
    self->scale.x = 1.0f;
    self->scale.y = 1.0f;
    self->scale.z = 1.0f;
    self->unk5C = a1;
    self->offs = D_004FF0D8;
    self->unk6C = 4;
    self->unk70 = 6;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FC48);
#ifdef SKIP_ASM
extern "C" void func_003A4868(void* self);
void operator_delete(int* ptr);
extern void* D_00494CC0[];

class func_0039FC48_cVirt {
public:
    char pad[0x10];
    // vptr at 0x10; slot N at vtable offset N*8
    virtual void v01(int);
};

extern "C" void func_0039FC48(void* self, int flags)
{
    *(void**)((char*)self + 0x8) = D_00494BD8;
    func_0039FC48_cVirt* o = *(func_0039FC48_cVirt**)((char*)self + 0xC);
    if (o != 0) {
        o->v01(3);
    }
    *(void***)((char*)self + 0x8) = D_00494CC0;
    func_003A4868(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FCC8);
#ifdef SKIP_ASM
extern "C" void func_0039FD38(void* self);
extern "C" void func_00397468(void* self, int mode, unsigned short v);

extern "C" void func_0039FCC8(void* self, void* anim, unsigned char mode, unsigned short v)
{
    if (*(void**)((char*)self + 0xC) != anim) {
        func_0039FD38(self);
    }
    *(unsigned char*)((char*)self + 0x10) = mode;
    *(void**)((char*)self + 0xC) = anim;
    func_00397468(anim, *(unsigned char*)((char*)self + 0x10), v);
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FD38);
#ifdef SKIP_ASM
struct sVEntry39FD38 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0039FD38(void* self)
{
    void* obj = *(void**)((char*)self + 0xC);
    if (obj != 0) {
        sVEntry39FD38* vt = *(sVEntry39FD38**)((char*)obj + 0x10);
        vt[1].fn((char*)obj + vt[1].delta, 3);
        *(void**)((char*)self + 0xC) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FE00);
#ifdef SKIP_ASM
struct sStateDef39FE00 {
    int f0;
    int id;                 // 0x04
    unsigned char layer : 5; // 0x08
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    unsigned char pad9[3];
};

struct sVE39FE00 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sState39FE00 {
    char pad0[0x8];
    sVE39FE00* vt;          // 0x08
    char padC[0x8];
    unsigned int b0 : 1;    // 0x14
    unsigned int b1 : 6;
    unsigned int b7 : 1;
    unsigned int layer : 5;
    unsigned int rest : 19;
    char pad18[0x20];
    int id;                 // 0x38
    void* data;             // 0x3C
};

// Initialises a UI state from its definition record (id, layer, flags) and points it at the following data.
extern "C" void func_0039FE00(sState39FE00* self, sStateDef39FE00* def)
{
    self->id = def->id;
    self->layer = def->layer;
    self->b0 = (*(int*)((char*)def + 8) >> 6) & 1;
    self->vt[9].fn((char*)self + self->vt[9].delta, (*(int*)((char*)def + 8) >> 9) & 1);
    self->b7 = def->b7;
    self->data = def + 1;
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FEB8);
#ifdef SKIP_ASM
struct sUIAlignFlags14 {
    unsigned int lo : 13;
    unsigned int align : 6;
};

struct sUIVec2 {
    float x;
    float y;
};

static inline unsigned int getUIAlign(void* self)
{
    return ((sUIAlignFlags14*)((char*)self + 0x14))->align;
}

extern "C" void func_0039FEB8(void* self, sUIVec2* pos, sUIVec2* size)
{
    unsigned int align = getUIAlign(self);
    if ((align & 1) == 0) {
        if (align & 4) {
            float d = size->y;
            pos->y -= d;
        } else {
            pos->y -= size->y * 0.5f;
        }
    }
    if ((align & 8) == 0) {
        if (align & 0x20) {
            pos->x -= size->x;
        } else {
            pos->x -= size->x * 0.5f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FF50__FPv);
#ifdef SKIP_ASM
int func_0039FF50(void* self)
{
    return *(int*)((char*)*(void**)((char*)*(void**)((char*)self + 0x5c) + 0xd0) + 0x10);
}
#endif

//100%
INCLUDE_ASM("ui/uistatestack", func_0039FF60);
#ifdef SKIP_ASM
extern "C" void* func_0039FF60(void* self, int a1)
{
    return *(int*)((char*)self + 0x38) == a1 ? self : 0;
}
#endif

