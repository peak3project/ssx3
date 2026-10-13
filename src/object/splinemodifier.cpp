#include "common.h"

//100%
INCLUDE_ASM("object/splinemodifier", cSplineModifier_cSplineModifier);
#ifdef SKIP_ASM
class cStream003595D8 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
};

struct sSmQuad_95D8 {
    float v[4];
} __attribute__((aligned(16)));

struct sSmFollow_95D8 {
    unsigned int id;        // 0xD8
    int count;              // 0xDC
    void* node;             // 0xE0
    float length;           // 0xE4
};

struct cSplineModifier_95D8 {
    void** vtable;          // 0x0
    char pad_0x4[0x54];
    int field_0x58;         // 0x58
    char pad_0x5c[0x54];
    sSmQuad_95D8 qB0;       // 0xB0
    sSmQuad_95D8 qC0;       // 0xC0
    int field_0xd0;         // 0xD0
    int field_0xd4;         // 0xD4
    sSmFollow_95D8 follow;  // 0xD8
};

extern void* D_0048F250[];
extern sSmQuad_95D8 D_004FF120;
extern "C" void cSpline_readFromReplayFrame(void* self, cStream003595D8* stream);

extern "C" cSplineModifier_95D8* cSplineModifier_cSplineModifier(cSplineModifier_95D8* self, cStream003595D8* stream)
{
    self->vtable = D_0048F250;
    sSmFollow_95D8* f = &self->follow;
    self->follow.id = 0xFFFFFFFF;
    self->follow.node = 0;
    self->follow.count = 0;
    self->follow.length = 0;
    stream->v02((char*)self + 0x10, 0x50);
    cSpline_readFromReplayFrame(f, stream);
    self->qB0 = D_004FF120;
    self->qC0 = D_004FF120;
    self->field_0x58 = 1;
    self->field_0xd0 = 0;
    self->field_0xd4 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_00359688);
#ifdef SKIP_ASM
// PORT: callers declare func_00359688(void* self); the body also takes the speed in $f12.
extern "C" void func_00359688_impl(void* self, float speed) __asm__("func_00359688");
extern "C" void func_00359688_impl(void* self, float speed)
{
    *(float*)((char*)self + 0x48) = speed * 27.77777862548828f;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_00359698);
#ifdef SKIP_ASM
extern "C" float func_002D1C70();

struct cSplineModifier_9698 {
    char pad_0x0[0x30];
    int mode;               // 0x30
    char pad_0x34[0x8];
    float pos;              // 0x3C
    float accel;            // 0x40
    float accelTime;        // 0x44
    float speed;            // 0x48
    int field_0x4c;
    int stopped;            // 0x50
    int active;             // 0x54
    int dirty;              // 0x58
    char pad_0x5c[0x88];
    float length;           // 0xE4
};

extern "C" void func_00359698(cSplineModifier_9698* self)
{
    float zero = 0.0f;
    if (zero < self->accelTime) {
        self->accelTime -= func_002D1C70();
        self->speed += self->accel * func_002D1C70();
    }
    if (self->active == 0) {
        return;
    }
    if (self->stopped != 0) {
        return;
    }
    float pos = self->pos + self->speed * func_002D1C70();
    self->pos = pos;
    if (pos < zero) {
        int mode = self->mode;
        if (mode == 0) {
            self->speed = -self->speed;
            self->pos = zero;
            self->stopped = 1;
            self->active = 0;
        } else if (mode == 2) {
            self->speed = -self->speed;
            self->pos = -pos;
        } else if (mode == 4) {
            self->speed = -self->speed;
            self->pos = zero;
            self->stopped = 1;
            self->active = 0;
        } else {
            self->pos = pos + self->length;
        }
    } else if (self->length <= pos) {
        int mode = self->mode;
        if (mode == 0) {
            self->active = 0;
            self->stopped = 1;
            self->speed = -self->speed;
            self->pos = self->length - 0.10000000149011612f;
        } else if (mode == 2) {
            self->speed = -self->speed;
            self->pos = pos - (pos - (self->length - 0.10000000149011612f));
        } else if (mode == 4) {
            self->active = 0;
            self->stopped = 1;
            self->speed = -self->speed;
            self->pos = self->length - 0.10000000149011612f;
        } else {
            self->pos = pos - self->length;
        }
    }
    self->dirty = 1;
}
#endif

INCLUDE_ASM("object/splinemodifier", func_00359830);

//100%
INCLUDE_ASM("object/splinemodifier", func_00359CF8);
#ifdef SKIP_ASM
struct sSmVec4_9CF8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSmMat_9CF8 {
    sSmVec4_9CF8 r[4];
};

struct sSmBody_9CF8 {
    sSmVec4_9CF8 pos;       // 0x00
    sSmVec4_9CF8 f10;       // 0x10
    sSmVec4_9CF8 vel;       // 0x20
    sSmVec4_9CF8 rot;       // 0x30
};

struct cSplineModifier_9CF8 {
    char pad_0x0[0x48];
    float speed;            // 0x48
    int field_0x4c;
    int stopped;            // 0x50
    int active;             // 0x54
    char pad_0x58[0x8];
    sSmMat_9CF8 mat;        // 0x60
    sSmVec4_9CF8 origin;    // 0xA0
    sSmVec4_9CF8 dir;       // 0xB0
    float fC0;              // 0xC0
    float fC4;              // 0xC4
    float fC8;              // 0xC8
    float fCC;              // 0xCC
    float fD0;              // 0xD0
    float fD4;              // 0xD4
};

