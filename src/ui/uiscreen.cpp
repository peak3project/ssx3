#include "common.h"

extern "C" void cListNode_removeFromList(void* self);

struct sDeleteTarget {
    char pad_0x00[0x8];
    short field_0x8;
    char pad_0xA[2];
    void (*fn)(void*, int); // 0xC
};

//100%
INCLUDE_ASM("ui/uiscreen", cUIThread_deleteThread__FPv);
#ifdef SKIP_ASM
void cUIThread_deleteThread(void* self)
{
    cListNode_removeFromList(self);
    if (self != 0) {
        sDeleteTarget* target = *(sDeleteTarget**)((char*)self + 0x8);
        target->fn((char*)self + target->field_0x8, 3);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039C558);
#ifdef SKIP_ASM
extern "C" void func_00397948_C558(void*) __asm__("func_00397948");
extern "C" void func_003A4868(void*);
extern "C" void func_0039FC48(void* self, int flags);
extern "C" void cMemMan_free__FPv(void* p);
void operator_delete(int*);
extern void* D_00494670[];
extern void* D_004949E8[];
extern void* D_00494C98[];
extern void* D_00494CC0[];

// Destructor of a UI screen: frees its buffers and tears down the embedded members.
extern "C" void func_0039C558(void* p, int flags)
{
    char* self = (char*)p;
    *(void***)(self + 0x8) = D_00494670;
    if (*(void**)(self + 0x3C) != 0) {
        cMemMan_free__FPv(*(void**)(self + 0x3C));
    }
    if (*(void**)(self + 0xC) != 0 && (*(int*)(self + 0x14) & 2)) {
        cMemMan_free__FPv(*(void**)(self + 0xC));
    }
    *(void***)(self + 0xCC) = D_00494C98;
    *(void***)(self + 0x48) = D_004949E8;
    func_00397948_C558(self + 0xB4);
    char* m40 = self + 0x40;
    *(void***)(self + 0xC8) = D_00494CC0;
    func_003A4868(self + 0xC0);
    *(void***)(self + 0xBC) = D_00494CC0;
    func_003A4868(self + 0xB4);
    func_0039FC48(m40, 2);
    *(void***)(self + 0x30) = D_00494C98;
    func_00397948_C558(self + 0x18);
    *(void***)(self + 0x2C) = D_00494CC0;
    func_003A4868(self + 0x24);
    *(void***)(self + 0x20) = D_00494CC0;
    func_003A4868(self + 0x18);
    *(void***)(self + 0x8) = D_00494CC0;
    func_003A4868(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", cUIScreen_setData);
#ifdef SKIP_ASM
extern "C" int func_003B4818(void* data);
extern "C" void* func_003B47F8(void* src, void* dst);
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00493E00[];

extern "C" void cUIScreen_setData(void* self, char* data)
{
    int size = func_003B4818(data);
    if (size != 0) {
        char* buf = (char*)operator_new_tag(size, D_00493E00, 0x100, 0);
        *(char**)((char*)self + 0xC) = buf;
        char* old = data;
        data = buf;
        func_003B47F8(old, data);
        *(int*)((char*)self + 0x14) |= 2;
    } else {
        *(int*)((char*)self + 0x14) &= ~2;
    }
    *(char**)((char*)self + 0x10) = data;
    *(char**)((char*)self + 0x34) = data + *(int*)(data + 8);
    *(char**)((char*)self + 0x38) = data + *(int*)(data + 4);
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039C728);
#ifdef SKIP_ASM
extern "C" void* func_0039C728(void* self, unsigned short frame)
{
    int* list = *(int**)((char*)self + 0x34);
    char* e = (char*)list + 4;
    unsigned int i;
    for (i = 0; i < (unsigned int)*list; i++) {
        if (*(unsigned short*)(e + 0x8) == frame) {
            return e;
        }
        e = e + *(int*)(e + 0x4);
    }
    return 0;
}
#endif

struct sFrameEntry {
    int label; // 0x0
    int stride; // 0x4
    unsigned short field_0x8; // 0x8
};

struct sFrameList {
    int count; // 0x0
};

struct cUIScreen {
    char pad_0x00[0x34];
    sFrameList* list; // 0x34
};

//100%
INCLUDE_ASM("ui/uiscreen", cUIScreen_getFrameByLabel__FP9cUIScreeni);
#ifdef SKIP_ASM
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label)
{
    sFrameList* list = self->list;
    sFrameEntry* e = (sFrameEntry*)((char*)list + 4);
    unsigned int i;
    for (i = 0; i < (unsigned int)list->count; i++) {
        if (e->label == label) {
            return e->field_0x8;
        }
        e = (sFrameEntry*)((char*)e + e->stride);
    }
    return 0xFFFF;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", cUIScreen_getPrimaryThread);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

extern "C" void* cUIScreen_getPrimaryThread(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x18));
    if (n != 0) {
        for (; !cListNode_isSentinel((cListNode*)n); n = *(void**)((char*)n + 4)) {
            if ((*(int*)((char*)n + 0x10) >> 25) & 1) {
                return n;
            }
        }
    }
    return 0;
}
#endif

extern "C" void* cUIScreen_getPrimaryThread(void* self);
void cUIThread_deleteThread(void* self);
extern "C" void cUIScreen_playFrame(void* self, unsigned short frame, int flag);

//100%
INCLUDE_ASM("ui/uiscreen", cUIScreen_jumpToFrame__FPvUs);
#ifdef SKIP_ASM
void cUIScreen_jumpToFrame(void* self, unsigned short frame)
{
    void* thread = cUIScreen_getPrimaryThread(self);
    if (thread != 0) {
        cUIThread_deleteThread(thread);
    }
    cUIScreen_playFrame(self, frame, 0);
}
#endif

INCLUDE_ASM("ui/uiscreen", cUIScreen_playFrame);

INCLUDE_ASM("ui/uiscreen", func_0039C978);

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CBC8);
#ifdef SKIP_ASM
extern "C" void func_0039CBC8(void* p0, void* p1, void* p2, void* p3)
{
    *(unsigned int*)((char*)p3 + 0x10) &= 0xFEFFFFFFU;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CBE0);
