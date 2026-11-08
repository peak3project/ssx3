#include "common.h"

//100%
INCLUDE_ASM("ai/ridermetrix", cRiderMetrix_linkToRider);
#ifdef SKIP_ASM
extern "C" int* func_00116FA8(void* p);
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_004A1078[];

inline void* operator new[](unsigned int, void* p) { return p; }

struct sMetrixEntry_001172E0
{
    char pad_0x00[0x98];
    int index;
    sMetrixEntry_001172E0() { func_00116FA8(this); }
};

// PORT: element address built through int (pointer in int).
extern "C" void cRiderMetrix_linkToRider(char* self, char* rider)
{
    *(char**)(self + 0x1AC) = rider;
    if (*(int*)(rider + 0x870) >= 0)
    {
        sMetrixEntry_001172E0** slot = (sMetrixEntry_001172E0**)(self + 0x1B0);
        *(int*)(self + 0x1B4) = 0x2C;
        *slot = new (operator_new__FUi(0x2C * sizeof(sMetrixEntry_001172E0), D_004A1078, 0, 0)) sMetrixEntry_001172E0[0x2C];
        for (int i = 0; i < *(int*)(self + 0x1B4); i++)
        {
            ((sMetrixEntry_001172E0*)(i * 0x9C + *(int*)(self + 0x1B0)))->index = i;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001173B8);
#ifdef SKIP_ASM
struct sRiderMetrixEntry_001173B8
{
    int state;
    char pad[0x98];
};

struct sRiderMetrix_001173B8
{
    char pad[0x1B0];
    sRiderMetrixEntry_001173B8* entries;
    int count;
};

extern "C" void func_001173B8(sRiderMetrix_001173B8* self)
{
    if (self->entries != 0)
    {
        for (int i = 0; i < self->count; i++)
        {
            self->entries[i].state = 0x34;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117400);
#ifdef SKIP_ASM
struct sRiderMetrixEntry_00117400
{
    int type;
    char pad[0x98];
};

struct sRiderMetrix_00117400
{
    char pad[0x1B0];
    sRiderMetrixEntry_00117400* entries;
    int count;
    int bits[2];
    int dirty;
};

static inline bool rmBitTest00117400(int* bits, int i)
{
    int mask = 1 << i;
    return (*(int*)((char*)bits + ((i & ~0x1F) >> 3)) & mask) != 0;
}

extern "C" int func_00117400(sRiderMetrix_00117400* self, int type)
{
    if (self->entries == 0)
        return 0;
    if (self->dirty)
    {
        for (int i = 0; i < self->count; i++)
        {
            int t = self->entries[i].type;
            if (t != 0x34)
            {
                int off = (t & ~0x1F) >> 3;
                int* b = self->bits;
                *(int*)((char*)b + off) |= 1 << t;
            }
        }
        self->dirty = 0;
    }
    return rmBitTest00117400(self->bits, type);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001174B0);
#ifdef SKIP_ASM
struct sVEntry001174B0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001174B0(void* self, void* obj)
{
    sVEntry001174B0* vt = *(sVEntry001174B0**)obj;
    vt[1].fn((char*)obj + vt[1].delta, self, 0x1AC);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001174E8);
#ifdef SKIP_ASM
struct sVEntry001174E8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001174E8(void* self, void* obj)
{
    sVEntry001174E8* vt = *(sVEntry001174E8**)obj;
    vt[2].fn((char*)obj + vt[2].delta, self, 0x1AC);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117520);
#ifdef SKIP_ASM
extern "C" void func_00117520(void* self, int a1)
{
    int delta = a1 - *(int*)((char*)self + 0x1c8);
    *(int*)((char*)self + 0x1c8) = a1;
    *(int*)((char*)self + 0x198) += delta;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_00117540);
#ifdef SKIP_ASM
extern "C" void func_001175B8(char* self);
extern "C" void func_003E6448(void* dst, int value, int size);
extern "C" void func_00117838(void* self);
extern "C" void func_001175F8(void* self);

extern "C" void func_00117540(char* self)
{
    func_001175B8(self);
    func_001173B8((sRiderMetrix_001173B8*)self);
    func_003E6448(self + 0xA8, 0, 0x50);
    *(int*)(self + 0xF8) = 0;
    func_00117838(self);
    func_001175F8(self);
    *(int*)(self + 0x1A8) = 0;
    *(float*)(self + 0xA4) = -1.0f;
    func_003E6448(self + 0x1B8, 0, 8);
    *(int*)(self + 0x1C0) = 1;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001175B8);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);

extern "C" void func_001175B8(char* self)
{
    func_003E6448(self + 0xFC, 0, 0xAC);
    *(int*)(self + 0x18C) = -1;
    *(int*)(self + 0x198) = *(int*)(self + 0x1C8);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001175F8);
#ifdef SKIP_ASM
extern "C" void func_001179E0(void* self, int type);

extern "C" void func_001175F8(void* self)
{
    func_001179E0(self, 3);
    *(int*)((char*)self + 0x9C) = 0;
    *(int*)((char*)self + 0xA0) = 0;
    *(float*)((char*)self + 0xA4) = -1.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117638);
#ifdef SKIP_ASM
extern "C" void func_001171A8(void* self, int type, int value, int arg, float f);

// PORT: g++ <? (min) operator, removed in GCC 4.3.
static inline float rmClamp_117638(float v, float lo, float hi)
{
    if (v >= lo)
        return v <? hi;
    return lo;
}

static inline bool rmIsState_117638(char* p, int st)
{
    return *(int*)p == st;
}

// PORT: g++ <? (min) operator, removed in GCC 4.3.
extern "C" void func_00117638(void* self, int points)
{
    char* s = (char*)self;
    if (points > 0)
    {
        int n = *(int*)(s + 0x9C) + 1;
        *(int*)(s + 0x9C) = n;
        float m = ((float)n + 10.0f) * 0.05000000074505806f;
        float k = rmClamp_117638(m, 0.5f, 2.0f);
        *(float*)(s + 0xA4) = -1.0f;
        *(int*)(s + 0xA0) += (int)(points * k);
        char* r = *(char**)(s + 0x1B0);
        if (r != 0)
        {
            int v = 0;
            char* p = r + 0x1D4;
            if (!rmIsState_117638(p, 0x34))
                v = *(int*)(r + 0x1E8);
            func_001171A8(p, 3, v, n, 0.0f);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001176F8);
#ifdef SKIP_ASM
extern "C" void func_001176F8(void* self)
{
    *(float*)((char*)self + 0xa4) = -1.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117708);
#ifdef SKIP_ASM
// PORT: g++ >? (max) operator, removed in GCC 4.3.
extern "C" void func_00117708(void* self, float seconds)
{
    *(float*)((char*)self + 0xa4) = *(float*)((char*)self + 0xa4) >? seconds;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117718);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// Same function as func_00117B88(self, type, value, arg, duration): the float travels in $f12 either way,
// but the original prototype lists it before arg, which decides the argument evaluation order.
extern "C" void func_00117B88_f(void* self, int type, int value, float duration, int arg) __asm__("func_00117B88");
extern "C" void func_00119EF8(void* self, int type, int value);

struct sRaceSettings_117718 {
    char pad[0x48];
    signed char mode;       // 0x48
    signed char online;     // 0x49
};
extern sRaceSettings_117718 D_00535BC8_117718 __asm__("D_00535BC8");

// Records a trick combo (count at 0x9C, score at 0xA0) in the rider metrics and awards it.
extern "C" void func_00117718(void* self_)
{
    char* self = (char*)self_;
    int n = *(int*)(self + 0x9C);
    if (n >= 2) {
        int pts = *(int*)(self + 0xA0);
        if (pts > 0) {
            *(int*)(self + 0x198) += pts;
            *(int*)(self + 0x134) += n;
            if (*(int*)(self + 0x188) < pts)
                *(int*)(self + 0x188) = pts;
            if (*(int*)(self + 0x9C) > *(int*)(self + 0x184))
                *(int*)(self + 0x184) = *(int*)(self + 0x9C);
            cBE_getInterface_Fv(cBE_getBE(), 0);
            int offline = 0;
            if (D_00535BC8_117718.mode == 4)
                offline = D_00535BC8_117718.online == 0;
            if (!offline) {
                func_00117B88_f(self, 0x26, *(int*)(self + 0xA0), 1.5f, *(int*)(self + 0x9C));
                func_00117B88_f(self, 0x18, *(int*)(self + 0xA0), 0.7f, 0);
            } else {
                int v = *(int*)(self + 0xA0) / 500;
                func_00119EF8(self, 2, v > 20 ? 20 : v);
            }
        }
    }
    func_001175F8(self);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117838);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);

extern "C" void func_00117838(void* p)
{
    char* self = (char*)p;
    *(int*)(self + 0x14) = 0;
    *(float*)(self + 0x18) = 1.0f;
    *(int*)(self + 0x1C) = 0;
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x4) = 0;
    *(int*)(self + 0x8) = 0;
    *(int*)(self + 0xC) = 0;
    *(int*)(self + 0x10) = 0;
    *(int*)(self + 0x20) = 0;
    *(float*)(self + 0x24) = -1.0f;
    *(int*)(self + 0x28) = 0;
    *(float*)(self + 0x2C) = -1.0f;
    *(float*)(self + 0x30) = -1.0f;
    *(int*)(self + 0x34) = 0;
    *(int*)(self + 0x38) = 0;
    *(int*)(self + 0x3C) = 0;
    *(float*)(self + 0x40) = -1.0f;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5C) = 0;
    *(int*)(self + 0x70) = 0;
    *(float*)(self + 0x6C) = -1.0f;
    *(int*)(self + 0x74) = 0;
    *(float*)(self + 0x78) = -1.0f;
    *(int*)(self + 0x7C) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x84) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0x8C) = 0;
    *(int*)(self + 0x90) = 0;
    *(int*)(self + 0x94) = 0;
    *(int*)(self + 0x98) = 0;
    func_003E6448(self + 0x60, 0, 0xC);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117900__FPv);
