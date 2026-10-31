#include "common.h"

//100%
INCLUDE_ASM("main/sectionman", cSectionMan_setSky);
#ifdef SKIP_ASM
extern char D_005047F8[];
extern char D_004A2A20[]; // "APBR1"
extern char D_004A2A28[]; // "BPBR1"
extern char D_004A2A30[]; // "CPBR1"
extern char D_004A2A38[]; // "DPBR1"
extern char D_004A2A40[]; // "EPBR1"
extern int D_004A43C4;
extern "C" int func_0038AC50(void* self, const char* name);

// Picks the default rider irradiance bank for the given course.
extern "C" void cSectionMan_setSky(void* self, int sky)
{
    switch (sky) {
    case 1:
    case 11:
    case 18:
        D_004A43C4 = func_0038AC50(D_005047F8, D_004A2A28);
        break;
    case 2:
    case 9:
    case 12:
    case 19:
        D_004A43C4 = func_0038AC50(D_005047F8, D_004A2A30);
        break;
    case 3:
    case 6:
    case 15:
    case 20:
        D_004A43C4 = func_0038AC50(D_005047F8, D_004A2A38);
        break;
    case 4:
    case 7:
    case 10:
    case 13:
    case 16:
    case 21:
        D_004A43C4 = func_0038AC50(D_005047F8, D_004A2A40);
        break;
    case 0:
    case 5:
    case 8:
    case 14:
    case 17:
    default:
        D_004A43C4 = func_0038AC50(D_005047F8, D_004A2A20);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("main/sectionman", func_0022E228);
#ifdef SKIP_ASM
struct sSectionNode {
    int field_0x0;
    sSectionNode* next; // 0x4
};

struct sSectionMan {
    sSectionNode nodes[50]; // 0x0
    int field_0x190;
    int field_0x194;
    sSectionNode* freeList; // 0x198
    int field_0x19c;
    int field_0x1a0;
};

extern "C" void func_0022E228(sSectionMan* self)
{
    int i;
    self->freeList = self->nodes;
    for (i = 0; i < 50; i++) {
        self->nodes[i].field_0x0 = 49;
        self->nodes[i].next = &self->nodes[i + 1];
    }
    self->field_0x190 = 49;
    self->field_0x194 = 0;
    self->field_0x19c = 0;
    self->field_0x1a0 = 0;
}
#endif

//100%
INCLUDE_ASM("main/sectionman", func_0022E278__FPv);
#ifdef SKIP_ASM
struct sSectionLink {
    int pad0;
    sSectionLink* next; // 0x4
};

void* func_0022E278(void* self)
{
    sSectionLink* node = *(sSectionLink**)((char*)self + 0x198);
    *(sSectionLink**)((char*)self + 0x198) = node->next;
    return node;
}
#endif

//100%
INCLUDE_ASM("main/sectionman", func_0022E288__FPvT0);
#ifdef SKIP_ASM
int func_0022E288(void* self, void* a1)
{
    int t0 = *(int*)((char*)self + 0x198);
    *(int*)((char*)a1 + 0x4) = t0;
    *(int*)((char*)self + 0x198) = (int)a1;
    return t0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/sectionman", func_0022E298);
#ifdef SKIP_ASM
struct sSectionNode_E298 {
    int id;
    sSectionNode_E298* next; // 0x4
};

void* func_0022E278(void* self);
extern "C" void func_0022E360(void* self, void* prev, void* node);

extern "C" void func_0022E298(void* self, int id)
{
    sSectionNode_E298* n = *(sSectionNode_E298**)((char*)self + 0x19C);
    sSectionNode_E298* prev = 0;
    while (n != 0) {
        if (n->id == id) {
            sSectionNode_E298* cur = n;
            n = n->next;
            func_0022E360(self, prev, cur);
        } else {
            prev = n;
            n = n->next;
        }
    }
    n = (sSectionNode_E298*)func_0022E278(self);
    n->id = id;
    n->next = 0;
    if (prev != 0) {
        prev->next = n;
    } else {
        *(sSectionNode_E298**)((char*)self + 0x19C) = n;
    }
    *(int*)((char*)self + 0x1A0) += 1;
}
#endif

//100%
INCLUDE_ASM("main/sectionman", func_0022E348);
#ifdef SKIP_ASM
extern "C" int* func_0022E348(void* self, void* a1)
{
    if (a1 != 0) {
        return *(int**)((char*)a1 + 0x4);
    }
    return *(int**)((char*)self + 0x19c);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("main/sectionman", func_0022E360);
#ifdef SKIP_ASM
// PORT: the unit defines func_0022E288 as returning int; this caller treats it as void.
void func_0022E288_v(void* self, void* node) __asm__("func_0022E288__FPvT0");

extern "C" void func_0022E360(void* self, void* prev, void* node)
{
    if (prev == 0) {
        *(int*)((char*)self + 0x19C) = *(int*)((char*)node + 0x4);
    } else {
        *(int*)((char*)prev + 0x4) = *(int*)((char*)node + 0x4);
    }
    func_0022E288_v(self, node);
    *(int*)((char*)self + 0x1A0) = *(int*)((char*)self + 0x1A0) - 1;
}
#endif

