#include "common.h"

INCLUDE_ASM("worldpainter/quadtree", cQuadTree_getFreeNode);

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C18E8);
#ifdef SKIP_ASM
extern "C" void func_002C18E8(char *self, unsigned short a, unsigned short b, unsigned short c, unsigned short d) {
    char *arr = *(char **)(self + 0x20);
    *(unsigned short *)(arr + (a << 3)) = b;
    *(unsigned short *)(arr + (b << 3)) = c;
    *(unsigned short *)(arr + (c << 3)) = d;
    *(unsigned short *)(arr + (d << 3)) = **(unsigned short **)(self + 0x24);
    **(unsigned short **)(self + 0x24) = a;
    *(int *)(self + 0xC) = *(int *)(self + 0xC) - 4;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C1950);
#ifdef SKIP_ASM
extern "C" void func_002C1A00(void* self, void* node, unsigned short x, unsigned short z, int size, int a5, int a6);

extern "C" void func_002C1950(void* self, int a1, int a2, float fx, float fz, float fsize)
{
    int x = (int)((fx - *(float*)((char*)self + 4)) * *(float*)self);
    int z = (int)((fz - *(float*)((char*)self + 8)) * *(float*)self);
    fsize = fsize * *(float*)self;
    if ((unsigned int)x > 0x7FFF || (unsigned int)z > 0x7FFF) {
        return;
    }
    int size = 0x8000 / (int)fsize;
    func_002C1A00(self, *(char**)((char*)self + 0x20) + *(unsigned short*)((char*)self + 0x14) * 8, (unsigned short)(x << 1), (unsigned short)(z << 1), size, a1, a2);
}
#endif

INCLUDE_ASM("worldpainter/quadtree", func_002C1A00);
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C1CD8);
#ifdef SKIP_ASM
extern "C" void* func_002C1CD8(void* self, float fx, float fz)
{
    int x = (int)((fx - *(float*)((char*)self + 4)) * *(float*)self);
    int z = (int)((fz - *(float*)((char*)self + 8)) * *(float*)self);
    if ((unsigned int)x > 0x7FFF || (unsigned int)z > 0x7FFF) {
        return (char*)self + 0x18;
    }
    unsigned short ux = x << 1;
    unsigned short uz = z << 1;
    char* nodes = *(char**)((char*)self + 0x20);
    unsigned short* node = (unsigned short*)(nodes + *(unsigned short*)((char*)self + 0x14) * 8);
    while (node[0] & 1) {
        int idx = ((ux >> 15) << 1) | (uz >> 15);
        ux <<= 1;
        uz <<= 1;
        node = (unsigned short*)(nodes + (*(unsigned short*)((char*)node + (idx << 1)) >> 1) * 8);
    }
    if (node[0] & 1) {
        return 0;
    }
    return node;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", cQuadTree_exportTree);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void func_002C16B8(unsigned short* p, unsigned short a, unsigned short b, unsigned short c, unsigned short d);
struct func_002C2088_sOut;
struct func_002C2088_sNode;
extern "C" void func_002C2088(void* self, func_002C2088_sOut* out, int* count, int* map, func_002C2088_sNode* node);
extern char D_00485FB0[];
extern char D_00485FC8[];

struct sQTHeader_1DA8 {
    float f0;           // 0x00
    float f4;           // 0x04
    float f8;           // 0x08
    int fC;             // 0x0C
    int f10;            // 0x10
    unsigned short f14; // 0x14
    unsigned short f16;
    int f18;            // 0x18
    int f1C;            // 0x1C
    char* f20;          // 0x20
    int f24;            // 0x24
};

extern "C" void cQuadTree_exportTree(sQTHeader_1DA8* self, char** out, int* size, void* ctx,
                                     float (*fixFloat)(void*, float), int (*fixInt)(int, void*),
                                     unsigned short (*fixShort)(unsigned short, void*))
{
    int i;
    *size = self->fC * 8 + 0x28;
    int* map = new (D_00485FB0, 0, 0) int[self->f10];
    for (i = 0; i < self->f10; i++)
        map[i] = -1;
    *out = new (D_00485FC8, 0, 0) char[*size];
    func_00416210(*out, 0xDEADBEEF, *size);
    sQTHeader_1DA8* o = (sQTHeader_1DA8*)*out;
    *o = *self;
    int cnt = 0;
    unsigned short* p = (unsigned short*)(o + 1);
    func_002C2088(self, (func_002C2088_sOut*)p, &cnt, map, (func_002C2088_sNode*)(self->f20 + self->f14 * 8));
    for (i = 0; i < cnt; i++, p += 4) {
        if (p[0] & 1) {
            func_002C16B8(p, map[p[0] >> 1], map[p[1] >> 1], map[p[2] >> 1], map[p[3] >> 1]);
            p[0] = fixShort(p[0], ctx);
            p[1] = fixShort(p[1], ctx);
            p[2] = fixShort(p[2], ctx);
            p[3] = fixShort(p[3], ctx);
        } else {
            ((int*)p)[0] = fixInt(((int*)p)[0], ctx);
            ((int*)p)[1] = fixInt(((int*)p)[1], ctx);
        }
    }
    o->f10 = 0;
    o->f24 = 0;
    o->f1C = fixInt(self->f1C, ctx);
    o->f18 = fixInt(self->f18, ctx);
    o->f0 = fixFloat(ctx, o->f0);
    o->f4 = fixFloat(ctx, o->f4);
    o->f8 = fixFloat(ctx, o->f8);
    o->fC = fixInt(o->fC, ctx);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2088);
#ifdef SKIP_ASM
struct func_002C2088_sNode {
    unsigned short child[4];
};
struct func_002C2088_sOut {
    int f0;
    int f4;
};

// PORT: node index computed from pointers cast to unsigned int
extern "C" void func_002C2088(void* self, func_002C2088_sOut* out, int* count, int* map, func_002C2088_sNode* node)
{
    int i;
    unsigned short* p;
    out[*count].f4 = *(int*)((char*)node + 4);
    out[*count].f0 = *(int*)((char*)node + 0);
    map[(unsigned short)(((unsigned int)node - *(unsigned int*)((char*)self + 0x20)) >> 3)] = (*count)++;
    if (node->child[0] & 1) {
        p = node->child;
        for (i = 0; i < 4; i++) {
            func_002C2088(self, out, count, map, *(func_002C2088_sNode**)((char*)self + 0x20) + (*p++ >> 1));
        }
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2178);
#ifdef SKIP_ASM
extern "C" int func_002C2178(char *self, unsigned short *node) {
    int count = 1;
    if (node != 0) {
        if (*node & 1) {
            unsigned short *p = node;
            int i = 3;
            do {
                unsigned short v = *p;
                p += 1;
                i -= 1;
                count += func_002C2178(self, (unsigned short *)(*(char **)(self + 0x20) + ((v >> 1) * 8)));
            } while (i >= 0);
        }
    }
    return count;
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2200);
#ifdef SKIP_ASM
extern "C" void func_002C2200(void) {

}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2208);
#ifdef SKIP_ASM
extern "C" void func_002C2208(void) {

}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2210);
#ifdef SKIP_ASM
extern "C" short func_002C2338(unsigned char c);

extern "C" void func_002C2210(void* self, short* dst, const char* src)
{
    while (*src != 0) {
        *dst++ = func_002C2338(*src++);
    }
    *dst = 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2268);
#ifdef SKIP_ASM
extern "C" char func_002C2430(short c);

