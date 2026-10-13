#include "common.h"

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_agf {
public:
    virtual ~cRiderVbA0_agf();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_agf : public cRiderVbA0_agf { public: char padA[0xC]; };
class cRiderVbB0_agf { public: virtual void b01(); };
class cRiderVbB_agf : public cRiderVbB0_agf { public: char padB[0x14]; };
class cRiderVbC0_agf {
public:
    virtual ~cRiderVbC0_agf();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_agf : public cRiderVbC0_agf { public: char padC[0x10]; };
class cRiderVbBC_agf : public cRiderVbB_agf, public cRiderVbC_agf { public: };
class cRiderVbPad_agf { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_agf : public cRiderVbPad_agf, public cRiderVbA_agf, public cRiderVbBC_agf {
public:
    virtual ~cRiderVb_agf();
};
void operator_delete(int* p);
#endif

INCLUDE_ASM("visualfx/angerfx", cAngerFX_cAngerFX);

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D4A70);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

class cVbDtor002D4A70 : virtual public cRiderVb_agf {
public:
    void* m04;
    virtual ~cVbDtor002D4A70();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002D4A70::~cVbDtor002D4A70()
{
    if (m04 != 0) cMemMan_free(m04);
}
// PORT: the compiler names this dtor _$_15cVbDtor002D4A70; expose it under the address-derived name.
__asm__(".globl func_002D4A70\n.type func_002D4A70,@function\nfunc_002D4A70 = _$_15cVbDtor002D4A70\n.size func_002D4A70,0x170\n");
#endif

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D4BE0);
#ifdef SKIP_ASM
extern "C" void* func_003E6448(void* dst, int c, int n);

extern "C" void func_002D4BE0(void* self)
{
    func_003E6448(*(void**)((char*)self + 4), 0, 0x58);
}
#endif

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D4C08);
#ifdef SKIP_ASM
void* cBEAggressionInterface_getThis();
extern "C" int func_00155B50(void* self, int a, int b);
extern char* D_004A28A8;
extern float D_00488EA0[];
extern float D_00488F48[];
extern float D_00488FF0[];
extern float D_00489070[];
extern float D_004890F0[];
extern float D_00489150[];

struct sCol_2D4C08 {
    float r, g, b, a;
};
extern sCol_2D4C08 D_004D5B30;
extern sCol_2D4C08 D_004D5B40;
extern sCol_2D4C08 D_004D5B50;
extern sCol_2D4C08 D_004D5B60;

struct sAngerSlot_2D4C08 {
    float level;            // 0x0
    sCol_2D4C08 col;        // 0x4
    float glowA;            // 0x14
    float glowB;            // 0x18
    int anger;              // 0x1C
    int t20;                // 0x20
    int t24;                // 0x24
    int t28;                // 0x28
};

struct sAnger_2D4C08 {
    char* rider;                    // 0x0
    sAngerSlot_2D4C08* slots;       // 0x4
};

struct sPlayers_2D4C08 {
    int f0;
    char* p[3];             // 0x4
    unsigned int count;     // 0x10
};

struct sVE_2D4C08 {
    short delta;
    short index;
    int (*fn)(void*);
};

static inline int riderV_2D4C08(char* rider, int n)
{
    char* obj = rider + 0x6C0;
    sVE_2D4C08* vt = *(sVE_2D4C08**)obj;
    return vt[n].fn(obj + vt[n].delta);
}

static inline float approach_2D4C08(float x, float target, float step)
{
    if (target + step < x) {
        return x - step;
    }
    if (x < target - step) {
        return x + step;
    }
    return target;
}

static inline sPlayers_2D4C08* players_2D4C08()
{
    return *(sPlayers_2D4C08**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
}

extern "C" void func_002D4C08(sAnger_2D4C08* self)
{
    if (riderV_2D4C08(self->rider, 8) != 0) {
        return;
    }
    for (unsigned int i = 0; i < players_2D4C08()->count; i++) {
        char* g = *(char**)(D_004A28A8 + 0x84);
        char* other = *(char**)(*(char**)(*(char**)((*(sPlayers_2D4C08**)(g + 0x84))->p[i] + 0xA8) + 0x20) + 4);
        if (other == 0) {
            continue;
        }
        sAngerSlot_2D4C08* st = &self->slots[i];
        if (*(int*)(self->rider + 0xAC4) != 0) {
            st->level = 0;
            return;
        }
        int n = **(int**)(g + 0x28);
        int ok = n != 0 && n < 10;
        if (ok) {
            st->level = 0;
            return;
        }
        void* aggr = cBEAggressionInterface_getThis();
        int a = riderV_2D4C08(self->rider, 7);
        int lvl = func_00155B50(aggr, a, riderV_2D4C08(other, 7));
        int old = st->anger;
        st->anger = lvl;
        if (lvl >= 4) {
            st->col = D_004D5B30;
        } else if (lvl >= 3) {
            st->col = D_004D5B40;
        } else if (lvl >= 2) {
            st->col = D_004D5B50;
        } else {
            st->col = D_004D5B60;
        }
        if (lvl >= 2) {
            st->level = approach_2D4C08(st->level, 1.0f, 0.10000000894069672f);
        } else {
            st->level = approach_2D4C08(st->level, 0.0f, 0.06666667014360428f);
        }
        st->col.r = st->level * 0.800000011920929f;
        if (st->t20 > 0 || old != lvl) {
            st->t20++;
            st->t20 %= 41;
        }
        if (st->t24 > 0 || (lvl >= 4 && st->t20 == 0)) {
            st->t24++;
            st->t24 %= 31;
        }
        if (st->t28 > 0 || old < lvl) {
            if (old < lvl) {
                st->t28 = 0;
            }
            st->t28++;
            st->t28 %= 24;
            if (st->t20 > 0 || st->t24 > 0) {
                st->t28 = 0;
            }
        }
        float x = st->level;
        float ga = x * D_00488EA0[st->t20] * D_00488FF0[st->t24] * D_004890F0[st->t28];
        float gb = x * D_00488F48[st->t20] * D_00489070[st->t24] * D_00489150[st->t28];
        st->glowA = ga;
        st->glowB = gb;
    }
}
#endif

INCLUDE_ASM("visualfx/angerfx", func_002D5048);

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D5598);
#ifdef SKIP_ASM
extern "C" void func_002D5598(unsigned char* rgb, float r, float g, float b)
{
    rgb[0] = (int)r;
    rgb[1] = (int)g;
    rgb[2] = (int)b;
}
#endif

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D55C0);
#ifdef SKIP_ASM
extern float D_004A3A38;

