#include "common.h"

//100%
INCLUDE_ASM("intersect/aifwddiff", cAIFwdDiffCache_Init);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_00340970(void* self);
extern char D_0048E4F8[];
extern char D_0048E508[];

struct sCacheEntry_7890 {
    unsigned int key;
    sCacheEntry_7890* next;
    sCacheEntry_7890* prev;
    char pad[0x1CD0 - 0xC];
};
struct sCache_7890 {
    sCacheEntry_7890* entries;  // 0x0
    sCacheEntry_7890* lru;      // 0x4
    sCacheEntry_7890** buckets; // 0x8
    int count;                  // 0xC
};

extern "C" void cAIFwdDiffCache_Init(sCache_7890* self, int n)
{
    sCacheEntry_7890* mem = (sCacheEntry_7890*)operator_new_tag(n * sizeof(sCacheEntry_7890), D_0048E4F8, 0, 0);
    sCacheEntry_7890* p = mem;
    for (int k = n - 1; k != -1; k--, p++) {
        func_00340970(p);
    }
    self->entries = mem;
    for (int i = 0; i < n; i++) {
        self->entries[i].next = &self->entries[i] + 1;
        self->entries[i].prev = &self->entries[i] - 1;
        self->entries[i].key = 0xFFFFFFFF;
    }
    self->entries[0].prev = self->entries + n - 1;
    self->entries[n - 1].next = self->entries;
    self->count = n * 2 + 13;
    self->lru = self->entries;
    self->buckets = (sCacheEntry_7890**)operator_new_tag(self->count * 4, D_0048E508, 0x80000000, 0);
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_003279D0);
#ifdef SKIP_ASM
struct sFwdDiffList;
struct sFwdDiffLink;
struct sFwdDiffTable;
struct sFwdDiffNode;
extern "C" void func_00327AC0(sFwdDiffList* list, sFwdDiffLink* n);
extern "C" void func_00327B30(void* self, void* node);
extern "C" void func_00327BB0(sFwdDiffTable* table, sFwdDiffNode* node);
extern "C" void func_00327C00(void* self, void* src, void* node);

struct sCacheNode_279D0 {
    unsigned int key;           // 0x0
    sCacheNode_279D0* lruNext;  // 0x4
    sCacheNode_279D0* lruPrev;  // 0x8
    sCacheNode_279D0* next;     // 0xC
};

struct sCache_279D0 {
    int pad0;
    sCacheNode_279D0* lru;      // 0x4
    sCacheNode_279D0** buckets; // 0x8
    unsigned int count;         // 0xC
};

static inline int func_003279D0_less(unsigned int a, unsigned int b) { return a < b; }

extern "C" void func_003279D0(sCache_279D0* self, void* src, sCacheNode_279D0** out)
{
    unsigned int key = *(unsigned int*)((char*)src + 0x150);
    sCacheNode_279D0* n = self->buckets[key % self->count];
    while (n != 0 && !func_003279D0_less(key, n->key)) {
        if (n->key == key) {
            func_00327AC0((sFwdDiffList*)self, (sFwdDiffLink*)n);
            *out = n;
            return;
        }
        n = n->next;
    }
    n = self->lru;
    func_00327B30(self, n);
    n->key = key;
    func_00327BB0((sFwdDiffTable*)self, (sFwdDiffNode*)n);
    self->lru = n->lruNext;
    func_00327C00(self, src, n);
    *out = n;
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00327AC0);
#ifdef SKIP_ASM
struct sFwdDiffLink {
    int pad0;
    sFwdDiffLink* next;   // 0x4
    sFwdDiffLink* prev;   // 0x8
};

struct sFwdDiffList {
    int pad0;
    sFwdDiffLink* head;   // 0x4
};

extern "C" void func_00327AC0(sFwdDiffList* list, sFwdDiffLink* n)
{
    if (list->head == n) {
        list->head = n->next;
        return;
    }
    if (list->head->prev == n) {
        return;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    n->prev = list->head->prev;
    n->next = list->head;
    list->head->prev->next = n;
    list->head->prev = n;
}
#endif

INCLUDE_ASM("intersect/aifwddiff", func_00327B30);

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00327BB0);
#ifdef SKIP_ASM
struct sFwdDiffNode {
    unsigned int key;
    int pad4;
    int pad8;
    sFwdDiffNode* next;
};

struct sFwdDiffTable {
    int pad0;
    int pad4;
    sFwdDiffNode** buckets;
    unsigned int count;
};

