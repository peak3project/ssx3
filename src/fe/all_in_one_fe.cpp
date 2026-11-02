#include "common.h"

// g++ 2.95 vtable slot: this-pointer adjustment, index, function (F is the slot's function type;
// sVEntry<void> is a raw slot). Virtual calls in this unit go through these by hand.
template <class F> struct sVEntry {
    short delta;
    short index;
    F* fn;
};

// EA's 2-float vector (prototype name, e.g. setTileUV__7cUIIconG8t2Vector).
struct t2Vector {
    float x, y;
};

// Vertex position of the HUD sprite quads: 16-byte aligned, with an empty default ctor (vertex arrays get a vec_new
// loop) and the (x, y, z, const float& w) ctor the quad builders use.
struct sVtxPos {
    float x, y, z, w;
    sVtxPos() {}
    sVtxPos(float ax, float ay, float az, const float& aw) : x(ax), y(ay), z(az), w(aw) {}
    void setZW(float az, float aw) { z = az; w = aw; }
} __attribute__((aligned(16)));

// One vertex as the render context's slot-71 draw call takes it: UV + q, integer colour, position.
struct sHudVertex {
    float u, v, q, pad;
    int g, b, a, r;
    sVtxPos pos;
};

// The render context D_004A289C as these functions use it: GS state block pointer at 0xE84, vptr at 0x10D8 (slot 71
// draws a vertex list).
struct sRenderCtx {
    char pad[0xE84];
    char* e84;              // 0xE84
};
extern sRenderCtx* D_004A289C;

// An RGBA colour as the element colour getter func_001E91A8 writes it and func_001F1190 takes it (the first component
// is the one the fades scale).
struct sColour {
    float r, g, b, a;
};

// Four floats, 4-byte aligned (not a t4Vector, which is 16-aligned): the 4-float slots some callers give the element
// position / scale getters.
struct sFloat4 {
    float x, y, z, w;
};

// The rider's cBeing interface (rider + 0x6C0), slots in the prototype's order (as in seg/seg_1FBE38).
struct t4Vector;
struct t4Matrix;
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

// Script value (luno/lunovm.cpp layout; as in seg/seg_1FBE38): a word or a pair, then the type (4 = table, 5 = pair).
// D_004C9098 is the nil value.
struct cLunoValue;
extern "C" void func_00224DF0(cLunoValue*, int);
extern "C" void func_00225068(cLunoValue*, const cLunoValue*);
extern "C" void luno_cLunoVM_execute(cLunoValue**, char**, int);
struct cLunoPair {
    int a, b;
};
struct cLunoValue {
    union {
        int i;
        cLunoPair pair;
    } u;
    int type;
    cLunoValue() { type = 0; u.i = 0; }
    ~cLunoValue() {}
    void Release() { if (type == 4) func_00224DF0(this, 2); }
    void Clear() { type = 0; u.i = 0; }
    void SetTable(const cLunoValue* src) {
        Release();
        Clear();
        func_00225068(this, src);
        type = 4;
    }
    void Assign(const cLunoValue* src) {
        Release();
        Clear();
        if (src->type == 4) {
            func_00225068(this, src);
        } else if (src->type == 5) {
            u.pair = src->u.pair;
        } else {
            u.i = src->u.i;
        }
        type = src->type;
    }
};
extern cLunoValue D_004C9098;

// A HUD sprite: texture id and UV rectangle.
struct sHudSprite {
    int tex;                // 0x0
    int pad[2];
    float v0;               // 0xC
    float u0;               // 0x10
    float u1;               // 0x14
    float v1;               // 0x18
};

// Gauge layout: segment scale and number of middle segments.
struct sGaugeBar {
    float scale;
    int count;
};

extern char* D_004A28A8;
extern float D_00504FB8[];

static inline int texOf(sHudSprite* s)
{
    return s->tex;
}

static inline void setTex(sHudSprite* s)
{
    *(short*)(D_004A289C->e84 + 0x10) = texOf(s);
}

static inline void setUV(sHudVertex* v, sHudSprite* s)
{
    v[0].u = s->u0;
    v[0].v = s->v0;
    v[1].u = s->u1;
    v[1].v = s->v0;
    v[2].u = s->u0;
    v[2].v = s->v1;
    v[3].u = s->u1;
    v[3].v = s->v1;
}

static inline void setUVFlip(sHudVertex* v, sHudSprite* s)
{
    v[0].u = s->u1;
    v[0].v = s->v0;
    v[1].u = s->u0;
    v[1].v = s->v0;
    v[2].u = s->u1;
    v[2].v = s->v1;
    v[3].u = s->u0;
    v[3].v = s->v1;
}

static inline void setPos(sHudVertex* v, float x0, float y0, float x1, float y1)
{
    v[0].pos.x = x0;
    v[0].pos.y = y0;
    v[1].pos.x = x1;
    v[1].pos.y = y0;
    v[2].pos.x = x0;
    v[2].pos.y = y1;
    v[3].pos.x = x1;
    v[3].pos.y = y1;
}

static inline void drawQuad(sHudVertex* v)
{
    char* ctx = (char*)D_004A289C;
    sVEntry<void(void*, int, sHudVertex*, int)>* vt = *(sVEntry<void(void*, int, sHudVertex*, int)>**)(ctx + 0x10D8);
    vt[71].fn(ctx + vt[71].delta, 4, v, 0);
}

// Declarations shared by the functions of this unit.
extern "C" void* func_0039E2A0(void *, int);
extern char D_00474E08[];
extern unsigned short D_004A2088[];
extern "C" void func_0039E390(void *, int);
extern char D_00474248[];
extern int D_004A275C;
extern char D_00474160[];
int GetHashValue32(char*);
extern char D_0046E340[];
extern char D_00473B78[];
extern "C" void func_001E91F8(void*, void*);
extern "C" void func_001E9220(void*, void*, int);
void func_001E9290(void*, void*);
extern "C" void func_001F10F8(void*, void*, void*, void*, void*, int, int, int);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
void func_001E91A8(void*, void*);
extern "C" void func_001E95A0(void*, void*, void*, void*, int, int);
extern "C" void func_001F1190(void*, int, void*, void*, void*, void*);
extern "C" int sprintf(char*, const char*, ...);
extern char D_0046D0D0[];
extern char D_00473688[];
extern char D_004735B0[];
extern char D_004733F8[];
extern char D_00473320[];
extern char D_00473248[];
extern char D_00473170[];
extern char D_00473098[];
extern char D_00472FC0[];
extern char D_00472EE8[];
extern char D_00472E10[];
extern char D_00472D38[];
extern char D_00472C60[];
extern char D_00472AB0[];
extern "C" void func_001D5428(void*, int);
extern char D_00472928[];
extern "C" void* func_001D53B0(void* self, int a1, int a2);
extern char D_00472440[];
extern char D_004722B8[];
extern char D_004721E0[];
extern char D_00471F80[];
extern char D_00471EA8[];
extern char D_00479780[];

INCLUDE_ASM("fe/all_in_one_fe", __sti__all_in_one_fe_cpp);

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C640);
#ifdef SKIP_ASM
extern "C" void* func_0021C640(void *self) {
    func_0039E2A0(self, 0);
    *(char**)((char*)self + 8) = D_00474E08;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C678);
