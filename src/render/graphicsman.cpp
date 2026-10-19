#include "common.h"

// R5900 128-bit GPR quadword, for functions that copy a 16-byte block via a
// single lq/sq pair instead of word-by-word.
typedef int cQuad128 __attribute__((mode(TI)));

//100%
INCLUDE_ASM("render/graphicsman", cGraphicsMan_AddBlendedMatrix);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00492638[];

struct sBlendWeight {
    short bone;
    short weight;
};

struct sBlendMatrix {
    int count;              // 0x0
    sBlendWeight* weights;  // 0x4
    int pad_0x8;
};

struct sGfxManBlend {
    char pad_0x000[0xF48];
    sBlendMatrix* blend;    // 0xF48
    int nBlend;             // 0xF4C
};

extern "C" int func_00369A78(void* a, void* b, int tol0, int tol1, int tol2);

extern "C" void cGraphicsMan_AddBlendedMatrix(sGfxManBlend* self, sBlendMatrix* m)
{
    if (self->blend == 0) {
        sBlendMatrix* mem = (sBlendMatrix*)operator_new_tag(0x3000, D_00492638, 0x100, 0);
        self->blend = mem;
        sBlendWeight* w = (sBlendWeight*)(mem + 0x200);
        for (int k = 0; k < 0x200; k++) {
            self->blend[k].weights = w;
            w += 3;
        }
    }
    sBlendMatrix* e = self->blend;
    for (int i = 0; i < self->nBlend; i++, e++) {
        if (func_00369A78(e, m, 10, 20, 20)) {
            for (int j = 0; j < e->count; j++) {
                m->weights[j].bone = e->weights[j].bone;
            }
            return;
        }
    }
    self->blend[self->nBlend].count = m->count;
    for (int j = 0; j < m->count; j++) {
        self->blend[self->nBlend].weights[j] = m->weights[j];
    }
    self->nBlend++;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00369A78);
#ifdef SKIP_ASM
struct sKey_9A78 {
    short x;                        // 0x0
    unsigned short id;              // 0x2
    short y;                        // 0x4
    unsigned short idA;             // 0x6
    short z;                        // 0x8
    unsigned short idB;             // 0xA
};

struct sEnt_9A78 {
    int type;
    sKey_9A78* key;
};

static inline int iabs_9A78(int v)
{
    return v < 0 ? -v : v;
}

// Compares two entries' keys; type 3 (and inexact 1/2) allow position tolerances and swapped ends.
extern "C" int func_00369A78(void* ap, void* bp, int tol0, int tol1, int tol2)
{
    sEnt_9A78* a = (sEnt_9A78*)ap;
    sEnt_9A78* b = (sEnt_9A78*)bp;
    if (a->type != b->type)
        goto fail;
    if (a->key->id != b->key->id)
        goto fail;
    switch (a->type) {
    case 1:
        if (a->key->x == b->key->x)
            return 1;
        break;
    case 2:
        if (a->key->x == b->key->x && a->key->idA == b->key->idA && a->key->y == b->key->y)
            return 1;
        break;
    case 3:
        break;
    default:
        goto fail;
    }
    if (a->key->idA == b->key->idA && a->key->idB == b->key->idB) {
        if (iabs_9A78(a->key->x - b->key->x) > tol0 || iabs_9A78(a->key->y - b->key->y) > tol1 || iabs_9A78(a->key->z - b->key->z) > tol2)
            goto fail;
        return 1;
    }
    if (a->key->idB == b->key->idA && a->key->idA == b->key->idB) {
        if (iabs_9A78(a->key->x - b->key->x) <= tol0 && iabs_9A78(a->key->z - b->key->y) <= tol1 && iabs_9A78(a->key->y - b->key->z) <= tol2)
            return 1;
    }
fail:
    return 0;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00369C28);
#ifdef SKIP_ASM
extern char* D_004A5B64;
extern "C" void SYNCTASK_run(int a);
extern "C" void func_003E5398(int a);

struct sGmVEntryI_9C28 {
    short delta;
    short index;
    int (*fn)(void*);
};

class cGmApp_9C28 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};

extern "C" void func_00369C28(void* self)
{
    for (;;) {
        sGmVEntryI_9C28* vt = *(sGmVEntryI_9C28**)((char*)self + 0x10D8);
        if (vt[18].fn((char*)self + vt[18].delta) != 0) break;
        (*(cGmApp_9C28**)(D_004A5B64 + 0x8))->v11();
        SYNCTASK_run(0);
        func_003E5398(0);
        (*(cGmApp_9C28**)(D_004A5B64 + 0x8))->v12();
    }
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00369CB0);
#ifdef SKIP_ASM
struct sGfxVEntry95 {
    short delta;
    short index;
    void (*fn)(void*, void*, int, void*, int, int, int, float);
};

