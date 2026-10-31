#include "common.h"

//100%
INCLUDE_ASM("world/wscriptcache", cWScriptCache_init);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void* func_003ACA50(void* self);
extern "C" void func_003ACA70(int* self, int flags);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00495070[];

// PORT: array cookie arithmetic through int (pointer in int).
extern "C" void cWScriptCache_init(void* self, int count)
{
    char* old = *(char**)((char*)self + 0x4);
    if (old != 0) {
        char* p = (char*)(*(int*)(old - 0x10) * 0xC + (int)old);
        while (*(char**)((char*)self + 0x4) != p) {
            p -= 0xC;
            func_003ACA70((int*)p, 0);
        }
        cMemMan_free(*(char**)((char*)self + 0x4) - 0x10);
    }
    *(int*)((char*)self + 0x8) = count;
    char** slot = (char**)((char*)self + 0x4);
    char* mem = (char*)operator_new_tag(count * 0xC + 0x10, D_00495070, 0x20000000, 0);
    char* arr = mem + 0x10;
    *(int*)mem = count;
    char* q = arr;
    int i;
    for (i = count - 1; i != -1; i--, q += 0xC) {
        func_003ACA50(q);
    }
    *slot = arr;
    *(int*)((char*)self + 0xC) = 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AC8F0);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void operator_delete(int*);
extern "C" void func_003ACA70(int* self, int flags);
extern int D_004A4810;

// PORT: array cookie arithmetic through int (pointer in int).
extern "C" void func_003AC8F0(int* self, int flags)
{
    char* old = *(char**)((char*)self + 0x4);
    if (old != 0) {
        char* p = (char*)(*(int*)(old - 0x10) * 0xC + (int)old);
        while (*(char**)((char*)self + 0x4) != p) {
            p -= 0xC;
            func_003ACA70((int*)p, 0);
        }
        cMemMan_free(*(char**)((char*)self + 0x4) - 0x10);
    }
    D_004A4810 = 0;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AC980);
#ifdef SKIP_ASM
extern "C" void func_003ACAD0(int);

extern "C" void func_003AC980(void *self) {
    unsigned int i;

    for (i = 0; i < *(unsigned int *)((char *)self + 8); i++) {
        func_003ACAD0(*(int *)((char *)self + 4) + i * 0xC);
    }
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003AC9E0);
#ifdef SKIP_ASM
extern "C" void func_003ACBB8(int, int);

extern "C" void func_003AC9E0(void *arg0, int arg1, int arg2) {
    func_003ACBB8((*(int *)((char*)(arg0) + (4))) + (arg1 * 0xC), arg2);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACA10);
#ifdef SKIP_ASM
struct sWScriptCacheItem {
    char pad_0x00[0xC];
};

extern "C" void func_003ACC50(sWScriptCacheItem* e, int index, int value);

extern "C" void func_003ACA10(void* self, int index, int value)
{
    sWScriptCacheItem* p = *(sWScriptCacheItem**)((char*)self + 0x4);
    func_003ACC50(&p[index], index, value);
}
#endif

// 0xc-byte elements reached through a pointer at self+0x4
struct sWScriptCacheEntry {
    char pad_0x00[0x8];
    int field_0x8;
};

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACA38);
#ifdef SKIP_ASM
extern "C" int func_003ACA38(void* self, int a1)
{
    sWScriptCacheEntry* p = *(sWScriptCacheEntry**)((char*)self + 0x4);
    return p[a1].field_0x8;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACA50__FPv);
#ifdef SKIP_ASM
void* func_003ACA50(void* self)
{
    int t0 = 0;
    *(short*)self = (short)t0;
    *(int*)((char*)self + 0x4) = -1;
    *(int*)((char*)self + 0x8) = t0;
    *(short*)((char*)self + 0x2) = (short)t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACA70);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void operator_delete(int*);

extern "C" void func_003ACA70(int* self, int flags)
{
    if (*(void**)((char*)self + 0x8) != 0 && *(short*)((char*)self + 0x2) == 0) {
        cMemMan_free(*(void**)((char*)self + 0x8));
    }
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACAD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void ASYNCFILE_release_CAD0(int, int *, int *) __asm__("ASYNCFILE_release");
extern "C" void* func_002523A8(int);
extern "C" void func_003B47F8(int, int);
extern "C" int func_003B4818_CAD0(int) __asm__("func_003B4818");
extern "C" int func_003DF980_CAD0(int) __asm__("func_003DF980");
extern "C" void func_003E6574_CAD0(int, int, int) __asm__("func_003E6574");
int operator_new_CAD0(unsigned int, void*, int, int) __asm__("operator_new__FUi");
extern char D_00495080[];
extern "C" void func_003ACAD0_impl(void *self_) __asm__("func_003ACAD0");
extern "C" void func_003ACAD0_impl(void *self_) {
    char *self = (char*)self_;
    short st = *(short*)self;
    if (st == 1 && func_003DF980_CAD0(*(int*)(self + 4)) == st) {
        int sp0 = 0;
        int sp4 = 0;
        ASYNCFILE_release_CAD0(*(int*)(self + 4), &sp0, &sp4);
        if (sp0 != 0) {
            if (sp4 > 0) {
                int t = func_003B4818_CAD0(sp0);
                if (t > 0) {
                    int r = operator_new_CAD0(t, D_00495080, 0x20000000, 0);
                    *(int*)(self + 8) = r;
                    func_003B47F8(sp0, r);
                } else {
                    int r = operator_new_CAD0(sp4, D_00495080, 0x20000000, 0);
                    *(int*)(self + 8) = r;
                    func_003E6574_CAD0(r, sp0, sp4);
                }
                func_002523A8(sp0);
            }
        }
        *(short*)self = 2;
    }
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003ACBB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sBXStr_CBB8 { char *p; int pad[3]; sBXStr_CBB8() {} };
extern "C" void func_003186D0_CBB8(sBXStr_CBB8*, const char*, int) __asm__("func_003186D0");
extern "C" void func_00318630_CBB8(sBXStr_CBB8*, sBXStr_CBB8*, const char*) __asm__("func_00318630");
extern "C" int func_003DF690_CBB8(const char*, int) __asm__("func_003DF690");
extern "C" void cBXString_dt_CBB8(sBXStr_CBB8*, int) __asm__("cBXString__cBXString");
extern char D_004A47C0[];
extern char D_004A4818[];
extern "C" void func_003ACBB8_impl(void *self, int arg) __asm__("func_003ACBB8");
extern "C" void func_003ACBB8_impl(void *self, int arg) {
    sBXStr_CBB8 a;
    sBXStr_CBB8 b;
    *(short*)((char*)self + 2) = 0;
    func_003186D0_CBB8(&b, D_004A47C0, arg);
    func_00318630_CBB8(&a, &b, D_004A4818);
    *(int*)((char*)self + 4) = func_003DF690_CBB8(a.p, 0x100);
    cBXString_dt_CBB8(&a, 2);
    cBXString_dt_CBB8(&b, 2);
    int n = *(int*)((char*)self + 4);
    *(short*)((char*)self + 0) = n <= 0 ? 2 : 1;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACC50);
#ifdef SKIP_ASM
struct sWSCItemFields {
    short type;   // 0x0
    short owned;  // 0x2
    int pad4;
    int value;    // 0x8
};

extern "C" void func_003ACCD8(sWScriptCacheItem* e, void* world, int index);
extern void* D_004A47B8;

extern "C" void func_003ACC50(sWScriptCacheItem* e, int index, int value)
{
    sWSCItemFields* f = (sWSCItemFields*)e;
    f->value = value;
    f->owned = 1;
    f->type = 2;
    func_003ACCD8(e, D_004A47B8, index);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACC90);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

extern "C" void func_003ACC90(void* self)
{
    void* buf = *(void**)((char*)self + 0x8);
    if (buf != 0) {
        if (*(short*)((char*)self + 0x2) == 0) {
            cMemMan_free(buf);
        }
        *(void**)((char*)self + 0x8) = 0;
    }
    *(short*)self = 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ACCD8);
#ifdef SKIP_ASM
struct sWScriptCacheItem;
void cMemMan_free(void* p);

struct sRef_CCD8 {
    unsigned int idx : 8;
    unsigned int slot : 24;
};

struct sPair_CCD8 {
    short a;
    unsigned short b;
};

struct sRec40_CCD8 {
    int f0;
    int f4;
    int f8;
    char pad[0x34];
};

struct sRec54_CCD8 {
    int f0;
    int f4;
    int f8;
    char pad[0x48];
};

#define WSD_CCD8 (*(char**)((char*)e + 0x8))

static inline void* toPtr_CCD8(unsigned int v)
{
    return (void*)(v << 2);
}

static inline void* lookup_CCD8(char* obj, int tblOff, unsigned int slot)
{
    unsigned int v = (*(unsigned int**)(obj + tblOff))[slot] >> 8;
    if (v == 0) {
        return 0;
    }
    return toPtr_CCD8(v);
}

static inline void* resolve_CCD8(char* w, sRef_CCD8 ref, int tblOff)
{
    char* obj = (*(char***)(w + 0x8))[ref.idx];
    if (obj == 0) {
        return 0;
    }
    return lookup_CCD8(obj, tblOff, ref.slot);
}

extern "C" void func_003ACCD8(sWScriptCacheItem* ep, void* world, int index)
{
    char* e = (char*)ep;
    char** wp = (char**)world;
    char* d = WSD_CCD8;
    if (d == 0) {
        *(short*)e = 3;
        return;
    }
    {
        if (!(*(unsigned short*)d == 0x1000 && *(int*)(d + 0xC) == *(int*)(*(char**)*wp + 0x4))) {
            if (*(short*)(e + 0x2) == 0) {
                cMemMan_free(d);
            }
            WSD_CCD8 = 0;
        }
        if (WSD_CCD8 != 0) {
            *(int*)(WSD_CCD8 + 0x14) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x14);
            *(int*)(WSD_CCD8 + 0x1C) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x1C);
            *(int*)(WSD_CCD8 + 0x24) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x24);
            *(int*)(WSD_CCD8 + 0x2C) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x2C);
            *(int*)(WSD_CCD8 + 0x34) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x34);
            *(int*)(WSD_CCD8 + 0x3C) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x3C);
            *(int*)(WSD_CCD8 + 0x40) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x40);
            *(int*)(WSD_CCD8 + 0x48) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x48);
            *(int*)(WSD_CCD8 + 0x50) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x50);
            *(int*)(WSD_CCD8 + 0x58) = (int)WSD_CCD8 + *(int*)(WSD_CCD8 + 0x58);
            int* t3c = *(int**)(WSD_CCD8 + 0x3C);
            for (int i = 0; i < *(int*)(WSD_CCD8 + 0x38); i++) {
                t3c[i] = (int)WSD_CCD8 + t3c[i];
            }
            for (int i = 0; i < *(int*)(WSD_CCD8 + 0x4C); i++) {
                (*(int**)(WSD_CCD8 + 0x50))[i] = *(int*)(WSD_CCD8 + 0x40) + (*(int**)(WSD_CCD8 + 0x50))[i];
            }
            sRef_CCD8 ref;
            *(unsigned int*)&ref = 0xFFFFFFFF;
            ref.idx = index;
            for (int i = 0; i < *(int*)(WSD_CCD8 + 0x44); i++) {
                ref.slot = i;
                char* o = (char*)resolve_CCD8(*wp, ref, 0x1C);
                char* x = (char*)(*(int**)(WSD_CCD8 + 0x50))[*(unsigned short*)(*(char**)(WSD_CCD8 + 0x48) + (i << 1))];
                *(char**)(o + 0x88) = x;
                int v = *(int*)(x + 0x4) & 0xFFFF0000;
                *(int*)(o + 0x8) = v | (v >> 16) | 2;
            }
            for (int i = 0; i < *(int*)(WSD_CCD8 + 0x4C); i++) {
                char* r = (*(char***)(WSD_CCD8 + 0x50))[i];
                int type = *(int*)r;
                if (type == 1 || type == 3) {
                    *(void**)(r + 0xC) = resolve_CCD8(*wp, *(sRef_CCD8*)(r + 0xC), 0x64);
                } else {
                    *(void**)(r + 0xC) = 0;
                }
            }
            int n54 = *(int*)(WSD_CCD8 + 0x54);
            for (int i = 0; i < n54; i++) {
                char* w = *wp;
                ref.slot = i;
                char* o = (char*)resolve_CCD8(w, ref, 0x44);
                sPair_CCD8 p = (*(sPair_CCD8**)(WSD_CCD8 + 0x58))[i];
                *(int*)(o + 0x28) = (short)p.b;
                unsigned int v = p.a << 16;
                *(unsigned int*)(o + 0x1C) = (v & 0xFFFF0000) | (v >> 16);
            }
            {
                sRec40_CCD8* r = *(sRec40_CCD8**)(WSD_CCD8 + 0x2C);
                int n = *(int*)(WSD_CCD8 + 0x28);
                for (int i = 0; i < n; i++, r++) {
                    r->f8 = (int)WSD_CCD8 + r->f8;
                }
            }
            {
                sRec54_CCD8* r = *(sRec54_CCD8**)(WSD_CCD8 + 0x24);
                int n = *(int*)(WSD_CCD8 + 0x20);
                for (int i = 0; i < n; i++, r++) {
                    r->f8 = (int)WSD_CCD8 + r->f8;
                }
            }
        }
    }
    *(short*)e = 3;
}
#endif

INCLUDE_ASM("world/wscriptcache", func_003AD120);

//100%
INCLUDE_ASM("world/wscriptcache", func_003AD188);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_003AD188(void)
{
    return *(void**)(D_004A28A8 + 0x84);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AD198);
#ifdef SKIP_ASM
extern char* D_004A28A8;

extern "C" void* func_003AD198(void)
{
    return *(void**)(*(char**)(D_004A28A8 + 0x84) + 0x8C);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AD1A8);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern "C" void func_002F5998(void* lights);
extern "C" void func_00122658(void* self);

extern "C" void func_003AD1A8(void)
{
    func_002F5998(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x90));
    char* riders = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
    if (riders != 0) {
        for (int i = 0; i < *(int*)(riders + 0x78); i++) {
            func_00122658(*(void**)(riders + 0x28 + i * 4));
        }
    }
}
#endif

extern "C" void* func_002E27E8(void* self);

//100%
INCLUDE_ASM("world/wscriptcache", func_003AD230__FPv);
#ifdef SKIP_ASM
void* func_003AD230(void* self)
{
    return func_002E27E8(self);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AD250);
