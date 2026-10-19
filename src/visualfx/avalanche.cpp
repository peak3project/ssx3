#include "common.h"

INCLUDE_ASM("visualfx/avalanche", tActiveAvalancheNode_getFrameData);

INCLUDE_ASM("visualfx/avalanche", func_002D6290);

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D6378);
#ifdef SKIP_ASM
extern void* D_00488648[];
extern void* D_00488680[];
struct func_002D6378_sElem {
    char pad[0x2F0];
};
extern func_002D6378_sElem D_004EE840[];
extern "C" void func_002D9B40(void* self);
extern "C" void func_003715B0(void* p, int flags);
void operator_delete(int* ptr);

extern "C" void func_002D6378(int* self, int flags)
{
    *(void***)self = D_00488648;
    func_002D9B40(self);
    int i;
    for (i = 0; i < 64; i++) {
        func_003715B0(&D_004EE840[i], 1);
    }
    *(void***)self = D_00488680;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D6410);
#ifdef SKIP_ASM
struct func_002D6410_sElem {
    float x;
    float y;
    float z;
    float w;
    int r;
    int g;
    int b;
    int a;
    char pad[0x10];
};
extern func_002D6410_sElem D_004D5B70[];
extern func_002D6410_sElem D_004EDB70[];
extern char D_00538450[];
extern int D_004A3AC0;
extern "C" void func_00416210(void* dst, int c, int n);

extern "C" void func_002D6410(void)
{
    int i;
    for (i = 0; i < 0x800; i++) {
        int c = (i & 1) ? 0xFF : 0;
        func_002D6410_sElem* e = &D_004D5B70[i];
        e->a = 0xFF;
        e->r = c;
        e->g = c;
        e->b = c;
        e->z = 1.0f;
        e->w = 0.0f;
        e->x = 0.0f;
        e->y = 0.0f;
    }
    for (i = 0; i < 0x20; i++) {
        func_002D6410_sElem* e = &D_004EDB70[i];
        e->a = 0xFF;
        e->r = 0xFF;
        e->g = 0xFF;
        e->b = 0;
        e->z = 1.0f;
        e->w = 0.0f;
        e->x = 0.0f;
        e->y = 0.0f;
    }
    D_004A3AC0 = 0;
    func_00416210(D_00538450, 0, 0x400);
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D64D8);
#ifdef SKIP_ASM
struct sVec4_64D8 {
    float x, y, z, w;
    sVec4_64D8() {}
    sVec4_64D8(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));
