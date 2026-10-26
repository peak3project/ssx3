#include "common.h"

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_camaction);
#ifdef SKIP_ASM
extern "C" int get_uint(void* reader, void* dst);
extern "C" int get_cCTActionSwitchCam(void* reader, void* dst);
extern "C" int get_cCTActionBoundedCam(void* reader, char* obj);
extern "C" int get_cCTActionSpline(void* reader, void* dst);
void* get_cCTActionNone(void* unused, int* outType);
// PORT: the game's tagged allocator, bound as a placement operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");

struct sCTActVec3A {
    float x, y, z;
};

extern sCTActVec3A D_004FF0D8_act __asm__("D_004FF0D8");     // zero vector
extern void* D_0045C2E8[];      // cCTAction vtable
extern void* D_0045C1D0[];      // bounded cam
extern void* D_0045C1B8[];      // spline
extern char D_0045C0B0[];
extern char D_0045C0C8[];
extern char D_0045C0E0[];
extern char D_0045C0F8[];

// PORT: raw vtable stores stand in for the real virtual classes (vptr at 0x4, after `type`).
// Classes with their own vtable set `type` in their own ctor, after the derived vptr store.
struct sCTActA {
    int type;           // 0x00
    void** vtable;      // 0x04
    sCTActA()
    {
        vtable = D_0045C2E8;
    }
    sCTActA(int t)
    {
        vtable = D_0045C2E8;
        type = t;
    }
};

struct sCTActSwitchA : sCTActA {
    int target;         // 0x08
    float blend;        // 0x0C
    sCTActSwitchA() : sCTActA(0)
    {
        target = 0;
        blend = 1.0f;
    }
};

struct sCTActBoundedA : sCTActA {
    int f08;            // 0x08
    float blend;        // 0x0C
    float f10;          // 0x10
    float f14;          // 0x14
    float f18;          // 0x18
    float f1C;          // 0x1C
    int f20;            // 0x20
    int f24;            // 0x24
    sCTActVec3A f28;    // 0x28
    sCTActBoundedA() : sCTActA()
    {
        vtable = D_0045C1D0;
        type = 1;
        f08 = 0;
        blend = 1.0f;
        f14 = 0.5235987901687622f;
        f10 = 400.0f;
        f1C = 25.0f;
        f18 = 70.0f;
        f24 = 0;
        f28 = D_004FF0D8_act;
        f20 = 0;
    }
};

struct sCTActSplineA : sCTActA {
    int f08;            // 0x08
    float blend;        // 0x0C
    float f10;          // 0x10
    int f14;            // 0x14
    float f18;          // 0x18
    int f1C;            // 0x1C
    sCTActSplineA() : sCTActA()
    {
        vtable = D_0045C1B8;
        type = 2;
        f08 = 0;
        blend = 1.0f;
        f10 = 0.5235987901687622f;
        f14 = 0;
        f18 = 4.0f;
        f1C = 0;
    }
};

struct sCTActNoneA : sCTActA {
    sCTActNoneA() : sCTActA(3) {}
};

extern "C" int get_camaction(void* reader, void** out)
{
    int type;
    int n = get_uint(reader, &type);
    switch (type) {
    case 0: {
        sCTActSwitchA* o = new (D_0045C0B0, 0, 0) sCTActSwitchA;
        int r = get_cCTActionSwitchCam(reader, o);
        *out = o;
        n += r;
        break;
    }
    case 1: {
        sCTActBoundedA* o = new (D_0045C0C8, 0, 0) sCTActBoundedA;
        int r = get_cCTActionBoundedCam(reader, (char*)o);
        *out = o;
        n += r;
        break;
    }
    case 2: {
        sCTActSplineA* o = new (D_0045C0E0, 0, 0) sCTActSplineA;
        int r = get_cCTActionSpline(reader, o);
        *out = o;
        n += r;
        break;
    }
    case 3: {
        sCTActNoneA* o = new (D_0045C0F8, 0, 0) sCTActNoneA;
        // PORT: get_cCTActionNone returns the byte count as void*.
        int r = (int)get_cCTActionNone(reader, (int*)o);
        *out = o;
        n += r;
        break;
    }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTActionBoundedCam);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int get_float(void* reader, void* dst);
extern "C" int get_uint(void* reader, void* dst);
// get_t3Vector returns the byte count read (the unit declares it void*); bind an int-returning alias.
extern "C" int get_t3Vector_n(void* reader, void* dst) __asm__("get_t3Vector");

extern "C" int get_cCTActionBoundedCam(void* reader, char* obj)
{
    int n;
    *(int*)obj = 1;
    n = get_float(reader, obj + 0xC);
    n += get_float(reader, obj + 0x10);
    n += get_float(reader, obj + 0x14);
    n += get_float(reader, obj + 0x18);
    n += get_float(reader, obj + 0x1C);
    n += get_float(reader, obj + 0x20);
    n += get_uint(reader, obj + 0x24);
    n += get_t3Vector_n(reader, obj + 0x28);
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTActionSwitchCam);
#ifdef SKIP_ASM
extern "C" int get_float(void* reader, void* dst);
extern "C" int get_uint(void* reader, void* dst);

extern "C" int get_cCTActionSwitchCam(void* reader, void* dst)
{
    *(int*)dst = 0;
    int n = get_float(reader, (char*)dst + 0xC);
    return n + get_uint(reader, (char*)dst + 0x8);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTActionSpline);
#ifdef SKIP_ASM
extern "C" int get_cCTActionSpline(void* reader, void* dst)
{
    *(int*)dst = 2;
    int n = get_float(reader, (char*)dst + 0xC);
    n += get_float(reader, (char*)dst + 0x10);
    n += get_float(reader, (char*)dst + 0x14);
    n += get_float(reader, (char*)dst + 0x18);
    return n + get_float(reader, (char*)dst + 0x1C);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTActionNone__FPvPi);
#ifdef SKIP_ASM
void* get_cCTActionNone(void* unused, int* outType)
{
    *outType = 3;
    return 0;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_camboundobj);
#ifdef SKIP_ASM
// PORT: the game's tagged allocator, bound as a placement operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");

struct sCTVec3G {
    float x, y, z;
    sCTVec3G() {}
    sCTVec3G(float a, float b, float c) : x(a), y(b), z(c) {}
};

extern sCTVec3G D_004FF0D8;     // zero vector
extern void* D_0045C3F0[];      // cCTBoundObj vtable
extern void* D_0045C2A8[];      // ellipse
extern void* D_0045C268[];      // box
extern void* D_0045C228[];      // line
extern void* D_0045C1E8[];      // point
extern char D_0045C110[];
extern char D_0045C128[];
extern char D_0045C140[];
extern char D_0045C158[];

// PORT: raw vtable stores stand in for the real virtual classes: the base ctor stores the
// cCTBoundObj vtable first and the derived class's vtable last, where g++ 2.95 sets the
// derived vptr (after the base ctor, before the derived class's members are constructed).
struct sCTBoundObjG {
    sCTVec3G center;    // 0x00
    int f0C;            // 0x0C
    int f10;            // 0x10
    int f14;            // 0x14
    sCTVec3G size;      // 0x18
    void** vtable;      // 0x24
    sCTBoundObjG(const sCTVec3G& s, void** vt)
    {
        vtable = D_0045C3F0;
        center = D_004FF0D8;
        f0C = 0;
        f10 = 0;
        f14 = 0;
        size = s;
        vtable = vt;
    }
};

struct sCTBoundEllG : sCTBoundObjG {
    int type;           // 0x28
    sCTBoundEllG() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C2A8) { type = 0; }
};

struct sCTBoundBoxG : sCTBoundObjG {
    int type;           // 0x28
    sCTBoundBoxG() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C268) { type = 1; }
};

struct sCTBoundLineG : sCTBoundObjG {
    int type;           // 0x28
    sCTVec3G pts[2];    // 0x2C
    sCTBoundLineG() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C228)
    {
        type = 2;
        pts[0] = D_004FF0D8;
        pts[1] = D_004FF0D8;
    }
};

struct sCTBoundPointG : sCTBoundObjG {
    int type;           // 0x28
    sCTBoundPointG() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C1E8) { type = 3; }
};

class cCTBoundObjEllK2;
class cCTBoundObjBoxK2;
class cCTBoundObjLineK2;
struct sBoundObjPoint;
extern "C" int get_cCTBoundObjEllipse(void* reader, cCTBoundObjEllK2* obj);
extern "C" int get_cCTBoundObjBox(void* reader, cCTBoundObjBoxK2* obj);
extern "C" int get_cCTBoundObjLine(void* reader, cCTBoundObjLineK2* obj);
void* get_cCTBoundObjPoint(void* self, sBoundObjPoint* obj);

extern "C" int get_camboundobj(void* reader, void** out)
{
    int type;
    int n = get_uint(reader, &type);
    switch (type) {
    case 0: {
        sCTBoundEllG* o = new (D_0045C110, 0, 0) sCTBoundEllG;
        int r = get_cCTBoundObjEllipse(reader, (cCTBoundObjEllK2*)o);
        *out = o;
        n += r;
        break;
    }
    case 1: {
        sCTBoundBoxG* o = new (D_0045C128, 0, 0) sCTBoundBoxG;
        int r = get_cCTBoundObjBox(reader, (cCTBoundObjBoxK2*)o);
        *out = o;
        n += r;
        break;
    }
    case 2: {
        sCTBoundLineG* o = new (D_0045C140, 0, 0) sCTBoundLineG;
        int r = get_cCTBoundObjLine(reader, (cCTBoundObjLineK2*)o);
        *out = o;
        n += r;
        break;
    }
    case 3: {
        sCTBoundPointG* o = new (D_0045C158, 0, 0) sCTBoundPointG;
        // PORT: get_cCTBoundObjPoint returns the byte count as void*.
        int r = (int)get_cCTBoundObjPoint(reader, (sBoundObjPoint*)o);
        *out = o;
        n += r;
        break;
    }
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTBoundObjEllipse);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// get_t3Vector returns the byte count read (the unit declares it void*); bind an int-returning alias.
extern "C" int get_t3Vector_n(void* reader, void* dst) __asm__("get_t3Vector");

class cCTBoundObjEllK2 {
public:
    char pad_0x00[0x24];
    // vptr at 0x24; int at 0x28
    virtual void* center();
    virtual void* sizeX();
    virtual void* sizeY();
    virtual void* sizeZ();
    virtual void* axis();
};

extern "C" int get_cCTBoundObjEllipse(void* reader, cCTBoundObjEllK2* obj)
{
    int n;
    *(int*)((char*)obj + 0x28) = 0;
    n = get_t3Vector_n(reader, obj->center());
    n += get_t3Vector_n(reader, obj->axis());
    n += get_float(reader, obj->sizeX());
    n += get_float(reader, obj->sizeY());
    n += get_float(reader, obj->sizeZ());
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTBoundObjBox);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// get_t3Vector returns the byte count read (the unit declares it void*); bind an int-returning alias.
extern "C" int get_t3Vector_n(void* reader, void* dst) __asm__("get_t3Vector");

class cCTBoundObjBoxK2 {
public:
    char pad_0x00[0x24];
    // vptr at 0x24; int at 0x28
    virtual void* center();
    virtual void* sizeX();
    virtual void* sizeY();
    virtual void* sizeZ();
    virtual void* axis();
};

extern "C" int get_cCTBoundObjBox(void* reader, cCTBoundObjBoxK2* obj)
{
    int n;
    *(int*)((char*)obj + 0x28) = 1;
    n = get_t3Vector_n(reader, obj->center());
    n += get_t3Vector_n(reader, obj->axis());
    n += get_float(reader, obj->sizeX());
    n += get_float(reader, obj->sizeY());
    n += get_float(reader, obj->sizeZ());
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTBoundObjLine);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// get_t3Vector returns the byte count read (the unit declares it void*); bind an int-returning alias.
extern "C" int get_t3Vector_n(void* reader, void* dst) __asm__("get_t3Vector");

class cCTBoundObjLineK2 {
public:
    char pad_0x00[0x24];
    // vptr at 0x24; int at 0x28
    virtual void* center();
    virtual void* sizeX();
    virtual void* sizeY();
    virtual void* sizeZ();
    virtual void* axis();
};

extern "C" int get_cCTBoundObjLine(void* reader, cCTBoundObjLineK2* obj)
{
    int n;
    *(int*)((char*)obj + 0x28) = 2;
    n = get_t3Vector_n(reader, obj->center());
    n += get_t3Vector_n(reader, obj->axis());
    n += get_float(reader, obj->sizeX());
    n += get_float(reader, obj->sizeY());
    n += get_float(reader, obj->sizeZ());
    n += get_t3Vector_n(reader, (char*)obj + 0x2C);
    n += get_t3Vector_n(reader, (char*)obj + 0x38);
    return n;
}
#endif

struct sBoundObjVTable {
    char pad_0x00[0x8];
    short field_0x8;
    char pad_0xA[2];
    void* (*fn)(void*); // 0xC
};

struct sBoundObjPoint {
    char pad_0x00[0x24];
    sBoundObjVTable* vtable;
    int field_0x28;
};

extern "C" void* get_t3Vector(void* self, void* v);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTBoundObjPoint__FPvP14sBoundObjPoint);
#ifdef SKIP_ASM
void* get_cCTBoundObjPoint(void* self, sBoundObjPoint* obj)
{
    obj->field_0x28 = 3;
    void* result = obj->vtable->fn((char*)obj + obj->vtable->field_0x8);
    return get_t3Vector(self, result);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_camspline);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// get_t3Vector returns the byte count read (the unit declares it void*); bind an int-returning alias.
extern "C" int get_t3Vector_n(void* reader, void* dst) __asm__("get_t3Vector");
extern char D_0045C170[];

struct sCTSplineG : sCTBoundObjG {
    sCTVec3G pts[4];    // 0x28
    sCTSplineG() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C3F0)
    {
        pts[0] = D_004FF0D8;
        pts[1] = D_004FF0D8;
        pts[2] = D_004FF0D8;
        pts[3] = D_004FF0D8;
    }
};

class cCTSplineK2 {
public:
    char pad_0x00[0x24];
    // vptr at 0x24; control points at 0x28
    virtual void* center();
    virtual void* sizeX();
    virtual void* sizeY();
    virtual void* sizeZ();
    virtual void* axis();
};

extern "C" int get_camspline(void* reader, cCTSplineK2** out)
{
    int n;
    *out = (cCTSplineK2*)new (D_0045C170, 0, 0) sCTSplineG;
    n = get_t3Vector_n(reader, (*out)->center());
    n += get_t3Vector_n(reader, (*out)->axis());
    n += get_float(reader, (*out)->sizeX());
    n += get_float(reader, (*out)->sizeY());
    n += get_float(reader, (*out)->sizeZ());
    n += get_t3Vector_n(reader, (char*)*out + 0x28);
    n += get_t3Vector_n(reader, (char*)*out + 0x34);
    n += get_t3Vector_n(reader, (char*)*out + 0x40);
    n += get_t3Vector_n(reader, (char*)*out + 0x4C);
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00171FA8);
#ifdef SKIP_ASM
struct sVec4_171FA8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBox_171FA8 {
    sVec4_171FA8 lo;
    sVec4_171FA8 hi;
};

struct sVEbox_171FA8 {
    short delta;
    short index;
    sBox_171FA8 (*fn)(void*);
};

struct sVEin_171FA8 {
    short delta;
    short index;
    int (*fn)(void*, sVec4_171FA8*);
};

