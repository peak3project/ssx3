#include "common.h"

struct cWorldViewSectionList {
    char pad_0x00[0x8];
    int mNumSections; // 0x8
};

struct cWorldView {
    char pad_0x00[0x4];
    cWorldViewSectionList* mSections; // 0x4
};

//100%
INCLUDE_ASM("world/worldview", cWorldView_getNumSections__FP10cWorldView);
#ifdef SKIP_ASM
int cWorldView_getNumSections(cWorldView* self)
{
    if (self->mSections == 0) {
        return 0;
    }
    return self->mSections->mNumSections;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A9820);
#ifdef SKIP_ASM
extern "C" void* func_003A9820(cWorldView* self, unsigned int i)
{
    cWorldViewSectionList* list = self->mSections;
    if (list == 0 || i >= (unsigned int)list->mNumSections) {
        return 0;
    }
    return *(char**)((char*)self + 0x8) + i * 0x58;
}
#endif

struct cWorldViewEntry {
    char pad_0x00[0x14];
    int field_0x14;
};

//100%
INCLUDE_ASM("world/worldview", cWorldView_isSectionLoaded__FP10cWorldViewi);
#ifdef SKIP_ASM
int cWorldView_isSectionLoaded(cWorldView* self, int section)
{
    if (self->mSections == 0 || (unsigned int)section >= (unsigned int)self->mSections->mNumSections) {
        return 0;
    }
    cWorldViewEntry* entry = (cWorldViewEntry*)((char*)self + section * 8);
    return (unsigned int)(entry->field_0x14 - 5) < 2;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A9890);
#ifdef SKIP_ASM
extern "C" int func_003A9890(cWorldView* self, unsigned int i)
{
    cWorldViewSectionList* list = self->mSections;
    if (list == 0 || i >= (unsigned int)list->mNumSections) {
        return 0;
    }
    return *(int*)((char*)self + (i << 3) + 0x14) == 0;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A98C8);