extern "C" void func_00369CB0(void* self, void* obj, int a2, int a3, int a4)
{
    sGfxVEntry95* vt = *(sGfxVEntry95**)((char*)self + 0x10D8);
    vt[95].fn((char*)self + vt[95].delta, obj, *(int*)((char*)obj + 0x94), (char*)obj + 0x10, a2, a3, a4, 1.0f);
}
#endif

INCLUDE_ASM("render/graphicsman", func_00369CF8);

//100%
INCLUDE_ASM("render/graphicsman", func_00369FF0__FPv);
#ifdef SKIP_ASM
void func_00369FF0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00369FF8);
#ifdef SKIP_ASM
extern "C" void func_00369FF8(void* self)
{
    char* vt = *(char**)((char*)self + 0x10D8);
    ((void (*)(void*))*(void**)(vt + 0x3CC))((char*)self + *(short*)(vt + 0x3C8));
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036A020);
#ifdef SKIP_ASM
extern "C" void func_0036A020(void* self)
{
    char* vt = *(char**)((char*)self + 0x10D8);
    ((void (*)(void*))*(void**)(vt + 0x3C4))((char*)self + *(short*)(vt + 0x3C0));
}
#endif

INCLUDE_ASM("render/graphicsman", func_0036A048);

extern "C" void* func_0036A1C0(int);

//100%
INCLUDE_ASM("render/graphicsman", func_0036A190__FPvi);
#ifdef SKIP_ASM
void* func_0036A190(void* self, int a1)
{
    return func_0036A1C0(a1);
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036A1B0__FPvT0);
#ifdef SKIP_ASM
int func_0036A1B0(void* self, void* a1)
{
    int t0 = -1;
    *(int*)a1 = 0;
    *(int*)((char*)a1 + 0x4) = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036A1C0);
#ifdef SKIP_ASM
extern int D_004A5B88;
extern void* D_0053AB40[];

// PORT: the unit declares this (int) returning void*; the arg is a list node pointer.
extern "C" void* func_0036A1C0(int n)
{
    void** node = (void**)n;
    void** head = &D_0053AB40[D_004A5B88];
    *node = *head;
    *head = node;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036A1E8);
#ifdef SKIP_ASM
extern int D_004A5B88;
extern void* D_0053AB40[];

class cGmNode_A1E8 {
public:
    cGmNode_A1E8* next;
    virtual ~cGmNode_A1E8();
};

