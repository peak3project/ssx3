#include "common.h"

//100%
INCLUDE_ASM("scripter/datamanager", cDataManager_cDataManager);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void func_00275CD0(void* self, void* node);
extern char D_004825A0[];
extern const char D_00481AB8[];

struct sDataNode5828 {
    char pad[0x18];
};

struct cDataManager5828 {
    int count;              // 0x0
    sDataNode5828* nodes;   // 0x4
    int field_0x8;          // 0x8
    void* vtable;           // 0xC
};

extern "C" cDataManager5828* cDataManager_cDataManager(cDataManager5828* self, int flags, int count)
{
    self->vtable = D_004825A0;
    self->count = count;
    self->nodes = (sDataNode5828*)operator_new_tag(count * sizeof(sDataNode5828), D_00481AB8, flags, 0);
    self->field_0x8 = 0;
    for (int i = 0; i < count; i++) {
        func_00275CD0(self, &self->nodes[i]);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_002758C0);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern char D_004825A0[];

extern "C" void func_002758C0(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_004825A0;
    void* p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        cMemMan_free(p);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275920);
#ifdef SKIP_ASM
void* func_00275CF8(void* self);
extern "C" int BIG_sizeofheader(void* data);
struct sDmNode5B98;
extern "C" sDmNode5B98* func_00275B98(void* self, char* big, sDmNode5B98* prev);
extern int D_00450DD4[];

struct sDmVEntry5920 {
    short delta;
    short index;
    void (*fn)(void*, int, void*, int, void*, void*);
};

struct sDmNode5920 {
    int field_0x0;
    int field_0x4;          // 0x4
    void* data;             // 0x8
    int size;               // 0xC
    int refs;               // 0x10
};

extern "C" sDmNode5920* func_00275920(void* self, int a1, void* data, int size)
{
    sDmNode5920* n = (sDmNode5920*)func_00275CF8(self);
    int saved = D_00450DD4[0];
    n->data = data;
    n->refs = 1;
    n->size = size;
    D_00450DD4[0] = 0;
    int big = BIG_sizeofheader(data);
    D_00450DD4[0] = saved;
    if (big != 0) {
        sDmVEntry5920* vt = *(sDmVEntry5920**)((char*)self + 0xC);
        vt[4].fn((char*)self + vt[4].delta, a1, data, size, n, &n->field_0x4);
        func_00275B98(self, (char*)data, (sDmNode5B98*)n);
    } else {
        sDmVEntry5920* vt = *(sDmVEntry5920**)((char*)self + 0xC);
        vt[2].fn((char*)self + vt[2].delta, a1, data, size, n, &n->field_0x4);
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275A20);
#ifdef SKIP_ASM
void func_00275CD0(void* self, void* node);

struct sDmNode5A20 {
    int a;              // 0x0
    int b;              // 0x4
    int key;            // 0x8
    int c;              // 0xC
    int pad_10;         // 0x10
    sDmNode5A20* next;  // 0x14
};

class cDataManager5A20 {
public:
    int count;          // 0x0
    void* nodes;        // 0x4
    void* freeList;     // 0x8
    // vptr at 0xC
    virtual void v01();
    virtual void v02();
    virtual void v03(int key, int c, int a, int b);
    virtual void v04();
    virtual void v05(int key, int c, int a, int b);
};

// PORT: the unit declares func_00275A20 as returning void; it really returns the entry's key.
int func_00275A20_impl(cDataManager5A20* self, sDmNode5A20* entry) __asm__("func_00275A20");

int func_00275A20_impl(cDataManager5A20* self, sDmNode5A20* entry)
{
    sDmNode5A20* first = entry->next;
    if (first != 0) {
        sDmNode5A20* n = first;
        do {
            sDmNode5A20* next = n->next;
            self->v03(n->key, n->c, n->a, n->b);
            func_00275CD0(self, n);
            n = next;
        } while (n != 0);
        self->v05(entry->key, entry->c, entry->a, entry->b);
    } else {
        self->v03(entry->key, entry->c, entry->a, entry->b);
    }
    int key = entry->key;
    func_00275CD0(self, entry);
    return key;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/datamanager", func_00275B08);
#ifdef SKIP_ASM
extern "C" void func_00275A20(void* self, void* entry);

struct sDmEntry275B08 {
    char pad_0x00[0x10];
    int used;
    int unk_0x14;
};

struct sDmTable275B08 {
    int count;
    sDmEntry275B08* entries;
};

extern "C" void func_00275B08(sDmTable275B08* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (self->entries[i].used != 0) {
            func_00275A20(self, &self->entries[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275B78);
#ifdef SKIP_ASM
extern "C" int func_00275B78(void* self, int* p)
{
    return p[2];
}
#endif

INCLUDE_ASM("scripter/datamanager", func_00275B80);
//100%
INCLUDE_ASM("scripter/datamanager", func_00275B98);
#ifdef SKIP_ASM
void* func_00275CF8(void* self);
extern "C" int BIG_sizeofheader(void* data);
extern "C" char* BIG_locateentryz(void* big, int a1, int index, int* offset, int* size);
extern int D_00450DD4[];

struct sDmVEntry5B98 {
    short delta;
    short index;
    void (*fn)(void*, char*, char*, int, void*, void*);
};

struct sDmNode5B98 {
    int field_0x0;
    int field_0x4;          // 0x4
    char* data;             // 0x8
    int size;               // 0xC
    int refs;               // 0x10
    sDmNode5B98* next;      // 0x14
};

extern "C" sDmNode5B98* func_00275B98(void* self, char* big, sDmNode5B98* prev)
{
    int ent[2];
    ent[0] = 0;
    ent[1] = 0;
    int i = 1;
    char* name = BIG_locateentryz(big, 0, 0, &ent[0], &ent[1]);
    while (name != 0) {
        char* sub = big + ent[0];
        int saved = D_00450DD4[0];
        D_00450DD4[0] = 0;
        int r = BIG_sizeofheader(sub);
        D_00450DD4[0] = saved;
        if (r != 0) {
            prev = func_00275B98(self, sub, prev);
        } else {
            sDmNode5B98* n = (sDmNode5B98*)func_00275CF8(self);
            n->data = sub;
            n->size = ent[1];
            prev->next = n;
            prev = n;
            sDmVEntry5B98* vt = *(sDmVEntry5B98**)((char*)self + 0xC);
            vt[2].fn((char*)self + vt[2].delta, name, sub, ent[1], prev, &prev->field_0x4);
        }
        name = BIG_locateentryz(big, 0, i++, &ent[0], 0);
    }
    return prev;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275CD0__FPvT0);
#ifdef SKIP_ASM
void func_00275CD0(void* self, void* node)
{
    *(int*)((char*)node + 0x8) = 0;
    *(int*)((char*)node + 0xc) = 0;
    *(int*)((char*)node + 0x10) = 0;
    *(int*)((char*)node + 0x0) = 0;
    *(int*)((char*)node + 0x4) = 0;
    *(void**)((char*)node + 0x14) = *(void**)((char*)self + 0x8);
    *(void**)((char*)self + 0x8) = node;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275CF8__FPv);
#ifdef SKIP_ASM
void* func_00275CF8(void* self)
{
    void* head = *(void**)((char*)self + 0x8);
    *(void**)((char*)self + 0x8) = *(void**)((char*)head + 0x14);
    *(void**)((char*)head + 0x14) = 0;
    return head;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275D10);
#ifdef SKIP_ASM
extern "C" void func_00283C30(void* self);
void func_00283C20(void* self);

extern "C" void* func_00275D10(void* self)
{
    void* list = (char*)self + 0xC;
    func_00283C30(list);
    func_00283C20(list);
    *(int*)((char*)self + 0xBC) = -1;
    *(int*)((char*)self + 0x4) = 1;
    *(int*)((char*)self + 0xA4) = 0;
    *(int*)((char*)self + 0xA8) = 0;
    *(int*)((char*)self + 0xC8) = 0;
    *(int*)((char*)self + 0xB0) = 0;
    *(int*)((char*)self + 0xAC) = 0;
    *(int*)((char*)self + 0xB8) = 0;
    *(int*)((char*)self + 0xC0) = 0;
    *(int*)((char*)self + 0xC4) = 0;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0xB4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275D90);
#ifdef SKIP_ASM
extern "C" void func_00276868(void* self, int a1);
void operator_delete(int* ptr);

extern "C" void func_00275D90(int* self, int flags)
{
    func_00276868(self, 1);
    *self = 0;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275DD8);
#ifdef SKIP_ASM
extern "C" int func_00277450(void* self, int index, int a2);
extern "C" void func_002776E0(void* self);
extern "C" void* func_00282BF0(void* self, int a1);
int func_00283C58(void* self);
extern "C" int func_00283C80(void* list, void* cmd);
extern "C" void* func_00283D70(void* list, int i);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");
struct sDmCmd5DD8 {
    int a1;         // 0x0
    int id;         // 0x4
    int a2;         // 0x8
    int field_0xC;  // 0xC
    int a4;         // 0x10
    int a5;         // 0x14
    int a6;         // 0x18
};

// Queues a plain command (no lookup) and starts it when the queue was idle.
extern "C" int func_00275DD8(char* self, int a1, int a2)
{
    if (func_00283C58(self + 0xC) != 0) {
        return 0;
    }
    sDmCmd5DD8 cmd;
    cmd.a1 = a1;
    cmd.id = -1;
    cmd.a2 = a2;
    cmd.field_0xC = -1;
    cmd.a4 = -1;
    cmd.a5 = -1;
    // 64-bit "none" value compared against the pending index below; needed for the target's branch layout
    long none = 0;
    cmd.a6 = -1;
    void* list = self + 0xC;
    func_00283C80(list, &cmd);
    if (*(int*)(self + 0xA4) == 0) {
        return 1;
    }
    if (*(int*)(self + 0xBC) >= none) {
        return 1;
    }
    *(int*)(self + 0xBC) = func_00277450(self, func_00283D28_count(list) - 1, 0);
    if (*(int*)(self + 0xA4) == 3) {
        int ok = *(int*)((char*)func_00282BF0(*(void**)self, *(int*)((char*)func_00283D70(list, 0) + 0xC)) + 0x20) == 4;
        if (ok)
            func_002776E0(self);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00275ED0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00277450(void* self, int index, int a2);
extern "C" void func_002776E0(void* self);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" int func_002797A0(void* eng, int a1, int a2, int a3, int a4);
extern "C" void* func_00282BF0(void* self, int a1);
extern "C" int func_00283BB8(void* self);
int func_00283C58(void* self);
extern "C" int func_00283C80(void* list, void* cmd);
extern "C" void* func_00283D70(void* list, int i);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");

struct sDmCmd5ED0 {
    int a1;         // 0x0
    int id;         // 0x4
    int a2;         // 0x8
    int field_0xC;  // 0xC
    int a4;         // 0x10
    int a5;         // 0x14
    int a6;         // 0x18
};

extern "C" int func_00275ED0(char* self, int a1, int a2, int lookup, int a4, int a5, int a6)
{
    if (func_00283C58(self + 0xC) != 0) {
        return 0;
    }
    sDmCmd5ED0 cmd;
    cmd.a1 = a1;
    cmd.id = -1;
    cmd.a2 = a2;
    cmd.field_0xC = -1;
    cmd.a4 = a4;
    cmd.a5 = a5;
    cmd.a6 = a6;
    if (lookup != 0) {
        int id = func_002797A0(*(void**)self, a1, a4, a5, a6);
        if (id < 0) {
            return 0;
        }
        cmd.id = id;
    }
    void* list = self + 0xC;
    func_00283C80(list, &cmd);
    if (*(int*)(self + 0xA4) == 0) {
        return 1;
    }
    if (*(int*)(self + 0xBC) >= 0) {
        return 1;
    }
    *(int*)(self + 0xBC) = func_00277450(self, func_00283D28_count(list) - 1, 0);
    if (*(int*)(self + 0xA4) == 3) {
        int ok;
        if (func_00277DD8(self, func_00283D70(list, 0)) == 0) {
            ok = *(int*)((char*)func_00282BF0(*(void**)self, *(int*)((char*)func_00283D70(list, 0) + 0xC)) + 0x20) == 4;
        } else {
            ok = func_00283BB8((char*)*(void**)self + 0x500);
        }
        if (ok) {
            func_002776E0(self);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276048);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00277450(void* self, int index, int a2);
extern "C" void func_002776E0(void* self);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" void* func_00282BF0(void* self, int a1);
extern "C" int func_00283BB8(void* self);
int func_00283C58(void* self);
extern "C" int func_00283C80(void* list, void* cmd);
extern "C" void* func_00283D70(void* list, int i);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");

struct sDmCmd6048 {
    int type;       // 0x0
    int a1;         // 0x4
    int a2;         // 0x8
    int id;         // 0xC
    int a3;         // 0x10
    int a4;         // 0x14
    int a5;         // 0x18
};

extern "C" int func_00276048(char* self, int a1, int a2, int a3, int a4, int a5)
{
    if (func_00283C58(self + 0xC) == 0) {
        void* list = self + 0xC;
        sDmCmd6048 cmd;
        cmd.type = 0x1C;
        cmd.id = -1;
        cmd.a2 = a2;
        cmd.a1 = a1;
        cmd.a3 = a3;
        cmd.a4 = a4;
        cmd.a5 = a5;
        func_00283C80(list, &cmd);
        if (*(int*)(self + 0xA4) != 0 && *(int*)(self + 0xBC) < 0) {
        *(int*)(self + 0xBC) = func_00277450(self, func_00283D28_count(list) - 1, 0);
        if (*(int*)(self + 0xA4) == 3) {
            int ok;
            if (func_00277DD8(self, func_00283D70(list, 0)) == 0) {
                ok = *(int*)((char*)func_00282BF0(*(void**)self, *(int*)((char*)func_00283D70(list, 0) + 0xC)) + 0x20) == 4;
            } else {
                ok = func_00283BB8((char*)*(void**)self + 0x500);
            }
            if (ok) {
                func_002776E0(self);
            }
        }
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276198);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00283C80(void* list, void* cmd);
extern "C" int func_00283DC0(void* self, void* out);
extern "C" void func_00276868(void* self, int a1);
extern "C" int func_00277450(void* self, int index, int a2);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");

extern "C" int func_00276198(void* self, void* other)
{
    int cmd[8];
    int n = func_00283D28_count((char*)self + 0xC);
    if (*(int*)((char*)other + 0xA4) == 3) {
        return 0;
    }
    if (func_00283D28_count((char*)other + 0xC) != 0) {
        while (func_00283DC0((char*)other + 0xC, cmd) != 0) {
            func_00283C80((char*)self + 0xC, cmd);
        }
        func_00276868(other, 1);
        if (*(int*)((char*)self + 0xA4) != 0 && *(int*)((char*)self + 0xBC) < 0) {
            *(int*)((char*)self + 0xBC) = func_00277450(self, n, 0);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276270);
#ifdef SKIP_ASM
extern "C" void func_00276868(void* self, int a1);
extern "C" int func_00277450(void* self, int index, int a2);
extern "C" void func_00277598(void* self, int index);
extern "C" void func_00277778(void* self);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" int func_00282798(void* self, int a1);
extern "C" void* func_00283D28(void*);
extern "C" void* func_00283D70(void* list, int i);

extern "C" int func_00276270(char* self, int a1)
{
    if (*(int*)(self + 0xA4) == 1) {
        func_00277778(self);
    }
    if (*(int*)(self + 0xA4) != 0) {
        return *(int*)(self + 0xA4);
    }
    *(int*)(self + 0xB4) = a1;
    void* list = self + 0xC;
    if (func_00283D28(list) == 0) {
        return 0;
    }
    int idx = func_00277450(self, 0, 0);
    if (idx < 0) {
        func_00276868(self, 1);
        return *(int*)(self + 0xA4);
    }
    func_00277598(self, idx);
    char* e = (char*)func_00283D70(list, 0);
    if (func_00277DD8(self, e) == 0) {
        if (func_00282798(*(void**)self, *(int*)(e + 0xC)) == 1) {
            *(int*)(self + 0xA4) = 1;
        } else {
            *(int*)(self + 0xA4) = 2;
        }
    } else {
        if (*(int*)(e + 0xC) < 0) {
            *(int*)(self + 0xA4) = 1;
        } else {
            *(int*)(self + 0xA4) = 2;
        }
    }
    *(int*)(self + 0xBC) = func_00277450(self, idx + 1, 0);
    return *(int*)(self + 0xA4);
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276388);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern void* D_004A28A4;
extern char D_004A34A0[];
int GetHashValue32(char* s);
void* func_00230698(void* self, int a1);
char* func_0027C070(void* obj);
extern "C" void func_00277778(void* self);
extern "C" int func_00277DD8(void* self, void* a1);
// The unit declares func_00279720 as void; it returns func_002822A0's result.
int func_00279720_i(void* self, int val, int key, int b, int c) __asm__("func_00279720");
extern "C" int func_0027A4A0(void* self, int a1, int a2);
extern "C" void func_002826D8(void* self, int a1);
extern "C" void* func_00282BF0(void* self, int a1);
extern "C" int func_002839A8(void* self);
extern "C" void func_00283AA0(void* self);
extern "C" void* func_00283D70(void* list, int i);
extern "C" void func_002E4370(void* snd, int a1, int h, int h2, int a4, int a5, float t0, float t1, float t2);
// PORT: real parameter order of func_002E4370 has the floats before the two trailing ints (cf. boardwakefx).
void func_002E4370_f(void* snd, int a1, int h, int h2, float t0, float t1, float t2, int a4, int a5) __asm__("func_002E4370");
extern "C" void func_002E4540(void* snd, int a1, int h, int a3, float t);
extern "C" void func_002E4578(void* p);
extern "C" void func_002EA6B8(void* gm, float t);
extern "C" void func_002EA860(void* gm);
extern "C" void* func_0039F9D8(void* table, int hash);

struct sDmVEntry_6388 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

struct sDmVEntry2_6388 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sDm_6388 {
    void* eng;              // 0x0
    int active;             // 0x4
    int val;                // 0x8
    char list[0xA4 - 0xC];  // 0xC
    int state;              // 0xA4
    int fA8;
    int fAC;                // 0xAC
    int fB0;                // 0xB0
    int fB4;
    int fB8;                // 0xB8
};

struct sDmFade_6388 {
    char pad_0x0[0x8];
    signed char cat;        // 0x8
    signed char key;        // 0x9
    short tIn;              // 0xA
    short tHold;            // 0xC
    short tOut;             // 0xE
};

struct sDmItem_6388 {
    int f0;
    int f4;
    int flags;              // 0x8
    int id;                 // 0xC
};

// The unit declares func_00276388 as void; it returns the state at 0xA4.
int func_00276388_impl(char* self, int fade, int notify) __asm__("func_00276388");

int func_00276388_impl(char* self, int fade, int notify)
{
    sDm_6388* dm = (sDm_6388*)self;
    if (*(int*)(self + 0xA4) == 1) {
        func_00277778(self);
    }
    if (*(int*)(self + 0xA4) != 2) {
        return *(int*)(self + 0xA4);
    }
    sDmItem_6388* item = (sDmItem_6388*)func_00283D70(self + 0xC, 0);
    dm->state = 3;
    char* table = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x48) + 0x18;
    char* o = (char*)func_0039F9D8(table, GetHashValue32(D_004A34A0));
    if (o != 0) {
        sDmVEntry_6388* e = &(*(sDmVEntry_6388**)(o + 0x8))[24];
        e->fn(o + e->delta, 0, 0);
    }
    if (func_00277DD8(self, item) == 0) {
        func_00279720_i(*(void**)self, *(int*)(self + 0x8), item->id, 0, (item->flags >> 3) & 1);
        if (*(int*)(self + 0x4) != 0) {
            void* snd = func_00230698(*(void**)(D_004A28A8 + 0x84), 0);
            if (*(int*)((char*)snd + 0x44) != 0) {
                func_002E4578(snd);
            }
            int tIn = 0;
            int tHold = 0;
            float t = 0.0f;
            sDmFade_6388* f = (sDmFade_6388*)func_0027C070(func_00282BF0(*(void**)self, item->id));
            if (fade) {
                tIn = f->tIn;
                tHold = f->tHold;
            }
            *(int*)(self + 0xB8) = 0;
            if (tIn + tHold + f->tOut > 0) {
                if (f->cat != 7) {
                    int h = func_0027A4A0(*(void**)self, f->cat, f->key);
                    if (h != 0) {
                        int h2 = func_0027A4A0(*(void**)self, f->cat, f->key);
                        float tt = (float)tIn * 0.01666666753590107f;
                        func_002E4370_f(snd, 2, h, h2, tt, (float)tHold * 0.01666666753590107f, (float)f->tOut * 0.01666666753590107f, 0, 0);
                        t = tt;
                        *(int*)(self + 0xB8) = tIn + tHold;
                    }
                } else if (tIn) {
                    int h = func_0027A4A0(D_004A28A4, 7, f->key);
                    float tt = (float)tIn * 0.01666666753590107f;
                    func_002E4540(snd, 2, h, 0, tt);
                    t = tt;
                }
                if (*(int*)(self + 0xB8) > 0) {
                    notify = 0;
                    func_002826D8(*(void**)self, item->id);
                    *(int*)(self + 0xAC) = 1;
                    *(int*)(self + 0xB0) = 1;
                }
            }
            if (t <= 0.0f) {
                t = 0.5f;
            }
            func_002EA6B8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x64), t);
        }
        if (notify) {
            char* eng = *(char**)self;
            sDmVEntry2_6388* e = &(*(sDmVEntry2_6388**)(eng + 0x2A8))[6];
            e->fn(eng + e->delta, item->id);
        }
    } else {
        if (*(int*)(self + 0x4) != 0) {
            func_002EA860(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x64));
        }
        func_002839A8(*(char**)self + 0x500);
        if (notify) {
            func_00283AA0(*(char**)self + 0x500);
        }
    }
    return *(int*)(self + 0xA4);
}
#endif

extern "C" void* func_00277C08(void*, int, int);

//100%
INCLUDE_ASM("scripter/datamanager", func_002766B0__FPvi);
#ifdef SKIP_ASM
void* func_002766B0(void* self, int a1)
{
    return func_00277C08(self, a1, 0);
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_002766D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00276270(char* self, int a1);
extern "C" void func_00276868(void* self, int a1);
extern "C" int func_00277450(void* self, int index, int a2);
extern "C" void func_00277598(void* self, int index);
extern "C" void func_00277800(void* self);
// The unit declares func_00277980 as void; it returns whether it handled the update.
extern "C" int func_00277980_r(void* self) __asm__("func_00277980");
extern "C" void* func_00277C08(void*, int, int);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" int func_00282540(void* self, int id);
extern "C" void func_00283818(void* p);
extern "C" void* func_00283D70(void* list, int i);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");

struct sSeqItem_66D0 {
    char pad_0x0[0xC];
    int handle;         // 0xC
};

struct sSeq_66D0 {
    char* owner;        // 0x0
    char pad_0x4[0x8];
    char list[0x98];    // 0xC
    int state;          // 0xA4
    int fA8;            // 0xA8
    char pad_0xAC[0x8];
    int fB4;            // 0xB4
    char pad_0xB8[0x4];
    int cur;            // 0xBC
    int pos;            // 0xC0
};

extern "C" int func_002766D0(sSeq_66D0* self, int delta, int force)
{
    int pos = delta + self->pos;
    if (pos == self->pos) {
        return self->state;
    }
    if (pos < self->cur) {
        pos = self->cur;
    }
    int n = func_00283D28_count(self->list);
    if (self->state != 3) {
        self->pos = 0;
        if (pos < n) {
            func_00277598(self, pos);
            int st = self->state;
            self->cur = -1;
            self->state = 0;
            if (st != 0) {
                func_00276270((char*)self, self->fB4);
            }
            return self->state;
        }
        goto reset;
    }
    self->pos = pos;
    if (self->cur > 0 && self->cur < pos) {
        sSeqItem_66D0* it = (sSeqItem_66D0*)func_00283D70(self->list, self->cur);
        if (func_00277DD8(self, it) == 0) {
            func_00282540(self->owner, it->handle);
        } else if (it->handle != 0) {
            func_00283818(self->owner + 0x500);
        }
        it->handle = -1;
        self->cur = -1;
        if (self->fA8) {
            func_00277C08(self, 0, 1);
        }
        self->cur = func_00277450(self, pos, 0);
    }
    if (self->fA8 == 0) {
        if (force == 0 || func_00277980_r(self) == 0) {
            if (self->cur < 0) {
                goto reset;
            }
            func_00277800(self);
        }
    }
    return self->state;
reset:
    func_00276868(self, 1);
    return self->state;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276868);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern char D_004A34A0[];
int GetHashValue32(char* s);
void* func_00230698(void* self, int a1);
extern "C" void func_002E4578(void* p);
extern "C" void func_002EA820(void* p);
extern "C" void* func_0039F9D8(void* table, int hash);
extern "C" void func_00277598(void* self, int index);
extern "C" void* func_00277C08(void*, int, int);

struct sDmVEntry6868 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" void func_00276868(void* p, int a1)
{
    char* self = (char*)p;
    if (*(int*)(self + 0xA8) != 0) {
        func_00277C08(self, 0, 1);
    }
    if (*(int*)(self + 0xC4) != 0) {
        *(int*)(self + 0xC4) = 1;
        func_00277C08(self, 0, 0);
    }
    if (*(int*)(self + 0x4) != 0 && *(int*)(self + 0xA4) == 3) {
        void* gm = *(void**)(*(char**)(D_004A28A8 + 0x84) + 0x64);
        if (a1 != 0) {
            func_002EA820(gm);
            if (*(int*)(self + 0xB0) != 0) {
                func_002E4578(func_00230698(*(void**)(D_004A28A8 + 0x84), 0));
            }
        }
        char* table = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x48) + 0x18;
        char* o = (char*)func_0039F9D8(table, GetHashValue32(D_004A34A0));
        if (o != 0) {
            sDmVEntry6868* e = &(*(sDmVEntry6868**)(o + 0x8))[24];
            e->fn(o + e->delta, 1, 0);
        }
    }
    func_00277598(self, 5);
    *(int*)(self + 0xBC) = -1;
    *(int*)(self + 0xA4) = 0;
    *(int*)(self + 0xC8) = 0;
    *(int*)(self + 0xB0) = 0;
    *(int*)(self + 0xB8) = 0;
    *(int*)(self + 0xAC) = 0;
    *(int*)(self + 0xC0) = 0;
    *(int*)(self + 0xC4) = 0;
    *(int*)(self + 0xB4) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276998);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00283D70(void* list, int i);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");

extern "C" int func_00276998(void* self, int i)
{
    void* list = (char*)self + 0xC;
    if (i < func_00283D28_count(list) && *(int*)func_00283D70(list, i) < 0x1C) {
        return *(int*)func_00283D70(list, i);
    }
    return 0x1C;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276A08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00283D70(void* list, int i);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");

extern "C" int func_00276A08(void* self, int i)
{
    void* list = (char*)self + 0xC;
    if (i < func_00283D28_count(list) && *(int*)func_00283D70(list, i) >= 0x1D) {
        return *(int*)func_00283D70(list, i);
    }
    return 0x20;
}
#endif
//100%
INCLUDE_ASM("scripter/datamanager", func_00276A78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00283D70(void* list, int i);
extern "C" int func_002827F8(void* self, int id);
int func_00283D28_count(void* list) __asm__("func_00283D28");

extern "C" int func_00276A78(void* self, int i)
{
    void* list = (char*)self + 0xC;
    if (i >= func_00283D28_count(list)) {
        return -1;
    }
    void* item = func_00283D70(list, i);
    if (func_00277DD8(self, item) != 0) {
        return -1;
    }
    int r = *(int*)((char*)item + 0x4);
    if (r < 0) {
        int id = *(int*)((char*)item + 0xC);
        r = -1;
        if (id >= 0) {
            r = func_002827F8(*(void**)self, id);
        }
    }
    return r;
}
#endif
//100%
INCLUDE_ASM("scripter/datamanager", func_00276B08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00283D70(void* list, int i);
// The unit declares func_00283D28 as returning void*, but it returns the list's count.
int func_00283D28_count(void* list) __asm__("func_00283D28");

extern "C" void* func_00276B08(void* self, int i)
{
    void* list = (char*)self + 0xC;
    if (i < func_00283D28_count(list)) {
        void* item = func_00283D70(list, i);
        if (func_00277DD8(self, item) == 0) {
            int id = *(int*)((char*)item + 0xC);
            if (id >= 0) {
                return func_00282BF0(*(void**)self, id);
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276B98);
#ifdef SKIP_ASM
extern "C" void func_00277778(void* self);

extern "C" int func_00276B98(void* self)
{
    if (*(int*)((char*)self + 0xA4) == 1) {
        func_00277778(self);
    }
    return *(int*)((char*)self + 0xA4);
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276BD8);
#ifdef SKIP_ASM
extern "C" void* func_00283D70(void* list, int i);
extern "C" int func_00282838(void* self, int a1);

extern "C" int func_00276BD8(void* self)
{
    if (*(int*)((char*)self + 0xA4) != 3) return 0;
    if (*(int*)((char*)self + 0xC4) != 0) return 3;
    if (*(int*)((char*)self + 0xC8) == 0) {
        void* list = (char*)self + 0xC;
        if (*(int*)((char*)func_00283D70(list, 0) + 0x8) & 8) {
            if (*(int*)((char*)self + 0xB0) == 0) return 2;
            if (*(int*)((char*)self + 0xB8) - 1 > 0) return 2;
        } else {
            if (func_00282838(*(void**)self, *(int*)((char*)func_00283D70(list, 0) + 0xC)) == 0) return 1;
        }
    }
    return *(int*)((char*)self + 0xBC) < 0 ? 5 : 4;
}
#endif

extern "C" void* func_00283D28(void*);

//100%
INCLUDE_ASM("scripter/datamanager", func_00276CA8__FPv);
#ifdef SKIP_ASM
void* func_00276CA8(void* self)
{
    return func_00283D28((char*)self + 0xc);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/datamanager", func_00276CC8);
#ifdef SKIP_ASM
void* func_00230698(void* self, int a1);
extern "C" void func_00276388(void* self, int a1, int a2);
extern "C" void func_00277778(void* self);
extern "C" void func_00277800(void* self);
extern "C" void func_00277838(void* self);
extern "C" void func_00277980(void* self);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" void func_00282720(void* self, int a1);
extern "C" int func_00282798(void* self, int a1);
extern "C" int func_00282838(void* self, int a1);
extern "C" int func_002839A8(void* self);
extern "C" int func_00283BB8(void* self);
extern "C" void* func_00283D70(void* list, int i);
extern "C" void func_002E4578(void* p);
extern char* D_004A28A8;

extern "C" void func_00276CC8(char* self)
{
    if (*(int*)(self + 0xA4) == 1) {
        func_00277778(self);
        return;
    }
    if (*(int*)(self + 0xA4) == 2) {
        int v = *(int*)(self + 0xB4);
        if (v != 0) {
            func_00276388(self, v == 1, 0);
            *(int*)(self + 0xB4) = 0;
        }
    }
    if (*(int*)(self + 0xA4) != 3) {
        return;
    }
    if (*(int*)(self + 0xC4) != 0) {
        return;
    }
    if (*(int*)(self + 0xB0) != 0) {
        char* item = (char*)func_00283D70(self + 0xC, 0);
        char* obj = (char*)func_00230698(*(void**)(D_004A28A8 + 0x84), 0);
        if (*(int*)(self + 0xB8) != 0) {
            if (--*(int*)(self + 0xB8) == 0) {
                if (*(int*)(self + 0xAC) == 0) {
                    func_00277800(self);
                    return;
                }
                if (func_00277DD8(self, item) == 0) {
                    func_00282720(*(void**)self, *(int*)(item + 0xC));
                } else {
                    func_002839A8(*(char**)self + 0x500);
                }
            }
        }
        if (*(int*)(obj + 0x44) == 0 && *(int*)(self + 0xB8) == 0) {
            *(int*)(self + 0xAC) = 0;
            *(int*)(self + 0xB0) = 0;
        }
    }
    if (*(int*)(self + 0xA8) != 0) {
        void* list = self + 0xC;
        char* item = (char*)func_00283D70(list, *(int*)(self + 0xBC));
        int ok;
        if (func_00277DD8(self, item) == 0) {
            ok = func_00282798(*(void**)self, *(int*)((char*)func_00283D70(list, *(int*)(self + 0xBC)) + 0xC)) == 2;
        } else {
            ok = *(int*)(item + 0xC) >= 0;
        }
        if (ok) {
            func_00277C08(self, 0, 1);
            func_00277838(self);
        }
        return;
    }
    if (*(int*)(self + 0xC8) != 0) {
        if (--*(int*)(self + 0xC8) == 0) {
            if (*(int*)(self + 0xB0) != 0) {
                func_002E4578(func_00230698(*(void**)(D_004A28A8 + 0x84), 0));
                *(int*)(self + 0xAC) = 0;
                *(int*)(self + 0xB0) = 0;
                *(int*)(self + 0xB8) = 0;
            }
            func_00277800(self);
            return;
        }
    }
    char* item = (char*)func_00283D70(self + 0xC, 0);
    int done = 0;
    if (func_00277DD8(self, item) == 0) {
        if (func_00282798(*(void**)self, *(int*)(item + 0xC)) == 2 || func_00282838(*(void**)self, *(int*)(item + 0xC)) != 0) {
            done = 1;
        }
    } else if (func_00283BB8(*(char**)self + 0x500) != 0) {
        func_00277980(self);
        done = 1;
    }
    if (done) {
        func_00277800(self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00276F48);
#ifdef SKIP_ASM
extern "C" int func_00277450(void* self, int index, int a2);
extern "C" void func_00277800(void* self);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" int func_00282540(void* self, int id);
extern "C" void func_00283818(void* p);
extern "C" void* func_00283D70(void* list, int i);

extern "C" void func_00276F48(char* self)
{
    if (*(int*)(self + 0xA4) != 3) {
        return;
    }
    if (*(int*)(self + 0xC8) != 0) {
        return;
    }
    void* list = self + 0xC;
    char* e = (char*)func_00283D70(list, 0);
    if (!(*(int*)(e + 0x8) & 1)) {
        return;
    }
    *(int*)(self + 0xC8) = 1;
    if (*(int*)(self + 0xBC) < 0) {
        func_00277450(self, 1, 1);
        return;
    }
    int idx = func_00277450(self, *(int*)(self + 0xBC), 1);
    if (idx != *(int*)(self + 0xBC)) {
        char* e2 = (char*)func_00283D70(list, *(int*)(self + 0xBC));
        if (func_00277DD8(self, e2) == 0) {
            func_00282540(*(void**)self, *(int*)(e2 + 0xC));
            *(int*)(e2 + 0xC) = -1;
        } else if (*(int*)(e2 + 0xC) >= 0) {
            func_00283818(*(char**)self + 0x500);
        }
        *(int*)(self + 0xBC) = idx;
    }
    if (idx >= 0) {
        func_00277800(self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277060);
#ifdef SKIP_ASM
extern "C" void* func_00283D70(void* list, int i);

extern "C" int func_00277060(void* self)
{
    if (*(int*)((char*)self + 0xA4) != 3) {
        return 0;
    }
    int r = 0;
    void* e = func_00283D70((char*)self + 0xC, 0);
    if (*(int*)((char*)e + 0x8) & 1) {
        r = *(int*)((char*)self + 0xA8) == 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_002770C0);
#ifdef SKIP_ASM
extern "C" void* func_00283D70(void* list, int i);

extern "C" int func_002770C0(void* self)
{
    if (*(int*)((char*)self + 0xA4) != 3) {
        return 1;
    }
    void* e = func_00283D70((char*)self + 0xC, 0);
    return (*(int*)((char*)e + 0x8) >> 2) & 1;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277100);
#ifdef SKIP_ASM
extern "C" int func_00277100(void* self)
{
    if (*(int*)((char*)self + 0xA4) == 1) {
        return 0;
    }
    int idx = *(int*)((char*)self + 0xBC);
    void* list = (char*)self + 0xC;
    if (idx < 0) {
        return 1;
    }
    void* item = func_00283D70(list, idx);
    if (func_00277DD8(self, item) != 0) {
        return *(int*)((char*)item + 0xC) >= 0;
    }
    return func_00282798(*(void**)self, *(int*)((char*)func_00283D70(list, *(int*)((char*)self + 0xBC)) + 0xC)) == 2;
}
#endif
//100%
INCLUDE_ASM("scripter/datamanager", func_002771A8);
#ifdef SKIP_ASM
extern "C" void func_00283C58__FPv(int);

extern "C" void func_002771A8(int arg0) {
    func_00283C58__FPv(arg0 + 0xC);
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_002771C8);
#ifdef SKIP_ASM
extern "C" void* func_00283D70(void* list, int i);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" void* func_00282BF0(void* self, int a1);
extern void* D_004A28A4;

extern "C" int func_002771C8(void* self, void* obj)
{
    if (*(int*)((char*)self + 0xA4) != 3) {
        return 0;
    }
    void* e = func_00283D70((char*)self + 0xC, 0);
    if (func_00277DD8(self, e) != 0) {
        return 0;
    }
    return obj == func_00282BF0(D_004A28A4, *(int*)((char*)e + 0xC));
}
#endif

INCLUDE_ASM("scripter/datamanager", func_00277248);

//100%
INCLUDE_ASM("scripter/datamanager", func_00277298);
#ifdef SKIP_ASM
extern "C" int func_00277298(void* self)
{
    int r = 0;
    if (*(int*)((char*)self + 0xa4) == 3) {
        r = *(int*)((char*)self + 0xa8) != 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_002772B8__FPv);
#ifdef SKIP_ASM
int func_002772B8(void* self)
{
    return *(int*)((char*)self + 0xB0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/datamanager", func_002772C0);
#ifdef SKIP_ASM
extern "C" int func_002771C8(void* self, void* obj);
char* func_0027C070(void* obj);
extern "C" void func_002EF378(int a0);
extern char D_004A34A8[];

extern "C" void func_002772C0(void* self, int a1, void* obj)
{
    if (func_002771C8(self, obj) != 0) {
        char* name = func_0027C070(obj);
        char* msg = D_004A34A8;
        if (*name != 0) {
            func_002EF378((int)msg); // PORT: string pointer passed as int (unit declares func_002EF378(int))
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/datamanager", func_00277310);
#ifdef SKIP_ASM
extern "C" int func_002771C8(void* self, void* obj);
char* func_0027C070(void* obj);
extern "C" int func_00274D08(void* obj);
extern "C" void func_00277980(void* self);

extern "C" void func_00277310(void* self, int a1, void* obj)
{
    if (func_002771C8(self, obj) != 0 && *(int*)((char*)self + 0x4) != 0 &&
        *(int*)((char*)obj + 0x1C) == 0) {
        char* name = func_0027C070(obj);
        if (func_00274D08(obj) + 1 <= *(short*)(name + 0x12)) {
            func_00277980(self);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/datamanager", func_002773A0);
#ifdef SKIP_ASM
extern "C" int func_002771C8(void* self, void* obj);
extern "C" void func_002776E0(void* self);
extern "C" void func_002826D8(void* self, int a1);

extern "C" void func_002773A0(void* self, int a1, void* obj)
{
    if (func_002771C8(self, obj) != 0) {
        if (*(int*)((char*)self + 0xB8) != 0) {
            func_002826D8(*(void**)self, a1);
        }
        func_002776E0(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/datamanager", func_00277400);
#ifdef SKIP_ASM
extern "C" int func_002771C8(void* self, void* obj);
char* func_0027C070(void* obj);
extern "C" void func_002EF378(int a0);

extern "C" void func_00277400(void* self, int a1, void* obj)
{
    if (func_002771C8(self, obj) != 0) {
        if (*func_0027C070(obj) != 0) {
            func_002EF378(0);
        }
    }
}
#endif

INCLUDE_ASM("scripter/datamanager", func_00277450);

//100%
INCLUDE_ASM("scripter/datamanager", func_00277598);
#ifdef SKIP_ASM
struct sDmEnt7DE8;
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" sDmEnt7DE8* func_00277DE8(void* self, int* key);
extern "C" int func_00282540(void* self, int id);
extern "C" void func_00283818(void* p);
extern "C" int func_00283BB8(void* self);
extern "C" void* func_00283D70(void* list, int i);
extern "C" int func_00283DA0(void* self);
extern "C" int func_00283DC0(void* self, void* out);
extern "C" void* func_0028B180();

struct sDmCmd7598 {
    int category;   // 0x0
    int key;        // 0x4
    int flags;      // 0x8
    int id;         // 0xC
    int a;          // 0x10
    int b;          // 0x14
    int c;          // 0x18
};

struct sDmSndVEntry7598 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00277598(void* selfp, int n)
{
    char* self = (char*)selfp;
    while (n != 0) {
        if (func_00283DA0(self + 0xC) != 0) {
            return;
        }
        sDmCmd7598 cmd = *(sDmCmd7598*)func_00283D70(self + 0xC, 0);
        if (cmd.id >= 0) {
            if (func_00277DD8(self, &cmd) == 0) {
                func_00282540(*(void**)self, cmd.id);
            } else {
                if (*(int*)(*(char**)self + 0x504) != 0) {
                    int* ent = (int*)func_00277DE8(self, (int*)&cmd);
                    int snd;
                    if (func_00283BB8(*(char**)self + 0x500) != 0) {
                        snd = ent[6];
                    } else {
                        snd = ent[5];
                    }
                    if (snd >= 0) {
                        char* o = (char*)func_0028B180();
                        sDmSndVEntry7598* vt = *(sDmSndVEntry7598**)(o + 0x5558);
                        char* sys = o + 0x118;
                        vt[4].fn(sys + vt[4].delta, snd);
                    }
                }
                func_00283818(*(char**)self + 0x500);
            }
        }
        func_00283DC0(self + 0xC, 0);
        n--;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_002776E0);
#ifdef SKIP_ASM
extern "C" void* func_00283D70(void* list, int i);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" int func_00282798(void* self, int a1);

extern "C" void func_002776E0(void* self)
{
    int idx = *(int*)((char*)self + 0xBC);
    if (idx >= 0) {
        void* list = (char*)self + 0xC;
        char* e = (char*)func_00283D70(list, idx);
        int ok;
        if (func_00277DD8(self, e) == 0) {
            ok = func_00282798(*(void**)self,
                               *(int*)((char*)func_00283D70(list, *(int*)((char*)self + 0xBC)) + 0xC)) == 1;
        } else {
            ok = *(int*)(e + 0xC) < 0;
        }
        if (ok) {
            func_00277C08(self, 1, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277778);
#ifdef SKIP_ASM
extern "C" void* func_00283D70(void* list, int i);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" int func_00282798(void* self, int a1);

extern "C" void func_00277778(void* self)
{
    if (*(int*)((char*)self + 0xA4) == 1) {
        char* e = (char*)func_00283D70((char*)self + 0xC, 0);
        if (func_00277DD8(self, e) == 0) {
            int r = func_00282798(*(void**)self, *(int*)(e + 0xC));
            if (r == 2) {
                *(int*)((char*)self + 0xA4) = r;
            }
        } else {
            *(int*)((char*)self + 0xA4) = 2;
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277800);
#ifdef SKIP_ASM
extern "C" void func_002776E0(void* self);
extern "C" void func_00277838(void* self);

extern "C" void func_00277800(void* self)
{
    func_002776E0(self);
    if (*(int*)((char*)self + 0xA8) == 0) {
        func_00277838(self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277838);
#ifdef SKIP_ASM
void* func_00230698(void* self, int a1);
extern "C" void func_00276868(void* self, int a1);
extern "C" int func_00277450(void* self, int index, int a2);
extern "C" void func_00277598(void* self, int index);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" void func_00279720(void* self, int val, int key, int b, int c);
extern "C" int func_002839A8(void* self);
extern "C" void* func_00283D70(void* list, int i);
extern "C" float func_002E4678(void* self);
extern "C" void func_002EA780(void* self, float t);
extern char* D_004A28A8;

struct sDmCmd7838 {
    int category;   // 0x0
    int key;        // 0x4
    int flags;      // 0x8
    int id;         // 0xC
};

struct sDmEngVEntry7838 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

extern "C" void func_00277838(void* selfp)
{
    char* self = (char*)selfp;
    if (*(int*)(self + 0xBC) > 0) {
        *(int*)(self + 0xC8) = 0;
        func_00277598(self, *(int*)(self + 0xBC));
        *(int*)(self + 0xC0) = 0;
        *(int*)(self + 0xBC) = -1;
        sDmCmd7838* cmd = (sDmCmd7838*)func_00283D70(self + 0xC, 0);
        if (func_00277DD8(self, cmd) == 0) {
            func_00279720(*(void**)self, *(int*)(self + 0x8), cmd->id, 0, (cmd->flags >> 3) & 1);
            char* eng = *(char**)self;
            sDmEngVEntry7838* vt = *(sDmEngVEntry7838**)(eng + 0x2A8);
            vt[6].fn(eng + vt[6].delta, cmd->id);
        } else {
            func_002839A8(*(char**)self + 0x500);
        }
        if (*(int*)(self + 0xB0) != 0) {
            *(int*)(self + 0xAC) = 1;
        }
        *(int*)(self + 0xBC) = func_00277450(self, 1, 0);
    } else {
        int wasOn = *(int*)(self + 0xB0);
        func_00276868(self, 0);
        if (*(int*)(self + 0x4) != 0) {
            void* app = *(void**)(D_004A28A8 + 0x84);
            void* fade = *(void**)((char*)app + 0x64);
            char* p = (char*)func_00230698(app, 0);
            if (wasOn != 0 && *(int*)(p + 0x44) != 0) {
                func_002EA780(fade, func_002E4678(p));
            } else {
                func_002EA780(fade, 0.5f);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277980);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* func_00230698(void* self, int a1);
char* func_0027C070(void* obj);
extern "C" int func_00277DD8(void* self, void* a1);
struct sDmEnt7DE8;
extern "C" sDmEnt7DE8* func_00277DE8(void* self, int* key);
extern "C" void* func_00282BF0(void* self, int a1);
extern "C" void* func_00283D70(void* list, int i);
extern "C" void func_002E4578(void* p);
extern "C" int func_0027A4A0(void* self, int a1, int a2);
extern "C" void func_002E4370(void* snd, int a1, int h, int h2, int a4, int a5, float t0, float t1, float t2);
extern "C" void func_002E44F0(void* snd, int a1, int h, float t);
extern "C" void func_002E4540(void* snd, int a1, int h, int a3, float t);
extern char* D_004A28A8;
extern void* D_004A28A4;

struct sDmFade_7980 {
    char pad_0x0[0x10];
    signed char cat;        // 0x10
    signed char key;        // 0x11
    short tIn;              // 0x12
    short tHold;            // 0x14
    short tOut;             // 0x16
};

struct sDmEnt_7980 {
    int v0;
    int cat;                // 0x4
    int key;                // 0x8
    float t;                // 0xC
};

// The unit declares func_00277980 as void; it returns whether it handled the update.
int func_00277980_impl(char* self) __asm__("func_00277980");

int func_00277980_impl(char* self)
{
    if (*(int*)(self + 0xB0) != 0) {
        if (*(int*)(self + 0xAC) != 0) {
            func_002E4578(func_00230698(*(void**)(D_004A28A8 + 0x84), 0));
            return 0;
        }
        return 1;
    }
    char* item = (char*)func_00283D70(self + 0xC, 0);
    if (func_00277DD8(self, item) == 0) {
        sDmFade_7980* f = (sDmFade_7980*)func_0027C070(func_00282BF0(D_004A28A4, *(int*)(item + 0xC)));
        void* snd = func_00230698(*(void**)(D_004A28A8 + 0x84), 0);
        if (*(int*)((char*)snd + 0x44) != 0) {
            func_002E4578(snd);
        }
        if (f->tIn + f->tHold + f->tOut > 0) {
            if (f->cat != 7) {
                int h = func_0027A4A0(*(void**)self, f->cat, f->key);
                if (h == 0) {
                    return 0;
                }
                int h2 = func_0027A4A0(*(void**)self, f->cat, f->key);
                func_002E4370(snd, 2, h, h2, 0, 0, (float)f->tIn * 0.01666666753590107f, (float)f->tHold * 0.01666666753590107f, (float)f->tOut * 0.01666666753590107f);
                *(int*)(self + 0xB8) = f->tIn + f->tHold;
            } else {
                int h = func_0027A4A0(D_004A28A4, 7, f->key);
                func_002E4540(snd, 2, h, 0, (float)f->tIn * 0.01666666753590107f);
                *(int*)(self + 0xB8) = 0;
            }
            if (*(int*)(self + 0xB8) > 0) {
                *(int*)(self + 0xAC) = 0;
                *(int*)(self + 0xB0) = 1;
            }
        }
    } else {
        sDmEnt_7980* e = (sDmEnt_7980*)func_00277DE8(self, (int*)item);
        void* snd = func_00230698(*(void**)(D_004A28A8 + 0x84), 0);
        if (*(int*)((char*)snd + 0x44) != 0) {
            func_002E4578(snd);
        }
        if (0.0f < e->t) {
            if (e->cat != 7) {
                int h = func_0027A4A0(*(void**)self, e->cat, e->key);
                func_002E44F0(snd, 2, h, e->t);
                *(int*)(self + 0xB8) = 0;
            } else {
                int h = func_0027A4A0(D_004A28A4, 7, e->key);
                func_002E4540(snd, 2, h, 0, e->t);
                *(int*)(self + 0xB8) = 0;
            }
        }
    }
    return *(int*)(self + 0xB0);
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277C08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char* D_004A28A8;
void* func_00230698(void* self, int a1);
extern "C" int func_00277DD8(void* self, void* a1);
extern "C" void func_002826D8(void* self, int a1);
extern "C" void func_00282720(void* self, int a1);
extern "C" int func_00282798(void* self, int a1);
extern "C" void func_00283B78(void* self, int on);
extern "C" void* func_00283D70(void* list, int i);
extern "C" void func_002E4638(void* p, int on);
extern "C" void func_002EA8B8(void* p, int on);

struct sSeqItem_7C08 {
    char pad_0x0[0xC];
    int handle;         // 0xC
};

struct sSeq_7C08 {
    char* owner;        // 0x0
    int f4;             // 0x4
    char pad_0x8[0x4];
    char list[0x98];    // 0xC
    int state;          // 0xA4
    int paused;         // 0xA8
    char pad_0xAC[0x18];
    int pauseCount;     // 0xC4
};

// The unit declares func_00277C08 as returning void*; the body returns nothing. Bind by asm label.
extern "C" void func_00277C08_impl(sSeq_7C08* self, int on, int hard) __asm__("func_00277C08");

extern "C" void func_00277C08_impl(sSeq_7C08* self, int on, int hard)
{
    if (self->state != 3) {
        return;
    }
    if (hard == 0) {
        int c = self->pauseCount;
        if (on) {
            self->pauseCount = c + 1;
            if (c != 0) {
                return;
            }
        } else {
            if (c <= 0) {
                return;
            }
            int d = c - 1;
            self->pauseCount = d;
            if (d != 0) {
                return;
            }
        }
        if (self->paused) {
            return;
        }
    } else {
        if (self->paused == on) {
            return;
        }
        self->paused = on;
        if (self->pauseCount) {
            return;
        }
    }
    if (on) {
        sSeqItem_7C08* it = (sSeqItem_7C08*)func_00283D70(self->list, 0);
        if (func_00277DD8(self, it) == 0) {
            int st = func_00282798(self->owner, it->handle);
            if (st >= 3 && st <= 5) {
                func_002826D8(self->owner, it->handle);
            }
        } else {
            func_00283B78(self->owner + 0x500, 1);
        }
        if (self->f4) {
            func_002EA8B8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x64), 1);
            char* p = (char*)func_00230698(*(void**)(D_004A28A8 + 0x84), 0);
            if (*(int*)(p + 0x44)) {
                func_002E4638(p, 1);
            }
        }
    } else {
        sSeqItem_7C08* it = (sSeqItem_7C08*)func_00283D70(self->list, 0);
        if (func_00277DD8(self, it) == 0) {
            if (func_00282798(self->owner, it->handle) == 5) {
                func_00282720(self->owner, it->handle);
            }
        } else {
            func_00283B78(self->owner + 0x500, 0);
        }
        if (self->f4) {
            func_002EA8B8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x64), 0);
            char* p = (char*)func_00230698(*(void**)(D_004A28A8 + 0x84), 0);
            if (*(int*)(p + 0x44)) {
                func_002E4638(p, 0);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277DD8);
#ifdef SKIP_ASM
extern "C" int func_00277DD8(void* self, void* a1)
{
    return *(int*)a1 >= 0x1d;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277DE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");

struct sDmCfg7DE8 {
    unsigned int flags;
    int v[(0x288 - 4) / 4];
};

struct sDmEnt7DE8 {
    int v[7];
};

extern sDmCfg7DE8 D_00535610;
extern sDmEnt7DE8 D_004823DC[];
extern sDmEnt7DE8 D_0048247C[];

extern "C" sDmEnt7DE8* func_00277DE8(void* self, int* key)
{
    cBE_getInterface_Fv(cBE_getBE(), 4);
    sDmCfg7DE8 cfg = D_00535610;
    if ((cfg.flags & 0x300000) != 0x200000) {
        return &D_0048247C[*key];
    }
    return &D_004823DC[*key];
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277F08__FPv);
#ifdef SKIP_ASM
void func_00277F08(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 0x4) = -1;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00277F20);
#ifdef SKIP_ASM
extern "C" void func_00281E80(void* self);
extern "C" void func_00283798(void* self);
extern "C" void func_00281018(void* self);
extern "C" void func_0027BFD0(void* self);
extern "C" void func_002805B8(void* self);
extern "C" void cScriptAnimBankManager_cScriptAnimBankManager(void* self, int flags, int a2, int a3);
extern "C" void cScriptSoundBankManager_cScriptSoundBankManager(void* self, int flags, int a2, int a3);
void func_00281160(void* self, int i);
extern void* D_00482100[];
extern void* D_004821A0[];
extern void* D_00482168[];
extern void* D_004821B8[];
extern void* D_004A34B0;

struct sScriptSlot_7F20 {
    char data[0x120];
    sScriptSlot_7F20() { func_00281018(this); }
    void* operator new[](unsigned int, void* p) { return p; }
};

struct sScriptMgr_7F20 {
    char pad_0x0[0x2A8];
    void** vt2A8;               // 0x2A8
    void** vt2AC;               // 0x2AC
    char pad_0x2B0[0x518 - 0x2B0];
    void** vt518;               // 0x518
    char pad_0x51C[0x528 - 0x51C];
    void** vt528;               // 0x528
    int f52C;                   // 0x52C
    int f530;                   // 0x530
    int f534;                   // 0x534
    int f538;                   // 0x538
    int f53C;                   // 0x53C
    int f540;                   // 0x540
    int f544;                   // 0x544
    int f548;                   // 0x548
    int f54C;                   // 0x54C
    int f550;                   // 0x550
    int f554;                   // 0x554
    int ids[50];                // 0x558
    int f620;                   // 0x620
    int f624;                   // 0x624
    char cues[10][0x10];        // 0x628
    char pad_0x6C8[0x6D0 - 0x6C8];
    char slots[2][0x120];       // 0x6D0
    char pad_0x910[0xA48 - 0x910];
    int fA48;                   // 0xA48
};

extern "C" sScriptMgr_7F20* func_00277F20(sScriptMgr_7F20* self)
{
    func_00281E80(self);
    func_00283798((char*)self + 0x500);
    cDataManager_cDataManager((cDataManager5828*)((char*)self + 0x51C), 0, 0x100);
    self->vt2AC = D_00482100;
    self->vt518 = D_004821A0;
    self->vt528 = D_00482168;
    self->vt2A8 = D_004821B8;
    new ((char*)self + 0x6D0) sScriptSlot_7F20[2];
    func_0027BFD0((char*)self + 0x910);
    func_002805B8((char*)self + 0x92C);
    cScriptAnimBankManager_cScriptAnimBankManager((char*)self + 0xA28, 0, 10, 0xF0);
    cScriptSoundBankManager_cScriptSoundBankManager((char*)self + 0xA38, 0, 10, 0x11);
    self->f52C = 0;
    self->f530 = 0;
    self->f534 = 0;
    self->f538 = 0;
    self->f53C = 0;
    self->f540 = 0;
    self->f544 = 0;
    self->f548 = 0;
    D_004A34B0 = self;
    self->fA48 = 10;
    self->f550 = 2;
    self->f54C = 0;
    self->f554 = 0;
    self->f620 = 0;
    self->f624 = 0;
    int i;
    for (i = 49; i >= 0; i--) {
        self->ids[i] = 0;
    }
    for (i = 0; i < 10; i++) {
        func_00277F08(self->cues[i]);
    }
    for (i = 0; i < 2; i++) {
        func_00281160(self->slots[i], i);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_002780B8);
#ifdef SKIP_ASM
extern void* D_00482260[];
extern void* D_00482298[];
extern void* D_004822E0[];
extern void* D_00482318[];
extern "C" void func_00278308(void* self);
extern "C" void func_00283518(void* self, int flags);
extern "C" void func_00275498(void* self, int flags);
extern "C" void func_00283228(void* self, int flags);
extern "C" void func_002758C0(void* self, int flags);
extern "C" void func_002837C8(void* self, int flags);
extern "C" void func_00281ED8(void* self, int flags);

struct sVE_780B8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sSlot_780B8 {
    char pad[0xC];
    sVE_780B8* vt;              // 0xC
    char rest[0x120 - 0x10];
};

// Script manager destructor: members in reverse order, then the base.
extern "C" void func_002780B8(char* self, int flags)
{
    *(void***)(self + 0x2AC) = D_00482100;
    *(void***)(self + 0x518) = D_004821A0;
    *(void***)(self + 0x528) = D_00482168;
    *(void***)(self + 0x2A8) = D_004821B8;
    if (*(int*)(self + 0x52C) != 0) {
        func_00278308(self);
    }
    D_004A34B0 = 0;
    func_00283518(self + 0xA38, 2);
    func_00275498(self + 0xA28, 2);
    *(void***)(self + 0x944) = D_00482298;
    *(void***)(self + 0x92C) = D_00482260;
    func_00283228(self + 0x938, 0);
    *(void***)(self + 0x928) = D_00482318;
    *(void***)(self + 0x910) = D_004822E0;
    func_00283228(self + 0x91C, 0);
    sSlot_780B8* p = (sSlot_780B8*)(self + 0x910);
    sSlot_780B8* begin = (sSlot_780B8*)(self + 0x6D0);
    if (begin != 0) {
        do {
            while (begin != p) {
                p--;
                p->vt[1].fn((char*)p + p->vt[1].delta, 0);
            }
        } while (0);
    }
    func_002758C0(self + 0x51C, 0);
    func_002837C8(self + 0x500, 0);
    func_00281ED8(self, flags);
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00278210);
#ifdef SKIP_ASM
extern "C" void* func_003E1908(const char* name, int flags);
extern "C" void cBXScriptEngine_SetupBXEngine(void* self, int count, int a2, int size);
extern char* D_004A3494;
extern char* D_004A3498;

struct sDmScript8210 {
    int field_0x0;
    int field_0x4;
    int offset;             // 0x8
};

struct sDmEngine8210 {
    char pad_0x0[0x52C];
    int* hdr;                   // 0x52C
    sDmScript8210* scripts;     // 0x530
    char* base;                 // 0x534
    char pad_0x538[0x1C];
    int field_0x554;            // 0x554
    char pad_0x558[0xC8];
    int field_0x620;            // 0x620
};

// PORT: script offsets are rebased into pointers held in int.
extern "C" void func_00278210(sDmEngine8210* self)
{
    int* hdr = (int*)func_003E1908(D_004A3494, 0);
    self->hdr = hdr;
    self->scripts = (sDmScript8210*)(hdr + 1);
    char* base = (char*)func_003E1908(D_004A3498, 0);
    self->base = base;
    if (base != 0) {
        for (int i = 0; i < *self->hdr; i++) {
            self->scripts[i].offset = (int)self->base + self->scripts[i].offset;
        }
    } else {
        for (int i = 0; i < *self->hdr; i++) {
            self->scripts[i].offset = 0;
        }
    }
    self->field_0x554 = 0;
    self->field_0x620 = 0;
    cBXScriptEngine_SetupBXEngine(self, *self->hdr, 10, 0x4000);
}
#endif

//100%
INCLUDE_ASM("scripter/datamanager", func_00278308);
#ifdef SKIP_ASM
extern "C" void func_00282020(void* self);
extern "C" void* func_002523A8(void* self);

extern "C" void func_00278308(void* self)
{
    func_00282020(self);
    func_002523A8(*(void**)((char*)self + 0x52C));
    if (*(void**)((char*)self + 0x534) != 0) {
        func_002523A8(*(void**)((char*)self + 0x534));
    }
    *(int*)((char*)self + 0x52C) = 0;
    *(int*)((char*)self + 0x530) = 0;
    *(int*)((char*)self + 0x534) = 0;
    *(int*)((char*)self + 0x554) = 0;
}
#endif