#ifdef SKIP_ASM
extern "C" void func_0039CBE0(cUIScreen* self, void* p1, void* p2, void* p3)
{
    sFrameEntry* e = (sFrameEntry*)((char*)self->list + 4);
    unsigned int i;
    for (i = 0; i < (unsigned int)self->list->count; i++) {
        if (e->label == *(int*)((char*)p2 + 4)) {
            *(unsigned short*)((char*)p3 + 0xC) = e->field_0x8;
            return;
        }
        e = (sFrameEntry*)((char*)e + e->stride);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CC38);
#ifdef SKIP_ASM
extern "C" void func_0039CC38(cUIScreen* self, void* p1, void* p2)
{
    sFrameEntry* e = (sFrameEntry*)((char*)self->list + 4);
    unsigned int i;
    for (i = 0; i < (unsigned int)self->list->count; i++) {
        if (e->label == *(int*)((char*)p2 + 4)) {
            cUIScreen_playFrame(self, e->field_0x8, 1);
            return;
        }
        e = (sFrameEntry*)((char*)e + e->stride);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CCA8);
#ifdef SKIP_ASM
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void* cUIAnimationBank_getAnimationByHashName(void* bank, int hash);
// PORT: callers pass a 5th arg (0) that func_0039FCC8 never reads
extern "C" void func_0039FCC8(void* self, void* anim, unsigned char mode, unsigned short v, int x);

extern "C" void func_0039CCA8(void* self, void* p1, void* msg)
{
    void* obj = cUIScreen_getObjectByHashName(self, *(int*)((char*)msg + 8));
    if (obj != 0) {
        void* anim = cUIAnimationBank_getAnimationByHashName(
            (char*)*(void**)((char*)*(void**)((char*)self + 0xD0) + 0x10) + 0x50,
            *(int*)((char*)msg + 4));
        if (anim != 0) {
            func_0039FCC8(obj, anim, *(unsigned char*)((char*)msg + 0xC), *(unsigned short*)((char*)p1 + 8), 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CD30);
#ifdef SKIP_ASM
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_0039FD38(void* self);

class func_0039CD30_cVirt {
public:
    char pad[0x8];
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
    virtual void v13(int, void*);
};

extern "C" void func_0039CD30(void* self, int a1, int* msg)
{
    func_0039CD30_cVirt* obj = (func_0039CD30_cVirt*)cUIScreen_getObjectByHashName(self, msg[1]);
    if (obj != 0) {
        func_0039FD38(obj);
        obj->v13(msg[2], msg + 3);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CD90__FPv);
#ifdef SKIP_ASM
void func_0039CD90(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CD98__FPv);
#ifdef SKIP_ASM
void func_0039CD98(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CDA0);
#ifdef SKIP_ASM
class func_0039CDA0_cVirtA {
public:
    char pad[0x8];
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
    virtual void v15();
    virtual int v16(void*, int);
};

class func_0039CDA0_cVirtB {
public:
    char pad[0x4];
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual int v03(void*, int);
};

extern "C" void func_0039CDA0(void* self, void* p1, int* msg)
{
    func_0039CDA0_cVirtA* a = *(func_0039CDA0_cVirtA**)((char*)self + 0xD0);
    if (a->v16(self, msg[1]) == 0) {
        func_0039CDA0_cVirtB* b = **(func_0039CDA0_cVirtB***)((char*)*(void**)((char*)self + 0xD0) + 0x10);
        if (b != 0) {
            b->v03(self, msg[1]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CE20);
#ifdef SKIP_ASM
struct sUIFlags1C {
    unsigned int lo : 8;
    unsigned int mode : 6;
};

extern "C" void func_0039CE20(void* self)
{
    void* p = *(void**)((char*)self + 0xd0);
    if (p != 0) {
        ((sUIFlags1C*)((char*)p + 0x1c))->mode = 3;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CE48);
#ifdef SKIP_ASM
extern "C" void func_00398638(void*, int);

extern "C" void func_0039CE48(void* self)
{
    func_00398638((char*)self + 0x40, 0);
    void* p = *(void**)((char*)self + 0xd0);
    if (p != 0) {
        ((sUIFlags1C*)((char*)p + 0x1c))->mode = 6;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CE90__FPv);
#ifdef SKIP_ASM
void func_0039CE90(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039CE98);
#ifdef SKIP_ASM
extern "C" void func_0039CE98(void* self, void* p1, void* p2, void* p3)
{
    *(unsigned int*)((char*)p3 + 0x10) &= 0xFEFFFFFFU;
    void* p = *(void**)((char*)self + 0xd0);
    if (p != 0) {
        ((sUIFlags1C*)((char*)p + 0x1c))->mode = 7;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", cUIScreen_createAllObjects);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void cList_addToEnd(cList*, cListNode*);
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" char* cUIScreen_createObjectByStruct(void* self, char* rec);
extern "C" void* func_003E6448(void* dst, int c, int n);
extern char D_00493EF0[];

struct sUIVtCED0 { short delta; short index; void (*fn)(void*, void*); };

extern "C" void cUIScreen_createAllObjects(void* self)
{
    char* data = *(char**)((char*)self + 0x38);
    char* rec = data + 4;
    if (*(unsigned int*)data != 0) {
        *(void***)((char*)self + 0x3C) = (void**)operator_new_tag(*(unsigned int*)data * 4, D_00493EF0, 0x20000000, 0);
        func_003E6448(*(void***)((char*)self + 0x3C), 0, **(unsigned int**)((char*)self + 0x38) * 4);
    }
    void** out = *(void***)((char*)self + 0x3C);
    for (unsigned int i = 0; i < **(unsigned int**)((char*)self + 0x38); i++) {
        char* obj = cUIScreen_createObjectByStruct(self, rec);
        if (obj != 0) {
            *out++ = obj;
            *(int*)(obj + 0x38) = *(int*)(rec + 4);
            cList_addToEnd((cList*)((char*)self + 0xB4), (cListNode*)obj);
        }
        rec += *(unsigned short*)(rec + 2);
    }
    for (unsigned int i = 0; i < **(unsigned int**)((char*)self + 0x38); i++) {
        void* o = (*(void***)((char*)self + 0x3C))[i];
        if (o != 0) {
            char* d = *(char**)((char*)self + 0xD0);
            sUIVtCED0* vt = *(sUIVtCED0**)(d + 8);
            vt[18].fn(d + vt[18].delta, o);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039D008);
#ifdef SKIP_ASM
struct sObjRec_0039D008 {
    short pad0;
    unsigned short size; // 0x2
    int key;             // 0x4
};

extern "C" void* func_0039D008(void* self, int key)
{
    sObjRec_0039D008* e = (sObjRec_0039D008*)(*(char**)((char*)self + 0x38) + 4);
    unsigned int i;
    for (i = 0; i < *(*(unsigned int**)((char*)self + 0x38)); i++) {
        if (e->key == key) {
            char* obj = cUIScreen_createObjectByStruct(self, (char*)e);
            *(int*)(obj + 0x38) = key;
            return obj;
        }
        e = (sObjRec_0039D008*)((char*)e + e->size);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", cUIScreen_createObjectByStruct);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as fresh memory (no aliasing with the record or the vtables).
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* func_0039FB30(void* self, void* screen, int a2);
extern "C" void* func_0021CCC8(void* self);
extern "C" void* func_003977E8(void* self);
extern "C" void* func_003A5338(void* self);
extern "C" void* func_003A5508(void* self);
extern "C" void* func_00399768(void* mem, void* screen, int a2);
extern "C" void* func_003A0348(void* mem, void* screen, int a2);
extern "C" void* func_003A1148(void* mem, void* screen, int a2);
extern "C" void* func_003A3280(void* mem, void* screen, int a2);
extern char D_004A4788[];
extern char D_004A4790[];
extern char D_004A4798[];
extern char D_004A47A0[];
extern char D_00493F00[];
extern char D_00493F10[];
extern char D_00493F20[];
extern char D_00493F30[];
extern char D_00493F40[];
extern char D_00493F50[];
extern char D_00493F60[];
extern void* D_00494348[];
extern void* D_00494408[];
extern void* D_004944C8[];
extern void* D_00494868[];
extern void* D_00494928[];
extern void* D_004949E8[];
extern void* D_00494AA8[];

struct sUIVtRec_D078 { short delta; short index; void (*fn)(void*, char*); };
struct sUIVtDel_D078 { short delta; short index; void (*fn)(void*, int); };

// UI objects keep their vtable at +0x8; slot 10 builds the object from its screen record
static inline void initFromRec_D078(char* o, char* rec)
{
    sUIVtRec_D078* vt = *(sUIVtRec_D078**)(o + 8);
    vt[10].fn(o + vt[10].delta, rec);
}

// slot 1: deleting destructor
static inline void deleteObj_D078(char* o)
{
    sUIVtDel_D078* vt = *(sUIVtDel_D078**)(o + 8);
    vt[1].fn(o + vt[1].delta, 3);
}

static inline char* alloc_D078(unsigned int size, const char* tag)
{
    return (char*)operator new(size, tag, 0x20000000, 0);
}

extern "C" char* cUIScreen_createObjectByStruct(void* self, char* rec)
{
    switch (*(unsigned short*)rec) {
    case 0x11: {
        char* o = alloc_D078(0x88, D_004A4788);
        func_0039FB30(o, self, 0);
        *(void***)(o + 8) = D_00494AA8;
        func_0021CCC8(o + 0x74);
        *(int*)(o + 0x78) = -1;
        *(int*)(o + 0x7C) = 0;
        initFromRec_D078(o, rec);
        return o;
    }
    case 0x10: {
        char* o = alloc_D078(0x90, D_00493F00);
        func_0039FB30(o, self, 0);
        *(void***)(o + 8) = D_004949E8;
        func_003977E8(o + 0x74);
        int* h = (int*)(rec + 0x24);
        for (unsigned int i = 0; i < *(unsigned int*)(rec + 0x20); i++, h++) {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *h);
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                cList_addToEnd((cList*)(o + 0x74), (cListNode*)c);
            }
        }
        initFromRec_D078(o, rec);
        return o;
    }
    case 0x12: {
        char* o = (char*)func_00399768(alloc_D078(0x31C, D_00493F10), self, 0);
        initFromRec_D078(o, rec);
        return o;
    }
    case 0x13: {
        char* o = alloc_D078(0xA8, D_004A4790);
        func_0039FB30(o, self, 0);
        *(void***)(o + 8) = D_004949E8;
        func_003977E8(o + 0x74);
        *(void***)(o + 8) = D_00494928;
        func_003A5338(o + 0x90);
        *(unsigned char*)(o + 0xA4) = 0xFF;
        *(char*)(o + 0x95) = 0;
        *(char*)(o + 0x96) = 0;
        *(char*)(o + 0x97) = 0;
        *(char*)(o + 0x98) = 0;
        *(int*)(o + 0x9C) = 0;
        *(int*)(o + 0xA0) = 0;
        int* h = (int*)(rec + 0x24);
        for (unsigned int i = 0; i < *(unsigned char*)(rec + 0x20); i++, h++) {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *h);
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                cList_addToEnd((cList*)(o + 0x74), (cListNode*)c);
            }
        }
        initFromRec_D078(o, rec);
        return o;
    }
    case 0x15: {
        char* o = alloc_D078(0x80, D_004A4798);
        int* h = (int*)(rec + 0x20);
        func_0039FB30(o, self, 0);
        *(void***)(o + 8) = D_00494868;
        func_003A5508(o + 0x74);
        *(int*)(o + 0x14) |= 2;
        *(int*)(o + 0x78) = 0;
        *(int*)(o + 0x7C) = 0;
        initFromRec_D078(o, rec);
        char* c = (char*)cUIScreen_getObjectByHashName(self, h[0]);
        if (c != 0) {
            cListNode_removeFromList(c);
            *(char**)(c + 0x40) = o;
            char* old = *(char**)(o + 0x78);
            if (old != 0)
                deleteObj_D078(old);
            *(char**)(o + 0x78) = c;
        }
        c = (char*)cUIScreen_getObjectByHashName(self, h[1]);
        if (c != 0) {
            *(int*)(c + 0x14) &= ~1;
            cListNode_removeFromList(c);
            *(char**)(c + 0x40) = o;
            char* old = *(char**)(o + 0x7C);
            if (old != 0)
                deleteObj_D078(old);
            *(char**)(o + 0x7C) = c;
        }
        return o;
    }
    case 0x19: {
        char* o = alloc_D078(0x88, D_00493F20);
        func_0039FB30(o, self, 0);
        *(int*)(o + 0x74) = 0;
        *(int*)(o + 0x78) = 0;
        *(int*)(o + 0x7C) = 0;
        *(int*)(o + 0x80) = 0;
        *(int*)(o + 0x84) = 0;
        *(void***)(o + 8) = D_00494408;
        initFromRec_D078(o, rec);
        {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *(int*)(rec + 0x20));
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                *(char**)(o + 0x74) = c;
            }
        }
        {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *(int*)(rec + 0x24));
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                *(char**)(o + 0x78) = c;
            }
        }
        return o;
    }
    case 0x21: {
        char* o = alloc_D078(0xCC, D_00493F30);
        func_0039FB30(o, self, 0);
        *(int*)(o + 0x74) = 0;
        *(int*)(o + 0x78) = 0;
        *(int*)(o + 0x7C) = 0;
        *(int*)(o + 0x80) = 0;
        *(int*)(o + 0x84) = 0;
        *(int*)(o + 0x88) = 0;
        *(int*)(o + 0xC0) = 0;
        *(int*)(o + 0xC4) = 0;
        *(int*)(o + 0xC8) = 0;
        *(char*)(o + 0x8C) = 0;
        *(char*)(o + 0xA5) = 0;
        *(void***)(o + 8) = D_004944C8;
        initFromRec_D078(o, rec);
        {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *(int*)(rec + 0x20));
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                *(char**)(o + 0x74) = c;
            }
        }
        {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *(int*)(rec + 0x24));
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                *(char**)(o + 0x78) = c;
            }
        }
        return o;
    }
    case 0x16: {
        char* o = alloc_D078(0x90, D_00493F40);
        func_0039FB30(o, self, 0);
        *(int*)(o + 0x74) = 0;
        *(int*)(o + 0x78) = 0;
        *(int*)(o + 0x7C) = 0;
        *(int*)(o + 0x80) = 0;
        *(int*)(o + 0x88) = 0;
        *(int*)(o + 0x8C) = 0;
        *(void***)(o + 8) = D_00494348;
        initFromRec_D078(o, rec);
        {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *(int*)(rec + 0x24));
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                *(char**)(o + 0x88) = c;
            }
        }
        {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *(int*)(rec + 0x28));
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                *(char**)(o + 0x8C) = c;
            }
        }
        return o;
    }
    case 0x17: {
        char* o = (char*)func_003A0348(alloc_D078(0xBC, D_004A47A0), self, 0);
        initFromRec_D078(o, rec);
        return o;
    }
    case 0x20: {
        char* o = (char*)func_003A1148(alloc_D078(0xD0, D_00493F50), self, 0);
        int* h = (int*)(rec + 0x2C);
        for (unsigned int i = 0; i < *(unsigned char*)(rec + 0x22); i++, h++) {
            char* c = (char*)cUIScreen_getObjectByHashName(self, *h);
            if (c != 0) {
                cListNode_removeFromList(c);
                *(char**)(c + 0x40) = o;
                cList_addToEnd((cList*)(o + 0x8C), (cListNode*)c);
            }
        }
        initFromRec_D078(o, rec);
        return o;
    }
    case 0x18: {
        char* o = (char*)func_003A3280(alloc_D078(0x90, D_00493F60), self, 0);
        initFromRec_D078(o, rec);
        return o;
    }
    }
    return 0;
}
#endif

extern "C" void* func_00398798(void*);

//100%
INCLUDE_ASM("ui/uiscreen", func_0039D758__FPv);
#ifdef SKIP_ASM
void* func_0039D758(void* self)
{
    return func_00398798((char*)self + 0x40);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ui/uiscreen", func_0039D778);
#ifdef SKIP_ASM
extern "C" void func_0039C978(void* self, void* thread);
extern "C" void func_00398910(void* list, unsigned short frame);

extern "C" void func_0039D778(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x18));
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            void* next = *(void**)((char*)n + 4);
            if (*(unsigned short*)((char*)n + 0xE) != *(unsigned short*)((char*)n + 0xC)) {
                func_0039C978(self, n);
                int flags = *(signed char*)((char*)n + 0x13);
                if ((flags & 1) == 0) {
                    cListNode_removeFromList(n);
                    if (n != 0) {
                        sDeleteTarget* target = *(sDeleteTarget**)((char*)n + 0x8);
                        target->fn((char*)n + target->field_0x8, 3);
                    }
                }
            }
            n = next;
        }
    }
    unsigned short frame = 0xFFFF;
    void* t = cUIScreen_getPrimaryThread(self);
    if (t != 0) {
        frame = *(unsigned short*)((char*)t + 0xC);
    } else {
        t = cList_first((cList*)((char*)self + 0x18));
        if (t != 0) {
            frame = *(unsigned short*)((char*)t + 0xC);
        }
    }
    func_00398910((char*)self + 0x40, frame);
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", cUIScreen_getObjectByHashName);
#ifdef SKIP_ASM
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash)
{
    void** objs = *(void***)((char*)self + 0x3C);
    if (objs != 0) {
        for (unsigned int i = 0; i < **(unsigned int**)((char*)self + 0x38); i++) {
            void* o = objs[i];
            if (o != 0 && *(int*)((char*)o + 0x38) == hash) {
                return o;
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039D8C0);
#ifdef SKIP_ASM
extern "C" void func_0039FC48(void* self, int flags);
extern void* D_004944C8[];

extern "C" void func_0039D8C0(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004944C8;
    void* a = *(void**)((char*)self + 0x74);
    if (a != 0) {
        sDeleteTarget* t = *(sDeleteTarget**)((char*)a + 0x8);
        t->fn((char*)a + t->field_0x8, 3);
    }
    void* b = *(void**)((char*)self + 0x78);
    if (b != 0) {
        sDeleteTarget* t = *(sDeleteTarget**)((char*)b + 0x8);
        t->fn((char*)b + t->field_0x8, 3);
    }
    func_0039FC48(self, flags);
}
#endif

extern "C" void* func_0039FE00(void* self);

//100%
INCLUDE_ASM("ui/uiscreen", func_0039D948__FPv);
#ifdef SKIP_ASM
void* func_0039D948(void* self)
{
    return func_0039FE00(self);
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039D968);
#ifdef SKIP_ASM
struct func_0039D968_sVEntry {
    short delta;
    short index;
    void (*fn)(void*, float, float);
};

extern "C" void func_0039D968(void* self, float x, float y)
{
    char* a = *(char**)((char*)self + 0x74);
    if (a != 0 && *(void**)((char*)self + 0x78) != 0) {
        float px = x + *(float*)((char*)self + 0x44);
        float py = y + *(float*)((char*)self + 0x48);
        if ((*(int*)(a + 0x14) >> 6) & 1) {
            func_0039D968_sVEntry* vt = *(func_0039D968_sVEntry**)(a + 8);
            vt[0x11].fn(a + vt[0x11].delta, px, py);
        }
        char* b = *(char**)((char*)self + 0x78);
        if ((*(int*)(b + 0x14) >> 6) & 1) {
            func_0039D968_sVEntry* vt = *(func_0039D968_sVEntry**)(b + 8);
            vt[0x11].fn(b + vt[0x11].delta, px, py);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039DA20);
#ifdef SKIP_ASM
extern "C" int strlen(const char*);
int GetHashValue32(char* str);
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0039DE68(void* self, int a);

struct sV3_DA20 {
    float x, y, z;
};
struct sV4_DA20 {
    float x, y, z, w;
};

struct sWVt_DA20 { short delta; short index; void* fn; };
typedef void (*tShow_DA20)(void*, int);
typedef void (*tGet_DA20)(void*, sV4_DA20*);

struct sWidget_DA20 {
    char pad0[8];
    sWVt_DA20* vt;      // 0x08
    char padC[0x44 - 0xC];
    sV3_DA20 pos;       // 0x44
};

struct sScroll_DA20 {
    char pad0[0x14];
    int flags;                  // 0x14
    char pad18[0x5C - 0x18];
    cUIScreen* screen;          // 0x5C
    char pad60[0x74 - 0x60];
    sWidget_DA20* track;        // 0x74
    sWidget_DA20* thumb;        // 0x78
    sWidget_DA20* up;           // 0x7C
    sWidget_DA20* down;         // 0x80
    sWidget_DA20* extra;        // 0x84
    int mode;                   // 0x88
    char upLabel[0x19];         // 0x8C
    char downLabel[0x1B];       // 0xA5
    int pos;                    // 0xC0
    int total;                  // 0xC4
    int visible;                // 0xC8
};

static inline void wShow_DA20(sWidget_DA20* w, int on)
{
    ((tShow_DA20)w->vt[9].fn)((char*)w + w->vt[9].delta, on);
}

static inline void wGet_DA20(sWidget_DA20* w, sV4_DA20* out)
{
    ((tGet_DA20)w->vt[20].fn)((char*)w + w->vt[20].delta, out);
}

static inline void wSet_DA20(sWidget_DA20* w, sV4_DA20* in)
{
    ((tGet_DA20)w->vt[21].fn)((char*)w + w->vt[21].delta, in);
}

extern "C" void func_0039DA20(sScroll_DA20* self, int pos, int visible, int total)
{
    char* name = self->upLabel;
    if (strlen(name) != 0 && pos < self->pos) {
        cUIScreen* scr = self->screen;
        if (scr != 0) {
            int f = cUIScreen_getFrameByLabel(scr, GetHashValue32(name));
            if (f != 0xFFFF)
                cUIScreen_playFrame(scr, f, 1);
        }
    }
    name = self->downLabel;
    if (strlen(name) != 0 && self->pos < pos) {
        cUIScreen* scr = self->screen;
        if (scr != 0) {
            int f = cUIScreen_getFrameByLabel(scr, GetHashValue32(name));
            if (f != 0xFFFF)
                cUIScreen_playFrame(scr, f, 1);
        }
    }
    self->total = total;
    self->pos = pos;
    self->visible = visible;
    if (self->track == 0 || self->thumb == 0)
        return;
    sV3_DA20 tpos = self->track->pos;
    sV3_DA20 npos = self->thumb->pos;
    sV4_DA20 tsize;
    sV4_DA20 nsize;
    {
        sWidget_DA20* w = self->track;
        ((tGet_DA20)w->vt[20].fn)((char*)w + w->vt[20].delta, &tsize);
    }
    {
        sWidget_DA20* w = self->thumb;
        ((tGet_DA20)w->vt[20].fn)((char*)w + w->vt[20].delta, &nsize);
    }
    func_0039DE68(self, 1);
    if (self->total != 0) {
        if (self->flags & 1) {
            float fp = (float)self->pos / (float)self->total;
            float fv = (float)self->visible / (float)self->total;
            npos.x = tpos.x;
            nsize.x = tsize.x;
            npos.y = tpos.y + tsize.y * fp;
            nsize.y = tsize.y * fv;
            if (tsize.y < nsize.y)
                nsize.y = tsize.y;
        }
        if (self->up != 0) {
            if (self->pos == 0)
                wShow_DA20(self->up, 0);
            else
                wShow_DA20(self->up, 1);
        }
        if (self->down != 0) {
            if (self->pos + self->visible >= self->total)
                wShow_DA20(self->down, 0);
            else
                wShow_DA20(self->down, 1);
        }
    } else {
        npos.y = tpos.y;
        npos.x = tpos.x;
        nsize.x = tsize.x;
        nsize.y = tsize.y;
    }
    if (nsize.y == tsize.y) {
        switch (self->mode) {
        case 0:
            func_0039DE68(self, 0);
            break;
        case 1:
            if (self->up != 0)
                wShow_DA20(self->up, 0);
            if (self->down != 0)
                wShow_DA20(self->down, 0);
            wShow_DA20(self->thumb, 0);
            break;
        case 2:
            if (self->up != 0)
                wShow_DA20(self->up, 1);
            if (self->down != 0)
                wShow_DA20(self->down, 1);
            wShow_DA20(self->thumb, 0);
            break;
        }
    } else {
        if (self->extra != 0)
            wShow_DA20(self->extra, 1);
        wShow_DA20(self->thumb, 1);
        wShow_DA20(self->track, 1);
    }
    self->thumb->pos = npos;
    {
        sWidget_DA20* w = self->thumb;
        ((tGet_DA20)w->vt[21].fn)((char*)w + w->vt[21].delta, &nsize);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039DE68);
#ifdef SKIP_ASM
struct func_0039DE68_sVEntry {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void func_0039DE68_call(char* o, int a)
{
    func_0039DE68_sVEntry* vt = *(func_0039DE68_sVEntry**)(o + 8);
    vt[9].fn(o + vt[9].delta, a);
}

extern "C" void func_0039DE68(void* self, int a)
{
    char* o = *(char**)((char*)self + 0x7C);
    if (o != 0) {
        func_0039DE68_call(o, a);
    }
    o = *(char**)((char*)self + 0x80);
    if (o != 0) {
        func_0039DE68_call(o, a);
    }
    o = *(char**)((char*)self + 0x84);
    if (o != 0) {
        func_0039DE68_call(o, a);
    }
    func_0039DE68_call(*(char**)((char*)self + 0x78), a);
    func_0039DE68_call(*(char**)((char*)self + 0x74), a);
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039DF28);
#ifdef SKIP_ASM
extern "C" void func_0039FC48(void* self, int flags);
extern void* D_00494348[];

extern "C" void func_0039DF28(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00494348;
    void* a = *(void**)((char*)self + 0x88);
    if (a != 0) {
        sDeleteTarget* t = *(sDeleteTarget**)((char*)a + 0x8);
        t->fn((char*)a + t->field_0x8, 3);
    }
    void* b = *(void**)((char*)self + 0x8C);
    if (b != 0) {
        sDeleteTarget* t = *(sDeleteTarget**)((char*)b + 0x8);
        t->fn((char*)b + t->field_0x8, 3);
    }
    func_0039FC48(self, flags);
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039DFB0);
#ifdef SKIP_ASM
extern "C" void func_0039DFB0(void* self)
{
    func_0039FE00(self);
    *(int*)((char*)self + 0x78) = 10;
    *(int*)((char*)self + 0x80) = 100;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039DFE8);
#ifdef SKIP_ASM
struct cUIThing;
unsigned short cUIThing_getKeyframerEvent(cUIThing* self, int x);
extern "C" void cUIScreen_playFrame(void* self, unsigned short frame, int flag);
void* func_0039FF50(void* self);
extern char D_004A5A58;

struct func_0039DFE8_sVEntryI {
    short delta;
    short index;
    int (*fn)(void*);
};
struct func_0039DFE8_sVEntryM {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};
struct func_0039DFE8_sVEntryS {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" int func_0039DFE8(char* self, char* input)
{
    char* t = *(char**)((char*)func_0039FF50(self) + 0x14);
    char* snd = &D_004A5A58;
    if (t) snd = t;
    func_0039DFE8_sVEntryI* vi = *(func_0039DFE8_sVEntryI**)(input + 8);
    if (vi[19].fn(input + vi[19].delta)) {
        if (*(int*)(self + 0x74) > 0) {
            unsigned short ev = cUIThing_getKeyframerEvent((cUIThing*)self, 8);
            if (ev != 0xFFFF) {
                cUIScreen_playFrame(*(void**)(self + 0x5C), ev, 1);
            }
            *(int*)(self + 0x74) = *(int*)(self + 0x74) - 1;
            char* mgr = *(char**)(*(char**)(self + 0x5C) + 0xD0);
            func_0039DFE8_sVEntryM* vm = *(func_0039DFE8_sVEntryM**)(mgr + 8);
            vm[19].fn(mgr + vm[19].delta, self, 9);
            func_0039DFE8_sVEntryS* vs = *(func_0039DFE8_sVEntryS**)snd;
            vs[2].fn(snd + vs[2].delta, 1);
        }
        return 1;
    }
    func_0039DFE8_sVEntryI* vi2 = *(func_0039DFE8_sVEntryI**)(input + 8);
    if (vi2[20].fn(input + vi2[20].delta)) {
        if (*(int*)(self + 0x74) + 1 < *(int*)(self + 0x78)) {
            unsigned short ev = cUIThing_getKeyframerEvent((cUIThing*)self, 9);
            if (ev != 0xFFFF) {
                cUIScreen_playFrame(*(void**)(self + 0x5C), ev, 1);
            }
            *(int*)(self + 0x74) = *(int*)(self + 0x74) + 1;
            char* mgr = *(char**)(*(char**)(self + 0x5C) + 0xD0);
            func_0039DFE8_sVEntryM* vm = *(func_0039DFE8_sVEntryM**)(mgr + 8);
            vm[19].fn(mgr + vm[19].delta, self, 9);
            func_0039DFE8_sVEntryS* vs = *(func_0039DFE8_sVEntryS**)snd;
            vs[2].fn(snd + vs[2].delta, 1);
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E130);
#ifdef SKIP_ASM
struct func_0039E130_sVec3 {
    float x, y, z;
};
struct func_0039E130_sVEntryF {
    short delta;
    short index;
    void (*fn)(void*, float, float);
};
struct func_0039E130_sVEntryV {
    short delta;
    short index;
    void (*fn)(void*, func_0039E130_sVec3*);
};

extern "C" void func_0039E130(char* self, float dx, float dy)
{
    char* a = *(char**)(self + 0x88);
    if (a == 0 || *(char**)(self + 0x8C) == 0) {
        return;
    }
    float x = dx + *(float*)(self + 0x44);
    float y = dy + *(float*)(self + 0x48);
    func_0039E130_sVEntryF* va = *(func_0039E130_sVEntryF**)(a + 8);
    va[17].fn(a + va[17].delta, x, y);
    char* o = *(char**)(self + 0x88);
    func_0039E130_sVec3 pos = *(func_0039E130_sVec3*)(o + 0x44);
    func_0039E130_sVec3 s1;
    func_0039E130_sVEntryV* vo = *(func_0039E130_sVEntryV**)(o + 8);
    vo[20].fn(o + vo[20].delta, &s1);
    char* b = *(char**)(self + 0x8C);
    func_0039E130_sVec3 s2;
    func_0039E130_sVEntryV* vb = *(func_0039E130_sVEntryV**)(b + 8);
    vb[20].fn(b + vb[20].delta, &s2);
    float w = s1.x - s2.x;
    char* b2 = *(char**)(self + 0x8C);
    func_0039E130_sVec3 p = *(func_0039E130_sVec3*)(b2 + 0x44);
    p.x = pos.x + w / ((float)*(int*)(self + 0x78) - 1.0f) * (float)*(int*)(self + 0x74);
    *(func_0039E130_sVec3*)(b2 + 0x44) = p;
    char* b3 = *(char**)(self + 0x8C);
    func_0039E130_sVEntryF* vb3 = *(func_0039E130_sVEntryF**)(b3 + 8);
    vb3[17].fn(b3 + vb3[17].delta, x, y);
}
#endif

extern void* D_0046DD60[];

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E288__FPv);
#ifdef SKIP_ASM
void* func_0039E288(void* self)
{
    *(int*)self = (int)(void*)D_0046DD60;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E2A0);
#ifdef SKIP_ASM
extern "C" void* func_003977E8(void* self);
extern void* D_004946C8[];

extern "C" void* func_0039E2A0(void* self, int a1)
{
    char* s = (char*)self;
    *(void**)(s + 0x4) = s;
    *(void**)(s + 0x0) = s;
    *(void***)(s + 0x8) = D_004946C8;
    *(int*)(s + 0xC) = 0;
    *(int*)(s + 0x10) = a1;
    *(signed char*)(s + 0x14) = -1;
    *(signed char*)(s + 0x15) = 0xF;
    *(short*)(s + 0x1C) = 0x218;
    *(int*)(s + 0x20) = 0;
    func_003977E8(s + 0x24);
    *(int*)(s + 0x40) = 0;
    *(signed char*)(s + 0x44) = -1;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E318);
#ifdef SKIP_ASM
extern "C" void* func_003977E8(void* self);
extern void* D_004946C8[];

extern "C" void* func_0039E318(void* self, int a1, int a2)
{
    char* s = (char*)self;
    *(void**)(s + 0x4) = s;
    *(void**)(s + 0x0) = s;
    *(void***)(s + 0x8) = D_004946C8;
    *(int*)(s + 0xC) = 0;
    *(int*)(s + 0x10) = a1;
    *(signed char*)(s + 0x14) = -1;
    *(signed char*)(s + 0x15) = 0xF;
    *(short*)(s + 0x1C) = 0x218;
    *(int*)(s + 0x20) = a2;
    func_003977E8(s + 0x24);
    *(int*)(s + 0x40) = 0;
    *(signed char*)(s + 0x44) = -1;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E390);
#ifdef SKIP_ASM
// PORT: unit declares func_00397948 as returning void*; called here as void (bound by asm label).
extern "C" void func_00397948_v(void*) __asm__("func_00397948");
extern "C" void func_003A4868(void*);
void operator_delete(int*);
extern void* D_004946C8[];
extern void* D_00494C98[];
extern void* D_00494CC0[];

extern "C" void func_0039E390(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004946C8;
    func_00397948_v((char*)self + 0x24);
    *(void***)((char*)self + 0x3C) = D_00494C98;
    func_00397948_v((char*)self + 0x24);
    *(void***)((char*)self + 0x38) = D_00494CC0;
    func_003A4868((char*)self + 0x30);
    *(void***)((char*)self + 0x2C) = D_00494CC0;
    func_003A4868((char*)self + 0x24);
    *(void***)((char*)self + 0x8) = D_00494CC0;
    func_003A4868(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

extern "C" void* func_00397948(void*);

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E438);
#ifdef SKIP_ASM
extern "C" void func_0039E438(void *arg0, signed char arg1) {
    if (arg1 < 0) {
        (*(unsigned char *)((char*)(arg0) + (0x15))) = 0xFFU;
        return;
    }
    (*(unsigned char *)((char*)(arg0) + (0x15))) = (unsigned char) ((*(unsigned char *)((char*)(arg0) + (0x15))) | ((int) (0x01000000 << arg1) >> 0x18));
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E470);
#ifdef SKIP_ASM
extern "C" void func_0039E470(void* self, signed char bit)
{
    signed char mask = ~(1 << bit);
    *((unsigned char*)self + 0x15) &= mask;
}
#endif
//100%
INCLUDE_ASM("ui/uiscreen", func_0039E4A0__FPv);
#ifdef SKIP_ASM
void* func_0039E4A0(void* self)
{
    return func_00397948(((char*)self + 0x24));
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E4C0);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList*);

struct sVEntry39E4C0 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

extern "C" void func_0039E4C0(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x24));
    if (n != 0) {
        sVEntry39E4C0* vt = *(sVEntry39E4C0**)((char*)self + 8);
        vt[0xD].fn((char*)self + vt[0xD].delta, (char*)n + 0x40);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E508__FPv);
#ifdef SKIP_ASM
void func_0039E508(void* self)
{
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E510);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct func_0039E510_sVEntryC {
    short delta;
    short index;
    void (*fn)(void*, unsigned char);
};
struct func_0039E510_sVEntryI {
    short delta;
    short index;
    int (*fn)(void*);
};
struct func_0039E510_sVEntryV {
    short delta;
    short index;
    void (*fn)(void*, void*);
};
struct func_0039E510_sVEntryP {
    short delta;
    short index;
    int (*fn)(void*, void*);
};

static inline int func_0039E510_padTest(char* pad, int slot)
{
    func_0039E510_sVEntryI* vt = *(func_0039E510_sVEntryI**)(pad + 8);
    return vt[slot].fn(pad + vt[slot].delta);
}

extern "C" void func_0039E510(char* self)
{
    int mask = *(signed char*)(self + 0x15);
    char* pad = *(char**)(*(char**)(self + 0x10) + 0xC);
    *(signed char*)(self + 0x14) = 0;
    do {
        func_0039E510_sVEntryC* vc = *(func_0039E510_sVEntryC**)(pad + 8);
        vc[44].fn(pad + vc[44].delta, *(unsigned char*)(self + 0x14));
        if (func_0039E510_padTest(pad, 45)) {
            if (func_0039E510_padTest(pad, 41) || (func_0039E510_padTest(pad, 40) && (mask & 1))) {
                func_0039E510_sVEntryP* vs = *(func_0039E510_sVEntryP**)(self + 8);
                if (!vs[8].fn(self + vs[8].delta, pad)) {
                    char* n = (char*)cList_first((cList*)(self + 0x24));
                    if (n != 0) {
                        do {
                            if (*(int*)(n + 0x14) & 1) {
                                func_0039E510_sVEntryP* vn = *(func_0039E510_sVEntryP**)(n + 8);
                                if (vn[4].fn(n + vn[4].delta, pad)) break;
                            }
                            n = *(char**)(n + 4);
                        } while (!cListNode_isSentinel((cListNode*)n));
                    }
                }
                func_0039E510_sVEntryV* vs2 = *(func_0039E510_sVEntryV**)(self + 8);
                vs2[9].fn(self + vs2[9].delta, pad);
                break;
            }
        }
        mask >>= 1;
    } while (++*(signed char*)(self + 0x14) < 2);
    *(signed char*)(self + 0x14) = -1;
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E688);
#ifdef SKIP_ASM
class func_0039E688_cVirt {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int);
};

extern "C" void func_0039E688(void* self, func_0039E688_cVirt* obj)
{
    obj->v07(1);
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E6B8);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct sVEntry39E6B8a {
    short delta;
    short index;
    void (*fn)(void*);
};
struct sVEntry39E6B8b {
    short delta;
    short index;
    void (*fn)(void*, float, float);
};

extern "C" void func_0039E6B8(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x24));
    if (n != 0) {
        sVEntry39E6B8a* vt = *(sVEntry39E6B8a**)((char*)self + 8);
        vt[0xE].fn((char*)self + vt[0xE].delta);
        do {
            char* obj = (char*)n + 0x40;
            if ((*(int*)((char*)n + 0x54) >> 6) & 1) {
                sVEntry39E6B8b* vt2 = *(sVEntry39E6B8b**)((char*)n + 0x48);
                vt2[0x11].fn(obj + vt2[0x11].delta, 0.0f, 0.0f);
            }
            n = *(void**)((char*)n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
}
#endif

struct cList;
struct cListNode;
void cList_addToEnd(cList*, cListNode*);

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E758);
#ifdef SKIP_ASM
extern "C" void func_0039E758(void* self, cListNode* node)
{
    cList_addToEnd((cList*)((char*)self + 0x24), node);
}
#endif

//100%
INCLUDE_ASM("ui/uiscreen", func_0039E778);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct sVEntry_func_0039E778 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0039E778(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x24));
    if (n != 0) {
        do {
            char* obj = (char*)n + 0x40;
            if ((*(int*)((char*)n + 0x54) >> 6) & 1) {
                sVEntry_func_0039E778* vt = *(sVEntry_func_0039E778**)((char*)n + 0x48);
                vt[9].fn(obj + vt[9].delta, 0);
            }
            n = *(void**)((char*)n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
}
#endif
//100%
INCLUDE_ASM("ui/uiscreen", func_0039E7F0);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct sVEntry_func_0039E7F0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_0039E7F0(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x24));
    if (n != 0) {
        do {
            char* obj = (char*)n + 0x40;
            if ((*(int*)((char*)n + 0x54) >> 6) & 1) {
                sVEntry_func_0039E7F0* vt = *(sVEntry_func_0039E7F0**)((char*)n + 0x48);
                vt[9].fn(obj + vt[9].delta, 1);
            }
            n = *(void**)((char*)n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ui/uiscreen", func_0039E868);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);
extern "C" void func_0039D778(void*);

extern "C" void func_0039E868(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x24));
    if (n != 0) {
        do {
            func_0039D778(n);
            n = *(void**)((char*)n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
}
#endif