#ifdef SKIP_ASM
extern "C" void* func_003AD250(void* self, ...) {
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AD290);
#ifdef SKIP_ASM
extern float D_00509080[4];
extern float D_00509090[4];
extern float D_005090A0[4];
extern float D_005090B0[4];
extern float D_005090C0[4];
extern float D_005090D0[4];
extern float D_005090E0[4];
extern float D_005090F0[4];
extern float D_00509100[4];
extern float D_00509110[4];
extern float D_00509120[4];
extern float D_00509130[4];
extern float D_00509140[4];
extern float D_00509150[4];
extern float D_00509160[4];
extern float D_00509170[4];
extern float D_00509180[4];
extern float D_00509190[4];
extern float D_005091A0[4];
extern float D_005091B0[4];
extern float D_005091C0[4];
extern float D_005091D0[4];
extern float D_005091E0[4];
extern float D_005091F0[4];
extern float D_00509200[4];
extern float D_00509210[4];
extern float D_00509220[4];
extern float D_00509230[4];
extern float D_00509240[4];
extern float D_00509250[4];
extern float D_00509260[4];
extern float D_00509270[4];
extern float D_00509280[4];
extern float D_00509290[4];
extern float D_005092A0[4];
extern float D_005092B0[4];
extern float D_005092C0[4];
extern float D_005092D0[4];
extern float D_005092E0[4];
extern float D_005092F0[4];
extern float D_00509300[4];
extern float D_00509310[4];
extern float D_00509320[4];
extern float D_00509330[4];
extern float D_00509340[4];
extern float D_00509350[4];
extern float D_00509360[4];
extern float D_00509370[4];
extern float D_00509380[4];
extern float D_00509390[4];
extern float D_005093A0[4];
extern float D_005093B0[4];
extern float D_005093C0[4];
extern float D_005093D0[4];
extern float D_005093E0[4];
extern float D_005093F0[4];
extern int D_004A5A70;
extern int D_004A5A74;
extern int D_004A5A78[2];
extern int D_004A5A80[2];
extern int D_004A5A88[2];
extern int D_004A5A90[2];
extern int D_004A5A98[2];
extern int D_004A5AA0[2];
extern int D_004A5AA8[2];
extern int D_004A5AB0[2];
extern int D_004A5AB8[2];
extern int D_004A5AC0[2];
extern int D_004A5AC8[2];
extern int D_004A5AD0[2];
extern int D_004A5AD8[2];
extern int D_004A5AE0[2];
extern long D_00509400[2];
extern long D_00509410[2];
extern long D_00509420[2];
extern char D_2400[];
extern char D_2270[];
extern char D_22C8[];
static inline void initE(int* p, int n)
{
    *(char*)p = n;
    *p = (*p & 0xFF) | (n << 8);
}
static inline void initD(long* p, char* sz)
{
    p[0] = 0;
    p[1] = (long)(((unsigned)sz >> 3) | 0x14000000) << 32;
}
void sti_003AD290(int init, int prio) __asm__("func_003AD290");
void sti_003AD290(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_00509080[0] = 1.0f;
        D_00509080[1] = 1.0f;
        D_00509080[2] = 1.0f;
        D_00509080[3] = 0.5f;
        D_00509090[0] = 0.4998680055141449f;
        D_00509090[1] = 1.0f;
        D_00509090[2] = 1.0f;
        D_00509090[3] = 0.0f;
        D_005090A0[0] = 0.12951700389385223f;
        D_005090A0[1] = 1.0f;
        D_005090A0[2] = 1.0f;
        D_005090A0[3] = 0.0f;
        D_005090B0[0] = 0.22426900267601013f;
        D_005090B0[1] = 0.9402310252189636f;
        D_005090B0[2] = 0.5425059795379639f;
        D_005090B0[3] = 0.0004030000127386302f;
        D_005090C0[0] = 0.4652079939842224f;
        D_005090C0[1] = 0.32170501351356506f;
        D_005090C0[2] = 0.9943439960479736f;
        D_005090C0[3] = 0.0f;
        D_005090D0[0] = 0.17792600393295288f;
        D_005090D0[1] = 1.0f;
        D_005090D0[2] = 1.0f;
        D_005090D0[3] = 0.0f;
        D_005090E0[0] = 0.4411740005016327f;
        D_005090E0[1] = 0.41388601064682007f;
        D_005090E0[2] = 0.3211260139942169f;
        D_005090E0[3] = 0.4398239850997925f;
        D_005090F0[0] = 0.500997006893158f;
        D_005090F0[1] = 0.24849599599838257f;
        D_005090F0[2] = 1.0f;
        D_005090F0[3] = 1.0f;
        D_00509100[0] = 0.27687299251556396f;
        D_00509100[1] = 0.6395620107650757f;
        D_00509100[2] = 0.13423900306224823f;
        D_00509100[3] = 0.0f;
        D_00509110[0] = 0.8936439752578735f;
        D_00509110[1] = 0.5263469815254211f;
        D_00509110[2] = 0.5051450133323669f;
        D_00509110[3] = 0.8687300086021423f;
        D_00509120[0] = 1.0f;
        D_00509120[1] = 1.0f;
        D_00509120[2] = 1.0f;
        D_00509120[3] = 1.0f;
        D_00509130[0] = 1.0f;
        D_00509130[1] = 0.0f;
        D_00509130[2] = 0.0f;
        D_00509130[3] = 0.0f;
        D_00509140[0] = 1.0f;
        D_00509140[1] = 0.550000011920929f;
        D_00509140[2] = 0.5350000262260437f;
        D_00509140[3] = 0.550000011920929f;
        D_00509150[0] = 1.0f;
        D_00509150[1] = 1.0f;
        D_00509150[2] = 1.0f;
        D_00509150[3] = 1.0f;
        D_00509160[0] = 1.0f;
        D_00509160[1] = 1.0f;
        D_00509160[2] = 1.0f;
        D_00509160[3] = 1.0f;
        D_00509170[0] = 1.0f;
        D_00509170[1] = 0.0f;
        D_00509170[2] = 0.0f;
        D_00509170[3] = 0.0f;
        D_00509180[0] = 1.0f;
        D_00509180[1] = 0.0f;
        D_00509180[2] = 0.0f;
        D_00509180[3] = 0.0f;
        D_00509190[0] = 1.0f;
        D_00509190[1] = 1.0f;
        D_00509190[2] = 1.0f;
        D_00509190[3] = 1.0f;
        D_005091A0[0] = 1.0f;
        D_005091A0[1] = 0.5f;
        D_005091A0[2] = 1.0f;
        D_005091A0[3] = 0.5f;
        D_005091B0[0] = 1.0f;
        D_005091B0[1] = 0.5f;
        D_005091B0[2] = 1.0f;
        D_005091B0[3] = 0.5f;
        D_005091C0[0] = 1.0f;
        D_005091C0[1] = 0.5f;
        D_005091C0[2] = 1.0f;
        D_005091C0[3] = 0.5f;
        D_005091D0[0] = 1.0f;
        D_005091D0[1] = 0.7828119993209839f;
        D_005091D0[2] = 0.06171900033950806f;
        D_005091D0[3] = 0.03984399884939194f;
        D_005091E0[0] = 1.0f;
        D_005091E0[1] = 1.0f;
        D_005091E0[2] = 0.7988259792327881f;
        D_005091E0[3] = 0.0f;
        D_005091F0[0] = 0.9886710047721863f;
        D_005091F0[1] = 0.9230499863624573f;
        D_005091F0[2] = 0.34311699867248535f;
        D_005091F0[3] = 0.0f;
        D_00509200[0] = 1.0f;
        D_00509200[1] = 1.0f;
        D_00509200[2] = 1.0f;
        D_00509200[3] = 1.0f;
        D_00509210[0] = 1.0f;
        D_00509210[1] = 1.0f;
        D_00509210[2] = 0.7976430058479309f;
        D_00509210[3] = 0.0f;
        D_00509220[0] = 1.0f;
        D_00509220[1] = 0.9222670197486877f;
        D_00509220[2] = 0.34179699420928955f;
        D_00509220[3] = 0.0f;
        D_00509230[0] = 1.0f;
        D_00509230[1] = 0.7847639918327332f;
        D_00509230[2] = 0.06054700165987015f;
        D_00509230[3] = 0.04062499850988388f;
        D_00509240[0] = 1.0f;
        D_00509240[1] = 0.800000011920929f;
        D_00509240[2] = 0.44999998807907104f;
        D_00509240[3] = 1.0f;
        D_00509250[0] = 1.0f;
        D_00509250[1] = 0.3281260132789612f;
        D_00509250[2] = 1.0f;
        D_00509250[3] = 0.3539060056209564f;
        D_00509260[0] = 1.0f;
        D_00509260[1] = 1.0f;
        D_00509260[2] = 1.0f;
        D_00509260[3] = 1.0f;
        D_00509270[0] = 1.0f;
        D_00509270[1] = 1.0f;
        D_00509270[2] = 1.0f;
        D_00509270[3] = 1.0f;
        D_00509280[0] = 1.0f;
        D_00509280[1] = 0.8613290190696716f;
        D_00509280[2] = 0.38124799728393555f;
        D_00509280[3] = 0.0f;
        D_00509290[0] = 1.0f;
        D_00509290[1] = 1.0f;
        D_00509290[2] = 1.0f;
        D_00509290[3] = 1.0f;
        D_005092A0[0] = 1.0f;
        D_005092A0[1] = 0.3244380056858063f;
        D_005092A0[2] = 1.0f;
        D_005092A0[3] = 0.0f;
        D_005092B0[0] = 1.0f;
        D_005092B0[1] = 1.0f;
        D_005092B0[2] = 1.0f;
        D_005092B0[3] = 1.0f;
        D_005092C0[0] = 1.0f;
        D_005092C0[1] = 1.0f;
        D_005092C0[2] = 0.0f;
        D_005092C0[3] = 0.0f;
        D_005092D0[0] = 0.7007060050964355f;
        D_005092D0[1] = 0.0f;
        D_005092D0[2] = 0.0f;
        D_005092D0[3] = 0.0f;
        D_005092E0[0] = 1.0f;
        D_005092E0[1] = 0.7828530073165894f;
        D_005092E0[2] = 0.06140600144863129f;
        D_005092E0[3] = 0.04146299883723259f;
        D_005092F0[0] = 1.0f;
        D_005092F0[1] = 0.32487601041793823f;
        D_005092F0[2] = 1.0f;
        D_005092F0[3] = 0.35280099511146545f;
        D_00509300[0] = 1.0f;
        D_00509300[1] = 1.0f;
        D_00509300[2] = 0.7977359890937805f;
        D_00509300[3] = 0.0f;
        D_00509310[0] = 1.0f;
        D_00509310[1] = 0.4937489926815033f;
        D_00509310[2] = 1.0f;
        D_00509310[3] = 0.49179700016975403f;
        D_00509320[0] = 1.0f;
        D_00509320[1] = 1.0f;
        D_00509320[2] = 1.0f;
        D_00509320[3] = 1.0f;
        D_00509330[0] = 1.0f;
        D_00509330[1] = 0.800000011920929f;
        D_00509330[2] = 1.0f;
        D_00509330[3] = 0.800000011920929f;
        D_00509340[0] = 1.0f;
        D_00509340[1] = 1.0f;
        D_00509340[2] = 0.0f;
        D_00509340[3] = 0.0f;
        D_00509350[0] = 1.0f;
        D_00509350[1] = 1.0f;
        D_00509350[2] = 0.0f;
        D_00509350[3] = 0.0f;
        D_00509360[0] = 1.0f;
        D_00509360[1] = 1.0f;
        D_00509360[2] = 0.0f;
        D_00509360[3] = 0.0f;
        D_00509370[0] = 1.0f;
        D_00509370[1] = 0.3273420035839081f;
        D_00509370[2] = 1.0f;
        D_00509370[3] = 0.35390499234199524f;
        D_00509380[0] = 1.0f;
        D_00509380[1] = 1.0f;
        D_00509380[2] = 0.061000000685453415f;
        D_00509380[3] = 0.039000000804662704f;
        D_00509390[0] = 1.0f;
        D_00509390[1] = 1.0f;
        D_00509390[2] = 0.7999979853630066f;
        D_00509390[3] = 0.0f;
        D_005093A0[0] = 1.0f;
        D_005093A0[1] = 0.9589840173721313f;
        D_005093A0[2] = 0.6143789887428284f;
        D_005093A0[3] = 0.0f;
        D_005093B0[0] = 1.0f;
        D_005093B0[1] = 0.9285150170326233f;
        D_005093B0[2] = 0.3399839997291565f;
        D_005093B0[3] = 0.0f;
        D_005093C0[0] = 1.0f;
        D_005093C0[1] = 0.8738250136375427f;
        D_005093C0[2] = 0.24931700527668f;
        D_005093C0[3] = 0.017578000202775f;
        D_005093D0[0] = 1.0f;
        D_005093D0[1] = 0.7843739986419678f;
        D_005093D0[2] = 0.06132800132036209f;
        D_005093D0[3] = 0.03945299983024597f;
        D_005093E0[0] = 1.0f;
        D_005093E0[1] = 0.0f;
        D_005093E0[2] = 1.0f;
        D_005093E0[3] = 0.0f;
        D_005093F0[0] = 1.0f;
        D_005093F0[1] = 1.0f;
        D_005093F0[2] = 0.0f;
        D_005093F0[3] = 0.0f;
        D_004A5A74 = 0;
        D_004A5A70 = 0;
        initE(D_004A5A78, 0);
        initE(D_004A5A80, 1);
        initE(D_004A5A88, 2);
        initE(D_004A5A90, 3);
        initE(D_004A5A98, 4);
        initE(D_004A5AA0, 5);
        initE(D_004A5AA8, 6);
        initE(D_004A5AB0, 7);
        initE(D_004A5AB8, 8);
        initE(D_004A5AC0, 9);
        initE(D_004A5AC8, 10);
        initE(D_004A5AD0, 11);
        initE(D_004A5AD8, 12);
        initE(D_004A5AE0, 13);
        initD(D_00509400, D_2400);
        initD(D_00509410, D_2270);
        initD(D_00509420, D_22C8);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADC18);
#ifdef SKIP_ASM
extern void* D_00495150[];
void operator_delete(int*);

extern "C" void func_003ADC18(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00495150;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADC48__FPv);
#ifdef SKIP_ASM
int func_003ADC48(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADC50);
#ifdef SKIP_ASM
extern "C" int func_003ADC50(void* self, int i)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        return (*(int**)((char*)data + 0x3C))[i];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADC80);
#ifdef SKIP_ASM
extern "C" int func_003ADC80(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(int*)((char*)data + 0x10);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADCB0);
#ifdef SKIP_ASM
extern "C" int func_003ADCB0(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(int*)((char*)data + 0x14);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADCE0);
#ifdef SKIP_ASM
extern "C" int func_003ADCE0(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(int*)((char*)data + 0x28);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADD10);
#ifdef SKIP_ASM
extern "C" int func_003ADD10(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(int*)((char*)data + 0x2C);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADD40);
#ifdef SKIP_ASM
extern "C" int func_003ADD40(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(int*)((char*)data + 0x20);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADD70);
#ifdef SKIP_ASM
extern "C" int func_003ADD70(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(int*)((char*)data + 0x24);
        }
    }
    return 0;
}
#endif

extern "C" void* func_003AD290(int, int);

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADDA0__FPv);
#ifdef SKIP_ASM
void* func_003ADDA0(void* self)
{
    return func_003AD290(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADDC0);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADDC0(void* self, int a1, int a2, int a3, int a4)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, 0, a2, 0, 0, 0, a3, a4);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADE08);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADE08(void* self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, 0, a2, a3, 0, a4, a5, a6);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADE58);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADE58(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, a2, a3, a4, a5, a6, a7, a8);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADE90);
