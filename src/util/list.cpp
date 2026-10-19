#include "common.h"

struct cListNode {
    cListNode* next; // 0x0
    cListNode* prev; // 0x4
};

struct cList {
    char pad_0x00[0x4];
    cListNode* head; // 0x4
    char pad_0x08[0x4];
    cListNode* tail; // 0xC
};

//100%
INCLUDE_ASM("util/list", cListNode_isSentinel__FP9cListNode);
#ifdef SKIP_ASM
int cListNode_isSentinel(cListNode* node)
{
    return (node->prev == node) || (node->next == node);
}
#endif

//100%
INCLUDE_ASM("util/list", cListNode_removeFromList);
#ifdef SKIP_ASM
extern "C" void cListNode_removeFromList(cListNode* self)
{
    cListNode* next = self->next;
    cListNode* prev = self->prev;
    if (next != 0 && next != self) {
        if (prev == self) {
            next->prev = next;
        } else {
            next->prev = prev;
        }
    }
    if (prev != 0 && prev != self) {
        if (next == self) {
            prev->next = prev;
        } else {
            prev->next = next;
        }
    }
    self->prev = self;
    self->next = self;
}
#endif

//100%
INCLUDE_ASM("util/list", func_00397788);
#ifdef SKIP_ASM
class func_00397788_cVirt {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(void*);
};

extern "C" int func_00397788(void* a, func_00397788_cVirt* obj)
{
    return obj->v02(a);
}
#endif

//100%
INCLUDE_ASM("util/list", func_003977B8);
#ifdef SKIP_ASM
class func_003977B8_cVirt {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(void*);
};

extern "C" int func_003977B8(void* a, func_003977B8_cVirt* obj)
{
    return obj->v02(a);
}
#endif

//100%
INCLUDE_ASM("util/list", func_003977E8);
#ifdef SKIP_ASM
void func_00397930(void*);
extern void* D_00494C98[];
extern void* D_00494CC0[];

extern "C" void* func_003977E8(void* self)
{
    char* s = (char*)self;
    *(void**)(s + 0x4) = s;
    *(void**)(s + 0x0) = s;
    *(void***)(s + 0x18) = D_00494C98;
    *(void***)(s + 0x8) = D_00494CC0;
    *(void**)(s + 0x10) = s + 0xC;
    *(void***)(s + 0x14) = D_00494CC0;
    *(void**)(s + 0xC) = s + 0xC;
    func_00397930(s);
    return self;
}
#endif

//100%
INCLUDE_ASM("util/list", cList_first__FP5cList);
#ifdef SKIP_ASM
cListNode* cList_first(cList* list)
{
    cListNode* head = list->head;
    return (head->prev == head) ? 0 : head;
}
#endif

//100%
INCLUDE_ASM("util/list", func_00397858);
#ifdef SKIP_ASM
extern "C" int *func_00397858(void *arg0) {
    int *temp_2;

    temp_2 = (*(int **)((char*)(arg0) + (0xC)));
    return ((*temp_2 ^ (int) temp_2) == 0) ? 0 : temp_2;
}
#endif

//100%
INCLUDE_ASM("util/list", func_00397870);
#ifdef SKIP_ASM
extern "C" cListNode* func_00397870(cList* list, int count)
{
    cListNode* n = cList_first(list);
    for (; count > 0; count--) {
        if (n == 0) {
            return 0;
        }
        if (cListNode_isSentinel(n)) {
            break;
        }
        n = n->prev;
    }
    if (n != 0 && !cListNode_isSentinel(n)) {
        return n;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("util/list", func_003978E8);
#ifdef SKIP_ASM
extern "C" int func_003978E8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("util/list", cList_addToFront__FP5cListP9cListNode);
#ifdef SKIP_ASM
void cList_addToFront(cList* list, cListNode* newNode)
{
    cListNode* head = list->head;
    newNode->prev = head;
    newNode->next = head->next;
    head->next = newNode;
    list->head = newNode;
}
#endif

//100%
INCLUDE_ASM("util/list", cList_addToEnd__FP5cListP9cListNode);
#ifdef SKIP_ASM
void cList_addToEnd(cList* list, cListNode* newNode)
{
    cListNode* tail = list->tail;
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev = newNode;
    list->tail = newNode;
}
#endif

//100%
INCLUDE_ASM("util/list", func_00397930__FPv);
#ifdef SKIP_ASM
void func_00397930(void* self)
{
    void* t0 = (char*)self + 0xc;
    *(void**)((char*)self + 0x4) = t0;
    *(void**)((char*)self + 0xc) = self;
    *(void**)((char*)self + 0x10) = t0;
    *(void**)self = self;
}
#endif

//100%
INCLUDE_ASM("util/list", func_00397948);
#ifdef SKIP_ASM
class func_00397948_cVirt {
public:
    void* next;                  // 0x0
    func_00397948_cVirt* prev;   // 0x4
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01(int);
};

extern "C" void func_00397948(void* self)
{
    func_00397948_cVirt* n = *(func_00397948_cVirt**)((char*)self + 0x4);
    while (n->prev != n) {
        func_00397948_cVirt* p = n->prev;
        if (n != 0) {
            n->v01(3);
        }
        n = p;
    }
    func_00397930(self);
}
#endif

//100%
INCLUDE_ASM("util/list", func_003979C0);
#ifdef SKIP_ASM
extern "C" int func_003979C0(cList* list)
{
    cListNode* node = list->head;
    int count = 0;
    while (node->prev != node) {
        node = node->prev;
        count++;
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("util/list", func_003979F8);
#ifdef SKIP_ASM
class func_003979F8_cVirt {
public:
    void* next;                  // 0x0
    func_003979F8_cVirt* prev;   // 0x4
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(void*);
};

extern "C" int func_003979F8(void* self, void* arg)
{
    func_003979F8_cVirt* n = *(func_003979F8_cVirt**)((char*)self + 0x4);
    while (n->prev != n) {
        func_003979F8_cVirt* p = n->prev;
        int r = n->v02(arg);
        if (r != 0) {
            return r;
        }
        n = p;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("util/list", func_00397A68);
#ifdef SKIP_ASM
class func_00397A68_cVirt {
public:
    void* next;                  // 0x0
    func_00397A68_cVirt* prev;   // 0x4
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual int v03(void*);
};

extern "C" int func_00397A68(void* self, void* arg)
{
    func_00397A68_cVirt* n = *(func_00397A68_cVirt**)((char*)self + 0x4);
    while (n->prev != n) {
        func_00397A68_cVirt* p = n->prev;
        int r = n->v03(arg);
        if (r != 0) {
            return r;
        }
        n = p;
    }
    return 0;
}
#endif

