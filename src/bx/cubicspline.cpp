#include "common.h"

//100%
INCLUDE_ASM("bx/cubicspline", cCubicSplineInterpolant_initCommon);
#ifdef SKIP_ASM
void func_0031D790(void* self);
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_0048DB38[];

struct sCubicSplineFlags {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int f3 : 8;
    unsigned int count : 8;
};

struct sCubicSpline {
    sCubicSplineFlags flags;
    float f4;
    void* data;
};

// PORT: binds the real 2-arg body; the unit declares a 1-arg prototype used by callers
extern "C" void cCubicSplineInterpolant_initCommon_impl(sCubicSpline* self, int n) __asm__("cCubicSplineInterpolant_initCommon");
extern "C" void cCubicSplineInterpolant_initCommon_impl(sCubicSpline* self, int n)
{
    if (self->data != 0) {
        func_0031D790(self);
    }
    self->flags.count = n - 1;
    self->data = operator_new__FUi(self->flags.count * 0x14, D_0048DB38, 0, 0);
    self->flags.b1 = 1;
    self->flags.f3 = 0;
}
#endif

extern "C" void cCubicSplineInterpolant_initCommon(void* self);

//100%
INCLUDE_ASM("bx/cubicspline", func_0031D700__FPv);
#ifdef SKIP_ASM
void func_0031D700(void* self)
{
    cCubicSplineInterpolant_initCommon(self);
    *(int*)self &= -2;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031D738__FPvff);
#ifdef SKIP_ASM
void func_0031D738(void* self, float a, float b)
{
    cCubicSplineInterpolant_initCommon(self);
    unsigned int flags = *(unsigned int*)self;
    void* ptr = *(void**)((char*)self + 0x8);
    flags |= 1;
    *(unsigned int*)self = flags;
    *(float*)((char*)ptr + 0x10) = a;
    *(float*)((char*)self + 0x4) = b;
}
#endif

void* cMemMan_free(void* ptr);

//100%
INCLUDE_ASM("bx/cubicspline", func_0031D790__FPv);
#ifdef SKIP_ASM
void func_0031D790(void* self)
{
    if (*(void**)((char*)self + 0x8) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x8));
        *(void**)((char*)self + 0x8) = 0;
    }
    int flags = *(int*)self;
    flags &= -3;
    flags &= -5;
    *(int*)self = flags;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031D7E0);
#ifdef SKIP_ASM
struct sCubicSplineKeyK2 {
    float x;  // 0x0
    float y;  // 0x4
    float tx; // 0x8
    float ty; // 0xC
    float pad_0x10;
};

extern "C" void func_0031D8B0(sCubicSpline* self);

extern "C" void func_0031D7E0(sCubicSpline* self, float x, float y)
{
    if (self->flags.f3 == self->flags.count) {
        ((sCubicSplineKeyK2*)self->data)[self->flags.f3 - 1].tx = x;
        ((sCubicSplineKeyK2*)self->data)[self->flags.f3 - 1].ty = y;
        func_0031D8B0(self);
        self->flags.b2 = 1;
    } else {
        ((sCubicSplineKeyK2*)self->data)[self->flags.f3].x = x;
        ((sCubicSplineKeyK2*)self->data)[self->flags.f3].y = y;
        self->flags.f3++;
    }
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031D8B0);
#ifdef SKIP_ASM
// self->data holds 5 floats per key: x, y, end x, end y, start slope on input;
// d, c, b, a, x of each segment (y = a + b*u + c*u^2 + d*u^3, u = t - x) on output.
// Builds the natural (flags.b0 == 0) or clamped (flags.b0 == 1) cubic spline through the added keys.
extern "C" void func_0031D8B0(sCubicSpline* self)
{
    float x[256];
    float a[256];
    float h[256];
    float alpha[256];
    float l[256];
    float mu[256];
    float z[256];
    float b[256];
    float c[256];
    float d[256];
    int n = self->flags.count;
    int i;
    for (i = 0; i < n; i++) {
        x[i] = ((float*)self->data)[i * 5 + 0];
        a[i] = ((float*)self->data)[i * 5 + 1];
    }
    x[n] = ((float*)self->data)[(n - 1) * 5 + 2];
    a[n] = ((float*)self->data)[(n - 1) * 5 + 3];
    for (i = 0; i < n; i++) {
        h[i] = x[i + 1] - x[i];
    }
    switch (self->flags.b0) {
    case 0:
        for (i = 1; i < n; i++) {
            alpha[i] = 3.0f / h[i] * (a[i + 1] - a[i]) - 3.0f / h[i - 1] * (a[i] - a[i - 1]);
        }
        l[0] = 1.0f;
        mu[0] = 0.0f;
        z[0] = 0.0f;
        for (i = 1; i < n; i++) {
            l[i] = 2.0f * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }
        l[n] = 1.0f;
        z[n] = 0.0f;
        c[n] = 0.0f;
        for (i = n - 1; i >= 0; i--) {
            c[i] = z[i] - mu[i] * c[i + 1];
            b[i] = (a[i + 1] - a[i]) / h[i] - h[i] * (c[i + 1] + 2.0f * c[i]) * 0.33333334f;
            d[i] = (c[i + 1] - c[i]) / (3.0f * h[i]);
        }
        break;
    case 1:
        alpha[0] = 3.0f * (a[1] - a[0]) / h[0] - 3.0f * ((float*)self->data)[4];
        alpha[n] = 3.0f * self->f4 - 3.0f * (a[n] - a[n - 1]) / h[n - 1];
        for (i = 1; i < n; i++) {
            alpha[i] = 3.0f / h[i] * (a[i + 1] - a[i]) - 3.0f / h[i - 1] * (a[i] - a[i - 1]);
        }
        l[0] = 2.0f * h[0];
        mu[0] = 0.5f;
        z[0] = alpha[0] / l[0];
        for (i = 1; i < n; i++) {
            l[i] = 2.0f * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }
        l[n] = h[n - 1] * (2.0f - mu[n - 1]);
        z[n] = (alpha[n] - h[n - 1] * z[n - 1]) / l[n];
        c[n] = z[n];
        for (i = n - 1; i >= 0; i--) {
            c[i] = z[i] - mu[i] * c[i + 1];
            b[i] = (a[i + 1] - a[i]) / h[i] - h[i] * (c[i + 1] + 2.0f * c[i]) * 0.33333334f;
            d[i] = (c[i + 1] - c[i]) / (3.0f * h[i]);
        }
        break;
    }
    for (i = 0; i < n; i++) {
        ((float*)self->data)[i * 5 + 0] = d[i];
        ((float*)self->data)[i * 5 + 1] = c[i];
        ((float*)self->data)[i * 5 + 2] = b[i];
        ((float*)self->data)[i * 5 + 3] = a[i];
        ((float*)self->data)[i * 5 + 4] = x[i];
    }
    self->f4 = x[n];
    *(unsigned int*)&self->flags &= 0xF807FFFF;
}
#endif

