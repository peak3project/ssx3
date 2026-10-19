#include "common.h"

//100%
INCLUDE_ASM("animation/mdfarchive", cMdfArchive_getModelPartByIndex);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_003B47F8(void* src, void* dst);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_0048A5D0[];

struct sMdfPart_00314CB0
{
    char name[0x10];
    int dataOffset;
    int dataSize;
    char pad_0x18[0x48];
};

struct sMdfArchive_00314CB0
{
    int f0;
    int f4;
    sMdfPart_00314CB0* parts;
    char* data;
};

extern "C" void* cMdfArchive_getModelPartByIndex(sMdfArchive_00314CB0* self, int i)
{
    char name[0x40];
    sprintf(name, D_0048A5D0, &self->parts[i]);
    char* p = (char*)operator_new_tag(self->parts[i].dataSize + 0x60, name, 0x3000000, 0);
    func_003E6574(p, &self->parts[i], 0x60);
    if (self->parts[i].dataSize)
    {
        func_003B47F8(self->data + self->parts[i].dataOffset, p + 0x60);
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("animation/mdfarchive", func_00314D60);
#ifdef SKIP_ASM
extern unsigned int* D_004A3E78;

extern "C" int func_00314D60(int* a, int* b)
{
    return D_004A3E78[*a] < D_004A3E78[*b] ? -1 : 1;
}
#endif

//100%
INCLUDE_ASM("animation/mdfarchive", func_00314D98);
#ifdef SKIP_ASM
inline void* operator new[](unsigned int, void* p) { return p; }
// 0x206-entry member array with an empty constructor (only the dead loop setup remains).
struct sMdfEntry_314D98 {
    int v;
    sMdfEntry_314D98() {}
};
extern void* D_004A3E7C;

extern "C" void* func_00314D98(void* self)
{
    new (self) sMdfEntry_314D98[0x206];
    D_004A3E7C = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("animation/mdfarchive", func_00314DB0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_004A3E7C;

extern "C" void func_00314DB0(void* self, int flags)
{
    D_004A3E7C = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("animation/mdfarchive", func_00314DD8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char* D_0048CFC0[];
extern unsigned int* D_004A3E78;
extern "C" int func_00314D60(int* a, int* b);
extern "C" void func_00418EF8(void* base, int n, int size, int (*cmp)(int*, int*));
extern "C" void* func_00416210(void* dst, int c, int n);

struct sMdfHashTable_00314DD8
{
    unsigned int hash[0x206];
    int order[0x206];
    char map[0x818];
};

extern "C" void func_00314DD8(sMdfHashTable_00314DD8* self)
{
    for (int i = 0; i < 0x206; i++)
    {
        int h = GetHashValue32(D_0048CFC0[i]);
        self->order[i] = i;
        self->hash[i] = h;
    }
    D_004A3E78 = self->hash;
    func_00418EF8(self->order, 0x206, 4, func_00314D60);
    D_004A3E78 = 0;
    func_00416210(self->map, -1, 0x818);
}
#endif

//100%
INCLUDE_ASM("animation/mdfarchive", func_00314E88);
#ifdef SKIP_ASM
struct sMdfIndex_00314E88
{
    unsigned int hashes[0x206]; // 0x000: sorted by order[]
    int order[0x206];           // 0x818
};

// Binary search for `hash`; returns its entry index, or -1.
extern "C" int func_00314E88(sMdfIndex_00314E88* self, unsigned int hash)
{
    int lo = 0;
    int hi = 0x206;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        int idx = self->order[mid];
        unsigned int h = self->hashes[idx];
        if (hash == h)
        {
            return idx;
        }
        if (hash < h)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/mdfarchive", func_00314EF0);
#ifdef SKIP_ASM
extern "C" void func_00314EF0(sMdfIndex_00314E88* self, unsigned int hash, void* value)
{
    int i = func_00314E88(self, hash);
    if (i >= 0)
    {
        ((void**)((char*)self + 0x1030))[i] = value;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/mdfarchive", func_00314F30);
#ifdef SKIP_ASM
struct sMdfHandle_00314F30
{
    unsigned int kind : 8;
    unsigned int index : 24;
};

static inline void SetKind_00314F30(sMdfHandle_00314F30* h, int v) { h->kind = v; }
static inline void SetIndex_00314F30(sMdfHandle_00314F30* h, int v) { h->index = v; }

// PORT: func_00314EF0's value slot receives the handle struct by value here.
void func_00314EF0_handle(sMdfIndex_00314E88* self, unsigned int hash, sMdfHandle_00314F30 value) __asm__("func_00314EF0");

extern "C" void func_00314F30(sMdfIndex_00314E88* self, int kind, char* list)
{
    sMdfHandle_00314F30 h;
    for (int i = 0; i < *(short*)(*(char**)(list + 4) + 2); i++)
    {
        SetKind_00314F30(&h, kind);
        SetIndex_00314F30(&h, i);
        func_00314EF0_handle(self, *(unsigned int*)(i * 0x14 + *(int*)(list + 8)), h);
    }
}
#endif

//100%
INCLUDE_ASM("animation/mdfarchive", func_00314FE8);
#ifdef SKIP_ASM
extern void* D_004A5950;

extern "C" void func_00314FE8(sMdfIndex_00314E88* self, char* list)
{
    for (int i = 0; i < *(short*)(*(char**)(list + 4) + 2); i++)
    {
        func_00314EF0(self, *(unsigned int*)(i * 0x14 + *(int*)(list + 8)), D_004A5950);
    }
}
#endif

//100%
INCLUDE_ASM("animation/mdfarchive", func_00315070);
#ifdef SKIP_ASM
extern char* D_0048CFC0[];
extern char D_0048A4C0[];

extern "C" char* func_00315070(sMdfIndex_00314E88* self, unsigned int key)
{
    for (int i = 0; i < 0x206; i++) {
        if (key == ((unsigned int*)((char*)self + 0x1030))[i]) {
            return D_0048CFC0[i];
        }
    }
    return D_0048A4C0;
}
#endif

