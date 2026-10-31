#include "common.h"

//100%
INCLUDE_ASM("world/world", cWorld_cWorld);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_003A7DD0(void* mem);
extern "C" void* func_003AC7C8(void* mem, void* world);
extern "C" void* func_002BB130(void* mem);
extern "C" void func_0032DC10(int a, int b, int c, int d);
extern char D_00494D58[];
extern char D_00494D68[];
extern char D_00494D78[];
// The unit declares D_004A47B8 as int (later); this view stores the world pointer.
extern void* D_world_4A47B8 __asm__("D_004A47B8");

extern "C" void* cWorld_cWorld(void** self)
{
    D_world_4A47B8 = self;
    self[0] = func_003A7DD0(cMemMan_alloc(0x1C00, D_00494D58, 0, 0));
    self[1] = func_003AC7C8(cMemMan_alloc(0x10, D_00494D68, 0, 0), self);
    self[2] = func_002BB130(cMemMan_alloc(8, D_00494D78, 0, 0));
    self[4] = 0;
    self[5] = 0;
    func_0032DC10(0xA, 4, 2, 5);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6740);
#ifdef SKIP_ASM
struct sWorldVEntry0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern char* D_004A5B80;
extern int D_004A47B8;
extern "C" void func_003A7E38(int* self, int flags);
extern "C" void func_003AC8F0(void* self, int flags);
extern "C" void func_002BB140(void* self, int flags);
extern "C" void func_0032DE20(void);
void operator_delete(int* p);

