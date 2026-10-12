#include "common.h"

//100%
INCLUDE_ASM("sound/soundsys", cBankSys_cBankSys);
#ifdef SKIP_ASM
extern "C" void* func_002ADE88(void* self, int heap);
extern "C" void* cBankManager_cBankManager(void* self, int embedded, int count, int heap);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

struct sSndBsVtEnt {
    short delta;
    short index;
    void* fn;
};
struct sSndBsVt4 {
    sSndBsVtEnt e[4];
} __attribute__((aligned(8)));
struct sSndBsVt7 {
    sSndBsVtEnt e[7];
} __attribute__((aligned(8)));

extern char D_00483A48[];
extern char D_00483B48[];
extern const char D_004A3668[];
extern const char D_004A3670[];
extern const sSndBsVt4 D_00483A60_bs __asm__("D_00483A60");
extern const sSndBsVt7 D_00483A80_bs __asm__("D_00483A80");
extern int D_004A3664;

// PORT: hand-expanded g++ 2.95 virtual-base ctor (vtable upcast-offset fixup on stack copies).
extern "C" char* cBankSys_cBankSys(char* self, int embedded, int count, int heap)
{
    if (embedded) {
        char* mon = self + 0x10;
        *(char**)self = self + 0x18;
        *(char**)(self + 0x1F0) = mon;
        func_002ADE88(mon, heap);
        cBankManager_cBankManager(*(void**)self, 0, count, heap);
    }
    *(const void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &D_00483A60_bs;
    *(void**)(*(char**)self + 0xAB0) = D_00483B48;
    *(const void**)(*(char**)self + 0x1D4) = &D_00483A80_bs;
    if (!embedded) {
        sSndBsVt4 t1 = D_00483A60_bs;
        *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &t1;
        char* c1 = *(char**)(*(char**)self + 0x1D8) - 0x10;
        int adj1 = self - c1;
        t1.e[1].delta = D_00483A60_bs.e[1].delta + adj1;
        sSndBsVt7 t2 = D_00483A80_bs;
        *(void**)(*(char**)self + 0x1D4) = &t2;
        char* c2 = *(char**)self - 0x18;
        int adj2 = self - c2;
        t2.e[1].delta = D_00483A80_bs.e[1].delta + adj2;
    }
    *(void**)(self + 0xC) = D_00483A48;
    D_004A3664 = (int)self;
    *(void**)(self + 4) = new (D_004A3668, 0, 0) char[0x10];
    *(void**)(self + 8) = new (D_004A3670, 0, 0) char[0x10];
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0028FEA0);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);

struct sSndDtVtEnt {
    short delta;
    short index;
    void* fn;
};
struct sSndDtVt4 {
    sSndDtVtEnt e[4];
} __attribute__((aligned(8)));
struct sSndDtVt7 {
    sSndDtVtEnt e[7];
} __attribute__((aligned(8)));

extern char D_00483A48[];
extern const sSndDtVt4 D_00483A60;
extern const sSndDtVt7 D_00483A80;
extern char D_00483B48[];
extern int D_004A3664;

// PORT: hand-expanded g++ 2.95 virtual-base dtor (vtable upcast-offset fixup on stack copies).
extern "C" void func_0028FEA0(char* self, int flags)
{
    *(void**)(self + 0xC) = D_00483A48;
    *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = (void*)&D_00483A60;
    *(void**)(*(char**)self + 0xAB0) = D_00483B48;
    *(void**)(*(char**)self + 0x1D4) = (void*)&D_00483A80;
    if (flags == 0) {
        sSndDtVt4 t1 = D_00483A60;
        *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &t1;
        char* c1 = *(char**)(*(char**)self + 0x1D8) - 0x10;
        int adj1 = self - c1;
        t1.e[1].delta = D_00483A60.e[1].delta + adj1;
        sSndDtVt7 t2 = D_00483A80;
        *(void**)(*(char**)self + 0x1D4) = &t2;
        char* c2 = *(char**)self - 0x18;
        int adj2 = self - c2;
        t2.e[1].delta = D_00483A80.e[1].delta + adj2;
    }
    if (*(void**)(self + 4)) cMemMan_free(*(void**)(self + 4));
    if (*(void**)(self + 8)) cMemMan_free(*(void**)(self + 8));
    D_004A3664 = 0;
    if (flags & 2) {
        func_0028BB10(*(void**)self, 0);
        func_002ADEE8(*(void**)(*(char**)self + 0x1D8), 0);
    }
    if (flags & 1) operator_delete((int*)self);
}
#endif

INCLUDE_ASM("sound/soundsys", func_002906B8);

INCLUDE_ASM("sound/soundsys", func_00290B58);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00290C10);
#ifdef SKIP_ASM
struct func_00290B58_sCurve {
    float x[5];
    float y[5];
};

extern "C" float func_00290B58(func_00290B58_sCurve* c, float v);
extern func_00290B58_sCurve D_00445898[];

extern "C" float func_00290C10(int i, float v)
{
    return func_00290B58(&D_00445898[i], v);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00290C40);
