#include "common.h"

//100%
INCLUDE_ASM("ui/uistate", cUIState_hideObjSafe);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
cListNode* cList_first(cList*);
int cListNode_isSentinel(cListNode*);
int GetHashValue32(char*);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);

struct sVEntry39E8B8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void cUIState_hideObjSafe(void* self, char* name)
{
    cListNode* n = cList_first((cList*)((char*)self + 0x24));
    if (n != 0) {
        do {
            void* obj = cUIScreen_getObjectByHashName(n, GetHashValue32(name));
            if (obj != 0) {
                sVEntry39E8B8* vt = *(sVEntry39E8B8**)((char*)obj + 8);
                vt[9].fn((char*)obj + vt[9].delta, 0);
                return;
            }
            n = *(cListNode**)((char*)n + 4);
        } while (!cListNode_isSentinel(n));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistate", cUIState_showObjSafe);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
cListNode* cList_first(cList*);
int cListNode_isSentinel(cListNode*);
int GetHashValue32(char*);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);

struct sVEntry39E948 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void cUIState_showObjSafe(void* self, char* name)
{
    cListNode* n = cList_first((cList*)((char*)self + 0x24));
    if (n != 0) {
        do {
            void* obj = cUIScreen_getObjectByHashName(n, GetHashValue32(name));
            if (obj != 0) {
                sVEntry39E948* vt = *(sVEntry39E948**)((char*)obj + 8);
                vt[9].fn((char*)obj + vt[9].delta, 1);
                return;
            }
            n = *(cListNode**)((char*)n + 4);
        } while (!cListNode_isSentinel(n));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistate", func_0039E9D8);
#ifdef SKIP_ASM
extern "C" void func_0039F8C8(void* self);
extern "C" void func_00397948(void*);
extern "C" void func_003A4868(void* self);
void operator_delete(int*);
extern void* D_00494C98[];
extern void* D_00494CC0[];

extern "C" void func_0039E9D8(void* self, int flags)
{
    func_0039F8C8(self);
    *(void***)((char*)self + 0x34) = D_00494C98;
    func_00397948((char*)self + 0x1C);
    *(void***)((char*)self + 0x30) = D_00494CC0;
    func_003A4868((char*)self + 0x28);
    *(void***)((char*)self + 0x24) = D_00494CC0;
    func_003A4868((char*)self + 0x1C);
    *(void***)((char*)self + 0x18) = D_00494C98;
    func_00397948(self);
    *(void***)((char*)self + 0x14) = D_00494CC0;
    func_003A4868((char*)self + 0xC);
    *(void***)((char*)self + 0x8) = D_00494CC0;
    func_003A4868(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistate", func_0039EA90);
#ifdef SKIP_ASM
struct func_0039EA90_sFlags {
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

struct func_0039EA90_node {
    char pad0[0x4];
    func_0039EA90_node* next; // 0x4
    char pad8[0x1C - 0x8];
    union {
        int flags; // 0x1C
        func_0039EA90_sFlags bits;
    };
};

static inline void func_0039EA90_setB3(func_0039EA90_node* n, int v) { n->bits.b3 = v; }
static inline void func_0039EA90_setB5(func_0039EA90_node* n, int v) { n->bits.b5 = v; }
static inline void func_0039EA90_setId(func_0039EA90_node* n, int v) { n->bits.id = v; }
static inline void func_0039EA90_setB4(func_0039EA90_node* n, int v) { n->bits.b4 = v; }

extern "C" int func_0039EA90(cList* list, signed char id)
{
    func_0039EA90_node* n = (func_0039EA90_node*)cList_first(list);
    if (n != 0) {
        do {
            if ((((unsigned int)n->flags >> 8) & 0x3F) == id && ((n->flags >> 6) & 1) == 0) {
                func_0039EA90_setB3(n, 1);
                func_0039EA90_setB5(n, 1);
                func_0039EA90_setId(n, 2);
                func_0039EA90_setB4(n, 1);
                return 1;
            }
            n = n->next;
        } while (!cListNode_isSentinel((cListNode*)n));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uistate", func_0039EB60);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
cListNode* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct func_0039EB60_node {
    char pad0[0x4];
    func_0039EB60_node* next; // 0x4
    char pad8[0x1C - 0x8];
    int flags; // 0x1C
};

extern "C" int func_0039EB60(cList* list, signed char id)
{
    func_0039EB60_node* n = (func_0039EB60_node*)cList_first(list);
    if (n != 0) {
        do {
            if ((((unsigned int)n->flags >> 8) & 0x3F) == id && ((n->flags >> 6) & 1) == 0) {
                return 1;
            }
            n = n->next;
        } while (!cListNode_isSentinel((cListNode*)n));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uistate", func_0039EBE0);
#ifdef SKIP_ASM
struct func_0039EBE0_sVEntry {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0039EBE0(void* self)
{
    char* n = (char*)cList_first((cList*)self);
    if (n != 0) {
        do {
            if ((*(int*)(n + 0x1C) >> 3) & 1) {
                func_0039EBE0_sVEntry* vt = *(func_0039EBE0_sVEntry**)(n + 8);
                vt[15].fn(n + vt[15].delta);
            }
            n = *(char**)(n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
    n = (char*)cList_first((cList*)((char*)self + 0x1C));
    if (n != 0) {
        do {
            if ((*(int*)(n + 0x1C) >> 3) & 1) {
                func_0039EBE0_sVEntry* vt = *(func_0039EBE0_sVEntry**)(n + 8);
                vt[15].fn(n + vt[15].delta);
            }
            n = *(char**)(n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistate", func_0039ECA8__FPv);
#ifdef SKIP_ASM
void func_0039ECA8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uistate", func_0039ECB0);
#ifdef SKIP_ASM
void cListNode_removeFromList(cListNode*);
extern "C" void* cUIStateStack_getCurrentState(void* self);
extern "C" void func_0039F7B8(void* self, void* state, int a2, int a3);
extern "C" void func_0039E868(void* state);

class sState_ECB0;

class sStateBase_ECB0 {
public:
    int pad0;
    sState_ECB0* next;      // 0x4
    virtual ~sStateBase_ECB0(); // vtable at 0x8
    virtual void v02();
    virtual void v03();
    virtual void onEnter();
    virtual void onExit();
    virtual void onHide(int a);
    virtual int onShow(int a);
    virtual void v08();
    virtual void v09();
    virtual int isReady();
    virtual void onClose(int a);
    virtual void onUpdate();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void notify(sState_ECB0* from, int msg);
};

class sState_ECB0 : public sStateBase_ECB0 {
public:
    char padC[0x1C - 0xC];
    unsigned int b0 : 1;    // 0x1C
    unsigned int f1 : 2;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
    unsigned int b14 : 1;
    sState_ECB0* under;     // 0x20
};

// Steps every active state of the stack through its transition states (2..7); returns nonzero when a
// state finished closing and none was (re)opened.
extern "C" int func_0039ECB0(void* self)
{
    int closed = 0;
    int opened = 0;
    sState_ECB0* st = (sState_ECB0*)cList_first((cList*)self);
    if (st == 0)
        goto done;
    while (!cListNode_isSentinel((cListNode*)st)) {
        sState_ECB0* next = st->next;
        if ((*(int*)((char*)st + 0x1C) >> 5) & 1) {
            switch ((signed char)st->id) {
            case 2:
                opened = 1;
                st->onEnter();
                st->id = 4;
                func_0039E868(st);
                if (st->b0) {
                    sState_ECB0* under = st->under;
                    if (under != 0) {
                        func_0039F7B8(self, under, 1, 1);
                        under->notify(st, 0x15);
                    }
                }
            case 4:
                if (st->onShow((*(int*)((char*)st + 0x1C) >> 4) & 1))
                    st->id = 3;
                st->b4 = 0;
                func_0039E868(st);
                break;
            case 3:
                if ((*(int*)((char*)st + 0x1C) >> 4) & 1) {
                    st->onShow(1);
                    st->b4 = 0;
                }
                st->onHide(0);
                st->id = 5;
                func_0039E868(st);
                break;
            case 5:
                st->onUpdate();
                func_0039E868(st);
                break;
            case 6:
                if (st->isReady())
                    st->id = 7;
                st->b4 = 1;
                func_0039E868(st);
                break;
            case 7: {
                int handled = 0;
                closed = 1;
                st->onClose(0);
                st->onExit();
                st->id = 8;
                st->b5 = 0;
                if ((*(int*)((char*)st + 0x1C) >> 7) & 1)
                    cListNode_removeFromList((cListNode*)st);
                int fl = *(int*)((char*)st + 0x1C);
                int pinned = fl & 1;
                if (pinned) {
                    sState_ECB0* under = st->under;
                    closed = 0;
                    handled = ((fl >> 14) & 1) ? 0 : func_0039EB60((cList*)self, 1);
                    if (!handled) {
                        st->b7 = 1;
                        if (under != 0) {
                            if (under->f1 != 0)
                                under->f1 = under->f1 - 1;
                            under->b5 = under->f1 == 0;
                            under->notify(st, 0x16);
                        }
                    } else if (under != 0) {
                        func_0039F7B8(self, under, 0, 1);
                    }
                }
                if (st != 0) {
                    if ((*(int*)((char*)st + 0x1C) >> 7) & 1) {
                        cListNode_removeFromList((cListNode*)st);
                        delete st;
                    } else {
                        st->b3 = 0;
                    }
                }
                if (!pinned || handled) {
                    if (cUIStateStack_getCurrentState(self) == 0) {
                        if (func_0039EA90((cList*)self, 1) == 0)
                            func_0039EA90((cList*)self, 8);
                    }
                }
                break;
            }
            }
        }
        st = next;
    }
done:
    if (closed == 0)
        return 0;
    return opened ^ 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ui/uistate", func_0039F100);
#ifdef SKIP_ASM
extern "C" int func_0039ECB0(void* self);
extern "C" void func_0039E868(void* self);

struct sVEntry39F100 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0039F100(void* self)
{
    if (func_0039ECB0(self) != 0) {
        func_0039ECB0(self);
    }
    cListNode* n = cList_first((cList*)((char*)self + 0x1C));
    if (n != 0) {
        do {
            if ((*(int*)((char*)n + 0x1C) >> 5) & 1) {
                sVEntry39F100* vt = *(sVEntry39F100**)((char*)n + 8);
                vt[0xC].fn((char*)n + vt[0xC].delta);
            }
            func_0039E868(n);
            n = *(cListNode**)((char*)n + 4);
        } while (!cListNode_isSentinel(n));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uistate", func_0039F190);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
cListNode* cList_first(cList*);

struct func_0039F190_node {
    char pad0[0x4];
    func_0039F190_node* next; // 0x4
    char pad8[0x1C - 0x8];
    unsigned int b0 : 6;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int id : 6;
};

static inline void func_0039F190_setId(func_0039F190_node* n, int v) { n->id = v; }
static inline void func_0039F190_setB7(func_0039F190_node* n, int v) { n->b7 = v; }

extern "C" func_0039F190_node* func_0039F190(cList* list, int count)
{
    func_0039F190_node* n = (func_0039F190_node*)cList_first(list);
    int i;
    for (i = 0; i < count; i++) {
        if (n == 0) {
            goto done;
        }
        func_0039F190_setId(n, 6);
        func_0039F190_setB7(n, 1);
        n = n->next;
    }
done:
    return n;
}
#endif