extern "C" void func_00327BB0(sFwdDiffTable* table, sFwdDiffNode* node)
{
    unsigned int key = node->key;
    sFwdDiffNode** link = &table->buckets[key % table->count];
    for (;;) {
        sFwdDiffNode* cur = *link;
        if (cur == 0 || key < cur->key) {
            *link = node;
            node->next = cur;
            return;
        }
        link = &cur->next;
    }
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00327C00);
#ifdef SKIP_ASM
extern "C" void func_00391418(void* t, void* a);
extern "C" void func_00327C68(void* self, void* a);
extern "C" void func_003914F8(void* t);
extern "C" void func_00391480(void* t, void* a);
struct sGp2930 { int a, b; };
extern sGp2930 D_004A5A20; // placeholder: target is a raw $gp+0x2930 reference

extern "C" void func_00327C00(void* self, void* a1, void* a2)
{
    sGp2930* t = &D_004A5A20;
    func_00391418(t, (char*)a1 + 0x40);
    func_00327C68(self, a2);
    func_003914F8(t);
    func_00391480(t, (char*)a2 + 0x10);
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00327C68);
#ifdef SKIP_ASM
extern "C" void func_00327C68(void* self, void* a)
{
    float* p = (float*)((char*)a + 0x650);
    int n = 0x50;
    do {
        p[0] = 10000000000.0f;
        p[4] = 10000000000.0f;
        p[8] = 10000000000.0f;
        p += 16;
    } while (n-- > 0);
    p = (float*)((char*)a + 0x1A90);
    n = 8;
    do {
        p[0] = 10000000000.0f;
        p[4] = 10000000000.0f;
        p[8] = 10000000000.0f;
        p += 16;
    } while (n-- > 0);
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00327CC8);
#ifdef SKIP_ASM
struct sQuad_27CC8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBlock_27CC8 {
    int d[32];
};

struct sFwdDiff_27CC8 {
    sQuad_27CC8 m[8];       // 0x00
    sQuad_27CC8 q;          // 0x80
    char pad_0x90[0x8];
    sBlock_27CC8* blkp;     // 0x98
    char pad_0x9C[0x24];
    sBlock_27CC8 blk;       // 0xC0
};

extern "C" sFwdDiff_27CC8* func_00327CC8(sFwdDiff_27CC8* self, sFwdDiff_27CC8* src)
{
    int i;
    for (i = 0; i < 8; i++) {
        self->m[i] = src->m[i];
    }
    self->q = src->q;
    self->blk = src->blk;
    self->blkp = &self->blk;
    return self;
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00327DA8);
#ifdef SKIP_ASM
extern "C" void func_003E6574(void* dst, void* src, int n);

extern "C" int func_00327DA8(sFwdDiff_27CC8* self, char* buf, int a2)
{
    if (buf == 0) {
        return 0;
    }
    self->blk.d[0] = a2;
    self->blk.d[1] = 0;
    self->blkp = &self->blk;
    self->blk.d[4] = 1;
    int len0;
    int len1;
    func_003E6574(&len0, buf, 4);
    func_003E6574(&len1, buf + 4, 4);
    func_003E6574((char*)self->blkp + 0x8, buf + 0x8, 4);
    func_003E6574((char*)self->blkp + 0xC, buf + 0xC, 4);
    func_003E6574((char*)self->blkp + 0x14, buf + 0x10, 0xC);
    func_003E6574((char*)self->blkp + 0x2C, buf + 0x1C, 0xC);
    func_003E6574((char*)self->blkp + 0x38, buf + 0x28, 0x24);
    func_003E6574((char*)self->blkp + 0x5C, buf + 0x4C, 0x24);
    char* p = buf + 0x70;
    *(char**)((char*)self->blkp + 0x20) = p;
    p += (*(int*)((char*)self->blkp + 0xC) + 1) * 0xC;
    *(char**)((char*)self->blkp + 0x24) = p;
    p += len1;
    p += len0;
    char* b = (char*)self->blkp;
    if (*(int*)(b + 0x8) != 0) {
        *(char**)(b + 0x28) = 0;
    } else {
        *(char**)(b + 0x28) = *(char**)(b + 0x24);
    }
    sQuad_27CC8 v;
    char* c = (char*)self->blkp;
    v.x = *(float*)(c + 0x14);
    v.y = *(float*)(c + 0x18);
    v.z = *(float*)(c + 0x1C);
    v.w = 1.0f;
    self->q = v;
    return p - buf;
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00327F18);
#ifdef SKIP_ASM
extern "C" int func_0032DF28(void* self);
extern "C" int func_0032CDB0(void* self, void* pos, void* out, int a3, int a4, int a5, int a6, float radius);

