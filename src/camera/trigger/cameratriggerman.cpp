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
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CA08);
#ifdef SKIP_ASM
extern "C" void func_0016CA08(void) {

}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CA10__FPv);
#ifdef SKIP_ASM
void func_0016CA10(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CA18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void operator_delete(int*);
extern void* D_004A28A8;
extern "C" void func_0016BF40(void* self);

struct sCtVec4_CA18 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sCtBox_CA18 {
    sCtVec4_CA18 min;
    sCtVec4_CA18 max;
};
struct sCtCell_CA18 {
    int level;
    int x, y, z;
};
struct sCtNode_CA18 {
    sCtNode_CA18* child[2][2][2];   // 0x00
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
struct sCtRoot_CA18 {
    sCtCell_CA18 cell;              // 0x00
    sCtNode_CA18* node;             // 0x10
};

extern "C" void func_00328F28_CA18(void* out, const void* box) __asm__("func_00328F28");
extern "C" void func_003284B8_CA18(void* node, int idx, void* item, const void* target, const void* cur) __asm__("func_003284B8");

class cCtShape_CA18 {
public:
    char pad[0x24];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual sCtBox_CA18 bounds();
};

struct sCtTrig_CA18 {
    int f0;
    unsigned int mask;              // 0x4
    cCtShape_CA18* shape;           // 0x8
    char padC[0x8];
    char item[0xC];                 // 0x14
    sCtTrig_CA18* reg;              // 0x20
};

struct sCtMan_CA18 {
    sCtTrig_CA18** trigs;           // 0x0
    int count;                      // 0x4
};

static inline void remove_CA18(char* w, void* item, const sCtBox_CA18* box)
{
    (*(int*)(w + 0xA0))++;
    sCtCell_CA18 c;
    func_00328F28_CA18(&c, box);
    sCtRoot_CA18* r = (sCtRoot_CA18*)w;
    sCtRoot_CA18* rx = c.x < 0 ? r + 4 : r;
    sCtRoot_CA18* ry = c.y < 0 ? rx + 2 : rx;
    sCtRoot_CA18* rz = c.z < 0 ? ry + 1 : ry;
    sCtRoot_CA18* q = rz;
    func_003284B8_CA18(q->node, 2, item, &c, q);
    if (q->node->empty()) {
        operator_delete((int*)q->node);
        q->node = 0;
    }
}

extern "C" void func_0016CA18(void* vself);
extern "C" void func_0016CA18(void* vself)
{
    sCtMan_CA18* self = (sCtMan_CA18*)vself;
    for (int i = 0; i < self->count; i++) {
        sCtTrig_CA18* t = self->trigs[i];
        char* w = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x20);
        sCtBox_CA18 box = t->shape->bounds();
        remove_CA18(w, t->item, &box);
    }
    cCameraTriggerStack_init((cCameraTriggerStack*)((char*)vself + 0x1C));
    cCameraTriggerStack_init((cCameraTriggerStack*)((char*)vself + 0x3C));
    func_0016BF40(vself);
    cCamera_resetChaseControllerSwitches();
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", cCameraTriggerMan_purge);
#ifdef SKIP_ASM
void operator_delete(int*);
extern void* D_004A28A8;
extern "C" void func_0016C098(void** self);

struct sCtVec4_P {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sCtBox_P {
    sCtVec4_P min;
    sCtVec4_P max;
};
struct sCtCell_P {
    int level;
    int x, y, z;
};
struct sCtNode_P {
    sCtNode_P* child[2][2][2];      // 0x00
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
struct sCtRoot_P {
    sCtCell_P cell;                 // 0x00
    sCtNode_P* node;                // 0x10
};

extern "C" void func_00328F28_P(void* out, const void* box) __asm__("func_00328F28");
extern "C" void func_003284B8_P(void* node, int idx, void* item, const void* target, const void* cur) __asm__("func_003284B8");

class cCtShape_P {
public:
    char pad[0x24];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual sCtBox_P bounds();
};

struct sCtTrig_P {
    int f0;
    unsigned int mask;              // 0x4
    cCtShape_P* shape;              // 0x8
    char padC[0x8];
    char item[0xC];                 // 0x14
    sCtTrig_P* reg;                 // 0x20
};

struct sCtMan_P {
    sCtTrig_P** trigs;              // 0x0
    int count;                      // 0x4
};

static inline void remove_P(char* w, void* item, const sCtBox_P* box)
{
    (*(int*)(w + 0xA0))++;
    sCtCell_P c;
    func_00328F28_P(&c, box);
    sCtRoot_P* r = (sCtRoot_P*)w;
    sCtRoot_P* rx = c.x < 0 ? r + 4 : r;
    sCtRoot_P* ry = c.y < 0 ? rx + 2 : rx;
    sCtRoot_P* rz = c.z < 0 ? ry + 1 : ry;
    sCtRoot_P* q = rz;
    func_003284B8_P(q->node, 2, item, &c, q);
    if (q->node->empty()) {
        operator_delete((int*)q->node);
        q->node = 0;
    }
}

// Takes every registered trigger out of the world's space hash and clears the trigger stacks and active lists.
extern "C" void cCameraTriggerMan_purge(void* vself)
{
    sCtMan_P* self = (sCtMan_P*)vself;
    for (int i = 0; i < self->count; i++) {
        sCtTrig_P* t = self->trigs[i];
        if (t->reg != 0) {
            char* w = *(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x20);
            sCtBox_P box = t->shape->bounds();
            remove_P(w, t->item, &box);
        }
    }
    cCameraTriggerStack_init((cCameraTriggerStack*)((char*)vself + 0x1C));
    cCameraTriggerStack_init((cCameraTriggerStack*)((char*)vself + 0x3C));
    func_0016C098((void**)vself);
    cActiveTriggerList_purge((cActiveTriggerList*)((char*)vself + 0x14));
    cActiveTriggerList_purge((cActiveTriggerList*)((char*)vself + 0x18));
    cCamera_resetChaseControllerSwitches();
}
#endif

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

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016CEA8);
#ifdef SKIP_ASM
extern "C" void func_0016CA18(void* vself);

extern "C" void func_0016CEA8(void* vself) {
    func_0016CA18(vself);
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

//100%
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
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016D1F8);
#ifdef SKIP_ASM
extern "C" int func_0016D1F8(int arg0) {
    return arg0;
}
#endif

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

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016D320);
#ifdef SKIP_ASM
struct sCell_D320 {
    int level, x, y, z;
    void** node;                    // 0x10
};

struct sRoot_D320 {
    sCell_D320 cell[8];
};

struct sVEnt_D320 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

struct sVec4_D320 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sQH_D320 {};

struct sCtx_D320 {
    void* list;                     // 0x0
    char* cam;                      // 0x4
};

struct sLNode_D320 {
    sLNode_D320* next;              // 0x0 (also data ptr in the active list)
    sLNode_D320* link;              // 0x4
    int f08;
    int f0C;
};

extern "C" void* func_0016C6B0_D320(void*, void*) __asm__("func_0016C6B0");
extern "C" void cActiveTriggerList_add(void*, void*);
extern "C" void func_00176890(void* node, void* ctx);
extern "C" void func_0016C678(void*);
extern "C" int func_00328360(sCell_D320* c, void* box);
extern "C" void helpX_D320(char* flag, sCtx_D320* ctx, sCtx_D320* ctx2, void* box, void** node, sCell_D320* cell) __asm__("func_00174848");
extern "C" void* func_0016C6E0(void*, int);
extern "C" void* func_0016C778(void*, void*);
extern "C" void func_0016E1D8(void*, void*);
void func_0016D238(void* self, int a1);

// CameraCollisionCallback::operator()(cell)
static inline void trigCb_D320(sCtx_D320* ctx, void** node)
{
    char* e;
    for (e = (char*)node[10]; e != 0; e = *(char**)e) {
        if (*(int*)(e + 8) == 4) {
            char* trig = *(char**)(e + 0xC);
            char* sub = ctx->cam + 0x6C0;
            char* bound = *(char**)(trig + 8);
            sVEnt_D320* cvt = *(sVEnt_D320**)sub;
            sVEnt_D320* bvt = *(sVEnt_D320**)(bound + 0x24);
            char* bthis = bound + bvt[7].delta;
            int r = cvt[5].fn(sub + cvt[5].delta);
            if (bvt[7].fn(bthis, r)) {
                void* f = func_0016C6B0_D320(ctx->list, trig);
                if (f) {
                    *(int*)((char*)f + 0xC) = 1;
                } else {
                    cActiveTriggerList_add(ctx->list, trig);
                }
            }
        }
    }
}

static inline void visit_D320(sRoot_D320* t, int k, sCtx_D320* ctx, void* box)
{
    sQH_D320 h;
    sCell_D320* c = (sCell_D320*)((char*)t + k * 0x14);
    if (t->cell[k].node) {
        void** n = c->node;
        char* f = (char*)&h;
        int r = func_00328360(c, box);
        if (r == 0) {
            trigCb_D320(ctx, n);
            if (n[0] != 0) func_00176890(n[0], ctx);
            if (n[1] != 0) func_00176890(n[1], ctx);
            if (n[2] != 0) func_00176890(n[2], ctx);
            if (n[3] != 0) func_00176890(n[3], ctx);
            if (n[4] != 0) func_00176890(n[4], ctx);
            if (n[5] != 0) func_00176890(n[5], ctx);
            if (n[6] != 0) func_00176890(n[6], ctx);
            if (n[7] != 0) func_00176890(n[7], ctx);
        } else if (r == 2) {
            helpX_D320(f, ctx, ctx, box, n, c);
        }
    }
}

extern "C" void func_0016D320(char* self, char* cam)
{
    int ok = 0;
    if (*(int*)(cam + 0x874) != 0) {
        ok = *(int*)(cam + 0x87C) != 0;
    }
    if (!ok) return;
    int idx = *(int*)(cam + 0x870);
    func_0016C678(self + (idx * 4 + 0x14));
    sRoot_D320* t = *(sRoot_D320**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x20);
    sCtx_D320 ctx;
    ctx.list = (char*)(idx * 4 + (int)self) + 0x14;
    ctx.cam = cam;
    char* sub = cam + 0x6C0;
    sVEnt_D320* cvt = *(sVEnt_D320**)sub;
    sVec4_D320* pmin = (sVec4_D320*)cvt[5].fn(sub + cvt[5].delta);
    sVEnt_D320* cvt2 = *(sVEnt_D320**)sub;
    sVec4_D320* pmax = (sVec4_D320*)cvt2[5].fn(sub + cvt2[5].delta);
    sCtx_D320* c = &ctx;
    sVec4_D320 box[2];
    box[0] = *pmin;
    box[1] = *pmax;
    int changed;
    int out;
    visit_D320(t, 0, c, box);
    visit_D320(t, 1, c, box);
    visit_D320(t, 2, c, box);
    visit_D320(t, 3, c, box);
    visit_D320(t, 4, c, box);
    visit_D320(t, 5, c, box);
    visit_D320(t, 6, c, box);
    visit_D320(t, 7, c, box);
    sLNode_D320* p = *(sLNode_D320**)(self + idx * 4 + 0x14);
    if (p) {
        for (; p; ) {
            if (p->f0C == 0) {
                int* q = (int*)p->next;
                if (func_0016D260((sCamTrigStack*)(self + (idx * 0x20 + 0x1c)), q[0], &changed, &out)) {
                    func_0016E1D8((void*)q[4], cam);
                } else if (changed) {
                    int* e = (int*)func_0016C6E0(self + (idx * 4 + 0x14), out);
                    if (e) func_0016E1D8((void*)e[3], cam);
                }
                p = (sLNode_D320*)func_0016C778(self + (idx * 4 + 0x14), p);
            } else {
                p = p->link;
            }
        }
    }
    sLNode_D320* p2 = *(sLNode_D320**)(self + idx * 4 + 0x14);
    if (p2) {
        for (; p2; p2 = p2->link) {
            if (p2->f08) {
                func_0016D238(self + (idx * 0x20 + 0x1c), **(int**)p2);
                func_0016E1D8((void*)(*(int**)p2)[3], cam);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016E1D8);
#ifdef SKIP_ASM
extern "C" void func_00162060_p(void* cam, int mode, void* arg, float blend) __asm__("func_00162060");

struct sCtPlayerList_E1D8 {
    int count;
    char* players[1];
};

struct sCamTrigData_E1D8 {
    int mode;   // 0x0
    int f04;    // 0x4
    int type;   // 0x8
    float time; // 0xC
};

extern "C" void func_0016E1D8(void* selfv, void* playerv)
{
    sCamTrigData_E1D8* self = (sCamTrigData_E1D8*)selfv;
    char* player = (char*)playerv;
    int mode = self->mode;
    sCtPlayerList_E1D8* list = *(sCtPlayerList_E1D8**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x84);
    void* cam = *(void**)(list->players[*(int*)(player + 0x870)] + 0xA8);
    switch (mode) {
    case 2: {
        float rate = self->time == 0.0f ? 1.0f : (1.0f / self->time) * 0.01666666753590107f;
        func_00162060_p(cam, 0x5C, self, rate);
        break;
    }
    case 1: {
        float rate = self->time == 0.0f ? 1.0f : (1.0f / self->time) * 0.01666666753590107f;
        func_00162060_p(cam, 0x5B, self, rate);
        break;
    }
    case 0: {
        int r;
        float rate = 0.0f;
        if (self->time == 0.0f) {
            rate = 1.0f;
        } else {
            rate = (1.0f / self->time) * 0.01666666753590107f;
        }
        switch (self->type) {
        case 3:
            r = 4;
            break;
        case 7:
            r = 3;
            break;
        case 1:
            r = 2;
            break;
        case 2:
            r = 1;
            break;
        case 4:
            r = 7;
            break;
        case 5:
            r = 5;
            break;
        case 6:
            r = 6;
            break;
        case 8:
            r = 8;
            break;
        case 10:
            r = 9;
            break;
        case 9:
            r = 10;
            break;
        case 11:
            r = 11;
            break;
        case 12:
            r = 12;
            break;
        case 13:
            r = 13;
            break;
        case 14:
            r = 14;
            break;
        case 15:
            r = 15;
            break;
        case 16:
            r = 16;
            break;
        case 17:
            r = 17;
            break;
        case 18:
            r = 18;
            break;
        case 19:
            r = 19;
            break;
        case 20:
            r = 20;
            break;
        case 21:
            r = 21;
            break;
        case 22:
            r = 22;
            break;
        case 23:
            r = 23;
            break;
        case 24:
            r = 24;
            break;
        case 25:
            r = 25;
            break;
        case 26:
            r = 26;
            break;
        case 27:
            r = 27;
            break;
        case 28:
            r = 28;
            break;
        case 29:
            r = 29;
            break;
        case 30:
            r = 30;
            break;
        case 31:
            r = 31;
            break;
        case 32:
            r = 32;
            break;
        case 33:
            r = 41;
            break;
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
            r = self->type - 1;
            break;
        case 44:
            r = 42;
            break;
        case 45:
            r = 43;
            break;
        case 46:
            r = 44;
            break;
        case 47:
            r = 45;
            break;
        case 48:
            r = 46;
            break;
        case 49:
            r = 47;
            break;
        case 50:
            r = 48;
            break;
        case 51:
            r = 49;
            break;
        case 52:
            r = 50;
            break;
        case 53:
            r = 51;
            break;
        case 54:
            r = 52;
            break;
        case 55:
            r = 53;
            break;
        case 56:
            r = 54;
            break;
        case 57:
            r = 55;
            break;
        case 58:
            r = 56;
            break;
        case 59:
            r = 57;
            break;
        case 60:
            r = 58;
            break;
        case 61:
            r = 59;
            break;
        case 62:
            r = 60;
            break;
        case 63:
            r = 61;
            break;
        case 64:
            r = 62;
            break;
        case 65:
            r = 63;
            break;
        case 66:
            r = 64;
            break;
        case 67:
            r = 65;
            break;
        case 68:
            r = 66;
            break;
        case 69:
            r = 67;
            break;
        case 70:
            r = 68;
            break;
        case 71:
            r = 69;
            break;
        case 72:
            r = 70;
            break;
        case 73:
            r = 71;
            break;
        case 74:
            r = 72;
            break;
        case 75:
            r = 73;
            break;
        case 42:
            r = 76;
            break;
        case 0:
        default:
            r = 0;
            break;
        }
        func_00162060_p(cam, r, 0, rate);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016E560);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" void func_0031BE50(float* sout, float* cout, float x);

extern t4Vector D_004FF140;
extern t4Vector D_004FF150;
extern t4Vector D_004FF160;
extern t4Matrix D_004FF1A0;

struct sVec3_E560 {
    float x, y, z;
    sVec3_E560() {}
    sVec3_E560(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sVec4_E560 : t4Vector
{
    sVec4_E560() {}
    sVec4_E560(const float& ax, const float& ay, const float& az, const float& aw) { x = ax; y = ay; z = az; w = aw; }
    sVec4_E560(const sVec3_E560& v, const float& aw) { x = v.x; y = v.y; z = v.z; w = aw; }
} __attribute__((aligned(16)));

struct sMtx_E560;

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply in place, d = b * d).
static inline void vu0MulMatEq_E560(sMtx_E560* d, const sMtx_E560* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0Copy_E560(sMtx_E560* d, const sMtx_E560* s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

struct sMtx_E560 {
    float m[4][4];
    sMtx_E560() {}
    sMtx_E560(const sMtx_E560& o) { vu0Copy_E560(this, &o); }
    sMtx_E560& operator=(const sMtx_E560& o)
    {
        vu0Copy_E560(this, &o);
        return *this;
    }
    sMtx_E560& operator*=(const sMtx_E560& b)
    {
        vu0MulMatEq_E560(this, &b);
        return *this;
    }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector into the last matrix row).
static inline void vu0MulVecRow3_E560(sMtx_E560* m, const t4Vector& v)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, %1\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, 0x30(%0)\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector, vector loaded first).
static inline t4Vector vu0MulVec2_E560(const sMtx_E560* m, const t4Vector& v)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

struct sXform_E560 {
    sVec3_E560 pos;     // 0x0
    float rot[3];       // 0xC
    sVec3_E560 size;    // 0x18
};

// Multiply by a rotation of `angle` about the unit axis `a` (Rodrigues).
#define ROT_E560(R, a, angle) \
    { \
        const float* ax = a; \
        float s, c; \
        func_0031BE50(&s, &c, angle); \
        float t = 1.0f - c; \
        float x = ax[0]; \
        float y = ax[1]; \
        float z = ax[2]; \
        float tx = t * x; \
        float ty = t * y; \
        float tz = t * z; \
        float sx = s * x; \
        float sy = s * y; \
        float sz = s * z; \
        R.m[0][0] = tx * x + c; \
        R.m[1][0] = tx * y + sz; \
        R.m[2][0] = tx * z - sy; \
        R.m[0][1] = ty * x - sz; \
        R.m[1][1] = ty * y + c; \
        R.m[2][1] = ty * z + sx; \
        R.m[0][2] = tz * x + sy; \
        R.m[1][2] = tz * y - sx; \
        R.m[2][2] = tz * z + c; \
        R.m[3][0] = 0.0f; \
        R.m[3][1] = 0.0f; \
        R.m[3][2] = 0.0f; \
        R.m[0][3] = 0.0f; \
        R.m[1][3] = 0.0f; \
        R.m[2][3] = 0.0f; \
        R.m[3][3] = 1.0f; \
    }

// PORT: PS2-only VU0 inline asm (scale matrix rows by the components of s).
static inline void vu0ScaleRows_E560(sMtx_E560* d, const sMtx_E560* m, const t4Vector& s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2      $vf8, 0x0(%0)\n"
        "sqc2      $vf9, 0x10(%0)\n"
        "sqc2      $vf10, 0x20(%0)\n"
        "sqc2      $vf11, 0x30(%0)\n"
        :
        : "r"(d), "r"(m), "m"(s)
        : "memory");
}

static inline sMtx_E560 scaled_E560(const sMtx_E560& m, const t4Vector& s)
{
    sMtx_E560 r;
    vu0ScaleRows_E560(&r, &m, s);
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline t4Vector Normalize_E560(const t4Vector& v)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// cCTBoundObjEllipse: move p onto the ellipsoid surface when it lies outside.
extern "C" void func_0016E560(const sXform_E560* t, t4Vector* p)
{
    sMtx_E560 M = (const sMtx_E560&)D_004FF1A0;
    M = scaled_E560(M, sVec4_E560(1.0f / t->size.x, 1.0f / t->size.y, 1.0f / t->size.z, 1.0f));
    {
        sMtx_E560* m = &M;
        sMtx_E560 R;
        ROT_E560(R, &D_004FF160.x, -t->rot[0]);
        *m *= R;
    }
    {
        sMtx_E560* m = &M;
        sMtx_E560 R;
        ROT_E560(R, &D_004FF150.x, -t->rot[2]);
        *m *= R;
    }
    {
        sMtx_E560* m = &M;
        sMtx_E560 R;
        ROT_E560(R, &D_004FF140.x, -t->rot[1]);
        *m *= R;
    }
    vu0MulVecRow3_E560(&M, sVec4_E560(sVec3_E560(-t->pos.x, -t->pos.y, -t->pos.z), 1.0f));
    t4Vector q = vu0MulVec2_E560(&M, *p);
    q.w = 0.0f;
    if (q.x * q.x + q.y * q.y + q.z * q.z < 1.0f) {
        return;
    }
    q = Normalize_E560(q);
    q.w = 1.0f;
    M = (const sMtx_E560&)D_004FF1A0;
    vu0MulVecRow3_E560(&M, sVec4_E560(t->pos, 1.0f));
    {
        sMtx_E560* m = &M;
        sMtx_E560 R;
        ROT_E560(R, &D_004FF140.x, t->rot[1]);
        *m *= R;
    }
    {
        sMtx_E560* m = &M;
        sMtx_E560 R;
        ROT_E560(R, &D_004FF150.x, t->rot[2]);
        *m *= R;
    }
    {
        sMtx_E560* m = &M;
        sMtx_E560 R;
        ROT_E560(R, &D_004FF160.x, t->rot[0]);
        *m *= R;
    }
    M = scaled_E560(M, sVec4_E560(t->size.x, t->size.y, t->size.z, 1.0f));
    *p = vu0MulVec2_E560(&M, q);
    p->w = 1.0f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016F068);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" void func_0031BE50(float* sout, float* cout, float x);

extern t4Vector D_004FF140;
extern t4Vector D_004FF150;
extern t4Vector D_004FF160;
extern t4Matrix D_004FF1A0;

struct sVec3_F068 {
    float x, y, z;
    sVec3_F068() {}
    sVec3_F068(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sVec4_F068 : t4Vector
{
    sVec4_F068() {}
    sVec4_F068(const float& ax, const float& ay, const float& az, const float& aw) { x = ax; y = ay; z = az; w = aw; }
    sVec4_F068(const sVec3_F068& v, const float& aw) { x = v.x; y = v.y; z = v.z; w = aw; }
} __attribute__((aligned(16)));

struct sMtx_F068;

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply in place, d = b * d).
static inline void vu0MulMatEq_F068(sMtx_F068* d, const sMtx_F068* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0Copy_F068(sMtx_F068* d, const sMtx_F068* s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

struct sMtx_F068 {
    float m[4][4];
    sMtx_F068() {}
    sMtx_F068(const sMtx_F068& o) { vu0Copy_F068(this, &o); }
    sMtx_F068& operator=(const sMtx_F068& o)
    {
        vu0Copy_F068(this, &o);
        return *this;
    }
    sMtx_F068& operator*=(const sMtx_F068& b)
    {
        vu0MulMatEq_F068(this, &b);
        return *this;
    }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector into the last matrix row).
static inline void vu0MulVecRow3_F068(sMtx_F068* m, const t4Vector& v)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, %1\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, 0x30(%0)\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector, vector loaded first).
static inline t4Vector vu0MulVec2_F068(const sMtx_F068* m, const t4Vector& v)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector Sub_F068(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (d -= b).
static inline void SubEq_F068(t4Vector& d, const t4Vector& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(d)
        : "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector Scale_F068(const t4Vector& v, float s)
{
    t4Vector r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "o"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_F068(const t4Vector& a, const t4Vector& b)
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

struct sXform_F068 {
    sVec3_F068 pos;     // 0x0
    float rot[3];       // 0xC
    sVec3_F068 size;    // 0x18
};

// Multiply by a rotation of `angle` about the unit axis `a` (Rodrigues).
#define ROT_F068(R, a, angle) \
    { \
        const float* ax = a; \
        float s, c; \
        func_0031BE50(&s, &c, angle); \
        float t = 1.0f - c; \
        float x = ax[0]; \
        float y = ax[1]; \
        float z = ax[2]; \
        float tx = t * x; \
        float ty = t * y; \
        float tz = t * z; \
        float sx = s * x; \
        float sy = s * y; \
        float sz = s * z; \
        R.m[0][0] = tx * x + c; \
        R.m[1][0] = tx * y + sz; \
        R.m[2][0] = tx * z - sy; \
        R.m[0][1] = ty * x - sz; \
        R.m[1][1] = ty * y + c; \
        R.m[2][1] = ty * z + sx; \
        R.m[0][2] = tz * x + sy; \
        R.m[1][2] = tz * y - sx; \
        R.m[2][2] = tz * z + c; \
        R.m[3][0] = 0.0f; \
        R.m[3][1] = 0.0f; \
        R.m[3][2] = 0.0f; \
        R.m[0][3] = 0.0f; \
        R.m[1][3] = 0.0f; \
        R.m[2][3] = 0.0f; \
        R.m[3][3] = 1.0f; \
    }

extern int D_004A4DE8;              // guard of the static axis table below
extern t4Vector D_004C5450[3];      // static local: the three box axes

// cCTBoundObjBox: move p to the closest point of the (rotated) box.
extern "C" void func_0016F068(const sXform_F068* t, t4Vector* p)
{
    sMtx_F068 M = (const sMtx_F068&)D_004FF1A0;
    {
        sMtx_F068* m = &M;
        sMtx_F068 R;
        ROT_F068(R, &D_004FF160.x, -t->rot[0]);
        *m *= R;
    }
    {
        sMtx_F068* m = &M;
        sMtx_F068 R;
        ROT_F068(R, &D_004FF150.x, -t->rot[2]);
        *m *= R;
    }
    {
        sMtx_F068* m = &M;
        sMtx_F068 R;
        ROT_F068(R, &D_004FF140.x, -t->rot[1]);
        *m *= R;
    }
    vu0MulVecRow3_F068(&M, sVec4_F068(sVec3_F068(-t->pos.x, -t->pos.y, -t->pos.z), 1.0f));
    t4Vector q = vu0MulVec2_F068(&M, *p);
    q.w = 1.0f;
    t4Vector dmin = Sub_F068(q, sVec4_F068(sVec3_F068(-t->size.x, -t->size.y, -t->size.z), 1.0f));
    t4Vector dmax = Sub_F068(q, sVec4_F068(t->size.x, t->size.y, t->size.z, 1.0f));
    if (D_004A4DE8 == 0) {
        D_004C5450[0] = D_004FF140;
        D_004C5450[1] = D_004FF150;
        D_004C5450[2] = D_004FF160;
        D_004A4DE8 = 1;
    }
    for (int i = 0; i < 3; i++) {
        t4Vector n = Scale_F068(D_004C5450[i], -1.0f);
        float d = Dot_F068(n, dmin);
        if (d > 0.0f) {
            SubEq_F068(q, Scale_F068(n, d));
        }
        d = Dot_F068(D_004C5450[i], dmax);
        if (d > 0.0f) {
            SubEq_F068(q, Scale_F068(D_004C5450[i], d));
        }
    }
    M = (const sMtx_F068&)D_004FF1A0;
    vu0MulVecRow3_F068(&M, sVec4_F068(t->pos, 1.0f));
    {
        sMtx_F068* m = &M;
        sMtx_F068 R;
        ROT_F068(R, &D_004FF140.x, t->rot[1]);
        *m *= R;
    }
    {
        sMtx_F068* m = &M;
        sMtx_F068 R;
        ROT_F068(R, &D_004FF150.x, t->rot[2]);
        *m *= R;
    }
    {
        sMtx_F068* m = &M;
        sMtx_F068 R;
        ROT_F068(R, &D_004FF160.x, t->rot[0]);
        *m *= R;
    }
    *p = vu0MulVec2_F068(&M, q);
    p->w = 1.0f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016FBB8);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" void func_0031BE50(float* sout, float* cout, float x);

extern t4Vector D_004FF140;
extern t4Vector D_004FF150;
extern t4Vector D_004FF160;
extern t4Matrix D_004FF1A0;

struct sVec3_FBB8 {
    float x, y, z;
    sVec3_FBB8() {}
    sVec3_FBB8(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sVec4_FBB8 : t4Vector
{
    sVec4_FBB8() {}
    sVec4_FBB8(const float& ax, const float& ay, const float& az, const float& aw) { x = ax; y = ay; z = az; w = aw; }
    sVec4_FBB8(const sVec3_FBB8& v, const float& aw) { x = v.x; y = v.y; z = v.z; w = aw; }
} __attribute__((aligned(16)));

struct sMtx_FBB8;

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply in place, d = b * d).
static inline void vu0MulMatEq_FBB8(sMtx_FBB8* d, const sMtx_FBB8* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0Copy_FBB8(sMtx_FBB8* d, const sMtx_FBB8* s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

struct sMtx_FBB8 {
    float m[4][4];
    sMtx_FBB8() {}
    sMtx_FBB8(const sMtx_FBB8& o) { vu0Copy_FBB8(this, &o); }
    sMtx_FBB8& operator=(const sMtx_FBB8& o)
    {
        vu0Copy_FBB8(this, &o);
        return *this;
    }
    sMtx_FBB8& operator*=(const sMtx_FBB8& b)
    {
        vu0MulMatEq_FBB8(this, &b);
        return *this;
    }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector into the last matrix row).
static inline void vu0MulVecRow3_FBB8(sMtx_FBB8* m, const t4Vector& v)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, %1\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, 0x30(%0)\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector, vector loaded first).
static inline sVec4_FBB8 vu0MulVec2_FBB8(const sMtx_FBB8* m, const t4Vector& v)
{
    sVec4_FBB8 r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (scale matrix rows by the components of s).
static inline void vu0ScaleRows_FBB8(sMtx_FBB8* d, const sMtx_FBB8* m, const t4Vector& s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2      $vf8, 0x0(%0)\n"
        "sqc2      $vf9, 0x10(%0)\n"
        "sqc2      $vf10, 0x20(%0)\n"
        "sqc2      $vf11, 0x30(%0)\n"
        :
        : "r"(d), "r"(m), "m"(s)
        : "memory");
}

static inline sMtx_FBB8 scaled_FBB8(const sMtx_FBB8& m, const t4Vector& s)
{
    sMtx_FBB8 r;
    vu0ScaleRows_FBB8(&r, &m, s);
    return r;
}

struct sXform_FBB8 {
    sVec3_FBB8 pos;     // 0x0
    float rot[3];       // 0xC
    sVec3_FBB8 size;    // 0x18
    char pad_0x24[8];
    sVec3_FBB8 p0;      // 0x2C
    sVec3_FBB8 p1;      // 0x38
};

// Multiply by a rotation of `angle` about the unit axis `a` (Rodrigues).
#define ROT_FBB8(R, a, angle) \
    { \
        const float* ax = a; \
        float s, c; \
        func_0031BE50(&s, &c, angle); \
        float t = 1.0f - c; \
        float x = ax[0]; \
        float y = ax[1]; \
        float z = ax[2]; \
        float tx = t * x; \
        float ty = t * y; \
        float tz = t * z; \
        float sx = s * x; \
        float sy = s * y; \
        float sz = s * z; \
        R.m[0][0] = tx * x + c; \
        R.m[1][0] = tx * y + sz; \
        R.m[2][0] = tx * z - sy; \
        R.m[0][1] = ty * x - sz; \
        R.m[1][1] = ty * y + c; \
        R.m[2][1] = ty * z + sx; \
        R.m[0][2] = tz * x + sy; \
        R.m[1][2] = tz * y - sx; \
        R.m[2][2] = tz * z + c; \
        R.m[3][0] = 0.0f; \
        R.m[3][1] = 0.0f; \
        R.m[3][2] = 0.0f; \
        R.m[0][3] = 0.0f; \
        R.m[1][3] = 0.0f; \
        R.m[2][3] = 0.0f; \
        R.m[3][3] = 1.0f; \
    }

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector Sub_FBB8(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline t4Vector Add_FBB8(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector Scale_FBB8(const t4Vector& v, float s)
{
    t4Vector r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "o"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_FBB8(const t4Vector& a, const t4Vector& b)
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

// cCTBoundObjLine: move p to the closest point of the (transformed) line through p0 and p1.
extern "C" void func_0016FBB8(const sXform_FBB8* t, t4Vector* p)
{
    sMtx_FBB8 M = (const sMtx_FBB8&)D_004FF1A0;
    vu0MulVecRow3_FBB8(&M, sVec4_FBB8(t->pos, 1.0f));
    {
        sMtx_FBB8* m = &M;
        sMtx_FBB8 R;
        ROT_FBB8(R, &D_004FF140.x, t->rot[1]);
        *m *= R;
    }
    {
        sMtx_FBB8* m = &M;
        sMtx_FBB8 R;
        ROT_FBB8(R, &D_004FF150.x, t->rot[2]);
        *m *= R;
    }
    {
        sMtx_FBB8* m = &M;
        sMtx_FBB8 R;
        ROT_FBB8(R, &D_004FF160.x, t->rot[0]);
        *m *= R;
    }
    M = scaled_FBB8(M, sVec4_FBB8(t->size.x, t->size.y, t->size.z, 1.0f));
    sVec4_FBB8 e[2];
    e[0] = vu0MulVec2_FBB8(&M, sVec4_FBB8(t->p0.x, t->p0.y, t->p0.z, 1.0f));
    e[1] = vu0MulVec2_FBB8(&M, sVec4_FBB8(t->p1.x, t->p1.y, t->p1.z, 1.0f));
    t4Vector d = Sub_FBB8(e[1], e[0]);
    float k = Dot_FBB8(Sub_FBB8(*p, e[0]), d) / Dot_FBB8(d, d);
    *p = Add_FBB8(e[0], Scale_FBB8(d, k));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_00170240);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" void func_0031BE50(float* sout, float* cout, float x);

extern t4Vector D_004FF140;
extern t4Vector D_004FF150;
extern t4Vector D_004FF160;
extern t4Matrix D_004FF1A0;

struct sVec3_0240 {
    float x, y, z;
    sVec3_0240() {}
    sVec3_0240(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sVec4_0240 : t4Vector
{
    sVec4_0240() {}
    sVec4_0240(const float& ax, const float& ay, const float& az, const float& aw) { x = ax; y = ay; z = az; w = aw; }
    sVec4_0240(const sVec3_0240& v, const float& aw) { x = v.x; y = v.y; z = v.z; w = aw; }
} __attribute__((aligned(16)));

struct sMtx_0240;

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply in place, d = b * d).
static inline void vu0MulMatEq_0240(sMtx_0240* d, const sMtx_0240* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0Copy_0240(sMtx_0240* d, const sMtx_0240* s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

struct sMtx_0240 {
    float m[4][4];
    sMtx_0240() {}
    sMtx_0240(const sMtx_0240& o) { vu0Copy_0240(this, &o); }
    sMtx_0240& operator=(const sMtx_0240& o)
    {
        vu0Copy_0240(this, &o);
        return *this;
    }
    sMtx_0240& operator*=(const sMtx_0240& b)
    {
        vu0MulMatEq_0240(this, &b);
        return *this;
    }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector into the last matrix row).
static inline void vu0MulVecRow3_0240(sMtx_0240* m, const t4Vector& v)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, %1\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, 0x30(%0)\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector, vector loaded first).
static inline t4Vector vu0MulVec2_0240(const sMtx_0240* m, const t4Vector& v)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (scale matrix rows by the components of s).
static inline void vu0ScaleRows_0240(sMtx_0240* d, const sMtx_0240* m, const t4Vector& s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2      $vf8, 0x0(%0)\n"
        "sqc2      $vf9, 0x10(%0)\n"
        "sqc2      $vf10, 0x20(%0)\n"
        "sqc2      $vf11, 0x30(%0)\n"
        :
        : "r"(d), "r"(m), "m"(s)
        : "memory");
}

static inline sMtx_0240 scaled_0240(const sMtx_0240& m, const t4Vector& s)
{
    sMtx_0240 r;
    vu0ScaleRows_0240(&r, &m, s);
    return r;
}

struct sXform_0240 {
    sVec3_0240 pos;     // 0x0
    float rot[3];       // 0xC
    sVec3_0240 size;    // 0x18
    char pad_0x24[8];
    sVec3_0240 off;     // 0x2C
};

// Multiply by a rotation of `angle` about the unit axis `a` (Rodrigues).
#define ROT_0240(R, a, angle) \
    { \
        const float* ax = a; \
        float s, c; \
        func_0031BE50(&s, &c, angle); \
        float t = 1.0f - c; \
        float x = ax[0]; \
        float y = ax[1]; \
        float z = ax[2]; \
        float tx = t * x; \
        float ty = t * y; \
        float tz = t * z; \
        float sx = s * x; \
        float sy = s * y; \
        float sz = s * z; \
        R.m[0][0] = tx * x + c; \
        R.m[1][0] = tx * y + sz; \
        R.m[2][0] = tx * z - sy; \
        R.m[0][1] = ty * x - sz; \
        R.m[1][1] = ty * y + c; \
        R.m[2][1] = ty * z + sx; \
        R.m[0][2] = tz * x + sy; \
        R.m[1][2] = tz * y - sx; \
        R.m[2][2] = tz * z + c; \
        R.m[3][0] = 0.0f; \
        R.m[3][1] = 0.0f; \
        R.m[3][2] = 0.0f; \
        R.m[0][3] = 0.0f; \
        R.m[1][3] = 0.0f; \
        R.m[2][3] = 0.0f; \
        R.m[3][3] = 1.0f; \
    }

// Local-to-world point: translate, rotate (y, z, x axes), scale, then transform the offset.
extern "C" t4Vector func_00170240(const sXform_0240* t)
{
    sMtx_0240 M = (const sMtx_0240&)D_004FF1A0;
    vu0MulVecRow3_0240(&M, sVec4_0240(t->pos, 1.0f));
    {
        sMtx_0240* m = &M;
        sMtx_0240 R;
        ROT_0240(R, &D_004FF140.x, t->rot[1]);
        *m *= R;
    }
    {
        sMtx_0240* m = &M;
        sMtx_0240 R;
        ROT_0240(R, &D_004FF150.x, t->rot[2]);
        *m *= R;
    }
    {
        sMtx_0240* m = &M;
        sMtx_0240 R;
        ROT_0240(R, &D_004FF160.x, t->rot[0]);
        *m *= R;
    }
    M = scaled_0240(M, sVec4_0240(t->size.x, t->size.y, t->size.z, 1.0f));
    return vu0MulVec2_0240(&M, sVec4_0240(t->off.x, t->off.y, t->off.z, 1.0f));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_001707B0);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" void func_0031BE50(float* sout, float* cout, float x);

extern t4Vector D_004FF140;
extern t4Vector D_004FF150;
extern t4Vector D_004FF160;
extern t4Matrix D_004FF1A0;

struct sVec3_07B0 {
    float x, y, z;
    sVec3_07B0() {}
    sVec3_07B0(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sVec4_07B0 : t4Vector
{
    sVec4_07B0() {}
    sVec4_07B0(const float& ax, const float& ay, const float& az, const float& aw) { x = ax; y = ay; z = az; w = aw; }
    sVec4_07B0(const sVec3_07B0& v, const float& aw) { x = v.x; y = v.y; z = v.z; w = aw; }
} __attribute__((aligned(16)));

struct sMtx_07B0;

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply in place, d = b * d).
static inline void vu0MulMatEq_07B0(sMtx_07B0* d, const sMtx_07B0* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0Copy_07B0(sMtx_07B0* d, const sMtx_07B0* s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

struct sMtx_07B0 {
    float m[4][4];
    sMtx_07B0() {}
    sMtx_07B0(const sMtx_07B0& o) { vu0Copy_07B0(this, &o); }
    sMtx_07B0& operator=(const sMtx_07B0& o)
    {
        vu0Copy_07B0(this, &o);
        return *this;
    }
    sMtx_07B0& operator*=(const sMtx_07B0& b)
    {
        vu0MulMatEq_07B0(this, &b);
        return *this;
    }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector into the last matrix row).
static inline void vu0MulVecRow3_07B0(sMtx_07B0* m, const t4Vector& v)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, %1\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, 0x30(%0)\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector, vector loaded first).
static inline t4Vector vu0MulVec2_07B0(const sMtx_07B0* m, const t4Vector& v)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (scale matrix rows by the components of s).
static inline void vu0ScaleRows_07B0(sMtx_07B0* d, const sMtx_07B0* m, const t4Vector& s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2      $vf8, 0x0(%0)\n"
        "sqc2      $vf9, 0x10(%0)\n"
        "sqc2      $vf10, 0x20(%0)\n"
        "sqc2      $vf11, 0x30(%0)\n"
        :
        : "r"(d), "r"(m), "m"(s)
        : "memory");
}

static inline sMtx_07B0 scaled_07B0(const sMtx_07B0& m, const t4Vector& s)
{
    sMtx_07B0 r;
    vu0ScaleRows_07B0(&r, &m, s);
    return r;
}

struct sXform_07B0 {
    sVec3_07B0 pos;     // 0x0
    float rot[3];       // 0xC
    sVec3_07B0 size;    // 0x18
    char pad_0x24[8];
    sVec3_07B0 p0;      // 0x2C
    sVec3_07B0 p1;      // 0x38
};

// Multiply by a rotation of `angle` about the unit axis `a` (Rodrigues).
#define ROT_07B0(R, a, angle) \
    { \
        const float* ax = a; \
        float s, c; \
        func_0031BE50(&s, &c, angle); \
        float t = 1.0f - c; \
        float x = ax[0]; \
        float y = ax[1]; \
        float z = ax[2]; \
        float tx = t * x; \
        float ty = t * y; \
        float tz = t * z; \
        float sx = s * x; \
        float sy = s * y; \
        float sz = s * z; \
        R.m[0][0] = tx * x + c; \
        R.m[1][0] = tx * y + sz; \
        R.m[2][0] = tx * z - sy; \
        R.m[0][1] = ty * x - sz; \
        R.m[1][1] = ty * y + c; \
        R.m[2][1] = ty * z + sx; \
        R.m[0][2] = tz * x + sy; \
        R.m[1][2] = tz * y - sx; \
        R.m[2][2] = tz * z + c; \
        R.m[3][0] = 0.0f; \
        R.m[3][1] = 0.0f; \
        R.m[3][2] = 0.0f; \
        R.m[0][3] = 0.0f; \
        R.m[1][3] = 0.0f; \
        R.m[2][3] = 0.0f; \
        R.m[3][3] = 1.0f; \
    }

// Local-to-world point: translate, rotate (y, z, x axes), scale, then transform the second point.
extern "C" t4Vector func_001707B0(const sXform_07B0* t)
{
    sMtx_07B0 M = (const sMtx_07B0&)D_004FF1A0;
    vu0MulVecRow3_07B0(&M, sVec4_07B0(t->pos, 1.0f));
    {
        sMtx_07B0* m = &M;
        sMtx_07B0 R;
        ROT_07B0(R, &D_004FF140.x, t->rot[1]);
        *m *= R;
    }
    {
        sMtx_07B0* m = &M;
        sMtx_07B0 R;
        ROT_07B0(R, &D_004FF150.x, t->rot[2]);
        *m *= R;
    }
    {
        sMtx_07B0* m = &M;
        sMtx_07B0 R;
        ROT_07B0(R, &D_004FF160.x, t->rot[0]);
        *m *= R;
    }
    M = scaled_07B0(M, sVec4_07B0(t->size.x, t->size.y, t->size.z, 1.0f));
    return vu0MulVec2_07B0(&M, sVec4_07B0(t->p1.x, t->p1.y, t->p1.z, 1.0f));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerman", func_00170D20);
#ifdef SKIP_ASM
#include "bx/math3d.h"
extern "C" void func_0031BE50(float* sout, float* cout, float x);

extern t4Vector D_004FF140;
extern t4Vector D_004FF150;
extern t4Vector D_004FF160;
extern t4Matrix D_004FF1A0;

struct sVec3_0D20 {
    float x, y, z;
    sVec3_0D20() {}
    sVec3_0D20(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct sVec4_0D20 : t4Vector
{
    sVec4_0D20() {}
    sVec4_0D20(const float& ax, const float& ay, const float& az, const float& aw) { x = ax; y = ay; z = az; w = aw; }
    sVec4_0D20(const sVec3_0D20& v, const float& aw) { x = v.x; y = v.y; z = v.z; w = aw; }
} __attribute__((aligned(16)));

struct sMtx_0D20;

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply in place, d = b * d).
static inline void vu0MulMatEq_0D20(sMtx_0D20* d, const sMtx_0D20* b)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, 0x0(%1)\n"
        "lqc2      $vf9, 0x10(%1)\n"
        "lqc2      $vf10, 0x20(%1)\n"
        "lqc2      $vf11, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        :
        : "r"(d), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix copy through VU0 registers).
static inline void vu0Copy_0D20(sMtx_0D20* d, const sMtx_0D20* s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(d), "r"(s)
        : "memory");
}

struct sMtx_0D20 {
    float m[4][4];
    sMtx_0D20() {}
    sMtx_0D20(const sMtx_0D20& o) { vu0Copy_0D20(this, &o); }
    sMtx_0D20& operator=(const sMtx_0D20& o)
    {
        vu0Copy_0D20(this, &o);
        return *this;
    }
    sMtx_0D20& operator*=(const sMtx_0D20& b)
    {
        vu0MulMatEq_0D20(this, &b);
        return *this;
    }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector into the last matrix row).
static inline void vu0MulVecRow3_0D20(sMtx_0D20* m, const t4Vector& v)
{
    __asm__ __volatile__(
        "lqc2      $vf4, 0x0(%0)\n"
        "lqc2      $vf5, 0x10(%0)\n"
        "lqc2      $vf6, 0x20(%0)\n"
        "lqc2      $vf7, 0x30(%0)\n"
        "lqc2      $vf8, %1\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, 0x30(%0)\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix times vector, vector loaded first).
static inline t4Vector vu0MulVec2_0D20(const sMtx_0D20* m, const t4Vector& v)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (scale matrix rows by the components of s).
static inline void vu0ScaleRows_0D20(sMtx_0D20* d, const sMtx_0D20* m, const t4Vector& s)
{
    __asm__ __volatile__(
        "lqc2      $vf1, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf1x\n"
        "vmuly.xyzw $vf9, $vf5, $vf1y\n"
        "vmulz.xyzw $vf10, $vf6, $vf1z\n"
        "vmulw.xyzw $vf11, $vf7, $vf1w\n"
        "sqc2      $vf8, 0x0(%0)\n"
        "sqc2      $vf9, 0x10(%0)\n"
        "sqc2      $vf10, 0x20(%0)\n"
        "sqc2      $vf11, 0x30(%0)\n"
        :
        : "r"(d), "r"(m), "m"(s)
        : "memory");
}

static inline sMtx_0D20 scaled_0D20(const sMtx_0D20& m, const t4Vector& s)
{
    sMtx_0D20 r;
    vu0ScaleRows_0D20(&r, &m, s);
    return r;
}

struct sXform_0D20 {
    sVec3_0D20 pos;     // 0x0
    float rot[3];       // 0xC
    sVec3_0D20 size;    // 0x18
    char pad_0x24[4];
    sVec3_0D20 pts[1];  // 0x28
};

// Multiply by a rotation of `angle` about the unit axis `a` (Rodrigues).
#define ROT_0D20(R, a, angle) \
    { \
        const float* ax = a; \
        float s, c; \
        func_0031BE50(&s, &c, angle); \
        float t = 1.0f - c; \
        float x = ax[0]; \
        float y = ax[1]; \
        float z = ax[2]; \
        float tx = t * x; \
        float ty = t * y; \
        float tz = t * z; \
        float sx = s * x; \
        float sy = s * y; \
        float sz = s * z; \
        R.m[0][0] = tx * x + c; \
        R.m[1][0] = tx * y + sz; \
        R.m[2][0] = tx * z - sy; \
        R.m[0][1] = ty * x - sz; \
        R.m[1][1] = ty * y + c; \
        R.m[2][1] = ty * z + sx; \
        R.m[0][2] = tz * x + sy; \
        R.m[1][2] = tz * y - sx; \
        R.m[2][2] = tz * z + c; \
        R.m[3][0] = 0.0f; \
        R.m[3][1] = 0.0f; \
        R.m[3][2] = 0.0f; \
        R.m[0][3] = 0.0f; \
        R.m[1][3] = 0.0f; \
        R.m[2][3] = 0.0f; \
        R.m[3][3] = 1.0f; \
    }

// Local-to-world point: translate, rotate (y, z, x axes), scale, then transform point i.
extern "C" t4Vector func_00170D20(const sXform_0D20* t, int i)
{
    sMtx_0D20 M = (const sMtx_0D20&)D_004FF1A0;
    vu0MulVecRow3_0D20(&M, sVec4_0D20(t->pos, 1.0f));
    {
        sMtx_0D20* m = &M;
        sMtx_0D20 R;
        ROT_0D20(R, &D_004FF140.x, t->rot[1]);
        *m *= R;
    }
    {
        sMtx_0D20* m = &M;
        sMtx_0D20 R;
        ROT_0D20(R, &D_004FF150.x, t->rot[2]);
        *m *= R;
    }
    {
        sMtx_0D20* m = &M;
        sMtx_0D20 R;
        ROT_0D20(R, &D_004FF160.x, t->rot[0]);
        *m *= R;
    }
    M = scaled_0D20(M, sVec4_0D20(t->size.x, t->size.y, t->size.z, 1.0f));
    return vu0MulVec2_0D20(&M, sVec4_0D20(t->pts[i], 1.0f));
}
#endif