#ifdef SKIP_ASM
extern "C" void func_003ADEC8(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern "C" void* func_003ADE90(void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    *(int*)((char*)self + 0x60) = 0;
    func_003ADEC8(self, a1, a2, a3, a4, a5, a6, 2, a7);
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003ADEC8);
#ifdef SKIP_ASM
struct sAlloc_ADEC8 {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void* (*free)(void* p);
    int flags;
};
// PORT: the unit declares D_00509430 as char[] later; view bound by asm label
extern sAlloc_ADEC8 D_00509430_ADEC8 __asm__("D_00509430");
extern char D_00495218[];
extern char D_00495230[];
extern "C" signed char func_003B5440();
extern "C" void func_003E62B0();
extern "C" void func_003E6448(void* dst, int value, int size);
extern "C" void func_003E0AD8(int h, int a, int b);
extern "C" int func_003E0D80(int h, int a, int b, int c);
extern "C" int func_003DF690(int a, int flags);
extern "C" int func_003E06D8(int a, int b, int c, void* buf, int size);
extern "C" void func_003E0948(int h, int a, int b, int c, int d);
extern "C" int func_003E0BF8(int h, int a);
extern "C" int func_003E0C88(int h, int a, int b, int c);

static inline bool wsCanAlloc_ADEC8(sAlloc_ADEC8* a)
{
    return a->alloc != 0 && a->free != 0;
}

extern "C" void func_003ADEC8(void* selfp, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    char* self = (char*)selfp;
    if (func_003B5440() == 0) {
        a8 = 1;
    }
    func_003E6448(self, 0, 0x78);
    *(int*)(self + 0x18) = a7;
    *(int*)(self + 0x1C) = a8;
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 0x28) = 0;
    *(int*)(self + 0x24) = 0;
    *(int*)(self + 0x2C) = 0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x5C) = 0;
    *(int*)(self + 0x64) = 0;
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x70) = 0;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0xC) = a1;
    *(int*)(self + 0x10) = a4;
    if (!wsCanAlloc_ADEC8(&D_00509430_ADEC8)) {
        func_003E62B0();
        return;
    }
    if (a4 != 0) {
        *(int*)(self + 0x14) = 1;
        *(void**)(self + 0x4) = D_00509430_ADEC8.alloc(D_00495218, a3, 0, 0, D_00509430_ADEC8.flags);
        *(void**)(self + 0x8) = D_00509430_ADEC8.alloc(D_00495230, a6, 0, 0, D_00509430_ADEC8.flags);
        *(int*)(self + 0x30) = func_003E06D8(2, 2, 1, *(void**)(self + 0x4), a3);
        *(int*)(self + 0x34) = func_003E06D8(2, 2, 1, *(void**)(self + 0x8), a6);
        func_003E0AD8(*(int*)(self + 0x34), 0x98, 0x34);
        func_003E0AD8(*(int*)(self + 0x30), 0x98, 0x34);
        func_003E0948(*(int*)(self + 0x30), 1, 0xFF, 0x4D, 1);
        func_003E0948(*(int*)(self + 0x30), 2, 0, 0, -2);
        if (*(int*)(self + 0x1C) == 0) {
            func_003E0948(*(int*)(self + 0x34), 1, 0xFFFF, 0x4353, 1);
        } else {
            func_003E0948(*(int*)(self + 0x34), 1, 0xFFFF, 0x4353, -1);
        }
        func_003E0948(*(int*)(self + 0x34), 2, 0, 0, -2);
        int type = *(int*)(self + 0x18);
        if (type == 1) {
            *(int*)(self + 0x2C) = func_003DF690(a4, D_00509430_ADEC8.flags);
            *(int*)(self + 0x24) = func_003DF690(a1, D_00509430_ADEC8.flags);
        } else if (type == 0) {
            *(int*)(self + 0x3C) = func_003E0C88(*(int*)(self + 0x34), a4, 0, 0);
            *(int*)(self + 0x38) = func_003E0C88(*(int*)(self + 0x30), a1, 0, 0);
        } else if (type == 2) {
            *(int*)(self + 0x38) = func_003E0D80(*(int*)(self + 0x30), *(int*)(self + 0xC), a2, 0);
            *(int*)(self + 0x3C) = func_003E0D80(*(int*)(self + 0x34), *(int*)(self + 0x10), a5, 0);
        }
    } else {
        *(int*)(self + 0x14) = 0;
        *(void**)(self + 0x4) = D_00509430_ADEC8.alloc(D_00495218, a3, 0, 0, D_00509430_ADEC8.flags);
        *(void**)(self + 0x8) = 0;
        *(int*)(self + 0x30) = func_003E06D8(2, 3, 2, *(void**)(self + 0x4), a3);
        *(int*)(self + 0x34) = func_003E0BF8(*(int*)(self + 0x30), 2);
        func_003E0AD8(*(int*)(self + 0x34), 0x98, 0x34);
        func_003E0AD8(*(int*)(self + 0x30), 0x98, 0x34);
        func_003E0948(*(int*)(self + 0x30), 1, 0xFF, 0x4D, 1);
        func_003E0948(*(int*)(self + 0x30), 3, 0, 0, -2);
        if (*(int*)(self + 0x1C) == 0) {
            func_003E0948(*(int*)(self + 0x30), 2, 0xFFFF, 0x4353, 2);
        } else {
            func_003E0948(*(int*)(self + 0x30), 2, 0xFFFF, 0x4353, -1);
        }
        int type = *(int*)(self + 0x18);
        if (type == 1) {
            *(int*)(self + 0x24) = func_003DF690(a1, D_00509430_ADEC8.flags);
        } else if (type == 0) {
            *(int*)(self + 0x38) = func_003E0C88(*(int*)(self + 0x30), a1, 0, 0);
        } else if (type == 2) {
            *(int*)(self + 0x38) = func_003E0D80(*(int*)(self + 0x30), *(int*)(self + 0xC), a2, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE2F8);
#ifdef SKIP_ASM
extern "C" void func_003AE2F8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x70))) = arg1;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE300);
#ifdef SKIP_ASM
struct sWSVtE300 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// Memory interface record filled by func_003DE928 (size field first).
struct sWSMemIfE300 {
    int size;                   // 0x0
    int f4;                     // 0x4
    void* (*release)(void*);    // 0x8
    int pad[5];
};

extern void* (*D_00509434[])(void*);
extern "C" void func_003AEE30(void* self, int flags);
extern "C" int func_003DE928(sWSMemIfE300* mi);
extern "C" void func_003E0A28(void* p);

extern "C" void func_003AE300(char* self, int flags)
{
    char* o = *(char**)(self + 0x64);
    if (o != 0) {
        sWSVtE300* vt = *(sWSVtE300**)(o + 0x18);
        vt[1].fn(o + vt[1].delta, 3);
        *(void**)(self + 0x64) = 0;
    }
    if (*(void**)(self + 0x0) != 0) {
        func_003AEE30(*(void**)(self + 0x0), 3);
        *(void**)(self + 0x0) = 0;
    }
    if (*(void**)(self + 0x5C) != 0) {
        D_00509434[0](*(void**)(self + 0x5C));
        *(void**)(self + 0x5C) = 0;
    }
    func_003E0A28(*(void**)(self + 0x30));
    *(void**)(self + 0x30) = 0;
    if (*(int*)(self + 0x14) != 0) {
        func_003E0A28(*(void**)(self + 0x34));
        *(void**)(self + 0x34) = 0;
    }
    {
        void* p = *(void**)(self + 0x20);
        if (p != 0) {
            sWSMemIfE300 mi;
            mi.size = 0x20;
            func_003DE928(&mi);
            mi.release(p);
            *(void**)(self + 0x20) = 0;
        }
    }
    {
        void* p = *(void**)(self + 0x28);
        if (p != 0) {
            sWSMemIfE300 mi;
            mi.size = 0x20;
            func_003DE928(&mi);
            mi.release(p);
            *(void**)(self + 0x28) = 0;
        }
    }
    if (*(void**)(self + 0x4) != 0) {
        D_00509434[0](*(void**)(self + 0x4));
        *(void**)(self + 0x4) = 0;
    }
    if (*(void**)(self + 0x8) != 0) {
        D_00509434[0](*(void**)(self + 0x8));
        *(void**)(self + 0x8) = 0;
    }
    if (flags & 1) {
        D_00509434[0](self);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE450);
#ifdef SKIP_ASM
struct sAlloc_AE450 {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void* free;
    int flags;
};
// PORT: the unit declares D_00509430 as char[] later; view bound by asm label
extern sAlloc_AE450 D_00509430_AE450 __asm__("D_00509430");
extern char D_00495210[];

struct sTimer_AE450 {
    unsigned int start;     // 0x0
    int pad4;
    long ticks;             // 0x8
    int period;             // 0x10
    int pad14;
};

struct func_003B0430_sObj;
struct func_003B0430_sKey;
extern "C" func_003B0430_sObj* func_003B0430(func_003B0430_sObj* self, func_003B0430_sKey* key);
// PORT: the unit declares func_003B0758 with int params; it stores pointers.
extern "C" void* func_003B0758_AE450(void* self, void* a1, void* a2, void* a3, int a4) __asm__("func_003B0758");
void* func_003AECB8(void* self, void* a1);
void* func_003AED20(void* self, void* a1, int a2);
extern "C" void* func_003AED40(void* self, int a1, int a2);
extern "C" int func_003AEEF8(void* self);
extern "C" void func_003E0AD8(int h, int a, int b);
extern "C" int func_003E0D80(int h, int a, int b, int c);
extern "C" void ASYNCFILE_release(int h, void* data, int* size);
extern "C" int func_003B0600(void* p, int a1);
extern "C" unsigned int func_003E4E98();
extern "C" int func_003E5008();
extern "C" void func_0042E508(void* timer);
extern "C" void* func_003AE888(void*, int);

static inline void* wsAlloc_AE450(sAlloc_AE450* a, int size)
{
    return a->alloc(D_00495210, size, 0, 0, a->flags);
}

static inline bool wsCanAlloc_AE450(sAlloc_AE450* a)
{
    return a->alloc != 0 && a->free != 0;
}

// PORT: 64-bit long tick counter
extern "C" int func_003AE450(char* self, int a1, int a2)
{
    func_003E0AD8(*(int*)(self + 0x34), 0x97, 0x33);
    func_003E0AD8(*(int*)(self + 0x30), 0x97, 0x33);
    if (*(int*)(self + 0x24) != 0) {
        int size;
        ASYNCFILE_release(*(int*)(self + 0x24), self + 0x20, &size);
        *(int*)(self + 0x38) = func_003E0D80(*(int*)(self + 0x30), *(int*)(self + 0x20), size, 0);
    }
    if (*(int*)(self + 0x2C) != 0) {
        int size;
        ASYNCFILE_release(*(int*)(self + 0x2C), self + 0x28, &size);
        *(int*)(self + 0x3C) = func_003E0D80(*(int*)(self + 0x34), *(int*)(self + 0x28), size, 0);
    }
    if (*(int*)(self + 0x14) == 0) {
        *(int*)(self + 0x3C) = *(int*)(self + 0x38);
    }
    if (*(int*)(self + 0x1C) == 0) {
        char* s = (char*)func_003AED40(wsAlloc_AE450(&D_00509430_AE450, 0x14), *(int*)(self + 0x34), *(int*)(self + 0x3C));
        *(char**)(self + 0x0) = s;
        *(unsigned int*)(self + 0x54) = *(int*)(s + 0xC) >= 0;
    } else {
        *(unsigned int*)(self + 0x54) = 0;
    }
    *(void**)(self + 0x64) = 0;
    if (wsCanAlloc_AE450(&D_00509430_AE450)) {
        char key[0x10];
        *(char**)(self + 0x60) = self;
        func_003B0758_AE450(key, self + 0x60, (void*)func_003AECB8, (void*)func_003AED20, a1);
        *(func_003B0430_sObj**)(self + 0x64) = func_003B0430((func_003B0430_sObj*)wsAlloc_AE450(&D_00509430_AE450, 0x1C), (func_003B0430_sKey*)key);
    }
    *(int*)(self + 0x74) = func_003B0600(*(void**)(self + 0x64), 0);
    sTimer_AE450* t = (sTimer_AE450*)wsAlloc_AE450(&D_00509430_AE450, 0x18);
    t->ticks = 0;
    t->start = func_003E4E98();
    t->period = 0x1000;
    *(sTimer_AE450**)(self + 0x5C) = t;
    func_0042E508(t);
    unsigned int ms = (unsigned int)(t->ticks * 1000) / func_003E5008();
    *(int*)(self + 0x40) = a2;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x58) = 0;
    *(unsigned int*)(self + 0x4C) = ms;
    if (*(void**)(self + 0x0) != 0) {
        func_003AEEF8(*(void**)(self + 0x0));
    }
    func_003AE888(self, 0x1000);
    return *(int*)(self + 0x74);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE6C8);
#ifdef SKIP_ASM
extern "C" int func_004139F8(float f);
extern "C" int func_003B0600(void* p, int a1);
extern "C" int func_003B0580(void* self);

extern "C" int func_003AE6C8(void* self, float f)
{
    *(float*)((char*)self + 0x48) = f;
    *(int*)((char*)self + 0x74) = func_003B0600(*(void**)((char*)self + 0x64), func_004139F8(f));
    *(int*)((char*)self + 0x44) = func_003B0580(*(void**)((char*)self + 0x64));
    return *(int*)((char*)self + 0x74);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE718);
#ifdef SKIP_ASM
extern "C" int func_003AF258(int, int);

extern "C" int func_003AE718(void *self) {
    if (*(int *)((char *)self + 0x70) != 0) {
        if (*(int *)((char *)self + 0x74) != 0) {
            return func_003AF258(*(int *)((char *)self + 0x70), *(int *)((char *)self + 0x44));
        }
        return func_003AF258(*(int *)((char *)self + 0x70), func_004139F8(*(float *)((char *)self + 0x48)));
    }
    return 0;
}
#endif

INCLUDE_ASM("world/wscriptcache", func_003AE780);

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE860);
#ifdef SKIP_ASM
extern "C" int func_003AEFA8(void* p);

extern "C" int func_003AE860(void** self)
{
    void* p = *self;
    int r = 1;
    if (p != 0) {
        r = func_003AEFA8(p);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE888);
#ifdef SKIP_ASM
struct func_003AE888_sTimer {
    unsigned int last;
    int pad4;
    ulong accum;
    unsigned int rate;
};

extern "C" int func_003AEE98(void* self, int v);
extern "C" unsigned int func_003E4E98();

// PORT: accum is a 64-bit ulong
extern "C" void* func_003AE888(void* self, int speed)
{
    if ((unsigned int)speed > 0x4000) {
        speed = 0x4000;
    }
    int s = speed;
    if (*(void**)self != 0) {
        func_003AEE98(*(void**)self, s);
    }
    func_003AE888_sTimer* t = *(func_003AE888_sTimer**)((char*)self + 0x5C);
    unsigned int now = func_003E4E98();
    if (t->rate == 0x1000) {
        t->accum += (ulong)(now - t->last);
    } else {
        t->accum += ((ulong)t->rate * (ulong)(now - t->last)) >> 12;
    }
    t->rate = s;
    t->last = now;
    return 0;
}
#endif

extern "C" void* func_003AE888(void*, int);

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE938__FPv);
#ifdef SKIP_ASM
void* func_003AE938(void* self)
{
    return func_003AE888(self, 0);
}
#endif

