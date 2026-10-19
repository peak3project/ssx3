#include "common.h"

//100%
INCLUDE_ASM("scripter/videngine", cVidEngine_ReadyVideo);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002533C8(void* mem);
extern "C" void func_00253390(void* self);
extern "C" int func_002534A8(void* p, void* q);
extern "C" void func_00253418(void* p, int a1);
extern const char D_00481FC8[];

struct sVidParams38E8 {
    int file;       // 0x0
    int f4;         // 0x4
    int f8;         // 0x8
    int fC;         // 0xC
    int f10;        // 0x10
    int f14;        // 0x14
    int f18;        // 0x18
    int f1C;        // 0x1C
    float f20;      // 0x20
};

extern "C" int cVidEngine_ReadyVideo(void** self, int file)
{
    if (*self != 0) return 0;
    *self = func_002533C8(cMemMan_alloc(0x44, D_00481FC8, 0x100, 0));
    sVidParams38E8 p;
    func_00253390(&p);
    //S
    p.file = file;
    p.f8 = 1;
    p.f18 = 0x100;
    p.f1C = 9;
    p.fC = 0;
    p.f10 = 0;
    //E
    if (func_002534A8(*self, &p) == 0) {
        if (*self != 0) func_00253418(*self, 3);
        *self = 0;
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_002839A8);
#ifdef SKIP_ASM
extern "C" int func_00253860(void*);
extern "C" void* func_0028B180();
extern "C" void func_0029CE28(void*);
extern "C" void func_002EA820(void*);
extern int D_004A2A54;
extern int D_004A2A50;
extern int D_005366E8[];
extern int D_00442918[];

struct sVidObj { char pad0[0x10]; int state; };
struct sVidOwner { char pad0[0x64]; sVidObj* obj; };
struct sVidMgr { char pad0[0x84]; sVidOwner* owner; };
extern sVidMgr* D_004A28A8;
extern char* D_004A289C;

struct sVidPlayer { void* p; int active; int f8; int fC; int f10; int f14; };
struct sVtEnt { short delta; short index; void* fn; };

extern "C" int func_002839A8(sVidPlayer* self)
{
    void* p = self->p;
    if (p == 0) return 0;
    if (self->active != 0) return 1;
    func_00253860(p);
    int n = D_004A2A54 + 1;
    self->active = 1;
    D_005366E8[n] = 10;
    D_004A2A50 = D_00442918[0];
    D_004A2A54 = n;
    sVidObj* q = D_004A28A8->owner->obj;
    self->f14 = 0;
    int s = q->state;
    if (s != 0 && s != 2) self->f14 = 1;
    func_002EA820(q);
    {
        char* o = D_004A289C;
        sVtEnt* vt = *(sVtEnt**)(o + 0x10D8);
        self->f10 = *((int*(*)(void*))vt[42].fn)(o + vt[42].delta);
    }
    {
        char* o = D_004A289C;
        sVtEnt* vt = *(sVtEnt**)(o + 0x10D8);
        ((void(*)(void*, int))vt[40].fn)(o + vt[40].delta, 0);
    }
    func_0029CE28(func_0028B180());
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283AA0);
#ifdef SKIP_ASM
extern "C" void func_00253938(void* self);

extern "C" void func_00283AA0(void* self)
{
    void* p = *(void**)self;
    if (p != 0 && *(int*)((char*)self + 0x4) != 0 && *(int*)((char*)self + 0xC) == 0) {
        func_00253938(p);
        *(int*)((char*)self + 0x8) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283AF8);
#ifdef SKIP_ASM
extern "C" void func_00253890(void* p, int a1);
extern "C" void func_002539E0(void* self);
extern "C" void func_00253A40(void* self);

extern "C" void func_00283AF8(void* self)
{
    void* v = *(void**)((char*)self + 0x0);
    if (v != 0 && *(int*)((char*)self + 0x4) != 0) {
        if (*(int*)((char*)self + 0x8) != 0) {
            if (*(int*)((char*)v + 0x8) != 0) {
                func_00253A40(v);
            }
        } else {
            if (*(int*)((char*)v + 0x8) == 0) {
                func_002539E0(v);
            }
        }
        func_00253890(*(void**)((char*)self + 0x0), *(int*)((char*)self + 0x8) ^ 1);
        *(int*)((char*)self + 0x8) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283B78);
#ifdef SKIP_ASM
extern "C" void func_00283B78(void* self, int inc)
{
    if (*(int*)((char*)self + 0x0) != 0 && *(int*)((char*)self + 0x4) != 0) {
        if (inc != 0) {
            *(int*)((char*)self + 0xc) += 1;
        } else if (*(int*)((char*)self + 0xc) != 0) {
            *(int*)((char*)self + 0xc) -= 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283BB8);
#ifdef SKIP_ASM
extern "C" int func_00283BB8(void* self)
{
    int* p = *(int**)((char*)self + 0x0);
    if (p == 0 || *(int*)((char*)self + 0x4) == 0) {
        return 0;
    }
    return *p;
}
#endif

INCLUDE_ASM("scripter/videngine", func_00283BE0);

//100%
INCLUDE_ASM("scripter/videngine", func_00283C20__FPv);
#ifdef SKIP_ASM
void func_00283C20(void* self)
{
    *(int*)((char*)self + 0x8c) = 0;
    *(int*)((char*)self + 0x90) = 0;
    *(int*)((char*)self + 0x94) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/videngine", func_00283C30);
#ifdef SKIP_ASM
void func_00283C20(void*);

extern "C" void* func_00283C30(void* self)
{
    func_00283C20(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283C58__FPv);
#ifdef SKIP_ASM
int func_00283C58(void* self)
{
    return *(int*)((char*)self + 0x94);
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283C60);
#ifdef SKIP_ASM
extern "C" int func_00283C60(void* self, int a1)
{
    if (a1 == 4) {
        return 0;
    }
    return a1 + 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/videngine", func_00283C80);
#ifdef SKIP_ASM
int func_00283C58(void*);
extern "C" int func_00283C60(void* self, int a1);

struct sVidCmd3C80 {
    int v[7];
};

extern "C" int func_00283C80(void* self, sVidCmd3C80* cmd)
{
    if (func_00283C58(self) != 0) return 0;
    ((sVidCmd3C80*)self)[*(int*)((char*)self + 0x90)] = *cmd;
    *(int*)((char*)self + 0x90) = func_00283C60(self, *(int*)((char*)self + 0x90));
    if (*(int*)((char*)self + 0x90) == *(int*)((char*)self + 0x8C)) {
        *(int*)((char*)self + 0x94) = 1;
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/videngine", func_00283D28);
#ifdef SKIP_ASM
int func_00283C58(void*);

extern "C" int func_00283D28(void* self)
{
    int n;
    if (func_00283C58(self) != 0) {
        return 5;
    }
    n = *(int*)((char*)self + 0x90) - *(int*)((char*)self + 0x8c);
    if (n < 0) {
        n += 5;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283D70);
#ifdef SKIP_ASM
extern "C" void* func_00283D70(void* self, int a1)
{
    return (char*)self + ((*(int*)((char*)self + 0x8c) + a1) % 5) * 0x1c;
}
#endif

//100%
INCLUDE_ASM("scripter/videngine", func_00283DA0);
#ifdef SKIP_ASM
extern "C" int func_00283DA0(void* self)
{
    int r = 0;
    if (*(int*)((char*)self + 0x90) == *(int*)((char*)self + 0x8c)) {
        r = *(int*)((char*)self + 0x94) == 0;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/videngine", func_00283DC0);
#ifdef SKIP_ASM
extern "C" int func_00283DA0(void* self);
extern "C" int func_00283C60(void* self, int a1);

struct sVidEntry1C { int v[7]; };

extern "C" int func_00283DC0(void* self, sVidEntry1C* out)
{
    if (func_00283DA0(self) != 0) {
        return 0;
    }
    *(int*)((char*)self + 0x94) = 0;
    if (out != 0) {
        *out = ((sVidEntry1C*)self)[*(int*)((char*)self + 0x8c)];
    }
    *(int*)((char*)self + 0x8c) = func_00283C60(self, *(int*)((char*)self + 0x8c));
    return 1;
}
#endif