extern "C" float func_0040DA10(float x);

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_171FA8 Add_171FA8(const sVec4_171FA8& a, const sVec4_171FA8& b)
{
    sVec4_171FA8 r;
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

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_171FA8 Sub_171FA8(const sVec4_171FA8& a, const sVec4_171FA8& b)
{
    sVec4_171FA8 r;
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

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_171FA8 Scale_171FA8(const sVec4_171FA8& v, float s)
{
    sVec4_171FA8 r;
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_171FA8(const sVec4_171FA8& v)
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

static inline sBox_171FA8 GetBox_171FA8(char* o)
{
    sVEbox_171FA8* e = &(*(sVEbox_171FA8**)(o + 0x24))[6];
    return e->fn(o + e->delta);
}

static inline int Inside_171FA8(char* o, sVec4_171FA8* p)
{
    sVEin_171FA8* e = &(*(sVEin_171FA8**)(o + 0x24))[7];
    return e->fn(o + e->delta, p);
}

static inline sVec4_171FA8 Center_171FA8(const sBox_171FA8& b)
{
    return Scale_171FA8(Add_171FA8(b.lo, b.hi), 0.5f);
}

extern "C" sVec4_171FA8 func_00171FA8(char* obj, sVec4_171FA8* pos, float step)
{
    sVec4_171FA8 center = Center_171FA8(GetBox_171FA8(obj));
    sVec4_171FA8 dir = Sub_171FA8(*pos, center);
    sVec4_171FA8 a = *pos;
    sVec4_171FA8 b = center;
    float k = 2.0f;
    sVEin_171FA8* e;
    while (e = &(*(sVEin_171FA8**)(obj + 0x24))[7], e->fn(obj + e->delta, &a)) {
        b = a;
        sVec4_171FA8 off = Scale_171FA8(dir, k);
        a = Add_171FA8(center, off);
        k += k;
    }
    float len = Length_171FA8(Sub_171FA8(a, b));
    int n = (int)func_0040DA10(len / step) + 1;
    for (int i = 0; i < n; i++) {
        sVec4_171FA8 m = Scale_171FA8(Add_171FA8(a, b), 0.5f);
        e = &(*(sVEin_171FA8**)(obj + 0x24))[7];
        if (e->fn(obj + e->delta, &m)) {
            b = m;
        } else {
            a = m;
        }
    }
    return a;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001721C0);
#ifdef SKIP_ASM
extern "C" float func_001731C0(float* v);

struct sCTVec3K2 {
    float x, y, z;
    sCTVec3K2() {}
    sCTVec3K2(float a, float b, float c) : x(a), y(b), z(c) {}
};

static inline sCTVec3K2 operator-(const sCTVec3K2& a, float s)
{
    return sCTVec3K2(a.x - s, a.y - s, a.z - s);
}

static inline sCTVec3K2 operator+(const sCTVec3K2& a, float s)
{
    return sCTVec3K2(a.x + s, a.y + s, a.z + s);
}

struct sCTVec4K2 {
    float x, y, z, w;
    sCTVec4K2() {}
    sCTVec4K2(const sCTVec3K2& v, float w_) : x(v.x), y(v.y), z(v.z), w(w_) {}
} __attribute__((aligned(16)));

struct sCTBoxK2 {
    sCTVec4K2 min;
    sCTVec4K2 max;
    sCTBoxK2(const sCTVec4K2& a, const sCTVec4K2& b) : min(a), max(b) {}
};

// Bounding box of a trigger volume: centre +- the largest half-extent.
extern "C" sCTBoxK2 func_001721C0(char* obj)
{
    float r = func_001731C0((float*)(obj + 0x18));
    sCTVec3K2 rv(r, r, r);
    const sCTVec3K2& c = *(sCTVec3K2*)obj;
    return sCTBoxK2(sCTVec4K2(c - r, 1.0f), sCTVec4K2(c + r, 1.0f));
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00172278);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00172840);
#ifdef SKIP_ASM
extern "C" float func_001731C0(float* v);

struct sCTVec3K2b {
    float x, y, z;
    sCTVec3K2b() {}
    sCTVec3K2b(float a, float b, float c) : x(a), y(b), z(c) {}
};

static inline sCTVec3K2b operator-(const sCTVec3K2b& a, float s)
{
    return sCTVec3K2b(a.x - s, a.y - s, a.z - s);
}

static inline sCTVec3K2b operator+(const sCTVec3K2b& a, float s)
{
    return sCTVec3K2b(a.x + s, a.y + s, a.z + s);
}

struct sCTVec4K2b {
    float x, y, z, w;
    sCTVec4K2b() {}
    sCTVec4K2b(const sCTVec3K2b& v, float w_) : x(v.x), y(v.y), z(v.z), w(w_) {}
} __attribute__((aligned(16)));

struct sCTBoxK2b {
    sCTVec4K2b min;
    sCTVec4K2b max;
    sCTBoxK2b(const sCTVec4K2b& a, const sCTVec4K2b& b) : min(a), max(b) {}
};

// Bounding box of a trigger volume: centre +- the largest half-extent.
extern "C" sCTBoxK2b func_00172840(char* obj)
{
    float r = func_001731C0((float*)(obj + 0x18));
    sCTVec3K2b rv(r, r, r);
    const sCTVec3K2b& c = *(sCTVec3K2b*)obj;
    return sCTBoxK2b(sCTVec4K2b(c - r, 1.0f), sCTVec4K2b(c + r, 1.0f));
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001728F8);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_camvolume);
#ifdef SKIP_ASM
class cCTVolumeEllK2;
class cCTVolumeBoxK2;
extern "C" int get_cCTVolumeEllipse(void* reader, cCTVolumeEllK2* obj);
extern "C" int get_cCTVolumeBox(void* reader, cCTVolumeBoxK2* obj);
extern void* D_0045C350[];      // volume ellipse vtable
extern void* D_0045C300[];      // volume box vtable
extern char D_0045C188[];
extern char D_0045C1A0[];

struct sCTVolEllG : sCTBoundObjG {
    int type;           // 0x28
    sCTVolEllG() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C350) { type = 0; }
};

struct sCTVolBoxG : sCTBoundObjG {
    int type;           // 0x28
    sCTVolBoxG() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C300) { type = 1; }
};

