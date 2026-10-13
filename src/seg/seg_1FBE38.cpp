#include "common.h"

//100%
INCLUDE_ASM("seg/seg_1FBE38", checkActiveNode);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern char *D_004A3DD8_AE38 __asm__("D_004A3DD8");
extern char D_00489618_AE38[] __asm__("D_00489618");
extern char D_00489628_AE38[] __asm__("D_00489628");
extern char D_00489638_AE38[] __asm__("D_00489638");
extern char D_00489648_AE38[] __asm__("D_00489648");
extern "C" void func_003578A8_AE38(void*, int, void*, void*, void*) __asm__("func_003578A8");
extern "C" void func_00351B40_AE38(void*, int, void*, void*, int, void*) __asm__("func_00351B40");
extern "C" void func_00342C08_AE38(void*, int, void*, void*, void*) __asm__("func_00342C08");
extern "C" void cDeadFadeNode_cDeadFadeNode_AE38(void*, int, void*, void*, void*) __asm__("cDeadFadeNode_cDeadFadeNode");
struct N_AE38 { int p0, p1, p2; virtual ~N_AE38(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual int v10(int); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); };
extern "C" int checkActiveNode(void *a, int type, void *buf) {
    N_AE38 *n = (N_AE38*)a;
    if (n->v10(9) || n->v10(6) || n->v10(22))
        return 1;
    if (n->v10(type)) {
        n->v37();
        return 1;
    }
    char *o = *(char**)((char*)n + 0x18);
    switch (type) {
    case 13:
        *(int*)(o + 0xC) = 0;
        func_003578A8_AE38(cMemMan_alloc(0x2C, D_00489618_AE38, 0x20000000, 0), 1, o, buf, n);
        return -1;
    case 11:
        *(int*)(o + 0xC) = 0;
        func_00351B40_AE38(cMemMan_alloc(0x6C0, D_00489628_AE38, 0x20000000, 0), 1, o, buf, *(int*)(D_004A3DD8_AE38 + 0x294), n);
        return -1;
    case 0:
        *(int*)(o + 0xC) = 0;
        func_00342C08_AE38(cMemMan_alloc(0x34, D_00489638_AE38, 0x20000000, 0), 1, o, buf, n);
        return -1;
    case 22:
        *(int*)(o + 0xC) = 0;
        cDeadFadeNode_cDeadFadeNode_AE38(cMemMan_alloc(0x3C, D_00489648_AE38, 0x20000000, 0), 1, o, buf, n);
        return -1;
    }
    delete n;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB060);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_B060 __asm__("D_004A3DD8");