struct sSphere_27F18 {
    float pos[4];
    float radius;
    int pad[3];
};
struct sShape_27F18 {
    char pad[0x10];
    float pos[4];           // 0x10
    float radius;           // 0x20
    int pad24[2];
    int count;              // 0x2C
    sSphere_27F18 subs[1];  // 0x30
};

extern "C" int func_00327F18(void* self, sShape_27F18* shape, int a2, int a3)
{
    void* m = *(void**)((char*)self + 0x98);
    if (*(int*)((char*)m + 8) != 0) {
        *(int*)(*(char**)((char*)self + 0x98) + 0x28) = func_0032DF28(m);
    }
    if (func_0032CDB0(self, shape->pos, (char*)self + 0x80, 0, 0, a2, a3, shape->radius) == 0) {
        return 0;
    }
    if (shape->count == 0) {
        return 1;
    }
    for (int i = 0; i < shape->count; i++) {
        if (func_0032CDB0(self, shape->subs[i].pos, (char*)self + 0x80, 0, 0, a2, a3, shape->subs[i].radius) != 0) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00328030);
#ifdef SKIP_ASM
extern "C" float func_0032C590(void* self);
extern "C" int func_0032CA78(void* self, void* a1, void* a2, void* a3, void* v, void* a5, void* a6);

struct sVec4_28030 {
    float x, y, z, w;
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec4_28030 vu0Sub_28030(const sVec4_28030& a, const sVec4_28030& b)
{
    sVec4_28030 r;
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
static inline float vu0Dot_28030(const sVec4_28030& a, const sVec4_28030& b)
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
static inline sVec4_28030 vu0Scale_28030(const sVec4_28030& v, float s)
{
    sVec4_28030 r;
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

extern "C" int func_00328030(void* self, sVec4_28030* p, void* a2, void* a3, sVec4_28030* dir, void* a5, void* a6)
{
    float dot;
    {
        sVec4_28030 d = vu0Sub_28030(*(sVec4_28030*)((char*)self + 0x80), *p);
        dot = vu0Dot_28030(*dir, d);
    }
    if (func_0032C590(self) < __builtin_fabsf(dot)) {
        return 0;
    }
    if (dot < 0.0f) {
        sVec4_28030 nd = vu0Scale_28030(*dir, -1.0f);
        return func_0032CA78(self, p, a2, a3, &nd, a5, a6);
    }
    return func_0032CA78(self, p, a2, a3, dir, a5, a6);
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00328170);
#ifdef SKIP_ASM
extern "C" void func_003281D0(void *, int, void *, int, int);

extern "C" void func_00328170(void *arg0) {
    void *temp_4;

    temp_4 = (*(void **)((char*)(arg0) + (0x98)));
    if ((*(int *)((char*)(temp_4) + (8))) != 0) {
        (*(int *)((char*)((*(void **)((char*)(arg0) + (0x98)))) + (0x28))) = func_0032DF28(temp_4);
    }
    func_003281D0(arg0, (*(int *)((char*)((*(void **)((char*)(arg0) + (0x98)))) + (0xC))), (char*)arg0 + 0x80, 0, 0);
}
#endif

INCLUDE_ASM("intersect/aifwddiff", func_003281D0);
//100%
INCLUDE_ASM("intersect/aifwddiff", func_00328360);
#ifdef SKIP_ASM
struct sCell_00328360 {
    int level;
    int x, y, z;
};
struct sBox_00328360 {
    float minx, miny, minz, pad;
    float maxx, maxy, maxz;
};

extern "C" int func_00328360(sCell_00328360* c, sBox_00328360* b)
{
    union {
        int i;
        float f;
    } s;
    s.i = (c->level + 0x7F) << 23;
    float scale = s.f;
    float x0 = ((float)c->x - 0.2f) * scale;
    if (b->maxx < x0) {
        return 1;
    }
    float y0 = ((float)c->y - 0.2f) * scale;
    if (b->maxy < y0) {
        return 1;
    }
    float z0 = ((float)c->z - 0.2f) * scale;
    if (b->maxz < z0) {
        return 1;
    }
    float x1 = ((float)(c->x + 1) + 0.2f) * scale;
    if (x1 < b->minx) {
        return 1;
    }
    float y1 = ((float)(c->y + 1) + 0.2f) * scale;
    if (y1 < b->miny) {
        return 1;
    }
    float z1 = ((float)(c->z + 1) + 0.2f) * scale;
    if (z1 < b->minz) {
        return 1;
    }
    if (x1 < b->maxx) {
        return 2;
    }
    if (y1 < b->maxy) {
        return 2;
    }
    if (z1 < b->maxz) {
        return 2;
    }
    if (b->minx < x1) {
        return 2;
    }
    if (b->miny < y1) {
        return 2;
    }
    if (b->miny < y1) {
        return 2;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_003284B8);
#ifdef SKIP_ASM
void operator_delete(int* p);

struct sItem_003284B8 {
    sItem_003284B8* next;   // 0x0
    sItem_003284B8* prev;   // 0x4
};
struct sList_003284B8 {
    sItem_003284B8* head;
    void remove(sItem_003284B8* it)
    {
        if (it->next) it->next->prev = it->prev;
        if (it->prev) {
            it->prev->next = it->next;
        } else {
            head = it->next;
        }
    }
};
struct sNode_003284B8 {
    sNode_003284B8* child[2][2][2];     // 0x00
    sList_003284B8 lists[3];            // 0x20
    int empty()
    {
        if (child[0][0][0] || child[0][0][1] || child[0][1][0] || child[0][1][1] || child[1][0][0] ||
            child[1][0][1] || child[1][1][0] || child[1][1][1]) {
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if (lists[i].head) return 0;
        }
        return 1;
    }
};
struct sCell_003284B8 {
    int level;
    int x, y, z;
};

extern "C" void func_003284B8(sNode_003284B8* node, int idx, sItem_003284B8* item, const sCell_003284B8* target,
                              const sCell_003284B8* cur)
{
    int lv = cur->level;
    if (target->level == lv) {
        node->lists[idx].remove(item);
        return;
    }
    int sh = lv - target->level - 1;
    int dx = (target->x >> sh) - cur->x * 2;
    int dy = (target->y >> sh) - cur->y * 2;
    int dz = (target->z >> sh) - cur->z * 2;
    sCell_003284B8 c;
    c.x = cur->x * 2 + dx;
    c.level = --lv;
    c.y = cur->y * 2 + dy;
    c.z = cur->z * 2 + dz;
    sNode_003284B8** ch = &node->child[dx][dy][dz];
    func_003284B8(*ch, idx, item, target, &c);
    if ((*ch)->empty()) {
        operator_delete((int*)*ch);
        *ch = 0;
    }
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00328660);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is the game's operator new(size, tag, flags, align).
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_003E6448(void* p, int v, int n);
extern char D_004A3FC0[];

struct sItem_00328660 {
    sItem_00328660* next;   // 0x0
    sItem_00328660* prev;   // 0x4
};
struct sList_00328660 {
    sItem_00328660* head;
    sList_00328660() : head(0) {}
    void push(sItem_00328660* it)
    {
        if (head) head->prev = it;
        it->next = head;
        it->prev = 0;
        head = it;
    }
};
struct sNode_00328660 {
    sNode_00328660* child[2][2][2];     // 0x00
    sList_00328660 lists[3];            // 0x20
    sNode_00328660() { func_003E6448(child, 0, sizeof(child)); }
};
struct sCell_00328660 {
    int level;
    int x, y, z;
};

extern "C" void func_00328660(sNode_00328660* node, int idx, sItem_00328660* item, sCell_00328660* target, const sCell_00328660* at)
{
    sCell_00328660 cur = *at;
    while (cur.level != target->level) {
        int sh = cur.level - target->level - 1;
        cur.level--;
        int dx = (target->x >> sh) - cur.x * 2;
        int dy = (target->y >> sh) - cur.y * 2;
        int dz = (target->z >> sh) - cur.z * 2;
        cur.x = cur.x * 2 + dx;
        cur.y = cur.y * 2 + dy;
        cur.z = cur.z * 2 + dz;
        sNode_00328660** c = &node->child[dx][dy][dz];
        if (*c == 0) {
            *c = new (D_004A3FC0, 0x20000000, 0) sNode_00328660;
        }
        node = *c;
    }
    node->lists[idx].push(item);
}
#endif

INCLUDE_ASM("intersect/aifwddiff", func_00328808);

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00328C20);
#ifdef SKIP_ASM
struct sNode_8C20 {
    sNode_8C20* child[2][2][2];         // 0x00
    sList_00328660 lists[3];            // 0x20
    sNode_8C20() {}
    sNode_8C20(sNode_8C20* c, const sCell_00328660& cc, const sCell_00328660& pc)
    {
        int dx = cc.x - pc.x * 2;
        int dy = cc.y - pc.y * 2;
        int dz = cc.z - pc.z * 2;
        func_003E6448(child, 0, sizeof(child));
        child[dx][dy][dz] = c;
    }
};

struct sRoot_8C20 {
    sCell_00328660 cell;            // 0x00
    sNode_8C20* node;               // 0x10
};

static inline int Contains_8C20(const sCell_00328660& a, const sCell_00328660& b)
{
    int d = a.level - b.level;
    if (d < 0) {
        return 0;
    }
    if (d == 0) {
        return b.x == a.x && b.y == a.y && b.z == a.z;
    }
    return (b.x >> d) == a.x && (b.y >> d) == a.y && (b.z >> d) == a.z;
}

static inline sCell_00328660 Parent_8C20(const sCell_00328660& c)
{
    sCell_00328660 r;
    r.level = c.level + 1;
    r.x = c.x >> 1;
    r.y = c.y >> 1;
    r.z = c.z >> 1;
    return r;
}

extern "C" void func_00328C20(sRoot_8C20* root, int idx, sItem_00328660* item, sCell_00328660* cell)
{
    sNode_8C20** pn = &root->node;
    if (root->node == 0) {
        root->cell = *cell;
        sNode_8C20* n = new (D_004A3FC0, 0x20000000, 0) sNode_8C20;
        func_003E6448(n->child, 0, sizeof(n->child));
        *pn = n;
        root->node->lists[idx].push(item);
        return;
    }
    while (!Contains_8C20(root->cell, *cell)) {
        sCell_00328660 nc = Parent_8C20(root->cell);
        sNode_8C20* n = new (D_004A3FC0, 0x20000000, 0) sNode_8C20(root->node, root->cell, nc);
        root->cell = nc;
        root->node = n;
    }
    func_00328660((sNode_00328660*)root->node, idx, item, cell, &root->cell);
}
#endif

//100%
INCLUDE_ASM("intersect/aifwddiff", func_00328F28);
#ifdef SKIP_ASM
struct sVec4_8F28 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBox_8F28 {
    sVec4_8F28 min;
    sVec4_8F28 max;
};

struct sCell_8F28 {
    int level;
    int x, y, z;
};

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sVec4_8F28 vu0Sub_8F28(const sVec4_8F28& a, const sVec4_8F28& b)
{
    sVec4_8F28 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sVec4_8F28 vu0Add_8F28(const sVec4_8F28& a, const sVec4_8F28& b)
{
    sVec4_8F28 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sVec4_8F28 vu0Scale_8F28(const sVec4_8F28& v, float s)
{
    sVec4_8F28 r;
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

// PORT: PS2 float->int->float round trip kept in the FPU (cvt.w.s / mfc1 / cvt.s.w).
static inline int Floor_8F28(float f)
{
    float t;
    int q;
    __asm__("cvt.w.s %0, %2\n\tmfc1 %1, %0\n\tcvt.s.w %0, %0" : "=&f"(t), "=r"(q) : "f"(f));
    if (f < t) {
        q--;
    }
    return q;
}

static inline sCell_8F28 Parent_8F28(const sCell_8F28& c)
{
    sCell_8F28 r;
    r.level = c.level + 1;
    r.x = c.x >> 1;
    r.y = c.y >> 1;
    r.z = c.z >> 1;
    return r;
}

extern "C" void func_00328F28(sCell_8F28* c, sBox_8F28* b)
{
    sVec4_8F28 size = vu0Sub_8F28(b->max, b->min);
    sVec4_8F28 center = vu0Add_8F28(b->min, vu0Scale_8F28(size, 0.5f));
    float m = size.x;
    if (m < size.y) {
        m = size.y;
    }
    if (m < size.z) {
        m = size.z;
    }
    union {
        float f;
        int i;
    } u;
    u.f = m * 0.7142857313156128f;
    c->level = ((u.i >> 23) & 0xFF) - 0x7F;
    if (c->level < 11) {
        c->level = 11;
    }
    union {
        int i;
        float f;
    } s;
    s.i = (c->level + 0x7F) << 23;
    float scale = s.f;
    c->x = Floor_8F28(center.x / scale);
    c->y = Floor_8F28(center.y / scale);
    c->z = Floor_8F28(center.z / scale);
    for (;;) {
        s.i = (c->level + 0x7F) << 23;
        scale = s.f;
        int ok = 0;
        if (((float)c->x - 0.2f) * scale <= b->min.x && ((float)c->y - 0.2f) * scale <= b->min.y && ((float)c->z - 0.2f) * scale <= b->min.z
            && b->max.x <= ((float)(c->x + 1) + 0.2f) * scale && b->max.y <= ((float)(c->y + 1) + 0.2f) * scale && b->max.z <= ((float)(c->z + 1) + 0.2f) * scale) {
            ok = 1;
        }
        if (ok) {
            break;
        }
        *c = Parent_8F28(*c);
    }
}
#endif

INCLUDE_ASM("intersect/aifwddiff", func_003291E0);

INCLUDE_ASM("intersect/aifwddiff", func_00329590);