extern float D_004A3A94;

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_64D8(const sVec4_64D8& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4_64D8 vNorm_64D8(const sVec4_64D8& v)
{
    sVec4_64D8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_64D8 vScale_64D8(const sVec4_64D8& v, float s)
{
    sVec4_64D8 r;
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

static inline int isBad_64D8(const float* f)
{
    unsigned int b = *(const unsigned int*)f;
    int r = 0;
    if (b == 0x7F800000 || b == 0x7FC00000 || b == 0xFF800000 || b == 0xFFC00000)
        r = 1;
    return r;
}

extern "C" void func_002D64D8(void* self, sVec4_64D8* v)
{
    if (D_004A3A94 < vLen_64D8(*v))
        *v = vScale_64D8(vNorm_64D8(*v), D_004A3A94);
    int bad = isBad_64D8(&v->x) || isBad_64D8(&v->y) || isBad_64D8(&v->z) || isBad_64D8(&v->w);
    if (bad)
        *v = sVec4_64D8(10.0f, 10.0f, 10.0f, 0.0f);
}
#endif

INCLUDE_ASM("visualfx/avalanche", tAvalancheNode_calculate);

//100%
INCLUDE_ASM("visualfx/avalanche", tActiveAvalancheNode_calculateScale);
#ifdef SKIP_ASM
struct sAvalancheData {
    char pad[0xF0];
    unsigned short type;
    char padF2[0xE];
    float f100;
    float f104;
    float f108;
};

extern "C" void tActiveAvalancheNode_calculateScale(void* self, float t)
{
    sAvalancheData* d = *(sAvalancheData**)((char*)self + 0x2E0);
    float x = t * 30.0f;
    if (x < d->f104) {
        *(float*)((char*)self + 0xB0) = 1.0f;
        *(float*)((char*)self + 0xB4) = x / d->f104;
        return;
    }
    if (x < d->f100 - d->f108) {
        *(float*)((char*)self + 0xB4) = 1.0f;
        *(float*)((char*)self + 0xB0) = 1.0f;
        return;
    }
    if (d->type != 2) {
        float v = (d->f100 - x) / d->f108;
        *(float*)((char*)self + 0xB4) = v;
        *(float*)((char*)self + 0xB0) = v;
        if (v > 0.0f) {
            // PORT: sqrt.s (sqrtf without errno check)
            __asm__("sqrt.s %0, %1" : "=f"(v) : "f"(v));
            *(float*)((char*)self + 0xB0) = v;
        }
    }
}
#endif

INCLUDE_ASM("visualfx/avalanche", func_002D7CA8);

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D7DD8);
#ifdef SKIP_ASM
extern "C" void cDynamicColourEmitter_reset(void* self);

struct sVEntry2D7DD8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_002D7DD8(void* self, int force)
{
    char* p = *(char**)((char*)self + 0x2E0);
    if (p != 0 && (force != 0 || *(unsigned short*)(p + 0xF0) != 2)) {
        char* q = *(char**)(p + 0xF8);
        if (q != 0) {
            char* obj = *(char**)(q + 0xC);
            if (obj != 0) {
                sVEntry2D7DD8* vt = *(sVEntry2D7DD8**)(obj + 0xC);
                vt[1].fn(obj + vt[1].delta, 3);
            }
        }
        *(int*)(*(char**)((char*)self + 0x2E0) + 0x114) = 0;
        *(char**)((char*)self + 0x2E0) = 0;
        cDynamicColourEmitter_reset((char*)self + 0xD0);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", tActiveAvalanche_buildArray);
#ifdef SKIP_ASM
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00487548[];

struct tActiveAvalanche_node {
    char pad[0x2E4];
    tActiveAvalanche_node* next; // 0x2E4
};

struct tActiveAvalanche {
    int unk0;
    tActiveAvalanche_node* head;   // 0x4
    tActiveAvalanche_node** array; // 0x8
};

extern "C" void tActiveAvalanche_buildArray(tActiveAvalanche* self)
{
    tActiveAvalanche_node* p;
    int n = 0;
    for (p = self->head; p != 0; p = p->next) {
        n++;
    }
    self->array = (tActiveAvalanche_node**)operator_new_tag(n * 4, D_00487548, 0, 0);
    int i = 0;
    for (p = self->head; p != 0; p = p->next) {
        self->array[i++] = p;
    }
}
#endif

INCLUDE_ASM("visualfx/avalanche", func_002D7EF8);

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D81B0);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern "C" void* func_0028B180();
extern "C" void func_0029DEF0(void* self, int a1);
extern char* D_004A28A8;

extern "C" void func_002D81B0(void* self)
{
    if (*(void**)((char*)self + 0x8) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x8));
        *(void**)((char*)self + 0x8) = 0;
    }
    if (*(int*)self != 0) {
        char* n = *(char**)((char*)self + 0x4);
        while (n != 0) {
            func_002D7DD8(n, 1);
            n = *(char**)(n + 0x2E4);
        }
        *(int*)self = 0;
        func_0029DEF0(func_0028B180(), 0);
        char* p = *(char**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0xA8);
        if (*(int*)(p + 0x708) != 0) {
            *(int*)(p + 0x708) = *(int*)(p + 0x708) - 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D8258);
#ifdef SKIP_ASM
extern char D_004A3AD0[];
extern char D_004A3AD8[];
extern char D_004A3AE0[];
extern "C" void func_002D83B8(int, char*);

extern "C" void func_002D8258(void)
{
    func_002D83B8(1, D_004A3AD0);
    func_002D83B8(1, D_004A3AD8);
    func_002D83B8(0, D_004A3AE0);
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D82A0);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern "C" void func_003DEC80(void* a, void* b, void* data, int size, int prio);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_004A3AE8[];

extern "C" int func_002D82A0(int direct, void* a, void* b, char* src, int stride, int rows)
{
    if (direct) {
        func_003DEC80(a, b, src, stride * rows, 100);
    } else {
        char* buf = (char*)operator_new_tag(stride * rows, D_004A3AE8, 0, 0);
        char* d = buf;
        for (int i = 0; i < rows; i++) {
            char* end = src + stride;
            char* p = end;
            while (src != p) {
                *d++ = *--p;
            }
            src = end;
        }
        func_003DEC80(a, b, buf, stride * rows, 100);
        if (buf != 0) {
            cMemMan_free(buf);
        }
    }
    return stride * rows;
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D83B8);
#ifdef SKIP_ASM
extern void* D_004A3AB0;
extern int D_004A3A48;
extern char D_004A3AF0[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144BE0(void* iface);
extern "C" char* func_00144C48(void* iface, int i);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_003DEBF0(char* name, int mode, int prio, int* fd);
extern "C" void func_003DECA0(int fd, int prio);
extern "C" int func_002D82A0(int direct, void* a, void* b, char* src, int stride, int rows);

struct sAvPart_83B8 {
    char pad_0x0[0xE0];
    float pos[3];                   // 0xE0
    char pad_0xEC[0xF4 - 0xEC];
    sAvPart_83B8* next;             // 0xF4
    char pad_0xF8[0x4];
    char* data;                     // 0xFC
    float count;                    // 0x100
};

struct sAvLink_83B8 {
    int id;                         // 0x0
    char* obj;                      // 0x4
};

struct sAvPair_83B8 {
    short a;
    short b;
};

struct sAvGroup_83B8 {
    int f0;
    sAvPart_83B8* parts;            // 0x4
    sAvGroup_83B8* next;            // 0x8
    unsigned short nlinks;          // 0xC
    unsigned short npairs;          // 0xE
    sAvLink_83B8 links[0x20];       // 0x10
    sAvPair_83B8 pairs[1];          // 0x110
};

// PORT: func_002D82A0 takes the file handle and offset as void* (ints passed through pointers).
extern "C" void func_002D83B8(int direct, char* name)
{
    if (D_004A3AB0 == 0) {
        return;
    }
    int off = 0;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    char buf[0x100];
    sprintf(buf, D_004A3AF0, func_00144C48(iface, func_00144BE0(iface)), name);
    int fd;
    if (func_003DEBF0(buf, 0x26, 0x64, &fd)) {
        sAvGroup_83B8* g;
        for (g = (sAvGroup_83B8*)D_004A3AB0; g != 0; g = g->next) {
            for (sAvPart_83B8* p = g->parts; p != 0; p = p->next) {
                off += 0x10 + (int)p->count * 10;
            }
            off += 4;
            int k;
            for (k = 0; k < g->nlinks; k++) {
                off += 8;
            }
            for (k = 0; k < g->npairs; k++) {
                off += 4;
            }
        }
        int magic = 0x2BEEF00;
        func_002D82A0(direct, (void*)fd, 0, (char*)&magic, 4, 1);
        func_002D82A0(direct, (void*)fd, (void*)4, (char*)&off, 4, 1);
        off = 8;
        for (g = (sAvGroup_83B8*)D_004A3AB0; g != 0; g = g->next) {
            unsigned short h;
            for (sAvPart_83B8* p = g->parts; p != 0; p = p->next) {
                h = 0xBEEF;
                off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)&h, 2, 1);
                h = (int)p->count * 10 + 0xC;
                off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)&h, 2, 1);
                off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)p->pos, 4, 3);
                off += func_002D82A0(1, (void*)fd, (void*)off, p->data, 10, (int)p->count);
            }
            h = g->nlinks;
            off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)&h, 2, 1);
            h = g->npairs;
            off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)&h, 2, 1);
            int k;
            for (k = 0; k < g->nlinks; k++) {
                off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)&g->links[k].id, 4, 1);
                off += func_002D82A0(direct, (void*)fd, (void*)off, g->links[k].obj + 0x78, 4, 1);
            }
            for (k = 0; k < g->npairs; k++) {
                off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)&g->pairs[k].b, 2, 1);
                off += func_002D82A0(direct, (void*)fd, (void*)off, (char*)&g->pairs[k].a, 2, 1);
            }
        }
        func_003DECA0(fd, 0x64);
    }
    D_004A3A48 = 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D87D0);
