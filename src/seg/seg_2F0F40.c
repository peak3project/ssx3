#include "common.h"

INCLUDE_ASM("seg/seg_2F0F40", func_003EFF40);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F00D8);
#ifdef SKIP_ASM
extern char D_004A4AD8[];
extern int func_003F5910(int, int, int, int, int);
extern void func_003EFF40(int*, char*, int*);
void func_003F00D8(int* p, int a, int b) {
    int t[4];
    func_003F5910(p[1], a, 0, b, -1);
    if (p[0x508 / 4]) {
        t[1] = a;
        t[3] = b;
        t[2] = 0;
        t[0] = 0;
        func_003EFF40(p, D_004A4AD8, t);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0150);
#ifdef SKIP_ASM
extern char* strchr(const char* s, int c);
void func_003F0150(char* s) {
    char* p = strchr(s, '@');
    if (p) *p = 0;
    p = strchr(s, '/');
    if (p) *p = 0;
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F0198);

INCLUDE_ASM("seg/seg_2F0F40", func_003F02D0);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0568);
#ifdef SKIP_ASM
extern char D_004A4B18[];
extern char D_004A4B10[];
extern char D_004A4B08[];
extern int cDirtysock_tag_TagFieldSetFourCC(char* dst, int len, const char* key, int val);
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
void func_003F0568(char* p) {
    char buf[0x200];
    if (*(int*)(p + 0x1C)) {
        cDirtysock_tag_TagFieldSetFourCC(p + 0x140, 0x100, D_004A4B18, *(int*)(p + 0x1C));
    }
    cDirtysock_tag_TagFieldDupl(buf, 0x200, p + 0x240);
    if (p[0x140]) {
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A4B10, p + 0x140);
    }
    if (p[0x40]) {
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A4B08, p + 0x40);
    }
    func_003F00D8((int*)p, 0x50534554, (int)buf);
    *(int*)(p + 0x2C0) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0610);
