#include "common.h"

//100%
INCLUDE_ASM("world/wscriptcache", cWScriptCache_init);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void* func_003ACA50(void* self);
extern "C" void func_003ACA70(int* self, int flags);
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
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
    char* mem = (char*)operator_new__FUi(count * 0xC + 0x10, D_00495070, 0x20000000, 0);
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
    *(short*)self = (short)0;
    *(int*)((char*)self + 0x4) = -1;
    *(int*)((char*)self + 0x8) = 0;
    *(short*)((char*)self + 0x2) = (short)0;
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
extern "C" void* func_003B47F8(int, int);
extern "C" int func_003B4818_CAD0(int) __asm__("func_003B4818");
extern "C" int func_003DF980(int);
extern "C" void func_003E6574_CAD0(int, int, int) __asm__("func_003E6574");
int operator_new_CAD0(unsigned int, void*, int, int) __asm__("operator_new__FUi");
extern char D_00495080[];
extern "C" void func_003ACAD0_impl(void *self_) __asm__("func_003ACAD0");
extern "C" void func_003ACAD0_impl(void *self_) {
    char *self = (char*)self_;
    short st = *(short*)self;
    if (st == 1 && func_003DF980(*(int*)(self + 4)) == st) {
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
extern "C" int* func_003ADCB0(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(int**)((char*)data + 0x14);
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
extern "C" void* func_003ADD10(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(void**)((char*)data + 0x2C);
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
extern "C" void* func_003ADD70(void* self)
{
    if (*(short*)self == 3) {
        void* data = *(void**)((char*)self + 0x8);
        if (data != 0) {
            return *(void**)((char*)data + 0x24);
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
