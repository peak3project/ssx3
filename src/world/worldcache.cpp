#include "common.h"

//100%
INCLUDE_ASM("world/worldcache", cWorldBlockAllocator_init);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00494DC0[];
extern char D_00494DD8[];

struct sWBABlock {
    void* data;
    int size;
    int f08;
    int f0C;
    int used;
    sWBABlock* next;
};

struct sWBAlloc {
    int blockSize;
    unsigned int count;
    int numFree;
    sWBABlock* blocks;
    sWBABlock* freeList;
};

extern "C" void cWorldBlockAllocator_init(void* selfp, int count, int blockSize)
{
    sWBAlloc* self = (sWBAlloc*)selfp;
    self->blockSize = blockSize;
    self->count = count;
    self->numFree = count;
    self->blocks = new (D_00494DC0, 0x20000000, 0) sWBABlock[count];
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        self->blocks[i].used = 0;
        self->blocks[i].size = self->blockSize;
        self->blocks[i].f08 = 0;
        self->blocks[i].f0C = 0;
        self->blocks[i].data = new (D_00494DD8, 0x25000000, 0) char[self->blockSize];
        self->blocks[i].next = (i < self->count - 1) ? &self->blocks[i + 1] : 0;
    }
    self->freeList = self->blocks;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A76C0);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);

struct func_003A76C0_sEntry {
    void* data;
    int pad[5];
};

struct func_003A76C0_sCache {
    int f0;
    unsigned int count;
    int f8;
    func_003A76C0_sEntry* entries;
};

extern "C" void func_003A76C0(void* p, int flags)
{
    func_003A76C0_sCache* self = (func_003A76C0_sCache*)p;
    for (unsigned int i = 0; i < self->count; i++) {
        if (self->entries[i].data != 0) {
            cMemMan_free(self->entries[i].data);
        }
    }
    if (self->entries != 0) {
        cMemMan_free(self->entries);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7768__FPv);
#ifdef SKIP_ASM
void* func_003A7768(void* self)
{
    void* item = *(void**)((char*)self + 0x10);
    *(void**)((char*)self + 0x10) = *(void**)((char*)item + 0x14);
    *(int*)((char*)self + 0x8) -= 1;
    *(int*)((char*)item + 0x10) = 1;
    return item;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7790__FPvT0);
#ifdef SKIP_ASM
void func_003A7790(void* self, void* item)
{
    *(int*)((char*)item + 0x10) = 0;
    *(void**)((char*)item + 0x14) = *(void**)((char*)self + 0x10);
    *(void**)((char*)self + 0x10) = item;
    *(int*)((char*)self + 0x8) += 1;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A77B0__FPvii);
#ifdef SKIP_ASM
void* func_003A77B0(void* self, int a1, int a2)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = a2;
    *(int*)self = a1;
    *(int*)((char*)self + 0x8) = t0;
    *(int*)((char*)self + 0xc) = t0;
    *(int*)((char*)self + 0x10) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A77D0);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void func_003A7818(void* self);

