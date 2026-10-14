#include "common.h"

//100%
INCLUDE_ASM("seg/seg_1C9348", HUFF_about);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, int flags, int align) __asm__("cMemMan_alloc");
extern "C" void* func_00416210(void* dst, int c, unsigned int n);
extern char D_004865C8[];
extern char D_004865D8[] __attribute__((aligned(8)));
extern char D_004A3980[] __attribute__((aligned(8)));
extern char D_004A3988[] __attribute__((aligned(8)));
extern char D_004A3990[] __attribute__((aligned(8)));
extern char D_004865F0[] __attribute__((aligned(8)));

// EA codex "about" block describing the Huffman/RLE codec.
struct sCodexAbout_HUFF {
    int signature;                  // 0x0
    int size;                       // 0x4
    int version;                    // 0x8
    unsigned int b0 : 1;            // 0xC
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int pad : 27;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    char author[32];                // 0x24
    char versionstr[8];             // 0x44
    char shorttypestr[8];           // 0x4C
    char longtypestr[16];           // 0x54
    char desc[32];                  // 0x64
};

extern "C" void* HUFF_about(void)
{
    sCodexAbout_HUFF* a = (sCodexAbout_HUFF*)operator new(0x84, D_004865C8, 0x20000000, 0);
    if (a != 0) {
        func_00416210(a, 0, 0x84);
        a->signature = 'HUFF';
        a->size = 0x84;
        a->version = 100;
        a->b0 = 1;
        a->b1 = 1;
        a->b2 = 1;
        a->b3 = 1;
        a->b4 = 0;
        a->f14 = 0;
        a->f18 = 0;
        a->f1C = 1;
        a->f20 = 0;
        __builtin_memcpy(a->author, D_004865D8, 18);
        __builtin_memcpy(a->versionstr, D_004A3980, 5);
        __builtin_memcpy(a->shorttypestr, D_004A3988, 4);
        __builtin_memcpy(a->longtypestr, D_004A3990, 8);
        __builtin_memcpy(a->desc, D_004865F0, 12);
    }
    return a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C8468);