#ifdef SKIP_ASM
struct sViewEnt_3A98C8 { int state; float value; };
struct sView_3A98C8 { int f0; char* info; char pad8[0xC]; sViewEnt_3A98C8 ents[1]; };
extern "C" int func_003A98C8(sView_3A98C8* self, unsigned int idx, float value)
{
    if (self->info != 0 && idx < *(unsigned int*)(self->info + 8)) {
        self->ents[idx].value = value;
        switch (self->ents[idx].state) {
        case 0:
            self->ents[idx].state = 1;
            break;
        case 3:
            self->ents[idx].state = 5;
            break;
        case 4:
            return 0;
        case 1: case 2: case 5: case 6:
            break;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A9958);
#ifdef SKIP_ASM
struct sViewEnt_3A9958 { int state; int pad; };
struct sView_3A9958 { int f0; char* info; char pad8[0xC]; sViewEnt_3A9958 ents[1]; };
extern "C" int func_003A9958(sView_3A9958* self, unsigned int idx)
{
    if (self->info != 0 && idx < *(unsigned int*)(self->info + 8)) {
        switch (self->ents[idx].state) {
        case 2:
            return 0;
        case 5: case 6:
            self->ents[idx].state = 3;
            break;
        case 1:
            self->ents[idx].state = 0;
            break;
        case 0: case 3: case 4:
            break;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A99D8);
#ifdef SKIP_ASM
extern "C" void func_003A8F10(void* world, unsigned int i);
struct func_003A99D8_sEntry { int state; int field_0x4; };
struct func_003A99D8_sView { void* world; cWorldViewSectionList* mSections; };
extern "C" int func_003A99D8(func_003A99D8_sView* self, unsigned int i)
{
    cWorldViewSectionList* list = self->mSections;
    if (list != 0 && i < (unsigned int)list->mNumSections) {
        int off = i << 3;
        char* base = (char*)self + 0x14;
        func_003A99D8_sEntry* e = (func_003A99D8_sEntry*)(base + off);
        int st = e->state;
        if (st == 5) {
            e->state = 6;
            func_003A8F10(self->world, i);
            return 1;
        } else if (st == 6) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A9A98);
#ifdef SKIP_ASM
extern "C" void* func_003A9A98(void* self, int a1)
{
    return (char*)(*(void**)((char*)self + 0x10)) + a1 * 0x44;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A9AB0__FPv);
#ifdef SKIP_ASM
int func_003A9AB0(void* self)
{
    return *(int*)((char*)*(void**)((char*)self + 0x4) + 0x10);
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003A9D60);
#ifdef SKIP_ASM
struct sWVSlot_9D60 {
    int state;
    int f4;
};

struct sWVItem_9D60 {
    char pad0[0x1C];
    void* section;
    char pad20[0x58 - 0x20];
};

struct sWVCam_9D60 {
    int active;
    int f4;
    int frame;
    char padC[0x40 - 0xC];
    float f40;
    float f44;
    float f48;
    char pad4C[0x50 - 0x4C];
};

struct sWV_9D60 {
    void* world;
    cWorldViewSectionList* mSections;
    sWVItem_9D60* items;
    int fC;
    int f10;
    sWVSlot_9D60 slots[0x45];
    char pad23C[0x240 - 0x23C];
    sWVCam_9D60 cams[4];
};

extern char* D_004A5B64;
extern "C" void func_003AA028(void* self, void* section, int cam, int loaded);

extern "C" void func_003A9D60(sWV_9D60* self, int cam)
{
    if (*(int*)((char*)self + cam * 0x50 + 0x240) != 0) {
        int frame = *(int*)(D_004A5B64 + 0x18);
        float v = *(float*)((char*)self + cam * 0x50 + 0x280);
        *(float*)((char*)self + cam * 0x50 + 0x284) = v;
        *(float*)((char*)self + cam * 0x50 + 0x288) = v;
        unsigned int i;
        for (i = 0; i < (unsigned int)self->mSections->mNumSections; i++) {
            int st = self->slots[i].state;
            if (st == 5 || st == 6) {
                func_003AA028(self, self->items[i].section, cam, st == 6);
            }
        }
        *(int*)((char*)self + cam * 0x50 + 0x248) = frame;
        *(int*)((char*)self + cam * 0x50 + 0x244) = 0;
    }
}
#endif

INCLUDE_ASM("world/worldview", func_003A9E50);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldview", func_003AA028);
#ifdef SKIP_ASM
extern "C" float func_003A9E50(void* self, void* pos, void* bmin, void* bmax);
extern "C" int func_003A8618(void* self, int a1);
extern "C" void func_003A8448(void* self, int i, float f);

struct sV4_A028 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sWVCam_A028 {
    int active;         // 0x00
    int f4;
    int frame;          // 0x08
    int fC;
    sV4_A028 pos;       // 0x10
    sV4_A028 bmin;      // 0x20
    sV4_A028 bmax;      // 0x30
    float range;        // 0x40
    float near;         // 0x44
    float best;         // 0x48
    int f4C;
};

struct sWV_A028 {
    void* world;        // 0x00
    char pad4[0x23C];
    sWVCam_A028 cams[4]; // 0x240
};

struct sSecInfo_A028 {
    short f0;
    unsigned short id;  // 0x02
};

struct sSection_A028 {
    float bmin[4];      // 0x00
    float bmax[4];      // 0x10
    sV4_A028 n0;        // 0x20
    sV4_A028 n1;        // 0x30
    char pad40[0x10];
    void* child0;       // 0x50
    void* child1;       // 0x54
    sSecInfo_A028* info; // 0x58
};

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float Dot_A028(const sV4_A028& a, const sV4_A028& b)
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

static inline int overlap_A028(const sV4_A028* c, const sSection_A028* s)
{
    int r = 0;
    if (c[0].x <= s->bmax[0] && c[1].x >= s->bmin[0] &&
        c[0].y <= s->bmax[1] && c[1].y >= s->bmin[1] &&
        c[0].z <= s->bmax[2] && c[1].z >= s->bmin[2]) {
        r = 1;
    }
    return r;
}

extern "C" void func_003AA028(void* self_, void* sec_, int cam, int loaded)
{
    if (!overlap_A028(&((sWV_A028*)self_)->cams[cam].bmin, (sSection_A028*)sec_))
        return;
    if (((sSection_A028*)sec_)->info != 0) {
        float d = func_003A9E50(self_, &((sWV_A028*)self_)->cams[cam].pos, sec_, ((sSection_A028*)sec_)->bmax);
        float m = ((sWV_A028*)self_)->cams[cam].near;
        float w;
        if (d < 0.0f) {
            w = 0.800000011920929f;
            if (func_003A8618(((sWV_A028*)self_)->world, ((sSection_A028*)sec_)->info->id) == 0)
                m = 0.0f;
        } else {
            if (((sWV_A028*)self_)->cams[cam].range < d)
                return;
            w = (1.0f - d / ((sWV_A028*)self_)->cams[cam].range) * 0.800000011920929f;
            if (d < m) {
                if (func_003A8618(((sWV_A028*)self_)->world, ((sSection_A028*)sec_)->info->id) == 0)
                    m = d;
            }
        }
        if (loaded)
            ((sWV_A028*)self_)->cams[cam].near = m;
        if (m < ((sWV_A028*)self_)->cams[cam].best)
            ((sWV_A028*)self_)->cams[cam].best = m;
        func_003A8448(((sWV_A028*)self_)->world, ((sSection_A028*)sec_)->info->id, w);
    }
    if (((sSection_A028*)sec_)->child0 != 0) {
        if (Dot_A028(((sSection_A028*)sec_)->n0, ((sWV_A028*)self_)->cams[cam].bmin) < 0.0f)
            func_003AA028(self_, ((sSection_A028*)sec_)->child0, cam, loaded);
    }
    if (((sSection_A028*)sec_)->child1 != 0) {
        if (Dot_A028(((sSection_A028*)sec_)->n1, ((sWV_A028*)self_)->cams[cam].bmax) < 0.0f)
            func_003AA028(self_, ((sSection_A028*)sec_)->child1, cam, loaded);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA2F0);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int c, int n);

struct func_003AA2F0_sEntry {
    float dist;
    float scale;
    short a;
    short b;
};

struct func_003AA2F0_sState {
    int f00;
    unsigned int flags;
    unsigned int f08;
    int f0C;
    func_003AA2F0_sEntry entries[24];
};

extern func_003AA2F0_sState D_00508F50;

struct func_003AA2F0_sView {
    int f00;
    func_003AA2F0_sState* state;
    void** vt;
};
// splat labels D_00508F50+8 separately
extern unsigned int D_00508F58[];
extern int D_004A5A68;
extern void* D_00495150[];

// PORT: the unit declares this `void`, but the body returns self ($2); bound via asm label.
func_003AA2F0_sView* func_003AA2F0_impl(func_003AA2F0_sView* self) __asm__("func_003AA2F0");

func_003AA2F0_sView* func_003AA2F0_impl(func_003AA2F0_sView* self)
{
    self->vt = D_00495150;
    self->f00 = 0;
    if (D_004A5A68 == 0) {
        D_00508F50.f08 = 0xFFFFFFFF;
        D_004A5A68 = 1;
    }
    func_003AA2F0_sState* s = &D_00508F50;
    self->state = s;
    func_003E6448(s, 0, sizeof(func_003AA2F0_sState));
    D_00508F58[0] = 0xFFFFFFFF;
    s->f0C = -1;
    D_00508F50.f00 = 0;
    int i;
    for (i = 0; i < 24; i++) {
        s->entries[i].dist = 1000.0f;
        s->entries[i].scale = 0.5f;
        s->entries[i].a = 0;
        s->entries[i].b = -1;
    }
    D_00508F50.flags = (((D_00508F50.flags | 1) & ~4) | 2) << 16;
    return self;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA3F0);
#ifdef SKIP_ASM
class func_003AA3F0_cObj {
public:
    char pad00[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual int v06(void* a1);
};

// PORT: stores a pointer in an int field (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003AA3F0(func_003AA3F0_cObj* self, void* a1)
{
    *(int*)((char*)a1 + 0x8) += (int)a1;
    *(int*)((char*)a1 + 0xC) += (int)a1;
    self->v06(a1);
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA438);
#ifdef SKIP_ASM
class func_003AA438_cObj {
public:
    char pad00[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07(void* p, void* base);
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual int v11(void* p, void* base);
};

struct func_003AA438_sEnt {
    int f0;
    int f4;
    int f8;
    unsigned int fC;
};

extern char D_004FF1A0[];

// PORT: stores pointers in int fields (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003AA438(func_003AA438_cObj* self, void* a1)
{
    int n = *(int*)((char*)a1 + 0x4);
    func_003AA438_sEnt* e = *(func_003AA438_sEnt**)((char*)a1 + 0x8);
    int i;
    for (i = 0; i < n; i++, e++) {
        if (e->f4 != 0) {
            e->f4 += (int)a1;
            self->v07((void*)e->f4, a1);
        }
        if (e->fC == 0xFFFFFFFF) {
            e->fC = (unsigned int)D_004FF1A0;
        } else {
            e->fC += (int)a1;
        }
        if (e->f8 != 0) {
            e->f8 += (int)a1;
            self->v11((void*)e->f8, a1);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA520);
#ifdef SKIP_ASM
class func_003AA520_cObj {
public:
    char pad00[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int v08(void* p, int base);
};

// PORT: stores pointers in int fields (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003AA520(func_003AA520_cObj* self, void* a1, int base)
{
    int i = 0;
    int* p = (int*)(*(int*)((char*)a1 + 0x20) += base);
    for (; i < *(int*)((char*)a1 + 0x1C); i++) {
        *p += base;
        self->v08((void*)*p++, base);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA5C8);
#ifdef SKIP_ASM
class func_003AA5C8_cObj {
public:
    char pad00[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
    virtual int v15(void* a1);
};

// PORT: stores a pointer in an int field (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003AA5C8(func_003AA5C8_cObj* self, void* a1)
{
    *(int*)((char*)a1 + 0x8) += (int)a1;
    self->v15(a1);
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA608);
#ifdef SKIP_ASM
class func_003AA608_cObj {
public:
    char pad00[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
    virtual int v11(void* p, void* base);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16(void* p);
};

struct func_003AA608_sEnt {
    int f0;
    int f4;
    int f8;
    unsigned int fC;
};

extern char D_004FF1A0[];

// PORT: stores pointers in int fields (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003AA608(func_003AA608_cObj* self, void* a1)
{
    int n = *(int*)((char*)a1 + 0x4);
    func_003AA608_sEnt* e = *(func_003AA608_sEnt**)((char*)a1 + 0x8);
    int i;
    for (i = 0; i < n; i++, e++) {
        if (e->f4 != 0) {
            e->f4 += (int)a1;
            self->v16((void*)e->f4);
        }
        if (e->fC == 0xFFFFFFFF) {
            e->fC = (unsigned int)D_004FF1A0;
        } else {
            e->fC += (int)a1;
        }
        if (e->f8 != 0) {
            e->f8 += (int)a1;
            self->v11((void*)e->f8, 0);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA6E8);
#ifdef SKIP_ASM
extern "C" int func_003AA6E8(void* self, void* a1)
{
    *(int*)((char*)a1 + 0x20) += (int)a1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA700);
#ifdef SKIP_ASM
// PORT: decodes an int handle into a pointer ((void*)(i << 2)); not 64-bit safe.
extern "C" int func_003AA700(void* self, void* a1)
{
    unsigned int h = *(unsigned int*)((char*)a1 + 0x64);
    char* sec = (*(char***)(**(char***)self + 8))[h & 0xFF];
    void* res;
    unsigned int i;
    if (sec == 0 || (i = (*(unsigned int**)(sec + 0x24))[h >> 8] >> 8) == 0) {
        res = 0;
    } else {
        res = (void*)(i << 2);
    }
    *(void**)((char*)a1 + 0x64) = res;
    *(int*)((char*)a1 + 0x84) = 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA758);
#ifdef SKIP_ASM
// PORT: stores a pointer in an int field (int typing needed to match); not 64-bit safe.
extern "C" int func_003AA758(void* self, void* a1)
{
    if (*(int*)((char*)a1 + 0x10) == -1) {
        *(int*)((char*)a1 + 0x10) = 0;
    } else {
        *(int*)((char*)a1 + 0x10) = (int)((char*)a1 + 0x14);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA780);
#ifdef SKIP_ASM
// PORT: decodes int handles into pointers ((void*)(i << 2)); not 64-bit safe.
extern "C" int func_003AA780(void* self, int n, int* data)
{
    int g;
    for (g = 0; g < n; g++) {
        int j;
        unsigned int* hp = (unsigned int*)(data + 1);
        for (j = 0; j < *data; j++, hp++) {
            unsigned int h = *hp;
            char* sec = (*(char***)(**(char***)self + 8))[h & 0xFF];
            void* res;
            unsigned int i;
            if (sec == 0 || (i = (*(unsigned int**)(sec + 0x4))[h >> 8] >> 8) == 0) {
                res = 0;
            } else {
                res = (void*)(i << 2);
            }
            *(void**)hp = res;
        }
        data += *data + 1;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA830);
#ifdef SKIP_ASM
class func_003AA830_cObj {
public:
    char pad00[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
    virtual int v12(void* p, int base);
};

// PORT: stores pointers in int fields (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003AA830(func_003AA830_cObj* self, void* a1, int base)
{
    int i = 0;
    int* p = (int*)(*(int*)((char*)a1 + 0x20) += base);
    for (; i < *(int*)((char*)a1 + 0x1C); i++) {
        *p += base;
        self->v12((void*)*p++, base);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AA8D8);
#ifdef SKIP_ASM
extern "C" int func_003AA8D8(void* self, void* a1, int a2)
{
    *(int*)((char*)a1 + 0x4) += a2;
    return 1;
}
#endif

INCLUDE_ASM("world/worldview", func_003AA8F0);

//100%
INCLUDE_ASM("world/worldview", func_003AA960);
#ifdef SKIP_ASM
struct func_003AA960_sNode {
    char pad[0x60];
    int prev;       // 0x60 (index fixed up into a pointer)
    int next;       // 0x64
    void* owner;    // 0x68
    char pad6C[0x90 - 0x6C];
};

// PORT: stores pointers in int fields (int typing needed to match); not 64-bit safe.
extern "C" int func_003AA960(void* self, void* list)
{
    int i;
    int count = *(int*)((char*)list + 0x20);
    func_003AA960_sNode* nodes = (func_003AA960_sNode*)((char*)list + 0x30);
    int next = 1;
    *(func_003AA960_sNode**)((char*)list + 0x24) = nodes;
    int prev = count - 1;
    for (i = 0; i < *(int*)((char*)list + 0x20); i++) {
        if (nodes[i].prev != -1) {
            nodes[i].prev = (int)&nodes[prev];
        } else {
            nodes[i].prev = 0;
        }
        if (nodes[i].next != -1) {
            nodes[i].next = (int)&nodes[next];
        } else {
            nodes[i].next = 0;
        }
        prev++;
        next++;
        if (prev >= *(int*)((char*)list + 0x20)) {
            prev = 0;
        }
        if (next >= *(int*)((char*)list + 0x20)) {
            next = 0;
        }
        nodes[i].owner = list;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AAA08);
#ifdef SKIP_ASM
extern "C" void func_0032C540(void* self);
extern "C" int func_00327DA8(void* self, char* data, void* ctx);

struct sList_3AAA08 {
    char* items;
    int count;
};

struct sNode_3AAA08 {
    unsigned short n;
    unsigned short pad;
    char* p4;
    char* p8;
    char* pC;
    char* p10;
};

struct sChunk_3AAA08 {
    unsigned short type;
    unsigned short n;
    char* data;             // 0x4
    sList_3AAA08* list;     // 0x8
    char* items;            // 0xC
};

extern "C" int func_003AAA08(void* self, void* ctx, sChunk_3AAA08* c)
{
    if ((int)c->data == -1) {
        c->data = 0;
    } else {
        c->data = (char*)c + (int)c->data;
    }
    if ((int)c->list == -1) {
        c->list = 0;
    } else {
        c->list = (sList_3AAA08*)((char*)c + (int)c->list);
    }
    if ((int)c->items == -1) {
        c->items = 0;
    } else {
        c->items = (char*)c + (int)c->items;
    }
    if (c->type == 3) {
        sList_3AAA08* l = c->list;
        l->count = 0;
        l->items = 0;
        l->count = c->n;
        l->items = c->items;
        for (int i = 0; i < l->count; i++) {
            func_0032C540(l->items + i * 0x140);
        }
        char* data = c->data;
        for (int i = 0; i < l->count; i++) {
            data += func_00327DA8(l->items + i * 0x140, data, ctx);
        }
    } else if (c->type == 1) {
        sList_3AAA08* l = c->list;
        l->count = 0;
        l->items = 0;
        l->count = c->n;
        l->items = c->items;
        sNode_3AAA08* node = (sNode_3AAA08*)c->data;
        for (int i = 0; i < l->count; i++) {
            ((sNode_3AAA08**)l->items)[i] = node;
            node->p4 = (char*)node + (int)node->p4;
            node->p8 = (char*)node + (int)node->p8;
            node->pC = (char*)node + (int)node->pC;
            node->p10 = (char*)node + (int)node->p10;
            node = (sNode_3AAA08*)(node->p10 + node->n * 16);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AABD8);
#ifdef SKIP_ASM
// PORT: func_003AD230__FPv is declared (void*) but takes a flags int and returns a float.
float func_003AD230_f(int flags) __asm__("func_003AD230__FPv");

struct func_003AABD8_sObj {
    char pad_0x00[0xC];
    int flags;          // 0xC
    char pad_0x10[0xC];
    float pos[3];       // 0x1C
    float min[3];       // 0x28
    float max[3];       // 0x34
    int field_0x40;
    int field_0x44;
};

extern "C" int func_003AABD8(void* self, func_003AABD8_sObj* obj)
{
    float r = func_003AD230_f(obj->flags & 0x70);
    obj->field_0x44 = 0;
    obj->field_0x40 = 0;
    obj->min[0] = obj->pos[0] - r;
    obj->min[1] = obj->pos[1] - r;
    obj->min[2] = obj->pos[2] - r;
    obj->max[0] = obj->pos[0] + r;
    obj->max[1] = obj->pos[1] + r;
    obj->max[2] = obj->pos[2] + r;
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AAC50);
#ifdef SKIP_ASM
extern "C" int func_003AAC50(void* self, void* obj)
{
    if (*(int*)((char*)obj + 0xC) & 0x100) {
        return 0;
    }
    int t = *(int*)((char*)obj + 0x10);
    if (t < 3) {
        if (t > 0) {
            if (*(float*)((char*)obj + 0x1C) > 5000.0f) {
                *(float*)((char*)obj + 0x1C) = 5000.0f;
            }
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AACA8);
#ifdef SKIP_ASM
extern "C" int func_003AACA8(void* self, void* a1)
{
    if (*(int*)((char*)a1 + 0xC) & 0x100) {
        return 0;
    }
    switch (*(int*)((char*)a1 + 0x10)) {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("world/worldview", func_003AAD98);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_003AA2F0(void* self);
extern char D_00494F70[];
extern void* D_00495090[];

extern "C" void* func_003AAD98()
{
    void* p = cMemMan_alloc(0x14, D_00494F70, 0, 0);
    func_003AA2F0(p);
    *(void***)((char*)p + 0x8) = D_00495090;
    return p;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AADE8);
#ifdef SKIP_ASM
void func_003AAE60(void*);
void operator_delete(int*);
extern void* D_00495090[];
extern void* D_00495150[];

extern "C" void func_003AADE8(int* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00495090;
    func_003AAE60(self);
    *(void***)((char*)self + 0x8) = D_00495150;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AAE40);
#ifdef SKIP_ASM
extern char*** D_004A47B8;

extern "C" void func_003AAE40(void* self, int a1)
{
    char*** w = D_004A47B8;
    *(int*)((char*)self + 0xC) = a1;
    *(char****)self = w;
    *(int*)((char*)self + 0x10) = *(short*)(**w + 0x2A);
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AAE60__FPv);
#ifdef SKIP_ASM
void func_003AAE60(void* self)
{
}
#endif

INCLUDE_ASM("world/worldview", func_003AAE68);

INCLUDE_ASM("world/worldview", func_003AB498);

//100%
INCLUDE_ASM("world/worldview", func_003ABE40);
#ifdef SKIP_ASM
struct func_003ABE40_sTab {
    int f0;
    unsigned int* entries;
};
struct func_003ABE40_sLib {
    int f0;
    int f4;
    func_003ABE40_sTab** tables;
};

class func_003ABE40_cObj {
public:
    func_003ABE40_sLib** f0;
    int f4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual int v06(void* a1);
};

extern "C" int func_003ABF20(void* self, void* a1);

static inline unsigned int func_003ABE40_lookup(func_003ABE40_cObj* self, unsigned int id)
{
    func_003ABE40_sTab* t = (*self->f0)->tables[id & 0xFF];
    unsigned int r;
    unsigned int v;
    if (t == 0 || (v = t->entries[id >> 8] >> 8) == 0) {
        r = 0;
    } else {
        r = v << 2;
    }
    return r;
}

// PORT: stores pointers in int fields (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003ABE40(func_003ABE40_cObj* self, void* a1)
{
    int i = 0;
    *(int*)((char*)a1 + 0x8) += (int)a1;
    *(int*)((char*)a1 + 0xC) += (int)a1;
    int* tbl = *(int**)((char*)a1 + 0xC);
    unsigned int* p = (unsigned int*)(tbl + 1);
    for (; i < *tbl; i++, p++) {
        *p = func_003ABE40_lookup(self, *p);
    }
    self->v06(a1);
    func_003ABF20(self, a1);
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003ABF20);
#ifdef SKIP_ASM
extern "C" void func_003ABF50(void* self, void* a1);

// PORT: adds a pointer to an int field (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003ABF20(void* self, void* a1)
{
    *(int*)((char*)a1 + 0x24) += (int)a1;
    func_003ABF50(self, a1);
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003ABF50);
#ifdef SKIP_ASM
extern "C" void func_003ABFC0(void* self, void* item, void* list);

struct func_003ABF50_sEntry {
    int field_0x0;
    void* item;     // 0x4
    int field_0x8;
    int field_0xC;
};

struct func_003ABF50_sList {
    int field_0x0;
    int count;                       // 0x4
    func_003ABF50_sEntry* entries;   // 0x8
};

// PORT: the unit declares func_003ABF50 as returning void (func_003ABF20 calls it that way),
// but the body returns 1; bind the int-returning body to the symbol with an asm label.
int func_003ABF50_impl(void* self, func_003ABF50_sList* list) __asm__("func_003ABF50");

int func_003ABF50_impl(void* self, func_003ABF50_sList* list)
{
    int n = list->count;
    func_003ABF50_sEntry* e = list->entries;
    int i;
    for (i = 0; i < n; i++, e++) {
        if (e->item != 0) {
            func_003ABFC0(self, e->item, list);
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003ABFC0);
#ifdef SKIP_ASM
extern "C" void func_003AC048(void* self, void* obj, void* list, int index);

// PORT: the unit declares func_003ABFC0 as returning void (func_003ABF50 calls it that way),
// but the body returns 1; bind the int-returning body to the symbol with an asm label.
int func_003ABFC0_impl(void* self, void* item, void* list) __asm__("func_003ABFC0");

int func_003ABFC0_impl(void* self, void* item, void* list)
{
    void** p = *(void***)((char*)item + 0x20);
    int i;
    for (i = 0; i < *(int*)((char*)item + 0x1C); i++, p++) {
        func_003AC048(self, *p, list, i);
    }
    return 1;
}
#endif

INCLUDE_ASM("world/worldview", func_003AC048);

//100%
INCLUDE_ASM("world/worldview", func_003AC2A8);
#ifdef SKIP_ASM
struct func_003AC2A8_sRes {
    int f0;
    int f4;
    int f8;
    int fC;
};
struct func_003AC2A8_sTab {
    int pad[5];
    unsigned int* entries;
};
struct func_003AC2A8_sLib {
    int f0;
    int f4;
    func_003AC2A8_sTab** tables;
};
struct func_003AC2A8_sView {
    int f0;
    int f4;
};
struct func_003AC2A8_cObj {
    func_003AC2A8_sLib** f0;
    func_003AC2A8_sView* f4;
};

extern "C" int func_003AC358(void* self, void* a1);

static inline func_003AC2A8_sRes* func_003AC2A8_lookup(func_003AC2A8_cObj* self, unsigned int id)
{
    func_003AC2A8_sTab* t = (*self->f0)->tables[id & 0xFF];
    unsigned int v;
    if (t == 0 || (v = t->entries[id >> 8] >> 8) == 0) {
        return 0;
    }
    return (func_003AC2A8_sRes*)(v << 2);
}

// PORT: stores pointers in int fields; not 64-bit safe.
extern "C" int func_003AC2A8(func_003AC2A8_cObj* self, void* a1)
{
    func_003AC2A8_sRes* r = func_003AC2A8_lookup(self, *(unsigned int*)((char*)a1 + 0x80));
    *(func_003AC2A8_sRes**)((char*)a1 + 0x80) = r;
    *(int*)((char*)a1 + 0x94) = r->fC;
    *(int*)((char*)a1 + 0x8C) = 0;
    *(func_003AC2A8_sView**)((char*)a1 + 0x88) = self->f4;
    int x = self->f4->f4 & 0xFFFF0000;
    *(int*)((char*)a1 + 0x8) = x | (x >> 16) | 2;
    func_003AC358(self, a1);
    return 1;
}
#endif

//100%
INCLUDE_ASM("world/worldview", func_003AC358);
#ifdef SKIP_ASM
struct func_003AC358_sObj {
    char pad[0x1C];
    int count;
};
struct func_003AC358_sEnt {
    int f0;
    func_003AC358_sObj* obj;
    int f8;
    int fC;
};
struct func_003AC358_sList {
    int f0;
    int count;
    func_003AC358_sEnt* entries;
};

extern "C" void* func_003AC508(void* self, void* a1, func_003AC358_sList* list, void* cur);

// PORT: stores a pointer in an int field (offset -> pointer fixup); not 64-bit safe.
extern "C" int func_003AC358(void* self, void* a1)
{
    int i;
    func_003AC358_sList* list;
    void* cur;
    *(int*)((char*)a1 + 0x98) += (int)a1;
    list = *(func_003AC358_sList**)((char*)a1 + 0x80);
    cur = *(void**)((char*)a1 + 0x98);
    int n = list->count;
    func_003AC358_sEnt* e = list->entries;
    for (i = 0; i < n; i++, e++) {
        func_003AC358_sObj* o = e->obj;
        if (o != 0) {
            int j;
            for (j = 0; j < o->count; j++) {
                cur = func_003AC508(self, a1, list, cur);
            }
        }
    }
    return 1;
}
#endif

INCLUDE_ASM("world/worldview", func_003AC508);

//100%
INCLUDE_ASM("world/worldview", func_003AC7C8);
#ifdef SKIP_ASM
extern "C" void cWScriptCache_init(void* self, int a1);

extern "C" void* func_003AC7C8(void* self, int a1)
{
    *(int*)((char*)self + 0x0) = a1;
    *(int*)((char*)self + 0x4) = 0;
    cWScriptCache_init(self, 1);
    return self;
}
#endif

