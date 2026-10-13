#include "md5.h"

struct md5_ctx {
    unsigned int lo; // 0x0
    unsigned int hi; // 0x4
    unsigned int a; // 0x8
    unsigned int b; // 0xC
    unsigned int c; // 0x10
    unsigned int d; // 0x14
};

//100%
INCLUDE_ASM("md5", md5_process);
#ifdef SKIP_ASM
// The reference md5.c (L. Peter Deutsch) transform, little-endian path.
struct md5_state_process {
    unsigned int count[2];
    unsigned int abcd[4];
    unsigned char buf[64];
};

#define T_MASK ((unsigned int)~0)
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define F(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | ~(z)))

extern "C" void md5_process(md5_ctx* ctx, const unsigned char* data)
{
    md5_state_process* pms = (md5_state_process*)ctx;
    unsigned int a = pms->abcd[0], b = pms->abcd[1], c = pms->abcd[2], d = pms->abcd[3];
    unsigned int t;
    unsigned int xbuf[16];
    const unsigned int* X;

    if (!((data - (const unsigned char*)0) & 3)) {
        X = (const unsigned int*)data;
    } else {
        __builtin_memcpy(xbuf, data, 64);
        X = xbuf;
    }

#define SET(a, b, c, d, k, s, Ti) \
    t = a + F(b, c, d) + X[k] + Ti; \
    a = ROTATE_LEFT(t, s) + b
    SET(a, b, c, d, 0, 7, 0xd76aa478);
    SET(d, a, b, c, 1, 12, 0xe8c7b756);
    SET(c, d, a, b, 2, 17, 0x242070db);
    SET(b, c, d, a, 3, 22, 0xc1bdceee);
    SET(a, b, c, d, 4, 7, 0xf57c0faf);
    SET(d, a, b, c, 5, 12, 0x4787c62a);
    SET(c, d, a, b, 6, 17, 0xa8304613);
    SET(b, c, d, a, 7, 22, 0xfd469501);
    SET(a, b, c, d, 8, 7, 0x698098d8);
    SET(d, a, b, c, 9, 12, 0x8b44f7af);
    SET(c, d, a, b, 10, 17, 0xffff5bb1);
    SET(b, c, d, a, 11, 22, 0x895cd7be);
    SET(a, b, c, d, 12, 7, 0x6b901122);
    SET(d, a, b, c, 13, 12, 0xfd987193);
    SET(c, d, a, b, 14, 17, 0xa679438e);
    SET(b, c, d, a, 15, 22, 0x49b40821);
#undef SET

#define SET(a, b, c, d, k, s, Ti) \
    t = a + G(b, c, d) + X[k] + Ti; \
    a = ROTATE_LEFT(t, s) + b
    SET(a, b, c, d, 1, 5, 0xf61e2562);
    SET(d, a, b, c, 6, 9, 0xc040b340);
    SET(c, d, a, b, 11, 14, 0x265e5a51);
    SET(b, c, d, a, 0, 20, 0xe9b6c7aa);
    SET(a, b, c, d, 5, 5, 0xd62f105d);
    SET(d, a, b, c, 10, 9, 0x02441453);
    SET(c, d, a, b, 15, 14, 0xd8a1e681);
    SET(b, c, d, a, 4, 20, 0xe7d3fbc8);
    SET(a, b, c, d, 9, 5, 0x21e1cde6);
    SET(d, a, b, c, 14, 9, 0xc33707d6);
    SET(c, d, a, b, 3, 14, 0xf4d50d87);
    SET(b, c, d, a, 8, 20, 0x455a14ed);
    SET(a, b, c, d, 13, 5, 0xa9e3e905);
    SET(d, a, b, c, 2, 9, 0xfcefa3f8);
    SET(c, d, a, b, 7, 14, 0x676f02d9);
    SET(b, c, d, a, 12, 20, 0x8d2a4c8a);
#undef SET

#define SET(a, b, c, d, k, s, Ti) \
    t = a + H(b, c, d) + X[k] + Ti; \
    a = ROTATE_LEFT(t, s) + b
    SET(a, b, c, d, 5, 4, 0xfffa3942);
    SET(d, a, b, c, 8, 11, 0x8771f681);
    SET(c, d, a, b, 11, 16, 0x6d9d6122);
    SET(b, c, d, a, 14, 23, 0xfde5380c);
    SET(a, b, c, d, 1, 4, 0xa4beea44);
    SET(d, a, b, c, 4, 11, 0x4bdecfa9);
    SET(c, d, a, b, 7, 16, 0xf6bb4b60);
    SET(b, c, d, a, 10, 23, 0xbebfbc70);
    SET(a, b, c, d, 13, 4, 0x289b7ec6);
    SET(d, a, b, c, 0, 11, 0xeaa127fa);
    SET(c, d, a, b, 3, 16, 0xd4ef3085);
    SET(b, c, d, a, 6, 23, 0x04881d05);
    SET(a, b, c, d, 9, 4, 0xd9d4d039);
    SET(d, a, b, c, 12, 11, 0xe6db99e5);
    SET(c, d, a, b, 15, 16, 0x1fa27cf8);
    SET(b, c, d, a, 2, 23, 0xc4ac5665);
#undef SET

#define SET(a, b, c, d, k, s, Ti) \
    t = a + I(b, c, d) + X[k] + Ti; \
    a = ROTATE_LEFT(t, s) + b
    SET(a, b, c, d, 0, 6, 0xf4292244);
    SET(d, a, b, c, 7, 10, 0x432aff97);
    SET(c, d, a, b, 14, 15, 0xab9423a7);
    SET(b, c, d, a, 5, 21, 0xfc93a039);
    SET(a, b, c, d, 12, 6, 0x655b59c3);
    SET(d, a, b, c, 3, 10, 0x8f0ccc92);
    SET(c, d, a, b, 10, 15, 0xffeff47d);
    SET(b, c, d, a, 1, 21, 0x85845dd1);
    SET(a, b, c, d, 8, 6, 0x6fa87e4f);
    SET(d, a, b, c, 15, 10, 0xfe2ce6e0);
    SET(c, d, a, b, 6, 15, 0xa3014314);
    SET(b, c, d, a, 13, 21, 0x4e0811a1);
    SET(a, b, c, d, 4, 6, 0xf7537e82);
    SET(d, a, b, c, 11, 10, 0xbd3af235);
    SET(c, d, a, b, 2, 15, 0x2ad7d2bb);
    SET(b, c, d, a, 9, 21, 0xeb86d391);
#undef SET

    pms->abcd[0] += a;
    pms->abcd[1] += b;
    pms->abcd[2] += c;
    pms->abcd[3] += d;
}
#endif
#ifdef SKIP_ASM
#endif