#ifdef SKIP_ASM
extern "C" unsigned func_002C8468(unsigned char *p, int n) {
    unsigned r = 0;
    while (n--) {
        r = (r << 8) + *p++;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C84A0);
#ifdef SKIP_ASM
extern "C" unsigned func_002C8468(unsigned char *p, int n);

extern "C" int func_002C84A0(unsigned char *p) {
    int r = 0;
    if (func_002C8468(p, 2) == 0x30FB
        || func_002C8468(p, 2) == 0x31FB
        || func_002C8468(p, 2) == 0x32FB
        || func_002C8468(p, 2) == 0x33FB
        || func_002C8468(p, 2) == 0x34FB
        || func_002C8468(p, 2) == 0x35FB) {
        r = 100;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C8550);
#ifdef SKIP_ASM
extern "C" unsigned func_002C8468(unsigned char *p, int n);

extern "C" void func_002C8550(unsigned char *p) {
    if (func_002C8468(p, 2) & 0x100) {
        func_002C8468(p + 5, 3);
    } else {
        func_002C8468(p + 2, 3);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C85A0);
#ifdef SKIP_ASM
extern "C" int func_002C76C0(int, int);

extern "C" int func_002C85A0(int a, int b, int c) {
    return func_002C76C0(a, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C85C0);
#ifdef SKIP_ASM
extern "C" void func_002C85C0(unsigned char *src, unsigned char *dst, int n) {
    unsigned char *end = src + n;
    int prev = 0;
    if (src < end) {
        do {
            int c = *src++;
            *dst++ = c - prev;
            prev = c;
        } while (src < end);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C8600);
#ifdef SKIP_ASM
struct HuffOut_8600 {
    unsigned char* buf;
    int pos;
};

struct HuffState_8600 {
    char pad0[0x2D64];
    unsigned int mask[17];   // 0x2D64
    unsigned int bitcount;   // 0x2DA8
    unsigned int bitbuf;     // 0x2DAC
    char pad2DB0[0x2DE4 - 0x2DB0];
    int nbytes;              // 0x2DE4
};

// PORT: the unit declares this with other parameter types; defined under an asm label
extern "C" void func_002C8600_impl(HuffState_8600* s, HuffOut_8600* out, unsigned int code, unsigned int len) __asm__("func_002C8600");
extern "C" void func_002C8600_impl(HuffState_8600* s, HuffOut_8600* out, unsigned int code, unsigned int len)
{
    if (len > 16) {
        func_002C8600_impl(s, out, code >> 16, len - 16);
        func_002C8600_impl(s, out, code, 16);
        return;
    }
    s->bitcount += len;
    s->bitbuf += (code & s->mask[len]) << (24 - s->bitcount);
    while (s->bitcount >= 8) {
        out->buf[out->pos] = (unsigned char)(s->bitbuf >> 16);
        out->pos++;
        s->bitbuf <<= 8;
        s->bitcount -= 8;
        s->nbytes++;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C86F8);
#ifdef SKIP_ASM
struct HS_86F8 { char pad[0x1524]; int l[0x208]; int r[0x208]; int a[256]; };
extern "C" void func_002C86F8(HS_86F8 *self, unsigned i, int d) {
    if (i < 0x100) {
        self->a[i] = d;
        return;
    }
    func_002C86F8(self, self->l[i], d + 1);
    func_002C86F8(self, self->r[i], d + 1);
}
#endif

INCLUDE_ASM("seg/seg_1C9348", func_002C8770);

INCLUDE_ASM("seg/seg_1C9348", func_002C8970);

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C8A78);
#ifdef SKIP_ASM
struct HuffState_8A78 {
    char pad0[0xD44];
    unsigned int len[252];      // 0xD44
    unsigned int base[252];     // 0x1134
};

struct HuffOut_8A78;

extern "C" void func_002C8600_8A78(HuffState_8A78* s, HuffOut_8A78* out, unsigned int code, unsigned int len) __asm__("func_002C8600");

// PORT: the unit declares this with other parameter types; defined under an asm label
extern "C" void func_002C8A78_impl(HuffState_8A78* s, HuffOut_8A78* out, unsigned int v) __asm__("func_002C8A78");
extern "C" void func_002C8A78_impl(HuffState_8A78* s, HuffOut_8A78* out, unsigned int v)
{
    unsigned int base;
    unsigned int bits;
    if (v < 0xFC) {
        bits = s->len[v];
        base = s->base[v];
    } else if (v < 0x1FC) {
        bits = 6;
        base = 0xFC;
    } else if (v < 0x3FC) {
        bits = 7;
        base = 0x1FC;
    } else if (v < 0x7FC) {
        bits = 8;
        base = 0x3FC;
    } else if (v < 0xFFC) {
        bits = 9;
        base = 0x7FC;
    } else if (v < 0x1FFC) {
        bits = 10;
        base = 0xFFC;
    } else if (v < 0x3FFC) {
        bits = 11;
        base = 0x1FFC;
    } else if (v < 0x7FFC) {
        bits = 12;
        base = 0x3FFC;
    } else if (v < 0xFFFC) {
        bits = 13;
        base = 0x7FFC;
    } else if (v < 0x1FFFC) {
        bits = 14;
        base = 0xFFFC;
    } else if (v < 0x3FFFC) {
        bits = 15;
        base = 0x1FFFC;
    } else if (v < 0x80000) {
        bits = 16;
        base = 0x3FFFC;
    } else if (v < 0x100000) {
        bits = 17;
        base = 0x80000;
    } else {
        bits = 18;
        base = 0x100000;
    }
    func_002C8600_8A78(s, out, 1, bits + 1);
    func_002C8600_8A78(s, out, v - base, bits + 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1C9348", func_002C8C30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct HS_8C30 { char pad[0x2564]; int a[256]; int b[0x11A]; int cur; };
extern void func_002C8600_8C30(HS_8C30 *, int, int, int) __asm__("func_002C8600");
extern "C" void func_002C8A78(HS_8C30 *, int, int);

extern "C" void func_002C8C30_impl(HS_8C30 *self, int x, int y) __asm__("func_002C8C30");
extern "C" void func_002C8C30_impl(HS_8C30 *self, int x, int y) {
    func_002C8600_8C30(self, x, self->b[self->cur], self->a[self->cur]);
    func_002C8A78(self, x, 0);
    func_002C8600_8C30(self, x, y, 9);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1C9348", func_002C8CA8);
#ifdef SKIP_ASM
struct HS_8CA8 { char pad[0x2564]; int a[256]; int b[0x11A]; int cur; };
extern "C" void func_002C8600(HS_8CA8 *, int, int, int);
extern "C" void func_002C8C30(HS_8CA8 *, int, int);

extern "C" void func_002C8CA8(HS_8CA8 *self, int x, int idx) {
    if (idx == self->cur) {
        func_002C8C30(self, x, idx);
        return;
    }
    func_002C8600(self, x, self->b[idx], self->a[idx]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", func_002C8CF8);
#ifdef SKIP_ASM
struct HuffState_8CF8 {
    char pad0[0xD44];
    unsigned int len[252];      // 0xD44
    unsigned int base[252];     // 0x1134
};

extern "C" void func_002C8CF8(HuffState_8CF8* s)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        s->len[i] = 0;
        s->base[i] = 0;
    }
    for (; i < 12; i++) {
        s->len[i] = 1;
        s->base[i] = 4;
    }
    for (; i < 28; i++) {
        s->len[i] = 2;
        s->base[i] = 12;
    }
    for (; i < 60; i++) {
        s->len[i] = 3;
        s->base[i] = 28;
    }
    for (; i < 124; i++) {
        s->len[i] = 4;
        s->base[i] = 60;
    }
    for (; i < 252; i++) {
        s->len[i] = 5;
        s->base[i] = 124;
    }
}
#endif

INCLUDE_ASM("seg/seg_1C9348", func_002C8E48);

INCLUDE_ASM("seg/seg_1C9348", func_002C9A48);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1C9348", func_002C9F60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct HuffBuf_9F60 {
    char* buf;
    int len;
};

struct HuffState_9F60 {
    char pad0[0x2D64];
    unsigned int mask[17];      // 0x2D64
    unsigned int bitcount;      // 0x2DA8
    unsigned int bitbuf;        // 0x2DAC
    char* src;                  // 0x2DB0
    char* srcend;               // 0x2DB4
    int srclen;                 // 0x2DB8
    char pad2DBC[0x2DE4 - 0x2DBC];
    int nbytes;                 // 0x2DE4
    int remaining;              // 0x2DE8
};

extern "C" void func_002C8CF8_9F60(HuffState_9F60* s) __asm__("func_002C8CF8");
extern "C" void func_002C8600_9F60(HuffState_9F60* s, HuffBuf_9F60* out, unsigned int code, unsigned int len) __asm__("func_002C8600");
extern "C" void func_002C8E48(void* s, int a, int b);
extern "C" void func_002C9A48(void* s, void* out, int a);

extern "C" int func_002C9F60(HuffState_9F60* s, HuffBuf_9F60* in, HuffBuf_9F60* out, int len, int mode)
{
    unsigned int i;
    unsigned int code;
    s->bitcount = 0;
    s->bitbuf = 0;
    s->mask[0] = 0;
    for (i = 1; i < 17; i++) {
        s->mask[i] = s->mask[i - 1] * 2 + 1;
    }
    func_002C8CF8_9F60(s);
    s->src = in->buf;
    {
        int n = in->len;
        s->srclen = n;
        s->remaining = n;
        s->srcend = s->src + n;
    }
    out->len = 0;
    s->bitcount = 0;
    s->bitbuf = 0;
    s->nbytes = 0;
    func_002C8E48(s, 0x39, 0xF);
    if (len == in->len) {
        code = 0;
        if (mode == 0) code = 0x30FB;
        else if (mode == 1) code = 0x32FB;
        else if (mode == 2) code = 0x34FB;
        func_002C8600_9F60(s, out, code, 16);
        func_002C8600_9F60(s, out, in->len, 24);
    } else {
        code = 0;
        if (mode == 0) code = 0x31FB;
        else if (mode == 1) code = 0x33FB;
        else if (mode == 2) code = 0x35FB;
        func_002C8600_9F60(s, out, code, 16);
        func_002C8600_9F60(s, out, len, 24);
        func_002C8600_9F60(s, out, in->len, 24);
    }
    func_002C9A48(s, out, 0x39);
    return out->len;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1C9348", HUFF_encode);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* name, int flags, int align);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_002C85C0(unsigned char *src, unsigned char *dst, int n);
extern "C" int func_002C9F60_A100(void* s, void* in, void* out, int len, int mode) __asm__("func_002C9F60");
extern char D_00486600[];
extern char D_00486618[];

struct HuffBuf_A100 {
    void* buf;
    int len;
};

extern "C" int HUFF_encode(void* src, int len, void* dst, int* opts)
{
    void* tmp = 0;
    int mode = 0;
    int result = 0;
    void* s;
    if (opts) mode = *opts;
    s = cMemMan_alloc(0x31EC, D_00486600, 0x20000000, 0);
    if (s) {
        HuffBuf_A100 in;
        HuffBuf_A100 out;
        switch (mode) {
        case 1:
            tmp = operator_new_tag(len, D_00486618, 0x20000000, 0);
            func_002C85C0((unsigned char*)src, (unsigned char*)tmp, len);
            in.buf = tmp;
            break;
        case 2:
            tmp = operator_new_tag(len, D_00486618, 0x20000000, 0);
            func_002C85C0((unsigned char*)src, (unsigned char*)tmp, len);
            func_002C85C0((unsigned char*)tmp, (unsigned char*)tmp, len);
            in.buf = tmp;
            break;
        case 0:
        default:
            in.buf = src;
            break;
        }
        in.len = len;
        out.buf = dst;
        out.len = len;
        result = func_002C9F60_A100(s, &in, &out, len, mode);
        if (tmp) cMemMan_free(tmp);
        operator_delete((int*)s);
    }
    return result;
}
#endif