#ifdef SKIP_ASM
extern void* D_004A3AB4;
extern int D_004A3AB8;
extern int D_004A3ABC;
extern int D_004A3AC4;
extern int D_004A3A4C;
extern char D_004A3AD8[];
// PORT: the read call returns func_003DEB50's result (bytes read); the ealib unit declares it void.
extern "C" int func_003DEC60_i(int fd, int off, void* data, int size, int prio) __asm__("func_003DEC60");
extern "C" void func_002D9A80(void);
extern "C" void cAvalanche_resolveDataPointers(void);

// Loads the avalanche data file for the current mountain (magic 0x2BEEF00, then the data size) into a fresh buffer.
extern "C" void func_002D87D0(void)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    char buf[0x100];
    sprintf(buf, D_004A3AF0, func_00144C48(iface, func_00144BE0(iface)), D_004A3AD8);
    D_004A3ABC = 0;
    D_004A3AC4 = 1;
    int fd;
    if (func_003DEBF0(buf, 1, 0x64, &fd)) {
        func_002D9A80();
        if (D_004A3AB4 != 0 && D_004A3AB8 != 0) {
            cMemMan_free(D_004A3AB4);
        }
        int* hdr = (int*)operator_new_tag(8, buf, 0, 0);
        func_003DEC60_i(fd, 0, hdr, 8, 0x64);
        if (hdr[0] != 0x2BEEF00) {
            if (hdr != 0) {
                cMemMan_free(hdr);
            }
            D_004A3AB4 = 0;
            D_004A3AB8 = 0;
        } else {
            int size = hdr[1];
            if (hdr != 0) {
                cMemMan_free(hdr);
            }
            void* data = operator_new_tag(size, buf, 0, 0);
            D_004A3AB8 = 1;
            D_004A3AB4 = data;
            func_003DEC60_i(fd, 0, data, size + 8, 0x64);
            func_003DECA0(fd, 0x64);
            D_004A3AC4 = 0;
        }
    }
    D_004A3A4C = 0;
    cAvalanche_resolveDataPointers();
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/avalanche", func_002D8948);
#ifdef SKIP_ASM
struct sAvalancheSlot {
    int active;
    char pad[0x18];
};
extern int D_004A3A30;
extern int D_004A3A34;
extern int D_004A3A5C;
extern int D_004A3A60;
extern int D_004A3A7C;
extern int D_004A3ABC;
extern int D_004A3AC4;
extern sAvalancheSlot D_00538938[];
extern "C" void func_002D96E0(void);
extern "C" void cAvalanche_resolveDataPointers(void);
extern "C" int cAvalanche_triggerAvalanche(int a);
extern "C" void func_002D7EF8(void* self);

extern "C" void func_002D8948(void)
{
    if (D_004A3A30 != 0) {
        if (D_004A3A34 != 0) {
            func_002D96E0();
            D_004A3A34 = 0;
            D_004A3AC4 = 0;
        }
        cAvalanche_resolveDataPointers();
        if (D_004A3A5C != 0) {
            cAvalanche_triggerAvalanche(D_004A3A7C);
            if (D_004A3A5C < 0) {
                D_004A3A5C = 0;
            }
        }
        if (D_004A3A30 != 0 && D_004A3ABC != 0 && D_004A3A60 != 0) {
            int i;
            for (i = 0; i < 16; i++) {
                func_002D7EF8(&D_00538938[i]);
            }
            if (D_004A3A60 < 0) {
                D_004A3A60 = 0;
            }
        }
    }
}
#endif