#ifdef SKIP_ASM
extern "C" void *func_0021C678(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C6D8);
#ifdef SKIP_ASM
extern "C" void func_0021C6D8(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C700);
#ifdef SKIP_ASM
extern "C" int func_0021C700(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x4C)));
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C708);
#ifdef SKIP_ASM
extern "C" void func_0021C708(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C730);
#ifdef SKIP_ASM
extern char D_00474D30[];

extern "C" void *func_0021C730(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474D30;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C798);
#ifdef SKIP_ASM
extern "C" void func_0021C798(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C7C0);
#ifdef SKIP_ASM
extern char D_00474C58[];

extern "C" void *func_0021C7C0(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474C58;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C828);
#ifdef SKIP_ASM
extern "C" void func_0020E900(void* self);

extern "C" void func_0021C828(void* self) {
    func_0020E900(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C848);
#ifdef SKIP_ASM
extern "C" void func_0021C848(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C870);
#ifdef SKIP_ASM
extern "C" void func_0021C870(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C898);
#ifdef SKIP_ASM
extern char D_00474AA8[];

extern "C" void *func_0021C898(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474AA8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C900);
#ifdef SKIP_ASM
extern "C" void func_0021C900(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C928);
#ifdef SKIP_ASM
extern "C" void func_0021C928(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C950);
#ifdef SKIP_ASM
extern char D_004748F8[];

extern "C" void *func_0021C950(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004748F8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0x9C))) = 1;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C9C0);
#ifdef SKIP_ASM
extern "C" void func_0021C9C0(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C9E8);
#ifdef SKIP_ASM
extern "C" void func_0021C9E8(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA10);
#ifdef SKIP_ASM
extern "C" void func_0021CA10(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA38);
#ifdef SKIP_ASM
extern "C" void func_0021CA38(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA60);
#ifdef SKIP_ASM
extern "C" void func_0021CA60(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA88);
#ifdef SKIP_ASM
extern "C" void func_0021CA88(void *self, int flags) {
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CAA8);
#ifdef SKIP_ASM
extern char D_004743F0[];
extern "C" void* func_0021CAA8(void *self, int a1) {
    func_0039E2A0(self, a1);
    *(char**)((char*)self + 8) = D_004743F0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CAE0);
#ifdef SKIP_ASM
extern "C" void func_0021CAE0(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB08);
#ifdef SKIP_ASM
extern "C" void* func_0021CB08(void *self) {
    func_0039E2A0(self, 0);
    *(char**)((char*)self + 8) = D_00474248;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB40);
#ifdef SKIP_ASM
extern "C" void func_0021CB40(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474248;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB68);
#ifdef SKIP_ASM
extern "C" int func_0021CB68(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB70);
#ifdef SKIP_ASM
extern "C" void func_0021CB70(int *p) {
    p[0]=1;
    p[1]=0;
    p[2]=0;
    p[3]=0;
    p[4]=0;
    p[5]=0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB90);
#ifdef SKIP_ASM
extern "C" void func_0021CB90(int arg0) {
    D_004A275C = arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB98);
#ifdef SKIP_ASM
extern "C" int func_0021CB98(void) {
    return D_004A275C;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CBA0);
#ifdef SKIP_ASM
extern "C" void* func_0020EAA0(void*);
struct sElem_CBA0 {
    void* operator new[](unsigned int, void* p) { return p; }
    char pad[8];
    char sub[0x84];
    sElem_CBA0() { func_0020EAA0(sub); }
};

extern "C" void *func_0021CBA0(void *arg0) {
    char* self = (char*)arg0;
    func_0039E2A0(self, 0);
    *(char**)(self + 8) = D_00474160;
    new (self + 0x48) sElem_CBA0[2];
    *(int*)(self + 0x474) = -1;
    *(float*)(self + 0x478) = 1.0f;
    *(float*)(self + 0x47C) = 1.0f;
    *(int*)(self + 0x480) = 0;
    *(int*)(self + 0x484) = 0;
    *(float*)(self + 0x488) = 1.0f;
    *(float*)(self + 0x48C) = 1.0f;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CC40);
#ifdef SKIP_ASM
extern "C" void func_0020EB08(void *, int);

extern "C" void func_0021CC40(void *arg0, int arg1) {
    (*(char **)((char*)(arg0) + (8))) = D_00474160;
    if ((char*)arg0 + 0x48 != 0) {
        char *p = (char*)arg0 + 0x48 + 0x118;
        while ((char*)arg0 + 0x48 != p) {
            p -= 0x8C;
            func_0020EB08(p + 8, 2);
        }
    }
    func_0039E390(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CCC8);
#ifdef SKIP_ASM
extern "C" unsigned char *func_0021CCC8(unsigned char *arg0) {
    *arg0 &= 0xF0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CCE0);
#ifdef SKIP_ASM
extern "C" void func_0021CCE0(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CD08);
#ifdef SKIP_ASM
extern char D_00474088[];

extern "C" void *func_0021CD08(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474088;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CD70);
#ifdef SKIP_ASM
extern "C" void func_0021CD70(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CD98);
#ifdef SKIP_ASM
extern char D_00473FB0[];

extern "C" void *func_0021CD98(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473FB0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CE00);
#ifdef SKIP_ASM
extern "C" void func_0021CE00(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CE28);
#ifdef SKIP_ASM
extern char D_00473ED8[];

extern "C" void *func_0021CE28(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473ED8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CE90);
#ifdef SKIP_ASM
extern "C" void func_0021CE90(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CEB8);
#ifdef SKIP_ASM
extern char D_00473E00[];

extern "C" void *func_0021CEB8(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xA0))) = 1;
    (*(char **)((char*)(arg0) + (8))) = D_00473E00;
    (*(int *)((char*)(arg0) + (0xC))) = GetHashValue32(D_0046E340);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CF38);
#ifdef SKIP_ASM
extern "C" void func_0021CF38(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CF60);
#ifdef SKIP_ASM
extern char D_00473D28[];

extern "C" void *func_0021CF60(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xA0))) = 1;
    (*(char **)((char*)(arg0) + (8))) = D_00473D28;
    (*(int *)((char*)(arg0) + (0xC))) = GetHashValue32(D_0046E340);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CFE0);
#ifdef SKIP_ASM
extern "C" void func_0021CFE0(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D008);
#ifdef SKIP_ASM
extern char D_00473C50[];

extern "C" void *func_0021D008(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473C50;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D070);
#ifdef SKIP_ASM
extern "C" void *func_0021D070(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473B78;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D0D0);
#ifdef SKIP_ASM
extern "C" void *func_0021D0D0(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473B78;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D138);
#ifdef SKIP_ASM
extern "C" void func_0021D138(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D160);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
#define func_0021D160_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern "C" void func_00391C48(int, int, char*);

extern "C" void func_0021D160(float x, float y, int c, int d, ...) {
    char* ap;
    func_0021D160_va_start(ap);
    func_00391C48(c, d, ap);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D1A0);
