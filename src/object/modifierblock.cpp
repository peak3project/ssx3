#include "common.h"

struct sBoundBoxTarget {
    char pad_0x00[0x68];
    short field_0x68;
    char pad_0x6A[2];
    void (*fnBoundBox)(void*); // 0x6C
    char pad_0x70[0x78 - 0x70];
    short field_0x78;
    char pad_0x7A[2];
    void (*fnRadius)(void*); // 0x7C
};

struct sBoundBoxNode {
    sBoundBoxTarget* target; // 0x0
};

struct tModifierBlock {
    sBoundBoxNode* node; // 0x0
    int field_0x4;
    int field_0x8;
    int field_0xC;
    int field_0x10;
    int field_0x14;
    void* field_0x18;
    int field_0x1C;
    int field_0x20;
    void* field_0x24;
};

extern void* D_00491340[16];
extern void* D_00491200[16];

//100%
INCLUDE_ASM("object/modifierblock", tModifierBlock_tModifierBlock__FP14tModifierBlock);
#ifdef SKIP_ASM
tModifierBlock* tModifierBlock_tModifierBlock(tModifierBlock* self)
{
    self->field_0x18 = D_00491340;
    self->field_0x24 = D_00491200;
    self->field_0x10 = 0;
    self->field_0x14 = 0;
    self->field_0x1C = 0;
    self->field_0x20 = 0;
    self->node = 0;
    self->field_0x4 = 0;
    self->field_0x8 = 0;
    self->field_0xC = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352AE8);
#ifdef SKIP_ASM
extern "C" void func_003530D0(tModifierBlock* self);
extern "C" void func_00353118(tModifierBlock* self);
extern "C" void func_00353150(tModifierBlock* self);
extern "C" void func_00353188(tModifierBlock* self);
extern "C" void func_003531D0(void* self);
extern "C" void func_00353300(void* self, unsigned int mask);
extern "C" void func_0035B6D0(void* self);
extern "C" void func_00345760(void* self);
void operator_delete(int* ptr);

extern "C" void func_00352AE8(tModifierBlock* self, int flags)
{
    func_003530D0(self);
    func_00353118(self);
    func_00353150(self);
    func_00353188(self);
    func_003531D0(self);
    func_00353300(self, 0xFFFFFFFF);
    self->field_0x24 = D_00491200;
    func_0035B6D0(&self->field_0x1C);
    self->field_0x18 = D_00491340;
    func_00345760(&self->field_0x10);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352B88);