extern "C" void* func_003AE888(void*, int);

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE958__FPv);
#ifdef SKIP_ASM
void* func_003AE958(void* self)
{
    return func_003AE888(self, 0x1000);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE978);
#ifdef SKIP_ASM
extern "C" int func_003AEF48(int);

extern "C" int func_003AE978(int *arg0) {
    int temp_4;
    int var_2;

    temp_4 = *arg0;
    var_2 = 0;
    if (temp_4 != 0) {
        var_2 = func_003AEF48(temp_4);
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AE9A0);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B5F60();
extern "C" int func_003B7B48(int id, void* out);
extern "C" int func_003B7C40(int id, void* out);
extern "C" int func_003E5008();
extern "C" void func_0042E508(void* timer);

// PORT: accum is a 64-bit ulong
struct func_003AE9A0_sTimer {
    unsigned int last;
    int pad4;
    ulong accum;
    unsigned int rate;
};

struct func_003AE9A0_sInfo {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xC;
};

struct func_003AE9A0_sOwner {
    char pad[0xC];
    int id;
};

struct func_003AE9A0_sSync {
    func_003AE9A0_sOwner* owner;
    char pad04[0x48];
    int offset;
    int last;
    int enabled;
    int drift;
    func_003AE9A0_sTimer* timer;
};

extern "C" int func_003AE9A0(func_003AE9A0_sSync* self)
{
    func_003AE9A0_sInfo b;
    func_003AE9A0_sInfo a;
    func_003AE9A0_sTimer* t = self->timer;
    func_0042E508(t);
    unsigned int ms = (unsigned int)(t->accum * 1000) / func_003E5008();
    int res = ms - self->offset;
    if (self->enabled != 0) {
        func_003B58A0();
        func_003B7B48(self->owner->id, &a);
        func_003B7C40(a.field_0x4, &b);
        func_003B58D8();
        int d = b.field_0x4 - func_003B5F60();
        if (self->last < d) {
            self->last = d;
            self->drift = self->drift - self->drift / 8 + (d - res);
            int av = -self->drift;
            if (av < self->drift) av = self->drift;
            if (av > 0x108) {
                self->offset -= self->drift / 8;
                self->drift = 0;
                res = ms - self->offset;
            }
        }
    }
    return res;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AEAD0);
#ifdef SKIP_ASM
struct sAlloc_AEAD0 {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void* free;
    int flags;
};
// PORT: the unit declares D_00509430 as char[] later; view bound by asm label
extern sAlloc_AEAD0 D_00509430_AEAD0 __asm__("D_00509430");
extern char D_00495210[];

extern "C" unsigned char* func_003E12E0(void* q);
extern "C" int SYNCTASK_run(int a);
extern "C" int func_003B11F0(int v);
void* func_003B0720(void* self);
extern "C" void* func_003B11A0();
// PORT: func_003B04F8 returns its vcall's int result; the unit defines it void.
extern "C" int func_003B04F8_i(void* self, void* obj, void* item) __asm__("func_003B04F8");
extern "C" void func_003B0538(void* self);
extern "C" void* func_003E13E8(void* p, int a1);
extern "C" int func_003E1530(void* q);

struct sChunk_AEAD0 {
    unsigned char* data;    // 0x0
    unsigned char* body;    // 0x4
    unsigned int size;      // 0x8
};

static inline unsigned int le32_AEAD0(unsigned char* p)
{
    return (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
}

// PORT: chunk pointers passed through int parameters of some callees. The unit declares
// func_003AEAD0(int, void*) for its caller; the real body takes (self, ctx, out), bound by asm label.
extern "C" void func_003AEAD0_impl(char* self, char* ctx, sChunk_AEAD0** out) __asm__("func_003AEAD0");
extern "C" void func_003AEAD0_impl(char* self, char* ctx, sChunk_AEAD0** out)
{
    int kind = 0;
    void* q = *(void**)(self + 0x30);
    *out = 0;
    for (;;) {
        unsigned char* p = func_003E12E0(q);
        SYNCTASK_run(0);
        if (p != 0) {
            unsigned int tag = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
            if (func_003B11F0(tag))
                kind = 3;
            if (kind != 0) {
                sChunk_AEAD0* c = (sChunk_AEAD0*)func_003B0720(D_00509430_AEAD0.alloc(D_00495210, 0xC, 0, 0, D_00509430_AEAD0.flags));
                *out = c;
                c->data = p;
                if (kind == 2) {
                    unsigned int size = le32_AEAD0(p + 4);
                    c->body = p;
                    c->size = size;
                } else {
                    unsigned int size = le32_AEAD0(p + 4);
                    c->body = p + 8;
                    c->size = size;
                }
                if (*(int*)(ctx + 0x14) != 0)
                    return;
                if (kind != 3)
                    return;
                if (func_003B04F8_i(ctx, func_003B11A0(), c) != 2)
                    func_003B0538(ctx);
                return;
            }
            char name[8];
            *(unsigned int*)name = tag;
            name[4] = 0;
            func_003E13E8(q, (int)p);
        }
        if (func_003E1530(q))
            return;
    }
}
#endif

extern "C" void* func_003AEAD0(int, void*);

//100%
INCLUDE_ASM("world/wscriptcache", func_003AECB8__FPvT0);
#ifdef SKIP_ASM
void* func_003AECB8(void* self, void* a1)
{
    return func_003AEAD0(*(int*)a1, self);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AECE0);
#ifdef SKIP_ASM
extern "C" void* func_003E13E8(void* p, int a1);
extern void* (*D_00509434[])(void*);

extern "C" void* func_003AECE0(int self, int a1)
{
    int* obj = (int*)a1;
    void* r = func_003E13E8(*(void**)(self + 0x30), *obj);
    if (obj != 0) {
        r = D_00509434[0](obj);
    }
    return r;
}
#endif

extern "C" void* func_003AECE0(int, int);

//100%
INCLUDE_ASM("world/wscriptcache", func_003AED20__FPvT0i);
#ifdef SKIP_ASM
void* func_003AED20(void* self, void* a1, int a2)
{
    return func_003AECE0(*(int*)a1, a2);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AED40);
#ifdef SKIP_ASM
struct func_003AED40_sAlloc {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void* free;
    int flags;
};
// PORT: the unit declares D_00509430 as char[] later; view bound by asm label
extern func_003AED40_sAlloc D_00509430_v __asm__("D_00509430");
extern char D_00495250[];

extern "C" signed char func_003B5440();
extern "C" void func_003E62B0();
extern "C" int func_003BA020(void* desc);
extern "C" int func_003B7AC8(int a, int b);
extern "C" int func_003B7E38(int a, void* desc, int b, int c, void* mem, int size);
extern "C" int func_003B7DE8(int h, int a, int b);

extern "C" void* func_003AED40(void* self, int a1, int a2)
{
    char desc[0x18];
    if (func_003B5440() == 0) {
        func_003E62B0();
    } else {
        *(void**)((char*)self + 0x4) = 0;
        *(int*)((char*)self + 0x10) = -1;
        *(int*)((char*)self + 0xC) = -1;
        func_003BA020(desc);
        int size = func_003B7AC8(1, 0x1E);
        void* mem = D_00509430_v.alloc(D_00495250, size, 0, 0, D_00509430_v.flags);
        *(void**)((char*)self + 0x4) = mem;
        int h = func_003B7E38(a1, desc, 1, 0x1E, mem, size);
        *(int*)((char*)self + 0xC) = h;
        *(int*)((char*)self + 0x10) = func_003B7DE8(h, -1, a2);
        *(float*)self = 1.0f;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AEE30);
#ifdef SKIP_ASM
extern "C" int func_003B7838(void* a);
extern void* (*D_00509434[])(void*);

extern "C" void func_003AEE30(void* self, int flags)
{
    if (*(void**)((char*)self + 0x4) != 0) {
        func_003B7838(*(void**)((char*)self + 0xC));
        D_00509434[0](*(void**)((char*)self + 0x4));
        *(void**)((char*)self + 0x4) = 0;
    }
    if (flags & 1) {
        D_00509434[0](self);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AEE98);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7FB8(int h, int v);

extern "C" int func_003AEE98(void* self, int v)
{
    int r;
    if (*(int*)((char*)self + 0xC) != -1) {
        func_003B58A0();
        r = func_003B7FB8(*(int*)((char*)self + 0xC), v);
        func_003B58D8();
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AEEF8);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7D80(int h, int a1);

extern "C" int func_003AEEF8(void* self)
{
    int r;
    if (*(int*)((char*)self + 0x10) != -1) {
        func_003B58A0();
        r = func_003B7D80(*(int*)((char*)self + 0x10), 0);
        func_003B58D8();
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AEF48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003B7E70(int, int);
int func_003AEF48_impl(void *self, int arg) __asm__("func_003AEF48");

int func_003AEF48_impl(void *self, int arg) {
    int r;

    if (*(int *)((char *)self + 0xC) != -1) {
        func_003B58A0();
        r = func_003B7E70(*(int *)((char *)self + 0xC), arg);
        func_003B58D8();
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AEFA8);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7B48(int id, void* out);
extern "C" int func_003B7C40(int id, void* out);

struct func_003AEFA8_sInfo {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xC;
};

extern "C" int func_003AEFA8(void* self)
{
    func_003AEFA8_sInfo b;
    func_003AEFA8_sInfo a;
    func_003B58A0();
    if (func_003B7B48(*(int*)((char*)self + 0xC), &a) >= 0 && func_003B7C40(a.field_0x4, &b) >= 0) {
        func_003B58D8();
        return b.field_0x8 == 0;
    }
    func_003B58D8();
    return 0;
}
#endif

extern void* D_00456890[];

//100%
INCLUDE_ASM("world/wscriptcache", func_003AF010);
#ifdef SKIP_ASM
extern "C" void *func_003AF010(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    return arg0;
}
#endif

INCLUDE_ASM("world/wscriptcache", func_003AF020);
//100%
INCLUDE_ASM("world/wscriptcache", func_003AF0C8);
#ifdef SKIP_ASM
extern "C" void* func_003B0340(void*);
extern "C" void f03A8_F0C8(void*, int) __asm__("func_003B03A8");
extern "C" void f03B0_F0C8(void*, int) __asm__("func_003B03B0");
extern "C" void f03B8_F0C8(void*, int) __asm__("func_003B03B8");
extern "C" void f03C0_F0C8(void*, int) __asm__("func_003B03C0");
extern "C" void f03C8_F0C8(void*, unsigned int) __asm__("func_003B03C8");
extern "C" void f03D0_F0C8(void*, int) __asm__("func_003B03D0");
extern char D_00495260[];
struct sAlloc_F0C8 {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void (*free)(void* p);
    int flags;
};
// PORT: the unit declares D_00509430 as char[] later; view bound by asm label
extern sAlloc_F0C8 D_00509430_F0C8 __asm__("D_00509430");

struct sElem_F0C8 { char pad[0x34]; };
struct sSelf_F0C8 { sElem_F0C8* arr; unsigned int count; };

extern "C" void func_003AF0C8(void* vself, unsigned int count, int a2, int a3, int a4, int a5)
{
    sSelf_F0C8* self = (sSelf_F0C8*)vself;
    unsigned int* raw;
    char* arr;
    char* p;
    int i;
    unsigned int k;

    i = count - 1;
    raw = (unsigned int*)D_00509430_F0C8.alloc(D_00495260, count * 0x34 + 0x10, 0, 0, D_00509430_F0C8.flags);
    arr = (char*)raw + 0x10;
    *raw = count;
    p = arr;
    if (count != 0) {
        do {
            i--;
            func_003B0340(p);
            p += 0x34;
        } while (i != -1);
    }
    self->arr = (sElem_F0C8*)arr;
    self->count = count;
    if (count != 0) {
        f03D0_F0C8(arr, 0);
    }
    for (k = 0; k < self->count; k++) {
        f03A8_F0C8(&self->arr[k], a2);
        f03B0_F0C8(&self->arr[k], a3);
        f03B8_F0C8(&self->arr[k], a4);
        f03C0_F0C8(&self->arr[k], a5);
        f03C8_F0C8(&self->arr[k], k);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AF230);
#ifdef SKIP_ASM
struct func_003AF230_sArr {
    char* items;
    unsigned int count;
};

extern "C" void* func_003AF230(func_003AF230_sArr* self, unsigned int idx)
{
    if (self->count < idx) {
        return 0;
    }
    return self->items + idx * 0x34;
}
#endif

INCLUDE_ASM("world/wscriptcache", func_003AF258);
//100%
INCLUDE_ASM("world/wscriptcache", func_003AF2F8);
#ifdef SKIP_ASM
extern "C" int func_003AF2F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AF300);
#ifdef SKIP_ASM
extern unsigned char D_00499C81[];
static inline unsigned char ctype_3AF300(char c) { return D_00499C81[c]; }
extern "C" void func_003AF300(char** pp, unsigned int* plen)
{
    unsigned int n;
    char* p = *pp;
    for (n = 0; n < *plen && (ctype_3AF300(p[n]) & 8); n++) {
    }
    *pp = p + n;
    *plen = *plen - n;
}

#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003AF378);
#ifdef SKIP_ASM
extern unsigned char D_00499C81[];
static inline int to_lower_AF378(int c) { if (D_00499C81[c] & 1) return c + 0x20; return c; }

extern "C" int func_003AF378(const char* a, const char* b)
{
    int i;
    int d = 0;
    i = 0;
    while (a[i] != 0 && b[i] != 0) {
        d += to_lower_AF378(a[i]) - to_lower_AF378(b[i]);
        if (d != 0) {
            return d;
        }
        i++;
    }
    return a[i] - b[i];
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003AF428);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sNames_F428 { const char* e[5]; };
struct sVals_F428 { unsigned int e[5]; };
extern const sNames_F428 D_00495290;
extern const sVals_F428 D_004952A8;
extern "C" int func_003AF378(const char*, const char*) __asm__("func_003AF378");

extern "C" unsigned int func_003AF428(char* s, unsigned int len)
{
    unsigned int i;
    char ch = 9;
    unsigned int r;
    unsigned int j;

    for (i = 0; i < len; i++) {
        char c = s[i];
        if (c == 9 || c == 13) {
            s[i] = 0;
            ch = c;
            break;
        }
    }
    sNames_F428 names = D_00495290;
    sVals_F428 vals = D_004952A8;
    r = 0xFFFFFFFF;
    for (j = 0; j < 5; j++) {
        if (func_003AF378(names.e[j], s) == 0) {
            r = vals.e[j];
            break;
        }
    }
    if (i != len) {
        s[i] = ch;
    }
    return r;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003AF560);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long func_0041E9E0(unsigned char *s, unsigned char **end, int base);

extern "C" int func_003AF560(unsigned char **pp, unsigned int *plen, int *out) {
    unsigned int i;
    int ch = 9;
    unsigned char *end;
    long r;

    for (i = 0; i < *plen; i++) {
        unsigned char c = (*pp)[i];
        if ((unsigned int)(c - 9) < 2U) {
            ch = (signed char)c;
            (*pp)[i] = 0;
            break;
        }
    }
    r = func_0041E9E0(*pp, &end, 10);
    *plen = *plen - (end - *pp);
    if (i != *plen) {
        (*pp)[i] = (unsigned char)ch;
    }
    if (end == *pp) {
        return 0;
    }
    *out = (int)r;
    return 1;
}
#endif

INCLUDE_ASM("world/wscriptcache", func_003AF670);

INCLUDE_ASM("world/wscriptcache", func_003AF7F0);
//100%
INCLUDE_ASM("world/wscriptcache", func_003B0340);
#ifdef SKIP_ASM
extern "C" void *func_003B0340(void *self) {
    *(int *)((char *)self + 0x00) = 0x20;
    *(int *)((char *)self + 0x04) = 0x15E;
    *(int *)((char *)self + 0x08) = 0x258;
    *(int *)((char *)self + 0x0C) = 0x32;
    *(unsigned *)((char *)self + 0x10) = 0xFFFFFFFFu;
    *(unsigned char *)((char *)self + 0x24) = 0xFF;
    *(unsigned char *)((char *)self + 0x25) = 0xFF;
    *(unsigned char *)((char *)self + 0x26) = 0xFF;
    *(int *)((char *)self + 0x18) = 2;
    *(unsigned *)((char *)self + 0x14) = 0xFFFFFFFFu;
    *(unsigned char *)((char *)self + 0x27) = 0xFF;
    *(int *)((char *)self + 0x1C) = 2;
    *(int *)((char *)self + 0x20) = 0;
    *(int *)((char *)self + 0x28) = 0;
    *(int *)((char *)self + 0x2C) = 0;
    *(int *)((char *)self + 0x30) = 0;
    return self;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03A8);
#ifdef SKIP_ASM
extern "C" void func_003B03A8(int *arg0, int arg1) {
    *arg0 = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03B0);
#ifdef SKIP_ASM
extern "C" void func_003B03B0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (4))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03B8);
#ifdef SKIP_ASM
extern "C" void func_003B03B8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03C0);
#ifdef SKIP_ASM
extern "C" void func_003B03C0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03C8);
#ifdef SKIP_ASM
extern "C" void func_003B03C8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03D0);
#ifdef SKIP_ASM
extern "C" void func_003B03D0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03D8);
#ifdef SKIP_ASM
extern "C" void func_003B03D8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03E0);
#ifdef SKIP_ASM
extern "C" void func_003B03E0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03E8);
#ifdef SKIP_ASM
extern "C" void func_003B03E8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03F0);
#ifdef SKIP_ASM
extern "C" void func_003B03F0(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x24))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B03F8);
#ifdef SKIP_ASM
extern "C" void func_003B03F8(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x25))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B0400);
#ifdef SKIP_ASM
extern "C" void func_003B0400(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x26))) = arg1;
}
#endif
//100%
INCLUDE_ASM("world/wscriptcache", func_003B0408);
#ifdef SKIP_ASM
extern "C" void func_003B0408(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (0x27))) = arg1;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0410__FPv);
#ifdef SKIP_ASM
void* func_003B0410(void* self)
{
    int t0 = 0;
    *(int*)self = t0;
    *(int*)((char*)self + 0xc) = (int)(void*)D_00456890;
    *(int*)((char*)self + 0x4) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0430);
