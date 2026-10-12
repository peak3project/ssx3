#include "common.h"

//100%
INCLUDE_ASM("render/ps2graphicsman", cPSPGraphicsMan_NewNonBindTexID);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00492068[];

struct cTexSlots367150 {
    int unk_0x0;
    int count;
    void* slots[2000];
    void** freeHead;
};

extern "C" int cPSPGraphicsMan_NewNonBindTexID(cTexSlots367150* self)
{
    void** head = self->freeHead;
    int id = head - self->slots;
    self->freeHead = (void**)*head;
    self->count++;
    char* tex = (char*)self + 8;
    void** slot = (void**)(tex + (id << 2));
    *slot = cMemMan_alloc(0x58, D_00492068, 0x21000000, 0);
    return id;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003671C8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

struct cTexSlots3671C8 {
    int unk_0x0;
    int count;
    void* slots[2000];
    void* freeHead;
};

extern "C" void func_003671C8(cTexSlots3671C8* self, int id)
{
    operator_delete((int*)self->slots[id]);
    self->slots[id] = self->freeHead;
    self->freeHead = &self->slots[id];
    self->count--;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367230);
#ifdef SKIP_ASM
extern "C" void func_00367230(void)
{
    for (int i = 0; i < 500; i++) {
    }
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", cPSPGraphicsMan_NewBindTexID);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00492078[];

extern "C" void cPSPGraphicsMan_NewBindTexID(void* self, int id)
{
    char* tex = (char*)self + 8;
    void** slot = (void**)(tex + (id << 2));
    *slot = cMemMan_alloc(0x58, D_00492078, 0x21000000, 0);
    *(int*)self += 1;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003672C0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

struct sGmPtrTable {
    int count;
    int pad_0x4;
    int* entries[1];
};

extern "C" void func_003672C0(sGmPtrTable* self, int idx)
{
    int** base = self->entries; int** e = base + idx;
    operator_delete(*e);
    *e = 0;
    self->count--;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367310);
#ifdef SKIP_ASM
extern "C" void func_00367310(void)
{
    for (int i = 0; i < 1500; i++) {
    }
}
#endif

extern "C" void* func_00365E40(void*, int, int, void*);

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367340__FPvii);
#ifdef SKIP_ASM
void* func_00367340(void* self, int a1, int a2)
{
    return func_00365E40((char*)self + 0x4350, a1, a2, (char*)self + 0x8);
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367360);
#ifdef SKIP_ASM
extern "C" void func_00366548(void* p);
// PORT: the unit defines func_00367310(void), but this caller passes self.
void func_00367310_1(void* self) __asm__("func_00367310");

extern "C" void func_00367360(void* self)
{
    int i;
    func_00367230();
    func_00367310_1(self);
    func_00366548((char*)self + 0x1F60);
    func_00366548((char*)self + 0x4350);
    for (i = 1; i >= 0; i--) {
        ((int*)((char*)self + 0x1F4C))[i] = -1;
    }
    *(int*)((char*)self + 0x1F54) = -1;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003673D0__FPv);
#ifdef SKIP_ASM
void func_003673D0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003673D8);
#ifdef SKIP_ASM
extern "C" int func_00366CE0(void* heap, int size, int idx, int other, int a4, int a5);

// Allocates a block in the texture heap and marks the matching entry as resident and locked.
extern "C" int func_003673D8(char* self, int size)
{
    int idx = func_00366CE0(self + 0x1F60, size, -1, -1, -1, 1);
    char* e = *(char**)(self + 0x3F50) + idx * 0x1C;
    *(int*)e |= 0x22;
    *(int*)(e + 8) = 0x7FFFFFFF;
    return *(int*)e >> 13;
}
#endif

INCLUDE_ASM("render/ps2graphicsman", func_00367440);

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367B60);
#ifdef SKIP_ASM
extern "C" void func_00367B60(void* self, int i)
{
    char* obj = *(char**)((char*)self + (i << 2) + 8);
    if (*(int*)(obj + 0x28) != -1) {
        char* sub = *(int*)(obj + 0xC) != 9 ? (char*)self + 0x1F60 : (char*)self + 0x4350;
        char* e = *(char**)(sub + 0x1FF0) + *(int*)(obj + 0x30) * 0x1C;
        *(int*)e &= ~2;
    }
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367BC0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
extern "C" void func_003663D8(void* self, int id);

struct sGmTex7BC0 {
    int owned;              // 0x0
    char pad_0x4[0x8];
    int kind;               // 0xC
    char pad_0x10[0xC];
    void* bufA;             // 0x1C
    void* bufB;             // 0x20
    char pad_0x24[0x4];
    int slotA;              // 0x28
    int slotB;              // 0x2C
    int idA;                // 0x30
    int idB;                // 0x34
};

struct sGmMan7BC0 {
    int count;
    int pad_0x4;
    sGmTex7BC0* texs[1];    // 0x8
};

static inline void fill7BC0(int* p, int v)
{
    for (int i = 1; i >= 0; i--) {
        p[i] = v;
    }
}

extern "C" void func_00367BC0(sGmMan7BC0* self, int id)
{
    char* s = (char*)self;
    sGmTex7BC0* t = self->texs[id];
    if (t->slotA != -1) {
        func_003663D8(t->kind != 9 ? s + 0x1F60 : s + 0x4350, t->idA);
    }
    if (t->slotB != -1) {
        func_003663D8(s + 0x1F60, t->idB);
    }
    if (t->owned != 0) {
        if (t->bufA != 0) {
            cMemMan_free(t->bufA);
        }
        if (t->bufB != 0) {
            cMemMan_free(t->bufB);
        }
    }
    if (id < 0x5DC) {
        func_003672C0((sGmPtrTable*)self, id);
    } else {
        func_003671C8((cTexSlots3671C8*)self, id);
    }
    fill7BC0((int*)(s + 0x1F4C), -1);
    *(int*)(s + 0x1F54) = -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/ps2graphicsman", func_00367CD0);
#ifdef SKIP_ASM
extern "C" int func_00367440(void* self, int a1, void* a2, int a3, int a4, int a5, int a6, int a7,
                             int a8, int a9, int a10, int a11);
extern char D_004A4068[];

extern "C" int func_00367CD0(void* self, int a, int b, int c)
{
    return func_00367440(self, 0, D_004A4068, a, b, 0, c, 0, 0, 3, 0, -1);
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367D20);
#ifdef SKIP_ASM
extern "C" void* func_003E6574(void*, void*, int);
extern "C" void func_00369098(void* self, int idx);

extern "C" void func_00367D20(void* self, int idx, void* data, int a3, int a4, int a5, int a6,
                              int a7, void* clut, int upload)
{
    char* e = *(char**)((char*)self + (idx << 2) + 8);
    if (upload != 0) {
        if (data != 0) {
            func_003E6574(*(void**)(e + 0x1C), data, *(int*)(e + 0x10));
        }
        if (clut != 0) {
            func_003E6574(*(void**)(e + 0x20), clut, 4 << *(int*)(e + 0x18));
        }
    }
    func_00369098(self, idx);
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367DB8);
#ifdef SKIP_ASM
// PORT: 64-bit GS register words (ulong is 64-bit here).
struct sGsTex0Bits {
    ulong TBP0 : 14;
    ulong TBW : 6;
    ulong PSM : 6;
    ulong TW : 4;
    ulong TH : 4;
    ulong TCC : 1;
    ulong TFX : 2;
    ulong CBP : 14;
    ulong CPSM : 4;
    ulong CSM : 1;
    ulong CSA : 5;
    ulong CLD : 3;
};

struct sPs2RenderTex {
    char pad_0x00[0x28];
    int addr;               // 0x28
    char pad_0x2C[0xC];
    sGsTex0Bits tex0;       // 0x38
};

struct sPs2TexSet {
    char pad_0x00[0x8];
    sPs2RenderTex* tex[1];  // 0x08
};

static inline ulong gsSetFrame367DB8(int fbp, int fbw, int psm, int fbmsk)
{
    return (ulong)fbp | ((ulong)fbw << 16) | ((ulong)psm << 24) | ((ulong)fbmsk << 32);
}

extern "C" void func_00367DB8(sPs2TexSet* self, int idx, ulong** pp)
{
    sPs2RenderTex* t = self->tex[idx];
    ulong* p = *pp;
    p[0] = 0x10000005;
    p[1] = 0;
    p[2] = (ulong)0x8800 << 45;
    p[3] = (ulong)0x50000004 << 32;
    p[4] = ((ulong)0x10000000 << 32) | 0x8003;
    p[5] = 0xE;
    p[6] = gsSetFrame367DB8(t->addr >> 5, (1 << t->tex0.TW) >> 6, t->tex0.PSM, 0);
    p[7] = 0x4C;
    p[8] = ((ulong)((1 << t->tex0.TW) - 1) << 16) | ((ulong)((1 << t->tex0.TH) - 1) << 48);
    p[9] = 0x40;
    p[10] = (ulong)((0x800 - ((1 << t->tex0.TW) >> 1)) << 4) |
            ((ulong)((0x800 - ((1 << t->tex0.TH) >> 1)) << 4) << 32);
    p[11] = 0x18;
    p += 12;
    *pp = p;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00367F18);
#ifdef SKIP_ASM
// PORT: 64-bit GS register words (ulong is 64-bit here).
struct sGsTex0Bits7F18 {
    ulong TBP0 : 14;
    ulong TBW : 6;
    ulong PSM : 6;
    ulong TW : 4;
    ulong TH : 4;
    ulong TCC : 1;
    ulong TFX : 2;
    ulong CBP : 14;
    ulong CPSM : 4;
    ulong CSM : 1;
    ulong CSA : 5;
    ulong CLD : 3;
};

struct sPs2RenderTex7F18 {
    char pad_0x00[0x38];
    sGsTex0Bits7F18 tex0;   // 0x38
};

struct sPs2TexSet7F18 {
    char pad_0x00[0x8];
    sPs2RenderTex7F18* tex[1];  // 0x08
};

union sFloatBits7F18 {
    float f;
    int i;
};

// Draw a full-size sprite over render texture idx, tinted with color (a, r, g, b in 0..1).
extern "C" void func_00367F18(sPs2TexSet7F18* self, int idx, float* color, ulong** pp)
{
    sPs2RenderTex7F18* t = self->tex[idx];
    ulong* p = *pp;
    sFloatBits7F18 q;
    q.f = 1.0f;
    p[0] = 0x10000006;
    p[1] = 0;
    p[2] = 0;
    p[3] = (ulong)0x50000005 << 32;
    p[4] = ((ulong)0x44000000 << 32) | 1;
    p[5] = 0x5510;
    p[6] = 0x10E;
    p[7] = (ulong)(int)(color[1] * 128.0f) | ((ulong)(int)(color[2] * 128.0f) << 8) |
           ((ulong)(int)(color[3] * 128.0f) << 16) | ((ulong)(int)(color[0] * 128.0f) << 24) |
           ((ulong)q.i << 32);
    p[8] = (ulong)((0x800 - ((1 << t->tex0.TW) >> 1)) << 4) |
           ((ulong)((0x800 - ((1 << t->tex0.TH) >> 1)) << 4) << 16) | ((ulong)1 << 32);
    p[9] = (ulong)((((1 << t->tex0.TW) >> 1) + 0x801) << 4) |
           ((ulong)((((1 << t->tex0.TH) >> 1) + 0x801) << 4) << 16) | ((ulong)1 << 32);
    p[10] = ((ulong)0x10000000 << 32) | 0x8001;
    p[11] = 0xE;
    {
        ulong hi = ((ulong)((1 << t->tex0.TH) - 2) << 48) | (((ulong)1 << 32) | 1);
        p[12] = ((ulong)((1 << t->tex0.TW) - 2) << 16) | hi;
    }
    p[13] = 0x40;
    p += 14;
    *pp = p;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00368138);
#ifdef SKIP_ASM
extern char D_0044B200[];

// PORT: 64-bit `ulong` DMA tag, pointer packed into the upper word
extern "C" void func_00368138(void* self, ulong** pkt)
{
    (*pkt)[0] = ((ulong)(int)D_0044B200 << 32) | 0x30000022;
    (*pkt)[1] = 0;
    *pkt += 2;
}
#endif

INCLUDE_ASM("render/ps2graphicsman", func_00368170);

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003684F0);
#ifdef SKIP_ASM
struct sPs2UpTex {
    char pad_0x00[0xC];
    unsigned int psm;       // 0xC
    char pad_0x10[0x10];
    int addr;               // 0x20
    char pad_0x24[0x8];
    int dbp;                // 0x2C
};

struct sPs2UpMgr {
    char pad_0x0[0x8];
    sPs2UpTex* texs[1];     // 0x8
};

// PORT: 64-bit `ulong` GIF/DMA packet words.
extern "C" void func_003684F0(sPs2UpMgr* self, int idx, ulong** dma, ulong** gif)
{
    sPs2UpTex* tex = self->texs[idx];
    ulong* p = *gif;
    ulong* d = *dma;
    int w;
    int h;
    int qwc;
    if (tex->psm - 0xB < 2) {
        w = 8;
        h = 2;
        qwc = 0x10;
    } else {
        w = 0x10;
        h = 0x10;
        qwc = 0x40;
    }
    p[0] = 0x10000006;
    p[1] = 0;
    p[2] = ((ulong)0x10000000 << 32) | 4;
    p[3] = 0xE;
    p[4] = ((ulong)tex->dbp << 32) | ((ulong)1 << 48);
    p[5] = 0x50;
    p[6] = 0;
    p[7] = 0x51;
    p[8] = w | ((ulong)h << 32);
    p[9] = 0x52;
    p[10] = 0;
    p[11] = 0x53;
    p[12] = qwc | ((ulong)2 << 58);
    p[13] = 0;
    p[14] = 0x30000000 | qwc | ((ulong)tex->addr << 32);
    p[15] = 0;
    p[16] = 0x10000002;
    p[17] = 0;
    p[18] = ((ulong)0x10000000 << 32) | 0x8001;
    p[19] = 0xE;
    p[20] = 0;
    p[21] = 0x3F;
    func_00368138(self, &d);
    p += 22;
    *dma = d;
    *gif = p;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("render/ps2graphicsman", func_00368660);
#ifdef SKIP_ASM
extern "C" int func_00366CE0(void* heap, int size, int idx, int other, int a4, int a5);
extern "C" void func_00368170(void* self, int idx, ulong** dma, ulong** gif);
extern "C" void func_00368970(void* self, int idx, int slot, ulong** dma);
extern "C" ulong* func_0038F460(void* ring, unsigned int addr, int size, int flags);
extern "C" void* func_0038F668(void* ring, ulong* p, int a2);
extern void* D_004A4474;

struct sUpNode_8660 {
    int flags;
    int f4[6];
};

struct sUpHeap_8660 {
    char pad_0x0[0x1FF0];
    sUpNode_8660* nodes;    // 0x1FF0
};

struct sUpTex_8660 {
    char pad_0x00[0xC];
    unsigned int psm;       // 0xC
    char pad_0x10[0x4];
    int size;               // 0x14
    char pad_0x18[0x8];
    int clut;               // 0x20
    char pad_0x24[0x4];
    int addr;               // 0x28
    int caddr;              // 0x2C
    int node;               // 0x30
    int cnode;              // 0x34
};

struct sUpMgr_8660 {
    char pad_0x0[0x8];
    sUpTex_8660* texs[0x7D1];   // 0x8
    int state[2];               // 0x1F4C
};

// PORT: 64-bit `ulong` GIF/DMA packet words.
extern "C" void func_00368660(char* self, int a, int b, int a3, ulong** pp, void** gifOut)
{
    ulong* cur = *pp;
    sUpTex_8660* objs[2];
    if (a < 0 && b < 0)
        return;
    objs[0] = a >= 0 ? ((sUpMgr_8660*)self)->texs[a] : 0;
    objs[1] = b >= 0 ? ((sUpMgr_8660*)self)->texs[b] : 0;
    int sent = 0;
    ulong* gif = 0;
    for (int k = 0; k < 2; k++) {
        int idx = b;
        if (k == 0)
            idx = a;
        if (idx < 0)
            continue;
        int other = a;
        if (k == 0)
            other = b;
        sUpTex_8660* t = ((sUpMgr_8660*)self)->texs[idx];
        sUpHeap_8660* heap;
        int shift;
        if (t->psm == 9) {
            heap = (sUpHeap_8660*)(self + 0x4350);
            shift = 2;
        } else {
            heap = (sUpHeap_8660*)(self + 0x1F60);
            shift = 0;
        }
        if (t->addr < 0) {
            ((sUpMgr_8660*)self)->state[k] = -1;
            int n = func_00366CE0(heap, t->size, idx, other, a3, 1);
            sUpNode_8660* nd = &heap->nodes[n];
            int fl = nd->flags;
            t->node = n;
            t->addr = (fl >> 8) << shift;
            if (gif == 0)
                gif = func_0038F460(D_004A4474, *(unsigned int*)gifOut, -1, 0);
            func_00368170(self, idx, &cur, &gif);
            sent = 1;
        }
        if (t->clut != 0 && t->caddr < 0) {
            *(int*)(self + 0x1F54) = -1;
            int n = func_00366CE0(self + 0x1F60, t->psm - 0xB < 2 ? 0x100 : 0x400, idx, other, a3, 0);
            int* f = &((sUpHeap_8660*)(self + 0x1F60))->nodes[n].flags;
            int fl = *f | 4;
            *f = fl;
            t->cnode = n;
            t->caddr = fl >> 8;
            if (gif == 0)
                gif = func_0038F460(D_004A4474, *(unsigned int*)gifOut, -1, 0);
            func_003684F0((sPs2UpMgr*)self, idx, &cur, &gif);
            sent = 1;
        }
    }
    if (gif != 0)
        *gifOut = func_0038F668(D_004A4474, gif, 4);
    if (!sent) {
        cur[0] = 0x10000001;
        cur[1] = 0;
        cur[2] = 0;
        cur[3] = (ulong)0x8800 << 45;
        cur += 4;
    }
    if (a >= 0)
        func_00368970(self, a, 0, &cur);
    if (b >= 0)
        func_00368970(self, b, 1, &cur);
    *pp = cur;
}
#endif

INCLUDE_ASM("render/ps2graphicsman", func_00368970);

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00369098);
#ifdef SKIP_ASM
extern "C" void func_00366E30(void* list, int i);

extern "C" void func_00369098(void* self, int idx)
{
    char* e = *(char**)((char*)self + (idx << 2) + 8);
    if (*(int*)(e + 0x28) != -1) {
        if (*(int*)(e + 0xC) != 9) {
            func_00366E30((char*)self + 0x1F60, idx);
        } else {
            func_00366E30((char*)self + 0x4350, idx);
        }
    }
    int v = -1;
    int* a = (int*)((char*)self + 0x1F4C);
    for (int i = 1; i >= 0; i--) {
        a[i] = v;
    }
    *(int*)((char*)self + 0x1F54) = -1;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00369130);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` bitfield (GS TEX1 register layout)
struct sGsTex1 {
    ulong LCM : 1;
    ulong pad0 : 1;
    ulong MXL : 3;
    ulong MMAG : 1;
    ulong MMIN : 3;
    ulong MTBA : 1;
    ulong pad1 : 9;
    ulong L : 2;
    ulong pad2 : 11;
    ulong K : 12;
    ulong pad3 : 20;
};

struct sGfxTex1 {
    char pad[0x40];
    sGsTex1 tex1;
};

struct sGfxTexTable1 {
    int pad[2];
    sGfxTex1* entries[1];
};

extern "C" void func_00369130(sGfxTexTable1* self, int idx, int mmin, int mmag, int l, int k)
{
    sGfxTex1* e = self->entries[idx];
    sGsTex1 t = e->tex1;
    t.L = l;
    t.K = k;
    t.MMIN = mmin;
    t.MMAG = mmag;
    e->tex1 = t;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003691B0);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` bitfield (GS TEX0 register layout)
struct sGsTex0 {
    ulong TBP0 : 14;
    ulong TBW : 6;
    ulong PSM : 6;
    ulong TW : 4;
    ulong TH : 4;
    ulong TCC : 1;
    ulong TFX : 2;
    ulong CBP : 14;
    ulong CPSM : 4;
    ulong CSM : 1;
    ulong CSA : 5;
    ulong CLD : 3;
};

struct sGfxTex {
    char pad[0x38];
    sGsTex0 tex0;
};

struct sGfxTexTable {
    int pad[2];
    sGfxTex* entries[1];
};

extern "C" void func_003691B0(sGfxTexTable* self, int idx, int tfx)
{
    if (idx != -1) {
        self->entries[idx]->tex0.TFX = tfx;
    }
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003691F8);
#ifdef SKIP_ASM
extern "C" void func_00416210(void* dst, int c, int n);
extern "C" void func_003E6448(void* dst, unsigned int value, int size);
extern void* D_004A5B80;
extern void* D_00493950[];

inline void* operator new(unsigned int, void* p) { return p; }

struct sTexPair_691F8 {
    short s[2];
    sTexPair_691F8() { for (unsigned int i = 0; i < 2; i++) s[i] = -1; }
};

struct sRS_691F8 {
    int f0;                     // 0x00
    int flagsA;                 // 0x04
    int flagsB;                 // 0x08
    int fC;                     // 0x0C
    sTexPair_691F8 tex;         // 0x10
    sRS_691F8() { func_00416210(this, 0, 0x10); }
};

struct sGfxPair_691F8 {
    int a, b;
    sGfxPair_691F8() {}
};

struct sGfxState_691F8 {
    sRS_691F8* top;                 // 0x00 (0xE84)
    sRS_691F8 stack[4];             // 0x04 (0xE88)
    sRS_691F8 cur;                  // 0x54 (0xED8)
    int pad68;                      // 0x68 (0xEEC)
    sTexPair_691F8 texs[4];         // 0x6C (0xEF0)
    sTexPair_691F8 tex;             // 0x7C (0xF00)
    sGfxPair_691F8 p0[2];           // 0x80 (0xF04)
    sGfxPair_691F8 p1[2];           // 0x90 (0xF14)
    sGfxState_691F8() {}
};

struct sKey8_691F8 {
    int a, b;
};

extern sRS_691F8 D_00501420;
extern sTexPair_691F8 D_004A5A10[];
extern sKey8_691F8 D_004A5960[];

static inline void gfxSet0_691F8(sRS_691F8* r, int v, int mask, int shift)
{
    r->f0 = (r->f0 & ~(mask << shift)) | ((v << shift) & (mask << shift));
}

static inline void gfxSetA_691F8(sRS_691F8* r, int v, int mask, int shift)
{
    r->flagsA = (r->flagsA & ~(mask << shift)) | ((v << shift) & (mask << shift));
}

static inline void gfxSetB_691F8(sRS_691F8* r, int v, int mask, int shift)
{
    r->flagsB = (r->flagsB & ~(mask << shift)) | ((v << shift) & (mask << shift));
}

static inline void gfxSetC_691F8(sRS_691F8* r, int v, int mask, int shift)
{
    r->fC = (r->fC & ~(mask << shift)) | ((v << shift) & (mask << shift));
}

static inline void gfxSetTex_691F8(sRS_691F8* r, const sTexPair_691F8& t)
{
    r->tex = t;
}

extern "C" void* func_003691F8(char* self)
{
    *(void***)(self + 0x10D8) = D_00493950;
    new (self + 0xE84) sGfxState_691F8;
    *(int*)(self + 0xF44) = 0;
    D_004A5B80 = self;
    for (unsigned int i = 0; i < 2; i++) D_004A5A10[0].s[i] = -1;
    func_00416210(&D_00501420, 0, 0x10);
    gfxSetA_691F8(&D_00501420, 1, 3, 23);
    gfxSetA_691F8(&D_00501420, 0, 1, 22);
    gfxSetA_691F8(&D_00501420, 3, 3, 20);
    gfxSetA_691F8(&D_00501420, 0, 0xFF, 12);
    gfxSetA_691F8(&D_00501420, 0, 3, 0);
    gfxSetB_691F8(&D_00501420, 4, 0x1F, 5);
    gfxSetB_691F8(&D_00501420, 0, 0x1F, 0);
    gfxSet0_691F8(&D_00501420, 0, 3, 0);
    gfxSet0_691F8(&D_00501420, 0, 3, 10);
    gfxSet0_691F8(&D_00501420, 0, 0xF, 6);
    gfxSetC_691F8(&D_00501420, 0, 0x3FFFFFFF, 0);
    for (unsigned int k = 0; k < 2; k++) {
        gfxSetA_691F8(&D_00501420, 5, 0x1F, 2 + k * 5);
        gfxSet0_691F8(&D_00501420, 0, 0xFF, 12 + k * 8);
    }
    for (unsigned int k = 0; k < 2; k++) {
        gfxSet0_691F8(&D_00501420, 0, 3, 2 + k * 2);
    }
    gfxSetTex_691F8(&D_00501420, D_004A5A10[0]);
    for (int k = 0; k < 4; k++) {
        ((sRS_691F8*)(self + 0xE88))[k] = D_00501420;
    }
    *(sRS_691F8**)(self + 0xE84) = (sRS_691F8*)(self + 0xE88);
    *(sKey8_691F8*)self = D_004A5960[0];
    *(int*)(self + 0x8) = 0;
    func_003E6448(self + 0xF50, 0xFFFFFFFF, 0x158);
    *(int*)(self + 0x270) = 1;
    *(int*)(self + 0x26C) = 0;
    *(int*)(self + 0x274) = 0;
    *(int*)(self + 0xF48) = 0;
    *(int*)(self + 0xF4C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003695D8);
#ifdef SKIP_ASM
extern void* D_004A5B80;
extern void* D_00493950[];
void operator_delete(int* ptr);

extern "C" void func_003695D8(void* self, int flags)
{
    *(void***)((char*)self + 0x10D8) = D_00493950;
    D_004A5B80 = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00369610);
#ifdef SKIP_ASM
struct sVEntry00369610 {
    short delta;
    short index;
    void (*fn)(void*, int*);
};

extern "C" void func_00369610(void* self, int* mask)
{
    int i;
    unsigned int j;
    for (i = 0; i < 4; i++) {
        ((int*)((char*)self + 0xED8))[i] = ~mask[i];
    }
    for (j = 0; j < 2; j++) {
        ((short*)((char*)self + 0xEE8))[j] = 0x7FFF;
    }
    sVEntry00369610* vt = *(sVEntry00369610**)((char*)self + 0x10D8);
    vt[62].fn((char*)self + vt[62].delta, mask);
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00369690);
#ifdef SKIP_ASM
extern "C" void* func_003E6574(void*, void*, int);

extern "C" void func_00369690(void* self, int count, void* src)
{
    *(int*)((char*)self + 0xE80) = count;
    func_003E6574((char*)self + 0x280, src, count * 0xC);
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003696C8);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const void* a, const void* b);
extern "C" void* func_003B3900(void* src, const char* name);
extern "C" char* strcpy(char* dst, const char* src);
extern char D_004A41A0[];

struct sTexEnt_96C8 {
    int handle;     // 0x0
    char name[8];   // 0x4
};

struct sVE_96C8 {
    short delta;
    short index;
    int (*fn)(void*, void*, const char*, int, int, int);
};

struct sGfx_96C8 {
    char pad0[0x278];
    int numSrc;                 // 0x278
    void** src;                 // 0x27C
    sTexEnt_96C8 ents[256];     // 0x280
    int count;                  // 0xE80
};

// Look up (or load and cache) a texture by its 4-character name.
extern "C" int func_003696C8(void* self_, const char* name)
{
    sGfx_96C8* self = (sGfx_96C8*)self_;
    char buf[0x10];
    const char* p = name;
    if (*p) {
        char* d = buf;
        do
            *d++ = *p++;
        while (*p && p - name < 4);
    }
    buf[p - name] = 0;
    for (int i = 0; i < self->count; i++) {
        if (func_004165A8(buf, self->ents[i].name) == 0)
            return self->ents[i].handle;
    }
    strcpy(self->ents[self->count].name, buf);
    for (int j = 0; j < self->numSrc; j++) {
        void* r = func_003B3900(self->src[j], self->ents[self->count].name);
        if (r != 0) {
            sVE_96C8* vt = *(sVE_96C8**)((char*)self + 0x10D8);
            self->ents[self->count].handle = vt[46].fn((char*)self + vt[46].delta, r, D_004A41A0, 0, 1, -1);
            return self->ents[self->count++].handle;
        }
    }
    self->ents[self->count].handle = -1;
    return self->ents[self->count++].handle;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_00369890__FPvii);
#ifdef SKIP_ASM
void func_00369890(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x27c) = a2;
    *(int*)((char*)self + 0x278) = a1;
    *(int*)((char*)self + 0xe80) = 0;
}
#endif

//100%
INCLUDE_ASM("render/ps2graphicsman", func_003698A0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

extern "C" void func_003698A0(void* self)
{
    void* p = *(void**)((char*)self + 0xF48);
    if (p != 0) {
        cMemMan_free(p);
    }
    *(void**)((char*)self + 0xF48) = 0;
    *(int*)((char*)self + 0xF4C) = 0;
}
#endif

