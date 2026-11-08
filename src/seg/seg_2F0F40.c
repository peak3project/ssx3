#include "common.h"

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003EFF40);
#ifdef SKIP_ASM
extern char D_00496B58_FF40[] __asm__("D_00496B58");
extern char D_00496B70_FF40[] __asm__("D_00496B70");
extern char D_00496B80_FF40[] __asm__("D_00496B80");
extern char D_00496B90_FF40[] __asm__("D_00496B90");
extern char D_004A4AD0_FF40[] __asm__("D_004A4AD0");
extern void func_003EFED0(char *, const char *, ...);
struct I_FF40 { int f0; int f4; int f8; char *fC; };

void func_003EFF40_impl(char *self, char *x, struct I_FF40 *info) __asm__("func_003EFF40");
void func_003EFF40_impl(char *self, char *x, struct I_FF40 *info) {
    int a, b;
    int n, flag;
    int cr;
    char *p;
    char *s = info->fC;

    b = info->f8;
    if (b == 0) b = 0x2D2D2D2D;
    a = info->f4;
    if (a == -1) {
        a = 0x2A2A2A2A;
        if (b == -1) {
            b = 0x636F6E6E;
        } else if (b == (int)0xFEFEFEFE) {
            b = 0x64697363;
        } else {
            b = 0x2D2D2D2D;
        }
    }
    func_003EFED0(self, D_00496B58_FF40, x, a >> 24, a >> 16, a >> 8, a, b >> 24, b >> 16, b >> 8, b);
    n = 0;
    flag = 0;
    if (*s != 0 && *s < 0x7F) {
        cr = 13;
        p = s;        do {
            unsigned char c = *p;
            char ch = *p;
            if (ch < 0x20) {
                if ((unsigned)(c - 9) < 2) continue;
                if (ch != cr) {
                    flag = 1;
                    break;
                }
            }
        } while (p++, n++, *p != 0 && *p < 0x7F);
    }
    if (n == 0) {
        func_003EFED0(self, D_00496B70_FF40);
    } else if (flag == 1) {
        func_003EFED0(self, D_00496B80_FF40);
    } else if (n >= 0x201) {
        func_003EFED0(self, D_00496B90_FF40);
    } else {
        func_003EFED0(self, D_004A4AD0_FF40, s);
    }
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0198);
#ifdef SKIP_ASM
extern char D_004A4AE0[];
extern int D_004A4AE8[];
extern char D_004A4AF0[];
extern char D_004A4AF8[];
extern char* strchr(const char* s, int c);
extern int cDirtysock_tag_TagFieldDupl(char* dst, int len, const char* src);
extern char* cDirtysock_tag_TagFieldFind(const char* tag, const char* key);
extern int cDirtysock_tag_TagFieldGetString(const char* data, char* buf, int len, const char* defval);
extern int cDirtysock_tag_TagFieldDelete(char* tag, const char* key);
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
void func_003F0198(char* self, int* ev) {
    char tag[0x800];
    char name[0x100];
    char* nm;
    char* p;
    char* q;
    cDirtysock_tag_TagFieldDupl(tag, 0x800, (char*)ev[3]);
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(tag, D_004A4AE0), (char*)name, 0x100, (char*)D_004A4AE8);
    nm = (char*)name;
    cDirtysock_tag_TagFieldDelete(tag, D_004A4AE0);
    p = strchr(nm, '@');
    if (p) *p = 0;
    cDirtysock_tag_TagFieldSetString(tag, 0x800, D_004A4AE0, nm);
    if (p) {
        nm = p + 1;
        q = strchr(nm, '/');
        if (q) *q = 0;
        cDirtysock_tag_TagFieldSetString(tag, 0x800, D_004A4AF0, nm);
        if (q) {
            cDirtysock_tag_TagFieldSetString(tag, 0x800, D_004A4AF8, q + 1);
        }
    }
    ev[3] = (int)tag;
    ev[0] = 0x63686174;
    (*(void (**)(char*, int*, int))(self + 0x4B0))(self, ev, *(int*)(self + 0x4AC));
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F02D0);
#ifdef SKIP_ASM
// Fills the output record from the event tag fields.
extern int D_004512C0[];
extern int D_004A4AE8[];
extern char D_004A4B00[];
extern char D_004A4B08[];
extern char D_004A4B10[];
extern char D_004A4B18[];
extern char* cDirtysock_tag_TagFieldFind(const char* tag, const char* key);
extern int cDirtysock_tag_TagFieldGetString(const char* data, char* buf, int len, const char* defval);
extern int cDirtysock_tag_TagFieldGetFourCC(const char* data, int def);
extern int func_004165A8(const char*, const char*);
extern int func_003EFE20(char*, int, short*, int, char*, int);
void func_003F02D0(char* self, char* ev, char* out) {
    char key[3];
    char buf[0x100];
    short v;
    int w;
    int i = 0;
    int fourcc;
    char* f;
    char* p;
    out[0xA7] = 0;
    out[0xA4] = 0;
    out[0x54] = 0;
    out[0x40] = 0;
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(ev + 0xC), D_004A4B00), buf, 0x100, (char*)D_004A4AE8);
    while (i < 6) {
        if (func_004165A8((const char*)D_004512C0[i], buf) == 0) {
            out[0xA7] = i;
            break;
        }
        i++;
    }
    f = cDirtysock_tag_TagFieldFind(*(char**)(ev + 0xC), D_004A4B08);
    if (f) {
        *(int*)(out + 0xA8) |= 0x2000;
    }
    cDirtysock_tag_TagFieldGetString(f, out + 0x54, 0x50, (char*)D_004A4AE8);
    if (out[0x54] != 0) {
        func_003EFE20(self, *(int*)(self + 0x1C), (short*)(self + 0x30C), 1, out + 0x40, 0x14);
        out[0xA4] = *(unsigned short*)(self + 0x30C) >> 8;
        w = *(short*)(self + 0x30C);
        out[0xA6] = 0;
        out[0xA5] = w;
    } else {
        i = 0;
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(ev + 0xC), D_004A4B10), buf, 0x100, (char*)D_004A4AE8);
        fourcc = cDirtysock_tag_TagFieldGetFourCC(cDirtysock_tag_TagFieldFind(buf, D_004A4B18), 0);
        if (*(int*)(self + 0x308) > 0) {
            p = self + 0x30C;
            for (; i < *(int*)(self + 0x308); i++, p += 2) {
                short w = *(short*)p;
                key[0] = w >> 8;
                key[1] = w;
                key[2] = 0;
                f = cDirtysock_tag_TagFieldFind(buf, key);
                if (f) {
                    unsigned char b0, b1;
                    cDirtysock_tag_TagFieldGetString(f, out + 0x54, 0x50, (char*)D_004A4AE8);
                    b1 = key[1];
                    b0 = key[0];
                    out[0xA4] = b0;
                    out[0xA5] = b1;
                    out[0xA6] = 0;
                    v = (short)((((int)(b1 << 24) >> 8) | (b0 << 24)) >> 16);
                    func_003EFE20(self, fourcc, &v, 1, out + 0x40, 0x14);
                    break;
                }
            }
        }
        if (out[0xA4] == 0) {
            int r = func_003EFE20(self, fourcc, (short*)(self + 0x30C), *(int*)(self + 0x308), out + 0x40, 0x14);
            short s = r;
            out[0xA6] = 0;
            v = r;
            out[0xA4] = s >> 8;
            out[0xA5] = s;
        }
    }
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F08E8);
#ifdef SKIP_ASM
extern char D_004A4AA0[];
extern char D_004A4AE0[];
extern char D_004A4B08[];
extern char D_004A4B20[];
extern char D_004A4B28[];
extern char D_004A4B30[];
extern char* strchr(const char* s, int c);
extern char* strncpy(char* d, const char* s, int n);
extern char* strcpy(char* d, const char* s);
extern int strlen(const char* s);
extern char* func_004162D0(char*, const char*);
extern int cDirtysock_tag_TagFieldDupl(char* dst, int len, const char* src);
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
extern int func_003F3A98(int, int);
extern int func_003F5D88(int);
int func_003F08E8(char* self, int a1, int a2, int ms, char* host, char* nick, int cb, int ctx) {
    char tag[0x100];
    char tmp[0x100];
    char* q;
    char* buf = self + 0x394;
    char* s;
    func_003F0B50((struct S07A0*)self);
    *(int*)(self + 0x4C0) = ctx;
    *(int*)(self + 0x4C4) = cb;
    *(int*)(self + 0x10) = a2;
    *buf = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B08, self + 0x314);
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B20, self + 0x354);
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B28, self + 0x2C8);
    if (strchr(host, ':') == 0) {
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, nick);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B30, host);
    } else {
        strncpy(tmp, host, 0xFF);
        tmp[0xFF] = 0;
        q = strchr(tmp, ':');
        if (q) {
            *q = 0;
            cDirtysock_tag_TagFieldDupl(tag, 0x100, tmp);
            q++;
            if ((unsigned int)(strlen(tag) + strlen(nick)) < 0x100) {
                func_004162D0(tag, nick);
            }
            cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, tag);
            if (*q == '$') {
                cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B30, q + 1);
            } else {
                cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AA0, q);
            }
        }
    }
    s = self + 0x494;
    cDirtysock_tag_TagFieldDupl(s, 0x10, nick);
    if (*s == '/') {
        strcpy(s, self + 0x495);
    }
    q = strchr(s, '/');
    if (q) *q = 0;
    *(int*)self = func_003F3A98(a1, ms * 1000);
    func_003F0610((int*)self, 1);
    *(int*)(self + 0xC) = func_003F5D88(*(int*)(self + 4)) + ms * 1000;
    *(int*)(self + 0x2C4) = -1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0B50);