#ifdef SKIP_ASM
void* func_003B0738(void* self);
extern void* D_004568A8[];

struct func_003B0430_sKey {
    int v[4];
};

struct func_003B0430_sObj {
    int field_0x0;
    func_003B0430_sKey key;   // 0x4
    int field_0x14;
    void** vtable;            // 0x18
};

extern "C" func_003B0430_sObj* func_003B0430(func_003B0430_sObj* self, func_003B0430_sKey* key)
{
    self->vtable = D_004568A8;
    func_003B0738(&self->key);
    self->key = *key;
    self->field_0x14 = 0;
    self->field_0x0 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B04A0);
#ifdef SKIP_ASM
extern "C" void func_003B0538(void* self);
extern void* (*D_00509434[])(void*);
extern void* D_004568A8[];

extern "C" void func_003B04A0(void* self, int flags)
{
    *(void***)((char*)self + 0x18) = D_004568A8;
    func_003B0538(self);
    if (flags & 1) {
        D_00509434[0](self);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B04F8);
#ifdef SKIP_ASM
class func_003B04F8_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual int v02(void* a, int b);
    virtual void v03();
    virtual int v04();
    virtual float v05();
};

extern "C" void func_003B04F8(void* self, func_003B04F8_cObj* obj, int a2)
{
    *(func_003B04F8_cObj**)((char*)self + 0x14) = obj;
    *(int*)self = a2;
    obj->v02(self, a2);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0538);
#ifdef SKIP_ASM
struct sVEntry003B0538 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_003B0538(void* self)
{
    void* obj = *(void**)((char*)self + 0x14);
    if (obj != 0) {
        sVEntry003B0538* vt = *(sVEntry003B0538**)obj;
        vt[1].fn((char*)obj + vt[1].delta, 3);
        *(void**)((char*)self + 0x14) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0580);
#ifdef SKIP_ASM
extern "C" int func_003B0580(void* self)
{
    func_003B04F8_cObj* obj = *(func_003B04F8_cObj**)((char*)self + 0x14);
    if (obj == 0) {
        return 0;
    }
    return obj->v04();
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B05C0);
#ifdef SKIP_ASM
extern "C" float func_003B05C0(void* self)
{
    func_003B04F8_cObj* obj = *(func_003B04F8_cObj**)((char*)self + 0x14);
    if (obj == 0) {
        return 0.0f;
    }
    return obj->v05();
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0600);
#ifdef SKIP_ASM
class func_003B0600_cVirt {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual int v03(int);
};

struct func_003B0600_sObj {
    int loaded;                                    // 0x0
    void* arg;                                     // 0x4
    void (*load)(func_003B0600_sObj*, void*, func_003B0600_sObj*); // 0x8
    char pad_0xC[0x8];
    func_003B0600_cVirt* obj;                      // 0x14
};

extern "C" int func_003B0600(void* p, int a1)
{
    func_003B0600_sObj* self = (func_003B0600_sObj*)p;
    if (self->obj == 0) {
        if (self->loaded == 0) {
            self->load(self, self->arg, self);
        }
    }
    int r;
    if (self->obj != 0) {
        r = self->obj->v03(a1);
    } else {
        r = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0680);
#ifdef SKIP_ASM
class func_003B0680_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int a);
};

extern "C" void func_003B0680(void* self, int a)
{
    (*(func_003B0680_cObj**)((char*)self + 0x14))->v06(a);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B06B0);
#ifdef SKIP_ASM
struct func_003B06B0_sReq {
    int pending;
    int arg;
    void (*fn)(func_003B06B0_sReq* self, int arg, int* out);
};

extern "C" int func_003B06B0(func_003B06B0_sReq* self)
{
    int r;
    int v = self->pending;
    if (v != 0) {
        self->pending = 0;
        r = v;
        return v;
    }
    self->fn(self, self->arg, &r);
    return r;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B06F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sWSCb06F8 {
    int pad0;
    void* ctx;
    int pad8;
    void (*fn)(sWSCb06F8* self, void* ctx, int arg);
};

// The unit later declares func_003B06F8(void*, void*) for its caller; bind this definition by asm label.
void func_003B06F8_impl(sWSCb06F8* self, int arg) __asm__("func_003B06F8");
void func_003B06F8_impl(sWSCb06F8* self, int arg)
{
    self->fn(self, self->ctx, arg);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0720__FPv);
#ifdef SKIP_ASM
void* func_003B0720(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)((char*)self + 0x8) = t0;
    *(int*)self = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0738__FPv);
#ifdef SKIP_ASM
void* func_003B0738(void* self)
{
    int t0 = 0;
    *(int*)self = t0;
    *(int*)((char*)self + 0xc) = 2;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)((char*)self + 0x8) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0758);
#ifdef SKIP_ASM
extern "C" void* func_003B0758(void* self, int a1, int a2, int a3, int a4)
{
    *(int*)((char*)self + 0xc) = a4;
    *(int*)self = a1;
    *(int*)((char*)self + 0x4) = a2;
    *(int*)((char*)self + 0x8) = a3;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B0770);
#ifdef SKIP_ASM
extern char D_00509430[];
extern void* D_0050943C[];

extern "C" void* func_003B0770(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init != 0) {
            func_003B0410(D_00509430);
        } else {
            D_0050943C[0] = (void*)D_00456890;
        }
    }
}
#endif

extern "C" void* func_003B0770(int, int);

//100%
INCLUDE_ASM("world/wscriptcache", func_003B07B8__FPv);
#ifdef SKIP_ASM
void* func_003B07B8(void* self)
{
    return func_003B0770(1, 0xffff);
}
#endif

extern "C" void* func_003B0770(int, int);

//100%
INCLUDE_ASM("world/wscriptcache", func_003B07D8__FPv);
#ifdef SKIP_ASM
void* func_003B07D8(void* self)
{
    return func_003B0770(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B07F8);
#ifdef SKIP_ASM
extern "C" void* func_003B2A68(unsigned int w, int h, int bpp, int a3, int a4, int flags, int a6, int a7);
extern "C" void* func_003B3D40(void* img);
extern "C" void func_003E6448(void* dst, int value, int size);
extern int D_00509438[];

static inline char* func_003B07F8_data(char* p)
{
    if (*(int*)(p + 0xC) & 0x1000) {
        return p + *(int*)(p + 0x10);
    }
    return p + 0x10;
}

extern "C" void* func_003B07F8(void* self, unsigned int w, int h)
{
    *(int*)((char*)self + 0x0) = 2;
    *(int*)((char*)self + 0x8) = 3;
    *(int*)((char*)self + 0xC) = 3;
    *(int*)((char*)self + 0x10) = 0;
    char* img = (char*)func_003B2A68(w, h, 0x20, 0, 0, D_00509438[0], 0, 0xF0);
    *(char**)((char*)self + 0x4) = img;
    char* hdr = (char*)func_003B3D40(img);
    hdr[4] = 0x32;
    hdr[5] = 0x34;
    hdr[6] = 0x30;
    unsigned int size = ((w >> 4) * h >> 4) << 10;
    func_003E6448(func_003B07F8_data(*(char**)((char*)self + 0x4)), 0, size);
    **(char**)((char*)self + 0x4) = 5;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B08E0);
#ifdef SKIP_ASM
extern "C" void func_003B2B68(char* buf);
extern void* (*D_00509434[])(void*);

extern "C" void func_003B08E0(void* self, int flags)
{
    if (*(void**)((char*)self + 0x4) != 0) {
        func_003B2B68(*(char**)((char*)self + 0x4));
        *(void**)((char*)self + 0x4) = 0;
    }
    *(int*)((char*)self + 0x8) = 7;
    *(int*)((char*)self + 0xC) = 7;
    if (flags & 1) {
        D_00509434[0](self);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0948);
#ifdef SKIP_ASM
extern void* D_00456850[];

struct sWSNode2 {
    sWSNode2* next;
    sWSNode2* prev;
};

static inline void wsListInit(sWSNode2* h)
{
    h->next = (sWSNode2*)3;
    h->prev = (sWSNode2*)3;
    h->next = h;
    h->prev = h;
    h->next = h;
    h->prev = h;
}

extern "C" void* func_003B0948(void* self)
{
    *(void***)self = D_00456850;
    wsListInit((sWSNode2*)((char*)self + 0x18));
    wsListInit((sWSNode2*)((char*)self + 0x20));
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x78) = 0;
    return self;
}
#endif

INCLUDE_ASM("world/wscriptcache", func_003B09A0);

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0B10);
#ifdef SKIP_ASM
extern "C" void func_003B0B40(void* a, void* b, void* c);

extern "C" int func_003B0B10(void* self, void* a1, void* a2)
{
    func_003B0B40(a2, self, a1);
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B0B40);
#ifdef SKIP_ASM
extern "C" void func_003B06F8(void* req, void* blk);
extern "C" void func_003E6574(void* dst, void* src, int size);
extern "C" void func_004029D0(void* dst, void* src, int size);

struct func_003B0B40_sBlock {
    int f0;
    void* data;
    int size;
};

struct func_003B0B40_sScript {
    char pad00[0x14];
    int count;
    char pad18[0x10];
    func_003B06B0_sReq* req;
    char pad2C[0x4C];
    void* hdr;
    char* buf;
};

// PORT: func_003B06B0 returns the block pointer as int.
extern "C" void func_003B0B40(void* a, void* b, void* c)
{
    func_003B0B40_sScript* self = (func_003B0B40_sScript*)a;
    void* data = 0;
    func_003B0B40_sBlock* blk = (func_003B0B40_sBlock*)func_003B06B0(self->req);
    if (blk != 0) {
        data = blk->data;
    }
    int total;
    int i;
    if (data != 0) {
        i = blk->size;
        total = (i + 7) & ~0xF;
        i -= 8;
        func_003E6574(self->buf, data, i);
        for (; i < total + 0x10; i += 4) {
            *(int*)(self->buf + i) = 0;
        }
    } else {
        total = 0x10;
        for (i = 0; i < 0x10; i += 4) {
            *(int*)(self->buf + i) = 0xB7010000;
        }
    }
    if (blk != 0) {
        func_003B06F8(self->req, blk);
    }
    self->count++;
    func_004029D0(b, self->hdr, total);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0C58);
#ifdef SKIP_ASM
struct sAlloc_B0C58 {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void* (*free)(void* p);
    int flags;
};
// PORT: the unit declares D_00509430 as char[] later; view bound by asm label
extern sAlloc_B0C58 D_00509430_B0C58 __asm__("D_00509430");
struct sD_0050A088;
extern sD_0050A088 D_0050A088;
extern int D_00509648[];
// MPEG decoder globals: plain scalars outside small data (the original TU kept them out of $gp)
#define BSS_B0C58 __attribute__((section(".bss")))
extern int D_005094F4_s __asm__("D_005094F4") BSS_B0C58;
extern int D_005094F8_s __asm__("D_005094F8") BSS_B0C58;
extern int D_005094FC_s __asm__("D_005094FC") BSS_B0C58;
extern int D_00509500_s __asm__("D_00509500") BSS_B0C58;
extern int D_00509524_s __asm__("D_00509524") BSS_B0C58;
extern int D_00509548_s __asm__("D_00509548") BSS_B0C58;
extern int D_00509584_s __asm__("D_00509584") BSS_B0C58;
extern int D_0050958C_s __asm__("D_0050958C") BSS_B0C58;
extern int D_005095A0_s __asm__("D_005095A0") BSS_B0C58;
extern int D_005094D4_s __asm__("D_005094D4") BSS_B0C58;
extern int D_005094D8_s __asm__("D_005094D8") BSS_B0C58;
extern int D_005094DC_s __asm__("D_005094DC") BSS_B0C58;
extern int D_005094E0_s __asm__("D_005094E0") BSS_B0C58;
extern char D_004953E8[];
extern char D_004953F0[];
extern char D_00495400[];
extern "C" void func_003B1228(void* data);
extern "C" int func_003B13D8(void);
extern "C" void* func_003B07F8(void* self, unsigned int w, int h);
extern "C" void func_00402708(void);
extern "C" void func_004027B8(void* a, void* b, int size);
extern "C" void* func_00402C08(void* a, int n, void* fn, void* arg);
extern "C" int func_003B0B10(void* self, void* a1, void* a2);

