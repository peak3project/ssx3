#include "common.h"

//100%
INCLUDE_ASM("animation/rideranimbase", cRiderAnimBase_cRiderAnimBase);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d), like cMemMan_alloc.
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void func_003142E8(void* self);
extern "C" void func_00311A50(void* self);
extern char D_0048D7D8[];
extern const char D_0048A4E0[];

extern "C" void* cRiderAnimBase_cRiderAnimBase(void* self)
{
    *(int*)((char*)self + 0x54) = 0;
    *(void**)((char*)self + 0x58) = D_0048D7D8;
    *(void**)((char*)self + 0x50) = operator_new_tag(0x30, D_0048A4E0, 0, 0);
    for (int i = 0; i < 6; i++)
    {
        func_003142E8(*(char**)((char*)self + 0x50) + (i << 3));
    }
    func_00311A50(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00311958);
#ifdef SKIP_ASM
void cMemMan_free(void* p);
void operator_delete(int* p);
extern "C" void func_00314668(void* self);
extern char D_0048D7D8[];

extern "C" void func_00311958(void* self, int flags)
{
    *(void**)((char*)self + 0x58) = D_0048D7D8;
    for (int i = 0; i < 6; i++)
    {
        func_00314668(*(char**)((char*)self + 0x50) + (i << 3));
    }
    void* p = *(void**)((char*)self + 0x50);
    if (p)
        cMemMan_free(p);
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

INCLUDE_ASM("animation/rideranimbase", func_003119E8);

INCLUDE_ASM("animation/rideranimbase", func_003119F8);

INCLUDE_ASM("animation/rideranimbase", func_00311A30);

//100%
INCLUDE_ASM("animation/rideranimbase", func_00311A50);
#ifdef SKIP_ASM
extern "C" void func_00314668(void* self);

struct sRabQuad32 {
    int w[8];
} __attribute__((aligned(16)));

extern sRabQuad32 D_004FF230;

struct sRiderAnimBase {
    int mAnims[6];      // 0x00
    int m18;            // 0x18
    float m1C;          // 0x1C
    long m20;           // 0x20 PORT: 64-bit long (sd)
    int pad28[2];       // 0x28
    sRabQuad32 m30;     // 0x30
    char* mSequencers;  // 0x50
};

extern "C" void func_00311A50(void* p)
{
    sRiderAnimBase* self = (sRiderAnimBase*)p;
    for (int i = 0; i < 6; i++)
    {
        func_00314668(self->mSequencers + (i << 3));
        self->mAnims[i] = 0x1B6;
    }
    //START
    self->m18 = 0;
    self->m1C = 1.0f;
    self->m30 = D_004FF230;
    self->m20 = -1;
    //END
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00311AE8);
#ifdef SKIP_ASM
extern "C" int* cAIAnimEventMap_getBlendInTime(int anim);

extern "C" int func_00311AE8(void* self, int i)
{
    int anim = *(int*)((char*)self + (i << 2));
    if (anim == 0x1B6) {
        return 0;
    }
    return *cAIAnimEventMap_getBlendInTime(anim);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00311B20);
#ifdef SKIP_ASM
struct cAnimSequenceNode;

struct cAnimSequencer {
    int mCount;                        // 0x0
    cAnimSequenceNode* mFirstSequence; // 0x4
};

cAnimSequenceNode* cAnimSequencer_getSequence(cAnimSequencer* self, int index);

extern "C" cAnimSequenceNode* func_00311B20(void* self, int i)
{
    cAnimSequencer* seqs = *(cAnimSequencer**)((char*)self + 0x50);
    return cAnimSequencer_getSequence(&seqs[i], 0);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", cRiderAnimBase_changeHeadingOffset);
#ifdef SKIP_ASM
extern "C" void func_0031BE50(float* s, float* c, float angle);

struct sRabQuat_00311B48
{
    float x, y, z, w;
    sRabQuat_00311B48() {}
    sRabQuat_00311B48(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));

struct sRabXform_00311B48
{
    sRabQuat_00311B48 pos;
    sRabQuat_00311B48 rot;
};

extern sRabQuat_00311B48 D_004FF130;
extern sRabQuat_00311B48 D_004FF160;
extern "C" void cRiderAnimBase_changeOrientationOffset(void* self, sRabXform_00311B48* xf);

static inline sRabQuat_00311B48 AxisAngle_00311B48(const sRabQuat_00311B48& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sRabQuat_00311B48(s * axis.x, s * axis.y, s * axis.z, c);
}

extern "C" void cRiderAnimBase_changeHeadingOffset(void* self, float angle)
{
    sRabXform_00311B48 xf;
    xf.pos = D_004FF130;
    xf.rot = AxisAngle_00311B48(D_004FF160, -angle);
    cRiderAnimBase_changeOrientationOffset(self, &xf);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", cRiderAnimBase_changeOrientationOffset);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sRabQuat_00311B48 QuatMul_00311BF0(const sRabQuat_00311B48& a, const sRabQuat_00311B48& b)
{
    sRabQuat_00311B48 r;
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
static inline sRabQuat_00311B48 Sub_00311BF0(const sRabQuat_00311B48& a, const sRabQuat_00311B48& b)
{
    sRabQuat_00311B48 r;
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
static inline sRabQuat_00311B48 Add_00311BF0(const sRabQuat_00311B48& a, const sRabQuat_00311B48& b)
{
    sRabQuat_00311B48 r;
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
static inline sRabQuat_00311B48 Rot_00311BF0(const sRabQuat_00311B48& q, const sRabQuat_00311B48& v)
{
    sRabQuat_00311B48 r;
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

static inline sRabXform_00311B48 Combine_00311BF0(const sRabXform_00311B48& a, const sRabXform_00311B48& b)
{
    sRabXform_00311B48 r;
    r.rot = QuatMul_00311BF0(a.rot, b.rot);
    r.pos = Add_00311BF0(Rot_00311BF0(a.rot, Sub_00311BF0(b.pos, D_004FF130)), a.pos);
    return r;
}

extern "C" void cRiderAnimBase_changeOrientationOffset(void* self, sRabXform_00311B48* xf)
{
    for (int i = 0; i < 6; i++) {
        int j = 0;
        if (j < (*(cAnimSequencer**)((char*)self + 0x50))[i].mCount) {
            do {
            sRabXform_00311B48* src = (sRabXform_00311B48*)((char*)cAnimSequencer_getSequence(&(*(cAnimSequencer**)((char*)self + 0x50))[i], j) + 0x60);
            sRabXform_00311B48* dst = (sRabXform_00311B48*)((char*)cAnimSequencer_getSequence(&(*(cAnimSequencer**)((char*)self + 0x50))[i], j) + 0x60);
            *dst = Combine_00311BF0(*xf, *src);
                j++;
            } while (j < (*(cAnimSequencer**)((char*)self + 0x50))[i].mCount);
        }
    }
}
#endif

INCLUDE_ASM("animation/rideranimbase", func_00311D88);

INCLUDE_ASM("animation/rideranimbase", func_00311E38);

//100%
INCLUDE_ASM("animation/rideranimbase", func_00311E88);
#ifdef SKIP_ASM
extern "C" void func_00314718(void* self, int v);
extern "C" void func_003146D0(void* self, float v);

extern "C" void func_00311E88(char* self, int i, float v)
{
    func_00314718(*(char**)(self + 0x50) + (i << 3), 0x3F);
    func_003146D0(*(char**)(self + 0x50) + (i << 3), v);
    *(int*)(self + (i << 2)) = 0x1B6;
}
#endif

INCLUDE_ASM("animation/rideranimbase", func_00311F00);

//100%
INCLUDE_ASM("animation/rideranimbase", func_003123C0);
#ifdef SKIP_ASM
struct sVEntry003123C0 {
    short delta;
    short index;
    void (*fn)(void*, cAnimSequencer*, cAnimSequenceNode*, float);
};

extern "C" void func_00312598(void* self, int a1);

extern "C" void func_003123C0(char* self, int a1, float t)
{
    for (int i = 0; i < 6; i++)
    {
        cAnimSequenceNode* node = cAnimSequencer_getSequence(&(*(cAnimSequencer**)(self + 0x50))[i], 0);
        while (node)
        {
            cAnimSequenceNode* next = *(cAnimSequenceNode**)((char*)node + 0xC8);
            sVEntry003123C0* vt = *(sVEntry003123C0**)(self + 0x58);
            vt[2].fn(self + vt[2].delta, &(*(cAnimSequencer**)(self + 0x50))[i], node, t);
            node = next;
        }
    }
    func_00312598(self, a1);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312490);
#ifdef SKIP_ASM
extern "C" int func_001446A0(void* self, int mask);

struct sVEntry00312490 {
    short delta;
    short index;
    void (*fn)(void*, cAnimSequencer*, cAnimSequenceNode*);
};

struct sSeqRef_00312490 {
    cAnimSequenceNode* node;
    cAnimSequencer* seq;
};

extern "C" void func_00312490(char* self)
{
    sSeqRef_00312490 list[32];
    int n = 0;
    for (int i = 0; i < 6; i++)
    {
        cAnimSequenceNode* node = cAnimSequencer_getSequence(&(*(cAnimSequencer**)(self + 0x50))[i], 0);
        while (node)
        {
            if (func_001446A0((char*)node + 0xB0, 0x3F) != 0)
            {
                list[n].node = node;
                list[n].seq = &(*(cAnimSequencer**)(self + 0x50))[i];
                n++;
            }
            node = *(cAnimSequenceNode**)((char*)node + 0xC8);
        }
    }
    for (int k = 0; k < n; k++)
    {
        sVEntry00312490* vt = *(sVEntry00312490**)(self + 0x58);
        vt[3].fn(self + vt[3].delta, list[k].seq, list[k].node);
    }
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312598);
#ifdef SKIP_ASM
struct sAnimState_00312598
{
    char data[0x50];
    sAnimState_00312598() {}
};

extern "C" int func_00314418(void* seq, sAnimState_00312598* out, int max);
extern "C" void func_0030F2B0(void* model, int count, sAnimState_00312598* states, int a3);

extern "C" void func_00312598(void* p, int a1)
{
    char* self = (char*)p;
    int n = 0;
    sAnimState_00312598 states[0x40];
    for (int i = 0; i < 6; i++)
    {
        n += func_00314418(*(char**)(self + 0x50) + (i << 3), &states[n], 0x40 - n);
    }
    func_0030F2B0(*(void**)(self + 0x54), n, states, a1);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312660);
#ifdef SKIP_ASM
extern "C" int func_00311F00(void* self, void* seq, int anim, int a3, int a4, int a5, float blend);
extern "C" void* cAnimSequencer_getSequence(void* self, int index) __asm__("cAnimSequencer_getSequence__FP14cAnimSequenceri");
extern "C" void func_00313CF0(void* self, int idx, float v);
extern "C" int func_00314418_2660(void* self, void* out, int max) __asm__("func_00314418");
extern "C" void func_00314668(void* self);
extern char* D_004A3E7C;
extern int D_004A5950;

struct sVEntry00312660 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sSeqVec_312660 {
    float x, y, z, w;
    sSeqVec_312660() {}
} __attribute__((aligned(16)));

struct sSeqState_312660 {
    int id;
    float time;
    int pad08[2];
    long e;
    char pad18[0x8];
    sSeqVec_312660 a;
    sSeqVec_312660 b;
    int c;
    char pad44[0xC];
};

struct sSequencer_312660 {
    int mCount;
    void* mFirstSequence;
};

// Samples the first animation state of 'anim' at time 't' using a temporary sequencer.
extern "C" sSeqState_312660 func_00312660(char* self, int anim, int h, float t)
{
    sSeqState_312660 states[0x40];
    sSequencer_312660 seq;
    func_003142E8(&seq);
    if (h == D_004A5950) {
        sVEntry00312660* vt = *(sVEntry00312660**)(self + 0x58);
        int id = vt[4].fn(self + vt[4].delta, anim);
        h = *(int*)(id * 4 + D_004A3E7C + 0x1030);
    }
    func_00311F00(self, &seq, anim, h, 1, 0, 0.0f);
    func_00313CF0(cAnimSequencer_getSequence(&seq, 0), 0, t);
    func_00314418_2660(&seq, states, 0x40);
    func_00314668(&seq);
    return states[0];
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312790);
#ifdef SKIP_ASM
struct sVEntry00312790 {
    short delta;
    short index;
    int (*fn)(void*, int);
};
extern char* D_004A3E7C;
extern char** D_004A3DF8;

extern "C" float func_00312790(char* self, int a1)
{
    sVEntry00312790* vt = *(sVEntry00312790**)(self + 0x58);
    int id = vt[4].fn(self + vt[4].delta, a1);
    if (id == 0x207)
        return 0.0f;
    unsigned int h = *(unsigned int*)(id * 4 + D_004A3E7C + 0x1030);
    char* clip = *(char**)((char*)D_004A3DF8 + ((h & 0xFF) << 2));
    char* q = (char*)((h >> 8) * 0x14 + *(int*)(clip + 0x8));
    return (*(unsigned short*)(q + 0xC) - 1) * 0.03333333507180214f;
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312820);
#ifdef SKIP_ASM
struct sVEntry00312820 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sAnimKey00312820 {
    unsigned short value;
    unsigned short pad;
};

extern "C" float func_00312820(char* self, int a1, int frame)
{
    sVEntry00312820* vt = *(sVEntry00312820**)(self + 0x58);
    int id = vt[4].fn(self + vt[4].delta, a1);
    if (id == 0x207)
        return 0.0f;
    unsigned int h = *(unsigned int*)(id * 4 + D_004A3E7C + 0x1030);
    char* clip = *(char**)((char*)D_004A3DF8 + ((h & 0xFF) << 2));
    char* q = (char*)((h >> 8) * 0x14 + *(int*)(clip + 0x8));
    float r;
    if (frame < *(unsigned short*)(q + 0x12))
    {
        sAnimKey00312820* keys = *(sAnimKey00312820**)(clip + 0x10);
        r = keys[*(unsigned short*)(q + 0x10) + frame].value * 0.03333333507180214f;
    }
    else
    {
        r = -1.0f;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/rideranimbase", cRiderAnimBase_play);
#ifdef SKIP_ASM
extern "C" int* cAIAnimEventMap_getBlendInTime(int anim);
extern "C" int func_00311F00(void* self, void* seq, int anim, int a3, int a4, int a5, float blend);
extern int D_0048D808[];
extern char* D_004A3E7C;

struct sVEntry003128E8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

// PORT: the unit declares cRiderAnimBase_play as void for its callers, but it returns the new
// sequence id (callers in ai/ai read $v0); the int-returning body is bound by asm label.
int cRiderAnimBase_play_impl(char* self, int anim, int flags, float blend) __asm__("cRiderAnimBase_play");

int cRiderAnimBase_play_impl(char* self, int anim, int flags, float blend)
{
    sVEntry003128E8* vt = *(sVEntry003128E8**)(self + 0x58);
    int id = vt[4].fn(self + vt[4].delta, anim);
    if (id == 0x207)
        return 0x1B6;
    if (blend < 0.0f)
    {
        blend = *(float*)&cAIAnimEventMap_getBlendInTime(anim)[4];
    }
    int h = *(int*)(id * 4 + D_004A3E7C + 0x1030);
    int slot = cAIAnimEventMap_getBlendInTime(anim)[3];
    return *(int*)(self + (slot << 2)) = func_00311F00(self, *(char**)(self + 0x50) + (slot << 3), anim, h, flags, D_0048D808[slot], blend);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/rideranimbase", func_003129E0);
#ifdef SKIP_ASM
extern "C" int* cAIAnimEventMap_getBlendInTime(int anim);
extern "C" int func_00311F00(void* self, void* seq, int anim, int a3, int a4, int a5, float blend);
extern int D_0048D808[];

extern "C" void func_003129E0(char* self, int anim, int a2, float blend)
{
    int slot = cAIAnimEventMap_getBlendInTime(anim)[3];
    if (blend < 0.0f)
    {
        blend = *(float*)&cAIAnimEventMap_getBlendInTime(anim)[4];
    }
    *(int*)(self + (slot << 2)) = func_00311F00(self, *(char**)(self + 0x50) + (slot << 3), anim, a2, 1, D_0048D808[slot], blend);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312AA0__FPvi);
#ifdef SKIP_ASM
int func_00312AA0(void* self, int i)
{
    return *(int*)((char*)self + (i << 2));
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312AB0);
#ifdef SKIP_ASM
extern "C" float func_00312AB0(void* self, int i)
{
    cAnimSequencer* seqs = *(cAnimSequencer**)((char*)self + 0x50);
    cAnimSequenceNode* node = cAnimSequencer_getSequence(&seqs[i], 0);
    return *(float*)((char*)node + 0x8) / *(float*)((char*)node + 0x10);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00312AE8);
#ifdef SKIP_ASM
extern "C" int func_00312AE8(void* self, int i)
{
    cAnimSequencer* seqs = *(cAnimSequencer**)((char*)self + 0x50);
    return *(int*)((char*)cAnimSequencer_getSequence(&seqs[i], 0) + 0xC0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/rideranimbase", func_00312B18);
#ifdef SKIP_ASM
struct cAnimSequence;
void cAnimSequence_fadeWeight(cAnimSequence* self, float weight, float target);
extern "C" void func_003145F8(void* seq, void* node);
extern "C" void cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" int func_00312B18(void* self, cAnimSequencer* seq, char* node, int anim)
{
    float w = *(float*)(node + 0x94);
    float target = *(float*)(node + 0x9C);
    float weight = *(float*)(node + 0x98);
    func_003145F8(seq, node);
    cRiderAnimBase_play(self, anim, 0, -1.0f);
    char* s = (char*)cAnimSequencer_getSequence(seq, 0);
    *(float*)(s + 0x98) = w;
    *(float*)(s + 0x94) = w;
    if (target != 0.0f)
    {
        cAnimSequence_fadeWeight((cAnimSequence*)s, weight, target);
    }
    return anim;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/rideranimbase", func_00312BD0);
#ifdef SKIP_ASM
extern "C" void func_00144670(void* self, int bit);
extern "C" void cRiderAnimBase_play(void* self, int anim, int flags, float blend);

extern "C" void func_00312BD0(void* self, void* unused, void* rider, int anim)
{
    func_00144670((char*)rider + 0xB0, 0x3F);
    cRiderAnimBase_play(self, anim, 0, -1.0f);
}
#endif

INCLUDE_ASM("animation/rideranimbase", func_00312C20);

INCLUDE_ASM("animation/rideranimbase", func_003130A8);

//100%
INCLUDE_ASM("animation/rideranimbase", func_00313508);
#ifdef SKIP_ASM
struct sAnimSlot_00313508
{
    char pad0[0x14];
    int active;      // 0x14
    char pad18[0x4];
    sAnimSlot_00313508() {}
};

struct sRiderAnim_00313508
{
    int owner;                      // 0x0
    sAnimSlot_00313508 slots[3];    // 0x4
    char pad58[0x8];
    sRabQuad32 pair;                // 0x60
    int u80;                        // 0x80
    int u84;                        // 0x84
    long u88;                       // 0x88
    float f90;                      // 0x90
    float value;                    // 0x94
    float target;                   // 0x98
    float remaining;                // 0x9C
    int notify;                     // 0xA0
    int uA4;                        // 0xA4
    int uA8;                        // 0xA8
    void* head;                     // 0xAC
    ulong active;                   // 0xB0
    ulong triggered;                // 0xB8
    int dirty;                      // 0xC0
    int uC4;                        // 0xC4
    sRiderAnim_00313508(int owner);
};

inline void* operator new(unsigned int, void* p) { return p; }

// PORT: long/ulong are 64-bit here
inline sRiderAnim_00313508::sRiderAnim_00313508(int o)
{
    owner = o;
    for (int i = 2; i >= 0; i--)
    {
        slots[i].active = 0;
    }
    pair = D_004FF230;
    u88 = -1;
    u80 = 0;
    u84 = 0;
    f90 = 1.0f;
    remaining = 0.0f;
    value = 1.0f;
    target = 1.0f;
    notify = 0;
    uA4 = 0;
    uA8 = 0;
    triggered = 0;
    active = 0;
    head = 0;
    dirty = 0;
    uC4 = 0;
}

extern "C" sRiderAnim_00313508* func_00313508(sRiderAnim_00313508* self, int owner)
{
    return new (self) sRiderAnim_00313508(owner);
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_003135B0);
#ifdef SKIP_ASM
struct sAnimEvents_00313868;
struct sAnimEvents_00313938;
extern "C" void func_00313868(sAnimEvents_00313868* self, float from, float to);
extern "C" void func_00313938(sAnimEvents_00313938* self, float time);
extern "C" void func_003139A8(sAnimEvents_00313938* self);

struct sTrack_003135B0 {
    int field_0x0;
    float time;     // 0x4
    float speed;    // 0x8
    float length;   // 0xC
    char pad10[0x8];
    int loop;       // 0x18
};

// PORT: ulong is 64-bit here
struct sRab_003135B0 {
    int field_0x0;
    sTrack_003135B0 tracks[3];  // 0x4
    char pad58[0x90 - 0x58];
    float scale;                // 0x90
    char pad94[0xB8 - 0x94];
    ulong triggered;            // 0xB8
    int fC0;                    // 0xC0
    int fC4;                    // 0xC4
};

// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).

static inline float ffloor_003135B0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

static inline void fire_003135B0(sRab_003135B0* self, float from, float to)
{
    func_00313868((sAnimEvents_00313868*)self, from, to);
}

extern "C" int func_003135B0(sRab_003135B0* self, int i, float dt)
{
    float t0 = self->tracks[i].time;
    float len = self->tracks[i].length;
    float t = t0 + self->tracks[i].speed * self->scale * dt;
    if (i == 0) {
        self->triggered = 0;
        self->fC0 = 0;
        if (self->fC4 != 0) {
            func_00313938((sAnimEvents_00313938*)self, t0);
            self->fC4 = 0;
        }
    }
    if (self->tracks[i].loop == 0) {
        if (t <= 0.0f) {
            t = 0.0f;
            if (i == 0) {
                func_003139A8((sAnimEvents_00313938*)self);
            }
        } else if (len <= t) {
            t = len;
            if (i == 0) {
                func_003139A8((sAnimEvents_00313938*)self);
            }
        }
        if (i == 0) {
            fire_003135B0(self, t0, t);
        }
    } else if (t < 0.0f || len <= t) {
        int n = (int)ffloor_003135B0(t / len);
        t -= len * (float)n;
        if (i == 0) {
            func_003139A8((sAnimEvents_00313938*)self);
            if (n >= 2) {
                fire_003135B0(self, 0.0f, len);
            } else if (n < -1) {
                fire_003135B0(self, len, 0.0f);
            } else if (n == 1) {
                if (t0 <= t) {
                    fire_003135B0(self, 0.0f, len);
                } else {
                    fire_003135B0(self, t0, len);
                    fire_003135B0(self, 0.0f, t);
                }
            } else if (n == -1) {
                if (t <= t0) {
                    fire_003135B0(self, len, 0.0f);
                } else {
                    fire_003135B0(self, t0, 0.0f);
                    fire_003135B0(self, len, t);
                }
            }
        }
    } else if (i == 0) {
        fire_003135B0(self, t0, t);
    }
    self->tracks[i].time = t;
    return 0;
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00313800);
#ifdef SKIP_ASM
struct sBlend_00313800
{
    char pad0[0x94];
    float value;     // 0x94
    float target;    // 0x98
    float remaining; // 0x9C
    int notify;      // 0xA0
};

// Moves value toward target over the remaining time; returns 1 when the blend
// finishes and notify is set.
extern "C" int func_00313800(sBlend_00313800* self, float dt)
{
    float t = self->remaining;
    if (t != 0.0f)
    {
        if (t <= dt)
        {
            self->value = self->target;
            self->remaining = 0.0f;
            if (self->notify != 0)
            {
                return 1;
            }
        }
        else
        {
            float v = self->value;
            self->remaining = t - dt;
            self->value = v + (dt / t) * (self->target - v);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00313868);
#ifdef SKIP_ASM
struct sAnimEvent_00313868
{
    int bit;                        // 0x0
    int kind;                       // 0x4
    float time;                     // 0x8
    sAnimEvent_00313868* next;      // 0xC
};

struct sAnimEvents_00313868
{
    char pad0[0xAC];
    sAnimEvent_00313868* head;      // 0xAC
    ulong active;                   // 0xB0
    ulong triggered;                // 0xB8
};

// Fires every kind-0 event whose time lies in (from, to] (or [to, from) when
// playing backwards).
// PORT: ulong is 64-bit here
extern "C" void func_00313868(sAnimEvents_00313868* self, float from, float to)
{
    if (from == to)
    {
        return;
    }
    int forward = from <= to;
    for (sAnimEvent_00313868* e = self->head; e != 0; e = e->next)
    {
        if (e->kind == 0)
        {
            float t = e->time;
            if (forward)
            {
                if (!(from < t && t <= to))
                    continue;
            }
            else
            {
                if (!(to <= t && t < from))
                    continue;
            }
            ulong bit = (ulong)1 << e->bit;
            ulong old = self->active;
            self->active = old | bit;
            self->triggered |= bit & ~old;
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_00313938);
#ifdef SKIP_ASM
struct sAnimEvent_00313938
{
    int bit;                        // 0x0
    int kind;                       // 0x4
    float time;                     // 0x8
    sAnimEvent_00313938* next;      // 0xC
};

struct sAnimEvents_00313938
{
    char pad0[0xAC];
    sAnimEvent_00313938* head;      // 0xAC
    ulong active;                   // 0xB0
    ulong triggered;                // 0xB8
    int dirty;                      // 0xC0
};

// PORT: ulong is 64-bit here
extern "C" void func_00313938(sAnimEvents_00313938* self, float time)
{
    for (sAnimEvent_00313938* e = self->head; e != 0; e = e->next)
    {
        if (e->kind == 0 && e->time == time)
        {
            ulong bit = (ulong)1 << e->bit;
            ulong old = self->active;
            self->active = old | bit;
            self->triggered |= bit & ~old;
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/rideranimbase", func_003139A8);
#ifdef SKIP_ASM
// PORT: ulong is 64-bit here
extern "C" void func_003139A8(sAnimEvents_00313938* self)
{
    self->dirty = 1;
    for (sAnimEvent_00313938* e = self->head; e != 0; e = e->next)
    {
        if (e->kind != 0)
        {
            ulong bit = (ulong)1 << e->bit;
            ulong old = self->active;
            self->active = old | bit;
            self->triggered |= bit & ~old;
        }
    }
}
#endif