#ifdef SKIP_ASM
float func_00117900(void* self)
{
    return *(float*)((char*)self + 0x14);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117908);
#ifdef SKIP_ASM
extern "C" int func_00117908(void* self)
{
    int v = (int)(*(float*)((char*)self + 0x1C) * 10000.0f + 5.0f);
    return v - v % 10;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117948);
#ifdef SKIP_ASM
extern "C" int func_00117948(void* self)
{
    int v = (int)(*(float*)((char*)self + 0x1C4) * *(float*)((char*)self + 0x14) * 10000.0f + 5.0f);
    return v - v % 10;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117990);
#ifdef SKIP_ASM
extern "C" int func_00117990(void* self)
{
    int v = (int)(*(float*)((char*)self + 0x1C4) * *(float*)((char*)self + 0x18) * *(float*)((char*)self + 0x14) * 10000.0f + 5.0f);
    return v - v % 10;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001179E0);
#ifdef SKIP_ASM
struct sMetrixSlot {
    int type;
    char pad_0x04[0x98];
};

struct sMetrixSlots {
    char pad_0x00[0x1B0];
    sMetrixSlot* slots;
    int count;
};

extern "C" void func_001179E0(void* self_, int type)
{
    sMetrixSlots* self = (sMetrixSlots*)self_;
    if (self->slots != 0)
    {
        if (type < 0x22)
        {
            self->slots[type].type = 0x34;
        }
        else
        {
            for (int i = 0x23; i < self->count; i++)
            {
                if (self->slots[i].type == type)
                {
                    self->slots[i].type = 0x34;
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117A58);
#ifdef SKIP_ASM
struct sMetrixSlotR {
    int type;
    float total;
    float value;
    char pad_0x0C[0x90];
};

struct sMetrixSlotsR {
    char pad_0x00[0x1B0];
    sMetrixSlotR* slots;
    int count;
};

static inline bool slotIsFreeR(const sMetrixSlotR& s)
{
    return s.type == 0x34;
}

extern "C" int func_00117A58(void* self_, int type)
{
    sMetrixSlotsR* self = (sMetrixSlotsR*)self_;
    if (type < 0x22)
    {
        return type;
    }
    float best = 1.0f;
    int bestIdx = -1;
    for (int i = 0x23; i < self->count; i++)
    {
        if (slotIsFreeR(self->slots[i]))
        {
            return i;
        }
        float r = self->slots[i].value / self->slots[i].total;
        if (r < best)
        {
            best = r;
            bestIdx = i;
        }
    }
    return bestIdx;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_00117AE8);
#ifdef SKIP_ASM
struct sMetrixSlotAE8 {
    char pad_0x00[0x9C];
};

extern "C" void func_00117048(void* slot, int a, const char* b, float c, int d);

// PORT: returns the slot index, but the unit's later declaration (used by
// cRiderMetrix_evAutoResetSurface) says void; bind the int-returning body here.
int func_00117AE8_impl(void* self, int a, const char* b, float c, int d) __asm__("func_00117AE8");

int func_00117AE8_impl(void* self, int a, const char* b, float c, int d)
{
    if (*(sMetrixSlotAE8**)((char*)self + 0x1B0) == 0)
        return -1;
    int idx = func_00117A58(self, a);
    func_00117048(&(*(sMetrixSlotAE8**)((char*)self + 0x1B0))[idx], a, b, c, d);
    return idx;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_00117B88);
#ifdef SKIP_ASM
struct sMetrixSlotB88 {
    char pad_0x00[0x9C];
};

extern "C" void func_001170A8(void* slot, int type, int value, float duration, int arg);

// PORT: returns the slot index, but the unit's later declarations say void;
// bind the int-returning body here.
int func_00117B88_impl(void* self, int type, int value, int arg, float duration) __asm__("func_00117B88");

int func_00117B88_impl(void* self, int type, int value, int arg, float duration)
{
    if (*(sMetrixSlotB88**)((char*)self + 0x1B0) == 0)
        return -1;
    int idx = func_00117A58(self, type);
    func_001170A8(&(*(sMetrixSlotB88**)((char*)self + 0x1B0))[idx], type, value, duration, arg);
    return idx;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_00117C28);
#ifdef SKIP_ASM
extern "C" void func_00117718(void*);
extern "C" void* func_0028B180();
struct sGradeStep_119210;
extern "C" int func_00119210(void* self, int* idx, sGradeStep_119210* tbl, int type, float x);
extern "C" void func_00116FB8(void* slot);
extern "C" void func_00117FE0(void* self);
extern "C" void func_00290F58(void* audio, void* rider, float mult);
extern "C" void* func_00416210(void* dst, int c, int n);
int func_0011FE98(void* rider);
int func_0011FEE8(void* rider);

extern sGradeStep_119210 D_00459E00[];
extern sGradeStep_119210 D_00459E20[];
extern sGradeStep_119210 D_00459F68[];
extern sGradeStep_119210 D_00459E40[];
extern sGradeStep_119210 D_00459F08[];

struct sVec17C28 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRider17C28 {
    char pad_0x000[0x1C0];
    sVec17C28 up;        // 0x1C0
    char pad_0x1D0[0x10];
    sVec17C28 vel;       // 0x1E0
    char pad_0x1F0[0x110];
    float timeScale;     // 0x300
};

struct sMetrixSlot17C28 {
    char pad_0x00[0x9C];
};

struct sMetrix17C28 {
    char pad_0x00[0x14];
    float mult;          // 0x14
    char pad_0x18[0x4];
    float f1C;           // 0x1C
    char pad_0x20[0x4];
    float airTime;       // 0x24
    char pad_0x28[0x4];
    float t2C;           // 0x2C
    float t30;           // 0x30
    char pad_0x34[0x8];
    float add3C;         // 0x3C
    float t40;           // 0x40
    char pad_0x44[0x28];
    float t6C;           // 0x6C
    char pad_0x70[0x8];
    float t78;           // 0x78
    char pad_0x7C[0x8];
    int points;          // 0x84
    int idx88;           // 0x88
    int idx8C;           // 0x8C
    int idx90;           // 0x90
    int idx94;           // 0x94
    int idx98;           // 0x98
    char pad_0x9C[0x8];
    float tA4;           // 0xA4
    char pad_0xA8[0xB4];
    float maxSpeed;      // 0x15C
    float maxAvg;        // 0x160
    float speedSum;      // 0x164
    float frames;        // 0x168
    char pad_0x16C[0x3C];
    float avgSpeed;      // 0x1A8
    sRider17C28* rider;  // 0x1AC
    sMetrixSlot17C28* slots; // 0x1B0
    int count;           // 0x1B4
    char clear[8];       // 0x1B8
    int dirty;           // 0x1C0
};

// PORT: PS2-only VU0 inline asm (vector length).
static inline float len17C28(const sVec17C28& v)
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

extern "C" void func_00117C28(sMetrix17C28* self)
{
    float dt = self->rider->timeScale * 0.016666668f;
    float speed = len17C28(self->rider->vel);
    if (self->tA4 >= 0.0f) {
        if (func_0011FE98(self->rider) == 0 && func_0011FEE8(self->rider) != 1) {
            self->tA4 = self->tA4 - dt;
            if (self->tA4 <= 0.0f) {
                func_00117718(self);
            }
        }
    }
    if (self->t30 >= 0.0f) {
        self->t30 += dt;
        self->points += func_00119210(self, &self->idx88, D_00459E00, 0x1C, self->t30);
    }
    if (self->t40 >= 0.0f) {
        self->t40 += dt;
        self->mult += self->add3C;
        self->points += func_00119210(self, &self->idx8C, D_00459E20, 0x20, self->t40);
    }
    if (self->airTime >= 0.0f) {
        float d = speed * dt;
        self->airTime += d;
        self->mult += d * 5e-05f;
        sVec17C28 up = self->rider->up;
        if (up.z < 0.0f) {
            self->f1C += d * 0.0002f;
        }
        self->points += func_00119210(self, &self->idx98, D_00459F68, 0x1D, self->airTime);
    }
    if (self->t2C >= 0.0f) {
        self->t2C += dt;
        self->mult += dt * 0.01f;
        self->points += func_00119210(self, &self->idx90, D_00459E40, 0x1E, self->t2C);
    }
    if (self->t6C >= 0.0f) {
        self->t6C += dt;
        self->mult += dt * 0.04999999701976776f;
    }
    if (self->t78 >= 0.0f) {
        self->t78 += dt;
        self->mult += dt * 0.04999999701976776f;
        self->points += func_00119210(self, &self->idx94, D_00459F08, 0x1F, self->t78);
    }
    self->avgSpeed = self->avgSpeed * 0.9f + speed * 0.1f;
    self->speedSum += speed;
    self->frames += 1.0f;
    if (self->maxAvg < self->avgSpeed) {
        self->maxAvg = self->avgSpeed;
    }
    if (self->maxSpeed < speed) {
        self->maxSpeed = speed;
    }
    func_00117FE0(self);
    if (self->slots != 0) {
        for (int i = 0; i < self->count; i++) {
            func_00116FB8(&self->slots[i]);
        }
    }
    func_00416210(self->clear, 0, 8);
    self->dirty = 1;
    func_00290F58(func_0028B180(), self->rider, self->mult);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00117FE0);
#ifdef SKIP_ASM
extern "C" void func_00117AE8(void* self, int a, const char* b, float c, int d);
extern "C" int func_00117908(void* self);
extern "C" int func_00117948(void* self);
extern "C" int func_00119310(void* self, int points);
extern "C" void* func_0028B180();
extern "C" void func_0029A7D8(void* audio, void* rider, int n);
extern "C" void func_0029B3C0(void* audio, void* rider);
extern "C" void func_0029B0E0(void* audio, void* rider);
extern "C" void func_00299638(void* audio, void* rider);
extern "C" void func_002997B8(void* audio, void* rider);
extern "C" float func_0012F118(void* p, int* out);
extern "C" float func_001360C8(void* p, int* out);
extern "C" float func_00135F70(void* p, int* out);
extern "C" float func_00136100(void* p);
extern "C" float func_00136168(void* p);
extern "C" int func_001298C8();
extern "C" float func_0031C040(float x);
extern "C" int func_00150960(void* a, void* b);
extern "C" void* cBE_getBE();
void* cBE_getInterface(void* be, int kind) __asm__("cBE_getInterface__Fv");
int func_0011FEE8(void* rider);
// Same functions as func_001171A8 / func_00117B88 above: the float comes before the last int in the
// original prototypes (seg_14B10 / func_00117718), which decides the argument evaluation order.
extern "C" void func_001171A8_7FE0(void* slot, int type, int value, float f, int arg) __asm__("func_001171A8");
extern "C" void func_00117B88_7FE0(void* self, int type, int value, float duration, int arg) __asm__("func_00117B88");
extern char D_00457820[]; // "STALLED!"
extern char D_00457830[]; // "OFF-AXIS!"
extern char D_00457840[]; // "INVERTED!"
extern char D_00457850[]; // "LATE SPIN!"
extern char D_00457860[]; // "LATE FLIP!"

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float truncF_7FE0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    return t;
}

// PORT: PS2-only abs.s asm helper (fabsf off-PS2).
static inline float abs_7FE0(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

struct sMetrixSlot_7FE0 {
    int type;       // 0x00 (0x34 = unused)
    float duration; // 0x04
    float elapsed;  // 0x08 (elapsed / duration = displayed fraction)
    int arg;        // 0x0C
    int f10;        // 0x10
    int value;      // 0x14
    char pad_0x18[0x84];
};

struct sVtEnt_7FE0 {
    short delta;
    short index;
    void* (*fn)(void*);
};

struct sBeing_7FE0 {
    sVtEnt_7FE0* vtbl;
};

struct sHandler_7FE0 {

    char pad_0x000[0x1F0];
    char sub1F0[0x40];      // 0x1F0
    char sub230[0x90];      // 0x230
    int f2C0;               // 0x2C0
    char pad_0x2C4[0x6C];
    float f330;             // 0x330
};

struct sRider_7FE0 {
    char pad_0x000[0x2F0];
    float f2F0;             // 0x2F0
    int f2F4;               // 0x2F4
    float f2F8;             // 0x2F8
    char pad_0x2FC[0x8];
    int f304;               // 0x304
    char pad_0x308[0x3B8];
    sBeing_7FE0 being;      // 0x6C0
    char pad_0x6C4[0xB8];
    sHandler_7FE0* handler; // 0x77C
};

struct sRiderMetrix_7FE0 {
    char pad_0x000[0x14];
    float mult;             // 0x14
    char pad_0x018[0x4];
    float f1C;              // 0x1C
    char pad_0x020[0x34];
    int f54;                // 0x54
    char pad_0x058[0x4];
    int f5C;                // 0x5C
    char pad_0x060[0x24];
    int points;             // 0x84
    char pad_0x088[0x14];
    int comboCount;         // 0x9C
    int comboScore;         // 0xA0
    float comboTimer;       // 0xA4
    char pad_0x0A8[0xF0];
    int total;              // 0x198
    char pad_0x19C[0x10];
    sRider_7FE0* rider;     // 0x1AC
    sMetrixSlot_7FE0* slots; // 0x1B0
};

static inline bool handlerInMode_7FE0(const sHandler_7FE0* h, int mode)
{
    return h->f2C0 == mode;
}

static inline bool slotIsFree_7FE0(const sMetrixSlot_7FE0& s)
{
    return s.type == 0x34;
}

// Moves cur towards target by at most step.
static inline float approach_7FE0(float target, float cur, float step)
{
    float r;
    if (target + step < cur)
        r = cur - step;
    else if (cur < target - step)
        r = cur + step;
    else
        r = target;
    return r;
}


static inline int approachI_7FE0(int target, int cur, int step)
{
    if (target + step < cur)
        return cur - step;
    if (cur < target - step)
        return cur + step;
    return target;
}

extern "C" void func_00117FE0(void* self_)
{
    sRiderMetrix_7FE0* self = (sRiderMetrix_7FE0*)self_;
    if (self->slots == 0)
        return;
    int pts = func_00117948(self);
    if (pts > 0) {
        func_00117B88_7FE0(self, 1, pts, -1.0f, func_00119310(self, pts));
        func_0029A7D8(func_0028B180(), self->rider, pts);
    }
    if (func_0011FEE8(self->rider) == 8 && !handlerInMode_7FE0(self->rider->handler, 3))
        func_001171A8_7FE0(&self->slots[11], 11, 0, self->rider->handler->f330 <? 1.0f, 0);
    else
        func_001179E0(self, 11);
    func_001179E0(self, 0x10);
    func_001179E0(self, 0x11);
    func_001179E0(self, 0x12);
    func_001179E0(self, 0x13);
    func_001179E0(self, 0x14);
    func_001179E0(self, 0x15);
    func_001179E0(self, 0x16);
    func_001179E0(self, 0x17);
    if (func_0011FEE8(self->rider) != 2 && func_0011FEE8(self->rider) != 5) {
        func_001179E0(self, 0xC);
        func_001179E0(self, 0xD);
        func_001179E0(self, 0xF);
        func_001179E0(self, 0xE);
    } else {
        int noHeading = 0;
        float heading;
        if (func_0011FEE8(self->rider) == 2)
            heading = func_0012F118(self->rider->handler->sub1F0, &noHeading);
        else
            heading = func_001360C8(self->rider->handler->sub230, &noHeading);
        if (noHeading) {
            func_001179E0(self, 0xD);
        } else {
            float wobble = func_0031C040((float)func_001298C8() * 0.10471976548433304f);
            float v = heading * 0.15915493667125702f + wobble * 0.029999999329447746f;
            if (v < 0.0f)
                v += 1.0f;
            if (!slotIsFree_7FE0(self->slots[13])) {
                float cur = self->slots[13].elapsed / self->slots[13].duration;
                float d = cur - v;
                if (0.5f < d) {
                    v = approach_7FE0(v, cur - 1.0f, 0.03333333507180214f);
                    if (v < 0.0f)
                        v += 1.0f;
                } else if (d < -0.5f) {
                    v = approach_7FE0(v, cur + 1.0f, 0.03333333507180214f);
                    if (1.0f < v)
                        v -= 1.0f;
                } else {
                    v = approach_7FE0(v, cur, 0.03333333507180214f);
                }
            }
            func_001171A8_7FE0(&self->slots[13], 13, 0, v, 0);
        }
        if (func_0011FEE8(self->rider) == 2) {
            if (noHeading)
                func_001179E0(self, 0xC);
            else
                func_00117B88_7FE0(self, 0xC, 0, -1.0f, 0);
        } else {
            int noPitch = 0;
            float pitch = func_00135F70(self->rider->handler->sub230, &noPitch);
            if (noPitch) {
                func_001179E0(self, 0xC);
                func_001179E0(self, 0xD);
                func_001179E0(self, 0xF);
                func_001179E0(self, 0xE);
            } else {
                func_00117B88_7FE0(self, 0xC, 0, -1.0f, 0);
                int id;
                int n1 = 0x34;
                int n2 = 0x34;
                int n3 = 0x34;
                int n4 = 0x34;
                if (2.7488937377929688f < abs_7FE0(pitch)) {
                    id = 0x10;
                } else if (1.9634956121444702f < pitch) {
                    id = 0x17;
                    n1 = 0x15;
                    n2 = 0x16;
                    n3 = 0x11;
                    n4 = 0x10;
                } else if (1.1780973672866821f < pitch) {
                    id = 0x16;
                } else if (0.39269912242889404f < pitch) {
                    id = 0x15;
                    n1 = 0x17;
                    n2 = 0x16;
                    n3 = 0x13;
                    n4 = 0x14;
                } else if (pitch < -1.9634956121444702f) {
                    id = 0x11;
                    n1 = 0x13;
                    n2 = 0x12;
                    n3 = 0x17;
                    n4 = 0x10;
                } else if (pitch < -1.1780973672866821f) {
                    id = 0x12;
                } else if (pitch < -0.39269912242889404f) {
                    id = 0x13;
                    n1 = 0x11;
                    n2 = 0x12;
                    n3 = 0x15;
                    n4 = 0x14;
                } else {
                    id = 0x14;
                }
                float a = func_00136100(self->rider->handler->sub230);
                float b = func_00136168(self->rider->handler->sub230);
                func_001171A8_7FE0(&self->slots[id], id, 0, 1.0f, 0);
                if (n1 != 0x34)
                    func_001171A8_7FE0(&self->slots[n1], n1, 0, a, 1);
                if (n2 != 0x34)
                    func_001171A8_7FE0(&self->slots[n2], n2, 0, a, 1);
                if (n3 != 0x34)
                    func_001171A8_7FE0(&self->slots[n3], n3, 0, b, 2);
                if (n4 != 0x34)
                    func_001171A8_7FE0(&self->slots[n4], n4, 0, b, 2);
                int prev = 0;
                if (!slotIsFree_7FE0(self->slots[14]))
                    prev = self->slots[14].arg;
                int kind = 0;
                if (noHeading == 0) {
                    float diff = pitch - heading;
                    float q = diff * 0.15915493667125702f + 0.5f;
                    float qi = truncF_7FE0(q);
                    if (q < qi)
                        qi -= 1.0f;
                    diff -= qi * 6.2831854820251465f;
                    float grade = 0.0f;
                    if (2.7488937377929688f < abs_7FE0(diff)) {
                        func_00117AE8(self, 0xE, D_00457820, -1.0f, 1);
                        kind = 1;
                        if (2.7488937377929688f < abs_7FE0(pitch) || abs_7FE0(pitch) < 0.39269912242889404f) {
                            grade = 1.0f;
                        } else {
                            grade = 2.0f;
                            if (1.1780973672866821f < abs_7FE0(pitch) && abs_7FE0(pitch) < 1.9634956121444702f)
                                grade = 5.0f;
                        }
                    } else if (1.1780973672866821f < abs_7FE0(diff)) {
                        float m = diff * pitch;
                        if ((0.0f < m && 1.5707964897155762f < abs_7FE0(pitch)) || (m < 0.0f && abs_7FE0(pitch) < 1.5707964897155762f)) {
                            if (0.10000000149011612f < b) {
                                func_00117AE8(self, 0xE, D_00457830, -1.0f, 2);
                                grade = 3.0f;
                                kind = 2;
                            }
                        } else if (0.10000000149011612f < a) {
                            func_00117AE8(self, 0xE, D_00457840, -1.0f, 3);
                            grade = 2.0f;
                            kind = 3;
                        }
                    } else if (0.39269912242889404f < abs_7FE0(diff)) {
                        if (abs_7FE0(heading) < 0.7853982448577881f || 2.3561947345733643f < abs_7FE0(heading)) {
                            func_00117AE8(self, 0xE, D_00457850, -1.0f, 4);
                            grade = 1.0f;
                            kind = 4;
                        } else {
                            grade = 2.0f;
                            func_00117AE8(self, 0xE, D_00457860, -1.0f, 5);
                            kind = 5;
                        }
                    }
                    if (grade == 0.0f) {
                        func_001179E0(self, 0xF);
                        func_001179E0(self, 0xE);
                    } else {
                        func_00117B88_7FE0(self, 0xF, (int)grade, -1.0f, 0);
                        self->f1C += grade * 0.0008333333535119891f;
                        if (kind != prev) {
                            int n = func_00117908(self);
                            int sum = self->points + n;
                            func_001171A8_7FE0(&self->slots[2], 2, sum, 0.0f, n);

                        }
                    }
                }
            }
        }
    }
    float speed;
    if (slotIsFree_7FE0(self->slots[5])) {
        speed = self->rider->f2F8;
    } else {
        float base = self->rider->f2F8;
        float v;
        if (self->rider->f304 != 3)
            v = base + self->mult;
        else
            v = base;
        speed = approach_7FE0(v <? 1.0f, self->slots[5].elapsed / self->slots[5].duration, 0.01666666753590107f);
    }
    float speed2;
    if (slotIsFree_7FE0(self->slots[6]))
        speed2 = self->rider->f2F8;
    else
        speed2 = approach_7FE0(self->rider->f2F8, self->slots[6].elapsed / self->slots[6].duration, 0.01666666753590107f);
    func_001171A8_7FE0(&self->slots[5], 5, 0, speed, 0);
    func_001171A8_7FE0(&self->slots[6], 6, 0, speed2, 0);
    if (self->rider->f2F4 == 0) {
        func_001179E0(self, 8);
    } else {
        if (slotIsFree_7FE0(self->slots[8]))
            func_001171A8_7FE0(&self->slots[8], 8, 0, 0.0f, 0);
        int n = (self->rider->f2F4 <? 10) - 1;
        float x = (float)n * 0.1111111119389534f;
        float f = approach_7FE0(x <? 1.0f, self->slots[8].elapsed / self->slots[8].duration, 0.0066666672937572f);
        func_001171A8_7FE0(&self->slots[8], 8, 0, f, n);
    }
    int room = 10 - (self->rider->f2F4 <? 10);
    if ((self->f5C != 0 || self->f54 != 0) && room > 0) {
        int c = self->f54;
        if (self->f5C != 0)
            c++;
        c = c <? room;
        if (slotIsFree_7FE0(self->slots[10])) {
            func_001171A8_7FE0(&self->slots[10], 10, 0, 0.0f, 0);
            func_0029B0E0(func_0028B180(), self->rider);
        }
        float x = (float)c * 0.1111111119389534f;
        float f = approach_7FE0(x <? 1.0f, self->slots[10].elapsed / self->slots[10].duration, 0.01666666753590107f);

        func_001171A8_7FE0(&self->slots[10], 10, 0, f, c);
    } else {
        if (!slotIsFree_7FE0(self->slots[10]))
            func_0029B3C0(func_0028B180(), self->rider);
        func_001179E0(self, 10);
    }
    if (slotIsFree_7FE0(self->slots[9])) {
        if (0.0f < self->rider->f2F0) {
            func_001171A8_7FE0(&self->slots[9], 9, 0, 0.0f, 0);
            func_00299638(func_0028B180(), self->rider);
        }
    } else {
        float cur = self->slots[9].elapsed / self->slots[9].duration;
        if (cur == 1.0f && self->rider->f2F0 == 0.0f) {
            func_001179E0(self, 9);
            func_002997B8(func_0028B180(), self->rider);
        } else {
            func_001171A8_7FE0(&self->slots[9], 9, 0, approach_7FE0(1.0f - self->rider->f2F0 * 0.05000000074505806f, cur, 0.01666666753590107f), self->rider->f2F4 <? 11);
        }
    }
    func_001171A8_7FE0(&self->slots[7], 7, self->total, 0.0f, 0);
    if (!slotIsFree_7FE0(self->slots[3])) {
        int shown = self->slots[3].value;
        float cur = self->slots[3].elapsed / self->slots[3].duration;
        func_001171A8_7FE0(&self->slots[3], 3, approachI_7FE0(self->comboScore, shown, 70), approach_7FE0(1.0f, cur, 0.01666666753590107f), self->comboCount);

        if (self->comboTimer < 0.0f)
            self->slots[3].f10 = 4;
        else
            self->slots[3].f10 = (int)(self->comboTimer * 3.266666889190674f);
    }
    int n = func_00117908(self);
    int sum = self->points + n;
    if (!slotIsFree_7FE0(self->slots[2])) {
        func_001171A8_7FE0(&self->slots[2], 2, sum,
            self->slots[2].value - self->slots[2].arg == self->points ? approach_7FE0(1.0f, self->slots[2].elapsed / self->slots[2].duration, 0.01666666753590107f) : 0.0f, n);

    } else if (sum > 0) {
        func_001171A8_7FE0(&self->slots[2], 2, sum, 0.0f, n);
    }
    void* itf = cBE_getInterface(cBE_getBE(), 0xB);
    sBeing_7FE0* being = &self->rider->being;
    sVtEnt_7FE0* vt = being->vtbl;
    int res = func_00150960(itf, vt[7].fn((char*)being + vt[7].delta));
    func_001171A8_7FE0(&self->slots[25], 25, res, 0.0f, 0);
    if (!slotIsFree_7FE0(self->slots[4])) {
        int shown = self->slots[4].value;
        func_001171A8_7FE0(&self->slots[4], 4, shown, approach_7FE0(1.0f, self->slots[4].elapsed / self->slots[4].duration, 0.01666666753590107f), 0);
    }

}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00118FF8);
#ifdef SKIP_ASM
struct sTrickId;
extern "C" void gGenTrickName(char* buf, sTrickId* id, int size);
extern "C" void func_00117AE8(void* self, int a, const char* b, float c, int d);
extern "C" void func_00309918(void* self, void* d);
extern void* D_004A3DD8;

extern "C" void func_00118FF8(void* self, sTrickId* id, int repeat)
{
    char buf[0x100];
    gGenTrickName(buf, id, 0xFF);
    func_00117AE8(self, 0, buf, 3.0f, repeat);
    func_00309918(D_004A3DD8, id);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119068);
#ifdef SKIP_ASM
struct sMetrixRecent {
    char pad_0x00[0x60];
    int recent[3];
};

extern "C" void func_00119068(void* self_, int value)
{
    sMetrixRecent* self = (sMetrixRecent*)self_;
    for (int i = 0; i < 3; i++)
    {
        if (self->recent[i] == 0)
        {
            self->recent[i] = value;
            break;
        }
        if (self->recent[i] == value && i < 2 && self->recent[i + 1] == 0)
        {
            self->recent[i] = value;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001190F0);
#ifdef SKIP_ASM
struct sTrickId;

struct sTrickId190F0 {
    int w0;
    int w1;
};

struct sTrickHist190F0 {
    char pad0[0x8];
    int u8;                       // 0x8
    char padC[0x20 - 0xC];
    int u20;                      // 0x20
    int u24;
    int u28;                      // 0x28
    char pad2C[0x70 - 0x2C];
    int u70;                      // 0x70
    char pad74[0x7C - 0x74];
    int u7C;                      // 0x7C
    char pad80[0xA8 - 0x80];
    sTrickId190F0 hist[10];       // 0xA8
    int histIdx;                  // 0xF8
};

static inline int func_trickIdEqual(const void* a, const void* b, int size)
{
    const unsigned char* p = (const unsigned char*)a;
    const unsigned char* q = (const unsigned char*)b;
    while (size--) {
        if (*p != *q) {
            return 0;
        }
        p++;
        q++;
    }
    return 1;
}

// sTrickId is defined later in the unit, hence the casts. Don't copy id_ into a typed
// local: a separate local shifts every register by one.
extern "C" int func_001190F0(void* self_, sTrickId* id_)
{
    sTrickHist190F0* self = (sTrickHist190F0*)self_;
    int count;

    if (self->u8 != 0 || self->u20 != 0 || self->u70 != 0 || self->u7C != 0 || self->u28 != 0) {
        return 0;
    }
    count = 0;
    if ((((sTrickId190F0*)id_)->w1 & 0x3F800) != 0x800 && (((sTrickId190F0*)id_)->w0 & 0xFC00000) != 0x400000) {
        for (int i = 0; i < 10; i++) {
            if (func_trickIdEqual(id_, &self->hist[i], 8)) {
                count++;
            }
        }
    }
    self->hist[self->histIdx] = *(sTrickId190F0*)id_;
    self->histIdx++;
    self->histIdx %= 10;
    return count;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119210);
#ifdef SKIP_ASM
extern "C" void func_001179E0(void* self, int type);
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);

struct sGradeStep_119210
{
    float threshold;
    float mult;
};

extern "C" int func_00119210(void* self, int* idx, sGradeStep_119210* tbl, int type, float x)
{
    // PORT: pointer arithmetic through int.
    sGradeStep_119210* e = (sGradeStep_119210*)(*idx * 8 + (int)tbl);
    float t = e->threshold;
    if (t < 0.0f) return 0;
    if (t <= x)
    {
        float m = *(float*)((char*)self + 0x1C4);
        int v = (int)(e->mult * m + 0.5f);
        *idx = *idx + 1;
        func_001179E0(self, 0x1C);
        func_001179E0(self, 0x1D);
        func_001179E0(self, 0x1E);
        func_001179E0(self, 0x1F);
        func_001179E0(self, 0x20);
        func_00117B88(self, type, v, (int)t, 1.5f);
        return v;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119310);
#ifdef SKIP_ASM
extern "C" int func_00119310(void* self, int points)
{
    if (points < 1000)
    {
        return 0;
    }
    if (points < 2500)
    {
        return 1;
    }
    if (points < 4000)
    {
        return 2;
    }
    if (points < 7500)
    {
        return 3;
    }
    if (points < 11500)
    {
        return 4;
    }
    return 5;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119368);
#ifdef SKIP_ASM
extern "C" int func_0011A7A8(void* self);

extern "C" float func_00119368(void* self, int a1)
{
    *(int*)((char*)self + 0x1A4) += func_0011A7A8(self);
    func_00117838(self);
    func_001175F8(self);
    *(int*)((char*)self + 0x120) += 1;
    if (!a1)
        return *(float*)(*(char**)((char*)self + 0x1AC) + 0x2F8) * -0.10000000149011612f;
    return *(float*)(*(char**)((char*)self + 0x1AC) + 0x2F8) * -0.699999988079071f;
}
#endif

extern "C" void func_00117718(void*);

//100%
INCLUDE_ASM("ai/ridermetrix", func_001193E0);
#ifdef SKIP_ASM
extern "C" float func_001193E0(void* self)
{
    func_00117718(self);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119400);
#ifdef SKIP_ASM
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);

extern "C" float func_00119400(char* self)
{
    *(int*)(self + 0x128) += 1;
    func_00117B88(self, 0x2C, 0, 0, 1.5f);
    return 1.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119448);
#ifdef SKIP_ASM
extern "C" void func_001171A8(void* self, int type, int value, int arg, float f);

extern "C" float func_00119448(char* self, float value)
{
    *(int*)(self + 0x130) += 1;
    char* p = *(char**)(self + 0x1B0);
    if (p != 0)
    {
        if (*(float*)(self + 0x18) < value)
        {
            func_001171A8(p + 0x270, 4, (int)value, 0, 0.0f);
            *(float*)(self + 0x18) = value;
        }
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001194C0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* func_0028B180();
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);
extern "C" int func_00238510(void* mgr, int id, int a2);
extern "C" void func_002A3CE8(void* snd, void* rider, int a2);

struct sVEntry001194C0 { short delta; short index; int (*fn)(void*); };

static inline bool rmRiderFlags_1194C0(char* r)
{
    return *(int*)(r + 0x874) != 0 && *(int*)(r + 0x87C) != 0;
}

extern "C" float func_001194C0(char* self, int a1)
{
    char* sub = *(char**)(self + 0x1AC) + 0x6C0;
    sVEntry001194C0* vt = *(sVEntry001194C0**)sub;
    if (vt[8].fn(sub + vt[8].delta) != 0)
    {
        void* mgr = *(void**)((char*)D_004A28A8 + 0xC0);
        char* sub2 = *(char**)(self + 0x1AC) + 0x6C0;
        sVEntry001194C0* vt2 = *(sVEntry001194C0**)sub2;
        if (func_00238510(mgr, vt2[7].fn(sub2 + vt2[7].delta), a1) != 0)
        {
            func_00117B88(self, 0x29, a1, 0, 2.5f);
            if (rmRiderFlags_1194C0(*(char**)(self + 0x1AC)))
            {
                func_002A3CE8(func_0028B180(), *(void**)(self + 0x1AC), 1);
            }
        }
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001195A8);
#ifdef SKIP_ASM
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);

extern "C" float func_001195A8(void* self, int value)
{
    func_00117B88(self, 0x2A, value, 0, 5.0f);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001195D8);
#ifdef SKIP_ASM
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);

extern "C" float func_001195D8(void* self, int value)
{
    func_00117B88(self, 0x2B, value, 0, 5.0f);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119608);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);
extern "C" void func_00119EF8(void* self, int kind, int amount);

// View of sGameSettings (defined later in this unit); bound to the same symbol by asm label.
struct sGameSettings_119608 {
    char pad_0x00[0x48];
    signed char eventKind; // 0x48: 4 = free ride
    signed char gameType;  // 0x49: 0 = Conquer the Mountain
};
extern sGameSettings_119608 D_00535BC8_119608 __asm__("D_00535BC8");

extern "C" float func_00119608(void* self, int pts)
{
    int v = (int)(pts * *(float*)((char*)self + 0x1C4) + 0.5f);
    cBE_getInterface(cBE_getBE(), 0);
    int career = D_00535BC8_119608.eventKind == 4 && D_00535BC8_119608.gameType == 0;
    if (!career)
    {
        func_00117B88(self, 0x23, v, 0, 2.5f);
        func_00117B88(self, 0x18, v, 0, 0.699999988079071f);
    }
    else
    {
        int amount = v / 500;
        if (amount > 20)
        {
            amount = 20;
        }
        func_00119EF8(self, 1, amount);
    }
    *(int*)((char*)self + 0x198) += v;
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119708);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int func_00150528(void* iface, int id);
int func_00150540(void* iface, int id);

extern "C" float func_00119708(char* self, int id)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 6);
    float a = func_00150528(iface, id) * 9.999999747378752e-05f;
    float b = func_00150540(iface, id) * 1.6666666624587378e-06f;
    *(float*)(self + 0x14) += a;
    *(float*)(self + 0x3C) = b;
    if (*(float*)(self + 0x40) < 0.0f)
    {
        *(float*)(self + 0x40) = 0.0f;
    }
    if (id >= 0x23)
    {
        *(int*)(self + 0x5C) = 1;
    }
    func_001176F8(self);
    return 0.0f;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_001197D8);
#ifdef SKIP_ASM
extern "C" void func_00119068(void* self_, int value);

// PORT: g++ >? (max) operator.
extern "C" float func_001197D8(void* p, int v)
{
    char* self = (char*)p;
    func_00119068(self, v);
    if (v >= 0x23)
    {
        (*(int*)(self + 0x54))++;
        if (*(int*)(*(char**)(self + 0x1AC) + 0x2F4) >= 6)
            (*(int*)(self + 0x58))++;
    }
    else if (v >= 0x13)
    {
        (*(int*)(self + 0x50))++;
    }
    else
    {
        (*(int*)(self + 0x4C))++;
    }
    float t = *(float*)(self + 0x40);
    *(float*)(self + 0x48) = t >? *(float*)(self + 0x48);
    *(int*)(self + 0x5C) = 0;
    *(float*)(self + 0x40) = -1.0f;
    *(float*)(self + 0x44) += t;
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119898);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (float absolute value).
static inline float metrixAbs_00119898(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ `>?` (max) operator. Prototype mismatch: the unit declares
// `void* func_00119898(void*)` for an existing caller, but the body takes a float in $f12.
float func_00119898_impl(void* self, float x) __asm__("func_00119898");

float func_00119898_impl(void* self, float x)
{
    *(float*)((char*)self + 0x14) -= metrixAbs_00119898(*(float*)((char*)self + 0x34)) * 0.015915492549538612f;
    *(float*)((char*)self + 0x34) = x;
    *(float*)((char*)self + 0x14) += metrixAbs_00119898(x) * 0.015915492549538612f;
    *(float*)((char*)self + 0x14) = *(float*)((char*)self + 0x14) >? 0.0f;
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_001198D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (float absolute value).
static inline float metrixAbs_001198D8(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: g++ `>?` (max) operator.
extern "C" float func_001198D8(void* self, float x)
{
    *(float*)((char*)self + 0x14) -= metrixAbs_001198D8(*(float*)((char*)self + 0x38)) * 0.028647884726524353f;
    *(float*)((char*)self + 0x38) = x;
    *(float*)((char*)self + 0x14) += metrixAbs_001198D8(x) * 0.028647884726524353f;
    *(float*)((char*)self + 0x14) = *(float*)((char*)self + 0x14) >? 0.0f;
    return 0.0f;
}
#endif

extern "C" void* func_00119898(void*);

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119918__FPvi);
#ifdef SKIP_ASM
void* func_00119918(void* self, int a1)
{
    *(int*)((char*)self + 0x20) = a1;
    return func_00119898(self);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119938__FPvii);
#ifdef SKIP_ASM
float func_00119938(void* self, int a1, int a2)
{
    *(float*)((char*)self + 0x6c) = 0.0f;
    *(int*)((char*)self + 0xc) = a2;
    *(int*)((char*)self + 0x20) = a2;
    *(int*)((char*)self + 0x70) = a1;
    *(int*)((char*)self + 0x5c) = 1;
    return *(float*)((char*)self + 0x6c);
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119958);
#ifdef SKIP_ASM
extern "C" float func_0011A228(void* self, int stance, int alternate, int style, int flag, int takeoff);

extern "C" float func_00119958(void* self, int v)
{
    float s24 = *(float*)((char*)self + 0x24);
    float s30 = *(float*)((char*)self + 0x30);
    (*(int*)((char*)self + 0x54))++;
    (*(int*)((char*)self + 0x74))++;
    float r = func_0011A228(self, 0, 0, 0, 0, 0);
    func_00117838(self);
    *(int*)((char*)self + 0xC) = v;
    *(int*)((char*)self + 0x20) = v;
    *(float*)((char*)self + 0x24) = s24;
    *(float*)((char*)self + 0x30) = s30;
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_001199F8);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
extern "C" float func_001199F8(char* self, int v)
{
    *(int*)(self + 0x10) = v;
    *(int*)(self + 0x28) = v;
    *(float*)(self + 0x2C) = *(float*)(self + 0x2C) >? 0.0f;
    func_001176F8(self);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119A38);
#ifdef SKIP_ASM
extern "C" float func_0011A228(void* self, int stance, int alternate, int style, int flag, int takeoff);

extern "C" float func_00119A38(void* self)
{
    float s24 = *(float*)((char*)self + 0x24);
    float s30 = *(float*)((char*)self + 0x30);
    int v = *(int*)((char*)self + 0x20);
    float r = func_0011A228(self, 0, 0, v, 0, s30 >= 0.0f);
    func_00117838(self);
    *(int*)((char*)self + 0xC) = v;
    *(int*)((char*)self + 0x20) = v;
    *(float*)((char*)self + 0x24) = s24;
    *(float*)((char*)self + 0x30) = s30;
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119AD8);
#ifdef SKIP_ASM
// PORT: prototype mismatch (see func_00119898).
float func_00119898_impl(void* self, float x) __asm__("func_00119898");

extern "C" float func_00119AD8(void* self, int a1)
{
    *(int*)((char*)self + 0x28) = a1;
    return func_00119898_impl(self, *(float*)((char*)self + 0x34) + 3.1415927410125732f);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_00119B08);
#ifdef SKIP_ASM
extern "C" int func_0011A7A8(void* self);
extern "C" int func_00117948(void* self);

extern "C" float func_00119B08(void* self, int flag)
{
    if (flag)
    {
        (*(int*)((char*)self + 0x12C))++;
        func_00117B88(self, 0x2D, 0, 0, 1.5f);
    }
    else
    {
        (*(int*)((char*)self + 0x124))++;
    }
    float r = 0.0f;
    *(int*)((char*)self + 0x1A0) += func_0011A7A8(self);
    if (func_00117948(self) > 0)
        r = -0.25f;
    func_00117838(self);
    func_001175F8(self);
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119BB0);
#ifdef SKIP_ASM
extern "C" float func_00119BB0(void* self, int a1)
{
    float r;
    if (a1)
    {
        func_00117B88(self, 0x21, 0, 0, 1.5f);
        r = 0.10000000149011612f;
    }
    else
        r = 0.0f;
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119BF0);
#ifdef SKIP_ASM
extern "C" float func_00119BF0(void* self, int a1)
{
    *(int*)((char*)self + 0x7C) = a1;
    *(float*)((char*)self + 0x30) = -1.0f;
    *(int*)((char*)self + 0x78) = 0;
    *(float*)((char*)self + 0x14) += 0.04999999701976776f;
    func_001176F8(self);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119C38);
#ifdef SKIP_ASM
extern "C" float func_0011A228(void* self, int stance, int alternate, int style, int flag, int takeoff);
extern "C" void func_00117838(void* self);

extern "C" float func_00119C38(void* self)
{
    *(int*)((char*)self + 0x80) += 1;
    float r = func_0011A228(self, 0, 0, 0, 0, 1);
    func_00117838(self);
    *(int*)((char*)self + 0x30) = 0;
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ai/ridermetrix", func_00119C98);
#ifdef SKIP_ASM
extern "C" void func_0011A168(void* self, int a, int b, int c, int d);

extern "C" float func_00119C98(void* self, int v)
{
    func_0011A168(self, 0, 0, 0, 0);
    if (*(float*)((char*)self + 0x14) > 0.0f)
    {
        *(int*)((char*)self + 0x0) = v;
        *(float*)((char*)self + 0x34) = 0.0f;
        *(float*)((char*)self + 0x38) = 0.0f;
        *(int*)((char*)self + 0x4) = 0;
        *(int*)((char*)self + 0xC) = 0;
        *(int*)((char*)self + 0x10) = 0;
        *(float*)((char*)self + 0x40) = -1.0f;
        *(int*)((char*)self + 0x8) = 1;
        func_003E6448((char*)self + 0x60, 0, 0xC);
    }
    func_001176F8(self);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119D40);
#ifdef SKIP_ASM
extern "C" void func_00117838(void* self);
extern "C" float func_0011A228(void* self, int stance, int alternate, int style, int flag, int takeoff);

extern "C" float func_00119D40(void* self, int stance, int alternate, int style, int flag)
{
    if (style != 0 && *(float*)((char*)self + 0x14) > 0.0f)
    {
        *(float*)((char*)self + 0x14) += 0.12999999523162842f;
    }
    int saved = *(int*)((char*)self + 0x70);
    float r = func_0011A228(self, stance, alternate, style, flag, 0);
    func_00117838(self);
    *(int*)((char*)self + 0x0) = stance;
    *(int*)((char*)self + 0x4) = alternate;
    *(int*)((char*)self + 0xC) = style;
    *(int*)((char*)self + 0x10) = flag;
    if (style != 0)
    {
        *(int*)((char*)self + 0x20) = style;
        *(int*)((char*)self + 0x24) = 0;
    }
    if (flag != 0)
    {
        *(int*)((char*)self + 0x28) = flag;
        *(int*)((char*)self + 0x2C) = 0;
    }
    if (saved != 0)
    {
        *(int*)((char*)self + 0x70) = saved;
        *(int*)((char*)self + 0x5C) = 1;
        *(int*)((char*)self + 0x6C) = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119E38);
#ifdef SKIP_ASM
extern "C" float func_0011A228(void* self, int stance, int alternate, int style, int flag, int takeoff);

extern "C" float func_00119E38(void* self, int a, int b)
{
    float r = 0.0f;
    int v20 = *(int*)((char*)self + 0x20);
    int v28 = *(int*)((char*)self + 0x28);
    if (*(int*)((char*)self + 0x70))
    {
        *(float*)((char*)self + 0x34) = r;
        *(float*)((char*)self + 0x24) = -1.0f;
        *(int*)((char*)self + 0x20) = 0;
    }
    else
    {
        r = func_0011A228(self, 0, 0, 0, 0, 1);
        func_00117838(self);
    }
    *(int*)((char*)self + 0xC) = v20;
    *(int*)((char*)self + 0x10) = v28;
    *(int*)((char*)self + 0x4) = b;
    *(int*)((char*)self + 0x0) = a;
    *(int*)((char*)self + 0x30) = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_00119EF8);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001E3760(int id, int amount);
extern "C" void func_001597B0(void* iface, int id, int amount);
int func_00117B88_i(void* self, int type, int value, int arg, float duration) __asm__("func_00117B88");

struct sVE119EF8 {
    short delta;
    short index;
    int (*fn)(void*);
};

static inline int IsBusy119EF8()
{
    int n = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
    return n != 0 && n < 10;
}

static inline int GetId119EF8(char* self)
{
    char* obj = *(char**)(self + 0x1AC) + 0x6C0;
    sVE119EF8* vt = *(sVE119EF8**)obj;
    return vt[7].fn(obj + vt[7].delta);
}

// PORT: callers in this unit declare it void; the function returns 0.0f.
float func_00119EF8_impl(char* self, unsigned int kind, int amount) __asm__("func_00119EF8");

// Awards trick/score metrics of the given kind and plays the matching reward popups.
float func_00119EF8_impl(char* self, unsigned int kind, int amount)
{
    if (amount != 0 && !IsBusy119EF8()) {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 0xD);
        func_001E3760(GetId119EF8(self), amount);
        func_001597B0(iface, GetId119EF8(self), amount);
        func_00117B88_i(self, 0x18, amount, 0, 0.7f);
        switch (kind) {
        case 3:
            func_00117B88_i(self, 0x31, amount, amount, 1.5f);
            break;
        case 1:
            func_00117B88_i(self, 0x2E, amount, 0, 2.5f);
            break;
        case 0:
            func_00117B88_i(self, 0x2F, amount, 0, 2.5f);
            break;
        case 2:
            func_00117B88_i(self, 0x30, amount, *(int*)(self + 0x9C), 2.5f);
            break;
        case 4:
            break;
        }
    }
    return 0.0f;
}
#endif

extern "C" void func_00117AE8(void* self, int a, const char* b, float c, int d);
extern const char D_00457888[];

//100%
INCLUDE_ASM("ai/ridermetrix", cRiderMetrix_evAutoResetSurface__FPv);
#ifdef SKIP_ASM
float cRiderMetrix_evAutoResetSurface(void* self)
{
    func_00117AE8(self, 0x33, D_00457888, 1.5f, 0);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A0C0__FPv);
#ifdef SKIP_ASM
float func_0011A0C0(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A0D0);
#ifdef SKIP_ASM
extern "C" float func_0011A0D0(void) {
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A0E0);
#ifdef SKIP_ASM
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);

extern "C" float func_0011A0E0(void* self)
{
    func_00117B88(self, 0x1A, 0, 0, 1.0f);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A110);
#ifdef SKIP_ASM
extern "C" void func_00119EF8(void* self, int kind, int amount);
extern "C" float func_0011A110(void* self, int amount)
{
    func_00117B88(self, 0x1B, amount, 0, 1.5f);
    func_00119EF8(self, 4, amount);
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A168);
#ifdef SKIP_ASM
struct sTrickId;
extern "C" int func_0011A8C8(void* self, sTrickId* id, int stance, int alternate, int style, int flag);
extern "C" int func_0011B1A8(void* self, sTrickId* id);
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);
extern "C" void* func_0028B180();
extern "C" void func_0029B7E0(void* audio, int rider);
extern "C" int func_001190F0(void* self, sTrickId* id);
extern "C" void func_00118FF8(void* self, sTrickId* id, int repeat);

// Same layout as sTrickId, which the unit defines after this function.
struct sTrickIdA168 {
    int w0;
    int w1;
};

extern "C" void func_0011A168(void* self, int stance, int alternate, int style, int flag)
{
    sTrickIdA168 idv;
    sTrickId* id = (sTrickId*)&idv;
    if (func_0011A8C8(self, id, stance, alternate, style, flag) != 0)
    {
        int pts = func_0011B1A8(self, id);
        if (pts > 0)
        {
            *(float*)((char*)self + 0x14) += pts * 9.999999747378752e-05f;
            func_00117B88(self, 0x32, pts, 0, 1.5f);
            func_0029B7E0(func_0028B180(), *(int*)((char*)self + 0x1AC));
        }
        func_00118FF8(self, id, func_001190F0(self, id) > 0);
    }
}
#endif

// 8-byte packed trick identity built by func_0011A8C8
struct sTrickId {
    int w0;
    int w1;
};

struct sGameSettings {
    char pad_0x00[0x48];
    signed char eventKind; // 0x48: 4 = free ride
    signed char gameType;  // 0x49: 0 = Conquer the Mountain
};

struct sScoreGrades {
    char pad_0x00[0x16c];
    int gradeCounts[6]; // 0x16c: landed tricks per grade (func_00119310)
};

extern void* D_004A28A8;
extern sGameSettings D_00535BC8;

extern "C" void func_001179E0(void* self, int type);
extern "C" int func_0012A250(void* race);
extern "C" int func_0011A8C8(void* self, sTrickId* id, int stance, int alternate, int style, int flag);
extern "C" int func_00117948(void* self);
extern "C" int func_0011B1A8(void* self, sTrickId* id);
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);
extern "C" void* func_0028B180();
extern "C" void func_0029B7E0(void* audio, int rider);
extern "C" int func_001190F0(void* self, sTrickId* id);
extern "C" void func_00118FF8(void* self, sTrickId* id, int repeat);
extern "C" int func_00117990(void* self);
extern "C" int func_00119310(void* self, int points);
extern "C" int func_00117908(void* self);
extern "C" void func_00117638(void* self, int points);
extern "C" void func_0029B430(void* audio, int rider, int ubers, int runUbers);
extern "C" void func_00119EF8(void* self, int kind, int amount);
extern "C" void func_00117708(void* self, float seconds);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int abs(int);

// g++ max operator: the target uses max.s, which only `>?` produces
#define MAX(a, b) ((a) >? (b))

// Rounds whole degrees to the nearest multiple of 180.
static inline int func_roundDegrees(int deg)
{
    int r = deg % 180;
    if (r < -90) {
        return deg - r - 180;
    }
    if (r > 90) {
        return deg - r + 180;
    }
    return deg - r;
}

// Trick landing commit: names and scores the trick that just ended, updates
// the run statistics and the combo, and returns the meter delta.
//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A228);
#ifdef SKIP_ASM
extern "C" float func_0011A228(void* self, int stance, int alternate, int style, int flag, int takeoff)
{
    sTrickId id;
    float delta;
    int valid;
    int repeats;
    int divisor;
    int pending;
    int grade;
    int inverted;
    int points;
    int total;
    int spin;
    int flip;
    int career;

    func_001179E0(self, 1);
    func_001179E0(self, 2);
    func_001179E0(self, 4);
    func_001179E0(self, 0x1c);
    func_001179E0(self, 0x1d);
    func_001179E0(self, 0x1e);
    func_001179E0(self, 0x1f);
    func_001179E0(self, 0x20);

    if (func_0012A250(*(void**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xc))) {
        return 0.0f;
    }

    valid = func_0011A8C8(self, &id, stance, alternate, style, flag);
    delta = 0.0f;
    if (func_00117948(self) > 0) {
        repeats = 0;
        if (valid) {
            int bonus = func_0011B1A8(self, &id);
            if (bonus > 0) {
                *(float*)((char*)self + 0x14) += (float)bonus * 0.0001f;
                func_00117B88(self, 0x32, bonus, 0, 1.5f);
                func_0029B7E0(func_0028B180(), *(int*)((char*)self + 0x1ac));
            }
            repeats = func_001190F0(self, &id);
            func_00118FF8(self, &id, repeats > 0);
        }
        divisor = repeats + 1;
        pending = func_00117948(self);
        points = func_00117990(self);
        grade = func_00119310(self, pending);
        inverted = func_00117908(self);
        func_00117638(self, pending / divisor);
        delta = func_00117900(self) / (float)divisor;

        points /= divisor;
        points -= points % 10;
        *(int*)((char*)self + 0x198) += points + inverted;
        *(int*)((char*)self + 0x19c) += inverted;
        *(int*)((char*)self + 0x110) += 1;
        ((sScoreGrades*)self)->gradeCounts[grade]++;

        if (*(int*)((char*)self + 0x18c) < pending) {
            *(int*)((char*)self + 0x18c) = pending;
            *(sTrickId*)((char*)self + 0x190) = id;
        }

        spin = func_roundDegrees((int)(*(float*)((char*)self + 0x34) * 57.295776f));
        flip = func_roundDegrees((int)(*(float*)((char*)self + 0x38) * 57.295776f));
        *(int*)((char*)self + 0xfc) += abs(spin);
        *(int*)((char*)self + 0x100) += abs(flip);
        *(float*)((char*)self + 0x144) += *(float*)((char*)self + 0x44);
        *(int*)((char*)self + 0x104) += *(int*)((char*)self + 0x4c);
        *(int*)((char*)self + 0x108) += *(int*)((char*)self + 0x80);

        if (*(int*)((char*)self + 0x54) > 0) {
            func_0029B430(func_0028B180(), *(int*)((char*)self + 0x1ac), *(int*)((char*)self + 0x54),
                          *(int*)((char*)self + 0x114));
        }

        *(int*)((char*)self + 0x114) += *(int*)((char*)self + 0x54);
        *(int*)((char*)self + 0x118) += *(int*)((char*)self + 0x58);
        *(int*)((char*)self + 0x11c) += *(int*)((char*)self + 0x74);
        *(float*)((char*)self + 0x14c) = MAX(*(float*)((char*)self + 0x30), *(float*)((char*)self + 0x14c));
        *(float*)((char*)self + 0x150) = MAX(*(float*)((char*)self + 0x48), *(float*)((char*)self + 0x150));
        *(float*)((char*)self + 0x154) = MAX(*(float*)((char*)self + 0x24), *(float*)((char*)self + 0x154));
        *(float*)((char*)self + 0x158) = MAX(*(float*)((char*)self + 0x78), *(float*)((char*)self + 0x158));
        *(int*)((char*)self + 0x198) += *(int*)((char*)self + 0x84);
        total = points + *(int*)((char*)self + 0x84) + inverted;

        cBE_getInterface(cBE_getBE(), 0);
        // free ride in Conquer the Mountain pays the career instead of the HUD
        career = D_00535BC8.eventKind == 4 && D_00535BC8.gameType == 0;
        if (!career) {
            if (repeats > 0) {
                func_00117B88(self, 0x24, total, grade, 2.5f);
            } else {
                func_00117B88(self, 0x23, total, grade, 2.5f);
            }
            func_00117B88(self, 0x18, total, 0, 0.7f);
        } else {
            int amount = total / 500;
            if (amount > 20) {
                amount = 20;
            }
            func_00119EF8(self, 0, amount);
        }
    }

    if (!takeoff) {
        if (style != 0 || flag != 0) {
            return delta;
        }
    } else if (*(int*)((char*)self + 0x20) != 0 || *(int*)((char*)self + 0x28) != 0) {
        return delta;
    }
    if (*(float*)((char*)self + 0x14) > 0.0f || *(float*)((char*)self + 0xa4) < 0.0f) {
        func_00117708(self, 1.5f);
    }
    return delta;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A7A8);
#ifdef SKIP_ASM
extern "C" int func_00117908(void* self);
extern "C" int func_00117948(void* self);
extern "C" void func_001179E0(void* self, int type);
extern "C" void func_00117B88(void* self, int type, int value, int arg, float duration);

extern "C" int func_0011A7A8(void* self)
{
    int n = func_00117948(self);
    if (n > 0)
    {
        func_001179E0(self, 1);
        func_00117B88(self, 0x25, n, 0, 1.5f);
    }
    if (*(int*)((char*)self + 0xA0) > 0)
    {
        func_001179E0(self, 3);
        func_00117B88(self, 0x27, *(int*)((char*)self + 0xA0), 0, 1.5f);
    }
    int total = *(int*)((char*)self + 0x84) + func_00117908(self);
    if (total > 0)
    {
        func_001179E0(self, 2);
        func_001179E0(self, 0x1D);
        func_001179E0(self, 0x1C);
        func_001179E0(self, 0x1E);
        func_001179E0(self, 0x1F);
        func_001179E0(self, 0x20);
        func_00117B88(self, 0x28, total, 0, 1.5f);
    }
    func_001179E0(self, 4);
    return n;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011A8C8);
#ifdef SKIP_ASM
struct sMetrixA8C8 {
    int a0;          // 0x00
    int a1;          // 0x04
    int a2;          // 0x08
    int a3;          // 0x0C
    int a4;          // 0x10
    char pad14[0x0C];
    int s8;          // 0x20
    float f9;        // 0x24
    int s10;         // 0x28
    float f11;       // 0x2C
    char pad30[4];
    float f13;       // 0x34
    float f14;       // 0x38
    char pad3c[0x24];
    int arr[4];      // 0x60
    int s28;         // 0x70
    char pad74[8];
    int s31;         // 0x7C
    char pad80[0x12C];
    char* rider;     // 0x1AC
};

struct sTrickBitsA8C8 {
    unsigned int w0a : 3;
    unsigned int w0b : 4;
    unsigned int w0c : 3;
    unsigned int w0d : 2;
    unsigned int w0e : 4;
    unsigned int w0f : 3;
    unsigned int w0g : 3;
    unsigned int w0h : 6;
    unsigned int w0i : 4;
    unsigned int w1a : 3;
    unsigned int w1b : 7;
    unsigned int w1c : 1;
    unsigned int w1d : 7;
    unsigned int w1e : 2;
    unsigned int w1f : 4;
    unsigned int w1g : 3;
    unsigned int w1h : 5;
};

extern "C" void func_003E6448(void* dst, int value, int size);
extern unsigned char D_0043D388[][11];
extern unsigned char D_0043D4C8[][11];

// Packs the trick that just ended (spins, flips, grabs, style) into an sTrickId;
// returns nonzero when there is a trick to score.
extern "C" int func_0011A8C8(void* self_, sTrickId* id, int stance, int alternate, int style, int flag)
{
    sMetrixA8C8* self = (sMetrixA8C8*)self_;
    sTrickBitsA8C8* t = (sTrickBitsA8C8*)id;
    func_003E6448(t, 0, 8);
    if (self->s28 != 0) {
        t->w0a = self->a3;
        t->w1a = self->s28;
        if (style != 0) {
            t->w1g = 3;
        }
        return 1;
    }
    if (self->a0 != 0) {
        self->f13 = -self->f13;
    }
    if (self->s8 == 4) {
        self->f14 = -self->f14;
    }
    int ydeg = func_roundDegrees((int)(self->f13 * 57.295776f));
    int xdeg = func_roundDegrees((int)(self->f14 * 57.295776f));
    int xc = abs(xdeg / 360);
    int yc = abs(ydeg / 180);
    if (self->s10 != 0) {
        if (yc >= 2) {
            int v;
            if (yc < 12) {
                v = 13;
                if (yc >= 6) {
                    v = 14;
                }
            } else {
                v = 15;
            }
            t->w1f = v;
        } else if (yc == 1 && self->f11 >= 3.0f) {
            int v;
            if (self->s10 == 1) {
                v = 11;
                if (self->f11 < 12.0f) {
                    v = 9;
                    if (self->f11 < 9.0f) {
                        v = 5;
                        if (self->f11 >= 6.0f) {
                            v = 7;
                        }
                    }
                }
            } else {
                v = 12;
                if (self->f11 < 12.0f) {
                    v = 10;
                    if (self->f11 < 9.0f) {
                        v = 6;
                        if (self->f11 >= 6.0f) {
                            v = 8;
                        }
                    }
                }
            }
            t->w1f = v;
        } else {
            if (self->s10 == 1) {
                t->w1f = self->s8 == 0 ? 1 : 3;
            } else {
                t->w1f = self->s8 == 0 ? 2 : 4;
            }
            t->w0b = yc < 11 ? yc : 10;
        }
        return 1;
    }
    if (self->s8 != 0) {
        if (self->f9 <= 50.0f) {
            t->w0a = 5;
        } else {
            t->w0a = self->s8;
            t->w0b = yc < 11 ? yc : 10;
            if (*(int*)(self->rider + 0x324) != 0) {
                if (self->s8 == 1) {
                    t->w0a = 2;
                } else if (self->s8 == 2) {
                    t->w0a = 1;
                }
            }
        }
        return 1;
    }
    int p = yc;
    int q = xc;
    int n = 0;
    while (xc > 0) {
        xc--;
        if (yc < 3) {
            break;
        }
        yc -= 3;
        n++;
    }
    xc = q;
    yc = p;
    if (ydeg > 0 || yc > 14) {
        p = yc + 14;
    }
    if (xdeg < 0 || xc > 5) {
        q = xc + 5;
    }
    int k = 0;
    if (self->arr[0] != 0) {
        do {
            k++;
        } while (k < 3 && self->arr[k] != 0);
    }
    if (self->a4 == 1) {
        t->w0c = 5;
    } else if (self->a4 == 2) {
        t->w0c = 6;
    } else if (self->a3 != 0) {
        if (self->a0 != 0) {
            t->w0c = 3;
        } else {
            t->w0c = 2;
        }
    } else if (self->a2 != 0) {
        t->w0c = 4;
    } else if (self->a0 != 0) {
        t->w0c = 1;
    }
    if (p < 29 && q < 11) {
        if (self->a1 != 0 && alternate != 0) {
            t->w0h = D_0043D4C8[p][q];
        } else {
            t->w0h = D_0043D388[p][q];
        }
    } else {
        func_003E6448(t, 0, 8);
        t->w0h = 1;
        return 1;
    }
    if (t->w0h == 0) {
        if (yc > 0) {
            if (ydeg > 0) {
                t->w0d = 2;
            } else {
                t->w0d = 1;
            }
        }
        if (xc == 0) {
            t->w0e = yc;
        }
        t->w0f = xc;
        if (xc > 0) {
            if (n > 0 && n == xc) {
                if (self->f14 > 0.0f) {
                    t->w0g = 4;
                } else {
                    t->w0g = 3;
                }
            } else {
                if (self->f14 > 0.0f) {
                    t->w0g = 1;
                } else {
                    t->w0g = 2;
                }
            }
        }
    }
    if (xc > 0 && yc != xc * 3 && yc < 15) {
        t->w0i = yc;
    }
    if (flag == 1) {
        t->w1g = 4;
    } else if (flag == 2) {
        t->w1g = 5;
    } else if (style != 0) {
        t->w1g = 3;
    } else if (t->w0h == 0 && (n == 0 || t->w0i != 0)) {
        if (stance != 0 && self->a0 == 0) {
            t->w1g = 2;
        } else if (yc == 0 && xc == 0 && k > 0) {
            t->w1g = 1;
        }
    }
    if (k > 0) {
        t->w1b = self->arr[0];
        if (k > 1) {
            t->w1c = 1;
            if (k == 2) {
                t->w1d = self->arr[1];
            } else {
                t->w1d = 1;
            }
        }
    }
    if (self->s31 != 0) {
        t->w1e = self->s31;
    }
    return xc > 0 || yc > 0 || k > 0 || self->s31 != 0;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011B1A8);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);

