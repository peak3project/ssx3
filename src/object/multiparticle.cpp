#include "common.h"

//100%
INCLUDE_ASM("object/multiparticle", cMultiParticle_setupMultiParticle);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc(unsigned int size, const char* tag, int flags, int d);
extern "C" void* func_00370018(void* p);
extern "C" void func_003705E0(void* sys, void* data, int n);
extern char D_004A4030[];
extern char D_004A4038[];
extern char D_004FF1A0[];

// PORT: array new bound to the tagged allocator
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

struct sMPRef {
    unsigned int id;
    sMPRef() : id(0xFFFFFFFF) {}
};

struct sMultiParticle {
    int count;     // 0x0
    int field_0x4; // 0x4
    int field_0x8; // 0x8
    sMPRef* refs;  // 0xC
    void* sys;     // 0x10
};

extern "C" void cMultiParticle_setupMultiParticle(sMultiParticle* self)
{
    sMPRef** slot = &self->refs;
    *slot = new (D_004A4030, 0x20000000, 0) sMPRef[self->count];
    self->sys = func_00370018(cMemMan_alloc(0x190, D_004A4038, 0x20000000, 0));
    for (int i = 0; i < self->count; i++) {
        self->refs[i].id = 0xFFFFFFFF;
    }
    func_003705E0(self->sys, D_004FF1A0, self->field_0x8);
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358120);
#ifdef SKIP_ASM
extern "C" void func_00370788(void* self, float dt);

extern "C" void func_00358120(void* self)
{
    func_00370788(*(void**)((char*)self + 0x10), 0.01666666753590107f);
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358140);
#ifdef SKIP_ASM
struct sMoveList {
    int field_0x0;          // 0x0
    int count;              // 0x4
    int field_0x8;          // 0x8
    unsigned int* entries;  // 0xC
};