extern "C" int get_camvolume(void* reader, void** out)
{
    int type;
    int n = get_uint(reader, &type);
    switch (type) {
    case 0: {
        sCTVolEllG* o = new (D_0045C188, 0, 0) sCTVolEllG;
        int r = get_cCTVolumeEllipse(reader, (cCTVolumeEllK2*)o);
        *out = o;
        n += r;
        break;
    }
    case 1: {
        sCTVolBoxG* o = new (D_0045C1A0, 0, 0) sCTVolBoxG;
        int r = get_cCTVolumeBox(reader, (cCTVolumeBoxK2*)o);
        *out = o;
        n += r;
        break;
    }
    default:
        *(int*)reader -= n;
        return 0;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTVolumeEllipse);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// get_t3Vector returns the byte count read (the unit declares it void*); bind an int-returning alias.
extern "C" int get_t3Vector_n(void* reader, void* dst) __asm__("get_t3Vector");

class cCTVolumeEllK2 {
public:
    char pad_0x00[0x24];
    // vptr at 0x24; int at 0x28
    virtual void* center();
    virtual void* sizeX();
    virtual void* sizeY();
    virtual void* sizeZ();
    virtual void* axis();
};

extern "C" int get_cCTVolumeEllipse(void* reader, cCTVolumeEllK2* obj)
{
    int n;
    *(int*)((char*)obj + 0x28) = 0;
    n = get_t3Vector_n(reader, obj->center());
    n += get_t3Vector_n(reader, obj->axis());
    n += get_float(reader, obj->sizeX());
    n += get_float(reader, obj->sizeY());
    n += get_float(reader, obj->sizeZ());
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", get_cCTVolumeBox);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// get_t3Vector returns the byte count read (the unit declares it void*); bind an int-returning alias.
extern "C" int get_t3Vector_n(void* reader, void* dst) __asm__("get_t3Vector");

class cCTVolumeBoxK2 {
public:
    char pad_0x00[0x24];
    // vptr at 0x24; int at 0x28
    virtual void* center();
    virtual void* sizeX();
    virtual void* sizeY();
    virtual void* sizeZ();
    virtual void* axis();
};

extern "C" int get_cCTVolumeBox(void* reader, cCTVolumeBoxK2* obj)
{
    int n;
    *(int*)((char*)obj + 0x28) = 1;
    n = get_t3Vector_n(reader, obj->center());
    n += get_t3Vector_n(reader, obj->axis());
    n += get_float(reader, obj->sizeX());
    n += get_float(reader, obj->sizeY());
    n += get_float(reader, obj->sizeZ());
    return n;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001731C0);
#ifdef SKIP_ASM
extern "C" float func_001731C0(float* v)
{
    float x = v[0];
    float y = v[1];
    float r = v[2];
    if (y < x) {
        if (r < x) {
            return x;
        }
    } else if (r < y) {
        r = y;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00173208);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001622B0(void* self);
extern void* D_0045C4C8[];
struct sQuad_00173208 {
    int v[4];
} __attribute__((aligned(16)));

extern sQuad_00173208 D_004FF130_00173208 __asm__("D_004FF130");

extern "C" void* func_00173208(void* self)
{
    func_001622B0(self);
    *(void***)((char*)self + 0x10) = D_0045C4C8;
    *(float*)((char*)self + 0x58) = 0.800000011920929f;
    *(float*)((char*)self + 0x5C) = 10.300000190734863f;
    *(float*)((char*)self + 0x60) = 1.100000023841858f;
    *(float*)((char*)self + 0x64) = 5.0f;
    *(float*)((char*)self + 0x68) = 10.0f;
    *(float*)((char*)self + 0x6C) = 70.0f;
    *(float*)((char*)self + 0x70) = 400.0f;
    *(int*)((char*)self + 0x74) = 0;
    *(float*)((char*)self + 0x78) = 20.0f;
    *(sQuad_00173208*)((char*)self + 0x40) = D_004FF130_00173208;
    *(int*)((char*)self + 0xC) = 0x5A;
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x50) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001732B8);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// PORT: the unit declares func_001732B8 as `void* (void*)` (callers pass the
// flags through in $a1); the real body takes (self, flags). Bound by asm label.
void func_001732B8_impl(void* self, int flags) __asm__("func_001732B8");

// deleting destructor: reset the vtable, free when bit 0 of flags is set
void func_001732B8_impl(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001732E8);
#ifdef SKIP_ASM
struct sVec4_1732E8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVL_1732E8 {
    short delta;
    short index;
    long (*fn)(void*);
};

struct sVV_1732E8 {
    short delta;
    short index;
    sVec4_1732E8 (*fn)(void*);
};

struct sVN_1732E8 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVec2_1732E8 {
    float x, y;
    sVec2_1732E8(float ax, float ay) : x(ax), y(ay) {}
};

extern "C" float func_0031C228(float x);
extern "C" void func_0031BE50(float* sout, float* cout, float x);
extern sVec4_1732E8 D_004FF160_1732E8 __asm__("D_004FF160");

// PORT: PS2-only VU0 inline asm (dst += b).
static inline void AddEq_1732E8(sVec4_1732E8& dst, const sVec4_1732E8& b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_1732E8 Sub_1732E8(const sVec4_1732E8& a, const sVec4_1732E8& b)
{
    sVec4_1732E8 r;
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

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_1732E8 Scale_1732E8(const sVec4_1732E8& v, float s)
{
    sVec4_1732E8 r;
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

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_1732E8(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_1732E8(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline float wrap_1732E8(float x)
{
    return x - ffloor_1732E8(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

static inline float Len2_1732E8(const sVec2_1732E8& v)
{
    return Sqrt_1732E8(v.x * v.x + v.y * v.y);
}

static inline float Atan2_1732E8(float y, float x)
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

extern "C" void func_001732E8_x(char* self, long key) __asm__("func_001732E8");
extern "C" void func_001732E8_x(char* self, long key)
{
    char* o = *(char**)(self + 0x30);
    char* r = *(char**)(o + 4) + 0x6C0;
    sVL_1732E8* e = &(*(sVL_1732E8**)r)[7];
    if (key != e->fn(r + e->delta))
        return;
    sVec4_1732E8 a, b, dir;
    {
        char* o1 = *(char**)(self + 0x30);
        sVV_1732E8* e1 = &(*(sVV_1732E8**)o1)[1];
        a = e1->fn(o1 + e1->delta);
    }
    {
        char* o2 = *(char**)(self + 0x30);
        sVV_1732E8* e2 = &(*(sVV_1732E8**)o2)[4];
        b = e2->fn(o2 + e2->delta);
    }
    AddEq_1732E8(a, Scale_1732E8(D_004FF160_1732E8, *(float*)(self + 0x6C)));
    AddEq_1732E8(a, Scale_1732E8(b, *(float*)(self + 0x74)));
    *(float*)(self + 0x50) = wrap_1732E8(Atan2_1732E8(b.y, b.x));
    float p = Atan2_1732E8(b.z, Len2_1732E8(sVec2_1732E8(b.x, b.y)));
    float mm = -*(float*)(self + 0x78) * 0.01745329424738884f;
    *(float*)(self + 0x54) = wrap_1732E8(p * -*(float*)(self + 0x58) + mm);
    float s0, c0, s1, c1;
    func_0031BE50(&s0, &c0, *(float*)(self + 0x50));
    func_0031BE50(&s1, &c1, -*(float*)(self + 0x54));
    dir.x = c1 * c0;
    dir.y = c1 * s0;
    dir.z = -s1;
    dir.w = 0.0f;
    *(sVec4_1732E8*)(self + 0x40) = Sub_1732E8(a, Scale_1732E8(dir, *(float*)(self + 0x70)));
    sVN_1732E8* v = &(*(sVN_1732E8**)(self + 0x10))[5];
    v->fn(self + v->delta);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00173678);
#ifdef SKIP_ASM
struct sVE173678a {
    short delta;
    short index;
    void* (*fn)(void*);
};

struct sVE173678b {
    short delta;
    short index;
    void* (*fn)(void*, void*);
};

extern "C" void* func_00173678(void* self)
{
    sVE173678b* vt = *(sVE173678b**)((char*)self + 0x10);
    char* o = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sVE173678a* vt2 = *(sVE173678a**)o;
    return vt[3].fn((char*)self + vt[3].delta, vt2[7].fn(o + vt2[7].delta));
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001736E0);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00173E40);
#ifdef SKIP_ASM
struct sV_173E40 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_173E40 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPair_173E40 {
    sV_173E40 a;
    sV_173E40 b;
};

extern sM_173E40 D_004FF1A0;
extern sV_173E40 D_004FF150;
extern sV_173E40 D_004FF160_v173E40 __asm__("D_004FF160");
extern "C" void func_0031BE50(float* sout, float* cout, float x);
extern "C" sPair_173E40 func_0031B748(sM_173E40* m);

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_173E40(sM_173E40* dst, const sM_173E40* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_173E40(sM_173E40* dst, const sM_173E40* a, const sM_173E40* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_173E40(sM_173E40* m, const sV_173E40& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

static inline void SinCos_173E40(float* s, float* c, float angle)
{
    func_0031BE50(s, c, angle);
}

static inline void RotAxis_173E40(sM_173E40* m, const sV_173E40& axis, float angle)
{
    sM_173E40 r;
    float s;
    float c;
    float one = 1.0f;
    SinCos_173E40(&s, &c, angle);
    float t = one - c;
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    r.m[0][0] = tx * x + c;
    r.m[1][0] = tx * y + sz;
    r.m[2][0] = tx * z - sy;
    r.m[0][1] = ty * x - sz;
    r.m[1][1] = ty * y + c;
    r.m[2][1] = ty * z + sx;
    r.m[0][2] = tz * x + sy;
    r.m[1][2] = tz * y - sx;
    r.m[2][2] = tz * z + c;
    r.m[3][0] = 0.0f;
    r.m[3][1] = 0.0f;
    r.m[3][2] = 0.0f;
    r.m[0][3] = 0.0f;
    r.m[1][3] = 0.0f;
    r.m[2][3] = 0.0f;
    r.m[3][3] = one;
    vu0MulMtx_173E40(m, m, &r);
}

extern "C" sPair_173E40 func_00173E40(char* src)
{
    sM_173E40 m;
    vu0CopyMtx_173E40(&m, &D_004FF1A0);
    vu0TransMtx_173E40(&m, *(sV_173E40*)(src + 0x40));
    RotAxis_173E40(&m, D_004FF150, -*(float*)(src + 0x54));
    RotAxis_173E40(&m, D_004FF160_v173E40, *(float*)(src + 0x50));
    return func_0031B748(&m);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00174190);
#ifdef SKIP_ASM
extern void* D_0045C458[];
extern "C" void* func_00173208(void* self);

extern "C" void* func_00174190(void* self)
{
    func_00173208(self);
    *(int*)((char*)self + 0xC) = 0x5B;
    *(void***)((char*)self + 0x10) = D_0045C458;
    *(int*)((char*)self + 0x80) = 0;
    *(int*)((char*)self + 0x74) = 0;
    return self;
}
#endif

extern void* D_0045C458[];
extern "C" void* func_001732B8(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001741D8__FPv);
#ifdef SKIP_ASM
void* func_001741D8(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045C458;
    return func_001732B8(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00174200);
#ifdef SKIP_ASM
struct sVec4_174200 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVE_174200 {
    short delta;
    short index;
    sVec4_174200 (*fn)(void*);
};

extern "C" float func_0031C228(float x);
extern sVec4_174200 D_004FF160_174200 __asm__("D_004FF160");

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_174200 Add_174200(const sVec4_174200& a, const sVec4_174200& b)
{
    sVec4_174200 r;
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

// PORT: PS2-only VU0 inline asm (d = a + b).
static inline void AddTo_174200(sVec4_174200& d, const sVec4_174200& a, const sVec4_174200& b)
{
    sVec4_174200 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    d = r;
}

// PORT: PS2-only VU0 inline asm (d = v * s).
static inline void ScaleTo_174200(sVec4_174200& d, const sVec4_174200& v, float s)
{
    sVec4_174200 r;
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
    d = r;
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_174200 Sub_174200(const sVec4_174200& a, const sVec4_174200& b)
{
    sVec4_174200 r;
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

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_174200 Scale_174200(const sVec4_174200& v, float s)
{
    sVec4_174200 r;
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

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_174200(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct sVec2_174200 {
    float x, y;
    sVec2_174200(float ax, float ay) : x(ax), y(ay) {}
};

static inline float Len2_174200(const sVec2_174200& v)
{
    return Sqrt_174200(v.x * v.x + v.y * v.y);
}

static inline float Atan2_174200(float y, float x)
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

extern "C" void func_00174200(char* self)
{
    char* act = *(char**)(self + 0x80);
    *(float*)(self + 0x70) = *(float*)(act + 0x10);
    *(float*)(self + 0x6C) = *(float*)(act + 0x18);
    *(float*)(self + 0x78) = *(float*)(act + 0x1C);
    *(float*)(self + 0x00) = *(float*)(act + 0x14);
    *(float*)(self + 0x74) = *(float*)(act + 0x20);
    sVec4_174200 p;
    if (*(int*)(act + 0x24) == 1) {
        p.x = *(float*)(act + 0x28);
        p.y = *(float*)(act + 0x2C);
        p.z = *(float*)(act + 0x30);
        p.w = 1.0f;
    } else {
        sVec4_174200 c, a, t, b;
        char* o = *(char**)(self + 0x30);
        sVE_174200* e = &(*(sVE_174200**)o)[1];
        ((void (*)(void*, void*))e->fn)(&a, o + e->delta);
        float k = *(float*)(self + 0x74);
        o = *(char**)(self + 0x30);
        e = &(*(sVE_174200**)o)[4];
        ((void (*)(void*, void*))e->fn)(&b, o + e->delta);
        ScaleTo_174200(t, b, k);
        AddTo_174200(c, a, t);
        sVec4_174200 t2;
        ScaleTo_174200(t2, D_004FF160_174200, *(float*)(self + 0x6C));
        AddTo_174200(p, c, t2);
    }
    *(sVec4_174200*)(self + 0x20) = p;
    {
        char* o = *(char**)(*(char**)(self + 0x80) + 8);
        sVE_174200* e = &(*(sVE_174200**)(o + 0x24))[6];
        ((void (*)(void*, void*))e->fn)(o + e->delta, self + 0x40);
    }
    sVec4_174200 d = Sub_174200(p, *(sVec4_174200*)(self + 0x40));
    *(float*)(self + 0x50) = Atan2_174200(d.y, d.x);
    *(float*)(self + 0x54) = Atan2_174200(d.z, Len2_174200(sVec2_174200(d.x, d.y)));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001744B0);
#ifdef SKIP_ASM
struct sVec4_1744B0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVE_1744B0 {
    short delta;
    short index;
    sVec4_1744B0 (*fn)(void*);
};

struct sVEL_1744B0 {
    short delta;
    short index;
    long (*fn)(void*);
};

extern "C" float func_0031C228(float x);
extern sVec4_1744B0 D_004FF160_1744B0 __asm__("D_004FF160");

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_1744B0 Add_1744B0(const sVec4_1744B0& a, const sVec4_1744B0& b)
{
    sVec4_1744B0 r;
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

// PORT: PS2-only VU0 inline asm (d = a + b).
static inline void AddTo_1744B0(sVec4_1744B0& d, const sVec4_1744B0& a, const sVec4_1744B0& b)
{
    sVec4_1744B0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    d = r;
}

// PORT: PS2-only VU0 inline asm (d = v * s).
static inline void ScaleTo_1744B0(sVec4_1744B0& d, const sVec4_1744B0& v, float s)
{
    sVec4_1744B0 r;
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
    d = r;
}

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_1744B0 Sub_1744B0(const sVec4_1744B0& a, const sVec4_1744B0& b)
{
    sVec4_1744B0 r;
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

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_1744B0 Scale_1744B0(const sVec4_1744B0& v, float s)
{
    sVec4_1744B0 r;
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

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_1744B0(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct sVec2_1744B0 {
    float x, y;
    sVec2_1744B0(float ax, float ay) : x(ax), y(ay) {}
};

static inline float Len2_1744B0(const sVec2_1744B0& v)
{
    return Sqrt_1744B0(v.x * v.x + v.y * v.y);
}

static inline float Atan2_1744B0(float y, float x)
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

extern "C" void func_001732E8(void* self, long a1);

extern "C" void func_001744B0(char* self, long a1)
{
    {
        char* o = *(char**)(*(char**)(self + 0x30) + 4) + 0x6C0;
        sVEL_1744B0* e = &(*(sVEL_1744B0**)o)[7];
        if (e->fn(o + e->delta) != a1)
            return;
    }
    char* act = *(char**)(self + 0x80);
    sVec4_1744B0 p;
    if (*(int*)(act + 0x24) == 1) {
        p.x = *(float*)(act + 0x28);
        p.y = *(float*)(act + 0x2C);
        p.z = *(float*)(act + 0x30);
        p.w = 1.0f;
    } else {
        sVec4_1744B0 c, a, t, b;
        char* o = *(char**)(self + 0x30);
        sVE_1744B0* e = &(*(sVE_1744B0**)o)[1];
        ((void (*)(void*, void*))e->fn)(&a, o + e->delta);
        float k = *(float*)(self + 0x74);
        o = *(char**)(self + 0x30);
        e = &(*(sVE_1744B0**)o)[4];
        ((void (*)(void*, void*))e->fn)(&b, o + e->delta);
        ScaleTo_1744B0(t, b, k);
        AddTo_1744B0(c, a, t);
        sVec4_1744B0 t2;
        ScaleTo_1744B0(t2, D_004FF160_1744B0, *(float*)(self + 0x6C));
        AddTo_1744B0(p, c, t2);
    }
    char* act2 = *(char**)(self + 0x80);
    *(float*)(self + 0x70) = *(float*)(act2 + 0x10);
    *(float*)(self + 0x6C) = *(float*)(act2 + 0x18);
    *(float*)(self + 0x78) = *(float*)(act2 + 0x1C);
    *(float*)(self + 0x00) = *(float*)(act2 + 0x14);
    *(float*)(self + 0x74) = *(float*)(act2 + 0x20);
    func_001732E8(self, a1);
    {
        char* o = *(char**)(*(char**)(self + 0x80) + 8);
        sVE_1744B0* e = &(*(sVE_1744B0**)(o + 0x24))[6];
        ((void (*)(void*, void*))e->fn)(o + e->delta, self + 0x40);
    }
    sVec4_1744B0 d = Sub_1744B0(p, *(sVec4_1744B0*)(self + 0x40));
    *(float*)(self + 0x50) = Atan2_1744B0(d.y, d.x);
    *(float*)(self + 0x54) = Atan2_1744B0(d.z, Len2_1744B0(sVec2_1744B0(d.x, d.y)));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001747A0);
#ifdef SKIP_ASM
struct sVE1747A0a {
    short delta;
    short index;
    void* (*fn)(void*);
};

struct sVE1747A0b {
    short delta;
    short index;
    void* (*fn)(void*, void*);
};

extern "C" void* func_001747A0(void* self)
{
    sVE1747A0b* vt = *(sVE1747A0b**)((char*)self + 0x10);
    char* o = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sVE1747A0a* vt2 = *(sVE1747A0a**)o;
    return vt[3].fn((char*)self + vt[3].delta, vt2[7].fn(o + vt2[7].delta));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00174808);
#ifdef SKIP_ASM
extern "C" void* func_00174808(void* self, ...)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00174848);
#ifdef SKIP_ASM
struct sCell_1748 {
    int level, x, y, z;
};
struct sVEnt1748 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

extern "C" void* func_0016C6B0(void*, void*);
extern "C" void cActiveTriggerList_add(void*, void*);
extern "C" void func_00176890(void* node, void* ctx);

// CameraCollisionCallback::operator()(cell)
static inline void trigCb_1748(char* ctx, void** node)
{
    char* e;
    for (e = (char*)node[10]; e != 0; e = *(char**)e) {
        if (*(int*)(e + 8) == 4) {
            char* trig = *(char**)(e + 0xC);
            char* sub = *(char**)(ctx + 4) + 0x6C0;
            char* bound = *(char**)(trig + 8);
            sVEnt1748* cvt = *(sVEnt1748**)sub;
            sVEnt1748* bvt = *(sVEnt1748**)(bound + 0x24);
            char* bthis = bound + bvt[7].delta;
            int r = cvt[5].fn(sub + cvt[5].delta);
            if (bvt[7].fn(bthis, r)) {
                void* f = func_0016C6B0(*(void**)ctx, trig);
                if (f) {
                    *(int*)((char*)f + 0xC) = 1;
                } else {
                    cActiveTriggerList_add(*(void**)ctx, trig);
                }
            }
        }
    }
}

// nash::Cell::descend<CameraCollisionCallback>, one level inlined
static inline void descend_1748(void** n, char* cb)
{
    trigCb_1748(cb, n);
    if (n[0] != 0) func_00176890(n[0], cb);
    if (n[1] != 0) func_00176890(n[1], cb);
    if (n[2] != 0) func_00176890(n[2], cb);
    if (n[3] != 0) func_00176890(n[3], cb);
    if (n[4] != 0) func_00176890(n[4], cb);
    if (n[5] != 0) func_00176890(n[5], cb);
    if (n[6] != 0) func_00176890(n[6], cb);
    if (n[7] != 0) func_00176890(n[7], cb);
}

extern "C" void func_00174848(char* self, char* cb, char* cb2, float* box, void** node, sCell_1748* cell)
{
    trigCb_1748(cb, node);
    if (cell->level == 11) {
        return;
    }
    int bits = (cell->level + 0x7E) << 23;
    float s = *(float*)&bits;
    sCell_1748 k;
    k.level = cell->level - 1;
    k.x = cell->x * 2;
    k.y = cell->y * 2;
    k.z = cell->z * 2;
    int ovLoX = 0;
    float xLoA = ((float)k.x - 0.2f) * s;
    float xLoB = ((float)(k.x + 1) + 0.2f) * s;
    if (box[0] < xLoB && xLoA < box[4]) ovLoX = 1;
    int ovHiX = 0;
    float xHiB = ((float)(k.x + 2) + 0.2f) * s;
    float xHiA = ((float)(k.x + 1) - 0.2f) * s;
    if (box[0] < xHiB && xHiA < box[4]) ovHiX = 1;
    if (ovLoX || ovHiX) {
        int ovLoY = 0;
        float yLoB = ((float)(k.y + 1) + 0.2f) * s;
        float yLoA = ((float)k.y - 0.2f) * s;
        if (box[1] < yLoB && yLoA < box[5]) ovLoY = 1;
        int ovHiY = 0;
        float yHiB = ((float)(k.y + 2) + 0.2f) * s;
        float yHiA = ((float)(k.y + 1) - 0.2f) * s;
        if (box[1] < yHiB && yHiA < box[5]) ovHiY = 1;
        if (ovLoY || ovHiY) {
            int ovLoZ = 0;
            float zLoB = ((float)(k.z + 1) + 0.2f) * s;
            float zLoA = ((float)k.z - 0.2f) * s;
            if (box[2] < zLoB && zLoA < box[6]) ovLoZ = 1;
            int ovHiZ = 0;
            float zHiB = ((float)(k.z + 2) + 0.2f) * s;
            float zHiA = ((float)(k.z + 1) - 0.2f) * s;
            if (box[2] < zHiB && zHiA < box[6]) ovHiZ = 1;
            if (ovLoZ || ovHiZ) {
                int inLoX = 0;
                if (box[0] < xLoA && xLoB < box[4]) inLoX = 1;
                int inHiX = 0;
                if (box[0] < xHiA && xHiB < box[4]) inHiX = 1;
                int inLoY = 0;
                if (box[1] < yLoA && yLoB < box[5]) inLoY = 1;
                int inHiY = 0;
                if (box[1] < yHiA && yHiB < box[5]) inHiY = 1;
                int inLoZ = 0;
                if (box[2] < zLoA && zLoB < box[6]) inLoZ = 1;
                int inHiZ = 0;
                if (box[2] < zHiA && zHiB < box[6]) inHiZ = 1;
                void** c;
                c = (void**)node[0];
                if (c != 0 && ovLoX && ovLoY && ovLoZ) {
                    if (inLoX && inLoY && inLoZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[1];
                k.z++;
                if (c != 0 && ovLoX && ovLoY && ovHiZ) {
                    if (inLoX && inLoY && inHiZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[3];
                k.y++;
                if (c != 0 && ovLoX && ovHiY && ovHiZ) {
                    if (inLoX && inHiY && inHiZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[2];
                k.z--;
                if (c != 0 && ovLoX && ovHiY && ovLoZ) {
                    if (inLoX && inHiY && inLoZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[6];
                k.x++;
                if (c != 0 && ovHiX && ovHiY && ovLoZ) {
                    if (inHiX && inHiY && inLoZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[7];
                k.z++;
                if (c != 0 && ovHiX && ovHiY && ovHiZ) {
                    if (inHiX && inHiY && inHiZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[5];
                k.y--;
                if (c != 0 && ovHiX && ovLoY && ovHiZ) {
                    if (inHiX && inLoY && inHiZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
                c = (void**)node[4];
                k.z--;
                if (c != 0 && ovHiX && ovLoY && ovLoZ) {
                    if (inHiX && inLoY && inLoZ) descend_1748(c, cb2);
                    else func_00174848(self, cb, cb2, box, c, &k);
                }
            }
        }
    }
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00175A20);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176270);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];

extern "C" void func_00176270(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762A0);
#ifdef SKIP_ASM
extern "C" void func_001762A0(void) {

}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762A8);
#ifdef SKIP_ASM
extern "C" void func_001762A8(void) {

}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762B0);
#ifdef SKIP_ASM
extern "C" void func_001762B0(void) {

}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762B8);
#ifdef SKIP_ASM
extern "C" float func_001762B8(void) {
    return 0.7853982f;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762C8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern long long D_004FF120;

extern "C" long long *func_001762C8(long long *arg0) {
    *arg0 = D_004FF120;
    return arg0;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762E0);
#ifdef SKIP_ASM
extern "C" void func_001762E0(void) {

}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762E8);
#ifdef SKIP_ASM
extern "C" void func_001762E8(void) {

}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001762F0);
#ifdef SKIP_ASM
class cTriggerVirt5 {
public:
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xC;
    // vptr at 0x10; slot N lives at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" void func_001762F0(cTriggerVirt5* self)
{
    self->v05();
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176318);
#ifdef SKIP_ASM
extern "C" void func_00176318(void) {

}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176320);
#ifdef SKIP_ASM
extern "C" int func_00176320(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176328);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00176328(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

typedef int cQuad128 __attribute__((mode(TI)));

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176358);
#ifdef SKIP_ASM
extern "C" void* func_00176358(void* self, void* a1)
{
    *(cQuad128*)self = *(cQuad128*)((char*)a1 + 0x20);
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176368);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00176368(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176398);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00176398(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001763C8);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_001763C8(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001763F8);
#ifdef SKIP_ASM
extern void* D_0045BDE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_001763F8(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_0045BDE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176428);
#ifdef SKIP_ASM
extern "C" void func_00176428(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x80))) = arg1;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176430);
#ifdef SKIP_ASM
extern "C" int func_00176430(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x80)));
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176438);
#ifdef SKIP_ASM
extern "C" int func_00176438(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176440__FPv);
#ifdef SKIP_ASM
void* func_00176440(void* self)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176448__FPv);
#ifdef SKIP_ASM
void* func_00176448(void* self)
{
    return (char*)self + 0xC;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176450__FPv);
#ifdef SKIP_ASM
void* func_00176450(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176458__FPv);
#ifdef SKIP_ASM
void* func_00176458(void* self)
{
    return (char*)self + 0x14;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176460__FPv);
#ifdef SKIP_ASM
void* func_00176460(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176468);
#ifdef SKIP_ASM
extern void* D_0045C3A0[];
inline void* operator new(unsigned int, void* p) { return p; }

struct sCTBoundK_6468 : sCTBoundObjG {
    sCTBoundK_6468() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C3A0) {}
};

extern "C" void* func_00176468(void* self)
{
    return new (self) sCTBoundK_6468;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001764E8);
#ifdef SKIP_ASM
extern "C" void* func_001764E8(void* self)
{
    return new (self) sCTVolEllG;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176570);
#ifdef SKIP_ASM
extern "C" void* func_00176570(void* self)
{
    return new (self) sCTVolBoxG;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001765F8__FPv);
#ifdef SKIP_ASM
void func_001765F8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176600);
#ifdef SKIP_ASM
extern "C" void* func_00176600(void* self)
{
    return new (self) sCTBoundEllG;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176688);
#ifdef SKIP_ASM
extern "C" void* func_00176688(void* self)
{
    return new (self) sCTBoundBoxG;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176710);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sCTBoundLineK : sCTBoundObjG {
    int type;
    sCTVec3G pts[2];
    sCTBoundLineK() __asm__("func_00176710");
};

sCTBoundLineK::sCTBoundLineK() : sCTBoundObjG(sCTVec3G(1.0f, 1.0f, 1.0f), D_0045C228)
{
    type = 2;
    pts[0] = D_004FF0D8;
    pts[1] = D_004FF0D8;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001767F8);
#ifdef SKIP_ASM
extern "C" int func_001767F8(int arg0) {
    return arg0 + 0x2C;
}
#endif
//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176800);
#ifdef SKIP_ASM
extern "C" int func_00176800(int arg0) {
    return arg0 + 0x38;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176808);
#ifdef SKIP_ASM
struct sVec4A16 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" void func_00176808(float* v, sVec4A16* out)
{
    sVec4A16 t;
    t.x = v[0];
    t.y = v[1];
    t.z = v[2];
    t.w = 1.0f;
    *out = t;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176840);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00176840(void* self)
{
    int* p = *(int**)((char*)self + 0x8);
    if (p != 0) {
        operator_delete(p);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176868);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00176868(void* self)
{
    int* p = *(int**)((char*)self + 0x8);
    if (p != 0) {
        operator_delete(p);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176890);
#ifdef SKIP_ASM
struct sVEnt176890 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

extern "C" void* func_0016C6B0(void*, void*);
extern "C" void cActiveTriggerList_add(void*, void*);

extern "C" void func_00176890(void* node, void* ctx)
{
    char* e;
    for (e = *(char**)((char*)node + 0x28); e != 0; e = *(char**)e) {
        if (*(int*)(e + 8) == 4) {
            char* trig = *(char**)(e + 0xC);
            char* sub = *(char**)((char*)ctx + 4) + 0x6C0;
            char* bound = *(char**)(trig + 8);
            sVEnt176890* cvt = *(sVEnt176890**)sub;
            sVEnt176890* bvt = *(sVEnt176890**)(bound + 0x24);
            char* bthis = bound + bvt[7].delta;
            int r = cvt[5].fn(sub + cvt[5].delta);
            if (bvt[7].fn(bthis, r)) {
                void* f = func_0016C6B0(*(void**)ctx, trig);
                if (f) {
                    *(int*)((char*)f + 0xC) = 1;
                } else {
                    cActiveTriggerList_add(*(void**)ctx, trig);
                }
            }
        }
    }
    if (*(void**)((char*)node + 0x0)) func_00176890(*(void**)((char*)node + 0x0), ctx);
    if (*(void**)((char*)node + 0x4)) func_00176890(*(void**)((char*)node + 0x4), ctx);
    if (*(void**)((char*)node + 0x8)) func_00176890(*(void**)((char*)node + 0x8), ctx);
    if (*(void**)((char*)node + 0xC)) func_00176890(*(void**)((char*)node + 0xC), ctx);
    if (*(void**)((char*)node + 0x10)) func_00176890(*(void**)((char*)node + 0x10), ctx);
    if (*(void**)((char*)node + 0x14)) func_00176890(*(void**)((char*)node + 0x14), ctx);
    if (*(void**)((char*)node + 0x18)) func_00176890(*(void**)((char*)node + 0x18), ctx);
    if (*(void**)((char*)node + 0x1C)) func_00176890(*(void**)((char*)node + 0x1C), ctx);
}
#endif

extern "C" void* func_00175A20(int, int);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176A28__FPv);
#ifdef SKIP_ASM
void* func_00176A28(void* self)
{
    return func_00175A20(1, 0xffff);
}
#endif

extern "C" void* func_00175A20(int, int);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176A48__FPv);
#ifdef SKIP_ASM
void* func_00176A48(void* self)
{
    return func_00175A20(0, 0xffff);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176A68);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045CAB0[];

extern "C" void* func_00176A68(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x3C;
    *(void***)((char*)self + 0x10) = D_0045CAB0;
    return self;
}
#endif

extern void* D_0045CAB0[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176AA8__FPv);
#ifdef SKIP_ASM
void* func_00176AA8(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045CAB0;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176AD0);
#ifdef SKIP_ASM
extern "C" float func_00176AD0(void* self)
{
    return 61.68796157836914f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176AE0);
#ifdef SKIP_ASM
extern "C" void func_00176AE0(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176B10);
#ifdef SKIP_ASM
struct sCamInfo_00178BB0;
extern "C" void func_00162568(void* self, sCamInfo_00178BB0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);
extern "C" void func_00162998(void* self, void* info);
extern "C" void func_00162A20(void* self, void* info);
extern "C" void func_00162B80(void* self, void* info);
extern "C" void func_00162C78(void* self, void* info);
extern "C" void func_00163010(void* self, void* info, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_00163270(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001633B0(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00162B90(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001635F8(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00164878(void* self, void* info, float a);
extern "C" void func_001646A0(void* self, void* info, float a, float b);
// PORT: the camera.cpp definition takes 7 floats; this caller passes an 8th in $f19.
extern "C" void func_00163450(void* self, void* info, float a, float b, float c, float d, float e, float f,
                              float g, float h);
extern "C" void func_001641C0(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_001643A8(void* self, void* info, float a, float b, float c);

struct sCamInfo_176B10
{
    char data[0x68];
} __attribute__((aligned(16)));

extern "C" void func_00176B10(char* self)
{
    sCamInfo_176B10 info;
    func_00162568(self, (sCamInfo_00178BB0*)&info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    func_00162998(self, &info);
    func_00162A20(self, &info);
    func_00162B80(self, &info);
    func_00162C78(self, &info);
    func_00163010(self, &info, 222.8457794189453f, 5.91639518737793f, 76.68663024902344f, 5.25f,
                  1.7668397426605225f, 0.9239780306816101f, 0.907414972782135f);
    func_00163270(self, &info, 5.74874210357666f, 27.03497314453125f, 8.82034969329834f, 7.998477935791016f,
                  0.9783917665481567f);
    func_001633B0(self, &info, 0.0f, 0.9651793837547302f, 1.0f, 0.949999988079071f);
    func_00163450(self, &info, 348.64111328125f, 66.33821868896484f, 162.2997283935547f, 2.00368070602417f, 0.0f,
                  0.9800000190734863f, 0.9599999785423279f, 0.4552607834339142f);
    func_00162B90(self, &info, 57.0410041809082f, 1.552131175994873f, 10.378137588500977f, 10.066482543945312f,
                  0.9241908192634583f);
    func_001635F8(self, &info, 1.840967059135437f, 2.494720935821533f, 0.0949358195066452f, 0.8546590209007263f);
    func_00164878(self, &info, 1.5269116163253784f);
    func_001646A0(self, &info, 120.85977172851562f, 0.9706981778144836f);
    func_001641C0(self, &info, 600.0f, 300.0f, 100.0f, 0.9800000190734863f);
    func_001643A8(self, &info, 15.0f, 1.5f, 1.5f);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176CE0);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);
class cCamTargetK8940 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
};
class cCamCtrlK8940 {
public:
    char pad_0x00[0x10];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" void func_00176CE0(cCamCtrlK8940* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTargetK8940*)(rider + 0x6C0))->v07()) {
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176D68);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045CA38[];

extern "C" void* func_00176D68(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x3D;
    *(void***)((char*)self + 0x10) = D_0045CA38;
    return self;
}
#endif

extern void* D_0045CA38[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176DA8__FPv);
#ifdef SKIP_ASM
void* func_00176DA8(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045CA38;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176DD0);
#ifdef SKIP_ASM
extern "C" float func_00176DD0(void* self)
{
    return 61.68796157836914f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176DE0);
#ifdef SKIP_ASM
extern "C" void func_00176DE0(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176E10);
#ifdef SKIP_ASM
struct sCamInfo_00178BB0;
extern "C" void func_00162568(void* self, sCamInfo_00178BB0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);
extern "C" void func_00162998(void* self, void* info);
extern "C" void func_00162A20(void* self, void* info);
extern "C" void func_00162B80(void* self, void* info);
extern "C" void func_00162C78(void* self, void* info);
extern "C" void func_00163010(void* self, void* info, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_00163270(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001633B0(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00162B90(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001635F8(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00164878(void* self, void* info, float a);
extern "C" void func_001646A0(void* self, void* info, float a, float b);
// PORT: the camera.cpp definition takes 7 floats; this caller passes an 8th in $f19.
extern "C" void func_00163450(void* self, void* info, float a, float b, float c, float d, float e, float f,
                              float g, float h);
extern "C" void func_001641C0(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_001643A8(void* self, void* info, float a, float b, float c);

struct sCamInfo_176E10
{
    char data[0x68];
} __attribute__((aligned(16)));

extern "C" void func_00176E10(char* self)
{
    sCamInfo_176E10 info;
    func_00162568(self, (sCamInfo_00178BB0*)&info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    func_00162998(self, &info);
    func_00162A20(self, &info);
    func_00162B80(self, &info);
    func_00162C78(self, &info);
    func_00163010(self, &info, 300.9249267578125f, 11.549837112426758f, 76.68663024902344f, 10.755208015441895f,
                  1.7668397426605225f, 0.9239780306816101f, 0.907414972782135f);
    func_00163270(self, &info, 11.678784370422363f, 31.225603103637695f, 11.392387390136719f, 9.33469009399414f,
                  0.9783917665481567f);
    func_001633B0(self, &info, 0.0f, 0.9599078297615051f, 1.0f, 0.949999988079071f);
    func_00163450(self, &info, 348.64111328125f, 66.33821868896484f, 162.2997283935547f, 2.00368070602417f, 0.0f,
                  0.9800000190734863f, 0.9599999785423279f, 0.4552607834339142f);
    func_00162B90(self, &info, 31.10257339477539f, 0.37469127774238586f, 12.332656860351562f, 10.589057922363281f,
                  0.9241908192634583f);
    func_001635F8(self, &info, 1.8110172748565674f, 2.494720935821533f, 0.13641449809074402f, 0.8536682724952698f);
    func_00164878(self, &info, 1.5269116163253784f);
    func_001646A0(self, &info, 146.38900756835938f, 0.9706981778144836f);
    func_001641C0(self, &info, 600.0f, 300.0f, 100.0f, 0.9800000190734863f);
    func_001643A8(self, &info, 15.0f, 1.5f, 1.5f);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00176FE0);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);
extern "C" void func_00176FE0(cCamCtrlK8940* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTargetK8940*)(rider + 0x6C0))->v07()) {
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177068);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045C9C0[];

extern "C" void* func_00177068(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x3E;
    *(void***)((char*)self + 0x10) = D_0045C9C0;
    return self;
}
#endif

extern void* D_0045C9C0[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001770A8__FPv);
#ifdef SKIP_ASM
void* func_001770A8(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045C9C0;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001770D0);
#ifdef SKIP_ASM
extern "C" float func_001770D0(void* self)
{
    return 61.68796157836914f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001770E0);
#ifdef SKIP_ASM
extern "C" void func_001770E0(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177110);
#ifdef SKIP_ASM
struct sCamInfo_00178BB0;
extern "C" void func_00162568(void* self, sCamInfo_00178BB0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);
extern "C" void func_00162998(void* self, void* info);
extern "C" void func_00162A20(void* self, void* info);
extern "C" void func_00162B80(void* self, void* info);
extern "C" void func_00162C78(void* self, void* info);
extern "C" void func_00163010(void* self, void* info, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_00163270(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001633B0(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00162B90(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001635F8(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00164878(void* self, void* info, float a);
extern "C" void func_001646A0(void* self, void* info, float a, float b);
// PORT: the camera.cpp definition takes 7 floats; this caller passes an 8th in $f19.
extern "C" void func_00163450(void* self, void* info, float a, float b, float c, float d, float e, float f,
                              float g, float h);
extern "C" void func_001641C0(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_001643A8(void* self, void* info, float a, float b, float c);

struct sCamInfo_177110
{
    char data[0x68];
} __attribute__((aligned(16)));

extern "C" void func_00177110(char* self)
{
    sCamInfo_177110 info;
    func_00162568(self, (sCamInfo_00178BB0*)&info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    func_00162998(self, &info);
    func_00162A20(self, &info);
    func_00162B80(self, &info);
    func_00162C78(self, &info);
    func_00163010(self, &info, 505.79815673828125f, 11.549837112426758f, 76.68663024902344f, 11.38194465637207f,
                  1.7668397426605225f, 0.9239780306816101f, 0.907414972782135f);
    func_00163270(self, &info, 13.021197319030762f, 98.84776306152344f, 12.293619155883789f, 13.058300971984863f,
                  0.9783917665481567f);
    func_001633B0(self, &info, 0.0f, 0.9653480052947998f, 1.0f, 0.949999988079071f);
    func_00163450(self, &info, 348.64111328125f, 66.33821868896484f, 162.2997283935547f, 2.00368070602417f, 0.0f,
                  0.9800000190734863f, 0.9599999785423279f, 0.4552607834339142f);
    func_00162B90(self, &info, 50.02703094482422f, 2.5781052112579346f, 13.97744369506836f, 10.748767852783203f,
                  0.9241908192634583f);
    func_001635F8(self, &info, 1.878627061843872f, 2.494720935821533f, 0.10213389247655869f, 0.8599911332130432f);
    func_00164878(self, &info, 1.5269116163253784f);
    func_001646A0(self, &info, 167.9465789794922f, 0.9706981778144836f);
    func_001641C0(self, &info, 600.0f, 300.0f, 100.0f, 0.9800000190734863f);
    func_001643A8(self, &info, 15.0f, 1.5f, 1.5f);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001772E0);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);
extern "C" void func_001772E0(cCamCtrlK8940* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTargetK8940*)(rider + 0x6C0))->v07()) {
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177368);
#ifdef SKIP_ASM
struct sCamInfo_00178BB0;
extern "C" void func_00162568(void* self, sCamInfo_00178BB0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);
extern "C" void func_00162998(void* self, void* info);
extern "C" void func_00162A20(void* self, void* info);
extern "C" void func_00162B80(void* self, void* info);
extern "C" void func_00162C78(void* self, void* info);
extern "C" void func_00163010(void* self, void* info, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_00163270(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001633B0(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00162B90(void* self, void* info, float a, float b, float c, float d, float e);
extern "C" void func_001635F8(void* self, void* info, float a, float b, float c, float d);
extern "C" void func_00164878(void* self, void* info, float a);
extern "C" void func_001646A0(void* self, void* info, float a, float b);
extern "C" void func_00165540(void* self, float ang);

struct sCamInfo_177368
{
    char data[0x68];
} __attribute__((aligned(16)));

extern "C" void func_00177368(char* self)
{
    sCamInfo_177368 info;
    func_00162568(self, (sCamInfo_00178BB0*)&info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    func_00162998(self, &info);
    func_00162A20(self, &info);
    func_00162B80(self, &info);
    func_00162C78(self, &info);
    func_00163010(self, &info, 356.4251708984375f, 0.0f, 76.68663024902344f, 0.0f, 1.6834967136383057f,
                  0.9239780306816101f, 0.907414972782135f);
    func_00163270(self, &info, 0.0f, -168.60406494140625f, 0.0f, 0.0f, 0.9783917665481567f);
    func_001633B0(self, &info, 0.0f, 0.9709749817848206f, 1.0f, 0.949999988079071f);
    func_00162B90(self, &info, -0.24752351641654968f, 0.008603549562394619f, 0.12915411591529846f,
                  0.22476252913475037f, 0.9241908192634583f);
    func_001635F8(self, &info, 1.878627061843872f, 2.494720935821533f, 0.19890090823173523f, 0.8672914505004883f);
    func_00164878(self, &info, 1.5269116163253784f);
    func_001646A0(self, &info, 0.0f, 0.9706981778144836f);
    func_00165540(self, *(float*)(self + 0x390));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001774C0);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045CB28[];

extern "C" void* func_001774C0(void* self, int n)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = n + 0x12;
    *(void***)((char*)self + 0x10) = D_0045CB28;
    *(float*)((char*)self + 0x390) = (float)n * 0.7853981852531433f;
    return self;
}
#endif

extern void* D_0045CB28[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177520__FPv);
#ifdef SKIP_ASM
void* func_00177520(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045CB28;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177548__FPv);
#ifdef SKIP_ASM
float func_00177548(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177558);
#ifdef SKIP_ASM
extern "C" void func_00177558(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177588);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);
extern "C" void func_00177588(cCamCtrlK8940* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTargetK8940*)(rider + 0x6C0))->v07()) {
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177610);
#ifdef SKIP_ASM
extern "C" void* func_00177610(void* self, ...)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177650);
#ifdef SKIP_ASM
extern float D_004C5890[4];
extern float D_004C58A0[4];
extern float D_004C58B0[4];
extern float D_004C58C0[4];
extern float D_004C58D0[4];
extern float D_004C58E0[4];
extern float D_004C58F0[4];
extern float D_004C5900[4];
extern float D_004C5910[4];
extern float D_004C5920[4];
extern float D_004C5930[4];
extern float D_004C5940[4];
extern float D_004C5950[4];
extern float D_004C5960[4];
extern float D_004C5970[4];
extern float D_004C5980[4];
extern float D_004C5990[4];
extern float D_004C59A0[4];
extern float D_004C59B0[4];
extern float D_004C59C0[4];
extern float D_004C59D0[4];
extern float D_004C59E0[4];
extern float D_004C59F0[4];
extern float D_004C5A00[4];
extern float D_004C5A10[4];
extern float D_004C5A20[4];
extern float D_004C5A30[4];
extern float D_004C5A40[4];
extern float D_004C5A50[4];
extern float D_004C5A60[4];
extern float D_004C5A70[4];
extern float D_004C5A80[4];
extern float D_004C5A90[4];
extern float D_004C5AA0[4];
extern float D_004C5AB0[4];
extern float D_004C5AC0[4];
extern float D_004C5AD0[4];
extern float D_004C5AE0[4];
extern float D_004C5AF0[4];
extern float D_004C5B00[4];
extern float D_004C5B10[4];
extern float D_004C5B20[4];
extern float D_004C5B30[4];
extern float D_004C5B40[4];
extern float D_004C5B50[4];
extern float D_004C5B60[4];
extern float D_004C5B70[4];
extern float D_004C5B80[4];
extern float D_004C5B90[4];
extern float D_004C5BA0[4];
extern float D_004C5BB0[4];
extern float D_004C5BC0[4];
extern float D_004C5BD0[4];
extern float D_004C5BE0[4];
extern float D_004C5BF0[4];
extern float D_004C5C00[4];

void sti_00177650(int init, int prio) __asm__("func_00177650");
void sti_00177650(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004C5890[0] = 1.0f;
        D_004C5890[1] = 1.0f;
        D_004C5890[2] = 1.0f;
        D_004C5890[3] = 0.5f;
        D_004C58A0[0] = 0.4998680055141449f;
        D_004C58A0[1] = 1.0f;
        D_004C58A0[2] = 1.0f;
        D_004C58A0[3] = 0.0f;
        D_004C58B0[0] = 0.12951700389385223f;
        D_004C58B0[1] = 1.0f;
        D_004C58B0[2] = 1.0f;
        D_004C58B0[3] = 0.0f;
        D_004C58C0[0] = 0.22426900267601013f;
        D_004C58C0[1] = 0.9402310252189636f;
        D_004C58C0[2] = 0.5425059795379639f;
        D_004C58C0[3] = 0.0004030000127386302f;
        D_004C58D0[0] = 0.4652079939842224f;
        D_004C58D0[1] = 0.32170501351356506f;
        D_004C58D0[2] = 0.9943439960479736f;
        D_004C58D0[3] = 0.0f;
        D_004C58E0[0] = 0.17792600393295288f;
        D_004C58E0[1] = 1.0f;
        D_004C58E0[2] = 1.0f;
        D_004C58E0[3] = 0.0f;
        D_004C58F0[0] = 0.4411740005016327f;
        D_004C58F0[1] = 0.41388601064682007f;
        D_004C58F0[2] = 0.3211260139942169f;
        D_004C58F0[3] = 0.4398239850997925f;
        D_004C5900[0] = 0.500997006893158f;
        D_004C5900[1] = 0.24849599599838257f;
        D_004C5900[2] = 1.0f;
        D_004C5900[3] = 1.0f;
        D_004C5910[0] = 0.27687299251556396f;
        D_004C5910[1] = 0.6395620107650757f;
        D_004C5910[2] = 0.13423900306224823f;
        D_004C5910[3] = 0.0f;
        D_004C5920[0] = 0.8936439752578735f;
        D_004C5920[1] = 0.5263469815254211f;
        D_004C5920[2] = 0.5051450133323669f;
        D_004C5920[3] = 0.8687300086021423f;
        D_004C5930[0] = 1.0f;
        D_004C5930[1] = 1.0f;
        D_004C5930[2] = 1.0f;
        D_004C5930[3] = 1.0f;
        D_004C5940[0] = 1.0f;
        D_004C5940[1] = 0.0f;
        D_004C5940[2] = 0.0f;
        D_004C5940[3] = 0.0f;
        D_004C5950[0] = 1.0f;
        D_004C5950[1] = 0.550000011920929f;
        D_004C5950[2] = 0.5350000262260437f;
        D_004C5950[3] = 0.550000011920929f;
        D_004C5960[0] = 1.0f;
        D_004C5960[1] = 1.0f;
        D_004C5960[2] = 1.0f;
        D_004C5960[3] = 1.0f;
        D_004C5970[0] = 1.0f;
        D_004C5970[1] = 1.0f;
        D_004C5970[2] = 1.0f;
        D_004C5970[3] = 1.0f;
        D_004C5980[0] = 1.0f;
        D_004C5980[1] = 0.0f;
        D_004C5980[2] = 0.0f;
        D_004C5980[3] = 0.0f;
        D_004C5990[0] = 1.0f;
        D_004C5990[1] = 0.0f;
        D_004C5990[2] = 0.0f;
        D_004C5990[3] = 0.0f;
        D_004C59A0[0] = 1.0f;
        D_004C59A0[1] = 1.0f;
        D_004C59A0[2] = 1.0f;
        D_004C59A0[3] = 1.0f;
        D_004C59B0[0] = 1.0f;
        D_004C59B0[1] = 0.5f;
        D_004C59B0[2] = 1.0f;
        D_004C59B0[3] = 0.5f;
        D_004C59C0[0] = 1.0f;
        D_004C59C0[1] = 0.5f;
        D_004C59C0[2] = 1.0f;
        D_004C59C0[3] = 0.5f;
        D_004C59D0[0] = 1.0f;
        D_004C59D0[1] = 0.5f;
        D_004C59D0[2] = 1.0f;
        D_004C59D0[3] = 0.5f;
        D_004C59E0[0] = 1.0f;
        D_004C59E0[1] = 0.7828119993209839f;
        D_004C59E0[2] = 0.06171900033950806f;
        D_004C59E0[3] = 0.03984399884939194f;
        D_004C59F0[0] = 1.0f;
        D_004C59F0[1] = 1.0f;
        D_004C59F0[2] = 0.7988259792327881f;
        D_004C59F0[3] = 0.0f;
        D_004C5A00[0] = 0.9886710047721863f;
        D_004C5A00[1] = 0.9230499863624573f;
        D_004C5A00[2] = 0.34311699867248535f;
        D_004C5A00[3] = 0.0f;
        D_004C5A10[0] = 1.0f;
        D_004C5A10[1] = 1.0f;
        D_004C5A10[2] = 1.0f;
        D_004C5A10[3] = 1.0f;
        D_004C5A20[0] = 1.0f;
        D_004C5A20[1] = 1.0f;
        D_004C5A20[2] = 0.7976430058479309f;
        D_004C5A20[3] = 0.0f;
        D_004C5A30[0] = 1.0f;
        D_004C5A30[1] = 0.9222670197486877f;
        D_004C5A30[2] = 0.34179699420928955f;
        D_004C5A30[3] = 0.0f;
        D_004C5A40[0] = 1.0f;
        D_004C5A40[1] = 0.7847639918327332f;
        D_004C5A40[2] = 0.06054700165987015f;
        D_004C5A40[3] = 0.04062499850988388f;
        D_004C5A50[0] = 1.0f;
        D_004C5A50[1] = 0.800000011920929f;
        D_004C5A50[2] = 0.44999998807907104f;
        D_004C5A50[3] = 1.0f;
        D_004C5A60[0] = 1.0f;
        D_004C5A60[1] = 0.3281260132789612f;
        D_004C5A60[2] = 1.0f;
        D_004C5A60[3] = 0.3539060056209564f;
        D_004C5A70[0] = 1.0f;
        D_004C5A70[1] = 1.0f;
        D_004C5A70[2] = 1.0f;
        D_004C5A70[3] = 1.0f;
        D_004C5A80[0] = 1.0f;
        D_004C5A80[1] = 1.0f;
        D_004C5A80[2] = 1.0f;
        D_004C5A80[3] = 1.0f;
        D_004C5A90[0] = 1.0f;
        D_004C5A90[1] = 0.8613290190696716f;
        D_004C5A90[2] = 0.38124799728393555f;
        D_004C5A90[3] = 0.0f;
        D_004C5AA0[0] = 1.0f;
        D_004C5AA0[1] = 1.0f;
        D_004C5AA0[2] = 1.0f;
        D_004C5AA0[3] = 1.0f;
        D_004C5AB0[0] = 1.0f;
        D_004C5AB0[1] = 0.3244380056858063f;
        D_004C5AB0[2] = 1.0f;
        D_004C5AB0[3] = 0.0f;
        D_004C5AC0[0] = 1.0f;
        D_004C5AC0[1] = 1.0f;
        D_004C5AC0[2] = 1.0f;
        D_004C5AC0[3] = 1.0f;
        D_004C5AD0[0] = 1.0f;
        D_004C5AD0[1] = 1.0f;
        D_004C5AD0[2] = 0.0f;
        D_004C5AD0[3] = 0.0f;
        D_004C5AE0[0] = 0.7007060050964355f;
        D_004C5AE0[1] = 0.0f;
        D_004C5AE0[2] = 0.0f;
        D_004C5AE0[3] = 0.0f;
        D_004C5AF0[0] = 1.0f;
        D_004C5AF0[1] = 0.7828530073165894f;
        D_004C5AF0[2] = 0.06140600144863129f;
        D_004C5AF0[3] = 0.04146299883723259f;
        D_004C5B00[0] = 1.0f;
        D_004C5B00[1] = 0.32487601041793823f;
        D_004C5B00[2] = 1.0f;
        D_004C5B00[3] = 0.35280099511146545f;
        D_004C5B10[0] = 1.0f;
        D_004C5B10[1] = 1.0f;
        D_004C5B10[2] = 0.7977359890937805f;
        D_004C5B10[3] = 0.0f;
        D_004C5B20[0] = 1.0f;
        D_004C5B20[1] = 0.4937489926815033f;
        D_004C5B20[2] = 1.0f;
        D_004C5B20[3] = 0.49179700016975403f;
        D_004C5B30[0] = 1.0f;
        D_004C5B30[1] = 1.0f;
        D_004C5B30[2] = 1.0f;
        D_004C5B30[3] = 1.0f;
        D_004C5B40[0] = 1.0f;
        D_004C5B40[1] = 0.800000011920929f;
        D_004C5B40[2] = 1.0f;
        D_004C5B40[3] = 0.800000011920929f;
        D_004C5B50[0] = 1.0f;
        D_004C5B50[1] = 1.0f;
        D_004C5B50[2] = 0.0f;
        D_004C5B50[3] = 0.0f;
        D_004C5B60[0] = 1.0f;
        D_004C5B60[1] = 1.0f;
        D_004C5B60[2] = 0.0f;
        D_004C5B60[3] = 0.0f;
        D_004C5B70[0] = 1.0f;
        D_004C5B70[1] = 1.0f;
        D_004C5B70[2] = 0.0f;
        D_004C5B70[3] = 0.0f;
        D_004C5B80[0] = 1.0f;
        D_004C5B80[1] = 0.3273420035839081f;
        D_004C5B80[2] = 1.0f;
        D_004C5B80[3] = 0.35390499234199524f;
        D_004C5B90[0] = 1.0f;
        D_004C5B90[1] = 1.0f;
        D_004C5B90[2] = 0.061000000685453415f;
        D_004C5B90[3] = 0.039000000804662704f;
        D_004C5BA0[0] = 1.0f;
        D_004C5BA0[1] = 1.0f;
        D_004C5BA0[2] = 0.7999979853630066f;
        D_004C5BA0[3] = 0.0f;
        D_004C5BB0[0] = 1.0f;
        D_004C5BB0[1] = 0.9589840173721313f;
        D_004C5BB0[2] = 0.6143789887428284f;
        D_004C5BB0[3] = 0.0f;
        D_004C5BC0[0] = 1.0f;
        D_004C5BC0[1] = 0.9285150170326233f;
        D_004C5BC0[2] = 0.3399839997291565f;
        D_004C5BC0[3] = 0.0f;
        D_004C5BD0[0] = 1.0f;
        D_004C5BD0[1] = 0.8738250136375427f;
        D_004C5BD0[2] = 0.24931700527668f;
        D_004C5BD0[3] = 0.017578000202775f;
        D_004C5BE0[0] = 1.0f;
        D_004C5BE0[1] = 0.7843739986419678f;
        D_004C5BE0[2] = 0.06132800132036209f;
        D_004C5BE0[3] = 0.03945299983024597f;
        D_004C5BF0[0] = 1.0f;
        D_004C5BF0[1] = 0.0f;
        D_004C5BF0[2] = 1.0f;
        D_004C5BF0[3] = 0.0f;
        D_004C5C00[0] = 1.0f;
        D_004C5C00[1] = 1.0f;
        D_004C5C00[2] = 0.0f;
        D_004C5C00[3] = 0.0f;
    }
}
#endif

extern "C" void* func_00177650(int, int);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177E28);
#ifdef SKIP_ASM
extern "C" void func_00177E28(void) {

}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177E30__FPv);
#ifdef SKIP_ASM
void* func_00177E30(void* self)
{
    return func_00177650(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177E50);
#ifdef SKIP_ASM
extern "C" void* func_00162318(void* self);
extern void* D_0045CCC8[];

extern "C" void* func_00177E50(void* self)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x42;
    *(void***)((char*)self + 0x10) = D_0045CCC8;
    return self;
}
#endif

extern void* D_0045CCC8[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177E90__FPv);
#ifdef SKIP_ASM
void* func_00177E90(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045CCC8;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177EB8);
#ifdef SKIP_ASM
extern "C" float func_00177EB8(void* self)
{
    return 61.68796157836914f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177EC8);
#ifdef SKIP_ASM
extern "C" void func_00177EC8(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177EF8);
#ifdef SKIP_ASM
struct sVec_00177EF8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVEa_00177EF8 {
    short delta;
    short index;
    sVec_00177EF8* (*fn)(void*);
};

struct sVEb_00177EF8 {
    short delta;
    short index;
    sVec_00177EF8 (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec_00177EF8 ctScale_00177EF8(const sVec_00177EF8& v, float s)
{
    sVec_00177EF8 r;
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
static inline sVec_00177EF8 ctAdd_00177EF8(const sVec_00177EF8& a, const sVec_00177EF8& b)
{
    sVec_00177EF8 r;
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

static inline sVec_00177EF8 ctGetB_00177EF8(void* self)
{
    char* o2 = *(char**)((char*)self + 0x30);
    sVEb_00177EF8* e2 = &(*(sVEb_00177EF8**)o2)[1];
    return e2->fn(o2 + e2->delta);
}

extern "C" sVec_00177EF8 func_00177EF8(void* self)
{
    char* o = *(char**)(*(char**)((char*)self + 0x30) + 4) + 0x6C0;
    sVEa_00177EF8* e = &(*(sVEa_00177EF8**)o)[5];
    sVec_00177EF8* v = e->fn(o + e->delta);
    return ctAdd_00177EF8(ctScale_00177EF8(*v, 0.19999998807907104f), ctScale_00177EF8(ctGetB_00177EF8(self), 0.800000011920929f));
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00177FC0);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178208);
#ifdef SKIP_ASM
struct sVec4_8208 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCamInfo_00178BB0;
extern sVec4_8208 D_004FF160_8208 __asm__("D_004FF160");
extern "C" void func_00162568(void* self, sCamInfo_00178BB0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_8208 Sub_8208(const sVec4_8208& a, const sVec4_8208& b)
{
    sVec4_8208 r;
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

// PORT: PS2-only VU0 inline asm (*v * s).
static inline sVec4_8208 ScaleP_8208(const sVec4_8208* v, float s)
{
    sVec4_8208 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "o"(*v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_8208(const sVec4_8208& v)
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
// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_8208 Add_8208(const sVec4_8208& a, const sVec4_8208& b)
{
    sVec4_8208 r;
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

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_8208 Scale_8208(const sVec4_8208& v, float s)
{
    sVec4_8208 r;
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

// PORT: PS2-only VU0 inline asm (dst = a + b).
static inline void AddD_8208(sVec4_8208& dst, const sVec4_8208& a, const sVec4_8208& b)
{
    sVec4_8208 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    dst = r;
}

// PORT: PS2 sqrt.s asm helper; use sqrtf on PC.
static inline float Sqrt_8208(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" sVec4_8208 f_177FC0_8208(void* self, const sVec4_8208& v) __asm__("func_00177FC0");
extern "C" sVec4_8208 f_177EF8_8208(void* self) __asm__("func_00177EF8");
extern "C" int func_0011FE98(void* self);

struct sCamInfo_8208 {
    char pad0[0x20];
    sVec4_8208 pos;   // 0x20
    char pad30[0x38];
} __attribute__((aligned(16)));

extern "C" void func_00178208_v(char* self) __asm__("func_00178208");

extern "C" void func_00178208_v(char* self)
{
    sCamInfo_8208 info;
    func_00162568(self, (sCamInfo_00178BB0*)&info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    *(float*)self = 0.7853981852531433f;
    sVec4_8208 d = Sub_8208(*(sVec4_8208*)(self + 0x20), *(sVec4_8208*)(self + 0x40));
    float len = Length_8208(d);
    float t;
    if (len >= 150.0f) {
        if (len <= 1500.0f) {
            t = (len - 150.0f) / 1350.0f;
        } else {
            t = 1.0f;
        }
    } else {
        t = 0.0f;
    }
    float f = (1.0f - t) * 0.9879999756813049f;
    if (func_0011FE98(*(void**)(*(char**)(self + 0x30) + 4)) == 5) {
        f = Sqrt_8208(f);
    }
    {
        sVec4_8208 s = Scale_8208(*(sVec4_8208*)(self + 0x40), f);
        float g = 1.0f - f;
        AddD_8208(d, s, Scale_8208(f_177FC0_8208(self, info.pos), g));
        *(sVec4_8208*)(self + 0x40) = d;
    }
    AddD_8208(d, f_177EF8_8208(self), ScaleP_8208(&D_004FF160_8208, 37.0f));
    *(sVec4_8208*)(self + 0x20) = d;
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001783E0);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178520);
#ifdef SKIP_ASM
struct func_00178520_sVec4 { float x, y, z, w; } __attribute__((aligned(16)));
extern void* D_0045CC50[];
extern "C" void* func_00162318(void* self);

extern "C" void* func_00178520(void* self, func_00178520_sVec4* a, func_00178520_sVec4* b)
{
    func_00162318(self);
    *(int*)((char*)self + 0xC) = 0x43;
    *(void***)((char*)self + 0x10) = D_0045CC50;
    *(func_00178520_sVec4*)((char*)self + 0x390) = *a;
    *(func_00178520_sVec4*)((char*)self + 0x3A0) = *b;
    return self;
}
#endif

extern void* D_0045CC50[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178588__FPv);
#ifdef SKIP_ASM
void* func_00178588(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045CC50;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001785B0);
#ifdef SKIP_ASM
extern "C" float func_001785B0(void* self)
{
    return 61.68796157836914f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001785C0);
#ifdef SKIP_ASM
extern "C" void func_001785C0(void* self, void* out)
{
    *(float*)((char*)out + 0x4) = 6.654887676239014f;
    *(float*)((char*)out + 0x0) = 16.140756607055664f;
    *(float*)((char*)out + 0xC) = 0.8425687551498413f;
    *(float*)((char*)out + 0x8) = 0.9264262914657593f;
    *(int*)((char*)out + 0x10) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001785F0);
#ifdef SKIP_ASM
struct sVec4_1785F0
{
    float x, y, z, w;
} __attribute__((aligned(16)));


struct sVEntry_1785F0 { short delta; short index; sVec4_1785F0 (*fn)(void*); };

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_1785F0 Sub_1785F0(const sVec4_1785F0& a, const sVec4_1785F0& b)
{
    sVec4_1785F0 r;
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
static inline sVec4_1785F0 Add_1785F0(const sVec4_1785F0& a, const sVec4_1785F0& b)
{
    sVec4_1785F0 r;
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

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_1785F0 Scale_1785F0(const sVec4_1785F0& v, float s)
{
    sVec4_1785F0 r;
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4_1785F0 Normalize_1785F0(const sVec4_1785F0& v)
{
    sVec4_1785F0 r;
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

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_1785F0(const sVec4_1785F0& a, const sVec4_1785F0& b)
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

static inline sVec4_1785F0 GetPos_1785F0(char* self)
{
    char* o = *(char**)(self + 0x30);
    sVEntry_1785F0* e = &(*(sVEntry_1785F0**)o)[1];
    return e->fn(o + e->delta);
}

// The unit declares func_001785F0 later with its own vector type; bind this body by asm label.
extern "C" sVec4_1785F0 func_001785F0_impl(char* self) __asm__("func_001785F0");

extern "C" sVec4_1785F0 func_001785F0_impl(char* self)
{
    sVec4_1785F0 dir = Normalize_1785F0(Sub_1785F0(*(sVec4_1785F0*)(self + 0x390), *(sVec4_1785F0*)(self + 0x3A0)));
    sVec4_1785F0 rel = Sub_1785F0(GetPos_1785F0(self), *(sVec4_1785F0*)(self + 0x390));
    sVec4_1785F0 off = Scale_1785F0(dir, Dot_1785F0(rel, dir) / Dot_1785F0(dir, dir));
    sVec4_1785F0 res = Sub_1785F0(Add_1785F0(*(sVec4_1785F0*)(self + 0x390), off), Scale_1785F0(dir, 1500.0f));
    return res;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178758);
#ifdef SKIP_ASM
struct sVec4_178758 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVE_178758 {
    short delta;
    short index;
    sVec4_178758 (*fn)(void*);
};

extern sVec4_178758 D_004FF160_178758 __asm__("D_004FF160");

// PORT: PS2-only VU0 inline asm (a + b).
static inline sVec4_178758 Add_178758(const sVec4_178758& a, const sVec4_178758& b)
{
    sVec4_178758 r;
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

// PORT: PS2-only VU0 inline asm (*v * s).
static inline sVec4_178758 ScaleP_178758(const sVec4_178758* v, float s)
{
    sVec4_178758 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "o"(*v), "f"(s)
        : "memory");
    return r;
}

static inline sVec4_178758 CallA_178758(char* self)
{
    char* o = *(char**)(self + 0x30);
    sVE_178758* e = &(*(sVE_178758**)o)[1];
    return e->fn(o + e->delta);
}

extern "C" sVec4_178758 f_178758(char* self) __asm__("func_00178758");
extern "C" sVec4_178758 f_178758(char* self)
{
    return Add_178758(CallA_178758(self), ScaleP_178758(&D_004FF160_178758, -100.0f));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001787E0);
#ifdef SKIP_ASM
struct sVec4_1787E0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sCamInfo_1787E0 {
    char data[0x68];
} __attribute__((aligned(16)));

extern sVec4_1787E0 D_004FF140_1787E0 __asm__("D_004FF140");
extern "C" void func_00162568(void* self, sCamInfo_00178BB0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);
extern "C" sVec4_1787E0 f_1785F0_1787E0(void* self) __asm__("func_001785F0");
extern "C" sVec4_1787E0 f_178758_1787E0(void* self) __asm__("func_00178758");

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_1787E0 Sub_1787E0(const sVec4_1787E0& a, const sVec4_1787E0& b)
{
    sVec4_1787E0 r;
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

// PORT: PS2-only VU0 inline asm (*v * s).
static inline sVec4_1787E0 ScaleP_1787E0(const sVec4_1787E0* v, float s)
{
    sVec4_1787E0 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "o"(*v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place vector times scalar).
static inline void ScaleEq_1787E0(sVec4_1787E0& v, float s)
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_1787E0(const sVec4_1787E0& v)
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

extern "C" void func_001787E0(char* self)
{
    sCamInfo_1787E0 info;
    func_00162568(self, (sCamInfo_00178BB0*)&info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    *(float*)self = 0.7853981852531433f;
    *(sVec4_1787E0*)(self + 0x40) = f_1785F0_1787E0(self);
    *(sVec4_1787E0*)(self + 0x20) = f_178758_1787E0(self);
    sVec4_1787E0 d = Sub_1787E0(*(sVec4_1787E0*)(self + 0x20), *(sVec4_1787E0*)(self + 0x40));
    float len = Length_1787E0(d);
    if (len < 1.0f) {
        d = ScaleP_1787E0(&D_004FF140_1787E0, 600.0f);
    } else if (len > 600.0f) {
        ScaleEq_1787E0(d, 600.0f / len);
        *(sVec4_1787E0*)(self + 0x40) = Sub_1787E0(*(sVec4_1787E0*)(self + 0x20), d);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178938);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);

struct sVec4_00178938 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" sVec4_00178938 func_001785F0(void* self);
extern "C" sVec4_00178938 func_00178758(void* self);

class cCamTarget_00178938 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
};
class cCamCtrl_00178938 {
public:
    char pad_0x00[0x10];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" void func_00178938(cCamCtrl_00178938* self, int id)
{
    char* rider = *(char**)(*(char**)((char*)self + 0x30) + 4);
    if (id == ((cCamTarget_00178938*)(rider + 0x6C0))->v07()) {
        *(sVec4_00178938*)((char*)self + 0x40) = func_001785F0(self);
        *(sVec4_00178938*)((char*)self + 0x20) = func_00178758(self);
        func_00166C60(self, id);
        func_00166550(self, 559.7440185546875f, 300.0f);
        self->v05();
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_001789E8);
#ifdef SKIP_ASM
struct sVec4_1789E8
{
    float x, y, z, w;
} __attribute__((aligned(16)));


struct sVEntry_1789E8 { short delta; short index; sVec4_1789E8 (*fn)(void*); };

// PORT: PS2-only VU0 inline asm (a - b).
static inline sVec4_1789E8 Sub_1789E8(const sVec4_1789E8& a, const sVec4_1789E8& b)
{
    sVec4_1789E8 r;
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
static inline sVec4_1789E8 Add_1789E8(const sVec4_1789E8& a, const sVec4_1789E8& b)
{
    sVec4_1789E8 r;
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

// PORT: PS2-only VU0 inline asm (v * s).
static inline sVec4_1789E8 Scale_1789E8(const sVec4_1789E8& v, float s)
{
    sVec4_1789E8 r;
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

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4_1789E8 Normalize_1789E8(const sVec4_1789E8& v)
{
    sVec4_1789E8 r;
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

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_1789E8(const sVec4_1789E8& v)
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

// PORT: PS2-only VU0 inline asm (in-place vector divided by scalar).
static inline void DivEq_1789E8(sVec4_1789E8& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_1789E8(const sVec4_1789E8& a, const sVec4_1789E8& b)
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

struct sQuad_1789E8
{
    float v[4];
} __attribute__((aligned(16)));
extern sQuad_1789E8 D_004FF140_v1789E8 __asm__("D_004FF140");
extern void* D_0045CBD8[];
extern "C" void* func_00162318(void* self);

static inline sVec4_1789E8 Get_1789E8(char* o, int slot)
{
    sVEntry_1789E8* e = &(*(sVEntry_1789E8**)o)[slot];
    return e->fn(o + e->delta);
}

extern "C" void* func_001789E8(char* self, char* src)
{
    func_00162318(self);
    sVec4_1789E8* d = (sVec4_1789E8*)(self + 0x390);
    *(int*)(self + 0xC) = 0x44;
    *(void***)(self + 0x10) = D_0045CBD8;
    *(int*)(self + 0x3A0) = 0;
    sVec4_1789E8 dir = (Length_1789E8(Get_1789E8(src, 3)) > 1.0f) ? Normalize_1789E8(Get_1789E8(src, 3)) : Get_1789E8(src, 4);
    *d = dir;
    *(float*)(self + 0x398) = 0.0f;
    float len = Length_1789E8(*(sVec4_1789E8*)(self + 0x390));
    if (len > 0.009999999776482582f)
        DivEq_1789E8(*(sVec4_1789E8*)(self + 0x390), len);
    else
        *(sQuad_1789E8*)(self + 0x390) = D_004FF140_v1789E8;
    return self;
}
#endif

extern void* D_0045CBD8[];
extern "C" void* func_00162458(void*);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178B70__FPv);
#ifdef SKIP_ASM
void* func_00178B70(void* self)
{
    *(int*)((char*)self + 0x10) = (int)(void*)D_0045CBD8;
    return func_00162458(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178B98__FPv);
#ifdef SKIP_ASM
float func_00178B98(void* self)
{
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178BA8__FPvT0);
#ifdef SKIP_ASM
void func_00178BA8(void* self, void* other)
{
    *(int*)((char*)other + 0x10) = 0;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178BB0);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" float func_0031C040(float x);
extern "C" void func_0031BE50(float* s, float* c, float angle);

struct sVec_00178BB0 {
    float x, y, z, w;
    sVec_00178BB0() {}
    sVec_00178BB0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sCamInfo_00178BB0 {
    char data[0x68];
} __attribute__((aligned(16)));

extern sVec_00178BB0 D_004FF160;
extern "C" void func_00162568(void* self, sCamInfo_00178BB0* out, float a, float b, float c, float d,
                              float e, float f, float g, float h);

struct sVEv_00178BB0 {
    short delta;
    short index;
    sVec_00178BB0 (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec_00178BB0 ctScale_00178BB0(const sVec_00178BB0& v, float s)
{
    sVec_00178BB0 r;
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
static inline sVec_00178BB0 ctAdd_00178BB0(const sVec_00178BB0& a, const sVec_00178BB0& b)
{
    sVec_00178BB0 r;
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

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec_00178BB0 ctSub_00178BB0(const sVec_00178BB0& a, const sVec_00178BB0& b)
{
    sVec_00178BB0 r;
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

// PORT: PS2-only VU0 inline asm (v rotated by quaternion q).
static inline sVec_00178BB0 ctRot_00178BB0(const sVec_00178BB0& q, const sVec_00178BB0& v)
{
    sVec_00178BB0 r;
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

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_00178BB0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline float wrap_00178BB0(float x)
{
    return x - ffloor_00178BB0(x * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
}

static inline sVec_00178BB0 AxisAngle_00178BB0(const sVec_00178BB0& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    sVec_00178BB0 q;
    q.w = c;
    q.x = s * axis.x;
    q.y = s * axis.y;
    q.z = s * axis.z;
    return q;
}

static inline sVec_00178BB0 getPos_00178BB0(char* self)
{
    char* o = *(char**)(self + 0x30);
    sVEv_00178BB0* e = &(*(sVEv_00178BB0**)o)[1];
    return e->fn(o + e->delta);
}

extern "C" void func_00178BB0(char* self)
{
    sCamInfo_00178BB0 info;
    func_00162568(self, &info, 0.2713613510131836f, 0.8999999761581421f, 0.29420721530914307f,
                  0.8513929843902588f, 0.8500000238418579f, 0.9700000286102295f, 0.10000000149011612f,
                  0.6000000238418579f);
    (*(int*)(self + 0x3A0))++;
    *(int*)(self + 0x3A0) %= 0x44C;
    float ang = wrap_00178BB0((float)*(int*)(self + 0x3A0) * 0.0009090909152291715f * 6.2831854820251465f);
    float a = (1.0f - func_0031C040(ang)) * 0.7482788562774658f + -0.7482788562774658f;
    a -= ffloor_00178BB0(a * 0.15915493667125702f + 0.5f) * 6.2831854820251465f;
    sVec_00178BB0 q = AxisAngle_00178BB0(D_004FF160, a);
    sVec_00178BB0 v = ctRot_00178BB0(q, *(sVec_00178BB0*)(self + 0x390));
    *(sVec_00178BB0*)(self + 0x20) = ctAdd_00178BB0(getPos_00178BB0(self), ctScale_00178BB0(D_004FF160, -3.0f));
    int multi = *(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x78) >= 2;
    float h = 0.0f;
    if (multi) {
        h = 150.0f;
    }
    float d = 0.0f;
    if (multi) {
        d = 200.0f;
    }
    *(sVec_00178BB0*)(self + 0x40) =
        ctAdd_00178BB0(ctSub_00178BB0(*(sVec_00178BB0*)(self + 0x20), ctScale_00178BB0(v, d + 126.0f)),
                       ctScale_00178BB0(D_004FF160, h + -27.0f));
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178E90);
#ifdef SKIP_ASM
extern "C" void func_00166C60(void* self, int id);
extern "C" void func_00166550(void* self, float a, float b);

struct sCamVEntryIntA {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sCamVEntryVoidA {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00178E90(void* self, int id)
{
    char* obj = *(char**)(*(char**)((char*)self + 0x30) + 0x4) + 0x6C0;
    sCamVEntryIntA* vt = *(sCamVEntryIntA**)obj;
    if (id == vt[7].fn(obj + vt[7].delta))
    {
        func_00166C60(self, id);
        func_00166550(self, 100.0f, 100.0f);
        sCamVEntryVoidA* vt2 = *(sCamVEntryVoidA**)((char*)self + 0x10);
        vt2[5].fn((char*)self + vt2[5].delta);
    }
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178F18);
#ifdef SKIP_ASM
extern "C" void* func_00178F18(void* self, ...)
{
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00178F58);
#ifdef SKIP_ASM
extern float D_004C5C10[4];
extern float D_004C5C20[4];
extern float D_004C5C30[4];
extern float D_004C5C40[4];
extern float D_004C5C50[4];
extern float D_004C5C60[4];
extern float D_004C5C70[4];
extern float D_004C5C80[4];
extern float D_004C5C90[4];
extern float D_004C5CA0[4];
extern float D_004C5CB0[4];
extern float D_004C5CC0[4];
extern float D_004C5CD0[4];
extern float D_004C5CE0[4];
extern float D_004C5CF0[4];
extern float D_004C5D00[4];
extern float D_004C5D10[4];
extern float D_004C5D20[4];
extern float D_004C5D30[4];
extern float D_004C5D40[4];
extern float D_004C5D50[4];
extern float D_004C5D60[4];
extern float D_004C5D70[4];
extern float D_004C5D80[4];
extern float D_004C5D90[4];
extern float D_004C5DA0[4];
extern float D_004C5DB0[4];
extern float D_004C5DC0[4];
extern float D_004C5DD0[4];
extern float D_004C5DE0[4];
extern float D_004C5DF0[4];
extern float D_004C5E00[4];
extern float D_004C5E10[4];
extern float D_004C5E20[4];
extern float D_004C5E30[4];
extern float D_004C5E40[4];
extern float D_004C5E50[4];
extern float D_004C5E60[4];
extern float D_004C5E70[4];
extern float D_004C5E80[4];
extern float D_004C5E90[4];
extern float D_004C5EA0[4];
extern float D_004C5EB0[4];
extern float D_004C5EC0[4];
extern float D_004C5ED0[4];
extern float D_004C5EE0[4];
extern float D_004C5EF0[4];
extern float D_004C5F00[4];
extern float D_004C5F10[4];
extern float D_004C5F20[4];
extern float D_004C5F30[4];
extern float D_004C5F40[4];
extern float D_004C5F50[4];
extern float D_004C5F60[4];
extern float D_004C5F70[4];
extern float D_004C5F80[4];

void sti_00178F58(int init, int prio) __asm__("func_00178F58");
void sti_00178F58(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004C5C10[0] = 1.0f;
        D_004C5C10[1] = 1.0f;
        D_004C5C10[2] = 1.0f;
        D_004C5C10[3] = 0.5f;
        D_004C5C20[0] = 0.4998680055141449f;
        D_004C5C20[1] = 1.0f;
        D_004C5C20[2] = 1.0f;
        D_004C5C20[3] = 0.0f;
        D_004C5C30[0] = 0.12951700389385223f;
        D_004C5C30[1] = 1.0f;
        D_004C5C30[2] = 1.0f;
        D_004C5C30[3] = 0.0f;
        D_004C5C40[0] = 0.22426900267601013f;
        D_004C5C40[1] = 0.9402310252189636f;
        D_004C5C40[2] = 0.5425059795379639f;
        D_004C5C40[3] = 0.0004030000127386302f;
        D_004C5C50[0] = 0.4652079939842224f;
        D_004C5C50[1] = 0.32170501351356506f;
        D_004C5C50[2] = 0.9943439960479736f;
        D_004C5C50[3] = 0.0f;
        D_004C5C60[0] = 0.17792600393295288f;
        D_004C5C60[1] = 1.0f;
        D_004C5C60[2] = 1.0f;
        D_004C5C60[3] = 0.0f;
        D_004C5C70[0] = 0.4411740005016327f;
        D_004C5C70[1] = 0.41388601064682007f;
        D_004C5C70[2] = 0.3211260139942169f;
        D_004C5C70[3] = 0.4398239850997925f;
        D_004C5C80[0] = 0.500997006893158f;
        D_004C5C80[1] = 0.24849599599838257f;
        D_004C5C80[2] = 1.0f;
        D_004C5C80[3] = 1.0f;
        D_004C5C90[0] = 0.27687299251556396f;
        D_004C5C90[1] = 0.6395620107650757f;
        D_004C5C90[2] = 0.13423900306224823f;
        D_004C5C90[3] = 0.0f;
        D_004C5CA0[0] = 0.8936439752578735f;
        D_004C5CA0[1] = 0.5263469815254211f;
        D_004C5CA0[2] = 0.5051450133323669f;
        D_004C5CA0[3] = 0.8687300086021423f;
        D_004C5CB0[0] = 1.0f;
        D_004C5CB0[1] = 1.0f;
        D_004C5CB0[2] = 1.0f;
        D_004C5CB0[3] = 1.0f;
        D_004C5CC0[0] = 1.0f;
        D_004C5CC0[1] = 0.0f;
        D_004C5CC0[2] = 0.0f;
        D_004C5CC0[3] = 0.0f;
        D_004C5CD0[0] = 1.0f;
        D_004C5CD0[1] = 0.550000011920929f;
        D_004C5CD0[2] = 0.5350000262260437f;
        D_004C5CD0[3] = 0.550000011920929f;
        D_004C5CE0[0] = 1.0f;
        D_004C5CE0[1] = 1.0f;
        D_004C5CE0[2] = 1.0f;
        D_004C5CE0[3] = 1.0f;
        D_004C5CF0[0] = 1.0f;
        D_004C5CF0[1] = 1.0f;
        D_004C5CF0[2] = 1.0f;
        D_004C5CF0[3] = 1.0f;
        D_004C5D00[0] = 1.0f;
        D_004C5D00[1] = 0.0f;
        D_004C5D00[2] = 0.0f;
        D_004C5D00[3] = 0.0f;
        D_004C5D10[0] = 1.0f;
        D_004C5D10[1] = 0.0f;
        D_004C5D10[2] = 0.0f;
        D_004C5D10[3] = 0.0f;
        D_004C5D20[0] = 1.0f;
        D_004C5D20[1] = 1.0f;
        D_004C5D20[2] = 1.0f;
        D_004C5D20[3] = 1.0f;
        D_004C5D30[0] = 1.0f;
        D_004C5D30[1] = 0.5f;
        D_004C5D30[2] = 1.0f;
        D_004C5D30[3] = 0.5f;
        D_004C5D40[0] = 1.0f;
        D_004C5D40[1] = 0.5f;
        D_004C5D40[2] = 1.0f;
        D_004C5D40[3] = 0.5f;
        D_004C5D50[0] = 1.0f;
        D_004C5D50[1] = 0.5f;
        D_004C5D50[2] = 1.0f;
        D_004C5D50[3] = 0.5f;
        D_004C5D60[0] = 1.0f;
        D_004C5D60[1] = 0.7828119993209839f;
        D_004C5D60[2] = 0.06171900033950806f;
        D_004C5D60[3] = 0.03984399884939194f;
        D_004C5D70[0] = 1.0f;
        D_004C5D70[1] = 1.0f;
        D_004C5D70[2] = 0.7988259792327881f;
        D_004C5D70[3] = 0.0f;
        D_004C5D80[0] = 0.9886710047721863f;
        D_004C5D80[1] = 0.9230499863624573f;
        D_004C5D80[2] = 0.34311699867248535f;
        D_004C5D80[3] = 0.0f;
        D_004C5D90[0] = 1.0f;
        D_004C5D90[1] = 1.0f;
        D_004C5D90[2] = 1.0f;
        D_004C5D90[3] = 1.0f;
        D_004C5DA0[0] = 1.0f;
        D_004C5DA0[1] = 1.0f;
        D_004C5DA0[2] = 0.7976430058479309f;
        D_004C5DA0[3] = 0.0f;
        D_004C5DB0[0] = 1.0f;
        D_004C5DB0[1] = 0.9222670197486877f;
        D_004C5DB0[2] = 0.34179699420928955f;
        D_004C5DB0[3] = 0.0f;
        D_004C5DC0[0] = 1.0f;
        D_004C5DC0[1] = 0.7847639918327332f;
        D_004C5DC0[2] = 0.06054700165987015f;
        D_004C5DC0[3] = 0.04062499850988388f;
        D_004C5DD0[0] = 1.0f;
        D_004C5DD0[1] = 0.800000011920929f;
        D_004C5DD0[2] = 0.44999998807907104f;
        D_004C5DD0[3] = 1.0f;
        D_004C5DE0[0] = 1.0f;
        D_004C5DE0[1] = 0.3281260132789612f;
        D_004C5DE0[2] = 1.0f;
        D_004C5DE0[3] = 0.3539060056209564f;
        D_004C5DF0[0] = 1.0f;
        D_004C5DF0[1] = 1.0f;
        D_004C5DF0[2] = 1.0f;
        D_004C5DF0[3] = 1.0f;
        D_004C5E00[0] = 1.0f;
        D_004C5E00[1] = 1.0f;
        D_004C5E00[2] = 1.0f;
        D_004C5E00[3] = 1.0f;
        D_004C5E10[0] = 1.0f;
        D_004C5E10[1] = 0.8613290190696716f;
        D_004C5E10[2] = 0.38124799728393555f;
        D_004C5E10[3] = 0.0f;
        D_004C5E20[0] = 1.0f;
        D_004C5E20[1] = 1.0f;
        D_004C5E20[2] = 1.0f;
        D_004C5E20[3] = 1.0f;
        D_004C5E30[0] = 1.0f;
        D_004C5E30[1] = 0.3244380056858063f;
        D_004C5E30[2] = 1.0f;
        D_004C5E30[3] = 0.0f;
        D_004C5E40[0] = 1.0f;
        D_004C5E40[1] = 1.0f;
        D_004C5E40[2] = 1.0f;
        D_004C5E40[3] = 1.0f;
        D_004C5E50[0] = 1.0f;
        D_004C5E50[1] = 1.0f;
        D_004C5E50[2] = 0.0f;
        D_004C5E50[3] = 0.0f;
        D_004C5E60[0] = 0.7007060050964355f;
        D_004C5E60[1] = 0.0f;
        D_004C5E60[2] = 0.0f;
        D_004C5E60[3] = 0.0f;
        D_004C5E70[0] = 1.0f;
        D_004C5E70[1] = 0.7828530073165894f;
        D_004C5E70[2] = 0.06140600144863129f;
        D_004C5E70[3] = 0.04146299883723259f;
        D_004C5E80[0] = 1.0f;
        D_004C5E80[1] = 0.32487601041793823f;
        D_004C5E80[2] = 1.0f;
        D_004C5E80[3] = 0.35280099511146545f;
        D_004C5E90[0] = 1.0f;
        D_004C5E90[1] = 1.0f;
        D_004C5E90[2] = 0.7977359890937805f;
        D_004C5E90[3] = 0.0f;
        D_004C5EA0[0] = 1.0f;
        D_004C5EA0[1] = 0.4937489926815033f;
        D_004C5EA0[2] = 1.0f;
        D_004C5EA0[3] = 0.49179700016975403f;
        D_004C5EB0[0] = 1.0f;
        D_004C5EB0[1] = 1.0f;
        D_004C5EB0[2] = 1.0f;
        D_004C5EB0[3] = 1.0f;
        D_004C5EC0[0] = 1.0f;
        D_004C5EC0[1] = 0.800000011920929f;
        D_004C5EC0[2] = 1.0f;
        D_004C5EC0[3] = 0.800000011920929f;
        D_004C5ED0[0] = 1.0f;
        D_004C5ED0[1] = 1.0f;
        D_004C5ED0[2] = 0.0f;
        D_004C5ED0[3] = 0.0f;
        D_004C5EE0[0] = 1.0f;
        D_004C5EE0[1] = 1.0f;
        D_004C5EE0[2] = 0.0f;
        D_004C5EE0[3] = 0.0f;
        D_004C5EF0[0] = 1.0f;
        D_004C5EF0[1] = 1.0f;
        D_004C5EF0[2] = 0.0f;
        D_004C5EF0[3] = 0.0f;
        D_004C5F00[0] = 1.0f;
        D_004C5F00[1] = 0.3273420035839081f;
        D_004C5F00[2] = 1.0f;
        D_004C5F00[3] = 0.35390499234199524f;
        D_004C5F10[0] = 1.0f;
        D_004C5F10[1] = 1.0f;
        D_004C5F10[2] = 0.061000000685453415f;
        D_004C5F10[3] = 0.039000000804662704f;
        D_004C5F20[0] = 1.0f;
        D_004C5F20[1] = 1.0f;
        D_004C5F20[2] = 0.7999979853630066f;
        D_004C5F20[3] = 0.0f;
        D_004C5F30[0] = 1.0f;
        D_004C5F30[1] = 0.9589840173721313f;
        D_004C5F30[2] = 0.6143789887428284f;
        D_004C5F30[3] = 0.0f;
        D_004C5F40[0] = 1.0f;
        D_004C5F40[1] = 0.9285150170326233f;
        D_004C5F40[2] = 0.3399839997291565f;
        D_004C5F40[3] = 0.0f;
        D_004C5F50[0] = 1.0f;
        D_004C5F50[1] = 0.8738250136375427f;
        D_004C5F50[2] = 0.24931700527668f;
        D_004C5F50[3] = 0.017578000202775f;
        D_004C5F60[0] = 1.0f;
        D_004C5F60[1] = 0.7843739986419678f;
        D_004C5F60[2] = 0.06132800132036209f;
        D_004C5F60[3] = 0.03945299983024597f;
        D_004C5F70[0] = 1.0f;
        D_004C5F70[1] = 0.0f;
        D_004C5F70[2] = 1.0f;
        D_004C5F70[3] = 0.0f;
        D_004C5F80[0] = 1.0f;
        D_004C5F80[1] = 1.0f;
        D_004C5F80[2] = 0.0f;
        D_004C5F80[3] = 0.0f;
    }
}
#endif

extern "C" void* func_00178F58(int, int);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00179730);
#ifdef SKIP_ASM
extern "C" void func_00179730(void) {

}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00179738__FPv);
#ifdef SKIP_ASM
void* func_00179738(void* self)
{
    return func_00178F58(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00179758);
#ifdef SKIP_ASM
extern "C" void* func_00179758(void* self, ...)
{
    return self;
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00179798);

extern "C" void* func_00179798(int, int);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00179FA8__FPv);
#ifdef SKIP_ASM
void* func_00179FA8(void* self)
{
    return func_00179798(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_00179FC8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144CC0(void* iface, int id);

extern "C" int func_00179FC8(void* self, int id)
{
    if (func_00144CC0(cBE_getInterface_Fv(cBE_getBE(), 0), id) == 1) {
        return 1;
    }
    if (id >= 0xE && id <= 0x10) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A028);
#ifdef SKIP_ASM
struct func_0017A028_sEntry {
    int active;
    char pad_0x4[0x88];
};

struct func_0017A028_sMgr {
    int count;
    char pad_0x4[0x88];
    func_0017A028_sEntry entries[1];
};

extern "C" int func_0017A028(func_0017A028_sMgr* self, int i)
{
    if (*(int*)((char*)self + 0x8C08) == 0) {
        return -1;
    }
    i = (i + 1) % self->count;
    while (self->entries[i].active == 0) {
        i = (i + 1) % self->count;
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A0B8);
#ifdef SKIP_ASM
extern "C" int func_0017A0B8(func_0017A028_sMgr* self, int i)
{
    if (*(int*)((char*)self + 0x8C08) == 0) {
        return -1;
    }
    i = (i + self->count - 1) % self->count;
    while (self->entries[i].active == 0) {
        i = (i + self->count - 1) % self->count;
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A158);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_A158(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00144CC0(void* iface, int id);

// PORT: the unit also declares this with a pointer third argument; defined under an asm label with its real type
extern "C" int func_0017A158_impl(int* list, int idx, int kind) __asm__("func_0017A158");
extern "C" int func_0017A158_impl(int* list, int idx, int kind)
{
    if (idx >= 0 && idx < list[0]) {
        unsigned int v = *(unsigned int*)((char*)list + idx * 0x8C + 0x84);
        switch (kind) {
        case 0:
            if (v < 5) return 1;
            break;
        case 1:
            if (v >= 5 && v < 8) return 1;
            break;
        case 2:
            if (v >= 8 && v < 11) return 1;
            break;
        case 3:
            if (v >= 11 && v < 14) return 1;
            break;
        case 5:
        case 6:
            if (v >= 14 && v < 17) return 1;
            break;
        case 4:
            if (!func_00144CC0(cBE_getInterface_A158(cBE_getBE(), 0), v)) return 1;
            break;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A220);
#ifdef SKIP_ASM
extern "C" int func_0017A158(int* self, int i, void* key);

// Circular search: first index after `start` for which func_0017A158 matches.
extern "C" int func_0017A220(int* self, int start, void* key)
{
    int n;
    int i = (start + 1) % self[0];
    for (n = 0; n < self[0]; n++) {
        if (func_0017A158(self, i, key))
            return i;
        i = (i + 1) % self[0];
    }
    return -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A2C8);
#ifdef SKIP_ASM
extern "C" int func_0017A158(int* self, int i, void* key);

// Circular search backwards: first index before `start` for which func_0017A158 matches.
extern "C" int func_0017A2C8(int* self, int start, void* key)
{
    int n;
    int i = (start + self[0] - 1) % self[0];
    for (n = 0; n < self[0]; n++) {
        if (func_0017A158(self, i, key))
            return i;
        i = (i + self[0] - 1) % self[0];
    }
    return -1;
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A378);

INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A638);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A830);
#ifdef SKIP_ASM
struct cBXString;
struct cBigFile;
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" cBXString* func_00318630(cBXString* self, cBXString* a, const char* str);
extern "C" cBXString* func_003186D0(cBXString* self, const char* str, cBXString* b);
// PORT: the bigfile ctor forwards (path, flags) to cBigFile_open; bind the 3-arg form.
cBigFile* cBigFile_cBigFile1_A830(cBigFile* self, const char* path, int flags) __asm__("cBigFile_cBigFile1__FP8cBigFile");
void cBigFile__cBigFile(cBigFile* self, int flags);
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_003A6948(const char* path, int n, void* names);
extern char D_0045CE20[];
extern char D_004A1298[];

struct sCamEntry_A830 {
    char name[0x40];    // 0x00
    char tag[4];        // 0x40
    char pad_44[0x48];
};

struct sCamMgr_A830 {
    int count;                          // 0x0000
    sCamEntry_A830 entries[0x100];    // 0x0004
};

struct sCamName_A830 {
    char* name;
    int ok;
};

// Non-POD (user-declared copy ctor, never defined) so locals get the 16-byte slots g++ gives classes.
struct sStr_A830 {
    char* s;
    sStr_A830() {}
    sStr_A830(const sStr_A830&);
};

struct sBigFile_A830 {
    int f0;
    int f4;
    sBigFile_A830() {}
    sBigFile_A830(const sBigFile_A830&);
};

// Returns 0 when (name, tag) is already registered; otherwise looks the name up in the bigfile.
extern "C" int func_0017A830(sCamMgr_A830* self, char* name, char* tag)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (func_0041AA88(name, self->entries[i].name) == 0 &&
            func_0041AA88(tag, self->entries[i].tag) == 0) {
            return 0;
        }
    }
    sStr_A830 base;
    sStr_A830 s;
    sBigFile_A830 bf;
    sCamName_A830 nm;
    char* pre = D_0045CE20;
    cBXString_cBXString2(&s, tag);
    func_003186D0((cBXString*)&base, pre, (cBXString*)&s);
    cBXString__cBXString(&s, 2);
    cBigFile* pbf = (cBigFile*)&bf;
    func_00318630((cBXString*)&s, (cBXString*)&base, D_004A1298);
    cBigFile_cBigFile1_A830(pbf, s.s, 0x100);
    cBXString__cBXString(&s, 2);
    nm.name = name;
    int r = func_003A6948(base.s, 1, &nm);
    int result = r == 0 ? 0 : nm.ok;
    cBigFile__cBigFile((cBigFile*)&bf, 2);
    cBXString__cBXString(&base, 2);
    return result;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017A978);
#ifdef SKIP_ASM
struct cBXString;
struct cBigFile;
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" cBXString* func_00318630(cBXString* self, cBXString* a, const char* str);
extern "C" cBXString* func_003186D0(cBXString* self, const char* str, cBXString* b);
// PORT: the bigfile ctor forwards (path, flags) to cBigFile_open; bind the 3-arg form.
cBigFile* cBigFile_cBigFile1_17A978(cBigFile* self, const char* path, int flags) __asm__("cBigFile_cBigFile1__FP8cBigFile");
void cBigFile__cBigFile(cBigFile* self, int flags);
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_003A6948(const char* path, int n, void* names);
extern char D_0045CE20[];
extern char D_004A1298[];

struct sCamEntry_17A978 {
    char name[0x40];    // 0x00
    char tag[4];        // 0x40
    char pad_44[0x48];
};

struct sCamMgr_17A978 {
    int count;                          // 0x0000
    sCamEntry_17A978 entries[0x100];    // 0x0004
};

struct sCamName_17A978 {
    char* name;
    int ok;
};

// Non-POD (user-declared copy ctor, never defined) so locals get the 16-byte slots g++ gives classes.
struct sStr_17A978 {
    char* s;
    sStr_17A978() {}
    sStr_17A978(const sStr_17A978&);
};

struct sBigFile_17A978 {
    int f0;
    int f4;
    sBigFile_17A978() {}
    sBigFile_17A978(const sBigFile_17A978&);
};

extern "C" int func_0017A978(void* selfp, int n, void* namesp, char* tag)
{
    sCamMgr_17A978* self = (sCamMgr_17A978*)selfp;
    sCamName_17A978* names = (sCamName_17A978*)namesp;
    int fail = 0;
    int i;
    int j;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < self->count; j++) {
            if (func_0041AA88(names[i].name, self->entries[j].name) == 0 &&
                func_0041AA88(tag, self->entries[j].tag) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            fail = 1;
            break;
        }
    }
    if (!fail) {
        return 0;
    }
    sStr_17A978 base;
    sStr_17A978 s;
    sBigFile_17A978 bf;
    char* pre = D_0045CE20;
    cBXString_cBXString2(&s, tag);
    func_003186D0((cBXString*)&base, pre, (cBXString*)&s);
    cBXString__cBXString(&s, 2);
    cBigFile* pbf = (cBigFile*)&bf;
    func_00318630((cBXString*)&s, (cBXString*)&base, D_004A1298);
    cBigFile_cBigFile1_17A978(pbf, s.s, 0x100);
    cBXString__cBXString(&s, 2);
    int r = func_003A6948(base.s, n, names);
    if (r == 0) {
        cBigFile__cBigFile((cBigFile*)&bf, 2);
        cBXString__cBXString(&base, 2);
        return 0;
    }
    for (int k = 0; k < n; k++) {
        if (names[k].ok) {
            for (int m = 0; m < self->count; m++) {
                if (func_0041AA88(names[k].name, self->entries[m].name) == 0 &&
                    func_0041AA88(tag, self->entries[m].tag) == 0) {
                    names[k].ok = 0;
                    break;
                }
            }
        }
    }
    cBigFile__cBigFile((cBigFile*)&bf, 2);
    cBXString__cBXString(&base, 2);
    return r;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017ABC8__FPv);
#ifdef SKIP_ASM
void* func_0017ABC8(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)((char*)self + 0x8) = -1;
    *(int*)self = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017ABE0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
void cMemMan_free(void* p);
extern char* D_004A289C;

struct sVE_0017ABE0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sIdList_0017ABE0 {
    int* ids;
    int count;
};

extern "C" void func_0017ABE0(sIdList_0017ABE0* self, int flags)
{
    if (self->ids != 0)
    {
        for (int i = 0; i < self->count; i++)
        {
            int id = self->ids[i];
            if (id >= 0)
            {
                char* obj = D_004A289C;
                sVE_0017ABE0* vt = *(sVE_0017ABE0**)(obj + 0x10D8);
                vt[50].fn(obj + vt[50].delta, id);
            }
        }
        if (self->ids != 0)
            cMemMan_free(self->ids);
    }
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerfactory", func_0017AC98);
#ifdef SKIP_ASM
extern "C" int func_0017AC98(void* self, int i)
{
    if (i >= 0 && i < *(int*)((char*)self + 0x4)) {
        *(int*)((char*)self + 0x8) = i;
    } else {
        *(int*)((char*)self + 0x8) = -1;
    }
    return 1;
}
#endif