INCLUDE_ASM("visualfx/avalanche", func_002D8A00);

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D8EA8);
#ifdef SKIP_ASM
struct sQ_8EA8 {
    int v[4];
} __attribute__((aligned(16)));

struct sElem_8EA8 {
    float x, y, z, w;
    int r;
    int g;
    int b;
    int a;
    sQ_8EA8 q;
};

struct sLink_8EA8 {
    float id;
    char* obj;
};

struct sGroup_8EA8 {
    int f0;
    int f4;
    int f8;
    unsigned short nlinks;      // 0xC
    unsigned short npairs;      // 0xE
    sLink_8EA8 links[1];        // 0x10
};

struct sNode_8EA8 {
    char pad[0xD0];
    char sub[0x2E0 - 0xD0];
    char* obj;                  // 0x2E0
    sNode_8EA8* next;           // 0x2E4
};

struct sSelf_8EA8 {
    sGroup_8EA8* group;         // 0x0
    sNode_8EA8* nodes;          // 0x4
    char pad8[0x10];
    float thresh;               // 0x18
};

struct sRS_8EA8 {
    int w0;
    unsigned int w1;
};

struct sVE_8EA8 {
    short delta;
    short index;
    sQ_8EA8* (*fn)(void*);
};

struct sVE2_8EA8 {
    short delta;
    short index;
    void (*fn)(void*, int, void*, int);
};

struct sCtx_8EA8 {
    char pad[0xE84];
    sRS_8EA8* top;              // 0xE84
    char pad2[0x10D8 - 0xE88];
    sVE2_8EA8* vt;              // 0x10D8
};

extern sCtx_8EA8* D_004A5B80_8EA8 __asm__("D_004A5B80");
extern int D_004A3A58;
extern int D_004A3A54;
extern sElem_8EA8 D_004EDB70_8EA8[] __asm__("D_004EDB70");
extern "C" void func_002D8A00(void* node);
extern "C" void func_00371688(void* p, int a);

static inline void rsSet_8EA8(sCtx_8EA8* ctx, int mask, int shift, int v)
{
    ctx->top->w1 = (ctx->top->w1 & ~mask) | ((v << shift) & mask);
}

// PORT: link ids are compared as floats; pointers held in 32-bit fields.
// Updates the avalanche debris nodes and draws the link markers.
extern "C" void func_002D8EA8(void* selfp)
{
    sSelf_8EA8* self = (sSelf_8EA8*)selfp;
    sCtx_8EA8* ctx = D_004A5B80_8EA8;
    if (self->group == 0) {
        return;
    }
    int i;
    sNode_8EA8* n;
    for (n = self->nodes, i = 0; n != 0; n = n->next, i++) {
        if (n->obj != 0) {
            if (i < D_004A3A58) {
                func_002D8A00(n);
            }
            if (D_004A3A54 != 0) {
                if (*(unsigned char*)(n->obj + 0xF2) != 0) {
                    func_00371688(n->sub, 7);
                }
            }
        }
    }
    if (D_004A3A58 == 0) {
        return;
    }
    int k;
    for (k = 0; k < self->group->nlinks; k++) {
        char* q0 = (char*)&D_004EDB70_8EA8[0].q;
        char* d0 = (char*)D_004EDB70_8EA8;
        char* q1 = (char*)&D_004EDB70_8EA8[1].q;
        sQ_8EA8 t = *(sQ_8EA8*)(self->group->links[k].obj + 0x40);
        *(sQ_8EA8*)(q0 + k * 0x60) = t;
        int c = 0;
        char* e0 = d0 + k * 0x60;
        if (self->group->links[k].id < self->thresh) {
            c = 0xFF;
        }
        *(int*)(e0 + 0x10) = c;
        int d = 0;
        if (self->thresh <= self->group->links[k].id) {
            d = 0xFF;
        }
        *(int*)(e0 + 0x14) = d;
        char* o = *(char**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0x28);
        char* sub = o + 0x6C0;
        sVE_8EA8* vt = *(sVE_8EA8**)sub;
        *(sQ_8EA8*)(q1 + k * 0x60) = *vt[5].fn(sub + vt[5].delta);
        int e = 0;
        char* e1 = d0 + (2 * k + 1) * 0x30;
        if (self->group->links[k].id < self->thresh) {
            e = 0xFF;
        }
        *(int*)(e1 + 0x10) = e;
        int f = 0;
        if (self->thresh <= self->group->links[k].id) {
            f = 0xFF;
        }
        *(int*)(e1 + 0x14) = f;
    }
    int saved = (ctx->top->w1 & 0x1800000) >> 23;
    rsSet_8EA8(ctx, 0x1800000, 23, 2);
    ctx->vt[0x248 / 8].fn((char*)ctx + ctx->vt[0x248 / 8].delta, self->group->nlinks, D_004EDB70_8EA8, 0);
    rsSet_8EA8(ctx, 0x1800000, 23, saved);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/avalanche", func_002D9130);
#ifdef SKIP_ASM
struct sRState_9130 {
    int f0;
    int f4;
    unsigned b0 : 5;
    unsigned b5 : 5;
    unsigned b10 : 22;
    int fC;
    short f10;
    short f12;
};
struct sRCtx_9130 {
    char pad[0xE84];
    sRState_9130* top;          // 0xE84
    char padE88[0x10D8 - 0xE88];
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
    virtual void setMatrix(void* m, int a);
    virtual void setPos(float x, float y, float z);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void setRot(void* r);
};
struct sCam_9130 {
    int f0;
    float* views[4];            // 0x4
    int cur;                    // 0x14
    float mats[4][4];           // 0x18
};
extern char* D_004A28A8;
extern sRCtx_9130* D_004A5B80;
extern int D_004A41EC;
extern sRState_9130 D_00501420;
extern "C" void func_002D8EA8(void* slot);

static inline sCam_9130* getCam_9130() { return *(sCam_9130**)(*(char**)(D_004A28A8 + 0x84) + 0x84); }

static inline void setB5_9130(sRCtx_9130* c, int v) { c->top->b5 = v; }

extern "C" void func_002D9130(void)
{
    if ((D_004A3A30 != 0 && D_004A3ABC != 0) || D_004A41EC != 0)
    {
        sRCtx_9130* ctx = D_004A5B80;
        float* view = getCam_9130()->views[getCam_9130()->cur];
        ctx->top[1] = ctx->top[0];
        ctx->top++;
        *ctx->top = D_00501420;
        setB5_9130(ctx, 7);
        *(short*)((char*)ctx->top + 0x10) = -1;
        ctx->setMatrix(getCam_9130()->mats[getCam_9130()->cur], 1);
        ctx->setPos(view[0], view[1], view[2]);
        ctx->setRot(view + 0x10);
        if (D_004A3A30 != 0)
        {
            for (int i = 0; i < 16; i++)
                func_002D8EA8(&D_00538938[i]);
        }
        ctx->top--;
    }
}
#endif

INCLUDE_ASM("visualfx/avalanche", cAvalanche_addAvalancheNode);

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D9538);
#ifdef SKIP_ASM
struct sAvParams9538 { int data[0xD8 / 4]; };
struct sAvNode9538 {
    sAvParams9538 params;       // 0x0
    char padD8[0xF0 - 0xD8];
    unsigned short type;        // 0xF0
    unsigned char emit;         // 0xF2
    char padF3;
    sAvNode9538* next;          // 0xF4
    int id;                     // 0xF8
};
struct sAvGroup9538 {
    int f0;
    sAvNode9538* nodes;         // 0x4
    sAvGroup9538* next;         // 0x8
};
extern void* D_004A3AB0;

