#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cWorldTriggerManager_cWorldTriggerManager(void* self);
extern const char D_00483588[];
extern void* D_004A52D4;

//99.88%
INCLUDE_ASM("sound/icepick/worldtriggermanager", WORLDTRIGGERMANAGER_Init__Fv);
#ifdef SKIP_ASM
void WORLDTRIGGERMANAGER_Init()
{
    if (D_004A52D4 == 0) {
        void* mem = cMemMan_alloc(0x344, D_00483588, 0, 0);
        D_004A52D4 = cWorldTriggerManager_cWorldTriggerManager(mem);
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B4B48);
#ifdef SKIP_ASM
extern "C" void func_002B5988(char** self, int flags);

extern "C" void func_002B4B48()
{
    if (D_004A52D4 != 0) {
        func_002B5988((char**)D_004A52D4, 3);
    }
    D_004A52D4 = 0;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B4B70);
#ifdef SKIP_ASM
extern unsigned char D_004A35A8[];

extern "C" void* func_002B4B70(void* self)
{
    *(int*)((char*)self + 0x30) = -1;
    *(float*)((char*)self + 0x2C) = 1.0f;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x34) = 0;
    *(int*)((char*)self + 0x38) = 0;
    *(unsigned char*)((char*)self + 0x40) = D_004A35A8[0];
    *(float*)((char*)self + 0x68) = -1.0f;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x6C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B4BE0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_002B4BE0(int* self, int flags)
{
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B4C08);
#ifdef SKIP_ASM
extern "C" int func_002B4C08(void* self, int a1, int a2, int a3)
{
    if (a1 == *(int*)((char*)self + 0x4)
        && a2 == *(int*)((char*)self + 0x8)
        && a3 == *(int*)((char*)self + 0x3c)) {
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B4C38);

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5758);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_002A72D8(void* snd, int id, float t);
extern "C" void func_002AD5F0(void* self, int idx, int a2, float v);
extern unsigned char D_004A35A8[];
struct sWorldTrigger70;

extern "C" void func_002B5758(sWorldTrigger70* t)
{
    char* self = (char*)t;
    if (*(int*)((char*)self + 0x38) != 0) {
        if (*(int*)((char*)self + 0x30) != -9999) {
            func_002A72D8(func_0028B180(), *(int*)((char*)self + 0x30), 0.25f);
        }
    } else if (*(int*)((char*)self + 0x30) != -9999) {
        func_002AD5F0(**(char***)((char*)func_0028B180() + 0x118) + 0x1D8, *(int*)((char*)self + 0x30), 1, 0.25f);
    }
    *(int*)((char*)self + 0x30) = -1;
    *(unsigned char*)((char*)self + 0x40) = D_004A35A8[0];
    *(float*)((char*)self + 0x68) = -1.0f;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x6C) = 0;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5818);
#ifdef SKIP_ASM
extern "C" int func_002B63D0(void* self, int idx, int* type, int* a, int* b, int c, int d);

extern "C" int func_002B5818(void* self, int idx, int* type, int* a, int* b, int c, int d)
{
    return func_002B63D0(D_004A52D4, idx, type, a, b, c, d);
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5838);
#ifdef SKIP_ASM
extern "C" int func_002B63D0(void* self, int idx, int* type, int* a, int* b, int c, int d);

extern "C" int func_002B5838(void* self, int idx)
{
    int type;
    int a;
    int b;
    func_002B63D0(D_004A52D4, idx, &type, &a, &b, 0, 1);
    return type == 5;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5878);
#ifdef SKIP_ASM
extern "C" int func_002B65B0(void* self, int idx, char* dst);

extern "C" int func_002B5878(void* self, int idx, char* dst)
{
    return func_002B65B0(D_004A52D4, idx, dst);
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5898);
#ifdef SKIP_ASM
extern unsigned char D_004A35A8[];

extern "C" void func_002B5898(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x30) = -1;
    *(int*)((char*)self + 0x34) = 0;
    *(unsigned char*)((char*)self + 0x40) = D_004A35A8[0];
    *(float*)((char*)self + 0x68) = -1.0f;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x6c) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/icepick/worldtriggermanager", cWorldTriggerManager_cWorldTriggerManager);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* func_002B4B70(void* self);
extern "C" void cWorldTriggerManager_LoadTriggerInfo(void* self);
extern const char D_004835A0[];

struct sWorldTrigger58D0 {
    char pad[0x70];
};

extern "C" void* cWorldTriggerManager_cWorldTriggerManager(void* self)
{
    *(int*)((char*)self + 0x324) = 0;
    *(int*)((char*)self + 0x330) = 0;
    *(int*)((char*)self + 0x328) = -1;
    *(int*)((char*)self + 0x32C) = -1;
    *(int*)((char*)self + 0x334) = 1;
    int* mem = (int*)operator_new_tag(0x1190, D_004835A0, 0, 0);
    mem[0] = 40;
    sWorldTrigger58D0* arr = (sWorldTrigger58D0*)((char*)mem + 0x10);
    sWorldTrigger58D0* p = arr;
    for (int i = 39; i != -1; i--, p++) {
        func_002B4B70(p);
    }
    *(sWorldTrigger58D0**)self = arr;
    *(int*)((char*)self + 0x338) = 0;
    cWorldTriggerManager_LoadTriggerInfo(self);
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5988);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);