//100%
INCLUDE_ASM("md5", md5_init__FP7md5_ctx);
#ifdef SKIP_ASM
void md5_init(md5_ctx* ctx)
{
    unsigned int a = 0x67452301;
    unsigned int b = 0xEFCDAB89;
    unsigned int c = 0x98BADCFE;
    unsigned int d = 0x10325476;
    ctx->a = a;
    ctx->d = d;
    ctx->b = b;
    ctx->c = c;
    ctx->lo = 0;
    ctx->hi = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("md5", md5_append);
#ifdef SKIP_ASM
extern "C" void* func_0041605C(void* dst, const void* src, int n);
extern "C" void md5_process(md5_ctx* ctx, const unsigned char* data);

// Same layout as md5_ctx, viewed as the reference md5.c's md5_state_t.
struct md5_state_append {
    unsigned int count[2];
    unsigned int abcd[4];
    unsigned char buf[64];
};

extern "C" void md5_append(md5_ctx* ctx, const unsigned char* data, int nbytes)
{
    md5_state_append* pms = (md5_state_append*)ctx;
    const unsigned char* p = data;
    int left = nbytes;
    int offset = (pms->count[0] >> 3) & 63;
    unsigned int nbits = (unsigned int)(nbytes << 3);

    if (nbytes <= 0) {
        return;
    }

    pms->count[1] += nbytes >> 29;
    pms->count[0] += nbits;
    if (pms->count[0] < nbits) {
        pms->count[1]++;
    }

    if (offset) {
        int copy = (offset + nbytes > 64 ? 64 - offset : nbytes);

        // PORT: pointer-in-int; the target adds offset to the state pointer before the buf offset (pms->buf + offset)
        func_0041605C((unsigned char*)(offset + (int)pms) + 0x18, p, copy);
        if (offset + copy < 64) {
            return;
        }
        p += copy;
        left -= copy;
        md5_process(ctx, pms->buf);
    }

    for (; left >= 64; p += 64, left -= 64) {
        md5_process(ctx, p);
    }

    if (left) {
        func_0041605C(pms->buf, p, left);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("md5", md5_finish);
#ifdef SKIP_ASM
// Same layout as md5_ctx, viewed as the reference md5.c's md5_state_t (count[2], abcd[4]).
struct md5_state_K4 {
    unsigned int count[2];  // 0x0
    unsigned int abcd[4];   // 0x8
};

extern "C" void md5_append(md5_ctx* ctx, const unsigned char* data, int nbytes);
extern unsigned char D_0048DAF8[];

extern "C" void md5_finish(md5_ctx* ctx, unsigned char* digest)
{
    md5_state_K4* pms = (md5_state_K4*)ctx;
    unsigned char data[8];
    int i;

    for (i = 0; i < 8; ++i) {
        data[i] = (unsigned char)(pms->count[i >> 2] >> ((i & 3) << 3));
    }
    md5_append(ctx, D_0048DAF8, ((55 - (pms->count[0] >> 3)) & 63) + 1);
    md5_append(ctx, data, 8);
    for (i = 0; i < 16; ++i) {
        digest[i] = (unsigned char)(pms->abcd[i >> 2] >> ((i & 3) << 3));
    }
}
#endif
#ifdef SKIP_ASM
#endif