#ifdef SKIP_ASM
// Vertical gauge from three sprites (cap, repeated middle, base), filled from the bottom by `fill`.
extern "C" void func_0021D1A0(float fill, float sx, float sy, char* self, char* elems, signed char sel, int idx,
                              sGaugeBar* bar, float* col, int x, float* rect)
{
    t2Vector a;
    t2Vector p;
    t2Vector size;
    t2Vector sc;
    t2Vector one;
    sHudSprite** sprites = (sHudSprite**)(self + (idx * 0xC + 0x4FC));
    char* e = elems + sel * 0x24;
    func_001E91F8(e, &a);
    func_001E9220(e, &size, 0);
    func_001E9290(e, &sc);
    sc.x *= sx;
    sc.y *= sy;
    size.x *= sc.x;
    size.y *= sc.y;
    sc.y *= bar->scale;
    one.x = 1.0f;
    one.y = 1.0f;
    func_001F10F8(self, &p, &a, &size, &one, e[0x20], e[0x21], x);
    int* w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((e[0x22] << 5) & 0x3E0);
    sHudVertex vtx[4];
    sHudVertex* verts = vtx;
    for (int i = 0; i < 4; i++) {
        int r = (int)(col[0] * 128.0f);
        int g = (int)(col[1] * 128.0f);
        int b = (int)(col[2] * 128.0f);
        int a = (int)(col[3] * 128.0f);
        vtx[i].r = r;
        vtx[i].g = g;
        vtx[i].b = b;
        vtx[i].a = a;
        vtx[i].q = 1.0f;
        vtx[i].pos.setZW(0.0f, 1.0f);
    }
    if (fill == 1.0f) {
        if (rect != 0) {
            rect[0] = p.x;
            rect[1] = p.y;
            rect[2] = size.x;
            rect[3] = size.y;
        }
        p.y += size.y;
        {
            sHudSprite* s = sprites[2];
            setTex(s);
            float h = sc.y * 23.0f;
            setUV(vtx, s);
            setPos(vtx, p.x, p.y - h, p.x + size.x, p.y);
            drawQuad(verts);
            p.y -= h;
        }
        {
            sHudSprite* s = sprites[1];
            setTex(s);
            float h = sc.y * 23.0f;
            setUV(vtx, s);
            for (int i = 0; i < bar->count; i++) {
                setPos(vtx, p.x, p.y - h, p.x + size.x, p.y);
                drawQuad(verts);
                p.y -= h;
            }
        }
        {
            sHudSprite* s = sprites[0];
            setTex(s);
            setUV(vtx, s);
            setPos(vtx, p.x, p.y - sc.y * 31.0f, p.x + size.x, p.y);
            drawQuad(verts);
        }
    } else {
        float bottom = p.y + size.y;
        float top = p.y + size.y * (1.0f - fill);
        if (rect != 0) {
            rect[0] = p.x;
            rect[3] = bottom - top;
            rect[2] = size.x;
            rect[1] = top;
        }
        {
            sHudSprite* s = sprites[2];
            float h = sc.y * 23.0f;
            float y = bottom - h;
            float tv = s->v0;
            int clipped = y <= top;
            if (clipped) {
                tv = tv + (s->v1 - tv) * (top - y) / h;
                y = top;
            }
            setTex(s);
            vtx[0].u = s->u0;
            vtx[0].v = tv;
            vtx[1].u = s->u1;
            vtx[1].v = tv;
            vtx[2].u = s->u0;
            vtx[2].v = s->v1;
            vtx[3].u = s->u1;
            vtx[3].v = s->v1;
            setPos(vtx, p.x, y, p.x + size.x, bottom);
            drawQuad(verts);
            bottom = y;
            if (clipped)
                return;
        }
        {
            sHudSprite* s = sprites[1];
            float h = sc.y * 23.0f;
            setTex(s);
            setUV(vtx, s);
            for (int i = 0; i < bar->count; i++) {
                float y = bottom - h;
                int last = y <= top;
                if (last) {
                    float tv = s->v0 + (s->v1 - s->v0) * (top - y) / h;
                    vtx[0].v = tv;
                    vtx[1].v = tv;
                    y = top;
                }
                setPos(vtx, p.x, y, p.x + size.x, bottom);
                drawQuad(verts);
                bottom = y;
                if (last)
                    return;
            }
        }
        {
            sHudSprite* s = sprites[0];
            float h = sc.y * 31.0f;
            float y = bottom - h;
            float tv = s->v0;
            int clipped = y <= top;
            if (clipped) {
                tv = tv + (s->v1 - tv) * (top - y) / h;
                y = top;
            }
            setTex(s);
            vtx[0].u = s->u0;
            vtx[0].v = tv;
            vtx[1].u = s->u1;
            vtx[1].v = tv;
            vtx[2].u = s->u0;
            vtx[2].v = s->v1;
            vtx[3].u = s->u1;
            vtx[3].v = s->v1;
            setPos(vtx, p.x, y, p.x + size.x, bottom);
            drawQuad(verts);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D9A0);
#ifdef SKIP_ASM
struct sPlayerHud_D9A0 {
    char pad[0x48];
    int rider;              // 0x48
    char pad4C[0x8C - 0x4C];
};
struct sHudRoot_D9A0 {
    sPlayerHud_D9A0 players[2];     // 0x0
    char pad118[0x494 - 0x118];
    sHudSprite* sprites[0x20];    // 0x494
};
extern int D_004A4E98;
extern float D_004A5B28;
extern float D_004A5B2C;
extern sColour D_004C8668;
extern "C" int func_00147618(void* iface, int a1);
extern "C" void func_001F1338(void* self, void* pos, void* size, void* scale, void* col);

// Horizontal gauge: cap icon, start piece, middle, end piece, then the fill bar on top.
extern "C" void func_0021D9A0(float fill, float alpha, char* self, char* elems, sGaugeBar* bar, int idx,
                              int icon, float* scale)
{
    int alt = func_00147618(cBE_getInterface_Fv(cBE_getBE(), 1), ((sHudRoot_D9A0*)self)->players[idx].rider);
    t2Vector a;
    t2Vector sc;
    sVtxPos t;     // icon colour first, then reused for the bar size
    t2Vector pos;
    t2Vector p;
    t2Vector v;
    if (icon != 0) {
        char* ie = elems + 0x7BC;
        func_001E91F8(ie, &a);
        func_001E9290(ie, &sc);
        func_001E91A8(ie, &t);
        if (alt == 0) {
            pos = a;
            func_001E95A0(self + 0x6AC, &pos, &sc, &t, elems[0x7DC], elems[0x7DD]);
        } else {
            pos = a;
            func_001E95A0(self + 0x7F8, &pos, &sc, &t, elems[0x7DC], elems[0x7DD]);
        }
    }
    char* e = elems + 0x798;
    func_001E91F8(e, &a);
    func_001E9220(e, &t, 0);
    func_001E9290(e, &sc);
    sc.x *= scale[0];
    sc.y *= scale[1];
    t.x *= sc.x;
    t.y *= sc.y;
    v.x = 1.0f;
    v.y = 1.0f;
    func_001F10F8(self, &p, &a, &t, &v, elems[0x7B8], elems[0x7B9], idx);
    int* w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((elems[0x7BA] << 5) & 0x3E0);
    sHudVertex vtx[4];
    sHudVertex* verts = vtx;
    for (int i = 0; i < 4; i++) {
        int r = (int)(alpha * 128.0f);
        vtx[i].r = r;
        vtx[i].g = 0x80;
        vtx[i].b = 0x80;
        vtx[i].a = 0x80;
        vtx[i].q = 1.0f;
    }
    {
        sHudSprite* s = ((sHudRoot_D9A0*)self)->sprites[alt == 0 ? 0x12 : 0x13];
        v.x = sc.x * 20.0f;
        v.y = sc.y * 20.0f;
        t2Vector c;
        c.x = p.x;
        c.y = p.y + (t.y - v.y) * 0.5f;
        setTex(s);
        setUV(vtx, s);
        vtx[0].pos = sVtxPos(c.x, c.y, 0.0f, 1.0f);
        vtx[1].pos = sVtxPos(c.x + v.x, c.y, 0.0f, 1.0f);
        vtx[2].pos = sVtxPos(c.x, c.y + v.y, 0.0f, 1.0f);
        vtx[3].pos = sVtxPos(c.x + v.x, c.y + v.y, 0.0f, 1.0f);
        drawQuad(verts);
    }
    float d = v.x + sc.x * 3.0f;
    p.x += d;
    t.x -= d;
    v = p;
    float segW = sc.x * (bar->scale * 9.0f);
    {
        sHudSprite* s = ((sHudRoot_D9A0*)self)->sprites[0x10];
        setTex(s);
        setUV(vtx, s);
        vtx[0].pos = sVtxPos(p.x, p.y, 0.0f, 1.0f);
        vtx[1].pos = sVtxPos(p.x + segW, p.y, 0.0f, 1.0f);
        vtx[2].pos = sVtxPos(p.x, p.y + t.y, 0.0f, 1.0f);
        vtx[3].pos = sVtxPos(p.x + segW, p.y + t.y, 0.0f, 1.0f);
        drawQuad(verts);
        p.x += segW;
    }
    if (bar->count > 0) {
        sHudSprite* s = ((sHudRoot_D9A0*)self)->sprites[0x11];
        setTex(s);
        float midW = t.x - (segW + segW);
        setUV(vtx, s);
        vtx[0].pos = sVtxPos(p.x, p.y, 0.0f, 1.0f);
        vtx[1].pos = sVtxPos(p.x + midW, p.y, 0.0f, 1.0f);
        vtx[2].pos = sVtxPos(p.x, p.y + t.y, 0.0f, 1.0f);
        vtx[3].pos = sVtxPos(p.x + midW, p.y + t.y, 0.0f, 1.0f);
        drawQuad(verts);
        p.x += midW;
    }
    {
        sHudSprite* s = ((sHudRoot_D9A0*)self)->sprites[0x10];
        setTex(s);
        setUVFlip(vtx, s);
        vtx[0].pos = sVtxPos(p.x, p.y, 0.0f, 1.0f);
        vtx[1].pos = sVtxPos(p.x + segW, p.y, 0.0f, 1.0f);
        vtx[2].pos = sVtxPos(p.x, p.y + t.y, 0.0f, 1.0f);
        vtx[3].pos = sVtxPos(p.x + segW, p.y + t.y, 0.0f, 1.0f);
        drawQuad(verts);
        p.x += segW;
    }
    if (fill <= 0.0f)
        return;
    {
        if (D_004A4E98 == 0) {
            D_004A4E98 = 1;
            D_004A5B28 = 3.0f;
            D_004A5B2C = 3.0f;
        }
        t2Vector m;
        m.x = D_004A5B28 * sc.x;
        m.y = D_004A5B2C * sc.y;
        t2Vector fs;
        fs.x = (t.x - (m.x + m.x)) * fill;
        fs.y = t.y - (m.y + m.y);
        sColour col = D_004C8668;
        col.r *= alpha;
        v.x += m.x;
        v.y += m.y;
        int* w2 = (int*)(D_004A289C->e84 + 8);
        *w2 = (*w2 & ~0x3E0) | (((elems[0x7BA] + 1) << 5) & 0x3E0);
        t2Vector one;
        one.x = 1.0f;
        one.y = 1.0f;
        func_001F1338(self, &v, &fs, &one, &col);
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E1B0);
#ifdef SKIP_ASM
extern char D_00477F30[];
extern int D_00535BF8[];
extern "C" void func_0021E7E0_E1B0(char* self, sColour* colp, t2Vector* pos, t2Vector* size,
                                   float t, float sx, float sy, float amin, float amax) __asm__("func_0021E7E0");

extern "C" void func_0021E1B0(char* self, char* obj, int* rider, int x)
{
    t2Vector scale;
    sColour col;
    t2Vector sc;
    sFloat4 a;
    t2Vector size1;
    t2Vector size2;
    t2Vector dim;
    t2Vector p;
    sColour c2;
    t2Vector size3;
    t2Vector tmp;
    t2Vector pa;
    t2Vector sa;
    t2Vector sb;
    scale.x = 1.0f;
    scale.y = 1.0f;
    float k = 1.0f;
    char* r = *(char**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + (rider[0] << 2) + 0x28);
    func_001E91A8(D_00477F30 + *(int*)(r + 0xEC) * 0x24, &col);
    float t = ((float*)rider)[0x12];
    if (t >= 0.0f) {
        if (*(int*)(r + 0xEC) == 0) {
            k = D_00504FB8[(int)(t * 12.566370964050293f * 81.4873275756836f) & 0x1FF] * 0.199636310338974f * (1.0f - t * t) + k;
        } else {
            col.r = col.r * (t * 0.5f + 0.5f);
        }
    }
    func_001E9290(obj + 0x360, &sc);
    int* tex = (int*)(self + 0x444);
    func_001E91F8(obj + 0x360, &a);
    func_001E9220(D_00477F30 + 0xD8, &size1, 0);
    size1.x *= sc.x;
    size1.y *= sc.y;
    int off = *(int*)(r + 0xEC) << 2;
    func_001E9220(D_00477F30 + *(int*)(r + 0xEC) * 0x24, &size2, *(int*)((char*)tex + off));
    size2.x *= sc.x;
    size2.y *= sc.y;
    dim.x = size2.x + size1.x;
    dim.y = size2.y;
    func_001F10F8(self, &p, &a, &dim, &scale, obj[0x380], obj[0x381], x);
    p.x += size2.x;
    p.y += size1.y;
    int* w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((obj[0x382] << 5) & 0x3E0);
    func_001E91A8(D_00477F30 + 0xFC, &c2);
    func_001E9220(D_00477F30 + 0xFC, &size3, 0);
    size3.x *= sc.x;
    size3.y *= sc.y;
    func_001F1190(self, *(int*)(self + 0x46C), &p, &size3, &scale, &c2);
    p.x += size3.x;
    func_001E91A8(D_00477F30 + 0x120, &c2);
    func_001E9220(D_00477F30 + 0x120, &size3, 0);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    int off3 = (D_00535BF8[0] - 1) << 2;
    func_001F1190(self, *(int*)((char*)tex + off3), &p, &size3, &sc, &c2);
    if (k != 1.0f) {
        size2.x *= k;
        size2.y *= k;
        size1.x *= k;
        size1.y *= k;
        dim.x *= k;
        dim.y *= k;
    }
    func_001F10F8(self, &p, &a, &dim, &scale, obj[0x380], obj[0x381], x);
    w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((obj[0x382] << 5) & 0x3E0);
    int off4 = *(int*)(r + 0xEC) << 2;
    func_001F1190(self, *(int*)((char*)tex + off4), &p, &size2, &scale, &col);
    signed char n = *(int*)(r + 0xEC) < 4 ? *(int*)(r + 0xEC) : 3;
    tmp = p;
    int off5 = n * 4;
    int tx = *(int*)(self + off5 + 0x45C);
    tmp.x += size2.x;
    func_001F1190(self, tx, &tmp, &size1, &scale, &col);
    if (((float*)rider)[0x13] >= 0.0f) {
        w = (int*)(D_004A289C->e84 + 8);
        *w = (*w & ~0x3E0) | (((obj[0x382] - 1) << 5) & 0x3E0);
        pa = p;
        sa = size2;
        func_0021E7E0_E1B0(self, &col, &pa, &sa, ((float*)rider)[0x13], 1.8101750612258911f, 1.8101750612258911f, 0.5f, 1.0f);
        pa = tmp;
        sb = size1;
        func_0021E7E0_E1B0(self, &col, &pa, &sb, ((float*)rider)[0x13], 1.8101750612258911f, 1.8101750612258911f, 0.5f, 1.0f);
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E750);
#ifdef SKIP_ASM
extern "C" float func_0021E750(int unused, int a, int flags, float x, float y, float z) {
    int v = a;
    if (flags & 1) {
        x = 640.0f - x;
        v = (flags & 2) ? a : -v;
    }
    if (v == 0) {
        x -= z * y * 0.5f;
    } else if (v > 0) {
        x -= z * y;
    }
    return x;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E7A8);
#ifdef SKIP_ASM
extern "C" float func_0021E7A8(int arg0, int mode, float a, float b, float c) {
    if (mode == 0) {
        a -= c * b * 0.5f;
    } else if (mode > 0) {
        a -= c * b;
    }
    return a;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E7E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0021EA00(void* self, sColour* col, float* pos, float w, float h, float u0, float v0, float u1, float v1);

extern "C" void func_0021E7E0(char* self, sColour* colp, float* pos, float* size,
                              float t, float sx, float sy, float amin, float amax) {
    sColour col = *colp;
    sColour* c = &col;
    float dw, dh;
    float range = amax - amin;
    c->r = c->r * (amin + (t > 1.0f ? range * (2.0f - t) : range * t));
    dw = size[0] * (sx - 1.0f);
    dh = size[1] * (sy - 1.0f);
    pos[0] -= dw * 0.5f;
    pos[1] -= dh * 0.5f;
    size[0] += dw;
    size[1] += dh;
    int id = *(int*)(self + 0x474);
    *(short*)(D_004A289C->e84 + 0x10) = id;
    if (size[0] > 72.0f) {
        float mid = (*(float*)(self + 0x484) + *(float*)(self + 0x488)) * 0.5f;
        func_0021EA00(self, c, pos, 36.0f, size[1], *(float*)(self + 0x484), *(float*)(self + 0x480), mid, *(float*)(self + 0x48C));
        pos[0] += 36.0f;
        func_0021EA00(self, c, pos, size[0] - 72.0f, size[1], mid, *(float*)(self + 0x480), mid, *(float*)(self + 0x48C));
        pos[0] += size[0] - 72.0f;
        func_0021EA00(self, c, pos, 36.0f, size[1], mid, *(float*)(self + 0x480), *(float*)(self + 0x488), *(float*)(self + 0x48C));
    } else {
        func_0021EA00(self, c, pos, size[0], size[1], *(float*)(self + 0x484), *(float*)(self + 0x480), *(float*)(self + 0x488), *(float*)(self + 0x48C));
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021EA00);
#ifdef SKIP_ASM
extern "C" void func_0021EA00(void* self, sColour* col, float* pos, float w, float h, float u0, float v0, float u1, float v1)
{
    if (h > 72.0f) {
        sHudVertex vtx[8];
        for (int i = 0; i < 8; i++) {
            int r = (int)(col->r * 128.0f);
            int g = (int)(col->g * 128.0f);
            int b = (int)(col->b * 128.0f);
            int a = (int)(col->a * 128.0f);
            vtx[i].r = r;
            vtx[i].g = g;
            vtx[i].b = b;
            vtx[i].a = a;
            vtx[i].q = 1.0f;
            if (i & 1)
                vtx[i].u = u1;
            else
                vtx[i].u = u0;
        }
        vtx[0].v = v0;
        vtx[1].v = v0;
        vtx[2].v = (v0 + v1) * 0.5f;
        vtx[3].v = (v0 + v1) * 0.5f;
        vtx[4].v = (v0 + v1) * 0.5f;
        vtx[5].v = (v0 + v1) * 0.5f;
        vtx[6].v = v1;
        vtx[7].v = v1;
        vtx[0].pos = sVtxPos(pos[0], pos[1], 0.0f, 1.0f);
        vtx[1].pos = sVtxPos(pos[0] + w, pos[1], 0.0f, 1.0f);
        vtx[2].pos = sVtxPos(pos[0], pos[1] + 36.0f, 0.0f, 1.0f);
        vtx[3].pos = sVtxPos(pos[0] + w, pos[1] + 36.0f, 0.0f, 1.0f);
        vtx[4].pos = sVtxPos(pos[0], pos[1] + h - 36.0f, 0.0f, 1.0f);
        vtx[5].pos = sVtxPos(pos[0] + w, pos[1] + h - 36.0f, 0.0f, 1.0f);
        vtx[6].pos = sVtxPos(pos[0], pos[1] + h, 0.0f, 1.0f);
        vtx[7].pos = sVtxPos(pos[0] + w, pos[1] + h, 0.0f, 1.0f);
        char* ctx = (char*)D_004A289C;
        sVEntry<void(void*, int, sHudVertex*, int)>* vt = *(sVEntry<void(void*, int, sHudVertex*, int)>**)(ctx + 0x10D8);
        vt[71].fn(ctx + vt[71].delta, 8, vtx, 0);
    } else {
        sHudVertex vtx[4];
        for (int i = 0; i < 4; i++) {
            int r = (int)(col->r * 128.0f);
            int g = (int)(col->g * 128.0f);
            int b = (int)(col->b * 128.0f);
            int a = (int)(col->a * 128.0f);
            vtx[i].r = r;
            vtx[i].g = g;
            vtx[i].b = b;
            vtx[i].a = a;
            vtx[i].q = 1.0f;
            if (i & 1)
                vtx[i].u = u1;
            else
                vtx[i].u = u0;
        }
        vtx[0].v = v0;
        vtx[1].v = v0;
        vtx[2].v = v1;
        vtx[3].v = v1;
        vtx[0].pos = sVtxPos(pos[0], pos[1], 0.0f, 1.0f);
        vtx[1].pos = sVtxPos(pos[0] + w, pos[1], 0.0f, 1.0f);
        vtx[2].pos = sVtxPos(pos[0], pos[1] + h, 0.0f, 1.0f);
        vtx[3].pos = sVtxPos(pos[0] + w, pos[1] + h, 0.0f, 1.0f);
        char* ctx = (char*)D_004A289C;
        sVEntry<void(void*, int, sHudVertex*, int)>* vt = *(sVEntry<void(void*, int, sHudVertex*, int)>**)(ctx + 0x10D8);
        vt[71].fn(ctx + vt[71].delta, 4, vtx, 0);
    }
}
#endif

INCLUDE_ASM("fe/all_in_one_fe", func_0021ED48);

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021F338);
#ifdef SKIP_ASM
extern sColour D_004C8568;
extern sColour D_004C8588;
extern sColour D_004C85A8;
extern sColour D_004C85C8;
extern sColour D_004C85E8;

extern "C" void func_0021F338(char* self, char* obj, int n, int x, t2Vector* pos, t2Vector* scale, float alpha) {
    if (n > 0) {
        sColour cols[5];
        sFloat4 a;
        t2Vector p;
        t2Vector size;
        t2Vector sc;
        t2Vector dim;
        sColour col;
        float step;
        int i;
        cols[0] = D_004C8568;
        cols[1] = D_004C8588;
        cols[2] = D_004C85A8;
        cols[3] = D_004C85C8;
        cols[4] = D_004C85E8;
        func_001E91F8(obj + 0x240, &a);
        func_001E9220(obj + 0x240, &size, *(int*)(self + 0x4A0));
        func_001E9290(obj + 0x240, &sc);
        if (scale) {
            sc.x *= scale->x;
            sc.y *= scale->y;
        }
        if (pos == 0) {
            dim.x = size.x * n + (n - 1) * 2.0f;
            dim.y = size.y;
            func_001F10F8(self, &p, &a, &dim, &sc, obj[0x260], obj[0x261], x);
        } else {
            p = *pos;
            p.x -= (size.x * n + (n - 1) * 2.0f) * sc.x * 0.5f;
            p.y -= size.y * sc.y * 0.5f;
        }
        int* w = (int*)(D_004A289C->e84 + 8);
        *w = (*w & ~0x3E0) | ((obj[0x262] << 5) & 0x3E0);
        step = (size.x + 2.0f) * sc.x;
        col = cols[n - 1];
        col.r *= alpha;
        for (i = 0; i < n; i++) {
            func_001F1190(self, *(int*)(self + 0x4A0), &p, &size, &sc, &col);
            p.x += step;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021F660);
#ifdef SKIP_ASM
extern signed char D_00535C10[];
extern int D_00536640[];
extern char D_0046ED68[];
extern char D_004A2138[];
extern sColour D_004C8808;
extern "C" void func_00392908(void*, float, float, char*);

extern "C" void func_0021F660(char* self, int elems, int* rider, int x, int flag) {
    t2Vector scale;
    t2Vector p;
    sFloat4 a;
    t2Vector size;
    t2Vector sc;
    sColour c;
    char buf[64];
    sColour col;
    int idx = 0x42;
    char* r = *(char**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + (*rider << 2) + 0x28);
    int sz = *(int*)(self + 0x4B4);
    if (flag) {
        sz = *(int*)(self + 0x49C);
        idx = 0x1B;
    }
    char* e = (char*)(idx * 0x24 + elems); // PORT: pointer passed as int
    scale.x = 1.0f;
    scale.y = 1.0f;
    func_001E91F8(e, &a);
    func_001E9220(e, &size, sz);
    func_001E9290(e, &sc);
    size.x *= sc.x;
    size.y *= sc.y;
    func_001F10F8(self, &p, &a, &size, &scale, e[0x20], e[0x21], x);
    func_001E91A8(e, &c);
    int* w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((e[0x22] << 5) & 0x3E0);
    func_001F1190(self, sz, &p, &size, &scale, &c);
    if (flag == 0) {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        signed char mode = D_00535C10[0];
        cBeing* o = (cBeing*)(r + 0x6C0);
        int k = o->getAIIndex();
        int val = D_00536640[k];
        if (mode == 0 || mode == 5) {
            int t = (int)((float)val * 0.01666666753590107f);
            int rem = t % 3600;
            sprintf(buf, D_0046ED68, t / 3600, rem / 60, rem % 60);
        } else {
            sprintf(buf, D_004A2138, val + rider[0x7C / 4]);
        }
        char* t = *(char**)(self + 0x42C);
        p.x += size.x * 0.5f;
        p.y += size.y;
        sc.x *= 1.907578468322754f;
        sc.y *= 1.907578468322754f;
        *(float*)(t + 0x38) = *(float*)(t + 0x30) * sc.x;
        *(float*)(t + 0x3C) = *(float*)(t + 0x34) * sc.y;
        col = D_004C8808;
        *(sColour*)(*(char**)(self + 0x42C) + 0x40) = col;
        func_00392908(*(char**)(self + 0x42C), p.x, p.y, buf);
        t = *(char**)(self + 0x42C);
        *(float*)(t + 0x38) = *(float*)(t + 0x30) * scale.x;
        *(float*)(t + 0x3C) = *(float*)(t + 0x34) * scale.y;
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021F9B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern sColour D_004C8648;
extern char D_004A2300[];
extern "C" int func_0022D390(void*, int);
extern "C" int func_00153520(void*, int, int);
extern "C" int func_00153350(void*, int);
extern "C" void func_00391CB0(void*, float, float, char*);

extern "C" void func_0021F9B0(char* self, char* obj, char* rider, int x, float t) {
    t2Vector scale;
    t2Vector p;
    sFloat4 a;
    t2Vector size;
    t2Vector sc;
    sColour col;
    char buf[64];
    char* m = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x78);
    int id = *(int*)(m + 0x1BC);
    if (func_0022D390(m, id)) {
        float s = 1.0f;
        scale.x = 1.0f;
        scale.y = 1.0f;
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 10);
        if (t < 0.4399542808532715f) {
            float u = t * 2.272963523864746f;
            s = D_00504FB8[(int)(u * 12.566370964050293f * 81.4873275756836f) & 0x1FF] * 0.19996199011802673f * (1.0f - u * u) + 1.0f;
        }
        func_001E91F8(obj + 0x804, &a);
        func_001E9220(obj + 0x804, &size, *(int*)(self + 0x4A8));
        func_001E9290(obj + 0x804, &sc);
        size.x *= s;
        size.y *= s;
        sc.x *= s;
        sc.y *= s;
        func_001F10F8(self, &p, &a, &size, &scale, obj[0x824], obj[0x825], x);
        int* w = (int*)(D_004A289C->e84 + 8);
        *w = (*w & ~0x3E0) | ((obj[0x826] << 5) & 0x3E0);
        col.r = 1.0f;
        col.g = 1.0f;
        col.b = 1.0f;
        col.a = 1.0f;
        func_001F1190(self, *(int*)(self + 0x4A8), &p, &size, &scale, &col);
        char* tx = *(char**)(self + 0x42C);
        p.x += size.x;
        p.y += (size.y - (float)*(int*)(tx + 0x14) * *(float*)(tx + 0x34) * sc.y) * 0.5f;
        if (t > 0.4399542808532715f) {
            func_001E91A8(obj + 0x804, &col);
        } else {
            col = D_004C8648;
        }
        char* tx2 = *(char**)(self + 0x42C);
        *(float*)(tx2 + 0x38) = *(float*)(tx2 + 0x30) * sc.x;
        *(float*)(tx2 + 0x3C) = *(float*)(tx2 + 0x34) * sc.y;
        *(sColour*)(*(char**)(self + 0x42C) + 0x40) = col;
        cBeing* o = (cBeing*)(rider + 0x6C0);
        sprintf(buf, D_004A2300, func_00153520(iface, o->getAIIndex(), id), func_00153350(iface, id));
        func_00391CB0(*(char**)(self + 0x42C), p.x, p.y, buf);
        tx = *(char**)(self + 0x42C);
        *(float*)(tx + 0x38) = *(float*)(tx + 0x30) * scale.x;
        *(float*)(tx + 0x3C) = *(float*)(tx + 0x34) * scale.y;
    }
}
#endif

INCLUDE_ASM("fe/all_in_one_fe", func_0021FD38);

INCLUDE_ASM("fe/all_in_one_fe", func_002200C0);

INCLUDE_ASM("fe/all_in_one_fe", func_002204A0);

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220AD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Big_0AD0 { unsigned int pad0 : 20; unsigned int mode : 2; unsigned int pad1 : 10; int rest[0xA1]; };
struct Bits_0AD0 { int a, b; unsigned int lo : 5; int v : 5; unsigned int hi : 22; };
struct Glob_0AD0 { char pad[0x504]; int f504; };
extern Big_0AD0 D_00535610;
extern Glob_0AD0* D_004A28A4;

extern "C" void func_00220AD0(char* self, char* obj, float t) {
    t2Vector a;
    sFloat4 b;
    Big_0AD0 big;
    sColour c;
    t2Vector d;
    t2Vector e;
    void* p = obj + 0xAD4;
    func_001E91F8(p, &a);
    func_001E9290(p, &b);
    cBE_getInterface_Fv(cBE_getBE(), 4);
    big = D_00535610;
    if (D_004A28A4->f504 != 0 && big.mode != 2) {
        b.y *= 0.75f;
        a.y -= 60.0f;
    }
    func_001E91A8(obj + 0xAD4, &c);
    if (t <= 0.5f) {
        c.r *= t * 2.0f;
    } else {
        c.r *= (1.0f - t) * 2.0f;
    }
    d.x = 2.0f;
    d.y = 2.0f;
    *(t2Vector*)(*(char**)(self + 0xB50) + 0x28) = d;
    int* w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((obj[0xAF6] << 5) & 0x3E0);
    e = a;
    func_001E95A0(self + 0xB48, &e, &b, &c, obj[0xAF4], obj[0xAF5]);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220D38);
#ifdef SKIP_ASM
extern char D_00473AA8[];
extern "C" void* func_00220D38(void *self) {
    func_0039E2A0(self, 0);
    *(char**)((char*)self + 8) = D_00473AA8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220D70);
#ifdef SKIP_ASM
extern "C" void func_00220D70(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220D98);
#ifdef SKIP_ASM
extern char D_004739D8[];
extern "C" void* func_00220D98(void *self) {
    func_0039E2A0(self, 0);
    *(char**)((char*)self + 8) = D_004739D8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220DD0);
#ifdef SKIP_ASM
extern "C" void func_00220DD0(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220DF8);
#ifdef SKIP_ASM
extern char D_00473908[];
extern "C" void* func_00220DF8(void *self) {
    func_0039E2A0(self, 0);
    *(char**)((char*)self + 8) = D_00473908;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220E30);
#ifdef SKIP_ASM
extern "C" void func_00220E30(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220E58);
#ifdef SKIP_ASM
extern char D_00473838[];

extern "C" void *func_00220E58(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00473838;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220E90);
#ifdef SKIP_ASM
extern "C" void func_00220E90(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220EB8);
#ifdef SKIP_ASM
extern "C" void func_00220EB8(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220EE0);
#ifdef SKIP_ASM
extern char D_00473760[];

extern "C" void *func_00220EE0(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473760;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220F48);
#ifdef SKIP_ASM
extern "C" void *func_00220F48(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473688;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220FA8);
#ifdef SKIP_ASM
extern "C" void func_001F7548(void*);

extern "C" void *func_00220FA8(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473688;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    func_001F7548(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221018);
#ifdef SKIP_ASM
extern "C" void func_00221018(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221040);
#ifdef SKIP_ASM
extern "C" void *func_00221040(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004735B0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002210A0);
#ifdef SKIP_ASM
extern "C" void func_001F7738(void*);

extern "C" void *func_002210A0(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004735B0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    func_001F7738(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221110);
#ifdef SKIP_ASM
extern "C" void func_00221110(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221138);
#ifdef SKIP_ASM
extern "C" void func_00221138(void *arg0, int flags) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390(arg0, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221160);
#ifdef SKIP_ASM
extern char D_004734D0[];

extern "C" void *func_00221160(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004734D0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002211C8);
#ifdef SKIP_ASM
extern "C" void *func_002211C8(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004733F8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221228);
#ifdef SKIP_ASM
extern "C" void func_002006B8(void*);

extern "C" void *func_00221228(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004733F8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    func_002006B8((char*)arg0 + 0x9C);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221298);
#ifdef SKIP_ASM
extern "C" void func_00221298(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

extern "C" void func_002212C0(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002212C8);
#ifdef SKIP_ASM
inline void* operator new[](unsigned int, void* p) { return p; }
struct Elem { Elem() {} };

extern "C" void *func_002212C8(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473320;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    new ((char*)arg0 + 0x9C) Elem[8];
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221350);
#ifdef SKIP_ASM
extern "C" void *func_00221350(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473320;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    new ((char*)arg0 + 0x9C) Elem[8];
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002213D8);
#ifdef SKIP_ASM
extern "C" void func_002213D8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

extern "C" void func_00221400(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221408);
#ifdef SKIP_ASM
extern "C" void *func_00221408(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473248;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221468);
#ifdef SKIP_ASM
extern "C" void *func_00221468(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473248;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002214D0);
#ifdef SKIP_ASM
extern "C" void func_002214D0(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002214F8);
#ifdef SKIP_ASM
extern "C" void *func_002214F8(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473170;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221558);
#ifdef SKIP_ASM
extern "C" void *func_00221558(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473170;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002215C8);
#ifdef SKIP_ASM
extern "C" void func_002215C8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002215F0);
#ifdef SKIP_ASM
extern "C" void *func_002215F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473098;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221658);
#ifdef SKIP_ASM
extern "C" void *func_00221658(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473098;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002216C8);
#ifdef SKIP_ASM
extern "C" void func_002216C8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002216F0);
#ifdef SKIP_ASM
extern "C" void *func_002216F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472FC0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221758);
#ifdef SKIP_ASM
extern "C" void *func_00221758(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472FC0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002217C8);
#ifdef SKIP_ASM
extern "C" void func_002217C8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002217F0);
#ifdef SKIP_ASM
extern "C" void *func_002217F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472EE8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221858);
#ifdef SKIP_ASM
extern "C" void *func_00221858(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472EE8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002218C8);
#ifdef SKIP_ASM
extern "C" void func_002218C8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002218F0);
#ifdef SKIP_ASM
extern "C" void *func_002218F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472E10;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221958);
#ifdef SKIP_ASM
extern "C" void *func_00221958(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472E10;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002219C8);
#ifdef SKIP_ASM
extern "C" void func_002219C8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002219F0);
#ifdef SKIP_ASM
extern "C" void *func_002219F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472D38;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221A58);
#ifdef SKIP_ASM
extern "C" void *func_00221A58(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472D38;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221AC8);
#ifdef SKIP_ASM
extern "C" void func_00221AC8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221AF0);
#ifdef SKIP_ASM
extern "C" void *func_00221AF0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472C60;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221B58);
#ifdef SKIP_ASM
extern "C" void *func_00221B58(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472C60;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221BC8);
#ifdef SKIP_ASM
extern "C" void func_00221BC8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221BF0);
#ifdef SKIP_ASM
extern "C" void func_00221BF0(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221C18);
#ifdef SKIP_ASM
extern char D_00472B88[];

