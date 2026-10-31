#include "common.h"

//100%
INCLUDE_ASM("bx/memblockman", cMemMan_initialize);
#ifdef SKIP_ASM
extern void* D_00538B00[16];
extern char D_004FF250[];
extern unsigned int D_004A3EBC;
extern unsigned int D_004A3EC0;
extern int D_004A3EB8;
extern "C" int func_003E5698(void* mutex);
extern "C" void func_0031FF60(void* heap, unsigned int base, unsigned int size);
extern "C" void cMemBlockMan_initialize(void);

extern "C" void cMemMan_initialize(unsigned int base, unsigned int size)
{
    func_003E5698(D_00538B00);
    D_004A3EBC = base;
    D_004A3EC0 = size;
    func_0031FF60(D_004FF250, base, size);
    D_004A3EB8 = 1;
    cMemBlockMan_initialize();
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319A90);
#ifdef SKIP_ASM
extern "C" void* func_00319E48(unsigned int size, unsigned int align);
extern "C" void func_003E6220(void* p, unsigned int n);
extern char D_004FF250[];
// PORT: func_00320058__FPv / func_00320078__FPv take (heap, align, size); the defining unit declares 1 arg.
void* func_00320058_K2(void* heap, unsigned int align, unsigned int size) __asm__("func_00320058__FPv");
void* func_00320078_K2(void* heap, unsigned int align, unsigned int size) __asm__("func_00320078__FPv");

extern "C" void* func_00319A90(unsigned int size, unsigned int align, int flags, int top)
{
    void* p;
    if (top == 0 && size != 0 && size <= 0x200) {
        p = func_00319E48(size, align);
    } else {
        if (align <= 15)
            align = 16;
        if (top != 0)
            p = func_00320078_K2(D_004FF250, align, size);
        else
            p = func_00320058_K2(D_004FF250, align, size);
    }
    if (p != 0 && flags < 0)
        func_003E6220(p, size);
    return p;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319B48);
#ifdef SKIP_ASM
extern "C" int func_0031A088(void* p);
extern "C" void func_00319F68(void* p);
extern char D_004FF250[];
// PORT: func_003200C0__FPv is called with (list, item) here; bind the 2-arg form to that symbol.
int func_003200C0_2(void* list, void* item) __asm__("func_003200C0__FPv");

extern "C" void func_00319B48(void* p)
{
    if (p != 0)
    {
        if (func_0031A088(p) != 0)
        {
            func_00319F68(p);
        }
        else
        {
            func_003200C0_2(D_004FF250, p);
        }
    }
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319B98);
#ifdef SKIP_ASM
extern "C" int func_0031A130(void* self);
unsigned int func_0031FBB8(void* list, void* item);
extern char D_004FF250[];