extern "C" void func_002B5988(char** self, int flags)
{
    char* base = *self;
    if (base != 0) {
        char* p = base + *(int*)(base - 0x10) * 0x70;
        while (*self != p) {
            p -= 0x70;
            func_002B4BE0((int*)p, 0);
        }
        cMemMan_free(*self - 0x10);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", cWorldTriggerManager_LoadTriggerInfo);
#ifdef SKIP_ASM
extern "C" int BXFILE_exists(const char* name);
extern "C" char* func_003E22F0(const char* name, int a1);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char* D_004A3858;
extern char D_004835C0[];

struct sTrigInfoEnt { int type; int* data; };

// PORT: the unit declares LoadTriggerInfo as void (the ctor ignores it); the body returns 0/1. Bound by asm label.
int cWorldTriggerManager_LoadTriggerInfo_impl(void* self) __asm__("cWorldTriggerManager_LoadTriggerInfo");

int cWorldTriggerManager_LoadTriggerInfo_impl(void* self)
{
    if (BXFILE_exists(D_004A3858) != 0) {
        char* data = func_003E22F0(D_004A3858, 0);
        *(char**)((char*)self + 0x338) = data;
        if (*data != 0) {
            return 0;
        }
        *(int*)((char*)self + 0x340) = *(int*)(data + 8) + 2;
        *(sTrigInfoEnt**)((char*)self + 0x33C) = (sTrigInfoEnt*)operator_new_tag(*(int*)((char*)self + 0x340) * 8, D_004835C0, 0, 0);
        int* p = (int*)(data + 0xC);
        for (int i = 2; i < *(int*)((char*)self + 0x340); i++) {
            (*(sTrigInfoEnt**)((char*)self + 0x33C))[i].type = *p;
            (*(sTrigInfoEnt**)((char*)self + 0x33C))[i].data = p;
            int t = *p;
            if (t == 1) {
                p += 6;
            } else if (t == 2) {
                p += 14;
            } else if (t == 3) {
                p += 12;
            } else if (t == 4) {
                p += 4;
            }
        }
    } else {
        *(char**)((char*)self + 0x338) = 0;
        *(int*)((char*)self + 0x340) = 0;
        *(sTrigInfoEnt**)((char*)self + 0x33C) = 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5B90);
#ifdef SKIP_ASM
struct sWorldTrigger70 {
    int active;
    char pad[0x30];
    int unk34;
    char pad2[0x38];
};

extern "C" sWorldTrigger70* func_002B5B90(sWorldTrigger70** self)
{
    for (int i = 0; i < 40; i++) {
        if ((*self)[i].active == 0) {
            return &(*self)[i];
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5BC0);
#ifdef SKIP_ASM
extern "C" int func_002B4C08(void* self, int a1, int a2, int a3);

extern "C" sWorldTrigger70* func_002B5BC0(sWorldTrigger70** self, int a, int b, int c)
{
    for (int i = 0; i < 40; i++) {
        if ((*self)[i].active != 0 && func_002B4C08(&(*self)[i], a, b, c)) {
            return &(*self)[i];
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5C68);
#ifdef SKIP_ASM
struct sWtVec3 { float x, y, z; };
struct sWtVec4 {
    float x, y, z, w;
    sWtVec4() {}
    sWtVec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

extern "C" void func_002B5C68(sWorldTrigger70** self, int a, int b, int c, int d, int e, float f, const sWtVec3& pos)
{
    sWtVec3 p = pos;
    if (*(int*)((char*)self + 0x334) != 0) {
        char* t = (char*)func_002B5BC0(self, a, b, c);
        if (t == 0) {
            sWtVec4 q;
            q = sWtVec4(p.x, p.y, p.z, 1.0f);
            t = (char*)func_002B5B90(self);
            *(int*)(t + 0x0) = 1;
            *(int*)(t + 0x4) = a;
            *(int*)(t + 0x8) = b;
            *(int*)(t + 0x3C) = c;
            *(int*)(t + 0xC) = d;
            *(float*)(t + 0x10) = f;
            *(int*)(t + 0x14) = e;
            *(sWtVec4*)(t + 0x20) = q;
        } else {
            *(float*)(t + 0x10) = f;
        }
        *(int*)(t + 0x34) = 1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5D78);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" int func_004165A8(const void* a, const void* b);
// PORT: func_0029B960__FPv is an empty stub whose caller passes (mgr, name).
void func_0029B960_2(void* mgr, void* name) __asm__("func_0029B960__FPv");
extern "C" void func_002B4C38(sWorldTrigger70* t);
extern "C" void func_002B5758(sWorldTrigger70* t);
extern unsigned char D_004A35A8[];

extern "C" void func_002B5D78(sWorldTrigger70** self)
{
    if (*(int*)((char*)func_0028B180() + 0x5FB0) != 0) return;
    for (int i = 0; i < 40; i++) {
        if ((*self)[i].active == 1) {
            if ((*self)[i].unk34 == 0) {
                if (func_004165A8((char*)&(*self)[i] + 0x40, D_004A35A8)) {
                    // PORT: pointer arithmetic through int
                    func_0029B960_2(func_0028B180(), (char*)(i * 0x70 + *(int*)self) + 0x40);
                }
                (*self)[i].active = 0;
                func_002B5758(&(*self)[i]);
            } else {
                func_002B4C38(&(*self)[i]);
            }
            (*self)[i].unk34 = 0;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5E68);
#ifdef SKIP_ASM
extern "C" void func_002B5758(sWorldTrigger70* t);

extern "C" void func_002B5E68(void* self)
{
    for (int i = 0; i < 40; i++) {
        if ((*(sWorldTrigger70**)self)[i].active == 1) {
            (*(sWorldTrigger70**)self)[i].active = 0;
            func_002B5758(&(*(sWorldTrigger70**)self)[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B5F60);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" int func_002B63D0(void* self, int idx, int* type, int* a, int* b, int c, int d);
extern "C" int func_002B6740(void* self, void* obj);
struct sTriggerIdCache;
extern "C" void func_002B6868(sTriggerIdCache* self, int id);
extern "C" int func_00287968(void* self, int a1, int a2);
extern "C" int func_00288A20(void* self, void* rider);
extern "C" int func_002906B8(void* self);
extern "C" void* func_00416210(void* dst, int c, int n);

struct sWtEnt5F60 {
    signed char b0;
    char pad1[3];
    int f4[5];
};

struct sWtPair5F60 {
    int a;
    int b;
};

struct sWtV16_5F60 {
    int f0;
    int f4;
    int f8;
    int fC;
};

struct sWtSub5F60 {
    int f0;
    sWtEnt5F60 cfg;         // 0x04
    volatile int cur;       // 0x1C (re-read after every store and twice back-to-back: volatile)
    sWtEnt5F60* ents;       // 0x20
    int arr24[4];           // 0x24
    int* p34;               // 0x34
    int* p38;               // 0x38
    int* p3C;               // 0x3C
    sWtPair5F60 arr40[4];   // 0x40
    int* p60;               // 0x60
    int* p64;               // 0x64
    int* p68;               // 0x68
    int* p6C;               // 0x6C
    sWtV16_5F60* p70;       // 0x70
    int* p74;               // 0x74
    int* p78;               // 0x78
    int* p7C;               // 0x7C
    int* p80;               // 0x80
    int* p84;               // 0x84
};

struct sWtTrack5F60 {
    char pad0[0x1D8];
    sWtSub5F60 sub;         // 0x1D8
};

struct sWtSnd5F60 {
    sWtTrack5F60* track;    // 0x0
    int* types;             // 0x4
    int* args;              // 0x8
    char pad[0x10C];
    sWtTrack5F60** cur;     // 0x118
};

#define MIN_5F60(a, b) ((a) < (b) ? (a) : (b))
#define MAX_5F60(a, b) ((a) < (b) ? (b) : (a))

extern "C" int func_002B5F60(char* self, void* evt, int id, char* rider, int vol)
{
    if (*(int*)(*(char**)(self + 0x33C) + id * 8) == 3)
        return -1;
    if (evt != 0)
    {
        if (evt != *(void**)(self + 0x328))
        {
            if (func_002B6740(self, evt))
                func_002B6868((sTriggerIdCache*)self, (int)evt);
        }
        *(void**)(self + 0x328) = evt;
    }
    int type, a, b;
    if (func_002B63D0(self, id, &type, &a, &b, 1, 0) != 0 && b == 0)
    {
        sWtSnd5F60* snd = (sWtSnd5F60*)func_0028B180();
        int tp = type;
        int ar = a;
        sWtTrack5F60* t = snd->track;
        sWtSub5F60* s = &t->sub;
        t->sub.cur++;
        s->ents[t->sub.cur] = s->cfg;
        t->sub.arr24[t->sub.cur] = 0;
        s->p34[t->sub.cur] = 0;
        s->p38[t->sub.cur] = s->ents[t->sub.cur].b0;
        s->p3C[t->sub.cur] = 0;
        func_00416210((char*)s + t->sub.cur * 8 + 0x40, 0, 8);
        s->p60[t->sub.cur] = 0;
        s->p64[t->sub.cur] = 0;
        s->p68[t->sub.cur] = 0;
        s->p6C[t->sub.cur] = 0;
        s->p70[t->sub.cur].f4 = 0;
        s->p70[t->sub.cur].f0 = 100;
        s->p70[t->sub.cur].f8 = 90;
        s->p70[t->sub.cur].fC = 50;
        s->p74[t->sub.cur] = 0;
        s->p80[t->sub.cur] = 0;
        s->p84[t->sub.cur] = 0;
        s->p78[t->sub.cur] = 0x7F;
        s->p7C[t->sub.cur] = 1;
        snd->types[snd->track->sub.cur] = tp;
        snd->args[snd->track->sub.cur] = ar;
        {
            sWtTrack5F60* t2 = *((sWtSnd5F60*)func_0028B180())->cur;
            sWtSub5F60* s2 = &t2->sub;
            s2->p38[t2->sub.cur] = vol;
            s2->ents[t2->sub.cur].b0 = MAX_5F60(MIN_5F60(s2->p38[s2->cur], 0x7F), 0);
        }
        {
            sWtTrack5F60** pt = ((sWtSnd5F60*)func_0028B180())->cur;
            int h = func_00287968(func_0028B180(), 7, 0);
            (*pt)->sub.p3C[(*pt)->sub.cur] = h;
        }
        if (rider != 0)
        {
            sWtTrack5F60* t3 = *((sWtSnd5F60*)func_0028B180())->cur;
            t3->sub.arr24[t3->sub.cur] = (int)(rider + 0x110);
            sWtTrack5F60** pt = ((sWtSnd5F60*)func_0028B180())->cur;
            int h = func_00288A20(func_0028B180(), rider);
            (*pt)->sub.p64[(*pt)->sub.cur] = h;
            sWtTrack5F60* t4 = *((sWtSnd5F60*)func_0028B180())->cur;
            t4->sub.p34[t4->sub.cur] = 1;
        }
        return func_002906B8(func_0028B180());
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B63D0);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" int func_002ADF60(int a);
extern "C" int func_002B6550(void* self, int type, int* a, int* b, int* c, int arg);

struct sWTMObj {
    char pad0[0x10];
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int pad30;
    int f34;
};

struct sWTMEntry {
    int type;
    sWTMObj* obj;
};

extern "C" int func_002B63D0(void* self, int idx, int* type, int* a, int* b, int c, int d)
{
    *b = 0;
    if (idx >= *(int*)((char*)self + 0x340)) {
        *type = 0;
        *a = 0;
        return 0;
    }
    int r = 1;
    int t = (*(sWTMEntry**)((char*)self + 0x33C))[idx].type;
    if (t == 3) {
        *type = t;
        *a = 0;
    } else if (t == 1) {
        *type = (*(sWTMEntry**)((char*)self + 0x33C))[idx].obj->f10;
        *a = (*(sWTMEntry**)((char*)self + 0x33C))[idx].obj->f14;
    } else if (t == 2) {
        *type = (*(sWTMEntry**)((char*)self + 0x33C))[idx].obj->f10;
        void* p = func_0028B180();
        int rnd = func_002ADF60(*(int*)(*(char**)*(void**)((char*)p + 0x118) + 0x1D8));
        sWTMObj* o = (*(sWTMEntry**)((char*)self + 0x33C))[idx].obj;
        int v = (unsigned)((rnd & 0x7FFF) * o->f34) / 0x7FFF;
        if (v < o->f24) *a = o->f14;
        else if (v < o->f28 + o->f24) *a = o->f18;
        else if (v < o->f2C + o->f28 + o->f24) *a = o->f1C;
        else *a = o->f20;
    } else if (d == 0) {
        r = func_002B6550(self, idx, type, a, b, c);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6550);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" int func_002A34D0(void* mgr, int a1, int a2, int a3);

extern "C" int func_002B6550(void* self, int type, int* a, int* b, int* c, int arg)
{
    int r = 0;
    *a = 0;
    *b = 0;
    *c = 0;
    if (type == 0x4D) {
        *c = 1;
        r = func_002A34D0(func_0028B180(), 0, 1, arg);
    }
    return r;
}
#endif

INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B65B0);

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6628__FPv);
#ifdef SKIP_ASM
int func_002B6628(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6630);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const void* a, const void* b);
extern unsigned char D_004A35A8[];

extern "C" int func_002B6630(sWorldTrigger70** self, int id)
{
    int n = 0;
    for (int i = 0; i < 40; i++) {
        if ((*self)[i].active == 1 && func_004165A8((char*)&(*self)[i] + 0x40, D_004A35A8)) {
            if (*(int*)((char*)&(*self)[i] + 0xC) != id) n++;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B66E8);
#ifdef SKIP_ASM
extern "C" int func_002B66E8(sWorldTrigger70** self, int a1, int a2, sWorldTrigger70* except)
{
    for (int i = 0; i < 40; i++) {
        sWorldTrigger70* t = &(*self)[i];
        if (t->active == 1 && t != except
            && *(int*)((char*)t + 0x4) == a1
            && *(int*)((char*)t + 0x8) == a2) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6740);
#ifdef SKIP_ASM
extern "C" void* func_0028B1C8(void);
extern "C" void func_002B8190(void* self, void* obj, int* o0, int* o1, int* o2, int* o3);
extern "C" int func_002B67D8(void* self, unsigned int i);

extern "C" int func_002B6740(void* self, void* obj)
{
    int ids[4];
    func_002B8190(*(void**)((char*)func_0028B1C8() + 0x4C), obj, &ids[0], &ids[1], &ids[2], &ids[3]);
    if (func_002B67D8(self, ids[0])) {
        return 1;
    }
    if (func_002B67D8(self, ids[1])) {
        return 1;
    }
    if (func_002B67D8(self, ids[2])) {
        return 1;
    }
    return func_002B67D8(self, ids[3]) != 0;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B67D8);
#ifdef SKIP_ASM
struct sTriggerRef {
    int id;
    void* obj;
};

extern "C" int func_002B67D8(void* self, unsigned int i)
{
    if (i < 2) {
        return 0;
    }
    sTriggerRef* refs = *(sTriggerRef**)((char*)self + 0x33c);
    return *(int*)((char*)refs[i].obj + 0x4) == 1;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6808);
#ifdef SKIP_ASM
struct sTriggerIdCache {
    int unk0;
    int ids[200];       // 0x4
    int count;          // 0x324
    int unk328;
    int lastId;         // 0x32C
    int lastResult;     // 0x330
};

extern "C" int func_002B6808(sTriggerIdCache* self, int id)
{
    if (id == self->lastId) {
        return self->lastResult;
    }
    int i = self->count - 1;
    self->lastId = id;
    for (; i >= 0; i--) {
        if (self->ids[i] == id) {
            self->lastResult = 1;
            return 1;
        }
    }
    self->lastResult = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6868);
#ifdef SKIP_ASM
extern "C" void func_002B6868(sTriggerIdCache* self, int id)
{
    if (func_002B6808(self, id) == 0) {
        if (self->count < 200) {
            self->ids[self->count] = id;
            self->count++;
        }
        self->lastId = -1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B68D0);
#ifdef SKIP_ASM
extern "C" void func_002B5E68(void* self);
void func_002B6900(void* self);

extern "C" void func_002B68D0(void* self)
{
    func_002B5E68(self);
    func_002B6900(self);
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6900__FPv);
#ifdef SKIP_ASM
void func_002B6900(void* self)
{
    *(int*)((char*)self + 0x330) = 0;
    *(int*)((char*)self + 0x324) = 0;
    *(int*)((char*)self + 0x328) = -1;
    *(int*)((char*)self + 0x32c) = -1;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6988);
#ifdef SKIP_ASM
extern "C" int func_002B6988(void* self, unsigned int i)
{
    if (i < 2) {
        return 0;
    }
    sTriggerRef* refs = *(sTriggerRef**)((char*)self + 0x33c);
    return *(int*)((char*)refs[i].obj + 0x8) == 1;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B69B8);
#ifdef SKIP_ASM
struct sWtmVEntryF {
    short delta;
    short index;
    float (*fn)(void*);
};

extern "C" int func_002B69B8(void* self, void* src, void* state)
{
    void* obj = *(void**)((char*)src + 0xC);
    if (obj == 0) {
        return 0;
    }
    float prev = *(float*)((char*)state + 0x68);
    sWtmVEntryF* vt = *(sWtmVEntryF**)((char*)obj + 0xC);
    float cur = vt[30].fn((char*)obj + vt[30].delta);
    int below = cur < prev;
    int r = *(int*)((char*)state + 0x6C) != 0 && !below;
    *(float*)((char*)state + 0x68) = cur;
    *(int*)((char*)state + 0x6C) = below;
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6A68);
#ifdef SKIP_ASM
extern "C" void func_002B6A68(sWorldTrigger70** self)
{
    for (int i = 0; i < 40; i++) {
        if ((*self)[i].active == 1) {
            (*self)[i].unk34 = 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6AA0);
#ifdef SKIP_ASM
struct sQuad6AA0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern sQuad6AA0 D_004FF120;

struct sTriggerSlot120 {
    int unk0;
    char pad[0x10c];
    sQuad6AA0 q;        // 0x110
};

struct sTriggerSlots {
    sTriggerSlot120 slots[2];
};

extern "C" sTriggerSlots* func_002B6AA0(sTriggerSlots* self)
{
    sTriggerSlot120* p = self->slots;
    for (int i = 1; i != -1; i--, p++) {
        p->unk0 = 0;
        p->q = D_004FF120;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6AE0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_002B6AE0(int* self, int flags)
{
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6B08);
#ifdef SKIP_ASM
extern "C" void func_002B6B50(void*);

extern "C" int func_002B6B08(void* self, int a1)
{
    if (a1 != 0) {
        func_002B6B50(self);
    }
    return 1;
}
#endif

extern "C" void func_002B6C20(void*);

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6B30);
#ifdef SKIP_ASM
extern "C" void func_002B6B30(void* self, int a1)
{
    if (a1 != 0) {
        func_002B6C20(self);
    }
}
#endif

INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6B50);

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6C20);
#ifdef SKIP_ASM
struct sWtmEnt18 {
    char pad[0xC];
    int active;
    char pad2[0x8];
};
struct sWtmEntList {
    char pad[0xC];
    int count;
    sWtmEnt18 entries[1];
};
extern "C" void func_002B7410(void* self, sWtmEnt18* e);

// PORT: the unit declares func_002B6C20 as void(void*); its callers pass a1 through.
int func_002B6C20_impl(void* self, sWtmEntList* list) __asm__("func_002B6C20");

int func_002B6C20_impl(void* self, sWtmEntList* list)
{
    int n = list->count;
    sWtmEnt18* entries = list->entries;
    for (int i = 0; i < n; i++) {
        sWtmEnt18* e = &entries[i];
        if (e->active != 0) {
            func_002B7410(self, e);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6C90);
#ifdef SKIP_ASM
struct sTriggerEntry18 {
    int unk0;
    int unk4;
    int unk8;
    int active;
    void* unk10;
    int unk14;
};

extern "C" void func_002B7318(void* self, sTriggerEntry18* e);

extern "C" int func_002B6C90(void* self, int a1, sTriggerEntry18* entries, int n)
{
    for (int i = 0; i < n; i++) {
        if (entries[i].active != 0) {
            func_002B7318(self, &entries[i]);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6CF8);
#ifdef SKIP_ASM
struct sWtmEnt18;

struct sVec3_2B6CF8 {
    float x, y, z;
    sVec3_2B6CF8() {}
    sVec3_2B6CF8(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

extern "C" void func_002B6F40(void* self, int* shape, sVec3_2B6CF8* lo, sVec3_2B6CF8* hi);

extern "C" void func_002B6CF8(void* self, sWtmEnt18* e, sVec3_2B6CF8* lo, sVec3_2B6CF8* hi)
{
    *lo = sVec3_2B6CF8(10000.0f, 10000.0f, 10000.0f);
    *hi = sVec3_2B6CF8(-10000.0f, -10000.0f, -10000.0f);
    int* info = *(int**)((char*)e + 0x10);
    char* base = (char*)(info + 2);
    char* p = base + info[0] * 4;
    for (int i = 0; i < info[1]; i++) {
        sVec3_2B6CF8 a;
        sVec3_2B6CF8 b;
        func_002B6F40(self, (int*)p, &a, &b);
        if (a.x < lo->x) lo->x = a.x;
        if (a.y < lo->y) lo->y = a.y;
        if (a.z < lo->z) lo->z = a.z;
        if (b.x > hi->x) hi->x = b.x;
        if (b.y > hi->y) hi->y = b.y;
        if (b.z > hi->z) hi->z = b.z;
        switch (*(int*)p) {
        case 0:
            p += 0x1C;
            break;
        case 1:
            p += 0x30;
            break;
        case 2:
            p += 0x30;
            break;
        case 3:
            p += 0x18;
            break;
        }
    }
    char* obj = *(char**)((char*)e + 0xC);
    lo->x += *(float*)(obj + 0x40);
    lo->y += *(float*)(obj + 0x44);
    lo->z += *(float*)(obj + 0x48);
    hi->x += *(float*)(obj + 0x40);
    hi->y += *(float*)(obj + 0x44);
    hi->z += *(float*)(obj + 0x48);
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B6F40);
#ifdef SKIP_ASM
// PORT: sqrt.s (sqrtf without errno check)
static inline float wtSqrt_2B6F40(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

static inline sVec3_2B6CF8 operator*(const sVec3_2B6CF8& v, float s)
{
    return sVec3_2B6CF8(v.x * s, v.y * s, v.z * s);
}

static inline sVec3_2B6CF8 operator+(const sVec3_2B6CF8& a, const sVec3_2B6CF8& b)
{
    return sVec3_2B6CF8(a.x + b.x, a.y + b.y, a.z + b.z);
}

static inline void operator-=(sVec3_2B6CF8& a, const sVec3_2B6CF8& b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
}

static inline void operator+=(sVec3_2B6CF8& a, const sVec3_2B6CF8& b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
}

static inline sVec3_2B6CF8 Cross_2B6F40(const sVec3_2B6CF8& a, const sVec3_2B6CF8& b)
{
    return sVec3_2B6CF8(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

struct sShape_2B6F40 {
    int type;
    int id;
    float cx, cy, cz;       // 0x08
    float e0, e1, e2;       // 0x14
    float ax, ay, az;       // 0x20
};

extern "C" void func_002B6F40(void* self, int* shape, sVec3_2B6CF8* lo, sVec3_2B6CF8* hi)
{
    sShape_2B6F40* s = (sShape_2B6F40*)shape;
    switch (s->type)
    {
    case 0:
        lo->x = s->cx - s->e0;
        lo->y = s->cy - s->e0;
        lo->z = s->cz - s->e0;
        hi->x = s->cx + s->e0;
        hi->y = s->cy + s->e0;
        hi->z = s->cz + s->e0;
        break;
    case 1:
    {
        sVec3_2B6CF8 a;
        sVec3_2B6CF8 b;
        sVec3_2B6CF8 c;
        sVec3_2B6CF8 z;
        a = sVec3_2B6CF8(s->ax, s->ay, s->az);
        z = sVec3_2B6CF8(0.0f, 0.0f, 1.0f);
        b = Cross_2B6F40(z, a);
        b = b * (1.0f / wtSqrt_2B6F40(b.x * b.x + b.y * b.y + b.z * b.z));
        c = Cross_2B6F40(a, b);
        *lo = sVec3_2B6CF8(s->cx, s->cy, s->cz);
        *hi = sVec3_2B6CF8(s->cx, s->cy, s->cz);
        *lo -= a * s->e0 + b * s->e1 + c * s->e2;
        *hi += a * s->e0 + b * s->e1 + c * s->e2;
        break;
    }
    case 2:
        lo->x = s->cx - s->e0;
        lo->y = s->cy - s->e0;
        lo->z = s->cz - s->e0;
        hi->x = s->cx + s->e0;
        hi->y = s->cy + s->e0;
        hi->z = s->cz + s->e0;
        break;
    case 3:
        lo->x = s->cx - s->e0;
        lo->y = s->cy - s->e0;
        lo->z = s->cz - s->e0;
        hi->x = s->cx + s->e0;
        hi->y = s->cy + s->e0;
        hi->z = s->cz + s->e0;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B7318);
#ifdef SKIP_ASM
struct sWtVec4_7318 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sWtBox_7318 {
    sWtVec4_7318 min;
    sWtVec4_7318 max;
};
struct sWtCell_7318 {
    int level;
    int x, y, z;
};
struct sWtRoot_7318 {
    sWtCell_7318 cell;
    void* node;
};

extern "C" void func_002B6CF8_7318(void* self, void* trig, sVec3_2B6CF8* min, sVec3_2B6CF8* max) __asm__("func_002B6CF8");
extern "C" void func_00328F28(void* out, const void* box);
extern "C" void func_00328C20(void* root, int idx, void* item, const void* target);

static inline void insert_7318(char* w, void* item, const sWtBox_7318* box)
{
    sWtCell_7318 c;
    func_00328F28(&c, box);
    sWtRoot_7318* r = (sWtRoot_7318*)w;
    sWtRoot_7318* rx = c.x < 0 ? r + 4 : r;
    sWtRoot_7318* ry = c.y < 0 ? rx + 2 : rx;
    sWtRoot_7318* rz = c.z < 0 ? ry + 1 : ry;
    func_00328C20(rz, 2, item, &c);
}

// Registers an active sound trigger in the world's spatial tree using its bounds.
extern "C" void func_002B7318(void* self, sTriggerEntry18* e)
{
    char* trig = (char*)e;
    if (trig == 0 || *(int*)(trig + 0xC) == 0 || *(int*)(*(char**)(trig + 0x10) + 4) == 0) {
        return;
    }
    sVec3_2B6CF8 min;
    sVec3_2B6CF8 max;
    func_002B6CF8_7318(self, trig, &min, &max);
    char* w = *(char**)((char*)func_0028B1C8() + 0x20);
    *(int*)(trig + 8) = 5;
    float one = 1.0f;
    sWtBox_7318 box;
    box.min.x = min.x;
    box.min.y = min.y;
    box.min.z = min.z;
    box.min.w = one;
    box.max.x = max.x;
    box.max.y = max.y;
    box.max.z = max.z;
    box.max.w = one;
    insert_7318(w, trig, &box);
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B7410);
#ifdef SKIP_ASM
struct sWtVec4_7410 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sWtBox_7410 {
    sWtVec4_7410 min;
    sWtVec4_7410 max;
};

struct sHashKey_7410 {
    int level;
    int x, y, z;
};

struct sOctCell_7410 {
    void* child[8];
    void* lists[3];
};

struct sHashCellR_7410 {
    char pad_0x0[0x10];
    sOctCell_7410* oct;   // 0x10
};

extern "C" void func_002B6CF8_7410(void* self, void* trig, sVec3_2B6CF8* min, sVec3_2B6CF8* max) __asm__("func_002B6CF8");
extern "C" void func_00328F28_7410(sHashKey_7410* out, const void* box) __asm__("func_00328F28");
extern "C" void func_003284B8_7410(sOctCell_7410* oct, int type, void* node, sHashKey_7410* key,
                                   sHashCellR_7410* cell) __asm__("func_003284B8");
struct sTriggerIdSlot120;
extern "C" void func_002B77C0(sTriggerIdSlot120* self, int trig);

static inline int octEmpty_7410(sOctCell_7410* o)
{
    if (o->child[0] != 0 || o->child[1] != 0 || o->child[2] != 0 || o->child[3] != 0
        || o->child[4] != 0 || o->child[5] != 0 || o->child[6] != 0 || o->child[7] != 0) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (o->lists[i] != 0) {
            return 0;
        }
    }
    return 1;
}

static inline void wtRemove_7410(sHashCellR_7410* cell, void* item, const sWtBox_7410* box)
{
    (*(int*)((char*)cell + 0xA0))++;
    sHashKey_7410 key;
    func_00328F28_7410(&key, box);
    sHashCellR_7410* c1 = key.x < 0 ? cell + 4 : cell;
    sHashCellR_7410* c2 = key.y < 0 ? c1 + 2 : c1;
    sHashCellR_7410* c3 = key.z < 0 ? c2 + 1 : c2;
    sHashCellR_7410* c = c3;
    func_003284B8_7410(c->oct, 2, item, &key, c);
    if (octEmpty_7410(c->oct)) {
        operator_delete((int*)c->oct);
        c->oct = 0;
    }
}

// Removes an active sound trigger from the world's spatial tree (freeing an octree cell that becomes empty).
extern "C" void func_002B7410(void* self, sWtmEnt18* e)
{
    char* trig = (char*)e;
    if (trig == 0 || *(int*)(trig + 0xC) == 0 || *(int*)(*(char**)(trig + 0x10) + 4) == 0) {
        return;
    }
    sVec3_2B6CF8 min;
    sVec3_2B6CF8 max;
    func_002B6CF8_7410(self, trig, &min, &max);
    sHashCellR_7410* cell = ((sHashCellR_7410**)func_0028B1C8())[8];
    float one = 1.0f;
    sWtBox_7410 box;
    box.min.x = min.x;
    box.min.y = min.y;
    box.min.z = min.z;
    box.min.w = one;
    box.max.x = max.x;
    box.max.y = max.y;
    box.max.z = max.z;
    box.max.w = one;
    wtRemove_7410(cell, trig, &box);
    func_002B77C0((sTriggerIdSlot120*)self, (int)trig);
}
#endif

INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B75D0);

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B77C0);
#ifdef SKIP_ASM
struct sTriggerIdSlot120 {
    int count;
    int ids[71];
};

static inline int getTriggerId(sTriggerIdSlot120* s, int j)
{
    return s->ids[j];
}

static inline void clearTriggerId(sTriggerIdSlot120* s, int j)
{
    s->ids[j] = 0;
}

extern "C" void func_002B77C0(sTriggerIdSlot120* self, int id)
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < self[i].count; j++) {
            if (getTriggerId(&self[i], j) == id) {
                clearTriggerId(&self[i], j);
            }
        }
    }
}
#endif

INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B7848);

INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B7908);

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B8190);
#ifdef SKIP_ASM
extern "C" void func_002B8190(void* self, void* obj, int* o0, int* o1, int* o2, int* o3)
{
    int* hdr = *(int**)(*(char**)((char*)obj + 0x8C) + 0x10);
    char* base = (char*)hdr + 8;
    char* p = base + (hdr[0] << 2);
    int n = hdr[1];
    int* recs[4];
    int i;
    int j;

    for (i = 0; i < n; i++) {
        recs[i] = (int*)p;
        switch (*(int*)p) {
        case 0:
            p += 0x1C;
            break;
        case 1:
            p += 0x30;
            break;
        case 2:
            p += 0x30;
            break;
        case 3:
            p += 0x18;
            break;
        }
    }

    *o0 = 0;
    *o1 = 0;
    *o2 = 0;
    *o3 = 0;

    for (j = 0; j < n; j++) {
        int v;
        switch (*recs[0]) {
        case 0:
            v = recs[j][1];
            break;
        case 1:
            v = recs[j][1];
            break;
        case 2:
            v = recs[j][1];
            break;
        case 3:
            v = recs[j][1];
            break;
        default:
            v = recs[j][1];
            break;
        }
        switch (j) {
        case 0:
            *o0 = v;
            break;
        case 1:
            *o1 = v;
            break;
        case 2:
            *o2 = v;
            break;
        case 3:
            *o3 = v;
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B82B8);
#ifdef SKIP_ASM
// Evaluates one of the trigger fade curves (selected by curve) at t.
extern "C" float func_002B82B8(float curve, float t)
{
    switch ((int)curve) {
    case 0:
        t = t * t;
        t = 1.0f - t;
        break;
    case 1:
        t = t / (1.5f - t * 0.5f);
        t = 1.0f - t;
        break;
    case 2:
        t = 1.0f - t;
        break;
    case 3:
        t = 1.0f - t;
        t = t / (1.5f - t * 0.5f);
        break;
    case 4:
        t = 1.0f - t;
        t = t * t;
        break;
    case 5:
        if (t <= 0.7f) {
            t = 1.0f;
        } else {
            t = 1.0f - t;
            t = t * 3.3333332538604736f;
        }
        break;
    default:
        t = 0.0f;
        break;
    }
    return t;
}
#endif

//100%
INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B83F8);
#ifdef SKIP_ASM
extern "C" void func_002BADD0(void* node, void* list);

struct sOctKey83F8 {
    int lvl;
    int x;
    int y;
    int z;
};

struct sOctItem83F8 {
    sOctItem83F8* next;
    int f4;
    int type;
};

struct sOctNode83F8 {
    sOctNode83F8* child[8];
    char pad20[8];
    sOctItem83F8* items;    // 0x28
};

struct sOctList83F8 {
    int count;
    sOctItem83F8* items[1];
};

union sFloatBits83F8 {
    int i;
    float f;
};

static inline int Classify83F8(const float* v, const sOctKey83F8* key)
{
    sFloatBits83F8 u;
    u.i = (key->lvl + 0x7F) << 23;
    float size = u.f;
    if (v[0] < ((float)key->x - 0.2f) * size)
        return 1;
    if (((float)(key->x + 1) + 0.2f) * size < v[0])
        return 1;
    if (v[1] < ((float)key->y - 0.2f) * size)
        return 1;
    if (((float)(key->y + 1) + 0.2f) * size < v[1])
        return 1;
    if (v[2] < ((float)key->z - 0.2f) * size)
        return 1;
    if (((float)(key->z + 1) + 0.2f) * size < v[2])
        return 1;
    return 2;
}

extern "C" void func_002B83F8(void* self, sOctList83F8** partial, sOctList83F8** inside, float** pos,
                              sOctNode83F8* node, sOctKey83F8* key)
{
    int r = Classify83F8(*pos, key);
    if (r == 0)
    {
        for (sOctItem83F8* p = node->items; p != 0; p = p->next)
        {
            if (p->type == 5)
            {
                sOctList83F8* l = *inside;
                l->items[l->count++] = p;
            }
        }
        if (node->child[0]) func_002BADD0(node->child[0], inside);
        if (node->child[1]) func_002BADD0(node->child[1], inside);
        if (node->child[2]) func_002BADD0(node->child[2], inside);
        if (node->child[3]) func_002BADD0(node->child[3], inside);
        if (node->child[4]) func_002BADD0(node->child[4], inside);
        if (node->child[5]) func_002BADD0(node->child[5], inside);
        if (node->child[6]) func_002BADD0(node->child[6], inside);
        if (node->child[7]) func_002BADD0(node->child[7], inside);
    }
    else if (r == 2)
    {
        for (sOctItem83F8* p = node->items; p != 0; p = p->next)
        {
            if (p->type == 5)
            {
                sOctList83F8* l = *partial;
                l->items[l->count++] = p;
            }
        }
        if (key->lvl == 11)
            return;
        sOctKey83F8 k;
        k.lvl = key->lvl - 1;
        k.x = key->x * 2;
        k.y = key->y * 2;
        k.z = key->z * 2;
        if (node->child[0]) func_002B83F8(self, partial, inside, pos, node->child[0], &k);
        k.x++;
        if (node->child[4]) func_002B83F8(self, partial, inside, pos, node->child[4], &k);
        k.y++;
        if (node->child[6]) func_002B83F8(self, partial, inside, pos, node->child[6], &k);
        k.x--;
        if (node->child[2]) func_002B83F8(self, partial, inside, pos, node->child[2], &k);
        k.z++;
        if (node->child[3]) func_002B83F8(self, partial, inside, pos, node->child[3], &k);
        k.x++;
        if (node->child[7]) func_002B83F8(self, partial, inside, pos, node->child[7], &k);
        k.y--;
        if (node->child[5]) func_002B83F8(self, partial, inside, pos, node->child[5], &k);
        k.x--;
        if (node->child[1]) func_002B83F8(self, partial, inside, pos, node->child[1], &k);
    }
}
#endif

INCLUDE_ASM("sound/icepick/worldtriggermanager", func_002B8818);

