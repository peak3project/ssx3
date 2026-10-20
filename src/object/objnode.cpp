#include "common.h"

extern "C" void cBucketMan_add(void* mgr, void* node, void* param);
extern void* D_00491F00[16];
extern char D_004A5988;

struct cObjNode {
    char pad_0x00[0xC];
    void* field_0xC;
};

//100%
INCLUDE_ASM("object/objnode", cObjNode_cObjNode__FP8cObjNodePv);
#ifdef SKIP_ASM
cObjNode* cObjNode_cObjNode(cObjNode* self, void* param2)
{
    self->field_0xC = D_00491F00;
    cBucketMan_add(&D_004A5988, self, param2);
    return self;
}
#endif

//100%
INCLUDE_ASM("object/objnode", func_003546C8);
#ifdef SKIP_ASM
extern "C" void func_00354E48(void* mgr, void* node);
void operator_delete(int*);

extern "C" void func_003546C8(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_00491F00;
    func_00354E48(&D_004A5988, self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("object/objnode", func_00354720);
#ifdef SKIP_ASM
extern void* D_00491E80[];
extern int D_0044AFF0[];
extern "C" void* func_00354648(void* self, void* a1);

extern "C" void* func_00354720(void* self, void* a1, int type)
{
    func_00354648(self, a1);
    *(void***)((char*)self + 0xC) = D_00491E80;
    *(short*)((char*)self + 0x10) = type;
    *(short*)((char*)self + 0x12) = 0;
    D_0044AFF0[*(short*)((char*)self + 0x10)]++;
    return self;
}
#endif

//100%
INCLUDE_ASM("object/objnode", cTypeObjNode_cTypeObjNode);
#ifdef SKIP_ASM
struct sObjNodeVEntry4788 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern void* D_00491E80[];
extern int D_0044AFF0[];
// PORT: cObjNode_cObjNode takes (self, param2); this caller also leaves the stream in $6.
cObjNode* cObjNode_cObjNode_3(cObjNode* self, void* param2, void* stream) __asm__("cObjNode_cObjNode__FP8cObjNodePv");

extern "C" void* cTypeObjNode_cTypeObjNode(void* self, void* a, void* stream)
{
    cObjNode_cObjNode_3((cObjNode*)self, a, stream);
    *(void***)((char*)self + 0xC) = D_00491E80;
    sObjNodeVEntry4788* vt = *(sObjNodeVEntry4788**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x10, 4);
    D_0044AFF0[*(short*)((char*)self + 0x10)]++;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/objnode", func_00354808);
#ifdef SKIP_ASM
extern "C" void func_003546C8(void* self, int flags);
extern void* D_00491E80[];
extern int D_0044AFF0[];

// PORT: the unit declares func_00354808(void*), but this is a deleting
// destructor taking (self, flags); the real body is bound by asm label.
void func_00354808_impl(void* self, int flags) __asm__("func_00354808");

void func_00354808_impl(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_00491E80;
    D_0044AFF0[*(short*)((char*)self + 0x10)]--;
    func_003546C8(self, flags);
}
#endif

//100%
INCLUDE_ASM("object/objnode", func_00354850);
#ifdef SKIP_ASM
extern int D_004A5B78;
extern int D_004A5B7C;
extern void* D_00491E00[];

static inline int objNextId_4850(int* c)
{
    return (*c)++;
}

extern "C" void* func_00354850(void* self, void* a1, int type)
{
    int id;
    func_00354720(self, a1, type);
    *(void***)((char*)self + 0xC) = D_00491E00;
    if (type == 6) {
        id = objNextId_4850(&D_004A5B7C);
    } else {
        id = objNextId_4850(&D_004A5B78);
    }
    *(int*)((char*)self + 0x14) = id;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/objnode", cSortObjNode_cSortObjNode);
#ifdef SKIP_ASM
struct sVEntryCSortObjNode {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern void* D_00491E00[];
extern "C" void* cTypeObjNode_cTypeObjNode(void* self, void* a, void* stream);

extern "C" void* cSortObjNode_cSortObjNode(void* self, void* a, void* stream)
{
    cTypeObjNode_cTypeObjNode(self, a, stream);
    *(void***)((char*)self + 0xC) = D_00491E00;
    sVEntryCSortObjNode* vt = *(sVEntryCSortObjNode**)stream;
    vt[2].fn((char*)stream + vt[2].delta, (char*)self + 0x14, 4);
    return self;
}
#endif

extern void* D_00491E00[];
extern "C" void* func_00354808(void*);

//99.5%
INCLUDE_ASM("object/objnode", func_00354920__FPv);
#ifdef SKIP_ASM
void* func_00354920(void* self)
{
    *(int*)((char*)self + 0xc) = (int)(void*)D_00491E00;
    return func_00354808(self);
}
#endif

//100%
INCLUDE_ASM("object/objnode", func_00354948);
#ifdef SKIP_ASM
class func_00354948_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(void* buf, int size);
};

extern "C" void func_00354948(void* self, func_00354948_cObj* obj)
{
    obj->v01((char*)self + 0x10, 4);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("object/objnode", func_00354980);
#ifdef SKIP_ASM
extern "C" void func_00354980(void* self, func_00354948_cObj* obj)
{
    func_00354948(self, obj);
    obj->v01((char*)self + 0x14, 4);
}
#endif

//100%
INCLUDE_ASM("object/objnode", func_003549D0__FPv);
#ifdef SKIP_ASM
void* func_003549D0(void* self)
{
    int t0 = 0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)self = t0;
    return self;
}
#endif