struct sWSNode_B0C58 {
    sWSNode_B0C58* next;
    sWSNode_B0C58* prev;
};

struct sScript_B0C58 {
    char pad00[0x10];
    int count;
};

struct sData_B0C58 {
    int f0;
    void* data;
};

struct sPlayer_B0C58 {
    int f0;
    int state;              // 0x4
    int w;                  // 0x8
    int h;                  // 0xC
    int f10;                // 0x10
    int f14;                // 0x14
    sWSNode_B0C58 list18;   // 0x18
    sWSNode_B0C58 frames;   // 0x20
    sScript_B0C58* script;  // 0x28
    void* work;             // 0x2C
    char mpeg[0x48];        // 0x30
    void* ipuBuf;           // 0x78
    void* ipuBufUc;         // 0x7C
};

extern "C" int func_003B0C58(sPlayer_B0C58* self, sScript_B0C58* script, sData_B0C58* d)
{
    self->script = script;
    self->f10 = 0;
    self->f14 = 0;
    if (self->work != 0) {
        D_00509430_B0C58.free(self->work);
        self->work = 0;
    }
    if (self->ipuBuf != 0) {
        D_00509430_B0C58.free(self->ipuBuf);
        self->ipuBuf = 0;
    }
    self->state = 1;
    void* data = d->data;
    *(void**)&D_0050A088 = D_00509648;
    func_003B1228(data);
    func_003B13D8();
    int mode = D_00509648[0x420 / 4];
    if (mode == 0) {
        D_00509524_s = 1;
        D_005095A0_s = 1;
        D_00509584_s = 3;
        D_0050958C_s = 1;
        D_00509548_s = 5;
    }
    D_005094FC_s = (D_005094F4_s + 15) / 16;
    D_00509500_s = (mode != 0 && D_00509524_s == 0) ? (D_005094F8_s + 31) / 32 * 2 : (D_005094F8_s + 15) / 16;
    int w = D_005094FC_s * 16;
    D_005094D4_s = w;
    self->w = w;
    int h = D_00509500_s * 16;
    D_005094D8_s = h;
    self->h = h;
    D_005094DC_s = w >> 1;
    D_005094E0_s = h >> 1;
    int n = self->script->count;
    for (int i = 0; i < n; i++) {
        int cw = self->w;
        int ch = self->h;
        char* r = (char*)func_003B07F8(D_00509430_B0C58.alloc(D_004953E8, 0x14, 0, 0, D_00509430_B0C58.flags), cw, ch);
        sWSNode_B0C58* node = r ? (sWSNode_B0C58*)(r + 8) : 0;
        sWSNode_B0C58* head = &self->frames;
        sWSNode_B0C58* old = head->next;
        head->next = node;
        old->prev = node;
        node->next = old;
        node->prev = head;
    }
    self->work = D_00509430_B0C58.alloc(D_004953F0, self->w * self->h * 9 / 2 + 0x176C, 0, 0, D_00509430_B0C58.flags | 0x400);
    self->ipuBuf = D_00509430_B0C58.alloc(D_00495400, 0x32000, 0, 0, D_00509430_B0C58.flags | 0x400);
    self->ipuBufUc = (void*)(((unsigned int)self->ipuBuf & 0x0FFFFFFF) | 0x30000000);
    func_00402708();
    func_004027B8(self->mpeg, self->work, self->w * self->h * 9 / 2 + 0x176C);
    func_00402C08(self->mpeg, 1, (void*)func_003B0B10, self);
    return 2;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0FA0__FPv);
#ifdef SKIP_ASM
int func_003B0FA0(void* self)
{
    return *(int*)((char*)self + 0x10);
}
#endif

// padded past the 8-byte gp-relative threshold so the compiler emits
// absolute lui/lo addressing like the target, instead of assuming small data
struct sD_00509508 { float value; int pad[2]; };
extern sD_00509508 D_00509508;

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0FA8);
#ifdef SKIP_ASM
extern "C" float func_003B0FA8()
{
    return D_00509508.value;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B0FB8);
#ifdef SKIP_ASM
struct sWSPool;
struct sWSItem;
extern "C" sWSItem* func_003B10D0(sWSPool* self);
extern "C" void func_00402A10(void* dma, void* data, int qwc);

extern "C" void* func_003B0FB8(void* self)
{
    sWSItem* item = func_003B10D0((sWSPool*)self);
    char* hdr = *(char**)((char*)item + 0x4);
    char* data;
    if (*(int*)(hdr + 0xC) & 0x1000) {
        data = hdr + *(int*)(hdr + 0x10);
    } else {
        data = hdr + 0x10;
    }
    func_00402A10((char*)self + 0x30, data, *(int*)((char*)self + 0x8) / 16 * *(int*)((char*)self + 0xC) / 16);
    *(int*)((char*)self + 0x10) += 1;
    return item;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B1050);
#ifdef SKIP_ASM
extern "C" void* func_003B0FB8(void* self);
extern "C" int func_00402B38(void* sema);

class func_003B1050_cCache {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(void*);
};

extern "C" void* func_003B1050(func_003B1050_cCache* self, unsigned int limit)
{
    void* item = 0;
    do {
        if (item != 0) {
            self->v06(item);
        }
        if (func_00402B38((char*)self + 0x30) != 0) {
            return 0;
        }
        item = func_003B0FB8(self);
    } while (*(unsigned int*)((char*)self + 0x10) < limit);
    return item;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B10D0);
#ifdef SKIP_ASM
struct sWSNode {
    sWSNode* next;
    sWSNode* prev;

    void unlink()
    {
        sWSNode* n = next;
        sWSNode* p = prev;
        p->next = n;
        n->prev = p;
        prev = next = (sWSNode*)0xB;
    }
};

struct sWSList {
    sWSNode head;

    void addTail(sWSNode* n)
    {
        sWSNode* tail = head.prev;
        tail->next = n;
        head.prev = n;
        n->prev = tail;
        n->next = &head;
    }
};

struct sWSItemBase {
    int a;
    int b;
};

struct sWSItem : sWSItemBase, sWSNode {
    int refs; // 0x10
};

struct sWSPool {
    char pad00[0x18];
    sWSList used; // 0x18
    sWSList free; // 0x20
};

extern "C" sWSItem* func_003B10D0(sWSPool* self)
{
    sWSNode* n = self->free.head.next;
    if (n != &self->free.head) {
        sWSItem* item;
        n->unlink();
        item = static_cast<sWSItem*>(n);
        self->used.addTail(item);
        item->refs = 1;
        return item;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1140);
#ifdef SKIP_ASM
extern "C" void func_003B1140(sWSPool* self, sWSItem* item)
{
    if (--item->refs > 0) {
        return;
    }
    item->unlink();
    self->free.addTail(item);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B11A0);
#ifdef SKIP_ASM
struct sAlloc_11A0 {
    void* (*alloc)(const char* tag, int size, int align, int d, int flags);
    void* (*free)(void* p);
    int flags;
};
// PORT: the unit declares D_00509430 as char[] later; view bound by asm label
extern sAlloc_11A0 D_00509430_11A0 __asm__("D_00509430");
extern "C" void* func_003B11A0(void)
{
    return func_003B0948(D_00509430_11A0.alloc(D_004953E8, 0x80, 0, 0, D_00509430_11A0.flags));
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B11E8__FPv);
#ifdef SKIP_ASM
void func_003B11E8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B11F0);
#ifdef SKIP_ASM
extern int D_00495448[];

extern "C" int func_003B11F0(int v)
{
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (D_00495448[i] == v) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1228);
#ifdef SKIP_ASM
// defined (padded) later in the unit; incomplete here keeps lui/lo addressing
struct sD_0050A088;
extern sD_0050A088 D_0050A088;

extern "C" void func_003B1290(int n);

extern "C" void func_003B1228(void* data)
{
    char* r = *(char**)&D_0050A088;
    *(void**)(r + 0x0) = data;
    *(int*)(r + 0x8) = 0;
    *(int*)(r + 0x4) = 0;
    func_003B1290(0);
}
#endif

// padded past the 8-byte gp-relative threshold so the compiler emits
// absolute lui/lo addressing like the target
struct sD_0050A088 { void* ptr; int pad[2]; };
extern sD_0050A088 D_0050A088;

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1258);
#ifdef SKIP_ASM
extern "C" unsigned int func_003B1258(int a0)
{
    return *(unsigned int*)((char*)D_0050A088.ptr + 0x4) >> (unsigned int)(-a0);
}
#endif

extern "C" void* func_003B1300(int);

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1270__FPv);
#ifdef SKIP_ASM
void* func_003B1270(void* self)
{
    return func_003B1300(1);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1290);
#ifdef SKIP_ASM
struct sBitReader_1290 {
    unsigned char* p;   // 0x0
    unsigned int bits;  // 0x4
    int count;          // 0x8
};

// Reads the next byte into the bit buffer; taking the reader by reference matches the target's register copy.
static inline void FillByte_1290(sBitReader_1290*& r, int c)
{
    r->bits |= *r->p++ << (24 - c);
}

// Drops n bits from the bit buffer and refills it a byte at a time.
extern "C" void func_003B1290(int n)
{
    sBitReader_1290* r = (sBitReader_1290*)D_0050A088.ptr;
    r->bits <<= n;
    int c = r->count - n;
    while (c < 25) {
        FillByte_1290(r, c);
        c += 8;
    }
    ((sBitReader_1290*)D_0050A088.ptr)->count = c;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B1300);
#ifdef SKIP_ASM
extern "C" void func_003B1290(int n);

// PORT: returns a bit-field value as void* to fit the unit's existing
// `extern "C" void* func_003B1300(int)` declaration (really unsigned int).
extern "C" void* func_003B1300(int n)
{
    unsigned int v = func_003B1258(n);
    func_003B1290(n);
    return (void*)v;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1340);
#ifdef SKIP_ASM
struct sBitReader_1340 {
    unsigned char* p;   // 0x0
    unsigned int bits;  // 0x4
    int count;          // 0x8
};

// Reads the next byte into the bit buffer; taking the reader by reference matches the target's register copy.
static inline void FillByte_1340(sBitReader_1340*& r, int c)
{
    r->bits |= *r->p++ << (24 - c);
}

// Drops the whole 32-bit buffer and refills it a byte at a time.
extern "C" void func_003B1340(void)
{
    sBitReader_1340* r = (sBitReader_1340*)D_0050A088.ptr;
    r->bits = 0;
    int c = r->count - 32;
    while (c < 25) {
        FillByte_1340(r, c);
        c += 8;
    }
    ((sBitReader_1340*)D_0050A088.ptr)->count = c;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B13A8);
#ifdef SKIP_ASM
extern "C" void func_003B1340(void);

extern "C" unsigned int func_003B13A8(void)
{
    unsigned int v = func_003B1258(0x20);
    func_003B1340();
    return v;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B13D8);
#ifdef SKIP_ASM
// PORT: func_003B1498 takes no arguments (the unit declares it void*(void*)); bound by asm label
extern "C" void func_003B1498_noarg(void) __asm__("func_003B1498");
extern "C" void func_003B14F0(void);
extern "C" void group_of_pictures_header(void);
extern "C" void func_003B17A8(void);