extern "C" void func_00319B98(void* self)
{
    if (func_0031A130(self) == 0) {
        func_0031FBB8(D_004FF250, self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/memblockman", cMemMan_internalResizeBlock);
#ifdef SKIP_ASM
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern "C" void* func_0041605C(void* dst, const void* src, int n);
extern void* D_00538B00[16];
extern char D_0048DA08[];
// PORT: operator_new__FUi takes (size, tag, flags, align) here.
void* operator_new_K2(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
// PORT: func_00319B98 returns the block size; the unit declares it void.
extern "C" unsigned int func_00319B98_K2(void* p) __asm__("func_00319B98");

static inline unsigned int cMemMan_blockSizeK2(void* p)
{
    MUTEX_lock(D_00538B00);
    unsigned int n = func_00319B98_K2(p);
    MUTEX_unlock(D_00538B00);
    return n;
}

static inline void cMemMan_freeBlockK2(void* p)
{
    MUTEX_lock(D_00538B00);
    func_00319B48(p);
    MUTEX_unlock(D_00538B00);
}

extern "C" void* cMemMan_internalResizeBlock(void* old, unsigned int size)
{
    void* p = operator_new_K2(size, D_0048DA08, 0x100, 0);
    func_0041605C(p, old, size < cMemMan_blockSizeK2(old) ? size : cMemMan_blockSizeK2(old));
    cMemMan_freeBlockK2(old);
    return p;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319CC8);
#ifdef SKIP_ASM
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern "C" void func_0031A200(void);
extern void* D_00538B00[16];

extern "C" void func_00319CC8(void)
{
    MUTEX_lock(D_00538B00);
    func_0031A200();
    MUTEX_unlock(D_00538B00);
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319D08);
#ifdef SKIP_ASM
extern "C" void func_00319D08(void) {

}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319D10__FPv);
#ifdef SKIP_ASM
void func_00319D10(void* self)
{
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319D18__FPv);
#ifdef SKIP_ASM
int func_00319D18(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", cMemBlockMan_initialize);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* func_003200E8(void* p);
void* func_00320120(void* p);
void* func_00320158(void* p);
void* func_00320190(void* p);
void* func_003201D8(void* p);
void* func_00320220(void* p);
void* func_00320270(void* p);
extern const char D_0048DA18[];
extern const char D_0048DA28[];
extern const char D_0048DA38[];
extern const char D_0048DA48[];
extern const char D_0048DA58[];
extern const char D_0048DA68[];
extern const char D_0048DA78[];
extern void* D_004A5B60;
extern void* D_004A5B50;
extern void* D_004A5B5C;
extern void* D_004A5B6C;
extern void* D_004A5B74;
extern void* D_004A5B68;
extern void* D_004A5B58;
extern int D_004A3EC8;

extern "C" void cMemBlockMan_initialize(void)
{
    D_004A5B60 = func_003200E8(cMemMan_alloc(0x804, D_0048DA18, 0x1000000, 0));
    D_004A5B50 = func_00320120(cMemMan_alloc(0x2004, D_0048DA28, 0x2000000, 0));
    D_004A5B5C = func_00320158(cMemMan_alloc(0x6004, D_0048DA38, 0x3000000, 0));
    D_004A5B6C = func_00320190(cMemMan_alloc(0x32004, D_0048DA48, 0x4000000, 0));
    D_004A5B74 = func_003201D8(cMemMan_alloc(0x25804, D_0048DA58, 0x5000000, 0));
    D_004A5B68 = func_00320220(cMemMan_alloc(0x20004, D_0048DA68, 0x6000000, 0));
    D_004A5B58 = func_00320270(cMemMan_alloc(0x20004, D_0048DA78, 0x7000000, 0));
    D_004A3EC8 = 1;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319E48);
#ifdef SKIP_ASM
extern "C" void* func_00319A90(unsigned int size, unsigned int align, int flags, int top);
// PORT: the pool allocators are bound with their real (pool, align) arity; the
// symbols are named __FPv upstream.
void* func_003202C0_impl(void* pool, unsigned int align) __asm__("func_003202C0__FPv");
void* func_003202F8_impl(void* pool, unsigned int align) __asm__("func_003202F8__FPv");
void* func_00320330_impl(void* pool, unsigned int align) __asm__("func_00320330__FPv");
void* func_00320368_impl(void* pool, unsigned int align) __asm__("func_00320368__FPv");
void* func_003203B8_impl(void* pool, unsigned int align) __asm__("func_003203B8__FPv");
void* func_00320408_impl(void* pool, unsigned int align) __asm__("func_00320408__FPv");
void* func_00320448_impl(void* pool, unsigned int align) __asm__("func_00320448__FPv");
extern void* D_004A5B60;
extern void* D_004A5B50;
extern void* D_004A5B5C;
extern void* D_004A5B6C;
extern void* D_004A5B74;
extern void* D_004A5B68;
extern void* D_004A5B58;
extern int D_004A3EC8;

// PORT: binds the real 2-arg body; the unit declares a 1-arg prototype used by callers
extern "C" void* func_00319E48(unsigned int size, unsigned int align);
extern "C" void* func_00319E48(unsigned int size, unsigned int align)
{
    size = size > align ? size : align;
    if (D_004A3EC8) {
        size = size + (-(size & 3) & 3);
        if (size <= 8)
            return func_003202C0_impl(D_004A5B60, align);
        if (size <= 0x10)
            return func_003202F8_impl(D_004A5B50, align);
        if (size <= 0x20)
            return func_00320330_impl(D_004A5B5C, align);
        if (size <= 0x40)
            return func_00320368_impl(D_004A5B6C, align);
        if (size <= 0x80)
            return func_003203B8_impl(D_004A5B74, align);
        if (size <= 0x100)
            return func_00320408_impl(D_004A5B68, align);
        if (size <= 0x200)
            return func_00320448_impl(D_004A5B58, align);
    } else
        size = 0x201;
    return func_00319A90(size, align > 7 ? align : 8, 0, 0);
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_00319F68);
#ifdef SKIP_ASM
void func_00320488(void* pool, void** p);
void func_00320498(void* pool, void** p);
void func_003204A8(void* pool, void** p);
void func_003204B8(void* pool, void** p);
void func_003204D0(void* pool, void** p);
void func_003204E8(void* pool, void** p);
void func_00320500(void* pool, void** p);
extern void* D_004A5B60;
extern void* D_004A5B50;
extern void* D_004A5B5C;
extern void* D_004A5B6C;
extern void* D_004A5B74;
extern void* D_004A5B68;
extern void* D_004A5B58;

template <unsigned int N>
inline bool inPool_319F68(void* pool, void* p)
{
    return (unsigned int)((char*)p - (char*)pool) < N;
}

extern "C" void func_00319F68(void* p)
{
    if (inPool_319F68<0x800>(D_004A5B60, p))
        func_00320488(D_004A5B60, (void**)p);
    else if (inPool_319F68<0x2000>(D_004A5B50, p))
        func_00320498(D_004A5B50, (void**)p);
    else if (inPool_319F68<0x6000>(D_004A5B5C, p))
        func_003204A8(D_004A5B5C, (void**)p);
    else if (inPool_319F68<0x32000>(D_004A5B6C, p))
        func_003204B8(D_004A5B6C, (void**)p);
    else if (inPool_319F68<0x25800>(D_004A5B74, p))
        func_003204D0(D_004A5B74, (void**)p);
    else if (inPool_319F68<0x20000>(D_004A5B68, p))
        func_003204E8(D_004A5B68, (void**)p);
    else if (inPool_319F68<0x20000>(D_004A5B58, p))
        func_00320500(D_004A5B58, (void**)p);
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A088);
#ifdef SKIP_ASM
extern void* D_004A5B50;
extern void* D_004A5B58;
extern void* D_004A5B5C;
extern void* D_004A5B60;
extern void* D_004A5B68;
extern void* D_004A5B6C;
extern void* D_004A5B74;

static inline int func_0031A088_in(void* p, void* base, unsigned int size)
{
    return (unsigned int)((char*)p - (char*)base) <= size - 1;
}

extern "C" int func_0031A088(void* p)
{
    if (func_0031A088_in(p, D_004A5B60, 0x800))
        return 1;
    if (func_0031A088_in(p, D_004A5B50, 0x2000))
        return 1;
    if (func_0031A088_in(p, D_004A5B5C, 0x6000))
        return 1;
    if (func_0031A088_in(p, D_004A5B6C, 0x32000))
        return 1;
    if (func_0031A088_in(p, D_004A5B74, 0x25800))
        return 1;
    if (func_0031A088_in(p, D_004A5B68, 0x20000))
        return 1;
    return func_0031A088_in(p, D_004A5B58, 0x20000);
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A130);
#ifdef SKIP_ASM
extern void* D_004A5B50;
extern void* D_004A5B58;
extern void* D_004A5B5C;
extern void* D_004A5B60;
extern void* D_004A5B68;
extern void* D_004A5B6C;
extern void* D_004A5B74;

static inline int func_0031A130_in(void* p, void* base, unsigned int size)
{
    return (unsigned int)((char*)p - (char*)base) <= size - 1;
}

extern "C" int func_0031A130(void* p)
{
    if (func_0031A130_in(p, D_004A5B60, 0x800))
        return 0x8;
    if (func_0031A130_in(p, D_004A5B50, 0x2000))
        return 0x10;
    if (func_0031A130_in(p, D_004A5B5C, 0x6000))
        return 0x20;
    if (func_0031A130_in(p, D_004A5B6C, 0x32000))
        return 0x40;
    if (func_0031A130_in(p, D_004A5B74, 0x25800))
        return 0x80;
    if (func_0031A130_in(p, D_004A5B68, 0x20000))
        return 0x100;
    if (func_0031A130_in(p, D_004A5B58, 0x20000))
        return 0x200;
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A200);
#ifdef SKIP_ASM
extern int D_004A3EC8;
extern void* D_004A5B50;
extern void* D_004A5B58;
extern void* D_004A5B5C;
extern void* D_004A5B60;
extern void* D_004A5B68;
extern void* D_004A5B6C;
extern void* D_004A5B74;
// PORT: these empty stubs are defined as f(void), but this caller passes one argument.
void func_00320518_1(void*) __asm__("func_00320518__Fv");
void func_00320520_1(void*) __asm__("func_00320520__Fv");
void func_00320528_1(void*) __asm__("func_00320528__Fv");
void func_00320530_1(void*) __asm__("func_00320530__Fv");
void func_00320538_1(void*) __asm__("func_00320538__Fv");
void func_00320540_1(void*) __asm__("func_00320540__Fv");
void func_00320548_1(void*) __asm__("func_00320548__Fv");

extern "C" void func_0031A200(void)
{
    if (D_004A3EC8 != 0) {
        func_00320518_1(D_004A5B60);
        func_00320520_1(D_004A5B50);
        func_00320528_1(D_004A5B5C);
        func_00320530_1(D_004A5B6C);
        func_00320538_1(D_004A5B74);
        func_00320540_1(D_004A5B68);
        func_00320548_1(D_004A5B58);
    }
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A258);
#ifdef SKIP_ASM
extern "C" int func_0031A258(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("bx/memblockman", func_0031A260);
#ifdef SKIP_ASM
extern "C" void func_0031A260(void) {

}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A268);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 FPU-flag probe: builds two float4s from flag bits and multiplies them on VU0.
extern "C" void func_0031A268(int flags)
{
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    int i;
    for (i = 0; i < 4; i++) {
        float f;
        if ((flags & 0x8800) == 0) {
            f = 0.0f;
            if (!(flags & 8))
                f = 1.0f;
        } else {
            f = 1.0000000031710769e-30f;
            if (!(flags & 8))
                f = 1.0000000150474662e+30f;
        }
        a[i] = f;
        if (flags & 0x80)
            f = -f;
        b[i] = f;
        flags <<= 1;
    }
    __asm__ __volatile__(
        "qmfc2.ni   $8, $vf1\n"
        "qmfc2.ni   $9, $vf2\n"
        "lqc2       $vf1, %0\n"
        "lqc2       $vf2, %1\n"
        "vmul.xyzw  $vf1, $vf1, $vf2\n"
        "qmtc2.ni   $8, $vf1\n"
        "qmtc2.ni   $9, $vf2\n"
        "vnop\n"
        :
        : "m"(a[0]), "m"(b[0])
        : "$8", "$9");
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A308);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 state save (VF1-VF31, MAC/status/Q/clip flags, ACC) to a 0x210-byte buffer.
extern "C" void func_0031A308(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "cfc2.i     $9, $vi17\n"
        "sqc2       $vf1, 0x0($8)\n"
        "sqc2       $vf2, 0x10($8)\n"
        "sw         $9, 0x200($8)\n"
        "sqc2       $vf3, 0x20($8)\n"
        "sqc2       $vf4, 0x30($8)\n"
        "cfc2.ni    $9, $vi16\n"
        "sqc2       $vf5, 0x40($8)\n"
        "sqc2       $vf6, 0x50($8)\n"
        "sw         $9, 0x204($8)\n"
        "vwaitq\n"
        "cfc2.ni    $9, $vi22\n"
        "sw         $9, 0x208($8)\n"
        "cfc2.ni    $9, $vi18\n"
        "sw         $9, 0x20C($8)\n"
        "sqc2       $vf7, 0x60($8)\n"
        "sqc2       $vf8, 0x70($8)\n"
        "vmaddx.xyzw $vf1, $vf0, $vf0x\n"
        "sqc2       $vf9, 0x80($8)\n"
        "sqc2       $vf10, 0x90($8)\n"
        "sqc2       $vf11, 0xA0($8)\n"
        "sqc2       $vf12, 0xB0($8)\n"
        "sqc2       $vf13, 0xC0($8)\n"
        "sqc2       $vf14, 0xD0($8)\n"
        "sqc2       $vf15, 0xE0($8)\n"
        "sqc2       $vf16, 0xF0($8)\n"
        "sqc2       $vf17, 0x100($8)\n"
        "sqc2       $vf18, 0x110($8)\n"
        "sqc2       $vf19, 0x120($8)\n"
        "sqc2       $vf20, 0x130($8)\n"
        "sqc2       $vf21, 0x140($8)\n"
        "sqc2       $vf22, 0x150($8)\n"
        "sqc2       $vf23, 0x160($8)\n"
        "sqc2       $vf24, 0x170($8)\n"
        "sqc2       $vf25, 0x180($8)\n"
        "sqc2       $vf26, 0x190($8)\n"
        "sqc2       $vf27, 0x1A0($8)\n"
        "sqc2       $vf28, 0x1B0($8)\n"
        "sqc2       $vf29, 0x1C0($8)\n"
        "sqc2       $vf30, 0x1D0($8)\n"
        "sqc2       $vf31, 0x1E0($8)\n"
        "sqc2       $vf1, 0x1F0($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/memblockman", func_0031A3C0);
#ifdef SKIP_ASM
extern "C" void func_0031A268(int status);

// PORT: PS2-only VU0 state restore (inverse of func_0031A308): VF1-VF31, flags, ACC.
extern "C" void func_0031A3C0(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "lw         $9, 0x208($8)\n"
        "ctc2.ni    $9, $vi22\n"
        "lw         $9, 0x20C($8)\n"
        "ctc2.ni    $9, $vi18\n"
        "lqc2       $vf1, 0x1F0($8)\n"
        "vaddax.xyzw ACC, $vf1, $vf0x\n"
        "lqc2       $vf1, 0x0($8)\n"
        "lqc2       $vf2, 0x10($8)\n"
        "lqc2       $vf3, 0x20($8)\n"
        "lqc2       $vf4, 0x30($8)\n"
        "lqc2       $vf5, 0x40($8)\n"
        "lqc2       $vf6, 0x50($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
    func_0031A268(*(int*)((char*)buf + 0x200));
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "lqc2       $vf7, 0x60($8)\n"
        "lqc2       $vf8, 0x70($8)\n"
        "lqc2       $vf9, 0x80($8)\n"
        "lqc2       $vf10, 0x90($8)\n"
        "lqc2       $vf11, 0xA0($8)\n"
        "lqc2       $vf12, 0xB0($8)\n"
        "lw         $9, 0x204($8)\n"
        "lqc2       $vf13, 0xC0($8)\n"
        "lqc2       $vf14, 0xD0($8)\n"
        "ctc2.ni    $9, $vi16\n"
        "lqc2       $vf15, 0xE0($8)\n"
        "lqc2       $vf16, 0xF0($8)\n"
        "lqc2       $vf17, 0x100($8)\n"
        "lqc2       $vf18, 0x110($8)\n"
        "lqc2       $vf19, 0x120($8)\n"
        "lqc2       $vf20, 0x130($8)\n"
        "lqc2       $vf21, 0x140($8)\n"
        "lqc2       $vf22, 0x150($8)\n"
        "lqc2       $vf23, 0x160($8)\n"
        "lqc2       $vf24, 0x170($8)\n"
        "lqc2       $vf25, 0x180($8)\n"
        "lqc2       $vf26, 0x190($8)\n"
        "lqc2       $vf27, 0x1A0($8)\n"
        "lqc2       $vf28, 0x1B0($8)\n"
        "lqc2       $vf29, 0x1C0($8)\n"
        "lqc2       $vf30, 0x1D0($8)\n"
        "lqc2       $vf31, 0x1E0($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A490);
#ifdef SKIP_ASM
// PORT: PS2-only handler trampoline: saves/restores all 32 FPU registers around the
// handler call and re-enables interrupts (sync; ei). Needs a native replacement off-PS2.
extern "C" int func_0031A490(int arg, void (*handler)(int))
{
    int save[32];
    __asm__ __volatile__(
        "mfc1 $2, $f0\n\tsw $2, %0\n\t"
        "mfc1 $2, $f1\n\tsw $2, %1\n\t"
        "mfc1 $2, $f2\n\tsw $2, %2\n\t"
        "mfc1 $2, $f3\n\tsw $2, %3\n\t"
        "mfc1 $2, $f4\n\tsw $2, %4\n\t"
        "mfc1 $2, $f5\n\tsw $2, %5\n\t"
        "mfc1 $2, $f6\n\tsw $2, %6\n\t"
        "mfc1 $2, $f7\n\tsw $2, %7\n\t"
        : "=m"(save[0]), "=m"(save[1]), "=m"(save[2]), "=m"(save[3]), "=m"(save[4]), "=m"(save[5]), "=m"(save[6]), "=m"(save[7])
        :
        : "$2");
    __asm__ __volatile__(
        "mfc1 $2, $f8\n\tsw $2, %0\n\t"
        "mfc1 $2, $f9\n\tsw $2, %1\n\t"
        "mfc1 $2, $f10\n\tsw $2, %2\n\t"
        "mfc1 $2, $f11\n\tsw $2, %3\n\t"
        "mfc1 $2, $f12\n\tsw $2, %4\n\t"
        "mfc1 $2, $f13\n\tsw $2, %5\n\t"
        "mfc1 $2, $f14\n\tsw $2, %6\n\t"
        "mfc1 $2, $f15\n\tsw $2, %7\n\t"
        : "=m"(save[8]), "=m"(save[9]), "=m"(save[10]), "=m"(save[11]), "=m"(save[12]), "=m"(save[13]), "=m"(save[14]), "=m"(save[15])
        :
        : "$2");
    __asm__ __volatile__(
        "mfc1 $2, $f16\n\tsw $2, %0\n\t"
        "mfc1 $2, $f17\n\tsw $2, %1\n\t"
        "mfc1 $2, $f18\n\tsw $2, %2\n\t"
        "mfc1 $2, $f19\n\tsw $2, %3\n\t"
        "mfc1 $2, $f20\n\tsw $2, %4\n\t"
        "mfc1 $2, $f21\n\tsw $2, %5\n\t"
        "mfc1 $2, $f22\n\tsw $2, %6\n\t"
        "mfc1 $2, $f23\n\tsw $2, %7\n\t"
        : "=m"(save[16]), "=m"(save[17]), "=m"(save[18]), "=m"(save[19]), "=m"(save[20]), "=m"(save[21]), "=m"(save[22]), "=m"(save[23])
        :
        : "$2");
    __asm__ __volatile__(
        "mfc1 $2, $f24\n\tsw $2, %0\n\t"
        "mfc1 $2, $f25\n\tsw $2, %1\n\t"
        "mfc1 $2, $f26\n\tsw $2, %2\n\t"
        "mfc1 $2, $f27\n\tsw $2, %3\n\t"
        "mfc1 $2, $f28\n\tsw $2, %4\n\t"
        "mfc1 $2, $f29\n\tsw $2, %5\n\t"
        "mfc1 $2, $f30\n\tsw $2, %6\n\t"
        "mfc1 $2, $f31\n\tsw $2, %7\n\t"
        : "=m"(save[24]), "=m"(save[25]), "=m"(save[26]), "=m"(save[27]), "=m"(save[28]), "=m"(save[29]), "=m"(save[30]), "=m"(save[31])
        :
        : "$2");
    handler(arg);
    __asm__ __volatile__(
        "lw $2, %0\n\tmtc1 $2, $f0\n\t"
        "lw $2, %1\n\tmtc1 $2, $f1\n\t"
        "lw $2, %2\n\tmtc1 $2, $f2\n\t"
        "lw $2, %3\n\tmtc1 $2, $f3\n\t"
        "lw $2, %4\n\tmtc1 $2, $f4\n\t"
        "lw $2, %5\n\tmtc1 $2, $f5\n\t"
        "lw $2, %6\n\tmtc1 $2, $f6\n\t"
        "lw $2, %7\n\tmtc1 $2, $f7\n\t"
        :
        : "m"(save[0]), "m"(save[1]), "m"(save[2]), "m"(save[3]), "m"(save[4]), "m"(save[5]), "m"(save[6]), "m"(save[7])
        : "$2");
    __asm__ __volatile__(
        "lw $2, %0\n\tmtc1 $2, $f8\n\t"
        "lw $2, %1\n\tmtc1 $2, $f9\n\t"
        "lw $2, %2\n\tmtc1 $2, $f10\n\t"
        "lw $2, %3\n\tmtc1 $2, $f11\n\t"
        "lw $2, %4\n\tmtc1 $2, $f12\n\t"
        "lw $2, %5\n\tmtc1 $2, $f13\n\t"
        "lw $2, %6\n\tmtc1 $2, $f14\n\t"
        "lw $2, %7\n\tmtc1 $2, $f15\n\t"
        :
        : "m"(save[8]), "m"(save[9]), "m"(save[10]), "m"(save[11]), "m"(save[12]), "m"(save[13]), "m"(save[14]), "m"(save[15])
        : "$2");
    __asm__ __volatile__(
        "lw $2, %0\n\tmtc1 $2, $f16\n\t"
        "lw $2, %1\n\tmtc1 $2, $f17\n\t"
        "lw $2, %2\n\tmtc1 $2, $f18\n\t"
        "lw $2, %3\n\tmtc1 $2, $f19\n\t"
        "lw $2, %4\n\tmtc1 $2, $f20\n\t"
        "lw $2, %5\n\tmtc1 $2, $f21\n\t"
        "lw $2, %6\n\tmtc1 $2, $f22\n\t"
        "lw $2, %7\n\tmtc1 $2, $f23\n\t"
        :
        : "m"(save[16]), "m"(save[17]), "m"(save[18]), "m"(save[19]), "m"(save[20]), "m"(save[21]), "m"(save[22]), "m"(save[23])
        : "$2");
    __asm__ __volatile__(
        "lw $2, %0\n\tmtc1 $2, $f24\n\t"
        "lw $2, %1\n\tmtc1 $2, $f25\n\t"
        "lw $2, %2\n\tmtc1 $2, $f26\n\t"
        "lw $2, %3\n\tmtc1 $2, $f27\n\t"
        "lw $2, %4\n\tmtc1 $2, $f28\n\t"
        "lw $2, %5\n\tmtc1 $2, $f29\n\t"
        "lw $2, %6\n\tmtc1 $2, $f30\n\t"
        "lw $2, %7\n\tmtc1 $2, $f31\n\t"
        :
        : "m"(save[24]), "m"(save[25]), "m"(save[26]), "m"(save[27]), "m"(save[28]), "m"(save[29]), "m"(save[30]), "m"(save[31])
        : "$2");
    __asm__ __volatile__("sync\n\tei");
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031A6B8);
#ifdef SKIP_ASM
extern int D_004A3ECC;
extern "C" void func_00423C30(int, int);

extern "C" void func_0031A6B8(void)
{
    func_00423C30(D_004A3ECC, 0x65);
}
#endif

INCLUDE_ASM("bx/memblockman", func_0031A6D8);

//100%
INCLUDE_ASM("bx/memblockman", func_0031A920);
#ifdef SKIP_ASM
extern "C" void func_00424880(int);
extern "C" void func_00423AA0(int, int);
extern "C" int func_004248E8(int);
extern "C" void func_00423DC0(int);
extern "C" void func_00423CC0();
extern "C" void func_00423BF0(int);
extern "C" void func_00423BB0(int);
extern "C" void func_00423DB0(int);

extern "C" void func_0031A920(void* self)
{
    func_00424880(3);
    func_00423AA0(3, *(int*)((char*)self + 0x14290));
    func_004248E8(3);
    *(int*)((char*)self + 0x20) = 1;
    func_00423DC0(*(int*)((char*)self + 0x14044));
    func_00423DC0(*(int*)((char*)self + 0x4034));
    func_00423CC0();
    func_00423CC0();
    func_00423BF0(*(int*)((char*)self + 0x4030));
    func_00423BB0(*(int*)((char*)self + 0x4030));
    func_00423BF0(*(int*)((char*)self + 0x14040));
    func_00423BB0(*(int*)((char*)self + 0x14040));
    func_00423DB0(*(int*)((char*)self + 0x4034));
    func_00423DB0(*(int*)((char*)self + 0x14044));
    func_00423DB0(*(int*)((char*)self + 0x18));
    func_00423DB0(*(int*)((char*)self + 0xC));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/memblockman", func_0031A9D8);
#ifdef SKIP_ASM
extern "C" void func_0031A3C0(void* buf);

extern "C" void func_0031A9D8(void* self)
{
    if (*(int*)((char*)self + 0x14048) != 0) {
        func_0031A3C0((char*)self + 0x14080);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/memblockman", func_0031AA18);
#ifdef SKIP_ASM
extern "C" void func_0031AA18(void* self)
{
    if (*(int*)((char*)self + 0x14048) != 0) {
        func_0031A308((char*)self + 0x14080);
    }
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AA58);
#ifdef SKIP_ASM
extern "C" void* func_00423DE0(int);
extern "C" int func_00423DF0(int);

struct sMemBlkVEntryA {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sMemBlkVEntryB {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0031AA58(void* self)
{
    *(int*)((char*)self + 0x1C) = 1;
    sMemBlkVEntryA* vt = *(sMemBlkVEntryA**)((char*)self + 0x8);
    vt[11].fn((char*)self + vt[11].delta);
    func_00423DE0(*(int*)((char*)self + 0x18));
    *(int*)((char*)self + 0x1C) = 0;
    while (func_00423DF0(*(int*)((char*)self + 0x18)) == *(int*)((char*)self + 0x18))
    {
    }
    sMemBlkVEntryB* vt2 = *(sMemBlkVEntryB**)((char*)self + 0x8);
    vt2[12].fn((char*)self + vt2[12].delta);
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AAC8);
#ifdef SKIP_ASM
extern "C" void func_00423DC0(int);

extern "C" void func_0031AAC8(void* self)
{
    if (*(int*)((char*)self + 0x1C) != 0) {
        func_00423DC0(*(int*)((char*)self + 0x18));
    }
}
#endif

extern "C" void* func_00423DE0(int);

//100%
INCLUDE_ASM("bx/memblockman", func_0031AAF0__FPv);
#ifdef SKIP_ASM
void* func_0031AAF0(void* self)
{
    return func_00423DE0(*(int*)((char*)self + 0xc));
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AB10);
#ifdef SKIP_ASM
// Wakes the thread at 0xC, then idles forever.
extern "C" void func_0031AB10(void* self)
{
    func_00423DC0(*(int*)((char*)self + 0xC));
    for (;;) {
        func_00423CC0();
    }
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AB30);
#ifdef SKIP_ASM
extern "C" int func_00423C90();
extern "C" void func_00423D10(int thread);
int cExecutionMan_checkHalt(void* self, int flag);

struct sMbVE_AB30 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sMbOwner_AB30 {
    char pad_0x0[0x28];
    sMbVE_AB30 vt5;     // 0x28
};

// Halt request: on the execution thread checks the halt directly; otherwise forwards it and wakes the worker.
extern "C" void func_0031AB30(void* self)
{
    char* s = (char*)self;
    *(volatile int*)(s + 0x4038) = 1;
    int cur = func_00423C90();
    if (cur != *(int*)(s + 0x14040)) {
        func_00423D10(*(int*)(s + 0x14040));
    }
    if (cur == *(int*)(s + 0x10)) {
        cExecutionMan_checkHalt(self, 0);
        return;
    }
    sMbOwner_AB30* o = *(sMbOwner_AB30**)(s + 0x8);
    o->vt5.fn(s + o->vt5.delta);
    func_0031AAF0(self);
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031ABC0__FPv);
#ifdef SKIP_ASM
void func_0031ABC0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031ABC8__FPv);
#ifdef SKIP_ASM
int func_0031ABC8(void* self)
{
    return 0x3C;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031ABD0);
#ifdef SKIP_ASM
void* func_00317520();
extern "C" void func_00423DD0(int);

extern "C" void func_0031ABD0(void)
{
    char* app = (char*)func_00317520();
    if (*(int*)(app + 0x4038) == 0) {
        func_00423DD0(*(int*)(app + 0x4034));
    }
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AC08);
#ifdef SKIP_ASM
extern "C" void* func_00423DE0(int);
extern "C" void func_00423CD0(int);
extern "C" void func_00423CC0();
// PORT: func_00317500__Fv is called with self here; bind the 1-arg form to that symbol.
int func_00317500_1(void* self) __asm__("func_00317500__Fv");

extern "C" void func_0031AC08(void* self)
{
    while (func_00423DE0(*(int*)((char*)self + 0x4034)), *(int*)((char*)self + 0x20) == 0)
    {
        func_00317500_1(self);
    }
    func_00423CD0(*(int*)((char*)self + 0x10));
    func_00423CC0();
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AC60);
#ifdef SKIP_ASM
struct sMemJobVEntry {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0031AC60(void* self)
{
    while (func_00423DE0(*(int*)((char*)self + 0x14044)), *(int*)((char*)self + 0x20) == 0)
    {
        void* obj = *(void* volatile*)((char*)self + 0x14048);
        sMemJobVEntry* vt = *(sMemJobVEntry**)obj;
        vt[2].fn((char*)obj + vt[2].delta);
        *(void* volatile*)((char*)self + 0x14048) = 0;
    }
    func_00423CD0(*(int*)((char*)self + 0x10));
    func_00423CC0();
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031ACD8);
#ifdef SKIP_ASM
extern "C" void func_00423DC0(int);

extern "C" void func_0031ACD8(void* self, int a1)
{
    *(int*)((char*)self + 0x14048) = a1;
    func_00423DC0(*(int*)((char*)self + 0x14044));
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AD00);
#ifdef SKIP_ASM
extern "C" int func_0031AD00(void* self)
{
    return *(int*)((char*)self + 0x14048) == 0;
}
#endif

extern "C" unsigned int D_004A3ED0;

//100%
INCLUDE_ASM("bx/memblockman", func_0031AD18);
#ifdef SKIP_ASM
extern "C" void func_0031AD18()
{
    D_004A3ED0 = 0;
}
#endif

//100%
INCLUDE_ASM("bx/memblockman", func_0031AD20);
#ifdef SKIP_ASM
extern int D_00519C40[];
extern int D_004A3ED4;
extern "C" int func_00402618(int cmd, int* out);
extern "C" void func_003E3D78(void);

extern "C" int func_0031AD20(void)
{
    int flags = D_00519C40[0];
    if (D_004A3ED4 != 0) {
        int r;
        D_004A3ED4 = 0;
        r = 0;
        func_00402618(2, &r);
    }
    if ((flags & 6) == 6) {
        int r2 = 0;
        func_00402618(2, &r2);
        if (r2 != 0)
            D_004A3ED0 = 1;
        D_00519C40[0] &= ~6;
        func_003E3D78();
    }
    return 0;
}
#endif

