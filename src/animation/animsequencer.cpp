#include "common.h"

struct cAnimSequence {
    char pad_0x00[0x98];
    float mCurrentWeight; // 0x98
    float mTargetWeight; // 0x9C
    float mFadeSpeed; // 0xA0
};

//100%
INCLUDE_ASM("animation/animsequencer", cAnimSequence_fadeWeight__FP13cAnimSequenceff);
#ifdef SKIP_ASM
void cAnimSequence_fadeWeight(cAnimSequence* self, float weight, float target)
{
    self->mCurrentWeight = weight;
    self->mTargetWeight = target;
    self->mFadeSpeed = 0.0f;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313A20);
#ifdef SKIP_ASM
extern "C" void func_00313A20(void* self, float v)
{
    if (*(float*)((char*)self + 0x98) != 0.0f || *(float*)((char*)self + 0x9C) == 0.0f || v < *(float*)((char*)self + 0x9C))
    {
        *(float*)((char*)self + 0x9C) = v;
    }
    *(float*)((char*)self + 0x98) = 0.0f;
    *(int*)((char*)self + 0xA0) = 1;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313A70);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0048A5B0[];

struct sSeqNode313A70
{
    int key;
    int active;
    float weight;
    sSeqNode313A70* next;
};

extern "C" void func_00313A70(void* self, int key, float weight)
{
    sSeqNode313A70* n = (sSeqNode313A70*)cMemMan_alloc(0x10, D_0048A5B0, 0x20000000, 0);
    sSeqNode313A70* old = *(sSeqNode313A70**)((char*)self + 0xAC);
    *(sSeqNode313A70**)((char*)self + 0xAC) = n;
    n->key = key;
    n->weight = weight;
    n->next = old;
    n->active = 0;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313AD8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0048A5B0[];

struct sSeqNode313AD8
{
    int key;
    int active;
    int unk8;
    sSeqNode313AD8* next;
};

extern "C" void func_00313AD8(void* self, int key)
{
    sSeqNode313AD8* n = (sSeqNode313AD8*)cMemMan_alloc(0x10, D_0048A5B0, 0x20000000, 0);
    sSeqNode313AD8* old = *(sSeqNode313AD8**)((char*)self + 0xAC);
    *(sSeqNode313AD8**)((char*)self + 0xAC) = n;
    n->key = key;
    n->active = 1;
    n->next = old;
    n->unk8 = 0;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313B38);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
struct sNode_00313B38 {
    int id;
    int refs;
    float time;
    sNode_00313B38* next;
};

extern "C" void func_00313B38(char* self, int id, float time) {
    sNode_00313B38** link;
    for (link = (sNode_00313B38**)(self + 0xAC); *link != 0; link = &(*link)->next) {
        sNode_00313B38* n = *link;
        if (n->id == id && n->time == time && n->refs == 0) {
            *link = n->next;
            operator_delete((int*)n);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313BA8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
struct sSeqNode313BA8
{
    int key;
    int active;
    int unk8;
    sSeqNode313BA8* next;
};

extern "C" void func_00313BA8(void* self, int key)
{
    sSeqNode313BA8** pp;
    for (pp = (sSeqNode313BA8**)((char*)self + 0xAC); *pp != 0; pp = &(*pp)->next)
    {
        if ((*pp)->key == key)
        {
            sSeqNode313BA8* n = *pp;
            if (n->active != 0)
            {
                *pp = n->next;
                operator_delete((int*)n);
                return;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313C08);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00313C08(char* self)
{
    while (*(char**)(self + 0xAC) != 0)
    {
        char* node = *(char**)(self + 0xAC);
        *(char**)(self + 0xAC) = *(char**)(node + 0xC);
        operator_delete((int*)node);
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313C50);
#ifdef SKIP_ASM
extern void** D_004A3DF8;

struct sSeqEntry_00313C50
{
    int anim;
    int t;
    float w;
    float len;
    float speed;
    int active;
    int f18;
};

struct sSeq_00313C50
{
    int f0;
    sSeqEntry_00313C50 e[5];
    char pad90[0xC4 - 0x90];
    int dirty;
};

extern "C" void func_00313C50(void* self, int i, int anim)
{
    sSeq_00313C50* s = (sSeq_00313C50*)self;
    (s->e + i)->anim = anim;
    char* clip = *(char**)((char*)D_004A3DF8 + ((anim & 0xFF) << 2));
    char* q = (char*)(((unsigned)anim >> 8) * 0x14 + *(int*)(clip + 0x8));
    s->e[i].len = (*(unsigned short*)(q + 0xC) - 1) * 0.03333333507180214f;
    if (s->e[i].active == 0)
    {
        s->e[i].t = 0;
        s->e[i].w = 1.0f;
        s->e[i].speed = 1.0f;
        s->e[i].active = 1;
        s->e[i].f18 = 0;
        s->dirty = 1;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313CF0);
#ifdef SKIP_ASM
extern "C" void func_00313CF0(void* self, int a1, float val)
{
    char* p = (char*)self + a1 * 0x1c;
    *(float*)(p + 0x8) = val;
    *(int*)((char*)self + 0xc4) = 1;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313D10);
#ifdef SKIP_ASM
extern "C" void func_00313D10(int arg0, int arg1, float fparg0) {
    (*(float *)((char*)(((arg1 * 0x1C) + arg0)) + (0xC))) = fparg0;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313D28);
#ifdef SKIP_ASM
extern "C" void func_00313D28(void* self, int a1, float val)
{
    char* p = (char*)self + a1 * 0x1c;
    *(float*)(p + 0x14) = val;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313D40);
#ifdef SKIP_ASM
extern "C" void func_00313D40(void* self, int a1, int val)
{
    char* p = (char*)self + a1 * 0x1c;
    *(int*)(p + 0x1c) = val;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313D58);
#ifdef SKIP_ASM
extern "C" void func_00313D58(int arg0, int arg1) {
    (*(int *)((char*)(((arg1 * 0x1C) + arg0)) + (0x18))) = 0;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313D70);
#ifdef SKIP_ASM
struct sSeqTrack_00313D70
{
    char pad0[0x8];
    float time;   // 0x8
    char pad1[0x4];
    float end;    // 0x10
    float weight; // 0x14
    int flag;     // 0x18
};

struct sSeq_00313D70
{
    sSeqTrack_00313D70 tracks[5]; // 0x0
    char pad0[0x8];
    float scale;   // 0x94
    char pad1[0xC];
    float fadeOut; // 0xA4
    float fadeIn;  // 0xA8
};

// PORT: g++ <? (min) operator, removed in GCC 4.3.
extern "C" float func_00313D70(sSeq_00313D70* self, int i)
{
    float time = self->tracks[i].time;
    float w = self->scale * self->tracks[i].weight;
    float end = self->tracks[i].end;
    if (time < self->fadeIn)
    {
        w = (time / self->fadeIn) <? w;
    }
    float rem = end - time;
    if (rem < self->fadeOut)
    {
        w = (rem / self->fadeOut) <? w;
    }
    return w;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00313DD0);
#ifdef SKIP_ASM
struct sVEntry_313DD0 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

static inline void Ser_313DD0(char* s, void* p, int n)
{
    sVEntry_313DD0* e = &(*(sVEntry_313DD0**)s)[1];
    e->fn(s + e->delta, p, n);
}

class cAsStream;

extern "C" void func_00313DD0(void* node, cAsStream* stream)
{
    char* self = (char*)node;
    char* s = (char*)stream;
    Ser_313DD0(s, self + 0x0, 0x4);
    Ser_313DD0(s, self + 0x4, 0x54);
    Ser_313DD0(s, self + 0x60, 0x20);
    Ser_313DD0(s, self + 0x80, 0x4);
    Ser_313DD0(s, self + 0x84, 0x4);
    Ser_313DD0(s, self + 0x88, 0x8);
    Ser_313DD0(s, self + 0x90, 0x4);
    Ser_313DD0(s, self + 0x94, 0x4);
    Ser_313DD0(s, self + 0x98, 0x4);
    Ser_313DD0(s, self + 0x9C, 0x4);
    Ser_313DD0(s, self + 0xA0, 0x4);
    Ser_313DD0(s, self + 0xA4, 0x4);
    Ser_313DD0(s, self + 0xA8, 0x4);
    Ser_313DD0(s, self + 0xB0, 0x10);
    Ser_313DD0(s, self + 0xC0, 0x4);
    Ser_313DD0(s, self + 0xC4, 0x4);
    int n = 0;
    char* p = *(char**)(self + 0xAC);
    if (p != 0) {
        int c = 0;
        do {
            p = *(char**)(p + 0xC);
            c++;
        } while (p != 0);
        n = c;
    }
    Ser_313DD0(s, &n, 4);
    for (p = *(char**)(self + 0xAC); p; p = *(char**)(p + 0xC)) {
        Ser_313DD0(s, p, 0x10);
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00314050);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0048A5B0[];

struct sVEntry_314050 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

static inline void Read_314050(char* s, void* p, int n)
{
    sVEntry_314050* e = &(*(sVEntry_314050**)s)[2];
    e->fn(s + e->delta, p, n);
}

extern "C" void func_00314050(void* node, void* stream)
{
    char* self = (char*)node;
    char* s = (char*)stream;
    Read_314050(s, self + 0x0, 0x4);
    Read_314050(s, self + 0x4, 0x54);
    Read_314050(s, self + 0x60, 0x20);
    Read_314050(s, self + 0x80, 0x4);
    Read_314050(s, self + 0x84, 0x4);
    Read_314050(s, self + 0x88, 0x8);
    Read_314050(s, self + 0x90, 0x4);
    Read_314050(s, self + 0x94, 0x4);
    Read_314050(s, self + 0x98, 0x4);
    Read_314050(s, self + 0x9C, 0x4);
    Read_314050(s, self + 0xA0, 0x4);
    Read_314050(s, self + 0xA4, 0x4);
    Read_314050(s, self + 0xA8, 0x4);
    Read_314050(s, self + 0xB0, 0x10);
    Read_314050(s, self + 0xC0, 0x4);
    Read_314050(s, self + 0xC4, 0x4);
    int n;
    Read_314050(s, &n, 4);
    char* tail = *(char**)(self + 0xAC);
    for (int i = 0; i < n; i++) {
        char* p = (char*)cMemMan_alloc(0x10, D_0048A5B0, 0x20000000, 0);
        Read_314050(s, p, 0x10);
        if (*(char**)(self + 0xAC) != 0) {
            *(char**)(tail + 0xC) = p;
        } else {
            *(char**)(self + 0xAC) = p;
        }
        tail = p;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_003142E8__FPv);
#ifdef SKIP_ASM
void func_003142E8(void* self)
{
    *(int*)self = 0;
    *(void**)((char*)self + 0x4) = 0;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_003142F8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_0048A5C0[];

struct sSeqNode_003142F8 {
    char pad_0x00[0xC8];
    sSeqNode_003142F8* next; // 0xC8
};

struct sSequencer_003142F8 {
    int mCount;                        // 0x0
    sSeqNode_003142F8* mFirstSequence; // 0x4
};

extern "C" void* func_00313508(void* mem, int arg);

extern "C" void* func_003142F8(void* seq, int arg)
{
    sSequencer_003142F8* self = (sSequencer_003142F8*)seq;
    sSeqNode_003142F8* node = (sSeqNode_003142F8*)func_00313508(cMemMan_alloc(0xD0, D_0048A5C0, 0x20000000, 0), arg);
    node->next = self->mFirstSequence;
    self->mFirstSequence = node;
    self->mCount++;
    return node;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00314368);
#ifdef SKIP_ASM
// Same layout as the unit's cAnimSequenceNode / cAnimSequencer (declared later in the unit).
struct sSeqNode_00314368 {
    char pad_0x00[0xC8];
    sSeqNode_00314368* next; // 0xC8
};

struct sSequencer_00314368 {
    int mCount;                      // 0x0
    sSeqNode_00314368* mFirstSequence; // 0x4
};

extern "C" void func_00314368(sSequencer_00314368* self, sSeqNode_00314368* node)
{
    if (self->mFirstSequence != 0)
    {
        sSeqNode_00314368* p = self->mFirstSequence;
        while (p->next != 0)
        {
            p = p->next;
        }
        p->next = node;
    }
    else
    {
        self->mFirstSequence = node;
    }
    node->next = 0;
    self->mCount++;
}
#endif

INCLUDE_ASM("animation/animsequencer", func_003143C8);

//100%
INCLUDE_ASM("animation/animsequencer", func_00314418);
#ifdef SKIP_ASM
struct sSeq_00314418;
extern "C" float func_00313D70_314418(sSeq_00314418* self, int i) __asm__("func_00313D70");

struct sVec4_314418
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sSeqTrack_314418
{
    char pad0[0x4];
    int id;         // 0x4
    float time;     // 0x8
    char padC[0xC];
    int flag;       // 0x18
};

struct sSeq_00314418
{
    sSeqTrack_314418 tracks[3];     // 0x00
    char pad54[0xC];
    sVec4_314418 a;                 // 0x60
    sVec4_314418 b;                 // 0x70
    int c;                          // 0x80
    int d;                          // 0x84
    long e;                         // 0x88
    char pad90[0x38];
    sSeq_00314418* next;            // 0xC8
};

struct sSeqState_314418
{
    int id;             // 0x00
    float time;         // 0x04
    int d;              // 0x08
    float weight;       // 0x0C
    long e;             // 0x10
    char pad18[0x8];
    sVec4_314418 a;     // 0x20
    sVec4_314418 b;     // 0x30
    int c;              // 0x40
    char pad44[0xC];
};

// PORT: `long` field is 64-bit (ld/sd).
extern "C" int func_00314418(void* self, sSeqState_314418* out)
{
    int count = 0;
    sSeq_00314418* n = *(sSeq_00314418**)((char*)self + 0x4);
    while (n != 0)
    {
        for (int j = 0; j < 3; j++)
        {
            if (n->tracks[j].flag != 0)
            {
                sSeqState_314418* o = &out[count];
                o->id = n->tracks[j].id;
                o->time = n->tracks[j].time;
                o->a = n->a;
                o->b = n->b;
                o->c = n->c;
                o->d = n->d;
                o->weight = func_00313D70_314418(n, j);
                o->e = n->e;
                count++;
            }
        }
        n = n->next;
    }
    return count;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/animsequencer", func_00314518);
#ifdef SKIP_ASM
extern "C" void* func_003142F8(void* seq, int arg);
extern "C" void func_00313C50(void* self, int i, int anim);

extern "C" void* func_00314518(void* self, int arg, int anim, float val)
{
    void* node = func_003142F8(self, arg);
    func_00313C50(node, 0, anim);
    func_00313CF0(node, 0, val);
    func_00313D40(node, 0, 0);
    return node;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/animsequencer", func_00314588);
#ifdef SKIP_ASM
extern "C" void* func_003142F8(void* seq, int arg);
extern "C" void func_00313C50(void* self, int i, int anim);

extern "C" void* func_00314588(void* self, int arg, int anim, float val)
{
    void* node = func_003142F8(self, arg);
    func_00313C50(node, 0, anim);
    func_00313CF0(node, 0, val);
    func_00313D40(node, 0, 1);
    return node;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_003145F8);
#ifdef SKIP_ASM
struct sSeqNode_003145F8 {
    char pad_0x00[0xC8];
    sSeqNode_003145F8* next; // 0xC8
};

struct sSequencer_003145F8 {
    int mCount;                        // 0x0
    sSeqNode_003145F8* mFirstSequence; // 0x4
};

extern "C" void func_003145F8(sSequencer_003145F8* self, sSeqNode_003145F8* node)
{
    sSeqNode_003145F8** pp;
    for (pp = &self->mFirstSequence; *pp != 0; pp = &(*pp)->next)
    {
        sSeqNode_003145F8* n = *pp;
        if (n == node)
        {
            *pp = n->next;
            if (n != 0)
            {
                func_00313C08((char*)n);
                operator_delete((int*)n);
            }
            self->mCount--;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00314668);
#ifdef SKIP_ASM
struct sSeqNode_00314668 {
    char pad_0x00[0xC8];
    sSeqNode_00314668* next; // 0xC8
};

struct sSequencer_00314668 {
    int mCount;                        // 0x0
    sSeqNode_00314668* mFirstSequence; // 0x4
};

extern "C" void func_00314668(sSequencer_00314668* self)
{
    while (self->mFirstSequence != 0)
    {
        sSeqNode_00314668* n = self->mFirstSequence;
        self->mFirstSequence = n->next;
        if (n != 0)
        {
            func_00313C08((char*)n);
            operator_delete((int*)n);
        }
        self->mCount--;
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_003146D0);
#ifdef SKIP_ASM
extern "C" void func_003146D0(void* self, float v)
{
    for (char* node = *(char**)((char*)self + 0x4); node != 0; node = *(char**)(node + 0xC8))
    {
        func_00313A20(node, v);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/animsequencer", func_00314718);
#ifdef SKIP_ASM
extern "C" void func_00313BA8(void* self, int v);

extern "C" void func_00314718(void* self, int v)
{
    for (char* node = *(char**)((char*)self + 0x4); node != 0; node = *(char**)(node + 0xC8))
    {
        func_00313BA8(node, v);
    }
}
#endif

struct cAnimSequenceNode {
    char pad_0x00[0xC8];
    cAnimSequenceNode* next; // 0xC8
};

struct cAnimSequencer {
    char pad_0x00[0x4];
    cAnimSequenceNode* mFirstSequence; // 0x4
};

//100%
INCLUDE_ASM("animation/animsequencer", cAnimSequencer_getSequence__FP14cAnimSequenceri);
#ifdef SKIP_ASM
cAnimSequenceNode* cAnimSequencer_getSequence(cAnimSequencer* self, int index)
{
    cAnimSequenceNode* cur = self->mFirstSequence;
    while (cur != 0 && index-- > 0) {
        cur = cur->next;
    }
    return cur;
}
#endif

INCLUDE_ASM("animation/animsequencer", func_00314788);

INCLUDE_ASM("animation/animsequencer", func_003147B8);
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/animsequencer", func_003147F0);
#ifdef SKIP_ASM
class cAsStream {
public:
    virtual void serialize(void* data, int size);
};

struct sSeqNode_003147F0 {
    char pad_0x00[0xC8];
    sSeqNode_003147F0* next; // 0xC8
};

struct sSequencer_003147F0 {
    int mCount;                        // 0x0
    sSeqNode_003147F0* mFirstSequence; // 0x4
};

extern "C" void func_00313DD0(void* node, cAsStream* s);

extern "C" void func_003147F0(sSequencer_003147F0* self, cAsStream* s)
{
    s->serialize(self, 4);
    sSeqNode_003147F0* n = self->mFirstSequence;
    for (int i = 0; i < self->mCount; i++)
    {
        func_00313DD0(n, s);
        n = n->next;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("animation/animsequencer", func_00314880);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is the game's tagged operator new(size, tag, flags, d); bound by asm label.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_003E6448(void* dst, int value, int size);
extern "C" void func_00314050(void* node, void* stream);
extern const char D_0048A5C0[];

struct sStreamVE_314880 { short delta; short index; void (*fn)(void*, void*, int); };

struct sSeqTrack_314880
{
    char pad[0x1C];
    sSeqTrack_314880() {}
};

struct sSeqNode_314880
{
    sSeqTrack_314880 tracks[3];
    char pad54[0xD0 - 0x54];
    sSeqNode_314880() {}
};

extern "C" void func_00314880(void* self, void* stream)
{
    int n;
    sStreamVE_314880* vt = *(sStreamVE_314880**)stream;
    vt[2].fn((char*)stream + vt[2].delta, &n, 4);
    *(int*)self = 0;
    for (int i = 0; i < n; i++)
    {
        sSeqNode_314880* node = new (D_0048A5C0, 0x20000000, 0) sSeqNode_314880;
        func_003E6448(node, 0, 0xD0);
        func_00314050(node, stream);
        func_00314368((sSequencer_00314368*)self, (sSeqNode_00314368*)node);
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00314978__FPv);
#ifdef SKIP_ASM
void* func_00314978(void* self)
{
    *(int*)self = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00314988);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_003149D0(void** self);

extern "C" void func_00314988(int* self, int flags)
{
    func_003149D0((void**)self);
    if (flags & 1)
    {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_003149D0);
#ifdef SKIP_ASM
void cMemMan_free(void* ptr);

extern "C" void func_003149D0(void** self)
{
    if (self[0] != 0)
    {
        cMemMan_free(self[0]);
    }
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
}
#endif

extern "C" void* func_00314AA0(void*);

//100%
INCLUDE_ASM("animation/animsequencer", func_00314A18__FPvi);
#ifdef SKIP_ASM
// PORT: asm label (same binding the unit uses for func_00314AA0's two-argument body).
void func_00314AA0_impl(void* self, char* data) __asm__("func_00314AA0");

void func_00314A18(void* self, int a1)
{
    *(int*)self = a1;
    func_00314AA0_impl(self, (char*)a1);
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00314A40__FPv);
#ifdef SKIP_ASM
void* func_00314A40(void* self)
{
    *(int*)self = 0;
    return func_00314AA0(self);
}
#endif

INCLUDE_ASM("animation/animsequencer", func_00314A60);

//100%
INCLUDE_ASM("animation/animsequencer", func_00314AA0);
#ifdef SKIP_ASM
// The original had the same mismatch: callers (func_00314A18/func_00314A40, the
// latter already 100%) see the one-argument declaration above and leave $5 as-is,
// while the definition takes two. The asm label binds this two-argument body to
// the symbol without changing the callers' prototype.
// PORT: asm labels are GCC/Clang-only; the port should give callers the real signature.
void func_00314AA0_impl(void* self, char* data) __asm__("func_00314AA0");
void func_00314AA0_impl(void* self, char* data)
{
    *(char**)((char*)self + 0x4) = data;
    *(char**)((char*)self + 0x8) = data + *(short*)(data + 0x6);
    *(char**)((char*)self + 0xC) = data + *(int*)(data + 0x8);
}
#endif

INCLUDE_ASM("animation/animsequencer", func_00314AC0);
//100%
INCLUDE_ASM("animation/animsequencer", func_00314AE0);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);

extern "C" int func_00314AE0(char* self, const char* name) {
    int i;
    for (i = 0; i < *(short*)(*(char**)(self + 4) + 4); i++) {
        if (func_0041AA88(name, *(char**)(self + 8) + i * 0x60) == 0)
            return 1;
    }
    return 0;
}
#endif
//100%
INCLUDE_ASM("animation/animsequencer", func_00314B70);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);

extern "C" char* func_00314B70(char* self, const char* name) {
    int i;
    for (i = 0; i < *(short*)(*(char**)(self + 4) + 4); i++) {
        if (func_0041AA88(name, *(char**)(self + 8) + i * 0x60) == 0)
            return *(char**)(self + 8) + i * 0x60;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("animation/animsequencer", func_00314C00);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" void* cMdfArchive_getModelPartByIndex(void* self, int index);

struct sMdfPart60 {
    char name[0x60];
};

struct sMdfHeader {
    int pad0;
    short count; // 0x4
};

struct sMdfArchive {
    int pad0;
    sMdfHeader* header; // 0x4
    sMdfPart60* parts;  // 0x8
};

extern "C" void* func_00314C00(sMdfArchive* self, const char* name)
{
    for (int i = 0; i < self->header->count; i++)
    {
        if (func_0041AA88(name, self->parts[i].name) == 0)
            return cMdfArchive_getModelPartByIndex(self, i);
    }
    return 0;
}
#endif


//100%
INCLUDE_ASM("animation/animsequencer", func_00314C98);
#ifdef SKIP_ASM
extern "C" int func_00314C98(void *arg0, int arg1) {
    return (*(int *)((char*)(arg0) + (8))) + (arg1 * 0x60);
}
#endif