// PORT: PS2 abs.s asm helper; use fabsf on PC.
static inline float Abs_9CF8(float x)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: PS2 sqrt.s asm helper; use sqrtf on PC.
static inline float Sqrt_9CF8(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

// PORT: PS2-only VU0 inline asm (normalize).
static inline sSmVec4_9CF8 vu0Normalize_9CF8(const sSmVec4_9CF8& v)
{
    sSmVec4_9CF8 r;
    __asm__(
        "lqc2       $vf3, %1\n"
        "vaddw.x    $vf6, $vf0, $vf0w\n"
        "vmul.xyzw  $vf4, $vf3, $vf3\n"
        "vadday.x   ACC, $vf4, $vf4y\n"
        "vmaddaz.x  ACC, $vf6, $vf4z\n"
        "vmaddw.x   $vf4, $vf6, $vf4w\n"
        "vrsqrt     Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2       $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector * scalar).
static inline sSmVec4_9CF8 vu0Scale_9CF8(const sSmVec4_9CF8& v, float s)
{
    sSmVec4_9CF8 r;
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

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector).
static inline sSmVec4_9CF8 vu0MulMat_9CF8(const sSmMat_9CF8* m, const sSmVec4_9CF8& v)
{
    sSmVec4_9CF8 r;
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

// PORT: PS2-only VU0 inline asm (a - b).
static inline sSmVec4_9CF8 vu0Sub_9CF8(const sSmVec4_9CF8& a, const sSmVec4_9CF8& b)
{
    sSmVec4_9CF8 r;
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
static inline sSmVec4_9CF8 vu0Add_9CF8(const sSmVec4_9CF8& a, const sSmVec4_9CF8& b)
{
    sSmVec4_9CF8 r;
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

// PORT: PS2-only VU0 inline asm (cross product, w = 0).
static inline sSmVec4_9CF8 vu0Cross_9CF8(const sSmVec4_9CF8& a, const sSmVec4_9CF8& b)
{
    sSmVec4_9CF8 r;
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

// PORT: PS2-only VU0 inline asm (a += b).
static inline void vu0AddTo_9CF8(sSmVec4_9CF8& a, const sSmVec4_9CF8& b)
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

extern "C" void func_00359CF8(cSplineModifier_9CF8* self, sSmBody_9CF8* body)
{
    char* sub = (char*)self + 0x10;
    if (self->active == 0) {
        return;
    }
    if (self->stopped != 0) {
        return;
    }
    float a = 0.0f;
    float b = a;
    float t = self->dir.x;
    if (9.999999747378752e-06f < Abs_9CF8(t)) {
        float c4 = self->fC4;
        float c0 = self->fC0;
        float d0 = self->fD0;
        float sum = d0 + self->fD4;
        b = -d0 / sum;
        b *= c4 / t - self->dir.y * c0 / d0;
        a = (1.0f / Sqrt_9CF8(sum)) * (self->fC8 - self->dir.z * (c0 + c4) / sum);
    }
    sSmVec4_9CF8 vel = vu0Scale_9CF8(vu0Normalize_9CF8(self->dir), *(float*)(sub + 0x38));
    sSmVec4_9CF8 w;
    w.x = 0.0f;
    w.z = b * self->speed;
    w.y = a * self->speed;
    w.w = 0.0f;
    w = vu0MulMat_9CF8(&self->mat, w);
    sSmVec4_9CF8 d = vu0Sub_9CF8(body->pos, self->origin);
    vu0AddTo_9CF8(body->vel, vu0Add_9CF8(vel, vu0Cross_9CF8(d, w)));
    vu0AddTo_9CF8(body->rot, w);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/splinemodifier", func_00359EB8);
#ifdef SKIP_ASM
extern "C" void func_00359688(void* self);

extern "C" void func_00359EB8(void* self, int msg)
{
    if (msg == 0x190) {
        func_00359688(self);
        *(int*)((char*)self + 0x50) = 0;
        *(int*)((char*)self + 0x54) = 1;
    } else if (msg == 0x191) {
        *(int*)((char*)self + 0x50) = 0;
        *(int*)((char*)self + 0x54) = 1;
    } else if (msg == 0x192) {
        *(float*)((char*)self + 0x48) = -*(float*)((char*)self + 0x48);
        *(int*)((char*)self + 0x50) = 0;
        *(int*)((char*)self + 0x54) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_00359F30);
#ifdef SKIP_ASM
class cStream00359F30 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
};

extern "C" void func_00345538(void* self, cStream00359F30* stream);

extern "C" void func_00359F30(void* self, cStream00359F30* stream)
{
    stream->v01((char*)self + 0x10, 0x50);
    func_00345538((char*)self + 0xD8, stream);
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_00359F88);
#ifdef SKIP_ASM
struct sSmQuad4_359F88 {
    float x, y, z, w;
    sSmQuad4_359F88(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern void* D_0048F168[];
extern "C" void func_003451C0(void* ref, int id);
extern "C" void func_0035A550(void* self, float v);
extern "C" void func_0035A3F0(void* self);
extern "C" void cMultiSplineModifier_allocNodes(void* self);
extern "C" void cMultiSplineModifier_setupNodes(void* self);
extern "C" void cMultiSplineModifier_setupOverlapSystem(void* self);
extern "C" void* func_0035AC20(void* self);

extern "C" void* func_00359F88(char* self, char* desc, char* model)
{
    *(char**)(self + 0x40) = model;
    *(void***)self = D_0048F168;
    *(unsigned int*)(self + 0x48) = 0xFFFFFFFF;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x18) = 0;
    *(int*)(self + 0x4) = *(int*)(desc + 0x2C);
    *(int*)(self + 0x8) = *(int*)(desc + 0x8);
    *(float*)(self + 0xC) = *(float*)(desc + 0x10) * 0.01745329424738884f;
    func_003451C0(self + 0x48, *(int*)(desc + 0x4));
    func_0035A550(self, *(float*)(desc + 0xC));
    if (*(float*)(desc + 0xC) >= 0.0f) {
        *(float*)(self + 0x10) = 0.0f;
    } else {
        *(float*)(self + 0x10) = *(float*)(self + 0x54);
    }
    *(int*)(self + 0x1C) = *(int*)(desc + 0x28) != 0;
    float zero = 0.0f;
    *(sSmQuad4_359F88*)(self + 0x20) = sSmQuad4_359F88(*(float*)(desc + 0x18), *(float*)(desc + 0x1C),
                                                       *(float*)(desc + 0x20), *(float*)(desc + 0x24));
    if (*(float*)(desc + 0x14) != zero) {
        *(float*)(self + 0x10) = *(float*)(desc + 0x14);
    }
    if (*(float*)(self + 0x10) < zero || *(float*)(self + 0x54) < *(float*)(self + 0x10)) {
        *(float*)(self + 0x10) = zero;
    }
    cMultiSplineModifier_allocNodes(self);
    func_0035A3F0(self);
    cMultiSplineModifier_setupNodes(self);
    func_0035AC20(self);
    cMultiSplineModifier_setupOverlapSystem(self);
    if (*(int*)(*(char**)(self + 0x40) + 0x8) & 0x100) {
        *(int*)(self + 0x34) = 1;
    } else {
        *(int*)(self + 0x34) = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A118);
#ifdef SKIP_ASM
class cStream0035A118 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
    virtual int v03();
};

struct sSmFollow_A118 {
    unsigned int id;        // 0x48
    int count;              // 0x4C
    void* node;             // 0x50
    float length;           // 0x54
};

struct cMultiSplineModifier_A118 {
    void** vtable;          // 0x0
    int count;              // 0x4
    char pad_0x8[0x28];
    int field_0x30;         // 0x30
    char pad_0x34[0xC];
    int field_0x40;         // 0x40
    void** insts;           // 0x44
    sSmFollow_A118 follow;  // 0x48
};

extern void* D_0048F168[];
// PORT: same symbol as the unit's cSpline_readFromReplayFrame(void*, cStream003595D8*).
extern "C" void cSpline_readFromReplayFrame_A118(void* self, cStream0035A118* stream) __asm__("cSpline_readFromReplayFrame");
extern "C" void cMultiSplineModifier_allocNodes(void* self);
extern "C" void cMultiSplineModifier_setupNodes(void* self);
extern "C" void cMultiSplineModifier_setupOverlapSystem(void* self);
void* cObjectInterface_getInstanceMan();
extern "C" void* func_003511D0(void* man, unsigned int id);

extern "C" cMultiSplineModifier_A118* func_0035A118(cMultiSplineModifier_A118* self, cStream0035A118* stream)
{
    self->vtable = D_0048F168;
    sSmFollow_A118* f = &self->follow;
    self->follow.id = 0xFFFFFFFF;
    self->follow.node = 0;
    self->follow.count = 0;
    self->follow.length = 0;
    stream->v02((char*)self + 0x4, 0x34);
    cSpline_readFromReplayFrame_A118(f, stream);
    self->field_0x40 = stream->v03();
    cMultiSplineModifier_allocNodes(self);
    unsigned int id = 0xFFFFFFFF;
    for (int i = 0; i < self->count; i++) {
        stream->v02(&id, 4);
        self->insts[i] = func_003511D0(cObjectInterface_getInstanceMan(), id);
    }
    cMultiSplineModifier_setupNodes(self);
    cMultiSplineModifier_setupOverlapSystem(self);
    self->field_0x30 = 1;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A250);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);
void* cObjectInterface_getInstanceMan();
void func_00351260(void* man, void* inst);
extern "C" void func_0035A780(void* self);
extern void* D_0048F168[];
extern void* D_004913F8[];

struct cMultiSplineModifier_A250 {
    void** vtable;          // 0x0
    int count;              // 0x4
    char pad_0x8[0x30];
    void* nodes;            // 0x38
    void* data;             // 0x3C
    int field_0x40;
    void** insts;           // 0x44
};

extern "C" void func_0035A250(cMultiSplineModifier_A250* self, int flags)
{
    self->vtable = D_0048F168;
    func_0035A780(self);
    if (self->nodes != 0) {
        cMemMan_free(self->nodes);
    }
    if (self->data != 0) {
        cMemMan_free(self->data);
    }
    for (int i = 0; i < self->count; i++) {
        func_00351260(cObjectInterface_getInstanceMan(), self->insts[i]);
    }
    if (self->insts != 0) {
        cMemMan_free(self->insts);
    }
    self->vtable = D_004913F8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", cMultiSplineModifier_allocNodes);
#ifdef SKIP_ASM
// PORT: operator_new__FUi is the game's tagged allocator (size, tag, flags, d); bound by asm label
// as operator new[] so the array new-expressions below match.
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_0048EA30[];
extern char D_0048EA40[];
extern char D_0048EA50[];

struct sSplineNode_A330 {
    char data[0x40];
    sSplineNode_A330() {}
};

struct sSplineSeg_A330 {
    char data[0x60];
    sSplineSeg_A330() {}
};

struct sMultiSpline_A330 {
    int f0;
    int count;                  // 0x4
    char pad8[0x38 - 0x8];
    sSplineNode_A330* nodes;    // 0x38
    sSplineSeg_A330* segs;      // 0x3C
    char* owner;                // 0x40
    int* indices;               // 0x44
};

extern "C" void cMultiSplineModifier_allocNodes(void* selfv)
{
    sMultiSpline_A330* self = (sMultiSpline_A330*)selfv;
    sSplineNode_A330** pn = &self->nodes;
    *pn = new (D_0048EA30, 0x20000000, 0) sSplineNode_A330[*(int*)(*(char**)(self->owner + 0x80) + 0x4)];
    sSplineSeg_A330** ps = &self->segs;
    *ps = new (D_0048EA40, 0xA0000000, 0) sSplineSeg_A330[self->count];
    self->indices = new (D_0048EA50, 0x20000000, 0) int[self->count];
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A3F0);
#ifdef SKIP_ASM
void* cObjectInterface_getInstanceMan();
extern "C" void* func_00351170(void* man);

extern "C" void func_0035A3F0(void* self)
{
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x4); i++) {
        (*(void***)((char*)self + 0x44))[i] = func_00351170(cObjectInterface_getInstanceMan());
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", cMultiSplineModifier_setupNodes);
#ifdef SKIP_ASM
struct sInstanceStruct;
void* cObjectInterface_getInstanceMan();
void cInstanceMan_copyInstance(void* man, sInstanceStruct* inst, void* tmpl);
extern "C" void func_003E6574(void* dst, void* src, int n);

struct sSplineInstA458 {
    char pad_0x0[0x8];
    unsigned int flags;     // 0x8
    char pad_0xC[0x6C];
    int field_0x78;         // 0x78
};

struct sMultiSplineA458 {
    char pad_0x0[0x4];
    int count;                      // 0x4
    char pad_0x8[0x38];
    void* tmpl;                     // 0x40
    sSplineInstA458** insts;        // 0x44
};

extern "C" void cMultiSplineModifier_setupNodes(void* p)
{
    sMultiSplineA458* self = (sMultiSplineA458*)p;
    int i;
    int keep = self->insts[0]->field_0x78;
    func_003E6574(self->insts[0], self->tmpl, 0xA0);
    self->insts[0]->field_0x78 = keep;
    for (i = 1; i < self->count; i++) {
        cInstanceMan_copyInstance(cObjectInterface_getInstanceMan(), (sInstanceStruct*)self->insts[i], self->tmpl);
        self->insts[i]->flags = (self->insts[i]->flags & ~0x40) | 0x20;
        self->insts[i]->flags &= ~0x100;
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A550);
#ifdef SKIP_ASM
extern "C" void func_0035A550(void* self, float speed)
{
    *(float*)((char*)self + 0x14) = speed * 27.77777862548828f;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A560);
#ifdef SKIP_ASM
extern "C" float func_002D1C70();

extern "C" void func_0035A560(void* self)
{
    float t = *(float*)((char*)self + 0x10) + *(float*)((char*)self + 0x14) * func_002D1C70();
    *(float*)((char*)self + 0x10) = t;
    if (t < 0.0f) {
        *(float*)((char*)self + 0x10) = t + *(float*)((char*)self + 0x54);
    } else if (t >= *(float*)((char*)self + 0x54)) {
        *(float*)((char*)self + 0x10) = t - *(float*)((char*)self + 0x54);
    }
    *(int*)((char*)self + 0x30) = 1;
}
#endif

extern "C" void* func_0035AC20(void* self);

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A5D8__FPv);
#ifdef SKIP_ASM
void* func_0035A5D8(void* self)
{
    return func_0035AC20(self);
}
#endif

INCLUDE_ASM("object/splinemodifier", cMultiSplineModifier_setupOverlapSystem);

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A780);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void* func_002D1BE0();

struct sHashKey_A780 {
    int level;      // 0x0
    int x;          // 0x4
    int y;          // 0x8
    int z;          // 0xC
};

struct sOctCell_A780 {
    void* child[8];
    void* lists[3];
};

struct sHashCellR_A780 {
    char pad_0x0[0x10];
    sOctCell_A780* oct;   // 0x10
};

extern "C" void func_00328F28_A780(sHashKey_A780* out, void* box) __asm__("func_00328F28");
extern "C" void func_003284B8_A780(sOctCell_A780* oct, int type, void* node, sHashKey_A780* key,
                                   sHashCellR_A780* cell) __asm__("func_003284B8");

static inline int octEmpty_A780(sOctCell_A780* o)
{
    if (o->child[0] != 0 || o->child[1] != 0 || o->child[2] != 0 || o->child[3] != 0
        || o->child[4] != 0 || o->child[5] != 0 || o->child[6] != 0 || o->child[7] != 0) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (o->lists[i] != 0) {
            return 0;
        }
    }
    return 1;
}

// Removes every spline segment but the first from the space hash (freeing octree cells that become empty).
extern "C" void func_0035A780(void* vself)
{
    char* self = (char*)vself;
    for (int i = 1; i < *(int*)(self + 0x4); i++) {
        void* node = (*(void***)(self + 0x44))[i];
        sHashCellR_A780* cell = (sHashCellR_A780*)func_002D1BE0();
        // PORT: the segment array (0x60-byte entries) is indexed with 32-bit integer arithmetic.
        char* box = (char*)(i * 0x60 + *(int*)(self + 0x3C)) + 0x30;
        (*(int*)((char*)cell + 0xA0))++;
        sHashKey_A780 key;
        func_00328F28_A780(&key, box);
        sHashCellR_A780* c1 = key.x < 0 ? cell + 4 : cell;
        sHashCellR_A780* c2 = key.y < 0 ? c1 + 2 : c1;
        sHashCellR_A780* c3 = key.z < 0 ? c2 + 1 : c2;
        sHashCellR_A780* c = c3;
        func_003284B8_A780(c->oct, 0, node, &key, c);
        if (octEmpty_A780(c->oct)) {
            operator_delete((int*)c->oct);
            c->oct = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035A918);
#ifdef SKIP_ASM
struct sSmVec4_A918 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSmBox_A918 {
    sSmVec4_A918 min;       // 0x30
    sSmVec4_A918 max;       // 0x40
};

struct sSmElem_A918 {
    char pad_0x0[0x30];
    sSmBox_A918 box;        // 0x30
    char pad_0x50[0x10];
};

struct sSmVE_A918 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct cMultiSpline_A918 {
    sSmVE_A918* vtable;     // 0x0
    int count;              // 0x4
    char pad_0x8[0x10];
    float radius;           // 0x18
    char pad_0x1c[0x14];
    int dirty;              // 0x30
    char pad_0x34[0x8];
    sSmElem_A918* elems;    // 0x3C
    char* model;            // 0x40
    char** insts;           // 0x44
};

struct sBox_F048;
extern "C" void* func_002D1BE0();
extern "C" void func_003291E0(void* world, int type, void* id, sBox_F048* box, sBox_F048* old);

// PORT: PS2-only VU0 inline asm (a - b).
static inline sSmVec4_A918 vu0Sub_A918(const sSmVec4_A918& a, const sSmVec4_A918& b)
{
    sSmVec4_A918 r;
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
static inline sSmVec4_A918 vu0Add_A918(const sSmVec4_A918& a, const sSmVec4_A918& b)
{
    sSmVec4_A918 r;
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

static inline sSmVec4_A918 instPos_A918(cMultiSpline_A918* self, int i)
{
    return *(sSmVec4_A918*)(self->insts[i] + 0x40);
}

struct sSmInst_A918 {
    char pad_0x0[0x40];
    sSmVec4_A918 pos;       // 0x40
    char pad_0x50[0x10];
    float bmin[3];          // 0x60
    float bmax[3];          // 0x6C
};

static inline void setMin_A918(sSmInst_A918* in, const sSmVec4_A918& v)
{
    in->bmin[0] = v.x;
    in->bmin[1] = v.y;
    in->bmin[2] = v.z;
}

static inline void setMax_A918(sSmInst_A918* in, const sSmVec4_A918& v)
{
    in->bmax[0] = v.x;
    in->bmax[1] = v.y;
    in->bmax[2] = v.z;
}

extern "C" void func_0035A918(cMultiSpline_A918* self)
{
    if (self->dirty != 0) {
        self->vtable[3].fn((char*)self + self->vtable[3].delta);
    }
    for (int i = 1; i < self->count; i++) {
        sSmBox_A918 old = self->elems[i].box;
        float r = self->radius;
        sSmVec4_A918 ext;
        ext.x = r;
        ext.y = r;
        ext.z = r;
        ext.w = 0.0f;
        self->elems[i].box.min = vu0Sub_A918(instPos_A918(self, i), ext);
        self->elems[i].box.max = vu0Add_A918(instPos_A918(self, i), ext);
        void* id = self->insts[i];
        func_003291E0(func_002D1BE0(), 0, id, (sBox_F048*)&self->elems[i].box, (sBox_F048*)&old);
        setMin_A918((sSmInst_A918*)self->insts[i], self->elems[i].box.min);
        setMax_A918((sSmInst_A918*)self->insts[i], self->elems[i].box.max);
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035AAD0__FPv);
#ifdef SKIP_ASM
void* func_0035AAD0(void* self)
{
    void* t0 = (char*)*(void**)((char*)self + 0x34) + 0x1;
    *(int*)((char*)self + 0x34) = (int)t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035AAE0__FPv);
#ifdef SKIP_ASM
void* func_0035AAE0(void* self)
{
    void* t0 = (char*)*(void**)((char*)self + 0x34) - 0x1;
    *(int*)((char*)self + 0x34) = (int)t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035AAF0);
#ifdef SKIP_ASM
struct sSmVEntryV_AAF0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sSmVEntryP_AAF0 {
    short delta;
    short index;
    void* (*fn)(void*);
};

extern "C" void* func_0035AAF0(void* self, void* item)
{
    if (*(int*)((char*)self + 0x30) != 0) {
        sSmVEntryV_AAF0* vt = *(sSmVEntryV_AAF0**)self;
        vt[3].fn((char*)self + vt[3].delta);
    }
    if (item == *(void**)((char*)self + 0x40)) {
        void* obj = *(void**)((char*)item + 0xC);
        sSmVEntryP_AAF0* vt2 = *(sSmVEntryP_AAF0**)((char*)obj + 0xC);
        return vt2[24].fn((char*)obj + vt2[24].delta);
    }
    return (char*)item + 0x10;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035AB60);
#ifdef SKIP_ASM
struct sSmVEntryI_AB60 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sSmVEntryV_AB60 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" int func_0035AB60(void* self, void* item)
{
    void* cur = *(void**)((char*)self + 0x40);
    if (item == cur) {
        void* obj = *(void**)((char*)item + 0xC);
        sSmVEntryI_AB60* e = &(*(sSmVEntryI_AB60**)((char*)obj + 0xC))[26];
        if (e->fn((char*)obj + e->delta) != 0) {
            obj = *(void**)(*(char**)((char*)self + 0x40) + 0xC);
            e = &(*(sSmVEntryI_AB60**)((char*)obj + 0xC))[27];
            return e->fn((char*)obj + e->delta);
        }
        return 0;
    }
    void* obj = *(void**)((char*)cur + 0xC);
    sSmVEntryV_AB60* vt = *(sSmVEntryV_AB60**)((char*)obj + 0xC);
    vt[33].fn((char*)obj + vt[33].delta, (char*)item + 0x10, *(int*)((char*)self + 0x38));
    return *(int*)((char*)self + 0x38);
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035ABF0);
#ifdef SKIP_ASM
class cSplineVirt {
public:
    int field_0x0;
    int field_0x4;
    int field_0x8;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual int v51();
};

extern "C" int func_0035ABF0(void* self)
{
    cSplineVirt* o = *(cSplineVirt**)((char*)*(void**)((char*)self + 0x40) + 0xC);
    return o->v51();
}
#endif

INCLUDE_ASM("object/splinemodifier", func_0035AC20);

INCLUDE_ASM("object/splinemodifier", func_0035B200);

//100%
INCLUDE_ASM("object/splinemodifier", func_0035B418);
#ifdef SKIP_ASM
struct sSmVec4_35B418 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSmBox_35B418 {
    char pad_0x0[0x30];
    sSmVec4_35B418 min;     // 0x30
    sSmVec4_35B418 max;     // 0x40
    char pad_0x50[0x10];
};

struct sSmVE_35B418 {
    short delta;
    short index;
    void (*fn)(void*);
};
struct sSmMat_35B418 {
    sSmVec4_35B418 r[4];
};

struct sSmVE43_35B418 {
    short delta;
    short index;
    sSmMat_35B418 (*fn)(void*);
};
struct sSmVE93_35B418 {
    short delta;
    short index;
    int (*fn)(void*, sSmVec4_35B418*, sSmVec4_35B418*, const sSmMat_35B418&);
};
struct sSmVEModel_35B418 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct cMultiSpline_35B418 {
    sSmVE_35B418* vtable;   // 0x0
    int count;              // 0x4
    char pad_0x8[0x14];
    int follow;             // 0x1C
    char pad_0x20[0x10];
    int dirty;              // 0x30
    char pad_0x34[0x4];
    int mode;               // 0x38
    sSmBox_35B418* boxes;   // 0x3C
    char* model;            // 0x40
    char** insts;           // 0x44
};

extern char* D_004A5B80;
extern "C" void func_00345430(void* a, void* b);

extern "C" void func_0035B418(cMultiSpline_35B418* self)
{
    if (self->dirty != 0) {
        self->vtable[3].fn((char*)self + self->vtable[3].delta);
    }
    char* model = *(char**)(self->model + 0xC);
    char* w = D_004A5B80;
    for (int i = 1; i < self->count; i++) {
        sSmVE93_35B418* vt = *(sSmVE93_35B418**)(w + 0x10D8);
        char* thisp = w + vt[93].delta;
        sSmBox_35B418* box = &self->boxes[i];
        sSmVE43_35B418* vt2 = *(sSmVE43_35B418**)(w + 0x10D8);
        int hit = vt[93].fn(thisp, &box->min, &box->max, vt2[43].fn(w + vt2[43].delta));
        if (hit != 1) {
            sSmVEModel_35B418* mvt = *(sSmVEModel_35B418**)(model + 0xC);
            mvt[33].fn(model + mvt[33].delta, self->insts[i] + 0x10, self->mode);
            if (hit != 0) {
                sSmVEModel_35B418* mvt2 = *(sSmVEModel_35B418**)(model + 0xC);
                mvt2[5].fn(model + mvt2[5].delta, (void*)self->mode, 0x420);
            } else {
                sSmVEModel_35B418* mvt2 = *(sSmVEModel_35B418**)(model + 0xC);
                mvt2[5].fn(model + mvt2[5].delta, (void*)self->mode, 0x400);
            }
        }
    }
    if (self->follow != 0) {
        func_00345430((char*)self + 0x48, (char*)self + 0x20);
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035B5A8);
#ifdef SKIP_ASM
class cStream0035B5A8 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
    virtual void v02(void* buf, int size);
    virtual void v03();
    virtual void v04();
    virtual void v05(void* obj);
};

class cStream00359F30;
extern "C" void func_00345538(void* self, cStream00359F30* stream);

extern "C" void func_0035B5A8(void* self, cStream0035B5A8* stream)
{
    stream->v01((char*)self + 0x4, 0x34);
    func_00345538((char*)self + 0x48, (cStream00359F30*)stream);
    stream->v05(*(void**)((char*)self + 0x40));
    for (int i = 0; i < *(int*)((char*)self + 0x4); i++) {
        stream->v01((*(char***)((char*)self + 0x44))[i] + 0x78, 4);
    }
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035B670);
#ifdef SKIP_ASM
extern "C" void func_0035B670(void* self, void* node)
{
    void* h = *(void**)self;
    if (h != 0) {
        *(void**)((char*)h + 0x4) = node;
    }
    *(void**)((char*)node + 0x4) = self;
    *(void**)node = *(void**)self;
    *(void**)self = node;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035B690);
#ifdef SKIP_ASM
struct sSplineLink {
    sSplineLink* next; // 0x0
    sSplineLink* prev; // 0x4
};

extern "C" void func_0035B690(sSplineLink* link, sSplineLink* other)
{
    while (link->next != 0) {
        link = link->next;
    }
    other->next = 0;
    other->prev = link;
    link->next = other;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035B6D0);
#ifdef SKIP_ASM
extern "C" void func_0035B6D0(sSplineLink* link)
{
    if (link->next != 0) {
        link->next->prev = link->prev;
    }
    if (link->prev != 0) {
        link->prev->next = link->next;
    }
    link->next = 0;
    link->prev = 0;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035B708);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void* func_002D1BE0();
extern "C" void* func_002D1BD8();
extern "C" void func_00328F28(void* out, const void* box);
extern "C" void func_003284B8(void* node, int idx, void* item, const void* target, const void* cur);
extern "C" void func_00328C20(void* root, int idx, void* item, const void* target);
extern char D_004911D0[];
extern "C" void cRailModifier_buildXform(void* self);
struct sSmMod_C040;
extern "C" void func_0035C040(sSmMod_C040* self);

struct sSmVec4_B708 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sSmBox_B708 {
    sSmVec4_B708 min;
    sSmVec4_B708 max;
};
struct sSmCell_B708 {
    int level;
    int x, y, z;
};
struct sSmNode_B708 {
    sSmNode_B708* child[2][2][2];   // 0x00
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
struct sSmRoot_B708 {
    sSmCell_B708 cell;              // 0x00
    sSmNode_B708* node;             // 0x10
};
struct sSmSeg_B708 {
    char pad0[0x64];
    sSmSeg_B708* next;              // 0x64
    char pad68[4];
    float minx, miny, minz;         // 0x6C
    float maxx, maxy, maxz;         // 0x78
};
struct sSmTrack_B708 {
    char pad0[0x20];
    int count;                      // 0x20
    sSmSeg_B708* first;             // 0x24
};
struct sSmSet_B708 {
    char pad0[0x44];
    unsigned int* refs;             // 0x44
};
struct sSmWorld_B708 {
    char pad0[0x8];
    sSmSet_B708** sets;             // 0x8
};
struct sSmVEntry_B708 {
    short delta;
    short index;
    int (*fn)(void*);
};
struct sSmModelObj_B708 {
    char pad0[0xC];
    sSmVEntry_B708* vt;             // 0xC
};
struct sSmModel_B708 {
    char pad0[0xC];
    sSmModelObj_B708* obj;          // 0xC
    char pad10[0x50];
    float minx, miny, minz;         // 0x60
    float maxx, maxy, maxz;         // 0x6C
};
struct sSmDesc_B708 {
    int f0;
    unsigned int id;                // 0x4
    int f8;                         // 0x8
};

static inline sSmRoot_B708* findRoot_B708(char* w, int x, int y, int z)
{
    sSmRoot_B708* r = (sSmRoot_B708*)w;
    sSmRoot_B708* rx = x >= 0 ? r : r + 4;
    sSmRoot_B708* ry = y >= 0 ? rx : rx + 2;
    sSmRoot_B708* rz = z >= 0 ? ry : ry + 1;
    return rz;
}

static inline void remove_B708(char* w, void* item, const sSmBox_B708* box)
{
    (*(int*)(w + 0xA0))++;
    sSmCell_B708 c;
    func_00328F28(&c, box);
    sSmRoot_B708* r = findRoot_B708(w, c.x, c.y, c.z);
    func_003284B8(r->node, 2, item, &c, &r->cell);
    if (r->node->empty()) {
        operator_delete((int*)r->node);
        r->node = 0;
    }
}

static inline void insert_B708(char* w, void* item, const sSmBox_B708* box)
{
    sSmCell_B708 c;
    func_00328F28(&c, box);
    func_00328C20(findRoot_B708(w, c.x, c.y, c.z), 2, item, &c);
}

static inline sSmTrack_B708* toTrack_B708(unsigned int p)
{
    return (sSmTrack_B708*)(p << 2);
}

static inline sSmTrack_B708* refToTrack_B708(unsigned int v)
{
    unsigned int p = v >> 8;
    if (p == 0) {
        return 0;
    }
    return toTrack_B708(p);
}

struct sSmRef_B708 {
    unsigned int id;

    sSmTrack_B708* get()
    {
        sSmSet_B708* set = (*(sSmWorld_B708**)func_002D1BD8())->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        return refToTrack_B708(set->refs[id >> 8]);
    }
};

// PORT: PS2-only VU0 inline asm (a -= b).
static inline void subEq_B708(sSmVec4_B708& a, const sSmVec4_B708& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b));
}

// PORT: PS2-only VU0 inline asm (a += b).
static inline void addEq_B708(sSmVec4_B708& a, const sSmVec4_B708& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b));
}

static inline sSmBox_B708 getBox_B708(const sSmModel_B708* m)
{
    sSmBox_B708 b;
    b.min.x = m->minx;
    b.min.y = m->miny;
    b.min.z = m->minz;
    b.min.w = 1.0f;
    b.max.x = m->maxx;
    b.max.y = m->maxy;
    b.max.z = m->maxz;
    b.max.w = 1.0f;
    return b;
}

static inline void setBox_B708(char* self, sSmBox_B708 b)
{
    *(sSmBox_B708*)(self + 0x10) = b;
}

static inline void grow_B708(sSmBox_B708& box, float d)
{
    sSmVec4_B708 pad;
    pad.x = d;
    pad.y = d;
    pad.z = d;
    pad.w = 0.0f;
    subEq_B708(box.min, pad);
    addEq_B708(box.max, pad);
}

extern "C" char* func_0035B708(char* self, sSmDesc_B708* desc, sSmModel_B708* model)
{
    sSmBox_B708* box = (sSmBox_B708*)(self + 0x10);
    *(unsigned int*)(self + 0x30) = 0xFFFFFFFF;
    *(void**)(self + 0x8) = D_004911D0;
    *(void**)(self + 0x0) = 0;
    *(void**)(self + 0x4) = 0;
    *(sSmModel_B708**)(self + 0x40) = model;
    *(unsigned int*)(self + 0x30) = desc->id;
    *(int*)(self + 0x34) = desc->f8;
    sSmModelObj_B708* o = model->obj;
    if (o->vt[44].fn((char*)o + o->vt[44].delta) == 0) {
        sSmModel_B708* m = *(sSmModel_B708**)(self + 0x40);
        sSmBox_B708 b;
        b.min.x = m->minx;
        b.min.y = m->miny;
        b.min.z = m->minz;
        b.min.w = 1.0f;
        b.max.x = m->maxx;
        b.max.y = m->maxy;
        b.max.z = m->maxz;
        b.max.w = 1.0f;
        setBox_B708(self, b);
        sSmVec4_B708 pad;
        pad.x = 100.0f;
        pad.y = 100.0f;
        pad.z = 100.0f;
        pad.w = 0.0f;
        subEq_B708(((sSmBox_B708*)(self + 0x10))->min, pad);
        addEq_B708(((sSmBox_B708*)(self + 0x10))->max, pad);
    }
    cRailModifier_buildXform(self);
    func_0035C040((sSmMod_C040*)self);
    insert_B708((char*)func_002D1BE0(), *(void**)(self + 0x44), box);
    sSmTrack_B708* t = ((sSmRef_B708*)(self + 0x30))->get();
    sSmSeg_B708* seg = t->first;
    for (int i = 0; i < t->count; i++) {
        sSmBox_B708 b;
        b.min.x = seg->minx;
        b.min.y = seg->miny;
        b.min.z = seg->minz;
        b.min.w = 1.0f;
        b.max.x = seg->maxx;
        b.max.y = seg->maxy;
        b.max.z = seg->maxz;
        b.max.w = 1.0f;
        remove_B708((char*)func_002D1BE0(), seg, &b);
        seg = seg->next;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("object/splinemodifier", func_0035BA88);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void* func_002D1BE0();

struct sSmVec4_BA88 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sSmBox_BA88 {
    sSmVec4_BA88 min;
    sSmVec4_BA88 max;
};
struct sSmCell_BA88 {
    int level;
    int x, y, z;
};
struct sSmNode_BA88 {
    sSmNode_BA88* child[2][2][2];   // 0x00
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
struct sSmRoot_BA88 {
    sSmCell_BA88 cell;              // 0x00
    sSmNode_BA88* node;             // 0x10
};
struct sSmSeg_BA88 {
    char pad0[0x64];
    sSmSeg_BA88* next;              // 0x64
    char pad68[4];
    float minx, miny, minz;         // 0x6C
    float maxx, maxy, maxz;         // 0x78
};
struct sSmTrack_BA88 {
    char pad0[0x20];
    int count;                      // 0x20
    sSmSeg_BA88* first;             // 0x24
};
struct sSmSet_BA88 {
    char pad0[0x44];
    unsigned int* refs;             // 0x44
};
struct sSmWorld_BA88 {
    char pad0[0x8];
    sSmSet_BA88** sets;             // 0x8
};

extern "C" void* func_002D1BD8();
extern "C" void func_00328F28(void* out, const void* box);
extern "C" void func_003284B8(void* node, int idx, void* item, const void* target, const void* cur);
extern "C" void func_00328C20(void* root, int idx, void* item, const void* target);
extern char D_004911D0[];
extern "C" void cRailModifier_buildXform(void* self);

class cSmStream_BA88 {
public:
    virtual void v01();
    virtual void v02(void* p, int n);
    virtual int v03();
};

static inline sSmRoot_BA88* findRoot_BA88(char* w, const sSmCell_BA88& c)
{
    sSmRoot_BA88* r = (sSmRoot_BA88*)w;
    sSmRoot_BA88* rx = c.x >= 0 ? r : r + 4;
    sSmRoot_BA88* ry = c.y >= 0 ? rx : rx + 2;
    sSmRoot_BA88* rz = c.z >= 0 ? ry : ry + 1;
    return rz;
}

static inline void remove_BA88(char* w, void* item, const sSmBox_BA88* box)
{
    (*(int*)(w + 0xA0))++;
    sSmCell_BA88 c;
    func_00328F28(&c, box);
    sSmRoot_BA88* r = findRoot_BA88(w, c);
    func_003284B8(r->node, 2, item, &c, &r->cell);
    if (r->node->empty()) {
        operator_delete((int*)r->node);
        r->node = 0;
    }
}

static inline void insert_BA88(char* w, void* item, const sSmBox_BA88* box)
{
    sSmCell_BA88 c;
    func_00328F28(&c, box);
    func_00328C20(findRoot_BA88(w, c), 2, item, &c);
}

static inline sSmTrack_BA88* toTrack_BA88(unsigned int p)
{
    return (sSmTrack_BA88*)(p << 2);
}

static inline sSmTrack_BA88* refToTrack_BA88(unsigned int v)
{
    unsigned int p = v >> 8;
    if (p == 0) {
        return 0;
    }
    return toTrack_BA88(p);
}

struct sSmRef_BA88 {
    unsigned int id;

    sSmTrack_BA88* get()
    {
        sSmSet_BA88* set = (*(sSmWorld_BA88**)func_002D1BD8())->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        return refToTrack_BA88(set->refs[id >> 8]);
    }
};

extern "C" char* func_0035BA88(char* self, cSmStream_BA88* src)
{
    *(unsigned int*)(self + 0x30) = 0xFFFFFFFF;
    *(void**)(self + 0x8) = D_004911D0;
    *(void**)(self + 0x0) = 0;
    *(void**)(self + 0x4) = 0;
    src->v02(self + 0x10, 0x30);
    *(int*)(self + 0x40) = src->v03();
    cRailModifier_buildXform(self);
    insert_BA88((char*)func_002D1BE0(), *(void**)(self + 0x44), (sSmBox_BA88*)(self + 0x10));
    sSmTrack_BA88* t = ((sSmRef_BA88*)(self + 0x30))->get();
    sSmSeg_BA88* seg = t->first;
    for (int i = 0; i < t->count; i++) {
        sSmBox_BA88 b;
        b.min.x = seg->minx;
        b.min.y = seg->miny;
        b.min.z = seg->minz;
        b.min.w = 1.0f;
        b.max.x = seg->maxx;
        b.max.y = seg->maxy;
        b.max.z = seg->maxz;
        b.max.w = 1.0f;
        remove_BA88((char*)func_002D1BE0(), seg, &b);
        seg = seg->next;
    }
    return self;
}
#endif

INCLUDE_ASM("object/splinemodifier", func_0035BD70);

//100%
INCLUDE_ASM("object/splinemodifier", func_0035C040);
#ifdef SKIP_ASM
struct sSmVec4_C040 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSmBox_C040 {
    sSmVec4_C040 min;
    sSmVec4_C040 max;
};

struct sSmVEntryI_C040 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sSmVEntryB_C040 {
    short delta;
    short index;
    sSmBox_C040* (*fn)(void*);
};

struct sSmVtbl_C040 {
    char pad_0x0[0x160];
    sSmVEntryI_C040 v44;    // 0x160
    sSmVEntryB_C040 v45;    // 0x168
};

struct sSmObj_C040 {
    char pad_0x0[0xC];
    sSmVtbl_C040* vt;       // 0xC
};

struct sSmOwner_C040 {
    char pad_0x0[0xC];
    sSmObj_C040* obj;       // 0xC
};

struct sSmMod_C040 {
    char pad_0x0[0x10];
    sSmBox_C040 box;        // 0x10
    char pad_0x30[0x10];
    sSmOwner_C040* owner;   // 0x40
};

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (a -= b, 4 floats).
static inline void vecSubEq_C040(sSmVec4_C040& a, const sSmVec4_C040& b)
{
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        ".set pop\n"
        : "=m"(a)
        : "m"(a), "m"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm; the PC port needs a C fallback (a += b, 4 floats).
static inline void vecAddEq_C040(sSmVec4_C040& a, const sSmVec4_C040& b)
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

extern "C" void func_0035C040(sSmMod_C040* self)
{
    sSmObj_C040* o = self->owner->obj;
    if (o->vt->v44.fn((char*)o + o->vt->v44.delta) != 0) {
        o = self->owner->obj;
        sSmBox_C040* b = o->vt->v45.fn((char*)o + o->vt->v45.delta);
        self->box = *b;
        sSmVec4_C040 pad;
        pad.x = 100.0f;
        pad.y = 100.0f;
        pad.z = 100.0f;
        pad.w = 0.0f;
        vecSubEq_C040(self->box.min, pad);
        vecAddEq_C040(self->box.max, pad);
    }
}
#endif