extern "C" void func_00358140(sMoveList* self, unsigned int key)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if ((self->entries[i] & 0xFF) == key) {
            self->count--;
            if (i < self->count) {
                self->entries[i] = self->entries[self->count];
                i--;
            } else {
                self->entries[i] = 0xFFFFFFFF;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003581B8);
#ifdef SKIP_ASM
struct sParticleList {
    int capacity; // 0x0
    int count;    // 0x4
    int field_0x8;
    int* items;   // 0xc
};

extern "C" void func_003581B8(sParticleList* list, int item)
{
    int n = list->count;
    if (n < list->capacity) {
        list->items[n] = item;
        list->count = n + 1;
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003581F0);
#ifdef SKIP_ASM
struct sMoveList_81F0 {
    int field_0x0;          // 0x0
    int count;              // 0x4
    int field_0x8;          // 0x8
    unsigned int* entries;  // 0xC
};

// Removes the first entry equal to key, filling the hole with the last entry.
extern "C" void func_003581F0(sMoveList_81F0* self, unsigned int key)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (self->entries[i] == key) {
            self->count--;
            // the do/while(0) wrapper (a compiled-out macro block) is needed to match register allocation
            do {
                if (i < self->count) {
                    self->entries[i] = self->entries[self->count];
                } else {
                    self->entries[i] = 0xFFFFFFFF;
                }
                return;
            } while (0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358260);
#ifdef SKIP_ASM
struct sMPVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMPBox {
    sMPVec4 min;
    sMPVec4 max;
};

struct sMPModelSet {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};

struct sMPWorld {
    char pad_0x0[0x8];
    sMPModelSet** sets;     // 0x8
};

extern "C" sMPWorld** func_002D1BD8();
extern "C" void func_00370888(void* desc, sMPBox* box, const sMPVec4& center);

static inline void* refToPtr58260(unsigned int p)
{
    return (void*)(p << 2);
}

static inline void* lookup58260(sMPModelSet* set, unsigned int idx)
{
    unsigned int p = set->refs[idx] >> 8;
    if (p == 0) {
        return 0;
    }
    return refToPtr58260(p);
}

struct sMPModelRef {
    unsigned int id;

    void* get(sMPWorld* w)
    {
        sMPModelSet* set = w->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        return lookup58260(set, id >> 8);
    }
};

struct sMPModel {
    char pad_0x0[0x40];
    sMPVec4 pos;            // 0x40
    sMPVec4 getPos() { return pos; }
};

// PORT: PS2-only VU0 inline asm (dst += b).
static inline void vu0AddTo58260(sMPVec4& dst, sMPVec4 b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sMPVec4 vu0Add58260(const sMPVec4& a, const sMPVec4& b)
{
    sMPVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

struct sMultiPart58260 {
    void* owner;            // 0x0
    int count;              // 0x4
    void* data;             // 0x8
    sMPModelRef* refs;      // 0xC
    void* desc;             // 0x10
    char pad_0x14[0xC];
    sMPBox box;             // 0x20
    sMPVec4 center;         // 0x40
};

extern "C" void func_00358260(sMultiPart58260* self)
{
    for (int i = 0; i < self->count; i++) {
        sMPModel* m = (sMPModel*)self->refs[i].get(*func_002D1BD8());
        if (m != 0) {
            sMPBox b = self->box;
            vu0AddTo58260(b.min, m->pos);
            vu0AddTo58260(b.max, m->pos);
            func_00370888(self->desc, &b, vu0Add58260(m->getPos(), self->center));
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358380);
#ifdef SKIP_ASM
struct sSerVEntry_58380 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sMultiPart_58380 {
    void* owner;            // 0x0
    int count;              // 0x4
    void* data;             // 0x8
    int* items;             // 0xC
    void* desc;             // 0x10
};

extern "C" void func_00370AA8(void* desc, void* stream);

extern "C" void func_00358380(sMultiPart_58380* self, void* stream)
{
    sSerVEntry_58380* e = &(*(sSerVEntry_58380**)stream)[1];
    e->fn((char*)stream + e->delta, self, 4);
    e = &(*(sSerVEntry_58380**)stream)[1];
    e->fn((char*)stream + e->delta, &self->count, 4);
    e = &(*(sSerVEntry_58380**)stream)[1];
    e->fn((char*)stream + e->delta, self->data, 0xD8);
    func_00370AA8(self->desc, stream);
    e = &(*(sSerVEntry_58380**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x40, 0x10);
    e = &(*(sSerVEntry_58380**)stream)[1];
    e->fn((char*)stream + e->delta, (char*)self + 0x20, 0x20);
    if (self->count > 0) {
        e = &(*(sSerVEntry_58380**)stream)[1];
        e->fn((char*)stream + e->delta, self->items, self->count << 2);
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003584B8);
#ifdef SKIP_ASM
class func_003584B8_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
};

extern "C" void func_003584B8(void* self, func_003584B8_cObj* obj)
{
    obj->v01(self, 4);
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003584F0);
#ifdef SKIP_ASM
extern void* D_004A4040;
extern void* D_0048EDE0[];
extern "C" void* func_00354850(void* self, void* a1, int type);

extern "C" void* func_003584F0(void* self, void* a1)
{
    char* s = (char*)self;
    int i;
    func_00354850(self, a1, 0x12);
    *(void***)(s + 0xC) = D_0048EDE0;
    unsigned int* p = (unsigned int*)(s + 0x18);
    for (i = 0x7F; i != -1; i--, p++) {
        *p = 0xFFFFFFFF;
    }
    D_004A4040 = self;
    for (i = 0; i < 0x80; i++) {
        ((unsigned int*)(s + 0x18))[i] = 0xFFFFFFFF;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358588);
#ifdef SKIP_ASM
extern void* D_004A4040;
extern void* D_0048EDE0[];
extern "C" void* cSortObjNode_cSortObjNode(void* self, void* a1, void* stream);
extern "C" void func_00358780(void* self, int idx);

class func_00358588_cStream {
public:
    virtual void v01();
    virtual void v02(void* buf, int size);
};

extern "C" void* func_00358588(void* self, void* a1, func_00358588_cStream* stream)
{
    char* s = (char*)self;
    int i;
    int j;
    cSortObjNode_cSortObjNode(self, a1, stream);
    *(void***)(s + 0xC) = D_0048EDE0;
    unsigned int* p = (unsigned int*)(s + 0x18);
    for (j = 0x7F; j != -1; j--, p++) {
        *p = 0xFFFFFFFF;
    }
    D_004A4040 = self;
    stream->v02(s + 0x18, 0x200);
    for (i = 0; i < 0x80; i++) {
        if (((unsigned int*)(s + 0x18))[i] != 0xFFFFFFFF) {
            func_00358780(self, i);
        }
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358668);
#ifdef SKIP_ASM
extern void* D_004A4040;
extern void* D_0048EDE0[];
extern "C" void func_00358998(void* self, int idx);
// PORT: func_00354920__FPv is the ObjNode deleting dtor; it takes (self, flags).
extern void* func_00354920_dtor(void* self, int flags) __asm__("func_00354920__FPv");

extern "C" void func_00358668(void* self, int flags)
{
    char* s = (char*)self;
    int i;
    *(void***)(s + 0xC) = D_0048EDE0;
    for (i = 0; i < 0x80; i++) {
        if (((unsigned int*)(s + 0x18))[i] != 0xFFFFFFFF) {
            func_00358998(self, i);
        }
    }
    D_004A4040 = 0;
    func_00354920_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358700);
#ifdef SKIP_ASM
extern void* D_004A4040;
extern "C" void func_00358998(void* self, int idx);

struct sMpSlot_8700 {
    unsigned char kind;
    unsigned char pad[3];
};

struct sMpMgr_8700 {
    char pad[0x18];
    sMpSlot_8700 slots[128];
};

extern "C" void func_00358700(int kind)
{
    int i;
    if (D_004A4040 != 0) {
        for (i = 0; i < 0x80; i++) {
            sMpMgr_8700* m = (sMpMgr_8700*)D_004A4040;
            if (((unsigned int*)((char*)m + 0x18))[i] != 0xFFFFFFFF && m->slots[i].kind == kind) {
                func_00358998(m, i);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358780);
#ifdef SKIP_ASM
struct sMpVec4_8780 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sMpBox_8780 {
    sMpVec4_8780 min;
    sMpVec4_8780 max;
};
struct sMpCell_8780 {
    int level;
    int x, y, z;
};
struct sMpNode_8780 {
    sMpNode_8780* child[2][2][2];   // 0x00
    void* lists[3];                 // 0x20
    int empty()
    {
        if (child[0][0][0] || child[0][0][1] || child[0][1][0] || child[0][1][1] || child[1][0][0] ||
            child[1][0][1] || child[1][1][0] || child[1][1][1]) {
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if (lists[i]) return 0;
        }
        return 1;
    }
};
struct sMpRoot_8780 {
    sMpCell_8780 cell;
    sMpNode_8780* node;
};
struct sMpPart_8780 {
    char pad[0x20];
    int count;             // 0x20
    char* first;           // 0x24
};
struct sMpTable_8780 {
    char pad[0x44];
    unsigned int* entries; // 0x44
};
struct sMpMgr_8780 {
    char pad[0x8];
    sMpTable_8780** tables; // 0x8
};

extern "C" sMpMgr_8780** func_002D1BD8_8780(void) __asm__("func_002D1BD8");
extern "C" char* func_002D1BE0(void);
extern "C" void func_00328F28(void* out, const void* box);
extern "C" void func_003284B8(void* node, int idx, void* item, const void* target, const void* cur);
void operator_delete(int*);

static inline void* refToPtr_8780(unsigned int p)
{
    return (void*)(p << 2);
}

static inline void* lookup_8780(sMpTable_8780* t, unsigned int idx)
{
    unsigned int p = t->entries[idx] >> 8;
    if (p == 0) {
        return 0;
    }
    return refToPtr_8780(p);
}

struct sMpRef_8780 {
    unsigned int id;

    void* get(sMpMgr_8780* w)
    {
        sMpTable_8780* t = w->tables[id & 0xFF];
        if (t == 0) {
            return 0;
        }
        return lookup_8780(t, id >> 8);
    }
};

static inline sMpRoot_8780* findRoot_8780(char* w, int x, int y, int z)
{
    sMpRoot_8780* r = (sMpRoot_8780*)w;
    sMpRoot_8780* rx = x >= 0 ? r : r + 4;
    sMpRoot_8780* ry = y >= 0 ? rx : rx + 2;
    sMpRoot_8780* rz = z >= 0 ? ry : ry + 1;
    return rz;
}

static inline void remove_8780(char* w, void* item, const sMpBox_8780* box)
{
    (*(int*)(w + 0xA0))++;
    sMpCell_8780 c;
    func_00328F28(&c, box);
    sMpRoot_8780* r = findRoot_8780(w, c.x, c.y, c.z);
    func_003284B8(r->node, 2, item, &c, &r->cell);
    if (r->node->empty()) {
        operator_delete((int*)r->node);
        r->node = 0;
    }
}

// Removes every particle node of slot 'idx' from the world's spatial tree.
extern "C" void func_00358780(void* self, int idx)
{
    sMpRef_8780 ref = ((sMpRef_8780*)((char*)self + 0x18))[idx];
    sMpPart_8780* part = (sMpPart_8780*)ref.get(*func_002D1BD8_8780());
    char* node = part->first;
    for (int i = 0; i < part->count; i++) {
        sMpBox_8780 box;
        box.min.x = *(float*)(node + 0x6C);
        box.min.y = *(float*)(node + 0x70);
        box.min.z = *(float*)(node + 0x74);
        box.min.w = 1.0f;
        box.max.x = *(float*)(node + 0x78);
        box.max.y = *(float*)(node + 0x7C);
        box.max.z = *(float*)(node + 0x80);
        box.max.w = 1.0f;
        remove_8780(func_002D1BE0(), node, &box);
        node = *(char**)(node + 0x64);
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358998);
#ifdef SKIP_ASM
struct sMpVec4_8998 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sMpBox_8998 {
    sMpVec4_8998 min;
    sMpVec4_8998 max;
};
struct sMpCell_8998 {
    int level;
    int x, y, z;
};
struct sMpRoot_8998 {
    sMpCell_8998 cell;
    void* node;
};
struct sMpPart_8998 {
    char pad[0x20];
    int count;             // 0x20
    char* first;           // 0x24
};
struct sMpTable_8998 {
    char pad[0x44];
    unsigned int* entries; // 0x44
};
struct sMpMgr_8998 {
    char pad[0x8];
    sMpTable_8998** tables; // 0x8
};

extern "C" sMpMgr_8998** func_002D1BD8_8998(void) __asm__("func_002D1BD8");
extern "C" char* func_002D1BE0(void);
extern "C" void func_00328F28(void* out, const void* box);
extern "C" void func_00328C20(void* root, int idx, void* item, const void* target);

static inline void* refToPtr_8998(unsigned int p)
{
    return (void*)(p << 2);
}

static inline void* lookup_8998(sMpTable_8998* t, unsigned int idx)
{
    unsigned int p = t->entries[idx] >> 8;
    if (p == 0) {
        return 0;
    }
    return refToPtr_8998(p);
}

struct sMpRef_8998 {
    unsigned int id;

    void* get(sMpMgr_8998* w)
    {
        sMpTable_8998* t = w->tables[id & 0xFF];
        if (t == 0) {
            return 0;
        }
        return lookup_8998(t, id >> 8);
    }
};

static inline sMpRoot_8998* findRoot_8998(char* w, int x, int y, int z)
{
    sMpRoot_8998* r = (sMpRoot_8998*)w;
    sMpRoot_8998* rx = x >= 0 ? r : r + 4;
    sMpRoot_8998* ry = y >= 0 ? rx : rx + 2;
    sMpRoot_8998* rz = z >= 0 ? ry : ry + 1;
    return rz;
}

static inline void insert_8998(char* w, void* item, const sMpBox_8998* box)
{
    sMpCell_8998 c;
    func_00328F28(&c, box);
    func_00328C20(findRoot_8998(w, c.x, c.y, c.z), 2, item, &c);
}

// Re-inserts every particle node of slot 'idx' into the world's spatial tree, then frees the slot.
extern "C" void func_00358998(void* self, int idx)
{
    sMpRef_8998 ref = ((sMpRef_8998*)((char*)self + 0x18))[idx];
    sMpPart_8998* part = (sMpPart_8998*)ref.get(*func_002D1BD8_8998());
    char* node = part->first;
    for (int i = 0; i < part->count; i++) {
        sMpBox_8998 box;
        box.min.x = *(float*)(node + 0x6C);
        box.min.y = *(float*)(node + 0x70);
        box.min.z = *(float*)(node + 0x74);
        box.min.w = 1.0f;
        box.max.x = *(float*)(node + 0x78);
        box.max.y = *(float*)(node + 0x7C);
        box.max.z = *(float*)(node + 0x80);
        box.max.w = 1.0f;
        insert_8998(func_002D1BE0(), node, &box);
        node = *(char**)(node + 0x64);
    }
    ((unsigned int*)((char*)self + 0x18))[idx] = 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358B28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sMPRef8B28 {
    unsigned int id;
    sMPRef8B28() : id(0xFFFFFFFF) {}
};

struct sMPMgr8B28 {
    char pad_0x0[0x18];
    sMPRef8B28 slots[128];          // 0x18
};

extern void* D_004A4040;
extern sMPMgr8B28* D_004A4040_mgr8B28 __asm__("D_004A4040");
extern char D_004A4048[];
extern "C" void* cMemMan_alloc(unsigned int size, const char* tag, int flags, int d);
extern "C" void* func_003584F0(void* self, void* a1);
extern "C" void func_00358780(void* self, int idx);
extern "C" void func_00358998(void* self, int idx);

extern "C" void func_00358B28(sMPRef8B28 key, int add)
{
    if (D_004A4040 == 0) {
        func_003584F0(cMemMan_alloc(0x218, D_004A4048, 0x20000000, 0), (void*)1);
    }
    sMPRef8B28 kFree;
    int idx = -1;
    for (int i = 0; i < 128; i++) {
        if (idx == -1 && D_004A4040_mgr8B28->slots[i].id == kFree.id) {
            idx = i;
        }
        if (D_004A4040_mgr8B28->slots[i].id == key.id) {
            idx = i;
            goto found;
        }
    }
found:
    sMPMgr8B28* mgr = D_004A4040_mgr8B28;
    if (idx != -1) {
        sMPRef8B28& s = mgr->slots[idx];
        if (s.id == key.id) {
            if (add == 0) {
                return;
            }
        } else if (add != 0) {
            return;
        }
        mgr->slots[idx] = key;
        if (add != 0) {
            func_00358998(mgr, idx);
        } else {
            func_00358780(mgr, idx);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358C30);
#ifdef SKIP_ASM
struct sSerVEntry_00358C30 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00354980(void* self, void* stream);

extern "C" void func_00358C30(void* self, void* stream)
{
    func_00354980(self, stream);
    sSerVEntry_00358C30* vt = *(sSerVEntry_00358C30**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x18, 0x200);
}
#endif

INCLUDE_ASM("object/multiparticle", func_00358C80);

//100%
INCLUDE_ASM("object/multiparticle", func_00358DB0);
#ifdef SKIP_ASM
extern "C" void* func_00341C80(void* self, void* a, void* stream);
extern "C" void func_00359030(void* self);
extern char D_0048EC28[];
extern char D_0048EA20[];

struct sStreamVE_8DB0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

// Element type with an empty constructor; the array new leaves only its loop counters.
struct sParticle_8DB0 {
    char data[0x40];
    sParticle_8DB0() {}
};

extern "C" void* func_00358DB0(void* self, void* a1, void* stream)
{
    char* s = (char*)self;
    sParticle_8DB0** pp = (sParticle_8DB0**)(s + 0x84);
    func_00341C80(s + 0x18, a1, stream);
    *(void**)(s + 0x54) = D_0048EC28;
    sStreamVE_8DB0* vt = *(sStreamVE_8DB0**)stream;
    vt[2].fn((char*)stream + vt[2].delta, self, 0x18);
    *pp = new (D_0048EA20, 0x20000000, 0) sParticle_8DB0[*(int*)(s + 0x74)];
    func_00359030(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358E50);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
void cMemMan_free(void*);
extern "C" void func_00341CF0(void* p, int flags);
extern char D_0048EC28[];

extern "C" void func_00358E50(void* self, int flags)
{
    *(void**)((char*)self + 0x54) = D_0048EC28;
    void* buf = *(void**)((char*)self + 0x84);
    if (buf != 0) {
        cMemMan_free(buf);
    }
    func_00341CF0((char*)self + 0x18, 0);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358EB8);
#ifdef SKIP_ASM
extern "C" void func_00341D48(void* p);
extern "C" int func_0034EBA0(void* p);

extern "C" int func_00358EB8(void* self)
{
    char* s = (char*)self;
    *(float*)(s + 0x3C) = 10000000000.0f;
    *(float*)(s + 0x40) = 10000000000.0f;
    if (*(signed char*)(s + 0x15) == 0) {
        if (*(signed char*)(s + 0x14) != 0) {
            int t = *(int*)(s + 0x24);
            if (t >= 0) {
                if (t > 0) {
                    *(int*)(s + 0x24) = t - 1;
                } else {
                    float pos = *(float*)(s + 0x4) + *(float*)(s + 0x0);
                    float max = *(float*)(s + 0xC);
                    float v = *(float*)(s + 0x34);
                    *(float*)(s + 0x3C) = v;
                    *(float*)(s + 0x40) = v;
                    *(float*)(s + 0x4) = pos;
                    if (max <= pos) {
                        *(float*)(s + 0x4) = max;
                        if (*(signed char*)(s + 0x16) != 0) {
                            *(signed char*)(s + 0x15) = 1;
                        }
                        *(signed char*)(s + 0x14) = 0;
                    }
                    if (func_0034EBA0(s + 0x34) == 0) {
                        return 0;
                    }
                }
            }
        } else {
            func_00341D48(s + 0x18);
            return 1;
        }
        *(unsigned short*)(s + 0x5A) |= 1;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358F90);
#ifdef SKIP_ASM
struct sMpQuad {
    float v[4];
} __attribute__((aligned(16)));

extern sMpQuad D_004FF120;
extern "C" void func_00356AE0(void* self, void* out);

extern "C" void func_00358F90(void* self, void* out)
{
    func_00356AE0((char*)self + 0x48, out);
    *(sMpQuad*)((char*)out + 0x20) = D_004FF120;
    *(sMpQuad*)((char*)out + 0x30) = D_004FF120;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00358FD0);
#ifdef SKIP_ASM
extern "C" void func_00341FE8(void*);
extern "C" void func_00359030(void*);

extern "C" void func_00358FD0(void* self, int msg)
{
    if (msg == 0x82) {
        if (*(unsigned short*)((char*)self + 0x14) == 0) {
            *(float*)((char*)self + 0x10) = *(float*)((char*)self + 0x38);
            func_00359030(self);
            *(char*)((char*)self + 0x14) = 1;
            *(float*)((char*)self + 0x4) = *(float*)((char*)self + 0x8);
        }
    } else {
        func_00341FE8((char*)self + 0x18);
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00359030);
#ifdef SKIP_ASM
struct sMpItem_9030 {
    char pad_0x0[0x90];
    float mtx[16];          // 0x90
} __attribute__((aligned(16)));

struct sMpPart_9030 {
    int field_0x0;
    int field_0x4;
    void* info;             // 0x8
    int field_0xc;
};

struct sMpModel_9030 {
    int field_0x0;
    int count;              // 0x4
    sMpPart_9030* parts;    // 0x8
};

struct sMpInst_9030 {
    char pad_0x0[0x80];
    sMpModel_9030* model;   // 0x80
};

struct sMpNode_9030 {
    char pad_0x0[0x48];
    sMpItem_9030* items;    // 0x48 (self + 0x7C)
};

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMatrix_9030(void* dst, void* src)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

struct sMtx_9030 {
    float m[16];
};

struct sMp_9030 {
    char pad_0x0[0x60];
    sMpInst_9030* inst;     // 0x60
    char pad_0x64[0x10];
    int count;              // 0x74
    char pad_0x78[0xC];
    sMtx_9030* mtx;         // 0x84
};

// Gathers the world matrices of the model's active parts into the matrix buffer at 0x84.
extern "C" void func_00359030(void* vself)
{
    sMp_9030* self = (sMp_9030*)vself;
    if (self->count <= 0) {
        return;
    }
    sMpModel_9030* model = self->inst->model;
    int n = 0;
    sMpPart_9030* p = model->parts;
    for (int i = 0; i < model->count; i++, p++) {
        if (p->info != 0) {
            sMpNode_9030* node = (sMpNode_9030*)((char*)self + 0x34);
            vu0CopyMatrix_9030(&self->mtx[n], node->items[n].mtx);
            n++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003590C8);
#ifdef SKIP_ASM
extern "C" void func_0034FD90(void*);

extern "C" void func_003590C8(void* self)
{
    if (*(signed char*)((char*)self + 0x15) == 0) {
        func_0034FD90((char*)self + 0x48);
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003590F0);
#ifdef SKIP_ASM
struct sVEntry003590F0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00342150(void* self, void* stream);

extern "C" void func_003590F0(void* self, void* obj)
{
    func_00342150((char*)self + 0x18, obj);
    sVEntry003590F0* vt = *(sVEntry003590F0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x18);
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00359140);
#ifdef SKIP_ASM
struct sMpItem_9140 {
    char data[0xD0];
};

struct sMpMtx_9140 {
    float m[16];
};

struct sMpPartInfo_9140 {
    char pad_0x0[0x1C];
    int active;             // 0x1C
};

struct sMpPart_9140 {
    int field_0x0;
    int field_0x4;
    sMpPartInfo_9140* info; // 0x8
    int field_0xc;
};

struct sMpModel_9140 {
    int field_0x0;
    int count;              // 0x4
    sMpPart_9140* parts;    // 0x8
};

struct sMpInst_9140 {
    char pad_0x0[0x80];
    sMpModel_9140* model;   // 0x80
};

struct sMp_9140 {
    char pad_0x0[0x14];
    signed char f14;        // 0x14
    signed char f15;        // 0x15
    signed char f16;        // 0x16
    signed char f17;        // 0x17
    char pad_0x18[0x48];
    sMpInst_9140* inst;     // 0x60
    char pad_0x64[0x18];
    sMpItem_9140* items;    // 0x7C
    int field_0x80;
    sMpMtx_9140* mtx;       // 0x84
};

extern "C" void func_0034E348(void* self);
extern "C" void func_00351948(sMpItem_9140* item, sMpMtx_9140* mtx);

extern "C" void func_00359140(sMp_9140* self)
{
    func_0034E348((char*)self + 0x34);
    if (self->items == 0) {
        return;
    }
    if (self->f14 == 0) {
        if (self->f17 == 0) {
            return;
        }
        if (self->f15 == 0) {
            return;
        }
    }
    sMpModel_9140* model = self->inst->model;
    int n = 0;
    sMpPart_9140* p = model->parts;
    for (int i = 0; i < model->count; i++, p++) {
        if (p->info->active != 0) {
            func_00351948(&self->items[n], (sMpMtx_9140*)((char*)self->mtx + (n << 6)));
            n++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00359228);
#ifdef SKIP_ASM
extern "C" void func_00341AA0(void* self, int a, int type, int b, int c);
extern void* D_0048EA70[];

extern "C" void* func_00359228(void* self, int a, int b, int c)
{
    func_00341AA0(self, a, 2, b, c);
    *(void***)((char*)self + 0x3C) = D_0048EA70;
    *(int*)((char*)self + 0x6C) = 0;
    *(int*)((char*)self + 0x4) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00359270);
#ifdef SKIP_ASM
struct sVEntry00359270 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void* func_00341C80(void* self, void* a, void* stream);
extern void* D_0048EA70[];

extern "C" void* func_00359270(void* self, void* a, void* stream)
{
    func_00341C80(self, a, stream);
    *(void***)((char*)self + 0x3C) = D_0048EA70;
    sVEntry00359270* vt = *(sVEntry00359270**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x6C, 4);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003592D0);
#ifdef SKIP_ASM
extern "C" void func_00341D48(void* p);

struct sVEntry_3592D0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" int func_003592D0(void* self)
{
    char* s = (char*)self;
    *(float*)(s + 0x24) = 10000000000.0f;
    *(float*)(s + 0x28) = 10000000000.0f;
    if (*(int*)(s + 0x8) == 0) {
        float v = *(float*)(s + 0x6C);
        int t = *(int*)(s + 0xC);
        if (v > 0.0f) {
            if (t >= 0) {
                if (t == 0 && v > 0.0f) {
                    float r = v - __builtin_fabsf(*(float*)(s + 0x10));
                    *(float*)(s + 0x6C) = r;
                    if (r < 0.0f) {
                        *(float*)(s + 0x6C) = 0.0f;
                    }
                }
                func_00341D48(s);
                if (*(float*)(s + 0x6C) > 0.0f) {
                    *(int*)(s + 0x4) = 1;
                } else {
                    *(int*)(s + 0x4) = 0;
                }
                return 1;
            }
        } else {
            if (t > 0) {
                *(int*)(s + 0xC) = t - 1;
            }
            if (*(int*)(s + 0x8) != 0) {
                char* obj = s + 0x30;
                sVEntry_3592D0* e = &(*(sVEntry_3592D0**)(s + 0x3C))[34];
                e->fn(obj + e->delta, 1);
                return 0;
            }
        }
        *(unsigned short*)(s + 0x42) |= 1;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_003593D0);
#ifdef SKIP_ASM
// PORT: func_00341FE8 really takes (self, id, value); the unit declares it (void*).
extern "C" void func_00341FE8_set(void* self, int id, float v) __asm__("func_00341FE8");

extern "C" void func_003593D0(void* self, int id, float v)
{
    if (id == 0x8C) {
        *(float*)((char*)self + 0x6C) += v * 0.03333333507180214f;
    } else {
        func_00341FE8_set(self, id, v);
    }
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00359410);
#ifdef SKIP_ASM
struct sSerVEntry_00359410 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00342150(void* self, void* stream);

extern "C" void func_00359410(void* self, void* stream)
{
    func_00342150(self, stream);
    sSerVEntry_00359410* vt = *(sSerVEntry_00359410**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x6C, 0x4);
}
#endif

//100%
INCLUDE_ASM("object/multiparticle", func_00359460);
#ifdef SKIP_ASM
extern char D_0048F250[];
extern "C" void func_003451C0(void* ref, int id);
extern "C" void func_00359688(void* self, float v);
float AIrandf(float lo, float hi);

extern "C" void* func_00359460(char* self, char* desc)
{
    *(void**)self = D_0048F250;
    *(unsigned int*)(self + 0xD8) = 0xFFFFFFFF;
    *(int*)(self + 0xE0) = 0;
    *(int*)(self + 0xDC) = 0;
    *(int*)(self + 0xE4) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x30) = *(int*)(desc + 0x8);
    *(int*)(self + 0x34) = *(int*)(desc + 0xC);
    *(float*)(self + 0x38) = *(float*)(desc + 0x14) * 0.01745329424738884f;
    *(float*)(self + 0x40) = *(float*)(desc + 0x24) * 100.0f;
    *(float*)(self + 0x44) = *(float*)(desc + 0x28);
    func_003451C0(self + 0xD8, *(int*)(desc + 0x4));
    func_00359688(self, *(float*)(desc + 0x10));
    if (*(float*)(desc + 0x10) >= 0.0f) {
        *(float*)(self + 0x3C) = 0.0f;
    } else {
        *(float*)(self + 0x3C) = *(float*)(self + 0xE4);
    }
    float zero = 0.0f;
    *(int*)(self + 0x54) = *(int*)(desc + 0x20) != 0;
    *(int*)(self + 0x50) = 0;
    if (*(float*)(desc + 0x18) != zero) {
        *(float*)(self + 0x3C) = *(float*)(desc + 0x18);
    }
    *(float*)(self + 0x3C) += AIrandf(-1.0f, 1.0f) * *(float*)(desc + 0x1C);
    if (*(float*)(self + 0x3C) < zero || *(float*)(self + 0xE4) < *(float*)(self + 0x3C)) {
        *(float*)(self + 0x3C) = zero;
    }
    *(sMpQuad*)(self + 0xB0) = D_004FF120;
    *(sMpQuad*)(self + 0xC0) = D_004FF120;
    *(int*)(self + 0x58) = 1;
    *(int*)(self + 0xD0) = 0;
    *(int*)(self + 0xD4) = 0;
    return self;
}
#endif

