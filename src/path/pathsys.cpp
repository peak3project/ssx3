#include "common.h"

//100%
INCLUDE_ASM("path/pathsys", cPathSys_resolvePaths);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_0026BA68(void* dst, void* src);
extern "C" int func_0026A180(void* path, char* data);
extern char D_00481438[];
extern void* D_00481448[];

inline void* operator new[](unsigned int, void* p) { return p; }

struct sPathB310 {
    char pad_0x0[0x34];
    void** vtable;          // 0x34
    int field_0x38;         // 0x38
    sPathB310() { vtable = D_00481448; }
};

struct sPathSysB310 {
    char pad_0x0[0x10];
    int count;              // 0x10
    sPathB310* paths;       // 0x14
};

extern "C" int cPathSys_resolvePaths(sPathSysB310* self, char* p)
{
    int count;
    sPathB310** slot = &self->paths;
    char* start = p;
    func_0026BA68(&count, p);
    p += 4;
    self->count = count;
    *slot = new (operator_new_tag(count * sizeof(sPathB310), D_00481438, 0, 0)) sPathB310[count];
    for (int i = 0; i < self->count; i++) {
        p += func_0026A180(&self->paths[i], p);
    }
    return p - start;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B410);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_0026BA68(void* dst, void* src);
extern "C" int func_0026A180(void* path, char* data);
extern char D_004A3408[];
extern void* D_00481478[];

struct sPathB410 {
    char pad_0x0[0x34];
    void** vtable;          // 0x34
    int field_0x38;         // 0x38
    int field_0x3C;         // 0x3C
    sPathB410() { vtable = D_00481478; }
    void* operator new[](unsigned int, void* p) { return p; }
};

struct sPathSysB410 {
    char pad_0x0[0x8];
    int count;              // 0x8
    sPathB410* paths;       // 0xC
};

extern "C" int func_0026B410(sPathSysB410* self, char* p)
{
    int count;
    sPathB410** slot = &self->paths;
    char* start = p;
    func_0026BA68(&count, p);
    p += 4;
    self->count = count;
    *slot = new (operator_new_tag(count * sizeof(sPathB410), D_004A3408, 0, 0)) sPathB410[count];
    for (int i = 0; i < self->count; i++) {
        p += func_0026A180(&self->paths[i], p);
    }
    return p - start;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B508);
#ifdef SKIP_ASM
struct sPathEntry28 {
    int field_0x0;
    int field_0x4;
    char pad_0x8[0x20];
};

struct sPathEntry40 {
    char pad_0x0[0x40];
};

struct sPathEntry3C {
    char pad_0x0[0x3c];
};

struct sPathSys {
    int count28;             // 0x0
    sPathEntry28* entries28; // 0x4
    int count40;             // 0x8
    sPathEntry40* entries40; // 0xc
    int count3C;             // 0x10
    sPathEntry3C* entries3C; // 0x14
};

