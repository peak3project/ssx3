#include "common.h"
#include "ai/rider.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type).
// Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// 16-byte vector with inline constructors (a non-POD sibling of t4Vector, as in ai/ai); stores x, y, z, w.
struct sVec4 : t4Vector
{
    sVec4() {}
    sVec4(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot(const t4Vector& a, const t4Vector& b)
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

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline t4Vector Scale(const t4Vector& v, float s)
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

// PORT: PS2-only VU0 inline asm (vector times scalar; Scale with a "memory" clobber).
static inline t4Vector ScaleM(const t4Vector& v, float s)
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline t4Vector Sub(const t4Vector& a, const t4Vector& b)
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

// PORT: PS2-only VU0 inline asm (vector subtract; Sub with a "memory" clobber).
static inline t4Vector SubM(const t4Vector& a, const t4Vector& b)
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

// PORT: PS2-only VU0 inline asm (vector subtract; sVec4 operands).
static inline sVec4 SubV(const sVec4& a, const sVec4& b)
{
    sVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline t4Vector Norm(const t4Vector& v)
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

// PORT: PS2-only FPU asm (absolute value).
static inline float Abs(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline t4Vector Add(const t4Vector& a, const t4Vector& b)
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

// PORT: PS2-only VU0 inline asm (vector add; Add with a "memory" clobber).
static inline t4Vector AddM(const t4Vector& a, const t4Vector& b)
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Len(const t4Vector& v)
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

// PORT: `<?` is the g++ minimum operator (EE min.s).
static inline float Clamp(float v, float lo, float hi)
{
    return (v >= lo) ? (v <? hi) : lo;
}

// PORT: PS2-only VU0 inline asm (vector divided by scalar; sVec4 operands).
static inline sVec4 DivV(const sVec4& v, float s)
{
    sVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place vector * scalar).
static inline void ScaleEq(t4Vector& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "lqc2      $vf4, %0\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (a += b).
static inline void AddEq(t4Vector& a, const t4Vector& b)
{
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

// The rider's being interface (seg/seg_1FBE38's cBeing, prototype vtable order) at rider + 0x6C0.
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
// A rider as these functions see it: its own data, then the cBeing base at 0x6C0.
struct cRiderData_1218 {
    char pad[0x6C0];
};
class cRider_1218 : public cRiderData_1218, public cBeing {
};
// The race (seg/seg_1FBE38 layout): riders by being index at 0x28.
struct sRace {
    char pad_0x0[0x28];
    cRider_1218* riders[1];     // 0x28
};
struct sNashTree;
struct sGame {
    char pad_0x0[0xC];
    sRace* race;                // 0xC
    char pad_0x10[0x10];
    sNashTree* nash;            // 0x20: the world's nash cell tree
};
// The game singleton (D_004A28A8).
struct sApp {
    char pad_0x0[0x84];
    sGame* game;                // 0x84
};
extern sApp* D_004A28A8;

// A 0x24-byte record per rider (looked up by rider index): whether it is set, distance and angle.
struct sRiderRec {
    int active;
    int pad4;
    float dist;
    float angle;
    char pad10[0x24 - 0x10];
};

// Position, direction, surface normal and speed (filled by func_001057B8 / func_00108388).
struct sInfo {
    t4Vector pos;
    t4Vector dir;
    t4Vector normal;
    float speed;
} __attribute__((aligned(16)));

// The track a rider holds at 0xAB8: Query fills up to max records near (x, y); func_0026AB20 gives a position.
struct sTrackRec {
    int type;
    int flags;
    float a;
    float b;
};
class cTrack {
public:
    char pad[0x34];
    virtual int Query(sTrackRec* buf, int max, float x, float y);
};
extern "C" t4Vector func_0026AB20(cTrack*, int, float);

// The save / load stream: slot 1 writes, slot 2 reads (func_00103480 / func_00103578 and func_00104D68 /
// func_00104DE0 are save / load pairs), ReadPtr restores a pointer, WriteInt writes one word.
struct sItem_3578;
class cStream {
public:
    virtual void Write(void* p, int n);
    virtual void Read(void* p, int n);
    virtual sItem_3578* ReadPtr();
    virtual void v04();
    virtual void WriteInt(int v);
};

// The pad word as func_0010C0A8 / func_0010C140 read it: buttons 16 and 17 and the 6-bit signed axis at 26.
struct sPadW0 {
    unsigned int pad0 : 16;
    unsigned int b16 : 1;
    unsigned int b17 : 1;
    unsigned int pad18 : 8;
    int w0 : 6;
};

// The AI state functions: the object these functions run on keeps its current state as a pointer to member
// at +0xF44 (state index at +0xF38), taken from the table D_0043CF20.
class cAiObj;
typedef void (cAiObj::*tAiState)();
extern "C" tAiState D_0043CF20[4];

// Constant vectors (in .bss, set up at startup; ai/ai's names): D_004FF130 origin (w = 1), D_004FF160 the z axis.
extern t4Vector D_004FF130;
extern t4Vector D_004FF160;

INCLUDE_ASM("seg/seg_1218", func_00100218);

// Callees and globals shared by the functions below.
extern "C" float func_0031C228(float);
extern "C" float func_00100348_0348(char* self, t4Vector* target) __asm__("func_00100348");
// PORT: the unit later declares func_00100610 with the out-pointer spelled out; same symbol, by-value return here
t4Vector func_00100610_0610(char* self) __asm__("func_00100610");
extern "C" void func_00100610(t4Vector*, void*);
extern "C" float func_00100348(void*, t4Vector*);
extern "C" int func_0010BB18_0680(void*, float*, int*) __asm__("func_0010BB18");
extern "C" int func_0010BBF8_0680(void*, int*) __asm__("func_0010BBF8");
extern "C" void func_0010C140_0680(void*, void*) __asm__("func_0010C140");
extern "C" void func_0010C0A8(void*, void*);
extern "C" int func_0010B980_0680(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6) __asm__("func_0010B980");
extern "C" int func_0010BD10(char* self, int* out);
extern "C" int func_0010B980(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6);
extern "C" void func_0010BFA8_c(char*, int, int, int, int) __asm__("func_0010BFA8");
extern "C" void func_00100680(void*, void*);
extern "C" void func_0010C140(void*, void*);
extern "C" void func_00112A50(void*, int);
extern "C" void func_00101688(void* self);
int func_001441A0(void*, void*);
extern int D_004A3DD8;
extern "C" char* cAIAnimEventMap_getBlendInTime(int id);
// PORT: the handlers are defined later in the unit with mixed parameter/return types; bind uniform views by asm label
extern "C" int func_001048C0(void* self, void* x, void* anim, float dt);
extern "C" int func_00104940(void* self, void* x, void* anim, float dt);
extern "C" int func_001049C0(void* self, void* x, void* anim, float dt);
extern "C" int f_00104110_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104110");
extern "C" int f_00104178_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104178");
extern "C" int f_00104238_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104238");
extern "C" int f_001042A8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001042A8");
extern "C" int f_00104358_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104358");
extern "C" int f_001045D8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001045D8");
extern "C" int f_00104660_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104660");
extern "C" int f_001042E0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001042E0");
extern "C" int f_001043F8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001043F8");
extern "C" int f_001045B8_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001045B8");
extern "C" int f_001047F0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001047F0");
extern "C" int f_00104728_36A0(void* self, void* x, void* anim, float dt) __asm__("func_00104728");
extern "C" int f_001046B0_36A0(void* self, void* x, void* anim, float dt) __asm__("func_001046B0");
extern "C" void func_00103AA0_36A0(void* self, void* anim) __asm__("func_00103AA0");
extern "C" int func_00104CA0_3918(void* self, void* ev, void* data) __asm__("func_00104CA0");
extern "C" int func_00104A40_3918(void* self, void* ev, void* data) __asm__("func_00104A40");
extern "C" int func_00104A60_3918(void* self, void* ev, void* data) __asm__("func_00104A60");
extern "C" int func_00104B78_3918(void* self, void* ev, void* data) __asm__("func_00104B78");
extern "C" int func_00104C18_3918(void* self, void* ev, void* data) __asm__("func_00104C18");
extern "C" int func_00104B48_3918(void* self, void* ev, void* data) __asm__("func_00104B48");
extern "C" int func_00104C38_3918(void* self, void* ev, void* data) __asm__("func_00104C38");
extern "C" int func_00104B98_3918(void* self, void* ev, void* data) __asm__("func_00104B98");
extern "C" int func_00104BB8_3918(void* self, void* ev, void* data) __asm__("func_00104BB8");
extern "C" int func_00104BD8_3918(void* self, void* ev, void* data) __asm__("func_00104BD8");
extern "C" int func_00104C80_3918(void* self, void* ev, void* data) __asm__("func_00104C80");
extern "C" bool func_001446A0(void*, int);
extern "C" bool func_001446B8(void*, int);
extern "C" void func_00144670(void*, int);
extern "C" void func_00104CC8(void*, int);
extern char* D_004A3E7C;
extern "C" void func_00313C50(void*, int, int);
extern "C" void func_00313CF0(void*, int, float);
extern "C" int func_00313800(void*, float);
extern "C" void func_003145F8(void*, void*);
extern "C" void func_00313D40(void*, int, int);
extern "C" int func_003135B0(void*, int, float);
extern "C" void func_00313D28(void*, int, float);
extern "C" int func_00103CC8_a(void*, void*, int*, int, int, int, float, float) __asm__("func_00103CC8");
extern "C" int func_00103E28(void* self, void* x, char* anim, int i0, int i1, int i2, int i3, int i4, float dt, float v);
extern "C" int func_00103CC8_42A8(void*, void*, char*, int, int, int, float, float) __asm__("func_00103CC8");
extern "C" int func_00103BE0_a(void *, void *, int *, int, int, float, float) __asm__("func_00103BE0");
extern "C" int func_00103FF8_45B8(int, int, int, int, int) __asm__("func_00103FF8");
extern "C" int func_00103CC8(void* self, void* x, char* anim, int a, int b, float dt, float w, int c);
extern "C" int func_00312B18(int, int, int*, int);
extern "C" int func_00312B18_4A60(void*, void*, int*, int) __asm__("func_00312B18");
extern "C" int func_00312BD0(void*, void*, int, int);
extern "C" int func_00312BD0_4C38(void*, void*, int*, int) __asm__("func_00312BD0");
extern "C" void func_00289B18_4CC8(void*, int, int) __asm__("func_00289B18");
extern char* D_004A3500;
extern "C" void func_00311710_4CF8(int, int, int) __asm__("func_00311710");
extern int D_004A3DFC;
extern "C" void func_003147F0(void*, cStream*);
extern "C" void func_00314668(void*);
extern "C" void func_00314880(void*, cStream*);
extern sVec4 D_004FF120;
int func_0011FEE8(void*);
int func_0011FE98(void*);
extern "C" void func_00106F78(void*);
extern "C" int func_001231A8(void*);
extern "C" void func_0016D320(void*, void*);
extern "C" void func_0032F708(void* self, int flags);
extern char D_004C5830[];
// PORT: the project names this func_0011FEC8__FPv (one param); callers pass a state too.
void func_0011FEC8_2(void* self, int v) __asm__("func_0011FEC8__FPv");
int func_00312AA0(void* anim, int ch);
extern "C" float func_00312AB0(void* anim, int ch);
extern "C" int func_00311AE8(void*, int);
extern "C" int cRiderAnimBase_play(void*, int, int, float);
extern "C" void cRider_updateOrientationImplicit(cRider* self);
extern "C" void cAirPredictor_startLaunchIntoAir_57B8(void*, const t4Vector*, const t4Vector*, float) __asm__("cAirPredictor_startLaunchIntoAir");
extern "C" void func_00108388(char* self, char* info, int flag);
extern "C" void func_00105D98(void* rider, void* info, int id);
extern "C" void func_00106538_m2537(void* rider, const t4Vector& v) __asm__("func_00106538");
extern "C" void func_001065B0(void* rider, void* hit);
extern "C" void func_0010E910(void* rider, int a, int b, int c, void* hit, float speed);
extern "C" void func_00119E38(void* metrix, int a, int b);
extern "C" void func_00329B40(void* p, const t4Vector* d);
extern "C" void func_00329AE0(int);
// PORT: the project names these __FPv (one param); callers pass a state too.
void func_0011FE78_6848(void* self, int v) __asm__("func_0011FE78__FPv");
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void cRiderAnimBase_changeHeadingOffset(void* anim, float a);
extern "C" void func_0011DFE0(cRider* self, const t4Vector& axis, float angle);
extern "C" float func_00119D40(void* metrix, int a, int b, int c, int d);
extern "C" void func_0010E098(cRider* self, int a, float f);
extern "C" void func_00115358(cRider* self);
extern "C" void func_001326C8(void*, int);
extern "C" void func_0013ADC0(void* p, t4Vector* n);
int AIrand();
extern "C" void cAirPredictor_startLaunchIntoAir(void*, const t4Vector*, const t4Vector*, float);
extern "C" void func_0010EB30_7E70(char*, int, int, int, sInfo*) __asm__("func_0010EB30");
extern "C" void func_00108388_7E70(char*, sInfo*, int) __asm__("func_00108388");
extern "C" void func_0010E468(void*, void*);
extern "C" void func_0010E2E8(void*, void*);
extern "C" void func_0010E3A8(void*, void*);
extern "C" void func_0010E228(void*, void*);
extern float D_004A4C84;
extern int D_005308D0[];
extern "C" void func_00131348(void*);
extern "C" void* func_0028B180();
extern "C" void func_002A0E70(void*, void*, int);
extern "C" int func_00334680_86B8(void*, sVec4*, sVec4*, int, float) __asm__("func_00334680");
extern "C" int func_001086B8_86B8(char* self, sVec4* tgt, sVec4* dir) __asm__("func_001086B8");
extern "C" int func_00334680(void*, t4Vector*, t4Vector*, int, float);
extern "C" char* func_00311B20(void*, int);
extern "C" int func_001086B8(void*, t4Vector*, t4Vector*);
void operator_delete(int* p);
// PORT: func_00108E88 takes the rider; declared elsewhere in this file without parameters
void func_00108E88_self(void* self) __asm__("func_00108E88");
extern "C" void func_0010CAB8(void* self);
extern "C" void func_0010D170(void* self);
extern "C" void* func_003E6448(void* dst, int value, int size);
extern "C" void func_00108E88();
extern "C" float func_0010DEF0(void* self);
extern "C" void func_00120090(void* self, float v);
extern "C" void func_0010A960_A768(void* self, void* pad) __asm__("func_0010A960");
extern "C" void func_0010AA70_A768(void* self, void* pad) __asm__("func_0010AA70");
extern "C" void func_0010B790_A768(void* self, void* pad) __asm__("func_0010B790");
extern "C" void func_0010B590_A768(void* self, void* pad) __asm__("func_0010B590");
extern "C" void func_0010AED8_A768(void* self, void* pad) __asm__("func_0010AED8");
extern "C" void func_0010B250_A768(void* self, void* pad) __asm__("func_0010B250");
extern "C" void func_0010B750_A768(void* self, void* pad) __asm__("func_0010B750");
extern "C" void func_0010AD78_A768(void* self, void* pad) __asm__("func_0010AD78");
extern "C" void func_00111AC0(char*, void*);
extern "C" void func_00111D98(void* self, void* src);
extern "C" int func_0010D1A0(void*);
extern "C" int func_0010DA10(void*);
extern "C" int func_0010DBF0(void*, int*);
extern "C" int func_0010BBF8(void*, int*);
extern "C" int func_0010BB18(void*, float*, int*);
extern "C" void func_00135CB0(void*, float*, float*);
extern "C" void func_00135DB0(void*, float*, float*);
extern "C" int func_001298C8();
extern "C" int func_0010C1D0(void*);
extern "C" void* cBE_getBE();
void* cBE_getInterface_C258(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144BE0(void* iface);

//100%
INCLUDE_ASM("seg/seg_1218", func_00100250);
#ifdef SKIP_ASM
extern "C" float func_00100250(void* self, const t4Vector* v)
{
    char* p = *(char**)((char*)self + 0x18);
    t4Vector a = *(t4Vector*)(p + 0x1A0);
    t4Vector b = *(t4Vector*)(p + 0x1C0);
    t4Vector u = Sub(*v, Scale(a, Dot(*v, a)));
    float r = -Dot(Norm(u), b);
    float f = *(float*)((char*)self + 0xDF4);
    if (f == 1.0f)
        return r;
    return r * 0.12667641043663025f * f;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00100348);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline t4Vector Cross_0348(const t4Vector& a, const t4Vector& b)
{
    t4Vector r;
    __asm__(
        "lqc2      $vf4, %1\n"
        "lqc2      $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w    $vf6, $vf6, $vf6\n"
        "sqc2      $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline float Atan2_0348(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f)
            r += 3.1415927410125732f;
        else
            r -= 3.1415927410125732f;
    }
    return r;
}

static inline cBeing* Obj_0348(char* self) { return (cBeing*)(*(char**)(self + 0x18) + 0x6C0); }

extern "C" float func_00100348_0348(char* self, t4Vector* target)
{
    t4Vector up = *(t4Vector*)(*(char**)(self + 0x18) + 0x1C0);
    if (up.z <= 0.0f)
        up = D_004FF160;
    t4Vector fwd = *Obj_0348(self)->getVelocity();
    t4Vector side = Cross_0348(fwd, up);
    t4Vector d = SubM(*target, *Obj_0348(self)->getPosition());
    d.z = 0.0f;
    d = Norm(d);
    d = Norm(SubM(d, ScaleM(up, Dot(d, up))));
    float x = Dot(d, fwd);
    float y = Dot(d, side);
    float a = Atan2_0348(y, x);
    float t = Abs(a) * 6.289702415466309f;
    if (t < 0.019999999552965164f) {
        t = 0.0f;
    } else {
        if (t > 0.9800000190734863f)
            t = 0.9800000190734863f;
        if (a < 0.0f)
            t = -t;
    }
    return t;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00100610);
#ifdef SKIP_ASM
struct sCam_0610 {
    char pad0[0x110];
    t4Vector pos;       // 0x110
    char pad120[0x490 - 0x120];
    t4Vector target;    // 0x490
    char pad4A0[0x10];
    t4Vector base;      // 0x4B0
};

t4Vector func_00100610_0610(char* self)
{
    t4Vector d = Sub((*(sCam_0610**)(self + 0x18))->target, (*(sCam_0610**)(self + 0x18))->pos);
    d = ScaleM(d, 0.1f);
    return Add((*(sCam_0610**)(self + 0x18))->base, d);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_00100680);
#ifdef SKIP_ASM
struct sPad_0680 {
    unsigned int pad0 : 17;
    unsigned int b17 : 1;
    unsigned int pad18 : 2;
    int b20 : 6;
    unsigned int pad26 : 6;
    int w0 : 6;
    int w6 : 6;
};

extern "C" void func_00100680_0680(char* self, sPad_0680* pad) __asm__("func_00100680");

extern "C" void func_00100680_0680(char* self, sPad_0680* pad)
{
    t4Vector v;
    int x;
    int y;
    int below, o3, o4, o5, o6;
    int z;
    func_00100610(&v, self);
    pad->b20 = (int)(func_00100348(self, &v) * 31.0f);
    if (func_0010BB18_0680(self, (float*)(self + 0xDF0), &x)) {
        float sp = *(float*)(self + 0xDF0);
        float len = Len(*(t4Vector*)(*(char**)(self + 0x18) + 0x1E0));
        if (sp + 138.88890075683594f < len) {
            if (x)
                pad->w0 = 0x1F;
        } else if (len < sp - 138.88890075683594f) {
            if (x)
                func_0010C140_0680(self, pad);
            else
                func_0010C0A8(self, pad);
        }
    } else if (func_0010BBF8_0680(self, &y)) {
        float s = 1.0f;
        if (y)
            s = -1.0f;
        int c = *(int*)(self + 0xE40);
        if (c == 0) {
            pad->w6 = (int)(-s * 31.0f);
            *(int*)(self + 0xE40) = 60;
        } else if (c > 0) {
            *(int*)(self + 0xE40) = c - 1;
            if (c - 1 <= 0)
                *(int*)(self + 0xE40) = -1;
            pad->w6 = (int)(-s * 31.0f);
        } else {
            pad->w6 = (int)(s * 31.0f);
        }
    } else {
        *(int*)(self + 0xE40) = 0;
        char* r = *(char**)(self + 0x18);
        if (*(float*)(r + 0x2F8) >= 0.8999999761581421f && *(float*)(r + 0x2F0) > 0.0f && *(float*)(self + 0xDF8) > 50.0f)
            pad->b17 = 1;
        func_0010C0A8(self, pad);
    }
    float* spd = (float*)(self + 0xDF0);
    z = 0;
    if (func_0010B980_0680(self, spd, &below, &o3, &o4, &o5, &o6)) {
        *(int*)(self + 0xE70) = -1;
        *(tAiState*)(self + 0xF44) = D_0043CF20[0];
        *(short*)(self + 0xF38) = 0;
    } else if (func_0010BD10(self, &z)) {
        if (z) {
            *(tAiState*)(self + 0xF44) = D_0043CF20[3];
            *(short*)(self + 0xF38) = 3;
        } else if (!((cBeing*)((char*)D_004A28A8->game->race->riders[*(int*)((char*)spd + 0x80)] + 0x6C0))->isHuman()) {
            *(tAiState*)(self + 0xF44) = D_0043CF20[2];
            *(short*)(self + 0xF38) = 2;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_001009E0);
#ifdef SKIP_ASM
struct sPad_09E0 {
    unsigned int pad0 : 14;
    unsigned int b14 : 2;
    unsigned int pad16 : 4;
    int b20 : 6;
    unsigned int pad26 : 6;
    int w0 : 6;
};

extern "C" void func_001009E0(char* self, sPad_09E0* pad)
{
    int below, o3, o4, o5, o6;
    if (!func_0010B980(self, (float*)(self + 0xDF0), &below, &o3, &o4, &o5, &o6)) {
        *(tAiState*)(self + 0xF44) = D_0043CF20[1];
        *(short*)(self + 0xF38) = 1;
        func_00100680(self, pad);
        return;
    }
    t4Vector v;
    func_00100610(&v, self);
    float f = func_00100348(self, &v);
    pad->b20 = (int)(f * 31.0f);
    char* rider = *(char**)(self + 0x18);
    float len = Len(*(t4Vector*)(rider + 0x1E0));
    if (below && *(float*)(rider + 0x4C8) < 10000.0f && Abs(f) < 1.0f) {
        func_0010BFA8_c(self, o5, o6, o4, o3);
        pad->b14 = 3;
        return;
    }
    float sp = *(float*)(self + 0xDF0);
    if (len < sp - 138.88890075683594f) {
        func_0010C140(self, pad);
        return;
    }
    if (sp + 138.88890075683594f < len)
        pad->w0 = 0x1F;
}
#endif

INCLUDE_ASM("seg/seg_1218", func_00100B90);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_00100F88);
#ifdef SKIP_ASM
struct sPad_0F88 {
    unsigned int pad0 : 20;
    int b20 : 6;
};

struct sCtl_0F88 {
    float speed;
    char pad4[0x80 - 4];
    int target;
};

// PORT: PS2-only FPU asm (float -> int -> float truncation).
static inline float Trunc_0F88(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    return t;
}

static inline float Floor_0F88(float x)
{
    float t = Trunc_0F88(x);
    if (x < t)
        t -= 1.0f;
    return t;
}

static inline sRiderRec* Rec_0F88(char* self) { return &((sRiderRec*)*(char**)(self + 0x18))[*(int*)(self + 0xE70)]; }

extern "C" void func_00100F88(char* self, sPad_0F88* pad)
{
    t4Vector v;
    int below, o3, o4, o5, o6;
    int z;
    sCtl_0F88* ctl = (sCtl_0F88*)(self + 0xDF0);
    sRiderRec* rec = Rec_0F88(self);
    cRider_1218* tgt = D_004A28A8->game->race->riders[ctl->target];
    float diff = rec->angle - *(float*)(*(char**)(self + 0x18) + 0x4CC);
    float ang = diff - Floor_0F88(diff * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
    float mySpd = Len(*(t4Vector*)(*(char**)(self + 0x18) + 0x1E0));
    float hisSpd = Len(*tgt->getVelocity());
    float steer = 0.0f;
    if (Abs(ang) > 1.5707964897155762f) {
        func_00100610(&v, self);
        steer = func_00100348(self, &v);
        if (mySpd < hisSpd)
            func_0010C140(self, pad);
        else
            func_0010C0A8(self, pad);
    } else {
        float d = Rec_0F88(self)->dist;
        float lim;
        if (d == 0.0f) {
            lim = 1.5707963705062866f;
        } else {
            lim = func_0031C228(150.0f / d);
            if (d < 0.0f)
                lim += 3.1415927410125732f;
        }
        if (Abs(ang) > lim || mySpd <= hisSpd) {
            func_00100610(&v, self);
            steer = func_00100348(self, &v);
            func_0010C0A8(self, pad);
        } else if (tgt->isComputer()) {
            if (*(int*)((char*)tgt + 0xAB8) == *(int*)(*(char**)(self + 0x18) + 0xAB8))
                func_00112A50(*(char**)(self + 0x18), 0);
            func_00100610(&v, self);
            steer = func_00100348(self, &v);
            func_0010C0A8(self, pad);
        }
    }
    pad->b20 = (int)(steer * 31.0f);
    z = 0;
    if (func_0010B980(self, (float*)(self + 0xDF0), &below, &o3, &o4, &o5, &o6)) {
        *(int*)(self + 0xE70) = -1;
        *(tAiState*)(self + 0xF44) = D_0043CF20[0];
        *(short*)(self + 0xF38) = 0;
    } else if (!func_0010BD10(self, &z)) {
        *(tAiState*)(self + 0xF44) = D_0043CF20[1];
        *(short*)(self + 0xF38) = 1;
    } else if (z) {
        *(tAiState*)(self + 0xF44) = D_0043CF20[3];
        *(short*)(self + 0xF38) = 3;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101310);
#ifdef SKIP_ASM
struct sSlotA_101310 {
    char pad[0x18];
    unsigned int id;
    sSlotA_101310() : id(0xFFFFFFFF) {}
};

struct sSlotB_101310 {
    unsigned int id;
    char pad[0xC];
    sSlotB_101310() : id(0xFFFFFFFF) {}
};

class cTable_101310 {
public:
    void* owner;
    sSlotA_101310 a[64];
    char pad704[0x50];
    sSlotB_101310 b[64];
    cTable_101310(void* o);
};

cTable_101310::cTable_101310(void* o)
{
    owner = o;
    func_00101688(this);
}
// PORT: the compiler names this ctor __13cTable_101310Pv; expose it under the address-derived name.
__asm__(".globl func_00101310\n.type func_00101310,@function\nfunc_00101310 = __13cTable_101310Pv\n.size func_00101310,0x94\n");
#endif

INCLUDE_ASM("seg/seg_1218", func_001013A8);

//100%
INCLUDE_ASM("seg/seg_1218", func_00101688);
#ifdef SKIP_ASM
struct sSlotA_101688 {
    int f0;
    int f4;
    int state;          // 0x8
    char padC[0x10];
};

struct sPair_101688 {
    int a;
    int b;
    int c;
};

struct sNode_101688 {
    int f0;
    int f4;
    int f8;
    sNode_101688* next; // 0xC
};

struct sTable_101688 {
    void* owner;                // 0x000
    sSlotA_101688 slots[64];    // 0x004
    int count;                  // 0x704
    int f708;                   // 0x708
    sPair_101688 pairs[6];      // 0x70C
    sNode_101688 nodes[64];     // 0x754
    sNode_101688* freeList;     // 0xB54
    int fB58;                   // 0xB58
    int fB5C;                   // 0xB5C
};

extern "C" void func_00101688(void* vself)
{
    sTable_101688* self = (sTable_101688*)vself;
    int i;
    self->count = 0;
    int j;
    for (j = 0; j < 64; j++)
        self->slots[j].state = 2;
    for (i = 0; i < 6; i++) {
        self->pairs[i].a = 0;
        self->pairs[i].b = 0;
    }
    for (i = 0; i < 63; i++)
        self->nodes[i].next = &self->nodes[i + 1];
    self->freeList = self->nodes;
    self->nodes[63].next = 0;
    self->fB58 = 0;
    self->fB5C = 0;
    self->f708 = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101728);
#ifdef SKIP_ASM
struct sXform_1728 {
    char pad[0x30];
    t4Vector pos;
};

class cComp_1728 {
public:
    int f0;
    int f4;
    int f8;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int IsDead();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual sXform_1728* GetXform();
};

struct sObj_1728 {
    int pad[3];
    cComp_1728* comp;
};

struct sBank_1728 {
    char pad[0x1C];
    unsigned int* handles;
};

struct sWorld_1728 {
    int pad[2];
    sBank_1728** banks;
};

struct sEnt_1728 {
    float x;
    float y;
    int state;
    float px, py, pz;
    unsigned int id;
};

struct sMgr_1728 {
    int f0;
    sEnt_1728 ents[64];
    int count;
};

extern sWorld_1728** D_004A47B8;
extern "C" void func_00101888(sMgr_1728*, unsigned int*);

static inline sObj_1728* lookup_1728(unsigned int id)
{
    sBank_1728* b = (*D_004A47B8)->banks[id & 0xFF];
    if (b) {
        unsigned int v = b->handles[id >> 8] >> 8;
        if (v)
            return (sObj_1728*)(v << 2); // PORT: packed pointer in a 32-bit handle
    }
    return 0;
}

extern "C" void func_00101728(sMgr_1728* self, unsigned int* idp, float x, float y)
{
    cComp_1728* c = lookup_1728(*idp)->comp;
    if (c == 0)
        return;
    if (c->IsDead())
        return;
    func_00101888(self, idp);
    for (int i = 0; i < 64; i++) {
        sEnt_1728* e = &self->ents[i];
        if (e->state == 2) {
            e->state = 0;
            e->id = *idp;
            e->x = x;
            e->y = y;
            t4Vector p = c->GetXform()->pos;
            e->px = p.x;
            e->py = p.y;
            e->pz = p.z;
            self->count++;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101888);
#ifdef SKIP_ASM
extern "C" void func_00101888(sMgr_1728* self, unsigned int* idp)
{
    int n = self->count;
    if (n != 0) {
        int remaining = n;
        for (int i = 0; i < 64 && remaining != 0; i++) {
            sEnt_1728* e = &self->ents[i];
            if (e->state != 2) {
                remaining--;
                if (e->id == *idp) {
                    func_001441A0(self, e);
                    return;
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101900);
#ifdef SKIP_ASM
struct N_1900 { int key; int val; int refs; N_1900 *next; };
struct P_1900 { char pad[0xB54]; N_1900 *freelist; N_1900 *used; };

extern "C" void func_00101900(P_1900 *arg0, int *arg1, int arg2) {
    N_1900 *p;
    N_1900 *n;

    for (p = arg0->used; p != 0; p = p->next) {
        if (p->key == *arg1) {
            p->refs++;
            return;
        }
    }
    n = arg0->freelist;
    arg0->freelist = n->next;
    n->key = *arg1;
    n->val = arg2;
    n->refs = 1;
    n->next = arg0->used;
    arg0->used = n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101970);
#ifdef SKIP_ASM
struct sNode_1970 { int key; int pad; int ref; sNode_1970* next; };
struct sC_1970 { int x, a, b; };
struct sSelf_1970 {
    char pad0[0x708];
    sC_1970 arrC[6];
    char pad1[0x754 - 0x750];
    char pad2[0xB54 - 0x754];
    sNode_1970* freeList;
    sNode_1970* used;
};
extern "C" void func_00101970(sSelf_1970* self, int* key) {
    sNode_1970* prev = 0;
    sNode_1970* n = self->used;
    while (n) {
        if (n->key == *key) {
            if (--n->ref == 0) {
                if (prev) prev->next = n->next;
                else self->used = n->next;
                n->next = self->freeList;
                self->freeList = n;
                if (self->used == 0) {
                    for (int k = 0; k < 6; k++) { self->arrC[k].a = 0; self->arrC[k].b = 0; }
                }
            }
            return;
        }
        prev = n;
        n = n->next;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101A10);
#ifdef SKIP_ASM
extern "C" int func_00101A10(int arg0, int arg1) {
    return (*(int *)((char*)(((arg1 * 0xC) + arg0)) + (0x710)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101A28);
#ifdef SKIP_ASM
struct sLink_1A28 {
    sLink_1A28* next;
};

struct sNode_1A28 {
    sNode_1A28* kids[8];
    sLink_1A28* items;
};

struct sList_1A28 {
    int n;
    sLink_1A28* items[1];
};

extern "C" int func_0030A310(int, sLink_1A28*);

extern "C" void func_00101A28(sList_1A28* list, sNode_1A28* node, int recurse)
{
    sLink_1A28* p;
    for (p = node->items; p; p = p->next) {
        if (func_0030A310(D_004A3DD8, p))
            list->items[list->n++] = p;
    }
    if (recurse) {
        if (node->kids[0]) func_00101A28(list, node->kids[0], 1);
        if (node->kids[1]) func_00101A28(list, node->kids[1], 1);
        if (node->kids[2]) func_00101A28(list, node->kids[2], 1);
        if (node->kids[3]) func_00101A28(list, node->kids[3], 1);
        if (node->kids[4]) func_00101A28(list, node->kids[4], 1);
        if (node->kids[5]) func_00101A28(list, node->kids[5], 1);
        if (node->kids[6]) func_00101A28(list, node->kids[6], 1);
        if (node->kids[7]) func_00101A28(list, node->kids[7], 1);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00101B60);
#ifdef SKIP_ASM
// ai/focusbox.cpp: the focus box update (prototype asserts: NumFocusInstances, numfocusinstances <
// arraysize(focusinstances), numunfocusinstances < arraysize(unfocusinstances)).
// nash::CellKey: a cell's level (log2 of its size) and integer coordinates.
struct sNashKey {
    int level;
    int x;
    int y;
    int z;
};

// One root of the nash cell tree: its key and its cell (nash::Cell = sNode_1A28: eight children, then the
// instance list).
struct sNashRoot {
    sNashKey key;
    sNode_1A28* cell;
};

struct sNashTree {
    sNashRoot roots[8];
};

// An axis-aligned focus box (the empty ctor leaves the dead `li 5; li -1` of g++'s array-ctor loop).
struct sFocusBox {
    t4Vector min;
    t4Vector max;
    sFocusBox() {}
};

// An instance record in a cell's list (tInstanceRecord): 0x100 = in focus, 0x200 = the focus pass parity.
struct tFocusRec {
    tFocusRec* next;
    int f4;
    unsigned int flags;
};

// The instances func_00101A28 collects.
struct sFocusList {
    int n;
    tFocusRec* items[512];
};

// One focus instance: the position it follows and that position at the last update.
struct sFocusInst {
    const t4Vector* pos;
    int pad[3];
    t4Vector last;
};

struct sFocusBoxes {
    int NumFocusInstances;              // 0x0
    int pad4[3];
    sFocusInst inst[6];                 // 0x10
    int lastTime;                       // 0xD0
    int parity;                         // 0xD4
    int numInstances;                   // 0xD8
    tFocusRec* instances[512];          // 0xDC
};

struct InstanceCompare {
};

extern t4Vector D_004A61E0;
extern "C" void func_00101A28_1B60(sFocusList* list, const sNode_1A28* node, int recurse) __asm__("func_00101A28");
extern "C" void func_003E6574(void* dst, void* src, int size);
extern "C" void func_0013FAD8(tFocusRec** first, tFocusRec** last, tFocusRec** out, const InstanceCompare& cmp);
extern "C" void func_0030A460(int, tFocusRec*);
extern "C" void func_0030A3A0(int, tFocusRec*);

struct FocusCallback;
// Retail's out-of-line copy of FocusCallback::operator() (matched in ai/control/handplantcontrol); the
// recursion inside the inline operator goes to it.
extern "C" void func_00144368_1B60(const FocusCallback* cb, const sNode_1A28* cell, const sNashKey* key) __asm__("func_00144368");

// FocusCallback: collects the instances of every cell that touches one of the focus boxes.
struct FocusCallback {
    sFocusList* list;
    sFocusBox* boxes;
    int count;

    void operator()(const sNode_1A28& cell, const sNashKey& key) const
    {
        int i = 0;
        for (;;) {
            if (i == count) {
                return;
            }
            union { int i; float f; } u;
            u.i = (key.level + 0x7F) << 23;
            float s = u.f;
            int ok = 0;
            if (((float)key.x - 0.2f) * s <= boxes[i].max.x && ((float)key.y - 0.2f) * s <= boxes[i].max.y && ((float)key.z - 0.2f) * s <= boxes[i].max.z
                && boxes[i].min.x <= ((float)(key.x + 1) + 0.2f) * s && boxes[i].min.y <= ((float)(key.y + 1) + 0.2f) * s && boxes[i].min.z <= ((float)(key.z + 1) + 0.2f) * s) {
                ok = 1;
            }
            if (ok) {
                goto found;
            }
            i++;
        }
    found:
        int leaf = key.level < 14;
        func_00101A28_1B60(list, &cell, leaf);
        if (leaf) {
            return;
        }
        if (key.level == 11) {
            return;
        }
        sNashKey k;
        k.level = key.level - 1;
        k.x = key.x * 2;
        k.y = key.y * 2;
        k.z = key.z * 2;
        if (cell.kids[0]) func_00144368_1B60(this, cell.kids[0], &k);
        k.x++;
        if (cell.kids[4]) func_00144368_1B60(this, cell.kids[4], &k);
        k.y++;
        if (cell.kids[6]) func_00144368_1B60(this, cell.kids[6], &k);
        k.x--;
        if (cell.kids[2]) func_00144368_1B60(this, cell.kids[2], &k);
        k.z++;
        if (cell.kids[3]) func_00144368_1B60(this, cell.kids[3], &k);
        k.x++;
        if (cell.kids[7]) func_00144368_1B60(this, cell.kids[7], &k);
        k.y--;
        if (cell.kids[5]) func_00144368_1B60(this, cell.kids[5], &k);
        k.x--;
        if (cell.kids[1]) func_00144368_1B60(this, cell.kids[1], &k);
    }
};

// Visit root k of the tree (same shape as intersect/worldsphtree's visit helpers: the root's address is
// taken before the test).
static inline void Visit(const FocusCallback& cb, const sNashTree* tree, int k)
{
    const sNashRoot* r = &tree->roots[k];
    if (tree->roots[k].cell) {
        cb(*r->cell, r->key);
    }
}

extern "C" void func_00101B60(sFocusBoxes* self)
{
    sFocusList list;
    list.n = 0;
    int moved = 0;
    sFocusBox boxes[6];
    for (int i = 0; i < self->NumFocusInstances; i++) {
        t4Vector p = *self->inst[i].pos;
        boxes[i].min = Sub(p, D_004A61E0);
        boxes[i].max = Add(p, D_004A61E0);
        if (Len(Sub(self->inst[i].last, p)) >= 2000.0f) {
            moved = 1;
        }
    }
    if (!moved && self->lastTime >= 0 && func_001298C8() - self->lastTime < 20) {
        return;
    }
    if (self->NumFocusInstances != 0) {
        sNashTree* tree = D_004A28A8->game->nash;
        FocusCallback cb;
        cb.list = &list;
        cb.boxes = boxes;
        cb.count = self->NumFocusInstances;
        Visit(cb, tree, 0);
        Visit(cb, tree, 1);
        Visit(cb, tree, 2);
        Visit(cb, tree, 3);
        Visit(cb, tree, 4);
        Visit(cb, tree, 5);
        Visit(cb, tree, 6);
        Visit(cb, tree, 7);
    }
    self->lastTime = func_001298C8();
    for (int i = 0; i < self->NumFocusInstances; i++) {
        t4Vector p = *self->inst[i].pos;
        self->inst[i].last = p;
    }
    tFocusRec* focusinstances[256];
    tFocusRec* unfocusinstances[256];
    int numfocusinstances = 0;
    int numunfocusinstances = 0;
    self->parity ^= 1;
    for (int i = 0; i < list.n; i++) {
        tFocusRec* r = list.items[i];
        if (!(r->flags & 0x100)) {
            focusinstances[numfocusinstances++] = r;
            r->flags |= 0x100;
        }
        if (self->parity) {
            r->flags &= ~0x200;
        } else {
            r->flags |= 0x200;
        }
    }
    for (int i = 0; i < self->numInstances; i++) {
        tFocusRec* r = self->instances[i];
        if (((r->flags & 0x200) == 0) != self->parity) {
            unfocusinstances[numunfocusinstances++] = r;
            r->flags &= ~0x100;
        }
    }
    self->numInstances = list.n;
    func_003E6574(self->instances, list.items, list.n << 2);
    tFocusRec* sorted[256];
    if (numunfocusinstances) {
        func_0013FAD8(unfocusinstances, unfocusinstances + numunfocusinstances, sorted, InstanceCompare());
        for (int i = 0; i < numunfocusinstances; i++) {
            func_0030A460(D_004A3DD8, sorted[i]);
        }
    }
    if (numfocusinstances) {
        func_0013FAD8(focusinstances, focusinstances + numfocusinstances, sorted, InstanceCompare());
        for (int i = 0; i < numfocusinstances; i++) {
            func_0030A3A0(D_004A3DD8, sorted[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001032C0);
#ifdef SKIP_ASM
struct S_32C0 {
    char pad[0xD4];
    int flag;
    int n;
    void *arr[8];
};

extern "C" void func_001032C0(S_32C0 *arg0, void *arg1) {
    int temp_3;
    int temp_6;
    int var_2;
    int n;

    temp_3 = (*(int *)((char*)(arg1) + (8)));
    temp_6 = temp_3 | 0x100;
    (*(int *)((char*)(arg1) + (8))) = temp_6;
    if (arg0->flag != 0) {
        var_2 = temp_6 & 0xFFFFFDFF;
    } else {
        var_2 = temp_3 | 0x300;
    }
    (*(int *)((char*)(arg1) + (8))) = var_2;
    n = arg0->n;
    arg0->arr[n] = arg1;
    arg0->n = n + 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103308);
#ifdef SKIP_ASM
struct S_3308 { char pad[0xD8]; int cnt; void *arr[8]; };
extern "C" void func_00103308(S_3308 *arg0, int arg1) {
    int n = 0;
    int i;

    for (i = 0; i < arg0->cnt; i++) {
        void *e = arg0->arr[i];
        if (*(unsigned char *)((char*)e + 0x78) != arg1) {
            arg0->arr[n] = e;
            n++;
        }
    }
    arg0->cnt = n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103358);
#ifdef SKIP_ASM
struct S_3358 { char pad[0xD0]; int f_d0; int pad2; int cnt; void *arr[8]; };
extern "C" void func_00103358(S_3358 *arg0) {
    int i;

    for (i = 0; i < arg0->cnt; i++) {
        *(int *)((char*)arg0->arr[i] + 8) &= 0xFFFFFEFF;
    }
    arg0->cnt = 0;
    arg0->f_d0 = -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001033B0);
#ifdef SKIP_ASM
struct V_33B0 { int x, y, z, w; } __attribute__((aligned(16)));

extern "C" void func_001033B0(void *arg0, V_33B0 *arg1) {
    V_33B0 sp0;

    (*(int *)((char*)(arg0) + (0xD0))) = -1;
    (*(V_33B0 **)((char*)(arg0) + ((*(int *)((char*)(arg0) + (0))) << 5) + (0x10))) = arg1;
    sp0 = *arg1;
    (*(V_33B0 *)((char*)((((*(int *)((char*)(arg0) + (0))) << 5) + (int)arg0)) + (0x20))) = sp0;
    (*(int *)((char*)(arg0) + (0))) = (int) ((*(int *)((char*)(arg0) + (0))) + 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001033F8);
#ifdef SKIP_ASM
struct sEntry1033F8 {
    int id;
    int data[7];
} __attribute__((aligned(16)));

struct sList1033F8 {
    int count;
    char pad4[0xC];
    sEntry1033F8 entries[6];    // 0x10
    int fD0;                    // 0xD0
};

// Removes the entry with the given id from the list, shifting the rest down.
extern "C" void func_001033F8(sList1033F8* self, int id)
{
    int i;
    self->fD0 = -1;
    for (i = 0; i < self->count; i++) {
        if (self->entries[i].id == id) {
            for (i++; i < self->count; i++) {
                self->entries[i - 1] = self->entries[i];
            }
            self->count--;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103480);
#ifdef SKIP_ASM
struct sEnt_3480 {
    char d[0x20];
};

struct sObj_3480 {
    int n;
    char pad4[0x1C];
    sEnt_3480 ents[5];
    char padC0[0x10];
    int fD0;
    int pad;
    int m;
    int vals[1];
};

extern "C" void func_00103480(sObj_3480* self, cStream* s)
{
    s->Write(&self->fD0, 4);
    for (int i = 0; i < self->n; i++)
        s->Write(&self->ents[i], 0x10);
    s->Write(&self->m, 4);
    for (int j = 0; j < self->m; j++)
        s->WriteInt(self->vals[j]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103578);
#ifdef SKIP_ASM
struct sItem_3578 {
    int f0;
    int f4;
    unsigned int flags;
};

struct sEnt_3578 {
    char d[0x20];
};

struct sObj_3578 {
    int n;
    char pad4[0x1C];
    sEnt_3578 ents[5];
    char padC0[0x10];
    int fD0;
    int fD4;
    int m;
    sItem_3578* items[1];
};

extern "C" void func_00103578(sObj_3578* self, cStream* s)
{
    s->Read(&self->fD0, 4);
    for (int i = 0; i < self->n; i++)
        s->Read(&self->ents[i], 0x10);
    self->fD4 = 1;
    s->Read(&self->m, 4);
    for (int j = 0; j < self->m; j++) {
        sItem_3578* it = s->ReadPtr();
        it->flags = (it->flags | 0x100) & 0xFFFFFDFF;
        self->items[j] = it;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001036A0);
#ifdef SKIP_ASM
extern "C" void func_001036A0(char* self, void* x, int* anim, float dt)
{
    int done = 0;
    switch (*(int*)(cAIAnimEventMap_getBlendInTime(*anim) + 4)) {
    case 0:
        done = func_001048C0(self, x, anim, dt);
        break;
    case 1:
        done = func_00104940(self, x, anim, dt);
        break;
    case 2:
        done = func_001049C0(self, x, anim, dt);
        break;
    case 3:
        done = f_00104110_36A0(self, x, anim, dt);
        break;
    case 4:
        done = f_00104178_36A0(self, x, anim, dt);
        break;
    case 5:
        done = f_00104238_36A0(self, x, anim, dt);
        break;
    case 6:
        done = f_001042A8_36A0(self, x, anim, dt);
        break;
    case 7:
        done = f_00104358_36A0(self, x, anim, dt);
        break;
    case 8:
        done = f_001045D8_36A0(self, x, anim, dt);
        break;
    case 9:
        done = f_00104660_36A0(self, x, anim, dt);
        break;
    case 10:
        done = f_001042E0_36A0(self, x, anim, dt);
        break;
    case 11:
        done = f_001043F8_36A0(self, x, anim, dt);
        break;
    case 12:
        done = f_001045B8_36A0(self, x, anim, dt);
        break;
    case 13:
        done = f_001047F0_36A0(self, x, anim, dt);
        break;
    case 14:
        done = f_00104728_36A0(self, x, anim, dt);
        break;
    case 15:
        done = f_001046B0_36A0(self, x, anim, dt);
        break;
    }
    if (done == 0) {
        char* r = *(char**)(self + 0x60);
        if (r != 0) {
            int ok = 0;
            if (*(int*)(r + 0x874) != 0) {
                ok = *(int*)(r + 0x87C) != 0;
            }
            if (ok) {
                func_00103AA0_36A0(self, anim);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103918);
#ifdef SKIP_ASM
struct sEvent3918 { int a; int b; };

struct sEventOwner3918 {
    int results[20];        // 0x00
    sEvent3918* events;     // 0x50
};

// Runs the handler for an animation event's type and stores its result in the per-event slot.
extern "C" void func_00103918(sEventOwner3918* self, sEvent3918* ev, int* data)
{
    int idx = ev - self->events;
    char* info = cAIAnimEventMap_getBlendInTime(*data);
    switch (*(int*)(info + 8)) {
    case 0:
        self->results[idx] = func_00104CA0_3918(self, ev, data);
        break;
    case 1:
        self->results[idx] = func_00104A40_3918(self, ev, data);
        break;
    case 2:
        self->results[idx] = func_00104A60_3918(self, ev, data);
        break;
    case 3:
        self->results[idx] = func_00104B78_3918(self, ev, data);
        break;
    case 4:
        self->results[idx] = func_00104C18_3918(self, ev, data);
        break;
    case 5:
        self->results[idx] = func_00104B48_3918(self, ev, data);
        break;
    case 6:
        self->results[idx] = func_00104C38_3918(self, ev, data);
        break;
    case 7:
        self->results[idx] = func_00104B98_3918(self, ev, data);
        break;
    case 8:
        self->results[idx] = func_00104BB8_3918(self, ev, data);
        break;
    case 9:
        self->results[idx] = func_00104BD8_3918(self, ev, data);
        break;
    case 10:
        self->results[idx] = func_00104C80_3918(self, ev, data);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103AA0);
#ifdef SKIP_ASM
struct sEnt_3AA0 {
    char pad[0x10];
    unsigned short first;
    unsigned short count;
};

struct sRec_3AA0 {
    unsigned short a;
    unsigned short b;
};

struct sBank_3AA0 {
    int pad[2];
    sEnt_3AA0* ents;
    int padC;
    sRec_3AA0* recs;
};

struct sObj_3AA0 {
    int f0;
    unsigned int id;
    char pad[0xA8];
    char sub[1];
};

struct sBankTab_3AA0 {
    sBank_3AA0* banks[1];
};

extern sBankTab_3AA0* D_004A3DF8;

extern "C" void func_00103AA0(void* self, sObj_3AA0* o)
{
    int n = D_004A3DF8->banks[o->id & 0xFF]->ents[o->id >> 8].count;
    for (int i = 0; i < n; i++) {
        int ok = 0;
        if (func_001446A0(o->sub, i) && func_001446B8(o->sub, i))
            ok = 1;
        if (ok) {
            sBank_3AA0* b = D_004A3DF8->banks[o->id & 0xFF];
            unsigned short r = b->recs[b->ents[o->id >> 8].first + i].b;
            if (r & 0x8000) {
                func_00144670(o->sub, i);
                func_00104CC8(self, r & 0x7FFF);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103BE0);
#ifdef SKIP_ASM
extern "C" int func_00103BE0(void* self, void* x, char* anim, int a, int b, float dt, float v)
{
    if (v < 0.0f) {
        func_00313C50(anim, 0, *(int*)(D_004A3E7C + b * 4 + 0x1030));
        func_00313CF0(anim, 0, -v * *(float*)(anim + 0x10));
    } else {
        func_00313C50(anim, 0, *(int*)(D_004A3E7C + a * 4 + 0x1030));
        func_00313CF0(anim, 0, v * *(float*)(anim + 0x10));
    }
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103CC8);
#ifdef SKIP_ASM
extern "C" int func_00103CC8(void* self, void* x, char* anim, int a, int b, float dt, float w, int c)
{
    func_00313C50(anim, 0, *(int*)(D_004A3E7C + b * 4 + 0x1030));
    if (0.0f < w) {
        func_00313C50(anim, 1, *(int*)(D_004A3E7C + c * 4 + 0x1030));
    } else {
        w = -w;
        func_00313C50(anim, 1, *(int*)(D_004A3E7C + a * 4 + 0x1030));
    }
    func_00313D28(anim, 0, 1.0f - w);
    func_00313D28(anim, 1, w);
    func_00313D40(anim, 0, 1);
    float t = dt * 0.01666666753590107f;
    func_003135B0(anim, 0, t);
    func_00313CF0(anim, 1, *(float*)(anim + 8) / *(float*)(anim + 0x10) * *(float*)(anim + 0x2C));
    if (func_00313800(anim, t)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103E28);
#ifdef SKIP_ASM
extern "C" int func_00103E28(void* self, void* x, char* anim, int i0, int i1, int i2, int i3, int i4, float dt, float v)
{
    int from, to;
    float w;
    if (v > 0.5f) {
        from = i4;
        to = i3;
        w = (v - 0.5f) * 2.0f;
    } else if (v > 0.0f) {
        from = i3;
        to = i2;
        w = v * 2.0f;
    } else if (v > -0.5f) {
        from = i2;
        to = i1;
        w = v * 2.0f + 1.0f;
    } else {
        from = i1;
        to = i0;
        w = (v + 1.0f) * 2.0f;
    }
    if (*(int*)(D_004A3E7C + from * 4 + 0x1030) != *(int*)(anim + 4)) {
        float r = *(float*)(anim + 8) / *(float*)(anim + 0x10);
        func_00313C50(anim, 0, *(int*)(D_004A3E7C + from * 4 + 0x1030));
        func_00313CF0(anim, 0, *(float*)(anim + 0x10) * r);
    }
    func_00313C50(anim, 1, *(int*)(D_004A3E7C + to * 4 + 0x1030));
    func_00313D28(anim, 0, w);
    func_00313D28(anim, 1, 1.0f - w);
    func_00313D40(anim, 0, 1);
    float t = dt * 0.01666666753590107f;
    func_003135B0(anim, 0, t);
    func_00313CF0(anim, 1, *(float*)(anim + 8) / *(float*)(anim + 0x10) * *(float*)(anim + 0x2C));
    if (func_00313800(anim, t)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00103FF8);
#ifdef SKIP_ASM
extern "C" int func_00103FF8(void* self, void* x, char* anim, int a, float dt, int b)
{
    if (*(int*)(anim + 4) == *(int*)(D_004A3E7C + a * 4 + 0x1030)) {
        func_00313D40(anim, 0, 0);
        func_003135B0(anim, 0, dt * 0.01666666753590107f);
        if (*(float*)(anim + 8) >= *(float*)(anim + 0x10)) {
            func_00313C50(anim, 0, *(int*)(D_004A3E7C + b * 4 + 0x1030));
            func_00313D40(anim, 0, 1);
            func_00313CF0(anim, 0, 0.0f);
        }
    } else {
        func_003135B0(anim, 0, dt * 0.01666666753590107f);
    }
    if (func_00313800(anim, dt * 0.01666666753590107f)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104110);
#ifdef SKIP_ASM
extern "C" int func_00104110(void *arg0, void *a1, int *arg2, float f12) {
    float var_f13;
    void *temp_3;

    temp_3 = (*(void **)((char*)(arg0) + (0x60)));
    var_f13 = (*(float *)((char*)(temp_3) + (0x1FC)));
    if ((*(int *)((char*)(temp_3) + (0x320))) != 0) {
        var_f13 = -var_f13;
    }
    if (*arg2 == 7) {
        return func_00103CC8_a(arg0, a1, arg2, 0x11, 0xF, 0x10, f12, var_f13);
    }
    if (*arg2 == 0xA) {
        return func_00103CC8_a(arg0, a1, arg2, 0x1A, 0x17, 0x19, f12, var_f13);
    }
    return func_00103CC8_a(arg0, a1, arg2, 0x1A, 0x18, 0x19, f12, var_f13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104178);
#ifdef SKIP_ASM
extern "C" int func_00104178(char* self, void* x, int* anim, float dt)
{
    char* p = *(char**)(self + 0x60);
    float v = *(float*)(p + 0x1FC);
    if (*(int*)(p + 0x320) != 0)
        v = -v;
    int a, b, c, d, e;
    int s = *anim;
    if (s == 6) {
        a = 0xE; b = 0xD; c = 0xA; d = 0xB; e = 0xC;
    } else if (s == 8) {
        a = 0x16; b = 0x15; c = 0x12; d = 0x13; e = 0x14;
    } else if (s == 14) {
        a = 0x20; b = 0x1F; c = 0x1B; d = 0x1D; e = 0x1E;
    } else if (s != 15) {
        a = 9; b = 8; c = 5; d = 6; e = 7;
    } else {
        a = 0x20; b = 0x1F; c = 0x1C; d = 0x1D; e = 0x1E;
    }
    return func_00103E28(self, x, (char*)anim, a, b, c, d, e, dt, v);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104238);
#ifdef SKIP_ASM
extern "C" int func_00104238(void *arg0, void *a1, int *arg2, float f12) {
    int var_7;
    int var_8;
    int var_9;
    float var_f13;
    void *temp_3;

    temp_3 = (*(void **)((char*)(arg0) + (0x60)));
    var_f13 = (*(float *)((char*)(temp_3) + (0x238)));
    if ((*(int *)((char*)(temp_3) + (0x320))) != 0) {
        var_f13 = -var_f13;
    }
    switch (*arg2) {
    case 0x12:
        var_7 = 0x41;
        var_8 = 0x3F;
        var_9 = 0x40;
        break;
    default:
        var_7 = 0x47;
        var_8 = 0x45;
        var_9 = 0x46;
        break;
    case 0x13:
        var_7 = 0x44;
        var_8 = 0x42;
        var_9 = 0x43;
        break;
    }
    return func_00103CC8_a(arg0, a1, arg2, var_7, var_8, var_9, f12, var_f13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001042A8);
#ifdef SKIP_ASM
extern "C" int func_001042A8(void *arg0, void *a1, char *a2, float dt) {
    float var_f13;
    void *temp_3;

    temp_3 = (*(void **)((char*)(arg0) + (0x60)));
    var_f13 = (*(float *)((char*)(temp_3) + (0x214)));
    if ((*(int *)((char*)(temp_3) + (0x320))) == 0) {
        var_f13 = -var_f13;
    }
    return func_00103CC8_42A8(arg0, a1, a2, 0x24, 0x21, 0x22, dt, var_f13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001042E0);
#ifdef SKIP_ASM
extern "C" int func_001042E0(void *arg0, void *a1, int *arg2, float f12) {
    int x = *arg2;
    if (x == 0xDA) {
        return func_00103BE0_a(arg0, a1, arg2, 0x16A, 0x16B, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
    }
    if (x == 0xE2) {
        return func_00103BE0_a(arg0, a1, arg2, 0x173, 0x174, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
    }
    if (x == 0xEA) {
        return func_00103BE0_a(arg0, a1, arg2, 0x17C, 0x17D, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
    }
    return func_00103BE0_a(arg0, a1, arg2, 0x185, 0x186, f12, (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x238))));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104358);
#ifdef SKIP_ASM
extern "C" int func_00104358(char* self, void* x, char* anim, float dt) {
    char* p = *(char**)(self + 0x60);
    float b = Abs(*(float*)(p + 0x2A4));
    float a = Abs(*(float*)(p + 0x2B0));
    float m = (a < b) ? b : a;
    func_00313CF0(anim, 0, m * *(float*)(anim + 0x10));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001043F8);
#ifdef SKIP_ASM
extern "C" int func_001043F8(char* self, void* x, char* anim, float dt)
{
    int slot = 0xA5;
    switch (*(int*)anim) {
    case 0x129: slot = 0xA5; break;
    case 0x12A: slot = 0xAB; break;
    case 0x12B: slot = 0xA8; break;
    case 0x12C: slot = 0xAC; break;
    case 0x12D: slot = 0xA6; break;
    case 0x12E: slot = 0xAA; break;
    case 0x12F: slot = 0xA7; break;
    case 0x130: slot = 0xA9; break;
    }
    func_00313C50(anim, 1, *(int*)(D_004A3E7C + slot * 4 + 0x1030));
    func_00313D40(anim, 1, 1);
    char* rider = *(char**)(self + 0x60);
    float b = Abs(*(float*)(rider + 0x298));
    float a = Abs(*(float*)(rider + 0x28C));
    float m = (a < b) ? b : a;
    m = Clamp(m, 0.0f, 1.0f);
    float w = m * 0.75f + 0.25f;
    func_00313D28(anim, 0, 1.0f - w);
    func_00313D28(anim, 1, w);
    func_00313CF0(anim, 0, m * *(float*)(anim + 0x10));
    float t = dt * 0.01666666753590107f;
    func_003135B0(anim, 1, t);
    if (func_00313800(anim, t)) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001045B8);
#ifdef SKIP_ASM
extern "C" int func_001045B8(int a, int b, int c) {
    return func_00103FF8_45B8(a, b, c, 0x89, 0x8A);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001045D8);
#ifdef SKIP_ASM
extern "C" int func_001045D8(char* self, void* x, char* anim, float dt) {
    func_00313CF0(anim, 0, *(float*)(anim + 0x10) * *(float*)(*(char**)(*(char**)(self + 0x60) + 0x77C) + 0x2A0));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104660);
#ifdef SKIP_ASM
extern "C" int func_00104660(void *arg0, void *arg1, int *arg2, float f12) {
    float w = (*(float *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x244)));

    if (*arg2 == 0x2D) {
        return func_00103BE0_a(arg0, arg1, arg2, 0x161, 0x160, f12, w);
    }
    return func_00103BE0_a(arg0, arg1, arg2, 0x15B, 0x15A, f12, w);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001046B0);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
extern "C" int func_001046B0(char* self, void* x, int* anim, float dt)
{
    float v = *(float*)(*(char**)(self + 0x60) + 0x274);
    v = v + v - 1.0f;
    float w;
    if (v >= -1.0f) {
        w = v <? 1.0f;
    } else {
        w = -1.0f;
    }
    int a, b, c;
    a = 0x3C;
    if (*anim != 0x1C) {
        b = 0x3A; c = 0x3B;
    } else {
        a = 0x31; b = 0x30; c = 0x32;
    }
    return func_00103CC8(self, x, (char*)anim, a, b, dt, w, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104728);
#ifdef SKIP_ASM
extern "C" int func_00104728(char* self, void* x, char* anim, float dt) {
    float v;
    int s = *(int*)anim;
    if (s == 0x19 || s == 0x21) {
        v = Clamp(1.0f - *(float*)(*(char**)(self + 0x60) + 0x268), 0.0f, 1.0f);
    } else {
        v = *(float*)(*(char**)(self + 0x60) + 0x268);
    }
    func_00313CF0(anim, 0, v * *(float*)(anim + 0x10));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001047F0);
#ifdef SKIP_ASM
extern "C" int func_001047F0(char* self, void* x, char* anim, float dt) {
    float v;
    int s = *(int*)anim;
    if (s == 0x25) {
        v = 1.0f - Abs(*(float*)(*(char**)(self + 0x60) + 0x280));
    } else if (s == 0x26) {
        v = 1.0f - Abs(*(float*)(*(char**)(self + 0x60) + 0x280));
    } else {
        v = Abs(*(float*)(*(char**)(self + 0x60) + 0x280));
    }
    func_00313CF0(anim, 0, Clamp(v, 0.0f, 1.0f) * *(float*)(anim + 0x10));
    if (func_00313800(anim, dt * 0.01666666753590107f) != 0) {
        func_003145F8(x, anim);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001048C0);
#ifdef SKIP_ASM
extern "C" int func_001048C0(void* self, void* x, void* anim, float dt) {
    float t = dt * 0.01666666753590107f;
    int done;
    if (func_003135B0(anim, 0, t) != 0) {
        done = 1;
    } else {
        done = func_00313800(anim, t);
    }
    if (done == 0) {
        return 0;
    }
    func_003145F8(x, anim);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104940);
#ifdef SKIP_ASM
extern "C" int func_00104940(void* self, void* x, void* anim, float dt) {
    float t = dt * 0.01666666753590107f;
    int done;
    if (func_003135B0(anim, 0, t) != 0) {
        done = 1;
    } else {
        done = func_00313800(anim, t);
    }
    if (done == 0) {
        return 0;
    }
    func_003145F8(x, anim);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001049C0);
#ifdef SKIP_ASM
extern "C" int func_001049C0(void* self, void* x, void* anim, float dt) {
    float t = dt * 0.01666666753590107f;
    int done;
    if (func_003135B0(anim, 0, t) != 0) {
        done = 1;
    } else {
        done = func_00313800(anim, t);
    }
    if (done == 0) {
        return 0;
    }
    func_003145F8(x, anim);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104A40);
#ifdef SKIP_ASM
extern "C" int func_00104A40(int a, int b, int* c) {
    return func_00312B18(a, b, c, 0x11F);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104A60);
#ifdef SKIP_ASM
// Plays the landing animation that matches the current trick state.
extern "C" int func_00104A60(void* a, void* b, int* c)
{
    switch (*c) {
    case 0x10F: case 0x11D:
        return func_00312B18_4A60(a, b, c, 0x123);
    case 0x110: case 0x118: case 0x119: case 0x11E:
        return func_00312B18_4A60(a, b, c, 0x124);
    case 0x10D: case 0x116: case 0x11B:
        return func_00312B18_4A60(a, b, c, 0x121);
    case 0x10E: case 0x117: case 0x11C:
        return func_00312B18_4A60(a, b, c, 0x122);
    case 0x111:
        return func_00312B18_4A60(a, b, c, 0x125);
    case 0x112:
        return func_00312B18_4A60(a, b, c, 0x126);
    case 0x113:
        return func_00312B18_4A60(a, b, c, 0x127);
    case 0x114:
        return func_00312B18_4A60(a, b, c, 0x128);
    }
    return 0x1B6;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104B48);
#ifdef SKIP_ASM
extern "C" int func_00104B48(void *arg0, void* b, int c) {
    if (*(int *)((char*)arg0 + 0x64) != 0) {
        return func_00312BD0(arg0, b, c, 0x1B4);
    }
    return func_00312BD0(arg0, b, c, 0x11F);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104B78);
#ifdef SKIP_ASM
extern "C" int func_00104B78(int a, int b, int* c) {
    return func_00312B18(a, b, c, 5);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104B98);
#ifdef SKIP_ASM
extern "C" int func_00104B98(int a, int b, int* c) {
    return func_00312B18(a, b, c, 3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104BB8);
#ifdef SKIP_ASM
extern "C" int func_00104BB8(int a, int b, int* c) {
    return func_00312B18(a, b, c, 0x13);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104BD8);
#ifdef SKIP_ASM
extern "C" int func_00104BD8(void *arg0, void* a1, int a2) {
    if ((*(int *)((char*)((*(void **)((char*)(arg0) + (0x60)))) + (0x330))) == 1) {
        return func_00312BD0(arg0, a1, a2, 0x1C);
    }
    return func_00312BD0(arg0, a1, a2, 0x24);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104C18);
#ifdef SKIP_ASM
extern "C" int func_00104C18(void* a, void* b, int c) {
    return func_00312BD0(a, b, c, 5);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104C38);
#ifdef SKIP_ASM
extern "C" int func_00104C38(void* a0, void* a1, int *arg2) {
    int var_7;
    switch (*arg2) {
    case 0x45:
        var_7 = 0x14;
        break;
    case 0x46:
        var_7 = 0x13;
        break;
    default:
        var_7 = 0x12;
        break;
    }
    return func_00312BD0_4C38(a0, a1, arg2, var_7);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104C80);
#ifdef SKIP_ASM
extern "C" int func_00104C80(void* a, void* b, int c) {
    return func_00312BD0(a, b, c, 0x1B2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104CA0);
#ifdef SKIP_ASM
extern "C" int func_00104CA0(int arg0, void* arg1, void* arg2) {
    func_003145F8(arg1, arg2);
    return 0x1B6;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104CC8);
#ifdef SKIP_ASM
extern "C" void func_00104CC8(void *arg0, int arg1) {
    int temp_2 = (*(int *)((char*)(arg0) + (0x60)));
    int s = arg1 & 0xFFFF;
    if (temp_2 != 0) {
        func_00289B18_4CC8(D_004A3500, temp_2, s);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104CF8);
#ifdef SKIP_ASM
extern "C" void func_00104CF8(void *arg0, int a1) {
    int var_6;
    void *temp_2;
    void *temp_4;

    temp_2 = (*(void **)((char*)(arg0) + (0x64)));
    var_6 = 0;
    if (temp_2 != 0) {
        var_6 = (*(int *)((char*)(temp_2) + (0xCD8)));
    } else {
        temp_4 = (*(void **)((char*)(arg0) + (0x60)));
        if (temp_4 != 0) {
            var_6 = (*(int *)((char*)(temp_4) + (0x364)));
        }
    }
    func_00311710_4CF8(D_004A3DFC, a1, var_6);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104D38);
#ifdef SKIP_ASM
extern "C" void func_00104D38(void *arg0, void *arg1) {
    (*(int *)((char*)(arg0) + (0x64))) = 0;
    (*(void **)((char*)(arg0) + (0x60))) = arg1;
    (*(int *)((char*)(arg0) + (0x54))) = (int) (*(int *)((char*)(arg1) + (0x780)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104D50);
#ifdef SKIP_ASM
extern "C" void func_00104D50(void *arg0, void *arg1) {
    (*(void **)((char*)(arg0) + (0x64))) = arg1;
    (*(int *)((char*)(arg0) + (0x60))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = (int) (*(int *)((char*)(arg1) + (8)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104D68);
#ifdef SKIP_ASM
extern "C" void func_00104D68(char* self, cStream* s) {
    s->Write(self, 0x50);
    for (int i = 0; i < 6; i++) {
        func_003147F0(*(char**)(self + 0x50) + i * 8, s);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104DE0);
#ifdef SKIP_ASM
extern "C" void func_00104DE0(char* self, cStream* s) {
    s->Read(self, 0x50);
    for (int i = 0; i < 6; i++) {
        func_00314668(*(char**)(self + 0x50) + i * 8);
        func_00314880(*(char**)(self + 0x50) + i * 8, s);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00104E70);
#ifdef SKIP_ASM
struct sTri_4E70 {
    float a;
    float b;
    unsigned short flags;
    unsigned short pad;
};

struct sMat_4E70 {
    char pad[0x10];
    sTri_4E70 tris[1];
};

class cHitObj_4E70 {
public:
    char pad[0xC];
    virtual void h00(); virtual void h01(); virtual void h02(); virtual void h03(); virtual void h04();
    virtual void h05(); virtual void h06(); virtual void h07(); virtual void h08(); virtual void h09();
    virtual void h10(); virtual void h11(); virtual void h12(); virtual void h13(); virtual void h14();
    virtual void h15(); virtual void h16(); virtual void h17(); virtual void h18(); virtual void h19();
    virtual void h20(); virtual void h21(); virtual void h22(); virtual void h23(); virtual void h24();
    virtual void h25(); virtual void h26(); virtual void h27(); virtual void h28(); virtual void h29();
    virtual void h30(); virtual void h31(); virtual void h32(); virtual void h33(); virtual void h34();
    virtual void h35(); virtual void h36(); virtual void h37(); virtual void h38(); virtual void h39();
    virtual void h40();
    virtual void OnHit(struct sContact_4E70*);
};

struct sSurf_4E70 {
    char pad[0xC];
    cHitObj_4E70* obj;
    char pad10[0x78 - 0x10];
    unsigned int id;
    char pad7C[0x88 - 0x7C];
    sMat_4E70* mat;
};

struct sOwner_4E70 {
    char pad[0x150];
    unsigned int order;
};

struct sContact_4E70 {
    sVec4 pos;
    sVec4 normal;
    sVec4 vel;
    char pad30[0x10];
    float height;
    char pad44[0xC];
    sSurf_4E70* surf;
    sOwner_4E70* owner;
    int pad58;
    int idx;
    char pad60[0x20];
} __attribute__((aligned(16)));

class cScope_4E70 {
public:
    char pad[0x50];
    virtual void s0();
    virtual void s1();
    virtual float Height();
};

struct sSelf_4E70 {
    char pad[0x5B8];
    unsigned int ids[64];
    char pad6B8[0x860 - 0x6B8];
    void* tree;
    char pad864[0xAA0 - 0x864];
    char* body;
};

extern "C" int func_00334458_4E70(void*, cScope_4E70*, sContact_4E70*, int, int) __asm__("func_00334458");

// PORT: PS2-only VU0 inline asm (vector add in place).
static inline void AddTo_4E70(sVec4& a, const sVec4& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(a)
        : "m"(a), "m"(b));
}

// PORT: the RID list is indexed as i * 4 + (int)base (pointer held in int) to get the target's addu operand order.
#define RID_4E70(i) (*(unsigned int*)((i) * 4 + (int)self->ids))

static inline int IsWall_4E70(sContact_4E70* c)
{
    sTri_4E70* t = &c->surf->mat->tris[c->idx];
    return (t->flags & 1) && t->a != 0.0f;
}

static inline int IsBack_4E70(sSelf_4E70* self, sContact_4E70* c)
{
    sVec4 rel = SubV(c->pos, *(sVec4*)(self->body + 0x10));
    return Dot(rel, c->normal) < 0.0f;
}

static inline int Before_4E70(sContact_4E70* a, sContact_4E70* b)
{
    if (a->surf) {
        if (b->surf == 0)
            return 1;
        return a->surf->id < b->surf->id;
    }
    if (b->surf)
        return 0;
    return a->owner->order < b->owner->order;
}

extern "C" float func_00104E70(sSelf_4E70* self, cScope_4E70* scope, sContact_4E70* out)
{
    int count = 0;
    sContact_4E70 hits[64];
    int n = func_00334458_4E70(self->tree, scope, hits, 64, 0);
    if (n == 0)
        return -1.0f;
    if (hits[0].surf)
        RID_4E70(count++) = hits[0].surf->id;
    int best = 0;
    float h = scope->Height();
    float bestDist = Abs(hits[0].height - h);
    int bestWall = IsWall_4E70(&hits[0]);
    int bestBack = IsBack_4E70(self, &hits[0]);
    for (int i = 1; i < n; i++) {
        if (hits[i].surf) {
            int j = 0;
            while (j < count && RID_4E70(j) != hits[i].surf->id)
                j++;
            if (j >= count)
                RID_4E70(count++) = hits[i].surf->id;
        }
        float dist = Abs(hits[i].height - h);
        int wall = IsWall_4E70(&hits[i]);
        if (wall && !bestWall) {
            best = i;
            bestDist = dist;
            bestWall = 1;
            continue;
        }
        if (bestWall && !wall)
            continue;
        int back = IsBack_4E70(self, &hits[i]);
        if (back && !bestBack) {
            best = i;
            bestDist = dist;
            bestBack = 1;
            continue;
        }
        if (bestBack && !back)
            continue;
        if (dist < bestDist) {
            best = i;
            bestDist = dist;
        } else if (dist == bestDist) {
            if (Before_4E70(&hits[i], &hits[best]))
                best = i;
        }
    }
    *out = hits[best];
    if (n >= 2) {
        sVec4 sum = D_004FF120;
        for (int k = 0; k < n; k++) {
            if (IsWall_4E70(&hits[k]))
                AddTo_4E70(sum, hits[k].normal);
        }
        float len = Len(sum);
        if (len > 0.0010000000474974513f) {
            sVec4 nrm = DivV(sum, len);
            out->normal = nrm;
        }
    }
    RID_4E70(count) = 0xFFFFFFFF;
    if (out->surf) {
        cHitObj_4E70* o = out->surf->obj;
        if (o)
            o->OnHit(out);
    }
    return out->height;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_00105398);
#ifdef SKIP_ASM
struct sTri_5398 {
    int a;
    float b;
    unsigned short flags;
    unsigned short pad;
};

struct sMat_5398 {
    char pad[0x10];
    sTri_5398 tris[1];
};

struct sSurf_5398 {
    char pad[8];
    int flags;
    char padC[0x88 - 0xC];
    sMat_5398* mat;
};

struct sContact_5398 {
    t4Vector pos;
    t4Vector normal;
    t4Vector vel;
    char pad30[0x20];
    sSurf_5398* surf;
    int pad54;
    int pad58;
    int idx;
    char pad60[0x20];
} __attribute__((aligned(16)));

struct cScope_5398 {
    char data[0x320];
    cScope_5398(void* tree, int flag) __asm__("func_0032F650");
};

extern "C" float func_00104E70_5398(char*, cScope_5398*, sContact_5398*) __asm__("func_00104E70");
extern "C" void func_001057B8_5398(char*, sSurf_5398*, sInfo*, sContact_5398*, float) __asm__("func_001057B8");
extern "C" void func_00296088_5398(void*, char*, sSurf_5398*, int) __asm__("func_00296088");

// PORT: PS2-only VU0 inline asm (vector divided by scalar).
static inline t4Vector Div_5398(const t4Vector& v, float s)
{
    t4Vector r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s));
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline t4Vector Norm_5398(const t4Vector& v)
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
        : "m"(v));
    return r;
}

static inline unsigned short TriFlags_5398(sSurf_5398* s, int i)
{
    return ((sTri_5398*)(i * sizeof(sTri_5398) + (int)s->mat->tris))->flags; // PORT: pointer in int
}

extern "C" void func_00105398(char* self, t4Vector* norm)
{
    sContact_5398 c;
    sInfo info;
    if (func_0011FEE8(self) == 9)
        return;
    func_00106F78(self);
    cScope_5398 sc(*(void**)(self + 0xAA0), 1);
    cScope_5398* ps = &sc;
    float d = func_00104E70_5398(self, ps, &c);
    if (d >= 0.0f) {
        if (func_001231A8(self))
            norm = (t4Vector*)(self + 0x370);
        if (norm) {
            t4Vector t = Sub(c.normal, Scale(*norm, Dot(c.normal, *norm)));
            float len = Len(t);
            if (len < 0.0010000000474974513f)
                c.normal = *norm;
            else
                c.normal = Div_5398(t, len);
        } else if (func_0011FE98(self) == 4) {
            t4Vector* up = (t4Vector*)(*(char**)(self + 0x77C) + 0xB0);
            if (Dot(c.normal, *up) > 0.0f)
                c.normal = *up;
            else
                c.normal = Scale(*up, -1.0f);
        }
        float k = Dot(Scale(c.normal, -1.0f), Sub(*(t4Vector*)(self + 0x1E0), c.vel)) >= 0.0f
                      ? Dot(Scale(c.normal, -1.0f), Sub(*(t4Vector*)(self + 0x1E0), c.vel))
                      : 0.0f;
        info.pos = c.pos;
        info.dir = Norm_5398(*(t4Vector*)(self + 0x1E0));
        info.normal = c.normal;
        info.speed = k;
        if ((TriFlags_5398(c.surf, c.idx) & 2) && !(c.surf->flags & 0x2000)) {
            *(sContact_5398*)(self + 0x9E0) = c;
            *(sInfo*)(self + 0xA60) = info;
        }
        if (TriFlags_5398(c.surf, c.idx) & 1)
            func_001057B8_5398(self, c.surf, &info, &c, d);
        if (!(c.surf->flags & 0x2000))
            func_00296088_5398(D_004A3500, self, c.surf, c.idx);
    }
    func_0016D320(D_004C5830, self);
    func_0032F708(&sc, 2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001057B8);
#ifdef SKIP_ASM
// Rider hits a surface: hit->n is the contact normal, hit->vel the surface velocity.
// The unit declares this later with its own vector type; bind it by asm label.

struct sHit_57B8 {
    char pad0[0x10];
    t4Vector n;         // 0x10
    t4Vector vel;       // 0x20
    char pad30[0x1C];
    int mat;            // 0x4C
    char pad50[0xC];
    int surf;           // 0x5C
};

// PORT: PS2-only VU0 inline asm (a += b).
static inline void AddEq_57B8(t4Vector& a, const t4Vector& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

static inline float DotV_57B8(t4Vector a, const t4Vector& b)
{
    return Dot(a, b);
}

// PORT: g++ minimum operator.
static inline float Clamp_57B8(float x, float lo, float hi)
{
    if (lo <= x)
        return x <? hi;
    return lo;
}

static inline float Max_57B8(float x, float lo)
{
    if (lo < x)
        return x;
    return lo;
}

// PORT: PS2 FPU sqrt.s via inline asm; use sqrtf off-PS2.
static inline float Sqrt_57B8(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_001057B8(cRider* rider, char* obj, char* info, sHit_57B8* hit, float depth)
{
    if (func_0011FEE8(rider) == 9)
        return;
    int off = hit->surf * 12 + 0x10;
    float* surf = (float*)(*(char**)(obj + 0x88) + off);
    float grip = Clamp_57B8(surf[1], 0.0f, 1.0f);
    float bounce = surf[0];
    if (bounce == 0.0f) {
        func_00108388((char*)rider, info, 1);
        return;
    }
    float vn = Dot(hit->n, SubM(hit->vel, rider->mVelocity)) >= 0.0f
                   ? Dot(hit->n, SubM(hit->vel, rider->mVelocity)) : 0.0f;
    char* h = *(char**)(obj + 0xC);
    if (h == 0 || (*(sVEntry<int(void*)>**)(h + 0xC))[14].fn(h + (*(sVEntry<int(void*)>**)(h + 0xC))[14].delta) != 0) {
        func_00106538_m2537(rider, ScaleM(hit->n, depth * 1.100000023841858f));
        if (vn < 0.0f)
            vn = 0.0f;
        bounce = vn + Clamp_57B8(grip * vn, 55.55555725097656f, 1388.888916015625f);
        if (func_0011FE98(rider) == 0)
            func_001065B0(rider, hit);
        cRider_updateOrientationImplicit(rider);
    } else {
        float inv = 1.0f / (100.0f / bounce + 1.0f);
        float b = vn * inv;
        float c = (1.0f - grip) * inv;
        bounce = Sqrt_57B8((b * b - c) >? 0.0f) - b; // PORT: g++ maximum operator
    }
    float facing = DotV_57B8(rider->unk_180, hit->n);
    if (func_0011FE98(rider) == 1 || (func_0011FE98(rider) == 2 && *(int*)((char*)rider->mRiderHandler + 0x30) == 1)) {
        if (Len(rider->mVelocity) < 833.3333740234375f) {
            float* acc = &rider->unk_3F4;
            *acc = *acc + (2.5f - facing) * (hit->n.z >= 0.20000000298023224f ? hit->n.z : 0.20000000298023224f);
        }
    }
    int anim = func_00311AE8(rider->mRiderAnim, 2);
    int state = func_0011FE98(rider);
    if (state == 1 && (anim == 9 || anim == 2 || anim == 0xB || anim == state) && facing > 0.30000001192092896f) {
        t4Vector w = AddM(SubM(rider->mVelocity, hit->vel), ScaleM(hit->n, vn));
        float speed = Len(w);
        float out = Max_57B8(bounce - vn, 277.77777099609375f);
        float f = (speed + 555.5555419921875f) * 0.5f;
        if (speed <= 27.77777862548828f)
            f = f / 27.77777862548828f;
        else
            f = f / speed;
        ScaleEq(w, f);
        rider->mVelocity = AddM(w, ScaleM(hit->n, out));
        sVEntry<void(void*, float)>* vt = *(sVEntry<void(void*, float)>**)&rider->mVtbl;
        vt[kRiderVt_vibrationBump].fn((char*)rider + vt[kRiderVt_vibrationBump].delta, vn);
        if (func_00312AA0(rider->mRiderAnim, 2) != 0x10C || func_00312AB0(rider->mRiderAnim, 2) > 0.20000000298023224f) {
            rider->unk_438 = 0;
            func_0010E910(rider, 0, 0, 0, hit, speed);
            func_00119E38(rider->mMetrix, rider->unk_320 != rider->unk_324, 0);
            func_0011FEC8_2(rider, 0xD);
            func_0011FEC8_2(rider, 5);
            cRiderAnimBase_play(rider->mRiderAnim, 0x10C, 1, -1.0f);
        }
        char* sub = (char*)&rider->mVtbl;
        sVEntry<t4Vector*(void*)>* vt2 = *(sVEntry<t4Vector*(void*)>**)sub;
        t4Vector* pos = vt2[kRiderVt_getPosition].fn(sub + vt2[kRiderVt_getPosition].delta);
        sVEntry<t4Vector*(void*)>* vt3 = *(sVEntry<t4Vector*(void*)>**)sub;
        t4Vector* vel = vt3[kRiderVt_getVelocity].fn(sub + vt3[kRiderVt_getVelocity].delta);
        cAirPredictor_startLaunchIntoAir_57B8(rider->mAirPredictor, pos, vel, rider->unk_2E4);
        return;
    }
    AddEq_57B8(rider->mVelocity, ScaleM(hit->n, bounce));
    func_00105D98(rider, info, hit->mat);
}
#endif

INCLUDE_ASM("seg/seg_1218", func_00105D98);

//100%
INCLUDE_ASM("seg/seg_1218", func_00106538);
#ifdef SKIP_ASM
extern "C" void func_00106538(char* self, const t4Vector* d)
{
    AddEq(*(t4Vector*)(self + 0x110), *d);
    AddEq(*(t4Vector*)(self + 0x9D0), *d);
    func_00329B40(*(void**)(self + 0xAA0), d);
    AddEq(*(t4Vector*)(self + 0x400), *d);
    AddEq(*(t4Vector*)(self + 0x410), *d);
}
#endif

INCLUDE_ASM("seg/seg_1218", func_001065B0);

//100%
INCLUDE_ASM("seg/seg_1218", func_00106828);
#ifdef SKIP_ASM
extern "C" void func_00106828(void *arg0) {
    func_00329AE0((*(int *)((char*)(arg0) + (0xAA0))));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00106848);
#ifdef SKIP_ASM
// Rider touches down: kill the velocity into the ground, classify the landing from the board's
// orientation against the ground normal (state at 0x328), and start the landing reaction.

struct sLand_6848 {
    char pad0[0x10];
    t4Vector n;         // 0x10
    char pad20[0x2C];
    int mat;            // 0x4C
    char* obj;          // 0x50
    char pad54[0x2C];
} __attribute__((aligned(16)));

// The unit defines this later with its own vector type; bind it by asm label.
extern "C" int func_00108A48_6848(cRider* self, sLand_6848* land) __asm__("func_00108A48");

struct sQuat_6848 {
    float x, y, z, w;
    sQuat_6848() {}
    sQuat_6848(float ax, float ay, float az, float aw) { w = aw; x = ax; y = ay; z = az; }
} __attribute__((aligned(16)));

static inline float Atan2_6848(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f)
            a += 3.1415927410125732f;
        else
            a -= 3.1415927410125732f;
    }
    return a;
}

static inline t4Vector GetUp_6848(cRider* r)
{
    return r->mMatrix.row[2];
}

static inline float AtLeast_6848(float x, float lo)
{
    return x <= lo ? lo : x;
}

static inline float AtMost_6848(float x, float hi)
{
    return x <= hi ? x : hi;
}

static inline sVec4 Side_6848(const sAnimModelBone* b)
{
    return sVec4(1.0f - 2.0f * (b->rot.y * b->rot.y + b->rot.z * b->rot.z),
                   2.0f * (b->rot.x * b->rot.y + b->rot.w * b->rot.z),
                   2.0f * (b->rot.x * b->rot.z - b->rot.w * b->rot.y),
                   0.0f);
}

static inline sVec4 Front_6848(const sAnimModelBone* b)
{
    return sVec4(2.0f * (b->rot.y * b->rot.x - b->rot.w * b->rot.z),
                   1.0f - 2.0f * (b->rot.z * b->rot.z + b->rot.x * b->rot.x),
                   2.0f * (b->rot.y * b->rot.z + b->rot.w * b->rot.x),
                   0.0f);
}

static inline sVec4 Up_6848(const sAnimModelBone* b)
{
    return sVec4(2.0f * (b->rot.z * b->rot.x + b->rot.w * b->rot.y),
                   2.0f * (b->rot.z * b->rot.y - b->rot.w * b->rot.x),
                   1.0f - 2.0f * (b->rot.x * b->rot.x + b->rot.y * b->rot.y),
                   0.0f);
}

static inline sQuat_6848 AxisAngle_6848(const t4Vector& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sQuat_6848(s * axis.x, s * axis.y, s * axis.z, c);
}

#define LAND_STATE(r) ((r)->unk_328)
#define LAND_KIND(r) ((r)->unk_330)

extern "C" int func_00106848(cRider* self)
{
    sLand_6848 land;
    if (!func_00108A48_6848(self, &land))
        return 0;
    float vn = Dot(self->mVelocity, land.n);
    if (vn < 0.0f) {
        vn = -vn;
        ScaleEq(land.n, -1.0f);
    }
    vn = AtLeast_6848(vn, 555.5555419921875f);
    float imp = AtMost_6848(Len(self->mVelocity), vn);
    t4Vector dv = self->mVelocity;
    self->mVelocity = ScaleM(land.n, imp);
    self->mVelocity.z = self->mVelocity.z * 0.10000000149011612f;
    dv = SubM(self->mVelocity, dv);
    if (land.obj != 0) {
        char* h = *(char**)(land.obj + 0xC);
        if (h != 0) {
            sVEntry<void(void*, void*, const t4Vector&)>* vt = *(sVEntry<void(void*, void*, const t4Vector&)>**)(h + 0xC);
            vt[43].fn(h + vt[43].delta, &land, ScaleM(dv, -1.0f));
        }
    }
    sAnimModelBone* bone = &self->mAnimModel->bones[self->unk_8A0];
    sVec4 side = Side_6848(bone);
    sVec4 up = Up_6848(bone);
    float a = Dot(*(t4Vector*)&side, land.n);
    float b = Dot(*(t4Vector*)&up, land.n);
    float angle = Atan2_6848(b, a);
    int prev = LAND_STATE(self);
    if (func_0011FEE8(self) == 1) {
        if (self->unk_320 == 0)
            LAND_STATE(self) = 1;
        else
            LAND_STATE(self) = 2;
    } else if (LAND_KIND(self) != 0) {
        if (Abs(angle) > 1.5707964897155762f)
            LAND_STATE(self) = 2;
        else
            LAND_STATE(self) = 1;
    } else if (func_0011FEE8(self) == 0xC) {
        LAND_STATE(self) = 3;
    } else {
        sVec4 front = Front_6848(bone);
        if (front.z < 0.0f) {
            if (b < 0.0f)
                LAND_STATE(self) = 4;
            else
                LAND_STATE(self) = 3;
        } else if (Abs(angle) > 2.6179940700531006f) {
            LAND_STATE(self) = 2;
        } else if (Abs(angle) < 0.523598849773407f) {
            LAND_STATE(self) = 1;
        } else if (angle < -0.523598849773407f) {
            LAND_STATE(self) = 4;
        } else {
            LAND_STATE(self) = 3;
        }
    }
    self->unk_438 = land.mat;
    if (func_0011FE98(self) == 1) {
        func_0010E910(self, 0, LAND_STATE(self), LAND_KIND(self), &land, imp);
    } else {
        func_0010E098(self, 1, func_00119D40(self->mMetrix, self->unk_320 != self->unk_324, 0, LAND_STATE(self), LAND_KIND(self)));
    }
    *(int*)(D_004A3500 + 0x598C) = land.mat;
    func_0011FE78_6848(self, 4);
    int st = func_0011FEE8(self);
    if (st == 0 || func_0011FEE8(self) == 4 || func_0011FEE8(self) == 5 || func_0011FEE8(self) == 0xB) {
        int fall = 0;
        if (func_0011FEE8(self) == 5 || func_0011FEE8(self) == 4)
            fall = 1;
        func_0011FEC8_2(self, 0xD);
        func_00115358(self);
        int kind = LAND_KIND(self);
        if (kind != 0) {
            if (kind == 1)
                cRiderAnimBase_play(self->mRiderAnim, 0x1A, 0, -1.0f);
            else
                cRiderAnimBase_play(self->mRiderAnim, 0x22, 0, -1.0f);
            func_0011FEC8_2(self, 1);
        } else {
            func_001326C8((char*)self->mRiderHandler + 0x2B0, fall);
            func_0011FEC8_2(self, 7);
        }
    } else if (prev != LAND_STATE(self)) {
        if (prev == 3) {
            func_0011DFE0(self, GetUp_6848(self), 1.5707963705062866f);
            cRiderAnimBase_changeHeadingOffset(self->mRiderAnim, 1.5707963705062866f);
            float yaw = 0.0f;
            char* ra = (char*)self->mRiderAnim;
            *(t4Vector*)(ra + 0x30) = D_004FF130;
            *(sQuat_6848*)(ra + 0x40) = AxisAngle_6848(D_004FF160, -yaw);
        } else if (prev == 4) {
            func_0011DFE0(self, GetUp_6848(self), -1.5707963705062866f);
            cRiderAnimBase_changeHeadingOffset(self->mRiderAnim, -1.5707963705062866f);
            float yaw = 0.0f;
            char* ra = (char*)self->mRiderAnim;
            *(t4Vector*)(ra + 0x30) = D_004FF130;
            *(sQuat_6848*)(ra + 0x40) = AxisAngle_6848(D_004FF160, -yaw);
        }
        func_00115358(self);
    }
    func_0013ADC0((char*)self->mRiderHandler + 0xB0, &land.n);
    return 1;
}

#undef LAND_STATE
#undef LAND_KIND
#endif

INCLUDE_ASM("seg/seg_1218", func_00106F78);

INCLUDE_ASM("seg/seg_1218", func_00107578);

INCLUDE_ASM("seg/seg_1218", func_00107888);

//100%
INCLUDE_ASM("seg/seg_1218", func_00107E70);
#ifdef SKIP_ASM
static inline t4Vector Get_7E70(char* p) { return *(t4Vector*)p; }

static inline float ClampAbs_7E70(float v, const float& lim)
{
    return Clamp(v, -lim, lim);
}

extern "C" void func_00107E70(char* self, char* other, t4Vector* n, int flag, float speed)
{
    if (func_0011FEE8(self) == 10)
        return;
    float absSpd = Abs(speed);
    float s = ClampAbs_7E70(speed, 555.5555419921875f);
    t4Vector imp = Scale(*n, s);
    if (func_001231A8(self)) {
        AddEq(*(t4Vector*)(self + 0x1E0),
                   Sub(imp, Scale(*(t4Vector*)(self + 0x370), Dot(imp, *(t4Vector*)(self + 0x370)))));
    } else {
        AddEq(*(t4Vector*)(self + 0x1E0), imp);
        if (func_0011FE98(self) == 1 || (func_0011FE98(self) == 2 && *(int*)(*(char**)(self + 0x77C) + 0x30) == 1)) {
            cBeing* ai = (cBeing*)(self + 0x6C0);
            const t4Vector* pos = ai->getPosition();
            cAirPredictor_startLaunchIntoAir(*(void**)(self + 0x788), pos, ai->getVelocity(), *(float*)(self + 0x2E4));
            if (Dot(*n, Get_7E70(self + 0x1C0)) * s > 0.0f)
                absSpd = 0.0f;
        }
    }
    if (func_0011FE98(self) == 2)
        return;
    if (func_0011FEE8(self) == 9)
        return;
    if (absSpd < 39.99532699584961f)
        return;
    float r = ((sRiderRec*)self)[*(int*)(other + 0x86C)].dist;
    sInfo info;
    info.pos = Add(*(t4Vector*)(self + 0x110), Scale(*n, r));
    info.dir = Norm(*(t4Vector*)(self + 0x1E0));
    info.normal = *n;
    info.speed = s;
    if ((D_005308D0[0] >> 5) & 1)
        absSpd = 599.9739990234375f;
    if (absSpd > 599.9739990234375f) {
        float dz = Dot(Get_7E70(self + 0x160), *n);
        float dy = Dot(Get_7E70(self + 0x170), *n);
        float dx = Dot(Get_7E70(self + 0x180), *n);
        int anim;
        if (Abs(dz) < Abs(dy) && Abs(dx) < Abs(dy)) {
            if (dy < 0.0f) {
                unsigned int k;
                if (Len(*(t4Vector*)(self + 0x1E0)) > D_004A4C84)
                    k = (unsigned int)AIrand() % 6;
                else
                    k = (unsigned int)AIrand() % 3;
                if (k == 0)
                    anim = 0x14E;
                else if (k == 1)
                    anim = 0x14F;
                else if (k == 2)
                    anim = 0x151;
                else if (k == 3)
                    anim = 0x14D;
                else
                    anim = 0x150;
            } else {
                anim = (AIrand() & 1) == 0 ? 0x14A : 0x14B;
            }
        } else if (Abs(dz) < Abs(dx) && Abs(dy) < Abs(dx)) {
            anim = 0x14B;
        } else if (dz < 0.0f) {
            anim = 0x149;
        } else {
            anim = 0x148;
        }
        func_0010EB30_7E70(self, anim, flag, 0, &info);
        if (flag)
            func_0010E468(self, other);
        else
            func_0010E2E8(self, other);
    } else {
        func_00108388_7E70(self, &info, 0);
        if (flag)
            func_0010E3A8(self, other);
        else
            func_0010E228(self, other);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108388);
#ifdef SKIP_ASM
static inline t4Vector Get_8388(char* p) { return *(t4Vector*)p; }

extern "C" void func_00108388(char* self, char* info, int flag)
{
    if (func_0011FE98(self) != 0 && func_0011FE98(self) != 4)
        return;
    if (func_0011FEE8(self) == 1) {
        func_00131348(*(char**)(self + 0x77C) + 0x1D0);
    } else if (func_0011FEE8(self) != 0 && func_0011FEE8(self) != 2 && func_0011FEE8(self) != 7) {
        return;
    }
    int played = 0;
    float d = Dot(Get_8388(self + 0x1B0), *(t4Vector*)(info + 0x20));
    if (d > 0.7071067690849304f) {
        cRiderAnimBase_play(*(void**)(self + 0x784), 0x37, 0, -1.0f);
    } else if (d < -0.7071067690849304f) {
        cRiderAnimBase_play(*(void**)(self + 0x784), 0x38, 0, -1.0f);
    } else {
        float side = Dot(Get_8388(self + 0x1A0), *(t4Vector*)(info + 0x20));
        if (*(int*)(self + 0x320))
            side = -side;
        if (*(float*)(info + 0x30) < 1111.111083984375f && Len(*(t4Vector*)(self + 0x1E0)) > 1388.888916015625f &&
            func_0011FE98(self) != 4) {
            float a = *(float*)(self + 0x2DC);
            if (Abs(a) < 6.2831854820251465f) {
                if (a < 0.0f)
                    *(float*)(self + 0x2DC) += (int)((unsigned int)AIrand() % 3) * -3.1415927410125732f;
                else if (a > 0.0f)
                    *(float*)(self + 0x2DC) += (int)((unsigned int)AIrand() % 3) * 3.1415927410125732f;
                else
                    *(float*)(self + 0x2DC) += ((int)((unsigned int)AIrand() % 5) - 2) * 3.1415927410125732f;
            }
            cRiderAnimBase_play(*(void**)(self + 0x784), side < 0.0f ? 0x3A : 0x3C, 0, -1.0f);
            played = 1;
        } else {
            cRiderAnimBase_play(*(void**)(self + 0x784), side < 0.0f ? 0x39 : 0x3B, 0, -1.0f);
        }
    }
    if (flag)
        func_002A0E70(func_0028B180(), self, played);
    func_0011FEC8_2(self, 3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_001086B8);
#ifdef SKIP_ASM
struct sNode_86B8 {
    sVec4 pos;
    float qx, qy, qz, qw;
};

struct sPath_86B8 {
    char pad[0x2C];
    sNode_86B8* nodes;
};

struct sHit_86B8 {
    sVec4 pos;
    char pad[0x80 - 0x10];
};

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec4 Add_86B8(const sVec4& a, const sVec4& b)
{
    sVec4 r;
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
static inline sVec4 Scale_86B8(const sVec4& v, float s)
{
    sVec4 r;
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

static inline float Lerp_86B8(float a, float b, float t)
{
    return t * a + (1.0f - t) * b;
}

static inline sVec4 Fwd_86B8(const sNode_86B8* n)
{
    return sVec4(1.0f - (n->qy * n->qy + n->qz * n->qz) * 2.0f,
                    (n->qx * n->qy + n->qw * n->qz) * 2.0f,
                    (n->qx * n->qz - n->qw * n->qy) * 2.0f,
                    0.0f);
}

extern "C" int func_001086B8_86B8(char* self, sVec4* tgt, sVec4* dir)
{
    sNode_86B8* n = &(*(sPath_86B8**)(self + 0x780))->nodes[*(int*)(self + 0x8A0)];
    const sVec4& fwd = Fwd_86B8(n);
    sVec4 pos = Add_86B8(n->pos, *(sVec4*)(self + 0x9D0));
    float t = *(float*)(self + 0x25C);
    float nearR = Lerp_86B8(50.0f, 30.0f, t);
    float farR;
    if (!*(int*)(self + 0x330))
        farR = Lerp_86B8(170.0f, 100.0f, t);
    else
        farR = Lerp_86B8(170.0f, 50.0f, t);
    float proj = Dot(fwd, SubV(*tgt, pos));
    float lo = nearR - farR;
    float hi = farR - nearR;
    sVec4 d = SubV(Add_86B8(pos, Scale_86B8(fwd, Clamp(proj, lo, hi))), *tgt);
    if (Len(d) <= nearR)
        return 1;
    float dd = Dot(*dir, fwd);
    float den = 1.0f - dd * dd;
    if (den < 0.0010000000474974513f)
        return 0;
    sVec4 b = DivV(SubV(pos, *tgt), den);
    float u = Dot(b, SubV(Scale_86B8(*dir, dd), fwd));
    sVec4 p = Add_86B8(pos, Scale_86B8(fwd, Clamp(u, lo, hi)));
    sHit_86B8 hit;
    if (!func_00334680_86B8(*(void**)(self + 0x860), &p, &hit.pos, 1, 300.0f))
        return 0;
    d = SubV(p, hit.pos);
    return Len(d) <= nearR;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_00108A48);
#ifdef SKIP_ASM
struct sNode_8A48 {
    t4Vector pos;
    char pad[0x10];
};

struct sPath_8A48 {
    char pad[0x2C];
    sNode_8A48* nodes;
};

extern "C" int func_00108A48(char* self, t4Vector* tgt)
{
    if (func_0011FE98(self) != 0 && func_0011FE98(self) != 1)
        return 0;
    t4Vector p = AddM(*(t4Vector*)((char*)(*(sPath_8A48**)(self + 0x780))->nodes + (*(int*)(self + 0x8A0) << 5)),
                             *(t4Vector*)(self + 0x9D0));
    if (!func_00334680(*(void**)(self + 0x860), &p, tgt, 1, 300.0f))
        return 0;
    float spd = Len(*(t4Vector*)(self + 0x1E0));
    if (0.001f < spd) {
        t4Vector d = Sub(*tgt, p);
        if (Dot(d, *(t4Vector*)(self + 0x1E0)) < spd * -0.20000000298023224f)
            return 0;
    }
    if (func_00311AE8(*(void**)(self + 0x784), 2) == 0x12) {
        if (!func_001446A0(func_00311B20(*(void**)(self + 0x784), 2) + 0xB0, 2) &&
            func_001446A0(func_00311B20(*(void**)(self + 0x784), 2) + 0xB0, 0))
            return 0;
    } else if (func_00311AE8(*(void**)(self + 0x784), 2) == 0x13 ||
               func_00311AE8(*(void**)(self + 0x784), 2) == 0x14) {
        if (!func_001446A0(func_00311B20(*(void**)(self + 0x784), 2) + 0xB0, 2))
            return 0;
    }
    return func_001086B8(self, tgt, tgt + 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108C28);
#ifdef SKIP_ASM
struct S_8C28 { char pad[0x5B8]; unsigned arr[64]; };
extern "C" int func_00108C28(S_8C28 *arg0, void *arg1) {
    int i = 0;
    if (~arg0->arr[0]) {
        do {
            if (arg0->arr[i] == *(unsigned *)((char*)arg1 + 0x78)) {
                return 1;
            }
            i++;
        } while (i < 64 && arg0->arr[i] != 0xFFFFFFFF);
    }
    return 0;
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_s12 {
public:
    virtual ~cRiderVbA0_s12();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_s12 : public cRiderVbA0_s12 { public: char padA[0xC]; };
class cRiderVbB0_s12 { public: virtual void b01(); };
class cRiderVbB_s12 : public cRiderVbB0_s12 { public: char padB[0x14]; };
class cRiderVbC0_s12 {
public:
    virtual ~cRiderVbC0_s12();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_s12 : public cRiderVbC0_s12 { public: char padC[0x10]; };
class cRiderVbBC_s12 : public cRiderVbB_s12, public cRiderVbC_s12 { public: };
class cRiderVbPad_s12 { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_s12 : public cRiderVbPad_s12, public cRiderVbA_s12, public cRiderVbBC_s12 {
public:
    cRiderVb_s12();
    virtual ~cRiderVb_s12();
};
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108C80);
#ifdef SKIP_ASM
// PORT: the rider class below derives from a composite of 31 parts that each derive virtually from cRider.
// Each part: an optional leading base (Head), the vbase pointer, then its own data; the parts named by a
// func_ address have out-of-line destructors (the visualfx/ai classes at those addresses), the others are
// destroyed inline. The composite's vptr sits at 0xDE8.
struct cCompHead00_s12 { char pad[0x18]; };
class cCompPart00_s12 : public cCompHead00_s12, virtual public cRiderVb_s12 { public: char body[0x4]; };
struct cCompHead01_s12 { char pad[0x4]; };
class cCompPart01_s12 : public cCompHead01_s12, virtual public cRiderVb_s12 { public: char body[0x8]; };
struct cCompHead02_s12 { char pad[0x40]; };
class cCompPart02_s12 : public cCompHead02_s12, virtual public cRiderVb_s12 {
public:
    char body[0x2C];
    virtual ~cCompPart02_s12();             // func_00136AD0
};
class cCompPart03_s12 : virtual public cRiderVb_s12 { public: char body[0xC]; };
struct cCompHead04_s12 { char pad[0x50]; };
class cCompPart04_s12 : public cCompHead04_s12, virtual public cRiderVb_s12 { public: char body[0xC]; };
struct cCompHead05_s12 { char pad[0xA0]; };
class cCompPart05_s12 : public cCompHead05_s12, virtual public cRiderVb_s12 { public: char body[0xC]; };
class cCompPart06_s12 : virtual public cRiderVb_s12 { public: char body[0xC]; };
struct cCompHead07_s12 { char pad[0x14]; };
class cCompPart07_s12 : public cCompHead07_s12, virtual public cRiderVb_s12 { public: char body[0x8]; };
class cCompPart08_s12 : virtual public cRiderVb_s12 { public: char body[0xC]; };
class cCompPart09_s12 : virtual public cRiderVb_s12 { public: char body[0xC]; };
struct cCompHead10_s12 { char pad[0x14]; };
class cCompPart10_s12 : public cCompHead10_s12, virtual public cRiderVb_s12 { public: char body[0x8]; };
struct cCompHead11_s12 { char pad[0x58]; };
class cCompPart11_s12 : public cCompHead11_s12, virtual public cRiderVb_s12 { public: char body[0x4]; };
struct cCompHead12_s12 { char pad[0x14]; };
class cCompPart12_s12 : public cCompHead12_s12, virtual public cRiderVb_s12 { public: char body[0x8]; };
struct cCompHead13_s12 { char pad[0x8]; };
class cCompPart13_s12 : public cCompHead13_s12, virtual public cRiderVb_s12 { public: char body[0x4]; };
struct cCompHead14_s12 { char pad[0x80]; };
class cCompPart14_s12 : public cCompHead14_s12, virtual public cRiderVb_s12 { public: char body[0xC]; };
struct cCompHead15_s12 { char pad[0x8]; };
class cCompPart15_s12 : public cCompHead15_s12, virtual public cRiderVb_s12 { public: char body[0x4]; };
struct cCompHead16_s12 { char pad[0x4]; };
class cCompPart16_s12 : public cCompHead16_s12, virtual public cRiderVb_s12 { public: char body[0x8]; };
struct cCompHead17_s12 { char pad[0x14]; };
class cCompPart17_s12 : public cCompHead17_s12, virtual public cRiderVb_s12 { public: char body[0x8]; };
struct cCompHead18_s12 { char pad[0x8]; };
class cCompPart18_s12 : public cCompHead18_s12, virtual public cRiderVb_s12 { public: char body[0x4]; };
class cCompPart19_s12 : virtual public cRiderVb_s12 { public: char body[0xC]; };
class cCompPart20_s12 : virtual public cRiderVb_s12 {
public:
    char body[0xBC];
    virtual ~cCompPart20_s12();             // func_002DCDA0
};
class cCompPart21_s12 : virtual public cRiderVb_s12 {
public:
    char body[0xAC];
    virtual ~cCompPart21_s12();             // func_002DA8E8
};
class cCompPart22_s12 : virtual public cRiderVb_s12 {
public:
    char body[0xEC];
    virtual ~cCompPart22_s12();             // func_002E83F0
};
class cCompPart23_s12 : virtual public cRiderVb_s12 {
public:
    char body[0x3AC];
    virtual ~cCompPart23_s12();             // func_002E64C0
};
class cCompPart24_s12 : virtual public cRiderVb_s12 {
public:
    char body[0x10C];
    virtual ~cCompPart24_s12();             // func_002EAC60
};
class cCompPart25_s12 : virtual public cRiderVb_s12 {
public:
    char body[0x1C];
    virtual ~cCompPart25_s12();             // func_002EF530
};
class cCompPart26_s12 : virtual public cRiderVb_s12 {
public:
    char body[0xC];
    virtual ~cCompPart26_s12();             // func_002D4A70
};
class cCompPart27_s12 : virtual public cRiderVb_s12 {
public:
    char body[0x3C];
    virtual ~cCompPart27_s12();             // func_002E37D0
};
class cCompPart28_s12 : virtual public cRiderVb_s12 {
public:
    char body[0x12C];
    virtual ~cCompPart28_s12();             // func_002DF1C8
};
class cCompPart29_s12 : virtual public cRiderVb_s12 {
public:
    char body[0xAC];
    virtual ~cCompPart29_s12();             // func_002F0FE8
};
class cCompPart30_s12 : virtual public cRiderVb_s12 {
public:
    virtual ~cCompPart30_s12();             // func_002F6388
};
class cComp_s12 : public cCompPart00_s12, public cCompPart01_s12, public cCompPart02_s12, public cCompPart03_s12, public cCompPart04_s12, public cCompPart05_s12, public cCompPart06_s12, public cCompPart07_s12, public cCompPart08_s12, public cCompPart09_s12, public cCompPart10_s12, public cCompPart11_s12, public cCompPart12_s12, public cCompPart13_s12, public cCompPart14_s12, public cCompPart15_s12, public cCompPart16_s12, public cCompPart17_s12, public cCompPart18_s12, public cCompPart19_s12, public cCompPart20_s12, public cCompPart21_s12, public cCompPart22_s12, public cCompPart23_s12, public cCompPart24_s12, public cCompPart25_s12, public cCompPart26_s12, public cCompPart27_s12, public cCompPart28_s12, public cCompPart29_s12, public cCompPart30_s12 {
public:
    char tail[0xC4];
    // PORT: func_0010FCD8 constructs this part (fields up to 0xDE8 and the vptr at 0xDE8)
    cComp_s12();
    ~cComp_s12() {}
    // Own vtable (D_00458710): a pure slot, then func_00111AC0 and func_00111D98.
    virtual void v01() = 0;
    virtual void v02();
    virtual void v03();
};

class cRiderE_108C80 : public cComp_s12 {
public:
    char tail[0x160];
    cRiderE_108C80(int flag);
    virtual ~cRiderE_108C80();
    virtual void a19();
    // Overrides of the composite's slots (D_004585F0): func_0010A768, func_0010A898, func_0010A8E8.
    virtual void v01();
    virtual void v02();
    virtual void v03();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cRiderE_108C80::cRiderE_108C80(int flag)
{
    if (flag)
        *(int*)((char*)(cRiderVb_s12*)this + 0x878) = 1;
    func_00108E88_self(this);
}
// PORT: the compiler names this ctor __14cRiderE_108C80ii; expose it under the address-derived name.
__asm__(".globl func_00108C80\n.type func_00108C80,@function\nfunc_00108C80 = __14cRiderE_108C80ii\n.size func_00108C80,0x208\n");
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108E88);
#ifdef SKIP_ASM
// Release build: the assert compiles to nothing (gcc still emits its loop notes).
#define ASSERT_8E88(cond) do { } while (0)
void func_00108E88_self(char* self) __asm__("func_00108E88");

void func_00108E88_self(char* self)
{
    *(int*)(self + 0xE0C) = -1;
    *(int*)(self + 0xE10) = 0;
    *(int*)(self + 0xE14) = 0;
    *(int*)(self + 0xE18) = 0;
    *(int*)(self + 0xE20) = 0;
    *(int*)(self + 0xE24) = 0;
    *(int*)(self + 0xE28) = 0;
    *(int*)(self + 0xE1C) = 0;
    *(int*)(self + 0xE2C) = 0;
    *(int*)(self + 0xE38) = 0;
    *(int*)(self + 0xE3C) = 0;
    *(int*)(self + 0xE30) = 0;
    *(int*)(self + 0xE34) = 0;
    *(int*)(self + 0xDF0) = 0;
    *(int*)(self + 0xE74) = 0;
    *(int*)(self + 0xE78) = 0;
    *(short*)(self + 0xF38) = 0;
    *(int*)(self + 0xF30) = 0;
    *(int*)(self + 0xF34) = 0;
    *(t4Vector*)(self + 0xE50) = D_004FF130;
    *(t4Vector*)(self + 0xE60) = D_004FF130;
    *(int*)(self + 0xE40) = 0;
    func_0010CAB8(self);
    *(int*)(self + 0xE70) = -1;
    *(float*)(self + 0xDF4) = 1.0f;
    *(tAiState*)(self + 0xF44) = D_0043CF20[1];
    *(short*)(self + 0xF38) = 1;
    ASSERT_8E88(self != 0);
    func_003E6448(self + 0xE7C, 0, 0x3C);
    func_003E6448(self + 0xEB8, 0, 0x3C);
    func_003E6448(self + 0xEF4, 0, 0x3C);
    func_0010D170(self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108F88);
#ifdef SKIP_ASM
extern "C" void func_00108F88(void) {
    func_00108E88();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_00108FA8);
#ifdef SKIP_ASM
// Compiler-generated: the composite's parts are destroyed in reverse order (the out-of-line part destructors
// are called, the others are inlined), then the cRider virtual base when this is the most-derived object.
// Needs -fno-rtti for this unit: the retail vtables carry no typeinfo pointer, and every level here stores
// cRider's own 0x6D0 vtable (D_00459B90), which g++ only shares between classes without RTTI.
cRiderE_108C80::~cRiderE_108C80()
{
}
// PORT: the compiler names these dtors _$_<len><Class>; map them to the address-derived names.
__asm__(".globl func_00108FA8\n.type func_00108FA8,@function\nfunc_00108FA8 = _$_14cRiderE_108C80\n.size func_00108FA8,0x17C0\n");
__asm__("_$_12cRiderVb_s12 = func_0011B978\n"
        "_$_15cCompPart02_s12 = func_00136AD0\n"
        "_$_15cCompPart20_s12 = func_002DCDA0\n"
        "_$_15cCompPart21_s12 = func_002DA8E8\n"
        "_$_15cCompPart22_s12 = func_002E83F0\n"
        "_$_15cCompPart23_s12 = func_002E64C0\n"
        "_$_15cCompPart24_s12 = func_002EAC60\n"
        "_$_15cCompPart25_s12 = func_002EF530\n"
        "_$_15cCompPart26_s12 = func_002D4A70\n"
        "_$_15cCompPart27_s12 = func_002E37D0\n"
        "_$_15cCompPart28_s12 = func_002DF1C8\n"
        "_$_15cCompPart29_s12 = func_002F0FE8\n"
        "_$_15cCompPart30_s12 = func_002F6388\n");
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A768);
#ifdef SKIP_ASM
// Clears the pad input, updates the rider, then runs the input handler for the rider state.
extern "C" void func_0010A768(char* self, void* pad)
{
    func_003E6448(pad, 0, 8);
    func_00120090(*(void**)(self + 0x18), func_0010DEF0(self));
    int state = func_0011FEE8(*(void**)(self + 0x18));
    switch (state) {
    case 0:
        func_0010A960_A768(self, pad);
        break;
    case 2:
        func_0010AA70_A768(self, pad);
        break;
    case 6:
        func_0010B790_A768(self, pad);
        break;
    case 4:
        func_0010B590_A768(self, pad);
        break;
    case 7:
        func_0010AED8_A768(self, pad);
        break;
    case 5:
        func_0010B250_A768(self, pad);
        break;
    case 8:
        func_0010B750_A768(self, pad);
        break;
    case 1:
        func_0010AD78_A768(self, pad);
        break;
    case 3: case 9: case 10: case 11: case 12: case 13:
        break;
    }
    if (state != 5) {
        *(int*)(self + 0xE34) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A898);
#ifdef SKIP_ASM
struct C_A898 {
    virtual void m0(char*, int);
};

extern "C" void func_0010A898(char *arg0, C_A898 *arg1) {
    func_00111AC0(arg0, arg1);
    arg1->m0(arg0 + 0xDF0, 0x150);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A8E8);
#ifdef SKIP_ASM
extern "C" void func_0010A8E8(char* self, cStream* in)
{
    func_00111D98(self, in);
    in->Read(self + 0xDF0, 0x150);
    short state = *(short*)(self + 0xF38);
    *(tAiState*)(self + 0xF44) = D_0043CF20[state];
    *(short*)(self + 0xF38) = state;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010A960);
#ifdef SKIP_ASM
struct sFlags_A960 {
    unsigned int pad0 : 12;
    unsigned int b12 : 1;
    unsigned int pad13 : 5;
    unsigned int b18 : 1;
    unsigned int b19 : 1;
};

class cObj_A960;
typedef void (cObj_A960::*Fn_A960)(sFlags_A960*);

class cObj_A960 {
public:
    virtual void v0();
    char pad[0xE20];
    int fE20;
    char padE24[0xF44 - 0xE24];
    Fn_A960 state;
};

extern "C" void func_0010A960(cObj_A960* self, sFlags_A960* f)
{
    int t;
    f->b12 = func_0010D1A0(self);
    self->fE20 = 0;
    if (func_0010DBF0(self, &t)) {
        if (t)
            f->b19 = 1;
        else
            f->b18 = 1;
    } else if (func_0010DA10(self)) {
        f->b19 = 1;
        f->b18 = 1;
    }
    (self->*(self->state))(f);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010AA70);
#ifdef SKIP_ASM
struct sPad_AA70 {
    unsigned int pad0 : 13;
    unsigned int b13 : 1;
    unsigned int b14 : 1;
    int b15 : 6;
    int b21 : 6;
    unsigned int pad27 : 5;
    int w0 : 6;
};

extern "C" void func_0010AA70(char* self, sPad_AA70* pad)
{
    sTrackRec buf[12];
    char* rider = *(char**)(self + 0x18);
    cTrack* trk = *(cTrack**)(rider + 0xAB8);
    int n = trk->Query(buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 50.0f);
    int sel = -1;
    if (Len(*(t4Vector*)(*(char**)(self + 0x18) + 0x1E0)) < *(float*)(self + 0xDF0) - 138.88890075683594f)
        pad->b14 = 1;
    if (*(int*)(self + 0xE1C)) {
        t4Vector a = Sub(*(t4Vector*)(self + 0xE60), *(t4Vector*)(self + 0xE50));
        t4Vector b = Sub(*(t4Vector*)(*(char**)(self + 0x18) + 0x110), *(t4Vector*)(self + 0xE50));
        if (Len(b) < Len(a) - 50.0f)
            pad->b13 = 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x10) {
            sel = i;
            pad->b13 = 1;
            break;
        }
    }
    float* ctl = (float*)(self + 0xDF0);
    if (sel != -1) {
        char* r = *(char**)(self + 0x18);
        t4Vector half = Sub(*(t4Vector*)(r + 0x490), *(t4Vector*)(r + 0x110));
        half = Scale(half, 0.5f);
        t4Vector pos = func_0026AB20(trk, 0, buf[sel].b);
        t4Vector d = Sub(pos, half);
        pad->w0 = (int)(func_00100348(self, &d) * 31.0f);
    }
    pad->b15 = (int)(ctl[0x12] * 31.0f);
    pad->b21 = (int)(ctl[0x13] * 31.0f);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_0010AD78);
#ifdef SKIP_ASM
struct sPad_AD78 {
    unsigned int pad0 : 18;
    int b18 : 6;
    int b24 : 6;
    unsigned int pad30 : 2;
    int w0 : 6;
};

extern "C" void func_0010AD78(char* self, sPad_AD78* pad)
{
    int flag;
    int r = func_0010BBF8(self, &flag);
    float s = 1.0f;
    if (flag)
        s = -1.0f;
    {
        t4Vector v;
        func_00100610(&v, self);
        pad->b18 = (int)(func_00100348(self, &v) * 31.0f);
    }
    if (r) {
        pad->w0 = (int)(s * 31.0f);
        t4Vector p = *(t4Vector*)(*(char**)(self + 0x18) + 0x1A0);
        float z = p.z + p.z;
        float y = Clamp(z, -1.0f, 1.0f);
        if (Abs(y) > 0.1f)
            pad->b24 = (int)(y * 31.0f);
    } else {
        pad->w0 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010AED8);
#ifdef SKIP_ASM
struct sPad_AED8 {
    unsigned int pad0 : 25;
    int b25 : 6;
    unsigned int pad31 : 1;
    int w0 : 6;
};

extern "C" void func_0010AED8(char* self, sPad_AED8* pad)
{
    int below, o3, o4, o5, o6, ok;
    int r = func_0010B980(self, (float*)(self + 0xDF0), &below, &o3, &o4, &o5, &o6);
    *(int*)(self + 0xE20) = o4;
    *(unsigned int*)pad |= 0x1FE0000;
    if (r && below) {
        *(unsigned int*)pad |= 0x6000;
        func_0010BFA8_c(self, o5, o6, o4, o3);
        return;
    }
    t4Vector p = *(t4Vector*)(*(char**)(self + 0x18) + 0x1A0);
    float z = p.z + p.z;
    float y = Clamp(z, -1.0f, 1.0f);
    if (Abs(y) > 0.1f)
        pad->b25 = (int)(y * 31.0f);
    char* rider = *(char**)(self + 0x18);
    if ((unsigned int)(*(int*)(rider + 0x328) - 3) >= 2 &&
        func_00311AE8(*(void**)(rider + 0x784), 2) != 0xE) {
        float s = (*(float*)(self + 0xE38) < 0.0f) ? 1.0f : -1.0f;
        pad->w0 = (int)(s * 31.0f);
    }
    int r2 = func_0010BB18(self, (float*)(self + 0xDF0), &ok);
    float len = Len(*(t4Vector*)(*(char**)(self + 0x18) + 0x1E0));
    if (r2 && ok && len < *(float*)(self + 0xDF0) - 138.88890075683594f)
        *(unsigned int*)pad |= 0x10000;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B0E8);
#ifdef SKIP_ASM
extern "C" void func_0010B0E8(char* self, float t)
{
    float a, b, c, d;
    func_00135CB0(*(char**)(*(char**)(self + 0x18) + 0x77C) + 0x230, &a, &b);
    func_00135DB0(*(char**)(*(char**)(self + 0x18) + 0x77C) + 0x230, &c, &d);
    int stop = 0;
    if (*(int*)(self + 0xE20) && t < 1.0f)
        stop = 1;
    if (stop) {
        *(float*)(self + 0xE3C) = 0.0f;
        *(float*)(self + 0xE38) = 0.0f;
        return;
    }
    if (!*(int*)(self + 0xE10))
        return;
    if (*(float*)(self + 0xE38) != 0.0f) {
        float lim = t + 0.1f;
        if (lim < a)
            *(float*)(self + 0xE38) = 0.0f;
        else if (lim < b && a - 0.4f < 0.0f)
            *(float*)(self + 0xE38) = 0.0f;
    }
    if (*(float*)(self + 0xE3C) != 0.0f) {
        float lim = t + 0.1f;
        if (lim < c) {
            *(float*)(self + 0xE3C) = 0.0f;
            *(float*)(self + 0xE38) = 0.0f;
        } else if (lim < d && c - 0.4f < 0.0f) {
            *(float*)(self + 0xE3C) = 0.0f;
            *(float*)(self + 0xE38) = 0.0f;
        }
    }
}
#endif

INCLUDE_ASM("seg/seg_1218", func_0010B250);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1218", func_0010B590);
#ifdef SKIP_ASM
struct sPad_B590 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};

struct sPadBits_B590 {
    unsigned int pad0 : 24;
    int b24 : 6;
};

extern "C" void func_0010B590(char* self, sPad_B590* pad)
{
    char* o = *(char**)(*(char**)(self + 0x18) + 0x788);
    int st = *(int*)(o + 0xAC);
    int ok = 0;
    if (st == 1 || st == 3)
        ok = 1;
    float d;
    if (ok)
        d = *(float*)(o + 0x98) - *(float*)(o + 0xA0);
    else
        d = 0.0f;
    *(int*)(self + 0xE10) = 0;
    *(int*)(self + 0xE14) = 0;
    *(int*)(self + 0xE18) = 1;
    *(int*)(self + 0xE20) = 0;
    *(int*)(self + 0xE0C) = -1;
    if (d > 1.0f) {
        *(int*)(self + 0xE10) = 1;
        *(float*)(self + 0xE38) = 1.0f;
        if (AIrand() & 1)
            *(float*)(self + 0xE38) = -*(float*)(self + 0xE38);
    } else {
        *(float*)(self + 0xE38) = 0.0f;
    }
    if (d > 3.0f) {
        *(int*)(self + 0xE10) = 1;
        *(float*)(self + 0xE3C) = 1.0f;
        if (AIrand() & 1)
            *(float*)(self + 0xE3C) = -*(float*)(self + 0xE3C);
    } else {
        *(float*)(self + 0xE3C) = 0.0f;
    }
    if (d < 0.5f && *(float*)(self + 0xE3C) == 0.0f && *(float*)(self + 0xE38) == 0.0f) {
        t4Vector v;
        func_00100610(&v, self);
        ((sPadBits_B590*)pad)->b24 = (int)(-func_00100348(self, &v) * 31.0f);
        *(int*)(self + 0xE0C) = -1;
    }
    pad->b2 = *(int*)(self + 0xE0C);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B750);
#ifdef SKIP_ASM
extern "C" void func_0010B750(void *arg0, int *arg1) {
    *arg1 = (*arg1 & ~0x1000) | ((func_0010D1A0(arg0) & 1) << 0xC);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B790);
#ifdef SKIP_ASM
struct sPad_B790 {
    unsigned int pad0 : 12;
    int b12 : 6;
};

extern "C" void func_0010B790(char* self, sPad_B790* pad)
{
    float t = 180.0f - (float)func_001298C8();
    float th = 33.0f;
    th -= (float)((((cBeing*)(*(char**)(self + 0x18) + 0x6C0))->getAIIndex() - 1) * 10);
    if (t < th && ((cBeing*)(*(char**)(self + 0x18) + 0x6C0))->getAIIndex() < 4) {
        pad->b12 = 0x1F;
        return;
    }
    if (t < 72.0f && ((cBeing*)(*(char**)(self + 0x18) + 0x6C0))->getAIIndex() < 3) {
        pad->b12 = -0x1F;
        return;
    }
    if (func_001298C8() % 20 == 0) {
        unsigned int r = AIrand();
        float* p = (float*)(self + 0xDF0);
        *p = (float)r * 0.009999999776482582f;
        if ((AIrand() & 1) == 0)
            *(float*)(self + 0xDF0) = -*(float*)(self + 0xDF0);
    }
    pad->b12 = (int)(*(float*)(self + 0xDF0) * 31.0f);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010B980);
#ifdef SKIP_ASM
extern "C" int func_0010B980(char* self, float* speed, int* below, int* o3, int* o4, int* o5, int* o6)
{
    sTrackRec buf[12];
    char* rider = *(char**)(self + 0x18);
    cTrack* trk = *(cTrack**)(rider + 0xAB8);
    int n = trk->Query(buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 300.0f);
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x10) {
            int fl = buf[i].flags;
            *speed = (float)(fl >> 4) * 27.777780532836914f;
            *o3 = (fl >> 3) & 1;
            *o4 = (fl >> 2) & 1;
            *o5 = (fl >> 1) & 1;
            *o6 = fl & 1;
            *below = (buf[i].a <= *(float*)(*(char**)(self + 0x18) + 0x4C4)) ? 1 : 0;
            *(t4Vector*)(self + 0xE50) = func_0026AB20(trk, 0, buf[i].a);
            *(t4Vector*)(self + 0xE60) = func_0026AB20(trk, 0, buf[i].b);
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BB18);
#ifdef SKIP_ASM
struct sHit_BB18 { int type; int val; float lim; int d; };
extern "C" int func_0010BB18(void* self_, float* out, int* ok) {
    char* self = (char*)self_;
    sHit_BB18 buf[12];
    char* rider = *(char**)(self + 0x18);
    char* q = *(char**)(rider + 0xAB8);
    char* vt = *(char**)(q + 0x34);
    int n = (*(int (**)(char*, sHit_BB18*, int, float, float))(vt + 0xC))(q + *(short*)(vt + 8), buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 600.0f);
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x11) {
            *out = (float)buf[i].val * 27.777780532836914f;
            *ok = buf[i].lim <= *(float*)(*(char**)(self + 0x18) + 0x4C4);
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BBF8);
#ifdef SKIP_ASM
struct sHit_BBF8 { int type; int val; int d[2]; };
extern "C" int func_0010BBF8(void* self_, int* out) {
    char* self = (char*)self_;
    sHit_BBF8 buf[12];
    char* rider = *(char**)(self + 0x18);
    char* q = *(char**)(rider + 0xAB8);
    char* vt = *(char**)(q + 0x34);
    int n = (*(int (**)(char*, sHit_BBF8*, int, float, float))(vt + 0xC))(q + *(short*)(vt + 8), buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4) + 50.0f);
    *out = 0;
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0x13) {
            *out = buf[i].val > 0;
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BC98);
#ifdef SKIP_ASM
struct sHit_BC98 { int type; int d[3]; };
extern "C" int func_0010BC98(char* self) {
    sHit_BC98 buf[12];
    char* rider = *(char**)(self + 0x18);
    char* q = *(char**)(rider + 0xAB8);
    char* vt = *(char**)(q + 0x34);
    int n = (*(int (**)(char*, sHit_BC98*, int, float, float))(vt + 0xC))(q + *(short*)(vt + 8), buf, 12, *(float*)(rider + 0x4C0), *(float*)(rider + 0x4C4));
    for (int i = 0; i < n; i++) {
        if (buf[i].type == 0xF) return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_1218", func_0010BD10);

//100%
INCLUDE_ASM("seg/seg_1218", func_0010BFA8);
#ifdef SKIP_ASM
struct sObj_BFA8 {
    char pad[0xE0C];
    int fE0C;
    int fE10;
    int fE14;
    int fE18;
    int fE1C;
    int fE20;
    char padE24[0x14];
    float fE38;
    float fE3C;
};

extern "C" void func_0010BFA8(sObj_BFA8* self, int a, int b, int c, int d)
{
    self->fE0C = -1;
    int* p = &self->fE10;
    *p = (a || b);
    self->fE14 = func_0010C1D0(self);
    self->fE20 = c;
    self->fE1C = d;
    self->fE18 = 0;
    if (self->fE10) {
        self->fE38 = a ? 1.0f : 0.0f;
        self->fE3C = b ? 1.0f : 0.0f;
        if (AIrand() & 1)
            self->fE38 = -self->fE38;
        if (AIrand() & 1)
            self->fE3C = -self->fE3C;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C0A8);
#ifdef SKIP_ASM
extern "C" void func_0010C0A8(void* self, void* padp)
{
    sPadW0* pad = (sPadW0*)padp;
    float len = Len(*(t4Vector*)(*(char**)((char*)self + 0x18) + 0x1E0));
    float s = 0.97f;
    if (len < 833.3334350585938f)
        s = 1.0f;
    if (*(float*)((char*)self + 0xDF8) < 20.0f)
        s = 0.0f;
    pad->w0 = (int)(s * 31.0f);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C140);
#ifdef SKIP_ASM
extern "C" void func_0010C140(void* self, void* padp)
{
    sPadW0* pad = (sPadW0*)padp;
    float len = Len(*(t4Vector*)(*(char**)((char*)self + 0x18) + 0x1E0));
    float s = 0.97f;
    if (len < 833.3334350585938f)
        s = 1.0f;
    pad->w0 = (int)(s * 31.0f);
    pad->b16 = 1;
    pad->b17 = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C1D0);
#ifdef SKIP_ASM
extern "C" int func_0010C1D0(void* self) {
    unsigned int r = AIrand();
    float thr = *(float*)((char*)self + 0xDFC) * 100.0f;
    return thr <= (float)(r % 100U);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C258);
#ifdef SKIP_ASM
extern "C" int func_0010C258(void* self) {
    if (*(unsigned int*)(*(char**)((char*)self + 0x18) + 0xB2C) & 1) {
        if (func_00144BE0(cBE_getInterface_C258(cBE_getBE(), 0)) != 0xE) {
            unsigned int r = AIrand();
            float thr = *(float*)((char*)self + 0xDFC) * 100.0f;
            return (float)(r % 100U) < thr;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C320);
#ifdef SKIP_ASM
extern "C" int func_0010C320(void* self) {
    unsigned int r = AIrand();
    float thr = *(float*)((char*)self + 0xDFC) * 70.0f + 30.0f;
    return (float)(r % 100U) < thr;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C3B8);
#ifdef SKIP_ASM
extern "C" int func_0010C3B8(void* self) {
    unsigned int r = AIrand();
    float thr = *(float*)((char*)self + 0xDFC) * 40.0f + 60.0f;
    return (float)(r % 100U) < thr;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1218", func_0010C450);
#ifdef SKIP_ASM
extern "C" int func_0010C450(void* self, int a, int b)
{
    switch (a) {
    case 1:
        if (b == 1)
            return 1;
        return (b == 2) ? 1 : 2;
    case 2:
        if (b == 1)
            return 1;
        return (b == 2) ? 1 : 2;
    case 3:
        if (b == 1)
            return 0;
        if (b == 2)
            return 1;
        return 1;
    case 4:
        if (b == 1)
            return 0;
        if (b == 2)
            return 0;
        return 1;
    case 5:
        if (b == 1)
            return 0;
        if (b == 2)
            return 0;
        return 0;
    }
    return 0;
}
#endif