extern "C" void func_002D9538(int id, sAvParams9538* params)
{
    for (sAvGroup9538* g = (sAvGroup9538*)D_004A3AB0; g != 0; g = g->next) {
        for (sAvNode9538* n = g->nodes; n != 0; n = n->next) {
            if (n->id == id) {
                if (n->type == 2) return;
                n->emit = 1;
                n->params = *params;
                return;
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/avalanche", func_002D9660);
#ifdef SKIP_ASM
extern "C" void tAvalancheNode_calculate(void* node, void* self);

extern "C" void func_002D9660(void* self)
{
    void* n = *(void**)((char*)self + 0x4);
    while (n != 0) {
        tAvalancheNode_calculate(n, self);
        n = *(void**)((char*)n + 0xF4);
    }
}
#endif

INCLUDE_ASM("visualfx/avalanche", func_002D96B0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/avalanche", func_002D96E0);
#ifdef SKIP_ASM
extern "C" void func_002D9A80(void);
extern "C" void func_002D8258(void);
extern "C" void func_002D87D0(void);
extern void* D_004A3AB0;

extern "C" void func_002D96E0(void)
{
    func_002D9A80();
    for (void* p = D_004A3AB0; p != 0; p = *(void**)((char*)p + 0x8)) {
        func_002D9660(p);
    }
    func_002D8258();
    func_002D87D0();
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D9738);
#ifdef SKIP_ASM
struct sAvNode_9738 { char pad[0xF4]; sAvNode_9738* next; };
struct sAvEnt_9738 { short a; short depth; };
struct sAv_9738 {
    int f0;
    sAvNode_9738* head;      // 0x4
    char pad8[6];
    unsigned short count;    // 0xE
    char pad10[0x100];
    sAvEnt_9738 ents[64];    // 0x110
};
// Records (a, depth of stop in the node list) while there is room for it.
extern "C" void func_002D9738(sAv_9738* self, int a, sAvNode_9738* stop)
{
    if (self->count < 64) {
        int depth = 0;
        sAvNode_9738* p = self->head;
        while (p != 0 && p != stop) {
            depth++;
            p = p->next;
        }
        self->ents[self->count].a = a;
        self->ents[self->count].depth = depth;
        self->count++;
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", cAvalanche_triggerAvalanche);
#ifdef SKIP_ASM
extern "C" float cRenderStateMan_SnowFlakeColourR(int a);
extern "C" float cRenderStateMan_SnowFlakeColourG(int a);
extern "C" float cRenderStateMan_SnowFlakeColourB(int a);
extern "C" void func_00370DC8(void* self, void* node, float k);
extern "C" void tActiveAvalancheNode_calculateScale(void* self, float t);

extern "C" void func_0029DEF0(void* self, int a1);
extern char* D_004A28A8;
extern void* D_004A3AB0;

struct sVec_D97A8 {
    float x, y, z, w;
    sVec_D97A8() {}
    sVec_D97A8(const float& a, const float& b, const float& c, const float& d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

struct sMat_D97A8 {
    sVec_D97A8 row[4];
};
extern sMat_D97A8 D_004FF1A0_D97A8 __asm__("D_004FF1A0");

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void CopyMatrix_D97A8(sMat_D97A8* dst, sMat_D97A8* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

struct sAvAct_D97A8;
struct sAvNode_D97A8 {
    char pad0[0xE0];
    sVec_D97A8 pos;             // 0xE0
    unsigned short type;        // 0xF0
    unsigned char emit;         // 0xF2
    unsigned char owned;        // 0xF3
    sAvNode_D97A8* next;        // 0xF4
    char* obj;                  // 0xF8
    char padFC[0x114 - 0xFC];
    sAvAct_D97A8* act;          // 0x114
};

struct sAvGroup_D97A8 {
    int id;                     // 0x0
    sAvNode_D97A8* nodes;       // 0x4
    sAvGroup_D97A8* next;       // 0x8
};

struct sAvAct_D97A8 {
    int f0;                     // 0x0
    char pad4[0x10 - 0x4];
    sVec_D97A8 pos;             // 0x10
    sMat_D97A8 m20;             // 0x20
    sVec_D97A8 objPos;          // 0x60
    sMat_D97A8 m70;             // 0x70
    char padB0[0xC0 - 0xB0];
    sVec_D97A8 scale;           // 0xC0
    char emitter[0x1E0 - 0xD0]; // 0xD0
    sVec_D97A8 colour;          // 0x1E0
    char pad1F0[0x2D0 - 0x1F0];
    int f2D0;                   // 0x2D0
    char pad2D4[0x2E0 - 0x2D4];
    sAvNode_D97A8* data;        // 0x2E0
    sAvAct_D97A8* next;         // 0x2E4
    int pad2E8;
    int f2EC;                   // 0x2EC
};
extern sAvAct_D97A8 D_act_D97A8[] __asm__("D_004EE770");

struct sAvSlot_D97A8 {
    sAvGroup_D97A8* group;      // 0x0
    sAvAct_D97A8* active;       // 0x4
    void* arr;                  // 0x8
    int fC;
    int f10;                    // 0x10
    int f14;                    // 0x14
    float time;                 // 0x18
};
extern sAvSlot_D97A8 D_slots_D97A8[] __asm__("D_00538938");

extern "C" int cAvalanche_triggerAvalanche(int id)
{
    cAvalanche_resolveDataPointers();
    for (sAvGroup_D97A8* g = (sAvGroup_D97A8*)D_004A3AB0; g != 0; g = g->next) {
        if (g->id != id)
            continue;
        for (int j = 0; j < 16; j++) {
            if (D_slots_D97A8[j].group == g)
                return (int)0x80000000;
        }
        sAvSlot_D97A8* slot = D_slots_D97A8;
        for (int i = 0; i < 16; i++, slot++) {
            if (slot->group != 0)
                continue;
            slot->group = g;
            slot->active = 0;
            slot->time = 0.0f;
            slot->f10 = 0;
            slot->f14 = 0;
            sAvAct_D97A8* act = D_act_D97A8;
            int k = 0;
            for (sAvNode_D97A8* n = g->nodes; n != 0; n = n->next) {
                for (; k < 64; k++, act++) {
                    if (act->data == 0) {
                        act->data = n;
                        n->act = act;
                        act->next = slot->active;
                        slot->active = act;
                        act->f0 = 0;
                        act->pos = n->pos;
                        CopyMatrix_D97A8(&act->m20, &D_004FF1A0_D97A8);
                        act->f2EC = 0;
                        {
                            sVec_D97A8 p = *(sVec_D97A8*)(n->obj + 0x40);
                            act->objPos = p;
                        }
                        CopyMatrix_D97A8(&act->m70, &D_004FF1A0_D97A8);
                        act->scale = sVec_D97A8(1.0f, 1.0f, 1.0f, 1.0f);
                        tActiveAvalancheNode_calculateScale(act, 0.0f);
                        if (n->emit) {
                            cDynamicColourEmitter_reset(act->emitter);
                            func_00370DC8(act->emitter, n, 2.0f);
                            act->f2D0 = 1;
                            float r = cRenderStateMan_SnowFlakeColourR(0);
                            float gg = cRenderStateMan_SnowFlakeColourG(0);
                            float b = cRenderStateMan_SnowFlakeColourB(0);
                            act->colour = sVec_D97A8(r, gg, b, 0.0f);
                        }
                        break;
                    }
                }
                if (k == 64) {
                    slot->group = 0;
                    for (act = slot->active; act != 0; act = act->next) {
                        if (act->data)
                            act->data->act = 0;
                        act->data = 0;
                    }
                    return (int)0x80000000;
                }
            }
            tActiveAvalanche_buildArray((tActiveAvalanche*)slot);
            func_0029DEF0(func_0028B180(), 1);
            (*(int*)(*(char**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0xA8) + 0x708))++;
            return slot - D_slots_D97A8;
        }
    }
    return (int)0x80000000;
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D9A80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct func_002D9A80_sSlot {
    int active;
    char pad[0x18];
};
// Typed view of D_00538938 (func_002D8948 declares it earlier in the unit with its own element type).
extern func_002D9A80_sSlot D_slots_9A80[] __asm__("D_00538938");
extern int D_004A3AB8;
void cMemMan_free(void*);
extern "C" void func_002D81B0(void* self);

static inline void freeSlot_9A80(func_002D9A80_sSlot* s)
{
    if (s->active != 0) {
        func_002D81B0(s);
    }
}

extern "C" void func_002D9A80(void)
{
    int i;
    for (i = 0; i < 16; i++) {
        freeSlot_9A80(&D_slots_9A80[i]);
    }
    if (D_004A3AB8 != 0) {
        for (char* p = (char*)D_004A3AB0; p != 0; p = *(char**)(p + 0x8)) {
            for (char* n = *(char**)(p + 0x4); n != 0; n = *(char**)(n + 0xF4)) {
                if (*(unsigned char*)(n + 0xF3) != 0 && *(void**)(n + 0xFC) != 0) {
                    cMemMan_free(*(void**)(n + 0xFC));
                }
                *(unsigned char*)(n + 0xF3) = 0;
                *(void**)(n + 0xFC) = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D9B40);
#ifdef SKIP_ASM
extern "C" void func_002D9A80(void);
extern "C" void func_00416210(void* dst, int c, int n);
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern char D_00538450[];
extern int D_004A3AC0;
extern void* D_004A3AB4;
extern int D_004A3AB8;
extern int D_004A3ABC;

extern "C" void func_002D9B40(void* self)
{
    func_002D9A80();
    char* p = (char*)D_004A3AB0;
    while (p != 0) {
        char* cur = p;
        char* n = *(char**)(p + 0x4);
        while (n != 0) {
            char* next = *(char**)(n + 0xF4);
            operator_delete((int*)n);
            n = next;
        }
        p = *(char**)(p + 0x8);
        operator_delete((int*)cur);
    }
    D_004A3AB0 = 0;
    D_004A3AC0 = 0;
    func_00416210(D_00538450, 0, 0x400);
    if (D_004A3AB4 != 0 && D_004A3AB8 != 0) {
        cMemMan_free(D_004A3AB4);
        D_004A3AB4 = 0;
        D_004A3AB8 = 0;
    }
    D_004A3ABC = 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D9C00);
#ifdef SKIP_ASM
struct sAvVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sAvMatrix {
    sAvVec4 row[4];
};

struct sAvNode {
    char pad[0x60];
    sAvVec4 pos;            // 0x60
    sAvMatrix rot;          // 0x70
    float scale;            // 0xB0
    char padB4[0x2E0 - 0xB4];
    void* data;             // 0x2E0
    char pad2E4[0x2F0 - 0x2E4];
};

extern sAvNode D_004EE770[64];

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMatrixAV(sAvMatrix* dst, sAvMatrix* src)
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
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times scalar).
static inline void vu0ScaleMatrixAV(sAvMatrix* dst, sAvMatrix* src, float s)
{
    int t;
    __asm__ __volatile__(
        "mfc1      %0, %3\n"
        "lqc2      $vf4, 0x0(%2)\n"
        "qmtc2.ni  %0, $vf3\n"
        "lqc2      $vf5, 0x10(%2)\n"
        "lqc2      $vf6, 0x20(%2)\n"
        "lqc2      $vf7, 0x30(%2)\n"
        "vmulx.xyzw $vf8, $vf4, $vf3x\n"
        "vmulx.xyzw $vf9, $vf5, $vf3x\n"
        "vmulx.xyzw $vf10, $vf6, $vf3x\n"
        "vmulx.xyzw $vf11, $vf7, $vf3x\n"
        "sqc2      $vf8, 0x0(%1)\n"
        "sqc2      $vf9, 0x10(%1)\n"
        "sqc2      $vf10, 0x20(%1)\n"
        "sqc2      $vf11, 0x30(%1)\n"
        : "=&r"(t)
        : "r"(dst), "r"(src), "f"(s)
        : "memory");
}

extern "C" void func_002D9C00(int id, sAvMatrix* out)
{
    int i;
    for (i = 0; i < 64; i++) {
        sAvNode* node = &D_004EE770[i];
        if (node->data != 0 && *(int*)((char*)node->data + 0xF8) == id) {
            vu0CopyMatrixAV(out, &node->rot);
            vu0ScaleMatrixAV(out, out, node->scale);
            out->row[3] = node->pos;
            return;
        }
    }
}
#endif

INCLUDE_ASM("visualfx/avalanche", func_002D9CB0);

INCLUDE_ASM("visualfx/avalanche", cAvalanche_readFromReplayFrame);

//100%
INCLUDE_ASM("visualfx/avalanche", func_002D9FB8);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern "C" void cAvalanche_resolveDataPointers(void);
extern void* D_004A3AB4;
extern int D_004A3AB8;
extern int D_004A3AC4;

extern "C" void func_002D9FB8(void* data)
{
    func_002D9B40(data);
    if (D_004A3AB4 != 0 && D_004A3AB8 != 0) {
        cMemMan_free(D_004A3AB4);
    }
    D_004A3AB4 = data;
    D_004A3AB8 = 0;
    if (*(int*)data != 0x2BEEF00) {
        D_004A3AB4 = 0;
        D_004A3AC4 = 1;
    } else {
        D_004A3AC4 = 0;
        cAvalanche_resolveDataPointers();
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", cAvalanche_resolveDataPointers);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern void* D_004A3AB0;
extern void* D_004A3AB4;
extern int D_004A3ABC;

struct sAvVec4_A028 {
    float x, y, z, w;
    sAvVec4_A028() {}
    sAvVec4_A028(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));
struct sAvNodeA028 {
    char pad0[0xE0];
    sAvVec4_A028 pos;           // 0xE0
    unsigned short type;        // 0xF0
    unsigned char emit;         // 0xF2
    unsigned char owned;        // 0xF3
    sAvNodeA028* next;          // 0xF4
    int id;                     // 0xF8
    char* data;                 // 0xFC
    float count;                // 0x100
};
struct sAvPairA028 { float v; int f4; };
struct sAvIdxA028 { unsigned short a; unsigned short b; };
struct sAvGroupA028 {
    int f0;
    sAvNodeA028* nodes;         // 0x4
    sAvGroupA028* next;         // 0x8
    unsigned short nPairs;      // 0xC
    unsigned short nIdx;        // 0xE
    sAvPairA028 pairs[32];      // 0x10
    sAvIdxA028 idx[1];          // 0x110
};

extern "C" void cAvalanche_resolveDataPointers(void)
{
    if (D_004A3AB0 == 0)
        return;
    if (D_004A3AB4 == 0)
        return;
    if (D_004A3ABC != 0)
        return;
    char* p = (char*)D_004A3AB4 + 8;
    for (sAvGroupA028* g = (sAvGroupA028*)D_004A3AB0; g != 0; g = g->next) {
        for (sAvNodeA028* n = g->nodes; n != 0; n = n->next) {
            p += 4;
            float* f = (float*)p;
            n->pos = sAvVec4_A028(f[0], f[1], f[2], 1.0f);
            p += 12;
            if (n->owned && n->data)
                cMemMan_free(n->data);
            n->data = p;
            n->owned = 0;
            p += (int)n->count * 10;
        }
        g->nPairs = *(unsigned short*)p;
        p += 2;
        g->nIdx = *(unsigned short*)p;
        p += 2;
        for (int i = 0; i < g->nPairs; i++) {
            g->pairs[i].v = *(float*)p;
            g->pairs[i].f4 = 0;
            p += 8;
        }
        for (int j = 0; j < g->nIdx; j++) {
            g->idx[j].b = *(unsigned short*)p;
            p += 2;
            g->idx[j].a = *(unsigned short*)p;
            p += 2;
        }
        g->nPairs = 0;
    }
    D_004A3ABC = 1;
}
#endif

//100%
INCLUDE_ASM("visualfx/avalanche", func_002DA1C0);
#ifdef SKIP_ASM
struct sVec4_A1C0 {
    float x, y, z, w;
    sVec4_A1C0() {}
    sVec4_A1C0(const float& ax, const float& ay, const float& az, const float& aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));
struct sVec3_A1C0 { float x, y, z; };
struct sAvInfo_A1C0 {
    sVec4_A1C0 center;          // 0x0
    float total;                // 0x10
    float minDist;              // 0x14
    int count;                  // 0x18
    bool any;                   // 0x1C
};
struct sAvNode_A1C0 {
    char pad0[0x60];
    sVec4_A1C0 pos;             // 0x60
    char pad70[0xB0 - 0x70];
    float weight;               // 0xB0
    char padB4[0x2E0 - 0xB4];
    char* src;                  // 0x2E0
    sAvNode_A1C0* next;         // 0x2E4
};
extern sVec4_A1C0 D_004FF120;

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec4_A1C0 vSub_A1C0(const sVec4_A1C0& a, const sVec4_A1C0& b)
{
    sVec4_A1C0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float vLen_A1C0(const sVec4_A1C0& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vAddEq_A1C0(sVec4_A1C0& dst, const sVec4_A1C0& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void vDivEq_A1C0(sVec4_A1C0& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s));
}

// PORT: g++ `<?` (min) operator.
extern "C" sAvInfo_A1C0 func_002DA1C0(sVec3_A1C0 p)
{
    sAvInfo_A1C0 r;
    r.center = D_004FF120;
    r.minDist = 999999.0f;
    r.count = 0;
    r.total = 0.0f;
    r.any = 0;
    for (int i = 0; i < 16; i++) {
        sAvalancheSlot* s = &D_00538938[i];
        if (s->active == 0)
            continue;
        for (sAvNode_A1C0* n = *(sAvNode_A1C0**)s->pad; n != 0; n = n->next) {
            if (n->src == 0)
                continue;
            sVec4_A1C0 d = vSub_A1C0(sVec4_A1C0(p.x, p.y, p.z, 1.0f), n->pos);
            float dist = vLen_A1C0(d);
            if (dist < 225000000.0f) {
                vAddEq_A1C0(r.center, n->pos);
                r.total += n->weight;
                r.minDist = r.minDist <? dist;
                r.any |= *(unsigned short*)(n->src + 0xF0) == 2;
                r.count++;
            }
        }
    }
    vDivEq_A1C0(r.center, (float)r.count);
    r.total = r.total / (float)r.count;
    return r;
}
#endif