#ifdef SKIP_ASM
extern int D_004A4AE8[];
extern int func_003F5738(int);
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

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0C90);
#ifdef SKIP_ASM
extern char D_004A4B28[];
extern char D_004A4B38[];
extern char D_004A4B40[];
extern char D_004A4B48[];
extern char D_004A4B50[];
extern char D_004A4B58[];
extern char D_004A4B60[];
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
extern int cDirtysock_tag_TagFieldSetNumber(char* dst, int len, const char* key, int val);
extern int func_003EE778(int, int);
extern int func_003EE1E8(int, int, int);
extern int func_003EE600(int, int);
void* func_003F0C90(char* self, int a, int b) {
    char buf[0x100];
    if (*(int*)(self + 0x4A8) == 0) {
        char* s = self + 0x494;
        *(int*)(self + 0x4B8) = a;
        *(int*)(self + 0x4B4) = b;
        *(int*)(self + 0x4A4) = func_003EE778(0x3E8, 0x7D0);
        *(int*)(self + 0x4A8) = func_003EE1E8(0x64, 0x64, 0);
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B38, s);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B40, D_004A4B48);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B28, D_004A4B50);
        cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A4B58, 1);
        func_003F00D8((int*)self, 0x52474554, (int)buf);
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B38, s);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B40, D_004A4B60);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B28, D_004A4B50);
        cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A4B58, 2);
        func_003F00D8((int*)self, 0x52474554, (int)buf);
        func_003EE600(*(int*)(self + 0x4A8), 1);
    }
    return *(void**)(self + 0x4A8);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0E30);
