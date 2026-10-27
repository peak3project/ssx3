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

//100%
INCLUDE_ASM("luno/lunovm", func_00225DE8);
#ifdef SKIP_ASM
extern float D_004C8D18[4];
extern float D_004C8D28[4];
extern float D_004C8D38[4];
extern float D_004C8D48[4];
extern float D_004C8D58[4];
extern float D_004C8D68[4];
extern float D_004C8D78[4];
extern float D_004C8D88[4];
extern float D_004C8D98[4];
extern float D_004C8DA8[4];
extern float D_004C8DB8[4];
extern float D_004C8DC8[4];
extern float D_004C8DD8[4];
extern float D_004C8DE8[4];
extern float D_004C8DF8[4];
extern float D_004C8E08[4];
extern float D_004C8E18[4];
extern float D_004C8E28[4];
extern float D_004C8E38[4];
extern float D_004C8E48[4];
extern float D_004C8E58[4];
extern float D_004C8E68[4];
extern float D_004C8E78[4];
extern float D_004C8E88[4];
extern float D_004C8E98[4];
extern float D_004C8EA8[4];
extern float D_004C8EB8[4];
extern float D_004C8EC8[4];
extern float D_004C8ED8[4];
extern float D_004C8EE8[4];
extern float D_004C8EF8[4];
extern float D_004C8F08[4];
extern float D_004C8F18[4];
extern float D_004C8F28[4];
extern float D_004C8F38[4];
extern float D_004C8F48[4];
extern float D_004C8F58[4];
extern float D_004C8F68[4];
extern float D_004C8F78[4];
extern float D_004C8F88[4];
extern float D_004C8F98[4];
extern float D_004C8FA8[4];
extern float D_004C8FB8[4];
extern float D_004C8FC8[4];
extern float D_004C8FD8[4];
extern float D_004C8FE8[4];
extern float D_004C8FF8[4];
extern float D_004C9008[4];
extern float D_004C9018[4];
extern float D_004C9028[4];
extern float D_004C9038[4];
extern float D_004C9048[4];
extern float D_004C9058[4];
extern float D_004C9068[4];
extern float D_004C9078[4];
extern float D_004C9088[4];

