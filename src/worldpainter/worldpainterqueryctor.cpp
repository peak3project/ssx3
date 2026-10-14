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

INCLUDE_ASM("worldpainter/worldpainterqueryctor", func_002C0778);

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