extern "C" void *func_00221C18(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472B88;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221C80);
#ifdef SKIP_ASM
extern "C" void *func_00221C80(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472AB0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221CE0);
#ifdef SKIP_ASM
extern "C" void *func_00221CE0(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472AB0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xA0))) = 1;
    (*(int *)((char*)(arg0) + (0x9C))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221D58);
#ifdef SKIP_ASM
extern "C" void func_00221D58(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

extern "C" void func_00221D80(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221D88);
#ifdef SKIP_ASM
extern "C" void func_00221D88(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00472928;
    func_001D5428(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221DB0);
#ifdef SKIP_ASM
extern "C" void *func_00221DB0(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00472928;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221DF0);
#ifdef SKIP_ASM
extern "C" void func_00221DF0(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221E18);
#ifdef SKIP_ASM
extern char D_00472850[];

extern "C" void *func_00221E18(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472850;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221E80);
#ifdef SKIP_ASM
extern "C" void func_00221E80(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221EA8);
#ifdef SKIP_ASM
extern char D_00472778[];

extern "C" void *func_00221EA8(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472778;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221F10);
#ifdef SKIP_ASM
extern "C" void func_00221F10(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221F38);
#ifdef SKIP_ASM
extern char D_004726A0[];

extern "C" void *func_00221F38(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004726A0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221FA0);
#ifdef SKIP_ASM
extern "C" void func_00221FA0(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221FC8);
#ifdef SKIP_ASM
extern char D_004725C8[];

extern "C" void *func_00221FC8(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004725C8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222030);
#ifdef SKIP_ASM
extern "C" void func_00222030(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00472440;
    func_001D5428(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222058);
#ifdef SKIP_ASM
extern "C" void *func_00222058(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00472440;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222098);
#ifdef SKIP_ASM
extern "C" void func_00222098(void *self, int flags) {
    *(char**)((char*)self + 8) = D_004722B8;
    func_001D5428(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002220C0);
#ifdef SKIP_ASM
extern "C" void *func_002220C0(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_004722B8;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222100);
#ifdef SKIP_ASM
extern "C" void *func_00222100(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004721E0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222160);
#ifdef SKIP_ASM
extern "C" void *func_00222160(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004721E0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002221C8);
#ifdef SKIP_ASM
extern "C" void func_002221C8(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002221F0);
#ifdef SKIP_ASM
extern "C" void func_002221F0(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222218);
#ifdef SKIP_ASM
extern char D_00472108[];

extern "C" void *func_00222218(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472108;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222280);
#ifdef SKIP_ASM
extern "C" void func_00222280(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00471F80;
    func_001D5428(self, flags);
}
#endif

extern "C" void func_002222A8(void) {
}

extern "C" void func_002222B0(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002222B8);
#ifdef SKIP_ASM
extern "C" void *func_002222B8(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00471F80;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002222F8);
#ifdef SKIP_ASM
extern "C" void *func_002222F8(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00471EA8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222358);
#ifdef SKIP_ASM
extern "C" void *func_00222358(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00471EA8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002223C0);
#ifdef SKIP_ASM
extern "C" void func_002223C0(void *self, int flags) {
    *(char**)((char*)self + 8) = D_00474E08;
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002223E8);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
#define func_002223E8_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern "C" void func_003929F8(int, int, char*);

extern "C" void func_002223E8(float x, float y, int c, int d, ...) {
    char* ap;
    func_002223E8_va_start(ap);
    func_003929F8(c, d, ap);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/all_in_one_fe", func_00222428);
#ifdef SKIP_ASM
extern "C" void __sti__all_in_one_fe_cpp(int, int);

extern "C" void func_00222428(void) {
    __sti__all_in_one_fe_cpp(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222448);
#ifdef SKIP_ASM
extern unsigned short D_00441D38[];

extern "C" unsigned int func_00222448(const unsigned char *p, int n) {
    const unsigned char *end = p + n;
    unsigned int crc = 0xFBEA;
    while (p < end) {
        crc = D_00441D38[(*p++ ^ crc) & 0xFF] ^ (crc >> 8);
    }
    return crc;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002224A0);
#ifdef SKIP_ASM
extern "C" int func_002224A0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002224A8);
#ifdef SKIP_ASM
extern "C" void* func_002224A8(void* arg0) {
    return arg0;
}
#endif

extern "C" void func_002224B0(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002224B8);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

extern "C" void func_002224B8(cLunoValue** out, char** state, cLunoValue* a, int c) {
    char* s = *state;
    int n = *(int*)(s + *(int*)(s + 4) + 8);
    cLunoValue* arr = new (D_00479780, 0x20000000, 0) cLunoValue[n];
    *out = arr;
    arr[0].SetTable(a);
    cLunoValue* b = &D_004C9098;
    cLunoValue* p = *out;
    cLunoValue* q = &p[1];
    if (p[1].type == 4) func_00224DF0(q, 2);
    q->type = 0;
    p[1].u.i = 0;
    if (b->type == 4) {
        func_00225068(q, b);
    } else if (b->type == 5) {
        p[1].u.pair = b->u.pair;
    } else {
        p[1].u.i = b->u.i;
    }
    q->type = b->type;
    luno_cLunoVM_execute(out, state, c);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222648);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

extern "C" void func_00222648(cLunoValue** out, char** state, cLunoValue* a, cLunoValue* b, int c) {
    char* s = *state;
    int n = *(int*)(s + *(int*)(s + 4) + 8);
    cLunoValue* arr = new (D_00479780, 0x20000000, 0) cLunoValue[n];
    *out = arr;
    arr[0].SetTable(a);
    cLunoValue* p = *out;
    cLunoValue* q = &p[1];
    if (p[1].type == 4) func_00224DF0(q, 2);
    q->type = 0;
    p[1].u.i = 0;
    if (b->type == 4) {
        func_00225068(q, b);
    } else if (b->type == 5) {
        p[1].u.pair = b->u.pair;
    } else {
        p[1].u.i = b->u.i;
    }
    q->type = b->type;
    luno_cLunoVM_execute(out, state, c);
}
#endif
