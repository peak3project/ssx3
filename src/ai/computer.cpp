#include "common.h"
#include "ai/rider.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// The AI's rider list (the game's +0xC object; ai/ai's sAiRiderList): riders at 0x28, their count at 0x78.
struct sAiRiderList
{
    char pad0[0x8];
    int frame;                  // 0x8: frame counter
    char padC[0x1C];
    char* mRiders[19];          // 0x28
    int mMode;                  // 0x74
    int mCount;                 // 0x78
    int pad7C;                  // 0x7C
    int f80;                    // 0x80
};

// The game singleton D_004A28A8 (seg/seg_1FBE38's sApp / sGame; only the members this unit reads).
struct sGame {
    char pad_0x0[0xC];
    sAiRiderList* race;         // 0xC
    char pad_0x10[0x18];
    void* f28;                  // 0x28
};
struct sApp {
    char pad_0x0[0x84];
    sGame* game;                // 0x84
    char pad_0x88[0x38];
    char* fC0;                  // 0xC0 (ai/ai: p)
};
extern sApp* D_004A28A8;

// The computer rider's AI (cComputer) as the animation pickers func_0010CBE0 / func_0010CD20 / func_0010CF68 see
// it: its rider at 0x18, the pick's timing at 0xE24..0xE34 and three 15-entry use counters (cleared by
// func_0010D170).
struct cComputer
{
    char pad0[0x18];
    char* mRider;               // 0x18
    char pad1C[0xE24 - 0x1C];
    int fE24;                   // 0xE24
    int fE28;                   // 0xE28
    float fE2C;                 // 0xE2C
    float fE30;                 // 0xE30
    float fE34;                 // 0xE34
    char padE38[0xE7C - 0xE38];
    int a[15];                  // 0xE7C
    int b[15];                  // 0xEB8
    int c[15];                  // 0xEF4
};

// cRider's per-other-rider record (ai/rider.h sRiderPair, 6 of them at 0x0) with the fields func_0010F3B8 resets.
struct sAiPair { int vis; int val; float dist; int c; int d; int e; int f; int g; int h; };

//100%
INCLUDE_ASM("ai/computer", cComputer_setIndividualRiderDifficulty);
#ifdef SKIP_ASM
struct sAiTune {
    char pad0[0xDC];
    float accel;     // 0xDC
    float speed;     // 0xE0
    int boost;       // 0xE4
};

// cComputer as the difficulty code sees it: the rider at 0x18 read as its AI tuning, the skill values.
struct sCompSkill {
    char pad_0x0[0x18];
    sAiTune* tune;                  // 0x18
    char pad_0x1C[0xDF8 - 0x1C];
    float skillA;                   // 0xDF8
    float skillB;                   // 0xDFC
    short diff;                     // 0xE00
    short pad_0xE02;
    int f4;                         // 0xE04
    int f8;                         // 0xE08
};

// Applies the per-level AI tuning; mode 0 and mode 2 override the skill values with their own tables.
// skillB is stored as a percentage and scaled to 0..1 at the end.
extern "C" void cComputer_setIndividualRiderDifficulty(sCompSkill* self, int level, int mode)
{
    switch (level) {
    case 1:
        self->skillA = 100.0f;
        self->skillB = 86.9153976f;
        self->tune->accel = -49670.1406f;
        self->tune->speed = 47500.0f;
        self->tune->boost = 0;
        break;
    case 2:
        self->skillA = 80.3891449f;
        self->skillB = 79.5998383f;
        self->tune->accel = -70000.0f;
        self->tune->speed = 45000.0f;
        self->tune->boost = 1;
        break;
    case 3:
        self->skillA = 51.007576f;
        self->skillB = 68.9012375f;
        self->tune->accel = -81571.1797f;
        self->tune->speed = 40000.0f;
        self->tune->boost = 1;
        break;
    case 4:
        self->skillA = 46.6018982f;
        self->skillB = 56.8430748f;
        self->tune->accel = -80321.1797f;
        self->tune->speed = 37500.0f;
        self->tune->boost = 1;
        break;
    case 5:
        self->skillA = 14.000701f;
        self->skillB = 42.4410439f;
        self->tune->accel = -92500.0f;
        self->tune->speed = 32500.0f;
        self->tune->boost = 1;
        break;
    }
    if (mode == 0) {
        switch (level) {
        case 1:
            self->skillA = 100.0f;
            self->skillB = 83.8930817f;
            self->tune->speed = 45000.0f;
            break;
        case 2:
            self->skillA = 55.8049736f;
            self->skillB = 64.6436768f;
            self->tune->speed = 42500.0f;
            break;
        case 3:
            self->skillA = 40.2501869f;
            self->skillB = 60.0044975f;
            self->tune->speed = 37500.0f;
            break;
        case 4:
            self->skillA = 15.5423021f;
            self->skillB = 52.0049553f;
            self->tune->speed = 32500.0f;
            break;
        case 5:
            self->skillA = 7.95483208f;
            self->skillB = 35.0202637f;
            self->tune->speed = 30000.0f;
            break;
        }
    } else if (mode == 2) {
        switch (level) {
        case 1:
            self->skillA = 100.0f;
            self->skillB = 100.0f;
            self->tune->speed = 50000.0f;
            break;
        case 2:
            self->skillA = 84.9981003f;
            self->skillB = 82.6824875f;
            self->tune->speed = 47500.0f;
            break;
        case 3:
            self->skillA = 74.9987259f;
            self->skillB = 70.8223801f;
            self->tune->speed = 40000.0f;
            break;
        case 4:
            self->skillA = 54.9958344f;
            self->skillB = 59.9440651f;
            self->tune->speed = 37500.0f;
            break;
        case 5:
            self->skillA = 29.9814339f;
            self->skillB = 46.9987717f;
            self->tune->speed = 32500.0f;
            break;
        }
    }
    self->skillB *= 0.01f;
}
#endif

//100%
INCLUDE_ASM("ai/computer", cComputer_updateRiderDifficulty);
#ifdef SKIP_ASM
extern signed char D_00535BC8[];
extern int D_005308D0[];
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" short func_0010C450(void* self, int level, int mode);
extern "C" int func_00144BE0(void* iface);
extern "C" int func_00147CB8(void* iface, int flag);
void cComputer_setIndividualRiderDifficulty_UR(void* self, int level, int mode) __asm__("cComputer_setIndividualRiderDifficulty");

static inline int ValidOr_UR(int v, int invalid, int def)
{
    if (v <= invalid)
        v = def;
    return v;
}

void cComputer_updateRiderDifficulty_UR(sCompSkill* self) __asm__("cComputer_updateRiderDifficulty");
void cComputer_updateRiderDifficulty_UR(sCompSkill* self)
{
    char* rider = *(char**)((char*)self + 0x18);
    int mode = *(int*)D_004A28A8->fC0;
    char* obj = rider + 0x6C0;
    sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)obj;
    int r = vt[7].fn(obj + vt[7].delta);
    int level = ValidOr_UR(r, -1, 1);
    self->diff = func_0010C450(self, level, mode);
    if (level == 1 && mode == 3) {
        self->f4 = 1;
    } else {
        self->f4 = 0;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BC8[0x48] == 1 || D_00535BC8[0x48] == 6 || D_00535BC8[0x48] == 5) {
        self->f8 = 1;
    } else {
        self->f8 = 0;
    }
    cComputer_setIndividualRiderDifficulty_UR(self, level, func_00147CB8(cBE_getInterface_Fv(cBE_getBE(), 1), D_00535BC8[0x48] == 0));
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535BC8[0x4A] == 4) {
        self->diff = 0;
    } else if (D_00535BC8[0x4A] == 5) {
        self->diff = 2;
    }
    if ((D_005308D0[0] >> 2) & 1) {
        self->skillB = 1.0f;
        self->skillA = 100.0f;
        self->f4 = 1;
        self->tune->accel = -100.0f;
        self->tune->speed = 100.0f;
        self->tune->boost = 2;
        if (level == 1 || level == 2) {
            self->diff = 2;
        } else {
            self->diff = 1;
        }
        return;
    }
    if (func_00144BE0(iface) == 4) {
        self->skillB += self->skillB * 0.25f;
    } else if (func_00144BE0(iface) == 2 || func_00144BE0(iface) == 3) {
        self->skillB += self->skillB * 0.10000000149011612f;
    }
    if (self->skillB > 1.0f) {
        self->skillB = 1.0f;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010C9A8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144C98(void* iface);
extern "C" void func_00148AA8(void* iface, int a1, int a2);

static inline int riderV7_10C9A8(char* rider)
{
    char* obj = rider + 0x6C0;
    sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)obj;
    return vt[7].fn(obj + vt[7].delta);
}

extern "C" void func_0010C9A8(void* self)
{
    void* s = cBE_getInterface_Fv(cBE_getBE(), 3);
    void* g = cBE_getInterface_Fv(cBE_getBE(), 0);
    if (func_00144C98(g) == 2)
    {
        func_00148AA8(s, riderV7_10C9A8(*(char**)((char*)self + 0x18)), 7);
    }
    else if (func_00144C98(g) == 1)
    {
        func_00148AA8(s, riderV7_10C9A8(*(char**)((char*)self + 0x18)), 4);
    }
    else
    {
        func_00148AA8(s, riderV7_10C9A8(*(char**)((char*)self + 0x18)), 1);
    }
}
#endif

extern "C" void cComputer_updateRiderDifficulty(void*);

//100%
INCLUDE_ASM("ai/computer", func_0010CAB8);
#ifdef SKIP_ASM
extern "C" void func_0010CAB8(void* self)
{
    cComputer_updateRiderDifficulty(self);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010CAD8);
#ifdef SKIP_ASM
extern "C" int func_0010C258(void* self);
extern "C" int func_0010C320(void* self);
extern "C" int func_0010C3B8(void* self);
extern "C" int func_0010CF68(void* self, float t);
extern "C" int func_0010CD20(void* self, float t);
extern "C" int func_0010CBE0(void* self, float t);

extern "C" int func_0010CAD8(void* self, float t)
{
    int r = -1;
    int skip = *(int*)((char*)self + 0xE20) != 0 && t < 1.0f;
    if (!skip && t > 0.75f && t != 100.0f)
    {
        if (func_0010C258(self)) r = func_0010CF68(self, t);
        if (r == -1)
        {
            if (func_0010C320(self)) r = func_0010CD20(self, t);
            if (r == -1)
            {
                if (func_0010C3B8(self)) r = func_0010CBE0(self, t);
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010CBE0);
#ifdef SKIP_ASM
unsigned int AIrand();
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" unsigned short func_001500D8(void* self, int a1, int a2);
extern "C" float func_00120038(void* self);
extern "C" float func_00312820(char* self, int a1, int frame);

static inline int riderV7_10CBE0(char* rider)
{
    char* obj = rider + 0x6C0;
    sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)obj;
    return vt[7].fn(obj + vt[7].delta);
}

extern "C" int func_0010CBE0(void* p, float t)
{
    cComputer* self = (cComputer*)p;
    self->fE24 = 0;
    self->fE28 = 0;
    self->fE30 = t;
    int idx = AIrand() % 15;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 6);
    int anim = func_001500D8(iface, riderV7_10CBE0(self->mRider), idx);
    float spd = func_00120038(self->mRider);
    float a = func_00312820(*(char**)(self->mRider + 0x784), anim, 2) / spd;
    float b = func_00312820(*(char**)(self->mRider + 0x784), anim, 1) / spd;
    if (t < a) return -1;
    self->fE34 = t - a;
    self->fE2C = a - b;
    if (idx != -1 && idx < 15)
    {
        self->a[idx]++;
    }
    return idx;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010CD20);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" unsigned short func_001500D8(void* self, int a1, int a2);
extern "C" unsigned short func_00150138(void* self, int a1, int a2);
extern "C" int func_00150198(void* self, int a1, int a2, int a3);
extern "C" float func_00120038(void* self);
extern "C" float func_00312820(char* self, int a1, int frame);

static inline int riderV7_10CD20(char* rider)
{
    char* obj = rider + 0x6C0;
    sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)obj;
    return vt[7].fn(obj + vt[7].delta);
}

extern "C" int func_0010CD20(void* p, float t)
{
    cComputer* self = (cComputer*)p;
    self->fE24 = 0;
    self->fE30 = t;
    int found = -1;
    int best = 10000;
    int i = 1;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 6);
    float spd = func_00120038(self->mRider);
    for (; i < 15; i++)
    {
        int anim = func_00150138(iface, riderV7_10CD20(self->mRider), i);
        if (anim == 0x1B6)
            continue;
        int alt = (*(int*)(self->mRider + 0xB2C) & 1) ? func_00150198(iface, riderV7_10CD20(self->mRider), i, *(int*)(self->mRider + 0x2F4) >= 5) : 0x1B6;
        if (0.0f < *(float*)(self->mRider + 0x2F0) && alt != 0x1B6)
            continue;
        int anim2 = func_001500D8(iface, riderV7_10CD20(self->mRider), i);
        float a = func_00312820(*(char**)(self->mRider + 0x784), anim2, 1) / spd;
        float b = func_00312820(*(char**)(self->mRider + 0x784), anim, 1) / spd;
        float c = func_00312820(*(char**)(self->mRider + 0x784), anim, 2) / spd;
        float sum = c + a;
        if (sum < t && self->c[i] < best)
        {
            self->fE28 = 1;
            found = i;
            self->fE2C = c - b;
            self->fE34 = t - sum;
            best = self->c[i];
        }
    }
    if (found != -1 && found < 15)
    {
        self->c[found]++;
    }
    return found;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010CF68);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" unsigned short func_001500D8(void* self, int a1, int a2);
extern "C" int func_00150198(void* self, int a1, int a2, int a3);
extern "C" float func_00120038(void* self);
extern "C" float func_00312820(char* self, int a1, int frame);

static inline int riderV7_10CF68(char* rider)
{
    char* obj = rider + 0x6C0;
    sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)obj;
    return vt[7].fn(obj + vt[7].delta);
}

extern "C" int func_0010CF68(void* p, float t)
{
    cComputer* self = (cComputer*)p;
    self->fE28 = 0;
    if (*(float*)(self->mRider + 0x2F0) <= 0.0f)
        return -1;
    self->fE30 = t;
    int found = -1;
    int best = 10000;
    int i = 0;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 6);
    float spd = func_00120038(self->mRider);
    for (; i < 15; i++)
    {
        int anim = func_00150198(iface, riderV7_10CF68(self->mRider), i, *(int*)(self->mRider + 0x2F4) >= 5);
        if (anim == 0x1B6)
            continue;
        int anim2 = func_001500D8(iface, riderV7_10CF68(self->mRider), i);
        float a = func_00312820(*(char**)(self->mRider + 0x784), anim2, 1) / spd;
        float b = func_00312820(*(char**)(self->mRider + 0x784), anim, 1) / spd;
        float c = func_00312820(*(char**)(self->mRider + 0x784), anim, 2) / spd;
        float sum = c + a;
        if (sum < t && self->b[i] < best)
        {
            self->fE24 = 1;
            found = i;
            self->fE2C = c - b;
            self->fE34 = t - sum;
            best = self->b[i];
        }
    }
    if (found != -1 && found < 15)
    {
        self->b[found]++;
    }
    return found;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010D170);
