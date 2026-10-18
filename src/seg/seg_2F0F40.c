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

INCLUDE_ASM("seg/seg_2F0F40", func_003F0568);

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

INCLUDE_ASM("seg/seg_2F0F40", func_003F0658);

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
extern void func_003F0B50(struct S07A0*);
extern void func_003F0BE0(struct S07A0*);
extern void func_003F55B8(int);
extern void func_00259210(struct S07A0*);
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

INCLUDE_ASM("seg/seg_2F0F40", func_003F0818);

INCLUDE_ASM("seg/seg_2F0F40", func_003F08E8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0B50);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0BE0);

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

INCLUDE_ASM("seg/seg_2F0F40", func_003F15C8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F16D8);

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

INCLUDE_ASM("seg/seg_2F0F40", func_003F3128);
