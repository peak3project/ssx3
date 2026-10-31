#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002EC418(void* self);
extern const char D_004A3B48[];

//100%
INCLUDE_ASM("visualfx/lensfx", cLensFxMan_construct__Fv);
#ifdef SKIP_ASM
void* cLensFxMan_construct()
{
    void* mem = cMemMan_alloc(0x6820, D_004A3B48, 0, 0);
    return func_002EC418(mem);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EC418);
#ifdef SKIP_ASM
extern "C" void* func_002E2E18(void* self);
extern void* D_00487F00[];

// PORT: asm label because the unit's forward declaration above has C++ linkage;
// fix that declaration to extern "C" and this can be a plain extern "C" definition.
void* func_002EC418_impl(void* self) __asm__("func_002EC418");
void* func_002EC418_impl(void* self)
{
    func_002E2E18(self);
    *(int*)((char*)self + 0x649c) = (int)(void*)D_00487F00;
    return self;
}
#endif

extern void* D_00487F00[];
extern "C" void* func_002E3060(void*);

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EC450__FPv);
#ifdef SKIP_ASM
void* func_002EC450(void* self)
{
    *(int*)((char*)self + 0x649c) = (int)(void*)D_00487F00;
    return func_002E3060(self);
}
#endif

INCLUDE_ASM("visualfx/lensfx", func_002EC478);

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EC9D0__FPv);
#ifdef SKIP_ASM
void* func_002EC9D0(void* self)
{
    *(int*)self = -1;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/lensfx", func_002EC9E0);
#ifdef SKIP_ASM
extern void* D_00487EE8[];
struct sLensFx;
extern "C" void func_002ECAF0(sLensFx* self);

extern "C" void* func_002EC9E0(void* self, int a1, int a2)
{
    *(void***)((char*)self + 0xC4) = D_00487EE8;
    *(int*)((char*)self + 0x0) = 1;
    *(int*)((char*)self + 0x4) = a1;
    *(int*)((char*)self + 0xC) = a2;
    *(int*)((char*)self + 0x8) = 0;
    char* p = (char*)self + 0x10;
    int i;
    for (i = 14; i != -1; i--, p += 0xC) {
        func_002EC9D0(p);
    }
    func_002ECAF0((sLensFx*)self);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/lensfx", func_002ECA68);
#ifdef SKIP_ASM
extern void* D_00487EE8[];
struct sLensFx;
extern "C" void func_002ECAF0(sLensFx* self);

extern "C" void* func_002ECA68(void* self, int a1, int a2)
{
    *(void***)((char*)self + 0xC4) = D_00487EE8;
    *(int*)((char*)self + 0x0) = 1;
    *(int*)((char*)self + 0x8) = a1;
    *(int*)((char*)self + 0xC) = a2;
    *(int*)((char*)self + 0x4) = 0;
    char* p = (char*)self + 0x10;
    int i;
    for (i = 14; i != -1; i--, p += 0xC) {
        func_002EC9D0(p);
    }
    func_002ECAF0((sLensFx*)self);
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ECAF0);
#ifdef SKIP_ASM
struct sLensEntry {
    int id;
    int a;
    int b;
};

struct sLensFx {
    char pad00[0x10];
    sLensEntry entries[15];
};

extern "C" void func_002ECAF0(sLensFx* self)
{
    int i;
    for (i = 0; i < 15; i++) {
        self->entries[i].id = -1;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ECB28);
#ifdef SKIP_ASM
extern void* D_00487EE8[];
extern "C" void func_002F2218(int a, int id);
void operator_delete(int* ptr);

extern "C" void func_002ECB28(sLensFx* self, int flags)
{
    *(void***)((char*)self + 0xC4) = D_00487EE8;
    int i;
    for (i = 0; i < 15; i++) {
        if (self->entries[i].id != -1) {
            func_002F2218(*(int*)((char*)self + 0xC), self->entries[i].id);
            self->entries[i].id = -1;
        }
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ECBC0);
#ifdef SKIP_ASM
struct func_002ECBC0_sEntry {
    int id;
    int b;
    int c;
};

struct func_002ECBC0_sMgr {
    char pad[0x10];
    func_002ECBC0_sEntry entries[15];
};

extern "C" int func_002ECC28(void* self, int a1, int a2);

extern "C" int func_002ECBC0(func_002ECBC0_sMgr* self, int a1, int a2)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (self->entries[i].id != -1 && self->entries[i].b == a2 && self->entries[i].c == a1) {
            return i;
        }
    }
    return func_002ECC28(self, a1, a2);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ECC28);
#ifdef SKIP_ASM
extern "C" int func_002F2130(int a, int x, int y);

extern "C" int func_002ECC28(void* p, int x, int y)
{
    sLensFx* self = (sLensFx*)p;
    int i;
    for (i = 0; i < 15; i++) {
        if (self->entries[i].id == -1) {
            self->entries[i].id = func_002F2130(*(int*)((char*)self + 0xC), x, y);
            self->entries[i].a = y;
            self->entries[i].b = x;
            return i;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ECCB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0014ABE0();
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" void* func_0014AD50(void* self, int rider);
void* func_0014BDB8_noarg() __asm__("func_0014BDB8__FPv");
int func_0014D988(void* self, int i);
extern "C" void* func_0014D998(void* self, int i);
extern "C" int func_00123168(void* self);
extern "C" int func_00123128(void* self);
extern "C" void* cUIStateStack_getCurrentState(void* self);
extern "C" void func_002F2218(int a, int id);
extern char* D_004A28A8;

struct sVEi_CCB8 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sLensItem_CCB8 {
    char pad0[4];
    short slot;                 // 0x4
    char pad6[0x11 - 6];
    signed char kind;           // 0x11
    signed char ids[2];         // 0x12
    char pad14[0x38 - 0x14];
};

struct sLensMgr_CCB8 {
    int active;                 // 0x0
    char* rider;                // 0x4
    int* charId;                // 0x8
    int fxSys;                  // 0xC
    sLensEntry entries[15];     // 0x10
};

extern "C" void func_002ECCB8(void* vself)
{
    sLensMgr_CCB8* self = (sLensMgr_CCB8*)vself;
    int used[15];
    for (int z = 14; z >= 0; z--) {
        used[z] = 0;
    }
    void* lib = func_0014ABE0();
    char* tbl = 0;
    int id = -1;
    char* rider = self->rider;
    if (rider != 0) {
        char* o = rider + 0x6C0;
        sVEi_CCB8* vt = *(sVEi_CCB8**)o;
        tbl = (char*)func_0014AD50(lib, vt[7].fn(o + vt[7].delta));
        id = func_00123168(self->rider);
        if (id < 10) {
            id = func_00123128(self->rider);
        }
    } else if (self->charId != 0) {
        char* st = (char*)cUIStateStack_getCurrentState(*(char**)(*(char**)(D_004A28A8 + 0x7C) + 0xC) + 0x18);
        tbl = (char*)func_0014AD28(lib, *(signed char*)(st + 0x44), *self->charId);
        id = *self->charId;
    }
    void* lib2 = func_0014BDB8_noarg();
    int n;
    sLensEntry* ents = self->entries;
    n = func_0014D988(lib2, id);
    sLensItem_CCB8* e = (sLensItem_CCB8*)func_0014D998(lib2, id);
    for (int i = 0; i < n; i++, e++) {
        int k = e->kind;
        if (k == -1) {
            continue;
        }
        short s = (*(short**)(tbl + 0x288))[e->slot];
        char* q;
        if (s >= 0) {
            q = tbl + (s * 4 + 0x290);
        } else {
            q = 0;
        }
        if (id < 10 && (*(unsigned short*)(q + 2) & 0x10) == 0) {
            continue;
        }
        for (int j = 0; j < 2; j++) {
            int v = e->ids[j];
            if (v == -1) {
                continue;
            }
            if (k >= 50) {
                used[func_002ECBC0((func_002ECBC0_sMgr*)self, k - 50, v)] = 1;
                used[func_002ECBC0((func_002ECBC0_sMgr*)self, k - 49, v)] = 1;
            } else {
                used[func_002ECBC0((func_002ECBC0_sMgr*)self, k, v)] = 1;
            }
        }
    }
    for (int r = 0; r < 15; r++) {
        if (ents[r].id != -1 && used[r] == 0) {
            func_002F2218(self->fxSys, ents[r].id);
            ents[r].id = -1;
        }
    }
    self->active = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/lensfx", func_002ECF78);
#ifdef SKIP_ASM
extern "C" void func_002ECCB8(void* self);

extern "C" void func_002ECF78(void* self)
{
    if (*(int*)self != 0) {
        func_002ECCB8(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ECFA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sLensRow_CFA0 {
    char* objs[9];
    char pad[0xF0 - 0x24];
};

struct sLensVE_CFA0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// The unit declares D_004FA370 later as sLensFxSlot[]; bind a row view to the same symbol.
extern sLensRow_CFA0 D_lensRows_CFA0[] __asm__("D_004FA370");
extern int D_004A3B54;

extern "C" void func_002ECFA0(void)
{
    if (D_004A3B54 != 0) {
        int i;
        for (i = 0; i < 8; i++) {
            int j;
            for (j = 0; j < 9; j++) {
                char* o = D_lensRows_CFA0[i].objs[j];
                if (o != 0) {
                    sLensVE_CFA0* vt = *(sLensVE_CFA0**)(o + 4);
                    vt[1].fn(o + vt[1].delta, 3);
                }
            }
        }
    }
    D_004A3B54 = 0;
}
#endif

INCLUDE_ASM("visualfx/lensfx", func_002ED048);

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ED1D0);
#ifdef SKIP_ASM
struct sLerpV4_D1D0 {
    float x, y, z, w;
    sLerpV4_D1D0() {}
    sLerpV4_D1D0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

static inline sLerpV4_D1D0 operator*(const sLerpV4_D1D0& a, float s)
{
    return sLerpV4_D1D0(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline sLerpV4_D1D0 operator+(const sLerpV4_D1D0& a, const sLerpV4_D1D0& b)
{
    return sLerpV4_D1D0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct sLensLerp_D1D0 {
    char pad00[0x28];
    sLerpV4_D1D0 a;
    sLerpV4_D1D0 b;
};

extern "C" void func_002ED1D0(sLensLerp_D1D0* self, const sLerpV4_D1D0* a, const sLerpV4_D1D0* b, int full)
{
    float t = 0.8999999761581421f;
    float s;
    if (full) {
        t = 1.0f;
    }
    s = 1.0f - t;
    self->a = sLerpV4_D1D0(self->a.x * s, self->a.y * s, self->a.z * s, self->a.w * s) + *a * t;
    self->b = sLerpV4_D1D0(self->b.x * s, self->b.y * s, self->b.z * s, self->b.w * s) + *b * t;
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002ED338);
#ifdef SKIP_ASM
struct sLerpV4 {
    float x, y, z, w;
    sLerpV4() {}
    sLerpV4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

static inline sLerpV4 operator*(const sLerpV4& a, float s)
{
    return sLerpV4(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline sLerpV4 operator+(const sLerpV4& a, const sLerpV4& b)
{
    return sLerpV4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct sLensLerp {
    char pad00[0x28];
    sLerpV4 a;
    sLerpV4 b;
};

extern "C" void func_002ED338(sLensLerp* self, const sLerpV4* a, const sLerpV4* b, float t)
{
    float s = 1.0f - t;
    self->a = sLerpV4(self->a.x * s, self->a.y * s, self->a.z * s, self->a.w * s) + *a * t;
    self->b = sLerpV4(self->b.x * s, self->b.y * s, self->b.z * s, self->b.w * s) + *b * t;
}
#endif

INCLUDE_ASM("visualfx/lensfx", func_002ED490);

INCLUDE_ASM("visualfx/lensfx", func_002EDB20);

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EDF00);
#ifdef SKIP_ASM
extern "C" float func_0040DA10(float x);
extern "C" float func_0040D758(float x);

// PORT: abs.s via inline asm (as an SDK math-header fabsf would); gcc folds __builtin_fabsf of a constant.
static inline float absf_DF00(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ `<?` (min) operator, removed in GCC 4.3.
static inline float clamp_DF00(float f, float lo, float hi)
{
    if (f >= lo) {
        return f <? hi;
    }
    return lo;
}

extern "C" float func_002EDF00(void* self)
{
    float lum = *(float*)((char*)self + 0x4) * 0.29899999499320984f
              + *(float*)((char*)self + 0x8) * 0.5870000123977661f
              + *(float*)((char*)self + 0xC) * 0.11400000005960464f;
    if (lum <= 0.10000000149011612f) {
        return 0.0f;
    }
    if (lum >= 0.44999998807907104f) {
        return 1.0f;
    }
    float k = 0.600117564201355f;
    float t = (lum - 0.10000000149011612f) / absf_DF00(0.3499999940395355f);
    return clamp_DF00(func_0040D758(func_0040DA10(t) * k), 0.0f, 1.0f);
}
#endif

// padded past the 8-byte gp-relative threshold so the compiler emits
// absolute lui/lo addressing like the target
struct sPad16 { char x; int pad[3]; };
extern sPad16 D_004FA3C0;

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EDFB8);
#ifdef SKIP_ASM
extern "C" void* func_002EDFB8(int a0)
{
    return (char*)&D_004FA3C0 + a0 * 0xf0;
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EDFD0);
#ifdef SKIP_ASM
extern char D_005047F8[];
extern "C" int func_0038AC50(void*, void*);

extern "C" void func_002EDFD0(void* self)
{
    *(int*)self = func_0038AC50(D_005047F8, self);
    *(int*)((char*)self + 4) = 0x123400;
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE010);
#ifdef SKIP_ASM
extern "C" void* func_0038ABF8(void* self, int i);
extern int D_004A43C4;

extern "C" void* func_002EE010(void* self);
extern "C" void* func_002EE010(void* self)
{
    if (*(int*)((char*)self + 4) != 0x123400) {
        if (*(signed char*)self == 0) {
            return func_0038ABF8(D_005047F8, D_004A43C4);
        }
        func_002EDFD0(self);
        return func_0038ABF8(D_005047F8, *(int*)self);
    }
    return func_0038ABF8(D_005047F8, *(int*)self);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE070);
#ifdef SKIP_ASM
struct sLensFxVEntry {
    short delta;
    short index;
    float* (*fn)(void*);
};

struct sLensFxObj {
    int unk0;
    sLensFxVEntry* vt; // 0x4
};

struct sLensFxSlot {
    sLensFxObj** p0;   // 0x0
    int pad4[3];
    sLensFxObj** p10;  // 0x10
    sLensFxObj** p14;  // 0x14
    int pad18[2];
    sLensFxObj** p20;  // 0x20
    char pad24[0xF0 - 0x24];
};

extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE070(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[27].fn((char*)obj + obj->vt[27].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE0B8);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE0B8(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[28].fn((char*)obj + obj->vt[28].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE100);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE100(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[29].fn((char*)obj + obj->vt[29].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE148);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE148(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[30].fn((char*)obj + obj->vt[30].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE190);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE190(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[31].fn((char*)obj + obj->vt[31].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE1D8);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE1D8(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[32].fn((char*)obj + obj->vt[32].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE220);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" int func_002EE220(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *(int*)obj->vt[33].fn((char*)obj + obj->vt[33].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE268);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE268(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[34].fn((char*)obj + obj->vt[34].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE2B0);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE2B0(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p14;
    return *obj->vt[35].fn((char*)obj + obj->vt[35].delta);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/lensfx", func_002EE2F8);
#ifdef SKIP_ASM
extern "C" void* func_002EE010(void* p);

// $gp-relative object at gp+0x24C0 (no symbol in the target)
extern int D_004A55B0;

extern "C" void func_002EE2F8(void)
{
    func_002EE010(&D_004A55B0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/lensfx", func_002EE318);
#ifdef SKIP_ASM
extern "C" void* func_002EE010(void* p);
extern "C" void* func_002EF0E8(void);

extern "C" void func_002EE318(void)
{
    func_002EE010(func_002EF0E8());
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/lensfx", func_002EE340);
#ifdef SKIP_ASM
extern "C" void* func_002EE010(void* p);
extern "C" void* func_002EF140(void);

extern "C" void func_002EE340(void)
{
    func_002EE010(func_002EF140());
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/lensfx", func_002EE368);
#ifdef SKIP_ASM
extern "C" void* func_002EE010(void* p);
extern "C" void* func_002EF198(void);

extern "C" void func_002EE368(void)
{
    func_002EE010(func_002EF198());
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE390);
#ifdef SKIP_ASM
extern "C" void* func_002EE010(void* p);
extern "C" void* func_002EF1F0();

extern "C" void func_002EE390()
{
    func_002EE010(func_002EF1F0());
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE3B8);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE3B8(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p0;
    return *obj->vt[6].fn((char*)obj + obj->vt[6].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE400);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE400(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p10;
    return *obj->vt[26].fn((char*)obj + obj->vt[26].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE448);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EE448(int i)
{
    if (D_004A3B60 == 0) {
        sLensFxSlot* s = &D_004FA370[i];
        sLensFxObj* obj = *s->p20;
        return *obj->vt[43].fn((char*)obj + obj->vt[43].delta) * (1.0f - *(float*)((char*)s + 0x24));
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE4C0);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE4C0(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[44].fn((char*)obj + obj->vt[44].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE508);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE508(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[45].fn((char*)obj + obj->vt[45].delta) * (1.0f - *(float*)((char*)s + 0x24));
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE570);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE570(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[46].fn((char*)obj + obj->vt[46].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE5B8);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE5B8(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[49].fn((char*)obj + obj->vt[49].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE600);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EE600(int i)
{
    if (D_004A3B60 == 0) {
        sLensFxSlot* s = &D_004FA370[i];
        sLensFxObj* obj = *s->p20;
        return *obj->vt[51].fn((char*)obj + obj->vt[51].delta);
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE660);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE660(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[52].fn((char*)obj + obj->vt[52].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE6A8);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE6A8(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[50].fn((char*)obj + obj->vt[50].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE6F0);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE6F0(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[48].fn((char*)obj + obj->vt[48].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE738);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE738(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[53].fn((char*)obj + obj->vt[53].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/lensfx", func_002EE780);
#ifdef SKIP_ASM
extern sLensFxSlot D_004FA370[];

extern "C" float func_002EE780(int i)
{
    sLensFxSlot* s = &D_004FA370[i];
    sLensFxObj* obj = *s->p20;
    return *obj->vt[54].fn((char*)obj + obj->vt[54].delta);
}
#endif