#ifdef SKIP_ASM
extern "C" void func_0010D170(cComputer* self)
{
    for (int i = 0; i < 15; i++)
    {
        self->a[i] = 0;
        self->b[i] = 0;
        self->c[i] = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010D1A0);
#ifdef SKIP_ASM
int func_0011FE98(void* self);
int func_0011FEE8(void* self);
extern "C" float func_0031C228(float x);

struct sRider_0010D1A0 {
    char pad0[0x1B0];
    t4Vector vel;  // 0x1B0
    char pad1C0[0x4C8 - 0x1C0];
    float speed;        // 0x4C8
    float heading;      // 0x4CC
    char pad4D0[0x788 - 0x4D0];
    char* board;        // 0x788

    t4Vector getVel() { return vel; }
};

struct sComputer_0010D1A0 {
    char pad0[0x18];
    sRider_0010D1A0* rider;  // 0x18
    char pad1C[0xE70 - 0x1C];
    int dir;                 // 0xE70
    int stuckTime;           // 0xE74
    int wrongTime;           // 0xE78
};

static inline float atan2_0010D1A0(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f) {
            return y;
        }
        if (y >= 0.0f) {
            return 1.5707963705062866f;
        }
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f) {
            a += 3.1415927410125732f;
        } else {
            a -= 3.1415927410125732f;
        }
    }
    return a;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_0010D1A0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline float wrap_0010D1A0(float x)
{
    return x - ffloor_0010D1A0(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

extern "C" int func_0010D1A0(sComputer_0010D1A0* self)
{
    float ang = atan2_0010D1A0(self->rider->getVel().y, self->rider->getVel().x);
    float d = wrap_0010D1A0(self->rider->heading - ang);
    if (self->dir < 0) {
        if (__builtin_fabsf(d) > 1.047197699546814f) {
            self->wrongTime++;
        } else {
            self->wrongTime = 0;
        }
    } else {
        self->wrongTime = 0;
    }
    int wrong = self->wrongTime >= 0x3D;
    if (func_0011FE98(self->rider) == 2) {
        wrong = 0;
        self->stuckTime++;
    } else if (func_0011FE98(self->rider) == 4 && self->wrongTime > 0) {
        return 1;
    } else if (func_0011FE98(self->rider) == 1 || self->rider->speed < 1000.0f) {
        self->stuckTime = 0;
        wrong = 0;
        if (func_0011FE98(self->rider) == 1 && *(float*)(self->rider->board + 0xA0) > 30.0f) {
            return 1;
        }
    } else {
        self->stuckTime++;
    }
    int stuck = wrong || self->stuckTime >= 0xDF;
    if (func_0011FEE8(self->rider) != 8) {
        stuck = stuck && self->dir < 0;
    }
    return stuck;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010D410);
#ifdef SKIP_ASM
unsigned int AIrand();
extern "C" float func_0010D870(void* self, int a1, int a2, int a3);
extern "C" int func_0010FC30(sAiRiderList* self, int team);
extern "C" float func_00112588(void* self, int arg1);
extern "C" float func_0026A428(void* path, void* a1, void* a2, void* a3, int n);

// PORT: PS2-only VU0 inline asm (vector length).
static inline float vu0Length_10D410(const t4Vector& v)
{
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector vu0Scale_10D410(const t4Vector& v, float s)
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
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline t4Vector vu0Add_10D410(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

static inline int speedLimit_10D410(int kind)
{
    if (kind == 1) {
        return 20;
    }
    if (kind == 2) {
        return 40;
    }
    if (kind == 3) {
        return 60;
    }
    if (kind == 4) {
        return 80;
    }
    if (kind == 5) {
        return 100;
    }
    if (kind == 6) {
        return 120;
    }
    return 0;
}

extern "C" float func_0010D410(char* self, char* tgt)
{
    float sc[7];
    char* ai = (char*)D_004A28A8->game->race;
    int flags = *(int*)(tgt + 0x38);
    int kind = (flags >> 7) & 7;
    int lvl = (flags >> 4) & 7;
    int solo = flags & 1;
    if (kind > 8) {
        kind = 0;
    }
    int b2 = (flags >> 2) & 1;
    int b1 = (flags >> 1) & 1;
    int b3 = (flags >> 3) & 1;
    float base = func_0010D870(self, b3, b2, b1);
    if (base <= 0.0f) {
        return 0.0f;
    }
    if (*(int*)(self + 0xE04) == 0 && solo != 0) {
        return 0.0f;
    }
    float speed = vu0Length_10D410(*(t4Vector*)(*(char**)(self + 0x18) + 0x1E0)) * 0.035999998450279236f;
    if (lvl == 0) {
        if ((float)speedLimit_10D410(kind) < speed) {
            return 0.0f;
        }
    } else if (lvl == 3) {
        if (speed < (float)speedLimit_10D410(kind)) {
            return 0.0f;
        }
    }
    char* r = *(char**)(self + 0x18);
    float len = vu0Length_10D410(*(t4Vector*)(r + 0x1E0));
    float total = 22.0f;
    float s = func_00112588(r, 1) / len;
    t4Vector pos = vu0Add_10D410(*(t4Vector*)(*(char**)(self + 0x18) + 0x110), vu0Scale_10D410(*(t4Vector*)(*(char**)(self + 0x18) + 0x1E0), s));
    t4Vector out;
    float t;
    func_0026A428(tgt, &pos, &out, &t, 1);
    float d = t;
    float v = 100.0f - d * d * 1.5999999959603883e-05f;
    if (v < 0.0f) {
        v = 0.0f;
    }
    if (5000.0f < d) {
        return -1.0f;
    }
    sc[0] = v * 0.22727273404598236f;
    char* r2 = *(char**)(self + 0x18);
    if (*(int*)(r2 + 0xF0) != 0 && *(char**)(((sAiRiderList*)ai)->mRiders[*(int*)(r2 + 0xF8)] + 0xAB8) == tgt) {
        return 100.0f;
    }
    float zero = 0.0f;
    sc[1] = zero;
    float w = 1.0f / total;
    sc[2] = (float)lvl * (w * 0.3333333432674408f);
    // PORT: the path pointer is passed as func_0010FC30's int team
    int n = func_0010FC30((sAiRiderList*)ai, (int)tgt);
    n -= tgt == *(char**)(*(char**)(self + 0x18) + 0xAB8);
    float c;
    if (n <= 0) {
        c = 100.0f;
    } else if (n == 1) {
        c = 25.0f;
    } else {
        c = zero;
    }
    w = 5.0f / total;
    sc[3] = c * w;
    w = base / total;
    sc[4] = w;
    w = 5.0f / total;
    if (*(int*)(self + 0xE04) != 0 && solo != 0) {
        sc[5] = w * 100.0f;
    } else {
        sc[5] = 0.0f;
    }
    w = 2.0f / total;
    if (*(int*)(self + 0xE08) != 0) {
        sc[6] = (float)(AIrand() % 100) * w;
    } else {
        sc[6] = 0.0f;
    }
    float sum = 0.0f;
    for (int i = 0; i < 7; i++) {
        sum += sc[i];
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010D870);
#ifdef SKIP_ASM
extern "C" float func_0010D870(void* self, int a1, int a2, int a3)
{
    short s = *(short*)((char*)self + 0xE00);
    if (s == 0)
    {
        if (!a1)
            return 0.0f;
    }
    else if (s == 1)
    {
        if (!a2)
            return 0.0f;
    }
    else if (s == 2)
    {
        if (!a3)
            return 0.0f;
    }
    else if ((a1 == a2) != a3)
        return 0.0f;
    int n = 4;
    if (a1)
        n--;
    if (a2)
        n--;
    if (a3)
        n--;
    return n * 33.29999923706055f;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010D8F8);
#ifdef SKIP_ASM
struct sComputer_0010D8F8
{
    int a;
    int b;
    char pad[0x1C];
};

extern "C" int func_0010D8F8(void* self)
{
    sComputer_0010D8F8* p = *(sComputer_0010D8F8**)((char*)self + 0x18);
    for (int i = 0; i < 6; i++, p++)
    {
        if (p->a != 0 && p->b != 0)
            return i;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010D938);
#ifdef SKIP_ASM
extern "C" int func_0010DEB0(void* self);
float func_00113128(void* self);

extern "C" int func_0010D938(void* self)
{
    // PORT: func_0010DEB0 returns a pointer as int (unit declaration).
    int p = func_0010DEB0(self);
    if (p == 0)
        return 0;
    float d = func_00113128((void*)p) - (*(cRider**)((char*)self + 0x18))->unk_4D0;
    if (d < *(float*)((char*)(*(cRider**)((char*)self + 0x18)) + 0xDC))
        return 1;
    return 0;
}
#endif
//100%
INCLUDE_ASM("ai/computer", func_0010D990);
#ifdef SKIP_ASM
extern "C" int func_0010DEB0(void* self);
float func_00113128(void* self);

extern "C" int func_0010D990(void* self)
{
    // PORT: func_0010DEB0 returns a pointer as int (unit declaration).
    int p = func_0010DEB0(self);
    if (p == 0)
        return 0;
    float d = func_00113128((void*)p) - (*(cRider**)((char*)self + 0x18))->unk_4D0;
    if (*(float*)((char*)*(cRider**)((char*)self + 0x18) + 0xE0) < d)
        return 1;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010D9E8);
#ifdef SKIP_ASM
extern "C" int func_0010D9E8(void* self, int a1)
{
    void* p = *(void**)((char*)self + 0x18);
    int r = 0;
    if (*(int*)((char*)p + 0xf0) != 0) {
        r = *(int*)((char*)p + 0xf8) == a1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010DA10);
#ifdef SKIP_ASM
struct sRider_0010DA10 { sAiPair ent[6]; };
extern "C" int func_001298C8();
extern "C" int func_00311AE8(void*, int);
unsigned int AIrand();

extern "C" int func_0010DA10(char* self)
{
    float t = *(float*)(self + 0xF30);
    if (t < 0.0f)
    {
        *(float*)(self + 0xF30) = 0.0f;
        return 0;
    }
    if (0.0f < t)
    {
        *(float*)(self + 0xF30) = t - 0.01666666753590107f;
        return *(int*)(self + 0xF34);
    }
    if (func_001298C8() % 6 != 0)
        return 0;
    sAiRiderList* ai = D_004A28A8->game->race;
    int i;
    for (i = 0; i < ai->mCount; i++)
    {
        char* o = *(char**)(self + 0x18) + 0x6C0;
        sVEntry<int(void*)>* ve = &(*(sVEntry<int(void*)>**)o)[7];
        if (i == ve->fn(o + ve->delta))
            continue;
        char* o2 = ai->mRiders[i] + 0x6C0;
        sVEntry<int(void*)>* ve2 = &(*(sVEntry<int(void*)>**)o2)[8];
        if (ve2->fn(o2 + ve2->delta) == 0)
            continue;
        if (!((*(sRider_0010DA10**)(self + 0x18))->ent[i].dist < 200.0f))
            continue;
        if (func_00311AE8(*(void**)(ai->mRiders[i] + 0x784), 1) != 13)
            continue;
        unsigned int r = AIrand() % 100;
        int* pf = (int*)(self + 0xF34);
        *pf = (float)r < 25.0f;
        *(float*)(self + 0xF30) = 2.0f;
        return *(int*)(self + 0xF34);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010DBF0);
#ifdef SKIP_ASM
extern "C" int func_00155B50(void* self, int a, int b);
void* cBEAggressionInterface_getThis();

struct sEnt_0010DBF0 { int vis; int val; float dist; float angle; int d; int e; int f; int g; int h; };
struct sRider_0010DBF0 {
    sEnt_0010DBF0 ent[6];           // 0x0
    char padD8[0xF4 - 0xD8];
    int lastTaunt;                  // 0xF4
    char padF8[0x1B0 - 0xF8];
    t4Vector vel;              // 0x1B0
};

static inline int id_0010DBF0(char* self)
{
    char* o = *(char**)(self + 0x18) + 0x6C0;
    sVEntry<int(void*)>* ve = &(*(sVEntry<int(void*)>**)o)[7];
    return ve->fn(o + ve->delta);
}

static inline float atan2_0010DBF0(float y, float x, float pi)
{
    if (x == 0.0f) {
        if (y == 0.0f) {
            return y;
        }
        if (y >= 0.0f) {
            return 1.5707963705062866f;
        }
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f) {
            a += pi;
        } else {
            a -= pi;
        }
    }
    return a;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_0010DBF0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline float wrap_0010DBF0(float x)
{
    return x - ffloor_0010DBF0(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

static inline bool isAggr_0010DBF0(void* agg, int a, int b)
{
    return func_00155B50(agg, a, b) >= 3;
}

// Taunt check: finds a close rider beside us (30..150 degrees off our heading) that we're aggressive towards,
// at most every 120 frames; *side tells which side it is on.
extern "C" int func_0010DBF0(char* self, int* side)
{
    if (func_001298C8() % 6 != 0)
        return 0;
    sAiRiderList* ai = D_004A28A8->game->race;
    int i;
    for (i = 0; i < ai->mCount; i++)
    {
        float pi = 3.1415927410125732f;
        float lo = 0.5235988497734070f;
        float hi = 2.6179940700531006f;
        if (i == id_0010DBF0(self))
            continue;
        sRider_0010DBF0* r = *(sRider_0010DBF0**)(self + 0x18);
        if (!(r->ent[i].dist < 200.0f))
            continue;
        t4Vector a = r->vel;
        t4Vector b = r->vel;
        float ang = atan2_0010DBF0(a.y, b.x, pi);
        float d = wrap_0010DBF0(ang - (*(sRider_0010DBF0**)(self + 0x18))->ent[i].angle);
        float ad = __builtin_fabsf(d);
        if (!(lo < ad))
            continue;
        if (!(ad < hi))
            continue;
        void* agg = cBEAggressionInterface_getThis();
        if (!isAggr_0010DBF0(agg, id_0010DBF0(self), i))
            continue;
        if (!((*(sRider_0010DBF0**)(self + 0x18))->lastTaunt + 120 < func_001298C8()))
            continue;
        *side = 0.0f < d;
        (*(sRider_0010DBF0**)(self + 0x18))->lastTaunt = func_001298C8();
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010DEB0);
#ifdef SKIP_ASM

extern "C" int func_0010DEB0(void* self)
{
    int i = func_0010D8F8(self);
    if (i < 0)
        return 0;
    return (int)D_004A28A8->game->race->mRiders[i];
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010DEF0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
float func_00113128(void* self);
extern signed char D_00535C11[];

extern "C" float func_0010DEF0(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    // PORT: func_0010DEB0 returns a pointer as int (unit declaration).
    int p = func_0010DEB0(self);
    if (p == 0) return 1.0f;
    char* r = *(char**)((char*)self + 0x18);
    if (*(int*)(r + 0xE4) == 0) return 1.0f;
    if (D_00535C11[0] == 2) return 1.0f;
    if (*(float*)(r + 0x4D0) < 50000.0f) return 1.0f;
    float m;
    float d = func_00113128((void*)p) - *(float*)(*(char**)((char*)self + 0x18) + 0x4D0);
    char* r2 = *(char**)((char*)self + 0x18);
    float k = *(float*)(r2 + 0xDC);
    if (d < k && (*(int*)(r2 + 0xE4) == 2 || *(int*)(r2 + 0xE4) == 3))
    {
        m = ((d - k) / k + 1.0f) * 1.100000023841858f;
    }
    else
    {
        char* r3 = *(char**)((char*)self + 0x18);
        float k2 = *(float*)(r3 + 0xE0);
        if (k2 < d && (*(int*)(r3 + 0xE4) == 1 || *(int*)(r3 + 0xE4) == 3))
        {
            m = 1.0f / ((d - k2) / k2 + 1.0f);
            m *= 0.9090908765792847f;
        }
        else
            m = 1.0f;
    }
    return m;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E028);
#ifdef SKIP_ASM
extern "C" int func_001298C8();

extern "C" void func_0010E028(void* self, int mode, float t)
{
    int v;
    if (mode == 0)
    {
        v = -1;
        *(int*)((char*)self + 0x358) = 0;
    }
    else
    {
        int frames = (int)(t * 60.0f);
        v = func_001298C8() + frames;
        *(int*)((char*)self + 0x358) = mode;
    }
    *(int*)((char*)self + 0x354) = v;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E098);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void* func_0028B180();
extern "C" void func_00149690(void* iface, int rider, int b);
extern "C" void func_0029AB08(void* mgr, void* rider, float cur, float amt);
extern "C" void func_0010E028(void* self, int mode, float t);

// PORT: g++ `<?` (min) operator.
static inline float clamp_10E098(float v, float lo, float hi)
{
    if (v >= lo) return v <? hi;
    return lo;
}

extern "C" void func_0010E098(void* self, int mask, float amt)
{
    if (*(int*)((char*)self + 0x304) == 3)
        return;
    if (amt == 0.0f)
        return;
    if (amt > 0.0f)
    {
        func_00149690(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)((char*)self + 0x86C), *(int*)((char*)self + 0xB34));
        if ((mask & *(int*)((char*)self + 0xB28)) == 0)
            return;
    }
    func_0029AB08(func_0028B180(), self, *(float*)((char*)self + 0x2F8), amt);
    *(float*)((char*)self + 0x2F8) = clamp_10E098(*(float*)((char*)self + 0x2F8) + amt, 0.0f, 1.0f);
    if (*(float*)((char*)self + 0x2F8) == 1.0f && amt > 0.0f && *(int*)((char*)self + 0xB2C) != 0)
    {
        if (*(float*)((char*)self + 0x2F0) == 0.0f)
            func_0010E028(self, 5, 0.0f);
        if (*(int*)((char*)self + 0x2F4) <= 0)
            *(int*)((char*)self + 0x2F4) += 1;
        if (*(int*)((char*)self + 0x2F4) >= 1 && *(int*)((char*)self + 0x2F4) <= 9)
        {
            // PORT: g++ `>?` (max) operator.
            *(float*)((char*)self + 0x2F0) = *(float*)((char*)self + 0x2F0) >? 20.0f;
        }
    }
    else if (amt < 0.0f && *(int*)((char*)self + 0x2F4) < 10)
    {
        *(float*)((char*)self + 0x2F0) = 0.0f;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E228);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_00298488(void* snd, void* a, void* b);
extern "C" void func_002A0A30(void* snd, void* a, void* b, int c, int d);
void* cBEAggressionInterface_getThis();
extern "C" void func_00155BF0(void* agg, int a, int b, int c);

extern "C" void func_0010E228(void* a, void* b)
{
    func_00298488(func_0028B180(), a, b);
    func_002A0A30(func_0028B180(), b, a, 1, 0);
    void* agg = cBEAggressionInterface_getThis();
    char* ob = (char*)b + 0x6C0;
    sVEntry<int(void*)>* eb = &(*(sVEntry<int(void*)>**)ob)[7];
    int rb = eb->fn(ob + eb->delta);
    char* oa = (char*)a + 0x6C0;
    sVEntry<int(void*)>* ea = &(*(sVEntry<int(void*)>**)oa)[7];
    func_00155BF0(agg, rb, ea->fn(oa + ea->delta), 0);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E2E8);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_00298488(void* snd, void* a, void* b);
extern "C" void func_002A0A30(void* snd, void* a, void* b, int c, int d);
void* cBEAggressionInterface_getThis();
extern "C" void func_00155BF0(void* agg, int a, int b, int c);

extern "C" void func_0010E2E8(void* a, void* b)
{
    func_00298488(func_0028B180(), a, b);
    func_002A0A30(func_0028B180(), b, a, 1, 1);
    void* agg = cBEAggressionInterface_getThis();
    char* ob = (char*)b + 0x6C0;
    sVEntry<int(void*)>* eb = &(*(sVEntry<int(void*)>**)ob)[7];
    int rb = eb->fn(ob + eb->delta);
    char* oa = (char*)a + 0x6C0;
    sVEntry<int(void*)>* ea = &(*(sVEntry<int(void*)>**)oa)[7];
    func_00155BF0(agg, rb, ea->fn(oa + ea->delta), 1);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E3A8);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_00298138(void* snd, void* a, void* b);
extern "C" void func_002A0A30(void* snd, void* a, void* b, int c, int d);
void* cBEAggressionInterface_getThis();
extern "C" void func_00155BF0(void* agg, int a, int b, int c);

extern "C" void func_0010E3A8(void* a, void* b)
{
    func_00298138(func_0028B180(), b, a);
    func_002A0A30(func_0028B180(), b, a, 0, 0);
    void* agg = cBEAggressionInterface_getThis();
    char* ob = (char*)b + 0x6C0;
    sVEntry<int(void*)>* eb = &(*(sVEntry<int(void*)>**)ob)[7];
    int rb = eb->fn(ob + eb->delta);
    char* oa = (char*)a + 0x6C0;
    sVEntry<int(void*)>* ea = &(*(sVEntry<int(void*)>**)oa)[7];
    func_00155BF0(agg, rb, ea->fn(oa + ea->delta), 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/computer", func_0010E468);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_00298138(void* snd, void* a, void* b);
extern "C" void func_002A0A30(void* snd, void* a, void* b, int c, int d);
extern "C" void func_00298D00(void* snd, void* obj);
void* cBEAggressionInterface_getThis();
extern "C" void func_00155BF0(void* agg, int a, int b, int c);
extern "C" float func_00119400(char* self);
extern "C" void func_0010E098(void*, int, float);

extern "C" void func_0010E468(void* a, void* b)
{
    func_00298138(func_0028B180(), b, a);
    func_002A0A30(func_0028B180(), b, a, 0, 1);
    func_00298D00(func_0028B180(), b);
    void* agg = cBEAggressionInterface_getThis();
    char* ob = (char*)b + 0x6C0;
    sVEntry<int(void*)>* eb = &(*(sVEntry<int(void*)>**)ob)[7];
    int rb = eb->fn(ob + eb->delta);
    char* oa = (char*)a + 0x6C0;
    sVEntry<int(void*)>* ea = &(*(sVEntry<int(void*)>**)oa)[7];
    func_00155BF0(agg, rb, ea->fn(oa + ea->delta), 3);
    func_0010E098(b, 2, func_00119400(*(char**)((char*)b + 0x790)));
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E558);
#ifdef SKIP_ASM
extern int D_005308D0[];
extern signed char D_00535C12[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001194C0(void*, int);

extern "C" void func_0010E558(void* self, int* arg)
{
    *(int*)((char*)self + 0xE8) = *(int*)((char*)self + 0xEC);
    if (((D_005308D0[0] >> 9) & 1) == 0)
    {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        if (D_00535C12[0] == 1)
        {
            func_001194C0(*(void**)((char*)self + 0x790), *arg);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E5D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void* iface);
extern "C" void func_00125108(void* self);
extern "C" void func_00270AB0(void* a, int b, int c);
extern signed char D_00535BC8[];

static inline int state_0010E5D8() { return D_00535BC8[0x48]; }

extern "C" void func_0010E5D8(void* self, int* arg, int a2, int a3)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    char* s = D_004A28A8->fC0;
    int mode = *func_00144BC0(iface);
    int v = 0;
    if (state_0010E5D8() == 0 || state_0010E5D8() == 1 || state_0010E5D8() == 3 || state_0010E5D8() == 2
        || (state_0010E5D8() == 5 && *(int*)(s + 0x98) != 0)
        || (state_0010E5D8() == 6 && *(int*)(s + 0x98) != 0)
        || mode == 5 || mode == 6 || mode == 7 || mode == 8 || mode == 9
        || mode == 10 || mode == 11 || mode == 12 || mode == 13 || mode == 1
        || D_00535BC8[0x49] != 0)
        v = 1;
    if (*arg == 1 && v != 0)
    {
        int ok = *(float*)((char*)self + 0x470) >= 0.0f;
        if (!ok)
            func_00125108(self);
    }
    if (*arg == 11)
    {
        char* o = (char*)self + 0x6C0;
        sVEntry<int(void*)>* e = &(*(sVEntry<int(void*)>**)o)[7];
        void* tgt = D_004A28A8->game->f28;
        func_00270AB0(tgt, e->fn(o + e->delta), arg[1]);
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E770);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_0029CED8(void*, int, void*, float);
extern "C" void func_002A3B18(void*, void*, int);

extern "C" void func_0010E770(void* self, float amount)
{
    *(float*)((char*)self + 0x2E8) += amount;
    func_0029CED8(func_0028B180(), 0, self, 1.0f);
    func_002A3B18(func_0028B180(), self, 1);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E7D0);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_0029CED8(void*, int, void*, float);
extern "C" void func_002A3B18(void*, void*, int);

extern "C" void func_0010E7D0(void* self, float amount)
{
    *(float*)((char*)self + 0x2EC) += amount;
    func_0029CED8(func_0028B180(), 1, self, 1.0f);
    func_002A3B18(func_0028B180(), self, 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/computer", func_0010E830);
#ifdef SKIP_ASM
int func_0011FE98(void* self);
extern "C" float func_00119448(char* self, float value);
extern "C" void func_0010E098(void*, int, float);
extern "C" void* func_0028B180();
extern "C" void func_0029CED8(void*, int, void*, float);

extern "C" void func_0010E830(void* self, float value)
{
    if (func_0011FE98(self) == 1 || func_0011FE98(self) == 4)
    {
        func_0010E098(self, 4, func_00119448(*(char**)((char*)self + 0x790), value));
        func_0029CED8(func_0028B180(), 2, self, value);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/computer", func_0010E8B8);
#ifdef SKIP_ASM
extern "C" void func_0010E098(void*, int, float);
extern "C" float func_00119608(void*);
extern "C" void* func_0028B180();
extern "C" void func_0029CED8(void*, int, void*, float);

extern "C" void func_0010E8B8(void* self, int v)
{
    func_0010E098(self, 0x10, func_00119608(*(void**)((char*)self + 0x790)));
    func_0029CED8(func_0028B180(), 3, self, 1.0f);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010E910);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0010E028(void* self, int mode, float t);
void func_0010E098_fi(void*, float, int) __asm__("func_0010E098");
void func_00111AA0_impl(void* self, void* a, void* b, int c, float x) __asm__("func_00111AA0__FPv");
extern "C" float func_00119D40(void* self, int stance, int alternate, int style, int flag);
extern "C" int func_00149778(void* self, int rider, int value);
void func_00270870_10E910(void* self, int key, void* p) __asm__("func_00270870");
extern "C" void func_002948D0(void* mgr, void* rider, float v);
extern void* D_004A3500;

extern "C" void func_0010E910(char* self, int a1, int a2, int a3, char* evt, float t)
{
    char* m = *(char**)(self + 0x790);
    int c0 = *(int*)(m + 0x114);
    int b0 = *(int*)(m + 0x134);
    int d0 = *(int*)(m + 0x198);
    float r = func_00119D40(m, *(int*)(self + 0x320) != *(int*)(self + 0x324), a1, a2, a3);
    char* m1 = *(char**)(self + 0x790);
    int c1 = *(int*)(m1 + 0x114);
    int b1 = *(int*)(m1 + 0x134);
    int d1 = *(int*)(m1 + 0x198);
    func_00270870_10E910(D_004A28A8->game->f28, *(int*)(self + 0x86C), m1 + 0xFC);
    if (c0 < c1)
    {
        int v = *(int*)(self + 0x2F4);
        if (v < 10)
        {
            int d = c1 - c0;
            int lim = 10 - v;
            int nv = v + (d < lim ? d : lim);
            *(int*)(self + 0x2F4) = nv;
            if (nv == 10)
                *(float*)(self + 0x2F0) = 60.0f;
        }
    }
    func_00111AA0_impl(*(void**)(self + 0x77C), evt, evt + 0x10, *(int*)(evt + 0x4C), t);
    char* o = self + 0x6C0;
    sVEntry<int(void*)>* ve = &(*(sVEntry<int(void*)>**)o)[8];
    if (ve->fn(o + ve->delta))
    {
        if (b0 < b1)
            func_0010E028(self, 3, 0.0f);
        else if (c0 < c1)
            func_0010E028(self, 2, 0.0f);
        else if (func_00149778(cBE_getInterface_Fv(cBE_getBE(), 3), *(int*)(self + 0x86C), d1 - d0))
            func_0010E028(self, 1, 0.0f);
    }
    func_0010E098_fi(self, r, 1);
    if (0.0f < r)
        *(float*)(self + 0x2EC) = 0.0f;
    sVEntry<void(void*, float)>* vf = &(*(sVEntry<void(void*, float)>**)(self + 0x6C0))[17];
    vf->fn(self + vf->delta, t * 0.5f);
    func_002948D0(D_004A3500, self, r);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010EB30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" float func_00119B08(void* self, int flag);
extern "C" void func_00296310(void* mgr, void* rider);
extern "C" void func_0029F660(void* mgr, void* rider, int a, int b);
extern "C" void func_002961F0(void* mgr, void* rider, float v);
void func_0011FEC8_EB30(void* self, int v) __asm__("func_0011FEC8__FPv");
void func_0011FE78_EB30(void* self, int v) __asm__("func_0011FE78__FPv");
extern "C" void func_00116930(void* rider);
extern "C" void cRider_doLeanPoseAdjust(void* self, void* xf);
extern "C" void cRider_updateOrientationImplicit(void*);
// Animation state sample (rideranimbase func_00312660's result, 0x50 bytes).
struct sSeqState_EB30 {
    char pad[0x50];
} __attribute__((aligned(16)));
// Packed index word (handplantcontrol's sIdx): low byte and upper 24 bits both hold the index.
struct sIdx_EB30 { unsigned int id:8; int val:24; };
extern sIdx_EB30 D_004A4C08_EB30 __asm__("D_004A4C08");
extern "C" sSeqState_EB30 func_00312660(void* anim, int id, sIdx_EB30 h, float t);
extern "C" void func_0030ECD8(void* xf, void* model, void* buf, int a3);
extern "C" void cRiderAnimBase_changeOrientationOffset(void* self, void* xf);
extern "C" void cRiderAnimBase_changeHeadingOffset(void* self, float angle);
extern "C" int cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_0031BE50(float* s, float* c, float angle);

// 16-byte vector with inline constructors (ai/ai's sVec4).
struct sVec4_EB30 : t4Vector
{
    sVec4_EB30() {}
    sVec4_EB30(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

// A bone transform: position, rotation quaternion.
struct sXf_EB30
{
    sVec4_EB30 pos;
    sVec4_EB30 rot;
};

extern "C" void func_0011DFE0(void* self, sVec4_EB30 dir, float angle);
extern sVec4_EB30 D_004FF130_EB30 __asm__("D_004FF130");
extern sVec4_EB30 D_004FF160_EB30 __asm__("D_004FF160");

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sVec4_EB30 QuatMul_EB30(const sVec4_EB30& a, const sVec4_EB30& b)
{
    sVec4_EB30 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_EB30 Sub_EB30(const sVec4_EB30& a, const sVec4_EB30& b)
{
    sVec4_EB30 r;
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

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_EB30 Add_EB30(const sVec4_EB30& a, const sVec4_EB30& b)
{
    sVec4_EB30 r;
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

// PORT: PS2-only VU0 inline asm (v rotated by quaternion q).
static inline sVec4_EB30 Rot_EB30(const sVec4_EB30& q, const sVec4_EB30& v)
{
    sVec4_EB30 r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vsub.w    $vf8, $vf8, $vf8\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vopmsub.xyz $vf7, $vf6, $vf4\n"
        "vmulaw.xyz ACC, $vf5, $vf0w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf6, $vf4w\n"
        "vmaddaw.xyz ACC, $vf7, $vf0w\n"
        "vmaddw.xyz $vf8, $vf7, $vf0w\n"
        "sqc2      $vf8, %0\n"
        : "=m"(r)
        : "m"(q), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_EB30 Scale_EB30(const sVec4_EB30& v, float s)
{
    sVec4_EB30 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline sVec4_EB30 Conj_EB30(const sXf_EB30& p)
{
    sVec4_EB30 r;
    r.w = p.rot.w;
    r.x = p.rot.x;
    r.y = p.rot.y;
    r.z = p.rot.z;
    r.x = -r.x;
    r.y = -r.y;
    r.z = -r.z;
    return r;
}

static inline sXf_EB30 Invert_EB30(const sXf_EB30& a)
{
    sXf_EB30 r;
    r.rot = Conj_EB30(a);
    r.pos = Add_EB30(Scale_EB30(Rot_EB30(r.rot, Sub_EB30(a.pos, D_004FF130_EB30)), -1.0f), D_004FF130_EB30);
    return r;
}

static inline sXf_EB30 Combine_EB30(const sXf_EB30& a, const sXf_EB30& b)
{
    sXf_EB30 r;
    r.rot = QuatMul_EB30(a.rot, b.rot);
    r.pos = Add_EB30(Rot_EB30(a.rot, Sub_EB30(b.pos, D_004FF130_EB30)), a.pos);
    return r;
}

static inline sVec4_EB30 AxisAngle_EB30(const sVec4_EB30& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sVec4_EB30(s * axis.x, s * axis.y, s * axis.z, c);
}

static inline void SetHeading_EB30(char* a, float angle)
{
    *(sVec4_EB30*)(a + 0x30) = D_004FF130_EB30;
    *(sVec4_EB30*)(a + 0x40) = AxisAngle_EB30(D_004FF160_EB30, -angle);
}

extern "C" void func_0010EB30(char* self, int a1, int a2, int a3, char* evt)
{
    sVEntry<void(void*, float)>* vf = &(*(sVEntry<void(void*, float)>**)(self + 0x6C0))[17];
    vf->fn(self + vf->delta, *(float*)(evt + 0x30) * 5.0f);
    float r = func_00119B08(*(void**)(self + 0x790), a2);
    func_0010E098(self, 1, r);
    func_00296310(func_0028B180(), self);
    func_0029F660(func_0028B180(), self, 0, 0);
    func_002961F0(func_0028B180(), self, r);
    func_00111AA0_impl(*(void**)(self + 0x77C), evt, evt + 0x20, a3, *(float*)(evt + 0x30));
    func_0011FEC8_EB30(self, 0xD);
    if (*(int*)(self + 0x328) == 3) {
        func_0011DFE0(self, *(sVec4_EB30*)(self + 0x1C0), 1.5707964f);
        cRiderAnimBase_changeHeadingOffset(*(void**)(self + 0x784), 1.5707964f);
        SetHeading_EB30(*(char**)(self + 0x784), 0.0f);
    } else if (*(int*)(self + 0x328) == 4) {
        func_0011DFE0(self, *(sVec4_EB30*)(self + 0x1C0), -1.5707964f);
        cRiderAnimBase_changeHeadingOffset(*(void**)(self + 0x784), -1.5707964f);
        SetHeading_EB30(*(char**)(self + 0x784), 0.0f);
    }
    *(int*)(self + 0x328) = 0;
    func_00116930(self);
    cRider_doLeanPoseAdjust(self, self + 0x110);
    cRider_updateOrientationImplicit(self);
    *(int*)(self + 0x1F8) = 0;
    *(int*)(self + 0x1F0) = 0;
    *(int*)(self + 0x1F4) = 0;
    *(int*)(self + 0x210) = 0;
    *(int*)(self + 0x208) = 0;
    *(int*)(self + 0x20C) = 0;
    *(int*)(self + 0x258) = 0;
    *(int*)(self + 0x250) = 0;
    *(int*)(self + 0x254) = 0;
    *(int*)(self + 0x330) = 0;
    sSeqState_EB30 st = func_00312660(*(void**)(self + 0x784), a1, D_004A4C08_EB30, *(float*)(self + 0x1F8));
    sXf_EB30 a;
    func_0030ECD8(&a, *(void**)(self + 0x780), &st, 0);
    char* trk = *(char**)(self + 0x780);
    sVec4_EB30* n = (sVec4_EB30*)((*(int*)(self + 0x89C) << 4) + *(int*)(trk + 0x24));
    sXf_EB30 node;
    node.pos = sVec4_EB30(n->x * *(float*)(trk + 0x140), n->y * *(float*)(trk + 0x144),
                          n->z * *(float*)(trk + 0x148), n->w * *(float*)(trk + 0x14C));
    node.rot = *(sVec4_EB30*)(*(char**)(trk + 0x28) + (*(int*)(self + 0x89C) << 4));
    sXf_EB30 y = Combine_EB30(node, Invert_EB30(a));
    *(sXf_EB30*)(self + 0x110) = Combine_EB30(*(sXf_EB30*)(self + 0x110), y);
    cRider_updateOrientationImplicit(self);
    sXf_EB30 w = Invert_EB30(y);
    cRiderAnimBase_changeOrientationOffset(*(void**)(self + 0x784), &w);
    cRiderAnimBase_play(*(void**)(self + 0x784), a1, 0, -1.0f);
    func_0011FEC8_EB30(self, 8);
    func_0011FE78_EB30(self, 2);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010F1C0);
#ifdef SKIP_ASM
extern "C" void func_0010E098(void*, int, float);
extern "C" void func_0010E8B8(void* self, int v);
extern "C" int func_00116120(void* rider, int a, int b);

static inline void computerV_0010F1C0(char* self, int i)
{
    char* obj = self + 0x6C0;
    sVEntry<int(void*)>* vt = *(sVEntry<int(void*)>**)obj;
    vt[i].fn(obj + vt[i].delta);
}

extern "C" void func_0010F1C0(char* self, int kind, float amt)
{
    switch (kind) {
    case 0:
        break;
    case 1:
        computerV_0010F1C0(self, 13);
        break;
    case 2:
        computerV_0010F1C0(self, 14);
        break;
    case 3:
        computerV_0010F1C0(self, 15);
        break;
    case 4:
        func_0010E098(self, 8, amt);
        break;
    case 6:
        func_0010E8B8(self, (int)amt);
        break;
    case 5:
        func_00116120(self, 0, 4);
        break;
    case 7:
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/computer", func_0010F280);
#ifdef SKIP_ASM
extern "C" float func_00119BB0(void*);
extern "C" void func_0010E098(void*, int, float);

extern "C" void func_0010F280(void* self, int flag)
{
    func_0010E098(self, 1, func_00119BB0(*(void**)((char*)self + 0x790)));
}
#endif

extern "C" void* func_0011A0E0(void*);

//100%
INCLUDE_ASM("ai/computer", func_0010F2B8__FPv);
#ifdef SKIP_ASM
void* func_0010F2B8(void* self)
{
    return func_0011A0E0(*(void**)((char*)self + 0x790));
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010F2D8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0011A110(void*, int);
extern "C" void func_00159B08(void*, int, int);

extern "C" void func_0010F2D8(void* self, int a, int b)
{
    func_0011A110(*(void**)((char*)self + 0x790), b);
    func_00159B08(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(int*)((char*)self + 0x86C), a);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010F338);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00119EF8(void*, int);
extern "C" void func_001599A0(void*, int, int);

extern "C" void func_0010F338(void* self, int a, int a2)
{
    func_00119EF8(*(void**)((char*)self + 0x790), 3);
    func_001599A0(cBE_getInterface_Fv(cBE_getBE(), 0xD), *(int*)((char*)self + 0x86C), a);
}
#endif

extern "C" void* func_0010F3B8(void* self);

//100%
INCLUDE_ASM("ai/computer", func_0010F398__FPv);
#ifdef SKIP_ASM
void* func_0010F398(void* self)
{
    return func_0010F3B8(self);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010F3B8);
#ifdef SKIP_ASM
struct sRider_0010F3B8 {
    sAiPair ent[6];
    char pad[0x10];
    int fE8;
    char pad2[0x4D8 - 0xEC];
    float f4D8;
    void setTarget(int t) { fE8 = t; }
};
struct sAI_0010F3B8 { char pad[0x28]; sRider_0010F3B8* riders[20]; int count; };
extern "C" int func_0011D640(void*);
float func_00113128(void* self);

// PORT: the unit declares this as returning void*; it returns nothing.
extern "C" void func_0010F3B8_impl(sAI_0010F3B8* self) __asm__("func_0010F3B8");
extern "C" void func_0010F3B8_impl(sAI_0010F3B8* self)
{
    int i;
    for (i = 0; i < self->count; i++)
    {
        int j;
        for (j = 0; j < 6; j++)
        {
            sAiPair* e = &self->riders[i]->ent[j];
            int v = 0;
            if (i != j && j < self->count)
                v = func_0011D640(self->riders[i]) != 0;
            e->vis = v;
            if (j < self->count)
            {
                char* o = (char*)self->riders[j] + 0x6C0;
                sVEntry<int(void*)>* ve = &(*(sVEntry<int(void*)>**)o)[8];
                self->riders[i]->ent[j].val = ve->fn(o + ve->delta);
            }
            self->riders[i]->ent[j].dist = 10000000000.0f;
            self->riders[i]->ent[j].c = 0;
            self->riders[i]->ent[j].d = 0;
            self->riders[i]->ent[j].e = 0;
            self->riders[i]->ent[j].f = 0;
            self->riders[i]->ent[j].g = 0;
            self->riders[i]->ent[j].h = 0;
        }
        self->riders[i]->f4D8 = func_00113128(self->riders[i]);
        self->riders[i]->setTarget(-1);
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010F560);
#ifdef SKIP_ASM
void* cBEAggressionInterface_getThis();
extern "C" int func_00155B50(void* agg, int a, int b);
extern "C" float func_0031C228(float x);
extern "C" void func_0010F878(sAiRiderList* self);
extern "C" void func_0010F998(void* self);

struct sRiderInfo_0010F560 {
    int active;     // 0x0
    int f4;         // 0x4
    float dist;     // 0x8
    float angle;    // 0xC
    char pad10[0xC];
    int aggressive; // 0x1C
    int f20;        // 0x20
};

struct sRider_0010F560 {
    sRiderInfo_0010F560 info[6];  // 0x0
    char padD8[0xDC - 0xD8];
    float minDist;                // 0xDC
    float maxDist;                // 0xE0

    t4Vector* getPos()
    {
        char* o = (char*)this + 0x6C0;
        sVEntry<t4Vector*(void*)>* e = &(*(sVEntry<t4Vector*(void*)>**)o)[5];
        return e->fn(o + e->delta);
    }
};

struct sComputer_0010F560 {
    char pad0[0x8];
    int frame;                       // 0x8
    char padC[0x28 - 0xC];
    sRider_0010F560* riders[0x14];   // 0x28
    int count;                       // 0x78
    char pad7C[0x84 - 0x7C];
    int skip;                        // 0x84
};

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector sub_0010F560(const t4Vector& a, const t4Vector& b)
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

static inline float atan2_0010F560(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f) {
            return y;
        }
        if (y >= 0.0f) {
            return 1.5707963705062866f;
        }
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f) {
            a += 3.1415927410125732f;
        } else {
            a -= 3.1415927410125732f;
        }
    }
    return a;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_0010F560(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline float wrap_0010F560(float x)
{
    return x - ffloor_0010F560(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

extern "C" void func_0010F560(sComputer_0010F560* self)
{
    if (self->frame % 6 != 0) {
        return;
    }
    func_0010F998(self);
    int n = self->count - self->skip;
    if (n < 2) {
        return;
    }
    for (int i = 0; i < n; i++) {
        self->riders[i]->minDist = -50000.0f;
        self->riders[i]->maxDist = 50000.0f;
        for (int j = i + 1; j < n; j++) {
            if (self->riders[i]->info[j].active == 0) {
                continue;
            }
            t4Vector d = sub_0010F560(*self->riders[i]->getPos(), *self->riders[j]->getPos());
            float dist;
            float dx = d.x;
            float dy = d.y;
            float sq = dx * dx + dy * dy;
            // PORT: sqrt.s (sqrtf without errno check)
            __asm__("sqrt.s %0, %1" : "=f"(dist) : "f"(sq));
            float ang = atan2_0010F560(dy, dx);
            self->riders[i]->info[j].dist = dist;
            self->riders[j]->info[i].dist = dist;
            self->riders[i]->info[j].angle = wrap_0010F560(ang + 3.1415927410125732f);
            self->riders[j]->info[i].angle = ang;
            if (func_00155B50(cBEAggressionInterface_getThis(), i, j) >= 2) {
                self->riders[i]->info[j].aggressive = 1;
            } else {
                self->riders[i]->info[j].aggressive = 0;
            }
        }
    }
    func_0010F878((sAiRiderList*)self);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010F878);
#ifdef SKIP_ASM
void* cBEAggressionInterface_getThis();
extern "C" int func_00155B50(void* self, int a, int b);

extern "C" void func_0010F878(sAiRiderList* self)
{
    if (self->f80 <= 0) return;
    for (int i = 0; i < self->mCount; i++)
    {
        *(int*)(self->mRiders[i] + 0xF0) = 0;
        *(int*)(self->mRiders[i] + 0xF8) = -1;
        for (int j = 0; j < self->mCount; j++)
        {
            if (i == j) continue;
            int a = func_00155B50(cBEAggressionInterface_getThis(), i, j);
            if (a == 4)
            {
                *(int*)(self->mRiders[i] + 0xF0) = 1;
                *(int*)(self->mRiders[i] + 0xF8) = j;
            }
            *(int*)(self->mRiders[i] + 0xFC) = a;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010F998);
#ifdef SKIP_ASM
float func_00113128(void* self);
extern "C" int func_0012A180(sAiRiderList* self);
extern "C" void func_003E6328(int n, int* keys, int* order);
extern "C" void* func_0028B180();
extern "C" void func_00299E28(void* a, cRider* r, cRider* next, cRider* prev, int oldRank, int newRank);

extern "C" void func_0010F998(void* self_)
{
    sAiRiderList* self = (sAiRiderList*)self_;
    int order[8];
    int keys[8];
    if (self->mMode == 0) return;
    if (func_0012A180(self) == 0) return;
    for (int i = 0; i < self->mCount; i++)
    {
        order[i] = i;
        cRider* r = (cRider*)self->mRiders[i];
        switch (self->mMode)
        {
        case 1:
            if (r->mIsActor)
            {
                keys[i] = 0xFFFF;
            }
            else
            {
                // Two arms: retail (and the July 2003 prototype) still compute this flag
                // (li 1; bc1t; li 0) although nothing reads it - the branch on it vanished when
                // jump2 cross-jumped the identical arms after reload.
                bool late = r->mFinishTime >= 10.0f;
                if (late)
                    keys[i] = -(int)(func_00113128(r) + (float)(r->unk_0EC * 20));
                else
                    keys[i] = -(int)(func_00113128(r) + (float)(r->unk_0EC * 20));
            }
            break;
        case 2:
            if (r->mIsActor)
                keys[i] = -0xFFFF;
            else
                keys[i] = *(int*)((char*)r->mMetrix + 0x198);
            break;
        }
    }
    int count = self->mCount;
    func_003E6328(count, keys, order);
    for (int i = 0; i < self->mCount; i++)
    {
        if (((cRider*)self->mRiders[order[i]])->unk_0EC != i)
        {
            cRider* next = 0;
            cRider* prev = 0;
            if (i > 0)
                prev = (cRider*)self->mRiders[order[i - 1]];
            if (i < self->mCount - 1)
                next = (cRider*)self->mRiders[order[i + 1]];
            func_00299E28(func_0028B180(), (cRider*)self->mRiders[order[i]], next, prev,
                          ((cRider*)self->mRiders[order[i]])->unk_0EC, i);
        }
        ((cRider*)self->mRiders[order[i]])->unk_0EC = i;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010FBF0);
#ifdef SKIP_ASM
extern "C" int func_0010FBF0(sAiRiderList* self, int team)
{
    int n = 0;
    for (int i = 0; i < self->mCount; i++)
    {
        if (*(int*)(self->mRiders[i] + 0xAB8) == team)
            n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010FC30);
#ifdef SKIP_ASM
extern "C" int func_0010FC30(sAiRiderList* self, int team)
{
    int n = 0;
    for (int i = 0; i < self->mCount; i++)
    {
        char* obj = self->mRiders[i] + 0x6C0;
        sVEntry<int(void*)>* e = &(*(sVEntry<int(void*)>**)obj)[9];
        if (e->fn(obj + e->delta))
        {
            if (*(int*)(self->mRiders[i] + 0xAB8) == team)
                n++;
        }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_0010FCD8);
#ifdef SKIP_ASM
// The computer rider's handler: a composite of 31 rider behaviour parts that each derive virtually from
// cRider (the same model as seg/seg_1218, which destroys it). Constructing it is compiler-generated g++ 2.95
// code: the cRider base and the vbase pointers when in charge, every part in order (the out-of-line part
// constructors are called, the others are inlined), then the vtable fix-ups for the virtual base (stack
// copies of the cRider-in-part vtables with the this-delta adjusted) and the handler's own fields.
class cRiderVbA0_cmp {
public:
    virtual ~cRiderVbA0_cmp();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_cmp : public cRiderVbA0_cmp { public: char padA[0xC]; };
class cRiderVbB0_cmp { public: virtual void b01(); };
class cRiderVbB_cmp : public cRiderVbB0_cmp { public: char padB[0x14]; };
class cRiderVbC0_cmp {
public:
    virtual ~cRiderVbC0_cmp();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_cmp : public cRiderVbC0_cmp { public: char padC[0x10]; };
class cRiderVbBC_cmp : public cRiderVbB_cmp, public cRiderVbC_cmp { public: };
class cRiderVbPad_cmp { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_cmp : public cRiderVbPad_cmp, public cRiderVbA_cmp, public cRiderVbBC_cmp {
public:
    char padD[0x77C - 0x6FC];
    void* mRiderHandler;            // 0x77C
    cRiderVb_cmp();                 // cRider_cRider
    virtual ~cRiderVb_cmp();
};

extern t4Vector D_004FF160;

struct cCompHead00_cmp { char pad[0x18]; };
class cCompPart00_cmp : public cCompHead00_cmp, virtual public cRiderVb_cmp {
public:
    char body[0x4];
    cCompPart00_cmp();              // func_0013C650
};
struct cCompHead01_cmp { char pad[0x4]; };
class cCompPart01_cmp : public cCompHead01_cmp, virtual public cRiderVb_cmp { public: char body[0x8]; };
struct cCompHead02_cmp { char pad[0x40]; };
class cCompPart02_cmp : public cCompHead02_cmp, virtual public cRiderVb_cmp {
public:
    char body[0x2C];
    cCompPart02_cmp();              // func_00136980
    virtual ~cCompPart02_cmp();
};
class cCompPart03_cmp : virtual public cRiderVb_cmp { public: char body[0xC]; };
// A handle at 0x24 of part 4's leading base: invalid (~0) when constructed, and reset to that by the part.
struct cCompHandle_cmp {
    unsigned int id;
    cCompHandle_cmp() { id = 0xFFFFFFFF; }
};
struct cCompHead04_cmp {
    t4Vector v;                     // 0x00
    char pad10[0x8];
    int f18;                        // 0x18
    char pad1C[0x8];
    cCompHandle_cmp h;              // 0x24
    char pad28[0x28];
};
class cCompPart04_cmp : public cCompHead04_cmp, virtual public cRiderVb_cmp {
public:
    char body[0xC];
    cCompPart04_cmp()
    {
        h = cCompHandle_cmp();
        f18 = 0;
        v = D_004FF160;
    }
};
struct cCompHead05_cmp { char pad[0xA0]; };
class cCompPart05_cmp : public cCompHead05_cmp, virtual public cRiderVb_cmp {
public:
    char body[0xC];
    cCompPart05_cmp();              // func_00141480
};
class cCompPart06_cmp : virtual public cRiderVb_cmp { public: char body[0xC]; };
struct cCompHead07_cmp { char pad[0x14]; };
class cCompPart07_cmp : public cCompHead07_cmp, virtual public cRiderVb_cmp { public: char body[0x8]; };
class cCompPart08_cmp : virtual public cRiderVb_cmp { public: char body[0xC]; };
class cCompPart09_cmp : virtual public cRiderVb_cmp { public: char body[0xC]; };
struct cCompHead10_cmp { char pad[0x14]; };
class cCompPart10_cmp : public cCompHead10_cmp, virtual public cRiderVb_cmp { public: char body[0x8]; };
struct cCompHead11_cmp { char pad[0x58]; };
class cCompPart11_cmp : public cCompHead11_cmp, virtual public cRiderVb_cmp { public: char body[0x4]; };
struct cCompHead12_cmp { int f00; char pad[0x10]; };
class cCompPart12_cmp : public cCompHead12_cmp, virtual public cRiderVb_cmp {
public:
    char body[0x8];
    cCompPart12_cmp() { f00 = 0; }
};
struct cCompHead13_cmp { char pad[0x8]; };
class cCompPart13_cmp : public cCompHead13_cmp, virtual public cRiderVb_cmp { public: char body[0x4]; };
struct cCompHead14_cmp { char pad[0x80]; };
class cCompPart14_cmp : public cCompHead14_cmp, virtual public cRiderVb_cmp {
public:
    char body[0xC];
    cCompPart14_cmp();              // func_00142388
};
struct cCompHead15_cmp { char pad[0x8]; };
class cCompPart15_cmp : public cCompHead15_cmp, virtual public cRiderVb_cmp { public: char body[0x4]; };
struct cCompHead16_cmp { char pad[0x4]; };
class cCompPart16_cmp : public cCompHead16_cmp, virtual public cRiderVb_cmp { public: char body[0x8]; };
struct cCompHead17_cmp { char pad[0x14]; };
class cCompPart17_cmp : public cCompHead17_cmp, virtual public cRiderVb_cmp { public: char body[0x8]; };
struct cCompHead18_cmp { char pad[0x8]; };
class cCompPart18_cmp : public cCompHead18_cmp, virtual public cRiderVb_cmp { public: char body[0x4]; };
class cCompPart19_cmp : virtual public cRiderVb_cmp { public: char body[0xC]; };
class cCompPart20_cmp : virtual public cRiderVb_cmp {
public:
    char body[0xBC];
    cCompPart20_cmp();              // cBoardWakeFX_cBoardWakeFX
    virtual ~cCompPart20_cmp();
};
class cCompPart21_cmp : virtual public cRiderVb_cmp {
public:
    char body[0xAC];
    cCompPart21_cmp();              // cBoardSparkFX_cBoardSparkFX
    virtual ~cCompPart21_cmp();
};
class cCompPart22_cmp : virtual public cRiderVb_cmp {
public:
    char body[0xEC];
    cCompPart22_cmp();              // cBoardTrailFX_initialize
    virtual ~cCompPart22_cmp();
};
class cCompPart23_cmp : virtual public cRiderVb_cmp {
public:
    char body[0x3AC];
    cCompPart23_cmp();              // func_002E6320
    virtual ~cCompPart23_cmp();
};
class cCompPart24_cmp : virtual public cRiderVb_cmp {
public:
    char body[0x10C];
    cCompPart24_cmp();              // func_002EAAE0
    virtual ~cCompPart24_cmp();
};
class cCompPart25_cmp : virtual public cRiderVb_cmp {
public:
    char body[0x1C];
    cCompPart25_cmp();              // func_002EF3B0
    virtual ~cCompPart25_cmp();
};
class cCompPart26_cmp : virtual public cRiderVb_cmp {
public:
    char body[0xC];
    cCompPart26_cmp();              // cAngerFX_cAngerFX
    virtual ~cCompPart26_cmp();
};
class cCompPart27_cmp : virtual public cRiderVb_cmp {
public:
    char body[0x3C];
    cCompPart27_cmp();              // func_002E3680
    virtual ~cCompPart27_cmp();
};
class cCompPart28_cmp : virtual public cRiderVb_cmp {
public:
    char body[0x12C];
    cCompPart28_cmp();              // func_002DE4A8
    virtual ~cCompPart28_cmp();
};
class cCompPart29_cmp : virtual public cRiderVb_cmp {
public:
    char body[0xAC];
    cCompPart29_cmp();              // func_002F0E88
    virtual ~cCompPart29_cmp();
};
class cCompPart30_cmp : virtual public cRiderVb_cmp {
public:
    cCompPart30_cmp();              // func_002F6238
    virtual ~cCompPart30_cmp();
};
/// The handler's two five-entry tables; their element constructor does nothing (the two empty array-construction
// loops before the fix-ups: retail deleted the first and kept the second, see tools/patch_vecmark.py).
struct cCompSlot_cmp { cCompSlot_cmp() {} int w[4]; };
struct cCompSlots_cmp { cCompSlot_cmp slotA[5]; cCompSlot_cmp slotB[5]; };
class cComp_cmp : public cCompPart00_cmp, public cCompPart01_cmp, public cCompPart02_cmp, public cCompPart03_cmp, public cCompPart04_cmp, public cCompPart05_cmp, public cCompPart06_cmp, public cCompPart07_cmp, public cCompPart08_cmp, public cCompPart09_cmp, public cCompPart10_cmp, public cCompPart11_cmp, public cCompPart12_cmp, public cCompPart13_cmp, public cCompPart14_cmp, public cCompPart15_cmp, public cCompPart16_cmp, public cCompPart17_cmp, public cCompPart18_cmp, public cCompPart19_cmp, public cCompPart20_cmp, public cCompPart21_cmp, public cCompPart22_cmp, public cCompPart23_cmp, public cCompPart24_cmp, public cCompPart25_cmp, public cCompPart26_cmp, public cCompPart27_cmp, public cCompPart28_cmp, public cCompPart29_cmp, public cCompPart30_cmp, public cCompSlots_cmp {
public:
    char tail[0x10];
    int fDE0;
    int fDE4;
    cComp_cmp();
    virtual void v01() = 0;
    virtual void v02();
    virtual void v03();
};

cComp_cmp::cComp_cmp()
{
    mRiderHandler = this;
    fDE0 = 6;
    fDE4 = 14;
}
// PORT: the compiler names these constructors __<len><Class>[i]; map them to the address-derived names.
__asm__(".globl func_0010FCD8\n.type func_0010FCD8,@function\nfunc_0010FCD8 = __9cComp_cmpi\n.size func_0010FCD8,0x15DC\n");
__asm__("__12cRiderVb_cmp = cRider_cRider\n"
        "__15cCompPart00_cmpi = func_0013C650\n"
        "__15cCompPart02_cmpi = func_00136980\n"
        "__15cCompPart05_cmpi = func_00141480\n"
        "__15cCompPart14_cmpi = func_00142388\n"
        "__15cCompPart20_cmpi = cBoardWakeFX_cBoardWakeFX\n"
        "__15cCompPart21_cmpi = cBoardSparkFX_cBoardSparkFX\n"
        "__15cCompPart22_cmpi = cBoardTrailFX_initialize\n"
        "__15cCompPart23_cmpi = func_002E6320\n"
        "__15cCompPart24_cmpi = func_002EAAE0\n"
        "__15cCompPart25_cmpi = func_002EF3B0\n"
        "__15cCompPart26_cmpi = cAngerFX_cAngerFX\n"
        "__15cCompPart27_cmpi = func_002E3680\n"
        "__15cCompPart28_cmpi = func_002DE4A8\n"
        "__15cCompPart29_cmpi = func_002F0E88\n"
        "__15cCompPart30_cmpi = func_002F6238\n");
#endif

//100%
INCLUDE_ASM("ai/computer", func_001112B8);
#ifdef SKIP_ASM
extern "C" void func_001112F8(void* self, int a1);
extern "C" void func_00111380(void*, int);

extern "C" void func_001112B8(void* self, int v)
{
    func_001112F8(self, v);
    int old = *(int*)((char*)self + 0xDE0);
    *(int*)((char*)self + 0xDE0) = v;
    func_00111380(self, old);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_001112F8);
#ifdef SKIP_ASM
// Motion-state dispatch: the second argument is passed through to the handler.
extern "C" void func_0013F410(void* self);
void func_00139A18_a1(void* motion, int a1) __asm__("func_00139A18__FPv");
void func_00136F28_a1(void* motion, int a1) __asm__("func_00136F28__FPv");
extern "C" void func_0013C5A0(void* motion);
extern "C" void func_00139178(void* motion);
extern "C" void func_0013C7A8(void* self);
extern "C" void func_001399E0(void* motion, int a1);
extern "C" void cWipeoutMotion_gainFocus(void* motion, int a1);
extern "C" void func_0013AD20(void* motion);
extern "C" void cHandplantMotion_gainFocus(void* motion);

extern "C" void func_001112F8(void* self, int a1)
{
    switch (*(int*)((char*)self + 0xDE0)) {
    case 0:
        func_0013F410(self);
        break;
    case 1:
        func_00139A18_a1((char*)self + 0x20, a1);
        break;
    case 2:
        func_00136F28_a1((char*)self + 0x30, a1);
        break;
    case 4:
        func_0013C5A0((char*)self + 0xB0);
        break;
    case 5:
        func_00139178((char*)self + 0x110);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111380);
#ifdef SKIP_ASM
extern "C" void func_0013F410(void* self);
void func_00139A18_a1(void* motion, int a1) __asm__("func_00139A18__FPv");
void func_00136F28_a1(void* motion, int a1) __asm__("func_00136F28__FPv");
extern "C" void func_0013C5A0(void* motion);
extern "C" void func_00139178(void* motion);
extern "C" void func_0013C7A8(void* self);
extern "C" void func_001399E0(void* motion, int a1);
extern "C" void cWipeoutMotion_gainFocus(void* motion, int a1);
extern "C" void func_0013AD20(void* motion);
extern "C" void cHandplantMotion_gainFocus(void* motion);

extern "C" void func_00111380(void* self, int a1)
{
    switch (*(int*)((char*)self + 0xDE0)) {
    case 0:
        func_0013C7A8(self);
        break;
    case 1:
        func_001399E0((char*)self + 0x20, a1);
        break;
    case 2:
        cWipeoutMotion_gainFocus((char*)self + 0x30, a1);
        break;
    case 4:
        func_0013AD20((char*)self + 0xB0);
        break;
    case 5:
        cHandplantMotion_gainFocus((char*)self + 0x110);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111408);
#ifdef SKIP_ASM
extern "C" void func_0013D818(void* self);
extern "C" void func_00139A20(void* motion);
extern "C" void func_00136E98(void* motion);
extern "C" void func_00136958(void* motion);
extern "C" void func_0013AF28(void* motion);
extern "C" void func_001391A8(void* motion);

extern "C" void func_00111408(void* self)
{
    switch (*(int*)((char*)self + 0xDE0)) {
    case 0:
        func_0013D818(self);
        break;
    case 1:
        func_00139A20((char*)self + 0x20);
        break;
    case 2:
        func_00136E98((char*)self + 0x30);
        break;
    case 3:
        func_00136958((char*)self + 0xA0);
        break;
    case 4:
        func_0013AF28((char*)self + 0xB0);
        break;
    case 5:
        func_001391A8((char*)self + 0x110);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_001114A0);
#ifdef SKIP_ASM
extern "C" void func_0013F178(void* self);
extern "C" void func_00139C88(void* motion);
extern "C" void func_00136EE0(void* motion);
void func_00136978(void* motion);
extern "C" void func_0013BFA8(void* motion);
void* func_00139528(void* motion);

extern "C" void func_001114A0(void* self)
{
    switch (*(int*)((char*)self + 0xDE0)) {
    case 0:
        func_0013F178(self);
        break;
    case 1:
        func_00139C88((char*)self + 0x20);
        break;
    case 2:
        func_00136EE0((char*)self + 0x30);
        break;
    case 3:
        func_00136978((char*)self + 0xA0);
        break;
    case 4:
        func_0013BFA8((char*)self + 0xB0);
        break;
    case 5:
        func_00139528((char*)self + 0x110);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111538);
#ifdef SKIP_ASM
extern "C" void func_00111578(void* self, int a1);
extern "C" void func_00111630(void*, int);

extern "C" void func_00111538(void* self, int v)
{
    func_00111578(self, v);
    int old = *(int*)((char*)self + 0xDE4);
    *(int*)((char*)self + 0xDE4) = v;
    func_00111630(self, old);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111578);
#ifdef SKIP_ASM
extern "C" void func_00131C30(void* m, int a1);
extern "C" void func_0012FE98(void* m);
void func_0012E9B0_a1(void* m, int a1) __asm__("func_0012E9B0__FPv");
extern "C" void func_0012FB68(void* m, int a1);
extern "C" void func_00134CB0(void* m);
extern "C" void func_00132048(void* m);
extern "C" void func_0012E690(void* m);
extern "C" void func_00132F98(void* m);

// Controller-state dispatch: the second argument is passed through to the handler.
extern "C" void func_00111578(void* self, int a1)
{
    switch (*(int*)((char*)self + 0xDE4)) {
    case 0:
        func_00131C30((char*)self + 0x1C0, a1);
        break;
    case 1:
        func_0012FE98((char*)self + 0x1D0);
        break;
    case 2:
        func_0012E9B0_a1((char*)self + 0x1F0, a1);
        break;
    case 4:
        func_0012FB68((char*)self + 0x210, a1);
        break;
    case 5:
        func_00134CB0((char*)self + 0x230);
        break;
    case 7:
        func_00132048((char*)self + 0x2B0);
        break;
    case 8:
        func_0012E690((char*)self + 0x2C0);
        break;
    case 11:
        func_00132F98((char*)self + 0x370);
        break;
    case 3: case 6: case 9: case 10: case 12: case 13:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111630);
#ifdef SKIP_ASM
void func_00131608(void* p);
void func_0012FC60(void* p);
extern "C" void func_0012E980(void* p);
extern "C" void func_0012F620(void* p);
extern "C" void func_00133128(void* p);
extern "C" void func_0012BE20(void* p);
extern "C" void func_00131D08(void* p);
extern "C" void func_0012CA30(void* p);
extern "C" void func_0012F230(void* p);
extern "C" void func_0012C5C8(void* p);
extern "C" void func_001328B0(void* p);
extern "C" void func_00136268(void* p, int a1);
// Forwards to the handler for the AI's current state.
extern "C" void func_00111630(void* self, int a1)
{
    switch (*(int*)((char*)self + 0xDE4)) {
    case 0:
        func_00131608((char*)self + 0x1C0);
        break;
    case 1:
        func_0012FC60((char*)self + 0x1D0);
        break;
    case 2:
        func_0012E980((char*)self + 0x1F0);
        break;
    case 4:
        func_0012F620((char*)self + 0x210);
        break;
    case 5:
        func_00133128((char*)self + 0x230);
        break;
    case 6:
        func_0012BE20((char*)self + 0x290);
        break;
    case 7:
        func_00131D08((char*)self + 0x2B0);
        break;
    case 8:
        func_0012CA30((char*)self + 0x2C0);
        break;
    case 9:
        func_0012F230((char*)self + 0x350);
        break;
    case 10:
        func_0012C5C8((char*)self + 0x360);
        break;
    case 11:
        func_001328B0((char*)self + 0x370);
        break;
    case 12:
        func_00136268((char*)self + 0x390, a1);
        break;
    case 3:
    case 13:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111728);
#ifdef SKIP_ASM
extern "C" void func_00131620(void* p, int a1);
extern "C" void func_0012FC80(void* p, int a1);
extern "C" void func_0012E9B8(void* p, int a1);
extern "C" void func_0012E778(void* p, int a1);
extern "C" void func_0012F730(void* p, int a1);
extern "C" void func_00133308(void* p, int a1);
extern "C" void func_0012BF68(void* p, int a1);
extern "C" void func_00131D30(void* p, int a1);
extern "C" void func_0012CB68(void* p, int a1);
extern "C" void func_0012F398(void* p);
extern "C" void func_0012C678(void* p);
extern "C" void func_00132A30(void* p, int a1);
extern "C" void func_00136508(void* p, int a1);
// Forwards to the second handler for the AI's current state.
extern "C" void func_00111728(void* self, int a1)
{
    switch (*(int*)((char*)self + 0xDE4)) {
    case 0:
        func_00131620((char*)self + 0x1C0, a1);
        break;
    case 1:
        func_0012FC80((char*)self + 0x1D0, a1);
        break;
    case 2:
        func_0012E9B8((char*)self + 0x1F0, a1);
        break;
    case 3:
        func_0012E778((char*)self + 0x200, a1);
        break;
    case 4:
        func_0012F730((char*)self + 0x210, a1);
        break;
    case 5:
        func_00133308((char*)self + 0x230, a1);
        break;
    case 6:
        func_0012BF68((char*)self + 0x290, a1);
        break;
    case 7:
        func_00131D30((char*)self + 0x2B0, a1);
        break;
    case 8:
        func_0012CB68((char*)self + 0x2C0, a1);
        break;
    case 9:
        func_0012F398((char*)self + 0x350);
        break;
    case 10:
        func_0012C678((char*)self + 0x360);
        break;
    case 11:
        func_00132A30((char*)self + 0x370, a1);
        break;
    case 12:
        func_00136508((char*)self + 0x390, a1);
        break;
    case 13:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111830);
#ifdef SKIP_ASM
extern const char* D_00459D70[];
extern const char D_00456C48[];

extern "C" const char* func_00111830(void* self)
{
    unsigned int i = *(unsigned int*)((char*)self + 0xDE0);
    if (i >= 7) {
        return D_00456C48;
    }
    return D_00459D70[i];
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111860);
#ifdef SKIP_ASM
extern const char* D_00459DC8[];
extern const char D_00456C48[];

extern "C" const char* func_00111860(void* self)
{
    unsigned int i = *(unsigned int*)((char*)self + 0xDE4);
    if (i >= 15) {
        return D_00456C48;
    }
    return D_00459DC8[i];
}
#endif
//100%
INCLUDE_ASM("ai/computer", func_00111890);
#ifdef SKIP_ASM
extern "C" void func_002DCF28(void*);
extern "C" void func_002DAA78(void*);
extern "C" void func_002E8560(void*);
extern "C" void func_002E6640(void*);
void func_002EADC0(void*);
extern "C" void func_002EF6A0(void*);
extern "C" void func_002D4BE0(void*);
extern "C" void func_002E3930(void*);
extern "C" void func_002DF3B0(void*);
extern "C" void func_002F1148(void*);
void func_002F64E8(void*);
// PORT: cWorldPainterMan_reset is defined with an unused self param; this caller passes none.
void cWorldPainterMan_reset_noarg() __asm__("cWorldPainterMan_reset__FPv");
void* func_002306A8(void* self, int i);

extern "C" void func_00111890(void* self)
{
    char* s = (char*)self;
    func_002DCF28(s + 0x3B0);
    func_002DAA78(s + 0x470);
    func_002E8560(s + 0x520);
    func_002E6640(s + 0x610);
    func_002EADC0(s + 0x9C0);
    func_002EF6A0(s + 0xAD0);
    func_002D4BE0(s + 0xAF0);
    func_002E3930(s + 0xB00);
    func_002DF3B0(s + 0xB40);
    func_002F1148(s + 0xC70);
    func_002F64E8(s + 0xD20);
    cWorldPainterMan_reset_noarg();
    int id = *(int*)(*(char**)(s + 0x18) + 0x870);
    if (id >= 0)
    {
        char* obj = (char*)func_002306A8(D_004A28A8->game, id);
        if (obj != 0)
        {
            sVEntry<void(void*)>* vt = *(sVEntry<void(void*)>**)(obj + 0xC);
            vt[14].fn(obj + vt[14].delta);
        }
    }
}
#endif

extern "C" void* func_002E23E0(void*);

//100%
INCLUDE_ASM("ai/computer", func_00111948);
#ifdef SKIP_ASM
extern "C" void func_002D4C08(void*);
extern "C" void func_002DABC8(void*);
extern "C" void func_002DD0B8(void*);
extern "C" void func_002DF920(void*);
extern "C" void func_002E39D8(void*);
extern "C" void func_002E66B8(void*);
extern "C" void func_002E8938(void*);
extern "C" void func_002EADD0(void*);
extern "C" void func_002EF6D0(void*);
extern "C" void func_002F1150(void*);
extern "C" void func_00392D18(void*);
extern "C" void func_002F6518(void*);
extern int D_004A4534;

extern "C" void func_00111948(void* self)
{
    if (D_004A4534 != 0) {
        cRider* r = *(cRider**)((char*)self + 0x18);
        char* o = (char*)&r->mVtbl;
        sVEntry<int(void*)>* e = &(*(sVEntry<int(void*)>**)o)[kRiderVt_isComputer];
        if (e->fn(o + e->delta) != 0)
            return;
    }
    func_00392D18((char*)self + 0xD30);
    func_002DD0B8((char*)self + 0x3B0);
    func_002DABC8((char*)self + 0x470);
    func_002E8938((char*)self + 0x520);
    func_002E66B8((char*)self + 0x610);
    func_002EADD0((char*)self + 0x9C0);
    func_002EF6D0((char*)self + 0xAD0);
    func_002D4C08((char*)self + 0xAF0);
    func_002E39D8((char*)self + 0xB00);
    func_002DF920((char*)self + 0xB40);
    func_002F1150((char*)self + 0xC70);
    func_002F6518((char*)self + 0xD20);
}
#endif
//100%
INCLUDE_ASM("ai/computer", func_001119F8);
#ifdef SKIP_ASM
extern "C" void func_002D5048(void*);
extern "C" void func_002DB478(void*);
extern "C" void func_002DDAB8(void*);
extern "C" void func_002E24D0(void*);
extern "C" void func_002E3AF8(void*);
extern "C" void func_002E7A10(void*);
extern "C" void func_002EA480(void*);
extern "C" void func_002EB198(void*);
extern "C" void func_002EF950(void*);
extern "C" void func_002F1510(void*);
void func_002F6908(void*);
extern int D_004A4534;

extern "C" void func_001119F8(void* self)
{
    if (D_004A4534 != 0) {
        cRider* r = *(cRider**)((char*)self + 0x18);
        char* o = (char*)&r->mVtbl;
        sVEntry<int(void*)>* e = &(*(sVEntry<int(void*)>**)o)[kRiderVt_isComputer];
        if (e->fn(o + e->delta) != 0)
            return;
    }
    func_002DDAB8((char*)self + 0x3B0);
    func_002DB478((char*)self + 0x470);
    func_002EA480((char*)self + 0x520);
    func_002E7A10((char*)self + 0x610);
    func_002EB198((char*)self + 0x9C0);
    func_002EF950((char*)self + 0xAD0);
    func_002D5048((char*)self + 0xAF0);
    func_002E3AF8((char*)self + 0xB00);
    func_002E24D0((char*)self + 0xB40);
    func_002F1510((char*)self + 0xC70);
    func_002F6908((char*)self + 0xD20);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111AA0__FPv);
#ifdef SKIP_ASM
// PORT: prototype mismatch. The project names this func_00111AA0__FPv (one
// void* param), but every caller passes (self, vecA, vecB, int, float) and the
// body forwards them to func_002E23E0 with an extra 0 flag. The unit declares
// func_002E23E0 as (void*), so both are bound by asm label.
void func_002E23E0_impl(void* self, void* a, void* b, int c, int flag, float x) __asm__("func_002E23E0");

void func_00111AA0_impl(void* self, void* a, void* b, int c, float x) __asm__("func_00111AA0__FPv");

void func_00111AA0_impl(void* self, void* a, void* b, int c, float x)
{
    func_002E23E0_impl((char*)self + 0xB40, a, b, c, 0, x);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111AC0);
#ifdef SKIP_ASM
// The save / load stream (vptr at 0x0): slot 1 writes, slot 2 reads.
class cStream {
public:
    virtual void Write(void* p, int n);
    virtual void Read(void* p, int n);
};

extern char D_004D33A0[];
extern "C" void func_00104D68(void* self, void* s);
extern "C" void func_00310EA8(void* self, void* s);
extern "C" void func_00113AA0(void* self, void* s);
extern "C" void func_001174B0(void* self, void* s);
extern "C" void func_0013F848(void* self, void* s);
extern "C" void func_0013ACB0(void* self, void* s);
extern "C" void func_00138AD8(void* self, void* s);
extern "C" void func_0013C5E0(void* self, void* s);
extern "C" void func_00139970(void* self, void* s);
extern "C" void func_00131598(void* self, void* s);
extern "C" void func_0012FBF0(void* self, void* s);
extern "C" void func_001361F8(void* self, void* s);
extern "C" void func_0012C558(void* self, void* s);
extern "C" void func_00132840(void* self, void* s);
extern "C" void func_0012E708(void* self, void* s);
extern "C" void func_0012F5B0(void* self, void* s);
extern "C" void func_0012C9C0(void* self, void* s);
extern "C" void func_001330B8(void* self, void* s);
extern "C" void func_001368E8(void* self, void* s);
extern "C" void func_002F6A58(void* self, void* s);
extern "C" int func_0026B508(void* tree, void* path);
extern "C" int func_0026B550(void* tree, void* path);

extern "C" void func_00111AC0(char* self, char* s)
{
    cStream* st = (cStream*)s;
    st->Write(*(void**)(self + 0x18), 0x6C0);
    func_00104D68(*(void**)(*(char**)(self + 0x18) + 0x784), s);
    func_00310EA8(*(void**)(*(char**)(self + 0x18) + 0x780), s);
    func_00113AA0(*(void**)(*(char**)(self + 0x18) + 0x788), s);
    func_001174B0(*(void**)(*(char**)(self + 0x18) + 0x790), s);
    unsigned int id0 = 0xFFFFFFFF;
    char* p0 = **(char***)(*(char**)(self + 0x18) + 0x864);
    if (p0 != 0) {
        id0 = *(unsigned int*)(p0 + 0x150);
    }
    st->Write(&id0, 4);
    st->Write(*(void**)(*(char**)(self + 0x18) + 0x864), 0x10);
    unsigned int id1 = 0xFFFFFFFF;
    char* p1 = **(char***)(*(char**)(self + 0x18) + 0x868);
    if (p1 != 0) {
        id1 = *(unsigned int*)(p1 + 0x150);
    }
    st->Write(&id1, 4);
    st->Write(*(void**)(*(char**)(self + 0x18) + 0x868), 0x10);
    st->Write(self + 0xDE0, 4);
    st->Write(self + 0xDE4, 4);
    func_0013F848(self, s);
    func_0013ACB0(self + 0x20, s);
    func_00138AD8(self + 0x30, s);
    func_0013C5E0(self + 0xB0, s);
    func_00139970(self + 0x110, s);
    func_00131598(self + 0x1D0, s);
    func_0012FBF0(self + 0x210, s);
    func_001361F8(self + 0x230, s);
    func_0012C558(self + 0x290, s);
    func_00132840(self + 0x2B0, s);
    func_0012E708(self + 0x2C0, s);
    func_0012F5B0(self + 0x350, s);
    func_0012C9C0(self + 0x360, s);
    func_001330B8(self + 0x370, s);
    func_001368E8(self + 0x390, s);
    func_002F6A58(self + 0xD20, s);
    st->Write(*(void**)(*(char**)(self + 0x18) + 0xABC), 0x20);
    st->Write(*(void**)(*(char**)(self + 0x18) + 0xAC0), 0x20);
    int ids[2];
    ids[0] = func_0026B508(D_004D33A0, *(void**)(*(char**)(self + 0x18) + 0xAB4));
    ids[1] = func_0026B550(D_004D33A0, *(void**)(*(char**)(self + 0x18) + 0xAB8));
    st->Write(ids, 8);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00111D98);
#ifdef SKIP_ASM
struct sRefSet_00111D98 {
    char pad_0x0[0xC];
    unsigned int* refs;     // 0xC
};

struct sRefWorld_00111D98 {
    char pad_0x0[0x8];
    sRefSet_00111D98** sets;    // 0x8
};

extern sRefWorld_00111D98** D_004A47B8;
extern char D_004D33A0[];
extern "C" void func_00104DE0(void* self, void* s);
extern "C" void func_00310EE0(void* self, void* s);
extern "C" void func_00113AD8(void* self, void* s);
extern "C" void func_001174E8(void* self, void* s);
extern "C" void func_0013F880(void* self, void* s);
extern "C" void func_0013ACE8(void* self, void* s);
extern "C" void func_00138B10(void* self, void* s);
extern "C" void func_0013C618(void* self, void* s);
extern "C" void func_001399A8(void* self, void* s);
extern "C" void func_001315D0(void* self, void* s);
extern "C" void func_0012FC28(void* self, void* s);
extern "C" void func_00136230(void* self, void* s);
extern "C" void func_0012C590(void* self, void* s);
extern "C" void func_00132878(void* self, void* s);
extern "C" void func_0012E740(void* self, void* s);
extern "C" void func_0012F5E8(void* self, void* s);
extern "C" void func_0012C9F8(void* self, void* s);
extern "C" void func_001330F0(void* self, void* s);
extern "C" void func_00136920(void* self, void* s);
extern "C" void func_002DCF28(void*);
extern "C" void func_002DAA78(void*);
extern "C" void func_002E8560(void*);
extern "C" void func_002E6640(void*);
void func_002EADC0(void*);
extern "C" void func_002EF6A0(void*);
extern "C" void func_002D4BE0(void*);
extern "C" void func_002E3930(void*);
extern "C" void func_002F1148(void*);
extern "C" void func_002F6A90(void* self, void* s);
extern "C" void* func_0026AF70(void* tree, int id);
extern "C" void* func_0026AF88(void* tree, int id);
extern "C" void func_00312598(void* self, int a1);
extern "C" void func_003103F0(void* self);
extern "C" void func_00106828(void* self);

static inline void* idxToPtr_00111D98(unsigned int i)
{
    return (void*)(i << 2);
}

static inline void* refToPtr_00111D98(unsigned int v)
{
    unsigned int i = v >> 8;
    if (i == 0) {
        return 0;
    }
    return idxToPtr_00111D98(i);
}

struct sRef_00111D98 {
    unsigned int id;
    sRef_00111D98() : id(0xFFFFFFFF) {}

    void* get()
    {
        sRefSet_00111D98* set = (*D_004A47B8)->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        return refToPtr_00111D98(set->refs[id >> 8]);
    }
};

extern "C" void func_00111D98(char* self, char* s)
{
    cStream* st = (cStream*)s;
    st->Read(*(void**)(self + 0x18), 0x6C0);
    func_00104DE0(*(void**)(*(char**)(self + 0x18) + 0x784), s);
    func_00310EE0(*(void**)(*(char**)(self + 0x18) + 0x780), s);
    func_00113AD8(*(void**)(*(char**)(self + 0x18) + 0x788), s);
    func_001174E8(*(void**)(*(char**)(self + 0x18) + 0x790), s);
    int ids[2];
    sRef_00111D98 r0;
    st->Read(&r0, 4);
    st->Read(*(void**)(*(char**)(self + 0x18) + 0x864), 0x10);
    if (~r0.id != 0) {
        **(void***)(*(char**)(self + 0x18) + 0x864) = r0.get();
    }
    sRef_00111D98 r1;
    st->Read(&r1, 4);
    st->Read(*(void**)(*(char**)(self + 0x18) + 0x868), 0x10);
    if (~r1.id != 0) {
        **(void***)(*(char**)(self + 0x18) + 0x868) = r1.get();
    }
    st->Read(self + 0xDE0, 4);
    st->Read(self + 0xDE4, 4);
    func_0013F880(self, s);
    func_0013ACE8(self + 0x20, s);
    func_00138B10(self + 0x30, s);
    func_0013C618(self + 0xB0, s);
    func_001399A8(self + 0x110, s);
    func_001315D0(self + 0x1D0, s);
    func_0012FC28(self + 0x210, s);
    func_00136230(self + 0x230, s);
    func_0012C590(self + 0x290, s);
    func_00132878(self + 0x2B0, s);
    func_0012E740(self + 0x2C0, s);
    func_0012F5E8(self + 0x350, s);
    func_0012C9F8(self + 0x360, s);
    func_001330F0(self + 0x370, s);
    func_00136920(self + 0x390, s);
    func_002DCF28(self + 0x3B0);
    func_002DAA78(self + 0x470);
    func_002E8560(self + 0x520);
    func_002E6640(self + 0x610);
    func_002EADC0(self + 0x9C0);
    func_002EF6A0(self + 0xAD0);
    func_002D4BE0(self + 0xAF0);
    func_002E3930(self + 0xB00);
    func_002F1148(self + 0xC70);
    func_002F6A90(self + 0xD20, s);
    st->Read(*(void**)(*(char**)(self + 0x18) + 0xABC), 0x20);
    st->Read(*(void**)(*(char**)(self + 0x18) + 0xAC0), 0x20);
    st->Read(ids, 8);
    *(void**)(*(char**)(self + 0x18) + 0xAB4) = func_0026AF70(D_004D33A0, ids[0]);
    *(void**)(*(char**)(self + 0x18) + 0xAB8) = func_0026AF88(D_004D33A0, ids[1]);
    t4Vector* q = *(t4Vector**)(*(char**)(self + 0x18) + 0x78C);
    if (q != 0) {
        *q = *(t4Vector*)(*(char**)(self + 0x18) + 0x110);
    }
    func_00312598(*(void**)(*(char**)(self + 0x18) + 0x784), 0);
    func_003103F0(*(void**)(*(char**)(self + 0x18) + 0x780));
    func_00106828(*(void**)(self + 0x18));
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00112180);
#ifdef SKIP_ASM
extern "C" void* func_0026B5E0(void*, int, int);
extern char D_004D33A0[];
extern "C" float func_00115B08(void* self);

void func_0011D660_112180(void* self, t4Vector* a, t4Vector* b, int n, float t) __asm__("func_0011D660");
extern "C" float func_0026A638(void* path, void* a1, void* a2, void* a3, void* hint, int n);
t4Vector func_0026AB20_112180(void* path, float t, int* inRange) __asm__("func_0026AB20");

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector vu0Scale_112180(const t4Vector& v, float s)
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
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void vu0AddEq_112180(t4Vector& dst, t4Vector b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

extern "C" void func_00112180(char* self, int flag)
{
    float* p = (float*)func_0026B5E0(D_004D33A0, 1, *(int*)(self + 0x86C));
    if (flag)
    {
        t4Vector dir;
        t4Vector pos;
        dir.x = p[5];
        dir.y = p[6];
        dir.z = p[7];
        dir.w = 0.0f;
        pos.x = p[2];
        pos.y = p[3];
        pos.z = p[4];
        pos.w = 1.0f;
        vu0AddEq_112180(pos, vu0Scale_112180(dir, func_00115B08(self)));
        func_0011D660_112180(self, &pos, &dir, 5, 0.0f);
    }
    *(int*)(*(char**)(self + 0xABC) + 0x14) = -1;
    *(int*)(*(char**)(self + 0xAC0) + 0x14) = -1;
    *(void**)(self + 0xAB4) = ((void**)p)[8];
    *(void**)(self + 0xAB8) = ((void**)p)[9];
    t4Vector up;
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = 0.0f;
    up.w = 1.0f;
    float out;
    float res = func_0026A638(*(void**)(self + 0xAB4), self + 0x110, &up, &out, *(void**)(self + 0xAC0), 1);
    float t = *(float*)(*(char**)(self + 0xAB4) + 0x38);
    if (t < res)
        res = 0.0f;
    *(float*)(self + 0x4D0) = *(float*)(self + 0x4D4) = t - res;
    res = func_0026A638(*(void**)(self + 0xAB8), self + 0x110, self + 0x490, self + 0x4C8, *(void**)(self + 0xABC), 1);
    *(float*)(self + 0x4C0) = *(float*)(self + 0x4C4) = res;
    t4Vector pos2 = func_0026AB20_112180(*(void**)(self + 0xAB8), res + 796.0f, 0);
    *(t4Vector*)(self + 0x4A0) = pos2;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00112338);
#ifdef SKIP_ASM
struct sEnt_00112338 { int a; int b; int c; int d; };
struct sComp_00112338 { char pad[0x4DC]; sEnt_00112338 ent[12]; int count; };

extern sEnt_00112338 D_004A5D60[];
extern "C" void func_003E6574(void*, void*, int);
extern "C" void func_00112FB0(void* self, float* a, float* b, t4Vector* c);
extern "C" void func_001127F0(void* self, int a);
extern "C" float func_0026AC48(void* self);
extern "C" void func_0010E5D8(void* self, int* arg, int a2, int a3);

extern "C" void func_00112338(char* self)
{
    sComp_00112338* s = (sComp_00112338*)self;
    func_003E6574(D_004A5D60, s->ent, s->count << 4);
    int n = s->count;
    t4Vector c;
    float a;
    float b;
    func_00112FB0(self, &a, &b, &c);
    if (0.0f < *(float*)(self + 0x4D4))
    {
        void* old = *(void**)(self + 0xAB4);
        if (500.0f < a && D_004A28A8->game->race->frame % 60 == 0)
            func_001127F0(self, 0);
        else if (func_0026AC48(*(void**)(self + 0xAB4)) - 200.0f < b)
            func_001127F0(self, 1);
        else
        {
            char* o = *(char**)(self + 0xAB4);
            sVEntry<int(void*, float, float)>* ve = &(*(sVEntry<int(void*, float, float)>**)(o + 0x34))[2];
            if (ve->fn(o + ve->delta, *(float*)(self + 0x4D4), *(float*)(self + 0x4D0)))
                func_001127F0(self, 0);
        }
        if (*(void**)(self + 0xAB4) != old)
        {
            *(int*)(*(char**)(self + 0xAC0) + 0x14) = -1;
            func_00112FB0(self, &a, &b, &c);
        }
    }
    int i;
    for (i = 0; i < s->count; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (s->ent[i].a == D_004A5D60[j].a && s->ent[i].b == D_004A5D60[j].b)
            {
                D_004A5D60[j].a = 0;
                break;
            }
        }
        func_0010E5D8(self, (int*)&s->ent[i], j < n, 1);
    }
    for (i = 0; i < n; i++)
    {
        if (D_004A5D60[i].a)
            func_0010E5D8(self, (int*)&D_004A5D60[i], 1, 0);
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00112588);
#ifdef SKIP_ASM
extern "C" float func_00112588(void* self, int arg1)
{
    float v = 796.0f;
    if (arg1 == 0) {
        v = 200.0f;
    }
    return v;
}
#endif

// R5900 128-bit GPR quadword, for functions that copy/return a 16-byte
// block via a single lq/sq pair instead of word-by-word.
typedef int cQuad128 __attribute__((mode(TI)));

//100%
INCLUDE_ASM("ai/computer", func_001125A8);
#ifdef SKIP_ASM
extern "C" cQuad128 func_001125A8(void* self)
{
    cQuad128 v = *(cQuad128*)((char*)self + 0x4A0);
    *(cQuad128*)((char*)self + 0x4B0) = v;
    return v;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_001125B8__FPv);
#ifdef SKIP_ASM
int func_001125B8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_001125C0);
#ifdef SKIP_ASM
// PORT: the unit defines func_001125B8 as int; here its result is used as a bool (xori 1).
bool func_001125B8_b(void* self) __asm__("func_001125B8__FPv");
// PORT: the unit defines func_001125A8(void* self); callers pass a second arg in $5.
cQuad128 func_001125A8_2(void* self, int a) __asm__("func_001125A8");
extern "C" float func_0026A638(void* path, void* a1, void* a2, void* a3, void* hint, int n);
extern "C" float func_0026A428(void* path, void* a1, void* a2, void* a3, int n);
t4Vector func_0026AB20_1125C0(void* path, float t, int* inRange) __asm__("func_0026AB20");
extern "C" float func_0026AC48(void* self);
extern "C" void func_00112A50(void* self, int a);

static inline float atan2_001125C0(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f) {
            return y;
        }
        if (y >= 0.0f) {
            return 1.5707963705062866f;
        }
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f) {
            a += 3.1415927410125732f;
        } else {
            a -= 3.1415927410125732f;
        }
    }
    return a;
}

extern "C" void func_001125C0(char* self)
{
    *(float*)(self + 0x4C0) = *(float*)(self + 0x4C4);
    int nf = !func_001125B8_b(self);
    if (nf)
        *(float*)(self + 0x4C4) = func_0026A638(*(void**)(self + 0xAB8), self + 0x110, self + 0x490, self + 0x4C8, *(void**)(self + 0xABC), nf);
    else
        *(float*)(self + 0x4C4) = func_0026A428(*(void**)(self + 0xAB8), self + 0x110, self + 0x490, self + 0x4C8, 0);
    float k = func_00112588(self, nf);
    *(t4Vector*)(self + 0x4A0) = func_0026AB20_1125C0(*(void**)(self + 0xAB8), *(float*)(self + 0x4C4) + k, 0);
    func_001125A8_2(self, nf);
    if (0.0f < *(float*)(self + 0x4D4))
    {
        if (500.0f < *(float*)(self + 0x4C8) && D_004A28A8->game->race->frame % 60 == 0)
            func_00112A50(self, 0);
        else if (func_0026AC48(*(void**)(self + 0xAB8)) - 200.0f < *(float*)(self + 0x4C4))
            func_00112A50(self, 1);
        else
        {
            char* o = *(char**)(self + 0xAB8);
            sVEntry<int(void*, float, float)>* ve = &(*(sVEntry<int(void*, float, float)>**)(o + 0x34))[2];
            if (ve->fn(o + ve->delta, *(float*)(self + 0x4C0), *(float*)(self + 0x4C4)))
                func_00112A50(self, 0);
        }
    }
    float dx = *(float*)(self + 0x4A0) - *(float*)(self + 0x490);
    float dy = *(float*)(self + 0x4A4) - *(float*)(self + 0x494);
    *(float*)(self + 0x4CC) = atan2_001125C0(dy, dx);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_001127F0);
#ifdef SKIP_ASM
extern char D_004D33A0[];
extern "C" int func_0026B178(void* tree, void* pos, void** out, int maxOut);
extern "C" float func_0026A428(void* path, void* a1, void* a2, void* a3, int n);
t4Vector func_0026AB20_1127F0(void* path, float t, int* inRange) __asm__("func_0026AB20");

// PORT: PS2-only VU0 inline asm (vector length).
static inline float vu0Length_1127F0(const t4Vector& v)
{
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector vu0Scale_1127F0(const t4Vector& v, float s)
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
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline t4Vector vu0Add_1127F0(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector vu0Sub_1127F0(const t4Vector& a, const t4Vector& b)
{
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_1127F0(const t4Vector& a, const t4Vector& b)
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

extern "C" void func_001127F0(void* vself, int skipCur)
{
    char* self = (char*)vself;
    void* paths[3];
    t4Vector out;
    t4Vector pos;
    float len = vu0Length_1127F0(*(t4Vector*)(self + 0x1E0));
    void* best = *(void**)(self + 0xAB4);
    float bestD = 9.999999933815813e+36f;
    if (len == 0.0f) {
        pos = *(t4Vector*)(self + 0x110);
    } else {
        float s = func_00112588(self, 1) / len;
        pos = vu0Add_1127F0(*(t4Vector*)(self + 0x110), vu0Scale_1127F0(*(t4Vector*)(self + 0x1E0), s));
    }
    int n = func_0026B178(D_004D33A0, &pos, paths, 3);
    for (int i = 0; i < n; i++) {
        if (skipCur && paths[i] == *(void**)(self + 0xAB4)) {
            continue;
        }
        float tOut;
        float t = func_0026A428(paths[i], &pos, &out, &tOut, 1);
        if (paths[i] == *(void**)(self + 0xAB4)) {
            if (1592.0f < __builtin_fabsf(*(float*)((char*)paths[i] + 0x38) - *(float*)(self + 0x4D0) - t)) {
                *(int*)(*(char**)(self + 0xAC0) + 0x14) = -1;
            }
        }
        t += 796.0f;
        t4Vector d1 = vu0Sub_1127F0(pos, func_0026AB20_1127F0(paths[i], t, 0));
        t4Vector d0 = vu0Sub_1127F0(*(t4Vector*)(self + 0x110), out);
        float dist = vu0Dot_1127F0(d0, d0) + vu0Dot_1127F0(d1, d1);
        if (dist < bestD) {
            best = paths[i];
            bestD = dist;
        }
    }
    *(void**)(self + 0xAB4) = best;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00112A50);
#ifdef SKIP_ASM
extern char D_004D33A0[];
extern "C" int func_0026AFB8(void* tree, void* pos, void** out, int maxOut, int a4);
extern "C" float func_0026AC48(void* self);
extern "C" float func_0026A638(void* path, void* a1, void* a2, void* a3, void* hint, int n);
extern "C" float func_0026A428(void* path, void* a1, void* a2, void* a3, int n);
t4Vector func_0026AB20_112A50(void* path, float t, int* inRange) __asm__("func_0026AB20");

// PORT: PS2-only VU0 inline asm (vector length).
static inline float vu0Length_112A50(const t4Vector& v)
{
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector vu0Scale_112A50(const t4Vector& v, float s)
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
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline t4Vector vu0Add_112A50(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector vu0Sub_112A50(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__ __volatile__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_112A50(const t4Vector& a, const t4Vector& b)
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

extern "C" void func_00112A50(void* vself, int keep)
{
    char* self = (char*)vself;
    void* paths[6];
    t4Vector out;
    t4Vector pos;
    float len = vu0Length_112A50(*(t4Vector*)(self + 0x1E0));
    void* best = 0;
    float bestD = 9.999999933815813e+36f;
    float bestW = -1.0f;
    if (len == 0.0f) {
        pos = *(t4Vector*)(self + 0x110);
    } else {
        pos = vu0Add_112A50(*(t4Vector*)(self + 0x110), vu0Scale_112A50(*(t4Vector*)(self + 0x1E0), 796.0f / len));
    }
    int n = func_0026AFB8(D_004D33A0, &pos, paths, 6, 0);
    for (int i = 0; i < n; i++) {
        if (paths[i] == *(void**)(self + 0xAB8) && keep) {
            continue;
        }
        float tOut;
        float t = func_0026A428(paths[i], &pos, &out, &tOut, 1);
        if (func_0026AC48(paths[i]) - 200.0f < t) {
            continue;
        }
        t4Vector d1 = vu0Sub_112A50(pos, func_0026AB20_112A50(paths[i], t + 796.0f, 0));
        t4Vector d0 = vu0Sub_112A50(*(t4Vector*)(self + 0x110), out);
        float dist = vu0Dot_112A50(d0, d0) + vu0Dot_112A50(d1, d1);
        char* o = self + 0x6C0;
        sVEntry<int(void*)>* ve = &(*(sVEntry<int(void*)>**)o)[9];
        if (ve->fn(o + ve->delta) == 1) {
            sVEntry<float(void*, void*)>* vf = &(*(sVEntry<float(void*, void*)>**)(self + 0x6C0))[20];
            dist = vf->fn(self + vf->delta, paths[i]);
            if (bestW < dist) {
                best = paths[i];
                bestW = dist;
                if (best == *(void**)(self + 0xAB8)) {
                    best = 0;
                }
            }
        } else {
            if (dist < bestD) {
                best = paths[i];
                bestD = dist;
                if (best == *(void**)(self + 0xAB8)) {
                    best = 0;
                }
            }
        }
    }
    if (best != 0) {
        *(void**)(self + 0xAB8) = best;
        *(int*)(*(char**)(self + 0xABC) + 0x14) = -1;
        float r = func_0026A638(*(void**)(self + 0xAB8), self + 0x110, self + 0x490, self + 0x4C8, *(void**)(self + 0xABC), 1);
        *(float*)(self + 0x4C4) = r;
        *(t4Vector*)(self + 0x4A0) = func_0026AB20_112A50(*(void**)(self + 0xAB8), r + 796.0f, 0);
        *(float*)(self + 0x4C0) = *(float*)(self + 0x4C4);
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00112D58);
#ifdef SKIP_ASM
extern char D_004D33A0[];
int func_0026AF98_112D58(void* self, void* a1, void** out, int maxOut) __asm__("func_0026AF98__FPv");
extern "C" float func_0026A428(void* path, void* a1, void* a2, void* a3, int n);
extern "C" float func_0026A638(void* path, void* a1, void* a2, void* a3, void* hint, int n);
extern "C" float func_0026AC48(void* self);
t4Vector func_00269F18_112D58(void* path, float* t) __asm__("func_00269F18");

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector vu0Sub_112D58(const t4Vector& a, const t4Vector& b)
{
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_112D58(const t4Vector& a, const t4Vector& b)
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

extern "C" void func_00112D58(char* self)
{
    void* paths[6];
    t4Vector pos;
    int n = func_0026AF98_112D58(D_004D33A0, self + 0x110, paths, 6);
    void* best = 0;
    float bestD = 9.999999933815813e+36f;
    int i;
    for (i = 0; i < n; i++)
    {
        float tOut;
        float t = func_0026A428(paths[i], self + 0x110, &pos, &tOut, 1);
        float len = func_0026AC48(paths[i]);
        char* o = self + 0x6C0;
        sVEntry<int(void*)>* ve = &(*(sVEntry<int(void*)>**)o)[8];
        if (ve->fn(o + ve->delta) == 0 && len - 200.0f < t)
            continue;
        float t2 = t + 796.0f;
        t4Vector d1 = vu0Sub_112D58(*(t4Vector*)(self + 0x110), func_00269F18_112D58(paths[i], &t2));
        t4Vector d0 = vu0Sub_112D58(*(t4Vector*)(self + 0x110), pos);
        float dist = vu0Dot_112D58(d0, d0) + vu0Dot_112D58(d1, d1);
        if (dist < bestD)
        {
            best = paths[i];
            bestD = dist;
            if (best == *(void**)(self + 0xAB8))
                best = 0;
        }
    }
    if (*(void**)(self + 0xAB8) == 0)
        return;
    if (best)
        *(void**)(self + 0xAB8) = best;
    *(int*)(*(char**)(self + 0xABC) + 0x14) = -1;
    *(float*)(self + 0x4C4) = func_0026A638(*(void**)(self + 0xAB8), self + 0x110, self + 0x490, self + 0x4C8, *(void**)(self + 0xABC), 1);
    *(t4Vector*)(self + 0x490) = func_00269F18_112D58(*(void**)(self + 0xAB8), (float*)(self + 0x4C4));
    float t3 = *(float*)(self + 0x4C4) + 796.0f;
    *(t4Vector*)(self + 0x4A0) = func_00269F18_112D58(*(void**)(self + 0xAB8), &t3);
    *(float*)(self + 0x4C0) = *(float*)(self + 0x4C4);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00112FB0);
#ifdef SKIP_ASM
extern "C" float func_0026A638(void* path, void* a1, void* a2, void* a3, void* hint, int n);
struct sVE_12FB0 { short delta; short index; int (*fn)(void*, float, float, void*, int); };
struct sE_12FB0 { int id; float dist; };
struct sTbl_12FB0 { char pad[0x18]; sE_12FB0 e[6]; };
extern sTbl_12FB0 D_004D33A0_12FB0 __asm__("D_004D33A0");

extern "C" void func_00112FB0(void* vself, float* a, float* b, t4Vector* c)
{
    char* self = (char*)vself;
    float res = func_0026A638(*(void**)(self + 0xAB4), self + 0x110, c, a, *(void**)(self + 0xAC0), 1);
    *b = res;
    float t = *(float*)(*(char**)(self + 0xAB4) + 0x38) - res;
    float lim = *(float*)(self + 0x4D4);
    *(float*)(self + 0x4D0) = t;
    if (t < lim) {
        sTbl_12FB0* tbl = &D_004D33A0_12FB0;
        for (int i = 0; i < 6; i++) {
            float d = tbl->e[i].dist;
            sE_12FB0* e = &tbl->e[i];
            if (d == 0.0f)
                break;
            if (d < *(float*)(self + 0x4D0))
                break;
            if (e->dist < *(float*)(self + 0x4D4))
                func_0010E558(self, &e->id);
        }
        char* o = *(char**)(self + 0xAB4);
        sVE_12FB0* ve = &(*(sVE_12FB0**)(o + 0x34))[1];
        *(int*)(self + 0x59C) = ve->fn(o + ve->delta, *(float*)(self + 0x4D4), *(float*)(self + 0x4D0), self + 0x4DC, 12);
        *(float*)(self + 0x4D4) = *(float*)(self + 0x4D0);
    } else {
        char* o = *(char**)(self + 0xAB4);
        sVE_12FB0* ve = &(*(sVE_12FB0**)(o + 0x34))[1];
        *(int*)(self + 0x59C) = ve->fn(o + ve->delta, lim, lim, self + 0x4DC, 12);
    }
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00113128__FPv);
#ifdef SKIP_ASM
float func_00113128(void* self)
{
    return *(float*)((char*)self + 0x4D0);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00113130__FPv);
#ifdef SKIP_ASM
float func_00113130(void* self)
{
    return *(float*)((char*)self + 0x4D8);
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00113138);
#ifdef SKIP_ASM
extern "C" void cAirPredictor_reset(char* self);

extern "C" void* func_00113138(void* self)
{
    *(unsigned int*)((char*)self + 0x30) = 0xFFFFFFFF;
    cAirPredictor_reset((char*)self);
    return self;
}
#endif

//100%
INCLUDE_ASM("ai/computer", func_00113170);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00113170(void* self, int flags)
{
    if (flags & 1)
    {
        operator_delete((int*)self);
    }
}
#endif

