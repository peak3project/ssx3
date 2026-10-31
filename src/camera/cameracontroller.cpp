#include "common.h"

//100%
INCLUDE_ASM("camera/cameracontroller", cCameraController_cCameraController);
#ifdef SKIP_ASM
extern void* D_0045B938[];
extern char D_0045B220[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* func_0015C930(void* self);

extern "C" void* cCameraController_cCameraController(void* self, int a1)
{
    *(void***)((char*)self + 0x14) = D_0045B938;
    *(void**)((char*)self + 0x8) = func_0015C930(cMemMan_alloc(8, D_0045B220, 0x20000000, 0));
    *(int*)((char*)self + 0x10) = a1;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015CC10);
#ifdef SKIP_ASM
extern void* D_0045B938[];
extern "C" void func_0015C940(void* p, int mode);
void operator_delete(int* ptr);

extern "C" void func_0015CC10(void* self, int flags)
{
    *(void***)((char*)self + 0x14) = D_0045B938;
    void* p = *(void**)((char*)self + 0x8);
    if (p != 0) {
        func_0015C940(p, 3);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015CC70);
#ifdef SKIP_ASM
struct sCamCtrlNode {
    void* obj;          // 0x0
    char pad_0x04[0x10];
    sCamCtrlNode* next; // 0x14
};

struct sCamCtrlVE {
    short delta;
    short index;
    void (*fn)(void*, int);
};

void* func_0015E030(void* self);
extern "C" void func_002F41A8(void* p);

// PORT: the unit declares func_0015CC70(void* self), but the body takes a
// second argument (callers pass it in $5); the real body is bound by asm label.
void func_0015CC70_impl(void* self, int a) __asm__("func_0015CC70");

void func_0015CC70_impl(void* self, int a)
{
    for (sCamCtrlNode* n = **(sCamCtrlNode***)((char*)self + 0x8); n != 0; n = n->next)
    {
        void* obj = n->obj;
        sCamCtrlVE* vt = *(sCamCtrlVE**)((char*)obj + 0x10);
        vt[3].fn((char*)obj + vt[3].delta, a);
    }
    func_0015E030(*(void**)((char*)self + 0x10));
    func_002F41A8(*(void**)((char*)self + 0x10));
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015CCF0);
#ifdef SKIP_ASM
struct sCamCtrlNodeB {
    void* obj;           // 0x0
    char pad_0x04[0x10];
    sCamCtrlNodeB* next; // 0x14
};

struct sCamCtrlVE0 {
    short delta;
    short index;
    void (*fn)(void*);
};

void* func_0015E030(void* self);
extern "C" void func_002F41A8(void* p);

extern "C" void func_0015CCF0(void* self)
{
    for (sCamCtrlNodeB* n = **(sCamCtrlNodeB***)((char*)self + 0x8); n != 0; n = n->next)
    {
        void* obj = n->obj;
        sCamCtrlVE0* vt = *(sCamCtrlVE0**)((char*)obj + 0x10);
        vt[4].fn((char*)obj + vt[4].delta);
    }
    func_0015E030(*(void**)((char*)self + 0x10));
    func_002F41A8(*(void**)((char*)self + 0x10));
}
#endif

extern "C" void func_0015CB08(int);

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015CD60__FPv);
#ifdef SKIP_ASM
void func_0015CD60(void* self)
{
    func_0015CB08(*(int*)((char*)self + 0x8));
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", cManualCameraController_cManualCameraController);
#ifdef SKIP_ASM
extern void* D_0045B8D8[];
extern char D_0045B230[];
extern char D_0045B240[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cCameraController_cCameraController(void* self, int a1);
extern "C" void* func_0015FD08(void* self);
extern "C" void* func_0015FFB0(void* self);
extern "C" void func_0015CF80(void* self, int msg);

extern "C" void* cManualCameraController_cManualCameraController(void* self, int a1)
{
    cCameraController_cCameraController(self, a1);
    *(void***)((char*)self + 0x14) = D_0045B8D8;
    *(int*)((char*)self + 0x0) = 1;
    *(void**)((char*)self + 0x18) = func_0015FD08(cMemMan_alloc(0x40, D_0045B230, 0x20000000, 0));
    *(void**)((char*)self + 0x1C) = func_0015FFB0(cMemMan_alloc(0x40, D_0045B240, 0x20000000, 0));
    func_0015CF80(self, 0x51);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015CE10);
#ifdef SKIP_ASM
extern void* D_0045B8D8[];
extern "C" void func_0015CC10(void* self, int flags);

struct sCamCtrlVEDtor {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0015CE10(void* self, int flags)
{
    *(void***)((char*)self + 0x14) = D_0045B8D8;
    char* a = *(char**)((char*)self + 0x18);
    if (a != 0) {
        sCamCtrlVEDtor* vt = *(sCamCtrlVEDtor**)(a + 0x10);
        vt[1].fn(a + vt[1].delta, 3);
    }
    char* b = *(char**)((char*)self + 0x1C);
    if (b != 0) {
        sCamCtrlVEDtor* vt = *(sCamCtrlVEDtor**)(b + 0x10);
        vt[1].fn(b + vt[1].delta, 3);
    }
    func_0015CC10(self, flags);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/cameracontroller", func_0015CE98);
#ifdef SKIP_ASM
class cCamCtrlVObj_0015CE98 {
public:
    char pad[0x10];
    // vptr at 0x10
    virtual void v01();
    virtual void v02();
    virtual void v03(int a);
};

extern "C" void func_0015CC70(void* self);

extern "C" void func_0015CE98(void* self, int a)
{
    func_0015CC70(self);
    (*(cCamCtrlVObj_0015CE98**)((char*)self + 0x18))->v03(a);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/cameracontroller", func_0015CEE8);
#ifdef SKIP_ASM
class cCamCtrlVObj {
public:
    char pad[0x10];
    // vptr at 0x10 (g++ 2.95 places it after the class's own data)
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" void func_0015CCF0(void* self);

extern "C" void func_0015CEE8(void* self)
{
    func_0015CCF0(self);
    (*(cCamCtrlVObj**)((char*)self + 0x18))->v04();
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/cameracontroller", func_0015CF28);
#ifdef SKIP_ASM
extern "C" void cCameraAlgoList_insert(void* list, int a, int b, float w);

extern "C" void func_0015CF28(void* self, int a, int b)
{
    func_0015CD60(self);
    cCameraAlgoList_insert(*(void**)((char*)self + 0x8), a, b, 1.0f);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/cameracontroller", func_0015CF80);
#ifdef SKIP_ASM
extern "C" void func_0015CF28(void* self, int a, int b);

extern "C" void func_0015CF80(void* self, int msg)
{
    switch (msg) {
    case 0x50:
        func_0015CF28(self, *(int*)((char*)self + 0x1C), 0);
        break;
    case 0x51:
        func_0015CF28(self, *(int*)((char*)self + 0x18), 0);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015CFD0);
#ifdef SKIP_ASM
extern "C" int func_0015CFD0(void *arg0) {
    return (*(int *)((char*)(**(*(void ****)((char*)(arg0) + (8)))) + (0xC)));
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015CFE8);
#ifdef SKIP_ASM
extern "C" void func_0015CFE8(void* self)
{
    void** p = *(void***)((char*)self + 0x8);
    cCamCtrlVObj* obj = *(cCamCtrlVObj**)*p;
    obj->v05();
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015D020);
#ifdef SKIP_ASM
extern "C" int func_0015D020(void* self)
{
    int r = 0;
    if (*(int*)((char*)self + 0x30) & 2) {
        int s = *(int*)((char*)self + 0x2C);
        if (s != 0x5D) {
            r = s != 0x3C;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("camera/cameracontroller", func_0015D050);
#ifdef SKIP_ASM
extern "C" void* cChaseCameraController_createChaseAlgorithmBlend(void*, int, int, float);

extern "C" void* func_0015D050(void* self, int a1, int a2)
{
    return cChaseCameraController_createChaseAlgorithmBlend(self, a1, a2, 1.0f);
}
#endif