#ifdef SKIP_ASM
struct sSndVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSndVEntryVec {
    short delta;
    short index;
    sSndVec4* (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float sndVu0Length(const sSndVec4& v)
{
    float r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %0, $vi22\n"
        : "=r"(r)
        : "m"(v));
    return r;
}

extern "C" float func_00290C10(int i, float v);

extern "C" int func_00290C40(void* self, void* src)
{
    char* obj = (char*)src + 0x6C0;
    sSndVEntryVec* vt = *(sSndVEntryVec**)obj;
    sSndVec4* p = vt[2].fn(obj + vt[2].delta);
    int v = (int)func_00290C10(3, sndVu0Length(*p));
    if (v > 127) {
        v = 127;
    }
    if (v < 0) {
        v = 0;
    }
    return v;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00290CC0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd0CC0Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd0CC0E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd0CC0Sub {
    char pad0[4];
    sSnd0CC0Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd0CC0Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd0CC0E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd0CC0Mgr {
    char pad0[0x1D8];
    sSnd0CC0Sub sub;         // 0x1D8
};
struct sSnd0CC0Sys {
    sSnd0CC0Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd0CC0Mgr** p118;      // 0x118
};

extern "C" int func_00290CC0(void* vself, int a, int b)
{
    sSnd0CC0Sys* self = (sSnd0CC0Sys*)vself;
    sSnd0CC0Mgr* m = self->mgr;
    sSnd0CC0Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd0CC0Mgr** pp = self->p118;
    int r = (int)func_00287968(self, 5, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00290F58);
#ifdef SKIP_ASM
extern "C" int func_00285D98(void* self, int which);
extern "C" int func_00288CE8(void* self);

extern "C" void func_00290F58(void* self, int id, float v)
{
    if (func_00285D98(self, 0) == id) {
        *(float*)((char*)self + 0x6074) = v;
    } else if (func_00288CE8(self) == 2 && func_00285D98(self, 1) == id) {
        *(float*)((char*)self + 0x6078) = v;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00290FD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_0011FE98(void*);
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");

extern "C" int func_00290FD0(void* self, int which)
{
    int r = 3;
    char* rider = (char*)func_00285D98_p(self, which);
    if (func_0011FE98(rider) != 1) {
        return 3;
    }
    float v = *(float*)((char*)self + (which << 2) + 0x6074);
    int s = *(int*)(*(char**)(rider + 0x788) + 0xAC);
    int ok = s == 1 || s == 3;
    float d;
    if (ok) {
        char* st = *(char**)(rider + 0x788);
        d = *(float*)(st + 0x98) - *(float*)(st + 0xA0);
    } else {
        d = 4.0f;
    }
    if (d <= 3.0f && v > 0.0f) {
        if (v < 0.25f) {
            r = 0;
        } else if (v < 0.5f) {
            r = 1;
        } else {
            r = 2;
        }
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002910E0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd10E0Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd10E0E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd10E0Sub {
    char pad0[4];
    sSnd10E0Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd10E0Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd10E0E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd10E0Mgr {
    char pad0[0x1D8];
    sSnd10E0Sub sub;         // 0x1D8
};
struct sSnd10E0Sys {
    sSnd10E0Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd10E0Mgr** p118;      // 0x118
};

static inline void snd10E0Init(void* vself, int a, int b)
{
    sSnd10E0Sys* self = (sSnd10E0Sys*)vself;
    sSnd10E0Mgr* m = self->mgr;
    sSnd10E0Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
}


struct sSndKey8_10E0 {
    long v;
} __attribute__((packed));
extern sSndKey8_10E0 D_004A3680[];

// PORT: 64-bit long sound key; voice target stored as int
extern "C" void func_002910E0(void* vself)
{
    sSnd10E0Sys* self = (sSnd10E0Sys*)vself;
    if (*(int*)((char*)self + 0x5834) != 0) {
        return;
    }
    snd10E0Init(self, 0, 0x20);
    (*self->p118)->sub.p3C[(*self->p118)->sub.cur] = (int)((char*)self + 0x5830);
    (*self->p118)->sub.p7C[(*self->p118)->sub.cur] = 0;
    sSnd10E0Mgr* m = *self->p118;
    sSndKey8_10E0 k = D_004A3680[0];
    sSnd10E0Sub* s = &m->sub;
    *(sSndKey8_10E0*)((char*)s + (m->sub.cur << 3) + 0x40) = k;
    func_002906B8(self);
    *(int*)((char*)self + 0x5834) = 1;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002913D8);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00291438);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd1438Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd1438E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd1438Sub {
    char pad0[4];
    sSnd1438Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd1438Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd1438E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd1438Mgr {
    char pad0[0x1D8];
    sSnd1438Sub sub;         // 0x1D8
};
struct sSnd1438Sys {
    sSnd1438Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd1438Mgr** p118;      // 0x118
};

static inline int snd1438AddVoice(void* vself, int a, int b, int type)
{
    sSnd1438Sys* self = (sSnd1438Sys*)vself;
    sSnd1438Mgr* m = self->mgr;
    sSnd1438Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd1438Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_003B58A0();
extern "C" int func_003B8AB8(int id);
extern "C" void func_003B58D8();
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_00291438(void* self)
{
    func_003B58A0();
    int busy = func_003B8AB8(*(int*)((char*)self + 0x5FCC)) != 0;
    func_003B58D8();
    if (!busy) {
        func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + 0x5FCC), 1, 0.0f);
    }
    *(int*)((char*)self + 0x5FCC) = snd1438AddVoice(self, 8, 0x10, 5);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00291710);
#ifdef SKIP_ASM
int func_0011FE98(void* rider);

// PORT: the unit declares this as int(void*, int); defined under an asm label with its real type
extern "C" int func_00291710_impl(void* self, void* rider) __asm__("func_00291710");
extern "C" int func_00291710_impl(void* self, void* rider)
{
    int x;
    if (func_0011FE98(rider) == 4) {
        x = *(int*)((char*)self + 0x598C);
    } else {
        x = *(int*)((char*)rider + 0x438);
    }
    switch (x) {
    case 2: case 3: case 13:
        return 1;
    case 1:
        return 2;
    case 4:
        return 3;
    case 7: case 8: case 18:
        return 7;
    case 9:
        return 5;
    case 10:
        return 4;
    case 11:
        return 8;
    case -1: case 0: case 5: case 6: case 12: case 14: case 15: case 16: case 17: case 19:
        return 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002917B8);
#ifdef SKIP_ASM
extern "C" int func_002917B8(void* self, int a1)
{
    if (a1 > 3) {
        return 1;
    }
    return 0x10;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002917D0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);
extern "C" int func_00288A20(void* self, void* obj);
extern "C" int func_00288AE0(void* self);
extern "C" void func_002A9988(void* self, float a, float b);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_002917B8(void* self, int a1);
extern signed char D_00535C11[];

struct sSnd17D0Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd17D0E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd17D0Sub {
    char pad0[4];
    sSnd17D0Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd17D0Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd17D0E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd17D0Mgr {
    char pad0[0x1D8];
    sSnd17D0Sub sub;         // 0x1D8
};
struct sSnd17D0Sys {
    sSnd17D0Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd17D0Mgr** p118;      // 0x118
};
struct sSndKey8_17D0 {
    long v;
} __attribute__((packed));
extern sSndKey8_17D0 D_004A3688_17D0[] __asm__("D_004A3688");

// PORT: 64-bit long sound key
void func_002917D0_17D0(void* vself, void* obj) __asm__("func_002917D0");
void func_002917D0_17D0(void* vself, void* obj)
{
    sSnd17D0Sys* self = (sSnd17D0Sys*)vself;
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (!ok) {
        return;
    }
    int flag = 0;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        flag = func_00288AE0(self) == 0;
    }
    int a = func_002917B8(self, 0);
    sSnd17D0Mgr* m = self->mgr;
    sSnd17D0Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = 0;
    sSnd17D0Mgr* m3 = *self->p118;
    sSnd17D0Sub* s3 = &m3->sub;
    s3->vals[m3->sub.cur] = 0;
    s3->ch[m3->sub.cur].vol = (s3->vals[s3->cur] < 0x7F && s3->vals[s3->cur] < 0) ? 0 : (s3->vals[s3->cur] < 0x7F ? (unsigned char)s3->vals[s3->cur] : 0x7F);
    sSnd17D0Mgr** pp = self->p118;
    int r = (int)func_00287968(self, 6, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    {
        sSnd17D0Mgr* m2 = *self->p118;
        m2->sub.tgt[m2->sub.cur] = (char*)obj + 0x110;
    }
    {
        sSnd17D0Mgr* m2 = *self->p118;
        sSndKey8_17D0 k = D_004A3688_17D0[0];
        sSnd17D0Sub* s2 = &m2->sub;
        *(sSndKey8_17D0*)((char*)s2 + (m2->sub.cur << 3) + 0x40) = k;
    }
    {
        sSnd17D0Mgr* m2 = *self->p118;
        m2->sub.p60[m2->sub.cur] = (int)obj;
    }
    {
        sSnd17D0Mgr** pq = self->p118;
        int q = func_00288A20(self, obj);
        (*pq)->sub.p64[(*pq)->sub.cur] = q;
    }
    func_002A9988(&(*self->p118)->sub, 100.0f, -1.0f);
    (*self->p118)->sub.p7C[(*self->p118)->sub.cur] = 0;
    if (flag) {
        (*self->p118)->sub.p80[(*self->p118)->sub.cur] = 1;
        (*self->p118)->sub.p84[(*self->p118)->sub.cur] = *(int*)((char*)obj + 0x870);
    }
    func_002906B8(self);
}
#endif

INCLUDE_ASM("sound/soundsys", func_00291C88);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00292508);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);
extern "C" int func_00288A20(void* self, void* obj);
extern "C" int func_00288AE0(void* self);
extern "C" void func_002A9988(void* self, float a, float b);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_002917B8(void* self, int a1);
extern signed char D_00535C11[];

struct sSnd2508Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd2508E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd2508Sub {
    char pad0[4];
    sSnd2508Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd2508Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd2508E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd2508Mgr {
    char pad0[0x1D8];
    sSnd2508Sub sub;         // 0x1D8
};
struct sSnd2508Sys {
    sSnd2508Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd2508Mgr** p118;      // 0x118
};
struct sSndKey8_2508 {
    long v;
} __attribute__((packed));
extern sSndKey8_2508 D_004A36A0_2508[] __asm__("D_004A36A0");

// PORT: 64-bit long sound key
void func_00292508_2508(void* vself, void* obj, int n) __asm__("func_00292508");
void func_00292508_2508(void* vself, void* obj, int n)
{
    sSnd2508Sys* self = (sSnd2508Sys*)vself;
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (!ok) {
        return;
    }
    int flag = 0;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        flag = func_00288AE0(self) == 0;
    }
    int a = func_002917B8(self, n);
    int b = n * 8 + 3;
    sSnd2508Mgr* m = self->mgr;
    sSnd2508Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd2508Mgr* m3 = *self->p118;
    sSnd2508Sub* s3 = &m3->sub;
    s3->vals[m3->sub.cur] = 0;
    s3->ch[m3->sub.cur].vol = (s3->vals[s3->cur] < 0x7F && s3->vals[s3->cur] < 0) ? 0 : (s3->vals[s3->cur] < 0x7F ? (unsigned char)s3->vals[s3->cur] : 0x7F);
    sSnd2508Mgr** pp = self->p118;
    int r = (int)func_00287968(self, 6, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    {
        sSnd2508Mgr* m2 = *self->p118;
        m2->sub.tgt[m2->sub.cur] = (char*)obj + 0x110;
    }
    {
        sSnd2508Mgr* m2 = *self->p118;
        sSndKey8_2508 k = D_004A36A0_2508[0];
        sSnd2508Sub* s2 = &m2->sub;
        *(sSndKey8_2508*)((char*)s2 + (m2->sub.cur << 3) + 0x40) = k;
    }
    (*self->p118)->sub.p7C[(*self->p118)->sub.cur] = 0;
    {
        sSnd2508Mgr* m2 = *self->p118;
        m2->sub.p60[m2->sub.cur] = (int)obj;
    }
    {
        sSnd2508Mgr** pq = self->p118;
        int q = func_00288A20(self, obj);
        (*pq)->sub.p64[(*pq)->sub.cur] = q;
    }
    func_002A9988(&(*self->p118)->sub, 100.0f, -1.0f);
    if (flag) {
        (*self->p118)->sub.p80[(*self->p118)->sub.cur] = 1;
        (*self->p118)->sub.p84[(*self->p118)->sub.cur] = *(int*)((char*)obj + 0x870);
    }
    func_002906B8(self);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002929D8);
#ifdef SKIP_ASM
extern "C" void* func_0028B1D8();
extern "C" void func_00292A50(void* self, int id);
extern "C" void func_00292B48(void* self);

extern "C" void func_002929D8(void* self)
{
    func_00292B48(self);
    for (int i = 0; i < *(int*)((char*)func_0028B1D8() + 0x78); i++) {
        func_00292A50(self, *(int*)((char*)func_0028B1D8() + (i << 2) + 0x28));
    }
    *(int*)((char*)self + 0x5830) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00292A50);
#ifdef SKIP_ASM
int func_0011FE98(void*);
extern "C" int func_00291710(void* self, int id);
extern "C" void func_002917D0(void* self, int id);
extern "C" void func_00291C88(void* self, int id, int n);
extern "C" void func_00292508(void* self, int id, int n);

// PORT: id is a pointer passed as int (the unit declares func_00292A50(void*, int)).
extern "C" void func_00292A50(void* self, int id)
{
    int a = func_0011FE98((void*)id);
    int n = func_00291710(self, id);
    *(int*)((char*)id + 0x760) = a;
    *(int*)((char*)id + 0x764) = a;
    *(int*)((char*)id + 0x768) = n;
    *(int*)((char*)id + 0x76C) = n;
    func_002917D0(self, id);
    func_00291C88(self, id, n);
    func_00292508(self, id, n);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00292AE8);
#ifdef SKIP_ASM
struct sSndId292AE8 {
    long v;
} __attribute__((packed));
extern sSndId292AE8 D_004A36A8[];
extern "C" void func_002ADDE0(void* bank, long id);

struct sVE292AE8 { short delta; short index; void (*fn)(void*, int); };

struct sBank292AE8 {
    char pad0[0x8D8];
    sVE292AE8* vt;      // 0x8D8
};
struct sSys292AE8 {
    char pad0[0x1D8];
    sBank292AE8 bank;   // 0x1D8
};

// Notifies the sound bank, then (re)starts the default ambient stream.
// PORT: the 8-byte stream id is passed by value from an unaligned global (64-bit `long`).
extern "C" void func_00292AE8(char* self, int a1)
{
    sSys292AE8* sys = **(sSys292AE8***)(self + 0x118);
    sVE292AE8* vt = sys->bank.vt;
    sys = (sSys292AE8*)&sys->bank;
    vt[4].fn((char*)sys + vt[4].delta, a1);
    func_002ADDE0(&(**(sSys292AE8***)(self + 0x118))->bank, D_004A36A8[0].v);
}
#endif

INCLUDE_ASM("sound/soundsys", func_00292B48);

INCLUDE_ASM("sound/soundsys", func_00294170);

//100%
INCLUDE_ASM("sound/soundsys", func_00294678);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00294880(void* self, int i, int v);
extern "C" void func_0029FCC8(void* self, void* rider);
extern "C" void func_002A7408(void* self, int i);
extern "C" int func_00288AE0(void* self);
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");

struct sSsVt4678 { short delta; short index; int (*fn)(void*); };

extern "C" void func_00294678(void* self, char* rider)
{
    int s = *(int*)(*(char**)(rider + 0x788) + 0xAC);
    int ok = s == 1 || s == 3;
    if (!ok) {
        char* o = rider + 0x6C0;
        sSsVt4678* e = &(*(sSsVt4678**)o)[7];
        func_00294880(self, e->fn(o + e->delta), 1);
        return;
    }
    int idx = -1;
    {
        char* o = rider + 0x6C0;
        sSsVt4678* e = &(*(sSsVt4678**)o)[7];
        func_00294880(self, e->fn(o + e->delta), 0);
    }
    float x = *(float*)(*(char**)(rider + 0x788) + 0x98);
    func_0029FCC8(self, rider);
    if (func_00288AE0(self) != 0) {
        idx = 0;
    } else {
        int ok2 = *(int*)(rider + 0x874) != 0 && *(int*)(rider + 0x87C) != 0;
        if (ok2) {
            idx = *(int*)(rider + 0x870);
        }
    }
    if (func_00285D98_p(self, idx) == rider && x > 2.0f) {
        func_002A7408(self, idx);
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_002947B0);

//100%
INCLUDE_ASM("sound/soundsys", func_00294880);
#ifdef SKIP_ASM
extern "C" void func_00294880(void* self, int i, int v)
{
    if (i < 6) {
        *(int*)((char*)self + (i << 2) + 0x59e8) = v;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002948A0);
#ifdef SKIP_ASM
extern "C" void func_002948A0(void* self)
{
    int i;
    for (i = 5; i >= 0; i--) {
        *(int*)((char*)self + (i << 2) + 0x59e8) = 0;
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_002948D0);

//100%
INCLUDE_ASM("sound/soundsys", func_00294F48);
#ifdef SKIP_ASM
struct sSndVEntry294F48 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" int func_00294F48(void* self)
{
    sSndVEntry294F48* vt = *(sSndVEntry294F48**)((char*)self + 0xC);
    return vt[1].fn((char*)self + vt[1].delta, 0, 0);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00294F78);
#ifdef SKIP_ASM
struct sVEnt_294F78 { short delta; short index; int (*fn)(void*, int, int); };

extern "C" void func_00294F78(void* self, int cue)
{
    int id = -1;
    switch (cue) {
    case 5: case 6:
        id = -1;
        break;
    case 7:
        id = 0x10;
        break;
    case 8:
        id = 0x11;
        break;
    case 0: case 9:
        id = 3;
        break;
    case 1: case 10:
        id = 4;
        break;
    case 2: case 11:
        id = 2;
        break;
    case 3: case 12:
        id = 1;
        break;
    case 4: case 13:
        id = 0xD;
        break;
    case 14:
        id = 0x12;
        break;
    case 15:
        id = 7;
        break;
    }
    if (id != -1) {
        sVEnt_294F78* vt = *(sVEnt_294F78**)((char*)self + 0xC);
        vt[1].fn((char*)self + vt[1].delta, 0, id);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00295028);
#ifdef SKIP_ASM
extern "C" void* func_002AD550(void* self, int idx, int a2);

struct sSnd5028Ring {
    int cap;
    int* data;
    int head;
    int tail;
};
struct sSnd5028Sys {
    char pad0[0x118];
    char** mgr;                 // 0x118
    char pad11C[0x597C - 0x11C];
    sSnd5028Ring ring;          // 0x597C
};

static inline int ring5028Count(sSnd5028Sys* s)
{
    return (s->ring.head - s->ring.tail + s->ring.cap) % s->ring.cap;
}
static inline int ring5028Empty(sSnd5028Sys* s)
{
    return s->ring.head == s->ring.tail;
}
static inline int ring5028Get(sSnd5028Sys* s, int i)
{
    if (ring5028Empty(s) || i >= ring5028Count(s)) return -1;
    sSnd5028Ring* r = &s->ring;
    return r->data[(s->ring.tail + i) % s->ring.cap];
}

extern "C" int func_00295028(void* vself, int a, int b)
{
    sSnd5028Sys* self = (sSnd5028Sys*)vself;
    int n = ring5028Count(self);
    for (int i = 0; i < n; i += 5) {
        int x = ring5028Get(self, i);
        int y = ring5028Get(self, i + 4);
        if (a == x && b == y) {
            int v = ring5028Get(self, i + 1);
            if (v != 0 && func_002AD550(*self->mgr + 0x1D8, v, 1) == 0) continue;
            return 1;
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("sound/soundsys", func_00295208);

//100%
INCLUDE_ASM("sound/soundsys", func_00295628);
#ifdef SKIP_ASM
static inline int ring5628Full(sSnd5028Sys* s)
{
    return (s->ring.head + 1) % s->ring.cap == s->ring.tail;
}
static inline int ring5628Pop(sSnd5028Sys* s)
{
    sSnd5028Ring* r = &s->ring;
    if (ring5028Empty(s)) return -1;
    int v = r->data[r->tail];
    if (++s->ring.tail >= s->ring.cap) s->ring.tail = 0;
    return v;
}
static inline void ring5628Push(sSnd5028Sys* s, int v)
{
    sSnd5028Ring* r = &s->ring;
    if (ring5628Full(s)) return;
    r->data[r->head] = v;
    if (++s->ring.head >= s->ring.cap) s->ring.head = 0;
}

// PORT: the event pointer is stored in an int ring slot.
extern "C" void func_00295628(void* vself, void* evt, int h, int t, int a, int idx)
{
    sSnd5028Sys* self = (sSnd5028Sys*)vself;
    if (ring5628Full(self)) {
        ring5628Pop(self);
        func_002AD5F0(*self->mgr + 0x1D8, ring5628Pop(self), 1, 0.0f);
        ring5628Pop(self);
        ring5628Pop(self);
        ring5628Pop(self);
    }
    ring5628Push(self, (int)evt);
    ring5628Push(self, h);
    ring5628Push(self, t);
    ring5628Push(self, a);
    ring5628Push(self, idx);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00295950);
#ifdef SKIP_ASM
static inline int ring5950Full(sSnd5028Sys* s)
{
    return (s->ring.head + 1) % s->ring.cap == s->ring.tail;
}
static inline int ring5950Pop(sSnd5028Sys* s)
{
    sSnd5028Ring* r = &s->ring;
    if (ring5028Empty(s)) return -1;
    int v = r->data[r->tail];
    if (++s->ring.tail >= s->ring.cap) s->ring.tail = 0;
    return v;
}
static inline void ring5950Push(sSnd5028Sys* s, int v)
{
    sSnd5028Ring* r = &s->ring;
    if (ring5950Full(s)) return;
    r->data[r->head] = v;
    if (++s->ring.head >= s->ring.cap) s->ring.head = 0;
}

extern "C" void func_00295950(void* vself, int evt, int h, int idx)
{
    sSnd5028Sys* self = (sSnd5028Sys*)vself;
    int n = ring5028Count(self);
    for (int i = 0; i < n; i++) {
        int e = ring5950Pop(self);
        int v1 = ring5950Pop(self);
        int v2 = ring5950Pop(self);
        int v3 = ring5950Pop(self);
        int v4 = ring5950Pop(self);
        if (evt == e && idx == v4) v2 = h;
        ring5950Push(self, e);
        ring5950Push(self, v1);
        ring5950Push(self, v2);
        ring5950Push(self, v3);
        ring5950Push(self, v4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00296088);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00288B40(void* self, int which, float f);
// func_00295028 takes the event pointer here (the unit declares (void*, int, int) later).
int func_00295028_p(void* self, void* evt, int idx) __asm__("func_00295028");
extern "C" int func_002B5F60(void* mgr, void* evt, int id, void* rider, int vol);
extern "C" void func_00295628(void* self, void* evt, int h, int t, int a, int idx);
extern void* D_004A52D4;

struct sSsVt6088 { short delta; short index; int (*fn)(void*); };

extern "C" void func_00296088(void* self, char* rider, char* evt, int idx)
{
    if (*(void**)(evt + 0x8C) == 0) return;
    char* obj = rider + 0x6C0;
    sSsVt6088* e = &(*(sSsVt6088**)obj)[5];
    if (func_00288B40(self, e->fn(obj + e->delta), 100.0f) < 0) return;
    if (func_00295028_p(self, evt, idx) != 0) return;
    sSndVEntryVec* vt = *(sSndVEntryVec**)obj;
    sSndVec4* p = vt[2].fn(obj + vt[2].delta);
    int v = (int)func_00290C10(0, sndVu0Length(*p));
    if (v > 127) v = 127;
    if (v < 0) v = 0;
    int* tbl = *(int**)(*(char**)(evt + 0x8C) + 0x10);
    if (idx >= tbl[0]) idx = 0;
    int* ids = tbl + 2;
    int* q = ids;
    if (ids[idx] != 0) q = &ids[idx];
    int r = func_002B5F60(D_004A52D4, evt, *q, rider, v);
    if (r < 0) return;
    func_00295628(self, evt, r, *(int*)(**(char***)((char*)self + 0x118) + 0x260) + 1000, 0, idx);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002961F0);
#ifdef SKIP_ASM
extern "C" int func_00288AE0(void* self);
extern "C" void func_002A73D8(void* self, int a1, int i);
extern "C" void func_002A7438(void* self, int i);
extern "C" void func_0028F108(void* self, void* rider);
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");

// PORT: PS2-only inline asm (float absolute value).
static inline float absf_961F0(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_002961F0(void* self, char* rider, float v)
{
    int idx = -1;
    if (func_00288AE0(self) != 0) {
        idx = 0;
    } else {
        int ok = *(int*)(rider + 0x874) != 0 && *(int*)(rider + 0x87C) != 0;
        if (ok) {
            idx = *(int*)(rider + 0x870);
        }
    }
    if (func_00285D98_p(self, idx) != rider) {
        return;
    }
    float a = absf_961F0(v);
    if (a <= 0.0f) {
        func_002A7438(self, idx);
    } else if (a < 0.25f) {
        func_002A73D8(self, 0, idx);
    } else if (a < 0.65f) {
        func_002A73D8(self, 1, idx);
    } else {
        func_002A73D8(self, 2, idx);
    }
    func_0028F108(self, rider);
}
#endif

INCLUDE_ASM("sound/soundsys", func_00296310);

INCLUDE_ASM("sound/soundsys", func_00296868);

//100%
INCLUDE_ASM("sound/soundsys", func_00296E20);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_00296E20(void* self, void* obj)
{
    if (*(int*)((char*)obj + 0x774) >= 0) {
        func_002AD5F0((char*)**(void***)((char*)func_0028B180() + 0x118) + 0x1D8, *(int*)((char*)obj + 0x774), 1, 0.75f);
        *(int*)((char*)obj + 0x774) = -1;
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_00296E80);

//100%
INCLUDE_ASM("sound/soundsys", func_00297438);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_00297438(void* self, void* obj)
{
    if (*(int*)((char*)obj + 0x778) >= 0) {
        func_002AD5F0((char*)**(void***)((char*)func_0028B180() + 0x118) + 0x1D8, *(int*)((char*)obj + 0x778), 1, 0.75f);
        *(int*)((char*)obj + 0x778) = -1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002974A0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd74A0Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd74A0E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd74A0Sub {
    char pad0[4];
    sSnd74A0Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd74A0Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd74A0E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd74A0Mgr {
    char pad0[0x1D8];
    sSnd74A0Sub sub;         // 0x1D8
};
struct sSnd74A0Sys {
    sSnd74A0Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd74A0Mgr** p118;      // 0x118
};

extern "C" int func_00288A20(void* self, void* obj);

#define SND_74A0_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_74A0_MAX(a, b) ((a) > (b) ? (a) : (b))

extern "C" void func_002A9988(void* self, float a, float b);
extern "C" int func_00288940(void* self, sSndVec4* pos);

static inline void snd74A0AddVoice(void* vself, int a, int b, int type)
{
    sSnd74A0Sys* self = (sSnd74A0Sys*)vself;
    sSnd74A0Mgr* m = self->mgr;
    sSnd74A0Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd74A0Mgr* m2 = *self->p118;
    sSnd74A0Sub* s2 = &m2->sub;
    s2->vals[m2->sub.cur] = 0x7F;
    s2->ch[m2->sub.cur].vol = SND_74A0_MAX(0, SND_74A0_MIN(s2->vals[s2->cur], 0x7F));
    sSnd74A0Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
}


extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_00295028(void* self, int a, int b);
extern "C" void func_00295628(void* self, void* evt, int h, int t, int a, int idx);

extern "C" void func_002974A0(void* self, char* evt, int n)
{
    if (n == 0) return;
    if (n == 0x66 && *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0)) == 0) return;
    if (*(int*)((char*)self + 0x62A8) >= 0) return;
    if (func_00295028(self, (int)evt, 0) != 0) return;
    int pri = 0x50;
    sSndVec4 pos = *(sSndVec4*)(evt + 0x40);
    int type = 2;
    int b;
    if (n < 100) {
        b = n;
    } else if (n < 150) {
        b = n - 100;
        type = 8;
    } else if (n < 200) {
        b = n - 150;
        type = 9;
    } else {
        b = n - 200;
        type = 4;
    }
    snd74A0AddVoice(self, type, b, 5);
    sSnd74A0Mgr** pp;
    int r;
    sSnd74A0Sys* sys = (sSnd74A0Sys*)self;
    sSnd74A0Mgr* m3 = *sys->p118;
    m3->sub.tgt[m3->sub.cur] = &pos;
    sSnd74A0Mgr* m4 = *sys->p118;
    m4->sub.p34[m4->sub.cur] = 1;
    func_002A9988(&(*sys->p118)->sub, 300.0f, -1.0f);
    pp = sys->p118;
    r = func_00288940(sys, &pos);
    (*pp)->sub.p64[(*pp)->sub.cur] = r;
    sSnd74A0Mgr* m5 = *sys->p118;
    m5->sub.p78[m5->sub.cur] = pri;
    int h = func_002906B8(self);
    func_00295628(self, evt, h, *(int*)(**(char***)((char*)self + 0x118) + 0x260) + 50, 0, 0);
}
#endif

INCLUDE_ASM("sound/soundsys", func_00297950);

//100%
INCLUDE_ASM("sound/soundsys", func_00297EB8);
#ifdef SKIP_ASM
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_00297EB8(void* self, int a1, int a2)
{
    for (int i = 0; i < 30; i++) {
        if (*(int*)((char*)self + i * 0x30 + 0x5A00) == 1 &&
            *(int*)((char*)self + i * 0x30 + 0x5A04) == a1 &&
            *(int*)((char*)self + i * 0x30 + 0x5A20) == a2) {
            func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8,
                          *(int*)((char*)self + i * 0x30 + 0x5A24), 1, 0.0f);
            *(int*)((char*)self + i * 0x30 + 0x5A00) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00297F70);
#ifdef SKIP_ASM
extern "C" void func_00297F70(void* self)
{
    int i;
    for (i = 29; i >= 0; i--) {
        *(int*)((char*)self + i * 0x30 + 0x5a00) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00297FA0);
#ifdef SKIP_ASM
struct sSsVec4FA0 {
    float x, y, z, w;
    sSsVec4FA0() {}
} __attribute__((aligned(16)));

struct sSsVtFA0 { short delta; short index; char* (*fn)(void*, ...); };

extern "C" void func_00297FA0(void* self)
{
    for (int i = 0; i < 30; i++) {
        char* s = (char*)self + i * 0x30;
        if (*(int*)(s + 0x5A00) != 1) continue;
        char* inner = *(char**)(*(char**)(s + 0x5A04) + 0xC);
        if (inner == 0) {
            func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8, *(int*)(s + 0x5A24), 1, 0.0f);
            *(int*)(s + 0x5A00) = 0;
        } else if (*(int*)(s + 0x5A08) == -1) {
            sSsVtFA0* vt = *(sSsVtFA0**)(inner + 0xC);
            sSsVec4FA0 p;
            p = *(sSsVec4FA0*)(vt[24].fn(inner + vt[24].delta) + 0x30);
            *(sSsVec4FA0*)(s + 0x5A10) = p;
        } else {
            sSsVtFA0* vt = *(sSsVtFA0**)(inner + 0xC);
            if (vt[26].fn(inner + vt[26].delta) != 0) {
                char* o = *(char**)(*(char**)(s + 0x5A04) + 0xC);
                sSsVtFA0* vt2 = *(sSsVtFA0**)(o + 0xC);
                sSsVec4FA0 p;
                p = *(sSsVec4FA0*)(vt2[29].fn(o + vt2[29].delta, *(int*)(s + 0x5A08)) + 0x30);
                *(sSsVec4FA0*)(s + 0x5A10) = p;
            } else {
                sSsVec4FA0 p;
                p = *(sSsVec4FA0*)(*(char**)(s + 0x5A04) + 0x40);
                *(sSsVec4FA0*)(s + 0x5A10) = p;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002980B0);
#ifdef SKIP_ASM
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_002980B0(void* self)
{
    int i;
    for (i = 0; i < 30; i++) {
        if (*(int*)((char*)self + i * 0x30 + 0x5A00) == 1) {
            func_002AD5F0((char*)**(void***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + i * 0x30 + 0x5A24), 1, 0.0f);
            *(int*)((char*)self + i * 0x30 + 0x5A00) = 0;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00298138);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd8138Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd8138E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd8138Sub {
    char pad0[4];
    sSnd8138Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd8138Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd8138E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd8138Mgr {
    char pad0[0x1D8];
    sSnd8138Sub sub;         // 0x1D8
};
struct sSnd8138Sys {
    sSnd8138Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd8138Mgr** p118;      // 0x118
};

extern "C" int func_00295028(void* self, int a, int b);
extern "C" void func_00295628(void* self, void* evt, int h, int t, int a, int idx);
extern "C" int func_00288A20(void* self, void* obj);

static inline bool snd8138Active(void* o)
{
    return *(int*)((char*)o + 0x874) && *(int*)((char*)o + 0x87C);
}

static inline int snd8138AddVoice(void* vself, void* obj, int a, int b, int type)
{
    sSnd8138Sys* self = (sSnd8138Sys*)vself;
    sSnd8138Mgr* m = self->mgr;
    sSnd8138Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd8138Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    sSnd8138Mgr* m2 = *self->p118;
    m2->sub.tgt[m2->sub.cur] = (char*)obj + 0x110;
    pp = self->p118;
    r = func_00288A20(self, obj);
    (*pp)->sub.p64[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_00298138(void* self, void* obj, void* obj2)
{
    if (!snd8138Active(obj) && !snd8138Active(obj2)) {
        return;
    }
    if (func_00295028(self, 5, 0) != 0) {
        return;
    }
    int h = snd8138AddVoice(self, obj, 0, 0x5A, 5);
    func_00295628(self, (void*)5, h, *(int*)(**(char***)((char*)self + 0x118) + 0x260) + 50, 0, 0);
}
#endif

INCLUDE_ASM("sound/soundsys", func_00298488);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002989A8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd89A8Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd89A8E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd89A8Sub {
    char pad0[4];
    sSnd89A8Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd89A8Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd89A8E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd89A8Mgr {
    char pad0[0x1D8];
    sSnd89A8Sub sub;         // 0x1D8
};
struct sSnd89A8Sys {
    sSnd89A8Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd89A8Mgr** p118;      // 0x118
};

extern "C" int func_00295028(void* self, int a, int b);
extern "C" void func_00295628(void* self, void* evt, int h, int t, int a, int idx);
extern "C" int func_00288A20(void* self, void* obj);
extern "C" void func_002A9988(void* self, float a, float b);

static inline int snd89A8AddVoice(void* vself, void* obj, int a, int b, int type)
{
    sSnd89A8Sys* self = (sSnd89A8Sys*)vself;
    sSnd89A8Mgr* m = self->mgr;
    sSnd89A8Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd89A8Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    func_002A9988(&(*self->p118)->sub, 100.0f, -1.0f);
    pp = self->p118;
    r = func_00288A20(self, obj);
    (*pp)->sub.p64[(*pp)->sub.cur] = r;
    sSnd89A8Mgr* m2 = *self->p118;
    m2->sub.tgt[m2->sub.cur] = (char*)obj + 0x110;
    return func_002906B8(self);
}

extern "C" void func_002989A8(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (!ok) {
        return;
    }
    if (func_00295028(self, 6, 0) != 0) {
        return;
    }
    int h = snd89A8AddVoice(self, obj, 0, 0x36, 5);
    func_00295628(self, (void*)6, h, *(int*)(**(char***)((char*)self + 0x118) + 0x260) + 50, 0, 0);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00298D00);
#ifdef SKIP_ASM
struct sSndKey8 {
    long v;
} __attribute__((packed));
extern sSndKey8 D_004A3678[];
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" void func_002ADCA0(void*, int, long, int, int, int, int, int);

// PORT: 64-bit long sound key
extern "C" void func_00298D00(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        char* p = **(char***)((char*)self + 0x118) + 0x1D8;
        sSndKey8* key = D_004A3678;
        int r = (int)func_00287968(self, 9, 0);
        func_002ADCA0(p, 0xFA, key->v, r, 0, 0x72, 0x7F, 0);
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_00298D90);

//100%
INCLUDE_ASM("sound/soundsys", func_002992D8);
#ifdef SKIP_ASM
extern "C" int func_00288AE0(void* self);
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_002992D8(void* self, void* obj)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        int n = --*(int*)((char*)self + 0x59E4);
        if (n <= 0) {
            if (n == 0) {
                func_002AD5F0((char*)**(void***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + 0x59E0), 1, 0.0f);
            }
            *(int*)((char*)self + 0x59E4) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_00299368);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd9368Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd9368E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd9368Sub {
    char pad0[4];
    sSnd9368Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd9368Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd9368E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd9368Mgr {
    char pad0[0x1D8];
    sSnd9368Sub sub;         // 0x1D8
};
struct sSnd9368Sys {
    sSnd9368Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd9368Mgr** p118;      // 0x118
};

struct sSndId299368 {
    long v;
} __attribute__((packed));
extern sSndId299368 D_004A36A8_9368[] __asm__("D_004A36A8");
extern "C" void func_002ADDE0(void* bank, long id);
extern "C" int func_00288AE0(void* self);

static inline int IsReady299368(char* obj)
{
    return *(int*)(obj + 0x874) != 0 && *(int*)(obj + 0x87C) != 0;
}

static inline void AddVoice299368(sSnd9368Sys* self, int a, int bb, int type)
{
    sSnd9368Mgr* m = self->mgr;
    sSnd9368Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = bb;
    sSnd9368Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
}

// Starts the "crowd cheer" voice for the object if the bank is ready and nothing else is playing.
// PORT: the 8-byte stream id is passed by value from an unaligned global (64-bit `long`).
extern "C" void func_00299368(sSnd9368Sys* self, char* obj)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    if (!IsReady299368(obj)) {
        return;
    }
    func_002ADDE0(&(*self->p118)->sub, D_004A36A8_9368[0].v);
    AddVoice299368(self, 0, 0x6C, 9);
    func_002906B8(self);
}
#endif

INCLUDE_ASM("sound/soundsys", func_00299638);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002997B8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd97B8Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd97B8E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd97B8Sub {
    char pad0[4];
    sSnd97B8Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd97B8Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd97B8E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd97B8Mgr {
    char pad0[0x1D8];
    sSnd97B8Sub sub;         // 0x1D8
};
struct sSnd97B8Sys {
    sSnd97B8Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd97B8Mgr** p118;      // 0x118
};

extern "C" int func_00288A20(void* self, void* obj);

#define SND_97B8_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_97B8_MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int snd97B8AddVoice(void* vself, int a, int b, int type)
{
    sSnd97B8Sys* self = (sSnd97B8Sys*)vself;
    sSnd97B8Mgr* m = self->mgr;
    sSnd97B8Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd97B8Mgr* m2 = *self->p118;
    sSnd97B8Sub* s2 = &m2->sub;
    s2->vals[m2->sub.cur] = 0x7F;
    s2->ch[m2->sub.cur].vol = SND_97B8_MAX(0, SND_97B8_MIN(s2->vals[s2->cur], 0x7F));
    sSnd97B8Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);
extern "C" void* func_0028B1C8();
extern "C" int func_00270280(void* p);
extern int D_004A2A50;

extern "C" void func_002997B8(void* self, void* obj)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (!ok) {
        return;
    }
    int c = 1;
    int pos = *(float*)((char*)obj + 0x470) >= 0.0f;
    if (pos) c = 0;
    if ((D_004A2A50 & 1) || func_00270280(*(void**)((char*)func_0028B1C8() + 0x28)) != 0) c = 0;
    if (*(int*)((char*)func_0028B1C8() + 0x214) != 4) c = 0;
    if (c) {
        snd97B8AddVoice(self, 0, 0x69, 9);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00299B70);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd9B70Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd9B70E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd9B70Sub {
    char pad0[4];
    sSnd9B70Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd9B70Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd9B70E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd9B70Mgr {
    char pad0[0x1D8];
    sSnd9B70Sub sub;         // 0x1D8
};
struct sSnd9B70Sys {
    sSnd9B70Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd9B70Mgr** p118;      // 0x118
};

static inline int snd9B70AddVoice(void* vself, int a, int b, int type)
{
    sSnd9B70Sys* self = (sSnd9B70Sys*)vself;
    sSnd9B70Mgr* m = self->mgr;
    sSnd9B70Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd9B70Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);

extern "C" void func_00299B70(void* self, void* obj)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        snd9B70AddVoice(self, 0, 0x6C, 9);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_00299E28);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSnd9E28Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd9E28E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd9E28Sub {
    char pad0[4];
    sSnd9E28Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd9E28Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd9E28E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd9E28Mgr {
    char pad0[0x1D8];
    sSnd9E28Sub sub;         // 0x1D8
};
struct sSnd9E28Sys {
    sSnd9E28Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd9E28Mgr** p118;      // 0x118
};

static inline int snd9E28AddVoice(void* vself, int a, int b, int type)
{
    sSnd9E28Sys* self = (sSnd9E28Sys*)vself;
    sSnd9E28Mgr* m = self->mgr;
    sSnd9E28Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSnd9E28Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C10[];
extern "C" int func_002A4290(void* self);
extern "C" void* func_0028B1C8();
extern "C" void* func_0028B1D8();
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
extern "C" int func_00295028(void* self, int a, int b);
extern "C" int func_00288AE0(void* self);
extern "C" void func_00295628(void* self, void* evt, int h, int t, int a, int idx);
extern "C" void func_002A0560(void* self, void* a, void* b);

extern "C" void func_00299E28(void* self, void* obj, void* a, void* b, int lim, int n)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C10[0] != 0 && func_002A4290(self) == 0) {
        return;
    }
    if (*(int*)((char*)func_0028B1C8() + 0x214) != 4) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (!ok && func_00285D98_p(self, -1) != obj) {
        return;
    }
    int cnt = *(int*)((char*)func_0028B1D8() + 0x7C);
    if (cnt + *(int*)((char*)func_0028B1D8() + 0x80) < 2) {
        return;
    }
    if (n == 0 && func_00295028(self, 1, 0) == 0 && func_00288AE0(self) == 0) {
        int h = snd9E28AddVoice(self, 0, 0x6D, 9);
        func_00295628(self, (void*)1, h, *(int*)(**(char***)((char*)self + 0x118) + 0x260) + 200, 0, 0);
    }
    if (n < lim) {
        if (a != 0) {
            func_002A0560(self, obj, a);
        }
    } else {
        if (b != 0) {
            func_002A0560(self, b, obj);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029A220);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndA220Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndA220E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndA220Sub {
    char pad0[4];
    sSndA220Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndA220Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndA220E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndA220Mgr {
    char pad0[0x1D8];
    sSndA220Sub sub;         // 0x1D8
};
struct sSndA220Sys {
    sSndA220Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndA220Mgr** p118;      // 0x118
};

static inline int sndA220AddVoice(void* vself, int a, int b, int type)
{
    sSndA220Sys* self = (sSndA220Sys*)vself;
    sSndA220Mgr* m = self->mgr;
    sSndA220Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndA220Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);
extern "C" void func_00296E20(void* self, void* obj);
extern "C" void func_00297438(void* self, void* obj);
extern "C" void func_002992D8(void* self, void* obj);
extern "C" void func_0028F108(void* self, void* rider);
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");

extern "C" void func_0029A220(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok && func_00288AE0(self) == 0) {
        sndA220AddVoice(self, 0, 0x7B, 5);
    }
    func_00296E20(self, obj);
    func_00297438(self, obj);
    if (*(int*)((char*)self + 0x59E4) > 0) {
        func_002992D8(self, obj);
    }
    if (obj == func_00285D98_p(self, -1)) {
        func_0028F108(self, obj);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029A530);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndA530Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndA530E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndA530Sub {
    char pad0[4];
    sSndA530Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndA530Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndA530E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndA530Mgr {
    char pad0[0x1D8];
    sSndA530Sub sub;         // 0x1D8
};
struct sSndA530Sys {
    sSndA530Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndA530Mgr** p118;      // 0x118
};

static inline int sndA530AddVoice(void* vself, int a, int b, int type)
{
    sSndA530Sys* self = (sSndA530Sys*)vself;
    sSndA530Mgr* m = self->mgr;
    sSndA530Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndA530Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_0029A530(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        sndA530AddVoice(self, 0, 0x77, 9);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029A7D8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndA7D8Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndA7D8E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndA7D8Sub {
    char pad0[4];
    sSndA7D8Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndA7D8Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndA7D8E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndA7D8Mgr {
    char pad0[0x1D8];
    sSndA7D8Sub sub;         // 0x1D8
};
struct sSndA7D8Sys {
    sSndA7D8Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndA7D8Mgr** p118;      // 0x118
};

static inline int sndA7D8AddVoice(void* vself, int a, int b, int type)
{
    sSndA7D8Sys* self = (sSndA7D8Sys*)vself;
    sSndA7D8Mgr* m = self->mgr;
    sSndA7D8Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndA7D8Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);
extern "C" void func_003B58A0();
extern "C" int func_003B8AB8(int id);
extern "C" void func_003B58D8();
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_0029A7D8(void* self, void* obj, int n)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        int v = n % 100;
        if (v < *(int*)((char*)self + 0x5FA8)) {
            func_003B58A0();
            int busy = func_003B8AB8(*(int*)((char*)self + 0x5FAC)) != 0;
            func_003B58D8();
            if (!busy) {
                func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + 0x5FAC), 1, 0.0f);
            }
            *(int*)((char*)self + 0x5FAC) = sndA7D8AddVoice(self, 0, 0x4D, 9);
        }
        *(int*)((char*)self + 0x5FA8) = v;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029AB08);
#ifdef SKIP_ASM
extern "C" void func_0029AB08(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        *(short*)((char*)self + (*(int*)((char*)obj + 0x870) << 1) + 0x5FE8) = 0x1000;
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_0029AB40);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029B0E0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndB0E0Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndB0E0E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndB0E0Sub {
    char pad0[4];
    sSndB0E0Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndB0E0Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndB0E0E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndB0E0Mgr {
    char pad0[0x1D8];
    sSndB0E0Sub sub;         // 0x1D8
};
struct sSndB0E0Sys {
    sSndB0E0Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndB0E0Mgr** p118;      // 0x118
};

static inline int sndB0E0AddVoice(void* vself, int a, int b, int type)
{
    sSndB0E0Sys* self = (sSndB0E0Sys*)vself;
    sSndB0E0Mgr* m = self->mgr;
    sSndB0E0Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndB0E0Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_0029B0E0(void* self, void* obj)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        if (*(int*)((char*)self + 0x5FDC) != -1) {
            func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + 0x5FDC), 1, 0.0f);
        }
        *(int*)((char*)self + 0x5FDC) = sndB0E0AddVoice(self, 0, 0x66, 9);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029B3C0);
#ifdef SKIP_ASM
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_0029B3C0(void* self, void* obj)
{
    if (obj != 0) {
        int ok = 0;
        if (*(int*)((char*)obj + 0x874) != 0) {
            ok = *(int*)((char*)obj + 0x87C) != 0;
        }
        if (!ok) {
            return;
        }
    }
    if (*(int*)((char*)self + 0x5FDC) != -1) {
        func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + 0x5FDC), 1, 0.0f);
        *(int*)((char*)self + 0x5FDC) = -1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029B430);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndB430Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndB430E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndB430Sub {
    char pad0[4];
    sSndB430Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndB430Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndB430E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndB430Mgr {
    char pad0[0x1D8];
    sSndB430Sub sub;         // 0x1D8
};
struct sSndB430Sys {
    sSndB430Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndB430Mgr** p118;      // 0x118
};

static inline int sndB430AddVoice(void* vself, int a, int b, int type)
{
    sSndB430Sys* self = (sSndB430Sys*)vself;
    sSndB430Mgr* m = self->mgr;
    sSndB430Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndB430Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);
extern "C" void func_002A3DE0(void* self, void* obj, int ev);

extern "C" void func_0029B430(void* self, void* obj, int a, int b)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        sndB430AddVoice(self, 0, 0x67, 9);
        int t = b + a;
        if (b < 4) {
            if (t >= 4) {
                if (t < 9) {
                    func_002A3DE0(self, obj, 1);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029B738);
#ifdef SKIP_ASM
extern "C" int func_00288AE0(void* self);
extern "C" int func_00285D98(void* self, int which);
extern "C" void* func_0028B1C8();
extern "C" void func_002A3DE0(void* self, void* obj, int ev);

extern "C" void func_0029B738(void* self)
{
    if (func_00288AE0(self) != 0) return;
    // PORT: func_00285D98 returns a rider pointer as int
    char* r = (char*)func_00285D98(self, -1);
    if (*(int*)(r + 0x870) == *(int*)((char*)self + 0x5820)) {
        if (*(int*)(r + 0x2F4) == 10 && *(int*)((char*)self + 0x581C) != *(int*)(r + 0x2F4) &&
            *(int*)((char*)func_0028B1C8() + 0x214) == 4) {
            func_002A3DE0(self, r, 2);
        }
    } else {
        *(int*)((char*)self + 0x5820) = *(int*)(r + 0x870);
    }
    *(int*)((char*)self + 0x581C) = *(int*)(r + 0x2F4);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029B7E0);
#ifdef SKIP_ASM
extern "C" void func_002A3DE0(void* self, void* obj, int ev);

extern "C" void func_0029B7E0(void* self, void* obj)
{
    int ok = 0;
    if (*(int*)((char*)obj + 0x874) != 0) {
        ok = *(int*)((char*)obj + 0x87C) != 0;
    }
    if (ok) {
        func_002A3DE0(self, obj, 8);
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_0029B818);

//100%
INCLUDE_ASM("sound/soundsys", func_0029B960__FPv);
#ifdef SKIP_ASM
void func_0029B960(void* self)
{
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029B968);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndB968Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndB968E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndB968Sub {
    char pad0[4];
    sSndB968Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndB968Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndB968E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndB968Mgr {
    char pad0[0x1D8];
    sSndB968Sub sub;         // 0x1D8
};
struct sSndB968Sys {
    sSndB968Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndB968Mgr** p118;      // 0x118
};

extern "C" int func_00288A20(void* self, void* obj);

#define SND_B968_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_B968_MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int sndB968AddVoice(void* vself, void* obj, int a, int b, int type)
{
    sSndB968Sys* self = (sSndB968Sys*)vself;
    sSndB968Mgr* m = self->mgr;
    sSndB968Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndB968Mgr* m2 = *self->p118;
    sSndB968Sub* s2 = &m2->sub;
    s2->vals[m2->sub.cur] = 0x7F;
    s2->ch[m2->sub.cur].vol = SND_B968_MAX(0, SND_B968_MIN(s2->vals[s2->cur], 0x7F));
    sSndB968Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    sSndB968Mgr* m3 = *self->p118;
    m3->sub.tgt[m3->sub.cur] = (char*)obj + 0x110;
    pp = self->p118;
    r = func_00288A20(self, obj);
    (*pp)->sub.p64[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_0029B968(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        sndB968AddVoice(self, obj, 0, 0x50, 5);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029BCF8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndBCF8Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndBCF8E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndBCF8Sub {
    char pad0[4];
    sSndBCF8Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndBCF8Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndBCF8E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndBCF8Mgr {
    char pad0[0x1D8];
    sSndBCF8Sub sub;         // 0x1D8
};
struct sSndBCF8Sys {
    sSndBCF8Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndBCF8Mgr** p118;      // 0x118
};

extern "C" int func_00288A20(void* self, void* obj);

#define SND_BCF8_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_BCF8_MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int sndBCF8AddVoice(void* vself, void* obj, int a, int b, int type)
{
    sSndBCF8Sys* self = (sSndBCF8Sys*)vself;
    sSndBCF8Mgr* m = self->mgr;
    sSndBCF8Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndBCF8Mgr* m2 = *self->p118;
    sSndBCF8Sub* s2 = &m2->sub;
    s2->vals[m2->sub.cur] = 0x7F;
    s2->ch[m2->sub.cur].vol = SND_BCF8_MAX(0, SND_BCF8_MIN(s2->vals[s2->cur], 0x7F));
    sSndBCF8Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    sSndBCF8Mgr* m3 = *self->p118;
    m3->sub.tgt[m3->sub.cur] = (char*)obj + 0x110;
    pp = self->p118;
    r = func_00288A20(self, obj);
    (*pp)->sub.p64[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_0029BCF8(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        sndBCF8AddVoice(self, obj, 0, 0x51, 5);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029C088);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndC088Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndC088E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndC088Sub {
    char pad0[4];
    sSndC088Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndC088Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndC088E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndC088Mgr {
    char pad0[0x1D8];
    sSndC088Sub sub;         // 0x1D8
};
struct sSndC088Sys {
    sSndC088Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndC088Mgr** p118;      // 0x118
};

extern "C" int func_00288A20(void* self, void* obj);

#define SND_C088_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_C088_MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int sndC088AddVoice(void* vself, void* obj, int a, int b, int type)
{
    sSndC088Sys* self = (sSndC088Sys*)vself;
    sSndC088Mgr* m = self->mgr;
    sSndC088Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndC088Mgr* m2 = *self->p118;
    sSndC088Sub* s2 = &m2->sub;
    s2->vals[m2->sub.cur] = 0x7F;
    s2->ch[m2->sub.cur].vol = SND_C088_MAX(0, SND_C088_MIN(s2->vals[s2->cur], 0x7F));
    sSndC088Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    sSndC088Mgr* m3 = *self->p118;
    m3->sub.tgt[m3->sub.cur] = (char*)obj + 0x110;
    pp = self->p118;
    r = func_00288A20(self, obj);
    (*pp)->sub.p64[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_0029C088(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        sndC088AddVoice(self, obj, 0, 0x52, 5);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029C418__FPv);
#ifdef SKIP_ASM
void func_0029C418(void* self)
{
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029C420);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndC420Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndC420E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndC420Sub {
    char pad0[4];
    sSndC420Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndC420Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndC420E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndC420Mgr {
    char pad0[0x1D8];
    sSndC420Sub sub;         // 0x1D8
};
struct sSndC420Sys {
    sSndC420Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndC420Mgr** p118;      // 0x118
};

static inline int sndC420AddVoice(void* vself, char* mon, int a, int b, int type)
{
    sSndC420Sys* self = (sSndC420Sys*)vself;
    sSndC420Mgr* m = self->mgr;
    sSndC420Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndC420Mgr** pp = *(sSndC420Mgr***)mon;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);
extern "C" int func_002B49E0(void*);
extern "C" void func_002B3D48(void*, float);
extern "C" void func_0028D488(void* self);
extern "C" void func_0028CF98(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_002B3A70(void*);

extern "C" void func_0029C420(void* self, int mode)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    char* mon = (char*)self + 0x118;
    sndC420AddVoice(self, mon, 0, 0x4E, 5);
    if (mode == 3) {
        int st = func_002B49E0((char*)self + 0x118);
        if (st == 0xC9 || st == 1 || st == 2 || st == 3) {
            if (*(int*)((char*)self + 0x627C) != 0) {
                func_002B3D48((char*)self + 0x118, 2.0f);
            }
        }
    }
    if (mode == 1) {
        int st = func_002B49E0((char*)self + 0x118);
        if (*(int*)((char*)self + 0x530) == 0 || st == 0xC9 || st == 1 || st == 2 || st == 3) {
            if (*(int*)((char*)self + 0x627C) != 0) {
                func_0028D488(self);
                func_0028CF98(self, 0, 0, -1, 0);
                func_002B3A70((char*)self + 0x118);
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029C7B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);
extern "C" int func_00288AE0(void* self);
extern "C" void* func_0028B1C8();
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00295028(void* self, int a, int b);
void func_002B3A98_C7B0(void* p) __asm__("func_002B3A98");
void func_0028DF08_C7B0(void* p) __asm__("func_0028DF08__FPv");
void func_002B1758(void* self, int a1);
int func_002B4908(void* self);
extern "C" void func_002A3170(void* self);
extern "C" void func_002A3400(void* self);
extern "C" int func_002A4078(void* self);
extern "C" int func_002A40E8(void* self);
extern "C" void func_00295950(void* self, int a, int b, int c);
extern signed char D_00535C11[];
extern char* D_004A28A8;

struct sSnd7B0Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd7B0E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd7B0Sub {
    char pad0[4];
    sSnd7B0Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd7B0Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd7B0E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd7B0Mgr {
    char pad0[0x1D8];
    sSnd7B0Sub sub;         // 0x1D8
};
struct sSnd7B0Sys {
    sSnd7B0Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSnd7B0Mgr** p118;      // 0x118
};
struct sSs7B0PreC { char pad[0xC]; };
class sSs7B0Self : public sSs7B0PreC {
public:
    virtual void v01(int a, int b);
};
struct sSs7B0Pre118 { char pad[0x5440]; };
class sSs7B0Obj : public sSs7B0Pre118 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(int a);
};

static inline int snd7B0Add(void* vself, int a, int b)
{
    sSnd7B0Sys* self = (sSnd7B0Sys*)vself;
        sSnd7B0Mgr* m = self->mgr;
        sSnd7B0Sub* s = &m->sub;
        m->sub.cur++;
        s->ch[m->sub.cur] = m->sub.def;
        m->sub.tgt[m->sub.cur] = 0;
        s->p34[m->sub.cur] = 0;
        s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
        s->p3C[m->sub.cur] = 0;
        func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
        s->p60[m->sub.cur] = 0;
        s->p64[m->sub.cur] = 0;
        s->p68[m->sub.cur] = 0;
        s->p6C[m->sub.cur] = 0;
        s->p70[m->sub.cur].f4 = 0;
        s->p70[m->sub.cur].f0 = 100;
        s->p70[m->sub.cur].f8 = 90;
        s->p70[m->sub.cur].fC = 50;
        s->p74[m->sub.cur] = 0;
        s->p80[m->sub.cur] = 0;
        s->p84[m->sub.cur] = 0;
        s->p78[m->sub.cur] = 0x7F;
        s->p7C[m->sub.cur] = 1;
        self->a4[self->mgr->sub.cur] = a;
        self->a8[self->mgr->sub.cur] = b;
        sSnd7B0Mgr* m3 = *self->p118;
        sSnd7B0Sub* s3 = &m3->sub;
        s3->vals[m3->sub.cur] = 0x7F;
        s3->ch[m3->sub.cur].vol = (s3->vals[s3->cur] < 0x7F && s3->vals[s3->cur] < 0) ? 0 : (s3->vals[s3->cur] < 0x7F ? (unsigned char)s3->vals[s3->cur] : 0x7F);
        sSnd7B0Mgr** pp = self->p118;
        int r = (int)func_00287968(self, 9, 0);
        (*pp)->sub.p3C[(*pp)->sub.cur] = r;
        return func_002906B8(self);
}

extern "C" void func_0029C7B0(void* vself)
{
    sSnd7B0Sys* self = (sSnd7B0Sys*)vself;
    char* base = (char*)vself;
    func_002B3A98_C7B0(base + 0x118);
    func_0028DF08_C7B0(vself);
    *(int*)(base + 0x582C) = *(int*)(*(int*)((char*)func_0028B1C8() + 0xC) + 8);
    ((sSs7B0Self*)vself)->v01(0, 0x62);
    if (func_00288AE0(vself) == 0) {
        snd7B0Add(vself, 0, 0x5E);
    }
    if (*(int*)(base + 0x627C) != 0) {
        ((sSs7B0Obj*)(base + 0x118))->v04(0);
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (func_00295028(vself, 0, 0) == 0) {
        int m = D_00535C11[0];
        if (m == 1) {
            func_002A3170(vself);
        } else if (m == 2) {
            func_002A3170(vself);
        } else {
            int* p = *(int**)(D_004A28A8 + 0xC0);
            if (p[0x98 / 4] != 0) {
                func_002A3400(vself);
                func_002B1758(base + 0x5560, 0);
                if (func_002A4078(vself) != 0 || func_002A40E8(vself) != 0) {
                    *(int*)(base + 0x5774) = 1;
                    *(int*)(base + 0x5778) = func_002B4908(base + 0x118);
                }
            } else {
                int v = p[0];
                if (v == 1) {
                    *(int*)(base + 0x5774) = 1;
                    *(int*)(base + 0x5778) = func_002B4908(base + 0x118);
                } else if (v == 2) {
                    if (func_002A4078(vself) != 0 || func_002A40E8(vself) != 0) {
                        *(int*)(base + 0x5774) = 1;
                        *(int*)(base + 0x5778) = func_002B4908(base + 0x118);
                    }
                }
            }
        }
    }
    if (*(int*)(base + 0x627C) == 0) {
        if (func_00288AE0(vself) == 0) {
            *(int*)(base + 0x627C) = 1;
            ((sSs7B0Obj*)(base + 0x118))->v04(0x25);
        } else if (*(int*)(base + 0x6298) != 0) {
            ((sSs7B0Obj*)(base + 0x118))->v04(0x25);
        }
    }
    func_00295950(vself, 0, *(int*)(**(char***)(base + 0x118) + 0x260) + 0x32, 0);
    *(int*)(base + 0x5824) = **(int**)(D_004A28A8 + 0xC0);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029CCA8);
#ifdef SKIP_ASM
extern "C" int func_00288AE0(void* self);
extern "C" void* func_0028B1D8();
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" void func_002ADCA0(void*, int, long, int, int, int, int, int);
// PORT: func_004139F8 is libgcc's float -> unsigned conversion (__fixunssfsi).
extern "C" int func_004139F8(float f);
extern char* D_004A28A8;
extern int D_005308D0[];
extern sSndKey8 D_004A3678[];

// PORT: 64-bit long sound key
extern "C" void func_0029CCA8(char* self)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    char* g = *(char**)(D_004A28A8 + 0xC0);
    if (g == 0) {
        return;
    }
    int ok = 0;
    if (*(int*)(g + 0x88) != 0) {
        ok = ((D_005308D0[0] >> 9) & 1) ^ 1;
    }
    if (!ok) {
        return;
    }
    int t = (int)((float)*(int*)((char*)func_0028B1D8() + 0xC) * 0.01666666753590107f);
    int m = (func_004139F8((float)*(unsigned int*)(g + 0x78) * 0.01666666753590107f) - t) % 3600;
    if (m <= 0) {
        return;
    }
    if (m != *(int*)(self + 0x607C) && m < 11 && (m == 10 || m == 8 || m == 6 || m < 5)) {
        char* p = **(char***)(self + 0x118) + 0x1D8;
        sSndKey8* key = D_004A3678;
        int r = (int)func_00287968(self, 9, 0);
        func_002ADCA0(p, 0x1C2, key->v, r, 0, 0x4E, 0x7F, 0);
    }
    *(int*)(self + 0x607C) = m;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029CE28);
#ifdef SKIP_ASM
extern "C" void func_002AD2A8(void*);

extern "C" void func_0029CE28(void* self)
{
    if (*(int*)((char*)self + 0x5FB0) == 0) {
        *(int*)((char*)self + 0x5FB0) = 1;
        *(int*)((char*)**(void***)((char*)self + 0x118) + 0x26C) = 1;
        func_002AD2A8((char*)**(void***)((char*)self + 0x118) + 0x1D8);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029CE70);
#ifdef SKIP_ASM
extern "C" void func_002AD300(void* self);
extern "C" void func_002AD810(void* self);
extern "C" void func_002B6A68(void* self);
extern void* D_004A52D4;

extern "C" void func_0029CE70(void* self)
{
    if (*(int*)((char*)self + 0x5FB0) != 0) {
        *(int*)((char*)self + 0x5FB0) = 0;
        func_002AD300(**(char***)((char*)self + 0x118) + 0x1D8);
        *(int*)(**(char***)((char*)self + 0x118) + 0x26C) = 0;
        func_002AD810(**(char***)((char*)self + 0x118) + 0x1D8);
        func_002B6A68(D_004A52D4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029CED8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndCED8Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndCED8E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndCED8Sub {
    char pad0[4];
    sSndCED8Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndCED8Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndCED8E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndCED8Mgr {
    char pad0[0x1D8];
    sSndCED8Sub sub;         // 0x1D8
};
struct sSndCED8Sys {
    sSndCED8Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndCED8Mgr** p118;      // 0x118
};

static inline int sndCED8AddVoice(void* vself, int a, int b, int type)
{
    sSndCED8Sys* self = (sSndCED8Sys*)vself;
    sSndCED8Mgr* m = self->mgr;
    sSndCED8Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndCED8Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_002A3EB8(void* self, void* obj, int n);

extern "C" void func_0029CED8(void* self, int kind, void* obj, float x)
{
    if (obj != 0) {
        bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
        if (!ok) {
            return;
        }
    }
    int id = 0x74;
    if (kind == 0) {
        id = 0x70;
    } else if (kind == 1) {
        id = 0x71;
    } else if (kind == 2) {
        id = 0x75;
    } else if (kind == 3) {
        id = 0x76;
    }
    sndCED8AddVoice(self, 0, id, 9);
    if (kind == 2) {
        if (x == 2.0f) {
            func_002A3EB8(self, obj, 1);
        } else if (x == 3.0f) {
            func_002A3EB8(self, obj, 2);
        } else if (x == 5.0f) {
            func_002A3EB8(self, obj, 4);
        } else if (x == 10.0f) {
            func_002A3EB8(self, obj, 8);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029D290);
#ifdef SKIP_ASM
extern "C" void* func_0028B1D8();
extern "C" void func_0029D370(void* self);
extern "C" void func_0029D678(void* self, float v);
extern "C" void func_002AD650(void* self, int id, float v);

static inline int sndIsOn(char* t)
{
    return *(int*)t == 1;
}

extern "C" void func_0029D290(void* self)
{
    char* s = *(char**)((char*)func_0028B1D8() + 0x28);
    int v = *(int*)(s + 0x430);
    int ok = v != -1;
    if (ok) {
        if ((v & 0xFF) != *(unsigned char*)((char*)self + 0x5FC0)) {
            *(int*)((char*)self + 0x5FC0) = v;
            if (*(int*)(s + 0x434) < 0x16) {
                func_0029D370(self);
            } else {
                func_0029D678(self, 5.029983997344971f);

                char* o = **(char***)((char*)self + 0x118);
                char* bm = o + 0x1D8;
                char* e = *(char**)(o + 0xACC);
                int id = sndIsOn(e + 0x300);
                if (id) id = *(int*)(e + 0x304); else id = -1;
                func_002AD650(bm, id, 5.029983997344971f);

                char* o2 = **(char***)((char*)self + 0x118);
                char* bm2 = o2 + 0x1D8;
                char* e2 = *(char**)(o2 + 0xACC);
                int id2 = sndIsOn(e2 + 0x360);
                if (id2) id2 = *(int*)(e2 + 0x364); else id2 = -1;
                func_002AD650(bm2, id2, 5.029983997344971f);
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029D370);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndD370Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndD370E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndD370Sub {
    char pad0[4];
    sSndD370Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndD370Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndD370E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndD370Mgr {
    char pad0[0x1D8];
    sSndD370Sub sub;         // 0x1D8
};
struct sSndD370Sys {
    sSndD370Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndD370Mgr** p118;      // 0x118
};

static inline int sndD370AddVoice(void* vself, int a, int b)
{
    sSndD370Sys* self = (sSndD370Sys*)vself;
    sSndD370Mgr* m = self->mgr;
    sSndD370Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndD370Mgr** pp = self->p118;
    int r = (int)func_00287968(self, 5, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_0029D370(void* self)
{
    if (*(int*)((char*)self + 0x6C74) != 0) {
        *(int*)((char*)self + 0x5FC8) = sndD370AddVoice(self, 9, 0);
    }
    *(int*)((char*)self + 0x5FC4) = 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029D610);
#ifdef SKIP_ASM
extern "C" void func_003B58A0(void);
extern "C" void func_003B58D8(void);
extern "C" int func_003B8AB8(int h);
extern "C" void func_0029D678(void* self, float v);
extern "C" void func_0029D370(void* self);

extern "C" void func_0029D610(void* self)
{
    if (*(int*)((char*)self + 0x5FC4) != 0) {
        func_003B58A0();
        int done = func_003B8AB8(*(int*)((char*)self + 0x5FC8)) != 0;
        func_003B58D8();
        if (done) {
            func_0029D678(self, 0.0f);
            func_0029D370(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029D678);
#ifdef SKIP_ASM
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_0029D678(void* self, float v)
{
    if (*(int*)((char*)self + 0x5FC4) != 0) {
        int idx = *(int*)((char*)self + 0x5FC8);
        if (idx >= 0) {
            func_002AD5F0((char*)**(void***)((char*)self + 0x118) + 0x1D8, idx, 1, v);
            *(int*)((char*)self + 0x5FC8) = -1;
        }
        *(int*)((char*)self + 0x5FC4) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029D6D0__FPv);
#ifdef SKIP_ASM
void func_0029D6D0(void* self)
{
    *(int*)((char*)self + 0x5FD8) = 1;
}
#endif

INCLUDE_ASM("sound/soundsys", func_0029D6E0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029D8E0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndD8E0Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndD8E0E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndD8E0Sub {
    char pad0[4];
    sSndD8E0Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndD8E0Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndD8E0E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndD8E0Mgr {
    char pad0[0x1D8];
    sSndD8E0Sub sub;         // 0x1D8
};
struct sSndD8E0Sys {
    sSndD8E0Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndD8E0Mgr** p118;      // 0x118
};

static inline int sndD8E0AddVoice(void* vself, int a, int b, int type)
{
    sSndD8E0Sys* self = (sSndD8E0Sys*)vself;
    sSndD8E0Mgr* m = self->mgr;
    sSndD8E0Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndD8E0Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void* func_0028B1D8();
extern "C" void func_002A3C00(void* self, void* obj, int a2);

struct sSndVtEntD8E0 { short delta; short index; void (*fn)(void*, int); };

extern "C" void func_0029D8E0(void* self)
{
    if (*(int*)((char*)self + 0x5FD4) != 0) {
        char* o = (char*)self + 0x118;
        sSndVtEntD8E0* e = &(*(sSndVtEntD8E0**)((char*)self + 0x5558))[4];
        e->fn(o + e->delta, 0x27);
        *(int*)((char*)self + 0x5FD0) = 0;
        *(int*)((char*)self + 0x5FD4) = 0;
    }
    sndD8E0AddVoice(self, 0, 0x6D, 9);
    func_002A3C00(self, *(void**)((char*)func_0028B1D8() + 0x28), 1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029DBB0);
#ifdef SKIP_ASM
extern "C" void func_00294F78(void* self, int id);
extern "C" void func_00296E20(void* self, void* obj);
extern "C" void func_00297438(void* self, void* obj);
extern "C" void func_0029B3C0(void* self, void* obj);

struct sSndVtEnt { short delta; short index; void (*fn)(void*, int); };

extern "C" void func_0029DBB0(void* self, int keep)
{
    if (*(int*)((char*)self + 0x5FD4) != 0) {
        if (keep == 0) {
            func_00294F78(self, 0xE);
        }
        func_00296E20(self, *(void**)((char*)func_0028B1D8() + 0x28));
        func_00297438(self, *(void**)((char*)func_0028B1D8() + 0x28));
        func_0029B3C0(self, 0);
        char* o = (char*)self + 0x118;
        sSndVtEnt* e = &(*(sSndVtEnt**)((char*)self + 0x5558))[4];
        e->fn(o + e->delta, 0x27);
        *(int*)((char*)self + 0x5FD0) = 0;
        *(int*)((char*)self + 0x5FD4) = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029DC48);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndDC48Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndDC48E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndDC48Sub {
    char pad0[4];
    sSndDC48Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndDC48Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndDC48E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndDC48Mgr {
    char pad0[0x1D8];
    sSndDC48Sub sub;         // 0x1D8
};
struct sSndDC48Sys {
    sSndDC48Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndDC48Mgr** p118;      // 0x118
};

static inline int sndDC48AddVoice(void* vself, int a, int b, int type)
{
    sSndDC48Sys* self = (sSndDC48Sys*)vself;
    sSndDC48Mgr* m = self->mgr;
    sSndDC48Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndDC48Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" void func_0029DC48(void* self, void* obj)
{
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        sndDC48AddVoice(self, 0, 0x61, 9);
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_0029DEF0);

INCLUDE_ASM("sound/soundsys", func_0029E438);

//100%
INCLUDE_ASM("sound/soundsys", func_0029E560__FPv);
#ifdef SKIP_ASM
void func_0029E560(void* self)
{
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029E578);
#ifdef SKIP_ASM
extern "C" void func_0029E578(void* self, void* a1)
{
    int idx = *(int*)((char*)a1 + 0x870);
    self = (char*)self + idx * 4;
    *(int*)((char*)self + 0x6080) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029E590);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndE590Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndE590E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndE590Sub {
    char pad0[4];
    sSndE590Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndE590Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndE590E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndE590Mgr {
    char pad0[0x1D8];
    sSndE590Sub sub;         // 0x1D8
};
struct sSndE590Sys {
    sSndE590Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndE590Mgr** p118;      // 0x118
};

extern "C" int func_00288A20(void* self, void* obj);

#define SND_E590_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_E590_MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int sndE590AddVoice(void* vself, int a, int b, int type, unsigned short pitch)
{
    sSndE590Sys* self = (sSndE590Sys*)vself;
    sSndE590Mgr* m = self->mgr;
    sSndE590Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndE590Mgr* m2 = *self->p118;
    sSndE590Sub* s2 = &m2->sub;
    s2->vals[m2->sub.cur] = 0x7F;
    s2->ch[m2->sub.cur].vol = SND_E590_MAX(0, SND_E590_MIN(s2->vals[s2->cur], 0x7F));
    sSndE590Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    sSndE590Mgr* m3 = *self->p118;
    *(unsigned short*)((char*)&m3->sub.ch[m3->sub.cur] + 0xC) = pitch;
    return func_002906B8(self);
}


extern "C" int func_00288AE0(void* self);

static inline char* sndE590Tbl(void* self)
{
    return (char*)self + 0x6080;
}

extern "C" void func_0029E590(void* self, void* obj, float x)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        int idx = *(int*)((char*)obj + 0x870);
        float prev = *(float*)(sndE590Tbl(self) + (idx << 2));
        unsigned short pitch = (int)((x <? prev) * 5.0f) * 0x50 + 0x1000;
        sndE590AddVoice(self, 0, 0x5F, 9, pitch);
        *(float*)(sndE590Tbl(self) + (idx << 2)) = x;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029E970);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int func_002906B8(void* self);

struct sSndE970Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSndE970E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSndE970Sub {
    char pad0[4];
    sSndE970Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSndE970Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSndE970E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSndE970Mgr {
    char pad0[0x1D8];
    sSndE970Sub sub;         // 0x1D8
};
struct sSndE970Sys {
    sSndE970Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
    char padC[0x118 - 0xC];
    sSndE970Mgr** p118;      // 0x118
};

extern "C" int func_00288A20(void* self, void* obj);

#define SND_E970_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_E970_MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int sndE970AddVoice(void* vself, int a, int b, int type)
{
    sSndE970Sys* self = (sSndE970Sys*)vself;
    sSndE970Mgr* m = self->mgr;
    sSndE970Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->a4[self->mgr->sub.cur] = a;
    self->a8[self->mgr->sub.cur] = b;
    sSndE970Mgr* m2 = *self->p118;
    sSndE970Sub* s2 = &m2->sub;
    s2->vals[m2->sub.cur] = 0x7F;
    s2->ch[m2->sub.cur].vol = SND_E970_MAX(0, SND_E970_MIN(s2->vals[s2->cur], 0x7F));
    sSndE970Mgr** pp = self->p118;
    int r = (int)func_00287968(self, type, 0);
    (*pp)->sub.p3C[(*pp)->sub.cur] = r;
    return func_002906B8(self);
}

extern "C" int func_00288AE0(void* self);

static inline char* sndE970Tbl(void* self)
{
    return (char*)self + 0x6080;
}

extern "C" void func_0029E970(void* self, void* obj)
{
    if (func_00288AE0(self) != 0) {
        return;
    }
    bool ok = *(int*)((char*)obj + 0x874) && *(int*)((char*)obj + 0x87C);
    if (ok) {
        int idx = *(int*)((char*)obj + 0x870);
        if (*(float*)(sndE970Tbl(self) + (idx << 2)) == 1.0f) {
            return;
        }
        sndE970AddVoice(self, 0, 0x60, 9);
        *(float*)(sndE970Tbl(self) + (idx << 2)) = 1.0f;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029ED18);
#ifdef SKIP_ASM
extern "C" void* func_0028B1D8();
extern "C" void func_0029B3C0(void* self, void* obj);
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);

extern "C" void func_0029ED18(void* self)
{
    func_00296E20(self, *(void**)((char*)func_0028B1D8() + 0x28));
    func_00297438(self, *(void**)((char*)func_0028B1D8() + 0x28));
    func_0029B3C0(self, 0);
    if (*(int*)((char*)self + 0x59E4) > 0) {
        func_002AD5F0(**(char***)((char*)self + 0x118) + 0x1D8, *(int*)((char*)self + 0x59E0), 1, 0.0f);
        *(int*)((char*)self + 0x59E4) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029ED90);
#ifdef SKIP_ASM
extern "C" int func_0029F198(void* self);
extern "C" void* func_00287968(void* self, int a1, int a2);
extern "C" int BXFILE_exists(const char* name);
extern "C" void func_002B0CE0(void* self);
extern "C" void func_002B0DA0(void* self);
extern "C" void func_002B0E60(void* self, int a, int b, char* name, int c, int d, int e);
extern "C" void func_003DED50(const char* name, int a, int b, void** h);
extern "C" void func_003DEDC0(void* h, int a);
extern char D_00482DF8[];
extern char D_00482E10[];
extern char D_00482E28[];
extern char D_00482E40[];
extern char D_004A3568[];

static inline void sndStreamLoad(const char* name, void** h)
{
    if (BXFILE_exists(name)) {
        func_003DED50(name, 0, 100, h);
    }
}

extern "C" void func_0029ED90(char* self, int restart)
{
    int mode = func_0029F198(self);
    if (mode == *(int*)(self + 0x572C)) {
        return;
    }
    if (restart) {
        func_002B0DA0(self + 0x5560);
    }
    void** h = (void**)(self + 0x5728);
    if (*h) {
        func_003DEDC0(*h, 100);
    }
    if (mode == 2) {
        sndStreamLoad(D_00482DF8, h);
    } else if (mode == 4) {
        sndStreamLoad(D_00482E10, h);
    } else if (mode == 8) {
        sndStreamLoad(D_00482E28, h);
    } else {
        sndStreamLoad(D_00482E40, h);
    }
    *(int*)(self + 0x572C) = mode;
    if (restart) {
        func_002B0CE0(self + 0x5560);
        func_002B0E60(self + 0x5560, 0, 0, D_004A3568, (int)func_00287968(self, 4, 0), 1, -1);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029EEE0);
#ifdef SKIP_ASM
extern "C" int func_0028B1B0();

extern "C" int func_0029EEE0(void* self, int a1, const char* name)
{
    if (a1 == 0) {
        if (name[0] == 'D' && name[1] == 'J' && name[2] == '_') {
            if (func_0028B1B0() != 0) {
                *(int*)((char*)self + 0x5738) = 2;
            } else {
                *(int*)((char*)self + 0x5738) = 11;
            }
        } else if (name[0] == 'P' && name[1] == 'A' && name[2] == '_') {
            *(int*)((char*)self + 0x5738) = 3;
        } else if (name[0] == 'A' && name[1] == 'r' && name[2] == 'c' && name[3] == 'a' && name[4] == 'd' && name[5] == 'e') {
            *(int*)((char*)self + 0x5738) = 10;
        } else {
            *(int*)((char*)self + 0x5738) = 4;
        }
        return *(int*)((char*)self + 0x5738);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F000);
#ifdef SKIP_ASM
extern "C" void func_00287F00(void* self, int a1, float f0, float f1);

extern "C" void* func_0029F000(void* self, int a1, int type, int a3)
{
    if (a1 == 0) {
        if (type == 2) {
            func_00287F00(self, 0, 0.9999024868011475f, 0.6499993801116943f);
        }
        if (type == 0xB) {
            return (char*)self + 0x5730;
        }
        return func_00287968(self, type, a3);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F088);
#ifdef SKIP_ASM
extern "C" int func_0029F088(void* self, int a1)
{
    if (a1 == 0) {
        return *(int*)((char*)self + 0x5738);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F0A0);
#ifdef SKIP_ASM
extern "C" float func_00287920(void* self, int ch);

extern "C" int func_0029F0A0(void* self)
{
    if (func_00287920(self, 4) == 0.0f) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F0D8);
#ifdef SKIP_ASM
extern "C" int func_00288AE0(void* self);
extern "C" float func_00287920(void* self, int ch);

extern "C" int func_0029F0D8(void* self)
{
    if (func_00288AE0(self) != 0) {
        return 0;
    }
    if (func_00287920(self, 2) == 0.0f) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F128);
#ifdef SKIP_ASM
extern "C" float func_00287920(void* self, int ch);

extern "C" int func_0029F128(void* self)
{
    if (func_00287920(self, 3) == 0.0f) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F160);
#ifdef SKIP_ASM
extern "C" float func_00287920(void* self, int ch);

extern "C" int func_0029F160(void* self)
{
    if (func_00287920(self, 0xA) == 0.0f) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F198);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");

struct sSsOpts9F198 {
    unsigned int w0;
    int data[0x288 / 4 - 1];
};
extern sSsOpts9F198 D_00535610_ss9F198 __asm__("D_00535610");

extern "C" int func_0029F198(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 4);
    sSsOpts9F198 o = D_00535610_ss9F198;
    unsigned m = o.w0 >> 22;
    m &= 7;
    switch (m) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 8;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F2B0);
#ifdef SKIP_ASM
// PORT: the unit declares this as void(int, int); defined under an asm label with its real type
extern "C" int func_0029F2B0_impl(unsigned int idx, int flag) __asm__("func_0029F2B0");
extern "C" int func_0029F2B0_impl(unsigned int idx, int flag)
{
    if (flag == 0) {
        switch (idx) {
        case 6: return 1;
        case 3: return 2;
        case 0: return 4;
        case 8: return 8;
        case 1: return 0x10;
        case 4: return 0x20;
        case 9: return 0x80;
        case 7: return 0x40;
        case 5: return 0x100;
        case 2: return 0x200;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_0029F330);
#ifdef SKIP_ASM
extern "C" int func_00123128(void*);
extern "C" int func_00123168(void*);
extern "C" void func_0029F2B0(int, int);

extern "C" void func_0029F330(void* self)
{
    int a = func_00123128(self);
    func_0029F2B0(a, func_00123168(self));
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F378);
#ifdef SKIP_ASM
extern "C" int func_0029F378(void* self, void* obj)
{
    switch (func_00123168(obj)) {
    case 0:
        return func_00123128(obj);
    case 14:
    case 16:
    case 21:
        return 6;
    default:
        return 7;
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_0029F3F8);

//100%
INCLUDE_ASM("sound/soundsys", func_0029F5E0);
#ifdef SKIP_ASM
extern "C" void func_0028BCE8(void* self, int i);

extern "C" void func_0029F5E0(void* self)
{
    func_0028BCE8(**(void***)((char*)self + 0x118), 0xE);
    func_0028BCE8(**(void***)((char*)self + 0x118), 0xF);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029F620);
#ifdef SKIP_ASM
struct sSndVEntry29F620 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_0029F620(void* self, void* obj)
{
    void* sub = (char*)obj + 0x6C0;
    sSndVEntry29F620* vt = *(sSndVEntry29F620**)sub;
    if (vt[7].fn((char*)sub + vt[7].delta) == 0) {
        return 0xE;
    }
    return 0xF;
}
#endif

INCLUDE_ASM("sound/soundsys", func_0029F660);

//100%
INCLUDE_ASM("sound/soundsys", func_0029FCC8);
#ifdef SKIP_ASM
extern "C" int func_002A3FE8(void* self);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" int* func_00144BC0(void*);
extern "C" void* func_0028B1E8();
extern "C" int func_00288B40(void* self, int which, float f);
extern "C" int func_002B0E28(void* self, int i);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern "C" int func_00123128(void*);
// PORT: the unit defines func_0029F330 as void; it returns its tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
// PORT: D_004A482C is called with 4 args here (the unit's later declaration has 3).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");
extern float D_004A36D8;

class cSsFCC8Obj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09();
};
struct sSsFCC8RiderA {
    char pad0[0x470];
    float f470;
    char pad474[0x6C0 - 0x474];
};
struct sSsFCC8Rider : public sSsFCC8RiderA, public cSsFCC8Obj {
    char pad6C4[0x788 - 0x6C4];
    char* p788;
    char pad78C[0x87C - 0x78C];
    int f87C;
};

extern "C" void func_0029FCC8(void* self, void* vrider)
{
    sSsFCC8Rider* rider = (sSsFCC8Rider*)vrider;
    if (func_0029F0A0(self) == 0) return;
    if (func_002A3FE8(self) != 0) return;
    if (func_00288AE0(self) != 0) return;
    int pos = rider->f470 >= 0.0f;
    if (pos) return;
    if (*(float*)(rider->p788 + 0x98) < 4.000256061553955f) return;
    int chk = 0;
    if (rider->v09() != 0 || rider->f87C == 0) chk = 1;
    if (chk && func_00285D98_p(self, -1) != rider) return;
    float v = rider->f470;
    float zero = 0.0f;
    int pos2 = v >= zero;
    if (pos2) return;
    char* snd = (char*)self + 0x5560;
    if (func_002B0E28(snd, 0) == 0) return;
    int r = func_0029F330_i(rider);
    if (func_00288B40(self, rider->v05(), D_004A36D8) < 0) return;
    int sel = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
    if (sel == 1) {
        if (func_002B1458(snd, 0, 0x2084, (int)rider, func_00123128(rider), 0, 0, zero) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x2084), 2, r, 3);
        }
    } else if (sel == 2) {
        if (func_002B1458(snd, 0, 0x2083, (int)rider, func_00123128(rider), 0, 0, zero) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x2083), 2, r, 3);
        }
    } else {
        if (func_002B1458(snd, 0, 0x2091, (int)rider, func_00123128(rider), 0, 0, zero) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x2091), 2, r, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_0029FF80);
#ifdef SKIP_ASM
extern "C" int func_0029F0A0(void* self);
extern "C" int func_00288AE0(void* self);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" int* func_00144BC0(void*);
extern "C" void* func_0028B1E8();
extern "C" int func_00288B40(void* self, int which, float f);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern "C" int func_00123128(void*);
// PORT: the unit defines func_0029F330 as void; it returns its tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
extern void (*D_004A482C)(void*, int, int);
extern float D_004A36D8;

class cSsFF80Obj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09();
};
struct sSsFF80RiderA {
    char pad0[0x470];
    float f470;
    char pad474[0x6C0 - 0x474];
};
struct sSsFF80Rider : public sSsFF80RiderA, public cSsFF80Obj {
    char pad6C4[0x87C - 0x6C4];
    int f87C;
};

extern "C" void func_0029FF80(void* self, sSsFF80Rider* rider, int alt)
{
    if (func_0029F0A0(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    int pos = rider->f470 >= 0.0f;
    if (pos) return;
    int chk = 0;
    if (rider->v09() != 0 || rider->f87C == 0) chk = 1;
    if (chk && func_00285D98_p(self, -1) != rider) return;
    int r = func_0029F330_i(rider);
    if (func_00288B40(self, rider->v05(), D_004A36D8) < 0) return;
    if (alt != 0) {
        int sel = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
        if (sel == 1) {
            if (func_002B1458((char*)self + 0x5560, 0, 0x2090, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
                D_004A482C(func_003D8008(1, 0, 0x2090), 1, r);
            }
        } else if (sel == 2) {
            if (func_002B1458((char*)self + 0x5560, 0, 0x209B, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
                D_004A482C(func_003D8008(1, 0, 0x209B), 1, r);
            }
        } else {
            if (func_002B1458((char*)self + 0x5560, 0, 0x209D, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
                D_004A482C(func_003D8008(1, 0, 0x209D), 1, r);
            }
        }
    } else {
        int sel = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
        if (sel == 1) {
            if (func_002B1458((char*)self + 0x5560, 0, 0x2082, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
                D_004A482C(func_003D8008(1, 0, 0x2082), 1, r);
            }
        } else if (sel == 2) {
            if (func_002B1458((char*)self + 0x5560, 0, 0x209A, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
                D_004A482C(func_003D8008(1, 0, 0x209A), 1, r);
            }
        } else {
            if (func_002B1458((char*)self + 0x5560, 0, 0x209C, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
                D_004A482C(func_003D8008(1, 0, 0x209C), 1, r);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A02D8);
#ifdef SKIP_ASM
extern "C" int func_002A3F90(void* self);
extern "C" int func_002A4040(void* self);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" int* func_00144BC0(void*);
extern "C" void* func_0028B1E8();
extern "C" int func_00288B40(void* self, int which, float f);
extern "C" int func_002B0E28(void* self, int i);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern "C" int func_00123128(void*);
// PORT: the unit defines func_0029F330 as void; it returns its tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
// PORT: D_004A482C is called with 4 args here (the unit's later declaration has 3).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");
extern float D_004A36D8;

class cSs02D8Obj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09();
};
struct sSs02D8RiderA {
    char pad0[0x470];
    float f470;
    char pad474[0x6C0 - 0x474];
};
struct sSs02D8Rider : public sSs02D8RiderA, public cSs02D8Obj {
    char pad6C4[0x87C - 0x6C4];
    int f87C;
};

extern "C" void func_002A02D8(void* self, sSs02D8Rider* rider)
{
    if (func_0029F0A0(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    int pos = rider->f470 >= 0.0f;
    if (pos) return;
    int chk = 0;
    if (rider->v09() != 0 || rider->f87C == 0) chk = 1;
    if (chk && func_00285D98_p(self, -1) != rider) return;
    if (func_002B0E28((char*)self + 0x5560, 0) == 0) return;
    int r = func_0029F330_i(rider);
    int mode;
    if (func_002A3F90(self) != 0 || func_002A4040(self) != 0) {
        mode = 1;
    } else {
        mode = 3;
    }
    if (func_00288B40(self, rider->v05(), D_004A36D8) < 0) return;
    int sel = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
    if (sel == 1) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x2088, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x2088), 2, r, mode);
        }
    } else if (sel == 2) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20A0, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x20A0), 2, r, mode);
        }
    } else {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20A1, (int)rider, func_00123128(rider), 0, 0, 0.0f) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x20A1), 2, r, mode);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A0560);
#ifdef SKIP_ASM
extern "C" int func_0029F0A0(void* self);
extern "C" int func_00288AE0(void* self);
extern "C" int func_00123168(void*);
extern "C" int func_00288B40(void* self, int which, float f);
extern "C" int func_002B0E28(void* self, int i);
int func_002B1458_f(void* self, int a, int b, int c, int d, float f, int e, int refresh) __asm__("func_002B1458");
extern "C" void* func_003D8008(int a, int b, int c);
extern "C" int func_00123128(void*);
extern "C" void* func_0028B1C8();
// PORT: the unit defines func_0029F330/func_002A1D48 as void; they return their tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
int func_002A1D48_i(void* self, void* obj) __asm__("func_002A1D48");
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
unsigned func_002A1820_0560(void* self, void* a, void* b) __asm__("func_002A1820");
void func_0031BE50_0560(float a, float* x, float* y) __asm__("func_0031BE50");
// PORT: D_004A482C is called with 4 and 5 args here (the unit's later declaration has 3).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");
extern float D_004A36D8;
extern void* D_004A28A4;
static inline int sndA30Mode0560(int m)
{
    return *(int*)((char*)D_004A28A4 + 0x550) == m;
}

struct sVec4_0560 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_0560(const sVec4_0560& a, const sVec4_0560& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

class cSs0560Obj {
public:
    virtual void v01();
    virtual sVec4_0560* v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09();
};
struct sSs0560RiderA {
    char pad0[0x470];
    float f470;
    char pad474[0x4CC - 0x474];
    float f4CC;
    char pad4D0[0x6C0 - 0x4D0];
};
struct sSs0560Rider : public sSs0560RiderA, public cSs0560Obj {
    char pad6C4[0x87C - 0x6C4];
    int f87C;
};

void func_002A0560_0560(void* self, sSs0560Rider* a, sSs0560Rider* b) __asm__("func_002A0560");
void func_002A0560_0560(void* self, sSs0560Rider* a, sSs0560Rider* b)
{
    if (func_0029F0A0(self) == 0) return;
    if (!sndA30Mode0560(2)) return;
    if (func_00288AE0(self) != 0) return;
    if (func_00123168(a) != 0) return;
    if (func_00123168(b) != 0) return;
    if (*(int*)(*(int*)((char*)func_0028B1C8() + 0xC) + 8) - *(int*)((char*)self + 0x582C) < 0x258) return;
    int posA = a->f470 >= 0.0f;
    if (posA) return;
    int posB = b->f470 >= 0.0f;
    if (posB) return;
    int chkA = 0;
    if (a->v09() != 0 || a->f87C == 0) chkA = 1;
    int chkB = 0;
    if (b->v09() != 0 || b->f87C == 0) chkB = 1;
    void* pl = func_00285D98_p(self, -1);
    if (chkA && chkB && a != pl && b != pl) return;
    char* snd = (char*)self + 0x5560;
    if (func_002B0E28(snd, 0) == 0) return;
    int okA = func_00288B40(self, a->v05(), D_004A36D8);
    if (okA < 0) return;
    int okB = func_00288B40(self, b->v05(), D_004A36D8);
    if (okA != okB) return;
    float t0, t1;
    func_0031BE50_0560(b->f4CC, &t0, &t1);
    sVec4_0560 v;
    v.x = t1;
    v.y = t0;
    v.z = 0;
    v.w = 0;
    float d = vu0Dot_0560(v, *a->v02());
    d -= vu0Dot_0560(v, *b->v02());
    if (!(d > 670.55999755859375f)) return;
    if (!(d < 1788.159912109375f)) return;
    int mode = 1;
    int rA = func_0029F330_i(a);
    int s = func_002A1D48_i(self, b);
    int rB = func_0029F330_i(b);
    if (d >= 1341.1199951171875f) mode = 2;
    unsigned sel = func_002A1820_0560(self, a, b);
    if (sel == 2) {
        d = 0.0f;
        if (func_002B1458_f(snd, 0, 0x2081, (int)a, func_00123128(a), d, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x2081), 2, rA, mode);
        }
        if (func_002B1458_f(snd, 0, 0x207F, (int)b, func_00123128(b), d, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x207F), 2, rB, mode);
        }
    } else if (sel < 2) {
        d = 0.0f;
        if (func_002B1458_f(snd, 0, 0x2080, (int)a, func_00123128(a), d, 0, 0) != 0) {
            s |= 0x1000;
            D_004A482C_5(func_003D8008(1, 0, 0x2080), 3, rA, mode, s);
        }
        if (func_002B1458_f(snd, 0, 0x207D, (int)b, func_00123128(b), d, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x207D), 2, rB, mode);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A0A30);
#ifdef SKIP_ASM
extern "C" int func_0029F0A0(void* self);
extern "C" int func_00288AE0(void* self);
extern "C" int func_00123168(void*);
extern "C" int func_00288B40(void* self, int which, float f);
extern "C" int func_002B0E28(void* self, int i);
// func_002B1458 with the float argument in its real position (same registers).
int func_002B1458_f(void* self, int a, int b, int c, int d, float f, int e, int refresh) __asm__("func_002B1458");
extern "C" void* func_003D8008(int a, int b, int c);
extern "C" int func_00123128(void*);
extern "C" void func_0029F660(void* self, void* rider, int a, int b);
// PORT: the unit defines func_0029F330 as void; it returns its tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
// PORT: D_004A482C is called with 4 args here (the unit's later declaration has 3).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");
extern float D_004A36D8;
extern void* D_004A28A4;
static inline int sndA30Mode(int m)
{
    return *(int*)((char*)D_004A28A4 + 0x550) == m;
}

class cSs0A30Obj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09();
};
struct sSs0A30RiderA {
    char pad0[0x470];
    float f470;
    char pad474[0x6C0 - 0x474];
};
struct sSs0A30Rider : public sSs0A30RiderA, public cSs0A30Obj {
    char pad6C4[0x87C - 0x6C4];
    int f87C;
};
struct sSs1820Rider;
extern "C" int func_002A1820(void* self, sSs1820Rider* a, sSs1820Rider* b);

extern "C" void func_002A0A30(void* self, sSs0A30Rider* a, sSs0A30Rider* b, int p7, int p8)
{
    if (func_0029F0A0(self) == 0) return;
    if (!sndA30Mode(2)) return;
    if (func_00288AE0(self) != 0) return;
    if (func_00123168(a) != 0) return;
    if (func_00123168(b) != 0) return;
    int posA = a->f470 >= 0.0f;
    if (posA) return;
    int posB = b->f470 >= 0.0f;
    if (posB) return;
    int chkA = 0;
    if (a->v09() != 0 || a->f87C == 0) chkA = 1;
    int chkB = 0;
    if (b->v09() != 0 || b->f87C == 0) chkB = 1;
    void* pl = func_00285D98_p(self, -1);
    if (chkA && chkB && a != pl && b != pl) return;
    func_0029F660(self, b, 0, 1);
    char* snd = (char*)self + 0x5560;
    if (func_002B0E28(snd, 0) == 0) return;
    int okB = func_00288B40(self, b->v05(), D_004A36D8) >= 0;
    int okA = func_00288B40(self, a->v05(), D_004A36D8) >= 0;
    if (!okB && !okA) return;
    int rA = func_0029F330_i(a);
    int rB = func_0029F330_i(b);
    if (p8 != 0) return;
    if (p7 != 0) return;
    int sel = func_002A1820(self, (sSs1820Rider*)a, (sSs1820Rider*)b);
    if (sel == 2) {
        if (func_002B1458_f(snd, 0, 0x208F, (int)b, func_00123128(b), 0.0f, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x208F), 2, rB, 3);
        }
        if (func_002B1458_f(snd, 0, 0x208A, (int)a, func_00123128(a), 0.0f, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x208A), 2, rA, 3);
        }
    } else if (sel == 1) {
        if (func_002B1458_f(snd, 0, 0x207E, (int)b, func_00123128(b), 0.0f, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x207E), 2, rB, 3);
        }
        if (func_002B1458_f(snd, 0, 0x208A, (int)a, func_00123128(a), 0.0f, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x208A), 2, rA, 3);
        }
    } else if (sel == 0) {
        if (func_002B1458_f(snd, 0, 0x2078, (int)b, func_00123128(b), 0.0f, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x2078), 2, rB, 3);
        }
        if (func_002B1458_f(snd, 0, 0x208E, (int)a, func_00123128(a), 0.0f, 0, 0) != 0) {
            D_004A482C_4(func_003D8008(1, 0, 0x208E), 2, rA, 3);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A0E70);
#ifdef SKIP_ASM
extern "C" int func_00288B40(void* self, int which, float f);
extern "C" int func_002B0E28(void* self, int i);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern "C" int func_00123128(void*);
extern "C" void func_0029F660(void* self, void* rider, int a, int b);
// PORT: the unit defines func_0029F330 as void; it returns its tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
extern void (*D_004A482C)(void*, int, int);
extern float D_004A36D8;

class cSs0E70Obj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v09();
};
struct sSs0E70RiderA {
    char pad0[0x470];
    float f470;
    char pad474[0x6C0 - 0x474];
};
struct sSs0E70Rider : public sSs0E70RiderA, public cSs0E70Obj {
    char pad6C4[0x874 - 0x6C4];
    int f874;
    int f878;
    int f87C;
};

extern "C" void func_002A0E70(void* self, sSs0E70Rider* rider, int play)
{
    if (func_0029F0A0(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    int chk = 0;
    if (rider->v09() != 0 || rider->f87C == 0) chk = 1;
    if (chk && func_00285D98_p(self, -1) != rider) return;
    float v = rider->f470;
    float zero = 0.0f;
    int pos = v >= zero;
    if (pos) return;
    char* snd = (char*)self + 0x5560;
    if (func_002B0E28(snd, 0) == 0) return;
    if (func_00288B40(self, rider->v05(), D_004A36D8) < 0) return;
    func_0029F660(self, rider, 2, 0);
    if (play == 0) return;
    int ok = rider->f874 != 0 && rider->f87C != 0;
    if (!ok) return;
    int r = func_0029F330_i(rider);
    if (func_002B1458(snd, 0, 0x2077, (int)rider, func_00123128(rider), 0, 0, zero) == 0) return;
    D_004A482C(func_003D8008(1, 0, 0x2077), 1, r);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1028);
#ifdef SKIP_ASM
extern "C" int func_002B1220(void* self, int i);
extern "C" int func_002AB150(void* self, int i);
extern "C" void* func_002AD550(void* self, int idx, int a2);
extern "C" void func_002B11B0(void*, int);

extern "C" int func_002A1028(void* self, int id)
{
    int idx = func_002AB150(*(void**)((char*)self + 0x118), func_002B1220((char*)self + 0x5560, 0));
    if (idx < 0) {
        return 1;
    }
    void* voice = func_002AD550(**(char***)((char*)self + 0x118) + 0x1D8, idx, 3);
    if (voice == 0) {
        return 0;
    }
    if (*(int*)((char*)voice + 0x80) == id) {
        func_002B11B0((char*)self + 0x5560, 0);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A10C0);
#ifdef SKIP_ASM
extern "C" int func_002B1220(void* self, int i);
extern "C" int func_002AB150(void* self, int i);
extern "C" void* func_002AD550(void* self, int idx, int a2);

extern "C" int func_002A10C0(void* self, int id)
{
    int idx = func_002AB150(*(void**)((char*)self + 0x118), func_002B1220((char*)self + 0x5560, 0));
    if (idx < 0) {
        return 0;
    }
    void* voice = func_002AD550(**(char***)((char*)self + 0x118) + 0x1D8, idx, 3);
    if (voice == 0) {
        return 0;
    }
    return *(int*)((char*)voice + 0x80) == id;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1138);
#ifdef SKIP_ASM
extern "C" int func_00288B40(void* self, int which, float f);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
// PORT: the unit defines func_0029F330/func_002A1D48 as void; they return their tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
int func_002A1D48_i(void* self, void* obj) __asm__("func_002A1D48");
// PORT: D_004A482C is called with 5 args here (the unit's later declaration has 3).
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");
extern float D_004A36D8;

struct sSsVt1138 { short delta; short index; int (*fn)(void*); };

// PORT: callers declare func_002A1138 as (void*, int, int); the body takes (self, rider, obj).
void func_002A1138_impl(void* self, char* rider, void* obj) __asm__("func_002A1138");

void func_002A1138_impl(void* self, char* rider, void* obj)
{
    if (func_0029F0A0(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (rider == 0) rider = *(char**)((char*)func_0028B1D8() + 0x2C);
    if (obj == 0) obj = *(void**)((char*)func_0028B1D8() + 0x28);
    char* o = rider + 0x6C0;
    sSsVt1138* e = &(*(sSsVt1138**)o)[5];
    if (func_00288B40(self, e->fn(o + e->delta), D_004A36D8) < 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x20D3, (int)rider, func_00123128(rider), 0, 0, 0.0f) == 0) return;
    int r = func_0029F330_i(rider);
    int s = func_002A1D48_i(self, obj);
    D_004A482C_5(func_003D8008(1, 0, 0x20D3), 3, r, s, 4);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1280);
#ifdef SKIP_ASM
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern "C" int func_00288B40(void* self, int which, float f);
// PORT: the unit defines func_0029F330/func_002A1D48 as void; they return their tail call's result.
int func_0029F330_i(void* self) __asm__("func_0029F330");
int func_002A1D48_i(void* self, void* obj) __asm__("func_002A1D48");
// PORT: D_004A482C is called with 4 args here (the unit's later declaration has 3).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");
extern float D_004A36D8;

struct sSsVt1280 { short delta; short index; int (*fn)(void*); };

// PORT: callers declare func_002A1280 as (void*, int, int); the body takes (self, rider, obj).
void func_002A1280_impl(void* self, char* rider, void* obj) __asm__("func_002A1280");

void func_002A1280_impl(void* self, char* rider, void* obj)
{
    if (func_0029F0A0(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    char* o = rider + 0x6C0;
    sSsVt1280* e = &(*(sSsVt1280**)o)[5];
    if (func_00288B40(self, e->fn(o + e->delta), D_004A36D8) < 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x20D4, (int)rider, func_00123128(rider), 0, 0, 0.0f) == 0) return;
    int r = func_0029F330_i(rider);
    int s = func_002A1D48_i(self, obj);
    D_004A482C_4(func_003D8008(1, 0, 0x20D4), 2, r, s);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1388);
#ifdef SKIP_ASM
extern "C" void* func_0028B1D8();
extern "C" void func_002A1400(void* self, int a);

extern "C" int func_002A1388(void* self, void* obj)
{
    int i = *(int*)((char*)obj + 0x1C);
    int id;
    if (i >= 0 && i < *(int*)((char*)func_0028B1D8() + 0x78)) {
        id = *(int*)((char*)func_0028B1D8() + (i << 2) + 0x28);
    } else {
        id = *(int*)((char*)func_0028B1D8() + 0x28);
    }
    func_002A1400(self, id);
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1400);
#ifdef SKIP_ASM
extern "C" int func_002A1E68(void* self, void* rider);
// PORT: callers pass self to func_002A4248 (the unit's later definition takes no args).
int func_002A4248_s(void* self) __asm__("func_002A4248");
extern signed char D_00535C11[];

// PORT: callers declare func_002A1400 as (void*, int); the body takes (self, rider).
void func_002A1400_impl(void* self, char* rider) __asm__("func_002A1400");

void func_002A1400_impl(void* self, char* rider)
{
    if (func_0029F0A0(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    char* o = rider + 0x6C0;
    sSsVt1280* e = &(*(sSsVt1280**)o)[5];
    if (func_00288B40(self, e->fn(o + e->delta), D_004A36D8) < 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x20B9, (int)rider, func_00123128(rider), 0, 0, 0.0f) == 0) return;
    int r = func_0029F330_i(rider);
    int k = func_002A1E68(self, rider);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int v;
    if (k == 1) {
        v = 1;
    } else if (func_002A4248_s(self) != 0) {
        v = 2;
    } else if (D_00535C11[0] == 2) {
        v = 2;
    } else if (k == 2 || k == 4) {
        v = 4;
    } else {
        v = 2;
    }
    D_004A482C_4(func_003D8008(1, 0, 0x20B9), 2, r, v);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1560);
#ifdef SKIP_ASM
extern "C" int func_002B0E28(void* self, int i);
extern void (*D_004A482C)(void*, int, int);

extern "C" void func_002A1560(void* self, char* rider)
{
    if (func_0029F0A0(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    char* o = rider + 0x6C0;
    int check = 0;
    sSsVt1280* e9 = &(*(sSsVt1280**)o)[9];
    if (e9->fn(o + e9->delta) != 0 || *(int*)(rider + 0x87C) == 0) check = 1;
    if (check && func_00285D98_p(self, -1) != rider) return;
    char* bm = (char*)self + 0x5560;
    if (func_002B0E28(bm, 0) == 0) return;
    char* o2 = rider + 0x6C0;
    sSsVt1280* e = &(*(sSsVt1280**)o2)[5];
    if (func_00288B40(self, e->fn(o2 + e->delta), D_004A36D8) < 0) return;
    if (func_002B1458(bm, 0, 0x20B8, (int)rider, func_00123128(rider), 0, 0, 0.0f) == 0) return;
    int r = func_0029F330_i(rider);
    D_004A482C(func_003D8008(1, 0, 0x20B8), 1, r);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A16B0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_0029F0A0(void* self);
extern "C" int func_002B0E28(void* self, int i);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
// func_0029F2B0 returns a value (the unit's earlier declaration says void).
int func_0029F2B0_r(int a, int b) __asm__("func_0029F2B0");
extern "C" void* func_003D8008(int a, int b, int c);
extern void (*D_004A482C)(void*, int, int);
extern signed char D_00535C11[];

extern "C" void func_002A16B0(void* self, int a1)
{
    if (func_0029F0A0(self) != 0) {
        char* bm = (char*)self + 0x5560;
        if (func_002B0E28(bm, 0) != 0) {
            cBE_getInterface_Fv(cBE_getBE(), 0);
            if (D_00535C11[0] != 0) {
                if (func_002B1458(bm, 0, 0x20BC, 0, a1, 0, 1, 0.0f) != 0) {
                    int r = func_0029F2B0_r(a1, 0);
                    D_004A482C(func_003D8008(1, 0, 0x20BC), 1, r);
                }
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A1778);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F0A0(void* self);
extern "C" int func_002B0E28(void* self, int i);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
// func_0029F2B0 returns a value (the unit's earlier declaration says void).
int func_0029F2B0_r(int a, int b) __asm__("func_0029F2B0");
extern "C" void* func_003D8008(int a, int b, int c);
extern void (*D_004A482C)(void*, int, int);

extern "C" void func_002A1778(void* self, int a1)
{
    if (func_0029F0A0(self) != 0) {
        char* bm = (char*)self + 0x5560;
        if (func_002B0E28(bm, 0) != 0) {
            if (func_002B1458(bm, 0, 0x20BD, 0, a1, 0, 1, 0.0f) != 0) {
                int r = func_0029F2B0_r(a1, 0);
                D_004A482C(func_003D8008(1, 0, 0x20BD), 1, r);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1820);
#ifdef SKIP_ASM
extern "C" void* func_0028B1D8();
void* cBEAggressionInterface_getThis();
extern "C" int func_00155B50(void* ag, int a, int b);
extern "C" int func_00155AB0(void* ag, int a, int b);

class cSs1820Obj {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
};
struct sSs1820RiderA {
    char pad0[0x6C0];
};
struct sSs1820Rider : public sSs1820RiderA, public cSs1820Obj {
    char pad6C4[0x874 - 0x6C4];
    int f874;
    int f878;
    int f87C;
};

extern "C" int func_002A1820(void* self, sSs1820Rider* a, sSs1820Rider* b)
{
    if (*(int*)((char*)func_0028B1D8() + 0x78) == 2) return 2;
    int oka = a->f874 != 0 && a->f87C != 0;
    if (oka) {
        int okb = b->f874 != 0 && b->f87C != 0;
        if (okb) return 2;
    }
    int r = 2;
    int c1 = func_00155B50(cBEAggressionInterface_getThis(), a->v07(), b->v07());
    int c2 = func_00155B50(cBEAggressionInterface_getThis(), b->v07(), a->v07());
    if (c1 < 2 && c2 < 2) {
        int t = func_00155AB0(cBEAggressionInterface_getThis(), a->v07(), b->v07());
        if (t == 0) r = 0;
        else if (t == 1) r = 1;
    }
    return r;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A19D8);

//100%
INCLUDE_ASM("sound/soundsys", func_002A1B58);
#ifdef SKIP_ASM
extern "C" void func_002A1400(void* self, int a);

extern "C" int func_002A1B58(void* self, int msg, int a)
{
    if (msg == 2) {
        func_002A1400(self, a);
        return 1;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A1B88);
#ifdef SKIP_ASM
extern "C" void func_002A1138(void* self, int a, int b);
extern "C" void func_002A1280(void* self, int a, int b);

extern "C" int func_002A1B88(void* self, int type, int a, int b)
{
    if (type == 0) {
        func_002A1138(self, a, b);
        return 1;
    }
    if (type == 1) {
        func_002A1280(self, a, b);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1BD0__FPv);
#ifdef SKIP_ASM
int func_002A1BD0(void* self)
{
    return 0x1;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A1BD8);

//100%
INCLUDE_ASM("sound/soundsys", func_002A1D48);
#ifdef SKIP_ASM
extern "C" int func_00123128(void*);
extern "C" int func_00123168(void*);
extern "C" void func_002A1DA0(void* self, int a, int b);

extern "C" void func_002A1D48(void* self, void* obj)
{
    int a = func_00123128(obj);
    func_002A1DA0(self, a, func_00123168(obj));
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1DA0);
#ifdef SKIP_ASM
// PORT: the unit declares this as void(void*, int, int); defined under an asm label with its real type
extern "C" int func_002A1DA0_impl(void* self, unsigned int idx, int flag) __asm__("func_002A1DA0");
extern "C" int func_002A1DA0_impl(void* self, unsigned int idx, int flag)
{
    if (flag == 0) {
        switch (idx) {
        case 6: return 1;
        case 3: return 2;
        case 0: return 4;
        case 8: return 8;
        case 1: return 0x10;
        case 4: return 0x20;
        case 9: return 0x40;
        case 7: return 0x80;
        case 5: return 0x100;
        case 2: return 0x200;
        }
    }
    return 0x1000;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A1E20);
#ifdef SKIP_ASM
extern "C" int func_002A1E20(void* self, unsigned int x)
{
    switch (x) {
    case 0: case 1: case 5: case 8: case 11: case 14: case 17: case 18:
        return 1;
    case 2: case 3: case 6: case 9: case 12: case 15: case 19: case 20:
        return 2;
    case 4: case 7: case 10: case 13: case 16: case 21:
        return 4;
    }
    return 0;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A1E68);

//100%
INCLUDE_ASM("sound/soundsys", func_002A2018);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2018(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20C8, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_4(func_003D8008(1, 0, 0x20C8), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A20D0);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A20D0(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20C9, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_4(func_003D8008(1, 0, 0x20C9), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2188);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1D8();
// func_002A1D48 returns its tail call's value (the unit defines it as void).
int func_002A1D48_r(void* self, void* obj) __asm__("func_002A1D48");
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 5-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2188(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20CA, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int a = func_002A1D48_r(self, *(void**)((char*)func_0028B1D8() + 0x28));
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_5(func_003D8008(1, 0, 0x20CA), 3, r, a, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2260);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2260(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20E7, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_4(func_003D8008(1, 0, 0x20E7), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2318);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2318(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20E8, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_4(func_003D8008(1, 0, 0x20E8), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A23D0);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A23D0(void* self, int mode)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20E9, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m;
            if (mode == -1) {
                m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            } else {
                m = func_002A1E20(self, mode);
            }
            D_004A482C_4(func_003D8008(1, 0, 0x20E9), 2, r, m);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A24B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" int func_002A1BD8(void* self, int a, int b);
extern "C" void* func_003D8008(int a, int b, int c);
// 5-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A24B0(void* self, int a1)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20CC, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1BD8(self, a1, -1);
            D_004A482C_5(func_003D8008(1, 0, 0x20CC), 3, r, m, 3);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A2568);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1BD8(void* self, int a, int b);
extern "C" void* func_003D8008(int a, int b, int c);
// 5-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2568(void* self, int a1)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20CC, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1BD8(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)), a1);
            D_004A482C_5(func_003D8008(1, 0, 0x20CC), 3, r, m, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2638);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2638(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20BA, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_4(func_003D8008(1, 0, 0x20BA), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A26F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F0D8(void* self);
extern "C" void func_002B11B0(void*, int);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_003D8008(int a, int b, int c);
// 5-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A26F0(void* self, int a, int b)
{
    if (func_0029F0D8(self) != 0) {
        char* bm = (char*)self + 0x5560;
        func_002B11B0(bm, 0);
        if (func_002B1458(bm, 0, 0x20E5, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int x = 2;
            if (a) x = 1;
            if (*(int*)((char*)self + 0x5794) != 0) {
                *(int*)((char*)self + 0x5794) = 0;
            }
            int y = 2;
            if (!b) y = 1;
            D_004A482C_5(func_003D8008(1, 0, 0x20E5), 3, r, x, y);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A27D8);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_003D8008(int a, int b, int c);
extern void (*D_004A482C)(void*, int, int);

extern "C" void func_002A27D8(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20E6, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            D_004A482C(func_003D8008(1, 0, 0x20E6), 1, r);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2860);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_003D8008(int a, int b, int c);
// 6-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_6)(void*, int, int, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2860(void* self, int n)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20CF, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int lo = 0;
            int hi = 0;
            if (n >= 0 && n != 999) {
                if (n < 100) {
                    lo = 1 << n;
                } else {
                    n -= 100;
                    hi = 1 << n;
                }
            }
            D_004A482C_6(func_003D8008(1, 0, 0x20CF), 4, r, 3, lo, hi);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2938);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1D8();
// func_002A1D48 returns its tail call's value (the unit defines it as void).
int func_002A1D48_r(void* self, void* obj) __asm__("func_002A1D48");
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 5-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2938(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x2102, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int a = func_002A1D48_r(self, *(void**)((char*)func_0028B1D8() + 0x28));
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_5(func_003D8008(1, 0, 0x2102), 3, r, a, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2A10);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00145750(void*);
// func_002A1DA0 returns a value (the unit declares it void).
int func_002A1DA0_r(void* self, int a, int b) __asm__("func_002A1DA0");
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2A10(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x210B, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1DA0_r(self, func_00145750(cBE_getInterface_Fv(func_0028B1E8(), 0)), 0);
            D_004A482C_4(func_003D8008(1, 0, 0x210B), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2AD0);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1E20(void* self, unsigned int a1);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2AD0(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x212B, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1E20(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)));
            D_004A482C_4(func_003D8008(1, 0, 0x212B), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A2B88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2B88(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x212C, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int v = *(int*)((char*)self + 0x5780);
            D_004A482C_4(func_003D8008(1, 0, 0x212C), 2, r, v);
        }
        *(int*)((char*)self + 0x5780) = 1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A2C30);
#ifdef SKIP_ASM
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1BD8(void* self, int a, int b);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2C30(void* self)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x212D, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1BD8(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)), -1);
            D_004A482C_4(func_003D8008(1, 0, 0x212D), 2, r, m);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A2CF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" int func_002A1BD8(void* self, int a, int b);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2CF0(void* self, int a1)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x212E, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1BD8(self, a1, -1);
            D_004A482C_4(func_003D8008(1, 0, 0x212E), 2, r, m);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A2DA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F0D8(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" int func_002A1BD8(void* self, int a, int b);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A2DA0(void* self, int a1)
{
    if (func_0029F0D8(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x212F, 0, 0xA, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1BD8(self, a1, -1);
            D_004A482C_4(func_003D8008(1, 0, 0x212F), 2, r, m);
        }
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A2E50);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A3170);
#ifdef SKIP_ASM
extern "C" void func_002A26F0(void* self, int a, int b);
void func_002B1758(void* self, int a1);
int func_002B4908(void* self);

extern "C" void func_002A3170(void* self)
{
    func_002A26F0(self, 0, 0);
    func_002B1758((char*)self + 0x5560, 0);
    *(int*)((char*)self + 0x5774) = 1;
    *(int*)((char*)self + 0x5778) = func_002B4908((char*)self + 0x118);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A31C0);
#ifdef SKIP_ASM
extern "C" int func_0029F128(void* self);
extern "C" int func_002A4040(void* self);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C11[];
extern char* D_004A28A8;
extern "C" int func_00295028(void* self, int a, int b);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A31C0(void* self)
{
    if (func_0029F128(self) == 0) return;
    if (func_002A4040(self) != 0) return;
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] != 0) return;
    if (**(int**)(D_004A28A8 + 0xC0) < 2) {
        if (func_00295028(self, 0, 0) != 0) return;
        if (func_002B1458((char*)self + 0x5560, 0, 0x20C0, 0, 0xB, 0, 0, 0.0f) == 0) return;
        int r = func_0029F198(self);
        D_004A482C_4(func_003D8008(1, 0, 0x20C0), 2, r, 1);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A32B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F128(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1D8();
// func_002A1D48 returns its tail call's value (the unit defines it as void).
int func_002A1D48_r(void* self, void* obj) __asm__("func_002A1D48");
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A32B0(void* self)
{
    if (func_0029F128(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20C1, 0, 0xB, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int a = func_002A1D48_r(self, *(void**)((char*)func_0028B1D8() + 0x28));
            D_004A482C_4(func_003D8008(1, 0, 0x20C1), 2, r, a);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3358);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F128(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1D8();
// func_002A1D48 returns its tail call's value (the unit defines it as void).
int func_002A1D48_r(void* self, void* obj) __asm__("func_002A1D48");
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A3358(void* self)
{
    if (func_0029F128(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20C2, 0, 0xB, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int a = func_002A1D48_r(self, *(void**)((char*)func_0028B1D8() + 0x28));
            D_004A482C_4(func_003D8008(1, 0, 0x20C2), 2, r, a);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A3400);
#ifdef SKIP_ASM
extern "C" int func_0029F128(void* self);
extern "C" int func_00288AE0(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1BD8(void* self, int a, int b);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A3400(void* self)
{
    if (func_0029F128(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x20C3, 0, 0xB, 0, 0, 0.0f) == 0) return;
    int r = func_0029F198(self);
    int m = func_002A1BD8(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)), -1);
    D_004A482C_4(func_003D8008(1, 0, 0x20C3), 2, r, m);
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A34D0);

//100%
INCLUDE_ASM("sound/soundsys", func_002A3708);
#ifdef SKIP_ASM
extern "C" int func_0029F128(void* self);
extern "C" int func_00123168(void*);
extern "C" int func_0029F198(void* self);
extern "C" int func_002A1E68(void* self, void* rider);
// PORT: callers pass self to func_002A4248 (the unit's later definition takes no args).
int func_002A4248_s(void* self) __asm__("func_002A4248");
// PORT: D_004A482C is called with 5 args here (the unit's later declaration has 3).
extern void (*D_004A482C_5)(void*, int, int, int, int) __asm__("D_004A482C");
extern sSndKey8 D_004A36E8[];

// PORT: 64-bit long sound key
extern "C" void func_002A3708(void* self, char* rider)
{
    if (func_0029F128(self) == 0) return;
    if (func_00288AE0(self) != 0) return;
    if (func_00123168(rider) != 0) return;
    if (func_002A4248_s(self) != 0) {
        char* o = rider + 0x6C0;
        char* p = **(char***)((char*)self + 0x118) + 0x1D8;
        sSndKey8* key = D_004A36E8;
        sSsVt1280* e = &(*(sSsVt1280**)o)[7];
        int v = e->fn(o + e->delta);
        func_002ADCA0(p, 1000, key->v, 0, v, 0, 0, 0);
        return;
    }
    if (func_002B1458((char*)self + 0x5560, 0, 0x20C5, 0, 0xB, 0, 0, 0.0f) == 0) return;
    int a = func_0029F198(self);
    int b = func_002A1D48_i(self, rider);
    int c = func_002A1E68(self, rider);
    D_004A482C_5(func_003D8008(1, 0, 0x20C5), 3, a, b, c);
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A3860);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A39E0);
#ifdef SKIP_ASM
extern "C" int func_0029F128(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" int func_0029F198(void* self);
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A1BD8(void* self, int a, int b);
extern "C" void* func_003D8008(int a, int b, int c);
// 4-argument view of the D_004A482C callback (the unit declares a 3-argument one).
extern void (*D_004A482C_4)(void*, int, int, int) __asm__("D_004A482C");

extern "C" void func_002A39E0(void* self)
{
    if (func_0029F128(self) != 0) {
        if (func_002B1458((char*)self + 0x5560, 0, 0x20BB, 0, 0xB, 0, 0, 0.0f) != 0) {
            int r = func_0029F198(self);
            int m = func_002A1BD8(self, *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0)), -1);
            D_004A482C_4(func_003D8008(1, 0, 0x20BB), 2, r, m);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3B18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F160(void* self);
// func_00285D98 returns an object pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
extern "C" int func_00288AE0(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern void (*D_004A482C)(void*, int, int);

extern "C" void func_002A3B18(void* self, void* obj, int a2)
{
    if (func_0029F160(self) == 0) return;
    if (obj == 0) return;
    int done = *(float*)((char*)obj + 0x470) >= 0.0f;
    if (done) return;
    if (obj != func_00285D98_p(self, -1)) return;
    if (func_00288AE0(self) != 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x20A7, 0, 0xC, 0, 0, 0.0f) != 0) {
        D_004A482C(func_003D8008(1, 0, 0x20A7), 1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3C00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0029F160(void* self);
// func_00285D98 returns an object pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");
extern "C" int func_00288AE0(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern void (*D_004A482C)(void*, int, int);

extern "C" void func_002A3C00(void* self, void* obj, int a2)
{
    if (func_0029F160(self) == 0) return;
    if (obj == 0) return;
    if (a2 != 2) {
        int done = *(float*)((char*)obj + 0x470) >= 0.0f;
        if (done) return;
    }
    if (obj != func_00285D98_p(self, -1)) return;
    if (func_00288AE0(self) != 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x20A8, 0, 0xC, 0, 0, 0.0f) != 0) {
        D_004A482C(func_003D8008(1, 0, 0x20A8), 1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3CE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void (*D_004A482C)(void*, int, int);
// func_00285D98 returns a rider pointer here (the unit declares it int).
void* func_00285D98_p(void* self, int which) __asm__("func_00285D98");

extern "C" void func_002A3CE8(void* self, char* rider, int n)
{
    float zero;
    if (func_0029F160(self) == 0) return;
    if (rider == 0) return;
    float v = *(float*)(rider + 0x470);
    zero = 0.0f;
    int done = v >= zero;
    if (done) return;
    if (n != 1 && rider != func_00285D98_p(self, -1)) return;
    if (func_00288AE0(self) != 0) return;
    if (n == 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x20A9, 0, 0xC, 0, 0, zero) != 0) {
        D_004A482C(func_003D8008(1, 0, 0x20A9), 1, n);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3DE0);
#ifdef SKIP_ASM
extern "C" int func_0029F160(void* self);
extern "C" int func_00288AE0(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern void (*D_004A482C)(void*, int, int);

extern "C" void func_002A3DE0(void* self, void* obj, int ev)
{
    if (func_0029F160(self) == 0) return;
    if (obj == 0) return;
    int done = *(float*)((char*)obj + 0x470) >= 0.0f;
    if (done) return;
    if (func_00288AE0(self) != 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x2133, 0, 0xC, 0, 0, 0.0f) != 0) {
        D_004A482C(func_003D8008(1, 0, 0x2133), 1, ev);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3EB8);
#ifdef SKIP_ASM
extern "C" int func_0029F160(void* self);
extern "C" int func_00288AE0(void* self);
extern "C" int func_002B1458(void* self, int a, int b, int c, int d, int e, int refresh, float f);
extern "C" void* func_003D8008(int a, int b, int c);
extern void (*D_004A482C)(void*, int, int);

extern "C" void func_002A3EB8(void* self, void* obj, int ev)
{
    if (func_0029F160(self) == 0) return;
    if (obj == 0) return;
    int done = *(float*)((char*)obj + 0x470) >= 0.0f;
    if (done) return;
    if (func_00288AE0(self) != 0) return;
    if (func_002B1458((char*)self + 0x5560, 0, 0x2145, 0, 0xC, 0, 0, 0.0f) != 0) {
        D_004A482C(func_003D8008(1, 0, 0x2145), 1, ev);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3F90);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A3FD8(void* self, unsigned int a1);

extern "C" int func_002A3F90(void* self)
{
    return func_002A3FD8(self, *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0)));
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3FD8);
#ifdef SKIP_ASM
extern "C" int func_002A3FD8(void* self, unsigned int a1)
{
    return a1 - 0x11 < 5;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A3FE8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A4030(void* self, unsigned int a1);

extern "C" int func_002A3FE8(void* self)
{
    return func_002A4030(self, *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0)));
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4030);
#ifdef SKIP_ASM
extern "C" int func_002A4030(void* self, unsigned int a1)
{
    return a1 - 0xe < 3;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4040);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C10[];

extern "C" int func_002A4040(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    return D_00535C10[0] == 4;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4078);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A40E0(void* self, unsigned int a1);
extern signed char D_00535C10[];

extern "C" int func_002A4078(void* self)
{
    if (func_002A40E0(self, *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0))) != 0) {
        return 1;
    }
    if (D_00535C10[0] == 0) {
        return 1;
    }
    return D_00535C10[0] == 5;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A40E0);
#ifdef SKIP_ASM
extern "C" int func_002A40E0(void* self, unsigned int a1)
{
    return a1 < 5;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A40E8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A4158(void* self, unsigned int a1);
extern signed char D_00535C10[];

extern "C" int func_002A40E8(void* self)
{
    if (func_002A4158(self, *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0))) != 0) {
        return 1;
    }
    if (D_00535C10[0] == 1) {
        return 1;
    }
    int r = 0;
    if (D_00535C10[0] == 6) {
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4158);
#ifdef SKIP_ASM
extern "C" int func_002A4158(void* self, unsigned int a1)
{
    return a1 - 5 < 3;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4168);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A41C8(void* self, unsigned int a1);
extern signed char D_00535C10[];

extern "C" int func_002A4168(void* self)
{
    if (func_002A41C8(self, *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0))) != 0) {
        return 1;
    }
    return D_00535C10[0] == 2;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A41C8);
#ifdef SKIP_ASM
extern "C" int func_002A41C8(void* self, unsigned int a1)
{
    return a1 - 8 < 3;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A41D8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);
extern "C" int func_002A4238(void* self, unsigned int a1);
extern signed char D_00535C10[];

extern "C" int func_002A41D8(void* self)
{
    if (func_002A4238(self, *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0))) != 0) {
        return 1;
    }
    return D_00535C10[0] == 3;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4238);
#ifdef SKIP_ASM
extern "C" int func_002A4238(void* self, unsigned int a1)
{
    return a1 - 0xb < 3;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4248);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C12[];

extern "C" int func_002A4248(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    switch (D_00535C12[0]) {
    case 4:
        return 1;
    case 5:
        return 1;
    default:
        return 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4290);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C12[];

extern "C" int func_002A4290(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    return D_00535C12[0] == 4;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A42C8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C12[];

extern "C" int func_002A42C8(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C12[0] >= 6) {
        if (D_00535C12[0] <= 11) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4318);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C12[];

extern "C" int func_002A4318(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C12[0] >= 6) {
        if (D_00535C12[0] <= 8) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4368);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern signed char D_00535C12[];

extern "C" int func_002A4368(void)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C12[0] >= 9) {
        if (D_00535C12[0] <= 11) {
            return 1;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A43B8);
#ifdef SKIP_ASM
extern "C" void* func_0028B1D8();
extern "C" void func_002A1138(void* self, int a, int b);
extern "C" void func_002A1400(void* self, int a);
extern "C" void func_002A26F0(void* self, int a, int b);
extern "C" void func_002A2568(void* self, int a);
extern "C" void func_002A2638(void* self);
extern "C" void func_002A27D8(void* self);
extern "C" void func_002A2860(void* self, int a);
extern "C" void func_002A2AD0(void* self);
extern "C" void func_002A2B88(void* self);
extern "C" void func_002A2C30(void* self);
extern "C" void func_002A2E50(void* self, int a);

extern "C" void func_002A43B8(char* self)
{
    if (*(int*)(self + 0x5768) != 0) {
        func_002A26F0(self, 0, 0);
        *(int*)(self + 0x5768) = 0;
    } else if (*(int*)(self + 0x5784) != 0) {
        func_002A2AD0(self);
        *(int*)(self + 0x5784) = 0;
    } else if (*(int*)(self + 0x576C) != 0) {
        func_002A2638(self);
        *(int*)(self + 0x576C) = 0;
    } else if (*(int*)(self + 0x577C) != 0) {
        func_002A2B88(self);
        *(int*)(self + 0x577C) = 0;
    } else if (*(int*)(self + 0x5770) != 0) {
        func_002A2C30(self);
        *(int*)(self + 0x5770) = 0;
    } else if (*(int*)(self + 0x5788) != 0) {
        func_002A1138(self, 0, 0);
        *(int*)(self + 0x5788) = 0;
    } else if (*(int*)(self + 0x5774) != 0) {
        func_002A2860(self, *(int*)(self + 0x5778));
        *(int*)(self + 0x5774) = 0;
    } else if (*(int*)(self + 0x574C) != 0) {
        func_002A2E50(self, 0);
        *(int*)(self + 0x574C) = 0;
    } else if (*(int*)(self + 0x5750) != 0) {
        func_002A2E50(self, 0);
        *(int*)(self + 0x5750) = 0;
    } else if (*(int*)(self + 0x5754) != 0) {
        func_002A2E50(self, 1);
        *(int*)(self + 0x5754) = 0;
    } else if (*(int*)(self + 0x5758) != 0) {
        func_002A2568(self, *(int*)(self + 0x575C));
        *(int*)(self + 0x5758) = 0;
    } else if (*(int*)(self + 0x5740) != 0) {
        func_002A27D8(self);
        *(int*)(self + 0x5740) = 0;
    }
    if (*(int*)(self + 0x5744) != 0) {
        char* b = (char*)func_0028B1D8();
        int t = *(int*)(b + (*(int*)(self + 0x5748) << 2) + 0x28);
        if (t != 0) {
            func_002A1400(self, t);
        }
        *(int*)(self + 0x5744) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4550);
#ifdef SKIP_ASM
extern "C" void func_002A4550(void* self)
{
    *(int*)((char*)self + 0x5740) = 0;
    *(int*)((char*)self + 0x5744) = 0;
    *(int*)((char*)self + 0x574C) = 0;
    *(int*)((char*)self + 0x5750) = 0;
    *(int*)((char*)self + 0x5754) = 0;
    *(int*)((char*)self + 0x5758) = 0;
    *(int*)((char*)self + 0x5760) = 0;
    *(int*)((char*)self + 0x5768) = 0;
    *(int*)((char*)self + 0x576C) = 0;
    *(int*)((char*)self + 0x5770) = 0;
    *(int*)((char*)self + 0x5774) = 0;
    *(int*)((char*)self + 0x577C) = 0;
    *(int*)((char*)self + 0x5784) = 0;
    *(int*)((char*)self + 0x5788) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4590);
#ifdef SKIP_ASM
extern "C" void func_002A4590(void* self, int flag)
{
    *(int*)((char*)self + 0x57F8) = 0;
    *(int*)((char*)self + 0x57FC) = 0;
    *(int*)((char*)self + 0x5804) = 0;
    *(int*)((char*)self + 0x5808) = 0;
    *(int*)((char*)self + 0x5800) = -1;
    *(int*)((char*)self + 0x5810) = -1;
    if (flag) {
        *(int*)((char*)self + 0x580C) = -1;
    }
    *(int*)((char*)self + 0x5814) = 0x17;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A45C0);
#ifdef SKIP_ASM
extern "C" void func_002A4590(void* self, int flag);
extern "C" void* func_0028B1D8();
extern "C" int func_002A4078(void* self);
extern "C" void func_002A4660(void* self, int id, int a, int b, int c);
extern char* D_004A28A8;
extern int D_00536730[];

extern "C" void func_002A45C0(void* self)
{
    if (**(int**)(D_004A28A8 + 0xC0) == 1) {
        func_002A4590(self, 0);
    }
    int id = D_00536730[0];
    char* rider = *(char**)((char*)func_0028B1D8() + 0x28);
    int a;
    if (func_002A4078(self) != 0) {
        a = *(int*)(*(char**)(rider + 0x790) + 0x128);
    } else {
        a = 0;
    }
    func_002A4660(self, id, a, *(int*)(*(char**)(rider + 0x790) + 0x114), *(int*)(rider + 0x480) ^ 1);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4660);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern "C" void* func_0028B1E8();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);

extern "C" void func_002A4660(void* self, int a1, int a2, int a3, int a4)
{
    char* g = *(char**)(D_004A28A8 + 0xC0);
    if (*(int*)(g + 0x98) != 0 || *(int*)(g + 0x70) <= *(int*)g) {
        *(int*)((char*)self + 0x57F8) = 1;
        if (a4 != 0 && *(int*)g == 3) {
            *(int*)((char*)self + 0x57FC) = 1;
        }
        *(int*)((char*)self + 0x5800) = a1;
        *(int*)((char*)self + 0x5810) = *func_00144BC0(cBE_getInterface_Fv(func_0028B1E8(), 0));
    }
    *(int*)((char*)self + 0x5804) += a2;
    *(int*)((char*)self + 0x5808) += a3;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4718);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void*);

extern "C" int func_002A4718(void* self)
{
    int id = *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0));
    int cur = *(int*)((char*)self + 0x5814);
    if (id == cur || cur == 0x17) {
        return 0;
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A4770);
#ifdef SKIP_ASM
extern "C" int func_002A40E0(void* self, unsigned int a1);
extern "C" int func_002A4158(void* self, unsigned int a1);
extern "C" int func_002A4238(void* self, unsigned int a1);
extern "C" int func_002A4030(void* self, unsigned int a1);
extern "C" int func_002A3FD8(void* self, unsigned int a1);
extern "C" void func_002A2E50(void* self, int a);
// bank-monitor method: returns BXrand()
extern "C" unsigned int func_002ADF60(void* mon);

extern "C" int func_002A4770(void* self)
{
    char* s = (char*)self;
    if (*(int*)(s + 0x57F8) != 0) {
        *(int*)(s + 0x57F8) = 0;
        int flags[3];
        int i;
        for (i = 2; i >= 0; i--) {
            flags[i] = 0;
        }
        int n = 0;
        if (*(int*)(s + 0x57FC) != 0) {
            if (*(int*)(s + 0x5800) == 0) {
                flags[0] = 1;
                n = 1;
            }
            if (*(int*)(s + 0x5804) >= 5) {
                flags[1] = 1;
                n++;
            }
            int lim;
            if (func_002A40E0(self, *(int*)(s + 0x5810))) {
                lim = 0x1B;
            } else if (func_002A4158(self, *(int*)(s + 0x5810))) {
                lim = 0x1B;
            } else {
                lim = func_002A4238(self, *(int*)(s + 0x5810)) ? 0x1B : 0x18;
            }
            if (*(int*)(s + 0x5808) >= lim) {
                flags[2] = 1;
                n++;
            }
        }
        *(int*)(s + 0x57FC) = 0;
        if (n == 0) {
            if (*(int*)(s + 0x6254) != 0) {
                int cur = *(int*)(s + 0x5814);
                if (cur != 0x17) {
                    if (func_002A3FD8(self, cur)) {
                        func_002A2E50(self, 0);
                        return 1;
                    }
                    if (func_002A4030(self, *(int*)(s + 0x5814))) {
                        func_002A23D0(self, *(int*)(s + 0x5814));
                        return 1;
                    }
                    func_002A24B0(self, *(int*)(s + 0x5814));
                    return 1;
                }
            }
            return 0;
        }
        if (n >= 2) {
            int last = *(int*)(s + 0x580C);
            if (last != -1 && flags[last] != 0) {
                flags[last] = 0;
                n--;
            }
        }
        int pick = -1;
        int k = (func_002ADF60(*(void**)(**(char***)(s + 0x118) + 0x1D8)) & 0x7FFF) * n / 0x7FFF + 1;
        while (k > 0) {
            pick++;
            if (flags[pick]) {
                k--;
            }
        }
        switch (pick) {
        case 0:
            func_002A2938(self);
            break;
        case 1:
            func_002A2CF0(self, *(int*)(s + 0x5810));
            break;
        case 2:
            func_002A2DA0(self, *(int*)(s + 0x5810));
            break;
        }
        *(int*)(s + 0x580C) = pick;
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A49E8);
#ifdef SKIP_ASM
struct sSndId2A49E8 {
    long v;
} __attribute__((packed));
extern sSndId2A49E8 D_004A36F0[];
extern "C" void func_002ADCA0(void* bank, int a1, long id, int a3, int a4, int a5, int a6, int a7);

// Flags the transition and fades the ambient stream back in.
// PORT: the 8-byte stream id is passed by value from an unaligned global (64-bit `long`).
extern "C" void func_002A49E8(char* self)
{
    *(int*)(self + 0x5818) = 1;
    func_002ADCA0(**(char***)(self + 0x118) + 0x1D8, 0x7530, D_004A36F0[0].v, 0, 0, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4A38);
#ifdef SKIP_ASM
extern "C" int func_002A10C0(void* self, int id);

extern "C" int func_002A4A38(void* self)
{
    if (*(int*)((char*)self + 0x5818) != 0) {
        return func_002A10C0(self, 10) != 0;
    }
    return 0;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A4A78);

//100%
INCLUDE_ASM("sound/soundsys", func_002A4B68);
#ifdef SKIP_ASM
extern "C" int func_002B49E0(void*);
extern "C" void func_002B11B0(void*, int);

extern "C" void func_002A4B68(void* self)
{
    if (func_002B49E0((char*)self + 0x118) == 0x191) {
        func_002B11B0((char*)self + 0x5560, 0);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4BA8);
#ifdef SKIP_ASM
extern "C" void* func_002A4BA8(void* self)
{
    int i;
    *(int*)self = 0;
    for (i = 4; i >= 0; i--) {
        *(int*)((char*)self + (i << 2) + 4) = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4BE0);
#ifdef SKIP_ASM
extern "C" void func_002A4CF8(void*);
void operator_delete(int*);

extern "C" void func_002A4BE0(void* self, int flags)
{
    func_002A4CF8(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4C28);
#ifdef SKIP_ASM
struct sSndHandleList5 {
    int count;
    int items[5];
};
extern "C" int func_003E1908(int a, int b);

extern "C" int func_002A4C28(sSndHandleList5* list, int a, int b)
{
    if (list->count >= 5 || (list->items[list->count] = func_003E1908(a, b), list->items[list->count] == 0)) {
        return 0;
    }
    list->count++;
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4CA0);
#ifdef SKIP_ASM
unsigned int BXrand();

struct sSndRandList {
    unsigned int count;
    int items[1];
};

extern "C" int func_002A4CA0(sSndRandList* list)
{
    if (list->count == 0) {
        return 0;
    }
    return list->items[BXrand() % list->count];
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4CF8);
#ifdef SKIP_ASM
struct sSndPtrList {
    int count;
    void* items[5];
};
void cMemMan_free(void*);

extern "C" void func_002A4CF8(void* self)
{
    sSndPtrList* list = (sSndPtrList*)self;
    for (int i = 0; i < list->count; i++) {
        if (list->items[i] != 0) {
            cMemMan_free(list->items[i]);
        }
        list->items[i] = 0;
    }
    list->count = 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4D68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct func_002A4D68_sTriple {
    int a;
    int b;
    int c;
};

struct func_002A4D68_sChan {
    int e0;
    int e4;
    int e8;
    char pad[0x20 - 0xC];
    int index;      // +0x20
    char pad2[0x30 - 0x24];
    func_002A4D68_sChan() {}
};

struct func_002A4D68_sObj {
    int f0;
    char pad4[0x10 - 0x4];
    int f10;
    int f14;
    int f18;
    int f1C;
    func_002A4D68_sTriple triples[15];  // 0x20
    int fD4;
    int fD8;
    int fDC;
    func_002A4D68_sChan chans[3];       // 0xE0
    int f170;
    int f174;
    int f178;
    int f17C;
    int f180;
    int f184;
    int f188;
    int f18C;
    func_002A4D68_sObj() __asm__("func_002A4D68");
};

func_002A4D68_sObj::func_002A4D68_sObj()
    : f0(-1), f10(0), f14(0), f18(0), f1C(0), fD4(0), fD8(-1),
      f170(0), f174(-1), f178(0), f17C(0), f180(0), f184(3), f188(0), f18C(0)
{
    int i;
    for (i = 0; i < 15; i++) {
        triples[i].a = 0;
        triples[i].b = 0;
        triples[i].c = 0;
    }
    for (i = 0; i < 3; i++) {
        *(int*)((char*)this + i * 0x30 + 0x100) = i;
        *(int*)((char*)this + i * 0x30 + 0xE0) = -1;
        *(int*)((char*)this + i * 0x30 + 0xE4) = -1;
        *(int*)((char*)this + i * 0x30 + 0xE8) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A4E38);
#ifdef SKIP_ASM
extern "C" void func_002A6848(void* self);
extern "C" void func_002A6430(void* self, float v);
void operator_delete(int*);

extern "C" void func_002A4E38(void* self, int flags)
{
    func_002A6848(self);
    func_002A6430(self, 0.0f);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A4E88);

//100%
INCLUDE_ASM("sound/soundsys", func_002A5CD8);
#ifdef SKIP_ASM
struct s2A5CD8Entry {
    int active;
    int value;
    int pad;
};

struct s2A5CD8 {
    char pad[0x20];
    s2A5CD8Entry entries[1];
};

extern "C" void func_002A5CD8(s2A5CD8* self, int i, int v)
{
    if (i >= 0) {
        if (self->entries[i].active) {
            self->entries[i].value = v;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A5D08);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" int func_002906B8(void* self);

struct sVec4_5D08 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sPoolGroup5D08 {
    int key;
    int handle;
    int cnt;
    int pad0C;
    sVec4_5D08 vec;
    char pad20[0x10];
};
struct sPoolSlot5D08 {
    sVec4_5D08* p;
    int v4;
    sPoolGroup5D08* grp;
};
struct sPool5D08 {
    int f0;
    char pad4[0xC];
    sVec4_5D08 vec10;
    sPoolSlot5D08 slots[15];
    int count;
    int fD8;
    char padDC[4];
    sPoolGroup5D08 groups[3];
    int f170;
    char pad174[8];
    int f17C;
};

struct sSnd5D08Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd5D08E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd5D08Sub {
    char pad0[4];
    sSnd5D08Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd5D08Ch* ch;          // 0x20
    sVec4_5D08* tgt[4];      // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    char e40[4][8];          // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd5D08E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd5D08Mgr {
    char pad0[0x1D8];
    sSnd5D08Sub sub;         // 0x1D8
};
struct sSnd5D08Sys {
    sSnd5D08Mgr* mgr;
    int* a4;                 // 0x4
    int* a8;                 // 0x8
};
struct sSndKey8_5D08 {
    long v;
} __attribute__((packed));
extern sSndKey8_5D08 D_004A3700_5D08[] __asm__("D_004A3700");
extern sSnd5D08Sys* D_004A36F8_5D08 __asm__("D_004A36F8");

#define SND_5D08_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SND_5D08_MAX(a, b) ((a) > (b) ? (a) : (b))

// PORT: 64-bit long sound key
int func_002A5D08_5D08(sPool5D08* self, sSnd5D08Sub* P, int key) __asm__("func_002A5D08");
int func_002A5D08_5D08(sPool5D08* self, sSnd5D08Sub* P, int key)
{
    int idx = -1;
    int cnt = self->count;
    if (cnt >= 15 || P->tgt[P->cur] == 0) {
        return -1;
    }
    sPoolSlot5D08* found = 0;
    int i;
    for (i = 0; i < 15; i++) {
        if (found == 0 && self->slots[i].p == 0) {
            found = &self->slots[i];
            idx = i;
        }
    }
    self->count++;
    found->p = P->tgt[P->cur];
    found->v4 = P->vals[P->cur];
    i = 0;
    do {
        if (self->groups[i].key == key) {
            self->groups[i].cnt++;
            found->grp = &self->groups[i];
            break;
        }
        i++;
    } while (i < 3);
    if (self->count == 1) {
        self->f0 = P->p64[P->cur];
        self->f17C = P->p3C[P->cur];
        self->vec10 = *found->p;
    }
    if (found->grp == 0) {
        int h = 0;
        do {
            if (self->groups[h].cnt == 0) {
                found->grp = &self->groups[h];
                self->groups[h].key = key;
                self->groups[h].cnt++;
                self->f170++;
                break;
            }
            h++;
        } while (h < 3);
        found->grp->vec = *found->p;
        sSnd5D08Sys* sys = D_004A36F8_5D08;
        sSnd5D08Mgr* m = sys->mgr;
        int a = self->fD8;
        sSnd5D08Sub* s = &m->sub;
        m->sub.cur++;
        s->ch[m->sub.cur] = m->sub.def;
        m->sub.tgt[m->sub.cur] = 0;
        s->p34[m->sub.cur] = 0;
        s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
        s->p3C[m->sub.cur] = 0;
        func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
        s->p60[m->sub.cur] = 0;
        s->p64[m->sub.cur] = 0;
        s->p68[m->sub.cur] = 0;
        s->p6C[m->sub.cur] = 0;
        s->p70[m->sub.cur].f4 = 0;
        s->p70[m->sub.cur].f0 = 100;
        s->p70[m->sub.cur].f8 = 90;
        s->p70[m->sub.cur].fC = 50;
        s->p74[m->sub.cur] = 0;
        s->p80[m->sub.cur] = 0;
        s->p84[m->sub.cur] = 0;
        s->p78[m->sub.cur] = 0x7F;
        s->p7C[m->sub.cur] = 1;
        sys->a4[sys->mgr->sub.cur] = a;
        sys->a8[sys->mgr->sub.cur] = key;
        {
            sSnd5D08Sys* s2 = D_004A36F8_5D08;
            s2->mgr->sub.tgt[s2->mgr->sub.cur] = &found->grp->vec;
            sSnd5D08Mgr* m2 = s2->mgr;
            sSnd5D08Sub* ss = &m2->sub;
            ss->vals[m2->sub.cur] = found->v4;
            ss->ch[m2->sub.cur].vol = SND_5D08_MAX(0, SND_5D08_MIN(ss->vals[ss->cur], 0x7F));
        }
        {
            sSnd5D08Mgr* m2 = D_004A36F8_5D08->mgr;
            m2->sub.p3C[m2->sub.cur] = self->f17C;
        }
        {
            sSnd5D08Mgr* m2 = D_004A36F8_5D08->mgr;
            m2->sub.p74[m2->sub.cur] = 1;
        }
        {
            sSnd5D08Mgr* m2 = D_004A36F8_5D08->mgr;
            m2->sub.p64[m2->sub.cur] = self->f0;
        }
        {
            sSnd5D08Mgr* m2 = D_004A36F8_5D08->mgr;
            sSndKey8_5D08 k = D_004A3700_5D08[0];
            sSnd5D08Sub* s4 = &m2->sub;
            *(sSndKey8_5D08*)((char*)s4 + (m2->sub.cur << 3) + 0x40) = k;
        }
        {
            sSnd5D08Mgr* m2 = D_004A36F8_5D08->mgr;
            m2->sub.p60[m2->sub.cur] = (int)self;
        }
        {
            sSnd5D08Mgr* m2 = D_004A36F8_5D08->mgr;
            m2->sub.p7C[m2->sub.cur] = 0;
        }
        found->grp->handle = func_002906B8(D_004A36F8_5D08);
    }
    return idx;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A62F0);
#ifdef SKIP_ASM
extern char** D_004A36F8;

struct sSsVoice62F0 { int f0; int id; int refs; };
struct sSsEnt62F0 { int active; int f4; sSsVoice62F0* v; };
struct sSsMgr62F0 {
    int f0;
    char pad4[0x20 - 0x4];
    sSsEnt62F0 ent[15];         // 0x20
    int nactive;                // 0xD4
    char padD8[0x170 - 0xD8];
    int nvoices;                // 0x170
    int id;                     // 0x174
    int f178;                   // 0x178
    int f17C;
    int state;                  // 0x180
    int f184;
    float vol;                  // 0x188
    int f18C;                   // 0x18C
};

extern "C" void func_002A62F0(void* vself, int idx, float fade)
{
    sSsMgr62F0* self = (sSsMgr62F0*)vself;
    if (idx < 0) return;
    if (self->ent[idx].active == 0) return;
    sSsVoice62F0* v = self->ent[idx].v;
    self->nactive--;
    self->ent[idx].active = 0;
    self->ent[idx].v = 0;
    if (--v->refs == 0) {
        if (v->id >= 0) {
            func_002AD5F0(*D_004A36F8 + 0x1D8, v->id, 1, fade);
        }
        v->id = -1;
        v->f0 = -1;
        self->f18C = 0;
        self->nvoices--;
    }
    if (self->nactive != 0) return;
    if (self->vol > 0.25f) self->vol = 0.25f;
    if (self->id >= 0) {
        if (fade == 0.0f) {
            func_002AD5F0(*D_004A36F8 + 0x1D8, self->id, 2, fade);
        }
        self->id = -1;
        if (self->state == 2) self->state = 1;
    }
    self->f178 = 0;
    self->f0 = -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A6430);
#ifdef SKIP_ASM
extern "C" void func_002A62F0(void* voice, int b, float v);

extern "C" void func_002A6430(void* self, float v)
{
    for (int i = 0; i < 15; i++) {
        if (*(int*)((char*)self + 0x20 + i * 0xC) != 0) {
            func_002A62F0(self, i, v);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A64A0);
#ifdef SKIP_ASM
extern "C" void func_002A6848(void* self);
extern "C" int func_002A4CA0(sSndRandList* list);
extern "C" void func_002A8450(char** sys, int a, int b);
extern "C" int func_002A86B8(char** sys);
extern char** D_004A36F8;

struct sSnd64A0Ent {
    char pad0[0x48];
    float a;
    float b;
    char pad50[4];
};
struct sSnd64A0Sys {
    char pad0[0x1C];
    sSnd64A0Ent ent[1];
};
struct sSnd64A0Ch {
    unsigned char vol;
    char pad1[0x17];
};

#define S64_MIN(a, b) ((a) < (b) ? (a) : (b))
#define S64_MAX(a, b) ((a) >= (b) ? (a) : (b))

struct sSnd64A0Sub {
    char pad0[0x1C];
    volatile int cur;   // 0x1C
    sSnd64A0Ch* ch;     // 0x20
    void* tgt[5];       // 0x24
    int* vals;          // 0x38
    int* p3C;           // 0x3C
    char pad40[0x64 - 0x40];
    int* p64;           // 0x64
    char pad68[0x74 - 0x68];
    int* p74;           // 0x74
    void setVal(int i, int v) {
        vals[i] = v;
    }
    void update(int i) {
        ch[i].vol = S64_MAX(S64_MIN(vals[cur], 0x7F), 0);
    }
};
struct sSnd64A0Mgr {
    char pad0[0x1D8];
    sSnd64A0Sub sub;    // 0x1D8
};

extern "C" void func_002A64A0(void* vself, int idx)
{
    char* self = (char*)vself;
    func_002A6848(self);
    if (*(int*)(self + 0xD4) == 0) return;
    sSnd64A0Ent* e = &((sSnd64A0Sys*)D_004A36F8)->ent[idx];
    *(int*)(self + 0x184) = idx;
    *(float*)(self + 0x188) = e->a + e->b;
    int r = func_002A4CA0((sSndRandList*)e);
    if (r == 0) return;
    func_002A8450(D_004A36F8, *(int*)(self + 0xD8), r);
    sSnd64A0Mgr* m1 = *(sSnd64A0Mgr**)D_004A36F8;
    m1->sub.tgt[m1->sub.cur] = self + 0x10;
    sSnd64A0Mgr* m2 = *(sSnd64A0Mgr**)D_004A36F8;
    m2->sub.setVal(m2->sub.cur, *(int*)(self + 0x178));
    m2->sub.update(m2->sub.cur);
    sSnd64A0Mgr* m3 = *(sSnd64A0Mgr**)D_004A36F8;
    m3->sub.p3C[m3->sub.cur] = *(int*)(self + 0x17C);
    sSnd64A0Mgr* m4 = *(sSnd64A0Mgr**)D_004A36F8;
    m4->sub.p74[m4->sub.cur] = 1;
    sSnd64A0Mgr* m5 = *(sSnd64A0Mgr**)D_004A36F8;
    m5->sub.p64[m5->sub.cur] = *(int*)self;
    *(int*)(self + 0x174) = func_002A86B8(D_004A36F8);
    *(int*)(self + 0x18C) = idx + 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A6648);
#ifdef SKIP_ASM
extern "C" void func_002A6848(void* self);
extern "C" int func_002A4CA0(sSndRandList* list);
extern "C" void func_002A8450(char** sys, int a, int b);
extern "C" int func_002A86B8(char** sys);
extern char** D_004A36F8;

struct sSnd6648Ent {
    char pad0[0x48];
    float a;
    float b;
    char pad50[4];
};
struct sSnd6648Sys {
    char pad0[0x1C];
    sSnd6648Ent ent[1];
};
struct sSnd6648Ch {
    unsigned char vol;
    char pad1[0x17];
};

#define S66_MIN(a, b) ((a) < (b) ? (a) : (b))
#define S66_MAX(a, b) ((a) >= (b) ? (a) : (b))

struct sSnd6648Sub {
    char pad0[0x1C];
    volatile int cur;   // 0x1C
    sSnd6648Ch* ch;     // 0x20
    void* tgt[5];       // 0x24
    int* vals;          // 0x38
    int* p3C;           // 0x3C
    char pad40[0x64 - 0x40];
    int* p64;           // 0x64
    char pad68[0x74 - 0x68];
    int* p74;           // 0x74
    void setVal(int i, int v) {
        vals[i] = v;
    }
    void update(int i) {
        ch[i].vol = S66_MAX(S66_MIN(vals[cur], 0x7F), 0);
    }
};
struct sSnd6648Mgr {
    char pad0[0x1D8];
    sSnd6648Sub sub;    // 0x1D8
};

extern "C" void func_002A6648(void* vself, int idx)
{
    char* self = (char*)vself;
    func_002A6848(self);
    if (*(int*)(self + 0xD4) == 0) return;
    sSnd6648Ent* e = &((sSnd6648Sys*)D_004A36F8)->ent[idx];
    *(int*)(self + 0x184) = idx;
    *(float*)(self + 0x188) = e->a + e->b;
    int r = func_002A4CA0((sSndRandList*)((char*)e + 0x18));
    if (r == 0) return;
    func_002A8450(D_004A36F8, *(int*)(self + 0xD8), r);
    sSnd6648Mgr* m1 = *(sSnd6648Mgr**)D_004A36F8;
    m1->sub.tgt[m1->sub.cur] = self + 0x10;
    sSnd6648Mgr* m2 = *(sSnd6648Mgr**)D_004A36F8;
    m2->sub.setVal(m2->sub.cur, *(int*)(self + 0x178));
    m2->sub.update(m2->sub.cur);
    sSnd6648Mgr* m3 = *(sSnd6648Mgr**)D_004A36F8;
    m3->sub.p3C[m3->sub.cur] = *(int*)(self + 0x17C);
    sSnd6648Mgr* m4 = *(sSnd6648Mgr**)D_004A36F8;
    m4->sub.p74[m4->sub.cur] = 1;
    sSnd6648Mgr* m5 = *(sSnd6648Mgr**)D_004A36F8;
    m5->sub.p64[m5->sub.cur] = *(int*)self;
    *(int*)(self + 0x174) = func_002A86B8(D_004A36F8);
    *(int*)(self + 0x18C) = ~idx;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A67F0);
#ifdef SKIP_ASM
extern "C" void func_002A67F0(void* self)
{
    if (*(int*)((char*)self + 0x180) == 0) {
        *(int*)((char*)self + 0x180) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A6808);
#ifdef SKIP_ASM
extern "C" void func_002A6848(void* self);

extern "C" void func_002A6808(void* self)
{
    if (*(int*)((char*)self + 0x180) == 2) {
        func_002A6848(self);
    }
    *(int*)((char*)self + 0x180) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A6848);
#ifdef SKIP_ASM
extern "C" void func_002AD5F0(void* p, int idx, int a2, float v);
extern char** D_004A36F8;

extern "C" void func_002A6848(void* self)
{
    float lim = 0.25f;
    if (lim < *(float*)((char*)self + 0x188)) {
        *(float*)((char*)self + 0x188) = lim;
    }
    *(int*)((char*)self + 0x180) = 0;
    if (*(int*)((char*)self + 0x174) >= 0) {
        func_002AD5F0(*D_004A36F8 + 0x1D8, *(int*)((char*)self + 0x174), 2, 0.0f);
        *(int*)((char*)self + 0x174) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A69A0);
#ifdef SKIP_ASM
extern "C" void* func_002ADE88(void* self, int heap);
extern "C" void* cBankManager_cBankManager(void* self, int embedded, int count, int heap);
extern "C" char* func_002A8140(char* self, int embedded, int count, int heap);
extern "C" void* func_002A4BA8(void* self);

struct sSnd69VtEnt {
    short delta;
    short index;
    void* fn;
};
struct sSnd69Vt4 {
    sSnd69VtEnt e[4];
} __attribute__((aligned(8)));
struct sSnd69Vt7 {
    sSnd69VtEnt e[7];
} __attribute__((aligned(8)));

struct sSnd69List {
    char pad0[0x18];
    sSnd69List() { func_002A4BA8(this); }
};
struct sSnd69Ent {
    sSnd69List a;
    sSnd69List b;
    sSnd69List c;
    float f48;
    float f4C;
    int f50;
    void* operator new[](unsigned int, void* p) { return p; }
};

extern char D_004837F8[];
extern char D_00483B48[];
extern const sSnd69Vt4 D_00483818_69 __asm__("D_00483818");
extern const sSnd69Vt7 D_00483838_69 __asm__("D_00483838");


// PORT: hand-expanded g++ 2.95 virtual-base ctor (vtable upcast-offset fixup on stack copies).
extern "C" char* func_002A69A0(char* self, int embedded, int count, int unused, int heap)
{
    if (embedded) {
        char* mon = self + 0x118;
        *(char**)self = self + 0x120;
        *(char**)(self + 0x2F8) = mon;
        func_002ADE88(mon, heap);
        cBankManager_cBankManager(*(void**)self, 0, count, heap);
    }
    func_002A8140(self, 0, count, heap);
    *(const void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &D_00483818_69;
    *(void**)(*(char**)self + 0xAB0) = D_00483B48;
    *(const void**)(*(char**)self + 0x1D4) = &D_00483838_69;
    if (!embedded) {
        sSnd69Vt4 t1 = D_00483818_69;
        *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &t1;
        char* c1 = *(char**)(*(char**)self + 0x1D8) - 0x118;
        int adj1 = self - c1;
        t1.e[1].delta = D_00483818_69.e[1].delta + adj1;
        sSnd69Vt7 t2 = D_00483838_69;
        *(void**)(*(char**)self + 0x1D4) = &t2;
        char* c2 = *(char**)self - 0x120;
        int adj2 = self - c2;
        t2.e[1].delta = D_00483838_69.e[1].delta + adj2;
    }
    *(void**)(self + 0xC) = D_004837F8;
    *(int*)(self + 0x14) = 0;
    *(int*)(self + 0x18) = 0;
    new (self + 0x1C) sSnd69Ent[3];
    D_004A36F8 = (char**)self;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A6B50);
#ifdef SKIP_ASM
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
void operator_delete(int*);
extern "C" void func_002A4BE0(void* self, int flags);
struct sSsMgr6F38;
extern "C" void func_002A6F38(sSsMgr6F38* self);
extern "C" void func_002A82D8(char* self, int flags);

struct sSnd6BVtEnt {
    short delta;
    short index;
    void* fn;
};
struct sSnd6BVt4 {
    sSnd6BVtEnt e[4];
} __attribute__((aligned(8)));
struct sSnd6BVt7 {
    sSnd6BVtEnt e[7];
} __attribute__((aligned(8)));

extern char D_004837F8[];
extern char D_00483B48[];
extern const sSnd6BVt4 D_00483818_6B __asm__("D_00483818");
extern const sSnd6BVt7 D_00483838_6B __asm__("D_00483838");

// PORT: hand-expanded g++ 2.95 virtual-base dtor (vtable upcast-offset fixup on stack copies).
extern "C" void func_002A6B50(char* self, int flags)
{
    *(void**)(self + 0xC) = D_004837F8;
    *(const void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &D_00483818_6B;
    *(void**)(*(char**)self + 0xAB0) = D_00483B48;
    *(const void**)(*(char**)self + 0x1D4) = &D_00483838_6B;
    if (flags == 0) {
        sSnd6BVt4 t1 = D_00483818_6B;
        *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &t1;
        char* c1 = *(char**)(*(char**)self + 0x1D8) - 0x118;
        int adj1 = self - c1;
        t1.e[1].delta = D_00483818_6B.e[1].delta + adj1;
        sSnd6BVt7 t2 = D_00483838_6B;
        *(void**)(*(char**)self + 0x1D4) = &t2;
        char* c2 = *(char**)self - 0x120;
        int adj2 = self - c2;
        t2.e[1].delta = D_00483838_6B.e[1].delta + adj2;
    }
    func_002A6F38((sSsMgr6F38*)self);
    D_004A36F8 = 0;
    if (self + 0x1C != 0) {
        char* p = self + 0x1C + 3 * 0x54;
        while (self + 0x1C != p) {
            p -= 0x54;
            func_002A4BE0(p + 0x30, 2);
            func_002A4BE0(p + 0x18, 2);
            func_002A4BE0(p, 2);
        }
    }
    func_002A82D8(self, 0);
    if (flags & 2) {
        func_0028BB10(*(void**)self, 0);
        func_002ADEE8(*(void**)(*(char**)self + 0x1D8), 0);
    }
    if (flags & 1) operator_delete((int*)self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A6D18);
#ifdef SKIP_ASM
extern "C" void func_002A4E88(void* voice);

extern "C" void func_002A6D18(void* self)
{
    for (int i = 0; i < *(int*)((char*)self + 0x14); i++) {
        func_002A4E88((char*)*(void**)((char*)self + 0x18) + i * 0x190);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A6D78);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_002A4CF8(void*);
struct sSndFileBuf;
extern "C" sSndFileBuf* func_002A77F8(sSndFileBuf* self, const char* name, int flags);
extern "C" int func_002A7BF8(void* self, const char* name);
extern "C" void func_002A7040(void* self, void* parser);
extern "C" void func_002A7890(void* self, int flags);
extern const char D_00483108[];
extern const char D_004A3570[];

struct sSnd6D78Voice : public func_002A4D68_sObj {
    void operator delete[](void* p, unsigned int size);
};
struct sSnd6D78List {
    char pad0[0x18];
};
struct sSnd6D78Ent {
    sSnd6D78List a;
    sSnd6D78List b;
    sSnd6D78List c;
    float f48;
    float f4C;
    int f50;
};
struct sSnd6D78Self {
    char pad0[0x14];
    int count;                  // 0x14
    sSnd6D78Voice* voices;      // 0x18
    sSnd6D78Ent ent[3];         // 0x1C
};
struct sSnd6D78Parser {
    int size;
    char* data;
    char* cur;
    char token[0x800];
};

extern "C" void func_002A6D78(sSnd6D78Self* self, const char* name, const char* key, int n, int v)
{
    self->count = n;
    sSnd6D78Voice*& slot = self->voices;
    slot = new (D_00483108, 0, 0) sSnd6D78Voice[n];
    for (int i = 0; i < 3; i++) {
        self->ent[i].f48 = 0.0f;
        self->ent[i].f4C = 0.0f;
        self->ent[i].f50 = 0;
        func_002A4CF8(&self->ent[i].c);
        func_002A4CF8(&self->ent[i].b);
        func_002A4CF8(&self->ent[i].a);
    }
    for (int i = 0; i < n; i++) {
        self->voices[i].fD8 = v;
    }
    sSnd6D78Parser p;
    func_002A77F8((sSndFileBuf*)&p, name, 0x100);
    p.cur = p.data;
    if (func_002A7BF8(&p, D_004A3570)) func_002A7040(self, &p);
    p.cur = p.data;
    if (func_002A7BF8(&p, key)) func_002A7040(self, &p);
    func_002A7890(&p, 2);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A6F38);
#ifdef SKIP_ASM
extern "C" void func_002A7718(void* self);
extern "C" void func_002A4E38(void* p, int flags);

struct sSsChan6F38 {
    char a[0x18];               // 0x00
    char b[0x18];               // 0x18
    char c[0x18];               // 0x30
    int f48;
    int f4C;
    int f50;
};
struct sSsMgr6F38 {
    char pad0[0x14];
    int count;                  // 0x14
    char* arr;                  // 0x18
    sSsChan6F38 chans[3];       // 0x1C
};

extern "C" void func_002A6F38(sSsMgr6F38* self)
{
    func_002A7718(self);
    char* base = self->arr;
    if (base != 0) {
        char* p = base + *(int*)(base - 0x10) * 0x190;
        while (self->arr != p) {
            p -= 0x190;
            func_002A4E38(p, 0);
        }
        cMemMan_free(self->arr - 0x10);
        self->arr = 0;
        self->count = 0;
    }
    for (int i = 0; i < 3; i++) {
        self->chans[i].f48 = 0;
        self->chans[i].f4C = 0;
        self->chans[i].f50 = 0;
        func_002A4CF8(self->chans[i].c);
        func_002A4CF8(self->chans[i].b);
        func_002A4CF8(self->chans[i].a);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A7040);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_002A7F90(void* self);
extern "C" int func_002A7FF8(void* self, const char* name, char* out);
extern "C" int func_002A8070(void* self, const char* name, float* out);
// func_002A7DA0 returns the token buffer (the unit declares it void elsewhere).
extern "C" const char* func_002A7DA0_s(void* self) __asm__("func_002A7DA0");
extern const char D_004A3708[];
extern const char D_004A3710[];
extern const char D_00483118[];
extern const char D_00483128[];
extern const char D_004A3718[];
extern const char D_00483138[];

extern "C" void func_002A7040(void* self, void* parser)
{
    sSnd6D78Self* s = (sSnd6D78Self*)self;
    char val[0x200];
    char key[0x200];
    while (!func_002A7F90(parser)) {
        const char* name = func_002A7DA0_s(parser);
        for (int i = 0; i < 3; i++) {
            sprintf(key, D_004A3708, i + 1);
            if (func_0041AA88(name, key) == 0) {
                func_002A7FF8(parser, name, val);
                func_002A4C28((sSndHandleList5*)&s->ent[i].a, (int)val, 0);
                break;
            }
            sprintf(key, D_004A3710, i + 1);
            if (func_0041AA88(name, key) == 0) {
                func_002A7FF8(parser, name, val);
                func_002A4C28((sSndHandleList5*)&s->ent[i].b, (int)val, 0);
                break;
            }
            sprintf(key, D_00483118, i + 1);
            if (func_0041AA88(name, key) == 0) {
                func_002A7FF8(parser, name, val);
                func_002A4C28((sSndHandleList5*)&s->ent[i].c, (int)val, 0);
                break;
            }
            sprintf(key, D_00483128, i + 1);
            if (func_0041AA88(name, key) == 0) {
                func_002A8070(parser, name, &s->ent[i].f48);
                break;
            }
            sprintf(key, D_004A3718, i + 1);
            if (func_0041AA88(name, key) == 0) {
                func_002A8070(parser, name, &s->ent[i].f4C);
                break;
            }
            sprintf(key, D_00483138, i + 1);
            if (func_0041AA88(name, key) == 0) {
                func_002A8070(parser, name, (float*)&s->ent[i].f50);
                break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A72C0);
#ifdef SKIP_ASM
extern "C" void func_002A72C0(void* self, int a1, int* a2, int* a3)
{
    *a2 = a1 & 0xff;
    *a3 = a1 >> 8;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A72D8);
#ifdef SKIP_ASM
extern "C" void func_002A62F0(void* voice, int b, float v);

extern "C" void func_002A72D8(void* self, int id, float v)
{
    if (id >= 0 && *(void**)((char*)self + 0x18) != 0) {
        int a;
        int b;
        func_002A72C0(self, id, &a, &b);
        func_002A62F0((char*)*(void**)((char*)self + 0x18) + a * 0x190, b, v);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7340);
#ifdef SKIP_ASM
extern "C" void func_002A7340(void* self, int id, int v)
{
    if (id >= 0 && *(void**)((char*)self + 0x18) != 0) {
        int a;
        int b;
        func_002A72C0(self, id, &a, &b);
        func_002A5CD8((s2A5CD8*)((char*)*(void**)((char*)self + 0x18) + a * 0x190), b, v);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A73A8);
#ifdef SKIP_ASM
extern "C" void func_002A64A0(void* voice, int a1);

struct sSndVoice190 {
    char data[0x190];
};

extern "C" void func_002A73A8(void* self, int a1, int i)
{
    sSndVoice190* v = *(sSndVoice190**)((char*)self + 0x18);
    if (v != 0) {
        func_002A64A0(&v[i], a1);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A73D8);
#ifdef SKIP_ASM
extern "C" void func_002A6648(void* voice, int a1);

extern "C" void func_002A73D8(void* self, int a1, int i)
{
    sSndVoice190* v = *(sSndVoice190**)((char*)self + 0x18);
    if (v != 0) {
        func_002A6648(&v[i], a1);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7408);
#ifdef SKIP_ASM
extern "C" void func_002A67F0(void* voice);

extern "C" void func_002A7408(void* self, int i)
{
    sSndVoice190* v = *(sSndVoice190**)((char*)self + 0x18);
    if (v != 0) {
        func_002A67F0(&v[i]);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7438);
#ifdef SKIP_ASM
extern "C" void func_002A6808(void* voice);

extern "C" void func_002A7438(void* self, int i)
{
    sSndVoice190* v = *(sSndVoice190**)((char*)self + 0x18);
    if (v != 0) {
        func_002A6808(&v[i]);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A7468);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);

struct sSnd7468Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd7468Env {
    int a;
    int b;
    int c;
    int d;
};
struct sSnd7468Pair {
    int a;
    int b;
};
struct sSnd7468Sub {
    char pad0[0x4];
    sSnd7468Ch def;         // 0x04
    volatile int cur;       // 0x1C
    sSnd7468Ch* ch;         // 0x20
    void* tgt[4];           // 0x24
    int* p34;               // 0x34
    int* vals;              // 0x38
    int* p3C;               // 0x3C
    sSnd7468Pair pr[4];     // 0x40
    int* p60;               // 0x60
    int* p64;               // 0x64
    int* p68;               // 0x68
    int* p6C;               // 0x6C
    sSnd7468Env* env;       // 0x70
    int* p74;               // 0x74
    int* p78;               // 0x78
    int* p7C;               // 0x7C
    int* p80;               // 0x80
    int* p84;               // 0x84
};
struct sSnd7468Mgr {
    char pad0[0x1D8];
    sSnd7468Sub sub;        // 0x1D8
};

extern "C" void func_002A7468(char** sys)
{
    sSnd7468Mgr* m = *(sSnd7468Mgr**)sys;
    sSnd7468Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = s->def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->env[m->sub.cur].b = 0;
    s->env[m->sub.cur].a = 100;
    s->env[m->sub.cur].c = 90;
    s->env[m->sub.cur].d = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7678);
#ifdef SKIP_ASM
extern "C" int func_002A5D08(void* voice, void* bank, int a1);

extern "C" int func_002A7678(void* self, int a1)
{
    sSndVoice190* v = *(sSndVoice190**)((char*)self + 0x18);
    if (v == 0) {
        return -1;
    }
    char* p = *(char**)self + 0x1D8;
    int r = func_002A5D08(&v[(*(int**)(p + 0x64))[*(int*)(p + 0x1C)]], p, a1);
    if (r >= 0) {
        char* q = *(char**)self + 0x1D8;
        r = (r << 8) | (*(int**)(q + 0x64))[*(int*)(q + 0x1C)];
    }
    (*(int*)(*(char**)self + 0x1F4))--;
    return r;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A7718);

//100%
INCLUDE_ASM("sound/soundsys", func_002A77C8);
#ifdef SKIP_ASM
struct s2A77C8Item {
    char pad[0x18C];
    int value;
};

extern "C" int func_002A77C8(void* self, int i)
{
    if (i < *(int*)((char*)self + 0x14)) {
        return (*(s2A77C8Item**)((char*)self + 0x18))[i].value;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A77F8);
#ifdef SKIP_ASM
extern "C" int func_00317F98(const char* name);
extern "C" int func_003E1B68(const char* name, void* buf, int size);
// PORT: operator_new__FUi really takes (size, tag, flags, d), like cMemMan_alloc.
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

struct sSndFileBuf {
    int size;
    char* data;
    char* cur;
};

extern "C" sSndFileBuf* func_002A77F8(sSndFileBuf* self, const char* name, int flags)
{
    self->data = 0;
    self->cur = 0;
    self->size = func_00317F98(name);
    if (self->size != 0) {
        self->data = (char*)operator_new_tag(self->size + 1, name, flags, 0);
        func_003E1B68(name, self->data, self->size + 1);
        self->cur = self->data;
        self->data[self->size] = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A7890);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);

extern "C" void func_002A7890(void* self, int flags)
{
    void* p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        cMemMan_free(p);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A78E0__FPv);
#ifdef SKIP_ASM
signed char func_002A78E0(void* self)
{
    return *(*(signed char**)((char*)self + 0x8))++;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A78F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
signed char func_002A78E0(void* self);
extern "C" int func_002A79C8(void* self);

// func_002A78F8 returns int (its body leaves a result in v0); the unit declares it void.
int func_002A78F8_r(void*) __asm__("func_002A78F8");

int func_002A78F8_r(void* self)
{
    while (**(signed char**)((char*)self + 0x8) != 0) {
        if (func_002A79C8(self) == 1) return 1;
        signed char c = **(signed char**)((char*)self + 0x8);
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r') {
            int r = 0;
            if (c == '[') r = 1;
            return r;
        }
        func_002A78E0(self);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A79C8);
#ifdef SKIP_ASM
extern "C" int func_002A7A90(void* self);

extern "C" int func_002A79C8(void* self)
{
    signed char c = **(signed char**)((char*)self + 0x8);
    if (c != 0) {
        if (c == '#' || c == ';') {
            int r = func_002A7A90(self);
            if (r != 0) {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7A20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_002A78F8 returns int (its body leaves a result in v0); the unit declares it void.
int func_002A78F8_r(void*) __asm__("func_002A78F8");
extern "C" char* func_002A7B08(void*);
extern "C" int func_002A7F90(void*);

extern "C" void func_002A7A20(void* self)
{
    func_002A78F8_r(self);
    while (**(signed char**)((char*)self + 0x8) == '[') {
        func_002A7B08(self);
        func_002A78F8_r(self);
    }
    func_002A7F90(self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7A90);
#ifdef SKIP_ASM
extern "C" int func_002A7A90(void* self)
{
    while (**(signed char**)((char*)self + 0x8) != 0) {
        signed char c = **(signed char**)((char*)self + 0x8);
        if (c == '\r') {
            return 0;
        }
        if (c == '\n') {
            return 0;
        }
        func_002A78E0(self);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A7B08);
#ifdef SKIP_ASM
signed char func_002A78E0(void* self);
extern "C" int func_002A79C8(void* self);
extern "C" int func_002A7EF0(void* self, const char* s);
extern const char D_004A3720[];

extern "C" char* func_002A7B08(void* self)
{
    while (**(signed char**)((char*)self + 0x8) != 0) {
        func_002A79C8(self);
        if (func_002A78E0(self) == '[') {
            int n = 0;
            if (**(signed char**)((char*)self + 0x8) != ']') {
                do {
                    char* dst = (char*)self + 0xC;
                    dst[n] = func_002A78E0(self);
                    n++;
                } while (**(signed char**)((char*)self + 0x8) != ']');
            }
            if (func_002A7EF0(self, D_004A3720) == 0) {
                char* buf = (char*)self + 0xC;
                buf[n] = 0;
                return buf;
            }
            break;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A7BF8);
#ifdef SKIP_ASM
extern "C" char* func_002A7B08(void*);
extern "C" int func_0041AA88(const char* a, const char* b);

extern "C" int func_002A7BF8(void* self, const char* name)
{
    char* s;
    while (**(signed char**)((char*)self + 0x8) != 0 && (s = func_002A7B08(self)) != 0) {
        if (func_0041AA88(s, name) == 0) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A7C68);
#ifdef SKIP_ASM
extern "C" char* func_002A7B08(void*);
extern "C" char* func_0041AD80(const char* s, const char* sub);

extern "C" int func_002A7C68(void* self, char* name)
{
    char* tok;
    while (**(char**)((char*)self + 0x8) != 0 && (tok = func_002A7B08(self)) != 0) {
        if (func_0041AD80(name, tok) == name || func_0041AD80(tok, name) == tok) {
            return 1;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7CF0);
#ifdef SKIP_ASM
signed char func_002A78E0(void* self);
extern "C" void func_002A78F8(void*);
extern "C" int func_002A7EF0(void* self, const char* s);
extern const char D_004A3728[];

extern "C" char* func_002A7CF0(void* self)
{
    int n = 0;
    func_002A78F8(self);
    func_002A7EF0(self, D_004A3728);
    if (**(signed char**)((char*)self + 0x8) != '"') {
        char* dst = (char*)self + 0xC;
        do {
            dst[n] = func_002A78E0(self);
            n++;
        } while (**(signed char**)((char*)self + 0x8) != '"');
    }
    func_002A7EF0(self, D_004A3728);
    char* buf = (char*)self + 0xC;
    buf[n] = 0;
    return buf;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A7DA0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7E60);
#ifdef SKIP_ASM
extern "C" void func_002A78F8(void*);
extern "C" void func_002A7DA0(void*);
extern "C" int func_004178B0(const char* s, const char* fmt, ...);
extern char D_004A3730[];

extern "C" float func_002A7E60(void* self)
{
    float f;
    func_002A78F8(self);
    func_002A7DA0(self);
    func_004178B0((char*)self + 0xC, D_004A3730, &f);
    return f;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7EA8);
#ifdef SKIP_ASM
extern "C" void func_002A78F8(void*);
extern "C" void func_002A7DA0(void*);
extern "C" int func_004178B0(const char* s, const char* fmt, ...);
extern char D_004A3738[];

extern "C" int func_002A7EA8(void* self)
{
    int v;
    func_002A78F8(self);
    func_002A7DA0(self);
    func_004178B0((char*)self + 0xC, D_004A3738, &v);
    return v;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7EF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
signed char func_002A78E0(void* self);
int func_002A78F8_r(void*) __asm__("func_002A78F8");

extern "C" int func_002A7EF0(void* self, const char* name)
{
    int i = 0;
    func_002A78F8_r(self);
    while (**(char**)((char*)self + 0x8) != 0 && name[i] != 0) {
        if (func_002A78E0(self) != name[i]) {
            return 1;
        }
        i++;
    }
    return name[i];
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7F90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_002A78F8_r(void*) __asm__("func_002A78F8");

extern "C" int func_002A7F90(void* self)
{
    if (*(char**)((char*)self + 0x8) - *(char**)((char*)self + 0x4) >= *(int*)((char*)self + 0x0)) {
        return 1;
    }
    func_002A78F8_r(self);
    signed char c = **(signed char**)((char*)self + 0x8);
    int r = 0;
    if (c == 0 || c == '[') {
        r = 1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A7FF8);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_002A7EF0(void* self, const char* s);
extern "C" char* func_002A7CF0(void* self);
extern "C" char* strcpy(char* dst, const char* src);
extern char D_004A3740[];

extern "C" int func_002A7FF8(void* self, const char* name, char* out)
{
    if (func_0041AA88((char*)self + 0xC, name) != 0) {
        return 0;
    }
    if (func_002A7EF0(self, D_004A3740) != 0) {
        return 0;
    }
    char* s = func_002A7CF0(self);
    if (s == 0) {
        return 0;
    }
    strcpy(out, s);
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A8070);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_002A7EF0(void* self, const char* s);
extern "C" float func_002A7E60(void* self);
extern char D_004A3740[];

extern "C" int func_002A8070(void* self, const char* name, float* out)
{
    if (func_0041AA88((char*)self + 0xC, name) != 0) {
        return 0;
    }
    if (func_002A7EF0(self, D_004A3740) != 0) {
        return 0;
    }
    *out = func_002A7E60(self);
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A80D8);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_002A7EF0(void* self, const char* s);
extern "C" int func_002A7EA8(void* self);
extern char D_004A3740[];

extern "C" int func_002A80D8(void* self, const char* name, int* out)
{
    if (func_0041AA88((char*)self + 0xC, name) != 0) {
        return 0;
    }
    if (func_002A7EF0(self, D_004A3740) != 0) {
        return 0;
    }
    *out = func_002A7EA8(self);
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A8140);
#ifdef SKIP_ASM
extern "C" void* func_002ADE88(void* self, int heap);
extern "C" void* cBankManager_cBankManager(void* self, int embedded, int count, int heap);
extern "C" char* cBankSys_cBankSys(char* self, int embedded, int count, int heap);
extern "C" void func_003B97D8();
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

struct sSndCtVtEnt {
    short delta;
    short index;
    void* fn;
};
struct sSndCtVt4 {
    sSndCtVtEnt e[4];
} __attribute__((aligned(8)));
struct sSndCtVt7 {
    sSndCtVtEnt e[7];
} __attribute__((aligned(8)));

extern char D_00483A48[];
extern char D_00483B48[];
extern const char D_00483148[];
extern const sSndCtVt4 D_004839F0_ct __asm__("D_004839F0");
extern const sSndCtVt7 D_00483A10_ct __asm__("D_00483A10");
extern int D_004A3744;

// PORT: hand-expanded g++ 2.95 virtual-base ctor (vtable upcast-offset fixup on stack copies).
extern "C" char* func_002A8140(char* self, int embedded, int count, int heap)
{
    if (embedded) {
        char* mon = self + 0x14;
        *(char**)self = self + 0x1C;
        *(char**)(self + 0x1F4) = mon;
        func_002ADE88(mon, heap);
        cBankManager_cBankManager(*(void**)self, 0, count, heap);
    }
    cBankSys_cBankSys(self, 0, count, heap);
    *(const void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &D_004839F0_ct;
    *(void**)(*(char**)self + 0xAB0) = D_00483B48;
    *(const void**)(*(char**)self + 0x1D4) = &D_00483A10_ct;
    if (!embedded) {
        sSndCtVt4 t1 = D_004839F0_ct;
        *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &t1;
        char* c1 = *(char**)(*(char**)self + 0x1D8) - 0x14;
        int adj1 = self - c1;
        t1.e[1].delta = D_004839F0_ct.e[1].delta + adj1;
        sSndCtVt7 t2 = D_00483A10_ct;
        *(void**)(*(char**)self + 0x1D4) = &t2;
        char* c2 = *(char**)self - 0x1C;
        int adj2 = self - c2;
        t2.e[1].delta = D_00483A10_ct.e[1].delta + adj2;
    }
    *(void**)(self + 0xC) = D_00483A48;
    func_003B97D8();
    *(void**)(self + 0x10) = new (D_00483148, 0, 0) char[0x20] ;
    D_004A3744 = (int)self;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A82D8);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern "C" void func_0028FEA0(char* self, int flags);
extern "C" void func_003B9880();

struct sSndDtBVtEnt {
    short delta;
    short index;
    void* fn;
};
struct sSndDtBVt4 {
    sSndDtBVtEnt e[4];
} __attribute__((aligned(8)));
struct sSndDtBVt7 {
    sSndDtBVtEnt e[7];
} __attribute__((aligned(8)));

extern char D_00483A48[];
extern const sSndDtBVt4 D_004839F0;
extern const sSndDtBVt7 D_00483A10;
extern char D_00483B48[];
extern int D_004A3744;

// PORT: hand-expanded g++ 2.95 virtual-base dtor (vtable upcast-offset fixup on stack copies).
extern "C" void func_002A82D8(char* self, int flags)
{
    *(void**)(self + 0xC) = D_00483A48;
    *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = (void*)&D_004839F0;
    *(void**)(*(char**)self + 0xAB0) = D_00483B48;
    *(void**)(*(char**)self + 0x1D4) = (void*)&D_00483A10;
    if (flags == 0) {
        sSndDtBVt4 t1 = D_004839F0;
        *(void**)(*(char**)(*(char**)self + 0x1D8) + 4) = &t1;
        char* c1 = *(char**)(*(char**)self + 0x1D8) - 0x14;
        int adj1 = self - c1;
        t1.e[1].delta = D_004839F0.e[1].delta + adj1;
        sSndDtBVt7 t2 = D_00483A10;
        *(void**)(*(char**)self + 0x1D4) = &t2;
        char* c2 = *(char**)self - 0x1C;
        int adj2 = self - c2;
        t2.e[1].delta = D_00483A10.e[1].delta + adj2;
    }
    if (*(void**)(self + 0x10)) cMemMan_free(*(void**)(self + 0x10));
    D_004A3744 = 0;
    func_003B9880();
    func_0028FEA0(self, 0);
    if (flags & 2) {
        func_0028BB10(*(void**)self, 0);
        func_002ADEE8(*(void**)(*(char**)self + 0x1D8), 0);
    }
    if (flags & 1) operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A8450);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);

struct sSnd8450Ch {
    signed char vol;
    char pad1[0x17];
};
struct sSnd8450E8 {
    int a;
    int b;
};
struct sSnd8450E16 {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct sSnd8450Sub {
    char pad0[4];
    sSnd8450Ch def;          // 0x04
    volatile int cur;        // 0x1C
    sSnd8450Ch* ch;          // 0x20
    void* tgt[4];            // 0x24
    int* p34;                // 0x34
    int* vals;               // 0x38
    int* p3C;                // 0x3C
    sSnd8450E8 e40[4];       // 0x40
    int* p60;                // 0x60
    int* p64;                // 0x64
    int* p68;                // 0x68
    int* p6C;                // 0x6C
    sSnd8450E16* p70;        // 0x70
    int* p74;                // 0x74
    int* p78;                // 0x78
    int* p7C;                // 0x7C
    int* p80;                // 0x80
    int* p84;                // 0x84
};
struct sSnd8450Mgr {
    char pad0[0x1D8];
    sSnd8450Sub sub;         // 0x1D8
};
struct sSnd8450Sys {
    sSnd8450Mgr* mgr;
    char pad4[0xC];
    sSnd8450E8* e10;         // 0x10
};

extern "C" void func_002A8450(char** sys, int a, int b)
{
    sSnd8450Sys* self = (sSnd8450Sys*)sys;
    sSnd8450Mgr* m = self->mgr;
    sSnd8450Sub* s = &m->sub;
    m->sub.cur++;
    s->ch[m->sub.cur] = m->sub.def;
    m->sub.tgt[m->sub.cur] = 0;
    s->p34[m->sub.cur] = 0;
    s->vals[m->sub.cur] = s->ch[m->sub.cur].vol;
    s->p3C[m->sub.cur] = 0;
    func_00416210((char*)s + m->sub.cur * 8 + 0x40, 0, 8);
    s->p60[m->sub.cur] = 0;
    s->p64[m->sub.cur] = 0;
    s->p68[m->sub.cur] = 0;
    s->p6C[m->sub.cur] = 0;
    s->p70[m->sub.cur].f4 = 0;
    s->p70[m->sub.cur].f0 = 100;
    s->p70[m->sub.cur].f8 = 90;
    s->p70[m->sub.cur].fC = 50;
    s->p74[m->sub.cur] = 0;
    s->p80[m->sub.cur] = 0;
    s->p84[m->sub.cur] = 0;
    s->p78[m->sub.cur] = 0x7F;
    s->p7C[m->sub.cur] = 1;
    self->e10[self->mgr->sub.cur].a = a;
    self->e10[self->mgr->sub.cur].b = b;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A86B8);

//100%
INCLUDE_ASM("sound/soundsys", func_002A8C20);
#ifdef SKIP_ASM
extern char D_004835F8[];

extern "C" void* func_002A8C20(void* self)
{
    *(void**)self = D_004835F8;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x30C) = -1;
    *(int*)((char*)self + 0x310) = -1;
    *(int*)((char*)self + 0x31C) = 0;
    *(int*)((char*)self + 0x318) = -1;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A8C50);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);

extern "C" void func_002A8C50(void* self, int flags)
{
    *(void**)self = D_004835F8;
    void* p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        cMemMan_free(p);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A8CB0);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d), like cMemMan_alloc.
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_003B5478();
extern "C" void func_003B5158(void* buf, int size, int flags);
extern "C" int func_003B5B68(int* out);
extern const char D_00483158[];

struct sSndVtE8CB0 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sSndVoice8CB0 {
    int idx;
    int a;
    int b;
    int c;
    int d;
    int next;
};

struct sSndSys8CB0 {
    sSndVtE8CB0* vt;            // 0x0
    void* buf;                  // 0x4
    int pad_8;                  // 0x8
    sSndVoice8CB0 voices[32];   // 0xC
    int f30C;                   // 0x30C
    int freeHead;               // 0x310
    int pad_314;                // 0x314
    int f318;                   // 0x318
    int f31C;                   // 0x31C
};

extern "C" void func_002A8CB0(sSndSys8CB0* self, int a1)
{
    self->buf = operator_new_tag(0x32000, D_00483158, 0, 0);
    func_003B5478();
    sSndVtE8CB0* vt = self->vt;
    vt[2].fn((char*)self + vt[2].delta, a1);
    func_003B5158(self->buf, 0x32000, 0x80303);
    self->freeHead = 31;
    self->f318 = -1;
    for (int i = 31; i >= 0; i--) {
        self->voices[i].idx = i;
        self->voices[i].a = -1;
        self->voices[i].b = -1;
        self->voices[i].c = 0;
        self->voices[i].d = 0;
        self->voices[i].next = i - 1;
    }
    self->f31C = 0;
    int t = 0;
    int r = func_003B5B68(&t);
    self->f30C = t + r;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A8D90);
#ifdef SKIP_ASM
extern "C" void func_003B4DD8(void* cfg);
extern "C" void func_003B4FC0(void* cfg);
extern "C" void func_003BC930();

struct sSnd8D90Cfg {
    char pad0[0x28];
    short f28;
    unsigned short f2A;
    short f2C;
    unsigned char f2E;
    unsigned char f2F;
    unsigned char f30;
    char pad31[0x3F - 0x31];
    unsigned char f3F;
    unsigned char f40;
    unsigned char f41;
    char pad42[0x47 - 0x42];
    unsigned char f47;
    char pad48;
    unsigned char f49;
    char pad4A[0x4C - 0x4A];
    unsigned char f4C;
    char pad4D;
    short f4E;
    short f50;
    short f52;
    short f54;
    short f56;
    short f58;
    char pad5A[0xE0 - 0x5A];
};

extern "C" int func_002A8D90(char* self, int mode)
{
    sSnd8D90Cfg cfg;
    func_003B4DD8(&cfg);
    cfg.f2A = 36000;
    cfg.f2C = 24000;
    cfg.f3F = 0;
    cfg.f40 = 50;
    cfg.f41 = 50;
    cfg.f28 = 20;
    switch (mode) {
    case 3:
        if (*(int*)(self + 8) == 1) return 1;
        cfg.f2E = 0x10;
        cfg.f2F = 8;
        cfg.f30 = 0x18;
        cfg.f47 = 4;
        cfg.f4C = 3;
        cfg.f4E = 0x28;
        cfg.f50 = 0x120;
        cfg.f52 = 0x24;
        cfg.f49 = 2;
        func_003BC930();
        *(int*)(self + 8) = 2;
        break;
    case 2:
        if (*(int*)(self + 8) == 2) return 1;
        cfg.f2E = 0x10;
        cfg.f2F = 8;
        cfg.f30 = 0x30;
        cfg.f49 = 1;
        cfg.f47 = 2;
        cfg.f4C = 6;
        cfg.f4E = 0x48;
        cfg.f50 = 0x140;
        cfg.f52 = 0x44;
        cfg.f54 = 0x28;
        cfg.f56 = 0x120;
        cfg.f58 = 0x24;
        *(int*)(self + 8) = 1;
        break;
    case 0:
    case 1:
        if (*(int*)(self + 8) == 2) return 1;
        cfg.f2E = 0x10;
        cfg.f2F = 8;
        cfg.f30 = 0x30;
        cfg.f49 = 1;
        cfg.f47 = 2;
        cfg.f4C = 3;
        cfg.f4E = 0x28;
        cfg.f50 = 0x120;
        cfg.f52 = 0x24;
        *(int*)(self + 8) = 1;
        break;
    }
    func_003B4FC0(&cfg);
    return 2;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A8F50);
#ifdef SKIP_ASM
extern "C" void func_003B5B20(int a, int b);
extern "C" void func_003B5320();
void cMemMan_free(void*);

extern "C" void func_002A8F50(void* self)
{
    void* p;
    func_003B5B20(-1, -1);
    func_003B5320();
    p = *(void**)((char*)self + 0x4);
    if (p != 0) {
        cMemMan_free(p);
    }
    *(void**)((char*)self + 0x4) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/soundsys", func_002A8FA0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002A8C20(void* self);
extern const char D_00483168[];

extern "C" void* func_002A8FA0()
{
    return func_002A8C20(cMemMan_alloc(0x320, D_00483168, 0, 0));
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A8FD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003B5B20(int a, int b);
extern "C" int func_003B5B68(int* out);
// The unit defines func_002A92B8 with its own entry/pool view types; bind this unit's struct view.
sSndVoice8CB0* func_002A92B8_v(sSndSys8CB0* self) __asm__("func_002A92B8");

extern "C" int func_002A8FD8(sSndSys8CB0* self, int size)
{
    int i = self->f318;
    if (i >= 0) {
        sSndVoice8CB0* prev = 0;
        sSndVoice8CB0* b = &self->voices[i];
        for (;;) {
            if (b->c == size) {
                b->d = 2;
                if (prev) {
                    prev->next = b->next;
                }
                b->next = -1;
                return b->idx;
            }
            if (size < b->c) {
                sSndVoice8CB0* n = func_002A92B8_v(self);
                int top = b->b;
                n->d = 2;
                n->next = -1;
                n->b = top;
                n->a = top - size;
                n->c = size;
                b->b = top - size;
                b->c -= size;
                return n->idx;
            }
            if (b->next < 0) break;
            prev = b;
            b = &self->voices[b->next];
        }
    }
    int avail = 0;
    if (func_003B5B68(&avail) < size) {
        return -1;
    }
    if (self->f31C != 0) {
        return -2;
    }
    sSndVoice8CB0* n = func_002A92B8_v(self);
    int top = self->f30C;
    n->d = 2;
    n->a = top - size;
    n->next = -1;
    n->b = top;
    n->c = size;
    func_003B5B20(-1, self->f30C -= size);
    return n->idx;
}
#endif

INCLUDE_ASM("sound/soundsys", func_002A9128);

//100%
INCLUDE_ASM("sound/soundsys", func_002A9250);
#ifdef SKIP_ASM
extern "C" void func_003B5B20(int a, int b);

struct sSndPoolEntry2A9250 {
    int unk0;
    int unk4;
    int unk8;
    char pad[0x14 - 0xC];
    int next;
};

struct sSndPool2A9250 {
    char pad[0xC];
    sSndPoolEntry2A9250 entries[32];
    int unk30C;
    int freeHead;
    char pad2[0x31C - 0x314];
    int unk31C;
};

extern "C" void func_002A9250(sSndPool2A9250* self, int i)
{
    self->unk31C = 1;
    sSndPoolEntry2A9250* e = &self->entries[i];
    func_003B5B20(e->unk4, e->unk8);
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A9288);
#ifdef SKIP_ASM
extern "C" void func_003B5B20(int a, int b);

extern "C" void func_002A9288(void* self)
{
    func_003B5B20(-1, *(int*)((char*)self + 0x30C));
    *(int*)((char*)self + 0x31C) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A92B8);
#ifdef SKIP_ASM
struct s2A92B8Entry {
    char pad[0x14];
    int next;
};

struct s2A92B8 {
    char pad[0xC];
    s2A92B8Entry entries[32];
    int unk30C;
    int freeHead;
};

extern "C" s2A92B8Entry* func_002A92B8(s2A92B8* self)
{
    int i = self->freeHead;
    if (i < 0) {
        return 0;
    }
    s2A92B8Entry* e = &self->entries[i];
    self->freeHead = e->next;
    e->next = -1;
    return e;
}
#endif

//100%
INCLUDE_ASM("sound/soundsys", func_002A92F8);
#ifdef SKIP_ASM
extern "C" void func_003B5B20(int a, int b);

struct s2A92F8Entry {
    int index;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int next;
};

extern "C" void func_002A92F8(void* self, s2A92F8Entry* e)
{
    *(int*)((char*)self + 0x30C) = e->unk8;
    e->unk4 = -1;
    e->unk8 = -1;
    e->unkC = 0;
    e->unk10 = 0;
    e->next = *(int*)((char*)self + 0x310);
    *(int*)((char*)self + 0x310) = e->index;
    if (*(int*)((char*)self + 0x31C) == 0) {
        func_003B5B20(-1, *(int*)((char*)self + 0x30C));
    }
}
#endif

