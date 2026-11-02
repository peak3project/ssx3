#include "common.h"
#include "bx/math3d.h"

// Script-binding layer shared by the bound functions of this unit. Every binding unpacks its argument list the same
// way (the binding's defaults record is copied into a local record, then each passed argument is stored by index,
// with an int->float conversion when the binding's type table says the slot is a float) and reports an int result
// through the same two stores. Both are statement macros (do { } while (0)); the loop notes they leave weight the
// register references inside them, which is why the bodies must stay macro expansions.
// Script value (luno/lunovm.cpp layout); D_004C9098 is the nil value the bindings return.
struct cLunoValue {
    int word0;
    int word1;
    int type;
};
extern cLunoValue D_004C9098;
// Reference sets of the current world (wscript/wscriptman.cpp layout). A reference id packs the set index (low 8 bits)
// and the slot; refs[slot] >> 8 is the object address >> 2.
struct sRefSet {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};
struct sRefWorld {
    char pad_0x0[0x8];
    sRefSet** sets;         // 0x8
};
extern sRefWorld** D_004A47B8;
// The script manager (cWScriptMan in the prototype, whose setBeing stores at 0x0); D_004A3DD8 points at the instance.
struct cWScriptMan {
    int being;              // 0x0: index of the current being (rider)
    char pad_0x4[0x28C];
    char* f290;             // 0x290: object of the reference id -1
    void* f294;             // 0x294
    int f298;               // 0x298
    char pad_0x29C[0x8];
    char* f2A4;             // 0x2A4
};
extern cWScriptMan* D_004A3DD8;
// A being: the script/AI-facing interface of a rider. Slot order of the prototype's vtable _vt$6cBeing; parameter
// types from its mangled names (applyBoost__6cBeingRC8t4Vector, transport__6cBeingRC8t4Matrix, ...).
struct tInstanceRecord;
class cBeing {
public:
    virtual ~cBeing();
    virtual const t4Vector* getVelocity() const;
    virtual int isIntersecting(tInstanceRecord* rec) const;
    virtual void applyBoost(const t4Vector& impulse);
    virtual const t4Vector* getPosition() const;
    virtual const t4Matrix* getTransform() const;
    virtual int getAIIndex() const;
    virtual bool isHuman() const;
    virtual bool isComputer() const;
    virtual void transport(const t4Matrix& m);
    virtual void resetToPath();
    virtual void initForMission(const t4Matrix& m);
};
// The scene node of a world object (the object holds it at +0xC): the prototype's cObjNode / cTypeObjNode /
// cInstanceNode family. Slot 1 is the virtual destructor; isType (10) and isMoveNode (16) are named as in the
// prototype's _vt$13cInstanceNode; the other slots are known only by position.
struct cInstanceNode_1FBE38 {
    int p0, p1, p2;
    virtual ~cInstanceNode_1FBE38();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual int isType(int type) const;
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int isMoveNode();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual t4Matrix* v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual float v30();
    virtual int v31();
    virtual int v32(float);
    virtual void v33();
    virtual void v34(int);
    virtual void v35();
    virtual void v36(int, float);
    virtual void v37();
};
// A plain (not 16-byte aligned) 4-float vector built in place for the node calls that take a vector pointer.
struct sVec4_1FBE38 { float x, y, z, w; sVec4_1FBE38(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };
// A rider as these bindings see it (include/ai/rider.h has the flat layout): its cBeing base sits at 0x6C0, after the
// rider's own data, so converting between cRider_1FBE38* and cBeing* adds/subtracts 0x6C0 with a null check.
struct cRiderData_1FBE38 {
    char pad_0x0[0x3FC];
    int unk_3FC;                // 0x3FC (cRider::unk_3FC)
    char pad_0x400[0x2C0];
};
struct sRiderHandler_1FBE38 {
    char pad_0x0[0xD4];
    unsigned int fD4;           // 0xD4
};
class cRider_1FBE38 : public cRiderData_1FBE38, public cBeing {
public:
    char pad_0x6C4[0xB8];
    sRiderHandler_1FBE38* mRiderHandler;    // 0x77C (cRider::mRiderHandler)
    char pad_0x780[0xF0];
    int mViewIndex;             // 0x870 (cRider::mViewIndex)
    int mIsHuman;               // 0x874
    int mIsActor;               // 0x878
    int mIsLocal;               // 0x87C
};
// The race (main/gamemode.cpp layout): riders by being index at 0x28; each player holds its rider at +0x18.
struct sRacePlayer {
    char pad_0x0[0x18];
    cRider_1FBE38* rider;       // 0x18
};
struct sRace {
    char pad_0x0[0x28];
    cRider_1FBE38* riders[6];   // 0x28
    sRacePlayer* players[12];   // 0x40
    sRacePlayer* players2[3];   // 0x70
    int numPlayers;             // 0x7C
    char pad_0x80[0x8];
    int numPlayers2;            // 0x88
    char pad_0x8C[0x1C];
    void* fA8;                  // 0xA8
};
// The game's cameras (camera/camera.cpp); one per view, indexed by cRider::mViewIndex.
struct sCameras {
    int f0;                     // 0x0
    char* cam[1];               // 0x4
};
struct sGame {
    char pad_0x0[0xC];
    sRace* race;                // 0xC
    char pad_0x10[0x18];
    void* f28;                  // 0x28
    char pad_0x2C[0x4C];
    char* f78;                  // 0x78
    char pad_0x7C[0x8];
    sCameras* cameras;          // 0x84
};
// The game singleton (D_004A28A8).
struct sApp {
    char pad_0x0[0x14];
    float f14;                  // 0x14
    char pad_0x18[0x60];
    void* f78;                  // 0x78
    char pad_0x7C[0x8];
    sGame* game;                // 0x84
    char pad_0x88[0x38];
    int fC0;                    // 0xC0
};
extern sApp* D_004A28A8;
extern char* D_004A28A4;
extern void* D_004A4028;
// One script argument as the VM passes it to a binding: the slot index in the defaults record, then the value
// (cLunoValue layout: value word, second word, type).
struct sBindArg_1FBE38 { int idx; int val; int pad; int type; };
struct sBindEnd_1FBE38 {};  // empty trailing member of a defaults record; value-init copies its byte through a stack temp
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
#define BIND_UNPACK_ARGS_1FBE38(vp, rec, defaults, size, types, n, args) do { \
        vp = rec; \
        func_003E6574(vp, defaults, size); \
        sBindArg_1FBE38* p_ = args; \
        for (int i_ = 0; i_ < n; i_++, p_++) { \
            int k_ = p_->idx; \
            int* d_ = (int*)((k_ << 2) + (int)vp); \
            if (p_->type != (types)[k_] && (types)[k_] == 2) \
                *(float*)d_ = (float)p_->val; \
            else \
                *d_ = p_->val; \
        } \
    } while (0)
#define BIND_SET_RESULT_1FBE38(ret, value) do { \
        int r_ = (value); \
        (ret)->type = 1; \
        *func_00226610(ret) = r_; \
    } while (0)

// Reference ids: refs[slot] >> 8 is the object address >> 2 (0 = no object); the id -1 names the script manager's
// current object.
static inline char *refToPtr_1FBE38(unsigned i) { return (char*)(i << 2); }
static inline char *refToObj_1FBE38(unsigned i) { if (i == 0) return 0; return refToPtr_1FBE38(i); }
static inline char *lookupRef_1FBE38(unsigned id) {
    if (~id == 0)
        return D_004A3DD8->f290;
    sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
    unsigned i;
    if (!s || (i = s->refs[id >> 8] >> 8) == 0)
        return 0;
    return (char*)(i << 2);
}


