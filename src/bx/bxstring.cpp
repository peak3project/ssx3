#include "common.h"

//100%
INCLUDE_ASM("bx/bxstring", cBXString_cBXString1);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" cBXString* cBXString_cBXString4(cBXString* self, const char* str);

// PORT: pointer held in int to get the target's negative header offsets.
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other)
{
    int s = *(int*)other;
    if (*(int*)(s - 0xC) >= 0)
    {
        *(int*)self = s;
        *(int*)(s - 0xC) = *(int*)(s - 0xC) + 1;
    }
    else
    {
        *(char**)self = D_004A3E90;
        cBXString_cBXString4(self, *(char**)other);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", cBXString_Realloc);
#ifdef SKIP_ASM
struct cBXString;
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label.
// Declared as an operator new so gcc treats the result as fresh (malloc-like) memory.
void* operator new(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_0048D850[];
extern char* D_004A3E90;

extern "C" void cBXString_Realloc(cBXString* self, int size)
{
    if (size == 0) {
        *(char**)self = D_004A3E90;
        return;
    }
    int* hdr = (int*)operator new(size + 0xD, D_0048D850, 0x20000000, 0);
    char* s = (char*)(hdr + 3);
    hdr[0] = 1;
    *(char**)self = s;
    s[size] = 0;
    hdr[1] = size;
    hdr[2] = size;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", cBXString_Reset);
#ifdef SKIP_ASM
struct cBXString;
extern char D_0048DCD4[];
extern char* D_004A3E90;
void cMemMan_free(void*);

// PORT: pointer held in int to get the target's negative header offsets.
extern "C" void cBXString_Reset(cBXString* self)
{
    int s = *(int*)self;
    if ((char*)s != D_0048DCD4)
    {
        int rc = *(int*)(s - 0xC) - 1;
        *(int*)(s - 0xC) = rc;
        if (rc == 0)
        {
            void* h = (void*)(*(int*)self - 0xC);
            if (h != 0)
                cMemMan_free(h);
        }
        *(char**)self = D_004A3E90;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", func_00318120);
#ifdef SKIP_ASM
struct cBXString;
extern "C" void cBXString_Reset(cBXString* self);
extern "C" void cBXString_Realloc(cBXString* self, int size);
extern "C" void* func_0041605C(void* dst, const void* src, int n);

// PORT: pointer held in int to get the target's negative load offsets.
extern "C" void func_00318120(cBXString* self)
{
    int old = *(int*)self;
    if (*(int*)(old - 0xC) >= 2)
    {
        cBXString_Reset(self);
        cBXString_Realloc(self, *(int*)(old - 8));
        func_0041605C(*(char**)self, (void*)old, *(int*)(old - 8) + 1);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", cBXString_Resize);
#ifdef SKIP_ASM
struct cBXString;
extern "C" void cBXString_Reset(cBXString* self);
extern "C" void cBXString_Realloc(cBXString* self, int size);

// PORT: pointer held in int to get the target's negative load offsets.
extern "C" void cBXString_Resize(cBXString* self, int size)
{
    int s = *(int*)self;
    if (*(int*)(s - 0xC) >= 2 || *(int*)(s - 4) < size)
    {
        cBXString_Reset(self);
        cBXString_Realloc(self, size);
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_003181E8);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" void cBXString_Realloc(cBXString* self, int size);
extern "C" void* func_0041605C(void* dst, const void* src, int n);

// Copies len chars of src starting at pos into dst, reserving extra more.
extern "C" void func_003181E8(cBXString* src, cBXString* dst, int len, int pos, int extra)
{
    int total = len + extra;
    if (total == 0)
    {
        *(char**)dst = D_004A3E90;
        return;
    }
    cBXString_Realloc(dst, total);
    func_0041605C(*(char**)dst, *(char**)src + pos, len);
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", cBXString__cBXString);
#ifdef SKIP_ASM
extern char D_0048DCD4[];
void cMemMan_free(void*);
void operator_delete(int*);

// PORT: pointer held in int to get the target's negative header offsets.
extern "C" void cBXString__cBXString(cBXString* self, int flags)
{
    int s = *(int*)self;
    if ((char*)s != D_0048DCD4)
    {
        int rc = *(int*)(s - 0xC) - 1;
        *(int*)(s - 0xC) = rc;
        if (rc <= 0)
        {
            void* h = (void*)(*(int*)self - 0xC);
            if (h != 0)
                cMemMan_free(h);
        }
    }
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", cBXString_cBXString2);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" unsigned int strlen(const char* s);
extern "C" void cBXString_Realloc(cBXString* self, int size);
extern "C" void* func_0041605C(void* dst, const void* src, int n);

extern "C" cBXString* cBXString_cBXString2(cBXString* self, const char* str)
{
    *(char**)self = D_004A3E90;
    int len;
    if (str != 0)
        len = strlen(str);
    else
        len = 0;
    if (len != 0)
    {
        cBXString_Realloc(self, len);
        func_0041605C(*(char**)self, str, len);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00318350);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" unsigned int strlen(const char* s);
extern "C" void cBXString_Realloc(cBXString* self, int size);
extern "C" void* func_0041605C(void* dst, const void* src, int n);

// cBXString(const char* str, int n): at most n chars of str.
extern "C" cBXString* func_00318350(cBXString* self, const char* str, int n)
{
    *(char**)self = D_004A3E90;
    if (n >= strlen(str))
        n = strlen(str);
    if (n != 0)
    {
        cBXString_Realloc(self, n);
        func_0041605C(*(char**)self, str, n);
    }
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", cBXString_InitFromCString);
#ifdef SKIP_ASM
extern char D_0048DCD4[];

// PORT: pointer held in int to get the target's negative store offset.
extern "C" void cBXString_InitFromCString(cBXString* self, int len, const char* str)
{
    cBXString_Resize(self, len);
    if (*(char**)self != D_0048DCD4)
    {
        func_0041605C(*(char**)self, str, len);
        *(int*)(*(int*)self - 8) = len;
        (*(char**)self)[len] = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", cBXString_operatorE);
#ifdef SKIP_ASM
extern char D_0048DCD4[];

// PORT: pointers held in int to get the target's negative header offsets
// (refcount at -0xC, length at -8).
extern "C" cBXString* cBXString_operatorE(cBXString* self, cBXString* other)
{
    if (*(char**)self != *(char**)other)
    {
        if ((*(int*)(*(int*)self - 0xC) < 0 && *(char**)self != D_0048DCD4) ||
            *(int*)(*(int*)other - 0xC) < 0)
        {
            cBXString_InitFromCString(self, *(int*)(*(int*)other - 8), *(char**)other);
        }
        else
        {
            cBXString_Reset(self);
            *(char**)self = *(char**)other;
            (*(int*)(*(int*)self - 0xC))++;
        }
    }
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", cBXString_cBXString4);
#ifdef SKIP_ASM
struct cBXString;
extern "C" unsigned int strlen(const char* s);
extern "C" void cBXString_InitFromCString(cBXString* self, int len, const char* str);

extern "C" cBXString* cBXString_cBXString4(cBXString* self, const char* str)
{
    int len;
    if (str != 0)
        len = strlen(str);
    else
        len = 0;
    cBXString_InitFromCString(self, len, str);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", func_00318540);
#ifdef SKIP_ASM
extern "C" void cBXString_Realloc(cBXString* self, int size);
extern "C" void* func_0041605C(void* dst, const void* src, int n);

// Builds the string from two pieces: (len1, s1) followed by (len2, s2).
extern "C" void func_00318540(cBXString* self, int len1, const char* s1, int len2, const char* s2)
{
    int total = len1 + len2;
    if (total != 0)
    {
        cBXString_Realloc(self, total);
        func_0041605C(*(char**)self, s1, len1);
        func_0041605C(*(char**)self + len1, s2, len2);
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_003185C8);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" void func_00318540(cBXString* self, int len1, const char* s1, int len2, const char* s2);
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other);
extern "C" void cBXString__cBXString(cBXString* self, int flags);

// cBXString(a + b). PORT: pointer held in int for the negative header offsets.
extern "C" cBXString* func_003185C8(cBXString* self, cBXString* a, cBXString* b)
{
    char* tmp = D_004A3E90;
    int sa = *(int*)a;
    int sb = *(int*)b;
    func_00318540((cBXString*)&tmp, *(int*)(sa - 8), (char*)sa, *(int*)(sb - 8), (char*)sb);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00318630);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" unsigned int strlen(const char* s);
extern "C" void func_00318540(cBXString* self, int len1, const char* s1, int len2, const char* s2);
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other);
extern "C" void cBXString__cBXString(cBXString* self, int flags);

// cBXString(a + str). PORT: pointer held in int for the negative header offsets.
extern "C" cBXString* func_00318630(cBXString* self, cBXString* a, const char* str)
{
    char* tmp = D_004A3E90;
    int* lenp = (int*)(*(int*)a - 8);
    int len;
    if (str != 0)
        len = strlen(str);
    else
        len = 0;
    func_00318540((cBXString*)&tmp, *lenp, *(char**)a, len, str);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_003186D0);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" unsigned int strlen(const char* s);
extern "C" void func_00318540(cBXString* self, int len1, const char* s1, int len2, const char* s2);
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other);
extern "C" void cBXString__cBXString(cBXString* self, int flags);

// cBXString(str + b). PORT: pointer held in int for the negative header offset.
extern "C" cBXString* func_003186D0(cBXString* self, const char* str, cBXString* b)
{
    char* tmp = D_004A3E90;
    int len;
    if (str != 0)
        len = strlen(str);
    else
        len = 0;
    int sb = *(int*)b;
    func_00318540((cBXString*)&tmp, len, str, *(int*)(sb - 8), (char*)sb);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00318760);
#ifdef SKIP_ASM
// local string temp: non-POD (user copy ctor) so it gets a 16-byte BLKmode stack slot
struct sBXTmp_318760 {
    char* p;
    sBXTmp_318760(char* s) : p(s) {}
    sBXTmp_318760(const sBXTmp_318760& o) : p(o.p) {}
};

// cBXString(a + ch). PORT: pointer held in int for the negative header offset.
extern "C" cBXString* func_00318760(cBXString* self, cBXString* a, char ch)
{
    sBXTmp_318760 tmp(D_004A3E90);
    char c = ch;
    int sa = *(int*)a;
    func_00318540((cBXString*)&tmp, *(int*)(sa - 8), (char*)sa, 1, &c);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_003187C8);
#ifdef SKIP_ASM
// local string temp: non-POD (user copy ctor) so it gets a 16-byte BLKmode stack slot
struct sBXTmp_3187C8 {
    char* p;
    sBXTmp_3187C8(char* s) : p(s) {}
    sBXTmp_3187C8(const sBXTmp_3187C8& o) : p(o.p) {}
};

// cBXString(ch + b). PORT: pointer held in int for the negative header offset.
extern "C" cBXString* func_003187C8(cBXString* self, char ch, cBXString* b)
{
    sBXTmp_3187C8 tmp(D_004A3E90);
    char c = ch;
    int sb = *(int*)b;
    func_00318540((cBXString*)&tmp, 1, &c, *(int*)(sb - 8), (char*)sb);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", cBXString_ConcatImpl);
#ifdef SKIP_ASM
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other);
extern "C" void cBXString_Reset(cBXString* self);
extern "C" void func_00318540(cBXString* self, int len1, const char* s1, int len2, const char* s2);
extern "C" void* func_0041605C(void* dst, const void* src, int n);

struct cBXStringHdrK2 {
    int ref; // -0xC
    int len; // -0x8
    int cap; // -0x4
};

// PORT: pointer held in int to get the target's negative header offsets.
extern "C" void cBXString_ConcatImpl(cBXString* self, int len, const char* str)
{
    int s = *(int*)self;
    cBXStringHdrK2* h = (cBXStringHdrK2*)(s - 0xC);
    if (*(int*)(s - 0xC) >= 2 || *(int*)(s - 4) < *(int*)(s - 8) + len)
    {
        char* tmp;
        cBXString_cBXString1((cBXString*)&tmp, self);
        int old = *(int*)self;
        cBXString_Reset(self);
        func_00318540(self, *(int*)(old - 8), (char*)old, len, str);
        cBXString__cBXString((cBXString*)&tmp, 2);
    }
    else
    {
        func_0041605C((char*)s + h->len, str, len);
        *(int*)(*(int*)self - 8) += len;
        (*(char**)self)[*(int*)(*(int*)self - 8)] = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", cBXString_Concat);
#ifdef SKIP_ASM
struct cBXString;
extern "C" unsigned int strlen(const char* s);
extern "C" void cBXString_ConcatImpl(cBXString* self, int len, const char* str);

extern "C" cBXString* cBXString_Concat(cBXString* self, const char* str)
{
    int len;
    if (str != 0)
        len = strlen(str);
    else
        len = 0;
    cBXString_ConcatImpl(self, len, str);
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00318968);
#ifdef SKIP_ASM
extern "C" cBXString* func_00318968(cBXString* self, char ch)
{
    char buf = ch;
    cBXString_ConcatImpl(self, 1, &buf);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", func_003189A0);
#ifdef SKIP_ASM
struct cBXString;
extern "C" void cBXString_ConcatImpl(cBXString* self, int len, const char* str);

// cBXString += cBXString; the length lives in the header 8 bytes before the chars.
extern "C" cBXString* func_003189A0(cBXString* self, char** other)
{
    cBXString_ConcatImpl(self, *(int*)(*other - 8), *other);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", func_003189D0);
#ifdef SKIP_ASM
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other);

// PORT: pointer held in int to get the target's negative header offsets.
extern "C" char* func_003189D0(cBXString* self, int size)
{
    int s = *(int*)self;
    if (*(int*)(s - 0xC) >= 2 || *(int*)(s - 4) < size)
    {
        char* tmp;
        cBXString_cBXString1((cBXString*)&tmp, self);
        int len = *(int*)((int)tmp - 8);
        cBXString_Reset(self);
        cBXString_Realloc(self, len < size ? size : len);
        func_0041605C(*(char**)self, tmp, len);
        *(int*)(*(int*)self - 8) = len;
        (*(char**)self)[len] = 0;
        cBXString__cBXString((cBXString*)&tmp, 2);
    }
    return *(char**)self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", func_00318A88);
#ifdef SKIP_ASM
extern char D_0048DCD4[];

// PORT: pointer held in int to get the target's negative store offset.
extern "C" void func_00318A88(cBXString* self, int len)
{
    func_00318120(self);
    if (len == -1)
        len = strlen(*(char**)self);
    if (*(char**)self != D_0048DCD4)
    {
        *(int*)(*(int*)self - 8) = len;
        (*(char**)self)[len] = 0;
    }
}
#endif

extern "C" char* strchr(char* str, int ch);

struct cBXString {
    char* str;
};

//100%
INCLUDE_ASM("bx/bxstring", func_00318AF8);
#ifdef SKIP_ASM
extern "C" char* func_00318AF8(cBXString* self, int len)
{
    func_003189D0(self, len);
    *(int*)(*(int*)self - 8) = len;
    self->str[len] = 0;
    return self->str;
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00318B40);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(cBXString* self, int flags);

// Make the string unique (copy-on-write detach) when its two header counts differ.
// PORT: pointer held in int for the negative header offsets.
extern "C" void func_00318B40(cBXString* self)
{
    int s = *(int*)self;
    if (*(int*)(s - 8) != *(int*)(s - 4)) {
        cBXString tmp;
        cBXString_cBXString1(&tmp, self);
        int len = *(int*)(*(int*)&tmp - 8);
        cBXString_Reset(self);
        cBXString_Realloc(self, len);
        func_0041605C(self->str, tmp.str, len);
        cBXString__cBXString(&tmp, 2);
    }
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00318BC0);
#ifdef SKIP_ASM
extern "C" char* func_00318BC0(cBXString* self)
{
    char* r = func_003189D0(self, 0);
    *(int*)(*(int*)self - 0xC) = -1;
    return r;
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00318BF8);
#ifdef SKIP_ASM
extern "C" void func_00318BF8(void **arg0) {
    void *temp_4;

    temp_4 = *arg0;
    if (temp_4 != &D_0048DCD4) {
        (*(int *)((char*)(temp_4) + (-0xC))) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", cBXString_FindLastOf__FP9cBXStringci);
#ifdef SKIP_ASM
int cBXString_FindLastOf(cBXString* self, char ch, int len)
{
    char* result = strchr(self->str + len, ch);
    if (result == 0) {
        return -1;
    }
    return result - self->str;
}
#endif

extern "C" char* func_0041ACC0(char* str, int ch);

//100%
INCLUDE_ASM("bx/bxstring", func_00318C60);
#ifdef SKIP_ASM
extern "C" int func_0041AC40(int);

extern "C" int func_00318C60(int *arg0) {
    int temp_2;

    temp_2 = func_0041AC40(*arg0);
    if (temp_2 == 0) {
        return -1;
    }
    return temp_2 - *arg0;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", cBXString_FindFirstOf__FP9cBXStringc);
#ifdef SKIP_ASM
int cBXString_FindFirstOf(cBXString* self, char ch)
{
    char* result = func_0041ACC0(self->str, ch);
    if (result == 0) {
        return -1;
    }
    return result - self->str;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00318CE8);
#ifdef SKIP_ASM
extern "C" char* func_0041AD80(char* str);

extern "C" int func_00318CE8(cBXString* self, int unused, int start)
{
    char* result = func_0041AD80(self->str + start);
    if (result == 0) {
        return -1;
    }
    return result - self->str;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", func_00318D28);
#ifdef SKIP_ASM
extern unsigned char D_00499C81[];
static inline int to_upper(int c) { if (D_00499C81[c] & 2) return c - 0x20; return c; }
// In-place upper-case; D_00499C81 is the ctype table (+1), bit 2 = lower-case.
// PORT: pointer held in int to get the target's negative load offset.
extern "C" void func_00318D28(cBXString* self)
{
    func_00318120(self);
    char* p = self->str;
    int i = *(int*)((int)p - 8);
    while (--i >= 0)
    {
        *p = to_upper(*p);
        p++;
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00318D90);
#ifdef SKIP_ASM
extern unsigned char D_00499C81[];
static inline int to_lower(int c) { if (D_00499C81[c] & 1) return c + 0x20; return c; }
// In-place lower-case; D_00499C81 is the ctype table (+1), bit 1 = upper-case.
// PORT: pointer held in int to get the target's negative load offset.
extern "C" void func_00318D90(cBXString* self)
{
    func_00318120(self);
    char* p = self->str;
    int i = *(int*)((int)p - 8);
    while (--i >= 0)
    {
        *p = to_lower(*p);
        p++;
    }
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00318DF8);
#ifdef SKIP_ASM
// Replace every `from` with `to` in place.
// PORT: pointer held in int to get the target's negative load offset.
extern "C" void func_00318DF8(cBXString* self, char from, char to)
{
    func_00318120(self);
    char* p = self->str;
    int i = *(int*)((int)p - 8);
    while (--i >= 0)
    {
        if (*p == from)
            *p = to;
        p++;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", func_00318E68);
#ifdef SKIP_ASM
extern "C" void func_00318120(cBXString* self);

extern "C" void func_00318E68(cBXString* self, int idx, char ch)
{
    func_00318120(self);
    self->str[idx] = ch;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00318EB8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void*, int, unsigned int);

// cBXString(ch, n): n copies of ch.
extern "C" cBXString* func_00318EB8(cBXString* self, char ch, int n)
{
    *(char**)self = D_004A3E90;
    if (n > 0) {
        cBXString_Realloc(self, n);
        func_00416210(*(char**)self, ch, n);
    }
    return self;
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00318F20);
#ifdef SKIP_ASM
extern "C" cBXString* func_00318F20(cBXString* self, char ch)
{
    char buf = ch;
    cBXString_InitFromCString(self, 1, &buf);
    return self;
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00318F58);
#ifdef SKIP_ASM
extern "C" cBXString* func_00318F90(cBXString* self, cBXString* other, int start, int count);

extern "C" cBXString* func_00318F58(cBXString* self, cBXString* other, int start)
{
    func_00318F90(self, other, start, *(int*)(*(int*)other - 8) - start);
    return self;
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00318F90);
#ifdef SKIP_ASM
// Mid(start, count). PORT: pointer held in int for the header offset.
extern "C" cBXString* func_00318F90(cBXString* self, cBXString* other, int start, int count)
{
    if (start < 0)
        start = 0;
    if (count < 0)
        count = 0;
    int len = *(int*)(*(int*)other - 8);
    if (len < start + count)
        count = len - start;
    if (len < start)
        count = 0;
    char* tmp = D_004A3E90;
    func_003181E8(other, (cBXString*)&tmp, count, start, 0);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstring", func_00319028);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" void func_003181E8(cBXString* src, cBXString* dst, int len, int pos, int extra);
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other);
extern "C" void cBXString__cBXString(cBXString* self, int flags);

// Right(n): the last n chars of other. PORT: pointer held in int for the header offset.
extern "C" cBXString* func_00319028(cBXString* self, cBXString* other, int n)
{
    if (n < 0)
        n = 0;
    else
    {
        int len = *(int*)(*(int*)other - 8);
        if (len < n)
            n = len;
    }
    char* tmp = D_004A3E90;
    func_003181E8(other, (cBXString*)&tmp, n, *(int*)(*(int*)other - 8) - n, 0);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/bxstring", cBXString_cBXString5);
#ifdef SKIP_ASM
struct cBXString;
extern char* D_004A3E90;
extern "C" void func_003181E8(cBXString* src, cBXString* dst, int len, int pos, int extra);
extern "C" cBXString* cBXString_cBXString1(cBXString* self, cBXString* other);
extern "C" void cBXString__cBXString(cBXString* self, int flags);

// PORT: pointer held in int to get the target's negative header offset.
extern "C" cBXString* cBXString_cBXString5(cBXString* self, cBXString* other, int n)
{
    if (n < 0)
        n = 0;
    else
    {
        int len = *(int*)(*(int*)other - 8);
        if (len < n)
            n = len;
    }
    char* tmp = D_004A3E90;
    func_003181E8(other, (cBXString*)&tmp, n, 0, 0);
    cBXString_cBXString1(self, (cBXString*)&tmp);
    cBXString__cBXString((cBXString*)&tmp, 2);
    return self;
}
#endif


//100%
INCLUDE_ASM("bx/bxstring", func_00319120);
#ifdef SKIP_ASM
// PORT: the unit defines cBXString_cBXString5 returning cBXString*; the caller ignores the result.
void cBXString_cBXString5_v(cBXString* self, cBXString* other, int n) __asm__("cBXString_cBXString5");
extern "C" int func_0041AD10(char* str, int ch);

extern "C" cBXString* func_00319120(cBXString* self, cBXString* other, int ch)
{
    cBXString_cBXString5_v(self, other, func_0041AD10(other->str, ch));
    return self;
}
#endif
//100%
INCLUDE_ASM("bx/bxstring", func_00319170);
#ifdef SKIP_ASM
// PORT: the unit defines cBXString_cBXString5 returning cBXString*; the caller ignores the result.
void cBXString_cBXString5_v(cBXString* self, cBXString* other, int n) __asm__("cBXString_cBXString5");
extern "C" int func_0041AB08(char* str, int ch);

extern "C" cBXString* func_00319170(cBXString* self, cBXString* other, int ch)
{
    cBXString_cBXString5_v(self, other, func_0041AB08(other->str, ch));
    return self;
}
#endif
