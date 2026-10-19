#include "common.h"

struct cBucketMan {
    char pad_0x00[0x4];
    char* mBuckets; // 0x4, element size 0x44
};

//100%
INCLUDE_ASM("object/bucketman", cBucketMan_init);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_004A4020[];
extern char D_00491F00[];

struct sBucketList_3549E0 {
    int f0;
    sBucketList_3549E0* prev;
    sBucketList_3549E0* next;
    void* vt;
};

struct sBucket_3549E0 {
    int flags;
    sBucketList_3549E0 l0;
    sBucketList_3549E0 l1;
    sBucketList_3549E0 l2;
    sBucketList_3549E0 l3;
    sBucket_3549E0()
    {
        l0.vt = D_00491F00;
        l0.prev = 0;
        l0.next = 0;
        l1.vt = D_00491F00;
        l1.prev = 0;
        l1.next = 0;
        l2.vt = D_00491F00;
        l2.prev = 0;
        l2.next = 0;
        l3.vt = D_00491F00;
        l3.prev = 0;
        l3.next = 0;
    }
    ~sBucket_3549E0() {}
};

extern "C" void cBucketMan_init(cBucketMan* self, int n)
{
    char** slot = &self->mBuckets;
    *slot = (char*)new (D_004A4020, 0, 0) sBucket_3549E0[n];
    *(int*)self = n;
    for (int i = 0; i < *(int*)self; i++) {
        ((sBucket_3549E0*)self->mBuckets)[i].l0.prev = &((sBucket_3549E0*)self->mBuckets)[i].l1;
        ((sBucket_3549E0*)self->mBuckets)[i].l0.next = 0;
        ((sBucket_3549E0*)self->mBuckets)[i].l1.prev = 0;
        ((sBucket_3549E0*)self->mBuckets)[i].l1.next = &((sBucket_3549E0*)self->mBuckets)[i].l0;
        ((sBucket_3549E0*)self->mBuckets)[i].l2.prev = &((sBucket_3549E0*)self->mBuckets)[i].l3;
        ((sBucket_3549E0*)self->mBuckets)[i].l2.next = 0;
        ((sBucket_3549E0*)self->mBuckets)[i].l3.prev = 0;
        ((sBucket_3549E0*)self->mBuckets)[i].l3.next = &((sBucket_3549E0*)self->mBuckets)[i].l2;
        ((sBucket_3549E0*)self->mBuckets)[i].flags = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00354B38);
#ifdef SKIP_ASM
extern "C" void cBucketMan_purgeBucket(cBucketMan* self, int index);
extern "C" void func_003546C8(void* self, int flags);
void cMemMan_free(void*);

extern "C" void func_00354B38(cBucketMan* self)
{
    int i;
    for (i = 0; i < *(int*)self; i++) {
        cBucketMan_purgeBucket(self, i);
    }
    char* b = self->mBuckets;
    if (b != 0) {
        char* p = b + ((int*)b)[-4] * 0x44;
        while (self->mBuckets != p) {
            p -= 0x44;
            func_003546C8(p + 0x34, 2);
            func_003546C8(p + 0x24, 2);
            func_003546C8(p + 0x14, 2);
            func_003546C8(p + 0x4, 2);
        }
        cMemMan_free(self->mBuckets - 0x10);
    }
    self->mBuckets = 0;
    *(int*)self = 0;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", cBucketMan_add);
#ifdef SKIP_ASM
struct sBucketLink {
    int field_0x0;
    sBucketLink* prev; // 0x4
    sBucketLink* next; // 0x8
};

struct sBucketLists {
    int flags;              // 0x00
    sBucketLink head0;      // 0x04
    char pad_0x10[0x14];    // 0x10
    sBucketLink head1;      // 0x24
    char pad_0x30[0x14];    // 0x30
};

extern "C" void cBucketMan_add(cBucketMan* self, sBucketLink* node, int index)
{
    if (((sBucketLists*)self->mBuckets)[index].flags & 1) {
        node->prev = ((sBucketLists*)self->mBuckets)[index].head1.prev;
        ((sBucketLists*)self->mBuckets)[index].head1.prev->next = node;
        node->next = (sBucketLink*)(self->mBuckets + index * 0x44 + 0x24);
        ((sBucketLists*)self->mBuckets)[index].head1.prev = node;
    } else {
        node->prev = ((sBucketLists*)self->mBuckets)[index].head0.prev;
        ((sBucketLists*)self->mBuckets)[index].head0.prev->next = node;
        node->next = (sBucketLink*)(self->mBuckets + index * 0x44 + 0x4);
        ((sBucketLists*)self->mBuckets)[index].head0.prev = node;
    }
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00354C98);
#ifdef SKIP_ASM
void* cBucketMan_addfirst(cBucketMan* self, int index);
extern "C" void* func_00354ED0(cBucketMan* self, int index);
extern "C" void* func_00354F20(cBucketMan* self, void* node, int index);
extern "C" void* func_00354F70(cBucketMan* self, void* node, int index);

struct sSortVE_4C98 {
    short delta;
    short index;
    int (*fn)(void*, void*);
};

struct sSortDelVE_4C98 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sSortNode_4C98 {
    int f0;
    sSortNode_4C98* prev;   // 0x4
    sSortNode_4C98* next;   // 0x8
    sSortVE_4C98* vt;       // 0xC
};

struct sSortLink_4C98 {
    int field_0x0;
    sSortNode_4C98* prev;   // 0x4
    sSortNode_4C98* next;   // 0x8
};

struct sSortLists_4C98 {
    int flags;              // 0x00
    sSortLink_4C98 head0;   // 0x04
    char pad_0x10[0x14];    // 0x10
    sSortLink_4C98 head1;   // 0x24
    char pad_0x30[0x14];    // 0x30
};

// Moves every node of the bucket's pending list into its sorted list.
extern "C" void func_00354C98(cBucketMan* self, int index)
{
    sSortNode_4C98* n = (sSortNode_4C98*)cBucketMan_addfirst(self, index);
    while (n) {
        sSortNode_4C98* nextN = (sSortNode_4C98*)func_00354F70(self, n, index);
        n->next->prev = n->prev;
        n->prev->next = n->next;
        sSortNode_4C98* m;
        for (m = (sSortNode_4C98*)func_00354ED0(self, index); m; m = (sSortNode_4C98*)func_00354F20(self, m, index)) {
            if (n->vt[6].fn((char*)n + n->vt[6].delta, m)) {
                if (n->vt[7].fn((char*)n + n->vt[7].delta, m)) {
                    n->prev = m->prev;
                    m->prev->next = n;
                    n->next = m->next;
                    m->next->prev = n;
                    m->prev = 0;
                    m->next = 0;
                    if (m) {
                        sSortDelVE_4C98* dv = (sSortDelVE_4C98*)m->vt;
                        dv[1].fn((char*)m + dv[1].delta, 3);
                    }
                } else {
                    n->prev = m->prev;
                    m->prev->next = n;
                    n->next = m;
                    m->prev = n;
                }
                break;
            }
        }
        if (m == 0) {
            n->prev = ((sSortLists_4C98*)self->mBuckets)[index].head0.prev;
            ((sSortLists_4C98*)self->mBuckets)[index].head0.prev->next = n;
            n->next = (sSortNode_4C98*)(self->mBuckets + index * 0x44 + 0x4);
            ((sSortLists_4C98*)self->mBuckets)[index].head0.prev = n;
        }
        n = nextN;
    }
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00354E48);
#ifdef SKIP_ASM
struct sBucketNode {
    int field_0x0;
    sBucketNode* prev; // 0x4
    sBucketNode* next; // 0x8
};

extern "C" void func_00354E48(cBucketMan* self, sBucketNode* node)
{
    if (node->prev != 0 && node->next != 0) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00354E78);
#ifdef SKIP_ASM
extern "C" void func_00354E78(cBucketMan* self, sBucketNode* node)
{
    func_00354E48(self, node);
    node->prev = 0;
    node->next = 0;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", cBucketMan_first__FP10cBucketMani);
#ifdef SKIP_ASM
// PORT: holds a pointer in an int (needed to match); not 64-bit safe.
void* cBucketMan_first(cBucketMan* self, int index)
{
    index *= 0x44;
    index += (int)self->mBuckets;
    void* head = *(void**)(index + 0x8);
    return (head == (void*)(index + 0x14)) ? 0 : head;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00354ED0);
#ifdef SKIP_ASM
// PORT: holds a pointer in an int (same shape as cBucketMan_first); not 64-bit safe.
extern "C" void* func_00354ED0(cBucketMan* self, int index)
{
    index *= 0x44;
    index += (int)self->mBuckets;
    void* tail = *(void**)(index + 0x1C);
    return (tail == (void*)(index + 0x4)) ? 0 : tail;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", cBucketMan_next__FP10cBucketManPvi);
#ifdef SKIP_ASM
void* cBucketMan_next(cBucketMan* self, void* node, int index)
{
    char* bucket = self->mBuckets + index * 0x44;
    void* next = *(void**)((char*)node + 0x4);
    return (next == (void*)(bucket + 0x14)) ? 0 : next;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00354F20);
#ifdef SKIP_ASM
extern "C" void* func_00354F20(cBucketMan* self, void* node, int index)
{
    void* next = *(void**)((char*)node + 0x8);
    return (next == (void*)(self->mBuckets + index * 0x44 + 0x4)) ? 0 : next;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", cBucketMan_addfirst__FP10cBucketMani);
#ifdef SKIP_ASM
// PORT: holds a pointer in an int (needed to match); not 64-bit safe.
void* cBucketMan_addfirst(cBucketMan* self, int index)
{
    index *= 0x44;
    index += (int)self->mBuckets;
    void* head = *(void**)(index + 0x28);
    return (head == (void*)(index + 0x34)) ? 0 : head;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00354F70);
#ifdef SKIP_ASM
extern "C" void* func_00354F70(cBucketMan* self, void* node, int index)
{
    void* next = *(void**)((char*)node + 0x4);
    return (next == (void*)(self->mBuckets + index * 0x44 + 0x34)) ? 0 : next;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/bucketman", func_00354F98);
#ifdef SKIP_ASM
struct sBucketVEntry4F98 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00354F98(cBucketMan* self, int index)
{
    void* node = cBucketMan_first(self, index);
    while (node != 0) {
        void* next = cBucketMan_next(self, node, index);
        sBucketVEntry4F98* vt = *(sBucketVEntry4F98**)((char*)node + 0xC);
        vt[2].fn((char*)node + vt[2].delta);
        node = next;
    }
    cBucketMan_first(self, index);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/bucketman", func_00355028);
#ifdef SKIP_ASM
struct sBucketVEntry5028 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00355028(cBucketMan* self, int index)
{
    void* node = cBucketMan_first(self, index);
    while (node != 0) {
        sBucketVEntry5028* vt = *(sBucketVEntry5028**)((char*)node + 0xC);
        vt[3].fn((char*)node + vt[3].delta);
        node = cBucketMan_next(self, node, index);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/bucketman", func_003550A0);
#ifdef SKIP_ASM
struct sBucketVEntry50A0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_003550A0(cBucketMan* self, int index)
{
    void* node = cBucketMan_first(self, index);
    while (node != 0) {
        sBucketVEntry50A0* vt = *(sBucketVEntry50A0**)((char*)node + 0xC);
        vt[4].fn((char*)node + vt[4].delta);
        node = cBucketMan_next(self, node, index);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/bucketman", cBucketMan_purgeBucket);
#ifdef SKIP_ASM
struct sBucketVEntryPurge {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void cBucketMan_purgeBucket(cBucketMan* self, int index)
{
    void* node = cBucketMan_first(self, index);
    while (node != 0) {
        void* next = cBucketMan_next(self, node, index);
        if (node != 0) {
            sBucketVEntryPurge* vt = *(sBucketVEntryPurge**)((char*)node + 0xC);
            vt[1].fn((char*)node + vt[1].delta, 3);
        }
        node = next;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/bucketman", func_003551A8);
#ifdef SKIP_ASM
struct sBucketVEntry51A8 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sBucketVEntry51A8b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

void* cBucketMan_first(cBucketMan* self, int index);
void* cBucketMan_next(cBucketMan* self, void* node, int index);

extern "C" void func_003551A8(cBucketMan* self, int index, int key)
{
    void* node = cBucketMan_first(self, index);
    while (node != 0) {
        void* next = cBucketMan_next(self, node, index);
        sBucketVEntry51A8* e = &(*(sBucketVEntry51A8**)((char*)node + 0xC))[11];
        if (e->fn((char*)node + e->delta) == key) {
            if (node != 0) {
                sBucketVEntry51A8b* vt = *(sBucketVEntry51A8b**)((char*)node + 0xC);
                vt[1].fn((char*)node + vt[1].delta, 3);
            }
        }
        node = next;
    }
}
#endif

// 0x44-byte elements reached through a pointer at self+0x4
struct sBucketEntry {
    int flags;
    char pad_0x04[0x40];
};

//100%
INCLUDE_ASM("object/bucketman", func_00355260);
#ifdef SKIP_ASM
extern "C" void func_00355260(void* self, int a1)
{
    sBucketEntry* p = *(sBucketEntry**)((char*)self + 0x4);
    p[a1].flags |= 1;
}
#endif

//100%
INCLUDE_ASM("object/bucketman", func_00355280);
#ifdef SKIP_ASM
extern void* D_00491028[];
extern "C" void* func_0034FB00(void* self, void* a1, int type, void* a3);

extern "C" void* func_00355280(void* self, void* a1, int type, void* a3)
{
    func_0034FB00(self, a1, type, a3);
    *(void***)((char*)self + 0xC) = D_00491028;
    *(float*)((char*)self + 0x24) = 1.0f;
    *(unsigned short*)((char*)self + 0x12) |= 1;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x28) = 0;
    return self;
}
#endif