void sti_00225DE8(int init, int prio) __asm__("func_00225DE8");
void sti_00225DE8(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init) {
            D_004C8D18[0] = 1.0f;
            D_004C8D18[1] = 1.0f;
            D_004C8D18[2] = 1.0f;
            D_004C8D18[3] = 0.5f;
            D_004C8D28[0] = 0.4998680055141449f;
            D_004C8D28[1] = 1.0f;
            D_004C8D28[2] = 1.0f;
            D_004C8D28[3] = 0.0f;
            D_004C8D38[0] = 0.12951700389385223f;
            D_004C8D38[1] = 1.0f;
            D_004C8D38[2] = 1.0f;
            D_004C8D38[3] = 0.0f;
            D_004C8D48[0] = 0.22426900267601013f;
            D_004C8D48[1] = 0.9402310252189636f;
            D_004C8D48[2] = 0.5425059795379639f;
            D_004C8D48[3] = 0.0004030000127386302f;
            D_004C8D58[0] = 0.4652079939842224f;
            D_004C8D58[1] = 0.32170501351356506f;
            D_004C8D58[2] = 0.9943439960479736f;
            D_004C8D58[3] = 0.0f;
            D_004C8D68[0] = 0.17792600393295288f;
            D_004C8D68[1] = 1.0f;
            D_004C8D68[2] = 1.0f;
            D_004C8D68[3] = 0.0f;
            D_004C8D78[0] = 0.4411740005016327f;
            D_004C8D78[1] = 0.41388601064682007f;
            D_004C8D78[2] = 0.3211260139942169f;
            D_004C8D78[3] = 0.4398239850997925f;
            D_004C8D88[0] = 0.500997006893158f;
            D_004C8D88[1] = 0.24849599599838257f;
            D_004C8D88[2] = 1.0f;
            D_004C8D88[3] = 1.0f;
            D_004C8D98[0] = 0.27687299251556396f;
            D_004C8D98[1] = 0.6395620107650757f;
            D_004C8D98[2] = 0.13423900306224823f;
            D_004C8D98[3] = 0.0f;
            D_004C8DA8[0] = 0.8936439752578735f;
            D_004C8DA8[1] = 0.5263469815254211f;
            D_004C8DA8[2] = 0.5051450133323669f;
            D_004C8DA8[3] = 0.8687300086021423f;
            D_004C8DB8[0] = 1.0f;
            D_004C8DB8[1] = 1.0f;
            D_004C8DB8[2] = 1.0f;
            D_004C8DB8[3] = 1.0f;
            D_004C8DC8[0] = 1.0f;
            D_004C8DC8[1] = 0.0f;
            D_004C8DC8[2] = 0.0f;
            D_004C8DC8[3] = 0.0f;
            D_004C8DD8[0] = 1.0f;
            D_004C8DD8[1] = 0.550000011920929f;
            D_004C8DD8[2] = 0.5350000262260437f;
            D_004C8DD8[3] = 0.550000011920929f;
            D_004C8DE8[0] = 1.0f;
            D_004C8DE8[1] = 1.0f;
            D_004C8DE8[2] = 1.0f;
            D_004C8DE8[3] = 1.0f;
            D_004C8DF8[0] = 1.0f;
            D_004C8DF8[1] = 1.0f;
            D_004C8DF8[2] = 1.0f;
            D_004C8DF8[3] = 1.0f;
            D_004C8E08[0] = 1.0f;
            D_004C8E08[1] = 0.0f;
            D_004C8E08[2] = 0.0f;
            D_004C8E08[3] = 0.0f;
            D_004C8E18[0] = 1.0f;
            D_004C8E18[1] = 0.0f;
            D_004C8E18[2] = 0.0f;
            D_004C8E18[3] = 0.0f;
            D_004C8E28[0] = 1.0f;
            D_004C8E28[1] = 1.0f;
            D_004C8E28[2] = 1.0f;
            D_004C8E28[3] = 1.0f;
            D_004C8E38[0] = 1.0f;
            D_004C8E38[1] = 0.5f;
            D_004C8E38[2] = 1.0f;
            D_004C8E38[3] = 0.5f;
            D_004C8E48[0] = 1.0f;
            D_004C8E48[1] = 0.5f;
            D_004C8E48[2] = 1.0f;
            D_004C8E48[3] = 0.5f;
            D_004C8E58[0] = 1.0f;
            D_004C8E58[1] = 0.5f;
            D_004C8E58[2] = 1.0f;
            D_004C8E58[3] = 0.5f;
            D_004C8E68[0] = 1.0f;
            D_004C8E68[1] = 0.7828119993209839f;
            D_004C8E68[2] = 0.06171900033950806f;
            D_004C8E68[3] = 0.03984399884939194f;
            D_004C8E78[0] = 1.0f;
            D_004C8E78[1] = 1.0f;
            D_004C8E78[2] = 0.7988259792327881f;
            D_004C8E78[3] = 0.0f;
            D_004C8E88[0] = 0.9886710047721863f;
            D_004C8E88[1] = 0.9230499863624573f;
            D_004C8E88[2] = 0.34311699867248535f;
            D_004C8E88[3] = 0.0f;
            D_004C8E98[0] = 1.0f;
            D_004C8E98[1] = 1.0f;
            D_004C8E98[2] = 1.0f;
            D_004C8E98[3] = 1.0f;
            D_004C8EA8[0] = 1.0f;
            D_004C8EA8[1] = 1.0f;
            D_004C8EA8[2] = 0.7976430058479309f;
            D_004C8EA8[3] = 0.0f;
            D_004C8EB8[0] = 1.0f;
            D_004C8EB8[1] = 0.9222670197486877f;
            D_004C8EB8[2] = 0.34179699420928955f;
            D_004C8EB8[3] = 0.0f;
            D_004C8EC8[0] = 1.0f;
            D_004C8EC8[1] = 0.7847639918327332f;
            D_004C8EC8[2] = 0.06054700165987015f;
            D_004C8EC8[3] = 0.04062499850988388f;
            D_004C8ED8[0] = 1.0f;
            D_004C8ED8[1] = 0.800000011920929f;
            D_004C8ED8[2] = 0.44999998807907104f;
            D_004C8ED8[3] = 1.0f;
            D_004C8EE8[0] = 1.0f;
            D_004C8EE8[1] = 0.3281260132789612f;
            D_004C8EE8[2] = 1.0f;
            D_004C8EE8[3] = 0.3539060056209564f;
            D_004C8EF8[0] = 1.0f;
            D_004C8EF8[1] = 1.0f;
            D_004C8EF8[2] = 1.0f;
            D_004C8EF8[3] = 1.0f;
            D_004C8F08[0] = 1.0f;
            D_004C8F08[1] = 1.0f;
            D_004C8F08[2] = 1.0f;
            D_004C8F08[3] = 1.0f;
            D_004C8F18[0] = 1.0f;
            D_004C8F18[1] = 0.8613290190696716f;
            D_004C8F18[2] = 0.38124799728393555f;
            D_004C8F18[3] = 0.0f;
            D_004C8F28[0] = 1.0f;
            D_004C8F28[1] = 1.0f;
            D_004C8F28[2] = 1.0f;
            D_004C8F28[3] = 1.0f;
            D_004C8F38[0] = 1.0f;
            D_004C8F38[1] = 0.3244380056858063f;
            D_004C8F38[2] = 1.0f;
            D_004C8F38[3] = 0.0f;
            D_004C8F48[0] = 1.0f;
            D_004C8F48[1] = 1.0f;
            D_004C8F48[2] = 1.0f;
            D_004C8F48[3] = 1.0f;
            D_004C8F58[0] = 1.0f;
            D_004C8F58[1] = 1.0f;
            D_004C8F58[2] = 0.0f;
            D_004C8F58[3] = 0.0f;
            D_004C8F68[0] = 0.7007060050964355f;
            D_004C8F68[1] = 0.0f;
            D_004C8F68[2] = 0.0f;
            D_004C8F68[3] = 0.0f;
            D_004C8F78[0] = 1.0f;
            D_004C8F78[1] = 0.7828530073165894f;
            D_004C8F78[2] = 0.06140600144863129f;
            D_004C8F78[3] = 0.04146299883723259f;
            D_004C8F88[0] = 1.0f;
            D_004C8F88[1] = 0.32487601041793823f;
            D_004C8F88[2] = 1.0f;
            D_004C8F88[3] = 0.35280099511146545f;
            D_004C8F98[0] = 1.0f;
            D_004C8F98[1] = 1.0f;
            D_004C8F98[2] = 0.7977359890937805f;
            D_004C8F98[3] = 0.0f;
            D_004C8FA8[0] = 1.0f;
            D_004C8FA8[1] = 0.4937489926815033f;
            D_004C8FA8[2] = 1.0f;
            D_004C8FA8[3] = 0.49179700016975403f;
            D_004C8FB8[0] = 1.0f;
            D_004C8FB8[1] = 1.0f;
            D_004C8FB8[2] = 1.0f;
            D_004C8FB8[3] = 1.0f;
            D_004C8FC8[0] = 1.0f;
            D_004C8FC8[1] = 0.800000011920929f;
            D_004C8FC8[2] = 1.0f;
            D_004C8FC8[3] = 0.800000011920929f;
            D_004C8FD8[0] = 1.0f;
            D_004C8FD8[1] = 1.0f;
            D_004C8FD8[2] = 0.0f;
            D_004C8FD8[3] = 0.0f;
            D_004C8FE8[0] = 1.0f;
            D_004C8FE8[1] = 1.0f;
            D_004C8FE8[2] = 0.0f;
            D_004C8FE8[3] = 0.0f;
            D_004C8FF8[0] = 1.0f;
            D_004C8FF8[1] = 1.0f;
            D_004C8FF8[2] = 0.0f;
            D_004C8FF8[3] = 0.0f;
            D_004C9008[0] = 1.0f;
            D_004C9008[1] = 0.3273420035839081f;
            D_004C9008[2] = 1.0f;
            D_004C9008[3] = 0.35390499234199524f;
            D_004C9018[0] = 1.0f;
            D_004C9018[1] = 1.0f;
            D_004C9018[2] = 0.061000000685453415f;
            D_004C9018[3] = 0.039000000804662704f;
            D_004C9028[0] = 1.0f;
            D_004C9028[1] = 1.0f;
            D_004C9028[2] = 0.7999979853630066f;
            D_004C9028[3] = 0.0f;
            D_004C9038[0] = 1.0f;
            D_004C9038[1] = 0.9589840173721313f;
            D_004C9038[2] = 0.6143789887428284f;
            D_004C9038[3] = 0.0f;
            D_004C9048[0] = 1.0f;
            D_004C9048[1] = 0.9285150170326233f;
            D_004C9048[2] = 0.3399839997291565f;
            D_004C9048[3] = 0.0f;
            D_004C9058[0] = 1.0f;
            D_004C9058[1] = 0.8738250136375427f;
            D_004C9058[2] = 0.24931700527668f;
            D_004C9058[3] = 0.017578000202775f;
            D_004C9068[0] = 1.0f;
            D_004C9068[1] = 0.7843739986419678f;
            D_004C9068[2] = 0.06132800132036209f;
            D_004C9068[3] = 0.03945299983024597f;
            D_004C9078[0] = 1.0f;
            D_004C9078[1] = 0.0f;
            D_004C9078[2] = 1.0f;
            D_004C9078[3] = 0.0f;
            D_004C9088[0] = 1.0f;
            D_004C9088[1] = 1.0f;
            D_004C9088[2] = 0.0f;
            D_004C9088[3] = 0.0f;
            D_004C9098.type = 0;
            D_004C9098.word0 = 0;
        } else {
            func_00225B90(&D_004C9098, 2);
        }
    }
}
#endif

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