extern "C" void func_0036A1E8()
{
    D_004A5B88 = (D_004A5B88 + 1) % 4;
    cGmNode_A1E8* n = (cGmNode_A1E8*)D_0053AB40[D_004A5B88];
    while (n != 0) {
        cGmNode_A1E8* next = n->next;
        delete n;
        n = next;
    }
    D_0053AB40[D_004A5B88] = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/graphicsman", func_0036A290);
#ifdef SKIP_ASM
extern "C" void func_0036A1E8();

extern "C" void func_0036A290()
{
    int i;
    for (i = 0; i < 4; i++)
        func_0036A1E8();
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036A2C0);
#ifdef SKIP_ASM
struct sGmVec4_A2C0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sGmMtx_A2C0 {
    sGmVec4_A2C0 r[4];
};

extern "C" sGmMtx_A2C0* func_0038F2A8(sGmVec4_A2C0* pos);

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply out = a * b); the PC port needs a plain multiply.
static inline void gmMtxMul_A2C0(sGmMtx_A2C0* out, sGmMtx_A2C0* a, sGmMtx_A2C0* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(out), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (64-byte matrix copy); the PC port needs a plain copy.
static inline void gmMtxCopy_A2C0(sGmMtx_A2C0* dst, sGmMtx_A2C0* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

extern "C" void func_0036A2C0(void* self, sGmMtx_A2C0* m)
{
    if (*(int*)((char*)self + 0xA4) != 0) {
        sGmMtx_A2C0 t2;
        sGmVec4_A2C0 pos = m->r[3];
        sGmMtx_A2C0 tmp;
        sGmMtx_A2C0* r = func_0038F2A8(&pos);
        gmMtxMul_A2C0(&tmp, m, r);
        gmMtxCopy_A2C0(&t2, &tmp);
        gmMtxCopy_A2C0(m, &t2);
    }
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036A3B0);
#ifdef SKIP_ASM
extern "C" int func_0036A3B0(int arg0) {
    int temp_2;
    int temp_2_2;
    int temp_2_3;

    temp_2_2 = arg0 & 0xFF;
    temp_2_3 = (temp_2_2 | (temp_2_2 * 0x10)) & 0xF0F;
    temp_2 = (temp_2_3 | (temp_2_3 * 4)) & 0x3333;
    return (temp_2 | (temp_2 * 2)) & 0x5555;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036A3E0);
#ifdef SKIP_ASM
extern "C" int func_0036A3E0(unsigned short x, unsigned short y) {
    int a = func_0036A3B0(x);
    return a | (func_0036A3B0(y) << 1);
}
#endif
INCLUDE_ASM("render/graphicsman", func_0036A428);

//100%
INCLUDE_ASM("render/graphicsman", func_0036AA60);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here (GIF/DMA packet words); cQuad128 is a 128-bit GPR quadword.
extern "C" void func_0036AA60(void* self, int x, int y, char** pp)
{
    *(cQuad128*)(*pp + 0x00) = 0x10000006;
    *(ulong*)(*pp + 0x10) = ((ulong)0x10000000 << 32) | 4;
    *(ulong*)(*pp + 0x18) = 0xE;
    *(ulong*)(*pp + 0x20) = ((ulong)y << 32) | ((ulong)0x8000 << 33);
    *(ulong*)(*pp + 0x28) = 0x50;
    *(ulong*)(*pp + 0x30) = 0;
    *(ulong*)(*pp + 0x38) = 0x51;
    *(ulong*)(*pp + 0x40) = ((ulong)0x10 << 32) | 0x10;
    *(ulong*)(*pp + 0x48) = 0x52;
    *(ulong*)(*pp + 0x50) = 0;
    *(ulong*)(*pp + 0x58) = 0x53;
    *(cQuad128*)(*pp + 0x60) = ((cQuad128)0x08000000 << 32) | 0x40;
    *(ulong*)(*pp + 0x70) = ((ulong)x << 32) | 0x30000040;
    *(ulong*)(*pp + 0x78) = 0;
    *(cQuad128*)(*pp + 0x80) = 0x10000002;
    *(ulong*)(*pp + 0x90) = ((ulong)0x10000000 << 32) | 1;
    *(ulong*)(*pp + 0x98) = 0xE;
    *(ulong*)(*pp + 0xA0) = 0;
    *(ulong*)(*pp + 0xA8) = 0x3F;
    *pp += 0xB0;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036ABA0);
#ifdef SKIP_ASM
extern float D_004A432C;
extern float D_004A4330;
extern int D_004A4334;
extern float D_004A4338;

struct sGmQuad_ABA0 {
    int v[4];
};
extern sGmQuad_ABA0 D_00504720;

struct sGmEntry_ABA0 {
    float x;            // 0x0
    float y;            // 0x4
    int z;              // 0x8
    float w;            // 0xC
    sGmQuad_ABA0 q;     // 0x10
};

struct sGmOwner_ABA0 {
    char pad[0x6C64];
    sGmEntry_ABA0 entries[1];
};

extern "C" void func_0036ABA0(void* self, int idx)
{
    char* e = (char*)&((sGmOwner_ABA0*)self)->entries[idx];
    *(float*)(e + 0x0) = D_004A432C;
    *(float*)(e + 0x4) = D_004A4330;
    *(int*)(e + 0x8) = D_004A4334;
    *(float*)(e + 0xC) = D_004A4338;
    *(sGmQuad_ABA0*)(e + 0x10) = D_00504720;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/graphicsman", func_0036AC00);
#ifdef SKIP_ASM
extern int D_004A4324;
extern int D_004A4328;
extern void* D_004A4474;
extern char D_00507B80[];
extern "C" void func_0036ABA0(void* self, int idx);
extern "C" void func_0036A428(void* self, void* mat, int idx);
extern "C" char* func_0038F460(void* self, unsigned int addr, int size, int flags);
extern "C" int func_0038F668(void* self, char* end, int arg);
extern "C" int func_00366CE0(void* self, int size, int owner, int skipB, int level, int align);
extern "C" void func_0036AA60(void* self, int x, int y, char** pp);
extern "C" void func_0036AE20(void* self, int idx, int a, int b, int n, char** pp);
extern "C" void func_0036B158(void* self, int idx, int y, char** pp);
extern "C" void func_003663D8(void* self, int id);
extern "C" void func_00368138(void* self, void* pkt);

struct sGmEntry_AC00 {
    float x;            // 0x0
    float y;            // 0x4
    int z;              // 0x8
    float w;            // 0xC
    int q[4];           // 0x10
};

struct sGmOwner_AC00 {
    char pad[0x6C64];
    sGmEntry_AC00 entries[1];
};

struct sGmVEntry_AC00 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0036AC00(char* self, int idx, void* pkt2, int* handle)
{
    if (D_004A4324 == 0) {
        return;
    }
    if (D_004A4328 != 0) {
        func_0036ABA0(self, idx);
    }
    sGmEntry_AC00* e = &((sGmOwner_AC00*)self)->entries[idx];
    if (e->w == 0.0f && e->z != 0) {
        return;
    }
    char* mat = D_00507B80 + (idx << 10);
    func_0036A428(self, mat, idx);
    void* dma = D_004A4474;
    char* pkt = func_0038F460(dma, *handle, -1, 0);
    int slot = func_00366CE0(*(char**)(self + 0x18F4) + 0x1F60, 0x400, 0x7FFFFFFF, 0, 0, 1);
    int* rec = (int*)(*(char**)(*(char**)(self + 0x18F4) + 0x3F50) + slot * 0x1C);
    // PORT: the packet builder takes the matrix block's address as an int.
    func_0036AA60(self, (int)mat, *rec >> 8, &pkt);
    *handle = func_0038F668(dma, pkt, 4);
    pkt = func_0038F460(dma, *handle, -1, 0);
    int a = *(int*)(self + 0x5A80);
    int b = *(int*)(self + 0x5A84);
    sGmVEntry_AC00* vt = *(sGmVEntry_AC00**)(self + 0x10D8);
    int n = vt[11].fn(self + vt[11].delta);
    func_0036AE20(self, idx, a, b, n * 2, &pkt);
    *handle = func_0038F668(dma, pkt, 4);
    pkt = func_0038F460(dma, *handle, -1, 0);
    func_0036B158(self, idx, *rec >> 8, &pkt);
    *handle = func_0038F668(dma, pkt, 4);
    func_003663D8(*(char**)(self + 0x18F4) + 0x1F60, slot);
    func_00368138(*(char**)(self + 0x18F4), pkt2);
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036AE20);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here (GIF/DMA packet words).
struct sGmVE_AE20 {
    short delta;
    short index;
    unsigned int (*fn)(void*);
};

static inline unsigned int gmCall_AE20(char* self, int slot)
{
    sGmVE_AE20* vt = *(sGmVE_AE20**)(self + 0x10D8);
    return vt[slot].fn(self + vt[slot].delta);
}

extern "C" void func_0036AE20(void* vself, int idx, int a, int b, int n, char** pp)
{
    char* self = (char*)vself;
    unsigned int full = 0x1000;
    int w = *(int*)(self + 0x5A30);
    int h = *(int*)(self + 0x5A34);
    int offX = ((full - gmCall_AE20(self, 10)) >> 1) << 4;
    int offY = ((full - gmCall_AE20(self, 11)) >> 1) << 4;
    int cols = w / 8;
    int zbp = *(int*)(self + 0x5A80);
    ulong* p = (ulong*)*pp;
    p += 2;
    p[0] = (cols * 2 + 11) | ((ulong)0x8000 << 45);
    p[1] = 0xE;
    unsigned int fbw = gmCall_AE20(self, 10) >> 6;
    p[2] = b | ((ulong)fbw << 16) | ((ulong)0x3FFF0200 << 16);
    p[3] = 0x4C;
    p[4] = (ulong)(unsigned int)(zbp | 0x1000000) | ((ulong)0x8000 << 17);
    p[5] = 0x4E;
    p[6] = 0x30000;
    p[7] = 0x47;
    p[8] = offX | ((ulong)offY << 32);
    p[9] = 0x18;
    p[10] = ((ulong)(w - 1) << 16) | ((ulong)(h * 2 - 1) << 48);
    p[11] = 0x40;
    p[12] = 0;
    p[13] = 0x3F;
    p[14] = (ulong)0x8000 << 24;
    p[15] = 0x3B;
    p[16] = 0;
    p[17] = 0x14;
    unsigned int tbw = gmCall_AE20(self, 10) >> 6;
    p[18] = (a << 5) | ((ulong)tbw << 14) | ((ulong)0xEAB2 << 20);
    p[19] = 6;
    p[20] = 0x116;
    p[21] = 0;
    p[22] = 0x3F80000080808080;
    p[23] = 1;
    p += 24;
    for (int i = 0; i < cols; i += 2) {
        int j = i * 0x80;
        int x0 = offX + 0x80 + j;
        int x1 = offX + 0x100 + j;
        int u0 = 8 + j;
        int u1 = 0x88 + j;
        p[0] = u0 | 0x80000;
        p[1] = 3;
        p[2] = x0 | ((ulong)offY << 16);
        p[3] = 5;
        p[4] = u1 | ((ulong)(n * 16 + 8) << 16);
        p[5] = 3;
        p[6] = x1 | ((ulong)(offY + n * 16) << 16);
        p[7] = 5;
        p += 8;
    }
    *(ulong*)*pp = ((p - (ulong*)*pp) / 2 - 1) | 0x10000000;
    ((ulong*)*pp)[1] = 0;
    *pp = (char*)p;
}
#endif

INCLUDE_ASM("render/graphicsman", func_0036B158);

INCLUDE_ASM("render/graphicsman", func_0036B5E8);

INCLUDE_ASM("render/graphicsman", func_0036B9D8);

INCLUDE_ASM("render/graphicsman", func_0036C188);

INCLUDE_ASM("render/graphicsman", func_0036C398);

//100%
INCLUDE_ASM("render/graphicsman", func_0036C740);
#ifdef SKIP_ASM
extern float D_004A43D4;
extern float D_004A43D8;
extern float D_004A43DC;
extern float D_004A43E0;
extern float D_004A43E4;
extern float D_004A43F0;
extern float D_004A43F4;

struct sGmEntry_C740 {
    float v[7];
};

struct sGmOwner_C740 {
    char pad[0x6CD4];
    sGmEntry_C740 entries[1];
};

extern "C" void func_0036C740(void* self, int idx)
{
    char* e = (char*)&((sGmOwner_C740*)self)->entries[idx];
    *(float*)(e + 0x0) = D_004A43D4;
    *(float*)(e + 0x4) = D_004A43D8;
    *(float*)(e + 0x8) = D_004A43DC;
    *(float*)(e + 0xC) = D_004A43E0;
    *(float*)(e + 0x10) = D_004A43E4;
    *(float*)(e + 0x14) = D_004A43F0;
    *(float*)(e + 0x18) = D_004A43F4;
}
#endif

INCLUDE_ASM("render/graphicsman", func_0036C790);

//100%
INCLUDE_ASM("render/graphicsman", func_0036CBF8);
#ifdef SKIP_ASM
struct sGfxVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern cQuad128 D_004FF120;

// PORT: PS2-only VU0 inline asm (vector divided by scalar).
static inline sGfxVec4 vu0DivGM(const sGfxVec4& v, float s)
{
    sGfxVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

extern "C" void func_0036CBF8(char* self, int w, int h, float x, float y, float s, sGfxVec4* v)
{
    *(int*)(self + 0x0) = w;
    *(int*)(self + 0x4) = h;
    *(float*)(self + 0xC) = x * s / (float)w;
    *(sGfxVec4*)(self + 0x60) = vu0DivGM(vu0DivGM(*v, s), s);
    *(float*)(self + 0x4C) = s;
    *(float*)(self + 0x30) = 1.0f / (float)*(int*)(self + 0x4);
    *(float*)(self + 0x34) = y * s;
    sGfxVec4 one;
    one.x = 1.0f;
    one.y = 1.0f;
    one.z = 0.0f;
    one.w = 0.0f;
    *(cQuad128*)(self + 0x130) = D_004FF120;
    *(sGfxVec4*)(self + 0x140) = one;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036CCB8);
#ifdef SKIP_ASM
int BXrand();

static inline float randf_0036CCB8(float a, float b)
{
    union { int i; float f; } u;
    u.i = (BXrand() & 0x7FFFFF) | 0x3F800000;
    return a + (b - a) * (u.f - 1.0f);
}

extern "C" void func_0036CCB8(char* self)
{
    *(float*)(self + 0x38) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x3C) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x40) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x44) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x48) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x50) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x54) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x58) = randf_0036CCB8(1.0f, 2.0f);
    *(float*)(self + 0x5C) = randf_0036CCB8(1.0f, 2.0f);
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036CE00);
#ifdef SKIP_ASM
extern "C" void func_0036CE00(void* self, float a, float b, float c)
{
    *(float*)((char*)self + 0x10) = c;
    *(float*)((char*)self + 0x20) = b - a;
    *(float*)((char*)self + 0x18) = a - c * 1.5f;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036CE28);