#ifdef SKIP_ASM
void func_003F0610(int* p, int a) {
    int t[4];
    p[2] = a;
    if (p[0x4C4 / 4]) {
        t[0] = 0x636F6E6E;
        t[1] = a;
        t[2] = 0;
        t[3] = 0;
        ((void (*)(int*, int*, int))p[0x4C4 / 4])(p, t, p[0x4C0 / 4]);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0658);
#ifdef SKIP_ASM
struct S0658E { int f0, f4, f8, fC, f10; };
struct S0658 { int pad[5]; int f14; int pad2[(0x4C8-0x18)/4]; struct S0658E e[1]; };
extern int D_004512B0[];
extern int func_003F5D88(int);
void func_003F0658(struct S0658* p, int idx, int a, int b, int ms) {
    int t = 0;
    if (ms > 0) {
        t = func_003F5D88(((int*)p)[1]) + ms * 1000;
    }
    p->e[idx].f0 = D_004512B0[idx];
    p->f14++;
    p->e[idx].f4 = p->f14;
    p->e[idx].fC = b;
    p->e[idx].f10 = a;
    p->e[idx].f8 = t;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0710);
#ifdef SKIP_ASM
extern void* func_002591E8(int);
extern void func_00416210(void*, int, int);
extern int cDirtysock_tag_TagFieldDupl(char* dst, int len, const char* src);
extern int func_003F5478(int);
int* func_003F0710(const char* a, const char* b) {
    int* p = (int*)func_002591E8(0x50C);
    if (p) {
        func_00416210(p, 0, 0x50C);
        cDirtysock_tag_TagFieldDupl((char*)p + 0x314, 0x40, a);
        cDirtysock_tag_TagFieldDupl((char*)p + 0x354, 0x40, b);
        p[1] = func_003F5478(0x8000);
        p[5] = 0x64;
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F07A0);
#ifdef SKIP_ASM
struct S07A0Obj {
    int pad[3];
    void (*fn)(struct S07A0Obj*);
};
struct S07A0 {
    struct S07A0Obj* obj;
    int f4;
};
extern int func_003F0B50(struct S07A0*);
extern void func_003F0BE0(struct S07A0*);
extern void func_003F55B8(int);
extern void func_00259210(void*);
void func_003F07A0(struct S07A0* p) {
    if (p->obj) {
        p->obj->fn(p->obj);
        p->obj = 0;
    }
    func_003F0B50(p);
    func_003F0BE0(p);
    func_003F55B8(p->f4);
    func_00259210(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0800);
#ifdef SKIP_ASM
int func_003F0800(int* p) {
    return p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0808);
#ifdef SKIP_ASM
void func_003F0808(int* p, int a, int b) {
    p[0x504 / 4] = a;
    p[0x508 / 4] = b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0818);
#ifdef SKIP_ASM
int func_003F0818(char* p, const char* src, int key, char* s, int x) {
    short* q;
    int j;
    cDirtysock_tag_TagFieldDupl(p + 0x2C8, 0x40, src);
    *(int*)(p + 0x1C) = key;
    j = 0;
    q = (short*)(p + 0x30C);
    do {
        if (s[0] < 0x61 || s[1] < 0x61) {
            break;
        }
        *q = 0;
        j++;
        *q = s[0] << 8;
        *q |= s[1];
        s += 2;
        q++;
    } while (j < 4);
    *(int*)(p + 0x18) = x;
    *(int*)(p + 0x308) = j;
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F08E8);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0B50);
#ifdef SKIP_ASM
extern int D_004A4AE8[];
extern void func_003F5738(int);
int func_003F0B50(struct S07A0* p) {
    if (p->obj) {
        p->obj->fn(p->obj);
        p->obj = 0;
    }
    func_003F00D8((int*)p, 0x44495343, (int)D_004A4AE8);
    func_003F5738(p->f4);
    if (((int*)p)[2] == 5) {
        func_003F0610((int*)p, 6);
    }
    func_003F0610((int*)p, 0);
    ((int*)p)[0x4C4 / 4] = 0;
    func_003F0BE0(p);
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0BE0);
#ifdef SKIP_ASM
extern int func_003EE9A0(int);
extern void* func_003EE480(int, int);
extern void func_003EE820(int);
extern void func_003EE260(int);
void func_003F0BE0(struct S07A0* sp) {
    int* p = (int*)sp;
    int t[4];
    int x;
    if (p[0x4A8 / 4]) {
        while ((x = func_003EE9A0(p[0x4A4 / 4]))) {
            func_00259210(func_003EE480(p[0x4A8 / 4], x));
        }
        if (p[0x4B8 / 4]) {
            t[0] = 0x726F7374;
            t[1] = 0;
            t[2] = 0;
            t[3] = p[0x4A8 / 4];
            ((void (*)(int*, int*, int))p[0x4B8 / 4])(p, t, p[0x4B4 / 4]);
        }
        func_003EE820(p[0x4A4 / 4]);
        p[0x4A4 / 4] = 0;
        func_003EE260(p[0x4A8 / 4]);
        p[0x4A8 / 4] = 0;
        p[0x4A8 / 4] = 0;
        p[0x4B4 / 4] = 0;
        p[0x4B8 / 4] = 0;
    }
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F0C90);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0E30);
#ifdef SKIP_ASM
int func_003F0E30(int* p) {
    return p[0x4A8 / 4];
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F0E38);

INCLUDE_ASM("seg/seg_2F0F40", func_003F11F8);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F14D8);
#ifdef SKIP_ASM
extern int func_003EEC88(int, int);
extern int func_003EE468(int, int);
int func_003F14D8(int* p, int a) {
    int r = 0;
    if (p[0x4A4 / 4] && a) {
        int x = func_003EEC88(p[0x4A4 / 4], a);
        if (x) {
            r = func_003EE468(p[0x4A8 / 4], x);
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F1538);
#ifdef SKIP_ASM
void func_003F1538(char* p) {
    p[0x40] = 0;
    p[0x140] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F1548);
#ifdef SKIP_ASM
extern int cDirtysock_tag_TagFieldDupl(char* dst, int len, const char* src);
void func_003F1548(char* p, const char* src) {
    if (p[0x2C8]) {
        cDirtysock_tag_TagFieldDupl(p + 0x40, 0x100, src);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F1578);
#ifdef SKIP_ASM
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
void func_003F1578(char* p, const char* val, const char* key) {
    if (key[0] && key[1] && !key[2] && val[0]) {
        cDirtysock_tag_TagFieldSetString(p + 0x140, 0x100, key, val);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F15C8);
#ifdef SKIP_ASM
extern int D_004512C0[];
extern char D_004A4AF8[];
extern char D_004A4B00[];
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
extern int func_003F5D88(int);
extern void func_003F0568(char*);
int func_003F15C8(char* p, char* s, int st, int d) {
    unsigned int now = func_003F5D88(*(int*)(p + 4));
    int v;
    char* buf;
    if ((unsigned int)(st - 1) < 5) {
        v = D_004512C0[st];
    } else {
        v = D_004512C0[0];
    }
    buf = p + 0x240;
    *buf = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x80, D_004A4AF8, s);
    cDirtysock_tag_TagFieldSetString(buf, 0x80, D_004A4B00, (char*)v);
    if (*(unsigned int*)(p + 0x2C0) == 0) {
        *(unsigned int*)(p + 0x2C0) = now + d;
    }
    if (*(int*)(p + 0x2C4) != st) {
        *(int*)(p + 0x2C4) = st;
        *(unsigned int*)(p + 0x2C0) = now;
    }
    if (now >= *(unsigned int*)(p + 0x2C0)) {
        func_003F0568(p);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F16D8);
#ifdef SKIP_ASM
extern char D_004A4B70[];
extern char D_004A4B78[];
extern int D_004A4AE8[];
extern char* cDirtysock_tag_TagFieldFind(const char* tag, const char* key);
extern int cDirtysock_tag_TagFieldGetString(const char* data, char* buf, int len, const char* defval);
int func_003F16D8(int* p, char* tag, int a, int b, int c) {
    if (cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(tag, D_004A4B70), 0, 0, (char*)D_004A4AE8) < 0x40) {
        if (cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(tag, D_004A4B78), 0, 0, (char*)D_004A4AE8) <= 0) {
            func_003F0658(p, 2, a, b, c);
            func_003F00D8(p, 0x53454E44, (int)tag);
            return 0;
        }
    }
    return -3;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F17C8);
#ifdef SKIP_ASM
void func_003F17C8(int* p, int a, int b) {
    p[0x4B0 / 4] = a;
    p[0x4AC / 4] = b;
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F17D8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F2220);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F30F0);
#ifdef SKIP_ASM
void func_003F30F0(unsigned int* p) {
    p[0] = 0;
    p[1] = 0x67452301;
    p[2] = 0xEFCDAB89;
    p[3] = 0x98BADCFE;
    p[4] = 0x10325476;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F3128);
#ifdef SKIP_ASM
struct Md5Ctx {
    unsigned int count;
    unsigned int state[4];
    unsigned char buf[64];
};
extern void func_003F2220(struct Md5Ctx*);
void func_003F3128(struct Md5Ctx* ctx, unsigned char* data, int len) {
    unsigned int idx;
    unsigned char* p;
    p = data;
    if (len < 0) {
        len = 0;
        while (data[len]) {
            len++;
        }
    }
    idx = ctx->count & 0x3F;
    while (len > 0) {
        ctx->buf[idx] = *p++;
        ctx->count++;
        idx++;
        if (idx == 0x40) {
            func_003F2220(ctx);
            idx = 0;
        }
        len--;
    }
}
#endif