// PORT: <? (g++ min operator)
extern "C" void func_002D55C0(unsigned char* p, float r, float g, float b)
{
    float zero = 0.0f;
    float one = 1.0f;
    r *= D_004A3A38;
    g *= D_004A3A38;
    b *= D_004A3A38;
    float cr, cg, cb;
    if (r >= zero) cr = r <? one; else cr = zero;
    if (g >= zero) cg = g <? one; else cg = zero;
    if (b >= zero) cb = b <? one; else cb = zero;
    p[3] = (int)(cr * 255.0f);
    p[4] = (int)(cg * 255.0f);
    p[5] = (int)(cb * 255.0f);
}
#endif

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D5658);
#ifdef SKIP_ASM
extern "C" void func_002D5658(unsigned char* p, float r, float g, float b, float a)
{
    p[6] = (int)(r * 127.0f);
    p[7] = (int)(g * 127.0f);
    p[8] = (int)(b * 127.0f);
    p[9] = (int)(a * 255.0f);
}
#endif

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D56B0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_003715B0(void* p, int a1);
extern "C" void func_003714F8(void* p, int a1);

extern "C" void func_002D56B0(int* self, int flags)
{
    func_003715B0((char*)self + 0xD0, 1);
    func_003714F8((char*)self + 0xD0, 2);
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D5718);
#ifdef SKIP_ASM
extern "C" int func_002D5718(const void* a, const void* b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;
    if (x < y) {
        return -1;
    }
    if (y < x) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/angerfx", func_002D5750);
#ifdef SKIP_ASM
extern "C" int func_002D5750(const void* a, const void* b)
{
    unsigned short x = *(const unsigned short*)a;
    unsigned short y = *(const unsigned short*)b;
    if (x < y) {
        return -1;
    }
    return y < x;
}
#endif