extern "C" int func_003B13D8(void)
{
    for (;;) {
        func_003B1498_noarg();
        switch ((int)func_003B13A8()) {
        case 0x1B3:
            func_003B14F0();
            break;
        case 0x1B8:
            group_of_pictures_header();
            break;
        case 0x1B7:
            return 0;
        case 0x100:
            func_003B17A8();
            return 1;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B1498);
#ifdef SKIP_ASM
extern "C" void func_003B1290(int n);

// PORT: no return value here; the unit declares it void* and callers forward $v0.
void func_003B1498_impl(void* self) __asm__("func_003B1498");

void func_003B1498_impl(void* self)
{
    func_003B1290(*(int*)((char*)D_0050A088.ptr + 0x8) & 7);
    while (func_003B1258(0x18) != 1) {
        func_003B1290(8);
    }
}
#endif

INCLUDE_ASM("world/wscriptcache", func_003B14F0);

//100%
INCLUDE_ASM("world/wscriptcache", group_of_pictures_header);
#ifdef SKIP_ASM
extern int D_00509648[];
extern int D_0044C378[];
extern int D_0044C37C[];
extern int D_0044C380[];
extern void* D_00509628[];
extern void* D_0050962C[];
extern void* D_00509630[];
extern void* D_00509634[];
extern void* D_00509638[];
extern void* D_0050963C[];
extern void* D_00509640[];
extern char D_00495468[];
void* func_003B2360(void* self);
extern "C" void func_003B1988(void);

extern "C" void group_of_pictures_header(void)
{
    if (D_0050A088.ptr == D_00509648) {
        D_0044C378[0] = D_0044C37C[0] + 1;
        D_0044C380[0] = 1;
    }
    D_00509628[0] = func_003B1300(1);
    D_0050962C[0] = func_003B1300(5);
    D_00509630[0] = func_003B1300(6);
    func_003B2360(D_00495468);
    D_00509634[0] = func_003B1300(6);
    D_00509638[0] = func_003B1300(6);
    D_0050963C[0] = func_003B1300(1);
    D_00509640[0] = func_003B1300(1);
    func_003B1988();
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B17A8);
#ifdef SKIP_ASM
extern int D_00509554[];
extern int D_00509558[];
extern void* D_0050955C[];
extern void* D_00509560[];
extern void* D_00509564[];
extern void* D_00509568[];
extern void* D_0050956C[];
extern "C" void func_003B1988(void);
extern "C" int func_003B2318(void);
extern "C" void func_003B2440(void);

// PORT: func_003B1300 really returns unsigned int (unit declares void*)
extern "C" void func_003B17A8(void)
{
    *(int*)((char*)D_0050A088.ptr + 0x430) = 0;
    D_00509554[0] = (int)func_003B1300(0xA);
    D_00509558[0] = (int)func_003B1300(3);
    D_0050955C[0] = func_003B1300(0x10);
    if (D_00509558[0] == 2 || D_00509558[0] == 3) {
        D_00509560[0] = func_003B1300(1);
        D_00509564[0] = func_003B1300(3);
    }
    if (D_00509558[0] == 3) {
        D_00509568[0] = func_003B1300(1);
        D_0050956C[0] = func_003B1300(3);
    }
    func_003B2318();
    func_003B1988();
    func_003B2440();
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1878);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044C2D8[];
extern int D_005094F8_B1878[] __asm__("D_005094F8");

extern "C" int func_003B1878(void)
{
    int r;
    int v;
    int t;

    if (*(int*)((char*)D_0050A088.ptr + 0x420) != 0) {
        r = 0;
        if (D_005094F8_B1878[0] >= 0xAF1) {
            r = (int)func_003B1300(3);
        }
    } else {
        r = 0;
    }
    if (*(int*)((char*)D_0050A088.ptr + 0x424) == 1) {
        *(int*)((char*)D_0050A088.ptr + 0x434) = (int)func_003B1300(7);
    }
    t = (int)func_003B1300(5);
    {
        char *p = (char*)D_0050A088.ptr;
        *(int*)(p + 0x438) = *(int*)(p + 0x420) != 0
            ? (*(int*)(p + 0x428) != 0 ? (int)D_0044C2D8[t] : t * 2)
            : t;
    }
    if (func_003B1300(1) != 0) {
        *(int*)((char*)D_0050A088.ptr + 0x43C) = (int)func_003B1300(1);
        func_003B1300(1);
        func_003B1300(6);
        func_003B2318();
    } else {
        *(int*)((char*)D_0050A088.ptr + 0x43C) = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1988);
#ifdef SKIP_ASM
extern "C" unsigned int func_003B1258(int a0);
extern "C" unsigned int func_003B1300_u(int n) __asm__("func_003B1300");
extern "C" void func_003B1340(void);
extern "C" void func_003B1498_v(void) __asm__("func_003B1498");
extern "C" void func_003B2380_v(void) __asm__("func_003B2380__FPv");
extern "C" void func_003B1AB0(void);
extern "C" void func_003B1CC0(void);
extern "C" void func_003B1D58(void);
extern "C" void sequence_scalable_extension(void);
extern "C" void func_003B1FC8(void);
extern "C" void func_003B20B8(void);
extern "C" void picture_spatial_scalable_extension(void);
extern "C" void func_003B22F8(void);
extern "C" void copyright_extension(void);

// Parses a script block: runs one command per 0x1B5 token, skips 0x1B2 sections.
extern "C" void func_003B1988(void)
{
    unsigned int tok;
    func_003B1498_v();
    while ((tok = func_003B1258(0x20)) == 0x1B5 || tok == 0x1B2) {
        if (tok == 0x1B5) {
            func_003B1340();
            switch (func_003B1300_u(4)) {
            case 1: func_003B1AB0(); break;
            case 2: func_003B1CC0(); break;
            case 3: func_003B1D58(); break;
            case 5: sequence_scalable_extension(); break;
            case 7: func_003B1FC8(); break;
            case 8: func_003B20B8(); break;
            case 9: picture_spatial_scalable_extension(); break;
            case 10: func_003B22F8(); break;
            case 4: copyright_extension(); break;
            case 6: break;
            }
            func_003B1498_v();
        } else {
            func_003B1340();
            func_003B2380_v();
        }
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1AB0);
#ifdef SKIP_ASM
extern int D_005095DC[];
extern int D_00509520[];
extern int D_00509524[];
extern int D_00509528[];
extern int D_0050952C[];
extern int D_00509530[];
extern int D_00509534[];
extern int D_00509510[];
extern int D_00509514[];
extern int D_00509518[];
extern int D_005094EC[];
extern int D_005094F0[];
extern int D_005094F4[];
extern int D_005094F8[];
extern float D_00509504[];
struct sD_00509508;
extern float D_0044C388[];
extern char D_004954B8[];
void* func_003B2360(void* self);

struct sMpegCtx1AB0 {
    char pad[0x420];
    int f420;
    int f424;
};

// Parse an MPEG-2 sequence extension.
extern "C" void func_003B1AB0(void)
{
    sMpegCtx1AB0* g = (sMpegCtx1AB0*)D_0050A088.ptr;
    g->f420 = 1;
    g->f424 = 0;
    D_005095DC[0] = 0;
    D_00509520[0] = (int)func_003B1300(8);
    D_00509524[0] = (int)func_003B1300(1);
    D_00509528[0] = (int)func_003B1300(2);
    int hext = (int)func_003B1300(2);
    int vext = (int)func_003B1300(2);
    int brext = (int)func_003B1300(0xC);
    func_003B2360(D_004954B8);
    int vbvext = (int)func_003B1300(8);
    D_0050952C[0] = (int)func_003B1300(1);
    D_00509530[0] = (int)func_003B1300(2);
    D_00509534[0] = (int)func_003B1300(5);
    D_00509508.value = D_0044C388[D_00509510[0]] * ((float)(D_00509530[0] + 1) / (float)(D_00509534[0] + 1));
    if ((D_00509520[0] >> 7) & 1) {
        if ((D_00509520[0] & 0xF) == 5) {
            D_005094EC[0] = 0x85;
            D_005094F0[0] = 8;
        }
    } else {
        D_005094EC[0] = D_00509520[0] >> 4;
        D_005094F0[0] = D_00509520[0] & 0xF;
    }
    D_005094F4[0] = (hext << 12) | (D_005094F4[0] & 0xFFF);
    D_005094F8[0] = (vext << 12) | (D_005094F8[0] & 0xFFF);
    D_00509514[0] = D_00509514[0] + (brext << 18);
    D_00509504[0] = D_00509514[0] * 400.0f;
    D_00509518[0] = D_00509518[0] + (vbvext << 10);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1CC0);
#ifdef SKIP_ASM
extern void* D_00509538[];
extern void* D_0050953C[];
extern void* D_00509540[];
extern void* D_00509544[];
extern void* D_00509548[];
extern void* D_0050954C[];
extern void* D_00509550[];
extern char D_004954D0[];
void* func_003B2360(void* self);

extern "C" void func_003B1CC0(void)
{
    D_00509538[0] = func_003B1300(3);
    D_0050953C[0] = func_003B1300(1);
    if (D_0050953C[0] != 0) {
        D_00509540[0] = func_003B1300(8);
        D_00509544[0] = func_003B1300(8);
        D_00509548[0] = func_003B1300(8);
    }
    D_0050954C[0] = func_003B1300(0xE);
    func_003B2360(D_004954D0);
    D_00509550[0] = func_003B1300(0xE);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1D58);
#ifdef SKIP_ASM
struct sWSTables1D58 {
    char pad0[0x10];
    void* a10[64];              // 0x010
    void* a110[64];             // 0x110
    void* a210[64];             // 0x210
    void* a310[64];             // 0x310
    void* p410;                 // 0x410
    void* p414;                 // 0x414
    void* p418;                 // 0x418
    void* p41C;                 // 0x41C
};

extern unsigned char D_0044C218[];


extern "C" void func_003B1D58(void)
{
    sD_0050A088* gd = &D_0050A088;
    {
        void* p = func_003B1300(1);
        ((sWSTables1D58*)gd->ptr)->p410 = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                void* q = func_003B1300(8);
                int k = D_0044C218[i];
                sWSTables1D58* g = ((sWSTables1D58*)D_0050A088.ptr);
                g->a10[k] = q;
                g->a210[k] = q;
            }
        }
    }
    {
        void* p = func_003B1300(1);
        ((sWSTables1D58*)D_0050A088.ptr)->p414 = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                void* q = func_003B1300(8);
                int k = D_0044C218[i];
                sWSTables1D58* g = ((sWSTables1D58*)D_0050A088.ptr);
                g->a110[k] = q;
                g->a310[k] = q;
            }
        }
    }
    {
        void* p = func_003B1300(1);
        ((sWSTables1D58*)D_0050A088.ptr)->p418 = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                void* q = func_003B1300(8);
                int k = D_0044C218[i];
                sWSTables1D58* g = ((sWSTables1D58*)D_0050A088.ptr);
                g->a210[k] = q;
            }
        }
    }
    {
        void* p = func_003B1300(1);
        ((sWSTables1D58*)D_0050A088.ptr)->p41C = p;
        if (p != 0) {
            int i;
            for (i = 0; i < 64; i++) {
                void* q = func_003B1300(8);
                int k = D_0044C218[i];
                sWSTables1D58* g = ((sWSTables1D58*)D_0050A088.ptr);
                g->a310[k] = q;
            }
        }
    }
}
#endif

INCLUDE_ASM("world/wscriptcache", sequence_scalable_extension);

//100%
INCLUDE_ASM("world/wscriptcache", func_003B1FC8);
#ifdef SKIP_ASM
extern int D_00509524[];
extern int D_00509584[];
extern int D_00509588[];
extern int D_00509598[];
extern void* D_005095C0[];
extern void* D_005095D0[];
extern char D_00495538[];
extern char D_00495568[];
void* func_003B2360(void* self);

