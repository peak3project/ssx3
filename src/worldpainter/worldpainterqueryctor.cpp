#include "common.h"

//100%
INCLUDE_ASM("worldpainter/worldpainterqueryctor", cWorldPainterQuery_cWorldPainterQuery);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern char D_00483E00[];
extern char D_00483CB8[];
extern char D_00483CD0[];
extern char D_00483CE0[];
extern char D_00483CF0[];
extern char D_00483D00[];
extern char D_00483D10[];
extern char D_00483D20[];
extern char D_00483D38[];
extern char D_00483D50[];
extern char D_00483D60[];
extern char D_00483D70[];
extern char D_00483D80[];
extern char D_00483D90[];
extern char D_00483DA0[];
extern "C" void* func_002BC6F8(void* p);
extern "C" void* func_002BC728(void* p);
extern "C" void* func_002BC750(void* p);
extern "C" void* func_002BC778(void* p);
extern "C" void* func_002BC7A0(void* p);
extern "C" void* func_002BC7C8(void* p);
extern "C" void* func_002BC830(void* p);
extern "C" void* func_002BC890(void* p);
extern "C" void* func_002BC8E8(void* p);
extern "C" void* func_002BC910(void* p);
extern "C" void* func_002BC980(void* p);
extern "C" void* func_002BC9B0(void* p);
extern "C" void* func_002BCAF8(void* p);
extern "C" void* func_002BCBD0(void* p);

struct sWPQueryType {
    unsigned int flags : 8;
    unsigned int kind : 24;
};

struct sWPQuery_0410 {
    void* impl;                     // 0x0
    void* vtbl;                     // 0x4
    float minDist;                  // 0x8
    float maxDist;                  // 0xC
    sWPQueryType type;              // 0x10
    sWPQuery_0410* next;            // 0x14
};

extern sWPQuery_0410* D_004A3880_0410 __asm__("D_004A3880");

