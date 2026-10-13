#include "common.h"

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", cCameraTriggerMan_cleanupOnExit);
#ifdef SKIP_ASM
struct cActiveTriggerList;
struct cCameraTriggerList;
struct cCameraTriggerStack;
void cCameraTriggerStack_init(cCameraTriggerStack* self);
void cActiveTriggerList_purge(cActiveTriggerList* self);
void cCameraTriggerList_init(cCameraTriggerList* self);
extern "C" void cCameraTriggerMan_purge(void* self);
extern "C" void cCamera_resetChaseControllerSwitches();

extern "C" void cCameraTriggerMan_cleanupOnExit(void* self)
{
    cActiveTriggerList_purge((cActiveTriggerList*)((char*)self + 0x14));
    cActiveTriggerList_purge((cActiveTriggerList*)((char*)self + 0x18));
    cCameraTriggerStack_init((cCameraTriggerStack*)((char*)self + 0x1C));
    cCameraTriggerStack_init((cCameraTriggerStack*)((char*)self + 0x3C));
    cCameraTriggerMan_purge(self);
    cCameraTriggerList_init((cCameraTriggerList*)self);
    cCamera_resetChaseControllerSwitches();
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CA10__FPv);
#ifdef SKIP_ASM
void func_0016CA10(void* self)
{
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerman", cCameraTriggerMan_purge);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", cCameraTriggerMan_loadTriggers);
#ifdef SKIP_ASM
struct sCamTrigMan {
    char** triggers; // 0x0
    int count;       // 0x4
};

extern "C" int cCameraTriggerList_loadFromFile(void* self, const char* file);