extern "C" void func_003A6740(void** self, int flags)
{
    char* obj = D_004A5B80;
    sWorldVEntry0* e = &(*(sWorldVEntry0**)(obj + 0x10D8))[107];
    e->fn(obj + e->delta);
    if (self[0] != 0) {
        func_003A7E38((int*)self[0], 3);
    }
    if (self[1] != 0) {
        func_003AC8F0(self[1], 3);
    }
    if (self[2] != 0) {
        func_002BB140(self[2], 3);
    }
    func_0032DE20();
    D_004A47B8 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void cWorld_resetMap(void*);

//100%
INCLUDE_ASM("world/world", func_003A67E0);
#ifdef SKIP_ASM
extern "C" void func_003A67E0(void* self)
{
    cWorld_resetMap(self);
}
#endif

//100%
INCLUDE_ASM("world/world", cWorld_resetMap);
#ifdef SKIP_ASM
struct cWorldView;
int cWorldView_getNumSections(cWorldView* view);
int cWorldView_isSectionLoaded(cWorldView* view, int i);

struct sWRMEntry {
    unsigned int lo : 8;
    unsigned int ptr : 24;
};

struct sWRMTable {
    char pad00[0x1C];
    sWRMEntry* entries;
};

struct sWRMObj {
    int f0;
    int f4;
    int f8;
};

struct sWRMSection {
    char pad00[0x26];
    short count;
    char pad28[0x30];
};

struct sWRMMap {
    char pad00[0x14];
    sWRMSection* sections;
};

struct sWRMWorld {
    sWRMMap* map;
    int f04;
    sWRMTable** tables;
    int f0C;
    char view[4];
};

static inline sWRMObj* sWRM_toPtr(unsigned int p)
{
    return (sWRMObj*)(p << 2);
}

static inline sWRMObj* sWRM_lookup(sWRMTable* t, unsigned int idx)
{
    unsigned int p = t->entries[idx].ptr;
    if (p == 0) return 0;
    return sWRM_toPtr(p);
}

static inline sWRMObj* sWRM_get(sWRMWorld* w, unsigned int id)
{
    sWRMTable* t = w->tables[id & 0xFF];
    if (t == 0) return 0;
    return sWRM_lookup(t, id >> 8);
}

extern "C" void cWorld_resetMap(void* selfp)
{
    sWRMWorld** self = (sWRMWorld**)selfp;
    unsigned int ref = 0xFFFFFFFF;
    unsigned int i;
    for (i = 0; i < (unsigned int)cWorldView_getNumSections((cWorldView*)(*self)->view); i++) {
        if (cWorldView_isSectionLoaded((cWorldView*)(*self)->view, i)) {
            int n = (*self)->map->sections[i].count;
            unsigned int s = i & 0xFF;
            ref = (int)ref & ~0xFF;
            ref |= s;
            int j;
            for (j = 0; j < n; j++) {
                ref = (ref & 0xFF) | (j << 8);
                sWRMObj* o = sWRM_get(*self, ref);
                if (o) {
                    int v = o->f8 & 0xFFFF0000;
                    o->f8 = v | (v >> 16) | 2;
                }
            }
        }
    }
}
#endif

extern "C" void func_003A8290(int);

//100%
INCLUDE_ASM("world/world", func_003A6928__FPv);
#ifdef SKIP_ASM
void func_003A6928(void* self)
{
    func_003A8290(*(int*)self);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6948);
#ifdef SKIP_ASM
struct cBXString;
extern "C" void* cBXString_cBXString2(void* self, const char* str);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" cBXString* func_00318630(cBXString* self, cBXString* a, const char* str);
extern "C" cBXString* func_003186D0(cBXString* self, const char* str, cBXString* b);
extern "C" void func_00318D28(cBXString* self);
extern "C" void* func_003E1908(const char* name, int flags);
extern "C" int func_004165A8(const void* a, const void* b);
void cMemMan_free(void*);
extern char D_004A47C0[];
extern char D_004A47C8[];

struct sName_3A6948 {
    char* name;
    int ok;
};

struct sEntry_3A6948 {
    char name[0x58];
};

struct sFile_3A6948 {
    unsigned short magic;       // 0x00
    char pad_2[6];
    unsigned int count;         // 0x08
    char pad_c[8];
    sEntry_3A6948* entries;     // 0x14
};

struct sStr_3A6948 {
    char* s;
    sStr_3A6948() {}
    sStr_3A6948(const sStr_3A6948&);
};

extern "C" int func_003A6948(const char* path, int n, sName_3A6948* names)
{
    sFile_3A6948* data;
    int ret;
    {
        sStr_3A6948 full;
        sStr_3A6948 tmp;
        sStr_3A6948 str;
        char* pre = D_004A47C0;
        cBXString* t = (cBXString*)&tmp;
        cBXString_cBXString2(&str, path);
        func_003186D0(t, pre, (cBXString*)&str);
        func_00318630((cBXString*)&full, t, D_004A47C8);
        data = (sFile_3A6948*)func_003E1908(full.s, 0x3000000);
        cBXString__cBXString(&full, 2);
        cBXString__cBXString(t, 2);
        cBXString__cBXString(&str, 2);
    }
    ret = data && data->magic == 0x3800;
    if (ret)
    {
        int i;
        data->entries = (sEntry_3A6948*)((char*)data + 0x50);
        ret = 0;
        for (i = 0; i < n; i++)
        {
            sStr_3A6948 s;
            unsigned int j;
            names[i].ok = 0;
            cBXString_cBXString2(&s, names[i].name);
            func_00318D28((cBXString*)&s);
            for (j = 0; j < data->count; j++)
            {
                if (func_004165A8(&data->entries[j], s.s) == 0)
                {
                    names[i].ok = ret = 1;
                    break;
                }
            }
            cBXString__cBXString(&s, 2);
        }
    }
    if (data)
        cMemMan_free(data);
    return ret;
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6AE0);
#ifdef SKIP_ASM
struct cWorldView;
extern "C" void* cBXString_cBXString2(void* self, const char* str);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void func_003A7F90(void* cache);
extern "C" int cWorldCache_init(void* cache, const char* name, int a2);
int cWorldView_getNumSections(cWorldView* view);
extern "C" void cWScriptCache_init(void* cache, int n);
extern "C" void func_002BB1D0(void* p, int n);

struct func_003A6AE0_sBXString {
    char* str;
};

extern "C" void func_003A6AE0(void** self, const char* name, int a2)
{
    func_003A6AE0_sBXString s;
    cBXString_cBXString2(&s, name);
    func_003A7F90(self[0]);
    cWorldCache_init(self[0], name, a2);
    cWScriptCache_init(self[1], cWorldView_getNumSections((cWorldView*)((char*)self[0] + 0x10)));
    func_002BB1D0(self[2], cWorldView_getNumSections((cWorldView*)((char*)self[0] + 0x10)));
    cBXString__cBXString(&s, 2);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6B78);
#ifdef SKIP_ASM
struct func_003A6B78_sEntry {
    short type;
    char pad2[6];
    void* data;
};

struct func_003A6B78_sTable {
    char pad[4];
    func_003A6B78_sEntry* entries;
};

extern "C" int func_003AD120(func_003A6B78_sEntry* e, void* obj, int i);

extern "C" int func_003A6B78(void* self, void* obj, int i)
{
    return func_003AD120(&(*(func_003A6B78_sTable**)((char*)self + 0x4))->entries[*(unsigned char*)((char*)obj + 0x78)], obj, i);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6BA8);
#ifdef SKIP_ASM
struct func_003A6BA8_sEntry {
    short type;
    char pad2[6];
    void* data;
};

struct func_003A6BA8_sTable {
    char pad[4];
    func_003A6BA8_sEntry* entries;
};

extern "C" int func_003ADC80(func_003A6BA8_sEntry* e);

extern "C" int func_003A6BA8(void* self, int i)
{
    return func_003ADC80(&(*(func_003A6BA8_sTable**)((char*)self + 0x4))->entries[i]);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6BD8);
#ifdef SKIP_ASM
extern "C" int func_003ADCB0(func_003A6BA8_sEntry* e);

extern "C" int func_003A6BD8(void* self, int i)
{
    return func_003ADCB0(&(*(func_003A6BA8_sTable**)((char*)self + 0x4))->entries[i]);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6C08);
#ifdef SKIP_ASM
extern "C" int func_003ADCE0(func_003A6BA8_sEntry* e);

extern "C" int func_003A6C08(void* self, int i)
{
    return func_003ADCE0(&(*(func_003A6BA8_sTable**)((char*)self + 0x4))->entries[i]);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6C38);
#ifdef SKIP_ASM
extern "C" int func_003ADD10(func_003A6BA8_sEntry* e);

extern "C" int func_003A6C38(void* self, int i)
{
    return func_003ADD10(&(*(func_003A6BA8_sTable**)((char*)self + 0x4))->entries[i]);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6C68);
#ifdef SKIP_ASM
extern "C" int func_003ADD40(func_003A6BA8_sEntry* e);

extern "C" int func_003A6C68(void* self, int i)
{
    return func_003ADD40(&(*(func_003A6BA8_sTable**)((char*)self + 0x4))->entries[i]);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6C98);
#ifdef SKIP_ASM
extern "C" int func_003ADD70(func_003A6BA8_sEntry* e);

extern "C" int func_003A6C98(void* self, int i)
{
    return func_003ADD70(&(*(func_003A6BA8_sTable**)((char*)self + 0x4))->entries[i]);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6CC8__FPvT0);
#ifdef SKIP_ASM
int func_003A6CC8(void* self, void* a1)
{
    return *(int*)((char*)*(void**)((char*)*(void**)((char*)a1 + 0x88) + 0xc) + 0x8);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6CD8__FPvT0);
#ifdef SKIP_ASM
int func_003A6CD8(void* self, void* a1)
{
    return *(int*)((char*)*(void**)((char*)*(void**)((char*)a1 + 0x88) + 0xc) + 0x8);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6CE8);
#ifdef SKIP_ASM
extern "C" void* func_003A6CE8(void* self, int a1)
{
    return (char*)(*(void**)self) + a1 * 0x140;
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6D00__FPvi);
#ifdef SKIP_ASM
int func_003A6D00(void* self, int a1)
{
    return *(int*)((char*)*(void**)self + a1 * 4);
}
#endif

//100%
INCLUDE_ASM("world/world", func_003A6D18);
#ifdef SKIP_ASM
extern "C" int func_003ADC50(func_003A6BA8_sEntry* e, unsigned int i);

extern "C" int func_003A6D18(void* self, unsigned int* handle)
{
    unsigned int h = *handle;
    return func_003ADC50(&(*(func_003A6BA8_sTable**)((char*)self + 0x4))->entries[h & 0xFF], h >> 8);
}
#endif