extern "C" void func_003B1FC8(void)
{
    int n;
    int i;
    if (D_00509524[0] != 0) {
        if (D_00509598[0] == 0) {
            n = 1;
        } else {
            n = D_00509588[0] != 0 ? 3 : 2;
        }
    } else if (D_00509584[0] != 3) {
        n = 1;
    } else {
        n = D_00509598[0] != 0 ? 3 : 2;
    }
    for (i = 0; i < n; i++) {
        D_005095C0[i] = func_003B1300(0x10);
        func_003B2360(D_00495538);
        D_005095D0[i] = func_003B1300(0x10);
        func_003B2360(D_00495568);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B20B8);
#ifdef SKIP_ASM
extern void* D_00509570[];
extern void* D_00509580[];
extern int D_00509584[];
extern int D_00509588[];
extern void* D_0050958C[];
extern void* D_00509590[];
extern void* D_00509594[];
extern int D_00509598[];
extern void* D_0050959C[];
extern void* D_005095A0[];
extern void* D_005095A4[];
extern void* D_005095A8[];
extern void* D_005095AC[];
extern void* D_005095B0[];
extern void* D_005095B4[];
extern void* D_005095B8[];

extern "C" void func_003B20B8(void)
{
    D_00509570[0] = func_003B1300(4);
    D_00509570[1] = func_003B1300(4);
    D_00509570[2] = func_003B1300(4);
    D_00509570[3] = func_003B1300(4);
    D_00509580[0] = func_003B1300(2);
    D_00509584[0] = (int)func_003B1300(2);
    D_00509588[0] = (int)func_003B1300(1);
    D_0050958C[0] = func_003B1300(1);
    D_00509590[0] = func_003B1300(1);
    *(void**)((char*)D_0050A088.ptr + 0x428) = func_003B1300(1);
    D_00509594[0] = func_003B1300(1);
    *(void**)((char*)D_0050A088.ptr + 0x42C) = func_003B1300(1);
    D_00509598[0] = (int)func_003B1300(1);
    D_0050959C[0] = func_003B1300(1);
    D_005095A0[0] = func_003B1300(1);
    D_005095A4[0] = func_003B1300(1);
    if (D_005095A4[0] != 0) {
        D_005095A8[0] = func_003B1300(1);
        D_005095AC[0] = func_003B1300(3);
        D_005095B0[0] = func_003B1300(1);
        D_005095B4[0] = func_003B1300(7);
        D_005095B8[0] = func_003B1300(8);
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", picture_spatial_scalable_extension);
#ifdef SKIP_ASM
extern void* D_005095F8[];
extern int D_005095FC[];
extern int D_00509600[];
extern void* D_00509604[];
extern void* D_00509608[];
extern void* D_0050960C[];
extern char D_00495598[];
extern char D_004955D0[];
void* func_003B2360(void* self);

// PORT: func_003B1300 really returns unsigned int (unit declares void*)
extern "C" void picture_spatial_scalable_extension(void)
{
    *(int*)((char*)D_0050A088.ptr + 0x430) = 1;
    D_005095F8[0] = func_003B1300(0xA);
    func_003B2360(D_00495598);
    D_005095FC[0] = (int)func_003B1300(0xF);
    if (D_005095FC[0] >= 0x4000) {
        D_005095FC[0] -= 0x8000;
    }
    func_003B2360(D_004955D0);
    D_00509600[0] = (int)func_003B1300(0xF);
    if (D_00509600[0] >= 0x4000) {
        D_00509600[0] -= 0x8000;
    }
    D_00509604[0] = func_003B1300(2);
    D_00509608[0] = func_003B1300(1);
    D_0050960C[0] = func_003B1300(1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B22F8);
#ifdef SKIP_ASM
extern int D_00495608[];

extern "C" void func_003B22F8(void)
{
    func_003B11E8(D_00495608);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B2318);
#ifdef SKIP_ASM
// PORT: func_003B1270 takes a void* it never reads; this caller passes nothing, so it binds
// a no-argument declaration to the mangled symbol.
void* func_003B1270_noarg() __asm__("func_003B1270__FPv");

extern "C" int func_003B2318(void)
{
    int n = 0;
    while (func_003B1270_noarg() != 0) {
        func_003B1290(8);
        n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2360__FPv);
#ifdef SKIP_ASM
void* func_003B2360(void* self)
{
    return func_003B1300(1);
}
#endif

extern "C" void* func_003B1498(void* self);

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2380__FPv);
#ifdef SKIP_ASM
void* func_003B2380(void* self)
{
    return func_003B1498(self);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", copyright_extension);
#ifdef SKIP_ASM
extern void* D_00509610[];
extern void* D_00509614[];
extern void* D_00509618[];
extern void* D_0050961C[];
extern void* D_00509620[];
extern void* D_00509624[];
extern char D_00495630[];
extern char D_00495658[];
extern char D_00495688[];
void* func_003B2360(void* self);

extern "C" void copyright_extension(void)
{
    D_00509610[0] = func_003B1300(1);
    D_00509614[0] = func_003B1300(8);
    D_00509618[0] = func_003B1300(1);
    func_003B1300(7);
    func_003B2360(D_00495630);
    D_0050961C[0] = func_003B1300(0x14);
    func_003B2360(D_00495658);
    D_00509620[0] = func_003B1300(0x16);
    func_003B2360(D_00495688);
    D_00509624[0] = func_003B1300(0x16);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2440);
#ifdef SKIP_ASM
extern int D_00509648[];
extern int D_00509554[];
extern int D_00509558[];
extern int D_0044C378[];
extern int D_0044C37C[];
extern int D_0044C380[];
extern int D_0044C3C8[];
extern int D_0044C3CC[];
extern int D_0050A098[];

extern "C" void func_003B2440(void)
{
    if (D_0050A088.ptr != D_00509648) {
        return;
    }
    int last;
    if (D_00509558[0] != 3 && D_00509554[0] != (last = D_0044C3CC[0])) {
        if (D_0044C3C8[0] != 0) {
            D_0044C3C8[0] = 0;
            D_0044C378[0] += 0x400;
        }
        if (D_00509554[0] < last && D_0044C380[0] == 0) {
            D_0044C3C8[0] = 1;
        }
        D_0044C380[0] = 0;
        D_0044C3CC[0] = D_00509554[0];
    }
    D_0050A098[0] = D_0044C378[0] + D_00509554[0];
    if (D_0044C3C8[0] != 0 && D_0044C3CC[0] >= D_00509554[0]) {
        D_0050A098[0] += 0x400;
    }
    D_0044C37C[0] = (D_0044C37C[0] < D_0050A098[0]) ? D_0050A098[0] : D_0044C37C[0];
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2528);
#ifdef SKIP_ASM
struct func_003B2528_sKey {
    char c;
};

extern "C" char func_003B3DA8(int key);
extern "C" unsigned char func_003B39D8(func_003B2528_sKey* k);

extern "C" int func_003B2528(int key)
{
    func_003B2528_sKey k;
    if (key == 0) {
        key = 0x20;
    }
    k.c = func_003B3DA8(key);
    return func_003B39D8(&k);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2558);
#ifdef SKIP_ASM
extern "C" int func_003B2528(int fmt);

extern "C" int func_003B2558(int w, int h, int fmt, int maxLevel)
{
    int total = 0;
    int c = func_003B2528(fmt);
    int bpp = 0x10;
    if (c != 0xF) bpp = c;
    if (w < 1 || w > 0x10000 || h < 1) return 0;
    if (h > 0x10000) return 0;
    if (w * h > 1000000000) return 0;
    if (func_003B3DA8(c) == 0) return 0;
    int i;
    for (i = 0; i <= maxLevel; i++) {
        int lw = w >> i;
        int lh = h >> i;
        if (lw <= 0) lw = 1;
        if (lh <= 0) lh = 1;
        if (total != 0) total = (total + 0xF) & ~0xF;
        total += ((lw * bpp + 7) / 8) * lh;
        if (lw == 1 && lh == 1) break;
    }
    return total;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2688);
#ifdef SKIP_ASM
extern "C" int func_003B2688(int v)
{
    switch (v) {
    case 8:
        return 0x100;
    case 4:
        return 0x10;
    default:
        return 0;
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B26B8);
#ifdef SKIP_ASM
extern "C" int func_003B2528(int fmt);
extern "C" int func_003B2558(int w, int h, int fmt, int maxLevel);

extern "C" int func_003B26B8(int w, int h, int fmt, int clut, int maxLevel, int extra1, int extra2)
{
    int c = func_003B2528(fmt);
    int size = func_003B2558(w, h, fmt, maxLevel);
    size += 0x10;
    if (c < 9 && clut != 0) {
        if (clut == 0xF) clut = 0x10;
        if (size != 0) size = (size + 0xF) & ~0xF;
        int n = func_003B2688(c) * clut / 8 + 0x10;
        size = ((size + 0xF) & ~0xF) + n;
    }
    if (extra1 != 0) {
        int t = size + 8;
        size = t + extra1;
    }
    if (extra2 != 0) {
        int t = size + 0x10;
        size = t + extra2;
    }
    return size;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B27C8);
#ifdef SKIP_ASM
extern "C" char func_003B3DA8(int key);
extern "C" void func_003E6448(void* dst, int value, int size);
// PORT: memset-like fill called with an unsigned all-ones value here
extern "C" void func_003E6448_u(void* dst, unsigned int value, int size) __asm__("func_003E6448");
extern "C" int func_003B2558(int w, int h, int fmt, int maxLevel);
extern "C" int func_003B2688(int v);
extern "C" unsigned char func_003B38B8(int clut);

struct sTexHdr_27C8 {
    unsigned type : 8;          // 0x0
    unsigned next : 24;
    short w;                    // 0x4
    short h;                    // 0x6
    int f8;                     // 0x8
    unsigned flags : 28;        // 0xC
    unsigned levels : 4;
    int dataOff;                // 0x10
};

struct sRGBA_27C8 {
    unsigned char r, g, b, a;
};

static inline unsigned char* texData_27C8(sTexHdr_27C8* t)
{
    if (*(int*)((char*)t + 0xC) & 0x1000) {
        return (unsigned char*)t + t->dataOff;
    }
    return (unsigned char*)t + 0x10;
}

extern "C" void func_003B27C8(void* tex, int w, int h, int fmt, int clut, int levels, int extra1, int extra2)
{
    sTexHdr_27C8* t = (sTexHdr_27C8*)tex;
    int bpp = 0x20;
    if (fmt != 0) bpp = fmt;
    char c = func_003B3DA8(bpp);
    func_003E6448(t, 0, 0x10);
    t->type = c;
    t->w = w;
    t->h = h;
    t->levels = levels;
    sTexHdr_27C8* hdr = t;
    unsigned char* p = (unsigned char*)hdr + (func_003B2558(w, h, bpp, levels) + 0x10);
    if (bpp < 9 && clut != 0) {
        int n = func_003B2688(bpp);
        unsigned char cfmt = func_003B38B8(clut);
        int off = ((p - (unsigned char*)hdr) + 0xF) & ~0xF;
        p = (unsigned char*)hdr + off;
        int cbits = 0x10;
        if (clut != 0xF) cbits = clut;
        hdr->next = off;
        func_003E6448(p, 0, 0x10);
        ((sTexHdr_27C8*)p)->type = cfmt;
        ((sTexHdr_27C8*)p)->h = 1;
        ((sTexHdr_27C8*)p)->w = n;
        if (clut >= 0x20) {
            sRGBA_27C8* pal = (sRGBA_27C8*)texData_27C8((sTexHdr_27C8*)p);
            for (int i = 0; i < n; i++) {
                pal[i].b = i;
                pal[i].g = i;
                pal[i].r = i;
                pal[i].a = 0xFF;
            }
        } else {
            func_003E6448_u(texData_27C8((sTexHdr_27C8*)p), 0xFFFFFFFF, n * cbits / 8);
        }
        hdr = (sTexHdr_27C8*)p;
        p += n * cbits / 8 + 0x10;
    }
    if (extra1 != 0) {
        hdr->next = p - (unsigned char*)hdr;
        hdr = (sTexHdr_27C8*)p;
        func_003E6448(p, 0, extra1 + 8);
        *(int*)(p + 4) = extra1;
        p[0] = 0x6F;
        p += extra1 + 8;
    }
    if (extra2 != 0) {
        hdr->next = p - (unsigned char*)hdr;
        func_003E6448(p, 0, extra2 + 0x10);
        p[0] = 0x69;
        *(short*)(p + 6) = 0x10;
        *(int*)(p + 0x10) = 0x455355;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B2A68);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_003B26B8(int w, int h, int fmt, int clut, int maxLevel, int extra1, int extra2);
extern "C" void func_003B27C8(void* tex, int w, int h, int fmt, int clut, int maxLevel, int extra1, int extra2);
extern void* (*D_0044C454[])(char* name, int size, int a2, int align, int heap);
extern char D_004956B0[];

extern "C" void* func_003B2A68(unsigned int w, int h, int fmt, int clut, int maxLevel, int heap, int extra1, int extra2)
{
    char name[16];
    void* tex = 0;
    int size = func_003B26B8(w, h, fmt, clut, maxLevel, extra1, extra2);
    if (size != 0) {
        sprintf(name, D_004956B0, w, h, fmt);
        tex = D_0044C454[0](name, size, 0, 0x10, heap);
        if (tex != 0) {
            func_003B27C8(tex, w, h, fmt, clut, maxLevel, extra1, extra2);
        }
    }
    return tex;
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2B68);
#ifdef SKIP_ASM
extern void (*D_0044C458[])(char* buf);

extern "C" void func_003B2B68(char* buf)
{
    buf[0] = 0;
    D_0044C458[0](buf);
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2B90);
#ifdef SKIP_ASM
// Decodes one 4x4 alpha block into the alpha bytes of dst: mode 3 is DXT3 (explicit 4-bit alpha),
// anything else is DXT5 (two endpoints + 3-bit indices).
// NOTE: the DXT3 path steps through dst as `unsigned long` (64-bit on the EE), not as 32-bit pixels.
// PORT: callers declare func_003B2B90 with char* parameters; defined under an asm label.
extern "C" void func_003B2B90_impl(unsigned long* dst, int stride, unsigned char* src, int mode) __asm__("func_003B2B90");
extern "C" void func_003B2B90_impl(unsigned long* dst, int stride, unsigned char* src, int mode)
{
    if (mode == 3) {
        for (unsigned int y = 0; y < 4; y++) {
            for (unsigned int x = 0; x < 2; x++) {
                unsigned char b = *src++;
                unsigned int lo = b & 0xF;
                *dst = (*dst & 0xFFFFFF) | (int)((lo | (lo << 4)) << 24);
                dst++;
                unsigned int hi = b & 0xF0;
                *dst = (*dst & 0xFFFFFF) | (int)((hi | (hi >> 4)) << 24);
                dst++;
            }
            dst = (unsigned long*)((char*)dst + stride - 0x20);
        }
        return;
    }
    unsigned char* s = src;
    unsigned char* d = (unsigned char*)dst + 3;
    unsigned char a0 = *s++;
    unsigned char a1 = *s++;
    unsigned char a2, a3, a4, a5, a6, a7;
    if (a0 > a1) {
        a2 = (6 * a0 + a1 + 3) / 7;
        a3 = (5 * a0 + 2 * a1 + 3) / 7;
        a4 = (4 * a0 + 3 * a1 + 3) / 7;
        a5 = (3 * a0 + 4 * a1 + 3) / 7;
        a6 = (2 * a0 + 5 * a1 + 3) / 7;
        a7 = (a0 + 6 * a1 + 3) / 7;
    } else {
        a2 = (4 * a0 + a1 + 2) / 5;
        a3 = (3 * a0 + 2 * a1 + 2) / 5;
        a4 = (2 * a0 + 3 * a1 + 2) / 5;
        a5 = (a0 + 4 * a1 + 2) / 5;
        a6 = 0;
        a7 = 0xFF;
    }
    for (int i = 0; i < 2; i++) {
        unsigned long bits = *(unsigned long*)s;
        s += 3;
        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < 4; x++) {
                unsigned char idx = bits & 7;
                bits >>= 3;
                switch (idx) {
                case 0: *d = a0; break;
                case 1: *d = a1; break;
                case 2: *d = a2; break;
                case 3: *d = a3; break;
                case 4: *d = a4; break;
                case 5: *d = a5; break;
                case 6: *d = a6; break;
                case 7: *d = a7; break;
                }
                d += 4;
            }
            d += stride - 0x10;
        }
    }
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B2E78);
#ifdef SKIP_ASM
// PORT: 64-bit `ulong` palette entries (`long` is 8 bytes on this compiler).
static inline unsigned short dxtTo1555_2E78(unsigned short c)
{
    if (c != 0) {
        // the alpha bit is a sign-extended short constant (forces the final 16-bit mask)
        int g = ((c >> 1) & 0x3E0) | (short)0x8000;
        c = ((c & 0x1F) << 10) | g | (c >> 11);
    }
    return c;
}

// Decode one DXT1 block into 4 rows of 4 64-bit texels.
extern "C" void func_003B2E78(char* src, int pitch, char* dst)
{
    ulong pal[4];
    ulong c = *(ulong*)dst;
    ulong c0 = ((c & 0x1F) << 3) | ((c & 0x7E0) << 5) | ((c & 0xF800) << 8);
    ulong c1 = ((c >> 13) & 0xF8) | ((c >> 11) & 0xFC00) | ((c & 0xF8000000) >> 8);
    pal[0] = c0 | 0x40204;
    pal[1] = c1 | 0x40204;
    if (c0 >= c1) {
        int b0 = c0 & 0xFF0000;
        int b1 = c1 & 0xFF0000;
        int g0 = c0 & 0xFF00;
        int g1 = c1 & 0xFF00;
        int r0 = c0 & 0xFF;
        int r1 = c1 & 0xFF;
        pal[2] = ((((b0 * 5 + b1 * 3) >> 3) & 0xFF0000) | (((g0 * 5 + g1 * 3) >> 3) & 0xFF00)) | (((r0 * 5 + r1 * 3) >> 3) & 0xFF);
        pal[3] = (((((b0 * 3 + b1 * 5) >> 3) & 0xFF0000) | (((g0 * 3 + g1 * 5) >> 3) & 0xFF00)) | (((r0 * 3 + r1 * 5) >> 3) & 0xFF)) | 0xFF000000UL;
    } else {
        int b0 = c0 & 0xFF0000;
        int b1 = c1 & 0xFF0000;
        int g0 = c0 & 0xFF00;
        int g1 = c1 & 0xFF00;
        int r0 = c0 & 0xFF;
        int r1 = c1 & 0xFF;
        pal[2] = ((ulong)((r0 + r1) | ((g0 + g1) | (b0 + b1))) >> 1) | 0xFF000000UL;
        pal[3] = 0;
    }
    pal[0] |= 0xFF000000;
    pal[1] |= 0xFF000000;
    pal[2] |= 0xFF000000;
    pal[0] = dxtTo1555_2E78(pal[0]);
    pal[1] = dxtTo1555_2E78(pal[1]);
    pal[2] = dxtTo1555_2E78(pal[2]);
    pal[3] = dxtTo1555_2E78(pal[3]);
    unsigned int b;
    b = ((unsigned char*)dst)[4];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
    src += pitch;
    b = ((unsigned char*)dst)[5];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
    src += pitch;
    b = ((unsigned char*)dst)[6];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
    src += pitch;
    b = ((unsigned char*)dst)[7];
    ((ulong*)src)[0] = pal[b & 3];
    ((ulong*)src)[1] = pal[(b >> 2) & 3];
    ((ulong*)src)[2] = pal[(b >> 4) & 3];
    ((ulong*)src)[3] = pal[b >> 6];
}
#endif

//100%
INCLUDE_ASM("world/wscriptcache", func_003B3308);
#ifdef SKIP_ASM
// PORT: 64-bit `long` compares (ld); `long` is 8 bytes on this compiler.
extern "C" int func_003B3308(void* buf, int size, int type)
{
    if (type == 3) {
        unsigned long* p = (unsigned long*)buf;
        int n = size / 16;
        int i;
        for (i = 0; i < n; i++) {
            unsigned long v = *p++;
            if (v != 0xFFFFFFFF) {
                return 1;
            }
            if (*p != v) {
                return 1;
            }
            p += 3;
        }
    } else {
        unsigned short* q = (unsigned short*)buf;
        int n = size / 16;
        int i;
        for (i = 0; i < n; i++) {
            if (*q != 0xFFFF) {
                return 1;
            }
            q += 16;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/wscriptcache", func_003B33B0);
#ifdef SKIP_ASM
extern "C" int func_003B3308(void* buf, int size, int type);
extern "C" void func_003B2E78(char* src, int pitch, char* dst);
extern "C" void func_003B2B90(char* src, int pitch, char* dst, int fmt);

// Compress a w x h image into 4x4 blocks.
extern "C" void func_003B33B0(void* out, char* src, int w, int h, int fmt)
{
    char* dst = (char*)out;
    int x, y;
    int n = w * h;
    if (fmt == 3 || fmt == 5) {
        if (func_003B3308(dst, n, fmt)) {
            for (y = 0; y < h; y += 4) {
                for (x = 0; x < w; x += 4) {
                    func_003B2E78(src, w * 8, dst + 8);
                    func_003B2B90(src, w * 8, dst, fmt);
                    src += 0x20;
                    dst += 0x10;
                }
                src += w * 0x18;
            }
        } else {
            for (y = 0; y < h; y += 4) {
                for (x = 0; x < w; x += 4) {
                    func_003B2E78(src, w * 8, dst + 8);
                    src += 0x20;
                    dst += 0x10;
                }
                src += w * 0x18;
            }
        }
    } else {
        for (y = 0; y < h; y += 4) {
            for (x = 0; x < w; x += 4) {
                func_003B2E78(src, w * 4, dst);
                src += 0x20;
                dst += 8;
            }
            src += w * 0x18;
        }
    }
}
#endif

