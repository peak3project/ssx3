#include "common.h"
#include "bx/math3d.h"

// ---- Shared declarations: one type per real thing, used by the functions below ----

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// Three floats with an empty and a by-value ctor (not the POD t3Vector).
struct sFsVec3 {
    float x, y, z;
    sFsVec3() {}
    sFsVec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

inline sFsVec3 operator+(const sFsVec3& a, const sFsVec3& b) { return sFsVec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline sFsVec3 operator-(const sFsVec3& a, const sFsVec3& b) { return sFsVec3(a.x - b.x, a.y - b.y, a.z - b.z); }
inline sFsVec3 operator*(const sFsVec3& a, float s) { return sFsVec3(a.x * s, a.y * s, a.z * s); }

// Two floats with an empty and a by-value ctor (texture coordinates).
struct sFsVec2 {
    float x, y;
    sFsVec2() {}
    sFsVec2(float ax, float ay) : x(ax), y(ay) {}
};

inline sFsVec2 operator+(const sFsVec2& a, const sFsVec2& b) { return sFsVec2(a.x + b.x, a.y + b.y); }
inline sFsVec2 operator-(const sFsVec2& a, const sFsVec2& b) { return sFsVec2(a.x - b.x, a.y - b.y); }
inline sFsVec2 operator*(const sFsVec2& a, float s) { return sFsVec2(a.x * s, a.y * s); }

// A float colour (a, r, g, b) with an empty ctor.
struct sFsColor {
    float a, r, g, b;
    sFsColor() {}
};

// A render-state record of the graphics manager's state stack (D_00501420 holds the default).
struct sFsRenderState {
    unsigned int f0_0 : 12;
    unsigned int f0_12 : 8;
    unsigned int f0_20 : 12;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 25;
    int f8;
    int fC;
    int f10;
};
extern sFsRenderState D_00501420;

// Four floats with an empty ctor and a const-reference ctor (16-byte aligned; not the POD t4Vector).
struct sFsVec4 {
    float x, y, z, w;
    sFsVec4() {}
    sFsVec4(const float& a, const float& b, const float& c, const float& d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

// A model's texture-page / slot reference (page 0xFF = always loaded).
struct sFsModel {
    char pad_0x0[0x7D];
    unsigned char page;     // 0x7D
    short slot;             // 0x7E
};

unsigned int BXrand();
extern char* D_004A47B8;

// Uniform float in [0, 1) built from the random mantissa bits.
static inline float randf()
{
    union {
        int i;
        float f;
    } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return u.f - 1.0f;
}

// PORT: SN abs.s asm helper (PS2 FPU).
static inline float fsAbs(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// A model's texture page and slot are loaded (page 0xFF: nothing to load).
static inline int IsLoaded(sFsModel* m)
{
    char* wc = *(char**)D_004A47B8;
    if (m->page == 0xFF)
        return 1;
    int ok = *(int*)(wc + (m->page << 3) + 0x24) == 6;
    return ok ? *(int*)(wc + m->slot * 0x18 + 0x3F0) == 3 : 0;
}

// Render-state bitfield setters.
static inline void SetF0_12(sFsRenderState* rs, int v) { rs->f0_12 = v; }
static inline void SetF4_2(sFsRenderState* rs, int v) { rs->f4_2 = v; }

// One 0x188-byte flag-set element (the lists below hold 15): active flag at 0x5C, vptr at 0x184
// (slot 1 = destructor).
struct sFlagSetElem {
    char pad0[0x5C];
    int active;                         // 0x5C
    char pad60[0x184 - 0x60];
    sVEntry<void(void*, int)>* vt;      // 0x184
};

// The 15-element flag-set list: vtable at 0xC, the wave level state, then the elements.
struct sFlagSetList {
    char pad0[0xC];
    void** vtable;                  // 0xC
    float level;                    // 0x10
    float base;                     // 0x14
    float delta;                    // 0x18
    float t;                        // 0x1C
    sFlagSetElem elems[15];         // 0x20
};

// The flag mesh as cFlagSet_CreateMesh / func_0034D1E8 use it (vtable slot 6 adds a vertex: position, colour, uv).
struct sFsMesh {
    int pad0;
    sVEntry<void(void*, sFsVec3*, sFsColor*, sFsVec2*)>* vt;   // 0x4
};

// The flag mesh as func_0034B818 / func_0034CF98 use it (vtable slot 3 with one pointer argument).
struct sFlagMesh {
    int pad0;
    sVEntry<void(void*, void*)>* vt;   // 0x4
};

// Four floats with an empty ctor and a placement operator new[] (arrays of 16 are built in place).
struct sFlagVec4c {
    float v[4];
    sFlagVec4c() {}
    void* operator new[](unsigned int, void* p) { return p; }
};

// ---- end of shared declarations ----

//100%
INCLUDE_ASM("object/flagset", cFlagSet_CreateMesh);
#ifdef SKIP_ASM
extern char* D_004A5B80;
extern char D_0048E850[];
extern "C" void func_0034BCA0(void* self, void* verts);

// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");










struct sFlagElem_CM {
    char pad0[0x1C];
    float windX;            // 0x1C
    float windY;            // 0x20
    char pad24[0x3C];
    sFsMesh* mesh;       // 0x60
    int cols;               // 0x64
    int rows;               // 0x68
    float colScale;         // 0x6C
    float rowScale;         // 0x70
    sFsVec3* verts;        // 0x74
    float phase[4];         // 0x78
    float u;                // 0x88
    float v;                // 0x8C
};

extern "C" void cFlagSet_CreateMesh(void* p, void* item)
{
    sFlagElem_CM* self = (sFlagElem_CM*)p;
    int i;
    for (i = 0; i < 4; i++) {
        self->phase[i] = randf();
    }
    self->u = 0.0f;
    self->v = 0.0f;
    char* mgr = D_004A5B80;
    sFsVec2 quv[4];
    sFsColor qcol[4];
    sFsVec3 pos[4];
    sVEntry<void(void*, void*, int, sFsVec3*, sFsVec2*, sFsColor*)>* vt = *(sVEntry<void(void*, void*, int, sFsVec3*, sFsVec2*, sFsColor*)>**)(mgr + 0x10D8);
    vt[97].fn(mgr + vt[97].delta, item, 0, pos, quv, qcol);
    if (self->windX < 0.01f && self->windY < 0.01f) {
        self->cols = 8;
        self->rows = 2;
    } else {
        self->cols = 8;
        self->rows = 5;
    }
    self->colScale = (float)(self->cols - 1);
    self->rowScale = (float)(self->rows - 1);
    sVEntry<void*(void*, int, int, unsigned int)>* e = &(*(sVEntry<void*(void*, int, int, unsigned int)>**)(mgr + 0x10D8))[76];
    self->mesh = (sFsMesh*)e->fn(mgr + e->delta, self->cols, self->rows, 0x60000000u);
    if (self->mesh == 0) {
        return;
    }
    int n = self->cols * self->rows;
    sFsVec3** pv = &self->verts;
    *pv = new (D_0048E850, 0x20000000, 0) sFsVec3[n];
    sFsVec2 uv[50];
    sFsColor col[50];
    int idx = 0;
    for (int r = 0; r < self->rows; r++) {
        for (int c = 0; c < self->cols; c++) {
            float fc = (float)c / self->colScale;
            float fr = (float)r / self->rowScale;
            self->verts[idx] = (pos[0] * (1.0f - fc) + pos[1] * fc) * (1.0f - fr) + (pos[2] * (1.0f - fc) + pos[3] * fc) * fr;
            uv[idx] = (quv[0] * (1.0f - fc) + quv[1] * fc) * (1.0f - fr) + (quv[2] * (1.0f - fc) + quv[3] * fc) * fr;
            col[idx].a = 1.0f;
            col[idx].r = (qcol[0].r * (1.0f - fc) + qcol[1].r * fc) * (1.0f - fr) + (qcol[2].r * (1.0f - fc) + qcol[3].r * fc) * fr;
            col[idx].g = (qcol[0].g * (1.0f - fc) + qcol[1].g * fc) * (1.0f - fr) + (qcol[2].g * (1.0f - fc) + qcol[3].g * fc) * fr;
            col[idx].b = (qcol[0].b * (1.0f - fc) + qcol[1].b * fc) * (1.0f - fr) + (qcol[2].b * (1.0f - fc) + qcol[3].b * fc) * fr;
            idx++;
        }
    }
    sFsVec3 verts[50];
    func_0034BCA0(self, verts);
    sFsMesh* m = self->mesh;
    m->vt[6].fn((char*)m + m->vt[6].delta, verts, col, uv);
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034B7B8);
#ifdef SKIP_ASM
extern char* D_004A5B80;
void cMemMan_free(void*);


extern "C" void func_0034B7B8(void* self)
{
    char* s = (char*)self;
    void* h = *(void**)(s + 0x60);
    if (h != 0) {
        char* mgr = D_004A5B80;
        sVEntry<void(void*, void*)>* vt = *(sVEntry<void(void*, void*)>**)(mgr + 0x10D8);
        vt[77].fn(mgr + vt[77].delta, h);
        *(void**)(s + 0x60) = 0;
    }
    void* m = *(void**)(s + 0x74);
    if (m != 0) {
        cMemMan_free(m);
        *(void**)(s + 0x74) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034B818);
#ifdef SKIP_ASM
extern int D_004A4240;
extern "C" void* func_002D1CB0();
extern "C" int func_002D1C98();
extern "C" void func_0034BCA0(void* self, void* verts);

struct sFlagVert_B818 {
    float x, y, z;
    sFlagVert_B818() {}
};



struct sFlagElem_B818 {
    char pad0[0x4];
    float speed[4];         // 0x4
    char pad14[0x38];
    float blend;            // 0x4C
    float scrollU;          // 0x50
    float scrollV;          // 0x54
    char pad58[0x4];
    int active;             // 0x5C
    sFlagMesh* mesh;   // 0x60
    char pad64[0x14];
    float phase[4];         // 0x78
    float u;                // 0x88
    float v;                // 0x8C
    int parity;             // 0x90
};

extern "C" void func_0034B818(void* elem)
{
    sFlagElem_B818* self = (sFlagElem_B818*)elem;
    if (D_004A4240 == 0) {
        return;
    }
    if (self->active == 0) {
        return;
    }
    if (self->mesh == 0) {
        return;
    }
    char* wind = (char*)func_002D1CB0();
    float k = self->blend;
    float t = k + *(float*)(wind + 0x10) * (1.0f - k);
    int i;
    for (i = 0; i < 4; i++) {
        self->phase[i] += self->speed[i] * t;
        if (1.0f <= self->phase[i]) {
            self->phase[i] -= 1.0f;
        }
    }
    if (func_002D1C98() % 2 == self->parity) {
        sFlagVert_B818 verts[50];
        func_0034BCA0(self, verts);
        sFlagMesh* m = self->mesh;
        sVEntry<void(void*, void*)>* e = &m->vt[3];
        e->fn((char*)m + e->delta, verts);
    }
    if (0.001f < self->scrollU || 0.001f < self->scrollV) {
        self->u += self->scrollU;
        if (1.0f < self->u) {
            self->u -= 1.0f;
        }
        self->v += self->scrollV;
        if (1.0f < self->v) {
            self->v -= 1.0f;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034B9B0);
#ifdef SKIP_ASM
extern char* D_004A5B80;
extern int D_004A4244;
// PORT: 128-bit integer mode for VU0 asm memory operands
typedef int cQuad128_34B9B0 __attribute__((mode(TI)));
extern char D_004FF1A0[];









// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void MatCopy_34B9B0(t4Matrix* d, const t4Matrix* s)
{
    __asm__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

struct sFSE_34B9B0 {
    char pad[0x94];
    sFsModel* models[1];
};

#define TOP_34B9B0(c) (*(sFsRenderState**)((c) + 0xE84))

extern "C" void func_0034B9B0(sFlagSetElem* e)
{
    char* self = (char*)e;
    if (D_004A4244 == 0) {
        return;
    }
    char* ctx = D_004A5B80;
    TOP_34B9B0(ctx)[1] = TOP_34B9B0(ctx)[0];
    *++TOP_34B9B0(ctx) = D_00501420;
    if (*(signed char*)(self + 3) != 0) {
        SetF0_12(TOP_34B9B0(D_004A5B80), 0xFF);
        SetF4_2(TOP_34B9B0(D_004A5B80), 11);
    } else {
        SetF4_2(TOP_34B9B0(ctx), 5);
    }
    for (int i = 0; i < *(int*)(self + 0x5C); i++) {
        sFsModel* m = ((sFSE_34B9B0*)self)->models[i];
        if (!IsLoaded(m)) {
            continue;
        }
        {
            sVEntry<int(void*, sFsVec4*, sFsVec4*, t4Matrix*)>* vt = *(sVEntry<int(void*, sFsVec4*, sFsVec4*, t4Matrix*)>**)(ctx + 0x10D8);
            char* thisp = ctx + vt[93].delta;
            sFsVec4 a(*(float*)((char*)m + 0x60), *(float*)((char*)m + 0x64), *(float*)((char*)m + 0x68), 1.0f);
            sFsVec4 b(*(float*)((char*)m + 0x6C), *(float*)((char*)m + 0x70), *(float*)((char*)m + 0x74), 1.0f);
            sFsVec4* pb = &b;
            sVEntry<t4Matrix(void*)>* vt43 = *(sVEntry<t4Matrix(void*)>**)(ctx + 0x10D8);
            t4Matrix c = vt43[43].fn(ctx + vt43[43].delta);
            if (vt[93].fn(thisp, &a, pb, &c) == 1) {
                continue;
            }
        }
        {
            char* pos = (char*)m + 0x10;
            t4Matrix mat;
            MatCopy_34B9B0(&mat, (t4Matrix*)D_004FF1A0);
            mat.row[3].x = *(float*)(self + 0x88);
            mat.row[3].y = *(float*)(self + 0x8C);
            char* h = *(char**)(self + 0x60);
            if (h != 0) {
                sVEntry<void(void*, void*, void*, t4Matrix*)>* hv = *(sVEntry<void(void*, void*, void*, t4Matrix*)>**)(h + 4);
                hv[7].fn(h + hv[7].delta, pos, *(void**)((char*)m + 0x94), &mat);
            } else {
                sVEntry<void(void*, void*, int, int, int)>* v96 = *(sVEntry<void(void*, void*, int, int, int)>**)(ctx + 0x10D8);
                v96[96].fn(ctx + v96[96].delta, m, 0, 0, 0);
            }
        }
    }
    TOP_34B9B0(ctx)--;
}
#endif

INCLUDE_ASM("object/flagset", func_0034BCA0);

//100%
INCLUDE_ASM("object/flagset", func_0034C2E0);
#ifdef SKIP_ASM


struct sFlagSet_C2E0 {
    char pad0[0x5C];
    int count;          // 0x5C
    char pad60[0x34];
    void* items[1];     // 0x94
};

extern "C" void func_0034C2E0(void* elem, void* stream)
{
    int i;
    sFlagSet_C2E0* self = (sFlagSet_C2E0*)elem;
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, self, 0x60);
    for (i = 0; i < self->count; i++) {
        sVEntry<void(void*, void*)>* e2 = &(*(sVEntry<void(void*, void*)>**)stream)[5];
        e2->fn((char*)stream + e2->delta, self->items[i]);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flagset", func_0034C378);
#ifdef SKIP_ASM


extern "C" void cFlagSet_CreateMesh(void* self, void* item);

extern "C" void func_0034C378(void* elem, void* stream)
{
    int i;
    sFlagSet_C2E0* self = (sFlagSet_C2E0*)elem;
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, self, 0x60);
    for (i = 0; i < self->count; i++) {
        sVEntry<void*(void*)>* e2 = &(*(sVEntry<void*(void*)>**)stream)[3];
        self->items[i] = e2->fn((char*)stream + e2->delta);
    }
    if (self->count > 0) {
        cFlagSet_CreateMesh(self, self->items[0]);
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034C428);
#ifdef SKIP_ASM
extern "C" void* func_00354648(void* self, void* a1);
extern "C" void* func_0034AF38(void* self);
extern void* D_0048FB80[];



extern "C" sFlagSetList* func_0034C428(sFlagSetList* self, void* a1)
{
    int i;
    sFlagSetElem* p = self->elems;
    func_00354648(self, a1);
    self->vtable = D_0048FB80;
    for (i = 14; i != -1; i--, p++) {
        func_0034AF38(p);
    }
    self->base = 0.5f;
    self->delta = 0.25f;
    self->t = 0;
    self->level = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034C4B8);
#ifdef SKIP_ASM
extern "C" void func_003546C8(void* self, int flags);
extern void* D_0048FB80[];




extern "C" void func_0034C4B8(sFlagSetList* self, int flags)
{
    self->vtable = D_0048FB80;
    if (self->elems != 0) {
        sFlagSetElem* p = self->elems + 15;
        while (self->elems != p) {
            p--;
            p->vt[1].fn((char*)p + p->vt[1].delta, 0);
        }
    }
    func_003546C8(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034C548);
#ifdef SKIP_ASM


extern "C" int func_0034AFE8(void* self, void* data, void* ctx);
extern "C" void func_0034B038(void* self, void* data, void* ctx);

extern "C" void func_0034C548(sFlagSetList* self, void* node, void* desc)
{
    int i;
    sFlagSetElem* e;
    for (i = 0, e = self->elems; i < 15; i++, e++) {
        if (e->active != 0 && func_0034AFE8(e, desc, node) != 0) {
            func_0034B038(e, desc, node);
            return;
        }
    }
    sFlagSetElem* f = self->elems;
    for (int j = 0; j < 15; j++, f++) {
        if (f->active == 0) {
            func_0034B038(f, desc, node);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034C600);
#ifdef SKIP_ASM


extern "C" int func_0034B168(void* elem, void* arg);

extern "C" void func_0034C600(sFlagSetList* self, void* arg)
{
    int i;
    sFlagSetElem* e = self->elems;
    for (i = 0; i < 15; i++, e++) {
        if (e->active != 0 && func_0034B168(e, arg) != 0) {
            return;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flagset", func_0034C668);
#ifdef SKIP_ASM


extern "C" int func_002D1BA0();
extern "C" void func_0034B818(void* elem);
extern char* D_004A5B64;


extern "C" void func_0034C668(sFlagSetList* self)
{
    float amp = 0.15f;
    switch (func_002D1BA0()) {
    case 1:
        break;
    case 2:
        amp = 0.3f;
        break;
    case 3:
        amp = 0.45f;
        break;
    }
    self->t += 1.0f / (float)*(int*)(D_004A5B64 + 0x10);
    if (1.0f <= self->t) {
        self->t -= 1.0f;
        self->base += self->delta;
        float lo = -amp;
        self->delta = lo + (amp - lo) * randf();
        if (self->base + self->delta < 0.0f) {
            self->delta = -self->base;
        }
        if (1.0f < self->base + self->delta) {
            self->delta = 1.0f - self->base;
        }
    }
    self->level = self->base + self->delta * self->t;
    int i;
    for (i = 0; i < 15; i++) {
        sFlagSetElem* e = &self->elems[i];
        if (e->active != 0) {
            func_0034B818(e);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flagset", func_0034C7F8);
#ifdef SKIP_ASM


extern "C" void func_0034B9B0(sFlagSetElem* e);

extern "C" void func_0034C7F8(sFlagSetList* self)
{
    int i;
    for (i = 0; i < 15; i++) {
        sFlagSetElem* e = &self->elems[i];
        if (e->active != 0) {
            func_0034B9B0(e);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flagset", func_0034C848);
#ifdef SKIP_ASM


extern "C" void func_0034C2E0(void* elem, void* arg);

extern "C" void func_0034C848(sFlagSetList* self, void* arg)
{
    int i;
    for (i = 0; i < 15; i++) {
        func_0034C2E0(&self->elems[i], arg);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flagset", func_0034C898);
#ifdef SKIP_ASM


extern "C" void func_0034C378(void* elem, void* arg);

extern "C" void func_0034C898(sFlagSetList* self, void* arg)
{
    int i;
    for (i = 0; i < 15; i++) {
        func_0034C378(&self->elems[i], arg);
    }
}
#endif

INCLUDE_ASM("object/flagset", func_0034C8E8);

//100%
INCLUDE_ASM("object/flagset", func_0034CAB8);
#ifdef SKIP_ASM
struct sFlagBlock_CAB8 {
    unsigned int w[4];
};


struct sFlagSet_CAB8 {
    char pad0[0xC];
    void** vtable;              // 0xC
    char pad10[0xC];
    sFlagBlock_CAB8 block;      // 0x1C
    int field_0x2c;             // 0x2C
    int field_0x30;             // 0x30
    int field_0x34;             // 0x34
    int field_0x38;             // 0x38
    int field_0x3c;             // 0x3C
};

extern "C" void* func_0034FB00(void* self, int a1, int type, void* obj);
extern "C" void func_0034D1E8(void* self);
extern "C" void func_0034D6F0(void* self, float dt);
extern void* D_0048FA00[];

// PORT: the unit declares this as void (callers ignore the result); bound by asm label.
extern "C" sFlagSet_CAB8* func_0034CAB8_ctor(sFlagSet_CAB8* self, int a1, void* obj, sFlagBlock_CAB8* desc, int flag, float dt) __asm__("func_0034CAB8");
extern "C" sFlagSet_CAB8* func_0034CAB8_ctor(sFlagSet_CAB8* self, int a1, void* obj, sFlagBlock_CAB8* desc, int flag, float dt)
{
    func_0034FB00(self, a1, 9, obj);
    self->block.w[0] = 0xFFFFFFFF;
    self->vtable = D_0048FA00;
    new ((char*)self + 0x40) sFlagVec4c[16];
    self->block = *desc;
    self->field_0x30 = 0;
    self->field_0x2c = 0;
    self->field_0x34 = 0;
    self->block.w[0] = 0xFFFFFFFF;
    func_0034D1E8(self);
    func_0034D6F0(self, dt);
    self->field_0x38 = 4;
    self->field_0x3c = 4;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034CB80);
#ifdef SKIP_ASM
extern char* D_004A5B80;
extern void* D_0048FA00[];
extern "C" void func_0034FBF0(void* self, int flags);


extern "C" void func_0034CB80(void* self, int flags)
{
    char* s = (char*)self;
    *(void***)(s + 0xC) = D_0048FA00;
    void* h = *(void**)(s + 0x40);
    if (h != 0) {
        char* mgr = D_004A5B80;
        sVEntry<void(void*, void*)>* vt = *(sVEntry<void(void*, void*)>**)(mgr + 0x10D8);
        vt[77].fn(mgr + vt[77].delta, h);
    }
    func_0034FBF0(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034CBE8);
#ifdef SKIP_ASM
extern "C" void* cInstanceNode_cInstanceNode(void* self, void* a1, void* stream);
extern "C" void func_0034D1E8(void* self);
extern void* D_0048FA00[];



extern "C" void* func_0034CBE8(void* self, void* a1, void* stream)
{
    cInstanceNode_cInstanceNode(self, a1, stream);
    *(unsigned int*)((char*)self + 0x1C) = 0xFFFFFFFF;
    *(void***)((char*)self + 0xC) = D_0048FA00;
    new ((char*)self + 0x40) sFlagVec4c[16];
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[2];
    e->fn((char*)stream + e->delta, (char*)self + 0x1C, 0x24);
    func_0034D1E8(self);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/flagset", func_0034CC80);
#ifdef SKIP_ASM
class cFlagObj_CC80 {
public:
    int f0, f4, f8;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual int isA(int type);
};

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_0034CAB8(void* self, int a1, void* obj, void* pos, int flag, float force);
extern "C" void func_0034CDE8(void* self, int flag, float force);
extern char D_004A4018[];


extern "C" void func_0034CC80(char* self, char* obj, int flag)
{
    if (*(int*)(self + 0x40) == 0) {
        return;
    }
    if (obj == 0) {
        return;
    }
    float force;
    if (*(float*)(self + 0x34) < 0.0f) {
        force = *(float*)(self + 0x30) * 0.4f;
    } else {
        force = *(float*)(self + 0x30) * -0.4f;
    }
    cFlagObj_CC80* o = *(cFlagObj_CC80**)(obj + 0xC);
    if (o != 0) {
        if (o->isA(9) == 0) {
            return;
        }
        if (!(0.25f <= fsAbs(force))) {
            return;
        }
        if (flag != 0) {
            char* p = *(char**)(self + 0x104);
            if (p == 0) {
                return;
            }
            void* q = *(void**)(p + 0xC);
            if (q == 0) {
                return;
            }
            func_0034CDE8(q, flag, force);
        } else {
            char* p = *(char**)(self + 0x108);
            if (p == 0) {
                return;
            }
            void* q = *(void**)(p + 0xC);
            if (q == 0) {
                return;
            }
            func_0034CDE8(q, 0, force);
        }
    } else if (0.25f <= fsAbs(force)) {
        void* m = cMemMan_alloc(0x10C, D_004A4018, 0x20000000, 0);
        func_0034CAB8(m, 1, obj, self + 0x1C, flag, force);
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034CDE8);
#ifdef SKIP_ASM
extern "C" void func_0034D6F0(void* self, float dt);

extern "C" void func_0034CDE8(void* self, int on, float dt)
{
    func_0034D6F0(self, dt);
    if (on) {
        if (*(int*)((char*)self + 0x38) == 0) {
            *(int*)((char*)self + 0x38) = 4;
        }
    } else {
        if (*(int*)((char*)self + 0x3C) == 0) {
            *(int*)((char*)self + 0x3C) = 4;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034CE48);
#ifdef SKIP_ASM
extern "C" void func_0034CC80(char* self, char* obj, int flag);
extern "C" void func_0034CF98(void* self);



extern "C" void func_0034CE48(char* self)
{
    if (*(int*)(self + 0x38) > 0) {
        if (--*(int*)(self + 0x38) == 0) {
            func_0034CC80(self, *(char**)(self + 0x104), 1);
        }
    }
    if (*(int*)(self + 0x3C) > 0) {
        if (--*(int*)(self + 0x3C) == 0) {
            func_0034CC80(self, *(char**)(self + 0x108), 0);
        }
    }
    char* osc = self + 0x1C;
    *(float*)(self + 0x2C) += *(float*)(self + 0x34);
    if (*(float*)(self + 0x30) < 0.01f && fsAbs(*(float*)(osc + 0x10)) < 0.01f) {
        sVEntry<void(void*, int)>* vt = *(sVEntry<void(void*, int)>**)(self + 0xC);
        vt[34].fn(self + vt[34].delta, 1);
        return;
    }
    if (0.0f <= *(float*)(self + 0x34)) {
        if (*(float*)(self + 0x2C) >= *(float*)(self + 0x30)) {
            float a = *(float*)(self + 0x30);
            *(float*)(self + 0x2C) = a;
            float h = a * 0.5f;
            *(float*)(self + 0x30) = h;
            *(float*)(self + 0x34) = -h * 0.1f;
        }
    } else {
        float a = *(float*)(self + 0x30);
        float na = -a;
        if (*(float*)(self + 0x2C) <= na) {
            *(float*)(self + 0x2C) = na;
            float h = a * 0.5f;
            *(float*)(self + 0x30) = h;
            *(float*)(self + 0x34) = h * 0.1f;
        }
    }
    func_0034CF98(self);
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034CF98);
#ifdef SKIP_ASM
extern float D_0044AFD0[];

struct sFsVec4_CF98 {
    float x, y, z, w;
    sFsVec4_CF98() {}
    sFsVec4_CF98(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));


// PORT: VU0 macro-mode vector scale in place (v *= s).
static inline void fsScaleIn_CF98(sFsVec4_CF98& v, float s)
{
    __asm__(
        "mfc1       $2, %2\n"
        "lqc2       $vf4, 0x0(%1)\n"
        "qmtc2.ni   $2, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2       $vf5, 0x0(%1)\n"
        : "=m"(v)
        : "r"(&v), "f"(s)
        : "$2");
}

// PORT: VU0 macro-mode vector scale (a * s).
static inline sFsVec4_CF98 fsScale_CF98(const sFsVec4_CF98& a, float s)
{
    sFsVec4_CF98 r;
    __asm__(
        "mfc1       $2, %2\n"
        "lqc2       $vf4, 0x0(%1)\n"
        "qmtc2.ni   $2, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2       $vf5, %0\n"
        : "=m"(r)
        : "r"(&a), "f"(s)
        : "$2");
    return r;
}

static inline sFsVec3 fsAdd_CF98(const sFsVec3& a, const sFsVec4_CF98& b)
{
    return sFsVec3(a.x + b.x, a.y + b.y, a.z + b.z);
}



struct sFlagSet_CF98 {
    char pad0[0x20];
    int mode;               // 0x20
    float scale;            // 0x24
    char pad28[0x4];
    float wind;             // 0x2C
    char pad30[0x10];
    sFlagMesh* mesh;   // 0x40
    sFsVec3 top[8];    // 0x44
    sFsVec3 bottom[8]; // 0xA4
};

extern "C" void func_0034CF98(void* p)
{
    sFlagSet_CF98* self = (sFlagSet_CF98*)p;
    if (self->mesh == 0) {
        return;
    }
    float s = self->wind * self->scale;
    sFsVec4_CF98 dir(200.0f, 0.0f, 0.0f, 0.0f);
    fsScaleIn_CF98(dir, s);
    sFsVec4_CF98 offs[8];
    sFsVec4_CF98* o = offs;
    for (int i = 0; i < 8; i++) {
        *o++ = fsScale_CF98(dir, D_0044AFD0[i]);
    }
    sFsVec3 pts[16];
    if (self->mode == 1) {
        for (int i = 0; i < 8; i++) {
            pts[i] = fsAdd_CF98(self->top[i], offs[i]);
            pts[i + 8] = fsAdd_CF98(self->bottom[i], offs[i]);
        }
    } else {
        for (int i = 0; i < 8; i++) {
            pts[i] = fsAdd_CF98(self->top[i], offs[i]);
            pts[i + 8] = self->bottom[i];
        }
    }
    sFlagMesh* m = self->mesh;
    sVEntry<void(void*, void*)>* e = &m->vt[3];
    e->fn((char*)m + e->delta, pts);
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034D1E8);
#ifdef SKIP_ASM
extern char* D_004A5B80;
extern "C" void func_0034CF98(void* self);









struct sFsNode_D1E8 {
    char pad0[0x8];
    unsigned int flags;   // 0x8
};

struct sFlagSet_D1E8 {
    char pad0[0x18];
    sFsNode_D1E8* node;     // 0x18
    char pad1C[0x24];
    sFsMesh* mesh;     // 0x40
    sFsVec3 top[8];      // 0x44
    sFsVec3 bottom[8];   // 0xA4
    void* obj104;           // 0x104
    void* obj108;           // 0x108
};

extern "C" void func_0034D1E8(void* p)
{
    sFlagSet_D1E8* self = (sFlagSet_D1E8*)p;
    self->obj104 = 0;
    self->obj108 = 0;
    self->node->flags = (self->node->flags & ~2u) | 4;
    char* mgr = D_004A5B80;
    sVEntry<void*(void*, int, int, unsigned int)>* e = &(*(sVEntry<void*(void*, int, int, unsigned int)>**)(mgr + 0x10D8))[76];
    self->mesh = (sFsMesh*)e->fn(mgr + e->delta, 8, 2, 0x60000000u);
    sFsVec3 pos[4];
    sFsVec2 quv[4];
    sFsColor qcol[4];
    sVEntry<void(void*, void*, int, sFsVec3*, sFsVec2*, sFsColor*)>* vt = *(sVEntry<void(void*, void*, int, sFsVec3*, sFsVec2*, sFsColor*)>**)(mgr + 0x10D8);
    vt[97].fn(mgr + vt[97].delta, self->node, 0, pos, quv, qcol);
    sFsVec2 uv[16];
    sFsColor col[16];
    for (int i = 0; i < 8; i++) {
        float t = (float)i;
        self->top[i] = pos[0] + (pos[1] - pos[0]) * t * 0.1428571492433548f;
        self->bottom[i] = pos[2] + (pos[3] - pos[2]) * t * 0.1428571492433548f;
        uv[i] = quv[0] + (quv[1] - quv[0]) * t * 0.1428571492433548f;
        uv[i + 8] = quv[2] + (quv[3] - quv[2]) * t * 0.1428571492433548f;
        col[i].a = 1.0f;
        col[i].r = qcol[0].r + (qcol[1].r - qcol[0].r) * t * 0.1428571492433548f;
        col[i].g = qcol[0].g + (qcol[1].g - qcol[0].g) * t * 0.1428571492433548f;
        col[i].b = qcol[0].b + (qcol[1].b - qcol[0].b) * t * 0.1428571492433548f;
        col[i + 8].a = 1.0f;
        col[i + 8].r = qcol[2].r + (qcol[3].r - qcol[2].r) * t * 0.1428571492433548f;
        col[i + 8].g = qcol[2].g + (qcol[3].g - qcol[2].g) * t * 0.1428571492433548f;
        col[i + 8].b = qcol[2].b + (qcol[3].b - qcol[2].b) * t * 0.1428571492433548f;
    }
    sFsMesh* m = self->mesh;
    m->vt[6].fn((char*)m + m->vt[6].delta, pos, col, uv);
    func_0034CF98(self);
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034D650);
#ifdef SKIP_ASM
extern "C" void func_0034D6F0(void* self, float dt);


// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float fsDot_D650(const t4Vector& a, const t4Vector& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

extern "C" void func_0034D650(void* self, void* obj)
{
    char* s = (char*)self;
    char* o = (char*)obj;
    if (*(float*)(s + 0x30) >= 1.0f) return;
    float d = fsDot_D650(*(t4Vector*)(o + 0x20), *(t4Vector*)(o + 0x10));
    func_0034D6F0(self, d * 0.0010000000474974513f * *(float*)(o + 0x30));
    if (*(int*)(s + 0x38) == 0) *(int*)(s + 0x38) = 4;
    if (*(int*)(s + 0x3C) == 0) *(int*)(s + 0x3C) = 4;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034D6F0);
#ifdef SKIP_ASM
struct sFlag34D6F0 {
    char pad0[0x30];
    float wind;     // 0x30
    float speed;    // 0x34
};


// Accumulates wind strength on the flag set (clamped to 1) and sets the flap speed with the wind direction.
extern "C" void func_0034D6F0(void* vself, float v)
{
    sFlag34D6F0* self = (sFlag34D6F0*)vself;
    self->wind += fsAbs(v);
    if (self->wind > 1.0f) {
        self->wind = 1.0f;
    }
    if (self->speed == 0.0f) {
        if (v < 0.0f) {
            self->speed = self->wind * -0.1f;
        } else {
            self->speed = self->wind * 0.1f;
        }
    } else if (self->speed < 0.0f) {
        self->speed = self->wind * -0.1f;
    } else {
        self->speed = self->wind * 0.1f;
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034D778);
#ifdef SKIP_ASM








#define TOP_D778(c) (*(sFsRenderState**)((c) + 0xE84))

extern "C" void func_0034D778(void* vself)
{
    char* self = (char*)vself;
    if (!IsLoaded(*(sFsModel**)(self + 0x18))) {
        return;
    }
    char* ctx = D_004A5B80;
    {
        sFsModel* m = *(sFsModel**)(self + 0x18);
        sVEntry<int(void*, sFsVec4*, sFsVec4*, t4Matrix*)>* vt = *(sVEntry<int(void*, sFsVec4*, sFsVec4*, t4Matrix*)>**)(ctx + 0x10D8);
        char* thisp = ctx + vt[93].delta;
        sFsVec4 a(*(float*)((char*)m + 0x60), *(float*)((char*)m + 0x64), *(float*)((char*)m + 0x68), 1.0f);
        sFsVec4 b(*(float*)((char*)m + 0x6C), *(float*)((char*)m + 0x70), *(float*)((char*)m + 0x74), 1.0f);
        sFsVec4* pb = &b;
        sVEntry<t4Matrix(void*)>* vt43 = *(sVEntry<t4Matrix(void*)>**)(ctx + 0x10D8);
        t4Matrix c = vt43[43].fn(ctx + vt43[43].delta);
        if (vt[93].fn(thisp, &a, pb, &c) == 1) {
            return;
        }
    }
    TOP_D778(ctx)[1] = TOP_D778(ctx)[0];
    sFsRenderState* t = TOP_D778(ctx);
    TOP_D778(ctx) = t + 1;
    t[1].f4_2 = 5;
    sFsModel* m = *(sFsModel**)(self + 0x18);
    char* pos = (char*)m + 0x10;
    char* h = *(char**)(self + 0x40);
    if (h != 0) {
        sVEntry<void(void*, void*, void*, t4Matrix*)>* hv = *(sVEntry<void(void*, void*, void*, t4Matrix*)>**)(h + 4);
        hv[7].fn(h + hv[7].delta, pos, *(void**)((char*)m + 0x94), 0);
    } else {
        sVEntry<void(void*, void*, int, int, int)>* v96 = *(sVEntry<void(void*, void*, int, int, int)>**)(ctx + 0x10D8);
        v96[96].fn(ctx + v96[96].delta, m, 0, 0, 0);
    }
    TOP_D778(ctx)--;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034D960);
#ifdef SKIP_ASM

extern "C" void func_0034FE90(void* self, void* stream);

extern "C" void func_0034D960(void* self, void* stream)
{
    func_0034FE90(self, stream);
    sVEntry<void(void*, void*, int)>* vt = *(sVEntry<void(void*, void*, int)>**)stream;
    vt[1].fn((char*)stream + vt[1].delta, (char*)self + 0x1C, 0x24);
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034D9B0);
#ifdef SKIP_ASM
extern "C" void* func_00355280(void* self, void* a1, int type, void* a3);
extern "C" void cAnimNode_setAnimMeshCache(void* self);
extern "C" float func_00351508(void* p);
struct sFlagOwner_E348;
extern "C" void func_0034E348(sFlagOwner_E348* self);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern void* D_00490CC8[];
extern char D_0048E758[];

struct sFlagSlot_34D9B0 {
    int v[16];
    sFlagSlot_34D9B0() {}
};

extern "C" void* func_0034D9B0(char* self, void* a1, int a2, void* a3, int force)
{
    char* node = self + 0x14;
    func_00355280(node, a1, a2, a3);
    *(void***)(self + 0x20) = D_00490CC8;
    sFlagSlot_34D9B0** slot = (sFlagSlot_34D9B0**)(self + 0x44);
    *slot = new (D_0048E758, 0x20000000, 0) sFlagSlot_34D9B0[*(int*)(*(char**)(*(char**)(node + 0x18) + 0x80) + 4)];
    cAnimNode_setAnimMeshCache(self);
    float f = 0.0f;
    if (*(void**)(self + 0x48) != 0) {
        f = func_00351508(*(void**)(self + 0x48));
    }
    *(float*)(self + 0x0) = f;
    *(float*)(self + 0x8) = 10000000000.0f;
    *(float*)(self + 0x4) = f;
    *(int*)(self + 0x10) = 1;
    *(float*)(self + 0xC) = 10000000000.0f;
    char* sub = self + 0x14;
    if (force != 0 || (*(unsigned int*)(*(char**)(sub + 0x18) + 8) & 1)) {
        char* n = *(char**)(sub + 0x18);
        *(unsigned int*)(n + 8) = (*(unsigned int*)(n + 8) & ~2u) | 4;
    }
    func_0034E348((sFlagOwner_E348*)self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034DAC8);
#ifdef SKIP_ASM
extern "C" void* cMoveNode_cMoveNode(void* self, void* a1, void* stream);


// Element type with an empty constructor; the array new leaves only its loop counters.
struct sFlagSlot_34DAC8 {
    int v[16];
    sFlagSlot_34DAC8() {}
};

extern "C" void* func_0034DAC8(char* self, void* a1, void* stream)
{
    int unusedFlag;
    char* node = self + 0x14;
    sFlagSlot_34DAC8** slot = (sFlagSlot_34DAC8**)(self + 0x44);
    cMoveNode_cMoveNode(node, a1, stream);
    *(void***)(self + 0x20) = D_00490CC8;
    *slot = new (D_0048E758, 0x20000000, 0) sFlagSlot_34DAC8[*(int*)(*(char**)(*(char**)(node + 0x18) + 0x80) + 4)];
    cAnimNode_setAnimMeshCache(self);
    sVEntry<void(void*, void*, int)>* vt = *(sVEntry<void(void*, void*, int)>**)stream;
    vt[2].fn((char*)stream + vt[2].delta, self, 0x14);
    sVEntry<void(void*, void*, int)>* vt2 = *(sVEntry<void(void*, void*, int)>**)stream;
    vt2[2].fn((char*)stream + vt2[2].delta, &unusedFlag, 4);
    func_0034E348((sFlagOwner_E348*)self);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034DBA8);
#ifdef SKIP_ASM

struct sFlagItem_DBA8 {
    char pad_0x0[0x84];
    sVEntry<void(void*, int)>* vt;       // 0x84
    char pad_0x88[0x48];
};

struct sFlagOwner_DBA8 {
    char pad_0x0[0x14];
    char node[0xC];             // 0x14
    void** vtable;              // 0x20
    char pad_0x24[0x20];
    void* cache;                // 0x44
    sFlagItem_DBA8* items;      // 0x48, array-new block (count at -0x10)
    void* buf;                  // 0x4C
};

void cMemMan_free(void*);
void operator_delete(int*);
extern "C" void func_003553C0(void* self, int flags);
extern void* D_00490CC8[];

extern "C" void func_0034DBA8(sFlagOwner_DBA8* self, int flags)
{
    self->vtable = D_00490CC8;
    if (self->cache != 0) {
        cMemMan_free(self->cache);
    }
    sFlagItem_DBA8* items = self->items;
    if (items != 0) {
        sFlagItem_DBA8* p = items + ((int*)items)[-4];
        while (self->items != p) {
            p--;
            p->vt[1].fn((char*)p + p->vt[1].delta, 0);
        }
        cMemMan_free((char*)self->items - 0x10);
    }
    if (self->buf != 0) {
        cMemMan_free(self->buf);
    }
    func_003553C0(self->node, 0);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034DC90);
#ifdef SKIP_ASM



extern "C" void func_0034DC90(void* self)
{
    sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)((char*)self + 0x20);
    vt[52].fn((char*)self + vt[52].delta);
    char* sub = (char*)self + 0x14;
    sVEntry<void(void*, void*, int)>* vt2 = *(sVEntry<void(void*, void*, int)>**)((char*)self + 0x20);
    void* objB = sub + vt2[33].delta;
    void* r = ((sVEntry<void*(void*)>*)vt2)[24].fn(sub + vt2[24].delta);
    vt2[33].fn(objB, r, *(int*)((char*)self + 0x44));
    *(unsigned short*)((char*)self + 0x26) &= ~1;
}
#endif

INCLUDE_ASM("object/flagset", func_0034DD18);

//100%
INCLUDE_ASM("object/flagset", func_0034E320);
#ifdef SKIP_ASM
extern char D_004FF1A0[];

extern "C" void* func_0034E320(void* self, int i) {
    char* base = *(char**)((char*)self + 0x48);
    if (base == 0) {
        return D_004FF1A0;
    }
    return base + i * 0xD0 + 0x90;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034E348);
#ifdef SKIP_ASM

struct sFlagItem_E348 {
    char pad0[0x84];
    sVEntry<void(void*, float)>* vt;    // 0x84
    char pad88[0x48];
};

struct sFlagOwner_E348 {
    int field_0x0;
    float time;                 // 0x4
    char pad8[0x8];
    int dirty;                  // 0x10
    char pad14[0x2C];
    int count;                  // 0x40
    int field_0x44;
    sFlagItem_E348* items;      // 0x48
};

extern "C" void func_0034E348(sFlagOwner_E348* self)
{
    int i;
    if (self->items != 0) {
        for (i = 0; i < self->count; i++) {
            // PORT: pointer arithmetic done in int (gives the target's offset-first addu).
            sFlagItem_E348* e = (sFlagItem_E348*)(i * 0xD0 + (int)self->items);
            e->vt[2].fn((char*)e + e->vt[2].delta, self->time);
        }
    }
    self->dirty = 1;
}
#endif

//100%
INCLUDE_ASM("object/flagset", func_0034E3D8);
#ifdef SKIP_ASM

extern "C" void func_00356B30(void* self, void* stream);

extern "C" void func_0034E3D8(void* self, void* stream)
{
    int dummy;
    func_00356B30((char*)self + 0x14, stream);
    sVEntry<void(void*, void*, int)>* e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, self, 0x14);
    e = &(*(sVEntry<void(void*, void*, int)>**)stream)[1];
    e->fn((char*)stream + e->delta, &dummy, 4);
}
#endif