#ifdef SKIP_ASM
extern "C" void func_0036CE28(void* self, float a, float b)
{
    float d = b - a;
    float s = *(float*)((char*)self + 0x4c);
    a = a * s;
    d = d * s;
    *(float*)((char*)self + 0x14) = d;
    *(float*)((char*)self + 0x1c) = a - d;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036CE48);
#ifdef SKIP_ASM
extern "C" void func_0036CE48(void *arg0) {
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(float *)((char*)(arg0) + (0x1C))) = 1e20f;
}
#endif
//100%
INCLUDE_ASM("render/graphicsman", func_0036CE58);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_0036CE58(void *arg0, long long *arg1) {
    (*(long long *)((char*)(arg0) + (0xB0))) = (long long) *arg1;
    (*(long long *)((char*)(arg0) + (0xC0))) = (long long) D_004FF120;
    (*(long long *)((char*)(arg0) + (0xD0))) = (long long) D_004FF120;
}
#endif
//100%
INCLUDE_ASM("render/graphicsman", func_0036CE80);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (a - b). Same body as vu0SubGM (defined later in the unit).
static inline sGfxVec4 vu0Sub_CE80(const sGfxVec4& a, const sGfxVec4& b)
{
    sGfxVec4 r;
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

// PORT: PS2-only VU0 inline asm (v * s). Same body as vu0ScaleGM (defined later in the unit).
static inline sGfxVec4 vu0Scale_CE80(const sGfxVec4& v, float s)
{
    sGfxVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

extern "C" void func_0036CE80(char* self, sGfxVec4* a, sGfxVec4* b)
{
    *(sGfxVec4*)(self + 0xB0) = vu0Sub_CE80(vu0Scale_CE80(*a, 2.0f), *b);
    *(sGfxVec4*)(self + 0xC0) = vu0Sub_CE80(*b, *a);
    *(cQuad128*)(self + 0xD0) = D_004FF120;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036CEF8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector add).
static inline sGfxVec4 vu0AddGM(const sGfxVec4& a, const sGfxVec4& b)
{
    sGfxVec4 r;
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sGfxVec4 vu0SubGM(const sGfxVec4& a, const sGfxVec4& b)
{
    sGfxVec4 r;
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sGfxVec4 vu0ScaleGM(const sGfxVec4& v, float s)
{
    sGfxVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

extern "C" void func_0036CEF8(char* self, sGfxVec4* a, sGfxVec4* b, sGfxVec4* c)
{
    *(sGfxVec4*)(self + 0xB0) = vu0SubGM(*a, vu0ScaleGM(vu0AddGM(*b, *c), 3.0f));
    *(sGfxVec4*)(self + 0xC0) = vu0ScaleGM(*b, 2.0f);
    *(sGfxVec4*)(self + 0xD0) = vu0ScaleGM(*c, 2.0f);
}
#endif

extern cQuad128 D_004FF120;

//100%
INCLUDE_ASM("render/graphicsman", func_0036CFA8);
#ifdef SKIP_ASM
extern "C" void func_0036CFA8(char* self, sGfxVec4* v, float s)
{
    *(sGfxVec4*)(self + 0xE0) = vu0DivGM(vu0ScaleGM(*v, *(float*)(self + 0xC)), s * *(float*)(self + 0x4C));
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036D008);
#ifdef SKIP_ASM
extern "C" void func_0036D008(void* self)
{
    *(cQuad128*)((char*)self + 0xe0) = D_004FF120;
}
#endif

INCLUDE_ASM("render/graphicsman", func_0036D020);

//100%
INCLUDE_ASM("render/graphicsman", func_0036D1F0);
#ifdef SKIP_ASM
struct sGmVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sGmFrustum {
    char pad_0x00[0x4C];
    float scale;        // 0x4C
    char pad_0x50[0x20];
    sGmVec4 v70;        // 0x70
    sGmVec4 v80;        // 0x80
    sGmVec4 v90;        // 0x90
    sGmVec4 vA0;        // 0xA0
};

// PORT: PS2-only VU0 inline asm (v / s).
static inline sGmVec4 gmDivD1F0(const sGmVec4& v, float s)
{
    sGmVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a + b).
static inline sGmVec4 gmAddD1F0(const sGmVec4& a, const sGmVec4& b)
{
    sGmVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sGmVec4 gmSubD1F0(const sGmVec4& a, const sGmVec4& b)
{
    sGmVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (v * s).
static inline sGmVec4 gmScaleD1F0(const sGmVec4& v, float s)
{
    sGmVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

extern "C" void func_0036D1F0(sGmFrustum* self, const sGmVec4* a, const sGmVec4* b,
                              const sGmVec4* c, const sGmVec4* d)
{
    self->v80 = gmDivD1F0(*b, self->scale);
    self->v90 = gmDivD1F0(*c, self->scale);
    self->vA0 = gmDivD1F0(*d, self->scale);
    self->v70 = gmSubD1F0(gmDivD1F0(*a, self->scale), gmScaleD1F0(gmAddD1F0(gmAddD1F0(self->v80, self->v90), self->vA0), 1.5f));
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036D318);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector add).
// PORT: PS2-only VU0 inline asm (vector subtract).
// PORT: PS2-only VU0 inline asm (vector times scalar).
// PORT: PS2-only VU0 inline asm (vector divided by scalar).
extern "C" void func_0036D318(char* self, sGfxVec4* a, sGfxVec4* b, sGfxVec4* c, sGfxVec4* d, float t)
{
    *(sGfxVec4*)(self + 0xF0) = vu0SubGM(*a, vu0ScaleGM(vu0AddGM(*c, *d), 1.5f));
    *(sGfxVec4*)(self + 0x120) = vu0DivGM(vu0SubGM(*b, *a), t * *(float*)(self + 0x4C));
    *(sGfxVec4*)(self + 0x100) = *c;
    *(sGfxVec4*)(self + 0x110) = *d;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036D3D8);
#ifdef SKIP_ASM
extern "C" void func_0036D3D8(void* self, float val)
{
    *(float*)((char*)self + 0x8) = val * *(float*)((char*)self + 0x4c);
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036D3E8);
#ifdef SKIP_ASM
extern "C" void func_0036D3E8(void* self, float val)
{
    *(float*)((char*)self + 0x8) += val * *(float*)((char*)self + 0x4c);
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_0036D400);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 random-number unit (R register); the PC port needs a C PRNG.
extern "C" void func_0036D400(float* seed)
{
    float v = *seed;
    __asm__ __volatile__(
        "qmtc2.ni  %0, $vf3\n"
        "vrinit    R, $vf3x\n"
        "vrnext.x  $vf3, R\n"
        "qmfc2.ni  %0, $vf3\n"
        : "=r"(v)
        : "0"(v));
    *seed = v;
}
#endif

INCLUDE_ASM("render/graphicsman", func_0036D428);

INCLUDE_ASM("render/graphicsman", func_0036D500);

//100%
INCLUDE_ASM("render/graphicsman", func_00370018);
#ifdef SKIP_ASM
extern char D_00493160[];
void func_002F7A68(void*);

extern "C" void* func_00370018(void* self)
{
    *(void**)((char*)self + 0x18C) = D_00493160;
    func_002F7A68((char*)self + 0x10);
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x184) = 0;
    return self;
}
#endif

INCLUDE_ASM("render/graphicsman", func_00370058);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/graphicsman", func_003705E0);
#ifdef SKIP_ASM
extern "C" void func_00370058(void* gfx, void* a1, void* desc, void* out, float f);

extern "C" void func_003705E0(char* self, void* a1, char* d)
{
    *(int*)(self + 0x180) = *(int*)(d + 0xD0);
    *(float*)(self + 0x188) = *(float*)(d + 0xD4);
    *(int*)(self + 0x4) = *(int*)(d + 0xC4);
    *(int*)(self + 0x8) = *(int*)(d + 0xC8);
    float t = *(float*)(d + 0x8);
    float r;
    if (t < 0.0f) {
        r = t;
    } else {
        r = t + *(float*)(d + 0x14) + *(float*)(d + 0x1C) * 0.5f;
    }
    *(float*)(self + 0x0) = r;
    float x = *(float*)(d + 0x8) >= 0.0f ? *(float*)(d + 0x8) : *(float*)(d + 0x14) + *(float*)(d + 0x1C) * 0.5f;
    sGfxVec4 v;
    v.x = *(float*)(d + 0x78);
    v.y = *(float*)(d + 0x7C);
    v.z = *(float*)(d + 0x80);
    v.w = 0.0f;
    func_0036CBF8(self + 0x10, *(int*)(d + 0x0), *(int*)(d + 0x4), x, *(float*)(d + 0x20), *(float*)(d + 0xC), &v);
    func_00370058(self + 0x10, a1, d, self + 0x160, -1.0f);
}
#endif

INCLUDE_ASM("render/graphicsman", func_00370708);

//100%
INCLUDE_ASM("render/graphicsman", func_00370758);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_00493160[];

extern "C" void func_00370758(int* self, int flags)
{
    *(void**)((char*)self + 0x18C) = D_00493160;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/graphicsman", func_00370788);
#ifdef SKIP_ASM
extern "C" void func_0036D428(void* self, float val);

extern "C" void func_00370788(char* self, float dt)
{
    float t = *(float*)(self + 0x0);
    if (t == 0.0f) {
        return;
    }
    if (t < 0.0f) {
        func_0036D428(self + 0x10, 1.0f / (float)*(int*)(D_004A5B64 + 0x10));
    } else {
        func_0036D3E8(self + 0x10, 1.0f / (float)*(int*)(D_004A5B64 + 0x10));
        *(float*)(self + 0x0) -= 1.0f / (float)*(int*)(D_004A5B64 + 0x10);
        if (*(float*)(self + 0x0) < 0.0f) {
            *(float*)(self + 0x0) = 0.0f;
        }
    }
    float v = *(float*)(self + 0x184) + *(float*)(self + 0x188) * dt;
    *(float*)(self + 0x184) = v;
    if ((int)v >= *(int*)(self + 0x180)) {
        *(float*)(self + 0x184) = 0.0f;
    }
    *(int*)(self + 0xC) = 1;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00370888);
#ifdef SKIP_ASM
struct sGmQuad {
    float v[4];
} __attribute__((aligned(16)));

struct sGmQuad2 {
    sGmQuad a;
    sGmQuad b;
};

extern "C" void func_003708C0(void* self);

extern "C" void func_00370888(void* self, const sGmQuad2* m, const sGmQuad* v)
{
    *(sGmQuad2*)((char*)self + 0x160) = *m;
    *(sGmQuad*)((char*)self + 0xC0) = *v;
    func_003708C0(self);
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_003708C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sGfxRS_708C0 {
    int field_0x0;          // 0x0
    int flagsA;             // 0x4, bits 2..6 = layer
    int flagsB;             // 0x8, bits 5..9 = blend
    int field_0xC;          // 0xC
    short tex;              // 0x10
    short pad;
};

struct sGfxMat_708C0 {
    float m[4][4];
};

struct sGfxVEntry_708C0 {
    short delta;
    short index;
    void* fn;
};

struct sGfxCtx_708C0 {
    char pad_0x0[0xE84];
    sGfxRS_708C0* top;          // 0xE84
    char pad_0xE88[0xF50 - 0xE88];
    int texIds[(0x10D8 - 0xF50) / 4];   // 0xF50
    sGfxVEntry_708C0* vtable;   // 0x10D8
};

extern sGfxCtx_708C0* D_004A5B80_708C0 __asm__("D_004A5B80");
extern int D_0044B420[];

typedef sGfxMat_708C0 (*tGetMat_708C0)(void*);
typedef int (*tCull_708C0)(void*, void*, void*, const sGfxMat_708C0&);
typedef void (*tDraw_708C0)(void*, void*);

struct sGfxObj_708C0 {
    char pad_0x0[0x4];
    int base;               // 0x4
    int kind;               // 0x8
    int visible;            // 0xC
};

static inline int GetTexId_708C0(int i)
{
    return D_004A5B80_708C0->texIds[i];
}

extern "C" void func_003708C0(void* selfp)
{
    char* self = (char*)selfp;
    sGfxCtx_708C0* g = D_004A5B80_708C0;
    sGfxVEntry_708C0* vt = g->vtable;
    if (((tCull_708C0)vt[93].fn)((char*)g + vt[93].delta, self + 0x160, self + 0x170,
                                 ((tGetMat_708C0)vt[43].fn)((char*)g + vt[43].delta)) == 1) {
        return;
    }
    if (((sGfxObj_708C0*)self)->visible == 0) {
        return;
    }
    int layer = D_0044B420[((sGfxObj_708C0*)self)->kind];
    g->top[1] = g->top[0];
    sGfxRS_708C0* prev = g->top;
    g->top = prev + 1;
    prev[1].flagsB = (prev[1].flagsB & ~0x3E0) | 0xE0;
    g->top->flagsA = (g->top->flagsA & 0xFFBFFFFF) | 0x400000;
    g->top->flagsA = g->top->flagsA & 0xFE7FFFFF;
    g->top->flagsA = g->top->flagsA & 0xFFCFFFFF;
    g->top->flagsA = (g->top->flagsA & 0xFFF00FFF) | 0x14000;
    g->top->flagsA = (g->top->flagsA & ~0x7C) | ((layer << 2) & 0x7C);
    g->top->tex = GetTexId_708C0(((sGfxObj_708C0*)self)->base + (int)*(float*)(self + 0x184));
    sGfxVEntry_708C0* vt2 = g->vtable;
    ((tDraw_708C0)vt2[82].fn)((char*)g + vt2[82].delta, self + 0x10);
    g->top--;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00370AA8);
#ifdef SKIP_ASM
struct sGmSerVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sGmSerObj {
    sGmSerVEntry* vt;
};

struct sGmSer12 {
    float a;
    float b;
    int c;
};

extern "C" void func_00370AA8(void* self, sGmSerObj* out)
{
    sGmSer12 buf;
    buf.a = *(float*)((char*)self + 0x0);
    buf.b = *(float*)((char*)self + 0x18);
    buf.c = *(int*)((char*)self + 0xC);
    out->vt[1].fn((char*)out + out->vt[1].delta, &buf, 12);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/graphicsman", func_00370AF8);
#ifdef SKIP_ASM
class cStream00370AF8 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

extern "C" void func_0036D500(void* a, void* b);

extern "C" void func_00370AF8(void* self, cStream00370AF8* stream)
{
    struct {
        float a;
        float b;
        int c;
    } buf;
    stream->v02(&buf, 0xC);
    *(float*)((char*)self + 0x0) = buf.a;
    *(float*)((char*)self + 0x18) = buf.b;
    func_0036D500((char*)self + 0x10, (char*)self + 0x160);
    *(int*)((char*)self + 0xC) = buf.c;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00370B60);
#ifdef SKIP_ASM
void func_002F7A68(void*);
extern "C" void* func_00416210(void* dst, int c, int n);
extern void* D_00493118[];

struct sGmView_0B60 {
    char pad_0x0[0xC];
    int field_0xc;          // 0xC
    int field_0x10;         // 0x10
    int field_0x14;         // 0x14
    char pad_0x18[0x158];
    int field_0x170;        // 0x170
    int field_0x174;        // 0x174
    int field_0x178;        // 0x178
    int field_0x17c;        // 0x17C
    char pad_0x180[0x20];
    int field_0x1a0;        // 0x1A0
    int field_0x1a4;        // 0x1A4
    char pad_0x1a8[0x38];
    int field_0x1e0;        // 0x1E0
    char block[0x10];       // 0x1E4
    short ids[2];           // 0x1F4
    void** vtable;          // 0x1F8
};

extern "C" sGmView_0B60* func_00370B60(sGmView_0B60* self)
{
    self->field_0xc = 0;
    self->field_0x10 = 0;
    self->field_0x14 = 0;
    self->vtable = D_00493118;
    func_002F7A68((char*)self + 0x20);
    self->field_0x170 = 0;
    self->field_0x174 = 1;
    self->field_0x178 = -1;
    self->field_0x17c = 0;
    self->field_0x1a0 = 0;
    self->field_0x1a4 = 0;
    self->field_0x1e0 = 0;
    char* blk = self->block;
    for (unsigned int i = 0; i < 2; i++) {
        self->ids[i] = -1;
    }
    func_00416210(blk, 0, 0x10);
    return self;
}
#endif

//100%
INCLUDE_ASM("render/graphicsman", func_00370C08);
#ifdef SKIP_ASM
extern "C" void func_00370CF8(void* self, int flag);
void operator_delete(int* ptr);
extern void* D_00493118[];

extern "C" void func_00370C08(void* self, int flags)
{
    *(void***)((char*)self + 0x1F8) = D_00493118;
    func_00370CF8(self, 1);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