extern "C" int func_0026B508(sPathSys* self, sPathEntry3C* entry)
{
    int i;
    if (entry != 0) {
        for (i = 0; i < self->count3C; i++) {
            if (&self->entries3C[i] == entry) {
                return i;
            }
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B550);
#ifdef SKIP_ASM
extern "C" int func_0026B550(sPathSys* self, sPathEntry40* entry)
{
    int i;
    if (entry != 0) {
        for (i = 0; i < self->count40; i++) {
            if (&self->entries40[i] == entry) {
                return i;
            }
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B598);
#ifdef SKIP_ASM
extern "C" int func_0026B598(sPathSys* self, int a, int b)
{
    int i;
    int count = self->count28;
    for (i = 0; i < count; i++) {
        if (self->entries28[i].field_0x4 == a && self->entries28[i].field_0x0 == b) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B5E0);
#ifdef SKIP_ASM
struct sPathEntry {
    int id;                 // 0x0
    int type;               // 0x4
    char pad_0x8[0x20];
};

struct sPathEntryList {
    int count;              // 0x0
    sPathEntry* entries;    // 0x4
};

extern "C" sPathEntry* func_0026B5E0(sPathEntryList* list, int type, int id)
{
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->entries[i].type == type && list->entries[i].id == id) {
            return &list->entries[i];
        }
    }
    if (list->count > 0) {
        return list->entries;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B648);
#ifdef SKIP_ASM
extern "C" int func_0026B648(void *arg0, int arg1) {
    int temp_2;

    temp_2 = (*(int *)((char*)(arg0) + (0)));
    if ((temp_2 <= 0) || (arg1 >= temp_2) || (arg1 < 0)) {
        return 0;
    }
    return (*(int *)((char*)(arg0) + (4))) + (arg1 * 0x28);
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B680);
#ifdef SKIP_ASM
struct sPathVec3 {
    float x, y, z;
    sPathVec3() {}
    sPathVec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

static inline sPathVec3 operator-(const sPathVec3& a, const sPathVec3& b)
{
    return sPathVec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

struct sPathNearEntry {
    int id;             // 0x0
    int type;           // 0x4
    sPathVec3 pos;      // 0x8
    char pad_0x14[0x14];
};

struct sPathNearList {
    int count;                  // 0x0
    sPathNearEntry* entries;    // 0x4
};

extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00154630(void* self, int value, int id);
extern char* D_004A28A8;

// PORT: sqrt.s helper
static inline float pathSqrt(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline float pathLen(const sPathVec3& v)
{
    return pathSqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

extern "C" int func_0026B680(sPathNearList* list, sPathVec3* pos)
{
    int i;
    float best = 10000000.0f;
    int bestId = -1;
    for (i = 0; i < list->count; i++) {
        if (list->entries[i].type == 2 && list->entries[i].id != 0) {
            if (func_00154630(cBE_getInterface_Fv(cBE_getBE(), 10), list->entries[i].id,
                              *(int*)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0x78) + 0x1BC)) != 0) {
                sPathVec3 d = list->entries[i].pos - *pos;
                float dist = pathLen(d);
                if (dist < best) {
                    best = dist;
                    bestId = list->entries[i].id;
                }
            }
        }
    }
    return bestId;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B7D8);
#ifdef SKIP_ASM
extern "C" void func_0026BA68(void* dst, void* src);
extern "C" void func_0026BA88(void* dst, void* src);

struct sPathPair_B7D8 {
    int a;      // 0x0
    int b;      // 0x4
};

struct sPathSys_B7D8 {
    char pad_0x0[0x18];
    sPathPair_B7D8 pairs[1];    // 0x18
};

extern "C" int func_0026B7D8(sPathSys_B7D8* self, char* p)
{
    int count;
    char* start = p;
    func_0026BA68(&count, p);
    p += 4;
    for (int i = 0; i < count; i++) {
        func_0026BA88(&self->pairs[i].b, p);
        p += 4;
        func_0026BA68(&self->pairs[i].a, p);
        p += 4;
    }
    return p - start;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026B880);
#ifdef SKIP_ASM
extern "C" void func_0026BA68(void* dst, void* src);
extern "C" void func_0026BA48(void* dst, void* src);

extern int D_00445428[];

struct sPathNode_B880 {
    int id;             // 0x0
    int type;           // 0x4
    char pos[0xC];      // 0x8
    char dir[0xC];      // 0x14
    char* f20;          // 0x20
    char* f24;          // 0x24
};

struct sPathSys_B880 {
    int count;                  // 0x0
    sPathNode_B880* nodes;      // 0x4
    int pad_0x8;                // 0x8
    char* fC;                   // 0xC
    int pad_0x10;               // 0x10
    char* f14;                  // 0x14
};

extern "C" int func_0026B880(sPathSys_B880* self, char* p)
{
    int tmp;
    int a;
    int b;
    char* start = p;
    func_0026BA68(&tmp, p);
    p += 4;
    self->nodes = (sPathNode_B880*)p;
    self->count = tmp;
    for (int i = 0; i < self->count; i++) {
        func_0026BA68(&self->nodes[i].id, p);
        p += 4;
        func_0026BA68(&tmp, p);
        p += 4;
        func_0026BA48(self->nodes[i].pos, p);
        p += 0xC;
        func_0026BA48(self->nodes[i].dir, p);
        p += 0xC;
        func_0026BA68(&a, p);
        p += 4;
        func_0026BA68(&b, p);
        p += 4;
        self->nodes[i].type = 0;
        for (int j = 0; j < 3; j++) {
            if (D_00445428[j] == tmp) {
                self->nodes[i].type = j;
                break;
            }
        }
        self->nodes[i].f24 = self->fC + a * 0x40;
        self->nodes[i].f20 = self->f14 + b * 0x3C;
    }
    return p - start;
}
#endif

extern "C" void* func_003E6574(void*, void*, int);

//100%
INCLUDE_ASM("path/pathsys", func_0026BA48);
#ifdef SKIP_ASM
extern "C" void func_0026BA48(void* dst, void* src)
{
    if (dst != src) {
        func_003E6574(dst, src, 0xc);
    }
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026BA68);
#ifdef SKIP_ASM
extern "C" void func_0026BA68(void* dst, void* src)
{
    if (dst != src) {
        func_003E6574(dst, src, 0x4);
    }
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026BA88);
#ifdef SKIP_ASM
extern "C" void func_0026BA88(void* dst, void* src)
{
    if (dst != src) {
        func_003E6574(dst, src, 0x4);
    }
}
#endif

INCLUDE_ASM("path/pathsys", func_0026BAA8);

INCLUDE_ASM("path/pathsys", func_0026BAE8);

INCLUDE_ASM("path/pathsys", func_0026C3D0);
//100%
INCLUDE_ASM("path/pathsys", func_0026C400);
#ifdef SKIP_ASM
extern "C" int func_0026C400(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif
//100%
INCLUDE_ASM("path/pathsys", func_0026C408);
#ifdef SKIP_ASM
extern "C" int func_0026C408(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026C410__FPv);
#ifdef SKIP_ASM
void func_0026C410(void* self)
{
}
#endif

//100%
INCLUDE_ASM("path/pathsys", func_0026C418__FPv);
#ifdef SKIP_ASM
void func_0026C418(void* self)
{
}
#endif

extern "C" void* func_0026BAE8(int, int);

//100%
INCLUDE_ASM("path/pathsys", func_0026C420);
#ifdef SKIP_ASM
extern "C" int func_0026C420(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x38)));
}
#endif
//100%
INCLUDE_ASM("path/pathsys", func_0026C428);
#ifdef SKIP_ASM
extern "C" int func_0026C428(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3C)));
}
#endif
//100%
INCLUDE_ASM("path/pathsys", func_0026C430);
#ifdef SKIP_ASM
extern "C" float func_0026C430(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x38)));
}
#endif

//99.38%
INCLUDE_ASM("path/pathsys", func_0026C438__FPv);
#ifdef SKIP_ASM
void* func_0026C438(void* self)
{
    return func_0026BAE8(1, 0xffff);
}
#endif