extern "C" int cCameraTriggerMan_loadTriggers(sCamTrigMan* self, const char* file)
{
    int err = cCameraTriggerList_loadFromFile(self, file);
    if (err != 0)
        return err;
    for (int i = 0; i < self->count; i++)
        *(int*)(self->triggers[i] + 0x20) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", cCameraTriggerMan_streamIn);
#ifdef SKIP_ASM
struct sCamTrigManB {
    char** triggers; // 0x0
    int count;       // 0x4
};

extern "C" int cCameraTriggerList_loadFromBuffer(void* self, void* buf);
void cCameraTriggerMan_setInGameTriggers(void* self);

extern "C" void cCameraTriggerMan_streamIn(void* self, void* stream)
{
    cCameraTriggerMan_cleanupOnExit(self);
    cCameraTriggerList_loadFromBuffer(self, stream);
    sCamTrigManB* m = (sCamTrigManB*)self;
    for (int i = 0; i < m->count; i++)
        *(int*)(m->triggers[i] + 0x20) = 0;
    cCameraTriggerMan_setInGameTriggers(self);
}
#endif

extern void* D_004C5830[];
extern "C" void* func_0016CEF0(void*, void*, int);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CEC8__FPvi);
#ifdef SKIP_ASM
// PORT: the unit declares func_0016CEF0 as returning void*; this caller treats it as void.
void func_0016CEF0_CEC8(void*, void*, int) __asm__("func_0016CEF0");
void func_0016CEC8(void* self, int a1)
{
    func_0016CEF0_CEC8((void*)D_004C5830, self, a1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CEF0);
#ifdef SKIP_ASM
extern "C" void cCameraTriggerMan_streamIn(void* self, void* stream);

// PORT: the unit declares func_0016CEF0 as returning void*, but the body returns nothing.
void func_0016CEF0_impl(void* self, void* unused, void* stream) __asm__("func_0016CEF0");
void func_0016CEF0_impl(void* self, void* unused, void* stream)
{
    if (stream != 0) {
        cCameraTriggerMan_streamIn(self, stream);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CF18);
#ifdef SKIP_ASM
// PORT: func_0016CF40__FPv is mangled as (void*), but this caller passes two args.
void func_0016CF40_2(void* mgr, void* self) __asm__("func_0016CF40__FPv");

extern "C" void func_0016CF18(void* self)
{
    func_0016CF40_2((void*)D_004C5830, self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CF40__FPv);
#ifdef SKIP_ASM
void func_0016CF40(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CF48);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_004A28A8;

struct sCtVec4_CF48 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sCtBox_CF48 {
    sCtVec4_CF48 min;
    sCtVec4_CF48 max;
};
struct sCtCell_CF48 {
    int level;
    int x, y, z;
};
struct sCtNode_CF48 {
    sCtNode_CF48* child[2][2][2];   // 0x00
    void* lists[3];                 // 0x20
    int empty()
    {
        if (child[0][0][0] || child[0][0][1] || child[0][1][0] || child[0][1][1] || child[1][0][0] ||
            child[1][0][1] || child[1][1][0] || child[1][1][1]) {
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if (lists[i]) return 0;
        }
        return 1;
    }
};
struct sCtRoot_CF48 {
    sCtCell_CF48 cell;              // 0x00
    sCtNode_CF48* node;             // 0x10
};

extern "C" void func_00328F28(void* out, const void* box);
extern "C" void func_003284B8(void* node, int idx, void* item, const void* target, const void* cur);
extern "C" void func_00328C20(void* root, int idx, void* item, const void* target);

class cCtShape_CF48 {
public:
    char pad[0x24];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual sCtBox_CF48 bounds();
};

struct sCtTrig_CF48 {
    int f0;
    unsigned int mask;              // 0x4
    cCtShape_CF48* shape;           // 0x8
    char padC[0x8];
    char item[0xC];                 // 0x14
    sCtTrig_CF48* reg;              // 0x20
};

struct sCtMan_CF48 {
    sCtTrig_CF48** trigs;           // 0x0
    int count;                      // 0x4
};

static inline sCtRoot_CF48* findRoot_CF48(char* w, int x, int y, int z)
{
    sCtRoot_CF48* r = (sCtRoot_CF48*)w;
    sCtRoot_CF48* rx = x >= 0 ? r : r + 4;
    sCtRoot_CF48* ry = y >= 0 ? rx : rx + 2;
    sCtRoot_CF48* rz = z >= 0 ? ry : ry + 1;
    return rz;
}

static inline void remove_CF48(char* w, void* item, const sCtBox_CF48* box)
{
    (*(int*)(w + 0xA0))++;
    sCtCell_CF48 c;
    func_00328F28(&c, box);
    sCtRoot_CF48* r = findRoot_CF48(w, c.x, c.y, c.z);
    func_003284B8(r->node, 2, item, &c, &r->cell);
    if (r->node->empty()) {
        operator_delete((int*)r->node);
        r->node = 0;
    }
}

static inline void insert_CF48(char* w, void* item, const sCtBox_CF48* box)
{
    sCtCell_CF48 c;
    func_00328F28(&c, box);
    func_00328C20(findRoot_CF48(w, c.x, c.y, c.z), 2, item, &c);
}

// PORT: the unit declares func_0016CF48 as returning void*; it returns nothing.
extern "C" void func_0016CF48_impl(void* vself, int mask) __asm__("func_0016CF48");

extern "C" void func_0016CF48_impl(void* vself, int mask)
{
    sCtMan_CF48* self = (sCtMan_CF48*)vself;
    for (int i = 0; i < self->count; i++) {
        sCtTrig_CF48* t = self->trigs[i];
        if (t->mask & mask) {
            if (t->reg == 0) {
                t->reg = t;
                char* w = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x20);
                sCtBox_CF48 box = t->shape->bounds();
                insert_CF48(w, t->item, &box);
            }
        } else if (t->reg != 0) {
            char* w = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x20);
            sCtBox_CF48 box = t->shape->bounds();
            remove_CF48(w, t->item, &box);
            t->reg = 0;
        }
    }
}
#endif

extern "C" void* func_0016CF48(void* self, int type);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", cCameraTriggerMan_setInGameTriggers__FPv);
#ifdef SKIP_ASM
void cCameraTriggerMan_setInGameTriggers(void* self)
{
    func_0016CF48(self, 2);
}
#endif

//99.29%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016D1D8__FPv);
#ifdef SKIP_ASM
void* func_0016D1D8(void* self)
{
    return func_0016CF48(self, 1);
}
#endif

struct cCameraTriggerStack {
    int field_0x0;
    int field_0x4;
};

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", cCameraTriggerStack_init__FP19cCameraTriggerStack);
#ifdef SKIP_ASM
void cCameraTriggerStack_init(cCameraTriggerStack* self)
{
    self->field_0x0 = 0;
    self->field_0x4 = 0;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016D210);
#ifdef SKIP_ASM
void cCameraTriggerStack_init(cCameraTriggerStack* self);

extern "C" cCameraTriggerStack* func_0016D210(cCameraTriggerStack* self)
{
    cCameraTriggerStack_init(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016D238__FPvi);
#ifdef SKIP_ASM
void func_0016D238(void* self, int a1)
{
    *(int*)((char*)self + (*(int*)self << 2) + 0x8) = a1;
    *(int*)((char*)self + 0x4) = a1;
    *(int*)self = *(int*)self + 1;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016D260);
#ifdef SKIP_ASM
struct sCamTrigStack {
    unsigned int count; // 0x0
    int top; // 0x4
    int items[1]; // 0x8
};

extern "C" int func_0016D260(sCamTrigStack* self, int key, int* changed, int* out)
{
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        if (self->items[i] == key) {
            unsigned int j;
            for (j = i + 1; j < self->count; j++) {
                self->items[j - 1] = self->items[j];
            }
            self->count--;
            break;
        }
    }
    if (self->count != 0) {
        int t = self->items[self->count - 1];
        if (t == self->top) {
            *changed = 0;
        } else {
            *changed = 1;
            *out = t;
        }
        return 0;
    }
    *changed = 0;
    return 1;
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016D320);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016E1D8);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016E560);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016F068);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016FBB8);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_00170240);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_001707B0);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_00170D20);