#ifdef SKIP_ASM
int func_003F0E30(int* p) {
    return p[0x4A8 / 4];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0E38);
#ifdef SKIP_ASM
extern char* strchr(const char* s, int c);
extern void* func_002591E8(int);
extern int func_003EEC88(int, int);
extern int func_003EE468(int, int);
extern int func_003EE320(int, int);
extern int func_003EEB30(int, int, int);
extern char D_004A4AE0[];
extern char D_004A4B28[];
extern char D_004A4B38[];
extern char D_004A4B40[];
extern char D_004A4B48[];
extern char D_004A4B50[];
extern char D_004A4B58[];
extern char D_004A4B60[];
extern char D_004A4B68[];
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
extern int cDirtysock_tag_TagFieldSetNumber(char* dst, int len, const char* key, int val);
typedef struct { char b[0xB8]; } Ent_0E38;
int func_003F0E38(char* self, char* e, int a, int b, int c) {
    char buf[0x100];
    char* ent;
    int x;
    if (e == 0 || *(int*)(e + 0xA8) == 0 || e[0] == 0 || strchr(e, '/') != 0)
        return -3;
    if (strchr(e, '@') != 0)
        return -3;
    if (*(int*)(self + 0x18) == 0) {
        if (strchr(e, '.') != 0)
            return -3;
    }
    func_003F0658((struct S0658*)self, 0, a, b, c);
    if (*(int*)(self + 0x4A8) == 0)
        return 0;
    x = func_003EEC88(*(int*)(self + 0x4A4), (int)e);
    if (x == 0) {
        ent = (char*)func_002591E8(0xB8);
        *(Ent_0E38*)ent = *(Ent_0E38*)e;
        func_003EEB30(*(int*)(self + 0x4A4), (int)ent, func_003EE320(*(int*)(self + 0x4A8), (int)ent));
    } else {
        ent = (char*)func_003EE468(*(int*)(self + 0x4A8), x);
        *(int*)(ent + 0xA8) |= *(int*)(e + 0xA8);
    }
    *(int*)(ent + 0xAC) = 0;
    if (*(int*)(e + 0xA8) & 4) {
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B38, self + 0x494);
        cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A4B58, *(int*)(self + 0x4CC));
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B40, D_004A4B48);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B28, D_004A4B50);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, e);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B68, e + 0x20);
        func_003F00D8((int*)self, 0x52414444, (int)buf);
        *(int*)(ent + 0xA8) |= 0x10000;
        *(int*)(ent + 0xAC) = *(int*)(self + 0x14);
    }
    if (*(int*)(e + 0xA8) & 0x200) {
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B38, self + 0x494);
        cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A4B58, *(int*)(self + 0x4CC));
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B40, D_004A4B60);
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, e);
        func_003F00D8((int*)self, 0x52414444, (int)buf);
        *(int*)(ent + 0xA8) |= 0x10000;
        *(int*)(ent + 0xAC) = *(int*)(self + 0x14);
    }
    if (*(int*)(e + 0xA8) & 0x800000) {
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, e);
        func_003F00D8((int*)self, 0x50414444, (int)buf);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F11F8);
