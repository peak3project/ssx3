#include "common.h"

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DBD10);
#ifdef SKIP_ASM
struct Pre_BD10 { char pad0[0xF50]; int texmap[0x51]; char pad1[0x10B0 - 0x1094]; int dst[10]; };
class Mgr_BD10 : public Pre_BD10 {
public:
  void SetEffectTexMap(int effectID, int tex) {
    texmap[effectID] = tex;
  }
  int GetEffectTexMap(int effectID) {
    return texmap[effectID];
  }
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
  virtual void v11();
  virtual void v12();
  virtual void v13();
  virtual void v14();
  virtual void v15();
  virtual void v16();
  virtual void v17();
  virtual void v18();
  virtual void v19();
  virtual void v20();
  virtual void v21();
  virtual void v22();
  virtual void v23();
  virtual void v24();
  virtual void v25();
  virtual void v26();
  virtual void v27();
  virtual void v28();
  virtual void v29();
  virtual void v30();
  virtual void v31();
  virtual void v32();
  virtual void v33();
  virtual void v34();
  virtual void v35();
  virtual void v36();
  virtual void v37();
  virtual void v38();
  virtual void v39();
  virtual void v40();
  virtual void v41();
  virtual void v42();
  virtual void v43();
  virtual void v44();
  virtual void v45();
  virtual int v46(long, char*, int, int, long);
};
extern Mgr_BD10 *D_BD10 __asm__("D_004A5B80");
extern "C" int FILE_load(char*, int);
extern "C" long func_003B3900(int, char*);
extern "C" void func_002523A8(int);
extern char D_00487918[];
extern char D_00487938[];
struct sFXShape_BD10 { char name[8]; int tex; };
extern sFXShape_BD10 gFXShape_BD10[] __asm__("D_004891B0");
extern "C" int func_002DBD10(int a0, long a1) {
    int files[2];
    int v;
    long r;
    int n = 2;
    if (a1)
        n = 1;
    for (int i = 0; i < n; i++) {
        switch (i) {
        case 0:
            files[i] = FILE_load(D_00487918, 0x100);
            break;
        case 1:
            files[i] = FILE_load(D_00487938, 0x100);
            break;
        }
    }
    Mgr_BD10* m = D_BD10;
    for (int k = 0; k < 0x51; k++) {
        r = 0;
        for (int i = 0; i < n; i++) {
            r = func_003B3900(files[i], gFXShape_BD10[k].name);
            if (r != 0)
                break;
        }
        v = -1;
        if (r != 0)
            v = D_BD10->v46(r, gFXShape_BD10[k].name, gFXShape_BD10[k].tex, 1, -1);
        m->SetEffectTexMap(k, v);
    }
    for (int i = 0; i < n; i++)
        func_002523A8(files[i]);
    for (int i = 0; i < 10; i++)
        m->dst[i] = m->GetEffectTexMap(0x47 + i);
    return a0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DBEE0);
