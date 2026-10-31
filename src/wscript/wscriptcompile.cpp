#include "common.h"

//100%
INCLUDE_ASM("wscript/wscriptcompile", cWScriptCompile_parseKeywords);
#ifdef SKIP_ASM
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern char D_0048E8C0[];

struct cWScriptKeyword {
    cWScriptKeyword* next;
    char pad04[0x74];
    unsigned int f78;
    unsigned char f7C;
    unsigned char f7D;
    short f7E;
    char pad80[0x30];
};

struct cWScriptCompileKw {
    int f0;
    int count;
    cWScriptKeyword* free;
    cWScriptKeyword* pool;
};

extern "C" cWScriptCompileKw* cWScriptCompile_parseKeywords(cWScriptCompileKw* self, int a1, int n)
{
    int i;
    self->f0 = a1;
    self->count = n;
    cWScriptKeyword** slot = &self->pool;
    cWScriptKeyword* mem = (cWScriptKeyword*)operator_new__FUi(n * 0xB0, D_0048E8C0, 0x20000000, 0);
    cWScriptKeyword* q = mem;
    int j;
    for (j = n - 1; j != -1; j--, q++) {
        q->f78 = 0xFFFFFFFF;
        q->f7C = 0;
        q->f7D = 0xFF;
        q->f7E = -1;
    }
    *slot = mem;
    self->free = 0;
    for (i = 0; i < self->count; i++) {
        self->pool[i].next = self->free;
        self->free = &self->pool[i];
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptcompile", func_00351120);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
void cMemMan_free(void* p);

extern "C" void func_00351120(void* self, int flags)
{
    void* p = *(void**)((char*)self + 0xC);
    if (p != 0) {
        cMemMan_free(p);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptcompile", func_00351170);
#ifdef SKIP_ASM
struct sWSNode {
    sWSNode* next;
    int pad4;
    unsigned int flags;
    char pad0C[0x78 - 0xC];
    unsigned int type : 8;
    unsigned int index : 24;
    char pad7C[0xB0 - 0x7C];
};

struct sWSPool {
    unsigned char type;
    char pad1[7];
    sWSNode* free;
    sWSNode* base;
};

extern "C" sWSNode* func_00351170(sWSPool* self)
{
    sWSNode* p = self->free;
    if (p != 0) {
        self->free = p->next;
    }
    p->type = self->type;
    p->index = p - self->base;
    p->flags |= 0x2000;
    return p;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptcompile", func_003511D0);
#ifdef SKIP_ASM
extern "C" sWSNode* func_003511D0(sWSPool* self, unsigned int id)
{
    sWSNode** link = &self->free;
    sWSNode* p = self->free;
    while (p != 0) {
        if (p - self->base == (id >> 8)) {
            *link = p->next;
            p->type = self->type;
            int idx = p - self->base;
            p->flags |= 0x2000;
            p->index = idx;
            return p;
        }
        link = &p->next;
        p = p->next;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptcompile", func_00351260__FPvT0);
#ifdef SKIP_ASM
void func_00351260(void* self, void* a1)
{
    int t0 = *(int*)((char*)self + 0x8);
    *(int*)a1 = t0;
    *(int*)((char*)self + 0x8) = (int)a1;
}
#endif