// Creates the query implementation for the requested kind and links the query into the global list.
extern "C" sWPQuery_0410* cWorldPainterQuery_cWorldPainterQuery(sWPQuery_0410* self, unsigned int type)
{
    self->type.flags = type;
    self->type.kind = type >> 8;
    self->vtbl = D_00483E00;
    self->minDist = 4286578688.0f;
    self->maxDist = 4286578688.0f;
    switch (self->type.kind) {
    case 0:
        self->impl = func_002BC6F8(cMemMan_alloc(0x18, D_00483CB8, 0, 0));
        break;
    case 1:
        self->impl = func_002BC728(cMemMan_alloc(0x10, D_00483CD0, 0, 0));
        break;
    case 2:
        self->impl = func_002BC750(cMemMan_alloc(0x10, D_00483CE0, 0, 0));
        break;
    case 3:
        self->impl = func_002BC778(cMemMan_alloc(0x10, D_00483CF0, 0, 0));
        break;
    case 4:
        self->impl = func_002BC7A0(cMemMan_alloc(0x10, D_00483D00, 0, 0));
        break;
    case 5:
        self->impl = func_002BC7C8(cMemMan_alloc(0x38, D_00483D10, 0, 0));
        break;
    case 6:
        self->impl = func_002BC830(cMemMan_alloc(0x40, D_00483D20, 0, 0));
        break;
    case 7:
        self->impl = func_002BC890(cMemMan_alloc(0x38, D_00483D38, 0, 0));
        break;
    case 8:
        self->impl = func_002BC8E8(cMemMan_alloc(0x10, D_00483D50, 0, 0));
        break;
    case 9:
        self->impl = func_002BC910(cMemMan_alloc(0x50, D_00483D60, 0, 0));
        break;
    case 10:
        self->impl = func_002BC980(cMemMan_alloc(0x10, D_00483D70, 0, 0));
        break;
    case 11:
        self->impl = func_002BC9B0(cMemMan_alloc(0x58, D_00483D80, 0, 0));
        break;
    case 12:
        self->impl = func_002BCAF8(cMemMan_alloc(0xA0, D_00483D90, 0, 0));
        break;
    case 13:
        self->impl = func_002BCBD0(cMemMan_alloc(0x18, D_00483DA0, 0, 0));
        break;
    }
    self->next = D_004A3880_0410;
    D_004A3880_0410 = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpainterqueryctor", func_002C06C0);
#ifdef SKIP_ASM
void operator_delete(int* p);
extern char D_00483E00[];
extern char D_00485D30[];

struct sWPQuery_06C0 {
    int* buf;
    void* vtbl;
    char pad8[0xC];
    sWPQuery_06C0* next;
};

extern sWPQuery_06C0* D_004A3880;

extern "C" void func_002C06C0(sWPQuery_06C0* self, int flags)
{
    self->vtbl = D_00483E00;
    operator_delete(self->buf);
    sWPQuery_06C0* p = D_004A3880;
    if (p == self) {
        D_004A3880 = self->next;
    } else {
        while (p->next != self) {
            p = p->next;
        }
        if (p != 0) {
            p->next = self->next;
        }
    }
    self->vtbl = D_00485D30;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpainterqueryctor", func_002C0778);
#ifdef SKIP_ASM
// Callee func_002C0A10(self, list, x, y) returns the item for (x, y) in list = section->data->lists[type.flags].
extern int D_004A3860;
extern char* D_004A28A8;

// PORT: PS2 sqrt.s asm helper.
static inline float sqrt_0778(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

struct sVE_0778 {
    short delta;
    short index;
    void* fn;
};

struct sImpl_0778 {
    float dist;         // 0x0
    sVE_0778* vtbl;     // 0x4
};

struct sItem_0778 {
    int id;
    int value;
};

struct sSectionData_0778 {
    int pad0;
    int count;
    void* lists[1];
};

struct sSection_0778 {
    short type;
    short pad2;
    int pad4;
    sSectionData_0778* data;
};

struct sHeader_0778 {
    unsigned int numSections;
    sSection_0778* sections;
};

struct sQ_0778 {
    sImpl_0778* obj;    // 0x0
    void* vtbl;         // 0x4
    float x;            // 0x8
    float y;            // 0xC
    sWPQueryType type;  // 0x10
};

extern "C" sItem_0778* func_002C0A10_0778(void* self, void* list, float x, float y) __asm__("func_002C0A10");

typedef void (*VFn_0778)(void*);
typedef int (*VFnI_0778)(void*, int);
typedef void (*VFnF_0778)(float, void*);
typedef void (*VFnFI_0778)(float, void*, int);
typedef void (*VFnFP_0778)(float, void*, float*);

extern "C" struct sImpl_0778* func_002C0778(struct sQ_0778* self, float x, float y, float step)
{
    struct sHeader_0778* hdr = *(struct sHeader_0778**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0x10) + 8);
    int unset = (self->obj->dist == -99999.0f);
    if (!unset) {
        float dx = self->x - x;
        float dy = self->y - y;
        self->obj->dist = self->obj->dist + sqrt_0778(dx * dx + dy * dy);
    }
    int idx = D_004A3860;
    self->x = x;
    self->y = y;
    for (;;) {
        int hit = 0;
        if (hdr->sections[idx].type == 3) {
            if (hdr->sections[idx].data != 0)
                hit = 0 < hdr->sections[idx].data->count;
        }
        if (!hit)
            break;
        struct sSection_0778* sec = &hdr->sections[idx];
        void* list = sec->data->lists[self->type.flags];
        if (list == 0) {
            if (unset) {
                struct sVE_0778* vt = self->obj->vtbl;
                ((VFn_0778)vt[69].fn)((char*)self->obj + vt[69].delta);
            }
            break;
        }
        struct sItem_0778* item = func_002C0A10_0778(self, list, self->x, self->y);
        if (item == 0)
            break;
        if (item->id != self->type.kind)
            return self->obj;
        {
            struct sVE_0778* vt = self->obj->vtbl;
            int r = ((VFnI_0778)vt[68].fn)((char*)self->obj + vt[68].delta, item->value);
            if (r != 0)
                self->obj->dist = 0.0f;
        }
        if (unset) {
            struct sVE_0778* vt = self->obj->vtbl;
            ((VFnFI_0778)vt[66].fn)(-1.0f, (char*)self->obj + vt[66].delta, item->value);
            self->obj->dist = 0.0f;
        } else if (step == -99999.0f) {
            if (0.0f <= *(float*)item->value && *(float*)item->value <= self->obj->dist) {
                struct sVE_0778* vt = self->obj->vtbl;
                ((VFnFI_0778)vt[66].fn)(1.0f, (char*)self->obj + vt[66].delta, item->value);
                self->obj->dist = 0.0f;
            } else {
                struct sVE_0778* vt = self->obj->vtbl;
                ((VFnFI_0778)vt[66].fn)(-*(float*)item->value, (char*)self->obj + vt[66].delta, item->value);
            }
        } else {
            struct sVE_0778* vt = self->obj->vtbl;
            ((VFnFI_0778)vt[66].fn)(step, (char*)self->obj + vt[66].delta, item->value);
        }
        return self->obj;
    }
    {
        struct sVE_0778* vt = self->obj->vtbl;
        ((VFn_0778)vt[69].fn)((char*)self->obj + vt[69].delta);
    }
    return self->obj;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpainterqueryctor", func_002C0A10);
#ifdef SKIP_ASM
struct func_002C0A10_sItem {
    int a;
    int b;
};

struct func_002C0A10_sList {
    int field_0x0;
    int field_0x4;
    func_002C0A10_sItem* items;
};

extern "C" int func_002BAF90(func_002C0A10_sList* list);

extern "C" func_002C0A10_sItem* func_002C0A10(void* self, func_002C0A10_sList* list)
{
    int i = func_002BAF90(list);
    return (i != -1) ? &list->items[i] : 0;
}
#endif