#ifdef SKIP_ASM
extern char D_004A4AE0[];
extern char D_004A4B28[];
extern char D_004A4B38[];
extern char D_004A4B40[];
extern char D_004A4B48[];
extern char D_004A4B50[];
extern char D_004A4B58[];
extern char D_004A4B60[];
extern char D_004A4B68[];
extern char* strchr(const char* s, int c);
extern int cDirtysock_tag_TagFieldSetString(char* dst, int len, const char* key, const char* val);
extern int cDirtysock_tag_TagFieldSetNumber(char* dst, int len, const char* key, int val);
extern int func_003EEC88(int, int);
extern int func_003EE468(int, int);
extern void func_003EED08(int, char*);
extern void* func_003EE480(int, int);
// Release-build assert: compiles to an empty do { } while (0) (its loop notes still shape the code)
#define ASSERT_11F8(cond) do { } while (0)
int func_003F11F8(char* self, char* name, int a, int b, int ms) {
    char buf[0x100];
    int ret = -2;
    int id;
    char* ent;
    int t;
    if (name) {
        if (*(int*)(self + 0x4A8) != 0) {
            if (strchr(name, '/')) return -3;
            if (strchr(name, '@')) return -3;
            if (*(int*)(self + 0x18) == 0) {
                if (strchr(name, '.')) return -3;
            }
            func_003F0658((struct S0658*)self, 1, a, b, ms);
            id = func_003EEC88(*(int*)(self + 0x4A4), (int)name);
            if (id != 0) {
                ent = (char*)func_003EE468(*(int*)(self + 0x4A8), id);
                t = *(int*)(ent + 0xA8) & *(int*)(name + 0xA8);
                *(int*)(ent + 0xA8) ^= t;
                if (t & 4) {
                    buf[0] = 0;
                    cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A4B58, *(int*)(self + 0x4E0));
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B38, self + 0x494);
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B40, D_004A4B48);
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B28, D_004A4B50);
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, name);
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B68, name + 0x20);
                    func_003F00D8((int*)self, 0x5244454C, (int)buf);
                }
                if (t & 0x200) {
                    buf[0] = 0;
                    cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A4B58, *(int*)(self + 0x4E0));
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B38, self + 0x494);
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B40, D_004A4B60);
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, name);
                    func_003F00D8((int*)self, 0x5244454C, (int)buf);
                }
                if (t & 0x800000) {
                    buf[0] = 0;
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4B38, self + 0x494);
                    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A4AE0, name);
                    func_003F00D8((int*)self, 0x5044454C, (int)buf);
                }
                if ((*(int*)(ent + 0xA8) & 0x100204) == 0) {
                    func_003EED08(*(int*)(self + 0x4A4), name);
                    func_00259210(func_003EE480(*(int*)(self + 0x4A8), id));
                }
                ret = 0;
            }
        }
    }
    ASSERT_11F8(ret == 0 || ret == -2);
    return ret;
}
#endif

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

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F17D8);
#ifdef SKIP_ASM
extern char D_00496BA0[];
extern char D_00496BB8[];
extern char D_004A4B80[];
extern char D_004A4B58[];
extern char D_004A4B88[];
extern char D_004A4AE0[];
extern int D_004A4AE8[];
extern char D_004A4B68[];
extern char D_004A4B90[];
extern int func_003F5D88(int);
extern void f17_5908(int) __asm__("func_003F5908");
extern int func_003F5638(int, int, int);
extern int func_003F5A70(int, int*, int*, char**);
extern int func_003F5C38(int, int, int, int, int);
extern int func_003F5738(int);
extern int func_003F5910(int, int, int, int, int);
extern int func_003EE560(int, int);
extern int func_003EE620(int);
extern int f17_EED08(int, char*) __asm__("func_003EED08");
extern int func_00415FC8(void*, void*, int);
extern int cDirtysock_tag_TagFieldGetNumber(const char* data, int defval);
extern char* strcpy(char* d, const char* s);
extern int strlen(const char* s);
extern void* memset(void*, int, unsigned int);
struct Ev_17D8 {
    int kind;
    int type;
    int arg;
    char* data;
};
struct Obj_17D8 {
    int f0;
    int addr;
    int (*poll)(struct Obj_17D8*);
    void (*destroy)(struct Obj_17D8*);
};
struct Conn_17D8;
typedef void (*Cb_17D8)(struct Conn_17D8*, struct Ev_17D8*, int);
struct Req_17D8 {
    int kind;
    int seq;
    unsigned int timeout;
    int ctx;
    Cb_17D8 cb;
};
struct Conn_17D8 {
    struct Obj_17D8* obj;
    int sess;
    int state;
    unsigned int timeout;
    int port;
    int f14;
    int f18;
    char pad1C[0x2C0 - 0x1C];
    unsigned int f2C0;
    char pad2C4[0x394 - 0x2C4];
    char auth[0x4A4 - 0x394];
    int names;
    int roster;
    int admnCtx;
    Cb_17D8 admnCb;
    int rostCtx;
    Cb_17D8 rostCb;
    int rostCount;
    int stateCtx;
    Cb_17D8 stateCb;
    struct Req_17D8 req[3];
    int f504;
    int f508;
};
typedef struct { char b[0xB8]; } Ent_17D8;
void func_003F17D8(struct Conn_17D8* self) {
    char name[0x20];
    struct Ev_17D8 ev;
    Ent_17D8 old;
    char* data;
    int done;
    unsigned int now;
    int i;
    int flags;
    int id;
    char* ent;

    now = func_003F5D88(self->sess);
    f17_5908(self->sess);
    memset(&ev, 0, sizeof(ev));
    if (self->stateCb != 0 && self->obj != 0) {
        i = self->obj->poll(self->obj);
        if (i != 0) {
            if (i > 0) {
                func_003F5638(self->sess, self->obj->addr, self->port);
                func_003EFED0((char*)self, D_00496BA0, self->obj->addr, self->port);
                func_003F00D8((int*)self, 0x41555448, (int)self->auth);
            }
            if (i < 0) {
                func_003F0610((int*)self, 2);
                self->stateCb = 0;
            }
            self->obj->destroy(self->obj);
            self->obj = 0;
        }
    }
    if (self->timeout != 0 && self->timeout < now) {
        func_003F0610((int*)self, 3);
        self->stateCb = 0;
    }
    if (self->state == 5) {
        if (self->f2C0 != 0 && now >= self->f2C0) {
            func_003F0568((char*)self);
        }
    }
    if (self->state == 5) {
        for (i = 0; i < 3; i++) {
            if (self->req[i].cb != 0 && self->req[i].timeout != 0 && self->req[i].timeout < now) {
                func_003F5738(self->sess);
                func_003F0610((int*)self, 6);
                break;
            }
        }
    }
    if (self->state == 6 || self->state == 3) {
        for (i = 0; i < 3; i++) {
            if (self->req[i].cb != 0) {
                ev.kind = self->req[i].kind;
                ev.arg = -4;
                self->req[i].cb(self, &ev, self->req[i].ctx);
                self->req[i].cb = 0;
            }
        }
    }
    while (func_003F5A70(self->sess, &ev.type, &ev.arg, &data) >= 0) {
        done = 0;
        ev.data = data;
        if (self->f508 != 0) {
            func_003EFF40((int*)self, D_004A4B80, (int*)&ev);
        }
        if (ev.type == -1) {
            if (ev.arg == -1) {
                func_003F0610((int*)self, 5);
            }
            if (ev.type == -1 && ev.arg == (int)0xFEFEFEFE) {
                func_003F0610((int*)self, 6);
            }
        }
        if (ev.type == 0x50494E47) {
            func_003F5910(self->sess, 0x50494E47, ev.arg, (int)ev.data, -1);
        }
        if (ev.type == 0x41555448) {
            ev.kind = 0x61757468;
            self->stateCb(self, &ev, self->stateCtx);
            self->timeout = 0;
            if (ev.arg != 0) {
                func_003F0B50((struct S07A0*)self);
            }
        }
        if (ev.type == 0x52454356 && self->admnCb != 0) {
            func_003F0198((char*)self, (int*)&ev);
        }
        if (ev.type == 0x53454E44 && self->req[2].cb != 0) {
            ev.kind = 0x73656E64;
            self->req[2].cb(self, &ev, self->req[2].ctx);
            self->req[2].cb = 0;
        }
        if (ev.type == 0x41444D4E && self->admnCb != 0) {
            ev.kind = 0x61646D6E;
            self->admnCb(self, &ev, self->admnCtx);
        }
        if (ev.type == 0x52474554) {
            if (cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(ev.data, D_004A4B58), 0) == 2) {
                self->rostCount = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(ev.data, D_004A4B88), 0);
                done = self->rostCount == 0;
            }
        }
        if (ev.type == 0x524F5354 && self->roster != 0) {
            flags = 4;
            id = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(ev.data, D_004A4B58), 0);
            if (id != 1) flags = 0;
            if (id == 2) flags = 0x200;
            if (flags == 0x200) {
                if (--self->rostCount == 0) done = 1;
            }
            cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(ev.data, D_004A4AE0), name, 0x20, (char*)D_004A4AE8);
            func_003F0150(name);
            if (self->f18 != 0 || strchr(name, '.') == 0) {
                id = func_003EEC88(self->names, (int)name);
                if (id == 0) {
                    if ((unsigned int)strlen(name) < 0x20) {
                        ent = (char*)func_002591E8(0xB8);
                        func_00416210(ent, 0, 0xB8);
                        strcpy(ent, name);
                        id = func_003EE320(self->roster, (int)ent);
                        func_003EEB30(self->names, (int)ent, id);
                    }
                }
                if (id != 0) {
                    ent = (char*)func_003EE468(self->roster, id);
                    if (ent != 0) {
                        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(ev.data, D_004A4B68), ent + 0x20, 0x20, (char*)D_004A4AE8);
                        if (flags != 0) {
                            *(int*)(ent + 0xA8) = (*(int*)(ent + 0xA8) | flags) & ~0x100000;
                        }
                    }
                }
            }
        }
        if (ev.type == 0x50474554 && self->roster != 0) {
            cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(ev.data, D_004A4AE0), name, 0x20, (char*)D_004A4AE8);
            func_003F0150(name);
            id = func_003EEC88(self->names, (int)name);
            if (id != 0) {
                ent = (char*)func_003EE468(self->roster, id);
                old = *(Ent_17D8*)ent;
                func_003F02D0((char*)self, (char*)&ev, ent);
                if (func_00415FC8(&old, ent, 0xB8) != 0) {
                    func_003EE600(self->roster, 1);
                    func_003EFED0((char*)self, D_00496BB8, ent, ent[0xA7], ent + 0x40, ent + 0x54, ent + 0xA4);
                }
            }
        }
        if (ev.type == 0x52414444 && self->roster != 0) {
            ev.kind = 0x61646475;
            id = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(ev.data, D_004A4B58), 0);
            for (i = 0; (ent = (char*)func_003EE560(self->roster, i)) != 0; i++) {
                if ((*(int*)(ent + 0xA8) & 0x10000) && *(int*)(ent + 0xAC) == id) {
                    if (ev.arg != 0) {
                        if (self->req[0].cb != 0) {
                            ev.arg = -2;
                            ev.data = ent;
                            self->req[0].cb(self, &ev, self->req[0].ctx);
                        }
                        func_003EE480(self->roster, f17_EED08(self->names, ent));
                        func_00259210(ent);
                    } else {
                        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(ev.data, D_004A4B90), name, 0x20, (char*)D_004A4AE8);
                        func_003F0150(name);
                        if (name[0] != 0 && (unsigned int)strlen(name) < 0x20) {
                            int k = f17_EED08(self->names, ent);
                            cDirtysock_tag_TagFieldDupl(ent, 0x20, name);
                            func_003EEB30(self->names, (int)ent, k);
                        }
                        if (self->req[0].cb != 0) {
                            ev.arg = 0;
                            ev.data = ent;
                            self->req[0].cb(self, &ev, self->req[0].ctx);
                        }
                        *(int*)(ent + 0xAC) = 0;
                        *(int*)(ent + 0xA8) ^= 0x10000;
                    }
                    break;
                }
            }
            func_003EE600(self->roster, 1);
        }
        if (ev.type == 0x5244454C && self->req[1].cb != 0) {
            if (cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(ev.data, D_004A4B58), 0) == self->req[1].seq) {
                ev.kind = 0x64656C75;
                self->req[1].cb(self, &ev, self->req[1].ctx);
                self->req[1].cb = 0;
            }
        }
        if (done != 0) {
            if (self->rostCb != 0) {
                ev.kind = 0x656E6472;
                ev.type = 0;
                ev.arg = 0;
                ev.data = 0;
                self->rostCb(self, &ev, self->rostCtx);
            }
        }
        func_003F5C38(self->sess, 0, 0, 0, 0);
    }
    if (self->rostCb != 0 && func_003EE620(self->roster) > 0) {
        ev.kind = 0x726F7374;
        ev.type = 0;
        ev.arg = 0;
        ev.data = (char*)self->roster;
        self->rostCb(self, &ev, self->rostCtx);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F2220);