extern "C" void func_003A77D0(void* self, int flags)
{
    func_003A7818(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", func_003A7818);
#ifdef SKIP_ASM
void func_003A7790(void* self, void* item);

extern "C" void func_003A7818(void* self)
{
    if (*(void**)((char*)self + 0xC) != 0) {
        void* next;
        do {
            void* item = *(void**)((char*)self + 0xC);
            next = *(void**)((char*)item + 0x14);
            func_003A7790(*(void**)self, item);
            *(void**)((char*)self + 0xC) = next;
            *(int*)((char*)self + 0x8) = *(int*)((char*)self + 0x8) - 1;
        } while (next != 0);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7878);
#ifdef SKIP_ASM
void* func_003A7768(void* self);

struct sWCBlock_7878 {
    char* data;
    int size;
    int pos;
    int pad;
    int used;
    sWCBlock_7878* next;
};

struct sWCPool_7878 {
    void* alloc;
    int f4;
    unsigned int count;
    sWCBlock_7878* head;
    sWCBlock_7878* cur;
};

static inline void NewBlock_7878(sWCPool_7878* self)
{
    sWCBlock_7878* b = (sWCBlock_7878*)func_003A7768(self->alloc);
    b->pos = 0;
    b->pad = 0;
    b->next = self->head;
    self->head = b;
    self->cur = b;
    self->count++;
}

extern "C" char* func_003A7878(sWCPool_7878* self, int size, unsigned int flags)
{
    if (self->count == 0)
        NewBlock_7878(self);
    sWCBlock_7878* first = self->cur;
    int align = 4 << ((flags >> 24) & 0xF);
    int pos = first->pos;
    int rem = pos % align;
    int pad = 0;
    if (rem)
        pad = align - rem;
    if (pos + pad + size < first->size)
    {
        first->pos = pos + (pad + size);
        char* p = first->data + pos;
        p += pad;
        self->cur->pad += pad;
        return p;
    }
    if (self->count >= 2)
    {
        self->cur = self->head;
        if (self->cur)
        {
            do
            {
                sWCBlock_7878* b = self->cur;
                if (b != first)
                {
                    int bpos = b->pos;
                    rem = bpos % align;
                    pad = 0;
                    if (rem)
                        pad = align - rem;
                    if (bpos + pad + size < b->size)
                    {
                        b->pos = bpos + (pad + size);
                        char* p = b->data + bpos;
                        p += pad;
                        self->cur->pad += pad;
                        return p;
                    }
                }
                self->cur = self->cur->next;
            } while (self->cur);
        }
    }
    NewBlock_7878(self);
    self->cur->pos += size;
    return self->cur->data;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", func_003A7A20);
#ifdef SKIP_ASM
struct func_003A7A20_sCfg {
    int id;
    int size;
    int count;
};
extern func_003A7A20_sCfg D_0044C1E0[];
extern "C" void cWorldBlockAllocator_init(void* self, int size, int count);

extern "C" void* func_003A7A20(void* self)
{
    cWorldBlockAllocator_init(self, D_0044C1E0[0].size, D_0044C1E0[0].count);
    cWorldBlockAllocator_init((char*)self + 0x14, D_0044C1E0[1].size, D_0044C1E0[1].count);
    cWorldBlockAllocator_init((char*)self + 0x28, D_0044C1E0[2].size, D_0044C1E0[2].count);
    int i;
    for (i = 63; i >= 0; i--) {
        ((int*)((char*)self + 0x3C))[i] = 0;
    }
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", func_003A7AA8);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void func_003A76C0(void* self, int flags);

struct func_003A7AA8_sElem {
    char pad[0x14];
};

extern "C" void func_003A7AA8(func_003A7AA8_sElem* self, int flags)
{
    if (self != 0) {
        func_003A7AA8_sElem* p = self + 3;
        while (self != p) {
            p--;
            func_003A76C0(p, 0);
        }
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", cWorldMemoryMan_activateSectionMem);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* func_003A77B0(void* self, int section, int index);
extern char D_00494DE8[];

struct cWorldMemoryMan_sSection {
    char pad[0x14];
};

// PORT: the section pointer is passed as int (the callee's mangled name is __FPvii).
extern "C" void cWorldMemoryMan_activateSectionMem(void* self, int index, int section)
{
    void** mem = (void**)((char*)self + 0x3C);
    void** slot = &mem[index];
    *slot = func_003A77B0(cMemMan_alloc(0x14, D_00494DE8, 0x20000000, 0),
                          (int)((cWorldMemoryMan_sSection*)self + section), index);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", func_003A7B98);
#ifdef SKIP_ASM
extern "C" void func_003A77D0(void* self, int flags);

extern "C" void func_003A7B98(void* self, int i)
{
    char* base = (char*)self + 0x3C;
    void** p = (void**)(base + (i << 2));
    if (*p != 0) {
        func_003A77D0(*p, 3);
    }
    *p = 0;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", cHullPage_cHullPage);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d), like cMemMan_alloc.
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00494E00[];

extern "C" void* cHullPage_cHullPage(void* self, unsigned short* data)
{
    *(unsigned short**)self = data;
    unsigned short n = *data;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x4) = n;
    *(void**)((char*)self + 0xC) = operator_new_tag(n * 4, D_00494E00, 0x20000000, 0);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7C30);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);

extern "C" void func_003A7C30(int* self, int flags)
{
    *(int*)((char*)self + 0x4) = 0;
    if (*(void**)((char*)self + 0xC) != 0) {
        cMemMan_free(*(void**)((char*)self + 0xC));
    }
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", cWorldCacheTable_cWorldCacheTable);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* func_00416210(void* dst, int c, int n);
extern char D_00494E18[];

struct sWCTEntry {
    int* ptr;
    int count;
};

struct sWCTable {
    int* pool;
    sWCTEntry entries[28];
    short* sizes;
};

extern "C" void* cWorldCacheTable_cWorldCacheTable(void* selfp, void* data)
{
    sWCTable* self = (sWCTable*)selfp;
    self->sizes = (short*)data;
    func_00416210(self->entries, 0, sizeof(self->entries));
    int total = 0;
    for (int i = 0; i < 28; i++) {
        int n = self->sizes[i];
        self->entries[i].count = n;
        total += n;
    }
    self->pool = new (D_00494E18, 0, 0) int[total];
    func_00416210(self->pool, 0, total * 4);
    int off = 0;
    int* pool = self->pool;
    for (int j = 0; j < 28; j++) {
        if (self->entries[j].count != 0) {
            self->entries[j].ptr = pool + off;
            off += self->entries[j].count;
        }
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7D80);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);

extern "C" void func_003A7D80(int* self, int flags)
{
    if (*(void**)self != 0) {
        cMemMan_free(*(void**)self);
    }
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7DD0);
#ifdef SKIP_ASM
extern "C" void* func_003A8F80(void* self);
extern "C" void* cStreamMan_cStreamMan(void* self);
extern char* D_004A5B64;

extern "C" void* func_003A7DD0(void* self)
{
    func_003A8F80((char*)self + 0x10);
    cStreamMan_cStreamMan((char*)self + 0x300);
    char* app = D_004A5B64;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x3EC) = 0;
    *(int*)((char*)self + 0x3E8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x1BF0) = (int)((float)*(int*)(app + 0x10) * 0.10000000149011612f);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7E38);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void func_003A7E98(void* self);
extern "C" void func_003A6E20(void* p, int flags);
extern "C" void func_003A8FB8(void* p, int flags);

extern "C" void func_003A7E38(int* self, int flags)
{
    func_003A7E98(self);
    func_003A6E20((char*)self + 0x300, 2);
    func_003A8FB8((char*)self + 0x10, 2);
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7E98);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern "C" void func_003A8330(void* self);
extern "C" int func_003A9890(void* view, int i);
extern "C" void func_003A8230(void* self, int i);
extern "C" void func_003A7D80(int* self, int flags);

struct func_003A7E98_sVEntry {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct func_003A7E98_sObj {
    int f0;
    int f4;
    func_003A7E98_sVEntry* vt;
};

struct func_003A7E98_sHdr {
    int f0;
    int f4;
    unsigned int count;
};

struct func_003A7E98_sCache {
    func_003A7E98_sHdr* hdr;
    int* f04;
    void* f08;
    func_003A7AA8_sElem* f0C;
    char view[0x3D8];
    func_003A7E98_sObj* obj;
};

extern "C" void func_003A7E98(void* p)
{
    func_003A7E98_sCache* self = (func_003A7E98_sCache*)p;
    func_003A8330(self);
    func_003A7E98_sObj* o = self->obj;
    if (o != 0) {
        o->vt[1].fn((char*)o + o->vt[1].delta, 3);
    }
    if (self->f04 != 0) {
        func_003A7D80(self->f04, 3);
    }
    if (self->f08 != 0) {
        unsigned int i;
        for (i = 0; i < self->hdr->count; i++) {
            if (func_003A9890(self->view, i) == 0) {
                func_003A8230(self, i);
            }
        }
        if (self->f08 != 0) {
            cMemMan_free(self->f08);
        }
    }
    if (self->hdr != 0) {
        cMemMan_free(self->hdr);
    }
    if (self->f0C != 0) {
        func_003A7AA8(self->f0C, 3);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A7F90);
#ifdef SKIP_ASM
extern "C" void func_003A7E98(void* self);

extern "C" void func_003A7F90(void* self)
{
    func_003A7E98(self);
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x3EC) = 0;
    *(int*)((char*)self + 0x3E8) = 0;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", cWorldCache_init);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_003A7A20(void* self);
extern "C" void* cWorldCacheTable_cWorldCacheTable(void* self, void* data);
extern "C" void* FILE_load(const char* name, int flags);
extern "C" void* func_003AAD98(void);
extern "C" int func_003A6E98(void* self, const char* name, void* owner);
// PORT: the unit defines func_003A9000(sWorldCacheMap*, sWCHdr*, int id); this caller passes the cache in the
// third argument. Bound by asm label with pointer parameters.
extern "C" int func_003A9000_p(void* self, void* data, void* owner) __asm__("func_003A9000");
struct func_003A82C8_sCache;
extern "C" void func_003A82C8(func_003A82C8_sCache* self);
extern char D_00494E30[];
extern char D_00494E40[];
extern char D_00494E50[];
extern char D_004A47C0[];
extern char D_004A47C8[];

struct sBXStr_7FC0
{
    char* p;
    sBXStr_7FC0() {}
    sBXStr_7FC0(const sBXStr_7FC0&);
};

extern "C" void* cBXString_cBXString2(sBXStr_7FC0* self, const char* s);
extern "C" sBXStr_7FC0* func_00318630(sBXStr_7FC0* self, sBXStr_7FC0* a, const char* str);
extern "C" sBXStr_7FC0* func_003186D0(sBXStr_7FC0* self, const char* str, sBXStr_7FC0* b);
extern "C" void cBXString__cBXString(sBXStr_7FC0* self, int flags);

struct sVE_7FC0 { short delta; short index; void (*fn)(void*, int); };

extern "C" int cWorldCache_init(void* self, const char* name, int arg)
{
    *(void**)((char*)self + 0xC) = func_003A7A20(cMemMan_alloc(0x13C, D_00494E30, 0, 0));
    sBXStr_7FC0 path;
    sBXStr_7FC0 full;
    sBXStr_7FC0 base;
    func_003186D0(&full, D_004A47C0, (cBXString_cBXString2(&base, name), &base));
    func_00318630(&path, &full, D_004A47C8);
    *(void**)self = FILE_load(path.p, 0x2000000);
    cBXString__cBXString(&path, 2);
    cBXString__cBXString(&full, 2);
    cBXString__cBXString(&base, 2);
    char* hdr = *(char**)self;
    *(char**)(hdr + 0x14) = hdr + 0x50;
    *(void**)((char*)self + 0x4) = cWorldCacheTable_cWorldCacheTable(cMemMan_alloc(0xE8, D_00494E40, 0, 0), *(char**)self + 0x18);
    *(void***)((char*)self + 0x8) = (void**)operator_new_tag(*(int*)(*(char**)self + 0x8) * 4, D_00494E50, 0, 0);
    for (unsigned int i = 0; i < *(unsigned int*)(*(char**)self + 0x8); i++)
        (*(void***)((char*)self + 0x8))[i] = 0;
    char* x = (char*)func_003AAD98();
    *(char**)((char*)self + 0x3E8) = x;
    sVE_7FC0* vt = *(sVE_7FC0**)(x + 8);
    vt[2].fn(x + vt[2].delta, arg);
    if (func_003A6E98((char*)self + 0x300, name, self) == 0)
        return 0;
    int r = func_003A9000_p((char*)self + 0x10, *(void**)self, self);
    if (r == 0)
        return 0;
    func_003A82C8((func_003A82C8_sCache*)self);
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", cWorldCache_activateSectionMem);
#ifdef SKIP_ASM
extern char D_00494E60[];
extern "C" void* cWorldCacheTable_cWorldCacheTable(void* self, void* data);

extern "C" void cWorldCache_activateSectionMem(void* self, int i, int section)
{
    cWorldMemoryMan_activateSectionMem(*(void**)((char*)self + 0xC), i, section);
    // PORT: pointer held in int (index-first address arithmetic)
    void** slot = (void**)(i * 4 + *(int*)((char*)self + 0x8));
    *slot = cWorldCacheTable_cWorldCacheTable(cMemMan_alloc(0xE8, D_00494E60, 0, 0),
        *(char**)(*(char**)self + 0x14) + i * 0x58 + 0x20);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", func_003A8230);
#ifdef SKIP_ASM
extern "C" void func_003A7B98(void* self, int i);
extern "C" void func_003A7D80(int* self, int flags);

extern "C" void func_003A8230(void* self, int i)
{
    func_003A7B98(*(void**)((char*)self + 0xC), i);
    int* e = (*(int***)((char*)self + 0x8))[i];
    if (e != 0) {
        func_003A7D80(e, 3);
    }
    (*(int***)((char*)self + 0x8))[i] = 0;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8290);
#ifdef SKIP_ASM
extern "C" void func_003A9258(void* p);
extern "C" void cWorldCache_updatePages(void* self);
extern "C" void func_003A7098(void* p);

extern "C" void func_003A8290(void* self)
{
    func_003A9258((char*)self + 0x10);
    cWorldCache_updatePages(self);
    func_003A7098((char*)self + 0x300);
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A82C8);
#ifdef SKIP_ASM
int func_003A9AB0(void*);

struct func_003A82C8_sEntry {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

struct func_003A82C8_sCache {
    char pad[0x3EC];
    unsigned int count;   // 0x3EC
    func_003A82C8_sEntry entries[1]; // 0x3F0
};

extern "C" void func_003A82C8(func_003A82C8_sCache* self)
{
    unsigned int i;
    self->count = func_003A9AB0((char*)self + 0x10);
    for (i = 0; i < self->count; i++) {
        self->entries[i].a = 0;
        self->entries[i].b = 0;
        self->entries[i].c = 0;
        self->entries[i].e = 0;
        self->entries[i].f = 0;
        self->entries[i].d = 0;
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8330);
#ifdef SKIP_ASM
extern "C" void func_003A7010(void* p, int i);
extern "C" void func_003A8528(void* self, int i);

struct sWcEnt_8330 {
    int state;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
};

struct sWc_8330 {
    char pad[0x3EC];
    unsigned int count;         // 0x3EC
    sWcEnt_8330 ents[1];        // 0x3F0
};

extern "C" void func_003A8330(void* vself)
{
    sWc_8330* self = (sWc_8330*)vself;
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        switch (self->ents[i].state) {
        case 0:
        case 1:
            break;
        case 2:
            func_003A7010((char*)self + 0x300, i);
            self->ents[i].state = 4;
            func_003A8528(self, i);
            break;
        case 3:
        case 4:
            self->ents[i].state = 4;
            func_003A8528(self, i);
            break;
        }
        self->ents[i].state = 0;
        self->ents[i].f8 = 0;
        self->ents[i].f4 = 0;
        self->ents[i].f10 = 0;
        self->ents[i].f14 = 0;
        self->ents[i].fC = 0;
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8448);
#ifdef SKIP_ASM
struct sWCSlot {
    int state;   // 0x0
    int f4;      // 0x4
    int f8;      // 0x8
    float fC;    // 0xC
    int time;    // 0x10
    int f14;     // 0x14
};

struct sWCSlots {
    char pad[0x3F0];
    sWCSlot slot[256];   // 0x3F0
    int timeBase;        // 0x1BF0
};

extern char* D_004A5B64;

extern "C" void func_003A8448(sWCSlots* self, int i, float f)
{
    self->slot[i].time = *(int*)(D_004A5B64 + 0x1C);
    self->slot[i].fC = f;
    self->slot[i].f4 = 0;
    switch (self->slot[i].state) {
    case 0:
        self->slot[i].state = 1;
        break;
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        self->slot[i].state = 3;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A84C8);
#ifdef SKIP_ASM
extern char* D_004A5B64;

// PORT: callers declare (void*, unsigned short); the body never masks the id
extern "C" void func_003A84C8_i(sWCSlots* self, int i) __asm__("func_003A84C8");
extern "C" void func_003A84C8_i(sWCSlots* self, int i)
{
    self->slot[i].f4 = 0;
    self->slot[i].time = *(int*)(D_004A5B64 + 0x1C) - self->timeBase;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A84F8);
#ifdef SKIP_ASM
extern "C" void func_003A84F8(void* self, int a1, int a2)
{
    self = (char*)self + a1 * 0x18;
    *(int*)((char*)self + 0x3f4) = a2;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8510);
#ifdef SKIP_ASM
extern "C" int func_003A8510(int arg0, int arg1) {
    return (*(int *)((char*)(((arg1 * 0x18) + arg0)) + (0x3F4)));
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8528);
#ifdef SKIP_ASM
struct sHandle_8528 {
    unsigned int type : 8;
    unsigned int index : 24;
};
struct sRef_8528 {
    unsigned char kind;
    unsigned char type;
    unsigned short index;
};
struct sRefList_8528 {
    int f0;
    int f4;
    int count;          // 0x8
    sRef_8528* refs;    // 0xC
};
struct sCell_8528 {
    int loaded;             // 0x0
    int f4;
    sRefList_8528* list;    // 0x8
    int pad[3];
};
struct sCache_8528 {
    char pad[0x3F0];
    sCell_8528 cells[1];    // 0x3F0
};
extern "C" void func_003A8E20(void* self, int cell, int kind, sHandle_8528 h);
extern "C" void func_003A7C30(int* self, int flags);

// Unloads a cache cell: reports each referenced object (kind, handle) to func_003A8E20, then frees the list.
extern "C" void func_003A8528(void* vself, int cell)
{
    sCache_8528* self = (sCache_8528*)vself;
    sRefList_8528* list = self->cells[cell].list;
    sHandle_8528 h;
    *(unsigned int*)&h = 0xFFFFFFFF;  // starts as the invalid handle
    for (int i = list->count - 1; i >= 0; i--) {
        h.type = list->refs[i].type;
        h.index = list->refs[i].index;
        func_003A8E20(self, cell, list->refs[i].kind, h);
    }
    if (self->cells[cell].list != 0)
        func_003A7C30((int*)self->cells[cell].list, 3);
    self->cells[cell].list = 0;
    self->cells[cell].loaded = 0;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8618);
#ifdef SKIP_ASM
extern "C" int func_003A8618(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x18;
    return *(int*)(p + 0x3f0) == 3;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8638);
#ifdef SKIP_ASM
extern "C" int func_003A8638(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x18;
    return *(int*)(p + 0x3f0) == 0;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8650);
#ifdef SKIP_ASM
extern "C" void func_003A8650(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x18;
    *(int*)(p + 0x3f0) = 3;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", cWorldCache_updatePages);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cHullPage_cHullPage(void* self, unsigned short* data);
extern "C" void* func_003A9A98(void* self, int i);
extern "C" int func_003A6F88(void* self, int i, int a, int b);
extern "C" void func_003A8528(void* self, int i);
extern char* D_004A5B64;
extern char* D_004A5B80;
extern char D_00494E88[];

// PORT: g++ 2.95 new-expression; the ctor and the tagged allocator are bound to their symbols by asm label.
struct sHullPage_8668 {
    char data[0x10];
    sHullPage_8668(unsigned short* d) __asm__("cHullPage_cHullPage");
    void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
};

struct sWCPSlot_8668 {
    int state;   // 0x0
    int locked;  // 0x4
    sHullPage_8668* page;  // 0x8
    float pri;   // 0xC
    int time;    // 0x10
    int stamp;   // 0x14
};

struct sWCPCache_8668 {
    char pad0[0x390];
    int busy;                   // 0x390
    char pad394[0x3EC - 0x394];
    unsigned int count;         // 0x3EC
    sWCPSlot_8668 slot[256];    // 0x3F0
    int timeBase;               // 0x1BF0
};

struct sVE_8668 { short delta; short index; int (*fn)(void*); };

static inline int Frame_8668()
{
    char* o = D_004A5B80;
    sVE_8668* vt = *(sVE_8668**)(o + 0x10D8);
    return vt[114].fn(o + vt[114].delta);
}

extern "C" void cWorldCache_updatePages(void* p)
{
    sWCPCache_8668* self = (sWCPCache_8668*)p;
    int now = *(int*)(D_004A5B64 + 0x1C);
    int best = -1;
    float bestPri = -1.0f;
    for (unsigned int i = 0; i < self->count; i++)
    {
        int st = self->slot[i].state;
        if (st == 0)
            continue;
        int expired = 0;
        if (self->slot[i].locked == 0 && now - self->slot[i].time >= self->timeBase)
            expired = 1;
        switch (st)
        {
        case 2:
            break;
        case 1:
            if (expired)
            {
                self->slot[i].state = 0;
                break;
            }
            if (self->slot[i].pri > bestPri)
            {
                bestPri = self->slot[i].pri;
                best = i;
            }
            break;
        case 3:
            if (!expired)
                break;
            self->slot[i].state = 4;
            self->slot[i].stamp = Frame_8668();
            break;
        case 4:
            if (Frame_8668() - self->slot[i].stamp < 5)
                break;
            func_003A8528(self, i);
            self->slot[i].state = 0;
            break;
        }
    }
    if (best < 0)
        return;
    void* mgr = (char*)self + 0x300;
    if (self->busy != 0)
        return;
    unsigned short* data = (unsigned short*)func_003A9A98((char*)self + 0x10, best);
    self->slot[best].page = new (D_00494E88, 0x20000000, 0) sHullPage_8668(data);
    func_003A6F88(mgr, best, data[0], *(int*)(data + 2));
    self->slot[best].state = 2;
}
#endif

INCLUDE_ASM("world/worldcache", func_003A88A8);

//100%
INCLUDE_ASM("world/worldcache", func_003A89C8);
#ifdef SKIP_ASM
struct sWcEnt_89C8 {
    int state;
    int f4;
    int f8;
    float fC;
    int f10;
    int f14;
};

struct sWc_89C8 {
    char pad[0x3EC];
    unsigned int count;         // 0x3EC
    sWcEnt_89C8 ents[1];        // 0x3F0
};

extern "C" void func_003A8528(void* self, int i);

extern "C" void func_003A89C8(void* vself)
{
    sWc_89C8* self = (sWc_89C8*)vself;
    int best = -1;
    float bestPri = 1.0f;
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        int st = self->ents[i].state;
        if (st == 0)
            continue;
        if (st <= 0)
            continue;
        if (st < 3)
            continue;
        if (st >= 5)
            continue;
        if (self->ents[i].f4 != 0)
            continue;
        if (self->ents[i].fC < bestPri) {
            bestPri = self->ents[i].fC;
            best = i;
        }
    }
    if (best >= 0) {
        self->ents[best].state = 4;
        func_003A8528(self, best);
        self->ents[best].state = 0;
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", cWorldCache_addBxStreamDataTest);
#ifdef SKIP_ASM
struct sWCPool_7878;
extern "C" char* func_003A7878(sWCPool_7878* self, int size, unsigned int flags);
// PORT: operator_new__FUi really takes (size, tag, flags, d), like cMemMan_alloc.
void* operator_new_bx(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00494D40[];
extern char D_00494E98[];

struct sBxRef_8AA8 {
    unsigned char refs;
    unsigned char pad;
    unsigned short pad2;
};
struct sBxTypeTbl_8AA8 {
    sBxRef_8AA8* refs;
    int count;
};
struct sBxBank_8AA8 {
    int f0;
    sBxTypeTbl_8AA8 types[1];       // 0x4
};
struct sBxItem_8AA8 {
    unsigned char type;
    unsigned char bank;
    unsigned short id;
};
struct sBxList_8AA8 {
    char pad0[0x8];
    int count;                      // 0x8
    sBxItem_8AA8* items;            // 0xC
};
struct sBxSlot_8AA8 {
    sBxList_8AA8* list;
    char pad4[0x14];
};
struct sBxPools_8AA8 {
    char pad0[0x3C];
    sWCPool_7878* pools[1];         // 0x3C
};
struct sWorldCache_8AA8 {
    int f0;
    sBxBank_8AA8* global;           // 0x4
    sBxBank_8AA8** banks;           // 0x8
    sBxPools_8AA8* pools;           // 0xC
    char pad10[0x3E8];
    sBxSlot_8AA8 slots[1];          // 0x3F8
};

static inline void* bxAlloc_8AA8(sBxPools_8AA8* pl, int bank, int size, unsigned int flags)
{
    if (bank == 0xFF)
        return operator_new_bx(size, D_00494D40, flags, 0);
    return func_003A7878(pl->pools[bank], size, flags);
}

static inline int addRef_8AA8(sBxRef_8AA8* r)
{
    if (r->refs != 0) {
        r->refs++;
        return 1;
    }
    r->refs++;
    return 0;
}

static inline void release_8AA8(sBxRef_8AA8* r)
{
    if (--r->refs == 0)
        *(unsigned int*)r = r->refs;
}

// Adds one stream data item (type, bank|id<<8) to a load list, allocating its storage on first use.
extern "C" unsigned int cWorldCache_addBxStreamDataTest(sWorldCache_8AA8* self, int slot, int type, unsigned int key, int size)
{
    int bank = key & 0xFF;
    unsigned int id = key >> 8;
    sBxBank_8AA8* b;
    if (bank == 0xFF)
        b = self->global;
    else
        b = self->banks[bank];
    if (addRef_8AA8(&b->types[type].refs[id])) {
        sBxList_8AA8* l = self->slots[slot].list;
        l->items[l->count].type = type;
        l->items[l->count].bank = key;
        l->items[l->count].id = key >> 8;
        l->count++;
        return 0;
    }
    if (size == 0)
        return 0;
    void* p;
    switch (type) {
    case 9:
    case 10:
        p = bxAlloc_8AA8(self->pools, bank, size, 0x45000000);
        break;
    case 1:
    case 2:
    case 3:
    case 11:
    case 12:
        p = bxAlloc_8AA8(self->pools, bank, size, 0x22000000);
        break;
    case 14:
        p = operator_new_bx(size, D_00494E98, 0, 0);
        break;
    default:
        p = bxAlloc_8AA8(self->pools, bank, size, 0);
        break;
    }
    if (p != 0)
        return (unsigned int)p;
    release_8AA8(&b->types[type].refs[id]);
    return 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8CD0);
#ifdef SKIP_ASM
struct sWCEntry8CD0 {
    unsigned char id;           // 0x0
    unsigned char lo;           // 0x1
    unsigned short hi;          // 0x2
};

struct sWCList8CD0 {
    int f0;
    int f4;
    int count;                  // 0x8
    sWCEntry8CD0* entries;      // 0xC
};

struct sWCGroup8CD0 {
    sWCList8CD0* list;          // 0x0
    char pad4[0x14];
};

struct sWCVt8CD0 {
    short delta;
    short index;
    int (*fn)(void*, int, unsigned int, int);
};

struct sWCObj8CD0 {
    int f0;
    int f4;
    sWCVt8CD0* vt;              // 0x8
};

struct sWCSlot8CD0 {
    int f0;
    int* bits;                  // 0x4
};

struct sWorldCache8CD0 {
    int f0;
    sWCSlot8CD0* deflt;         // 0x4
    sWCSlot8CD0** tables;       // 0x8
    char padC[0x3E8 - 0xC];
    sWCObj8CD0* obj;            // 0x3E8
    char pad3EC[0xC];
    sWCGroup8CD0 groups[1];     // 0x3F8
};

extern int D_004A47D0;

// PORT: a4 is a pointer carried in an int (compared against &D_004A47D0, then shifted).
extern "C" void func_003A8CD0(sWorldCache8CD0* self, int group, int id, unsigned int key, int a4)
{
    sWCSlot8CD0* tbl;
    sWCList8CD0* list;
    unsigned int hi = key >> 8;
    if ((key & 0xFF) == 0xFF) {
        tbl = self->deflt;
    } else {
        tbl = self->tables[key & 0xFF];
    }
    list = self->groups[group].list;
    list->entries[list->count].id = id;
    list->entries[list->count].lo = key;
    list->entries[list->count].hi = key >> 8;
    list->count++;
    if (a4 == (int)&D_004A47D0) {
        sWCObj8CD0* o = self->obj;
        o->vt[3].fn((char*)o + o->vt[3].delta, id, key, 0);
    } else {
        sWCObj8CD0* o = self->obj;
        a4 = o->vt[3].fn((char*)o + o->vt[3].delta, id, key, a4);
    }
    {
        sWCSlot8CD0* e = &tbl[id];
        e->bits[hi] = (unsigned char)e->bits[hi] | ((a4 >> 2) << 8);
    }
}
#endif

INCLUDE_ASM("world/worldcache", func_003A8E20);

//100%
INCLUDE_ASM("world/worldcache", func_003A8F10);
#ifdef SKIP_ASM
static inline char *refToPtr_8F10(unsigned i) { return (char*)(i << 2); }
static inline char *conv_8F10(unsigned i) { if (i == 0) return 0; return refToPtr_8F10(i); }
// Sets flag 0x40 on every object listed for cell idx.
extern "C" void func_003A8F10(char** self, int idx)
{
    int n = *(short*)(*(char**)(self[0] + 0x14) + idx * 0x58 + 0x22);
    char* list = ((char**)self[2])[idx];
    for (unsigned i = 0; i < n; i++) {
        char* o = conv_8F10(((unsigned*)*(char**)(list + 0xC))[i] >> 8);
        *(unsigned short*)(o + 0xA) |= 0x40;
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8F80);
#ifdef SKIP_ASM
inline void* operator new[](unsigned int, void* p) { return p; }
// The cache's leading two-entry member array has an empty constructor; the
// vec_mark compiler leaves only its dead loop setup behind.
struct sCacheHead_3A8F80 {
    int v;
    sCacheHead_3A8F80() {}
};
extern "C" void func_003A9188_8F80(void* self) __asm__("func_003A9188");

// PORT: the unit declares this as void(void*); defined under an asm label with its real type
extern "C" void* func_003A8F80(void* self);
extern "C" void* func_003A8F80(void* self)
{
    new (self) sCacheHead_3A8F80[2];
    func_003A9188_8F80(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A8FB8);
#ifdef SKIP_ASM
void operator_delete(int*);
void func_003A9180(void* self);

extern "C" void func_003A8FB8(void* self, int flags)
{
    func_003A9180(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A9000);
#ifdef SKIP_ASM
struct sWCQuad {
    float v[4];
} __attribute__((aligned(16)));

struct sWCNode {
    sWCQuad min;
    sWCQuad max;
    char pad20[0x30];
    int left;
    int right;
    int leaf;
    char pad5C[4];
};

struct sWCLeaf {
    char pad00[0x44];
};

struct sWCSect {
    char pad00[0x1C];
    int node;
    char pad20[0x38];
};

struct sWCHdr {
    char pad00[8];
    unsigned int numSects;
    unsigned int numNodes;
    char pad10[0x40];
};

struct sWCPair {
    int a;
    int b;
};

struct sWorldCacheMap {
    int id;
    sWCHdr* hdr;
    sWCSect* sects;
    sWCNode* nodes;
    sWCLeaf* leaves;
    sWCPair pairs[65];
    char pad21C[4];
    sWCQuad min;
    sWCQuad max;
};

// PORT: offsets in the loaded data are rewritten in place as pointers (pointer in int)
extern "C" int func_003A9000(sWorldCacheMap* self, sWCHdr* hdr, int id)
{
    unsigned int i;

    char* p;
    self->id = id;
    self->hdr = hdr;
    self->sects = (sWCSect*)((char*)hdr + 0x50);
    p = (char*)self->sects + hdr->numSects * 0x58;
    p = (char*)(((unsigned int)p + 0xF) & 0xFFFFFFF0);
    self->nodes = (sWCNode*)p;
    self->leaves = (sWCLeaf*)(p + hdr->numNodes * 0x60);

    for (i = 0; i < self->hdr->numSects; i++) {
        self->sects[i].node = (int)&self->nodes[self->sects[i].node];
        self->pairs[i].a = 0;
        self->pairs[i].b = 0;
    }

    for (i = 0; i < self->hdr->numNodes; i++) {
        if (self->nodes[i].left >= 0) {
            self->nodes[i].left = (int)&self->nodes[self->nodes[i].left];
        } else {
            self->nodes[i].left = 0;
        }
        if (self->nodes[i].right >= 0) {
            self->nodes[i].right = (int)&self->nodes[self->nodes[i].right];
        } else {
            self->nodes[i].right = 0;
        }
        if (self->nodes[i].leaf >= 0) {
            self->nodes[i].leaf = (int)&self->leaves[self->nodes[i].leaf];
        } else {
            self->nodes[i].leaf = 0;
        }
    }

    self->min = ((sWCNode*)self->sects[0].node)->min;
    self->max = ((sWCNode*)self->sects[0].node)->max;
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A9180__FPv);
#ifdef SKIP_ASM
void func_003A9180(void* self)
{
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A9188);
#ifdef SKIP_ASM
struct func_003A9188_sVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
extern func_003A9188_sVec4 D_004FF130;

extern "C" void func_003A9658(void* self, unsigned int i, func_003A9188_sVec4* v, float f);

struct func_003A9188_sPair {
    int a;
    int b;
};

struct func_003A9188_sSlot {
    int f0;
    char pad[0x4C];
};

struct func_003A9188_sCache {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    func_003A9188_sPair pairs[64];
    char pad214[0x220 - 0x214];
    func_003A9188_sVec4 v220;
    func_003A9188_sVec4 v230;
    func_003A9188_sSlot slots[2];
    int f2E0;
    int f2E4;
};

extern "C" void func_003A9188(func_003A9188_sCache* self)
{
    unsigned int i;
    self->f0 = 0;
    self->f4 = 0;
    self->f8 = 0;
    self->fC = 0;
    self->f10 = 0;
    self->v220 = D_004FF130;
    self->v230 = D_004FF130;
    for (i = 0; i < 64; i++) {
        self->pairs[i].a = 0;
        self->pairs[i].b = 0;
    }
    for (i = 0; i < 2; i++) {
        self->slots[i].f0 = 0;
        func_003A9658(self, i, &D_004FF130, 0.0f);
    }
    self->f2E0 = 0;
    self->f2E4 = 0;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A9258);
#ifdef SKIP_ASM
extern "C" int func_00416B18(const char* a, const char* b, int n);
struct func_003A9558_sNode;
extern "C" void func_003A9558(void** self, func_003A9558_sNode* node);
extern "C" void func_003A95C0(void** self, void* node, int* ok);
extern "C" void func_003AD1A8();
extern "C" void func_003A9D60(void* self, int i);
extern char D_004A47E8[];
extern char D_004A47F0[];
extern char D_004A47F8[];
extern char D_004A4800[];
extern char D_004A4808[];

struct sWCSection_9258 {
    char name[0x18];
    int id;             // 0x18
    void* tree;         // 0x1C
    char pad20[0x58 - 0x20];
};

struct sWCInfo_9258 {
    int f0;
    int f4;
    unsigned int count; // 0x8
};

struct sWCEntry_9258 {
    int state;
    float pri;
};

struct sWCLoader_9258 {
    void* cache;                // 0x0
    sWCInfo_9258* info;         // 0x4
    sWCSection_9258* sections;  // 0x8
    int fC;
    int f10;
    sWCEntry_9258 entries[64];  // 0x14
    char pad214[0x2E0 - 0x214];
    int f2E0;                   // 0x2E0
    int f2E4;                   // 0x2E4
};

struct sVE_9258 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_003A9258(void* p)
{
    sWCLoader_9258* self = (sWCLoader_9258*)p;
    if (self->info == 0)
        return;
    self->f2E0 = 0;
    self->f2E4 = 0;
    for (unsigned int i = 0; i < self->info->count; i++) {
        switch (self->entries[i].state) {
        case 0:
            break;
        case 1:
            if (func_00416B18(self->sections[i].name, D_004A47E8, 4) == 0
                || func_00416B18(self->sections[i].name, D_004A47F0, 4) == 0
                || func_00416B18(self->sections[i].name, D_004A47F8, 4) == 0
                || func_00416B18(self->sections[i].name, D_004A4800, 4) == 0
                || func_00416B18(self->sections[i].name, D_004A4808, 4) == 0)
                cWorldCache_activateSectionMem(self->cache, i, 0);
            else
                cWorldCache_activateSectionMem(self->cache, i, 2);
            func_003A8448((sWCSlots*)self->cache, self->sections[i].id, self->entries[i].pri);
            func_003A84F8(self->cache, self->sections[i].id, 1);
            self->entries[i].state = 2;
            break;
        case 2:
            if (func_003A8618(self->cache, self->sections[i].id)) {
                self->entries[i].state = 5;
                char* o = D_004A5B80;
                sVE_9258* vt = *(sVE_9258**)(o + 0x10D8);
                vt[102].fn(o + vt[102].delta, i);
            }
            break;
        case 4:
            if (func_003A8638(self->cache, self->sections[i].id)) {
                int ok = 1;
                func_003A95C0((void**)self, self->sections[i].tree, &ok);
                if (ok) {
                    self->entries[i].state = 0;
                    func_003A8230(self->cache, i);
                    func_003AD1A8();
                }
            }
            break;
        case 5:
            self->f2E0++;
            break;
        case 6:
            self->f2E0++;
            self->f2E4++;
            break;
        case 3:
            func_003A84C8_i((sWCSlots*)self->cache, self->sections[i].id);
            func_003A9558((void**)self, (func_003A9558_sNode*)self->sections[i].tree);
            self->entries[i].state = 4;
            break;
        }
    }
    for (int j = 0; j < 2; j++)
        func_003A9D60(self, j);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", func_003A9558);
#ifdef SKIP_ASM
extern "C" void func_003A84C8(void* cache, unsigned short id);

struct func_003A9558_sNode {
    char pad_0x00[0x50];
    func_003A9558_sNode* left;   // 0x50
    func_003A9558_sNode* right;  // 0x54
    unsigned short* section;     // 0x58
};

extern "C" void func_003A9558(void** self, func_003A9558_sNode* node)
{
    if (node->section != 0) {
        func_003A84C8(*self, node->section[1]);
    }
    if (node->left != 0) {
        func_003A9558(self, node->left);
    }
    if (node->right != 0) {
        func_003A9558(self, node->right);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldcache", func_003A95C0);
#ifdef SKIP_ASM
extern "C" int func_003A8638(void* self, int a1);

extern "C" void func_003A95C0(void** self, void* node, int* ok)
{
    if (*ok != 0) {
        void* d = *(void**)((char*)node + 0x58);
        if (d != 0 && func_003A8638(*self, *(unsigned short*)((char*)d + 2)) == 0) {
            *ok = 0;
            return;
        }
        if (*(void**)((char*)node + 0x50) != 0) {
            func_003A95C0(self, *(void**)((char*)node + 0x50), ok);
        }
        if (*(void**)((char*)node + 0x54) != 0 && *ok != 0) {
            func_003A95C0(self, *(void**)((char*)node + 0x54), ok);
        }
    }
}
#endif

INCLUDE_ASM("world/worldcache", func_003A9658);

//100%
INCLUDE_ASM("world/worldcache", func_003A96E0);
#ifdef SKIP_ASM
extern "C" void func_003A9D60(void* self, int i);

extern "C" int func_003A96E0(void* self, int i, sWCQuad* outPos, float* outT)
{
    char* e = (char*)self + i * 0x50;
    if (*(int*)(e + 0x240) == 0) {
        return 0;
    }
    func_003A9D60(self, i);
    int r = 1;
    *outPos = *(sWCQuad*)(e + 0x250);
    float t = *(float*)(e + 0x284) - 0.5f;
    *outT = t;
    if (!(t > 0.0f)) {
        r = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("world/worldcache", func_003A9770);
#ifdef SKIP_ASM
extern "C" void func_003A9D60(void* self, int i);

extern "C" int func_003A9770(void* self, int i, sWCQuad* outPos, float* outT)
{
    char* e = (char*)self + i * 0x50;
    if (*(int*)(e + 0x240) == 0) {
        return 0;
    }
    func_003A9D60(self, i);
    int r = 1;
    *outPos = *(sWCQuad*)(e + 0x250);
    float t = *(float*)(e + 0x288) - 0.5f;
    *outT = t;
    if (!(t > 0.0f)) {
        r = 0;
    }
    return r;
}
#endif