struct sTrickBonus_11B1A8
{
    int grade;              // 0x0
    int points;             // 0x4
    unsigned char a;        // 0x8
    unsigned char b;        // 0x9
    unsigned char c;        // 0xA
    unsigned char d;        // 0xB
    unsigned char e;        // 0xC
    unsigned char f;        // 0xD
    unsigned char g;        // 0xE
    unsigned char pad;      // 0xF
};
extern sTrickBonus_11B1A8 D_0043D608[];

struct sTrickBits_11B1A8
{
    unsigned int pad0 : 10;
    unsigned int a : 2;     // bits 10-11
    unsigned int b : 4;     // bits 12-15
    unsigned int c : 3;     // bits 16-18
    unsigned int d : 3;     // bits 19-21
    unsigned int pad1 : 6;
    unsigned int e : 4;     // bits 28-31
    unsigned int pad2 : 3;
    unsigned int f : 7;     // bits 3-9
    unsigned int pad3 : 1;
    unsigned int g : 7;     // bits 11-17
    unsigned int pad4 : 9;
    unsigned int grade : 5; // bits 27-31
};

extern "C" int func_0011B1A8(void* self, sTrickId* id)
{
    sTrickBits_11B1A8* t = (sTrickBits_11B1A8*)id;
    sTrickBonus_11B1A8* e = D_0043D608;
    for (int i = 0; i < 24; i++, e++)
    {
        if (t->a != e->a) continue;
        if (t->b != e->b) continue;
        if (t->c != e->c) continue;
        if (t->d != e->d) continue;
        if (t->e != e->e) continue;
        if (t->f != e->f) continue;
        if (t->g != e->g) continue;
        func_003E6448(id, 0, 8);
        t->grade = e->grade;
        return e->points;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011B2C0);
#ifdef SKIP_ASM
extern float D_004A6310[2][3][4][2];

extern "C" void func_0011B2C0(void)
{
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 3; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 2; d++) {
                    int va = a ? 0 : 5;
                    int vb = b ? (b == 1 ? 11 : 0) : 20;
                    int vc = c ? (c == 1 ? 15 : (c == 2 ? 10 : 0)) : 20;
                    int vd = d ? 0 : 5;
                    D_004A6310[a][b][c][d] = 120.0f - (float)(va + vb + vc + vd);
                }
            }
        }
    }
}
#endif

INCLUDE_ASM("ai/ridermetrix", func_0011B3F8);

extern "C" void* func_0041AA88(void* self);

//100%
INCLUDE_ASM("ai/ridermetrix", func_0011B678__FPv);
#ifdef SKIP_ASM
void* func_0011B678(void* self)
{
    return func_0041AA88(self);
}
#endif

