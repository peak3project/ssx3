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

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016E1D8);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016E560);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016F068);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_0016FBB8);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_00170240);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_001707B0);

INCLUDE_ASM("camera/trigger/cameratriggerman", func_00170D20);