#ifdef SKIP_ASM

#define MD5_F(x, y, z) ((z) ^ (((y) ^ (z)) & (x)))
#define MD5_G(x, y, z) ((y) ^ (((x) ^ (y)) & (z)))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | ~(z)))
#define MD5_STEP(f, a, b, c, d, x, s, ac)     { (a) += f((b), (c), (d)) + (x) + (unsigned int)(ac);       (a) = ((a) << (s)) | ((a) >> (32 - (s)));       (a) += (b); }
struct Md5Ctx;
void func_003F2220(struct Md5Ctx* ctx) {
    unsigned int* st = (unsigned int*)ctx;
    unsigned int x[16];
    unsigned int a, b, c, d;
    unsigned char* p;
    unsigned int* o;
    o = x + 16;
    a = 16;
    p = (unsigned char*)st + 0x54;
    do {
        o--;
        b = *--p;
        a--;
        b = (b << 8) + *--p;
        b = (b << 8) + *--p;
        b = (b << 8) + *--p;
        *o = b;
    } while (a);
    a = st[1];
    b = st[2];
    c = st[3];
    d = st[4];
    MD5_STEP(MD5_F, a, b, c, d, x[0], 7, 0xD76AA478U);
    MD5_STEP(MD5_F, d, a, b, c, x[1], 12, 0xE8C7B756U);
    MD5_STEP(MD5_F, c, d, a, b, x[2], 17, 0x242070DBU);
    MD5_STEP(MD5_F, b, c, d, a, x[3], 22, 0xC1BDCEEEU);
    MD5_STEP(MD5_F, a, b, c, d, x[4], 7, 0xF57C0FAFU);
    MD5_STEP(MD5_F, d, a, b, c, x[5], 12, 0x4787C62AU);
    MD5_STEP(MD5_F, c, d, a, b, x[6], 17, 0xA8304613U);
    MD5_STEP(MD5_F, b, c, d, a, x[7], 22, 0xFD469501U);
    MD5_STEP(MD5_F, a, b, c, d, x[8], 7, 0x698098D8U);
    MD5_STEP(MD5_F, d, a, b, c, x[9], 12, 0x8B44F7AFU);
    MD5_STEP(MD5_F, c, d, a, b, x[10], 17, 0xFFFF5BB1U);
    MD5_STEP(MD5_F, b, c, d, a, x[11], 22, 0x895CD7BEU);
    MD5_STEP(MD5_F, a, b, c, d, x[12], 7, 0x6B901122U);
    MD5_STEP(MD5_F, d, a, b, c, x[13], 12, 0xFD987193U);
    MD5_STEP(MD5_F, c, d, a, b, x[14], 17, 0xA679438EU);
    MD5_STEP(MD5_F, b, c, d, a, x[15], 22, 0x49B40821U);
    MD5_STEP(MD5_G, a, b, c, d, x[1], 5, 0xF61E2562U);
    MD5_STEP(MD5_G, d, a, b, c, x[6], 9, 0xC040B340U);
    MD5_STEP(MD5_G, c, d, a, b, x[11], 14, 0x265E5A51U);
    MD5_STEP(MD5_G, b, c, d, a, x[0], 20, 0xE9B6C7AAU);
    MD5_STEP(MD5_G, a, b, c, d, x[5], 5, 0xD62F105DU);
    MD5_STEP(MD5_G, d, a, b, c, x[10], 9, 0x02441453U);
    MD5_STEP(MD5_G, c, d, a, b, x[15], 14, 0xD8A1E681U);
    MD5_STEP(MD5_G, b, c, d, a, x[4], 20, 0xE7D3FBC8U);
    MD5_STEP(MD5_G, a, b, c, d, x[9], 5, 0x21E1CDE6U);
    MD5_STEP(MD5_G, d, a, b, c, x[14], 9, 0xC33707D6U);
    MD5_STEP(MD5_G, c, d, a, b, x[3], 14, 0xF4D50D87U);
    MD5_STEP(MD5_G, b, c, d, a, x[8], 20, 0x455A14EDU);
    MD5_STEP(MD5_G, a, b, c, d, x[13], 5, 0xA9E3E905U);
    MD5_STEP(MD5_G, d, a, b, c, x[2], 9, 0xFCEFA3F8U);
    MD5_STEP(MD5_G, c, d, a, b, x[7], 14, 0x676F02D9U);
    MD5_STEP(MD5_G, b, c, d, a, x[12], 20, 0x8D2A4C8AU);
    MD5_STEP(MD5_H, a, b, c, d, x[5], 4, 0xFFFA3942U);
    MD5_STEP(MD5_H, d, a, b, c, x[8], 11, 0x8771F681U);
    MD5_STEP(MD5_H, c, d, a, b, x[11], 16, 0x6D9D6122U);
    MD5_STEP(MD5_H, b, c, d, a, x[14], 23, 0xFDE5380CU);
    MD5_STEP(MD5_H, a, b, c, d, x[1], 4, 0xA4BEEA44U);
    MD5_STEP(MD5_H, d, a, b, c, x[4], 11, 0x4BDECFA9U);
    MD5_STEP(MD5_H, c, d, a, b, x[7], 16, 0xF6BB4B60U);
    MD5_STEP(MD5_H, b, c, d, a, x[10], 23, 0xBEBFBC70U);
    MD5_STEP(MD5_H, a, b, c, d, x[13], 4, 0x289B7EC6U);
    MD5_STEP(MD5_H, d, a, b, c, x[0], 11, 0xEAA127FAU);
    MD5_STEP(MD5_H, c, d, a, b, x[3], 16, 0xD4EF3085U);
    MD5_STEP(MD5_H, b, c, d, a, x[6], 23, 0x04881D05U);
    MD5_STEP(MD5_H, a, b, c, d, x[9], 4, 0xD9D4D039U);
    MD5_STEP(MD5_H, d, a, b, c, x[12], 11, 0xE6DB99E5U);
    MD5_STEP(MD5_H, c, d, a, b, x[15], 16, 0x1FA27CF8U);
    MD5_STEP(MD5_H, b, c, d, a, x[2], 23, 0xC4AC5665U);
    MD5_STEP(MD5_I, a, b, c, d, x[0], 6, 0xF4292244U);
    MD5_STEP(MD5_I, d, a, b, c, x[7], 10, 0x432AFF97U);
    MD5_STEP(MD5_I, c, d, a, b, x[14], 15, 0xAB9423A7U);
    MD5_STEP(MD5_I, b, c, d, a, x[5], 21, 0xFC93A039U);
    MD5_STEP(MD5_I, a, b, c, d, x[12], 6, 0x655B59C3U);
    MD5_STEP(MD5_I, d, a, b, c, x[3], 10, 0x8F0CCC92U);
    MD5_STEP(MD5_I, c, d, a, b, x[10], 15, 0xFFEFF47DU);
    MD5_STEP(MD5_I, b, c, d, a, x[1], 21, 0x85845DD1U);
    MD5_STEP(MD5_I, a, b, c, d, x[8], 6, 0x6FA87E4FU);
    MD5_STEP(MD5_I, d, a, b, c, x[15], 10, 0xFE2CE6E0U);
    MD5_STEP(MD5_I, c, d, a, b, x[6], 15, 0xA3014314U);
    MD5_STEP(MD5_I, b, c, d, a, x[13], 21, 0x4E0811A1U);
    MD5_STEP(MD5_I, a, b, c, d, x[4], 6, 0xF7537E82U);
    MD5_STEP(MD5_I, d, a, b, c, x[11], 10, 0xBD3AF235U);
    MD5_STEP(MD5_I, c, d, a, b, x[2], 15, 0x2AD7D2BBU);
    MD5_STEP(MD5_I, b, c, d, a, x[9], 21, 0xEB86D391U);
    st[1] += a;
    st[2] += b;
    st[3] += c;
    st[4] += d;
}
#endif

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