INCLUDE_ASM("bx/cubicspline", func_0031DEE0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/cubicspline", func_0031E0E0);
#ifdef SKIP_ASM
extern "C" void func_0031DEE0(void* self, float t);

extern "C" void func_0031E0E0(void* self)
{
    float end = *(float*)((char*)self + 4);
    float start = *(float*)(*(char**)((char*)self + 8) + 0x10);
    float step = (end - start) * 0.010101010091602802f;
    for (float a = start; a <= end; a += step) {
    }
    for (float t = start; t <= end; t += step) {
        func_0031DEE0(self, t);
    }
}
#endif

INCLUDE_ASM("bx/cubicspline", func_0031E190);
//100%
INCLUDE_ASM("bx/cubicspline", func_0031E1D8);
#ifdef SKIP_ASM
// PORT: PS2-only dlmalloc 2.7 library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0031E1D8\n.type func_0031E1D8, @function\nfunc_0031E1D8:\n"
    "daddu $6, $4, $0\n"
    "ori $2, $0, 0xFFFF\n"
    "srl $4, $6, 8\n"
    "sltu $2, $2, $4\n"
    "bnez $2, .L0031E258\n"
    "addiu $3, $4, -0x100\n"
    "srl $3, $3, 16\n"
    "andi $3, $3, 0x8\n"
    "sllv $4, $4, $3\n"
    "addiu $2, $4, -0x1000\n"
    "srl $2, $2, 16\n"
    "andi $5, $2, 0x4\n"
    "sllv $4, $4, $5\n"
    "addu $3, $3, $5\n"
    "addiu $2, $4, -0x4000\n"
    "srl $2, $2, 16\n"
    "andi $5, $2, 0x2\n"
    "sllv $4, $4, $5\n"
    "addu $3, $3, $5\n"
    "srl $2, $4, 15\n"
    "srl $4, $4, 14\n"
    "nor $2, $0, $2\n"
    "and $2, $4, $2\n"
    "addiu $2, $2, 0xD\n"
    "subu $5, $2, $3\n"
    "addiu $2, $5, 0x6\n"
    "sll $3, $5, 2\n"
    "srlv $2, $6, $2\n"
    "andi $2, $2, 0x3\n"
    "addiu $2, $2, 0x20\n"
    "jr $31\n"
    "addu $2, $3, $2\n"
    ".L0031E258:\n"
    "jr $31\n"
    "addiu $2, $0, 0x5F\n"
    ".size func_0031E1D8, . - func_0031E1D8\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031E260__FPv);
#ifdef SKIP_ASM
void func_0031E260(void* self)
{
    char* p = (char*)self + 0x38;
    for (int i = 0x5E; i >= 0; i--) {
        *(void**)(p + 0xC) = p;
        *(void**)(p + 0x8) = p;
        p += 8;
    }
    *(int*)((char*)self + 0x34C) = 0x40000;
    *(int*)((char*)self + 0x344) = 0x8000;
    *(int*)((char*)self + 0x360) |= 1;
    *(int*)self = (*(int*)self & 3) | 0x50;
    *(void**)((char*)self + 0x30) = (char*)self + 0x38;
    *(int*)((char*)self + 0x348) = 0;
    *(int*)((char*)self + 0x354) = 0;
    *(int*)((char*)self + 0x35C) = 0x1000;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031E2D8);
#ifdef SKIP_ASM
// dlmalloc 2.7 sYSMALLOc()
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" unsigned int func_0031FFD8(void* self, long incr); // PORT: 64-bit long param
extern "C" void* func_0031E818(void* ms, unsigned int bytes);
struct sMState_31EEE8;
extern "C" void func_0031EEE8(void* ms, sMState_31EEE8* av);
// PORT: the unit declares func_0031ED60(void*); the body really takes (ms, mem).
extern "C" void func_0031ED60_E2D8(void* ms, void* mem) __asm__("func_0031ED60");
extern "C" int* func_00415FB8();

struct sMChunk_31E2D8
{
    unsigned int prev_size;      // 0x0
    unsigned int size;           // 0x4
};

struct sMState_31E2D8
{
    unsigned int max_fast;              // 0x0
    sMChunk_31E2D8* fastbins[11];       // 0x4
    sMChunk_31E2D8* top;                // 0x30
    char pad34[0x344 - 0x34];
    unsigned int trim_threshold;        // 0x344
    unsigned int top_pad;               // 0x348
    char pad34C[0x35C - 0x34C];
    unsigned int pagesize;              // 0x35C
    unsigned int morecore_properties;   // 0x360
    unsigned int mmapped_mem;           // 0x364
    unsigned int sbrked_mem;            // 0x368
    unsigned int max_sbrked_mem;        // 0x36C
    unsigned int max_mmapped_mem;       // 0x370
    unsigned int max_total_mem;         // 0x374
};

extern "C" void* func_0031E2D8(void* ms, unsigned int nb, sMState_31E2D8* av)
{
    sMChunk_31E2D8* old_top;
    unsigned int old_size;
    char* old_end;
    long size;
    char* brk;
    long correction;
    char* snd_brk;
    unsigned int front_misalign;
    unsigned int end_misalign;
    char* aligned_brk;
    sMChunk_31E2D8* p;
    sMChunk_31E2D8* remainder;
    unsigned int remainder_size;
    unsigned int sum;
    unsigned int pagemask = av->pagesize - 1;

    if (av->max_fast & 2) {
        func_0031EEE8(ms, (sMState_31EEE8*)av);
        return func_0031E818(ms, nb - 15);
    }

    old_top = av->top;
    old_size = old_top->size & ~3U;
    old_end = (char*)old_top + old_size;

    brk = snd_brk = (char*)0xFFFFFFFF;

    size = nb + av->top_pad + 16;
    if (av->morecore_properties & 1)
        size -= old_size;
    size = (size + pagemask) & ~pagemask;
    if (size > 0)
        brk = (char*)func_0031FFD8(ms, size);

    if (brk != (char*)0xFFFFFFFF) {
        av->sbrked_mem += size;

        if (brk == old_end && snd_brk == (char*)0xFFFFFFFF) {
            old_top->size = (size + old_size) | 1;
        } else {
            front_misalign = 0;
            end_misalign = 0;
            correction = 0;
            aligned_brk = brk;

            if ((av->morecore_properties & 1) && old_size != 0 && brk < old_end) {
                av->morecore_properties &= ~1U;
            }

            if (av->morecore_properties & 1) {
                if (old_size != 0)
                    av->sbrked_mem += brk - old_end;

                front_misalign = (unsigned int)(brk + 8) & 15;
                if (front_misalign > 0) {
                    correction = 16 - front_misalign;
                    aligned_brk += correction;
                }

                correction += old_size;

                end_misalign = (unsigned int)(brk + size + correction);
                correction += ((end_misalign + pagemask) & ~pagemask) - end_misalign;

                snd_brk = (char*)func_0031FFD8(ms, correction);

                if (snd_brk == (char*)0xFFFFFFFF) {
                    correction = 0;
                    snd_brk = (char*)func_0031FFD8(ms, 0);
                } else if (snd_brk < brk) {
                    snd_brk = brk + size;
                    correction = 0;
                    av->morecore_properties &= ~1U;
                }
            } else {
                if (snd_brk == (char*)0xFFFFFFFF) {
                    snd_brk = (char*)func_0031FFD8(ms, 0);
                    av->sbrked_mem += snd_brk - brk - size;
                }
            }

            if (snd_brk != (char*)0xFFFFFFFF) {
                av->top = (sMChunk_31E2D8*)aligned_brk;
                av->top->size = (snd_brk - aligned_brk + correction) | 1;
                av->sbrked_mem += correction;

                if (old_size != 0) {
                    old_size = (old_size - 12) & ~15U;
                    old_top->size = old_size | 1;
                    ((sMChunk_31E2D8*)((char*)old_top + old_size))->size = 5;
                    ((sMChunk_31E2D8*)((char*)old_top + old_size + 4))->size = 5;
                    if (old_size >= 16) {
                        unsigned int tt = av->trim_threshold;
                        av->trim_threshold = 0xFFFFFFFF;
                        func_0031ED60_E2D8(ms, (char*)old_top + 8);
                        av->trim_threshold = tt;
                    }
                }
            }
        }

        sum = av->sbrked_mem;
        if (sum > av->max_sbrked_mem)
            av->max_sbrked_mem = sum;
        sum += av->mmapped_mem;
        if (sum > av->max_total_mem)
            av->max_total_mem = sum;

        p = av->top;
        size = p->size & ~3U;
        if ((unsigned int)size >= (unsigned int)(nb + 16)) {
            remainder_size = size - nb;
            remainder = (sMChunk_31E2D8*)((char*)p + nb);
            av->top = remainder;
            p->size = nb | 1;
            remainder->size = remainder_size | 1;
            return (char*)p + 8;
        }
    }

    *func_00415FB8() = 12;
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031E6D8);
#ifdef SKIP_ASM
extern "C" unsigned int func_0031FFD8(void* self, long incr); // PORT: 64-bit long param
// PORT: libgcc 64-bit helpers called by name so the relocations match
// (__divdi3 / __muldi3 in the retail ELF's unnamed libgcc copy).
extern "C" long func_0040FCB0(long a, long b);
extern "C" long func_004114D0(long a, long b);

struct sChunk_31E6D8
{
    unsigned int prev_size;
    unsigned int size;
};

struct sMState_31E6D8
{
    char pad_0x00[0x30];
    sChunk_31E6D8* top;         // 0x30
    char pad_0x34[0x35C - 0x34];
    unsigned int pagesize;      // 0x35C
    char pad_0x360[0x8];
    unsigned int sbrked_mem;    // 0x368
};

extern "C" int func_0031E6D8(void* ms, unsigned int pad, sMState_31E6D8* av)
{
    long top_size;
    long extra;
    long released;
    char* current_brk;
    char* new_brk;
    unsigned int pagesz;

    pagesz = av->pagesize;
    top_size = av->top->size & ~3;
    extra = func_004114D0(func_0040FCB0(top_size - pad - 16 + (pagesz - 1), pagesz) - 1, pagesz);
    if (extra > 0) {
        current_brk = (char*)func_0031FFD8(ms, 0);
        if (current_brk == (char*)av->top + top_size) {
            func_0031FFD8(ms, -extra);
            new_brk = (char*)func_0031FFD8(ms, 0);
            if (new_brk != (char*)0xFFFFFFFF) {
                released = current_brk - new_brk;
                if (released != 0) {
                    av->sbrked_mem -= released;
                    av->top->size = (top_size - released) | 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031E818);
#ifdef SKIP_ASM
// PORT: PS2-only dlmalloc 2.7 library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0031E818\n.type func_0031E818, @function\nfunc_0031E818:\n"
    "addiu $29, $29, -0xA0\n"
    "lui $2, (0xFFFFFFDF >> 16)\n"
    "sq $30, 0x10($29)\n"
    "ori $2, $2, (0xFFFFFFDF & 0xFFFF)\n"
    "sq $16, 0x90($29)\n"
    "daddu $30, $4, $0\n"
    "sq $17, 0x80($29)\n"
    "sltu $2, $2, $5\n"
    "sq $19, 0x60($29)\n"
    "sq $20, 0x50($29)\n"
    "sq $21, 0x40($29)\n"
    "sq $22, 0x30($29)\n"
    "sq $23, 0x20($29)\n"
    "sd $31, 0x0($29)\n"
    "sq $18, 0x70($29)\n"
    "beqz $2, .L0031E874\n"
    "lw $18, 0x0($30)\n"
    "jal func_00415FB8\n"
    "nop\n"
    "addiu $3, $0, 0xC\n"
    "sw $3, 0x0($2)\n"
    "b .L0031ED2C\n"
    "daddu $2, $0, $0\n"
    ".L0031E874:\n"
    "addiu $3, $5, 0x13\n"
    "sltiu $2, $3, 0x10\n"
    "bnez $2, .L0031E890\n"
    "addiu $19, $0, 0x10\n"
    "lui $2, (0xFFFFFFF0 >> 16)\n"
    "ori $2, $2, (0xFFFFFFF0 & 0xFFFF)\n"
    "and $19, $3, $2\n"
    ".L0031E890:\n"
    "lw $3, 0x0($18)\n"
    "xori $2, $3, 0x1\n"
    "andi $2, $2, 0x1\n"
    "beqz $2, .L0031E8C0\n"
    "sltu $2, $3, $19\n"
    "bnel $3, $0, .L0031EC74\n"
    "lw $17, 0x30($18)\n"
    "daddu $4, $30, $0\n"
    "jal func_0031EEE8\n"
    "daddu $5, $18, $0\n"
    "b .L0031EC74\n"
    "lw $17, 0x30($18)\n"
    ".L0031E8C0:\n"
    "bnez $2, .L0031E8EC\n"
    "sltiu $23, $19, 0x100\n"
    "srl $2, $19, 1\n"
    "addiu $2, $2, -0x4\n"
    "addu $4, $18, $2\n"
    "lw $17, 0x0($4)\n"
    "beqz $17, .L0031E8EC\n"
    "addiu $2, $17, 0x8\n"
    "lw $3, 0x8($17)\n"
    "b .L0031ED2C\n"
    "sw $3, 0x0($4)\n"
    ".L0031E8EC:\n"
    "beqz $23, .L0031E92C\n"
    "addiu $2, $19, 0x38\n"
    "addu $6, $18, $2\n"
    "lw $17, 0x4($6)\n"
    "addiu $8, $6, -0x8\n"
    "beq $17, $8, .L0031E950\n"
    "srl $22, $19, 3\n"
    "addu $4, $17, $19\n"
    "lw $7, 0xC($17)\n"
    "lw $3, 0x4($4)\n"
    "addiu $2, $17, 0x8\n"
    "ori $3, $3, 0x1\n"
    "sw $3, 0x4($4)\n"
    "sw $7, 0x4($6)\n"
    "b .L0031ED2C\n"
    "sw $8, 0x8($7)\n"
    ".L0031E92C:\n"
    "jal func_0031E1D8\n"
    "daddu $4, $19, $0\n"
    "lw $3, 0x0($18)\n"
    "andi $3, $3, 0x2\n"
    "beqz $3, .L0031E950\n"
    "daddu $22, $2, $0\n"
    "daddu $4, $30, $0\n"
    "jal func_0031EEE8\n"
    "daddu $5, $18, $0\n"
    ".L0031E950:\n"
    "lw $17, 0x44($18)\n"
    "addiu $21, $18, 0x38\n"
    "beq $17, $21, .L0031EAA0\n"
    "nop\n"
    "lw $3, 0x4($17)\n"
    "nop\n"
    ".L0031E968:\n"
    "lui $2, (0xFFFFFFFC >> 16)\n"
    "ori $2, $2, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $7, 0xC($17)\n"
    "beqz $23, .L0031E9A0\n"
    "and $16, $3, $2\n"
    "bnel $7, $21, .L0031E9A4\n"
    "sw $7, 0x44($18)\n"
    "lw $2, 0x34($18)\n"
    "bnel $17, $2, .L0031E9A4\n"
    "sw $7, 0x44($18)\n"
    "addiu $2, $19, 0x10\n"
    "sltu $2, $2, $16\n"
    "bnez $2, .L0031ECA8\n"
    "addu $6, $17, $19\n"
    ".L0031E9A0:\n"
    "sw $7, 0x44($18)\n"
    ".L0031E9A4:\n"
    "beq $16, $19, .L0031ECE0\n"
    "sw $21, 0x8($7)\n"
    "sltiu $20, $16, 0x100\n"
    "beqz $20, .L0031E9D4\n"
    "srl $5, $16, 3\n"
    "addiu $8, $18, 0x338\n"
    "sll $2, $5, 3\n"
    "addiu $2, $2, 0x38\n"
    "addu $2, $18, $2\n"
    "lw $6, 0x0($2)\n"
    "b .L0031EA60\n"
    "addiu $7, $2, -0x8\n"
    ".L0031E9D4:\n"
    "jal func_0031E1D8\n"
    "daddu $4, $16, $0\n"
    "daddu $5, $2, $0\n"
    "sll $2, $5, 3\n"
    "addiu $2, $2, 0x38\n"
    "addu $4, $18, $2\n"
    "lw $6, 0x0($4)\n"
    "addiu $7, $4, -0x8\n"
    "beq $6, $7, .L0031EA60\n"
    "addiu $8, $18, 0x338\n"
    "lw $3, 0xC($7)\n"
    "lw $2, 0x4($3)\n"
    "sltu $2, $16, $2\n"
    "beqz $2, .L0031EA1C\n"
    "nop\n"
    "daddu $6, $7, $0\n"
    "b .L0031EA60\n"
    "lw $7, 0x4($4)\n"
    ".L0031EA1C:\n"
    "bnez $20, .L0031EA64\n"
    "sra $4, $5, 5\n"
    "lw $2, 0x4($6)\n"
    "ori $16, $16, 0x1\n"
    "sltu $2, $16, $2\n"
    "beql $2, $0, .L0031EA64\n"
    "lw $7, 0xC($6)\n"
    "lw $6, 0x8($6)\n"
    "nop\n"
    ".L0031EA40:\n"
    "lw $2, 0x4($6)\n"
    "sltu $2, $16, $2\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5440FFFA /* bnel $2, $0, .L0031EA40: raw word */\n"
    "lw $6, 0x8($6)\n"
    "lw $7, 0xC($6)\n"
    ".L0031EA60:\n"
    "sra $4, $5, 5\n"
    ".L0031EA64:\n"
    "addiu $3, $0, 0x1\n"
    "sll $4, $4, 2\n"
    "andi $5, $5, 0x1F\n"
    "addu $4, $8, $4\n"
    "sllv $3, $3, $5\n"
    "lw $2, 0x0($4)\n"
    "or $2, $2, $3\n"
    "sw $2, 0x0($4)\n"
    "sw $7, 0xC($17)\n"
    "sw $6, 0x8($17)\n"
    "sw $17, 0xC($6)\n"
    "sw $17, 0x8($7)\n"
    "lw $17, 0x44($18)\n"
    "bnel $17, $21, .L0031E968\n"
    "lw $3, 0x4($17)\n"
    ".L0031EAA0:\n"
    "bnel $23, $0, .L0031EB3C\n"
    "addiu $22, $22, 0x1\n"
    "sll $2, $22, 3\n"
    "addiu $2, $2, 0x38\n"
    "addu $2, $18, $2\n"
    "lw $17, 0x4($2)\n"
    "addiu $8, $2, -0x8\n"
    "beq $17, $8, .L0031EB38\n"
    "daddu $10, $21, $0\n"
    "lui $4, (0xFFFFFFFC >> 16)\n"
    "ori $4, $4, (0xFFFFFFFC & 0xFFFF)\n"
    "ori $11, $19, 0x1\n"
    "lw $2, 0x4($17)\n"
    "nop\n"
    ".L0031EAD8:\n"
    "and $16, $2, $4\n"
    "sltu $3, $16, $19\n"
    "bnel $3, $0, .L0031EB30\n"
    "lw $17, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "subu $9, $16, $19\n"
    "lw $7, 0xC($17)\n"
    "addiu $5, $17, 0x8\n"
    "sltiu $2, $9, 0x10\n"
    "sw $7, 0xC($6)\n"
    "bnez $2, .L0031ECE8\n"
    "sw $6, 0x8($7)\n"
    "addu $6, $17, $19\n"
    "ori $4, $9, 0x1\n"
    "sw $6, 0x44($18)\n"
    "addu $3, $6, $9\n"
    "sw $6, 0x40($18)\n"
    "daddu $2, $5, $0\n"
    "sw $10, 0xC($6)\n"
    "sw $10, 0x8($6)\n"
    "b .L0031ECD4\n"
    "sw $11, 0x4($17)\n"
    ".L0031EB30:\n"
    "bnel $17, $8, .L0031EAD8\n"
    "lw $2, 0x4($17)\n"
    ".L0031EB38:\n"
    "addiu $22, $22, 0x1\n"
    ".L0031EB3C:\n"
    "addiu $4, $18, 0x338\n"
    "srl $9, $22, 5\n"
    "daddu $13, $4, $0\n"
    "sll $2, $9, 2\n"
    "sll $3, $22, 3\n"
    "addu $4, $4, $2\n"
    "sll $5, $9, 8\n"
    "addu $3, $3, $18\n"
    "andi $6, $22, 0x1F\n"
    "addiu $5, $5, 0x38\n"
    "addiu $2, $0, 0x1\n"
    "lui $10, (0xFFFFFFFC >> 16)\n"
    "lw $7, 0x0($4)\n"
    "sllv $6, $2, $6\n"
    "addiu $8, $3, 0x30\n"
    "daddu $11, $21, $0\n"
    "daddu $14, $23, $0\n"
    "addu $5, $5, $18\n"
    "ori $10, $10, (0xFFFFFFFC & 0xFFFF)\n"
    "ori $12, $19, 0x1\n"
    "nop\n"
    ".L0031EB90:\n"
    "sltu $2, $7, $6\n"
    "bnez $2, .L0031EBA8\n"
    "sll $2, $9, 2\n"
    "bnez $6, .L0031EBE8\n"
    "and $2, $6, $7\n"
    "sll $2, $9, 2\n"
    ".L0031EBA8:\n"
    "addu $3, $2, $13\n"
    "addiu $9, $9, 0x1\n"
    ".L0031EBB0:\n"
    "addiu $3, $3, 0x4\n"
    "addiu $4, $4, 0x4\n"
    "sltiu $2, $9, 0x3\n"
    "beqz $2, .L0031EC70\n"
    "addiu $5, $5, 0x100\n"
    "lw $7, 0x0($3)\n"
    ".word 0x50E0FFF9 /* beql $7, $0, .L0031EBB0: raw word */\n"
    "addiu $9, $9, 0x1\n"
    "addiu $8, $5, -0x8\n"
    "b .L0031EBE4\n"
    "addiu $6, $0, 0x1\n"
    "nop\n"
    ".L0031EBE0:\n"
    "addiu $8, $8, 0x8\n"
    ".L0031EBE4:\n"
    "and $2, $6, $7\n"
    ".L0031EBE8:\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5040FFFA /* beql $2, $0, .L0031EBE0: raw word */\n"
    "sll $6, $6, 1\n"
    "lw $17, 0xC($8)\n"
    "bnel $17, $8, .L0031EC20\n"
    "lw $2, 0x4($17)\n"
    "nor $2, $0, $6\n"
    "addiu $8, $17, 0x8\n"
    "and $7, $7, $2\n"
    "sll $6, $6, 1\n"
    "b .L0031EB90\n"
    "sw $7, 0x0($4)\n"
    ".L0031EC20:\n"
    "lw $7, 0xC($17)\n"
    "and $16, $2, $10\n"
    "subu $9, $16, $19\n"
    "sw $7, 0xC($8)\n"
    "sltiu $2, $9, 0x10\n"
    "bnez $2, .L0031ECF4\n"
    "sw $8, 0x8($7)\n"
    "addu $6, $17, $19\n"
    "sw $6, 0x40($18)\n"
    "sw $6, 0x44($18)\n"
    "sw $11, 0xC($6)\n"
    "beqz $14, .L0031EC58\n"
    "sw $11, 0x8($6)\n"
    "sw $6, 0x34($18)\n"
    ".L0031EC58:\n"
    "sw $12, 0x4($17)\n"
    "ori $2, $9, 0x1\n"
    "sw $2, 0x4($6)\n"
    "addu $3, $6, $9\n"
    "b .L0031ED28\n"
    "sw $9, 0x0($3)\n"
    ".L0031EC70:\n"
    "lw $17, 0x30($18)\n"
    ".L0031EC74:\n"
    "lui $2, (0xFFFFFFFC >> 16)\n"
    "ori $2, $2, (0xFFFFFFFC & 0xFFFF)\n"
    "addiu $3, $19, 0x10\n"
    "lw $4, 0x4($17)\n"
    "and $16, $4, $2\n"
    "sltu $3, $16, $3\n"
    "beqz $3, .L0031ED0C\n"
    "daddu $4, $30, $0\n"
    "daddu $5, $19, $0\n"
    "jal func_0031E2D8\n"
    "daddu $6, $18, $0\n"
    "b .L0031ED30\n"
    "lq $16, 0x90($29)\n"
    ".L0031ECA8:\n"
    "subu $9, $16, $19\n"
    "sw $6, 0x34($18)\n"
    "ori $5, $19, 0x1\n"
    "sw $6, 0x40($18)\n"
    "ori $4, $9, 0x1\n"
    "sw $6, 0x44($18)\n"
    "addu $3, $6, $9\n"
    "sw $7, 0xC($6)\n"
    "addiu $2, $17, 0x8\n"
    "sw $7, 0x8($6)\n"
    "sw $5, 0x4($17)\n"
    ".L0031ECD4:\n"
    "sw $4, 0x4($6)\n"
    "b .L0031ED2C\n"
    "sw $9, 0x0($3)\n"
    ".L0031ECE0:\n"
    "b .L0031ECF8\n"
    "addu $4, $17, $19\n"
    ".L0031ECE8:\n"
    "addu $4, $17, $16\n"
    "b .L0031ECFC\n"
    "daddu $2, $5, $0\n"
    ".L0031ECF4:\n"
    "addu $4, $17, $16\n"
    ".L0031ECF8:\n"
    "addiu $2, $17, 0x8\n"
    ".L0031ECFC:\n"
    "lw $3, 0x4($4)\n"
    "ori $3, $3, 0x1\n"
    "b .L0031ED2C\n"
    "sw $3, 0x4($4)\n"
    ".L0031ED0C:\n"
    "addu $6, $17, $19\n"
    "ori $2, $19, 0x1\n"
    "sw $6, 0x30($18)\n"
    "subu $9, $16, $19\n"
    "sw $2, 0x4($17)\n"
    "ori $3, $9, 0x1\n"
    "sw $3, 0x4($6)\n"
    ".L0031ED28:\n"
    "addiu $2, $17, 0x8\n"
    ".L0031ED2C:\n"
    "lq $16, 0x90($29)\n"
    ".L0031ED30:\n"
    "lq $17, 0x80($29)\n"
    "lq $18, 0x70($29)\n"
    "lq $19, 0x60($29)\n"
    "lq $20, 0x50($29)\n"
    "lq $21, 0x40($29)\n"
    "lq $22, 0x30($29)\n"
    "lq $23, 0x20($29)\n"
    "lq $30, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xA0\n"
    ".size func_0031E818, . - func_0031E818\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031ED60);
#ifdef SKIP_ASM
// dlmalloc 2.7 free()
struct sMChunk_31ED60
{
    unsigned int prev_size;      // 0x0
    unsigned int size;           // 0x4
    sMChunk_31ED60* fd;          // 0x8
    sMChunk_31ED60* bk;          // 0xC
};

struct sMState_31ED60
{
    unsigned int max_fast;              // 0x0
    sMChunk_31ED60* fastbins[11];       // 0x4
    sMChunk_31ED60* top;                // 0x30
    sMChunk_31ED60* last_remainder;     // 0x34
    sMChunk_31ED60* bins[0xC3];         // 0x38
    unsigned int trim_threshold;        // 0x344
    unsigned int top_pad;               // 0x348
};

struct sMalloc_31ED60
{
    sMState_31ED60* av;
};

struct sMState_31EEE8;
struct sMState_31E6D8;
extern "C" void func_0031EEE8(void* ms, sMState_31EEE8* av);
extern "C" int func_0031E6D8(void* ms, unsigned int pad, sMState_31E6D8* av);

// PORT: the unit declares func_0031ED60(void*); the body really takes (ms, mem).
extern "C" void func_0031ED60_free(sMalloc_31ED60* ms, void* mem) __asm__("func_0031ED60");

extern "C" void func_0031ED60_free(sMalloc_31ED60* ms, void* mem)
{
    sMState_31ED60* av = ms->av;
    sMChunk_31ED60* p;
    sMChunk_31ED60* nextchunk;
    unsigned int size;
    unsigned int nextsize;
    unsigned int prevsize;
    int nextinuse;
    sMChunk_31ED60* bck;
    sMChunk_31ED60* fwd;
    sMChunk_31ED60** fb;

    // PORT: chunk header reads go through (int)mem - 8 (pointer in int) to match gcc 2.95 offset folding
    if (mem != 0)
    {
        size = ((sMChunk_31ED60*)((int)mem - 8))->size & ~3U;
        p = (sMChunk_31ED60*)((char*)mem - 8);
        if (size <= av->max_fast)
        {
            av->max_fast |= 3;
            fb = &av->fastbins[(size >> 3) - 2];
            *(sMChunk_31ED60**)mem = *fb;
            *fb = p;
        }
        else if (!(((sMChunk_31ED60*)((int)mem - 8))->size & 2))
        {
            av->max_fast |= 1;
            nextchunk = (sMChunk_31ED60*)((char*)p + size);
            nextsize = nextchunk->size & ~3U;
            if (!(((sMChunk_31ED60*)((int)mem - 8))->size & 1))
            {
                prevsize = p->prev_size;
                size += prevsize;
                p = (sMChunk_31ED60*)((char*)p - (long)prevsize);
                fwd = p->fd;
                bck = p->bk;
                fwd->bk = bck;
                bck->fd = fwd;
            }
            if (nextchunk != av->top)
            {
                nextinuse = ((sMChunk_31ED60*)((char*)nextchunk + nextsize))->size & 1;
                nextchunk->size = nextsize;
                if (!nextinuse)
                {
                    fwd = nextchunk->fd;
                    bck = nextchunk->bk;
                    fwd->bk = bck;
                    bck->fd = fwd;
                    size += nextsize;
                }
                fwd = ((sMChunk_31ED60*)((char*)&av->bins[1 << 1] - 8))->fd;
                p->bk = (sMChunk_31ED60*)((char*)&av->bins[1 << 1] - 8);
                p->fd = fwd;
                ((sMChunk_31ED60*)((char*)&av->bins[1 << 1] - 8))->fd = p;
                fwd->bk = p;
                p->size = size | 1;
                ((sMChunk_31ED60*)((char*)p + size))->prev_size = size;
            }
            else
            {
                size += nextsize;
                p->size = size | 1;
                av->top = p;
            }
            if (size >= 0x4000)
            {
                if (av->max_fast & 2)
                    func_0031EEE8(ms, (sMState_31EEE8*)av);
                if ((av->top->size & ~3U) >= av->trim_threshold)
                    func_0031E6D8(ms, av->top_pad, (sMState_31E6D8*)av);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031EEE8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
void func_0031E260(void* av);

// dlmalloc 2.7 malloc_consolidate()
struct sMChunk_31EEE8
{
    unsigned int prev_size;      // 0x0
    unsigned int size;           // 0x4
    sMChunk_31EEE8* fd;          // 0x8
    sMChunk_31EEE8* bk;          // 0xC
};

struct sMState_31EEE8
{
    unsigned int max_fast;              // 0x0
    sMChunk_31EEE8* fastbins[11];       // 0x4
    sMChunk_31EEE8* top;                // 0x30
    sMChunk_31EEE8* last_remainder;     // 0x34
    sMChunk_31EEE8* bins[4];            // 0x38
};

extern "C" void func_0031EEE8(void* ms, sMState_31EEE8* av)
{
    sMChunk_31EEE8** fb;
    sMChunk_31EEE8** maxfb;
    sMChunk_31EEE8* p;
    sMChunk_31EEE8* nextp;
    sMChunk_31EEE8* unsorted_bin;
    sMChunk_31EEE8* first_unsorted;
    sMChunk_31EEE8* nextchunk;
    unsigned int size;
    unsigned int nextsize;
    unsigned int prevsize;
    int nextinuse;
    sMChunk_31EEE8* bck;
    sMChunk_31EEE8* fwd;

    if (av->max_fast != 0) {
        av->max_fast &= ~2U;
        unsorted_bin = (sMChunk_31EEE8*)((char*)&av->bins[1 << 1] - 8);
        maxfb = &av->fastbins[(av->max_fast >> 3) - 2];
        fb = &av->fastbins[0];
        do {
            if ((p = *fb) != 0) {
                *fb = 0;
                do {
                    nextp = p->fd;
                    size = p->size & ~1U;
                    nextchunk = (sMChunk_31EEE8*)((char*)p + size);
                    nextsize = nextchunk->size & ~3U;
                    if (!(p->size & 1)) {
                        prevsize = p->prev_size;
                        size += prevsize;
                        p = (sMChunk_31EEE8*)((char*)p - (long)prevsize);
                        fwd = p->fd;
                        bck = p->bk;
                        fwd->bk = bck;
                        bck->fd = fwd;
                    }
                    if (nextchunk != av->top) {
                        nextinuse = ((sMChunk_31EEE8*)((char*)nextchunk + nextsize))->size & 1;
                        nextchunk->size = nextsize;
                        if (!nextinuse) {
                            size += nextsize;
                            fwd = nextchunk->fd;
                            bck = nextchunk->bk;
                            fwd->bk = bck;
                            bck->fd = fwd;
                        }
                        first_unsorted = unsorted_bin->fd;
                        unsorted_bin->fd = p;
                        first_unsorted->bk = p;
                        p->size = size | 1;
                        p->bk = unsorted_bin;
                        p->fd = first_unsorted;
                        ((sMChunk_31EEE8*)((char*)p + size))->prev_size = size;
                    } else {
                        size += nextsize;
                        p->size = size | 1;
                        av->top = p;
                    }
                } while ((p = nextp) != 0);
            }
        } while (fb++ != maxfb);
    } else {
        func_0031E260(av);
    }
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F018);
#ifdef SKIP_ASM
struct sMChunk_31F018
{
    unsigned int prev_size;      // 0x0
    unsigned int size;           // 0x4
    sMChunk_31F018* fd;          // 0x8
    sMChunk_31F018* bk;          // 0xC
};

struct sMState_31F018
{
    unsigned int max_fast;       // 0x0
    char pad[0x30 - 4];
    sMChunk_31F018* top;         // 0x30
};

extern "C" void func_003E6574(void* dst, const void* src, unsigned int n);
// PORT: the unit declares func_0031ED60(void*); the body really takes (ms, mem).
extern "C" void func_0031ED60_F018(void* ms, void* mem) __asm__("func_0031ED60");
extern "C" void* func_0031F018_realloc(void* ms, unsigned int* oldmem, unsigned int bytes) __asm__("func_0031F018");

extern "C" void* func_0031F018_realloc(void* ms, unsigned int* oldmem, unsigned int bytes)
{
    sMState_31F018* av = *(sMState_31F018**)ms;
    unsigned int nb;
    sMChunk_31F018* oldp;
    unsigned int oldsize;
    sMChunk_31F018* newp;
    unsigned int newsize;
    unsigned int* newmem;
    sMChunk_31F018* next;
    sMChunk_31F018* remainder;
    unsigned int remainder_size;
    sMChunk_31F018* bck;
    sMChunk_31F018* fwd;
    unsigned int copysize;
    unsigned int ncopies;
    unsigned int* s;
    unsigned int* d;

    if (oldmem == 0)
        return func_0031E818(ms, bytes);
    if (bytes < (unsigned int)-32) {
        nb = bytes + 4 + 15;
        nb = nb < 16 ? 16 : nb & ~15U;
        oldp = (sMChunk_31F018*)((char*)oldmem - 8);
        oldsize = ((sMChunk_31F018*)((int)oldmem - 8))->size & ~3U;
        if (!(((sMChunk_31F018*)((int)oldmem - 8))->size & 2)) {
            if (oldsize >= nb) {
                newp = oldp;
                newsize = oldsize;
            } else {
                next = (sMChunk_31F018*)((char*)oldp + oldsize);
                if (next == av->top && (newsize = oldsize + (next->size & ~3U)) >= nb + 16) {
                    ((sMChunk_31F018*)((int)oldmem - 8))->size = (((sMChunk_31F018*)((int)oldmem - 8))->size & 1) | nb;
                    av->top = (sMChunk_31F018*)((char*)oldp + nb);
                    av->top->size = (newsize - nb) | 1;
                    return (char*)oldp + 8;
                } else if (next != av->top && !(((sMChunk_31F018*)((char*)next + (next->size & ~1U)))->size & 1)
                           && (newsize = oldsize + (next->size & ~3U)) >= nb) {
                    newp = oldp;
                    fwd = next->fd;
                    bck = next->bk;
                    fwd->bk = bck;
                    bck->fd = fwd;
                } else {
                    newmem = (unsigned int*)func_0031E818(ms, nb - 15);
                    if (newmem == 0)
                        return 0;
                    newp = (sMChunk_31F018*)((char*)newmem - 8);
                    newsize = ((sMChunk_31F018*)((int)newmem - 8))->size & ~3U;
                    if (newp == next) {
                        newsize += oldsize;
                        newp = oldp;
                    } else {
                        copysize = oldsize - 4;
                        s = oldmem;
                        d = newmem;
                        ncopies = copysize >> 2;
                        if (ncopies > 9)
                            func_003E6574(d, s, copysize);
                        else {
                            d[0] = s[0];
                            d[1] = s[1];
                            d[2] = s[2];
                            if (ncopies > 4) {
                                d[3] = s[3];
                                d[4] = s[4];
                                if (ncopies > 6) {
                                    d[5] = s[5];
                                    d[6] = s[6];
                                    if (ncopies > 8) {
                                        d[7] = s[7];
                                        d[8] = s[8];
                                    }
                                }
                            }
                        }
                        func_0031ED60_F018(ms, oldmem);
                        return (char*)newp + 8;
                    }
                }
            }
            remainder_size = newsize - nb;
            if (remainder_size < 16) {
                newp->size = (newp->size & 1) | newsize;
                ((sMChunk_31F018*)((char*)newp + newsize))->size |= 1;
            } else {
                remainder = (sMChunk_31F018*)((char*)newp + nb);
                newp->size = (newp->size & 1) | nb;
                remainder->size = remainder_size | 1;
                ((sMChunk_31F018*)((char*)remainder + remainder_size))->size |= 1;
                func_0031ED60_F018(ms, (char*)remainder + 8);
            }
            return (char*)newp + 8;
        }
    }
    *func_00415FB8() = 12;
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F2C8);
#ifdef SKIP_ASM
// dlmalloc 2.7 mEMALIGn()
extern "C" void* func_0031E818(void* ms, unsigned int bytes);
// PORT: the unit declares func_0031ED60(void*); the body really takes (ms, mem).
extern "C" void func_0031ED60_F2C8(void* ms, void* mem) __asm__("func_0031ED60");
extern "C" int* func_00415FB8();

struct sMChunk_31F2C8
{
    unsigned int prev_size;      // 0x0
    unsigned int size;           // 0x4
};

// PORT: the unit declares func_0031F2C8(void*); the body really takes (ms, alignment, bytes).
extern "C" void* func_0031F2C8_memalign(void* ms, unsigned int alignment, unsigned int bytes) __asm__("func_0031F2C8");

extern "C" void* func_0031F2C8_memalign(void* ms, unsigned int alignment, unsigned int bytes)
{
    unsigned int nb;
    char* m;
    sMChunk_31F2C8* p;
    char* brk;
    sMChunk_31F2C8* newp;
    unsigned int newsize;
    unsigned int leadsize;
    sMChunk_31F2C8* remainder;
    unsigned int remainder_size;
    unsigned int size;

    if (alignment <= 16)
        return func_0031E818(ms, bytes);
    if (alignment < 16)
        alignment = 16;
    if ((alignment & (alignment - 1)) != 0) {
        unsigned int a = 16 * 2;
        while (a < alignment)
            a <<= 1;
        alignment = a;
    }
    if (bytes >= (unsigned int)-32) {
        *func_00415FB8() = 12;
        return 0;
    }
    nb = (bytes + 4 + 15 < 16) ? 16 : (bytes + 4 + 15) & ~15;
    m = (char*)func_0031E818(ms, nb + alignment + 16);
    if (m == 0)
        return 0;
    p = (sMChunk_31F2C8*)(m - 8);
    // PORT: chunk header reads go through (int)m - 8 (pointer in int) to match gcc 2.95 offset folding
    if ((unsigned int)m % alignment != 0) {
        brk = (char*)(((unsigned int)(m + alignment - 1) & -(int)alignment) - 8);
        if ((unsigned int)(brk - (char*)p) < 16)
            brk += alignment;
        newp = (sMChunk_31F2C8*)brk;
        leadsize = brk - (char*)p;
        newsize = (((sMChunk_31F2C8*)((int)m - 8))->size & ~3) - leadsize;
        if (((sMChunk_31F2C8*)((int)m - 8))->size & 2) {
            newp->prev_size = ((sMChunk_31F2C8*)((int)m - 8))->prev_size + leadsize;
            newp->size = newsize | 2;
            return (char*)newp + 8;
        }
        newp->size = newsize | 1;
        ((sMChunk_31F2C8*)((char*)newp + newsize))->size |= 1;
        ((sMChunk_31F2C8*)((int)m - 8))->size = (((sMChunk_31F2C8*)((int)m - 8))->size & 1) | leadsize;
        func_0031ED60_F2C8(ms, (char*)p + 8);
        p = newp;
    }
    if (!(p->size & 2)) {
        size = p->size & ~3;
        if (size > nb + 16) {
            remainder_size = size - nb;
            remainder = (sMChunk_31F2C8*)((char*)p + nb);
            remainder->size = remainder_size | 1;
            p->size = (p->size & 1) | nb;
            func_0031ED60_F2C8(ms, (char*)remainder + 8);
        }
    }
    return (char*)p + 8;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F4E8);
#ifdef SKIP_ASM
// dlmalloc 2.7 mEMALIGn() variant: aligns the address mem + offset instead of mem
extern "C" void* func_0031E818(void* ms, unsigned int bytes);
// PORT: the unit declares func_0031ED60(void*); the body really takes (ms, mem).
extern "C" void func_0031ED60_F4E8(void* ms, void* mem) __asm__("func_0031ED60");
extern "C" int* func_00415FB8();

struct sMChunk_31F4E8
{
    unsigned int prev_size;      // 0x0
    unsigned int size;           // 0x4
};

// PORT: the unit declares func_0031F4E8(void*); the body really takes (ms, alignment, bytes, offset).
extern "C" void* func_0031F4E8_memalign(void* ms, unsigned int alignment, unsigned int bytes, unsigned int offset) __asm__("func_0031F4E8");

extern "C" void* func_0031F4E8_memalign(void* ms, unsigned int alignment, unsigned int bytes, unsigned int offset)
{
    unsigned int nb;
    char* m;
    sMChunk_31F4E8* p;
    char* brk;
    sMChunk_31F4E8* newp;
    unsigned int newsize;
    unsigned int leadsize;
    sMChunk_31F4E8* remainder;
    unsigned int remainder_size;
    unsigned int size;

    if (alignment <= 16)
        return func_0031E818(ms, bytes);
    if (alignment < 16)
        alignment = 16;
    if ((alignment & (alignment - 1)) != 0) {
        unsigned int a = 16 * 2;
        while (a < alignment)
            a <<= 1;
        alignment = a;
    }
    bytes += offset;
    if (bytes >= (unsigned int)-32) {
        *func_00415FB8() = 12;
        return 0;
    }
    nb = (bytes + 4 + 15 < 16) ? 16 : (bytes + 4 + 15) & ~15;
    m = (char*)func_0031E818(ms, nb + alignment + 16);
    if (m == 0)
        return 0;
    p = (sMChunk_31F4E8*)(m - 8);
    // PORT: chunk header reads go through (int)m - 8 (pointer in int) to match gcc 2.95 offset folding
    if ((unsigned int)(m + offset) % alignment != 0) {
        brk = (char*)(((unsigned int)(m + offset + alignment - 1) & -(int)alignment) - offset - 8);
        if ((unsigned int)(brk - (char*)p) < 16)
            brk += alignment;
        newp = (sMChunk_31F4E8*)brk;
        leadsize = brk - (char*)p;
        newsize = (((sMChunk_31F4E8*)((int)m - 8))->size & ~3) - leadsize;
        if (((sMChunk_31F4E8*)((int)m - 8))->size & 2) {
            newp->prev_size = ((sMChunk_31F4E8*)((int)m - 8))->prev_size + leadsize;
            newp->size = newsize | 2;
            return (char*)newp + 8;
        }
        newp->size = newsize | 1;
        ((sMChunk_31F4E8*)((char*)newp + newsize))->size |= 1;
        ((sMChunk_31F4E8*)((int)m - 8))->size = (((sMChunk_31F4E8*)((int)m - 8))->size & 1) | leadsize;
        func_0031ED60_F4E8(ms, (char*)p + 8);
        p = newp;
    }
    if (!(p->size & 2)) {
        size = p->size & ~3;
        if (size > nb + 16) {
            remainder_size = size - nb;
            remainder = (sMChunk_31F4E8*)((char*)p + nb);
            remainder->size = remainder_size | 1;
            p->size = (p->size & 1) | nb;
            func_0031ED60_F4E8(ms, (char*)remainder + 8);
        }
    }
    return (char*)p + 8;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F718);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

// dlmalloc 2.7 cALLOc()
extern "C" void* func_0031F718(void* ms, unsigned int n, unsigned int elem_size)
{
    unsigned int bytes = n * elem_size;
    void* mem = func_0031E818(ms, bytes);
    if (mem != 0) {
        unsigned int csz = *(unsigned int*)((char*)mem - 4);
        if (!(csz & 2)) {
            unsigned int clearsize = (csz & ~3U) - 4;
            unsigned int nclears = clearsize >> 2;
            unsigned int* d = (unsigned int*)mem;
            if (nclears > 9) {
                func_003E6448(d, 0, clearsize);
            } else {
                d[0] = 0;
                d[1] = 0;
                d[2] = 0;
                if (nclears > 4) {
                    d[3] = 0;
                    d[4] = 0;
                    if (nclears > 6) {
                        d[5] = 0;
                        d[6] = 0;
                        if (nclears > 8) {
                            d[7] = 0;
                            d[8] = 0;
                        }
                    }
                }
            }
        } else {
            func_003E6448(mem, 0, (csz & ~3U) - 8);
        }
    }
    return mem;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F7F0);
#ifdef SKIP_ASM
extern "C" int func_0031ED60_F7F0(void* ms, void* mem) __asm__("func_0031ED60");
extern "C" int func_0031F7F0(void* ms, void* mem)
{
    return func_0031ED60_F7F0(ms, mem);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F810);
#ifdef SKIP_ASM
extern "C" void* func_0031F858_F810(void* ms, unsigned int n, void* sizes, int opts, void** chunks) __asm__("func_0031F858");
extern "C" void* func_0031F810(void* ms, unsigned int n, unsigned int size, void** chunks)
{
    return func_0031F858_F810(ms, n, &size, 3, chunks);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F838);
#ifdef SKIP_ASM
extern "C" void* func_0031F858_F838(void* ms, unsigned int n, void* sizes, int opts, void** chunks) __asm__("func_0031F858");
extern "C" void* func_0031F838(void* ms, unsigned int n, void* sizes, void** chunks)
{
    return func_0031F858_F838(ms, n, sizes, 0, chunks);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031F858);
#ifdef SKIP_ASM
struct sMChunk_31F858
{
    unsigned int prev_size;
    unsigned int size;
};

struct sMState_31F858
{
    unsigned int max_fast;      // 0x0
    char pad[0x354 - 4];
    unsigned int n_mmaps_max;   // 0x354
};

// PORT: the unit declares func_0031F858(void*); the body really takes (ms, n, sizes, opts, chunks).
extern "C" void* func_0031F858_ialloc(void* ms, unsigned int n_elements, unsigned int* sizes, int opts, void** chunks) __asm__("func_0031F858");
extern "C" void func_003E6448_F858(void* dst, int c, unsigned int n) __asm__("func_003E6448");

extern "C" void* func_0031F858_ialloc(void* ms, unsigned int n_elements, unsigned int* sizes, int opts, void** chunks)
{
    sMState_31F858* av = *(sMState_31F858**)ms;
    unsigned int element_size;
    unsigned int contents_size;
    unsigned int array_size;
    void* mem;
    sMChunk_31F858* p;
    unsigned int remainder_size;
    void** marray;
    sMChunk_31F858* array_chunk;
    unsigned int mmx;
    unsigned int size;
    unsigned int i;

    if (av->max_fast == 0)
        func_0031EEE8(ms, (sMState_31EEE8*)av);

    if (chunks != 0) {
        if (n_elements == 0)
            return chunks;
        marray = chunks;
        array_size = 0;
    } else {
        if (n_elements == 0)
            return func_0031E818(ms, 0);
        marray = 0;
        unsigned int r = n_elements * 4 + 4 + 15;
        array_size = r < 16 ? 16 : r & ~15U;
    }

    if (opts & 1) {
        unsigned int r = *sizes + 4 + 15;
        element_size = r < 16 ? 16 : r & ~15U;
        contents_size = n_elements * element_size;
    } else {
        element_size = 0;
        contents_size = 0;
        for (i = 0; i != n_elements; ++i) {
            unsigned int r = sizes[i] + 4 + 15;
            contents_size += r < 16 ? 16 : r & ~15U;
        }
    }

    size = contents_size + array_size - 15;

    mmx = av->n_mmaps_max;
    av->n_mmaps_max = 0;
    mem = func_0031E818(ms, size);
    av->n_mmaps_max = mmx;
    if (mem == 0)
        return 0;

    p = (sMChunk_31F858*)((char*)mem - 8);
    remainder_size = ((sMChunk_31F858*)((int)mem - 8))->size & ~3U;

    if (opts & 2) {
        unsigned int t = array_size + 4;
        func_003E6448_F858(mem, 0, remainder_size - t);
    }

    if (marray == 0) {
        array_chunk = (sMChunk_31F858*)((char*)p + contents_size);
        marray = (void**)((char*)array_chunk + 8);
        array_chunk->size = (remainder_size - contents_size) | 1;
        remainder_size = contents_size;
    }

    for (i = 0;; ++i) {
        marray[i] = (char*)p + 8;
        if (i != n_elements - 1) {
            if (element_size != 0)
                size = element_size;
            else {
                unsigned int r = sizes[i] + 4 + 15;
                size = r < 16 ? 16 : r & ~15U;
            }
            remainder_size -= size;
            p->size = size | 1;
            p = (sMChunk_31F858*)((char*)p + size);
        } else {
            p->size = remainder_size | 1;
            break;
        }
    }
    return marray;
}
#endif
//100%
INCLUDE_ASM("bx/cubicspline", func_0031FAA8);
#ifdef SKIP_ASM
// dlmalloc 2.7 vALLOc(): memalign to the page size.
struct sMState_31FAA8
{
    unsigned int max_fast;              // 0x0
    char pad4[0x35C - 4];
    unsigned int pagesize;              // 0x35C
};

extern "C" void* func_0031FAA8(void** ms, unsigned int bytes)
{
    sMState_31FAA8* av = *(sMState_31FAA8**)ms;
    if (av->max_fast == 0) {
        func_0031EEE8(ms, (sMState_31EEE8*)av);
    }
    return func_0031F2C8_memalign(ms, av->pagesize, bytes);
}
#endif
//100%
INCLUDE_ASM("bx/cubicspline", func_0031FB00);
#ifdef SKIP_ASM
// dlmalloc 2.7 pvALLOc(): memalign to the page size, with the size rounded up to a page.
struct sMState_31FB00
{
    unsigned int max_fast;              // 0x0
    char pad4[0x35C - 4];
    unsigned int pagesize;              // 0x35C
};

extern "C" void* func_0031FB00(void** ms, unsigned int bytes)
{
    sMState_31FB00* av = *(sMState_31FB00**)ms;
    if (av->max_fast == 0) {
        func_0031EEE8(ms, (sMState_31EEE8*)av);
    }
    unsigned int pagesize = av->pagesize;
    return func_0031F2C8_memalign(ms, pagesize, (bytes + pagesize - 1) & ~(pagesize - 1));
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031FB68);
#ifdef SKIP_ASM
// dlmalloc 2.7 malloc_trim()
struct sMState_31E6D8;
extern "C" int func_0031E6D8(void* ms, unsigned int pad, sMState_31E6D8* av);

extern "C" int func_0031FB68(void** ms, unsigned int pad)
{
    sMState_31E6D8* av = *(sMState_31E6D8**)ms;
    func_0031EEE8(ms, (sMState_31EEE8*)av);
    return func_0031E6D8(ms, pad, av);
}
#endif
//100%
INCLUDE_ASM("bx/cubicspline", func_0031FBB8__FPvT0);
#ifdef SKIP_ASM
unsigned int func_0031FBB8(void* self, void* mem)
{
    if (mem != 0) {
        unsigned int size = *(unsigned int*)((char*)mem - 4);
        char* p = (char*)mem - 8;
        if (size & 2) {
            return (size & ~3U) - 8;
        } else if (*(unsigned int*)(p + (size & ~1U) + 4) & 1) {
            return (size & ~3U) - 4;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031FC20);
#ifdef SKIP_ASM
// dlmalloc 2.7 mALLINFo()
struct sMChunk_31FC20
{
    unsigned int prev_size;      // 0x0
    unsigned int size;           // 0x4
    sMChunk_31FC20* fd;          // 0x8
    sMChunk_31FC20* bk;          // 0xC
};

struct sMState_31FC20
{
    unsigned int max_fast;              // 0x0
    sMChunk_31FC20* fastbins[11];       // 0x4
    sMChunk_31FC20* top;                // 0x30
    sMChunk_31FC20* last_remainder;     // 0x34
    sMChunk_31FC20* bins[192];          // 0x38
    char pad338[0x18];                  // 0x338
    int n_mmaps;                        // 0x350
    int n_mmaps_max;                    // 0x354
    int max_n_mmaps;                    // 0x358
    unsigned int pagesize;              // 0x35C
    unsigned int morecore_properties;   // 0x360
    unsigned int mmapped_mem;           // 0x364
    unsigned int sbrked_mem;            // 0x368
    unsigned int max_sbrked_mem;        // 0x36C
    unsigned int max_mmapped_mem;       // 0x370
    unsigned int max_total_mem;         // 0x374
};

struct sMallinfo_31FC20
{
    int arena;
    int ordblks;
    int smblks;
    int hblks;
    int hblkhd;
    int usmblks;
    int fsmblks;
    int uordblks;
    int fordblks;
    int keepcost;
};

struct sMState_31EEE8;
extern "C" void func_0031EEE8(void* ms, sMState_31EEE8* av);

extern "C" sMallinfo_31FC20 func_0031FC20(void* ms)
{
    sMState_31FC20* av = *(sMState_31FC20**)ms;
    sMallinfo_31FC20 mi;
    int i;
    sMChunk_31FC20* b;
    sMChunk_31FC20* p;
    unsigned int avail;
    unsigned int fastavail;
    int nblocks;
    int nfastblocks;

    if (av->top == 0) {
        func_0031EEE8(ms, (sMState_31EEE8*)av);
    }

    avail = av->top->size & ~3U;
    nblocks = 1;

    nfastblocks = 0;
    fastavail = 0;

    for (i = 0; (unsigned int)i < 11U; ++i) {
        for (p = av->fastbins[i]; p != 0; p = p->fd) {
            ++nfastblocks;
            fastavail += p->size & ~3U;
        }
    }

    avail += fastavail;

    for (i = 1; i < 96; ++i) {
        sMChunk_31FC20** bp = &av->bins[i << 1];
        b = (sMChunk_31FC20*)((char*)bp - 8);
        for (p = bp[1]; p != b; p = p->bk) {
            ++nblocks;
            avail += p->size & ~3U;
            if (p == p->bk->bk) break;
            if (p == p->bk && p != b) break;
        }
    }

    mi.smblks = nfastblocks;
    mi.ordblks = nblocks;
    mi.fordblks = avail;
    mi.uordblks = av->sbrked_mem - avail;
    mi.arena = av->sbrked_mem;
    mi.hblks = av->n_mmaps;
    mi.hblkhd = av->mmapped_mem;
    mi.fsmblks = fastavail;
    mi.keepcost = av->top->size & ~3U;
    mi.usmblks = av->max_total_mem;
    return mi;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031FE28);
#ifdef SKIP_ASM
extern "C" void func_0031FE28(void) {

}
#endif
//100%
INCLUDE_ASM("bx/cubicspline", func_0031FE30);
#ifdef SKIP_ASM
extern "C" int func_0031FE30(void** self, int kind, unsigned int val) {
    char* ms = (char*)*self;
    func_0031EEE8(self, (sMState_31EEE8*)ms);
    switch (kind) {
    case 1:
        if (val < 0x51U) {
            int low = (*(int*)ms) & 3;
            int res;
            if (val != 0) {
                unsigned int t = val + 0x13;
                if (t >= 0x10U) {
                    res = (t & 0xFFFFFFF0) | low;
                } else {
                    res = low | 0x10;
                }
            } else {
                res = low | 8;
            }
            *(int*)ms = res;
            return 1;
        }
        return 0;
    case -1:
        *(unsigned int*)(ms + 0x344) = val;
        return 1;
    case -2:
        *(unsigned int*)(ms + 0x348) = val;
        return 1;
    case -3:
        *(unsigned int*)(ms + 0x34C) = val;
        return 1;
    case -4:
        if (val == 0) {
            *(int*)(ms + 0x354) = 0;
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031FF20__FPv);
#ifdef SKIP_ASM
void* func_0031FF20(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x0) = 0;
    return self;
}
#endif

void operator_delete(int* ptr);

//100%
INCLUDE_ASM("bx/cubicspline", func_0031FF38__FPvi);
#ifdef SKIP_ASM
void func_0031FF38(void* self, int flags)
{
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031FF60);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

extern "C" void func_0031FF60(void* self, unsigned int base, unsigned int size)
{
    unsigned int start = (base + 0xF) & 0xFFFFFFF0;
    *(unsigned int*)((char*)self + 0x4) = start;
    *(unsigned int*)((char*)self + 0x0) = start;
    *(unsigned int*)((char*)self + 0xC) = (size - (start - base)) & 0xFFFFFFF0;
    func_003E6448((void*)start, 0, 0x378);
    *(unsigned int*)((char*)self + 0x4) += 0x380;
    *(unsigned int*)((char*)self + 0xC) -= 0x380;
    *(unsigned int*)((char*)self + 0x8) = *(unsigned int*)((char*)self + 0x4);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_0031FFD8);
#ifdef SKIP_ASM
extern "C" unsigned int func_0031FFD8(void* self, long incr) // PORT: 64-bit long param
{
    if (incr >= 0) {
        unsigned int old = *(unsigned int*)((char*)self + 0x8);
        unsigned int top = old + incr;
        if (top <= *(unsigned int*)((char*)self + 0x4) + *(unsigned int*)((char*)self + 0xC)) {
            *(unsigned int*)((char*)self + 0x8) = top;
            return old;
        }
    } else {
        return *(unsigned int*)((char*)self + 0x8) += incr;
    }
    return 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320038);
#ifdef SKIP_ASM
extern "C" void* func_0031E818(void* ms, unsigned int bytes);
extern "C" void* func_00320038(void* ms, unsigned int bytes)
{
    return func_0031E818(ms, bytes);
}
#endif

extern "C" void* func_0031F2C8(void* self);

//100%
INCLUDE_ASM("bx/cubicspline", func_00320058__FPv);
#ifdef SKIP_ASM
void* func_00320058(void* self)
{
    return func_0031F2C8(self);
}
#endif

extern "C" void* func_0031F4E8(void* self);

//100%
INCLUDE_ASM("bx/cubicspline", func_00320078__FPv);
#ifdef SKIP_ASM
void* func_00320078(void* self)
{
    return func_0031F4E8(self);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320098);
#ifdef SKIP_ASM
extern "C" int func_00320098(void* self, unsigned int addr)
{
    unsigned int base = *(unsigned int*)((char*)self + 0x4);
    unsigned int end = base + *(unsigned int*)((char*)self + 0xC);
    int r = base < addr && addr < end;
    return r;
}
#endif

extern "C" int func_0031ED60(void* self);

//100%
INCLUDE_ASM("bx/cubicspline", func_003200C0__FPv);
#ifdef SKIP_ASM
int func_003200C0(void* self)
{
    return func_0031ED60(self);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003200E0);
#ifdef SKIP_ASM
extern "C" void func_003200E0(void) {

}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003200E8__FPv);
#ifdef SKIP_ASM
void* func_003200E8(void* self)
{
    *(void**)((char*)self + 0x800) = self;
    char* p = (char*)self;
    char* next = (char*)self + 8;
    for (unsigned int i = 0; i < 0xFF; i++) {
        *(void**)p = next;
        p += 8;
        next += 8;
    }
    *(int*)((char*)self + 0x7F8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320120__FPv);
#ifdef SKIP_ASM
void* func_00320120(void* self)
{
    *(void**)((char*)self + 0x2000) = self;
    char* p = (char*)self;
    char* next = (char*)self + 0x10;
    for (unsigned int i = 0; i < 0x1FF; i++) {
        *(void**)p = next;
        p += 0x10;
        next += 0x10;
    }
    *(int*)((char*)self + 0x1FF0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320158__FPv);
#ifdef SKIP_ASM
void* func_00320158(void* self)
{
    *(void**)((char*)self + 0x6000) = self;
    char* p = (char*)self;
    char* next = (char*)self + 0x20;
    for (unsigned int i = 0; i < 0x2FF; i++) {
        *(void**)p = next;
        p += 0x20;
        next += 0x20;
    }
    *(int*)((char*)self + 0x5FE0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320190__FPv);
#ifdef SKIP_ASM
void* func_00320190(void* self)
{
    unsigned int i = 0;
    *(void**)((char*)self + 0x32000) = self;
    char* p = (char*)self;
    char* next = (char*)self + 0x40;
    for (; i < 0xC7F; i++) {
        *(void**)p = next;
        p += 0x40;
        next += 0x40;
    }
    *(int*)((char*)self + 0x31FC0) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003201D8__FPv);
#ifdef SKIP_ASM
void* func_003201D8(void* self)
{
    unsigned int i = 0;
    *(void**)((char*)self + 0x25800) = self;
    char* p = (char*)self;
    char* next = (char*)self + 0x80;
    for (; i < 0x4AF; i++) {
        *(void**)p = next;
        p += 0x80;
        next += 0x80;
    }
    *(int*)((char*)self + 0x25780) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320220__FPv);
#ifdef SKIP_ASM
void* func_00320220(void* self)
{
    unsigned int i = 0;
    *(void**)((char*)self + 0x20000) = self;
    char* p = (char*)self;
    char* next = (char*)self + 0x100;
    for (; i < 0x1FF; i++) {
        *(void**)p = next;
        p += 0x100;
        next += 0x100;
    }
    *(int*)((char*)self + 0x1FF00) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320270__FPv);
#ifdef SKIP_ASM
void* func_00320270(void* self)
{
    unsigned int i = 0;
    *(void**)((char*)self + 0x20000) = self;
    char* p = (char*)self;
    char* next = (char*)self + 0x200;
    for (; i < 0xFF; i++) {
        *(void**)p = next;
        p += 0x200;
        next += 0x200;
    }
    *(int*)((char*)self + 0x1FE00) = 0;
    return self;
}
#endif

extern "C" void* func_00319E48(int size);

//100%
INCLUDE_ASM("bx/cubicspline", func_003202C0__FPv);
#ifdef SKIP_ASM
void* func_003202C0(void* self)
{
    void* node = *(void**)((char*)self + 0x800);
    if (node != 0) {
        void* next = *(void**)node;
        *(void**)((char*)self + 0x800) = next;
        return node;
    }
    return func_00319E48(0xC);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003202F8__FPv);
#ifdef SKIP_ASM
void* func_003202F8(void* self)
{
    void* node = *(void**)((char*)self + 0x2000);
    if (node != 0) {
        void* next = *(void**)node;
        *(void**)((char*)self + 0x2000) = next;
        return node;
    }
    return func_00319E48(0x14);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320330__FPv);
#ifdef SKIP_ASM
void* func_00320330(void* self)
{
    void* node = *(void**)((char*)self + 0x6000);
    if (node != 0) {
        void* next = *(void**)node;
        *(void**)((char*)self + 0x6000) = next;
        return node;
    }
    return func_00319E48(0x24);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320368__FPv);
#ifdef SKIP_ASM
static inline void* popFreeNode(void** head)
{
    void* node = *head;
    *head = *(void**)node;
    return node;
}

void* func_00320368(void* self)
{
    if (*(void**)((char*)self + 0x32000) != 0) {
        return popFreeNode((void**)((char*)self + 0x32000));
    }
    return func_00319E48(0x44);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003203B8__FPv);
#ifdef SKIP_ASM
void* func_003203B8(void* self)
{
    if (*(void**)((char*)self + 0x25800) != 0) {
        return popFreeNode((void**)((char*)self + 0x25800));
    }
    return func_00319E48(0x84);
}
#endif

//92.5%
INCLUDE_ASM("bx/cubicspline", func_00320408__FPv);
#ifdef SKIP_ASM
void* func_00320408(void* self)
{
    void* node = *(void**)((char*)self + 0x20000);
    if (node != 0) {
        void* next = *(void**)node;
        *(void**)((char*)self + 0x20000) = next;
        return node;
    }
    return func_00319E48(0x104);
}
#endif

//92.5%
INCLUDE_ASM("bx/cubicspline", func_00320448__FPv);
#ifdef SKIP_ASM
void* func_00320448(void* self)
{
    void* node = *(void**)((char*)self + 0x20000);
    if (node != 0) {
        void* next = *(void**)node;
        *(void**)((char*)self + 0x20000) = next;
        return node;
    }
    return func_00319E48(0x204);
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320488__FPvPPv);
#ifdef SKIP_ASM
void func_00320488(void* self, void** node)
{
    *node = *(void**)((char*)self + 0x800);
    *(void**)((char*)self + 0x800) = node;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320498__FPvPPv);
#ifdef SKIP_ASM
void func_00320498(void* self, void** node)
{
    *node = *(void**)((char*)self + 0x2000);
    *(void**)((char*)self + 0x2000) = node;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003204A8__FPvPPv);
#ifdef SKIP_ASM
void func_003204A8(void* self, void** node)
{
    *node = *(void**)((char*)self + 0x6000);
    *(void**)((char*)self + 0x6000) = node;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003204B8__FPvPPv);
#ifdef SKIP_ASM
void func_003204B8(void* self, void** node)
{
    *node = *(void**)((char*)self + 0x32000);
    *(void**)((char*)self + 0x32000) = node;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003204D0__FPvPPv);
#ifdef SKIP_ASM
void func_003204D0(void* self, void** node)
{
    *node = *(void**)((char*)self + 0x25800);
    *(void**)((char*)self + 0x25800) = node;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_003204E8__FPvPPv);
#ifdef SKIP_ASM
void func_003204E8(void* self, void** node)
{
    *node = *(void**)((char*)self + 0x20000);
    *(void**)((char*)self + 0x20000) = node;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320500__FPvPPv);
#ifdef SKIP_ASM
void func_00320500(void* self, void** node)
{
    *node = *(void**)((char*)self + 0x20000);
    *(void**)((char*)self + 0x20000) = node;
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320518__Fv);
#ifdef SKIP_ASM
void func_00320518(void)
{
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320520__Fv);
#ifdef SKIP_ASM
void func_00320520(void)
{
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320528__Fv);
#ifdef SKIP_ASM
void func_00320528(void)
{
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320530__Fv);
#ifdef SKIP_ASM
void func_00320530(void)
{
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320538__Fv);
#ifdef SKIP_ASM
void func_00320538(void)
{
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320540__Fv);
#ifdef SKIP_ASM
void func_00320540(void)
{
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320548__Fv);
#ifdef SKIP_ASM
void func_00320548(void)
{
}
#endif

//100%
INCLUDE_ASM("bx/cubicspline", func_00320550);
#ifdef SKIP_ASM
void* func_00316A00(void* self);
void func_00317930(void* self);
void* func_0031FF20(void* self);
void func_0031FF38(void* self, int flags);

inline void* operator new(unsigned int, void* p) { return p; }

struct sV2_0550 {
    float x, y;
    sV2_0550(const float& ax, const float& ay) : x(ax), y(ay) {}
};
struct sV3_0550 {
    float x, y, z;
    sV3_0550(const float& ax, const float& ay, const float& az) : x(ax), y(ay), z(az) {}
};
struct sV4_0550 {
    float x, y, z, w;
    sV4_0550(const float& ax, const float& ay, const float& az, const float& aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));
struct sQ_0550 {
    float x, y, z, w;
    sQ_0550(const float& ax, const float& ay, const float& az, const float& aw)
    {
        w = aw;
        x = ax;
        y = ay;
        z = az;
    }
} __attribute__((aligned(16)));
struct sM33_0550 {
    float m[3][3];
    sM33_0550()
    {
        m[0][0] = 1.0f; m[1][0] = 0.0f; m[2][0] = 0.0f;
        m[0][1] = 0.0f; m[1][1] = 1.0f; m[2][1] = 0.0f;
        m[0][2] = 0.0f; m[1][2] = 0.0f; m[2][2] = 1.0f;
    }
};
struct sM44_0550 {
    float m[4][4];
    sM44_0550(float d)
    {
        m[0][0] = d;    m[1][0] = 0.0f; m[2][0] = 0.0f; m[3][0] = 0.0f;
        m[0][1] = 0.0f; m[1][1] = d;    m[2][1] = 0.0f; m[3][1] = 0.0f;
        m[0][2] = 0.0f; m[1][2] = 0.0f; m[2][2] = d;    m[3][2] = 0.0f;
        m[0][3] = 0.0f; m[1][3] = 0.0f; m[2][3] = 0.0f; m[3][3] = d;
    }
};
struct sXf_0550 {
    sV4_0550 a;
    sQ_0550 b;
    sXf_0550(const sV4_0550& aa, const sQ_0550& ab) : a(aa), b(ab) {}
};

extern char D_004FF000[];
extern char D_004FF018[];
extern char D_004FF030[];
extern char D_004FF048[], D_004FF058[], D_004FF068[], D_004FF078[], D_004FF088[], D_004FF098[], D_004FF0A8[], D_004FF0B8[], D_004FF0C8[];
extern char D_004A5958;
extern void* D_004A3E94;
extern char D_004A5960[], D_004A5968[], D_004A5970[];
extern char D_004FF0D8[], D_004FF0E8[], D_004FF0F8[], D_004FF108[];
extern char D_004FF120[], D_004FF130[], D_004FF140[], D_004FF150[], D_004FF160[];
extern char D_004FF170[], D_004FF1A0[], D_004FF1E0[], D_004FF220[], D_004FF230[], D_004FF250[];

extern "C" void func_00320550(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init != 0) {
            func_00316A00(D_004FF000);
            func_00317930(D_004FF018);
            func_00317930(D_004FF030);
            new (D_004FF048) sV3_0550(1.0f, 0.0f, 0.0f);
            new (D_004FF058) sV3_0550(0.0f, 0.0f, 1.0f);
            new (D_004FF068) sV3_0550(1.0f, 1.0f, 0.0f);
            new (D_004FF078) sV3_0550(1.0f, 0.0f, 1.0f);
            new (D_004FF088) sV3_0550(0.0f, 1.0f, 0.0f);
            new (D_004FF098) sV3_0550(1.0f, 0.5f, 0.0f);
            new (D_004FF0A8) sV3_0550(0.0f, 0.0f, 0.0f);
            new (D_004FF0B8) sV3_0550(1.0f, 1.0f, 1.0f);
            new (D_004FF0C8) sV3_0550(0.25f, 0.25f, 0.25f);
            D_004A3E94 = &D_004A5958;
            new (D_004A5960) sV2_0550(0.0f, 0.0f);
            new (D_004A5968) sV2_0550(1.0f, 0.0f);
            new (D_004A5970) sV2_0550(0.0f, 1.0f);
            new (D_004FF0D8) sV3_0550(0.0f, 0.0f, 0.0f);
            new (D_004FF0E8) sV3_0550(1.0f, 0.0f, 0.0f);
            new (D_004FF0F8) sV3_0550(0.0f, 1.0f, 0.0f);
            new (D_004FF108) sV3_0550(0.0f, 0.0f, 1.0f);
            new (D_004FF120) sV4_0550(0.0f, 0.0f, 0.0f, 0.0f);
            new (D_004FF130) sV4_0550(0.0f, 0.0f, 0.0f, 1.0f);
            new (D_004FF140) sV4_0550(1.0f, 0.0f, 0.0f, 0.0f);
            new (D_004FF150) sV4_0550(0.0f, 1.0f, 0.0f, 0.0f);
            new (D_004FF160) sV4_0550(0.0f, 0.0f, 1.0f, 0.0f);
            new (D_004FF170) sM33_0550();
            new (D_004FF1A0) sM44_0550(1.0f);
            new (D_004FF1E0) sM44_0550(0.0f);
            new (D_004FF220) sQ_0550(0.0f, 0.0f, 0.0f, 1.0f);
            new (D_004FF230) sXf_0550(*(sV4_0550*)D_004FF130, *(sQ_0550*)D_004FF220);
            func_0031FF20(D_004FF250);
        } else {
            func_0031FF38(D_004FF250, 2);
        }
    }
}
#endif
