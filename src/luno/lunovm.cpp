#include "common.h"

// A script value: {word0, word1, type}. Type 4 is a table, word0 -> cLunoTable.
struct cLunoValue {
    int word0;
    int word1;
    int type;
};

// Table chain node: 0x20 bytes, vtable pointer at +0x1C (gcc 2.95 layout).
struct cLunoVtEntry {
    short delta;
    short index;
    void (*func)(void*, int);
};

struct cLunoTableEntry {
    char pad_0x00[0x1C];
    cLunoVtEntry* vtable;
};

struct cLunoTable {
    char pad_0x00[0x8];
    int refCount;
    int modulus;
    cLunoTableEntry* nodes;
};

// Table reference: word0 of a type-4 value.
struct cLunoTableRef {
    cLunoTable* table;
};

void operator_delete(int* ptr);
void cMemMan_free(void* ptr);
extern "C" void func_00224F30(cLunoTableRef* ref);
extern "C" void func_00224DF0(cLunoTableRef* ref, int flags);

INCLUDE_ASM("luno/lunovm", luno_cLunoVM_execute);

//100%
INCLUDE_ASM("luno/lunovm", func_00224C00);
#ifdef SKIP_ASM
struct sVEntry00224C00 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00224C00(void* self, sVEntry00224C00** stream, int base)
{
    int off;
    int v;
    off = *(int*)((char*)self + 0x0) - base;
    (*stream)[1].fn((char*)stream + (*stream)[1].delta, &off, 4);
    v = *(int*)((char*)self + 0x4);
    (*stream)[1].fn((char*)stream + (*stream)[1].delta, &v, 4);
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00224C78);
#ifdef SKIP_ASM
struct sVEntry00224C78 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_00224C78(void* self, sVEntry00224C78** stream, int base)
{
    int buf[2];
    (*stream)[2].fn((char*)stream + (*stream)[2].delta, &buf[0], 4);
    *(int*)((char*)self + 0x0) = base + buf[0];
    (*stream)[2].fn((char*)stream + (*stream)[2].delta, &buf[1], 4);
    *(int*)((char*)self + 0x4) = buf[1];
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00224D00);
#ifdef SKIP_ASM
extern "C" void func_00224D00(cLunoTable* self, int flags)
{
    cLunoTableEntry* nodes = self->nodes;

    if (nodes != 0) {
        cLunoTableEntry* e = nodes + ((int*)nodes)[-4];

        while (self->nodes != e) {
            e--;
            e->vtable[1].func((char*)e + e->vtable[1].delta, 0);
        }
        cMemMan_free((char*)self->nodes - 0x10);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00224DA0);
#ifdef SKIP_ASM
extern "C" void luno_cLunoTable_constructTable(cLunoTableRef* self);

extern "C" cLunoTableRef* func_00224DA0(cLunoTableRef* self)
{
    self->table = 0;
    luno_cLunoTable_constructTable(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00224DD0);
#ifdef SKIP_ASM
extern "C" void **func_00224DD0(void **arg0, void **arg1) {
    void *temp_6;

    temp_6 = *arg1;
    *arg0 = temp_6;
    (*(int *)((char*)(temp_6) + (8))) = (int) ((*(int *)((char*)(temp_6) + (8))) + 1);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00224DF0);
#ifdef SKIP_ASM
extern "C" void func_00224DF0(cLunoTableRef* self, int flags)
{
    if (--self->table->refCount == 0) {
        func_00224F30(self);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", luno_cLunoTable_constructTable);
#ifdef SKIP_ASM
// PORT: the game's operator new is cMemMan_alloc(size, tag, flags, 0); bound by asm label
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_00479860[];
extern char D_00479870[];
extern char D_00479890[];

struct cLunoNode_ct {
    cLunoValue key;
    cLunoValue val;
    cLunoNode_ct* next;
    void* vt;
    cLunoNode_ct()
    {
        vt = D_00479890;
        key.type = 0;
        key.word0 = 0;
        val.type = 0;
        val.word0 = 0;
        next = 0;
    }
    ~cLunoNode_ct() {}
};

extern "C" void ct_impl(cLunoTableRef* ref, int n) __asm__("luno_cLunoTable_constructTable");
extern "C" void ct_impl(cLunoTableRef* ref, int n)
{
    cLunoTable* t = (cLunoTable*)new (D_00479860, 0xA0000000, 0) cLunoTable;
    cLunoTableEntry** slot = &t->nodes;
    t->nodes = 0;
    t->refCount = 0;
    t->modulus = 0;
    ref->table = t;
    *slot = (cLunoTableEntry*)new (D_00479870, 0xA0000000, 0) cLunoNode_ct[n];
    ref->table->modulus = n - 1;
    ref->table->refCount = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("luno/lunovm", func_00224F30);
#ifdef SKIP_ASM
extern "C" void func_00224D00(cLunoTable* table, int flags);

extern "C" void func_00224F30(cLunoTableRef* ref)
{
    cLunoTable* t = ref->table;
    if (t != 0) {
        func_00224D00(t, 3);
    }
    ref->table = 0;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00224F68);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_00479870[];
extern char D_00479890[];

struct cLunoNode_224F68 {
    cLunoValue key;
    cLunoValue val;
    cLunoNode_224F68* next;
    void* vt;
    cLunoNode_224F68()
    {
        vt = D_00479890;
        key.type = 0;
        key.word0 = 0;
        val.type = 0;
        val.word0 = 0;
        next = 0;
    }
    ~cLunoNode_224F68() {}
};

extern "C" void func_00224F68(cLunoTableRef* ref)
{
    if (ref->table->nodes != 0) {
        cLunoTableEntry* p = ref->table->nodes + *(int*)((char*)ref->table->nodes - 0x10);
        while (ref->table->nodes != p) {
            p--;
            p->vtable[1].func((char*)p + p->vtable[1].delta, 0);
        }
        cMemMan_free((char*)ref->table->nodes - 0x10);
    }
    cLunoTableEntry** slot = &ref->table->nodes;
    *slot = (cLunoTableEntry*)new (D_00479870, 0xA0000000, 0) cLunoNode_224F68[ref->table->modulus + 1];
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00225068);
#ifdef SKIP_ASM
extern "C" cLunoTableRef* func_00225068(cLunoTableRef* self, cLunoTableRef* other)
{
    if (self->table != other->table) {
        if (self->table != 0) {
            if (--self->table->refCount == 0) {
                func_00224F30(self);
            }
        }
        self->table = other->table;
        self->table->refCount++;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_002250E0);
#ifdef SKIP_ASM
extern "C" void func_00225B90(cLunoValue* self, int flags);
extern cLunoValue D_004C9098;
void* func_00226620(void* self);

struct cLunoNode_50E0 {
    cLunoValue key;     // 0x00
    cLunoValue value;   // 0x0C
    cLunoNode_50E0* next;    // 0x18
    void* vtable;       // 0x1C
};

static inline int lunoKeyEquals_50E0(cLunoValue* a, cLunoValue* b)
{
    if (b->type == a->type) {
        return a->word0 == b->word0;
    }
    if (a->type == 2 && b->type == 1) {
        return *(float*)&a->word0 == (float)b->word0;
    }
    if (a->type == 1 && b->type == 2) {
        return a->word0 == (int)*(float*)&b->word0;
    }
    if (a->type == 3 && b->type == 1) {
        return a->word0 == b->word0;
    }
    return 0;
}

extern "C" cLunoValue* func_002250E0(cLunoTableRef* self, unsigned int arg1)
{
    cLunoTable* t = self->table;
    cLunoNode_50E0* n = (cLunoNode_50E0*)t->nodes + arg1 % (unsigned int)t->modulus;
    if (n->value.type != 0) {
        do {
            cLunoValue key;
            key.type = 3;
            *(int*)func_00226620(&key) = arg1;
            int eq = lunoKeyEquals_50E0(&n->key, &key);
            func_00225B90(&key, 2);
            if (eq) {
                return &n->value;
            }
            n = n->next;
        } while (n != 0);
    }
    return &D_004C9098;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00225248);
#ifdef SKIP_ASM
extern cLunoValue D_004C9098;

// Hash node: key, value, chain link (0x20 bytes, vtable at +0x1C).
struct cLunoNode {
    cLunoValue key;     // 0x00
    cLunoValue value;   // 0x0C
    cLunoNode* next;    // 0x18
    void* vtable;       // 0x1C
};

static inline int lunoKeyEquals(cLunoValue* a, cLunoValue* b)
{
    if (b->type == a->type) {
        return a->word0 == b->word0;
    }
    if (a->type == 2 && b->type == 1) {
        return *(float*)&a->word0 == (float)b->word0;
    }
    if (a->type == 1 && b->type == 2) {
        return a->word0 == (int)*(float*)&b->word0;
    }
    if (a->type == 3 && b->type == 1) {
        return a->word0 == b->word0;
    }
    return 0;
}

// Table lookup: returns the value stored under key, or the nil value.
extern "C" cLunoValue* func_00225248(cLunoTableRef* self, cLunoValue* key)
{
    cLunoTable* t = self->table;
    cLunoNode* n = (cLunoNode*)t->nodes + (unsigned int)key->word0 % (unsigned int)t->modulus;
    if (n->value.type != 0) {
        do {
            if (lunoKeyEquals(&n->key, key)) {
                return &n->value;
            }
            n = n->next;
        } while (n != 0);
    }
    return &D_004C9098;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", luno_cLunoTable_set);
#ifdef SKIP_ASM
extern char D_00479880[];
extern char D_00479890[];

struct sLunoPair_set {
    int word0;
    int word1;
};

// PORT: the game's operator new is cMemMan_alloc(size, tag, flags, 0); bound by asm label
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");

// Table chain node (same layout as cLunoNode / cLunoNode_224F68).
struct cLunoNode_set {
    cLunoValue key;            // 0x00
    cLunoValue value;          // 0x0C
    cLunoNode_set* next;       // 0x18
    cLunoVtEntry* vtable;      // 0x1C
};

// cLunoValue::operator= (inline Clear of the destination, then copy by type)
#define LUNO_ASSIGN_SET(D, S)                                              \
    {                                                                      \
        cLunoValue* d = &(D);                                              \
        if ((D).type == 4) {                                               \
            func_00224DF0((cLunoTableRef*)d, 2);                           \
        }                                                                  \
        d->type = 0;                                                       \
        (D).word0 = 0;                                                     \
        if ((S)->type == 4) {                                              \
            func_00225068((cLunoTableRef*)d, (cLunoTableRef*)(S));         \
        } else if ((S)->type == 5) {                                       \
            *(sLunoPair_set*)&(D) = *(sLunoPair_set*)(S);                  \
        } else {                                                           \
            (D).word0 = (S)->word0;                                        \
        }                                                                  \
        d->type = (S)->type;                                               \
    }

static inline int lunoKeyEquals_set(cLunoValue* a, cLunoValue* b)
{
    if (b->type == a->type) {
        return a->word0 == b->word0;
    }
    if (a->type == 2 && b->type == 1) {
        return *(float*)&a->word0 == (float)b->word0;
    }
    if (a->type == 1 && b->type == 2) {
        return a->word0 == (int)*(float*)&b->word0;
    }
    if (a->type == 3 && b->type == 1) {
        return a->word0 == b->word0;
    }
    return 0;
}

// Table store: sets key to val (a nil value removes a chained entry); nil keys are ignored.
extern "C" void luno_cLunoTable_set(cLunoTableRef* self, cLunoValue* key, cLunoValue* val)
{
    if (key->type == 0) {
        return;
    }
    cLunoTable* t = self->table;
    cLunoNode_set* n = (cLunoNode_set*)t->nodes + (unsigned int)key->word0 % (unsigned int)t->modulus;
    if (n->value.type == 0) {
        LUNO_ASSIGN_SET(n->key, key)
        LUNO_ASSIGN_SET(n->value, val)
        return;
    }
    if (lunoKeyEquals_set(&n->key, key)) {
        LUNO_ASSIGN_SET(n->value, val)
        return;
    }
    cLunoNode_set* prev = n;
    for (n = n->next; n != 0; n = n->next) {
        if (lunoKeyEquals_set(&n->key, key)) {
            {
                cLunoValue* d = &n->value;
                if (n->value.type == 4) {
                    func_00224DF0((cLunoTableRef*)d, 2);
                }
                d->type = 0;
                // Expanded Clear(); the do/while(0) is the original macro's wrapper (changes scheduling).
                do {
                    n->value.word0 = 0;
                } while (0);
                if (val->type == 4) {
                    func_00225068((cLunoTableRef*)d, (cLunoTableRef*)val);
                } else if (val->type == 5) {
                    *(sLunoPair_set*)&n->value = *(sLunoPair_set*)val;
                } else {
                    n->value.word0 = val->word0;
                }
                d->type = val->type;
            }
            if (n->value.type == 0) {
                prev->next = n->next;
                if (n != 0) {
                    n->vtable[1].func((char*)n + n->vtable[1].delta, 3);
                }
            }
            return;
        }
        prev = n;
    }
    if (val->type != 0) {
        cLunoNode_set* node = (cLunoNode_set*)operator new(0x20, D_00479880, 0x20000000, 0);
        node->value.type = 0;
        node->value.word0 = 0;
        node->vtable = (cLunoVtEntry*)D_00479890;
        node->key.type = 0;
        node->key.word0 = 0;
        LUNO_ASSIGN_SET(node->key, key)
        LUNO_ASSIGN_SET(node->value, val)
        node->next = 0;
        prev->next = node;
    }
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_002257E0);
#ifdef SKIP_ASM
extern "C" void func_00225BE8(cLunoValue* self, sVEntry00224C00** stream, int base);

extern "C" void func_002257E0(void* vself, sVEntry00224C00** stream, int base)
{
    cLunoTableRef* self = (cLunoTableRef*)vself;
    (*stream)[1].fn((char*)stream + (*stream)[1].delta, self->table, 8);
    int cnt = 0;
    cLunoTable* t = self->table;
    cLunoNode* n = (cLunoNode*)t->nodes;
    for (int i = 0; i <= t->modulus; i++) {
        if (n->value.type != 0) {
            cnt++;
        }
        cLunoNode* next = n + 1;
        for (cLunoNode* m = n->next; m != 0; m = m->next) {
            if (m->value.type != 0) {
                cnt++;
            }
        }
        n = next;
    }
    (*stream)[1].fn((char*)stream + (*stream)[1].delta, &cnt, 4);
    if (cnt > 0) {
        cLunoNode* n = (cLunoNode*)self->table->nodes;
        for (int i = 0; i <= self->table->modulus; i++) {
            cLunoValue* v = &n->value;
            if (n->value.type != 0) {
                cnt--;
                func_00225BE8(&n->key, stream, base);
                func_00225BE8(v, stream, base);
            }
            cLunoNode* next = n + 1;
            for (cLunoNode* m = n->next; m != 0; m = m->next) {
                cLunoValue* mv = &m->value;
                if (m->value.type != 0) {
                    cnt--;
                    func_00225BE8(&m->key, stream, base);
                    func_00225BE8(mv, stream, base);
                }
            }
            n = next;
        }
    }
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_002259A8);
#ifdef SKIP_ASM
extern "C" void func_00225B90(cLunoValue* self, int flags);
extern "C" void func_00225CA0(cLunoValue* self, sVEntry00224C00** stream, int base);
extern "C" void luno_cLunoTable_set(cLunoTableRef* self, cLunoValue* key, cLunoValue* val);


struct cLunoNode_9A8 {
    cLunoValue key;
    cLunoValue val;
    cLunoNode_9A8* next;
    void* vt;
    cLunoNode_9A8()
    {
        vt = D_00479890;
        key.type = 0;
        key.word0 = 0;
        val.type = 0;
        val.word0 = 0;
        next = 0;
    }
    void operator delete[](void* p, unsigned int size);
};

extern "C" void func_002259A8(cLunoTableRef* self, sVEntry00224C00** stream, int base)
{
    if (self->table->nodes != 0) {
        cLunoTableEntry* p = self->table->nodes + *(int*)((char*)self->table->nodes - 0x10);
        while (self->table->nodes != p) {
            p--;
            p->vtable[1].func((char*)p + p->vtable[1].delta, 0);
        }
        cMemMan_free((char*)self->table->nodes - 0x10);
    }
    (*stream)[2].fn((char*)stream + (*stream)[2].delta, self->table, 8);
    cLunoTableEntry** slot = &self->table->nodes;
    *slot = (cLunoTableEntry*)new (D_00479870, 0xA0000000, 0) cLunoNode_9A8[self->table->modulus + 1];
    int i;
    int cnt;
    cLunoValue key;
    cLunoValue val;
    (*stream)[2].fn((char*)stream + (*stream)[2].delta, &cnt, 4);
    for (i = 0; i < cnt; i++) {
        key.type = 0;
        key.word0 = 0;
        func_00225CA0(&key, stream, base);
        val.type = 0;
        val.word0 = 0;
        func_00225CA0(&val, stream, base);
        luno_cLunoTable_set(self, &key, &val);
        func_00225B90(&val, 2);
        func_00225B90(&key, 2);
    }
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00225B90);
#ifdef SKIP_ASM
extern "C" void func_00225B90(cLunoValue* self, int flags)
{
    if (self->type == 4) {
        func_00224DF0((cLunoTableRef*)self, 2);
    }
    self->type = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("luno/lunovm", func_00225BE8);
#ifdef SKIP_ASM
extern "C" void func_00224C00(void* self, sVEntry00224C00** stream, int base);
extern "C" void func_002257E0(void* self, sVEntry00224C00** stream, int base);

extern "C" void func_00225BE8(cLunoValue* self, sVEntry00224C00** stream, int base)
{
    (*stream)[1].fn((char*)stream + (*stream)[1].delta, &self->type, 4);
    if (self->type == 5) {
        func_00224C00(self, stream, base);
    } else if (self->type == 4) {
        func_002257E0(self, stream, base);
    } else {
        (*stream)[1].fn((char*)stream + (*stream)[1].delta, self, 4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("luno/lunovm", func_00225CA0);
#ifdef SKIP_ASM
struct sLunoPair_225CA0 {
    int word0;
    int word1;
};

// PORT: func_00224DA0 forwards a size argument to constructTable (unit declares 1 arg).
extern "C++" cLunoTableRef* func_00224DA0_sz(cLunoTableRef* self, int size) __asm__("func_00224DA0");
// Non-POD (user copy ctor) so the local is BLKmode and shares the block-scoped slot.
struct cLunoRefTmp_225CA0 {
    cLunoTable* table;
    cLunoRefTmp_225CA0() {}
    cLunoRefTmp_225CA0(const cLunoRefTmp_225CA0&);
};
extern "C" void func_002259A8(cLunoTableRef* self, sVEntry00224C00** stream, int base);

static inline int lunoReadInt_225CA0(sVEntry00224C00** stream)
{
    int v;
    (*stream)[2].fn((char*)stream + (*stream)[2].delta, &v, 4);
    return v;
}

extern "C" void func_00225CA0(cLunoValue* self, sVEntry00224C00** stream, int base)
{
    int type = lunoReadInt_225CA0(stream);
    if (type == 5) {
        sLunoPair_225CA0 tmp;
        tmp.word0 = 0;
        tmp.word1 = 0;
        func_00224C78(&tmp, (sVEntry00224C78**)stream, base);
        if (self->type == 4) {
            func_00224DF0((cLunoTableRef*)self, 2);
        }
        self->type = 0;
        self->word0 = 0;
        *(sLunoPair_225CA0*)self = tmp;
        self->type = type;
    } else if (type == 4) {
        cLunoRefTmp_225CA0 ref;
        func_00224DA0_sz((cLunoTableRef*)&ref, 0x20);
        func_002259A8((cLunoTableRef*)&ref, stream, base);
        if (self->type == type) {
            func_00224DF0((cLunoTableRef*)self, 2);
        }
        self->type = 0;
        self->word0 = 0;
        func_00225068((cLunoTableRef*)self, (cLunoTableRef*)&ref);
        self->type = type;
        func_00224DF0((cLunoTableRef*)&ref, 2);
    } else {
        self->type = type;
        (*stream)[2].fn((char*)stream + (*stream)[2].delta, self, 4);
    }
}
#endif

INCLUDE_ASM("luno/lunovm", func_00225DE8);

//100%
INCLUDE_ASM("luno/lunovm", func_00226600__FPvii);
#ifdef SKIP_ASM
void func_00226600(void* self, int a1, int a2)
{
    *(int*)self = a1;
    *(int*)((char*)self + 0x4) = a2;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00226610__FPv);
#ifdef SKIP_ASM
void* func_00226610(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00226618__FPv);
#ifdef SKIP_ASM
void* func_00226618(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00226620__FPv);
#ifdef SKIP_ASM
void* func_00226620(void* self)
{
    return self;
}
#endif

extern cLunoValue D_004C9098;

//100%
INCLUDE_ASM("luno/lunovm", func_00226628);
#ifdef SKIP_ASM
// Value add (for-loop step): same-type int/float/symbol add, float+int
// gives float, int+float gives int; anything else gives nil.
extern "C" cLunoValue* func_00226628(cLunoValue* self, const cLunoValue& a, const cLunoValue& b)
{
    if (b.type == a.type) {
        if (a.type == 2) {
            float f = *(float*)&a.word0 + *(float*)&b.word0;
            self->type = a.type;
            *(float*)func_00226618(self) = f;
        } else if (a.type == 1) {
            int i = a.word0 + b.word0;
            self->type = a.type;
            *(int*)func_00226610(self) = i;
        } else if (a.type == 3) {
            int i = a.word0 + b.word0;
            self->type = a.type;
            *(int*)func_00226620(self) = i;
        } else {
            *self = D_004C9098;
        }
    } else if (a.type == 2 && b.type == 1) {
        float f = *(float*)&a.word0 + (float)b.word0;
        self->type = a.type;
        *(float*)func_00226618(self) = f;
    } else if (a.type == 1 && b.type == 2) {
        int i = a.word0 + (int)*(float*)&b.word0;
        self->type = a.type;
        *(int*)func_00226610(self) = i;
    } else {
        *self = D_004C9098;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("luno/lunovm", func_00226768);
#ifdef SKIP_ASM
struct sVEntry00226768 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
extern char D_00479890[];

extern "C" void func_00226768(void* self, int flags)
{
    *(void**)((char*)self + 0x1C) = D_00479890;
    void* obj = *(void**)((char*)self + 0x18);
    if (obj != 0) {
        sVEntry00226768* vt = *(sVEntry00226768**)((char*)obj + 0x1C);
        vt[1].fn((char*)obj + vt[1].delta, 3);
    }
    func_00225B90((cLunoValue*)((char*)self + 0xC), 2);
    func_00225B90((cLunoValue*)self, 2);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_00225DE8(int, int);

//100%
INCLUDE_ASM("luno/lunovm", func_002267F0__FPv);
#ifdef SKIP_ASM
void* func_002267F0(void* self)
{
    return func_00225DE8(1, 0xffff);
}
#endif

extern "C" void* func_00225DE8(int, int);

//100%
INCLUDE_ASM("luno/lunovm", func_00226810__FPv);
#ifdef SKIP_ASM
void* func_00226810(void* self)
{
    return func_00225DE8(0, 0xffff);
}
#endif