#ifdef SKIP_ASM
struct Pre_BEE0 { char pad[0x10D8]; };
class Mgr_BEE0 : Pre_BEE0 {
public:
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
  virtual void v11();
  virtual void v12();
  virtual void v13();
  virtual void v14();
  virtual void v15();
  virtual void v16();
  virtual void v17();
  virtual void v18();
  virtual void v19();
  virtual void v20();
  virtual void v21();
  virtual void v22();
  virtual void v23();
  virtual void v24();
  virtual void v25();
  virtual void v26();
  virtual void v27();
  virtual void v28();
  virtual void v29();
  virtual void v30();
  virtual void v31();
  virtual void v32();
  virtual void v33();
  virtual void v34();
  virtual void v35();
  virtual void v36();
  virtual void v37();
  virtual void v38();
  virtual void v39();
  virtual void v40();
  virtual void v41();
  virtual void v42();
  virtual void v43();
  virtual void v44();
  virtual void v45();
  virtual void v46();
  virtual void v47();
  virtual void v48();
  virtual void v48b();
  virtual void v50(int);
};
extern Mgr_BEE0 *D_004A5B80;
void operator_delete(int *);
extern "C" void func_002DBEE0(int *self, int flags) {
    Mgr_BEE0 *m = D_004A5B80;
    int i;
    for (i = 0; i < 0x51; i++) {
        int *slot = (int*)((char*)m + 0xF50) + i;
        if (*slot != -1) {
            m->v50(*slot);
            *slot = -1;
        }
    }
    if (flags & 1) operator_delete(self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DBF80);
#ifdef SKIP_ASM
extern char D_00488308[];
extern "C" void *func_002DBF80(int *self) {
    self[0] = 0;
    *(char**)((char*)self + 4) = D_00488308;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DBF98);
#ifdef SKIP_ASM
extern "C" int func_00418EF8(void* base, int n, int size, int (*cmp)(void*, void*));
extern "C" int func_002DC168(void* arg0, void* arg1);
struct RS_BF98 {
    unsigned int w0_lo : 2;
    unsigned int a : 2;
    unsigned int w0_hi : 28;
    unsigned int b : 2;
    unsigned int c : 5;
    unsigned int w1_p7 : 5;
    unsigned int d : 8;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 2;
    unsigned int w1_hi : 7;
    unsigned int w2_lo : 5;
    unsigned int h : 5;
    unsigned int i : 19;
    unsigned int w2_hi : 3;
    int w3;
    int w4;
};
struct Ctx_BF98 { char pad[0xE84]; RS_BF98* top; char pad2[0xF60 - 0xE88]; int f60; };
extern Ctx_BF98* D_004A289C;
extern char D_00537AC0[];
struct VEnt_BF98 { short delta; short idx; void (*fn)(void*); };
struct Obj_BF98 { int n; char* vt; };

static inline void Push_BF98() {
    Ctx_BF98* ctx = D_004A289C;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
}
static inline void Pop_BF98() {
    D_004A289C->top--;
}
static inline void G3_BF98(int c, int f, int g, int e, int d) {
    Ctx_BF98* ctx = D_004A289C;
    ctx->top->c = c;
    ctx->top->f = f;
    ctx->top->g = g;
    ctx->top->e = e;
    ctx->top->d = d;
}

extern "C" void func_002DBF98(Obj_BF98* self) {
    if (self->n) {
        func_00418EF8(D_00537AC0, self->n, 8, func_002DC168);
        Push_BF98();
        {
            Ctx_BF98* ctx = D_004A289C;
            int v = ctx->f60;
            ctx->top->h = 7;
            ctx->top->b = 2;
            ctx->top->i = 0x3FF;
            *(short*)((char*)ctx->top + 0x10) = v;
        }
        {
            Ctx_BF98* ctx = D_004A289C;
            ctx->top->a = 3;
            *(short*)((char*)ctx->top + 0x12) = -1;
        }
        G3_BF98(5, 1, 0, 3, 0);
        {
            VEnt_BF98* e = (VEnt_BF98*)(self->vt + 0x18);
            e->fn((char*)self + e->delta);
        }
        Pop_BF98();
        self->n = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DC168);
#ifdef SKIP_ASM
extern "C" int func_002DC168(void *arg0, void *arg1) {
    int temp_3;
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (4)));
    temp_3 = (*(int *)((char*)(arg1) + (4)));
    if (temp_4 >= temp_3) {
        return (temp_3 >= temp_4) ? 0 : -1;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DC190);
#ifdef SKIP_ASM
struct sV3_C190 {
    float x, y, z;
    sV3_C190() {}
    sV3_C190(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sV4_C190 {
    float x, y, z, w;
    sV4_C190() {}
    sV4_C190(const sV3_C190& v, const float& vw) : x(v.x), y(v.y), z(v.z), w(vw) {}
    sV4_C190(float vx, float vy, float vz, const float& vw) : x(vx), y(vy), z(vz), w(vw) {}
    sV4_C190(float vx, float vy) : x(vx), y(vy), z(0.0f), w(0.0f) {}
} __attribute__((aligned(16)));

struct sRow_C190 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sMat_C190;

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, d = a * b).
static inline void mulMat_C190(sMat_C190* d, const sMat_C190* a, const sMat_C190* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void copyMat_C190(sMat_C190* d, const sMat_C190* s)
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
        : "r"(d), "r"(s)
        : "memory");
}


struct sMat_C190 {
    sRow_C190 r[4];
    sMat_C190() {}
    // Product constructor: *this = a * b.
    sMat_C190(const sMat_C190& a, const sMat_C190& b) { mulMat_C190(this, &a, &b); }
    sMat_C190& operator=(const sMat_C190& s)
    {
        copyMat_C190(this, &s);
        return *this;
    }
};

struct sCtx_C190 {
    char pad_0x0[0x6AF0];
    float sx;                       // 0x6AF0
    char pad_0x6AF4[0x10];
    float sy;                       // 0x6B04
    char pad_0x6B08[0x28];
    sMat_C190 view;                 // 0x6B30
    sV4_C190 clipMin;               // 0x6B70
    sV4_C190 clipMax;               // 0x6B80
    int ready;                      // 0x6B90
};

struct sVert_C190 {
    sV3_C190 pos;                   // 0x0
    float col[3];                   // 0xC
    float size;                     // 0x18
};

struct sPart_C190 {
    char pad_0x0[0x1C];
    int count;                      // 0x1C
    sVert_C190* verts;              // 0x20
};

struct sList_C190 {
    int f0;
    sPart_C190* part;               // 0x4
};

struct sMesh_C190 {
    int f0;
    int count;                      // 0x4
    sList_C190* list;               // 0x8
};

struct sObj_C190 {
    char pad_0x0[0x10];
    sMat_C190 mat;                  // 0x10
    char pad_0x50[0x14];
    sMesh_C190* mesh;               // 0x64
    sV3_C190 min;                   // 0x68
    sV3_C190 max;                   // 0x74
};

struct sSprite_C190 {
    sV4_C190 a;                     // 0x0
    sV4_C190 b;                     // 0x10
    float col[4];                   // 0x20
};

struct sOut_C190 {
    int count;
    int pad[3];
    sSprite_C190 e[1];              // 0x10
};

struct sKey_C190 {
    int idx;
    int depth;
};

extern sCtx_C190* D_C190 __asm__("D_004A5B80");
extern sKey_C190 D_00537AC0_C190[] __asm__("D_00537AC0");
extern "C" void func_0037D968(void* self);

static inline sV3_C190 operator*(const sV3_C190& a, float s)
{
    return sV3_C190(a.x * s, a.y * s, a.z * s);
}

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector).
static inline sV4_C190 mulMatVec_C190(const sMat_C190* m, const sV4_C190& v)
{
    sV4_C190 r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sV4_C190 sub_C190(const sV4_C190& a, const sV4_C190& b)
{
    sV4_C190 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sV4_C190 add4_C190(const sV4_C190& a, const sV4_C190& b)
{
    sV4_C190 r;
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

static inline int outcode_C190(const sCtx_C190* g, const sV4_C190& v)
{
    int code = 0;
    if (v.x < g->clipMin.x)
        code |= 2;
    if (g->clipMax.x < v.x)
        code |= 1;
    if (v.y < g->clipMin.y)
        code |= 8;
    if (g->clipMax.y < v.y)
        code |= 4;
    if (v.w < 0.0f) {
        code ^= 0x2F;
    } else {
        if (g->clipMin.z < v.z)
            code |= 0x20;
        if (v.z < g->clipMax.z)
            code |= 0x10;
    }
    return code;
}

extern "C" void func_002DC190(sOut_C190* out, sObj_C190** objs, int n, int clip)
{
    sCtx_C190* g = D_C190;
    if (g->ready == 0)
        func_0037D968(g);
    for (int i = 0; i < n; i++) {
        sObj_C190* obj = objs[i];
        sV4_C190 c = mulMatVec_C190(&g->view, sV4_C190(sV3_C190(obj->min.x + obj->max.x, obj->min.y + obj->max.y, obj->min.z + obj->max.z) * 0.5f, 1.0f));
        float d = (int)c.w;
        if (d >= 25000.0f)
            continue;
        float fade;
        if (d < 18000.0f)
            fade = 1.0f;
        else
            fade = (25000.0f - d) * 0.000142857141f;
        sMat_C190 m;
        m = sMat_C190(g->view, obj->mat);
        sMesh_C190* mesh = obj->mesh;
        sList_C190* list = mesh->list;
        for (int j = 0; j < mesh->count; j++) {
            sPart_C190* part = list->part;
            if (part != 0 && part->count != 0) {
                sVert_C190* v = part->verts;
                for (int k = 0; k < part->count; k++, v++) {
                    sV4_C190 p = mulMatVec_C190(&m, sV4_C190(v->pos.x, v->pos.y, v->pos.z, 1.0f));
                    int depth = (int)p.w;
                    if (depth > 0) {
                        float fd = depth;
                        float t;
                        if (fd <= 500.0f)
                            t = 0.0f;
                        else if (fd < 2499.66748046875f)
                            t = (fd - 500.0f) * 0.00050008314f;
                        else
                            t = 1.0f;
                        float a = fade * t;
                        if (a != 0.0f) {
                            p.w = 1.0f / p.w;
                            unsigned short id = out->count;
                            D_00537AC0_C190[id].idx = id;
                            D_00537AC0_C190[id].depth = depth;
                            p.x *= p.w;
                            p.y *= p.w;
                            float s = v->size * p.w;
                            sV4_C190 off(g->sx * s, g->sy * s);
                            out->e[out->count].a = sub_C190(p, off);
                            out->e[out->count].b = add4_C190(p, off);
                            if (clip != 0) {
                                if (outcode_C190(g, out->e[out->count].a) & outcode_C190(g, out->e[out->count].b))
                                    continue;
                            }
                            out->e[out->count].col[0] = a * 128.0f;
                            out->e[out->count].col[1] = v->col[0] * 128.0f;
                            out->e[out->count].col[2] = v->col[1] * 128.0f;
                            out->e[out->count].col[3] = v->col[2] * 128.0f;
                            out->count++;
                        }
                    }
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DC7B0);
#ifdef SKIP_ASM
struct sDma_C7B0 {
    int f0[4];
    int size : 28;                  // 0x10
    int f10hi : 4;
};
struct sRS_C7B0 {
    int f0;
    int f4;
    int f8;
    int fC;
    short tex;
    short pad;
};
struct sEnt_C7B0 {
    sRS_C7B0 rs;                    // 0x00
    unsigned int buf;               // 0x14
    unsigned int next;              // 0x18
    short key;                      // 0x1C
    short flag;                     // 0x1E
    char pad_0x20[0x60];
};
struct sRing_C7B0 {
    int count;                      // 0x0
    char pad_0x4[0x7C];
    sEnt_C7B0 ents[1];              // 0x80
};
struct sGfx_C7B0 {
    char pad_0x0[0xE84];
    sRS_C7B0* top;                  // 0xE84
    char pad_0xE88[0x18F0 - 0xE88];
    sRing_C7B0* ring;               // 0x18F0
    char pad_0x18F4[0x5A00 - 0x18F4];
    unsigned int buf;               // 0x5A00
};
extern sGfx_C7B0* D_C7B0 __asm__("D_004A5B80");
extern sDma_C7B0* D_004A4474;
extern "C" char* func_0038F460(void* self, unsigned int addr, int size, int flags);
extern "C" unsigned int func_0038F668(void* self, char* end, int arg);

static inline void SetUV_C7B0(float uv[2], const float& u, const float& v)
{
    uv[0] = u;
    uv[1] = v;
}

union uFI_C7B0 {
    float f;
    int i;
};

// GS ST register: s and t scaled by q, packed as raw float bits.
static inline long PackST_C7B0(const float uv[2], float q)
{
    uFI_C7B0 s, t;
    s.f = uv[0] * q;
    t.f = uv[1] * q;
    return (long)s.i | ((long)t.i << 32);
}

static inline int NumFit_C7B0(int qw, int dw)
{
    return (qw * 2) / dw;
}

// PORT: 64-bit GIF/DMA packet words; float bits reinterpreted through a union.
extern "C" void func_002DC7B0(sOut_C190* out)
{
    sGfx_C7B0* gfx = D_C7B0;
    int left = out->count;
    int max = NumFit_C7B0(D_004A4474->size - 4, 5) - 1;
    int start = 0;
    while (left > 0) {
        int n = max;
        if (left < n)
            n = left;
        unsigned int buf = gfx->buf;
        long* p = (long*)func_0038F460(D_004A4474, buf, -1, 0);
        float st0[2];
        float st1[2];
        SetUV_C7B0(st0, 0.0f, 0.0f);
        SetUV_C7B0(st1, 1.0f, 1.0f);
        int pad;
        int qwc;
        if ((n & 1) == 0) {
            pad = 0;
            qwc = ((n * 5) >> 1) + 3;
        } else {
            pad = 1;
            qwc = ((n * 5) >> 1) + 4;
        }
        p[0] = (qwc + 1) | 0x10000000;
        p[1] = 0;
        p[2] = 0;
        p[3] = (long)(qwc | 0x50000000) << 32;
        p[4] = 0x1400000000008001L;
        p[5] = 0;
        p[6] = 0x56;
        p[7] = 0;
        p[8] = (n | 0x8000) | 0x5400000000000000L;
        p[9] = 0x52512;
        p += 10;
        for (int j = start; j < start + n; j++) {
            sSprite_C190* e = &out->e[D_00537AC0_C190[j].idx];
            float q = e->a.w;
            uFI_C7B0 qb;
            qb.f = q;
            p[0] = PackST_C7B0(st0, q);
            p[1] = (long)(int)e->col[1] | ((long)(int)e->col[2] << 8) | ((long)(int)e->col[3] << 16) |
                   ((long)(int)e->col[0] << 24) | ((long)qb.i << 32);
            p[2] = (long)(int)e->a.x | ((long)(int)e->a.y << 16) | ((long)(int)(e->a.z * q) << 32);
            p[3] = PackST_C7B0(st1, q);
            p[4] = (long)(int)e->b.x | ((long)(int)e->b.y << 16) | ((long)(int)(e->b.z * q) << 32);
            p += 5;
        }
        if (pad)
            *p++ = 0;
        unsigned int next = func_0038F668(D_004A4474, (char*)p, 4);
        sRing_C7B0* ring = gfx->ring;
        sRS_C7B0* rs = gfx->top;
        if (ring->count < 0xA28) {
            rs->f8 = (rs->f8 & ~0x1F) | (*(int*)((char*)ring + 0x69CC4) & 0x1F);
            int key = *(int*)((char*)ring + 0x69CC0);
            sEnt_C7B0* e = (sEnt_C7B0*)((ring->count++ << 7) + ((unsigned int)ring->ents | 0x30000000));
            e->rs = *rs;
            e->buf = buf;
            e->next = next;
            e->key = key;
            e->flag = 0;
        }
        gfx->buf = next + 0x10;
        left -= n;
        start += n;
    }
}
#endif