#ifdef SKIP_ASM
struct sMbVEntryI {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_00352B88(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryI* vt = *(sMbVEntryI**)node;
        return vt[12].fn((char*)node + vt[12].delta);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", tModifierBlock_setBoundBox__FP14tModifierBlock);
#ifdef SKIP_ASM
struct sMbVEntry {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

// PORT: the symbol's mangling says one parameter, but the body passes $5 through
// to the virtual call untouched, so the real function takes a second argument.
void tModifierBlock_setBoundBox_impl(tModifierBlock* self, void* box) __asm__("tModifierBlock_setBoundBox__FP14tModifierBlock");

void tModifierBlock_setBoundBox_impl(tModifierBlock* self, void* box)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntry* vt = *(sMbVEntry**)node;
        vt[13].fn((char*)node + vt[13].delta, box);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352BF8);
#ifdef SKIP_ASM
struct sMbVEntryF {
    short delta;
    short index;
    float (*fn)(void*);
};

extern "C" float func_00352BF8(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryF* vt = *(sMbVEntryF**)node;
        return vt[14].fn((char*)node + vt[14].delta);
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", tModifierBlock_setRadius__FP14tModifierBlock);
#ifdef SKIP_ASM
void tModifierBlock_setRadius(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sBoundBoxTarget* target = node->target;
        target->fnRadius((char*)node + target->field_0x78);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352C70);
#ifdef SKIP_ASM
struct sMbVEntryV2C70 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sMbVEntryI2C70 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sMbChild2C70 {
    int field_0x0;
    sMbVEntryV2C70* vt;     // 0x4
};

extern "C" void func_0035F7D0(int h);
extern "C" void func_0035F410(int h);
extern "C" void func_00353188(tModifierBlock* self);

extern "C" void func_00352C70(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryV2C70* vt = *(sMbVEntryV2C70**)node;
        vt[2].fn((char*)node + vt[2].delta);
    }
    if (self->field_0x4 != 0) {
        func_0035F7D0(self->field_0x4);
    }
    if (self->field_0x8 != 0) {
        func_0035F410(self->field_0x8);
    }
    sMbChild2C70* c = (sMbChild2C70*)self->field_0xC;
    if (c != 0) {
        c->vt[2].fn((char*)c + c->vt[2].delta);
        c = (sMbChild2C70*)self->field_0xC;
        sMbVEntryI2C70* vt2 = (sMbVEntryI2C70*)c->vt;
        if (vt2[4].fn((char*)c + vt2[4].delta) == 0) {
            func_00353188(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352D20);
#ifdef SKIP_ASM
struct sMbVEntryV2D20 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sMbLink2D20 {
    sMbLink2D20* next;      // 0x0
    int field_0x4;
    sMbVEntryV2D20* vt;     // 0x8
};

extern "C" void func_00352D20(tModifierBlock* self)
{
    sMbLink2D20* h = *(sMbLink2D20**)&self->field_0x10;
    if (h != 0) {
        sMbLink2D20* p = h;
        do {
            sMbLink2D20* next = p->next;
            p->vt[5].fn((char*)p + p->vt[5].delta);
            p = next;
        } while (p != 0);
    }
    h = *(sMbLink2D20**)&self->field_0x1C;
    if (h != 0) {
        sMbLink2D20* p = h;
        do {
            sMbLink2D20* next = p->next;
            p->vt[3].fn((char*)p + p->vt[3].delta);
            p = next;
        } while (p != 0);
    }
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryV2D20* vt = *(sMbVEntryV2D20**)node;
        vt[4].fn((char*)node + vt[4].delta);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352DD0);
#ifdef SKIP_ASM
struct sMbVEntryV2DD0 {
    short delta;
    short index;
    void (*fn)(void*);
};


extern "C" void func_00352DD0(tModifierBlock* self)
{
    if (self->field_0x10 != 0) {
        void* p = (void*)self->field_0x10;
        void* next;
        do {
            next = *(void**)p;
            sMbVEntryV2DD0* vt = *(sMbVEntryV2DD0**)((char*)p + 0x8);
            vt[6].fn((char*)p + vt[6].delta);
            p = next;
        } while (p != 0);
    }
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryV2DD0* vt = *(sMbVEntryV2DD0**)node;
        vt[11].fn((char*)node + vt[11].delta);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352E50);
#ifdef SKIP_ASM
extern "C" int func_00352E50(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryI* vt = *(sMbVEntryI**)node;
        if (vt[17].fn((char*)node + vt[17].delta) != 0) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352E98);
#ifdef SKIP_ASM
class sMbVtbl_2E98 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

extern "C" void func_00352E98(sMbVtbl_2E98** self)
{
    sMbVtbl_2E98* o = *self;
    if (o != 0) {
        o->v3();
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352ED0);
#ifdef SKIP_ASM
extern "C" int func_00352ED0(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryI* vt = *(sMbVEntryI**)node;
        return vt[6].fn((char*)node + vt[6].delta);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352F08);
#ifdef SKIP_ASM
struct sMbVEntryV {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00352F08(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryV* vt = *(sMbVEntryV**)node;
        vt[7].fn((char*)node + vt[7].delta);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00352F40);
#ifdef SKIP_ASM
struct sMbVEntryP2F40 {
    short delta;
    short index;
    void (*fn)(void*, int, float);
};

struct sMbChild2F40 {
    int field_0x0;
    sMbVEntryP2F40* vt;     // 0x4
};

struct sMbLink2F40 {
    sMbLink2F40* next;      // 0x0
    int field_0x4;
    sMbVEntryP2F40* vt;     // 0x8
};

extern "C" void func_0035FB30(void* self, int id, float v);
extern "C" void func_0035F598(void* self, int id, float v);

extern "C" void func_00352F40(tModifierBlock* self, int id, float v)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryP2F40* vt = *(sMbVEntryP2F40**)node;
        vt[5].fn((char*)node + vt[5].delta, id, v);
    }
    if (self->field_0x4 != 0) {
        func_0035FB30((void*)self->field_0x4, id, v);
    }
    if (self->field_0x8 != 0) {
        func_0035F598((void*)self->field_0x8, id, v);
    }
    sMbChild2F40* c = (sMbChild2F40*)self->field_0xC;
    if (c != 0) {
        c->vt[3].fn((char*)c + c->vt[3].delta, id, v);
    }
    sMbLink2F40* h = *(sMbLink2F40**)&self->field_0x10;
    if (h != 0) {
        sMbLink2F40* p = h;
        do {
            sMbLink2F40* next = p->next;
            p->vt[7].fn((char*)p + p->vt[7].delta, id, v);
            p = next;
        } while (p != 0);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353020);
#ifdef SKIP_ASM
struct sMbVEntryP3020 {
    short delta;
    short index;
    void* (*fn)(void*);
};

struct sMbVEntryVII3020 {
    short delta;
    short index;
    void (*fn)(void*, int, int);
};

extern "C" void func_00353020(tModifierBlock* self, int a1, int a2)
{
    sBoundBoxNode* node = self->node;
    void* obj;
    if (node != 0) {
        sMbVEntryP3020* vt = *(sMbVEntryP3020**)node;
        obj = vt[25].fn((char*)node + vt[25].delta);
    } else {
        obj = 0;
    }
    if (obj != 0) {
        sMbVEntryVII3020* vt2 = *(sMbVEntryVII3020**)((char*)obj + 0xC);
        vt2[43].fn((char*)obj + vt2[43].delta, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353098);
#ifdef SKIP_ASM
extern "C" void func_00353098(tModifierBlock* self, void* arg)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntry* vt = *(sMbVEntry**)node;
        vt[22].fn((char*)node + vt[22].delta, arg);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_003530D0);
#ifdef SKIP_ASM
struct sMbVEntryDel {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_003530D0(tModifierBlock* self)
{
    sBoundBoxNode* node = self->node;
    if (node != 0) {
        sMbVEntryDel* vt = *(sMbVEntryDel**)node;
        vt[1].fn((char*)node + vt[1].delta, 3);
        self->node = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353118);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00353118(tModifierBlock* self)
{
    int** p = (int**)((char*)self + 0x4);
    if (*p != 0) {
        operator_delete(*p);
        *p = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353150);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_00353150(tModifierBlock* self)
{
    int** p = (int**)((char*)self + 0x8);
    if (*p != 0) {
        operator_delete(*p);
        *p = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353188);
#ifdef SKIP_ASM
struct sMbVEntryDel2 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00353188(tModifierBlock* self)
{
    void* obj = *(void**)((char*)self + 0xC);
    if (obj != 0) {
        sMbVEntryDel2* vt = *(sMbVEntryDel2**)((char*)obj + 0x4);
        vt[1].fn((char*)obj + vt[1].delta, 3);
        *(void**)((char*)self + 0xC) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_003531D0);
#ifdef SKIP_ASM
struct sModBlockDtorVEntry {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sModBlockLink {
    sModBlockLink* next;          // 0x0
    int field_0x4;
    sModBlockDtorVEntry* vt;      // 0x8
};

extern "C" void func_003531D0(void* self)
{
    sModBlockLink* head = *(sModBlockLink**)((char*)self + 0x10);
    if (head != 0) {
        sModBlockLink* p = head;
        do {
            sModBlockLink* next = p->next;
            if (p != 0) {
                p->vt[1].fn((char*)p + p->vt[1].delta, 3);
            }
            p = next;
        } while (p != 0);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353228);
#ifdef SKIP_ASM
struct sModBlockVEntry3228 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sModBlockLink3228 {
    sModBlockLink3228* next;      // 0x0
    int field_0x4;
    sModBlockVEntry3228* vt;      // 0x8
};

extern "C" void func_00353228(void* self)
{
    sModBlockLink3228* head = *(sModBlockLink3228**)((char*)self + 0x10);
    if (head != 0) {
        sModBlockLink3228* p = head;
        do {
            sModBlockLink3228* next = p->next;
            p->vt[3].fn((char*)p + p->vt[3].delta);
            p = next;
        } while (p != 0);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353278);
#ifdef SKIP_ASM
struct sModBlockVEntry3278 {
    short delta;
    short index;
    void* fn;
};

struct sModBlockLink3278 {
    sModBlockLink3278* next;      // 0x0
    int field_0x4;
    sModBlockVEntry3278* vt;      // 0x8
};

extern "C" void func_00353278(void* self)
{
    sModBlockLink3278* head = *(sModBlockLink3278**)((char*)self + 0x10);
    if (head != 0) {
        sModBlockLink3278* p = head;
        do {
            sModBlockLink3278* next = p->next;
            if (((int (*)(void*))p->vt[2].fn)((char*)p + p->vt[2].delta) == 3) {
                if (p != 0) {
                    ((void (*)(void*, int))p->vt[1].fn)((char*)p + p->vt[1].delta, 3);
                }
            }
            p = next;
        } while (p != 0);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353300);
#ifdef SKIP_ASM
struct sModBlockDtorVEntry3300 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sModBlockLink3300 {
    sModBlockLink3300* next;          // 0x0
    int field_0x4;
    sModBlockDtorVEntry3300* vt;      // 0x8
    char pad_0xC[0x30 - 0xC];
    unsigned int id;                       // 0x30
};

extern "C" void func_00353300(void* self, unsigned int id)
{
    sModBlockLink3300* head = *(sModBlockLink3300**)((char*)self + 0x1C);
    if (head == 0) return;
    sModBlockLink3300* p = head;
    if (~id) {
    loop:
        if (p == 0) return;
        if (p->id == id) {
            p->vt[1].fn((char*)p + p->vt[1].delta, 3);
            return;
        }
        p = p->next;
        goto loop;
    } else {
        do {
            sModBlockLink3300* next = p->next;
            if (p != 0) {
                p->vt[1].fn((char*)p + p->vt[1].delta, 3);
            }
            p = next;
        } while (p != 0);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353398);
#ifdef SKIP_ASM
struct sMbVEntryV3398 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00345720(void* pool, void* item);

extern "C" void func_00353398(void* self, void* list)
{
    void* p = *(void**)list;
    while (p != 0) {
        void* next = *(void**)p;
        sMbVEntryV3398* vt = *(sMbVEntryV3398**)((char*)p + 0x8);
        vt[3].fn((char*)p + vt[3].delta);
        func_00345720((char*)self + 0x10, p);
        p = next;
    }
    *(void**)list = 0;
    *(void**)((char*)list + 0x4) = 0;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353418);
#ifdef SKIP_ASM
struct sModifierLink {
    sModifierLink* next; // 0x0
    char pad_0x4[0x30 - 0x4];
    int id;              // 0x30
};

extern "C" int func_00353418(void* self, int id)
{
    sModifierLink* p = *(sModifierLink**)((char*)self + 0x1c);
    while (p != 0) {
        if (p->id == id) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353448);
#ifdef SKIP_ASM
extern "C" void func_0035F688(void* self, void* stream);
extern "C" void func_0035FD98(void* self, void* stream);

struct sVE_353448 { short delta; short index; int (*fn)(void*); };
struct sVEv_353448 { short delta; short index; void (*fn)(void*, void*); };
struct sVEw_353448 { short delta; short index; void (*fn)(void*, void*, int); };

struct sHdr_353448 {
    int flags;
    int a;
    int b;
    int count1;
    int count2;
    char ids[32];
};


static inline int VCall0_353448(char* o, int voff, int slot)
{
    sVE_353448* e = &(*(sVE_353448**)(o + voff))[slot];
    return e->fn(o + e->delta);
}

static inline void VCall1_353448(char* o, int voff, int slot, void* arg)
{
    sVEv_353448* e = &(*(sVEv_353448**)(o + voff))[slot];
    e->fn(o + e->delta, arg);
}

extern "C" void func_00353448(char* self, char* stream)
{
    sHdr_353448 h;
    h.flags = 0;
    h.b = 0;
    h.a = 0;
    h.count1 = 0;
    h.count2 = 0;
    for (int i = 0; i < 32; i++) {
        h.ids[i] = 0;
    }
    char* o0 = *(char**)(self + 0x0);
    if (o0 != 0) {
        h.flags |= 1;
        h.a = VCall0_353448(o0, 0, 26);
    }
    if (*(void**)(self + 0x4) != 0) {
        h.flags |= 2;
    }
    if (*(void**)(self + 0x8) != 0) {
        h.flags |= 4;
    }
    char* oC = *(char**)(self + 0xC);
    if (oC != 0) {
        h.flags |= 8;
        h.b = VCall0_353448(oC, 4, 5);
    }
    for (char* p = *(char**)(self + 0x10); p; p = *(char**)p) {
        h.ids[h.count1++] = VCall0_353448(p, 8, 2);
    }
    if (h.count1 > 0) {
        h.flags |= 0x10;
    }
    for (char* p = *(char**)(self + 0x1C); p; p = *(char**)p) {
        h.count2++;
    }
    if (h.count2 > 0) {
        h.flags |= 0x20;
    }
    {
        sVEw_353448* e = &(*(sVEw_353448**)stream)[1];
        e->fn(stream + e->delta, &h, 0x34);
    }
    char* w0 = *(char**)(self + 0x0);
    if (w0 != 0) {
        VCall1_353448(w0, 0, 27, stream);
    }
    if (*(void**)(self + 0x4) != 0) {
        func_0035FD98(*(void**)(self + 0x4), stream);
    }
    if (*(void**)(self + 0x8) != 0) {
        func_0035F688(*(void**)(self + 0x8), stream);
    }
    char* wC = *(char**)(self + 0xC);
    if (wC != 0) {
        VCall1_353448(wC, 4, 6, stream);
    }
    if (h.count1 > 0) {
        for (char* p = *(char**)(self + 0x10); p; p = *(char**)p) {
            VCall1_353448(p, 8, 4, stream);
        }
    }
    if (h.count2 > 0) {
        for (char* p = *(char**)(self + 0x1C); p; p = *(char**)p) {
            VCall1_353448(p, 8, 2, stream);
        }
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", tModifierBlock_readFromReplayFrame);
#ifdef SKIP_ASM
struct sMbStreamVEntry36D8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sMbStream36D8 {
    sMbStreamVEntry36D8* vt;
};

struct sMbReplayHdr36D8 {
    unsigned int flags;      // 0x00
    int type;                // 0x04
    int kind;                // 0x08
    int numA;                // 0x0C
    int numB;                // 0x10
    signed char typesA[32];  // 0x14
};

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cSplineModifier_cSplineModifier(void* self, sMbStream36D8* s);
extern "C" void* func_0035A118(void* self, sMbStream36D8* s);
extern "C" void* func_00357090(void* self, sMbStream36D8* s);
extern "C" void* func_00356F68(void* self, sMbStream36D8* s);
extern "C" void* func_0035DF70(void* self, sMbStream36D8* s);
extern "C" void* func_00357358(void* self, sMbStream36D8* s);
extern "C" void* func_00357798(void* self, sMbStream36D8* s);
extern "C" void* func_0035F788(void* self, sMbStream36D8* s);
extern "C" void* func_0035F1A8(void* self, sMbStream36D8* s);
extern "C" void* func_00342808(void* self, sMbStream36D8* s);
extern "C" void* func_003459A8(void* self, sMbStream36D8* s);
extern "C" void* func_00345D80(void* self, sMbStream36D8* s);
extern "C" void* func_003461C0(void* self, sMbStream36D8* s);
extern "C" void* func_0035BA88(void* self, sMbStream36D8* s);
extern "C" void func_00345720(void* pool, void* item);
extern "C" void func_0035B690(void* list, void* item);

extern const char D_0048E8D0[];
extern const char D_0048E8E0[];
extern const char D_0048E8F0[];
extern const char D_0048E908[];
extern const char D_0048E918[];
extern const char D_0048E928[];
extern const char D_0048E940[];
extern const char D_0048E958[];
extern const char D_0048E968[];
extern const char D_0048E978[];
extern const char D_0048E990[];
extern const char D_0048E9A8[];
extern const char D_0048E9B8[];

extern "C" void tModifierBlock_readFromReplayFrame(tModifierBlock* self, sMbStream36D8* stream)
{
    sMbReplayHdr36D8 hdr;
    int i;

    *(void**)&self->node = 0;
    self->field_0x4 = 0;
    self->field_0x8 = 0;
    self->field_0xC = 0;
    stream->vt[2].fn((char*)stream + stream->vt[2].delta, &hdr, 0x34);

    if (hdr.flags & 1) {
        if (hdr.type == 1) {
            *(void**)&self->node = cSplineModifier_cSplineModifier(cMemMan_alloc(0xF0, D_0048E8D0, 0x20000000, 0), stream);
        } else if (hdr.type == 2) {
            *(void**)&self->node = func_0035A118(cMemMan_alloc(0x58, D_0048E8D0, 0x20000000, 0), stream);
        } else if (hdr.type == 4) {
            *(void**)&self->node = func_00357090(cMemMan_alloc(0xB0, D_0048E8E0, 0x20000000, 0), stream);
        } else if (hdr.type == 3) {
            *(void**)&self->node = func_00356F68(cMemMan_alloc(0x90, D_0048E8F0, 0x20000000, 0), stream);
        } else if (hdr.type == 5) {
            *(void**)&self->node = func_0035DF70(cMemMan_alloc(0x2D0, D_0048E908, 0x20000000, 0), stream);
        } else if (hdr.type == 6) {
            *(void**)&self->node = func_00357358(cMemMan_alloc(0xB0, D_0048E918, 0x20000000, 0), stream);
        } else if (hdr.type == 7) {
            *(void**)&self->node = func_00357798(cMemMan_alloc(0x90, D_0048E928, 0x20000000, 0), stream);
        }
    }
    if (hdr.flags & 2) {
        self->field_0x4 = (int)func_0035F788(cMemMan_alloc(0x50, D_0048E940, 0x20000000, 0), stream);
    }
    if (hdr.flags & 4) {
        self->field_0x8 = (int)func_0035F1A8(cMemMan_alloc(0xE8, D_0048E958, 0x20000000, 0), stream);
    }
    if ((hdr.flags & 8) && hdr.kind == 1) {
        self->field_0xC = (int)func_00342808(cMemMan_alloc(0x50, D_0048E968, 0x20000000, 0), stream);
    }
    for (i = 0; i < hdr.numA; i++) {
        void* p;
        if (hdr.typesA[i] == 1) {
            p = func_003459A8(cMemMan_alloc(0x1F0, D_0048E978, 0x20000000, 0), stream);
        } else if (hdr.typesA[i] == 2) {
            p = func_00345D80(cMemMan_alloc(0x270, D_0048E990, 0x20000000, 0), stream);
        } else if (hdr.typesA[i] == 3) {
            p = func_003461C0(cMemMan_alloc(0x40, D_0048E9A8, 0x20000000, 0), stream);
        } else {
            p = 0;
        }
        func_00345720((char*)self + 0x10, p);
    }
    for (i = 0; i < hdr.numB; i++) {
        func_0035B690((char*)self + 0x1C, func_0035BA88(cMemMan_alloc(0x90, D_0048E9B8, 0x20000000, 0), stream));
    }
}
#endif

extern void* D_0048F008[];

//100%
INCLUDE_ASM("object/modifierblock", func_00353AC0__FPv);
#ifdef SKIP_ASM
void* func_00353AC0(void* self)
{
    *(void***)((char*)self + 0xc) = D_0048F008;
    *(int*)((char*)self + 0x10) = -1;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x14) = 0;
    return self;
}
#endif

extern "C" void* func_003546C8(void*);

//100%
INCLUDE_ASM("object/modifierblock", func_00353AE8__FPv);
#ifdef SKIP_ASM
void* func_00353AE8(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_0048F008;
    return func_003546C8(self);
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353B10);
#ifdef SKIP_ASM
// PORT: func_002D1C58 is defined returning void*, but its value is the rider index passed to func_002D1C20(int).
extern "C" int func_002D1C58_i() __asm__("func_002D1C58");
extern "C" void* func_002D1C20(int i);
extern int D_004A452C;
extern char D_004FF1A0[];

struct sMat_53B10 {
    float m[16];
} __attribute__((aligned(16)));

struct sVec4_53B10 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRS_53B10 {
    unsigned int f0lo : 2;
    unsigned int f0b : 2;
    unsigned int f0hi : 28;
    unsigned int f4lo : 12;
    unsigned int alpha : 8;
    unsigned int zmode : 2;
    unsigned int zon : 1;
    unsigned int blendm : 2;
    unsigned int f4hi : 7;
    int f8;                     // bits 5..9 = blend
    int fC;
    int f10;
};

struct sVE_53B10 { short delta; short index; void (*fn)(void*, void*, float, void*, void*, int, int, int); };

struct sCtx_53B10 {
    char pad_0x0[0xE84];
    sRS_53B10* top;             // 0xE84
    char pad_0xE88[0x10D8 - 0xE88];
    sVE_53B10* vtable;          // 0x10D8
};

extern sCtx_53B10* D_004A5B80_53B10 __asm__("D_004A5B80");

// PORT: PS2-only VU0 inline asm (4x4 matrix copy).
static inline void vu0CopyMatrix_53B10(sMat_53B10* dst, void* src)
{
    __asm__ __volatile__(
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

static inline void SetZOn_53B10(sRS_53B10* r, int v) { r->zon = v; }
static inline void SetBlendM_53B10(sRS_53B10* r, int v) { r->blendm = v; }
static inline void SetZMode_53B10(sRS_53B10* r, int v) { r->zmode = v; }
static inline void SetAlpha_53B10(sRS_53B10* r, int v) { r->alpha = v; }

extern "C" void func_00353B10(void* self)
{
    if (D_004A452C != 0)
        return;
    sCtx_53B10* ctx = D_004A5B80_53B10;
    if (*(void**)((char*)self + 0x14) == 0)
        return;
    sMat_53B10 m;
    vu0CopyMatrix_53B10(&m, D_004FF1A0);
    sVec4_53B10 pos = *(sVec4_53B10*)func_002D1C20(func_002D1C58_i());
    *(sVec4_53B10*)&m.m[12] = pos;
    ctx->top[1] = ctx->top[0];
    sRS_53B10* t = ctx->top;
    ctx->top = t + 1;
    int f8 = t[1].f8;
    t[1].f8 = f8 & ~0x3E0;
    int old = (unsigned int)(f8 & 0x3E0) >> 5;
    ctx->top->f0b = 3;
    SetZOn_53B10(ctx->top, 1);
    SetBlendM_53B10(ctx->top, 2);
    SetZMode_53B10(ctx->top, 0);
    SetAlpha_53B10(ctx->top, 0x14);
    char* o = *(char**)((char*)self + 0x14);
    if (o != 0)
    {
        *(unsigned int*)(o + 8) = (*(unsigned int*)(o + 8) & ~2u) | 4;
        char* o2 = *(char**)((char*)self + 0x14);
        sVE_53B10* vt = ctx->vtable;
        vt[95].fn((char*)ctx + vt[95].delta, o2, 1.0f, *(void**)(*(char**)(o2 + 0x80) + 0xC), &m, 0, 0, 0x5420);
    }
    sRS_53B10* t2 = ctx->top;
    ctx->top = t2 - 1;
    int* pf = (int*)((char*)t2 - 0xC);
    *pf = (*pf & ~0x3E0) | (old << 5);
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353CF0);
#ifdef SKIP_ASM
struct sMbTrackEntry3CF0 {
    char pad_0x0[0x26];
    short count;            // 0x26
    char pad_0x28[0x30];
};

struct sMbTrackTable3CF0 {
    char pad_0x0[0x14];
    sMbTrackEntry3CF0* entries; // 0x14
};

struct sMbModelSet3CF0 {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};

struct sMbWorld3CF0 {
    sMbTrackTable3CF0* table;   // 0x0
    int field_0x4;
    sMbModelSet3CF0** sets;     // 0x8
};

extern "C" sMbWorld3CF0** func_002D1BD8();
int func_00353D98(void* self);

static inline void* refToPtr3CF0(unsigned int p)
{
    return (void*)(p << 2);
}

struct sMbModelRef3CF0 {
    unsigned int id;

    void* get(sMbWorld3CF0* w)
    {
        sMbModelSet3CF0* set = w->sets[id & 0xFF];
        if (set == 0) {
            return 0;
        }
        unsigned int p = set->refs[id >> 8] >> 8;
        if (p == 0) {
            return 0;
        }
        return refToPtr3CF0(p);
    }
};

struct sMbTrackRef3CF0 {
    char pad_0x0[0x10];
    int id;                 // 0x10
    void* model;            // 0x14
};

extern "C" void func_00353CF0(sMbTrackRef3CF0* self, int id)
{
    self->id = id;
    if (id < 0) {
        func_00353D98(self);
        return;
    }
    sMbWorld3CF0* w = *func_002D1BD8();
    if (w->table->entries[id].count > 0) {
        sMbModelRef3CF0 ref;
        ref.id = id & 0xFF;
        self->model = ref.get(w);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353D98__FPv);
#ifdef SKIP_ASM
int func_00353D98(void* self)
{
    int t0 = -1;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x10) = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353DA8__FPv);
#ifdef SKIP_ASM
void* func_00353DA8(void* self)
{
    *(int*)((char*)self + 0x24) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353DB8);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);

extern "C" void func_00353DB8(void* self, int flags)
{
    void* p = *(void**)((char*)self + 0x24);
    if (p != 0) {
        cMemMan_free(p);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353E08);
#ifdef SKIP_ASM
extern "C" void cSpring_setupNodes(void* self);

struct sSpringDesc_3E08 {
    float f0, f4, f8, fC, f10, f14, f18;
    int count;      // 0x1C
};

struct sSpring_3E08 {
    int count;      // 0x0
    float f4, f8, fC, f10, f14, f18, f1C;
    float seg;      // 0x20
};

extern "C" void func_00353E08(void* self, sSpringDesc_3E08* d, float len)
{
    sSpring_3E08* s = (sSpring_3E08*)self;
    int n = d->count;
    s->count = n;
    s->f4 = d->f0;
    s->f8 = d->f4;
    s->fC = d->f8;
    s->f10 = d->fC;
    s->f14 = d->f10;
    s->f18 = d->f14 * 9.999999974752427e-07f;
    s->f1C = d->f18;
    s->seg = len / (float)(n - 1);
    cSpring_setupNodes(self);
}
#endif

//100%
INCLUDE_ASM("object/modifierblock", func_00353E80);
#ifdef SKIP_ASM
struct sMbVEntrySer3E80 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void cSpring_setupNodes(void* self);

extern "C" void* func_00353E80(void* self, void* stream)
{
    sMbVEntrySer3E80* e = &(*(sMbVEntrySer3E80**)stream)[2];
    e->fn((char*)stream + e->delta, self, 0x24);
    cSpring_setupNodes(self);
    e = &(*(sMbVEntrySer3E80**)stream)[2];
    e->fn((char*)stream + e->delta, *(void**)((char*)self + 0x24), *(int*)self * 0x50);
    return self;
}
#endif