//100%
INCLUDE_ASM("seg/seg_1FBE38", checkActiveNode);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern char D_00489618_AE38[] __asm__("D_00489618");
extern char D_00489628_AE38[] __asm__("D_00489628");
extern char D_00489638_AE38[] __asm__("D_00489638");
extern char D_00489648_AE38[] __asm__("D_00489648");
extern "C" void* func_003578A8_AE38(void*, int, void*, void*, void*) __asm__("func_003578A8");
extern "C" void func_00351B40_AE38(void*, int, void*, void*, void*, void*) __asm__("func_00351B40");
extern "C" void* func_00342C08_AE38(void*, int, void*, void*, void*) __asm__("func_00342C08");
extern "C" void cDeadFadeNode_cDeadFadeNode_AE38(void*, int, void*, void*, void*) __asm__("cDeadFadeNode_cDeadFadeNode");
extern "C" int checkActiveNode(void *a, int type, void *buf) {
    cInstanceNode_1FBE38 *n = (cInstanceNode_1FBE38*)a;
    if (n->isType(9) || n->isType(6) || n->isType(22))
        return 1;
    if (n->isType(type)) {
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
        func_00351B40_AE38(cMemMan_alloc(0x6C0, D_00489628_AE38, 0x20000000, 0), 1, o, buf, D_004A3DD8->f294, n);
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
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00359228(void*, int, void*, void*);
extern char D_00489658_B060[] __asm__("D_00489658");
extern unsigned D_B060[] __asm__("D_004FB390");
extern int D_004A55C0;
extern const int D_00445E70[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FB060(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_B060 + 40) = sBindEnd_1FBE38();
    }
    unsigned buf64[11];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_B060, 44);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 2, buf))
        return D_004C9098;
    func_00359228(cMemMan_alloc(0x70, D_00489658_B060, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB270);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00358C80_B270(void*, int, void*, void*) __asm__("func_00358C80");
extern char D_00489668_B270[] __asm__("D_00489668");
extern unsigned D_B270[] __asm__("D_004FB3C0");
extern int D_004A55C4;
extern const int D_00445E98[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FB270(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_B270 + 56) = sBindEnd_1FBE38();
    }
    unsigned buf64[15];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_B270, 60);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 3, buf))
        return D_004C9098;
    func_00358C80_B270(cMemMan_alloc(0x88, D_00489668_B270, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_003421A0(void*, int, void*, void*);
extern char D_00489678_B498[] __asm__("D_00489678");
extern unsigned D_B498[] __asm__("D_004FB400");
extern int D_004A55C8;
extern const int D_00445ED0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FB498(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_B498 + 40) = sBindEnd_1FBE38();
    }
    unsigned buf64[11];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_B498, 44);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 4, buf))
        return D_004C9098;
    func_003421A0(cMemMan_alloc(0x80, D_00489678_B498, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB6B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00343010(void*, int, void*, void*);
extern char D_00489688_B6B8[] __asm__("D_00489688");
extern unsigned D_B6B8[] __asm__("D_004FB430");
extern int D_004A55CC;
extern const int D_00445EF8[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FB6B8(int n, sBindArg_1FBE38 *e) {
    if (D_004A55CC == 0) {
        D_B6B8[0] = 0xFFFFFFFF;
        *(float*)&D_B6B8[1] = 100.0f;
        *(float*)&D_B6B8[3] = *(float*)&D_B6B8[2] = 0.0f;
        ((int*)D_B6B8)[4] = 0;
        ((int*)D_B6B8)[5] = 0;
        ((int*)D_B6B8)[6] = 0;
        ((int*)D_B6B8)[7] = 0;
        ((int*)D_B6B8)[8] = 0;
        ((int*)D_B6B8)[9] = 0;
        ((int*)D_B6B8)[10] = 0;
        ((int*)D_B6B8)[11] = 0;
        D_004A55CC = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_B6B8 + 48) = sBindEnd_1FBE38();
    }
    unsigned buf64[13];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_B6B8, 52);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 15, buf))
        return D_004C9098;
    func_00343010(cMemMan_alloc(0x48, D_00489688_B6B8, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FB8D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00343768(void*, int, void*, void*);
extern char D_004A3BE8_B8D0[] __asm__("D_004A3BE8");
extern unsigned D_B8D0[] __asm__("D_004FB468");
extern int D_004A55D0;
extern int D_004A3BE0_B8D0[2] __asm__("D_004A3BE0");
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FB8D0(int n, sBindArg_1FBE38 *e) {
    if (D_004A55D0 == 0) {
        D_B8D0[0] = 0xFFFFFFFF;
        ((int*)D_B8D0)[1] = 3;
        D_004A55D0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_B8D0 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_B8D0, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 7, buf))
        return D_004C9098;
    func_00343768(cMemMan_alloc(0x24, D_004A3BE8_B8D0, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FBAB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_0034EC58(void*, int, void*, void*);
extern char D_00489698_BAB0[] __asm__("D_00489698");
extern unsigned D_BAB0[] __asm__("D_004FB478");
extern int D_004A55D4;
extern const int D_00445F28[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FBAB0(int n, sBindArg_1FBE38 *e) {
    if (D_004A55D4 == 0) {
        D_BAB0[0] = 0xFFFFFFFF;
        *(float*)&D_BAB0[1] = 10.0f;
        *(float*)&D_BAB0[2] = 10.0f;
        *(float*)&D_BAB0[3] = 40.0f;
        *(float*)&D_BAB0[4] = 10.0f;
        *(float*)&D_BAB0[5] = 0.20000000298023224f;
        *(float*)&D_BAB0[6] = 10.0f;
        D_004A55D4 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_BAB0 + 28) = sBindEnd_1FBE38();
    }
    unsigned buf64[8];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_BAB0, 32);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 14, buf))
        return D_004C9098;
    func_0034EC58(cMemMan_alloc(0x7C, D_00489698_BAB0, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FBCB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00341AA0(void*, int, int, void*, void*);
extern char D_004896A8_BCB8[] __asm__("D_004896A8");
extern unsigned D_BCB8[] __asm__("D_004FB498");
extern int D_004A55D8;
extern const int D_00445F48[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FBCB8(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_BCB8 + 40) = sBindEnd_1FBE38();
    }
    unsigned buf64[11];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_BCB8, 44);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 1, buf))
        return D_004C9098;
    func_00341AA0(cMemMan_alloc(0x6C, D_004896A8_BCB8, 0x20000000, 0), 1, 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FBEC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00341388_BEC8(void*, int, int, void*, void*) __asm__("func_00341388");
extern char D_004A3BF0_BEC8[] __asm__("D_004A3BF0");
extern unsigned D_BEC8[] __asm__("D_004FB4C8");
extern int D_004A55DC;
extern const int D_00445F70[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FBEC8(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_BEC8 + 32) = sBindEnd_1FBE38();
    }
    unsigned buf64[9];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_BEC8, 36);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 8, buf))
        return D_004C9098;
    func_00341388_BEC8(cMemMan_alloc(0x50, D_004A3BF0_BEC8, 0x20000000, 0), 1, 8, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC0D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00356DB0(void*, int, void*, int, bool);
extern char D_004A3BF8_C0D0[] __asm__("D_004A3BF8");
extern unsigned D_C0D0[] __asm__("D_004FB4F0");
extern int D_004A55E0;
extern const int D_00445F90[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FC0D0(int n, sBindArg_1FBE38 *e) {
    if (D_004A55E0 == 0) {
        D_C0D0[0] = 0xFFFFFFFF;
        ((int*)D_C0D0)[1] = 0;
        ((int*)D_C0D0)[2] = 0;
        D_004A55E0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_C0D0 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_C0D0, 16);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 17, buf))
        return D_004C9098;
    func_00356DB0(cMemMan_alloc(0x2C, D_004A3BF8_C0D0, 0x20000000, 0), 1, obj, buf[1], buf[2] != 0);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC2C0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_003506D8(void*, void*);
extern "C" void* func_00350F60(void*, void*);
extern char D_004896B8[];
extern char D_004896C8[];

extern "C" void func_002FC2C0(char* self, char* ev) {
    switch (*(int*)(ev + 4)) {
    case 1: {
        char* o = *(char**)(self + 0xC);
        if (o) {
            if (*(short*)(o + 0x10) == 6)
                break;
            delete (cInstanceNode_1FBE38*)o;
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
            delete (cInstanceNode_1FBE38*)o;
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
            delete (cInstanceNode_1FBE38*)o;
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
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void func_002FC2C0_C420(void*, void*) __asm__("func_002FC2C0");
extern unsigned D_C420[] __asm__("D_004FB500");
extern int D_004A55E4;
extern int D_004A3C00;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FC420(int n, sBindArg_1FBE38 *e) {
    if (D_004A55E4 == 0) {
        D_C420[0] = 0xFFFFFFFF;
        ((int*)D_C420)[1] = 0;
        D_004A55E4 = 1;
        *(sBindEnd_1FBE38*)((char*)D_C420 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_C420, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (!p || !checkActiveNode(p, 6, buf))
        func_002FC2C0_C420(obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC5D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void cDeadFadeNode_cDeadFadeNode_C5D8(void*, int, void*, void*, int) __asm__("cDeadFadeNode_cDeadFadeNode");
extern char D_004896D8_C5D8[] __asm__("D_004896D8");
extern unsigned D_C5D8[] __asm__("D_004FB510");
extern int D_004A55E8;
extern const int D_00445FA0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FC5D8(int n, sBindArg_1FBE38 *e) {
    if (D_004A55E8 == 0) {
        D_C5D8[0] = 0xFFFFFFFF;
        ((int*)D_C5D8)[1] = 0;
        *(float*)&D_C5D8[2] = 2.0f;
        *(float*)&D_C5D8[3] = 25.0f;
        D_004A55E8 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_C5D8 + 16) = sBindEnd_1FBE38();
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_C5D8, 20);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 22, buf))
        return D_004C9098;
    cDeadFadeNode_cDeadFadeNode_C5D8(cMemMan_alloc(0x3C, D_004896D8_C5D8, 0x20000000, 0), 1, obj, buf, 0);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC7D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00342C08_C7D0(void*, int, void*, void*, void*) __asm__("func_00342C08");
extern char D_004896E8_C7D0[] __asm__("D_004896E8");
extern unsigned D_C7D0[] __asm__("D_004FB528");
extern int D_004A55EC;
extern const int D_00445FB0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FC7D0(int n, sBindArg_1FBE38 *e) {
    if (D_004A55EC == 0) {
        D_C7D0[0] = 0xFFFFFFFF;
        *(float*)&D_C7D0[1] = 1.0f;
        ((int*)D_C7D0)[2] = 1;
        ((int*)D_C7D0)[3] = -1;
        D_004A55EC = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_C7D0 + 16) = sBindEnd_1FBE38();
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_C7D0, 20);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 0, buf))
        return D_004C9098;
    func_00342C08_C7D0(cMemMan_alloc(0x34, D_004896E8_C7D0, 0x20000000, 0), 1, obj, buf, 0);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FC9C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_0034ADD8(void*, int, void*, void*);
extern char D_004A3C08_C9C8[] __asm__("D_004A3C08");
extern unsigned D_C9C8[] __asm__("D_004FB540");
extern int D_004A55F0;
extern const int D_00445FC0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FC9C8(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_C9C8 + 104) = sBindEnd_1FBE38();
    }
    unsigned buf64[27];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_C9C8, 108);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 10, buf))
        return D_004C9098;
    func_0034ADD8(cMemMan_alloc(0x1C, D_004A3C08_C9C8, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FCC20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_CC20[] __asm__("D_004FB5B0");
extern int D_004A55F4;
extern const int D_00446028[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" int checkActiveNode(void*, int, void*);
#define ASSERT_CC20(c) do { } while (0)

// PORT: struct return written with the hidden return pointer explicit.
extern "C" cLunoValue* func_002FCC20(cLunoValue* ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A55F4 == 0) {
        D_CC20[0] = 0xFFFFFFFF;
        *(float*)&D_CC20[2] = 0.5f;
        ((int*)D_CC20)[1] = 0;
        D_004A55F4 = 1;
        *(sBindEnd_1FBE38*)((char*)D_CC20 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_CC20, 16);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
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
        *ret = D_004C9098;
        ASSERT_CC20(ret);
        return ret;
    } while (0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FCDC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00346350(void*, int, void*, void*);
extern char D_004896F8_CDC8[] __asm__("D_004896F8");
extern unsigned D_CDC8[] __asm__("D_004FB5C0");
extern int D_004A55F8;
extern const int D_00446038[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FCDC8(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_CDC8 + 36) = sBindEnd_1FBE38();
    }
    unsigned buf64[10];
    unsigned *buf = buf64;
    buf64[8] = 0xFFFFFFFF;
    func_003E6574(buf, D_CDC8, 40);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 5, buf))
        return D_004C9098;
    func_00346350(cMemMan_alloc(0xB0, D_004896F8_CDC8, 0x20000000, 0), 1, obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FCFF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void func_00351B40_CFF0(void*, int, void*, void*, void*, void*) __asm__("func_00351B40");
extern char D_00489708_CFF0[] __asm__("D_00489708");
extern unsigned D_CFF0[] __asm__("D_004FB5E8");
extern int D_004A55FC;
extern const int D_00446060[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FCFF0(int n, sBindArg_1FBE38 *e) {
    if (D_004A55FC == 0) {
        D_CFF0[0] = 0xFFFFFFFF;
        ((int*)D_CFF0)[1] = 0;
        *(float*)&D_CFF0[2] = 0.10000000149011612f;
        *(float*)&D_CFF0[3] = 1.0f;
        *(float*)&D_CFF0[4] = 2.0f;
        *(float*)&D_CFF0[5] = 600.0f;
        *(float*)&D_CFF0[6] = 600.0f;
        *(float*)&D_CFF0[7] = 300.0f;
        *(float*)&D_CFF0[10] = *(float*)&D_CFF0[9] = *(float*)&D_CFF0[8] = 0.0f;
        *(float*)&D_CFF0[11] = 360.0f;
        *(float*)&D_CFF0[12] = -1.0f;
        D_CFF0[13] = 0xFFFFFFFF;
        ((int*)D_CFF0)[14] = -1;
        D_004A55FC = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_CFF0 + 60) = sBindEnd_1FBE38();
    }
    unsigned buf64[16];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[13] = 0xFFFFFFFF;
    func_003E6574(buf, D_CFF0, 64);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 11, buf))
        return D_004C9098;
    func_00351B40_CFF0(cMemMan_alloc(0x6C0, D_00489708_CFF0, 0x20000000, 0), 1, obj, buf, D_004A3DD8->f294, 0);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD250);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355DB8_D250(void*, void*, int, void*) __asm__("func_00355DB8");
extern unsigned D_D250[] __asm__("D_004FB628");
extern int D_004A5600;
extern const int D_004460A0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FD250(int n, sBindArg_1FBE38 *e) {
    if (D_004A5600 == 0) {
        D_D250[0] = 0xFFFFFFFF;
        *(float*)&D_D250[1] = 1.0f;
        *(float*)&D_D250[2] = 0.699999988079071f;
        *(float*)&D_D250[3] = 0.5f;
        D_004A5600 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_D250 + 16) = sBindEnd_1FBE38();
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_D250, 20);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        if (p->isMoveNode())
            func_00355DB8_D250(p, buf, D_004A3DD8->f298, D_004A3DD8->f294);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD420);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_003578A8_D420(void*, int, void*, void*, void*) __asm__("func_003578A8");
void operator_delete(int*);
extern char D_00489718_D420[] __asm__("D_00489718");
extern char D_00489730_D420[] __asm__("D_00489730");
extern unsigned D_D420[] __asm__("D_004FB640");
extern int D_004A5604;
extern const int D_004460B0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FD420(int n, sBindArg_1FBE38 *e) {
    if (D_004A5604 == 0) {
        ((int*)D_D420)[0] = 1;
        ((int*)D_D420)[1] = 0;
        *(float*)&D_D420[2] = -1.0f;
        *(float*)&D_D420[3] = 1.0f;
        *(float*)&D_D420[4] = 4.0f;
        *(float*)&D_D420[32] = *(float*)&D_D420[31] = *(float*)&D_D420[30] = *(float*)&D_D420[29] = *(float*)&D_D420[28] = *(float*)&D_D420[27] = *(float*)&D_D420[26] = *(float*)&D_D420[25] = *(float*)&D_D420[24] = *(float*)&D_D420[23] = *(float*)&D_D420[22] = *(float*)&D_D420[21] = *(float*)&D_D420[20] = *(float*)&D_D420[19] = *(float*)&D_D420[18] = *(float*)&D_D420[17] = *(float*)&D_D420[16] = *(float*)&D_D420[15] = *(float*)&D_D420[14] = *(float*)&D_D420[13] = *(float*)&D_D420[12] = *(float*)&D_D420[11] = *(float*)&D_D420[10] = *(float*)&D_D420[9] = *(float*)&D_D420[8] = *(float*)&D_D420[7] = *(float*)&D_D420[6] = *(float*)&D_D420[5] = 0.0f;
        *(float*)&D_D420[33] = 1.0f;
        *(float*)&D_D420[36] = *(float*)&D_D420[35] = *(float*)&D_D420[34] = 0.0f;
        *(float*)&D_D420[37] = 1.0f;
        *(float*)&D_D420[38] = 1.0f;
        *(float*)&D_D420[39] = 1.0f;
        *(float*)&D_D420[40] = 1.0f;
        *(float*)&D_D420[41] = 1.0f;
        *(float*)&D_D420[44] = *(float*)&D_D420[43] = *(float*)&D_D420[42] = 0.0f;
        *(float*)&D_D420[45] = 1.0f;
        *(float*)&D_D420[48] = *(float*)&D_D420[47] = *(float*)&D_D420[46] = 0.0f;
        ((int*)D_D420)[49] = 16;
        ((int*)D_D420)[50] = 0;
        *(float*)&D_D420[51] = 0.0f;
        ((int*)D_D420)[52] = 1;
        *(float*)&D_D420[53] = 20.0f;
        D_D420[54] = 0xFFFFFFFF;
        D_004A5604 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_D420 + 0xDC) = sBindEnd_1FBE38();
    }
    unsigned *buf = (unsigned*)cMemMan_alloc(0xE0, D_00489718_D420, 0x20000000, 0);
    buf[54] = 0xFFFFFFFF;
    func_003E6574(buf, D_D420, 0xE0);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0) {
        operator_delete((int*)buf);
        return D_004C9098;
    }
    void *p = *(void**)(obj + 0xC);
    if (p) {
        int r = checkActiveNode(p, 13, buf);
        if (r != 0) {
            if (r > 0)
                operator_delete((int*)buf);
            return D_004C9098;
        }
    }
    if (*(float*)&buf[7] > *(float*)&buf[5])
        *(float*)&buf[7] = *(float*)&buf[5];
    func_003578A8_D420(cMemMan_alloc(0x2C, D_00489730_D420, 0x20000000, 0), 1, obj, buf, 0);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD758);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V4_D758 : t4Vector { V4_D758() {} V4_D758(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
extern "C" void func_003558B8_D758(void*, t4Vector*) __asm__("func_003558B8");
static inline cBeing *being_D758(int k) {
    sRace *lvl = D_004A28A8->game->race;
    return lvl->riders[k];
}
// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (matrix * vector).
static inline V4_D758 mtxApply_D758(const t4Matrix *m, const t4Vector &v) {
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
static inline void vAddTo_D758(t4Vector &a, const t4Vector &b) {
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
extern unsigned D_D758[] __asm__("D_004FB720");
extern int D_004A5608;
extern const int D_00446190[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FD758(int n, sBindArg_1FBE38 *e) {
    if (D_004A5608 == 0) {
        D_D758[0] = 0xFFFFFFFF;
        ((int*)D_D758)[1] = -1;
        *(float*)&D_D758[4] = *(float*)&D_D758[3] = *(float*)&D_D758[2] = 0.0f;
        D_004A5608 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_D758 + 20) = sBindEnd_1FBE38();
    }
    unsigned buf64[6];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_D758, 24);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        if (p->isMoveNode()) {
            int k = buf[1];
            if (k != -1) {
                t4Vector pos = *being_D758(k)->getPosition();
                const t4Matrix *m = being_D758(buf[1])->getTransform();
                vAddTo_D758(pos, mtxApply_D758(m, V4_D758(*(float*)&buf[2], *(float*)&buf[3], *(float*)&buf[4], 0.0f)));
                func_003558B8_D758(p, &pos);
            }
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FD9F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355978(void*, int, int, sVec4_1FBE38*);
extern unsigned D_D9F8[] __asm__("D_004FB738");
extern int D_004A560C;
extern const int D_004461A8[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FD9F8(int n, sBindArg_1FBE38 *e) {
    if (D_004A560C == 0) {
        D_D9F8[0] = 0xFFFFFFFF;
        D_D9F8[1] = 0xFFFFFFFF;
        ((int*)D_D9F8)[2] = 0;
        *(float*)&D_D9F8[5] = *(float*)&D_D9F8[4] = *(float*)&D_D9F8[3] = 0.0f;
        D_004A560C = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_D9F8 + 24) = sBindEnd_1FBE38();
    }
    unsigned buf64[7];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574(buf, D_D9F8, 28);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    unsigned id2 = buf[1];
    if (~id2 != 0) {
        sRefSet *s2 = (*D_004A47B8)->sets[id2 & 0xFF];
        unsigned i2;
        char *o2;
        if (!s2 || (i2 = s2->refs[id2 >> 8] >> 8) == 0)
            o2 = 0;
        else
            o2 = (char*)(i2 << 2);
        cInstanceNode_1FBE38 *q = o2 ? *(cInstanceNode_1FBE38**)(o2 + 0xC) : 0;
        if (q && !q->isType(6)) {
            cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
            if (p && p->isMoveNode()) {
                int k = *(int*)((char*)q + 0x18);
                sVec4_1FBE38 v(*(float*)&buf[3], *(float*)&buf[4], *(float*)&buf[5], 0.0f);
                func_00355978(p, k, buf[2], &v);
            }
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FDC60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355978(void*, int, int, sVec4_1FBE38*);
extern unsigned D_DC60[] __asm__("D_004FB758");
extern int D_004A5610;
extern const int D_004461C0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FDC60(int n, sBindArg_1FBE38 *e) {
    if (D_004A5610 == 0) {
        D_DC60[0] = 0xFFFFFFFF;
        D_DC60[1] = 0xFFFFFFFF;
        ((int*)D_DC60)[2] = 0;
        *(float*)&D_DC60[5] = *(float*)&D_DC60[4] = *(float*)&D_DC60[3] = 0.0f;
        D_004A5610 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_DC60 + 24) = sBindEnd_1FBE38();
    }
    unsigned buf64[7];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574(buf, D_DC60, 28);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (~buf[1] != 0) {
        cInstanceNode_1FBE38 *q = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (q && !q->isType(6)) {
            unsigned id2 = buf[1];
            sRefSet *s2 = (*D_004A47B8)->sets[id2 & 0xFF];
            unsigned i2;
            char *o2;
            if (!s2 || (i2 = s2->refs[id2 >> 8] >> 8) == 0)
                o2 = 0;
            else
                o2 = (char*)(i2 << 2);
            cInstanceNode_1FBE38 *p = o2 ? *(cInstanceNode_1FBE38**)(o2 + 0xC) : 0;
            if (p && p->isMoveNode()) {
                int k = *(int*)((char*)q + 0x18);
                sVec4_1FBE38 v(*(float*)&buf[3], *(float*)&buf[4], *(float*)&buf[5], 0.0f);
                func_00355978(p, k, buf[2], &v);
            }
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FDED0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355AD0_DED0(void*, void*) __asm__("func_00355AD0");
extern unsigned D_DED0[] __asm__("D_004FB778");
extern int D_004A5614;
extern const int D_004461D8[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FDED0(int n, sBindArg_1FBE38 *e) {
    if (D_004A5614 == 0) {
        D_DED0[0] = 0xFFFFFFFF;
        D_DED0[1] = 0xFFFFFFFF;
        ((int*)D_DED0)[2] = 1;
        ((int*)D_DED0)[3] = 3;
        *(float*)&D_DED0[4] = 20.0f;
        *(float*)&D_DED0[7] = *(float*)&D_DED0[6] = *(float*)&D_DED0[5] = 0.0f;
        ((int*)D_DED0)[8] = 1;
        *(float*)&D_DED0[10] = *(float*)&D_DED0[9] = 0.0f;
        D_004A5614 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_DED0 + 44) = sBindEnd_1FBE38();
    }
    unsigned buf64[12];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574(buf, D_DED0, 48);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (~buf[1] != 0) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p) {
            if (p->isMoveNode())
                func_00355AD0_DED0(p, buf);
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE0C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void cMoveNode_addSpline_E0C0(void*, void*) __asm__("cMoveNode_addSpline");
extern unsigned D_E0C0[] __asm__("D_004FB7A8");
extern int D_004A5618;
extern const int D_00446208[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FE0C0(int n, sBindArg_1FBE38 *e) {
    if (D_004A5618 == 0) {
        D_E0C0[0] = 0xFFFFFFFF;
        D_E0C0[1] = 0xFFFFFFFF;
        ((int*)D_E0C0)[2] = 3;
        *(float*)&D_E0C0[3] = 20.0f;
        *(float*)&D_E0C0[6] = 1.0f;
        *(float*)&D_E0C0[9] = *(float*)&D_E0C0[8] = *(float*)&D_E0C0[7] = *(float*)&D_E0C0[5] = *(float*)&D_E0C0[4] = 0.0f;
        ((int*)D_E0C0)[10] = 1;
        ((int*)D_E0C0)[11] = 2;
        D_004A5618 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_E0C0 + 48) = sBindEnd_1FBE38();
    }
    unsigned buf64[13];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574(buf, D_E0C0, 52);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (~buf[1] != 0) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p) {
            if (p->isMoveNode())
                cMoveNode_addSpline_E0C0(p, buf);
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE2C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355B90_E2C0(void*, void*) __asm__("func_00355B90");
extern unsigned D_E2C0[] __asm__("D_004FB7E0");
extern int D_004A561C;
extern const int D_00446238[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FE2C0(int n, sBindArg_1FBE38 *e) {
    if (D_004A561C == 0) {
        D_E2C0[0] = 0xFFFFFFFF;
        ((int*)D_E2C0)[1] = 5;
        *(float*)&D_E2C0[3] = *(float*)&D_E2C0[2] = 0.0f;
        *(float*)&D_E2C0[4] = 0.016666699200868607f;
        *(float*)&D_E2C0[5] = 0.016666699200868607f;
        *(float*)&D_E2C0[6] = 1.0f;
        *(float*)&D_E2C0[10] = *(float*)&D_E2C0[9] = *(float*)&D_E2C0[8] = *(float*)&D_E2C0[7] = 0.0f;
        *(float*)&D_E2C0[11] = 1.0f;
        D_004A561C = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_E2C0 + 48) = sBindEnd_1FBE38();
    }
    unsigned buf64[13];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_E2C0, 52);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        if (p->isMoveNode())
            func_00355B90_E2C0(p, buf);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE4A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355BF0_E4A8(void*, void*) __asm__("func_00355BF0");
extern unsigned D_E4A8[] __asm__("D_004FB818");
extern int D_004A5620;
extern const int D_00446268[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FE4A8(int n, sBindArg_1FBE38 *e) {
    if (D_004A5620 == 0) {
        D_E4A8[0] = 0xFFFFFFFF;
        ((int*)D_E4A8)[1] = 0;
        ((int*)D_E4A8)[2] = 0;
        ((int*)D_E4A8)[3] = 0;
        *(float*)&D_E4A8[4] = 2.0f;
        D_004A5620 = 1;
        *(sBindEnd_1FBE38*)((char*)D_E4A8 + 20) = sBindEnd_1FBE38();
    }
    unsigned buf64[6];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_E4A8, 24);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        if (p->isMoveNode())
            func_00355BF0_E4A8(p, buf);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FE668);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355C50_E668(void*, void*) __asm__("func_00355C50");
extern unsigned D_E668[] __asm__("D_004FB830");
extern int D_004A5624;
extern const int D_00446280[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FE668(int n, sBindArg_1FBE38 *e) {
    if (D_004A5624 == 0) {
        D_E668[0] = 0xFFFFFFFF;
        ((int*)D_E668)[1] = 1;
        *(float*)&D_E668[3] = 0.10000000149011612f;
        *(float*)&D_E668[4] = 20.0f;
        *(float*)&D_E668[6] = *(float*)&D_E668[5] = *(float*)&D_E668[2] = 0.0f;
        *(float*)&D_E668[7] = 1.0f;
        D_004A5624 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_E668 + 32) = sBindEnd_1FBE38();
    }
    unsigned buf64[9];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_E668, 36);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        if (p->isMoveNode())
            func_00355C50_E668(p, buf);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", cViewer_addParticle);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_003578A8_E840(void*, int, void*, void*, void*) __asm__("func_003578A8");
void operator_delete(int*);
extern char D_00489740_E840[] __asm__("D_00489740");
extern char D_00489730_E840[] __asm__("D_00489730");
extern "C" void cMoveNode_addParticle_E840(void*, void*) __asm__("cMoveNode_addParticle");
// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector vSub_E840(const t4Vector &a, const t4Vector &b) {
    t4Vector r;
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
static inline float vLen_E840(const t4Vector &v) {
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
static inline sRace *lvl_E840() { return D_004A28A8->game->race; }
static inline int nearViewer_E840(const t4Vector &pos) {
    int notEdit = *(int*)(D_004A28A4 + 0x550) != 2;
    if (notEdit)
        return 1;
    int n = lvl_E840()->numPlayers;
    for (int i = 0; i < n; i++) {
        t4Vector d = vSub_E840(pos, *lvl_E840()->players[i]->rider->getPosition());
        if (vLen_E840(d) < 30000.0f)
            return 1;
    }
    n = lvl_E840()->numPlayers2;
    for (int i = 0; i < n; i++) {
        t4Vector d = vSub_E840(pos, *lvl_E840()->players2[i]->rider->getPosition());
        if (vLen_E840(d) < 30000.0f)
            return 1;
    }
    return 0;
}
struct Tag_E840 { char c; Tag_E840() {} Tag_E840(const Tag_E840 &o) : c(o.c) {} };
extern unsigned D_E840[] __asm__("D_004FB858");
extern int D_004A5628;
extern const int D_004462A0[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue cViewer_addParticle(int n, sBindArg_1FBE38 *e) {
    if (D_004A5628 == 0) {
        ((int*)D_E840)[0] = 1;
        ((int*)D_E840)[1] = 0;
        *(float*)&D_E840[2] = -1.0f;
        *(float*)&D_E840[3] = 1.0f;
        *(float*)&D_E840[4] = 4.0f;
        *(float*)&D_E840[32] = *(float*)&D_E840[31] = *(float*)&D_E840[30] = *(float*)&D_E840[29] = *(float*)&D_E840[28] = *(float*)&D_E840[27] = *(float*)&D_E840[26] = *(float*)&D_E840[25] = *(float*)&D_E840[24] = *(float*)&D_E840[23] = *(float*)&D_E840[22] = *(float*)&D_E840[21] = *(float*)&D_E840[20] = *(float*)&D_E840[19] = *(float*)&D_E840[18] = *(float*)&D_E840[17] = *(float*)&D_E840[16] = *(float*)&D_E840[15] = *(float*)&D_E840[14] = *(float*)&D_E840[13] = *(float*)&D_E840[12] = *(float*)&D_E840[11] = *(float*)&D_E840[10] = *(float*)&D_E840[9] = *(float*)&D_E840[8] = *(float*)&D_E840[7] = *(float*)&D_E840[6] = *(float*)&D_E840[5] = 0.0f;
        *(float*)&D_E840[33] = 1.0f;
        *(float*)&D_E840[36] = *(float*)&D_E840[35] = *(float*)&D_E840[34] = 0.0f;
        *(float*)&D_E840[37] = 1.0f;
        *(float*)&D_E840[38] = 1.0f;
        *(float*)&D_E840[39] = 1.0f;
        *(float*)&D_E840[40] = 1.0f;
        *(float*)&D_E840[41] = 1.0f;
        *(float*)&D_E840[44] = *(float*)&D_E840[43] = *(float*)&D_E840[42] = 0.0f;
        *(float*)&D_E840[45] = 1.0f;
        *(float*)&D_E840[48] = *(float*)&D_E840[47] = *(float*)&D_E840[46] = 0.0f;
        ((int*)D_E840)[49] = 16;
        ((int*)D_E840)[50] = 0;
        *(float*)&D_E840[51] = 0.0f;
        ((int*)D_E840)[52] = 1;
        *(float*)&D_E840[53] = 20.0f;
        D_E840[54] = 0xFFFFFFFF;
        D_004A5628 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb back; sb 0(sp)).
        (*(Tag_E840*)((char*)D_E840 + 0xDC)) = Tag_E840((*(Tag_E840*)((char*)D_E840 + 0xDC)));
    }
    unsigned *buf = (unsigned*)cMemMan_alloc(0xE0, D_00489740_E840, 0x20000000, 0);
    buf[54] = 0xFFFFFFFF;
    func_003E6574(buf, D_E840, 0xE0);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        if (p->isMoveNode()) {
            t4Vector pos = p->v24()->row[3];
            if (nearViewer_E840(pos)) {
                cMoveNode_addParticle_E840(p, buf);
                return D_004C9098;
            }
        }
    } else {
        t4Vector pos = *(t4Vector*)(obj + 0x40);
        if (nearViewer_E840(pos)) {
            func_003578A8_E840(cMemMan_alloc(0x2C, D_00489730_E840, 0x20000000, 0), 1, obj, buf, 0);
            return D_004C9098;
        }
    }
    operator_delete((int*)buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FEE98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void cMoveNode_addDynamicParticle_EE98(void*, void*, int, sVec4_1FBE38*) __asm__("cMoveNode_addDynamicParticle");
void operator_delete(int*);
extern char D_00489750_EE98[] __asm__("D_00489750");
extern unsigned D_EE98[] __asm__("D_004FB938");
extern int D_004A562C;
extern const int D_00446380[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FEE98(int n, sBindArg_1FBE38 *e) {
    if (D_004A562C == 0) {
        ((int*)D_EE98)[0] = 1;
        ((int*)D_EE98)[1] = 0;
        *(float*)&D_EE98[2] = -1.0f;
        *(float*)&D_EE98[3] = 1.0f;
        *(float*)&D_EE98[4] = 4.0f;
        *(float*)&D_EE98[32] = *(float*)&D_EE98[31] = *(float*)&D_EE98[30] = *(float*)&D_EE98[29] = *(float*)&D_EE98[28] = *(float*)&D_EE98[27] = *(float*)&D_EE98[26] = *(float*)&D_EE98[25] = *(float*)&D_EE98[24] = *(float*)&D_EE98[23] = *(float*)&D_EE98[22] = *(float*)&D_EE98[21] = *(float*)&D_EE98[20] = *(float*)&D_EE98[19] = *(float*)&D_EE98[18] = *(float*)&D_EE98[17] = *(float*)&D_EE98[16] = *(float*)&D_EE98[15] = *(float*)&D_EE98[14] = *(float*)&D_EE98[13] = *(float*)&D_EE98[12] = *(float*)&D_EE98[11] = *(float*)&D_EE98[10] = *(float*)&D_EE98[9] = *(float*)&D_EE98[8] = *(float*)&D_EE98[7] = *(float*)&D_EE98[6] = *(float*)&D_EE98[5] = 0.0f;
        *(float*)&D_EE98[33] = 1.0f;
        *(float*)&D_EE98[36] = *(float*)&D_EE98[35] = *(float*)&D_EE98[34] = 0.0f;
        *(float*)&D_EE98[37] = 1.0f;
        *(float*)&D_EE98[38] = 1.0f;
        *(float*)&D_EE98[39] = 1.0f;
        *(float*)&D_EE98[40] = 1.0f;
        *(float*)&D_EE98[41] = 1.0f;
        *(float*)&D_EE98[44] = *(float*)&D_EE98[43] = *(float*)&D_EE98[42] = 0.0f;
        *(float*)&D_EE98[45] = 1.0f;
        *(float*)&D_EE98[48] = *(float*)&D_EE98[47] = *(float*)&D_EE98[46] = 0.0f;
        ((int*)D_EE98)[49] = 16;
        ((int*)D_EE98)[50] = 0;
        *(float*)&D_EE98[51] = 0.0f;
        ((int*)D_EE98)[52] = 1;
        *(float*)&D_EE98[53] = 20.0f;
        D_EE98[54] = 0xFFFFFFFF;
        ((int*)D_EE98)[55] = 0;
        *(float*)&D_EE98[58] = *(float*)&D_EE98[57] = *(float*)&D_EE98[56] = 0.0f;
        D_004A562C = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_EE98 + 0xEC) = sBindEnd_1FBE38();
    }
    unsigned *buf = (unsigned*)cMemMan_alloc(0xF0, D_00489750_EE98, 0x20000000, 0);
    buf[54] = 0xFFFFFFFF;
    func_003E6574(buf, D_EE98, 0xF0);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p && p->isMoveNode()) {
        float one = 1.0f;
        sVec4_1FBE38 v(*(float*)&buf[56], *(float*)&buf[57], *(float*)&buf[58], one);
        cMoveNode_addDynamicParticle_EE98(p, buf, buf[55], &v);
        return D_004C9098;
    }
    operator_delete((int*)buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF1C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355E38_F1C8(void*, void*) __asm__("func_00355E38");
extern unsigned D_F1C8[] __asm__("D_004FBA28");
extern int D_004A5630;
extern const int D_00446470[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FF1C8(int n, sBindArg_1FBE38 *e) {
    if (D_004A5630 == 0) {
        D_F1C8[0] = 0xFFFFFFFF;
        D_F1C8[1] = 0xFFFFFFFF;
        ((int*)D_F1C8)[2] = -1;
        D_004A5630 = 1;
        *(sBindEnd_1FBE38*)((char*)D_F1C8 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574(buf, D_F1C8, 16);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (~buf[1] != 0) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p) {
            if (p->isMoveNode())
                func_00355E38_F1C8(p, buf);
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF390);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00348D98(void*, void*, void*);
extern char D_00489768_F390[] __asm__("D_00489768");
extern unsigned D_F390[] __asm__("D_004FBA38");
extern int D_004A5634;
extern const int D_00446480[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FF390(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_F390 + 84) = sBindEnd_1FBE38();
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
    func_003E6574(buf, D_F390, 88);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 20, buf))
        return D_004C9098;
    func_00348D98(cMemMan_alloc(0x80, D_00489768_F390, 0x20000000, 0), obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF5E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int checkActiveNode(void*, int, void*);
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00349B48(void*, void*, void*);
extern char D_00489778_F5E8[] __asm__("D_00489778");
extern unsigned D_F5E8[] __asm__("D_004FBA90");
extern int D_004A5638;
extern const int D_004464D8[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FF5E8(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_F5E8 + 84) = sBindEnd_1FBE38();
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
    func_003E6574(buf, D_F5E8, 88);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    void *p = *(void**)(obj + 0xC);
    if (p && checkActiveNode(p, 21, buf))
        return D_004C9098;
    *(float*)&buf[20] *= 0.0010000000474974513f;
    func_00349B48(cMemMan_alloc(0x80, D_00489778_F5E8, 0x20000000, 0), obj, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF850);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_00446530_F850[] __asm__("D_00446530");
extern "C" void func_0010F1C0(cRider_1FBE38*, int, float);
extern int D_004A563C_F850 __asm__("D_004A563C");
struct T12_F850 { int a; int b; int e; sBindEnd_1FBE38 f; };
extern T12_F850 D_004FBAE8_F850 __asm__("D_004FBAE8");
extern "C" cLunoValue func_002FF850(int n, sBindArg_1FBE38* e) {
    if (D_004A563C_F850 == 0) {
        D_004FBAE8_F850.a = -1;
        D_004A563C_F850 = 1;
        D_004FBAE8_F850.b = 0;
        D_004FBAE8_F850.e = 0;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBAE8_F850.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBAE8_F850, 16);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_00446530_F850[k] && D_00446530_F850[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    if (vp[0] == -1)
        vp[0] = D_004A3DD8->being;
    func_0010F1C0(D_004A28A8->game->race->riders[vp[0]], vp[1], *(float*)&vp[2]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FF9A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

extern unsigned D_F9A8[] __asm__("D_004FBAF8");
extern int D_004A5640;
extern const int D_00446540[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FF9A8(int n, sBindArg_1FBE38 *e) {
    if (D_004A5640 == 0) {
        D_F9A8[0] = 0xFFFFFFFF;
        ((int*)D_F9A8)[1] = -1;
        ((int*)D_F9A8)[2] = 0;
        D_004A5640 = 1;
        *(sBindEnd_1FBE38*)((char*)D_F9A8 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_F9A8, 16);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446540[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = lookupRef_1FBE38(buf[0]);
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p)
        p->v36(buf[1], *(float*)&buf[2]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FFB50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_004A5648_FB50 __asm__("D_004A5648");
extern sBindEnd_1FBE38 D_004A564C_FB50 __asm__("D_004A564C");
extern int D_004A5650_FB50 __asm__("D_004A5650");
extern int D_004A3C10_FB50[2] __asm__("D_004A3C10");
extern "C" void* cMemMan_alloc(int, void*, int, int);
extern "C" void* func_00350E90(void*, void*);
extern char D_004A3C18_FB50[] __asm__("D_004A3C18");
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FFB50(int n, sBindArg_1FBE38 *e) {
    if (D_004A5650_FB50 == 0) {
        D_004A5648_FB50 = 0xFFFFFFFF;
        D_004A5650_FB50 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A564C_FB50 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_004A5648_FB50, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj == 0)
        return D_004C9098;
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        if (p->isType(16) || p->isType(6))
            return D_004C9098;
        delete p;
    }
    func_00350E90(cMemMan_alloc(0x1C, D_004A3C18_FB50, 0x20000000, 0), obj);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FFD58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

extern unsigned D_FD58 __asm__("D_004A5658");
extern sBindEnd_1FBE38 D_004A565C;
extern int D_004A5660;
extern int D_004A3C20;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FFD58(int n, sBindArg_1FBE38 *e) {
    if (D_004A5660 == 0) {
        D_FD58 = 0xFFFFFFFF;
        D_004A5660 = 1;
        D_004A565C = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_FD58, 8);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C20)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = lookupRef_1FBE38(buf[0]);
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p) {
            if (p->isType(0x10))
                delete p;
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_002FFF00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0028B180(void);
extern "C" void func_002974A0_FF00(void*, void*, int) __asm__("func_002974A0");
extern unsigned D_FF00[] __asm__("D_004FBB08");
extern int D_004A5664;
extern int D_004A3C28;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_002FFF00(int n, sBindArg_1FBE38 *e) {
    if (D_004A5664 == 0) {
        D_FF00[0] = 0xFFFFFFFF;
        D_FF00[1] = 0xFFFFFFFF;
        D_004A5664 = 1;
        *(sBindEnd_1FBE38*)((char*)D_FF00 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_FF00, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int b1 = buf[1];
        func_002974A0_FF00(func_0028B180(), obj, b1);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003000A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0028B180(void);
extern "C" void func_00297950_00A8(void*, void*, int, int) __asm__("func_00297950");
extern unsigned D_00A8[] __asm__("D_004FBB18");
extern int D_004A5668;
extern const int D_00446550[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_003000A8(int n, sBindArg_1FBE38 *e) {
    if (D_004A5668 == 0) {
        D_00A8[0] = 0xFFFFFFFF;
        D_00A8[1] = 0xFFFFFFFF;
        ((int*)D_00A8)[2] = -1;
        D_004A5668 = 1;
        *(sBindEnd_1FBE38*)((char*)D_00A8 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_00A8, 16);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int b1 = buf[1];
        int b2 = buf[2];
        func_00297950_00A8(func_0028B180(), obj, b1, b2);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300260);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_0028B180(void);
extern "C" void func_00297EB8_0260(void*, void*, int, int) __asm__("func_00297EB8");
extern unsigned D_0260[] __asm__("D_004FBB28");
extern int D_004A566C;
extern const int D_00446560[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00300260(int n, sBindArg_1FBE38 *e) {
    if (D_004A566C == 0) {
        D_0260[0] = 0xFFFFFFFF;
        D_0260[1] = 0xFFFFFFFF;
        ((int*)D_0260)[2] = -1;
        D_004A566C = 1;
        *(sBindEnd_1FBE38*)((char*)D_0260 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_0260, 16);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int b1 = buf[1];
        int b2 = buf[2];
        func_00297EB8_0260(func_0028B180(), obj, b1, b2);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300418);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_0418[] __asm__("D_004FBB38");
extern int D_004A5670;
extern int D_004A3C30;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00300418(int n, sBindArg_1FBE38 *e) {
    if (D_004A5670 == 0) {
        D_0418[0] = 0xFFFFFFFF;
        ((int*)D_0418)[1] = 0;
        D_004A5670 = 1;
        *(sBindEnd_1FBE38*)((char*)D_0418 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_0418, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p) {
        int b1 = buf[1];
        if (b1 == 0)
            p->v34(0);
        else if (b1 == 1)
            p->v34(1);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003005E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_05E8 __asm__("D_004A5678");
extern sBindEnd_1FBE38 D_004A567C;
extern int D_004A5680;
extern int D_004A3C38;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_003005E8(int n, sBindArg_1FBE38 *e) {
    if (D_004A5680 == 0) {
        D_05E8 = 0xFFFFFFFF;
        D_004A5680 = 1;
        D_004A567C = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_05E8, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *o = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (o)
        o->v35();
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300770);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_004A5688_0770 __asm__("D_004A5688");
extern sBindEnd_1FBE38 D_004A568C_0770 __asm__("D_004A568C");
extern int D_004A5690_0770 __asm__("D_004A5690");
extern int D_004A3C40_0770[2] __asm__("D_004A3C40");
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00300770(int n, sBindArg_1FBE38 *e) {
    if (D_004A5690_0770 == 0) {
        D_004A5688_0770 = 0xFFFFFFFF;
        D_004A5690_0770 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A568C_0770 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_004A5688_0770, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    int k = D_004A3DD8->being;
    if (k >= 0 && obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        t4Matrix *m = (t4Matrix*)(obj + 0x10);
        if (p)
            m = p->v24();
        sRace *lvl = D_004A28A8->game->race;
        lvl->riders[k]->transport(*m);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300948);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_004A5698_0948 __asm__("D_004A5698");
extern sBindEnd_1FBE38 D_004A569C_0948 __asm__("D_004A569C");
extern int D_004A56A0_0948 __asm__("D_004A56A0");
extern int D_004A3C48_0948[2] __asm__("D_004A3C48");
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00300948(int n, sBindArg_1FBE38 *e) {
    if (D_004A56A0_0948 == 0) {
        D_004A5698_0948 = 0xFFFFFFFF;
        D_004A56A0_0948 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A569C_0948 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_004A5698_0948, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    int k = D_004A3DD8->being;
    if (k >= 0 && obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        t4Matrix *m = (t4Matrix*)(obj + 0x10);
        if (p)
            m = p->v24();
        sRace *lvl = D_004A28A8->game->race;
        lvl->riders[k]->initForMission(*m);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300B20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3C50_0B20[2] __asm__("D_004A3C50");
extern "C" void func_00358B28(unsigned, int);
extern int D_004A56A4_0B20 __asm__("D_004A56A4");
struct T12_0B20 { unsigned a; int b; sBindEnd_1FBE38 f; };
extern T12_0B20 D_004FBB48_0B20 __asm__("D_004FBB48");
extern "C" cLunoValue func_00300B20(int n, sBindArg_1FBE38* e) {
    if (D_004A56A4_0B20 == 0) {
        D_004FBB48_0B20.a = -1;
        D_004FBB48_0B20.b = 1;
        D_004A56A4_0B20 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBB48_0B20.f = sBindEnd_1FBE38();
    }
    unsigned v[4] __attribute__((aligned(16)));
    unsigned* vp = v;
    vp[0] = 0xFFFFFFFFu;
    func_003E6574(vp, &D_004FBB48_0B20, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3C50_0B20[k] && D_004A3C50_0B20[k] == 2)
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
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300C78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00278E50_0C78(char*, int, int, int, int, int, int, int) __asm__("func_00278E50");
extern "C" void func_00278ED0_0C78(char*, int, int, int, int, int, int) __asm__("func_00278ED0");
extern "C" int func_00278F38(char*, int);
extern "C" int func_00278F68(char*, int, int, int);
extern unsigned D_0C78[] __asm__("D_004FBB58");
extern int D_004A56A8;
extern int D_004A3C58;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00300C78(int n, sBindArg_1FBE38 *e) {
    if (D_004A56A8 == 0) {
        D_0C78[0] = 0xFFFFFFFF;
        ((int*)D_0C78)[1] = 0;
        D_004A56A8 = 1;
        *(sBindEnd_1FBE38*)((char*)D_0C78 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    func_003E6574(buf, D_0C78, 12);
    sBindArg_1FBE38 *x = e;
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
        func_00278ED0_0C78(D_004A28A4, 0, id, 3, -1, -1, -1);
        func_00278F38(D_004A28A4, 0);
        break;
    case 1:
        func_00278E50_0C78(D_004A28A4, 0, id, 3, 0, -1, -1, -1);
        func_00278F38(D_004A28A4, 0);
        break;
    case 2:
        func_00278F68(D_004A28A4, 0, 1, 0);
        break;
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300E28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);

extern int D_004A3C60_0E28[2] __asm__("D_004A3C60");
extern "C" void func_0030B928(cWScriptMan*, unsigned, int);
extern int D_004A56AC_0E28 __asm__("D_004A56AC");
struct T12u_0E28 { unsigned a; int b; sBindEnd_1FBE38 f; };
extern T12u_0E28 D_004FBB68_0E28 __asm__("D_004FBB68");
extern "C" cLunoValue func_00300E28(int n, sBindArg_1FBE38* e) {
    if (D_004A56AC_0E28 == 0) {
        D_004FBB68_0E28.a = 0xFFFFFFFFu;
        D_004FBB68_0E28.b = 1;
        D_004A56AC_0E28 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBB68_0E28.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBB68_0E28, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3C60_0E28[k] && D_004A3C60_0E28[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    unsigned x = vp[0];
    if (x != 0xFFFFFFFFu)
        func_0030B928(D_004A3DD8, x, vp[1]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00300F50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_0F50[] __asm__("D_004FBB78");
extern int D_56B0_0F50 __asm__("D_004A56B0");
extern const int D_00446570_0F50[] __asm__("D_00446570");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_0030BAC8_0F50(void*, unsigned, unsigned*, int) __asm__("func_0030BAC8");
extern "C" cLunoValue func_00300F50(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        *(sBindEnd_1FBE38*)((char*)D_0F50 + 0x54) = sBindEnd_1FBE38();
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
    func_003E6574(buf, D_0F50, 0x58);
    sBindArg_1FBE38 *x = e;
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
        func_0030BAC8_0F50(D_004A3DD8, buf[0], buf + 1, 20);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);
extern int D_004A3C68_1120[2] __asm__("D_004A3C68");
extern "C" void func_0030B9A0(cWScriptMan*, int, unsigned, unsigned);
extern int D_004A56B4_1120 __asm__("D_004A56B4");
struct T12_1120 { unsigned a; unsigned b; sBindEnd_1FBE38 f; };
extern T12_1120 D_004FBBD0_1120 __asm__("D_004FBBD0");
static inline bool isIdle_1120(int slot) {
    if (slot != -1) {
        cBeing *being = D_004A28A8->game->race->riders[slot];
        cRider_1FBE38 *rider = (cRider_1FBE38*)being;
        return !rider->isComputer();
    }
    return false;
}
extern "C" cLunoValue* func_00301120(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    int slot = D_004A3DD8->being;
    if (isIdle_1120(slot)) {
        if (D_004A56B4_1120 == 0) {
            D_004FBBD0_1120.a = 0xFFFFFFFF;
            D_004FBBD0_1120.b = 0xFFFFFFFF;
            D_004A56B4_1120 = 1;
            // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
            D_004FBBD0_1120.f = sBindEnd_1FBE38();
        }
        unsigned v[4] __attribute__((aligned(16)));
        unsigned* vp = v;
        v[1] = 0xFFFFFFFF;
        func_003E6574(vp, &D_004FBBD0_1120, 12);
        sBindArg_1FBE38* p = e;
        for (int i = 0; i < n; i++, p++) {
            int k = p->idx;
            unsigned* d = (unsigned*)((k << 2) + (int)vp);
            if (p->type != D_004A3C68_1120[k] && D_004A3C68_1120[k] == 2)
                *(float*)d = (float)p->val;
            else
                *d = p->val;
        }
        unsigned x = vp[0];
        if (x != 0xFFFFFFFFu) {
            if (~vp[1] == 0)
                vp[1] = *(int*)(D_004A3DD8->f290 + 0x78);
            unsigned b1 = vp[1];
            unsigned b0 = vp[0];
            func_0030B9A0(D_004A3DD8, slot, b0, b1);
            ret->type = 1;
            *func_00226610(ret) = 1;
            return ret;
        }
    }
    ret->type = 1;
    *func_00226610(ret) = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003012F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3C70_12F0[2] __asm__("D_004A3C70");
extern "C" int func_0030A868_12F0(cWScriptMan*, unsigned, int, int) __asm__("func_0030A868");
extern int D_004A56B8_12F0 __asm__("D_004A56B8");
struct T12_12F0 { unsigned a; int b; sBindEnd_1FBE38 f; };
extern T12_12F0 D_004FBBE0_12F0 __asm__("D_004FBBE0");
extern "C" cLunoValue* func_003012F0(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A56B8_12F0 == 0) {
        D_004FBBE0_12F0.a = -1;
        D_004FBBE0_12F0.b = -1;
        D_004A56B8_12F0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBBE0_12F0.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBBE0_12F0, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3C70_12F0[k] && D_004A3C70_12F0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    unsigned x = vp[0];
    if (x != 0xFFFFFFFFu) {
        int r = func_0030A868_12F0(D_004A3DD8, x, vp[1], -1);
        ret->type = 1;
        *func_00226610(ret) = r;
    } else {
        *ret = D_004C9098;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301440);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct T12_1440 { unsigned a; int b; sBindEnd_1FBE38 f; };
extern T12_1440 D_004FBBF0_1440 __asm__("D_004FBBF0");
extern int D_004A56BC_1440 __asm__("D_004A56BC");
extern int D_004A3C78_1440[2] __asm__("D_004A3C78");
#define ASSERT_1440(c) do { } while (0)
extern "C" cLunoValue func_00301440(int n, sBindArg_1FBE38* e) {
    if (D_004A56BC_1440 == 0) {
        D_004FBBF0_1440.a = 0xFFFFFFFF;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBBF0_1440.b = 1;
        D_004FBBF0_1440.f = sBindEnd_1FBE38();
        D_004A56BC_1440 = 1;
    }
    unsigned buf64[3] __attribute__((aligned(16)));
    unsigned* buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_004FBBF0_1440, 12);
    sBindArg_1FBE38* x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004A3C78_1440[idx];
        unsigned* d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    // NOTE: in the release build the looked-up object is consumed by debug code only, so the lookup is dead and just
    // the id test's operands survive (lw; nor) once the branch is removed after register allocation.
    ASSERT_1440(obj != 0);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301560);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);

extern int D_004A3C80_1560[2] __asm__("D_004A3C80");
extern "C" int func_0030BA80(cWScriptMan*, unsigned);
extern int D_004A56C8_1560 __asm__("D_004A56C8");
extern unsigned D_004A56C0_1560 __asm__("D_004A56C0");
extern sBindEnd_1FBE38 D_004A56C4_1560 __asm__("D_004A56C4");
extern "C" cLunoValue* func_00301560(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A56C8_1560 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A56C4_1560 = sBindEnd_1FBE38();
        D_004A56C0_1560 = -1;
        D_004A56C8_1560 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A56C0_1560, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3C80_1560[k] && D_004A3C80_1560[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    unsigned x = vp[0];
    if (x != 0xFFFFFFFFu) {
        BIND_SET_RESULT_1FBE38(ret, func_0030BA80(D_004A3DD8, x));
    } else {
        BIND_SET_RESULT_1FBE38(ret, 0);
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301680);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

float *func_00226618_1680(void*) __asm__("func_00226618__FPv");
extern unsigned D_1680 __asm__("D_004A56D0");
extern sBindEnd_1FBE38 D_004A56D4;
extern int D_004A56D8;
extern int D_004A3C88;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue* func_00301680(cLunoValue *ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A56D8 == 0) {
        D_1680 = 0xFFFFFFFF;
        D_004A56D8 = 1;
        D_004A56D4 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_1680, 8);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3C88)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = lookupRef_1FBE38(buf[0]);
    float v;
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p)
            v = p->v30();
        else
            v = -1.0f;
        ret->type = 2;
        *func_00226618_1680(ret) = v;
    } else {
        v = -1.0f;
        ret->type = 2;
        *func_00226618_1680(ret) = v;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301830);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int *func_00226610(void*);
extern unsigned D_1830 __asm__("D_004A56E0");
extern sBindEnd_1FBE38 D_004A56E4;
extern int D_004A56E8;
extern int D_004A3C90;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue* func_00301830(cLunoValue *ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A56E8 == 0) {
        D_1830 = 0xFFFFFFFF;
        D_004A56E8 = 1;
        D_004A56E4 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_1830, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        int v;
        if (p)
            v = p->v31();
        else
            v = 0;
        ret->type = 1;
        *func_00226610(ret) = v;
    } else {
        ret->type = 1;
        *func_00226610(ret) = 0;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003019C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_00226610(void*);
extern unsigned D_19C8[] __asm__("D_004FBC00");
extern int D_004A56EC;
extern int D_004A3C98;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue* func_003019C8(cLunoValue *ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A56EC == 0) {
        D_19C8[0] = 0xFFFFFFFF;
        *(float*)&D_19C8[1] = -1.0f;
        D_004A56EC = 1;
        *(sBindEnd_1FBE38*)((char*)D_19C8 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_19C8, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        float f = *(float*)&buf[1];
        int v;
        if (p)
            v = p->v32(f * 0.03333333507180214f);
        else
            v = 0;
        ret->type = 1;
        *func_00226610(ret) = v;
    } else {
        ret->type = 1;
        *func_00226610(ret) = 0;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301B88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_004A56F0_1B88 __asm__("D_004A56F0");
extern sBindEnd_1FBE38 D_004A56F4_1B88 __asm__("D_004A56F4");
extern int D_004A56F8_1B88 __asm__("D_004A56F8");
extern int D_004A3CA0_1B88[2] __asm__("D_004A3CA0");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_0030A6D8(cWScriptMan*, int);
int* func_00226610(void*);


extern "C" cLunoValue* func_00301B88(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A56F8_1B88 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A56F4_1B88 = sBindEnd_1FBE38();
        D_004A56F0_1B88 = -1;
        D_004A56F8_1B88 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A56F0_1B88, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3CA0_1B88[k] && D_004A3CA0_1B88[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A6D8(D_004A3DD8, vp[0]);
    ret->type = 1;
    *func_00226610(ret) = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301C80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_004A5700_1C80 __asm__("D_004A5700");
extern sBindEnd_1FBE38 D_004A5704_1C80 __asm__("D_004A5704");
extern int D_004A5708_1C80 __asm__("D_004A5708");
extern int D_004A3CA8_1C80[2] __asm__("D_004A3CA8");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_0030A700(cWScriptMan*, int);
int* func_00226610(void*);


extern "C" cLunoValue* func_00301C80(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A5708_1C80 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A5704_1C80 = sBindEnd_1FBE38();
        D_004A5700_1C80 = -1;
        D_004A5708_1C80 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5700_1C80, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3CA8_1C80[k] && D_004A3CA8_1C80[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A700(D_004A3DD8, vp[0]);
    ret->type = 1;
    *func_00226610(ret) = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301D78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_004A5710_1D78 __asm__("D_004A5710");
extern sBindEnd_1FBE38 D_004A5714_1D78 __asm__("D_004A5714");
extern int D_004A5718_1D78 __asm__("D_004A5718");
extern int D_004A3CB0_1D78[2] __asm__("D_004A3CB0");
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610_1D78(void*) __asm__("func_00226610__FPv");
extern "C" cLunoValue* func_00301D78(cLunoValue* ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A5718_1D78 == 0) {
        D_004A5710_1D78 = 0xFFFFFFFF;
        D_004A5718_1D78 = 1;
        // NOTE: guarded static-local init; the target copies the trailing byte through its copy ctor (lbu; sb 0(sp)).
        D_004A5714_1D78 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_004A5710_1D78, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        int found = 1;
        sRace* lvl = D_004A28A8->game->race;
        cBeing *being = lvl->riders[D_004A3DD8->being];
        cRider_1FBE38 *rider = (cRider_1FBE38*)being;
        if (rider->isIntersecting((tInstanceRecord*)obj)) {
            ret->type = found;
            *func_00226610_1D78(ret) = found;
            goto done;
        }
    }
    ret->type = 1;
    *func_00226610_1D78(ret) = 0;
done:
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00301F48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A5720_1F48 __asm__("D_004A5720");
extern sBindEnd_1FBE38 D_004A5724_1F48 __asm__("D_004A5724");
extern int D_004A5728_1F48 __asm__("D_004A5728");
extern int D_004A3CB8_1F48[2] __asm__("D_004A3CB8");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_00303D88_1F48(int) __asm__("func_00303D88");


extern "C" cLunoValue func_00301F48(int n, sBindArg_1FBE38* e) {
    if (D_004A5728_1F48 == 0) {
        D_004A5720_1F48 = -1;
        D_004A5728_1F48 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A5724_1F48 = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5720_1F48, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3CB8_1F48[k] && D_004A3CB8_1F48[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_00303D88_1F48(vp[0]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302048);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00445E40_2048[] __asm__("D_00445E40");
extern "C" void func_0030B7F8(cWScriptMan*);
extern "C" void func_0022D6C8_2048(char*, int) __asm__("func_0022D6C8");
extern unsigned D_2048[] __asm__("D_004FBC10");
extern int D_004A572C;
extern int D_004A3CC0;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00302048(int n, sBindArg_1FBE38 *e) {
    if (D_004A572C == 0) {
        ((int*)D_2048)[0] = -1;
        ((int*)D_2048)[1] = -1;
        D_004A572C = 1;
        *(sBindEnd_1FBE38*)((char*)D_2048 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    func_003E6574(buf, D_2048, 12);
    sBindArg_1FBE38 *x = e;
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
    int k = D_004A3DD8->being;
    if (k != -1) {
        sRace* lvl = D_004A28A8->game->race;
        cBeing *being = lvl->riders[k];
        cRider_1FBE38 *rider = (cRider_1FBE38*)being;
        r = !rider->isComputer();
    } else {
        r = 0;
    }
    if (r) {
        int v16 = 0;
        unsigned id = buf[0];
        int b1 = buf[1];
        char* w = D_004A28A8->game->f78;
        if (id < 8)
            v16 = D_00445E40_2048[id];
        if (b1 == 0) {
            if (v16 != 1)
                func_0030B7F8(D_004A3DD8);
            func_0022D6C8_2048(w, v16);
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302210);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void*, void*, int);
struct Defaults_2210 { int v[3]; sBindEnd_1FBE38 flag; };
extern Defaults_2210 D_004FBC20_2210 __asm__("D_004FBC20");
extern int D_004A5730_2210 __asm__("D_004A5730");
extern const int D_004465C8_2210[] __asm__("D_004465C8");
extern char* const D_00445E40_2210[] __asm__("D_00445E40");
extern "C" void* cBE_getBE_2210() __asm__("cBE_getBE");
extern "C" void* cBE_getInterface_2210(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144CE0(void* iface, int id);
extern "C" void func_0022CEA8_2210(void* self, int hash, char* name) __asm__("func_0022CEA8");
extern "C" void func_0022D088_2210(void* self, int hash, char* name) __asm__("func_0022D088");
extern "C" void func_00231250(void* self, int a, int b, int refresh);
extern "C" void* func_0028B180();
extern "C" void func_002A49E8_2210(void* self) __asm__("func_002A49E8");


extern "C" cLunoValue func_00302210(int n, sBindArg_1FBE38* e)
{
    if (D_004A5730_2210 == 0) {
        D_004FBC20_2210.v[0] = -1;
        D_004FBC20_2210.v[1] = -1;
        D_004FBC20_2210.v[2] = -1;
        D_004A5730_2210 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBC20_2210.flag = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBC20_2210, 0x10);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004465C8_2210[k] && D_004465C8_2210[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int ok;
    int cur = D_004A3DD8->being;
    if (cur != -1) {
        sRace* lvl = D_004A28A8->game->race;
        cBeing* being = lvl->riders[cur];
        cRider_1FBE38* rider = (cRider_1FBE38*)being;
        ok = !rider->isComputer();
    } else {
        ok = 0;
    }
    if (ok) {
        int sel = vp[2];
        int action = vp[1];
        int id = vp[0];
        char* name = 0;
        void* iface = cBE_getInterface_2210(cBE_getBE_2210(), 0);
        char* ui = D_004A28A8->game->f78;
        if ((unsigned int)sel < 8) {
            name = D_00445E40_2210[sel];
        }
        int hash = func_00144CE0(iface, id);
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
            func_00231250(D_004A28A8->game, 0xE, 2, 0);
            func_002A49E8_2210(func_0028B180());
            break;
        case 4:
            func_00231250(D_004A28A8->game, 0xE, 0, 0);
            break;
        case 5:
            *(int*)(ui + 0x1A4) = 1;
            break;
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302490);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct T12_2490 { unsigned a; int b; sBindEnd_1FBE38 f; };
extern T12_2490 D_4FBC30_2490 __asm__("D_004FBC30");
extern int D_5734_2490 __asm__("D_004A5734");
extern int D_3CC8_2490 __asm__("D_004A3CC8");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_00353228_2490(char*) __asm__("func_00353228");
extern "C" void func_00353278_2490(char*) __asm__("func_00353278");
extern "C" cLunoValue func_00302490(int n, sBindArg_1FBE38 *e) {
    if (D_5734_2490 == 0) {
        D_4FBC30_2490.a = 0xFFFFFFFF;
        D_4FBC30_2490.b = -1;
        D_5734_2490 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_4FBC30_2490.f = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_4FBC30_2490, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        int mode = buf[1];
        if (p) {
            if (p->isMoveNode()) {
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
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302680);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A3CD0_2680[2] __asm__("D_004A3CD0");
extern "C" int func_00303D90(unsigned);
extern int D_004A5740_2680 __asm__("D_004A5740");
extern int D_004A5738_2680 __asm__("D_004A5738");
extern sBindEnd_1FBE38 D_004A573C_2680 __asm__("D_004A573C");
extern "C" cLunoValue* func_00302680(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A5740_2680 == 0) {
        // NOTE: guarded static-local init (defaults record = { int, sBindEnd_1FBE38 }).
        D_004A5738_2680 = -1;
        D_004A573C_2680 = sBindEnd_1FBE38();
        D_004A5740_2680 = 1;
    }
    int v[4];
    int* vp;
    BIND_UNPACK_ARGS_1FBE38(vp, v, &D_004A5738_2680, 8, D_004A3CD0_2680, n, e);
    BIND_SET_RESULT_1FBE38(ret, func_00303D90(vp[0]));
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302778);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A3CD8_2778[2] __asm__("D_004A3CD8");
extern "C" int func_00303DF8(unsigned);
extern int D_004A5750_2778 __asm__("D_004A5750");
extern int D_004A5748_2778 __asm__("D_004A5748");
extern sBindEnd_1FBE38 D_004A574C_2778 __asm__("D_004A574C");
extern "C" cLunoValue* func_00302778(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A5750_2778 == 0) {
        // NOTE: guarded static-local init (defaults record = { int, sBindEnd_1FBE38 }).
        D_004A5748_2778 = -1;
        D_004A574C_2778 = sBindEnd_1FBE38();
        D_004A5750_2778 = 1;
    }
    int v[4];
    int* vp;
    BIND_UNPACK_ARGS_1FBE38(vp, v, &D_004A5748_2778, 8, D_004A3CD8_2778, n, e);
    BIND_SET_RESULT_1FBE38(ret, func_00303DF8(vp[0]));
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302870);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A3CE0_2870[2] __asm__("D_004A3CE0");
extern "C" int func_00303E60(unsigned);
extern int D_004A5760_2870 __asm__("D_004A5760");
extern int D_004A5758_2870 __asm__("D_004A5758");
extern sBindEnd_1FBE38 D_004A575C_2870 __asm__("D_004A575C");
extern "C" cLunoValue* func_00302870(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A5760_2870 == 0) {
        // NOTE: guarded static-local init (defaults record = { int, sBindEnd_1FBE38 }).
        D_004A5758_2870 = -1;
        D_004A575C_2870 = sBindEnd_1FBE38();
        D_004A5760_2870 = 1;
    }
    int v[4];
    int* vp;
    BIND_UNPACK_ARGS_1FBE38(vp, v, &D_004A5758_2870, 8, D_004A3CE0_2870, n, e);
    BIND_SET_RESULT_1FBE38(ret, func_00303E60(vp[0]));
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3CE8_2968[2] __asm__("D_004A3CE8");
extern int D_004A5770_2968 __asm__("D_004A5770");
extern unsigned D_004A5768_2968 __asm__("D_004A5768");
extern sBindEnd_1FBE38 D_004A576C_2968 __asm__("D_004A576C");
extern "C" cLunoValue func_00302968(int n, sBindArg_1FBE38* e) {
    if (D_004A5770_2968 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A576C_2968 = sBindEnd_1FBE38();
        D_004A5768_2968 = -1;
        D_004A5770_2968 = 1;
    }
    unsigned v[4] __attribute__((aligned(16)));
    unsigned* vp = v;
    vp[0] = 0xFFFFFFFFu;
    func_003E6574(vp, &D_004A5768_2968, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3CE8_2968[k] && D_004A3CE8_2968[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    cWScriptMan* g = D_004A3DD8;
    unsigned x = vp[0];
    sRefSet* e0 = (*D_004A47B8)->sets[x & 0xFF];
    unsigned w;
    char* r;
    if (e0 == 0 || (w = e0->refs[x >> 8] >> 8) == 0)
        r = 0;
    else
        r = (char*)(w << 2);
    g->f290 = r;
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302AC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3CF0_2AC0[2] __asm__("D_004A3CF0");
extern "C" void func_0030A728(cWScriptMan*, int, int);
extern int D_004A5774_2AC0 __asm__("D_004A5774");
struct T12_2AC0 { unsigned a; int b; sBindEnd_1FBE38 f; };
extern T12_2AC0 D_004FBC40_2AC0 __asm__("D_004FBC40");
extern "C" cLunoValue func_00302AC0(int n, sBindArg_1FBE38* e) {
    if (D_004A5774_2AC0 == 0) {
        D_004FBC40_2AC0.a = -1;
        D_004FBC40_2AC0.b = 0;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBC40_2AC0.f = sBindEnd_1FBE38();
        D_004A5774_2AC0 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBC40_2AC0, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3CF0_2AC0[k] && D_004A3CF0_2AC0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A728(D_004A3DD8, vp[0], vp[1]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302BD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3CF8_2BD8[2] __asm__("D_004A3CF8");
extern "C" int func_0030A868(cWScriptMan*, int, int, int);
extern int D_004A5780_2BD8 __asm__("D_004A5780");
extern unsigned D_004A5778_2BD8 __asm__("D_004A5778");
extern sBindEnd_1FBE38 D_004A577C_2BD8 __asm__("D_004A577C");
extern "C" cLunoValue func_00302BD8(int n, sBindArg_1FBE38* e) {
    if (D_004A5780_2BD8 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A577C_2BD8 = sBindEnd_1FBE38();
        D_004A5778_2BD8 = -1;
        D_004A5780_2BD8 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5778_2BD8, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3CF8_2BD8[k] && D_004A3CF8_2BD8[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A868(D_004A3DD8, vp[0], 0, -1);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302CE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D00_2CE8[2] __asm__("D_004A3D00");
extern "C" void func_0030A728(cWScriptMan*, int, int);
extern int D_004A5790_2CE8 __asm__("D_004A5790");
extern unsigned D_004A5788_2CE8 __asm__("D_004A5788");
extern sBindEnd_1FBE38 D_004A578C_2CE8 __asm__("D_004A578C");
extern "C" cLunoValue func_00302CE8(int n, sBindArg_1FBE38* e) {
    if (D_004A5790_2CE8 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A578C_2CE8 = sBindEnd_1FBE38();
        D_004A5788_2CE8 = -1;
        D_004A5790_2CE8 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5788_2CE8, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D00_2CE8[k] && D_004A3D00_2CE8[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A728(D_004A3DD8, vp[0], 0);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302DF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D08_2DF0[2] __asm__("D_004A3D08");
extern "C" void func_0030A728(cWScriptMan*, int, int);
extern int D_004A57A0_2DF0 __asm__("D_004A57A0");
extern unsigned D_004A5798_2DF0 __asm__("D_004A5798");
extern sBindEnd_1FBE38 D_004A579C_2DF0 __asm__("D_004A579C");
extern "C" cLunoValue func_00302DF0(int n, sBindArg_1FBE38* e) {
    if (D_004A57A0_2DF0 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A579C_2DF0 = sBindEnd_1FBE38();
        D_004A5798_2DF0 = -1;
        D_004A57A0_2DF0 = 1;
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5798_2DF0, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D08_2DF0[k] && D_004A3D08_2DF0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030A728(D_004A3DD8, vp[0], 2);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00302EF8);
#ifdef SKIP_ASM
extern int D_004A57A8_2EF8 __asm__("D_004A57A8");
extern sBindEnd_1FBE38 D_004A57AC_2EF8 __asm__("D_004A57AC");
extern int D_004A57B0_2EF8 __asm__("D_004A57B0");
extern int D_004A3D10_2EF8[2] __asm__("D_004A3D10");
extern "C" int func_00122EE8(cRider_1FBE38* rider, int which);


extern "C" cLunoValue* func_00302EF8(cLunoValue* ret, int n, sBindArg_1FBE38 *e)
{
    if (D_004A57B0_2EF8 == 0) {
        D_004A57A8_2EF8 = 0;
        D_004A57B0_2EF8 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A57AC_2EF8 = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int *vp;
    BIND_UNPACK_ARGS_1FBE38(vp, v, &D_004A57A8_2EF8, 8, D_004A3D10_2EF8, n, e);
    sRace* lvl = D_004A28A8->game->race;
    cBeing* being = lvl->riders[D_004A3DD8->being];
    cRider_1FBE38* r = (cRider_1FBE38*)being;
    int res;
    switch (vp[0]) {
    case 3: res = func_00122EE8(r, 0); break;
    case 4: res = func_00122EE8(r, 1); break;
    case 1: res = func_00122EE8(r, 2); break;
    case 0: res = func_00122EE8(r, 3); break;
    case 2: res = func_00122EE8(r, 4); break;
    case 5: res = func_00122EE8(r, 5); break;
    case 6: res = func_00122EE8(r, 6); break;
    case 7: res = func_00122EE8(r, 7); break;
    case 9: res = func_00122EE8(r, 8); break;
    case 10: res = func_00122EE8(r, 9); break;
    case 11: res = func_00122EE8(r, 10); break;
    case 12: res = func_00122EE8(r, 11); break;
    case 13: res = func_00122EE8(r, 12); break;
    case 14: res = func_00122EE8(r, 13); break;
    case 15: res = func_00122EE8(r, 14); break;
    case 16: res = func_00122EE8(r, 15); break;
    case 17: res = func_00122EE8(r, 16); break;
    case 8: res = func_00122EE8(r, 17); break;
    case 18: res = func_00122EE8(r, 18); break;
    default: res = 0; break;
    }
    BIND_SET_RESULT_1FBE38(ret, res);
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303130);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int *func_00226610(void*);
extern unsigned D_3130[] __asm__("D_004FBC50");
extern int D_004A57B4;
extern int D_004A3D18;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue* func_00303130(cLunoValue *ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A57B4 == 0) {
        D_3130[0] = 0xFFFFFFFF;
        D_3130[1] = 1;
        D_004A57B4 = 1;
        *(sBindEnd_1FBE38*)((char*)D_3130 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_3130, 12);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3D18)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = lookupRef_1FBE38(buf[0]);
    if (obj && *(int*)(obj + 0xC)) {
        ret->type = 1;
        *func_00226610(ret) = 1;
    } else {
        ret->type = 1;
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
static inline float len_32C0(const t4Vector &v) {
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
extern "C" cLunoValue* func_003032C0(cLunoValue* ret) {
    cBeing *being = D_004A28A8->game->race->riders[D_004A3DD8->being];
    cRider_1FBE38 *rider = (cRider_1FBE38*)being;
    float len = len_32C0(*rider->getVelocity());
    float res = len * D_004A28A8->f14;
    ret->type = 2;
    *(float*)func_00226618(ret) = res;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303380);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (vector length).
void* func_00226618(void*);
static inline float len_3380(const t4Vector &v) {
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
extern "C" cLunoValue* func_00303380(cLunoValue* ret) {
    cBeing *being = D_004A28A8->game->race->riders[D_004A3DD8->being];
    cRider_1FBE38 *rider = (cRider_1FBE38*)being;
    float len = len_3380(*rider->getVelocity());
    ret->type = 2;
    *(float*)func_00226618(ret) = len;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303430);
#ifdef SKIP_ASM
// Int result setter taking the value by const reference; the by-value macro form lets jump1 hoist the -1 arm.
static inline void setInt_3430(cLunoValue* r, const unsigned& v) {
    r->type = 1;
    *func_00226610(r) = v;
}
extern "C" cLunoValue* func_00303430(cLunoValue* ret) {
    char *p = D_004A3DD8->f290;
    unsigned v;
    if (p)
        v = *(unsigned*)(p + 0x78);
    else
        v = 0xFFFFFFFF;
    setInt_3430(ret, v);
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303490);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int* func_00226620_3490(void*) __asm__("func_00226620__FPv");
extern "C" unsigned func_003079D8_3490(char*) __asm__("func_003079D8");
extern "C" cLunoValue* func_00303490(cLunoValue* ret) {
    char *p = D_004A3DD8->f2A4;
    unsigned v;
    if (p)
        v = func_003079D8_3490(p);
    else
        v = 0xFFFFFFFF;
    ret->type = 3;
    *func_00226620_3490(ret) = v;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003034F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" cLunoValue* func_003034F8(cLunoValue* ret) {
    cBeing *being = D_004A28A8->game->race->riders[D_004A3DD8->being];
    cRider_1FBE38 *rider = (cRider_1FBE38*)being;
    unsigned v;
    if (func_00122EE8(rider, 4))
        v = rider->mRiderHandler->fD4;
    else
        v = 0xFFFFFFFF;
    BIND_SET_RESULT_1FBE38(ret, v);
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303598);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D20_3598[2] __asm__("D_004A3D20");
float AIrandf(float, float);
void* func_00226618(void*);
extern int D_004A57B8_3598 __asm__("D_004A57B8");
struct T12_3598 { float a; float b; sBindEnd_1FBE38 f; };
extern T12_3598 D_004FBC60_3598 __asm__("D_004FBC60");
extern "C" cLunoValue* func_00303598(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A57B8_3598 == 0) {
        D_004FBC60_3598.a = 0;
        D_004FBC60_3598.b = 1.0f;
        D_004A57B8_3598 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBC60_3598.f = sBindEnd_1FBE38();
    }
    float v[4] __attribute__((aligned(16)));
    float* vp = v;
    func_003E6574(vp, &D_004FBC60_3598, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D20_3598[k] && D_004A3D20_3598[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    float r = AIrandf(vp[0], vp[1]);
    ret->type = 2;
    *(float*)func_00226618(ret) = r;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003036B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A57C0_36B0 __asm__("D_004A57C0");
extern sBindEnd_1FBE38 D_004A57C4_36B0 __asm__("D_004A57C4");
extern int D_004A57C8_36B0 __asm__("D_004A57C8");
extern int D_004A3D28_36B0[2] __asm__("D_004A3D28");
extern "C" void func_003E6574(void*, void*, int);
extern "C" int func_0030AF08(cWScriptMan*, int, int);
int* func_00226610(void*);


extern "C" cLunoValue* func_003036B0(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A57C8_36B0 == 0) {
        D_004A57C0_36B0 = -1;
        D_004A57C8_36B0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A57C4_36B0 = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A57C0_36B0, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D28_36B0[k] && D_004A3D28_36B0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int r = func_0030AF08(D_004A3DD8, D_004A3DD8->being, vp[0]);
    ret->type = 1;
    *func_00226610(ret) = r;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003037B0);
#ifdef SKIP_ASM
extern int D_004A57D0_37B0 __asm__("D_004A57D0");
extern sBindEnd_1FBE38 D_004A57D4_37B0 __asm__("D_004A57D4");
extern int D_004A57D8_37B0 __asm__("D_004A57D8");
extern int D_004A3D30_37B0[2] __asm__("D_004A3D30");


extern "C" cLunoValue* func_003037B0(cLunoValue* ret, int n, sBindArg_1FBE38 *e)
{
    if (D_004A57D8_37B0 == 0) {
        D_004A57D0_37B0 = -1;
        D_004A57D8_37B0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A57D4_37B0 = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int *vp;
    BIND_UNPACK_ARGS_1FBE38(vp, v, &D_004A57D0_37B0, 8, D_004A3D30_37B0, n, e);
    sRace* lvl = D_004A28A8->game->race;
    cBeing* being = lvl->riders[D_004A3DD8->being];
    cRider_1FBE38* r = (cRider_1FBE38*)being;
    int res;
    switch (vp[0]) {
    case 3: res = func_00122EE8(r, 0); break;
    case 4: res = func_00122EE8(r, 1); break;
    case 1: res = func_00122EE8(r, 2); break;
    case 0: res = func_00122EE8(r, 3); break;
    case 2: res = func_00122EE8(r, 4); break;
    case 5: res = func_00122EE8(r, 5); break;
    case 6: res = func_00122EE8(r, 6); break;
    case 7: res = func_00122EE8(r, 7); break;
    case 9: res = func_00122EE8(r, 8); break;
    case 10: res = func_00122EE8(r, 9); break;
    case 11: res = func_00122EE8(r, 10); break;
    case 12: res = func_00122EE8(r, 11); break;
    case 13: res = func_00122EE8(r, 12); break;
    case 14: res = func_00122EE8(r, 13); break;
    case 15: res = func_00122EE8(r, 14); break;
    case 16: res = func_00122EE8(r, 15); break;
    case 17: res = func_00122EE8(r, 16); break;
    case 8: res = func_00122EE8(r, 17); break;
    case 18: res = func_00122EE8(r, 18); break;
    default: res = 0; break;
    }
    BIND_SET_RESULT_1FBE38(ret, res);
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003039F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A3FF0_39F0 __asm__("D_004A3FF0");
extern "C" void func_00343C60_39F0(int, int) __asm__("func_00343C60");
extern "C" void func_00343F38_39F0(int, int) __asm__("func_00343F38");
extern unsigned D_39F0[] __asm__("D_004FBC70");
extern int D_004A57DC;
extern int D_004A3D38;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_003039F0(int n, sBindArg_1FBE38 *e) {
    if (D_004A57DC == 0) {
        D_39F0[0] = 0xFFFFFFFF;
        ((int*)D_39F0)[1] = -1;
        D_004A57DC = 1;
        *(sBindEnd_1FBE38*)((char*)D_39F0 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_39F0, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
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
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303BA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A2A00_3BA0 __asm__("D_004A2A00");
struct T20_3BA0 { unsigned a; int b; int c; int d; sBindEnd_1FBE38 f; };
extern T20_3BA0 D_4FBC80_3BA0 __asm__("D_004FBC80");
extern int D_57E0_3BA0 __asm__("D_004A57E0");
extern const int D_004465D8_3BA0[] __asm__("D_004465D8");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_00229820_3BA0(int, unsigned, int, int) __asm__("func_00229820");
extern "C" void func_00229788(int, unsigned);
extern "C" void func_002297D8(int, unsigned);
extern "C" cLunoValue func_00303BA0(int n, sBindArg_1FBE38 *e) {
    if (D_57E0_3BA0 == 0) {
        D_4FBC80_3BA0.a = 0xFFFFFFFF;
        D_4FBC80_3BA0.b = -1;
        D_4FBC80_3BA0.c = 0;
        D_4FBC80_3BA0.d = 0;
        D_57E0_3BA0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_4FBC80_3BA0.f = sBindEnd_1FBE38();
    }
    unsigned buf64[5];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_4FBC80_3BA0, 0x14);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
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
            func_00229788(D_004A2A00_3BA0, h);
        else if (mode == 3)
            func_002297D8(D_004A2A00_3BA0, h);
    }
    return D_004C9098;
}
#endif

extern "C" void func_00303D88(void) {
}

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303D90);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
extern "C" void* cBE_getBE_3D90(void) __asm__("cBE_getBE");
void* cBE_getInterface_Fv_3D90(void* be, int kind) __asm__("cBE_getInterface__Fv");
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
extern "C" void* cBE_getBE_3DF8(void) __asm__("cBE_getBE");
void* cBE_getInterface_Fv_3DF8(void* be, int kind) __asm__("cBE_getInterface__Fv");
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
extern "C" void* cBE_getBE_3E60(void) __asm__("cBE_getBE");
void* cBE_getInterface_Fv_3E60(void* be, int kind) __asm__("cBE_getInterface__Fv");
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
static inline bool isIdle_3EC8(int slot) {
    if (slot != -1) {
        cBeing *being = D_004A28A8->game->race->riders[slot];
        cRider_1FBE38 *rider = (cRider_1FBE38*)being;
        return !rider->isComputer();
    }
    return false;
}
extern "C" cLunoValue* func_00303EC8(cLunoValue* ret) {
    if (isIdle_3EC8(D_004A3DD8->being)) {
        ret->type = 1;
        *func_00226610(ret) = 1;
    } else {
        ret->type = 1;
        *func_00226610(ret) = 0;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303F80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" cLunoValue func_00303F80(void) {
    int slot = D_004A3DD8->being;
    if (slot != -1) {
        cBeing *being = D_004A28A8->game->race->riders[slot];
        cRider_1FBE38 *rider = (cRider_1FBE38*)being;
        rider->unk_3FC = 1;
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00303FF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D40_3FF0[2] __asm__("D_004A3D40");
void func_0030B4C0(void*, int, int);
extern int D_004A57E4_3FF0 __asm__("D_004A57E4");
struct T12_3FF0 { int a; int b; sBindEnd_1FBE38 f; };
extern T12_3FF0 D_004FBC98_3FF0 __asm__("D_004FBC98");
extern "C" cLunoValue func_00303FF0(int n, sBindArg_1FBE38* e) {
    if (D_004A57E4_3FF0 == 0) {
        D_004FBC98_3FF0.a = 0;
        D_004FBC98_3FF0.b = -1;
        D_004A57E4_3FF0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBC98_3FF0.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBC98_3FF0, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D40_3FF0[k] && D_004A3D40_3FF0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030B4C0(D_004A3DD8, vp[0], vp[1]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304100);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D48_4100[2] __asm__("D_004A3D48");
void func_0030B4D8(void*, int, int);
extern int D_004A57E8_4100 __asm__("D_004A57E8");
struct T12_4100 { int a; int b; sBindEnd_1FBE38 f; };
extern T12_4100 D_004FBCA8_4100 __asm__("D_004FBCA8");
extern "C" cLunoValue func_00304100(int n, sBindArg_1FBE38* e) {
    if (D_004A57E8_4100 == 0) {
        D_004FBCA8_4100.a = 0;
        D_004A57E8_4100 = 1;
        D_004FBCA8_4100.b = 0;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBCA8_4100.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBCA8_4100, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D48_4100[k] && D_004A3D48_4100[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030B4D8(D_004A3DD8, vp[0], vp[1]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304210);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D50_4210[2] __asm__("D_004A3D50");
void func_0030B4F0(void*, int, int);
extern int D_004A57EC_4210 __asm__("D_004A57EC");
struct T12_4210 { int a; int b; sBindEnd_1FBE38 f; };
extern T12_4210 D_004FBCB8_4210 __asm__("D_004FBCB8");
extern "C" cLunoValue func_00304210(int n, sBindArg_1FBE38* e) {
    if (D_004A57EC_4210 == 0) {
        D_004FBCB8_4210.a = 0;
        D_004FBCB8_4210.b = -1;
        D_004A57EC_4210 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBCB8_4210.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBCB8_4210, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D50_4210[k] && D_004A3D50_4210[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_0030B4F0(D_004A3DD8, vp[0], vp[1]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304320);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned D_004A57F0_4320 __asm__("D_004A57F0");
extern sBindEnd_1FBE38 D_004A57F4_4320 __asm__("D_004A57F4");
extern int D_004A57F8_4320 __asm__("D_004A57F8");
extern int D_004A3D58_4320[2] __asm__("D_004A3D58");
// Inline accessor of the current script process (wscript/wscriptman func_0030D2D8 is its out-of-line copy). Calling it
// at each use gives the shared copy of the pointer the target keeps (lw; move) instead of one cached local.
static inline cWScriptMan *curProcess_4320() { return D_004A3DD8; }
void func_0030B508(void*, int, void*);
extern "C" cLunoValue func_00304320(int n, sBindArg_1FBE38* e) {
    if (D_004A57F8_4320 == 0) {
        D_004A57F0_4320 = 0xFFFFFFFF;
        D_004A57F8_4320 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A57F4_4320 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned* buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_004A57F0_4320, 8);
    sBindArg_1FBE38* x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_004A3D58_4320[idx];
        unsigned* d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    int gv = curProcess_4320()->being;
    unsigned id = buf[0];
    char *obj;
    if (~id == 0) {
        obj = curProcess_4320()->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj)
        func_0030B508(curProcess_4320(), gv, obj);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003044A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D60_44A8[2] __asm__("D_004A3D60");
extern "C" void func_00238550(int, int, int);
extern int D_004A5808_44A8 __asm__("D_004A5808");
extern int D_004A5800_44A8 __asm__("D_004A5800");
extern sBindEnd_1FBE38 D_004A5804_44A8 __asm__("D_004A5804");
extern "C" cLunoValue func_003044A8(int n, sBindArg_1FBE38* e) {
    if (D_004A5808_44A8 == 0) {
        D_004A5800_44A8 = -1;
        D_004A5808_44A8 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A5804_44A8 = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5800_44A8, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D60_44A8[k] && D_004A3D60_44A8[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int b = D_004A3DD8->being;
    func_00238550(D_004A28A8->fC0, b, vp[0]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003045B8);
#ifdef SKIP_ASM
// PORT: 64-bit bitfield container (unsigned long is 8 bytes on the EE).
struct Rec_45B8 {
    unsigned a0; int a1; int a2; int a3;
    unsigned a4; unsigned a5; unsigned a6; unsigned a7;
    unsigned a8; unsigned a9; unsigned a10; unsigned a11;
    unsigned a12; unsigned a13; unsigned a14; unsigned a15;
    sBindEnd_1FBE38 f;
};
extern Rec_45B8 D_4FBCC8_45B8 __asm__("D_004FBCC8");
extern int D_580C_45B8 __asm__("D_004A580C");
extern const int D_00446650_45B8[] __asm__("D_00446650");
extern "C" void func_003E6574(void*, void*, int);
struct BF_45B8 {
    unsigned long f0 : 3; unsigned long f1 : 4; unsigned long f2 : 3; unsigned long f3 : 2;
    unsigned long f4 : 4; unsigned long f5 : 3; unsigned long f6 : 3; unsigned long f7 : 6;
    unsigned long f8 : 4; unsigned long f9 : 3; unsigned long f10 : 7; unsigned long f11 : 1;
    unsigned long f12 : 7; unsigned long f13 : 2; unsigned long f14 : 4; unsigned long f15 : 3;
    unsigned long f16 : 5;
};
extern "C" void func_0030B520_45B8(cWScriptMan*, BF_45B8*) __asm__("func_0030B520");
extern "C" cLunoValue func_003045B8(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_4FBCC8_45B8.f = sBindEnd_1FBE38();
    }
    Rec_45B8 rec;
    Rec_45B8 *buf = &rec;
    func_003E6574(buf, &D_4FBCC8_45B8, 0x44);
    BF_45B8 bf;
    sBindArg_1FBE38 *x = e;
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
    func_0030B520_45B8(D_004A3DD8, &bf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304980);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_00355878(void*, void*);
extern unsigned D_4980[] __asm__("D_004FBD10");
extern int D_004A5810;
extern int D_004A3D68;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00304980(int n, sBindArg_1FBE38 *e) {
    if (D_004A5810 == 0) {
        D_4980[0] = 0xFFFFFFFF;
        *(float*)&D_4980[1] = 1.0f;
        D_004A5810 = 1;
        *(sBindEnd_1FBE38*)((char*)D_4980 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_4980, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p == 0)
        return D_004C9098;
    if (p->isMoveNode())
        func_00355878(p, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304B38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D70_4B38[2] __asm__("D_004A3D70");
extern "C" void func_002709D8(void*, int, int);
extern int D_004A5820_4B38 __asm__("D_004A5820");
extern int D_004A5818_4B38 __asm__("D_004A5818");
extern sBindEnd_1FBE38 D_004A581C_4B38 __asm__("D_004A581C");
extern "C" cLunoValue func_00304B38(int n, sBindArg_1FBE38* e) {
    if (D_004A5820_4B38 == 0) {
        D_004A5818_4B38 = -1;
        D_004A5820_4B38 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A581C_4B38 = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5818_4B38, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D70_4B38[k] && D_004A3D70_4B38[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    func_002709D8(D_004A28A8->game->f28, D_004A3DD8->being, vp[0]);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304C50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* func_00226618(void*);
extern "C" void func_003E6574(void*, void*, int);
extern unsigned D_5828_4C50 __asm__("D_004A5828");
extern sBindEnd_1FBE38 D_582C_4C50 __asm__("D_004A582C");
extern int D_5830_4C50 __asm__("D_004A5830");
extern int D_3D78_4C50 __asm__("D_004A3D78");
static inline t4Vector pos_4C50(char *o) { return *(t4Vector*)(o + 0x40); }
extern "C" cLunoValue* func_00304C50(cLunoValue* ret, int n, sBindArg_1FBE38 *e) {
    if (D_5830_4C50 == 0) {
        D_5828_4C50 = 0xFFFFFFFF;
        D_5830_4C50 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_582C_4C50 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_5828_4C50, 8);
    sBindArg_1FBE38 *x = e;
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
    int slot = D_004A3DD8->being;
    char *obj;
    if (~id == 0) {
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        cBeing *being = D_004A28A8->game->race->riders[slot];
        cRider_1FBE38 *rider = (cRider_1FBE38*)being;
        float v;
        if (rider) {
            float z = rider->getPosition()->z;
            v = z - pos_4C50(obj).z;
        }
        else
            v = 0.0f;
        ret->type = 2;
        *(float*)func_00226618(ret) = v;
    } else {
        ret->type = 2;
        *(int*)func_00226618(ret) = 0;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304E38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355888(void*, void*);
extern unsigned D_4E38[] __asm__("D_004FBD20");
extern int D_004A5834;
extern int D_004A3D80;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00304E38(int n, sBindArg_1FBE38 *e) {
    if (D_004A5834 == 0) {
        D_4E38[0] = 0xFFFFFFFF;
        *(float*)&D_4E38[1] = 1.0f;
        D_004A5834 = 1;
        *(sBindEnd_1FBE38*)((char*)D_4E38 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_4E38, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
    if (p == 0)
        return D_004C9098;
    if (p->isMoveNode())
        func_00355888(p, buf);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00304FF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A5838_4FF0 __asm__("D_004A5838");
extern int D_004A3D88_4FF0[2] __asm__("D_004A3D88");
extern "C" void func_003E6574(void*, void*, int);

struct T12_4FF0 { int a; int b; sBindEnd_1FBE38 f; };
extern T12_4FF0 D_004FBD30_4FF0 __asm__("D_004FBD30");

extern "C" cLunoValue func_00304FF0(int n, sBindArg_1FBE38* e) {
    if (D_004A5838_4FF0 == 0) {
        D_004FBD30_4FF0.a = 0;
        D_004A5838_4FF0 = 1;
        D_004FBD30_4FF0.b = 0;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBD30_4FF0.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBD30_4FF0, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D88_4FF0[k] && D_004A3D88_4FF0[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003050F0);
#ifdef SKIP_ASM
// Defaults record of this camera-shake binding; keyword indexes the shake keyword table (the prototype asserts
// dp->Index < kNumCameraShakeKeywords).
struct Rec_50F0 { int keyword; int useObj; unsigned id; float scale; sBindEnd_1FBE38 f; };
extern Rec_50F0 D_004FBD40_50F0 __asm__("D_004FBD40");
extern int D_004A583C;
extern const int D_00446690[];
extern int D_004A3BD8[2];  // shake type per camera-shake keyword
extern "C" void func_0015E360(char* cam, int type, float amount, float dist);
// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector vSub_50F0(const t4Vector &a, const t4Vector &b) {
    t4Vector r;
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
static inline float vLen_50F0(const t4Vector &v) {
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
// Translation row of a transform (by value).
static inline t4Vector trans_50F0(const t4Matrix *m) { return m->row[3]; }
extern "C" cLunoValue func_003050F0(int n, sBindArg_1FBE38 *e) {
    if (D_004A583C == 0) {
        D_004FBD40_50F0.keyword = 0;
        D_004FBD40_50F0.useObj = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBD40_50F0.f = sBindEnd_1FBE38();
        D_004FBD40_50F0.scale = 1.0f;
        D_004FBD40_50F0.id = 0xFFFFFFFF;
        D_004A583C = 1;
    }
    Rec_50F0 rec;
    Rec_50F0 *buf = &rec;
    rec.id = 0xFFFFFFFF;
    func_003E6574(buf, &D_004FBD40_50F0, 0x14);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446690[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = 0;
    if (buf->useObj) {
        unsigned id = buf->id;
        if (~id == 0) {
            obj = D_004A3DD8->f290;
        } else {
            sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
            char *r;
            if (!s)
                r = 0;
            else
                r = refToObj_1FBE38(s->refs[id >> 8] >> 8);
            obj = r;
        }
    }
    int being = D_004A3DD8->being;
    float scale = buf->scale;
    int keyword = buf->keyword;
    if (keyword == 0) {
        sGame *game = D_004A28A8->game;
        int np = game->race->numPlayers;
        if (obj) {
            for (int i = 0; i < np; i++) {
                const t4Vector *rp = game->race->players[i]->rider->getPosition();
                cInstanceNode_1FBE38 *node = *(cInstanceNode_1FBE38**)(obj + 0xC);
                t4Matrix *m = node ? node->v24() : (t4Matrix*)(obj + 0x10);
                t4Vector d = vSub_50F0(*rp, trans_50F0(m));
                float dist = vLen_50F0(d);
                cRider_1FBE38 *r = game->race->players[i]->rider;
                int view = r->mViewIndex;
                if (r->mIsLocal)
                    func_0015E360(game->cameras->cam[view], D_004A3BD8[keyword], 1.0f, dist * scale);
            }
        } else {
            for (int i = 0; i < np; i++) {
                if (game->race->players[i]->rider->getAIIndex() == being) {
                    cRider_1FBE38 *r = game->race->players[i]->rider;
                    int view = r->mViewIndex;
                    if (r->mIsLocal)
                        func_0015E360(game->cameras->cam[view], D_004A3BD8[keyword], 1.0f, 0.0f);
                    break;
                }
            }
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305478);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Rec_5478 { unsigned id; float a; float b; sBindEnd_1FBE38 f; };
extern Rec_5478 D_4FBD58_5478 __asm__("D_004FBD58");
extern int D_5840_5478 __asm__("D_004A5840");
extern const int D_004466A0_5478[] __asm__("D_004466A0");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_003559F8_5478(cInstanceNode_1FBE38*, void*, float, float) __asm__("func_003559F8");
extern "C" cLunoValue func_00305478(int n, sBindArg_1FBE38 *e) {
    if (D_5840_5478 == 0) {
        D_4FBD58_5478.id = 0xFFFFFFFF;
        D_4FBD58_5478.a = 400.0f;
        D_4FBD58_5478.b = 30.0f;
        D_5840_5478 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_4FBD58_5478.f = sBindEnd_1FBE38();
    }
    Rec_5478 rec;
    Rec_5478 *buf = &rec;
    rec.id = 0xFFFFFFFF;
    func_003E6574(buf, &D_4FBD58_5478, 0x10);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p) {
            if (p->isMoveNode())
                func_003559F8_5478(p, p->v24(), buf->a, buf->b);
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305660);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00390EC8(float);
extern unsigned D_5660 __asm__("D_004A5848");
extern sBindEnd_1FBE38 D_004A584C;
extern int D_004A5850;
extern int D_004A3D90;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00305660(int n, sBindArg_1FBE38 *e) {
    if (D_004A5850 == 0) {
        D_5660 = 0xFFFFFFFF;
        D_004A5850 = 1;
        D_004A584C = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_5660, 8);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3D90)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    int k = D_004A3DD8->being;
    if (k != -1) {
        sRace* lvl = D_004A28A8->game->race;
        cBeing *being = lvl->riders[k];
        if (being->isHuman())
            func_00390EC8(0.0f);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003057C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Rec_57C0 { unsigned id; int a; int b; float c; float d; float e; float g; float h; int k; sBindEnd_1FBE38 f; };
extern Rec_57C0 D_4FBD68_57C0 __asm__("D_004FBD68");
extern int D_5854_57C0 __asm__("D_004A5854");
extern const int D_004466B0_57C0[] __asm__("D_004466B0");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void cMoveNode_addHalo_57C0(void*, void*) __asm__("cMoveNode_addHalo");
extern "C" cLunoValue func_003057C0(int n, sBindArg_1FBE38 *e) {
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
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_4FBD68_57C0.f = sBindEnd_1FBE38();
    }
    Rec_57C0 rec;
    Rec_57C0 *buf = &rec;
    rec.id = 0xFFFFFFFF;
    func_003E6574(buf, &D_4FBD68_57C0, 0x28);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p) {
            if (p->isMoveNode())
                cMoveNode_addHalo_57C0(p, buf);
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003059A0);
#ifdef SKIP_ASM
struct Rec_59A0 { int head; unsigned id[8]; int cnt[8]; float f0[8]; float f1[8]; float f2[8]; float f3[8]; sBindEnd_1FBE38 f; };
extern Rec_59A0 D_004FBD90_59A0 __asm__("D_004FBD90");
extern const int D_004466D8_59A0[] __asm__("D_004466D8");
extern int D_004A5858_59A0 __asm__("D_004A5858");
static inline char *conv_59A0(unsigned i) { return i ? refToPtr_1FBE38(i) : 0; }
extern "C" void cAvalanche_addAvalancheNode(int, void*, float, float, float, float, int);
extern "C" cLunoValue func_003059A0(int n, sBindArg_1FBE38* e) {
    if (D_004A5858_59A0 == 0) {
        D_004FBD90_59A0.head = 0;
        D_004FBD90_59A0.id[7] = D_004FBD90_59A0.id[6] = D_004FBD90_59A0.id[5] = D_004FBD90_59A0.id[4] = D_004FBD90_59A0.id[3] = D_004FBD90_59A0.id[2] = D_004FBD90_59A0.id[1] = D_004FBD90_59A0.id[0] = 0xFFFFFFFF;
        D_004FBD90_59A0.cnt[7] = D_004FBD90_59A0.cnt[6] = D_004FBD90_59A0.cnt[5] = D_004FBD90_59A0.cnt[4] = D_004FBD90_59A0.cnt[3] = D_004FBD90_59A0.cnt[2] = D_004FBD90_59A0.cnt[1] = D_004FBD90_59A0.cnt[0] = 0;
        D_004FBD90_59A0.f0[7] = D_004FBD90_59A0.f0[6] = D_004FBD90_59A0.f0[5] = D_004FBD90_59A0.f0[4] = D_004FBD90_59A0.f0[3] = D_004FBD90_59A0.f0[2] = D_004FBD90_59A0.f0[1] = D_004FBD90_59A0.f0[0] = 10.0f;
        D_004FBD90_59A0.f1[7] = D_004FBD90_59A0.f1[6] = D_004FBD90_59A0.f1[5] = D_004FBD90_59A0.f1[4] = D_004FBD90_59A0.f1[3] = D_004FBD90_59A0.f1[2] = D_004FBD90_59A0.f1[1] = D_004FBD90_59A0.f1[0] = 0.0f;
        D_004FBD90_59A0.f2[7] = D_004FBD90_59A0.f2[6] = D_004FBD90_59A0.f2[5] = D_004FBD90_59A0.f2[4] = D_004FBD90_59A0.f2[3] = D_004FBD90_59A0.f2[2] = D_004FBD90_59A0.f2[1] = D_004FBD90_59A0.f2[0] = 3.0f;
        D_004FBD90_59A0.f3[7] = D_004FBD90_59A0.f3[6] = D_004FBD90_59A0.f3[5] = D_004FBD90_59A0.f3[4] = D_004FBD90_59A0.f3[3] = D_004FBD90_59A0.f3[2] = D_004FBD90_59A0.f3[1] = D_004FBD90_59A0.f3[0] = 1.0f;
        D_004A5858_59A0 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBD90_59A0.f = sBindEnd_1FBE38();
    }
    Rec_59A0 rec;
    Rec_59A0* vp = &rec;
    rec.id[7] = rec.id[6] = rec.id[5] = rec.id[4] = rec.id[3] = rec.id[2] = rec.id[1] = rec.id[0] = 0xFFFFFFFF;
    func_003E6574(vp, &D_004FBD90_59A0, 0xC8);
    sBindArg_1FBE38* x = e;
    for (int i = 0; i < n; i++, x++) {
        int k = x->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (x->type != D_004466D8_59A0[k] && D_004466D8_59A0[k] == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    int head = vp->head;
    int* cp = vp->cnt;
    float* f3 = vp->f3;
    float* f2 = vp->f2;
    float* f1 = vp->f1;
    float* f0 = vp->f0;
    for (int i = 0; i < 8; i++) {
        unsigned id = vp->id[i];
        if (id != 0xFFFFFFFF) {
            sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
            char *r;
            if (!s)
                r = 0;
            else {
                unsigned j = s->refs[id >> 8] >> 8;
                r = conv_59A0(j);
            }
            cAvalanche_addAvalancheNode(head, r, *f0, *f1, *f2, *f3, *cp);
        }
        cp++; f3++; f2++; f1++; f0++;
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305C88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3D98_5C88[2] __asm__("D_004A3D98");
extern "C" int cAvalanche_triggerAvalanche(int);
extern int D_004A3AC4_5C88 __asm__("D_004A3AC4");
extern int D_004A5868_5C88 __asm__("D_004A5868");
extern int D_004A5860_5C88 __asm__("D_004A5860");
extern sBindEnd_1FBE38 D_004A5864_5C88 __asm__("D_004A5864");
extern "C" cLunoValue func_00305C88(int n, sBindArg_1FBE38* e) {
    if (D_004A5868_5C88 == 0) {
        D_004A5868_5C88 = 1;
        D_004A5860_5C88 = 0;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A5864_5C88 = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004A5860_5C88, 8);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3D98_5C88[k] && D_004A3D98_5C88[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int a = vp[0];
    if (D_004A3AC4_5C88 == 0)
        cAvalanche_triggerAvalanche(a);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305D90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00355A78_5D90(void*, void*) __asm__("func_00355A78");
extern unsigned D_5D90 __asm__("D_004A5870");
extern sBindEnd_1FBE38 D_004A5874;
extern int D_004A5878;
extern int D_004A3DA0;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00305D90(int n, sBindArg_1FBE38 *e) {
    if (D_004A5878 == 0) {
        D_5D90 = 0xFFFFFFFF;
        D_004A5878 = 1;
        D_004A5874 = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_5D90, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s)
            r = 0;
        else {
            i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            r = t;
        }
        obj = r;
    }
    if (obj) {
        cInstanceNode_1FBE38 *p = *(cInstanceNode_1FBE38**)(obj + 0xC);
        if (p) {
            if (p->isMoveNode())
                func_00355A78_5D90(p, obj);
        }
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00305F40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Rec_5F40 {
    int a; int b; float c; float d; float e;
    float m[28];
    float v[16];
    int k; int l; float n; int o; float p; unsigned id;
    sBindEnd_1FBE38 f;
};
extern Rec_5F40 D_4FBE58_5F40 __asm__("D_004FBE58");
extern int D_587C_5F40 __asm__("D_004A587C");
extern const int D_004467A0_5F40[] __asm__("D_004467A0");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_002D9538_5F40(char*, Rec_5F40*) __asm__("func_002D9538");
extern "C" cLunoValue func_00305F40(int n, sBindArg_1FBE38 *e) {
    if (D_587C_5F40 == 0) {
        Rec_5F40 &r = D_4FBE58_5F40;
        r.a = 1;
        r.b = 0;
        r.c = -1.0f;
        r.d = 1.0f;
        r.e = 4.0f;
        r.m[27] = r.m[26] = r.m[25] = r.m[24] = r.m[23] = r.m[22] = r.m[21] = r.m[20] = r.m[19] = r.m[18] = r.m[17] = r.m[16] = r.m[15] = r.m[14] = r.m[13] = r.m[12] = r.m[11] = r.m[10] = r.m[9] = r.m[8] = r.m[7] = r.m[6] = r.m[5] = r.m[4] = r.m[3] = r.m[2] = r.m[1] = r.m[0] = 0.0f;
        r.v[0] = 1.0f;
        r.v[3] = r.v[2] = r.v[1] = 0.0f;
        r.v[4] = 1.0f;
        r.v[5] = 1.0f;
        r.v[6] = 1.0f;
        r.v[7] = 1.0f;
        r.v[8] = 1.0f;
        r.v[11] = r.v[10] = r.v[9] = 0.0f;
        r.v[12] = 1.0f;
        r.v[15] = r.v[14] = r.v[13] = 0.0f;
        r.k = 16;
        r.l = 0;
        r.n = 0.0f;
        r.o = 1;
        r.p = 20.0f;
        r.id = 0xFFFFFFFF;
        D_587C_5F40 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        r.f = sBindEnd_1FBE38();
    }
    Rec_5F40 rec;
    Rec_5F40 *buf = &rec;
    rec.id = 0xFFFFFFFF;
    func_003E6574(buf, &D_4FBE58_5F40, 0xE0);
    sBindArg_1FBE38 *x = e;
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
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        char *obj;
        if (!s)
            obj = 0;
        else
            obj = refToObj_1FBE38(s->refs[id >> 8] >> 8);
        func_002D9538_5F40(obj, buf);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003061B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

extern int D_004A3DA8_61B0[2] __asm__("D_004A3DA8");
extern int D_005308D0_61B0[] __asm__("D_005308D0");
extern int D_004A5888_61B0 __asm__("D_004A5888");
extern int D_004A5880_61B0 __asm__("D_004A5880");
extern sBindEnd_1FBE38 D_004A5884_61B0 __asm__("D_004A5884");
extern "C" cLunoValue* func_003061B0(cLunoValue* ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A5888_61B0 == 0) {
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004A5880_61B0 = 0;
        D_004A5884_61B0 = sBindEnd_1FBE38();
        D_004A5888_61B0 = 1;
    }
    int v[4];
    int *vp;
    BIND_UNPACK_ARGS_1FBE38(vp, v, &D_004A5880_61B0, 8, D_004A3DA8_61B0, n, e);
    int r;
    switch (vp[0]) {
    case 0: {
        int flags = D_005308D0_61B0[0] >> 6;
        r = 0;
        if ((flags & 1) == 0)
            r++;
        break;
    }
    case 1: {
        int flags = D_005308D0_61B0[0] >> 8;
        r = 0;
        if ((flags & 1) == 0)
            r++;
        break;
    }
    case 2: {
        int flags = D_005308D0_61B0[0] >> 7;
        r = 0;
        if ((flags & 1) == 0)
            r++;
        break;
    }
    default:
        r = 1;
        break;
    }
    BIND_SET_RESULT_1FBE38(ret, r);
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306300);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);
int* func_00226610(void*);

extern int D_004A3DB0_6300[2] __asm__("D_004A3DB0");
extern "C" void func_001E3510(int, int);
extern int D_00534B30_6300[] __asm__("D_00534B30");
extern "C" void* cBE_getInterface_6300(void*, int) __asm__("cBE_getInterface__Fv");
extern int D_004A588C_6300 __asm__("D_004A588C");
struct T12_6300 { int a; int b; sBindEnd_1FBE38 f; };
extern T12_6300 D_004FBF38_6300 __asm__("D_004FBF38");
extern "C" cLunoValue func_00306300(int n, sBindArg_1FBE38* e) {
    if (D_004A588C_6300 == 0) {
        D_004FBF38_6300.a = 0;
        D_004A588C_6300 = 1;
        D_004FBF38_6300.b = 0;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FBF38_6300.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FBF38_6300, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3DB0_6300[k] && D_004A3DB0_6300[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    int x = vp[0];
    int y = vp[1];
    cBE_getInterface_6300(D_004A28A8->f78, 7);
    if (D_00534B30_6300[0] == 0)
        func_001E3510(x, y);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306438);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00101728_6438(void*, void*, float, float) __asm__("func_00101728");
extern unsigned D_6438[] __asm__("D_004FBF48");
extern int D_004A5890;
extern const int D_00446880[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00306438(int n, sBindArg_1FBE38 *e) {
    if (D_004A5890 == 0) {
        D_6438[0] = 0xFFFFFFFF;
        *(float*)&D_6438[1] = 1000.0f;
        ((int*)D_6438)[2] = 0;
        D_004A5890 = 1;
        *(sBindEnd_1FBE38*)((char*)D_6438 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_6438, 16);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            obj = 0;
        else
            obj = (char*)(i << 2);
    }
    if (obj) {
        float f1 = *(float*)&buf[1];
        float f2 = *(float*)&buf[2];
        int tmp[1];
        tmp[0] = *(int*)(obj + 0x78);
        func_00101728_6438(D_004A28A8->game->race->fA8, tmp, f1, f2);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003065E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

extern "C" void func_00101888_65E8(void*, void*) __asm__("func_00101888");
extern unsigned D_65E8 __asm__("D_004A5898");
extern sBindEnd_1FBE38 D_004A589C;
extern int D_004A58A0;
extern int D_004A3DB8;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_003065E8(int n, sBindArg_1FBE38 *e) {
    if (D_004A58A0 == 0) {
        D_65E8 = 0xFFFFFFFF;
        D_004A58A0 = 1;
        D_004A589C = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_65E8, 8);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = (&D_004A3DB8)[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    char *obj = lookupRef_1FBE38(buf[0]);
    if (obj) {
        int tmp[1]; tmp[0] = *(int*)(obj + 0x78);
        func_00101888_65E8(D_004A28A8->game->race->fA8, tmp);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306770);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

extern "C" void func_00101900_6770(void*, void*, int) __asm__("func_00101900");
extern unsigned D_6770[] __asm__("D_004FBF58");
extern int D_004A58A4;
extern int D_004A3DC0;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00306770(int n, sBindArg_1FBE38 *e) {
    if (D_004A58A4 == 0) {
        D_6770[0] = 0xFFFFFFFF;
        D_6770[1] = 0;
        D_004A58A4 = 1;
        *(sBindEnd_1FBE38*)((char*)D_6770 + 8) = sBindEnd_1FBE38();
    }
    unsigned buf64[3];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, D_6770, 12);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }

    if (obj) {
        int b1 = buf[1];
        func_00101900_6770(D_004A28A8->game->race->fA8, obj + 0x78, b1);
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306908);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00101970_6908(void*, void*) __asm__("func_00101970");
extern unsigned D_6908 __asm__("D_004A58A8");
extern sBindEnd_1FBE38 D_004A58AC;
extern int D_004A58B0;
extern int D_004A3DC8;
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00306908(int n, sBindArg_1FBE38 *e) {
    if (D_004A58B0 == 0) {
        D_6908 = 0xFFFFFFFF;
        D_004A58B0 = 1;
        D_004A58AC = sBindEnd_1FBE38();
    }
    unsigned buf64[2];
    unsigned *buf = buf64;
    buf[0] = 0xFFFFFFFF;
    func_003E6574(buf, &D_6908, 8);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj)
        func_00101970_6908(D_004A28A8->game->race->fA8, obj + 0x78);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306A90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Rec_6A90 {
    int a; int b; float c; float d; float e;
    float m[28];
    float v[16];
    int k; int l; float n; int o; float p; int q; int w;
    sBindEnd_1FBE38 f;
};
extern Rec_6A90 D_4FBF68_6A90 __asm__("D_004FBF68");
extern int D_58B4_6A90 __asm__("D_004A58B4");
extern const int D_00446890_6A90[] __asm__("D_00446890");
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_00357A78_6A90(void*, int, Rec_6A90*, int) __asm__("func_00357A78");
extern "C" cLunoValue func_00306A90(int n, sBindArg_1FBE38 *e) {
    if (D_58B4_6A90 == 0) {
        Rec_6A90 &r = D_4FBF68_6A90;
        r.a = 1;
        r.b = 0;
        r.c = -1.0f;
        r.d = 1.0f;
        r.e = 4.0f;
        r.m[27] = r.m[26] = r.m[25] = r.m[24] = r.m[23] = r.m[22] = r.m[21] = r.m[20] = r.m[19] = r.m[18] = r.m[17] = r.m[16] = r.m[15] = r.m[14] = r.m[13] = r.m[12] = r.m[11] = r.m[10] = r.m[9] = r.m[8] = r.m[7] = r.m[6] = r.m[5] = r.m[4] = r.m[3] = r.m[2] = r.m[1] = r.m[0] = 0.0f;
        r.v[0] = 1.0f;
        r.v[3] = r.v[2] = r.v[1] = 0.0f;
        r.v[4] = 1.0f;
        r.v[5] = 1.0f;
        r.v[6] = 1.0f;
        r.v[7] = 1.0f;
        r.v[8] = 1.0f;
        r.v[11] = r.v[10] = r.v[9] = 0.0f;
        r.v[12] = 1.0f;
        r.v[15] = r.v[14] = r.v[13] = 0.0f;
        r.k = 16;
        r.l = 0;
        r.n = 0.0f;
        r.o = 1;
        r.p = 20.0f;
        r.q = 0;
        r.w = 0x80;
        D_58B4_6A90 = 1;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        r.f = sBindEnd_1FBE38();
    }
    Rec_6A90 rec;
    Rec_6A90 *buf = &rec;
    func_003E6574(buf, &D_4FBF68_6A90, 0xE4);
    sBindArg_1FBE38 *x = e;
    for (int i = 0; i < n; i++, x++) {
        int idx = x->idx;
        int t = D_00446890_6A90[idx];
        unsigned *d = (unsigned*)((idx << 2) + (int)buf);
        if (x->type != t && t == 2)
            *(float*)d = (float)x->val;
        else
            *d = x->val;
    }
    func_00357A78_6A90(D_004A4028, buf->q, buf, buf->w);
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306CB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_00357AE8(void*, int, int);
void func_00357B10(void*, int, int);
extern unsigned D_6CB0[] __asm__("D_004FC050");
extern int D_004A58B8;
extern const int D_00446970[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue func_00306CB0(int n, sBindArg_1FBE38 *e) {
    if (D_004A58B8 == 0) {
        ((int*)D_6CB0)[0] = 0;
        D_6CB0[1] = 0xFFFFFFFF;
        ((int*)D_6CB0)[2] = 0;
        D_004A58B8 = 1;
        *(sBindEnd_1FBE38*)((char*)D_6CB0 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[1] = 0xFFFFFFFF;
    func_003E6574(buf, D_6CB0, 16);
    sBindArg_1FBE38 *x = e;
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
        obj = D_004A3DD8->f290;
    } else {
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        unsigned i;
        char *r;
        if (!s || (i = s->refs[id >> 8] >> 8) == 0)
            r = 0;
        else
            r = (char*)(i << 2);
        obj = r;
    }
    if (obj) {
        if (buf[2] == 0)
            func_00357AE8(D_004A4028, buf[0], *(int*)(obj + 0x78));
        else
            func_00357B10(D_004A4028, buf[0], *(int*)(obj + 0x78));
    }
    return D_004C9098;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00306E68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0030BFC0_6E68(cWScriptMan*, int, int, int) __asm__("func_0030BFC0");
extern "C" void *func_0028B180();
extern "C" void func_002974A0_6E68(void*, void*, int) __asm__("func_002974A0");
int *func_00226610(void*);
extern unsigned D_6E68[] __asm__("D_004FC060");
extern int D_004A58BC;
extern const int D_00446980[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" cLunoValue* func_00306E68(cLunoValue *ret, int n, sBindArg_1FBE38 *e) {
    if (D_004A58BC == 0) {
        D_6E68[0] = 0xFFFFFFFF;
        D_6E68[1] = 0xFFFFFFFF;
        D_6E68[2] = 0xFFFFFFFF;
        D_004A58BC = 1;
        *(sBindEnd_1FBE38*)((char*)D_6E68 + 12) = sBindEnd_1FBE38();
    }
    unsigned buf64[4];
    unsigned *buf = buf64;
    buf64[0] = 0xFFFFFFFF;
    buf64[1] = 0xFFFFFFFF;
    buf64[2] = 0xFFFFFFFF;
    func_003E6574(buf, D_6E68, 16);
    sBindArg_1FBE38 *x = e;
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
    int r = func_0030BFC0_6E68(D_004A3DD8, buf[0], b1, b2);
    if (r == 1) {
        unsigned id = buf[1];
        char *obj;
        sRefSet *s = (*D_004A47B8)->sets[id & 0xFF];
        if (!s) {
            obj = 0;
        } else {
            unsigned i = s->refs[id >> 8] >> 8;
            char *t = refToObj_1FBE38(i);
            obj = t;
        }
        if (obj)
            func_002974A0_6E68(func_0028B180(), obj, 0x5C);
    }
    ret->type = 1;
    *func_00226610(ret) = r;
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307020);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574(void*, void*, int);

extern int D_004A3DD0_7020[2] __asm__("D_004A3DD0");
extern "C" int func_001E3570(int, int);
extern int D_004A58C0_7020 __asm__("D_004A58C0");
struct T12_7020 { int a; int b; sBindEnd_1FBE38 f; };
extern T12_7020 D_004FC070_7020 __asm__("D_004FC070");
extern "C" cLunoValue* func_00307020(cLunoValue* ret, int n, sBindArg_1FBE38* e) {
    if (D_004A58C0_7020 == 0) {
        D_004FC070_7020.a = 0;
        D_004A58C0_7020 = 1;
        D_004FC070_7020.b = 0;
        // NOTE: guarded static-local init; the trailing empty member's value-init copies its byte through a stack temp (lbu; sb 0(sp)).
        D_004FC070_7020.f = sBindEnd_1FBE38();
    }
    int v[4] __attribute__((aligned(16)));
    int* vp = v;
    func_003E6574(vp, &D_004FC070_7020, 12);
    sBindArg_1FBE38* p = e;
    for (int i = 0; i < n; i++, p++) {
        int k = p->idx;
        int* d = (int*)((k << 2) + (int)vp);
        if (p->type != D_004A3DD0_7020[k] && D_004A3DD0_7020[k] == 2)
            *(float*)d = (float)p->val;
        else
            *d = p->val;
    }
    BIND_SET_RESULT_1FBE38(ret, func_001E3570(vp[0], vp[1]) != 0);
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307128);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_00489A30_7128[] __asm__("D_00489A30");
extern "C" void* cWScriptProcess_cWScriptProcess(void* self, void* man, int a1, int a2);
extern "C" int func_00309B70(void*, int);
extern "C" void* func_00307128(void* self, void* man, int a1, char* a2, int a3) {
    cWScriptProcess_cWScriptProcess(self, man, a1, (int)a2);
    *(void**)((char*)self + 0x5C) = D_00489A30_7128;
    *(int*)((char*)self + 0x60) = *(int*)(a2 + 0x50);
    *(int*)((char*)self + 0x64) = a3;
    for (int i = 0; i < 4; i++)
        ((int*)((char*)self + 0x68))[i] = func_00309B70(*(void**)((char*)self + 0x10), ((int*)(a2 + 0x40))[i]);
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003071C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_00489A30_71C8[] __asm__("D_00489A30");
extern "C" void func_00307738(void*, int);
extern "C" void func_003071C8(void* self, int flags) {
    *(void**)((char*)self + 0x5C) = D_00489A30_71C8;
    func_00307738(self, flags);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003071F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_0010F2B8_71F0(cRider_1FBE38*) __asm__("func_0010F2B8__FPv");
extern "C" void func_00307C40_71F0(void*) __asm__("func_00307C40");
extern "C" void func_003071F0(void* self) {
    func_0010F2B8_71F0(D_004A28A8->game->race->riders[**(int**)((char*)self + 0x10)]);
    func_00307C40_71F0(self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_00307240);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct P_7240 { int state; char pad[0x58]; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); };
int func_0030B898_7240(void*, void*) __asm__("func_0030B898__FPvT0");
extern "C" void *func_0028B180(void);
extern "C" void func_0029D8E0(void*);
extern "C" void func_00307240(P_7240* self) {
    if (func_0030B898_7240(*(void**)((char*)self + 0x10), self)) {
        self->v06();
        self->v18();
        func_0029D8E0(func_0028B180());
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
extern "C" int func_00153D78(void* missions, int id);
extern "C" void func_00154160(void* missions, int id, int done);
extern "C" int func_00153FA0(void* missions, int id);
extern "C" int func_001511B0(void* econ, int reward);
extern "C" int func_00144C98(void* iface);
extern "C" void func_0010F2D8(cRider_1FBE38* rider, int player, int money);
extern "C" int func_00153FD8(void* missions, int id);
extern "C" void func_001541D0(void* missions, int id, int active);
extern "C" void func_0030AC98(int, void *, int);
extern "C" int func_00153E28(void* missions, int id);
extern "C" void func_00154010(void* missions, int id, int a);
extern "C" void func_00154080(void* missions, int id, int a);
extern "C" void func_00308DB8(int script);
extern "C" void func_00309B00(int script, void* self);
extern "C" void func_0026F228(void* replay);
extern "C" void func_0026F7B8(void* replay);

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
    sRace* race = D_004A28A8->game->race;
    func_0010F2D8(race->riders[**(int**)(self + 0x10)], pl, money);
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
    func_0026F228(D_004A28A8->game->f28);
    func_0026F7B8(D_004A28A8->game->f28);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1FBE38", func_003074C0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
extern "C" int cBE_getInterface__Fv(void* be, int kind);
extern "C" int func_00153E80_74C0(int, int) __asm__("func_00153E80");
extern "C" void func_001540F0_74C0(int, int, int) __asm__("func_001540F0");
extern "C" void func_00307D78(void*);
extern "C" void func_0030AC98(int, void *, int);
struct P_74C0 { int state; char pad[0x58]; virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); };
extern "C" void func_003074C0(P_74C0* self) {
    int iface = cBE_getInterface__Fv(cBE_getBE(), 10);
    if (!func_00153E80_74C0(iface, *(int*)((char*)self + 0x20)))
        func_001540F0_74C0(iface, *(int*)((char*)self + 0x20), 1);
    int h = *(int*)((char*)self + 0x70);
    if (h)
        func_0030AC98(*(int*)((char*)self + 0x10), self, h);
    else
        self->v20();
    if (self->state == 2)
        func_00307D78(self);
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