extern "C" void func_002C2268(void* self, char* dst, const short* src)
{
    for (; *src != 0; src++, dst++) {
        *dst = func_002C2430(*src);
    }
    *dst = 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C22C8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002C3FA8(void*);
extern const char D_00485FF0[];

extern "C" void* func_002C22C8(void)
{
    return func_002C3FA8(cMemMan_alloc(0x1500, D_00485FF0, 0x100, 0));
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2300);
#ifdef SKIP_ASM
class func_002C2300_cObj {
public:
    virtual ~func_002C2300_cObj();
};

extern "C" void func_002C2300(func_002C2300_cObj* self)
{
    delete self;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2338);
#ifdef SKIP_ASM
struct func_002C2338_sRange {
    unsigned short base;
    unsigned short first;
};
extern func_002C2338_sRange D_00445940[];
extern unsigned short D_00445950[];

extern "C" short func_002C2338(unsigned char c)
{
    int off = 0;
    int idx = 0;
    unsigned short v;

    if (c >= 0x20 && c <= 0x2F) {
        off = 1;
    } else if (c >= 0x30 && c <= 0x39) {
    } else if (c >= 0x3A && c <= 0x40) {
        off = 0xB;
    } else if (c >= 0x41 && c <= 0x5A) {
        idx = 1;
    } else if (c >= 0x5B && c <= 0x60) {
        off = 0x25;
    } else if (c >= 0x61 && c <= 0x7A) {
        idx = 2;
    } else if (c >= 0x7B && c <= 0x7E) {
        off = 0x3F;
    } else {
        return 0;
    }
    if (off != 0) {
        v = D_00445950[(c - 0x20) + 1 - off];
    } else {
        v = D_00445940[idx].base + c - D_00445940[idx].first;
    }
    return (v << 8) | (v >> 8);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2430);
#ifdef SKIP_ASM
extern unsigned char D_00445998[];
// Shift-JIS full-width range table: {first code, ASCII of first code} per range (digits, upper, lower case).
extern unsigned char D_004A3890[6];
extern unsigned char D_004A3891[5];

// Converts a Shift-JIS double-byte character (lead byte in the low byte) to ASCII; 0 if it has none.
// PORT: declared earlier in the unit as char(short); defined under its own name bound to the symbol.
extern "C" unsigned char func_002C2430_impl(unsigned int code) __asm__("func_002C2430");
extern "C" unsigned char func_002C2430_impl(unsigned int code)
{
    unsigned int hi = (code >> 8) & 0xFF;
    int i = 0;
    unsigned char* ascii = D_004A3891;
    code &= 0xFF;
    if (code == 0x81)
        return D_00445998[hi - 0x40];
    if (code == 0x82) {
        if (hi - 0x4F < 10)
            i = 0;
        else if (hi - 0x60 < 26)
            i = 1;
        else if ((unsigned char)(hi + 0x7F) < 26)
            i = 2;
        else
            i = 0;
        return ascii[i * 2] + (hi - D_004A3890[i * 2]);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C24D0);
#ifdef SKIP_ASM
extern "C" int func_002C24D0(unsigned short* s)
{
    int n = 0;
    while (*s++ != 0) {
        n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2508);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C2508(unsigned short* dst, unsigned short* src)
{
    unsigned short* ret = dst;
    while (*src != 0) {
        *dst++ = *src++;
    }
    *dst = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2540);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C2540(unsigned short* dst, char* src)
{
    unsigned short* ret = dst;
    while (*src != 0) {
        *dst++ = *src++;
    }
    *dst = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2580);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// The unit declares this as extern "C" void* func_002C2580(void*) further down
// (its caller func_002C5500 passes one arg); bind the 2-arg body to the symbol.
char* func_002C2580_impl(char* dst, unsigned short* src) __asm__("func_002C2580");
char* func_002C2580_impl(char* dst, unsigned short* src)
{
    char* ret = dst;
    while (*src != 0) {
        *dst++ = *src++;
    }
    *dst = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C25B8);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C25B8(unsigned short* dst, unsigned short* src, int n)
{
    unsigned short* ret = dst;
    while (*src != 0 && n > 0) {
        *dst++ = *src++;
        n--;
    }
    *dst = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C25F8);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C25F8(unsigned short* dst, const char* src, int n)
{
    unsigned short* start = dst;
    while (*src && n > 0) {
        *dst++ = *src++;
        n--;
    }
    *dst = 0;
    return start;
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2640);
#ifdef SKIP_ASM
extern "C" unsigned char* func_002C2640(unsigned char* dst, const unsigned short* src, int n)
{
    unsigned char* start = dst;
    while (*src && n > 0) {
        *dst++ = *src++;
        n--;
    }
    *dst = 0;
    return start;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C2688);
#ifdef SKIP_ASM
extern "C" unsigned short* func_002C2508(unsigned short* dst, unsigned short* src);

extern "C" unsigned short* func_002C2688(unsigned short* dst, unsigned short* src)
{
    while (*dst != 0) {
        dst++;
    }
    return func_002C2508(dst, src);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C26D0);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
typedef char* func_002C26D0_va_list;
#define func_002C26D0_va_start(ap)                                       \
    (ap = (char*)__builtin_next_arg()                                    \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

extern "C" int USTR_vsprintf(unsigned short* dst, const unsigned short* fmt, char* ap);

extern "C" int func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...)
{
    func_002C26D0_va_list ap;
    func_002C26D0_va_start(ap);
    return USTR_vsprintf(dst, fmt, ap);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2718);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

// PORT: hand-rolled EE EABI va_start (func_002C26D0_va_start, defined above); use <stdarg.h> off-PS2.
extern "C" int func_002C2718(unsigned short* dst, const char* fmt, ...)
{
    func_002C26D0_va_list ap;
    unsigned short buf[0x400];
    unsigned short* p;
    int n;
    int i;
    p = buf;
    n = strlen(fmt);
    for (i = 0; i < n; i++) {
        *p++ = *fmt++;
    }
    *p = 0;
    func_002C26D0_va_start(ap);
    return USTR_vsprintf(dst, buf, ap);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C27C0);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

// PORT: hand-rolled EE EABI va_start (func_002C26D0_va_start, defined above); use <stdarg.h> off-PS2.
extern "C" int func_002C27C0(unsigned short* dst, const char* fmt, ...)
{
    func_002C26D0_va_list ap;
    unsigned short buf[0x400];
    unsigned short* p;
    int n;
    int i;
    p = buf;
    n = strlen(fmt);
    for (i = 0; i < n; i++) {
        *p++ = *fmt++;
    }
    *p = 0;
    func_002C26D0_va_start(ap);
    return USTR_vsprintf(dst, buf, ap);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2868);
#ifdef SKIP_ASM
extern "C" void func_002C2868(char* s)
{
    while (*s != 0) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += 'a' - 'A';
        }
        s++;
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C28A0);
#ifdef SKIP_ASM
extern "C" void func_003E4E98();

extern "C" void func_002C28A0(void) {
    func_003E4E98();
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C28C0);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00486030[];

extern "C" int func_002C28C0(int unused, int size, int zeroFlag)
{
    return (int)new (D_00486030, zeroFlag ? 0x100 : 0, 0) char[size];
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C28F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// Unit declares func_002523A8 / func_002C28F8 later with void return; keep the int-returning
// signatures under asm labels. The argument passes straight through in a0.
extern "C" int func_002523A8_ret(void* p) __asm__("func_002523A8");
extern "C" int func_002C28F8_impl(void* p) __asm__("func_002C28F8");

extern "C" int func_002C28F8_impl(void* p)
{
    return func_002523A8_ret(p) != 0;
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2918);
#ifdef SKIP_ASM
extern "C" void func_003E6574();

extern "C" int func_002C2918(int arg0) {
    func_003E6574();
    return arg0;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C2940);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void MUTEX_lock_p(void*) __asm__("MUTEX_lock");
extern "C" void MUTEX_unlock_p(void*) __asm__("MUTEX_unlock");
extern "C" int cMemMan_internalResizeBlock(int, int);
extern "C" int func_002C28C0(int, int, int);
extern "C" void func_002C28F8(int);
extern char D_00538B00[];

extern "C" int func_002C2940(int block, int a, int size, int c) {
    if (block == 0) {
        return func_002C28C0(a, size, c);
    }
    if (size == 0) {
        func_002C28F8(block);
        return 0;
    } else {
        int r;
        MUTEX_lock_p(D_00538B00);
        r = cMemMan_internalResizeBlock(block, size);
        MUTEX_unlock_p(D_00538B00);
        return r;
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C29D0);
#ifdef SKIP_ASM
extern "C" int func_002C28C0(int, int, int);
extern "C" void func_002C28F8(int);
extern "C" int func_003E50C8(int* self, int a1, int a2, int a3, int a4, int a5);
extern char D_00486088[];

// Predicate helper; keeps p[0] in one register for both tests.
inline int func_002C29D0_valid(int arg0)
{
    return arg0 != 0;
}

// PORT: the unit later declares func_002C29D0() for its address use; bound by asm label
int* func_002C29D0_impl(int a0, int a1, int size) __asm__("func_002C29D0");

int* func_002C29D0_impl(int a0, int a1, int size)
{
    int* p = (int*)func_002C28C0(0, 0xC, 0);
    p[0] = 0;
    p[0] = func_002C28C0((int)D_00486088, size, 0);
    if (p[0] != 0) {
        if (func_003E50C8(p + 1, a0, a1, p[0], size, 0x63) == 0) {
            func_002C28F8(p[0]);
            p[0] = 0;
        }
    }
    if (func_002C29D0_valid(p[0])) {
        return p;
    }
    if (p != 0) {
        if (p[0] != 0) {
            func_002C28F8(p[0]);
        }
        func_002C28F8((int)p);
    }
    return 0;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C2AA8);
#ifdef SKIP_ASM
extern "C" void func_002C28F8(int);

extern "C" void func_002C2AA8(int *self) {
    if (*self != 0) {
        func_002C28F8(*self);
        *self = 0;
    }
    if (self != 0) {
        if (*self != 0) {
            func_002C28F8(*self);
        }
        func_002C28F8((int)self);
    }
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2B08);
#ifdef SKIP_ASM
extern "C" void func_003E5398();

extern "C" void func_002C2B08(void) {
    func_003E5398();
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2B28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_002C28C0(int, int, int);
extern "C" void func_003E5698(int);
extern char D_004A3898[];

// The unit declares func_002C2B28 later as void(); keep the real signature under an asm label.
extern "C" int func_002C2B28_impl(void) __asm__("func_002C2B28");

extern "C" int func_002C2B28_impl(void)
{
    int p = func_002C28C0((int)D_004A3898, 0x10, 0);
    func_003E5698(p);
    return p;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C2B68);
#ifdef SKIP_ASM
extern "C" void func_002C28F8(int);
extern "C" void func_003E56E0();

extern "C" void func_002C2B68(int arg0) {
    func_003E56E0();
    func_002C28F8(arg0);
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2B98);
#ifdef SKIP_ASM
extern "C" void MUTEX_lock();

extern "C" void func_002C2B98(void) {
    MUTEX_lock();
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2BB8);
#ifdef SKIP_ASM
extern "C" void MUTEX_unlock();

extern "C" void func_002C2BB8(void) {
    MUTEX_unlock();
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C2BD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_004165A8();
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void func_002C29D0();
extern "C" void func_002C2AA8();
extern "C" void func_002C2B08();
extern "C" void func_002C2B28();
extern void func_002C28C0_2BD8() __asm__("func_002C28C0");
extern void func_002C2940_2BD8() __asm__("func_002C2940");
extern "C" void func_0041610C();
extern "C" void func_00415FC8();
extern "C" void func_0041605C();
extern "C" void func_002C28A0();
extern "C" void func_004187A0();
extern "C" void func_004187C0();
extern "C" void func_004187E8();
extern "C" void func_00418EF8();
extern "C" void func_002C2BD8(char* self) {
    *(void**)(self + 0x3C) = (void*)&func_002C28C0_2BD8;
    *(void**)(self + 0x40) = (void*)&func_002C2940_2BD8;
    *(void**)(self + 0x44) = (void*)&func_002C28F8;
    *(void**)(self + 0x48) = (void*)&func_00416210;
    *(void**)(self + 0x50) = (void*)&func_0041610C;
    *(void**)(self + 0x54) = (void*)&func_00415FC8;
    *(void**)(self + 0x4C) = (void*)&func_0041605C;
    *(void**)(self + 0x58) = (void*)&func_002C28A0;
    *(void**)(self + 0x14) = (void*)&func_004187A0;
    *(void**)(self + 0x10) = (void*)&func_004187C0;
    *(void**)(self + 0x1C) = (void*)&func_004187E8;
    *(void**)(self + 0x18) = (void*)&func_00418EF8;
    *(void**)(self + 0xC) = (void*)&func_004165A8;
    *(void**)(self + 0x8) = (void*)&strcpy;
    *(void**)(self + 0x4) = (void*)&strlen;
    *(void**)(self + 0x20) = (void*)&func_002C29D0;
    *(void**)(self + 0x24) = (void*)&func_002C2AA8;
    *(void**)(self + 0x28) = (void*)&func_002C2B08;
    *(void**)(self + 0x2C) = (void*)&func_002C2B28;
    *(void**)(self + 0x30) = (void*)&func_002C2B68;
    *(void**)(self + 0x34) = (void*)&func_002C2B98;
    *(void**)(self + 0x38) = (void*)&func_002C2BB8;
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2D30);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00486098[];

extern "C" int func_002C2D30(int unused, int size, int zeroFlag)
{
    return (int)new (D_00486098, zeroFlag ? 0x100 : 0, 0) char[size];
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2D68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// Unit declares func_002523A8 / func_002C2D68 later with void return; keep the int-returning
// signatures under asm labels. The argument passes straight through in a0.
extern "C" int func_002523A8_ret(void* p) __asm__("func_002523A8");
extern "C" int func_002C2D68_impl(void* p) __asm__("func_002C2D68");

extern "C" int func_002C2D68_impl(void* p)
{
    return func_002523A8_ret(p) != 0;
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2D88);
#ifdef SKIP_ASM
extern "C" void func_003E6574();

extern "C" int func_002C2D88(int arg0) {
    func_003E6574();
    return arg0;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C2DB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void MUTEX_lock_p(void*) __asm__("MUTEX_lock");
extern "C" void MUTEX_unlock_p(void*) __asm__("MUTEX_unlock");
extern "C" int cMemMan_internalResizeBlock(int, int);
extern "C" int func_002C2D30(int, int, int);
extern "C" void func_002C2D68(int);
extern char D_00538B00[];

extern "C" int func_002C2DB0(int block, int a, int size, int c) {
    if (block == 0) {
        return func_002C2D30(a, size, c);
    }
    if (size == 0) {
        func_002C2D68(block);
        return 0;
    } else {
        int r;
        MUTEX_lock_p(D_00538B00);
        r = cMemMan_internalResizeBlock(block, size);
        MUTEX_unlock_p(D_00538B00);
        return r;
    }
}
#endif
//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C2E40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// The unit declares func_002C2E40 later as void(); keep the real signature under an asm label.
extern "C" int func_002C2E40_impl(unsigned short* s) __asm__("func_002C2E40");

extern "C" int func_002C2E40_impl(unsigned short* s)
{
    int n = 0;
    while (*s++) {
        n++;
    }
    return n;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C2E78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002C2D30_2E78() __asm__("func_002C2D30");
extern "C" void func_002C2D68();
extern void func_002C2DB0_2E78() __asm__("func_002C2DB0");
extern "C" void func_002C2E40();
extern "C" void func_00415FC8();
extern "C" void func_0041610C();
extern "C" void func_004162D0();
extern "C" void func_004187C0();
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);

extern "C" void func_002C2E78(char* self) {
    *(void**)(self + 0x1C) = (void*)&func_002C2D30_2E78;
    *(void**)(self + 0x20) = (void*)&func_002C2DB0_2E78;
    *(void**)(self + 0x24) = (void*)&func_002C2D68;
    *(void**)(self + 0x2C) = (void*)&func_002C2D88;
    *(void**)(self + 0x28) = (void*)&func_00416210;
    *(void**)(self + 0x30) = (void*)&func_0041610C;
    *(void**)(self + 0x34) = (void*)&func_00415FC8;
    *(void**)(self + 0x04) = (void*)&func_004162D0;
    *(void**)(self + 0x08) = (void*)&strlen;
    *(void**)(self + 0x0C) = (void*)&func_002C2E40;
    *(void**)(self + 0x10) = (void*)&sprintf;
    *(void**)(self + 0x14) = (void*)&strcpy;
    *(void**)(self + 0x18) = (void*)&func_004187C0;
}
#endif

INCLUDE_ASM("worldpainter/quadtree", func_002C2F18);

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C3FA0__FPv);
#ifdef SKIP_ASM
void func_002C3FA0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C3FA8);
#ifdef SKIP_ASM
extern "C" void func_002C4050(void*);
extern void* D_00486F78[];

extern "C" void* func_002C3FA8(void* self)
{
    *(void***)self = D_00486F78;
    func_002C4050(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C3FE0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_002523A8(void* p);
extern "C" void func_002C6360(void* self);
extern void* D_00486F78[];
extern void* D_004871E8[];

extern "C" void func_002C3FE0(void* self, int flags)
{
    *(void***)self = D_00486F78;
    func_002C6360(self);
    void* p = *(void**)((char*)self + 0x30);
    if (p != 0) {
        func_002523A8(p);
    }
    *(void***)self = D_004871E8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("worldpainter/quadtree", func_002C4050);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C4198);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
char* func_002C2580_impl(char* dst, unsigned short* src) __asm__("func_002C2580");

struct sVEntry002C4198 {
    short delta;
    short index;
    void (*fn)(void*, char*);
};

extern "C" void func_002C4198(void* self, unsigned short* name)
{
    char buf[1000];
    func_002C2580_impl(buf, name);
    sVEntry002C4198* vt = *(sVEntry002C4198**)self;
    vt[6].fn((char*)self + vt[6].delta, buf);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C41D8);
#ifdef SKIP_ASM
extern "C" void* func_002C48C0(void*, int);

extern "C" void func_002C41D8(void* self, const char* name)
{
    strcpy((char*)self + 0x139, name);
    func_002C48C0(self, 5);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4210);
#ifdef SKIP_ASM
extern "C" int func_0040A688(int h, int a1, char* name, int a3, int a4, void* buf);
extern int D_004A3940;
extern "C" void* func_003E6448(void* dst, int c, int n);

extern "C" void func_002C4210(void* self)
{
    char* buf = (char*)self + 0x4C0;
    func_003E6448(buf, 0, 0x1000);
    int r = func_0040A688(*(int*)((char*)self + 0xC), 0, (char*)self + 0x139, 0, 6, buf);
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 6);
    }
}
#endif

extern "C" void* func_002C48C0(void*, int);

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4290__FPvi);
#ifdef SKIP_ASM
void* func_002C4290(void* self, int a1)
{
    *(int*)((char*)self + 0x1c) = a1;
    return func_002C48C0(self, 0x22);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C42B0);
#ifdef SKIP_ASM
extern "C" int func_0040A688(int h, int a1, char* name, int a3, int a4, void* buf);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern int D_004A3940;
extern char D_004A3948[];

extern "C" void func_002C42B0(void* self)
{
    char* name = (char*)self + 0xB9;
    *(int*)((char*)self + 0x3C) = 0;
    char* path = (char*)self + 0xF9;
    strcpy(name, (char*)self + *(int*)((char*)self + 0x1C) * 0x78 + 0x1B0);
    sprintf(path, D_004A3948, name, name);
    int r = func_0040A688(*(int*)((char*)self + 0xC), 0, path, 0, 1, (char*)self + 0x480);
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x23);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4368__FPv);
#ifdef SKIP_ASM
void* func_002C4368(void* self)
{
    return func_002C48C0(self, 0x11);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4388);
#ifdef SKIP_ASM
extern "C" int func_0040A998(int h, int a1);
extern int D_004A3940;

extern "C" void func_002C4388(void* self)
{
    int r = func_0040A998(*(int*)((char*)self + 0xC), 0);
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x12);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C43E0__FPvi);
#ifdef SKIP_ASM
void* func_002C43E0(void* self, int a1)
{
    *(int*)((char*)self + 0x1c) = a1;
    return func_002C48C0(self, 0x13);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4400__FPv);
#ifdef SKIP_ASM
int func_002C4400(void* self)
{
    return *(int*)((char*)self + 0x490);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4408__FPvi);
#ifdef SKIP_ASM
void func_002C4408(void* self, int val)
{
    *(int*)((char*)self + 0x24) = val;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4410);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* func_002C48C0(void*, int);
extern char D_004A3948[];

extern "C" void func_002C4410(void* self)
{
    char* name = (char*)self + 0xB9;
    *(int*)((char*)self + 0x3C) = 0;
    strcpy(name, (char*)self + *(int*)((char*)self + 0x1C) * 0x78 + 0x1B0);
    sprintf((char*)self + 0xF9, D_004A3948, name, name);
    func_002C48C0(self, 0x36);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4480);
#ifdef SKIP_ASM
class func_002C4480_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10();
    virtual int v11(); // 0x58
};

extern "C" void func_002C4480(func_002C4480_cObj* self, int a1)
{
    *(int*)((char*)self + 0xC) = a1;
    if (self->v11() == 0) {
        *(int*)((char*)self + 0x10) = a1;
        func_002C48C0(self, 3);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C44E0);
#ifdef SKIP_ASM
struct sQTLevel {
    int f00;
    void* f04;
    int f08;
    int f0C;
    int f10;
};

struct sQTState {
    char pad000[0xC];
    int level;
    char pad010[0x16C];
    sQTLevel levels[1];
};

extern "C" void func_002C44E0(sQTState* self)
{
    self->levels[self->level].f10 = 0;
    if (self->levels[self->level].f08 == -1) {
        self->levels[self->level].f08 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4520);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004A3950[];

extern "C" void func_002C4520(void* self, const char* name)
{
    char* p = (char*)self + 0xB9;
    strcpy(p, name);
    sprintf((char*)self + 0xF9, D_004A3950, p);
    func_002C48C0(self, 0x14);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C4578);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004A3950[];
// PORT: func_002C2580 takes (dst, src); the unit declares it with one arg
char* func_002C2580_impl(char* dst, unsigned short* src) __asm__("func_002C2580");

extern "C" void func_002C4578(void* self, unsigned short* name)
{
    char* p = (char*)self + 0xB9;
    func_002C2580_impl(p, name);
    sprintf((char*)self + 0xF9, D_004A3950, p);
    func_002C48C0(self, 0x14);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C45D0);
#ifdef SKIP_ASM
// PORT: func_002C2580 takes (dst, src); the unit declares it with one arg
char* func_002C2580_impl(char* dst, unsigned short* src) __asm__("func_002C2580");
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* func_002C48C0(void*, int);
extern char D_004A3948[];

extern "C" void func_002C45D0(void* self, unsigned short* wname, int a2, int a3)
{
    char* name = (char*)self + 0xB9;
    func_002C2580_impl(name, wname);
    sprintf((char*)self + 0xF9, D_004A3948, name, name);
    *(int*)((char*)self + 0x2C) = a2;
    *(int*)((char*)self + 0x20) = a3;
    func_002C48C0(self, 0x15);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4648);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* func_002C48C0(void*, int);
extern char D_004A3948[];

extern "C" void func_002C4648(void* self, const char* src, int a2, int a3)
{
    char* name = (char*)self + 0xB9;
    strcpy(name, src);
    sprintf((char*)self + 0xF9, D_004A3948, name, name);
    *(int*)((char*)self + 0x2C) = a2;
    *(int*)((char*)self + 0x20) = a3;
    func_002C48C0(self, 0x15);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C46C0);
#ifdef SKIP_ASM
class func_002C46C0_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
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
    virtual void v36(char* name, int a2, int a3); // 0x120
};

extern "C" void func_002C54D0(void* self, int a1, char* dst);

extern "C" void func_002C46C0(func_002C46C0_cObj* self, int a1, int a2, int a3)
{
    char name[64];
    func_002C54D0(self, a1, name);
    self->v36(name, a2, a3);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4720__FPvii);
#ifdef SKIP_ASM
void* func_002C4720(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x2c) = a1;
    *(int*)((char*)self + 0x20) = a2;
    return func_002C48C0(self, 0x17);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4748);
#ifdef SKIP_ASM
extern "C" int func_002C4748(void* self)
{
    return *(int*)((char*)self + 0x4) == 0x34;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4758__FPv);
#ifdef SKIP_ASM
void func_002C4758(void* self)
{
    *(int*)((char*)self + 0x48) = 1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4768__FPv);
#ifdef SKIP_ASM
void* func_002C4768(void* self)
{
    return func_002C48C0(self, 0x18);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4788);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* func_002C48C0(void*, int);
extern char D_004A3948[];

extern "C" void func_002C4788(void* self, char* src, int a2, int a3)
{
    char* name = (char*)self + 0xB9;
    strcpy(name, src);
    sprintf((char*)self + 0xF9, D_004A3948, name, name);
    *(int*)((char*)self + 0x2C) = a2;
    *(int*)((char*)self + 0x20) = a3;
    func_002C48C0(self, 0x1B);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C4800);
#ifdef SKIP_ASM
extern "C" void func_002C54D0(void* self, int a1, char* dst);
extern "C" void func_002C4788(void* self, char* name, int a2, int a3);

extern "C" void func_002C4800(void* self, int a1, int a2, int a3)
{
    char name[64];
    func_002C54D0(self, a1, name);
    func_002C4788(self, name, a2, a3);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4858__FPvii);
#ifdef SKIP_ASM
void* func_002C4858(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x2c) = a1;
    *(int*)((char*)self + 0x20) = a2;
    return func_002C48C0(self, 0x1d);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4880);
#ifdef SKIP_ASM
extern "C" int func_002C4880(void* self)
{
    return *(int*)((char*)self + 0x4) == 0x35;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C4890__FPv);
#ifdef SKIP_ASM
void func_002C4890(void* self)
{
    *(int*)((char*)self + 0x44) = 1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C48A0__FPv);
#ifdef SKIP_ASM
void* func_002C48A0(void* self)
{
    return func_002C48C0(self, 0x1e);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C48C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_002523A8(void* p);
extern "C" void func_002C2210(void* self, short* dst, const char* src);
extern "C" int func_002C50E0(void* self);
extern "C" void func_002C5570(void* self, int a1);
extern "C" int func_003DF690(char* path, int a1);
extern "C" void* func_003E6448(void* dst, int c, int n);
extern "C" void func_003E6574_K(void* dst, const void* src, int n) __asm__("func_003E6574");
extern "C" int func_00409D10(int h, int a1, char* name, int a3);
extern "C" int func_00409E38(int h, int a1, char* name);
extern "C" int func_00409E70(int h);
extern "C" int func_0040A090(int h, int a1, int a2);
extern "C" int func_0040A1A8(int h, int a1, int a2);
extern "C" int func_0040A688(int h, int a1, char* name, int a3, int a4, void* buf);
extern "C" int func_0040AA68(int h, int a1, char* name);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern int D_004A3940;
extern char D_004A3948[];
extern char D_004A3958[];
extern char D_004A3960[] __attribute__((aligned(4)));
extern char D_00487460[];
extern char* D_004459F0[];
extern char D_00445A00[];
extern char D_00445A40[];
extern char D_00445A70[];
extern char D_00445AA0[];

struct sIconSys_48C0 {
    char head[4];               // 0x000
    unsigned short reserv1;     // 0x004
    unsigned short offsLF;      // 0x006
    unsigned int reserv2;       // 0x008
    unsigned int transRate;     // 0x00C
    int bgColor[4][4];          // 0x010
    float lightDir[3][4];       // 0x050
    float lightColor[3][4];     // 0x080
    float ambient[4];           // 0x0B0
    short title[34];            // 0x0C0
    char fnameView[64];         // 0x104
    char fnameCopy[64];         // 0x144
    char fnameDel[64];          // 0x184
    char reserve3[512];         // 0x1C4
};
extern sIconSys_48C0 D_005376F8;

class cMemCard_48C0 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66();
    virtual int v67(int idx); // 0x218
};

static inline int slotOf_48C0(int state, int a, int b)
{
    return state == a ? 1 : (state == b ? 2 : 0);
}

#define S_48C0(off) ((char*)self + (off))
#define I_48C0(off) (*(int*)((char*)self + (off)))

extern "C" void* func_002C48C0(void* vself, int state)
{
    cMemCard_48C0* self = (cMemCard_48C0*)vself;
    I_48C0(0x4) = state;
    switch (state) {
    case 1: {
        *(int*)((char*)self + I_48C0(0xC) * 0x14 + 0x184) = D_004A3940;
        if (I_48C0(0x30) != 0) {
            func_002523A8(*(void**)S_48C0(0x30));
            I_48C0(0x30) = 0;
        }
        if (I_48C0(0x18) >= 0) {
            int r = func_00409E70(I_48C0(0x18));
            D_004A3940 = r;
            if (r >= 0) {
                func_002C48C0(self, 2);
            }
            I_48C0(0x18) = -1;
        }
        I_48C0(0x2C) = 0;
        I_48C0(0x1C) = -1;
        I_48C0(0x20) = 0;
        break;
    }
    case 3:
        func_002C50E0(self);
        break;
    case 0x24: {
        I_48C0(0x48) = 0;
        int r = func_00409E38(I_48C0(0xC), 0, S_48C0(0xF9));
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x25: {
        char* path = S_48C0(0x79);
        sprintf(path, D_004A3958, S_48C0(0xF9), D_00487460);
        int r = func_00409D10(I_48C0(0xC), 0, path, 0x203);
        D_004A3940 = r;
        I_48C0(0x18) = -1;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x26: {
        char* title = S_48C0(0x58);
        func_003E6448(&D_005376F8, 0, 0x3C4);
        memcpy(&D_005376F8, D_004A3960, 5);
        func_002C2210(self, D_005376F8.title, title);
        if (I_48C0(0x8) > 0)
            D_005376F8.offsLF = I_48C0(0x8);
        else
            D_005376F8.offsLF = strlen(title) * 2;
        D_005376F8.transRate = 0x60;
        func_003E6574_K(D_005376F8.bgColor, D_00445A00, 0x40);
        func_003E6574_K(D_005376F8.lightDir, D_00445A40, 0x30);
        func_003E6574_K(D_005376F8.lightColor, D_00445A70, 0x30);
        func_003E6574_K(D_005376F8.ambient, D_00445AA0, 0x10);
        strcpy(D_005376F8.fnameView, D_004459F0[0]);
        strcpy(D_005376F8.fnameCopy, D_004459F0[1]);
        strcpy(D_005376F8.fnameDel, D_004459F0[2]);
        int r = func_0040A1A8(I_48C0(0x18), (int)&D_005376F8, 0x3C4);
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x27: {
        int r = func_00409E70(I_48C0(0x18));
        D_004A3940 = r;
        if (r < 0) {
            I_48C0(0x18) = -1;
            func_002C48C0(self, 1);
        } else {
            I_48C0(0x18) = -1;
        }
        break;
    }
    case 0x28: case 0x2C: case 0x30: {
        char path[64];
        if (I_48C0(0x30) != 0) {
            func_002523A8(*(void**)S_48C0(0x30));
            I_48C0(0x30) = 0;
        }
        int slot = slotOf_48C0(I_48C0(0x4), 0x2C, 0x30);
        sprintf(path, D_004A3958, S_48C0(0x14C0), D_004459F0[slot]);
        I_48C0(0x38) = func_003DF690(path, 0x100);
        break;
    }
    case 0x29: case 0x2D: case 0x31: {
        int slot = slotOf_48C0(I_48C0(0x4), 0x2D, 0x31);
        char* path = S_48C0(0x79);
        sprintf(path, D_004A3948, S_48C0(0xB9), D_004459F0[slot]);
        int r = func_00409D10(I_48C0(0xC), 0, path, 0x203);
        D_004A3940 = r;
        if (r < 0) {
            I_48C0(0x18) = -1;
            func_002C48C0(self, 1);
        } else {
            I_48C0(0x18) = -1;
        }
        break;
    }
    case 0x2A: case 0x2E: case 0x32: {
        int r = func_0040A1A8(I_48C0(0x18), I_48C0(0x30), I_48C0(0x34));
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x2B: case 0x2F: case 0x33: {
        if (I_48C0(0x30) != 0) {
            func_002523A8(*(void**)S_48C0(0x30));
            I_48C0(0x30) = 0;
        }
        int r = func_00409E70(I_48C0(0x18));
        D_004A3940 = r;
        if (r < 0) {
            I_48C0(0x18) = -1;
            func_002C48C0(self, 1);
        } else {
            I_48C0(0x18) = -1;
        }
        break;
    }
    case 0x16: {
        int r = func_00409D10(I_48C0(0xC), 0, S_48C0(0xF9), 0x203);
        D_004A3940 = r;
        if (r < 0) {
            I_48C0(0x18) = -1;
            func_002C48C0(self, 1);
        } else {
            I_48C0(0x18) = -1;
        }
        break;
    }
    case 0x17: {
        int r = func_0040A1A8(I_48C0(0x18), I_48C0(0x2C), I_48C0(0x20));
        D_004A3940 = r;
        I_48C0(0x2C) = 0;
        I_48C0(0x20) = 0;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x18:
        if (I_48C0(0x18) >= 0) {
            int r = func_00409E70(I_48C0(0x18));
            D_004A3940 = r;
            if (r < 0) {
                I_48C0(0x18) = -1;
                func_002C48C0(self, 1);
            } else {
                I_48C0(0x18) = -1;
            }
        } else {
            func_002C48C0(self, 0x19);
        }
        break;
    case 0x1C: {
        I_48C0(0x44) = 0;
        int r = func_00409D10(I_48C0(0xC), 0, S_48C0(0xF9), 1);
        D_004A3940 = r;
        I_48C0(0x18) = -1;
        if (r != 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x1D: {
        int r = func_0040A090(I_48C0(0x18), I_48C0(0x2C), I_48C0(0x20));
        D_004A3940 = r;
        if (r != 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x1E:
        if (I_48C0(0x18) >= 0) {
            int r = func_00409E70(I_48C0(0x18));
            D_004A3940 = r;
            if (r < 0) {
                I_48C0(0x18) = -1;
                func_002C48C0(self, 1);
            } else {
                I_48C0(0x18) = -1;
            }
        } else {
            func_002C48C0(self, 0x1F);
        }
        break;
    case 0x36: {
        *(int*)((char*)self + I_48C0(0xC) * 0x14 + 0x184) = 0;
        int r = func_0040AA68(I_48C0(0xC), 0, S_48C0(0xF9));
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x37: case 0x38: case 0x39: {
        int slot = slotOf_48C0(I_48C0(0x4), 0x38, 0x39);
        char* path = S_48C0(0x79);
        sprintf(path, D_004A3948, S_48C0(0xB9), D_004459F0[slot]);
        int r = func_0040AA68(I_48C0(0xC), 0, path);
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x3A: {
        char* path = S_48C0(0x79);
        sprintf(path, D_004A3948, S_48C0(0xB9), D_00487460);
        int r = func_0040AA68(I_48C0(0xC), 0, path);
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 0x3B: {
        int r = func_0040AA68(I_48C0(0xC), 0, S_48C0(0xB9));
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 1);
        break;
    }
    case 7:
        for (I_48C0(0x28) = 0; I_48C0(0x28) < I_48C0(0x14); I_48C0(0x28)++) {
            if (self->v67(I_48C0(0x28))) {
                sprintf(S_48C0(0x79), D_004A3948, (char*)self + I_48C0(0x28) * 0x78 + 0x1B0, D_00487460);
                func_002C48C0(self, 8);
                break;
            }
        }
        break;
    case 8: {
        int r = func_00409D10(I_48C0(0xC), 0, S_48C0(0x79), 1);
        D_004A3940 = r;
        if (r < 0) {
            I_48C0(0x18) = -1;
            func_002C5570(self, I_48C0(0x28));
            func_002C48C0(self, 0x10);
        } else {
            I_48C0(0x18) = -1;
        }
        break;
    }
    case 0xA: {
        int r = func_0040A090(I_48C0(0x18), (int)&D_005376F8, 0x3C4);
        D_004A3940 = r;
        if (r < 0) {
            func_002C5570(self, I_48C0(0x28));
            func_002C48C0(self, 0xF);
        }
        break;
    }
    case 9: {
        int r = func_00409E70(I_48C0(0x18));
        D_004A3940 = r;
        if (r < 0) {
            func_002C48C0(self, 0x10);
        } else {
            I_48C0(0x18) = -1;
        }
        break;
    }
    case 0xB: {
        char* path = S_48C0(0xF9);
        I_48C0(0x3C) = 0;
        char* buf = S_48C0(0x480);
        char* name = (char*)self + I_48C0(0x28) * 0x78 + 0x1B0;
        sprintf(path, D_004A3948, name, name);
        func_003E6448(buf, 0, 0x40);
        int r = func_0040A688(I_48C0(0xC), 0, path, 0, 1, buf);
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 0x10);
        break;
    }
    case 0xC: case 0xD: case 0xE: {
        int slot = slotOf_48C0(I_48C0(0x4), 0xD, 0xE);
        char* path = S_48C0(0x79);
        char* buf = S_48C0(0x480);
        sprintf(path, D_004A3948, (char*)self + I_48C0(0x28) * 0x78 + 0x1B0, D_004459F0[slot]);
        func_003E6448(buf, 0, 0x40);
        int r = func_0040A688(I_48C0(0xC), 0, path, 0, 1, buf);
        D_004A3940 = r;
        if (r < 0)
            func_002C48C0(self, 0x10);
        break;
    }
    case 0xF: {
        int r = func_00409E70(I_48C0(0x18));
        D_004A3940 = r;
        if (r < 0) {
            I_48C0(0x18) = -1;
            func_002C48C0(self, 0x10);
        } else {
            I_48C0(0x18) = -1;
        }
        break;
    }
    case 2: case 4: case 6: case 0x10: case 0x12: case 0x15: case 0x19: case 0x1B: case 0x1F:
    case 0x23: case 0x34: case 0x35: case 0x3D: case 0x40: case 0x42: case 0x44: case 0x46:
    case 0x48: case 0x4A: case 0x4C: case 0x4E:
        break;
    default:
        if (I_48C0(0x40) == 0)
            func_002C50E0(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C50E0);
#ifdef SKIP_ASM
extern "C" int func_0040A498(int h, int a1, int* a2, int* a3, int* a4);
extern int D_004A3938;
extern int D_004A393C;
extern int D_004A3944;

extern "C" int func_002C50E0(void* self)
{
    D_004A3938 = 0;
    *(int*)((char*)self + 0x20) = 0;
    int h = *(int*)((char*)self + 0xC);
    D_004A3944 = 0;
    D_004A393C = 0;
    int r = func_0040A498(h, 0, &D_004A3938, &D_004A393C, &D_004A3944) == 0;
    *(int*)((char*)self + 0x40) = r;
    *(int*)((char*)self + 0x4C) = 5;
    return r;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5140);
#ifdef SKIP_ASM
extern "C" int func_002C5140(void* self)
{
    if (*(int*)((char*)self + 0x4) != 0 || *(int*)((char*)self + 0x40) != 0) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5168);
#ifdef SKIP_ASM
extern "C" int func_002C5168(sQTState* self)
{
    switch (self->levels[self->level].f08) {
    case -1:
    case -3:
    case -8:
    case -9:
    case -10:
    case -10001:
    case -10002:
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C51D0);
#ifdef SKIP_ASM
// PORT: the unit declares this as `extern "C" void* func_002C51D0(void*, int)`
// for its callers; the body returns an int code, bound with an asm label.
extern "C" int func_002C51D0_impl(sQTState* self, int i) __asm__("func_002C51D0");

extern "C" int func_002C51D0_impl(sQTState* self, int i)
{
    switch (self->levels[i].f08) {
    case -10002:
    case -10001:
    case -7:
    case -6:
    case -5:
    case -4:
    case -3:
    case -2:
    case -1:
    case 0:
        return self->levels[i].f08;
    case -10:
    case -9:
    case -8:
    default:
        return -10;
    }
}
#endif

extern "C" void* func_002C51D0(void*, int);

//99.38%
INCLUDE_ASM("worldpainter/quadtree", func_002C5230__FPv);
#ifdef SKIP_ASM
int func_002C5230(void* self)
{
    return (func_002C51D0(self, *(int*)((char*)self + 0xc)) != 0);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5250);
#ifdef SKIP_ASM
extern "C" void func_002C5250(sQTState* self)
{
    self->levels[self->level].f00 = 0;
    self->levels[self->level].f04 = 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5278);
#ifdef SKIP_ASM
extern "C" void* func_003E6448(void* dst, int c, int n);
extern "C" void func_002C52D8(void* self);

extern "C" void func_002C5278(void* self)
{
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x54) = 0;
    func_003E6448((char*)self + 0x480, 0, 0x40);
    func_003E6448((char*)self + 0x1A4, 0, 0x2D0);
    func_003E6448((char*)self + 0x4C0, 0, 0x1000);
    func_002C52D8(self);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C52D8);
#ifdef SKIP_ASM
extern "C" void* func_003E6448(void* dst, int c, int n);

extern "C" void func_002C52D8(void* self)
{
    func_003E6448((char*)self + 0x480, 0, 0x40);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5300);
#ifdef SKIP_ASM
extern "C" int func_002C5300(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x14;
    return *(int*)(p + 0x184) == -0x2712;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5320);
#ifdef SKIP_ASM
extern "C" void* func_002C5320(void* self, int a1)
{
    return *(void**)((char*)self + a1 * 0x14 + 0x180);
}
#endif

//99.29%
INCLUDE_ASM("worldpainter/quadtree", func_002C5338__FPv);
#ifdef SKIP_ASM
void* func_002C5338(void* self)
{
    return func_002C5320(self, *(int*)((char*)self + 0xc));
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5358);
#ifdef SKIP_ASM
extern "C" int func_002C5358(sQTState* self, int i)
{
    switch (self->levels[i].f08) {
    case -10001:
    case -7:
    case -5:
    case -4:
    case -3:
    case -2:
    case -1:
    case 0:
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C53B0);
#ifdef SKIP_ASM
extern "C" int func_002C53B0(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x14;
    return *(int*)(p + 0x188) != 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C53C8);
#ifdef SKIP_ASM
extern "C" int func_002C53C8(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x14;
    return *(int*)(p + 0x18c) != 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C53E0);
#ifdef SKIP_ASM
int GetHashValue32(char*);
extern "C" unsigned short* func_002C2540(unsigned short* dst, char* src);
extern "C" int func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
// PORT: the unit defines func_002C5320 as returning void*; it returns an int count here.
extern "C" int func_002C5320_i(void* self, int idx) __asm__("func_002C5320");
extern char D_004A3968[];
extern char D_004861F8[];
extern char* D_004A28A8;

struct sQTEntry_53E0 {
    int count;
    int status;
    void* data;
    int fC;
    int f10;
};

struct sQT_53E0 {
    char pad[0x180];
    sQTEntry_53E0 entries[1];
};

struct func_002C53E0_sVEntry {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern "C" void func_002C53E0(sQT_53E0* self, int idx, unsigned short* dst)
{
    if (self->entries[idx].data == 0) {
        func_002C2540(dst, D_004A3968);
        return;
    }
    switch (self->entries[idx].status) {
    case -2:
        func_002C2540(dst, D_004A3968);
        break;
    case 0: {
        // PORT: g++ `>?` (max) operator, removed in GCC 4.3.
        int v = func_002C5320_i(self, idx) >? 0;
        char* obj = *(char**)(D_004A28A8 + 0x8C);
        func_002C53E0_sVEntry* vt = *(func_002C53E0_sVEntry**)(obj + 4);
        char* thisp = obj + vt[4].delta;
        func_002C26D0(dst, vt[4].fn(thisp, GetHashValue32(D_004861F8)), v);
        break;
    }
    default:
        func_002C2540(dst, D_004A3968);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C54D0);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);

extern "C" void func_002C54D0(void* self, int a1, char* dst)
{
    char* p = (char*)self + a1 * 0x78;
    strcpy(dst, p + 0x1b0);
}
#endif

extern "C" void* func_002C2580(void*);

//99.29%
INCLUDE_ASM("worldpainter/quadtree", func_002C5500__FPv);
#ifdef SKIP_ASM
void* func_002C5500(void* self)
{
    return func_002C2580((char*)self + 0x58);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5520__FPv);
#ifdef SKIP_ASM
void func_002C5520(void* self)
{
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5528);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

extern "C" bool func_002C5528(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x78;
    return strlen(p + 0x1b0) != 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5558);
#ifdef SKIP_ASM
extern "C" void func_002C5558(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x78;
    *(int*)(p + 0x1a4) = 1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5570);
#ifdef SKIP_ASM
extern "C" void func_002C5570(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x78;
    *(int*)(p + 0x1a8) = 1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C5588);
#ifdef SKIP_ASM
struct sQTSlot {
    int a;
    int b;
    char pad08[0x70];
};

struct sQTSlots {
    char pad000[0x1A4];
    sQTSlot slots[1];
};

extern "C" int func_002C5588(sQTSlots* self, int i)
{
    if (self->slots[i].b != 0 || self->slots[i].a != 0) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C55C0);
#ifdef SKIP_ASM
extern "C" int func_002C55C0(void* self, int a1)
{
    char* p = (char*)self + a1 * 0x78;
    return *(int*)(p + 0x1ac) != 0;
}
#endif

INCLUDE_ASM("worldpainter/quadtree", func_002C55D8);

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6128);
#ifdef SKIP_ASM
struct sQTVt6128 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sQTVtI6128 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sQTEnt6128 {
    int f0;                     // 0x00 (self + 0x1A4)
    int f4;                     // 0x04
    int f8;                     // 0x08
    char padC[0x52 - 0xC];
    char name[0x78 - 0x52];     // 0x52 (self + 0x1F6)
};

struct sQT6128 {
    sQTVt6128* vt;              // 0x000
    char pad4[0x1A0];
    sQTEnt6128 ents[1];         // 0x1A4
};

extern char D_00486490[];
extern char D_004864A0[];
extern char D_004864B8[];
extern char D_004864D0[];

static inline unsigned short* qtLoc6128(char* key)
{
    char* obj = *(char**)(D_004A28A8 + 0x8C);
    func_002C53E0_sVEntry* vt = *(func_002C53E0_sVEntry**)(obj + 4);
    char* thisp = obj + vt[4].delta;
    return vt[4].fn(thisp, GetHashValue32(key));
}

extern "C" void func_002C6128(sQT6128* self, int i, unsigned short* dst)
{
    unsigned short buf[64];
    if (self->vt[53].fn((char*)self + self->vt[53].delta) == 0) {
        func_002C2508(buf, qtLoc6128(D_00486490));
    } else if (self->vt[55].fn((char*)self + self->vt[55].delta) == 0) {
        func_002C2508(buf, qtLoc6128(D_004864A0));
    } else if (self->ents[i].f0 != 0 || self->ents[i].f4 != 0) {
        func_002C2508(buf, qtLoc6128(D_004864B8));
    } else if (self->ents[i].f8 != 0) {
        func_002C2508(buf, qtLoc6128(D_004864D0));
    } else if (((sQTVtI6128*)self->vt)[67].fn((char*)self + self->vt[67].delta, i) == 0) {
        func_002C2508(buf, qtLoc6128(D_00486490));
    } else {
        func_002C2540(buf, self->ents[i].name);
    }
    buf[32] = 0;
    func_002C2508(dst, buf);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6280);
#ifdef SKIP_ASM
class func_002C6280_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
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
    virtual int v20();
    virtual void v21();
    virtual int v22(int a);
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual int v67(int i);
};

struct func_002C6280_sElem {
    int flag;
    char pad[0x74];
};

struct func_002C6280_sData {
    char pad[0x1AC];
    func_002C6280_sElem elems[1];
};

extern "C" void func_002C6280(func_002C6280_cObj* self)
{
    int i = 0;
    int remain = self->v20();
    int unit = self->v22(*(int*)((char*)self + 0x24));
    for (; i < *(int*)((char*)self + 0x14); i++) {
        ((func_002C6280_sData*)self)->elems[i].flag = 0;
        if (self->v67(i) == 0) {
            if (remain >= unit) {
                remain -= unit;
            } else {
                ((func_002C6280_sData*)self)->elems[i].flag = 1;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6360);
#ifdef SKIP_ASM
extern "C" void func_0040A360(int a0, int a1, int* out);
extern "C" void func_002C5278(void* self);
extern int D_004A3940;

extern "C" void func_002C6360(void* p)
{
    sQTState* self = (sQTState*)p;
    if (*(int*)((char*)self + 0x40) != 0) {
        D_004A3940 = 0;
        func_0040A360(0, 0, &D_004A3940);
        if (D_004A3940 == -1) {
            self->levels[self->level].f10 = 1;
        }
    }
    *(int*)((char*)self + 0x40) = 0;
    self->level = 0;
    *(int*)((char*)self + 0x17C) = 0;
    *(int*)((char*)self + 0x180) = 0;
    *(int*)((char*)self + 0x184) = 0;
    *(int*)((char*)self + 0x188) = 0;
    *(int*)((char*)self + 0x3C) = 0;
    func_002C5278(self);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C63E8);
#ifdef SKIP_ASM
extern "C" int func_002C63E8(void* self, unsigned int a1)
{
    return a1 + 0x270f < 0x2706;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C63F8);
#ifdef SKIP_ASM
int GetHashValue32(char*);
extern "C" unsigned short* func_002C2540(unsigned short* dst, char* src);
extern "C" int func_002C26D0(unsigned short* dst, const unsigned short* fmt, ...);
// PORT: void view of func_002C26D0 (defined returning int); this caller treats it as void.
extern "C" void func_002C26D0_v(unsigned short* dst, const unsigned short* fmt, ...) __asm__("func_002C26D0");
extern char D_004A3970[];
extern char D_004864E8[];
extern char* D_004A28A8;

struct func_002C63F8_sVEntry {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

extern "C" void func_002C63F8(void* self, int n, unsigned short* dst)
{
    unsigned short fmt[8];
    unsigned short num[8];
    func_002C2540(fmt, D_004A3970);
    func_002C26D0_v(num, fmt, n + 1);
    if (n < 2) {
        if (n >= 0) {
            char* obj = *(char**)(D_004A28A8 + 0x8C);
            func_002C63F8_sVEntry* vt = *(func_002C63F8_sVEntry**)(obj + 4);
            char* thisp = obj + vt[4].delta;
            func_002C26D0(dst, vt[4].fn(thisp, GetHashValue32(D_004864E8)), num);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C64A8);
#ifdef SKIP_ASM
extern char D_004A3968[];

extern "C" void func_002C64A8(void* self, int a1, unsigned short* dst)
{
    func_002C2540(dst, D_004A3968);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/quadtree", func_002C64D0);
#ifdef SKIP_ASM
extern char D_004A3968[];

extern "C" void func_002C64D0(void* self, int a1, unsigned short* dst)
{
    func_002C2540(dst, D_004A3968);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C64F8);
#ifdef SKIP_ASM
struct sSaveSlot_2C64F8 {
    int busy;               // 0x00
    int locked;             // 0x04
    int bad;                // 0x08
    char pad0C[0x63];
    unsigned char sec;      // 0x6F
    unsigned char min;      // 0x70
    unsigned char hour;     // 0x71
    unsigned char day;      // 0x72
    unsigned char month;    // 0x73
    unsigned short year;    // 0x74
    char pad76[0x2];
};
struct sSaveMgrBase_2C64F8 {
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual int v67(int slot);
};
struct sSaveMgr_2C64F8 : sSaveMgrBase_2C64F8 {
    char pad4[0x1A0];
    sSaveSlot_2C64F8 slots[6];  // 0x1A4
};

extern "C" int func_002C64F8(sSaveMgr_2C64F8* self)
{
    int best = -1;
    if (self->v55() == 0) {
        return -1;
    }
    for (int i = 0; i < 6; i++) {
        if (self->slots[i].busy == 0 && self->slots[i].locked == 0 && self->v67(i) != 0 && self->slots[i].bad == 0) {
            if (best != -1) {
                unsigned int ct = self->slots[i].hour * 3600 + self->slots[i].min * 60 + self->slots[best].sec;
                unsigned short cy = self->slots[i].year;
                unsigned char cd = self->slots[i].day;
                unsigned int bt = self->slots[best].hour * 3600 + self->slots[best].min * 60 + self->slots[best].sec;
                unsigned short by = self->slots[best].year;
                unsigned char bm = self->slots[best].month;
                unsigned char bd = self->slots[best].day;
                unsigned char cm = self->slots[i].month;
                if (cy < by) {
                } else if (by < cy) {
                    best = i;
                } else if (cm < bm) {
                } else if (bm < cm) {
                    best = i;
                } else if (cd < bd) {
                } else if (bd < cd) {
                    best = i;
                } else if (ct < bt) {
                } else if (bt < ct) {
                    best = i;
                }
            } else {
                best = i;
            }
        }
    }
    return best;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C66B8);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);

extern "C" void func_002C66B8(void* self, const char* name, int flag)
{
    if (flag == 0) {
        strcpy((char*)self + 0x14C0, name);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C66D8);
#ifdef SKIP_ASM
extern "C" int func_002C66D8(void* self)
{
    char* p = (char*)self + *(int*)((char*)self + 0xc) * 0x14;
    return *(int*)(p + 0x184) == -0xb;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6700__FPv);
#ifdef SKIP_ASM
int func_002C6700(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6708__FPv);
#ifdef SKIP_ASM
int func_002C6708(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6710__FPv);
#ifdef SKIP_ASM
int func_002C6710(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6718);
#ifdef SKIP_ASM
#define QT_V10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
    virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

class cQuadTreeVObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8 (delta at +0, function at +4)
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    QT_V10(v1)
    virtual void v20(); virtual void v21();
    virtual int v22(int a); // 0xB0
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    QT_V10(v3) QT_V10(v4)
    virtual int v50(int a); // 0x190
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual int v61(int a); // 0x1E8
};

extern "C" void func_002C6718(cQuadTreeVObj* self)
{
    self->v61(*(int*)((char*)self + 0xC));
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6748__FPv);
#ifdef SKIP_ASM
int func_002C6748(void* self)
{
    return 0x4000;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6750__FPv);
#ifdef SKIP_ASM
int func_002C6750(void* self)
{
    return -0x1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6758);
#ifdef SKIP_ASM
extern "C" int func_002C6758(void* self, int a1)
{
    return (a1 + 0x3ff) / 0x400 + 0x4d;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6778);
#ifdef SKIP_ASM
#define QT_V10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
    virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

extern "C" void func_002C6778(cQuadTreeVObj* self)
{
    self->v22(*(int*)((char*)self + 0x24));
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C67A8__FPv);
#ifdef SKIP_ASM
int func_002C67A8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C67B0);
#ifdef SKIP_ASM
#define QT_V10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
    virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

extern "C" void func_002C67B0(cQuadTreeVObj* self)
{
    self->v50(*(int*)((char*)self + 0xC));
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C67E0__FPv);
#ifdef SKIP_ASM
int func_002C67E0(void* self)
{
    return -0x1;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C67E8__FPvi);
#ifdef SKIP_ASM
void* func_002C67E8(void* self, int a1)
{
    *(int*)((char*)self + 0xc) = a1;
    *(int*)((char*)self + 0x10) = a1;
    return func_002C48C0(self, 3);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6810);
#ifdef SKIP_ASM
extern "C" void func_002C6810(void* self, const char* name)
{
    *(int*)((char*)self + 0x54) = 0;
    strcpy((char*)self + 0x139, name);
    func_002C48C0(self, 0x3C);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6848);
#ifdef SKIP_ASM
extern "C" int func_0040A688(int h, int a1, char* name, int a3, int a4, void* buf);
extern int D_004A3940;
extern "C" void* func_003E6448(void* dst, int c, int n);

extern "C" void func_002C6848(void* self)
{
    char* buf = (char*)self + 0x4C0;
    func_003E6448(buf, 0, 0x1000);
    int r = func_0040A688(*(int*)((char*)self + 0xC), 0, (char*)self + 0x139, 0, 0x40, buf);
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x3D);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C68C8);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);

extern "C" void func_002C68C8(void* self, int i, char* dst)
{
    // PORT: (int)self pointer arithmetic (index added first, as in the target).
    strcpy(dst, (char*)((i << 6) + (int)self) + 0x4E0);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C68F0);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

struct func_002C68F0_sName {
    char name[0x78];
};

struct func_002C68F0_sTree {
    char pad_0x00[0x14];
    int count;                          // 0x14
    char pad_0x18[0x1B0 - 0x18];
    func_002C68F0_sName names[1];       // 0x1B0
};

extern "C" int func_002C68F0(func_002C68F0_sTree* self)
{
    int n = 0;
    int i;
    for (i = 0; i < self->count; i++) {
        if (strlen(self->names[i].name) != 0) {
            n++;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6968);
#ifdef SKIP_ASM
extern "C" void func_002C6968(void* self, const char* name, int a2)
{
    *(int*)((char*)self + 0x14E0) = a2;
    strcpy((char*)self + 0xF9, name);
    func_002C48C0(self, 0x3F);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C69A0);
#ifdef SKIP_ASM
extern "C" int func_00409D10(int h, int a1, char* name, int a3);
extern int D_004A3940;

extern "C" void func_002C69A0(void* self)
{
    *(int*)((char*)self + 0x18) = -1;
    int r = func_00409D10(*(int*)((char*)self + 0xC), 0, (char*)self + 0xF9, *(int*)((char*)self + 0x14E0));
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x40);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6A08__FPv);
#ifdef SKIP_ASM
void* func_002C6A08(void* self)
{
    return func_002C48C0(self, 0x49);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6A28);
#ifdef SKIP_ASM
// PORT: the unit declares func_002C48C0 as returning void*, but its body returns
// nothing (v0 is leftover); this caller needs the void prototype.
extern "C" void func_002C48C0_v(void* self, int state) __asm__("func_002C48C0");
extern "C" int func_00409E70(int h);
extern int D_004A3940;

extern "C" void func_002C6A28(void* self)
{
    D_004A3940 = func_00409E70(*(int*)((char*)self + 0x18));
    func_002C48C0_v(self, 0x4A);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6A60__FPvii);
#ifdef SKIP_ASM
void* func_002C6A60(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x14e4) = a1;
    *(int*)((char*)self + 0x14e8) = a2;
    return func_002C48C0(self, 0x41);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6A88);
#ifdef SKIP_ASM
extern "C" int func_00409F28(int h, int a1, int a2);
extern int D_004A3940;

extern "C" void func_002C6A88(void* self)
{
    int r = func_00409F28(*(int*)((char*)self + 0x18), *(int*)((char*)self + 0x14E4), *(int*)((char*)self + 0x14E8));
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x42);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6AE0__FPv);
#ifdef SKIP_ASM
void* func_002C6AE0(void* self)
{
    return func_002C48C0(self, 0x47);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6B00);
#ifdef SKIP_ASM
extern "C" int func_0040AB80(int h);
extern int D_004A3940;

extern "C" void func_002C6B00(void* self)
{
    int r = func_0040AB80(*(int*)((char*)self + 0x18));
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x48);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6B50__FPvii);
#ifdef SKIP_ASM
void* func_002C6B50(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x2c) = a1;
    *(int*)((char*)self + 0x24) = a2;
    return func_002C48C0(self, 0x43);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6B78);
#ifdef SKIP_ASM
extern "C" int func_0040A090(int h, int a1, int a2);
extern int D_004A3940;

extern "C" void func_002C6B78(void* self)
{
    int r = func_0040A090(*(int*)((char*)self + 0x18), *(int*)((char*)self + 0x2C), *(int*)((char*)self + 0x24));
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x44);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6BD0__FPvii);
#ifdef SKIP_ASM
void* func_002C6BD0(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0x2c) = a1;
    *(int*)((char*)self + 0x24) = a2;
    return func_002C48C0(self, 0x45);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6BF8);
#ifdef SKIP_ASM
extern "C" int func_0040A1A8(int h, int a1, int a2);
extern int D_004A3940;

extern "C" void func_002C6BF8(void* self)
{
    int r = func_0040A1A8(*(int*)((char*)self + 0x18), *(int*)((char*)self + 0x2C), *(int*)((char*)self + 0x24));
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x46);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6C50);
#ifdef SKIP_ASM
extern "C" void func_002C6C50(void* self, const char* name, int a2)
{
    *(int*)((char*)self + 0x20) = a2;
    strcpy((char*)self + 0xF9, name);
    func_002C48C0(self, 0x4B);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6C88);
#ifdef SKIP_ASM
extern "C" int func_00409E38(int h, int a1, char* name);
extern int D_004A3940;

extern "C" void func_002C6C88(void* self)
{
    int r = func_00409E38(*(int*)((char*)self + 0xC), 0, (char*)self + 0xF9);
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x4C);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6CE0);
#ifdef SKIP_ASM
extern "C" void func_002C6CE0(void* self, const char* name)
{
    strcpy((char*)self + 0xF9, name);
    func_002C48C0(self, 0x4D);
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6D18);
#ifdef SKIP_ASM
extern "C" int func_0040AA68(int h, int a1, char* name);
extern int D_004A3940;

extern "C" void func_002C6D18(void* self)
{
    int r = func_0040AA68(*(int*)((char*)self + 0xC), 0, (char*)self + 0xF9);
    D_004A3940 = r;
    if (r < 0) {
        func_002C48C0(self, 1);
    } else {
        func_002C48C0(self, 0x4E);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6D70);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_002523A8(void* p);

extern "C" void func_002C6D70(void* self, int flags)
{
    void* p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        func_002523A8(p);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_003DBB68(int);

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6DC0__FPv);
#ifdef SKIP_ASM
void* func_002C6DC0(void* self)
{
    return func_003DBB68(*(int*)((char*)self + 0x4));
}
#endif

//100%
INCLUDE_ASM("worldpainter/quadtree", func_002C6DE0);
#ifdef SKIP_ASM
struct func_002C6DE0_sEntry {
    unsigned int key;
    int value;
};

struct func_002C6DE0_sMap {
    int pad0;
    int pad4;
    int last;
    int count;
    func_002C6DE0_sEntry* entries;
};

extern "C" int func_002C6DE0(func_002C6DE0_sMap* self, unsigned int key)
{
    int lo = 0;
    int hi = self->last;
    if (self->count != 0) {
        if (self->entries[hi].key < key || key < self->entries[0].key) {
            return 0;
        }
        int mid = hi >> 1;
        while (self->entries[mid].key != key) {
            if (key < self->entries[mid].key) {
                hi = mid;
            } else {
                lo = mid;
            }
            int next = ((hi - lo) >> 1) + lo;
            if (next == mid) {
                return 0;
            }
            mid = next;
        }
        return self->entries[mid].value;
    }
    return 0;
}
#endif

INCLUDE_ASM("worldpainter/quadtree", func_002C6E98);