extern char **D_004A47B8_B060 __asm__("D_004A47B8");
static inline char *refToPtr_B060(unsigned i) { return (char*)(i << 2); }
static inline char *conv_B060(unsigned i) { if (i == 0) return 0; return refToPtr_B060(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00359228_B060(void*, int, void*, void*) __asm__("func_00359228");
extern char D_00489658_B060[] __asm__("D_00489658");
struct V3_B060 { float x, y, z; };
extern V3_B060 D_004C9098_B060 __asm__("D_004C9098");
struct Tag_B060 { char c; Tag_B060() {} Tag_B060(const Tag_B060 &o) : c(o.c) {} };
extern unsigned D_B060[] __asm__("D_004FB390");
extern int D_004A55C0;
extern const int D_00445E70[];
extern "C" void* func_003E6574_B060(void*, void*, int) __asm__("func_003E6574");
struct Ent_B060 { int idx; int val; int pad; int type; };
extern "C" V3_B060 func_002FB060(int n, Ent_B060 *e) {
    if (D_004A55C0 == 0) {
        D_B060[0] = 0xFFFFFFFF;
        ((int*)D_B060)[1] = 1;
        ((int*)D_B060)[2] = 0;
        *(float*)&D_B060[3] = -1.0f;
        *(float*)&D_B060[4] = -1.0f;
        *(float*)&D_B060[5] = 30.0f;
        ((int*)D_B060)[6] = 0;
        *(float*)&D_B060[7] = -1.0f;
        ((int*)D_B060)[8] = 0;
        ((int*)D_B060)[9] = 0;
        D_004A55C0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_B060*)((char*)D_B060 + 40)) = Tag_B060((*(Tag_B060*)((char*)D_B060 + 40)));
    }
    unsigned buf64[11];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_B060(buf, D_B060, 44);
    Ent_B060 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445E70[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_B060 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_B060 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_B060(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_B060;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 2, buf))
        return D_004C9098_B060;
    func_00359228_B060(cMemMan_alloc(0x70, D_00489658_B060, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_B060;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB270);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_B270 __asm__("D_004A3DD8");
extern char **D_004A47B8_B270 __asm__("D_004A47B8");
static inline char *refToPtr_B270(unsigned i) { return (char*)(i << 2); }
static inline char *conv_B270(unsigned i) { if (i == 0) return 0; return refToPtr_B270(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00358C80_B270(void*, int, void*, void*) __asm__("func_00358C80");
extern char D_00489668_B270[] __asm__("D_00489668");
struct V3_B270 { float x, y, z; };
extern V3_B270 D_004C9098_B270 __asm__("D_004C9098");
struct Tag_B270 { char c; Tag_B270() {} Tag_B270(const Tag_B270 &o) : c(o.c) {} };
extern unsigned D_B270[] __asm__("D_004FB3C0");
extern int D_004A55C4;
extern const int D_00445E98[];
extern "C" void* func_003E6574_B270(void*, void*, int) __asm__("func_003E6574");
struct Ent_B270 { int idx; int val; int pad; int type; };
extern "C" V3_B270 func_002FB270(int n, Ent_B270 *e) {
    if (D_004A55C4 == 0) {
        D_B270[0] = 0xFFFFFFFF;
        ((int*)D_B270)[1] = 1;
        ((int*)D_B270)[2] = 0;
        *(float*)&D_B270[3] = -1.0f;
        *(float*)&D_B270[4] = 30.0f;
        *(float*)&D_B270[5] = 30.0f;
        ((int*)D_B270)[6] = 0;
        *(float*)&D_B270[7] = -1.0f;
        ((int*)D_B270)[8] = 0;
        ((int*)D_B270)[9] = 0;
        *(float*)&D_B270[10] = 31.0f;
        *(float*)&D_B270[11] = -1.0f;
        *(float*)&D_B270[12] = 30.0f;
        ((int*)D_B270)[13] = 0;
        D_004A55C4 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_B270*)((char*)D_B270 + 56)) = Tag_B270((*(Tag_B270*)((char*)D_B270 + 56)));
    }
    unsigned buf64[15];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_B270(buf, D_B270, 60);
    Ent_B270 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445E98[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_B270 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_B270 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_B270(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_B270;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 3, buf))
        return D_004C9098_B270;
    func_00358C80_B270(cMemMan_alloc(0x88, D_00489668_B270, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_B270;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_B498 __asm__("D_004A3DD8");
extern char **D_004A47B8_B498 __asm__("D_004A47B8");
static inline char *refToPtr_B498(unsigned i) { return (char*)(i << 2); }
static inline char *conv_B498(unsigned i) { if (i == 0) return 0; return refToPtr_B498(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_003421A0_B498(void*, int, void*, void*) __asm__("func_003421A0");
extern char D_00489678_B498[] __asm__("D_00489678");
struct V3_B498 { float x, y, z; };
extern V3_B498 D_004C9098_B498 __asm__("D_004C9098");
struct Tag_B498 { char c; Tag_B498() {} Tag_B498(const Tag_B498 &o) : c(o.c) {} };
extern unsigned D_B498[] __asm__("D_004FB400");
extern int D_004A55C8;
extern const int D_00445ED0[];
extern "C" void* func_003E6574_B498(void*, void*, int) __asm__("func_003E6574");
struct Ent_B498 { int idx; int val; int pad; int type; };
extern "C" V3_B498 func_002FB498(int n, Ent_B498 *e) {
    if (D_004A55C8 == 0) {
        D_B498[0] = 0xFFFFFFFF;
        *(float*)&D_B498[1] = 0.6000000238418579f;
        ((int*)D_B498)[2] = 0;
        *(float*)&D_B498[3] = 60.0f;
        *(float*)&D_B498[4] = 0.019999999552965164f;
        *(float*)&D_B498[5] = -10.0f;
        *(float*)&D_B498[6] = 0.6000000238418579f;
        ((int*)D_B498)[7] = 0;
        *(float*)&D_B498[8] = -1.0f;
        *(float*)&D_B498[9] = -1.0f;
        D_004A55C8 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_B498*)((char*)D_B498 + 40)) = Tag_B498((*(Tag_B498*)((char*)D_B498 + 40)));
    }
    unsigned buf64[11];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_B498(buf, D_B498, 44);
    Ent_B498 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445ED0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_B498 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_B498 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_B498(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_B498;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 4, buf))
        return D_004C9098_B498;
    func_003421A0_B498(cMemMan_alloc(0x80, D_00489678_B498, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_B498;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB6B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_B6B8 __asm__("D_004A3DD8");
extern char **D_004A47B8_B6B8 __asm__("D_004A47B8");
static inline char *refToPtr_B6B8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_B6B8(unsigned i) { if (i == 0) return 0; return refToPtr_B6B8(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00343010_B6B8(void*, int, void*, void*) __asm__("func_00343010");
extern char D_00489688_B6B8[] __asm__("D_00489688");
struct V3_B6B8 { float x, y, z; };
extern V3_B6B8 D_004C9098_B6B8 __asm__("D_004C9098");
struct Tag_B6B8 { char c; Tag_B6B8() {} Tag_B6B8(const Tag_B6B8 &o) : c(o.c) {} };
extern unsigned D_B6B8[] __asm__("D_004FB430");
extern int D_004A55CC;
extern const int D_00445EF8[];
extern "C" void* func_003E6574_B6B8(void*, void*, int) __asm__("func_003E6574");
struct Ent_B6B8 { int idx; int val; int pad; int type; };
extern "C" V3_B6B8 func_002FB6B8(int n, Ent_B6B8 *e) {
    if (D_004A55CC == 0) {
        D_B6B8[0] = 0xFFFFFFFF;
        *(float*)&D_B6B8[1] = 100.0f;
        float z = 0.0f;
        *(float*)&D_B6B8[2] = z;
        *(float*)&D_B6B8[3] = z;
        ((int*)D_B6B8)[4] = 0;
        ((int*)D_B6B8)[5] = 0;
        ((int*)D_B6B8)[6] = 0;
        ((int*)D_B6B8)[7] = 0;
        ((int*)D_B6B8)[8] = 0;
        ((int*)D_B6B8)[9] = 0;
        ((int*)D_B6B8)[10] = 0;
        ((int*)D_B6B8)[11] = 0;
        D_004A55CC = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_B6B8*)((char*)D_B6B8 + 48)) = Tag_B6B8((*(Tag_B6B8*)((char*)D_B6B8 + 48)));
    }
    unsigned buf64[13];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_B6B8(buf, D_B6B8, 52);
    Ent_B6B8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445EF8[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_B6B8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_B6B8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_B6B8(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_B6B8;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 15, buf))
        return D_004C9098_B6B8;
    func_00343010_B6B8(cMemMan_alloc(0x48, D_00489688_B6B8, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_B6B8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB8D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_B8D0 __asm__("D_004A3DD8");
extern char **D_004A47B8_B8D0 __asm__("D_004A47B8");
static inline char *refToPtr_B8D0(unsigned i) { return (char*)(i << 2); }
static inline char *conv_B8D0(unsigned i) { if (i == 0) return 0; return refToPtr_B8D0(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00343768_B8D0(void*, int, void*, void*) __asm__("func_00343768");
extern char D_004A3BE8_B8D0[] __asm__("D_004A3BE8");
struct V3_B8D0 { float x, y, z; };
extern V3_B8D0 D_004C9098_B8D0 __asm__("D_004C9098");
struct Tag_B8D0 { char c; Tag_B8D0() {} Tag_B8D0(const Tag_B8D0 &o) : c(o.c) {} };
extern unsigned D_B8D0[] __asm__("D_004FB468");
extern int D_004A55D0;
extern int D_004A3BE0_B8D0[2] __asm__("D_004A3BE0");
extern "C" void* func_003E6574_B8D0(void*, void*, int) __asm__("func_003E6574");
struct Ent_B8D0 { int idx; int val; int pad; int type; };
extern "C" V3_B8D0 func_002FB8D0(int n, Ent_B8D0 *e) {
    if (D_004A55D0 == 0) {
        D_B8D0[0] = 0xFFFFFFFF;
        ((int*)D_B8D0)[1] = 3;
        D_004A55D0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_B8D0*)((char*)D_B8D0 + 8)) = Tag_B8D0((*(Tag_B8D0*)((char*)D_B8D0 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_B8D0(buf, D_B8D0, 12);
    Ent_B8D0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004A3BE0_B8D0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_B8D0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_B8D0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_B8D0(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_B8D0;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 7, buf))
        return D_004C9098_B8D0;
    func_00343768_B8D0(cMemMan_alloc(0x24, D_004A3BE8_B8D0, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_B8D0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FBAB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_BAB0 __asm__("D_004A3DD8");
extern char **D_004A47B8_BAB0 __asm__("D_004A47B8");
static inline char *refToPtr_BAB0(unsigned i) { return (char*)(i << 2); }
static inline char *conv_BAB0(unsigned i) { if (i == 0) return 0; return refToPtr_BAB0(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_0034EC58_BAB0(void*, int, void*, void*) __asm__("func_0034EC58");
extern char D_00489698_BAB0[] __asm__("D_00489698");
struct V3_BAB0 { float x, y, z; };
extern V3_BAB0 D_004C9098_BAB0 __asm__("D_004C9098");
struct Tag_BAB0 { char c; Tag_BAB0() {} Tag_BAB0(const Tag_BAB0 &o) : c(o.c) {} };
extern unsigned D_BAB0[] __asm__("D_004FB478");
extern int D_004A55D4;
extern const int D_00445F28[];
extern "C" void* func_003E6574_BAB0(void*, void*, int) __asm__("func_003E6574");
struct Ent_BAB0 { int idx; int val; int pad; int type; };
extern "C" V3_BAB0 func_002FBAB0(int n, Ent_BAB0 *e) {
    if (D_004A55D4 == 0) {
        D_BAB0[0] = 0xFFFFFFFF;
        *(float*)&D_BAB0[1] = 10.0f;
        *(float*)&D_BAB0[2] = 10.0f;
        *(float*)&D_BAB0[3] = 40.0f;
        *(float*)&D_BAB0[4] = 10.0f;
        *(float*)&D_BAB0[5] = 0.20000000298023224f;
        *(float*)&D_BAB0[6] = 10.0f;
        D_004A55D4 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_BAB0*)((char*)D_BAB0 + 28)) = Tag_BAB0((*(Tag_BAB0*)((char*)D_BAB0 + 28)));
    }
    unsigned buf64[8];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_BAB0(buf, D_BAB0, 32);
    Ent_BAB0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445F28[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_BAB0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_BAB0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_BAB0(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_BAB0;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 14, buf))
        return D_004C9098_BAB0;
    func_0034EC58_BAB0(cMemMan_alloc(0x7C, D_00489698_BAB0, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_BAB0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FBCB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_BCB8 __asm__("D_004A3DD8");
extern char **D_004A47B8_BCB8 __asm__("D_004A47B8");
static inline char *refToPtr_BCB8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_BCB8(unsigned i) { if (i == 0) return 0; return refToPtr_BCB8(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00341AA0_BCB8(void*, int, int, void*, void*) __asm__("func_00341AA0");
extern char D_004896A8_BCB8[] __asm__("D_004896A8");
struct V3_BCB8 { float x, y, z; };
extern V3_BCB8 D_004C9098_BCB8 __asm__("D_004C9098");
struct Tag_BCB8 { char c; Tag_BCB8() {} Tag_BCB8(const Tag_BCB8 &o) : c(o.c) {} };
extern unsigned D_BCB8[] __asm__("D_004FB498");
extern int D_004A55D8;
extern const int D_00445F48[];
extern "C" void* func_003E6574_BCB8(void*, void*, int) __asm__("func_003E6574");
struct Ent_BCB8 { int idx; int val; int pad; int type; };
extern "C" V3_BCB8 func_002FBCB8(int n, Ent_BCB8 *e) {
    if (D_004A55D8 == 0) {
        D_BCB8[0] = 0xFFFFFFFF;
        ((int*)D_BCB8)[1] = 1;
        ((int*)D_BCB8)[2] = 0;
        *(float*)&D_BCB8[3] = -1.0f;
        *(float*)&D_BCB8[4] = -1.0f;
        *(float*)&D_BCB8[5] = 30.0f;
        ((int*)D_BCB8)[6] = 0;
        *(float*)&D_BCB8[7] = -1.0f;
        ((int*)D_BCB8)[8] = 0;
        ((int*)D_BCB8)[9] = 0;
        D_004A55D8 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_BCB8*)((char*)D_BCB8 + 40)) = Tag_BCB8((*(Tag_BCB8*)((char*)D_BCB8 + 40)));
    }
    unsigned buf64[11];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_BCB8(buf, D_BCB8, 44);
    Ent_BCB8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445F48[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_BCB8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_BCB8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_BCB8(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_BCB8;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 1, buf))
        return D_004C9098_BCB8;
    func_00341AA0_BCB8(cMemMan_alloc(0x6C, D_004896A8_BCB8, 0x20000000, 0), 1, 1, obj, buf);
    return D_004C9098_BCB8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FBEC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_BEC8 __asm__("D_004A3DD8");
extern char **D_004A47B8_BEC8 __asm__("D_004A47B8");
static inline char *refToPtr_BEC8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_BEC8(unsigned i) { if (i == 0) return 0; return refToPtr_BEC8(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00341388_BEC8(void*, int, int, void*, void*) __asm__("func_00341388");
extern char D_004A3BF0_BEC8[] __asm__("D_004A3BF0");
struct V3_BEC8 { float x, y, z; };
extern V3_BEC8 D_004C9098_BEC8 __asm__("D_004C9098");
struct Tag_BEC8 { char c; Tag_BEC8() {} Tag_BEC8(const Tag_BEC8 &o) : c(o.c) {} };
extern unsigned D_BEC8[] __asm__("D_004FB4C8");
extern int D_004A55DC;
extern const int D_00445F70[];
extern "C" void* func_003E6574_BEC8(void*, void*, int) __asm__("func_003E6574");
struct Ent_BEC8 { int idx; int val; int pad; int type; };
extern "C" V3_BEC8 func_002FBEC8(int n, Ent_BEC8 *e) {
    if (D_004A55DC == 0) {
        D_BEC8[0] = 0xFFFFFFFF;
        ((int*)D_BEC8)[1] = 0;
        *(float*)&D_BEC8[2] = 1.0f;
        float z = 0.0f;
        *(float*)&D_BEC8[3] = z;
        *(float*)&D_BEC8[4] = 1.0f;
        *(float*)&D_BEC8[5] = z;
        *(float*)&D_BEC8[6] = 1.0f;
        *(float*)&D_BEC8[7] = z;
        D_004A55DC = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_BEC8*)((char*)D_BEC8 + 32)) = Tag_BEC8((*(Tag_BEC8*)((char*)D_BEC8 + 32)));
    }
    unsigned buf64[9];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_BEC8(buf, D_BEC8, 36);
    Ent_BEC8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445F70[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_BEC8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_BEC8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_BEC8(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_BEC8;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 8, buf))
        return D_004C9098_BEC8;
    func_00341388_BEC8(cMemMan_alloc(0x50, D_004A3BF0_BEC8, 0x20000000, 0), 1, 8, obj, buf);
    return D_004C9098_BEC8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC0D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_C0D0 __asm__("D_004A3DD8");
extern char **D_004A47B8_C0D0 __asm__("D_004A47B8");
static inline char *refToPtr_C0D0(unsigned i) { return (char*)(i << 2); }
static inline char *conv_C0D0(unsigned i) { if (i == 0) return 0; return refToPtr_C0D0(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00356DB0_C0D0(void*, int, void*, int, bool) __asm__("func_00356DB0");
extern char D_004A3BF8_C0D0[] __asm__("D_004A3BF8");
struct V3_C0D0 { float x, y, z; };
extern V3_C0D0 D_004C9098_C0D0 __asm__("D_004C9098");
struct Tag_C0D0 { char c; Tag_C0D0() {} Tag_C0D0(const Tag_C0D0 &o) : c(o.c) {} };
extern unsigned D_C0D0[] __asm__("D_004FB4F0");
extern int D_004A55E0;
extern const int D_00445F90[];
extern "C" void* func_003E6574_C0D0(void*, void*, int) __asm__("func_003E6574");
struct Ent_C0D0 { int idx; int val; int pad; int type; };
extern "C" V3_C0D0 func_002FC0D0(int n, Ent_C0D0 *e) {
    if (D_004A55E0 == 0) {
        D_C0D0[0] = 0xFFFFFFFF;
        ((int*)D_C0D0)[1] = 0;
        ((int*)D_C0D0)[2] = 0;
        D_004A55E0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_C0D0*)((char*)D_C0D0 + 12)) = Tag_C0D0((*(Tag_C0D0*)((char*)D_C0D0 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_C0D0(buf, D_C0D0, 16);
    Ent_C0D0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445F90[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_C0D0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_C0D0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_C0D0(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_C0D0;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 17, buf))
        return D_004C9098_C0D0;
    func_00356DB0_C0D0(cMemMan_alloc(0x2C, D_004A3BF8_C0D0, 0x20000000, 0), 1, obj, buf[1], buf[2] != 0);
    return D_004C9098_C0D0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC2C0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_003506D8(void*, void*);
extern "C" void func_00350F60(void*, void*);
extern char D_004896B8[];
extern char D_004896C8[];

typedef void (*DtorFn)(void*, int);

// virtual-destructor dispatch (delete obj): vtable entry {short delta @+8, fn @+0xC}
static inline void del_obj(char* o) {
    char* vt = *(char**)(o + 0xC);
    ((DtorFn) * (void**)(vt + 0xC))(o + *(short*)(vt + 8), 3);
}

extern "C" void func_002FC2C0(char* self, char* ev) {
    switch (*(int*)(ev + 4)) {
    case 1: {
        char* o = *(char**)(self + 0xC);
        if (o) {
            if (*(short*)(o + 0x10) == 6)
                break;
            del_obj(o);
        }
        int t = *(int*)(self + 8) & 0xFFFF0300;
        *(int*)(self + 8) = t | (t >> 16) | 2;
        break;
    }
    case 0: {
        char* o = *(char**)(self + 0xC);
        if (o) {
            if (*(short*)(o + 0x10) == 6)
                break;
            del_obj(o);
        }
        func_003506D8(cMemMan_alloc(0x1C, D_004896B8, 0x20000000, 0), self);
        break;
    }
    case 3: {
        char* o = *(char**)(self + 0xC);
        if (o) {
            short ty = *(short*)(o + 0x10);
            if (ty == 6 || ty == 0x13)
                break;
            del_obj(o);
        }
        func_00350F60(cMemMan_alloc(0x1C, D_004896C8, 0x20000000, 0), self);
        break;
    }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1FBE38", func_002FC420);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_C420 __asm__("D_004A3DD8");
extern char **D_004A47B8_C420 __asm__("D_004A47B8");
extern char *D_004A28A8_C420 __asm__("D_004A28A8");
static inline char *refToPtr_C420(unsigned i) { return (char*)(i << 2); }
static inline char *conv_C420(unsigned i) { if (i == 0) return 0; return refToPtr_C420(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void func_002FC2C0_C420(void*, void*) __asm__("func_002FC2C0");
struct V3_C420 { float x, y, z; };
extern V3_C420 D_004C9098_C420 __asm__("D_004C9098");
struct Tag_C420 { char c; Tag_C420() {} Tag_C420(const Tag_C420 &o) : c(o.c) {} };
extern unsigned D_C420[] __asm__("D_004FB500");
extern int D_004A55E4;
extern int D_004A3C00;
extern "C" void* func_003E6574_C420(void*, void*, int) __asm__("func_003E6574");
struct Ent_C420 { int idx; int val; int pad; int type; };
extern "C" V3_C420 func_002FC420(int n, Ent_C420 *e) {
    if (D_004A55E4 == 0) {
        D_C420[0] = 0xFFFFFFFF;
        ((int*)D_C420)[1] = 0;
        D_004A55E4 = 1;
        (*(Tag_C420*)((char*)D_C420 + 8)) = Tag_C420((*(Tag_C420*)((char*)D_C420 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_C420(buf, D_C420, 12);
    Ent_C420 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C00)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_C420 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_C420 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_C420(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_C420;
    void *p = *(void**)(obj + 0xC);
    if (!p || !checkActiveNode(p, 6, buf))
        func_002FC2C0_C420(obj, buf);
    return D_004C9098_C420;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC5D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_C5D8 __asm__("D_004A3DD8");
extern char **D_004A47B8_C5D8 __asm__("D_004A47B8");
static inline char *refToPtr_C5D8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_C5D8(unsigned i) { if (i == 0) return 0; return refToPtr_C5D8(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void cDeadFadeNode_cDeadFadeNode_C5D8(void*, int, void*, void*, int) __asm__("cDeadFadeNode_cDeadFadeNode");
extern char D_004896D8_C5D8[] __asm__("D_004896D8");
struct V3_C5D8 { float x, y, z; };
extern V3_C5D8 D_004C9098_C5D8 __asm__("D_004C9098");
struct Tag_C5D8 { char c; Tag_C5D8() {} Tag_C5D8(const Tag_C5D8 &o) : c(o.c) {} };
extern unsigned D_C5D8[] __asm__("D_004FB510");
extern int D_004A55E8;
extern const int D_00445FA0[];
extern "C" void* func_003E6574_C5D8(void*, void*, int) __asm__("func_003E6574");
struct Ent_C5D8 { int idx; int val; int pad; int type; };
extern "C" V3_C5D8 func_002FC5D8(int n, Ent_C5D8 *e) {
    if (D_004A55E8 == 0) {
        D_C5D8[0] = 0xFFFFFFFF;
        ((int*)D_C5D8)[1] = 0;
        *(float*)&D_C5D8[2] = 2.0f;
        *(float*)&D_C5D8[3] = 25.0f;
        D_004A55E8 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_C5D8*)((char*)D_C5D8 + 16)) = Tag_C5D8((*(Tag_C5D8*)((char*)D_C5D8 + 16)));
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_C5D8(buf, D_C5D8, 20);
    Ent_C5D8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445FA0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_C5D8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_C5D8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_C5D8(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_C5D8;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 22, buf))
        return D_004C9098_C5D8;
    cDeadFadeNode_cDeadFadeNode_C5D8(cMemMan_alloc(0x3C, D_004896D8_C5D8, 0x20000000, 0), 1, obj, buf, 0);
    return D_004C9098_C5D8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC7D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_C7D0 __asm__("D_004A3DD8");
extern char **D_004A47B8_C7D0 __asm__("D_004A47B8");
static inline char *refToPtr_C7D0(unsigned i) { return (char*)(i << 2); }
static inline char *conv_C7D0(unsigned i) { if (i == 0) return 0; return refToPtr_C7D0(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00342C08_C7D0(void*, int, void*, void*, int) __asm__("func_00342C08");
extern char D_004896E8_C7D0[] __asm__("D_004896E8");
struct V3_C7D0 { float x, y, z; };
extern V3_C7D0 D_004C9098_C7D0 __asm__("D_004C9098");
struct Tag_C7D0 { char c; Tag_C7D0() {} Tag_C7D0(const Tag_C7D0 &o) : c(o.c) {} };
extern unsigned D_C7D0[] __asm__("D_004FB528");
extern int D_004A55EC;
extern const int D_00445FB0[];
extern "C" void* func_003E6574_C7D0(void*, void*, int) __asm__("func_003E6574");
struct Ent_C7D0 { int idx; int val; int pad; int type; };
extern "C" V3_C7D0 func_002FC7D0(int n, Ent_C7D0 *e) {
    if (D_004A55EC == 0) {
        D_C7D0[0] = 0xFFFFFFFF;
        *(float*)&D_C7D0[1] = 1.0f;
        ((int*)D_C7D0)[2] = 1;
        ((int*)D_C7D0)[3] = -1;
        D_004A55EC = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_C7D0*)((char*)D_C7D0 + 16)) = Tag_C7D0((*(Tag_C7D0*)((char*)D_C7D0 + 16)));
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_C7D0(buf, D_C7D0, 20);
    Ent_C7D0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445FB0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_C7D0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_C7D0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_C7D0(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_C7D0;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 0, buf))
        return D_004C9098_C7D0;
    func_00342C08_C7D0(cMemMan_alloc(0x34, D_004896E8_C7D0, 0x20000000, 0), 1, obj, buf, 0);
    return D_004C9098_C7D0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC9C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_C9C8 __asm__("D_004A3DD8");
extern char **D_004A47B8_C9C8 __asm__("D_004A47B8");
static inline char *refToPtr_C9C8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_C9C8(unsigned i) { if (i == 0) return 0; return refToPtr_C9C8(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_0034ADD8_C9C8(void*, int, void*, void*) __asm__("func_0034ADD8");
extern char D_004A3C08_C9C8[] __asm__("D_004A3C08");
struct V3_C9C8 { float x, y, z; };
extern V3_C9C8 D_004C9098_C9C8 __asm__("D_004C9098");
struct Tag_C9C8 { char c; Tag_C9C8() {} Tag_C9C8(const Tag_C9C8 &o) : c(o.c) {} };
extern unsigned D_C9C8[] __asm__("D_004FB540");
extern int D_004A55F0;
extern const int D_00445FC0[];
extern "C" void* func_003E6574_C9C8(void*, void*, int) __asm__("func_003E6574");
struct Ent_C9C8 { int idx; int val; int pad; int type; };
extern "C" V3_C9C8 func_002FC9C8(int n, Ent_C9C8 *e) {
    if (D_004A55F0 == 0) {
        D_C9C8[0] = 0xFFFFFFFF;
        ((int*)D_C9C8)[1] = 1;
        ((int*)D_C9C8)[2] = 0;
        ((int*)D_C9C8)[3] = 0;
        *(float*)&D_C9C8[4] = 1.0f;
        *(float*)&D_C9C8[5] = 25.0f;
        *(float*)&D_C9C8[6] = 1.0f;
        *(float*)&D_C9C8[7] = 1.0f;
        float z = 0.0f;
        *(float*)&D_C9C8[8] = z;
        *(float*)&D_C9C8[9] = 1.0f;
        *(float*)&D_C9C8[10] = 1.0f;
        *(float*)&D_C9C8[11] = z;
        *(float*)&D_C9C8[12] = 1.0f;
        *(float*)&D_C9C8[13] = 1.0f;
        *(float*)&D_C9C8[14] = z;
        *(float*)&D_C9C8[15] = 1.0f;
        *(float*)&D_C9C8[16] = z;
        *(float*)&D_C9C8[17] = z;
        *(float*)&D_C9C8[18] = z;
        *(float*)&D_C9C8[19] = z;
        *(float*)&D_C9C8[20] = z;
        *(float*)&D_C9C8[21] = z;
        *(float*)&D_C9C8[22] = z;
        *(float*)&D_C9C8[23] = z;
        *(float*)&D_C9C8[24] = z;
        ((int*)D_C9C8)[25] = 0;
        D_004A55F0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_C9C8*)((char*)D_C9C8 + 104)) = Tag_C9C8((*(Tag_C9C8*)((char*)D_C9C8 + 104)));
    }
    unsigned buf64[27];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_C9C8(buf, D_C9C8, 108);
    Ent_C9C8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00445FC0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_C9C8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_C9C8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_C9C8(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_C9C8;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 10, buf))
        return D_004C9098_C9C8;
    func_0034ADD8_C9C8(cMemMan_alloc(0x1C, D_004A3C08_C9C8, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_C9C8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FCC20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_CC20 __asm__("D_004A3DD8");
extern char **D_004A47B8_CC20 __asm__("D_004A47B8");
struct V3_CC20 { float x, y, z; };
extern V3_CC20 D_004C9098_CC20 __asm__("D_004C9098");
struct Tag_CC20 { char c; Tag_CC20() {} Tag_CC20(const Tag_CC20 &o) : c(o.c) {} };
extern unsigned D_CC20[] __asm__("D_004FB5B0");
extern int D_004A55F4;
extern const int D_00446028[];
extern "C" void* func_003E6574_CC20(void*, void*, int) __asm__("func_003E6574");
struct Ent_CC20 { int idx; int val; int pad; int type; };
extern "C" int checkActiveNode(void*, int, void*);
#define ASSERT_CC20(c) do { } while (0)

// PORT: struct return written with the hidden return pointer explicit.
extern "C" V3_CC20* func_002FCC20(V3_CC20* ret, int n, Ent_CC20 *e) {
    if (D_004A55F4 == 0) {
        D_CC20[0] = 0xFFFFFFFF;
        *(float*)&D_CC20[2] = 0.5f;
        ((int*)D_CC20)[1] = 0;
        D_004A55F4 = 1;
        (*(Tag_CC20*)((char*)D_CC20 + 12)) = Tag_CC20((*(Tag_CC20*)((char*)D_CC20 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_CC20(buf, D_CC20, 16);
    Ent_CC20 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446028[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_CC20 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_CC20 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        void* node = *(void**)(obj + 0xC);
        if (node)
            checkActiveNode(node, 9, buf);
    }
    // compiled-out debug macros around the return; they shape the register allocation here
    do {
        *ret = D_004C9098_CC20;
        ASSERT_CC20(ret);
        return ret;
    } while (0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FCDC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_CDC8 __asm__("D_004A3DD8");
extern char **D_004A47B8_CDC8 __asm__("D_004A47B8");
static inline char *refToPtr_CDC8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_CDC8(unsigned i) { if (i == 0) return 0; return refToPtr_CDC8(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00346350_CDC8(void*, int, void*, void*) __asm__("func_00346350");
extern char D_004896F8_CDC8[] __asm__("D_004896F8");
struct V3_CDC8 { float x, y, z; };
extern V3_CDC8 D_004C9098_CDC8 __asm__("D_004C9098");
struct Tag_CDC8 { char c; Tag_CDC8() {} Tag_CDC8(const Tag_CDC8 &o) : c(o.c) {} };
extern unsigned D_CDC8[] __asm__("D_004FB5C0");
extern int D_004A55F8;
extern const int D_00446038[];
extern "C" void* func_003E6574_CDC8(void*, void*, int) __asm__("func_003E6574");
struct Ent_CDC8 { int idx; int val; int pad; int type; };
extern "C" V3_CDC8 func_002FCDC8(int n, Ent_CDC8 *e) {
    if (D_004A55F8 == 0) {
        *(float*)&D_CDC8[0] = 500.0f;
        *(float*)&D_CDC8[1] = 1.0f;
        *(float*)&D_CDC8[2] = 2400.0f;
        *(float*)&D_CDC8[3] = 0.10000000149011612f;
        *(float*)&D_CDC8[4] = 0.10000000149011612f;
        *(float*)&D_CDC8[5] = 10.0f;
        ((int*)D_CDC8)[6] = 0;
        ((int*)D_CDC8)[7] = 16;
        D_CDC8[8] = 0xFFFFFFFF;
        D_004A55F8 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_CDC8*)((char*)D_CDC8 + 36)) = Tag_CDC8((*(Tag_CDC8*)((char*)D_CDC8 + 36)));
    }
    unsigned buf64[10];
    unsigned *buf = buf64;
    buf64[8] = 0xFFFFFFFF;
    func_003E6574_CDC8(buf, D_CDC8, 40);
    Ent_CDC8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446038[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[8];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_CDC8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_CDC8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_CDC8(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_CDC8;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 5, buf))
        return D_004C9098_CDC8;
    func_00346350_CDC8(cMemMan_alloc(0xB0, D_004896F8_CDC8, 0x20000000, 0), 1, obj, buf);
    return D_004C9098_CDC8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FCFF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_CFF0 __asm__("D_004A3DD8");
extern char **D_004A47B8_CFF0 __asm__("D_004A47B8");
static inline char *refToPtr_CFF0(unsigned i) { return (char*)(i << 2); }
static inline char *conv_CFF0(unsigned i) { if (i == 0) return 0; return refToPtr_CFF0(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00351B40_CFF0(void*, int, void*, void*, int, int) __asm__("func_00351B40");
extern char D_00489708_CFF0[] __asm__("D_00489708");
struct V3_CFF0 { float x, y, z; };
extern V3_CFF0 D_004C9098_CFF0 __asm__("D_004C9098");
struct Tag_CFF0 { char c; Tag_CFF0() {} Tag_CFF0(const Tag_CFF0 &o) : c(o.c) {} };
extern unsigned D_CFF0[] __asm__("D_004FB5E8");
extern int D_004A55FC;
extern const int D_00446060[];
extern "C" void* func_003E6574_CFF0(void*, void*, int) __asm__("func_003E6574");
struct Ent_CFF0 { int idx; int val; int pad; int type; };
extern "C" V3_CFF0 func_002FCFF0(int n, Ent_CFF0 *e) {
    if (D_004A55FC == 0) {
        D_CFF0[0] = 0xFFFFFFFF;
        ((int*)D_CFF0)[1] = 0;
        *(float*)&D_CFF0[2] = 0.10000000149011612f;
        *(float*)&D_CFF0[3] = 1.0f;
        *(float*)&D_CFF0[4] = 2.0f;
        *(float*)&D_CFF0[5] = 600.0f;
        *(float*)&D_CFF0[6] = 600.0f;
        *(float*)&D_CFF0[7] = 300.0f;
        float z = 0.0f;
        *(float*)&D_CFF0[8] = z;
        *(float*)&D_CFF0[9] = z;
        *(float*)&D_CFF0[10] = z;
        *(float*)&D_CFF0[11] = 360.0f;
        *(float*)&D_CFF0[12] = -1.0f;
        D_CFF0[13] = 0xFFFFFFFF;
        ((int*)D_CFF0)[14] = -1;
        D_004A55FC = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_CFF0*)((char*)D_CFF0 + 60)) = Tag_CFF0((*(Tag_CFF0*)((char*)D_CFF0 + 60)));
    }
    unsigned buf64[16];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[13] = 0xFFFFFFFF;
    func_003E6574_CFF0(buf, D_CFF0, 64);
    Ent_CFF0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446060[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_CFF0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_CFF0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_CFF0(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_CFF0;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 11, buf))
        return D_004C9098_CFF0;
    func_00351B40_CFF0(cMemMan_alloc(0x6C0, D_00489708_CFF0, 0x20000000, 0), 1, obj, buf, *(int*)(D_004A3DD8_CFF0 + 0x294), 0);
    return D_004C9098_CFF0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD250);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_D250 __asm__("D_004A3DD8");
extern char **D_004A47B8_D250 __asm__("D_004A47B8");
extern char *D_004A28A8_D250 __asm__("D_004A28A8");
extern "C" void func_00355DB8_D250(void*, void*, int, int) __asm__("func_00355DB8");
struct O_D250 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_D250 { float x, y, z; };
extern V3_D250 D_004C9098_D250 __asm__("D_004C9098");
struct Tag_D250 { char c; Tag_D250() {} Tag_D250(const Tag_D250 &o) : c(o.c) {} };
extern unsigned D_D250[] __asm__("D_004FB628");
extern int D_004A5600;
extern const int D_004460A0[];
extern "C" void* func_003E6574_D250(void*, void*, int) __asm__("func_003E6574");
struct Ent_D250 { int idx; int val; int pad; int type; };
extern "C" V3_D250 func_002FD250(int n, Ent_D250 *e) {
    if (D_004A5600 == 0) {
        D_D250[0] = 0xFFFFFFFF;
        *(float*)&D_D250[1] = 1.0f;
        *(float*)&D_D250[2] = 0.699999988079071f;
        *(float*)&D_D250[3] = 0.5f;
        D_004A5600 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_D250*)((char*)D_D250 + 16)) = Tag_D250((*(Tag_D250*)((char*)D_D250 + 16)));
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_D250(buf, D_D250, 20);
    Ent_D250 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004460A0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_D250 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_D250 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_D250 *p = *(O_D250**)(obj + 0xC);
    if (p) {
        if (p->v16())
            func_00355DB8_D250(p, buf, *(int*)(D_004A3DD8_D250 + 0x298), *(int*)(D_004A3DD8_D250 + 0x294));
    }
    return D_004C9098_D250;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD420);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_D420 __asm__("D_004A3DD8");
extern char **D_004A47B8_D420 __asm__("D_004A47B8");
static inline char *refToPtr_D420(unsigned i) { return (char*)(i << 2); }
static inline char *conv_D420(unsigned i) { if (i == 0) return 0; return refToPtr_D420(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_003578A8_D420(void*, int, void*, void*, int) __asm__("func_003578A8");
void operator_delete(int*);
extern char D_00489718_D420[] __asm__("D_00489718");
extern char D_00489730_D420[] __asm__("D_00489730");
struct V3_D420 { float x, y, z; };
extern V3_D420 D_004C9098_D420 __asm__("D_004C9098");
struct Tag_D420 { char c; Tag_D420() {} Tag_D420(const Tag_D420 &o) : c(o.c) {} };
extern unsigned D_D420[] __asm__("D_004FB640");
extern int D_004A5604;
extern const int D_004460B0[];
extern "C" void* func_003E6574_D420(void*, void*, int) __asm__("func_003E6574");
struct Ent_D420 { int idx; int val; int pad; int type; };
extern "C" V3_D420 func_002FD420(int n, Ent_D420 *e) {
    if (D_004A5604 == 0) {
        ((int*)D_D420)[0] = 1;
        ((int*)D_D420)[1] = 0;
        *(float*)&D_D420[2] = -1.0f;
        *(float*)&D_D420[3] = 1.0f;
        *(float*)&D_D420[4] = 4.0f;
        float z = 0.0f;
        *(float*)&D_D420[5] = z;
        *(float*)&D_D420[6] = z;
        *(float*)&D_D420[7] = z;
        *(float*)&D_D420[8] = z;
        *(float*)&D_D420[9] = z;
        *(float*)&D_D420[10] = z;
        *(float*)&D_D420[11] = z;
        *(float*)&D_D420[12] = z;
        *(float*)&D_D420[13] = z;
        *(float*)&D_D420[14] = z;
        *(float*)&D_D420[15] = z;
        *(float*)&D_D420[16] = z;
        *(float*)&D_D420[17] = z;
        *(float*)&D_D420[18] = z;
        *(float*)&D_D420[19] = z;
        *(float*)&D_D420[20] = z;
        *(float*)&D_D420[21] = z;
        *(float*)&D_D420[22] = z;
        *(float*)&D_D420[23] = z;
        *(float*)&D_D420[24] = z;
        *(float*)&D_D420[25] = z;
        *(float*)&D_D420[26] = z;
        *(float*)&D_D420[27] = z;
        *(float*)&D_D420[28] = z;
        *(float*)&D_D420[29] = z;
        *(float*)&D_D420[30] = z;
        *(float*)&D_D420[31] = z;
        *(float*)&D_D420[32] = z;
        *(float*)&D_D420[33] = 1.0f;
        *(float*)&D_D420[34] = z;
        *(float*)&D_D420[35] = z;
        *(float*)&D_D420[36] = z;
        *(float*)&D_D420[37] = 1.0f;
        *(float*)&D_D420[38] = 1.0f;
        *(float*)&D_D420[39] = 1.0f;
        *(float*)&D_D420[40] = 1.0f;
        *(float*)&D_D420[41] = 1.0f;
        *(float*)&D_D420[42] = z;
        *(float*)&D_D420[43] = z;
        *(float*)&D_D420[44] = z;
        *(float*)&D_D420[45] = 1.0f;
        *(float*)&D_D420[46] = z;
        *(float*)&D_D420[47] = z;
        *(float*)&D_D420[48] = z;
        ((int*)D_D420)[49] = 16;
        ((int*)D_D420)[50] = 0;
        *(float*)&D_D420[51] = z;
        ((int*)D_D420)[52] = 1;
        *(float*)&D_D420[53] = 20.0f;
        D_D420[54] = 0xFFFFFFFF;
        D_004A5604 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_D420*)((char*)D_D420 + 0xDC)) = Tag_D420((*(Tag_D420*)((char*)D_D420 + 0xDC)));
    }
    unsigned *buf = (unsigned*)cMemMan_alloc(0xE0, D_00489718_D420, 0x20000000, 0);
    buf[54] = 0xFFFFFFFF;
    func_003E6574_D420(buf, D_D420, 0xE0);
    Ent_D420 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004460B0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[54];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_D420 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_D420 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_D420(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0) {
        operator_delete((int*)buf);
        return D_004C9098_D420;
    }
    void *p = *(void**)(obj + 0xC);
    if (p) {
        int r = checkActiveNode(p, 13, buf);
        if (r != 0) {
            if (r > 0)
                operator_delete((int*)buf);
            return D_004C9098_D420;
        }
    }
    if (*(float*)&buf[7] > *(float*)&buf[5])
        *(float*)&buf[7] = *(float*)&buf[5];
    func_003578A8_D420(cMemMan_alloc(0x2C, D_00489730_D420, 0x20000000, 0), 1, obj, buf, 0);
    return D_004C9098_D420;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD758);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_D758 __asm__("D_004A3DD8");
extern char **D_004A47B8_D758 __asm__("D_004A47B8");
extern char *D_004A28A8_D758 __asm__("D_004A28A8");
struct V4_D758 { float x, y, z, w; V4_D758() {} V4_D758(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} } __attribute__((aligned(16)));
struct M4_D758 { V4_D758 r[4]; };
struct Sh_D758 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual V4_D758 *v05(); virtual M4_D758 *v06(); };
extern "C" void func_003558B8_D758(void*, V4_D758*) __asm__("func_003558B8");
struct Lvl_D758 { char pad[0x28]; char *sh[1]; };
static inline Sh_D758 *shape_D758(int k) {
    Lvl_D758 *lvl = *(Lvl_D758**)(*(char**)(D_004A28A8_D758 + 0x84) + 0xC);
    char *q = lvl->sh[k];
    return (Sh_D758*)(q ? q + 0x6C0 : 0);
}
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (matrix * vector).
static inline V4_D758 mtxApply_D758(M4_D758 *m, const V4_D758 &v) {
    V4_D758 out;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf8, %1\n"
        "lqc2      $vf4, 0x0(%2)\n"
        "lqc2      $vf5, 0x10(%2)\n"
        "lqc2      $vf6, 0x20(%2)\n"
        "lqc2      $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        ".set pop\n"
        : "=m"(out)
        : "m"(v), "r"(m)
        : "memory");
    return out;
}
// PORT: PS2-only VU0 inline asm (vector add in place).
static inline void vAddTo_D758(V4_D758 &a, const V4_D758 &b) {
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}
struct O_D758 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_D758 { float x, y, z; };
extern V3_D758 D_004C9098_D758 __asm__("D_004C9098");
struct Tag_D758 { char c; Tag_D758() {} Tag_D758(const Tag_D758 &o) : c(o.c) {} };
extern unsigned D_D758[] __asm__("D_004FB720");
extern int D_004A5608;
extern const int D_00446190[];
extern "C" void* func_003E6574_D758(void*, void*, int) __asm__("func_003E6574");
struct Ent_D758 { int idx; int val; int pad; int type; };
extern "C" V3_D758 func_002FD758(int n, Ent_D758 *e) {
    if (D_004A5608 == 0) {
        D_D758[0] = 0xFFFFFFFF;
        ((int*)D_D758)[1] = -1;
        float z = 0.0f;
        *(float*)&D_D758[2] = z;
        *(float*)&D_D758[3] = z;
        *(float*)&D_D758[4] = z;
        D_004A5608 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_D758*)((char*)D_D758 + 20)) = Tag_D758((*(Tag_D758*)((char*)D_D758 + 20)));
    }
    unsigned buf64[6];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_D758(buf, D_D758, 24);
    Ent_D758 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446190[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_D758 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_D758 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_D758 *p = *(O_D758**)(obj + 0xC);
    if (p) {
        if (p->v16()) {
            int k = buf[1];
            if (k != -1) {
                V4_D758 pos = *shape_D758(k)->v05();
                M4_D758 *m = shape_D758(buf[1])->v06();
                vAddTo_D758(pos, mtxApply_D758(m, V4_D758(*(float*)&buf[2], *(float*)&buf[3], *(float*)&buf[4], 0.0f)));
                func_003558B8_D758(p, &pos);
            }
        }
    }
    return D_004C9098_D758;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD9F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_D9F8 __asm__("D_004A3DD8");
extern char **D_004A47B8_D9F8 __asm__("D_004A47B8");
extern char *D_004A28A8_D9F8 __asm__("D_004A28A8");
struct V4_D9F8 { float x, y, z, w; V4_D9F8(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };
extern "C" void func_00355978_D9F8(void*, int, int, V4_D9F8*) __asm__("func_00355978");
struct O_D9F8 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual int v10(int); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
static inline char *refToPtr_D9F8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_D9F8(unsigned i) { if (i == 0) return 0; return refToPtr_D9F8(i); }
struct V3_D9F8 { float x, y, z; };
extern V3_D9F8 D_004C9098_D9F8 __asm__("D_004C9098");
struct Tag_D9F8 { char c; Tag_D9F8() {} Tag_D9F8(const Tag_D9F8 &o) : c(o.c) {} };
extern unsigned D_D9F8[] __asm__("D_004FB738");
extern int D_004A560C;
extern const int D_004461A8[];
extern "C" void* func_003E6574_D9F8(void*, void*, int) __asm__("func_003E6574");
struct Ent_D9F8 { int idx; int val; int pad; int type; };
extern "C" V3_D9F8 func_002FD9F8(int n, Ent_D9F8 *e) {
    if (D_004A560C == 0) {
        D_D9F8[0] = 0xFFFFFFFF;
        D_D9F8[1] = 0xFFFFFFFF;
        ((int*)D_D9F8)[2] = 0;
        float z = 0.0f;
        *(float*)&D_D9F8[3] = z;
        *(float*)&D_D9F8[4] = z;
        *(float*)&D_D9F8[5] = z;
        D_004A560C = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_D9F8*)((char*)D_D9F8 + 24)) = Tag_D9F8((*(Tag_D9F8*)((char*)D_D9F8 + 24)));
    }
    unsigned buf64[7];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574_D9F8(buf, D_D9F8, 28);
    Ent_D9F8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004461A8[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_D9F8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_D9F8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_D9F8(i);
            r = t;
        }
        obj = r;
    }
    unsigned id2 = buf[1];
    if (~id2 != 0) {
        char *s2 = (*(char***)((char*)*D_004A47B8_D9F8 + 8))[id2 & 0xFF];
        unsigned i2;
        char *o2;
        if (!s2 || (i2 = ((unsigned*)*(char**)(s2 + 0x1C))[id2 >> 8] >> 8) == 0)
            o2 = 0;
        else
            o2 = (char*)(i2 << 2);
        O_D9F8 *q = o2 ? *(O_D9F8**)(o2 + 0xC) : 0;
        if (q && !q->v10(6)) {
            O_D9F8 *p = *(O_D9F8**)(obj + 0xC);
            if (p && p->v16()) {
                int k = *(int*)((char*)q + 0x18);
                V4_D9F8 v(*(float*)&buf[3], *(float*)&buf[4], *(float*)&buf[5], 0.0f);
                func_00355978_D9F8(p, k, buf[2], &v);
            }
        }
    }
    return D_004C9098_D9F8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FDC60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_DC60 __asm__("D_004A3DD8");
extern char **D_004A47B8_DC60 __asm__("D_004A47B8");
extern char *D_004A28A8_DC60 __asm__("D_004A28A8");
struct V4_DC60 { float x, y, z, w; V4_DC60(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };
extern "C" void func_00355978_DC60(void*, int, int, V4_DC60*) __asm__("func_00355978");
struct O_DC60 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual int v10(int); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
static inline char *refToPtr_DC60(unsigned i) { return (char*)(i << 2); }
static inline char *conv_DC60(unsigned i) { if (i == 0) return 0; return refToPtr_DC60(i); }
struct V3_DC60 { float x, y, z; };
extern V3_DC60 D_004C9098_DC60 __asm__("D_004C9098");
struct Tag_DC60 { char c; Tag_DC60() {} Tag_DC60(const Tag_DC60 &o) : c(o.c) {} };
extern unsigned D_DC60[] __asm__("D_004FB758");
extern int D_004A5610;
extern const int D_004461C0[];
extern "C" void* func_003E6574_DC60(void*, void*, int) __asm__("func_003E6574");
struct Ent_DC60 { int idx; int val; int pad; int type; };
extern "C" V3_DC60 func_002FDC60(int n, Ent_DC60 *e) {
    if (D_004A5610 == 0) {
        D_DC60[0] = 0xFFFFFFFF;
        D_DC60[1] = 0xFFFFFFFF;
        ((int*)D_DC60)[2] = 0;
        float z = 0.0f;
        *(float*)&D_DC60[3] = z;
        *(float*)&D_DC60[4] = z;
        *(float*)&D_DC60[5] = z;
        D_004A5610 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_DC60*)((char*)D_DC60 + 24)) = Tag_DC60((*(Tag_DC60*)((char*)D_DC60 + 24)));
    }
    unsigned buf64[7];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574_DC60(buf, D_DC60, 28);
    Ent_DC60 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004461C0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_DC60 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_DC60 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_DC60(i);
            r = t;
        }
        obj = r;
    }
    if (~buf[1] != 0) {
        O_DC60 *q = *(O_DC60**)(obj + 0xC);
        if (q && !q->v10(6)) {
            unsigned id2 = buf[1];
            char *s2 = (*(char***)((char*)*D_004A47B8_DC60 + 8))[id2 & 0xFF];
            unsigned i2;
            char *o2;
            if (!s2 || (i2 = ((unsigned*)*(char**)(s2 + 0x1C))[id2 >> 8] >> 8) == 0)
                o2 = 0;
            else
                o2 = (char*)(i2 << 2);
            O_DC60 *p = o2 ? *(O_DC60**)(o2 + 0xC) : 0;
            if (p && p->v16()) {
                int k = *(int*)((char*)q + 0x18);
                V4_DC60 v(*(float*)&buf[3], *(float*)&buf[4], *(float*)&buf[5], 0.0f);
                func_00355978_DC60(p, k, buf[2], &v);
            }
        }
    }
    return D_004C9098_DC60;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FDED0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_DED0 __asm__("D_004A3DD8");
extern char **D_004A47B8_DED0 __asm__("D_004A47B8");
extern char *D_004A28A8_DED0 __asm__("D_004A28A8");
extern "C" void func_00355AD0_DED0(void*, void*) __asm__("func_00355AD0");
struct O_DED0 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
static inline char *refToPtr_DED0(unsigned i) { return (char*)(i << 2); }
static inline char *conv_DED0(unsigned i) { if (i == 0) return 0; return refToPtr_DED0(i); }
struct V3_DED0 { float x, y, z; };
extern V3_DED0 D_004C9098_DED0 __asm__("D_004C9098");
struct Tag_DED0 { char c; Tag_DED0() {} Tag_DED0(const Tag_DED0 &o) : c(o.c) {} };
extern unsigned D_DED0[] __asm__("D_004FB778");
extern int D_004A5614;
extern const int D_004461D8[];
extern "C" void* func_003E6574_DED0(void*, void*, int) __asm__("func_003E6574");
struct Ent_DED0 { int idx; int val; int pad; int type; };
extern "C" V3_DED0 func_002FDED0(int n, Ent_DED0 *e) {
    if (D_004A5614 == 0) {
        D_DED0[0] = 0xFFFFFFFF;
        D_DED0[1] = 0xFFFFFFFF;
        ((int*)D_DED0)[2] = 1;
        ((int*)D_DED0)[3] = 3;
        *(float*)&D_DED0[4] = 20.0f;
        float z = 0.0f;
        *(float*)&D_DED0[5] = z;
        *(float*)&D_DED0[6] = z;
        *(float*)&D_DED0[7] = z;
        ((int*)D_DED0)[8] = 1;
        *(float*)&D_DED0[9] = z;
        *(float*)&D_DED0[10] = z;
        D_004A5614 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_DED0*)((char*)D_DED0 + 44)) = Tag_DED0((*(Tag_DED0*)((char*)D_DED0 + 44)));
    }
    unsigned buf64[12];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574_DED0(buf, D_DED0, 48);
    Ent_DED0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004461D8[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_DED0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_DED0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_DED0(i);
            r = t;
        }
        obj = r;
    }
    if (~buf[1] != 0) {
        O_DED0 *p = *(O_DED0**)(obj + 0xC);
        if (p) {
            if (p->v16())
                func_00355AD0_DED0(p, buf);
        }
    }
    return D_004C9098_DED0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE0C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_E0C0 __asm__("D_004A3DD8");
extern char **D_004A47B8_E0C0 __asm__("D_004A47B8");
extern char *D_004A28A8_E0C0 __asm__("D_004A28A8");
extern "C" void cMoveNode_addSpline_E0C0(void*, void*) __asm__("cMoveNode_addSpline");
struct O_E0C0 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
static inline char *refToPtr_E0C0(unsigned i) { return (char*)(i << 2); }
static inline char *conv_E0C0(unsigned i) { if (i == 0) return 0; return refToPtr_E0C0(i); }
struct V3_E0C0 { float x, y, z; };
extern V3_E0C0 D_004C9098_E0C0 __asm__("D_004C9098");
struct Tag_E0C0 { char c; Tag_E0C0() {} Tag_E0C0(const Tag_E0C0 &o) : c(o.c) {} };
extern unsigned D_E0C0[] __asm__("D_004FB7A8");
extern int D_004A5618;
extern const int D_00446208[];
extern "C" void* func_003E6574_E0C0(void*, void*, int) __asm__("func_003E6574");
struct Ent_E0C0 { int idx; int val; int pad; int type; };
extern "C" V3_E0C0 func_002FE0C0(int n, Ent_E0C0 *e) {
    if (D_004A5618 == 0) {
        D_E0C0[0] = 0xFFFFFFFF;
        D_E0C0[1] = 0xFFFFFFFF;
        ((int*)D_E0C0)[2] = 3;
        *(float*)&D_E0C0[3] = 20.0f;
        float z = 0.0f;
        *(float*)&D_E0C0[4] = z;
        *(float*)&D_E0C0[5] = z;
        *(float*)&D_E0C0[6] = 1.0f;
        *(float*)&D_E0C0[7] = z;
        *(float*)&D_E0C0[8] = z;
        *(float*)&D_E0C0[9] = z;
        ((int*)D_E0C0)[10] = 1;
        ((int*)D_E0C0)[11] = 2;
        D_004A5618 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_E0C0*)((char*)D_E0C0 + 48)) = Tag_E0C0((*(Tag_E0C0*)((char*)D_E0C0 + 48)));
    }
    unsigned buf64[13];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574_E0C0(buf, D_E0C0, 52);
    Ent_E0C0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446208[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_E0C0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_E0C0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_E0C0(i);
            r = t;
        }
        obj = r;
    }
    if (~buf[1] != 0) {
        O_E0C0 *p = *(O_E0C0**)(obj + 0xC);
        if (p) {
            if (p->v16())
                cMoveNode_addSpline_E0C0(p, buf);
        }
    }
    return D_004C9098_E0C0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE2C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_E2C0 __asm__("D_004A3DD8");
extern char **D_004A47B8_E2C0 __asm__("D_004A47B8");
extern char *D_004A28A8_E2C0 __asm__("D_004A28A8");
extern "C" void func_00355B90_E2C0(void*, void*) __asm__("func_00355B90");
struct O_E2C0 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_E2C0 { float x, y, z; };
extern V3_E2C0 D_004C9098_E2C0 __asm__("D_004C9098");
struct Tag_E2C0 { char c; Tag_E2C0() {} Tag_E2C0(const Tag_E2C0 &o) : c(o.c) {} };
extern unsigned D_E2C0[] __asm__("D_004FB7E0");
extern int D_004A561C;
extern const int D_00446238[];
extern "C" void* func_003E6574_E2C0(void*, void*, int) __asm__("func_003E6574");
struct Ent_E2C0 { int idx; int val; int pad; int type; };
extern "C" V3_E2C0 func_002FE2C0(int n, Ent_E2C0 *e) {
    if (D_004A561C == 0) {
        D_E2C0[0] = 0xFFFFFFFF;
        ((int*)D_E2C0)[1] = 5;
        float z = 0.0f;
        *(float*)&D_E2C0[2] = z;
        *(float*)&D_E2C0[3] = z;
        *(float*)&D_E2C0[4] = 0.016666699200868607f;
        *(float*)&D_E2C0[5] = 0.016666699200868607f;
        *(float*)&D_E2C0[6] = 1.0f;
        *(float*)&D_E2C0[7] = z;
        *(float*)&D_E2C0[8] = z;
        *(float*)&D_E2C0[9] = z;
        *(float*)&D_E2C0[10] = z;
        *(float*)&D_E2C0[11] = 1.0f;
        D_004A561C = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_E2C0*)((char*)D_E2C0 + 48)) = Tag_E2C0((*(Tag_E2C0*)((char*)D_E2C0 + 48)));
    }
    unsigned buf64[13];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_E2C0(buf, D_E2C0, 52);
    Ent_E2C0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446238[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_E2C0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_E2C0 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_E2C0 *p = *(O_E2C0**)(obj + 0xC);
    if (p) {
        if (p->v16())
            func_00355B90_E2C0(p, buf);
    }
    return D_004C9098_E2C0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE4A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_E4A8 __asm__("D_004A3DD8");
extern char **D_004A47B8_E4A8 __asm__("D_004A47B8");
extern char *D_004A28A8_E4A8 __asm__("D_004A28A8");
extern "C" void func_00355BF0_E4A8(void*, void*) __asm__("func_00355BF0");
struct O_E4A8 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_E4A8 { float x, y, z; };
extern V3_E4A8 D_004C9098_E4A8 __asm__("D_004C9098");
struct Tag_E4A8 { char c; Tag_E4A8() {} Tag_E4A8(const Tag_E4A8 &o) : c(o.c) {} };
extern unsigned D_E4A8[] __asm__("D_004FB818");
extern int D_004A5620;
extern const int D_00446268[];
extern "C" void* func_003E6574_E4A8(void*, void*, int) __asm__("func_003E6574");
struct Ent_E4A8 { int idx; int val; int pad; int type; };
extern "C" V3_E4A8 func_002FE4A8(int n, Ent_E4A8 *e) {
    if (D_004A5620 == 0) {
        D_E4A8[0] = 0xFFFFFFFF;
        ((int*)D_E4A8)[1] = 0;
        ((int*)D_E4A8)[2] = 0;
        ((int*)D_E4A8)[3] = 0;
        *(float*)&D_E4A8[4] = 2.0f;
        D_004A5620 = 1;
        (*(Tag_E4A8*)((char*)D_E4A8 + 20)) = Tag_E4A8((*(Tag_E4A8*)((char*)D_E4A8 + 20)));
    }
    unsigned buf64[6];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_E4A8(buf, D_E4A8, 24);
    Ent_E4A8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446268[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_E4A8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_E4A8 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_E4A8 *p = *(O_E4A8**)(obj + 0xC);
    if (p) {
        if (p->v16())
            func_00355BF0_E4A8(p, buf);
    }
    return D_004C9098_E4A8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE668);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_E668 __asm__("D_004A3DD8");
extern char **D_004A47B8_E668 __asm__("D_004A47B8");
extern char *D_004A28A8_E668 __asm__("D_004A28A8");
extern "C" void func_00355C50_E668(void*, void*) __asm__("func_00355C50");
struct O_E668 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_E668 { float x, y, z; };
extern V3_E668 D_004C9098_E668 __asm__("D_004C9098");
struct Tag_E668 { char c; Tag_E668() {} Tag_E668(const Tag_E668 &o) : c(o.c) {} };
extern unsigned D_E668[] __asm__("D_004FB830");
extern int D_004A5624;
extern const int D_00446280[];
extern "C" void* func_003E6574_E668(void*, void*, int) __asm__("func_003E6574");
struct Ent_E668 { int idx; int val; int pad; int type; };
extern "C" V3_E668 func_002FE668(int n, Ent_E668 *e) {
    if (D_004A5624 == 0) {
        D_E668[0] = 0xFFFFFFFF;
        ((int*)D_E668)[1] = 1;
        float z = 0.0f;
        *(float*)&D_E668[2] = z;
        *(float*)&D_E668[3] = 0.10000000149011612f;
        *(float*)&D_E668[4] = 20.0f;
        *(float*)&D_E668[5] = z;
        *(float*)&D_E668[6] = z;
        *(float*)&D_E668[7] = 1.0f;
        D_004A5624 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_E668*)((char*)D_E668 + 32)) = Tag_E668((*(Tag_E668*)((char*)D_E668 + 32)));
    }
    unsigned buf64[9];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_E668(buf, D_E668, 36);
    Ent_E668 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446280[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_E668 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_E668 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_E668 *p = *(O_E668**)(obj + 0xC);
    if (p) {
        if (p->v16())
            func_00355C50_E668(p, buf);
    }
    return D_004C9098_E668;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", cViewer_addParticle);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_E840 __asm__("D_004A3DD8");
extern char **D_004A47B8_E840 __asm__("D_004A47B8");
static inline char *refToPtr_E840(unsigned i) { return (char*)(i << 2); }
static inline char *conv_E840(unsigned i) { if (i == 0) return 0; return refToPtr_E840(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_003578A8_E840(void*, int, void*, void*, int) __asm__("func_003578A8");
void operator_delete(int*);
extern char D_00489740_E840[] __asm__("D_00489740");
extern char D_00489730_E840[] __asm__("D_00489730");
struct V4_E840 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sh_E840 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual V4_E840 *v05(); };
struct Ent_E840x { char pad[0x18]; char *obj; };
struct Lvl_E840 { char pad[0x40]; Ent_E840x *a1[12]; Ent_E840x *a2[3]; int n1; int pad80[2]; int n2; };
struct O_E840 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual char *v24(); };
extern char *D_004A28A4_E840 __asm__("D_004A28A4");
extern char *D_004A28A8_E840 __asm__("D_004A28A8");
extern "C" void cMoveNode_addParticle_E840(void*, void*) __asm__("cMoveNode_addParticle");
// PORT: PS2-only VU0 inline asm (vector subtract).
static inline V4_E840 vSub_E840(const V4_E840 &a, const V4_E840 &b) {
    V4_E840 r;
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
static inline float vLen_E840(const V4_E840 &v) {
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
static inline Lvl_E840 *lvl_E840() { return *(Lvl_E840**)(*(char**)(D_004A28A8_E840 + 0x84) + 0xC); }
static inline Sh_E840 *shape_E840(Ent_E840x *e) { return (Sh_E840*)(e->obj + 0x6C0); }
static inline int nearViewer_E840(const V4_E840 &pos) {
    int notEdit = *(int*)(D_004A28A4_E840 + 0x550) != 2;
    if (notEdit)
        return 1;
    int n = lvl_E840()->n1;
    for (int i = 0; i < n; i++) {
        V4_E840 d = vSub_E840(pos, *shape_E840(lvl_E840()->a1[i])->v05());
        if (vLen_E840(d) < 30000.0f)
            return 1;
    }
    n = lvl_E840()->n2;
    for (int i = 0; i < n; i++) {
        V4_E840 d = vSub_E840(pos, *shape_E840(lvl_E840()->a2[i])->v05());
        if (vLen_E840(d) < 30000.0f)
            return 1;
    }
    return 0;
}
struct V3_E840 { float x, y, z; };
extern V3_E840 D_004C9098_E840 __asm__("D_004C9098");
struct Tag_E840 { char c; Tag_E840() {} Tag_E840(const Tag_E840 &o) : c(o.c) {} };
extern unsigned D_E840[] __asm__("D_004FB858");
extern int D_004A5628;
extern const int D_004462A0[];
extern "C" void* func_003E6574_E840(void*, void*, int) __asm__("func_003E6574");
struct Ent_E840 { int idx; int val; int pad; int type; };
extern "C" V3_E840 cViewer_addParticle(int n, Ent_E840 *e) {
    if (D_004A5628 == 0) {
        ((int*)D_E840)[0] = 1;
        ((int*)D_E840)[1] = 0;
        *(float*)&D_E840[2] = -1.0f;
        *(float*)&D_E840[3] = 1.0f;
        *(float*)&D_E840[4] = 4.0f;
        float z = 0.0f;
        *(float*)&D_E840[5] = z;
        *(float*)&D_E840[6] = z;
        *(float*)&D_E840[7] = z;
        *(float*)&D_E840[8] = z;
        *(float*)&D_E840[9] = z;
        *(float*)&D_E840[10] = z;
        *(float*)&D_E840[11] = z;
        *(float*)&D_E840[12] = z;
        *(float*)&D_E840[13] = z;
        *(float*)&D_E840[14] = z;
        *(float*)&D_E840[15] = z;
        *(float*)&D_E840[16] = z;
        *(float*)&D_E840[17] = z;
        *(float*)&D_E840[18] = z;
        *(float*)&D_E840[19] = z;
        *(float*)&D_E840[20] = z;
        *(float*)&D_E840[21] = z;
        *(float*)&D_E840[22] = z;
        *(float*)&D_E840[23] = z;
        *(float*)&D_E840[24] = z;
        *(float*)&D_E840[25] = z;
        *(float*)&D_E840[26] = z;
        *(float*)&D_E840[27] = z;
        *(float*)&D_E840[28] = z;
        *(float*)&D_E840[29] = z;
        *(float*)&D_E840[30] = z;
        *(float*)&D_E840[31] = z;
        *(float*)&D_E840[32] = z;
        *(float*)&D_E840[33] = 1.0f;
        *(float*)&D_E840[34] = z;
        *(float*)&D_E840[35] = z;
        *(float*)&D_E840[36] = z;
        *(float*)&D_E840[37] = 1.0f;
        *(float*)&D_E840[38] = 1.0f;
        *(float*)&D_E840[39] = 1.0f;
        *(float*)&D_E840[40] = 1.0f;
        *(float*)&D_E840[41] = 1.0f;
        *(float*)&D_E840[42] = z;
        *(float*)&D_E840[43] = z;
        *(float*)&D_E840[44] = z;
        *(float*)&D_E840[45] = 1.0f;
        *(float*)&D_E840[46] = z;
        *(float*)&D_E840[47] = z;
        *(float*)&D_E840[48] = z;
        ((int*)D_E840)[49] = 16;
        ((int*)D_E840)[50] = 0;
        *(float*)&D_E840[51] = z;
        ((int*)D_E840)[52] = 1;
        *(float*)&D_E840[53] = 20.0f;
        D_E840[54] = 0xFFFFFFFF;
        D_004A5628 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_E840*)((char*)D_E840 + 0xDC)) = Tag_E840((*(Tag_E840*)((char*)D_E840 + 0xDC)));
    }
    unsigned *buf = (unsigned*)cMemMan_alloc(0xE0, D_00489740_E840, 0x20000000, 0);
    buf[54] = 0xFFFFFFFF;
    func_003E6574_E840(buf, D_E840, 0xE0);
    Ent_E840 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004462A0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    if (*(float*)&buf[7] > *(float*)&buf[5])
        *(float*)&buf[7] = *(float*)&buf[5];
    unsigned id = buf[54];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_E840 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_E840 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_E840(i);
            r = t;
        }
        obj = r;
    }
    O_E840 *p = *(O_E840**)(obj + 0xC);
    if (p) {
        if (p->v16()) {
            V4_E840 pos = *(V4_E840*)(p->v24() + 0x30);
            if (nearViewer_E840(pos)) {
                cMoveNode_addParticle_E840(p, buf);
                return D_004C9098_E840;
            }
        }
    } else {
        V4_E840 pos = *(V4_E840*)(obj + 0x40);
        if (nearViewer_E840(pos)) {
            func_003578A8_E840(cMemMan_alloc(0x2C, D_00489730_E840, 0x20000000, 0), 1, obj, buf, 0);
            return D_004C9098_E840;
        }
    }
    operator_delete((int*)buf);
    return D_004C9098_E840;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FEE98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_EE98 __asm__("D_004A3DD8");
extern char **D_004A47B8_EE98 __asm__("D_004A47B8");
static inline char *refToPtr_EE98(unsigned i) { return (char*)(i << 2); }
static inline char *conv_EE98(unsigned i) { if (i == 0) return 0; return refToPtr_EE98(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
struct V4_EE98 { float x, y, z, w; V4_EE98(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };
struct O_EE98 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
extern "C" void cMoveNode_addDynamicParticle_EE98(void*, void*, int, V4_EE98*) __asm__("cMoveNode_addDynamicParticle");
void operator_delete(int*);
extern char D_00489750_EE98[] __asm__("D_00489750");
struct V3_EE98 { float x, y, z; };
extern V3_EE98 D_004C9098_EE98 __asm__("D_004C9098");
struct Tag_EE98 { char c; Tag_EE98() {} Tag_EE98(const Tag_EE98 &o) : c(o.c) {} };
extern unsigned D_EE98[] __asm__("D_004FB938");
extern int D_004A562C;
extern const int D_00446380[];
extern "C" void* func_003E6574_EE98(void*, void*, int) __asm__("func_003E6574");
struct Ent_EE98 { int idx; int val; int pad; int type; };
extern "C" V3_EE98 func_002FEE98(int n, Ent_EE98 *e) {
    if (D_004A562C == 0) {
        ((int*)D_EE98)[0] = 1;
        ((int*)D_EE98)[1] = 0;
        *(float*)&D_EE98[2] = -1.0f;
        *(float*)&D_EE98[3] = 1.0f;
        *(float*)&D_EE98[4] = 4.0f;
        float z = 0.0f;
        *(float*)&D_EE98[5] = z;
        *(float*)&D_EE98[6] = z;
        *(float*)&D_EE98[7] = z;
        *(float*)&D_EE98[8] = z;
        *(float*)&D_EE98[9] = z;
        *(float*)&D_EE98[10] = z;
        *(float*)&D_EE98[11] = z;
        *(float*)&D_EE98[12] = z;
        *(float*)&D_EE98[13] = z;
        *(float*)&D_EE98[14] = z;
        *(float*)&D_EE98[15] = z;
        *(float*)&D_EE98[16] = z;
        *(float*)&D_EE98[17] = z;
        *(float*)&D_EE98[18] = z;
        *(float*)&D_EE98[19] = z;
        *(float*)&D_EE98[20] = z;
        *(float*)&D_EE98[21] = z;
        *(float*)&D_EE98[22] = z;
        *(float*)&D_EE98[23] = z;
        *(float*)&D_EE98[24] = z;
        *(float*)&D_EE98[25] = z;
        *(float*)&D_EE98[26] = z;
        *(float*)&D_EE98[27] = z;
        *(float*)&D_EE98[28] = z;
        *(float*)&D_EE98[29] = z;
        *(float*)&D_EE98[30] = z;
        *(float*)&D_EE98[31] = z;
        *(float*)&D_EE98[32] = z;
        *(float*)&D_EE98[33] = 1.0f;
        *(float*)&D_EE98[34] = z;
        *(float*)&D_EE98[35] = z;
        *(float*)&D_EE98[36] = z;
        *(float*)&D_EE98[37] = 1.0f;
        *(float*)&D_EE98[38] = 1.0f;
        *(float*)&D_EE98[39] = 1.0f;
        *(float*)&D_EE98[40] = 1.0f;
        *(float*)&D_EE98[41] = 1.0f;
        *(float*)&D_EE98[42] = z;
        *(float*)&D_EE98[43] = z;
        *(float*)&D_EE98[44] = z;
        *(float*)&D_EE98[45] = 1.0f;
        *(float*)&D_EE98[46] = z;
        *(float*)&D_EE98[47] = z;
        *(float*)&D_EE98[48] = z;
        ((int*)D_EE98)[49] = 16;
        ((int*)D_EE98)[50] = 0;
        *(float*)&D_EE98[51] = z;
        ((int*)D_EE98)[52] = 1;
        *(float*)&D_EE98[53] = 20.0f;
        D_EE98[54] = 0xFFFFFFFF;
        ((int*)D_EE98)[55] = 0;
        *(float*)&D_EE98[56] = z;
        *(float*)&D_EE98[57] = z;
        *(float*)&D_EE98[58] = z;
        D_004A562C = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_EE98*)((char*)D_EE98 + 0xEC)) = Tag_EE98((*(Tag_EE98*)((char*)D_EE98 + 0xEC)));
    }
    unsigned *buf = (unsigned*)cMemMan_alloc(0xF0, D_00489750_EE98, 0x20000000, 0);
    buf[54] = 0xFFFFFFFF;
    func_003E6574_EE98(buf, D_EE98, 0xF0);
    Ent_EE98 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446380[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    if (*(float*)&buf[7] > *(float*)&buf[5])
        *(float*)&buf[7] = *(float*)&buf[5];
    unsigned id = buf[54];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_EE98 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_EE98 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_EE98 *p = *(O_EE98**)(obj + 0xC);
    if (p && p->v16()) {
        float one = 1.0f;
        V4_EE98 v(*(float*)&buf[56], *(float*)&buf[57], *(float*)&buf[58], one);
        cMoveNode_addDynamicParticle_EE98(p, buf, buf[55], &v);
        return D_004C9098_EE98;
    }
    operator_delete((int*)buf);
    return D_004C9098_EE98;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF1C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_F1C8 __asm__("D_004A3DD8");
extern char **D_004A47B8_F1C8 __asm__("D_004A47B8");
extern char *D_004A28A8_F1C8 __asm__("D_004A28A8");
extern "C" void func_00355E38_F1C8(void*, void*) __asm__("func_00355E38");
struct O_F1C8 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_F1C8 { float x, y, z; };
extern V3_F1C8 D_004C9098_F1C8 __asm__("D_004C9098");
struct Tag_F1C8 { char c; Tag_F1C8() {} Tag_F1C8(const Tag_F1C8 &o) : c(o.c) {} };
extern unsigned D_F1C8[] __asm__("D_004FBA28");
extern int D_004A5630;
extern const int D_00446470[];
extern "C" void* func_003E6574_F1C8(void*, void*, int) __asm__("func_003E6574");
struct Ent_F1C8 { int idx; int val; int pad; int type; };
extern "C" V3_F1C8 func_002FF1C8(int n, Ent_F1C8 *e) {
    if (D_004A5630 == 0) {
        D_F1C8[0] = 0xFFFFFFFF;
        D_F1C8[1] = 0xFFFFFFFF;
        ((int*)D_F1C8)[2] = -1;
        D_004A5630 = 1;
        (*(Tag_F1C8*)((char*)D_F1C8 + 12)) = Tag_F1C8((*(Tag_F1C8*)((char*)D_F1C8 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574_F1C8(buf, D_F1C8, 16);
    Ent_F1C8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446470[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_F1C8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_F1C8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (~buf[1] != 0) {
        O_F1C8 *p = *(O_F1C8**)(obj + 0xC);
        if (p) {
            if (p->v16())
                func_00355E38_F1C8(p, buf);
        }
    }
    return D_004C9098_F1C8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF390);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_F390 __asm__("D_004A3DD8");
extern char **D_004A47B8_F390 __asm__("D_004A47B8");
static inline char *refToPtr_F390(unsigned i) { return (char*)(i << 2); }
static inline char *conv_F390(unsigned i) { if (i == 0) return 0; return refToPtr_F390(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00348D98_F390(void*, void*, void*) __asm__("func_00348D98");
extern char D_00489768_F390[] __asm__("D_00489768");
struct V3_F390 { float x, y, z; };
extern V3_F390 D_004C9098_F390 __asm__("D_004C9098");
struct Tag_F390 { char c; Tag_F390() {} Tag_F390(const Tag_F390 &o) : c(o.c) {} };
extern unsigned D_F390[] __asm__("D_004FBA38");
extern int D_004A5634;
extern const int D_00446480[];
extern "C" void* func_003E6574_F390(void*, void*, int) __asm__("func_003E6574");
struct Ent_F390 { int idx; int val; int pad; int type; };
extern "C" V3_F390 func_002FF390(int n, Ent_F390 *e) {
    if (D_004A5634 == 0) {
        D_F390[0] = 0xFFFFFFFF;
        D_F390[1] = 0xFFFFFFFF;
        D_F390[2] = 0xFFFFFFFF;
        D_F390[3] = 0xFFFFFFFF;
        D_F390[4] = 0xFFFFFFFF;
        D_F390[5] = 0xFFFFFFFF;
        D_F390[6] = 0xFFFFFFFF;
        D_F390[7] = 0xFFFFFFFF;
        D_F390[8] = 0xFFFFFFFF;
        ((int*)D_F390)[9] = -1;
        ((int*)D_F390)[10] = -1;
        ((int*)D_F390)[11] = -1;
        ((int*)D_F390)[12] = -1;
        ((int*)D_F390)[13] = -1;
        ((int*)D_F390)[14] = -1;
        ((int*)D_F390)[15] = -1;
        ((int*)D_F390)[16] = -1;
        ((int*)D_F390)[17] = 1;
        *(float*)&D_F390[18] = 0.5f;
        *(float*)&D_F390[19] = 0.5f;
        *(float*)&D_F390[20] = 1.0f;
        D_004A5634 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_F390*)((char*)D_F390 + 84)) = Tag_F390((*(Tag_F390*)((char*)D_F390 + 84)));
    }
    unsigned buf64[22];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    buf64[2] = 0xFFFFFFFF;
    buf64[3] = 0xFFFFFFFF;
    buf64[4] = 0xFFFFFFFF;
    buf64[5] = 0xFFFFFFFF;
    buf64[6] = 0xFFFFFFFF;
    buf64[7] = 0xFFFFFFFF;
    buf64[8] = 0xFFFFFFFF;
    func_003E6574_F390(buf, D_F390, 88);
    Ent_F390 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446480[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_F390 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_F390 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_F390(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_F390;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 20, buf))
        return D_004C9098_F390;
    func_00348D98_F390(cMemMan_alloc(0x80, D_00489768_F390, 0x20000000, 0), obj, buf);
    return D_004C9098_F390;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF5E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_F5E8 __asm__("D_004A3DD8");
extern char **D_004A47B8_F5E8 __asm__("D_004A47B8");
static inline char *refToPtr_F5E8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_F5E8(unsigned i) { if (i == 0) return 0; return refToPtr_F5E8(i); }
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00349B48_F5E8(void*, void*, void*) __asm__("func_00349B48");
extern char D_00489778_F5E8[] __asm__("D_00489778");
struct V3_F5E8 { float x, y, z; };
extern V3_F5E8 D_004C9098_F5E8 __asm__("D_004C9098");
struct Tag_F5E8 { char c; Tag_F5E8() {} Tag_F5E8(const Tag_F5E8 &o) : c(o.c) {} };
extern unsigned D_F5E8[] __asm__("D_004FBA90");
extern int D_004A5638;
extern const int D_004464D8[];
extern "C" void* func_003E6574_F5E8(void*, void*, int) __asm__("func_003E6574");
struct Ent_F5E8 { int idx; int val; int pad; int type; };
extern "C" V3_F5E8 func_002FF5E8(int n, Ent_F5E8 *e) {
    if (D_004A5638 == 0) {
        D_F5E8[0] = 0xFFFFFFFF;
        D_F5E8[1] = 0xFFFFFFFF;
        D_F5E8[2] = 0xFFFFFFFF;
        D_F5E8[3] = 0xFFFFFFFF;
        D_F5E8[4] = 0xFFFFFFFF;
        D_F5E8[5] = 0xFFFFFFFF;
        D_F5E8[6] = 0xFFFFFFFF;
        D_F5E8[7] = 0xFFFFFFFF;
        D_F5E8[8] = 0xFFFFFFFF;
        ((int*)D_F5E8)[9] = -1;
        ((int*)D_F5E8)[10] = -1;
        ((int*)D_F5E8)[11] = -1;
        ((int*)D_F5E8)[12] = -1;
        ((int*)D_F5E8)[13] = -1;
        ((int*)D_F5E8)[14] = -1;
        ((int*)D_F5E8)[15] = -1;
        ((int*)D_F5E8)[16] = -1;
        ((int*)D_F5E8)[17] = 1;
        *(float*)&D_F5E8[18] = 0.5f;
        *(float*)&D_F5E8[19] = 0.5f;
        *(float*)&D_F5E8[20] = 1.0f;
        D_004A5638 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_F5E8*)((char*)D_F5E8 + 84)) = Tag_F5E8((*(Tag_F5E8*)((char*)D_F5E8 + 84)));
    }
    unsigned buf64[22];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    buf64[2] = 0xFFFFFFFF;
    buf64[3] = 0xFFFFFFFF;
    buf64[4] = 0xFFFFFFFF;
    buf64[5] = 0xFFFFFFFF;
    buf64[6] = 0xFFFFFFFF;
    buf64[7] = 0xFFFFFFFF;
    buf64[8] = 0xFFFFFFFF;
    func_003E6574_F5E8(buf, D_F5E8, 88);
    Ent_F5E8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004464D8[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_F5E8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_F5E8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_F5E8(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_F5E8;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 21, buf))
        return D_004C9098_F5E8;
    *(float*)&buf[20] *= 0.0010000000474974513f;
    func_00349B48_F5E8(cMemMan_alloc(0x80, D_00489778_F5E8, 0x20000000, 0), obj, buf);
    return D_004C9098_F5E8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF850);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_F850 { char c; Flag_F850() {} Flag_F850(const Flag_F850& o) : c(o.c) {} };
struct Ent_F850 { int idx; int val; int pad; int kind; };
struct R12_F850 { int a; int b; int c; };
extern R12_F850 D_004C9098_F850 __asm__("D_004C9098");

extern int D_00446530_F850[] __asm__("D_00446530");
extern "C" void func_0010F1C0(int, int, float);
extern int* D_004A3DD8_F850 __asm__("D_004A3DD8");
extern char* D_004A28A8_F850 __asm__("D_004A28A8");
extern int D_004A563C_F850 __asm__("D_004A563C");
struct T12_F850 { int a; int b; int e; Flag_F850 f; };
extern T12_F850 D_004FBAE8_F850 __asm__("D_004FBAE8");
extern "C" R12_F850 func_002FF850(int n, Ent_F850* e) {
    if (D_004A563C_F850 == 0) {
        D_004FBAE8_F850.a = -1;
        D_004A563C_F850 = 1;
        D_004FBAE8_F850.b = 0;
        D_004FBAE8_F850.e = 0;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBAE8_F850.f = Flag_F850(D_004FBAE8_F850.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBAE8_F850, 16);
    Ent_F850* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_00446530_F850[k] && D_00446530_F850[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    if (vp[0] == -1)
        vp[0] = *D_004A3DD8_F850;
    char* o = *(char**)(D_004A28A8_F850 + 0x84);
    char* base = *(char**)(o + 0xC);
    func_0010F1C0(*(int*)(base + (vp[0] << 2) + 0x28), vp[1], *(float*)&vp[2]);
    return D_004C9098_F850;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF9A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_F9A8 __asm__("D_004A3DD8");
extern char **D_004A47B8_F9A8 __asm__("D_004A47B8");
extern char *D_004A28A8_F9A8 __asm__("D_004A28A8");
static inline char *look_F9A8(unsigned id) {
    if (~id == 0)
        return *(char**)(D_004A3DD8_F9A8 + 0x290);
    char *s = (*(char***)((char*)*D_004A47B8_F9A8 + 8))[id & 0xFF];
    unsigned i;
    if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}

struct O_F9A8 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(int, float); };
struct V3_F9A8 { float x, y, z; };
extern V3_F9A8 D_004C9098_F9A8 __asm__("D_004C9098");
struct Tag_F9A8 { char c; Tag_F9A8() {} Tag_F9A8(const Tag_F9A8 &o) : c(o.c) {} };
extern unsigned D_F9A8[] __asm__("D_004FBAF8");
extern int D_004A5640;
extern const int D_00446540[];
extern "C" void* func_003E6574_F9A8(void*, void*, int) __asm__("func_003E6574");
struct Ent_F9A8 { int idx; int val; int pad; int type; };
extern "C" V3_F9A8 func_002FF9A8(int n, Ent_F9A8 *e) {
    if (D_004A5640 == 0) {
        D_F9A8[0] = 0xFFFFFFFF;
        ((int*)D_F9A8)[1] = -1;
        ((int*)D_F9A8)[2] = 0;
        D_004A5640 = 1;
        (*(Tag_F9A8*)((char*)D_F9A8 + 12)) = Tag_F9A8((*(Tag_F9A8*)((char*)D_F9A8 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_F9A8(buf, D_F9A8, 16);
    Ent_F9A8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446540[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = look_F9A8(buf[0]);
    O_F9A8 *p = *(O_F9A8**)(obj + 0xC);
    if (p)
        p->v36(buf[1], *(float*)&buf[2]);
    return D_004C9098_F9A8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FFB50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_FB50 { char c; Flag_FB50() {} Flag_FB50(const Flag_FB50& o) : c(o.c) {} };
extern unsigned D_004A5648_FB50 __asm__("D_004A5648");
extern Flag_FB50 D_004A564C_FB50 __asm__("D_004A564C");
extern int D_004A5650_FB50 __asm__("D_004A5650");
extern int D_004A3C10_FB50[2] __asm__("D_004A3C10");
extern char *D_004A3DD8_FB50 __asm__("D_004A3DD8");
extern char **D_004A47B8_FB50 __asm__("D_004A47B8");
static inline char *refToPtr_FB50(unsigned i) { return (char*)(i << 2); }
static inline char *conv_FB50(unsigned i) { if (i == 0) return 0; return refToPtr_FB50(i); }
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00350E90_FB50(void*, void*) __asm__("func_00350E90");
extern char D_004A3C18_FB50[] __asm__("D_004A3C18");
struct O_FB50 { int p0, p1, p2; virtual void v01(int); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual int v10(int); };
struct V3_FB50 { float x, y, z; };
extern V3_FB50 D_004C9098_FB50 __asm__("D_004C9098");
extern "C" void* func_003E6574_FB50(void*, void*, int) __asm__("func_003E6574");
struct Ent_FB50 { int idx; int val; int pad; int type; };
extern "C" V3_FB50 func_002FFB50(int n, Ent_FB50 *e) {
    if (D_004A5650_FB50 == 0) {
        D_004A5648_FB50 = 0xFFFFFFFF;
        D_004A5650_FB50 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A564C_FB50 = Flag_FB50(D_004A564C_FB50);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_FB50(buf, &D_004A5648_FB50, 8);
    Ent_FB50 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004A3C10_FB50[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_FB50 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_FB50 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_FB50(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098_FB50;
    O_FB50 *p = *(O_FB50**)(obj + 0xC);
    if (p) {
        if (p->v10(16) || p->v10(6))
            return D_004C9098_FB50;
        p->v01(3);
    }
    func_00350E90_FB50(cMemMan_alloc(0x1C, D_004A3C18_FB50, 0x20000000, 0), obj);
    return D_004C9098_FB50;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FFD58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_FD58 __asm__("D_004A3DD8");
extern char **D_004A47B8_FD58 __asm__("D_004A47B8");
extern char *D_004A28A8_FD58 __asm__("D_004A28A8");
static inline char *look_FD58(unsigned id) {
    if (~id == 0)
        return *(char**)(D_004A3DD8_FD58 + 0x290);
    char *s = (*(char***)((char*)*D_004A47B8_FD58 + 8))[id & 0xFF];
    unsigned i;
    if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}

struct O_FD58 { int p0, p1, p2; virtual void v01(int); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual int v10(int); };
struct V3_FD58 { float x, y, z; };
extern V3_FD58 D_004C9098_FD58 __asm__("D_004C9098");
struct Tag_FD58 { char c; Tag_FD58() {} Tag_FD58(const Tag_FD58 &o) : c(o.c) {} };
extern unsigned D_FD58 __asm__("D_004A5658");
extern Tag_FD58 D_004A565C;
extern int D_004A5660;
extern int D_004A3C20;
extern "C" void* func_003E6574_FD58(void*, void*, int) __asm__("func_003E6574");
struct Ent_FD58 { int idx; int val; int pad; int type; };
extern "C" V3_FD58 func_002FFD58(int n, Ent_FD58 *e) {
    if (D_004A5660 == 0) {
        D_FD58 = 0xFFFFFFFF;
        D_004A5660 = 1;
        D_004A565C = Tag_FD58(D_004A565C);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_FD58(buf, &D_FD58, 8);
    Ent_FD58 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C20)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = look_FD58(buf[0]);
    if (obj) {
        O_FD58 *p = *(O_FD58**)(obj + 0xC);
        if (p) {
            if (p->v10(0x10))
                p->v01(3);
        }
    }
    return D_004C9098_FD58;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FFF00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_FF00 __asm__("D_004A3DD8");
extern char **D_004A47B8_FF00 __asm__("D_004A47B8");
extern char *D_004A28A8_FF00 __asm__("D_004A28A8");
static inline char *refToPtr_FF00(unsigned i) { return (char*)(i << 2); }
static inline char *conv_FF00(unsigned i) { if (i == 0) return 0; return refToPtr_FF00(i); }
extern "C" void *func_0028B180_FF00(void) __asm__("func_0028B180");
extern "C" void func_002974A0_FF00(void*, void*, int) __asm__("func_002974A0");
struct V3_FF00 { float x, y, z; };
extern V3_FF00 D_004C9098_FF00 __asm__("D_004C9098");
struct Tag_FF00 { char c; Tag_FF00() {} Tag_FF00(const Tag_FF00 &o) : c(o.c) {} };
extern unsigned D_FF00[] __asm__("D_004FBB08");
extern int D_004A5664;
extern int D_004A3C28;
extern "C" void* func_003E6574_FF00(void*, void*, int) __asm__("func_003E6574");
struct Ent_FF00 { int idx; int val; int pad; int type; };
extern "C" V3_FF00 func_002FFF00(int n, Ent_FF00 *e) {
    if (D_004A5664 == 0) {
        D_FF00[0] = 0xFFFFFFFF;
        D_FF00[1] = 0xFFFFFFFF;
        D_004A5664 = 1;
        (*(Tag_FF00*)((char*)D_FF00 + 8)) = Tag_FF00((*(Tag_FF00*)((char*)D_FF00 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_FF00(buf, D_FF00, 12);
    Ent_FF00 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C28)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_FF00 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_FF00 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_FF00(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int b1 = buf[1];
        func_002974A0_FF00(func_0028B180_FF00(), obj, b1);
    }
    return D_004C9098_FF00;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003000A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_00A8 __asm__("D_004A3DD8");
extern char **D_004A47B8_00A8 __asm__("D_004A47B8");
extern char *D_004A28A8_00A8 __asm__("D_004A28A8");
static inline char *refToPtr_00A8(unsigned i) { return (char*)(i << 2); }
static inline char *conv_00A8(unsigned i) { if (i == 0) return 0; return refToPtr_00A8(i); }
extern "C" void *func_0028B180_00A8(void) __asm__("func_0028B180");
extern "C" void func_00297950_00A8(void*, void*, int, int) __asm__("func_00297950");
struct V3_00A8 { float x, y, z; };
extern V3_00A8 D_004C9098_00A8 __asm__("D_004C9098");
struct Tag_00A8 { char c; Tag_00A8() {} Tag_00A8(const Tag_00A8 &o) : c(o.c) {} };
extern unsigned D_00A8[] __asm__("D_004FBB18");
extern int D_004A5668;
extern const int D_00446550[];
extern "C" void* func_003E6574_00A8(void*, void*, int) __asm__("func_003E6574");
struct Ent_00A8 { int idx; int val; int pad; int type; };
extern "C" V3_00A8 func_003000A8(int n, Ent_00A8 *e) {
    if (D_004A5668 == 0) {
        D_00A8[0] = 0xFFFFFFFF;
        D_00A8[1] = 0xFFFFFFFF;
        ((int*)D_00A8)[2] = -1;
        D_004A5668 = 1;
        (*(Tag_00A8*)((char*)D_00A8 + 12)) = Tag_00A8((*(Tag_00A8*)((char*)D_00A8 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_00A8(buf, D_00A8, 16);
    Ent_00A8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446550[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_00A8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_00A8 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_00A8(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int b1 = buf[1];
        int b2 = buf[2];
        func_00297950_00A8(func_0028B180_00A8(), obj, b1, b2);
    }
    return D_004C9098_00A8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300260);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_0260 __asm__("D_004A3DD8");
extern char **D_004A47B8_0260 __asm__("D_004A47B8");
extern char *D_004A28A8_0260 __asm__("D_004A28A8");
static inline char *refToPtr_0260(unsigned i) { return (char*)(i << 2); }
static inline char *conv_0260(unsigned i) { if (i == 0) return 0; return refToPtr_0260(i); }
extern "C" void *func_0028B180_0260(void) __asm__("func_0028B180");
extern "C" void func_00297EB8_0260(void*, void*, int, int) __asm__("func_00297EB8");
struct V3_0260 { float x, y, z; };
extern V3_0260 D_004C9098_0260 __asm__("D_004C9098");
struct Tag_0260 { char c; Tag_0260() {} Tag_0260(const Tag_0260 &o) : c(o.c) {} };
extern unsigned D_0260[] __asm__("D_004FBB28");
extern int D_004A566C;
extern const int D_00446560[];
extern "C" void* func_003E6574_0260(void*, void*, int) __asm__("func_003E6574");
struct Ent_0260 { int idx; int val; int pad; int type; };
extern "C" V3_0260 func_00300260(int n, Ent_0260 *e) {
    if (D_004A566C == 0) {
        D_0260[0] = 0xFFFFFFFF;
        D_0260[1] = 0xFFFFFFFF;
        ((int*)D_0260)[2] = -1;
        D_004A566C = 1;
        (*(Tag_0260*)((char*)D_0260 + 12)) = Tag_0260((*(Tag_0260*)((char*)D_0260 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_0260(buf, D_0260, 16);
    Ent_0260 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446560[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_0260 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_0260 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_0260(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int b1 = buf[1];
        int b2 = buf[2];
        func_00297EB8_0260(func_0028B180_0260(), obj, b1, b2);
    }
    return D_004C9098_0260;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300418);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_0418 __asm__("D_004A3DD8");
extern char **D_004A47B8_0418 __asm__("D_004A47B8");
extern char *D_004A28A8_0418 __asm__("D_004A28A8");
struct O_0418 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(int); };
struct V3_0418 { float x, y, z; };
extern V3_0418 D_004C9098_0418 __asm__("D_004C9098");
struct Tag_0418 { char c; Tag_0418() {} Tag_0418(const Tag_0418 &o) : c(o.c) {} };
extern unsigned D_0418[] __asm__("D_004FBB38");
extern int D_004A5670;
extern int D_004A3C30;
extern "C" void* func_003E6574_0418(void*, void*, int) __asm__("func_003E6574");
struct Ent_0418 { int idx; int val; int pad; int type; };
extern "C" V3_0418 func_00300418(int n, Ent_0418 *e) {
    if (D_004A5670 == 0) {
        D_0418[0] = 0xFFFFFFFF;
        ((int*)D_0418)[1] = 0;
        D_004A5670 = 1;
        (*(Tag_0418*)((char*)D_0418 + 8)) = Tag_0418((*(Tag_0418*)((char*)D_0418 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_0418(buf, D_0418, 12);
    Ent_0418 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C30)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_0418 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_0418 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_0418 *p = *(O_0418**)(obj + 0xC);
    if (p) {
        int b1 = buf[1];
        if (b1 == 0)
            p->v34(0);
        else if (b1 == 1)
            p->v34(1);
    }
    return D_004C9098_0418;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003005E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A3DD8_05E8 __asm__("D_004A3DD8");
extern char *D_004A47B8_05E8 __asm__("D_004A47B8");
struct O_05E8 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); };
struct V3_05E8 { float x, y, z; };
extern V3_05E8 D_004C9098_05E8 __asm__("D_004C9098");
struct Tag_05E8 { char c; Tag_05E8() {} Tag_05E8(const Tag_05E8 &o) : c(o.c) {} };
extern unsigned D_05E8 __asm__("D_004A5678");
extern Tag_05E8 D_004A567C;
extern int D_004A5680;
extern int D_004A3C38;
extern "C" void* func_003E6574_05E8(void*, void*, int) __asm__("func_003E6574");
struct Ent_05E8 { int idx; int val; int pad; int type; };
extern "C" V3_05E8 func_003005E8(int n, Ent_05E8 *e) {
    if (D_004A5680 == 0) {
        D_05E8 = 0xFFFFFFFF;
        D_004A5680 = 1;
        D_004A567C = Tag_05E8(D_004A567C);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_05E8(buf, &D_05E8, 8);
    Ent_05E8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C38)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(*(char**)&D_004A3DD8_05E8 + 0x290);
    } else {
        char *tb = *(char**)(*(char**)D_004A47B8_05E8 + 8);
        char *s = *(char**)(tb + (id & 0xFF) * 4);
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_05E8 *o = *(O_05E8**)(obj + 0xC);
    if (o)
        o->v35();
    return D_004C9098_05E8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300770);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_0770 { char c; Flag_0770() {} Flag_0770(const Flag_0770& o) : c(o.c) {} };
extern unsigned D_004A5688_0770 __asm__("D_004A5688");
extern Flag_0770 D_004A568C_0770 __asm__("D_004A568C");
extern int D_004A5690_0770 __asm__("D_004A5690");
extern int D_004A3C40_0770[2] __asm__("D_004A3C40");
extern int *D_004A3DD8_0770 __asm__("D_004A3DD8");
extern char **D_004A47B8_0770 __asm__("D_004A47B8");
extern char *D_004A28A8_0770 __asm__("D_004A28A8");
struct O_0770 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void *v24(); };
struct Sh_0770 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(void*); };
struct Lvl_0770 { char pad[0x28]; char *sh[1]; };
static inline char *refToPtr_0770(unsigned i) { return (char*)(i << 2); }
static inline char *conv_0770(unsigned i) { if (i == 0) return 0; return refToPtr_0770(i); }
struct V3_0770 { float x, y, z; };
extern V3_0770 D_004C9098_0770 __asm__("D_004C9098");
extern "C" void* func_003E6574_0770(void*, void*, int) __asm__("func_003E6574");
struct Ent_0770 { int idx; int val; int pad; int type; };
extern "C" V3_0770 func_00300770(int n, Ent_0770 *e) {
    if (D_004A5690_0770 == 0) {
        D_004A5688_0770 = 0xFFFFFFFF;
        D_004A5690_0770 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A568C_0770 = Flag_0770(D_004A568C_0770);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_0770(buf, &D_004A5688_0770, 8);
    Ent_0770 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004A3C40_0770[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)((char*)D_004A3DD8_0770 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_0770 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_0770(i);
            r = t;
        }
        obj = r;
    }
    int k = *D_004A3DD8_0770;
    if (k >= 0 && obj) {
        O_0770 *p = *(O_0770**)(obj + 0xC);
        void *v = obj + 0x10;
        if (p)
            v = p->v24();
        Lvl_0770 *lvl = *(Lvl_0770**)(*(char**)(D_004A28A8_0770 + 0x84) + 0xC);
        ((Sh_0770*)(lvl->sh[k] + 0x6C0))->v10(v);
    }
    return D_004C9098_0770;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300948);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_0948 { char c; Flag_0948() {} Flag_0948(const Flag_0948& o) : c(o.c) {} };
extern unsigned D_004A5698_0948 __asm__("D_004A5698");
extern Flag_0948 D_004A569C_0948 __asm__("D_004A569C");
extern int D_004A56A0_0948 __asm__("D_004A56A0");
extern int D_004A3C48_0948[2] __asm__("D_004A3C48");
extern int *D_004A3DD8_0948 __asm__("D_004A3DD8");
extern char **D_004A47B8_0948 __asm__("D_004A47B8");
extern char *D_004A28A8_0948 __asm__("D_004A28A8");
struct O_0948 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void *v24(); };
struct Sh_0948 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(void*); };
struct Lvl_0948 { char pad[0x28]; char *sh[1]; };
static inline char *refToPtr_0948(unsigned i) { return (char*)(i << 2); }
static inline char *conv_0948(unsigned i) { if (i == 0) return 0; return refToPtr_0948(i); }
struct V3_0948 { float x, y, z; };
extern V3_0948 D_004C9098_0948 __asm__("D_004C9098");
extern "C" void* func_003E6574_0948(void*, void*, int) __asm__("func_003E6574");
struct Ent_0948 { int idx; int val; int pad; int type; };
extern "C" V3_0948 func_00300948(int n, Ent_0948 *e) {
    if (D_004A56A0_0948 == 0) {
        D_004A5698_0948 = 0xFFFFFFFF;
        D_004A56A0_0948 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A569C_0948 = Flag_0948(D_004A569C_0948);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_0948(buf, &D_004A5698_0948, 8);
    Ent_0948 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004A3C48_0948[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)((char*)D_004A3DD8_0948 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_0948 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_0948(i);
            r = t;
        }
        obj = r;
    }
    int k = *D_004A3DD8_0948;
    if (k >= 0 && obj) {
        O_0948 *p = *(O_0948**)(obj + 0xC);
        void *v = obj + 0x10;
        if (p)
            v = p->v24();
        Lvl_0948 *lvl = *(Lvl_0948**)(*(char**)(D_004A28A8_0948 + 0x84) + 0xC);
        ((Sh_0948*)(lvl->sh[k] + 0x6C0))->v12(v);
    }
    return D_004C9098_0948;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300B20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_0B20 { char c; Flag_0B20() {} Flag_0B20(const Flag_0B20& o) : c(o.c) {} };
struct Ent_0B20 { int idx; int val; int pad; int kind; };
struct R12_0B20 { int a; int b; int c; };
extern R12_0B20 D_004C9098_0B20 __asm__("D_004C9098");

extern int D_004A3C50_0B20[2] __asm__("D_004A3C50");
extern "C" void func_00358B28(unsigned, int);
extern int D_004A56A4_0B20 __asm__("D_004A56A4");
struct T12_0B20 { unsigned a; int b; Flag_0B20 f; };
extern T12_0B20 D_004FBB48_0B20 __asm__("D_004FBB48");
extern "C" R12_0B20 func_00300B20(int n, Ent_0B20* e) {
    if (D_004A56A4_0B20 == 0) {
        D_004FBB48_0B20.a = -1;
        D_004FBB48_0B20.b = 1;
        D_004A56A4_0B20 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBB48_0B20.f = Flag_0B20(D_004FBB48_0B20.f);
    }
    unsigned v[4] __attribute__((aligned(16)));
    unsigned* vp = v;
    vp[0] = 0xFFFFFFFFu;
    func_003E6574(vp, &D_004FBB48_0B20, 12);
    Ent_0B20* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3C50_0B20[k] && D_004A3C50_0B20[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    if (~vp[0] != 0) {
        int y = vp[1];
        if (y == 1)
            func_00358B28(vp[0], 1);
        else if (y == 0)
            func_00358B28(vp[0], 0);
    }
    return D_004C9098_0B20;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300C78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A28A4_0C78 __asm__("D_004A28A4");
extern "C" void func_00278E50_0C78(int, int, int, int, int, int, int, int) __asm__("func_00278E50");
extern "C" void func_00278ED0_0C78(int, int, int, int, int, int, int) __asm__("func_00278ED0");
extern "C" void func_00278F38_0C78(int, int) __asm__("func_00278F38");
extern "C" void func_00278F68_0C78(int, int, int, int) __asm__("func_00278F68");
struct V3_0C78 { float x, y, z; };
extern V3_0C78 D_004C9098_0C78 __asm__("D_004C9098");
struct Tag_0C78 { char c; Tag_0C78() {} Tag_0C78(const Tag_0C78 &o) : c(o.c) {} };
extern unsigned D_0C78[] __asm__("D_004FBB58");
extern int D_004A56A8;
extern int D_004A3C58;
extern "C" void* func_003E6574_0C78(void*, void*, int) __asm__("func_003E6574");
struct Ent_0C78 { int idx; int val; int pad; int type; };
extern "C" V3_0C78 func_00300C78(int n, Ent_0C78 *e) {
    if (D_004A56A8 == 0) {
        D_0C78[0] = 0xFFFFFFFF;
        ((int*)D_0C78)[1] = 0;
        D_004A56A8 = 1;
        (*(Tag_0C78*)((char*)D_0C78 + 8)) = Tag_0C78((*(Tag_0C78*)((char*)D_0C78 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    func_003E6574_0C78(buf, D_0C78, 12);
    Ent_0C78 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C58)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    switch ((int)buf[1]) {
    case 0:
        func_00278ED0_0C78(D_004A28A4_0C78, 0, id, 3, -1, -1, -1);
        func_00278F38_0C78(D_004A28A4_0C78, 0);
        break;
    case 1:
        func_00278E50_0C78(D_004A28A4_0C78, 0, id, 3, 0, -1, -1, -1);
        func_00278F38_0C78(D_004A28A4_0C78, 0);
        break;
    case 2:
        func_00278F68_0C78(D_004A28A4_0C78, 0, 1, 0);
        break;
    }
    return D_004C9098_0C78;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300E28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
struct Ent_0E28 { int idx; int val; int pad; int kind; };
struct R12_0E28 { int a; int b; int c; };
extern R12_0E28 D_004C9098_0E28 __asm__("D_004C9098");
struct Flag_0E28 { char c; Flag_0E28() {} Flag_0E28(const Flag_0E28& o) : c(o.c) {} };

extern int D_004A3C60_0E28[2] __asm__("D_004A3C60");
extern "C" void func_0030B928(int, unsigned, int);
extern int D_004A3DD8_0E28 __asm__("D_004A3DD8");
extern int D_004A56AC_0E28 __asm__("D_004A56AC");
struct T12u_0E28 { unsigned a; int b; Flag_0E28 f; };
extern T12u_0E28 D_004FBB68_0E28 __asm__("D_004FBB68");
extern "C" R12_0E28 func_00300E28(int n, Ent_0E28* e) {
    if (D_004A56AC_0E28 == 0) {
        D_004FBB68_0E28.a = 0xFFFFFFFFu;
        D_004FBB68_0E28.b = 1;
        D_004A56AC_0E28 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBB68_0E28.f = Flag_0E28(D_004FBB68_0E28.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBB68_0E28, 12);
    Ent_0E28* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3C60_0E28[k] && D_004A3C60_0E28[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    unsigned x = vp[0];
    if (x != 0xFFFFFFFFu)
        func_0030B928(D_004A3DD8_0E28, x, vp[1]);
    return D_004C9098_0E28;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300F50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_0F50 __asm__("D_004A3DD8");
struct V3_0F50 { float x, y, z; };
extern V3_0F50 D_004C9098_0F50 __asm__("D_004C9098");
struct Tag_0F50 { char c; Tag_0F50() {} Tag_0F50(const Tag_0F50 &o) : c(o.c) {} };
extern unsigned D_0F50[] __asm__("D_004FBB78");
extern int D_56B0_0F50 __asm__("D_004A56B0");
extern const int D_00446570_0F50[] __asm__("D_00446570");
extern "C" void* func_003E6574_0F50(void*, void*, int) __asm__("func_003E6574");
extern "C" void func_0030BAC8_0F50(void*, unsigned, unsigned*, int) __asm__("func_0030BAC8");
struct Ent_0F50 { int idx; int val; int pad; int type; };
extern "C" V3_0F50 func_00300F50(int n, Ent_0F50 *e) {
    if (D_56B0_0F50 == 0) {
        D_0F50[0] = 0xFFFFFFFF;
        D_0F50[1] = 0xFFFFFFFF;
        D_0F50[2] = 0xFFFFFFFF;
        D_0F50[3] = 0xFFFFFFFF;
        D_0F50[4] = 0xFFFFFFFF;
        D_0F50[5] = 0xFFFFFFFF;
        D_0F50[6] = 0xFFFFFFFF;
        D_0F50[7] = 0xFFFFFFFF;
        D_0F50[8] = 0xFFFFFFFF;
        D_0F50[9] = 0xFFFFFFFF;
        D_0F50[10] = 0xFFFFFFFF;
        D_0F50[11] = 0xFFFFFFFF;
        D_0F50[12] = 0xFFFFFFFF;
        D_0F50[13] = 0xFFFFFFFF;
        D_0F50[14] = 0xFFFFFFFF;
        D_0F50[15] = 0xFFFFFFFF;
        D_0F50[16] = 0xFFFFFFFF;
        D_0F50[17] = 0xFFFFFFFF;
        D_0F50[18] = 0xFFFFFFFF;
        D_0F50[19] = 0xFFFFFFFF;
        D_0F50[20] = 0xFFFFFFFF;
        D_56B0_0F50 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_0F50*)((char*)D_0F50 + 0x54)) = Tag_0F50((*(Tag_0F50*)((char*)D_0F50 + 0x54)));
    }
    unsigned buf64[22];
    unsigned *buf = buf64;
    buf64[1] = 0xFFFFFFFF;
    buf64[2] = 0xFFFFFFFF;
    buf64[3] = 0xFFFFFFFF;
    buf64[4] = 0xFFFFFFFF;
    buf64[5] = 0xFFFFFFFF;
    buf64[6] = 0xFFFFFFFF;
    buf64[7] = 0xFFFFFFFF;
    buf64[8] = 0xFFFFFFFF;
    buf64[9] = 0xFFFFFFFF;
    buf64[10] = 0xFFFFFFFF;
    buf64[11] = 0xFFFFFFFF;
    buf64[12] = 0xFFFFFFFF;
    buf64[13] = 0xFFFFFFFF;
    buf64[14] = 0xFFFFFFFF;
    buf64[15] = 0xFFFFFFFF;
    buf64[16] = 0xFFFFFFFF;
    buf64[17] = 0xFFFFFFFF;
    buf64[18] = 0xFFFFFFFF;
    buf64[19] = 0xFFFFFFFF;
    buf64[20] = 0xFFFFFFFF;
    func_003E6574_0F50(buf, D_0F50, 0x58);
    Ent_0F50 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446570_0F50[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    if (buf[0] != 0xFFFFFFFF)
        func_0030BAC8_0F50(D_004A3DD8_0F50, buf[0], buf + 1, 20);
    return D_004C9098_0F50;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_1120 { char c; Flag_1120() {} Flag_1120(const Flag_1120& o) : c(o.c) {} };
struct Ent_1120 { int idx; int val; int pad; int kind; };
extern int D_004A3C68_1120[2] __asm__("D_004A3C68");
extern "C" int func_0030B9A0_1120(char*, int, unsigned, unsigned) __asm__("func_0030B9A0");
extern char *D_004A3DD8_1120 __asm__("D_004A3DD8");
extern char *D_004A28A8_1120 __asm__("D_004A28A8");
extern int D_004A56B4_1120 __asm__("D_004A56B4");
struct T12_1120 { unsigned a; unsigned b; Flag_1120 f; };
extern T12_1120 D_004FBBD0_1120 __asm__("D_004FBBD0");
struct A_1120 { char pad[0x6C0]; };
struct B_1120 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual bool v09(); };
struct D_1120 : A_1120, B_1120 { };
struct Tab_1120 { char pad[0x28]; D_1120 *arr[1]; };
static inline bool isIdle_1120(int slot) {
    if (slot != -1) {
        D_1120 *r = (*(Tab_1120**)(*(char**)(D_004A28A8_1120 + 0x84) + 0xC))->arr[slot];
        B_1120 *b = r;
        D_1120 *d = (D_1120*)b;
        return !d->v09();
    }
    return false;
}
extern "C" void* func_00301120(void* self, int n, Ent_1120* e) {
    int slot = *(int*)D_004A3DD8_1120;
    if (isIdle_1120(slot)) {
        if (D_004A56B4_1120 == 0) {
            D_004FBBD0_1120.a = 0xFFFFFFFF;
            D_004FBBD0_1120.b = 0xFFFFFFFF;
            D_004A56B4_1120 = 1;
            // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
            D_004FBBD0_1120.f = Flag_1120(D_004FBBD0_1120.f);
        }
        unsigned v[4] __attribute__((aligned(16)));
        unsigned* vp = v;
        v[1] = 0xFFFFFFFF;
        func_003E6574(vp, &D_004FBBD0_1120, 12);
        Ent_1120* p = e;
        for (int i = 0; i < n; i++, p++) {
            int k = p->idx;
            unsigned* d = (unsigned*)((k << 2) + (int)vp);
            if (p->kind != D_004A3C68_1120[k] && D_004A3C68_1120[k] == 2)
                *(float*)d = (float)p->val;
            else
                *d = p->val;
        }
        unsigned x = vp[0];
        if (x != 0xFFFFFFFFu) {
            if (~vp[1] == 0)
                vp[1] = *(int*)(*(char**)(D_004A3DD8_1120 + 0x290) + 0x78);
            unsigned b1 = vp[1];
            unsigned b0 = vp[0];
            func_0030B9A0_1120(D_004A3DD8_1120, slot, b0, b1);
            *(int*)((char*)self + 8) = 1;
            *func_00226610(self) = 1;
            return self;
        }
    }
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003012F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_12F0 { char c; Flag_12F0() {} Flag_12F0(const Flag_12F0& o) : c(o.c) {} };
struct Ent_12F0 { int idx; int val; int pad; int kind; };
struct R12_12F0 { int a; int b; int c; };
extern R12_12F0 D_004C9098_12F0 __asm__("D_004C9098");

extern int D_004A3C70_12F0[2] __asm__("D_004A3C70");
extern "C" int func_0030A868_12F0(int, unsigned, int, int) __asm__("func_0030A868");
extern int D_004A3DD8_12F0 __asm__("D_004A3DD8");
extern int D_004A56B8_12F0 __asm__("D_004A56B8");
struct T12_12F0 { unsigned a; int b; Flag_12F0 f; };
extern T12_12F0 D_004FBBE0_12F0 __asm__("D_004FBBE0");
extern "C" void* func_003012F0(void* self, int n, Ent_12F0* e) {
    if (D_004A56B8_12F0 == 0) {
        D_004FBBE0_12F0.a = -1;
        D_004FBBE0_12F0.b = -1;
        D_004A56B8_12F0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBBE0_12F0.f = Flag_12F0(D_004FBBE0_12F0.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBBE0_12F0, 12);
    Ent_12F0* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3C70_12F0[k] && D_004A3C70_12F0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    unsigned x = vp[0];
    if (x != 0xFFFFFFFFu) {
        int r = func_0030A868_12F0(D_004A3DD8_12F0, x, vp[1], -1);
        *(int*)((char*)self + 8) = 1;
        *func_00226610(self) = r;
    } else {
        *(R12_12F0*)self = D_004C9098_12F0;
    }
    return self;
}
#endif

INCLUDE_ASM("seg/seg_1FBE38", func_00301440);

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301560);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_1560 { char c; Flag_1560() {} Flag_1560(const Flag_1560& o) : c(o.c) {} };
struct Ent_1560 { int idx; int val; int pad; int kind; };
struct R12_1560 { int a; int b; int c; };
extern R12_1560 D_004C9098_1560 __asm__("D_004C9098");

extern int D_004A3C80_1560[2] __asm__("D_004A3C80");
extern "C" int func_0030BA80(int, unsigned);
extern int D_004A3DD8_1560 __asm__("D_004A3DD8");
extern int D_004A56C8_1560 __asm__("D_004A56C8");
extern unsigned D_004A56C0_1560 __asm__("D_004A56C0");
extern Flag_1560 D_004A56C4_1560 __asm__("D_004A56C4");
extern "C" void* func_00301560(void* self, int n, Ent_1560* e) {
    if (D_004A56C8_1560 == 0) {
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A56C4_1560 = Flag_1560(D_004A56C4_1560);
        D_004A56C0_1560 = -1;
        D_004A56C8_1560 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A56C0_1560, 8);
    Ent_1560* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3C80_1560[k] && D_004A3C80_1560[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    unsigned x = vp[0];
    if (x != 0xFFFFFFFFu) {
        int r = func_0030BA80(D_004A3DD8_1560, x);
        *(int*)((char*)self + 8) = 1;
        *func_00226610(self) = r;
    } else {
        *(int*)((char*)self + 8) = 1;
        *func_00226610(self) = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301680);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_1680 __asm__("D_004A3DD8");
extern char **D_004A47B8_1680 __asm__("D_004A47B8");
extern char *D_004A28A8_1680 __asm__("D_004A28A8");
static inline char *look_1680(unsigned id) {
    if (~id == 0)
        return *(char**)(D_004A3DD8_1680 + 0x290);
    char *s = (*(char***)((char*)*D_004A47B8_1680 + 8))[id & 0xFF];
    unsigned i;
    if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}

float *func_00226618_1680(void*) __asm__("func_00226618__FPv");
struct O_1680 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual float v30(); };
struct V3_1680 { int w0, w1, w2; };
struct Tag_1680 { char c; Tag_1680() {} Tag_1680(const Tag_1680 &o) : c(o.c) {} };
extern unsigned D_1680 __asm__("D_004A56D0");
extern Tag_1680 D_004A56D4;
extern int D_004A56D8;
extern int D_004A3C88;
extern "C" void* func_003E6574_1680(void*, void*, int) __asm__("func_003E6574");
struct Ent_1680 { int idx; int val; int pad; int type; };
extern "C" V3_1680* func_00301680(V3_1680 *ret, int n, Ent_1680 *e) {
    if (D_004A56D8 == 0) {
        D_1680 = 0xFFFFFFFF;
        D_004A56D8 = 1;
        D_004A56D4 = Tag_1680(D_004A56D4);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_1680(buf, &D_1680, 8);
    Ent_1680 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C88)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = look_1680(buf[0]);
    float v;
    if (obj) {
        O_1680 *p = *(O_1680**)(obj + 0xC);
        if (p)
            v = p->v30();
        else
            v = -1.0f;
        ((int*)ret)[2] = 2;
        *func_00226618_1680(ret) = v;
    } else {
        v = -1.0f;
        ((int*)ret)[2] = 2;
        *func_00226618_1680(ret) = v;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301830);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_1830 __asm__("D_004A3DD8");
extern char **D_004A47B8_1830 __asm__("D_004A47B8");
extern char *D_004A28A8_1830 __asm__("D_004A28A8");
static inline char *look_1830(unsigned id) {
    if (~id == 0)
        return *(char**)(D_004A3DD8_1830 + 0x290);
    char *s = (*(char***)((char*)*D_004A47B8_1830 + 8))[id & 0xFF];
    unsigned i;
    if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}

int *func_00226610(void*);
struct O_1830 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual int v31(); };
struct V3_1830 { int w0, w1, w2; };
struct Tag_1830 { char c; Tag_1830() {} Tag_1830(const Tag_1830 &o) : c(o.c) {} };
extern unsigned D_1830 __asm__("D_004A56E0");
extern Tag_1830 D_004A56E4;
extern int D_004A56E8;
extern int D_004A3C90;
extern "C" void* func_003E6574_1830(void*, void*, int) __asm__("func_003E6574");
struct Ent_1830 { int idx; int val; int pad; int type; };
extern "C" V3_1830* func_00301830(V3_1830 *ret, int n, Ent_1830 *e) {
    if (D_004A56E8 == 0) {
        D_1830 = 0xFFFFFFFF;
        D_004A56E8 = 1;
        D_004A56E4 = Tag_1830(D_004A56E4);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_1830(buf, &D_1830, 8);
    Ent_1830 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C90)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_1830 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_1830 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        O_1830 *p = *(O_1830**)(obj + 0xC);
        int v;
        if (p)
            v = p->v31();
        else
            v = 0;
        ((int*)ret)[2] = 1;
        *func_00226610(ret) = v;
    } else {
        ((int*)ret)[2] = 1;
        *func_00226610(ret) = 0;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003019C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_19C8 __asm__("D_004A3DD8");
extern char **D_004A47B8_19C8 __asm__("D_004A47B8");
extern char *D_004A28A8_19C8 __asm__("D_004A28A8");
int *func_00226610(void*);
struct O_19C8 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual int v32(float); };
struct V3_19C8 { int w0, w1, w2; };
struct Tag_19C8 { char c; Tag_19C8() {} Tag_19C8(const Tag_19C8 &o) : c(o.c) {} };
extern unsigned D_19C8[] __asm__("D_004FBC00");
extern int D_004A56EC;
extern int D_004A3C98;
extern "C" void* func_003E6574_19C8(void*, void*, int) __asm__("func_003E6574");
struct Ent_19C8 { int idx; int val; int pad; int type; };
extern "C" V3_19C8* func_003019C8(V3_19C8 *ret, int n, Ent_19C8 *e) {
    if (D_004A56EC == 0) {
        D_19C8[0] = 0xFFFFFFFF;
        *(float*)&D_19C8[1] = -1.0f;
        D_004A56EC = 1;
        (*(Tag_19C8*)((char*)D_19C8 + 8)) = Tag_19C8((*(Tag_19C8*)((char*)D_19C8 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_19C8(buf, D_19C8, 12);
    Ent_19C8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C98)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_19C8 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_19C8 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        O_19C8 *p = *(O_19C8**)(obj + 0xC);
        float f = *(float*)&buf[1];
        int v;
        if (p)
            v = p->v32(f * 0.03333333507180214f);
        else
            v = 0;
        ((int*)ret)[2] = 1;
        *func_00226610(ret) = v;
    } else {
        ((int*)ret)[2] = 1;
        *func_00226610(ret) = 0;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301B88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_1B88 { char c; Flag_1B88() {} Flag_1B88(const Flag_1B88& o) : c(o.c) {} };
extern unsigned D_004A56F0_1B88 __asm__("D_004A56F0");
extern Flag_1B88 D_004A56F4_1B88 __asm__("D_004A56F4");
extern int D_004A56F8_1B88 __asm__("D_004A56F8");
extern int D_004A3CA0_1B88[2] __asm__("D_004A3CA0");
extern int D_004A3DD8_1B88 __asm__("D_004A3DD8");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_0030A6D8(int, int);
int* func_00226610(void*);

struct Ent_1B88 { int idx; int val; int pad; int kind; };

extern "C" void* func_00301B88(void* self, int n, Ent_1B88* e) {
    if (D_004A56F8_1B88 == 0) {
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A56F4_1B88 = Flag_1B88(D_004A56F4_1B88);
        D_004A56F0_1B88 = -1;
        D_004A56F8_1B88 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A56F0_1B88, 8);
    Ent_1B88* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3CA0_1B88[k] && D_004A3CA0_1B88[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A6D8(D_004A3DD8_1B88, vp[0]);
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301C80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_1C80 { char c; Flag_1C80() {} Flag_1C80(const Flag_1C80& o) : c(o.c) {} };
extern unsigned D_004A5700_1C80 __asm__("D_004A5700");
extern Flag_1C80 D_004A5704_1C80 __asm__("D_004A5704");
extern int D_004A5708_1C80 __asm__("D_004A5708");
extern int D_004A3CA8_1C80[2] __asm__("D_004A3CA8");
extern int D_004A3DD8_1C80 __asm__("D_004A3DD8");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_0030A700(int, int);
int* func_00226610(void*);

struct Ent_1C80 { int idx; int val; int pad; int kind; };

extern "C" void* func_00301C80(void* self, int n, Ent_1C80* e) {
    if (D_004A5708_1C80 == 0) {
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A5704_1C80 = Flag_1C80(D_004A5704_1C80);
        D_004A5700_1C80 = -1;
        D_004A5708_1C80 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5700_1C80, 8);
    Ent_1C80* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3CA8_1C80[k] && D_004A3CA8_1C80[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A700(D_004A3DD8_1C80, vp[0]);
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301D78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_1D78 { char c; Flag_1D78() {} Flag_1D78(const Flag_1D78& o) : c(o.c) {} };
extern unsigned D_004A5710_1D78 __asm__("D_004A5710");
extern Flag_1D78 D_004A5714_1D78 __asm__("D_004A5714");
extern int D_004A5718_1D78 __asm__("D_004A5718");
extern int D_004A3CB0_1D78[2] __asm__("D_004A3CB0");
extern int *D_004A3DD8_1D78 __asm__("D_004A3DD8");
extern char **D_004A47B8_1D78 __asm__("D_004A47B8");
extern char *D_004A28A8_1D78 __asm__("D_004A28A8");
struct O_1D78 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void *v24(); };
struct Sh_1D78 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(void*); };
struct Lvl_1D78 { char pad[0x28]; char *sh[1]; };
static inline char *refToPtr_1D78(unsigned i) { return (char*)(i << 2); }
static inline char *conv_1D78(unsigned i) { if (i == 0) return 0; return refToPtr_1D78(i); }
struct V3_1D78 { float x, y, z; };
extern V3_1D78 D_004C9098_1D78 __asm__("D_004C9098");
extern "C" void* func_003E6574_1D78(void*, void*, int) __asm__("func_003E6574");
struct Chk_1D78 { virtual void v01(); virtual void v02(); virtual int v03(char*); };
int* func_00226610_1D78(void*) __asm__("func_00226610__FPv");
struct Ent_1D78 { int idx; int val; int pad; int type; };
extern "C" void* func_00301D78(void* self, int n, Ent_1D78 *e) {
    if (D_004A5718_1D78 == 0) {
        D_004A5710_1D78 = 0xFFFFFFFF;
        D_004A5718_1D78 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A5714_1D78 = Flag_1D78(D_004A5714_1D78);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_1D78(buf, &D_004A5710_1D78, 8);
    Ent_1D78 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004A3CB0_1D78[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)((char*)D_004A3DD8_1D78 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_1D78 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_1D78(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int found = 1;
        char *lvl = *(char**)(*(char**)(D_004A28A8_1D78 + 0x84) + 0xC);
        char *q = *(char**)(lvl + (*D_004A3DD8_1D78 << 2) + 0x28);
        char *a = q ? q + 0x6C0 : 0;
        char *r = a ? a - 0x6C0 : 0;
        Chk_1D78 *c = (Chk_1D78*)(r + 0x6C0);
        if (c->v03(obj)) {
            *(int*)((char*)self + 8) = found;
            *func_00226610_1D78(self) = found;
            goto done;
        }
    }
    *(int*)((char*)self + 8) = 1;
    *func_00226610_1D78(self) = 0;
done:
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301F48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_1F48 { char c; Flag_1F48() {} Flag_1F48(const Flag_1F48& o) : c(o.c) {} };
extern int D_004A5720_1F48 __asm__("D_004A5720");
extern Flag_1F48 D_004A5724_1F48 __asm__("D_004A5724");
extern int D_004A5728_1F48 __asm__("D_004A5728");
extern int D_004A3CB8_1F48[2] __asm__("D_004A3CB8");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_00303D88_1F48(int) __asm__("func_00303D88");

struct Ent_1F48 { int idx; int val; int pad; int kind; };
struct R12_1F48 { int a; int b; int c; };
extern R12_1F48 D_004C9098_1F48 __asm__("D_004C9098");

extern "C" R12_1F48 func_00301F48(int n, Ent_1F48* e) {
    if (D_004A5728_1F48 == 0) {
        D_004A5720_1F48 = -1;
        D_004A5728_1F48 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A5724_1F48 = Flag_1F48(D_004A5724_1F48);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5720_1F48, 8);
    Ent_1F48* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3CB8_1F48[k] && D_004A3CB8_1F48[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_00303D88_1F48(vp[0]);
    return D_004C9098_1F48;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302048);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int *D_004A3DD8_2048 __asm__("D_004A3DD8");
extern char *D_004A28A8_2048 __asm__("D_004A28A8");
extern int D_00445E40_2048[] __asm__("D_00445E40");
extern "C" void func_0030B7F8_2048(int*, int) __asm__("func_0030B7F8");
extern "C" void func_0022D6C8_2048(int, int) __asm__("func_0022D6C8");
struct Sh_2048 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual int v09(); };
struct V3_2048 { float x, y, z; };
extern V3_2048 D_004C9098_2048 __asm__("D_004C9098");
struct Tag_2048 { char c; Tag_2048() {} Tag_2048(const Tag_2048 &o) : c(o.c) {} };
extern unsigned D_2048[] __asm__("D_004FBC10");
extern int D_004A572C;
extern int D_004A3CC0;
extern "C" void* func_003E6574_2048(void*, void*, int) __asm__("func_003E6574");
struct Ent_2048 { int idx; int val; int pad; int type; };
extern "C" V3_2048 func_00302048(int n, Ent_2048 *e) {
    if (D_004A572C == 0) {
        ((int*)D_2048)[0] = -1;
        ((int*)D_2048)[1] = -1;
        D_004A572C = 1;
        (*(Tag_2048*)((char*)D_2048 + 8)) = Tag_2048((*(Tag_2048*)((char*)D_2048 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    func_003E6574_2048(buf, D_2048, 12);
    Ent_2048 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3CC0)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    int r;
    int k = *D_004A3DD8_2048;
    if (k != -1) {
        int k4 = k * 4;
        char *lvl = *(char**)(*(char**)(D_004A28A8_2048 + 0x84) + 0xC);
        char *q = *(char**)(lvl + k4 + 0x28);
        char *a = q ? q + 0x6C0 : 0;
        char *b = a ? a - 0x6C0 : 0;
        Sh_2048 *sh = (Sh_2048*)(b + 0x6C0);
        r = sh->v09() ^ 1;
    } else {
        r = 0;
    }
    if (r) {
        int v16 = 0;
        unsigned id = buf[0];
        int b1 = buf[1];
        int w = *(int*)(*(char**)(D_004A28A8_2048 + 0x84) + 0x78);
        if (id < 8)
            v16 = D_00445E40_2048[id];
        if (b1 == 0) {
            if (v16 != 1)
                func_0030B7F8_2048(D_004A3DD8_2048, id);
            func_0022D6C8_2048(w, v16);
        }
    }
    return D_004C9098_2048;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302210);
#ifdef SKIP_ASM
extern "C" void* func_003E6574_2210(void*, void*, int) __asm__("func_003E6574");
struct Flag_2210 { char c; Flag_2210() {} Flag_2210(const Flag_2210& o) : c(o.c) {} };
struct Defaults_2210 { int v[3]; Flag_2210 flag; };
extern Defaults_2210 D_004FBC20_2210 __asm__("D_004FBC20");
extern int D_004A5730_2210 __asm__("D_004A5730");
extern const int D_004465C8_2210[] __asm__("D_004465C8");
extern char* const D_00445E40_2210[] __asm__("D_00445E40");
extern int* D_004A3DD8_2210 __asm__("D_004A3DD8");
extern char* D_004A28A8_2210 __asm__("D_004A28A8");
struct V3_2210 { float x, y, z; };
extern V3_2210 D_004C9098_2210 __asm__("D_004C9098");
extern "C" void* cBE_getBE_2210() __asm__("cBE_getBE");
extern "C" void* cBE_getInterface_2210(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144CE0_2210(void* iface, int id) __asm__("func_00144CE0");
extern "C" void func_0022CEA8_2210(void* self, int hash, char* name) __asm__("func_0022CEA8");
extern "C" void func_0022D088_2210(void* self, int hash, char* name) __asm__("func_0022D088");
extern "C" void func_00231250_2210(void* self, int a, int b, int refresh) __asm__("func_00231250");
extern "C" void* func_0028B180_2210() __asm__("func_0028B180");
extern "C" void func_002A49E8_2210(void* self) __asm__("func_002A49E8");

struct Ent_2210 { int idx; int val; int pad; int kind; };

class cRider_2210 {
public:
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual bool isBusy();
};

extern "C" V3_2210 func_00302210(int n, Ent_2210* e)
{
    if (D_004A5730_2210 == 0) {
        D_004FBC20_2210.v[0] = -1;
        D_004FBC20_2210.v[1] = -1;
        D_004FBC20_2210.v[2] = -1;
        D_004A5730_2210 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBC20_2210.flag = Flag_2210(D_004FBC20_2210.flag);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574_2210(vp, &D_004FBC20_2210, 0x10);
    Ent_2210* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004465C8_2210[k] && D_004465C8_2210[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int ok;
    int cur = *D_004A3DD8_2210;
    if (cur != -1) {
        char* lvl = *(char**)(*(char**)(D_004A28A8_2210 + 0x84) + 0xC);
        char* q = *(char**)(lvl + (cur << 2) + 0x28);
        char* a = q ? q + 0x6C0 : 0;
        char* r = a ? a - 0x6C0 : 0;
        ok = !((cRider_2210*)(r + 0x6C0))->isBusy();
    } else {
        ok = 0;
    }
    if (ok) {
        int sel = vp[2];
        int action = vp[1];
        int id = vp[0];
        char* name = 0;
        void* iface = cBE_getInterface_2210(cBE_getBE_2210(), 0);
        char* ui = *(char**)(*(char**)(D_004A28A8_2210 + 0x84) + 0x78);
        if ((unsigned int)sel < 8) {
            name = D_00445E40_2210[sel];
        }
        int hash = func_00144CE0_2210(iface, id);
        switch ((unsigned int)action) {
        case 0:
            func_0022CEA8_2210(ui, hash, name);
            break;
        case 1:
            break;
        case 2:
            func_0022D088_2210(ui, hash, name);
            break;
        case 3:
            func_00231250_2210(*(void**)(D_004A28A8_2210 + 0x84), 0xE, 2, 0);
            func_002A49E8_2210(func_0028B180_2210());
            break;
        case 4:
            func_00231250_2210(*(void**)(D_004A28A8_2210 + 0x84), 0xE, 0, 0);
            break;
        case 5:
            *(int*)(ui + 0x1A4) = 1;
            break;
        }
    }
    return D_004C9098_2210;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302490);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_2490 __asm__("D_004A3DD8");
extern char **D_004A47B8_2490 __asm__("D_004A47B8");
struct O_2490 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_2490 { float x, y, z; };
extern V3_2490 D_004C9098_2490 __asm__("D_004C9098");
struct Tag_2490 { char c; Tag_2490() {} Tag_2490(const Tag_2490 &o) : c(o.c) {} };
struct T12_2490 { unsigned a; int b; Tag_2490 f; };
extern T12_2490 D_4FBC30_2490 __asm__("D_004FBC30");
extern int D_5734_2490 __asm__("D_004A5734");
extern int D_3CC8_2490 __asm__("D_004A3CC8");
extern "C" void* func_003E6574_2490(void*, void*, int) __asm__("func_003E6574");
extern "C" void func_00353228_2490(char*) __asm__("func_00353228");
extern "C" void func_00353278_2490(char*) __asm__("func_00353278");
struct Ent_2490 { int idx; int val; int pad; int type; };
extern "C" V3_2490 func_00302490(int n, Ent_2490 *e) {
    if (D_5734_2490 == 0) {
        D_4FBC30_2490.a = 0xFFFFFFFF;
        D_4FBC30_2490.b = -1;
        D_5734_2490 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_4FBC30_2490.f = Tag_2490(D_4FBC30_2490.f);
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_2490(buf, &D_4FBC30_2490, 12);
    Ent_2490 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_3CC8_2490)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_2490 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_2490 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        O_2490 *p = *(O_2490**)(obj + 0xC);
        int mode = buf[1];
        if (p) {
            if (p->v16()) {
                char *c = *(char**)(obj + 0xC);
                switch (mode) {
                case 0: {
                    char *q = *(char**)(c + 0x1C);
                    if (q)
                        func_00353228_2490(q);
                    break;
                }
                case 1: {
                    char *q = *(char**)(c + 0x1C);
                    if (q)
                        func_00353278_2490(q);
                    break;
                }
                }
            }
        }
    }
    return D_004C9098_2490;
}
#endif

INCLUDE_ASM("seg/seg_1FBE38", func_00302680);

INCLUDE_ASM("seg/seg_1FBE38", func_00302778);

INCLUDE_ASM("seg/seg_1FBE38", func_00302870);

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_2968 { char c; Flag_2968() {} Flag_2968(const Flag_2968& o) : c(o.c) {} };
struct Ent_2968 { int idx; int val; int pad; int kind; };
struct R12_2968 { int a; int b; int c; };
extern R12_2968 D_004C9098_2968 __asm__("D_004C9098");

extern int D_004A3CE8_2968[2] __asm__("D_004A3CE8");
extern char** D_004A47B8_2968 __asm__("D_004A47B8");
extern char* D_004A3DD8_2968 __asm__("D_004A3DD8");
extern int D_004A5770_2968 __asm__("D_004A5770");
extern unsigned D_004A5768_2968 __asm__("D_004A5768");
extern Flag_2968 D_004A576C_2968 __asm__("D_004A576C");
extern "C" R12_2968 func_00302968(int n, Ent_2968* e) {
    if (D_004A5770_2968 == 0) {
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A576C_2968 = Flag_2968(D_004A576C_2968);
        D_004A5768_2968 = -1;
        D_004A5770_2968 = 1;
    }
    unsigned v[4] __attribute__((aligned(16)));
    unsigned* vp = v;
    vp[0] = 0xFFFFFFFFu;
    func_003E6574(vp, &D_004A5768_2968, 8);
    Ent_2968* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3CE8_2968[k] && D_004A3CE8_2968[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    char* g = D_004A3DD8_2968;
    unsigned x = vp[0];
    char** tbl = *(char***)(*D_004A47B8_2968 + 8);
    char* e0 = tbl[x & 0xFF];
    unsigned w;
    int r;
    if (e0 == 0 || (w = (*(unsigned**)(e0 + 0x1C))[x >> 8] >> 8) == 0)
        r = 0;
    else
        r = w << 2;
    *(int*)(g + 0x290) = r;
    return D_004C9098_2968;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302AC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_2AC0 { char c; Flag_2AC0() {} Flag_2AC0(const Flag_2AC0& o) : c(o.c) {} };
struct Ent_2AC0 { int idx; int val; int pad; int kind; };
struct R12_2AC0 { int a; int b; int c; };
extern R12_2AC0 D_004C9098_2AC0 __asm__("D_004C9098");

extern int D_004A3CF0_2AC0[2] __asm__("D_004A3CF0");
extern "C" void func_0030A728(int, int, int);
extern int D_004A3DD8_2AC0 __asm__("D_004A3DD8");
extern int D_004A5774_2AC0 __asm__("D_004A5774");
struct T12_2AC0 { unsigned a; int b; Flag_2AC0 f; };
extern T12_2AC0 D_004FBC40_2AC0 __asm__("D_004FBC40");
extern "C" R12_2AC0 func_00302AC0(int n, Ent_2AC0* e) {
    if (D_004A5774_2AC0 == 0) {
        D_004FBC40_2AC0.a = -1;
        D_004FBC40_2AC0.b = 0;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBC40_2AC0.f = Flag_2AC0(D_004FBC40_2AC0.f);
        D_004A5774_2AC0 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBC40_2AC0, 12);
    Ent_2AC0* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3CF0_2AC0[k] && D_004A3CF0_2AC0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A728(D_004A3DD8_2AC0, vp[0], vp[1]);
    return D_004C9098_2AC0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302BD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_2BD8 { char c; Flag_2BD8() {} Flag_2BD8(const Flag_2BD8& o) : c(o.c) {} };
struct Ent_2BD8 { int idx; int val; int pad; int kind; };
struct R12_2BD8 { int a; int b; int c; };
extern R12_2BD8 D_004C9098_2BD8 __asm__("D_004C9098");

extern int D_004A3CF8_2BD8[2] __asm__("D_004A3CF8");
extern "C" void func_0030A868(int, int, int, int);
extern int D_004A3DD8_2BD8 __asm__("D_004A3DD8");
extern int D_004A5780_2BD8 __asm__("D_004A5780");
extern unsigned D_004A5778_2BD8 __asm__("D_004A5778");
extern Flag_2BD8 D_004A577C_2BD8 __asm__("D_004A577C");
extern "C" R12_2BD8 func_00302BD8(int n, Ent_2BD8* e) {
    if (D_004A5780_2BD8 == 0) {
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A577C_2BD8 = Flag_2BD8(D_004A577C_2BD8);
        D_004A5778_2BD8 = -1;
        D_004A5780_2BD8 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5778_2BD8, 8);
    Ent_2BD8* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3CF8_2BD8[k] && D_004A3CF8_2BD8[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A868(D_004A3DD8_2BD8, vp[0], 0, -1);
    return D_004C9098_2BD8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302CE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_2CE8 { char c; Flag_2CE8() {} Flag_2CE8(const Flag_2CE8& o) : c(o.c) {} };
struct Ent_2CE8 { int idx; int val; int pad; int kind; };
struct R12_2CE8 { int a; int b; int c; };
extern R12_2CE8 D_004C9098_2CE8 __asm__("D_004C9098");

extern int D_004A3D00_2CE8[2] __asm__("D_004A3D00");
extern "C" void func_0030A728(int, int, int);
extern int D_004A3DD8_2CE8 __asm__("D_004A3DD8");
extern int D_004A5790_2CE8 __asm__("D_004A5790");
extern unsigned D_004A5788_2CE8 __asm__("D_004A5788");
extern Flag_2CE8 D_004A578C_2CE8 __asm__("D_004A578C");
extern "C" R12_2CE8 func_00302CE8(int n, Ent_2CE8* e) {
    if (D_004A5790_2CE8 == 0) {
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A578C_2CE8 = Flag_2CE8(D_004A578C_2CE8);
        D_004A5788_2CE8 = -1;
        D_004A5790_2CE8 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5788_2CE8, 8);
    Ent_2CE8* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D00_2CE8[k] && D_004A3D00_2CE8[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A728(D_004A3DD8_2CE8, vp[0], 0);
    return D_004C9098_2CE8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302DF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_2DF0 { char c; Flag_2DF0() {} Flag_2DF0(const Flag_2DF0& o) : c(o.c) {} };
struct Ent_2DF0 { int idx; int val; int pad; int kind; };
struct R12_2DF0 { int a; int b; int c; };
extern R12_2DF0 D_004C9098_2DF0 __asm__("D_004C9098");

extern int D_004A3D08_2DF0[2] __asm__("D_004A3D08");
extern "C" void func_0030A728(int, int, int);
extern int D_004A3DD8_2DF0 __asm__("D_004A3DD8");
extern int D_004A57A0_2DF0 __asm__("D_004A57A0");
extern unsigned D_004A5798_2DF0 __asm__("D_004A5798");
extern Flag_2DF0 D_004A579C_2DF0 __asm__("D_004A579C");
extern "C" R12_2DF0 func_00302DF0(int n, Ent_2DF0* e) {
    if (D_004A57A0_2DF0 == 0) {
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A579C_2DF0 = Flag_2DF0(D_004A579C_2DF0);
        D_004A5798_2DF0 = -1;
        D_004A57A0_2DF0 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5798_2DF0, 8);
    Ent_2DF0* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D08_2DF0[k] && D_004A3D08_2DF0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A728(D_004A3DD8_2DF0, vp[0], 2);
    return D_004C9098_2DF0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302EF8);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_2EF8 { char c; Flag_2EF8() {} Flag_2EF8(const Flag_2EF8& o) : c(o.c) {} };
extern int D_004A57A8_2EF8 __asm__("D_004A57A8");
extern Flag_2EF8 D_004A57AC_2EF8 __asm__("D_004A57AC");
extern int D_004A57B0_2EF8 __asm__("D_004A57B0");
extern int D_004A3D10_2EF8[2] __asm__("D_004A3D10");
extern int* D_004A3DD8_2EF8 __asm__("D_004A3DD8");
extern char* D_004A28A8_2EF8 __asm__("D_004A28A8");
extern "C" int func_00122EE8_2EF8(char* rider, int which) __asm__("func_00122EE8");

struct Ent_2EF8 { int idx; int val; int pad; int kind; };

extern "C" void* func_00302EF8(void* self, int n, Ent_2EF8* e)
{
    if (D_004A57B0_2EF8 == 0) {
        D_004A57A8_2EF8 = 0;
        D_004A57B0_2EF8 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A57AC_2EF8 = Flag_2EF8(D_004A57AC_2EF8);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A57A8_2EF8, 8);
    Ent_2EF8* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D10_2EF8[k] && D_004A3D10_2EF8[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    char* lvl = *(char**)(*(char**)(D_004A28A8_2EF8 + 0x84) + 0xC);
    char* q = *(char**)(lvl + (*D_004A3DD8_2EF8 << 2) + 0x28);
    char* a = q ? q + 0x6C0 : 0;
    char* r = a ? a - 0x6C0 : 0;
    int res;
    switch (vp[0]) {
    case 0: res = func_00122EE8_2EF8(r, 0); break;
    case 1: res = func_00122EE8_2EF8(r, 1); break;
    case 2: res = func_00122EE8_2EF8(r, 2); break;
    case 3: res = func_00122EE8_2EF8(r, 3); break;
    case 4: res = func_00122EE8_2EF8(r, 4); break;
    case 5: res = func_00122EE8_2EF8(r, 5); break;
    case 6: res = func_00122EE8_2EF8(r, 6); break;
    case 7: res = func_00122EE8_2EF8(r, 7); break;
    case 8: res = func_00122EE8_2EF8(r, 8); break;
    case 9: res = func_00122EE8_2EF8(r, 9); break;
    case 10: res = func_00122EE8_2EF8(r, 10); break;
    case 11: res = func_00122EE8_2EF8(r, 11); break;
    case 12: res = func_00122EE8_2EF8(r, 12); break;
    case 13: res = func_00122EE8_2EF8(r, 13); break;
    case 14: res = func_00122EE8_2EF8(r, 14); break;
    case 15: res = func_00122EE8_2EF8(r, 15); break;
    case 16: res = func_00122EE8_2EF8(r, 16); break;
    case 17: res = func_00122EE8_2EF8(r, 17); break;
    case 18: res = func_00122EE8_2EF8(r, 18); break;
    default: res = 0; break;
    }
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = res;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303130);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_3130 __asm__("D_004A3DD8");
extern char **D_004A47B8_3130 __asm__("D_004A47B8");
extern char *D_004A28A8_3130 __asm__("D_004A28A8");
static inline char *look_3130(unsigned id) {
    if (~id == 0)
        return *(char**)(D_004A3DD8_3130 + 0x290);
    char *s = (*(char***)((char*)*D_004A47B8_3130 + 8))[id & 0xFF];
    unsigned i;
    if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}

int *func_00226610(void*);
struct V3_3130 { int w0, w1, w2; };
struct Tag_3130 { char c; Tag_3130() {} Tag_3130(const Tag_3130 &o) : c(o.c) {} };
extern unsigned D_3130[] __asm__("D_004FBC50");
extern int D_004A57B4;
extern int D_004A3D18;
extern "C" void* func_003E6574_3130(void*, void*, int) __asm__("func_003E6574");
struct Ent_3130 { int idx; int val; int pad; int type; };
extern "C" V3_3130* func_00303130(V3_3130 *ret, int n, Ent_3130 *e) {
    if (D_004A57B4 == 0) {
        D_3130[0] = 0xFFFFFFFF;
        D_3130[1] = 1;
        D_004A57B4 = 1;
        (*(Tag_3130*)((char*)D_3130 + 8)) = Tag_3130((*(Tag_3130*)((char*)D_3130 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_3130(buf, D_3130, 12);
    Ent_3130 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3D18)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = look_3130(buf[0]);
    if (obj && *(int*)(obj + 0xC)) {
        ((int*)ret)[2] = 1;
        *func_00226610(ret) = 1;
    } else {
        ((int*)ret)[2] = 1;
        *func_00226610(ret) = 0;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003032C0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector length).
void* func_00226618(void*);
extern char *D_004A3DD8_32C0 __asm__("D_004A3DD8");
extern char *D_004A28A8_32C0 __asm__("D_004A28A8");
struct Vec_32C0 { float x, y, z, w; } __attribute__((aligned(16)));
struct A_32C0 { char pad[0x6C0]; };
struct B_32C0 { virtual void v01(); virtual Vec_32C0 *v02(); };
struct D_32C0 : A_32C0, B_32C0 { };
struct Tab_32C0 { char pad[0x28]; D_32C0 *arr[1]; };
static inline float len_32C0(const Vec_32C0 &v) {
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
extern "C" void* func_003032C0(void* self) {
    D_32C0 *r = (*(Tab_32C0**)(*(char**)(D_004A28A8_32C0 + 0x84) + 0xC))->arr[*(int*)D_004A3DD8_32C0];
    B_32C0 *b = r;
    D_32C0 *d = (D_32C0*)b;
    float len = len_32C0(*d->v02());
    float res = len * *(float*)(D_004A28A8_32C0 + 0x14);
    *(int*)((char*)self + 8) = 2;
    *(float*)func_00226618(self) = res;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303380);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector length).
void* func_00226618(void*);
extern char *D_004A3DD8_3380 __asm__("D_004A3DD8");
extern char *D_004A28A8_3380 __asm__("D_004A28A8");
struct Vec_3380 { float x, y, z, w; } __attribute__((aligned(16)));
struct A_3380 { char pad[0x6C0]; };
struct B_3380 { virtual void v01(); virtual Vec_3380 *v02(); };
struct D_3380 : A_3380, B_3380 { };
struct Tab_3380 { char pad[0x28]; D_3380 *arr[1]; };
static inline float len_3380(const Vec_3380 &v) {
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
extern "C" void* func_00303380(void* self) {
    D_3380 *r = (*(Tab_3380**)(*(char**)(D_004A28A8_3380 + 0x84) + 0xC))->arr[*(int*)D_004A3DD8_3380];
    B_3380 *b = r;
    D_3380 *d = (D_3380*)b;
    float len = len_3380(*d->v02());
    *(int*)((char*)self + 8) = 2;
    *(float*)func_00226618(self) = len;
    return self;
}
#endif

INCLUDE_ASM("seg/seg_1FBE38", func_00303430);

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303490);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int* func_00226620_3490(void*) __asm__("func_00226620__FPv");
extern char *D_004A3DD8_3490 __asm__("D_004A3DD8");
extern "C" unsigned func_003079D8_3490(char*) __asm__("func_003079D8");
extern "C" void* func_00303490(void* self) {
    char *p = *(char**)(D_004A3DD8_3490 + 0x2A4);
    unsigned v;
    if (p)
        v = func_003079D8_3490(p);
    else
        v = 0xFFFFFFFF;
    *(int*)((char*)self + 8) = 3;
    *func_00226620_3490(self) = v;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003034F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int* func_00226610(void*);
extern char *D_004A3DD8_34F8 __asm__("D_004A3DD8");
extern char *D_004A28A8_34F8 __asm__("D_004A28A8");
struct A_34F8 { char pad[0x6C0]; };
struct B_34F8 { virtual void v01(); };
struct D_34F8 : A_34F8, B_34F8 { };
struct Tab_34F8 { char pad[0x28]; D_34F8 *arr[1]; };
extern "C" int func_00122EE8_34F8(D_34F8*, int) __asm__("func_00122EE8");
extern "C" void* func_003034F8(void* self) {
    D_34F8 *r = (*(Tab_34F8**)(*(char**)(D_004A28A8_34F8 + 0x84) + 0xC))->arr[*(int*)D_004A3DD8_34F8];
    B_34F8 *b = r;
    D_34F8 *d = (D_34F8*)b;
    unsigned v;
    if (func_00122EE8_34F8(d, 4))
        v = *(unsigned*)(*(char**)((char*)d + 0x77C) + 0xD4);
    else
        v = 0xFFFFFFFF;
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = v;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303598);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_3598 { char c; Flag_3598() {} Flag_3598(const Flag_3598& o) : c(o.c) {} };
struct Ent_3598 { int idx; int val; int pad; int kind; };
struct R12_3598 { int a; int b; int c; };
extern R12_3598 D_004C9098_3598 __asm__("D_004C9098");

extern int D_004A3D20_3598[2] __asm__("D_004A3D20");
float AIrandf(float, float);
void* func_00226618(void*);
extern int D_004A57B8_3598 __asm__("D_004A57B8");
struct T12_3598 { float a; float b; Flag_3598 f; };
extern T12_3598 D_004FBC60_3598 __asm__("D_004FBC60");
extern "C" void* func_00303598(void* self, int n, Ent_3598* e) {
    if (D_004A57B8_3598 == 0) {
        D_004FBC60_3598.a = 0;
        D_004FBC60_3598.b = 1.0f;
        D_004A57B8_3598 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBC60_3598.f = Flag_3598(D_004FBC60_3598.f);
    }
    float v[4] __attribute__((aligned(16)));
    float* vp = v;
    func_003E6574(vp, &D_004FBC60_3598, 12);
    Ent_3598* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D20_3598[k] && D_004A3D20_3598[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    float r = AIrandf(vp[0], vp[1]);
    *(int*)((char*)self + 8) = 2;
    *(float*)func_00226618(self) = r;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003036B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Flag_36B0 { char c; Flag_36B0() {} Flag_36B0(const Flag_36B0& o) : c(o.c) {} };
extern int D_004A57C0_36B0 __asm__("D_004A57C0");
extern Flag_36B0 D_004A57C4_36B0 __asm__("D_004A57C4");
extern int D_004A57C8_36B0 __asm__("D_004A57C8");
extern int D_004A3D28_36B0[2] __asm__("D_004A3D28");
extern "C" void func_003E6574(void*, void*, int);
extern "C" int func_0030AF08(int*, int, int);
extern int* D_004A3DD8_36B0 __asm__("D_004A3DD8");
int* func_00226610(void*);

struct Ent_36B0 { int idx; int val; int pad; int kind; };

extern "C" void* func_003036B0(void* self, int n, Ent_36B0* e) {
    if (D_004A57C8_36B0 == 0) {
        D_004A57C0_36B0 = -1;
        D_004A57C8_36B0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A57C4_36B0 = Flag_36B0(D_004A57C4_36B0);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A57C0_36B0, 8);
    Ent_36B0* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D28_36B0[k] && D_004A3D28_36B0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int r = func_0030AF08(D_004A3DD8_36B0, *D_004A3DD8_36B0, vp[0]);
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = r;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003037B0);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_37B0 { char c; Flag_37B0() {} Flag_37B0(const Flag_37B0& o) : c(o.c) {} };
extern int D_004A57D0_37B0 __asm__("D_004A57D0");
extern Flag_37B0 D_004A57D4_37B0 __asm__("D_004A57D4");
extern int D_004A57D8_37B0 __asm__("D_004A57D8");
extern int D_004A3D30_37B0[2] __asm__("D_004A3D30");
extern int* D_004A3DD8_37B0 __asm__("D_004A3DD8");
extern char* D_004A28A8_37B0 __asm__("D_004A28A8");
extern "C" int func_00122EE8_37B0(char* rider, int which) __asm__("func_00122EE8");

struct Ent_37B0 { int idx; int val; int pad; int kind; };

extern "C" void* func_003037B0(void* self, int n, Ent_37B0* e)
{
    if (D_004A57D8_37B0 == 0) {
        D_004A57D0_37B0 = -1;
        D_004A57D8_37B0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A57D4_37B0 = Flag_37B0(D_004A57D4_37B0);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A57D0_37B0, 8);
    Ent_37B0* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D30_37B0[k] && D_004A3D30_37B0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    char* lvl = *(char**)(*(char**)(D_004A28A8_37B0 + 0x84) + 0xC);
    char* q = *(char**)(lvl + (*D_004A3DD8_37B0 << 2) + 0x28);
    char* a = q ? q + 0x6C0 : 0;
    char* r = a ? a - 0x6C0 : 0;
    int res;
    switch (vp[0]) {
    case 3: res = func_00122EE8_37B0(r, 0); break;
    case 4: res = func_00122EE8_37B0(r, 1); break;
    case 1: res = func_00122EE8_37B0(r, 2); break;
    case 0: res = func_00122EE8_37B0(r, 3); break;
    case 2: res = func_00122EE8_37B0(r, 4); break;
    case 5: res = func_00122EE8_37B0(r, 5); break;
    case 6: res = func_00122EE8_37B0(r, 6); break;
    case 7: res = func_00122EE8_37B0(r, 7); break;
    case 9: res = func_00122EE8_37B0(r, 8); break;
    case 10: res = func_00122EE8_37B0(r, 9); break;
    case 11: res = func_00122EE8_37B0(r, 10); break;
    case 12: res = func_00122EE8_37B0(r, 11); break;
    case 13: res = func_00122EE8_37B0(r, 12); break;
    case 14: res = func_00122EE8_37B0(r, 13); break;
    case 15: res = func_00122EE8_37B0(r, 14); break;
    case 16: res = func_00122EE8_37B0(r, 15); break;
    case 17: res = func_00122EE8_37B0(r, 16); break;
    case 8: res = func_00122EE8_37B0(r, 17); break;
    case 18: res = func_00122EE8_37B0(r, 18); break;
    default: res = 0; break;
    }
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = res;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003039F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_39F0 __asm__("D_004A3DD8");
extern char **D_004A47B8_39F0 __asm__("D_004A47B8");
extern char *D_004A28A8_39F0 __asm__("D_004A28A8");
extern int D_004A3FF0_39F0 __asm__("D_004A3FF0");
extern "C" void func_00343C60_39F0(int, int) __asm__("func_00343C60");
extern "C" void func_00343F38_39F0(int, int) __asm__("func_00343F38");
struct V3_39F0 { float x, y, z; };
extern V3_39F0 D_004C9098_39F0 __asm__("D_004C9098");
struct Tag_39F0 { char c; Tag_39F0() {} Tag_39F0(const Tag_39F0 &o) : c(o.c) {} };
extern unsigned D_39F0[] __asm__("D_004FBC70");
extern int D_004A57DC;
extern int D_004A3D38;
extern "C" void* func_003E6574_39F0(void*, void*, int) __asm__("func_003E6574");
struct Ent_39F0 { int idx; int val; int pad; int type; };
extern "C" V3_39F0 func_003039F0(int n, Ent_39F0 *e) {
    if (D_004A57DC == 0) {
        D_39F0[0] = 0xFFFFFFFF;
        ((int*)D_39F0)[1] = -1;
        D_004A57DC = 1;
        (*(Tag_39F0*)((char*)D_39F0 + 8)) = Tag_39F0((*(Tag_39F0*)((char*)D_39F0 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_39F0(buf, D_39F0, 12);
    Ent_39F0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3D38)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_39F0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_39F0 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        int b1 = buf[1];
        int w = *(int*)(obj + 0x78);
        if (b1 == 0)
            func_00343C60_39F0(D_004A3FF0_39F0, w);
        else if (b1 == 1)
            func_00343F38_39F0(D_004A3FF0_39F0, w);
    }
    return D_004C9098_39F0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303BA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_3BA0 __asm__("D_004A3DD8");
extern char **D_004A47B8_3BA0 __asm__("D_004A47B8");
extern int D_004A2A00_3BA0 __asm__("D_004A2A00");
struct V3_3BA0 { float x, y, z; };
extern V3_3BA0 D_004C9098_3BA0 __asm__("D_004C9098");
struct Tag_3BA0 { char c; Tag_3BA0() {} Tag_3BA0(const Tag_3BA0 &o) : c(o.c) {} };
struct T20_3BA0 { unsigned a; int b; int c; int d; Tag_3BA0 f; };
extern T20_3BA0 D_4FBC80_3BA0 __asm__("D_004FBC80");
extern int D_57E0_3BA0 __asm__("D_004A57E0");
extern const int D_004465D8_3BA0[] __asm__("D_004465D8");
extern "C" void* func_003E6574_3BA0(void*, void*, int) __asm__("func_003E6574");
extern "C" void func_00229820_3BA0(int, unsigned, int, int) __asm__("func_00229820");
extern "C" void func_00229788_3BA0(int, unsigned, int, int) __asm__("func_00229788");
extern "C" void func_002297D8_3BA0(int, unsigned, int, int) __asm__("func_002297D8");
struct Ent_3BA0 { int idx; int val; int pad; int type; };
extern "C" V3_3BA0 func_00303BA0(int n, Ent_3BA0 *e) {
    if (D_57E0_3BA0 == 0) {
        D_4FBC80_3BA0.a = 0xFFFFFFFF;
        D_4FBC80_3BA0.b = -1;
        D_4FBC80_3BA0.c = 0;
        D_4FBC80_3BA0.d = 0;
        D_57E0_3BA0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_4FBC80_3BA0.f = Tag_3BA0(D_4FBC80_3BA0.f);
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_3BA0(buf, &D_4FBC80_3BA0, 0x14);
    Ent_3BA0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004465D8_3BA0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_3BA0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_3BA0 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        int mode = buf[1];
        int a = buf[2];
        int b = buf[3];
        unsigned h = *(unsigned*)(obj + 0x78);
        if (mode == 0)
            func_00229820_3BA0(D_004A2A00_3BA0, h, a, b);
        else if (mode == 1) {
        } else if (mode == 2)
            func_00229788_3BA0(D_004A2A00_3BA0, h, a, b);
        else if (mode == 3)
            func_002297D8_3BA0(D_004A2A00_3BA0, h, a, b);
    }
    return D_004C9098_3BA0;
}
#endif

extern "C" void func_00303D88(void) {
}

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303D90);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
extern "C" int cBE_getBE_3D90(void) __asm__("cBE_getBE");
void* cBE_getInterface_Fv_3D90(int be, int kind) __asm__("cBE_getInterface__Fv");
extern const int D_004465E8_3D90[] __asm__("D_004465E8");
extern signed char D_00535C11_3D90[] __asm__("D_00535C11");
extern "C" int func_00303D90(unsigned i) {
    if (i < 4) {
        cBE_getInterface_Fv_3D90(cBE_getBE_3D90(), 0);
        return D_004465E8_3D90[i] == D_00535C11_3D90[0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303DF8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
extern "C" int cBE_getBE_3DF8(void) __asm__("cBE_getBE");
void* cBE_getInterface_Fv_3DF8(int be, int kind) __asm__("cBE_getInterface__Fv");
extern const int D_004465F8_3DF8[] __asm__("D_004465F8");
extern signed char D_00535C10_3DF8[] __asm__("D_00535C10");
extern "C" int func_00303DF8(unsigned i) {
    if (i < 8) {
        cBE_getInterface_Fv_3DF8(cBE_getBE_3DF8(), 0);
        return D_004465F8_3DF8[i] == D_00535C10_3DF8[0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303E60);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
extern "C" int cBE_getBE_3E60(void) __asm__("cBE_getBE");
void* cBE_getInterface_Fv_3E60(int be, int kind) __asm__("cBE_getInterface__Fv");
extern const int D_00446618_3E60[] __asm__("D_00446618");
extern signed char D_00535C12_3E60[] __asm__("D_00535C12");
extern "C" int func_00303E60(unsigned i) {
    if (i < 0xF) {
        cBE_getInterface_Fv_3E60(cBE_getBE_3E60(), 0);
        return D_00446618_3E60[i] == D_00535C12_3E60[0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303EC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int* func_00226610(void*);
extern char *D_004A3DD8_3EC8 __asm__("D_004A3DD8");
extern char *D_004A28A8_3EC8 __asm__("D_004A28A8");
struct A_3EC8 { char pad[0x6C0]; };
struct B_3EC8 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual bool v09(); };
struct D_3EC8 : A_3EC8, B_3EC8 { };
struct Tab_3EC8 { char pad[0x28]; D_3EC8 *arr[1]; };
static inline bool isIdle_3EC8(int slot) {
    if (slot != -1) {
        D_3EC8 *r = (*(Tab_3EC8**)(*(char**)(D_004A28A8_3EC8 + 0x84) + 0xC))->arr[slot];
        B_3EC8 *b = r;
        D_3EC8 *d = (D_3EC8*)b;
        return !d->v09();
    }
    return false;
}
extern "C" void* func_00303EC8(void* self) {
    if (isIdle_3EC8(*(int*)D_004A3DD8_3EC8)) {
        *(int*)((char*)self + 8) = 1;
        *func_00226610(self) = 1;
    } else {
        *(int*)((char*)self + 8) = 1;
        *func_00226610(self) = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303F80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_3F80 __asm__("D_004A3DD8");
extern char *D_004A28A8_3F80 __asm__("D_004A28A8");
struct V3_3F80 { float x, y, z; };
extern V3_3F80 D_004C9098_3F80 __asm__("D_004C9098");
struct A_3F80 { char pad[0x6C0]; };
struct B_3F80 { virtual void v01(); };
struct D_3F80 : A_3F80, B_3F80 { };
struct Tab_3F80 { char pad[0x28]; D_3F80 *arr[1]; };
extern "C" V3_3F80 func_00303F80(void) {
    int slot = *(int*)D_004A3DD8_3F80;
    if (slot != -1) {
        D_3F80 *r = (*(Tab_3F80**)(*(char**)(D_004A28A8_3F80 + 0x84) + 0xC))->arr[slot];
        B_3F80 *b = r;
        D_3F80 *d = (D_3F80*)b;
        *(int*)((char*)d + 0x3FC) = 1;
    }
    return D_004C9098_3F80;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303FF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_3FF0 { char c; Flag_3FF0() {} Flag_3FF0(const Flag_3FF0& o) : c(o.c) {} };
struct Ent_3FF0 { int idx; int val; int pad; int kind; };
struct R12_3FF0 { int a; int b; int c; };
extern R12_3FF0 D_004C9098_3FF0 __asm__("D_004C9098");

extern int D_004A3D40_3FF0[2] __asm__("D_004A3D40");
void func_0030B4C0(void*, int, int);
extern void* D_004A3DD8_3FF0 __asm__("D_004A3DD8");
extern int D_004A57E4_3FF0 __asm__("D_004A57E4");
struct T12_3FF0 { int a; int b; Flag_3FF0 f; };
extern T12_3FF0 D_004FBC98_3FF0 __asm__("D_004FBC98");
extern "C" R12_3FF0 func_00303FF0(int n, Ent_3FF0* e) {
    if (D_004A57E4_3FF0 == 0) {
        D_004FBC98_3FF0.a = 0;
        D_004FBC98_3FF0.b = -1;
        D_004A57E4_3FF0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBC98_3FF0.f = Flag_3FF0(D_004FBC98_3FF0.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBC98_3FF0, 12);
    Ent_3FF0* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D40_3FF0[k] && D_004A3D40_3FF0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030B4C0(D_004A3DD8_3FF0, vp[0], vp[1]);
    return D_004C9098_3FF0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304100);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_4100 { char c; Flag_4100() {} Flag_4100(const Flag_4100& o) : c(o.c) {} };
struct Ent_4100 { int idx; int val; int pad; int kind; };
struct R12_4100 { int a; int b; int c; };
extern R12_4100 D_004C9098_4100 __asm__("D_004C9098");

extern int D_004A3D48_4100[2] __asm__("D_004A3D48");
void func_0030B4D8(void*, int, int);
extern void* D_004A3DD8_4100 __asm__("D_004A3DD8");
extern int D_004A57E8_4100 __asm__("D_004A57E8");
struct T12_4100 { int a; int b; Flag_4100 f; };
extern T12_4100 D_004FBCA8_4100 __asm__("D_004FBCA8");
extern "C" R12_4100 func_00304100(int n, Ent_4100* e) {
    if (D_004A57E8_4100 == 0) {
        D_004FBCA8_4100.a = 0;
        D_004A57E8_4100 = 1;
        D_004FBCA8_4100.b = 0;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBCA8_4100.f = Flag_4100(D_004FBCA8_4100.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBCA8_4100, 12);
    Ent_4100* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D48_4100[k] && D_004A3D48_4100[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030B4D8(D_004A3DD8_4100, vp[0], vp[1]);
    return D_004C9098_4100;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304210);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_4210 { char c; Flag_4210() {} Flag_4210(const Flag_4210& o) : c(o.c) {} };
struct Ent_4210 { int idx; int val; int pad; int kind; };
struct R12_4210 { int a; int b; int c; };
extern R12_4210 D_004C9098_4210 __asm__("D_004C9098");

extern int D_004A3D50_4210[2] __asm__("D_004A3D50");
void func_0030B4F0(void*, int, int);
extern void* D_004A3DD8_4210 __asm__("D_004A3DD8");
extern int D_004A57EC_4210 __asm__("D_004A57EC");
struct T12_4210 { int a; int b; Flag_4210 f; };
extern T12_4210 D_004FBCB8_4210 __asm__("D_004FBCB8");
extern "C" R12_4210 func_00304210(int n, Ent_4210* e) {
    if (D_004A57EC_4210 == 0) {
        D_004FBCB8_4210.a = 0;
        D_004FBCB8_4210.b = -1;
        D_004A57EC_4210 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBCB8_4210.f = Flag_4210(D_004FBCB8_4210.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBCB8_4210, 12);
    Ent_4210* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D50_4210[k] && D_004A3D50_4210[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030B4F0(D_004A3DD8_4210, vp[0], vp[1]);
    return D_004C9098_4210;
}
#endif

INCLUDE_ASM("seg/seg_1FBE38", func_00304320);

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003044A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_44A8 { char c; Flag_44A8() {} Flag_44A8(const Flag_44A8& o) : c(o.c) {} };
struct Ent_44A8 { int idx; int val; int pad; int kind; };
struct R12_44A8 { int a; int b; int c; };
extern R12_44A8 D_004C9098_44A8 __asm__("D_004C9098");

extern int D_004A3D60_44A8[2] __asm__("D_004A3D60");
extern "C" void func_00238550(int, int, int);
extern int* D_004A3DD8_44A8 __asm__("D_004A3DD8");
extern char* D_004A28A8_44A8 __asm__("D_004A28A8");
extern int D_004A5808_44A8 __asm__("D_004A5808");
extern int D_004A5800_44A8 __asm__("D_004A5800");
extern Flag_44A8 D_004A5804_44A8 __asm__("D_004A5804");
extern "C" R12_44A8 func_003044A8(int n, Ent_44A8* e) {
    if (D_004A5808_44A8 == 0) {
        D_004A5800_44A8 = -1;
        D_004A5808_44A8 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A5804_44A8 = Flag_44A8(D_004A5804_44A8);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5800_44A8, 8);
    Ent_44A8* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D60_44A8[k] && D_004A3D60_44A8[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int b = *D_004A3DD8_44A8;
    func_00238550(*(int*)(D_004A28A8_44A8 + 0xC0), b, vp[0]);
    return D_004C9098_44A8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003045B8);
#ifdef SKIP_ASM
// PORT: 64-bit bitfield container (unsigned long is 8 bytes on the EE).
extern char *D_004A3DD8_45B8 __asm__("D_004A3DD8");
struct V3_45B8 { float x, y, z; };
extern V3_45B8 D_004C9098_45B8 __asm__("D_004C9098");
struct Tag_45B8 { char c; Tag_45B8() {} Tag_45B8(const Tag_45B8 &o) : c(o.c) {} };
struct Rec_45B8 {
    unsigned a0; int a1; int a2; int a3;
    unsigned a4; unsigned a5; unsigned a6; unsigned a7;
    unsigned a8; unsigned a9; unsigned a10; unsigned a11;
    unsigned a12; unsigned a13; unsigned a14; unsigned a15;
    Tag_45B8 f;
};
extern Rec_45B8 D_4FBCC8_45B8 __asm__("D_004FBCC8");
extern int D_580C_45B8 __asm__("D_004A580C");
extern const int D_00446650_45B8[] __asm__("D_00446650");
extern "C" void* func_003E6574_45B8(void*, void*, int) __asm__("func_003E6574");
struct BF_45B8 {
    unsigned long f0 : 3; unsigned long f1 : 4; unsigned long f2 : 3; unsigned long f3 : 2;
    unsigned long f4 : 4; unsigned long f5 : 3; unsigned long f6 : 3; unsigned long f7 : 6;
    unsigned long f8 : 4; unsigned long f9 : 3; unsigned long f10 : 7; unsigned long f11 : 1;
    unsigned long f12 : 7; unsigned long f13 : 2; unsigned long f14 : 4; unsigned long f15 : 3;
    unsigned long f16 : 5;
};
extern "C" void func_0030B520_45B8(char*, BF_45B8*) __asm__("func_0030B520");
struct Ent_45B8 { int idx; int val; int pad; int type; };
extern "C" V3_45B8 func_003045B8(int n, Ent_45B8 *e) {
    if (D_580C_45B8 == 0) {
        D_4FBCC8_45B8.a0 = 0;
        D_4FBCC8_45B8.a1 = 0;
        D_4FBCC8_45B8.a2 = 0;
        D_4FBCC8_45B8.a3 = 0;
        D_4FBCC8_45B8.a4 = 0;
        D_4FBCC8_45B8.a5 = 0;
        D_4FBCC8_45B8.a6 = 0;
        D_4FBCC8_45B8.a7 = 0;
        D_4FBCC8_45B8.a8 = 0;
        D_4FBCC8_45B8.a9 = 0;
        D_4FBCC8_45B8.a10 = 0;
        D_4FBCC8_45B8.a11 = 0;
        D_4FBCC8_45B8.a12 = 0;
        D_4FBCC8_45B8.a13 = 0;
        D_4FBCC8_45B8.a14 = 0;
        D_4FBCC8_45B8.a15 = 0;
        D_580C_45B8 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_4FBCC8_45B8.f = Tag_45B8(D_4FBCC8_45B8.f);
    }
    Rec_45B8 rec;
    Rec_45B8 *buf = &rec;
    func_003E6574_45B8(buf, &D_4FBCC8_45B8, 0x44);
    BF_45B8 bf;
    Ent_45B8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446650_45B8[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    bf.f0 = buf->a0;
    bf.f1 = buf->a1;
    bf.f2 = buf->a2;
    bf.f3 = buf->a3;
    bf.f4 = buf->a4;
    bf.f5 = buf->a5;
    bf.f6 = buf->a6;
    bf.f7 = buf->a7;
    bf.f8 = buf->a8;
    bf.f9 = buf->a9;
    bf.f10 = buf->a10;
    bf.f11 = buf->a11;
    bf.f12 = buf->a12;
    bf.f13 = buf->a13;
    bf.f15 = buf->a14;
    bf.f14 = buf->a15;
    bf.f16 = 0;
    func_0030B520_45B8(D_004A3DD8_45B8, &bf);
    return D_004C9098_45B8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304980);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_4980 __asm__("D_004A3DD8");
extern char **D_004A47B8_4980 __asm__("D_004A47B8");
extern char *D_004A28A8_4980 __asm__("D_004A28A8");
void func_00355878(void*, void*);
struct O_4980 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_4980 { float x, y, z; };
extern V3_4980 D_004C9098_4980 __asm__("D_004C9098");
struct Tag_4980 { char c; Tag_4980() {} Tag_4980(const Tag_4980 &o) : c(o.c) {} };
extern unsigned D_4980[] __asm__("D_004FBD10");
extern int D_004A5810;
extern int D_004A3D68;
extern "C" void* func_003E6574_4980(void*, void*, int) __asm__("func_003E6574");
struct Ent_4980 { int idx; int val; int pad; int type; };
extern "C" V3_4980 func_00304980(int n, Ent_4980 *e) {
    if (D_004A5810 == 0) {
        D_4980[0] = 0xFFFFFFFF;
        *(float*)&D_4980[1] = 1.0f;
        D_004A5810 = 1;
        (*(Tag_4980*)((char*)D_4980 + 8)) = Tag_4980((*(Tag_4980*)((char*)D_4980 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_4980(buf, D_4980, 12);
    Ent_4980 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3D68)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_4980 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_4980 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_4980 *p = *(O_4980**)(obj + 0xC);
    if (p == 0)
        return D_004C9098_4980;
    if (p->v16())
        func_00355878(p, buf);
    return D_004C9098_4980;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304B38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_4B38 { char c; Flag_4B38() {} Flag_4B38(const Flag_4B38& o) : c(o.c) {} };
struct Ent_4B38 { int idx; int val; int pad; int kind; };
struct R12_4B38 { int a; int b; int c; };
extern R12_4B38 D_004C9098_4B38 __asm__("D_004C9098");

extern int D_004A3D70_4B38[2] __asm__("D_004A3D70");
extern "C" void func_002709D8(int, int, int);
extern int* D_004A3DD8_4B38 __asm__("D_004A3DD8");
extern char* D_004A28A8_4B38 __asm__("D_004A28A8");
extern int D_004A5820_4B38 __asm__("D_004A5820");
extern int D_004A5818_4B38 __asm__("D_004A5818");
extern Flag_4B38 D_004A581C_4B38 __asm__("D_004A581C");
extern "C" R12_4B38 func_00304B38(int n, Ent_4B38* e) {
    if (D_004A5820_4B38 == 0) {
        D_004A5818_4B38 = -1;
        D_004A5820_4B38 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A581C_4B38 = Flag_4B38(D_004A581C_4B38);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5818_4B38, 8);
    Ent_4B38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D70_4B38[k] && D_004A3D70_4B38[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_002709D8(*(int*)(*(char**)(D_004A28A8_4B38 + 0x84) + 0x28), *D_004A3DD8_4B38, vp[0]);
    return D_004C9098_4B38;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304C50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* func_00226618(void*);
extern "C" void func_003E6574(void*, void*, int);
struct Tag_4C50 { char c; Tag_4C50() {} Tag_4C50(const Tag_4C50 &o) : c(o.c) {} };
struct Ent_4C50 { int idx; int val; int pad; int type; };
extern char *D_004A3DD8_4C50 __asm__("D_004A3DD8");
extern char **D_004A47B8_4C50 __asm__("D_004A47B8");
extern char *D_004A28A8_4C50 __asm__("D_004A28A8");
extern unsigned D_5828_4C50 __asm__("D_004A5828");
extern Tag_4C50 D_582C_4C50 __asm__("D_004A582C");
extern int D_5830_4C50 __asm__("D_004A5830");
extern int D_3D78_4C50 __asm__("D_004A3D78");
struct Vec_4C50 { float x, y, z, w; } __attribute__((aligned(16)));
struct A_4C50 { char pad[0x6C0]; };
struct B_4C50 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual Vec_4C50 *v05(); };
struct D_4C50 : A_4C50, B_4C50 { };
struct Tab_4C50 { char pad[0x28]; D_4C50 *arr[1]; };
static inline Vec_4C50 pos_4C50(char *o) { return *(Vec_4C50*)(o + 0x40); }
extern "C" void* func_00304C50(void* self, int n, Ent_4C50 *e) {
    if (D_5830_4C50 == 0) {
        D_5828_4C50 = 0xFFFFFFFF;
        D_5830_4C50 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_582C_4C50 = Tag_4C50(D_582C_4C50);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_5828_4C50, 8);
    Ent_4C50 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_3D78_4C50)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    int slot = *(int*)D_004A3DD8_4C50;
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_4C50 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_4C50 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        D_4C50 *rr = (*(Tab_4C50**)(*(char**)(D_004A28A8_4C50 + 0x84) + 0xC))->arr[slot];
        B_4C50 *b = rr;
        D_4C50 *d = (D_4C50*)b;
        float v;
        if (d) {
            float z = d->v05()->z;
            v = z - pos_4C50(obj).z;
        }
        else
            v = 0.0f;
        *(int*)((char*)self + 8) = 2;
        *(float*)func_00226618(self) = v;
    } else {
        *(int*)((char*)self + 8) = 2;
        *(int*)func_00226618(self) = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304E38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_4E38 __asm__("D_004A3DD8");
extern char **D_004A47B8_4E38 __asm__("D_004A47B8");
extern char *D_004A28A8_4E38 __asm__("D_004A28A8");
extern "C" void func_00355888_4E38(void*, void*) __asm__("func_00355888");
struct O_4E38 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_4E38 { float x, y, z; };
extern V3_4E38 D_004C9098_4E38 __asm__("D_004C9098");
struct Tag_4E38 { char c; Tag_4E38() {} Tag_4E38(const Tag_4E38 &o) : c(o.c) {} };
extern unsigned D_4E38[] __asm__("D_004FBD20");
extern int D_004A5834;
extern int D_004A3D80;
extern "C" void* func_003E6574_4E38(void*, void*, int) __asm__("func_003E6574");
struct Ent_4E38 { int idx; int val; int pad; int type; };
extern "C" V3_4E38 func_00304E38(int n, Ent_4E38 *e) {
    if (D_004A5834 == 0) {
        D_4E38[0] = 0xFFFFFFFF;
        *(float*)&D_4E38[1] = 1.0f;
        D_004A5834 = 1;
        (*(Tag_4E38*)((char*)D_4E38 + 8)) = Tag_4E38((*(Tag_4E38*)((char*)D_4E38 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574_4E38(buf, D_4E38, 12);
    Ent_4E38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3D80)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_4E38 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_4E38 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    O_4E38 *p = *(O_4E38**)(obj + 0xC);
    if (p == 0)
        return D_004C9098_4E38;
    if (p->v16())
        func_00355888_4E38(p, buf);
    return D_004C9098_4E38;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304FF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A5838_4FF0 __asm__("D_004A5838");
extern int D_004A3D88_4FF0[2] __asm__("D_004A3D88");
extern "C" void func_003E6574(void*, void*, int);

struct Flag_4FF0 { char c; Flag_4FF0() {} Flag_4FF0(const Flag_4FF0& o) : c(o.c) {} };
struct Ent_4FF0 { int idx; int val; int pad; int kind; };
struct R12_4FF0 { int a; int b; int c; };
struct T12_4FF0 { int a; int b; Flag_4FF0 f; };
extern T12_4FF0 D_004FBD30_4FF0 __asm__("D_004FBD30");
extern R12_4FF0 D_004C9098_4FF0 __asm__("D_004C9098");

extern "C" R12_4FF0 func_00304FF0(int n, Ent_4FF0* e) {
    if (D_004A5838_4FF0 == 0) {
        D_004FBD30_4FF0.a = 0;
        D_004A5838_4FF0 = 1;
        D_004FBD30_4FF0.b = 0;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBD30_4FF0.f = Flag_4FF0(D_004FBD30_4FF0.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBD30_4FF0, 12);
    Ent_4FF0* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D88_4FF0[k] && D_004A3D88_4FF0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    return D_004C9098_4FF0;
}
#endif

INCLUDE_ASM("seg/seg_1FBE38", func_003050F0);

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305478);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_5478 __asm__("D_004A3DD8");
extern char **D_004A47B8_5478 __asm__("D_004A47B8");
struct O_5478 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void *v24(); };
struct V3_5478 { float x, y, z; };
extern V3_5478 D_004C9098_5478 __asm__("D_004C9098");
struct Tag_5478 { char c; Tag_5478() {} Tag_5478(const Tag_5478 &o) : c(o.c) {} };
struct Rec_5478 { unsigned id; float a; float b; Tag_5478 f; };
extern Rec_5478 D_4FBD58_5478 __asm__("D_004FBD58");
extern int D_5840_5478 __asm__("D_004A5840");
extern const int D_004466A0_5478[] __asm__("D_004466A0");
extern "C" void* func_003E6574_5478(void*, void*, int) __asm__("func_003E6574");
extern "C" void func_003559F8_5478(O_5478*, void*, float, float) __asm__("func_003559F8");
struct Ent_5478 { int idx; int val; int pad; int type; };
extern "C" V3_5478 func_00305478(int n, Ent_5478 *e) {
    if (D_5840_5478 == 0) {
        D_4FBD58_5478.id = 0xFFFFFFFF;
        D_4FBD58_5478.a = 400.0f;
        D_4FBD58_5478.b = 30.0f;
        D_5840_5478 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_4FBD58_5478.f = Tag_5478(D_4FBD58_5478.f);
    }
    Rec_5478 rec;
    Rec_5478 *buf = &rec;
    rec.id = 0xFFFFFFFF;
    func_003E6574_5478(buf, &D_4FBD58_5478, 0x10);
    Ent_5478 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004466A0_5478[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf->id;
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_5478 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_5478 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        O_5478 *p = *(O_5478**)(obj + 0xC);
        if (p) {
            if (p->v16())
                func_003559F8_5478(p, p->v24(), buf->a, buf->b);
        }
    }
    return D_004C9098_5478;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305660);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int *D_004A3DD8_5660 __asm__("D_004A3DD8");
extern char *D_004A28A8_5660 __asm__("D_004A28A8");
struct Sh_5660 { virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual int v08(); };
extern "C" void func_00390EC8_5660(float) __asm__("func_00390EC8");
struct V3_5660 { float x, y, z; };
extern V3_5660 D_004C9098_5660 __asm__("D_004C9098");
struct Tag_5660 { char c; Tag_5660() {} Tag_5660(const Tag_5660 &o) : c(o.c) {} };
extern unsigned D_5660 __asm__("D_004A5848");
extern Tag_5660 D_004A584C;
extern int D_004A5850;
extern int D_004A3D90;
extern "C" void* func_003E6574_5660(void*, void*, int) __asm__("func_003E6574");
struct Ent_5660 { int idx; int val; int pad; int type; };
extern "C" V3_5660 func_00305660(int n, Ent_5660 *e) {
    if (D_004A5850 == 0) {
        D_5660 = 0xFFFFFFFF;
        D_004A5850 = 1;
        D_004A584C = Tag_5660(D_004A584C);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_5660(buf, &D_5660, 8);
    Ent_5660 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3D90)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    int k = *D_004A3DD8_5660;
    if (k != -1) {
        int k4 = k * 4;
        char *lvl = *(char**)(*(char**)(D_004A28A8_5660 + 0x84) + 0xC);
        char *q = *(char**)(lvl + k4 + 0x28);
        Sh_5660 *sh = q ? (Sh_5660*)(q + 0x6C0) : 0;
        if (sh->v08())
            func_00390EC8_5660(0.0f);
    }
    return D_004C9098_5660;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003057C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_57C0 __asm__("D_004A3DD8");
extern char **D_004A47B8_57C0 __asm__("D_004A47B8");
struct O_57C0 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void *v24(); };
struct V3_57C0 { float x, y, z; };
extern V3_57C0 D_004C9098_57C0 __asm__("D_004C9098");
struct Tag_57C0 { char c; Tag_57C0() {} Tag_57C0(const Tag_57C0 &o) : c(o.c) {} };
struct Rec_57C0 { unsigned id; int a; int b; float c; float d; float e; float g; float h; int k; Tag_57C0 f; };
extern Rec_57C0 D_4FBD68_57C0 __asm__("D_004FBD68");
extern int D_5854_57C0 __asm__("D_004A5854");
extern const int D_004466B0_57C0[] __asm__("D_004466B0");
extern "C" void* func_003E6574_57C0(void*, void*, int) __asm__("func_003E6574");
extern "C" void cMoveNode_addHalo_57C0(void*, void*) __asm__("cMoveNode_addHalo");
struct Ent_57C0 { int idx; int val; int pad; int type; };
extern "C" V3_57C0 func_003057C0(int n, Ent_57C0 *e) {
    if (D_5854_57C0 == 0) {
        D_4FBD68_57C0.id = 0xFFFFFFFF;
        D_4FBD68_57C0.a = 0;
        D_4FBD68_57C0.b = -1;
        D_4FBD68_57C0.c = 1.0f;
        D_4FBD68_57C0.d = 1.0f;
        D_4FBD68_57C0.e = 1.0f;
        D_4FBD68_57C0.g = 1.0f;
        D_4FBD68_57C0.h = 100.0f;
        D_4FBD68_57C0.k = 0;
        D_5854_57C0 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_4FBD68_57C0.f = Tag_57C0(D_4FBD68_57C0.f);
    }
    Rec_57C0 rec;
    Rec_57C0 *buf = &rec;
    rec.id = 0xFFFFFFFF;
    func_003E6574_57C0(buf, &D_4FBD68_57C0, 0x28);
    Ent_57C0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004466B0_57C0[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf->id;
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_57C0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_57C0 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        O_57C0 *p = *(O_57C0**)(obj + 0xC);
        if (p) {
            if (p->v16())
                cMoveNode_addHalo_57C0(p, buf);
        }
    }
    return D_004C9098_57C0;
}
#endif

INCLUDE_ASM("seg/seg_1FBE38", func_003059A0);

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305C88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_5C88 { char c; Flag_5C88() {} Flag_5C88(const Flag_5C88& o) : c(o.c) {} };
struct Ent_5C88 { int idx; int val; int pad; int kind; };
struct R12_5C88 { int a; int b; int c; };
extern R12_5C88 D_004C9098_5C88 __asm__("D_004C9098");

extern int D_004A3D98_5C88[2] __asm__("D_004A3D98");
extern "C" int cAvalanche_triggerAvalanche(int);
extern int D_004A3AC4_5C88 __asm__("D_004A3AC4");
extern int D_004A5868_5C88 __asm__("D_004A5868");
extern int D_004A5860_5C88 __asm__("D_004A5860");
extern Flag_5C88 D_004A5864_5C88 __asm__("D_004A5864");
extern "C" R12_5C88 func_00305C88(int n, Ent_5C88* e) {
    if (D_004A5868_5C88 == 0) {
        D_004A5868_5C88 = 1;
        D_004A5860_5C88 = 0;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004A5864_5C88 = Flag_5C88(D_004A5864_5C88);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5860_5C88, 8);
    Ent_5C88* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3D98_5C88[k] && D_004A3D98_5C88[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int a = vp[0];
    if (D_004A3AC4_5C88 == 0)
        cAvalanche_triggerAvalanche(a);
    return D_004C9098_5C88;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305D90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_5D90 __asm__("D_004A3DD8");
extern char **D_004A47B8_5D90 __asm__("D_004A47B8");
extern char *D_004A28A8_5D90 __asm__("D_004A28A8");
static inline char *refToPtr_5D90(unsigned i) { return (char*)(i << 2); }
static inline char *conv_5D90(unsigned i) { if (i == 0) return 0; return refToPtr_5D90(i); }
extern "C" void func_00355A78_5D90(void*, void*) __asm__("func_00355A78");
struct O_5D90 { int p0, p1, p2; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
struct V3_5D90 { float x, y, z; };
extern V3_5D90 D_004C9098_5D90 __asm__("D_004C9098");
struct Tag_5D90 { char c; Tag_5D90() {} Tag_5D90(const Tag_5D90 &o) : c(o.c) {} };
extern unsigned D_5D90 __asm__("D_004A5870");
extern Tag_5D90 D_004A5874;
extern int D_004A5878;
extern int D_004A3DA0;
extern "C" void* func_003E6574_5D90(void*, void*, int) __asm__("func_003E6574");
struct Ent_5D90 { int idx; int val; int pad; int type; };
extern "C" V3_5D90 func_00305D90(int n, Ent_5D90 *e) {
    if (D_004A5878 == 0) {
        D_5D90 = 0xFFFFFFFF;
        D_004A5878 = 1;
        D_004A5874 = Tag_5D90(D_004A5874);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_5D90(buf, &D_5D90, 8);
    Ent_5D90 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3DA0)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_5D90 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_5D90 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_5D90(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        O_5D90 *p = *(O_5D90**)(obj + 0xC);
        if (p) {
            if (p->v16())
                func_00355A78_5D90(p, obj);
        }
    }
    return D_004C9098_5D90;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305F40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char **D_004A47B8_5F40 __asm__("D_004A47B8");
struct V3_5F40 { float x, y, z; };
extern V3_5F40 D_004C9098_5F40 __asm__("D_004C9098");
struct Tag_5F40 { char c; Tag_5F40() {} Tag_5F40(const Tag_5F40 &o) : c(o.c) {} };
struct Rec_5F40 {
    int a; int b; float c; float d; float e;
    float m[28];
    float v[16];
    int k; int l; float n; int o; float p; unsigned id;
    Tag_5F40 f;
};
extern Rec_5F40 D_4FBE58_5F40 __asm__("D_004FBE58");
extern int D_587C_5F40 __asm__("D_004A587C");
extern const int D_004467A0_5F40[] __asm__("D_004467A0");
extern "C" void* func_003E6574_5F40(void*, void*, int) __asm__("func_003E6574");
extern "C" void func_002D9538_5F40(char*, Rec_5F40*) __asm__("func_002D9538");
static inline char *refToPtr_5F40(unsigned i) { return (char*)(i << 2); }
static inline char *conv_5F40(unsigned i) { if (i == 0) return 0; return refToPtr_5F40(i); }
struct Ent_5F40 { int idx; int val; int pad; int type; };
extern "C" V3_5F40 func_00305F40(int n, Ent_5F40 *e) {
    if (D_587C_5F40 == 0) {
        Rec_5F40 &r = D_4FBE58_5F40;
        float zero = 0.0f;
        float one = 1.0f;
        r.a = 1;
        r.b = 0;
        r.c = -1.0f;
        r.d = one;
        r.e = 4.0f;
        r.m[0] = zero;
        r.m[1] = zero;
        r.m[2] = zero;
        r.m[3] = zero;
        r.m[4] = zero;
        r.m[5] = zero;
        r.m[6] = zero;
        r.m[7] = zero;
        r.m[8] = zero;
        r.m[9] = zero;
        r.m[10] = zero;
        r.m[11] = zero;
        r.m[12] = zero;
        r.m[13] = zero;
        r.m[14] = zero;
        r.m[15] = zero;
        r.m[16] = zero;
        r.m[17] = zero;
        r.m[18] = zero;
        r.m[19] = zero;
        r.m[20] = zero;
        r.m[21] = zero;
        r.m[22] = zero;
        r.m[23] = zero;
        r.m[24] = zero;
        r.m[25] = zero;
        r.m[26] = zero;
        r.m[27] = zero;
        r.v[0] = one;
        r.v[1] = zero;
        r.v[2] = zero;
        r.v[3] = zero;
        r.v[4] = one;
        r.v[5] = one;
        r.v[6] = one;
        r.v[7] = one;
        r.v[8] = one;
        r.v[9] = zero;
        r.v[10] = zero;
        r.v[11] = zero;
        r.v[12] = one;
        r.v[13] = zero;
        r.v[14] = zero;
        r.v[15] = zero;
        r.k = 16;
        r.l = 0;
        r.n = zero;
        r.o = 1;
        r.p = 20.0f;
        r.id = 0xFFFFFFFF;
        D_587C_5F40 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        r.f = Tag_5F40(r.f);
    }
    Rec_5F40 rec;
    Rec_5F40 *buf = &rec;
    rec.id = 0xFFFFFFFF;
    func_003E6574_5F40(buf, &D_4FBE58_5F40, 0xE0);
    Ent_5F40 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004467A0_5F40[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf->id;
    if (~id != 0) {
        char *s = (*(char***)((char*)*D_004A47B8_5F40 + 8))[id & 0xFF];
        char *obj;
        if (!s)
            obj = 0;
        else
            obj = conv_5F40(((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8);
        func_002D9538_5F40(obj, buf);
    }
    return D_004C9098_5F40;
}
#endif

INCLUDE_ASM("seg/seg_1FBE38", func_003061B0);

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306300);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_6300 { char c; Flag_6300() {} Flag_6300(const Flag_6300& o) : c(o.c) {} };
struct Ent_6300 { int idx; int val; int pad; int kind; };
struct R12_6300 { int a; int b; int c; };
extern R12_6300 D_004C9098_6300 __asm__("D_004C9098");

extern int D_004A3DB0_6300[2] __asm__("D_004A3DB0");
extern "C" void func_001E3510(int, int);
extern int D_00534B30_6300[] __asm__("D_00534B30");
extern "C" void* cBE_getInterface_6300(int, int) __asm__("cBE_getInterface__Fv");
extern char* D_004A28A8_6300 __asm__("D_004A28A8");
extern int D_004A588C_6300 __asm__("D_004A588C");
struct T12_6300 { int a; int b; Flag_6300 f; };
extern T12_6300 D_004FBF38_6300 __asm__("D_004FBF38");
extern "C" R12_6300 func_00306300(int n, Ent_6300* e) {
    if (D_004A588C_6300 == 0) {
        D_004FBF38_6300.a = 0;
        D_004A588C_6300 = 1;
        D_004FBF38_6300.b = 0;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FBF38_6300.f = Flag_6300(D_004FBF38_6300.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBF38_6300, 12);
    Ent_6300* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3DB0_6300[k] && D_004A3DB0_6300[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int x = vp[0];
    int y = vp[1];
    cBE_getInterface_6300(*(int*)(D_004A28A8_6300 + 0x78), 7);
    if (D_00534B30_6300[0] == 0)
        func_001E3510(x, y);
    return D_004C9098_6300;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306438);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_6438 __asm__("D_004A3DD8");
extern char **D_004A47B8_6438 __asm__("D_004A47B8");
extern char *D_004A28A8_6438 __asm__("D_004A28A8");
extern "C" void func_00101728_6438(void*, void*, float, float) __asm__("func_00101728");
struct V3_6438 { float x, y, z; };
extern V3_6438 D_004C9098_6438 __asm__("D_004C9098");
struct Tag_6438 { char c; Tag_6438() {} Tag_6438(const Tag_6438 &o) : c(o.c) {} };
extern unsigned D_6438[] __asm__("D_004FBF48");
extern int D_004A5890;
extern const int D_00446880[];
extern "C" void* func_003E6574_6438(void*, void*, int) __asm__("func_003E6574");
struct Ent_6438 { int idx; int val; int pad; int type; };
extern "C" V3_6438 func_00306438(int n, Ent_6438 *e) {
    if (D_004A5890 == 0) {
        D_6438[0] = 0xFFFFFFFF;
        *(float*)&D_6438[1] = 1000.0f;
        ((int*)D_6438)[2] = 0;
        D_004A5890 = 1;
        (*(Tag_6438*)((char*)D_6438 + 12)) = Tag_6438((*(Tag_6438*)((char*)D_6438 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_6438(buf, D_6438, 16);
    Ent_6438 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446880[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_6438 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_6438 + 8))[id & 0xFF];
        unsigned i;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        float f1 = *(float*)&buf[1];
        float f2 = *(float*)&buf[2];
        int tmp[1];
        tmp[0] = *(int*)(obj + 0x78);
        func_00101728_6438(*(void**)(*(char**)(*(char**)(D_004A28A8_6438 + 0x84) + 0xC) + 0xA8), tmp, f1, f2);
    }
    return D_004C9098_6438;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003065E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_65E8 __asm__("D_004A3DD8");
extern char **D_004A47B8_65E8 __asm__("D_004A47B8");
extern char *D_004A28A8_65E8 __asm__("D_004A28A8");
static inline char *look_65E8(unsigned id) {
    if (~id == 0)
        return *(char**)(D_004A3DD8_65E8 + 0x290);
    char *s = (*(char***)((char*)*D_004A47B8_65E8 + 8))[id & 0xFF];
    unsigned i;
    if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}

extern "C" void func_00101888_65E8(void*, void*) __asm__("func_00101888");
struct V3_65E8 { float x, y, z; };
extern V3_65E8 D_004C9098_65E8 __asm__("D_004C9098");
struct Tag_65E8 { char c; Tag_65E8() {} Tag_65E8(const Tag_65E8 &o) : c(o.c) {} };
extern unsigned D_65E8 __asm__("D_004A5898");
extern Tag_65E8 D_004A589C;
extern int D_004A58A0;
extern int D_004A3DB8;
extern "C" void* func_003E6574_65E8(void*, void*, int) __asm__("func_003E6574");
struct Ent_65E8 { int idx; int val; int pad; int type; };
extern "C" V3_65E8 func_003065E8(int n, Ent_65E8 *e) {
    if (D_004A58A0 == 0) {
        D_65E8 = 0xFFFFFFFF;
        D_004A58A0 = 1;
        D_004A589C = Tag_65E8(D_004A589C);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_65E8(buf, &D_65E8, 8);
    Ent_65E8 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3DB8)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = look_65E8(buf[0]);
    if (obj) {
        int tmp[1]; tmp[0] = *(int*)(obj + 0x78);
        func_00101888_65E8(*(void**)(*(char**)(*(char**)(D_004A28A8_65E8 + 0x84) + 0xC) + 0xA8), tmp);
    }
    return D_004C9098_65E8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306770);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_6770 __asm__("D_004A3DD8");
extern char **D_004A47B8_6770 __asm__("D_004A47B8");
extern char *D_004A28A8_6770 __asm__("D_004A28A8");
static inline char *look_6770(unsigned id) {
    if (~id == 0)
        return *(char**)(D_004A3DD8_6770 + 0x290);
    char *s = (*(char***)((char*)*D_004A47B8_6770 + 8))[id & 0xFF];
    unsigned i;
    if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}

extern "C" void func_00101900_6770(void*, void*, int) __asm__("func_00101900");
struct V3_6770 { float x, y, z; };
extern V3_6770 D_004C9098_6770 __asm__("D_004C9098");
struct Tag_6770 { char c; Tag_6770() {} Tag_6770(const Tag_6770 &o) : c(o.c) {} };
extern unsigned D_6770[] __asm__("D_004FBF58");
extern int D_004A58A4;
extern int D_004A3DC0;
extern "C" void* func_003E6574_6770(void*, void*, int) __asm__("func_003E6574");
struct Ent_6770 { int idx; int val; int pad; int type; };
extern "C" V3_6770 func_00306770(int n, Ent_6770 *e) {
    if (D_004A58A4 == 0) {
        D_6770[0] = 0xFFFFFFFF;
        D_6770[1] = 0;
        D_004A58A4 = 1;
        (*(Tag_6770*)((char*)D_6770 + 8)) = Tag_6770((*(Tag_6770*)((char*)D_6770 + 8)));
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_6770(buf, D_6770, 12);
    Ent_6770 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3DC0)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_6770 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_6770 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }

    if (obj) {
        int b1 = buf[1];
        func_00101900_6770(*(void**)(*(char**)(*(char**)(D_004A28A8_6770 + 0x84) + 0xC) + 0xA8), obj + 0x78, b1);
    }
    return D_004C9098_6770;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306908);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_6908 __asm__("D_004A3DD8");
extern char **D_004A47B8_6908 __asm__("D_004A47B8");
extern char *D_004A28A8_6908 __asm__("D_004A28A8");
extern "C" void func_00101970_6908(void*, void*) __asm__("func_00101970");
struct V3_6908 { float x, y, z; };
extern V3_6908 D_004C9098_6908 __asm__("D_004C9098");
struct Tag_6908 { char c; Tag_6908() {} Tag_6908(const Tag_6908 &o) : c(o.c) {} };
extern unsigned D_6908 __asm__("D_004A58A8");
extern Tag_6908 D_004A58AC;
extern int D_004A58B0;
extern int D_004A3DC8;
extern "C" void* func_003E6574_6908(void*, void*, int) __asm__("func_003E6574");
struct Ent_6908 { int idx; int val; int pad; int type; };
extern "C" V3_6908 func_00306908(int n, Ent_6908 *e) {
    if (D_004A58B0 == 0) {
        D_6908 = 0xFFFFFFFF;
        D_004A58B0 = 1;
        D_004A58AC = Tag_6908(D_004A58AC);
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574_6908(buf, &D_6908, 8);
    Ent_6908 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3DC8)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_6908 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_6908 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj)
        func_00101970_6908(*(void**)(*(char**)(*(char**)(D_004A28A8_6908 + 0x84) + 0xC) + 0xA8), obj + 0x78);
    return D_004C9098_6908;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306A90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V3_6A90 { float x, y, z; };
extern V3_6A90 D_004C9098_6A90 __asm__("D_004C9098");
struct Tag_6A90 { char c; Tag_6A90() {} Tag_6A90(const Tag_6A90 &o) : c(o.c) {} };
struct Rec_6A90 {
    int a; int b; float c; float d; float e;
    float m[28];
    float v[16];
    int k; int l; float n; int o; float p; int q; int w;
    Tag_6A90 f;
};
extern Rec_6A90 D_4FBF68_6A90 __asm__("D_004FBF68");
extern int D_58B4_6A90 __asm__("D_004A58B4");
extern const int D_00446890_6A90[] __asm__("D_00446890");
extern "C" void* func_003E6574_6A90(void*, void*, int) __asm__("func_003E6574");
extern int D_004A4028_6A90 __asm__("D_004A4028");
extern "C" void func_00357A78_6A90(int, int, Rec_6A90*, int) __asm__("func_00357A78");
struct Ent_6A90 { int idx; int val; int pad; int type; };
extern "C" V3_6A90 func_00306A90(int n, Ent_6A90 *e) {
    if (D_58B4_6A90 == 0) {
        Rec_6A90 &r = D_4FBF68_6A90;
        float zero = 0.0f;
        float one = 1.0f;
        r.a = 1;
        r.b = 0;
        r.c = -1.0f;
        r.d = one;
        r.e = 4.0f;
        r.m[0] = zero;
        r.m[1] = zero;
        r.m[2] = zero;
        r.m[3] = zero;
        r.m[4] = zero;
        r.m[5] = zero;
        r.m[6] = zero;
        r.m[7] = zero;
        r.m[8] = zero;
        r.m[9] = zero;
        r.m[10] = zero;
        r.m[11] = zero;
        r.m[12] = zero;
        r.m[13] = zero;
        r.m[14] = zero;
        r.m[15] = zero;
        r.m[16] = zero;
        r.m[17] = zero;
        r.m[18] = zero;
        r.m[19] = zero;
        r.m[20] = zero;
        r.m[21] = zero;
        r.m[22] = zero;
        r.m[23] = zero;
        r.m[24] = zero;
        r.m[25] = zero;
        r.m[26] = zero;
        r.m[27] = zero;
        r.v[0] = one;
        r.v[1] = zero;
        r.v[2] = zero;
        r.v[3] = zero;
        r.v[4] = one;
        r.v[5] = one;
        r.v[6] = one;
        r.v[7] = one;
        r.v[8] = one;
        r.v[9] = zero;
        r.v[10] = zero;
        r.v[11] = zero;
        r.v[12] = one;
        r.v[13] = zero;
        r.v[14] = zero;
        r.v[15] = zero;
        r.k = 16;
        r.l = 0;
        r.n = zero;
        r.o = 1;
        r.p = 20.0f;
        r.q = 0;
        r.w = 0x80;
        D_58B4_6A90 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        r.f = Tag_6A90(r.f);
    }
    Rec_6A90 rec;
    Rec_6A90 *buf = &rec;
    func_003E6574_6A90(buf, &D_4FBF68_6A90, 0xE4);
    Ent_6A90 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446890_6A90[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    func_00357A78_6A90(D_004A4028_6A90, buf->q, buf, buf->w);
    return D_004C9098_6A90;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306CB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A3DD8_6CB0 __asm__("D_004A3DD8");
extern char **D_004A47B8_6CB0 __asm__("D_004A47B8");
extern char *D_004A28A8_6CB0 __asm__("D_004A28A8");
extern void *D_004A4028_6CB0 __asm__("D_004A4028");
void func_00357AE8(void*, int, int);
void func_00357B10(void*, int, int);
struct V3_6CB0 { float x, y, z; };
extern V3_6CB0 D_004C9098_6CB0 __asm__("D_004C9098");
struct Tag_6CB0 { char c; Tag_6CB0() {} Tag_6CB0(const Tag_6CB0 &o) : c(o.c) {} };
extern unsigned D_6CB0[] __asm__("D_004FC050");
extern int D_004A58B8;
extern const int D_00446970[];
extern "C" void* func_003E6574_6CB0(void*, void*, int) __asm__("func_003E6574");
struct Ent_6CB0 { int idx; int val; int pad; int type; };
extern "C" V3_6CB0 func_00306CB0(int n, Ent_6CB0 *e) {
    if (D_004A58B8 == 0) {
        ((int*)D_6CB0)[0] = 0;
        D_6CB0[1] = 0xFFFFFFFF;
        ((int*)D_6CB0)[2] = 0;
        D_004A58B8 = 1;
        (*(Tag_6CB0*)((char*)D_6CB0 + 12)) = Tag_6CB0((*(Tag_6CB0*)((char*)D_6CB0 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574_6CB0(buf, D_6CB0, 16);
    Ent_6CB0 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446970[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[1];
    char *obj;
    if (~id == 0) {
        obj = *(char**)(D_004A3DD8_6CB0 + 0x290);
    } else {
        char *s = (*(char***)((char*)*D_004A47B8_6CB0 + 8))[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        if (buf[2] == 0)
            func_00357AE8(D_004A4028_6CB0, buf[0], *(int*)(obj + 0x78));
        else
            func_00357B10(D_004A4028_6CB0, buf[0], *(int*)(obj + 0x78));
    }
    return D_004C9098_6CB0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306E68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A3DD8_6E68 __asm__("D_004A3DD8");
extern char **D_004A47B8_6E68 __asm__("D_004A47B8");
extern "C" int func_0030BFC0_6E68(int, int, int, int) __asm__("func_0030BFC0");
extern "C" void *func_0028B180_6E68() __asm__("func_0028B180");
extern "C" void func_002974A0_6E68(void*, void*, int) __asm__("func_002974A0");
int *func_00226610(void*);
static inline char *refToPtr_6E68(unsigned i) { return (char*)(i << 2); }
static inline char *conv_6E68(unsigned i) { if (i == 0) return 0; return refToPtr_6E68(i); }
struct V3_6E68 { int w0, w1, w2; };
struct Tag_6E68 { char c; Tag_6E68() {} Tag_6E68(const Tag_6E68 &o) : c(o.c) {} };
extern unsigned D_6E68[] __asm__("D_004FC060");
extern int D_004A58BC;
extern const int D_00446980[];
extern "C" void* func_003E6574_6E68(void*, void*, int) __asm__("func_003E6574");
struct Ent_6E68 { int idx; int val; int pad; int type; };
extern "C" V3_6E68* func_00306E68(V3_6E68 *ret, int n, Ent_6E68 *e) {
    if (D_004A58BC == 0) {
        D_6E68[0] = 0xFFFFFFFF;
        D_6E68[1] = 0xFFFFFFFF;
        D_6E68[2] = 0xFFFFFFFF;
        D_004A58BC = 1;
        (*(Tag_6E68*)((char*)D_6E68 + 12)) = Tag_6E68((*(Tag_6E68*)((char*)D_6E68 + 12)));
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    buf64[2] = 0xFFFFFFFF;
    func_003E6574_6E68(buf, D_6E68, 16);
    Ent_6E68 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446980[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    int b1 = buf[1];
    int b2 = buf[2];
    int r = func_0030BFC0_6E68(D_004A3DD8_6E68, buf[0], b1, b2);
    if (r == 1) {
        unsigned id = buf[1];
        char *obj;
        char *s = (*(char***)((char*)*D_004A47B8_6E68 + 8))[id & 0xFF];
        if (!s) {
            obj = 0;
        } else {
            unsigned i = ((unsigned*)*(char**)(s + 0x1C))[id >> 8] >> 8;
            char *t = conv_6E68(i);
            obj = t;
        }
        if (obj)
            func_002974A0_6E68(func_0028B180_6E68(), obj, 0x5C);
    }
    ((int*)ret)[2] = 1;
    *func_00226610(ret) = r;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307020);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
struct Flag_7020 { char c; Flag_7020() {} Flag_7020(const Flag_7020& o) : c(o.c) {} };
struct Ent_7020 { int idx; int val; int pad; int kind; };
struct R12_7020 { int a; int b; int c; };
extern R12_7020 D_004C9098_7020 __asm__("D_004C9098");

extern int D_004A3DD0_7020[2] __asm__("D_004A3DD0");
extern "C" int func_001E3570(int, int);
extern int D_004A58C0_7020 __asm__("D_004A58C0");
struct T12_7020 { int a; int b; Flag_7020 f; };
extern T12_7020 D_004FC070_7020 __asm__("D_004FC070");
extern "C" void* func_00307020(void* self, int n, Ent_7020* e) {
    if (D_004A58C0_7020 == 0) {
        D_004FC070_7020.a = 0;
        D_004A58C0_7020 = 1;
        D_004FC070_7020.b = 0;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        D_004FC070_7020.f = Flag_7020(D_004FC070_7020.f);
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FC070_7020, 12);
    Ent_7020* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->kind != D_004A3DD0_7020[k] && D_004A3DD0_7020[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    bool r = func_001E3570(vp[0], vp[1]) != 0;
    *(int*)((char*)self + 8) = 1;
    *func_00226610(self) = r;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307128);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_00489A30_7128[] __asm__("D_00489A30");
extern "C" void* cWScriptProcess_cWScriptProcess(void* self, void* man, int a1, int a2);
extern "C" int func_00309B70_7128(int, int) __asm__("func_00309B70");
extern "C" void* func_00307128(void* self, void* man, int a1, char* a2, int a3) {
    cWScriptProcess_cWScriptProcess(self, man, a1, (int)a2);
    *(void**)((char*)self + 0x5C) = D_00489A30_7128;
    *(int*)((char*)self + 0x60) = *(int*)(a2 + 0x50);
    *(int*)((char*)self + 0x64) = a3;
    for (int i = 0; i < 4; i++)
        ((int*)((char*)self + 0x68))[i] = func_00309B70_7128(*(int*)((char*)self + 0x10), ((int*)(a2 + 0x40))[i]);
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003071C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_00489A30_71C8[] __asm__("D_00489A30");
extern "C" void func_00307738_71C8(void*) __asm__("func_00307738");
extern "C" void func_003071C8(void* self) {
    *(void**)((char*)self + 0x5C) = D_00489A30_71C8;
    func_00307738_71C8(self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003071F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *D_004A28A8_71F0 __asm__("D_004A28A8");
void func_0010F2B8_71F0(void*) __asm__("func_0010F2B8__FPv");
extern "C" void func_00307C40_71F0(void*) __asm__("func_00307C40");
struct Tab_71F0 { char pad[0x28]; void *arr[1]; };
extern "C" void func_003071F0(void* self) {
    func_0010F2B8_71F0((*(Tab_71F0**)(*(char**)(D_004A28A8_71F0 + 0x84) + 0xC))->arr[**(int**)((char*)self + 0x10)]);
    func_00307C40_71F0(self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307240);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_7240 { int state; char pad[0x58]; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); };
int func_0030B898_7240(void*, void*) __asm__("func_0030B898__FPvT0");
extern "C" void *func_0028B180_7240(void) __asm__("func_0028B180");
extern "C" void func_0029D8E0_7240(void*) __asm__("func_0029D8E0");
extern "C" void func_00307240(P_7240* self) {
    if (func_0030B898_7240(*(void**)((char*)self + 0x10), self)) {
        self->v06();
        self->v18();
        func_0029D8E0_7240(func_0028B180_7240());
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003072B0);
#ifdef SKIP_ASM
struct P_72B0 { int state; char pad[0x58]; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); };
extern "C" void func_003072B0(P_72B0* self) {
    if (self->state == 2)
        self->v06();
    self->v04();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307308);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern char* D_004A28A8_7308 __asm__("D_004A28A8");
extern "C" int func_00153D78(void* missions, int id);
extern "C" void func_00154160(void* missions, int id, int done);
extern "C" int func_00153FA0(void* missions, int id);
extern "C" int func_001511B0(void* econ, int reward);
extern "C" int func_00144C98(void* iface);
extern "C" void func_0010F2D8(void* rider, int player, int money);
extern "C" unsigned int func_00153FD8(void* missions, int id);
extern "C" void func_001541D0(void* missions, int id, int active);
extern "C" void func_0030AC98(int, void *, int);
extern "C" int func_00153E28(void* missions, int id);
extern "C" void func_00154010(void* missions, int id, int a);
extern "C" void func_00154080(void* missions, int id, int a);
extern "C" void func_00308DB8(int script);
extern "C" void func_00309B00(int script, void* self);
extern "C" void func_0026F228(void* replay);
extern "C" void func_0026F7B8(void* replay);

struct sGame_7308 {
    char pad_0x0[0x28];
    void* riders[8];        // 0x28
};

// Mission completed: pays the reward the first time, unlocks the follow-up mission and resets the script.
extern "C" void func_00307308(char* self)
{
    int money = 0;
    void* missions = cBE_getInterface_Fv(cBE_getBE(), 0xA);
    if (func_00153D78(missions, *(int*)(self + 0x20)) == 0) {
        func_00154160(missions, *(int*)(self + 0x20), 1);
        int reward = func_00153FA0(missions, *(int*)(self + 0x20));
        money = func_001511B0(cBE_getInterface_Fv(cBE_getBE(), 0xB), reward);
    }
    int pl = func_00144C98(cBE_getInterface_Fv(cBE_getBE(), 0));
    sGame_7308* game = *(sGame_7308**)(*(char**)(D_004A28A8_7308 + 0x84) + 0xC);
    func_0010F2D8(game->riders[**(int**)(self + 0x10)], pl, money);
    unsigned int next = func_00153FD8(missions, *(int*)(self + 0x20));
    if (next != 0xFFFFFFFF) {
        func_001541D0(missions, *(int*)(self + 0x20), 0);
        if (*(int*)(self + 0x6C) != 0) {
            func_0030AC98(*(int*)(self + 0x10), self, *(int*)(self + 0x6C));
        }
        if (func_00153E28(missions, next) != 0) {
            func_00154010(missions, next, 0);
            func_00154080(missions, next, 1);
            func_001541D0(missions, next, 1);
        }
    } else if (*(int*)(self + 0x6C) != 0) {
        func_0030AC98(*(int*)(self + 0x10), self, *(int*)(self + 0x6C));
    }
    func_00308DB8(*(int*)(self + 0x10));
    func_00309B00(*(int*)(self + 0x10), self);
    func_0026F228(*(void**)(*(char**)(D_004A28A8_7308 + 0x84) + 0x28));
    func_0026F7B8(*(void**)(*(char**)(D_004A28A8_7308 + 0x84) + 0x28));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003074C0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
extern "C" int cBE_getBE_74C0(void) __asm__("cBE_getBE");
int cBE_getInterface_Fv_74C0(int be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00153E80_74C0(int, int) __asm__("func_00153E80");
extern "C" void func_001540F0_74C0(int, int, int) __asm__("func_001540F0");
extern "C" void func_00307D78_74C0(void*) __asm__("func_00307D78");
extern "C" void func_0030AC98(int, void *, int);
struct P_74C0 { int state; char pad[0x58]; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); };
extern "C" void func_003074C0(P_74C0* self) {
    int iface = cBE_getInterface_Fv_74C0(cBE_getBE_74C0(), 10);
    if (!func_00153E80_74C0(iface, *(int*)((char*)self + 0x20)))
        func_001540F0_74C0(iface, *(int*)((char*)self + 0x20), 1);
    int h = *(int*)((char*)self + 0x70);
    if (h)
        func_0030AC98(*(int*)((char*)self + 0x10), self, h);
    else
        self->v20();
    if (self->state == 2)
        func_00307D78_74C0(self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307568);
#ifdef SKIP_ASM
extern "C" void func_0030AC98(int, void *, int);

extern "C" void func_00307568(void *arg0) {
    int temp_6;

    temp_6 = (*(int *)((char*)(arg0) + (0x74)));
    if (temp_6 != 0) {
        func_0030AC98((*(int *)((char*)(arg0) + (0x10))), arg0, temp_6);
    }
}
#endif
